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
 *   nwsel_mm_struct.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 * This file define the interface structure used by NWSEL_MM SAP
 *
 * Author:
 * -------
 * -------
 *
 ******************************************************************************/

#ifndef NWSEL_MM_STRUCT_H
#define NWSEL_MM_STRUCT_H

#include "l3_inc_enums.h"
#include "mcd_l3_inc_struct.h"
#include "l3_inc_local.h"
#include "as2nas_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "ps_public_enum.h"
#include "rsvas_enum.h"
#include "mm_mmi_enums.h"
#include "mm_ratcm_enums.h"

typedef struct {
    LOCAL_PARA_HDR  
    kal_uint8 trx_id;
    plmn_search_type_enum plmn_search_type;
    rat_enum rat;
    kal_uint8 plmn_id_count;
    plmn_id_struct plmn_id[MAX_NUM_SEARCH_PLMN];
    kal_bool is_manual_sel;
    kal_bool is_clear_abnormal_state;
    kal_bool force_to_release;
#if defined(__3G_CSG_SUPPORT__) || defined (UNIT_TEST)
    kal_bool is_manual_csg_sel;
    kal_uint32 csg_id;
#endif    
    kal_uint16 factory_mode_arfcn; //0xFFFF means invalid arfcn, /* 20081110 mtk00714, for fast camp on test machine */    
    kal_bool  trigger_by_signal_appear;
    
#if defined(__LTE_RAT__) && defined (__UMTS_TDD128_MODE__) && !defined (__SGLTE__)
    kal_bool  trigger_by_4g_plmn_loss;
#endif
#ifdef __UMTS_R7__
    kal_bool  is_higher_plmn_search; //CSCE_R7	
#endif
#if (defined(__OP01__) && defined(__GEMINI__)) 
    kal_bool  is_power_on;  //for CMCC case 5.1.1: is first search after power on
#endif
} nwsel_mm_plmn_search_req_struct;

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
    kal_bool is_ps_conn_releasing;
#if defined(__UMTS_FDD_MODE__) || defined(__TD_NETWORK_SHARING__) || defined (UNIT_TEST)
    kal_uint8 multi_plmn_count;
    plmn_id_struct multi_selected_plmn[MAX_NUM_MULTI_PLMN];
    as_cell_type_enum multi_selected_cell_type[MAX_NUM_MULTI_PLMN];
#endif
} nwsel_mm_plmn_search_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR   
    kal_bool force_to_release;
} nwsel_mm_deactivate_req_struct;

typedef struct {
    LOCAL_PARA_HDR   
    kal_bool is_completed;
    kal_bool is_ps_conn_releasing;
} nwsel_mm_deactivate_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR  
    kal_bool is_plmn_search_lte_ongoing;
    as_cell_type_enum cell_type;               // 4G camped on cell type
} nwsel_mm_search_status_update_req_struct;

typedef struct {
    LOCAL_PARA_HDR  
    kal_uint16 gibi_tag;
    rat_enum rat;
    kal_bool is_data_pending;
    kal_bool is_sys_info_present;
    hplmn_status_enum hplmn_status;
    fplmn_status_enum fplmn_status;
    kal_bool is_in_eq_plmn_list;
    mm_cell_change_enum abnormal_cell_change;
    mm_cell_change_enum abnormal_rai_cell_change;
    plmn_id_struct plmn_id;
    kal_uint8 la_code[2];
    kal_uint8 ra_code;
    kal_uint32 cell_id; //mtk02475: extended cell id in UMTS
    kal_bool cell_support_cs;
    kal_bool cell_support_ps; /* if FALSE, nmo and ra_code should not refer. */
    kal_bool is_acc_class_present;
    kal_uint16 acc_class;
    kal_uint8 extra_info_bitmask; /* mtk02475: for DSAC/data_speed_support update in connected mode*/
#if defined (__R6_DSAC__) || defined (UNIT_TEST)
    kal_bool is_dsac_present;
    kal_uint16 cs_dsac;
    kal_uint16 ps_dsac;
#endif
    kal_uint8 t3212_timer_val;
    network_mode_enum nmo;
    as_cell_type_enum cell_type;
    att_flag_enum att_flag;
    kal_bool mscr;
    rr_mm_sgsnr_flag_enum sgsnr;
#ifdef __PS_SERVICE__
    data_speed_support_enum cell_data_speed_support; /* MAUI_02361221: for egprs and hspa */
#endif	

#if defined (__PPACR_SUPPORT__) || defined (UNIT_TEST)
    kal_bool is_ppacr_present;
    ppacr_info_struct ppacr_info;
#endif

#if defined (__3G_CSG_SUPPORT__) || defined (UNIT_TEST)
    csg_access_mode_enum csg_access_mode;
    csg_info_struct csg_info;
#endif 

#ifdef __LTE_RAT__
    kal_bool is_gprs_info_in_si13_deferred;
#endif

} nwsel_mm_sys_info_update_req_struct;

typedef mm_sys_info_ind_struct nwsel_mm_sys_info_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    plmn_id_struct plmn_id;
    kal_uint8 la_code[2];
    kal_uint16 cell_id;
    kal_bool is_on_hplmn;
} nwsel_mm_cell_global_identity_info_update_req_struct;

typedef mm_cell_global_identity_info_ind_struct nwsel_mm_cell_global_identity_info_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_uas_plmn_list_present;
    as_plmn_list_struct uas_plmn_list;
    kal_bool is_gas_plmn_list_present;
    as_plmn_list_struct gas_plmn_list;
