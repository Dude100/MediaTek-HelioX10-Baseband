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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * smsal_cb.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains functions handling for cb inside SMSAL.
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

#ifndef _SMSAL_CB_H
#define _SMSAL_CB_H

#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h"
#include "smsal_l4c_enum.h"
#include "smsal_structs.h"
#include "kal_general_types.h"
#include "ps_public_enum.h"

#ifdef __CB__

void smsal_cb_init_context(void);

/* This function prototype is the sublayer entry function. */
void smsal_cb_entry_func(ilm_struct *ilm_ptr);

void smsal_cb_send_cbch_req(kal_uint8 cbch_req);

void smsal_cbch_req_handler(kal_uint8 src, kal_uint8 cbch_req);

#ifdef __HOMEZONE_SUPPORT__
void smsal_cb_hz_act_handler(local_para_struct *local_para_ptr);
#endif  // __HOMEZONE_SUPPORT__

void smsal_cb_update_req_handler(local_para_struct *local_para_ptr);

#if defined(__GSM_RAT__) || defined(__UMTS_RAT__)

void smsal_send_msg_to_ratcm(msg_type msg_id,
                             local_para_struct *local_para_ptr,
                             peer_buff_struct *peer_buff_ptr);


kal_bool smsal_cb_find_oldest_ctrl_blk(kal_uint8 *id);

void smsal_cb_timeout(void *p);

void smsal_cb_flush_oldest();

#ifdef __SAT__
#ifdef __REL6__
void smsal_ratcm_cb_data_download(kal_uint8 rat, kal_uint8 current_page, kal_uint8 total_page);

void smsal_ratcm_cb_data_download_clean(void);
#endif  //__SAT__
#endif  //__REL6__

void smsal_ratcm_cb_gs_change_ind_handler(local_para_struct *local_para_ptr);


void smsal_ratcm_cb_fill_page_header(local_para_struct *local_para_ptr, 
                                            kal_uint8 cur_page, 
                                            kal_uint8 total_page, 
                                            kal_uint8 *msg_data);

void smsal_ratcm_cb_data_ind_handler(local_para_struct *local_para_ptr,
                                     peer_buff_struct *peer_buff_ptr);


void smsal_cb_send_ratcm_cbch_req(kal_uint8 cbch_req);

void smsal_cb_update_ratcm_rmc_cb(void);

#endif /* __GSM_RAT__ || __UMTS_RAT__ */

#if defined(__LTE_RAT__)

void smsal_send_msg_to_eval(msg_type msg_id,
                             local_para_struct *local_para_ptr,
                             peer_buff_struct *peer_buff_ptr);

void smsal_eval_cb_gs_change_ind_handler(local_para_struct *local_para_ptr);


void smsal_eval_cb_fill_page_header(local_para_struct *local_para_ptr, 
                                        kal_uint8 cur_page, 
                                        kal_uint8 total_page, 
                                        kal_uint8 *msg_data);

void smsal_eval_cb_data_ind_handler(local_para_struct *local_para_ptr,
                                     peer_buff_struct  *peer_buff_ptr);


void smsal_cb_send_eval_cbch_req(kal_uint8 cbch_req);

void smsal_cb_update_eval_rmc_cb(void);

void smsal_cb_send_eval_msg_removal_req(kal_uint16 mid, kal_uint16 sn);

#endif /* __LTE_RAT__*/


void smsal_decode_cb_page(kal_uint8 *page_buf,
                          kal_uint8 *page_data,
                          kal_uint8 *page_length,
                          kal_uint8 start_pos,
                          kal_uint8 msg_info_length);

void smsal_decode_cbsdcs(kal_uint8            dcs,
                         kal_uint8            *lang_type,
                         smsal_dcs_enum       *alphabet_type,
                         smsal_msg_class_enum *msg_class,
                         kal_bool             *is_compress,
                         kal_bool             *is_reserved);


void smsal_cb_write_cnf(kal_uint8 id, kal_uint8 sub_act_code);


void smsal_cb_write_rej(kal_uint8 id,
                        kal_uint8 sub_act_code,
                        kal_uint16 cause);


