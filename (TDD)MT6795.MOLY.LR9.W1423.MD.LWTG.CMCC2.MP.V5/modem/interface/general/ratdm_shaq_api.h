/******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * --------------------------------------------------------
 *   ratdm_shaq_api.h
 *
 * Project:
 * --------------------------------------------------------
 *   
 *
 * Description:
 * --------------------------------------------------------
 *   
 *
 * Author:
 * --------------------------------------------------------
 * -------
 *
 * --------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * __NDIS_SUPPORT__ related code removal
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Integration change.
 *
 * removed!
 * removed!
 * LOCAL_PARA_HDR/PEER_BUF_HDR modification
 * 
 * removed!
 * removed!
 * 
 * Remove stack_ltlcom.h
 * 
 * removed!
 * removed!
 * modem related option move to modem internal
 * 
 * removed!
 * removed!
 * [uas]URLC TM queue switchable modification
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * decide not to use mutex, decide to use lock IRQ to replace change_priority
 *
 *
 * removed!
 * removed!
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * <saved by Perforce>
 *
 * 
 ******************************************************************************/

#ifndef _RATDM_SHAQ_API_H
#define _RATDM_SHAQ_API_H

#include "ratdm_shaq_application_api.h"

#ifdef __RATDM_UL_SHAQ__

#include "kal_general_types.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "l3_inc_local.h"

#ifdef __GEMINI__
#include "sim_common_enums.h"
#endif

#include "mmi_l3_enums.h"
#include "kal_public_api.h"
//#include "ratdm_trc.h"
#include "ps_ratdm_struct.h"
#include "global_def.h"

/* Buffer Management */
#include "flc2_ent_functions.h"

#include "l3_inc_enums.h"
#include "mmi_l3_enums.h"
#include "mcd_l3_inc_struct.h"
//#include "ratdm_context.h"
//#include "ratdm_utils.h"
//#include "ratdm_main.h"

#ifdef __DIALUP_GPRS_COUNTER_SUPPORT__
#include "l4c_ratdm_struct.h"
#endif

#ifdef __UMTS_RAT__
//#include "ratdm_rabm_struct.h"
#endif

#ifdef __UMTS_RAT__
#include "uas_common_enums.h"
#endif // ~ #ifdef __UMTS_RAT__


typedef struct ratdm_shaq_print_ps_q_element_struct
{
    LOCAL_PARA_HDR
    
    kal_uint16   pdu_len;
    kal_uint8    ref_count_2;
    kal_uint8    pb_resvered;
    kal_uint16   free_header_space;
    kal_uint16   free_tail_space;

    
    struct SHAQ_qElmtHeader *next_shaqElmt;   
    kal_uint8   pool_id;
    kal_uint8   context_id;
    kal_uint8   nsapi;
    kal_bool    bConfirm;   /* new parts */

    kal_uint16  npdu_num;
    kal_uint16  ori_free_header_space;

    kal_uint8   TxRBId;     /* new parts */
    kal_uint8   ap_enqueue_decision; // SHAQ_ENQUEUE_WHICH_QUEUE enum
    kal_uint16 bitLength; /*new parts*/ 
    kal_uint32 MUI; /*new parts*/ 
    struct ratdm_ps_data_req_struct_tag *next;

}ratdm_shaq_print_ps_q_element_struct;

#ifdef __UMTS_RAT__
typedef struct {
    LOCAL_PARA_HDR
    
    // below elements are the same as SHAQ_csr_data_req_struct
    kal_uint16   pdu_len;
    kal_uint8    ref_count_2;
    kal_uint8    pb_resvered;
    kal_uint16   free_header_space;
    kal_uint16   free_tail_space;

    void *next_shaqElmt; 

    kal_uint16      bitLength;    
    kal_uint16      frame_index;
                
    ExtendedRbId    RBId;
    kal_bool       queued_enabled;
    kal_uint16      dummy;
} ratdm_shaq_print_cs_q_element_struct;
#endif // ~ #ifdef __UMTS_RAT__

#ifndef __UMTS_RAT__
#define LAST_EXTENDED_RB_ID (32)  //refer to uas_common_enums.h
#endif // ~ #ifndef __UMTS_RAT__

