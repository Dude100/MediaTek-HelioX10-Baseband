/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   nwsel_eval_struct.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   message and common structure definition between NWSEL and EVAL module
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	Change full_band_search to full_band_searched_3g_status & full_band_searched_4g
 *
 * removed!
 * removed!
 * MMIVT2MP6
 *
 * removed!
 * removed!
 * .
 *
 * 06 19 2014 roy.lin
 * removed!
 * Update interface for PS detach without disable EUTRAN.
 *
 * removed!
 * removed!
 * add full_band_search
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Merging from //MOLY_CBr/maruco.tu/MOLY_CBr.factory/mcu/modem/...
 *
 * removed!
 * removed!
 * Merging
 *  	
 * 	//MOLY_CBr/ben.chiu/MOLY_VOLTE.PHASE2.DEV/mcu/...
 *  	
 * 	to //MOLY/TRUNK/MOLY/mcu/...
 *
 * removed!
 * removed!
 * MT last PDN deactivation.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * NAS REJECT CAUSE interface, MM<->EMM,MM<->NWSEL,MM<->MM
 * removed!
 * removed!
 * add search_type to search_status_update_req_struct
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * merge back to MOLY.
 *
 * removed!
 * removed!
 * td-fdd lte separate nwsel interface.
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * MOLY_CBr to MOLY.
 ****************************************************************************/


#ifndef  _NWSEL_EVAL_STRUCT_INC
#define  _NWSEL_EVAL_STRUCT_INC


#include "nwsel_eval_enums.h"
#include "l3_inc_local.h"
#include "ps_public_enum.h"
#include "l3_inc_enums.h"

/***** common structure definition *****/
typedef struct
{
    nas_proc_enum               emm_proc;
    lr_result_enum              lr_result;
    mm_cause_enum               lr_cause;
    esm_cause_enum              esm_cause; 
    kal_uint8                   attempt_counter;
    kal_uint8                   esm_attempt_counter;
    additional_update_result_enum   additional_update_result;
    eps_attach_update_result_enum   eps_attach_update_result;
    kal_bool                        is_ims_vops_support;
    lte_duplex_type_enum        lte_type;
    kal_bool                    is_ps_reattach;
} proc_result_only_struct;

typedef struct
{
    kal_bool                        stored_lai_valid;
    kal_bool                        stored_guti_valid;
    gsm_state_enum                  gsm_attach_state;
    eps_state_enum                  lte_attach_state;
    gsm_update_status_enum          gsm_update_status;
    eps_update_status_enum          lte_update_status;
} update_param_struct;

/***** message structure definition *****/
typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8                   trx_id;
    plmn_search_type_enum       plmn_search_type;
    lte_duplex_type_enum        lte_type;
    kal_uint8                   plmn_id_count;
    plmn_id_struct              plmn_id[MAX_NUM_SEARCH_PLMN];
    kal_bool                    is_manual_sel;        // if search is manual selection
    kal_bool                    force_to_release;
    kal_bool                    is_manual_csg_sel;    // identify if the csg_id below is valid
    kal_uint32                  csg_id;
    kal_bool                    trigger_by_signal_appear;
    kal_bool                    is_higher_plmn_search;
    kal_uint32                  factory_mode_arfcn; //0xFFFFFFFF means invalid arfcn - do normal search. For fast camp on test machine
#if (defined(__OP01__) && defined(__GEMINI__)) 
    kal_bool                    is_power_on; //for CMCC case 5.1.1: is first search after power on
#endif

} nwsel_eval_plmn_search_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   trx_id;
    plmn_search_result_enum     result;
    kal_bool                    is_eas_plmn_list_present;
    as_plmn_list_struct         eas_plmn_list;
    kal_uint8                   multi_plmn_count;
    plmn_id_struct              multi_selected_plmn[MAX_NUM_MULTI_PLMN];
    as_cell_type_enum           multi_selected_cell_type[MAX_NUM_MULTI_PLMN];

} nwsel_eval_plmn_search_cnf_struct; 


typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                    force_to_release;

} nwsel_eval_deactivate_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                    is_completed;

} nwsel_eval_deactivate_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                    is_plmn_search_2G3G_ongoing;
    as_cell_type_enum           cell_type;               // 2G/3G camped on cell type
    plmn_search_type_enum       plmn_search_type; /* Only for EMM/PLMNSEL to know if needed to check Forbidden TA list */

} nwsel_eval_search_status_update_req_struct;

