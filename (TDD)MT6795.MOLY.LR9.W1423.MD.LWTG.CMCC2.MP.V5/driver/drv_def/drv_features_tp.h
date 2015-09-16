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
 *    drv_features_tp.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for the touch panel driver feature option
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
#ifndef __DRV_FEATURES_TP_H__
#define __DRV_FEATURES_TP_H__

#include "drv_features_chip_select.h"

#if defined(DRV_TP_6235_SERIES)
   #define DRV_TOUCH_PANEL_PAIR_GUARANTEE
   #define DRV_TOUCH_PANEL_CUSTOMER_PARAMETER
   #define __DRV_TP_MEMORY_TRACE__

#ifdef TOUCH_PANEL_INTERNAL
   #define DRV_AUX_ADC_TP_MESSED_UP_WA
   #define DRV_TP_STAT_NOT_UP_TO_DATE_WA
   #define DRV_TP_ADC_WARM_UP_ISSUE_WA
   #define DRV_TOUCH_PANEL_MULTIPLE_PICK
   #define __DRV_TP_DISCARD_SHIFTING__
   #define DRV_ADC_TOUCH_SCREEN
   #define DRV_TP_NO_EXT_EINT
   #ifndef TOUCH_PANEL_PRESSURE
   #define TOUCH_PANEL_PRESSURE
   #endif
#endif /* TOUCH_PANEL_INTERNAL */
   #define DRV_TP_6235_SETTING

#elif defined(DRV_TP_6238_SERIES)
   #define DRV_TOUCH_PANEL_PAIR_GUARANTEE
   #define DRV_TOUCH_PANEL_CUSTOMER_PARAMETER
   #define __DRV_TP_MEMORY_TRACE__

#ifdef TOUCH_PANEL_INTERNAL
   #define DRV_AUX_ADC_TP_MESSED_UP_WA
   #define DRV_TP_STAT_NOT_UP_TO_DATE_WA
   #define DRV_TP_ADC_WARM_UP_ISSUE_WA
   #define DRV_TOUCH_PANEL_MULTIPLE_PICK
   #define __DRV_TP_DISCARD_SHIFTING__
   #define DRV_ADC_TOUCH_SCREEN
   #define DRV_TP_NO_EXT_EINT
   #ifndef TOUCH_PANEL_PRESSURE
   #define TOUCH_PANEL_PRESSURE
   #endif
#endif /* TOUCH_PANEL_INTERNAL */

#define DRV_TP_6253_SETTING

#elif defined(DRV_TP_6236_SERIES)  
   #define DRV_TOUCH_PANEL_PAIR_GUARANTEE
   #define DRV_TOUCH_PANEL_CUSTOMER_PARAMETER
   #define __DRV_TP_MEMORY_TRACE__

#ifdef TOUCH_PANEL_INTERNAL
   #define DRV_AUX_ADC_TP_MESSED_UP_WA
   #define DRV_TP_STAT_NOT_UP_TO_DATE_WA
   #define DRV_TP_ADC_WARM_UP_ISSUE_WA
   #define DRV_MT6268A_ADC_TP_MIXED_ISSUE_WA
   #define DRV_TOUCH_PANEL_MULTIPLE_PICK
   #define __DRV_TP_DISCARD_SHIFTING__
   #define DRV_ADC_TOUCH_SCREEN
   #define DRV_TP_NO_EXT_EINT
   #ifndef TOUCH_PANEL_PRESSURE
   #define TOUCH_PANEL_PRESSURE
   #endif
 #define DRV_ADC_TOUCH_SCREEN_OFFSET_0X50
#endif /* TOUCH_PANEL_INTERNAL */

   #define DRV_TP_6253_SETTING
   #define DRV_TP_IRQ_TPC
  
   
#elif defined(DRV_TP_6268_SERIES)
   #define DRV_TOUCH_PANEL_PAIR_GUARANTEE
   #define DRV_TOUCH_PANEL_CUSTOMER_PARAMETER
   #define __DRV_TP_MEMORY_TRACE__

