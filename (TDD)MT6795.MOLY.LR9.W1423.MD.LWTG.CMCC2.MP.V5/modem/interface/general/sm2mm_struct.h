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
 *  sm2mm_struct.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file describes the common structure of SM and MM. 
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
 * removed!
 * removed!
 *
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

#ifndef _SM2MM_STRUCT_H
#define _SM2MM_STRUCT_H

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "l3_inc_enums.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "as2nas_struct.h"
#include "irat_common_struct.h"

typedef struct {
    LOCAL_PARA_HDR
    qos_struct qos;
    kal_uint32 tlli;
    rp_enum radio_priority;
    est_cause_enum cause;
    kal_uint8 pkt_flow_identifier;
    peer_msg_id_struct peer_msg_id;
} gmmsm_unitdata_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint16 nsapi_status;
    traffic_class_enum  max_traffic_class; // the highest quality traffic class among all active PDP context
} gmmsm_nsapi_status_req_struct;

#ifdef __GEMINI__
typedef struct {
    LOCAL_PARA_HDR
} gmmsm_session_begin_req_struct;

typedef struct {
    LOCAL_PARA_HDR
} gmmsm_session_end_req_struct;
#endif

typedef struct {
    LOCAL_PARA_HDR
    est_cause_enum cause;
} gmmsm_attach_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    est_cause_enum cause;
} gmmsm_est_req_struct;

#ifdef __SM_UT__
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sm_calculate_mt_procedure_pdp_number_result;
    kal_uint8 sm_calculate_mo_procedure_pdp_number_result;
    kal_uint32 sm_calculate_how_many_pdp_are_used_result;
} sm_test_sm_calculate_how_many_pdp_are_used_struct;

#endif // ~ #ifdef __SM_UT__

/** 
  * According to Multimode interRAT message processing rules, 
  * the receiving module, said... the MOD_A, need to process this message in the following way  
  * - (1) Relay this interRAT message to next module, said... the MOD_B, first
  * - (2) then MOD_A can start to do processing of this message
  * because when a RD designs a new MM iRAT feature, he/she will assume others process these messages in this way
  * this rules make sures the interRAT message flow is as expected
  */
typedef struct {
    LOCAL_PARA_HDR
    irat_type_enum      irat_type;      //Indicates the inter-RAT type
    rat_type_enum       source_rat;     //Source RAT
    rat_type_enum       target_rat;     //Target RAT
    irat_result_enum    irat_result;    //The result of inter-RAT change
    void*               as_info_ptr;    //The pointer of AS container information
} gmmsm_rat_change_rsp_struct; // (23G4 finish)

/** 
  * According to Multimode interRAT message processing rules, 
  * the receiving module, said... the MOD_A, need to process this message in the following way  
  * - (1) Relay this interRAT message to next module, said... the MOD_B, first
  * - (2) then MOD_A can start to do processing of this message
  * because when a RD designs a new MM iRAT feature, he/she will assume others process these messages in this way
  * this rules make sures the interRAT message flow is as expected
  */
typedef struct {
    LOCAL_PARA_HDR
    irat_type_enum  irat_type;      //Indicates the inter-RAT type
    rat_type_enum   source_rat;     //Source RAT (GAS or UAS)
    rat_type_enum   target_rat;     //Target RAT (Should be EAS)
    kal_bool        esm_deactivate_isr; //ESM sets this flag if ESM bearer has been added or modified after ISR was activated
    kal_uint16      nsapi_status;   //PDP context status
    traffic_class_enum       max_traffic_class; // the highest quality traffic class among all active PDP context

    emm2mm_irat_info_struct emm_info;

    void*           as_info_ptr;    //Indicates the address of the activation request for RAT change to LTE, the information is dedicated for AS.
                                //The buffer will be freed by soure or target AS
} gmmsm_rat_change_req_struct; // (4G23 start)

typedef struct {
    LOCAL_PARA_HDR
    // check L4_NAS_RAT_CHANGE_SAP.docx for detail
} gmmsm_isr_deactivate_req_struct;

#ifdef __SGLTE__ 

typedef struct {
    LOCAL_PARA_HDR
    rat_enum source_rat;
    rat_enum target_rat;
    kal_uint16 nsapi_status;
    emm_mm_context_info_struct mm_context;
}gmmsm_ps_switch_context_transfer_req_struct;
#endif /* __SGLTE__*/

#endif 


