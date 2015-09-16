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
 * TCM2L4C_STRUCT.H
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef _TCM2L4C_STRUCT_H
#define _TCM2L4C_STRUCT_H

//------------------------------ suggest Add ------------------------------
//#include "kal_non_specific_general_types.h"
#include "l4c2tcm_func.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
//#include "app_ltlcom.h"
//#include "l4c_common_enum.h"
#include "l4c2tcm_struct.h"
#include "mmi_l3_enums.h"

//------------------------------ suggest Add ------------------------------
#include "kal_general_types.h"
#include "ps_public_struct.h"
#include "ps_public_enum.h"

/* __APP_SECONDARY_PDP_SUPPORT__ */
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
} tcm_pdp_reactivate_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_bool cause2_present ;    // if network has cause_2 value in ACTIVATE_PDP_CONTEXT_ACCEPT
    ps_cause_enum cause2;           /* Relay cause_2 value from SM. */
    pdp_addr_type_enum pdp_type;
    kal_uint8 primary_context_id;
} tcm_pdp_activate_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_bool is_rejected_by_nw; // if this PDP is rejected by NW using SM peer msg, KAL_TRUE, else, KAL_FALSE
    ps_cause_enum cause; /* reject cause (also used for cause_2) */
} tcm_pdp_activate_rej_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 primary_context_id;
} tcm_pdp_activate_ind_struct;

//#ifdef __TURN_ON_GENERAL_SECONDARY_PDP__
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 primary_context_id;
} tcm_sec_pdp_activate_ind_struct;
//#endif

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    qos_struct new_neg_qos;
    kal_bool tft_changed;
    kal_bool qos_changed;
    kal_uint8 primary_context_id;
} tcm_pdp_modify_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    ps_cause_enum cause; /* reject cause*/
} tcm_pdp_modify_rej_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    qos_struct new_neg_qos;
    kal_bool tft_changed;
    kal_bool qos_changed;
    kal_uint8 primary_context_id;
} tcm_pdp_modify_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 primary_context_id;
    l4c_result_enum result;
    ps_cause_enum cause; // Used by RAT_TCM when value == RAT_TCM_RETRY_NEEDED_AFTER_IRAT
} tcm_pdp_deactivate_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    ps_cause_enum cause; /* deactivation cause*/
    kal_uint8 primary_context_id;
} tcm_pdp_deactivate_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    mmi_event_enum event_id;
    kal_uint8 pdp_addr_len;
    pdp_addr_type_enum pdp_addr_type;
    kal_uint8 pdp_addr[MAXIMUM_POSSIBLE_ADDR_LEN];
} l4ctcm_ps_event_report_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 valid_contexts;
    kal_uint8 context_id[GPRS_MAX_PDP_SUPPORT];
    kal_uint8 bearer_capability[GPRS_MAX_PDP_SUPPORT];
} l4ctcm_bearer_capability_ind_struct; //hspa_mmi_h2

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 result;
    ps_cause_enum error_cause;  /* erica 20060320 */
} l4ctcm_set_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;       // Jeffery NEW!
    kal_uint8 result;
    ps_cause_enum error_cause;  /* erica 20060320 */
} l4ctcm_set_context_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
    ps_cause_enum cause;
} l4ctcm_set_acl_mode_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
    ps_cause_enum	cause;
    kal_uint16	start_index;
    kal_uint16	num_of_entries;
    kal_bool	       more_flag;
    tcm_acl_entry_struct	acl_list[TCM_MAX_PEER_ACL_ENTRIES];
} l4ctcm_get_acl_entries_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
    ps_cause_enum	cause;
} l4ctcm_add_acl_entry_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
    ps_cause_enum	cause;
} l4ctcm_set_acl_entry_cnf_struct;
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
    ps_cause_enum	cause;
} l4ctcm_del_acl_entry_cnf_struct;

