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
 * l4c_sim_cmd.h
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

#ifndef _L4C_SIM_CMD_H
#define _L4C_SIM_CMD_H

#include "kal_general_types.h"
#include "ps_public_struct.h" 

#include "ps2sat_struct.h"
#include "mcd_ps2sat_peer.h"
#include "l4c2csm_cc_struct.h"
#include "l4c2smsal_struct.h"

#include "sim_ps_enum.h"

#include "mcd_l3_inc_struct.h"       /* for nw_time_zone_time_struct used in l4c_smu_update_nw_time_req() */



enum
{
    NONE_TYPE,
    PHONELOCK_TYPE,
    PIN1_TYPE
};

extern kal_bool l4c_smu_get_iccid_req(kal_uint8 src_id, kal_uint8 *iccid_str);

extern kal_bool l4c_smu_get_imsi_req(kal_uint8 src_id, kal_uint8 *imsi);

extern kal_bool l4c_smu_exe_lock_req(
                    kal_uint8 src_id,
                    kal_uint8 opcode, /* smu_lock_opcode_enum */
                    kal_uint8 type, /* smu_security_type_enum */
                    kal_uint8 *passwd);

extern kal_bool l4c_smu_exe_master_reset_req(kal_uint8 src_id, kal_uint8 *pin);

extern kal_bool l4c_smu_get_dial_mode_req( /* sim_dn_enum */ kal_uint8 *dial_mode);

extern kal_bool l4c_smu_exe_verify_pin_req(kal_uint8 src_id, kal_uint8 pin_type, kal_uint8 *pin, kal_uint8 *new_pin);

extern kal_bool l4c_smu_app_exe_verify_pin_req(kal_uint8 src_id, kal_uint8 pin_type, kal_uint8 *pin, kal_uint8 *new_pin, kal_uint8 chan_id);

extern kal_bool l4c_smu_get_pin_type_req(
                    kal_uint8 src_id, /* smu_security_type_enum */
                    kal_uint8 *name);

extern kal_bool l4c_smu_app_get_pin_type_req(kal_uint8 src_id, kal_uint8 *name, kal_uint8 chan_id, smu_chv_type_enum chv_type);

extern sim_file_index_enum l4c_smu_file_idx_for_preferred_oper_list(sim_file_index_enum selected_file);

extern kal_bool l4c_smu_set_preferred_oper_list_req_ext(
            kal_uint8 src_id,
            sim_file_index_enum file_idx,
            kal_uint8 index,
            kal_uint8 opcode,
            kal_uint8 *oper,
            kal_uint8 rat);

extern kal_bool l4c_smu_set_preferred_oper_list_req(
                    kal_uint8 src_id,
                    kal_uint8 index,
                    kal_uint8 opcode,
                    kal_uint8 *oper,
                    kal_uint8 rat);

extern kal_bool l4c_smu_get_preferred_oper_list_req(
                    kal_uint8 src_id,
                    kal_uint8 index,
                    kal_uint16 file_idx_req,
                    kal_uint16 *num,
                    kal_uint8 *oper_list,
                    kal_uint8 *rat_list,
                    kal_uint16 *file_idx_rsp);

extern kal_bool l4c_smu_set_puc_params_req(kal_uint8 src_id, kal_uint8 *pin, kal_uint8 *currency, kal_uint8 *ppu);

extern kal_bool l4c_smu_get_puc_params_req(kal_uint8 src_id, kal_uint8 *currency, kal_uint8 *ppu);

extern kal_bool l4c_smu_exe_change_password_req(
                    kal_uint8 src_id, /* smu_security_type_enum */
                    kal_uint8 type,
                    kal_uint8 *old,
                    kal_uint8 *new1,
                    kal_uint8 *new2);

extern kal_bool l4c_smu_exe_restricted_access_req(
                    kal_uint8 src_id,
                    kal_uint8 cmd,
                    kal_uint16 file_id,
                    kal_uint8 channel,
                    kal_uint8 p1,
                    kal_uint8 p2,
                    kal_uint8 p3,
                    kal_uint8 *data,
            	      kal_uint8 *pathid,
            	      kal_uint8 pathid_length);

