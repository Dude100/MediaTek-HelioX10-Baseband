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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * L3_INC_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common enums of L3.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
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
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _L3_INC_LOCAL_H
#define _L3_INC_LOCAL_H

#include "kal_general_types.h"
//#include "kal_non_specific_general_types.h"
#include "l3_inc_enums.h"
#include "mcd_l3_inc_struct.h"
#include "ps_public_struct.h"
#include "irat_common_enums.h"

/*****************************************************************************
 * Constant Definitions
 *****************************************************************************/
#if defined (__GSM_RAT__) && defined (__UMTS_RAT__) && defined (__LTE_RAT__)
#define MAX_SUPPORTED_RAT 3

/* RAT configuration for dual mode capable project */
#elif (defined (__GSM_RAT__) && defined (__UMTS_RAT__)) || (defined (__GSM_RAT__) && defined (__LTE_RAT__)) || (defined (__UMTS_RAT__) && defined (__LTE_RAT__))
#define MAX_SUPPORTED_RAT 2

/* RAT configuration for single mode capable project */
#elif defined (__GSM_RAT__) || defined (__UMTS_RAT__) || defined (__LTE_RAT__)
#define MAX_SUPPORTED_RAT 1

#else
#error "Shall at least define 1 valid RAT!"
#endif /* RAT capability configuration */

#define RAC_MAX_NUM_LISTED_PLMNS 16*MAX_SUPPORTED_RAT   

/*****************************************************************************
 * Type Definitions
 *****************************************************************************/

#if (defined(__IPV4V6__) || defined (__IPV6__))
#define PACKET_FILTER_CONTENT_LEN   53  /* Poying: 29+(32-8) */
#else  /* (defined(__IPV4V6__) || defined (__IPV6__)) */
#define PACKET_FILTER_CONTENT_LEN   29
#endif /* (defined(__IPV4V6__) || defined (__IPV6__)) */

// LOCAL_PARA_HDR + kal_uint8 nsapi (SM code assume nsapi is the first parameter of some primitive)
#define NSAPI_STRUCT_HDR \
   LOCAL_PARA_HDR \
   kal_uint8 nsapi;

typedef struct {
    kal_uint8 pfi;
    kal_uint8 epi;
    kal_uint8 contents_len; /* in bytes*/
    kal_uint8 contents[PACKET_FILTER_CONTENT_LEN];
} packet_filter_struct;

typedef struct {
    kal_uint8 tft_op_code;
    kal_uint8 spare;
    kal_uint8 num_packet_filters;
    packet_filter_struct packet_list[8];
} tft_struct;

typedef struct {
    kal_uint16      req_n201u; //erica 20070112
} pdp_auxinfo_struct;


typedef struct {
    kal_uint8 length; /* LENGTH*/
    kal_uint8 digit0; /* DIGIT 0*/
    kal_uint8 odd_or_even; /* ODD OR EVEN*/
    kal_uint8 identity_type; /* IDENTITY TYPE*/
    kal_uint8 digit_byte[7];
} imsi_struct;

typedef struct {
    kal_uint16 bcch_list[8];
} bcchs_struct;


typedef struct {
    kal_uint8 length;
    kal_uint8 digit0;
    kal_uint8 odd_or_even;
    kal_uint8 identity_type;
    kal_uint8 digit_byte[7];
} imei_struct;

typedef struct {
    plmn_id_struct plmn_id;
    kal_uint8 la_code[2];
    kal_uint8 ra_code;  /* RA CODE*/
    kal_uint8 ta_code[2]; 
    kal_uint32 cell_id; /* CELL ID*/
#if defined(__CSG_SUPPORT__) || defined(__LTE_RAT__)
    kal_bool is_csg_cell;
    csg_info_struct csg_info;    
#endif
#ifdef __VOLTE_SUPPORT__
    kal_bool ims_emergency_support;
#endif
} cell_info_struct;

#if 0
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
#ifdef __CSG_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif
/*MAUI_02729678:In LU abnormal case, it need to remember cell inforamtion and current rat.
  And in some related function, one input parameter type is cell_info_struct.
  So it is not flexible to handle if we store abnormal cell information and rat 
  in a variable which is cell_info_rat_struct type.
  So, add this new type.
*/
typedef struct {
    cell_info_struct cell_info;
    rat_enum rat;  /* rat_enum */
    rat_duplex_type_enum duplex_type;
} cell_info_and_rat_struct;


