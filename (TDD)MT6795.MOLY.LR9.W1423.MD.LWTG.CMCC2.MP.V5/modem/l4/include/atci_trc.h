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
 * ATCI_TRC.H
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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


#ifndef _ATCI_TRC_H
#define _ATCI_TRC_H
//__GATI_ENABLE__

#ifndef GEN_FOR_PC

   #ifndef _STACK_CONFIG_H
   #error "stack_config.h should be included before tst_config.h"
   #endif

#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */


#ifndef _KAL_TRACE_H
   #error "kal_trace.h should be included before tst_trace.h"
#endif

#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_trace.h"

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "atci_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_ATCI)

   /* -------------------------------------------TRACE_FUNC trace class------------------------------------------- */

   /* gati */
   TRC_MSG(FUNC_GATI_DATA_REQ_HDLR, "gati_data_req_hdlr()")
   TRC_MSG(FUNC_GATI_DATA_RSP_HDLR, "gati_data_rsp_hdlr")
   TRC_MSG(FUNC_GATI_CTRL_REQ_HDLR, "gati_ctrl_req_hdlr()")
   TRC_MSG(FUNC_GATI_SWITCH_MODE_REQ_HDLR, "gati_switch_mode_req_hdlr()")
   TRC_MSG(FUNC_GATI_SUSPEND_READ_FROM_UART, "gati_suspend_read_from_uart()")   
   TRC_MSG(FUNC_GATI_SEND_DATA_CNF, "gati_send_data_cnf()")
   TRC_MSG(FUNC_GATI_REGISTER_MODULE, "gati_register_module()")
   TRC_MSG(FUNC_GATI_SEND_DATA_IND, "gati_send_data_ind()")
   TRC_MSG(FUNC_GATI_SEND_RTW_IND, "gati_send_rtw_ind()")
   TRC_MSG(FUNC_GATI_SEND_ILM, "gati_send_ilm()")
   TRC_MSG(FUNC_GATI_FLUSH_BUFFER, "gati_flush_buffer()")
   TRC_MSG(FUNC_GATI_INSERT_DATA_TO_BUFFER, "gati_insert_data_to_buffer()")
   TRC_MSG(FUNC_GATI_SEARCH_MOD_INDEX, "gati_search_mod_index()")
   TRC_MSG(FUNC_GATI_SEARCH_COMMAND, "gati_search_command()")
   TRC_MSG(FUNC_GATI_COMMAND_HDLR, "gati_command_hdlr()")
   TRC_MSG(FUNC_GATI_SEND_CTRL_CNF, "gati_send_ctrl_cnf()")
   TRC_MSG(FUNC_GATI_SEND_SWITCH_MODE_CNF, "gati_send_switch_mode_cnf()")
   TRC_MSG(FUNC_RMMI_NVRAM_READ_CNF_HDLR_ENTRY, "rmmi_nvram_read_cnf_hdlr()") 
   TRC_MSG(FUNC_GAS_REGISTER_MODULE, "gas_register_module()")
   TRC_MSG(FUNC_GAS_SEND_DATA_IND, "gas_send_data_ind()")
   TRC_MSG(FUNC_GAS_SEND_ILM, "gas_send_ilm()")
   TRC_MSG(FUNC_GAS_SEARCH_MOD_INDEX, "gas_search_mod_index()")
   TRC_MSG(FUNC_GAS_SEARCH_COMMAND, "gas_search_command()")
   TRC_MSG(FUNC_GAS_COMMAND_HDLR, "gas_command_hdlr()")
   TRC_MSG(FUNC_GAS_DATA_REQ_HDLR, "gas_data_req_hdlr()")
   TRC_MSG(FUNC_GAS_DATA_RSP_HDLR, "gas_data_rsp_hdlr")

   /* parser */
   TRC_MSG(FUNC_RMMI_CMD_PROCESSOR_ENTRY, "rmmi_cmd_processor()")
   TRC_MSG(FUNC_RMMI_PROCESS_MULTI_CMD_ENTRY, "rmmi_process_multi_cmd()")
   TRC_MSG(FUNC_RMMI_FIND_CMD_CLASS_ENTRY, "rmmi_find_cmd_class()")
   TRC_MSG(FUNC_RMMI_BASIC_CMD_PROCESSOR_ENTRY, "rmmi_basic_cmd_processor()")
   TRC_MSG(FUNC_RMMI_EXTENDED_CMD_PROCESSOR_ENTRY, "rmmi_extended_cmd_processor()")
   TRC_MSG(FUNC_RMMI_EXTENDED_COMMAND_ANALYZER_ENTRY, "rmmi_extended_command_analyzer()")
   TRC_MSG(FUNC_RMMI_BASIC_COMMAND_ANALYZER_ENTRY, "rmmi_basic_command_analyzer()")
   TRC_MSG(FUNC_RMMI_PROCESS_ONE_CMD_ENTRY, "rmmi_process_one_cmd()")
   TRC_MSG(FUNC_RMMI_AGPS_COMMAND_ANALYZER_ENTRY, "rmmi_agps_command_analyzer()")
   
   /*rsp*/
   TRC_MSG(FUNC_L4C_CC_CALL_METER_RIND_ENTRY, "l4c_cc_call_meter_rind()")
   TRC_MSG(FUNC_L4C_CC_CALL_WAIT_RIND_ENTRY, "l4c_cc_call_wait_rind()")
   TRC_MSG(FUNC_L4C_CC_CALL_RING_RIND_ENTRY, "l4c_cc_call_ring_rind()")
   TRC_MSG(FUNC_L4C_CC_CALL_RELEASE_RIND_ENTRY, "l4c_cc_call_release_rind()")
   TRC_MSG(FUNC_L4C_CC_CALL_MODIFY_RIND_ENTRY, "l4c_cc_call_modify_rind()")
   TRC_MSG(FUNC_L4C_CC_CALL_CONNECT_RIND_ENTRY, "l4c_cc_call_connect_rind()")
   TRC_MSG(FUNC_L4C_SS_USSR_RIND_ENTRY, "l4c_ss_ussr_rind()")
   TRC_MSG(FUNC_L4C_SS_USSN_RIND_ENTRY, "l4c_ss_ussn_rind()")
   TRC_MSG(FUNC_L4C_PS_CONNECT_RIND_ENTRY, "l4c_ps_connect_rind()")
   TRC_MSG(FUNC_L4C_PS_ACTIVATE_RIND_ENTRY, "l4c_ps_activate_rind()")
   TRC_MSG(FUNC_L4C_NW_REG_STATE_RIND_ENTRY, "l4c_nw_reg_state_rind()")
   TRC_MSG(FUNC_L4C_NW_TIME_ZONE_RIND_ENTRY, "l4c_nw_time_zone_rind()")
   TRC_MSG(FUNC_L4C_SMS_NEW_MSG_INDEX_RIND_ENTRY, "l4c_sms_new_msg_index_rind()")
   TRC_MSG(FUNC_L4C_SMS_NEW_MSG_TEXT_RIND_ENTRY, "l4c_sms_new_msg_text_rind()")
   TRC_MSG(FUNC_L4C_SMS_NEW_MSG_PDU_RIND_ENTRY, "l4c_sms_new_msg_pdu_rind()")
   TRC_MSG(FUNC_L4C_GENERAL_RRSP_ENTRY, "l4c_general_rrsp()")
   TRC_MSG(FUNC_L4C_CC_EXE_HANGUP_ACTIVE_CALL_RRSP_ENTRY, "l4c_cc_exe_hangup_active_call_rrsp()")
   TRC_MSG(FUNC_L4C_CC_GET_CALL_LIST_RRSP_ENTRY, "l4c_cc_get_call_list_rrsp()")
   TRC_MSG(FUNC_L4C_CC_EXE_CALL_ACCEPT_RRSP_ENTRY, "l4c_cc_exe_call_accept_rrsp()")
   TRC_MSG(FUNC_L4C_CC_EXE_CALL_SETUP_RRSP_ENTRY, "l4c_cc_exe_call_setup_rrsp()")
   TRC_MSG(FUNC_L4C_CC_EXE_CALL_MODIFY_RRSP_ENTRY, "l4c_cc_exe_call_modify_rrsp()")
   TRC_MSG(FUNC_L4C_DF_EXE_BACK_DATA_STATE_RRSP_ENTRY, "l4c_df_exe_back_data_state_rrsp()")
   TRC_MSG(FUNC_L4C_SS_EXE_EMLPP_RRSP_ENTRY, "l4c_ss_exe_emlpp_rrsp()")
   TRC_MSG(FUNC_L4C_SS_EXE_CALL_FORWARD_RRSP_ENTRY, "l4c_ss_exe_call_forward_rrsp()")
   TRC_MSG(FUNC_L4C_SS_EXE_CALL_WAIT_RRSP_ENTRY, "l4c_ss_exe_call_wait_rrsp()")
   TRC_MSG(FUNC_L4C_SS_EXE_CDIP_INTERROGATE_RRSP_ENTRY, "l4c_ss_exe_cdip_interrogate_rrsp()")
   TRC_MSG(FUNC_L4C_SS_EXE_CLIP_INTERROGATE_RRSP_ENTRY, "l4c_ss_exe_clip_interrogate_rrsp()")
   TRC_MSG(FUNC_L4C_SS_EXE_CLIR_INTERROGATE_RRSP_ENTRY, "l4c_ss_exe_clir_interrogate_rrsp()")
   TRC_MSG(FUNC_L4C_SS_EXE_CNAP_INTERROGATE_RRSP_ENTRY, "l4c_ss_exe_cnap_interrogate_rrsp()")
   TRC_MSG(FUNC_L4C_SS_EXE_COLP_INTERROGATE_RRSP_ENTRY, "l4c_ss_exe_colp_interrogate_rrsp()")
   TRC_MSG(FUNC_L4C_SS_EXE_CALL_BARRING_RRSP_ENTRY, "l4c_ss_exe_call_barring_rrsp()")
   TRC_MSG(FUNC_L4C_NW_GET_PLMN_LIST_RRSP_ENTRY, "l4c_nw_get_plmn_list_rrsp()")
   TRC_MSG(FUNC_L4C_PHB_GET_ENTRY_RRSP_ENTRY, "l4c_phb_get_entry_rrsp()")
   TRC_MSG(FUNC_L4C_SMU_EXE_RESTRICTED_ACCESS_RRSP_ENTRY, "l4c_smu_exe_restricted_access_rrsp()")
   TRC_MSG(FUNC_L4C_SMU_WRITE_SIM_RRSP_ENTRY,"l4c_smu_write_sim_rrsp()")/* mtk00468 add for CSIM */
   TRC_MSG(FUNC_L4C_SMU_EXE_DIAL_MODE_RRSP_ENTRY, "l4c_smu_exe_dial_mode_rrsp()")/*mtk00468 add for CSIMD response*/
   TRC_MSG(FUNC_L4C_SMU_GET_SHARED_KEY_RRSP_ENTRY, "l4c_smu_get_shared_key_rrsp()")
   TRC_MSG(FUNC_L4C_SMU_GET_SLB_VERSION_RRSP_ENTRY, "l4c_smu_get_slb_version_rrsp()")
   TRC_MSG(FUNC_L4C_SMU_SML_STATUS_RRSP_ENTRY, "l4c_smu_sml_status_rrsp()")
   TRC_MSG(FUNC_L4C_SMS_EXE_SEND_RRSP_ENTRY, "l4c_sms_exe_send_rrsp()")
   TRC_MSG(FUNC_L4C_SMS_EXE_READ_MSG_LIST_RRSP_ENTRY, "l4c_sms_exe_read_msg_list_rrsp()")
   TRC_MSG(FUNC_L4C_SMS_EXE_READ_MSG_RRSP_ENTRY, "l4c_sms_exe_read_msg_rrsp()")
   TRC_MSG(FUNC_L4C_SMS_EXE_READ_MSG_LIST_PDU_RRSP_ENTRY, "l4c_sms_exe_read_msg_list_pdu_rrsp()")
   TRC_MSG(FUNC_L4C_SMS_EXE_EMGL_LIST_RRSP_ENTRY, "l4c_sms_exe_emgl_list_rrsp()")
   TRC_MSG(FUNC_L4C_SMS_EXE_READ_MSG_PDU_RRSP_ENTRY, "l4c_sms_exe_read_msg_pdu_rrsp()")
   TRC_MSG(FUNC_L4C_SMS_EXE_WRITE_MSG_RRSP_ENTRY, "l4c_sms_exe_write_msg_rrsp()")
   TRC_MSG(FUNC_L4C_SMS_SET_PREFERRED_MEM_RRSP_ENTRY, "l4c_sms_set_preferred_mem_rrsp()")
   TRC_MSG(FUNC_L4C_EQ_WRITE_NVRAM_RRSP_ENTRY, "l4c_eq_write_nvram_rrsp()")
   TRC_MSG(FUNC_L4C_EQ_READ_NVRM_RRSP_ENTRY, "l4c_eq_read_nvram_rrsp()")
   TRC_MSG(FUNC_L4C_SMS_EXE_IMS_SEND_RRSP_ENTRY, "l4c_sms_exe_ims_send_rrsp()")
   /* fmttr*/
   TRC_MSG(FUNC_RMMI_CSIM_ERROR_RSP_FMTTR_ENTRY, "rmmi_csim_error_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_CNVRM_ERROR_RSP_FMTTR_ENTRY, "rmmi_cnvrm_error_rsp_fmttr()") 
   TRC_MSG(FUNC_RMMI_RESULT_CODE_FMTTR_ENTRY, "rmmi_result_code_fmttr()")
   TRC_MSG(FUNC_RMMI_CLCC_READ_RSP_FMTTR_ENTRY, "rmmi_clcc_read_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_CAEMLPP_READ_RSP_FMTTR_ENTRY, "rmmi_caemlpp_read_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_CCFC_INTERROGATE_RSP_FMTTR_ENTRY, "rmmi_ccfc_interrogate_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_CCWA_INTERROGATE_RSP_FMTTR_ENTRY, "rmmi_ccwa_interrogate_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_CDIP_READ_RSP_FMTTR_ENTRY, "rmmi_cdip_read_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_CLIP_READ_RSP_FMTTR_ENTRY, "rmmi_clip_read_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_CLIR_READ_RSP_FMTTR_ENTRY, "rmmi_clir_read_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_CNAP_READ_RSP_FMTTR_ENTRY, "rmmi_cnap_read_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_COLP_READ_RSP_FMTTR_ENTRY, "rmmi_colp_read_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_CLCK_INTERROGATE_RSP_FMTTR_ENTRY, "rmmi_clck_interrogate_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_CRSM_EXE_RSP_FMTTR_ENTRY, "rmmi_crsm_exe_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_COPS_TEST_RSP_FMTTR_ENTRY, "rmmi_cops_test_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_PHB_ENTRY_RSP_FMTTR_ENTRY, "rmmi_phb_entry_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_PHB_MSISDN_RSP_FMTTR_ENTRY, "rmmi_phb_msisdn_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_SMS_SEND_RSP_FMTTR_ENTRY, "rmmi_sms_send_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_SMS_LIST_RSP_FMTTR_ENTRY, "rmmi_sms_list_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_SMS_READ_RSP_FMTTR_ENTRY, "rmmi_sms_read_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_SMS_WRITE_RSP_FMTTR_ENTRY, "rmmi_sms_write_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_SMS_STORAGE_RSP_FMTTR_ENTRY, "rmmi_sms_storage_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_FAST_STRING_PRINT_ENTRY, "rmmi_fast_string_print()")
   TRC_MSG(FUNC_RMMI_SMS_IMS_SEND_RSP_FMTTR_ENTRY, "rmmi_sms_ims_send_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_SMS_IMS_RECV_IND_FMTTR_ENTRY, "rmmi_sms_ims_recv_ind_fmttr()")
   TRC_MSG(FUNC_RMMI_SMS_IMS_SMMA_RSP_FMTTR_ENTRY, "rmmi_sms_ims_smma_rsp_fmttr()")
   TRC_MSG(FUNC_RMMI_SMS_IMS_SMMA_IND_FMTTR_ENTRY, "rmmi_sms_ims_smma_ind_fmttr()")
   
   /* utility */
   TRC_MSG(FUNC_RMMI_INT_TO_ASCII_CONVERTER_ENTRY, "rmmi_int_to_ascii_converter()")
   TRC_MSG(FUNC_RMMI_INT_VALIDATOR_ENTRY, "rmmi_int_validator()")
   TRC_MSG(FUNC_CHECK_CHLD_OPCODE_ENTRY, "check_chld_opcode()")
   TRC_MSG(FUNC_CHECK_PHB_STORAGE_NAME_ENTRY, "check_phb_storage_name()")
   TRC_MSG(FUNC_CHECK_PHB_STORAGE_CODE_ENTRY, "check_phb_storage_code()")
   TRC_MSG(FUNC_CHECK_DCS_TOGSM7BIT_ENTRY, "check_dcs_toGsm7bit()")
   TRC_MSG(FUNC_CHECK_DCS_TOCSCS_ENTRY, "check_dcs_toCscs()")
   TRC_MSG(FUNC_CHECK_SMS_STORAGE_NAME_ENTRY, "check_sms_storage_name()")
   TRC_MSG(FUNC_CHECK_SMS_STORAGE_CODE_ENTRY, "check_sms_storage_code()")
   TRC_MSG(FUNC_CHECK_SMS_SCTS_ENTRY, "check_sms_scts()")
   TRC_MSG(FUNC_CHECK_FACILITY_TYPE_ENTRY, "check_facility_type()")
   TRC_MSG(FUNC_CHECK_PIN_NAME_ENTRY, "check_pin_name()")
   TRC_MSG(FUNC_CHECK_PPU_VALUE_ENTRY, "check_ppu_value()")
   TRC_MSG(FUNC_CHECK_PPU_STRING_ENTRY, "check_ppu_string()")
   TRC_MSG(FUNC_PARSE_INT_LIST_ENTRY, "parse_int_list()")
   TRC_MSG(FUNC_CHECK_CHAR_SET_NAME_ENTRY, "check_char_set_name()")
   TRC_MSG(FUNC_CHECK_CHAR_SET_CODE_ENTRY, "check_char_set_code()")
   TRC_MSG(FUNC_CHECK_KEYPAD_CODE_ENTRY, "check_keypad_code()")
   TRC_MSG(FUNC_CHECK_PDP_TYPE_NAME_ENTRY, "check_pdp_type_name()")
   TRC_MSG(FUNC_CHECK_PDP_TYPE_CODE_ENTRY, "check_pdp_type_code()")
   TRC_MSG(FUNC_CHECK_DOTTED_VALUE8_ENTRY, "check_dotted_value8()")
   TRC_MSG(FUNC_CHECK_DOTTED_VALUE16_ENTRY, "check_dotted_value16()")
   TRC_MSG(FUNC_CHECK_DOTTED_STRING8_ENTRY, "check_dotted_string8()")
   TRC_MSG(FUNC_CHECK_DOTTED_STRING16_ENTRY, "check_dotted_string16()")
   TRC_MSG(FUNC_CHECK_HEX_VALUE_ENTRY, "check_hex_value()")
   TRC_MSG(FUNC_CHECK_SMS_PDU_STRING_ENTRY, "check_sms_pdu_string()")
   TRC_MSG(FUNC_RMMI_FIND_CMD_MODE_ENTRY, "rmmi_find_cmd_mode()")
   TRC_MSG(FUNC_RMMI_STRING_VALIDATOR_ENTRY, "rmmi_string_validator()")
   TRC_MSG(FUNC_RMMI_SMS_TEXT_VALIDATOR_ENTRY, "rmmi_sms_text_validator()")
   TRC_MSG(FUNC_EXTRACT_NUMBER_ENTRY, "extract_number()")
   TRC_MSG(FUNC_RMMI_SKIP_LEADING_CHARS_ENTRY, "rmmi_skip_leading_chars()")
   TRC_MSG(FUNC_EXTRACT_NUMBER_STRING_ENTRY, "extract_number_string()")
   TRC_MSG(FUNC_IS_SMS_MSG_CMD_ENTRY, "is_sms_msg_cmd()")
   TRC_MSG(FUNC_IS_SMS_STD_CMD_ENTRY, "is_sms_standard_command()")
   TRC_MSG(FUNC_IS_SMS_MODE_CORRECT_ENTRY, "is_sms_mode_correct()")
   TRC_MSG(FUNC_RTC_TO_STRING_FORMAT_ENTRY, "rtc_to_string_format()")
   TRC_MSG(FUNC_STRING_TO_RTC_FORMAT_ENTRY, "string_to_rtc_format()")
   TRC_MSG(FUNC_TOUPPER_ENTRY, "toUpper()")
   TRC_MSG(FUNC_PRINT_HEX_VALUE_ENTRY, "print_hex_value()")
   TRC_MSG(FUNC_RMMI_EINT0_HDLR_ENTRY, "[DUAL TALK] rmmi_eint0_hdlr()")
   TRC_MSG(FUNC_RMMI_WAKEUP_TIMEOUT_HDLR,"[DUAL TALK] rmmi_wakeup_timeout_hdlr(),type:%Mrmmi_wakeup_type_enum")
   
   /* uart */
   TRC_MSG(FUNC_RMMI_UART_RTW_IND_HDLR_ENTRY, "rmmi_uart_rtw_ind_hdlr()")
   TRC_MSG(FUNC_RMMI_UART_RTR_IND_HDLR_ENTRY, "rmmi_uart_rtr_ind_hdlr()")
   TRC_MSG(FUNC_RMMI_UART_SEND_DATA_ENTRY, "rmmi_uart_send_data()")
   TRC_MSG(FUNC_RMMI_UART_READ_DATA_ENTRY, "rmmi_uart_read_data()")
   TRC_MSG(FUNC_RMMI_READ_FROM_UART_ENTRY, "rmmi_read_from_uart()")
   TRC_MSG(FUNC_RMMI_WRITE_TO_UART_ENTRY, "rmmi_write_to_uart()")

   /* sat */
   TRC_MSG(FUNC_RMMI_SEND_TO_SAT_ENTRY, "rmmi_rsp_to_SAT()")
   TRC_MSG(FUNC_L4C_SAT_ENVELOPE_RRSP_ENTRY, "l4c_sat_envelope_rrsp()")

   /* cc */
   TRC_MSG(FUNC_RMMI_START_ATH_FOR_DIALUP_ENTRY, "rmmi_start_ath_for_dialup_hdlr()")
   TRC_MSG(FUNC_RMMI_CLEAR_ATH_FOR_DIALUP_ENTRY, "rmmi_clear_ath_for_dialup_hdlr()")   

   /*IRDA*/
   TRC_MSG(FUNC_IRCOMM_CONNECT_IND_HDLR_ENTRY, "ircomm_connect_ind_hdlr()")
   TRC_MSG(FUNC_IRCOMM_DISCONNECT_IND_HDLR_ENTRY, "ircomm_disconnect_ind_hdlr()")

   /* Validator */
   TRC_MSG(FUNC_RMMI_ATA_HDLR_ENTRY, "rmmi_ata_hdlr()")
   TRC_MSG(FUNC_RMMI_ATD_HDLR_ENTRY, "rmmi_atd_hdlr()")
   TRC_MSG(FUNC_RMMI_ATE_HDLR_ENTRY, "rmmi_ate_hdlr()")
   TRC_MSG(FUNC_RMMI_ATH_HDLR_ENTRY, "rmmi_ath_hdlr()")
   TRC_MSG(FUNC_RMMI_ATS_HDLR_ENTRY, "rmmi_ats_hdlr()")
   TRC_MSG(FUNC_RMMI_ATV_HDLR_ENTRY, "rmmi_atv_hdlr()")
   TRC_MSG(FUNC_RMMI_ATQ_HDLR_ENTRY, "rmmi_atq_hdlr()")
   TRC_MSG(FUNC_RMMI_ATI_HDLR_ENTRY, "rmmi_ati_hdlr()")
   TRC_MSG(FUNC_RMMI_ATL_HDLR_ENTRY, "rmmi_atl_hdlr()")
   TRC_MSG(FUNC_RMMI_ATO_HDLR_ENTRY, "rmmi_ato_hdlr()")
   TRC_MSG(FUNC_RMMI_ATAMP_HDLR_ENTRY, "rmmi_atamp_hdlr()")
   TRC_MSG(FUNC_RMMI_CACM_HDLR_ENTRY, "rmmi_cacm_hdlr()")
   TRC_MSG(FUNC_RMMI_CAMM_HDLR_ENTRY, "rmmi_camm_hdlr()")
   TRC_MSG(FUNC_RMMI_CAOC_HDLR_ENTRY, "rmmi_caoc_hdlr()")
   TRC_MSG(FUNC_RMMI_CCWE_HDLR_ENTRY, "rmmi_ccwe_hdlr()")
   TRC_MSG(FUNC_RMMI_CBST_HDLR_ENTRY, "rmmi_cbst_hdlr()")
   TRC_MSG(FUNC_RMMI_CCUG_HDLR_ENTRY, "rmmi_ccug_hdlr()")
   TRC_MSG(FUNC_RMMI_CHUP_HDLR_ENTRY, "rmmi_chup_hdlr()")
   TRC_MSG(FUNC_RMMI_CHLD_HDLR_ENTRY, "rmmi_chld_hdlr()")
   TRC_MSG(FUNC_RMMI_CLCC_HDLR_ENTRY, "rmmi_clcc_hdlr()")
   TRC_MSG(FUNC_RMMI_CMOD_HDLR_ENTRY, "rmmi_cmod_hdlr()")
   TRC_MSG(FUNC_RMMI_CSNS_HDLR_ENTRY, "rmmi_csns_hdlr()")
   TRC_MSG(FUNC_RMMI_CTFR_HDLR_ENTRY, "rmmi_ctfr_hdlr()")
   TRC_MSG(FUNC_RMMI_VTS_HDLR_ENTRY, "rmmi_vts_hdlr()")
   TRC_MSG(FUNC_RMMI_CPAS_HDLR_ENTRY, "rmmi_cpas_hdlr()")
   TRC_MSG(FUNC_RMMI_CAEMLPP_HDLR_ENTRY, "rmmi_caemlpp_hdlr()")
   TRC_MSG(FUNC_RMMI_CCFC_HDLR_ENTRY, "rmmi_ccfc_hdlr()")
   TRC_MSG(FUNC_RMMI_CCWA_HDLR_ENTRY, "rmmi_ccwa_hdlr()")
   TRC_MSG(FUNC_RMMI_CDIP_HDLR_ENTRY, "rmmi_cdip_hdlr()")
   TRC_MSG(FUNC_RMMI_CLCK_HDLR_ENTRY, "rmmi_clck_hdlr()")
   TRC_MSG(FUNC_RMMI_CLIP_HDLR_ENTRY, "rmmi_clip_hdlr()")
   TRC_MSG(FUNC_RMMI_CLIR_HDLR_ENTRY, "rmmi_clir_hdlr()")
   TRC_MSG(FUNC_RMMI_COLP_HDLR_ENTRY, "rmmi_colp_hdlr()")
   TRC_MSG(FUNC_RMMI_CNAP_HDLR_ENTRY, "rmmi_cnap_hdlr()")
   TRC_MSG(FUNC_RMMI_CPWD_HDLR_ENTRY, "rmmi_cpwd_hdlr()")
   TRC_MSG(FUNC_RMMI_CSSN_HDLR_ENTRY, "rmmi_cssn_hdlr()")
   TRC_MSG(FUNC_RMMI_CUSD_HDLR_ENTRY, "rmmi_cusd_hdlr()")
   TRC_MSG(FUNC_RMMI_CCBS_HDLR_ENTRY, "rmmi_ccbs_hdlr()") 		/* mtk00468 add for CCBS */
   TRC_MSG(FUNC_RMMI_CGATT_HDLR_ENTRY, "rmmi_cgatt_hdlr()")
   TRC_MSG(FUNC_RMMI_COPS_HDLR_ENTRY, "rmmi_cops_hdlr()")
   TRC_MSG(FUNC_RMMI_CGCLASS_HDLR_ENTRY, "rmmi_cgclass_hdlr()")
   TRC_MSG(FUNC_RMMI_CSQ_HDLR_ENTRY, "rmmi_csq_hdlr()")
   TRC_MSG(FUNC_RMMI_CGREG_HDLR_ENTRY, "rmmi_cgreg_hdlr()")
   TRC_MSG(FUNC_RMMI_EPBSE_HDLR_ENTRY, "rmmi_epbse_hdlr()") 
   TRC_MSG(FUNC_RMMI_CEMS_HDLR_ENTRY, "rmmi_cems_hdlr()")			/* mtk00468 add for em mode suport */
   TRC_MSG(FUNC_RMMI_CFPS_HDLR_ENTRY, "rmmi_cnmp_hdlr()")			/* mtk00468 add for force plmn search */
   TRC_MSG(FUNC_RMMI_CAPL_HDLR_ENTRY, "rmmi_capl_hdlr()")			/* mtk00468 add for abort plmn list procedure */	
   TRC_MSG(FUNC_RMMI_CMPI_HDLR_ENTRY, "rmmi_cmpi_hdlr()")			/* mtk00468 add for getting sms profile name mode suport */
   TRC_MSG(FUNC_RMMI_CSMA_HDLR_ENTRY, "rmmi_csma_hdlr()")			/* mtk00468 add for abort send SMS */
   TRC_MSG(FUNC_RMMI_CSMN_HDLR_ENTRY, "rmmi_csmn_hdlr()")			/* mtk00468 add for getting number of SMS  */
   TRC_MSG(FUNC_RMMI_CREG_HDLR_ENTRY, "rmmi_creg_hdlr()")
   TRC_MSG(FUNC_RMMI_CIMI_HDLR_ENTRY, "rmmi_cimi_hdlr()")
   TRC_MSG(FUNC_RMMI_CPIN_HDLR_ENTRY, "rmmi_cpin_hdlr()")
   TRC_MSG(FUNC_RMMI_CPUC_HDLR_ENTRY, "rmmi_cpuc_hdlr()")
   TRC_MSG(FUNC_RMMI_CPOL_HDLR_ENTRY, "rmmi_cpol_hdlr()")
   TRC_MSG(FUNC_RMMI_EPOL_HDLR_ENTRY, "rmmi_epol_hdlr()")
   TRC_MSG(FUNC_RMMI_CRSM_HDLR_ENTRY, "rmmi_crsm_hdlr()")
   TRC_MSG(FUNC_RMMI_CSIM_HDLR_ENTRY, "rmmi_csim_hdlr()")//mtk00468 add for SIM read and write operation
   TRC_MSG(FUNC_RMMI_CGLA_HDLR_ENTRY, "rmmi_cgla_hdlr()")//MAUI_03082391  //mtk02514_nfc
   TRC_MSG(FUNC_RMMI_CRLA_HDLR_ENTRY, "rmmi_crla_hdlr()")
   TRC_MSG(FUNC_RMMI_CCHO_HDLR_ENTRY, "rmmi_ccho_hdlr()")
   TRC_MSG(FUNC_RMMI_CCHC_HDLR_ENTRY, "rmmi_cchc_hdlr()")
   TRC_MSG(FUNC_RMMI_CCSP_HDLR_ENTRY, "rmmi_ccsp_hdlr()")//mtk00468 add for CCPS operation
   TRC_MSG(FUNC_RMMI_CSIMD_HDLR_ENTRY, "rmmi_csimd_hdlr()")//mtk00468 add for SIM dial mode operation
   TRC_MSG(FUNC_RMMI_CSRM_HDLR_ENTRY, "rmmi_csrm_hdlr()")
   TRC_MSG(FUNC_RMMI_CALA_HDLR_ENTRY, "rmmi_cala_hdlr()")
   TRC_MSG(FUNC_RMMI_CALD_HDLR_ENTRY, "rmmi_cald_hdlr()")
   TRC_MSG(FUNC_RMMI_CCLK_HDLR_ENTRY, "rmmi_cclk_hdlr()")
   TRC_MSG(FUNC_RMMI_CSDF_HDLR_ENTRY, "rmmi_csdf_hdlr()")
   TRC_MSG(FUNC_RMMI_CSTF_HDLR_ENTRY, "rmmi_cstf_hdlr()")
   TRC_MSG(FUNC_RMMI_CBC_HDLR_ENTRY, "rmmi_cbc_hdlr()")
   TRC_MSG(FUNC_RMMI_CIND_HDLR_ENTRY, "rmmi_cind_hdlr()")
   TRC_MSG(FUNC_RMMI_CKPD_HDLR_ENTRY, "rmmi_ckpd_hdlr()")
   TRC_MSG(FUNC_RMMI_CLAC_HDLR_ENTRY, "rmmi_clac_hdlr()")   
   TRC_MSG(FUNC_RMMI_CMEC_HDLR_ENTRY, "rmmi_cmec_hdlr()")   
   TRC_MSG(FUNC_RMMI_CLAN_HDLR_ENTRY, "rmmi_clan_hdlr()")
   TRC_MSG(FUNC_RMMI_CLAE_HDLR_ENTRY, "rmmi_clae_hdlr()")
   TRC_MSG(FUNC_RMMI_CLVL_HDLR_ENTRY, "rmmi_clvl_hdlr()")
   TRC_MSG(FUNC_RMMI_VGR_HDLR_ENTRY, "rmmi_vgr_hdlr()")
   TRC_MSG(FUNC_RMMI_VGT_HDLR_ENTRY, "rmmi_vgt_hdlr()")
   TRC_MSG(FUNC_RMMI_CRSL_HDLR_ENTRY, "rmmi_crsl_hdlr()")
   TRC_MSG(FUNC_RMMI_CMUT_HDLR_ENTRY, "rmmi_cmut_hdlr()")
   TRC_MSG(FUNC_RMMI_CSIL_HDLR_ENTRY, "rmmi_csil_hdlr()")
   TRC_MSG(FUNC_RMMI_CTZR_HDLR_ENTRY, "rmmi_ctzr_hdlr()")
   TRC_MSG(FUNC_RMMI_CTSA_HDLR_ENTRY, "rmmi_ctsa_hdlr()")
   TRC_MSG(FUNC_RMMI_CSO_HDLR_ENTRY, "rmmi_cso_hdlr()")
   TRC_MSG(FUNC_RMMI_CSS_HDLR_ENTRY, "rmmi_css_hdlr()")
   TRC_MSG(FUNC_RMMI_ECSCN_HDLR_ENTRY, "rmmi_ecscn_hdlr()")
   TRC_MSG(FUNC_RMMI_CVIB_HDLR_ENTRY, "rmmi_cvib_hdlr()")
   TRC_MSG(FUNC_RMMI_CBKLT_HDLR_ENTRY,"rmmi_cbklt_hdlr()")
   TRC_MSG(FUNC_RMMI_CSGT_HDLR_ENTRY, "rmmi_csgt_hdlr()")
   TRC_MSG(FUNC_RMMI_CGMI_HDLR_ENTRY, "rmmi_cgmi_hdlr()")
   TRC_MSG(FUNC_RMMI_CGMM_HDLR_ENTRY, "rmmi_cgmm_hdlr()")
   TRC_MSG(FUNC_RMMI_CGMR_HDLR_ENTRY, "rmmi_cgmr_hdlr()")
   TRC_MSG(FUNC_RMMI_CGSN_HDLR_ENTRY, "rmmi_cgsn_hdlr()")
   TRC_MSG(FUNC_RMMI_ECAL_HDLR_ENTRY, "rmmi_ecal_hdlr()")
   TRC_MSG(FUNC_RMMI_CASP_HDLR_ENTRY, "rmmi_casp_hdlr()")   //mtk00468 add for audio sound play
   TRC_MSG(FUNC_RMMI_DIAG_HDLR_ENTRY, "rmmi_diag_hdlr()") //__USB_MULTIPLE_COMPORT_SUPPORT__, mtk02285_usb2
   TRC_MSG(FUNC_RMMI_CNUM_HDLR_ENTRY, "rmmi_cnum_hdlr()")
   TRC_MSG(FUNC_RMMI_EPBUM_HDLR_ENTRY, "rmmi_epbum_hdlr()")
   TRC_MSG(FUNC_RMMI_CPBF_HDLR_ENTRY, "rmmi_cpbf_hdlr()")
   TRC_MSG(FUNC_RMMI_CPBR_HDLR_ENTRY, "rmmi_cpbr_hdlr()")
   TRC_MSG(FUNC_RMMI_CPBS_HDLR_ENTRY, "rmmi_cpbs_hdlr()")
   TRC_MSG(FUNC_RMMI_CPBW_HDLR_ENTRY, "rmmi_cpbw_hdlr()")
   TRC_MSG(FUNC_RMMI_ESLN_HDLR_ENTRY, "rmmi_esln_hdlr()") 
   TRC_MSG(FUNC_RMMI_EAPPROVE_HDLR_ENTRY, "rmmi_eapprove_hdlr()")
   TRC_MSG(FUNC_RMMI_CPBI_HDLR_ENTRY, "rmmi_cpbi_hdlr()") //mtk00468 add for get status of phb entry
   TRC_MSG(FUNC_RMMI_CGSMS_HDLR_ENTRY, "rmmi_cgsms_hdlr()")
   TRC_MSG(FUNC_RMMI_CSMS_HDLR_ENTRY, "rmmi_csms_hdlr()")
   TRC_MSG(FUNC_RMMI_CMGC_HDLR_ENTRY, "rmmi_cmgc_hdlr()")
   TRC_MSG(FUNC_RMMI_CMGD_HDLR_ENTRY, "rmmi_cmgd_hdlr()")
   TRC_MSG(FUNC_RMMI_CMGF_HDLR_ENTRY, "rmmi_cmgf_hdlr()")
   TRC_MSG(FUNC_RMMI_CMGL_HDLR_ENTRY, "rmmi_cmgl_hdlr()")
   TRC_MSG(FUNC_RMMI_CMGR_HDLR_ENTRY, "rmmi_cmgr_hdlr()")
   TRC_MSG(FUNC_RMMI_CMGS_HDLR_ENTRY, "rmmi_cmgs_hdlr()")
   TRC_MSG(FUNC_RMMI_CMGW_HDLR_ENTRY, "rmmi_cmgw_hdlr()")
   TRC_MSG(FUNC_RMMI_EMGC_HDLR_ENTRY, "rmmi_emgc_hdlr()")
   TRC_MSG(FUNC_RMMI_ENMA_HDLR_ENTRY, "rmmi_enma_hdlr()")
   TRC_MSG(FUNC_RMMI_EMGS_HDLR_ENTRY, "rmmi_emgs_hdlr()")
   TRC_MSG(FUNC_RMMI_EMGW_HDLR_ENTRY, "rmmi_emgw_hdlr()")
   TRC_MSG(FUNC_RMMI_EMGL_HDLR_ENTRY, "rmmi_emgl_hdlr()")   
   TRC_MSG(FUNC_RMMI_CMMS_HDLR_ENTRY, "rmmi_cmms_hdlr()")
   TRC_MSG(FUNC_RMMI_CMSS_HDLR_ENTRY, "rmmi_cmss_hdlr()")
   TRC_MSG(FUNC_RMMI_CPMS_HDLR_ENTRY, "rmmi_cpms_hdlr()")
   TRC_MSG(FUNC_RMMI_CSCA_HDLR_ENTRY, "rmmi_csca_hdlr()")
   TRC_MSG(FUNC_RMMI_CSCB_HDLR_ENTRY, "rmmi_cscb_hdlr()")   
   TRC_MSG(FUNC_RMMI_ECBMR_HDLR_ENTRY, "rmmi_ecbmr_hdlr()")
   TRC_MSG(FUNC_RMMI_CSMP_HDLR_ENTRY, "rmmi_csmp_hdlr()")
   TRC_MSG(FUNC_RMMI_CNMI_HDLR_ENTRY, "rmmi_cnmi_hdlr()")
   TRC_MSG(FUNC_RMMI_CNMA_HDLR_ENTRY, "rmmi_cnma_hdlr()")
   TRC_MSG(FUNC_RMMI_CSDH_HDLR_ENTRY, "rmmi_csdh_hdlr()")
   TRC_MSG(FUNC_RMMI_ESMSMAIP_HDLR_ENTRY, "rmmi_esmsmaip_hdlr()")
   TRC_MSG(FUNC_RMMI_ESMSMOIP_HDLR_ENTRY, "rmmi_esmsmoip_hdlr()")
   TRC_MSG(FUNC_RMMI_ESMSMTIP_HDLR_ENTRY, "rmmi_esmsmtip_hdlr()")
   TRC_MSG(FUNC_RMMI_ESMMA_HDLR_ENTRY, "rmmi_esmma_hdlr()")
   TRC_MSG(FUNC_RMMI_CSCS_HDLR_ENTRY, "rmmi_cscs_hdlr()")
   TRC_MSG(FUNC_RMMI_CFUN_HDLR_ENTRY, "rmmi_cfun_hdlr()")
   TRC_MSG(FUNC_RMMI_CGACT_HDLR_ENTRY, "rmmi_cgact_hdlr()")
   TRC_MSG(FUNC_RMMI_EGACT_HDLR_ENTRY, "rmmi_egact_hdlr()")

   //mtk02219   
   TRC_MSG(FUNC_RMMI_CGCONTRDP_HDLR_ENTRY,  "rmmi_cgcontrdp_hdlr()")
   TRC_MSG(FUNC_RMMI_CGSCONTRDP_HDLR_ENTRY, "rmmi_cgscontrdp_hdlr()")
   TRC_MSG(FUNC_RMMI_CGEQOS_HDLR_ENTRY,     "rmmi_cgeqos_hdlr()")
   TRC_MSG(FUNC_RMMI_CGEQOSRDP_HDLR_ENTRY,  "rmmi_cgeqosrdp_hdlr()")
   TRC_MSG(FUNC_RMMI_CGTFTRDP_HDLR_ENTRY,   "rmmi_cgtftrdp_hdlr()")
   TRC_MSG(FUNC_RMMI_CEMODE_HDLR_ENTRY,     "rmmi_cemode_hdlr()")
   TRC_MSG(FUNC_RMMI_CEREG_HDLR_ENTRY,      "rmmi_cereg_hdlr()")
   TRC_MSG(FUNC_RMMI_CGDEL_HDLR_ENTRY,      "rmmi_cgdel_hdlr()")

   TRC_MSG(FUNC_RMMI_CGANS_HDLR_ENTRY, "rmmi_cgans_hdlr()")
   TRC_MSG(FUNC_RMMI_CGAUTO_HDLR_ENTRY, "rmmi_cgauto_hdlr()")
   TRC_MSG(FUNC_RMMI_CGCMOD_HDLR_ENTRY, "rmmi_cgcmod_hdlr()")
   TRC_MSG(FUNC_RMMI_CGDATA_HDLR_ENTRY, "rmmi_cgdata_hdlr()")
   TRC_MSG(FUNC_RMMI_EGLD_HDLR_ENTRY, "rmmi_egld_hdlr()")
   TRC_MSG(FUNC_RMMI_CGPADDR_HDLR_ENTRY, "rmmi_cgpaddr_hdlr()")
   TRC_MSG(FUNC_RMMI_CGDCONT_HDLR_ENTRY, "rmmi_cgdcont_hdlr()")
   TRC_MSG(FUNC_RMMI_CGDSCONT_HDLR_ENTRY, "rmmi_cgdscont_hdlr()")
   TRC_MSG(FUNC_RMMI_CGQMIN_HDLR_ENTRY, "rmmi_cgqmin_hdlr()")
   TRC_MSG(FUNC_RMMI_CGQREQ_HDLR_ENTRY, "rmmi_cgqreq_hdlr()")
   TRC_MSG(FUNC_RMMI_CGEQMIN_HDLR_ENTRY, "rmmi_cgeqmin_hdlr()")
   TRC_MSG(FUNC_RMMI_CGEQREQ_HDLR_ENTRY, "rmmi_cgeqreq_hdlr()")
   TRC_MSG(FUNC_RMMI_CGEQ_COMMON_HDLR_ENTRY, "rmmi_cgeq_hdlr(), qos_type=%Matci_qos_enum")   //mtk02285, 20111003
   TRC_MSG(FUNC_RMMI_CGTFT_HDLR_ENTRY, "rmmi_cgtft_hdlr()")
   TRC_MSG(FUNC_RMMI_EGDELPF_HDLR_ENTRY, "rmmi_egdelpf_hdlr()")
   TRC_MSG(FUNC_RMMI_EGLNKPF_HDLR_ENTRY, "rmmi_eglnkpf_hdlr()")
   TRC_MSG(FUNC_RMMI_CGSDATA_HDLR_ENTRY, "rmmi_cgsdata_hdlr()")
   TRC_MSG(FUNC_RMMI_CGPRCO_HDLR_ENTRY, "rmmi_cgprco_hdlr()")
   TRC_MSG(FUNC_RMMI_CGAUTH_HDLR_ENTRY, "rmmi_cgauth_hdlr()")
   TRC_MSG(FUNC_RMMI_PSBEARER_HDLR_ENTRY, "rmmi_psbearer_hdlr()")
   TRC_MSG(FUNC_RMMI_CRLP_HDLR_ENTRY, "rmmi_crlp_hdlr()")
   TRC_MSG(FUNC_RMMI_FCLASS_HDLR_ENTRY, "rmmi_fclass_hdlr()")
   TRC_MSG(FUNC_RMMI_ICF_HDLR_ENTRY, "rmmi_icf_hdlr()")
   TRC_MSG(FUNC_RMMI_DS_HDLR_ENTRY, "rmmi_ds_hdlr()")
   TRC_MSG(FUNC_RMMI_CR_HDLR_ENTRY, "rmmi_cr_hdlr()")
   TRC_MSG(FUNC_RMMI_CR_RESULT_CODE_FMTTR_ENTRY, "rmmi_cr_result_code_fmttr()")
   TRC_MSG(FUNC_RMMI_CEER_HDLR_ENTRY, "rmmi_ceer_hdlr()")
   TRC_MSG(FUNC_RMMI_EPIN_HDLR_ENTRY, "rmmi_epin_hdlr()")
   TRC_MSG(FUNC_RMMI_EPIN1_HDLR_ENTRY, "rmmi_epin1_hdlr()")   
   TRC_MSG(FUNC_RMMI_EPIN2_HDLR_ENTRY, "rmmi_epin2_hdlr()")
   TRC_MSG(FUNC_RMMI_EPINC_HDLR_ENTRY, "rmmi_cpinc_hdlr()")
   TRC_MSG(FUNC_RMMI_CSAS_HDLR_ENTRY, "rmmi_csas_hdlr()")
   TRC_MSG(FUNC_RMMI_CRES_HDLR_ENTRY, "rmmi_cres_hdlr()")
   TRC_MSG(FUNC_RMMI_EFSR_HDLR_ENTRY, "rmmi_efsr_hdlr()")
   TRC_MSG(FUNC_RMMI_EFSW_HDLR_ENTRY, "rmmi_efsw_hdlr()")
   TRC_MSG(FUNC_RMMI_EFSC_HDLR_ENTRY, "rmmi_efsc_hdlr()")
   TRC_MSG(FUNC_RMMI_EFSL_HDLR_ENTRY, "rmmi_efsl_hdlr()")
   TRC_MSG(FUNC_RMMI_EFSF_HDLR_ENTRY, "rmmi_efsf_hdlr()")
   TRC_MSG(FUNC_RMMI_EFSD_HDLR_ENTRY, "rmmi_efsd_hdlr()")
   TRC_MSG(FUNC_RMMI_EQUERY_HDLR_ENTRY, "rmmi_equery_hdlr()")
   TRC_MSG(FUNC_RMMI_BLDN_HDLR_ENTRY, "rmmi_bldn_hdlr()")
   TRC_MSG(FUNC_RMMI_EREG_HDLR_ENTRY, "rmmi_ereg_hdlr()")
   TRC_MSG(FUNC_RMMI_EPMIC_HDLR_ENTRY, "rmmi_epmic_hdlr()")
   TRC_MSG(FUNC_RMMI_EBTLB_HDLR_ENTRY, "rmmi_ebtlb_hdlr()")
   TRC_MSG(FUNC_RMMI_BVRA_HDLR_ENTRY, "rmmi_bvra_hdlr()")
   TRC_MSG(FUNC_RMMI_EVCARD_HDLR_ENTRY, "rmmi_evcard_hdlr()")
   TRC_MSG(FUNC_RMMI_EMMISTR_HDLR_ENTRY, "rmmi_emmistr_hdlr()")
   TRC_MSG(FUNC_RMMI_WS46_HDLR_ENTRY, "rmmi_ws46_hdlr()")
   TRC_MSG(FUNC_RMMI_ECPU_HDLR_ENTRY, "rmmi_ecpu_hdlr()")
   TRC_MSG(FUNC_RMMI_ERAM_HDLR_ENTRY, "rmmi_eram_hdlr()")
   TRC_MSG(FUNC_RMMI_ELAUNCH_HDLR_ENTRY, "rmmi_elaunch_hdlr()")
   TRC_MSG(FUNC_RMMI_ELOG_HDLR_ENTRY, "rmmi_elog_hdlr()")
   TRC_MSG(FUNC_RMMI_ESUO_HDLR_ENTRY, "rmmi_esuo_hdlr()") 
   TRC_MSG(FUNC_RMMI_TRACE_HDLR_ENTRY, "rmmi_trace_hdlr()")
   TRC_MSG(FUNC_RMMI_ESWM_HDLR_ENTRY, "rmmi_eswm_hdlr()")
   TRC_MSG(FUNC_RMMI_EMSDMOD_HDLR_ENTRY, "rmmi_emsdmod_hdlr()")
   TRC_MSG(FUNC_RMMI_EMSDTNUM_HDLR_ENTRY, "rmmi_emsdtnum_hdlr()")
   TRC_MSG(FUNC_RMMI_EMSDRNUM_HDLR_ENTRY, "rmmi_emsdrnum_hdlr()")
   TRC_MSG(FUNC_RMMI_EMSDSET_HDLR_ENTRY, "rmmi_emsdset_hdlr()")
   TRC_MSG(FUNC_RMMI_EMSD_HDLR_ENTRY, "rmmi_emsd_hdlr()")
   TRC_MSG(FUNC_RMMI_EMSDPUSH_HDLR_ENTRY, "rmmi_emsdpush_hdlr()")
   TRC_MSG(FUNC_RMMI_ESPEECH_HDLR_ENTRY, "rmmi_espeech_hdlr()")
   TRC_MSG(FUNC_RMMI_ESSTV_HDLR_ENTRY, "rmmi_esstv_hdlr()")
   TRC_MSG(FUNC_RMMI_EDTP_HDLR_ENTRY, "rmmi_edtp_hdlr()")
   TRC_MSG(FUNC_RMMI_EDTS_HDLR_ENTRY, "rmmi_edts_hdlr()")
   TRC_MSG(FUNC_RMMI_EDSETDEV_HDLR_ENTRY, "rmmi_esetdev_hdlr()")
   TRC_MSG(FUNC_RMMI_ESOV_HDLR_ENTRY, "rmmi_esov_hdlr()")
   TRC_MSG(FUNC_RMMI_ESMV_HDLR_ENTRY, "rmmi_esmv_hdlr()")
   TRC_MSG(FUNC_RMMI_ESSMA_HDLR_ENTRY, "rmmi_essma_hdlr()")
   TRC_MSG(FUNC_RMMI_L1AUD_SPC_CALLBACK, "rmmi_l1aud_spc_callback()")
   TRC_MSG(FUNC_RMMI_EPSAP_HDLR_ENTRY, "rmmi_epsap_hdlr()")
   TRC_MSG(FUNC_RMMI_EPSAPPULL_HDLR_ENTRY, "rmmi_epsappull_hdlr()")
   /*CSD_FAX*/
   TRC_MSG(FUNC_RMMI_FMI_HDLR_ENTRY, "rmmi_fmi_hdlr()")
   TRC_MSG(FUNC_RMMI_FMM_HDLR_ENTRY, "rmmi_fmm_hdlr()")
   TRC_MSG(FUNC_RMMI_FMR_HDLR_ENTRY, "rmmi_fmr_hdlr()")
   TRC_MSG(FUNC_RMMI_FPR_HDLR_ENTRY, "rmmi_fpr_hdlr()")
   TRC_MSG(FUNC_RMMI_FLO_HDLR_ENTRY, "rmmi_flo_hdlr()") 
   TRC_MSG(FUNC_RMMI_FDT_HDLR_ENTRY, "rmmi_fdt_hdlr()")
   TRC_MSG(FUNC_RMMI_FDR_HDLR_ENTRY, "rmmi_fdr_hdlr()")
   TRC_MSG(FUNC_RMMI_FIP_HDLR_ENTRY, "rmmi_fip_hdlr()")
   TRC_MSG(FUNC_RMMI_FKS_HDLR_ENTRY, "rmmi_fks_hdlr()")
   TRC_MSG(FUNC_RMMI_FK_HDLR_ENTRY, "rmmi_fk_hdlr()")
   TRC_MSG(FUNC_RMMI_FET_HDLR_ENTRY, "rmmi_fet_hdlr()")
   TRC_MSG(FUNC_RMMI_FTM_HDLR_ENTRY, "rmmi_ftm_hdlr()")
   TRC_MSG(FUNC_RMMI_FRM_HDLR_ENTRY, "rmmi_frm_hdlr()")
   TRC_MSG(FUNC_RMMI_FTH_HDLR_ENTRY, "rmmi_fth_hdlr()")
   TRC_MSG(FUNC_RMMI_FRH_HDLR_ENTRY, "rmmi_frh_hdlr()")
   TRC_MSG(FUNC_RMMI_FTS_HDLR_ENTRY, "rmmi_fts_hdlr()")
   TRC_MSG(FUNC_RMMI_FRS_HDLR_ENTRY, "rmmi_frs_hdlr()")
   TRC_MSG(FUNC_RMMI_FCC_HDLR_ENTRY, "rmmi_fcc_hdlr()")
   TRC_MSG(FUNC_RMMI_FDCC_HDLR_ENTRY, "rmmi_fdcc_hdlr()")
   TRC_MSG(FUNC_RMMI_FIS_HDLR_ENTRY, "rmmi_fis_hdlr()")
   TRC_MSG(FUNC_RMMI_FDIS_HDLR_ENTRY, "rmmi_fdis_hdlr()")
   TRC_MSG(FUNC_RMMI_FCS_HDLR_ENTRY, "rmmi_fcs_hdlr()")
   TRC_MSG(FUNC_RMMI_FDCS_HDLR_ENTRY, "rmmi_fdcs_hdlr()")
   TRC_MSG(FUNC_RMMI_FLI_HDLR_ENTRY, "rmmi_fli_hdlr()")
   TRC_MSG(FUNC_RMMI_FLID_HDLR_ENTRY, "rmmi_flid_hdlr()")
   TRC_MSG(FUNC_RMMI_FPI_HDLR_ENTRY, "rmmi_fli_hdlr()")
   TRC_MSG(FUNC_RMMI_FCIG_HDLR_ENTRY, "rmmi_flid_hdlr()")
   TRC_MSG(FUNC_RMMI_FLP_HDLR_ENTRY, "rmmi_flp_hdlr()")
   TRC_MSG(FUNC_RMMI_FLPL_HDLR_ENTRY, "rmmi_flpl_hdlr()")
   TRC_MSG(FUNC_RMMI_FSP_HDLR_ENTRY, "rmmi_fsp_hdlr()")
   TRC_MSG(FUNC_RMMI_FSPL_HDLR_ENTRY, "rmmi_fspl_hdlr()")
   TRC_MSG(FUNC_RMMI_FNR_HDLR_ENTRY, "rmmi_fnr_hdlr()")
   TRC_MSG(FUNC_RMMI_FIE_HDLR_ENTRY, "rmmi_fie_hdlr()")
   TRC_MSG(FUNC_RMMI_FPS_HDLR_ENTRY, "rmmi_fps_hdlr()")
   TRC_MSG(FUNC_RMMI_FPTS_HDLR_ENTRY, "rmmi_fpts_hdlr()")
   TRC_MSG(FUNC_RMMI_FRQ_HDLR_ENTRY, "rmmi_frq_hdlr()")
   TRC_MSG(FUNC_RMMI_FBADLIN_HDLR_ENTRY, "rmmi_fbadlin_hdlr()")
   TRC_MSG(FUNC_RMMI_FBADMUL_HDLR_ENTRY, "rmmi_fbadmul_hdlr()")
   TRC_MSG(FUNC_RMMI_FCQ_HDLR_ENTRY, "rmmi_fcq_hdlr()")
   TRC_MSG(FUNC_RMMI_FIT_HDLR_ENTRY, "rmmi_fit_hdlr()")
   TRC_MSG(FUNC_RMMI_FPP_HDLR_ENTRY, "rmmi_fpp_hdlr()")
   TRC_MSG(FUNC_RMMI_FBO_HDLR_ENTRY, "rmmi_fbo_hdlr()")
   TRC_MSG(FUNC_RMMI_FBOR_HDLR_ENTRY, "rmmi_fbor_hdlr()")
   TRC_MSG(FUNC_RMMI_FEA_HDLR_ENTRY, "rmmi_fea_hdlr()")
   TRC_MSG(FUNC_RMMI_FREL_HDLR_ENTRY, "rmmi_frel_hdlr()")
   TRC_MSG(FUNC_RMMI_FNS_HDLR_ENTRY, "rmmi_fns_hdlr()")
   TRC_MSG(FUNC_RMMI_FCR_HDLR_ENTRY, "rmmi_fcr_hdlr()")
   TRC_MSG(FUNC_RMMI_FBU_HDLR_ENTRY, "rmmi_fbu_hdlr()")
   TRC_MSG(FUNC_RMMI_FBUG_HDLR_ENTRY, "rmmi_fbug_hdlr()")
   TRC_MSG(FUNC_RMMI_FAP_HDLR_ENTRY, "rmmi_fap_hdlr()")
   TRC_MSG(FUNC_RMMI_FSA_HDLR_ENTRY, "rmmi_fsa_hdlr()")
   TRC_MSG(FUNC_RMMI_FPA_HDLR_ENTRY, "rmmi_fpa_hdlr()")
   TRC_MSG(FUNC_RMMI_FPW_HDLR_ENTRY, "rmmi_fpw_hdlr()")
   TRC_MSG(FUNC_RMMI_FCT_HDLR_ENTRY, "rmmi_fct_hdlr()")
   TRC_MSG(FUNC_RMMI_FPHCTO_HDLR_ENTRY, "rmmi_fphcto_hdlr()")
   TRC_MSG(FUNC_RMMI_FHS_HDLR_ENTRY, "rmmi_fhs_hdlr()")
   TRC_MSG(FUNC_RMMI_FMS_HDLR_ENTRY, "rmmi_fms_hdlr()")
   TRC_MSG(FUNC_RMMI_FMINSP_HDLR_ENTRY, "rmmi_fminsp_hdlr()")
   TRC_MSG(FUNC_RMMI_FRY_HDLR_ENTRY, "rmmi_fry_hdlr()")
   TRC_MSG(FUNC_RMMI_FBS_HDLR_ENTRY, "rmmi_fbs_hdlr()")
   TRC_MSG(FUNC_RMMI_FFC_HDLR_ENTRY, "rmmi_ffc_hdlr()")
   TRC_MSG(FUNC_RMMI_FVRFC_HDLR_ENTRY, "rmmi_fvrfc_hdlr()")
   TRC_MSG(FUNC_RMMI_FDFFC_HDLR_ENTRY, "rmmi_fdffc_hdlr()")
   TRC_MSG(FUNC_RMMI_FLNFC_HDLR_ENTRY, "rmmi_flnfc_hdlr()")
   TRC_MSG(FUNC_RMMI_FWDFC_HDLR_ENTRY, "rmmi_fwdfc_hdlr()")

   TRC_MSG(FUNC_RMMI_CTMSET_HDLR_ENTRY, "rmmi_ctmset_hdlr()")
   TRC_MSG(FUNC_RMMI_CTMOPEN_HDLR_ENTRY, "rmmi_ctmopen_hdlr()")
   TRC_MSG(FUNC_RMMI_CTMCLOSE_HDLR_ENTRY, "rmmi_ctmclose_hdlr()")
   TRC_MSG(FUNC_RMMI_CTMCONN_HDLR_ENTRY, "rmmi_ctmconn_hdlr()")
   TRC_MSG(FUNC_RMMI_CTMS_HDLR_ENTRY, "rmmi_ctms_hdlr()")
   TRC_MSG(FUNC_RMMI_CTMCFG_HDLR_ENTRY, "rmmi_ctmcfg_hdlr()")
   TRC_MSG(FUNC_RMMI_CTMCALL_HDLR_ENTRY, "rmmi_ctmcall_hdlr()")
	
   TRC_MSG(FUNC_RMMI_EMEMS_HDLR_ENTRY, "rmmi_emems_hdlr()") 
   TRC_MSG(FUNC_RMMI_EEMODE_HDLR_ENTRY,     "rmmi_eemode_hdlr()")
	
   /* -------------------------------------------TRACE_INFO trace class------------------------------------------- */ 
   /* parser/UART/RESULT */
   TRC_MSG(INFO_EXTCOMMAND_HASH_VALUE, "rmmi_extended_cmd_processor(), hash_value1= %u, hash_value2= %u. cmd_index: %u/%u")
   TRC_MSG(RMMI_MULTI_CMD_RECEIVED, "multi cmd received")
   TRC_MSG(BASIC_COMMAND_HASH_VALUE, "rmmi_basic_cmd_processor(), hash_value = %u")
   TRC_MSG(AT_CMD_STRING, "command: %c%c%c%c%c%c%c%c%c%c%c%c")
   TRC_MSG(CUSTOM_CMD_HDLR, "CUSTOMER AT Cmd")
   TRC_MSG(RMMI_MULTI_CMD_NOT_FINISHED, "multi cmd NOT finished")
   TRC_MSG(RMMI_PROCESS_MULTI_CMD_ACTION_EXIST, "rmmi_process_multi_cmd: is_ucm_action = %d,route_through_mmi=%d")
   TRC_MSG(UCM_ACTION, "It's a ucm action, OK will return by UCM")
   TRC_MSG(ROUTE_THRU_LMMI_FOR_BASIC_CMD, "route through mmi in basic_cmd_hdlr ,OK will return later") 
   TRC_MSG(RMMI_PROCESS_MULTI_CMD, "process_multi_cmd")
   TRC_MSG(RMMI_MULTI_CMD_STRING_EXIST, "multi cmd string exist")
   TRC_MSG(RMMI_MULTI_CMD_STRING_NOT_EXIST, "multi cmd string NOT exist")
   TRC_MSG(RMMI_SRC_ID_AND_CID, "current_src_id = %d, cid = %d")
   TRC_MSG(RMMI_RECEIVE_DATA_DURING_ATD, "receiving data during ATD")
   TRC_MSG(RMMI_ABORT_ATD_OPERATION, "abort ATD !!")
   TRC_MSG(INFO_RMMI_INPUT, "read uart, que.len=%d, space=%d, read=%d, uart_empty=%d")
   TRC_MSG(RMMI_CMD_FROM_SAT, "cmd from sat")
   TRC_MSG(RMMI_CMD_FROM_TST, "cmd from tst")
   TRC_MSG(RMMI_CLEAR_OUTPUT_QUEUE, "clear output queue!!")
   TRC_MSG(RMMI_RSP_ERROR_CAUSE, "rmmi_rsp , rmmi_cause = %u")
   TRC_MSG(RMMI_RESULT_CODE_FMTTR, "result code: %Mrmmi_rsp_type_enum")
   TRC_MSG(RMMI_RESULT_CODE_ERROR, "result code: %Mrmmi_rsp_type_enum, cause: %Mps_cause_enum")
   TRC_MSG(RMMI_MULTI_CMD_ERROR, "multi cmd error")           
   TRC_MSG(INFO_RMMI_OBTAIN_UART_CONTROL,"rmmi_obtain_uart_control() ,port=%d, owner:%Msim_interface_enum") 
   TRC_MSG(INFO_CHECK_CMD_ALLOW_RETURN_FALSE, "check_cmd_allow() return false")
   TRC_MSG(INFO_MSG_BASED_REGISTER, "register msessage based channel: ch_num:%d")
   TRC_MSG(INFO_MSG_BASED_EXECUTION, "execution message based AT: port:%d, src:%d, length:%d, pdu_length: %d")
   TRC_MSG(INFO_MSG_BASED_RESPONSE, "send response message: len: %d, src: %d")
   TRC_MSG(INFO_MSG_BASED_URC, "send urc message: len: %d")
   TRC_MSG(INFO_RMMI_SELECT_CONTEXT, "[RMMI_ROOT] select context: cid:%d, %Msim_interface_enum")
   TRC_MSG(INFO_RMMI_INVALID_PORT, "[RMMI_ROOT] INVALID: port:%d")   
   TRC_MSG(INFO_RMMI_UART_PLUGIN, "[RMMI_ROOT] UART plugin, src:%d, cid:%d, port:%d")
   TRC_MSG(INFO_RMMI_UART_PLUGOUT, "[RMMI_ROOT] UART plugout, src:%d, cid:%d, port:%d")
   TRC_MSG(INFO_AT_ETSTLP, "+ETSTLP: tst_port_ps: %hd, tst_port_l1: %hd")
   TRC_MSG(INFO_RMMI_USB_ACTIVE, "Is UART active, port:%d, active: %d")
   TRC_MSG(INFO_WAKEUP,"[DUAL TALK] Wake Up: %Mrmmi_wakeup_type_enum")
   TRC_MSG(INFO_PULL_GPIO, "[DUAL TALK] Pull GPIO %d")
   TRC_MSG(INFO_DUMP_AGPS_MD_HEADER, "agps md header : version = %d , type = %d , length = %d")
   TRC_MSG(INFO_WRITE_TO_AGPSD, "write data to AGPSD via uart_port_gps_ccci, size : %d")
   
   /* CC */
   TRC_MSG(RMMI_EXPLICT_SEND_CIEV, "Explictly to send CIEV: %d, %d")
   TRC_MSG(INFO_HF_IS_NOT_READY_TO_RECIEVE_URC_REPORT, "HF is not ready to receive URC report")
   TRC_MSG(INFO_CLEAR_HF_URC_REPORT_FLAG, "Clear hf_urc_report_flag: cid =%d,src_id=%d")
   TRC_MSG(INFO_RMMI_CANCEL_EVENT, "rmmi: cancel retry timer!, event_id=%d")
   TRC_MSG(INFO_RMMI_ATH_NO_CALL_HANGUP, "ath: no call to hangup")
   TRC_MSG(ATH_REL_ACTIVE_AND_ACCEPT, "ATH: REL_ACTIVE_AND_ACCEPT")
   TRC_MSG(ATH_REL_ACTIVE, "ATH: REL_ACTIVE , active_call_id=%hd")
   TRC_MSG(ATH_REL_HELD, "ATH: REL_HELD , hold_call_id =%hd")
   TRC_MSG(ATH_FOR_GPRS_DIALUP_FAILURE, "ATH is for GPRS dialup failure,do nothing and return OK")
   TRC_MSG(FOR_BT_HFP_CHLD_EQUAL_1X, "For BT HFP : chld=1x , shall also retrieve held call")
   TRC_MSG(ATDL_NO_LAST_NUMBER_DIALED, "ATDL: No last number dialed")
   TRC_MSG(ATA_FOR_DATA_CALL, "ATA for data call ")
   TRC_MSG(ATD_HDLR_CALL_MODIFY_REQUEST, "atd_hdlr: call modify request return %d")
   TRC_MSG(ATD_HDLR_PROCESSING_ATD_GPRS_DIALUP_OR_DATA_CALL, "atd_hdlr: Processing ATD GPRS dial-up or data call")
   TRC_MSG(ATD_HDLR_ATD_DIAL_VT_CALL, "atd_hdlr: atd to dial VT call")
   TRC_MSG(ATD_HDLR_IMS_NOT_SUPPORT_DATA_CALL, "atd_hdlr: IMS not support data call")
   
   /* BT */
   TRC_MSG(INFO_HFP_AUTH_FAIL,"HFP connecting") 
   TRC_MSG(INFO_HFP_CONNECTED,"HFP connected,port= %d") 
   TRC_MSG(INFO_HFP_RAND_NUM, "rand number, rand=0x%08x")   
   TRC_MSG(INFO_HFP_SEQ1, "Seq1 =0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x")   
   TRC_MSG(INFO_HFP_SEQ2, "Seq2 =0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x")   
   TRC_MSG(INFO_HFP_VERNO, "verno, verno=%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c")   
   TRC_MSG(INFO_HFP_OUTPUT, "Output =0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x")   
   TRC_MSG(INFO_SET_ATH_FOR_DIALUP, "Set ath_for_dialup=%d")
   TRC_MSG(INFO_ATCI_ROOT_SWITCH_FOR_HF, "ATCI Root switches to new_sim_id=%d")
   
    /*EQ/EM*/
   TRC_MSG(INFO_REQUEST_TYPE, "request_type = %d")

   /* PHB */
   TRC_MSG(INFO_ALPH_ID_PRESENT_NO_TEL_NUMBER, "Only alph_id is present, no tel number")

   /* GPRS */
   TRC_MSG(RMMI_CURRENT_ACCESS_TECHNOLOGY, "AcT:%hd <= Rat:%Mrat_enum, cell_data_speed:%Ml4c_data_speed_support_enum, max_data_bearer_capa:%Ml4c_data_bearer_capablility_enum")

   /* MISC */
   TRC_MSG(RMMI_PARAM_D, "param = %d")
   TRC_MSG(RMMI_PARAM_DD, "param1 = %d , param2 = %d")
   TRC_MSG(RMMI_PARAM_U, "param = %u")
   TRC_MSG(RMMI_PARAM_UU, "param1 = %u , param2 = %u")
   TRC_MSG(RMMI_RESPONSE_SUPPRESS_ON, "response suppress on")
   TRC_MSG(INFO_STRING_IS_PURE_ASCII_STRING_IS_NOT_STRATING_WITH_0X00, "string_is_pure_ascii() : string is not strating with 0x00")
   TRC_MSG(INFO_STRING_IS_PURE_ASCII_RETURN_FALSE_DUE_TO_STR_2, "string_is_pure_ascii() return false due to str[%d+2]=%x")
   TRC_MSG(INFO_STRING_IS_PURE_ASCII_RETURN_FALSE_DUE_TO_STR_3, "string_is_pure_ascii() return false due to str[%d+3]=%x")
   TRC_MSG(INFO_RMMI_PURE_ASCII, "pure_ascii=%d")
   TRC_MSG(RMMI_ATO_HDLR, "RMMI ATO, state = %Ml4c_state_enum")
   
   /* -------------------------------------------TRACE_STATE trace class------------------------------------------- */
	
   /* -------------------------------------------TRACE_WARNING trace class------------------------------------------- */
   /*parser*/
   TRC_MSG(WARNING_CANNOT_PROCESS_MULTI_CMD, "Warning: cid == 0xff! cannot process multi cmd")
   TRC_MSG(WARNING_RMMI_CMD_NOT_ALLOWED, "cmd NOT allowed, cause = %u")
   TRC_MSG(WARNING_RMMI_CMD_ALLOWED, "cmd allowed")

   /* uart */
   TRC_MSG(WARNING_RMMI_PORT_OWNER_ERROR, "Warning: port=%d,owner=%d")
   TRC_MSG(WARNING_RMMI_ERROR, "Warning: error")
   TRC_MSG(WARNING_RMMI_SET_UART_STOP_TO_SEND_FLAG, "set stop_to_send_flag,cid=%d")   
   TRC_MSG(WARNING_RMMI_UART_STOP_TO_SEND, "Warning: rmmi_uart_write_data stop to send,cid=%d")   
   TRC_MSG(WARNING_ORI_MODULE_ID_WRONG, "Warning: ori_module_id wrong, ori_module_id=%d")
   TRC_MSG(WARNING_ORI_MODULE_ID_EQUAL_MODULE_ID, "Warning: ori_module_id equal module_id, ori_module_id=%d")
   TRC_MSG(WARNING_CMUX_PORT_ERROR, "AT+CMUX isn't allowed on USB2")

   /*CC*/
   TRC_MSG(WARNING_ATH_DISCONNECT_AT_INITIAL_CALL, "ATH: can only disconnect AT-initial call")
   TRC_MSG(WARNING_CHUP_NO_CALL_TO_HANGUP, "AT+CHUP: no call to hangup")
   TRC_MSG(WARNING_CHUP_DISCONNECT_AT_INITIAL_CALL, "AT+CHUP: can only disconnect AT-initial call")
   TRC_MSG(CHLD_EQUAL_1X, "chld = 1x , x is not a active call ,call_state = %d")
   TRC_MSG(BLDN_NO_LAST_NUMBER_DIALED_EXIST, "BLDN: No last number dialed exist")
   TRC_MSG(BLDN_NO_SIM_INSERTED, "BLDN: no SIM inserted")
   TRC_MSG(ATD_MEMORY_DIAL_INVALID_MEMORY_LOCATION, "ATD memory dial , invalid memory location ")
   TRC_MSG(ATD_HDLR_DIAL_NUMBER_LENGTH_ILLEGAL, "atd_hdlr : atd dial number length is illegal")
   TRC_MSG(WARNING_DIALUP_NOT_ALLOWED_ON_1T1R, "Warning: Dialup is not allowed on 1T1R port %d") /* MAUI_02738549: 2011/03/02, avoid dialup on 1T1R USB COM */
   TRC_MSG(FUNC_RMMI_NEED_SET_TEST_NUM, "Need to set Ecall test num")
   TRC_MSG(FUNC_RMMI_NEED_SET_RECONFIGURATION_NUM, "Need to set Ecall reconfiguration num")


   /*GPRS*/
   TRC_MSG(WARNING_DISALLOW_GPRS_DIALUP_WHEN_MS_BUSY, "Warning: disallow gprs dialup when MS is busy")
   TRC_MSG(WARNING_RMMI_GPRS_STRING_VALID_CMD_NOT_ALLOWED, "Warning: gprs string valid ,but cmd not allowed")
   
   /* EQ/EM */
   TRC_MSG(WARNING_EQ_FS_RETURN_ERROR, "Warning: EQ fs action: %d return: %d")
   TRC_MSG(WARNING_THERMAL_PROT_RETURN_ERROR, "Warning: thermal_prot_set_threshold return error")

   /* -------------------------------------------TRACE_ERROR trace class------------------------------------------- */
   TRC_MSG(READ_FROM_UART_INCORRECT_OWNER, "read_from_uart .current owner=%d")
   TRC_MSG(READ_FROM_UART_INVALID_CHANNEL, "read_from_uart invalid channel")
   TRC_MSG(ERROR_INVALID_PORT , "Invalid port !")
   TRC_MSG(ERROR_CHECK_KEY_PAD, "Error: The output from custom_check_keypad_code() is invalid")
   TRC_MSG(ERROR_EXTRACT_NUMBER_FUNCTION_ILLEGAL_CHARACTER_ERROR, "Error: extract number function: illegal character  ERROR")
   TRC_MSG(ERROR_RMMI_INVALID_NUMBER, "number containing invalid char %c")
   TRC_MSG(ERROR_RMMI_ROOT_FIND_SRC_PORT_MAPPING, "[RMMI_ROOT] Could not find empty source/port mapping")

   /* -------------------------------------------TRACE_GROUP_1, For CC/SS/CTM---------------------------------------- */
   TRC_MSG(RMMI_CIEV, "CIEV: %d, %d")
   TRC_MSG(CTMI, "+CTMI")
   TRC_MSG(TIYI, "+TTYI: %d")
   TRC_MSG(CTMS, "+CTMS: %d, %d")
   TRC_MSG(CTMSET, "+CTMSET: %d, %d")
   TRC_MSG(CTMCFG, "+CTMCFG: %u, %u, %u, %u, %u")

   /* -------------------------------------------TRACE_GROUP_2, For GPRS--------------------------------------------- */

   /* -------------------------------------------TRACE_GROUP_3, For EQ/EM-------------------------------------------- */

   /* -------------------------------------------TRACE_GROUP_4, For SMS/PHB------------------------------------------ */

   /* -------------------------------------------TRACE_GROUP_5, For NW/SMU/HZ---------------------------------------- */

   /* -------------------------------------------TRACE_GROUP_6, For CID and PORT------------------------------------- */

   /* -------------------------------------------TRACE_GROUP_7, For GATI--------------------------------------------- */
   /*gati*/
   TRC_MSG(GATI_RECEIVE_RTR_FROM_UART, "GATI waits for the reply from the APP")
   TRC_MSG(GATI_NOT_WRITE_ALLOW, "GATI NOT WRITE ALLOW current_src_id=%d")
   TRC_MSG(GATI_WRITE_RMMI_ALL_FAIL, "GATI write RMMI_ALL fail, remain_size: %d, data size: %d, cid: %d")
   TRC_MSG(GATI_WRITE_INTEGRITY_FAIL, "GATI write integrity(URC) data fail, remain_size: %d, data size: %d, cid: %d")
   TRC_MSG(GATI_INPUT_DATA_IN_BINARY_MODE, "GATI input data in binary mode")
   TRC_MSG(GATI_OUTPUT_NON_GATI_DATA, "GATI output non-GATI data")
   TRC_MSG(GATI_NEED_SEND_RTW_IND, "GATI need to send RTW indication to the APP")
   TRC_MSG(GATI_BUFFER_FULL, "GATI linked-list buffer is full")
   TRC_MSG(GATI_REGISTER_FAIL, "GATI Can't not find an empty entry. Please increase GATI_MAX_MODULE_COUNT")

   /* -------------------------------------------TRACE_GROUP_8, For MISC--------------------------------------------- */

   /* -------------------------------------------TRACE_GROUP_9, For XXXXXX------------------------------------------- */

   /* -------------------------------------------TRACE_GROUP_10, For XXXXXX------------------------------------------ */


END_TRACE_MAP(MOD_ATCI)
#endif


