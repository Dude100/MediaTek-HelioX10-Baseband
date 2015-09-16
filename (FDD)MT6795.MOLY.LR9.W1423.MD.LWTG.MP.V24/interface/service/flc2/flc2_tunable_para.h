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
 *   flc2_tunable_para.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the function declarations used for gprs flow
 *   control implementation.
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
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/
#ifndef _FLC2_TUNABLE_PARA_H
#define _FLC2_TUNABLE_PARA_H

/******************************************************************************/
#include "flc2_mem_mngr_config.h"
#include "custom_flc_config.h"
#include "flc2_config.h"

/******************************************************************************/
#if defined(__PS_SERVICE__)
#define FLC2_MAX_PDP_CNTXTS         GPRS_MAX_PDP_SUPPORT

// Requested by QMU BM
#define FLC2_NPDU_UL_POOL_NUMBER    1

#else
#define FLC2_MAX_PDP_CNTXTS         0
#define FLC2_NPDU_UL_POOL_NUMBER    0
#endif

#define FLC2_NPDU_DL_POOL_NUMBER    1   //FLC2_MAX_PDP_CNTXTS
#define FLC2_MAX_NPDU_POOLS_NUM     FLC2_MAX_PDP_CNTXTS

/*************************************************************************
 * MM BLOCK 0 (Fixed Sized)
 *************************************************************************/
/* For AppPDU_UL AppPDU_DL */
/* FIX SIZE, BLOCK SIZE 3038 */
#define FLC2_MB_0_UNIT_SIZE         (3038)

/* Eric Hsieh: 20091107, apply new compile option for WAP over CSD */
#if defined(__TCPIP_OVER_CSD__) || defined(__EXT_MODEM__)
#define FLC2_APPPDU_UL_CHUNKS       1
#define FLC2_APPPDU_DL_CHUNKS       2
#ifndef __FLC2_MM_FIX_SIZE_SUPPORT__
#define __FLC2_MM_FIX_SIZE_SUPPORT__
#endif
#else
#define FLC2_APPPDU_UL_CHUNKS       0
#define FLC2_APPPDU_DL_CHUNKS       0
#endif

/*************************************************************************
 * MM BLOCK 1 (Fixed Sized)
 *************************************************************************/
/* For CSPDU_UL CSPDU_DL */
/* FIX SIZE, BLOCK SIZE 64 */
#define FLC2_MB_1_UNIT_SIZE         (64)

#if defined(__CS_SERVICE__) && defined(CSD_SUPPORT)
/* CSPDU_UL */
#define FLC2_CSPDU_UL_CHUNKS        65
#ifndef __FLC2_MM_FIX_SIZE_SUPPORT__
#define __FLC2_MM_FIX_SIZE_SUPPORT__
#endif

/* CSDPDU_DL */
#ifndef __SLIM_DATA__
#define FLC2_CSPDU_DL_CHUNKS        73
#else
#define FLC2_CSPDU_DL_CHUNKS        10
#endif

#else /* __CS_SERVICE__ && CSD_SUPPORT */
#define FLC2_CSPDU_UL_CHUNKS        0
#define FLC2_CSPDU_DL_CHUNKS        0
#endif /* __CS_SERVICE__ && CSD_SUPPORT */

/*************************************************************************
 * MM BLOCK 2 (Fixed Sized)
 *************************************************************************/
/* For NPDU_DL or NPDU_UL */
/* FIX SIZE, BLOCK SIZE 1660 */
#define FLC2_MB_2_UNIT_SIZE         (1660)

#if defined(__PS_SERVICE__)
/* NPDU_UL */
#if !defined(__UMTS_TDD128_MODE__) || defined(__3G_NEW_DATA_PLANE_ARCH__)
#if !defined(__USE_LEGACY_23G_DATAPATH__)
#define FLC2_NPDU_UL_CHUNKS         8
#else
#define FLC2_NPDU_UL_CHUNKS         3
#endif

#else
#if (defined(__HSUPA_SUPPORT__) && !defined(__HSUPA_CAPABILITY_NOT_SUPPORT__))
/* HSUPA support, set UL pool to 40KB */
#define FLC2_NPDU_UL_CHUNKS         25
#elif defined(__LLC_ACK_MODE_SUPPORT__) || defined(__UMTS_RAT__)
#define FLC2_NPDU_UL_CHUNKS         8
#else
#define FLC2_NPDU_UL_CHUNKS         1
#endif

#endif

/* NPDU_DL */
#if defined(__EGPRS_MODE__) || defined(__UMTS_RAT__)
#define FLC2_NPDU_DL_CHUNKS         8
#else
#define FLC2_NPDU_DL_CHUNKS         4
#endif

#else

#define FLC2_NPDU_UL_CHUNKS         0
#define FLC2_NPDU_DL_CHUNKS         0
#endif

/*************************************************************************
 * MM BLOCK 3 (Fixed Sized)
 *************************************************************************/
/* For PSDPDU_ACK_DL or PSDPDU_UNACK_DL */

/* FIX SIZE, BLOCK SIZE 1660 */
#define FLC2_MB_3_UNIT_SIZE         (1660)