//#define __SHAQ_MINIMUM_LEVEL_GUARD_PATTERN_CHECK__ // can be turn off
//#define __SHAQ_MAXIMUM_LEVEL_GUARD_PATTERN_CHECK__ // can be turn off

#if defined (__SHAQ_MAXIMUM_LEVEL_GUARD_PATTERN_CHECK__) || defined (__SHAQ_MINIMUM_LEVEL_GUARD_PATTERN_CHECK__)
#define __SHAQ_GUARD_PATTERN_CHECK__
#endif // ~ #if defined (__SHAQ_MAXIMUM_LEVEL_GUARD_PATTERN_CHECK__) || defined (__SHAQ_MINIMUM_LEVEL_GUARD_PATTERN_CHECK__)

#define SHAQ_32BIT_GUARD_PATTERN (0x7D7E7D7E)
#define SHAQ_16BIT_GUARD_PATTERN (0x7D7E)
#define SHAQ_8BIT_GUARD_PATTERN (0x7D)
#define SHAQ_REASONABLE_MAXIMUM_SDU_SIZE MAX_VAL((MAX_L2_EXTERNAL_SDU_SIZE), 1520)

/*
    3 ways to protest the queue
        1. lock interrupt
         kal_uint32 savedIRQMask;
         savedIRQMask = SaveAndSetIRQMask();
         RestoreIRQMask(savedIRQMask);
        2. Disable scheduler
        3. change priority to equal to UL2 task
*/

#define M_SHAQ_IN_CRITICAL_ZONE(taskid,orig_prio) M_SHAQ_IN_CRITICAL_ZONE_USING_LOCK_IRQ()
#define M_SHAQ_OUT_CRITICAL_ZONE(taskid,orig_pri) M_SHAQ_OUT_CRITICAL_ZONE_USING_LOCK_IRQ()

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // ~ #if 0

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // ~ #if 0

#define M_SHAQ_IN_CRITICAL_ZONE_USING_LOCK_IRQ() \
    savedIRQMask = SaveAndSetIRQMask();

#define M_SHAQ_OUT_CRITICAL_ZONE_USING_LOCK_IRQ() \
    RestoreIRQMask(savedIRQMask);


#define M_SHAQ_LOGGER(p) 
// TODO: implement
#define M_SHAQ_PRINT(X) 
// TODO: implement
#define M_SHAQ_SAP NULL
// TODO: implement?

#define MAX_CS_TM_Q_NUM (3)
#define MAX_CS_UM_Q_NUM (1)

#define M_SHAQ_ASSERT(X) ASSERT(X)
#define M_SHAQ_DEBUG_ASSERT(X) ASSERT(X) // TODO: this configuration can be turned off
#define M_SHAQ_MAX_Q_SIZE   ((PS_TOT_NSAPI_NUM)+((MAX_CS_TM_Q_NUM)+(MAX_CS_UM_Q_NUM))+(1))
#define M_SHAQ_MINIMUM_CONTEXT_ID (1)
#define M_SHAQ_MAXIMUM_CONTEXT_ID ((PS_TOT_NSAPI_NUM)+((MAX_CS_TM_Q_NUM)+(MAX_CS_UM_Q_NUM)))

#define M_MIN_PS_SHAQ_NUMBER (M_SHAQ_MINIMUM_CONTEXT_ID)
#define M_MAX_PS_SHAQ_NUMBER (PS_TOT_NSAPI_NUM)
#define M_MIN_CS_SHAQ_NUMBER ((M_MAX_PS_SHAQ_NUMBER)+(1))
#define M_MAX_CS_SHAQ_NUMBER (M_SHAQ_MAXIMUM_CONTEXT_ID)

#define M_MIN_PS_CONTEXT_ID (M_MIN_PS_SHAQ_NUMBER)
#define M_MAX_PS_CONTEXT_ID (M_MAX_PS_SHAQ_NUMBER)
#define M_MIN_CS_CONTEXT_ID (M_MIN_CS_SHAQ_NUMBER)
#define M_MAX_CS_CONTEXT_ID (M_MAX_CS_SHAQ_NUMBER)