extern kal_bool l4c_smu_exe_dial_mode_req(kal_uint8 src_id, kal_uint8 type, kal_uint8 on_off, kal_uint8 *pin);

extern kal_bool l4c_smu_write_sim_req(
                    kal_uint8 src_id,
                    kal_uint16 file_idx,
                    kal_uint8 para,
                    kal_uint8 *data,
                    kal_uint16 length,
                    kal_uint8 *path,
                    kal_uint8 access_id); 

extern kal_bool l4c_smu_read_sim_req(
                    kal_uint8 src_id,
                    kal_uint16 file_idx,
                    kal_uint16 para,
                    kal_uint16 length,
                    kal_uint8 *path,
                    kal_uint8 access_id); 

extern kal_bool l4c_smu_read_file_info_req(kal_uint8 src_id, kal_uint16 file_idx, kal_uint8 *path, kal_uint8 access_id);   

extern kal_bool l4c_smu_set_personalization_req(
                    kal_uint8 src_id,
                    kal_uint8 category,
                    kal_uint8 op,
                    kal_uint8 key[17],
                    kal_uint8 len,
                    kal_uint8 data[10]);

extern kal_bool l4c_smu_get_shared_key_req(kal_uint8 src_id);

extern kal_bool l4c_smu_update_slb_req(kal_uint8 src_id, kal_uint16 slb_len, kal_uint8 *slb);

extern kal_bool l4c_smu_reset_slb_req(kal_uint8 src_id);

extern kal_bool l4c_smu_get_slb_version_req(kal_uint8 src_id);

#if defined(__SIM_ME_LOCK__)
extern kal_bool l4c_smu_update_nw_time_req(kal_uint8 nw_time_zone, nw_time_zone_time_struct *nw_time);
#endif

extern kal_bool l4c_smu_sml_status_req(kal_uint8 src_id);

extern kal_bool l4c_sim_power_off_req(kal_uint8 src_id);

extern kal_bool l4c_sim_remove_req(kal_uint8 src_id, kal_uint8 mode);

extern kal_bool l4c_sim_get_gsmcdma_dualsim_info_req (kal_uint8 src_id);

extern kal_bool l4c_sim_set_gsmcdma_dualsim_mode_req ( kal_uint8 src_id, kal_uint8 op);

extern kal_bool l4c_sim_check_pin_status_req(sim_chv_info_struct *chv_info, sim_chv_status_struct *chv_status);

extern kal_bool l4c_cphs_update_als_req(kal_uint8 src_id, kal_uint8 line_id);

extern void l4c_sim_pin_convert(kal_uint8 *dest, kal_uint8 *src);

extern kal_bool l4c_sim_reset_req(kal_uint8 src_id);

extern kal_bool l4c_bt_sim_profile_req(kal_uint8 src_id, kal_uint8 action, kal_uint8 transport_protocol_type, kal_uint8 *apdu, kal_uint16 length);

///extern kal_bool l4c_sim_csim_req(kal_uint8 src_id, kal_uint16 length, kal_uint8 *command);

/* MAUI_03082391 *///mtk02514_nfc
extern kal_bool l4c_sim_apdu_access_req(kal_uint8 src_id,l4c_action_enum action, kal_uint16 length, kal_uint8 *command,kal_uint8 channel_id);

extern kal_bool l4c_sim_manage_channel_req(kal_uint8 src_id, l4c_action_enum action, sim_manage_channel_mode_enum mode, kal_uint8 aid_len, kal_uint8 *aid);

#ifdef __VSIM__
extern kal_bool l4c_sim_vsim_req(kal_uint8 src_id, kal_uint8 switch_on);
#endif

extern kal_bool l4c_sim_app_start_req(kal_uint8 src_id, kal_uint8 applicationid);

extern kal_bool l4c_sim_app_authenticate_req(kal_uint8 src_id, uicc_auth_mode_enum mode, kal_uint8 channel_id, kal_uint16 command_len, kal_uint8 *command_data);

