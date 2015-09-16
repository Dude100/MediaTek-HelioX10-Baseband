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
 * LMMI_RSP.C
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
 *============================================================================
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


#define LMMI_RSP_C

#if ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__))

//#include "kal_release.h"      	/* Basic data type */
//#include "stack_common.h"
//#include "stack_msgs.h"
//#include "app_ltlcom.h"       	/* Task message communiction */
//#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
//#include "app_buff_alloc.h"
//#include "stack_timer.h"
//#include "event_shed.h"

#if defined (__MMI_SMI__) || defined (__MMI_FMI__)

#else

#include "mcd_l4_common.h"

//#include "l4c_common_enum.h"
//#include "l4c_rspfmttr.h"

//#include "l4c_aux_struct.h"
//#include "l4c2csm_ss_struct.h"
//#include "smsal_l4c_defs.h"
//#include "l4c2smsal_struct.h"


#ifdef __MOD_SMU__
//#include "ps2sim_struct.h"
//#include "sim_common_enums.h"
//#include "smu_common_enums.h"
#endif
//#include "csmss_common_enums.h"
//#include "rmmi_common_enum.h"
//#include "ps2sim_struct.h"
#include "smsal_l4c_enum.h"
//#include "l4c_sms_cmd.h"
//#include "rmmi_context.h"
//#include "l4c_context.h"
//#include "layer4_context.h"
//#include "l4c_rspfmttr.h"

//#include "mcd_l3_inc_struct.h"
//#include "mcd_l3_inc_gprs_struct.h"
//#include "l3_inc_enums.h"

//#include "l4_defs.h"
//#include "csmcc_atfunc.h"
//#include "csmss_atfunc.h"
//#include "l4c_aux_struct.h"
//#include "l4c_ss_parse.h"

//vito #ifdef __TCPIP__
#if 1
//#include "custom_nvram_editor_data_item.h"
//#include "l4c2abm_struct.h"
//#include "abm2l4c_struct.h"
#endif
//#include "em_struct.h"

//#include "l4c2phb_enums.h"
//#include "l4c2phb_struct.h"

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "ps_public_struct.h"
#include "med_struct.h"

void l4c_null_function_lrsp(void)
{
	ASSERT(0);
}

void l4c_cc_exe_reset_acm_lrsp(kal_bool result, kal_uint16 cause){}

void l4c_cc_set_acm_max_lrsp(kal_bool result, kal_uint16 cause){}

void l4c_cc_exe_reset_ccm_lrsp(kal_bool  result,kal_uint16  cause) {}

void l4c_cc_exe_chld_lrsp(kal_bool result, kal_uint16 cause,kal_uint8 opcode){}

//MAUI_01998659 void l4c_cc_exe_hangup_active_call_lrsp(void){}

void l4c_cc_exe_call_deflect_lrsp(kal_bool result, kal_uint16 cause){}

#if defined(__NONE_USED_L4MMI_MESSAGE__)
void l4c_cc_exe_start_dtmf_wrsp( kal_uint8 call_id, kal_uint8 response,
								kal_uint8 tone, kal_uint8 cause_present,
								kal_uint16 cause){}

void l4c_cc_exe_stop_dtmf_wrsp(void){}
#endif


void l4c_cc_exe_start_dtmf_lrsp( kal_uint8 call_id, kal_uint8 response,
				 kal_uint8 tone, kal_uint8 cause_present,
				 kal_uint16 cause){}

void l4c_cc_exe_stop_dtmf_lrsp( kal_uint8 call_id, kal_uint8 response,
				kal_uint8 tone, kal_uint8 cause_present,
				kal_uint16 cause){}

void l4c_cc_exe_ata_lrsp(l4c_result_struct result, kal_uint8 call_mode){}

void l4c_cc_exe_call_setup_lrsp(l4c_result_struct result,
                                kal_uint8 call_id, 
                                kal_bool is_diag_present, 
                                kal_uint8 diag){} //MAUI_02526481

#if defined(__NONE_USED_L4MMI_MESSAGE__)
void l4c_cc_exe_call_setup_wrsp(l4c_result_struct result,
                                kal_uint8 call_id){}
#endif

/*MAUI_01998659
void l4c_cc_exe_call_modify_lrsp (l4c_result_struct result,
                                         kal_uint8 call_mode){}
*/

void l4c_cc_exe_ath_lrsp(void){}

