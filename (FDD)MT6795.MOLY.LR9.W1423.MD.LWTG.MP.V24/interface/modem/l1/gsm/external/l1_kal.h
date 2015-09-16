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
 * l1_kal.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Layer 1 system service adaption interface
 *
 * Author:
 * -------
 * -------
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
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _L1_KAL_H
#define _L1_KAL_H

#include "kal_public_api.h"
//#include "stack_ltlcom.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "md_sap.h"
#include "l1_gemini_def.h"

/* Maruco 20090108, for fix build error of L1 simulation for MONZA2G_GEMINI
 * For target load, codegen and build should not include stdlib.h
 * For MODIS/L1 simulation, codegen should not include stdlib.h 
 * but build should include it (GEN_FOR_PC is enabled when codegen) */
#ifndef GEN_FOR_PC
#ifndef __MTK_TARGET__
#include <stdlib.h>
#endif /* end of __MTK_TARGET__ */
#endif /* end of GEN_FOR_PC */

#ifdef DUMMY_PROTOCOL
#define MOD_MPAL              MOD_DUMMYMPAL
#endif

// Remove this because the definitions are put in kal_public_defs.h
//MT6280 GCC Porting : build in function
//#if defined(__MTK_TARGET__)
//#if defined (__ARMCC_VERSION)
//#define INLINE __inline
//#elif defined (__GNUC__)
//#define INLINE extern inline
//#endif /* ARMCC , GNUC */
//#else  /* __MTK_TARGET__ */
//#define INLINE __inline
//#endif /* __MTK_TARGET__ */

/*******************************************************************************
 * Destination queue id definition
 *******************************************************************************/
#if 0 /* elly */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define GS_QUEUE_LAYER_1      MOD_L1
#define GS_QUEUE_LAYER_2      MOD_MPAL
#define GS_QUEUE_RR           MOD_MPAL
#define GS_QUEUE_CB           MOD_MPAL /* should be supported in another file */
#define GS_QUEUE_RLCMAC       MOD_MPAL
#if !defined(__UNIFIED_ISR_LEVEL__)  
#define GS_QUEUE_L1HISR  MOD_L1HISR
#else
#define GS_QUEUE_L1HISR  MOD_LISR2HISR_CTIRQ1
#endif
#define GS_MAX_QUEUE          END_OF_MOD_ID
#if defined(__L1_GPS_REF_TIME_SUPPORT__) || defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__)
#define GS_QUEUE_GPS          MOD_GPS   /* Shihyao, add it to support GPS time sync procedure*/
#endif

#ifdef L1A_SIM_WO_TL1
#define GS_QUEUE_TL1          MOD_TL1
#endif /* L1A_SIM_WO_TL1 */

#if defined(__GL1_GEMINI__)
#define GS_QUEUE_LAYER_1_2      MOD_L1_2
#define GS_QUEUE_LAYER_2_2      MOD_MPAL_2
#define GS_QUEUE_RR_2           MOD_MPAL_2
#define GS_QUEUE_CB_2           MOD_MPAL_2 /* should be supported in another file */
#define GS_QUEUE_RLCMAC_2       MOD_MPAL_2
#define GS_QUEUE_RSVAS          MOD_RSVAS   /* Shihyao 20100315, add it becuase suspend procedure is handled by RSVAS instead of MPAL*/
#define GS_MAX_QUEUE_2          END_OF_MOD_ID

#if (GL1_GEMINI_NUM >= 3)
#define GS_QUEUE_LAYER_1_3      MOD_L1_3
#define GS_QUEUE_LAYER_2_3      MOD_MPAL_3
#define GS_QUEUE_RR_3           MOD_MPAL_3
#define GS_QUEUE_CB_3           MOD_MPAL_3 /* should be supported in another file */
#define GS_QUEUE_RLCMAC_3       MOD_MPAL_3
#define GS_MAX_QUEUE_3          END_OF_MOD_ID

#if (GL1_GEMINI_NUM >= 4)
#define GS_QUEUE_LAYER_1_4      MOD_L1_4
#define GS_QUEUE_LAYER_2_4      MOD_MPAL_4
#define GS_QUEUE_RR_4           MOD_MPAL_4
#define GS_QUEUE_CB_4           MOD_MPAL_4 /* should be supported in another file */
#define GS_QUEUE_RLCMAC_4       MOD_MPAL_4
#define GS_MAX_QUEUE_4          END_OF_MOD_ID
#endif /* end of (GL1_GEMINI_NUM >= 4) */

#endif /* end of (GL1_GEMINI_NUM >= 3) */

