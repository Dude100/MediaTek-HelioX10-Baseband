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
 * RAT_TCM_DEFINES.H
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   RAT_TCM module defines h file
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


#ifndef _RAT_TCM_DEFINES_H_
#define _RAT_TCM_DEFINES_H_

#include "kal_public_defs.h"
#include "tcm_context.h"

#define RAT_TCM_MAX_SIM_NUM      (MAX_SIM_NUM)

#define RAT_TCM_DEBUG_ASSERT(x)  DEBUG_ASSERT(x)
#define RAT_TCM_ASSERT(x)  ASSERT(x)

#define RAT_TCM_TOT_CONTEXT TCM_TOT_CONTEXT

//#ifdef __GEMINI__
#if defined(__GEMINI__) || defined(__SGLTE__)
#ifndef GEMINI_PLUS
#define MOD_RAT_TCM_TOTAL_SIM (2)
#else  /* GEMINI_PLUS */
#define MOD_RAT_TCM_TOTAL_SIM (GEMINI_PLUS)
#endif /* GEMINI_PLUS */
#endif /* __GEMINI__ */

//#ifdef __GEMINI__
#if defined(__GEMINI__) || defined(__SGLTE__)
#define RAT_TCM_SIM_INTERFACE (rat_tcm_ptr_g->sim_interface)
#else  /* __GEMINI__ */
#define RAT_TCM_SIM_INTERFACE (0)
#endif /* __GEMINI__ */

#ifdef __SGLTE__
#define RAT_TCM_ANOTHER_SIM ((0==rat_tcm_ptr_g->sim_interface)?(1):(0))
#endif /* __SGLTE__ */


#define VALUE_OF_RAT_TCM_CONTEXT(X)   ((rat_tcm_ptr_g)->X)
#define RAT_TCM_CONTEXT(context_num, X)   ((rat_tcm_ptr_g)->rat_tcm_sib_tab[context_num].X)
#define RAT_TCM_CONTEXT_QUEUE(context_num, X)   ((rat_tcm_ptr_g)->rat_tcm_sib_tab[context_num].app_req_queue.X)
#define RAT_TCM_RAT_STATE()   VALUE_OF_RAT_TCM_CONTEXT(rat_tcm_rat_state)
#define RAT_TCM_TST_INJ_CONFIG(X)   (rat_tcm_ptr_g->tst_inj_config.X)
#define RAT_TCM_CONTEXT_DEACT_TRIGGERED(context_num, X)   ((rat_tcm_ptr_g)->rat_tcm_sib_tab[context_num].deact_triggered_flag.X)

#define RAT_TCM_TRACE_IMPORTANT_FUNC_GROUP TRACE_GROUP_1
#define RAT_TCM_TRACE_NORMAL_FUNC_GROUP TRACE_GROUP_2
#define RAT_TCM_TRACE_FUNC TRACE_FUNC
#define RAT_TCM_TRACE_STATE TRACE_STATE
#define RAT_TCM_TRACE_ERROR TRACE_ERROR
#define RAT_TCM_TRACE_WARNING TRACE_WARNING
#define RAT_TCM_TRACE_INFO TRACE_INFO

#define RAT_TCM_TRACE kal_trace
#define RAT_TCM_PROMPT_TRACE kal_prompt_trace
#define RAT_TCM_BRIEF_TRACE kal_brief_trace
#define RAT_TCM_FUNC_ENTRY_LOG(X) kal_brief_trace(TRACE_GROUP_1, X)
#define RAT_TCM_FUNC_NORMAL_EXIT_LOG(X) kal_brief_trace(TRACE_GROUP_1, X)
#define RAT_TCM_FUNC_ABNORMAL_EXIT_LOG(X) kal_brief_trace(TRACE_GROUP_1, X)

#ifdef __TCM_RAT_TCM_UT__
#define RAT_TCM_COVERAGE_TRACE(X) kal_prompt_trace(MOD_RAT_TCM, X)
#else // #ifdef __TCM_RAT_TCM_UT__
#define RAT_TCM_COVERAGE_TRACE(X)
#endif // ~ #ifdef __TCM_RAT_TCM_UT__

#endif /* _RAT_TCM_DEFINES_H_ */
