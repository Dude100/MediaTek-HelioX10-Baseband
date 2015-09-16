/*******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *    ratcm_gas_struct.h
 *
 * Project:
 * --------
 *    MONZA
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

#ifndef _RATCM_GAS_STRUCT_H
#define _RATCM_GAS_STRUCT_H


#ifdef __GEMINI__
#include "rsvas_enum.h"
#endif

/* add RHR */
#include "ratcm_gas_enums.h"
#include "mcd_l3_inc_struct.h"
#include "l3_inc_enums.h"
#include "l3_inc_local.h"
#include "rr_mpal_interface.h"
#include "l3llc_enums.h"
#include "kal_general_types.h"
#include "ps_public_enum.h"


/*----------------------------------------------------------------------------*/
/*                            pre-define struct                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                             GAS to RATCM                                   */
/*----------------------------------------------------------------------------*/

typedef struct{
    LOCAL_PARA_HDR
    domain_id_enum cn_domain_id;
    as_est_cnf_cause_enum result;
    kal_bool wait_gibi_flag;
    kal_bool is_rrc_conn_already_existed;
}ratcm_gas_conn_est_cnf_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_bool is_successful;
    domain_id_enum cn_domain_id;
}ratcm_gas_conn_est_ind_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_bool is_successful;
    domain_id_enum cn_domain_id;
    kal_bool ps_resume_flag;
    kal_bool wait_gibi_flag;
}ratcm_gas_conn_rel_cnf_struct;

typedef struct{
    LOCAL_PARA_HDR
    domain_id_enum cn_domain_id;
    kal_bool ps_resume_flag;
    kal_bool wait_gibi_flag;
}ratcm_gas_conn_rel_ind_struct;

typedef struct{
    LOCAL_PARA_HDR
    DC_Priority sapi;
    kal_uint8 mui;
    kal_bool is_successful;
}ratcm_gas_data_cnf_struct;

typedef struct{
    LOCAL_PARA_HDR
    domain_id_enum cn_domain_id;
}ratcm_gas_data_ind_struct;

typedef struct{
    LOCAL_PARA_HDR
    as_plmn_list_struct plmn_list;
}ratcm_gas_plmn_list_cnf_struct;

typedef struct{
    LOCAL_PARA_HDR
#ifdef __LTE_RAT__
    csfb_indicator_enum csfb_indicator;
#endif /* __LTE_RAT__ */
    as_plmn_list_struct plmn_list;
}ratcm_gas_plmn_loss_ind_struct;

typedef struct{
    LOCAL_PARA_HDR
}ratcm_gas_signal_appear_ind_struct;

typedef struct{
    LOCAL_PARA_HDR
    domain_id_enum cn_domain_id;
    ue_id_type_enum ue_id_type;
    kal_uint8 ue_identity[9];
}ratcm_gas_page_ind_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint8 trx_id;
    plmn_search_result_enum result;
    plmn_id_struct selected_plmn;
    kal_bool is_plmn_list_valid;
    as_plmn_list_struct plmn_list;
}ratcm_gas_plmn_search_cnf_struct;

typedef struct{
    LOCAL_PARA_HDR
    ready_timer_status_enum status;
}ratcm_gas_ready_timer_update_ind_struct;

typedef struct{
    LOCAL_PARA_HDR
    sync_ind_cause_enum cause;
    channel_type_enum channel_type;
    channel_mode_enum channel_mode;
    kal_bool is_ciphering_on;
}ratcm_gas_sync_ind_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint16 gibi_tag;
    plmn_id_struct plmn_id;
    kal_uint16 cell_id;
    as_cell_type_enum cell_type;
    kal_uint16 access_class;
    kal_bool cell_support_ps;
    kal_bool cell_support_cs;
    kal_uint8 la_code[2];
    kal_uint8 ra_code;
    kal_uint8 att_flag;
    kal_uint8 t3212_timer_val;
    kal_uint8 nmo;
    kal_uint8 mscr;
    kal_uint8 sgsnr;
    kal_uint8 cell_support_egprs;
