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
 *	rac_context.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for definition of RAC context.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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

#ifndef _RAC_CONTEXT_H
#define _RAC_CONTEXT_H

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"

/* MAUI_02838008 [Gemini+] MM checkin */
#include "global_def.h"
#include "ps_public_enum.h"
#include "l3_inc_enums.h"
#include "l4crac_enums.h"

#include "mcd_l3_inc_struct.h"
#include "rac2l4c_struct.h"
#include "mmi2mm_struct.h"
#ifdef __SAT__
#include "ps2sat_struct.h"
#endif

#include "rac_defs.h"

#ifdef __LTE_RAT__
#include "rac_eval_struct.h"
#endif /* __LTE_RAT__ */

#include "rac_nwsel_struct.h"

#ifdef __MODEM_EM_MODE__
#include "em_struct.h"
#endif /* __MODEM_EM_MODE__ */

#ifdef __VOLTE_SUPPORT__
#include "ims_common_def.h"
#endif /* __VOLTE_SUPPORT__ */

/* if some header should be include before this one */
#if defined(__GSM_RAT__) || defined(__UMTS_RAT__)
typedef struct {
    kal_bool                            is_dedicated_mode;
    /* for RAC2 */
    kal_uint8                           requested_gsm_band;
    /* for RAC2 */
    rac_gmm_state_enum                  rac_gmm_state;
    rac_gmm_state_enum                  previous_rac_gmm_state;
    mm_cause_enum                       gmm_cause;
    /* for RAC2 */
#ifdef __UMTS_RAT__
    kal_uint8                           requested_umts_fdd_band[SIZE_OF_UMTS_BAND]; //UMTS only
#endif

#if (defined(__UMTS_RAT__) && defined(__GSM_RAT__))
   /*
     mtk03643: prefer_rat for MM to select rat to perform PLMN search when leave from flight mode or power on
     ir_prefer_rat for AS to stay in/reselect to the preferred rat
     */
   rat_enum                            irat; //WCDMA prefer feature
#endif /* (defined(__UMTS_RAT__) && defined(__GSM_RAT__)) */

#ifdef __MONITOR_PAGE_DURING_TRANSFER__
       gprs_transfer_preference_enum       gprs_transfer_preference; //mtk02475: user preference for MONITOR_PAGE_DURING_TRANSFER feature
#endif
//#ifdef __HSPA_PREFERENCE_SETTING__
        hspa_preference_enum               hspa_preference; // mtk02475: user preference for HSPA functionality
//#endif
#ifdef UNIT_TEST
        kal_uint16                         fake_hw_umts_band_capability; //mtk02475: MODIS UT for UMTS band customization
        kal_uint8                          fake_hw_gsm_band_capability; //mtk03643: MODIS UT for GSM band customization
#endif /* UNIT_TEST */

    l4_voice_domain_preference_enum         l4_voice_domain_preference;

    kal_bool                               is_ims_voice_available;
    } rac_ugrac_context_struct;
#endif /* defined(__GSM_RAT__) || defined(__UMTS_RAT__) */

#ifdef __LTE_RAT__
typedef struct
{
    kal_uint8                       requested_lte_band[SIZE_LTE_BAND];
    rac_emm_state_enum              rac_emm_state;
    rac_emm_state_enum              previous_rac_emm_state;	
	additional_update_result_enum   rac_emm_additional_update_result;
    emm_cause_enum                  emm_cause;
    esm_cause_enum                  esm_cause;
    ue_mode_enum                    ue_mode;
    ue_mode_enum                    last_ue_mode;
    ue_mode_enum                    nvram_ue_mode;
    ue_mode_enum                    ue_mode_exclude_18;
    kal_bool                        is_ue_mode_exclude_18_changed;
    ue_usage_setting_enum           ue_usage_setting;
    l4_voice_domain_preference_enum l4_voice_domain_preference;
    kal_bool                        sms_over_ip;
    kal_bool                        sms_over_sgs;
    kal_bool                        on_cause18_plmn;
    ims_reg_status_enum             ims_reg_status;
#ifdef __IMS_SUPPORT__    
    ims_dereg_cause_enum            ims_dereg_cause;
#endif /* __IMS_SUPPORT__ */
    kal_bool                        is_ims_voice_available;
    kal_bool                        is_ims_sms_available;
    kal_uint8                       ue_mode_profile;
    kal_bool                        sms_only;
    kal_bool                        is_vdp_changed;
    kal_bool                        is_ue_usage_setting_changed;
    kal_bool                        is_ue_mode_changed;
    kal_bool                        is_ims_reg_status_changed;
    kal_bool                        is_sms_only_changed;
    kal_bool                        is_initial_ue_mode_updated;
#ifdef __IMS_SUPPORT__	
    kal_bool                        is_ims_support_changed;
    kal_bool                        is_ims_support;
#endif /* __IMS_SUPPORT__ */
#ifdef __VOLTE_SUPPORT__
    kal_bool                        is_emergency_attached;
#endif /* __VOLTE_SUPPORT__ */
    kal_bool                        is_check_attach_domain;
    kal_uint8                       feature_config[NVRAM_LTE_FEATURE_CONFIG_SIZE];
} rac_erac_context_struct;
#endif /* __LTE_RAT__ */

