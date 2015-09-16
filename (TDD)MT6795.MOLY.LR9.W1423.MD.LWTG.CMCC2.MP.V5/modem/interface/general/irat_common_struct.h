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
 *   irat_common_struct.h
 *
 * Project:
 * --------
 *   MOLY
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
 * 	CEL part
 *
 * removed!
 * removed!
 * Ping-Pong avoidance:Interface
 *
 * 10 22 2014 max.mo
 * removed!
 * .
 *
 * 10 14 2014 max.mo
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * . check in gsm attach state interface
 *
 * removed!
 * removed!
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
 * .
 *
 * removed!
 * removed!
 * Emergency PDN
 *
 * removed!
 * removed!
 * Help to workaround a codegen known issue.
 *
 * removed!
 * MOLY00041595
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * .
 *
 * removed!
 * removed!
 * 34612
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * .
 *
 * removed!
 * removed!
 * 34612
 * removed!
 * removed!
 * Integration change.
 *
 * removed!
 * removed!
 * Correct emm2mm_ps_swtich_info_struct and mm2emm_ps_swtich_info_struct
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * .
 *
 * removed!
 * mmdc check in interface
 *
 * removed!
 * mmdc interface check in
 *
 * removed!
 * removed!
 * Add interface for KC128 key
 *
 * 05 27 2013 jed.lee
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * change SM ESM interRAT context transfer interface
 *
 * removed!
 * removed!
 * [MM/EMM] 24.301/24.008 CR Implementation: Interface modification, add TMSI, ECC_PLMN
 *
 * removed!
 * removed!
 * merge code.
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
 * 01 24 2013 jeff.wu
 * removed!
 * Modify macro definition for header inclusion
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * NULL
 * [GAS][Multi-Mode] GAS bug fix check-in
 *
 * 11 07 2012 roy.lin
 * removed!
 * Use "apn_struct", "ip_addr_struct" to replace "irat_apn_struct", "irat_ip_addr_struct".
 *
 * removed!
 * removed!
 * [ETCM] merge interface, makefile, codegen related files
 * 1. libParseDbModem.c
 * 2. sap_info.h
 * 3. tcm_eval_struct.h
 * the above file is not merge, waits for DHL & EVAL owner
 *
 ****************************************************************************/

#ifndef _IRAT_COMMON_STRUCT_H
#define _IRAT_COMMON_STRUCT_H

#include "kal_general_types.h"
#include "mmi_l3_enums.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "ps_public_enum.h"
#include "stack_config.h"
#include "l3_inc_enums.h"
#include "l3_inc_local.h"
#include "irat_common_enums.h"
#include "mcd_l3_inc_struct.h"

#define MAX_VAL(VAL_A, VAL_B)   (((VAL_A) > (VAL_B)) ? (VAL_A):(VAL_B))

#if defined(GPRS_MAX_PDP_SUPPORT) && defined(LTE_MAX_EPSB_SUPPORT)
    #define MAX_TRANSFERRED_BEARER_NUM MAX_VAL(GPRS_MAX_PDP_SUPPORT, LTE_MAX_EPSB_SUPPORT)
#elif defined(LTE_MAX_EPSB_SUPPORT)
    #define MAX_TRANSFERRED_BEARER_NUM LTE_MAX_EPSB_SUPPORT // fail safe, this line has no meaning. just prevent compile error
#else
    #define MAX_TRANSFERRED_BEARER_NUM GPRS_MAX_PDP_SUPPORT // fail safe, this line has no meaning. just prevent compile error
#endif

//#define MAX_BEARER_CTXT_NUM MAX_TRANSFERRED_BEARER_NUM

#define MAX_BEARER_CTXT_NUM 11
#define MAX_BEARER_ID       16

typedef struct {
    kal_uint8   ti_len;
    kal_uint8   ti[UGSM_TI_IE_LEN];
}irat_ti_struct;

typedef struct {
    kal_bool        cause_present;
    ps_cause_enum   cause_value;
}irat_addr_type_limitation_cause_struct;

typedef struct
{
    kal_uint8                   qci;
} simple_eps_qos_struct;

