/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *    drv_features_gpt.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file defines driver feature options for GPT Drivers: 
*
 *    
 *    This file should only be included by HAL modules and should not be 
 *    included by non-HAL modules.
 *
 * Author:
 * -------
 * -------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __DRV_FEATURES_GPT_H__
#define __DRV_FEATURES_GPT_H__

#include "drv_features_chip_select.h"

/****************** GPT Feature Option List ************************
*	[H] means hardware feature option.  [S] means software feature option.
*1. [H]DRV_GPT_GPT3.		--> chip support Three GPTs
*2.	[S]DRV_GPT_STOP_2_STEP  --> Separate GPT_Stop into two step to avoid 60-qbit problem.
*3. [H]DRV_GPT_NO_GPT_CG_BIT  --> Indicate there is NO GPT bit in CG register
*4. [S]DRV_GPT_DIRECT_SLEEP_MODE_HANDLE -->GPT directly get l1 sleep mode handle and perform sleep enable/disable
*																			      Not through lpwr and pdn API
*5. [H] DRV_GPT_NO_PDN_BIT  -->Indicate there is NO GPT bit in CG register
*6. [H]DRV_GPT_GPT4  	 --> chip support Four GPTs. 
*
*****************************************************************/

/**************** GPT Feature Option******************/
#if defined(DRV_GPT_6217_SERIES)
   #define DRV_GPT_GPT3
#elif defined(DRV_GPT_6218B_SERIES)
   #define DRV_GPT_GPT3
   #define DRV_GPT_6218B_GPT3_TIMING_DEBUG
#elif defined(DRV_GPT_6225_SERIES)
   #define DRV_GPT_GPT3
   #define DRV_GPT_STOP_2_STEP
#elif defined(DRV_GPT_6268A_SERIES)
   #define DRV_GPT_GPT3
   #define DRV_GPT_NO_GPT_CG_BIT
   #define DRV_GPT_DIRECT_SLEEP_MODE_HANDLE
#elif defined(DRV_GPT_6238_SERIES)
   #define DRV_GPT_GPT3
   #define DRV_GPT_DIRECT_SLEEP_MODE_HANDLE
#elif defined(DRV_GPT_6253D_SERIES)
   #define DRV_GPT_GPT3
   #define DRV_GPT_DIRECT_SLEEP_MODE_HANDLE
   #define DRV_GPT_STOP_2_STEP
#elif defined(DRV_GPT_6516_SERIES)
   #define DRV_GPT_NO_GPT_CG_BIT
   #define DRV_GPT_GPT3
#elif defined(DRV_GPT_6236_SERIES)
   #define DRV_GPT_GPT3
   #define DRV_GPT_NO_PDN_BIT
   #define DRV_GPT_DIRECT_SLEEP_MODE_HANDLE
#elif defined(DRV_GPT_6270_SERIES)
   #define DRV_GPT_GPT3
   #define DRV_GPT_NO_PDN_BIT
   #define DRV_GPT_DIRECT_SLEEP_MODE_HANDLE
#elif defined(DRV_GPT_6276_SERIES)
   #define DRV_GPT_GPT3
   #define DRV_GPT_GPT4
   #define DRV_GPT_NO_PDN_BIT
   #define DRV_GPT_DIRECT_SLEEP_MODE_HANDLE
#elif defined(DRV_GPT_6589_SERIES)
   #define DRV_GPT_GPT3
   #define DRV_GPT_GPT4
   #define DRV_GPT_DIRECT_SLEEP_MODE_HANDLE
#elif defined(DRV_GPT_6752_SERIES)
	#define DRV_GPT_GPT3
	#define DRV_GPT_GPT4
	#define DRV_GPT_DIRECT_SLEEP_MODE_HANDLE 

#elif defined(DRV_GPT_6290_SERIES)   
   #define DRV_GPT_TOTAL_COUNTER       (6U)
#if defined(__CR4__)
   #define DRV_GPT_BASE_COUNTER_NUM    (1U)
   #define DRV_GPT_CALLBACK_TIMER      (1U)
   #define DRV_GPT_CBUS_TIMER          (2U)
   #define DRV_GPT_DEBUG_TIMER         (3U)
#elif defined(__ARM7EJ_S__) /* __CR4__ */
   #define DRV_GPT_BASE_COUNTER_NUM    (3U)
   #define DRV_GPT_CALLBACK_TIMER      (3U)
   #define DRV_GPT_CBUS_TIMER          (5U)
#endif /* __ARM7EJ_S__ */
   #define DRV_GPT_SYSTEM_TIMER        (4U)
#endif

//add this option for protection Test.
#if defined(__PROTECTION_SQC__)
   #if defined(MT6276) || defined(MT6236)
   #define __ENABLE_GPT_PROTECTION__
   #endif
#endif

#ifdef __MEUT__
#define DCL_GPT_INTERFACE
#endif
/**************** GPT Feature End******************/
#endif
