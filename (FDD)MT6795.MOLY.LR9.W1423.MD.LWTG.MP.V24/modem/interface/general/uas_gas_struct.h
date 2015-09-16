/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   uas_gas_struct.h
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
 * ==========================================================================
 * $Log:$
 *
 * removed!
 * removed!
 * .
 *
 * 11 13 2013 bo.wu
 * removed!
 * .
 *
 * removed!
 * removed!
 * .2->34G NBR transfer
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
 * .
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
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * [Henry][Multi-Mode Development] GAS Development and R8 CR Sync
 *
 * removed!
 * removed!
 * .
 *
 * 09 27 2012 yong.su
 * removed!
 * <saved by Perforce>
 * 
 * 09 26 2012 ye.yuan
 * removed!
 * CSCE CODE Interface part .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * 05 25 2012 yong.su
 * removed!
 * .
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
 * Check in TK6280_DVT_DEV to MT6280_DVT_DEV
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * merge interface: uas_gas_struct.h
 *
 * removed!
 * removed!
 * .
 *
 * 11 09 2011 ryan.ou
 * removed!
 * .
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
 * .
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
 * Supported 3rd criteria for InterRAT cell reselection to UTRAN.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add copyright header.
 ****************************************************************************/

#ifndef _UAS_GAS_STRUCT_H
#define _UAS_GAS_STRUCT_H

#include "uas_gas_enums.h"    
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "csi_umts_asn.h"     
#include "l3_inc_enums.h"     
#include "mcd_l3_inc_struct.h"
#include "csi_gsm_asn.h"
#include "irat_common_enums.h"      
#include "irat_common_struct.h"

#ifdef __CMCC_STD_FR__
#define MAX_CELL_NUM 27
#endif

//Common structure

typedef struct {
   kal_uint8 t3212_timer_val;
   kal_bool att_flag;
} ts_cs_specific_cn_info;

#if defined(__PS_HO__) && defined(__UMTS_R6__)
typedef struct {
   kal_uint8 ra_code;
   kal_uint8 nmo;
} ts_ps_specific_cn_info;
#endif

//Dual mode MEME SAP start 
/*
typedef struct
{
   LOCAL_PARA_HDR
}uas_gas_config_gcell_meas_cnf_struct;*/

/*
typedef struct
{
   LOCAL_PARA_HDR
   ts_ir_gsm_cell_rssi_info gsm_cell_rssi_info;
}uas_gas_gcell_meas_ind_struct;*/

/*
typedef struct
{
   LOCAL_PARA_HDR
   ts_ir_gsm_cell_bsic_info gsm_cell_bsic_info;
}uas_gas_gcell_bsic_ind_struct;*/

/*
typedef struct {
  LOCAL_PARA_HDR
  ts_ir_umts_cell_list ir_umts_cell_list;
}gas_uas_config_ucell_meas_req_struct;*/
//Dual mode MEME SAP end

typedef struct
{
  kal_uint32 cell_change_timeout;
  /* MH: Added for informing GAS the CCO activation time (20070511) */
  kal_uint32 cell_change_activation_time;
  kal_uint32 wait_time;
} IR3G2TimerStruct;

typedef struct
{
  kal_uint8 numElements;
  GSM_TargetCellInfo element[MAX_TARGET_GSM_CELLS_NUM]; /* Only the first numElements are valid */
} GSM_TargetCellInfoList;

//From GAS to UAS
typedef struct
{
   LOCAL_PARA_HDR
}uas_gas_config_gcell_meas_cnf_struct;

typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8 list_ref;
   ts_ir_gsm_cell_rssi_info gsm_cell_rssi_info;
   kal_bool is_long_period;
}uas_gas_gcell_meas_ind_struct;

typedef struct
{
   LOCAL_PARA_HDR
   ts_ir_gsm_cell_bsic_info gsm_cell_bsic_info;
}uas_gas_gcell_bsic_ind_struct;

#ifdef __UMTS_FDD_MODE__
typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 list_ref;
  CsiUmtsCellList umts_cell_list;
#if defined(__GERAN_R5__) && defined(__UMTS_R5__)
  kal_int8 fdd_rscp_min_in_dbm;
