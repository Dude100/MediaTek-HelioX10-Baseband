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
 * L4C2TCM_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of TCM and L4C.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "ps_public_struct.h"

#ifndef _L4C2TCM_STRUCT_H
#define _L4C2TCM_STRUCT_H

#include "l4c2abm_struct.h"
#include "kal_public_api.h"
#include "tcm_api.h"
#include "ps_public_enum.h"
#include "l4c2tcm_func.h"
#include "irat_common_struct.h"
#include "l4c_common_enum.h"

/* __MEDIATEK_SMART_QOS__ */
#include "nvram_editor_data_item.h"

/* __APP_SECONDARY_PDP_SUPPORT__ */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8   context_id;
} tcm_pdp_reactivate_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8   context_id;
    kal_uint32  req_reason;     /* Used by ETCM */   
    l4ctcm_egact_support_rat_enum   rat;
} tcm_pdp_activate_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8   context_id;
} tcm_pdp_activate_rej_rsp_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8   context_id;
} tcm_pdp_modify_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8   context_id;
    #ifdef __LOCAL_DEACTIVATE_PDP_SUPPORT__
    kal_bool local_deactivate_pdp; /* __LOCAL_DEACTIVATE_PDP_SUPPORT__ */	
    #endif // ~ __LOCAL_DEACTIVATE_PDP_SUPPORT__
    tcm_pdp_deact_reason_enum deact_reason; // Used only in RAT_TCM >> ETCM >> ESM (due to MSG_ID_TCM_RAT_TCM_INIT_DEACTIVATE_CONTEXT_IND).
    l4ctcm_egact_support_rat_enum   rat;
} tcm_pdp_deactivate_req_struct;

/* for __APP_SECONDARY_PDP_SUPPORT__ */
typedef struct {
    LOCAL_PARA_HDR
   kal_uint8	            context_id;
   kal_bool	                is_qos_present; // indicates if QoS modification
   nvram_editor_qos_struct	modify_qos;     // modifying QoS value
} ltcm_pdp_qos_tft_modify_req_struct;
/* ~for __APP_SECONDARY_PDP_SUPPORT__ */

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8   context_id;
    kal_uint8   apn_length;
    kal_uint8   apn[100];
    kal_uint8   dcomp_algo;
    kal_uint8   hcomp_algo;
    kal_uint8   pdp_type;
    kal_uint8   pdp_addr_len;
    kal_uint8   addr_val[16];   // AT+CGDCONT should not set static IPv6 address, so 16*u8 size is okay?
    kal_uint8   ipv4addralloc;  // __REL8__
    kal_uint8   p_cscf_discovery;         //R10
    kal_uint8   im_cn_signalling_flag;    //R10
    kal_uint8   request_type;             //R12
} l4ctcm_set_pri_pdp_info_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8   context_id;
    kal_uint8   prim_context_id;
    kal_uint8   dcomp_algo;
    kal_uint8   hcomp_algo;
    kal_uint8   im_cn_signalling_flag;    //R10
} l4ctcm_set_sec_pdp_info_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 qos_type;
    kal_uint8 delay_class;
    kal_uint8 reliability_class;
    kal_uint8 peak_throughput;
    kal_uint8 precedence_class;
    kal_uint8 mean_throughput;
} l4ctcm_set_qos_info_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 qos_type;
    kal_uint8 traffic_class;
    kal_uint8 delivery_order;
    kal_uint8 delivery_of_err_sdu;
    kal_uint8 max_sdu_size;
    kal_uint8 max_bitrate_up_lnk;
    kal_uint8 max_bitrate_down_lnk;
    kal_uint8 residual_bit_err_rate;
    kal_uint8 sdu_err_ratio;
    kal_uint8 transfer_delay;
    kal_uint8 traffic_hndl_priority;
    kal_uint8 guarntd_bit_rate_up_lnk;
    kal_uint8 guarntd_bit_rate_down_lnk;
    kal_uint8 signalling_indication;
    kal_uint8 source_statistics_descriptor;
    kal_uint8 ext_max_bitrate_down_lnk;
    kal_uint8 ext_guarntd_bit_rate_down_lnk;
    kal_uint8 ext_max_bitrate_up_lnk;
    kal_uint8 ext_guarntd_bit_rate_up_lnk;
} l4ctcm_set_eqos_info_req_struct;

