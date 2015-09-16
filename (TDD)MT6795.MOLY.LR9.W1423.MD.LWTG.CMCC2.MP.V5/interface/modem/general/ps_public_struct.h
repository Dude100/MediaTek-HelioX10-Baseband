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
 * ps_public_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the ABM network internal APIs 
 *   and these APIs can only be used by MMI CBM and DA
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _PS_PUBLIC_STRUCT_H_
#define _PS_PUBLIC_STRUCT_H_

//#include "kal_non_specific_general_types.h"
#include "kal_public_defs.h"
#include "ps_public_enum.h"
#include "sim_ps_enum.h"
#include "sim_public_enum.h"
#if ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__))
    #include "mcd_l4_common.h"
#else
#include "kal_general_types.h"

extern kal_uint32 l4_pun_src_buff[180];
extern kal_uint32 l4_pun_dest_buff[200];
typedef struct _l4_addr_bcd_struct
{
	kal_uint8 addr_length;
	kal_uint8 addr_bcd[41];
} l4_addr_bcd_struct;


typedef struct _l4_name_struct
{
	kal_uint8 name_length;
	kal_uint8 name_dcs;
	kal_uint8 name[42];
} l4_name_struct;


typedef struct _l4_csd_name_struct
{
	kal_uint8 name_length;
	kal_uint8 name_dcs;
	kal_uint8 name[32];
} l4_csd_name_struct;

#endif /* ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__)) */

//#include "pwic.h"
//#include "pmic6318_sw.h"

/*#if defined(__VOIP__) || defined(__VIDEO_CALL_SUPPORT__)
#include "custom_voip_config.h"
#endif*/

#if defined(__WIFI_SUPPORT__)
/* WIFI test*/
#include "wndrv_ft_types.h"
#endif

#ifdef __MULTI_LEVEL_BACKLIGHT_SUPPORT__
#include "custom_hw_default.h"
#endif

typedef struct l4c_result_struct
{
   kal_uint8   flag;    /*l4c_result_enum*/
   kal_uint16   cause;

} l4c_result_struct;

typedef struct
{
   kal_uint32	total_rx_data;
   kal_uint32	total_tx_data;
   kal_uint32	last_rx_data;
   kal_uint32	last_tx_data;
} l4c_gprs_statistics_info_struct;

typedef struct
{
    kal_uint8 apn[MAX_APN_LEN];
} l4c_tcm_acl_entry_struct;

/* Poying: MSBB. */
typedef struct {
    kal_uint16 protocol_id;
    kal_uint8 protocol_config_len;
    kal_uint8 protocol_config[MAX_CONFIG_OPTION_CONTENT_LEN];
} config_option_struct;

typedef struct
{
    kal_uint8               context_id;
    kal_uint8               apn_length;
    kal_uint8               apn [ MAX_APN_LEN ];
    kal_uint8               dcomp_algo;      /*atci_dcomp_algo_enum*/
    kal_uint8               hcomp_algo;      /*atci_hcomp_algo_enum*/
    pdp_addr_type_enum      pdp_type;        /*pdp_type_enum*/
    pdp_addr_len_enum       pdp_addr_len;
    kal_uint8               addr_val[ MAX_PDP_ADDR_LEN ];
    kal_uint8               ipv4addralloc;
	kal_uint8               request_type;               //R12
	kal_uint8				p_cscf_discovery;			//R10
	kal_uint8				im_cn_signalling_flag;		//R10
} l4c_prim_pdp_info_struct;

typedef struct
{
    kal_uint8     context_id;      /* child context */
    kal_uint8     prim_context_id;  /* parent context */
    kal_uint8     dcomp_algo;     /* atci_dcomp_algo_enum */
    kal_uint8     hcomp_algo;     /* atci_hcomp_algo_enum */
	//mtk04121
	kal_uint8  	  im_cn_signalling_flag;		//R10
} l4c_sec_pdp_info_struct;

//mtk02219
#if !defined(__LTE_RAT__)
typedef struct {
    kal_uint8 pfi;
    kal_uint8 epi;
    kal_uint8 src_addr_sb_net_mask_len;
    kal_uint8 src_addr_sb_net_mask[MAX_SRC_ADDR_SBNET_MASK_LEN];
    kal_bool   prot_number_present;
    kal_uint8  prot_number_next_hdr;
    kal_uint8 dst_port_len;
    kal_uint16 dst_port_range[2];
    kal_uint8 src_port_len;
    kal_uint16 src_port_range[2];
    kal_bool   ipsec_spi_present;
    kal_uint32 ipsec_spi;
    kal_uint8 tos_len;
    kal_uint8 tos_traffic_class_mask[2];
    kal_bool   flow_label_present;
    kal_uint32 flow_label;
} l4c_pf_struct;

typedef struct
{
   kal_uint8 context_id;
   kal_uint8 tot_pf_count;
   l4c_pf_struct pf[8]; //mtk02126 8 is the max number of packet filters in 27.007 v 7.05 
} l4c_tft_struct;
#else

//mtk02219
typedef struct {
    kal_uint8 pfi;
    kal_uint8 epi;
    kal_uint8 src_addr_sb_net_mask_len;
    kal_uint8 src_addr_sb_net_mask[MAX_SRC_ADDR_SBNET_MASK_LEN];
    kal_bool   prot_number_present;
    kal_uint8  prot_number_next_hdr;
    kal_uint8 dst_port_len;
    kal_uint16 dst_port_range[2];
    kal_uint8 src_port_len;
    kal_uint16 src_port_range[2];
    kal_bool   ipsec_spi_present;
    kal_uint32 ipsec_spi;
    kal_uint8 tos_len;
    kal_uint8 tos_traffic_class_mask[2];
    kal_bool   flow_label_present;
    kal_uint32 flow_label;
} l4c_pf_struct_only_for_mmi;

//mtk02219
typedef struct
{
   kal_uint8 context_id;
   kal_uint8 tot_pf_count;
   l4c_pf_struct_only_for_mmi pf[8]; //mtk02126 8 is the max number of packet filters in 27.007 v 7.05 
} l4c_tft_struct_only_for_mmi;
#endif

typedef struct
{
    atci_qos_enum            qos_type;          /*atci_qos_enum*/
    kal_uint8                context_id;
    delay_class_enum         delay_class;       /*delay_class_enum*/
    reliability_class_enum   reliability_class; /*reliability_class_enum*/
    peak_throughput_class    peak_throughput;   /*peak_throughput_class*/
    precedence_class_enum    precedence_class;  /*precedence_class_enum*/
    mean_throughput_enum     mean_throughput;   /*mean_throughput_enum*/
} l4c_qos_struct;

typedef struct
{
    atci_qos_enum            qos_type;          /*atci_qos_enum*/
    kal_uint8                context_id;
    kal_uint8 traffic_class;
    kal_uint8 delivery_order;
    kal_uint8 delivery_of_err_sdu;
    kal_uint8 max_sdu_size;
    kal_uint8 max_bitrate_up_lnk;
    kal_uint8 max_bitrate_down_lnk;
    kal_uint8 residual_bit_err_rate;
    kal_uint8 sdu_err_ratio;
    kal_uint8 transfer_delay;
    kal_uint8 traffic_hndl_priority;
    kal_uint8 guarntd_bit_rate_up_lnk;
    kal_uint8 guarntd_bit_rate_down_lnk;
    kal_uint8 signalling_indication;
    kal_uint8 source_statistics_descriptor;
    kal_uint8 ext_max_bitrate_down_lnk;
    kal_uint8 ext_guarntd_bit_rate_down_lnk;
    kal_uint8 ext_max_bitrate_up_lnk;
    kal_uint8 ext_guarntd_bit_rate_up_lnk;
} l4c_eqos_struct;

