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
 * SM2TCM_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common enums of TCM and SM.
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

#ifndef _SM2TCM_STRUCT_H
#define _SM2TCM_STRUCT_H

#include "mmi_l3_enums.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "irat_common_struct.h"
#include "sm_esm_struct.h"
#include "l3_inc_local.h"
#include "tftlib_common_struct.h"

typedef struct {
    NSAPI_STRUCT_HDR // LOCAL_PARA_HDR + kal_uint8 nsapi (SM code assume nsapi is the first parameter of some primitive)    
    qos_struct qos_negotiated; /* QoS negotiated with the NW*/
    pdp_addr_type_enum pdp_addr_type; /* PDP Address Type, Can be IPV4, IPV6, PPP, IPV4V6*/
    kal_uint8 pdp_addr_len; /* Length of PDP Address Contents*/
    // If the pdp_addr_type == IPV4, this field contains IPV4 address, 
    // If the pdp_addr_type == IPV6, this field contains IPV6 address, 
    // If the pdp_addr_type == IPV4v6, this field contains IPV4 address in pdp_addr[0]~pdp_addr[3], 
    //                                 IPV6 address in pdp_addr[4]~pdp_addr[19]
    kal_uint8 pdp_addr[MAXIMUM_POSSIBLE_ADDR_LEN];
    kal_bool cause_2_present; // if network has cause_2 value in ACTIVATE_PDP_CONTEXT_ACCEPT
    ps_cause_enum cause_2; // the previous PDP accept cause_2 value, ex: PDP_TYPE_IPV4_ONLY_ALLOWED, 
                        // PDP_TYPE_IPV6_ONLY_ALLOWED, SINGLE_ADDR_BEARERS_ONLY_ALLOWED
    kal_uint8 config_protocol;
    kal_uint8 config_option_len; /* config option length*/
    config_option_struct config_option[MAX_NUM_CONFIG_OPTION_PACKETS];
} smreg_pdp_activate_cnf_struct;

typedef struct {
    NSAPI_STRUCT_HDR // LOCAL_PARA_HDR + kal_uint8 nsapi (SM code assume nsapi is the first parameter of some primitive)    
    kal_bool is_rejected_by_nw; // if this PDP is rejected by NW using SM peer msg, KAL_TRUE, else, KAL_FALSE
    ps_cause_enum cause; // Cause of rejection (also used for cause_2, 
                      // if cause_2 violation, reject immediately without trying to send ACTIVATE_PDP_CONTEXT_REQUEST)
    kal_uint8 config_protocol;
    kal_uint8 config_option_len; /* config option length*/
    config_option_struct config_option[MAX_NUM_CONFIG_OPTION_PACKETS];
} smreg_pdp_activate_rej_struct;

typedef struct {
    LOCAL_PARA_HDR
    pdp_addr_type_enum pdp_addr_type; /* PDP Address Type, Can be IPV4, IPV6, PPP, IPV4V6*/
    kal_uint8 pdp_addr_len; /* Length of PDP Address Contents*/
    kal_uint8 token_id; /* NW Initiated Context Identifier*/
    kal_uint8 apn_len; /* Length of Access Point Name Parameter*/
    kal_uint8 pdp_addr[MAXIMUM_POSSIBLE_ADDR_LEN];
      // If the pdp_addr_type == IPV4, pdp_addr_len == 4, this field contains IPV4 address, 
      // If the pdp_addr_type == IPV6, pdp_addr_len == 16, this field contains IPV6 address, 
      // If the pdp_addr_type == IPV4v6, 
      //  pdp_addr_len == 20, this field contains IPV4 address in pdp_addr[0]~pdp_addr[3], IPV6 address in pdp_addr[4]~pdp_addr[19]
      //  pdp_addr_len == 4, this field contains IPV4 address in pdp_addr[0]~pdp_addr[3]
      //  pdp_addr_len == 16, this field contains IPV6 address in pdp_addr[0]~pdp_addr[15]
    kal_uint8 access_name[100];
} smreg_pdp_activate_ind_struct;

typedef struct {
    //23.060 9.2.2.3 Network Requested Secondary PDP Context Activation Procedure using Gn
    //The MS sends an Activate Secondary PDP Context Request:
    //The Linked TI, TI, QoS Requested, and Protocol Configuration Options sent in the Activate secondary PDP Context Request shall be the same as previously received 
    LOCAL_PARA_HDR
    kal_uint8 token_id; /* NW Initiated Context Identifier*/
    qos_struct qos_required; /* Mandatory IE, QoS IE in 24.008 Table 9.5.15a REQUEST SECONDARY PDP CONTEXT ACTIVATION */
    kal_uint8 linked_nsapi; /* Mandatory IE, The nsapi value of the associated primary context*/
    kal_bool tft_present;
    tft_info_struct tft; /* Optional IE */
    kal_uint8 config_protocol; /* Optional IE, TFT IE in 24.008 Table 9.5.15a REQUEST SECONDARY PDP CONTEXT ACTIVATION */
    kal_uint8 config_option_len;
    config_option_struct config_option[MAX_NUM_CONFIG_OPTION_PACKETS];
} smreg_pdp_activate_sec_ind_struct;


