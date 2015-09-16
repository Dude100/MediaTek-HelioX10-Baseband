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
 *   mm_ratcm_struct.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 ******************************************************************************/

#ifndef MM_RATCM_STRUCT_H
#define MM_RATCM_STRUCT_H

#include "l3_inc_enums.h"
#include "mcd_l3_inc_struct.h"
#include "l3_inc_local.h"
#include "l3llc_enums.h"
#include "mmllc_enums.h"
#include "as2nas_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "ps_public_enum.h"
#include "mm_ratcm_enums.h"
#include "rsvas_enum.h"
#include "kal_public_defs.h"
#include "irat_common_struct.h"
#include "irat_common_enums.h"

/* Ripple: AS/NAS common define and struct */
//#define MAX_NUM_PLMN_PER_RAT 16

/*
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 mcc1;
    kal_uint8 mcc2;
    kal_uint8 mcc3;
    kal_uint8 mnc1;
    kal_uint8 mnc2;
    kal_uint8 mnc3;
} local_plmn_id_struct;

typedef struct {
    LOCAL_PARA_HDR
    local_plmn_id_struct plmn_id;
    kal_uint8 la_code[2];
}local_lai_struct;

typedef struct {
    LOCAL_PARA_HDR
    local_plmn_id_struct plmn_id;
    kal_uint8 la_code[2];
    kal_uint8 ra_code;
}local_rai_struct;
*/

/* Ripple: Remove 2006/01/13
typedef struct {
    LOCAL_PARA_HDR
    plmn_id_struct plmn_id;
    kal_uint8 power_level;
    kal_uint8 high_quality_plmn_count;
    kal_uint8 may_suitalbe_cell_exist;
} available_plmn_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 available_plmn_count;
    kal_uint8 high_quality_plmn_count;
    available_plmn_struct available_plmn[MAX_NUM_PLMN_PER_RAT];
} as_plmn_list_struct;
*/
/* ~Ripple */

typedef struct {
    LOCAL_PARA_HDR
    rat_enum rat;
    rat_enum active_rat;
} mm_ratcm_set_rat_mode_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_successful;
    mm_cause_enum cause;
} mm_ratcm_set_rat_mode_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    //kal_uint8 prefer_band;
    //kal_uint8 requested_gsm_band;
    //kal_uint8 requested_umts_fdd_band[SIZE_OF_UMTS_BAND]; /* mtk00714: umts multi-band */
    kal_uint8 drx_para[2]; /* for split paging cycle and non-drx timer */
    kal_uint8 imeisv_value_digit0;
    kal_uint8 imeisv_value_digit_byte[8];
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
    gprs_transfer_preference_enum prefer;
#endif
} mm_ratcm_init_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 trx_id;
    plmn_search_type_enum plmn_search_type;
    rat_enum rat;
    kal_uint8 plmn_id_count;
    plmn_id_struct plmn_id[MAX_NUM_SEARCH_PLMN];
    kal_bool is_manual_sel;
#if defined(__3G_CSG_SUPPORT__) || defined (UNIT_TEST)
    kal_bool is_manual_csg_sel;
    kal_uint32 csg_id;
#endif
    kal_bool is_ir_cell_resel_allowed;
    kal_uint16 factory_mode_arfcn; //0xFFFF means invalid arfcn, /* 20081110 mtk00714, for fast camp on test machine */
    kal_bool  trigger_by_signal_appear;
#if defined(__LTE_RAT__) && defined (__UMTS_TDD128_MODE__) && !defined (__SGLTE__)
    kal_bool  trigger_by_4g_plmn_loss;
#endif
#if defined(__UMTS_R7__) || defined (UNIT_TEST)
    kal_bool  is_higher_plmn_search; //CSCE_R7
#endif
#ifdef __LTE_RAT__
    kal_bool is_csfb_ongoing;
#endif
#if (defined(__OP01__) && defined(__GEMINI__)) 
    kal_bool  is_power_on;  //for CMCC case 5.1.1: is first search after power on