#ifdef __VOLTE_SUPPORT__
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                    prefer_ims_emergency;
} nwsel_eval_search_preference_update_req_struct;
#endif

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                  gibi_tag;
    kal_uint8                   ta_code[2];
    kal_uint8                   multi_plmn_count;
    plmn_id_struct              multi_plmn_id[MAX_NUM_MULTI_PLMN];
    as_cell_type_enum           multi_plmn_cell_type[MAX_NUM_MULTI_PLMN];
    csg_access_mode_enum        csg_access_mode;
    csg_info_struct             csg_info;
    lte_duplex_type_enum        lte_type;
#if defined( __VOLTE_SUPPORT__) || defined (UNIT_TEST)
    kal_bool ims_emergency_support;
#endif
} nwsel_eval_sys_info_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                  gibi_tag;
    plmn_id_struct              plmn_id;
    kal_uint8                   ta_code[2];
    as_cell_type_enum           cell_type;
    hplmn_status_enum           hplmn_status;
    fplmn_status_enum           fplmn_status;
    kal_bool                    is_in_eq_plmn_list;
    csg_access_mode_enum        csg_access_mode;
    csg_info_struct             csg_info;
#if defined( __VOLTE_SUPPORT__) || defined (UNIT_TEST)
    kal_bool ims_emergency_support;
#endif
} nwsel_eval_sys_info_update_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    event_type_enum             event_type_bitmask;
    update_eplmn_struct         eplmn_info;
    proc_result_only_struct     proc_result_only;
    update_param_struct         update_param;
#ifdef __SGLTE__    
    mmdc_peer_lr_result_struct  peer_lr_result;
#endif /* __SGLTE__ */

} nwsel_eval_regn_result_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    regn_proc_status_enum       mm_proc_status;         // indicate if MS is in limited or no service
    plmn_search_status_enum     plmn_search_status;
    plmn_search_type_enum       plmn_search_type;
    // sniff RPLMN 
    // only valid when the conditions hold 
    // plmn_search_status  == PLMN_SEARCH_UNRELATED
    // mm_proc_status == (MS_IN_NO_SERVICE || MS_IN_LIMITED_SERVICE)
    kal_uint8                   plmn_id_count;
    plmn_id_struct              plmn_id[MAX_NUM_SEARCH_PLMN];
} nwsel_eval_regn_status_update_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                    is_manual_list;
    lte_duplex_type_enum        lte_type;

} nwsel_eval_plmn_list_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    as_plmn_list_struct         eas_plmn_list;

} nwsel_eval_plmn_list_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    lte_duplex_type_enum        lte_type;
    kal_uint8                   plmn_count;
    plmn_id_struct              plmn_id[MAX_NUM_EQ_PLMN];  // include RPLMN

} nwsel_eval_csg_list_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    as_csg_list_struct          eas_csg_list;

} nwsel_eval_csg_list_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    domain_id_enum conn_domain;
} nwsel_eval_out_of_service_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    as_plmn_list_struct         eas_plmn_list;
    full_band_searched_enum     full_band_searched_3g_status;
    kal_bool                    full_band_searched_4g;
} nwsel_eval_plmn_loss_ind_struct;

#if defined( __VOLTE_SUPPORT__) || defined (UNIT_TEST)
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   emc_fplmn_count;
    plmn_id_struct              emc_fplmn_list[MAX_NUM_EMC_FPLMN];
    
} nwsel_eval_emc_fplmn_list_update_req_struct;
#endif

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   eq_plmn_count;
    plmn_id_struct              eq_plmn_id[MAX_NUM_EQ_PLMN];
    
} nwsel_eval_eq_plmn_list_update_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   plmn_id_count;
    plmn_id_struct              plmn_id[MAX_NUM_HPLMN];
    kal_uint8                   home_country_mcc[3];
} nwsel_eval_hplmn_info_update_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    voice_domain_preference_enum    eutran_voice_domain_preference;
    ue_mode_enum                    ue_mode;
    kal_bool                        sms_only;
    voice_domain_preference_enum    utran_voice_domain_preference;
} nwsel_eval_uemode_param_update_req_struct;

#if defined( __VOLTE_SUPPORT__) || defined (UNIT_TEST)
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool        prefer_ims_emergency;
} nwsel_eval_plmn_search_preference_update_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool        in_ims_emergency;
} nwsel_eval_emergency_status_update_ind_struct;

#endif // __VOLTE_SUPPORT__

#if defined(__LTE_RAT__) && (defined(__GSM_RAT__) || defined(__UMTS_RAT__))         
#if (defined(__OP01__) && defined(__GEMINI__)) 
typedef errc_sim_protect_req_struct nwsel_eval_power_on_protection_req_struct;
#endif
#endif

#if 0 /* mark empty primitive message structure */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* mark empty primitive message structure */


#endif   /* ----- #ifndef _NWSEL_EVAL_STRUCT_INC ----- */

