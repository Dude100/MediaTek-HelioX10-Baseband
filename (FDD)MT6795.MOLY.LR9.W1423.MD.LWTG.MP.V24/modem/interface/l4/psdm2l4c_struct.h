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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   psdm2l4c_struct.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   PSDM<->L4C related structures 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef PSDM2L4C_STRUCT_H
#define PSDM2L4C_STRUCT_H

#include "kal_public_defs.h"
#include "psdm2l4c_enum.h"
#include "l3_inc_enums.h"
#include "l3_inc_local.h"
#include "rmmi_common_enum.h"

#include "l4crac_enums.h"
#include "sim_public_enum.h"

//#if defined(__SGLTE__)

typedef struct
{
    kal_bool use_4g_rsrp;
    kal_bool use_4g_rsrq;
    psdm_criteria_relation_enum relation_4g_rsrp_rsrq;
} psdm_switch_pref_struct;

typedef struct
{
    kal_uint8 good_rssi;
    kal_uint8 bad_rssi;
    kal_uint8 good_rscp;
    kal_uint8 bad_rscp;
    kal_uint8 good_rsrp;
    kal_uint8 bad_rsrp;
    kal_uint8 good_rsrq;
    kal_uint8 bad_rsrq;
} psdm_threshold_config_struct;

typedef struct
{
    kal_uint32 t1;
    kal_uint32 t2;
    kal_uint32 t3;
    kal_uint32 t4;
} psdm_timer_config_struct;

typedef struct l4cpsdm_mmdc_config_req_ind_struct
{
    LOCAL_PARA_HDR
    psdm_config_enum type;//    The type of parameters to be configured

    union{
        psdm_switch_pref_struct switch_pref_config; 
        psdm_threshold_config_struct threshold_config; 
        psdm_timer_config_struct timer_config;
        kal_bool event_triggerred_bgs; 
    } params;
} l4cpsdm_mmdc_config_req_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    psdm_psd_enum target_ps_domain;
    mmdc_psd_switch_cause_enum cause;
} l4cpsdm_ps_indication_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    rat_enum cell_rat;
    mmdc_camp_on_status_enum cell_status;
    kal_bool is_immediately_switch;
    mmdc_psd_switch_cause_enum cause;
    kal_bool is_2g_cell_support_ps;
} l4cpsdm_mmdc_camp_on_status_ind_struct;


typedef struct psdm_as_status_events_struct
{
    as_ind_type_enum ind_type;
    mmdc_rr_state_enum cell_status;

    union{
        mmdc_srv_cell_info_struct srv_cell_info;
        mmdc_eas_sys_threshold_struct eas_threholds;
        mmdc_uas_sys_threshold_struct uas_threholds;
        mmdc_nbr_info_ind_struct nbr_infos;
        mmdc_gas_sys_threshold_struct gas_threholds;
        mmdc_as_oos_triger_ind_struct as_oos;
    } params;
} psdm_as_status_events_struct;

typedef struct
{
    kal_int32 rssi_in_qdbm;
    kal_int32 RSCP_in_qdbm;
    kal_int32 EcN0_in_qdbm;
    kal_int32 RSRP_in_qdbm;
    kal_int32 RSRQ_in_qdbm;
	kal_uint32 	arfcn;
} psdm_signal_strength_struct;

typedef struct
{
    rmmi_reg_state_enum reg_state;
    l4c_rac_gprs_status_enum ps_state;
} psdm_reg_state_struct;

typedef struct
{
    kal_bool is_sim_inserted;
    sim_error_cause_enum cause;
} psdm_sim_state_struct;

typedef struct l4cpsdm_mmdc_status_event_ind_struct
{
    LOCAL_PARA_HDR
    psdm_status_event_enum type;
    rat_enum rat;
        
    union{  
        psdm_as_status_events_struct as_ind;
        psdm_signal_strength_struct signal;
        psdm_reg_state_struct reg_ps_status;
        psdm_sim_state_struct sim_state;
        kal_bool cops_active;
        kal_bool set_rat_active;  
    } params;
} l4cpsdm_mmdc_status_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
} l4cpsdm_ps_attach_result_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool ps1_rf_status_on;
    kal_bool ps2_rf_status_on;
} l4cpsdm_mmdc_rf_status_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    psdm_psd_enum target_domain;
    psdm_switch_decision_enum decision;
    kal_bool is_action_conflict;
} l4cpsdm_ps_switch_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    rat_enum target_rat;
} l4cpsdm_ps_switch_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
} l4cpsdm_ps_switch_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
} l4cpsdm_ps_switch_transfer_complete_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    mmdc_ps_switch_notify_gas_enum notify_event;
    kal_bool ps_switch_result;
    kal_bool is_ps_on_2G;
} l4cpsdm_ps_switch_gas_notification_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    mmdc_recovery_search_enum cause;
} l4cpsdm_mmdc_recovery_search_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
} l4cpsdm_ps_switch_suspend_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
} l4cpsdm_ps_switch_transfer_complete_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    attach_cause_enum cause;
} l4cpsdm_ps_attach_req_struct;


typedef struct
{
	LOCAL_PARA_HDR
	plmn_search_abort_cause_enum cause;
} l4cpsdm_plmn_search_abort_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	plmn_search_abort_proc_status_enum status;
} l4cpsdm_plmn_search_abort_cnf_struct;


//#endif /*__SGLTE__*/

#endif /* PSDM2L4C_STRUCT_H */

