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
 *	smsal_checks.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains function propotype of smsal_checks.c
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


#ifndef _SMSAL_CHECKS_H
#define _SMSAL_CHECKS_H

#include "l3_inc_enums.h"
#include "smsal_enums.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h"
#include "l4c2smsal_struct.h"
#include "smsal_l4c_enum.h"
#include "kal_general_types.h"

/* These functions checks for Data coding scheme of peer messages */
kal_bool smsal_dcs_check(kal_uint8 dcs,
                         smsal_error_cause_enum *fail_cause_ptr);

/* These functions checks for protocol identifier of peer messages */
kal_bool smsal_pid_check(kal_uint8               pid,
                         smsal_error_cause_enum *fail_cause_ptr,
                         kal_uint8              *aux_info);


kal_bool smsal_l4c_msg_checks(msg_type               l4c_msg,
                              void                   *msg_ptr,
                              void                   *aux_info,
                              smsal_error_cause_enum *error_cause);

kal_bool smsal_sms_msg_checks(msg_type      msg_type,
                              void          *msg_ptr,
                              kal_uint8     msg_id,
                              kal_uint8     *aux_info);

kal_bool smsal_check_profile_para(l4csmsal_set_profile_para_req_struct *set_req,
                                  smsal_error_cause_enum *error_cause);
kal_bool smsal_check_common_para(l4csmsal_set_common_para_req_struct *set_req,
                                 smsal_error_cause_enum *error_cause);

kal_bool smsal_fo_check(kal_uint8 fo);
kal_bool smsal_bearer_check(kal_uint8 bearer);
kal_bool smsal_prefer_mem_check(smsal_select_mem_struct *prefer_mem);

#ifndef __SMS_STORAGE_BY_MMI__
kal_bool smsal_check_reply_index(kal_uint16 reply_index,
                                 smsal_error_cause_enum *error_cause);
#endif

kal_bool smsal_send_msg_req_struct_check(smsal_send_msg_req_hdr_struct *send_msg_ptr,
                                         kal_uint16 message_len,
                                         smsal_error_cause_enum *error_cause);
#if !defined(__SMS_STORAGE_BY_MMI__)
kal_bool smsal_recv_msg_req_struct_check(smsal_receive_msg_hdr_struct *send_msg_ptr,
                                         kal_uint16                   message_len,
                                         smsal_error_cause_enum       *error_cause);
#endif

kal_bool smsal_deliver_pdu_check(kal_uint16 message_len,
                                 peer_buff_struct *peer_buff_ptr,
                                 smsal_error_cause_enum *error_cause);
kal_bool smsal_submit_pdu_check(kal_uint16 message_len,
                                kal_uint16 pdu_len,
                                kal_uint8  *pdu_ptr,
                                smsal_error_cause_enum       *error_cause);

kal_bool smsal_check_send_msg(kal_uint8               src_id,
                              kal_uint16              message_len,
                              smsal_send_type_enum    sms_msg_type,
                              void                    *msg_ptr,
                              peer_buff_struct        *peer_buff_ptr,
                              smsal_error_cause_enum  *error_cause);

#if !defined(__SMS_STORAGE_BY_MMI__)
kal_bool smsal_check_receive_msg(kal_uint8               src_id,
                                 kal_uint16              message_len,
                                 void                    *msg_ptr,
                                 peer_buff_struct        *peer_buff_ptr,
                                 smsal_error_cause_enum  *error_cause);
#endif

#endif /* end of _SMSAL_CHECKS_H */


