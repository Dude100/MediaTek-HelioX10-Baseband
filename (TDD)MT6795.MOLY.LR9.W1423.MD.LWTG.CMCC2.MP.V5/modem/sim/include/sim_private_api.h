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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   sim_private_api.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   API provided by SIM task and inside-SIM task uses only
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef SIM_PRIVATE_API_H
#define SIM_PRIVATE_API_H

#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_general_types.h"
#include "kal_public_api.h" 
#include "sim_private_enum.h"
#include "sim_private_struct.h"
#include "sim_public_enum.h"

/* Driver related*/
#include "drv_comm.h"
#include "dcl.h"

extern void sim_task_main(task_entry_struct *task_entry_ptr);
extern kal_bool sim_init(kal_uint8 sim_indx);
extern void sim_main(kal_uint8 sim_indx, ilm_struct *ilm_ptr);
extern void sat_fetch_proactive_cmd(kal_uint16 proactive_cmd_len, sim_context_struct *this_sim);
extern kal_bool sim_process_init(void);
extern void sim_process_ilm(ilm_struct *current_ilm);
extern kal_bool sim_deinit(kal_uint8 sim_indx); /*[MAUI_02452276] mtk01612: must release sim_hd before clear is_sim_hd_valid to avoid double allocation*/

extern kal_uint16 Sim_Cmd_All(
            kal_uint8 *txData,
            kal_uint32 *txSize,
            kal_uint8 *rxData,
            kal_uint32 *rxSize,
            sim_context_struct *this_sim);

extern sim_cmd_result_enum sim_al_select(
                            sim_file_index_enum file_idx, 
                            kal_uint16 *status_word, 
                            kal_uint8 *rx_data, 
                            kal_uint8 *rx_size_ptr,
                            sim_context_struct *this_sim);
extern sim_cmd_result_enum sim_al_get_response(
                            kal_uint8 *getresponse_data_ptr,
                            kal_uint8 len,
                            sim_context_struct *this_sim);
extern sim_cmd_result_enum sim_al_reset(
                            sim_al_reset_type_enum type, 
                            sim_context_struct *this_sim);
extern sim_cmd_result_enum sim_al_verify_chv(
                            kal_uint8 which_chv,
                            kal_uint8 *chv_ptr,
                            kal_uint16 *status_word,
                            usim_logic_channel_enum channel,
                            sim_context_struct *this_sim);
extern sim_cmd_result_enum sim_al_unblock_chv(
                            kal_uint8 which_chv,
                            kal_uint8 *unblock_chv_ptr,
                            kal_uint8 *new_chv_ptr,
                            kal_uint16 *status_word,
                            usim_logic_channel_enum channel,
                            sim_context_struct *this_sim);
extern sim_cmd_result_enum sim_al_change_chv(
                            kal_uint8 which_chv,
                            kal_uint8 *old_chv_ptr,
                            kal_uint8 *new_chv_ptr,
                            kal_uint16 *status_word,
                            usim_logic_channel_enum channel,
                            sim_context_struct *this_sim);

extern sim_cmd_result_enum sim_al_switch_chv(
                                              sim_instruction_code_enum	chv_op,
                                              kal_uint8 which_pin,
                                              kal_uint8 *chv_ptr, 
                                              kal_uint16 *status_word,
                                              usim_logic_channel_enum channel,
                                              sim_context_struct *this_sim);

extern sim_cmd_result_enum sim_al_read_binary(
                            kal_uint16 offset,
                            kal_uint16 num_bytes,
                            kal_uint8 *read_data_ptr,
                            kal_uint16 *status_word,
                            usim_logic_channel_enum channel,
                            sim_context_struct *this_sim);
extern sim_cmd_result_enum sim_al_update_binary(
                            kal_uint16 offset,
                            kal_uint8 num_bytes,
                            kal_uint8 *data_ptr,
                            kal_uint16 *status_word,
                            usim_logic_channel_enum channel,
                            sim_context_struct *this_sim);
extern sim_cmd_result_enum sim_al_read_record(
                            sim_record_access_mode_enum read_mode,
                            kal_uint8 rec_num,
                            kal_uint16 rec_size,
                            kal_uint8 *read_data_ptr,
                            kal_uint16 *status_word,
                            usim_logic_channel_enum channel,
                            sim_context_struct *this_sim);
extern sim_cmd_result_enum sim_al_update_record(
                            sim_record_access_mode_enum write_mode,
                            kal_uint8 rec_num,
                            kal_uint8 rec_size,
                            kal_uint8 *data_ptr,
                            kal_uint16 *status_word,
                            usim_logic_channel_enum channel,
                            sim_context_struct *this_sim);

#if defined(__SIM_SEARCH_RECORD_SUPPORT__)
extern sim_cmd_result_enum sim_al_search_record(
                        kal_uint8 rec_index,
                        kal_uint8 pattern_len,
                        kal_uint8 *pattern_data_ptr,        
                        kal_uint8 expected_result_data_size,                                                
                        kal_uint8 *search_result_data_size,                        
                        kal_uint8 *search_result_data_ptr,
                        kal_uint16 *status_word,
                        usim_logic_channel_enum channel,
                        sim_context_struct *this_sim);
