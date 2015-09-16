/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *
 * Filename:
 * ---------
 * custom_flc_config.h
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   This file is used to define the FLC2 configuration.
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
 *==============================================================================
 *******************************************************************************/

#ifndef _CUSTOM_FLC_CONFIG_H
#define _CUSTOM_FLC_CONFIG_H

#include "kal_general_types.h"

/*************************************************************************
 * MM BLOCK 11 (ADM)
 *************************************************************************/
/* ADM, BLOCK SIZE, 64, 384, 640, 1636 */
/* For SPDU TPDU (TCP/IP, socket)*/

/*================= Guideline for SPDU_UL and SPDU_DL configuration =============

1. Each Socket has corresponding pool, and each pool has a dedicated buffer
   with size FLC2_SPDU_UL_SIZE_EM.
2. There is a share pool for all socket pools.
   Please define the growth pool size with FLC2_SPDU_UL_GROW_POOL_SIZE.
3. Please config FLC2_SPDU_DL_POOL_SIZE for downlink socket pool size.
   ( Receive Window Size.)

NOTE: Do NOT Change Socket number by yourself. It needs update protocol library.
========================================================================== */

/* SSPDU */
#define FLC2_SPDU_UL_SIZE_EM           (1664)

#ifdef __TCPIP__
 /* TCPIP is support. */

/* SPDU_UL configuration */
#define FLC2_SPDU_UL_SIZE           FLC2_SPDU_UL_SIZE_EM

#if defined(__WIFI_SUPPORT__) || defined(__HSUPA_SUPPORT__)

#if defined(__LOW_COST_SUPPORT_COMMON__)
#define FLC2_SPDU_UL_GROW_POOL_SIZE_PLUS 0
#else
#define FLC2_SPDU_UL_GROW_POOL_SIZE_PLUS 30
#endif

#if defined(__HOTSPOT_SUPPORT__)
#define FLC2_SPDU_UL_GROW_POOL_SIZE ((18+FLC2_SPDU_UL_GROW_POOL_SIZE_PLUS) *FLC2_SPDU_UL_SIZE)
#else // #if defined(__HOTSPOT_SUPPORT__)
#define FLC2_SPDU_UL_GROW_POOL_SIZE ((14+FLC2_SPDU_UL_GROW_POOL_SIZE_PLUS) *FLC2_SPDU_UL_SIZE) 
#endif // #if defined(__HOTSPOT_SUPPORT__)

#elif defined(__EGPRS_MODE__)
#define FLC2_SPDU_UL_GROW_POOL_SIZE (13 *FLC2_SPDU_UL_SIZE) 
#else  /* __EGPRS_MODE__ */
#define FLC2_SPDU_UL_GROW_POOL_SIZE (5 *FLC2_SPDU_UL_SIZE) 
#endif /* __EGPRS_MODE__ */


#if defined(__UMTS_RAT__)

#ifdef __HOTSPOT_SUPPORT_PERFORMANCE_BENCHMARK__
#define FLC2_SPDU_DL_POOL_SIZE  (120 * 1660)
#else
#define FLC2_SPDU_DL_POOL_SIZE  (51 * 1660) 
#endif

#elif defined(__EGPRS_MODE__)|| defined(__WIFI_SUPPORT__) 
#ifdef WISDOM_MMI
#define FLC2_SPDU_DL_POOL_SIZE  (120 * 1660) 
#else /* !WISDOM_MMI */
#define FLC2_SPDU_DL_POOL_SIZE  (34 * 1660) 
#endif /* !WISDOM_MMI */
#else  /* __EGPRS_MODE__ */
#if defined(__LOW_COST_SUPPORT_COMMON__)
#define FLC2_SPDU_DL_POOL_SIZE  (15 * 1660)
#else /* __LOW_COST_SUPPORT_COMMON__ */
#define FLC2_SPDU_DL_POOL_SIZE  (16 * 1660)
#endif
#endif /* __EGPRS_MODE__ */

#else /* =============  __TCPIP__  =================== */
 /* TCPIP is NOT support */

#define FLC2_SPDU_UL_SIZE           (0)

#define FLC2_SPDU_UL_GROW_POOL_SIZE (0) 
#define FLC2_SPDU_DL_POOL_SIZE (0) 

#endif /* =============  __TCPIP__  =================== */


#if defined(__HOTSPOT_SUPPORT__)
#define FLC2_HS_POOL_SIZE           (FLC2_SPDU_UL_SIZE_EM)
#define FLC2_HS_POOL_MAX_GROW_SIZE  (120 * FLC2_SPDU_UL_SIZE_EM)
#define FLC2_HS_GROW_STEP_SIZE      (3 * FLC2_SPDU_UL_SIZE_EM)
#else
#define FLC2_HS_POOL_SIZE           (0)
#define FLC2_HS_POOL_MAX_GROW_SIZE  (0) 
#define FLC2_HS_GROW_STEP_SIZE      (0)
#endif



