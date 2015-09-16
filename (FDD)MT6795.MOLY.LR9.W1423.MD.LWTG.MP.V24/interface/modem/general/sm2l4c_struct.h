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
 * SM2L4C_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of SM and L4C.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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

#ifndef _SM2L4C_STRUCT_H
#define _SM2L4C_STRUCT_H

#include "kal_general_types.h"
#include "irat_common_struct.h"
#include "kal_public_defs.h"

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
    irat_type_enum              irat_type;
    rat_type_enum               source_rat;
    rat_type_enum               target_rat;
    mm2emm_irat_info_struct     mm_info;
    sm2esm_irat_info_struct     sm_info;
    void                        *as_info_ptr;

    // check L4_NAS_RAT_CHANGE_SAP.docx for detail
} l4csm_rat_change_ind_struct; //(23G4 start)

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
    irat_type_enum              irat_type;
    rat_type_enum               source_rat;
    rat_type_enum               target_rat;
    irat_result_enum            irat_result;
    void*	                    as_info_ptr;    //The pointer of AS container information
    //bearer_mapping_result_enum	pdp_ctxt_sts[MAX_BEARER_ID];
    // check L4_NAS_RAT_CHANGE_SAP.docx for detail
} l4csm_rat_change_cnf_struct; //(4G23 finish)

#ifdef __SGLTE__
/*Huifeng: PS Swtich Struct  IND/CNF*/
typedef struct {
    LOCAL_PARA_HDR

    rat_enum               source_rat;
    rat_enum               target_rat;
    // SM -> SM,( 2->4 L4C Can discard this para)
    sm_irat_info_struct         sm_info;

    emm_mm_context_info_struct  mm_context;
} l4c_sm_ps_switch_context_transfer_ind_struct; 

typedef struct {
    LOCAL_PARA_HDR

    rat_enum               source_rat;
    rat_enum               target_rat;
} l4c_sm_ps_switch_context_transfer_cnf_struct;

typedef l4c_sm_ps_switch_context_transfer_cnf_struct l4c_ps_switch_context_transfer_cnf_struct;
#endif
#endif // ~ _SM2L4C_STRUCT_H


