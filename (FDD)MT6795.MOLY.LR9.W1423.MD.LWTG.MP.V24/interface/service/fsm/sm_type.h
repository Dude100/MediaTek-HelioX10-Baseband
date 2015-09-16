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
 *	sm_type.h
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

#ifndef __SM_TYPE_H__
#define __SM_TYPE_H__

/* INCLUDES ***********************************************************************/

#include "dlist.h"
#include "sm_event.h"
#include "kal_public_api.h" //MSBB change #include "stack_ltlcom.h"
#include "kal_general_types.h"

/* MACROS *************************************************************************/

#define cSM_MAX_SERVICE_NAME     40
#define cSM_MAX_PROCESSES        32             //MTK: Each will cost 40+16+8 bytes
#define cSM_MAX_INSTANCES        20             //MTK: Original UB is 32
#define cSM_MAX_RETURNED_EVENTS  5              //MTK: Origianl UB is 10. Each will cost 12 bytes
#define h4SM_NULL_EVENT          0xffffffff
#define h2SM_INVALID_EVENT_ID    0xFFFF


/* TYPE DEFINITIONS ***************************************************************/

struct tContext ; //forward reference to tContext structure

/* ---------------------------------------------------------------------------------
message translation function pointer
--------------------------------------------------------------------------------- */

typedef kal_bool (* tSM_TranslateMsgFnPtr)
                  (ilm_struct       *ptReceivedMsg,         //pointer to message to translate
                   kal_uint32       *pU32InterpretedEvent,  //returned event
                   kal_uint32       *pU32TableIndex,        //table index - defaults to 0
                   kal_uint32       *pInstanceIndex,        //instance index - defaults to 0
                   struct tContext  *ptContext) ;           //context structure

/* ---------------------------------------------------------------------------------
transition function pointer
--------------------------------------------------------------------------------- */
typedef kal_bool (* tSM_TransitionFnPtr)
                  (ilm_struct       *pvReceivedMsg,         //received message
                   kal_uint32       U32InterpretedEvent,    //interpreted event
                   kal_uint32       *pU32NextState,         //pointer to next state
                   struct tContext  *ptContext,             //pointer to current context
                   kal_bool*        pSaved,                 //pointer to save event flag
                   kal_bool*        pReleaseMsg,            //pointer to delete msg flag
                   kal_bool         isSavedEvent);          //flag of saved event indication

/* ---------------------------------------------------------------------------------
additional translation function pointer
--------------------------------------------------------------------------------- */

typedef kal_bool (* tSM_ExtraTranslateMsgFnPtr)
                  (ilm_struct *ptMessage,                 //message to translate
                   kal_uint32 *pU32Event,                 //returned event array
                   kal_uint32 *pInstanceIndex,            //service table index array
                   kal_uint32 *pU32TableIndex) ;          //instance index array

/* ---------------------------------------------------------------------------------
entry function pointer
--------------------------------------------------------------------------------- */

typedef kal_bool (* tSM_ProcEntryFnPtr) (struct tContext *ptContext, kal_uint32 *var) ;

/* ---------------------------------------------------------------------------------
event entry structure
--------------------------------------------------------------------------------- */

typedef struct
{
   tSM_TransitionFnPtr pfTransitionFn ; //pointer to a transition function
} tEventEntry ;

/* ---------------------------------------------------------------------------------
state event matrix entry structure
--------------------------------------------------------------------------------- */

typedef struct
{
   const tEventEntry *aEventEntryArray ;  //array of transition function pointers for state
} tTableEntry ;

/* ---------------------------------------------------------------------------------
transition table structure
--------------------------------------------------------------------------------- */

typedef struct
{
   kal_uint32              U32NumStates ;                      //number of states
   kal_uint32              U32NumEvents ;                      //number of events
   const tTableEntry       *aStateEventMatrix ;                //state event matrix
   kal_uint8               serviceName[cSM_MAX_SERVICE_NAME] ; //service name
} tTransitionTable ;

/* ---------------------------------------------------------------------------------
state machine structure
--------------------------------------------------------------------------------- */

