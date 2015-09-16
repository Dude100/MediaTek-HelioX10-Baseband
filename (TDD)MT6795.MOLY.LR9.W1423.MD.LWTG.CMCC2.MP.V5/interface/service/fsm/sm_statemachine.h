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
 *	sm_statemachine.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 * Header file for framework state machine
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SM_STATEMACHINE_H__
#define __SM_STATEMACHINE_H__

/* INCLUDES ***********************************************************************/

#include "sm_type.h"
#include "kal_public_api.h" //MSBB change #include "stack_ltlcom.h"
#include "kal_general_types.h"

/* MACROS *************************************************************************/

/* ---------------------------------------------------------------------------------
start and terminate states
--------------------------------------------------------------------------------- */

#define SM_START     0x0000
#define SM_TERMINATE 0xffff

/* ---------------------------------------------------------------------------------
transition function signature
--------------------------------------------------------------------------------- */

#define mSM_TRANSITION_FN(x)                                         \
                  kal_bool x(ilm_struct*      tReceivedMsg,          \
                             kal_uint32       U32InterpretedEvent,   \
                             kal_uint32*      pU32State,             \
                             struct tContext* ptContext,             \
                             kal_bool*        pSaved,                \
                             kal_bool*        pReleaseMsg,           \
                             kal_bool         isSavedEvent)

/* ---------------------------------------------------------------------------------
message translation function signature
--------------------------------------------------------------------------------- */

#define mSM_TRANSLATE_MSG_FN(x)                                      \
                  kal_bool x(ilm_struct*      ptReceivedMsg,         \
                             kal_uint32*      pU32InterpretedEvent,  \
                             kal_uint32*      pU32TableIndex,        \
                             kal_uint32*      pInstanceIndex,        \
                             struct tContext* ptContext)

/* PUBLIC FUNCTION DECLARATION ****************************************************/

extern mSM_TRANSITION_FN(eSM_IgnoreEvent) ;

extern mSM_TRANSITION_FN(eSM_WarningEvent) ;

extern mSM_TRANSITION_FN(eSM_InvalidEvent) ;

extern mSM_TRANSITION_FN(eSM_SavedEvent) ;

extern kal_bool eSM_EventLookup(const tTranslateTableEntry  *ptTable,
                               kal_uint32                   U32Entries,
                               ilm_struct                   *ptMessage,
                               kal_uint32                   *pU32Event,
                               kal_uint32                   *pU32TableIndex,
                               kal_uint32                   *pInstanceIndex) ;

extern void eSM_ExecuteContext(struct tContext *ptContext, ilm_struct *tReceivedMsg) ;

extern void eSM_InitContext(struct tContext *FirstContext) ;

extern void eSM_ResetFSM(struct tContext *ptContext, kal_bool Exec_Process_Entry);

extern void eSM_PopulateProcessServiceSM(tStateMachine            *pSM,
                                        kal_uint32                processId,
                                        kal_uint32                numStates,
                                        kal_uint32                numEvents,
                                        const tTableEntry         *pStateTable,
                                        const kal_int8            *serviceName);

extern kal_uint32 eSM_GetInstanceCurrentState(tComponentInfo *ptCompInfo, kal_uint32 processID, kal_uint32 instanceID);

extern kal_bool fSM_LookUpSpecificSavedEvent(tInstanceEntry *pInstance, kal_uint32 eventId, ilm_struct *pMsg);

extern kal_bool fSM_DeleteSpecificSavedEvent(tInstanceEntry *pInstance, kal_uint32 eventId);

extern kal_bool fSM_ClearSavedEventQueue(tInstanceEntry *pInstance);

// 20120925 Scotty R9_MultiMode__FSM_extern
extern void fSM_HandleSavedEvents(struct tContext *pContext, tInstanceEntry  *pInstance);
                                                 

#endif /* __SM_STATEMACHINE_H__ */
