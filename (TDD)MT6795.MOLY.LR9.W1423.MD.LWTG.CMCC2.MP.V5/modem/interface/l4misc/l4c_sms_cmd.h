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
 * l4c_sms_cmd.h
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _L4C_SMS_CMD_H
#define _L4C_SMS_CMD_H

//#include "kal_non_specific_general_types.h"
#include "l4c_aux_struct.h"
#include "mcd_l4_common.h"
#include "smsal_l4c_enum.h"
#include "l4c2smsal_struct.h"
#include "rmmi_common_enum.h"
#include "kal_general_types.h"
#include "ps_public_struct.h"
#include "ps_public_enum.h"
    
extern kal_bool l4c_sms_set_profile_params_req(
                    kal_uint8 src_id,
                    kal_uint16 para_ind,
                    kal_uint8 profile_no,
                    kal_uint8 pid,
                    kal_uint8 dcs,
                    kal_uint8 vp,
                    l4c_number_struct sc_addr,
                    l4_name_struct profile_name);

extern kal_bool l4c_sms_get_profile_params_req(
                    kal_uint8 src_id,
                    kal_uint8 profile_no,
                    kal_uint8 *pid,
                    kal_uint8 *dcs,
                    kal_uint8 *vp,
                    l4c_number_struct *sc_addr,
                    l4_name_struct *profile_name);

extern kal_bool l4c_sms_set_common_params_req(
                    kal_uint8 src_id,
                    kal_uint16 para_ind,
                    kal_uint8 fo,
                    kal_uint8 bearer_service,
                    kal_uint8 status_report,
                    kal_uint8 reply_path);

extern kal_bool l4c_sms_get_common_params_req(
                    kal_uint8 src_id,
                    kal_uint8 *fo,
                    kal_uint8 *bearer_service,
                    kal_uint8 *status_report,
                    kal_uint8 *reply_path);

extern kal_bool l4c_sms_startup_read_next_req(kal_uint8 src_id);

extern kal_bool l4c_sms_set_bearer_service_req(kal_uint8 src_id, kal_uint8 bearer);

extern void l4c_sms_get_bearer_service_req(kal_uint8 src_id, kal_uint8 *bearer);

extern kal_bool l4c_sms_exe_post_command_req(
                    kal_uint8 src_id,
                    kal_uint8 fo,
                    kal_uint8 ct,
                    kal_uint8 mn,
                    kal_uint8 pid,
                    l4c_number_struct dest,
                    kal_uint8 length,
                    kal_uint8 *cmd);

extern kal_bool l4c_sms_exe_post_command_pdu_req(
                    kal_uint8 src_id,
                    kal_uint16 data_len,
                    kal_uint16 length,
                    kal_uint8 *pdu);

extern kal_bool l4c_sms_exe_delete_msg_req(
                    kal_uint8 src_id,
                    kal_uint8 del_flag,
                    kal_uint16 index,
                    kal_uint8 *del_bitmap);

extern kal_bool l4c_sms_set_msg_format_req(kal_uint8 src_id, kal_uint8 format);

extern void l4c_sms_get_msg_format_req(kal_uint8 src_id, kal_uint8 *format);

extern kal_bool l4c_sms_exe_read_msg_list_req(
                    kal_uint8 src_id,
                    kal_uint8 change_status,
                    kal_uint8 status,
                    kal_uint16 start_index,
                    kal_uint8 no_msg);

extern kal_bool l4c_sms_exe_emgl_list_req(
                    kal_uint8 src_id,
                    kal_uint8 change_status,
                    kal_uint8 status,
                    kal_uint16 start_index,
                    kal_uint8 no_msg);

extern kal_bool l4c_sms_send_from_storage_req(
                    kal_uint8 src_id,
                    kal_uint16 index,
                    kal_bool addr_present,
                    l4c_number_struct da,
                    kal_uint8 profile_no_tag,
                    kal_uint8 profile_no);

extern kal_bool l4c_sms_set_status_req(
                    kal_uint8 src_id,
                    kal_uint8 new_status,
                    kal_uint16 index);

extern kal_bool l4c_sms_exe_read_msg_req(kal_uint8 src_id, kal_uint16 index, kal_bool change_status);

extern kal_bool l4c_sms_exe_post_msg_req(
                    kal_uint8 src_id,
                    kal_uint8 profile,
                    kal_uint16 reply_index,
                    l4c_number_struct dest,
                    kal_uint16 para,
                    l4c_number_struct sc_addr,
                    kal_uint8 vp,
                    smsal_pid_enum pid,
                    kal_uint8 udhi,
                    smsal_dcs_enum dcs,
                    kal_uint16 length,
                    kal_uint8 *msg,
                    kal_uint8 seq_num,
                    kal_uint8 mms_mode,
                    kal_uint8 tp_srr,
                    kal_uint8 tp_rp);