#endif
} mm_ratcm_plmn_search_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 trx_id;
    plmn_search_result_enum result;
    rat_enum rat;
    plmn_id_struct selected_plmn;
    kal_bool is_uas_plmn_list_present;
    as_plmn_list_struct uas_plmn_list;
    kal_bool is_gas_plmn_list_present;
    as_plmn_list_struct gas_plmn_list;
    as_cell_type_enum   selected_cell_type; //20081027
#if defined(__UMTS_FDD_MODE__) || defined(__TD_NETWORK_SHARING__) || defined (UNIT_TEST)
    kal_uint8 multi_plmn_count;
    plmn_id_struct multi_selected_plmn[MAX_NUM_MULTI_PLMN];
    as_cell_type_enum multi_selected_cell_type[MAX_NUM_MULTI_PLMN];
#endif
} mm_ratcm_plmn_search_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 eq_plmn_count;
    plmn_id_struct eq_plmn_id[MAX_NUM_EQ_PLMN]; /* The eq_plmn_id[0] should be RPLMN */
} mm_ratcm_eq_plmn_list_update_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 plmn_id_count;
    plmn_id_struct plmn_id[MAX_NUM_HPLMN]; //MAX_NUM_HPLMN: 4
    kal_uint8 home_country_mcc[3];
} mm_ratcm_hplmn_info_update_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 la_code[2];
    forbidden_la_type_enum forbidden_la_type; /* forbidden_la_type_enum */
    plmn_id_struct plmn_id;
} mm_ratcm_add_forbidden_la_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 la_code[2];
    plmn_id_struct plmn_id;
    kal_bool delete_all;
} mm_ratcm_del_forbidden_la_req_struct;

#if defined(__3G_CSG_SUPPORT__) || defined (UNIT_TEST)
typedef struct {
    LOCAL_PARA_HDR
    csg_update_type_enum csg_update_type;
    plmn_id_struct plmn_id;
    kal_uint32 csg_id;
} mm_ratcm_update_allowed_csg_list_req_struct;
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__UMTS_FDD_MODE__) || defined(__TD_NETWORK_SHARING__) || defined (UNIT_TEST)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined (__R6_DSAC__) || defined (UNIT_TEST)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__PS_SERVICE__) || defined (UNIT_TEST)
/* under construction !*/
#endif
/* under construction !*/
#if defined(__PPACR_SUPPORT__) || defined (UNIT_TEST)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if defined(__3G_CSG_SUPPORT__) || defined (UNIT_TEST)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif
typedef mm_sys_info_ind_struct mm_ratcm_sys_info_ind_struct;
typedef mm_cell_global_identity_info_ind_struct mm_ratcm_cell_global_identity_info_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_uas_plmn_list_present;
    as_plmn_list_struct uas_plmn_list;
    kal_bool is_gas_plmn_list_present;
    as_plmn_list_struct gas_plmn_list;
    csfb_indicator_enum csfb_ind;
#ifdef __GEMINI__
    as_suspend_mode_reason_enum cause; /* for RR suspend mode */
#endif /* __GEMINI__ */
} mm_ratcm_plmn_loss_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    rat_enum rat;
    kal_bool is_manual_list;
} mm_ratcm_plmn_list_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_uas_plmn_list_present;
    as_plmn_list_struct uas_plmn_list;
    kal_bool is_gas_plmn_list_present;
    as_plmn_list_struct gas_plmn_list;
} mm_ratcm_plmn_list_cnf_struct;

#if defined(__3G_CSG_SUPPORT__)|| defined (UNIT_TEST)
typedef struct {
    LOCAL_PARA_HDR
    rat_enum rat;
    kal_uint8 plmn_count;
    plmn_id_struct plmn_id[MAX_NUM_EQ_PLMN];
} mm_ratcm_csg_list_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    //kal_bool is_uas_csg_list_present;
    as_csg_list_struct uas_csg_list;
} mm_ratcm_csg_list_cnf_struct;
#endif