#define M_SHAQ_CS_TM_Q_NUM_1 (M_MIN_CS_CONTEXT_ID)
#define M_SHAQ_CS_TM_Q_NUM_2 ((M_MIN_CS_CONTEXT_ID)+(1))
#define M_SHAQ_CS_TM_Q_NUM_3 ((M_MIN_CS_CONTEXT_ID)+(2))
#define M_SHAQ_CS_UM_Q_NUM       (M_MAX_CS_CONTEXT_ID)

#define M_SHAQ_MAX_NSAPI (15)
#define M_SHAQ_SOCKET_NSAPI_ARRAY_SIZE ((M_SHAQ_MAX_NSAPI)+((MAX_CS_TM_Q_NUM)+(MAX_CS_UM_Q_NUM))+(1))
#define M_SHAQ_SOCKET_CID_ARRAY_SIZE ((M_SHAQ_MAXIMUM_CONTEXT_ID)+(1))
#define M_SHAQ_SOCKET_RBID_ARRAY_SIZE ((LAST_EXTENDED_RB_ID)+(1))


#define M_SHAQ_FIND_Q_USING_CID(qPtr, cid) \
                           qPtr = &(RATDM_SHAQ[cid]); \

#define M_SHAQ_PRINT_SHAQ_CONTENT(ap_Queue) SHAQ_int_print_queue (ap_Queue)
#define M_SHAQ_RECORD_SHAQ_IMPORTANT_CONTENT(ap_Queue) SHAQ_int_record_important_queue (ap_Queue)
#define M_SHAQ_PRINT_SHAQ_IMPORTANT_CONTENT(ap_Queue,queue_idx,cid_for_logging) SHAQ_int_print_important_queue (ap_Queue,queue_idx,cid_for_logging)
#if defined (__SHAQ_MAXIMUM_LEVEL_GUARD_PATTERN_CHECK__) || defined (__SHAQ_MINIMUM_LEVEL_GUARD_PATTERN_CHECK__)
#define M_SHAQ_INIT_Q_GUARD_PATTERN(ap_Queue) SHAQ_int_init_q_guard_pattern(ap_Queue)
#define M_SHAQ_CHECK_Q_GUARD_PATTERN(ap_Queue) SHAQ_int_check_q_guard_pattern(ap_Queue)
#define M_SHAQ_INIT_SOCKET_GUARD_PATTERN() SHAQ_int_init_socket_guard_pattern()
#define M_SHAQ_CHECK_SOCKET_GUARD_PATTERN() SHAQ_int_check_socket_guard_pattern()
#define M_SHAQ_DOUBLE_CHECK_QUEUE_ELEMENT_NUMBERS_CONSISTENCY(ap_Queue) SHAQ_int_double_check_queue_element_numbers_consistency(ap_Queue)
#else
#define M_SHAQ_INIT_Q_GUARD_PATTERN(ap_Queue) 
#define M_SHAQ_CHECK_Q_GUARD_PATTERN(ap_Queue) 
#define M_SHAQ_INIT_SOCKET_GUARD_PATTERN() 
#define M_SHAQ_CHECK_SOCKET_GUARD_PATTERN() 
#define M_SHAQ_DOUBLE_CHECK_QUEUE_ELEMENT_NUMBERS_CONSISTENCY(ap_Queue) 
#endif

#define M_SHAQ_PRINT_RB_NSAPI_CID_TABLE() SHAQ_int_print_rb_nsapi_cid_table()

#define SHAQ_psProcessOneCTrackPkt(X,Y) 

#ifdef __RATDM_UT__
#define RATDM_SHAQ_CALL_FLC_FREE(X,Y) kal_brief_trace(TRACE_GROUP_1, RATDM_SHAQ_FAKE_FLC_FREE_IN_UT, X, Y)
#else // #ifdef __RATDM_UT__
#define RATDM_SHAQ_CALL_FLC_FREE(X,Y) flc2_free_peer_buff(X,Y)
#endif // ~ #ifdef __RATDM_UT__

