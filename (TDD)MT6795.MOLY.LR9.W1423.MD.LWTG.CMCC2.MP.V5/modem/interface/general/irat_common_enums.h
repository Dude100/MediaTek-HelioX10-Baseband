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
 *   irat_common_enums.h
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
 * 	.
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
 * Change MAX_GSM_SYS_INFO_BLOCKS_NUM to 10
 *
 * removed!
 * removed!
 * Merge LTE GEMINI to MOLY
 *
 * removed!
 * removed!
 * Emergency PDN
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
 * Format SM code
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Merge error fixing
 *
 * removed!
 * removed!
 * [MM/EMM] 24.301/24.008 CR Implementation: Interface modification, add TMSI, ECC_PLMN
 *
 * removed!
 * removed!
 * Extern the number of LTE standby measurement frequencies from 4 to 8
 *
 * removed!
 * removed!
 * merge code.
 *
 * 03 14 2013 ye.yuan
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
 * [Henry][Multi-Mode Development] GAS Development and R8 CR Sync
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

#ifndef _IRAT_COMMON_ENUMS_H
#define _IRAT_COMMON_ENUMS_H

/* MACROS ******************************************************************/
/* MAX Values */
#define STADNBY_GSM_MAX_BSIC_NUM 32
#define BLK_LIST_ARRAY_SIZE (63)    /* Size of PCI bitmap array (504/8 = 63) */
#define MAX_NUM_LTE_MEAS_CELL (16)  /* Maximum number of reported cells per frequency */

#define MAX_MEAS_IRAT_FREQ (8)  /* The maximum supported LTE Inter-frequency for measurement.
                                   4 for TDD + 4 for FDD */

/* Measured results related: UAS to GAS/EAS */
#ifdef __UMTS_FDD_MODE__
#define MAX_NR_OF_FDD_CELLS_IN_CELL_LIST (32)
#endif
#ifdef __UMTS_TDD128_MODE__ 
#define MAX_NR_OF_TDD_CELLS_IN_CELL_LIST (32)
#endif //__UMTS_TDD128_MODE__

#ifdef __UMTS_TDD128_MODE__
#define MAX_NUM_MEASURED_UMTS_CARRIERS (9)
#else
#define MAX_NUM_MEASURED_UMTS_CARRIERS (3)
#endif 

#define LTE_INVALID_RSRP (0x7FFF)
#define LTE_INVALID_RSRQ (0x7FFF)
#define LTE_MAX_RSRP (-100)
#define LTE_MIN_RSRP (-660)
#define LTE_MAX_RSRQ (0)
#define LTE_MIN_RSRQ (-100)

#define MAX_NUM_CSG_FREQ (8) /* Maximum number used for 3G4 Autonumous CSG Search */
#define MAX_NUM_ECELL_MEAS_RESULT (8)

/* Maximum number used for 2G or 3G to LTE redirection information */
#define PCI_BITMAP_MAX_NUM (63)
#define MAX_NUM_MEASURED_GSM_CELLS 32 /* The maximum number of GSM cells that can be measured in the standby mode. 
                                       * This constant is used between UAS/EAS and GAS. 
                                       */

#define MAX_NUM_CSG_CARRIERS 8
#define MAX_NR_OF_CSG_CELLS_IN_CELL_LIST 8

#if (defined(__UMTS_R5__) && (defined(__GERAN_R5__)))
#define MAX_GSM_SYS_INFO_BLOCKS_NUM (10)
#endif

#if defined(__FDD_REDIRECTION__) || (defined(__UMTS_TDD128_MODE__) && defined(__UMTS_R6__) && defined(__GERAN_R6__))
#if defined(__UMTS_TDD128_MODE__)
#define MAX_TARGET_GSM_CELLS_NUM (64)
#else
#define MAX_TARGET_GSM_CELLS_NUM (32)
#endif
#else /* defined(__FDD_REDIRECTION__) || (defined(__UMTS_TDD128_MODE__) && defined(__UMTS_R6__) && defined(__GERAN_R6__)) */
#define MAX_TARGET_GSM_CELLS_NUM (1)
#endif /* defined(__FDD_REDIRECTION__) || (defined(__UMTS_TDD128_MODE__) && defined(__UMTS_R6__) && defined(__GERAN_R6__)) */

/* Maximun size of GSM list for 4G2 IR direction */
#define MAX_BYTE_OF_GSM_ARFCN (128)

/* Used for IR Handover */
#define MAX_LEN_HO_TO_UTRAN_MSG (251)          /* Octets */
#define MAX_LEN_UTRAN_HANDOVER_INFO_MSG (251)  /* Octets */
#define NAS_SECURITY_PARAM_LEN (6)