#else
#ifdef L1A_SIM
#define GS_QUEUE_RSVAS       MOD_RSVAS   /* Shihyao 20100315, add it becuase suspend procedure is handled by RSVAS instead of MPAL*/
#endif /* end of L1A_SIM */
#endif
#endif

/*******************************************************************************
 * L1 system service related MACRO definition
 *******************************************************************************/
 #if defined( __MTK_TARGET__) || defined(__UE_SIMULATOR__) || defined(__UL1_ON_MNT__) || defined(UNIT_TEST)

/*William 20120613 for ilm global passing */
#if defined( __MTK_TARGET__) || defined(__UE_SIMULATOR__)
extern ilm_struct l1_ilm_pool[]; 
#endif

/*******************************************************************************
 * Destination module id definition
 *******************************************************************************/
#define MOD_MPH_RR      MOD_MPAL
#define MOD_MPH_L2      MOD_MPAL
#define MOD_MPH_CB      MOD_MPAL
#define MOD_MPH_MAC     MOD_MPAL
#define MOD_MPH_L1      MOD_L1
#ifdef __MTK_TARGET__
#ifndef __L1_STANDALONE__
/*  Maruco20081223, add for using RF tool in engineering mode 
 *  L4C sends 4 new primitives(in em_sap.h) to L1A, 
 *  and L1A call L1C's function(in Rftool_types.h) to set parameters
 *  then L1C calls L1A's function to return primitive to MOD_UEM(module of L4C), 
 *  so L1A needs to define module(MOD_UEM) and EM(engineering mode)_SAP */
#define MOD_MPH_UEM   MOD_UEM
#endif /* end of __L1_STANDALONE__*/
#endif /* end of __MTK_TARGET__ */
#if defined(__L1_GPS_REF_TIME_SUPPORT__) || defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__)
/* Shihyao, add it to support GPS time sync procedure*/
#define MOD_MPH_GPS   MOD_GPS
#endif

/*Maruco20071024, define module of Slave*/
#if defined(__GL1_GEMINI__)
#define MOD_MPH_RR_2      MOD_MPAL_2
#define MOD_MPH_L2_2      MOD_MPAL_2
#define MOD_MPH_CB_2      MOD_MPAL_2
#define MOD_MPH_MAC_2     MOD_MPAL_2
#define MOD_MPH_L1_2      MOD_L1_2
#define MOD_MPH_RSVAS     MOD_RSVAS   /* Shihyao 20100315, add it becuase suspend procedure is handled by RSVAS instead of MPAL*/

#if (GL1_GEMINI_NUM >= 3)
#define MOD_MPH_RR_3      MOD_MPAL_3
#define MOD_MPH_L2_3      MOD_MPAL_3
#define MOD_MPH_CB_3      MOD_MPAL_3
#define MOD_MPH_MAC_3     MOD_MPAL_3
#define MOD_MPH_L1_3      MOD_L1_3

#if (GL1_GEMINI_NUM >= 4)
#define MOD_MPH_RR_4      MOD_MPAL_4
#define MOD_MPH_L2_4      MOD_MPAL_4
#define MOD_MPH_CB_4      MOD_MPAL_4
#define MOD_MPH_MAC_4     MOD_MPAL_4
#define MOD_MPH_L1_4      MOD_L1_4
#endif /* end of (GL1_GEMINI_NUM >= 4) */

#endif /* end of (GL1_GEMINI_NUM >= 3) */
#endif

/* elly, already defined in ul1_kal.h */
/* Joy 070401 for MONZA keep the definition*/
//#ifndef __MTK_UL1_FDD__
#define MOD_MPH_UL1     MOD_UL1 
//#define MOD_MPH_UL1HISR	MOD_UL1HISR
//#endif


/* After LISR2HISR, users of MOD_MPH_L1HISR: MOD_L1, MOD_LAPDM, MOD_FT  */

#if !defined(__UNIFIED_ISR_LEVEL__)  
#define MOD_MPH_L1HISR  MOD_L1HISR
#else
#define MOD_MPH_L1HISR  MOD_LISR2HISR_CTIRQ1
#endif

#define MOD_MPH_TL1     MOD_TL1

#define MOD_MPH_LL1     MOD_MLL1
/*******************************************************************************
 * Sap id definition
 *******************************************************************************/
