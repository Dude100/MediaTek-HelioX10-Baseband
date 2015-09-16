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
 *	l4crac_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for structure definition between RAC and L4C.
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


/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : l4c2rac_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _L4C2RAC_STRUCT_H
#define _L4C2RAC_STRUCT_H

#include "ps_public_enum.h"
#include "mcd_l3_inc_struct.h"
#include "kal_general_types.h"
#include "l3_inc_enums.h"
#include "l4c_common_enum.h"
#include "l4crac_enums.h"
#include "sim_public_enum.h"
#ifdef __IMS_SUPPORT__
#include "ims_common_def.h"
#endif /* __IMS_SUPPORT__ */
#include "irat_common_enums.h"

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    l4c_source_id_enum src_id; /* source id*/
} l4crac_act_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    l4c_source_id_enum src_id; /* source id*/
    mm_user_search_type_enum search_type; //mm_user_search_type_enum, erica 20070424, MAUI_00232280
} l4crac_reg_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    l4c_source_id_enum src_id; /* source id*/
    mm_user_search_type_enum search_type; //mm_user_search_type_enum, erica 20070424, MAUI_00232280
    #ifdef __SGLTE__
    kal_bool mmdc_ps_attach;
    attach_cause_enum attach_cause;
    #endif
} l4crac_ps_reg_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    l4c_source_id_enum src_id; /* source id*/
    domain_id_enum service; /* CS/PS/CS_PS*/
    kal_bool is_poweroff; /* TRUE/FALSE*/
} l4crac_dereg_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    l4c_source_id_enum src_id; /* source id*/
} l4crac_plmn_list_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    l4c_source_id_enum src_id; /* source id*/
    ms_mobile_class_enum ms_class; /* CC/CG/B*/
} l4crac_class_change_req_struct;

//tommy 030610 add for band selection for vito
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    l4c_source_id_enum src_id; /* source id*/
    band_selection_enum gsm_band; /* refer to band_selection_enum value*/ 
    kal_bool is_gsm_band_present;  
    kal_uint8 umts_fdd_band[SIZE_OF_UMTS_BAND];    /* 3G band change */
    kal_bool is_umts_band_present; /* 3G band change */

#ifdef __LTE_RAT__
    kal_uint8 requested_lte_bands[SIZE_LTE_BAND];
    kal_bool is_lte_band_present;
#endif /* __LTE_RAT__ */

}l4crac_set_preferred_band_req_struct;

#if defined(__GEMINI__) || defined(__SGLTE__)
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    sim_config_status_enum sim_config_status; // refer to sim_config_status_enum
    sim_insert_status_enum sim_insert_status; // refer to sim_insert_status_enum
}l4crac_sim_status_update_req_struct;
#endif

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    l4c_source_id_enum src_id; /* source id*/
    plmn_id_rat_struct plmn_id;
    //kal_uint8 plmn_sel_mode;

    /* Johnny:
    AUTO_RESELECTION/MANUAL_RESELECTION, there is no __MANUAL_MODE_NW_SEL__ compile option
    */    
    plmn_reselection_enum plmn_reselection_mode;
    rat_enum preference;   //  0:default ,  1:GSM ,   2:UMTS
    kal_uint32 factory_mode_arfcn; //FastCampOn 20081104
#ifdef __CSG_SUPPORT__
//mtk02475: for Rel8 CSG feature, user can specify CSG id for manual CSG selection
    kal_bool is_manual_csg_sel;
    kal_uint32 csg_id;
#endif
} l4crac_plmn_search_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    l4c_source_id_enum src_id;
    rat_enum rat_mode;
    kal_bool save_to_nvram; //MAUI_02554068
}l4crac_set_rat_mode_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    l4c_source_id_enum src_id;
}l4crac_plmn_list_stop_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    l4c_source_id_enum src_id;
    rat_enum prefer_rat;    
}l4crac_set_prefer_rat_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    l4c_source_id_enum src_id;
    susp_resu_mode_enum  mode;
    susp_resu_action_enum action;
    kal_uint8            susp_id;
}l4crac_susp_resu_update_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    kal_bool is_supporting_roaming;
    kal_bool disable_international_roaming_support;
    kal_bool disable_national_roaming_support;
    kal_bool disable_hhplmn_search_support;
}l4crac_set_roaming_mode_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    kal_bool force_send_SCRI;
    end_session_cause_enum cause;
}l4crac_end_ps_data_session_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    end_session_cause_enum cause;
}l4crac_end_ps_data_session_ind_struct;

