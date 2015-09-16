/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   usbcore_ind_q.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   USB Core indication queue operations.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                 HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "kal_public_api.h"
#include "intrCtrl.h"

#include "usbcore_ind_q.h"

#define USBC_UT_IND 0

#define USBC_MAX_IND_QUEUE_LEN          128 /* Maximal number of indication in queue. It got to be 2's power and must larger than 6. */
#define USBC_MAX_IND_QUEUE_LEN_MASK     (USBC_MAX_IND_QUEUE_LEN - 1)


static kal_uint32   usbc_ind_queue_head_s = 0;
static kal_uint32   usbc_ind_queue_len_s = 0;
static usbc_ind_t   usbc_ind_queue_s[USBC_MAX_IND_QUEUE_LEN];

/*------------------------------------------------------------------------------
 * Private implementation 
 *----------------------------------------------------------------------------*/
#define USBC_IND_QUEUE_LOCK(_stack_var) \
            _stack_var = SaveAndSetIRQMask()

#define USBC_IND_QUEUE_UNLOCK(_stack_var) \
            RestoreIRQMask(_stack_var)

#define USBC_IS_IND_QUEUE_FULL() \
            (USBC_MAX_IND_QUEUE_LEN == usbc_ind_queue_len_s)

#define USBC_IS_IND_QUEUE_EMPTY() \
            (0 == usbc_ind_queue_len_s)

#define USBC_GET_IND_QUEUE_INDEX(_index) \
            ((_index) & USBC_MAX_IND_QUEUE_LEN_MASK)

#define USBC_COPY_IND(_dst_ind, _src_ind) \
            kal_mem_cpy((_dst_ind), (_src_ind), sizeof(usbc_ind_t))

#if !USBC_UT_IND
    #define USBC_IND_QUEUE_FULL_ASSERT() ASSERT(KAL_FALSE)
#else
    #define USBC_IND_QUEUE_FULL_ASSERT()
#endif
/*------------------------------------------------------------------------------
 * Public interface
 *----------------------------------------------------------------------------*/
void usbc_enqueue_ind(usbc_ind_t *indication)
{
    kal_uint32  mask;
    kal_uint32  new_tail;
    kal_uint32  next_one;

    USBC_IND_QUEUE_LOCK(mask);

    if (!USBC_IS_IND_QUEUE_FULL()) {
        new_tail = USBC_GET_IND_QUEUE_INDEX(usbc_ind_queue_head_s + usbc_ind_queue_len_s);
        usbc_ind_queue_len_s++;
    } else {
        /*
         * If queue is full, we discard OLDEST NON-control request indication.
         * Since HIF driver guarantees at most one control transfer is on-going,
         * there are at most 1 CTRL_CMPLT and 1 SETUP_CMPLT in queue.
         */
        new_tail = usbc_ind_queue_head_s;
        usbc_ind_queue_head_s = USBC_GET_IND_QUEUE_INDEX(usbc_ind_queue_head_s + 1);
        if (USBC_IND_CTRL_SETUP == usbc_ind_queue_s[new_tail].type || 
            USBC_IND_CTRL_CMPLT == usbc_ind_queue_s[new_tail].type) {

            USBC_IND_QUEUE_FULL_ASSERT();
            if (USBC_IND_CTRL_SETUP == usbc_ind_queue_s[usbc_ind_queue_head_s].type ||
                USBC_IND_CTRL_CMPLT == usbc_ind_queue_s[usbc_ind_queue_head_s].type) {

                next_one = USBC_GET_IND_QUEUE_INDEX(usbc_ind_queue_head_s + 1);
                USBC_COPY_IND(&usbc_ind_queue_s[next_one], &usbc_ind_queue_s[usbc_ind_queue_head_s]);
            }
            USBC_COPY_IND(&usbc_ind_queue_s[usbc_ind_queue_head_s], &usbc_ind_queue_s[new_tail]);
        }
    }

    USBC_COPY_IND(&usbc_ind_queue_s[new_tail], indication);

    USBC_IND_QUEUE_UNLOCK(mask);
}

