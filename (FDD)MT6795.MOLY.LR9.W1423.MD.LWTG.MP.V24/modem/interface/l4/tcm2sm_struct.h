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
 * TCM2SM_STRUCT.H
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

#ifndef _TCM2SM_STRUCT_H
#define _TCM2SM_STRUCT_H

#include "mcd_l3_inc_gprs_struct.h"
#include "l3_inc_local.h"
#include "mmi_l3_enums.h"
#include "mmi_sm_enums.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"
#include "tftlib_common_struct.h"

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct {
    NSAPI_STRUCT_HDR // LOCAL_PARA_HDR + kal_uint8 nsapi (SM code assume nsapi is the first parameter of some primitive)    
    qos_struct qos_requested; /* QoS requested by the Application*/
    qos_struct qos_minimum; /* Minimum QoS required by the Application*/
    kal_uint8 token_id; /* This field is used in case the requestis sent for a NW initiated context.*/
    pdp_addr_type_enum pdp_addr_type; /* It gives the address type whether it is IPV4, IPV6 or PPP*/
    pdp_addr_len_enum pdp_addr_len; /* Length of the PDP address*/
    kal_uint8 apn_len; /* Length of Access Point Name Parameter*/
    kal_uint8 p_comp_algo; /* Algo to be used for Protocol Compression. Used only in case of GPRS*/
    kal_uint8 d_comp_algo; /* Algo to be used for Data Compression. Used only in case if GPRS*/
    initiated_enum initiated_by; /* This field will tell that the request has come for a NW initiated context or for MS initiated*/
    kal_uint8 pdp_addr[MAXIMUM_POSSIBLE_ADDR_LEN]; // if MT IPv4v6 PDP activation, 
                                         // NW may carry 20 bytes (IPv4+IPv6) address to UE, 
                                         // UE need to carry this 20 bytes address in ACTIVATE_PDP_CONTEXT_REQUEST
    kal_uint8 access_name[100];
    kal_uint8 config_protocol;
    kal_uint8 config_option_len; /* config option length*/
    config_option_struct config_option[MAX_NUM_CONFIG_OPTION_PACKETS];
    pdp_auxinfo_struct      aux_info; //erica 20070112
    kal_bool is_use_r6_qos ; /* __MEDIATEK_SMART_QOS__ */
} smreg_pdp_activate_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    smreg_pdp_activate_req_struct trace;
} sm_trace_smreg_pdp_activate_req_struct;

typedef struct {
    NSAPI_STRUCT_HDR // LOCAL_PARA_HDR + kal_uint8 nsapi (SM code assume nsapi is the first parameter of some primitive)    
    ps_cause_enum cause; /* Cause of deactivation*/
    teardown_enum tear_ind; /* This field indicates whether to deactivate all the associated context or only one for which request has come*/
    #ifdef __LOCAL_DEACTIVATE_PDP_SUPPORT__
    kal_bool local_deactivate_pdp; /* __LOCAL_DEACTIVATE_PDP_SUPPORT__ */	
    #endif // ~ __LOCAL_DEACTIVATE_PDP_SUPPORT__
} smreg_pdp_deactivate_req_struct;

typedef struct {
    NSAPI_STRUCT_HDR // LOCAL_PARA_HDR + kal_uint8 nsapi (SM code assume nsapi is the first parameter of some primitive)    

    initiated_enum initiated_by; /* This field will tell that the request has come for a NW initiated context or for MS initiated*/
    kal_uint8 token_id; /* This field is used in case the requestis sent for a NW initiated context.*/

    qos_struct qos_requested; /* QoS requested by the user*/
    qos_struct qos_minimum; /* Minimum QoS required by the User*/
    tft_info_struct tft; /* This field gives the TFT parameters*/
    kal_uint8 linked_nsapi; /* The nsapi value of the associated primary context*/
    kal_uint8 p_comp_algo; /* Protocol Compression Algorithm. Used only for GPRS*/
    kal_uint8 d_comp_algo; /* Data Comprssion Algorithm. Used only for UMTS*/
    kal_uint8 config_protocol;
    kal_uint8 config_option_len; /* config option length*/
    config_option_struct config_option[MAX_NUM_CONFIG_OPTION_PACKETS];
    pdp_auxinfo_struct      aux_info; //erica 20070112
    kal_bool is_use_r6_qos ; /* __MEDIATEK_SMART_QOS__ */
} smreg_pdp_activate_sec_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    smreg_pdp_activate_sec_req_struct trace;
} sm_trace_smreg_pdp_activate_sec_req_struct;

typedef struct {
    NSAPI_STRUCT_HDR // LOCAL_PARA_HDR + kal_uint8 nsapi (SM code assume nsapi is the first parameter of some primitive)    
    kal_bool qos_mod_present; // this is an optional IE in MODIFY PDP CONTEXT REQUEST (MS to Network direction)
    qos_struct qos_mod; /* New QoS Requested*/
    kal_bool qos_min_present;
    qos_struct min_qos;  /* minimum QoS */  //__3G_QOS__
    kal_bool tft_present; // this is an optional IE in MODIFY PDP CONTEXT REQUEST (MS to Network direction)
    tft_info_struct tft; /* New TFT Parameters*/
    //context_mod_type_enum mod_type; /* The type od modification initiated by user.*/
    kal_bool is_use_r6_qos ;
    //kal_uint8 config_protocol; // new, need to consider BCM:MS/NW ?
    //kal_uint8 config_option_len; /* config option length*/
    //config_option_struct config_option[MAX_NUM_CONFIG_OPTION_PACKETS];
} smreg_pdp_modify_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    ps_cause_enum cause; /* Cause of rejection*/
    kal_uint8 token_id; /* Context Indentifier*/
    pdp_addr_type_enum pdp_addr_type; /* PDP Address Type, can be IPV4, IPV6, PPP*/
    pdp_addr_len_enum pdp_addr_len; /* Length of PDP Address field*/
    kal_uint8 apn_len; /* Length of Access Point Name Parameter*/
    kal_uint8 pdp_addr[MAXIMUM_POSSIBLE_ADDR_LEN];
    kal_uint8 access_name[100];
} smreg_pdp_activate_rej_rsp_struct;

typedef struct {
    LOCAL_PARA_HDR
    ps_cause_enum cause; /* Cause of rejection*/
    kal_uint8 token_id; /* Context Indentifier*/
} smreg_pdp_activate_sec_rej_rsp_struct;


typedef struct {
    NSAPI_STRUCT_HDR // LOCAL_PARA_HDR + kal_uint8 nsapi (SM code assume nsapi is the first parameter of some primitive)    
} smreg_allow_dl_packet_ind_struct;

#endif 