#define MPH_L1_L1_SAP    L1_L1_SAP
#define MPH_L1_RR_SAP    L1_MPAL_SAP
#define MPH_RR_L1_SAP    MPAL_L1_SAP
#define MPH_L1_L2_SAP    L1_MPAL_SAP
#define MPH_L2_L1_SAP    MPAL_L1_SAP
#define MPH_L1_CB_SAP    L1_MPAL_SAP
#define MPH_CB_L1_SAP    MPAL_L1_SAP
#define MPH_L1_MAC_SAP   L1_MPAL_SAP
#define MPH_MAC_L1_SAP   MPAL_L1_SAP
#define MPH_UL1_L1_SAP   UL1_L1_SAP
#ifdef __UMTS_TDD128_MODE__
#define MPH_TL1_L1_SAP   TL1_LL1_SAP
#endif /*__UMTS_TDD128_MODE__*/

#define MPH_L1_LL1_SAP   L1_MLL1_SAP

#if defined(__GL1_GEMINI__)
#define MPH_L1_RSVAS_SAP   RSVAS_SAP   /* Shihyao 20100315, add it becuase suspend procedure is handled by RSVAS instead of MPAL*/
#endif

#if defined(__L1_GPS_REF_TIME_SUPPORT__) || defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__)
/* Shihyao, add it to support GPS time sync procedure*/
#define MPH_L1_GPS_SAP   GPS_L1_SAP
#endif

#ifdef __MTK_TARGET__
#ifndef __L1_STANDALONE__
/*  Maruco20081223, add for using RF tool in engineering mode 
 *  L4C sends 4 new primitives(in em_sap.h) to L1A, 
 *  and L1A call L1C's function(in Rftool_types.h) to set parameters
 *  then L1C calls L1A's function to return primitive to MOD_UEM(module of L4C), 
 *  so L1A needs to define module(MOD_UEM) and EM(engineering mode)_SAP */
#define MPH_L1_UEM_SAP   L1_EM_SAP
#endif /* end of __L1_STANDALONE__*/
#endif /* end of __MTK_TARGET__ */


extern INLINE void *L1_ALLOC_BUF(kal_uint32 byte_size) {
   void *buf_ptr = get_ctrl_buffer(byte_size);
   kal_mem_set(buf_ptr, 0, byte_size);
   return buf_ptr;
}

#define L1_FREE_BUF(buf)         free_ctrl_buffer(buf)

#define L1_OPEN_MESSAGE_QUEUE(queue) (KAL_SUCCESS)

/*William 20120613 for ilm global passing */
typedef enum
{    
    ilm_MOD_MPH_L1
#if defined(__GL1_GEMINI__)
    ,ilm_MOD_MPH_L1_2      
#if (GL1_GEMINI_NUM >= 3)
    ,ilm_MOD_MPH_L1_3   
#if (GL1_GEMINI_NUM >= 4)
    ,ilm_MOD_MPH_L1_4
#endif 
#endif 
#endif
    ,ilm_MOD_MPH_L1HISR
#ifdef __UMTS_FDD_MODE__
    ,ilm_MOD_MPH_UL1
#endif
#ifdef __UMTS_TDD128_MODE__
    ,ilm_MOD_MPH_TL1
#endif 
    ,ilm_POOL_SIZE  
} ENUM_ILM_ID;

extern INLINE void L1_SEND_MSG(module_type src_mod, module_type dest_mod, sap_type sap_id, ilm_struct *ilm_ptr) {
      if( ilm_ptr->local_para_ptr == NULL )
      	msg_send4( src_mod, dest_mod, sap_id, ilm_ptr->msg_id); 
      else 
      	msg_send5( src_mod, dest_mod, sap_id, ilm_ptr->msg_id, ilm_ptr->local_para_ptr); 
}

extern INLINE void L1_SEND_MSG_TO_NVRAM(module_type src_mod, module_type dest_mod, sap_type sap_id, ilm_struct *ilm_ptr) {
      	msg_send6( src_mod, dest_mod, sap_id, ilm_ptr->msg_id, ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr ); 
}

extern INLINE void LL1_SEND_MSG(module_type src_mod, module_type dest_mod, sap_type sap_id, ilm_struct *ilm_ptr) {
      if( ilm_ptr->local_para_ptr == NULL )
      	msg_send4( src_mod, dest_mod, sap_id, ilm_ptr->msg_id); 
      else 
      	msg_send5( src_mod, dest_mod, sap_id, ilm_ptr->msg_id, ilm_ptr->local_para_ptr); 
}

#define L1_RECV_MSG(ilm_ptr) \
       msg_receive_extq( ilm_ptr )
#if defined(__GL1_GEMINI__)
#define L1_RECV_MSG_2(ilm_ptr) \
      msg_receive_extq( ilm_ptr )
#if (GL1_GEMINI_NUM >= 3)
#define L1_RECV_MSG_3(ilm_ptr) \
      msg_receive_extq( ilm_ptr )
