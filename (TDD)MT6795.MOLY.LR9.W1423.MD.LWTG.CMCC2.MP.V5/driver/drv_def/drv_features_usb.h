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
 *    drv_features_usb.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for the usb driver features
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __DRV_FEATURES_USB_H__
#define __DRV_FEATURES_USB_H__

/**************** USB ******************/
#include "drv_features_chip_select.h"

#if defined(DRV_USB_6219_SERIES)
	#define DRV_USB_IP_V1
	#define DRV_USB_MCU_52M
#elif defined(DRV_USB_6227_SERIES)
	#define DRV_USB_IP_V1
#elif defined(DRV_USB_6225_SERIES)
	#define DRV_USB_IP_V1
	#define DRV_USB_LOGGING_V2
#elif defined(DRV_USB_6228_SERIES)
	#define DRV_USB_IP_V2
#elif defined(DRV_USB_6229_SERIES)
	#define DRV_USB_IP_V2
	#define DRV_USB_LOGGING_V1
#elif defined(DRV_USB_6238_SERIES)
	#define DRV_USB_IP_V3
	#define DRV_USB_LOGGING_V3
	#define DRV_USB_PHY_CHARGER_DETECT        
	#define DRV_USB_PHY_CURRENT_CONSUMPTION   
	#define DRV_USB_PHY_SUPPORT_OTG
	#define DRV_USB_DMA_SOL	
	#define MAX_EP_NUM		4
	#define MAX_TX_EP_NUM		4
	#define MAX_RX_EP_NUM		3
	#define MAX_DMA_NUM		4
	#define USB_MAX_FIFO_SIZE	4096
#elif defined(DRV_USB_6235_SERIES)
	#define DRV_USB_IP_V3
	#define DRV_USB_LOGGING_V3
	#define DRV_USB_PHY_CURRENT_CONSUMPTION
	#define DRV_USB_DMA_SOL	
	#define MAX_EP_NUM		4
	#define MAX_TX_EP_NUM		4
	#define MAX_RX_EP_NUM		3
	#define MAX_DMA_NUM		4
	#define USB_MAX_FIFO_SIZE	4096
#elif defined(DRV_USB_6268T_SERIES)
	#define DRV_USB_IP_V2
	#define DRV_USB_LOGGING_V4
#elif defined(DRV_USB_6268A_SERIES)  //6268A
	#define DRV_USB_IP_V3
	#define DRV_USB_LOGGING_V5
	#define DRV_USB_PHY_CHARGER_DETECT         
	#define DRV_USB_PHY_CURRENT_CONSUMPTION	
	#define DRV_USB_PHY_USB_UART_SHARE_PAD
	#define DRV_USB_PHY_SUPPORT_OTG
	#define DRV_USB_DMA_SOL	
	#define MAX_EP_NUM		4
	#define MAX_TX_EP_NUM		4
	#define MAX_RX_EP_NUM		3
	#define MAX_DMA_NUM		4
	#define USB_MAX_FIFO_SIZE	4096
#elif defined(DRV_USB_6268_SERIES)  //6268B
	#define DRV_USB_IP_V3
	#define DRV_USB_LOGGING_V5
	#define DRV_USB_PHY_CHARGER_DETECT         
	#define DRV_USB_PHY_CURRENT_CONSUMPTION	
	#define DRV_USB_PHY_USB_UART_SHARE_PAD
	#define DRV_USB_PHY_SUPPORT_OTG
	#define DRV_USB_PHY_COST_DOWN
	#define DRV_USB_PHY_65_INITIAL_VALUE		        
	#define DRV_USB_DMA_SOL		 
	#define MAX_EP_NUM		4
	#define MAX_TX_EP_NUM		4
	#define MAX_RX_EP_NUM		3
	#define MAX_DMA_NUM		4       
	#define USB_MAX_FIFO_SIZE	4096
#elif defined(DRV_USB_6516_SERIES)
	#define DRV_USB_IP_V3
	#define DRV_USB_LOGGING_V5
	#define DRV_USB_PHY_CHARGER_DETECT         
	#define DRV_USB_PHY_CURRENT_CONSUMPTION	
	#define DRV_USB_PHY_USB_UART_SHARE_PAD
	#define DRV_USB_PHY_SUPPORT_OTG
	#define MAX_EP_NUM		4
	#define MAX_TX_EP_NUM		4
	#define MAX_RX_EP_NUM		3
	#define MAX_DMA_NUM		4
	#define USB_MAX_FIFO_SIZE	4096