#if defined(__PS_SERVICE__)
/* PSPDU_ACK_DL */
#define FLC2_PSPDU_ACK_DL_CHUNKS    4  // One for each SAPI

/* PSPDU_UNACK_DL */
#ifdef __EGPRS_MODE__
#define FLC2_PSPDU_UNACK_DL_CHUNKS  12 // All 4 SAPIs use this one
#else  /* __EGPRS_MODE__ */
#define FLC2_PSPDU_UNACK_DL_CHUNKS  4  // All 4 SAPIs use this one
#endif /* __EGPRS_MODE__ */

/* PSPDU DL GROW POOL */
#define FLC2_PSPDU_DL_GROW_CHUNKS   8  // Either ack dl and unack dl can use it

#else

#define FLC2_PSPDU_ACK_DL_CHUNKS    0
#define FLC2_PSPDU_UNACK_DL_CHUNKS  0
#define FLC2_PSPDU_DL_GROW_CHUNKS   0
#endif

/*************************************************************************
 * MM BLOCK 4 (Fixed size)
 *************************************************************************/
/* ADM, BLOCK SIZE, 64, 384, 640, 1636 */
/* For IRDA (APP) */
/* IRDA */

/* FIX SIZE, BLOCK SIZE 512 */
#define FLC2_MB_4_UNIT_SIZE         (512)

#ifdef __IRDA_SUPPORT__
#define FLC2_IRDA_UL_CHUNKS         (6)
#define FLC2_IRDA_DL_CHUNKS         (6)

#ifndef __FLC2_MM_FIX_SIZE_SUPPORT__
#define __FLC2_MM_FIX_SIZE_SUPPORT__
#endif

#else
#define FLC2_IRDA_UL_CHUNKS        (0)
#define FLC2_IRDA_DL_CHUNKS        (0)
#endif

/*************************************************************************
 * MM BLOCK 10 (ADM)
 *************************************************************************/
/* ADM, BLOCK SIZE, 64, 384, 640, 1636 */
/* PSDATA ACK/UNACK UL, CIPHER*/

#if defined(__PS_SERVICE__)
#define FLC2_PSPDU_ACK_SAPI3_UL_POOL_SIZE           (12 * 1024)
#define FLC2_PSPDU_ACK_SAPI5_UL_POOL_SIZE           (12 * 1024)
#define FLC2_PSPDU_ACK_SAPI9_UL_POOL_SIZE           (6 * 1024)
#define FLC2_PSPDU_ACK_SAPI11_UL_POOL_SIZE          (4 * 1024)

/* Unack mode : pool size per PDP context */
#define FLC2_PSPDU_UNACK_PDP_UL_POOL_SIZE           (12 * 1024)

#ifdef __EGPRS_MODE__
/* Unack mode : grow pool size per PDP context */
#define FLC2_PSPDU_UNACK_UL_GROW_SIZE_PER_PDP_CNXT  (10 * 1024)
#else
#define FLC2_PSPDU_UNACK_UL_GROW_SIZE_PER_PDP_CNXT  (0)
#endif

#define FLC2_CIPHER_POOL_SIZE                       (5 * 1024)

#else
#define FLC2_PSPDU_ACK_SAPI3_UL_POOL_SIZE           (0)
#define FLC2_PSPDU_ACK_SAPI5_UL_POOL_SIZE           (0)
#define FLC2_PSPDU_ACK_SAPI9_UL_POOL_SIZE           (0)
#define FLC2_PSPDU_ACK_SAPI11_UL_POOL_SIZE          (0)
#define FLC2_PSPDU_UNACK_PDP_UL_POOL_SIZE           (0)
#define FLC2_PSPDU_UNACK_UL_GROW_SIZE_PER_PDP_CNXT  (0)
#define FLC2_CIPHER_POOL_SIZE                       (0)
#endif

/* Utilities */
#define FLC2_MAX(FLC_A, FLC_B)   (((FLC_A) > (FLC_B)) ? (FLC_A):(FLC_B))
#define FLC2_MIN(FLC_A, FLC_B)   (((FLC_A) < (FLC_B)) ? (FLC_A):(FLC_B))

#define FLC2_MAX_IN_FOUR_ELM(FLC_A, FLC_B,FLC_C, FLC_D) \
        (FLC2_MAX(FLC2_MAX(FLC2_MAX(FLC_A, FLC_B), FLC_C),FLC_D))

#define FLC2_MAX_IN_THREE_ELM(FLC_A, FLC_B, FLC_C) \
        (FLC2_MAX(FLC2_MAX(FLC_A, FLC_B), FLC_C))

#define FLC2_2ND_MAX_IN_FOUR_ELM(FLC_MAX, FLC_A, FLC_B, FLC_C, FLC_D) \
    (\
      (FLC_A == FLC_MAX)?( FLC2_MAX_IN_THREE_ELM(FLC_B, FLC_C, FLC_D) ):\
         (\
            (FLC_B == FLC_MAX)?( FLC2_MAX_IN_THREE_ELM(FLC_A, FLC_C, FLC_D) ):\
            (\
               (FLC_C == FLC_MAX)?( FLC2_MAX_IN_THREE_ELM(FLC_A, FLC_B, FLC_D) ):\
                  (FLC2_MAX_IN_THREE_ELM(FLC_A, FLC_B, FLC_C) )\
            )\
         )\
    )