#ifdef TOUCH_PANEL_INTERNAL
   #define DRV_AUX_ADC_TP_MESSED_UP_WA
   #define DRV_TP_ADC_WARM_UP_ISSUE_WA
   #define DRV_TP_STAT_NOT_UP_TO_DATE_WA
   #define DRV_MT6268A_ADC_TP_MIXED_ISSUE_WA
   #define DRV_TOUCH_PANEL_MULTIPLE_PICK
   #define __DRV_TP_DISCARD_SHIFTING__
   #define DRV_ADC_TOUCH_SCREEN
   #define DRV_TP_NO_EXT_EINT
   #ifndef TOUCH_PANEL_PRESSURE
   #define TOUCH_PANEL_PRESSURE
   #endif // #ifndef TOUCH_PANEL_PRESSURE
 
   #define DRV_ADC_TOUCH_SCREEN_OFFSET_0X50
#endif /* TOUCH_PANEL_INTERNAL */

#define DRV_TP_6268_SETTING

#elif defined(DRV_TP_6253_SERIES)
   #define DRV_TOUCH_PANEL_PAIR_GUARANTEE
   #define DRV_TOUCH_PANEL_CUSTOMER_PARAMETER
   #define __DRV_TP_MEMORY_TRACE__

#ifdef TOUCH_PANEL_INTERNAL
   #define DRV_TP_ADC_WARM_UP_ISSUE_WA
   #define DRV_AUX_ADC_TP_MESSED_UP_WA
   #define DRV_TP_STAT_NOT_UP_TO_DATE_WA
   #define DRV_MT6268A_ADC_TP_MIXED_ISSUE_WA
   #define DRV_TOUCH_PANEL_MULTIPLE_PICK
   #define __DRV_TP_DISCARD_SHIFTING__
   #define DRV_ADC_TOUCH_SCREEN
   #define DRV_TP_NO_EXT_EINT
   #ifndef TOUCH_PANEL_PRESSURE
   #define TOUCH_PANEL_PRESSURE
   #endif
   /*
      Indicate ADC touch screen register from offset 0x50
   */
   #define DRV_ADC_TOUCH_SCREEN_OFFSET_0X50
#endif /* TOUCH_PANEL_INTERNAL */

   #define DRV_TP_6253_SETTING


#elif defined(DRV_TP_6255_SERIES)
   #define DRV_TOUCH_PANEL_PAIR_GUARANTEE
   #define DRV_TOUCH_PANEL_CUSTOMER_PARAMETER
   #define __DRV_TP_MEMORY_TRACE__

#ifdef TOUCH_PANEL_INTERNAL
   #define DRV_TOUCH_PANEL_MULTIPLE_PICK
   #define __DRV_TP_DISCARD_SHIFTING__
   #define DRV_ADC_TOUCH_SCREEN
   #define DRV_TP_NO_EXT_EINT
   #ifndef TOUCH_PANEL_PRESSURE
   #define TOUCH_PANEL_PRESSURE
   #endif
   /*
      Indicate ADC touch screen register from offset 0x50
   */
   #define DRV_ADC_TOUCH_SCREEN_OFFSET_0X50
#endif
   #define DRV_TP_PENUP_FIXED
   #define DRV_TP_IRQ_TPC
   #define DRV_TP_SPL_NUM_ABB_8708
   
   #elif defined(DRV_TP_6256_SERIES) 
   #define DRV_TOUCH_PANEL_PAIR_GUARANTEE
   #define DRV_TOUCH_PANEL_CUSTOMER_PARAMETER
   #define __DRV_TP_MEMORY_TRACE__