void l4c_ss_exe_emlpp_lrsp(l4c_result_struct result,
								  kal_uint8 para_present,
                                  kal_uint8 opcode,
                                  kal_uint8 default_pri,
                                  kal_uint8 max_pri){}

void l4c_ss_exe_call_forward_lrsp(l4c_result_struct result,
										kal_uint8 para_present,
                                         kal_uint8 opcode,
                                         kal_uint8 type,
                                         kal_uint8 count,
                                         forwarding_list_struct *list){}

void l4c_ss_exe_call_wait_lrsp(l4c_result_struct result,
									  kal_uint8 para_present,
                                      kal_uint8 opcode,
                                      kal_uint8 count,
                                      kal_uint8 status,
                                      kal_uint8 *list){}

/*MAUI_01998659
void l4c_ss_exe_cdip_interrogate_lrsp(l4c_result_struct result,
	                                         kal_uint8 para_present,
                                             kal_uint8 status){}
*/

void l4c_ss_exe_call_barring_lrsp(l4c_result_struct result,
	                                     kal_uint8 para_present,
                                         kal_uint8 opcode,
                                         kal_uint8 type,
                                         kal_uint8 count,
                                         barring_list_struct *list){}

void l4c_ss_exe_clip_interrogate_lrsp(l4c_result_struct result,
											 kal_uint8 para_present,
                                             kal_uint8 status,
                                             kal_uint8 clir_option){}

void l4c_ss_exe_clir_interrogate_lrsp(l4c_result_struct result,
	                                         kal_uint8 para_present,
                                             kal_uint8 status,
                                             kal_uint8 clir_option){}

void l4c_ss_exe_cnap_interrogate_lrsp(l4c_result_struct result,
											 kal_uint8 para_present,
                                             kal_uint8 status,
                                             kal_uint8 clir_option){}

void l4c_ss_exe_colp_interrogate_lrsp(l4c_result_struct result,
											 kal_uint8 para_present,
                                             kal_uint8 status,
                                             kal_uint8 clir_option){}

void l4c_ss_exe_colr_interrogate_lrsp(l4c_result_struct result,
											 kal_uint8 para_present,
                                             kal_uint8 status,
                                             kal_uint8 clir_option){}

void l4c_ss_exe_change_password_lrsp(l4c_result_struct result){}

void l4c_ss_exe_ccbs_lrsp (l4c_result_struct result,
								  kal_uint8 para_present,
                                  kal_uint8 opcode,
                                  kal_uint8 ccbs_count,
                                  ccbs_list_struct *list){}

void l4c_ss_exe_ussd_lrsp(l4c_result_struct result,
	                          kal_uint8 para_present,
	                          kal_uint8 op_code,
                                  kal_uint8 dcs,
                                  kal_uint8 *ussd_str,
                                  kal_uint8 length,
                                  kal_uint8 ussd_version){}

void l4c_df_exe_back_data_state_lrsp(){} /* not ready */

#ifdef __MOD_RAC__

void l4c_nw_abort_plmn_list_lrsp(kal_bool result){}

void l4c_nw_exe_att_lrsp(kal_bool result){}

void l4c_nw_exe_cops_lrsp(l4c_result_struct result,
                          kal_uint8 status, kal_uint8 *plmn, kal_uint8 rat){}

void l4c_nw_powroff_detach_lrsp(l4c_result_struct result){}

void l4c_nw_get_plmn_list_lrsp(l4c_result_struct result,
                               kal_uint8 length,                               
                               l4c_rat_plmn_info_struct *list,
                               kal_uint8 num_of_hplmn){}

//void l4c_nw_set_class_lrsp(kal_bool result, kal_uint16 cause){}

void l4c_nw_set_hspa_mode_lrsp(kal_bool result) {} //mtk02285, hspa_mmi

void l4c_nw_set_preferred_band_lrsp(kal_bool result, kal_uint8 status){}

void l4c_nw_cfun_state_lrsp(kal_bool result){}

void l4c_nw_efun_state_lrsp(kal_bool result){}

void l4c_nw_set_rat_mode_lrsp(kal_bool result){}

void l4c_nw_set_prefer_rat_lrsp(kal_bool result){}

void l4c_nw_end_ps_data_session_lrsp(kal_uint8 result){}

#endif /* __MOD_RAC__ */