#endif

extern sim_cmd_result_enum sim_al_run_gsm_algo(
                            kal_uint8 *rand_num_ptr,
                            kal_uint8 *kc,
                            kal_uint8 *sres,
                            kal_uint16 *status_word, 
                            sim_context_struct *this_sim);
extern sim_cmd_result_enum sim_al_seek(
                            sim_seek_type_mode_enum type_mode,
                            kal_uint8 len,
                            kal_uint8 *pattern,
                            kal_uint8 *rec_num,
                            sim_context_struct *this_sim);
extern sim_cmd_result_enum sim_al_status(
                            usim_status_opt_enum type,
                            usim_status_rsp_enum rsp_type,
                            kal_uint8 *status_data_ptr, 
                            kal_uint16 *rsp_len,
                            kal_uint16 *status_word,
                            usim_logic_channel_enum channel,
                            sim_context_struct *this_sim);
extern sim_cmd_result_enum sim_al_rehabilitate(sim_context_struct *this_sim);
extern sim_cmd_result_enum sim_al_invalidate(sim_context_struct *this_sim);
extern sim_cmd_result_enum sim_al_fetch(
                            kal_uint8 *fetch_data_ptr, 
                            kal_uint16 length, 
                            sim_context_struct *this_sim);
extern sim_cmd_result_enum sim_al_terminal_response(
                            kal_uint8 *app_cmd_rsp_ptr,
                            kal_uint8 length,
                            sim_context_struct *this_sim);
extern sim_cmd_result_enum sim_al_terminal_profile(
                            kal_uint8 *term_prfl_ptr,
                            kal_uint8 term_prfl_len,
                            sim_context_struct *this_sim);
extern sim_cmd_result_enum sim_al_envelope(
                            kal_uint8 *data_ptr,
                            kal_uint8 data_len,
                            kal_uint8 *env_rsp_ptr,
                            kal_uint16 *env_rsp_len_ptr,
                            sim_context_struct *this_sim,
                            kal_uint16 *status_word);
extern sim_cmd_result_enum sim_al_increase(
                            kal_uint8 *value_to_be_added_ptr,
                            kal_uint8 value_len,
                            kal_uint8 *value_of_record_ptr,
                            kal_uint16 *length_of_data_ptr,
                            kal_uint16 *status_word,
                            usim_logic_channel_enum channel,
                            sim_context_struct *this_sim);
extern sim_cmd_result_enum sim_al_select_id(
                            sim_file_index_enum file_idx,
                            kal_uint8 *file_id,
                            kal_uint8 *rx_data,
                            kal_uint8 *rx_size_ptr,
                            kal_uint16 *status_word,
                            sim_context_struct *this_sim);
extern void sim_al_poweroff(sim_context_struct *this_sim);
extern void sim_init_card_dependent_context(sim_context_struct * this_sim);
extern void sim_clear_recovery_ctx(sim_context_struct * this_sim);
extern void sim_clear_channel_ctx(usim_logic_channel_enum channel, sim_context_struct *this_sim);

extern kal_bool sim_is_long_path_file(sim_file_index_enum file_idx,sim_context_struct *this_sim);

#ifdef __USIM_SUPPORT__
extern sim_cmd_result_enum usim_al_select(
                            sim_file_index_enum,
                            kal_uint8 *,
                            kal_uint8 *,
                            kal_uint16 *,
                            kal_uint16 *,
                            usim_logic_channel_enum,
                            sim_context_struct *);
extern sim_cmd_result_enum usim_al_deactivate_file(
                            sim_file_index_enum,
                            kal_uint8 *,
                            kal_uint16 *,
                            usim_logic_channel_enum,
                            sim_context_struct *);
extern sim_cmd_result_enum usim_al_activate_file(
                            sim_file_index_enum,
                            kal_uint8 *,
                            kal_uint16 *,
                            usim_logic_channel_enum,
                            sim_context_struct *);
extern sim_cmd_result_enum usim_al_app_authenticate(uicc_auth_mode_enum mode,
                                                    kal_uint8 *command_data,
                                                    kal_uint8 command_len,
                                                    kal_uint8 *rsp_data_ptr,
                                                    kal_uint16 *rsp_len,
                                                    kal_uint16 *status_word,
                                                    usim_logic_channel_enum channel,
                                                    sim_context_struct *this_sim);
extern sim_cmd_result_enum usim_al_authenticate(
                            kal_uint8 *,
                            kal_uint8 *,
                            kal_uint8 *,
                            kal_uint16 *,
                            kal_uint16 *,
                            usim_logic_channel_enum,
                            sim_context_struct *);
/* [MAUI_02011291] mtk80420: Fix klocwork issue, separate usim_al_increase from sim_al_increase */
extern sim_cmd_result_enum usim_al_increase(
                            kal_uint8 * value_to_be_added_ptr, 
                            kal_uint8 value_len, 
                            kal_uint8 * value_of_record_ptr, 
                            kal_uint16 * length_of_data_ptr, 
                            kal_uint16 * status_word, 
                            usim_logic_channel_enum channel, 
                            sim_context_struct * this_sim);