typedef l4ctcm_set_context_cnf_struct l4ctcm_set_pri_pdp_info_cnf_struct;
typedef l4ctcm_set_context_cnf_struct l4ctcm_set_sec_pdp_info_cnf_struct;
typedef l4ctcm_set_context_cnf_struct l4ctcm_set_qos_info_cnf_struct;
typedef l4ctcm_set_context_cnf_struct l4ctcm_set_eqos_info_cnf_struct;
typedef l4ctcm_set_context_cnf_struct l4ctcm_set_ppp_auth_info_cnf_struct;
//typedef l4ctcm_set_context_cnf_struct l4ctcm_set_gprs_account_info_cnf_struct;
typedef l4ctcm_set_context_cnf_struct l4ctcm_set_eps_qos_info_cnf_struct;
typedef l4ctcm_set_context_cnf_struct l4ctcm_undefine_pdp_info_cnf_struct; //mtk00714 w0637: AT definition
typedef l4ctcm_set_context_cnf_struct l4ctcm_set_config_option_cnf_struct;
//typedef l4ctcm_set_context_cnf_struct l4ctcm_set_ppp_auth_cnf_struct;   // mtk02126 define this struct for MSC to recognize MAUI_02420720

typedef l4ctcm_set_cnf_struct l4ctcm_start_cnf_struct;
typedef l4ctcm_set_cnf_struct l4ctcm_set_msq_mode_cnf_struct ;  /* __MEDIATEK_SMART_QOS__ */
typedef l4ctcm_set_cnf_struct l4ctcm_set_msq_entry_cnf_struct ; /* __MEDIATEK_SMART_QOS__ */

//typedef tcm_pdp_activate_ind_struct rat_tcm_print_embedded_activate_ind_struct;
typedef tcm_pdp_deactivate_ind_struct rat_tcm_print_embedded_deactivate_ind_msg_struct;
typedef tcm_pdp_modify_ind_struct rat_tcm_print_embedded_modify_ind_msg_struct;
typedef tcm_sec_pdp_activate_ind_struct rat_tcm_print_embedded_sec_activate_ind_msg_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 result;
    ps_cause_enum error_cause;
} l4ctcm_enter_data_mode_cnf_struct; //mtk02285, 20110322

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 result;
    ps_cause_enum error_cause;
} l4ctcm_leave_data_mode_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    l4c_prim_pdp_info_list_struct l4c_prim_pdp_info_list;
} tcm_ut_check_callback_l4ctcm_get_pri_pdp_info_struct;
//MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_PRI_PDP_INFO, l4c_prim_pdp_info_list_struct

typedef struct
{
    LOCAL_PARA_HDR
    l4c_sec_pdp_info_list_struct l4c_sec_pdp_info_list;
} tcm_ut_check_callback_l4ctcm_get_sec_pdp_info_struct;
//MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_SEC_PDP_INFO, l4c_sec_pdp_info_list_struct

typedef struct
{
    LOCAL_PARA_HDR
    l4c_qos_list_struct l4c_qos_list;
} tcm_ut_check_callback_l4ctcm_get_qos_info_struct;
//MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_QOS_INFO, l4c_qos_list_struct

typedef struct
{
    LOCAL_PARA_HDR
    l4c_config_option_list_struct l4c_config_option_list;
} tcm_ut_check_callback_l4ctcm_get_config_option_info_struct;
//MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_CONFIG_OPTION_INFO, l4c_config_option_list_struct