#elif defined(DRV_USB_6253T_SERIES)
	#define DRV_USB_IP_V3
	#define DRV_USB_LOGGING_V6 
	#define DRV_USB_PHY_CHARGER_DETECT
	#define DRV_USB_PHY_CURRENT_CONSUMPTION	
	#define DRV_USB_PHY_USB_UART_SHARE_PAD	
	#define DRV_USB_DMA_SOL	
	#define MAX_EP_NUM		4
	#define MAX_TX_EP_NUM		4
	#define MAX_RX_EP_NUM		3
	#define MAX_DMA_NUM		4
	#define USB_MAX_FIFO_SIZE	4096
#elif defined(DRV_USB_6253_SERIES)
	#define DRV_USB_IP_V3
	#define DRV_USB_LOGGING_V6 
	#define DRV_USB_PHY_CHARGER_DETECT
	#define DRV_USB_PHY_CURRENT_CONSUMPTION	
	#define DRV_USB_PHY_USB_UART_SHARE_PAD	
	#define DRV_USB_PHY_COST_DOWN  
	#define DRV_USB_PHY_M110_INITIAL_VALUE		
	#define DRV_USB_COST_DOWN_CHIP	
	#define DRV_MT6253_VERSION_CONTROL
	#define DRV_USB_DMA_BW_LIMIT  //MT6253 DMA INC4
	#define DRV_USB_DMA_SOL	
	#define MAX_EP_NUM		4
	#define MAX_TX_EP_NUM		4
	#define MAX_RX_EP_NUM		3
	#define MAX_DMA_NUM		4
	#define USB_MAX_FIFO_SIZE	2304
#elif defined(DRV_USB_6253EL_SERIES)
	#define DRV_USB_IP_V1_PLUS //Mentor1.1 enhance
	#define DRV_USB_LOGGING_V6
	#define DRV_USB_PHY_CURRENT_CONSUMPTION
	#define DRV_USB_PHY_U65_IP	
	#define MAX_EP_NUM		4
	#define MAX_TX_EP_NUM		4
	#define MAX_RX_EP_NUM		2
	#define MAX_DMA_NUM		0
	#define USB_MAX_FIFO_SIZE	4096
#elif defined(DRV_USB_6236_SERIES) 
	#define DRV_USB_IP_V3
	#define DRV_USB_LOGGING_V5
	#define DRV_USB_PHY_CHARGER_DETECT         
	#define DRV_USB_PHY_CURRENT_CONSUMPTION	
	#define DRV_USB_PHY_USB_UART_SHARE_PAD
	#define DRV_USB_PHY_COST_DOWN	
	#define DRV_USB_PHY_65_INITIAL_VALUE
	#define DRV_MT6236_VERSION_CONTROL	//E0
//	#define DRV_USB_PPP_BW_LIMIT // MT6236 BW -> ADMUX
	#define DRV_USB_DMA_BW_LIMIT  //MT6236 BW -> ADMUX
	#define DRV_USB_PHY_CALIBRATION		
	#define DRV_USB_SHARE_PAD_UART_DL
	#define DRV_USB_DMA_SOL
	#define MAX_EP_NUM		4
	#define MAX_TX_EP_NUM		4
	#define MAX_RX_EP_NUM		3
	#define MAX_DMA_NUM		4
	#define USB_MAX_FIFO_SIZE	4096
#elif defined(DRV_USB_6270A_SERIES) 
	#define DRV_USB_IP_V3
	#define DRV_USB_LOGGING_V5 //not test
	#define DRV_USB_PHY_CHARGER_DETECT         
	#define DRV_USB_PHY_CURRENT_CONSUMPTION	
	#define DRV_USB_PHY_USB_UART_SHARE_PAD
	#define DRV_USB_PHY_SUPPORT_OTG
	#define DRV_USB_PHY_COST_DOWN
	#define DRV_USB_PHY_65_INITIAL_VALUE			
	#define MAX_EP_NUM		4
	#define MAX_TX_EP_NUM		4
	#define MAX_RX_EP_NUM		3
	#define MAX_DMA_NUM		4
	#define USB_MAX_FIFO_SIZE	4096