#ifdef __CSG_SUPPORT__
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    l4c_source_id_enum src_id;
    plmn_id_rat_struct plmn_id_rat; //mtk02475: user can specified the CSG list scope
} l4crac_csg_list_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    l4c_source_id_enum src_id;
}l4crac_csg_list_stop_req_struct;
#endif /* __CSG_SUPPORT__ */

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    irat_type_enum irat_type;
    rat_type_enum source_rat;
    rat_type_enum target_rat;
    ho_from_lte_type_enum ir_ho_type;
}l4crac_rat_change_start_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    irat_type_enum irat_type;
    irat_result_enum irat_result;
    rat_type_enum source_rat;
    rat_type_enum target_rat;
}l4crac_rat_change_finish_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    l4c_source_id_enum              src_id;
    l4c_rac_sms_preference_enum     sms_preference;
} l4crac_set_sms_preference_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    l4c_source_id_enum                  src_id;
    kal_bool                            is_utran_vdp_valid;
    kal_bool                            is_eutran_vdp_valid;
    l4_voice_domain_preference_enum     utran_voice_domain_preference;
    l4_voice_domain_preference_enum     eutran_voice_domain_preference;
} l4crac_set_voice_domain_preference_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    l4c_source_id_enum              src_id;
    ue_usage_setting_enum           ue_usage_setting;
} l4crac_set_ue_usage_setting_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    l4c_source_id_enum              src_id;
    ue_mode_enum                    ue_mode;
} l4crac_set_ue_mode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    l4c_source_id_enum              src_id;
    kal_bool                        is_ims_voice_available;
} l4crac_set_ims_voice_availability_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    l4c_source_id_enum              src_id;
    kal_bool                        is_ims_sms_available;
} l4crac_set_ims_sms_availability_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
} l4crac_sim_ready_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    sim_error_cause_enum cause;
} l4crac_sim_error_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    kal_uint32 timer_interval[MAX_RECOVERY_TIMER_NUM];
} l4crac_set_recovery_search_timer_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id;
    kal_bool result;
} l4crac_set_recovery_search_timer_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id; // need to piggyback to L4C
} l4crac_get_recovery_search_timer_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    l4c_source_id_enum src_id; // piggyback to L4C from REQ
    kal_uint32 timer_interval[MAX_RECOVERY_TIMER_NUM];
} l4crac_get_recovery_search_timer_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    ps_cause_enum cause;
} l4crac_eps_attach_needed_rej_rsp_struct;

#ifdef __SGLTE__
/***********************************************/
typedef struct 
{
    LOCAL_PARA_HDR 
    l4c_source_id_enum              src_id;
    mmdc_mode_enum                  mode; 
} l4crac_mmdc_mode_update_req_struct;
typedef struct
{
    LOCAL_PARA_HDR
    l4c_source_id_enum              src_id;
    nas_proc_enum                    procedure;
    mm_cause_enum                   cause;
    plmn_id_struct                  plmn;
} l4crac_peer_reject_req_struct;
typedef struct 
{
    LOCAL_PARA_HDR
    mmdc_recovery_search_enum trigger_type;
} l4crac_mmdc_recovery_search_req_struct;
/***********************************************/

typedef struct {
    LOCAL_PARA_HDR
    rat_enum  cell_rat;
    mmdc_camp_on_status_enum  cell_status;
    kal_bool  is_immediately_switch;
    mmdc_psd_switch_cause_enum  cause;
    kal_bool  is_2g_cell_support_ps;      
} l4crac_mmdc_camp_on_status_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    rat_enum	target_rat;     
}l4crac_ps_switch_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool result;    
}l4crac_ps_switch_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool  result;      
}l4crac_ps_switch_suspend_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    plmn_search_abort_cause_enum cause;
}l4crac_plmn_search_abort_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    plmn_search_abort_proc_status_enum status;
}l4crac_plmn_search_abort_cnf_struct;

#endif /* __SGLTE__ */

#ifdef __SGLTE_DSDS__
typedef struct {
    LOCAL_PARA_HDR
    act_sim_enum active_sim;
}l4crac_active_sim_ind_struct;
#endif

#ifdef __IMS_SUPPORT__
typedef struct
{
    LOCAL_PARA_HDR
    l4c_source_id_enum              src_id;
    kal_bool                        ims_support;
} l4crac_ims_config_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    l4c_source_id_enum              src_id;
    ims_reg_state_enum 	            reg_state;
    ims_reg_type_enum	            reg_type;
    ims_dereg_cause_enum            dereg_cause;
} l4crac_ims_reg_status_update_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    ims_reg_type_enum               reg_type;
} l4crac_ims_reg_start_req_struct;

#endif /* __IMS_SUPPORT__*/
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 ue_oplmn_ver[2];
    kal_uint16 no_oplmn_entry;
    kal_uint8 *oplmn_data;  
}l4crac_ue_oplmn_update_req_struct;

#ifdef __VOLTE_SUPPORT__
typedef struct
{
    LOCAL_PARA_HDR 
    l4c_source_id_enum              src_id;
    mm_ims_voice_termination        mm_ivt;
} l4crac_set_mm_ims_voice_termination_req_struct;
#endif /* __VOLTE_SUPPORT__ */

#endif /* _L4C2RAC_STRUCT_H */


