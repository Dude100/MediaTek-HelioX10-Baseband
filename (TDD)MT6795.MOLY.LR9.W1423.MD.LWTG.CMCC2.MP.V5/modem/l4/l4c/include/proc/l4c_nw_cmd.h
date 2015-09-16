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
 * l4c_nw_cmd.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for ...
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

#ifndef _L4C_NW_CMD_H
#define _L4C_NW_CMD_H

//#include "kal_non_specific_general_types.h"
#include "l4c_common_enum.h"
#include "kal_general_types.h"
#include "ps_public_enum.h"
#ifdef __SGLTE__
#include "l3_inc_enums.h"
#endif

typedef enum
{
    RAC_STATUS_DETACHED,
    RAC_STATUS_ATTACHED
} l4crac_attach_status_enum;

typedef enum
{
    AUTO_SELECT,
    MANUAL_SEL,
    DEREG,
    MANUAL_THEN_AUTO = 4
} l4crac_cops_opcode_enum;

/* diamond, 2005/07/05 Flight mode */
typedef enum
{
    FLIGHTMODE_OFF = 0,
    FLIGHTMODE_SILENT,
    FLIGHTMODE_QUERY
} l4cmmi_flightmode_enum;

extern kal_bool l4c_nw_get_imei_req(kal_uint8 src_id, kal_uint8 *imei, kal_uint8 *svn);

extern kal_bool l4c_nw_powroff_detach_req(kal_uint8 src_id);

extern kal_bool l4c_nw_end_ps_data_session_req(kal_uint8 src_id, kal_uint8 force_send_SCRI, kal_uint8 trigger_cause);

extern kal_bool l4c_nw_exe_att_req(kal_uint8 src_id, kal_uint8 type, kal_uint8 opcode, kal_bool is_poweroff);

extern kal_bool l4c_nw_abort_att_req(kal_uint8 src_id, kal_uint8 connect_type, kal_bool ps_detach);

extern kal_bool l4c_nw_get_attach_status_req(kal_uint8 src_id, kal_uint8 type, kal_uint8 *status);
extern kal_bool l4c_nw_set_gprs_connect_type_req(kal_uint8 src_id, l4c_gprs_connect_type_enum type);

extern kal_bool l4c_nw_get_gprs_connect_type_req( /* l4c_gprs_connect_type_enum */ kal_uint8 *type);
extern kal_bool l4c_nw_set_and_trigger_auto_attach_req(kal_uint8 src_id);
extern kal_bool  l4c_nw_set_hspa_mode_req(kal_uint8 src_id, kal_uint8 hspa_mode, kal_uint8 apply_mode); //mtk02285, hspa_mmi
extern kal_bool  l4c_nw_get_hspa_mode_req(kal_uint8 src_id, kal_uint8 * hspa_mode); //mtk02285, hspa_mmi
extern l4c_hspa_preference_enum l4c_nw_get_max_hspa_support_mode(void);

extern kal_bool l4c_nw_exe_gprs_connection_type(void);

extern kal_bool l4c_nw_set_class_req(kal_uint8 src_id, kal_uint8 type);

extern kal_bool l4c_nw_get_class_req(kal_uint8 src_id, kal_uint8 *type);

extern kal_bool l4c_nw_set_sel_mode_req(kal_uint8 src_id, kal_uint8 mode);

extern kal_bool l4c_nw_get_sel_mode_req(kal_uint8 src_id, kal_uint8 *mode);

extern kal_bool l4c_nw_set_gprs_transfer_preference_req(kal_uint8 src_id, kal_uint8 prefer);

extern kal_bool l4c_nw_get_gprs_transfer_preference_req(kal_uint8 src_id, kal_uint8 * prefer);

extern kal_bool l4c_nw_exe_cops_req(kal_uint8 src_id, kal_uint8 opcode, kal_uint8 *oper, kal_uint8 rat, kal_uint32 factory_mode_arfcn, kal_uint8 preference); 

extern kal_bool l4c_nw_get_plmn_list_req(kal_uint8 src_id);

extern kal_bool l4c_nw_abort_plmn_list_req(kal_uint8 src_id);

extern kal_bool l4c_nw_get_current_oper_req(kal_uint8 src_id, kal_uint8 *oper);

extern kal_bool l4c_nw_get_signal_level_req(kal_uint8 src_id, kal_uint8 *rssi, kal_uint8 *ver);

extern kal_bool l4c_nw_get_extended_signal_level_req(kal_uint8 src_id, l4c_rat_enum rat, kal_uint8 *sig1, kal_uint8 *sig2);

extern kal_bool l4a_nw_set_preferred_band_req (kal_uint8 src_id,
                              kal_uint8 gsm_band, kal_uint8 *umts_fdd_band);