#define FLC2_MIN_IN_FOUR_ELM(FLC_A, FLC_B,FLC_C, FLC_D) \
    (FLC2_MIN(FLC2_MIN(FLC2_MIN(FLC_A, FLC_B), FLC_C),FLC_D))

#define FLC2_MIN_IN_THREE_ELM(FLC_A, FLC_B, FLC_C) \
    (FLC2_MIN(FLC2_MIN(FLC_A, FLC_B), FLC_C))

#define FLC2_2ND_MIN_IN_FOUR_ELM(FLC_MIN, FLC_A, FLC_B, FLC_C, FLC_D) \
    (\
      (FLC_A == FLC_MIN)?( FLC2_MIN_IN_THREE_ELM(FLC_B, FLC_C, FLC_D) ):\
         (\
            (FLC_B == FLC_MIN)?( FLC2_MIN_IN_THREE_ELM(FLC_A, FLC_C, FLC_D) ):\
            (\
               (FLC_C == FLC_MIN)?( FLC2_MIN_IN_THREE_ELM(FLC_A, FLC_B, FLC_D) ):\
                  (FLC2_MIN_IN_THREE_ELM(FLC_A, FLC_B, FLC_C) )\
            )\
         )\
    )

/*************************************************************************
 * Non-tunable Macros
 *************************************************************************/
/* Defination for Fix Size Pools */
/* MM BLOCK 0 */
/* For AppPDU_UL AppPDU_DL */
/* FIX SIZE, BLOCK SIZE 3010 */
#define FLC2_MB_0_PDU_SIZE      FLC2_FIX_POOL_SIZE_ALIGN(FLC2_MB_0_UNIT_SIZE)
#define FLC2_MB_0_CHUNK_SIZE    \
     (FLC2_MB_0_PDU_SIZE + FLC2_MEM_FIX_SIZE_CHUNK_TOTAL_OVERHEAD)

/* Eric Hsieh: 20091107, apply new compile option for WAP over CSD */
#if defined(__TCPIP_OVER_CSD__) || defined(__EXT_MODEM__)
#define FLC2_APPPDU_UL_POOL_SIZE    \
    FLC2_FIX_SIZE_POOL_SIZE_COUNT(FLC2_MB_0_CHUNK_SIZE, FLC2_APPPDU_UL_CHUNKS)
#define FLC2_APPPDU_DL_POOL_SIZE    \
     FLC2_FIX_SIZE_POOL_SIZE_COUNT(FLC2_MB_0_CHUNK_SIZE, FLC2_APPPDU_DL_CHUNKS)
#define FLC2_APPDU_POOL_NUMBER      2
#else
#define FLC2_APPPDU_UL_POOL_SIZE    0
#define FLC2_APPPDU_DL_POOL_SIZE    0
#define FLC2_APPDU_POOL_NUMBER      0
#endif

#define FLC2_MM_BLOCK_0_SIZE        \
     (FLC2_APPPDU_UL_POOL_SIZE + FLC2_APPPDU_DL_POOL_SIZE + \
      FLC2_MEM_FIX_SIZE_CTRL_HEADER_LEN)
/* End of MM BLOCK 0 */

/* MM BLOCK 1 */
/* For CSPDU_UL CSPDU_DL */
/* FIX SIZE, BLOCK SIZE 69 */
#define FLC2_MB_1_PDU_SIZE      FLC2_FIX_POOL_SIZE_ALIGN(FLC2_MB_1_UNIT_SIZE)
#define FLC2_MB_1_CHUNK_SIZE    \
    (FLC2_MB_1_PDU_SIZE + FLC2_MEM_FIX_SIZE_CHUNK_TOTAL_OVERHEAD)

#ifdef CSD_SUPPORT
#define FLC2_CSPDU_UL_POOL_SIZE     \
    FLC2_FIX_SIZE_POOL_SIZE_COUNT(FLC2_MB_1_CHUNK_SIZE, FLC2_CSPDU_UL_CHUNKS)
#define FLC2_CSPDU_DL_POOL_SIZE     \
    FLC2_FIX_SIZE_POOL_SIZE_COUNT(FLC2_MB_1_CHUNK_SIZE, FLC2_CSPDU_DL_CHUNKS)
#define FLC2_CSPDU_POOL_NUMBER      2
#else
#define FLC2_CSPDU_UL_POOL_SIZE     0
#define FLC2_CSPDU_DL_POOL_SIZE     0
#define FLC2_CSPDU_POOL_NUMBER      0
#endif

#define FLC2_MM_BLOCK_1_SIZE        \
     (FLC2_CSPDU_UL_POOL_SIZE + FLC2_CSPDU_DL_POOL_SIZE + \
      FLC2_MEM_FIX_SIZE_CTRL_HEADER_LEN)
/* End of MM BLOCK 1 */