extern sim_cmd_result_enum usim_al_get_challenge(
                            kal_uint8 *,
                            kal_uint16,
                            usim_logic_channel_enum,
                            sim_context_struct *);
extern sim_cmd_result_enum usim_select(
                            sim_file_index_enum,
                            kal_uint8 *,
                            kal_uint16 *,
                            usim_logic_channel_enum,
                            sim_context_struct *);
extern sim_cmd_result_enum usim_get_pin_status(
                            sim_chv_info_struct *, 
                            kal_uint16 *, 
                            uicc_app_type_enum, 
                            usim_logic_channel_enum,
                            sim_context_struct *);

extern sim_cmd_result_enum usim_al_manage_channel(
                           usim_logic_channel_enum ,
                           usim_channel_op_enum ,
                           kal_uint8 *,
                           kal_uint16 *,
                           sim_context_struct *);

extern sim_cmd_result_enum usim_select_aid(
                            kal_uint8 *,
                            kal_uint8,
                            usim_select_aid_ctrl_enum,
                            kal_uint16 *,
                            usim_logic_channel_enum,
                            sim_context_struct *);
extern sim_cmd_result_enum usim_al_read_binary_with_sfi(
                            sim_file_index_enum file_idx, 
                            kal_uint8 *path, 
                            usim_sfi_enum sfi, 
                            kal_uint8 offset, 
                            kal_uint16 num_bytes, 
                            kal_uint8 * read_data_ptr, 
                            kal_uint16 * status_word, 
                            usim_logic_channel_enum channel, 
                            sim_context_struct *this_sim);

extern void usim_terminal_capability(sim_context_struct *this_sim);

extern sim_cmd_result_enum usim_al_terminal_capability(kal_uint8 *term_capability_ptr, kal_uint8 term_capavility_len, sim_context_struct *this_sim);
#endif  /* __USIM_SUPPORT__ */

#ifdef __SIM_DBG__      /* Add to avoid compile warning - Benson 022504 */
extern void sim_dbg_print(module_type mod_id, kal_char *title, kal_uint8 *data, kal_uint16 len);
#endif 

extern sim_cmd_result_enum sim_al_fetch(kal_uint8 *fetch_data_ptr, kal_uint16 length, sim_context_struct *this_sim);
extern sim_cmd_result_enum sim_al_terminal_profile(
                            kal_uint8 *term_prfl_ptr,
                            kal_uint8 term_prfl_len,
                            sim_context_struct *this_sim);

extern kal_bool usim_fcp_query_tag(kal_uint8 *, kal_int16, usim_fcp_tag_enum, void *);
extern kal_uint8 fcp_tlv_search_tag(kal_uint8 *in_ptr, kal_int16 len, usim_fcp_tag_enum tag, kal_uint8 **out_ptr);

extern void sim_set_testsim(kal_bool is_test_sim, sim_context_struct *this_sim);

extern sim_cmd_result_enum sim_read_transparent_file(
                        sim_file_index_enum file_idx,
                        kal_uint8 **file_ptr,
                        kal_uint16 *file_size,
                        kal_uint16 *status_word,
                        sim_context_struct *this_sim);

#ifdef __ISIM_SUPPORT__  /* Tempotary use __ISIM_SUPPORT__ to wrap this function because of currently only ISIM application */
extern void sim_app_error_handler(uicc_app_type_enum app_type, usim_logic_channel_enum channel, sim_error_cause_enum cause, sim_context_struct *this_sim);
#endif

extern void sim_error_handler(sim_error_cause_enum cause, sim_context_struct * this_sim);

extern kal_bool is_simplus_detect(sim_context_struct *this_sim);

extern sim_cmd_result_enum sim_profile_download(sim_context_struct *this_sim);

extern void sim_send_msg_to_myself(
        msg_type msg_id,
        local_para_struct *local_para_ptr,
        peer_buff_struct *peer_buff_ptr,
        sim_context_struct *this_sim);

extern sim_cmd_result_enum usim_recovery_as_sim(sim_context_struct *this_sim); /*mtk01612: [MAUI_02052346]*/

/*mtk01612: [MAUI_02014578] wise detect O2 prepay SIM*/
#ifdef __SIM_O2_PREPAID_SIM_DETECT__ 
extern kal_bool is_o2_prepaid_sim_detect(sim_context_struct *this_sim);
#endif

#if defined(__SIM_MMDS_CLIENT__) || defined(__SGLTE__)
extern void sim_queue_initialization(sim_context_struct *this_sim, kal_uint8 int_qsize);
extern kal_bool sim_msg_receive_sim_queue(sim_context_struct *this_sim, ilm_struct *ilm_ptr);
extern void sim_int_wait_ext_msg(sim_context_struct *this_sim, kal_uint32 *MsgIdList, kal_uint32 MsgIdNum, ilm_struct *ilm_ptr, kal_uint32 timeout);
#endif

extern void sim_start_timer(sim_context_struct *this_sim);
extern void sim_stop_timer(sim_context_struct *this_sim);
extern void sim_send_ilm(
                module_type dest_id,
                kal_uint16 msg_id,
                void *local_param_ptr,
                void *peer_buf_ptr,
                sim_context_struct *this_sim);
