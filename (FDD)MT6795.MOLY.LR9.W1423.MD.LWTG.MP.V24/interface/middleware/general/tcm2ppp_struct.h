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
 * TCM2PPP_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of TCM and PPP.
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

#ifndef _TCM2PPP_STRUCT_H
#define _TCM2PPP_STRUCT_H

#include "kal_general_types.h"
//#include "kal_non_specific_general_types.h"    
//#include "mmi_sm_enums.h"    
//#include "tcm2sm_struct.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"

//#include "mmi_l3_enums.h"

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 context_id;
    pdp_addr_type_enum pdp_addr_type; /* pdp_addr_type_enum */
    kal_uint8 pdp_addr_len; /* pdp address length*/
    kal_uint8 pdp_addr[MAXIMUM_POSSIBLE_ADDR_LEN]; // Array size is 20; If IPv4v6 address is assigned, 
                                         // pdp_addr[0]~[3] is IPv4 address, pdp_addr[4]~[19] is IPv6
    kal_uint8 config_protocol;
    kal_uint8 config_option_len; /* config option length*/
    config_option_struct config_option[MAX_NUM_CONFIG_OPTION_PACKETS];
    kal_uint8 dns[4];
    kal_uint8 src_id;
    kal_bool pdp_act_cause_2_present ; // if network has cause_2 value in ACTIVATE_PDP_CONTEXT_ACCEPT
    ps_cause_enum pdp_act_cause_2 ; // just relay the PDP accept cause_2 value, 
                                 // meaningful possible values are: PDP_TYPE_IPV4_ONLY_ALLOWED, 
                                 //                                 PDP_TYPE_IPV6_ONLY_ALLOWED, 
                                 //                                 SINGLE_ADDR_BEARERS_ONLY_ALLOWED
} mmi_ext_pdp_activate_ack_rsp_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 context_id;
    kal_uint8 config_protocol;
    kal_uint8 config_option_len; /* config option length*/
    config_option_struct config_option[MAX_NUM_CONFIG_OPTION_PACKETS];
    kal_uint8 src_id;
    kal_bool is_rejected_by_nw; // if this PDP is rejected by NW using SM peer msg, KAL_TRUE, else, KAL_FALSE
    kal_bool pdp_act_cause_present ; // if network has cause_2 value in previous ACTIVATE_PDP_CONTEXT_ACCEPT
    ps_cause_enum pdp_act_cause ; // the previous PDP accept cause_2 value, ex: PDP_TYPE_IPV4_ONLY_ALLOWED, 
                                 // PDP_TYPE_IPV6_ONLY_ALLOWED, SINGLE_ADDR_BEARERS_ONLY_ALLOWED
    ps_cause_enum cause; // (ps_cause_enum), this is used by RAT_TCM when value == RAT_TCM_RETRY_NEEDED_AFTER_IRAT
} mmi_ext_pdp_activate_rej_rsp_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 context_id;
    kal_uint8 src_id;
    l4c_result_enum result; // deactivate success or fail
    ps_cause_enum cause; // (ps_cause_enum), this is used by RAT_TCM when value == RAT_TCM_RETRY_NEEDED_AFTER_IRAT
} mmi_ext_pdp_deactivate_ack_rsp_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 context_id;
} mmi_ext_pdp_deactivate_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 context_id;
    kal_uint8 dl_pool_id;
} mmi_ext_data_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 context_id;
    pdp_addr_type_enum pdp_addr_type;
    kal_uint8 pdp_addr_len;
    kal_uint8 pdp_addr[16];
} mmi_ext_update_pdp_addr_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 context_id; /* for __APP_SECONDARY_PDP_SUPPORT__ */
    kal_uint8 profile_id;
} mmi_data_req_struct;

// PPP Type PDP Dialup Feature
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 serial_number; // for matching request and confirm
} mmi_ext_pdp_set_ip_and_dns_info_cnf_struct;

//mtk04121
/* PPP Dial-up */
typedef struct {
	kal_uint8 ref_count;
	kal_uint16 msg_len;
	kal_uint8 src_id;
	kal_uint8 context_id;
	kal_uint8 result;
	ps_cause_enum error_cause;
} ppptcm_enter_data_mode_cnf_struct;

typedef mmi_ext_pdp_activate_ack_rsp_struct taf_ext_pdp_activate_ack_rsp_struct;
typedef mmi_ext_pdp_activate_rej_rsp_struct taf_ext_pdp_activate_rej_rsp_struct;
typedef mmi_ext_pdp_deactivate_ack_rsp_struct taf_ext_pdp_deactivate_ack_rsp_struct;
typedef mmi_ext_pdp_deactivate_req_struct taf_ext_pdp_deactivate_req_struct;
typedef mmi_ext_data_req_struct taf_data_req_struct;
typedef mmi_data_req_struct tcpip_tcm_data_ind_struct;
typedef mmi_ext_update_pdp_addr_req_struct taf_ext_update_pdp_addr_req_struct;
typedef mmi_ext_pdp_set_ip_and_dns_info_cnf_struct taf_ext_pdp_set_ip_and_dns_info_cnf_struct;

//mtk04121
/* PPP Dial-up */
typedef ppptcm_enter_data_mode_cnf_struct taf_ext_enter_data_mode_cnf_struct;

#endif 