/* MM BLOCK 2 */
/* For NPDU_DL or NPDU_UL */
#if !defined(__UMTS_TDD128_MODE__) || defined(__3G_NEW_DATA_PLANE_ARCH__)
// __HW_PFC_SUPPORT__
#define FLC2_MB_2_CHUNK_SIZE        (1704 + 32)
#else
#define FLC2_MB_2_PDU_SIZE          FLC2_FIX_POOL_SIZE_ALIGN(FLC2_MB_2_UNIT_SIZE)
#define FLC2_MB_2_CHUNK_SIZE        \
    (FLC2_MB_2_PDU_SIZE + FLC2_MEM_FIX_SIZE_CHUNK_TOTAL_OVERHEAD)
#endif

/******************************************************************************/

#ifdef __TCPIP__
#define FLC2_NPDU_UL_MAX_GROW_CHUNKS  0
#elif (FLC2_NPDU_UL_CHUNKS == 1)
#define FLC2_NPDU_UL_MAX_GROW_CHUNKS  1
#else
#define FLC2_NPDU_UL_MAX_GROW_CHUNKS  0
#endif

// Eric Hsieh: NPDU setting with HSPA data path optimization, let NPDU share PSPDU's grow size.
// The following value shall sync with PSPDU UMTS grow size.
#if !defined(__UMTS_TDD128_MODE__) || defined(__3G_NEW_DATA_PLANE_ARCH__)
#if defined(__LTE_RAT__)
#define _FLC2_NPDU_UL_MAX_GROW  (800 * 1024)
#define _FLC2_NPDU_DL_MAX_GROW  (62 * 1024)
#elif defined(__MAC_EHS_SUPPORT__) /* Support latter than R7 */

#ifdef __UL_MEMORY_SHRINK__
// UL: 5.7M -> Total pool size: 206400 (By PS2 Hsiu-Chi)
#define _FLC2_NPDU_UL_MAX_GROW  (202000)
#else
#define _FLC2_NPDU_UL_MAX_GROW  (310 * 1024)
#endif

#define _FLC2_NPDU_DL_MAX_GROW  (62 * 1024)
#elif defined(__HSUPA_SUPPORT__)
#define _FLC2_NPDU_UL_MAX_GROW  (202000)
#define _FLC2_NPDU_DL_MAX_GROW  (44 * 1024)
#elif defined(__LLC_ACK_MODE_SUPPORT__) || \
     (defined(__UMTS_RAT__) && !defined(__LOW_COST_SUPPORT_COMMON__))
/* DPA support or 3G R99 settings */
#define _FLC2_NPDU_UL_MAX_GROW  (33 * 1024)
#define _FLC2_NPDU_DL_MAX_GROW  (44 * 1024)
#else
/* 2G only project or 3G low cost project */
#define _FLC2_NPDU_UL_MAX_GROW  \
     FLC2_FIX_SIZE_POOL_SIZE_COUNT(FLC2_MB_2_CHUNK_SIZE, \
         FLC2_NPDU_UL_MAX_GROW_CHUNKS)

#define _FLC2_NPDU_DL_MAX_GROW  0
#endif

#else
#if (defined(__HSUPA_SUPPORT__) && !defined(__HSUPA_CAPABILITY_NOT_SUPPORT__))
/* HSUPA support, set UL pool to 50KB */
#define _FLC2_NPDU_UL_MAX_GROW  (50 * 1024)
#define _FLC2_NPDU_DL_MAX_GROW  (44 * 1024)
#elif defined(__OP01_FWPBW__) || defined(__OP01_FWPCOLOR__)
/* DPA support or 3G R99 settings */
#define _FLC2_NPDU_UL_MAX_GROW  (33 * 1024)
#define _FLC2_NPDU_DL_MAX_GROW  (44 * 1024)
#elif defined(__LLC_ACK_MODE_SUPPORT__) || \
     (defined(__UMTS_RAT__) && !defined(__LOW_COST_SUPPORT_COMMON__))
/* DPA support or 3G R99 settings */
#define _FLC2_NPDU_UL_MAX_GROW  (33 * 1024)
#define _FLC2_NPDU_DL_MAX_GROW  (44 * 1024)
#else
/* 2G only project or 3G low cost project */
#define _FLC2_NPDU_UL_MAX_GROW  \
     FLC2_FIX_SIZE_POOL_SIZE_COUNT(FLC2_MB_2_CHUNK_SIZE, \
         FLC2_NPDU_UL_MAX_GROW_CHUNKS)

#define _FLC2_NPDU_DL_MAX_GROW  0
#endif
#endif

#define FLC2_NPDU_UL_MAX_GROW   (_FLC2_NPDU_UL_MAX_GROW)
#define FLC2_NPDU_DL_MAX_GROW   (_FLC2_NPDU_DL_MAX_GROW * FLC2_MAX_NPDU_POOLS_NUM)

/******************************************************************************/
#define FLC2_PPP_RE_ALLOC_3G_PDU_NUM        4
#define FLC2_PPP_RE_ALLOC_2G_PDU_NUM        2

/******************************************************************************/
#if !defined(__USE_LEGACY_23G_DATAPATH__)
#ifdef __SMART_PHONE_MODEM__
#define FLC2_INTERNAL_UL_POOL_SIZE          0
#else
// QBM NET_UL: For NMU DHCPC (dongle only)
#define FLC2_INTERNAL_UL_POOL_SIZE          (2048 * 20)
#endif