extern void sim_startup_read(
                sim_cmd_result_enum ret_val,
                kal_uint8 access_id,
                kal_uint8 *pin1,
                sim_context_struct *this_sim);

#if defined(__SIM_MMDS_CLIENT__)
extern void sim_mmdc_chv_info_verified(sim_chv_info_struct *chv_info);
extern void sim_mmdc_chv_info_not_verified(sim_chv_info_struct *chv_info);
#endif

extern void sim_initialization(sim_context_struct *this_sim);

extern void sim_poll_timer_hdlr(sim_context_struct *this_sim);
//#endif /* __GEMINI__ */ 

#if (defined(__WIFI_SUPPORT__) || defined(__AGPS_USER_PLANE__)) 
extern void sim_application_ready_ind(kal_uint8 *imsi, sim_context_struct *this_sim);
#endif

extern sat_call_ctrl_type_enum sat_call_ctrl_check(
                            kal_uint8 *cmd_detail,
                            sat_call_ctrl_type_enum type,
                            kal_uint8 size_of_addr,
                            kal_uint8 *addr,
                            kal_uint8 size_of_ccp1,
                            kal_uint8 *ccp1,
                            kal_uint8 size_of_subaddr,
                            kal_uint8 *subaddr,
                            kal_uint8 *local_info,
                            kal_uint8 size_of_ccp2,
                            kal_uint8 *ccp2);
extern sat_call_ctrl_type_enum sat_sms_ctrl_check(
                            kal_uint8 *cmd_detail,
                            kal_uint8 size_of_addr1,
                            kal_uint8 *addr1,
                            kal_uint8 size_of_addr2,
                            kal_uint8 *addr2);

/* kal_bool sim_create_timer (void); */
extern void sat_check_proactive_cmd(sim_context_struct *this_sim);

extern kal_bool sat_start_timer(kal_uint8 timer_id, kal_uint8 *data, sim_context_struct *this_sim);

extern kal_uint32 sat_stop_timer(kal_uint8 timer_id, sim_context_struct *this_sim);

extern void sat_evdl_location_status(sim_context_struct *this_sim, kal_uint8 mm_status, kal_uint8 *location_info);
extern void sat_evdl_access_technology_change(sim_context_struct *this_sim, kal_uint8 rat_status);
extern void sat_evdl_nw_search_mode_change(sim_context_struct *this_sim);

extern kal_bool sim_check_card_exist(sim_context_struct *this_sim);
extern kal_bool sim_support_module(module_type src_mod_id, sim_context_struct *this_sim);

/*[MAUI_02356453] 20110123 mtk01612: sim_smu_error_ind is removed due to no need after MAUI_01815935*/

extern sim_cmd_result_enum usim_al_recovery(sim_context_struct *this_sim);
#ifdef __ISIM_SUPPORT__
extern sim_cmd_result_enum isim_al_recovery(usim_logic_channel_enum *channel, sim_context_struct *this_sim);
#endif
extern sim_cmd_result_enum sim_al_recovery(sim_context_struct *this_sim);
extern sim_cmd_result_enum usim_exception_handle(sim_context_struct *this_sim);
#ifdef __ISIM_SUPPORT__
extern sim_cmd_result_enum isim_exception_handle(usim_logic_channel_enum *channel, sim_context_struct *this_sim);
#endif
extern sim_cmd_result_enum sim_exception_handle(sim_context_struct *this_sim);

#ifdef __USIM_SUPPORT__
extern void usim_startup_read(kal_uint8 access_id, kal_uint8 *pin1, sim_context_struct *this_sim);
extern void usim_initialization(sim_context_struct *this_sim);
extern sim_cmd_result_enum usim_check_dn_type(sim_dn_enum *dn_type, sim_context_struct *this_sim);
extern sim_cmd_result_enum usim_read_iccid(kal_uint8 *iccid, kal_uint16 *status_word, sim_context_struct *this_sim);
extern sim_cmd_result_enum usim_get_aid(kal_uint16 *status_word, uicc_app_type_enum app_type, usim_logic_channel_enum channel_id, sim_context_struct *this_sim);
extern sim_cmd_result_enum usim_read_ad(kal_uint8 *ue_operation_mode,kal_uint16 *status_word ,sim_context_struct *this_sim);
#endif 

#ifdef __ISIM_SUPPORT__
extern void isim_initialization(usim_logic_channel_enum channel, sim_context_struct *this_sim);
extern void isim_startup_read(kal_uint8 access_id, kal_uint8 *pin1, usim_logic_channel_enum channel, sim_context_struct *this_sim);
#endif

extern void sim_get_dn_type(sim_dn_enum *type, sim_phase_enum phase, sim_context_struct *this_sim);

extern sim_cmd_result_enum sim_select(
                        sim_file_index_enum file_idx,
                        kal_uint8 *path,
                        kal_uint8 *select_rsp_ptr,
                        kal_uint16 *status_word,
                        sim_context_struct *this_sim);

extern sim_cmd_result_enum sim_read_service_table(sim_context_struct *this_sim);

extern sim_cmd_result_enum usim_read_service_table(kal_uint16 *status_word, sim_context_struct *this_sim);

extern void sat_evdl_location_status_retry(sim_context_struct *this_sim, kal_uint8 *envelope_data, kal_uint8 length);

