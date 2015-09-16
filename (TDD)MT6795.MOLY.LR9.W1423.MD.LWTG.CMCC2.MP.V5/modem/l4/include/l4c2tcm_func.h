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
 * L4C2TCM_FUNC.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file handles AT get and query command.
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


#ifndef _L4C2TCM_FUNC_H
#define _L4C2TCM_FUNC_H

//#include "ps_public_struct.h"
//#include "tcm_common.h"
//#include "kal_non_specific_general_types.h"
//#include "mmi_l3_enums.h"
//#include "l4c_common_enum.h"
//#include "tcm_common_enums.h"
//#include "l3_inc_enums.h"
//#include "l4c2tcm_struct.h"
#include "mmi_sm_enums.h"
//#include "custom_mmi_default_value.h"

#include "kal_general_types.h"
#include "ps_public_enum.h"
#include "tcm_api.h"

#include "tcm_context.h"

#include "ps_public_struct.h"

#include "nvram_editor_data_item.h"  /* __MEDIATEK_SMART_QOS__ */

// mtk04002_20120518: should NOT include tftlib_api.h here (will cause codegen error) => modify to include tftlib_common_struct.h
#include "tftlib_common_struct.h"

#ifdef __R99__
extern const kal_uint8 rmmi_sdu_err_ratio_string_table[8][3];
extern const kal_uint8 rmmi_residual_ber_string_table[10][3];
#endif /* __R99__ */ 

#ifdef __TCPIP__ /* ABM */
typedef struct
{
   kal_uint8	cid;
   kal_uint32	ext_rx_data;
   kal_uint32	ext_tx_data;
} l4c_ext_gprs_statistics_info_struct;
#endif

#ifdef __TCM_EXT_CALL_HISTORY_SUPPORT__
typedef struct
{
    kal_uint64    call_history_total_ext_tx_data;
    kal_uint64    call_history_total_ext_rx_data;
    kal_uint64    call_history_last_ext_tx_data;
    kal_uint64    call_history_last_ext_rx_data;
    kal_uint64    call_history_total_ext_conn_duration_in_secs;
    kal_uint32    call_history_last_ext_conn_duration_in_secs;
    kal_uint8      which_cid_is_last_cid;
}l4c_ext_gprs_call_history_info_struct;
#endif // ~ __TCM_EXT_CALL_HISTORY_SUPPORT__

//mtk04121
typedef struct
{
    kal_uint8   context_id;
    kal_uint8   bearer_id;
    kal_uint8   apn_length;
    kal_uint8   apn[MAX_APN_LEN];
    kal_bool    src_addr_sb_net_mask_present;
    kal_uint8   src_addr_sb_net_mask[IPV4_ADDR_LEN * 2];
    kal_bool    ipv6_src_addr_sb_net_mask_present;
    kal_uint8   ipv6_src_addr_sb_net_mask[IPV6_ADDR_LEN * 2];
    kal_bool    gw_addr_present;
    kal_uint8   gw_addr[IPV4_ADDR_LEN];
    kal_bool    ipv6_gw_addr_present;
    kal_uint8   ipv6_gw_addr[IPV6_ADDR_LEN];
    kal_bool    dns_present;
    kal_uint8   dns[IPV4_ADDR_LEN];
    kal_bool    dns2_present;
    kal_uint8   dns2[IPV4_ADDR_LEN];
    kal_bool    ipv6_dns_present;
    kal_uint8   ipv6_dns[IPV6_ADDR_LEN];
    kal_bool    ipv6_dns2_present;
    kal_uint8   ipv6_dns2[IPV6_ADDR_LEN];
    kal_bool    p_cscf_prim_addr_present;
    kal_uint8   p_cscf_prim_addr[IPV4_ADDR_LEN];
    kal_bool    p_cscf_sec_addr_present;
    kal_uint8   p_cscf_sec_addr[IPV4_ADDR_LEN];
    kal_bool    p_cscf_third_addr_present;
    kal_uint8   p_cscf_third_addr[IPV4_ADDR_LEN];
    kal_bool    ipv6_p_cscf_prim_addr_present;
    kal_uint8   ipv6_p_cscf_prim_addr[IPV6_ADDR_LEN];
    kal_bool    ipv6_p_cscf_sec_addr_present;
    kal_uint8   ipv6_p_cscf_sec_addr[IPV6_ADDR_LEN];
    kal_bool    ipv6_p_cscf_third_addr_present;
    kal_uint8   ipv6_p_cscf_third_addr[IPV6_ADDR_LEN];
    kal_bool    im_cn_signalling_flag_present;
    kal_uint8   im_cn_signalling_flag;
} l4c_prim_pdp_rdp_info_struct;