#else
#define FLC2_INTERNAL_UL_POOL_SIZE          0
#endif

/******************************************************************************/
#if !defined(__USE_LEGACY_23G_DATAPATH__)
#if defined(__LTE_RAT__) || defined(__UMTS_RAT__)
// 4G or 3G project
#define FLC2_HIF_UL_02_POOL_SIZE            (2048 * 80)
#else
// 2G project
#define FLC2_HIF_UL_02_POOL_SIZE            (2048 * 10)
#endif

#else
#define FLC2_HIF_UL_02_POOL_SIZE            0
#endif

/******************************************************************************/
#if defined(__MBIM_SUPPORT__) && defined(__UPS_SUPPORT__)
// Mac OS 10.5 and 10.6: Keep one buffer in USB Rx
#define FLC2_NPDU_UL_ECM_BUF                5000

#define FLC2_NPDU_UL_FWD_POOL_SIZE          (10 * 1024)
#else
#define FLC2_NPDU_UL_ECM_BUF                0
#define FLC2_NPDU_UL_FWD_POOL_SIZE          0
#endif

#define FLC2_NPDU_UL_FWD_POOL_SIZE_TOTAL    \
     (FLC2_NPDU_UL_FWD_POOL_SIZE * FLC2_NPDU_UL_FWD_POOL_NUMBER)

#define FLC2_NPDU_UL_POOL_SIZE              \
     (FLC2_FIX_SIZE_POOL_SIZE_COUNT(FLC2_MB_2_CHUNK_SIZE, FLC2_NPDU_UL_CHUNKS) + \
      FLC2_NPDU_UL_ECM_BUF)

#define FLC2_NPDU_DL_POOL_SIZE              \
     (FLC2_FIX_SIZE_POOL_SIZE_COUNT(FLC2_MB_2_CHUNK_SIZE, FLC2_NPDU_DL_CHUNKS) * \
     FLC2_MAX_NPDU_POOLS_NUM)

#define FLC2_NPDU_UL_POOL_SIZE_TOTAL        \
    (FLC2_NPDU_UL_POOL_SIZE * FLC2_NPDU_UL_POOL_NUMBER)

#define FLC2_NPDU_DL_POOL_SIZE_TOTAL        \
    (FLC2_NPDU_DL_POOL_SIZE * FLC2_NPDU_DL_POOL_NUMBER)

/* MM BLOCK 3 */
/* For PSDPDU_ACK_DL or PSDPDU_UNACK_DL */
/* FIX SIZE, BLOCK SIZE 1660 */
#define FLC2_MB_3_PDU_SIZE                  \
    FLC2_FIX_POOL_SIZE_ALIGN(FLC2_MB_3_UNIT_SIZE)

#define FLC2_MB_3_CHUNK_SIZE                \
    (FLC2_MB_3_PDU_SIZE + FLC2_MEM_FIX_SIZE_CHUNK_TOTAL_OVERHEAD)

#define FLC2_PSPDU_ACK_DL_INIT_POOL_SIZE    FLC2_MB_3_UNIT_SIZE

// Eric Hsieh: For init pool total size, we shall align with the minimal among
// the number of PDP contexts and the max no. of SAPIs
#define FLC2_PSPDU_POOL_SIZE(n)             \
    FLC2_FIX_SIZE_POOL_SIZE_COUNT(FLC2_MB_3_CHUNK_SIZE, (n))

#define FLC2_PSPDU_ACK_DL_POOL_SIZE         \
    FLC2_PSPDU_POOL_SIZE(FLC2_MIN(FLC2_MAX_PDP_CNTXTS, 4))

#define FLC2_PSPDU_ACK_GROW_STEP_SIZE       \
    FLC2_PSPDU_POOL_SIZE(2)

#define FLC2_PSPDU_ACK_MAX_GROW_SIZE        \
    FLC2_PSPDU_POOL_SIZE(FLC2_PSPDU_DL_GROW_CHUNKS)

#define FLC2_PSPDU_UNACK_DL_POOL_SIZE       \
    FLC2_PSPDU_POOL_SIZE(FLC2_PSPDU_UNACK_DL_CHUNKS)

#define FLC2_PSPDU_UNACK_GROW_STEP_SIZE     FLC2_PSPDU_ACK_GROW_STEP_SIZE
#define FLC2_PSPDU_UNACK_MAX_GROW_SIZE      FLC2_PSPDU_ACK_MAX_GROW_SIZE
#define FLC2_PSPDU_DL_GROW_POOL_SIZE        FLC2_PSPDU_ACK_MAX_GROW_SIZE

#define FLC2_NPDU_DL_TOTAL_GROW_SIZE        \
    (FLC2_NPDU_DL_MAX_GROW * FLC2_NPDU_DL_POOL_NUMBER)

#define FLC2_MM_BLOCK_3_MAX_GROW_SIZE       \
    FLC2_MAX(FLC2_PSPDU_DL_GROW_POOL_SIZE, FLC2_NPDU_DL_TOTAL_GROW_SIZE)