#ifdef TOUCH_PANEL_INTERNAL
   #define DRV_TOUCH_PANEL_MULTIPLE_PICK
   #define __DRV_TP_DISCARD_SHIFTING__
   #define DRV_ADC_TOUCH_SCREEN
   #define DRV_TP_NO_EXT_EINT
   #ifndef TOUCH_PANEL_PRESSURE
   #define TOUCH_PANEL_PRESSURE
   #endif
   /*
      Indicate ADC touch screen register from offset 0x50
   */
   #define DRV_ADC_TOUCH_SCREEN_OFFSET_0X50
#endif
   #define DRV_TP_PENUP_FIXED
   #define DRV_TP_IRQ_TPC
   #define DRV_TP_SPL_NUM_ABB_1708
   
	
#elif defined(DRV_TP_6276_SERIES)
   #define DRV_TOUCH_PANEL_PAIR_GUARANTEE
   #define DRV_TOUCH_PANEL_CUSTOMER_PARAMETER
   #define __DRV_TP_MEMORY_TRACE__

#ifdef TOUCH_PANEL_INTERNAL
   #define DRV_TP_ADC_WARM_UP_ISSUE_WA
   #define DRV_AUX_ADC_TP_MESSED_UP_WA
   #define DRV_TP_STAT_NOT_UP_TO_DATE_WA
   #define DRV_MT6268A_ADC_TP_MIXED_ISSUE_WA
   #define DRV_TOUCH_PANEL_MULTIPLE_PICK
   #define __DRV_TP_DISCARD_SHIFTING__
   #define DRV_ADC_TOUCH_SCREEN
   #define DRV_TP_NO_EXT_EINT
   #ifndef TOUCH_PANEL_PRESSURE
   #define TOUCH_PANEL_PRESSURE
   #endif
   /*
      Indicate ADC touch screen register from offset 0x50
   */
   #define DRV_ADC_TOUCH_SCREEN_OFFSET_0X50
 #endif
   
   #define DRV_TP_6253_SETTING
   #define DRV_TP_PENUP_FIXED
	 
#elif defined(DRV_TP_6253EL_SERIES)
   #define DRV_TOUCH_PANEL_PAIR_GUARANTEE
   #define DRV_TOUCH_PANEL_CUSTOMER_PARAMETER
   #define __DRV_TP_MEMORY_TRACE__
   #define  DRV_TP_PENUP_FIXED	

#ifdef TOUCH_PANEL_INTERNAL
   #define DRV_TP_ADC_WARM_UP_ISSUE_WA
   #define DRV_AUX_ADC_TP_MESSED_UP_WA
   #define DRV_TP_STAT_NOT_UP_TO_DATE_WA
   #define DRV_MT6268A_ADC_TP_MIXED_ISSUE_WA
   #define DRV_TOUCH_PANEL_MULTIPLE_PICK
   #define __DRV_TP_DISCARD_SHIFTING__
   #define DRV_ADC_TOUCH_SCREEN
   #define DRV_TP_NO_EXT_EINT
   #ifndef TOUCH_PANEL_PRESSURE
   #define TOUCH_PANEL_PRESSURE
   #endif
  
  #define DRV_ADC_TOUCH_SCREEN_OFFSET_0X50
#endif

  #define DRV_TP_6253_SETTING

#elif defined(DRV_TP_6516_AP_SERIES)

#ifdef TOUCH_PANEL_INTERNAL
   #define DRV_AUX_ADC_TP_MESSED_UP_WA
   #define DRV_TP_ADC_WARM_UP_ISSUE_WA
   #define DRV_TP_STAT_NOT_UP_TO_DATE_WA
   #define DRV_ADC_TOUCH_SCREEN
   #define DRV_TP_NO_EXT_EINT
   #ifndef TOUCH_PANEL_PRESSURE
   #define TOUCH_PANEL_PRESSURE
   #endif // #ifndef TOUCH_PANEL_PRESSURE
  
   #define DRV_ADC_TOUCH_SCREEN_OFFSET_0X50
   #define DRV_TP_6516_AP_SETTING
   
#endif

#endif

#ifdef __MEUT__
#define DCL_TS_INTERFACE
#endif

#endif