typedef struct {
    // if iRAT, source SM need to fill the following fields
    irat_transfer_bearer_type_enum  bearer_type;
    
    // NSAPI / EBI (range is 5~15)
    kal_uint8                       bearer_id;
    
    // NSAPI / EBI (range is 5~15)
    kal_uint8                       linked_bearer_id;
    
#ifdef __SGLTE__
    //if 2<->3 PS switch, Source RAT need transfer pool id to TARGET RAT
    kal_uint8                       pool_id;
#endif
	
    // secondary bearer set ip_addr_type = NULL_TYPE
    ip_addr_struct                  ip_addr;
    
    // secondary bearer doesn't need to set this field
    apn_struct                      apn;
    
    // this parameter is critical to 23G. SM can just send MAP FAIL to ESM when this parameter is not present
    kal_bool                        is_ug_qos_present;
    // negotiated qos parameter used in 23G
    qos_struct                      ug_qos;
    
    kal_bool                        is_eps_qos_present;
    // When ESM transfer more than GPRS_MAX_PDP_SUPPORT contexts to SM, 
    // SM need to use eps_qos to decide which contexts need to be mapped failed and inform ESM to local release it.
    simple_eps_qos_struct           eps_qos;
    
    // this parameter is critical to 2G. if iRAT is 4G2, SM can just send MAP FAIL to ESM when this parameter is not present
    kal_bool                        is_llc_sapi_present;
    kal_uint8                       llc_sapi; 
    
    // this parameter is critical to 2G. if iRAT is 4G2, SM can just send MAP FAIL to ESM when this parameter is not present
    kal_bool                        is_radio_priority_present;
    kal_uint8                       radio_priority;
    
    // this parameter is critical to 2G. if iRAT is 4G2, SM can just send MAP FAIL to ESM when this parameter is not present
    kal_bool                        is_pfi_present;
    kal_uint8                       pfi;
    
    // this parameter is critical to 23G. SM can just send MAP FAIL to ESM when this parameter is not present
    kal_bool                        is_ti_present;
    irat_ti_struct                  ti;
    
    bcm_enum                        bcm;
    
    irat_addr_type_limitation_cause_struct addr_type_limitation_cause;
    
    bearer_service_type_enum				bearer_service_type;
    
    /* only used in 23G4 inter-RAT, when tcm_requested_deact==KAL_TRUE, this PDP must map fail, used to perform local deact */
    kal_bool tcm_requested_deact;
}bearer_ctxt_struct;


typedef struct {
    kal_uint8           total_number;                   // Total number of PDP context/EPS bearer which will transfer to target RAT
    bearer_ctxt_struct  context[MAX_TRANSFERRED_BEARER_NUM]; // bearer context which will transfer to target RAT
}bearer_ctxt_transfer_struct;

typedef struct {
    // NSAPI / EBI (range is 5~15)
    kal_uint8                       bearer_id;
    
    // this parameter is critical to 23G. SM can just send MAP FAIL to ESM when this parameter is not present
    kal_bool                        is_ug_qos_present;
    // negotiated qos parameter used in 23G
    qos_struct                      ug_qos;
    
    // this parameter is critical to 2G. if iRAT is 4G2, SM can just send MAP FAIL to ESM when this parameter is not present
    kal_bool                        is_llc_sapi_present;
    kal_uint8                       llc_sapi; 
    
    // this parameter is critical to 2G. if iRAT is 4G2, SM can just send MAP FAIL to ESM when this parameter is not present
    kal_bool                        is_radio_priority_present;
    kal_uint8                       radio_priority;
    
    // this parameter is critical to 2G. if iRAT is 4G2, SM can just send MAP FAIL to ESM when this parameter is not present
    kal_bool                        is_pfi_present;
    kal_uint8                       pfi;
    
    // this parameter is critical to 23G. SM can just send MAP FAIL to ESM when this parameter is not present
    kal_bool                        is_ti_present;
    irat_ti_struct                  ti;

}bearer_legacy_rat_para_struct;


typedef struct
{
    sec_ctxt_domain_id_enum domain_id;
    kal_uint8               umts_ciphering_key[CK_LEN];
    kal_uint8               umts_integrity_key[IK_LEN];
    kal_uint8               gsm_ciphering_key[KC_LEN];
    kal_uint8               gsm_ciphering_key128[KC128_LEN];
}security_context_struct;


