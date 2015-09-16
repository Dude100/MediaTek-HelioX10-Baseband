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
 *    drv_features_6253E.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for MT6235 driver features.
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
#ifndef DRV_FEATURES_6253E_H
#define DRV_FEATURES_6253E_H

#if  defined(MT6253E)

/* Features for LCD */
#define DRV_LCD_MT6253EL_SERIES

/**** Features for Image Data Path -- START ****/
#define DRV_IDP_6252_SERIES
/**** Features for Image Data Path -- END ******/

/* Features for MSDC */
#define DRV_MSDC_MT6253EL_SERIES

/* Features for USB */
#define DRV_USB_6253EL_SERIES 					/* support USB 6253EL SERIES IP */


/* Features for UPLL */
#define DRV_UPLL_6253_SERIES 					/* support UPLL 6238 SERIES IP */

/* Features for MP4 */
//#define DRV_MP4_6238_SERIES 						/* support MP4 6228 SERIES IP */

/* Features for I2C */
#define DRV_I2C_6225_BASIC_SERIES

/* Features for ADC */
#define DRV_ADC_6252_SERIES
#define DRV_TP_6253EL_SERIES

/* Features for GCU*/
#define DRV_GCU_6225_SERIES

/* Features for GPT*/
//#define DRV_GPT_6217_SERIES
#define DRV_GPT_6238_SERIES // for GPT: DRV_GPT_DIRECT_SLEEP_MODE_HANDLE

/* Features for KBD*/
#define DRV_KBD_6238_SERIES

/* Features for PWM */
#define DRV_PWM_6253_SERIES
#define DRV_ALERTER_NOT_EXIST

/* Features for RTC */
#define DRV_RTC_6253_SERIES

/* Features for WDT */
#define DRV_WDT_6217_SERIES

/* Features for UART */
#define DRV_UART_6253EL_SERIES

/* Features for IrDA */
#define DRV_IRDA_6228_SERIES

/* Features for GPIO */
#define DRV_GPIO_6253E_SERIES

/* Misc. driver featuers */
#define DRV_MISC_6253EL_SERIES

/* Features for Camera ISP */
#define DRV_ISP_6235_SERIES
#define DRV_ISP_MT6252_HW_SUPPORT

//#define DRV_SPI_SUPPORT
/* Features for BMT */
#define DRV_BMT_6252_SERIES

/*storage cached transfer support*/
/*Blue mark them all for 53 E/L DVT*/
#define SIM_CACHED_SUPPORT

/*Features for SIM*/
#define DRV_2_SIM_CONTROLLER

#define SIM_TOUT_REG_V2
#define __DRV_SIM_REG_ON_PDN_V2__

/// JPEG
#define __DRV_GRAPHICS_JPEG_6253EL_SERIES__

/// RGB Resizer
#define __DRV_GRAPHICS_RGB_RESIZER_6253_SERIES__

/// RGB Rotator
#define __DRV_GRAPHICS_RGB_ROTATOR_6253_SERIES__

/// YUV Rotator
#define __DRV_GRAPHICS_YUV_ROTATOR_6253_SERIES__

#define DRV_MM_POWER_CTRL_MT6252_SERIES

/*Above is MT6253E*/
#endif /* MT6253E*/
#endif   /*DRV_FEATURES_6253E_H*/
