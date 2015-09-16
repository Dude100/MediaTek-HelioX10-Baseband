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
 *    drv_sw_features_usb.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for all usb software feature options.
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __DRV_SW_FEATURES_USB_H__
#define __DRV_SW_FEATURES_USB_H__

#include "drv_features_usb.h"

#if defined(DRV_USB_LOGGING_V1)
	#define __USB_SW_LOGGING_V1__
#elif defined(DRV_USB_LOGGING_V2)
	#define __USB_SW_LOGGING_V2__
#elif defined(DRV_USB_LOGGING_V3)
	#define __USB_SW_LOGGING_V3__
#elif defined(DRV_USB_LOGGING_V4)
	#define __USB_SW_LOGGING_V4__
#elif defined(DRV_USB_LOGGING_V5)
	#define __USB_SW_LOGGING_V5__
#elif defined(DRV_USB_LOGGING_V6)
	#define __USB_SW_LOGGING_V6__
#elif defined(DRV_USB_LOGGING_V7)
	#define __USB_SW_LOGGING_V7__
#elif defined(DRV_USB_LOGGING_V8)
	#define __USB_SW_LOGGING_V8__
#endif

#if (defined(DRV_USB_LOGGING_V2)||defined(DRV_USB_LOGGING_V3)||defined(DRV_USB_LOGGING_V5)||defined(DRV_USB_LOGGING_V6)||defined(DRV_USB_LOGGING_V7)||defined(DRV_USB_LOGGING_V8))
	#define __USB_SW_LOGGING_WITH_ISR__
#endif

#if defined(DRV_USB_DMA_SOL)
	#define __USB_SW_DMA_DIV__
#endif

#endif /*__DRV_SW_FEATURES_USB_H__*/