typedef struct {
    LOCAL_PARA_HDR
    RATCM_RRC_PagingCause paging_cause;
    domain_id_enum cn_domain_id;
    ue_id_type_enum ue_id_type;
} mm_ratcm_page_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint32 old_tlli;
    kal_uint32 new_tlli;
    tlli_update_type_enum status_tlli;
    rai_struct rai;
} mm_ratcm_tlli_assign_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_tmsi_lai_present;
    kal_uint8 tmsi[4];
    kal_bool is_lai_abnormal; /* MAUI_01959495 */
    lai_struct reg_lai;
    kal_bool is_ptmsi_rai_present;
    kal_uint8 ptmsi[4];
    kal_bool is_rai_abnormal; /* MAUI_01959495 */
    rai_struct reg_rai;
    kal_uint8 umts_ps_drx_clc;
} mm_ratcm_paging_param_assign_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    domain_id_enum cn_domain_id;
    kal_bool is_new_keys;
    kal_uint8 cksn;
    kal_bool gsm_cipher_key_infoP;
    kal_uint8 gsm_cipher_key_info[KC_LEN];
    kal_bool gsm_cipher_key128_infoP;
    kal_uint8 gsm_cipher_key128_info[KC128_LEN];
    kal_uint8 ps_cipher_algo;
    kal_bool umts_keys_infoP;
    kal_uint8 umts_cipher_key_info[CK_LEN];
    kal_uint8 umts_integrity_key_info[IK_LEN];
    kal_bool is_power_on; // for TS 24.008 CR1994
} mm_ratcm_security_mode_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    sync_ind_cause_enum cause;
    channel_type_enum channel_type; /* channel_type_enum */
    channel_mode_enum channel_mode; /* channel_mode_enum */
    kal_uint8 si;
    kal_bool is_cipher_on;
} mm_ratcm_sync_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    domain_id_enum cn_domain_id;
    kal_bool is_integrity_enabled;
    Ciphering_Status umts_ciphering_status;
    kal_uint8 service_req_mui;
} mm_ratcm_security_mode_complete_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    domain_id_enum cn_domain_id;
    Ciphering_Status umts_ciphering_status; /* Ciphering_Status */
} mm_ratcm_security_mode_change_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 mui;
    kal_uint16 gibi_tag;
    domain_id_enum cn_domain_id;
    mm_ratcm_est_cause_enum estb_cause;
    peer_msg_id_struct peer_msg_id;
    kal_bool is_service_req;
#if defined (__R6_DSAC__) || defined (UNIT_TEST)
    kal_bool is_dsac_present;
    kal_uint16 selected_dsac_info;
#endif
#if defined(__UMTS_FDD_MODE__) || defined(__TD_NETWORK_SHARING__) || defined (UNIT_TEST)
    plmn_id_struct selected_plmn;
#endif

#if defined(__PPACR_SUPPORT__) || defined (UNIT_TEST)
   ppac_checked_type_enum   PPACCheckedType;
   kal_uint16             selectedPPACInfo; //used by PPAC_LR_ALLOWED
#endif

#ifdef __LTE_RAT__
    csfb_indicator_enum csfb_indicator;
    csfb_service_type_enum csfb_service_type;
