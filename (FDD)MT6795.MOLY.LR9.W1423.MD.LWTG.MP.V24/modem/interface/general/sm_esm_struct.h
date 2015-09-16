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
 *  sm_emm_struct.h
 *
 * Project:
 * --------
 *  MOLY
 *
 * Description:
 * ------------
 *  This file describes the common structure of SM and eSM
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _SM_ESM_STRUCT_H
#define _SM_ESM_STRUCT_H

#include "kal_general_types.h"
#include "irat_common_struct.h"
#include "kal_public_defs.h"


typedef struct {
    kal_uint8 bearer_id;
    bearer_mapping_result_enum mapping_result;
}sm_esm_transferred_context_struct;

typedef struct {
    kal_uint8 total_number; // Total number of PDP context/EPS bearer which transfered to target RAT
    sm_esm_transferred_context_struct bearers[MAX_TRANSFERRED_BEARER_NUM];
}sm_esm_context_status_struct;

typedef struct {
    LOCAL_PARA_HDR
    // no need to include irat_type, source_rat, target_rat, irat_result. because ESM will send this msg to SM only when 4G23 success
    //bearer_ctxt_transfer_struct epsb_info;
    kal_uint8 total_number; // Total number of PDP context/EPS bearer which will transfer to target RAT
    bearer_ctxt_struct epsb_context[MAX_TRANSFERRED_BEARER_NUM]; // bearer context which will transfer to target RAT
} sm_esm_epsb_context_transfer_ind_struct; // 4G23 success context transfer: ESM --> SM

typedef sm_esm_epsb_context_transfer_ind_struct sm_esm_epsb_context_transfer_ind_for_sm_ut_struct;

typedef struct {
    LOCAL_PARA_HDR
    sm_esm_context_status_struct pdp_ctxt_sts;
} sm_esm_epsb_context_transfer_rsp_struct; // 4G23 success context transfer: SM --> ESM

typedef struct {
    LOCAL_PARA_HDR
    // no need to include irat_type, source_rat, target_rat, irat_result. because ESM will send this msg to SM only when 4G23 success
    //bearer_ctxt_transfer_struct pdp_info;
    kal_uint8 total_number; // Total number of PDP context/EPS bearer which will transfer to target RAT
    bearer_ctxt_struct pdp_context[MAX_TRANSFERRED_BEARER_NUM]; // bearer context which will transfer to target RAT
} sm_pdp_context_transfer_req_struct; // iRAT success context transfer: Source RAT  --> Target RAT

typedef sm_pdp_context_transfer_req_struct sm_esm_pdp_context_transfer_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    sm_esm_context_status_struct epsb_ctxt_sts;
} sm_esm_pdp_context_transfer_cnf_struct; // 23G4 success context transfer : ESM --> SM

#ifdef __SGLTE__
typedef sm_pdp_context_transfer_req_struct sm_ps_switch_pdp_context_transfer_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    sm_esm_context_status_struct pdp_ctxt_sts;
} sm_ps_switch_pdp_context_transfer_cnf_struct; // 23G4 success context transfer : ESM --> SM

#endif

#endif // ~ _SM_ESM_STRUCT_H