//mtk04121
typedef struct
{
    kal_uint8   context_id;
    kal_uint8   qci;
    kal_bool    max_bitrate_present;
    kal_uint8   max_bitrate_up_lnk;
    kal_uint8   max_bitrate_down_lnk;
    kal_uint8   ext_max_bitrate_up_lnk;
    kal_uint8   ext_max_bitrate_down_lnk;
    kal_uint8   ext2_max_bitrate_up_lnk;
    kal_uint8   ext2_max_bitrate_down_lnk;
    kal_bool    guarntd_bit_rate_present;
    kal_uint8   guarntd_bit_rate_up_lnk;
    kal_uint8   guarntd_bit_rate_down_lnk;
    kal_uint8   ext_guarntd_bit_rate_up_lnk;
    kal_uint8   ext_guarntd_bit_rate_down_lnk;
    kal_uint8   ext2_guarntd_bit_rate_up_lnk;
    kal_uint8   ext2_guarntd_bit_rate_down_lnk;
} l4c_eps_qos_struct;

//mtk04121
typedef struct
{
    kal_uint8   qci;
    kal_uint8   unused1;
    kal_uint8   unused2;
    kal_uint8   unused3;
    kal_uint8   max_bitrate_up_lnk;
    kal_uint8   max_bitrate_down_lnk;
    kal_uint8   guarntd_bit_rate_up_lnk;
    kal_uint8   guarntd_bit_rate_down_lnk;
    kal_uint8   ext_max_bitrate_up_lnk;
    kal_uint8   ext_max_bitrate_down_lnk;
    kal_uint8   ext_guarntd_bit_rate_up_lnk;
    kal_uint8   ext_guarntd_bit_rate_down_lnk;
    kal_uint8   ext2_max_bitrate_up_lnk;
    kal_uint8   ext2_max_bitrate_down_lnk;
    kal_uint8   ext2_guarntd_bit_rate_up_lnk;
    kal_uint8   ext2_guarntd_bit_rate_down_lnk;
} tcm_eps_qos_struct;

typedef struct
{
    kal_uint8 authentication_type;
    kal_uint8 user_name[MAX_GPRS_USER_NAME_LEN];
    kal_uint8 password[MAX_GPRS_PASSWORD_LEN];
    kal_uint8 dns[MAX_GPRS_IP_ADDR];
    kal_uint8 sec_dns[MAX_GPRS_IP_ADDR];
    kal_uint8 apn[MAX_GPRS_APN_LEN];
    kal_uint8 apn_length;
   
    //nvram_editor_qos_struct req_qos;
    kal_uint8 dcomp_algo; // Fixed value: SND_NO_DCOMP
    kal_uint8 hcomp_algo; // Fixed value: SND_NO_PCOMP
    kal_uint8 pdp_type; // Fixed value: IPV4_ADDR_TYPE 0x21 for IPv4
    kal_uint8 pdp_addr_len; // Fixed value: NULL_PDP_ADDR_LEN = 0x01, if use fixed IP address, this should be IPV4_ADDR_LEN = 0x04
    kal_uint8 pdp_addr_val[MAX_GPRS_IP_ADDR]; // should be all 0
} l4c_gprs_account_info_struct; //10A_DA_Revise, new gprs account struct, mtk02285

typedef struct
{
   kal_uint8 call_id;
   kal_uint8 call_state;
   kal_uint8 mpty;
   kal_uint8 number[MAX_CC_ADDR_LEN];
} l4c_call_list_entry_struct;

typedef struct
{
   kal_uint8 length;
   l4c_call_list_entry_struct list[L4C_MAX_CALL_LIST_LEN];
} l4c_call_list_struct;

typedef struct
{
   kal_uint8 type;
   kal_uint8 length;
   kal_uint8 number[MAX_CC_ADDR_LEN];
} l4c_number_struct;

typedef struct
{
   kal_uint8 type;
   kal_uint8 length;
   kal_uint8 number[MAX_CC_ADDR_LEN];
} l4c_sub_addr_struct;

typedef struct {
   kal_uint8 bs_code;
   kal_uint8 ss_status;
   kal_uint8 no_reply_timer;
   kal_uint8 subaddress_flag;
   kal_char address[MAX_CC_ADDR_LEN];
   kal_char subaddress[MAX_CC_SUB_ADDR_LEN];
} forwarding_list_struct;

typedef struct {
   kal_uint8 bs_code;
   kal_uint8 ss_status;
} barring_list_struct;

typedef struct {
   kal_uint8 ss_status;
   kal_uint8 subaddress_flag;
   l4_addr_bcd_struct address;
   l4_addr_bcd_struct subaddress;
   kal_uint8 bs_code;
} ccbs_list_struct;

typedef struct
{
    kal_bool cug_flag;
    kal_uint8 clir_flag;
    kal_uint8 call_type;
    csmss_string_op_enum opcode;
    l4c_number_struct addr;
} l4c_ss_string_info_struct;

typedef struct {
    kal_uint8 icon_attr;
    kal_uint8 icon_id;
} sat_icon_struct;

typedef struct {
    kal_uint8 length;
    kal_uint8 procomm[256];
    rsat_config_enum is_wait_for_rsp;
} sat_procomm_struct;

typedef struct {
    kal_uint8 p_class;
    kal_uint8 d_class;
    kal_uint8 r_class;
    kal_uint8 peak_rate;
    kal_uint8 mean_rate;
    kal_uint8 proto_type;
} sat_gprs_bearer_para_struct;

typedef struct {
    kal_uint8 speed;
    kal_uint8 service_name;
    kal_uint8 ce;
} sat_csd_bearer_para_struct;

//agps begin
/* OCTET STRING Ext-GeographicalInformation */
typedef struct L4C_SS_Ext_GeographicalInformation
{
   kal_uint8 numOctets;
   kal_uint8 stringData[20];
}
L4C_SS_Ext_GeographicalInformation;

/* OCTET STRING DecipheringKeys */
typedef struct L4C_SS_DecipheringKeys
{
   kal_uint8 numOctets;
   kal_uint8 stringData[15];
}
L4C_SS_DecipheringKeys;

/* OCTET STRING Add-GeographicalInformation */
typedef struct L4C_SS_Add_GeographicalInformation
{
   kal_uint8 numOctets;
   kal_uint8 stringData[91];
}
L4C_SS_Add_GeographicalInformation;

/* BIT STRING DeferredLocationEventType */
#define   L4C_SS_DeferredLocationEventType_msAvailable   0x00000001

#define   L4C_SS_DeferredLocationEventType_enteringIntoArea   0x00000002

#define   L4C_SS_DeferredLocationEventType_leavingFromArea   0x00000004

#define   L4C_SS_DeferredLocationEventType_beingInsideArea   0x00000008

typedef struct L4C_SS_DeferredLocationEventType
{
   kal_uint8 numBits;
   kal_uint8 stringData[2];
}
L4C_SS_DeferredLocationEventType;

/* OCTET STRING AddressString */
typedef struct L4C_SS_AddressString
{
   kal_uint8 numOctets;
   kal_uint8 stringData[20];
}
L4C_SS_AddressString;

