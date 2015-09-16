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
 *   rac_eval_struct.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   message and common structure definition between RAC and EVAL module
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
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * MMIVT2MP6
 *
 * 06 19 2014 roy.lin
 * removed!
 * Update interface for PS detach without disable EUTRAN.
 *
 * removed!
 * removed!
 * .check in actvie sim info req interface
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Change kal_bool amnual_resel to attach_cause_enum attach_cause for emmreg_attach_req_struct.
 *
 * removed!
 * removed!
 * MOLY
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Add manual_resel in emmreg_attach_req_struct for manual selection re-design in SGLTE project.
 *
 * removed!
 * removed!
 * VoLTE to MOLY
 *
 * removed!
 * removed!
 * Add mmdc_ps_attach in emmreg_attach_req_struct for PS Switch.
 *
 * removed!
 * removed!
 * add interface.
 *
 * removed!
 * removed!
 * .
 *
 * 07 26 2013 hc.chu
 * removed!
 * CREG, CEREG AT cmd enhancement
 *
 * removed!
 * removed!
 * Merge MMDC interface to MOLY
 *
 * removed!
 * removed!
 * add __MMDC__ for message/structure.
 *
 * removed!
 * removed!
 * Add active rat/proc. status in SetRatModeReq/Cnf for IRCC0 Stage2 Failure.
 *
 * removed!
 * removed!
 * .
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
 *
 * removed!
 * removed!
 * Add new msgid
 ****************************************************************************/


#ifndef  _RAC_EVAL_STRUCT_INC
#define  _RAC_EVAL_STRUCT_INC

#include "ps_public_enum.h"
#include "l3_inc_local.h"
#include "nvram_data_items.h"
#ifdef __VOLTE_SUPPORT__
#include "ims_common_def.h"
#endif /* __VOLTE_SUPPORT__ */

/***** message structure definition *****/
typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8                   imei[SIZE_IMEI]; 
    kal_uint8                   imei_svn;
    kal_uint8                   nvram_epsloci[SIZE_EPSLOCI];
    kal_uint8                   nvram_epsnsc[SIZE_EPSNSC];
    kal_uint8                   drx_data[SIZE_DRX_DATA];
    tin_enum                    tin;
    kal_uint8                   feature_config[NVRAM_LTE_FEATURE_CONFIG_SIZE];
    
} emmreg_init_req_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    erac_rat_enum               rat_mode;
    erac_rat_enum               active_rat;
    
} emmreg_set_rat_mode_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    proc_status_enum            status;
    
} emmreg_set_rat_mode_cnf_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8                   att_id;

#ifdef __SGLTE__
    kal_bool                    mmdc_ps_attach;
    attach_cause_enum           attach_cause;
#endif /*__SGLTE__*/
} emmreg_attach_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                       att_id;
    domain_id_enum                  attach_type;
    cell_info_and_rat_struct        cell_info;
	additional_update_result_enum   additional_update_result;
	kal_bool                        is_on_hplmn;
	
} emmreg_attach_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   att_id;
    domain_id_enum              detach_type;
    kal_bool                    is_power_off;
    kal_bool                    is_user_ps_reattach;

} emmreg_detach_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   att_id;
    domain_id_enum              detach_type;
    emm_cause_enum              emm_cause;
    esm_cause_enum              esm_cause;
    kal_bool                    is_reged;
    cell_info_and_rat_struct    cell_info;
    kal_bool                    is_on_hplmn;
    kal_bool                    is_reattach;
    
} emmreg_detach_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    data_speed_support_enum     cell_data_speed_support;
    cell_info_and_rat_struct    cell_info;
    kal_bool                    is_on_hplmn;
    
} emmreg_cell_info_update_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   full_nw_nameP;
    kal_uint8                   full_nw_name_len;
    kal_uint8                   full_nw_name[24];
    kal_uint8                   short_nw_nameP;
    kal_uint8                   short_nw_name_len;
    kal_uint8                   short_nw_name[24];
    kal_uint8                   nw_time_zoneP;
    kal_uint8                   nw_time_zone;
    kal_uint8                   nw_time_zone_timeP;
    nw_time_zone_time_struct    nw_time_zone_time;
    kal_uint8                   nw_day_light_saving_timeP;
    kal_uint8                   nw_day_light_saving_time;
    plmn_id_struct              plmn_id;

} emmreg_nw_info_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR

} emmreg_eps_attach_needed_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   no_ecc;
    ecc_number_struct           ecc_list[MAX_NW_ECC_NUM];

} emmreg_nw_ecc_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                    is_valid_requested_gsm_band;
    kal_uint8                   requested_gsm_band;
    kal_bool                    is_valid_requested_umts_fdd_band;
    kal_uint8                   requested_umts_fdd_band[SIZE_UMTS_FDD_BAND];
    kal_bool                    is_valid_requested_umts_tdd_band;
    kal_uint8                   requested_umts_tdd_band[SIZE_UMTS_TDD_BAND];
    kal_bool                    is_valid_requested_lte_band;
    kal_uint8                   requested_lte_band[SIZE_LTE_BAND];

} emmreg_set_preferred_band_req_struct;


#ifdef __SGLTE__
typedef struct {
    LOCAL_PARA_HDR
    kal_bool result;    
}emmreg_ps_switch_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool  result;      
}emmreg_ps_switch_suspend_cnf_struct;
#endif
#ifdef __VOLTE_SUPPORT__
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                        force_emc_attach;
} emmreg_emc_attach_ind_struct;

/* relay EMMREG_EMC_ATTACH_IND to EMMREG_EMC_ATTACH_REQ (from ESM to EMM) */
typedef emmreg_emc_attach_ind_struct    emmreg_emc_attach_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                       att_id;
    cell_info_and_rat_struct    	cell_info;
} emmreg_emc_attach_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                       att_id;
    emm_cause_enum    	            emm_cause;
    esm_cause_enum	                esm_cause;
    cell_info_and_rat_struct    	cell_info;
} emmreg_emc_detach_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                       is_ims_voice_available;
} emmreg_set_ims_voice_availability_req_struct;

typedef  struct
{
    LOCAL_PARA_HDR
    mm_ims_voice_termination        mm_ivt;
} emmreg_set_ims_voice_termination_req_struct;

#endif /* __VOLTE_SUPPORT__ */

typedef struct 
{
    LOCAL_PARA_HDR
    emm_nw_feature_support_struct   eps_nw_feature;
} emmreg_nw_feature_ind_struct;

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
#endif /* mark empty primitive message structure */


typedef struct 
{
    LOCAL_PARA_HDR
    ps_cause_enum               cause;
} emmreg_eps_attach_needed_rej_rsp_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    sat_nw_rej_info_enum        op;
    cell_info_and_rat_struct    current_cell;
    sat_nw_rej_type_enum        type;
    kal_uint8                   rej_cause;
} emmreg_nw_reject_ind_struct;


#ifdef __SGLTE_DSDS__

typedef struct
{
    LOCAL_PARA_HDR
    act_sim_enum                act_sim;
} emmreg_active_sim_info_req_struct;

#endif /* __SGLTE_DSDS__ */

#endif   /* ----- #ifndef _RAC_EVAL_STRUCT_INC ----- */