/* Used for IR Redirection (ts_eutra_redirect_info) */
#define MAX_UAS_EAS_REDIRECT_FREQ_NUM (8)

/* NAS Array Length */
#define UGSM_TI_IE_LEN  2 // according to 24.007 11.2.3.1.3
#define CK_LEN          16
#define IK_LEN          16
#define KC_LEN          8
#define KC128_LEN       16
#define PTMSI_LEN       4 /* not include P-TMSI Mobile IE header (0xF4) */
#define PTMSI_SIG_LEN   3
#define RAI_LEN         6
#define LAI_LEN         5
#define MS_ID_LEN       8
#define TMSI_LEN      4

/* TYPES DEFINITIONS ********************************************************/
typedef enum
{
    IR_RESULT_SUCCESS   = 0,            //Inter-RAT change is successful.
    IR_RESULT_FAILURE   = 1,            //Inter-RAT change is failed in target RAT.
    IR_RESULT_REJECT    = 2,            //Inter-RAT change is rejected in source RAT.
    IR_RESULT_SUCCESS_FORCED_BY_NAS = 3 //Inter-RAT change is forced to success in target NAS.
} irat_result_enum;

typedef enum
{
    IR_REJECT_NONE,                     //When irat_result != IR_RESULT_REJECT
    IR_REJECT_SET_RAT,                  //RATCM SET RAT action ongoing
    IR_REJECT_PLMN_SEARCH,              //RATCM PLMN SEARCH action ongoing
    IR_REJECT_RF_OFF,                   //RATCM RF OFF action ongoing
    IR_REJECT_DEACTIVATE,               //RATCM DEACTIVATE for IR search action ongoing
    IR_REJECT_PS_DETACH,                //MM PS Detach ongoing
    IR_REJECT_ONGOING_CM_SERVICE        //MM has ongoing CM service
} irat_reject_cause_enum;

typedef enum
{
    IR_TYPE_HO          = 0x00, //Indicates the inter-RAT procedure is handover procedure
    IR_TYPE_CCO         = 0x01, //Indicates the inter-RAT procedure is cell change order procedure. Note that this enumeration is only used between 2G and 4G.
    IR_TYPE_CCO_STAGE1  = 0x02, //Indicates the inter-RAT procedure is cell change order procedure before NAS starts to perform LU/RAU procedure for stage 2 contention phase. Note that this enumeration is only used between 2G and 4G.
    IR_TYPE_CCO_STAGE2  = 0x03, //Indicates the inter-RAT procedure is cell change order procedure for stage 2 contention phase. Note that this enumeration is only used between 2G and 4G.
    IR_TYPE_REDIRECT    = 0x04, //Indicates the inter-RAT procedure is redirection procedure
    IR_TYPE_CR          = 0x05, //Indicates the inter-RAT procedure is autonomous cell reselection procedure
    IR_TYPE_SEARCH      = 0x06, //This enumeration is only used by NAS to trigger search procedure. AS will not receive this enumeration.
} irat_type_enum;

typedef enum
{
    IR_SM_VIEW_SUCCESS,
    IR_SM_VIEW_FAIL,
    IR_SM_VIEW_SUCCESS_BUT_23G_RAT_UNKNOWN, // due to 4G23 IR_TYPE_SEARCH
    IR_SM_VIEW_NOT_REVELENT_TO_SM //ex: CCO stage 1, from SM's point of view, CCO stage 1 does not mean anything, SM does not need to do anything, SM just need to relay this msg.
} irat_sm_view_result_enum;