typedef L4C_SS_AddressString L4C_SS_ISDN_AddressString;

typedef struct
{
	kal_uint32		valueLen;
	kal_uint8  	*value;
}L4C_LCS_applib2_UnKnowExtensionItem;

typedef struct
{
	kal_uint32						valueLen;		// Extension Number
	L4C_LCS_applib2_UnKnowExtensionItem		*value;		// Point to the first 
}L4C_LCS_applib2_UnKnowExtensionItemArray;

/* SEQUENCE PrivateExtension */
typedef struct L4C_SS_PrivateExtension
{
   L4C_LCS_applib2_UnKnowExtensionItemArray	UnKnowItem;
}
L4C_SS_PrivateExtension;

/* SEQUENCE OF PrivateExtensionList */
typedef struct L4C_SS_PrivateExtensionList	
{	
   kal_uint8 numElements;	
	
   L4C_SS_PrivateExtension element[10];	
}	
L4C_SS_PrivateExtensionList;

/* SEQUENCE ExtensionContainer */
typedef struct L4C_SS_ExtensionContainer
{
   kal_uint8 validity;

   #define L4C_SS_ExtensionContainer_privateExtensionList_valid 0x02
   #define L4C_SS_ExtensionContainer_pcs_Extensions_valid 0x01

   L4C_SS_PrivateExtensionList privateExtensionList; /* OPTIONAL */
}
L4C_SS_ExtensionContainer;

/* OCTET STRING USSD-DataCodingScheme */
typedef struct L4C_SS_USSD_DataCodingScheme
{
   kal_uint8 numOctets;
   kal_uint8 stringData[1];
}
L4C_SS_USSD_DataCodingScheme;

/* OCTET STRING USSD-String */
typedef struct L4C_SS_USSD_String
{
   kal_uint8 numOctets;
   kal_uint8 stringData[160];
}
L4C_SS_USSD_String;

/* DEFINED NameString */
typedef L4C_SS_USSD_String L4C_SS_NameString;

/* DEFINED RequestorIDString */
typedef L4C_SS_USSD_String L4C_SS_RequestorIDString;

/* SEQUENCE LCSClientName */
typedef struct L4C_SS_LCSClientName
{
   kal_uint8 validity;

   #define L4C_SS_LCSClientName_lcs_FormatIndicator_valid 0x01

   L4C_SS_USSD_DataCodingScheme dataCodingScheme; /* MANDATORY */
   L4C_SS_NameString nameString; /* MANDATORY */

   kal_uint8 lcs_FormatIndicator; /* OPTIONAL */ /* L4C_SS_LCS_FormatIndicator */
}
L4C_SS_LCSClientName;

/* SEQUENCE LCSRequestorID */
typedef struct L4C_SS_LCSRequestorID
{
   kal_uint8 validity;

   #define L4C_SS_LCSRequestorID_lcs_FormatIndicator_valid 0x01

   L4C_SS_USSD_DataCodingScheme dataCodingScheme; /* MANDATORY */
   L4C_SS_RequestorIDString requestorIDString; /* MANDATORY */

   kal_uint8 lcs_FormatIndicator; /* OPTIONAL */ /* L4C_SS_LCS_FormatIndicator */
}
L4C_SS_LCSRequestorID;

/* DEFINED LCSCodewordString */
typedef L4C_SS_USSD_String L4C_SS_LCSCodewordString;

/* SEQUENCE LCSCodeword */
typedef struct L4C_SS_LCSCodeword
{
   L4C_SS_USSD_DataCodingScheme dataCodingScheme; /* MANDATORY */
   L4C_SS_LCSCodewordString lcsCodewordString; /* MANDATORY */
}
L4C_SS_LCSCodeword;

/* INTEGER LCSServiceTypeID */
typedef kal_uint8 L4C_SS_LCSServiceTypeID;

/* INTEGER AgeOfLocationInformation */
typedef kal_uint16 L4C_SS_AgeOfLocationInformation;

/* SEQUENCE LocationNotificationRes */
typedef struct L4C_SS_LocationNotificationRes
{
   kal_uint8 validity;

   #define L4C_SS_LocationNotificationRes_verificationResponse_valid 0x01

   kal_uint8 verificationResponse; /* OPTIONAL */ /* L4C_SS_VerificationResponse */
}
L4C_SS_LocationNotificationRes;

/* OCTET STRING LCS-ReferenceNumber */
typedef struct L4C_SS_LCS_ReferenceNumber
{
   kal_uint8 numOctets;
   kal_uint8 stringData[1];
}
L4C_SS_LCS_ReferenceNumber;

/* OCTET STRING GSN-Address */
typedef struct L4C_SS_GSN_Address
{
   kal_uint8 numOctets;
   kal_uint8 stringData[17];
}
L4C_SS_GSN_Address;

/* SEQUENCE LCS-AreaEventReportArg */
typedef struct L4C_SS_LCS_AreaEventReportArg
{
   kal_uint8 validity;

   #define L4C_SS_LCS_AreaEventReportArg_r_gmlc_address_valid 0x01

   L4C_SS_LCS_ReferenceNumber referenceNumber; /* MANDATORY */
   L4C_SS_GSN_Address h_gmlc_address; /* MANDATORY */
   L4C_SS_GSN_Address r_gmlc_address; /* OPTIONAL */
}
L4C_SS_LCS_AreaEventReportArg;

typedef struct L4C_SS_LCS_AreaEventCancellationArg
{
   L4C_SS_LCS_ReferenceNumber referenceNumber; /* MANDATORY */
   L4C_SS_GSN_Address h_gmlc_address; /* MANDATORY */
}
L4C_SS_LCS_AreaEventCancellationArg;

/* OCTET STRING AreaIdentification */
typedef struct L4C_SS_AreaIdentification
{
   kal_uint8 numOctets;
   kal_uint8 stringData[7];
}
L4C_SS_AreaIdentification;

/* SEQUENCE Area */
typedef struct L4C_SS_Area
{
   kal_uint8 areaType; /* MANDATORY */ /* L4C_SS_AreaType */
   L4C_SS_AreaIdentification areaIdentification; /* MANDATORY */
}
L4C_SS_Area;

/* SEQUENCE OF AreaList */
typedef struct L4C_SS_AreaList	
{	
   kal_uint8 numElements;
	
   L4C_SS_Area element[10];	
}	
L4C_SS_AreaList;

/* SEQUENCE AreaDefinition */
typedef struct L4C_SS_AreaDefinition
{
   L4C_SS_AreaList areaList; /* MANDATORY */
}
L4C_SS_AreaDefinition;

/* INTEGER IntervalTime */
typedef kal_uint16 L4C_SS_IntervalTime;

/* SEQUENCE AreaEventInfo */
typedef struct L4C_SS_AreaEventInfo
{
   kal_uint8 validity;

   #define L4C_SS_AreaEventInfo_occurrenceInfo_valid 0x02
   #define L4C_SS_AreaEventInfo_intervalTime_valid 0x01

   L4C_SS_AreaDefinition areaDefinition; /* MANDATORY */
   kal_uint8 occurrenceInfo; /* OPTIONAL */ /* L4C_SS_OccurrenceInfo */
   L4C_SS_IntervalTime intervalTime; /* OPTIONAL */
}
L4C_SS_AreaEventInfo;