#if !defined(__UMTS_TDD128_MODE__) || defined(__3G_NEW_DATA_PLANE_ARCH__)
// All NPDU_DL pools share the memory
#define FLC2_MM_BLOCK_3_REAL_GROW_SIZE       \
    FLC2_MAX(FLC2_PSPDU_DL_GROW_POOL_SIZE, _FLC2_NPDU_DL_MAX_GROW)
#else
#define FLC2_MM_BLOCK_3_REAL_GROW_SIZE       \
     FLC2_MM_BLOCK_3_MAX_GROW_SIZE
#endif

#define FLC2_MM_BLOCK_3_SIZE                (FLC2_NPDU_DL_POOL_SIZE_TOTAL + \
                                             FLC2_PSPDU_ACK_DL_POOL_SIZE + \
                                             FLC2_PSPDU_UNACK_DL_POOL_SIZE + \
                                             FLC2_MM_BLOCK_3_REAL_GROW_SIZE + \
                                             FLC2_MEM_ADM_CTRL_HEADER_LEN)
/* End of MM BLOCK 3 */
/* End of defination for Fix Size Pool */

/* MM BLOCK 4 */
/* ADM, BLOCK SIZE, 64, 384, 640, 1636 */
/* For IRDA (APP) */
#define FLC2_MB_4_PDU_SIZE      \
    FLC2_FIX_POOL_SIZE_ALIGN(FLC2_MB_4_UNIT_SIZE)

#define FLC2_MB_4_CHUNK_SIZE    \
    (FLC2_MB_4_PDU_SIZE + FLC2_MEM_FIX_SIZE_CHUNK_TOTAL_OVERHEAD)

#define FLC2_IRDA_UL_POOL_SIZE  \
    FLC2_FIX_SIZE_POOL_SIZE_COUNT(FLC2_MB_4_CHUNK_SIZE, FLC2_IRDA_UL_CHUNKS)

#define FLC2_IRDA_DL_POOL_SIZE  \
     FLC2_FIX_SIZE_POOL_SIZE_COUNT(FLC2_MB_4_CHUNK_SIZE, FLC2_IRDA_DL_CHUNKS)

#ifdef __IRDA_SUPPORT__
#define FLC2_IRDA_POOL_NUMBER   (2)
#else
#define FLC2_IRDA_POOL_NUMBER   (0)
#endif

#define FLC2_MM_BLOCK_4_SIZE    (FLC2_IRDA_UL_POOL_SIZE + \
                                 FLC2_IRDA_DL_POOL_SIZE + \
                                 FLC2_MEM_FIX_SIZE_CTRL_HEADER_LEN)
/* End of MM BLOCK 4 */

#ifndef __MTK_TARGET__
#define FLC2_UT_ONLY_POOL_SIZE      (FLC2_NPDU_DL_POOL_SIZE + 400 * 1024)
#define FLC2_MM_BLOCK_UT_ONLY_SIZE  \
     (FLC2_UT_ONLY_POOL_SIZE + FLC2_NPDU_DL_MAX_GROW)
#else
#define FLC2_UT_ONLY_POOL_SIZE      (4)
#define FLC2_MM_BLOCK_UT_ONLY_SIZE  (FLC2_MEM_ADM_CTRL_HEADER_LEN)
#endif

/* Defination for ADM Pools */
/* MM BLOCK 10 */
/* ADM, BLOCK SIZE, 64, 384, 640, 1636 */
/* PSDATA ACK/UNACK UL, CIPHER*/
#define FLC2_1ST_MIN_PSPDU_UL_SIZE (FLC2_MIN_IN_FOUR_ELM(FLC2_PSPDU_ACK_SAPI3_UL_POOL_SIZE ,\
                                                      FLC2_PSPDU_ACK_SAPI5_UL_POOL_SIZE ,\
                                                      FLC2_PSPDU_ACK_SAPI9_UL_POOL_SIZE ,\
                                                      FLC2_PSPDU_ACK_SAPI11_UL_POOL_SIZE))

#define FLC2_1ST_MAX_PSPDU_UL_SIZE (FLC2_MAX_IN_FOUR_ELM(FLC2_PSPDU_ACK_SAPI3_UL_POOL_SIZE ,\
                                                      FLC2_PSPDU_ACK_SAPI5_UL_POOL_SIZE ,\
                                                      FLC2_PSPDU_ACK_SAPI9_UL_POOL_SIZE ,\
                                                      FLC2_PSPDU_ACK_SAPI11_UL_POOL_SIZE))


#define FLC2_2ND_MAX_PSPDU_UL_SIZE (FLC2_2ND_MAX_IN_FOUR_ELM(FLC2_1ST_MAX_PSPDU_UL_SIZE ,\
                                                      FLC2_PSPDU_ACK_SAPI3_UL_POOL_SIZE ,\
                                                      FLC2_PSPDU_ACK_SAPI5_UL_POOL_SIZE ,\
                                                      FLC2_PSPDU_ACK_SAPI9_UL_POOL_SIZE ,\
                                                      FLC2_PSPDU_ACK_SAPI11_UL_POOL_SIZE))

