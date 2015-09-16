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
 * ABM2L4C_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of ABM and L4C.
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
#ifndef _ABM2L4C_STRUCT_H
#define _ABM2L4C_STRUCT_H
//#include "ps2sat_struct.h"
#include "l4c2abm_struct.h"
//#include "kal_non_specific_general_types.h"
//#include "custom_mmi_default_value.h"
#include "kal_general_types.h"
#include "ps_public_struct.h"
#include "tcm_api.h"
#include "ps_public_enum.h"

#ifdef __SATCE__
typedef struct {
    kal_uint8 ref_count;
    kal_uint8 msg_len;
    kal_uint8 nw_acct_id;    
    kal_bool is_apn_valid;
    kal_uint8 apn_length;
    kal_uint8 apn[50];
    kal_bool is_username_valid;
    kal_uint8 no_username;
    kal_uint8 username[16];
    kal_uint8 dcs_of_username;
    kal_bool is_passwd_valid;
    kal_uint8 no_passwd;
    kal_uint8 passwd[16];
    kal_uint8 dcs_of_passwd;
    kal_bool is_local_addr_valid;
    kal_uint8 no_local_addr;
    kal_uint8 local_addr[16];
    kal_bool is_dest_addr_valid;
    kal_uint8 no_dest_addr;
    kal_uint8 dest_addr[16];
    sat_gprs_bearer_para_struct gprs_bearer;
} abml4c_sate_set_gprs_account_info_req_struct;
#endif /* __SATCE__ */

// Packet filter content which is necessary for GGSN to enable packet classification and policing for downlink data transfer.
typedef struct {
    kal_uint8	pfi;    // Packet filter identifier
    kal_uint8	epi;	// Packet filter evaluation precedence
    kal_uint8	src_addr_sb_net_mask_len;
    kal_uint8	src_addr_sb_net_mask[8];    // IPv4 address and subnet mask
    kal_bool	prot_number_present;
    kal_uint8	prot_number_next_hdr;       // Protocol identifier
    kal_uint8	dst_port_len;
    kal_uint16	dst_port_range[2];          // Destination port range
    kal_uint8	src_port_len;
    kal_uint16	src_port_range[2];          // Source port range
    kal_bool	ipsec_spi_present;
    kal_uint32	ipsec_spi;                  // IPSec security parameter index
    kal_uint8	tos_len;
    kal_uint8	tos_traffic_class_mask[2];  // Type of Service and mask
    kal_bool	flow_label_present;
    kal_uint32	flow_label;                 // IPv6 Flow label
} l4c_gprs_pf_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   kal_uint8 profile_id;
   kal_uint8 profile_type;
   l4c_gprs_account_info_struct gprs_account_info;
   tcm_ps_qos_profile_struct qos_info; //mtk02285, 20110916
#ifdef __SATCE__
   abml4c_sate_set_gprs_account_info_req_struct sate_account_info;
#endif /* __SATCE__ */
   /* following are for __APP_SECONDARY_PDP_SUPPORT__ */
   kal_uint8 qos_id;			// QoS Profile ID
   kal_uint8 gprs_pf_num;               // Number of gprs_pf_info
   l4c_gprs_pf_struct gprs_pf_info[8];  // Packet filter content
} l4c_ps_abm_setup_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   kal_uint8 profile_id;
   /* following are for __APP_SECONDARY_PDP_SUPPORT__ */
   kal_uint8 qos_id;			// QoS Profile ID
   kal_uint8 context_id;
   kal_uint8 profile_type;
} l4c_ps_abm_disc_req_struct;

typedef struct {
   kal_uint8                ref_count;
   kal_uint16               msg_len;
   kal_uint8	            context_id;
   kal_bool	                is_qos_present; // indicates if QoS modification
   nvram_editor_qos_struct	modify_qos;     // modifying QoS value
   kal_uint8	            tft_opcode;     // tft_opcode_enum: the operation of TFT modification
   kal_uint8	            gprs_pf_num;    // number of gprs_pf_info
   l4c_gprs_pf_struct	    gprs_pf_info[8];// packet filter content
} l4c_ps_abm_qos_tft_modify_req_struct;

//MAUI_02395134
typedef struct {
   kal_uint8 authentication_type;
   kal_uint8 user_name[32];
   kal_uint8 password[32];
   kal_uint8 dns[4];
   kal_uint8 sec_dns[4];
   kal_uint8 addr_str[41+1]; //MAX_CC_ADDR_LEN +1
   kal_uint8 csd_ur;
   kal_uint8 csd_type;
   kal_uint8 csd_module;
} l4c_csd_account_info_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   kal_uint8 profile_type;
   kal_uint8 csd_profile_id;
   l4c_csd_account_info_struct csd_account_info;
} l4c_cc_abm_setup_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   kal_uint8 csd_profile_id;
   kal_uint8 profile_type;
} l4c_cc_abm_disc_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 result;
    kal_uint8 error_cause;
} l4cabm_start_cnf_struct;

typedef l4cabm_start_cnf_struct l4cabm_set_gprs_account_info_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 result;
    kal_uint8 error_cause;
    l4c_gprs_account_info_struct gprs_account_info;
} l4cabm_get_gprs_account_info_cnf_struct;

#ifdef __UCM_SUPPORT__
typedef struct
{
	kal_uint8 ref_count;
       kal_uint16 msg_len;
       kal_uint8     prof_id; 
	kal_uint8	sim_info;
} abm_l4c_get_csd_call_num_req_struct;
#endif /* __UCM_SUPPORT__ */

// Karen
typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;  
   kal_uint8 profile_id;
   kal_uint8 qos_id;
   kal_uint8 context_id;
} l4c_ps_abm_reactivate_req_struct;

typedef struct  
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 connect_type;
    kal_uint8 call_id;
    kal_uint8 context_id;
}l4c_abm_dialup_disc_req_struct;

typedef struct  
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 serial_num;
    kal_uint8 total_context_id;
    kal_uint8 context_id[MAX_GPRS_DIALUP_NUM];
}l4c_ps_abm_get_dialup_info_req_struct;

typedef struct {
    kal_uint8 context_id;
    kal_bool reset_tx;
    kal_bool reset_rx;
} l4c_ps_dialup_info_reset_cmd_struct;

typedef enum
{
    L4C_PS_ABM_DIALUP_RESET_TX_RX = 0,
    L4C_PS_ABM_DIALUP_RESET_TX,
    L4C_PS_ABM_DIALUP_RESET_RX,
    L4C_PS_ABM_DIALUP_RESET_IN_DETAIL,
    L4C_PS_ABM_DIALUP_RESET_INVALID
} l4c_reset_dialup_cmd_enum;

typedef struct  
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 serial_num;
   kal_uint8 total_reset_num;
   l4c_reset_dialup_cmd_enum reset_cmd_type; //RESET_TX_RX, RESET_TX, RESET_RX, RESET_IN_DETAIL
   l4c_ps_dialup_info_reset_cmd_struct reset_cmd[MAX_GPRS_DIALUP_NUM];
}l4c_ps_abm_reset_dialup_info_req_struct;
#endif /* ~_ABM2L4C_STRUCT_H */