/* SEQUENCE LCS-AreaEventRequestArg */
typedef struct L4C_SS_LCS_AreaEventRequestArg
{
   kal_uint8 validity;

   #define L4C_SS_LCS_AreaEventRequestArg_r_gmlc_address_valid 0x01

   L4C_SS_LCS_ReferenceNumber referenceNumber; /* MANDATORY */
   L4C_SS_GSN_Address h_gmlc_address; /* MANDATORY */
   L4C_SS_GSN_Address r_gmlc_address; /* OPTIONAL */
   L4C_SS_DeferredLocationEventType deferredLocationEventType; /* MANDATORY */
   L4C_SS_AreaEventInfo areaEventInfo; /* MANDATORY */
}
L4C_SS_LCS_AreaEventRequestArg;

/* SEQUENCE ResponseTime */
typedef struct L4C_SS_ResponseTime
{
   kal_uint8 responseTimeCategory; /* MANDATORY */ /* L4C_SS_ResponseTimeCategory */
}
L4C_SS_ResponseTime;

/* OCTET STRING Vertical-Accuracy */
typedef struct L4C_SS_Vertical_Accuracy
{
   kal_uint8 numOctets;
   kal_uint8 stringData[1];
}
L4C_SS_Vertical_Accuracy;

/* OCTET STRING Horizontal-Accuracy */
typedef struct L4C_SS_Horizontal_Accuracy
{
   kal_uint8 numOctets;
   kal_uint8 stringData[1];
}
L4C_SS_Horizontal_Accuracy;

/* SEQUENCE LCS-QoS */
typedef struct L4C_SS_LCS_QoS
{
   kal_uint8 validity;

   #define L4C_SS_LCS_QoS_horizontal_accuracy_valid 0x10
   #define L4C_SS_LCS_QoS_verticalCoordinateRequest_valid 0x08
   #define L4C_SS_LCS_QoS_vertical_accuracy_valid 0x04
   #define L4C_SS_LCS_QoS_responseTime_valid 0x02
   #define L4C_SS_LCS_QoS_extensionContainer_valid 0x01

   L4C_SS_Horizontal_Accuracy horizontal_accuracy; /* OPTIONAL */
   kal_int8 verticalCoordinateRequest; /* OPTIONAL */
   L4C_SS_Vertical_Accuracy vertical_accuracy; /* OPTIONAL */
   L4C_SS_ResponseTime responseTime; /* OPTIONAL */
   L4C_SS_ExtensionContainer extensionContainer; /* OPTIONAL */
}
L4C_SS_LCS_QoS;

/* BIT STRING SupportedGADShapes */
#define   L4C_SS_SupportedGADShapes_ellipsoidPoint   0x00000001

#define   L4C_SS_SupportedGADShapes_ellipsoidPointWithUncertaintyCircle   0x00000002

#define   L4C_SS_SupportedGADShapes_ellipsoidPointWithUncertaintyEllipse   0x00000004

#define   L4C_SS_SupportedGADShapes_polygon   0x00000008

#define   L4C_SS_SupportedGADShapes_ellipsoidPointWithAltitude   0x00000010

#define   L4C_SS_SupportedGADShapes_ellipsoidPointWithAltitudeAndUncertaintyElipsoid   0x00000020

#define   L4C_SS_SupportedGADShapes_ellipsoidArc   0x00000040

typedef struct L4C_SS_SupportedGADShapes
{
   kal_uint8 numBits;
   kal_uint8 stringData[2];
}
L4C_SS_SupportedGADShapes;

/* OCTET STRING GPSAssistanceData */
typedef struct L4C_SS_GPSAssistanceData
{
   kal_uint8 numOctets;
   kal_uint8 stringData[38];
}
L4C_SS_GPSAssistanceData;

/* SEQUENCE LCSClientExternalID */
typedef struct L4C_SS_LCSClientExternalID
{
   kal_uint8 validity;

   #define L4C_SS_LCSClientExternalID_externalAddress_valid 0x02
   #define L4C_SS_LCSClientExternalID_extensionContainer_valid 0x01

   L4C_SS_ISDN_AddressString externalAddress; /* OPTIONAL */
   L4C_SS_ExtensionContainer extensionContainer; /* OPTIONAL */
}
L4C_SS_LCSClientExternalID;

/* SEQUENCE LocationType */
typedef struct L4C_SS_LocationType
{
   kal_uint8 validity;

   #define L4C_SS_LocationType_deferredLocationEventType_valid 0x01

   kal_uint8 locationEstimateType; /* MANDATORY */ /* L4C_SS_LocationEstimateType */

   L4C_SS_DeferredLocationEventType deferredLocationEventType; /* OPTIONAL */
}
L4C_SS_LocationType;

/* SEQUENCE LCS-MOLRArg */
typedef struct L4C_SS_LCS_MOLRArg
{
   kal_uint16 validity;

   #define L4C_SS_LCS_MOLRArg_locationMethod_valid 0x0200
   #define L4C_SS_LCS_MOLRArg_lcs_QoS_valid 0x0100
   #define L4C_SS_LCS_MOLRArg_lcsClientExternalID_valid 0x0080
   #define L4C_SS_LCS_MOLRArg_mlc_Number_valid 0x0040
   #define L4C_SS_LCS_MOLRArg_gpsAssistanceData_valid 0x0020
   #define L4C_SS_LCS_MOLRArg_supportedGADShapes_valid 0x0010
   #define L4C_SS_LCS_MOLRArg_lcsServiceTypeID_valid 0x0008
   #define L4C_SS_LCS_MOLRArg_ageOfLocationInfo_valid 0x0004
   #define L4C_SS_LCS_MOLRArg_locationType_valid 0x0002
   #define L4C_SS_LCS_MOLRArg_pseudonymIndicator_valid 0x0001

   kal_uint8 molr_Type; /* MANDATORY */ /* L4C_SS_MOLR_Type */
   kal_uint8 locationMethod; /* OPTIONAL */ /* L4C_SS_LocationMethod */
   L4C_SS_LCS_QoS lcs_QoS; /* OPTIONAL */
   L4C_SS_LCSClientExternalID lcsClientExternalID; /* OPTIONAL */
   L4C_SS_ISDN_AddressString mlc_Number; /* OPTIONAL */
   L4C_SS_GPSAssistanceData gpsAssistanceData; /* OPTIONAL */

   L4C_SS_SupportedGADShapes supportedGADShapes; /* OPTIONAL */

   L4C_SS_LCSServiceTypeID lcsServiceTypeID; /* OPTIONAL */
   L4C_SS_AgeOfLocationInformation ageOfLocationInfo; /* OPTIONAL */
   L4C_SS_LocationType locationType; /* OPTIONAL */
   kal_uint8 pseudonymIndicator; /* OPTIONAL */
}
L4C_SS_LCS_MOLRArg;

/* SEQUENCE LocationNotificationArg */
typedef struct L4C_SS_LocationNotificationArg
{
   kal_uint8 validity;

   #define L4C_SS_LocationNotificationArg_lcsClientExternalID_valid 0x10
   #define L4C_SS_LocationNotificationArg_lcsClientName_valid 0x08
   #define L4C_SS_LocationNotificationArg_lcsRequestorID_valid 0x04
   #define L4C_SS_LocationNotificationArg_lcsCodeword_valid 0x02
   #define L4C_SS_LocationNotificationArg_lcsServiceTypeID_valid 0x01

   kal_uint8 notificationType; /* MANDATORY */ /* L4C_SS_NotificationToMSUser */
   L4C_SS_LocationType locationType; /* MANDATORY */
   L4C_SS_LCSClientExternalID lcsClientExternalID; /* OPTIONAL */
   L4C_SS_LCSClientName lcsClientName; /* OPTIONAL */

   L4C_SS_LCSRequestorID lcsRequestorID; /* OPTIONAL */
   L4C_SS_LCSCodeword lcsCodeword; /* OPTIONAL */
   L4C_SS_LCSServiceTypeID lcsServiceTypeID; /* OPTIONAL */
}
L4C_SS_LocationNotificationArg;

