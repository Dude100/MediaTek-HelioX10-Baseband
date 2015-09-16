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
 *	smsal_msg_proc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is the header file of smsal_msg_proc.c.
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

#ifndef _SMSAL_MSG_PROC_H
#define _SMSAL_MSG_PROC_H

#include "l4c2smsal_struct.h"
#include "smsal_peer_struct.h"
#include "smslib_def.h"
#include "smsal_structs.h"
#include "l3_inc_enums.h"
#include "smsal_enums.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "mcd_l4_common.h"
#include "kal_general_types.h"

void smsal_construct_tpdu(smsal_send_msg_req_hdr_struct *msg_ptr,
                          smsal_submit_peer_struct  *submit_ptr,
                          kal_uint16                msg_len,
                          kal_uint8                 *msg_data,
                          kal_uint8                 src_id );


void smsal_construct_msg_to_storage(kal_uint8                     data[],
                                    l4csmsal_write_req_struct     *write_req,
                                    kal_uint16                    msg_len,
                                    kal_uint8                     *msg_data);

#if defined(__SMS_STORAGE_BY_MMI__)
//NA
#else
void smsal_construct_mt_msg_to_storage(kal_uint8                     data[],
                                       smsal_receive_msg_hdr_struct *msg_recv_ptr,
                                       kal_uint16                    msg_len,
                                       kal_uint8                     *msg_data);
#endif

void smsal_construct_deliver_msg(local_para_struct *local_para_ptr);

void smsal_get_msg_ref_hdlr(kal_uint8 id , kal_uint8 *msg_ref);

#if defined(__SMS_STORAGE_BY_MMI__)
kal_bool smsal_check_rmi_use_hex(kal_uint8                src_id,
                                 smslib_general_struct    *sms_pdu);
#else
kal_bool smsal_check_rmi_use_hex(kal_uint8                src_id,
                                 smsal_pdu_decode_struct  *sms_pdu);
#endif

#if defined(__SMS_STORAGE_BY_MMI__)
peer_buff_struct *smsal_get_msg_content_ext(kal_uint8                rmi_use_hex,
                                            smslib_general_struct    *sms_pdu,
                                            kal_uint16               *msg_len,
                                            smsal_header_info_union  *msg_header);
#else
peer_buff_struct *smsal_get_msg_content(kal_uint8                rmi_use_hex,
                                        smsal_pdu_decode_struct  *sms_pdu,
                                        kal_uint16               *msg_len,
                                        smsal_header_info_union  *msg_header);
#endif

void smsal_unpack_msg(kal_uint8 dcs,
                      kal_uint8 *msg_ptr,
                      kal_uint8 *data,
                      kal_uint16 length,
                      kal_uint16 offset);

/* read */

#ifndef __SMS_STORAGE_BY_MMI__
void smsal_read_index(l4csmsal_read_req_struct *read_req);
void smsal_read_next(l4csmsal_read_req_struct *read_req);

#ifdef __SMS_RAW_DATA_ACCESS_SUPPORT__
void smsal_read_raw_data_index(l4csmsal_read_raw_data_req_struct *read_req);
void smsal_read_raw_data_cnf(kal_uint8  id,
                             kal_uint8  sub_act_code,
                             ilm_struct *ilm_ptr,
                             kal_bool   is_from_sim);
void smsal_read_raw_data_rej(kal_uint8 old_id, kal_uint16 error_cause);

void smsal_write_raw_data_cnf(kal_uint8 result,
                              kal_uint8 src_id,
                              smsal_error_cause_enum error_cause,
                              kal_uint16 index,
                              kal_uint8  status);

void smsal_write_raw_data_rej(kal_uint8 old_id, kal_uint16 error_cause);

void smsal_write_raw_data_single(kal_uint8 id,
                                 l4csmsal_write_raw_data_req_struct *write_req,
                                 kal_uint8 *msg_ptr, kal_uint16 pdu_len);

void smsal_write_raw_data_single_cnf(kal_uint8 old_id,
                                     local_para_struct *local_para_ptr);
#endif


/* write */

