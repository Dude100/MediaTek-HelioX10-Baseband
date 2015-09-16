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
 *	smsal_msgbox.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains function prototypes and MACROs for
 *   message box management.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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


#ifndef _SMSAL_MSG_STORAGE_H
#define _SMSAL_MSG_STORAGE_H

#include "smsal_context.h"
#include "smsal_defs.h"
#include "smsal_l4c_enum.h"
#include "smsal_structs.h"
#include "smsal_peer_struct.h"
#include "kal_public_api.h"
#include "kal_general_types.h"

#ifdef __SMS_STORAGE_BY_MMI__
#ifdef __SMS_ME_STORAGE__
#undef __SMS_ME_STORAGE__
#endif
#endif


#if !defined (__SMS_ME_STORAGE__)
#define INCR_USED_MSG_NUM(storage_type) do { \
        smsal_cntx_ptr->storage_num_info.used_sim_msg_num = \
                                                       smsal_cntx_ptr->storage_num_info.used_sim_msg_num + 1; \
    } while (0)

#define DECR_USED_MSG_NUM(storage_type) do { \
        smsal_cntx_ptr->storage_num_info.used_sim_msg_num = \
                                                       smsal_cntx_ptr->storage_num_info.used_sim_msg_num - 1; \
    } while (0)

#else
#define INCR_USED_MSG_NUM(storage_type) do { \
        if(storage_type == SMSAL_SM) \
        { \
            smsal_cntx_ptr->storage_num_info.used_sim_msg_num =  \
            smsal_cntx_ptr->storage_num_info.used_sim_msg_num + 1; \
        } else if (storage_type == SMSAL_ME) \
        { \
            smsal_cntx_ptr->storage_num_info.used_me_msg_num =  \
            smsal_cntx_ptr->storage_num_info.used_me_msg_num + 1; \
        } \
    } while (0)

#define DECR_USED_MSG_NUM(storage_type) do { \
        if(storage_type == SMSAL_SM) \
        { \
            smsal_cntx_ptr->storage_num_info.used_sim_msg_num =  \
            smsal_cntx_ptr->storage_num_info.used_sim_msg_num - 1; \
        } else if (storage_type == SMSAL_ME) \
        { \
            smsal_cntx_ptr->storage_num_info.used_me_msg_num =  \
            smsal_cntx_ptr->storage_num_info.used_me_msg_num - 1; \
        } \
    } while (0)
#endif /* !defined (__SMS_ME_STORAGE__) */

#define WHICH_MSGBOX(_s1,_s2) ((_s1 | (_s2 & 0x0f) ) == _s1) ? KAL_TRUE : KAL_FALSE


#ifdef __SMS_ME_STORAGE__ 
#define INCR_MSGBOX_NUM(status,storage_type) do { \
        if(WHICH_MSGBOX(SMSAL_STATUS_INBOX,status) == KAL_TRUE) { \
            if(storage_type == SMSAL_SM) \
                smsal_cntx_ptr->storage_num_info.inbox_sim_num++; \
            else if(storage_type == SMSAL_ME) \
                smsal_cntx_ptr->storage_num_info.inbox_me_num++; \
        } else { \
            if(storage_type == SMSAL_SM) \
                smsal_cntx_ptr->storage_num_info.outbox_sim_num++;\
            else if(storage_type == SMSAL_ME) \
                smsal_cntx_ptr->storage_num_info.outbox_me_num++; } } while (0)

#define DECR_MSGBOX_NUM(status,storage_type) do { \
        if(WHICH_MSGBOX(SMSAL_STATUS_INBOX,status) == KAL_TRUE) { \
            if(storage_type == SMSAL_SM) \
                smsal_cntx_ptr->storage_num_info.inbox_sim_num--; \
            else if(storage_type == SMSAL_ME) \
                smsal_cntx_ptr->storage_num_info.inbox_me_num--; \
        }  else { \
            if(storage_type == SMSAL_SM) \
                smsal_cntx_ptr->storage_num_info.outbox_sim_num--; \
            else if(storage_type == SMSAL_ME) \
                smsal_cntx_ptr->storage_num_info.outbox_me_num--; } } while (0)

#else
/* not support ME storage */
#define INCR_MSGBOX_NUM(status,storage_type) do { \
        if(WHICH_MSGBOX(SMSAL_STATUS_INBOX,status) == KAL_TRUE) \
            smsal_cntx_ptr->storage_num_info.inbox_sim_num++; \
        else smsal_cntx_ptr->storage_num_info.outbox_sim_num++; } while (0)

#define DECR_MSGBOX_NUM(status,storage_type) do { \
        if(WHICH_MSGBOX(SMSAL_STATUS_INBOX,status) == KAL_TRUE) \
            smsal_cntx_ptr->storage_num_info.inbox_sim_num--; \
        else smsal_cntx_ptr->storage_num_info.outbox_sim_num--; } while (0)
#endif /* __SMS_ME_STORAGE__ */



typedef enum
{
    SMSAL_MB_INIT,
    SMSAL_MB_FREE
} smsal_mb_init_enum;

#ifndef __SMS_STORAGE_BY_MMI__
void smsal_reset_msg_box_entry(kal_uint16 id, kal_uint8 mb_state);
void smsal_init_msg_box(void);
kal_bool smsal_alloc_msg_box(kal_uint16 size);
void smsal_dealloc_msg_box(void);
kal_bool smsal_get_unused_mb_entry(kal_uint16 *entry_id);
kal_bool smsal_get_free_mb_entry(smsal_storage_enum storage_type,
                                 kal_uint16 *entry_id);
kal_bool smsal_decode_msg_into_msgbox(kal_uint16 entry_id,
                                      smsal_read_file_aux_info_struct *aux_info,
                                      smsal_storage_enum storage_type,
                                      kal_uint8 *data,
                                      kal_uint16 length);
void smsal_update_msgbox_from_tpdu(smsal_mb_entry_struct    *entry_ptr,
                                   smsal_tpdu_decode_struct *tpdu_decode);
void smsal_update_msgbox_for_report(smsal_status_report_peer_struct *rep_ptr);
void smsal_update_msgbox_for_report_cnf(kal_uint8         id,
                                        ilm_struct *ilm_ptr,
                                        kal_bool          is_from_sim);
#endif //__SMS_STORAGE_BY_MMI__

#ifdef __FIX_7BIT_EMPTY_CONTENT__
void smsal_init_fix_7bit_empty_content(smsal_pdu_decode_struct *sms_pdu,
                                                 kal_uint8 *data,
                                                 smsal_mb_entry_struct *entry);
#endif /*__FIX_7BIT_EMPTY_CONTENT__*/

#endif /* end of smsal_msg_storage.h */