/* SEQUENCE LCS-MOLRRes */
typedef struct L4C_SS_LCS_MOLRRes
{
   kal_uint8 validity;

   #define L4C_SS_LCS_MOLRRes_locationEstimate_valid 0x04
   #define L4C_SS_LCS_MOLRRes_decipheringKeys_valid 0x02
   #define L4C_SS_LCS_MOLRRes_add_LocationEstimate_valid 0x01

   L4C_SS_Ext_GeographicalInformation locationEstimate; /* OPTIONAL */
   L4C_SS_DecipheringKeys decipheringKeys; /* OPTIONAL */

   L4C_SS_Add_GeographicalInformation add_LocationEstimate; /* OPTIONAL */
}
L4C_SS_LCS_MOLRRes;
//agps end

//eq begin
typedef struct {
		
    kal_uint32 PWM1_freq_Level_Info[5];
	kal_uint32 PWM1_duty_Level_Info[5]; 
	kal_uint32 PWM2_freq_Level_Info[5]; 
	kal_uint32 PWM2_duty_Level_Info[5];
	kal_uint32 PWM3_freq_Level_Info[5]; 
	kal_uint32 PWM3_duty_Level_Info[5]; 

	kal_uint8   MainLCD_Contrast_Level_Info[15];
	kal_uint8   MainLCD_Bias_Level_Info[5];
	kal_uint8   MainLCD_Linerate_Level_Info[5];
	kal_uint8   MainLCD_Temp_Level_Info[5];
   
	kal_uint8   SubLCD_Contrast_Level_Info[15];
	kal_uint8   SubLCD_Bias_Level_Info[5];
	kal_uint8   SubLCD_Linerate_Level_Info[5];
	kal_uint8   SubLCD_Temp_Level_Info[5];

	kal_uint32   Battery_Level_Info[10];

#ifdef __MULTI_LEVEL_BACKLIGHT_SUPPORT__
        kal_uint32 bl_PWM_freq_Level_Info[PWM_MAX_BACKLIGHT_LEVEL]; 
	kal_uint32 bl_PWM_duty_Level_Info[PWM_MAX_BACKLIGHT_LEVEL]; 
#endif
}
l4c_hw_profile_struct;

typedef struct {
    kal_uint8 rtc_sec;
    kal_uint8 rtc_min;
    kal_uint8 rtc_hour;
    kal_uint8 rtc_day;
    kal_uint8 rtc_mon;
    kal_uint8 rtc_wday;
    kal_uint8 rtc_year;
} rtc_format_struct;

typedef struct {
    kal_uint8 alarm_format;
    kal_uint8 alarm_index;
    kal_uint8 type;
    kal_uint8 text[30];
    kal_uint8 recurr;
    rtc_format_struct data_time;
} rtc_alarm_info_struct;

typedef struct mmi_at_alarm_info_struct
{
   kal_uint8 alarm_index;
   kal_uint8 recurr;
   rtc_format_struct date_time;
} mmi_at_alarm_info_struct;

typedef enum{
    VT_EM_REVERSE_INVALID = -1,
    VT_EM_REVERSE_DATA = 0,
    VT_EM_REVERSE_NULL
}vt_em_reverse_channel_data_type;

typedef enum{
    VT_EM_AL_INVALID = -1,
    VT_EM_AL2_WITH_SEQUENCE_NUMBER = 0,
    VT_EM_AL2_WITHOUT_SEQUENCE_NUMBER,
    VT_EM_AL3_CONTROL_FIELD_SIZE_0,
    VT_EM_AL3_CONTROL_FIELD_SIZE_1,
    VT_EM_AL3_CONTROL_FIELD_SIZE_2
}vt_em_al_choice;

typedef enum{
    VT_EM_MUX_LEVEL_INVALID = -1,
    VT_EM_MUX_LEVEL_0 = 0,
    VT_EM_MUX_LEVEL_1,
    VT_EM_MUX_LEVEL_1_WITH_DOUBLE_FLAG,
    VT_EM_MUX_LEVEL_2,
    VT_EM_MUX_LEVEL_2_WITH_OPTIONAL_HEADER,
    VT_EM_MUX_LEVEL_3,
    VT_EM_MUX_LEVEL_3_WITH_OPTIONAL_HEADER
}vt_em_mux_level_choice;

typedef enum{
    VT_EM_WNSRP_INVALID = -1,
    VT_EM_WNSRP_OFF = 0,
    VT_EM_WNSRP_ON
}vt_em_wnsrp_choice;

typedef enum{
    VT_EM_CODEC_INVALID = -1,
    VT_EM_CODEC_MPEG4_H263 = 0,
    VT_EM_CODEC_H263_MPEG4
}vt_em_video_codec_preference_choice;

typedef enum{
    VT_EM_AUTO_DROP_INVALID = -1,
    VT_EM_DISABLE_AUTO_DROP_IF_CHANNEL_FAIL = 0,
    VT_EM_ENABLE_AUTO_DROP_IF_CHANNEL_FAIL
}vt_em_auto_drop_if_channel_fail_choice;

typedef enum{
    VT_EM_TERMINAL_TYPE_INVALID = -1,
    VT_EM_TERMINAL_TYPE_NORMAL = 0,
    VT_EM_TERMINAL_TYPE_MASTER,
    VT_EM_TERMINAL_TYPE_SLAVE
}vt_em_terminal_type_choice;

typedef struct{
    vt_em_mux_level_choice mux_level_choice;
    vt_em_wnsrp_choice  wnsrp_choice;
    vt_em_al_choice audio_al_choice;
    vt_em_al_choice video_al_choice;
    vt_em_reverse_channel_data_type video_reverse_data_type_choice;
    vt_em_video_codec_preference_choice video_codec_preference_choice;
    vt_em_auto_drop_if_channel_fail_choice auto_drop_if_channel_fail_choice;
    vt_em_terminal_type_choice  terminal_type_choice;
    kal_int32 timer_T101; //default =  -1  (if its value equals -1, no change should be made) 
    kal_int32 timer_T109; //default =  -1  (if its value equals -1, no change should be made) 
    kal_int32 timer_T401; //default =  -1  (if its value equals -1, no change should be made) 
    kal_int32   user_specified_1; //default =  -1  (if its value equals -1, no change should be made) 
    kal_int32   user_specified_2; //default =  -1  (if its value equals -1, no change should be made) 
    kal_uint8   user_specified_3[64]; //get input length by strlen() (end by EOF)
}vt_em_config_struct;

typedef struct
{			
	kal_uint8	mcc[3];	//MCC
	kal_uint8	mnc[3];	//MNC
	kal_uint8	lac[2];	//LAC
	kal_uint16	cell_id;	 //cell ID
	kal_uint8	nc_info_index; // index in rlc array to acquire the corresponding arfcn, bsic, rxlevel...
    kal_uint8       rac;//RAC EM_RAC
#ifdef __PS_SERVICE__
    /*091014 WISDOM_EM Michael Shuang NMO*/
    kal_uint8 nmo;
#endif
    kal_uint8 supported_Band;
} rr_em_lai_info_struct;

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct
{
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    kal_uint8 unused;
}pmu6223_config_param_struct;

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

