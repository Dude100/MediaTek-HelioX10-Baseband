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
 *    uart_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for UART driver.
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
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef UART_HW_H
#define UART_HW_H

#if __LTE_TBC__
#include "dma_hw.h"
#endif
#include "drv_comm.h"

#if !defined(DRV_UART_OFF)

/*used in Task or normal function*/
#define UART_RBR(_baseaddr)		(_baseaddr+0x0)		/* Read only */
#define UART_THR(_baseaddr)		(_baseaddr+0x0)		/* Write only */
#define UART_IER(_baseaddr)		(_baseaddr+0x4)
#define UART_IIR(_baseaddr)		(_baseaddr+0x8)		/* Read only */
#define UART_FCR(_baseaddr)		(_baseaddr+0x8)		/* Write only */
#define UART_LCR(_baseaddr)		(_baseaddr+0xc)
#define UART_MCR(_baseaddr)		(_baseaddr+0x10)
#define UART_LSR(_baseaddr)		(_baseaddr+0x14)
#define UART_MSR(_baseaddr)		(_baseaddr+0x18)
#define UART_SCR(_baseaddr)		(_baseaddr+0x1c)
#define UART_DLL(_baseaddr)		(_baseaddr+0x0)
#define UART_DLH(_baseaddr)		(_baseaddr+0x4)
#define UART_EFR(_baseaddr)		(_baseaddr+0x8)		/* Only when LCR = 0xbf */
#define UART_XON1(_baseaddr)		(_baseaddr+0x10)	/* Only when LCR = 0xbf */
#define UART_XON2(_baseaddr)		(_baseaddr+0x14)	/* Only when LCR = 0xbf */
#define UART_XOFF1(_baseaddr)		(_baseaddr+0x18)	/* Only when LCR = 0xbf */
#define UART_XOFF2(_baseaddr)		(_baseaddr+0x1c)	/* Only when LCR = 0xbf */

#define	UART_RATE_STEP(_baseaddr)	(_baseaddr+0x24)
#define	UART_STEP_COUNT(_baseaddr)	(_baseaddr+0x28)
#define	UART_SAMPLE_COUNT(_baseaddr)	(_baseaddr+0x2c)
#define	UART_RATE_FIX_REG(_baseaddr)	(_baseaddr+0x34)
#define	UART_AUTO_BAUDSAMPLE(_baseaddr)	(_baseaddr+0x38)
#define	UART_GUARD(_baseaddr)		(_baseaddr+0x3C)
#define	UART_ESCAPE_DAT(_baseaddr)	(_baseaddr+0x40)
#define	UART_ESCAPE_EN(_baseaddr)	(_baseaddr+0x44)
#define	UART_SLEEP_EN(_baseaddr)	(_baseaddr+0x48)
#define	UART_DMA_EN(_baseaddr)		(_baseaddr+0x4c)
#define UART_RXTRI(_baseaddr)		(_baseaddr+0x50)


//IER
#if defined(DRV_UART_FIFO_FLOW_CONTROL)
#define UART_IER_ERBFI			0x0001
#define UART_IER_ETBEI			0x0002
#define UART_IER_ELSI			0x0004
#define UART_IER_EDSSI			0x0008
#define UART_IER_XOFFI			0x0020
#define UART_IER_RTSI			0x0040
#define UART_IER_CTSI			0x0080

#define IER_HW_NORMALINTS		0x001d
#define IER_HW_ALLINTS			0x001f
#define IER_SW_NORMALINTS		0x003d
#define IER_SW_ALLINTS			0x003f

#define UART_IER_ALLOFF			0x0010 //because of UART_IER_VFF_FC_EN not one of interrupt masks
#define UART_IER_VFIFO			0x0011	
#else //#if defined(DRV_UART_FIFO_FLOW_CONTROL)
#define UART_IER_ERBFI			0x0001
#define UART_IER_ETBEI			0x0002
#define UART_IER_ELSI			0x0004
#define UART_IER_EDSSI			0x0008
#define UART_IER_XOFFI			0x0020
#define UART_IER_RTSI			0x0040
#define UART_IER_CTSI			0x0080

#define IER_HW_NORMALINTS		0x000d
#define IER_HW_ALLINTS			0x000f
#define IER_SW_NORMALINTS		0x002d
#define IER_SW_ALLINTS			0x002f

#define UART_IER_ALLOFF			0x0000
#define UART_IER_VFIFO			0x0001	
#endif //#if defined(DRV_UART_FIFO_FLOW_CONTROL)



#define	UART_RATE_STEP_16		0x0000   /* baud = clock/UART_RATE_STEP/divisor */
#define	UART_RATE_STEP_8		0x0001
#define	UART_RATE_STEP_4		0x0002
#define	UART_RATE_STEP_COUNT		0x0003   /* baud = clock/UART_RATE_STEP_COUNT */
#define UART_STEP_COUNT_MASK		0x00ff
#define UART_SAMPLE_COUNT_MASK		0x00ff