#endif /* defined(__GERAN_R5__) && defined(__UMTS_R5__)*/
  kal_uint16 first_meas_uarfcn; // invalid value = UAS_GAS_INVALID_UARFCN
  kal_bool is_detected_cell_meas[MAX_NUM_MEASURED_UMTS_CARRIERS];
  /* This flag is used to indicate whether measurement period should be reset
   * immediately. (TRUE:  meas is performed in the first DRX. 
   *               FALSE: meas is performed in the first T-meas occasion)  
   * In current design, the following rules should be followed.
   * (1)If number of ARFCN != 0, this flag will be set as FALSE only if tmeasure measurement 
   *                             is triggered when priority measurement is on-going (i.e., at 
   *                             least one of UMTS cells hits priority reselection criteria for priority 
   *                             based measurement reselection). For other case, this flag should 
   *                             be set as TRUE. If any improvement is needed, the usage limitation 
   *                             for this flag should be confirmed with UL1's colleague.
   * (2) If number of ARFCN == 0, this flag will alwyas be set as FALSE;
   */
   kal_bool is_meas_period_reset;    
}gas_uas_config_ucell_meas_req_struct;
#endif /* __UMTS_FDD_MODE__ */
#ifdef __UMTS_TDD128_MODE__
typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 list_ref;
  CsiUmtsCellList umts_cell_list;
  kal_uint16 first_meas_uarfcn; //in tdd, it is unused,  invalid value = UAS_GAS_INVALID_UARFCN
  kal_bool is_detected_cell_meas[MAX_NUM_MEASURED_UMTS_CARRIERS];
  /* This flag is used to indicate whether measurement period should be reset
   * immediately. (TRUE:  meas is performed in the first DRX. 
   *               FALSE: meas is performed in the first T-meas occasion)  
   * In current design, the following rules should be followed.
   * (1)If number of ARFCN != 0, this flag will be set as FALSE only if tmeasure measurement 
   *                             is triggered when priority measurement is on-going (i.e., at 
   *                             least one of UMTS cells hits priority reselection criteria for priority 
   *                             based measurement reselection). For other case, this flag should 
   *                             be set as TRUE. If any improvement is needed, the usage limitation 
   *                             for this flag should be confirmed with UL1's colleague.
   * (2) If number of ARFCN == 0, this flag will alwyas be set as FALSE;
   */
   kal_bool is_meas_period_reset; 
}gas_uas_config_ucell_meas_req_struct;
#endif /* __UMTS_TDD128_MODE__ */

typedef struct {
  LOCAL_PARA_HDR
  te_l1_availibility_status l1_availibility_status;
}gas_uas_lower_layer_availability_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_handover_status ir_handover_to_gsm_status;
}uas_gas_ho_activate_gcell_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_handover_status ir_handover_to_gsm_status;
}uas_gas_handover_gcell_cnf_struct;

typedef struct {
   LOCAL_PARA_HDR
   ts_ciphering_info      ciphering_info;
   plmn_search_type_enum  plmn_search_type;
#if defined(__PS_HO__) && defined(__UMTS_R6__)
   /* Set CS_DOMAIN if this is a CS HO. Set PS_DOMAIN if this is a PS HO */
   domain_id_enum         ir_ho_type;
#endif
}gas_uas_handover_ucell_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   lai_struct  lai;
#if defined(__PS_HO__) && defined(__UMTS_R6__)
   kal_bool    is_cs_cn_info_valid;
   kal_bool    is_ps_cn_info_valid;
#endif
   ts_cs_specific_cn_info  gas_cs_cn_info;
#if defined(__PS_HO__) && defined(__UMTS_R6__)
   /* For PS HO, we need to know PS CN info */
   ts_ps_specific_cn_info  gas_ps_cn_info;
#endif
}gas_uas_ho_activate_ucell_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_cell_reselection_status ir_cell_eval_status;
  ts_eval_activate_fail_handle	eval_activate_fail_handle;
}uas_gas_evaluate_gcell_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_cell_reselection_status ir_cell_activation_status;
  ts_eval_activate_fail_handle eval_activate_fail_handle;
  te_ir_cell_change_fail_reason_enum ir_cell_change_failed_reason; 
}uas_gas_activate_gcell_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
}uas_gas_evaluate_gcell_stop_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
 te_ir_cell_change_complete_status ir_cell_change_complete_status;
  /*Byron: 2007/05/08: Add for real CCO fail cause*/
  te_ir_cell_change_fail_reason_enum ir_cell_change_failed_reason;
}uas_gas_gcell_change_complete_ind_struct;

#ifdef __CMCC_STD_FR__
typedef struct{
  U16 cellId;
  CsiUarfcn uarfcn;	
}CellPara;
typedef struct{
  LOCAL_PARA_HDR
  U8 numElements;
  CellPara  elements[MAX_CELL_NUM];
}std_fr_cell_list;
typedef struct
{
   	LOCAL_PARA_HDR
   	kal_uint8     frThreshold;
   	kal_uint8     numElements;
   	CsiUarfcn     element[9];
}gas_uas_std_fr_info_ind_struct;
#endif