/* Merged from GSM / UMTS Multimode development branch **********/
/* Common structure */
/* Measurement request/confirm related: GAS/UAS to EAS */

typedef struct
{
   kal_uint16	physical_cell_id;
   kal_int16	cpich_rscp;
   kal_int16	cpich_ec_n0;
} ir_reported_fdd_cells_csg_meas_info;

typedef struct
{
   kal_uint16  uarfcn;
   kal_int16   uarfcn_rssi;
   kal_uint8   num_reported_cells;
   ir_reported_fdd_cells_csg_meas_info  ir_reported_fdd_cells_csg_meas_info_list[MAX_NR_OF_CSG_CELLS_IN_CELL_LIST];
} ir_umts_carrier_csg_meas_result_struct;

typedef struct
{
   kal_uint16          earfcn;
   eas_bandwidth_enum  meas_bandwidth;
   kal_bool            skip_black_list;
   kal_uint8           black_list[BLK_LIST_ARRAY_SIZE];
} eas_meas_freq_info_struct;

typedef struct
{
   kal_uint16  earfcn;
   kal_uint8   cell_num;
   kal_uint16  cell[MAX_NUM_LTE_MEAS_CELL];
} eas_hps_qualify_struct;

/* Measurement request/confirm related: EAS/UAS to GAS */
typedef struct
{
   te_gsm_band_indicator gsm_band_indicator;
   kal_uint16 bcchArfcn;
} ts_ir_gsm_cell;

typedef struct
{
   kal_uint8 numElements;
   ts_ir_gsm_cell element[32];
} ts_ir_gsm_cell_list;

/* Measured results related: EAS to GAS/UAS */
typedef struct
{
   kal_uint16  pci;
   kal_int16   rsrp;
   kal_int16   rsrq;
} eas_meas_cell_rslt_struct;

typedef struct
{
   kal_uint16  earfcn;
   kal_uint8   cell_num;
   eas_meas_cell_rslt_struct  cell[MAX_NUM_LTE_MEAS_CELL];
} eas_meas_freq_rslt_struct;

/* Measured results related: UAS to GAS/EAS */
#ifdef __UMTS_FDD_MODE__
typedef struct
{
   kal_uint16 scrambling_code;
   kal_uint8  cpich_rscp;  /* R99:0-91, R5:(-5)-91 */
   kal_uint8  cpich_ec_n0; /* 0-49 */
   te_ir_bar_status  resel_status;
   te_ir_resel_criteria3_status  criteria3_status;
} ts_ir_reported_fdd_cells_meas_info;
#endif
#ifdef __UMTS_TDD128_MODE__
typedef struct {
    kal_uint16 cell_parameter;
    kal_int16 pccpch_rscp;  /* RSCP, in qdbm. Range: -500~ -100 (means -125 ~ -25 dBm 0.25 dB step) */
    te_ir_bar_status resel_status;
//    te_ir_resel_criteria3_status criteria3_status;//FDD only
}ts_ir_reported_tdd_cells_meas_info;
#endif

#ifdef __UMTS_FDD_MODE__
typedef struct
{
   kal_uint16 scrambling_code;
   kal_int16  cpich_rscp;    /* RSCP, in qdbm Range: -480 ~ -100 means (-120 ~ -25 )dBm in 0.25 dB step */
   kal_int16  cpich_ec_n0;   /* Ec/No, in qdb. Range: -100~0 (means -25 ~ 0 dB in 0.25 dB step) */
   te_ir_bar_status  resel_status;                 /* used when 2G active */
   te_ir_resel_criteria3_status  criteria3_status; /* used when 2G active */
} ir_umts_measured_result_per_cell;

typedef struct
{
   kal_uint16 uarfcn;
   kal_int16  uarfcn_rssi;  /* RSSI, in qdbm. Range: -480 ~ -100 (means -120 ~ -25 dBm 0.25 dB step) */
   kal_uint8  num_reported_cells;
   ir_umts_measured_result_per_cell  ir_reported_fdd_cells_meas_info[MAX_NR_OF_FDD_CELLS_IN_CELL_LIST];
} ir_umts_measured_result;
#endif

