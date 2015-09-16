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
 *    drv_features_uart.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for the uart driver feature option
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DRV_FEATURES_UART_H__
#define __DRV_FEATURES_UART_H__

#include "drv_features_chip_select.h"

/**************** UART ******************/
#if defined(DRV_UART_6205_SERIES)
   #define DRV_UART_6205_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_OLD_DMA
   #define DRV_UART3_NO_DMA
   #define DRV_UART_2_FIFO_DEPTHS
#elif defined(DRV_UART_6205B_SERIES)
   #define DRV_UART_6205B_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_OLD_DMA
   #define DRV_UART3_NO_DMA
   #define DRV_UART_NO_AUTOESCAPE
   #define DRV_UART_SLEEP_NO_FC
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_2_FIFO_DEPTHS
#elif defined(DRV_UART_6208_SERIES)
   #define DRV_UART_6208_REG
   #define DRV_UART_NO_AUTOESCAPE
   #define DRV_UART_6208_FC_SETTING
   #define DRV_UART_SLEEP_NO_FC
   #define DRV_UART1_NO_DMA  
   #define DRV_UART2_NO_DMA
   #define DRV_UART3_NO_DMA
   #define DRV_UART_1_FIFO_DEPTH
#elif defined(DRV_UART_6217_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_NORMAL_DMA
    #define DRV_UART3_NO_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_NO_UART3_PDN
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG1
   #define DRV_UART_2_FIFO_DEPTHS
#elif defined(DRV_UART_6218_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_NORMAL_DMA
    #define DRV_UART3_NO_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_6218_TX_DMA
   #define DRV_UART_2_FIFO_DEPTHS
#elif defined(DRV_UART_6218B_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_NORMAL_DMA
    #define DRV_UART3_NO_DMA
   #define DRV_UART_6218B_AUTOESCAPE
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_NO_UART3_PDN
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG1
   #define DRV_UART_2_FIFO_DEPTHS
#elif defined(DRV_UART_6219_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA 
   #define DRV_UART2_NORMAL_DMA
    #define DRV_UART3_NO_DMA
   #define DRV_UART_6219_AUTOESCAPE
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG2
   #define DRV_UART_2_FIFO_DEPTHS
#elif defined(DRV_UART_6227_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_NORMAL_DMA
    #define DRV_UART3_NO_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG2
   #define DRV_UART_2_FIFO_DEPTHS
#elif defined(DRV_UART_6225_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_NORMAL_DMA
    #define DRV_UART3_NO_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG2
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
#elif defined(DRV_UART_6251_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_NORMAL_DMA
   #define DRV_UART3_NO_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG7
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
   #define DRV_UART_GUARD_DALAY_IN_3M
   #define DRV_UART_COMPENSATE_AT
   #define DRV_UART_FIFO_FLOW_CONTROL    
#elif defined(DRV_UART_6253T_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_NORMAL_DMA
    #define DRV_UART3_NO_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG3 // different from 6225 series
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
   #define DRV_UART_GUARD_DALAY_IN_3M
   #define DRV_UART_COMPENSATE_AT
   #define DRV_UART_FIFO_FLOW_CONTROL 
   #define DRV_UART_FRACTIONAL
#elif defined(DRV_UART_6253EL_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_NORMAL_DMA
   #define DRV_UART3_NO_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG8 // different from 6225 series
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
   #define DRV_UART_GUARD_DALAY_IN_3M
   #define DRV_UART_COMPENSATE_AT
   #define DRV_UART_FIFO_FLOW_CONTROL     
   #define DRV_UART_FRACTIONAL
   #define DRV_UART_DCM_BUG_FIXED

#elif defined(DRV_UART_6268T_SERIES)
   // Copy from DRV_UART_6227_SERIES
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_NORMAL_DMA
   #define DRV_UART3_NO_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG2
   #define DRV_UART_2_FIFO_DEPTHS
   // Indicate MT6268T VFIFO is on FPGA
   #define DRV_UART_FPGA_VFIFO
   #define DRV_UART_FPGA_CLOCK