void l4c_smu_exe_lock_lrsp(kal_bool result, kal_uint16 cause, sim_chv_info_struct chv_info){}

void l4c_smu_exe_master_reset_lrsp(kal_bool result, kal_uint16 cause){}

void l4c_smu_exe_verify_pin_lrsp(kal_bool result, kal_uint8 next_type,sim_chv_info_struct chv_info){}

void l4c_smu_set_preferred_oper_list_lrsp (kal_bool result,
                                                  kal_uint16 cause){}

void l4c_smu_set_puc_params_lrsp(kal_bool result, kal_uint16 cause){}

void l4c_smu_exe_change_password_lrsp(kal_bool result, kal_uint16 cause, sim_chv_info_struct chv_info){}

void l4c_smu_exe_dial_mode_lrsp(kal_bool result, kal_uint16 cause){}

//void l4c_smu_exe_restricted_access_lrsp(l4c_result_struct result, kal_uint8 sw1, kal_uint8 sw2, kal_uint16 length, kal_uint8 *resp){}

void l4c_smu_write_sim_lrsp (kal_bool result, kal_uint16 cause, kal_uint8 access_id){} 

void l4c_smu_read_sim_lrsp (l4c_result_struct result,
                             kal_uint16 length,
                             kal_uint8 *data,
                             kal_uint8 access_id){} 

void l4c_sim_search_record_lrsp (kal_bool result,
                                    kal_uint16 cause,	
                                    kal_uint8 access_id,
                                    kal_uint8 record_num,
                                    kal_uint8 *record){} 
/* MAUI_02953154 */

void l4c_sim_get_gsmcdma_dualsim_info_lrsp (kal_uint8 is_sim_inserted,
                                            kal_uint8 is_df_gsm_existed,
                                            kal_uint8 is_df_cdma_existed){}

void l4c_sim_set_gsmcdma_dualsim_mode_lrsp (kal_uint8 op, kal_uint8 result){}

void l4c_sim_read_plmn_lrsp(kal_uint8 access_id, 
					kal_uint16 file_idx, 
					l4c_result_struct result, 
					kal_uint16 file_size, 
					kal_uint8 *file){}
void l4c_sim_write_plmn_lrsp(kal_uint8 access_id, 
					kal_uint16 file_idx, 
					l4c_result_struct result){}


void l4c_eq_get_uart_port_lrsp(kal_bool result,
                               kal_uint8 ps_uart_port,
                               kal_uint32 ps_baud_rate,
                               kal_uint8 tst_uart_port_ps,
                               kal_uint32 tst_baud_rate_ps,
                               kal_uint8 cti_uart_port,
                               kal_uint32 cti_baud_rate,
                               kal_uint8 tst_uart_port_l1,
                               kal_uint32 tst_baud_rate_l1,
                               kal_uint8 tst_output_mode,
                               kal_uint8 usb_logging_mode,
                               kal_uint8 tst_port_dsp,
                               kal_uint32 tst_baud_rate_dsp,
                               kal_bool high_Speed_SIM_Enabled,
                               kal_uint8 swdbg,
                               kal_uint8 uart_power_setting){} 

void l4c_smu_read_file_info_lrsp(l4c_result_struct result,
                                        kal_uint16 file_size,
                                        kal_uint8 num_of_rec,
                                        kal_uint8 access_id, 
                                        kal_uint8 file_type){} 

void l4c_smu_set_personalization_lrsp(l4c_result_struct result,
                                             kal_uint8 category,
                                             kal_uint8 op,
                                             kal_uint8 state,
                                             kal_uint8 retry_count,
                                             kal_uint8 num_of_sets,
                                             kal_uint8 space_of_sets){}

void l4c_smu_sml_status_lrsp(l4c_result_struct result,
                                    kal_uint8 state[7],
                                    kal_uint8 retry_count[7],
                                    kal_uint8 autolock_count[7],
                                    kal_uint8 num_of_sets[7],
                                    kal_uint8 total_size_of_cat[7],
                                    kal_uint8 key_state[7],
                                    kal_uint8 imsi[16],
                                    kal_uint8 is_valid_gid1,
                                    kal_uint8 ef_gid1,
                                    kal_uint8 is_valid_gid2,
                                    kal_uint8 ef_gid2,
                                    kal_uint8 digits_of_mnc){}
                                    
