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
 * PPP2TCM_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of TCM and L4C.
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

#ifndef _PPP2TCM_STRUCT_H
#define _PPP2TCM_STRUCT_H

//#include "mmi_l3_enums.h"

//------------------------------ suggest Add ------------------------------
//#include "kal_non_specific_general_types.h"

/* Poying: MSBB. */
//#include "mmi_sm_enums.h"
//#include "tcm2sm_struct.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"

//------------------------------ suggest Add ------------------------------
#include "kal_general_types.h"
#include "kal_public_defs.h"

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 l2p_type; /* layer two protocol*/
    kal_uint8 pdp_addr_len; /* pdp address length*/
    kal_uint8 pdp_type; /* pdp address type*/
    kal_uint8 pdp_addr[16];
    kal_uint8 config_protocol;
    kal_uint8 config_option_len; /* config option length*/
    config_option_struct config_option[MAX_NUM_CONFIG_OPTION_PACKETS];
    kal_uint8 src_id;
	//mtk04121
	kal_uint32 req_reason;
} mmi_ext_pdp_activate_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 flc_pool_type;
    kal_uint8 pool_id;
} mmi_ext_data_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 src_id;
    #ifdef __LOCAL_DEACTIVATE_PDP_SUPPORT__
    kal_bool local_deactivate_pdp; /* __LOCAL_DEACTIVATE_PDP_SUPPORT__ */	
    #endif // ~ __LOCAL_DEACTIVATE_PDP_SUPPORT__
    tcm_pdp_deact_reason_enum deact_reason; // this deactivation is due to MSG_ID_TCM_RAT_TCM_INIT_DEACTIVATE_CONTEXT_IND
} mmi_ext_pdp_deactivate_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_uint8 cause;
} mmi_link_free_ind_struct;

typedef struct {
    // [Note] 20081114
    //  This struct shall be aligned with cmux_pkt_data_ind_struct
    //  If you need to modify it, please notify both TCM & CMUX owners. Thanks!
    LOCAL_PARA_HDR
    kal_uint8 context_id; /* for __APP_SECONDARY_PDP_SUPPORT__ */
    kal_uint8 profile_id;
    kal_uint8 flc_pool_type;
    kal_uint8 pool_id;
} mmi_data_ind_struct;

// PPP Type PDP Dialup Feature
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 serial_number; // for matching request and confirm
    kal_uint8 context_id;
    kal_uint8 src_id;
    kal_uint8 ipv4_addr[4];
    kal_uint8 ipv4_dns1[4];
    kal_uint8 ipv4_dns2[4];
    kal_uint8 ipv6_addr[16];
    kal_uint8 ipv6_dns1[16];
    kal_uint8 ipv6_dns2[16];
} mmi_ext_pdp_set_ip_and_dns_info_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 context_id;    
    kal_uint8 channel_id;
    pdp_addr_type_enum pdp_type;    
    kal_uint8 additional_para_type; //tcm_pdp_activate_req_additional_para_type_enum (TCM_PDP_ACT_REQ_HAS_EXTRA_PARA_AS_MODULE_ID)
    kal_uint32 additional_para_content; // module id
}ppptcm_enter_data_mode_req_struct;


typedef mmi_ext_pdp_activate_ind_struct taf_ext_pdp_activate_ind_struct;
typedef mmi_ext_data_ind_struct taf_data_ind_struct;
typedef mmi_data_ind_struct tcpip_tcm_data_req_struct;
typedef mmi_ext_pdp_deactivate_ind_struct taf_ext_pdp_deactivate_ind_struct;
typedef mmi_link_free_ind_struct taf_link_free_ind_struct;
typedef mmi_ext_pdp_set_ip_and_dns_info_req_struct taf_ext_pdp_set_ip_and_dns_info_req_struct;

typedef ppptcm_enter_data_mode_req_struct taf_ext_enter_data_mode_req_struct;

#endif 


