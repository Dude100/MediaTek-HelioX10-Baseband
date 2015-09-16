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
 * RAT_TCM_ENUMS.H
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   RAT_TCM module enums h file
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


#ifndef _RAT_TCM_ENUMS_H_
#define _RAT_TCM_ENUMS_H_

#include "kal_public_defs.h"

typedef enum {
    ACT_REQ_QUEUE,
    DEACT_REQ_QUEUE,
    MOD_REQ_QUEUE
} rat_tcm_queue_enum;

typedef enum {
    RAT_TCM_RAT_UNKNOWN, // 0
    RAT_TCM_RAT_23G, // 1
    RAT_TCM_RAT_23G_GOING_TO_4G, // 2
    RAT_TCM_RAT_4G, // 3
    RAT_TCM_RAT_4G_GOING_TO_23G, // 4
    RAT_TCM_RAT_TOTAL_ENUM, // 5
    RAT_TCM_RAT_END = RAT_TCM_RAT_TOTAL_ENUM // 5
} rat_tcm_rat_state_enum;


typedef enum {
    RAT_TCM_ILM_BYPASS, // 0
    RAT_TCM_ILM_PROCESS_AND_BYPASS, // 1
    RAT_TCM_ILM_QUEUE, // 2
    RAT_TCM_ILM_HANDLE_METHOD_TOTAL_ENUM, // 3
    RAT_TCM_ILM_HANDLE_METHOD_END = RAT_TCM_ILM_HANDLE_METHOD_TOTAL_ENUM // 3
} rat_tcm_ilm_handle_enum;


typedef enum {
    RAT_TCM_INCOMMING_ILM_TYPE_ACT_REQ,
    RAT_TCM_INCOMMING_ILM_TYPE_DEACT_REQ,
    RAT_TCM_INCOMMING_ILM_TYPE_MOD_REQ,

    RAT_TCM_INCOMMING_ILM_TYPE_ACT_SUCCESS,
    RAT_TCM_INCOMMING_ILM_TYPE_DEACT_SUCCESS,
    RAT_TCM_INCOMMING_ILM_TYPE_MOD_SUCCESS,

    RAT_TCM_INCOMMING_ILM_TYPE_ACT_FAIL,
    RAT_TCM_INCOMMING_ILM_TYPE_DEACT_FAIL,
    RAT_TCM_INCOMMING_ILM_TYPE_MOD_FAIL,

    RAT_TCM_INCOMMING_ILM_TYPE_SECONDARY_ACT_IND,
    RAT_TCM_INCOMMING_ILM_TYPE_DEACT_IND,
    RAT_TCM_INCOMMING_ILM_TYPE_MOD_IND,

    RAT_TCM_INCOMMING_ILM_TYPE_MT_PRIMARY_INITIALIZATION,

    RAT_TCM_INCOMMING_ILM_TYPE_RELAY_TO_L4C,
    RAT_TCM_INCOMMING_ILM_TYPE_RELAY_TO_PPP,
    RAT_TCM_INCOMMING_ILM_TYPE_RELAY_TO_CURRENT_TCM,

    RAT_TCM_INCOMMING_ILM_TYPE_INTER_RAT_RELATED,
    #ifdef __SGLTE__
    RAT_TCM_INCOMMING_ILM_TYPE_PS_CHANGE_RELATED,
    #endif /* __SGLTE__ */
    RAT_TCM_INCOMMING_ILM_TYPE_TCM_START_UP_RELATED,

    RAT_TCM_INCOMMING_ILM_TYPE_UNKNOWN,

    RAT_TCM_INCOMMING_ILM_TYPE_TOTAL_ENUM,
    RAT_TCM_INCOMMING_ILM_TYPE_END = RAT_TCM_INCOMMING_ILM_TYPE_TOTAL_ENUM
} rat_tcm_incomming_ilm_type_enum;

typedef enum {
    RAT_TCM_REQ_NONE,
    RAT_TCM_REQ_QUEUED,
    RAT_TCM_REQ_QUEUED_AND_TCM_PROCESSING,
    RAT_TCM_REQ_QUEUED_AND_TCM_REPORT_FAIL_DURING_IRAT,
    #ifdef __SGLTE__
    RAT_TCM_REQ_QUEUED_AND_TCM_REPORT_FAIL_DURING_PS_SWITCH,
    #endif /* __SGLTE__ */
    RAT_TCM_REQ_PROGRESS_TOTAL_ENUM
} rat_tcm_req_progress_enum;

typedef enum {
    RAT_TCM_CONTEXT_USER_VIEW_INACTIVE,
    RAT_TCM_CONTEXT_USER_VIEW_ACTIVE,
    RAT_TCM_CONTEXT_USER_VIEW_TOTAL_ENUM
} rat_tcm_context_user_view_enum;

typedef enum {
    RAT_TCM_TRIGGERER_NONE,
    RAT_TCM_TRIGGERER_IS_USER, // USER priority > TFT_LIB, if TFT_LIB deact first, USER deact later, the value is still changed to USER. if USER deact first, TFT_LIB deact later, the value will still be USER
    RAT_TCM_TRIGGERER_IS_TFT_CONFLICT,
    RAT_TCM_TRIGGERER_IS_ENAS_TRIGGER,
    RAT_TCM_TRIGGERER_IS_TFT_VALIDATE_FAIL,
    RAT_TCM_TRIGGERER_TOTAL_ENUM
} rat_tcm_deact_triggerer_enum;

typedef enum {
    RAT_TCM_USER_EMPTY_USER,
    RAT_TCM_USER_L4C,
    RAT_TCM_USER_PPP,
    RAT_TCM_USER_MT_SECONDARY_AUTO_ESTABLISHED,
    RAT_TCM_USER_TOTAL_ENUM
} rat_tcm_context_user_enum;

#endif /* _RAT_TCM_ENUMS_H_ */