#endif /* __LTE_RAT__*/
    rat_enum current_rat; /* CELL_CHANGE_FINISH is in MM external queue and MM current rat is still source rat *
                           * RATCM should reject conn_est_req when current_rat is not match RATCM active rat   */
} mm_ratcm_conn_est_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    domain_id_enum cn_domain_id;
    as_est_cnf_cause_enum result;
    kal_bool wait_gibi_flag;
    kal_bool is_rrc_conn_already_existed;
} mm_ratcm_conn_est_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_successful;
    domain_id_enum cn_domain_id;
} mm_ratcm_conn_est_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    domain_id_enum cn_domain_id;
    as_rel_scope_enum scope;
} mm_ratcm_conn_rel_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    domain_id_enum cn_domain_id;
    as_rel_scope_enum scope;
    kal_bool ps_resume_flag;
    kal_bool wait_gibi_flag;
} mm_ratcm_conn_rel_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    domain_id_enum cn_domain_id;
    RATCM_RRC_ReleaseCause cause;
    kal_bool ps_resume_flag;
    kal_bool wait_gibi_flag;
} mm_ratcm_conn_rel_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    regn_proc_status_enum mm_proc_status;
    kal_uint32 t3212_or_t3302;
    gmm_ms_state_enum ms_state;
    mmas_regn_status_enum regn_status;
    plmn_search_status_enum plmn_search_status;
    plmn_search_type_enum plmn_search_type;	/* new plmn search type */
    lai_struct lai; /* for GAS bar cell */
    kal_uint32 cell_id; /* for GAS bar cell */
} mm_ratcm_regn_status_req_struct;

typedef mm_ratcm_regn_status_req_struct mm_ratcm_regn_status_update_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    action_on_ready_timer_enum action;
    gmm_ms_state_enum new_state;
    kal_uint32 value;
} mm_ratcm_ready_timer_update_req_struct; /* should be same as ratcm_gas_ready_timer_update_req_struct. */

typedef struct {
    LOCAL_PARA_HDR
    ready_timer_status_enum status;
} mm_ratcm_ready_timer_update_ind_struct; /* should be same as ratcm_gas_ready_timer_update_ind_struct. */

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_gprs_required;
} mm_ratcm_service_change_req_struct; /* Should same as ratcm_gas_service_change_req_struct. */

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 mui;
    kal_uint16 gibi_tag;
    DC_Priority  priority;
    kal_bool is_service_req;
} mm_ratcm_cs_data_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_integrity_applied;
} mm_ratcm_cs_data_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 mui;
    kal_uint16 gibi_tag;
    llc_sapi_enum sapi;
    rp_enum radio_priority;
    kal_uint8 cipher_ind;
    res_req_cause msg_type;
    kal_uint8 nsapi;
    kal_uint32 tlli;
    kal_uint8 pfi;
    concise_qos_struct qos_param;
    peer_msg_id_struct peer_msg_id;
} mm_ratcm_ps_data_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    //kal_uint8 mui;
    DC_Status status;
    peer_msg_id_struct peer_msg_id;
} mm_ratcm_ps_data_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_integrity_applied;
    kal_uint32 tlli;
} mm_ratcm_ps_data_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_cs_reset_keys;
    kal_bool is_ps_reset_keys;
} mm_ratcm_reset_keys_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint32 tlli;
} mm_ratcm_llc_resume_req_struct; /* Should be same as ratcm_llc_resume_req_struct */

typedef struct {
    LOCAL_PARA_HDR
    kal_uint32 tlli;
} mm_ratcm_llc_suspend_req_struct; /* Should be same as ratcm_llc_suspend_req_struct */

typedef struct {
    LOCAL_PARA_HDR
    kal_uint32 tlli;
    res_req_cause cause; /* res_req_cause */
    llgmm_cell_update_type_enum cell_update_type; /* llgmm_cell_update_type_enum */
} mm_ratcm_llc_trigger_req_struct; /* Should be same as ratcm_llc_trigger_req_struct */

#ifdef __PS_HO__
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 cipher_algo;
} mm_ratcm_llc_psho_ind_struct; /* Should be same as ratcm_llc_psho_ind_struct */
#endif

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_expiry; /*KAL_TRUE: T3122 expires, MM will retry LU immediately
						  KAL_FALSE: T3122 is stopped */
} mm_ratcm_t3122_timeout_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_expiry; /*KAL_TRUE: CCO activation time expires, MM will retry LU immediately
						  KAL_FALSE: CCO activation time is stopped */
} mm_ratcm_cco_activation_time_timeout_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    rat_enum rat;
} mm_ratcm_signal_appear_ind_struct;