#elif defined(DRV_UART_6268A_SERIES)
   // Copy from DRV_UART_6268T_SERIES
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_NORMAL_DMA
   #define DRV_UART3_NO_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG2
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
   #define DRV_UART_SLEEP_MODE_WORK_AROUND
   #define DRV_UART_MCU_MULTI_POP_PUSH
   #define DRV_UART_FRACTIONAL
#elif defined(DRV_UART_6268_SERIES)
   // Copy from DRV_UART_6268T_SERIES
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_NORMAL_DMA
   #define DRV_UART3_NO_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG4
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
   #define DRV_UART_SLEEP_MODE_WORK_AROUND
   #define DRV_UART_MCU_MULTI_POP_PUSH
   #define DRV_UART_FRACTIONAL
   //When use VFIFO, MT6268 E1 can enable UART HW FIFO flow control. 
   //This can prevent RX FIFO overflow under BT high throughput.
   #define DRV_UART_FIFO_FLOW_CONTROL 
#elif defined(DRV_UART_6270A_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NORMAL_DMA
   #define DRV_UART2_NORMAL_DMA
   #define DRV_UART3_NORMAL_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG4
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
   #define DRV_UART_SLEEP_MODE_WORK_AROUND
   #define DRV_UART_MCU_MULTI_POP_PUSH
   #define DRV_UART_FRACTIONAL
   #define DRV_UART_FIFO_FLOW_CONTROL   
#elif defined(DRV_UART_6280TK_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NORMAL_DMA
   #define DRV_UART2_NORMAL_DMA
   #define DRV_UART3_NORMAL_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG4
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
   #define DRV_UART_SLEEP_MODE_WORK_AROUND
   #define DRV_UART_MCU_MULTI_POP_PUSH
   #define DRV_UART_FRACTIONAL
   #define DRV_UART_FIFO_FLOW_CONTROL
   #define DRV_UART_SET_REG_DELAY_FOR_HW_BUG   //add liming:for uart hw bug,when set uart register,there may be error,for example:when set  LCR fron 0xbf to 0x03,MCR and XON1 will be mix up. Delay several codes will be ok.
   #define DRV_UART_CLOCK_6144M   //uart clock
#elif defined(DRV_UART_6236_SERIES)
   // Copy from DRV_UART_6268_SERIES
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_NORMAL_DMA
   #define DRV_UART3_NO_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG5 
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
   #define DRV_UART_SLEEP_MODE_WORK_AROUND
   #define DRV_UART_MCU_MULTI_POP_PUSH
   #define DRV_UART_FRACTIONAL
   #define DRV_UART_FIFO_FLOW_CONTROL 
   #define DRV_UART_POWER_ON_BEFORE_ACCESS
#elif defined(DRV_UART_6516_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA
#ifdef __MODEM_CONTROL_UART4__
   #define DRV_UART2_NO_DMA
   #define DRV_UART2_USE_UART4
#else
   #define DRV_UART2_NORMAL_DMA
#endif //__MODEM_CONTROL_UART4__
   #define DRV_UART3_NO_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG2
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
   #define DRV_UART_NO_PDN_CTRL
   #define DRV_UART_NO_UART_CG_BIT
   #define DRV_UART_SWITCHABLE_BETWEEN_PROCESSORS
#elif defined(DRV_UART_TK6516_SERIES)
// TK6516 chip UART options
   // On TK6516 we sim DMA is a must run item, so UART can NOT perform any read operation when SIM DMA
   // is activated
   // On TK6516 series, UART may assigned to AP or MD usage
   #define DRV_UART_SWITCHABLE_BETWEEN_PROCESSORS
// No generic DMA
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
//   #define DRV_UART2_NORMAL_DMA
   // We need to define NO_DMA to disable DMA clearly
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_NO_DMA
   #define DRV_UART3_NO_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_DMA_VFIFO_CONFIG2
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
   #define DRV_UART_NO_PDN_CTRL
