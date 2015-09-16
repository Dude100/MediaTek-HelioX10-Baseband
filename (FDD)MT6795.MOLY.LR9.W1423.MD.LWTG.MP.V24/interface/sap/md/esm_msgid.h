/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   esm_sap.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   LTE NAS ESM related message identity definition
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * [ESM] Add msgid for emergency call preference setting
 *
 * 08 15 2014 roy.lin
 * removed!
 * Add ESM GEMINI SUSPEND/RESUME msg id.
 *
 * 02 17 2014 roy.lin
 * removed!
 * Add EVAL_ESM_EPS_ATTACH_NEEDED_REJ_RSP msg id.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * [ESM] MSGID check-in
 *
 * removed!
 * removed!
 * 	Add message ids & SAP ids
 *
 * removed!
 * removed!
 * [ESM] Merge from MMDC pre-build CBr
 *
 * removed!
 * removed!
 * Check in missing patch for esm_msgid.h
 *
 * removed!
 * removed!
 * check in esm_msgid.h
 *
 * removed!
 * removed!
 * ESM EM Development.
 *
 * 11 07 2012 roy.lin
 * removed!
 * Add ESM related interface(msgid, struct, enum).
 ****************************************************************************/

#ifndef _ESM_SAP_H
#define _ESM_SAP_H

#include "module_msg_range.h"

MODULE_MSG_BEGIN( MSG_ID_ESM_CODE_BEGIN )
/****************************************************************************
 *                          Destination: ESM (EVAL to ESM) 
 ****************************************************************************/
MSG_ID_ESM_EVAL2ESM_BEGIN = MSG_ID_ESM_CODE_BEGIN,
MSG_ID_EVAL_ESM_PDN_CONN_EST_REQ,
MSG_ID_EVAL_ESM_BEARER_RSC_ALLOC_REQ,
MSG_ID_EVAL_ESM_BEARER_RSC_MOD_REQ,
MSG_ID_EVAL_ESM_EPSB_DEACT_REQ,
MSG_ID_EVAL_ESM_PDN_CONN_EST_RSP,
MSG_ID_EVAL_ESM_PDN_CONN_UPDATE_RSP,
MSG_ID_EVAL_ESM_EPS_ATTACH_NEEDED_REJ_RSP,
MSG_ID_EVAL_ESM_RAT_CHANGE_REQ,
MSG_ID_EVAL_ESM_RAT_CHANGE_RSP,

#if defined(__SGLTE__)
MSG_ID_EVAL_ESM_PS_SWITCH_CONTEXT_TRANSFER_REQ, // 2G -> 4G
MSG_ID_EVAL_ESM_PS_SWITCH_CONTEXT_TRANSFER_RSP, // 4G -> 2G
#endif /* __SGLTE__ */

/****************************************************************************
 *                          Destination: ESM (EMM to ESM) 
 ****************************************************************************/
MSG_ID_ESM_EMM2ESM_BEGIN,
MSG_ID_ESM_EMM_URGE_TO_EST_IND,
MSG_ID_ESM_EMM_DEREG_IND,
MSG_ID_ESM_EMM_GET_ESM_CAUSE_IND,
MSG_ID_ESM_EMM_GET_EPSB_STATUS_IND,
MSG_ID_ESM_EMM_UPDATE_EPSB_STATUS_IND,
MSG_ID_ESM_EMM_DATA_SUSPEND_IND,
MSG_ID_ESM_EMM_DATA_RESUME_IND,
MSG_ID_ESM_EMM_EPSBEARER_DATA_IND,
MSG_ID_ESM_EMM_DATA_IND,
MSG_ID_ESM_EMM_DATA_SEND_IND,
MSG_ID_ESM_EMM_DATA_CNF,
MSG_ID_ESM_EMM_CONN_RELEASE_IND,
MSG_ID_ESM_EMM_REEST_REJ,
MSG_ID_ESM_EMM_ABORT_CNF,
MSG_ID_ESM_EMM_RAT_CHANGE_IND,
MSG_ID_ESM_EMM_RAT_CHANGE_CNF,
MSG_ID_ESM_EMM_GEMINI_SUSPEND_IND,
MSG_ID_ESM_EMM_GEMINI_RESUME_IND,

/****************************************************************************
 *                          Destination: ESM (For MMDC use) 
 ****************************************************************************/
#if defined(__SGLTE__)
MSG_ID_ESM_EMM_PS_SWITCH_CONTEXT_TRANSFER_IND, // 4G -> 2G
MSG_ID_ESM_EMM_PS_SWITCH_CONTEXT_TRANSFER_CNF, // 2G -> 4G
#endif /* __SGLTE__ */

/****************************************************************************
 *                          Destination: ESM (For IMS use) 
 ****************************************************************************/
MSG_ID_ESM_EMM_EMC_ATTACH_REJ_IND,
MSG_ID_ESM_EMM_URGE_TO_EMC_EST_IND,
MSG_ID_ESM_EMM_EMC_DATA_FAIL_IND,
MSG_ID_ESM_EMM_ENTER_EMC_ATTACH_IND,

/****************************************************************************
 *                          Destination: ESM (LTM to ESM) 
 ****************************************************************************/
MSG_ID_ESM_LTM2ESM_BEGIN,
MSG_ID_ESM_LTM_IDLE_LEAVE_IND,

MSG_ID_ESM_LTM_EPSB_INIT_REQ,   
MSG_ID_ESM_LTM_EPSB_ACT_REQ,    
MSG_ID_ESM_LTM_EPSB_DEACT_REQ,  
MSG_ID_ESM_LTM_IDLE_ENTER_REQ,  
MSG_ID_ESM_LTM_IDLE_LEAVE_REQ,  
MSG_ID_ESM_LTM_IDLE_LEAVE_REJ, 
MSG_ID_ESM_LTM_UL_SUSPEND_REQ,
MSG_ID_ESM_LTM_UL_RESUME_REQ,
MSG_ID_ESM_LTM_GEMINI_SUSPEND_REQ,
MSG_ID_ESM_LTM_GEMINI_RESUME_REQ,

/****************************************************************************
 *                          Destination: ESM (SM to ESM) 
 ****************************************************************************/
MSG_ID_ESM_SM2ESM_BEGIN,
MSG_ID_SM_ESM_EPSB_CONTEXT_TRANSFER_RSP,
MSG_ID_SM_ESM_PDP_CONTEXT_TRANSFER_REQ,
MSG_ID_SM_ESM_STANDBY_ON_OLD_RAT_REQ,


/****************************************************************************
 *                          Destination: ESM (ESM internal use) 
 ****************************************************************************/
MSG_ID_ESM_MOD_GLOBAL_VAR_REQ,
MSG_ID_ESM_STATUS_REPORT_IND,
MSG_ID_ESM_STATUS_REPORT_RSP,
MSG_ID_ESM_SET_EMC_DOMAIN_PREFERENCE_REQ,

/****************************************************************************
 *                          Destination: ESM (For EM use) 
 ****************************************************************************/

MSG_ID_ESM_ENABLE_EM_INFO_IND_REQ,


MSG_ID_ESM_CODE_END,

MODULE_MSG_END( MSG_ID_ESM_CODE_TAIL )

#endif 