typedef struct
{
   kal_uint16 uarfcn;
    kal_int16 uarfcn_rssi;  /* RSSI, in qdbm. Range: -400 ~ -100 (means -100 ~ -25 dBm 0.25 dB step) */
   kal_uint8  num_reported_cells;
#ifdef __UMTS_FDD_MODE__
   ts_ir_reported_fdd_cells_meas_info  ir_reported_fdd_cells_meas_info[MAX_NR_OF_FDD_CELLS_IN_CELL_LIST];
#endif
#ifdef __UMTS_TDD128_MODE__
   ts_ir_reported_tdd_cells_meas_info  ir_reported_tdd_cells_meas_info[MAX_NR_OF_TDD_CELLS_IN_CELL_LIST];
#endif
} ts_ir_umts_carrier_meas_results;

typedef struct
{
   kal_uint8 num_carriers;
   ts_ir_umts_carrier_meas_results  ir_umts_carrier_meas_reults[MAX_NUM_MEASURED_UMTS_CARRIERS];
} ts_ir_umts_meas_info;

/* Define for Evaluation or Activation Failed Handle */
typedef struct
{
   te_eval_activate_fail_type  eval_activate_fail_type;
   /* In second, valid only when evalActivateFailType is CELL_BARRED */
   kal_uint16                  tbarred_val;
   /* In enum, valid only when evalActivateFailType is NAS_REJECT(only set and used by UAS now) */
   irat_reject_cause_enum      reject_cause;
} ts_eval_activate_fail_handle;

typedef struct
{
   kal_uint16  earfcn;
   kal_uint16  pci;
} eas_target_cell_info;

typedef struct
{
   kal_bool    is_valid;
   kal_uint16  earfcn;
   kal_uint16  pci;
   kal_uint32  cell_id;
} ir_lte_scell_struct;

/* This structure represents the redirection info from GSM or UMTS to LTE */
typedef struct
{
   kal_uint16  earfcn;
   kal_bool    target_cell_valid_flag;
   kal_uint16  target_cell;
   kal_bool    not_allowed_exist_flag;
   /* It is a LTE PCI bit map (0-503), least significant bit of not_allowed_cells [0] 
    * represents PCI-0, and the most significant bit of not_allowed_cells [0] 
    * represents PCI-7.
    * The cell IDs (PCI) of not allowed cells are set to  "1" and the cell IDs 
    * (PCI) of those other than not allowed cells are set to "0".
    */
   kal_uint8   not_allowed_cell[PCI_BITMAP_MAX_NUM];
} lte_redirect_info;

/* Measured results related: GAS to UAS/EAS */
typedef struct
{
   te_gsm_band_indicator  gsm_band_indicator;
   kal_uint16  bcch_arfcn;
   kal_int16   rssi_in_quarter_dbm;
} ts_ir_carrier_rssi_info;

typedef struct
{
   kal_uint8  num_carriers;
   ts_ir_carrier_rssi_info  carrier_rssi_info[MAX_NUM_MEASURED_GSM_CELLS];
} ts_ir_gsm_cell_rssi_info;

typedef struct
{
   kal_uint32  frame_offset;
   kal_uint16  quarter_bit_offset;
} ts_ir_gsm_cell_timing_info;

typedef struct
{
   te_gsm_band_indicator gsm_band_indicator;
   kal_uint16  bcch_arfcn;
   kal_bool    bsic_verified;
   kal_uint8   bsic;                                 /* This contains a valid value only if bsic_verified = TRUE */
   ts_ir_gsm_cell_timing_info  gsm_cell_timing_info; /* This contains a valid value only if bsic_verified = TRUE */
} ts_ir_gsm_cell_bsic_info;

#ifdef __UMTS_FDD_MODE__
typedef struct
{
   kal_uint16  uarfcn;
   kal_uint16  scrambling_code;
   kal_bool    tx_diversity;
} ts_umts_fdd_cell;
#endif

#ifdef __UMTS_TDD128_MODE__
typedef struct
{
   kal_uint16  uarfcn;
   kal_uint16  cell_parameter;
   kal_bool    tstd;
   kal_bool    sctd;
} ts_umts_tdd_cell;
#endif

