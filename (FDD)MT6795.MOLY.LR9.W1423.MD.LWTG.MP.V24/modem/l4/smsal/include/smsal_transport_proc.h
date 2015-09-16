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
 *	smsal_transport_proc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains function prototypes of SMSAL transport functions.
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


#ifndef _SMSAL_TRANSPORT_PROC_H
#define _SMSAL_TRANSPORT_PROC_H

#include "smsal_l4c_enum.h"
#include "smsal_structs.h"
#include "kal_public_api.h"
#include "mnsms_struct.h"
#include "smsal_peer_struct.h"
#include "l4c2smsal_struct.h"
#include "l3_inc_enums.h"
#include "smsal_enums.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "smslib_def.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_general_types.h"

void smsal_consult_nmi_table(smsal_msg_class_enum mclass,
                             kal_uint8 *table1,
                             kal_uint8 *table2,
                             kal_uint8 *table3);

void smsal_nmi_table_class0_mwd_update(void);

/*
 * MT SMS
 */
#ifndef __SMS_STORAGE_BY_MMI__
void smsal_message_waiting_handler(smsal_pdu_decode_struct *pdu_decode);
#endif

kal_bool smsal_mt_msg_hdlr(smsal_pdu_decode_struct *pdu_decode,
                           peer_buff_struct        *peer_buff_ptr,
                           sms_deliver_struct      *local_ptr);

#if defined(__SMS_STORAGE_BY_MMI__)
#else
smsal_pdu_decode_struct *smsal_decode_mt_msg(
    smsal_deliver_peer_struct *deliver_ptr,
    sms_deliver_struct        *local_ptr,
    kal_uint8                 *pdu_ptr,
    kal_uint16                pdu_len);
#endif

/*
 * MO SMS
 */
void smsal_mo_sms_hdlr(kal_uint8 id);

kal_bool smsal_get_mo_sms_info(l4csmsal_send_req_struct     *send_req,
                               peer_buff_struct             *peer_buff_ptr,
                               smsal_send_sms_aux_info_struct *sms_info,
                               smsal_error_cause_enum       *error_cause);

#ifndef __SMS_STORAGE_BY_MMI__
kal_bool smsal_reply_index_hdlr(kal_uint8     id,
                                kal_uint16    reply_index);
#endif

void smsal_fdn_check_hdlr(kal_uint8 id) ;

void
smsal_send_msg_text_mode(l4csmsal_send_req_struct  *send_req,
                         kal_uint8                 msg_ref,
                         sms_addr_struct           *sc_addr,
                         peer_buff_struct          *peer_buff_ptr);

void
smsal_send_cmd_text_mode(l4csmsal_send_req_struct  *send_req,
                         kal_uint8                 msg_ref,
                         smsal_sat_addr_struct     *sat_addr,
                         peer_buff_struct          *peer_ptr);

void
smsal_send_submit_to_sms(kal_uint8         msg_ref,
                         kal_uint8         src_id,
                         kal_uint8         seq_num,
                         kal_uint8         mms_mode,
                         peer_buff_struct  *peer_buff_ptr,
                         sms_addr_struct   *sc_addr);

void
smsal_send_command_to_sms(kal_uint8         msg_ref,
                          kal_uint8         src_id,
                          kal_uint8         seq_num,
                          kal_uint8         mms_mode,
                          peer_buff_struct  *peer_buff_ptr,
                          sms_addr_struct   *sc_addr);

void
smsal_send_pdu_mode(kal_uint8            msg_ref,
                    kal_uint8            src_id,
                    kal_uint8            seq_num,
                    kal_uint8            mms_mode,
                    smsal_mti_enum       mti,
                    peer_buff_struct     *peer_buff_ptr,
                    sms_addr_struct      *sc_addr);

#ifndef __SMS_STORAGE_BY_MMI__


kal_bool smsal_store_new_msg(kal_uint8                 id,
                             kal_uint8                 *pdu_ptr,
                             kal_uint16                pdu_len,
                             sms_deliver_struct        *local_ptr
                            );
#endif

void smsal_check_cnma_sent_ack_hdlr(kal_uint8           msg_class,
                                    kal_uint8           smi,
                                    kal_bool            *sent_ack);

