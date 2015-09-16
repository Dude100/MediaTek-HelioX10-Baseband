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
 *   cc_irq_adaptation.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Adaptation layer for CC IRQ.
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
#ifndef __CC_IRQ_ADAPTATION_H__
#define __CC_IRQ_ADAPTATION_H__
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "cc_irq_public.h"
#include "cc_irq_int.h"
#include "us_timer.h"

#if defined(__CC_IRQ_ON_PCCIF__)

#define CC_IRQ_INTR_ID_START                               IRQ_MD_PCCIF0_CODE
#define CC_IRQ_NESTED_TRIGGER_MAX                          4

/* in UT case, set CC IRQ number to physical channel number */
#if defined(__CC_IRQ_UT__)
#undef  CC_IRQ_MD1MD2_END
#define CC_IRQ_MD1MD2_END      (CC_IRQ_MD1MD2_START + PCCIF_IRQ_NUMBER)
#undef  CC_IRQ_MD2MD1_START
#define CC_IRQ_MD2MD1_START    CC_IRQ_MD1MD2_END
#undef  CC_IRQ_MD2MD1_END
#define CC_IRQ_MD2MD1_END      (CC_IRQ_MD2MD1_START + PCCIF_IRQ_NUMBER)
#undef  CC_IRQ_MD1MD2_NUMBER
#define CC_IRQ_MD1MD2_NUMBER    PCCIF_IRQ_NUMBER
#undef  CC_IRQ_MD2MD1_NUMBER
#define CC_IRQ_MD2MD1_NUMBER    PCCIF_IRQ_NUMBER
#undef CC_IRQ_MD1MD2_SYS
#undef CC_IRQ_MD2MD1_SYS
#define CC_IRQ_MD1MD2_SYS    CC_IRQ_MD1MD2_START
#define CC_IRQ_MD2MD1_SYS    CC_IRQ_MD2MD1_START

#undef CC_IRQ_SYS_USER_MD1MD2_END
#undef CC_IRQ_SYS_USER_MD2MD1_START
#undef CC_IRQ_SYS_USER_MD2MD1_END
#undef CC_IRQ_SYS_USER_MD1MD2_NUMBER
#undef CC_IRQ_SYS_USER_MD2MD1_NUMBER
#define CC_IRQ_SYS_USER_MD1MD2_END       4
#define CC_IRQ_SYS_USER_MD2MD1_START     4
#define CC_IRQ_SYS_USER_MD2MD1_END       8
#define CC_IRQ_SYS_USER_MD1MD2_NUMBER    4
#define CC_IRQ_SYS_USER_MD2MD1_NUMBER    4
#endif    /* __CC_IRQ_UT__ */

/* common adaptation for MD1/MD2 */
#define CC_IRQ_HW_INIT()                                   md_pccif_hw_init()
#define CC_IRQ_ENQUEUE_PARA(index, para0, para1, para2)    md_pccif_enqueue_para(index, para0, para1, para2)
#define CC_IRQ_IS_TX_RESOURCE_AVAIL(index, length)         (md_pccif_is_tx_res_avail(index, length) == KAL_TRUE)
#define CC_IRQ_TRIGGER_INTR(index)                         md_pccif_trigger_irq(index)
#define CC_IRQ_ENQUEUE_BUFF(index, addr, length)           md_pccif_enqueue_buff(index, addr, length)
#define CC_IRQ_GET_PENDED_PKT_CNT(index)                   md_pccif_get_pended_irq(index);
#define CC_IRQ_RX_PKT_IS_PARA(index)                       (md_pccif_get_pkt_type(index) == MD_PCCIF_HDR_TYPE_PARA)
#define CC_IRQ_RX_PKT_IS_BUFF(index)                       (md_pccif_get_pkt_type(index) == MD_PCCIF_HDR_TYPE_BUFF)
#define CC_IRQ_EXTR_BUFF(index, p_buff, p_length)          md_pccif_get_buff(index, p_buff, p_length)
#define CC_IRQ_HW_ACK(index)                               md_pccif_ack(index)
#define CC_IRQ_GET_VFLAG_BASE(index)                       md_pccif_get_user_ram_base()
#define CC_IRQ_STATE_SYNC()                                (cc_sys_state == CC_IRQ_SYS_STATE_RUNNING)
#define CC_IRQ_INIT_PROC                                   md_pccif_init_pkt_hdlr()
#define CC_IRQ_IS_ENABLED()                                md_pccif_is_enabled()
#define CC_IRQ_SET_DISABLE()                               md_pccif_set_disable()
#define CC_IRQ_SET_ENABLE()                                md_pccif_set_enable()
#define CC_IRQ_GET_CC_MUTEX()                              md_pccif_get_cc_mutex()
#define CC_IRQ_RELEASE_CC_MUTEX()                          md_pccif_release_cc_mutex()
#define CC_IRQ_HW_RESET()                                  md_pccif_hw_reset();

/* only SYS callback of CC IRQ is handled in HISR */
/* SYS callback uses index 0, so only 1st element in array shoudl be assigned as KAL_TRUE */
#define CC_IRQ_CB_HISR                                     KAL_TRUE

#if defined(__MD1__)