extern kal_bool l4c_sim_authenticate_req(kal_uint8 src_id, kal_uint8 rand_len, kal_uint8 *rand, kal_uint8 auth_len, kal_uint8 *auth);

extern void l4c_smu_sml_ready_notify_req(void);

#ifdef __SAT__
extern kal_bool l4c_sat_dspl_text_res(sat_dspl_text_res_struct *local_ptr);

extern kal_bool l4c_sat_get_inkey_res(sat_get_inkey_res_struct *local_ptr, sat_get_inkey_res_peer_struct *peer_ptr);

extern kal_bool l4c_sat_get_input_res(sat_get_input_res_struct *local_ptr, sat_get_input_res_peer_struct *peer_ptr);

extern kal_bool l4c_sat_setup_menu_res(sat_setup_menu_res_struct *local_ptr);

extern kal_bool l4c_sat_select_item_res(sat_select_item_res_struct *local_ptr);

extern kal_bool l4c_sat_play_tone_res(sat_play_tone_res_struct *local_ptr);

extern kal_bool l4c_sat_setup_call_res(sat_setup_call_res_struct *local_ptr);

extern kal_bool l4c_sat_send_sms_res(sat_send_sms_res_struct *local_ptr);

extern kal_bool l4c_sat_send_ss_res(sat_send_ss_res_struct *local_ptr);

extern kal_bool l4c_sat_send_ussd_res(sat_send_ussd_res_struct *local_ptr);

extern kal_bool l4c_sat_setup_idle_dspl_res(sat_setup_idle_dspl_res_struct *local_ptr);

extern kal_bool l4c_sat_run_at_command_res(sat_run_at_command_res_struct *local_ptr);

extern kal_bool l4c_sat_send_dtmf_res(kal_uint8 cmd_detail[5], kal_uint8 res, kal_uint8 additional_info);

extern kal_bool l4c_sat_lang_notify_res(sat_lang_notify_res_struct *local_ptr);

extern kal_bool l4c_sat_launch_browser_res(
                    kal_uint8 cmd_detail[5],
                    kal_uint8 res,
                    kal_uint8 additional_res);  /* MAUI_02888481 additional_info interface change */

extern kal_bool l4c_sat_exe_menu_select_req(sat_menu_select_req_struct *local_ptr);

extern kal_bool l4c_sat_evdl_idle_screen_available_req(void);

extern kal_bool l4c_sat_evdl_language_selection_req(kal_uint8 iso639_language[2]);

extern kal_bool l4c_sat_evdl_browser_termination_req(kal_uint8 browser_termination_cause);

extern kal_bool l4c_sat_provide_lang_info_req(kal_uint8 *lang);

extern kal_bool l4c_sat_file_change_res_req(kal_uint8 src_id, kal_uint8 is_successful);

extern kal_bool l4c_sat_open_channel_req(kal_uint8 cmd_detail[5], kal_uint8 res, kal_uint8 additional_info);

extern kal_bool l4c_sat_close_channel_req(kal_uint8 cmd_detail[5], kal_uint8 res);

extern kal_bool l4c_sat_send_data_req(kal_uint8 cmd_detail[5], kal_uint8 res);

extern kal_bool l4c_sat_recv_data_req(kal_uint8 cmd_detail[5], kal_uint8 res);

extern kal_bool l4c_sat_call_setup_req(
                    l4ccsm_cc_sat_setup_req_struct *local_ptr,
                    kal_uint8 *peer_ptr,
                    kal_uint8 length);

extern kal_bool l4c_sat_send_dtmf_req(kal_uint8 src_id, kal_uint8 *dtmf_digit, kal_uint8 no_digit);

extern kal_bool l4c_sat_abort_dtmf_req(kal_uint8 src_id);

extern kal_bool l4c_sat_send_sms_req(l4csmsal_sat_send_req_struct *local_ptr);

extern kal_bool l4c_rsat_evdl_data_available_req(kal_uint8 channel_status[2], kal_uint8 channel_data_length);

