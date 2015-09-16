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
 *    drv_features_mt6516.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for MT6516 driver features.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef DRV_FEATURES_MT6516_H
#define DRV_FEATURES_MT6516_H

#if  defined(MT6516)
/* Add by CS5: Kengchu */
#define DRV_EMIMPU
#define __GCU_SUPPORT__

/* Features for LCD */
#define DRV_LCD_MT6516_SERIES

/* Features for Image Data Path */

/*end of XXXXX*/

/* Features for TVout */

#if defined (__APPLICATION_PROCESSOR__) //Only for BTMT Test
/* Features for USB */
#define DRV_USB_6516_SERIES 					/* support USB 6516 SERIES IP */
#endif

/* Features for UPLL */
//#define DRV_UPLL_6516_SERIES

/* Features for MP4 */

/* H264 FEATURES */
#define DRV_H264_6238_SERIES

/* Features for ADC */
#if defined(__APPLICATION_PROCESSOR__)
  // MT6516 AP
#define DRV_ADC_MT6516_AP_SERIES
#define DRV_TP_6516_AP_SERIES
#else // #if defined(__APPLICATION_PROCESSOR__)
  // MT6516 MD
//#define DRV_ADC_6223_SERIES
#define DRV_ADC_NOT_EXIST
#endif // #if defined(__APPLICATION_PROCESSOR__)

/* Features for GCU*/
#define DRV_GCU_6225_SERIES

/* Features for GPT*/
#define DRV_GPT_6516_SERIES

/* Features for KBD*/
#define DRV_KBD_NOT_EXIST

/* Features for PWM */
#if defined(__APPLICATION_PROCESSOR__)
#define DRV_PWM_6216_AP_SERIES
#else
#define DRV_PWM_NOT_EXIST
#endif

#define DRV_ALERTER_NOT_EXIST

/* Features for RTC */
#if defined(__APPLICATION_PROCESSOR__)
#define DRV_RTC_6268_SERIES
#else
#define DRV_RTC_NOT_EXIST
#endif

/* Features for WDT */
#define DRV_WDT_6217_SERIES

/* Features for UART */
#define DRV_UART_6516_SERIES
//#define DRV_UART_TK6516_SERIES

// The number of UART VFIFO channels
#define DRV_UART_VFIFO_CHANNEL_COUNT		2

/* Features for IrDA */
/* No IrDA in MD side. */

/* Features for GPIO */
/* No GPIO in MD side. */
#define DRV_GPIO_TK6516_SERIES

/* Misc. driver featuers */
#if defined(__APPLICATION_PROCESSOR__)
  // MT6516 AP
#define DRV_MISC_MT6516_AP_SERIES
#else // #if defined(__APPLICATION_PROCESSOR__)
  // MT6516 MD
//#define DRV_MISC_6516_SERIES
#define DRV_MISC_MT6516_SERIES
#endif // #if defined(__APPLICATION_PROCESSOR__)

/*Multimedia init*/

/*SIM*/
#define SIM_PDN_REG_VERSION_3

/*Features for SIM*/
#define DRV_2_SIM_CONTROLLER

/*storage cached transfer support*/
#define SIM_CACHED_SUPPORT

/*Above is MT6516*/
#endif /* MT6516*/

#endif   /*DRV_FEATURES_MT6516_H*/
