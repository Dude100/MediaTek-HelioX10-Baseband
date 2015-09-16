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
 *    dma_config_mt6589.h
 *
 * Project:
 * --------
 *   WR8_Software
 *
 * Description:
 * ------------
 *   This file is intended for DMA driver.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _DMA_CONFIG_MT6752_H
#define _DMA_CONFIG_MT6752_H

#define __DMA_API_V2__ 					//DMA SW version
#define __DMA_V3__ 						//DMA HW version
#define __MULTI_CORE_SHARED_DMA__ 		//smartphone
#define __DMA_SIM_TX_RX_SUPPORT__ 

/*compile option for including AP-side DMA*/
//#define __DMA2_SUPPORT__		  		//use AP DMA

/******************************MD side***************************************************/ 
/*GDMA & PDMA channel info*/
#define DMA_ALL_CHANNEL          4  	//GDMA + PDMA channel number
#define DMA_MAX_CHANNEL          4 		//used DMA channel number
#define DMA_MAX_FULL_CHANNEL     2  	//GDMA channel number
#define DMA_FULL_CH_NUM     	 2		//for MD-side GDMA1 and GDMA2
#define DMA_HALF_CH_NUM    	 	 2		//for MD-side SIM and SIM2
#define DMA_VFF_CH_NUM      	 2		//for MD-side UART1 TX, UART1 RX

/*VFIFO channel info*/
#if defined (__BTMODULE_MT6752__)
#define __DMA_BT_VIRTUAL_FIFO__
#endif
#define DMA_VFIFO_PHY_CH_S  	 5      // Real VFIFO start channel number
#define DMA_CON_MASTER_UART1TX   0x05
#define DMA_CON_MASTER_UART1RX   0x06

/*for DMA interrupt mode*/
#define DMA_IRQ_CODE          	 IRQ_DMA_CODE

/*for DMA CG control*/
#define DMA_POWER_ON()        	 PDN_CLR(PDN_DMA)
#define DMA_SLEEP_ENABLE()		 PDN_SET(PDN_DMA)
#define DMA_SLEEP_DISABLE()      PDN_CLR(PDN_DMA)
/*======================================================================================*/

/******************************AP side***************************************************/ 
#if defined(__DMA2_SUPPORT__)
/*GDMA & PDMA channel info*/
#define DMA2_ALL_CHANNEL         12 	//G_DMA0, G_DMA1, HIF0, HIF1, IRDA0, I2C0, I2C1, I2C2, I2C3, I2C4, I2C5, I2C6, 
#define DMA2_MAX_CHANNEL         1  	//HIF1
#define DMA2_MAX_FULL_CHANNEL    0  	//NULL
#define DMA2_FULL_CH_NUM     	 2		//G_DMA0, G_DMA1
#define DMA2_HALF_CH_NUM     	 10		//HIF0, HIF1, IRDA0, I2C0, I2C1, I2C2, I2C3, I2C4, I2C5, I2C6
#define DMA2_VFF_CH_NUM      	 0		//for MD-side, we don't use AP-side's UART

/*VFIFO channel info*/
//doesn't use AP VFIFO DMA

/*for DMA interrupt mode*/
#define DMA2_IRQ_CODE            IRQ_AP_DMA_HIF1_CODE

/*for DMA CG control*/
#define DMA2_POWER_ON()          PDN_CLR(PDN_AP_DMA)
#define DMA2_SLEEP_ENABLE()      PDN_SET(PDN_AP_DMA)
#define DMA2_SLEEP_DISABLE()     PDN_CLR(PDN_AP_DMA)

#endif//__DMA2_SUPPORT__
/*======================================================================================*/

typedef enum {
	/*MD side */
    DMA_SW = 1,
    DMA_SW2 = 2,
    DMA_SIM = 3,
    DMA_SIM2 = 4,
    DMA_UART1TX = 5,
    DMA_UART1RX = 6,

	/*AP side*/
	#if defined(__DMA2_SUPPORT__)
    DMA_HIF1 = 0x84,
	#endif
    DMA_IDLE
} DMA_Master;

typedef enum {
   VDMA_UART1TX_CH = 5,
   VDMA_UART1RX_CH = 6,
} DMA_VFIFO_UART;  
 
#endif   /* !_DMA_CONFIG_MT6752_H */