extern kal_bool l4c_sms_exe_post_pdu_req(
                    kal_uint8 src_id,
                    kal_uint16 reply_index,
                    kal_uint16 data_len,
                    kal_uint8 source_id,
                    kal_uint8 seq_num,
                    kal_uint8 mms_mode,
                    kal_uint16 length,
                    kal_uint8 *pdu);

extern kal_bool l4c_sms_exe_write_msg_req(
                    kal_uint8 src_id,
                    kal_uint8 profile,
                    kal_uint8 status,
                    l4c_number_struct dest,
                    kal_uint16 para,
                    l4c_number_struct sc_addr,
                    kal_uint8 *scts,
                    kal_uint8 vp,
                    kal_uint8 pid,
                    kal_uint8 udhi,
                    kal_uint8 dcs,
                    kal_uint16 index,
                    kal_uint16 length,
                    kal_uint8 *msg,
                    kal_uint8 tp_srr,
            	    kal_uint8 tp_mms,
                    kal_uint8 tp_rp,
                    kal_uint8 tp_sri);

extern kal_bool l4c_sms_exe_write_pdu_req(
                    kal_uint8 src_id,
                    kal_uint8 status,
                    kal_uint16 data_len,
                    kal_uint16 length,
                    kal_uint8 *pdu);

extern kal_bool l4c_sms_set_more_req(kal_uint8 src_id, kal_uint8 mode);

extern void l4c_sms_get_more_req(kal_uint8 src_id, kal_uint8 *mode);

extern kal_bool l4c_sms_exe_storage_post_req(
                    kal_uint8 src_id,
                    kal_uint16 index,
                    kal_uint16 reply_index,
                    kal_bool addr_present,
                    l4c_number_struct dest,
                    kal_uint8 profile_no_tag,
                    kal_uint8 profile_no);

extern kal_bool l4c_sms_set_msg_ind_mode_req(
                    kal_uint8 src_id,
                    kal_uint8 mode,
                    kal_uint8 mt,
                    kal_uint8 bm,
                    kal_uint8 ds);

extern void l4c_sms_get_msg_ind_mode_req(
                    kal_uint8 src_id,
                    kal_uint8 *mode,
                    kal_uint8 *mt,
                    kal_uint8 *bm,
                    kal_uint8 *ds);

extern kal_bool l4c_sms_exe_send_ack_req(kal_uint8 src_id, kal_uint8 mode, kal_uint16 length, kal_uint8 *ack);

extern kal_bool l4c_sms_set_preferred_mem_req(kal_uint8 src_id, kal_uint8 mem1, kal_uint8 mem2, kal_uint8 mem3);

extern void l4c_sms_get_preferred_mem_req(kal_uint8 src_id, smsal_prefer_storage_struct *info);

#ifndef __SMS_STORAGE_BY_MMI__
extern kal_bool l4c_smsal_eqsi_query(
	                  rmmi_smsal_storage_enum  mem, 
                          kal_uint16 	    *beg_index,
                          kal_uint16	    *end_index,
                          kal_uint16          *used);
#endif
extern kal_bool l4c_sms_set_service_mode_req(kal_uint8 src_id, kal_uint8 mode);

extern void l4c_sms_get_service_mode_req(kal_uint8 src_id, kal_uint8 *mode, smsal_service_mode_struct *info);

extern kal_bool l4c_sms_get_no_msgs_req(
                    kal_uint8 src_id,
                    //kal_bool  *is_sms_ready,
                    kal_bool *is_sim_card_change,
                    kal_uint16 *in_sim_no,
                    kal_uint16 *in_me_no,
                    kal_uint16 *out_sim_no,
                    kal_uint16 *out_me_no,
                    kal_uint16 *unread_msg_num,
                    kal_uint16 *total_sim_num,
                    kal_uint16 *total_me_num);

extern kal_bool l4c_sms_get_no_profiles_req(kal_uint8 src_id, kal_uint8 *profile_no, kal_uint8 *name_len);
#if 0
/* under construction !*/
#endif
extern void l4c_sms_get_sc_addr_req(kal_uint8 src_id, kal_uint8 profile_no, l4c_number_struct *sc_addr);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
extern void l4c_sms_get_post_params_req(
                    kal_uint8 src_id,
                    kal_uint8 profile_no,
                    kal_uint8 *fo,
                    kal_uint8 *pid,
                    kal_uint8 *dcs,
                    kal_uint8 *vp,
                    l4_name_struct *profile_name);