#if (GL1_GEMINI_NUM >= 4)
#define L1_RECV_MSG_4(ilm_ptr) \
      msg_receive_extq( ilm_ptr )
#endif /* end of (GL1_GEMINI_NUM >= 4) */
#endif /* end of (GL1_GEMINI_NUM >= 3) */
#endif

#define L1_FREE_MSG(ilm_ptr)  { destroy_ilm(ilm_ptr); }

#if defined( __MTK_TARGET__) || defined(__UE_SIMULATOR__)

/*William 20120613 for ilm global passing */
#define L1_ALLOC_MSG(mod_id, size) _L1_ALLOC_MSG(ilm_##mod_id, size)

//MT6280 GCC Porting
extern INLINE ilm_struct* _L1_ALLOC_MSG(module_type ilm_id, kal_uint16 size)
{
   ilm_struct *ilm_ptr;
   ilm_ptr = &l1_ilm_pool[ilm_id];
   if (size)
     ilm_ptr->local_para_ptr = construct_local_para(size, TD_RESET);
   else 
   	 ilm_ptr->local_para_ptr = NULL;
   return ilm_ptr;
}

#endif


#else /* for simulation */

extern ilm_struct simu_ilm_pool[];

typedef unsigned long  dword;        /* 4 byte variable */
typedef unsigned short word;         /* 2 byte variable */
typedef signed short sword;          /* 2 byte variable */
typedef unsigned char  boolean;      /* 1 byte variable */

/*******************************************************************************
 * Destination module id definition
 *******************************************************************************/
#define MOD_MPH_RR      GS_QUEUE_RR
#define MOD_MPH_L2      GS_QUEUE_LAYER_2
#define MOD_MPH_CB      GS_QUEUE_CB
#define MOD_MPH_MAC     GS_QUEUE_RLCMAC
#define MOD_MPH_L1      GS_QUEUE_LAYER_1
#define MOD_MPH_UL1     MOD_UL1 

#define MOD_MPH_LL1     MOD_MLL1

/*Maruco20071024, define module of Slave*/
#if defined(__GL1_GEMINI__)
#define MOD_MPH_RR_2      GS_QUEUE_RR_2
#define MOD_MPH_L2_2      GS_QUEUE_LAYER_2_2
#define MOD_MPH_CB_2      GS_QUEUE_CB_2
#define MOD_MPH_MAC_2     GS_QUEUE_RLCMAC_2
#define MOD_MPH_L1_2      GS_QUEUE_LAYER_1_2

#if (GL1_GEMINI_NUM >= 3)
#define MOD_MPH_RR_3      GS_QUEUE_RR_3
#define MOD_MPH_L2_3      GS_QUEUE_LAYER_2_3
#define MOD_MPH_CB_3      GS_QUEUE_CB_3
#define MOD_MPH_MAC_3     GS_QUEUE_RLCMAC_3
#define MOD_MPH_L1_3      GS_QUEUE_LAYER_1_3

#if (GL1_GEMINI_NUM >= 4)
#define MOD_MPH_RR_4      GS_QUEUE_RR_4
#define MOD_MPH_L2_4      GS_QUEUE_LAYER_2_4
#define MOD_MPH_CB_4      GS_QUEUE_CB_4
#define MOD_MPH_MAC_4     GS_QUEUE_RLCMAC_4
#define MOD_MPH_L1_4      GS_QUEUE_LAYER_1_4
#endif /* end of (GL1_GEMINI_NUM >= 4) */

#endif /* end of (GL1_GEMINI_NUM >= 3) */

#endif

#if defined(L1A_SIM) || defined(__GL1_GEMINI__)
#define MOD_MPH_RSVAS      MOD_RSVAS   /* Shihyao 20100315, add it becuase suspend procedure is handled by RSVAS instead of MPAL*/
#endif

#if defined(__L1_GPS_REF_TIME_SUPPORT__) || defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__)
/* Shihyao, add it to support GPS time sync procedure*/
#define MOD_MPH_GPS   GS_QUEUE_GPS
#endif

/* elly, already defined in ul1_kal.h */
//#define MOD_MPH_UL1     GS_QUEUE_UL1
#if 0 /* elly */
/* under construction !*/
#else
#define MOD_MPH_L1HISR  GS_QUEUE_L1HISR
#endif

/*******************************************************************************
 * Sap id definition
 *******************************************************************************/