#ifdef __MTK_TARGET__
#define RATDM_GET_BITS(_uc, _s, _w) GET_BITS(_uc, _s, _w)
#else
#define RATDM_GET_BITS(_uc, _s, _w) get_bits(_uc, _s, _w)
#endif

/*
#define M_SHAQ_ELMT_HEADER \
	    PEER_BUFF_HDR \
            SHAQ_qElmtHeader* next_shaqElmt;           
*/

/* memory free function */
typedef void (*pShaqFuncFree) (kal_uint8*);

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
#endif

#ifdef __UMTS_RAT__
/* for CS only */
typedef struct
{
    /* Dont touch this part */
    //M_SHAQ_ELMT_HEADER    
	    PEER_BUFF_HDR
            struct SHAQ_qElmtHeader *next_shaqElmt; 

    /* Hands off please */
		
    kal_uint16      bitLength;    
    kal_uint16      frame_index;
            
    ExtendedRbId    RBId;
    kal_bool        queued_enabled;
    kal_uint16      dummy;
    
} SHAQ_csr_data_req_struct;
#endif //~#ifdef __UMTS_RAT__

typedef struct
{
    #ifdef __SHAQ_MINIMUM_LEVEL_GUARD_PATTERN_CHECK__
        kal_uint32        shareQMinLvlGuardPattern1;
    #endif // ~ #ifdef __SHAQ_MINIMUM_LEVEL_GUARD_PATTERN_CHECK__

    /* Main Queue */
    kal_uint32        m_qCount; 
    kal_uint32        m_qDataQuantity; /* In BITs */
    #ifdef __SHAQ_MAXIMUM_LEVEL_GUARD_PATTERN_CHECK__
        kal_uint32        shareQMaxLvlGuardPattern1;
    #endif // ~ #ifdef __SHAQ_MAXIMUM_LEVEL_GUARD_PATTERN_CHECK__
    struct SHAQ_qElmtHeader *mp_tail;
    #ifdef __SHAQ_MAXIMUM_LEVEL_GUARD_PATTERN_CHECK__
        kal_uint32        shareQMaxLvlGuardPattern2;
    #endif // ~ #ifdef __SHAQ_MAXIMUM_LEVEL_GUARD_PATTERN_CHECK__
    struct SHAQ_qElmtHeader  m_sentinel;  
    #ifdef __SHAQ_MAXIMUM_LEVEL_GUARD_PATTERN_CHECK__
        kal_uint32        shareQMaxLvlGuardPattern3;
    #endif // ~ #ifdef __SHAQ_MAXIMUM_LEVEL_GUARD_PATTERN_CHECK__

} SHAQ_linkListQEntity;

#ifdef __RATDM_SHAQ_HAS_PRIORITY_QUEUE__
typedef enum
{
    SHAQ_PRIORITY_QUEUE,
    SHAQ_NORMAL_QUEUE,
    SHAQ_NUMBER_OF_LINKED_LIST_QUEUE_FOR_A_RB
} SHAQ_LLQUEUE_IDX;
#else // #ifdef __RATDM_SHAQ_HAS_PRIORITY_QUEUE__
typedef enum
{
    SHAQ_NORMAL_QUEUE,
    SHAQ_PRIORITY_QUEUE = SHAQ_NORMAL_QUEUE,
    SHAQ_NUMBER_OF_LINKED_LIST_QUEUE_FOR_A_RB
} SHAQ_LLQUEUE_IDX;

#endif // ~ #ifdef __RATDM_SHAQ_HAS_PRIORITY_QUEUE__


