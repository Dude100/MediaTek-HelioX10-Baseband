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
 *	smsal_l4c_msgs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is the header file of smsal_l4c.c
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

#ifndef _SMSAL_L4C_MSGS_H
#define _SMSAL_L4C_MSGS_H

#include "kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "smsal_structs.h"
#include "smsal_l4c_enum.h"
#include "smslib_def.h"
#include "smsal_peer_struct.h"
#include "mnsms_struct.h"
#include "kal_general_types.h"
#include "ps_public_struct.h"
#include "sim_common_enums.h"


void smsal_l4c_entry_func(ilm_struct *ilm_ptr);

void smsal_send_msg_to_l4c(msg_type msg_id,
                           local_para_struct *local_para_ptr,
                           peer_buff_struct *peer_buff_ptr
                          );

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*
 * Handlers for handling requests from L4C
 */

kal_bool smsal_start_handler(READ_FILE_FINISH_FUNC fn_ptr,
                             kal_uint8         id,
                             kal_uint8         act_code,
                             kal_bool          send_init_cnf,
                             local_para_struct *local_para_ptr
                            );
void smsal_early_start_handler(void);
void smsal_early_start_finish(kal_uint8 id, kal_bool result);
void smsal_early_init_pending_act_hdlr(void);
void smsal_init_req_handler(local_para_struct *local_para_ptr);
#if defined(__CANCEL_LOCK_POWERON__)
void smsal_init_me_only_req_handler(local_para_struct *local_para_ptr);
#endif

void smsal_reread_files_handler(smsal_file_enum file_id[],
                                kal_uint8 file_list_cnt,
                                kal_uint32 file_type_bitmap,
                                READ_FILE_ERROR_FUNC  error_fn_ptr,
                                READ_FILE_FINISH_FUNC finish_fn_ptr,
                                local_para_struct *local_ptr,
                                kal_uint8 src_id);

void smsal_reread_mailbox_num_file_finish(kal_uint8 id, kal_bool result);

/* related to short message manuipulations  */
void smsal_delete_handler(local_para_struct *local_para_ptr);

void smsal_read_handler(local_para_struct *local_para_ptr);
void smsal_write_handler(local_para_struct *local_para_ptr,
                         peer_buff_struct *peer_buff_ptr);

#ifdef __SMS_RAW_DATA_ACCESS_SUPPORT__
void smsal_read_raw_data_handler(local_para_struct *local_para_ptr);
void smsal_write_raw_data_handler(local_para_struct *local_para_ptr,
                                  peer_buff_struct *peer_buff_ptr);
#endif

/* related to SEND short message */
void smsal_send_handler(local_para_struct *local_para_ptr,
                        peer_buff_struct *peer_buff_ptr);

void smsal_mo_sms_fdn_check(kal_uint8 id);
void smsal_send_by_sim_ctrl(kal_uint8 id, kal_uint8 sub_act_code);

#ifndef __SMS_STORAGE_BY_MMI__
void smsal_send_from_storage_handler(local_para_struct *local_para_ptr);
void smsal_send_from_storage_fdn_check(kal_uint8 id);
#endif

#ifdef __SMS_STORAGE_BY_MMI__
void smsal_send_deliver_report_handler(local_para_struct *local_para_ptr);
void smsal_sync_msg_storage_handler(local_para_struct *local_para_ptr);
#endif
void smsal_send_abort_handler(local_para_struct *local_para_ptr);

/* related to set parameter */
void smsal_set_common_para_handler(local_para_struct *local_ptr);
void smsal_set_profile_para_handler(local_para_struct *local_ptr);
#ifndef EMPTY_MMI
void smsal_startup_read_next_handler(void);
#endif
void smsal_fdn_check_rsp_handler(local_para_struct *local_ptr);

#ifndef __SMS_STORAGE_BY_MMI__
void smsal_copy_msg_req_handler(local_para_struct *local_ptr);
void smsal_set_status_req_handler(local_para_struct *local_ptr);
#endif

void smsal_get_mailbox_num_req_handler(local_para_struct *local_ptr);
void smsal_set_msg_waiting_req_handler(local_para_struct *local_ptr);
#ifdef __CPHS__
void smsal_get_ext1_num_req_handler(local_para_struct *local_ptr);
#endif
/*
 * Handlers for sending indications to L4C
 */
#ifdef __SMS_DEPERSONALIZATION__

#if defined(__SMS_STORAGE_BY_MMI__)
kal_bool smsal_de_personalization_req(kal_uint8 smi, smslib_general_struct *pdu_decode);
#else
kal_bool smsal_de_personalization_req(kal_uint8 smi, smsal_pdu_decode_struct *pdu_decode);
#endif

