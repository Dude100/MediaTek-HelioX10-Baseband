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
 * rmmi_utility.h
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef _RMMI_UTILITY_H
#define _RMMI_UTILITY_H

//#include "kal_non_specific_general_types.h"
#include "rmmi_context.h"
//#include "l4c_aux_struct.h"
#include "rmmi_common_enum.h"
//#include "app_ltlcom.h"
//#include "l4c2uem_struct.h"
#include "kal_general_types.h"
#include "ps_public_struct.h"
#include "l4crac_enums.h"

#define rmmi_int_validator_u8_check(error_cause, source_string_ptr, delimiter) \
                (kal_uint8)rmmi_int_validator_range_check( \
                                        error_cause, \
                                        source_string_ptr, \
                                        delimiter, \
                                        0xff)
                                    
#define rmmi_int_validator_u16_check(error_cause, source_string_ptr, delimiter) \
                (kal_uint16)rmmi_int_validator_range_check( \
                                        error_cause, \
                                        source_string_ptr, \
                                        delimiter, \
                                        0xffff)
                                        
#define rmmi_int_validator_u32_check(error_cause, source_string_ptr, delimiter) \
                (kal_uint32)rmmi_int_validator_range_check( \
                                        error_cause, \
                                        source_string_ptr, \
                                        delimiter, \
                                        0xffffffff)
                                        
extern kal_bool rmmi_open_uart_port(UART_PORT port, UART_BAUDRATE_T baud_rate);

extern kal_bool rmmi_check_port_ownership(DCL_DEV port, module_type* port_owner);

extern void rmmi_obtain_uart_control(kal_uint8 port, kal_bool plugout);

extern void rmmi_clear_uart_queue(kal_uint8 cid); 

extern kal_bool rmmi_is_number_string(kal_uint8 *str);

extern kal_uint32 rmmi_int_validator(rmmi_string_struct *source_string_ptr, kal_uint8 delimiter);

extern kal_uint32 rmmi_int_validator_ext(
                    kal_uint8 *error_cause,
                    rmmi_string_struct *source_string_ptr,
                    kal_uint8 delimiter);

//mtk02508 MAUI_01740414
extern kal_uint32 rmmi_int_validator_range_check(
                    kal_uint8 *error_cause, 
                    rmmi_string_struct *source_string_ptr, 
                    kal_uint8 delimiter, 
                    kal_uint32 max);

extern kal_int32 rmmi_signed_int_validator(
                    kal_uint8 *error_cause,
                    rmmi_string_struct *source_string_ptr,
                    kal_uint8 delimiter);

extern kal_uint8 rmmi_hex_validator_ext(
                    kal_uint8 *error_cause,
                    rmmi_string_struct *source_string_ptr,
                    kal_uint8 delimiter,
                    kal_uint16 max_length,
                    kal_uint8 *str);

extern kal_uint8 rmmi_string_validator(
                    rmmi_string_struct *source_string_ptr,
                    kal_uint8 delimiter,
                    kal_uint16 max_length,
                    kal_uint8 *str);

extern kal_uint8 rmmi_string_validator_ext(
                    kal_uint8 *error_cause,
                    rmmi_string_struct *source_string_ptr,
                    kal_uint8 delimiter,
                    kal_uint16 max_length,
                    kal_uint8 *str);

#if defined(__SIM_MMDS_CLIENT__)
kal_uint8 rmmi_mmdc_filter_out_string(kal_uint8 *error_cause,
                                      rmmi_string_struct *source_string_ptr,
                                      kal_uint8 delimiter,
                                      kal_uint16 max_length,
                                      kal_uint8 *str);

kal_uint16 rmmi_mmdc_get_path_length(kal_uint8 *path, 
                                     kal_uint16 length);
#endif

extern kal_uint8 rmmi_filename_validator(
                    kal_uint8 coding_scheme,
                    rmmi_string_struct *source_string_ptr,
                    kal_uint8 delimiter,
                    kal_uint16 max_length,
                    kal_wchar *filename,
                    kal_uint16 *filename_length,
                    kal_uint8 *error_cause);

extern kal_uint8 rmmi_sms_text_validator(
                    rmmi_string_struct *source_string_ptr,
                    kal_uint8 delimiter,
                    kal_uint16 max_length,
                    kal_uint8 *str);

extern kal_uint8 rmmi_find_cmd_mode(rmmi_string_struct *source_string_ptr);

extern kal_uint8 check_facility_type(kal_uint8 *fac);

extern kal_uint8 check_chld_opcode(kal_uint8 input, kal_uint8 *call_id);

extern void check_pin_name(kal_uint8 type, kal_uint8 *name);