#ifdef __LTE_RAT__
    kal_bool is_gprs_info_in_si13_deferred;
#endif /* __LTE_RAT__ */
}ratcm_gas_sys_info_ind_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    plmn_id_struct plmn_id;
    kal_uint8 la_code[2];
    kal_uint16 cell_id;
}ratcm_gas_cell_global_identity_info_ind_struct;

#if defined(__UMTS_RAT__) || defined (__LTE_RAT__)
typedef struct{
    LOCAL_PARA_HDR
    domain_id_enum connection_domain;
    rat_type_enum active_rat;
} ratcm_gas_cell_change_finish_ind_struct;
#endif /* defined(__UMTS_RAT__) || defined (__LTE_RAT__)*/

#ifdef __GEMINI__
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 is_success; /*TRUE if session can be started*/
    kal_uint8 req_id;
} ratcm_gas_ps_session_start_cnf_struct;
#endif

#ifdef __LTE_RAT__
typedef struct{
    LOCAL_PARA_HDR
    irat_type_enum irat_type;
    rat_type_enum source_rat;
    rat_type_enum target_rat;
    void* as_info_ptr;
}ratcm_gas_rat_change_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    irat_type_enum irat_type;
    rat_type_enum source_rat;
    rat_type_enum target_rat;
    irat_result_enum irat_result;
    void* as_info_ptr;
    domain_id_enum connection_domain;
} ratcm_gas_rat_change_cnf_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_bool is_successful; /* Indicates whether enabling or disabling E-UTRAN capability is successful. */
} ratcm_gas_eutran_cap_update_cnf_struct;
#endif /* __LTE_RAT__ */

/*----------------------------------------------------------------------------*/
/*                                RATCM to GAS                                */
/*----------------------------------------------------------------------------*/

typedef struct{
    LOCAL_PARA_HDR
    kal_bool is_sim_inserted;

    /* ALPS01612057: In orginial design, MM will queue SIM_ERROR during PLMN search, 
       but this causes SIM status unsynced between AS/NAS. Because SIM_READY is sent 
       from SIM to RR whereas SIM_ERROR is sent only from SIM to MM. MM proposes the
       solution: delete pending SIM_READY to sync AS/NAS sim status. */
    kal_bool is_delete_pending;
}ratcm_gas_sim_info_reset_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint8 la_code[2];
    forbidden_la_type_enum forbidden_la_type;
    plmn_id_struct plmn_id;
}ratcm_gas_add_forbidden_la_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint8 mui;
    kal_uint16 gibi_tag;
    domain_id_enum cn_domain_id;
    gas_est_cause_enum estb_cause;
#ifdef __LTE_RAT__
    csfb_indicator_enum csfb_indicator;
    csfb_service_type_enum csfb_service_type;
#endif /* __LTE_RAT__ */
}ratcm_gas_conn_est_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    domain_id_enum cn_domain_id;
}ratcm_gas_conn_rel_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint8 mui;
    kal_uint16 gibi_tag;
    domain_id_enum cn_domain_id;
}ratcm_gas_data_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint8 la_code[2];
    plmn_id_struct plmn_id;
    kal_bool delete_all;
}ratcm_gas_del_forbidden_la_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint8 eq_plmn_count;
    plmn_id_struct eq_plmn_id[MAX_NUM_EQ_PLMN];
}ratcm_gas_eq_plmn_list_update_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint8 requested_band; /* refer to gsm_band_enum */
    kal_uint8 drx_para[2]; /* for split paging cycle and non-drx timer */
    kal_uint8 imeisv_value_digit0;
    kal_uint8 imeisv_value_digit_byte[8];
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
    gprs_transfer_preference_enum prefer;
#endif /* __MONITOR_PAGE_DURING_TRANSFER__ */
}ratcm_gas_init_req_struct;