typedef struct
{
   te_umts_mode      mode;
#ifdef __UMTS_FDD_MODE__
   ts_umts_fdd_cell  fdd_cell;
#endif
#ifdef __UMTS_TDD128_MODE__
   ts_umts_tdd_cell  tdd_cell;
#endif
} ts_umts_target_cell;

typedef struct
{
   kal_bool	 is_best_cell_suitable_allowed_CSG;
   kal_bool  is_best_cell_allowed_hybrid;
   ir_umts_carrier_csg_meas_result_struct ir_umts_carrier_csg_meas_result;
} ts_3G_csg_ucell_evluation_result;

typedef struct
{
   kal_bool    bsic_present; /* if TRUE bsic is present */
   kal_uint8   bsic;         /* Optional, present if bsic_present is TRUE */
   te_gsm_band_indicator  gsm_band_indicator;
   kal_uint16  bcch_arfcn;
} GSM_TargetCellInfo;

#if defined(__UMTS_FDD_MODE__) || defined(__UMTS_TDD128_MODE__) // BJM
typedef struct
{
   kal_uint8           numElements;
   GSM_TargetCellInfo  target_gcell_info[MAX_TARGET_GSM_CELLS_NUM];
} uas_gas_redirectInfo;
#endif /* defined(__UMTS_FDD_MODE__) || defined(__UMTS_TDD128_MODE__) */

typedef struct
{
   te_gsm_band_indicator  gsm_band_indicator;
   kal_uint8             *ARFCN_bitmap;
} eas_gas_redirectInfo;

#if defined(__UMTS_FDD_MODE__) || defined(__UMTS_TDD128_MODE__) // BJM
typedef union
{
   uas_gas_redirectInfo  uas_redirectInfo;
   eas_gas_redirectInfo  eas_redirectInfo;
} redirect_info_union;
#endif /* defined(__UMTS_FDD_MODE__) || defined(__UMTS_TDD128_MODE__) */

#if (defined(__UMTS_R5__) && defined(__GERAN_R5__))
typedef struct
{
   kal_uint8  numOctets;
   kal_uint8  stringData[23]; /* Only the first numOctets elements are valid */
} GERAN_SystemInfoBlock;

typedef struct
{
   kal_uint8              numElements;
   GERAN_SystemInfoBlock  element[MAX_GSM_SYS_INFO_BLOCKS_NUM]; /* Only the first numElements are valid */
} GERAN_SystemInformation;
#endif

#if defined(__UMTS_FDD_MODE__) || defined(__UMTS_TDD128_MODE__) // BJM
typedef struct GSM_Redirect_Info
{
   te_ir_redirection_type  redirection_type;
   redirect_info_union     redirection_info;
} GSM_Redirect_Info;
#endif /* defined(__UMTS_FDD_MODE__) || defined(__UMTS_TDD128_MODE__) */

#if (defined(__UMTS_R5__) && defined(__GERAN_R5__)) // BJM
typedef struct
{
   GERAN_SysInfoType        sys_info_type;
   GERAN_SystemInformation  sys_info;
} te_ir_geran_sys_info;

typedef struct
{
   kal_uint8              bsic;
   te_gsm_band_indicator  gsm_band_indicator;
   kal_uint16             bcch_arfcn;
   te_ir_geran_sys_info   gsm_sys_info;
} GSM_TargetCell_SI_Info;
#endif /* (defined(__UMTS_R5__) && defined(__GERAN_R5__)) */

#if defined(__UMTS_FDD_MODE__) || defined(__UMTS_TDD128_MODE__) // BJM
typedef union
{
   GSM_TargetCellInfo  target_gcell_reselect_info;
   GSM_Redirect_Info   target_gcell_redirect_list;
} GSM_TargetCell_Info_union;

typedef struct
{
   kal_uint8               numElements;
   GSM_TargetCell_SI_Info  target_gcell_SI_info[MAX_TARGET_GSM_CELLS_NUM];
} GSM_TargetCell_SI_Info_List;

typedef union
{
   te_ir_geran_sys_info         target_gcell_reselect_SI_info;
   GSM_TargetCell_SI_Info_List  target_gcell_redirect_SI_list;
} GSM_TargetCell_SI_Info_union;
#endif /* defined(__UMTS_FDD_MODE__) || defined(__UMTS_TDD128_MODE__) */