void smsal_write_single(kal_uint8 id,
                        l4csmsal_write_req_struct *write_req,
                        void *msg_ptr
                       );

void smsal_write_cnf(kal_uint8 result,
                     kal_uint8 src_id,
                     smsal_error_cause_enum error_cause,
                     kal_uint16 index,
                     kal_uint8  status);

/* delete */
void smsal_delete_index(l4csmsal_delete_req_struct *del_req);
void smsal_delete_flag(l4csmsal_delete_req_struct *del_req);
void smsal_del_cnf(kal_uint8 result,
                   l4csmsal_delete_req_struct  *del_req,
                   l4csmsal_delete_cnf_struct  *del_cnf,
                   smsal_error_cause_enum error_cause) ;
#endif //__SMS_STORAGE_BY_MMI__

/* set param */
void smsal_set_param_cnf(kal_uint8 result,
                         kal_uint8 src_id,
                         msg_type msg_id,
                         smsal_error_cause_enum error_cause);

#ifndef __SMS_STORAGE_BY_MMI__
/* send from storage */
void smsal_update_for_send_fr_succ(kal_uint8 id);

/* main READ cnf/rej hdlr */
void smsal_read_cnf(kal_uint8  id,
                    kal_uint8  sub_act_code,
                    ilm_struct *ilm_ptr,
                    kal_bool   is_from_sim);


/* sub READ cnf/rej hdlr */
void smsal_read_single_cnf(kal_uint8 old_id,
                           kal_uint8  *scts_ptr,
                           kal_uint8 *pdu_ptr,
                           kal_uint16 pdu_len);

void smsal_read_rej(kal_uint8 old_id, kal_uint16 error_cause);

/* Main WRITE CNF/REJ Handlers */
void smsal_write_confirm(kal_uint8 id,
                         kal_uint8 sub_act_code,
                         local_para_struct *local_para_ptr);

void smsal_write_rej(kal_uint8 old_id, kal_uint16 error_cause);

/* Sub WRITE CNF/REJ Handlers */
void smsal_write_single_cnf(kal_uint8 old_id,
                            local_para_struct *local_para_ptr);

/* Main DEL CNF/REJ Handlers */
void smsal_delete_cnf(kal_uint8 id,
                      kal_uint8 sub_act_code,
                      local_para_struct *local_para_ptr);

void smsal_delete_rej(kal_uint8 id,
                      kal_uint8 sub_act_code,
                      kal_uint16 cause);

/* Sub DEL CNF/REJ Handlers */
void smsal_delete_index_cnf(kal_uint8 old_id,
                            local_para_struct *local_para_ptr);

void smsal_delete_index_rej(kal_uint8 old_id, kal_uint16 cause);

void smsal_delete_flag_cnf(kal_uint8 old_id,
                           local_para_struct *local_para_ptr);
void smsal_delete_flag_rej(kal_uint8 old_id, kal_uint16 cause);

#ifdef __SMSAL_DISCARD_PATENT__
void smsal_delete_by_patent_cnf(kal_uint8 old_id);

void smsal_delete_by_patent_rej(kal_uint8 old_id);
#endif

void smsal_copy_action_cnf(kal_uint8         id,
                           kal_uint8         sub_act_code,
                           ilm_struct        *ilm_ptr,
                           kal_bool          is_from_sim);

void smsal_copy_action_rej(kal_uint8  id,
                           kal_uint8  sub_act_code,
                           kal_uint16 error_cause);
void smsal_copy_read_msg_cnf(kal_uint8     id,
                             ilm_struct    *ilm_ptr,
                             kal_bool      is_from_sim);
void smsal_copy_write_msg_cnf(kal_uint8 id);
void smsal_copy_delete_msg_cnf(kal_uint8 id);

void smsal_set_status_action_cnf(kal_uint8         id,
                                 kal_uint8         sub_act_code,
                                 ilm_struct        *ilm_ptr,
                                 kal_bool          is_from_sim);

void smsal_set_status_action_rej(kal_uint8  id,
                                 kal_uint8  sub_act_code,
                                 kal_uint16 error_cause);