/* for R6 redirection feature */
#if (defined(__GERAN_R6__) || defined(__CMCC_FR__) || defined(__CMCC_STD_FR__))

/* Request to evaluate a cell
   because of inter RAT cell reselection or network ordered cell change */
typedef struct {
  LOCAL_PARA_HDR
  /* te_ir_cell_reselection_type ir_cell_reselection_type; depreted */
 te_ir_cell_change_trigger ir_cell_change_trigger;
  kal_bool notToCheck3rdCriterion; /* KAL_FALSE: check 3rd Criterion
                                        KAL_TRUE:  don't check, i.e., if IRCR candidate is from APBCR/CSG, 3rd criterion will not be checked */
 plmn_search_type_enum plmn_search_type;
 ts_umts_target_cell target_cell;
} gas_uas_evaluate_ucell_req_struct;

/* Request to activate a cell without an evaluation phase */
typedef struct {
  LOCAL_PARA_HDR
  kal_uint32 cell_change_timeout; /* value in milli seconds or zero when not required */
  /* te_ir_cell_reselection_type ir_cell_reselection_type; depreted */
  te_ir_cell_change_trigger ir_cell_change_trigger;
  kal_bool notToCheck3rdCriterion; /* KAL_FALSE: check 3rd Criterion
                                      KAL_TRUE:  don't check, i.e., if IRCR candidate is from APBCR/CSG, 3rd criterion will not be checked */
 plmn_search_type_enum plmn_search_type;
 ts_umts_target_cell target_cell; /* For IR_CELL_CHANGE_ORDER */
#if (defined(__GERAN_R6__) || defined(__CMCC_FR__))
 CsiUmtsCellList redirection_list; /* For IR_REDIRECTION */
#endif
#ifdef __CMCC_STD_FR__
 std_fr_cell_list std_fr_cell_list;
#endif
} gas_uas_activate_ucell_req_struct;

#else

/* Request to evaluate a cell
   because of inter RAT cell reselection or network ordered cell change */
typedef struct {
  LOCAL_PARA_HDR
 kal_uint16 cell_change_timeout; /* value in seconds or zero when not required */
 /* te_ir_cell_reselection_type ir_cell_reselection_type; depreted */
 te_ir_cell_change_trigger ir_cell_change_trigger;
    kal_bool notToCheck3rdCriterion; /* KAL_FALSE: check 3rd Criterion
                                        KAL_TRUE:  don't check, i.e., if IRCR candidate is from APBCR/CSG, 3rd criterion will not be checked */
 plmn_search_type_enum plmn_search_type;
 ts_umts_target_cell target_cell;
} gas_uas_evaluate_ucell_req_struct;

/* Request to activate a cell without an evaluation phase */
typedef gas_uas_evaluate_ucell_req_struct  gas_uas_activate_ucell_req_struct;
#endif /* (defined(__GERAN_R6__) && defined(__UMTS_R6__)) || defined (__FDD_REDIRECTION__) */

/* Request to stop an ongoing evaluation */
typedef struct {
  LOCAL_PARA_HDR
} gas_uas_evaluate_ucell_stop_req_struct;

#ifdef __LTE_RAT__
typedef struct {
  LOCAL_PARA_HDR
  eutran_cap_enum eutran_cap;
} gas_uas_eutran_cap_update_ind_struct;
#endif /* __LTE_RAT__ */

//From UAS to GAS
typedef struct {
  LOCAL_PARA_HDR
  ts_ciphering_info ciphering_info;
  plmn_search_type_enum plmn_search_type;
  te_gsm_band_indicator band_indicator;
  kal_uint16         message_length;
} uas_gas_handover_gcell_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 t3212_timer_val;
  kal_bool att_flag;
  kal_uint32 wait_time;
} uas_gas_ho_activate_gcell_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_handover_status ir_handover_to_utran_status;
} gas_uas_handover_ucell_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_handover_status ir_handover_to_utran_status;
} gas_uas_ho_activate_ucell_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 list_ref;
#ifdef __TDD_DM_GAP_OPTIMIZATION__
  kal_bool is_bsic_gap_valid;