void smsal_de_personalization_rsp(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif
void smsal_mem_available_ind(kal_uint8 type);
void smsal_mem_exceed_ind(kal_uint8 type);
void smsal_mem_full_ind(kal_uint8 type);
void smsal_msg_waiting_ind(kal_uint8                line_no,
                       #ifdef __REL4__
                           kal_uint8                msp_no,
                       #endif
                           kal_uint8                ind_type,
                           smsal_msg_waiting_struct *msg_ptr,
                           kal_bool                 is_from_storage);

void smsal_msg_waiting_ext_ind(kal_uint8                line_no,
                               kal_uint8                msp_no,
                               kal_bool                 is_from_storage);

#ifdef __SMS_R6_ENHANCED_VOICE_MAIL__
void smsal_evm_ind(smsal_msg_waiting_struct *msg_ptr);
#endif

void smsal_send_service1_cnf(kal_uint8           result,
                             kal_uint8           src_id,
                             kal_uint8           msg_ref,
                             kal_uint8           scts[],
                             peer_buff_struct    *peer_buff_ptr,
                             kal_uint16          cause,
                             kal_uint8           seq_num,
                             smsal_concat_struct concat_info);

/*
 * New Message Indications
 */
/* MAUI_00748299 [SMSAL][Revise] Add SC in status report */
void smsal_status_report_ind(smsal_status_report_peer_struct *status_ptr,
                             peer_buff_struct             *peer_buff_ptr,
                             kal_uint8                    dest_id,
                             sms_addr_struct              *sc_addr
                            );

#if defined(__SMS_STORAGE_BY_MMI__)
void smsal_new_msg_pdu_ind(smslib_general_struct    *pdu_decode,
                           kal_uint8                dest_id,
                           peer_buff_struct         *peer_buff_ptr,
                           kal_uint8                cnmi_id);

void smsal_new_msg_text_ind(smslib_general_struct   *pdu_decode,
                            kal_uint8               dest_id,
                            kal_uint8               cnmi_id,
                            kal_uint8               lmi_ind,
                            kal_uint16              index);
#else
void smsal_new_msg_pdu_ind(smsal_pdu_decode_struct  *pdu_decode,
                           kal_uint8                dest_id,
                           peer_buff_struct         *peer_buff_ptr,
                           kal_uint8                cnmi_id);

void smsal_new_msg_text_ind(smsal_pdu_decode_struct *pdu_decode,
                            kal_uint8               dest_id,
                            kal_uint8               cnmi_id,
                            kal_uint8               lmi_ind,
                            kal_uint16              index);
#endif

#ifndef __SMS_STORAGE_BY_MMI__
void smsal_new_msg_index_ind(kal_uint8 dest_id,
                             kal_uint16 index,
                             smsal_tpdu_decode_struct *tpdu);

void smsal_dispatch_stored_new_msg(smsal_mt_msg_aux_info_struct *aux_info,
                                   peer_buff_struct             *peer_ptr);
#endif

void smsal_init_vm_ind(void);

#if defined (__SAT__)
void smsal_sat_send_handler(local_para_struct *local_ptr);

void smsal_process_sat_send_msg(kal_uint8 id);


void smsal_sat_send_cnf(kal_uint8  src_id,
                        kal_uint8  res_code,
                        kal_uint8  error_cause);

void smsal_sat_send_sms_res(sat_terminal_res_enum res, sat_additional_info_for_res_enum cause);

#endif /* __SAT__ */

void smsal_new_app_data_ind(smsal_tpdu_decode_struct *tpdu ,
                            kal_uint16               dest_id);

#ifndef __SMS_STORAGE_BY_MMI__
#ifndef EMPTY_MMI
void smsal_startup_read_msg_ind(smsal_pdu_decode_struct *pdu_decode,
                                kal_uint16              index,
                                kal_uint8               status,
                                kal_uint8               *startup_seq_num,
                                kal_uint8               *scts_ptr);
#endif

void smsal_pending_act_hdlr(void);
#endif

/* __IMS_SUPPORT__ */
extern void smsal_ims_mo_sms_fdn_check(kal_uint8 id);

extern void smsal_ims_send_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void smsal_ims_recv_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void smsal_ims_deliver_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void smsal_ims_status_report_handler(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void smsal_ims_send_mem_avl_notif_req(local_para_struct *local_para_ptr);

extern void smsal_ims_send_mem_avl_notif_result_handler(local_para_struct *local_para_ptr);

extern void smsal_ims_new_msg_pdu_ind(smsal_pdu_decode_struct *pdu_decode, kal_uint8 dest_id, peer_buff_struct *peer_buff_ptr, kal_uint8 cnmi_id);

extern void smsal_ims_new_msg_text_ind(smsal_pdu_decode_struct *pdu_decode, kal_uint8 dest_id, kal_uint8 cnmi_id, kal_uint8 lmi_ind, kal_uint16 index);

extern void smsal_ims_dispatch_stored_new_msg(smsal_mt_msg_aux_info_struct *aux_info, peer_buff_struct *peer_ptr);

extern void smsal_ims_status_report_ind(smsal_status_report_peer_struct *status_ptr, peer_buff_struct *peer_buff_ptr, kal_uint8 dest_id, sms_addr_struct *sc_addr);

#endif /* _SMSAL_L4C_MSGS_H */


