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
 * med_global.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary global definitions of media task.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _MED_GLOBAL_H
#define _MED_GLOBAL_H

#if !defined(MED_MEM_CHECK)
   #include "kal_general_types.h"
   #include "kal_public_defs.h"
   #include "kal_public_api.h"
#endif

#define MAXOF(a,b) (((a)>(b))? (a):(b))
#define MINOF(a,b) (((a)<(b))? (a):(b))

#ifdef __ECALL_SUPPORT__
   #define __MED_ECALL_MOD__
#endif

#define  AUD_IDLE  0


/******************************************************
 * 1. Feature
 ******************************************************/
/* CTM */
#if defined(__MED_CTM_MOD__)
   //#define AUD_MED_CTM_EXT_MEM_SIZE (9*1024)  /* Actual: 8184(Driver) + 61(MED) bytes */
   #define AUD_MED_CTM_EXT_MEM_SIZE (0)
#else
   #define AUD_MED_CTM_EXT_MEM_SIZE (0)
#endif

/* eCall Modem */
#if defined(__ECALL_PSAP_SUPPORT__)
   #define AUD_MED_ECALL_EXT_MEM_SIZE (33*1024)
#elif defined(__ECALL_SUPPORT__)
   #define AUD_MED_ECALL_EXT_MEM_SIZE (13*1024)
#else
   #define AUD_MED_ECALL_EXT_MEM_SIZE (0)
#endif

/******************************************************
 * 2. Begin to count AUDIO EXT MEM size
 ******************************************************/
#define AUD_MED_OVERHEAD (4)

#if defined(__MCU_DTMF_SUPPORT__) 
    #define AUD_DRV_SW_DTMF_EXT_MEM_SIZE (11264+176) /*SW DTMF Working and Buffer memory : 8424 bytes, kal_adm_create() need extra 176bytes*/
#else
    #define AUD_DRV_SW_DTMF_EXT_MEM_SIZE (0)
#endif

/* Audio memory use cases:              [Overhead]        + [Working buffer]           + SW DTMF Woring and Buffer memory  */
#define MAX_AUD_MEM_SIZE_CTM            (AUD_MED_OVERHEAD + AUD_MED_CTM_EXT_MEM_SIZE   + AUD_DRV_SW_DTMF_EXT_MEM_SIZE)      /* CTM */
#define MAX_AUD_MEM_SIZE_ECALL          (AUD_MED_OVERHEAD + AUD_MED_ECALL_EXT_MEM_SIZE + AUD_DRV_SW_DTMF_EXT_MEM_SIZE)    /* eCall */


/******************************************************
 * MED shared memory usage definition 
 ******************************************************/

/**
 * when turn on debug on, adm need around 200K to log some information, 
 * so we enlarge MEM_OVERHEAD to 384 bytes */
#if defined(__MED_MEM_DEBUG_ON__)
   #define MEM_AUD_OVERHEAD (1024)
   #define MEM_OVERHEAD     (384)
   #define MEM_EXT_OVERHEAD (1024)
#else
   #define MEM_AUD_OVERHEAD (256)
   #define MEM_OVERHEAD     (256)
   #define MEM_EXT_OVERHEAD (256)
#endif /* __MED_MEM_DEBUG_ON__ */

/*==== MACROS ========*/

#if defined(PRODUCTION_RELEASE) || defined(MED_NOT_PRESENT)
   #define MED_MEM_INFO(v,w,x,y,z)
   #define MED_FREE_MEM_INFO(x,y,z)
   #define MED_MEM_FRAGMENTATION(x,y,z,a)
   #define MED_MEM_CONCURRENT(x,y,z,a) 
   #define MED_MEM_INFO_AUD(v,w,x,y,z)    
   #define MED_FREE_MEM_INFO_AUD(x,y,z)   
   #define MED_MEM_FRAGMENTATION_AUD(x,y,z,a)
   #define MED_MEM_CONCURRENT_AUD(x,y,z,a)
