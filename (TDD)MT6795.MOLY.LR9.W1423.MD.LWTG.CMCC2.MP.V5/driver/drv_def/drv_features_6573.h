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
 *    drv_features_6573.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for MT6276 driver features.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef DRV_FEATURES_6573_H
#define DRV_FEATURES_6573_H

#if  defined(MT6573)

#define __GCU_SUPPORT__

/* Features for LCD */
#define DRV_LCD_MT6573_SERIES

/* Features for USB */
#define DRV_USB_6573_SERIES

/* Features for UPLL */
#define DRV_UPLL_6276_SERIES

/* Features for I2C */
//#define DRV_I2C_6276_SERIES

/* Features for GCU*/
#define DRV_GCU_6225_SERIES


/* Features for ADC */
#define DRV_ADC_6573_SERIES


/* Features for WDT */
#define DRV_WDT_6573_SERIES

/* Features for RTC */
#define DRV_RTC_NOT_EXIST

/* Features for UART */
#define DRV_UART_6573_SERIES

/* Features for GPT*/
#define DRV_GPT_6276_SERIES

/* Features for KBD*/
#define DRV_KBD_NOT_EXIST

/* Features for PWM */
#define DRV_PWM_6268A_SERIES
#define DRV_ALERTER_NOT_EXIST

/* Features for GPIO */
#define DRV_GPIO_6573_SERIES


/* Features for Camera ISP */
#define DRV_ISP_6276_SERIES
//DRV_ISP_6238_SERIES

#define  DRV_ISP_MT6276_HW_SUPPORT

/* Features for BMT */
#define DRV_BMT_6573_SERIES


/* Features for MSDC */
#define DRV_MSDC_MT6276_SERIES

/* Features for HIF */
#define DRV_HIF_V1_SERIES

/* Misc. driver featuers */
#define DRV_MISC_6573_SERIES

/*Multimedia init*/
//#define MULTIMEDIA_INIT_MT6219_SERIES

/*Features for SIM*/
#define DRV_2_SIM_CONTROLLER

/*since I check in below setting with other CR, check in this line again*/
/*storage cached transfer support*/
#define MSDC_CACHED_SUPPORT
#define SIM_CACHED_SUPPORT

#define SIM_TOUT_REG_V2
#define DRV_SIM_DMA_V2
#define SIM_NAMING_FROM_0_ADDRESS //MT6573 is naming in SIM0, SIM1,..

#if defined(__MTK_TARGET__)
#define __3G_F8F9BC_HW_DRV_V1__
#define __3G_F8F9_THREE_SETS__
#endif

/*Above is MT6573*/
#endif /* MT6573*/
#endif   /*DRV_FEATURES_6573_H*/