typedef struct
{
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    kal_uint8 unused;
}pmu6238_config_param_struct;

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
#endif
typedef struct
{
    //pmu6326_read_reg_struct read_reg;
    //pmu6326_write_reg_struct write_reg;
    kal_uint8 unused;
}pmu6326_config_param_struct;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct
{
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    kal_uint8 unused;
}pmic_config_param_struct;

typedef struct
{
    kal_uint8	ref_count; 
    kal_uint16	msg_len;
    
    kal_uint16 arfcn;    /* input */
    kal_int16 afc;       /* input */
    kal_uint8 band;      /* input */
    kal_int8   tsc;      /* input */
    kal_int8   pcl;      /* input */
    kal_uint8   pattern; /* input */
}rf_test_gsm_tx_test_struct, l4cl1_em_rf_test_gsm_tx_test_req_struct;


typedef struct
{
    kal_uint8	ref_count; 
    kal_uint16	msg_len;
    
    kal_int16 arfcn;      /* input */
    kal_int16 gain;       /* input */
    kal_uint8 band;       /* input */
    kal_uint8  pattern;   /* input */
}rf_test_gsm_rx_test_struct, l4cl1_em_rf_test_gsm_rx_test_req_struct;


typedef struct
{
    kal_uint8	ref_count; 
    kal_uint16	msg_len;

    kal_uint8 band;                /* input */   
    kal_int16 arfcn_in;            /* input */
    kal_int16 arfcn_out[20];       /* output */
    kal_int16 power[20];           /* output */    
}rf_test_gsm_power_scan_struct, 
l4cl1_em_rf_test_gsm_power_scan_req_struct, 
l4cl1_em_rf_test_gsm_power_scan_cnf_struct;


typedef struct
{
    rf_test_gsm_tx_test_struct gsm_tx_test;
    rf_test_gsm_rx_test_struct gsm_rx_test;   
    rf_test_gsm_power_scan_struct gsm_power_scan;    
}rf_test_gsm_param_struct;

typedef struct
{
    kal_uint8 mono_enable;    /* input */
}fm_radio_mono_struct;
  
typedef struct
{
    kal_uint8 stereo_enable;  /* input */
    kal_uint8 sblend_onoff;    /* input */
}fm_radio_stereo_struct;

typedef struct
{
    kal_uint8 level;                  /* input */   
}fm_radio_rssi_struct;

typedef struct
{
    kal_uint8 item_value;          /* input */   
}fm_radio_if_count_delta_struct;

typedef struct
{
    fm_radio_mono_struct fm_radio_mono;
    fm_radio_stereo_struct fm_radio_stereo;   
    fm_radio_rssi_struct fm_radio_rssi;    
    fm_radio_if_count_delta_struct fm_radio_if;
}fm_radio_config_param_struct;

#if defined(__WIFI_SUPPORT__)
typedef struct
{
    kal_uint8 ich;    /* output */
    kal_uint8 qch;   /* output */
}rf_test_wifi_tx_get_dac_offset_struct;

typedef struct
{
    kal_uint8 contry_code[2];   /* input */
    kal_uint32 ch_freq;               /* input */
    kal_uint8 tx_rate;  /* input */    
    kal_uint8 tx_ant;                /* input */
    kal_uint8 gain;                   /* input */
    wndrv_test_bandwidth_enum txBw;
    wndrv_test_guard_intval_enum txGI;
    wndrv_test_mode_sel_enum txMode;
}rf_test_wifi_tx_common_struct;

typedef struct
{
    kal_uint8 contry_code[2];      /* input */
    kal_uint32 ch_freq;                 /* input */
    kal_uint8 tx_rate;  /* input */
    kal_uint8 tx_ant;                     /* input */
    kal_uint8 gain;                        /* input */
    kal_uint32 pkt_count;             /* input */
    kal_uint32 pkt_interval;         /* input */
    kal_uint32 pkt_length;             /* input */
    kal_uint8 tx_pattern;               /* input */
    kal_bool short_peramble;       /* input */
    kal_uint8 mac_header[24];     /* input */
    wndrv_test_bandwidth_enum txBw;                       /* input */
    wndrv_test_guard_intval_enum txGI;                         /* input */
    wndrv_test_mode_sel_enum txMode;                 /* input */
}rf_test_wifi_tx_cont_pkt_struct;

typedef struct
{
    kal_uint32 ch_freq;                     /* input */
    kal_uint32 pau_total;                  /* output -- pau_rx_ptk_count */
    kal_uint32 pau_err;                    /* output -- pau_crc_err_count */
    kal_uint32 pau_ccca;                  /* output -- pau_cca_count */
    kal_uint32 pau_fifo_full;            /* output -- pau_rx_fifo_full_count */
    kal_uint32 int_ok;                      /* int_rx_ok_num */
    kal_uint32 int_err;                     /* int_crc_err_num */
    kal_uint32 rssi_mean;                /* int_rssi_mean */
    kal_uint32 rssi_max;                  /* int_rssi_max */
    kal_uint32 rssi_min;                    /* int_rssi_min */
    kal_uint32 rssi_variance;            /* int_rssi_variance */
    kal_uint32 int_long_preamble;    /* int_long_preamble_num */
    kal_uint32 int_short_preamble;   /* int_short_preamble_num */
    wndrv_test_bandwidth_enum   rxBw;                         /* input */ 
}rf_test_wifi_rx_cont_pkt_struct;

typedef struct
{
    kal_uint8 pwr_mgt;     /* input */
}rf_test_wifi_power_save_struct;

typedef struct
{
    kal_uint32 mcr_index;
    kal_uint32 mcr32;
}rf_test_wifi_reg_mcr32_write_struct;

typedef struct
{
    kal_uint32 mcr_index;  /* input */
    kal_uint32 mcr32;         /* output */
}rf_test_wifi_reg_mcr32_read_struct;

typedef struct
{
    kal_uint32 mcr_index;  /* input */
    kal_uint16 mcr16;         /* input */
}rf_test_wifi_reg_mcr16_write_struct;

typedef struct
{
    kal_uint32 mcr_index;      /* intput */
    kal_uint16 mcr16;             /* output */
}rf_test_wifi_reg_mcr16_read_struct;

typedef struct
{
    kal_uint32 bbcr_index;   /* intput */
    kal_uint8 bbcr;              /* intput */
}rf_test_wifi_reg_bbcr_write_struct;

typedef struct
{
    kal_uint32 bbcr_index;    /* intput */
    kal_uint8 bbcr;               /* output */
}rf_test_wifi_reg_bbcr_read_struct;

typedef struct
{
    kal_uint32 eeprom_index;   /* intput */
    kal_uint16 eeprom;              /* intput */
}rf_test_wifi_reg_eeprom_write_struct;

typedef struct
{
    kal_uint32 eeprom_index;      /* intput */
    kal_uint16 eeprom;                 /* output */
}rf_test_wifi_reg_eeprom_read_struct;

typedef struct
{
    kal_uint32 efuse_index; /* intput */
    kal_uint32 efuse; /* intput */
}rf_test_wifi_reg_efuse_write_struct;