extern kal_bool l4c_nw_set_preferred_band_req (kal_uint8 src_id,
                                       kal_uint8 gsm_band, 
                                       kal_uint32 umts_band,
                                       kal_uint32 *lte_band);

extern kal_bool l4c_nw_get_band_req(kal_uint8 src_id,
                             kal_uint8 *gsm_band,
                             kal_uint32 *umts_band,
                             kal_uint32 *lte_band,
                             kal_uint8 *supported_gsm_band,
                             kal_uint32 *supported_umts_fdd_band,
                             kal_uint32 *supported_lte_band);

extern void l4c_nw_sim_mode_switch_start_req(kal_uint8 src_id);

extern void l4c_nw_sim_mode_switch_stop_req(kal_uint8 src_id);

extern kal_bool l4c_nw_cfun_state_req(kal_uint8 src_id, kal_uint8 cfun_state);

extern kal_bool l4c_nw_efun_state_req(kal_uint8 src_id, kal_uint8 efun_state);

extern l4c_rat_enum l4c_nw_check_ef_rat_mode(void);

extern kal_bool l4c_nw_get_rat_mode_req(kal_uint8 src_id, kal_uint8 *rat_mode);

extern kal_bool l4c_nw_get_rat_mode_ext_req(kal_uint8 src_id, kal_uint8 *rat_mode, kal_uint8 *prefer_rat);

extern kal_bool l4c_nw_set_rat_mode_req(kal_uint8 src_id, kal_uint8 rat_mode);

extern kal_bool l4c_nw_set_rat_mode_ext_req(kal_uint8 src_id, kal_uint8 rat_mode, l4c_prefer_rat_enum prefer_rat);

extern kal_bool l4c_nw_get_prefer_rat_req(kal_uint8 *prefer_rat);
extern kal_bool l4c_nw_set_prefer_rat_req(kal_uint8 src_id, kal_uint8 prefer_rat);

extern kal_bool l4c_nw_exe_rf_off_req(kal_uint8 src_id, l4c_action_enum action);

extern kal_bool l4c_nw_exe_rf_on_req(kal_uint8 src_id);

extern kal_bool l4c_nw_set_plmn_list_preference_req(kal_uint8 src_id, kal_uint8 preference);
extern kal_bool l4c_nw_get_plmn_list_preference_req(kal_uint8 src_id, kal_uint8 *preference);

extern kal_bool l4c_nw_get_romaing_status_req(kal_uint8 src_id, kal_bool* is_on_hplmn);

extern void l4c_nw_set_monitor_peer_pch_req(kal_bool on_off);

extern kal_bool l4c_nw_get_monitor_peer_pch_req(kal_bool *on_off);

extern kal_bool l4c_nw_get_csg_list_req(kal_uint8 src_id, kal_uint8 *oper, kal_uint8 rat);
extern kal_bool l4c_nw_abort_csg_list_req(kal_uint8 src_id);
extern kal_bool l4c_nw_csg_attach_req(kal_uint8 src_id, kal_uint8 *oper, kal_uint32 csg_id, kal_uint8 rat);
extern kal_bool l4c_nw_set_csg_auto_search_req(kal_uint8 src_id, kal_bool is_enable);
extern kal_bool l4c_nw_get_csg_auto_search_req(kal_uint8 src_id, kal_bool *is_enable);

extern kal_bool l4c_nw_get_romaing_mode_req(kal_uint8 src_id, kal_bool* support_roaming);
extern kal_bool l4c_nw_set_sysconfig_req(kal_uint8 src_id, 
                                         kal_uint8 rat_mode, 
                                         kal_uint8 prefer_rat, 
                                         kal_bool support_roaming, 
                                         kal_uint8 mobile_class);

#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
extern kal_bool l4c_nw_set_fd_mode_req(kal_uint8 src_id, kal_uint8 mode);
extern kal_uint8 l4c_nw_get_fd_mode_req(void);
extern kal_bool l4c_fd_set_screen_status(kal_bool is_screen_on);
extern kal_bool l4c_nw_is_fd_command_allowed(void);
#endif

extern kal_bool l4c_nw_get_voice_domain_preference_req(kal_uint8 src_id, l4c_rat_enum rat, kal_uint8 *preference);
extern kal_bool l4c_nw_set_voice_domain_preference_req(kal_uint8 src_id, kal_bool is_utran_vdp_valid, kal_uint8 utran_vdp, kal_bool is_eutran_vdp_valid, kal_uint8 eutran_vdp);
extern kal_bool l4c_nw_get_ue_usage_setting_req(kal_uint8 src_id, kal_uint8 *setting);
extern kal_bool l4c_nw_set_ue_usage_setting_req(kal_uint8 src_id, kal_uint8 setting);
extern kal_bool l4c_nw_get_ims_voice_availability_req(kal_uint8 src_id, kal_uint8 *state);
extern kal_bool l4c_nw_set_ims_voice_availability_req(kal_uint8 src_id, kal_uint8 state);
extern kal_bool l4c_nw_get_ims_sms_availability_req(kal_uint8 src_id, kal_uint8 *state);
extern kal_bool l4c_nw_set_ims_sms_availability_req(kal_uint8 src_id, kal_uint8 state);
extern kal_bool l4c_nw_get_ue_mode_req(kal_uint8 src_id, kal_uint8 *runtime_mode, kal_uint8 *nvram_mode);
extern kal_bool l4c_nw_set_ue_mode_req(kal_uint8 src_id, kal_uint8 mode);