void l4c_sim_reset_lrsp(kal_bool is_sim_inserted, kal_uint8 dual_sim_mode_setting){}
                                    
#ifdef __MOD_SMSAL__
void l4c_sms_set_profile_params_lrsp(kal_bool result,
											kal_uint16 cause
											){}

void l4c_sms_set_common_params_lrsp(kal_bool result,
									kal_uint16 cause){}

void l4c_sms_exe_post_command_lrsp (kal_bool result,
							kal_uint16 cause,
                                               kal_uint8 mr,
                                               kal_uint8 *scts,
                                               kal_uint8 source_id){}

void l4c_sms_exe_delete_msg_lrsp (kal_bool result,
										kal_uint16 cause,
										smsal_del_flag_enum del_flag,
										kal_uint16 index,
										kal_uint8 storage_type,
										kal_uint8 *del_bitmap,
										kal_uint8 source_id){}

//void l4c_sms_exe_read_msg_list_lrsp (l4c_sms_inbox_list_struct inbox,
 //                                           l4c_sms_outbox_list_struct outbox){}

void l4c_sms_exe_read_msg_lrsp (kal_bool result,
	 								kal_uint16 cause,
                                               smsal_concat_struct concat_info,
                                               kal_uint16 dest_port,
                                               kal_uint16 src_port,
											   kal_uint16 length,
                                               kal_uint8 mti,
                                               kal_uint8 status,
                                               kal_uint8 hex_dspl,
                                               kal_uint8 storage_type,
                                               l4_name_struct alpha_id,
                                               kal_uint8 *scts_submit, /* Johnny: only for SMSAL_MTI_SUBMIT */
                                               void *msg_header,
                                               kal_uint8 source_id,
                                               void *data){}

void l4c_sms_exe_read_raw_data_lrsp(kal_uint8  result,
										   kal_uint16 cause,
										   kal_uint16 index,
										   kal_uint8  status,
	                              					   kal_uint8  storage_type,
	                              					   kal_uint16 data_len,
  										   void* data){}

void l4c_sms_exe_write_raw_data_lrsp(kal_uint8  result,
										    kal_uint16 cause,
										    kal_uint16 index,
										    kal_uint8  status,
	                              					    kal_uint8  storage_type){}

void l4c_sms_exe_post_msg_lrsp (kal_bool result,
							kal_uint16 cause,
                                               kal_uint8 mr,
                                               kal_uint8 *scts,
                                               kal_uint8 seq_num,
                                               smsal_concat_struct concat_info,
                                               kal_uint8 source_id){}

void l4c_sms_exe_write_msg_lrsp (kal_bool  result,
					kal_uint16 cause,
                                 kal_uint16 index,
                                 kal_uint8 status,
                                 kal_uint8 storage_type,
                                 kal_uint8 source_id){}

void l4c_sms_exe_storage_post_lrsp (l4c_result_struct result,
                                               kal_uint8 mr,
                                               kal_uint8 *scts,
                                               void *concat_info){}

void l4c_sms_set_bearer_service_lrsp (kal_bool result, kal_uint16 cause){}

void l4c_sms_set_sc_addr_lrsp (kal_bool result, kal_uint16 cause){}

void l4c_sms_set_post_params_lrsp (kal_bool result, kal_uint16 cause){}

void l4c_sms_set_preferred_mem_lrsp (kal_bool result,
                                     smsal_prefer_storage_struct *param){}

void l4c_sms_set_mailbox_addr_lrsp (kal_bool result, kal_uint16 cause){}
void l4c_sms_get_mailbox_addr_lrsp (kal_bool result,kal_uint8 mailbox_num,kal_uint8 alpha_length,kal_uint8 max_num_length,l4c_sms_mailbox_info_struct *mailbox_info){}//mtk01616_071213
void l4c_sms_set_mbi_lrsp (kal_bool result, kal_uint16 cause){}

void l4c_sms_exe_read_msg_list_lrsp (smsal_inbox_list_struct inbox,
                                            smsal_outbox_list_struct outbox){}

void l4c_sms_copy_msg_lrsp(kal_uint8 result,
						 kal_uint16 cause,
						 kal_uint8 action,
						 kal_uint8 dst_storage,
						 kal_uint16 src_index,
						 kal_uint16 dst_index,
						 kal_uint8 source_id){}