#elif defined(DRV_UART_6276_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_NO_DMA
   #define DRV_UART3_NO_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
   #define DRV_UART_MCU_MULTI_POP_PUSH
   #define DRV_UART_FRACTIONAL
   #if !defined(MT6276_S01)
   #define DRV_UART_AUTOBAUD_61M
   #define DRV_UART_DMA_VFIFO_CONFIG6
   #define DRV_UART_VFIFO_V2
   #else
   #define DRV_UART_DCM_BUG_FIXED
   #define DRV_UART_VFIFO_V3
   #define DRV_UART_DMA_VFIFO_CONFIG9
   //Bei add for uart hw can not flush DMA internal buffer bug fix
   #define DRV_UART_DMA_INTERNAL_BUFFER_WORKAROUND
   #endif
   #define DRV_UART_DMA_EXTEND
#elif defined(DRV_UART_6573_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_NO_DMA
   #define DRV_UART3_NO_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
 //  #define DRV_UART_SLEEP_MODE_WORK_AROUND
   #define DRV_UART_MCU_MULTI_POP_PUSH
   #define DRV_UART_FRACTIONAL
   #define DRV_UART_AUTOBAUD_61M
   #define DRV_UART_DMA_EXTEND
   #define DRV_UART_DMA_VFIFO_CONFIG6
   #define DRV_UART_VFIFO_V2
   #define DRV_UART_NO_PDN_CTRL
   #define DRV_UART_NO_UART_CG_BIT
   #define DRV_UART_SWITCHABLE_BETWEEN_PROCESSORS
#elif defined(DRV_UART_6575_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_NO_DMA
   #define DRV_UART3_NO_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
	//	#define DRV_UART_SLEEP_MODE_WORK_AROUND
   #define DRV_UART_MCU_MULTI_POP_PUSH
   #define DRV_UART_FRACTIONAL
//   #define DRV_UART_AUTOBAUD_61M
//	#define DRV_UART_DCM_BUG_FIXED// for 6575 bringup
   #define DRV_UART_DMA_EXTEND
   #define DRV_UART_DMA_VFIFO_CONFIG10
   #define DRV_UART_VFIFO_V3
   #define DRV_UART_NO_PDN_CTRL
   #define DRV_UART_NO_UART_CG_BIT
   #define DRV_UART_SWITCHABLE_BETWEEN_PROCESSORS
   #define DRV_UART_DMA_INTERNAL_BUFFER_WORKAROUND
   #define DRV_MD_2_UART
   #define DRV_UART_PUTBYTE_DELAY
#elif defined(DRV_UART_6256_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_NO_DMA
   #define DRV_UART3_NO_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
   #define DRV_UART_MCU_MULTI_POP_PUSH
   #define DRV_UART_FRACTIONAL 
   #define DRV_UART_DCM_BUG_FIXED
   #define DRV_UART_VFIFO_V3
   #define DRV_UART_DMA_VFIFO_CONFIG9 
   #define DRV_UART_DMA_EXTEND
   #define DRV_UART_DMA_INTERNAL_BUFFER_WORKAROUND   //Bei add for uart hw can not flush DMA internal buffer bug fix
#elif defined(DRV_UART_6255_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA
   #define DRV_UART2_NO_DMA
   #define DRV_UART3_NO_DMA
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
   #define DRV_UART_MCU_MULTI_POP_PUSH
   #define DRV_UART_FRACTIONAL
   #define DRV_UART_DCM_NO_BUG // there is not bug when enable DCM  (liming add --- 3 stage:   stage 1: HW bug,disable DCM when DCM enable   stage2:add a bit to fix this bug   stage3: there is no HW bug )
   #define DRV_UART_VFIFO_V3
   #define DRV_UART_DMA_VFIFO_CONFIG9
   #define DRV_UART_DMA_EXTEND
   #define DRV_UART_CLOCK_52M//phase out MT6255 option in uart.c ,use this driver features to define uart clock ,but must kown the new chip's clock when the new chip bring up!!!
