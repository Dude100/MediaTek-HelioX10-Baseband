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
 *	rac_trc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for trace messages.
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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

#ifndef _RAC_TRC_H
#define _RAC_TRC_H

#include "stack_config.h"
#include "kal_trace.h"
#include "dhl_trace.h"

/* use during development temporarily */
#define RAC_DBG_LOG(_trace_class_, _fmt_, ...) \
    do {\
        dhl_print(_trace_class_, 0, MOD_RAC, _fmt_, ##__VA_ARGS__);\
    } while(0);\

#define RAC_FN_ENTRY_LOG(A)     kal_trace(TRACE_FUNC,A)
#define RAC_FN_EXIT_LOG(A)      NULL

#define RAC_INFO_LOG(A, ...)    kal_trace(TRACE_INFO, A, ##__VA_ARGS__)
#define RAC_ERROR_LOG(S,A)      kal_trace(TRACE_ERROR,S,A)

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
#include "rac_trc_gen.h"
#endif /* TST Trace Defintion */
#endif

/*****************************************************************************
 *  RAC trace format
 *      <1> trace index
 *          RAC_TRC_xxx_yyy_zzz - function trace
 *          RAC_TRC_XXX_YYY_ZZZ - other traces except for function trace
 *
 *      <2> trace content
 *          the prefix of log   - "[RAC] ......."
 *
 *  template:
 *      TRC_MSG(RAC_TRC_xyz, "[RAC] ...()")
 *      TRC_MSG(RAC_TRC_XYZ, "[RAC] ...")
 *
 *  NOTE: please apply the rule for traces after 2013/05/05
 *
 *****************************************************************************
 */
 
BEGIN_TRACE_MAP(MOD_RAC)

/* RAC_FN - send message */
TRC_MSG(RAC_FN_rac_handle_class_change,"[RAC] RAC_FN_rac_handle_class_change")
TRC_MSG(RAC_FN_rac_ug_ims_config_req,"[RAC] rac_ug_ims_config_req")
#ifdef __MODEM_EM_MODE__
TRC_MSG(RAC_TRC_rac_em_update_req_msg_handler, "[RAC] rac_em_update_req_msg_handler()")
TRC_MSG(RAC_TRC_rac_send_em_msg, "[RAC] rac_send_em_msg()")
#endif /* __MODEM_EM_MODE__ */

#ifdef __LTE_RAT__
TRC_MSG(RAC_TRC_rac_e_reset, "[RAC] rac_e_reset()")
TRC_MSG(RAC_TRC_rac_e_send_set_rat_mode_req, "[RAC] rac_e_send_set_rat_mode_req()")
TRC_MSG(RAC_TRC_rac_e_send_attach_req, "[RAC] rac_e_send_attach_req()")
TRC_MSG(RAC_TRC_rac_e_send_detach_req, "[RAC] rac_e_send_detach_req()")
TRC_MSG(RAC_TRC_rac_e_send_rfoff_req, "[RAC] rac_e_send_rfoff_req()")
TRC_MSG(RAC_TRC_rac_e_update_emm_state, "[RAC] rac_e_update_emm_state()")
TRC_MSG(RAC_TRC_rac_e_get_service_domain, "[RAC] rac_e_get_service_domain()")
TRC_MSG(RAC_TRC_rac_e_is_cell_info_equal, "[RAC] rac_e_is_cell_info_equal()")
TRC_MSG(RAC_TRC_rac_e_update_ue_mode, "[RAC] rac_e_update_ue_mode()")
TRC_MSG(RAC_TRC_rac_e_sync_ps_state, "[RAC] rac_e_sync_ps_state()")
TRC_MSG(RAC_TRC_rac_e_sync_ps_cause, "[RAC] rac_e_sync_ps_cause()")
TRC_MSG(RAC_TRC_rac_get_cs_state_in_lte, "[RAC] rac_get_cs_state_in_lte()")
TRC_MSG(RAC_TRC_rac_get_eps_state, "[RAC] rac_get_eps_state()")
TRC_MSG(RAC_TRC_rac_get_eps_status, "[RAC] rac_get_eps_status()")
TRC_MSG(RAC_TRC_is_rac_emm_state_null_dereg, "[RAC] is_rac_emm_state_null_dereg()")
TRC_MSG(RAC_TRC_is_rac_emm_state_reg, "[RAC] is_rac_emm_state_reg()")
TRC_MSG(RAC_TRC_is_rac_emm_state_att_req, "[RAC] is_rac_emm_state_att_req()")
TRC_MSG(RAC_TRC_is_cs_domain_accessible, "[RAC] is_cs_domain_accessible()")
TRC_MSG(RAC_TRC_convert_vdp_from_l4_to_nas, "[RAC] convert_vdp_from_l4_to_nas()")

TRC_MSG(RAC_TRC_rac_e_set_ims_voice_domain_preference_req, "[RAC] rac_e_set_ims_voice_domain_preference_req()")
TRC_MSG(RAC_TRC_rac_e_ims_reg_status_update_req, "[RAC] rac_e_ims_reg_status_update_req()")
TRC_MSG(RAC_TRC_rac_e_set_ims_voice_availability_req, "[RAC] rac_e_set_ims_voice_availability_req()")
TRC_MSG(RAC_TRC_rac_e_ims_config_req, "[RAC] rac_e_ims_config_req()")

#ifdef __VOLTE_SUPPORT__
TRC_MSG(RAC_TRC_rac_e_emc_attach_ind_msg_handler, "[RAC] rac_e_emc_attach_ind_msg_handler()")
TRC_MSG(RAC_TRC_rac_e_emc_attach_cnf_msg_handler, "[RAC] rac_e_emc_attach_cnf_msg_handler()")
TRC_MSG(RAC_TRC_rac_e_emc_detach_ind_msg_handler, "[RAC] rac_e_emc_detach_ind_msg_handler()")
#endif /* __VOLTE_SUPPORT__ */

TRC_MSG(RAC_TRC_rac_e_nw_feature_ind_msg_handler, "[RAC] rac_e_nw_feature_ind_msg_handler()")

#ifdef __MODEM_EM_MODE__
TRC_MSG(RAC_TRC_rac_e_get_em_info, "[RAC] rac_e_get_em_info()")
#endif /* __MODEM_EM_MODE__ */

TRC_MSG(RAC_TRC_rac_e_set_ue_mode_req_msg_handler, "[RAC] rac_e_set_ue_mode_req_msg_handler()")
TRC_MSG(RAC_TRC_rac_e_sim_ready_ind_msg_handler, "[RAC] rac_e_sim_ready_ind_msg_handler()")
TRC_MSG(RAC_TRC_rac_e_sim_error_ind_msg_handler, "[RAC] rac_e_sim_error_ind_msg_handler()")

#ifdef __SAT__
#ifndef __SAT_LOWCOST_NW_DISABLE__
TRC_MSG(RAC_TRC_rac_e_get_sat_location_info, "[RAC] rac_e_get_sat_location_info()")
#endif /* __SAT_LOWCOST_NW_DISABLE__ */
#endif /* __SAT__ */

#if defined(__GSM_RAT__) || defined(__UMTS_RAT__)
TRC_MSG(RAC_TRC_rac_update_last_domain, "[RAC] rac_update_last_domain()")
#endif /* __GSM_RAT__ || __UMTS_RAT__ */

TRC_MSG(RAC_TRC_rac_e_get_detach_domain_by_rat_mode, "rac_e_get_detach_domain_by_rat_mode()")
#endif /* __LTE_RAT__ */

/* RAC_INFO */
TRC_MSG(RAC_INFO_BEFORE_MAIN,"[RAC] RAC info before main: current_action: %Mrac_action_enum, mm_state: %Mrac_mm_state_enum")
TRC_MSG(RAC_INFO_BEFORE_MAIN_GMM_STATE,"[RAC] RAC info before main: gmm_state: %Mrac_gmm_state_enum")
TRC_MSG(RAC_INFO, "[RAC] current_action: %Mrac_action_enum, mm_state: %Mrac_mm_state_enum")
TRC_MSG(RAC_INFO_GMM_STATE, "[RAC] RAC info: gmm_state: %Mrac_gmm_state_enum")
TRC_MSG(RAC_MULTI_BAND,"[RAC] Multiband debug message : band : %x, %x, %x, %x, other : %d")
TRC_MSG(RAC_INFO_GET_SEL_MOD,"[RAC] RAC get NW sel mode = %d")
TRC_MSG(RAC_INFO_TST_INJECT_CMD_STRING,"[RAC] rac_atoi(&tst_inject->string[0])=%d, \n Inject command Reference=%d")
TRC_MSG(RAC_ABNORMAL_ASSERT, "[RAC] rac_abnormal_assert")
TRC_MSG(RAC_CHANGE_MS_CLASS, "[RAC] MS class change from %Mms_mobile_class_enum to %Mms_mobile_class_enum")
TRC_MSG(RAC_RECEIVE_DETACH_IND, "[RAC] TB_reg=%Mmm_user_regn_type_enum, TB_dereg=%Mmm_user_regn_type_enum, detach type=%Mmm_user_regn_type_enum, detach cause=%Mmm_cause_enum")
TRC_MSG(RAC_ACTIVATING_IGNORE, "[RAC] RAC warnning: ignore the request due to rac is activating")
TRC_MSG(RAC_GPRS_CONN_TYPE, "[RAC] GPRS Connection Type = %Ml4c_gprs_connect_type_enum")

TRC_MSG(RAC_TRC_READ_EF_RAC_PREFERENCE, "[RAC] read NVRAM_EF_RAC_PREFERENCE_LID back")
TRC_MSG(RAC_DEFAULT_RAT_MODE, "[RAC] default RAT mode = %Mrat_enum")
TRC_MSG(RAC_SET_RAT, "[RAC] Set RAT mode = %Mrat_enum")
TRC_MSG(RAC_PLMN_SEL_MODE, "[RAC] PLMN selection mode = %Mplmn_selection_mode_enum")
TRC_MSG(RAC_CURRENT_ACTIVE_RAT, "[RAC] step %d, current_active_rat: %Mrat_enum")
TRC_MSG(RAC_MULTIMODE_ACTIVE_RAT, "[RAC] RAT active: %Mrat_enum, L4: %Mrat_enum")

TRC_MSG(RAC_TRC_UG_SYNC_PS_CAUSE, "[RAC] rac_ug_sync_ps_cause()")

#ifdef __LTE_RAT__
TRC_MSG(RAC_TRC_BEFORE_MAIN_EMM_STATE,"[RAC] RAC info before main: emm_state: %Mrac_emm_state_enum")
TRC_MSG(RAC_TRC_EMM_STATE, "[RAC] RAC info: emm_state: %Mrac_emm_state_enum")
TRC_MSG(RAC_TRC_ON_A_CAUSE18_PLMN, "[RAC] on a PLMN with cause18 - CS domain not available")
TRC_MSG(RAC_TRC_READ_EF_EPSLOCI_EPSNSC_TIN, "[RAC] read NVRAM_EF_EPSLOCI_EPSNSC_TIN_LID back")
TRC_MSG(RAC_TRC_READ_EF_LTE_PREFERENCE, "[RAC] read NVRAM_EF_LTE_PREFERENCE_LID back")
TRC_MSG(RAC_TRC_EMM_DETACH_IND, "[RAC] TB_reg=%Mmm_user_regn_type_enum, TB_dereg=%Mmm_user_regn_type_enum, detach type=%Mmm_user_regn_type_enum, detach cause=%Memm_cause_enum")
TRC_MSG(RAC_TRC_UE_USAGE_SETTING, "[RAC] UE Usage Setting = %Mue_usage_setting_enum")
TRC_MSG(RAC_TRC_VOICE_DOMAIN_PREFERENCE_EUTRAN, "[RAC] Voice Domain Preference for EUTRAN = %Ml4_voice_domain_preference_enum")
TRC_MSG(RAC_TRC_SMS_OVER_IP_SGS, "[RAC] SMS over IP = %Mkal_bool, SMS over SGS = %Mkal_bool")
TRC_MSG(RAC_TRC_TIN, "[RAC] TIN = %Mtin_enum")
TRC_MSG(RAC_TRC_UE_MODE, "[RAC] UE Mode = %Mue_mode_enum")
TRC_MSG(RAC_TRC_SET_RUNTIME_UE_MODE, "[RAC] set runtime UE Mode from %Mue_mode_enum to %Mue_mode_enum")
TRC_MSG(RAC_TRC_NVRAM_UE_MODE, "[RAC] NVRAM UE Mode = %Mue_mode_enum")
TRC_MSG(RAC_TRC_NOT_SEND_UE_MODE_UPDATE_REQ, "[RAC] UE Mode parameters are the same, do not send UE_MODE_PARAM_UPDATE_REQ")
#ifdef __IMS_SUPPORT__
TRC_MSG(RAC_TRC_IMS_REG_STATUS_CHANGED, "[RAC] IMS reg. status is changed from %Mims_reg_status_enum to %Mims_reg_status_enum")
#endif /* __IMS_SUPPORT__ */
TRC_MSG(RAC_TRC_SET_UE_MODE_FAIL, "[RAC] Set UE Mode failed, invalid UE Mode = %Mue_mode_enum")
TRC_MSG(RAC_TRC_UNHANDLED_SIM_ERROR_CAUSE, "[RAC] unhandled SIM ERROR cause = %Msim_error_cause_enum")
TRC_MSG(RAC_TRC_CONSECUTIVE_SIM_ERROR, "[RAC] receive consecutive SIM_ERROR_IND with cause = %Msim_error_cause_enum")
TRC_MSG(RAC_TRC_NOT_SEND_UEMODE_UPDATE_REQ_SIM_REMOVED, "[RAC] do not send UE_MODE_PARAM_UPDATE_REQ due to SIM removed")
TRC_MSG(RAC_TRC_UE_USAGE_SETTING_UNSYNC, "[RAC] UE usage setting %Mue_usage_setting_enum is different from UE mode %Mue_mode_enum !")
TRC_MSG(RAC_TRC_REMAIN_CS_PS_DOMAIN, "[RAC] remains request_service as CS/PS domain when %Mrac_sim_status_enum for CS emergency call !")
TRC_MSG(RAC_TRC_UNHANDLED_EMM_STATE, "[RAC] unhandled EMM state %Mrac_emm_state_enum !")
TRC_MSG(RAC_TRC_LAST_ATTACH_DOMAIN, "[RAC] last attach domain %Mdomain_id_enum")
TRC_MSG(RAC_TRC_SET_LAST_ATTACH_DOMAIN, "[RAC] set last attach domain as %Mdomain_id_enum")
TRC_MSG(RAC_TRC_UPDATE_NEW_ATTACH_DOMAIN, "[RAC] update attach domain by sending ATTACH_REQ")
TRC_MSG(RAC_TRC_TO_UPDATE_LAST_ATTACH_DOMAIN, "[RAC] update last attach domain when detach = %Mkal_bool, service = %Mdomain_id_enum")
#endif /* __LTE_RAT__ */

TRC_MSG(RAC_CURRENT_ACTION,"[RAC] current action: %Mrac_action_enum")
TRC_MSG(UNEXPECTED_MESSAGE,"[RAC] Unexpected message for RAC in state: %d")
TRC_MSG(PLMN_LIST_FLAG_ERROR,"[RAC] PLMN LIST flag inconsistent: %d")
TRC_MSG(RAC_RECV_PS_DETACH_WHEN_PLMN_SEL,"[RAC] recv PS Detach when PLMN SEL(ignore):%d, %d")
TRC_MSG(RAC_L4C_GET_ATTACH_STATUS,"[RAC] gsm_state:%Mreg_state_enum,gsm_status:%Ml4c_rac_response_enum,gprs_state:%Mreg_state_enum,gprs_status:%Ml4c_rac_gprs_status_enum")
TRC_MSG(RAC_GET_STATE_STATUS_INFO,"[RAC] gsm_state:%Mreg_state_enum,gsm_status:%Ml4c_rac_response_enum,gprs_state:%Mreg_state_enum,gprs_status:%Ml4c_rac_gprs_status_enum")
TRC_MSG(RAC_NVRAM_WRITE_COUNT,"[RAC] nvram_write_counter:%d, when:%d")
TRC_MSG(RAC_PLMN_LIST_SEL_OR_BAND_X_WHEN_OTHER_ACTIONS,"[RAC] PLMN List,Sel,Band Change when rac_action:%Mrac_action_enum")
TRC_MSG(RAC_NOT_SEND_ATTACH_REQ_WHEN_RECV_PS_REG_REQ,"[RAC] Not send Attach Req to GMM gprs_state:%Mreg_state_enum,gprs_status:%Ml4c_rac_gprs_status_enum")
TRC_MSG(RAC_SAME_SEND_REG_IND,"[RAC] Same rac_send_reg_ind. Not send to L4C")
TRC_MSG(RAC_SEND_ATTACH_UNEXPECTEDLY, "[RAC] Send ATTACH, while gsm_state:%Mreg_state_enum, gprs_state:%Mreg_state_enum")

TRC_MSG(SAT_LOCATION_INFO_MM_STATUS,"[RAC][SAT] location info mm_status: %Msat_mm_status_enum")
TRC_MSG(SAT_EQUAL_LAST_LOCATION_INFO,"[RAC][SAT] equal last location info : %d")

TRC_MSG(RAC_RECEIVE_MM_SAME_LAI_IMSI_ATTACHING,"[RAC] receive attach cause MM_SAME_LAI_IMSI_ATTACHING ")
TRC_MSG(RAC_AUTO_ATTACH,"[RAC] l4crac_set_auto_attach_setting(): original = %d, new = %d")

TRC_MSG(RAC_START_TIMER, "[RAC] rac_start_timer_hdlr: %Mrac_timer_id_enum")
TRC_MSG(RAC_CANCEL_TIMER, "[RAC] rac_cancel_timer: %Mrac_timer_id_enum")
TRC_MSG(RAC_TIMEOUT, "[RAC] %Mrac_timer_id_enum expiry when current action is %Mrac_action_enum")


#ifdef __MONITOR_PAGE_DURING_TRANSFER__
TRC_MSG(RAC_GPRS_TRANSFER_PREFERENCE, "[RAC] gprs_transfer_preference = %Mgprs_transfer_preference_enum")
#endif

#ifdef __PLMN_LIST_PREF_SUPPORT__
TRC_MSG(RAC_PLMN_LIST_PREFERENCE, "[RAC] plmn_list_preference = %Mplmn_list_preference_enum")
#endif

//#ifdef __HSPA_PREFERENCE_SETTING__
TRC_MSG(RAC_HSPA_PREFERENCE, "[RAC] hspa_preference = %Mhspa_preference_enum")
//#endif

#ifdef __DYNAMIC_ROAMING_SUPPORT__
TRC_MSG(RAC_ROAMING_SUPPORT_SETTING, "[RAC] is_supporting_roaming: %Mkal_bool")
#endif

TRC_MSG(RAC_INTERNATIONAL_ROAMING_SUPPORT_SETTING, "[RAC] disable_international_roaming_support: %Mkal_bool")
TRC_MSG(RAC_NATIONAL_ROAMING_SUPPORT_SETTING, "[RAC] disable_national_roaming_support: %Mkal_bool")
TRC_MSG(RAC_DISABLE_HPPLMN_SEARCH_SETTING, "[RAC] disable_hhplmn_search_support: %Mkal_bool")
TRC_MSG(RAC_ROAMING_BROKER_SETTING, "[RAC] roaming_broker_support: %Mkal_bool")

#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
TRC_MSG(RAC_PEER_GPRS_TRANSFER_PREFERENCE, "[RAC] peer_gprs_transfer_preference = %Mkal_bool")
#endif

TRC_MSG(RAC_IRAT_PREFERENCE, "[RAC] AS prefer rat: %Mrat_enum")

TRC_MSG(RAC_SET_FOR_FLAG, "[RAC] Set next GPRS follow on request: %Mkal_bool")

#ifdef __CSG_SUPPORT__
TRC_MSG(RAC_CSG_AUTO_SEARCH_PREFERENCE, "[RAC] csg_auto_search_preferenc = %Mkal_bool")
#endif /* __CSG_SUPPORT__ */

TRC_MSG(RAC_CELL_SUPPORT_R8FD, "[RAC] cell network feature support R8 FD")

TRC_MSG(RAC_RECV_INACTIVE_DETACH_IND, "[RAC] receive invalid DETACH_IND when active RAT is %Mrat_enum")
TRC_MSG(RAC_RECV_INACTIVE_ATTACH_CNF, "[RAC] receive invalid ATTACH_CNF when active RAT is %Mrat_enum")

TRC_MSG(RAC_TRC_CS_SIM_STATUS, "[RAC] current CS SIM status = %Mrac_sim_status_enum")

/* RAC_ERROR */
TRC_MSG(RAC_TRC_UNEXPECTED_RAT_MODE, "[RAC] unexpected RAT mode: %d")
TRC_MSG(RAC_TRC_UNEXPECTED_ACTIVE_RAT_MODE, "[RAC] unexpected active RAT mode: %d")
#ifdef __LTE_RAT__
TRC_MSG(RAC_TRC_UNEXPECTED_VOICE_DOMAIN_PREFERENCE_FOR_EUTRAN, "[RAC] unexpected Voice Domain Preference for E-UTRAN: %Ml4_voice_domain_preference_enum")
#endif /* __LTE_RAT__ */

#ifdef __MODEM_EM_MODE__
TRC_MSG(RAC_TRC_UXPECTED_EM_SOURCE, "[RAC] unexpected EM source %Mem_source_enum !")
#endif /* __MODEM_EM_MODE__ */

#ifdef __VOLTE_SUPPORT__
TRC_MSG(RAC_TRC_MM_IVT, "[RAC] mobility management IVT: %Mmm_ims_voice_termination")
#endif /* __VOLTE_SUPPORT__ */

TRC_MSG(RAC_TRC_VOICE_DOMAIN_PREFERENCE_UTRAN, "[RAC] Voice Domain Preference for UTRAN = %Ml4_voice_domain_preference_enum")
TRC_MSG(RAC_TRC_UNEXPECTED_VOICE_DOMAIN_PREFERENCE_FOR_UTRAN, "[RAC] unexpected Voice Domain Preference for UTRAN: %Ml4_voice_domain_preference_enum")

#ifdef __SAT__
#ifndef __SAT_LOWCOST_NW_DISABLE__
TRC_MSG(RAC_TRC_UNEXPECTED_RAT_FOR_SAT, "[RAC] unexpected %Mrat_enum for SAT location information !!!")
#endif /* __SAT_LOWCOST_NW_DISABLE__ */
#endif /* __SAT__ */

END_TRACE_MAP(MOD_RAC)

#endif


