/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   cc_irq_ut.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This Module defines CC IRQ unit test function.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "cc_irq_public.h"
#include "cc_irq_int.h"
#include "intrCtrl.h"
#include "cc_irq_adaptation.h"

/*****************************************************************************
 * Type Definition                                                           *
 *****************************************************************************/
#if defined(__CC_IRQ_ON_PCCIF__)
#define CC_IRQ_UT_COMMON_CHANNEL_NUMBER    PCCIF_IRQ_NUMBER
#define SHARED_VAR(name)                   (*p_##name)
#if defined(__MD1__)
#define __CORE1__
#define CC_IRQ_UT_RX_IRQ_SHIFT    CC_IRQ_MD2MD1_START
#define CC_IRQ_UT_TX_IRQ_SHIFT    CC_IRQ_MD1MD2_START
#define CC_IRQ_MSG_TX_INDEX       CC_IRQ_MD1MD2_SYS
#define CC_IRQ_MSG_RX_INDEX       CC_IRQ_MD2MD1_SYS
#elif defined(__MD2__)
#define __CORE2__
#define CC_IRQ_UT_RX_IRQ_SHIFT    CC_IRQ_MD1MD2_START
#define CC_IRQ_UT_TX_IRQ_SHIFT    CC_IRQ_MD2MD1_START
#define CC_IRQ_MSG_TX_INDEX       CC_IRQ_MD2MD1_SYS
#define CC_IRQ_MSG_RX_INDEX       CC_IRQ_MD1MD2_SYS
#endif

volatile cc_irq_it_share_t* p_cc_irq_share_var;
#endif

#if defined(__CC_IRQ_WITH_SHARE_VAR__)
DEFINE_NC_SHARED_VAR(volatile cc_irq_it_share_t, cc_irq_share_var)
DECLARE_SHARED_VAR(volatile CC_IRQ_SHARE_MEM_T, cc_irq_l12ps_share_data)
DECLARE_SHARED_VAR(volatile CC_IRQ_SHARE_MEM_T, cc_irq_ps2l1_share_data)
#if defined(__PCORE__)
#define __CORE1__
#elif defined(__L1CORE__)
#define __CORE2__
#endif
#endif

/*****************************************************************************
 * Data Declaration                                                          *
 *****************************************************************************/
static kal_uint32 cc_irq_test_case = 0;
static kal_uint32 cc_irq_it_1_magic[CC_IRQ_UT_COMMON_CHANNEL_NUMBER];
static kal_uint32 cc_irq_it_2_magic[CC_IRQ_UT_COMMON_CHANNEL_NUMBER][CC_IRQ_PARA_NUMBER];
static kal_uint32 cc_irq_it_seq[CC_IRQ_PARA_NUMBER];
static kal_uint32 cc_irq_it_2_seq[CC_IRQ_UT_COMMON_CHANNEL_NUMBER][CC_IRQ_PARA_NUMBER];
static volatile kal_uint32 test_done = 0;
static kal_uint32 tx_seq = 0;
volatile static kal_int32 next_rx_index;    //- test case 8
static kal_uint32 cc_irq_ut_buff_test = 0;

extern kal_uint32 cc_hisr_index_mapping[];


/*****************************************************************************
 * Internal Definition                                                       *
 *****************************************************************************/
#define CC_IRQ_UNMASK_IRQ                        0
#define CC_IRQ_NO_UNMASK_IRQ                     1
#define CC_IRQ_WAIT_TEST_DONE                    0
#define CC_IRQ_NO_WAIT_TEST_DONE                 1
#define CC_IRQ_TX_SEQ_MAX                        0xFFFF
#define CC_IRQ_STRESS_IRQ_mask_state_cc_irq      0
#define CC_IRQ_STRESS_IRQ_UNmask_state_cc_irq    1
#define CC_IRQ_TEST_SEQ_MAX                      0xFFFF
#define CC_IRQ_RANDOM_TEST_OP_PERIOD_US          0x4000

//#define CC_SYS_COMM_UT
//#define __CC_BUFF_UT__    
//#define __CC_MSG_UT__
#define __CC_MISC_UT__

//- TEST STATUS
enum {
    CC_IRQ_TEST_STATUS_ENABLE = 1,
    CC_IRQ_TEST_STATUS_DISABLE = 2,
    CC_IRQ_WAIT_TX_SEND = 3,
    CC_IRQ_WAIT_TX_SEND_ACK = 4,
    CC_IRQ_WAIT_TX_MAX
} ;

//- Test Items
//- DIR1: CORE2 -> CORE1
//- DIR2: CORE1 -> CORE2
enum {
    CC_IRQ_UT_DIR1_WAIT_RESP = 0,
    CC_IRQ_UT_DIR2_WAIT_RESP,
    CC_IRQ_UT_DIR1_MUL_SRC,
    CC_IRQ_UT_DIR2_MUL_SRC,
    CC_IRQ_UT_DIR1_NESTED_TRIGGER,
    CC_IRQ_UT_DIR2_NESTED_TRIGGER,
    CC_IRQ_UT_DIR1_PREEMPT_TEST,
    CC_IRQ_UT_DIR2_PREEMPT_TEST,
    CC_IRQ_UT_RANDOMD_TEST,
    CC_IRQ_UT_DIR1_BUFF_BASIC_TEST = 0x200,
    CC_IRQ_UT_DIR2_BUFF_BASIC_TEST,
    CC_IRQ_UT_DIR1_BUFF_BASIC_TEST_NO_ACK,
    CC_IRQ_UT_DIR2_BUFF_BASIC_TEST_NO_ACK,
    CC_IRQ_UT_DIR1_BUFF_VAR_LEN,
    CC_IRQ_UT_DIR2_BUFF_VAR_LEN,
    CC_IRQ_UT_DIR1_BUFF_VAR_LEN_NO_ACK,
    CC_IRQ_UT_DIR2_BUFF_VAR_LEN_NO_ACK,
#if defined(__CC_IRQ_ON_PCCIF__)
    CC_IRQ_UT_DIR1_BUFF_PCCIF_WRAP,
    CC_IRQ_UT_DIR2_BUFF_PCCIF_WRAP,
    CC_IRQ_UT_DIR1_BUFF_PCCIF_COMB,
    CC_IRQ_UT_DIR2_BUFF_PCCIF_COMB,
#endif
#if defined(__CC_IRQ_ON_PCCIF__)
    CC_IRQ_UT_DIR1_MSG_BASIC = 0x300,
    CC_IRQ_UT_DIR2_MSG_BASIC,
    CC_IRQ_UT_DIR1_MSG_VAR_LEN,
    CC_IRQ_UT_DIR2_MSG_VAR_LEN,
    CC_IRQ_UT_DIR1_MSG_VAR_LEN_2,
    CC_IRQ_UT_DIR2_MSG_VAR_LEN_2,
    CC_IRQ_UT_DIR1_MSG_CON_TX,
    CC_IRQ_UT_DIR2_MSG_CON_TX,
#endif
#if defined(__CC_IRQ_ON_PCCIF__)
    CC_IRQ_UT_DIR1_USER_BASIC = 0x400,
    CC_IRQ_UT_DIR2_USER_BASIC,
    CC_IRQ_UT_DIR1_USER_MULTI,
    CC_IRQ_UT_DIR2_USER_MULTI,
    CC_IRQ_UT_DIR1_USER_CONCUR,
    CC_IRQ_UT_DIR2_USER_CONCUR
#endif
};

/*****************************************************************************
 * External definition                                                       *
 *****************************************************************************/



/*****************************************************************************
 * Internal Function                                                         *
 *****************************************************************************/