#define CC_IRQ_NUMBER                                      (CC_IRQ_MD1MD2_NUMBER)
#define CC_IRQ_TX_INDEX_IS_IN_RANGE(index)                 ((index) >= CC_IRQ_MD1MD2_START && (index) < CC_IRQ_MD1MD2_END)
#define CC_IRQ_RX_INDEX_IS_IN_RANGE(index)                 ((index) >= CC_IRQ_MD2MD1_START && (index) < CC_IRQ_MD2MD1_END)
#define CC_IRQ_TX_INDEX_OFFSET(index)                      ((index) - CC_IRQ_MD1MD2_START)
#define CC_IRQ_RX_INDEX_OFFSET(index)                      ((index) - CC_IRQ_MD2MD1_START)
#if defined(__CC_IRQ_UT__)
#define CC_IRQ_HISR_ID_MAPPING                             LISR2HISR_CC_IRQ_MD2MD1_SYS, LISR2HISR_CC_IRQ_MD2MD1_R0, LISR2HISR_CC_IRQ_MD2MD1_R1, LISR2HISR_CC_IRQ_MD2MD1_R2
#else
#define CC_IRQ_HISR_ID_MAPPING                             LISR2HISR_CC_IRQ_MD2MD1_SYS
#endif

#define CC_IRQ_SYS_RX_INDEX                                CC_IRQ_MD2MD1_SYS
#define CC_IRQ_SYS_TX_INDEX                                CC_IRQ_MD1MD2_SYS
#define CC_IRQ_SYS_HISR_MOD                                MOD_LISR2HISR_CC_IRQ_MD2MD1_SYS
#define CC_IRQ_SYS_USER_CB_NUMBER                          CC_IRQ_SYS_USER_MD2MD1_NUMBER
#define CC_IRQ_USER_RX_INDEX_IS_IN_RANGE(user_index)       ((user_index) >= CC_IRQ_SYS_USER_MD2MD1_START && (user_index) < CC_IRQ_SYS_USER_MD2MD1_END)
#define CC_IRQ_USER_TX_INDEX_IS_IN_RANGE(user_index)       ((user_index) >= CC_IRQ_SYS_USER_MD1MD2_START && (user_index) < CC_IRQ_SYS_USER_MD1MD2_END)
#define CC_IRQ_USER_TX_INDEX_OFFSET(index)                 ((index) - CC_IRQ_SYS_USER_MD1MD2_START)
#define CC_IRQ_USER_RX_INDEX_OFFSET(index)                 ((index) - CC_IRQ_SYS_USER_MD2MD1_START)

#elif defined(__MD2__)

#define CC_IRQ_NUMBER                                      (CC_IRQ_MD2MD1_NUMBER)
#define CC_IRQ_TX_INDEX_IS_IN_RANGE(index)                 ((index) >= CC_IRQ_MD2MD1_START && (index) < CC_IRQ_MD2MD1_END)
#define CC_IRQ_RX_INDEX_IS_IN_RANGE(index)                 ((index) >= CC_IRQ_MD1MD2_START && (index) < CC_IRQ_MD1MD2_END)
#define CC_IRQ_TX_INDEX_OFFSET(index)                      ((index) - CC_IRQ_MD2MD1_START)
#define CC_IRQ_RX_INDEX_OFFSET(index)                      ((index) - CC_IRQ_MD1MD2_START)

#define CC_IRQ_SYS_RX_INDEX                                CC_IRQ_MD1MD2_SYS
#define CC_IRQ_SYS_TX_INDEX                                CC_IRQ_MD2MD1_SYS
#define CC_IRQ_SYS_HISR_MOD                                MOD_CC_SYS_HISR
#define CC_IRQ_SYS_USER_CB_NUMBER                          CC_IRQ_SYS_USER_MD1MD2_NUMBER
#define CC_IRQ_USER_RX_INDEX_IS_IN_RANGE(user_index)       ((user_index) >= CC_IRQ_SYS_USER_MD1MD2_START && (user_index) < CC_IRQ_SYS_USER_MD1MD2_END)
#define CC_IRQ_USER_TX_INDEX_IS_IN_RANGE(user_index)       ((user_index) >= CC_IRQ_SYS_USER_MD2MD1_START && (user_index) < CC_IRQ_SYS_USER_MD2MD1_END)
#define CC_IRQ_USER_TX_INDEX_OFFSET(index)                 ((index) - CC_IRQ_SYS_USER_MD2MD1_START)
#define CC_IRQ_USER_RX_INDEX_OFFSET(index)                 ((index) - CC_IRQ_SYS_USER_MD1MD2_START)

#endif


#elif defined(__CC_IRQ_WITH_SHARE_VAR__)
#define CC_IRQ_NESTED_TRIGGER_MAX                          16
#else
#error "error CC IRQ Type"
#endif    /* __CC_IRQ_ON_PCCIF__ */

#define CC_IRQ_DMB()
#define CC_IRQ_USC(usc)    (usc = ust_get_current_time())
#define CC_IRQ_GET_DURATION_US(start, end, duration)    (duration = ust_us_duration((start), (end)))

#if defined(__CC_IRQ_UT__)
#define CC_IRQ_MSG_TX_GET_GLB_MOD_ID(mod_id)           (mod_id)
#define CC_IRQ_MSG_RX_GET_GLB_MOD_ID(mod_id)           (mod_id)
#else
extern kal_uint32 remap_module_id_from_global_to_local(kal_uint32 global_module);
extern kal_uint32 remap_module_id_from_local_to_global(kal_uint32 local_module);
#define CC_IRQ_MSG_TX_GET_GLB_MOD_ID(mod_id)           remap_module_id_from_local_to_global(mod_id)
#define CC_IRQ_MSG_RX_GET_GLB_MOD_ID(mod_id)           remap_module_id_from_global_to_local(mod_id)
#endif

#endif