//mtk04121
typedef struct
{
    kal_uint8   context_id;
    kal_uint8   primary_context_id;
    kal_uint8   bearer_id;
    kal_bool    im_cn_signalling_flag_present;
    kal_uint8   im_cn_signalling_flag;
} l4c_sec_pdp_rdp_info_struct;

typedef struct
{
   kal_uint8                   length;
   l4c_prim_pdp_info_struct    prim_pdp_info[ TCM_TOT_CONTEXT ];
} l4c_prim_pdp_info_list_struct;
 
typedef struct
{
   kal_uint8                   length;
   l4c_sec_pdp_info_struct     sec_pdp_info[ TCM_TOT_CONTEXT ];
} l4c_sec_pdp_info_list_struct;
 
typedef struct
{
   kal_uint8          length;
   l4c_qos_struct     qos_info[ TCM_TOT_CONTEXT ];
} l4c_qos_list_struct;

typedef struct
{
   kal_uint8          length;
   l4c_eqos_struct     qos_info[ TCM_TOT_CONTEXT ];
} l4c_eqos_list_struct;

//mtk04121
typedef struct 
{
    kal_uint8   context_id;
    kal_uint8   qci;
    kal_bool    max_bitrate_present;
    kal_uint8   max_bitrate_up_lnk;
    kal_uint8   max_bitrate_down_lnk;
    kal_uint8   ext_max_bitrate_up_lnk;
    kal_uint8   ext_max_bitrate_down_lnk;
    kal_uint8   ext2_max_bitrate_up_lnk;
    kal_uint8   ext2_max_bitrate_down_lnk;
    kal_bool    guarntd_bit_rate_present;
    kal_uint8   guarntd_bit_rate_up_lnk;
    kal_uint8   guarntd_bit_rate_down_lnk;
    kal_uint8   ext_guarntd_bit_rate_up_lnk;
    kal_uint8   ext_guarntd_bit_rate_down_lnk;
    kal_uint8   ext2_guarntd_bit_rate_up_lnk;
    kal_uint8   ext2_guarntd_bit_rate_down_lnk;
} l4c_eps_qos_rdp_struct;

//mtk04121
typedef struct
{
    kal_uint8           length;
    l4c_eps_qos_struct  qos_info[TCM_TOT_CONTEXT];
} l4c_eps_qos_list_struct;

typedef struct
{
    kal_uint8 context_id;
    kal_uint8 user_name[MAX_GPRS_USER_NAME_LEN];
    kal_uint8 password[MAX_GPRS_PASSWORD_LEN];
    kal_uint8 pri_dns[IPV4_ADDR_LEN];
    kal_uint8 sec_dns[IPV4_ADDR_LEN];
    kal_uint8 is_chap;
    l4c_tcm_activate_pdp_with_dnsv4_address_enum act_pdp_with_pco_req_dnsv4 ;    
#if ( (defined(__IPV6__)) || (defined(__IPV4V6__)) )
    l4c_tcm_activate_pdp_request_ipv6_dns_enum act_pdp_cntxt_req_ipv6_dns; // only valid for IPv6 and IPv4v6, possible value: 
                                          // TCM_ACTIVATE_PDP_NEED_REQUEST_IPV6_DNS & 
                                          // TCM_ACTIVATE_PDP_NOT_REQUEST_IPV6_DNS
    kal_bool    ipv6_dns1_present;
    kal_uint8   ipv6_dns1[IPV6_ADDR_LEN];
    kal_bool    ipv6_dns2_present;
    kal_uint8   ipv6_dns2[IPV6_ADDR_LEN];
#endif // ~ #if ( (defined(__IPV6__)) || (defined(__IPV4V6__)) )
} l4c_config_option_struct;

typedef struct
{
   kal_uint8          length;
   l4c_config_option_struct     config_option_info[ TCM_TOT_CONTEXT ];
} l4c_config_option_list_struct;
 
/* +CGDCONT */
kal_bool l4ctcm_get_pri_pdp_info(l4c_prim_pdp_info_list_struct *info);
void l4ctcm_get_pri_pdp_info_by_context_id(kal_uint8 context_id, l4c_prim_pdp_info_struct *info) ;

//mtk04121
/* +CGCONTRDP */
kal_bool l4ctcm_get_pri_pdp_rdp_info(kal_uint8 cid, l4c_prim_pdp_rdp_info_struct *info);

kal_bool l4ctcm_test_pri_pdp_rdp_info(kal_uint8 **rsp_str);

#if 0
/* under construction !*/
#endif

/* +CGDSCONT */
kal_bool l4ctcm_get_sec_pdp_info(l4c_sec_pdp_info_list_struct *info);

kal_bool l4ctcm_test_sec_pdp_info(kal_uint8 **rsp_str);