#else /* PRODUCTION_RELEASE */ 
   #define __AUD_TRACE_ON__
   #define __ECALL_TRACE_ON__
   
   #define MED_MEM_INFO(v,w,x,y,z)            kal_trace(TRACE_INFO, MEM_INFO, v, w, x, y, z);
   #define MED_FREE_MEM_INFO(x,y,z)           kal_trace(TRACE_INFO, FREE_MEM_INFO, x, y, z);
   #define MED_MEM_FRAGMENTATION(x,y,z,a)     kal_trace(TRACE_INFO, MEM_INFO_FRAGMENTATION, x, y, z, a);
   #define MED_MEM_CONCURRENT(x,y,z,a)        kal_trace(TRACE_INFO, MEM_INFO_CONCURRENT, x, y, z, a);
   #define MED_MEM_INFO_AUD(v,w,x,y,z)        kal_trace(TRACE_INFO, MEM_INFO_AUD, v, w, x, y, z);
   #define MED_FREE_MEM_INFO_AUD(x,y,z)       kal_trace(TRACE_INFO, FREE_MEM_INFO_AUD, x, y, z);
   #define MED_MEM_FRAGMENTATION_AUD(x,y,z,a) kal_trace(TRACE_INFO, MEM_INFO_FRAGMENTATION_AUD, x, y, z, a);
   #define MED_MEM_CONCURRENT_AUD(x,y,z,a)    kal_trace(TRACE_INFO, MEM_INFO_CONCURRENT_AUD, x, y, z, a);
#endif /* PRODUCTION_RELEASE */ 

#ifdef __AUD_TRACE_ON__
   #define AUD_FUNC_ENTRY(X)                  kal_trace(TRACE_GROUP_1, X);
   #define AUD_FUNC_ENTRY1(F, x)              kal_trace(TRACE_GROUP_1, F, x);
   #define AUD_FUNC_ENTRY2(F, x, y)           kal_trace(TRACE_GROUP_1, F, x, y);
   #define AUD_TRACE_VOLUME(x,y,z)            kal_trace(TRACE_GROUP_1, AUD_VOLUME_TRC, x, y, z);
   #define AUD_TRACE_PATH(x,y,z)              kal_trace(TRACE_GROUP_1, AUD_PATH_TRC, x, y, z);
   #define AUD_MODULE_KEYTONE_TRACE(x,y,z,l)  kal_trace(TRACE_INFO, AUD_MODULE_KEYTONE_TRC, x, y, z, l);
#else /* __AUD_TRACE_ON__ */ 
   #define AUD_FUNC_ENTRY(X)
   #define AUD_FUNC_ENTRY1(F, x)
   #define AUD_FUNC_ENTRY2(F, x, y)
   #define AUD_TRACE_VOLUME(x,y,z)
   #define AUD_TRACE_PATH(x,y,z)
   #define AUD_MODULE_KEYTONE_TRACE(x,y,z,l)
#endif /* __AUD_TRACE_ON__ */ 

#ifdef __ECALL_TRACE_ON__
   #define ECALL_FUNC_ENTRY(X)     kal_trace(TRACE_GROUP_1, X);
   #define ECALL_VALUE_TRACE(x)    kal_trace(TRACE_GROUP_1, AUD_ECALL_CHECK_VALUE, x);
#else /* __ECALL_TRACE_ON__ */ 
   #define ECALL_FUNC_ENTRY(X)
   #define ECALL_VALUE_TRACE(x)
#endif /* __ECALL_TRACE_ON__ */ 

/*==== TYPES =========*/
typedef enum
{
   MED_NVRAM_IDLE,
   MED_POWERON_READING_NVRAM,
   MED_POWERON_READING_NVRAM_FINISH
}
med_nvram_state_enum;

#endif /* _MED_GLOBAL_H */ 

