/*!
 *  @file hif_ior.h
 *  @author Roger Huang <chaomin.haung@mediatek.com>
 *  @version 1.0
 *  @section LICENSE
 *
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
 *  @section DESCRIPTION
 *  This file provides generic HIF IO Request interface of all HIF module
 */

#ifndef __HIF_IOR_H__
#define __HIF_IOR_H__

#include "qmu_bm.h"

/*!
 *  @brief hif_io_request_t is a typedef of struct _hif_io_request
 */
typedef struct _hif_io_request hif_io_request_t;
/*!
 *  @brief struct _hif_io_request describe io request used to communicate
 *         between hif modules
 */
struct _hif_io_request {
    /*!
     *  @brief next io request
     */
    hif_io_request_t*       next_request;
    /*!
     *  @brief pointer to current gpd of this io request
     */
    qbm_gpd*                first_gpd;
    /*!
     *  @brief pointer to last gpd of this io request
     */
    qbm_gpd*                last_gpd;
};


/*!
 *  @brief hif_io_request_list_t is a typedef of struct _hif_io_request_list
 */
typedef struct _hif_io_request_list hif_io_request_list_t;
/*!
 *  @brief struct _hif_io_request_list describe io request list used to
 *                store io request
 */
struct _hif_io_request_list {
    /*!
     *  @brief pointer to head of this io request list
     */
    hif_io_request_t*       head;
    /*!
     *  @brief pointer to tail of this io request list
     */
    hif_io_request_t*       tail;
};


#define HIF_LIST_INIT(_list)                                \
    ((_list)->head = (_list)->tail = NULL)


#define HIF_LIST_IS_EMPTY(_list)                            \
    ((_list)->head == NULL)


#define HIF_LIST_GET_HEAD(_list)                            \
    ((_list)->head)


#define HIF_LIST_GET_TAIL(_list)                            \
    ((_list)->tail)


#define HIF_LIST_POP_HEAD(_list)                            \
    ((_list)->head);                                        \
    {                                                       \
        void* next;                                         \
        next = (_list)->head->next_request;                 \
        (_list)->head = next;                               \
        if (next == NULL) {                                 \
            (_list)->tail = NULL;                           \
        }                                                   \
    }


#define HIF_LIST_PUSH_TAIL(_list, _entry)                   \
    {                                                       \
        (_entry)->next_request = NULL;                      \
        if ((_list)->tail) {                                \
            (_list)->tail->next_request = (_entry);         \
        } else {                                            \
            (_list)->head = (_entry);                       \
        }                                                   \
        (_list)->tail = (_entry);                           \
    }

#endif  // __HIF_IOR_H__