#define MPH_L1_L1_SAP    L1_L1_SAP
#define MPH_L1_RR_SAP    L1_MPAL_SAP
#define MPH_RR_L1_SAP    MPAL_L1_SAP
#define MPH_L1_L2_SAP    L1_MPAL_SAP
#define MPH_L2_L1_SAP    MPAL_L1_SAP
#define MPH_L1_CB_SAP    L1_MPAL_SAP
#define MPH_CB_L1_SAP    MPAL_L1_SAP
#define MPH_L1_MAC_SAP   L1_MPAL_SAP
#define MPH_MAC_L1_SAP   MPAL_L1_SAP
#define MPH_UL1_L1_SAP   UL1_L1_SAP
#ifdef __UMTS_TDD128_MODE__// for pass compile
#define MPH_TL1_L1_SAP   TL1_MLL1_SAP
#define MPH_L1_TL1_SAP   TL1_MLL1_SAP  //for TD half simulation
#endif /*__UMTS_TDD128_MODE__*/

#define MPH_L1_LL1_SAP   L1_MLL1_SAP


#if defined(L1A_SIM) || defined(__GL1_GEMINI__)
#define MPH_L1_RSVAS_SAP   RSVAS_SAP   /* Shihyao 20100315, add it becuase suspend procedure is handled by RSVAS instead of MPAL*/
#endif

#if defined(__L1_GPS_REF_TIME_SUPPORT__) || defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__)
/* Shihyao, add it to support GPS time sync procedure*/
#define MPH_L1_GPS_SAP   GPS_L1_SAP
#endif

extern kal_status gs_open_message_queue(module_type);
extern void script_send_message(module_type, void *, kal_bool);
extern void script_send_message_byMod(const int dest_mod, void *msg, kal_bool wait);
extern kal_status gs_send_message(module_type, void *, kal_bool);
extern kal_status gs_read_message(module_type, void *, kal_uint16, kal_bool);


extern INLINE void *L1_ALLOC_BUF(kal_uint32 byte_size) {
   void *buf_ptr = malloc(byte_size);
   memset(buf_ptr, 0, byte_size);
   return buf_ptr;
}


#define L1_FREE_BUF(buf)         free(buf)

#define L1_OPEN_MESSAGE_QUEUE(queue) \
      gs_open_message_queue((queue))

#ifndef __UE_SIMULATOR__
#if 1 //(defined L1A_SIM)
#define L1_SEND_MSG(src_mod, dest_mod, sap, ilm_ptr) \
      ilm_ptr->src_mod_id  = src_mod;  \
      ilm_ptr->dest_mod_id = dest_mod; \
	  ilm_ptr->sap_id  = sap;  \
      gs_send_message((module_type)dest_mod, (void*)ilm_ptr, true);

#define LL1_SEND_MSG L1_SEND_MSG /* elly */

#else /* L1A_SIM */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* L1A_SIM */

#define L1_RECV_MSG(ilm_ptr) \
      gs_read_message(GS_QUEUE_LAYER_1, ilm_ptr, sizeof(ilm_struct), true)
#if defined(__GL1_GEMINI__)
#define L1_RECV_MSG_2(ilm_ptr) \
      gs_read_message(GS_QUEUE_LAYER_1_2, ilm_ptr, sizeof(ilm_struct), true)
#if (GL1_GEMINI_NUM >= 3)
#define L1_RECV_MSG_3(ilm_ptr) \
      gs_read_message(GS_QUEUE_LAYER_1_3, ilm_ptr, sizeof(ilm_struct), true)
#if (GL1_GEMINI_NUM >= 4)
#define L1_RECV_MSG_4(ilm_ptr) \
      gs_read_message(GS_QUEUE_LAYER_1_4, ilm_ptr, sizeof(ilm_struct), true)
#endif /* end of (GL1_GEMINI_NUM >= 4) */
#endif /* end of (GL1_GEMINI_NUM >= 3) */
#endif

#endif //__UE_SIMULATOR__

#define L1_FREE_MSG(ilm_ptr)  if ((ilm_ptr)->src_mod_id != MOD_TIMER)  free(ilm_ptr.local_para_ptr[0])

//MT6280 GCC Porting
extern INLINE ilm_struct* L1_ALLOC_MSG(module_type mod_id, kal_uint32 size)
{
   ilm_struct *ilm_ptr;

   ilm_ptr = &simu_ilm_pool[mod_id];
   
   if (size == 0)
       size = 4; 

   {
      ilm_ptr->local_para_ptr = (local_para_struct *) malloc(size);
      memset(ilm_ptr->local_para_ptr, 0, size);
      ilm_ptr->local_para_ptr->msg_len = size;
   }
   return ilm_ptr;
}

#endif /* __MTK_TARGET__ */

#endif /* _L1_KAL_H */


