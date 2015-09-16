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
 *	csmcc_aux_msg_hdlr.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for auxiliary message handler declaration used in
 *   CSM(CC) module.
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

#ifndef _CSMCC_AUX_MSG_HDLR_H
#define _CSMCC_AUX_MSG_HDLR_H

#include "csmcc_types.h"
//#include "kal_non_specific_general_types.h"
#include "nvram_enums.h"
#include "mncc_struct.h"
#include "csmcc_common_enums.h"
#include "csmcc_enums.h"
#include "mcd_ss_tcapmessages.h"
#include "l4c2csm_cc_struct.h"
#include "csmcc_bc_types.h"
#include "mcd_ss_parameters.h"
#include "mcd_l4_common.h"
#include "kal_general_types.h"
#include "ps_public_enum.h"

extern csmcc_ret_t
csmcc_send_sim_read_req(kal_uint8 file_idx,
                        kal_uint8 file_len);

extern csmcc_ret_t 
csmcc_send_l4c_startup_cnf(kal_uint8 response,
                           kal_uint16 cause,
                           kal_uint8 init_type);

extern sim_interface_enum 
csm_gemini_get_actual_sim_id(sim_interface_enum simId);
extern csmcc_ret_t 
csmcc_send_nvram_read_req(nvram_lid_enum file_idx,
                          kal_uint16 para);
#ifdef __AOC_SUPPORT__
extern csmcc_ret_t 
csmcc_send_cc_acm_update_req(kal_uint32 acmmax,
                             kal_uint32 acm);

extern csmcc_ret_t 
csmcc_send_sim_write_req(kal_uint8 file_idx,
                         kal_uint8 *data_ptr,
                         kal_uint8 file_len);

extern csmcc_ret_t 
csmcc_send_sim_increase_req(kal_uint8 file_idx,
                            kal_uint8 *data_ptr,
                            kal_uint8 file_len);

extern csmcc_ret_t 
csmcc_send_l4c_acm_reset_cnf(kal_uint8 src_id,
                             kal_uint8 response,
                             kal_uint16 cause);

extern csmcc_ret_t
csmcc_send_l4c_acmmax_set_cnf(kal_uint8 src_id, 
                              kal_uint8 response,
                              kal_uint16 cause);
#endif /*__AOC_SUPPORT__*/

extern csmcc_ret_t 
csmcc_send_l4c_detach_ind(kal_bool irho);

//mtk01602, 070606: add two parameters for sending terminal response to SIM
extern csmcc_ret_t 
csmcc_send_l4c_setup_fail(kal_uint8 src_id,
                          kal_uint8 call_type, 
                          kal_uint16 cause,
                          kal_uint8  terminal_res,
                          kal_uint8  add_res,
                          kal_uint8 diagnostic);
                          
extern csmcc_ret_t
csmcc_send_l4c_emergency_setup_fail(kal_uint8 src_id,
                                    kal_uint16 cause);
                           