//FCR
#define UART_FCR_FIFOEN			0x0001
#define UART_FCR_CLRR			0x0002
#define UART_FCR_CLRT			0x0004
#define UART_FCR_FIFOINI		0x0007
#define UART_FCR_RX1Byte_Level		0x0000
#define UART_FCR_RX16Byte_Level		0x0040
#define UART_FCR_RX32Byte_Level		0x0080
#define UART_FCR_RX62Byte_Level		0x00c0

#define UART_FCR_TX1Byte_Level		0x0000
#define UART_FCR_TX16Byte_Level		0x0010
#define UART_FCR_TX32Byte_Level		0x0020
#define UART_FCR_TX62Byte_Level		0x0030

#define   UART_FCR_Normal		(UART_FCR_TX1Byte_Level | UART_FCR_RX16Byte_Level | UART_FCR_FIFOINI)
#define   UART_FCR_RX_Normal		(UART_FCR_RX16Byte_Level | UART_FCR_FIFOINI) //VFIFO single channel
#define   UART_FCR_TX_Normal		(UART_FCR_TX1Byte_Level   | UART_FCR_FIFOINI) //VFIFO single channel
#define   UART1_TxFIFO_DEPTH		16
#define   UART1_RxFIFO_DEPTH		24
#define   UART2_TxFIFO_DEPTH		16	
#define   UART2_RxFIFO_DEPTH		24
#define   UART3_TxFIFO_DEPTH		16	
#define   UART3_RxFIFO_DEPTH		24

#if defined(DRV_UART_FIFO_FLOW_CONTROL) //Use larger size of RX FIFO, because it can trigger flow CONTROL_CHANNEL_MSG
#define	 UART_VFIFO_DEPTH		(UART_FCR_FIFOINI | UART_FCR_RX16Byte_Level)
#else
#define	 UART_VFIFO_DEPTH		7
#endif      

//IIR,RO
#define UART_IIR_INT_INVALID		0x0001
#define UART_IIR_RLS			0x0006  // Receiver Line Status
#define UART_IIR_RDA			0x0004  // Receive Data Available
#define UART_IIR_CTI			0x000C  // Character Timeout Indicator
#define UART_IIR_THRE			0x0002  // Transmit Holding Register Empty
#define UART_IIR_MS			0x0000  // Check Modem Status Register
#define UART_IIR_SWFlowCtrl		0x0010  // Receive XOFF characters
#define UART_IIR_HWFlowCtrl		0x0020  // CTS or RTS Rising Edge
#define UART_IIR_FIFOS_ENABLED		0x00c0
#define UART_IIR_NO_INTERRUPT_PENDING   0x0001
#define UART_IIR_INT_MASK		0x001f

//===============================LCR================================
//WLS
#define UART_WLS_8			0x0003
#define UART_WLS_7			0x0002
#define UART_WLS_6			0x0001
#define UART_WLS_5			0x0000
#define UART_DATA_MASK			0x0003

//Parity
#define UART_NONE_PARITY		0x0000
#define UART_ODD_PARITY			0x0008
#define UART_EVEN_PARITY		0x0018
#define UART_MARK_PARITY		0x0028
#define UART_SPACE_PARITY		0x0038
#define UART_PARITY_MASK		0x0038

//Stop bits
#define UART_1_STOP			0x0000
#define UART_1_5_STOP			0x0004  // Only valid for 5 data bits
#define UART_2_STOP			0x0004
#define UART_STOP_MASK			0x0004

#define UART_LCR_DLAB			0x0080
#define UART_LCR_BREAK			0x0040
//===============================LCR================================

//MCR
#define UART_MCR_DTR			0x0001
#define UART_MCR_RTS			0x0002
#define UART_MCR_LOOPB			0x0010
#define UART_MCR_IRE			0x0040	//Enable IrDA modulation/demodulation
#define UART_MCR_XOFF			0x0080
#define UART_MCR_Normal			(UART_MCR_DTR | UART_MCR_RTS)
#define UART_MCR_DCM_EN			0x0020


//LSR
#define UART_LSR_DR			0x0001
#define UART_LSR_OE			0x0002
#define UART_LSR_PE			0x0004
#define UART_LSR_FE			0x0008
#define UART_LSR_BI			0x0010
#define UART_LSR_THRE			0x0020
#define UART_LSR_TEMT			0x0040
#define UART_LSR_FIFOERR		0x0080

//MSR
#define UART_MSR_DCTS			0x0001
#define UART_MSR_DDSR			0x0002
#define UART_MSR_TERI			0x0004
#define UART_MSR_DDCD			0x0008
#define UART_MSR_CTS			0x0010
#define UART_MSR_DSR			0x0020
#define UART_MSR_RI			0x0040
#define UART_MSR_DCD			0x0080