extern kal_bool l4c_rsat_evdl_channel_status_req(kal_uint8 channel_status[2]);

extern kal_bool l4c_rsat_open_gprs_channel_res(kal_uint8 cmd_detail[5], 
											kal_uint8 res, 
											kal_uint8 cause, 
											kal_uint8 ch_status[2], 
											kal_uint8 bearer, 
											sat_gprs_bearer_para_struct bearer_para, 
											kal_uint16 buffer_size);

extern kal_bool l4c_rsat_open_csd_channel_res(kal_uint8 cmd_detail[5], 
											kal_uint8 res, 
											kal_uint8 cause, 
											kal_uint8 ch_status[2], 
											kal_uint8 bearer, 
											sat_csd_bearer_para_struct bearer_para, 
											kal_uint16 buffer_size);

extern kal_bool l4c_rsat_open_server_mode_channel_res(kal_uint8 cmd_detail[5], 
											kal_uint8 res, 
											kal_uint8 cause, 
											kal_uint8 ch_status[2], 
											kal_uint8 bearer, 
											kal_uint16 buffer_size);

extern kal_bool l4c_rsat_close_channel_res(kal_uint8 cmd_detail[5], 
											kal_uint8 res, 
											kal_uint8 cause);

extern kal_bool l4c_rsat_send_data_res(kal_uint8 cmd_detail[5], 
									kal_uint8 ch_type, 
									kal_uint8 res,
									kal_uint8 cause,
									kal_uint8 ch_data_length);	

extern kal_bool l4c_rsat_recv_data_res(kal_uint8 cmd_detail[5], 
									kal_uint8 ch_type, 
									kal_uint8 res,
									kal_uint8 cause,
									kal_uint8 ch_data_length,
									kal_uint8 no_data,
									kal_uint8 *data);

extern kal_bool l4c_rsat_ch_status_res(kal_uint8 cmd_detail[5], 
									kal_uint8 res,
									kal_uint8 cause,
									kal_uint8 channel_status[2]);


extern kal_bool l4c_sat_terminal_response_req(kal_uint8 length, kal_uint8 *terminal_rsp);
extern kal_bool l4c_sat_envelope_req(kal_uint8 src_id, kal_uint8 length, kal_uint8 *envelope_data, kal_bool is_standard);
extern kal_bool l4c_sat_setup_sms(kal_uint8 src_id);
extern kal_bool l4c_sat_setup_ss(void);
extern kal_bool l4c_sat_setup_ussd(void);
extern kal_bool l4c_sat_setup_call(void);
extern kal_bool l4c_sat_dtmf(void);
extern kal_bool l4c_sat_menu_query(kal_uint8 *str, kal_uint16 *str_len);

extern kal_bool l4c_sat_ready_req(kal_uint8 src_id);

#endif /* __SAT__ */ 

extern void l4c_smu_sim_status_update_req(kal_uint8 new_sim_config);
extern void l4c_smu_dual_sim_to_flight_mode_req(void);

extern void l4c_sim_read_plmn_req(kal_uint8 src_id, kal_uint8 access_id, kal_uint16 file_idx);
extern void l4c_sim_write_plmn_req(kal_uint8 src_id, kal_uint8 access_id, kal_uint16 file_idx, kal_uint16 file_size, kal_uint8 *file);
extern void l4c_sim_search_record_req(kal_uint8 src_id,kal_uint16 file_idx, kal_uint16 para, kal_uint8 access_id,  kal_uint8 *path,kal_uint8 pattern_len,kal_uint8 *data);
/* MAUI_02953154 */

extern kal_bool l4c_sim_recovery_enhancement_switch_req(kal_bool mode);

extern kal_bool l4c_sim_query_info_req(kal_uint8 src_id, sim_query_info_enum info_id);

extern kal_bool l4c_sim_terminal_capability_setting_req(kal_uint8 additional_interface);

extern kal_bool l4c_regional_phone_mode_req(kal_uint32 mode);

extern kal_bool l4c_csus_set_sim_slot(kal_uint8 setting);

#endif /* _L4C_SIM_CMD_H */ 