typedef struct
{
    SHAQ_linkListQEntity ll_queue[SHAQ_NUMBER_OF_LINKED_LIST_QUEUE_FOR_A_RB];
    pShaqFuncFree mpf_free;     /* free function */
        #ifdef __SHAQ_MAXIMUM_LEVEL_GUARD_PATTERN_CHECK__
        kal_uint32        shareQMaxLvlGuardPattern4;
        #endif // ~ #ifdef __SHAQ_MAXIMUM_LEVEL_GUARD_PATTERN_CHECK__

    //kal_uint16  m_cTrackCount;  /* the count of current cTrack data (inc: PPP) (dec: PDCP) */
    //    #ifdef __SHAQ_MAXIMUM_LEVEL_GUARD_PATTERN_CHECK__
    //    kal_uint16        shareQMaxLvlGuardPattern5;
    //    #endif // ~ #ifdef __SHAQ_MAXIMUM_LEVEL_GUARD_PATTERN_CHECK__

    kal_bool    m_isShaqInitiated;  /* Used to identify if Q is ready, for RLC to know if it need to check this Q or not */

        #ifdef __SHAQ_MINIMUM_LEVEL_GUARD_PATTERN_CHECK__
        kal_uint8        shareQMinLvlGuardPattern2;
        #endif // ~ #ifdef __SHAQ_MINIMUM_LEVEL_GUARD_PATTERN_CHECK__

} SHAQ_qEntity;

typedef struct rb_nsapi_cid_mapping_arrays_struct
{
        #ifdef __SHAQ_MINIMUM_LEVEL_GUARD_PATTERN_CHECK__
        kal_uint8        socketMinLvlGuardPattern11;
        #endif // ~ #ifdef __SHAQ_MINIMUM_LEVEL_GUARD_PATTERN_CHECK__
    kal_uint8 CID_nsapi_map[M_SHAQ_SOCKET_CID_ARRAY_SIZE];
        #ifdef __SHAQ_MINIMUM_LEVEL_GUARD_PATTERN_CHECK__
        kal_uint8        socketMinLvlGuardPattern12;
        #endif // ~ #ifdef __SHAQ_MINIMUM_LEVEL_GUARD_PATTERN_CHECK__
    kal_uint8 nsapi_CID_map[M_SHAQ_SOCKET_NSAPI_ARRAY_SIZE];
        #ifdef __SHAQ_MINIMUM_LEVEL_GUARD_PATTERN_CHECK__
        kal_uint8        socketMinLvlGuardPattern13;
        #endif // ~ #ifdef __SHAQ_MINIMUM_LEVEL_GUARD_PATTERN_CHECK__
    kal_uint8 RBId_nsapi_map[M_SHAQ_SOCKET_RBID_ARRAY_SIZE];
        #ifdef __SHAQ_MINIMUM_LEVEL_GUARD_PATTERN_CHECK__
        kal_uint8        socketMinLvlGuardPattern14;
        #endif // ~ #ifdef __SHAQ_MINIMUM_LEVEL_GUARD_PATTERN_CHECK__
    kal_uint8 nsapi_RBId_map[M_SHAQ_SOCKET_NSAPI_ARRAY_SIZE];
        #ifdef __SHAQ_MINIMUM_LEVEL_GUARD_PATTERN_CHECK__
        kal_uint8        socketMinLvlGuardPattern15;
        #endif // ~ #ifdef __SHAQ_MINIMUM_LEVEL_GUARD_PATTERN_CHECK__
    kal_bool RBId_already_occupied_by_lbm[M_SHAQ_SOCKET_RBID_ARRAY_SIZE]; // this is to remember if certain RB is occupied by LBM
}rb_nsapi_cid_mapping_arrays_struct;

typedef struct ratdm_shaq_trace_data_for_a_llq{
    kal_uint32        m_qCount; 
    kal_uint32        m_qDataQuantity; /* In BITs */
}ratdm_shaq_trace_data_for_a_llq;

typedef struct ratdm_shaq_trace_data_temp_buffer{
    SHAQ_qEntity *ap_Queue;
    SHAQ_qElmtHeader *ap_qElmt;
    ratdm_shaq_trace_data_for_a_llq llq_trace_info[SHAQ_NUMBER_OF_LINKED_LIST_QUEUE_FOR_A_RB];
    kal_uint16 ip_id;
    SHAQ_LLQUEUE_IDX queue_idx;
}ratdm_shaq_trace_data_temp_buffer;