#define FLC2_3RD_MAX_PSPDU_UL_SIZE (FLC2_2ND_MIN_IN_FOUR_ELM(FLC2_1ST_MIN_PSPDU_UL_SIZE ,\
                                                      FLC2_PSPDU_ACK_SAPI3_UL_POOL_SIZE ,\
                                                      FLC2_PSPDU_ACK_SAPI5_UL_POOL_SIZE ,\
                                                      FLC2_PSPDU_ACK_SAPI9_UL_POOL_SIZE ,\
                                                      FLC2_PSPDU_ACK_SAPI11_UL_POOL_SIZE))

#define FLC2_4TH_MAX_PSPDU_UL_SIZE FLC2_1ST_MIN_PSPDU_UL_SIZE

/* Based on FLC2_MAX_PDP_CNTXTS , Calculate the MO Uplink Ack/UnAck PDU memory */
#define FLC2_PSPDU_ACK_UNACK_UL_SIZE_1_PDP_CNXT \
    (FLC2_MAX(FLC2_1ST_MAX_PSPDU_UL_SIZE , FLC2_PSPDU_UNACK_PDP_UL_POOL_SIZE))

/* Accumulate 2 PDP contexts */
#define FLC2_PSPDU_ACK_UNACK_UL_SIZE_2_PDP_CNXT \
    ( (FLC2_MAX(FLC2_2ND_MAX_PSPDU_UL_SIZE , FLC2_PSPDU_UNACK_PDP_UL_POOL_SIZE)) + \
    FLC2_PSPDU_ACK_UNACK_UL_SIZE_1_PDP_CNXT)

/* Accumulate 3 PDP contexts */
#define FLC2_PSPDU_ACK_UNACK_UL_SIZE_3_PDP_CNXT \
    ( (FLC2_MAX(FLC2_3RD_MAX_PSPDU_UL_SIZE , FLC2_PSPDU_UNACK_PDP_UL_POOL_SIZE)) + \
    FLC2_PSPDU_ACK_UNACK_UL_SIZE_2_PDP_CNXT)

/* Accumulate 4 PDP contexts */
#define FLC2_PSPDU_ACK_UNACK_UL_SIZE_4_PDP_CNXT \
    ( (FLC2_MAX(FLC2_4TH_MAX_PSPDU_UL_SIZE , FLC2_PSPDU_UNACK_PDP_UL_POOL_SIZE)) + \
    FLC2_PSPDU_ACK_UNACK_UL_SIZE_3_PDP_CNXT)

/* Operations */
#define FLC2_PSPDU_ACK_UNACK_UL_SIZE_MORE_THEN_4_PDP_CNXT \
(((FLC2_MAX_PDP_CNTXTS - 4)* FLC2_PSPDU_UNACK_PDP_UL_POOL_SIZE) + FLC2_PSPDU_ACK_UNACK_UL_SIZE_4_PDP_CNXT )

/* PSPDU UL size depends supported PDP context number. */
#define FLC2_PSPDU_UL_POOL_SIZE    \
    (\
        (0 == FLC2_MAX_PDP_CNTXTS)?(0):\
            (\
                (1 == FLC2_MAX_PDP_CNTXTS)?(FLC2_PSPDU_ACK_UNACK_UL_SIZE_1_PDP_CNXT):\
                    (\
                        (2 == FLC2_MAX_PDP_CNTXTS)?(FLC2_PSPDU_ACK_UNACK_UL_SIZE_2_PDP_CNXT):\
                            (\
                                (3 == FLC2_MAX_PDP_CNTXTS)?(FLC2_PSPDU_ACK_UNACK_UL_SIZE_3_PDP_CNXT):\
                                    (\
                                        (4 == FLC2_MAX_PDP_CNTXTS)?(FLC2_PSPDU_ACK_UNACK_UL_SIZE_4_PDP_CNXT):\
                                            (FLC2_PSPDU_ACK_UNACK_UL_SIZE_MORE_THEN_4_PDP_CNXT)\
                                    )\
                            )\
                    )\
            )\
    )

#define FLC2_PSPDU_UNACK_UL_GROW_SIZE (FLC2_PSPDU_UNACK_UL_GROW_SIZE_PER_PDP_CNXT * FLC2_MAX_PDP_CNTXTS)

#define FLC2_NPDU_UL_MAX_GROW_SIZE      \
    (FLC2_NPDU_UL_MAX_GROW * FLC2_NPDU_UL_POOL_NUMBER)

#define FLC2_MM_BLOCK_10_MAX_GROW_SIZE  \
    FLC2_MAX(FLC2_PSPDU_UNACK_UL_GROW_SIZE, FLC2_NPDU_UL_MAX_GROW_SIZE)

#if !defined(__UMTS_TDD128_MODE__) || defined(__3G_NEW_DATA_PLANE_ARCH__)
#if defined(__UMTS_RAT__)
// Every pool has its private size. Growed size is shared among all pools.
#define FLC2_NPDU_UL_REAL_GROW_SIZE         (FLC2_NPDU_UL_MAX_GROW)
#else
// 2G project: Original setting. Every pool has its own growed size.
#define FLC2_NPDU_UL_REAL_GROW_SIZE         (FLC2_NPDU_UL_MAX_GROW_SIZE)
#endif