extern kal_bool check_ppu_value(kal_uint8 *input, kal_uint8 *output);

extern void check_ppu_string(kal_uint8 *input, kal_uint8 *output);

extern void check_phb_storage_name(kal_uint8 storage, kal_uint8 *code);

extern kal_uint8 check_phb_storage_code(kal_uint8 *name);

extern void check_nw_class_name(kal_uint8 storage, kal_uint8 *code);

extern kal_uint8 check_nw_class_code(kal_uint8 *name);

extern kal_uint8 check_bscode_class(kal_uint8 bscode);

extern kal_uint8 check_bscode_L4enum(kal_uint8 classx);

extern kal_uint8 check_dcs_toGsm7bit(kal_uint8 *src_text, kal_uint8 *dest_text);

extern void check_dcs_toCscs(kal_uint8 dcs, kal_uint16 length, kal_uint8 *data, kal_uint8 *ch_str);

extern kal_uint8 Gsm7bit_default_ext_value_to_ascii(kal_uint8 gsm7bit_ext_value);

extern kal_wchar Gsm7bit_default_ext_value_to_UCS2(kal_uint8 gsm7bit_ext_value);

extern kal_wchar Gsm7bit_greece_char_to_UCS2(kal_uint8 gsm7bit_greece);

extern void rmmi_decode_cbsdcs(
                kal_uint8 dcs,
                kal_uint8 *lang_type,
                kal_uint8 *alphabet_type,//smsal_dcs_enum
                kal_uint8 *msg_class,//smsal_msg_class_enum
                kal_bool *is_compress,
                kal_bool *is_reserved);

extern void check_sms_storage_name(kal_uint8 storage, kal_uint8 *code);

extern kal_uint8 check_sms_storage_code(kal_uint8 *name);

extern void check_sms_scts(kal_uint8 *dest, kal_uint8 *scts);

extern kal_uint8 parse_dcs_list(rmmi_string_struct *source, kal_uint16 *list);

extern kal_bool parse_int_list(
                    kal_bool mode,
                    kal_uint8 total_mid_num,
                    kal_uint8 total_mir_num,
                    rmmi_string_struct *source,
                    l4c_cb_info_struct *info);

extern void check_char_set_name(kal_uint8 chset, kal_uint8 *chset_str);

extern kal_uint8 check_char_set_code(kal_uint8 *chset_str);

extern kal_uint8 check_sms_mem_code(kal_uint8 *mem_str);

extern kal_uint8 check_sms_status_code(kal_uint8 *status_str);

//extern kal_bool check_lan_code(kal_uint8 *lan_code);

//extern void check_auto_lan_code (kal_uint8 *lan_code);

extern kal_uint8 check_language_code(kal_uint8 *lan_name);

extern kal_bool check_language_name(kal_uint8 lan_code, kal_uint8 *lan_name);

extern void check_sms_mem_name(kal_uint8 code, kal_uint8 *name);

extern void check_sms_status_name(kal_uint8 code, kal_uint8 *name);

extern kal_bool check_keypad_code(kal_uint8 *key, kal_uint8 *keycode);

extern kal_bool convert_keypad_code(kal_uint8 keycode, kal_uint8 *key);

extern void check_pdp_type_name(kal_uint8 code, kal_uint8 *str);

extern kal_uint8 check_pdp_type_code(kal_uint8 *str);

//  MAUI_02555586 mtk02126 refine check_dotted_value8
extern kal_uint8 check_dotted_value8(kal_uint8 *str, kal_uint8 *val, kal_uint32 val_len);

extern void rmmi_value2string(kal_char *str, kal_uint8 *val, kal_uint8 cnt);

extern void rmmi_u8_to_dotstring(kal_uint8 *val, kal_uint8 *str, kal_uint8 length);

extern void rmmi_u16_to_dotstring(kal_uint16 *val, kal_uint8 *str, kal_uint8 length);

extern kal_bool rmmi_hexstring_to_integer(kal_uint8 *str, kal_uint32 *val);

extern void check_dotted_string8(kal_uint8 *val, kal_uint8 *str);

// MAUI_02555586 mtk02126 refine check_dotted_value16
extern kal_uint8 check_dotted_value16(kal_uint8 *str, kal_uint16 *val, kal_uint32 val_len);

extern void check_dotted_string16(kal_uint16 *str, kal_uint8 *val);

extern void check_hex_value(kal_uint8 *str, kal_uint8 *val);

extern void check_emsd_hex_value(kal_uint8 *str, kal_uint8 *val);


extern kal_bool string_is_pure_ascii(kal_uint8 *str, kal_uint8 *val, kal_uint8 dcs);  