static void cc_irq_it_isr(kal_uint32 irq_index, kal_uint32 para1, kal_uint32 para2, kal_uint32 para3)
{
    kal_uint32 correct_seq_1, correct_seq_2, correct_seq_3;
    kal_uint32 i, j, savedMask;
    
    switch (cc_irq_test_case)
    {
#if defined(__CORE2__)
    case CC_IRQ_UT_DIR2_WAIT_RESP:
#elif defined(__CORE1__)
    case CC_IRQ_UT_DIR1_WAIT_RESP:
#endif
        {
            //- test case 1 will only receive irq from index 0
            if (irq_index != 0)
                ASSERT(0);

            correct_seq_1 = cc_irq_it_1_magic[0] | cc_irq_it_seq[0];
            correct_seq_2 = cc_irq_it_1_magic[1] | cc_irq_it_seq[1];
            correct_seq_3 = cc_irq_it_1_magic[2] | cc_irq_it_seq[2];

            if (correct_seq_1 != para1 || correct_seq_2 != para2 || correct_seq_3 != para3)
            {
                EXT_ASSERT(0, para1, para2, para3);
            }

            cc_irq_it_seq[0]++;
            cc_irq_it_seq[1]++;
            cc_irq_it_seq[2]++;
            
            //- write parameter to share memory
            SHARED_VAR(cc_irq_share_var).share_para1 = para1;
            SHARED_VAR(cc_irq_share_var).share_para2 = para2;
            SHARED_VAR(cc_irq_share_var).share_para3 = para3;

            CC_IRQ_DMB();

            if (cc_irq_it_seq[0] == CC_IRQ_TX_SEQ_MAX &&
                cc_irq_it_seq[1] == CC_IRQ_TX_SEQ_MAX &&
                cc_irq_it_seq[2] == CC_IRQ_TX_SEQ_MAX )
            {
                test_done = 1;
            }
        }
        break;
#if defined(__CORE2__)
    case CC_IRQ_UT_DIR2_MUL_SRC:
#elif defined(__CORE1__)
    case CC_IRQ_UT_DIR1_MUL_SRC:
#endif
        {
            correct_seq_1 = cc_irq_it_2_magic[irq_index][0] | cc_irq_it_2_seq[irq_index][0];
            correct_seq_2 = cc_irq_it_2_magic[irq_index][1] | cc_irq_it_2_seq[irq_index][1];
            correct_seq_3 = cc_irq_it_2_magic[irq_index][2] | cc_irq_it_2_seq[irq_index][2];

            if (correct_seq_1 != para1 || correct_seq_2 != para2 || correct_seq_3 != para3)
            {
                EXT_ASSERT(0, para1, para2, para3);
            }
            
            cc_irq_it_2_seq[irq_index][0]++;
            cc_irq_it_2_seq[irq_index][1]++;
            cc_irq_it_2_seq[irq_index][2]++;
            
            SHARED_VAR(cc_irq_share_var).share_para1_arr[irq_index] = para1;
            SHARED_VAR(cc_irq_share_var).share_para2_arr[irq_index] = para2;
            SHARED_VAR(cc_irq_share_var).share_para3_arr[irq_index] = para3;

            CC_IRQ_DMB();

            savedMask = SaveAndSetIRQMask();
            
            test_done = 1;
            for (i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
            {
                for (j = 0; j < CC_IRQ_PARA_NUMBER; j++)
                {
                    if (cc_irq_it_2_seq[i][j] != CC_IRQ_TX_SEQ_MAX)
                    {
                        test_done = 0;
                        break;
                    }
                }

                if(test_done == 0)
                    break;
            }

            RestoreIRQMask(savedMask);
        }
        break;
#if defined(__CORE2__)
    case CC_IRQ_UT_DIR2_NESTED_TRIGGER:
#elif defined(__CORE1__)
    case CC_IRQ_UT_DIR1_NESTED_TRIGGER:
#endif
        {
            correct_seq_1 = cc_irq_it_2_magic[irq_index][0] | cc_irq_it_2_seq[irq_index][0];
            correct_seq_2 = cc_irq_it_2_magic[irq_index][1] | cc_irq_it_2_seq[irq_index][1];
            correct_seq_3 = cc_irq_it_2_magic[irq_index][2] | cc_irq_it_2_seq[irq_index][2];

            if (correct_seq_1 != para1 || correct_seq_2 != para2 || correct_seq_3 != para3)
            {
                EXT_ASSERT(0, para1, para2, para3);
            }

            cc_irq_it_2_seq[irq_index][0]++;
            cc_irq_it_2_seq[irq_index][1]++;
            cc_irq_it_2_seq[irq_index][2]++;

            savedMask = SaveAndSetIRQMask();
        
            test_done = 1;
            for (i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
            {
                for (j = 0; j < CC_IRQ_PARA_NUMBER; j++)
                {
                    if (cc_irq_it_2_seq[i][j] != CC_IRQ_NESTED_TRIGGER_MAX)
                    {
                        test_done = 0;
                        break;
                    }
                }
        
                if(test_done == 0)
                    break;
            }
        
            RestoreIRQMask(savedMask);
        }
        break;
#if defined(__CORE1__)
    case CC_IRQ_UT_DIR1_PREEMPT_TEST:
#elif defined(__CORE2__)
    case CC_IRQ_UT_DIR2_PREEMPT_TEST:
#endif
        {
           if (irq_index != next_rx_index)
                EXT_ASSERT(0, irq_index, next_rx_index, 0);
            
            correct_seq_1 = cc_irq_it_2_magic[irq_index][0] | cc_irq_it_2_seq[irq_index][0];
            correct_seq_2 = cc_irq_it_2_magic[irq_index][1] | cc_irq_it_2_seq[irq_index][1];
            correct_seq_3 = cc_irq_it_2_magic[irq_index][2] | cc_irq_it_2_seq[irq_index][2];
            
            if (correct_seq_1 != para1 || correct_seq_2 != para2 || correct_seq_3 != para3)
            {
                EXT_ASSERT(0, para1, para2, para3);
            }
            
            //- unmask higher priority CC IRQ.
            next_rx_index--;            
            
            //- notify another core to trigger next CC IRQ.
#if defined(__CORE1__)
            SHARED_VAR(cc_irq_share_var).dir2_tx_notify--;
#else
            SHARED_VAR(cc_irq_share_var).dir1_tx_notify--;
#endif

            if (next_rx_index >= 0)
                cc_irq_unmask(next_rx_index + CC_IRQ_UT_RX_IRQ_SHIFT);

            while(next_rx_index >= 0);
            test_done = 1;            
        }
        break;
    case CC_IRQ_UT_RANDOMD_TEST:
        {
            correct_seq_1 = cc_irq_it_2_magic[irq_index][0] | cc_irq_it_2_seq[irq_index][0];
            correct_seq_2 = cc_irq_it_2_magic[irq_index][1] | cc_irq_it_2_seq[irq_index][1];
            correct_seq_3 = cc_irq_it_2_magic[irq_index][2] | cc_irq_it_2_seq[irq_index][2];

            if (correct_seq_1 != para1 || correct_seq_2 != para2 || correct_seq_3 != para3)
            {
                EXT_ASSERT(0, para1, para2, para3);
            }
        
            cc_irq_it_2_seq[irq_index][0] = (cc_irq_it_2_seq[irq_index][0] + 1) % (CC_IRQ_TEST_SEQ_MAX + 1);
            cc_irq_it_2_seq[irq_index][1] = (cc_irq_it_2_seq[irq_index][1] + 1) % (CC_IRQ_TEST_SEQ_MAX + 1);
            cc_irq_it_2_seq[irq_index][2] = (cc_irq_it_2_seq[irq_index][2] + 1) % (CC_IRQ_TEST_SEQ_MAX + 1);
        }
        break;
    default:
        ASSERT(0);
    }
}

extern void cc_irq_ut_buff_isr(kal_uint32 cc_irq_ut_buff_isr, kal_uint32 para1, kal_uint32 para2, kal_uint32 para3);

#if defined(__UNIFIED_ISR_LEVEL__)
static void cc_irq_it_cb(kal_uint32 para1, kal_uint32 para2, kal_uint32 para3)
{
    kal_uint32 hisr_id, index;
	
    hisr_id = kal_get_current_hisr_index();

    for(index = 0; index < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; index++)
    {
        if(hisr_id == cc_hisr_index_mapping[index])
            break;
    }
    if (cc_irq_ut_buff_test)
        cc_irq_ut_buff_isr(index, para1, para2, para3);
    else
        cc_irq_it_isr(index, para1, para2, para3);
}
#else
static void cc_irq_it_cb(kal_uint32 para1, kal_uint32 para2, kal_uint32 para3)
{
    kal_uint32 irq_code;

    irq_code = IRQ_Current_LISR();
    if (cc_irq_ut_buff_test)
        cc_irq_ut_buff_isr(irq_code - CC_IRQ_INTR_ID_START, para1, para2, para3);
    else
        cc_irq_it_isr(irq_code - CC_IRQ_INTR_ID_START, para1, para2, para3);
}
#endif

#if defined (__CC_IRQ_WITH_SHARE_VAR__)
static kal_uint32 get_free_space_by_channel(volatile CC_IRQ_SHARE_MEM_T *p_share, kal_uint32 index)
{
    kal_uint32 read_ptr, write_ptr;

    read_ptr = p_share->cc_irq_read_ptr[index];
    write_ptr = p_share->cc_irq_write_ptr[index];

    if (write_ptr >= read_ptr)
        return CC_IRQ_NESTED_TRIGGER_MAX - (write_ptr - read_ptr);
    else
        return read_ptr - write_ptr - 1;
}
#endif

static void test_item_init(kal_uint32 test_case, kal_uint32 unmask_irq)
{
    kal_uint32 i, j;
    
    test_done = 0;

#if defined(__CORE2__)
    SHARED_VAR(cc_irq_share_var).dir1_test_start = CC_IRQ_TEST_STATUS_ENABLE;
    CC_IRQ_DMB();
    while(SHARED_VAR(cc_irq_share_var).dir2_test_start != CC_IRQ_TEST_STATUS_ENABLE);
    SHARED_VAR(cc_irq_share_var).dir1_test_end = CC_IRQ_TEST_STATUS_DISABLE;
    SHARED_VAR(cc_irq_share_var).dir1_unmask_enable = 0;
    SHARED_VAR(cc_irq_share_var).dir1_tx_notify = CC_IRQ_UT_COMMON_CHANNEL_NUMBER - 1;
    CC_IRQ_DMB();
#else
    SHARED_VAR(cc_irq_share_var).dir2_test_start = CC_IRQ_TEST_STATUS_ENABLE;
    CC_IRQ_DMB();
    while(SHARED_VAR(cc_irq_share_var).dir1_test_start != CC_IRQ_TEST_STATUS_ENABLE);
    SHARED_VAR(cc_irq_share_var).dir2_test_end = CC_IRQ_TEST_STATUS_DISABLE;
    SHARED_VAR(cc_irq_share_var).dir2_unmask_enable = 0;
    SHARED_VAR(cc_irq_share_var).dir2_tx_notify = CC_IRQ_UT_COMMON_CHANNEL_NUMBER - 1;
    CC_IRQ_DMB();
#endif
    
    tx_seq = 0;
    
    for (i = 0; i < CC_IRQ_PARA_NUMBER; i++)
    {
        cc_irq_it_seq[i] = 0;
        for(j = 0; j < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; j++)
        {
            cc_irq_it_2_seq[j][i] = 0;
        }
    }
    
    if (unmask_irq == CC_IRQ_UNMASK_IRQ)
    {
        for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
        {
            cc_irq_unmask(i + CC_IRQ_UT_RX_IRQ_SHIFT);
        }
    }
}

static void test_item_deinit(kal_uint32 test_case)
{
    kal_uint32 i;

    for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
        cc_irq_mask(i + CC_IRQ_UT_RX_IRQ_SHIFT);
    }

#if defined(__CORE2__)
    SHARED_VAR(cc_irq_share_var).dir1_test_start = CC_IRQ_TEST_STATUS_DISABLE;
    SHARED_VAR(cc_irq_share_var).dir1_test_end = CC_IRQ_TEST_STATUS_ENABLE;
    CC_IRQ_DMB();
    while(SHARED_VAR(cc_irq_share_var).dir2_test_end != CC_IRQ_TEST_STATUS_ENABLE);
#else
    SHARED_VAR(cc_irq_share_var).dir2_test_start = CC_IRQ_TEST_STATUS_DISABLE;
    SHARED_VAR(cc_irq_share_var).dir2_test_end = CC_IRQ_TEST_STATUS_ENABLE;
    CC_IRQ_DMB();
    while(SHARED_VAR(cc_irq_share_var).dir1_test_end != CC_IRQ_TEST_STATUS_ENABLE);
#endif

#if defined(__CC_IRQ_WITH_SHARE_VAR__)
{
    kal_uint32 free_space_cnt;
    for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
#if defined(__CORE2__)
        free_space_cnt = get_free_space_by_channel(SHARED_pVAR(cc_irq_l12ps_share_data), i);
#else
        free_space_cnt = get_free_space_by_channel(SHARED_pVAR(cc_irq_ps2l1_share_data), i);
#endif
        EXT_ASSERT(free_space_cnt == CC_IRQ_NESTED_TRIGGER_MAX, free_space_cnt, i, 0);
    }
}
#endif
}