void smsal_new_msg_ind(smsal_pdu_decode_struct  *pdu_decode,
                       kal_uint8                smi,
                       peer_buff_struct         *peer_buff_ptr);

extern kal_uint8 SMSAL_NMI_TABLE1[4][NUM_OF_NMI_MSG_ENUM];
extern kal_uint8 SMSAL_NMI_TABLE2[4][NUM_OF_NMI_MSG_ENUM];
extern kal_uint8 SMSAL_NMI_TABLE3[4][NUM_OF_NMI_MSG_ENUM];

#if !defined (__MTK_TARGET__) && defined (__SMSAL_UT__)

extern kal_uint8 tst_sat_mo_sms_ctrl_support;		//for UT coverage, skipping SIM check while MO SMS,then enter CTRL_BY_SIM procedureextern kal_uint8 tst_data_download_sms_support;
extern kal_uint8 tst_data_download_sms_support;		//for UT coverage, skipping SIM check while MT SMS with SIM download

#endif

#ifndef __SMS_STORAGE_BY_MMI__

/*
 * Replace message
 */
#ifdef __SMS_DELAY_MTSMS_REPLACE_TYPE__
kal_bool smsal_msg_replace_pending_hdlr(local_para_struct *local_para_ptr,
                                        peer_buff_struct  *peer_buff_ptr,
                                        smsal_pdu_decode_struct  *pdu_decode);
#endif

kal_bool smsal_msg_replace_hdlr(smsal_pdu_decode_struct   *pdu_decode,
                                peer_buff_struct     *peer_buff_ptr,
                                sms_deliver_struct   *local_ptr);

void smsal_replace_read_msg_cnf(kal_uint8   old_id,
                                ilm_struct  *ilm_ptr,
                                kal_bool    is_from_sim);
void smsal_replace_write_msg_cnf(kal_uint8 old_id);
void smsal_replace_msg_rej(kal_uint8 old_id);

void smsal_store_new_msg_cnf(kal_uint8 old_id);
void smsal_store_new_msg_rej(kal_uint8 old_id);

void smsal_deliver_cnf(kal_uint8   old_id,
                       kal_uint8   sub_act_code,
                       ilm_struct  *ilm_ptr,
                       kal_bool    is_from_sim);

void smsal_deliver_rej(kal_uint8 old_id,
                       kal_uint8 sub_act_code);
#endif

/*
 * Submit Report
 */
void
smsal_update_submit_report(kal_uint8  result,
                           kal_uint8  smi,
                           kal_uint8  udh_p,
                           kal_uint8  *user_data,
                           kal_uint8  *scts,
                           kal_uint16 cause,
#ifdef __SAT__
                           kal_uint8  sat_res_code,
                           kal_uint8  sat_cause,
#endif

                           peer_buff_struct *peer_buff_ptr);

/*
 * Deliver Report
 */
void smsal_deliver_nack_post(kal_uint8               smi,
                             smsal_error_cause_enum  failure_cause,
                             kal_uint8               para_ind,
                             kal_uint8               pid,
                             kal_uint8               dcs,
                             kal_uint8               data_len,
                             kal_uint8               *data);

void smsal_deliver_ack_post(kal_uint8   smi,
                            kal_uint8   para_ind,
                            kal_uint8   pid,
                            kal_uint8   dcs,
                            kal_uint8   data_len,
                            kal_uint8   *data);

#if defined (__SAT__)
void
smsal_sat_send_msg(l4csmsal_sat_send_req_struct *send_req,
                   kal_uint8                    msg_ref);

void
smsal_sat_send(msg_type                     msg_type,
               l4csmsal_sat_send_req_struct *send_req,
               kal_uint8                    msg_ref);

kal_bool smsal_sat_mo_msg_ctrl(kal_uint8             id,
                               smsal_sat_addr_struct *sat_addr);

void smsal_sat_send_mo_sms_cnf(kal_uint8         access_id,
                               kal_uint8         sub_act_code);

void smsal_sat_send_mo_sms_rej(kal_uint8         access_id,
                               kal_uint8         sub_act_code,
                               kal_uint16        cause);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