/*
 * extern kal_bool l4c_sms_exe_load_profile_req (kal_uint8 src_id,
 * kal_uint8 index);
 * 
 * extern kal_bool l4c_sms_exe_save_profile_req (kal_uint8 src_id,
 * kal_uint8 index);
 */
#if 0 
/* under construction !*/
#endif
extern kal_bool l4c_cb_subscribe_req(kal_uint8 src_id, kal_uint8 on_off);

extern kal_bool l4c_sms_set_cb_mode_req(kal_uint8 src_id, l4c_cb_info_struct *info);

extern kal_bool l4c_sms_get_cb_mode_req(
                    kal_uint8 src_id,
                    kal_uint8 *mode,
                    kal_uint8 *total_mid_num,
                    kal_uint8 *total_mir_num,
                    kal_uint8 *total_dcs_num,
                    l4c_cb_info_struct *info);

extern void l4c_sms_cb_msg_removal_req(kal_uint16 mid, kal_uint16 sn);


extern void l4c_sms_exe_abort_req(kal_uint8 src_id, kal_uint8 seq_num);

extern kal_bool l4c_sms_get_mailbox_addr_req(kal_uint8 src_id);

extern kal_bool l4c_sms_set_mailbox_addr_req(
                    kal_uint8 src_id,
                    kal_uint8 mailbox_num,
                    l4c_number_struct num_addr,
                    l4_name_struct name);

// R4/R5 SMS
extern kal_bool l4c_sms_set_mbi_req(kal_uint8 src_id, kal_uint8 msp_no, smsal_mbi_struct mbi);
extern kal_bool l4c_sms_get_mbi_req(kal_uint8 src_id, kal_uint8 *msp_num, smsal_mbi_struct *mbi);
extern kal_bool l4c_sms_set_msp_req(kal_uint8 src_id, kal_uint8 msp_no);
extern kal_bool l4c_sms_get_msp_req(kal_uint8 src_id, kal_uint8 *msp_no);

extern kal_bool l4c_smsal_init_me_sms_req(kal_uint8 src_id,kal_uint8 init_type);

extern kal_bool l4c_sms_reg_port_num_req(
                    kal_uint8 src_id,
                    kal_bool enable,
                    kal_uint32 port_num,
                    kal_uint16 mod_id,
                    kal_uint16 *cause,
                    kal_uint32 *ret_port_num,
                    kal_uint16 *ret_mod_id,
                    kal_uint8 *ret_source_id);

extern void l4c_sms_set_rmmi_sc_addr_req(kal_uint8 src_id, l4c_number_struct sc_addr);

extern kal_bool l4c_sms_set_rmmi_post_params_req(
                    kal_uint8 src_id,
                    kal_uint8 profile_no, //dummy
                    kal_uint16 para_ind,
                    kal_uint8 fo,
                    kal_uint8 pid,
                    kal_uint8 dcs,
                    kal_uint8 vp);

extern void l4c_sms_exe_save_settings_req(kal_uint8 src_id, kal_uint8 profile_id);

extern void l4c_sms_exe_restore_settings_req(kal_uint8 src_id, kal_uint8 profile_id);

extern kal_bool l4c_smsal_read_raw_data_req(kal_uint8 src_id, kal_uint16 index);
extern kal_bool l4c_smsal_write_raw_data_req(kal_uint8 src_id, kal_uint8 storage_type,kal_uint16 data_len,kal_uint8 *data);

extern void l4c_smsal_fdn_check_rsp(kal_uint8 result, kal_uint16 cause);

extern kal_bool l4c_sms_copy_msg_req(kal_uint8 src_id, kal_uint8 action, kal_uint8 dst_storage, kal_uint16 src_index);

extern void l4c_sms_sync_msg_res_req(kal_bool result);

extern kal_bool l4c_sms_exe_send_smma_req(kal_uint8 src_id);
extern kal_bool l4c_sms_exe_set_msg_waiting_req(kal_uint8 src_id,kal_uint8  line_no,kal_uint8  waiting_num,kal_uint8  ind_type);