#ifdef __DYNAMIC_BAND_SEL__
typedef struct {
    LOCAL_PARA_HDR
    band_selection_enum gsm_band; /* refer to band_selection_enum value*/
    kal_bool is_gsm_band_present;
    kal_uint8 umts_fdd_band[SIZE_OF_UMTS_BAND];    /* 3G band change */
    kal_bool is_umts_band_present; /* 3G band change */
}mm_ratcm_set_preferred_band_req_struct;
#endif

#if defined(__GEMINI__) || defined(__SGLTE__)
typedef struct {
    LOCAL_PARA_HDR
    sim_config_status_enum sim_config_status;
    sim_insert_status_enum sim_insert_status;
} mm_ratcm_sim_status_update_req_struct;
#endif /*__GEMINI__ || __SGLTE__*/

#ifdef __GEMINI__
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 req_id;
} mm_ratcm_ps_session_start_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_success; /*TRUE if session can be started*/
    kal_uint8 req_id;
} mm_ratcm_ps_session_start_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    rsvas_service_type_enum cause;
} mm_ratcm_suspend_ind_struct;

#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
//mtk02475: local param struct is only exist in GEMINI 2.0 project
typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_virtual_idle_mode;
} mm_ratcm_resume_ind_struct;
#endif /* __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_virtual_idle_mode;
} mm_ratcm_virtual_mode_ind_struct;
#endif /* __GEMINI__ */

#ifdef __MONITOR_PAGE_DURING_TRANSFER__
typedef struct {
    LOCAL_PARA_HDR
    gprs_transfer_preference_enum prefer;
} mm_ratcm_set_gprs_transfer_preference_req_struct;
#endif

/* MAUI_02852442, __NO_PSDATA_SEND_SCRI__ */
typedef struct {
    LOCAL_PARA_HDR
    kal_bool force_send_SCRI;
    end_session_cause_enum cause;
}mm_ratcm_end_ps_data_session_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    end_session_result_enum cause;
}mm_ratcm_end_ps_data_session_cnf_struct;
/* __NO_PSDATA_SEND_SCRI__ */

typedef struct {
    LOCAL_PARA_HDR
    rat_enum rat;
    domain_id_enum connection_domain;
    kal_bool is_gibi_tag_valid;
    kal_uint16 gibi_tag;
} mm_ratcm_cell_change_finish_ind_struct;

/* MAUI_03101878, [Silver Clam][CV][SilverClam-94]Pre-CV-CMAS: GPRS failed due to timeout */
typedef struct {
    LOCAL_PARA_HDR
    lai_struct current_lai;
} mm_ratcm_cb_loc_update_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_bool is_sim_inserted;
    kal_bool is_delete_pending;
} mm_ratcm_sim_info_reset_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    RATCM_RRC_LocalReleaseType localReleaseType;
    kal_uint16 locally_released_PS_RAB_bitmap;
    //traffic_class_enum max_traffic_class;
} mm_ratcm_local_release_ind_struct;

//__LTE__
typedef struct{
    LOCAL_PARA_HDR
    eutran_cap_enum eutran_cap;
} mm_ratcm_eutran_cap_update_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_successful;
} mm_ratcm_eutran_cap_update_cnf_struct;