#elif defined(DRV_USB_6276_SERIES)
	#define DRV_USB_IP_V3
	//#define DRV_USB_LOGGING_V5
	#define DRV_USB_LOGGING_V8 //MDCI
	#define DRV_USB_PHY_CHARGER_DETECT         
	#define DRV_USB_PHY_CURRENT_CONSUMPTION	
	#define DRV_USB_PHY_SUPPORT_OTG
	#define DRV_USB_PHY_U65_IP	
	#define DRV_USB_SUPPORT_DCM
	#define __USB_HS_SLEW_RATE_CAL__
	#define MAX_EP_NUM		4
	#define MAX_TX_EP_NUM		4
	#define MAX_RX_EP_NUM		3
	#define MAX_DMA_NUM		4
	#define USB_MAX_FIFO_SIZE	4096
#elif defined(DRV_USB_6256_SERIES)
	#define DRV_USB_IP_V3
	#define DRV_USB_LOGGING_V5 
	#define DRV_USB_LOGGING_V5_SINGLE_DSP	//6256E1 is dual DSP
	#define DRV_USB_PHY_CURRENT_CONSUMPTION
	#define DRV_USB_PHY_M60_IP	
	#define __USB_HS_SLEW_RATE_CAL__
	#define DRV_USB_COST_DOWN_CHIP
	#define MAX_EP_NUM		4
	#define MAX_TX_EP_NUM		4
	#define MAX_RX_EP_NUM		3
	#define MAX_DMA_NUM		4
	#define USB_MAX_FIFO_SIZE	2304
#elif defined(DRV_USB_6251_SERIES)
	#define DRV_USB_IP_V1_PLUS //Mentor1.1 enhance
	#define DRV_USB_LOGGING_V3 
	#define DRV_USB_PHY_U65_IP	
	#define MAX_EP_NUM		4
	#define MAX_TX_EP_NUM		4
	#define MAX_RX_EP_NUM		2
	#define MAX_DMA_NUM		0
	#define USB_MAX_FIFO_SIZE	4096
#elif defined(DRV_USB_6573_SERIES)
	#define DRV_USB_IP_V3
	#define DRV_USB_LOGGING_V5
	#define DRV_USB_PHY_CHARGER_DETECT
	#define DRV_USB_PHY_CURRENT_CONSUMPTION
	#define DRV_USB_PHY_SUPPORT_OTG
	#define DRV_USB_PHY_U65_IP
	#define MAX_EP_NUM		4
	#define MAX_TX_EP_NUM		4
	#define MAX_RX_EP_NUM		3
	#define MAX_DMA_NUM		4
	#define USB_MAX_FIFO_SIZE	4096
#elif defined(DRV_USB_6575_SERIES)  //6276
	#define DRV_USB_IP_V4
	#define DRV_USB_LOGGING_V5
	#define DRV_USB_PHY_CHARGER_DETECT
	#define DRV_USB_PHY_CURRENT_CONSUMPTION
	#define DRV_USB_PHY_SUPPORT_OTG
	#define DRV_USB_PHY_U40_IP	
	#define MAX_EP_NUM		4
	#define MAX_TX_EP_NUM		4
	#define MAX_RX_EP_NUM		3
	#define MAX_DMA_NUM		4
	#define USB_MAX_FIFO_SIZE	4096
#elif defined(DRV_USB_6255_SERIES)
	#define DRV_USB_IP_V4
	#define DRV_USB_LOGGING_V5
	#define DRV_USB_LOGGING_V5_SINGLE_DSP
	#define DRV_USB_PHY_CURRENT_CONSUMPTION
	#define DRV_USB_PHY_M60_IP
	#define DRV_USB_COST_DOWN_CHIP	
	#define __USB_HS_SLEW_RATE_CAL__		
	#define MAX_EP_NUM		4
	#define MAX_TX_EP_NUM		4
	#define MAX_RX_EP_NUM		3
	#define MAX_DMA_NUM		4
	#define USB_MAX_FIFO_SIZE	2304
#elif defined(DRV_USB_6280_SERIES)
	#define DRV_USB_IP_V4
	#define DRV_USB_LOGGING_V5
	#define DRV_USB_LOGGING_V5_SINGLE_DSP
	#define DRV_USB_PHY_CURRENT_CONSUMPTION
	#define DRV_USB_PHY_SUPPORT_OTG
	#define DRV_USB_PHY_U40_IP
	#define DRV_USB_SUPPORT_DCM
	#define DRV_USB_HW_TX_DIRECT_PATH_SUPPORT
	#define DRV_USB_DMA_QUEUE_SUPPORT
	#define DRV_USB_POWER_DOWN_SUPPORT	//allow sleep in USB SUSPEND(USB_POWERDWN_Mode)