/*****************************************************************************
 * Public Function                                                           *
 *****************************************************************************/
kal_uint32 cc_irq_test_init_done = 0;
kal_uint32 per_irq_tx_seq[CC_IRQ_UT_COMMON_CHANNEL_NUMBER];
kal_uint32 mask_state_cc_irq[CC_IRQ_UT_COMMON_CHANNEL_NUMBER];
kal_uint32 next_mask_process_time[CC_IRQ_UT_COMMON_CHANNEL_NUMBER];
kal_uint32 next_send_time_cc_irq[CC_IRQ_UT_COMMON_CHANNEL_NUMBER];
kal_uint32 cc_irq_prev_usc = 0;

kal_uint32 last_channel_full_time;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__CORE2__)
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif /* if 0 */

void cc_irq_basic_test_tx()
{
    while(tx_seq < CC_IRQ_TX_SEQ_MAX)
    {
        SHARED_VAR(cc_irq_share_var).share_para1 = 0;
        SHARED_VAR(cc_irq_share_var).share_para2 = 0;
        SHARED_VAR(cc_irq_share_var).share_para3 = 0;
    
        CC_IRQ_DMB();
    
        cc_irq_trigger_interrupt(0 + CC_IRQ_UT_TX_IRQ_SHIFT, cc_irq_it_1_magic[0] | tx_seq, cc_irq_it_1_magic[1] | tx_seq, cc_irq_it_1_magic[2] | tx_seq);
        
        while(1)
        {
            if (SHARED_VAR(cc_irq_share_var).share_para1 == (cc_irq_it_1_magic[0] | tx_seq) && \
                SHARED_VAR(cc_irq_share_var).share_para2 == (cc_irq_it_1_magic[1] | tx_seq) && \
                SHARED_VAR(cc_irq_share_var).share_para3 == (cc_irq_it_1_magic[2] | tx_seq))
            {
                break;
            }
        }
            
        tx_seq++;
    }
}

void cc_irq_basic_test_rx()
{
    while (test_done == 0);
}

void cc_irq_multi_test_tx()
{
    kal_uint32 irq_respond[CC_IRQ_UT_COMMON_CHANNEL_NUMBER];
    kal_uint32 i, end_test_loop;
    kal_int32  ret;
    
    while(tx_seq < CC_IRQ_TX_SEQ_MAX)
    {
        for(i = 0; i < 3; i++)
        {
            SHARED_VAR(cc_irq_share_var).share_para1_arr[i] = 0;
            SHARED_VAR(cc_irq_share_var).share_para2_arr[i] = 0;
            SHARED_VAR(cc_irq_share_var).share_para3_arr[i] = 0;

            CC_IRQ_DMB();
        }
        for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
        {
            ret = cc_irq_trigger_interrupt(0 + i + CC_IRQ_UT_TX_IRQ_SHIFT, cc_irq_it_2_magic[i][0] | tx_seq, cc_irq_it_2_magic[i][1] | tx_seq, cc_irq_it_2_magic[i][2] | tx_seq);

            ASSERT(ret == CC_IRQ_SUCCESS);
        }

        for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
            irq_respond[i] = 0;

        end_test_loop = 0;
        while(end_test_loop == 0)
        {
            for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER;i++)
            {
                if (SHARED_VAR(cc_irq_share_var).share_para1_arr[i] == (cc_irq_it_2_magic[i][0] | tx_seq))
                    irq_respond[i] |= (1 << 0);
                if (SHARED_VAR(cc_irq_share_var).share_para2_arr[i] == (cc_irq_it_2_magic[i][1] | tx_seq))
                    irq_respond[i] |= (1 << 1);
                if (SHARED_VAR(cc_irq_share_var).share_para3_arr[i] == (cc_irq_it_2_magic[i][2] | tx_seq))
                    irq_respond[i] |= (1 << 2);
            }

            for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
            {
                if (irq_respond[i] != 7)
                    break;
            }

            if (i == CC_IRQ_UT_COMMON_CHANNEL_NUMBER)
                end_test_loop = 1;
        }
        
        tx_seq++;
    }
}

void cc_irq_multi_test_rx()
{
    while (test_done == 0);
}

void cc_irq_trans_max_test_tx()
{
    kal_uint32 i;
    kal_int32  ret;
#if 0
/* under construction !*/
#endif
	
    while(tx_seq < CC_IRQ_NESTED_TRIGGER_MAX)
    {
        for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
        {
            ret = cc_irq_trigger_interrupt(i + CC_IRQ_UT_TX_IRQ_SHIFT, cc_irq_it_2_magic[i][0] | tx_seq, cc_irq_it_2_magic[i][1] | tx_seq, cc_irq_it_2_magic[i][2] | tx_seq);
            ASSERT(ret == CC_IRQ_SUCCESS);                    
        }
    
        tx_seq++;
    }

#if defined(__CORE2__)
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    SHARED_VAR(cc_irq_share_var).dir1_unmask_enable = 1;    
#else
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    SHARED_VAR(cc_irq_share_var).dir2_unmask_enable = 1;
#endif
}

void cc_irq_trans_max_test_rx()
{
    kal_uint32 i;

#if defined(__CORE2__)	
    //- wait for PCORE sends all packets
    while(SHARED_VAR(cc_irq_share_var).dir2_unmask_enable == 0);
#else
    //- wait for L1CORE sends all packets
    while(SHARED_VAR(cc_irq_share_var).dir1_unmask_enable == 0);
#endif

    //- unmask IRQs
    for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
        cc_irq_unmask(i + CC_IRQ_UT_RX_IRQ_SHIFT);
    }

    //- wait for all irq processed
    while(test_done == 0);
}

void cc_irq_pri_test_tx()
{
    kal_uint32 i, index;
    kal_int32  ret;
	
    for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
        index = CC_IRQ_UT_COMMON_CHANNEL_NUMBER - 1 - i;
        
        ret = cc_irq_trigger_interrupt(index + CC_IRQ_UT_TX_IRQ_SHIFT, cc_irq_it_2_magic[index][0] | tx_seq, cc_irq_it_2_magic[index][1] | tx_seq, cc_irq_it_2_magic[index][2] | tx_seq);
        ASSERT(ret == CC_IRQ_SUCCESS);

    //- wait receiver core response
#if defined(__CORE1__)
        while(index == SHARED_VAR(cc_irq_share_var).dir1_tx_notify);
#else
        while(index == SHARED_VAR(cc_irq_share_var).dir2_tx_notify);
#endif
    }
}

void cc_irq_pri_test_rx()
{
    //- unmask IRQ high highest priority.
    next_rx_index = CC_IRQ_UT_COMMON_CHANNEL_NUMBER - 1;
    cc_irq_unmask(CC_IRQ_UT_COMMON_CHANNEL_NUMBER - 1 + CC_IRQ_UT_RX_IRQ_SHIFT);
    while(test_done == 0);
}

#if defined(__CC_IRQ_ON_PCCIF__)
void cc_irq_ut_platform_init()
{
    kal_uint32 i;
	
    p_cc_irq_share_var= (cc_irq_it_share_t*)(PCCIF_CTRL_SRAM_USER_START + PCCIF_CTRL_SRAM_base);
    
    for(i = 0; i < NUM_IRQ_SOURCES; i++)
        IRQMask(i);
}

void cc_irq_ut_set_pri(kal_uint32 cc_irq_id, kal_uint32 pri)
{
#if defined(__MD1__)
    *(volatile kal_uint32 *)(MDCIRQ_PRLV(cc_irq_id)) = pri;
#elif defined(__MD2__)
    kal_uint32 reg_val, mask, off;
    
    reg_val = *IRQ_SEL(pri/4);
    off = (cc_irq_id % 4) * 8;
    mask = ~(0xFFUL << off);
    reg_val &= mask;
    reg_val |= (pri << off);
    *IRQ_SEL(pri/4) = reg_val;
#else
#error "unsupported chip"
#endif
}

