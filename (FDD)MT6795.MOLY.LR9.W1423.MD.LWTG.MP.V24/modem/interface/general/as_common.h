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
 *	as_common.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 * Common header file for access stratum
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
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __AS_COMMON_H__
#define __AS_COMMON_H__

/* INCLUDES ****************************************************************************/

#include "task_config.h"           //Alfie: added when porting with Karen's ask.
#include "kal_public_api.h"
/* TYPE DEFINITIONS ***************************************************************/

#define U8        kal_uint8
#define S8        kal_int8
#define U16       kal_uint16
#define S16       kal_int16
#define U32       kal_uint32
#define S32       kal_int32
#define tBOOL     kal_bool
#define Bool      kal_bool
#define TIME_OF_DAY double

#ifndef FALSE_E
#define FALSE_E   KAL_FALSE
#endif

#ifndef TRUE_E
#define TRUE_E    KAL_TRUE
#endif

#ifndef tMsg
#define tMsg      ilm_struct*
#endif


/* Vincent 051230: keep and reorder the enum value SUCCESS_E and FAILURE_E in avoid 
 * to confuse with the usage of kal_bool */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef enum
{
   FAILURE_E,       /* generic failure */
   SUCCESS_E        /* Command completed without errors */
} tReturnCode;

/* MACROS ******************************************************************************/

#define BITS_PER_BYTE   8

#ifdef MIN
#undef MIN
#endif
#define MIN(A,B) (((A)<(B))?(A):(B))

#ifdef MAX
#undef MAX
#endif
#define MAX(A,B) (((A)>(B))?(A):(B))

#define PUBLIC
#define PRIVATE   static

#define NOT_USED(x) (void)(x)

#define NOT_USED_FSM_PARAMETERS() \
      (void)(tReceivedMsg); \
      (void)(U32InterpretedEvent); \
      (void)(pU32State); \
      (void)(ptContext); \
      (void)(pSaved); \
      (void)(pReleaseMsg); \
      (void)(isSavedEvent);

#define SM_POPULATE_STATED_PROCESS(sm, offset, type)                  \
        eSM_PopulateProcessServiceSM(&(sm),                           \
                                     offset,                          \
                                     NUM_STATES_ ## type,             \
                                     NUM_EVENTS_ ## type,             \
                                     a ## type ## _StateTable,        \
                                     (kal_int8*)""#type"")

#define IS_VALID_ENTRY(checkParamPtr)              \
         (pContext != NULL) && (pState != NULL) && \
         ((checkParamPtr) == KAL_TRUE ? (pContext->pvParams != NULL) : KAL_TRUE)


/* Description: range checking macro.  Test if v is between min and
   max. Use this macro with contiguous enumerated types (see
   IS_WEEKEND macro example in contract_programming.h). */
/* Note: to avoid the following warning: comparison is always 1 due to limited 
 * range of data type. Don't use this IS_INRANGE just use (v <= max). */
#define IS_INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))

/* Description: valid pointer type checking macro.  Test if p is non
   null pointer. Note: a valid pointer always points on allocated
   memory. This is similar to the concept of references in C++. */
#define IS_VALID_PTR(p) ((p) != NULL)

#define IS_TBOOL(flag) ((flag == TRUE) || (flag == FALSE))

#define TT_ENTRY_SIZE  sizeof(tTranslateTableEntry)

#define mSM_ENTRY_FN(x) kal_bool x(struct tContext* pContext, kal_uint32* pState)

#define SM_PARAM(contextPtr, paramID)  (contextPtr)->ptCC->aSCIParams[(paramID)].U32ParamValue

//macro to initialise max process instance array
#define INIT_MAX_INSTANCES(component, array, processCount)  \
         {int i; for(i = 0; i < (processCount); i++){(component)->aMaxInstanceArray[i]=((array)[i]);}(component)->aMaxInstanceArray[i] = (array)[i];}

#define ALLOC_SEND_ILM(macro_src_mod, macro_dest_mod, macro_sap_id, macro_msg_id, macro_local_para_ptr, macro_peer_buff_ptr) \
    msg_send6((macro_src_mod), (macro_dest_mod), (macro_sap_id), (macro_msg_id), (local_para_struct *)(macro_local_para_ptr), (peer_buff_struct *)(macro_peer_buff_ptr))

/* Please notice that dhl_log_primitive6() will not free the local parameter and peer buffer, users should tack care about it by themself. */
#define ALLOC_LOG_ILM(macro_src_mod, macro_sap_id, macro_msg_id, macro_local_para_ptr) \
        dhl_log_primitive6((macro_src_mod), (MOD_DHL), (macro_sap_id), (macro_msg_id), (local_para_struct *)(macro_local_para_ptr), NULL)

#define MSG_CAST(ptr, msg, cast);                  \
         {                                         \
            ASSERT(msg->local_para_ptr != NULL);   \
            ptr = ( cast *)msg->local_para_ptr;    \
         }

#define UPLANE_TSTAMP(x)            //temporarily

#define UPLANE_BENCHMARK_TSTAMP(x)  //temporarily

#define CONFORMANCE_TSTAMP(x)       //temporarily

#define tReturn(x); {if (x == SUCCESS_E) return KAL_TRUE; else return KAL_FALSE;}

#define as_free_local_para_set_null(local_para) \
do { free_local_para((local_para_struct *)(local_para)); (local_para)=NULL; } while(0)

#define as_free_local_para_r_set_null(local_para) \
do { free_local_para_r((local_para_struct *)(local_para)); (local_para)=NULL; } while(0)

#define as_free_peer_buff_set_null(peer_buff) \
do { free_peer_buff((peer_buff_struct *)(peer_buff)); (peer_buff)=NULL; } while(0)

#define as_free_peer_buff_r_set_null(peer_buff) \
do { free_peer_buff_r((peer_buff_struct *)(peer_buff)); (peer_buff)=NULL; } while(0)

#define as_free_ctrl_buffer_set_null(ptr) \
do { free_ctrl_buffer(ptr); (ptr)=NULL; } while(0)

/* DHL api(dhl_internal_trace) parameter #2 is reserved, parameter #3 use MTK internal.
 * Redefine for coding convenience.
 */
#define uas_internal_trace(trc_class, msg_index, ...) \
dhl_internal_trace(trc_class, DHL_USER_FLAG_NONE, DHL_ACCESS_LEVEL_4_MTK_INTERNAL, \
                   msg_index, ##__VA_ARGS__)

#endif //__AS_COMMON_H__