extern void sat_procomm_play_tone(
                kal_uint8 *cmd_detail,
                kal_uint8 *data,
                kal_uint8 len,
                sim_context_struct *this_sim);
extern void sat_procomm_refresh(kal_uint8 *cmd_detail, kal_uint8 *data, kal_uint8 len, sim_context_struct *this_sim);
extern void sat_procomm_poll_interval(
                kal_uint8 *cmd_detail,
                kal_uint8 *data,
                kal_uint8 len,
                sim_context_struct *this_sim);
extern void sat_procomm_polling_off(
                kal_uint8 *cmd_detail,
                kal_uint8 *data,
                kal_uint8 len,
                sim_context_struct *this_sim);

extern void sat_procomm_provide_local_info(
                kal_uint8 *cmd_detail,
                kal_uint8 *data,
                kal_uint8 len,
                sim_context_struct *this_sim);

#ifdef __SAT__
extern sim_cmd_result_enum sat_timer_expiration_retry(sim_context_struct *this_sim);
extern sim_cmd_result_enum sat_envelope_retry(sim_context_struct *this_sim);
#endif 

/* extern void save_security_to_nvram(kal_uint8 src_id); */

extern void sim_al_queryspeed(sim_context_struct *this_sim);

/*[MAUI_00479434] mtk01612: csim feature*/
extern sim_cmd_result_enum sim_check_status(kal_uint16 status_word, sim_context_struct *this_sim);

#ifdef __SIM_ACCESS__
#ifdef __SAT__
extern void sat_procomm_set_up_idle_mode_text(
                kal_uint8 *cmd_detail,
                kal_uint8 *data,
                kal_uint8 len,
                sim_context_struct *this_sim);
extern void sat_procomm_setup_event_list(
                kal_uint8 *cmd_detail,
                kal_uint8 *data,
                kal_uint8 len,
                sim_context_struct *this_sim);
extern void sat_procomm_timer_management(
                kal_uint8 *cmd_detail,
                kal_uint8 *data,
                kal_uint8 len,
                sim_context_struct *this_sim);
extern void sat_procomm_run_at_command(
                kal_uint8 *cmd_detail,
                kal_uint8 *data,
                kal_uint8 len,
                sim_context_struct *this_sim);
extern void sat_procomm_send_dtmf(
                kal_uint8 *cmd_detail,
                kal_uint8 *data,
                kal_uint8 len,
                sim_context_struct *this_sim);
extern void sat_procomm_language_notification(
                kal_uint8 *cmd_detail,
                kal_uint8 *data,
                kal_uint8 len,
                sim_context_struct *this_sim);
extern void sat_procomm_launch_browser(
                kal_uint8 *cmd_detail,
                kal_uint8 *data,
                kal_uint8 len,
                sim_context_struct *this_sim);

extern void sat_procomm_send_ss(
                kal_uint8 *cmd_detail,
                kal_uint8 *data,
                kal_uint8 len,
                kal_uint8 is_type_changed,
                sim_context_struct *this_sim);
extern void sat_procomm_send_ussd(
                kal_uint8 *cmd_detail,
                kal_uint8 *data,
                kal_uint8 len,
                kal_uint8 is_type_changed,
                sim_context_struct *this_sim);
extern void sat_procomm_setup_menu(
                kal_uint8 *cmd_detail,
                kal_uint8 *data,
                kal_uint8 len,
                sim_context_struct *this_sim);
extern void sat_procomm_select_item(
                kal_uint8 *cmd_detail,
                kal_uint8 *data,
                kal_uint8 len,
                sim_context_struct *this_sim);

#endif /* __SAT__ */ 
#endif /* __SIM_ACCESS__ */ 


/* MAUI_01949579 mtk02374 20090903 for CTA GEMINI new bootup*/
extern void sim_reset_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);  //mtk02374 20090811 add for CTA new dual sim standard
extern void sim_start_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sim_app_start_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sim_run_algo_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sim_read_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sim_write_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sim_increase_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sim_security_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sim_timer_expiry_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);

#ifdef __USIM_SUPPORT__
extern void usim_update_netpar_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void usim_acl_mode_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void usim_dial_mode_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void usim_authenticate_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
#endif

extern void sim_file_info_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);

#ifdef __SIM_DUMMY_CMD__
extern void sim_seek_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
#endif

extern void sim_dial_mode_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sim_status_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sim_poweroff_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sim_read_plmn_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sim_write_plmn_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
#if defined(__SIM_MMDS_CLIENT__)
extern void sim_extmd_notify_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
#endif
extern void sim_sat_ready_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);

#ifdef __SIM_ACCESS__
extern void sim_tst_handler(ilm_struct *current_ilm, sim_context_struct *this_sim);
#endif 

#ifdef EXTERNAL_MMI
extern void sim_tst_handler(ilm_struct *current_ilm, sim_context_struct *this_sim);
#endif 

#ifdef __SIM_UNIT_TEST__
extern void sim_tst_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
#endif

#ifdef __SIM_HOT_SWAP_SUPPORT__
extern void sim_plug_out_ind_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sim_plug_in_ind_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
#endif