typedef struct {
    kal_uint8          plmn_count;
    plmn_id_rat_struct plmn_id_rat[RAC_MAX_NUM_LISTED_PLMNS];
    kal_uint8          la_code[RAC_MAX_NUM_LISTED_PLMNS][2];
    nwsel_plmn_list_status_enum    status[RAC_MAX_NUM_LISTED_PLMNS];	
} rac_plmn_list_struct;

typedef enum
{
    MS_NULL_STATE = 0,
    MS_READY_STATE,
    MS_STANDBY_STATE,
    MS_FORCED_TO_STANDBY_STATE
}gmm_ms_state_enum;

/* UAS/GAS <-> RATCM begin */
typedef struct {
    plmn_id_struct   plmn_id;
    kal_uint8        la_or_ta_code[2];
    kal_int8         power_level;
    kal_bool         may_suitable_cell_exist;   
                     //TRUE(1) for suitable cell may exist;
                     //FALSE(0) for no suitable cell exist.
    kal_bool         may_suitable_cell_exist_higher_pri;
    lte_duplex_type_enum    lte_type;
#ifdef __VOLTE_SUPPORT__
    kal_bool ims_emergency_support;
#endif
} available_plmn_struct;

typedef struct {
    kal_uint8        plmn_count;
    kal_uint8        high_quality_plmn_count;
    available_plmn_struct available_plmn[MAX_NUM_PLMN_PER_RAT];
} as_plmn_list_struct;

typedef struct {
    plmn_id_rat_struct plmn_id_rat;
    kal_uint8 csg_count;
    csg_info_struct *csg_info_list;
} available_plmn_csg_struct;

typedef struct {
    kal_uint8 plmn_count;
    available_plmn_csg_struct available_plmn_csg[MAX_NUM_PLMN_PER_RAT];
} as_csg_list_struct;

typedef struct
{
    kal_uint8 plmn_count;
    available_plmn_csg_struct available_plmn_csg[MAX_NUM_PLMN_OF_CSG];
} rac_csg_list_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool is_cs_cipher_key_info_present;      /* if GSM CS cipher key present */
    kal_uint8 cs_cipher_key_info[KC_LEN];        /* GSM CS domain cipher key (Kc) */
    kal_bool is_cs_cipher_key128_info_present;   /* if GSM CS cipher key128 present */
    kal_uint8 cs_cipher_key128_info[KC128_LEN];  /* GSM CS domain cipher key128 (Kc128) */
    kal_uint8 cksn; /* cipher key sequence number */
#ifdef __PS_HO__
    kal_bool is_ps_cipher_algo_present;
    kal_uint8 ps_cipher_algo;
#endif
}ratcm_gas_security_mode_req_struct;

typedef struct{
    domain_id_enum	domain_id;  //The domain of security context
    kal_uint8	umts_ciphering_key[CK_LEN]; //UMTS ciphering key
    kal_uint8	umts_integrity_key[IK_LEN]; //UMTS integrity key
}uas_security_context_struct;

/* UAS/GAS <-> RATCM end */

typedef struct {
    domain_id_enum pag_resp_rest_ind;
    domain_id_enum loc_reg_rest_ind;   
    kal_uint16 loc_reg_ppacr;
} ppacr_info_struct ;

/* L4C <-> ENAS/EAS begin */

/* Cell restriction related definitions */
#define REST_CELL_ARRAY_SIZE    8
#define REST_FREQ_ARRAY_SIZE    8

typedef enum {
    REST_MODE_NULL,
    REST_MODE_RESTRICTED_LIST,
    REST_MODE_PERMITTED_LIST
} rest_mode_enum;

typedef struct {
    kal_uint16                  earfcn;            /* EARFCN */
    kal_uint16                  lower_cell_id;     /* Lower Physical Cell Identity */
    kal_uint16                  higher_cell_id;    /* Higher Physical Cell Identity */
} rest_cell_range_struct;