#ifdef __GEMINI__
    as_suspend_mode_reason_enum cause; /* for RR suspend mode */
#endif /* __GEMINI__ */
    csfb_indicator_enum csfb_ind;
    kal_bool is_nas_csfb_ongoing;
} nwsel_mm_plmn_loss_ind_struct;

typedef struct {
    LOCAL_PARA_HDR   
    rat_enum rat;
    kal_bool is_manual_list;
} nwsel_mm_plmn_list_req_struct;

typedef struct {
    LOCAL_PARA_HDR   
    kal_bool is_uas_plmn_list_present;
    as_plmn_list_struct uas_plmn_list;
    kal_bool is_gas_plmn_list_present;
    as_plmn_list_struct gas_plmn_list;
} nwsel_mm_plmn_list_cnf_struct;

#ifdef __3G_CSG_SUPPORT__
typedef struct {
    LOCAL_PARA_HDR
    rat_enum rat;
    kal_uint8 plmn_count;
    plmn_id_struct plmn_id[MAX_NUM_EQ_PLMN];
} nwsel_mm_csg_list_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    //kal_bool is_uas_csg_list_present;
    as_csg_list_struct uas_csg_list;
} nwsel_mm_csg_list_cnf_struct;
#endif

typedef struct {
    LOCAL_PARA_HDR 
    regn_proc_status_enum nwsel_proc_status;
    plmn_search_status_enum plmn_search_status; 
    plmn_search_type_enum plmn_search_type;	/* new plmn search type */
    kal_bool is_send_to_as;
} nwsel_mm_regn_status_update_req_struct;

#ifdef __DYNAMIC_BAND_SEL__
typedef struct {
    LOCAL_PARA_HDR
    band_selection_enum gsm_band; /* refer to band_selection_enum value*/ 
    kal_bool is_gsm_band_present;  
    kal_uint8 umts_fdd_band[2];    /* 3G band change */
    kal_bool is_umts_band_present; /* 3G band change */
}nwsel_mm_set_preferred_band_req_struct;
#endif

typedef struct {
    LOCAL_PARA_HDR
    lr_result_enum lr_result;
    mm_cause_enum lr_cause;
    mm_proc_enum mm_proc;
    kal_uint8 attempt_counter; //update only when lr_proc needed
    plmn_id_struct rplmn; //from stored lai. Valid when LR_ACCEPT & LR_ACCEPT_PS_ONLY
    kal_bool forbidden_plmn_update_not_allowed; /*MM may change NW reject cause, and no need to add forbidden PLMN */
    kal_bool is_update_eq_plmn_needed; /* always check; indicate if NWSEL need to update EPLMN */
    kal_uint8 eq_plmn_byte_count;
    kal_uint8 eq_plmn_id[MAX_NUM_EQ_PLMN*3]; /* the EPLMN list from NW; 3 is NWSEL_PLMN_LEN */
    kal_bool is_back_to_abnormal_la;
    kal_bool is_rau_performed;
    kal_bool is_stored_lai_same_as_current;
    kal_bool stored_lai_valid;
    kal_bool stored_rai_valid;
    gsm_state_enum gsm_attach_state;
    gprs_state_enum gprs_attach_state;
    gsm_update_status_enum gsm_update_status;
    gprs_update_status_enum gprs_update_status;
#if defined(__ECALL_SUPPORT__) || defined (UNIT_TEST)
    mm_check_ecall_status_enum ecall_status;
#endif
#if defined (__SGLTE__)
    kal_bool    is_peer_reg_result;
    lai_struct  mm_peer_lai;
#endif
} nwsel_mm_regn_result_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    domain_id_enum conn_domain;
} nwsel_mm_out_of_service_ind_struct;

#ifdef __GEMINI__
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    as_suspend_mode_reason_enum cause;
} nwsel_mm_suspend_ind_struct;

#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
//mtk02475: local param struct is only exist in GEMINI 2.0 project
typedef struct {
   LOCAL_PARA_HDR
    kal_bool is_virtual_idle_mode;
} nwsel_mm_resume_ind_struct;
#endif /* __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_virtual_idle_mode;
} nwsel_mm_virtual_mode_ind_struct;
#endif /* __GEMINI__ */

typedef struct {
    LOCAL_PARA_HDR
    mm_event_type_enum event;
} nwsel_mm_event_ind_struct;

typedef struct {
    LOCAL_PARA_HDR   
    kal_uint8 plmn_id_count;
    plmn_id_struct plmn_id[MAX_NUM_HPLMN]; //MAX_NUM_HPLMN: 4
    kal_uint8 home_country_mcc[3];
} nwsel_mm_hplmn_info_update_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    eutran_cap_enum eutran_cap;
    kal_bool is_eucap_sysinfo_triggered;
} nwsel_mm_eutran_cap_update_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_successful;
} nwsel_mm_eutran_cap_update_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    voice_domain_preference_enum utran_voice_domain_preference;
    kal_bool is_eutran_param_updated; /* if FALSE, the following parameters are invalid */
    kal_bool is_eutran_vdp_or_ue_usage_changed;
    voice_domain_preference_enum eutran_voice_domain_preference;
    ue_usage_setting_enum ue_usage_setting;
} nwsel_mm_voice_prefer_ue_usage_update_req_struct;

#endif /* NWSEL_MM_STRUCT_H */