kal_uint8 smsal_access_cb_default_ch_cnf(kal_uint8 id,
                                         smsal_read_file_aux_info_struct *aux_info,
                                         peer_buff_struct *peer_buff_ptr,
                                         local_para_struct *local_para_ptr);

kal_uint8 smsal_access_cb_ch_info_cnf(kal_uint8 id,
                                      smsal_read_file_aux_info_struct *aux_info,
                                      peer_buff_struct *peer_buff_ptr,
                                      local_para_struct *local_para_ptr);

kal_uint8 smsal_access_sim_li_or_elp_cnf(kal_uint8 id,
                                         smsal_read_file_aux_info_struct *aux_info,
                                         peer_buff_struct *peer_buff_ptr,
                                         local_para_struct *local_para_ptr);

kal_uint8 smsal_access_sim_lp_cnf(kal_uint8 id,
                                  smsal_read_file_aux_info_struct *aux_info,
                                  peer_buff_struct *peer_buff_ptr,
                                  local_para_struct *local_para_ptr);

#ifndef __CB_CHANNEL_ONLY_STORED_IN_NVRAM__
kal_uint8 smsal_access_sim_cbmi_cnf(kal_uint8 id,
                                    smsal_read_file_aux_info_struct *aux_info,
                                    peer_buff_struct *peer_buff_ptr,
                                    local_para_struct *local_para_ptr);

kal_uint8 smsal_access_sim_cbmi_rej(kal_uint8 id,
                                    smsal_read_file_aux_info_struct *aux_info,
                                    peer_buff_struct *peer_buff_ptr,
                                    local_para_struct *local_para_ptr);

kal_uint8 smsal_access_sim_cbmir_cnf(kal_uint8 id,
                                     smsal_read_file_aux_info_struct *aux_info,
                                     peer_buff_struct *peer_buff_ptr,
                                     local_para_struct *local_para_ptr);

kal_uint8 smsal_access_sim_cbmir_rej(kal_uint8 id,
                                    smsal_read_file_aux_info_struct *aux_info,
                                    peer_buff_struct *peer_buff_ptr,
                                    local_para_struct *local_para_ptr);

#endif

kal_uint8 smsal_access_sim_cbmid_cnf(kal_uint8 id,
                                     smsal_read_file_aux_info_struct *aux_info,
                                     peer_buff_struct *peer_buff_ptr,
                                     local_para_struct *local_para_ptr);

void smsal_cb_update_rmc_cb(void);


#if defined(__3G_CB_SERVICE_BY_PLMN__)
void smsal_cb_service_by_plmn_handler(local_para_struct *local_para_ptr);
#endif

void smsal_cb_ctrl_blk_reset(kal_uint8 i);   /* for cb queueing */

void smsal_cb_init_aux_info(smsal_set_cb_aux_info_struct *aux_info);

void smsal_encode_cb_ch_info(smsal_set_cb_aux_info_struct *aux_info, kal_uint8 *pdu_ptr);

void smsal_cb_update_cntx(smsal_set_cb_aux_info_struct *aux_info);

#if defined (__SMSAL_UT__)
void smsal_cb_ut_debug(kal_uint8  blk_id, 
                       l4csmsal_cb_msg_text_ind_struct *lmi_msg_ind,
                       kal_uint16 total_length);
void smsal_cb_ut_rmi_pud_debug(l4csmsal_cb_msg_pdu_ind_struct *cbm_ptr,
                                            kal_uint16 total_length);
void smsal_cb_ut_rmi_text_debug(l4csmsal_cb_msg_text_ind_struct *cbm_ptr,
                                                            kal_uint16 total_length);
void smsal_cb_ut_hz_debug(l4csmsal_hz_cb_msg_ind_struct   *hz_msg_ind,
                                                            kal_uint16 total_length);
#endif // __SMSAL_UT__


void smsal_cb_msg_removal_req_handler(local_para_struct *local_para_ptr);
void smsal_cb_send_ratcm_msg_removal_req(kal_uint16 mid, kal_uint16 sn);


#endif // __CB__

#endif /* End of file smsal_cb.h */


