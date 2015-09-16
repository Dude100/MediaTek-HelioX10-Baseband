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
 * RMMI_MSGHDLR.H
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   This file is intends for �K.
 *
 * Author:
 * -------
 * -------
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
  *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _RMMI_MSGHDLR_H
#define _RMMI_MSGHDLR_H

//#include "app_ltlcom.h"
//#include "kal_non_specific_general_types.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_general_types.h"

extern void rmmi_uart_rtw_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_uart_rtr_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_uart_plugin_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_uart_plugout_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_uart_dsr_change_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_uart_escape_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern kal_uint16 rmmi_uart_send_data(kal_uint8 port);

extern kal_uint16 rmmi_uart_read_data(kal_uint8 port, kal_uint16 len);

extern void rmmi_process_one_cmd(kal_uint8 cid);
extern void rmmi_process_multi_cmd(kal_uint8 cid);
extern void rmmi_read_from_uart(kal_uint8 port);

extern void rmmi_write_to_uart(kal_uint8 *buffer, kal_uint16 length, kal_bool stuff);

extern void rmmi_uart_write_data(kal_uint8 *buffer, kal_uint16 length, kal_bool stuff, kal_uint8 cid, kal_uint8 port);
extern void rmmi_uart_print_data(kal_uint8 *buffer, kal_uint16 length,kal_uint8 cid, kal_uint8 port,kal_uint8 URC); 
extern void rmmi_send_rsp_to_SAT(void);
extern void rmmi_rsp_to_SAT(kal_uint8 *buffer, kal_uint16 length, kal_bool stuff);

#ifdef __IRDA_SUPPORT__
extern void ircomm_connect_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void ircomm_disconnect_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif /* __IRDA_SUPPORT__ */ 

#ifdef __CMUX_SUPPORT__
extern void rmmi_uart_cmux_dlc_connect_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_uart_cmux_close_down_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif /* __CMUX_SUPPORT__ */ 

#if defined(__BT_SUPPORT__)
extern void rmmi_bt_spp_conncet_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_bt_hf_conncet_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_bt_hf_slc_finish_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_uart_bt_reset_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_bt_l4c_at_general_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_bt_pcm_lb_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_bt_get_bd_addr_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

//add by stanley: 2006-0721: for MSG_ID_BT_L4C_TEST_CMD_CNF processing
extern void rmmi_bt_test_cmd_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_bt_adv_test_mode_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif /* defined(__BT_SUPPORT__) */ 

extern void rmmi_dmui_lawmo_cmd_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_force_tansfer_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_nvram_read_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_master_sim_change_req(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_atci_send_ilm(module_type dest_id, kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr);

extern void rmmi_send_ilm(module_type dest_id, kal_uint16 msg_id, kal_uint8 queue_class, void *local_param_ptr, void *peer_buf_ptr);

#if defined(__DT_SUPPORT__) || defined(__GEMINI__) 
extern void rmmi_uart_transfer_req_hdlr(module_type mod_id, local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr); 

extern void rmmi_uart_transfer_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_uart_transfer_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif 

extern void rmmi_register_channel_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr, module_type src_mod);

extern void rmmi_execution_at_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr, module_type src_mod);

#ifdef __ECALL_SUPPORT__
extern void rmmi_media_aud_emsd_monitor_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_media_aud_emsd_set_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr); 

extern void rmmi_media_aud_emsd_push_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_media_aud_emsd_pull_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr); 

extern void rmmi_media_aud_emsd_sync_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_media_aud_emsd_lack_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void rmmi_media_aud_emsd_hack_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif /*__ECALL_SUPPORT__*/
#ifdef __ECALL_PSAP_SUPPORT__
extern void rmmi_media_aud_emsd_psap_monitor_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rmmi_media_aud_emsd_psap_pull_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void rmmi_media_aud_emsd_psap_data_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif 
#ifdef __SMART_PHONE_MODEM__//__AGPS_SUPPORT__
extern void rmmi_lbs_write_to_uart(kal_uint8 *buffer, kal_uint16 length);
extern void rmmi_lbsap_data_send_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif

#ifndef __MTK_TARGET__
extern void atci_ut_uart_input_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif
#endif /* _RMMI_MSGHDLR_H */ 