void smsal_sat_mo_sms_ctrl_cnf(kal_uint8         id,
                               kal_uint8         sub_act_code,
                               local_para_struct *local_para_ptr);
#if defined(__SMS_STORAGE_BY_MMI__)
kal_bool smsal_sim_data_dl_hdlr(smslib_deliver_peer_struct  *deliver_ptr,
                                peer_buff_struct            *peer_buff_ptr,
                                sms_addr_struct             *sc_addr,
                                kal_uint8                   smi);
#else
kal_bool smsal_sim_data_dl_hdlr(smsal_deliver_peer_struct *deliver_ptr,
                                peer_buff_struct          *peer_buff_ptr,
                                sms_addr_struct           *sc_addr,
                                kal_uint8                 smi);
#endif

void smsal_sim_data_download_cnf(kal_uint8         id,
                                 local_para_struct *local_para_ptr);
#endif /* __SAT__ */

void smsal_forward_to_socket(peer_buff_struct *peer_buff_ptr,
                             smsal_tpdu_decode_struct *tpdu,
                             sms_addr_struct *sc_addr);

void smsal_soc_entry_func(ilm_struct *ilm_ptr);

module_type smsal_dispatcher(kal_int32 port);

kal_bool smsal_is_avl_for_new_msg(smsal_tpdu_decode_struct  *tpdu_decode,
                                  smsal_storage_enum        *storage_type_out,
                                  kal_uint8                 *error_cause);

/* __IMS_SUPPORT__ */
extern kal_bool smsal_get_ims_mo_sms_info(l4csmsal_ims_send_req_struct *send_req, peer_buff_struct *peer_buff_ptr, smsal_send_sms_aux_info_struct *sms_info, smsal_error_cause_enum *error_cause);

extern kal_bool smsal_ims_mt_msg_hdlr(smsal_pdu_decode_struct *pdu_decode, peer_buff_struct *peer_buff_ptr, l4csmsal_ims_sms_deliver_req_struct *local_ptr);

extern kal_bool smsal_ims_store_new_msg(kal_uint8 id, kal_uint8 *pdu_ptr, kal_uint16 pdu_len, l4csmsal_ims_sms_deliver_req_struct *local_ptr);

extern void smsal_ims_send_deliver_cnf(kal_uint8 src_id, kal_uint8 result, smsal_error_cause_enum  failure_cause);

extern void smsal_ims_send_status_report_cnf(kal_uint8 src_id, kal_uint8 result, smsal_error_cause_enum  failure_cause);

extern void smsal_ims_deliver_nack_post(kal_uint8 src_id, smsal_error_cause_enum failure_cause, kal_uint8 para_ind, kal_uint8 pid, kal_uint8 dcs, kal_uint8 data_len, kal_uint8 *data);

extern void smsal_ims_deliver_ack_post(kal_uint8 src_id, kal_uint8 para_ind, kal_uint8 pid, kal_uint8 dcs, kal_uint8 data_len, kal_uint8 *data);

extern void smsal_ims_new_msg_ind(smsal_pdu_decode_struct *pdu_decode, kal_uint8 src_id, peer_buff_struct *peer_buff_ptr);

extern void smsal_ims_store_new_msg_cnf(kal_uint8 old_id);

extern void smsal_ims_store_new_msg_rej(kal_uint8 old_id);

extern void smsal_ims_send_smma_post_hdlr(kal_uint8 smma);

extern peer_buff_struct *smsal_send_ims_msg_text_mode(l4csmsal_ims_send_req_struct *send_req, kal_uint8 msg_ref, sms_addr_struct *sc_addr, peer_buff_struct *peer_buff_ptr);

extern peer_buff_struct* smsal_send_ims_cmd_text_mode(l4csmsal_ims_send_req_struct *send_req, kal_uint8 msg_ref, smsal_sat_addr_struct *sat_addr, peer_buff_struct *peer_ptr);

extern smsal_pdu_decode_struct *smsal_ims_decode_mt_msg(smsal_deliver_peer_struct *deliver_ptr, l4csmsal_ims_sms_deliver_req_struct *local_ptr, kal_uint8 *pdu_ptr, kal_uint16 pdu_len);
#endif /* end of smsal_transport_proc.h */


