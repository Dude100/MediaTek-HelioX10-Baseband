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
 *	smsal_context.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains smsal context definition for SMSAL module .
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


#ifndef _SMSAL_CONTEXT_H
#define _SMSAL_CONTEXT_H

#include "smsal_timer.h"
#include "smsal_defs.h"
#include "smsal_structs.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_general_types.h"

#if defined(__GEMINI__) || defined(__SGLTE__)
#define SMSAL_SIM_ID  ((kal_uint8)(smsal_cur_mod-MOD_SMSAL))
#else
#define SMSAL_SIM_ID
#endif

/* SMSAL flags:
 *  bit0:  is_smsal_ready
 *  bit1:  is_mem_exd
 *  bit2:  is_mem_full
 *  bit3:  is_all_files_read
 *  bit4:  is_normal_service
 *  bit5:  sim_msg_storage  (whether support EFsms)
 *  bit6:  sim_parameter    (whether support EFsmsp)
 *  bit7:  mailbox_num      (whether support mailbox number)
 *  bit8:  mwf
 *  bit9:  mt sms wait to save during power on
 *  bit10: cb files are read or not
 *  bit11: sim card is changed or not
 */
#define SMSAL_RDY_FLAG              (0x00000001)
#define MEM_EXD_FLAG                (0x00000002)
#define MEM_FULL_FLAG               (0x00000004)
#define SMSAL_NORMAL_INIT           (0x00000008)
#define NORMAL_SERVICE_FLAG         (0x00000010)
#define SIM_MSG_FLAG                (0x00000020)
#define SMSAL_PARAM_FLAG            (0x00000040)
#define CPHS_MBOX_FLAG              (0x00000080)
#define CPHS_MWF_FLAG               (0x00000100)
#define MTSMS_WAIT_FLAG             (0x00000200)
#define CB_RDY_FLAG                 (0x00000400)
#define SIM_CHANGE_FLAG             (0x00000800)
#define ABORT_PENDING_FLAG          (0x00001000)
#define SIM_REFRESH_FLAG            (0x00002000)
#define FDN_PENDING_FLAG            (0x00004000)
#define SM_FULL_FLAG                (0x00008000)
#define ME_FULL_FLAG                (0x00010000)
#define SMSAL_SIM_SMSS_FLAG         (0x00020000)
#define SMSAL_SIM_SMSP_FLAG         (0x00040000)
#define SMSAL_FINISH_SIM_LOAD_FLAG  (0x00100000)
#define SMSAL_FINISH_NVM_LOAD_FLAG  (0x00200000)
#define SMSAL_EXT_FLAG              (0x01000000)
#define PHB_WAIT_EXT1_FLAG          (0x02000000)
#define NVM_MBOX_FLAG               (0x04000000)
#ifdef __REL4__
#define REL4_MBDN_FLAG              (0x10000000)
#define REL4_MBI_FLAG               (0x20000000)
#define REL4_MWIS_FLAG              (0x40000000)
#endif
#if defined(__CANCEL_LOCK_POWERON__)
#define SMSAL_ME_ONLY_INIT          (0x80000000)
#endif

/* SMSAL extend flags: */
#define SMSAL_EXT_IS_USIM           (0x00000001)

#define IS_FLAG_SET(mask) (((smsal_ptr_g->flags & mask)==mask) ? KAL_TRUE : KAL_FALSE)
#define SET_FLAGS(mask)   (smsal_ptr_g->flags |= mask)
#define CLR_FLAGS(mask)   (smsal_ptr_g->flags &= ~mask)

#define IS_FLAG_SET_EXT(mask) (((smsal_ptr_g->flags_ext & mask)==mask) ? KAL_TRUE : KAL_FALSE)
#define SET_FLAGS_EXT(mask)   (smsal_ptr_g->flags_ext |= mask)
#define CLR_FLAGS_EXT(mask)   (smsal_ptr_g->flags_ext &= ~mask)

/* if some header should be include before this one */
#ifndef _SMSAL_TIMER_H
#error "smsal_timer.h should be included before smsal_context.h"
#endif


typedef struct
{
    smsal_timer_struct          smsal_timer;

    smsal_timer_info_struct     timer_pool[SMSAL_MAX_TIMER_ITEM];

    kal_uint8                   msg_ref;
                                /* This variable range from 
                                 * 0..255 and unique message
                                 * reference for each MO-SM
                                 * shared between SMSAL, SMSTL
                                 * and Service Centre */
                                 
    kal_uint8                   sms_prefer_order;
                                /* 0(SMSAL_SM_FIRST): SIM
                                   1(SMSAL_ME_FIRST): ME */

    kal_uint16                  msg_box_num;

#ifndef __SMS_STORAGE_BY_MMI__
    smsal_mb_entry_struct       *message_box;
#endif

    smsal_storage_num_struct	storage_num_info;

    smsal_parameter_struct      sms_parameter;

    smsal_pending_act_struct    pending_act[SMSAL_MAX_PENDING_ACT];
                                /* Store the necessary information
                                 * for pending access of storages */

    smsal_send_abort_struct     send_abort;

    smsal_pending_cnmi_struct   cnmi[SMSAL_MAX_PENDING_CNMI];

    smsal_pending_smma_struct   smma;

   /* In order to save memory, I use bitmap to present following flags:
    *
    * 0: no, 1: yes
    *
    * bit0:  is_smsal_ready
    * bit1:  is_mem_exd
    * bit2:  is_mem_full
    * bit3:  is_all_files_read
    * bit4:  is_normal_service
    */
    kal_uint32                  flags;
    kal_uint32                  flags_ext;

#ifdef __CB__
    smsal_cb_struct             cb_data;
#endif

    smsal_reg_port_struct       reg_port;

#if defined(__SMS_ME_STORAGE__)
    smsal_concat_msg_save_struct    concat_msg_saving[SMSAL_MAX_CONCAT_MSG_SAVE];
#endif

#ifdef __SMSAL_UT__
    kal_uint8                   is_usim;
    kal_uint8                   is_sim_support;
#endif

} smsal_context_struct;

#if defined(__GEMINI__) || defined(__SGLTE__)
extern smsal_context_struct smsal_g[SMSAL_MAX_SIM_NUM];
#else
extern smsal_context_struct     smsal_g;
#endif

extern smsal_context_struct     *smsal_ptr_g;
extern module_type              smsal_cur_mod;

extern smsal_parameter_struct   *smsal_para_ptr_g;
#endif /* end of context strucutre */