void l4c_sms_send_from_storage_lrsp(kal_bool result,
					kal_uint16 cause,
					kal_uint8 mr,
					kal_uint16 index,
			                smsal_concat_struct concat_info,
			                kal_uint8 source_id){}

void l4c_sms_set_status_lrsp(kal_bool result,kal_uint16 error_cause,kal_uint16 index,kal_uint8 source_id){}

void l4c_sms_exe_abort_lrsp(kal_bool result,kal_uint8 source_id, kal_uint8 seq_num){}
void l4c_sms_exe_send_smma_lrsp(kal_bool result,kal_uint8 source_id){}
void l4c_sms_exe_set_msg_waiting_lrsp(kal_bool result,kal_uint16 cause,kal_uint8 source_id,kal_uint8 line_no,kal_uint8 waiting_num,kal_uint8 ind_type){}
void l4c_sms_send_deliver_report_lrsp(kal_bool result, kal_uint32 error_cause, kal_uint8 uid){}//mtk02088_storage8 
void l4c_sms_send_pdu_msg_lrsp(kal_bool result, kal_uint16 cause, kal_uint8 source_id, kal_uint8 mr, kal_uint8 seq_num){} 

void l4c_sms_etws_setting_lrsp(kal_bool result, kal_uint16 cause){} 

#endif /* __MOD_SMSAL__ */

extern void l4c_em_update_rsp(kal_bool result,
                             kal_uint8 cause){}
                            
extern void l4c_em_cell_resel_suspend_rsp(kal_bool result,
                                          kal_uint8 cause){}

extern void l4c_em_cell_resel_resume_rsp(kal_bool result,
                                         kal_uint8 cause){}                             

void l4c_em_get_cell_lock_rsp(kal_bool result, 
									kal_bool turn_on_or_off, 
									kal_bool band_indicator, 
									kal_uint16 lock_arfcn){}

void l4c_em_set_cell_lock_rsp(kal_bool result){}

void l4c_em_ext_get_cell_lock_lrsp(kal_bool result,
                                          kal_uint32 enabled_bitmap,
                                          kal_bool band_indicator,
                                          kal_uint16 *lock_arfcn){}

void l4c_em_ext_set_cell_lock_lrsp(kal_bool result){}

void l4c_em_nw_event_notify_rsp(kal_bool result){}
void l4c_em_feature_command_rsp(kal_bool result, kal_uint8 em_feature){}
void l4c_em_get_conftest_para_lrsp(kal_bool result, kal_uint8 conf_test_mode, kal_uint32 test_profile){}
void l4c_em_set_conftest_para_lrsp(kal_int8 result){}

void l4c_sms_set_cb_mode_lrsp(kal_bool result, kal_uint16 cause){}

#ifdef __MOD_TCM__
void l4c_ps_exe_act_lrsp (kal_bool result, kal_uint16 cause){}
void l4c_ps_exe_act_test_lrsp(kal_bool result, kal_uint16 cause){}
void l4c_ps_exe_modify_lrsp (kal_bool result, kal_uint16 cause){}
void l4c_ps_set_definition_lrsp ( kal_bool result, kal_uint16 cause){}

void l4c_ps_reset_gprs_data_counter_lrsp(kal_bool result, kal_uint16 cause){}

void l4c_ps_set_gprs_data_account_lrsp(kal_uint8 src_id,kal_bool result, kal_uint16 cause){}

void l4c_ps_get_gprs_data_account_lrsp(kal_bool result, l4c_gprs_account_info_struct gprs_account){}

void l4c_ps_set_sec_definition_lrsp (kal_bool result,
                                     kal_uint16 cause){}
void l4c_ps_set_qos_lrsp (kal_bool result, kal_uint16 cause){}

void l4c_ps_get_acl_mode_lrsp(kal_bool result, kal_uint8 dial_mode) {}

void l4c_ps_set_acl_mode_lrsp(kal_bool result, kal_uint16 cause) {}

void l4c_ps_get_acl_entries_lrsp(l4c_result_struct result, kal_uint16 start_index, kal_uint16 num_of_entries, kal_bool more_flag, l4c_tcm_acl_entry_struct *acl_list) {}

void l4c_ps_add_acl_entry_lrsp(l4c_result_struct	 result) {}

void l4c_ps_set_acl_entry_lrsp(l4c_result_struct	 result) {}

void l4c_ps_del_acl_entry_lrsp(l4c_result_struct result) {}