#else
void cc_irq_ut_set_pri(kal_uint32 cc_irq_id, kal_uint32 pri)
{
    kal_uint32 reg_val, mask, off;
#if defined(MT6291)
    reg_val = *(volatile kal_uint32 *)(MDCIRQ_PRLV(cc_irq_id));
    off = (cc_irq_id % 4) * 8;
    mask = ~(0xFFUL << off);
    reg_val &= mask;
    reg_val |= (pri << off);
    *(volatile kal_uint32 *)(MDCIRQ_PRLV(cc_irq_id)) = reg_val;
#else
#error "unsupported chip"
#endif
}

void cc_irq_ut_platform_init()
{
}
#endif



void cc_irq_it()
{
    kal_uint32 i, j;

#if 0
/* under construction !*/
/* under construction !*/
#endif

#if defined(CC_SYS_COMM_UT)
extern void cc_irq_sys_comm_ut();
    cc_irq_sys_comm_ut();
#endif

#if defined(__CC_MISC_UT__)
    cc_irq_ut_platform_init();
extern void cc_irq_misc_ut();
    cc_irq_misc_ut();
#endif

    //- Initialization
    for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
        cc_irq_register_callback(i + CC_IRQ_UT_RX_IRQ_SHIFT, cc_irq_it_cb);
        cc_irq_mask(i + CC_IRQ_UT_RX_IRQ_SHIFT);
    }
    
    /* set priority */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    cc_irq_ut_platform_init();
    
    for (i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
        cc_irq_it_1_magic[i] = 0x5AF00000 | (i << 16);    //- [15:0] is reserved for sequence number;
        for (j = 0; j < 3; j++)
        {
            cc_irq_it_2_magic[i][j] = 0xFF000000 | (i << 20) | (j << 16);    //- [15:0] is reserved for sequence number;
        }
    }

#if defined(__CC_BUFF_UT__)
extern void cc_irq_buff_test();
    cc_irq_buff_test();
#endif

#if defined(__CC_MSG_UT__)
extern void cc_irq_msg_ut();
    cc_irq_msg_ut();
#endif

    //- Test 1 - L1CORE triggers interrupt (same source) to PCORE and wait process done.
    cc_irq_test_case = CC_IRQ_UT_DIR1_WAIT_RESP;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_basic_test_rx();
#else
    cc_irq_basic_test_tx();
#endif
    test_item_deinit(cc_irq_test_case);



    //- Test 2 - PCORE triggers interrupt (same source) to L1CORE and wait process done.
    cc_irq_test_case = CC_IRQ_UT_DIR2_WAIT_RESP;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_basic_test_tx();
#else
    cc_irq_basic_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);
    
    


    //- Test 3 - L1CORE triggers interrupt to PCORE with multiple sources interleaved.
    cc_irq_test_case = CC_IRQ_UT_DIR1_MUL_SRC;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_multi_test_rx();
#else
    cc_irq_multi_test_tx();
#endif
    test_item_deinit(cc_irq_test_case);


    //- Test 4 - PCORE triggers interrupt to L1CORE with multiple sources interleaved.
    cc_irq_test_case = CC_IRQ_UT_DIR2_MUL_SRC;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_multi_test_tx();
#else
    cc_irq_multi_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 5 - L1CORE triggers interrupt to PCORE with nested trigger count being max and check behavior.
    cc_irq_test_case = CC_IRQ_UT_DIR1_NESTED_TRIGGER;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);    
#if defined(__CORE1__)
    cc_irq_trans_max_test_rx();
#else
    cc_irq_trans_max_test_tx();
#endif
    test_item_deinit(cc_irq_test_case);



    //- Test 6 - PCORE triggers interrupt to L1CORE with nested trigger count being max and check behavior.
    cc_irq_test_case = CC_IRQ_UT_DIR2_NESTED_TRIGGER;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_trans_max_test_tx();
#else
    cc_irq_trans_max_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);



    //- Test 7 - L1CORE trigger CC IRQ with lowest priority, wait PCORE ack, then trigger higher priority
    //- Be sure that CC IRQ with larger index has lower priority.
    cc_irq_test_case = CC_IRQ_UT_DIR1_PREEMPT_TEST;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_pri_test_rx();
#else
    cc_irq_pri_test_tx();
#endif    
    test_item_deinit(cc_irq_test_case);    
    
    

    //- Test 8 - PCORE trigger CC IRQ with lowest priority, wait L1CORE ack, then trigger higher priority
    //- Be sure that CC IRQ with larger index has lower priority.
    cc_irq_test_case = CC_IRQ_UT_DIR2_PREEMPT_TEST;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_pri_test_tx();
#else
    cc_irq_pri_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);
}











#define CC_IRQ_UT_BUFF_BASIC_BUFF_LEN     12
#define CC_IRQ_UT_BUFF_BASIC_TX_NUMBER    65535
#define CC_IRQ_BUFF_TEST_INIT_PKT_LEN     27
#define CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_LOOP    32
#define CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1    (32 - 4)
#define CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_2    (64 - 4)

kal_uint8 test_buff[CC_IRQ_UT_COMMON_CHANNEL_NUMBER][CC_IRQ_BUFF_MAX + 4];

/* dbg log */
kal_uint32 dbg_ptr, dbg_i;