//end
  #elif defined(DRV_UART_6280_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA		
   #define DRV_UART2_NO_DMA		
   #define DRV_UART3_NO_DMA		
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
   #define DRV_UART_MCU_MULTI_POP_PUSH
   #define DRV_UART_FRACTIONAL
   #define DRV_UART_DCM_NO_BUG // there is not bug when enable DCM  (liming add --- 3 stage:   stage 1: HW bug,disable DCM when DCM enable   stage2:add a bit to fix this bug   stage3: there is no HW bug )
   #define DRV_UART_VFIFO_V3
 
   #define DRV_UART_DMA_EXTEND
   #define DRV_UART_CLOCK_52M
   
   #define DRV_UART_DMA_VFIFO_CONFIG11   //liming add , need review
   #define DRV_UART_NO_PDN_CTRL
   #define DRV_UART_NO_UART_CG_BIT
   #define DRV_UART_SWITCHABLE_BETWEEN_PROCESSORS
   //#define DRV_MD_1_UART   //// for MD only have one uart port,like MT6280	
   //if MT6280 MD side want to use uart2,please remove the faeture option
    #define DRV_MD_UART2_USE_AP_UART1  //if MT6280 MD side want to use uart2,please add the faeture option
#elif defined(DRV_UART_6583_SERIES)
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA		
   #define DRV_UART2_NO_DMA		
   #define DRV_UART3_NO_DMA		
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
   #define DRV_UART_MCU_MULTI_POP_PUSH
   #define DRV_UART_FRACTIONAL
   #define DRV_UART_DCM_NO_BUG // there is not bug when enable DCM  (liming add --- 3 stage:   stage 1: HW bug,disable DCM when DCM enable   stage2:add a bit to fix this bug   stage3: there is no HW bug )
   #define DRV_UART_VFIFO_V3  // MD1 & MD2 use VFIFO DMA V3
   #define DRV_UART_DMA_EXTEND
   #define DRV_UART_CLOCK_52M
   #define DRV_UART_DMA_VFIFO_CONFIG11   /*MD1 & MD2 's  VFIFO  DMA  channel  is  the same as 6280*/
   #define DRV_UART_NO_PDN_CTRL
   #define DRV_UART_NO_UART_CG_BIT
   #define DRV_UART_SWITCHABLE_BETWEEN_PROCESSORS
   #define DRV_MD_1_UART   /* MD1  & MD2  each has only 1 UART */
   
   /*  History bug 's workaround is as below */
   
   #define DRV_UART_AUTO_BAUDRATE_BUG // there is a bug on auto baudrate,Rx maybe hang when the DLL and DLM are not 1 before  auto baudrate.//workaround:  clear DLL and DLM before auto baudrate.
   #define DRV_UART_TX_RX_CLEAR_BUG   // because of uart tx clear bug:  maybe send dirty byte when clear tx FIFO,	 if close FIFO before clear,that's OK
   #define DRV_UART_DMA_ENABLE_HANG_BUG // DMA TX maybe hang when connect META use DMA mode
 #ifdef __MD2__
   #define DRV_UART_BUS_EARLY_RESPONSE//for MT6255 & MT6256 early response
 #endif
    #if defined(__DMA_UART_VIRTUAL_FIFO__)  //which is defined in makefile
  #define DRV_UART_USE_VFIFO_MODE  /*  UART use MCU  mode or DMA mode on officail load instead of UDVT load*/
  #endif
   //#define DRV_UART_TEST_FOR_BRING_UP /*test uart rx/tx  for bring-up*/

 #elif defined(DRV_UART_6572_SERIES) 
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA		
   #define DRV_UART2_NO_DMA		
   #define DRV_UART3_NO_DMA		
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
   #define DRV_UART_MCU_MULTI_POP_PUSH
   #define DRV_UART_FRACTIONAL
   #define DRV_UART_DCM_NO_BUG // there is not bug when enable DCM  (liming add --- 3 stage:   stage 1: HW bug,disable DCM when DCM enable   stage2:add a bit to fix this bug   stage3: there is no HW bug )
   #define DRV_UART_VFIFO_V3  // MD1 & MD2 use VFIFO DMA V3
   #define DRV_UART_DMA_EXTEND
   #define DRV_UART_CLOCK_52M
   #define DRV_UART_DMA_VFIFO_CONFIG11   /*MD1 & MD2 's  VFIFO  DMA  channel  is  the same as 6280*/
   #define DRV_UART_NO_PDN_CTRL
   #define DRV_UART_NO_UART_CG_BIT
   #define DRV_UART_SWITCHABLE_BETWEEN_PROCESSORS
   #define DRV_MD_1_UART   /* MD1  & MD2  each has only 1 UART */
   
   /*  History bug 's workaround is as below */
   
   #define DRV_UART_AUTO_BAUDRATE_BUG // there is a bug on auto baudrate,Rx maybe hang when the DLL and DLM are not 1 before  auto baudrate.//workaround:  clear DLL and DLM before auto baudrate.
   #define DRV_UART_TX_RX_CLEAR_BUG   // because of uart tx clear bug:  maybe send dirty byte when clear tx FIFO,	 if close FIFO before clear,that's OK
   #define DRV_UART_DMA_ENABLE_HANG_BUG // DMA TX maybe hang when connect META use DMA mode
  #if defined(__DMA_UART_VIRTUAL_FIFO__)  //which is defined in makefile
  #define DRV_UART_USE_VFIFO_MODE  /*  UART use MCU  mode or DMA mode on officail load instead of UDVT load*/
  #endif
   //#define DRV_UART_TEST_FOR_BRING_UP /*test uart rx/tx  for bring-up*/
 #elif defined(DRV_UART_6582_SERIES) 
   #define DRV_UART_BASIC_REG
   #define DRV_UART_VFIFO_EN_REG
   #define DRV_UART1_NO_DMA		
   #define DRV_UART2_NO_DMA		
   #define DRV_UART3_NO_DMA		
   #define DRV_UART_HIGH_SPEED
   #define DRV_UART_AUTO_BAUD
   #define DRV_UART_SLEEP_MODE
   #define DRV_UART_SPEED_SAMPLE_COUNT
   #define DRV_UART_2_FIFO_DEPTHS
   #define DRV_UART_MCU_MULTI_POP_PUSH
   #define DRV_UART_FRACTIONAL
   #define DRV_UART_DCM_NO_BUG // there is not bug when enable DCM  (liming add --- 3 stage:   stage 1: HW bug,disable DCM when DCM enable   stage2:add a bit to fix this bug   stage3: there is no HW bug )
   #define DRV_UART_VFIFO_V3  // MD1 & MD2 use VFIFO DMA V3
   #define DRV_UART_DMA_EXTEND
   #define DRV_UART_CLOCK_52M
   #define DRV_UART_DMA_VFIFO_CONFIG11   /*MD1 & MD2 's  VFIFO  DMA  channel  is  the same as 6280*/
   #define DRV_UART_NO_PDN_CTRL
   #define DRV_UART_NO_UART_CG_BIT
   #define DRV_UART_SWITCHABLE_BETWEEN_PROCESSORS
   #define DRV_MD_1_UART   /* MD1  & MD2  each has only 1 UART */
   
   /*  History bug 's workaround is as below */
   
   #define DRV_UART_AUTO_BAUDRATE_BUG // there is a bug on auto baudrate,Rx maybe hang when the DLL and DLM are not 1 before  auto baudrate.//workaround:  clear DLL and DLM before auto baudrate.
   #define DRV_UART_TX_RX_CLEAR_BUG   // because of uart tx clear bug:  maybe send dirty byte when clear tx FIFO,	 if close FIFO before clear,that's OK
   #define DRV_UART_DMA_ENABLE_HANG_BUG // DMA TX maybe hang when connect META use DMA mode
  #if defined(__DMA_UART_VIRTUAL_FIFO__)  //which is defined in makefile
  #define DRV_UART_USE_VFIFO_MODE  /*  UART use MCU  mode or DMA mode on officail load instead of UDVT load*/
  #endif
   #define DRV_UART_TEST_FOR_BRING_UP /*test uart rx/tx  for bring-up*/
#endif

#ifdef __MEUT__
#define DCL_UART_INTERFACE
#endif

#endif
