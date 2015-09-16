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

/*******************************************************************************
 * Filename:
 * ---------
 *	cm2mm_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for structure definition between MM and CM layers.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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


#ifndef _CM2MM_STRUCT_H
#define _CM2MM_STRUCT_H

#define MAX_SUPPORTED_CALLS	7

#include "kal_general_types.h"
#include "l3_inc_enums.h"
#include "mmcm_enums.h"
#include "kal_public_defs.h"

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 ti;
    est_cause_enum cause;
    kal_bool send_priority;
    emlpp_priority_enum priority;
    kal_bool need_preemption;
    kal_bool is_ecall;
    kal_uint8 ecall_type;
} mmcm_est_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 ti;
#ifdef __UMTS_TDD128_MODE__
	kal_bool force_release; /*For TDD call clearing optimization*/
#endif
} mmcm_rel_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 ti;
} mmcm_prompt_rsp_struct;

typedef struct {
    LOCAL_PARA_HDR
    prompt_rej_cause reject_cause;
} mmcm_prompt_rej_struct;

#ifdef __REL6__
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 ti_count;
    kal_uint8 ti_list[MAX_SUPPORTED_CALLS];
} mmcc_reest_req_struct;
#endif

typedef struct {
    LOCAL_PARA_HDR
} mmcm_start_call_req_struct;

typedef struct {
    LOCAL_PARA_HDR
} mmcm_abort_call_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 ti_count;
    kal_uint8 ti_list[MAX_SUPPORTED_CALLS];
    kal_uint8 ecc_ti; /* if no ecc, this value should be 0xFF */
} mmcc_srvcc_est_req_struct;

typedef mmcm_est_req_struct mmcc_est_req_struct;
typedef mmcm_rel_req_struct mmcc_rel_req_struct;
typedef mmcm_prompt_rsp_struct mmcc_prompt_rsp_struct;
typedef mmcm_prompt_rej_struct mmcc_prompt_rej_struct;

typedef mmcm_est_req_struct mmss_est_req_struct;
typedef mmcm_rel_req_struct mmss_rel_req_struct;

typedef mmcm_est_req_struct mmsms_est_req_struct;
typedef mmcm_rel_req_struct mmsms_rel_req_struct;

#endif 