#ifdef __DYNAMIC_BAND_SEL__
/* MAUI_01972920 */
typedef struct{
    LOCAL_PARA_HDR
    kal_uint8 gsm_band; /* refer to band_selection_enum value*/ 
}ratcm_gas_set_preferred_band_req_struct;
#endif

typedef struct{
    LOCAL_PARA_HDR
    kal_bool is_tmsi_lai_present;
    kal_uint8 tmsi[4];
    lai_struct reg_lai;
    kal_bool is_ptmsi_rai_present;
    kal_uint8 ptmsi[4];
    rai_struct reg_rai;
}ratcm_gas_paging_param_assign_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_bool is_manual_list;
}ratcm_gas_plmn_list_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint8 trx_id;
    plmn_search_type_enum plmn_search_type;
    kal_uint16 factory_mode_arfcn; /* for factory_mode, assigned from AT_cmd */
    kal_uint8 plmn_count;
    plmn_id_struct plmn_id[MAX_NUM_SEARCH_PLMN];
    kal_bool is_manual_sel;
    kal_bool trigger_by_signal_appear; /* for fast recovery */
#ifdef __LTE_RAT__    
    kal_bool is_csfb_ongoing;
#endif
#if (defined(__OP01__) && defined(__GEMINI__)) 
    kal_bool  is_power_on;  //for CMCC case 5.1.1: is first search after power on
#endif
}ratcm_gas_plmn_search_req_struct;

typedef struct{
    LOCAL_PARA_HDR
	rat_enum rat_info;
}ratcm_gas_plmn_loss_info_update_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    action_on_ready_timer_enum action;
    gmm_ms_state_enum new_state;
    kal_uint32 value;
}ratcm_gas_ready_timer_update_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    regn_proc_status_enum proc_status;
    kal_uint32 t3212_or_t3302;
    gmm_ms_state_enum ms_state;
    mmas_regn_status_enum regn_status;
    plmn_search_status_enum plmn_search_status;
    plmn_search_type_enum plmn_search_type;
    /* __AUTH_FAIL_BAR_CELL__ */
    lai_struct lai; /* for bar cell list */
    kal_uint32 cell_id; /* for bar cell list (argument type sync. with UAS) */
    /* __AUTH_FAIL_BAR_CELL__ */
}ratcm_gas_regn_status_update_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint8 r_eq_plmn_count;
    plmn_id_struct r_eq_plmn_id[MAX_NUM_EQ_PLMN];
} ratcm_gas_rplmn_eq_plmn_list_update_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_bool is_gprs_required;
}ratcm_gas_service_change_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    rat_enum rat;
}ratcm_gas_set_rat_mode_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint32 old_tlli;
    kal_uint32 new_tlli;
    tlli_update_type_enum status_tlli;
    rai_struct rai;
}ratcm_gas_tlli_assign_req_struct;

#ifdef __MONITOR_PAGE_DURING_TRANSFER__
typedef struct{
    LOCAL_PARA_HDR
    gprs_transfer_preference_enum prefer;
}ratcm_gas_set_gprs_transfer_preference_req_struct;
#endif /* __MONITOR_PAGE_DURING_TRANSFER__ */

