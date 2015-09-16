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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   dcxo_div_public.h
 *
 * Project:
 * --------
 *   General with 32K-Less Feature
 *
 * Description:
 * ------------
 *   Provide public API interface of DCXO divider to other modulers for 32k-less control.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/ 
#ifndef __DCXO_DIV_PUBLIC_H__
#define __DCXO_DIV_PUBLIC_H__ 

#if defined(__F32_XOSC_REMOVAL_SUPPORT__)

#include "kal_general_types.h" // for kal type define
#include "kal_public_defs.h"
#include "kal_public_api.h"    // for kal assert define

#if defined(MT6280_S01) || (defined(MT6752) && defined(__MD2__))
#define IS_32K_REMOVAL_LPM_CNT_SUPPORT
#endif

#if defined(MT6572) || defined(MT6582)
#define LPM_DIV_UPDATE_LOCK_SUPPORT
#endif

typedef enum
{
   DCXO_DIV_INIT = 0,
   
   DCXO_DIV_L1_TICK,
   DCXO_DIV_L1_UPDATE,

   DCXO_DIV_UL1_TICK,
   DCXO_DIV_UL1_UPDATE,
   
   DCXO_DIV_TL1_TICK,
   DCXO_DIV_TL1_UPDATE
} DCXO_DIV_UPDATE_MODE;

#ifdef IS_32K_REMOVAL_LPM_CNT_SUPPORT
#ifdef LPM_DIV_UPDATE_LOCK_SUPPORT
kal_int32 DCXO_Div_GetLPMDeltaFreqErr( void );
kal_uint32 DCXO_Div_GetAccLPMCnt( void );
kal_uint32 DCXO_Div_GetLastUpdateLPMCnt( void );
void DCXO_Div_UpdateLPMParam_Unlock(DCXO_DIV_UPDATE_MODE mode, kal_bool lpmDivUpdated, kal_int32 deltaFreqErr, kal_int32 deltaFreqCAFC, kal_uint8 adjuster );
kal_bool DCXO_Div_CheckUpdateCondition_Lock( kal_uint8 adjuster );
#endif
#endif

#endif /* __F32_XOSC_REMOVAL_SUPPORT__ */	 
#endif /* __DCXO_DIV_PUBLIC_H__ */