typedef struct
{
    LOCAL_PARA_HDR
    l4c_eqos_list_struct l4c_eqos_list;
} tcm_ut_check_callback_l4ctcm_get_eqos_info_struct;
//MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_EQOS_INFO, l4c_eqos_list_struct

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 val;
} tcm_ut_check_callback_l4ctcm_encode_sdu_size_struct;
//MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_ENCODE_SDU_SIZE, kal_uint16 val_ptr

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 val;
} tcm_ut_check_callback_l4ctcm_decode_sdu_size_struct;
//MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_DECODE_SDU_SIZE, kal_uint16 val_ptr

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 val;
} tcm_ut_check_callback_l4ctcm_encode_bit_rate_struct;
//MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_ENCODE_BIT_RATE, kal_uint16 val_ptr

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 rate;
} tcm_ut_check_callback_l4ctcm_decode_bit_rate_struct;
//MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_DECODE_BIT_RATE, kal_uint32 rate_ptr

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 val;
} tcm_ut_check_callback_l4ctcm_encode_transfer_delay_struct;
//MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_ENCODE_TRANSFER_DELAY, kal_uint16 val_ptr

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 val;
} tcm_ut_check_callback_l4ctcm_decode_transfer_delay_struct;
//MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_DECODE_TRANSFER_DELAY, kal_uint16 delay_ptr

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 length;
    kal_uint8 addr[100];
} tcm_ut_check_callback_l4ctcm_get_pdp_addr_struct;
//MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_PDP_ADDR, kal_uint8 length, kal_uint8 addr[100]

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 total_context[100];
    kal_uint8 state_list[100];
} tcm_ut_check_callback_l4ctcm_get_context_state_struct;
//MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_CONTEXT_STATE, kal_uint8 total_context[100], kal_uint8 state_list[100]

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 empty_gprs_prof_entry[100];
} tcm_ut_check_callback_l4ctcm_get_empty_gprs_prof_struct;
//MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_EMPTY_GPRS_PROF, kal_uint8 empty_gprs_prof_entry[100]

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool is_chap;
} tcm_ut_check_callback_l4ctcm_get_ppp_auth_struct;
//MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_PPP_AUTH, kal_bool is_chap

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool callback_func_return_value;
} tcm_ut_check_callback_check_pdp_context_exist_or_during_activating_func_struct;
// MSG_ID_TCM_UT_CHECK_CALLBACK_CHECK_PDP_CONTEXT_EXIST_OR_DURING_ACTIVATING_FUNC

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool callback_func_return_value;
    kal_uint8 valid_contexts;
    kal_uint8 context_id[GPRS_MAX_PDP_SUPPORT];
    kal_uint8 bearer_capability[GPRS_MAX_PDP_SUPPORT];
} tcm_ut_check_callback_l4ctcm_get_bearer_capability_struct;
// MSG_ID_TCM_UT_CHECK_CALLBACK_L4CTCM_GET_BEARER_CAPABILITY

typedef struct
{
    LOCAL_PARA_HDR
} tcm_ut_result_ok_struct; 

typedef struct 
{
    LOCAL_PARA_HDR
    l4c_prim_pdp_rdp_info_struct info ;    
} tcm_ut_l4ctcm_get_pri_pdp_rdp_info_struct ; // l4ctcm_get_pri_pdp_rdp_info()

typedef struct 
{
    LOCAL_PARA_HDR 
    l4c_sec_pdp_rdp_info_struct info ;   
} tcm_ut_l4ctcm_get_sec_pdp_rdp_info_struct ; // l4ctcm_get_sec_pdp_rdp_info() 

typedef struct 
{
    LOCAL_PARA_HDR 
    l4c_prim_pdp_info_struct info ;
} tcm_ut_l4ctcm_get_pri_pdp_info_struct ; // l4ctcm_get_pri_pdp_info()

typedef struct 
{
    LOCAL_PARA_HDR
    l4c_sec_pdp_info_struct info ;
} tcm_ut_l4ctcm_get_sec_pdp_info_struct ; // l4ctcm_get_sec_pdp_info()

typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8 context_id ;
    pdp_addr_type_enum pdp_type ;
    pdp_addr_len_enum pdp_len ;
    kal_uint8 pdp_addr[IPV4V6_ADDR_LEN] ;
} tcm_ut_l4ctcm_get_nw_applied_pdp_info_struct ; // l4ctcm_get_pdp_addr() and l4ctcm_get_pdp_addr_type()

/* mtk03537: for LTE concatenated message in peer buffer */
typedef struct {
    PEER_BUFF_HDR
    kal_uint8           embed_msg_num;
    kal_uint32          embed_msg_id[10]; // at most 11 nsapis (nsapi 5~15), therefore, embedded at most have 10 entries
    local_para_struct   *embed_local_param[10]; // at most 11 nsapis (nsapi 5~15), therefore, embedded at most have 10 entries
} tcm_embed_struct;

#ifdef __SGLTE__
typedef struct {
    LOCAL_PARA_HDR
    kal_bool result;
} l4ctcm_pdp_eps_transfer_complete_ind_struct;
#endif /* __SGLTE__ */

#endif


