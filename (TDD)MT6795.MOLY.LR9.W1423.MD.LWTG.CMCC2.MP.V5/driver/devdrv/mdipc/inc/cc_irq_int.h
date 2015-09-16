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
 *   cc_irq_int.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Internal definition of CC IRQ.
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
#ifndef __CC_IRQ_INT_H__
#define __CC_IRQ_INT_H__
#include "md_pccif_int.h"

#define __CC_IRQ_ON_PCCIF__
#define CC_IRQ_PARA_NUMBER          3

#if defined(__CC_IRQ_ON_PCCIF__)
#define CC_IRQ_MAX_CHANNEL          PCCIF_IRQ_NUMBER
#endif

#define CC_IRQ_NR_TIMEOUT_US        (1000 * 10)    /* 10ms */

enum {
    CC_IRQ_SYS_OP_CTRL = 0,
    CC_IRQ_SYS_OP_MSG,
    CC_IRQ_SYS_OP_MISC,
    CC_IRQ_SYS_OP_MAX
};

typedef enum cc_irq_sys_state_e {
    CC_IRQ_SYS_STATE_INIT = 0,
    CC_IRQ_SYS_STATE_ASYNC,
    CC_IRQ_SYS_STATE_RUNNING,
    CC_IRQ_SYS_STATE_MAX
} cc_irq_sys_state_t;

enum {
    CC_IRQ_SYS_PKT_TYPE_INIT_HS = 0,
    CC_IRQ_SYS_PKT_TYPE_EXCEP,
    CC_IRQ_SYS_PKT_MAX
};

#if defined(__CC_IRQ_UT__)
typedef struct {
    kal_uint32 dir1_test_start;
    kal_uint32 dir1_test_end;
    kal_uint32 dir2_test_start;
    kal_uint32 dir2_test_end;    
    kal_uint32 share_para1;
    kal_uint32 share_para2;
    kal_uint32 share_para3;
    kal_uint32 share_para1_arr[CC_IRQ_MAX_CHANNEL];
    kal_uint32 share_para2_arr[CC_IRQ_MAX_CHANNEL];
    kal_uint32 share_para3_arr[CC_IRQ_MAX_CHANNEL];
    kal_uint32 dir1_unmask_enable;
    kal_uint32 dir2_unmask_enable;
    kal_int32 dir1_tx_notify;
    kal_int32 dir2_tx_notify;
} cc_irq_it_share_t;
#endif

/* Generic type of sys pkt */
typedef struct {
    kal_uint32 op_id:4;
    kal_uint32 reserved:28;
} cc_irq_sys_pkt_hdr_t;

/* cc sys pkt type */
typedef struct {
    kal_uint32 op_id:4;
    kal_uint32 ctrl_type:4;
    kal_uint32 reserved:24;
} cc_irq_sys_pkt_ctrl_t;

/* user callback type */
typedef struct {
    kal_uint32 op_id:4;
    kal_uint32 ext_id:8;
    kal_uint32 reserved:20;
} cc_irq_sys_pkt_misc_t;

extern void cc_sys_comm_init();
//extern kal_uint32 cc_sys_comm_get_state();
extern kal_int32 cc_irq_sys_tx_with_buffer(void *addr, kal_uint32 length);
extern kal_uint32 cc_sys_state;

#endif