typedef struct {
    LOCAL_PARA_HDR
    kal_bool cbch_req;
} ratcm_gas_cbch_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint16 cbmi[CB_MAX_MSG_CBMI_NUM];
    kal_uint16 cbmid[CB_MAX_MSG_CBMID_NUM];
    kal_uint16 cbmir[CB_MAX_MSG_CBMIR_NUM];
    kal_uint16 dcs[CB_MAX_LANG_NUM];
    kal_bool is_all_language_on;    
    l4c_cb_set_type_enum set_type;
} ratcm_gas_cb_update_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint16 mi;    
    kal_uint16 sn;
} ratcm_gas_cb_msg_removal_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint16 sn;
    kal_uint16 mi;
    kal_uint8 dcs;
    kal_uint8 page;
    kal_uint8 pages;
    kal_uint8 is_mids;
    kal_uint8 mi_index;
    kal_uint8 page_data[CB_MAX_DATA_NUM_PER_PAGE];
	
    kal_uint8 valid_blk_num;
} ratcm_gas_cb_page_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    cb_geography_enum geography_type;
} ratcm_gas_cb_gs_change_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_expiry; /*KAL_TRUE: T3122 expires, MM will retry LU immediately
						  KAL_FALSE: T3122 is stopped */
} ratcm_gas_t3122_timeout_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_expiry; /*KAL_TRUE: CCO activation timer expires, MM will retry LU immediately
						  KAL_FALSE: CCO activation timer is stopped */
} ratcm_gas_cco_activation_time_timeout_ind_struct;

typedef struct {
    LOCAL_PARA_HDR   
    kal_uint8 plmn_id_count;
    plmn_id_struct plmn_id[MAX_NUM_HPLMN]; /* MAX_NUM_HPLMN: 4 */
    kal_uint8 home_country_mcc[3];
} ratcm_gas_hplmn_info_update_req_struct; //mtk02475: for MAUI_02456964

#if defined(__GEMINI__) || defined(__SGLTE__)

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sim_config_status;
    kal_uint8 sim_insert_status;
} ratcm_gas_sim_status_update_req_struct;

#endif /* __GEMINI__ || __SGLTE__ */

#ifdef __GEMINI__

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 req_id;
} ratcm_gas_ps_session_start_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    rsvas_service_type_enum cause;
} ratcm_gas_suspend_ind_struct;

#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
/* MAUI_02865693 */
typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_in_virtual;
} ratcm_gas_virtual_mode_ind_struct;

/* MAUI_02877191, this message contains no local_param except for GEMINI2.0 */
typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_in_virtual;
} ratcm_gas_resume_ind_struct;
#endif /* __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */
#endif /* __GEMINI__ */

#if defined(__GEMINI_GSM__) && defined( __UMTS_RAT__)
typedef struct {
    LOCAL_PARA_HDR
} ratcm_gas_no_ir_sig_proc_req_struct;
#endif

#ifdef __SET_IMEI_BY_PLMN__
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 imeisv_value_digit0;
    kal_uint8 imeisv_value_digit_byte[8];
}ratcm_gas_set_imei_req_struct;
#endif

#if defined(__GEMINI_GSM__) && defined( __LTE_RAT__)
typedef struct {
    LOCAL_PARA_HDR
    cs_status_enum status;
} ratcm_gas_cs_status_update_req_struct;
#endif

#ifdef __LTE_RAT__
typedef struct{    
    LOCAL_PARA_HDR
    irat_type_enum irat_type;
    rat_type_enum source_rat;
    rat_type_enum target_rat;
    void* as_info_ptr;
    ratcm_gas_security_mode_req_struct security_mode_info;
    csfb_indicator_enum csfb_indicator;
    kal_bool is_lai_valid;
    lai_struct lai;
}ratcm_gas_rat_change_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    irat_type_enum irat_type;
    rat_type_enum source_rat;
    rat_type_enum target_rat;
    irat_result_enum irat_result;
    irat_reject_cause_enum irat_reject_cause; //Reject cause when irat_result is equal to IR_RESULT_REJECT.
    void* as_info_ptr;
} ratcm_gas_rat_change_rsp_struct;

typedef struct{    
    LOCAL_PARA_HDR
    paging_type_enum paging_type;
    csfb_service_type_enum paging_service;
}ratcm_gas_page_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    eutran_cap_enum eutran_cap; /* Indicates whether E-UTRAN is enable or disabled. */
} ratcm_gas_eutran_cap_update_req_struct; 
#endif /* __LTE_RAT__ */
#endif /* _RATCM_GAS_STRUCT_H */