/*========================================================================
 *  CAUTION !! CAUTION !! CAUTION !! CAUTION !! CAUTION !! CAUTION !!
 *
 *  Please DO NOT modify below setting.
 *
 *  CAUTION !! CAUTION !! CAUTION !! CAUTION !! CAUTION !! CAUTION !!
 *======================================================================= */




#ifdef __TCPIP__
 /* TCPIP is support. */

#if (defined(__VOIP__) || defined(STREAM_SUPPORT)) || defined(FLC2_25_SOCKET_SUPPORT)
#define FLC2_SPDU_UL_POOL_NUMBER    (25)   /* socket number, 1 block per socket */
#elif (defined(WAP_SUPPORT) && defined(__IMPS__))
#define FLC2_SPDU_UL_POOL_NUMBER    (19)   /* socket number, 1 block per socket */
#else  /* __VOIP__ */
#define FLC2_SPDU_UL_POOL_NUMBER    (14)   /* socket number, 1 block per socket */
#endif  /* __VOIP__ */

#else /* __TCPIP__ */

#define FLC2_SPDU_UL_POOL_NUMBER    (0)
#endif /* __TCPIP__ */

#define FLC2_SPDU_UL_MAX_GROW_SIZE  FLC2_SPDU_UL_GROW_POOL_SIZE 

#define FLC2_SPDU_UL_POOL_SIZE      (FLC2_SPDU_UL_SIZE_EM* FLC2_SPDU_UL_POOL_NUMBER)


/* TPDU */
#ifdef __TCPIP__

#if defined(__WIFI_SUPPORT__) || defined(__HSUPA_SUPPORT__)

#if defined(__LOW_COST_SUPPORT_COMMON__)
#define FLC2_TPDU_POOL_SIZE_PLUS 0
#else
#define FLC2_TPDU_POOL_SIZE_PLUS 22
#endif

#define FLC2_TPDU_POOL_SIZE    ((8+FLC2_TPDU_POOL_SIZE_PLUS)*1668) 
#else /* __WIFI_SUPPORT__ */
#define FLC2_TPDU_POOL_SIZE    ((4)*1668) 
#endif /* __WIFI_SUPPORT__ */

#else /* __TCPIP__ */
#define FLC2_TPDU_POOL_SIZE    (0) 
#endif /* __TCPIP__ */



/* The value shall synchronize with FLC2_MEM_ADM_CTRL_HEADER_LEN defined in flc2_mem_mngr_config.h */
//#define FLC2_MEM_ADM_CTRL_HEADER_LEN (((sizeof(flc2_mb_adm_ctrl_header_struct)+3)/4)*4)
#define FLC2_CUS_MEM_ADM_CTRL_HEADER_LEN  (20) 


/* MM BLOCK 11 */
/* ADM, BLOCK SIZE, 64, 384, 640, 1636 */
/* For SPDU TPDU (TCP/IP, socket)*/

#ifndef FLC2_MAX
#define FLC2_MAX(FLC_A, FLC_B)   (((FLC_A) > (FLC_B)) ? (FLC_A):(FLC_B))
#endif

#define FLC2_MM_BLOCK_11_SIZE ( FLC2_SPDU_UL_POOL_SIZE + \
                                FLC2_HS_POOL_SIZE + \
                                FLC2_MAX(FLC2_SPDU_UL_MAX_GROW_SIZE, FLC2_HS_POOL_MAX_GROW_SIZE) + \
                                FLC2_TPDU_POOL_SIZE + \
                                FLC2_CUS_MEM_ADM_CTRL_HEADER_LEN)

#define FLC2_MM_BLOCK_12_SIZE ( FLC2_SPDU_DL_POOL_SIZE + \
                                FLC2_CUS_MEM_ADM_CTRL_HEADER_LEN)

/* End of MM BLOCK 11 */




typedef enum {
	GPRS_FLC_UL,	/* Uplink */
	GPRS_FLC_DL	    /* Downlink */
} gprs_flc_dir_enum;


/* Global variable declaration. */
extern kal_uint32 flc2_mm_block_11_g[];
extern kal_uint32 flc2_mm_block_12_g[];


extern kal_uint32 flc_get_profile_info_spdu_ul(kal_uint32 *total_size_em_mode, kal_uint32 *max_grow_size);
extern kal_uint32 flc_get_profile_info_spdu_dl(kal_uint32 *max_grow_size);
extern kal_uint32 flc_get_profile_info_tpdu(kal_uint32 *max_grow_size);

extern kal_uint32* flc_get_mb_info_index_11(kal_uint32 *total_size, kal_uint32 *max_grow_size);
extern kal_uint32* flc_get_mb_info_index_12(kal_uint32 *total_size, kal_uint32 *max_grow_size);


#endif /* _CUSTOM_FLC_CONFIG_H */ 