#ifdef __R99__
void l4c_ps_set_eqos_lrsp (kal_bool result, kal_uint16 cause){}
#endif
void l4c_ps_set_tft_lrsp (kal_bool result, kal_uint16 cause){}
#endif
/* below not ready */
void l4c_eq_read_nvram_lrsp (l4c_result_struct result,
					 kal_uint16 file_idx,
                                    kal_uint16 length,
                                    kal_uint16 para,
                                    kal_uint8 *data) {}
void l4c_eq_set_audio_profile_lrsp(kal_bool result, kal_uint16 cause){}

void l4c_eq_get_audio_profile_lrsp(kal_bool result, audio_profile_struct audio_prof_out){}

void l4c_eq_set_audio_param_lrsp(kal_bool result, kal_uint16 cause){}

void l4c_eq_get_audio_param_lrsp(kal_bool result, audio_param_struct* audio_para){}

void l4c_eq_gpio_detect_res_lrsp(kal_bool result){}

void l4c_eq_audio_play_by_name_lrsp(kal_bool result, kal_uint16 cause){}
void l4c_eq_audio_stop_by_name_lrsp(kal_bool result, kal_uint16 cause){}

void l4c_eq_audio_play_by_string_lrsp(kal_bool result, kal_uint16 cause){}
void l4c_eq_audio_stop_by_string_lrsp(kal_bool result, kal_uint16 cause){}

//void l4c_eq_set_volume_lrsp (kal_bool result, kal_uint16 cause){}
//void l4c_eq_set_mute_mode_lrsp (kal_bool result, kal_uint16 cause){}
//void l4c_eq_set_silent_mode_lrsp (kal_bool result, kal_uint16 cause){}
void l4c_eq_set_rtc_time_lrsp (kal_bool result, kal_uint16 cause){}
//void l4c_eq_exe_rtc_delete_lrsp (kal_bool result, kal_uint16 cause){}
//void l4c_eq_set_date_time_format_lrsp (kal_bool result, kal_uint16 cause){}
void l4c_eq_set_language_lrsp (kal_bool result, kal_uint16 cause){}
//void l4c_eq_set_gpio_level_lrsp (kal_bool result, kal_uint16 cause){}
#if defined(__NONE_USED_L4MMI_MESSAGE__)
void l4c_eq_set_greeting_text_lrsp (kal_bool result, kal_uint16 cause){}
void l4c_eq_set_country_code_lrsp (kal_bool result, kal_uint16 cause){}
#endif
void l4c_eq_set_hw_level_lrsp(kal_bool result, kal_uint16 cause){}
#if defined(__NONE_USED_L4MMI_MESSAGE__)
void l4c_eq_set_vibrator_mode_lrsp(kal_bool result, kal_uint16 cause){}
#endif
void l4c_eq_cancel_lock_poweron_lrsp(kal_bool result, kal_uint16 cause){}
#if defined(__NONE_USED_L4MMI_MESSAGE__)
void l4c_eq_vm_record_lrsp(kal_bool result, kal_uint16 cause){}
void l4c_eq_vm_play_lrsp(kal_bool result, kal_uint16 cause){}
void l4c_eq_vm_delete_lrsp(kal_bool result, kal_uint16 cause){}
void l4c_eq_vm_abort_lrsp(kal_bool result, kal_uint16 cause){}
void l4c_eq_vm_append_lrsp(kal_bool result, kal_uint16 cause){}
void l4c_eq_vm_rename_lrsp(kal_bool result, kal_uint16 cause){}
void l4c_eq_vm_resume_lrsp(kal_bool result, kal_uint16 cause){}
#ifdef __FS_ON__
void l4c_eq_vm_get_info_lrsp(kal_uint16 no_vm, kal_wchar *file_list,
                             kal_bool more_entry, kal_uint32 free_space){}
void l4c_eq_vm_stop_lrsp(l4c_result_struct result, kal_wchar *file_name){}
void l4c_eq_vm_pause_lrsp(l4c_result_struct result, kal_wchar *file_name){}
#else
void l4c_eq_vm_get_info_lrsp(kal_uint32 index, kal_uint32 time){}
void l4c_eq_vm_stop_lrsp(l4c_result_struct result, kal_uint8 file_id){}
void l4c_eq_vm_pause_lrsp(l4c_result_struct result, kal_uint8 file_id){}
#endif
#endif
void l4c_attach_uart_port_lrsp(kal_uint8 result){} //l4c_port_result_enum
void l4c_detach_uart_port_lrsp(kal_uint8 result){} //l4c_port_result_enum

