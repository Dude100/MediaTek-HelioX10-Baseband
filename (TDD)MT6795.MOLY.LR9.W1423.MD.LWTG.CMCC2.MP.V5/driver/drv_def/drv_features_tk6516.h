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
 *    drv_features_6238.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for MT6238 driver features.
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef DRV_FEATURES_TK6516_H
#define DRV_FEATURES_TK6516_H

#if  defined(TK6516)
#define __GCU_SUPPORT__
#define DRV_LCD_NOT_EXIST

#define DRV_LAYER_TOTAL_COUNT   6
#define DRV_LAYER_COLOR_FORMAT					/* support RGB888/ARGB8888 or not */
#define DRV_LAYER_ROTATE							/* support LCD layer rotate or not */
#define DRV_PALETTE_COUNT	1
#undef DRV_PALETTE_RGB_565							/* support color palette up to RGB565 */
#define DRV_PALETTE_RGB_888						/* support color palette up to RGB888 */
#define DRV_LCD_ROI_BACKGROUND_COLOR
#define DRV_LCD_MEMORY_OUTPUT

/*start of XXXXX*/
#define DRV_LCD_MEMORY_OUTPUT_RGB565_SUPPORT
#define DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT
#undef DRV_LCD_MEMORY_OUTPUT_ARGB8888_SUPPORT
#define DRV_LCD_GAMMA_CORRECTION_SUPPORT
#define DRV_LCD_GAMMA_CORRECTION_QUEUE_NUMBER 256
#define DRV_LCD_HW_TRIGGER_SUPPORT
#define DRV_LCD_DC_TRIGGER_SUPPORT 
#define DRV_LCD_CMD_QUEUE_COUNT 2
#define DRV_LCD_CMD_QUEUE_NUMBER 32
#undef DRV_LCD_FW_UPDATE_SUPPORT

/* Features for Image Data Path */

/*end of XXXXX*/

/* Features for TVout */


/* Features for USB */


/* Features for UPLL */


/* Features for MP4 */


/* Features for ADC */
#define DRV_ADC_6223_SERIES

/* Features for GCU*/
#define DRV_GCU_6225_SERIES

/* Features for GPT*/
#define DRV_GPT_6217_SERIES

/* Features for KBD*/
#define DRV_KBD_NOT_EXIST

/* Features for PWM */
#define DRV_PWM_NOT_EXIST
#define DRV_ALERTER_NOT_EXIST

/* Features for RTC */
#define DRV_RTC_NOT_EXIST

/* Features for WDT */
#define DRV_WDT_6217_SERIES

/* Features for UART */
//#define DRV_UART_6516_SERIES
#define DRV_UART_TK6516_SERIES

// The number of UART VFIFO channels
#define DRV_UART_VFIFO_CHANNEL_COUNT		2

/* Features for IrDA */
/* No IrDA in MD side. */

/* Features for GPIO */
/* No GPIO in MD side. */
#define DRV_GPIO_TK6516_SERIES

/* Misc. driver featuers */
#define DRV_MISC_6516_SERIES

/* JPEG FEATURES */


/*Multimedia init*/

/*Above is TK6516*/
#endif /* TK6516*/

#endif   /*DRV_FEATURES_TK6516_H*/
