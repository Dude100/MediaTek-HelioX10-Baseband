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
 *   l4c2csm_ss_lcs_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : l4c2csm_ss_lcs_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _L4C2CSM_SS_LCS_STRUCT_H
#define _L4C2CSM_SS_LCS_STRUCT_H

#include "kal_general_types.h"
#include "ss_asn.h"

//SSAGPS
//to L4C
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    SS2_LocationNotificationArg   ssLocationNotificationArg;
    kal_uint8 ss_id; // for parallel SS
} l4ccsm_ciss_mtlr_begin_ind_struct;
//MSG_ID_L4CCSM_CISS_MTLR_BEGIN_IND,

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    SS2_LCS_AreaEventRequestArg   ssLCSAreaEventRequestArg;
    kal_uint8 ss_id; // for parallel SS
} l4ccsm_ciss_aerq_begin_ind_struct;
//MSG_ID_L4CCSM_CISS_AERQ_BEGIN_IND,

//null
//MSG_ID_L4CCSM_CISS_AERP_FAC_IND,
// for parallel SS
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 ss_id; // for parallel SS
} l4ccsm_ciss_aerp_fac_ind_struct;
//MSG_ID_L4CCSM_CISS_AERP_FAC_IND,

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 return_code;
    kal_uint8 cause_present;
    kal_uint16 cause;
    kal_uint8 ss_id; // for parallel SS
} l4ccsm_ciss_aerp_end_cnf_struct;
//MSG_ID_L4CCSM_CISS_AERP_END_CNF,

typedef l4ccsm_ciss_aerp_end_cnf_struct l4ccsm_ciss_molr_end_cnf_struct;
//MSG_ID_L4CCSM_CISS_MOLR_END_CNF,

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    SS2_LCS_AreaEventCancellationArg ssLCSAreaEventCancellationArg;
    kal_uint8 ss_id; // for parallel SS
} l4ccsm_ciss_aecl_begin_ind_struct;
//MSG_ID_L4CCSM_CISS_AECL_BEGIN_IND,

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    SS2_LCS_MOLRRes ssLCSMOLRRes;
    kal_uint8 ss_id; // for parallel SS
} l4ccsm_ciss_molr_fac_ind_struct;
//MSG_ID_L4CCSM_CISS_MOLR_FAC_IND,



//to CISS

//MT response
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    SS2_LocationNotificationRes ssLocationNotificationRes;
    kal_uint8 ss_id; // for parallel SS
} l4ccsm_ciss_mtlr_end_rsp_struct;
//MSG_ID_L4CCSM_CISS_MTLR_END_RSP,

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 cause_value;
    kal_uint8 ss_id; // for parallel SS
} l4ccsm_ciss_aerq_end_rsp_struct;
//or null?
//MSG_ID_L4CCSM_CISS_AERQ_END_RSP,

//MO request
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    SS2_LCS_AreaEventReportArg ssLCSAreaEventReportArg; 
    kal_uint8 ss_id; // for parallel SS
    kal_uint8 rat_info; //for CISS to recognize the operating rat: 0:2/3G, 1:4G
} l4ccsm_ciss_aerp_req_struct;
//MSG_ID_L4CCSM_CISS_AERP_REQ,

typedef  l4ccsm_ciss_aerp_req_struct l4ccsm_ciss_aerp_fac_res_struct;
//MSG_ID_L4CCSM_CISS_AERP_FAC_RES

typedef  l4ccsm_ciss_aerq_end_rsp_struct l4ccsm_ciss_aerp_end_req_struct;
typedef  l4ccsm_ciss_aerq_end_rsp_struct l4ccsm_ciss_aecl_end_rsp_struct;
typedef  l4ccsm_ciss_aerq_end_rsp_struct l4ccsm_ciss_molr_end_req_struct;
//MSG_ID_L4CCSM_CISS_AERP_END_REQ,
//MSG_ID_L4CCSM_CISS_AECL_END_RSP,
//MSG_ID_L4CCSM_CISS_MOLR_END_REQ
typedef  l4ccsm_ciss_aerq_end_rsp_struct l4ccsm_ciss_lcs_end_req_struct; // for general used

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    SS2_LCS_MOLRArg ssLCSMOLRArg;
    kal_uint8 ss_id; // for parallel SS
    kal_uint8 rat_info; //for CISS to recognize the operating rat: 0:2/3G, 1:4G
} l4ccsm_ciss_molr_req_struct;
//MSG_ID_L4CCSM_CISS_MOLR_REQ

typedef  l4ccsm_ciss_molr_req_struct l4ccsm_ciss_molr_fac_res_struct;
//MSG_ID_L4CCSM_CISS_MOLR_FAC_RES

#endif