//DLL
//DLM
//EFR
#define UART_EFR_AutoCTS		0x0080
#define UART_EFR_AutoRTS		0x0040
#define UART_EFR_Enchance		0x0010
#define UART_EFR_SWCtrlMask		0x000f
#define UART_EFR_NoSWFlowCtrl		0x0000
#define UART_EFR_ALLOFF			0x0000
#define UART_EFR_AutoRTSCTS		0x00c0

#define UART_EFR_SWFlowCtrlOFF		(0x0000)
#define UART_EFR_HWFLowCtrlTx		(1<<7)
#define UART_EFR_HWFLowCtrlRx		(1<<6)
#define UART_EFR_SWFlowCtrlX1_TX	(1<<3)
#define UART_EFR_SWFlowCtrlX2_TX	(1<<2)
#define UART_EFR_SWFlowCtrlX1_RX	(1<<1)
#define UART_EFR_SWFlowCtrlX2_RX	(1<<0)
#if defined(DRV_UART_FIFO_FLOW_CONTROL) //add 0x10 RX FIFO flow control in all values.
//Tx/Rx XON1/Xoff1 as flow control word
#define UART_EFR_SWFlowCtrlX1		0x001a	
//Tx/Rx XON2/Xoff2 as flow control word
#define UART_EFR_SWFlowCtrlX2		0x0015
//Tx/Rx XON1&XON2/Xoff1&Xoff2 as flow control word
#define UART_EFR_SWFlowCtrlXAll		0x001f
#else //#if defined(DRV_UART_FIFO_FLOW_CONTROL)
#define UART_EFR_SWFlowCtrlX1		0x000a
#define UART_EFR_SWFlowCtrlX2		0x0005
#define UART_EFR_SWFlowCtrlXAll		0x000f
#endif//#if defined(DRV_UART_FIFO_FLOW_CONTROL)

#define	UART_TXRXDMA_ON			0x0001
#define UART_TXRXDMA_OFF		0x0000

#define UART_RXTRI_VALUE		0x12

#if defined(DRV_UART_VFIFO_V2)

#ifdef DMA_POP
#undef DMA_POP
#endif

#ifdef DMA_PUSH
#undef DMA_PUSH
#endif

#define DMA_POP(_n)                 DRV_Reg8(DRV_Reg(DMA_VFF_RPT(_n))+DRV_Reg32(DMA_SRC(_n)));\
	if(DRV_Reg(DMA_VFF_RPT(_n)) == (DRV_Reg(DMA_VFF_SIZE(_n))-1))\
		DRV_WriteReg32(DMA_VFF_RPT(_n), (~DRV_Reg32(DMA_VFF_RPT(_n)))&0x10000);\
	else \
		DRV_WriteReg32(DMA_VFF_RPT(_n), DRV_Reg32(DMA_VFF_RPT(_n))+1);

#define DMA_PUSH(_n,_data)          while(DRV_Reg(DMA_W_INT_BUF_SIZE(_n))>=64);*(volatile kal_uint8*)DMA_VPORT(_n) = (kal_uint8)_data;
#define DMA_PUSH32(_n,_data)      while(DRV_Reg(DMA_W_INT_BUF_SIZE(_n))>60);*(volatile kal_uint32*)DMA_VPORT(_n) = (kal_uint32)_data;

#endif //#if defined(DRV_UART_VFIFO_V2)

#if defined(DRV_UART_VFIFO_V3)

#ifdef DMA_POP
#undef DMA_POP
#endif

#ifdef DMA_PUSH
#undef DMA_PUSH
#endif

#define DMA_POP(_n)                 DRV_Reg8(DRV_Reg(DMA_VFF_RPT(_n))+DRV_Reg32(DMA_SRC(_n)));\
	if(DRV_Reg(DMA_VFF_RPT(_n)) == (DRV_Reg(DMA_VFF_SIZE(_n))-1))\
		DRV_WriteReg32(DMA_VFF_RPT(_n), (~DRV_Reg32(DMA_VFF_RPT(_n)))&0x10000);\
	else \
		DRV_WriteReg32(DMA_VFF_RPT(_n), DRV_Reg32(DMA_VFF_RPT(_n))+1);

#define DMA_PUSH(_n,_data) \
		DRV_WriteReg8(DRV_Reg(DMA_VFF_WPT(_n))+DRV_Reg32(DMA_SRC(_n)),_data);\
		if(DRV_Reg(DMA_VFF_WPT(_n)) == (DRV_Reg(DMA_VFF_SIZE(_n))-1))\
		DRV_WriteReg32(DMA_VFF_WPT(_n), (~DRV_Reg32(DMA_VFF_WPT(_n)))&0x10000);\
		else \
		DRV_WriteReg32(DMA_VFF_WPT(_n), DRV_Reg32(DMA_VFF_WPT(_n))+1);

#endif //#if defined(DRV_UART_VFIFO_V3)



#endif /*#if !defined(DRV_UART_OFF)*/
#endif /*UART_HW_H*/