//mtk04121
/* +CGSCONTRDP */
kal_bool l4ctcm_get_sec_pdp_rdp_info(kal_uint8 cid, l4c_sec_pdp_rdp_info_struct *info);

kal_bool l4ctcm_test_sec_pdp_rdp_info(kal_uint8 **rsp_str);

//mtk04121
/* +CGTFT */
kal_bool l4ctcm_set_tft_info(tft_info_struct *info);
kal_bool l4ctcm_get_tft_info(tft_info_struct *info);
kal_bool l4ctcm_undef_cgtft(kal_uint8 cid) ;
kal_bool l4ctcm_test_tft_info(kal_uint8 **rsp_str);

/* +EGDELPF */
kal_bool l4ctcm_set_egdelpf(kal_uint8 cid, kal_uint8 pf_id) ;
kal_bool l4ctcm_get_egdelpf(kal_uint8 cid, kal_uint8 *pf_total_num, kal_uint8 *pf_list) ;
kal_bool l4ctcm_undef_egdelpf(kal_uint8 cid) ;

/* +EGLNKPF */
kal_bool l4ctcm_set_eglnkpf(kal_uint8 cid, kal_uint8 lnkpf_id) ;
kal_bool l4ctcm_get_eglnkpf(kal_uint8 cid, kal_uint8 *pf_total_num, kal_uint8 *pf_list) ;
kal_bool l4ctcm_undef_eglnkpf(kal_uint8 cid) ;

//mtk04121
/* +CGTFTRDP */
kal_bool l4ctcm_get_tft_rdp_info(tft_info_struct *info);

kal_bool l4ctcm_test_tft_rdp_info(kal_uint8 **rsp_str);

/* +CGQREQ / +CGQMIN */
kal_bool l4ctcm_get_qos_info(atci_qos_enum type, l4c_qos_list_struct *info);

#if 0
/* under construction !*/
#endif

/* +CGQREQ / +CGQMIN */
#ifdef __R99__
kal_bool l4ctcm_get_eqos_info(atci_qos_enum type, l4c_eqos_list_struct *info);

kal_bool l4ctcm_test_negotiated_eqos(kal_uint8 **rsp_str);

kal_bool l4ctcm_test_eqos_info(atci_qos_enum type, kal_uint8 **rsp_str);

kal_bool l4ctcm_encode_sdu_size(kal_uint16 size, kal_uint16 *val_ptr);

/* Poying: Move to tcm_api.h for MSBB. */
#if 0
/* under construction !*/
#ifdef __REL6__
/* under construction !*/
#else // #ifdef __REL6__
/* under construction !*/
#endif // ~ #ifdef __REL6__
#ifdef __REL6__
/* under construction !*/
#else // #ifdef __REL6__
/* under construction !*/
#endif // ~ #ifdef __REL6__
#endif 

kal_bool l4ctcm_encode_transfer_delay(kal_uint16 delay, kal_uint16 *val_ptr);

/* Poying: Move to tcm_api.h for MSBB. */
// kal_bool l4ctcm_decode_transfer_delay(kal_uint16 val, kal_uint16 *delay_ptr);

kal_bool l4ctcm_round_down_encode_func(kal_uint16 val, kal_uint16 offset, kal_uint16 min, kal_uint16 step, kal_uint16 *result_ptr);

kal_bool l4ctcm_round_up_encode_func(kal_uint16 val, kal_uint16 offset, kal_uint16 min, kal_uint16 step, kal_uint16 *result_ptr);
#endif

//mtk04121
/* +CGEQOS */
kal_bool l4ctcm_get_eps_qos_info(l4c_eps_qos_list_struct *info);

kal_bool l4ctcm_test_eps_qos_info(kal_uint8 **rsp_str);

//mtk04121
/* +CGEQOSRDP */
kal_bool l4ctcm_get_eps_qos_rdp_info(kal_uint8 cid, l4c_eps_qos_rdp_struct *info);

kal_bool l4ctcm_test_eps_qos_rdp_info(kal_uint8 **rsp_str);

/* erica: new EM */
kal_uint8 l4ctcm_get_pdp_type(kal_uint8 context_id);

/* +CGPADDR (No set) */
kal_bool l4ctcm_get_nw_applied_pdp_addr(kal_uint8 cid, kal_uint8 *length, kal_uint8 *addr);
kal_bool l4ctcm_get_user_defined_pdp_addr(kal_uint8 cid, kal_uint8 *length, kal_uint8 *addr);


/* +EGPPPAUTH */
kal_bool l4ctcm_get_ppp_auth(kal_uint8 context_id, kal_uint8 *is_chap);

kal_bool l4ctcm_get_config_option_info(l4c_config_option_list_struct *info);

#if 0
/* under construction !*/
#endif