/* Structure */
// IPv4 Header
#define RATDM_IPV4_UPPER_LAYER_PROTOCOL_OFFSET (9)
#define RATDM_IPV4_UPPER_LAYER_PROTOCOL_TCP (6)
#define RATDM_IPV4_UPPER_LAYER_PROTOCOL_UDP (17)
#define RATDM_TCP_ACK_POSITION_OFFSET (13)
// IPv6 Header
#define RATDM_IPV6_FIRST_NEXT_HEADER_OFFSET (6)
#define RATDM_IPV6_NEXT_HEADER_TCP (6)
#define RATDM_IPV6_NO_EXT_HDR_HEADER_LENGTH (40)
// Judge TCP ACK
#ifdef __IPV6__
 #ifdef __PPP_TYPE_PDP_DIALUP_SUPPORT__
  #define REASONABLE_TCP_ACK_PKT_SIZE (62)
 #else // __PPP_TYPE_PDP_DIALUP_SUPPORT__
  #define REASONABLE_TCP_ACK_PKT_SIZE (60)
 #endif // ~ __PPP_TYPE_PDP_DIALUP_SUPPORT__
#else // #ifdef __IPV6__
 #ifdef __PPP_TYPE_PDP_DIALUP_SUPPORT__
  #define REASONABLE_TCP_ACK_PKT_SIZE (42)
 #else // __PPP_TYPE_PDP_DIALUP_SUPPORT__
  #define REASONABLE_TCP_ACK_PKT_SIZE (40)
 #endif // ~ __PPP_TYPE_PDP_DIALUP_SUPPORT__
#endif // ~ #ifdef __IPV6__

#ifdef __RATDM_UT__
#define NEED_TO_BE_CHECKED_PKT_SIZE (99)
#else // #ifdef __RATDM_UT__
#define NEED_TO_BE_CHECKED_PKT_SIZE ((REASONABLE_TCP_ACK_PKT_SIZE)+(16)) // 16 is a RD decided buffer value and can be adjusted based on observed TCP ACK size distributions
#endif // ~ #ifdef __RATDM_UT__

/* public APIs */
#ifdef __UMTS_RAT__
#ifdef UNIT_TEST
void SHAQ_RLC_UT_enqueue (SHAQ_qEntity *ap_Queue, struct SHAQ_qElmtHeader *ap_qElmt, SHAQ_LLQUEUE_IDX queue_idx);
struct SHAQ_qElmtHeader* SHAQ_RLC_UT_dequeue (SHAQ_qEntity *ap_queue, SHAQ_LLQUEUE_IDX queue_idx);
#ifdef __RATDM_SHAQ_HAS_PRIORITY_QUEUE__    
struct SHAQ_qElmtHeader* SHAQ_RLC_UT_dequeue_priority_queue (ExtendedRbId RbId, kal_uint32 *queue_left_bits);
#endif
struct SHAQ_qElmtHeader* SHAQ_RLC_UT_dequeue_normal_queue (ExtendedRbId RbId, kal_uint32 *queue_left_bits);
#endif // ~ #ifdef UNIT_TEST
#endif //~#ifdef __UMTS_RAT__