typedef enum
{
    IR_TRANSFER_BEARER_PRIMARY_PDP_CONTEXT    = 0x00,
    IR_TRANSFER_BEARER_DEFAULT_EPS_CONTEXT    = IR_TRANSFER_BEARER_PRIMARY_PDP_CONTEXT,
    IR_TRANSFER_BEARER_SECONDARY_PDP_CONTEXT  = 0x01,
    IR_TRANSFER_BEARER_DEDICATED_EPS_CONTEXT  = IR_TRANSFER_BEARER_SECONDARY_PDP_CONTEXT,
    IR_TRANSFER_BEARER_REJECTED_BY_SM_DUE_TO_NSAPI_NOT_VALID,
    IR_TRANSFER_BEARER_REJECTED_BY_SM_DUE_TO_PDP_ADDR_TYPE_NOT_VALID,
    IR_TRANSFER_BEARER_REJECTED_BY_SM_DUE_TO_TFT_VALIDATE_FAIL,
    IR_TRANSFER_BEARER_REJECTED_BY_SM_DUE_TO_NO_23G_QOS,
    IR_TRANSFER_BEARER_REJECTED_BY_SM_DUE_TO_NO_23G_TI,
    IR_TRANSFER_BEARER_REJECTED_BY_SM_DUE_TO_NO_2G_LLC_SAPI,
    IR_TRANSFER_BEARER_REJECTED_BY_SM_DUE_TO_NO_2G_RADIO_PRIORITY,
    IR_TRANSFER_BEARER_REJECTED_BY_SM_DUE_TO_NO_EPS_QOS,
    IR_TRANSFER_BEARER_REJECTED_BY_SM_DUE_TO_EXCEED_GPRS_MAX_PDP_SUPPORT_KILL_QCI_1_TO_4,
    IR_TRANSFER_BEARER_REJECTED_BY_SM_DUE_TO_EXCEED_GPRS_MAX_PDP_SUPPORT_KILL_QCI_5_TO_9_SECONDARY,
    IR_TRANSFER_BEARER_REJECTED_BY_SM_DUE_TO_EXCEED_GPRS_MAX_PDP_SUPPORT_KILL_QCI_5_TO_9_PRIMARY,
    IR_TRANSFER_BEARER_REJECTED_BY_SM_DUE_TO_PRIMARY_MAPPED_FAILED,
    IR_TRANSFER_BEARER_REJECTED_BY_SM_DUE_TO_EMC_BEARER_NOT_ALLOWED
} irat_transfer_bearer_type_enum;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef enum
{
    RAT_TYPE_GAS,     // GERAN
    RAT_TYPE_UAS_FDD, // UTRAN (FDD mode)
    RAT_TYPE_UAS_TDD, // UTRAN (TDD mode)
    RAT_TYPE_EAS,      // E-UTRAN (LTE)
    RAT_TYPE_GAS_UAS_TBD // if 4G23 irat_type == IR_TYPE_SEARCH, LTE rat does not know which target rat will be chosen.
} rat_type_enum;

typedef enum
{
    BEARER_MAP_INVALID, // no such bearer
    BEARER_MAP_ACTIVE, // bearer mapping success
    BEARER_MAP_FAILED, // bearer mapping failure and local released
    BEARER_MAP_FAILED_DUE_TO_DETACH, // bearer mapping failure because new MM is detached.
    BEARER_MAP_FAILED_DUE_TO_CURRENT_SIM_NOT_HAVE_CONTEXT_MEMORY, // for example, if ESM context transfer to MOD_SM, but context memory is occupied by MOD_SM_2, that means MOD_SM_2 has PDP and hense MOD_SM cannot activate any PDP
    BEARER_MAP_FAILED_DUE_TO_NSAPI_NOT_VALID,
    BEARER_MAP_FAILED_DUE_TO_PDP_ADDR_TYPE_NOT_VALID,
    BEARER_MAP_FAILED_DUE_TO_TFT_VALIDATE_FAIL,
    BEARER_MAP_FAILED_DUE_TO_NO_23G_QOS,
    BEARER_MAP_FAILED_DUE_TO_NO_23G_TI,
    BEARER_MAP_FAILED_DUE_TO_NO_2G_LLC_SAPI,
    BEARER_MAP_FAILED_DUE_TO_NO_2G_RADIO_PRIORITY,
    BEARER_MAP_FAILED_DUE_TO_NO_EPS_QOS,
    BEARER_MAP_FAILED_DUE_TO_EXCEED_GPRS_MAX_PDP_SUPPORT_KILL_QCI_1_TO_4,
    BEARER_MAP_FAILED_DUE_TO_EXCEED_GPRS_MAX_PDP_SUPPORT_KILL_QCI_5_TO_9_SECONDARY,
    BEARER_MAP_FAILED_DUE_TO_EXCEED_GPRS_MAX_PDP_SUPPORT_KILL_QCI_5_TO_9_PRIMARY,
    BEARER_MAP_FAILED_DUE_TO_PRIMARY_MAPPED_FAILED,
    BEARER_MAP_FAILED_DUE_TO_EMC_BEARER_NOT_ALLOWED
    //BEARER_MAP_LOCAL_RELEASE // bearer local released
} bearer_mapping_result_enum;

typedef enum
{
    HO_FROM_LTE_TYPE_INVALID,
    HO_FROM_LTE_TYPE_PS_HO,
    HO_FROM_LTE_TYPE_SRVCC_HO,
    HO_FROM_LTE_TYPE_PS_SRVCC_HO
} ho_from_lte_type_enum;