#if defined(__2STAGE_NW_SELECTION__)
extern kal_bool l4c_nw_susp_resum_update_req(l4c_source_id_enum src_id, kal_uint8 data, kal_uint8 action);
#endif

extern kal_bool l4c_rf_info_req(kal_uint8 mode); //gps_desense

extern kal_bool l4c_nw_get_sms_preference_req(kal_uint8 src_id, kal_uint8 *preference);

extern kal_bool l4c_nw_set_sms_preference_req(kal_uint8 src_id, kal_uint8 preference);

extern kal_bool l4c_nw_ims_reg_status_update_req(kal_uint8 src_id, kal_uint8 reg_state, kal_uint8 reg_type, kal_uint32 ext_info, kal_uint8 dereg_cause);

extern kal_bool l4c_nw_ims_config_req(kal_uint8 src_id, kal_bool ims_support);

extern kal_bool l4c_nw_ims_nwsel_req(kal_uint8 src_id, kal_uint8 opcode, kal_uint8 *oper, kal_uint8 rat);

extern kal_bool l4c_nw_ims_abort_nwsel_req(kal_uint8 src_id);

extern kal_bool l4c_nw_ims_reg_start_req(kal_uint8 src_id, kal_uint8 type);

#ifdef __SGLTE__
extern kal_uint8 l4c_nw_get_mmdc_mode_req();
extern kal_bool l4c_nw_set_mmdc_mode_req(kal_uint8 src_id, kal_uint8 mode);
extern kal_bool l4c_nw_background_search_req();
extern kal_bool psdm_is_ps_switch_ongoing();
extern void l4c_send_msg_to_psdm(msg_type msg_name, void * param_ptr);
extern kal_bool l4c_psdm_set_mpc_req(kal_uint8 type, void* param);
extern kal_bool l4c_psdm_ps_switch_ind_req(kal_uint8 src_id, kal_uint8 ap_decision, kal_uint8 target_rat);
extern void l4c_psdm_rf_status_update_req(kal_uint8 efun_state);
extern void l4c_psdm_power_level_update_ind(rat_enum rat, kal_int32 rssi, kal_int32 RSCP, kal_int32 EcN0, kal_int32 RSRP, kal_int32 RSRQ, kal_uint32 arfcn);
extern void l4c_psdm_reg_state_update_ind(kal_uint8 gprs_state, kal_uint8 gprs_status, kal_uint8 rat);
extern void l4c_psdm_attach_result_ind(kal_bool attach_result);
extern void l4c_psdm_active_rat_change_ind(kal_uint8 new_rat);
extern void l4c_psdm_sim_status_update_ind(kal_bool is_sim_inserted, sim_error_cause_enum cause);
extern void l4c_psdm_cops_action_update_ind(kal_bool is_cops_action);
extern void l4c_psdm_set_rat_action_update_ind(kal_bool is_set_rat_action);
#endif

#ifdef __SGLTE_DSDS__
extern kal_bool l4c_nw_set_active_sim_req(kal_uint8 active_sim);
#endif

extern kal_bool l4crac_set_recovery_timer_req(kal_uint8 src_id, kal_uint32* timer, kal_uint8 num);
extern kal_bool l4crac_get_recovery_timer_req(kal_uint8 src_id);

void l4c_nw_send_sim_error_ind(sim_error_cause_enum cause);

#ifdef __VOLTE_SUPPORT__
extern kal_bool l4c_nw_get_ssac_param_req(kal_uint8 src_id);
#endif

#ifdef __UE_EFOPLMN__
extern kal_bool l4c_nw_set_preferred_oper_list_req(kal_uint8 *ver_no, 
                                                   kal_uint8 no_entry, 
                                                   kal_uint8 *oper, 
                                                   kal_uint8 *rat);
#endif

extern kal_bool l4c_nw_get_mm_ims_voice_termination_setting_req(kal_uint8 src_id, kal_uint8 *setting);
extern kal_bool l4c_nw_set_mm_ims_voice_termination_setting_req(kal_uint8 src_id, kal_uint8 setting);

extern kal_bool l4c_nw_vdm_voice_status_req(kal_uint8 src_id, kal_uint8 vdm_voice_status);

#endif /* _L4C_NW_CMD_H */ 