typedef struct
{
    kal_uint32 efuse_index; /* intput */
    kal_uint32 efuse; /* intput */
}rf_test_wifi_reg_efuse_read_struct;

typedef struct
{
    rf_test_wifi_tx_get_dac_offset_struct wifi_get_dac;
    rf_test_wifi_tx_common_struct wifi_tx_common;
    rf_test_wifi_tx_cont_pkt_struct wifi_tx_cont_pkt;
    rf_test_wifi_rx_cont_pkt_struct wifi_rx_cont_pkt;
    rf_test_wifi_power_save_struct wifi_power_save;
    rf_test_wifi_reg_mcr32_write_struct wifi_mcr32_write;
    rf_test_wifi_reg_mcr32_read_struct wifi_mcr32_read;
    rf_test_wifi_reg_mcr16_write_struct wifi_mcr16_write;
    rf_test_wifi_reg_mcr16_read_struct wifi_mcr16_read;
    rf_test_wifi_reg_bbcr_write_struct wifi_bbcr_write;
    rf_test_wifi_reg_bbcr_read_struct wifi_bbcr_read;
    rf_test_wifi_reg_eeprom_write_struct wifi_eeprom_write;
    rf_test_wifi_reg_eeprom_read_struct wifi_eeprom_read;
    rf_test_wifi_reg_efuse_write_struct wifi_efuse_write;
    rf_test_wifi_reg_efuse_read_struct  wifi_efuse_read;
}rf_test_wifi_param_struct;
#endif

//eq end

typedef struct 
{
    kal_uint8 addr_length;
    kal_uint8 addr_bcd[11];
}l4c_sms_addr_struct;

typedef struct 
{
	l4c_sms_addr_struct          sca;
	kal_uint8	tpdu[176];
	kal_uint8 pdu_len;
	kal_uint8 tpdu_len;
}l4c_usm_cmgw_struct;

typedef struct 
{
	kal_uint8 mode;
	kal_uint8	mt;
	kal_uint8 bm;
	kal_uint8 ds;
	kal_uint8 bfr;
}l4c_usm_cnmi_struct;

typedef struct 
{
	kal_uint16	reply_index;
	kal_uint16	data_len;
	kal_uint8		length;
	kal_uint8		pdu[176];
}l4c_usm_cmss_struct;

typedef struct {
   l4_name_struct name;
   l4c_number_struct number_info;
} l4c_sms_mailbox_info_struct;

typedef struct {
    kal_uint8  line_no; /* Number of Line*/
    kal_uint8  msp_no;
    kal_uint8  waiting_num;
    kal_uint8  ind_type;
    kal_bool   is_show_num;
    kal_bool   is_clear;
    kal_bool   is_from_storage;
} l4csmsal_msg_waiting_ind_ext_struct;

typedef struct {
   kal_uint16 mid[40];      // = [SMSAL_MMI_CBMI_MAX_ENTRY]
   kal_uint16 dcs[30];      // = [SMSAL_CB_MAX_ENTRY]
   kal_uint16 mir[60];      // = [SMSAL_CB_MAX_ENTRY*2]
   kal_uint8 mid_mask[40];  // = [SMSAL_MMI_CBMI_MAX_ENTRY]
   kal_uint8 mir_mask[30];  // = [SMSAL_CB_MAX_ENTRY]
   kal_uint8 dcs_mask[30];  // = [SMSAL_CB_MAX_ENTRY]
   kal_uint8 para_ind; /* used in set_cb_mode_req only */

   kal_bool is_all_language_on;

   /* used in get_cb_mode_cnf */
   kal_bool     is_cb_ready;
   kal_bool     is_sim_change;

   l4c_cb_set_type_enum    set_type;
} l4c_cb_info_struct;

typedef struct {
    kal_uint16 ref; /* concat. message reference*/
    kal_uint8 total_seg; /* total segments*/
    kal_uint8 seg; /* indicate which segment*/
} smsal_concat_struct;

typedef struct {
    kal_uint8 mem1; /* Storage type for Memory1*/
    kal_uint8 mem2; /* Storage type for Memory2*/
    kal_uint8 mem3; /* Storage type for Memory3*/
    kal_uint16 used1;
    kal_uint16 used2;
    kal_uint16 used3;
    kal_uint16 total1;
    kal_uint16 total2;
    kal_uint16 total3;
} smsal_prefer_storage_struct;

/* Message Waiting Indication Status */
typedef struct
{
#ifdef __REL6__
    kal_uint8 mbi_id[5]; //5 = NUM_OF_MSG_WAITING_TYPE
#else
   kal_uint8 mbi_id[4]; //4 = NUM_OF_MSG_WAITING_TYPE
#endif
} smsal_mbi_struct;

typedef struct {
    kal_uint8  mti; /* smsal_mti_enum */
    kal_uint8  status; /* Status of message*/
    kal_uint8  storage_type;
    kal_uint16 index; /* Index of message*/
} smsal_inbox_struct;

typedef struct {
    kal_uint16 msg_count; /* Message Count*/
    smsal_inbox_struct inbox_list[40];
} smsal_inbox_list_struct;

typedef struct {
    kal_uint8  mti; /* smsal_mti_enum */
    kal_uint8  status; /* Status of message*/
    kal_uint8  storage_type;
    kal_uint16 index; /* Index of message*/
} smsal_outbox_struct;

typedef struct {
    kal_uint16 msg_count; /* Message Count*/
    smsal_outbox_struct outbox_list[40];
} smsal_outbox_list_struct;

// Enhanced Voice Mail Information
typedef struct
{
    kal_uint16  id;

    kal_uint8   msg_len_insec;
    kal_uint8   msg_retention_day;  // max 31

    kal_uint8   priority;

    kal_uint8   msg_ext_flg;

    l4_addr_bcd_struct   calling_line_addr;

    kal_uint8   msg_ext_len;
    kal_uint8   *msg_ext_data;
}smsal_evmi_msg_struct;

typedef struct {
    kal_uint8 addr_length;
    kal_uint8 addr_bcd[11];
} sms_addr_struct;

typedef struct {
   kal_uint8 storage;
   kal_uint8 type;
   kal_uint8 num_index; 
   kal_uint8 aas_id;
   kal_uint16 index;
   kal_uint16 record_index;
   l4c_number_struct tel;
   l4_name_struct alpha_id;
} l4c_phb_entry_struct;

typedef struct {
#if defined(__VOIP__) || defined(__VIDEO_CALL_SUPPORT__)
   kal_uint8 address_type;
   union
   {
      l4c_number_struct tel;
      kal_uint8 uri[VOIP_URI_LEN];
   } address;
#else
   l4c_number_struct tel;
#endif /* defined(__VOIP__) || defined(__VIDEO_CALL_SUPPORT__) */
   l4_name_struct alpha_id;
   rtc_format_struct time;
   kal_uint8 count;
   kal_uint8 call_status;
   kal_int32 call_duration;
} l4c_phb_ln_entry_struct;

typedef struct { 
    kal_uint16 record_size;   /* size of record in storage */
    kal_uint16 record_num;    /* rec number */
    kal_uint8  alpha_length;  /* alpha length */
    kal_uint8 occurrence;
    kal_bool is_support;      /* to indicate the EF is supported or not */
} l4c_phb_desc_struct;

typedef l4_name_struct phb_sne_struct;
typedef l4_name_struct phb_aas_struct;
typedef l4_name_struct phb_gas_struct;