void l4c_phb_get_msisdn_lrsp (l4c_result_struct result,
                                    kal_uint16 no_list,
                                    l4c_phb_entry_struct *list){}
void l4c_phb_get_entry_by_index_lrsp (l4c_result_struct result,
                                    kal_uint16 no_list,
                                    l4c_phb_entry_struct *list, 
                                    kal_uint8 phb_result){}

void l4c_phb_sms_fdn_check_lrsp (kal_bool result,
                                    kal_uint8 cause){}

void l4c_phb_exe_write_entry_lrsp (l4c_result_struct result,
                                    kal_uint16 no_list,
                                    l4c_phb_entry_struct *list){}
#if defined(__NONE_USED_L4MMI_MESSAGE__)
void l4c_phb_exe_write_entry_wrsp (l4c_result_struct result,
                                    kal_uint16 no_list,
                                    l4c_phb_entry_struct *list){}
#endif

void l4c_phb_exe_delete_entry_lrsp (l4c_result_struct result,
                                    kal_uint16 no_list,
                                    l4c_phb_entry_struct *list,
                                    kal_uint16 old_index,
				    kal_uint8 type){}		

void l4c_phb_exe_read_ln_entry_lrsp (l4c_result_struct result,
                             kal_uint8 no_list,
                             kal_uint8 type,
                             kal_uint8 more_data,
                             l4c_phb_entry_struct *list){}

void l4c_phb_exe_write_ln_entry_lrsp (l4c_result_struct result,
                             kal_uint16 no_list,
                             l4c_phb_entry_struct list,
                             kal_uint8 type){}

void l4c_phb_exe_delete_ln_entry_lrsp (l4c_result_struct result,
                                    kal_uint16 no_list
                                    /*l4c_phb_entry_struct *list*/){}

void l4c_phb_read_usim_lrsp(l4c_result_struct *result,
                            kal_uint8 type,
                            kal_uint8 occurrence,
                            kal_uint16 record_index,
                            l4c_phb_usim_entry *entry){}

void l4c_phb_write_usim_lrsp(l4c_result_struct *result,
                            kal_uint8 type,
                            kal_uint8 occurrence,
                            kal_uint16 record_index,
                            l4c_phb_usim_entry *entry){}

void l4c_phb_delete_usim_lrsp(l4c_result_struct *result,
                            kal_uint8 type,
                            kal_uint8 occurrence,
                            kal_uint16 record_index){}

void l4c_phb_check_write_usim_entry_lrsp(l4c_result_struct *result,
                            kal_uint8 occurrence,
                            kal_uint16 record_index){}


void l4c_phb_number_check_lrsp(kal_bool result, kal_uint8 type){}

void l4c_phb_get_type_info_lrsp(kal_uint8 type, 
				  kal_bool result, 
				  kal_uint16 max_num_length, 
				  kal_uint16 max_text_length, 
				  kal_uint16 num_of_used_rec, 
				  kal_uint16 num_of_tot_rec, 
				  kal_uint16 num_of_free_ext){}

void l4c_phb_fdn_get_name_lrsp(l4c_result_struct result,
                            l4_name_struct alpha_id){}

extern void l4c_phb_get_ln_type_info_lrsp(kal_uint8 type, 
				  kal_bool result, 
				  kal_uint16 max_num_length, 
				  kal_uint16 max_text_length, 
				  kal_uint16 num_of_used_rec, 
				  kal_uint16 num_of_tot_rec, 
				  kal_uint16 num_of_free_ext);


void l4c_phb_read_sim_ln_lrsp(
                            l4c_result_struct result,
                            l4c_phb_ln_entry_struct entry){}

void l4c_phb_write_sim_ln_lrsp(
                            l4c_result_struct result,
                            kal_uint8 type){}

void l4c_phb_delete_sim_ln_lrsp(
                            l4c_result_struct result,
                            kal_uint8 type){}



void l4c_eq_usbconfig_lrsp(kal_bool result,
						kal_uint8 mode,
						kal_uint32 reserved){}


