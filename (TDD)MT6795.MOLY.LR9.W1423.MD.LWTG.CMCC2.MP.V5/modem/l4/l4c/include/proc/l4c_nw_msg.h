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
 * l4c_nw_msg.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for �K.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
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

#ifndef _L4C_NW_MSG_H
#define _L4C_NW_MSG_H

//#include "stack_ltlcom.h"
//#include "kal_non_specific_general_types.h"
//#include "l4c_common_enum.h"
#include "kal_general_types.h"
//#include "l4c_msghdlr.h"      
#include "ps_public_enum.h"   
//#include "ps_public_struct.h" 
#include "kal_public_defs.h"   

extern void l4crac_act_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_reg_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_ps_reg_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_dereg_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_plmn_list_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_class_change_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

//extern void l4crac_set_preferred_band_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_reg_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_reg_state_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_reg_cause_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr); // __NW_REG_CAUSE_REPORT__ mtk02285 20090310

//extern void l4crac_rx_level_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr); //rx_level, mtk02285, remove old interface

extern void l4crac_nw_info_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_cipher_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_nw_ecc_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_rfoff_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_plmn_search_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_set_rat_mode_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_plmn_list_stop_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_set_prefer_rat_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_end_ps_data_session_cnf_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);

extern void l4crac_end_ps_data_session_ind_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);

extern void l4crac_search_normal_finish_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4crac_mmrr_service_status_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_ps_event_report_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4c_ps_abm_nw_attach_ind(kal_uint8  status,kal_uint8* plmn,kal_uint8  gsm_state,
		kal_uint8  gprs_state,l4c_gprs_status_enum  gprs_status,kal_uint8  rat,kal_uint8  cell_support_egprs,kal_uint8*  lac);

extern void l4crac_set_roaming_mode_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_csg_list_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4crac_csg_list_stop_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

#if defined(__REPORT_AVAILABLE_PLMN__)
extern void l4crac_plmn_list_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif

#if defined(__2STAGE_NW_SELECTION__)
extern void l4crac_suspend_status_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4crac_susp_resu_update_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif

extern void l4crac_set_voice_domain_preference_cnf_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);
extern void l4crac_set_ue_usage_cnf_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);
extern void l4crac_set_ims_voice_availability_cnf_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);
extern void l4crac_set_ims_sms_availability_cnf_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);
extern void l4crac_set_ue_mode_cnf_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);

extern void l4c_rrce_pch_txrx_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

#if defined(__LTE_RAT__)
extern void l4c_eval_rat_change_ind_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);
extern void l4c_eval_rat_change_cnf_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);
extern void l4c_eval_cell_power_level_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4csm_rat_change_ind_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);
extern void l4csm_rat_change_cnf_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);
#endif /* __LTE_RAT__ */

extern void l4c_rsva_suspend_service_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4c_rsva_resume_service_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4c_rsva_abort_service_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4c_rsva_abort_service_complete_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4cps_rf_info_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4c_rrce_rrc_state_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4crac_set_sms_preference_cnf_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);

extern void l4crac_update_sms_preference_ind_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);

extern void l4crac_ims_reg_status_update_cnf_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);

extern void l4crac_nw_feature_ind_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);

extern void l4crac_uemode_param_update_ind_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);

extern void l4crac_plmn_status_ind_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);

extern void l4crac_ims_service_ind_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);

extern void l4c_eval_srvcc_status_update_ind_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);

extern void l4crac_set_recovery_search_timer_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4crac_get_recovery_search_timer_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#ifdef __SGLTE__
extern void l4c_sm_ps_switch_context_transfer_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4c_eval_ps_switch_context_transfer_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4c_ps_switch_context_transfer_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4crac_ps_switch_suspend_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4crac_ps_switch_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4cas_to_peer_info_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4crac_mmdc_camp_on_status_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4c_eval_ps_switch_context_transfer_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4c_sm_ps_switch_context_transfer_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4cpsdm_ps_indication_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4cpsdm_ps_switch_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4cpsdm_ps_switch_transfer_complete_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4cpsdm_ps_switch_gas_notification_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4c_eval_capability_change_ind_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);
extern void l4cpsdm_mmdc_recovery_search_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4cpsdm_ps_switch_suspend_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4cpsdm_ps_switch_resume_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4c_ps_switch_context_transfer_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4cpsdm_ps_attach_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4crac_plmn_search_abort_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4cpsdm_plmn_search_abort_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4crac_mmdc_plmn_loss_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif

#ifdef __VOLTE_SUPPORT__
extern void l4c_eval_get_ssac_param_cnf_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);
#endif

extern void l4crac_set_ims_voice_termination_cnf_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);

extern void l4crac_restart_clear_code_33_proc_ind_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);

#ifdef __MODEM_EM_MODE__
void l4_send_em_rat_changed_ind(kal_uint8 irat_type, kal_uint8 source_rat, kal_uint8 target_rat);
#endif
#endif /* _L4C_NW_MSG_H */ /* l4c_nw_msg.h */