#endif
  te_ir_urrc_state urrc_state;
  ts_ir_gsm_cell_list gsm_cell_list;
  /* This flag is used to indicate whether measurement period should be reset
   * immediately. (TRUE:  meas is performed in the first DRX. 
   *               FALSE: meas is performed in the first T-meas occasion) 
   * In current design, the following rules should be followed.
   * (1)If num of GSM cells != 0, this flag will be set as FALSE only if tmeas,gsm measurement 
   *                              is triggered when priority measurement is on-going (i.e., at 
   *                              least one of GSM cells hits priority reselection criteria for priority 
   *                              based measurement reselection). For other case, this flag should 
   *                              be set as TRUE. If any improvement is needed, the usage limitation 
   *                              for this flag should be confirmed with GL1's colleague.
   * (2) If num of GSM cells == 0, this flag will alwyas be set as FALSE;
   */
  kal_bool is_meas_period_reset;  
}uas_gas_config_gcell_meas_req_struct;

typedef struct {
  LOCAL_PARA_HDR
}gas_uas_config_ucell_meas_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_l1_availibility_status l1_availibility_status;
}uas_gas_lower_layer_availability_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 list_ref;
#ifdef __UMTS_FDD_MODE__
  ir_umts_measured_result ir_umts_meas_info;
#endif /* __UMTS_FDD_MODE__ */
#ifdef __UMTS_TDD128_MODE__  
  ts_ir_umts_meas_info ir_umts_meas_info;
#endif /* __UMTS_TDD128_MODE__ */  
#if defined(__LTE_RAT__) || defined(__23G_PRI_RESEL_SUPPORT__)
  kal_bool isLongPeriod;
#endif /* defined(__LTE_RAT__) || defined(__23G_PRI_RESEL_SUPPORT__) */
#ifdef UNIT_TEST
#ifdef __UMTS_FDD_MODE__
kal_uint32 meas_ind_ms_diff;
#endif
#ifdef __UMTS_TDD128_MODE__
kal_uint32 ucell_meas_ind_ms_diff;
#endif
#endif /* UNIT_TEST */
}gas_uas_ucell_meas_ind_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_cell_reselection_status ir_cell_eval_status;
  ts_eval_activate_fail_handle	eval_activate_fail_handle;
}gas_uas_evaluate_ucell_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_cell_reselection_status ir_cell_activation_status;
  ts_eval_activate_fail_handle	eval_activate_fail_handle;
  /*Byron: 2007/05/08: Add for real CCO fail cause*/
  te_ir_cell_change_fail_reason_enum ir_cell_change_failed_reason;
}gas_uas_activate_ucell_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
}gas_uas_evaluate_ucell_stop_cnf_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_cell_change_complete_status ir_cell_change_complete_status;
  /*Byron: 2007/05/08: Add for real CCO fail cause*/
  te_ir_cell_change_fail_reason_enum ir_cell_change_failed_reason;
}gas_uas_ucell_change_complete_ind_struct;


typedef struct {
  LOCAL_PARA_HDR
  te_ir_cell_change_trigger ir_cell_change_trigger;
  plmn_search_type_enum plmn_search_type;
  GSM_TargetCellInfo target_gcell_info;
} uas_gas_evaluate_gcell_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  te_ir_cell_change_trigger ir_cell_change_trigger;
  plmn_search_type_enum plmn_search_type;  
  GSM_TargetCell_Info_union target_gcell_info;
  GSM_TargetCell_SI_Info_union target_gcell_si_info;
  kal_uint32 cell_change_activation_time; /* milli-seconds, */   
  kal_uint32 cell_change_timeout; /* value in milli-seconds or zero when not required */
  kal_uint32 wait_time; /* milli-seconds: 0~15000 ms, GAS should not reselect back to UMTS/LTE within "wait_time" period */  
  kal_bool nc_mode_present; /* if TRUE nc_mode is present */
  kal_uint8  nc_mode; /* Optional, present if nc_mode_present is TRUE */
} uas_gas_activate_gcell_req_struct;

typedef struct {
  LOCAL_PARA_HDR
}uas_gas_evaluate_gcell_stop_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  kal_int8 q_rxlev_min; /* Range -115 to -25 dBm */
  kal_uint8 p_compensation; /* Range 0 to 12 dBm */
}uas_gas_cell_reselection_params_req_struct;
#if 0 /*brwang, 20080830, this definition should be placed before uas_gas_evaluate_gcell_req_struct*/
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
#endif


#if (defined(__UMTS_R5__) && defined(__GERAN_R5__))
typedef struct {
   LOCAL_PARA_HDR
   kal_bool isCompressedVersion;   
} gas_uas_ho_umts_info_ind_struct;

typedef struct {
   LOCAL_PARA_HDR
   kal_bool isCompressedVersion;   
} gas_uas_ho_umts_info_rsp_struct;
#endif