extern kal_bool check_hex_value_ext(kal_uint8 *str, kal_uint8 *val);

extern void print_hex_value(kal_uint8 *val, kal_uint8 *str);

extern void print_hex_value_ext(kal_uint8 *val, kal_uint8 *str, kal_uint8 length);

extern void rmmi_print_ucs2(kal_uint8 *val, kal_uint8 *str);
extern void rmmi_unicode_to_string(kal_uint8 *val, kal_uint8 *str);

extern void rmmi_byte_order_reverse(kal_uint8 *src, kal_uint16 length);

extern void check_sms_pdu_string(kal_uint16 len, kal_uint8 *bytes, kal_uint8 *str);

extern kal_uint32 rmmi_extract_number(rmmi_string_struct *source_string_ptr, rmmi_validator_cause_enum *result, kal_uint32 max);

kal_uint32 rmmi_extract_number_ext(rmmi_string_struct *source_string_ptr, rmmi_validator_cause_enum *result, kal_uint32 max);

extern kal_uint8 extract_number_string(
                    rmmi_string_struct *source_string_ptr,
                    kal_uint8 delimiter,
                    kal_uint8 *ss_string,
                    kal_uint8 max_length);

extern void rmmi_skip_leading_chars(rmmi_string_struct *source_string_ptr);

extern void ascii_to_ucs2(kal_uint8 *src, kal_wchar *dest);

extern kal_bool ucs2_to_ascii(kal_wchar *ucs2_src, kal_uint8 *ascii_dest);

extern kal_bool is_sms_command(kal_uint8 *data, kal_uint16 length);

extern kal_bool is_sms_standard_command(kal_uint8 *data);

extern kal_bool is_sms_mode_correct(kal_uint8 *data, kal_uint16 length);

extern kal_bool rmmi_is_cfunoff_command(kal_uint8 *data, kal_uint8 length);


//extern kal_bool is_sms_msg_cmd(void);

extern void rmmi_ring_repeat_hdlr(void);

/* Begin: mtk00714 +CASP */
extern void rmmi_casp_playaudio_timeout_hdlr(void *arg);

extern void rmmi_reset(void);

extern void rmmi_write_to_buffer(void *buffer_ptr, kal_uint8 *buffer, kal_uint16 length, kal_bool stuff);
extern void rmmi_write_unsolicitedResultCode(
                kal_uint8 *buffer,
                kal_uint16 length,
                kal_bool stuff,
                kal_uint8 mode,
                void *buffer_ptr);
extern void rmmi_write_unsolicitedResultCode_plus(
                kal_uint8 *buffer,
                kal_uint16 length,
                kal_bool stuff,
                kal_uint8 mode,
                void *buffer_ptr);
extern void rmmi_flush_ResultCodeBuffer(void *buffer_ptr, kal_bool flush);

extern void l4c_em_status_to_ccsr(kal_uint8 mod_id, kal_uint32 em_info, peer_buff_struct *info);       //mtk00468 add for CCSR 

#ifdef __MOD_UEM__
extern void rtc_to_string_format(kal_uint8 *buf, kal_uint8 date_mode, kal_uint8 time_mode, rtc_format_struct *rtc);

extern kal_bool string_to_rtc_format(rtc_format_struct *rtc, kal_uint8 *s);
#endif /* __MOD_UEM__ */ 

extern kal_uint8 rmmi_cid_2_srcid(kal_uint8 cid);
extern kal_uint8 rmmi_srcid_2_cid(kal_uint8 src_id);
extern kal_uint8 rmmi_cid_2_port(kal_uint8 cid);
extern kal_uint8 rmmi_port_2_cid(kal_uint8 port);
extern kal_bool rmmi_check_online_cid(kal_uint8 cid);
extern kal_bool rmmi_cpbr_read(kal_uint8 src_id, kal_uint8 storage, kal_uint16 index, kal_uint16 index2);
extern void rmmi_start_ath_for_dialup_hdlr(kal_uint8 port);
extern void rmmi_clear_ath_for_dialup_hdlr(void);

#ifndef __test_mode__
extern kal_bool rmmi_need_enter(kal_uint16 cmd);    /* mtk00924 20050222 for __test_mode__ modification */
#endif 
void rmmi_gsm7bit_to_IRA(kal_uint8 *src, kal_uint8 *des, kal_uint16 src_len, kal_uint8 des_len);

extern kal_bool check_cmd_allow(kal_uint16 cmd_code);
extern kal_bool check_cmd_with_pin(kal_uint16 cmd_code);
extern kal_bool is_sim_verified(void);
extern kal_bool is_nw_registered(void);