typedef enum
{
    GAS_CIPHER_ALGO_INVALID,
    GAS_CIPHER_ALGO_KC,
    GAS_CIPHER_ALGO_KC128
} gas_cipher_algo_enum;

typedef enum
{
    DOMAIN_ID_INVALID,
    DOMAIN_ID_PS_PRESENCE,
    DOMAIN_ID_CS_PRESENCE
} sec_ctxt_domain_id_enum;

typedef enum
{
    MT_CSFB_TYPE_INVALID,
    MT_CSFB_TYPE_STMSI_TMSI,
    MT_CSFB_TYPE_IMSI
} mt_csfb_type_enum;

typedef enum
{
    LOOPBACK_MODE_DEACTIVATE,
    LOOPBACK_MODE_ACTIVATE_A,
    LOOPBACK_MODE_ACTIVATE_B,
    LOOPBACK_MODE_CLOSELOOP_A,
    LOOPBACK_MODE_CLOSELOOP_B
} loopback_mode_status_enum;

typedef enum
{
    TAU_NOT_REQUIRED,
    TAU_REQUIRED,
    TAU_COMB_TALA_IMSI_ATTACH
} tau_required_enum;

#if 0 // use the one defined in l3_inc_enums.h instead
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* Merged from GSM / UMTS Multimode development branch **********/
typedef enum
{
   UMTS_UNDEFINED_MODE
#if defined(__UMTS_FDD_MODE__)
   ,UMTS_FDD_MODE
#endif
#if defined(__UMTS_TDD128_MODE__)
   ,UMTS_TDD_MODE
#endif
} te_umts_mode;

typedef enum
{
   EL1_BANDWIDTH_6_RB,
   EL1_BANDWIDTH_15_RB,
   EL1_BANDWIDTH_25_RB,
   EL1_BANDWIDTH_50_RB,
   EL1_BANDWIDTH_75_RB,
   EL1_BANDWIDTH_100_RB,
   EL1_BANDWIDTH_INVALID
} eas_bandwidth_enum;

/* Measured results related: UAS to GAS/EAS */
typedef enum {
   IR_BAR_STATUS_NOT_BARRED,
   IR_BAR_STATUS_BARRED
} te_ir_bar_status;

typedef enum {
   IR_RESEL_CRITERIA3_NOT_SATISFIED,
   IR_RESEL_CRITERIA3_UNKNOWN,
   IR_RESEL_CRITERIA3_SATISFIED
} te_ir_resel_criteria3_status;

typedef enum {
   AUTO_SEARCH_START = 0x00,
   AUTO_SEARCH_RESUME = 0x01,
   AUTO_SEARCH_STOP = 0x02
} auto_search_cmd_enum;

typedef enum {
   SEARCH_STATUS_SUSPENDED = 0x00,
   SEARCH_STATUS_FINISHED = 0x01,
   SEARCH_STATUS_STOPPED = 0x02
} search_status_enum;

/**
 * @brief 
 *     te_ir_handover_status specifies the result of inter-RAT handover 
 *     procedure 
 *     . 
 */
typedef enum
{
   /* Handover message is correct or procedure is success */
   IR_HANDOVER_STATUS_NORMAL_EVENT,
   /* Applicable during Evaluation only */
   IR_HANDOVER_STATUS_FREQUENCY_NOT_IMPLEMENTED,
   /* Applicable only for Activation procedure
    * HO to GSM: Handover procedure failed due to lower layer failure at GSM.
    * HO to UTRAN: Failure to establish channels on cell(s) required for handover
    *              at any point during handover activation procedure.
    */
   IR_HANDOVER_STATUS_PHYSICAL_CHANNEL_FAILURE,
   /* Applicable during Evaluation procedure
    * Handover procedure failed due to inconsitent/missing parameters protocol
    * error. 
    */
   IR_HANDOVER_STATUS_PROTOCOL_ERROR,
   /* Applicable only during Evaluation procedure
    * HO to GSM: Handover message has a channel mode configuration which is not
    *            supported
    * HO to UTRAN : Predefined configuration not read or default configuration 
    *               not implemented. 
    */
   IR_HANDOVER_STATUS_UNSUPPORTED_CONFIGURATION,
   /* Applicable only for activation procedure, e.g. abort CS connection by UAS */
   IR_HANDOVER_STATUS_UNSPICIFIED_ERROR
} te_ir_handover_status;

/* This enumeration represents whether evaluation or activation for the target 
 * E-UTRA is cell is successful, failure, or CCO timer timeout (only used by 
 * cell change order procedure).
 */