#ifdef __3G_CSG_SUPPORT__
typedef struct{
    LOCAL_PARA_HDR
    plmn_search_type_enum plmn_search_type;
    auto_search_cmd_enum auto_search_cmd;
    kal_uint8        num_carriers;
    kal_uint16      csg_uarfcn[MAX_NUM_CSG_CARRIERS];
} gas_uas_search_csg_ucell_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    search_status_enum search_status;
    kal_uint8         num_carriers;
    ts_3G_csg_ucell_evluation_result csg_ucell_evluation_result_list[MAX_NUM_CSG_CARRIERS];
} gas_uas_search_csg_ucell_cnf_struct;

typedef struct{
    LOCAL_PARA_HDR
    plmn_search_type_enum plmn_search_type;
    auto_search_cmd_enum auto_search_cmd;
    kal_uint8        num_carriers;
    kal_uint16      csg_uarfcn[MAX_NUM_CSG_CARRIERS];
} gas_uas_evaluate_csg_ucell_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    search_status_enum search_status;
    kal_uint8         num_carriers;
    ts_3G_csg_ucell_evluation_result csg_ucell_evluation_result_list[MAX_NUM_CSG_CARRIERS];
} gas_uas_evaluate_csg_ucell_cnf_struct;
#endif /* __3G_CSG_SUPPORT__ */

#if defined(__LTE_RAT__) || defined(__23G_PRI_RESEL_SUPPORT__)
typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 list_ref;
  te_ir_urrc_state urrc_state;
  kal_int16 prio_meas_period;
  ts_ir_gsm_cell_list gsm_cell_list;
}uas_gas_config_gcell_prio_meas_req_struct;

typedef struct {
  LOCAL_PARA_HDR
}gas_uas_config_ucell_prio_meas_cnf_struct;

typedef struct
{
   LOCAL_PARA_HDR
}uas_gas_config_gcell_prio_meas_cnf_struct;

#ifdef __UMTS_FDD_MODE__
typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 list_ref;
  kal_int16 prio_meas_period;
  CsiUmtsCellList umts_cell_list;
  kal_int8 fdd_rscp_min_in_dbm;
  kal_uint16 first_meas_uarfcn; // invalid value = UAS_GAS_INVALID_UARFCN
  kal_bool is_detected_cell_meas[MAX_NUM_MEASURED_UMTS_CARRIERS];
}gas_uas_config_ucell_prio_meas_req_struct;
#endif /* __UMTS_FDD_MODE__ */

#ifdef __UMTS_TDD128_MODE__
typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 list_ref;
  kal_int16 prio_meas_period;
  CsiUmtsCellList umts_cell_list;
  //kal_int8 fdd_rscp_min_in_dbm;
  kal_int8 tdd_rscp_min_in_dbm;
  kal_uint16 first_meas_uarfcn; // invalid value = UAS_GAS_INVALID_UARFCN
  kal_bool is_detected_cell_meas[9];
}gas_uas_config_ucell_prio_meas_req_struct;
#endif /* __UMTS_TDD128_MODE__ */
#endif /* defined(__LTE_RAT__) || defined(__23G_PRI_RESEL_SUPPORT__) */

#ifdef __WCDMA_PREFERRED__
typedef struct {
  LOCAL_PARA_HDR
  kal_int8 wcdma_preferred_rscp_threshold;
  kal_int8 wcdma_preferred_ecn0_threshold;
  kal_uint8 offset_2g_rssi_penalty; /* dbm*/
}gas_uas_wcdma_prefer_params_ind_struct;
#endif /* __WCDMA_PREFERRED__ */

#ifdef __LTE_RAT__
typedef struct {
  LOCAL_PARA_HDR
  eutran_cap_enum eutran_cap;
} uas_gas_eutran_cap_update_ind_struct;
#endif /* __LTE_RAT__ */

#ifdef __SGLTE__

#define MAX_NUM_OF_NC_UARFCN  9

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 plmn_num;
	plmn_id_struct r_eq_plmn[MAX_NUM_EQ_PLMN];
	kal_uint8 uarfcn_num;
	kal_uint16 uarfcn[MAX_NUM_OF_NC_UARFCN];	
} gas_uas_uarfcn_list_update_req_struct;

typedef struct {
  LOCAL_PARA_HDR
  kal_bool is_band_39_coverage;
}uas_gas_coverage_update_ind_struct;
#endif /* __SGLTE__ */

#endif /* _UAS_GAS_STRUCT_H */