void SHAQ_bootup(void);
#ifdef __UMTS_RAT__
void SHAQ_mountFreeFunc (kal_uint8 a_cid, pShaqFuncFree apf_free);
pShaqFuncFree SHAQ_queryFreeFunc(ExtendedRbId RbId);
kal_uint8 SHAQ_getCidFromRbid(ExtendedRbId RbId, kal_taskid taskid);
kal_uint8 SHAQ_rlcGetCidFromRbid(ExtendedRbId RbId);
#ifdef __RATDM_SHAQ_HAS_PRIORITY_QUEUE__    
kal_uint32 SHAQ_rlcQueryPriorityQueueLeftBits(ExtendedRbId RbId);
#endif // ~ #ifdef __RATDM_SHAQ_HAS_PRIORITY_QUEUE__    
kal_uint32 SHAQ_rlcQueryNormalQueueLeftBits(ExtendedRbId RbId);
SHAQ_qEntity* SHAQ_rlcFindQFromCid(kal_uint8 cid);
SHAQ_qElmtHeader* SHAQ_dequeue_diff_priority_queue (kal_uint8 a_txRbId, kal_uint32 * queue_left_bits, SHAQ_LLQUEUE_IDX priority);
#define SHAQ_dequeue_normal_queue(RB,LEFT_BITS) SHAQ_dequeue_diff_priority_queue(RB,LEFT_BITS,SHAQ_NORMAL_QUEUE)
#ifdef __RATDM_SHAQ_HAS_PRIORITY_QUEUE__
#define SHAQ_dequeue_priority_queue(RB,LEFT_BITS) SHAQ_dequeue_diff_priority_queue(RB,LEFT_BITS,SHAQ_PRIORITY_QUEUE)
#endif // ~ #ifdef __RATDM_SHAQ_HAS_PRIORITY_QUEUE_
SHAQ_qElmtHeader* SHAQ_dequeue (kal_uint8 a_txRbId);
SHAQ_retCode SHAQ_psPdcpEnqueue (ExtendedRbId RbId, SHAQ_qElmtHeader* pPeer, kal_taskid taskid);
#endif //~#ifdef __UMTS_RAT__
//void SHAQ_psProcessOneCTrackPkt (kal_uint8 a_cid, kal_taskid taskid);
#define SHAQ_psEnqueue(PEER,POOL,CID,TASK_ID) SHAQ_psEnqueueWithPriorityInfo(PEER,POOL,CID,TASK_ID,SHAQ_ENQUEUE_DECIDED_BY_SHAQ_API)
void SHAQ_psFillCidNsapiMapping(kal_uint8 CID, kal_uint8 nsapi);
void SHAQ_psEraseCidNsapiMapping(kal_uint8 nsapi);
void SHAQ_psFillRBIdNsapiMapping(kal_uint8 RBId, kal_uint8 nsapi);
void SHAQ_psEraseRBIdNsapiMapping(kal_uint8 RBId);
void SHAQ_psFillRBIdRABIdMapping(kal_uint8 RBId, kal_uint8 RABId);
void SHAQ_psEraseRBIdRABIdMapping(kal_uint8 RBId);
void SHAQ_change_turn_off_priority_queue_setting(kal_bool new_setting);
#ifdef __UMTS_RAT__
SHAQ_retCode SHAQ_csCsrEnqueue (kal_uint8 a_cid, SHAQ_qElmtHeader* ap_data);
void SHAQ_csRBestablished(kal_uint8 CID, kal_uint8 RBId);
void SHAQ_csRBreleased(kal_uint8 RBId);
kal_uint8 SHAQ_LBM_CreateRB(kal_uint8 RBId);
kal_bool SHAQ_LBM_ReleaseRB(kal_uint8 RBId);

#if defined(__UMTS_TDD128_MODE__) && defined(__REL7__)
kal_bool SHAQ_check_pdp_rab_state(kal_uint16 nsapi);
#endif

#ifdef UNIT_TEST
kal_uint8 SHAQ_RLC_UT_CreateRB(kal_uint8 RBId);
kal_bool SHAQ_RLC_UT_ReleaseRB(kal_uint8 RBId);
#endif // ~ #ifdef UNIT_TEST
void SHAQ_csKickUL2(module_type source_module);
void SHAQ_psKickUL2(module_type source_module, ExtendedRbId RbId);
#ifndef __MTK_TARGET__
void SHAQ_csr_ut_check_queue_context(kal_uint8 a_cid, module_type ut_module);
void SHAQ_pdcp_ut_check_queue_context_with_priority_info(ExtendedRbId RbId, module_type ut_module, SHAQ_LLQUEUE_IDX priority);
#define SHAQ_pdcp_ut_check_queue_context(RB,MODULE) SHAQ_pdcp_ut_check_queue_context_with_priority_info(RB,MODULE,SHAQ_NORMAL_QUEUE);
#endif // ~ #ifndef __MTK_TARGET__

#ifdef __RATDM_UT__
void SHAQ_fake_free_buff_func(kal_uint8 * pBuffer);
void SHAQ_test1(void);
void SHAQ_test2(void);
#endif // ~ #ifdef __RATDM_UT__

#endif //~#ifdef __UMTS_RAT__

#endif // ~ #ifdef __RATDM_UL_SHAQ__

#endif /* _RATDM_SHAQ_API_H */