/*mtk01612: [MAUI_03020152] sync polling timer*/
#if defined(__GEMINI__) && defined(__SIM_SYNC_POLL_TIMER__)
extern void sim_sync_poll_timer_ind_handler( ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
#endif		

#ifdef __SIM_RECOVERY_ENHANCEMENT__
extern void sim_recovery_enhancement_switch_req_handler(ilm_struct * sim_ilm_ptr, sim_context_struct * this_sim);
#endif

#ifdef __SAT__
extern void sat_proactive_cmd_handler(ilm_struct * ilm_ptr, sim_context_struct * this_sim);
extern void sat_proactive_cmd_process(sim_context_struct *this_sim);
extern void sat_file_change_ind_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_more_time_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_dspl_text_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_get_inkey_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_get_input_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_play_tone_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_setup_menu_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_select_item_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_send_sms_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_send_ss_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_send_ussd_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_setup_call_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_call_status_ind_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_sms_dl_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_cb_dl_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_menu_select_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_call_ctrl_by_sim_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_send_sms_ctrl_by_sim_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_file_change_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_provide_local_information_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void update_first_time_location_info_via_event_download(sim_context_struct *this_sim);
extern void sat_pdp_status_ind_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_reissue_refresh_handler(kal_uint8 *cmd_detail, kal_uint8 *data, kal_uint8 len, sim_context_struct *this_sim);

/* Remote SAT */
extern void rsat_envelope_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void rsat_terminal_rsp_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
#if 0  //andrew 20081205 RSAT don't do profile_download
/* under construction !*/
#endif
/* End Remote SAT */

extern void sat_set_up_idle_mode_text_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);

#ifdef __SATCB__
extern void sat_run_at_command_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
#endif

extern void sat_send_dtmf_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_language_notification_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);

#ifdef __SATCC__
extern void sat_launch_browser_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_evdl_browser_termination_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
#endif

extern void sat_evdl_mt_call_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_evdl_call_connect_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_evdl_call_disconnect_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_evdl_user_activity_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_evdl_idle_screen_available_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_evdl_language_selection_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);

#ifdef __SATCA__  
extern void sat_evdl_card_reader_status_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
#endif

extern void sat_evdl_access_technology_change_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);     /* mtk01488 */
#endif /* __SAT__ */ 

#ifdef __SATCE__
extern void sat_evdl_data_available_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_evdl_channel_status_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_open_gprs_channel_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_open_csd_channel_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_open_server_mode_channel_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_close_channel_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_send_data_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_recv_data_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sat_ch_status_res_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
#endif

extern void sat_activate_res_handler(ilm_struct *ilm, sim_context_struct *this_sim);

extern void sat_evdl_hci_connectivity_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);

extern void sat_evdl_network_reject_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);

/* __SATCR__*/
extern void sat_contactless_state_changed_res_handler(ilm_struct *ilm, sim_context_struct *this_sim);

#ifdef __BT_SIM_PROFILE__
extern void bt_sim_connect_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void bt_sim_reset_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void bt_sim_apdu_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void bt_sim_disconnect_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void bt_sim_power_off_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void bt_sim_power_on_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim); /*mtk01612: [MAUI_02356228]*/ 
#endif 

#ifdef __GSMCDMA_DUALSIM__
extern void l4c_sim_get_gsmcdma_dualsim_info_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void l4c_sim_set_gsmcdma_dualsim_mode_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
#endif 

extern void sim_error_ind_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);

#ifdef __VSIM__
extern void l4c_sim_set_vsim_mode_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
#endif

extern void sim_apdu_access_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);

#if defined(__USIM_SUPPORT__)
extern void sim_manage_channel_req_handler(ilm_struct * sim_ilm_ptr,sim_context_struct * this_sim);
#endif

#ifdef __SIM_UT__
extern void sim_error_test_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
#endif

extern void sim_query_info_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sim_get_atr(kal_uint8 *length, kal_uint8 *atr, sim_context_struct *this_sim);

extern void sim_terminal_capability_setting_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);

extern void sim_read_imsi_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);

#ifdef __SGLTE__
extern void sim_intsim_access_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);    
extern void sim_intsim_notify_ind_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);    
extern void sim_intsim_security_ind_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sim_intsim_dial_mode_change_ind_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
#ifdef __SGLTE_DSDS__
extern kal_uint8 sim_get_actual_sim_slot_id(kal_uint8 sim_idx);
extern kal_uint8 sim_get_switched_sim_protocol_id(kal_uint8 sim_idx);
#endif
#endif

extern kal_bool sim_is_uicc_card(usim_logic_channel_enum channel, kal_uint8 simInterface);

#ifdef __SIM_JSR177_APDU__ 
extern void sim_jsr177_apdu_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
extern void sim_jsr177_atr_req_handler(ilm_struct *sim_ilm_ptr, sim_context_struct *this_sim);
#endif 