typedef struct{
    kal_uint16                  lower_earfcn;      /* Lower EARFCN */
    kal_uint16                  higher_earfcn;     /* Higher EARFCN */
} rest_freq_range_struct;

typedef struct{
    rest_mode_enum              mode;                                               /* Restricted list mode */
    kal_uint8                   rest_cell_range_num;                                /* Number of restricted cell list */
    kal_uint8                   rest_freq_range_num;                                /* Number of restricted frequency list */
    rest_cell_range_struct      rest_cell_range_list[REST_CELL_ARRAY_SIZE];         /* Restricted cell list */
    rest_freq_range_struct      rest_freq_range_list[REST_FREQ_ARRAY_SIZE];         /* Restricted frequency list */
    kal_bool                    is_umts_rest;                                       /* If all umts cells are restricted */
    kal_bool                    is_gsm_rest;                                        /* If all gsm cells are restricted */
} rest_command_struct;

/* Monitor mode struct */
typedef struct{
    kal_bool                    is_monitor_mode_set;                                /* Is monitor mode is switched on or off */
} monitor_mode_command_struct;

/* L4C <-> ENAS/EAS end */

/* ETCM <-> ENAS/EAS begin */
#define MIN_APN_LEN                     1
#define MAX_APN_LEN                     100

typedef struct
{
    kal_uint8                   length;
    kal_uint8                   data[MAX_APN_LEN];

} apn_struct;

/* ETCM <-> ENAS/EAS end */

/* NWSEL <-> ENAS/EAS begin */
typedef struct
{
kal_uint8 addr_length;
	kal_uint8 addr_bcd[41];
} l3_addr_bcd_struct;

typedef struct {
	kal_uint8          category;
	l3_addr_bcd_struct	tel_number;
} ecc_number_struct;

/* RATCM -> MM -> NWSEL */
typedef struct {
    LOCAL_PARA_HDR
    plmn_id_struct plmn_id;
    kal_uint8 la_code[2];
    kal_uint16 cell_id;
} mm_cell_global_identity_info_ind_struct;

/* RATCM -> MM -> NWSEL */
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 gibi_tag;
    rat_enum rat;
    kal_bool is_data_pending;
    kal_bool is_sys_info_present;
#if defined(__UMTS_FDD_MODE__) || defined(__TD_NETWORK_SHARING__) || defined (UNIT_TEST)
    kal_uint8 multi_plmn_count;
    plmn_id_struct multi_plmn_id[MAX_NUM_MULTI_PLMN];
    as_cell_type_enum multi_plmn_cell_type[MAX_NUM_MULTI_PLMN];
#endif
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
    kal_uint8 dsac_plmn_bitmask;
    kal_uint16 cs_dsac[MAX_NUM_MULTI_PLMN];
    kal_uint16 ps_dsac[MAX_NUM_MULTI_PLMN];
#endif
    kal_uint8 t3212_timer_val;
    network_mode_enum nmo;
    as_cell_type_enum cell_type;
    att_flag_enum att_flag;
    kal_bool mscr;
    rr_mm_sgsnr_flag_enum sgsnr;
#if defined (__PS_SERVICE__) || defined (UNIT_TEST)
    data_speed_support_enum cell_data_speed_support; /* MAUI_02361221: for egprs and hspa */
#endif

#if defined (__PPACR_SUPPORT__) || defined (UNIT_TEST)
    kal_uint8 ppacr_plmn_bitmask;
    ppacr_info_struct ppacr_info_plmn_list[MAX_NUM_MULTI_PLMN];
#endif

#if defined (__3G_CSG_SUPPORT__) || defined (UNIT_TEST)
    csg_access_mode_enum csg_access_mode;
    csg_info_struct csg_info;
#endif

#ifdef __LTE_RAT__
    kal_bool is_gprs_info_in_si13_deferred;
#endif
} mm_sys_info_ind_struct;

typedef struct
{
   plmn_id_struct   rplmn;
   kal_uint8        eq_plmn_byte_count;
   kal_uint8        eq_plmn_id[MAX_NUM_EQ_PLMN*3];
} update_eplmn_struct;

/* NWSEL <-> ENAS/EAS end */