kal_bool usbc_dequeue_ind(usbc_ind_t *indication)
{
    kal_uint32  mask;
    kal_bool    succeeded;

    USBC_IND_QUEUE_LOCK(mask);

    if (USBC_IS_IND_QUEUE_EMPTY()) {
        succeeded = KAL_FALSE;
    } else {
        succeeded = KAL_TRUE;
        USBC_COPY_IND(indication, &usbc_ind_queue_s[usbc_ind_queue_head_s]);
        usbc_ind_queue_head_s = USBC_GET_IND_QUEUE_INDEX(usbc_ind_queue_head_s + 1);
        usbc_ind_queue_len_s--;
    }

    USBC_IND_QUEUE_UNLOCK(mask);

    return succeeded;
}

#if USBC_UT_IND

#define USBC_IND_UT_TYPE_MASK       0x3
#define USBC_IND_UT_DATA_MASK       0x3f

void usbc_ut_ind(void)
{
    kal_uint32  mask;
    kal_uint32  burst_len;
    kal_uint32  idx;
    kal_uint32  start_pos;
    usbc_ind_t  ind_to_enqueue;
    usbc_ind_t  ind_dequeued;

    for (burst_len = 1; burst_len <= USBC_MAX_IND_QUEUE_LEN; burst_len++) {
        for (start_pos = 0; start_pos < USBC_MAX_IND_QUEUE_LEN; start_pos++) {
            /*
             * Change queue head index.
             */
            USBC_IND_QUEUE_LOCK(mask);
            ASSERT(USBC_IS_IND_QUEUE_EMPTY());
            usbc_ind_queue_head_s = start_pos;
            USBC_IND_QUEUE_UNLOCK(mask);

            /*
             * Enqueue burst of indications.
             */
            for (idx = 0; idx < burst_len; idx++) {
                ind_to_enqueue.type = (idx & USBC_IND_UT_TYPE_MASK);
                ind_to_enqueue.data = (idx & USBC_IND_UT_DATA_MASK);
    
                usbc_enqueue_ind(&ind_to_enqueue);
            }

            /*
             * Dequeue burst of indications and check the correctness.
             */   
            for (idx = 0; idx < burst_len; idx++) {
                if (!usbc_dequeue_ind(&ind_dequeued)) {
                    ASSERT(KAL_FALSE);
                }
                if ((idx & USBC_IND_UT_TYPE_MASK) != ind_dequeued.type) {
                    ASSERT(KAL_FALSE);
                }
                if ((idx & USBC_IND_UT_DATA_MASK) != ind_dequeued.data) {
                    ASSERT(KAL_FALSE);
                }
            }
    
            /*
             * Check dequeue at empty queue condition.
             */
            if (usbc_dequeue_ind(&ind_dequeued)) {
                ASSERT(KAL_FALSE);
            }
        }
    }

    /*
     * Check enqueue at queue full with last indication is a device event.
     */
    ind_to_enqueue.type = USBC_IND_DEV_EVENT;
    ind_to_enqueue.data = 0x23;
    usbc_enqueue_ind(&ind_to_enqueue);

    for (idx = 1; idx < USBC_MAX_IND_QUEUE_LEN; idx++) {
        ind_to_enqueue.type = USBC_IND_DEV_EVENT;
        ind_to_enqueue.data = (idx & USBC_IND_UT_DATA_MASK);
        usbc_enqueue_ind(&ind_to_enqueue);
    }

    ind_to_enqueue.type = USBC_IND_DEV_EVENT;
    ind_to_enqueue.data = 0x18;
    usbc_enqueue_ind(&ind_to_enqueue);

    for (idx = 1; idx < USBC_MAX_IND_QUEUE_LEN; idx++) {
        if (!usbc_dequeue_ind(&ind_dequeued)) {
            ASSERT(KAL_FALSE);
        }
        if (USBC_IND_DEV_EVENT != ind_dequeued.type) {
            ASSERT(KAL_FALSE);
        }
        if ((idx & USBC_IND_UT_DATA_MASK) != ind_dequeued.data) {
            ASSERT(KAL_FALSE);
        }
    }

    if (!usbc_dequeue_ind(&ind_dequeued)) {
        ASSERT(KAL_FALSE);
    }
    if (USBC_IND_DEV_EVENT != ind_dequeued.type) {
        ASSERT(KAL_FALSE);
    }
    if (0x18 != ind_dequeued.data) {
        ASSERT(KAL_FALSE);
    }

    /*
     * Check enqueue at queue full with last indication is a control transfer.
     */
    ind_to_enqueue.type = USBC_IND_CTRL_SETUP;
    ind_to_enqueue.data = 0x23;
    usbc_enqueue_ind(&ind_to_enqueue);

    for (idx = 1; idx < USBC_MAX_IND_QUEUE_LEN; idx++) {
        ind_to_enqueue.type = USBC_IND_DEV_EVENT;
        ind_to_enqueue.data = (idx & USBC_IND_UT_DATA_MASK);
        usbc_enqueue_ind(&ind_to_enqueue);
    }

    ind_to_enqueue.type = USBC_IND_DEV_EVENT;
    ind_to_enqueue.data = 0x18;
    usbc_enqueue_ind(&ind_to_enqueue);

    if (!usbc_dequeue_ind(&ind_dequeued)) {
        ASSERT(KAL_FALSE);
    }
    if (USBC_IND_CTRL_SETUP != ind_dequeued.type) {
        ASSERT(KAL_FALSE);
    }
    if (0x23 != ind_dequeued.data) {
        ASSERT(KAL_FALSE);
    }

    for (idx = 2; idx < USBC_MAX_IND_QUEUE_LEN; idx++) {
        if (!usbc_dequeue_ind(&ind_dequeued)) {
            ASSERT(KAL_FALSE);
        }
        if (USBC_IND_DEV_EVENT != ind_dequeued.type) {
            ASSERT(KAL_FALSE);
        }
        if ((idx & USBC_IND_UT_DATA_MASK) != ind_dequeued.data) {
            ASSERT(KAL_FALSE);
        }
    }

    if (!usbc_dequeue_ind(&ind_dequeued)) {
        ASSERT(KAL_FALSE);
    }
    if (USBC_IND_DEV_EVENT != ind_dequeued.type) {
        ASSERT(KAL_FALSE);
    }
    if (0x18 != ind_dequeued.data) {
        ASSERT(KAL_FALSE);
    }

    /*
     * Check enqueue at queue full with last two indications are control transfer related.
     */
    ind_to_enqueue.type = USBC_IND_CTRL_SETUP;
    ind_to_enqueue.data = 0x23;
    usbc_enqueue_ind(&ind_to_enqueue);
    ind_to_enqueue.type = USBC_IND_CTRL_SETUP;
    ind_to_enqueue.data = 0x33;
    usbc_enqueue_ind(&ind_to_enqueue);


    for (idx = 2; idx < USBC_MAX_IND_QUEUE_LEN; idx++) {
        ind_to_enqueue.type = USBC_IND_DEV_EVENT;
        ind_to_enqueue.data = (idx & USBC_IND_UT_DATA_MASK);
        usbc_enqueue_ind(&ind_to_enqueue);
    }

    ind_to_enqueue.type = USBC_IND_DEV_EVENT;
    ind_to_enqueue.data = 0x18;
    usbc_enqueue_ind(&ind_to_enqueue);

    if (!usbc_dequeue_ind(&ind_dequeued)) {
        ASSERT(KAL_FALSE);
    }
    if (USBC_IND_CTRL_SETUP != ind_dequeued.type) {
        ASSERT(KAL_FALSE);
    }
    if (0x23 != ind_dequeued.data) {
        ASSERT(KAL_FALSE);
    }
    if (!usbc_dequeue_ind(&ind_dequeued)) {
        ASSERT(KAL_FALSE);
    }
    if (USBC_IND_CTRL_SETUP != ind_dequeued.type) {
        ASSERT(KAL_FALSE);
    }
    if (0x33 != ind_dequeued.data) {
        ASSERT(KAL_FALSE);
    }

    for (idx = 3; idx < USBC_MAX_IND_QUEUE_LEN; idx++) {
        if (!usbc_dequeue_ind(&ind_dequeued)) {
            ASSERT(KAL_FALSE);
        }
        if (USBC_IND_DEV_EVENT != ind_dequeued.type) {
            ASSERT(KAL_FALSE);
        }
        if ((idx & USBC_IND_UT_DATA_MASK) != ind_dequeued.data) {
            ASSERT(KAL_FALSE);
        }
    }

    if (!usbc_dequeue_ind(&ind_dequeued)) {
        ASSERT(KAL_FALSE);
    }
    if (USBC_IND_DEV_EVENT != ind_dequeued.type) {
        ASSERT(KAL_FALSE);
    }
    if (0x18 != ind_dequeued.data) {
        ASSERT(KAL_FALSE);
    }
}
#endif