typedef struct {

   kal_uint8                        imei[8];

   cell_info_and_rat_struct         current_cell_rat;
   plmn_id_rat_struct               selected_plmn_id;


   /* John Tang 2004/12/10: To keep the last content of "L4CRAC_REG_STATE_IND"
   sent  to L4C so that we can save the frequency which L4C sends status to MMI. Too
   many primitives may cause the external queue of MMI full. */
   l4crac_reg_state_ind_struct      last_l4crac_reg_state_ind;
#if defined(__GSM_RAT__) || defined(__UMTS_RAT__)
    gmmreg_init_req_struct          *local_para_ptr;
#endif /* defined(__GSM_RAT__) || defined(__UMTS_RAT__) */

    rac_nwsel_init_req_struct       *nwsel_init_req_ptr;
#ifdef __LTE_RAT__
    emmreg_init_req_struct          *emmreg_init_req_ptr;
#endif /* __LTE_RAT__ */

   local_para_struct                * plmn_search_req_ptr;

   /* mtk00714, add PLMN list retry for RAC, MAUI_00847832, MAUI_00850735 */
   eventid                          event_id[RAC_TOTAL_TIMER]; /* 0: retry plmn list or plmn search */
   event_scheduler                  *event_scheduler_ptr;
   //MAUI_02914482 [RAC] use evshed_create to replace new_evshed
   //stack_timer_struct                  base_timer;
   /* ~mtk00714 */

#ifdef __SAT__
#ifndef __SAT_LOWCOST_NW_DISABLE__
   sat_location_info_ind_struct     last_sat_location_info_ind;
   kal_bool                         send_sat_location_info_ind;
#endif /* #ifndef __SAT_LOWCOST_NW_DISABLE__ */
#endif /* __SAT__ */


   //#if (defined(__UMTS_RAT__) && defined(__GSM_RAT__))
   rat_enum                            prefer_rat;    //dual mode only
   //#endif
   rat_enum                            rat_mode;
   rat_enum                            request_rat_mode;
   //Tim
   /*active_rat should be replaced by l4c_get_active_rat, but used for detach ind*/
   rat_enum                            active_rat_mode;
   rat_enum                            target_rat_mode;
   rat_enum                            nvram_rat_mode; //mtk02475: for ECC retry other RAT feature
   domain_id_enum                      service_to_be_reged;

   rac_action_enum                     current_action;
   ms_mobile_class_enum                mobile_class;

#ifdef __PLMN_LIST_PREF_SUPPORT__
   /*mtk02475: PLMN LIST preference*/
   plmn_list_preference_enum           plmn_list_preference;
#endif

   kal_uint8                           retry_count;
   kal_uint8                           imei_svn;
   kal_uint8                           att_id;

   domain_id_enum                      prefered_service;
   plmn_selection_mode_enum            plmn_sel_mode;

   l4c_source_id_enum                  src_id;
#if defined(__FAST_DORMANCY__) || defined (__NO_PSDATA_SEND_SCRI__)
   l4c_source_id_enum                  end_data_src_id;
#endif
#ifdef __2STAGE_NW_SELECTION__
   l4c_source_id_enum                  sus_src_id;
#endif

   l4c_source_id_enum                  set_prefer_rat_src_id;

/* mtk02475: for RX_LEVEL_IND interface change, RAC no longer maintain RX LEVEL information */
//   kal_uint8                           rssi;
//   kal_uint8                           ber;
   kal_uint8                           nw_time_zone;

   kal_bool                           nw_time_zone_valid;
   kal_bool                           attach_req_sent;
   kal_bool                           auto_attach;
   kal_bool                           is_set_gprs_follow_on_request;   
   domain_id_enum                           service_to_be_dereged; /* John Tang 2004/03/08 */
   kal_uint8                           nvram_write_counter; /* John Tang 2004/07/09 */
   data_speed_support_enum                           cell_data_speed_support;   /* Erica 20070319: for edge status */

    /* Erica:
       High speed SIM, MM receives SIM_READY before 1st ATTACH_REQ(trigger by RAC_ACT_CNF).
       Therefore even though Phone lock is still on,
       but since MM "sim_valid_for_cs" flag is TRUE,
       MM will search normal service instead of limited service.
       Therefore L4C needs to decide the search type and passed to RAC and MM */
   mm_user_search_type_enum                           search_type;   //mm_user_search_type_enum, erica 20070424, MAUI_00232280
   kal_bool                            issearching;
   kal_uint8                           sim_interface;  /* 0x00: SIM1 ,    0x01: SIM2 */
#if defined(__GEMINI__) || defined(__SGLTE__)   
   kal_uint8                           dual_sim_config_status;
#endif

    kal_bool                           is_on_hplmn; //mtk02475: for EHPLMN, modem will provide the information of roaming

#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
    kal_bool                           peer_gprs_transfer_preference; //mtk02475: user preference for GEMINI 2.0 feature
#endif
#ifdef __DYNAMIC_ROAMING_SUPPORT__
   kal_bool                            is_supporting_roaming;
#endif
    kal_bool                           disable_international_roaming_support;
    kal_bool                           disable_national_roaming_support;
    kal_bool                           disable_hhplmn_search_support;
    kal_bool                           roaming_broker_support;
#ifdef __CSG_SUPPORT__
    local_para_struct                  *csg_list_req_ptr; //mtk02475: for CSG list retry
    kal_bool                           csg_auto_search_preference; //mtk02475: for Rel8 CSG autonomous search
#endif /* __CSG_SUPPORT__ */
    rac_mm_state_enum                  rac_mm_state;
    rac_mm_state_enum                  previous_rac_mm_state;

    kal_bool                           is_interRAT;
    kal_bool                           save_to_nvram;

#if defined(__GSM_RAT__) || defined(__UMTS_RAT__)
    rac_ugrac_context_struct            ugrac;
#endif

#if defined(__LTE_RAT__)
    rac_erac_context_struct             erac;
#endif /* __LTE_RAT__ */

    kal_bool                            is_sim_status_changed;
    rac_sim_status_enum                 sim_status;

    l4c_source_id_enum                  recovery_timer_src_id;
#ifdef __SGLTE__
    kal_bool                            is_mmdc_mode;
    kal_bool                            is_mmdc_ps_attach;
    attach_cause_enum                   ps_attach_cause;
    kal_bool                            notify_reattach_event;
#ifdef UNIT_TEST
    rat_enum                            ut_active_rat;
#endif
#endif /* __SGLTE__ */

#ifdef __SGLTE_DSDS__
    act_sim_enum                        act_sim;
    kal_bool                            need_attach_after_act_sim;
#endif

#if defined(__SGLTE_DSDS__) || (defined(__GEMINI__) && defined(__DUAL_SIM_PROJECT_SUPPORT_SGLTE_WORLD_PHONE_NVRAM__))
    kal_bool                            double_write_nvram;
#endif

#ifdef __MODEM_EM_MODE__
    em_source_enum                      em_src;
    kal_bool                            em_enable_for_ap;
    kal_bool                            em_enable_for_tool;
    kal_bool                            is_em_info_updated;
#endif /* __MODEM_EM_MODE__ */
#ifdef __UE_EFOPLMN__    
    kal_uint8 ue_oplmn_ver[2];
#endif 

#ifdef __VOLTE_SUPPORT__
    mm_ims_voice_termination            mm_ivt;
#endif /* __VOLTE_SUPPORT__ */

    domain_id_enum                      last_domain_in_attach_req; // for Search Normal

    kal_bool                            is_user_ps_reattach;

#ifdef __IMS_SUPPORT__
    ims_reg_type_enum                   ims_reg_type;
#endif /* __IMS_SUPPORT__ */

    kal_bool                            is_srvcc;

} rac_context_struct;

extern rac_context_struct *rac_ptr_global;
extern void *rac_callback_func_context[RAC_MAX_SPECIFIC_MOD_NUM][RAC_CALLBACK_TYPE_MAX_NUM];

#if !defined (__GEMINI__) && !defined(__SGLTE__)
#define RAC_MODULE_ID (MOD_RAC)

#else
#define RAC_MODULE_ID (MOD_RAC + rac_ptr_global->sim_interface)  //RAC current module id: MOD_RAC or MOD_RAC_2
extern void rac_context_selection(kal_uint8 sim_interface);
#ifdef UNIT_TEST
/* MAUI_02838008 [Gemini+] MM checkin */
extern rac_context_struct rac_context[MAX_SIM_NUM]; //for GV
#endif
#endif

#endif