typedef struct
{
   tSM_TranslateMsgFnPtr  pfTranslateMsg ;               //pointer to translation function
   tTransitionTable       atTables[cSM_MAX_PROCESSES] ;  //array of state-event tables
   tSM_ProcEntryFnPtr     *entryFn ;                     //should be reserved cuz instance?
   kal_uint16             numServices;
} tStateMachine ;


typedef struct
{
   const char              *processName;
   kal_uint32              numEvents;
} tProcessStateMachine;

typedef struct
{
   kal_uint32           U32NumStates ;       //number of states
   const tTableEntry    *aStateEventMatrix ; //state event matrix
} tTransitionFunctionTable;

typedef kal_bool (* tSM_ContinuationFuncPtr) (kal_uint32 *pU32State, struct tContext *ptContext) ;

typedef struct tFsmContext
{
   const char                 *procedureName;
   tTransitionFunctionTable   transitionTable ; //pointer to the current transition table
   kal_uint32                 state ;
   void                       *pvParams;
   tSM_ContinuationFuncPtr    pContinuationFunc;
   void                       *pContinuationData;
} tFsmContext;

typedef struct
{
   kal_uint32                 U32MsgType ;     //message type
   kal_uint32                 U32Event ;       //event to return
   tSM_ExtraTranslateMsgFnPtr pfTranslate ;    //additional translation function
} tTranslateTableEntry ;

/* ---------------------------------------------------------------------------------
Instance structure
--------------------------------------------------------------------------------- */

typedef struct
{
   tProcessStateMachine SMInfo ;          //state machine info that is constant regardless of context
   EventList            *pSavedEventQueue;//The internal event queue
   DLIST_HANDLE         FsmStack ;        //linked list of FSM contexts
   tFsmContext          *pFsmContext ;    //current FSM Context will be NULL if instance is not active
   kal_uint32           processId ;       //processId not strictly needed but useful for debug
   kal_uint32           instanceId ;
   //k:kal_bool             checkSavedEvents ;
} tInstanceEntry ;

//type for instance matrix
typedef tInstanceEntry* tInstanceArray ;

/* ---------------------------------------------------------------------------------
component control structure
--------------------------------------------------------------------------------- */

typedef struct
{
   kal_int8                aU8CompName[30] ; //task name
   tSM_TranslateMsgFnPtr   pfTranslateMsg ;  //pointer to translation function
   kal_uint32              numProcesses ;    //number of processes in aMaxInstanceArray
   kal_uint32              aMaxInstanceArray[cSM_MAX_PROCESSES];
                                             //array of the maximum instances of each process
   kal_uint32              aInstanceOffsetArray[cSM_MAX_PROCESSES];
                                             //array of ID of first instance of each process
   tInstanceArray          pInstanceArray;   //array of processes for this component
   //this variable is part of a workaround for maintaining the old procedural FSM
   //and should be removed if such support is not required
   //k:struct tContext         *pCurrentContext ;
} tComponentInfo ;

typedef struct
{
   DLIST_HANDLE      pEventQueue;   //The internal event queue
   tComponentInfo    *ptCompInfo ;  //pointer to component info structure
} tComponentControl ;

typedef struct tContext
{
   tComponentControl *ptCC ;                 //pointer to process control structure
   tStateMachine     *ptSM;                  //REMOVE ASAP!!! only here for compatibility with old procedure call
   void              *pvParams ;             //data block for procedure parameters
   void              *pProcedureReturnParams;
   //k:kal_bool          bIsTopLevel;            //REMOVE ASAP - use count of FSM context instead
   //this variable is part of a workaround for maintaining the old procedural FSM
   //and should be removed if such support is not required
   kal_bool          executeContext;         //False if context terminated
   //this variable should be removed and replaced in each transition function (where used)
   //with an increment reference for the msg pointer
   kal_bool          pReleaseMsg;
   tInstanceEntry    *pCurrentInstance;
   //MTK: the next three member are related to event list
   kal_uint32        *pEventIndex;           //used by component to return events after msg translation */
   kal_uint32        *pProcessIndex;
   kal_uint32        *pInstanceIndex;
} tContext;

#endif /* __SM_TYPE_H__ */