void l4c_sms_exe_load_profile_lrsp (){}
void l4c_sms_exe_save_profile_lrsp (){}
void l4c_sms_set_msg_ind_mode_lrsp (){}
void l4c_sat_exe_menu_select_lrsp (kal_uint8 result){}
void l4c_eq_write_nvram_lrsp (l4c_result_struct result,
                              kal_uint16 file_idx,
                              kal_uint16 para){}

void l4c_eq_reset_nvram_lrsp (l4c_result_struct result){}

void l4c_sat_call_setup_lrsp (l4c_result_struct result,
                                  kal_uint8 terminal_res,
                                  kal_uint8 additional_res){}
void l4c_sat_send_sms_lrsp (kal_uint8 res,
                            kal_uint16 cause){}
void l4c_sat_send_ss_lrsp (kal_uint8 res,
                                     kal_uint8 length,
                                     kal_uint8 *addition_info){}
void l4c_sat_send_ussd_lrsp (kal_uint8 res,
                             kal_uint8 length,
                             kal_uint8 *addition_info){}

void l4c_sat_envelope_lrsp(kal_uint16 sim_result, //sim_cmd_result_enum
                                kal_uint16 length,
                                kal_uint8 *envelope_rsp){}
void l4c_ss_string_parsing_lrsp(l4c_result_struct result, l4c_ss_string_info_struct *info){}

void l4c_ss_operation_lrsp(l4c_result_struct result){} 

void l4c_sat_send_dtmf_lrsp (kal_uint8 terminal_res,
                            kal_uint8 cause){}


void l4c_cphs_update_als_lrsp(kal_uint8  res,kal_uint16  cause) {}


void l4c_eq_lcd_set_contrast_lrsp(kal_int32 result) {}

void l4c_eq_rtc_delete_lrsp(kal_bool  result,kal_uint16  cause) {}

#if defined(__NONE_USED_L4MMI_MESSAGE__)
void l4c_em_set_cell_id_lock_lrsp(kal_bool result){}    
#endif
void l4c_vt_em_get_config_lrsp(vt_em_config_struct em_config){}
#ifdef __SATCE__
void l4c_sat_open_channel_lrsp (kal_uint8 terminal_res){}

void l4c_sat_close_channel_lrsp (kal_uint8 terminal_res){} // for code gen , we wont use it


void l4c_sat_send_data_lrsp (kal_uint8 *cmd_detail,
							kal_uint8 terminal_res,
                            kal_uint8 cause){}

void l4c_sat_recv_data_lrsp (kal_uint8 *cmd_detail,
							kal_uint8 terminal_res,
                            kal_uint8 cause){}

#endif /* __SATCE__ */

void l4c_eq_pmic_config_lrsp(kal_uint8 request_type, pmic_config_param_struct request){}

void l4c_eq_dcm_enable_lrsp(){}

void l4c_eq_rf_test_gsm_lrsp(kal_uint8 request_type, rf_test_gsm_param_struct request){}

void l4c_eq_fm_radio_config_lrsp(kal_uint8 request_type, fm_radio_config_param_struct request){}

#if defined(__WIFI_SUPPORT__)
void l4c_eq_rf_test_wifi_lrsp(kal_uint8 request_type, rf_test_wifi_param_struct request){}
#endif

#if 0 //__CTM_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __VOIP__
void l4c_mmi_voip_at_call_ctrl_approve_lrsp(kal_bool result){}
#endif

void l4c_eq_query_cal_data_dl_status_lrsp(kal_bool cal_data_valid){}

#ifdef __AGPS_CONTROL_PLANE__
void l4c_ss_mtlr_begin_res_lrsp(kal_uint8 result, kal_uint8 ss_id){}
void l4c_ss_aerq_begin_res_lrsp(kal_uint8 result, kal_uint8 ss_id){}
void l4c_ss_aerp_begin_lrsp(kal_uint8 result, kal_uint16 cause, kal_uint8 ss_id){}
void l4c_ss_aerp_end_lrsp(kal_uint8 result){}
void l4c_ss_aecl_begin_res_lrsp(kal_uint8 result, kal_uint8 ss_id){}
void l4c_ss_molr_begin_lrsp(kal_uint8 result, kal_uint16 cause, L4C_SS_LCS_MOLRRes *molr_res, kal_uint8 ss_id){}
void l4c_ss_molr_end_lrsp(kal_uint8 result){}
#endif

#endif /* __MMI_SMI__ */

#endif