extern DCL_STATUS sim_driver_reset_api(DCL_SIM_POWER ExpectVolt, DCL_SIM_POWER * ResultVolt_ptr, kal_bool warm, DCL_SIM_STATUS * RstResult_ptr, sim_context_struct *this_sim);
extern DCL_STATUS sim_driver_cmd_api(kal_uint8 *txData_ptr, kal_uint32 *txSize_ptr, kal_uint8 *rxData_ptr, kal_uint32 *rxSize_ptr, kal_uint16 *statusWord_ptr, sim_context_struct *this_sim);
extern DCL_STATUS sim_driver_get_card_info_api(DCL_SIM_INFO *info_ptr, sim_context_struct *this_sim);
extern DCL_STATUS sim_driver_set_clk_stop_mode_api(DCL_SIM_CLK_STOP mode, sim_context_struct *this_sim);
extern DCL_STATUS sim_driver_poweroff_api(sim_context_struct *this_sim);
extern DCL_STATUS sim_driver_get_speed_api(DCL_SIM_CARD_SPEED *speed_ptr, sim_context_struct *this_sim);
extern DCL_STATUS sim_driver_query_9000OnSelect_api(DCL_BOOL *got9000_ptr, sim_context_struct *this_sim);

#ifdef IC_MODULE_TEST 
extern DCL_STATUS sim_driver_set_slt_rlt_api(DCL_BOOL rlt, sim_context_struct *this_sim);
#endif

#if (!defined(__MTK_TARGET__) && defined(__SIM_UNIT_TEST__))
extern DCL_STATUS sim_driver_ut_reset_uicc_status_api(sim_context_struct *this_sim);
extern DCL_STATUS sim_driver_ut_reset_pin_cnr_api(kal_bool pin1_enabled, kal_bool pin2_enabled, sim_context_struct *this_sim);
extern DCL_STATUS sim_driver_ut_reset_chv_cnr_api(kal_bool pin1_enabled, sim_context_struct *this_sim);
extern kal_bool   is_sim_card_replaced(sim_context_struct *this_sim );
#endif

#ifdef __SIM_HOT_SWAP_SUPPORT__
extern void sim_process_plug_out(sim_context_struct * this_sim);
extern void sim_plug_out_call_back(kal_uint32 which_sim);
extern void sim_plug_in_call_back(kal_uint32 which_sim);
#endif

/*mtk01612: [MAUI_03020152] sync polling timer*/
#if defined(__GEMINI__) && defined(__SIM_SYNC_POLL_TIMER__)
extern void sim_sync_poll_timer_handle(sim_context_struct *this_sim);
#endif

extern sim_file_index_enum sim_get_grand_parent_file_idx(sim_file_index_enum file_index);

#ifdef __MINI_LOG_SUPPORT__
extern kal_uint32 sim_mini_log_callback(char* dst_buf, kal_uint32 bytes);
#endif

extern void sim_sat_mmdc_cs_send_ilm(module_type dest_id, kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr, sim_context_struct *this_sim);

extern kal_bool sim_sat_mmdc_msg_handler(kal_uint8 sim_indx, ilm_struct *ilm_ptr);

extern void sim_hot_swap_poll_timer_rollback(kal_uint32 which_sim);

extern void sim_hot_swap_poll_timer_set(kal_uint32 which_sim);

#define SIM_EF_INFO(sim_file_index_enum, X)  sim_ef_info[sim_file_index_enum].X

#define SIM_QUERY_SST(n) ((this_sim->sim_sst[(n-1)/4]&(0x03<<(((n-1)%4)*2)))==(0x03<<(((n-1)%4)*2)))\
      ? KAL_TRUE:KAL_FALSE
      
#define SIM_TIMER_CONTEXT_FIELD(X) (this_sim->sim_timer_context.X)
             
#define USIM_CH_PTR(channel)  (&(this_sim->uicc_ch_info[channel]))
#define USIM_CURRENT_FILE(channel)  (this_sim->uicc_ch_info[channel].sim_current_file_idx)
#define USIM_CURRENT_DF(channel)    (this_sim->uicc_ch_info[channel].sim_current_df_idx)
#define USIM_CURRENT_DF_ID(channel)    (this_sim->uicc_ch_info[channel].sim_current_df_file_id) // __CSIM__
#define USIM_CURRENT_PATH(channel) (this_sim->uicc_ch_info[channel].uicc_current_path)
#define USIM_CURRENT_FILE_SIZE(channel) (this_sim->uicc_ch_info[channel].file_size)
#define USIM_CURRENT_FILE_TYPE(channel) (this_sim->uicc_ch_info[channel].file_type)
#define USIM_CURRENT_REC_SIZE(channel)  (this_sim->uicc_ch_info[channel].rec_size)
#define USIM_CURRENT_NUM_OF_REC(channel) (this_sim->uicc_ch_info[channel].rec_num)
#define USIM_RX_BUFF_PTR (&(this_sim->rx_tmp_buff))

#ifdef __USIM_SUPPORT__
#define USIM_CURRENT_FD(channel) (this_sim->uicc_ch_info[channel].file_descriptor)

/* Service Table Query Macro */
#define USIM_UST_MASK(x) (0x01 << ((x-1)%8))

#define USIM_QUERY_UST(n)  (((this_sim->usim.ust[((n-SERVICE_END)-1)/8] & USIM_UST_MASK(n-SERVICE_END)) == \
                           USIM_UST_MASK(n-SERVICE_END)) ? KAL_TRUE:KAL_FALSE)