typedef struct
{
    ims_ind_enum                    ims_ind;
    emergency_service_ind_enum      emergency_service_ind;
    location_service_epc_ind_enum   location_service_epc_ind;
    location_service_cs_ind_enum    location_service_cs_ind;    
} emm_nw_feature_support_struct;

typedef struct
{
    ug_ims_ind_enum                 ims_voice_over_ps_ind;
    ug_emergency_service_ind_enum   emergency_service_ind;
} gmm_nw_feature_support_struct;

#ifdef __SGLTE__
typedef struct
{
    /* Relay from Peer 2G. */
    lr_result_enum      peer_lr_result;
    nas_proc_enum       peer_lr_procedure;
    mm_cause_enum       mm_peer_reject_cause;
    plmn_id_struct      mm_peer_plmn_id;
    kal_bool            is_update_eq_plmn_needed;
    kal_uint8           eq_plmn_byte_count;
    kal_uint8           eq_plmn_id[MAX_NUM_EQ_PLMN*3];
    
    /* Info from EMM itself. */
    kal_bool            stored_guti_valid;
    eps_state_enum      lte_attach_state;
    eps_update_status_enum lte_update_status; 
} mmdc_peer_lr_result_struct;

typedef struct
{
    kal_uint16  arfcn;
    kal_bool is_PCS1900_band;
} mmdc_srv_cell_info_struct;

typedef struct
{
    kal_uint16 arfcn;
    kal_bool is_PCS1900_band;
    kal_int32 rssi_good_threshold;
} mmdc_eas_2g_freq_threshold_struct;

typedef struct
{
    kal_uint8 num_2g_freq;
    mmdc_eas_2g_freq_threshold_struct eas_2g_freq_threshold[MAX_SYS_CRITERIA_NUM];
    kal_int32 rsrp_bad_threshold;
    kal_int32 rsrq_bad_threshold;
    kal_int32 qrxlevmin;
    kal_int32 qqualmin;
    kal_uint16 tresel_2g;
} mmdc_eas_sys_threshold_struct;

typedef struct
{
    kal_bool is_valid;
	kal_uint8 gsm_nbr_total;
    kal_int16 rscp_bad_threshold;   // in qdbm
    kal_int16 rssi_good_offset;       // in dbm
    kal_uint16 Treselection;   // in seconds
    kal_int16 Qrxlevmin;   // in dbm
} mmdc_uas_sys_threshold_struct;

typedef struct
{
    kal_uint8  thresh_utran_high;
    kal_int16  utran_qrxlevmin;
    kal_uint16  uarfcn;  
} mmdc_uas_priority_threshold_struct;

typedef struct
{
    kal_uint8  thresh_eutran_high;
    kal_int16  eutran_qrxlevmin;
    kal_uint16   earfcn;
} mmdc_eas_priority_threshold_struct;

typedef struct
{
    kal_bool is_priority_based;   //true: priority based reselection(using thresh_high); false: ranking reselection(using tdd_qoffset)
    kal_int8 tdd_qoffset;            // 2G3 based on ranking reselection
    kal_uint8  t_reselection;
    kal_uint8  umts_carrier_num;    //num of uas_priority_threshold
    kal_uint8  lte_freq_num;             //num of eas_priority_threshold
    mmdc_uas_priority_threshold_struct   uas_priority_threshold[MAX_NR_OF_UAS_PRIO_THRESH];
    mmdc_eas_priority_threshold_struct    eas_priority_threshold[MAX_NR_OF_EAS_PRIO_THRESH];
}mmdc_gas_sys_threshold_struct;

typedef struct
{
    kal_bool idle_oos;
    kal_bool conn_oos;
} mmdc_as_oos_triger_ind_struct;

typedef struct
{
    kal_bool is_eutra_nbr_present_tas;
    kal_bool is_utra_nbr_present_eas;
} mmdc_nbr_info_ind_struct;

#endif /* __SGLTE__*/

/* NWSEL <-> ENAS/EAS end */

#ifdef __LTE_RAT__
typedef struct {
    LOCAL_PARA_HDR
    errc_sim_protect_purpose_enum purpose;
    kal_bool need_protect;
} errc_sim_protect_req_struct;
#endif //__LTE_RAT__

#endif 