typedef struct {
    NSAPI_STRUCT_HDR // LOCAL_PARA_HDR + kal_uint8 nsapi (SM code assume nsapi is the first parameter of some primitive)    
    qos_struct qos_negotiated; /* QoS Negotaited with the NW*/
    kal_uint8 config_protocol;
    kal_uint8 config_option_len; /* config option length*/
    config_option_struct config_option[MAX_NUM_CONFIG_OPTION_PACKETS];
} smreg_pdp_activate_sec_cnf_struct;

typedef struct {
    NSAPI_STRUCT_HDR // LOCAL_PARA_HDR + kal_uint8 nsapi (SM code assume nsapi is the first parameter of some primitive)    
    ps_cause_enum cause; /* Cause of rejection*/
} smreg_pdp_activate_sec_rej_struct;

typedef struct {
    LOCAL_PARA_HDR
    ps_cause_enum cause; // Cause of Deactivation, if deact_fail == KAL_TRUE, the cause == RAT_TCM_RETRY_NEEDED_AFTER_IRAT
    kal_uint8 tot_valid_nsapi; /* Total number of nsapi that are valid in the nsapi_list*/
    kal_uint8 nsapi_list[11];
    kal_bool deact_fail; // most scenario, deact_fail == KAL_FALSE. but when iRAT success and there is pending deact_req, then the deact_fail == TRUE
} smreg_pdp_deactivate_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    ps_cause_enum cause; /* Cause of Deactivation*/
    kal_uint8 tear_ind;
    kal_uint8 tot_valid_nsapi; /* Total number of nsapi that are valid in the nsapi_list*/
    kal_uint8 nsapi_list[11];
} smreg_pdp_deactivate_ind_struct;

typedef struct {
    NSAPI_STRUCT_HDR // LOCAL_PARA_HDR + kal_uint8 nsapi (SM code assume nsapi is the first parameter of some primitive)    
    kal_bool qos_mod_neg_present; // this is an optional IE in MODIFY PDP CONTEXT ACCEPT (Network to MS direction)
    qos_struct qos_mod_neg; /* The QoS negotiated with the NW after the modification*/
    //context_mod_type_enum mod_type; /* Note: TCM should not store this into session_info_block_struct.mod_type. */
    kal_bool tft_present; // if TCM send MOD_REQ with tft_present==TRUE, SM will send MOD_CNF with tft_present==TRUE
    kal_bool qos_min_present; // if TCM send MOD_REQ with qos_min_present==TRUE, SM will send MOD_CNF with qos_min_present==TRUE
    kal_uint8 config_protocol; // new, need to consider BCM mode
    kal_uint8 config_option_len; /* config option length*/
    config_option_struct config_option[MAX_NUM_CONFIG_OPTION_PACKETS];
} smreg_pdp_modify_cnf_struct;

typedef struct {
    NSAPI_STRUCT_HDR // LOCAL_PARA_HDR + kal_uint8 nsapi (SM code assume nsapi is the first parameter of some primitive)    
    ps_cause_enum cause; /* Cause of rejection*/
} smreg_pdp_modify_rej_struct;

typedef struct {
    NSAPI_STRUCT_HDR // LOCAL_PARA_HDR + kal_uint8 nsapi (SM code assume nsapi is the first parameter of some primitive)    
    kal_bool qos_negotiated_present; // this is an mandatory IE in MODIFY PDP CONTEXT REQUEST (Network to MS direction)
    qos_struct qos_negotiated; // this is an mandatory IE in MODIFY PDP CONTEXT REQUEST (Network to MS direction)
    //context_mod_type_enum mod_type; /* Note: TCM should not store this into session_info_block_struct.mod_type. */
    kal_bool pdp_addr_present; // this is an optional IE in MODIFY PDP CONTEXT REQUEST (Network to MS direction)
    kal_uint8 pdp_addr_len; /* Length of PDP Address contents*/
    kal_uint8 pdp_addr[MAXIMUM_POSSIBLE_ADDR_LEN];
    kal_bool tft_present; // this is an optional IE in MODIFY PDP CONTEXT REQUEST (Network to MS direction)
    tft_info_struct tft; /* This field gives the TFT parameters*/
    kal_uint8 config_protocol;
    kal_uint8 config_option_len; /* config option length*/
    config_option_struct config_option[MAX_NUM_CONFIG_OPTION_PACKETS];
} smreg_pdp_modify_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 no_of_nsapis; 
    kal_uint8 nsapi_list[11];
} smreg_pdp_preserve_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 no_of_nsapis; 
    kal_uint8 nsapi_list[11];
} smreg_pdp_reestablish_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    irat_type_enum irat_type;
    rat_type_enum source_rat;
    rat_type_enum target_rat;
    irat_result_enum irat_result;
    //sm_esm_context_status_struct pdp_transfer_result;
} smreg_rat_change_complete_ind_struct;

#ifdef __SGLTE__
typedef struct {
    LOCAL_PARA_HDR

    rat_enum source_rat;
    rat_enum target_rat;
    kal_bool result;
    //sm_esm_context_status_struct pdp_transfer_result;
} smreg_ps_change_complete_ind_struct;
#endif

#endif 