typedef enum
{
   IR_CELL_RESELECTION_SUCCESS,
   IR_CELL_RESELECTION_FAILURE,
   IR_CELL_RESELECTION_TIMEOUT
} te_ir_cell_reselection_status;

/* Define for Evaluation or Activation Failed Type */
typedef enum
{
   IR_INITIAL_VALUE   = 0x00,
   NEVER_ALLOWED      = 0x01,  //For Frequency Band Not Support Case.
   PLMN_ID_MISMATCHED = 0x02,   
   LA_NOT_ALLOWED     = 0x03,
   CELL_BARRED        = 0x04,
   TEMP_FAILURE       = 0x05,
   CRITERIA3_NOT_SATISFIED = 0x06,
   TA_NOT_ALLOWED     = 0x07,
   CELL_BARRED_FREQ   = 0x08,
   CELL_BARRED_RESV_OPERATOR = 0x09,
   CELL_BARRED_RESV_OPERATOR_FREQ = 0x0A,
   CSG_NOT_ALLOWED    = 0x0B,
   GEMINI_FAILURE     = 0x0C,
   NAS_REJECT = 0x0D
} te_eval_activate_fail_type;

typedef enum {
   IR_CELL_RESELECTION,
   IR_CELL_CHANGE_ORDER,
   IR_REDIRECTION
#ifdef __CMCC_STD_FR__
   ,IR_STD_FR
#endif
   ,IR_AUTO_FAST_RETURN
   ,IR_NW_FAST_RETURN
} te_ir_cell_change_trigger;

typedef enum {
   GSM_BAND_INDICATOR_DCS1800, /* Default */
   GSM_BAND_INDICATOR_PCS1900
} te_gsm_band_indicator;

typedef enum {
   ACQ_CGI_SUCCESS             = 0x00,
   ACQ_CGI_FAIL_CELL_FOUND     = 0x01,
   ACQ_CGI_FAIL_CELL_NOT_FOUND = 0x02
} cgi_info_status_enum;

typedef enum {
   REPORT_CGI_STOP  = 0x00,
   REPORT_CGI_START = 0x01
} report_cgi_req_type_enum;

typedef enum {
   IR_FREQUENCY_NOT_IMPLEMENTED,
   IR_NO_RESPONSE_ON_TARGET_CELL,
   IR_REJECT_ON_TARGET_CELL,
   /* 3G failed reason */
   IR_CONFIGURATION_UNACCEPTABLE,
   IR_PHYSICAL_CHANNEL_FAILURE,
   /* for Gemini */
   IR_SUSPENDING_DURING_IR_CELL_RESEL,
   IR_CELL_CHANGE_FAIL_REASON_NONE
} te_ir_cell_change_fail_reason_enum;

typedef enum
{
   GAS_UAS_REDIRECTION_INFO = 0x00,
   EAS_UAS_REDIRECTION_INFO = 0x01,
   UAS_GAS_REDIRECTION_INFO = 0x02,
   EAS_GAS_REDIRECTION_INFO = 0x03
} te_ir_redirection_type;

#if (defined(__UMTS_R5__) && defined(__GERAN_R5__))
typedef enum{
   GERAN_SysInfo_None,
   GERAN_SysInfo_SI,
   GERAN_SysInfo_PSI
} GERAN_SysInfoType;
#endif

typedef enum {
   CIPHER_STATUS_NOT_STARTED,
   CIPHER_STATUS_STARTED
} te_cn_domain_cipher_status;

typedef enum
{
   IMSI_PAGING_TYPE,
   TMSI_PAGING_TYPE
} paging_type_enum; /* paging for CSFB */

typedef enum
{
   UNKNOWN_SERVICE_TYPE,
   CALL_SERVICE_TYPE,
   SS_SERVICE_TYPE,
   LCS_SERVICE_TYPE
} csfb_service_type_enum; /* service type for MO/MT CSFB */

typedef enum
{
   CSFB_IND_NONE,
   CSFB_IND_MO,
   CSFB_IND_MT
} csfb_indicator_enum; /* paging for CSFB */

typedef enum
{
   EUTRAN_DISABLED,
   EUTRAN_ENABLED
} eutran_cap_enum; /* E-UTRAN capability */

typedef enum
{
   NORMAL_CELL = 0x00,
   CSG_CELL    = 0x01,
   HYBRID_CELL = 0x02
} csg_access_mode_enum;

typedef enum
{
	BEARER_SERVICE_TYPE_NORMAL = 0,
	BEARER_SERVICE_TYPE_EMERGENCY
} bearer_service_type_enum;



#endif /* _IRAT_COMMON_ENUMS_H */