extern void l4c_sms_usm_general_rcode_req(
		kal_uint8 src_id,
		rmmi_usm_atcmd_enum atcmd_type,
		kal_uint32 atcmd_index,
		rmmi_usm_message_stat_enum tag_type,
		kal_bool iscomplete,
		kal_uint8 pdu_length,
		kal_uint8 *pdu,
		l4c_usm_cnmi_struct cnmi_parameter,
		l4c_usm_cmss_struct cmss_struct,
		kal_uint8 result,
		kal_uint16 cause);

extern void l4c_sms_sync_msg_storage_req(
			kal_uint8 src_id,
			kal_uint32 sm_max_num, 
			kal_uint32 sm_current_num, 
			kal_uint32 me_max_num, 
			kal_uint32 me_current_num, 
			kal_uint32 sr_max_num, 
			kal_uint32 sr_current_num); 

extern kal_bool l4c_sms_send_deliver_report_req(kal_uint8 src_id,kal_uint8 result,kal_uint32 error_cause, kal_uint8 mem, kal_uint32 index, kal_uint8 uid, kal_uint8 msg_class, kal_bool is_msg_wait, kal_uint8 msg_wait_store);
extern kal_bool l4c_sms_startup_read_res_req(kal_uint8 src_id);
extern kal_bool l4c_sms_get_mem_status_res_req(kal_uint8 src_id,kal_uint32 sim_max_num,kal_uint32 sim_current_num,kal_uint32 me_max_num,kal_uint32 me_current_num,kal_uint32 sr_max_num,kal_uint32 sr_current_num,kal_uint8 source_id);
extern kal_bool l4c_sms_mem_status_req(kal_uint8 src_id,kal_uint8 mem_status);
extern kal_bool l4c_sms_atcmd_cmgr_res_req(kal_uint8 src_id,kal_uint8 result,kal_uint16 cause,kal_uint8 source_id,kal_uint8 mem, kal_uint32 index, kal_uint8 stat, kal_uint16 pdu_length, kal_uint8 *pdu);
extern kal_bool l4c_sms_atcmd_cmgl_res_req(kal_uint8 src_id,kal_uint8 mem, kal_uint32 index, kal_uint8 stat, kal_uint16 pdu_length, kal_uint8 *pdu, kal_uint8 result,kal_uint16 cause, kal_uint8 is_complete, kal_uint8 source_id);
extern kal_bool l4c_sms_atcmd_cmgd_res_req(kal_uint8 src_id,kal_uint8 result, kal_uint16 cause, kal_uint8 source_id);
extern kal_bool l4c_sms_atcmd_cmgw_res_req(kal_uint8 src_id,kal_uint32 index, kal_uint8 result, kal_uint16 cause, kal_uint8 source_id);
extern kal_bool l4c_sms_atcmd_eqsi_res_req(kal_uint8 src_id,kal_uint8 mem, kal_uint32 begin, kal_uint32 end, kal_uint32 used, kal_uint8 source_id);

extern kal_bool l4c_sms_etws_setting_req(kal_uint8 src_id, kal_bool is_etws_needed, kal_bool is_etws_security_needed, kal_bool is_etws_testing_on, kal_bool write_to_nvram);

/* __IMS_SUPPORT__ */
extern kal_bool l4c_sms_ims_exe_submit_pdu_req(kal_uint8 src_id, kal_uint16 data_len, kal_uint16 length, kal_uint8 *pdu);

extern kal_bool l4c_sms_ims_exe_submit_text_req(kal_uint8 src_id, kal_uint8 profile, kal_uint16 reply_index, l4c_number_struct dest, kal_uint16 para, l4c_number_struct sca, kal_uint8 vp, smsal_pid_enum pid, kal_uint8 udhi, smsal_dcs_enum dcs, kal_uint16 length, kal_uint8 *msg, kal_uint8 seq_num, kal_uint8 mms_mode, kal_uint8 tp_srr, kal_uint8 tp_rp);

extern kal_bool l4c_sms_ims_exe_command_pdu_req(kal_uint8 src_id, kal_uint16 data_len, kal_uint16 length, kal_uint8 *pdu);

extern kal_bool l4c_sms_ims_exe_command_text_req(kal_uint8 src_id, kal_uint8 fo, kal_uint8 ct, kal_uint8 mn, kal_uint8 pid, l4c_number_struct dest, kal_uint16 length, kal_uint8 *cmd);

extern kal_bool l4c_sms_ims_exe_mt_pdu_req(kal_uint8 src_id, kal_uint16 pdu_len, kal_uint8 *pdu_ptr);

extern kal_bool l4c_sms_ims_exe_smma_req(kal_uint8 src_id, kal_uint8 op, kal_uint8 is_full);
#endif /* _L4C_SMS_CMD_H */ 