//mtk04121
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8   context_id;
    kal_uint8   qci;
    kal_uint8   max_bitrate_up_lnk;
    kal_uint8   max_bitrate_down_lnk;
    kal_uint8   guarntd_bit_rate_up_lnk;
    kal_uint8   guarntd_bit_rate_down_lnk;
    kal_uint8   ext_max_bitrate_up_lnk;
    kal_uint8   ext_max_bitrate_down_lnk;
    kal_uint8   ext_guarntd_bit_rate_up_lnk;
    kal_uint8   ext_guarntd_bit_rate_down_lnk;
    kal_uint8   ext2_max_bitrate_up_lnk;
    kal_uint8   ext2_max_bitrate_down_lnk;
    kal_uint8   ext2_guarntd_bit_rate_up_lnk;
    kal_uint8   ext2_guarntd_bit_rate_down_lnk;
} l4ctcm_set_eps_qos_info_req_struct;

typedef struct {
    LOCAL_PARA_HDR
} l4ctcm_start_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 is_chap;
} l4ctcm_set_ppp_auth_info_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    l4c_config_option_struct prco;
} l4ctcm_set_config_option_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint32 channel_id;
    pdp_addr_type_enum pdp_type;
}l4ctcm_enter_data_mode_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
}l4ctcm_leave_data_mode_req_struct;

/* __MEDIATEK_SMART_QOS__ */
typedef struct {
    LOCAL_PARA_HDR
    kal_bool   is_msq_on ;  /* True: Use R6 QOS if the current PLMN (NW/SIM) is on MSQ list (nvram_ef_msq_list_struct). */ 
} l4ctcm_set_msq_mode_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    nvram_ef_msq_entry_struct  entry ;
} l4ctcm_set_msq_entry_req_struct;
/* __MEDIATEK_SMART_QOS__ */

/* mtk00714 w0637: AT definition */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8   context_id;
    kal_uint16  undefine_action; //l4c_action_enum
} l4ctcm_undefine_pdp_info_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	on_off;
} l4ctcm_set_acl_mode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
	kal_uint16	start_index;
	kal_uint16	max_read_entries;
} l4ctcm_get_acl_entries_req_struct;

typedef struct
{
    kal_uint8 apn[MAX_APN_LEN];
} tcm_acl_entry_struct;

typedef struct
{
    LOCAL_PARA_HDR
	kal_uint16	       index;
	tcm_acl_entry_struct	acl_entry;
} l4ctcm_set_acl_entry_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	tcm_acl_entry_struct	acl_entry;
} l4ctcm_add_acl_entry_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_bool	del_all;
	kal_uint16	index;
	tcm_acl_entry_struct	acl_entry;
} l4ctcm_del_acl_entry_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint8 query_id;
    kal_uint8 last_cid;
} l4ctcm_query_ext_gprs_history_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint8   reset_id; 
    kal_bool    reset_all; 
    kal_bool    reset_certain_cid_last_history;
    kal_uint8   context_id; 
    kal_bool    reset_total_history;
} l4ctcm_reset_ext_gprs_history_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    irat_type_enum  irat_type;
    rat_type_enum   source_rat;
    rat_type_enum   target_rat;
} l4ctcm_rat_change_start_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    irat_type_enum  irat_type;
    rat_type_enum   source_rat;
    rat_type_enum   target_rat;
    irat_result_enum irat_result;
} l4ctcm_rat_change_finish_req_struct;

#endif 