#define FLC2_MM_BLOCK_10_REAL_GROW_SIZE     \
    FLC2_MAX(FLC2_PSPDU_UNACK_UL_GROW_SIZE, FLC2_NPDU_UL_REAL_GROW_SIZE)
#else
#define FLC2_MM_BLOCK_10_REAL_GROW_SIZE     (FLC2_MM_BLOCK_10_MAX_GROW_SIZE)
#endif

#define FLC2_MM_BLOCK_10_SIZE               (FLC2_PSPDU_UL_POOL_SIZE + \
                                             FLC2_NPDU_UL_POOL_SIZE_TOTAL + \
                                             FLC2_NPDU_UL_FWD_POOL_SIZE_TOTAL + \
                                             FLC2_MM_BLOCK_10_REAL_GROW_SIZE + \
                                             FLC2_CIPHER_POOL_SIZE + \
                                             FLC2_MEM_ADM_CTRL_HEADER_LEN)
/* End of MM BLOCK 10 */

#define FLC2_MM_BLOCK_HIF_UL_02_SIZE        (FLC2_HIF_UL_02_POOL_SIZE + \
                                             FLC2_MEM_ADM_CTRL_HEADER_LEN)

/* Define pool entity number. */
#if defined(__PS_SERVICE__)
#define FLC2_PSPDU_ACK_POOL_NUMBER      (8)
#define FLC2_PSPDU_UNACK_POOL_NUMBER    (1 + FLC2_MAX_PDP_CNTXTS)
#define FLC2_CIPHER_POOL_NUMBER         (1)
#else
#define FLC2_PSPDU_ACK_POOL_NUMBER      (0)
#define FLC2_PSPDU_UNACK_POOL_NUMBER    (0)
#define FLC2_CIPHER_POOL_NUMBER         (0)
#endif

#ifdef __TCPIP__
#if defined(__HOTSPOT_SUPPORT__)
#define FLC2_I_NET_POOL_NUMBER  (3 + FLC2_SPDU_UL_POOL_NUMBER) /* plus TPDU SRPDU HotSpot */
#else
#define FLC2_I_NET_POOL_NUMBER  (2 + FLC2_SPDU_UL_POOL_NUMBER) /* plus TPDU SRPDU */
#endif

#else
#define FLC2_I_NET_POOL_NUMBER  (0)
#endif

#define FLC2_PSPDU_GPRS_POOL_NUMBER     (FLC2_PSPDU_ACK_POOL_NUMBER + \
                                         FLC2_PSPDU_UNACK_POOL_NUMBER + \
                                         FLC2_CIPHER_POOL_NUMBER)

#define FLC2_PSPDU_TOTAL_POOL_NUMBER    FLC2_PSPDU_GPRS_POOL_NUMBER

#define FLC2_LLC_SUPERVISORY_DL_POOL_NUMBER     (1)

#ifdef __3G_NEW_DATA_PLANE_ARCH__
#define FLC2_MAC_DL_POOL_NUMBER         (1)
#else
#define FLC2_MAC_DL_POOL_NUMBER         (0)
#endif

#if defined(__MBIM_SUPPORT__) && defined(__UPS_SUPPORT__)
#define FLC2_NPDU_UL_FWD_POOL_NUMBER    (1)
#else
#define FLC2_NPDU_UL_FWD_POOL_NUMBER    (0)
#endif

#ifndef __USE_LEGACY_23G_DATAPATH__
#define FLC2_INTERNAL_UL_POOL_NUMBER    (1)
#else
#define FLC2_INTERNAL_UL_POOL_NUMBER    (0)
#endif

#ifndef __USE_LEGACY_23G_DATAPATH__
#define FLC2_HIFSMALL_UL_POOL_NUMBER    (1)
#else
#define FLC2_HIFSMALL_UL_POOL_NUMBER    (0)
#endif

#ifndef __USE_LEGACY_23G_DATAPATH__
#define FLC2_HIF_UL_02_POOL_NUMBER      (1)
#else
#define FLC2_HIF_UL_02_POOL_NUMBER      (0)
#endif

#define FLC2_ACT_POOL_ENTITY_TOTAL      (FLC2_APPDU_POOL_NUMBER + \
                                         FLC2_CSPDU_POOL_NUMBER + \
                                         FLC2_NPDU_UL_FWD_POOL_NUMBER + \
                                         FLC2_NPDU_UL_POOL_NUMBER + \
                                         FLC2_NPDU_DL_POOL_NUMBER + \
                                         FLC2_PSPDU_TOTAL_POOL_NUMBER + \
                                         FLC2_LLC_SUPERVISORY_DL_POOL_NUMBER + \
                                         FLC2_I_NET_POOL_NUMBER + \
                                         FLC2_IRDA_POOL_NUMBER + \
                                         FLC2_MAC_DL_POOL_NUMBER + \
                                         FLC2_INTERNAL_UL_POOL_NUMBER + \
                                         FLC2_HIFSMALL_UL_POOL_NUMBER + \
                                         FLC2_HIF_UL_02_POOL_NUMBER + \
                                         FLC2_MAX_UT_POOL_ID + 1)
#endif /* _FLC2_TUNABLE_PARA_H */