typedef struct{
    LOCAL_PARA_HDR
    irat_type_enum	irat_type;  //Indicates the inter-RAT type
    rat_type_enum	source_rat; //Source RAT (GAS or UAS)
    rat_type_enum	target_rat; //Target RAT (Should be EAS)
    void*	as_info_ptr;    //Indicates the address of the activation request for RAT change to LTE, the information is dedicated for AS.
                            //The buffer will be freed by soure or target AS
    ratcm_gas_security_mode_req_struct	gas_security;   //Indicates the GERAN security context if target_rat is GAS.
                            //Note that if the RAT change is failed and return to LTE, the security context should be reverted to the original one. NAS will send RATCM_GAS_SECURITY_MODE_REQ to update the original security information when NAS receives RAT_CHANGE_CNF indicated that the inter-RAT procedure is failed.
    uas_security_context_struct	uas_security[2];   //Indicates the UTRAN security context if target_rat is UAS.
                            //Note that if the RAT change is failed and return to LTE, the security information should be reverted to the original one. NAS will send RATCM_RRCE_SECURITY_MODE_REQ to update the original security information when NAS receives RAT_CHANGE_CNF indicated that the inter-RAT procedure is failed.
    csfb_indicator_enum	csfb_indicator; //Indicate that the purpose of current inter-RAT change is for CS fallback which is combined the information (MobilityFromEutra) from ERRC and the processing type of CSFB in EMM.
    loopback_mode_status_enum loopback_mode_status; //Notify RATCM to enter test mode for LTE-LBM mode B
    kal_bool             is_lai_valid;  //CSFB enhancement
    lai_struct           lai;           //CSFB enhancement
    kal_bool             is_srvcc;      //SRVCC support. If is_srvcc=KAL_TRUE, it means RATCM vsd_mod is 4. (is_r99_nw = KAL_TRUE)
} mm_ratcm_rat_change_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    irat_type_enum	irat_type;  //Indicates the inter-RAT type
    rat_type_enum	source_rat; //Source RAT
    rat_type_enum	target_rat; //Target RAT
    irat_result_enum	irat_result;    //The result of inter-RAT change
    void*	as_info_ptr;    //The pointer of AS container information
    domain_id_enum	connection_domain;  //Indicates that the current connection domain for the target RAT
    kal_bool is_gibi_tag_valid;
    kal_uint16 gibi_tag;
} mm_ratcm_rat_change_cnf_struct;

typedef struct{
    LOCAL_PARA_HDR
    irat_type_enum	irat_type;
    rat_type_enum	source_rat; //Source RAT (GAS or UAS)
    rat_type_enum	target_rat; //Target RAT (Should be EAS)
    void*	as_info_ptr;    //Indicates the address of the activation request for RAT change to LTE, the information is dedicated for AS.
                            //The buffer will be freed by soure or target AS
    kal_uint8 nas_security_param[NAS_SECURITY_PARAM_LEN];
                //NAS security parameter (Only valid for IRHO from UAS)
                //Byte1 ~ 4: NouceMME
                //Byte5: Selected Algorithm (Ciphering/Integrity)
                //Byte6: eKSI (including type of security context)
} mm_ratcm_rat_change_ind_struct;

typedef struct{
    LOCAL_PARA_HDR
    irat_type_enum	irat_type;
    rat_type_enum	source_rat; //Source RAT (GAS or UAS)
    rat_type_enum	target_rat; //Target RAT (Should be EAS)
    irat_result_enum	irat_result; //The result of inter-RAT change
    irat_reject_cause_enum irat_reject_cause; //Reject cause when irat_result is equal to IR_RESULT_REJECT.
    void*	as_info_ptr;    //Indicates the address of the activation request for RAT change to LTE, the information is dedicated for AS.
                            //The buffer will be freed by soure or target AS
} mm_ratcm_rat_change_rsp_struct;

typedef struct{
    LOCAL_PARA_HDR
    paging_type_enum paging_type;
    csfb_service_type_enum paging_service;
}mm_ratcm_page_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_completed;
}mm_ratcm_deactivate_cnf_struct;

#if defined(__GEMINI__)
typedef struct
{
   LOCAL_PARA_HDR
   cs_status_enum  status;
} mm_ratcm_cs_status_update_req_struct;
#endif

/*For TDD call clearing optimization*/
#ifdef __UMTS_TDD128_MODE__
typedef struct
{
    LOCAL_PARA_HDR
} mm_ratcm_force_rel_req_struct;
#endif
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 imeisv_value_digit0;
    kal_uint8 imeisv_value_digit_byte[8];
}mm_ratcm_set_imei_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool is_pch_state;
}mm_ratcm_rrc_state_ind_struct;

#endif /* MM_RATCM_STRUCT_H */