void smsal_set_status_read_msg_cnf(kal_uint8     id,
                                   ilm_struct    *ilm_ptr,
                                   kal_bool      is_from_sim);
void smsal_set_status_write_msg_cnf(kal_uint8 id);


/* Main SEND FROM STORAGE CNF/REJ Handlers */
void smsal_send_from_storage_cnf(kal_uint8 id,
                                 kal_uint8 sub_act_code,
                                 ilm_struct        *ilm_ptr,
                                 kal_bool          is_from_sim);

void smsal_send_from_storage_rej(kal_uint8 id,
                                 kal_uint8 sub_act_code,
                                 kal_uint16 cause);

void smsal_read_msg_from_storage_hdlr(kal_uint8     old_id,
                                      ilm_struct    *ilm_ptr,
                                      kal_bool      is_from_sim);

void smsal_msgbox_msg_post_hdlr(kal_uint8  id);

/* Sub SEND FROM STORAGE CNF/REJ Handlers */
void smsal_msgbox_post(kal_uint8 old_id, kal_uint8 msg_ref);
void smsal_msgbox_msg_post_cnf(kal_uint8     old_id,
                               ilm_struct    *ilm_ptr,
                               kal_bool      is_from_sim);
#endif //__SMS_STORAGE_BY_MMI__

void smsal_send_mo_sms_cnf(kal_uint8         id,
                           kal_uint8         sub_act_code,
                           ilm_struct        *ilm_ptr,
                           kal_bool          is_from_sim);


kal_bool smsal_get_rp_sms_info(smsal_sat_addr_struct      *sat_addr,
                               ilm_struct                 *ilm_ptr,
                               kal_bool                   is_from_sim);

#ifndef __SMS_STORAGE_BY_MMI__
void smsal_send_fr_read_rp_cnf(kal_uint8       id,
                               ilm_struct      *ilm_ptr,
                               kal_bool        is_from_sim);
#endif

void smsal_mo_sms_read_rp_cnf(kal_uint8       id,
                              ilm_struct      *ilm_ptr,
                              kal_bool        is_from_sim);


void smsal_send_mo_sms_rej(kal_uint8         id,
                           kal_uint8         sub_act_code,
                           kal_uint16        cause);

peer_buff_struct *smsal_get_status_report(smsal_status_report_peer_struct *status_ptr,
                                          kal_uint16               *msg_len,
                                          smsal_header_info_union  *msg_header);

#if defined(__SMSAL_XXX_C)
peer_buff_struct *smsal_get_user_data_content(smsal_tpdu_decode_struct *tpdu ,
                                              kal_uint16               *msg_len,
                                              l4_addr_bcd_struct       *oa_addr,
                                              kal_uint8                *scts);
#endif

#if !defined(__SMS_STORAGE_BY_MMI__)
void smsal_send_copy_cnf(kal_uint8 result,
                         smsal_error_cause_enum error_cause,
                         l4csmsal_copy_msg_req_struct *copy_req,
                         kal_uint16 dst_index) ;

void smsal_send_set_status_cnf(kal_uint8 result,
                               smsal_error_cause_enum       error_cause,
                               l4csmsal_set_status_req_struct *set_status_req);
#endif


void smsal_get_mailbox_num_cnf(kal_uint8    result,
                               kal_uint32   error_cause,
                               kal_uint8    src_id);

void smsal_set_msg_waiting_cnf(kal_bool     result,
                               kal_uint16   error_cause,
                               l4csmsal_set_msg_waiting_req_struct *set_msg_waiting_req);


#ifdef __CPHS__
void smsal_get_ext1_num_cnf(void);
#endif

/* __IMS_SUPPORT__ */
void smsal_send_ims_mo_sms_cnf(kal_uint8 id, kal_uint8 sub_act_code);

void smsal_send_ims_mo_sms_rej(kal_uint8 id, kal_uint8 sub_act_code, kal_uint16 cause);

void smsal_ims_mem_avl_get_msg_ref_cnf(kal_uint8 id);
#endif /* _SMSAL_MSG_PROC_H */