typedef struct 
{
   te_cn_domain_cipher_status  cipher_status;
   /* The following flag is only used when 2G -> 3G HO and ciphering is on. 
    * Normally, this flag should be set to KAL_FALSE. If GAS got a new 
    * ciphering key, but this hasn't been activated yet (GAS hasn't received 
    * CIPHER COMMAND), and then 2G -> 3G HO happens, 3G NW will use OLD key
    * for the folllowing ciphering. Thus, at this case, GAS should set this 
    * flag to TRUE. RRCE will use OLD key instead of NEW key for ciphering.
    * Please refer to 25.331 CR 2567
    */
   kal_bool  is_new_cipher_key_received;
} ts_ciphering_info;

typedef struct
{
   kal_uint16 pci;
   kal_int16  rsrp;
   kal_int16  rsrq;
} ecell_meas_result_struct;

typedef struct
{
   kal_uint16  earfcn;
   kal_bool    is_best_cell_suitable_allowed_CSG;
   kal_bool    is_best_cell_allowed_hybrid;
   ecell_meas_result_struct  ecell_meas_result;
} csg_freq_search_result_struct;

// RAT change from 23G to 4G, NAS context transfer(MM->EMM)
typedef struct
{
    // UAS -> EMM
    kal_uint8                   nas_security_param[NAS_SECURITY_PARAM_LEN];

    // MM -> EMM
    kal_bool                    is_gmm_ready_connected;
    tau_required_enum           tau_required;
    kal_uint8                   cksn;
    security_context_struct     security_context;
    kal_bool                    is_ptmsi_valid;
    kal_uint8                   ptmsi[PTMSI_LEN];
    kal_bool                    is_ptmsi_sig_valid;
    kal_uint8                   ptmsi_sig[PTMSI_SIG_LEN];
    kal_bool                    is_rai_valid;
    rai_struct                  rai;
    kal_bool                    is_lai_valid;
    lai_struct                  lai;
    kal_bool                    is_tmsi_valid;
    kal_uint8                   tmsi[TMSI_LEN];
    gsm_update_status_enum      mm_update_status;
    kal_bool                    is_ecc_list_valid;
    plmn_id_struct              ecc_list_plmn;
    gsm_state_enum              gsm_attach_state;

} mm2emm_irat_info_struct;

// RAT change from 4G to 23G, NAS context transfer(EMM->MM)
typedef struct
{
    // ERRC -> RATCM (GAS/UAS?)
    ho_from_lte_type_enum       ir_ho_type;
    kal_bool                    gsm_cipher_key_infoP;
    kal_bool                    gsm_cipher_key128_infoP;
    csfb_indicator_enum         csfb_indicator;
    
    // EMM -> RATCM
    loopback_mode_status_enum   loopback_mode_status;

    // EMM to MM
    kal_bool                    rau_required;
    kal_uint8                   nas_ksi;
    security_context_struct     security_context[2];
    kal_bool                    is_mapped_ptmsi_valid;
    kal_uint8                   mapped_ptmsi[PTMSI_LEN];
    kal_bool                    is_mapped_ptmsi_sig_valid;
    kal_uint8                   mapped_ptmsi_sig[PTMSI_SIG_LEN];
    kal_bool                    is_mapped_rai_valid;
    rai_struct                  mapped_rai;
    mt_csfb_type_enum           mt_csfb_type;
    kal_bool                    is_ecc_list_valid;
    plmn_id_struct              ecc_list_plmn;
    kal_bool                    is_eia0_used;

} emm2mm_irat_info_struct;


typedef struct
{
    // SM -> ESM
    kal_bool                    sm_deactivate_isr;

} sm2esm_irat_info_struct;

typedef struct {
    kal_uint8 total_number; // Total number of active EPS bearer on ESM
    bearer_legacy_rat_para_struct parameters[MAX_TRANSFERRED_BEARER_NUM];
}sm_esm_bearer_legacy_para_struct;

typedef struct
{
    // ESM -> MM
    kal_bool                    esm_deactivate_isr;

    // ESM -> SM
    kal_uint16                  nsapi_status;

    // ESM -> SM
    sm_esm_bearer_legacy_para_struct bearer_legacy_para;

} esm2sm_irat_info_struct;