extern kal_bool rmmi_bt_str_validator(
                    rmmi_string_struct *source_string_ptr,
                    kal_uint8 delimiter,
                    kal_uint16 max_length,
                    kal_uint8 *str,
                    kal_bool skip_bs);
extern kal_bool rmmi_bt_hex_validator(
                    rmmi_string_struct *source_string_ptr,
                    kal_uint8 delimiter,
                    kal_uint16 maxlen,
                    kal_uint8 *addr);

extern kal_uint16 rmmi_convert_l3_cause(kal_uint16 ps_cause);
extern kal_uint8 check_g3_service_class_code(kal_uint8 fclass_mode);

extern void toUpper(kal_uint8 *str);

extern void rmmi_view_profile(rmmi_profile_struct *profile_ptr);
extern kal_uint8 rmmi_current_access_technology(rat_enum rat, l4c_data_speed_support_enum cell_data_speed, l4c_data_bearer_capablility_enum max_data_bearer_capa);

extern kal_uint8 rmmi_ira_toGsm7bit(kal_uint8 src_text, kal_uint8 *des_text);
extern kal_bool check_UCS2_toGsm7bit(kal_uint8 *src_text, kal_uint8 src_len, kal_uint8 *dest_text, kal_uint8 *des_len);
extern kal_uint8 check_IRA_toGsm7bit(kal_uint8 *src_text, kal_uint8 *dest_text);

extern void rmmi_get_phb_length(kal_uint8 *alpha_length, kal_uint8 *num_length);
extern kal_bool rmmi_is_valid_phb_storage(rmmi_phb_type_enum storage);
extern phb_storage_enum rmmi_phb_get_sim_storage_by_current_module(void);

#ifdef __UCM_SUPPORT__
extern void rmmi_reset_ring_count(void);
#endif

extern kal_bool rmmi_check_ussd_length(kal_uint16 length, kal_uint8 *ussd_str); //DUMA00158731

extern phb_type_enum rmmi_epbum_type_to_phb_type(rmmi_epbum_ef_type_enum epbum_type);
extern rmmi_epbum_ef_type_enum rmmi_phb_type_to_epbum_type(phb_type_enum phb_type);

extern kal_uint32 l4c_copy_mini_log(char *dst_buf,kal_uint32 bytes);

extern reg_state_enum rmmi_convert_atci_state_to_reg(rmmi_reg_state_enum rmmi_state);

extern rmmi_reg_state_enum rmmi_convert_reg_state_to_atci(reg_state_enum old_state);

#ifdef __ATCI_QUEUE_AT__
extern kal_bool rmmi_is_action_conducting(kal_uint8 src_id);
extern kal_bool rmmi_need_clear_route_lmmi(); 
#endif

extern void rmmi_wakeup_md_timeout_hdlr(void);
extern void rmmi_wakeup_ap_timeout_hdlr(void);
extern void rmmi_start_wakeup_timer_hdlr(rmmi_wakeup_type_enum wake_up);
extern void rmmi_eint0_hdlr(void);
extern void rmmi_l1aud_spc_callback(kal_uint32 param1, void* param2);

extern void rmmi_convert_syssel_band(kal_uint8 gsm_band, kal_uint16 umts_band, kal_uint32 *band_map);

extern void rmmi_get_syssel_band(kal_uint8 band, 
                                 kal_uint8 *gsm_band, 
                                 kal_uint16 *umts_band);

#ifdef __SMART_PHONE_MODEM__//__AGPS_SUPPORT__
extern void rmmi_lbs_send_data(kal_int16 type, kal_uint8* data, kal_int16 length);
#endif

#ifdef __IMS_SUPPORT__
extern kal_bool atci_imsp_cmd_ind(kal_uint8 src_id, kal_uint8 *cmd_str, kal_uint16 length);
extern void atci_imsp_cmd_rsp_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void atci_imsp_urc_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern kal_bool atci_imsp_urc_ind(kal_uint8 *cmd_str, kal_uint16 length, kal_bool stuff);
extern void atci_imsp_cmd_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void atci_imsp_cmd_cnf(kal_uint8 src_id, kal_uint8 result, kal_uint8 *cmd_str, kal_uint16 length, kal_bool stuff);
extern void atci_imsp_result_code_fmttr(kal_uint8 src_id, kal_uint8 rsp_type, kal_uint8 *cmd_str, kal_uint16 length, kal_bool stuff);
extern void atci_imsp_write_to_uart(kal_uint8 current_src, kal_uint8 *buffer, kal_uint16 length, kal_bool stuff);
#endif

#endif /* _RMMI_UTILITY_H */