#if defined(MT6280_S01)
	#define DRV_USB_SLEEP_SUPPORT //MT6280 E2 allow modem sleep but USB still in normal mode! (USB IRQ is wakeup source)
 #endif
	#define __USB_HS_SLEW_RATE_CAL__
	#define MAX_EP_NUM		8
	#define MAX_TX_EP_NUM		8
	#define MAX_RX_EP_NUM		6
	#define MAX_DMA_NUM		8
	#define USB_MAX_FIFO_SIZE	8192
#elif defined(DRV_USB_6583_SERIES)
	#define DRV_USB_IP_V4
	#define DRV_USB_LOGGING_V5
	#define DRV_USB_LOGGING_V5_SINGLE_DSP
	#define DRV_USB_LOGGING_SLEEP_DIS	
	#define DRV_USB_PHY_CURRENT_CONSUMPTION
	#define DRV_USB_PHY_T28_IP
    //  #define __USB_HS_SLEW_RATE_CAL__
	#define MAX_EP_NUM		4
	#define MAX_TX_EP_NUM		4
	#define MAX_RX_EP_NUM		3
	#define MAX_DMA_NUM		4
	#define USB_MAX_FIFO_SIZE	4096	
	#define DRV_USB_FORCE_TRIGGER_ONE_EINT
#elif defined(DRV_USB_6572_SERIES)
	#define DRV_USB_IP_V4
	#define DRV_USB_LOGGING_V5
	#define DRV_USB_LOGGING_V5_SINGLE_DSP	
	#define DRV_USB_PHY_CURRENT_CONSUMPTION
	#define DRV_USB_PHY_T28_IP
//	#define __USB_HS_SLEW_RATE_CAL__
	#define MAX_EP_NUM		8
	#define MAX_TX_EP_NUM		8
	#define MAX_RX_EP_NUM		8
	#define MAX_DMA_NUM		8
	#define USB_MAX_FIFO_SIZE	8192	
//	#define DRV_USB_FORCE_TRIGGER_ONE_EINT	
#elif defined(DRV_USB_6582_SERIES)
	#define DRV_USB_IP_V4
	#define DRV_USB_LOGGING_V5
	#define DRV_USB_LOGGING_V5_SINGLE_DSP	
	#define DRV_USB_PHY_CURRENT_CONSUMPTION
	#define DRV_USB_PHY_T28_IP
//	#define __USB_HS_SLEW_RATE_CAL__
	#define MAX_EP_NUM		8
	#define MAX_TX_EP_NUM		8
	#define MAX_RX_EP_NUM		8
	#define MAX_DMA_NUM		8
	#define USB_MAX_FIFO_SIZE	8192	
//	#define DRV_USB_FORCE_TRIGGER_ONE_EINT	
#endif

#if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)||defined(DRV_USB_IP_V3) 
   // CHR_USB_EINT UnMask use central control
   #define DRV_MISC_CHR_USB_EINT_CENTRAL_UNMASK
#endif

#if defined(DRV_USB_PHY_USB_UART_SHARE_PAD)
	#define  __USB_AND_UART_WITH_ONE_PORT__
#endif

/**************** UPLL *******************/
#if defined(DRV_UPLL_6219_SERIES)
	#define DRV_UPLL_V1
#elif defined(DRV_UPLL_6228_SERIES)
	#define DRV_UPLL_V2
#elif defined(DRV_UPLL_6225_SERIES)
	#define DRV_UPLL_V3
#elif defined(DRV_UPLL_6268T_SERIES)
	#define DRV_UPLL_V4
#elif defined(DRV_UPLL_6238_SERIES)
	#define DRV_UPLL_V5
#elif defined(DRV_UPLL_6268_SERIES)
	#define DRV_UPLL_V6
#elif defined(DRV_UPLL_6516_SERIES)
	#define DRV_UPLL_V6	
#elif defined(DRV_UPLL_6253_SERIES)
	#define DRV_UPLL_V7		
#elif defined(DRV_UPLL_6236_SERIES)
	#define DRV_UPLL_V7
#elif defined(DRV_UPLL_6276_SERIES)
	#define DRV_UPLL_V8		
#endif


#endif /*End __DRV_FEATURES_USB_H__*/