typedef struct {
    kal_uint8 email_length;
    kal_uint16 record_index; /* Record index in physical storage*/
    kal_uint16 adn_record_index; /* adn record index */
    kal_uint8 email_address[PHB_MAX_EMAIL_LENGTH]; /* email address */
} phb_email_struct;

typedef struct
{
    kal_uint8 gas_id[PHB_MAX_ASSOCIATE_GRP];
} phb_grp_struct;

typedef struct
{
    kal_uint8 ctrl_info;
    kal_uint8 hidden_info;
} phb_pbc_struct;

typedef union {
    phb_sne_struct sne;
    phb_aas_struct aas;
    phb_gas_struct gas;
    phb_grp_struct grp;
    phb_email_struct email;
    phb_pbc_struct pbc;
} l4c_phb_usim_field;

typedef struct {
    l4c_phb_usim_field field;
} l4c_phb_usim_entry;

typedef struct {
   kal_uint8 storage;
   kal_uint8 type;
   kal_uint16 index;
   kal_uint16 record_index;
   l4_addr_bcd_struct tel;
   l4_name_struct alpha_id;
} l4c_phb_bcd_entry_struct;


typedef struct
{
	kal_uint16 num_of_entry;
	l4c_phb_bcd_entry_struct	phb_entry[1000/NVRAM_PHB_SIZE];
} l4c_phb_entries_struct;

/* for AT/MMI */
typedef struct {
   kal_uint8   plmn_id[7];
   kal_uint8   status; /*l4c_cops_status_enum*/
} l4c_plmn_info_struct;

typedef struct {
   kal_uint8   plmn_id[7];
   kal_uint8   status; /*l4c_cops_status_enum*/
   kal_uint8 rat;
   kal_uint8 lac[2];
} l4c_rat_plmn_info_struct;

typedef struct l4c_nw_time_zone_time_struct
{
	kal_uint8 year;
	kal_uint8 month;
	kal_uint8 day;
	kal_uint8 hour;
	kal_uint8 min;
	kal_uint8 sec;
	kal_uint8 time_zone;
} l4c_nw_time_zone_time_struct;

//mtk01616_080301: NOTE! this structure should sync with rac_ecc_number_struct
typedef struct l4c_rac_ecc_number_struct
{
	kal_uint8          category;
	l4_addr_bcd_struct	tel_number;
} l4c_rac_ecc_number_struct;

//mtk02374
typedef struct {
    kal_uint8 chv1_count;
    kal_uint8 chv2_count;
    kal_uint8 ubchv1_count;
    kal_uint8 ubchv2_count;
    kal_uint8 is_chv1_enabled;
    kal_uint8 is_chv1_verified;
    kal_uint8 is_chv2_enabled;
    kal_uint8 is_chv2_verified;
    kal_uint8 chv_key_ref[2];
} sim_chv_info_struct;

typedef struct {
    kal_uint8 chv1_status;
    kal_uint8 chv2_status;
    kal_uint8 ubchv1_status;
    kal_uint8 ubchv2_status;
} sim_chv_status_struct;

typedef struct {
    kal_uint8 ecc[3];
    kal_uint8 esc; // emergency service category //
    kal_uint8 name_length;
    kal_uint8 name_dcs;
    kal_uint8 name[MAX_SIM_NAME_LEN]; 
} sim_ecc_entry_struct;

typedef struct {
   kal_uint8 alpha_id_dcs;
   kal_uint8 alpha_id_size;
   kal_uint8 alpha_id[32];
   kal_uint8 ton_npi;
   kal_uint8 digit_size;
   kal_uint8 digit[41];
} l4csmu_addr_struct;

typedef struct {
   kal_uint8 alpha_id_size;
   kal_uint8 alpha_id[21];
   kal_uint8 ton_npi;
   kal_uint8 digit_size;
   kal_uint8 digit[4];//[41];
   kal_uint8 index_level;
   kal_bool network_specific;
   kal_bool premium_rate;
} l4csmu_info_num_struct;

typedef struct {
    kal_uint8   rand[16];
    kal_bool    is_auth_present;
    kal_uint8   auth[16];
    sim_interface_enum   sim_id;
} smu_supc_sim_authenticate_request_struct;

typedef struct {
    kal_uint16 result;
    kal_uint8   kc[8];
    kal_uint8   sres[4];
    kal_uint8   ck[16];
    kal_uint8   ik[16];
    kal_uint8   res[16];
    kal_uint8   res_len;
    kal_uint8   auts[16];
    kal_uint8   auts_len;
} smu_supc_sim_authenticate_response_struct;

typedef struct {
  kal_uint8 ref_count;
  kal_uint16 msg_len;
   kal_uint8 cmd_detail[5];
   kal_bool is_icon_available;
   sat_icon_struct icon_info;
  kal_uint8 bearer_type;
} l4csmu_sat_open_channel_ind_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 cmd_detail[5];
  kal_uint8 state;
  kal_bool is_icon_available;
  sat_icon_struct icon_info;
} l4csmu_sat_close_channel_ind_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 cmd_detail[5];
  kal_uint8 state;
   kal_bool is_icon_available;
   sat_icon_struct icon_info;
} l4csmu_sat_send_data_ind_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 cmd_detail[5];
  kal_uint8 state;
  kal_bool is_icon_available;
  sat_icon_struct icon_info;
} l4csmu_sat_recv_data_ind_struct;

typedef struct {
    kal_uint8 hnb_name_length;
    kal_uint8 hnb_name[MAX_HNB_NAME_LEN];
    csg_type_enum csg_type;
    kal_uint32 csg_id;
} csg_info_struct;

typedef struct {
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint8   gsm_tx_pwr_red;
    kal_uint8   umts_tx_pwr_red;
} l4c_max_tx_pwr_red_req_struct;

typedef struct {
    pdp_addr_type_enum ip_addr_type;
    kal_uint8 ipv4[4];
    kal_uint8 ipv6[16];
} ip_addr_struct;

typedef struct 
{
    kal_uint16                  earfcn;
    kal_uint8                   bandwidth;
} interrat_lte_cell_info_struct;

typedef struct {
    kal_bool  is_dnsv4_present ;
    kal_uint8 dnsv4[IPV4_ADDR_LEN] ;
} ipv4_dns_struct ;

typedef struct {
    kal_bool  is_dnsv6_present ;
    kal_uint8 dnsv6[IPV6_ADDR_LEN] ;
} ipv6_dns_struct ;

#define NUM_OF_DNS_ADDR 2 
typedef struct {
    ipv4_dns_struct v4[NUM_OF_DNS_ADDR];
    ipv6_dns_struct v6[NUM_OF_DNS_ADDR];
} dns_struct ;

typedef struct {
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint8 length;
    kal_uint8  string[128];
}l4ctst_at_response_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool  remote_wakeup_enable;
}l4c_usb_suspend_req_struct;

#ifndef __MTK_TARGET__
// for MSG_ID_L4C_INJECT_SBP_CHANGE_IND
typedef struct {
    LOCAL_PARA_HDR
    kal_bool                    is_sbp_feature_change;
    sbp_md_feature_enum         sbp_feature;
    kal_bool                    new_feature_val;
    kal_bool                    is_sbp_data_change;
    sbp_md_feature_data_enum    sbp_data;
    kal_uint8                   new_data_val;
}l4c_inject_sbp_change_ind_struct;
#endif

#endif