extern csmcc_ret_t 
csmcc_send_l4c_setup_succ(kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_send_l4c_emergency_setup_succ(kal_uint8 call_id);
                           
extern csmcc_ret_t 
csmcc_send_l4c_disc_fail(kal_uint8 src_id, 
                         kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_send_l4c_disc_succ(kal_uint8 call_id);
                           
extern csmcc_ret_t 
csmcc_send_cc_start_dtmf_req(kal_uint8 call_id,
                             kal_uint8 tone);
                           
extern csmcc_ret_t 
csmcc_send_cc_stop_dtmf_req(kal_uint8 call_id,
                            kal_uint8 tone);

extern csmcc_ret_t 
csmcc_send_cc_setup_res(kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_send_cc_ccbs_setup_req(kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_send_cc_rel_req(kal_uint8 call_id, 
                      kal_uint16 cause);

extern csmcc_ret_t 
csmcc_send_cc_ccbs_activate_req(kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_send_cc_disc_req(kal_uint8 call_id, 
                       kal_uint16 cause);

extern csmcc_ret_t 
csmcc_send_l4c_attach_ind(kal_uint8 channel_mode, kal_bool irho);

extern csmcc_ret_t 
csmcc_send_l4c_disc_ind(mncc_disc_ind_struct *disc_ind_ptr);

extern csmcc_ret_t 
csmcc_send_l4c_simple_disc_ind(kal_uint8 call_id, kal_uint16 cause,kal_uint8 diagnostic);

extern csmcc_ret_t 
csmcc_send_l4c_rel_ind(kal_uint8 call_id, 
                       kal_uint16 cause, kal_uint8 diagnostic);
                                        
extern csmcc_ret_t 
csmcc_cug_info_pack(mncc_facility_struct *fac_ptr,
                    csmcc_cug_param_struct *cug_param_ptr);
                                    
extern csmcc_ret_t 
csmcc_send_cc_setup_req(kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_send_cc_emergency_setup_req(kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_send_l4c_alert_ind(mncc_alert_ind_struct* alert_ind_ptr);

extern csmcc_ret_t 
csmcc_send_l4c_auto_dtmf_complete_ind(kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_send_cc_call_conf_req(kal_uint8 call_id);

extern csmcc_ret_t
csmcc_send_l4c_call_setup_ind(kal_uint8 call_id,
                              mncc_setup_ind_struct *setup_ind_ptr);
                                      
extern csmcc_ret_t
csmcc_send_l4c_call_present_ind(kal_uint8 call_id,
                              mncc_setup_ind_struct *setup_ind_ptr);

extern csmcc_ret_t 
csmcc_send_cc_alert_req(kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_send_l4c_call_preempt_ind(kal_uint8 call_id,
                                csmcc_preempt_type_enum preempt_type);
                                 
extern csmcc_ret_t 
csmcc_send_l4c_connect_ind(mncc_setup_cnf_struct *setup_cnf_ptr);

extern csmcc_ret_t 
csmcc_send_l4c_accept_succ(kal_uint8 call_id);
                                                         
extern csmcc_ret_t 
csmcc_send_cc_ccbs_est_res(kal_uint8 call_id,
                           kal_uint16 cause);

extern csmcc_ret_t 
csmcc_send_l4c_crss_succ(csmcc_req_enum crss_req);

extern csmcc_ret_t 
csmcc_send_l4c_crss_fail(kal_uint8 src_id,
                         csmcc_req_enum crss_req, 
                         kal_uint16 cause);
                                          
extern csmcc_ret_t 
csmcc_send_l4c_crss_error(kal_uint8 src_id,
                          csmcc_req_enum crss_req, 
                          kal_uint8 error_code);


extern csmcc_ret_t 
csmcc_send_l4c_crss_reject(kal_uint8 src_id,
                           csmcc_req_enum crss_req, 
                           Reject *reject);
                                          
extern csmcc_ret_t 
csmcc_send_l4c_accept_fail(kal_uint8 src_id,
                           kal_uint8 call_id, 
                           kal_uint16 cause);
                                            
extern csmcc_ret_t 
csmcc_send_cc_rej_req(kal_uint8 ti,
                      kal_uint16 cause);
                                       
extern csmcc_ret_t 
csmcc_send_cc_ccbs_rej_req(kal_uint8 call_id,
                           kal_uint16 cause);
                                            
extern csmcc_ret_t 
csmcc_send_cc_ccbs_setup_req(kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_send_cc_facility_req(kal_uint8 call_id, 
                           kal_uint8 opcode);

extern csmcc_ret_t 
csmcc_send_cc_hold_req(kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_send_cc_retrieve_req(kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_send_l4c_call_deflection_succ(kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_send_l4c_call_deflection_fail(kal_uint8 src_id,
                                    kal_uint8 call_id,
                                    kal_uint16 cause);

extern csmcc_ret_t 
csmcc_send_l4c_call_deflection_error(kal_uint8 src_id,
                                     kal_uint8 call_id,
                                     kal_uint8 error_code);

extern csmcc_ret_t 
csmcc_send_l4c_call_deflection_reject(kal_uint8 src_id,
                                      kal_uint8 call_id,
                                      Reject *reject);
                                                     
extern csmcc_ret_t 
csmcc_pack_deflected_addr(mncc_facility_struct *fac_ptr,
              l4ccsm_cc_call_deflection_req_struct *call_deflected_req_ptr);
                  
extern csmcc_ret_t 
csmcc_send_cc_call_deflection_req(
              l4ccsm_cc_call_deflection_req_struct *call_deflection_req_ptr);
                  
extern csmcc_ret_t 
csmcc_send_l4c_start_dtmf_succ(kal_uint8 call_id,
                               kal_uint8 tone);
                                                
extern csmcc_ret_t 
csmcc_send_l4c_start_dtmf_fail(kal_uint8 src_id,
                               kal_uint8 call_id,
                               kal_uint8 tone,
                               kal_uint16 cause);
                                                
extern csmcc_ret_t 
csmcc_send_cc_start_dtmf_req(kal_uint8 call_id,
                             kal_uint8 tone);
                                              
extern csmcc_ret_t 
csmcc_send_cc_stop_dtmf_req(kal_uint8 call_id,
                            kal_uint8 tone);
                                              
extern csmcc_ret_t 
csmcc_send_l4c_stop_dtmf_succ(kal_uint8 call_id,
                              kal_uint8 tone);

extern csmcc_ret_t
csmcc_send_l4c_stop_dtmf_fail(kal_uint8 src_id,
                              kal_uint8 call_id,
                              kal_uint8 tone,
                              kal_uint16 cause);

extern csmcc_ret_t 
csmcc_send_cc_modify_req(kal_uint8 call_id,
                         csmcc_bc_struct *bc, 
                         kal_uint8 rscd_P);                      
                                 
extern csmcc_ret_t 
csmcc_send_cc_modify_compl(kal_uint8 call_id,
                           csmcc_bc_struct *bc,
                           kal_uint8 rscd_P);
                                 
extern csmcc_ret_t 
csmcc_send_cc_modify_rej(kal_uint8 call_id,
                         csmcc_bc_struct *bc,
                         kal_uint16 cause);
                                 
extern csmcc_ret_t 
csmcc_send_l4c_modify_succ(kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_send_l4c_modify_fail(kal_uint8 src_id,
                           kal_uint8 call_id, 
                           kal_uint16 cause);
                             
extern csmcc_ret_t 
csmcc_send_l4c_modify_ind(kal_uint8 call_id);

#ifdef __AOC_SUPPORT__
extern csmcc_ret_t 
csmcc_send_l4c_ccm_ind(mncc_aoc_ind_struct *aoc_ind_ptr);
#endif
/*mtk00924 add 041210 for ECPI*/
/*mtk01602 add cause for WM FTA*/
/* MAUI_01315252, update call state */
extern csmcc_ret_t 
csmcc_send_l4c_cpi_ind(kal_uint8 call_id,
                       csmcc_cpi_msg_type_enum msg_type,
                       kal_bool is_ibt,
                       kal_bool is_tch,
                       kal_uint16 disc_cause,
                       kal_uint8 diagnostic);                                          

extern csmcc_ret_t 
csmcc_send_l4c_update_call_state_ind(kal_uint8 call_id, csmcc_call_state_enum call_state);

extern csmcc_ret_t 
csmcc_send_l4c_call_sync_ind(kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_send_l4c_notify_ss_ind(kal_uint8 call_id, 
                             NotifySS_Arg *notify_ss_arg_ptr);

#ifdef __SAT__

extern csmcc_ret_t 
csmcc_send_sim_call_ctrl_req(kal_uint8 call_id, kal_bool is_sat_action);

extern csmcc_ret_t 
csmcc_send_l4c_sat_setup_fail(kal_uint8 src_id,
                              kal_uint8 res,
                              kal_uint8 add_res,
                              kal_uint16 cause,
                              kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_send_l4c_sat_setup_succ(kal_uint8 src_id,
                              mncc_setup_cnf_struct *setup_cnf_ptr);

extern csmcc_ret_t
csmcc_send_sim_file_change_res(kal_bool res);

extern csmcc_ret_t 
csmcc_send_sim_call_status_ind(kal_bool call_status);

#endif /* __SAT__ */

#if defined(__CSD_T__) || defined(__CSD_NT__)
extern csmcc_ret_t 
csmcc_send_l4c_csd_est_ind(kal_uint8 call_id);
#endif

#ifdef __TCPIP_OVER_CSD__
extern csmcc_ret_t
csmcc_send_l4c_set_csd_prof_cnf(kal_uint8 response,
                                kal_uint8 error_code);
#endif                             

#if defined (__CPHS__) || defined (__CCM_NO_RESET__)
extern csmcc_ret_t 
csmcc_send_nvram_als_req (kal_uint8 line_id, kal_uint32  last_ccm);
#endif
#ifdef __CPHS__
extern csmcc_ret_t 
csmcc_send_l4c_display_als_ind (kal_uint8 line_id);

extern 
csmcc_ret_t csmcc_send_l4c_update_als_cnf( kal_uint8 result,
                                          kal_uint16 error_cause);
#ifdef __AOC_SUPPORT__
#if defined (__CCM_NO_RESET__) && defined (__LAST_CCM_RESET__)
/* MAUI_01938414 [CSMCC][Revise] support reset last ccm */
csmcc_ret_t csmcc_send_l4c_last_ccm_reset_cnf( kal_uint8 result,
                                          kal_uint16 error_cause);
#endif /*defined (__CCM_NO_RESET__) && defined (__LAST_CCM_RESET__)*/
#endif /*__AOC_SUPPORT__*/
#endif /*__CPHS__*/

extern csmcc_ret_t csmcc_send_l4c_call_info_ind(kal_bool call_exist);

extern csmcc_ret_t csmcc_send_l4c_auto_dtmf_start_ind(kal_uint8 call_id);

extern csmcc_ret_t csmcc_send_l4c_gen_notify_ss_ind(kal_uint8 call_id, 
                                         csmcc_notify_ss_type_enum notify_ss_type);

#ifdef __SAT__
extern csmcc_ret_t 
csmcc_send_l4c_sat_send_dtmf_cnf(kal_uint8 src_id, 
                                           kal_uint8 res, 
                                           kal_uint8 cause);

#ifndef __SAT_LOWCOST_NW_DISABLE__
extern csmcc_ret_t 
csmcc_send_sim_call_conn_req(kal_uint8 ti, kal_bool is_mt_call);
#ifdef __SUBADDR_SUPPORT__
extern csmcc_ret_t csmcc_send_sim_mt_call_req( kal_uint8 ti,
                                        kal_bool addr_p,
                                        kal_bool sub_addr_p,
                                        l4_addr_bcd_struct *addr,
                                        l4ccsm_cc_sub_addr_struct *sub_addr);
#else
extern csmcc_ret_t csmcc_send_sim_mt_call_req( kal_uint8 ti,
                                        kal_bool addr_p,
                                        l4_addr_bcd_struct *addr);
#endif
extern csmcc_ret_t 
csmcc_send_sim_call_disc_req(kal_uint8 ti,
                                             kal_bool is_far_end,
                                             //kal_bool cause_p,
                                             //kal_uint8 cause);
                                             kal_uint8 cause_len,
                                             kal_uint8 *cause_p);
#endif /* __SAT_LOWCOST_NW_DISABLE__ */
#endif /*__SAT__*/

#ifdef __VIDEO_CALL_SUPPORT__
extern csmcc_ret_t 
csmcc_send_l4c_video_call_status_ind (kal_uint8 call_id, 
			  	      kal_uint8 action, 
				      kal_bool result, 
				      kal_uint8 cause);
#endif /* __VIDEO_CALL_SUPPORT__ */

extern csmcc_ret_t csmcc_send_cc_abort_call_req(void); 
extern csmcc_ret_t csmcc_send_l4c_update_call_state_idle_ind(kal_uint8 call_id);

#ifdef __IMS_SUPPORT__
extern csmcc_ret_t csmcc_send_cc_srvcc_transfer_req(l4ccsm_cc_srvcc_transfer_req_struct *cc_srvcc_transfer_req_ptr);
extern csmcc_ret_t csmcc_send_l4c_srvcc_transfer_cnf(mncc_srvcc_transfer_cnf_struct *mncc_srvcc_transer_cnf_ptr);
#endif

#endif /* _CSMCC_AUX_MSG_HDLR_H */