#ifdef __SGLTE__
typedef struct
{
    // SM -> MM
    kal_bool                    esm_deactivate_isr;

    // SM -> SM
    kal_uint16                  nsapi_status;


} sm_irat_info_struct;

#endif
/* __4G_BACKGROUND_SEARCH__ begin*/
typedef struct
{
   kal_uint16  earfcn;
   kal_uint16  pci;
   kal_int16   rsrp;
   kal_int16   rsrq;
} eas_cell_info;

/* 3G4 background search */
typedef struct
{
   kal_uint16  uarfcn;
   kal_uint16  pci;
   kal_int16   rscp;
/*FDD:in qdBm.Range:-480~-100 means (-120 ~-25)dBm in 0.25 dB Step.*/
/*TDD:in qdBm.Range:-500~-100 means (-125 ~-25)dBm in 0.25 dB Step.*/
#ifdef __UMTS_FDD_MODE__
   kal_int16   ec_n0; /*Ec/N0, in qdB. Range: -100~0 means -25~0 dB in 0.25 dB setp.*/
#endif //__UMTS_FDD_MODE__
} uas_cell_info;


/*2G4 background search */
typedef struct
{
   kal_uint16  garfcn;
   kal_uint16  bsic;
   te_gsm_band_indicator gsm_band_ind;
   kal_int32   rssi;   
} gas_cell_info;
/* __4G_BACKGROUND_SEARCH__ end*/

#ifdef __SGLTE__
typedef struct
{
    kal_bool                    is_gmm_ready_connected;
    kal_uint8                   cksn;
    security_context_struct     security_context;
    kal_bool                    is_ptmsi_valid;
    kal_uint8                   ptmsi[PTMSI_LEN];
    kal_bool                    is_ptmsi_sig_valid;
    kal_uint8                   ptmsi_sig[PTMSI_SIG_LEN];
    kal_bool                    is_rai_valid;
    rai_struct                  rai;
    kal_bool                    is_ecc_list_valid;
    plmn_id_struct              ecc_list_plmn;
    kal_bool                    is_ps_attached;
} mm2emm_ps_switch_info_struct;

typedef struct
{
    kal_uint8                   nas_ksi;
    security_context_struct     security_context;
    kal_bool                    is_mapped_ptmsi_valid;
    kal_uint8                   mapped_ptmsi[PTMSI_LEN];
    kal_bool                    is_mapped_ptmsi_sig_valid;
    kal_uint8                   mapped_ptmsi_sig[PTMSI_SIG_LEN];
    kal_bool                    is_mapped_rai_valid;
    rai_struct                  mapped_rai;
    kal_bool                    is_ecc_list_valid;
    plmn_id_struct              ecc_list_plmn;
    kal_bool                    is_ps_attached;
} emm2mm_ps_switch_info_struct;

typedef struct
{
    kal_uint8                   gprs_cksn;
    security_context_struct     security_context;
    kal_bool                    is_ptmsi_valid;
    kal_uint8                   ptmsi[PTMSI_LEN];
    kal_bool                    is_ptmsi_sig_valid;
    kal_uint8                   ptmsi_sig[PTMSI_SIG_LEN];
    kal_bool                    is_rai_valid;
    rai_struct                  rai;
    kal_bool                    is_ps_attached;
    tin_enum                    tin;
} mm2mm_ps_switch_info_struct;

typedef enum
{
    MM_TO_EMM_CONTEXT,
    EMM_TO_MM_CONTEXT,
    MM_TO_MM_CONTEXT
}emm_mm_context_type_enum;

typedef union
{
    mm2emm_ps_switch_info_struct  mm2emm_context;
    emm2mm_ps_switch_info_struct  emm2mm_context;
    mm2mm_ps_switch_info_struct   mm2mm_context;
}emm_mm_context_union;

typedef struct emm_mm_context_info_struct
{
    emm_mm_context_type_enum which_context;
    emm_mm_context_union     context;
}emm_mm_context_info_struct;


#endif /* __SGLTE__  */

#endif /* _IRAT_COMMON_STRUCT_H */