#define USIM_QUERY_EST(n)  (((this_sim->usim.est[(n-1)/8] & USIM_UST_MASK(n)) == \
                           USIM_UST_MASK(n)) ? KAL_TRUE:KAL_FALSE)
#endif

/* USIM proprietary information */
#define SET_PROP_UICC_CHAR_EXIST(X)        ((X) |= 0x01)
#define SET_PROP_APP_PWR_EXIST(X)           ((X) |= 0x02)
#define SET_PROP_MIN_APP_CLK_EXIST(X)    ((X) |= 0x04)
#define SET_PROP_AVAIL_MEM_EXIST(X)       ((X) |= 0x08)
#define SET_PROP_SUPPORTED_SYS_CMD_EXIST(X)       ((X) |= 0x10)

#define IF_PROP_UICC_CHAR_EXIST(X)      ((X)&0x01)
#define IF_PROP_APP_PWR_EXIST(X)         ((X)&0x02)
#define IF_PROP_MIN_APP_CLK_EXIST(X)  ((X)&0x04)
#define IF_PROP_AVAIL_MEM_EXIST(X)      ((X)&0x08)
#define IF_SUPPORTED_SYS_CMD_EXIST(X)      ((X)&0x10)

/* File descriptor byte */
#define IS_SHAREABLE_FILE(X) (0x40 & (X))
#define IS_DF_ADF(X)    (((0x38 & (X)) == 0x38) ? KAL_TRUE : KAL_FALSE)
#define IS_TRANSPARENT_EF(X) (((0x07 & (X)) == 0x01) ? KAL_TRUE : KAL_FALSE)
#define IS_LINEAR_FIXED_EF(X) (((0x07 & (X)) == 0x02) ? KAL_TRUE : KAL_FALSE)
#define IS_CYCLIC_EF(X) (((0x07 & (X)) == 0x06) ? KAL_TRUE : KAL_FALSE)
#define IS_BER_TLV_EF(X) (((0x3F & (X)) == 0x39) ? KAL_TRUE : KAL_FALSE)

#define __SIM_TRACE_ON__

#ifdef __SIM_TRACE_ON__
#define SIM_FUNC_ENTRY(X)     kal_trace(TRACE_FUNC, X)
#define SIM_STATE_ENTRY(X)    kal_brief_trace(TRACE_STATE, X)
#define SIM_INFO_ENTRY(X,Y,Z) kal_brief_trace(TRACE_INFO, X, Y, Z)
#define SIM_WARNING_ENTRY(X)  kal_brief_trace(TRACE_WARNING, X)
#define SIM_ERROR_ENTRY(X)    kal_brief_trace(TRACE_ERROR, X)
#define SIM_TIMING_ENTRY(X)   kal_trace(TRACE_GROUP_1, X)
#define SIM_GROUP2_ENTRY(X)        kal_brief_trace(TRACE_GROUP_2, X)
#else
#define SIM_FUNC_ENTRY(X)
#define SIM_STATE_ENTRY(X)
#define SIM_INFO_ENTRY(X,Y,Z)
#define SIM_WARNING_ENTRY(X)
#define SIM_ERROR_ENTRY(X)
#define SIM_TIMING_ENTRY(X)
#define SIM_GROUP2_ENTRY(X)
#endif

/* The following is macro definition about MCD */
#define SIM_MCD_PACK(STRUCTID, PEER_MSG, PEER_BUFF, this_sim) \
   sim_mcd_pack(STRUCTID,                                     \
               (kal_uint8*)PEER_MSG,                          \
               PEER_BUFF, this_sim);

#ifdef __SATCE__
#define SIM_MCD_UNPACK(UNPACK_FUNC, STRUCTID, STRUCT, MSG_PTR, PEER_BUFF, this_SIM) { \
   MSG_PTR = (STRUCT*)this_sim->sat.sim_pun_buff;                                         \
   sim_mcd_unpack(STRUCTID, PEER_BUFF, this_SIM); }
#endif

#if defined(__SIM_MMDS_CLIENT__)|| defined(__SGLTE__)
#define sim_wait_ext_msg(this_sim, msg_id, ilm_ptr) \
{ \
    kal_uint32 MsgId; \
    MsgId = msg_id; \
    sim_int_wait_ext_msg(this_sim, &MsgId, 1, ilm_ptr, 0xFFFFFFFF); \
}

#define sim_wait_ext_msg_with_timeout(this_sim, msg_id, ilm_ptr, timeout) \
{ \
    kal_uint32 MsgId; \
    MsgId = msg_id; \
    sim_int_wait_ext_msg(this_sim, &MsgId, 1, ilm_ptr, timeout); \
}

#define sim_wait_multi_ext_msg(this_sim, msg_id_list, msg_id_num, ilm_ptr) \
{\
    sim_int_wait_ext_msg(this_sim, msg_id_list, msg_id_num, ilm_ptr, 0xFFFFFFFF);\
}

#define sim_wait_multi_ext_msg_with_timeout(this_sim, msg_id_list, msg_id_num, ilm_ptr, timeout) \
{ \
    sim_int_wait_ext_msg(this_sim, msg_id_list, msg_id_num, ilm_ptr, timeout); \
}
#endif

#endif