void cc_irq_ut_buff_isr(kal_uint32 index, kal_uint32 addr, kal_uint32 length, kal_uint32 no_use)
{
    kal_uint32 i, savedMask;
    kal_uint8  *ptr;

    ptr = (kal_uint8*)addr;
    switch(cc_irq_test_case)
    {
#if defined(__CORE1__)
    case CC_IRQ_UT_DIR1_BUFF_BASIC_TEST:
    case CC_IRQ_UT_DIR1_BUFF_BASIC_TEST_NO_ACK:
#else
    case CC_IRQ_UT_DIR2_BUFF_BASIC_TEST:
    case CC_IRQ_UT_DIR2_BUFF_BASIC_TEST_NO_ACK:
#endif
        {
            ASSERT(length == CC_IRQ_UT_BUFF_BASIC_BUFF_LEN);
            ASSERT(ptr != NULL);
            
            if (*(ptr + 0) != ((kal_uint8)index & 0xFF) || \
            	  *(ptr + 1) != 0xFF || \
            	  *(ptr + 2) != (cc_irq_it_2_seq[index][0] & 0xFF) || \
            	  *(ptr + 3) != ((cc_irq_it_2_seq[index][0] >> 8) & 0xFF))
            {
                ASSERT(0);
            }
            for (i = 4; i < CC_IRQ_UT_BUFF_BASIC_BUFF_LEN; i++)
            {
                if (*(ptr + i) != (index & 0xFF))
                    ASSERT(0);
            }
            cc_irq_it_2_seq[index][0]++;
            
            savedMask = SaveAndSetIRQMask();
            test_done = 1;
            for (i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
            {
                if (cc_irq_it_2_seq[i][0] != CC_IRQ_TX_SEQ_MAX)
                {
                    test_done = 0;
                    break;
                }
            }
            RestoreIRQMask(savedMask);
#if defined(__CORE1__)
            SHARED_VAR(cc_irq_share_var).dir2_tx_notify = 1;
#else
            SHARED_VAR(cc_irq_share_var).dir1_tx_notify = 1;
#endif
        }
        break;
#if defined(__CORE1__)
    case CC_IRQ_UT_DIR1_BUFF_VAR_LEN:
    case CC_IRQ_UT_DIR1_BUFF_VAR_LEN_NO_ACK:
#else
    case CC_IRQ_UT_DIR2_BUFF_VAR_LEN:
    case CC_IRQ_UT_DIR2_BUFF_VAR_LEN_NO_ACK:
#endif        
        {
            ASSERT(length == (cc_irq_it_2_seq[index][0] + CC_IRQ_BUFF_TEST_INIT_PKT_LEN));
            if (*(ptr + 0) != ((kal_uint8)(length & 0xFF)) || \
            	  *(ptr + 1) != ((kal_uint8)((length >> 8) & 0xFF)) || \
   	            *(ptr + length - 1) != 0xFF)
   	        {
   	            ASSERT(0);
   	        }
   	        
   	        for (i = 2; i < length - 1;i++)
   	        {
   	            ASSERT(*(ptr + i) == (kal_uint8)index);
   	        }

            cc_irq_it_2_seq[index][0]++;
            
            savedMask = SaveAndSetIRQMask();
            test_done = 1;
            for (i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
            {
                if (cc_irq_it_2_seq[i][0] != CC_IRQ_BUFF_MAX - CC_IRQ_BUFF_TEST_INIT_PKT_LEN + 1)
                {
                    test_done = 0;
                    break;
                }
            }
            RestoreIRQMask(savedMask);
#if defined(__CORE1__)
            SHARED_VAR(cc_irq_share_var).dir2_tx_notify = 1;
#else
            SHARED_VAR(cc_irq_share_var).dir1_tx_notify = 1;
#endif
        }
        break;
#if defined(__CC_IRQ_ON_PCCIF__)
#if defined(__CORE1__)
        case CC_IRQ_UT_DIR1_BUFF_PCCIF_WRAP:
#else
        case CC_IRQ_UT_DIR2_BUFF_PCCIF_WRAP:
#endif
        {
            if (cc_irq_it_2_seq[index][0] % 2)
            {
                ASSERT(length == CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1);
            }
            else
            {
                ASSERT(length == CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_2);
            }

   	        for (i = 0; i < length - 1;i++)
   	        {
   	            dbg_ptr = (kal_uint32)ptr;
   	            dbg_i = i;
   	            ASSERT(*(ptr + i) == (kal_uint8)index);
   	        }
   	        
   	        ASSERT(*(ptr + length - 1) == 0xFF);
            
            cc_irq_it_2_seq[index][0]++;
            
            test_done = 1;
            for (i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
            {
                if (cc_irq_it_2_seq[index][0] != CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_LOOP)
                {
                    test_done = 0;
                    break;
                }
            }
        }
        break;
#if defined(__CORE1__)
        case CC_IRQ_UT_DIR1_BUFF_PCCIF_COMB:
#else
        case CC_IRQ_UT_DIR2_BUFF_PCCIF_COMB:
#endif
        {
            /* 
            cc_irq_it_2_seq[index][0] == 0 => pkt_len == CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 - 3;
            cc_irq_it_2_seq[index][0] == 1 => pkt_len == CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 - 2;
            cc_irq_it_2_seq[index][0] == 2 => pkt_len == CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 - 1;
            ...
            cc_irq_it_2_seq[index][0] == 6 => pkt_len == CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 + 3;
            */
            ASSERT (length == cc_irq_it_2_seq[index][0] + CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 - 3);
            ASSERT (*(ptr + length - 1) == 0xFF);
            
            /* check payload */
            for(i = 1; i < length - 1; i++)
            {
                ASSERT(*(ptr + i) == (kal_uint8)(index & 0xFF));
            }
            
            cc_irq_it_2_seq[index][0]++;
            if (cc_irq_it_2_seq[index][0] == 7)
            {
                cc_irq_it_2_seq[index][0] = 0;
                cc_irq_it_2_seq[index][1]++;
            }	
            
            test_done = 1;
            for (i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
            {
                if (cc_irq_it_2_seq[i][1] != 3)
                {
                    test_done = 0;
                    break;
                }
            }
        }
        break;
#endif        
    default:
        ASSERT(0);
    }
}

void cc_irq_buff_basic_test_tx(kal_uint32 wait_rx_ack)
{
    kal_uint32 i, j;
    kal_int32  ret;

    for(i = 0; i < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; i++)
    {
        /* prepare buffer */
        test_buff[i][0] = i & 0xFF;        
        test_buff[i][1] = 0xFF;
        
        for(j = 4; j < CC_IRQ_UT_BUFF_BASIC_BUFF_LEN;j++)
            test_buff[i][j] = i & 0xFF;
    	
        tx_seq = 0;
        while(tx_seq < CC_IRQ_TX_SEQ_MAX)
        {
            test_buff[i][2] = tx_seq & 0xFF;
            test_buff[i][3] = (tx_seq >> 8) & 0xFF;

            if (wait_rx_ack == 1)
            {
#if defined(__CORE1__)
                SHARED_VAR(cc_irq_share_var).dir1_tx_notify = 0;
                ret = cc_irq_trigger_interrupt_with_buff(i + CC_IRQ_UT_TX_IRQ_SHIFT, (void*)test_buff[i], CC_IRQ_UT_BUFF_BASIC_BUFF_LEN);
                ASSERT(ret == CC_IRQ_SUCCESS);
                while(SHARED_VAR(cc_irq_share_var).dir1_tx_notify == 0);
#else
                SHARED_VAR(cc_irq_share_var).dir2_tx_notify = 0;
                ret = cc_irq_trigger_interrupt_with_buff(i + CC_IRQ_UT_TX_IRQ_SHIFT, (void*)test_buff[i], CC_IRQ_UT_BUFF_BASIC_BUFF_LEN);
                ASSERT(ret == CC_IRQ_SUCCESS);
                while(SHARED_VAR(cc_irq_share_var).dir2_tx_notify == 0);
#endif
            }
            else
            {
                while(1)
                {
                    ret = cc_irq_trigger_interrupt_with_buff(i + CC_IRQ_UT_TX_IRQ_SHIFT, (void*)test_buff[i], CC_IRQ_UT_BUFF_BASIC_BUFF_LEN);
                    if (ret == CC_IRQ_SUCCESS)
                        break;
                    else if (ret == CC_IRQ_ERR_CHANNEL_FULL)
                        continue;
                    else
                        ASSERT(0);
                }
            }
            
            tx_seq++;
        }
    }
}

void cc_irq_buff_basic_test_rx()
{
    while(test_done == 0);
}

kal_uint32 pkt_len, pkt_start;

void cc_irq_buff_var_len_tx(kal_uint32 wait_rx_ack)
{
    kal_uint32 chl;
    kal_int32  ret;

    for (chl = 0; chl < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; chl++)
    {
        kal_mem_set((void*)test_buff[chl], (kal_uint8)(chl & 0xFF), CC_IRQ_BUFF_MAX);
    }

    for (pkt_len = CC_IRQ_BUFF_TEST_INIT_PKT_LEN; pkt_len <= CC_IRQ_BUFF_MAX; pkt_len++)
    {
        /* prepare packet */
        for (chl = 0; chl < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; chl++)
        {
            /* recover previous end mark to index */
            test_buff[chl][pkt_len - 2] = (chl & 0xFF);
        	
            test_buff[chl][0] = (kal_uint8)(pkt_len & 0xFF);
            test_buff[chl][1] = (kal_uint8)((pkt_len >> 8) & 0xFF);
            test_buff[chl][pkt_len - 1] = 0xFF;    /* end mark */
        }
        
        for (chl = 0; chl < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; chl++)
        {
            if (wait_rx_ack == 1)
            {
#if defined(__CORE1__)
                SHARED_VAR(cc_irq_share_var).dir1_tx_notify = 0;
                ret = cc_irq_trigger_interrupt_with_buff(chl + CC_IRQ_UT_TX_IRQ_SHIFT, (void*)test_buff[chl], pkt_len);
                ASSERT(ret == CC_IRQ_SUCCESS);
                while(SHARED_VAR(cc_irq_share_var).dir1_tx_notify == 0);
#else
                SHARED_VAR(cc_irq_share_var).dir2_tx_notify = 0;
                ret = cc_irq_trigger_interrupt_with_buff(chl + CC_IRQ_UT_TX_IRQ_SHIFT, (void*)test_buff[chl], pkt_len);
                ASSERT(ret == CC_IRQ_SUCCESS);
                while(SHARED_VAR(cc_irq_share_var).dir2_tx_notify == 0);
#endif                    
            }
            else
            {
                while(1)
                {
                    ret = cc_irq_trigger_interrupt_with_buff(chl + CC_IRQ_UT_TX_IRQ_SHIFT, (void*)test_buff[chl], pkt_len);
                    if (ret == CC_IRQ_SUCCESS)
                        break;
                    else if (ret == CC_IRQ_ERR_CHANNEL_FULL)
                        continue;
                    else
                        ASSERT(0);
                }
            }
        }
    }
}

void cc_irq_buff_var_len_rx()
{
    while(test_done == 0);
}

void cc_irq_buff_pccif_wrap_tx()
{
    kal_uint32 chl, i;
    kal_int32  ret;
    
    for (chl = 0; chl < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; chl++)
    {
        kal_mem_set((void*)test_buff[chl], (kal_uint8)(chl & 0xFF), CC_IRQ_BUFF_MAX);
        
        for (i = 0; i < CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_LOOP; i++)
        {
            if (i % 2)
            {
                test_buff[chl][CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 - 1] = 0xFF;
                test_buff[chl][CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_2 - 1] = (kal_uint8)chl & 0xFF;
                pkt_len = CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1;
            }
            else
            {
                test_buff[chl][CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 - 1] = (kal_uint8)chl & 0xFF;
                test_buff[chl][CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_2 - 1] = 0xFF;
                pkt_len = CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_2;
            }

            while(1)
            {
                ret = cc_irq_trigger_interrupt_with_buff(chl + CC_IRQ_UT_TX_IRQ_SHIFT, (void*)test_buff[chl], pkt_len);
                if (ret == CC_IRQ_SUCCESS)
                    break;
                else if (ret == CC_IRQ_ERR_CHANNEL_FULL)
                    continue;
                else
                    ASSERT(0);
            }
        }
    }
}

void cc_irq_buff_pccif_wrap_rx()
{
    while(test_done == 0);
}

void cc_irq_buff_pccif_comb_tx()
{
    kal_uint32 chl;
    kal_int32  ret;
	
    for (chl = 0; chl < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; chl++)
    {
        kal_mem_set((void*)test_buff[chl], (kal_uint8)(chl & 0xFF), CC_IRQ_BUFF_MAX);
        test_buff[chl][CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 + 3 - 1] = 0xFF;
    }	
    
    for (chl = 0; chl < CC_IRQ_UT_COMMON_CHANNEL_NUMBER; chl++)
    {
        for (pkt_start = 1; pkt_start <= 3; pkt_start++)
        {
            for (pkt_len = CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 - 3; pkt_len <= CC_IRQ_BUFF_TEST_PCCIF_WRAP_TEST_PKT_LEN_1 + 3; pkt_len++)
            {
                test_buff[chl][pkt_start] = (kal_uint8)(pkt_len & 0xFF);
                test_buff[chl][pkt_start + pkt_len - 1] = 0xFF;
                while(1)
                {
                    ret = cc_irq_trigger_interrupt_with_buff(chl + CC_IRQ_UT_TX_IRQ_SHIFT, (void*)test_buff[chl] + pkt_start, pkt_len);
                    if (ret == CC_IRQ_SUCCESS)
                        break;
                    else if (ret == CC_IRQ_ERR_CHANNEL_FULL)
                        continue;
                    else
                        ASSERT(0);
                }
                test_buff[chl][pkt_start] = (kal_uint8)(chl & 0xFF);
                test_buff[chl][pkt_start + pkt_len - 1] = (kal_uint8)(chl & 0xFF);
            }
        }
    }
}

void cc_irq_buff_pccif_comb_rx()
{
    while(test_done == 0);
}

void cc_irq_buff_test()
{
    cc_irq_ut_buff_test = 1;

    //- Test 1 - CORE1 send multiple packet with length 12 (not include header) to CORE2 through each channel.
    cc_irq_test_case = CC_IRQ_UT_DIR1_BUFF_BASIC_TEST;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_buff_basic_test_rx();
#else
    cc_irq_buff_basic_test_tx(1);
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 2 - CORE2 send multiple packet with length 12 (not include header) to CORE1 through each channel.
    cc_irq_test_case = CC_IRQ_UT_DIR2_BUFF_BASIC_TEST;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_buff_basic_test_tx(1);
#else
    cc_irq_buff_basic_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 3 - CORE1 send multiple packet with length 12 (not include header) to CORE2 through each channel. (no ack)
    cc_irq_test_case = CC_IRQ_UT_DIR1_BUFF_BASIC_TEST_NO_ACK;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_buff_basic_test_rx();
#else
    cc_irq_buff_basic_test_tx(0);
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 4 - CORE2 send multiple packet with length 12 (not include header) to CORE1 through each channel. (no ack)
    cc_irq_test_case = CC_IRQ_UT_DIR2_BUFF_BASIC_TEST_NO_ACK;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_buff_basic_test_tx(0);
#else
    cc_irq_buff_basic_test_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 5 - CORE2 send variable length packet to CORE1 through each channel
    cc_irq_test_case = CC_IRQ_UT_DIR1_BUFF_VAR_LEN;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_buff_var_len_rx();
#else
    cc_irq_buff_var_len_tx(1);
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 6 - CORE1 send variable length packet to CORE2 through each channel
    cc_irq_test_case = CC_IRQ_UT_DIR2_BUFF_VAR_LEN;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_buff_var_len_tx(1);
#else
    cc_irq_buff_var_len_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 7 - CORE2 send variable length packet to CORE1 through each channel (no ack)
    cc_irq_test_case = CC_IRQ_UT_DIR1_BUFF_VAR_LEN_NO_ACK;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_buff_var_len_rx();
#else
    cc_irq_buff_var_len_tx(0);
#endif
    test_item_deinit(cc_irq_test_case);
    
    //- Test 8 - CORE1 send variable length packet to CORE2 through each channel (no ack)
    cc_irq_test_case = CC_IRQ_UT_DIR2_BUFF_VAR_LEN_NO_ACK;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_buff_var_len_tx(0);
#else
    cc_irq_buff_var_len_rx();
#endif
    test_item_deinit(cc_irq_test_case);




#if defined(__CC_IRQ_ON_PCCIF__)
    //- Special Test 1 - CORE2 triggers tx with wrap case on PCCIF and send packet to CORE1
    cc_irq_test_case = CC_IRQ_UT_DIR1_BUFF_PCCIF_WRAP;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_buff_pccif_wrap_rx();
#else
    cc_irq_buff_pccif_wrap_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Special Test 2 - CORE2 triggers tx with wrap case on PCCIF and send packet to CORE2
    cc_irq_test_case = CC_IRQ_UT_DIR2_BUFF_PCCIF_WRAP;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_buff_pccif_wrap_tx();
#else
    cc_irq_buff_pccif_wrap_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Special Test 3 - combination of different start address and packet length (mod 4 = 0, mod 4 = 1, mod 4 = 2, mod 4 = 3), CORE 2 to CORE 1
    cc_irq_test_case = CC_IRQ_UT_DIR1_BUFF_PCCIF_COMB;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_buff_pccif_comb_rx();
#else
    cc_irq_buff_pccif_comb_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Special Test 4 - combination of different start address and packet length (mod 4 = 0, mod 4 = 1, mod 4 = 2, mod 4 = 3), CORE 1 to CORE 2
    cc_irq_test_case = CC_IRQ_UT_DIR2_BUFF_PCCIF_COMB;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_buff_pccif_comb_tx();
#else
    cc_irq_buff_pccif_comb_rx();
#endif
    test_item_deinit(cc_irq_test_case);

#endif    /* defined(__CC_IRQ_ON_PCCIF__) */

    while(1);
}







#define CC_IRQ_MSG_UT_BASIC_LP_LEN      32
#define CC_IRQ_MSG_UT_BASIC_LP_P_LEN    (CC_IRQ_MSG_UT_BASIC_LP_LEN - sizeof(local_para_struct))
#define CC_IRQ_MSG_UT_VAR_LEN_MAX       (2048 - 4)
#define CC_IRQ_MSG_UT_QUE_PKT_MAX       1024
#define CC_IRQ_MSG_UT_TX_SKT_NUM        16

kal_uint32 dbg_end_index;
kal_uint32 cc_irq_ut_msg_check_ilm = 1;
kal_uint32 cc_irq_ut_msg_con_tested[CC_IRQ_MSG_UT_TX_SKT_NUM];

void cc_irq_ut_msg_isr(kal_uint32 dst_mod, kal_uint32 sap, kal_uint32 msg, local_para_struct *lp)
{
    kal_uint32 i;
    kal_uint8  *buf_ptr;
    
    if (cc_irq_ut_msg_check_ilm)
    {
        ASSERT(dst_mod == (0xFFFF - cc_irq_it_seq[0]));
        ASSERT(sap     == (0xAA00 | (cc_irq_it_seq[0] % 0x100)));
        ASSERT(msg     == (0x5500 | (cc_irq_it_seq[0] >> 8)));
    }
    
    ASSERT(lp-> ref_count == 1);
    
    switch(cc_irq_test_case)
    {
#if defined(__CORE1__)
    case CC_IRQ_UT_DIR1_MSG_BASIC:
#else
    case CC_IRQ_UT_DIR2_MSG_BASIC:
#endif
        {
            ASSERT(lp->msg_len == CC_IRQ_MSG_UT_BASIC_LP_LEN);
            
            for (i = 0; i < CC_IRQ_MSG_UT_BASIC_LP_P_LEN; i++)
            {
                buf_ptr = (kal_uint8*)lp + sizeof(local_para_struct) + i;
                if (i == (cc_irq_it_seq[0] % CC_IRQ_MSG_UT_BASIC_LP_P_LEN))
                {
                    ASSERT(*buf_ptr == 0xFF);
                }
                else
                {
                    ASSERT(*buf_ptr == 0xCC);
                }
            }
            
            cc_irq_it_seq[0]++;
            if (cc_irq_it_seq[0] == 0x10000)
                test_done = 1;
        }
        break;
#if defined(__CORE1__)
    case CC_IRQ_UT_DIR1_MSG_VAR_LEN:
#else
    case CC_IRQ_UT_DIR2_MSG_VAR_LEN:
#endif
        {
            kal_uint8 pattern = cc_irq_it_seq[0] & 0xFF;
            ASSERT(cc_irq_it_seq[0] + sizeof(local_para_struct) == lp->msg_len);
            
            for (i = 0; i < lp->msg_len - sizeof(local_para_struct); i++)
            {
                ASSERT(*((kal_uint8*)lp + sizeof(local_para_struct) + i) == pattern);
            }

            if (cc_irq_it_seq[0] == CC_IRQ_MSG_UT_VAR_LEN_MAX - sizeof(local_para_struct))
                test_done = 1;
            
            cc_irq_it_seq[0]++;
        }
    break;
#if defined(__CORE1__)
    case CC_IRQ_UT_DIR1_MSG_VAR_LEN_2:
#else
    case CC_IRQ_UT_DIR2_MSG_VAR_LEN_2:
#endif
        {
            kal_uint32 test_addr = (kal_uint32)lp + sizeof(local_para_struct);
            for (i = 0; i < cc_irq_it_seq[0] / 4; i++)
            {
                ASSERT(*(kal_uint32*)test_addr == ((cc_irq_it_seq[0] << 16) | (i & 0xFFFF)));
                test_addr += 4;
            }

            if (cc_irq_it_seq[0] == CC_IRQ_MSG_UT_VAR_LEN_MAX - sizeof(local_para_struct))
                test_done = 1;
        	
            cc_irq_it_seq[0]++;
        }
    break;
#if defined(__CORE1__)
    case CC_IRQ_UT_DIR1_MSG_CON_TX:
#else
    case CC_IRQ_UT_DIR2_MSG_CON_TX:
#endif
        {
            kal_uint32 skt;
        	
            ASSERT(dst_mod == 0xAAAA);
            ASSERT(sap == 0xFFFF);
            ASSERT(msg == 0x0000);
            ASSERT(lp->msg_len == CC_IRQ_MSG_UT_VAR_LEN_MAX + sizeof(local_para_struct));
            
            skt = (*((kal_uint32*)lp + sizeof(local_para_struct)) >> 16) & 0xFF;
            ASSERT(cc_irq_ut_msg_con_tested[skt] == 0);
            
            for (i = 0; i < CC_IRQ_MSG_UT_VAR_LEN_MAX - sizeof(local_para_struct); i+= 4)
            {
                ASSERT(*(kal_uint32*)((kal_uint32)lp + sizeof(local_para_struct) + i) = 0x88000000 | ((skt & 0xFF) << 16) | i);
            }
            cc_irq_ut_msg_con_tested[skt] = 1;
            
            test_done = 1;
            for (i = 0; i < CC_IRQ_MSG_UT_TX_SKT_NUM; i++)
            {
                if (cc_irq_ut_msg_con_tested[i] == 0)
                {
                    test_done = 0;
                    break;
                }
            }
        }
        break;
    default:
        {
            ASSERT(0);
        }
    }
}

void cc_irq_msg_var_len_tx(kal_uint32 payload_type)
{
    local_para_struct *test_ptr;
    
    for (tx_seq = 0; tx_seq <= CC_IRQ_MSG_UT_VAR_LEN_MAX - sizeof(local_para_struct); tx_seq++)
    {
        test_ptr = (local_para_struct *)construct_local_para(tx_seq + sizeof(local_para_struct), 0);
        if (payload_type == 1)
        {
            kal_mem_set((void*)test_ptr + sizeof(local_para_struct), tx_seq & 0xFF, tx_seq);
        }
        else if (payload_type == 2)
        {
            kal_uint32 i, test_addr;

            test_addr = (kal_uint32)test_ptr + sizeof(local_para_struct);
            ASSERT(test_addr % 4 == 0);
            for (i = 0; i < tx_seq / 4; i++)
            {
                *(kal_uint32*)test_addr = (tx_seq << 16) | (i & 0xFFFF);
                test_addr += 4;
            }
        }
        cc_irq_msg_send5(CC_IRQ_MSG_TX_INDEX, tx_seq & 0xFFFF, 0xFFFF - tx_seq, 0xAA00 | (tx_seq % 0x100), 0x5500 | (tx_seq >> 8), (local_para_struct*)test_ptr);
    }
}

void cc_irq_msg_var_len_rx()
{
    while(test_done == 0);
}

void cc_irq_msg_basic_tx()
{
    local_para_struct *test_ptr;
    kal_uint8         *buf_ptr;

    for (tx_seq = 0; tx_seq <= 65535; tx_seq++)
    {
        test_ptr = (local_para_struct *)construct_local_para(CC_IRQ_MSG_UT_BASIC_LP_LEN, 0);
        kal_mem_set((void*)test_ptr + sizeof(local_para_struct), 0xCC, CC_IRQ_MSG_UT_BASIC_LP_P_LEN);
    	
        buf_ptr = (kal_uint8*)test_ptr + sizeof(local_para_struct) + tx_seq % CC_IRQ_MSG_UT_BASIC_LP_P_LEN;
        *buf_ptr = 0xFF;
        cc_irq_msg_send5(CC_IRQ_MSG_TX_INDEX, tx_seq & 0xFFFF, 0xFFFF - tx_seq, 0xAA00 | (tx_seq % 0x100), 0x5500 | (tx_seq >> 8), (local_para_struct*)test_ptr);
        *buf_ptr = 0xCC;
    }
}

void cc_irq_msg_basic_rx()
{
    while(test_done == 0);
}

kal_uint8 cc_irq_msg_ut_pkt_que[CC_IRQ_MSG_UT_QUE_PKT_MAX][CC_IRQ_BUFF_MAX];
kal_uint32 cc_irq_msg_ut_pkt_len[CC_IRQ_MSG_UT_QUE_PKT_MAX];
kal_uint8 cc_irq_msg_ut_pkt_used[CC_IRQ_MSG_UT_QUE_PKT_MAX];
kal_uint32 cc_irq_msg_ut_skt_start[CC_IRQ_MSG_UT_TX_SKT_NUM];
kal_uint32 cc_irq_msg_ut_skt_end[CC_IRQ_MSG_UT_TX_SKT_NUM];
kal_uint32 cc_irq_msg_ut_pkt_ptr = 0;

kal_uint32 cc_irq_msg_ut_pkt_enqueue(void *ptr, kal_uint32 length)
{
    if (cc_irq_test_case != CC_IRQ_UT_DIR1_MSG_CON_TX && cc_irq_test_case != CC_IRQ_UT_DIR2_MSG_CON_TX)
        return 0;
	
    kal_mem_cpy((void*)cc_irq_msg_ut_pkt_que[cc_irq_msg_ut_pkt_ptr], ptr, length);
    cc_irq_msg_ut_pkt_len[cc_irq_msg_ut_pkt_ptr] = length;
    cc_irq_msg_ut_pkt_ptr++;
    ASSERT(cc_irq_msg_ut_pkt_ptr < CC_IRQ_MSG_UT_QUE_PKT_MAX);
    
    return 1;
}

kal_uint32 dbg_i, dbg_j, dbg_pkt_index, dbg_addr;

void cc_irq_msg_con_skt_tx()
{
    kal_uint32 i, j, pkt_per_msg;
    local_para_struct *msg;
    
    for(i = 0; i < CC_IRQ_MSG_UT_QUE_PKT_MAX; i++)
        cc_irq_msg_ut_pkt_used[i] = 0;
    
    cc_irq_msg_ut_pkt_ptr = 0;
    
    for (i = 0; i < CC_IRQ_MSG_UT_TX_SKT_NUM; i++)
    {
        msg = (local_para_struct *)construct_local_para(CC_IRQ_MSG_UT_VAR_LEN_MAX + sizeof(local_para_struct), 0);
        for (j = 0; j < CC_IRQ_MSG_UT_VAR_LEN_MAX - sizeof(local_para_struct); j+= 4)
        {
            *(kal_uint32*)((kal_uint32)msg + sizeof(local_para_struct) + j) = 0x88000000 | ((i & 0xFF) << 16) | j;
        }
        cc_irq_msg_ut_skt_start[i] = cc_irq_msg_ut_pkt_ptr;
        cc_irq_msg_send5(CC_IRQ_MSG_TX_INDEX, 0x5555, 0xAAAA, 0xFFFF, 0x0000, msg);
        cc_irq_msg_ut_skt_end[i] = cc_irq_msg_ut_pkt_ptr - 1;
    }
    
    pkt_per_msg = cc_irq_msg_ut_skt_end[0] - cc_irq_msg_ut_skt_start[0] + 1;
    ASSERT(pkt_per_msg != 0);
    
    for (i = 1; i < CC_IRQ_MSG_UT_TX_SKT_NUM; i++)
    {
        ASSERT(cc_irq_msg_ut_skt_end[i] - cc_irq_msg_ut_skt_start[i] + 1 == pkt_per_msg);
    }
    
    for (i = 0; i < pkt_per_msg; i++)
    {
        for (j = 0; j < CC_IRQ_MSG_UT_TX_SKT_NUM; j++)
        {
            kal_uint32 pkt_index = cc_irq_msg_ut_skt_start[j] + i;
            
dbg_i = i;
dbg_j = j;
dbg_pkt_index = pkt_index;
dbg_addr = (kal_uint32)cc_irq_msg_ut_pkt_que[pkt_index];

#if 0            
/* under construction !*/
/* under construction !*/
#endif
        }
    }
}

void cc_irq_msg_con_skt_rx()
{
	  cc_irq_ut_msg_check_ilm = 0;
    cc_irq_unmask(CC_IRQ_MSG_RX_INDEX);
    while(test_done == 0);
}

void cc_irq_msg_ut()
{
extern void cc_sys_comm_init();
    cc_sys_comm_init();

    //- Test 1 - CORE2 send a ILM with lenght less than a packet to CORE1
    cc_irq_test_case = CC_IRQ_UT_DIR1_MSG_BASIC;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_msg_basic_rx();
#else
    cc_irq_msg_basic_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 2 - CORE1 send a ILM with lenght less than a packet to CORE2
    cc_irq_test_case = CC_IRQ_UT_DIR2_MSG_BASIC;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_msg_basic_tx();
#else
    cc_irq_msg_basic_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 3 - CORE2 send variable length ILM to CORE1
    cc_irq_test_case = CC_IRQ_UT_DIR1_MSG_VAR_LEN;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_msg_var_len_rx();
#else
    cc_irq_msg_var_len_tx(1);
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 4 - CORE1 send variable length ILM to CORE2
    cc_irq_test_case = CC_IRQ_UT_DIR2_MSG_VAR_LEN;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_msg_var_len_tx(1);
#else
    cc_irq_msg_var_len_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 5 - CORE2 send variable length ILM to CORE1
    cc_irq_test_case = CC_IRQ_UT_DIR1_MSG_VAR_LEN_2;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_msg_var_len_rx();
#else
    cc_irq_msg_var_len_tx(2);
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 6 - CORE1 send variable length ILM to CORE2
    cc_irq_test_case = CC_IRQ_UT_DIR2_MSG_VAR_LEN_2;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_msg_var_len_tx(2);
#else
    cc_irq_msg_var_len_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 7 - CORE2 send ILM to CORE1 with concurrently
    cc_irq_test_case = CC_IRQ_UT_DIR1_MSG_CON_TX;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_msg_con_skt_rx();
#else
    cc_irq_msg_con_skt_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 8 - CORE1 send ILM to CORE2 with concurrently
    cc_irq_test_case = CC_IRQ_UT_DIR2_MSG_CON_TX;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_msg_con_skt_tx();
#else
    cc_irq_msg_con_skt_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 1 - CORE2 send a ILM with lenght less than a packet to CORE1
    cc_irq_test_case = CC_IRQ_UT_DIR1_MSG_BASIC;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_msg_basic_rx();
#else
    cc_irq_msg_basic_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    //- Test 2 - CORE1 send a ILM with lenght less than a packet to CORE2
    cc_irq_test_case = CC_IRQ_UT_DIR2_MSG_BASIC;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)
    cc_irq_msg_basic_tx();
#else
    cc_irq_msg_basic_rx();
#endif
    test_item_deinit(cc_irq_test_case);


    while(1);
}





const kal_uint8 cc_irq_ut_misc_pattern[] = {0x00, 0x55, 0xAA, 0xFF, 0xA5, 0x5A, 0xCC, 0x66, 0x33};
kal_uint8  cc_irq_ut_misc_test_buff[(CC_IRQ_BUFF_MAX - 4)];
kal_uint8  dbg_1, dbg_2;
kal_uint32 dbg_3;
void cc_irq_misc_isr(kal_uint32 para0, kal_uint32 para1, kal_uint32 para2)
{
    kal_uint32 i;
    kal_uint8  *ptr = (kal_uint8*)para0;
    kal_uint32 length = para1;
	
    switch(cc_irq_test_case)
    {
#if defined(__CORE1__)
    case CC_IRQ_UT_DIR1_USER_BASIC:
#else
    case CC_IRQ_UT_DIR2_USER_BASIC:
#endif    	
        {
            ASSERT(cc_irq_it_seq[0] == length);
            for (i = 1; i < cc_irq_it_seq[0]; i++)
            {
                ASSERT(*(ptr + i) == cc_irq_ut_misc_pattern[(i + cc_irq_it_seq[0]) % sizeof(cc_irq_ut_misc_pattern)]);
            }
            cc_irq_it_seq[0]++;
            if (cc_irq_it_seq[0] == CC_IRQ_BUFF_MAX - 4 + 1)
                test_done = 1;
        }
        break;
#if defined(__CORE1__)
    case CC_IRQ_UT_DIR1_USER_MULTI:
    case CC_IRQ_UT_DIR1_USER_CONCUR:
#else
    case CC_IRQ_UT_DIR2_USER_MULTI:
    case CC_IRQ_UT_DIR2_USER_CONCUR:
#endif
        {
            ASSERT(*(kal_uint8*)para0 == 0);
            dbg_1 = *((kal_uint8*)para0 + 1);
            dbg_2 = cc_irq_it_seq[0] / 4;
            dbg_3 = para0;
            ASSERT(*((kal_uint8*)para0 + 1) == cc_irq_it_seq[0] / 4);
            
            cc_irq_it_seq[0]++;
        }
        break;
    default:
        ASSERT(0);
    }
}

void cc_irq_misc_isr_1(kal_uint32 para0, kal_uint32 para1, kal_uint32 para2)
{
    switch(cc_irq_test_case)
    {
#if defined(__CORE1__)
    case CC_IRQ_UT_DIR1_USER_MULTI:
    case CC_IRQ_UT_DIR1_USER_CONCUR:
#else
    case CC_IRQ_UT_DIR2_USER_MULTI:
    case CC_IRQ_UT_DIR2_USER_CONCUR:
#endif
        {
            ASSERT(*(kal_uint8*)para0 == 1);
            ASSERT(*((kal_uint8*)para0 + 1) == cc_irq_it_seq[0] / 4);
            
            cc_irq_it_seq[0]++;
        }
        break;
    default:
        ASSERT(0);
    }
}

void cc_irq_misc_isr_2(kal_uint32 para0, kal_uint32 para1, kal_uint32 para2)
{
    switch(cc_irq_test_case)
    {
#if defined(__CORE1__)
    case CC_IRQ_UT_DIR1_USER_MULTI:
    case CC_IRQ_UT_DIR1_USER_CONCUR:
#else
    case CC_IRQ_UT_DIR2_USER_MULTI:
    case CC_IRQ_UT_DIR2_USER_CONCUR:
#endif
        {
            ASSERT(*(kal_uint8*)para0 == 2);
            ASSERT(*((kal_uint8*)para0 + 1) == cc_irq_it_seq[0] / 4);
            
            cc_irq_it_seq[0]++;
        }
        break;
    default:
        ASSERT(0);
    }
}

void cc_irq_misc_isr_3(kal_uint32 para0, kal_uint32 para1, kal_uint32 para2)
{
    kal_uint32 end_cnt = 16;

    switch(cc_irq_test_case)
    {
#if defined(__CORE1__)
    case CC_IRQ_UT_DIR1_USER_CONCUR:
        end_cnt = 4;
    case CC_IRQ_UT_DIR1_USER_MULTI:
#else
    case CC_IRQ_UT_DIR2_USER_CONCUR:
        end_cnt = 4;
    case CC_IRQ_UT_DIR2_USER_MULTI:
#endif
        {
            ASSERT(*(kal_uint8*)para0 == 3);
            ASSERT(*((kal_uint8*)para0 + 1) == cc_irq_it_seq[0] / 4);
            
            cc_irq_it_seq[0]++;
            
            if (cc_irq_it_seq[0] == end_cnt)
                test_done = 1;
        }
        break;
    default:
        ASSERT(0);
    }
}

void cc_irq_user_concur_rx()
{
#if defined(__CORE1__)
    while(SHARED_VAR(cc_irq_share_var).dir1_unmask_enable == 0);
#else
    while(SHARED_VAR(cc_irq_share_var).dir2_unmask_enable == 0);
#endif

    cc_irq_unmask(CC_IRQ_SYS_RX_INDEX);
    
    while(test_done == 0);
}

void cc_irq_user_concur_tx()
{
    kal_uint32 i;
    kal_uint32 ret;
    
    for (i = 0; i < CC_IRQ_BUFF_MAX - 4; i++)
    {
        cc_irq_ut_misc_test_buff[i] = 0;
    }
	
    for (tx_seq = 0; tx_seq < 4; tx_seq++)
    {
        cc_irq_ut_misc_test_buff[0] = tx_seq % 4;
        cc_irq_ut_misc_test_buff[1] = tx_seq / 4;
        
#if defined(__CORE1__)    	
        ret = cc_irq_user_tx(CC_IRQ_SYS_USER_MD1MD2_START + (tx_seq % 4), cc_irq_ut_misc_test_buff, 2);
#else
        ret = cc_irq_user_tx(CC_IRQ_SYS_USER_MD2MD1_START + (tx_seq % 4), cc_irq_ut_misc_test_buff, 2);
#endif
        ASSERT(ret == CC_IRQ_SUCCESS);
    }

#if defined(__CORE1__)
    SHARED_VAR(cc_irq_share_var).dir2_unmask_enable = 1;
#else
    SHARED_VAR(cc_irq_share_var).dir1_unmask_enable = 1;
#endif
}

void cc_irq_user_multi_rx()
{
    while(test_done == 0);
}

void cc_irq_user_multi_tx()
{
    kal_uint32 i;
    kal_int32  ret;
    
    for (i = 0; i < CC_IRQ_BUFF_MAX - 4; i++)
    {
        cc_irq_ut_misc_test_buff[i] = 0;
    }
	
    for (tx_seq = 0; tx_seq < 16; tx_seq++)
    {
        cc_irq_ut_misc_test_buff[0] = tx_seq % 4;
        cc_irq_ut_misc_test_buff[1] = tx_seq / 4;
        
#if defined(__CORE1__)    	
        ret = cc_irq_user_tx(CC_IRQ_SYS_USER_MD1MD2_START + (tx_seq % 4), cc_irq_ut_misc_test_buff, 2);
#else
        ret = cc_irq_user_tx(CC_IRQ_SYS_USER_MD2MD1_START + (tx_seq % 4), cc_irq_ut_misc_test_buff, 2);
#endif
        ASSERT(ret == CC_IRQ_SUCCESS);
    }
}

void cc_irq_user_basic_rx()
{
    while(test_done == 0);
}

void cc_irq_user_basic_tx()
{
    kal_uint32 j;
	
    for (tx_seq = 0; tx_seq <= CC_IRQ_BUFF_MAX - 4; tx_seq++)
    {
        /* prepare buffer */
        cc_irq_ut_misc_test_buff[0] = tx_seq & 0xFF;
        for (j = 1; j < tx_seq; j++)
        {
            cc_irq_ut_misc_test_buff[j] = cc_irq_ut_misc_pattern[(j +  tx_seq) % sizeof(cc_irq_ut_misc_pattern)];
        }
        
#if defined(__CORE1__)    	
        cc_irq_user_tx(CC_IRQ_SYS_USER_MD1MD2_START, cc_irq_ut_misc_test_buff, tx_seq);
#else
        cc_irq_user_tx(CC_IRQ_SYS_USER_MD2MD1_START, cc_irq_ut_misc_test_buff, tx_seq);
#endif
    }
}

void cc_irq_misc_ut()
{
#if defined(__CORE1__)
    cc_irq_user_register_cb(CC_IRQ_SYS_USER_MD2MD1_START, cc_irq_misc_isr);
    cc_irq_user_register_cb(CC_IRQ_SYS_USER_MD2MD1_START + 1, cc_irq_misc_isr_1);
    cc_irq_user_register_cb(CC_IRQ_SYS_USER_MD2MD1_START + 2, cc_irq_misc_isr_2);
    cc_irq_user_register_cb(CC_IRQ_SYS_USER_MD2MD1_START + 3, cc_irq_misc_isr_3);
#else
    cc_irq_user_register_cb(CC_IRQ_SYS_USER_MD1MD2_START, cc_irq_misc_isr);
    cc_irq_user_register_cb(CC_IRQ_SYS_USER_MD1MD2_START + 1, cc_irq_misc_isr_1);
    cc_irq_user_register_cb(CC_IRQ_SYS_USER_MD1MD2_START + 2, cc_irq_misc_isr_2);
    cc_irq_user_register_cb(CC_IRQ_SYS_USER_MD1MD2_START + 3, cc_irq_misc_isr_3);
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__CORE1__)    
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__CORE1__)    
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#endif

    /* case 3 */
    cc_irq_test_case = CC_IRQ_UT_DIR1_USER_MULTI;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)    
    cc_irq_user_multi_rx();
#else
    cc_irq_user_multi_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    /* case 4 */
    cc_irq_test_case = CC_IRQ_UT_DIR2_USER_MULTI;
    test_item_init(cc_irq_test_case, CC_IRQ_UNMASK_IRQ);
#if defined(__CORE1__)    
    cc_irq_user_multi_tx();
#else
    cc_irq_user_multi_rx();
#endif
    test_item_deinit(cc_irq_test_case);

    /* case 5 */
    cc_irq_test_case = CC_IRQ_UT_DIR1_USER_CONCUR;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__CORE1__)    
    cc_irq_user_concur_rx();
#else
    cc_irq_user_concur_tx();
#endif
    test_item_deinit(cc_irq_test_case);

    /* case 6 */
    cc_irq_test_case = CC_IRQ_UT_DIR2_USER_CONCUR;
    test_item_init(cc_irq_test_case, CC_IRQ_NO_UNMASK_IRQ);
#if defined(__CORE1__)    
    cc_irq_user_concur_tx();
#else
    cc_irq_user_concur_rx();
#endif
    test_item_deinit(cc_irq_test_case);
    
    while(1);
}