kal_bool l4ctcm_test_answer_mode(kal_uint8 const **rsp_str);

kal_bool l4ctcm_test_auto_answer_mode(kal_uint8 const **rsp_str);

kal_bool l4ctcm_test_modify_info(kal_uint8 const **rsp_str);

kal_bool l4ctcm_test_pri_pdp_info(kal_uint8 ** rsp_str);

kal_bool l4ctcm_test_pdp_addr (kal_uint8 const **rsp_str);

kal_bool l4ctcm_test_ppp_auth(kal_uint8 const **rsp_str);

kal_bool l4ctcm_get_msq_mode_info(kal_bool *is_msq_on); /* __MEDIATEK_SMART_QOS__ */

kal_bool l4ctcm_get_msq_entry_info(nvram_ef_msq_list_struct *msq_list_info); /* __MEDIATEK_SMART_QOS__ */

kal_bool l4ctcm_test_l2p(kal_uint8 const **rsp_str);

kal_bool l4ctcm_get_context_state(kal_uint8 *total_context, kal_uint8 *state_list);

void l4ctcm_get_bearer_capability(kal_uint8* valid_contexts, kal_uint8* context_id, kal_uint8* bearer_capability); //hspa_mmi_h2

kal_bool l4ctcm_get_empty_gprs_prof(kal_uint8 *empty_gprs_prof_entry);

kal_bool l4ctcm_get_gprs_statistics_info(l4c_gprs_statistics_info_struct *info);

kal_bool l4ctcm_pdp_capability(kal_uint8 **rsp_str);

#ifdef __TCPIP__ /* ABM */
kal_bool l4ctcm_get_ext_gprs_statistics_info(kal_uint8 cid, l4c_ext_gprs_statistics_info_struct *info);
#endif

#ifdef __TCM_EXT_CALL_HISTORY_SUPPORT__
kal_bool l4ctcm_query_ext_gprs_history(kal_uint8 last_cid, l4c_ext_gprs_call_history_info_struct * info);
kal_bool l4ctcm_reset_ext_gprs_history(kal_bool reset_all, kal_bool reset_certain_cid_last_history, kal_uint8 context_id, kal_bool reset_total_history);
kal_bool l4ctcm_reset_ext_gprs_history_command(kal_uint32 reset_command);
#endif  // MAUI_01643919, mtk02285, 20090316

kal_bool l4ctcm_set_sib_pdp_addr_type(kal_uint8 pdp_addr_type, kal_uint8 cid);
kal_uint8 l4ctcm_get_nw_applied_pdp_addr_type(kal_uint8 cid);

/* __IPV4V6__ ~ */
kal_uint8 l4ctcm_get_user_defined_pdp_addr_type(kal_uint8 cid);
kal_bool l4ctcm_check_is_context_valid(kal_uint8 cid);
void l4ctcm_sib_cpy(kal_uint8 dst_cid,kal_uint8 src_cid);
void l4ctcm_update_pdp_type(kal_uint8 cid,kal_uint8 pdp_addr_type);
/* ~ __IPV4V6__*/

kal_bool l4ctcm_test_protocol_config(kal_uint8 const **rsp_str);
kal_bool l4ctcm_test_cgauth(kal_uint8 const **rsp_str);

kal_bool check_pdp_context_exist_func(void);

// check if there is PDP activating or activated
// This function check if certain context has been called mmi_alloc_nsapi
kal_bool check_pdp_context_exist_or_during_activating_func(void);
#if (defined(__FAST_DORMANCY__) || defined(__NO_PSDATA_SEND_SCRI__))
kal_bool check_if_has_activation_pending_pdp(void);
kal_bool check_if_has_deactivation_pending_pdp(void);
kal_bool check_if_has_mt_activation_pending_pdp(void);
#endif /* (defined(__FAST_DORMANCY__) || defined(__NO_PSDATA_SEND_SCRI__)) */

kal_bool check_remote_pdp_context_exist_func(void);

kal_bool l4ctcm_pid_to_cid(kal_uint8 profile_id, kal_uint8 *context_id);

kal_bool l4ctcm_cmux_port_to_cid (kal_uint8 profile_id, kal_uint8 *context_id);

/* 20080616 mtk00714 */
//#ifdef __GEMINI__
#if defined(__GEMINI__) || defined(__SGLTE__)
extern kal_bool check_pdp_context_exist_in_either_SIM(kal_uint8 which_sim);
#endif

#ifdef __ACL_SUPPORT__
kal_uint8 l4ctcm_get_acl_type(void);
#endif

#ifdef __MEDIATEK_SMART_QOS__
void tcml4c_get_current_plmn_id(kal_uint8 *sim_plmn, kal_uint8 *nw_plmn);
#endif 

#endif /* ~_L4C2TCM_FUNC_H */

