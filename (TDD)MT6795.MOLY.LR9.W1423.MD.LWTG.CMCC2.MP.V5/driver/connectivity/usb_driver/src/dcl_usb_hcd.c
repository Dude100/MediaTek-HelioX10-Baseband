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
 *   dcl_usb_hcd.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  This file defines the DCL common definitions for USB host driver.
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
#include "drv_comm.h"
#include "reg_base.h"
  
#include "drvpdn.h"
#include "intrCtrl.h"
#include "gpio_sw.h"
#include "dma_hw.h"
#include "dma_sw.h"
#include "init.h"
#include "cache_sw.h"

#include "usb_hw.h"
#include "eint.h"
#include "usb_hcd.h"
#include "usb_hcd_pri.h"
#include "drv_hisr.h"
//#include "stack_common.h"        /* sap_type */
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"                /* msg_type */
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */

//#include "stack_common.h"        /* sap_type */
//#include "stack_msgs.h"                /* msg_type */
//#include "app_ltlcom.h"       /* Task message communiction */
#include "otg_if.h"
#include "otg_drv.h"
#include "usb_debug_tool.h"
#if defined(__IC_USB_ENABLE__)
#include "icusb_debug_tool.h"
#endif
#include "upll_ctrl.h"
#include "usb_custom.h"
#include "usb_trc.h"

#include "dcl.h"

#if (defined(MT6326))
//#include "pmic6326_sw.h"
//#include "i2c_dual_sw.h"
#include "Dcl_pmic6326_sw.h"
#endif





//#ifdef DCL_USB_INTERFACE

#if defined(__OTG_ENABLE__)||defined(__IC_USB_ENABLE__)

#if defined(DRV_USB_IP_V4)
#pragma arm section zidata = "NONCACHEDZI",  rwdata = "NONCACHEDRW"
TGPD USB_DMAQ_TX_GPD[TGPD_MAX_NUMBERS+1];
TGPD USB_DMAQ_RX_GPD[TGPD_MAX_NUMBERS+1];
#pragma arm section zidata, rwdata
#endif

/* Global variables */
#define DCL_USB_HCD_HANDLE  	0x00002000
#define DCL_USB_HCD_CHECK_HANDLE_IS_VALID(handle) ((handle)&DCL_USB_HCD_HANDLE)


/* static variables */
static kal_bool g_USB_Hcd_Init = KAL_FALSE;
static kal_bool g_USB_Hcd_Open = KAL_FALSE;

static USB_HCD_Struct g_UsbHcdInfo[USB_IP_NUM];
static void USB_HCD_Reset_Recovery_Timeout(void *parameter);
static void USB_HCD_Reset_Timeout(void *parameter);
static void  USB_HCD_Delay_Reset_Timeout(void *parameter);
static void USB_HCD_Debounce_Timeout(void *parameter);
static void USB_HCD_Debounce_Attach(kal_uint8 usb_ip_port);
static void USB_HCD_Process_Attach(kal_uint8 usb_ip_port);
static void USB_HCD_Process_Detach(kal_uint8 usb_ip_port);

#if defined(__IC_USB_ENABLE__)
static void USB_HCD_Remote_Wakeup(void);
#endif

static void USB_HCD_Resume_Recovery_Timeout(void *parameter);
static void USB_HCD_Send_Setup(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str);
static void USB_HCD_Send_Data(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str);
static void USB_HCD_Recv_Data(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str);
static void USB_HCD_DMA_Timeout_Hdlr(void *parameter);

extern const kal_uint32 USB_BaseAddr[USB_IP_NUM]; 
extern const kal_uint8  USB_IRQ_MAP[USB_IP_NUM];
extern const kal_uint8  USBDMA_IRQ_MAP[USB_IP_NUM];


/* EP0's FIFO address is fixed from 0~63 */
static kal_uint32 g_HCD_FIFOadd = USB_FIFO_START_ADDRESS;

const kal_uint32 USB_BaseAddr[USB_IP_NUM] =
{
#ifdef  __USB_ENABLE__
	USB_base,
#endif

#ifdef __IC_USB_ENABLE__
	ICUSB1_base,
#endif   
};

const kal_uint8  USB_IRQ_MAP[USB_IP_NUM]=
{
#ifdef  __USB_ENABLE__
	IRQ_USB_CODE,
#endif

#ifdef __IC_USB_ENABLE__
	IRQ_IC_USB1_CODE,	
#endif
};

#if defined(DRV_USB_IP_V3)
const kal_uint8  USBDMA_IRQ_MAP[USB_IP_NUM]=
{
#ifdef  __USB_ENABLE__
	IRQ_USBDMA_CODE,
#endif

#ifdef __IC_USB_ENABLE__
	IRQ_IC_USBDMA1_CODE,
#endif
};
#endif

/************************************************************
	static basic check functions
*************************************************************/

static void USB_HCD_EP_Check(kal_uint8 usb_ip_port,kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_uint32 line)
{
	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);

	if (usb_ip_port < USB_EXT_IP_NUM)
{
	if((ep_num == 0)||((direction == USB_EP_TX_DIR)&&(ep_num > MAX_TX_EP_NUM))||
		((direction == USB_EP_RX_DIR)&&(ep_num > MAX_RX_EP_NUM)))
			EXT_ASSERT(0, ep_num, (kal_uint32)direction, line);
	}
#if defined(__IC_USB_ENABLE__)	
	else
	{
		if((ep_num == 0)||((direction == USB_EP_TX_DIR)&&(ep_num > ICUSB_MAX_TX_EP_NUM))||
			((direction == USB_EP_RX_DIR)&&(ep_num > ICUSB_MAX_RX_EP_NUM)))
		EXT_ASSERT(0, ep_num, (kal_uint32)direction, line);
	}
#endif	
}

static kal_bool USB_HCD_Speed_Read_Is_HS(kal_uint8 usb_ip_port)
{
	if((USB_DRV_Reg8(USB_POWER_HCD(USB_BaseAddr[usb_ip_port]))&USB_POWER_HSMODE) != 0)
		return KAL_TRUE;
	else
		return KAL_FALSE;	
}

kal_bool USB_HCD_Get_UnMask_Irq(kal_uint8 usb_ip_port)
{
	return g_UsbHcdInfo[usb_ip_port].b_unmask_irq;
}


static kal_bool USB_HCD_Is_High_Speed(kal_uint8 usb_ip_port)
{
	return g_UsbHcdInfo[usb_ip_port].b_hcd_is_high_speed;
} 

static kal_bool USB_HCD_Is_RemoteWakeup_SUPPORT(kal_uint8 usb_ip_port)
{
	return g_UsbHcdInfo[usb_ip_port].host_common_param->support_Remote_Wakeup;
}


void USB_HCD_VBusEnable(kal_uint8 usb_ip_port,kal_bool enable)
{	
	kal_uint32  delay;
	
#if (defined(MT6326))	
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE volt;
	val.enable = enable;
	val.mod = VBUS;
	handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);	
#endif

	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);

	if(enable == KAL_TRUE)
	{
		
#if (defined(MT6326))
		volt.mod = VBUS;
		volt.voltage = PMU_VOLT_05_300000_V;
		DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&volt);		
//		dcl_pmic6326_vboost1_tune(VBOOST1_VOL_5_30_V);
		
		DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);		
//		dcl_pmic6326_boost_mode(BOOST_MODE_TYPE_I);
//		dcl_pmic6326_boost1_enable (KAL_TRUE);
//		dcl_pmic6326_vbus_enable(KAL_TRUE);
#endif

		for (delay = 0; delay < 50000; delay ++); //1000

		USB_DRV_SetBits8(USB_DEVCTL_HCD(USB_BaseAddr[usb_ip_port]), USB_DEVCTL_SESSION);
	}
	else
	{	
		USB_DRV_ClearBits8(USB_DEVCTL_HCD(USB_BaseAddr[usb_ip_port]), USB_DEVCTL_SESSION);
		
#if (defined(MT6326))
		DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);	
//		dcl_pmic6326_vbus_enable(KAL_FALSE);
#endif

	}	
	
#if (defined(MT6326))	
	DclPMU_Close(handle);
#endif	
}


kal_bool USB_HCD_DMA_Get_Run_Status(kal_uint8 usb_ip_port, kal_uint8 dma_chan)
{
	return g_UsbHcdInfo[usb_ip_port].dma_running[dma_chan-1];
}	


static void USB_HCD_EP_DMA_Running_Check(kal_uint8 usb_ip_port,kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_uint32 line)
{
	kal_uint8	dma_chan;

	dma_chan = g_UsbHcdInfo[usb_ip_port].dma_port[direction][ep_num-1];

	if((dma_chan != 0)&&(USBHCD_DMA_CheckRunStat(USB_BaseAddr[usb_ip_port],dma_chan) != 0))
	{
		EXT_ASSERT(0, ep_num, (kal_uint32)direction, line);
	}
}

static kal_uint8 USB_HCD_Get_DMA_Channel_Num(kal_uint8 usb_ip_port,kal_uint8 ep_num, USB_EP_DIRECTION direction)
{
	kal_uint8  dma_chan;

	USB_HCD_EP_Check(usb_ip_port,ep_num, direction, 0);

	dma_chan = g_UsbHcdInfo[usb_ip_port].dma_port[direction][ep_num-1];

	if (usb_ip_port < USB_EXT_IP_NUM)
	{
		if(g_UsbHcdInfo[usb_ip_port].dma_channel > MAX_DMA_NUM)
			EXT_ASSERT(0, g_UsbHcdInfo[usb_ip_port].dma_channel, MAX_DMA_NUM, 0);
	}
#if defined(__IC_USB_ENABLE__)	
	else
	{
		if(g_UsbHcdInfo[usb_ip_port].dma_channel > ICUSB_MAX_DMA_NUM)
			EXT_ASSERT(0, g_UsbHcdInfo[usb_ip_port].dma_channel, ICUSB_MAX_DMA_NUM, 0);
	}
#endif

	return dma_chan;
}


static void USB_HCD_Stop_DMA_Channel(kal_uint8 usb_ip_port,kal_uint8 ep_num, USB_EP_DIRECTION direction)
{
	kal_uint8 	dma_chan;

	dma_chan = USB_HCD_Get_DMA_Channel_Num(usb_ip_port,ep_num, direction);

	if(g_UsbHcdInfo[usb_ip_port].dma_dir[dma_chan-1] == USB_EP_RX_DIR)
	{
		/* Stop DMA RX timer */
		DclSGPT_Control((DCL_HANDLE)(g_UsbHcdInfo[usb_ip_port].dma_gpt_handle[ep_num-1]), SGPT_CMD_STOP, 0);
//		GPTI_StopItem(g_UsbHcdInfo[usb_ip_port].dma_gpt_handle[ep_num-1]);
	}

	/* stop DMA channel */
	USBHCD_DMA_Stop(USB_BaseAddr[usb_ip_port],dma_chan);

	/* Clear pending DMA interrupts */
#if defined(DRV_USB_IP_V3)
	// write 0 clear
	USB_DRV_WriteReg32(USB_DMAINTR_HCD(USB_BaseAddr[usb_ip_port]), ~((1<<(dma_chan-1))|(0xC000<<(dma_chan*2))));
#elif defined(DRV_USB_IP_V4)
	// write 1 clear
	USB_DRV_WriteReg8(USB_DMAINTR_HCD(USB_BaseAddr[usb_ip_port]), (1<<(dma_chan-1)));
#endif

	g_UsbHcdInfo[usb_ip_port].dma_pktrdy[dma_chan - 1] = KAL_FALSE;
	g_UsbHcdInfo[usb_ip_port].dma_running[dma_chan - 1] = KAL_FALSE;

}


static void USB_HCD_Stop_All_Active_Traffic(kal_uint8 usb_ip_port)
{
	kal_uint32   index;
	kal_uint32  ep_num;
	kal_uint16  TXCSR;
	kal_uint16  RXCSR;
	kal_uint8	dma_channel = 0;
	

	if (usb_ip_port < USB_EXT_IP_NUM)
		dma_channel = MAX_DMA_NUM;
#if defined(__IC_USB_ENABLE__)		
	else
		dma_channel = ICUSB_MAX_DMA_NUM;
#endif



	/* Stop all running DMA */
	for (index = 0; index < dma_channel; index++)
	{
		if(g_UsbHcdInfo[usb_ip_port].dma_running[index] == KAL_TRUE)
		{
			if(g_UsbHcdInfo[usb_ip_port].dma_dir[index] == USB_EP_TX_DIR)
			{
				ep_num = g_UsbHcdInfo[usb_ip_port].dma_tx_ep_num[index];

				USB_HCD_Stop_DMA_Channel(usb_ip_port,ep_num, USB_EP_TX_DIR);

				USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);
				TXCSR = USB_DRV_Reg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]));
				TXCSR |= USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG;
				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), 0x00);
				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), TXCSR);
				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), TXCSR);

				g_UsbHcdInfo[usb_ip_port].ep_tx_flush_intr[ep_num-1] = KAL_TRUE;

				if(g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1] != NULL)
					g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1](usb_ip_port,USB_HCD_DETATCH, 0);
			}
			else
			{
				ep_num = g_UsbHcdInfo[usb_ip_port].dma_rx_ep_num[index];

				USB_HCD_Stop_DMA_Channel(usb_ip_port,ep_num, USB_EP_RX_DIR);

				USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);
				RXCSR = USB_DRV_Reg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]));
				RXCSR |= USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG;
				USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), 0x00);
				USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), RXCSR);
				USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), RXCSR);

				g_UsbHcdInfo[usb_ip_port].ep_rx_flush_intr[ep_num-1] = KAL_TRUE;

				if(g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1] != NULL)
					g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1](usb_ip_port,USB_HCD_DETATCH, 0);
			}
		}
	}

	/* Remove and notify all queued endpoints */
	if(g_UsbHcdInfo[usb_ip_port].ep0_fifo_intr == KAL_TRUE)
	{
		g_UsbHcdInfo[usb_ip_port].ep0_fifo_intr = KAL_FALSE;
		USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), 0);
		USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), USB_CSR0_FLUSHFIFO);

		/* When USB host turn off Vbus, then call host down func will release ep0 handler, but before Vbus off disconn intr happen */
		if(g_UsbHcdInfo[usb_ip_port].ep0_hdlr != NULL)
			g_UsbHcdInfo[usb_ip_port].ep0_hdlr(usb_ip_port,USB_HCD_DETATCH, 0);
	}

	for(ep_num = 1; ep_num <= MAX_TX_EP_NUM; ep_num++)
	{
		if(g_UsbHcdInfo[usb_ip_port].ep_tx_fifo_intr[ep_num-1] == KAL_TRUE)
		{
			g_UsbHcdInfo[usb_ip_port].ep_tx_fifo_intr[ep_num-1]  = KAL_FALSE;

			USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);
			USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), 0x00);
			USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG);
			USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG);

			g_UsbHcdInfo[usb_ip_port].ep_tx_flush_intr[ep_num-1] = KAL_TRUE;

			if(g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1] != NULL)
				g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1](usb_ip_port,USB_HCD_DETATCH, 0);
		}
	}

	for(ep_num = 1; ep_num <= MAX_RX_EP_NUM; ep_num++)
	{
		if(g_UsbHcdInfo[usb_ip_port].ep_rx_fifo_intr[ep_num-1] == KAL_TRUE)
		{
			g_UsbHcdInfo[usb_ip_port].ep_rx_fifo_intr[ep_num-1]  = KAL_FALSE;

			USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);
			USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), 0x00);
			USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG);
			USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG);

			g_UsbHcdInfo[usb_ip_port].ep_rx_flush_intr[ep_num-1] = KAL_TRUE;

			if(g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1] != NULL)
				g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1](usb_ip_port,USB_HCD_DETATCH, 0);
		}
	}

}


static kal_uint32 USB_HCD_EP_Rx_Pkt_Len(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str)
{
	kal_uint32 savedMask;
	kal_uint16 CSR;
	kal_uint32 nCount = 0;
		
	USB_HCD_EP_Check(common_str.usb_ip_port,usb_ep_str.ep_num, USB_EP_RX_DIR, 0);
	
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[common_str.usb_ip_port]), usb_ep_str.ep_num);
	CSR = USB_DRV_Reg(USB_RXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]));
	
	if(CSR&USB_RXCSR_RXPKTRDY)
	{
		nCount = (kal_uint32)USB_DRV_Reg(USB_RXCOUNT_HCD(USB_BaseAddr[common_str.usb_ip_port]));
	}
	RestoreIRQMask(savedMask);

	return nCount;
}

/* Return packet length for endpoint 0*/
kal_uint32 USB_HCD_EP0_Pkt_Len(USBH_Common_Struct common_str)
{
	kal_uint32 savedMask;
	kal_uint32 nCount = 0;
	kal_uint16  CSR0;
		
	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[common_str.usb_ip_port]), 0);
	CSR0 = USB_DRV_Reg(USB_CSR0_HCD(USB_BaseAddr[common_str.usb_ip_port]));

	if(CSR0&USB_CSR0_RXPKTRDY)
	{
		nCount = (kal_uint32)USB_DRV_Reg8(USB_COUNT0_HCD(USB_BaseAddr[common_str.usb_ip_port]));
	}
	RestoreIRQMask(savedMask);

	return nCount;
}

/* EP RX data already read out, clear the data */
static void USB_HCD_EP_Bulk_Rx_Ready(kal_uint8 usb_ip_port,kal_uint8 ep_num)
{
	kal_uint32 savedMask;

	USB_HCD_EP_Check(usb_ip_port,ep_num, USB_EP_RX_DIR, 0);

	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);
	USB_DRV_ClearBits(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_RXCSR_RXPKTRDY);
	RestoreIRQMask(savedMask);

}

/* EP TX data prepared ready, set ready bit */
static void USB_HCD_EP_Bulk_Tx_Ready(kal_uint8 usb_ip_port,kal_uint8 ep_num)
{
	kal_uint32 savedMask;

	USB_Dbg_Trace(USB_DBG_SET_TXPKTREADY,ep_num, 0);
	USB_HCD_EP_Check(usb_ip_port,ep_num, USB_EP_TX_DIR, 0);
	USB_HCD_EP_DMA_Running_Check(usb_ip_port,ep_num, USB_EP_TX_DIR, 0);
	
	savedMask = SaveAndSetIRQMask();  //DMA_Setup : clear UnderRun bit & Set TX_PkyReady at the same time
	USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);

	if(USB_DRV_Reg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]))&USB_TXCSR_TXPKTRDY)  // check TX_PktReady bit 
	{
		ASSERT(0);
	}	
	USB_DRV_SetBits(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_TXCSR_TXPKTRDY);
	RestoreIRQMask(savedMask);

}


static void USB_HCD_EP_Interval(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str,kal_uint8 interval)
{
	USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[common_str.usb_ip_port]), usb_ep_str.ep_num);

	if (usb_ep_str.direction == USB_EP_TX_DIR)
	{	
		if (usb_ep_str.ep_num == 0)
		{
			USB_DRV_WriteReg8(USB_NAKLIMIT0_HCD(USB_BaseAddr[common_str.usb_ip_port]),interval);
		}
		else
		{
			USB_DRV_WriteReg8(USB_TXINTERVAL_HCD(USB_BaseAddr[common_str.usb_ip_port]),interval);		
		}	
	}
	else
	{
		USB_DRV_WriteReg8(USB_RXINTERVAL_HCD(USB_BaseAddr[common_str.usb_ip_port]),interval);		
	}
}

/* GPT timeout function*/
static void USB_HCD_Debounce_Timeout(void *parameter)
{
	SGPT_CTRL_START_T start;
	USB_HCD_Struct *USBD_Data = (USB_HCD_Struct *)parameter;
	kal_uint8 usb_ip_port = USBD_Data->usb_ip_port;


	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);

	DclSGPT_Control((DCL_HANDLE)(g_UsbHcdInfo[usb_ip_port].gpt_handle), SGPT_CMD_STOP, 0);	
//	GPTI_StopItem(g_UsbHcdInfo[usb_ip_port].gpt_handle);

	if(g_UsbHcdInfo[usb_ip_port].b_disable_attach == KAL_TRUE)
	{
		start.u2Tick = USB_HCD_DEBOUNCE_DELAY;					
    		start.pfCallback = USB_HCD_Debounce_Timeout;			
    		start.vPara = &g_UsbHcdInfo[usb_ip_port];							
    		DclSGPT_Control((DCL_HANDLE)(g_UsbHcdInfo[usb_ip_port].gpt_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	
//		GPTI_StartItem(g_UsbHcdInfo[usb_ip_port].gpt_handle, USB_HCD_DEBOUNCE_DELAY,USB_HCD_Debounce_Timeout, &g_UsbHcdInfo[usb_ip_port]);
	}
	else
	{
		USB_HCD_Debounce_Attach(usb_ip_port);
	}
}

/* Send reset signal to device*/
static void USB_HCD_Reset_Device(kal_uint8 usb_ip_port,USB_HCD_STATUS reset_reason)
{
	SGPT_CTRL_START_T start;
	
	/* Reset addr as 0 */
	USB_DRV_WriteReg8(USB_FADDR_HCD(USB_BaseAddr[usb_ip_port]), 0);

	/* Clear all endpoints' interrupts */
	USB_DRV_Reg(USB_INTRTX_HCD(USB_BaseAddr[usb_ip_port]));
	// write 0 clear
	USB_DRV_WriteReg(USB_INTRRX_HCD(USB_BaseAddr[usb_ip_port]), 0);

#ifdef DRV_USB_PHY_COST_DOWN  //6268B
	if (usb_ip_port < USB_EXT_IP_NUM)
	{	
		if(OTG_Get_Plug_Type() == OTG_PLUG_A)
		{
			USB_DRV_WriteReg8(USB_PHYIR4_0, (USB_PHYIR4_0_RG_CALIB_SELE0_ENABLE|USB_PHYIR4_0_RG_TX_I_TRIM0));
			USB_DRV_WriteReg8(USB_PHYCR2_2, (USB_PHYCR2_2_HS_DISC_TH|USB_PHYCR2_2_HSDISC_DEGL|USB_PHYCR2_2_HS_TRIM_TH));
		}
	}
#endif

	/* Set reset on the USB bus for 20ms */
	USB_DRV_SetBits8(USB_POWER_HCD(USB_BaseAddr[usb_ip_port]), USB_POWER_RESET);

	g_UsbHcdInfo[usb_ip_port].reset_reason = reset_reason;

	/* Delay for the reset process to complete */
	start.u2Tick = USB_HCD_RESET_DELAY;					
  	start.pfCallback = USB_HCD_Reset_Timeout;			
  	start.vPara = &g_UsbHcdInfo[usb_ip_port];							
  	DclSGPT_Control((DCL_HANDLE)(g_UsbHcdInfo[usb_ip_port].gpt_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	
//	GPTI_StartItem(g_UsbHcdInfo[usb_ip_port].gpt_handle, USB_HCD_RESET_DELAY,USB_HCD_Reset_Timeout, &g_UsbHcdInfo[usb_ip_port]);
}


static void USB_HCD_Debounce_Attach(kal_uint8 usb_ip_port)
{
	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);
	
	/* Reset the device */
	USB_HCD_Reset_Device(usb_ip_port,USB_HCD_OK);

}


static void USB_HCD_Process_Attach(kal_uint8 usb_ip_port)
{
	SGPT_CTRL_START_T start;
	OTG_STATE otg_state = OTG_Get_State();

	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);
	

	if (usb_ip_port < USB_EXT_IP_NUM)
	{	

//	if(((otg_state != OTG_STATE_A_SUSPEND)&&(otg_state != OTG_STATE_B_WAIT_ACON))
//		|| (g_UsbHcdInfo[usb_ip_port].b_disable_attach == KAL_TRUE))
		if((otg_state == OTG_STATE_A_WAIT_BCON)
			||(g_UsbHcdInfo[usb_ip_port].b_disable_attach == KAL_TRUE))
		{
			/* g_UsbHcdInfo[usb_ip_port].b_disable_attach == KAL_TRUE because it needs to wait FMT call message ACK */
			/* host need at least 100ms debounce time */

			/* Add for OTG function */
			OTG_Set_Status(OTG_STATUS_A_DETECT_B_CONN, KAL_TRUE);

   	 	start.u2Tick = USB_HCD_DEBOUNCE_DELAY;					
    			start.pfCallback = USB_HCD_Debounce_Timeout;			
    			start.vPara = &g_UsbHcdInfo[usb_ip_port];							
    			DclSGPT_Control((DCL_HANDLE)(g_UsbHcdInfo[usb_ip_port].gpt_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	
    
//			GPTI_StartItem(g_UsbHcdInfo[usb_ip_port].gpt_handle, USB_HCD_DEBOUNCE_DELAY,USB_HCD_Debounce_Timeout, &g_UsbHcdInfo[usb_ip_port]);
			/* disable interrupt */
			g_UsbHcdInfo[usb_ip_port].b_unmask_irq = KAL_FALSE;
		}
		else if (otg_state == OTG_STATE_B_WAIT_ACON)
		{
			/* Add for OTG function*/
			OTG_Set_Status(OTG_STATUS_B_DETECT_A_CONN, KAL_TRUE);

			/* Do HNP, B-device reset A-device automatically, need no debounce time */
				USB_HCD_Debounce_Attach(usb_ip_port);
		}
		else
		{
			ASSERT(0);
		}
	}
	else
	{   //UT Test
		start.u2Tick = USB_HCD_DEBOUNCE_DELAY;					
    		start.pfCallback = USB_HCD_Debounce_Timeout;			
		start.vPara = &g_UsbHcdInfo[usb_ip_port];							
		DclSGPT_Control((DCL_HANDLE)(g_UsbHcdInfo[usb_ip_port].gpt_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	
    
//			GPTI_StartItem(g_UsbHcdInfo[usb_ip_port].gpt_handle, USB_HCD_DEBOUNCE_DELAY,USB_HCD_Debounce_Timeout, &g_UsbHcdInfo[usb_ip_port]);
//			USB_HCD_Debounce_Attach(usb_ip_port);
	}
} 

static void USB_HCD_Reset_Resource(kal_uint8 usb_ip_port)
{
	g_HCD_FIFOadd = USB_FIFO_START_ADDRESS;
	g_UsbHcdInfo[usb_ip_port].dma_channel = 0;
	g_UsbHcdInfo[usb_ip_port].ep_tx_real_num = 0;
	g_UsbHcdInfo[usb_ip_port].ep_rx_real_num = 0;
}

static void USB_HCD_Process_Detach(kal_uint8 usb_ip_port)
{

	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);
	
	/* Reset all the attached device specific values */
	USB_DRV_WriteReg8(USB_FADDR_HCD(USB_BaseAddr[usb_ip_port]), 0);
	
	/* Clear all endpoints' interrupts */
	USB_DRV_Reg(USB_INTRTX_HCD(USB_BaseAddr[usb_ip_port]));
	// write 0 clear
	USB_DRV_WriteReg(USB_INTRRX_HCD(USB_BaseAddr[usb_ip_port]), 0);

	g_UsbHcdInfo[usb_ip_port].b_hcd_is_high_speed = KAL_FALSE;
	
	if (usb_ip_port < USB_EXT_IP_NUM)
	{
		if(OTG_Get_State() == OTG_STATE_B_IDLE)
		{
			ASSERT(0);
		}
		/* Add for OTG function */
		if(OTG_Get_Plug_Type() == OTG_PLUG_A)
			OTG_Set_Status(OTG_STATUS_A_DETECT_B_CONN, KAL_FALSE);
		else
			OTG_Set_Status(OTG_STATUS_B_DETECT_A_CONN, KAL_FALSE);

	}
	/* Call the callback function if there was one registered for a detach 
	** event 
	*/
	if(g_UsbHcdInfo[usb_ip_port].detach_hdlr == NULL)
		EXT_ASSERT(0, 0, 0, 0);
	g_UsbHcdInfo[usb_ip_port].detach_hdlr(usb_ip_port,USB_HCD_OK, 0);

	USB_HCD_Reset_Resource(usb_ip_port);

} /* Endbody */


/* Host detect remote wakeup */
static void USB_HCD_Resume_Recovery_Timeout(void *parameter)
{	
	USB_HCD_Struct *USBD_Data = (USB_HCD_Struct *)parameter;
	kal_uint8 usb_ip_port = USBD_Data->usb_ip_port;
	
	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);

	if (g_UsbHcdInfo[usb_ip_port].host_state != USBH_STATE_HOST)
		ASSERT(0);	
	
	DclSGPT_Control((DCL_HANDLE)(g_UsbHcdInfo[usb_ip_port].gpt_handle), SGPT_CMD_STOP, 0);
//	GPTI_StopItem(g_UsbHcdInfo[usb_ip_port].gpt_handle);	
//	ICUSB_Dbg_Trace(IC_USB_REMOTE_WAKEUP_DONE,0, 0);
	
	USB_DRV_ClearBits8(USB_POWER_HCD(USB_BaseAddr[usb_ip_port]), USB_POWER_RESUME);
    	
	if(g_UsbHcdInfo[usb_ip_port].resume_hdlr != NULL)
		g_UsbHcdInfo[usb_ip_port].resume_hdlr(usb_ip_port,USB_HCD_OK, 0);		
}


#if defined(__IC_USB_ENABLE__)
/* Host detect remote wakeup : called by EINT_Registration(icusb_eint) */
static void USB_HCD_Remote_Wakeup(void)
{	
	kal_uint8 icusb_remote_eint = 0x30;//custom_eint_get_channel(icusb_remote_eint_chann); QQ Test
	kal_uint8 usb_ip_port = ICUSB_PORT_1;  //IC USB Port
	
	EINT_Mask(icusb_remote_eint);	
	
//	  IRQMask(IRQ_EIT_CODE); // mask all interrupt 
//		SAL_EINT_Mask_Adv(1);   // EINT1

	/* Remote wakeup */
//	ICUSB_Dbg_Trace(IC_USB_REMOTE_WAKEUP, 0, 0);
	USB_HCD_Send_Resume(usb_ip_port);
}
#endif


static void USB_HCD_Resume(kal_uint8 usb_ip_port)
{
	if (usb_ip_port >=  USB_IP_NUM)
		ASSERT(0);

	
	if (usb_ip_port < USB_EXT_IP_NUM)
	{	
	if(OTG_Get_State() == OTG_STATE_A_SUSPEND)
	{
		/* Add for OTG function */
		OTG_Set_Status(OTG_STATUS_A_DETECT_B_RESUME, KAL_TRUE);
	}

	if(g_UsbHcdInfo[usb_ip_port].resume_hdlr != NULL)
			g_UsbHcdInfo[usb_ip_port].resume_hdlr(usb_ip_port,USB_HCD_OK, 0);
	}
	else
	{
		ASSERT(0); //IC USB Detect remote wakeup by using EINT
	}
}

void USB_HCD_Conn_Hdlr(kal_uint8 usb_ip_port)
{
	g_UsbHcdInfo[usb_ip_port].usb_ip_port = usb_ip_port;
	USB_HCD_Stop_All_Active_Traffic(usb_ip_port);
	USB_HCD_Process_Attach(usb_ip_port);
	g_UsbHcdInfo[usb_ip_port].host_state = USBH_STATE_START; 
}

void USB_HCD_Disconn_Hdlr(kal_uint8 usb_ip_port)
{
	USB_HCD_Stop_All_Active_Traffic(usb_ip_port);
	USB_HCD_Process_Detach(usb_ip_port);
	g_UsbHcdInfo[usb_ip_port].host_state = USBH_STATE_WAIT_BCON;
}



/* GPT timeout function*/
static void USB_HCD_Reset_Recovery_Timeout(void *parameter)
{
	kal_uint32 savedMask;

	USB_HCD_Struct *USBD_Data = (USB_HCD_Struct *)parameter;
	USBH_Common_Struct common_str;	
	USBH_EP_Struct usb_ep_str;
	common_str.usb_ip_port = USBD_Data->usb_ip_port;
	usb_ep_str.ep_num = 0;
	usb_ep_str.direction = USB_EP_TX_DIR;
	usb_ep_str.ep_type = USB_ENDPT_CTRL;


	if (common_str.usb_ip_port >= USB_IP_NUM)
		ASSERT(0);

	DclSGPT_Control((DCL_HANDLE)(g_UsbHcdInfo[common_str.usb_ip_port].gpt_handle), SGPT_CMD_STOP, 0);
//	GPTI_StopItem(g_UsbHcdInfo[common_str.usb_ip_port].gpt_handle);

	savedMask = SaveAndSetIRQMask();
	/* Enable ep0 */

	if (common_str.usb_ip_port < USB_EXT_IP_NUM)
	{
	/* Set NAK Limit, max value is 16, 16 stands for 4 seconds */
		if(USB_HCD_Speed_Read_Is_HS(common_str.usb_ip_port) == KAL_TRUE)
		{		
		
			USB_HCD_EP_Interval(common_str,usb_ep_str,g_UsbHcdInfo[common_str.usb_ip_port].host_common_param->ep0_interval);
			g_UsbHcdInfo[common_str.usb_ip_port].b_hcd_is_high_speed = KAL_TRUE;
		}
		else
		{
			USB_HCD_EP_Interval(common_str,usb_ep_str,(g_UsbHcdInfo[common_str.usb_ip_port].host_common_param->ep0_interval-3));
			g_UsbHcdInfo[common_str.usb_ip_port].b_hcd_is_high_speed = KAL_FALSE;
		}
	}
	else
	{	// ICUSB only support USB1.1
		USB_HCD_EP_Interval(common_str,usb_ep_str,(g_UsbHcdInfo[common_str.usb_ip_port].host_common_param->ep0_interval-3));
		g_UsbHcdInfo[common_str.usb_ip_port].b_hcd_is_high_speed = KAL_FALSE;
	}

	RestoreIRQMask(savedMask);

	/* Call the callback function of there was one register for the attach 
	** event 
	*/
	if(g_UsbHcdInfo[common_str.usb_ip_port].attach_hdlr == NULL)
		EXT_ASSERT(0, 0, 0, 0);
	g_UsbHcdInfo[common_str.usb_ip_port].attach_hdlr(common_str.usb_ip_port,g_UsbHcdInfo[common_str.usb_ip_port].reset_reason, 0);

	/* unmask USB IRQ*/
	USB_Dbg_Trace(USB_HCD_UNMASK_HISR,1, 0);
	g_UsbHcdInfo[common_str.usb_ip_port].b_unmask_irq = KAL_TRUE;

	IRQUnmask(USB_IRQ_MAP[common_str.usb_ip_port]);

}


/* GPT timeout function*/
static void USB_HCD_Reset_Timeout(void *parameter)
{
	SGPT_CTRL_START_T start;
	USB_HCD_Struct *USBD_Data = (USB_HCD_Struct *)parameter;
	kal_uint8 usb_ip_port = USBD_Data->usb_ip_port;

	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);
		
	DclSGPT_Control((DCL_HANDLE)(g_UsbHcdInfo[usb_ip_port].gpt_handle), SGPT_CMD_STOP, 0);	
//	GPTI_StopItem(g_UsbHcdInfo[usb_ip_port].gpt_handle);
	
	/* End the reset */
	USB_DRV_ClearBits8(USB_POWER_HCD(USB_BaseAddr[usb_ip_port]), USB_POWER_RESET);

#ifdef DRV_USB_PHY_COST_DOWN  //6268B
	if (usb_ip_port < USB_EXT_IP_NUM)
	{	
		if(OTG_Get_Plug_Type() == OTG_PLUG_A)
		{
			USB_DRV_WriteReg8(USB_PHYIR4_0, (USB_PHYIR4_0_RG_CALIB_SELE0_2|USB_PHYIR4_0_RG_TX_I_TRIM0));
		}
	}
#endif


	/* Delay for the reset recovery period, in USB spec. 9.2.6.2 */
  	start.u2Tick = USB_HCD_RESET_RECOVERY_DELAY;					
  	start.pfCallback = USB_HCD_Reset_Recovery_Timeout;			
  	start.vPara = &g_UsbHcdInfo[usb_ip_port];							
 	DclSGPT_Control((DCL_HANDLE)(g_UsbHcdInfo[usb_ip_port].gpt_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);		
//	GPTI_StartItem(g_UsbHcdInfo[usb_ip_port].gpt_handle, USB_HCD_RESET_RECOVERY_DELAY,USB_HCD_Reset_Recovery_Timeout, &g_UsbHcdInfo[usb_ip_port]);
}


/* GPT timeout function*/
static void  USB_HCD_Delay_Reset_Timeout(void *parameter)
{
	USB_HCD_Struct *USBD_Data = (USB_HCD_Struct *)parameter;
	kal_uint8 usb_ip_port = USBD_Data->usb_ip_port;
	USB_HCD_STATUS reset_reason = USBD_Data->reset_reason;
	
	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);

	DclSGPT_Control((DCL_HANDLE)(g_UsbHcdInfo[usb_ip_port].gpt_handle), SGPT_CMD_STOP, 0);
//	GPTI_StopItem(g_UsbHcdInfo[usb_ip_port].gpt_handle);
	USB_HCD_Reset_Device(usb_ip_port,reset_reason);
}


/*  Read FIFO data from EP with sfift */
static void USB_HCD_EPFIFORead(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str,kal_uint16 nBytes, void *pDst)
{
	kal_uint16  nCount = nBytes;
	kal_uint8   *pby;
	kal_uint32  nAddr;
		
	if (common_str.usb_ip_port >= USB_IP_NUM)
		ASSERT(0);
		
	if((nBytes != 0)&&(pDst == NULL))
		EXT_ASSERT(0, (kal_uint32)nBytes, 0, 0);
	
	/* not index register */
//	USB_DRV_WriteReg8(USB_INDEX, ep_num);
	nAddr = USB_EP0_HCD(USB_BaseAddr[common_str.usb_ip_port]) + (usb_ep_str.ep_num)*4;
	pby = (kal_uint8 *)pDst;

	/* read byte by byte */
	while (nCount) 
	{
		*pby++ = USB_DRV_Reg8(nAddr);	//lint !e613
		nCount--;
	}

}


/*  Write data to FIFO EP */
static void USB_HCD_EPFIFOWrite(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str,kal_uint16 nBytes, void *pSrc)
{
	kal_uint16 nCount = nBytes;
	kal_uint8 *pby;
	kal_uint32 nAddr;

	if ( common_str.usb_ip_port >= USB_IP_NUM)
		ASSERT(0);
	
	if((nBytes != 0)&&(pSrc == NULL))
		EXT_ASSERT(0, (kal_uint32)nBytes, 0, 0);

	/* not index register */
//	USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);
	nAddr = USB_EP0_HCD(USB_BaseAddr[common_str.usb_ip_port]) + (usb_ep_str.ep_num)*4;
	pby = (kal_uint8 *)pSrc;

	/* Write byte by byte */
	while (nCount) 
	{
		USB_DRV_WriteReg8(nAddr, *pby++);	//lint !e613
		nCount--;
	}
}



/* DMA setup function */
/* If the last one "callback_upd_run" parameter true =>
     application decides to clear "driver dma running status" by itself*/
     
static void USB_HCD_DMA_Setup(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str,kal_uint32 addr, kal_uint32 length,
				usb_dma_callback callback,kal_bool callback_upd_run, kal_bool known_size, USB_DMA_TYPE dma_type)				
{
	
	kal_uint8 usb_ip_port = common_str.usb_ip_port;
	kal_uint8 ep_num = usb_ep_str.ep_num;	
	USB_EP_DIRECTION direction = usb_ep_str.direction;
	USB_ENDPT_TXFER_TYPE ep_type = usb_ep_str.ep_type;
	kal_uint16  dma_ctrl;
	kal_uint8    dma_chan;
	static kal_uint32  dma_burst_mode = 0;
	kal_uint32  savedMask;


#ifdef  __DYNAMIC_SWITCH_CACHEABILITY__
	if((kal_bool)INT_QueryIsNonCachedRAM(addr, length) == KAL_FALSE)
		ASSERT(0);
#endif

	if(length == 0)
		ASSERT(0);

	dma_chan = USB_HCD_Get_DMA_Channel_Num(usb_ip_port,ep_num, direction);

	ASSERT(g_UsbHcdInfo[usb_ip_port].dma_running[dma_chan-1] == KAL_FALSE);

	if(g_UsbHcdInfo[usb_ip_port].is_bidirection_dma[dma_chan-1] == KAL_TRUE)
	{
		g_UsbHcdInfo[usb_ip_port].dma_dir[dma_chan-1] = direction;
	}
	else
	{
		if(g_UsbHcdInfo[usb_ip_port].dma_dir[dma_chan-1] != direction)
			EXT_ASSERT(0, dma_chan, (kal_uint32)g_UsbHcdInfo[usb_ip_port].dma_dir[dma_chan-1], (kal_uint32)direction);
	}

	g_UsbHcdInfo[usb_ip_port].dma_running[dma_chan-1] = KAL_TRUE;
	g_UsbHcdInfo[usb_ip_port].dma_callback[dma_chan-1] = callback;
	g_UsbHcdInfo[usb_ip_port].dma_callback_upd_run[dma_chan-1] = callback_upd_run;
	g_UsbHcdInfo[usb_ip_port].dma_length[dma_chan-1] = length;
	g_UsbHcdInfo[usb_ip_port].dma_pktrdy[dma_chan-1] = KAL_FALSE;

#ifdef __WRITE_THROUGH_CACHEABLE__
	if(direction == USB_EP_RX_DIR)
	{
		g_UsbHcdInfo[usb_ip_port].dma_length[dma_chan-1] = length;
		g_UsbHcdInfo[usb_ip_port].dma_addr[dma_chan-1] = addr;
	}
#endif

	if(direction == USB_EP_TX_DIR)
	{
#ifdef __USB_AUTO_SET__
		// auto set only can use on "ep1 with channel 2", "ep2 with channel 3", and "ep3 with channel 4"
		/* Judge if it is multiple of max packet length */
		if(((ep_num != 1)||(dma_chan != 2))&&((ep_num != 2)||(dma_chan != 3))&&((ep_num != 3)||(dma_chan != 4)))
		{
#endif
			if (length%g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].max_packet_size)
				g_UsbHcdInfo[usb_ip_port].dma_pktrdy[dma_chan-1] = KAL_TRUE;
#ifdef __USB_AUTO_SET__
		}
#endif /* __USB_AUTO_SET__ */
	}
	else
	{
		if (length%g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].max_packet_size)
		{
			USB_DRV_WriteReg(USB_RQPKTCOUNT_HCD(USB_BaseAddr[usb_ip_port],ep_num), (length/g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].max_packet_size)+1);
			g_UsbHcdInfo[usb_ip_port].dma_pktrdy[dma_chan-1] = KAL_TRUE;
		}
		else
		{
			USB_DRV_WriteReg(USB_RQPKTCOUNT_HCD(USB_BaseAddr[usb_ip_port],ep_num), (length/g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].max_packet_size));
		}
	}

	if(g_UsbHcdInfo[usb_ip_port].b_enable_dma_burst_auto_chge == KAL_TRUE)
		dma_burst_mode++;
	else
		dma_burst_mode = 0x03;

	/* DMA_CONFIG */
	if(dma_type == USB_DMA0_TYPE)
	{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	}
	else if(dma_type == USB_DMA1_TYPE)
	{
		if(direction == USB_EP_TX_DIR)
		{
			savedMask = SaveAndSetIRQMask();
			USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);

			/* Only is configured as multiple packet DMA TX mode */
			if(ep_type == USB_ENDPT_ISO)
			{
				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_TX_CSR_ISO);
			}
			else
			{
				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_TX_CSR);
			}

	#ifdef __USB_AUTO_SET__
			if(((ep_num == 1)&&(dma_chan == 2))||((ep_num == 2)&&(dma_chan == 3))||((ep_num == 3)&&(dma_chan == 4)))
			{
				USB_DRV_SetBits(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_TXCSR_AUTOSET_SPKT);
			}
	#endif

			RestoreIRQMask(savedMask);

			USB_DRV_WriteReg32(USB_DMAADDR_HCD(USB_BaseAddr[usb_ip_port],dma_chan), addr);
			USB_DRV_WriteReg32(USB_DMACNT_HCD(USB_BaseAddr[usb_ip_port],dma_chan), length);

			dma_ctrl = USB_DMACNTL_DMADIR|USB_DMACNTL_DMAMODE|USB_DMACNTL_INTEN|(ep_num<<4);
			dma_ctrl |= ((dma_burst_mode&0x03)<<9)|USB_DMACNTL_DMAEN;

			USB_DRV_WriteReg(USB_DMACNTL_HCD(USB_BaseAddr[usb_ip_port],dma_chan), dma_ctrl);
		}
		else if(direction == USB_EP_RX_DIR)
		{
			/* stop DMA channel */
			USBHCD_DMA_Stop(USB_BaseAddr[usb_ip_port],dma_chan);
//			USB_HCD_DMA_PPStop(dma_chan);

			if(known_size == KAL_TRUE)
			{
				savedMask = SaveAndSetIRQMask();
				USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);

				if(ep_type == USB_ENDPT_ISO)
				{
//					USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_RX_CSR_ISO|USB_RXCSR_REQPKT|USB_RXCSR_RXPKTRDY|USB_RXCSR_AUTOCLREN_SPKT);
					USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_RX_CSR_ISO|USB_RXCSR_REQPKT|USB_RXCSR_RXPKTRDY);				
				}
				else
				{
//					USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_RX_CSR|USB_RXCSR_REQPKT|USB_RXCSR_RXPKTRDY|USB_RXCSR_AUTOCLREN_SPKT);
					USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_RX_CSR|USB_RXCSR_REQPKT|USB_RXCSR_RXPKTRDY);
				}

				RestoreIRQMask(savedMask);
			}
			else
			{
		#ifdef __DMA_UNKNOWN_RX__
				savedMask = SaveAndSetIRQMask();
				USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);

				if(ep_type == USB_ENDPT_ISO)
				{
//					USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_RX_CSR_ISO|USB_RXCSR_REQPKT|USB_RXCSR_RXPKTRDY|USB_RXCSR_DMAREQMODE|USB_RXCSR_AUTOCLREN_SPKT);
					USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_RX_CSR_ISO|USB_RXCSR_REQPKT|USB_RXCSR_RXPKTRDY|USB_RXCSR_DMAREQMODE);
				}
				else
				{
//					USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_RX_CSR|USB_RXCSR_REQPKT|USB_RXCSR_RXPKTRDY|USB_RXCSR_DMAREQMODE|USB_RXCSR_AUTOCLREN_SPKT);
					USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_RX_CSR|USB_RXCSR_REQPKT|USB_RXCSR_RXPKTRDY|USB_RXCSR_DMAREQMODE);
				}

				RestoreIRQMask(savedMask);

				USB_Enable_DMA_Timer_Count(dma_chan, KAL_TRUE, 0x7F);
		#else
				ASSERT(0);
		#endif
			}

			USB_DRV_WriteReg32(USB_DMAADDR_HCD(USB_BaseAddr[usb_ip_port],dma_chan), addr);
			USB_DRV_WriteReg32(USB_DMACNT_HCD(USB_BaseAddr[usb_ip_port],dma_chan), length);

			dma_ctrl = USB_DMACNTL_DMAMODE|USB_DMACNTL_INTEN|(ep_num<<4);
			dma_ctrl |= ((dma_burst_mode&0x03)<<9)|USB_DMACNTL_DMAEN;
			USB_DRV_WriteReg(USB_DMACNTL_HCD(USB_BaseAddr[usb_ip_port],dma_chan), dma_ctrl);
		}
	}
#if defined(DRV_USB_IP_V3)
	
	else if(dma_type == USB_DMA2_TYPE)
	{
		if(direction == USB_EP_RX_DIR)
		{
			if(known_size == KAL_TRUE)
			{
				/* stop DMA channel */
				USBHCD_DMA_Stop(USB_BaseAddr[usb_ip_port],dma_chan);
//				USB_HCD_DMA_PPStop(dma_chan);

				savedMask = SaveAndSetIRQMask();
				USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);

				if(ep_type == USB_ENDPT_ISO)
				{
//					USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_RX_CSR_ISO|USB_RXCSR_REQPKT|USB_RXCSR_RXPKTRDY|USB_RXCSR_AUTOCLREN_SPKT);
					USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_RX_CSR_ISO|USB_RXCSR_REQPKT|USB_RXCSR_RXPKTRDY);

				}
				else
				{
//					USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_RX_CSR|USB_RXCSR_REQPKT|USB_RXCSR_RXPKTRDY|USB_RXCSR_AUTOCLREN_SPKT);
					USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_RX_CSR|USB_RXCSR_REQPKT|USB_RXCSR_RXPKTRDY);				
				}

				RestoreIRQMask(savedMask);
			}
			else
			{
				ASSERT(0);
			}

			USB_DRV_WriteReg32(USB_DMAADDR_HCD(USB_BaseAddr[usb_ip_port],dma_chan), addr);
			USB_DRV_WriteReg32(USB_DMACNT_HCD(USB_BaseAddr[usb_ip_port],dma_chan), length);

			dma_ctrl = USB_DMACNTL_DMAMODE|USB_DMACNTL_INTEN|(ep_num<<4)|USB_DMACNTL_ENDMAMODE2;
			dma_ctrl |= ((dma_burst_mode&0x03)<<9)|USB_DMACNTL_DMAEN;

			USB_DRV_WriteReg(USB_DMACNTL_HCD(USB_BaseAddr[usb_ip_port],dma_chan), dma_ctrl);
		}
		else if(direction == USB_EP_TX_DIR)
		{
			ASSERT(0);
		}
	}
#endif	
}



#if defined(DRV_USB_IP_V4)

/* DMAQ setup function. */
void USB_HCD_DMAQ_Setup(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str, kal_uint32 addr, kal_uint32 length,kal_bool callback_upd_run,kal_uint32 buf_count)
{
	kal_uint8 usb_ip_port = common_str.usb_ip_port;
	kal_uint8 ep_num = usb_ep_str.ep_num;	
	USB_EP_DIRECTION direction = usb_ep_str.direction;
	USB_ENDPT_TXFER_TYPE ep_type = usb_ep_str.ep_type;
	kal_uint16  dma_ctrl;
	kal_uint8	dma_chan = ep_num;
	kal_uint16  CSR;
	kal_uint16  IntrOut;
	kal_uint32  savedMask;
	kal_uint32	index;
	volatile kal_uint8  delay;
	volatile kal_uint32 temp_read;  
	
	//usb_device_dma_burst_mode+
	
	if (buf_count > TGPD_MAX_NUMBERS)
		ASSERT(0);
	
	if(ep_num != 1)
		ASSERT(0);

	if((length == 0)||(addr == NULL))
		ASSERT(0);


//	g_UsbHcdInfo[usb_ip_port].dma_callback[dma_chan-1] = callback;
	g_UsbHcdInfo[usb_ip_port].dma_callback_upd_run[dma_chan-1] = callback_upd_run;
	g_UsbHcdInfo[usb_ip_port].dma_pktrdy[dma_chan-1] = KAL_FALSE;
	

   	/* DMAQ_CONFIG */
	if(direction == USB_EP_RX_DIR)
	{		
//		DRV_WriteReg32(USB_DMAQ_RQCSR(dma_chan), USB_DMACNTL_DMAEN_STOP);
		if ((DRV_Reg32(USB_DMAQ_RQCSR(dma_chan))&USB_DMACNTL_DMAEN_ACTIVE) > 0)
		{
//			for (delay =0; delay < 200; delay ++);
			temp_read = DRV_Reg32(USB_DMAQ_RQCSR(dma_chan));
			
			while (1)
			{
				temp_read = DRV_Reg32(USB_DMAQ_RQCSR(dma_chan));
				if (temp_read == 0x00)
					break;
			}
			
//			if ((DRV_Reg32(USB_DMAQ_RQCSR(dma_chan))&USB_DMACNTL_DMAEN_ACTIVE) > 0)
//				ASSERT(0);
		}
	
		/*fill GPD buffers*/
		for (index = 0; index < RGPD_MAX_NUMBERS; index++)
		{
		  	USB_DMAQ_RX_GPD[index].flag = RGPD_FLAGS_HWO|RGPD_FLAGS_IOC; //1:HW is Owner, SW should not to access data buffer; HW will clear it to 0.
		  	USB_DMAQ_RX_GPD[index].chksum = 0;//PDU_calcCksum((kal_uint8 *)(USB_DMAQ_GPD+index), 16)-1;
		  	USB_DMAQ_RX_GPD[index].DataBufferLen = length;
		  	USB_DMAQ_RX_GPD[index].pNext = &(USB_DMAQ_RX_GPD[index+1]);
		  	USB_DMAQ_RX_GPD[index].pBuf = (kal_uint8*)addr;
		  	USB_DMAQ_RX_GPD[index].bufLen = 0;
		  	USB_DMAQ_RX_GPD[index].ExtLength = 0;
		  	USB_DMAQ_RX_GPD[index].ZTepFlag = 0;//ep_num & RGPD_ENDPOINT;
		}
		
		g_UsbHcdInfo[usb_ip_port].dmaQ_rx_length[dma_chan-1]= length;
			
		savedMask = SaveAndSetIRQMask();
		
		DRV_WriteReg8(USB_INDEX, ep_num);
		DRV_WriteReg(USB_RXCSR, USB_HCD_DMAQ_RX_CSR);
		
		DRV_WriteReg32(USB_DMAQ_RQSAR(dma_chan), (USB_DMAQ_RX_GPD+2));
 // 		DRV_WriteReg32(USB_DMAQ_QCR3, 0x00000000);  // there should be no ZLP
//		DRV_WriteReg32(USB_DMAQ_USBGCSR, DRV_Reg32(USB_DMAQ_USBGCSR)|(USB_DMAQ_USBGCSR_RQ_EN<<(dma_chan-1)));
//		DRV_WriteReg32(USB_DMAQ_QIMCR, USB_DMAQ_QIMCR_RX_DONE(dma_chan-1)|USB_DMAQ_QIMCR_RXEP_ERR|USB_DMAQ_QIMCR_RXQ_ERR|USB_DMAQ_QIMCR_RQ_EMPTY);
		DRV_WriteReg32(USB_DMAQ_RQSAR(dma_chan), (USB_DMAQ_RX_GPD+dma_chan-1));
		DRV_WriteReg32(USB_DMAQ_RQCSR(dma_chan), USB_DMACNTL_DMAEN_START);

		RestoreIRQMask(savedMask);
	}
	else
	{				
//		DRV_WriteReg32(USB_DMAQ_TQCSR(dma_chan), USB_DMACNTL_DMAEN_STOP);
		if ((DRV_Reg32(USB_DMAQ_TQCSR(dma_chan))&USB_DMACNTL_DMAEN_ACTIVE) > 0)
		{
//			for (delay =0; delay < 200; delay ++);
			temp_read = DRV_Reg32(USB_DMAQ_TQCSR(dma_chan));
			
			while (1)
			{
				temp_read = DRV_Reg32(USB_DMAQ_TQCSR(dma_chan));
				if (temp_read == 0x00)
					break;
			}
//			if ((DRV_Reg32(USB_DMAQ_TQCSR(dma_chan))&USB_DMACNTL_DMAEN_ACTIVE) > 0)
//				ASSERT(0);
		}
	
		/*fill GPD buffers*/
		for (index = 0; index < TGPD_MAX_NUMBERS; index++)
		{
		  	USB_DMAQ_TX_GPD[index].flag = TGPD_FLAGS_HWO; //1:HW is Owner, SW should not to access data buffer; HW will clear it to 0.
		  	USB_DMAQ_TX_GPD[index].chksum = 0;//PDU_calcCksum((kal_uint8 *)(USB_DMAQ_GPD+index), 16)-1;
		  	USB_DMAQ_TX_GPD[index].DataBufferLen = 0;
		  	USB_DMAQ_TX_GPD[index].pNext = &(USB_DMAQ_TX_GPD[index+1]);
		  	USB_DMAQ_TX_GPD[index].pBuf = (kal_uint8*)addr;
		  	USB_DMAQ_TX_GPD[index].bufLen =  length;
		  	USB_DMAQ_TX_GPD[index].ExtLength = 0;
		  	USB_DMAQ_TX_GPD[index].ZTepFlag = 0;//ep_num;
}

		g_UsbHcdInfo[usb_ip_port].dmaQ_tx_length[dma_chan-1]= length;
			
		savedMask = SaveAndSetIRQMask();
		
		DRV_WriteReg32(USB_DMAQ_TQSAR(dma_chan), (USB_DMAQ_TX_GPD+2));		
		DRV_WriteReg8(USB_INDEX, ep_num);			
		DRV_WriteReg(USB_TXCSR, USB_HCD_DMAQ_TX_CSR);	
//  		DRV_WriteReg32(USB_DMAQ_QCR3, 0x00000000);  // there should be no ZLP
//		DRV_WriteReg32(USB_DMAQ_USBGCSR,  DRV_Reg32(USB_DMAQ_USBGCSR)|(USB_DMAQ_USBGCSR_TQ_EN<<(dma_chan-1)));
//		DRV_WriteReg32(USB_DMAQ_QIMCR, USB_DMAQ_QIMCR_TX_DONE(dma_chan-1)|USB_DMAQ_QIMCR_TXEP_ERR|USB_DMAQ_QIMCR_TXQ_ERR|USB_DMAQ_QIMCR_TQ_EMPTY);
		DRV_WriteReg32(USB_DMAQ_TQSAR(dma_chan), (USB_DMAQ_TX_GPD+dma_chan-1));
		DRV_WriteReg32(USB_DMAQ_TQCSR(dma_chan), USB_DMACNTL_DMAEN_START);

		RestoreIRQMask(savedMask);
	}
}
#endif



/* May run in task */
static void USB_HCD_Send_Setup(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str)
{
	kal_uint32 savedMask;


	USB_Dbg_Trace(USB_HCD_EP0_CSR0,  1, USB_DRV_Reg8(USB_EPn_TXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port], 0)));

	if(usb_ep_str.ep_num != 0)
		EXT_ASSERT(0, usb_ep_str.ep_num, 0, 0);


	if (g_UsbHcdInfo[common_str.usb_ip_port].host_state == USBH_STATE_WAIT_BCON)  // cable just plug out
		return;


	if ( USB_DRV_Reg8(USB_EPn_TXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port], 0))  & USB_CSR0_TXPKTRDY)
		ASSERT(0);

	/* Write 8 bytes setup packet to FIFO */
	USB_HCD_EPFIFOWrite(common_str,usb_ep_str, 8, g_UsbHcdInfo[common_str.usb_ip_port].ep0_info.p_data);
	g_UsbHcdInfo[common_str.usb_ip_port].ep0_fifo_intr = KAL_TRUE;

	savedMask = SaveAndSetIRQMask();
	USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[common_str.usb_ip_port]), 0);
	USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[common_str.usb_ip_port]), (USB_CSR0_TXPKTRDY|USB_CSR0_SETUPPKT));
	RestoreIRQMask(savedMask);

}


/* May run in app task */
static void USB_HCD_Send_Data(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str)
{
	kal_uint16 todo;
	kal_uint32 savedMask;
	kal_uint8 usb_ip_port = common_str.usb_ip_port;
	kal_uint8 ep_num = usb_ep_str.ep_num;



	if(ep_num == 0)
	{
		if(g_UsbHcdInfo[usb_ip_port].ep0_info.b_dma_enable == KAL_TRUE)
		{
			ASSERT(0);
/*
			USB_HCD_DMA_Setup(0, USB_EP_TX_DIR, g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].ep_type, (kal_uint32)g_UsbHcdInfo[usb_ip_port].ep0_info.p_data, 
					g_UsbHcdInfo[usb_ip_port].ep0_info.data_length, KAL_FALSE, KAL_TRUE, USB_DMA0_TYPE);
*/
		}
		else
		{
			USB_Dbg_Trace(USB_HCD_EP0_CSR0,  2, USB_DRV_Reg8(USB_EPn_TXCSR_HCD(USB_BaseAddr[usb_ip_port], 0)));
			
			if (USB_DRV_Reg8(USB_EPn_TXCSR_HCD(USB_BaseAddr[usb_ip_port], 0))  & USB_CSR0_TXPKTRDY)
				ASSERT(0);
			
			if((g_UsbHcdInfo[usb_ip_port].ep0_info.data_length-g_UsbHcdInfo[usb_ip_port].ep0_info.sofar)
				>g_UsbHcdInfo[usb_ip_port].ep0_info.max_packet_size)
				todo = g_UsbHcdInfo[usb_ip_port].ep0_info.max_packet_size;
			else
				todo = g_UsbHcdInfo[usb_ip_port].ep0_info.data_length-g_UsbHcdInfo[usb_ip_port].ep0_info.sofar;

			/* Write data packet to FIFO */
			USB_HCD_EPFIFOWrite(common_str,usb_ep_str, todo, &g_UsbHcdInfo[usb_ip_port].ep0_info.p_data[g_UsbHcdInfo[usb_ip_port].ep0_info.sofar]);
			g_UsbHcdInfo[usb_ip_port].ep0_info.sofar += todo;
			g_UsbHcdInfo[usb_ip_port].ep0_fifo_intr = KAL_TRUE;

			USB_Dbg_Trace(USB_HCD_EP0_Data,  (kal_uint32)g_UsbHcdInfo[usb_ip_port].ep0_info.sofar, (kal_uint32)g_UsbHcdInfo[usb_ip_port].ep0_info.data_length);

			savedMask = SaveAndSetIRQMask();
			USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), 0);
			USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), USB_CSR0_TXPKTRDY);
			RestoreIRQMask(savedMask);

			USB_Dbg_Trace(USB_HCD_SEND_DATA_DONE,  ep_num, 0);
		}
	}
	else
	{
		if((g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].b_dma_enable == KAL_TRUE)&&(g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].data_length >= 64))
		{
			USB_HCD_DMA_Setup(common_str,usb_ep_str,(kal_uint32)g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].p_data, 
					g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].data_length,NULL, KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		}
		else
		{
			if((g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].data_length-g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].sofar)
				>g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].max_packet_size)
				todo = g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].max_packet_size;
			else
				todo = g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].data_length-g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].sofar;

			/* Write data packet to FIFO */
			USB_HCD_EPFIFOWrite(common_str,usb_ep_str,g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].data_length,&g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].p_data[g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].sofar]);

			g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].sofar += todo;
			g_UsbHcdInfo[usb_ip_port].ep_tx_fifo_intr[ep_num-1] = KAL_TRUE;

			savedMask = SaveAndSetIRQMask();
			USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);
			USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_TXCSR_TXPKTRDY);
			RestoreIRQMask(savedMask);

			USB_Dbg_Trace(USB_HCD_SEND_DATA_DONE,  ep_num, 0);
		}
	}
}


/* Run in HISR */
static void USB_HCD_Recv_Data(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str)
{
	SGPT_CTRL_START_T start;
	kal_uint8 dma_chan;
	kal_uint32 savedMask;
	kal_uint8 usb_ip_port = common_str.usb_ip_port;
	kal_uint8 ep_num = usb_ep_str.ep_num;

	if(ep_num == 0)
	{
		if(g_UsbHcdInfo[usb_ip_port].ep0_info.b_dma_enable == KAL_TRUE)
		{
			ASSERT(0);
/*
			USB_HCD_DMA_Setup(0, USB_EP_RX_DIR, g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].ep_type, (kal_uint32)g_UsbHcdInfo[usb_ip_port].ep0_info.p_data, 
					g_UsbHcdInfo[usb_ip_port].ep0_info.data_length, KAL_FALSE, KAL_TRUE, USB_DMA0_TYPE);
*/
		}
		else
		{
			USB_Dbg_Trace(USB_HCD_EP0_CSR0,  2, USB_DRV_Reg8(USB_EPn_TXCSR_HCD(USB_BaseAddr[usb_ip_port], 0)));
			
			if (USB_DRV_Reg8(USB_EPn_TXCSR_HCD(USB_BaseAddr[usb_ip_port], 0))  & USB_CSR0_REQPKT)
				ASSERT(0);
					
			g_UsbHcdInfo[usb_ip_port].ep0_fifo_intr = KAL_TRUE;

			savedMask = SaveAndSetIRQMask();
			USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), 0);
			USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), USB_CSR0_REQPKT);
			RestoreIRQMask(savedMask);
		}
	}
	else
	{
		if(g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].b_dma_enable == KAL_TRUE)
		{
			dma_chan = USB_HCD_Get_DMA_Channel_Num(usb_ip_port,ep_num, USB_EP_RX_DIR);

			/* Receive short packet will hang */
			start.u2Tick = USB_HCD_DMA_TIMER;					
  	  		start.pfCallback = USB_HCD_DMA_Timeout_Hdlr;			
  	  		start.vPara = &g_UsbHcdInfo[usb_ip_port].dma_rx_ep_num[dma_chan-1];							
  	 		DclSGPT_Control((DCL_HANDLE)(g_UsbHcdInfo[usb_ip_port].dma_gpt_handle[ep_num-1]), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);				
//			GPTI_StartItem(g_UsbHcdInfo[usb_ip_port].dma_gpt_handle[ep_num-1], USB_HCD_DMA_TIMER,USB_HCD_DMA_Timeout_Hdlr,(void*)&g_UsbHcdInfo[usb_ip_port].dma_rx_ep_num[dma_chan-1]);

			USB_HCD_DMA_Setup(common_str,usb_ep_str, (kal_uint32)g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].p_data, g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].data_length,
				NULL,KAL_FALSE, KAL_TRUE, USB_DMA1_TYPE);
		}
		else
		{
			savedMask = SaveAndSetIRQMask();

			USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);
			USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_RXCSR_REQPKT);
			RestoreIRQMask(savedMask);
		}
	}
}

static kal_bool USB_HCD_Is_DoubleFIFO_SUPPORT(kal_uint8 usb_ip_port)
{
	return g_UsbHcdInfo[usb_ip_port].host_common_param->support_Double_FIFO;
}




static void USB_HCD_DMA_Timeout_Hdlr(void *parameter)
{
	kal_uint8* temp = (kal_uint8*)parameter;
	kal_uint8 ep_num =  *temp;

//	USB_HCD_Struct *USBD_Data = (USB_HCD_Struct *)parameter;
	kal_uint8 usb_ip_port = 0;//USBD_Data->usb_ip_port;
	
	kal_uint8  dma_chan;

	dma_chan = USB_HCD_Get_DMA_Channel_Num(usb_ip_port,ep_num, USB_EP_RX_DIR);
	
	DclSGPT_Control((DCL_HANDLE)(g_UsbHcdInfo[usb_ip_port].dma_gpt_handle[ep_num-1]), SGPT_CMD_STOP, 0);
//	GPTI_StopItem(g_UsbHcdInfo[usb_ip_port].dma_gpt_handle[ep_num-1]);

	USB_Dbg_Trace(USB_HCD_DMA_TIMEOUT_ERROR,  ep_num, dma_chan);
	drv_trace0(TRACE_FUNC, (kal_uint32)USB_HCD_RX_DMA_TIMEOUT);


	if((g_UsbHcdInfo[usb_ip_port].dma_dir[dma_chan-1] == USB_EP_TX_DIR)||(g_UsbHcdInfo[usb_ip_port].dma_running[dma_chan-1] == KAL_FALSE))
	{
		ASSERT(0);
	}
	else
	{
		/* stop DMA channel */
		USBHCD_DMA_Stop(USB_BaseAddr[usb_ip_port],dma_chan);

		/* Clear pending DMA interrupts */
#ifdef DRV_USB_IP_V3 	
		// write 0 clear
		USB_DRV_WriteReg32(USB_DMAINTR_HCD(USB_BaseAddr[usb_ip_port]), ~((1<<(dma_chan-1))|(0xC000<<(dma_chan*2))));
#else // DRV_USB_IP_V4
			// write 1 clear
			USB_DRV_WriteReg8(USB_DMAINTR_HCD(USB_BaseAddr[usb_ip_port]), (1<<(dma_chan-1)));
#endif

		USB_HCD_EP_Bulk_Rx_Ready(usb_ip_port,ep_num);
	}

	g_UsbHcdInfo[usb_ip_port].dma_pktrdy[dma_chan-1] = KAL_FALSE;

	/* if application callback function does not request to clear drv_running set by itself, clear running state here*/
	if(g_UsbHcdInfo[usb_ip_port].dma_callback_upd_run[dma_chan-1] == KAL_FALSE)
	{
		g_UsbHcdInfo[usb_ip_port].dma_running[dma_chan-1] = KAL_FALSE;
	}

	g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1](usb_ip_port,USB_HCD_DMA_TIMEOUT, g_UsbHcdInfo[usb_ip_port].dma_length[dma_chan-1]);

}


/* DMA callback */
void USB_HCD_DMA_Callback(kal_uint8 usb_ip_port,kal_uint8 dma_chan)
{
	kal_uint8 ep_num;
	usb_dma_callback callback;

	if(dma_chan == 0)
		ASSERT(0);

	callback = g_UsbHcdInfo[usb_ip_port].dma_callback[dma_chan-1];
	g_UsbHcdInfo[usb_ip_port].dma_callback[dma_chan-1] = NULL;	
	/*lint -save -e676 */
	if(g_UsbHcdInfo[usb_ip_port].dma_dir[dma_chan-1] == USB_EP_TX_DIR)
	{
		ep_num = g_UsbHcdInfo[usb_ip_port].dma_tx_ep_num[dma_chan-1];
		USB_HCD_EP_Check(usb_ip_port,ep_num, USB_EP_TX_DIR, 0);
	}
	else
	{
		ep_num = g_UsbHcdInfo[usb_ip_port].dma_rx_ep_num[dma_chan-1];
		USB_HCD_EP_Check(usb_ip_port,ep_num, USB_EP_RX_DIR, 0);
		
		DclSGPT_Control((DCL_HANDLE)(g_UsbHcdInfo[usb_ip_port].dma_gpt_handle[ep_num-1]), SGPT_CMD_STOP, 0);
//		GPTI_StopItem(g_UsbHcdInfo[usb_ip_port].dma_gpt_handle[ep_num-1]);
		
	#ifdef __WRITE_THROUGH_CACHEABLE__
		/* Only RX need to invalidate cache */
		invalidate_wt_cache(g_UsbHcdInfo[usb_ip_port].dma_addr[dma_chan - 1], g_UsbHcdInfo[usb_ip_port].dma_length[dma_chan - 1]);
	#endif		
	}

	USB_Dbg_Trace(USB_HCD_DMA_CALLBACK,  ep_num, dma_chan);


	/* ep0 do not do this */
	if(g_UsbHcdInfo[usb_ip_port].dma_pktrdy[dma_chan-1] == KAL_TRUE)
	{
		if(g_UsbHcdInfo[usb_ip_port].dma_dir[dma_chan-1] == USB_EP_TX_DIR)
		{
			USB_HCD_EP_Bulk_Tx_Ready(usb_ip_port,ep_num);
	#ifdef __USB_AUTO_SET__
			if(((ep_num == 1)&&(dma_chan == 2))||
				((ep_num == 2)&&(dma_chan == 3))||  
					((ep_num == 3)&&(dma_chan == 4))) 
			{
				ASSERT(0);
			}
	#endif
		}
		else if(g_UsbHcdInfo[usb_ip_port].dma_dir[dma_chan-1] == USB_EP_RX_DIR)
		{
			USB_HCD_EP_Bulk_Rx_Ready(usb_ip_port,ep_num);
		}
	}

	g_UsbHcdInfo[usb_ip_port].dma_pktrdy[dma_chan-1] = KAL_FALSE;

	/* if application callback function does not request to clear drv_running set by itself, clear running state here*/
	if(g_UsbHcdInfo[usb_ip_port].dma_callback_upd_run[dma_chan-1] == KAL_FALSE)
	{
		g_UsbHcdInfo[usb_ip_port].dma_running[dma_chan-1] = KAL_FALSE;
	}

	if (callback != NULL)
	{	
		callback();
	}
	else
	{
		if(g_UsbHcdInfo[usb_ip_port].dma_dir[dma_chan-1] == USB_EP_TX_DIR)
			g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1](usb_ip_port,USB_HCD_OK, g_UsbHcdInfo[usb_ip_port].dma_length[dma_chan-1]);
		else
			g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1](usb_ip_port,USB_HCD_OK, g_UsbHcdInfo[usb_ip_port].dma_length[dma_chan-1]);
	}	
	/*lint -restore */
}


#if defined(DRV_USB_IP_V4)

void USB_HCD_DMAQ_Callback(kal_uint8 usb_ip_port,kal_uint8 index,USB_EP_DIRECTION direction)
{
	kal_uint8 ep_num = index+1;

	if (direction == USB_EP_RX_DIR)
	{
		
			if (USB_DMAQ_RX_GPD[index].flag == RGPD_FLAGS_HWO)
				ASSERT(0);
							
		//	DRV_WriteReg32(USB_DMAQ_RQCSR(index+1), USB_DMACNTL_DMAEN_STOP); // stop bit : not immediately stop DMAQ (must wait HW scheduling)
			
			if (g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1] != NULL)
					g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1](usb_ip_port,USB_HCD_OK, g_UsbHcdInfo[usb_ip_port].dmaQ_rx_length[index]);
	}
	else
	{
			if (USB_DMAQ_TX_GPD[index].flag == TGPD_FLAGS_HWO)
				ASSERT(0);
							
		//	DRV_WriteReg32(USB_DMAQ_TQCSR(index+1), USB_DMACNTL_DMAEN_STOP); // stop bit : not immediately stop DMAQ (must wait HW scheduling)
			
			if (g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1] != NULL) 			
				g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1](usb_ip_port,USB_HCD_OK, g_UsbHcdInfo[usb_ip_port].dmaQ_tx_length[index]);
	}
		
}

#endif



static void USB_HCD_DMA_Stop(kal_uint8 usb_ip_port,kal_uint8 ep_num, USB_EP_DIRECTION direction)
{
	kal_uint8   dma_chan;


	/* Stop running DMA */
	USB_HCD_EP_Check(usb_ip_port,ep_num, direction, 0);
	dma_chan = g_UsbHcdInfo[usb_ip_port].dma_port[direction][ep_num-1];

	if(dma_chan != 0)
	{
		if(g_UsbHcdInfo[usb_ip_port].dma_running[dma_chan-1] == KAL_TRUE)
		{
			if((g_UsbHcdInfo[usb_ip_port].is_bidirection_dma[dma_chan-1] == KAL_FALSE)
				&&(g_UsbHcdInfo[usb_ip_port].dma_dir[dma_chan-1] != direction))
			{
				ASSERT(0);
			}

			USB_HCD_Stop_DMA_Channel(usb_ip_port,ep_num, direction);
		}
	}
}

#if defined(DRV_USB_IP_V4)

static void USB_HCD_DMAQ_Stop(kal_uint8 usb_ip_port,kal_uint8 ep_num, USB_EP_DIRECTION direction)
{

}
#endif

/*************************************************************************
* FUNCTION
*  DclUSB_HCD_Initialize
*
* DESCRIPTION
*  This function is to initialize USB host module
*  It should be called before user register USB EINT handler and only called once
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK : command is executed successfully.
*  STATUS_INVALID_OPERATION : already initialized.
*
*************************************************************************/
DCL_STATUS DclUSB_HCD_Initialize(void)
{
	if(g_USB_Hcd_Init == KAL_TRUE)
	{
		/* Already initialized */
		return STATUS_INVALID_OPERATION;
	}
	else
	{
		g_USB_Hcd_Init = KAL_TRUE;
		return STATUS_OK;
	}
}


/*************************************************************************
* FUNCTION
*  DclUSB_HCD_Open
*
* DESCRIPTION
*  This function is to open the USB host module and return a valid handle
*
* PARAMETERS
*  dev: only valid for DCL_USB
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed
*  DCL_HANDLE_OCCUPIED: Already opened
*  Other value: A valid handle
*
*************************************************************************/
DCL_HANDLE DclUSB_HCD_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	if(dev != DCL_USB)
	{
		ASSERT(0);
		return (DCL_HANDLE)DCL_HANDLE_INVALID;
	}
	else
	{
		if(g_USB_Hcd_Open == KAL_FALSE)
		{
			g_USB_Hcd_Open = KAL_TRUE;

			/* Do open operation */
//			USB_PDNmode(KAL_TRUE);
			return (DCL_HANDLE)DCL_USB_HCD_HANDLE;
		}
		else
		{	
			/* Call open over once */
			return (DCL_HANDLE)DCL_HANDLE_OCCUPIED;
		}
	}
}

/*************************************************************************
* FUNCTION
*  DclUSB_HCD_Close
*
* DESCRIPTION
*  This function is to close the USB host module.
*
* PARAMETERS
*  handle: the returned handle value of DclUSB_HCD_Open
*
* RETURNS
*  STATUS_INVALID_OPERATION: OTG module does not open yet, but user want to close
*  STATUS_INVALID_DCL_HANDLE: Use invalid handle to close
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS DclUSB_HCD_Close(DCL_HANDLE handle)
{
	/* Check open or not and handle validity */
	if(DCL_USB_HCD_CHECK_HANDLE_IS_VALID(handle) == 0)
	{
		ASSERT(0);

		if(g_USB_Hcd_Open == KAL_FALSE)
			return STATUS_INVALID_OPERATION;
		else
			return STATUS_INVALID_DCL_HANDLE;
	}

	g_USB_Hcd_Open = KAL_FALSE;
//	USB_PDNmode(KAL_FALSE);
	return STATUS_OK;
}


/*************************************************************************
* FUNCTION
*  DclUSB_HCD_ReadData
*
* DESCRIPTION
*  This function is not supported for the USB host module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclUSB_HCD_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	/* Check open or not and handle validity */
/*	
	if((g_USB_Hcd_Open == KAL_FALSE)||(DCL_USB_HCD_CHECK_HANDLE_IS_VALID(handle) == 0))
	{
		ASSERT(0);

		if(g_USB_Hcd_Open == KAL_FALSE)
			return STATUS_INVALID_OPERATION;
		else
			return STATUS_INVALID_DCL_HANDLE;
	}
*/
	return STATUS_UNSUPPORTED;
}



/*************************************************************************
* FUNCTION
*  DclUSB_DRV_WriteData
*
* DESCRIPTION
*  This function is not supported for the USB host module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclUSB_HCD_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	/* Check open or not and handle validity */
/*	
	if((g_USB_Hcd_Open == KAL_FALSE)||(DCL_USB_HCD_CHECK_HANDLE_IS_VALID(handle) == 0))
	{
		ASSERT(0);

		if(g_USB_Hcd_Open == KAL_FALSE)
			return STATUS_INVALID_OPERATION;
		else
			return STATUS_INVALID_DCL_HANDLE;
	}
*/
	return STATUS_UNSUPPORTED;
}



/*************************************************************************
* FUNCTION
*  DclUSB_HCD_Configure
*
* DESCRIPTION
*  This function is not supported for the USB host module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclUSB_HCD_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	/* Check open or not and handle validity */
/*	
	if((g_USB_Hcd_Open == KAL_FALSE)||(DCL_USB_HCD_CHECK_HANDLE_IS_VALID(handle) == 0))
	{
		ASSERT(0);

		if(g_USB_Hcd_Open == KAL_FALSE)
			return STATUS_INVALID_OPERATION;
		else
			return STATUS_INVALID_DCL_HANDLE;
	}
*/
	return STATUS_UNSUPPORTED;
}



/*************************************************************************
* FUNCTION
*  DclUSB_HCD_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the USB host module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclUSB_HCD_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	/* Check open or not and handle validity */
/*	
	if((g_USB_Hcd_Open == KAL_FALSE)||(DCL_USB_HCD_CHECK_HANDLE_IS_VALID(handle) == 0))
	{
		ASSERT(0);

		if(g_USB_Hcd_Open == KAL_FALSE)
			return STATUS_INVALID_OPERATION;
		else
			return STATUS_INVALID_DCL_HANDLE;
	}
*/
	return STATUS_UNSUPPORTED;
}


/*******************************************************************************
	control functions for USB_HCD
 *******************************************************************************/
DCL_STATUS DCL_USB_CTRL_API_USB_HCD_HW_Mapping_EP(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_EP_MAPPING_T *ep_num;
	kal_uint8	usb_ip_port;
	USB_EP_DIRECTION direction;

	
	ep_num = &data->rHCD_EP_Set;
	usb_ip_port = (kal_uint8)ep_num->ip;
	direction = (USB_EP_DIRECTION)ep_num->direction;

	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);


	if(direction == USB_EP_TX_DIR)
	{
		g_UsbHcdInfo[usb_ip_port].ep_tx_real_num++;
		
		if (((usb_ip_port < USB_EXT_IP_NUM)&& (g_UsbHcdInfo[usb_ip_port].ep_tx_real_num > MAX_TX_EP_NUM)))
			ASSERT(0);
			
#if defined(__IC_USB_ENABLE__)
		if (((usb_ip_port >= USB_EXT_IP_NUM)&& (g_UsbHcdInfo[usb_ip_port].ep_tx_real_num > ICUSB_MAX_TX_EP_NUM)))			
			ASSERT(0);
#endif

		ep_num->return_value = g_UsbHcdInfo[usb_ip_port].ep_tx_real_num;
	}
	else
	{
		g_UsbHcdInfo[usb_ip_port].ep_rx_real_num++;
		
		if (((usb_ip_port < USB_EXT_IP_NUM)&& (g_UsbHcdInfo[usb_ip_port].ep_rx_real_num > MAX_RX_EP_NUM)))
			ASSERT(0);
			
#if defined(__IC_USB_ENABLE__)			
		if (((usb_ip_port >= USB_EXT_IP_NUM)&& (g_UsbHcdInfo[usb_ip_port].ep_rx_real_num > ICUSB_MAX_RX_EP_NUM)))	
			ASSERT(0);
#endif			

		ep_num->return_value = g_UsbHcdInfo[usb_ip_port].ep_rx_real_num;
	}

	return STATUS_OK;
}




DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Reset_Device(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_RESET_T *reset_device;
	kal_uint8	usb_ip_port;
	USB_HCD_STATUS reset_reason;
//	kal_uint16  IntrStatus;
	
	reset_device = &data->rHCD_RESET;
	usb_ip_port = (kal_uint8)reset_device->ip;
	reset_reason = (USB_HCD_STATUS)reset_device->reset_reason; 

	USB_HCD_Reset_Device(usb_ip_port,reset_reason);

	return STATUS_OK;
}

DCL_STATUS DCL_USB_CTRL_API_USB_HCD_SWRST(DCL_CTRL_DATA_T *data)
{ 
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
	kal_uint8	usb_ip_port;
	
	usb_ip = &data->rHCD_ip;
	usb_ip_port = (kal_uint8)usb_ip->ip;

#if defined(DRV_USB_IP_V3)
	USB_DRV_WriteReg(USB_SWRST_HCD(USB_BaseAddr[usb_ip_port]), USB_SWRST_SWRST);
#elif defined(DRV_USB_IP_V4)
	USB_DRV_SetBits(USB_BUSPERF3_HCD(USB_BaseAddr[usb_ip_port]), USB_BUSPERF3_SWRST);
#endif

	return STATUS_OK;
}

DCL_STATUS DCL_USB_CTRL_API_USB_HCD_EnSysIntr(DCL_CTRL_DATA_T *data)
{ 
	USB_HCD_CTRL_SYSTEM_T *system_drv;
	kal_uint8	usb_ip_port;
	kal_bool 	turn_on;
	
	system_drv = &data->rHCD_System_Set;
	usb_ip_port = (kal_uint8)system_drv->ip;
	turn_on = (kal_bool)system_drv->set;

	if (turn_on == KAL_TRUE)
	{	
		USB_DRV_WriteReg8(USB_INTRUSBE_HCD(USB_BaseAddr[usb_ip_port]), ~USB_INTRUSBE_SOF);
	}
	else
	{	
		USB_DRV_WriteReg8(USB_INTRUSBE_HCD(USB_BaseAddr[usb_ip_port]), USB_INTRUSBE_SOF);
}
	
	return STATUS_OK;
}
 
DCL_STATUS DCL_USB_CTRL_API_USB_HCD_VBusEnable(DCL_CTRL_DATA_T *data)
{ 
	USB_HCD_CTRL_SYSTEM_T *system_drv;
	kal_uint8	usb_ip_port;
	kal_bool	enable;
	
	system_drv = &data->rHCD_System_Set;
	usb_ip_port = (kal_uint8)system_drv->ip;
	enable = (kal_bool)system_drv->set;

	USB_HCD_VBusEnable(usb_ip_port,enable);

	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);

	if(enable == KAL_TRUE)
	{	
		USB_DRV_SetBits8(USB_DEVCTL_HCD(USB_BaseAddr[usb_ip_port]), USB_DEVCTL_SESSION);
	}
	else
	{	
		USB_DRV_ClearBits8(USB_DEVCTL_HCD(USB_BaseAddr[usb_ip_port]), USB_DEVCTL_SESSION);
	}	

	return STATUS_OK;
	
} 
 
 
DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Host_Mode_Detect(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
	kal_uint8	usb_ip_port;
	
	usb_ip = &data->rHCD_ip;
	usb_ip_port = (kal_uint8)usb_ip->ip;

	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);
	
	if (USB_DRV_Reg8(USB_DEVCTL_HCD(USB_BaseAddr[usb_ip_port]))& USB_DEVCTL_HOSTMODE)
		usb_ip->return_value = KAL_TRUE;
	else
		usb_ip->return_value = KAL_FALSE;

	return STATUS_OK;
}
 
DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Is_HNP_SUPPORT(DCL_CTRL_DATA_T *data)
{ 
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
	kal_uint8	usb_ip_port;
	
	usb_ip = &data->rHCD_ip;
	usb_ip_port = (kal_uint8)usb_ip->ip;

	usb_ip->return_value = g_UsbHcdInfo[usb_ip_port].host_common_param->support_HNP;

	return STATUS_OK;	
}

DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Is_RemoteWakeup_SUPPORT(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
	kal_uint8	usb_ip_port;
	
	usb_ip = &data->rHCD_ip;
	usb_ip_port = (kal_uint8)usb_ip->ip;

	usb_ip->return_value = USB_HCD_Is_RemoteWakeup_SUPPORT(usb_ip_port);
	
	return STATUS_OK;		
}

DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Is_SRP_SUPPORT(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
	kal_uint8	usb_ip_port;
	
	usb_ip = &data->rHCD_ip;
	usb_ip_port = (kal_uint8)usb_ip->ip;

	usb_ip->return_value = g_UsbHcdInfo[usb_ip_port].host_common_param->support_SRP;
	
	return STATUS_OK;		
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Is_High_Speed(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
	kal_uint8	usb_ip_port;
	
	usb_ip = &data->rHCD_ip;
	usb_ip_port = (kal_uint8)usb_ip->ip;

	usb_ip->return_value = USB_HCD_Is_High_Speed(usb_ip_port);//g_UsbHcdInfo[usb_ip_port].b_hcd_is_high_speed;

	return STATUS_OK;
} 
 

DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Reset_Resource(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
	kal_uint8	usb_ip_port;
	
	usb_ip = &data->rHCD_ip;
	usb_ip_port =(kal_uint8)usb_ip->ip;

	USB_HCD_Reset_Resource(usb_ip_port);

	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Init_Drv_Info(DCL_CTRL_DATA_T *data)
{
/* called by OTG_Host_Up_Hdlr */
	kal_uint32 	index;
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
	kal_uint8	usb_ip_port;
	
	usb_ip = &data->rHCD_ip;
	usb_ip_port = (kal_uint8)usb_ip->ip;

	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);
	
	/* interrupt handler */
	g_UsbHcdInfo[usb_ip_port].attach_hdlr = NULL;
	g_UsbHcdInfo[usb_ip_port].detach_hdlr = NULL;
	g_UsbHcdInfo[usb_ip_port].resume_hdlr = NULL;

	g_UsbHcdInfo[usb_ip_port].ep0_hdlr = NULL;
	g_UsbHcdInfo[usb_ip_port].ep0_info.b_enable = KAL_FALSE;

	for(index = 0; index < MAX_TX_EP_NUM; index++)
	{
		g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[index] = NULL;
		g_UsbHcdInfo[usb_ip_port].ep_tx_info[index].b_enable = KAL_FALSE;
}

	for(index = 0; index < MAX_RX_EP_NUM; index++)
	{
		g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[index] = NULL;
		g_UsbHcdInfo[usb_ip_port].ep_rx_info[index].b_enable = KAL_FALSE;
	}

	/* DMA parameters */
	for(index = 0; index < MAX_EP_NUM; index++)
	{
		g_UsbHcdInfo[usb_ip_port].dma_port[USB_EP_TX_DIR][index] = 0;
		g_UsbHcdInfo[usb_ip_port].dma_port[USB_EP_RX_DIR][index] = 0;
	}

	for(index = 0; index < MAX_DMA_NUM; index++)
	{
		g_UsbHcdInfo[usb_ip_port].dma_pktrdy[index] = KAL_FALSE;
		g_UsbHcdInfo[usb_ip_port].dma_running[index] = KAL_FALSE;
		g_UsbHcdInfo[usb_ip_port].dma_callback_upd_run[index] = KAL_FALSE;
		g_UsbHcdInfo[usb_ip_port].dma_tx_ep_num[index] = 0;
		g_UsbHcdInfo[usb_ip_port].dma_rx_ep_num[index] = 0;
	}

	g_UsbHcdInfo[usb_ip_port].b_unmask_irq = KAL_TRUE;

	g_UsbHcdInfo[usb_ip_port].ep_tx_real_num = 0;
	g_UsbHcdInfo[usb_ip_port].ep_rx_real_num = 0;

	USB_HCD_Reset_Resource(usb_ip_port);

	if ((g_UsbHcdInfo[usb_ip_port].gpt_handle == 0)||(g_UsbHcdInfo[usb_ip_port].gpt_handle == 0x7F))
		g_UsbHcdInfo[usb_ip_port].gpt_handle= DclSGPT_Open(DCL_GPT_CB, 0);
//		GPTI_GetHandle(&g_UsbHcdInfo[usb_ip_port].gpt_handle);

	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Release_Drv_Info(DCL_CTRL_DATA_T *data)
{
	DCL_HANDLE handle;
	kal_uint32 	index;
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
	kal_uint8	usb_ip_port;
	
	usb_ip = &data->rHCD_ip;
	usb_ip_port = (kal_uint8)usb_ip->ip;	

	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);

	g_UsbHcdInfo[usb_ip_port].ep0_hdlr = NULL;
	g_UsbHcdInfo[usb_ip_port].ep0_info.b_enable = KAL_FALSE;

	for(index = 0; index < MAX_TX_EP_NUM; index++)
	{
		g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[index] = NULL;
		g_UsbHcdInfo[usb_ip_port].ep_tx_info[index].b_enable = KAL_FALSE;
	}

	for(index = 0; index < MAX_RX_EP_NUM; index++)
	{
		g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[index] = NULL;
		g_UsbHcdInfo[usb_ip_port].ep_rx_info[index].b_enable = KAL_FALSE;
	}

	USB_HCD_Reset_Resource(usb_ip_port);


 	handle = (DCL_HANDLE)g_UsbHcdInfo[usb_ip_port].gpt_handle;
	g_UsbHcdInfo[usb_ip_port].gpt_handle = DclSGPT_Close(&handle);  
//	GPTI_ReleaseHandle(&g_UsbHcdInfo[usb_ip_port].gpt_handle);

	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Register_Drv_Info(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_REGISTER_DRV_INFO_T *prregister_drv_info;
	kal_uint8 usb_ip_port;
	kal_uint32 ep_num;
	
	prregister_drv_info = &data->rHCD_Drv_Info;
	usb_ip_port = (kal_uint8)prregister_drv_info->ip;
	ep_num = (kal_uint32)prregister_drv_info->u4ep_num;

	
	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);

	switch(prregister_drv_info->type)
	{
	case USB_HCD_HDLR_ATTACH:
		g_UsbHcdInfo[usb_ip_port].attach_hdlr = (usb_hcd_intr_handler_ptr)prregister_drv_info->hdlr;
		break;
	case USB_HCD_HDLR_DETACH:
		g_UsbHcdInfo[usb_ip_port].detach_hdlr = (usb_hcd_intr_handler_ptr)prregister_drv_info->hdlr;
		break;
	case USB_HCD_HDLR_RESUME:
		g_UsbHcdInfo[usb_ip_port].resume_hdlr = (usb_hcd_intr_handler_ptr)prregister_drv_info->hdlr;
		break;
	case USB_HCD_HDLR_EP0:
		g_UsbHcdInfo[usb_ip_port].ep0_hdlr = (usb_hcd_intr_handler_ptr)prregister_drv_info->hdlr;
		break;
	case USB_HCD_HDLR_EP_TX:
		USB_HCD_EP_Check(usb_ip_port,ep_num, USB_EP_TX_DIR, 0);
		g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[prregister_drv_info->u4ep_num -1] = (usb_hcd_intr_handler_ptr)prregister_drv_info->hdlr;
		break;
	case USB_HCD_HDLR_EP_RX:
		USB_HCD_EP_Check(usb_ip_port,ep_num, USB_EP_RX_DIR, 0);
		g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[prregister_drv_info->u4ep_num -1] = (usb_hcd_intr_handler_ptr)prregister_drv_info->hdlr;
		break;
	default:
		EXT_ASSERT(0, (kal_uint32)(prregister_drv_info->type), prregister_drv_info->u4ep_num, 0);
		break;
	}

	return STATUS_OK;

}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Set_UnMask_Irq(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_SYSTEM_T *system_drv;
	
	system_drv = &data->rHCD_System_Set;
	
/* set unmask variable to control if unmask USB interruput when leaving USB HISR*/
	g_UsbHcdInfo[(kal_uint8)(system_drv->ip)].b_unmask_irq = (kal_bool)(system_drv->set);
	
	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Get_UnMask_Irq(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
	
	usb_ip = &data->rHCD_ip;

	usb_ip->return_value = g_UsbHcdInfo[(kal_uint8)(usb_ip->ip)].b_unmask_irq;	
	
	return STATUS_OK;	
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Dis_Attach(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
	
	usb_ip = &data->rHCD_ip;

	g_UsbHcdInfo[(kal_uint8)(usb_ip->ip)].b_disable_attach = KAL_TRUE;
	
	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_En_Attach(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
//	kal_uint8	usb_ip_port;
	
	usb_ip = &data->rHCD_ip;

	g_UsbHcdInfo[(kal_uint8)(usb_ip->ip)].b_disable_attach = KAL_FALSE;

	return STATUS_OK;	
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Initialize_Drv(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
	kal_uint8	usb_ip_port;
	
	usb_ip = &data->rHCD_ip;
	usb_ip_port = (kal_uint8)usb_ip->ip;
		
/* called by OTG_Host_Up_Hdlr */

	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);
		/* Software reset */

	if (usb_ip_port < USB_EXT_IP_NUM)
	{
		// power on in otg_mode selection
	}
#if defined(__IC_USB_ENABLE__)	
	else
	{
		IC_USB_PDNmode(KAL_FALSE);// power on PHY Clock, PHY setting
	}
#endif
		

		
#if defined(DRV_USB_IP_V3)
	USB_DRV_WriteReg(USB_SWRST_HCD(USB_BaseAddr[usb_ip_port]), (USB_SWRST_DISUSBRESET|USB_SWRST_SWRST));
#elif defined(DRV_USB_IP_V4)
	USB_DRV_SetBits(USB_BUSPERF3_HCD(USB_BaseAddr[usb_ip_port]), (USB_BUSPERF3_DISUSBRESET|USB_BUSPERF3_SWRST));
#endif

	USB_DRV_WriteReg8(USB_RSTINFO_HCD(USB_BaseAddr[usb_ip_port]), 0xA0);
	USB_DRV_SetBits8(USB_POWER_HCD(USB_BaseAddr[usb_ip_port]), (USB_POWER_ISOUPDATE|USB_POWER_ENABLESUSPENDM));
	USB_DRV_WriteReg8(USB_VPLEN_HCD(USB_BaseAddr[usb_ip_port]), 0x02); 	

	g_UsbHcdInfo[usb_ip_port].host_common_param = USB_GetCustomFunc()->get_host_common_param_func();
	
	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Release_Drv(DCL_CTRL_DATA_T *data)
{
//	USB_HCD_CTRL_IP_NUM_T *usb_ip;
//	kal_uint8	usb_ip_port;
	
//	usb_ip = &data->rHCD_ip;
//	usb_ip_port = (kal_uint8)usb_ip->ip;

#ifdef __IC_USB_ENABLE__
//RG_USB11_FSLS_ENBGRI = 0
	USB_DRV_ClearBits8(USB_U1PHYCR0_1, USB_U1PHYCR0_1_RG_USB11_FSLS_ENBGRI);	
#endif

	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_SetAddress(DCL_CTRL_DATA_T *data)
{
	/* set address for hw*/
	USB_HCD_CTRL_SET_ADDRESS_T *prset_addr;
	
	prset_addr = &data->rHCD_Set_Addr;
		
	if ((kal_uint8)prset_addr->ip >= USB_IP_NUM)
		ASSERT(0);
	
	USB_DRV_WriteReg8(USB_FADDR_HCD(USB_BaseAddr[(kal_uint8)prset_addr->ip]), prset_addr->addr);
	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Resume(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
	kal_uint8	usb_ip_port;
	
	usb_ip = &data->rHCD_ip;
	usb_ip_port = (kal_uint8)usb_ip->ip;
	
	USB_HCD_Resume(usb_ip_port);

	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Suspend(DCL_CTRL_DATA_T *data)
{
//	USB_HCD_CTRL_IP_NUM_T *usb_ip;
//	kal_uint8	usb_ip_port;

//	usb_ip = &data->rHCD_ip;
//	usb_ip_port = (kal_uint8)usb_ip->ip;
	
	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Delay_Reset_Device(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_DELAY_RESET_DEVICE_T *prdelay_reset_device;
	kal_uint8 usb_ip_port;
	SGPT_CTRL_START_T start;
	
	prdelay_reset_device = &data->rHCD_Delay_Reset_Device;
	usb_ip_port = (kal_uint8)prdelay_reset_device->ip;

/* Reset after timeout, note that timeout unit is 10ms */

	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);

	g_UsbHcdInfo[usb_ip_port].reset_reason = (USB_HCD_STATUS)prdelay_reset_device->result;
	
	if((prdelay_reset_device->u4param)>0)
	{
		start.u2Tick = prdelay_reset_device->u4param;					
    		start.pfCallback = USB_HCD_Delay_Reset_Timeout;			
    		start.vPara = &g_UsbHcdInfo[usb_ip_port];							
    		DclSGPT_Control((DCL_HANDLE)(g_UsbHcdInfo[usb_ip_port].gpt_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	
//		GPTI_StartItem(g_UsbHcdInfo[usb_ip_port].gpt_handle, prdelay_reset_device->u4param,USB_HCD_Delay_Reset_Timeout, &g_UsbHcdInfo[usb_ip_port]);
	}
	else
	{
		USB_HCD_Reset_Device(usb_ip_port,(USB_HCD_STATUS)prdelay_reset_device->result);
	}
	
	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Set_EP_Max_Pkt(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_EP_CTRL_FUNC_1_T *prep_ctrl_func_1;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;
	USB_ENDPT_TXFER_TYPE	ep_type;

	prep_ctrl_func_1 = &data->rHCD_EP_Ctrl_Func_1;
	
	common_str.if_num = (kal_uint32)prep_ctrl_func_1->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep_ctrl_func_1->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep_ctrl_func_1->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep_ctrl_func_1->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep_ctrl_func_1->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep_ctrl_func_1->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep_ctrl_func_1->usb_ep_str.direction;				


	if (common_str.usb_ip_port >= USB_IP_NUM)
		ASSERT(0);

	if (common_str.usb_ip_port < USB_EXT_IP_NUM)
	{
		if(((usb_ep_str.direction == USB_EP_TX_DIR)&&(usb_ep_str.ep_num > MAX_TX_EP_NUM))||
			((usb_ep_str.direction == USB_EP_RX_DIR)&&(usb_ep_str.ep_num > MAX_RX_EP_NUM)))
			EXT_ASSERT(0, usb_ep_str.ep_num, (kal_uint32)usb_ep_str.direction, 0);
	}
#if defined(__IC_USB_ENABLE__)	
	else
	{
		if(((usb_ep_str.direction == USB_EP_TX_DIR)&&(usb_ep_str.ep_num > ICUSB_MAX_TX_EP_NUM))||
			((usb_ep_str.direction == USB_EP_RX_DIR)&&(usb_ep_str.ep_num > ICUSB_MAX_RX_EP_NUM)))
			EXT_ASSERT(0, usb_ep_str.ep_num, (kal_uint32)usb_ep_str.direction, 0);
	}
#endif

	if(usb_ep_str.ep_num == 0)
	{
		g_UsbHcdInfo[common_str.usb_ip_port].ep0_info.max_packet_size = usb_ep_str.ep_max_pkt_size;

		if(usb_ep_str.ep_max_pkt_size > USB_EP0_MAXP)
			EXT_ASSERT(0, usb_ep_str.ep_max_pkt_size, 0, 0);
	}
	else
	{
		if(usb_ep_str.direction == USB_EP_TX_DIR)
		{
			g_UsbHcdInfo[common_str.usb_ip_port].ep_tx_info[usb_ep_str.ep_num-1].max_packet_size = usb_ep_str.ep_max_pkt_size;		//lint !e661
			ep_type = g_UsbHcdInfo[common_str.usb_ip_port].ep_tx_info[usb_ep_str.ep_num-1].ep_type;					//lint !e661
		}
		else
		{
			g_UsbHcdInfo[common_str.usb_ip_port].ep_rx_info[usb_ep_str.ep_num-1].max_packet_size = usb_ep_str.ep_max_pkt_size;		//lint !e661 !e662
			ep_type = g_UsbHcdInfo[common_str.usb_ip_port].ep_rx_info[usb_ep_str.ep_num-1].ep_type;					//lint !e661 !e662
		}

		if(ep_type == USB_ENDPT_BULK)
		{
			if(USB_HCD_Is_High_Speed(common_str.usb_ip_port) == KAL_TRUE)
			{
				if (usb_ep_str.ep_max_pkt_size > USB_EP_BULK_MAXP_HS)
					EXT_ASSERT(0, usb_ep_str.ep_max_pkt_size, 0, 0);
			}
			else
			{
				if (usb_ep_str.ep_max_pkt_size >USB_EP_BULK_MAXP_FS)
					EXT_ASSERT(0, usb_ep_str.ep_max_pkt_size, 0, 0);
			}
		}
		else if (ep_type == USB_ENDPT_INTR)
		{

		}
		else if (ep_type == USB_ENDPT_ISO)
		{

		}
		else
		{
			ASSERT(0);
		}
	}
	return STATUS_OK;

}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Clear_Data01(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_EP_CTRL_FUNC_1_T *prep_ctrl_func_1;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;
	kal_uint32 savedMask;
		
	prep_ctrl_func_1 = &data->rHCD_EP_Ctrl_Func_1;
	
	common_str.if_num = (kal_uint32)prep_ctrl_func_1->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep_ctrl_func_1->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep_ctrl_func_1->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep_ctrl_func_1->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep_ctrl_func_1->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep_ctrl_func_1->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep_ctrl_func_1->usb_ep_str.direction;	
	
/* May run in task */
	if (common_str.usb_ip_port >= USB_IP_NUM)
		ASSERT(0);
	

	if(usb_ep_str.ep_num == 0)
	{
		ASSERT(0);
	}
	else
	{
		savedMask = SaveAndSetIRQMask();
		USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[common_str.usb_ip_port]), usb_ep_str.ep_num);

		if(usb_ep_str.direction == USB_EP_TX_DIR)
		{
			if((USB_DRV_Reg(USB_TXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]))&USB_TXCSR_FIFONOTEMPTY) != 0)
				g_UsbHcdInfo[common_str.usb_ip_port].ep_tx_flush_intr[usb_ep_str.ep_num-1] = KAL_TRUE;

			USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]), 0x00);
			USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]), (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
			USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]), (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
		}
		else
		{
			if((USB_DRV_Reg(USB_RXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]))&USB_RXCSR_RXPKTRDY) != 0)
				g_UsbHcdInfo[common_str.usb_ip_port].ep_rx_flush_intr[usb_ep_str.ep_num-1] = KAL_TRUE;

			USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]), 0x00);
			USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]), (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
			USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]), (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
		}
		RestoreIRQMask(savedMask);
	}

	return STATUS_OK;
}

DCL_STATUS DCL_USB_CTRL_API_USB_HCD_EP_Interval(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_EP_CTRL_FUNC_2_T *prep_ctrl_func_2;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;
	kal_uint8	interval;

	prep_ctrl_func_2 = &data->rHCD_EP_Ctrl_Func_2;

	common_str.if_num = (kal_uint32)prep_ctrl_func_2->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep_ctrl_func_2->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep_ctrl_func_2->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep_ctrl_func_2->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep_ctrl_func_2->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep_ctrl_func_2->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep_ctrl_func_2->usb_ep_str.direction;		
	
	interval = (kal_uint8)prep_ctrl_func_2->interval;

	USB_HCD_EP_Interval(common_str,usb_ep_str,interval);

	return STATUS_OK;
}



DCL_STATUS DCL_USB_CTRL_API_USB_HCD_EP0En(DCL_CTRL_DATA_T *data)
{
	kal_uint32 savedMask;
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
	kal_uint8	usb_ip_port;
	
	usb_ip = &data->rHCD_ip;
	usb_ip_port = (kal_uint8)usb_ip->ip;

	
/* May run in task */
	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);

	g_UsbHcdInfo[usb_ip_port].ep0_info.b_enable = KAL_TRUE;
	g_UsbHcdInfo[usb_ip_port].ep0_info.ep_type = USB_ENDPT_CTRL;

	savedMask = SaveAndSetIRQMask();
	/* Enable ep0 */
	USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), 0);
	/* Flush ep0 FIFO */
	USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), USB_CSR0_FLUSHFIFO);
	/* Enable EP0 interrupt */
	USB_DRV_SetBits(USB_INTRTXE_HCD(USB_BaseAddr[usb_ip_port]), USB_INTRE_EPEN);
	RestoreIRQMask(savedMask);
	
	return STATUS_OK;
}

DCL_STATUS DCL_USB_CTRL_API_USB_HCD_EP0_Data_Length(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_EP_CTRL_FUNC_3_T *prep_ctrl_func_3;
	USBH_Common_Struct common_str;

	prep_ctrl_func_3 = &data->rHCD_EP_Ctrl_Func_3;

	common_str.if_num = (kal_uint32)prep_ctrl_func_3->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep_ctrl_func_3->common_str.usb_ip_port;		

	prep_ctrl_func_3->return_value = g_UsbHcdInfo[common_str.usb_ip_port].ep0_info.sofar;
	
	return STATUS_OK;	
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_EP_Rx_Pkt_Len(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_EP_CTRL_FUNC_4_T *prep_ctrl_func_4;
//	kal_uint32 savedMask;
//	kal_uint16 CSR;
//	kal_uint32 nCount = 0;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;
	
	prep_ctrl_func_4 = &data->rHCD_EP_Ctrl_Func_4;
	
	common_str.if_num = (kal_uint32)prep_ctrl_func_4->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep_ctrl_func_4->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep_ctrl_func_4->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep_ctrl_func_4->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep_ctrl_func_4->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep_ctrl_func_4->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep_ctrl_func_4->usb_ep_str.direction;	
	
	
/* Return ep RX received packet length */
	prep_ctrl_func_4->return_value = USB_HCD_EP_Rx_Pkt_Len(common_str,usb_ep_str);

	return STATUS_OK;

}



DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Config_TxEP_Type(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_EP_CTRL_FUNC_5_T *prep_ctrl_func_5;
	USBH_Common_Struct 	common_str;
	USBH_EP_Struct 	usb_ep_str;
	kal_bool 	b_is_switch_to_dma;
	kal_uint32 savedMask;
	kal_uint8 usb_ip_port;
	kal_uint8 ep_num ;

	prep_ctrl_func_5 = &data->rHCD_EP_Ctrl_Func_5;

	common_str.if_num = (kal_uint32)prep_ctrl_func_5->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep_ctrl_func_5->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep_ctrl_func_5->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep_ctrl_func_5->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep_ctrl_func_5->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep_ctrl_func_5->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep_ctrl_func_5->usb_ep_str.direction;		
	
	b_is_switch_to_dma = (kal_bool)prep_ctrl_func_5->set;
	usb_ip_port = (kal_uint8)common_str.usb_ip_port;
	ep_num = (kal_uint8)usb_ep_str.ep_num;


	USB_HCD_EP_Check(usb_ip_port,ep_num, USB_EP_TX_DIR, 0);
	USB_HCD_EP_DMA_Running_Check(usb_ip_port,ep_num, USB_EP_TX_DIR, 0);

	g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].b_enable = KAL_TRUE;
	g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].b_dma_enable = b_is_switch_to_dma;
	

	if(b_is_switch_to_dma == KAL_TRUE)
	{
		if(g_UsbHcdInfo[usb_ip_port].ep_tx_enb_state[ep_num-1] == USB_EP_STATE_DMA)
			ASSERT(0);

		g_UsbHcdInfo[usb_ip_port].ep_tx_enb_state[ep_num-1] = USB_EP_STATE_DMA;

		savedMask = SaveAndSetIRQMask();
		USB_DRV_ClearBits(USB_INTRTXE_HCD(USB_BaseAddr[usb_ip_port]), (USB_INTRE_EPEN<<ep_num));
		USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);

		if(USB_DRV_Reg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]))&USB_TXCSR_FIFONOTEMPTY)
			ASSERT(0);

		/* Only is configured as multiple packet DMA TX mode */
		USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_TX_CSR);
		RestoreIRQMask(savedMask);
	}
	else
	{
		if(g_UsbHcdInfo[usb_ip_port].ep_tx_enb_state[ep_num-1] == USB_EP_STATE_FIFO)
			ASSERT(0);

		g_UsbHcdInfo[usb_ip_port].ep_tx_enb_state[ep_num-1] = USB_EP_STATE_FIFO;

		savedMask = SaveAndSetIRQMask();
		USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);

		/* When change ep state from DMA to FIFO, must make sure that FIFO is empty */
		if(USB_DRV_Reg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]))&USB_TXCSR_TXPKTRDY)
			ASSERT(0);

		USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), 0x00);
		USB_DRV_SetBits(USB_INTRTXE_HCD(USB_BaseAddr[usb_ip_port]), (USB_INTRE_EPEN<<ep_num));
		RestoreIRQMask(savedMask);
	}
	
	return STATUS_OK;

}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Config_RxEP_Type(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_EP_CTRL_FUNC_5_T *prep_ctrl_func_5;
	USBH_Common_Struct	common_str;
	USBH_EP_Struct	usb_ep_str;
	kal_bool	b_is_switch_to_dma;
	kal_uint32 savedMask;

	prep_ctrl_func_5 = &data->rHCD_EP_Ctrl_Func_5;

	common_str.if_num = (kal_uint32)prep_ctrl_func_5->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep_ctrl_func_5->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep_ctrl_func_5->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep_ctrl_func_5->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep_ctrl_func_5->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep_ctrl_func_5->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep_ctrl_func_5->usb_ep_str.direction;		
	
	b_is_switch_to_dma = (kal_bool)prep_ctrl_func_5->set;



/* When RX EP state is from FIFO to DMA, this function must be called before USB_EP_Bulk_Rx_Ready() */
	USB_HCD_EP_Check(common_str.usb_ip_port,usb_ep_str.ep_num, USB_EP_RX_DIR, 0);
	USB_HCD_EP_DMA_Running_Check(common_str.usb_ip_port,usb_ep_str.ep_num, USB_EP_RX_DIR, 0);

	g_UsbHcdInfo[common_str.usb_ip_port].ep_rx_info[usb_ep_str.ep_num-1].b_enable = KAL_TRUE;
	g_UsbHcdInfo[common_str.usb_ip_port].ep_rx_info[usb_ep_str.ep_num-1].b_dma_enable = b_is_switch_to_dma;
	
	if(b_is_switch_to_dma == KAL_TRUE)
	{
		if(g_UsbHcdInfo[common_str.usb_ip_port].ep_rx_enb_state[usb_ep_str.ep_num-1] == USB_EP_STATE_DMA)
			ASSERT(0);

		g_UsbHcdInfo[common_str.usb_ip_port].ep_rx_enb_state[usb_ep_str.ep_num-1] = USB_EP_STATE_DMA;
		savedMask = SaveAndSetIRQMask();
		USB_DRV_ClearBits(USB_INTRRXE_HCD(USB_BaseAddr[common_str.usb_ip_port]), (USB_INTRE_EPEN << usb_ep_str.ep_num));
		USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[common_str.usb_ip_port]), usb_ep_str.ep_num);
		USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]), USB_HCD_DMA_RX_CSR|USB_RXCSR_RXPKTRDY);		

		RestoreIRQMask(savedMask);
	}
	else
	{
		if(g_UsbHcdInfo[common_str.usb_ip_port].ep_rx_enb_state[usb_ep_str.ep_num-1] == USB_EP_STATE_FIFO)
			ASSERT(0);

		g_UsbHcdInfo[common_str.usb_ip_port].ep_rx_enb_state[usb_ep_str.ep_num-1] = USB_EP_STATE_FIFO;

		savedMask = SaveAndSetIRQMask();
		USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[common_str.usb_ip_port]), usb_ep_str.ep_num);

		/* When we change ep state from DMA to FIFO, must make sure that FIFO is empty */
		/* But there may be a null packet coming here in DMA callback */
		if(USB_DRV_Reg(USB_RXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]))&USB_RXCSR_RXPKTRDY)
		{
			if(USB_DRV_Reg(USB_RXCOUNT_HCD(USB_BaseAddr[common_str.usb_ip_port])) == 0)
			{
				USB_DRV_ClearBits(USB_RXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]), USB_RXCSR_RXPKTRDY);
			}
			else
				ASSERT(0);
		}

		USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]), USB_RXCSR_RXPKTRDY);
		USB_DRV_SetBits(USB_INTRRXE_HCD(USB_BaseAddr[common_str.usb_ip_port]), (USB_INTRE_EPEN << usb_ep_str.ep_num));
		RestoreIRQMask(savedMask);
	}
	
	return STATUS_OK;
	
}

DCL_STATUS DCL_USB_CTRL_API_USB_HCD_TxEPInit(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_EP_CTRL_FUNC_1_T *prep_ctrl_func_1;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;
	kal_uint8 usb_ip_port ;
	kal_uint8 ep_num;
	kal_uint8 ep_header;
	kal_uint16 data_size;
	USB_ENDPT_TXFER_TYPE type;
	kal_bool double_fifo;
	
	prep_ctrl_func_1 = &data->rHCD_EP_Ctrl_Func_1;
	
	common_str.if_num = (kal_uint32)prep_ctrl_func_1->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep_ctrl_func_1->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep_ctrl_func_1->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep_ctrl_func_1->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep_ctrl_func_1->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep_ctrl_func_1->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep_ctrl_func_1->usb_ep_str.direction;	
	usb_ip_port = (kal_uint8)common_str.usb_ip_port;
	
	ep_num = (kal_uint8)usb_ep_str.ep_num;
	ep_header = (kal_uint8)usb_ep_str.ep_real_num;
	data_size = (kal_uint16)usb_ep_str.ep_max_pkt_size;
	type = (USB_ENDPT_TXFER_TYPE)usb_ep_str.ep_type;

	double_fifo = USB_HCD_Is_DoubleFIFO_SUPPORT(usb_ip_port);

/* Run in HISR */
	if ((usb_ip_port >= USB_EXT_IP_NUM) && (type != USB_ENDPT_BULK))
		ASSERT(0);

	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);


	USB_HCD_EP_Check(usb_ip_port,ep_num, USB_EP_TX_DIR, 0);
	USB_HCD_EP_DMA_Running_Check(usb_ip_port,ep_num, USB_EP_TX_DIR, 0);

	g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].ep_type = type;
	g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].direction = USB_EP_TX_DIR;

	USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);
	/* double buffers, so flush twice */
	USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), 0x00);
	USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
	USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
	USB_DRV_WriteReg(USB_TXMAXP_HCD(USB_BaseAddr[usb_ip_port]), data_size);

	/* Set FIFO address here */
	if(type == USB_ENDPT_BULK)
	{
		USB_DRV_WriteReg8(USB_TXTYPE_HCD(USB_BaseAddr[usb_ip_port]), USB_TXTYPE_BULK|ep_header);
		if (usb_ip_port < USB_EXT_IP_NUM)
		{
			if(double_fifo == KAL_TRUE)
			{
				USB_DRV_WriteReg8(USB_TXFIFOSZ_HCD(USB_BaseAddr[usb_ip_port]), (USB_FIFOSZ_SIZE_512|USB_FIFOSZ_DPB));
				USB_DRV_WriteReg(USB_TXFIFOADD_HCD(USB_BaseAddr[usb_ip_port]), (g_HCD_FIFOadd/8));
				g_HCD_FIFOadd += USB_BULK_FIFO_UNIT_SIZE*2;
			}
			else
			{
				USB_DRV_WriteReg8(USB_TXFIFOSZ_HCD(USB_BaseAddr[usb_ip_port]), USB_FIFOSZ_SIZE_512);
				USB_DRV_WriteReg(USB_TXFIFOADD_HCD(USB_BaseAddr[usb_ip_port]), (g_HCD_FIFOadd/8));
				g_HCD_FIFOadd += USB_BULK_FIFO_UNIT_SIZE;
			
			}
		}
#if defined(__IC_USB_ENABLE__)		
		else
		{
			USB_DRV_WriteReg8(USB_TXFIFOSZ_HCD(USB_BaseAddr[usb_ip_port]), (USB_FIFOSZ_SIZE_64|USB_FIFOSZ_DPB));
			USB_DRV_WriteReg(USB_TXFIFOADD_HCD(USB_BaseAddr[usb_ip_port]), (g_HCD_FIFOadd/8));
			g_HCD_FIFOadd +=  ICUSB_BULK_FIFO_UNIT_SIZE*2;
		}
#endif		
	}
	else if (type == USB_ENDPT_INTR)
	{
		USB_DRV_WriteReg8(USB_TXTYPE_HCD(USB_BaseAddr[usb_ip_port]), USB_TXTYPE_INTR|ep_header);

		if(data_size > 64)
			ASSERT(0);

#ifdef  __INTR_HB__
		USB_DRV_WriteReg8(USB_TXFIFOSZ_HCD(USB_BaseAddr[usb_ip_port]), USB_FIFOSZ_SIZE_4096);
		USB_DRV_WriteReg(USB_TXFIFOADD_HCD(USB_BaseAddr[usb_ip_port]), (g_HCD_FIFOadd/8));
		g_HCD_FIFOadd += USB_INTR_FIFO_UNIT_SIZE;
#else		
		if(double_fifo == KAL_TRUE)
		{
			USB_DRV_WriteReg8(USB_TXFIFOSZ_HCD(USB_BaseAddr[usb_ip_port]), (USB_FIFOSZ_SIZE_32|USB_FIFOSZ_DPB));
			USB_DRV_WriteReg(USB_TXFIFOADD_HCD(USB_BaseAddr[usb_ip_port]), (g_HCD_FIFOadd/8));
			g_HCD_FIFOadd += USB_INTR_FIFO_UNIT_SIZE*2;
		
		}
		else
		{
			USB_DRV_WriteReg8(USB_TXFIFOSZ_HCD(USB_BaseAddr[usb_ip_port]), USB_FIFOSZ_SIZE_32);
			USB_DRV_WriteReg(USB_TXFIFOADD_HCD(USB_BaseAddr[usb_ip_port]), (g_HCD_FIFOadd/8));
			g_HCD_FIFOadd += USB_INTR_FIFO_UNIT_SIZE;
		}
#endif		
	}
	else if (type == USB_ENDPT_ISO)
	{
		USB_DRV_WriteReg8(USB_TXTYPE_HCD(USB_BaseAddr[usb_ip_port]), USB_TXTYPE_ISO|ep_header);

		if(data_size > 512)
			ASSERT(0);

#ifdef  __ISO_HB__
		USB_DRV_WriteReg8(USB_TXFIFOSZ_HCD(USB_BaseAddr[usb_ip_port]), USB_FIFOSZ_SIZE_4096);
		USB_DRV_WriteReg(USB_TXFIFOADD_HCD(USB_BaseAddr[usb_ip_port]), (g_HCD_FIFOadd/8));
		g_HCD_FIFOadd += USB_ISO_FIFO_UNIT_SIZE;
#else
		if(double_fifo == KAL_TRUE)
		{		
			USB_DRV_WriteReg8(USB_TXFIFOSZ_HCD(USB_BaseAddr[usb_ip_port]), (USB_FIFOSZ_SIZE_1024|USB_FIFOSZ_DPB));
			USB_DRV_WriteReg(USB_TXFIFOADD_HCD(USB_BaseAddr[usb_ip_port]), (g_HCD_FIFOadd/8));
			g_HCD_FIFOadd += USB_ISO_FIFO_UNIT_SIZE*2;
		}
		else
		{
			USB_DRV_WriteReg8(USB_TXFIFOSZ_HCD(USB_BaseAddr[usb_ip_port]), USB_FIFOSZ_SIZE_1024);
			USB_DRV_WriteReg(USB_TXFIFOADD_HCD(USB_BaseAddr[usb_ip_port]), (g_HCD_FIFOadd/8));
			g_HCD_FIFOadd += USB_ISO_FIFO_UNIT_SIZE;
		}
#endif		
	}
	else
	{
		ASSERT(0);
	}

	if (usb_ip_port < USB_EXT_IP_NUM)
	{	
		if(g_HCD_FIFOadd > USB_MAX_FIFO_SIZE)
			ASSERT(0);
	}
#if defined(__IC_USB_ENABLE__)	
	else
	{
		if(g_HCD_FIFOadd > ICUSB_MAX_FIFO_SIZE)
			ASSERT(0);
	}
#endif	

	return STATUS_OK;
}

DCL_STATUS DCL_USB_CTRL_API_USB_HCD_RxEPInit(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_EP_CTRL_FUNC_1_T *prep_ctrl_func_1;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;
	kal_uint8 usb_ip_port ;
	kal_uint8 ep_num;
	kal_uint8 ep_header;
	kal_uint16 data_size;
	USB_ENDPT_TXFER_TYPE type;
	kal_bool double_fifo;
	
	prep_ctrl_func_1 = &data->rHCD_EP_Ctrl_Func_1;
	
	common_str.if_num = (kal_uint32)prep_ctrl_func_1->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep_ctrl_func_1->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep_ctrl_func_1->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep_ctrl_func_1->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep_ctrl_func_1->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep_ctrl_func_1->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep_ctrl_func_1->usb_ep_str.direction;		
	
	usb_ip_port = (kal_uint8)common_str.usb_ip_port;
	ep_num = (kal_uint8)usb_ep_str.ep_num;
	ep_header = (kal_uint8)usb_ep_str.ep_real_num;
	data_size = (kal_uint16)usb_ep_str.ep_max_pkt_size;
	type = (USB_ENDPT_TXFER_TYPE)usb_ep_str.ep_type;

	double_fifo = USB_HCD_Is_DoubleFIFO_SUPPORT(usb_ip_port);

/* run in HISR */
/* initialize EP RX */


	if ((usb_ip_port >= USB_EXT_IP_NUM) && (type != USB_ENDPT_BULK))
		ASSERT(0);

	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);
		
		
	
	USB_HCD_EP_Check(usb_ip_port,ep_num, USB_EP_RX_DIR, 0);
	USB_HCD_EP_DMA_Running_Check(usb_ip_port,ep_num, USB_EP_RX_DIR, 0);

	g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].ep_type = type;
	g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].direction = USB_EP_RX_DIR;

	USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);
	USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), 0x00);
	USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
	USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
	USB_DRV_WriteReg(USB_RXMAXP_HCD(USB_BaseAddr[usb_ip_port]), data_size);

	/* set FIFO address here */
	if(type == USB_ENDPT_BULK)
	{
		USB_DRV_WriteReg8(USB_RXTYPE_HCD(USB_BaseAddr[usb_ip_port]), (USB_RXTYPE_BULK|ep_header));
		if (usb_ip_port < USB_EXT_IP_NUM)
		{
			if(double_fifo == KAL_TRUE)
			{
				USB_DRV_WriteReg8(USB_RXFIFOSZ_HCD(USB_BaseAddr[usb_ip_port]), (USB_FIFOSZ_SIZE_512|USB_FIFOSZ_DPB));
				USB_DRV_WriteReg(USB_RXFIFOADD_HCD(USB_BaseAddr[usb_ip_port]), (g_HCD_FIFOadd/8));
				g_HCD_FIFOadd += USB_BULK_FIFO_UNIT_SIZE*2;
			}
			else
			{
				USB_DRV_WriteReg8(USB_RXFIFOSZ_HCD(USB_BaseAddr[usb_ip_port]), USB_FIFOSZ_SIZE_512);
				USB_DRV_WriteReg(USB_RXFIFOADD_HCD(USB_BaseAddr[usb_ip_port]), (g_HCD_FIFOadd/8));
				g_HCD_FIFOadd += USB_BULK_FIFO_UNIT_SIZE;			
			}
		}
#if defined(__IC_USB_ENABLE__)		
		else
		{
			USB_DRV_WriteReg8(USB_RXFIFOSZ_HCD(USB_BaseAddr[usb_ip_port]), (USB_FIFOSZ_SIZE_64|USB_FIFOSZ_DPB));
			USB_DRV_WriteReg(USB_RXFIFOADD_HCD(USB_BaseAddr[usb_ip_port]), (g_HCD_FIFOadd/8));
			g_HCD_FIFOadd +=  ICUSB_BULK_FIFO_UNIT_SIZE*2 ;
		}
#endif		
	}
	else if(type == USB_ENDPT_INTR)
	{
		USB_DRV_WriteReg8(USB_RXTYPE_HCD(USB_BaseAddr[usb_ip_port]), (USB_RXTYPE_INTR|ep_header));

#ifdef  __INTR_HB__
		USB_DRV_WriteReg8(USB_RXFIFOSZ_HCD(USB_BaseAddr[usb_ip_port]), USB_FIFOSZ_SIZE_4096);
		USB_DRV_WriteReg(USB_RXFIFOADD_HCD(USB_BaseAddr[usb_ip_port]), (g_HCD_FIFOadd/8));
		g_HCD_FIFOadd += USB_INTR_FIFO_UNIT_SIZE;
#else
		if(double_fifo == KAL_TRUE)
		{
			USB_DRV_WriteReg8(USB_RXFIFOSZ_HCD(USB_BaseAddr[usb_ip_port]), (USB_FIFOSZ_SIZE_32|USB_FIFOSZ_DPB));
			USB_DRV_WriteReg(USB_RXFIFOADD_HCD(USB_BaseAddr[usb_ip_port]), (g_HCD_FIFOadd/8));
			g_HCD_FIFOadd += USB_INTR_FIFO_UNIT_SIZE*2;
		}
		else
		{
			USB_DRV_WriteReg8(USB_RXFIFOSZ_HCD(USB_BaseAddr[usb_ip_port]), USB_FIFOSZ_SIZE_32);
			USB_DRV_WriteReg(USB_RXFIFOADD_HCD(USB_BaseAddr[usb_ip_port]), (g_HCD_FIFOadd/8));
			g_HCD_FIFOadd += USB_INTR_FIFO_UNIT_SIZE;
		}
#endif
	}
	else if(type == USB_ENDPT_ISO)
	{
		USB_DRV_WriteReg8(USB_RXTYPE_HCD(USB_BaseAddr[usb_ip_port]), (USB_RXTYPE_ISO|ep_header));

#ifdef  __ISO_HB__
		USB_DRV_WriteReg8(USB_RXFIFOSZ_HCD(USB_BaseAddr[usb_ip_port]), USB_FIFOSZ_SIZE_4096);
		USB_DRV_WriteReg(USB_RXFIFOADD_HCD(USB_BaseAddr[usb_ip_port]), (g_HCD_FIFOadd/8));
		g_HCD_FIFOadd += USB_ISO_FIFO_UNIT_SIZE;
#else
		if(double_fifo == KAL_TRUE)
		{
			USB_DRV_WriteReg8(USB_RXFIFOSZ_HCD(USB_BaseAddr[usb_ip_port]), (USB_FIFOSZ_SIZE_1024|USB_FIFOSZ_DPB));
			USB_DRV_WriteReg(USB_RXFIFOADD_HCD(USB_BaseAddr[usb_ip_port]), (g_HCD_FIFOadd/8));
			g_HCD_FIFOadd += USB_ISO_FIFO_UNIT_SIZE*2;
		}
		else
		{
			USB_DRV_WriteReg8(USB_RXFIFOSZ_HCD(USB_BaseAddr[usb_ip_port]), USB_FIFOSZ_SIZE_1024);
			USB_DRV_WriteReg(USB_RXFIFOADD_HCD(USB_BaseAddr[usb_ip_port]), (g_HCD_FIFOadd/8));
			g_HCD_FIFOadd += USB_ISO_FIFO_UNIT_SIZE;
		}
#endif
	}
	else
	{
		ASSERT(0);
	}

	if (usb_ip_port < USB_EXT_IP_NUM)
	{	
		if(g_HCD_FIFOadd > USB_MAX_FIFO_SIZE)
			ASSERT(0);
	}
#if defined(__IC_USB_ENABLE__)	
	else
	{
		if(g_HCD_FIFOadd > ICUSB_MAX_FIFO_SIZE)
			ASSERT(0);
	}
#endif

	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_TxEPEn(DCL_CTRL_DATA_T *data)
{
	kal_uint32 savedMask;

	USB_HCD_CTRL_EP_ENABLE_T *prep_enable;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;
	kal_uint8 interval;
	kal_bool bDMA;
	kal_bool bDMAQ;	
	kal_uint8 usb_ip_port;
	kal_uint8 ep_num;
	USB_ENDPT_TXFER_TYPE ep_type;

	prep_enable = &data->rHCD_EP_Enable;
	
	common_str.if_num = (kal_uint32)prep_enable->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep_enable->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep_enable->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep_enable->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep_enable->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep_enable->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep_enable->usb_ep_str.direction;		
	
	interval= (kal_uint8)prep_enable->u1interval;
	bDMA = (kal_bool)prep_enable->fgbDMA;
	bDMAQ = (kal_bool)prep_enable->fgbDMAQ;	
	usb_ip_port= (kal_uint8)common_str.usb_ip_port;
	ep_num = (kal_uint8)usb_ep_str.ep_num;
	ep_type = (USB_ENDPT_TXFER_TYPE)usb_ep_str.ep_type;


	if ((bDMA == KAL_TRUE) & (bDMAQ == KAL_TRUE))
		ASSERT(0);

	
/* Run in HISR */
	USB_HCD_EP_Check(usb_ip_port,ep_num, USB_EP_TX_DIR, 0);
	USB_HCD_EP_DMA_Running_Check(usb_ip_port,ep_num, USB_EP_TX_DIR, 0);

	g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].b_enable = KAL_TRUE;
	g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].b_dma_enable = bDMA;
	g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].b_dmaQ_enable = bDMAQ;


	savedMask = SaveAndSetIRQMask();

	USB_DRV_SetBits(USB_INTRTXE_HCD(USB_BaseAddr[usb_ip_port]), (USB_INTRE_EPEN<<ep_num));

	USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);

	if(USB_HCD_Is_High_Speed(usb_ip_port) == KAL_TRUE)
	{
		USB_DRV_WriteReg8(USB_TXINTERVAL_HCD(USB_BaseAddr[usb_ip_port]), interval);
	}
	else
	{
		USB_DRV_WriteReg8(USB_TXINTERVAL_HCD(USB_BaseAddr[usb_ip_port]), interval-3);
	}

	if(bDMA == KAL_TRUE)
	{
//		USB_DRV_ClearBits(USB_INTRTXE, (USB_INTRE_EPEN<<ep_num));

		/* Double buffers, so flush twice */
		if((USB_DRV_Reg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]))&USB_TXCSR_FIFONOTEMPTY) != 0)
			g_UsbHcdInfo[usb_ip_port].ep_tx_flush_intr[ep_num-1] = KAL_TRUE;

		USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), 0x00);
		USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
		USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));

		/* Only is configured as multiple packet DMA TX mode */
		if(ep_type == USB_ENDPT_ISO)
		{
			USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_TX_CSR_ISO);
		}
		else
		{
			USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_TX_CSR);
		}
	}
#if (defined(DRV_USB_IP_V4))  //Unit IP
	else if(bDMAQ == KAL_TRUE)
	{
		DRV_WriteReg32(USB_DMAQ_QISAR, 0xFFFFFFFF); //write 1 clear	
		DRV_WriteReg32(USB_DMAQ_TQEIR, USB_DMAQ_QIMCR0 <<(ep_num-1));
		DRV_WriteReg32(USB_DMAQ_TQEMIMCR, USB_DMAQ_QIMCR0 <<(ep_num-1));
		DRV_WriteReg32(USB_DMAQ_TQEIR, USB_DMAQ_QIMCR0 <<(ep_num-1));		
		DRV_WriteReg32(USB_DMAQ_TQEIMCR, USB_DMAQ_QIMCR0 <<(ep_num-1));
		DRV_WriteReg32(USB_DMAQ_TEPEIR, USB_DMAQ_QIMCR0 <<(ep_num-1));		
		DRV_WriteReg32(USB_DMAQ_TEPEIMCR, USB_DMAQ_QIMCR0 <<(ep_num-1));
		DRV_WriteReg32(USB_DMAQ_QIMCR, USB_DMAQ_QIMCR_TX_DONE(ep_num-1)|USB_DMAQ_QIMCR_TXEP_ERR|USB_DMAQ_QIMCR_TXQ_ERR|USB_DMAQ_QIMCR_TXQ_EMPTY);	
	}
#endif	
	else // FIFO
	{
		/* double buffers, so flush twice */
		if((USB_DRV_Reg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]))&USB_TXCSR_FIFONOTEMPTY) != 0)
			g_UsbHcdInfo[usb_ip_port].ep_tx_flush_intr[ep_num-1] = KAL_TRUE;

		USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), 0x00);
		USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
		USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));

//		USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), 0x00);
//		USB_DRV_SetBits(USB_INTRTXE, (USB_INTRE_EPEN<<ep_num));
	}

	RestoreIRQMask(savedMask);

	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_RxEPEn(DCL_CTRL_DATA_T *data)
{
	kal_uint32 savedMask;
	USB_HCD_CTRL_EP_ENABLE_T *prep_enable;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;
	kal_uint8 interval;
	kal_bool bDMA;
	kal_bool bDMAQ;		
	kal_uint8 usb_ip_port;
	kal_uint8 ep_num;
	USB_ENDPT_TXFER_TYPE ep_type;

	prep_enable = &data->rHCD_EP_Enable;
	
	common_str.if_num = (kal_uint32)prep_enable->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep_enable->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep_enable->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep_enable->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep_enable->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep_enable->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep_enable->usb_ep_str.direction;	
		
	interval = (kal_uint8)prep_enable->u1interval;
	bDMA = (kal_bool)prep_enable->fgbDMA;
	bDMAQ = (kal_bool)prep_enable->fgbDMAQ;		
	usb_ip_port = (kal_uint8)common_str.usb_ip_port;
	ep_num = (kal_uint8)usb_ep_str.ep_num;
	ep_type = (USB_ENDPT_TXFER_TYPE)usb_ep_str.ep_type;


	if ((bDMA == KAL_TRUE) & (bDMAQ == KAL_TRUE))
		ASSERT(0);


/* Run in HISR */
	
	USB_HCD_EP_Check(usb_ip_port,ep_num, USB_EP_RX_DIR, 0);
	USB_HCD_EP_DMA_Running_Check(usb_ip_port,ep_num, USB_EP_RX_DIR, 0);

	g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].b_enable = KAL_TRUE;
	g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].b_dma_enable = bDMA;
	g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].b_dmaQ_enable = bDMAQ;

	savedMask = SaveAndSetIRQMask();

	USB_DRV_SetBits(USB_INTRRXE_HCD(USB_BaseAddr[usb_ip_port]), (USB_INTRE_EPEN<<ep_num));

	USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);

	if(USB_HCD_Is_High_Speed(usb_ip_port) == KAL_TRUE)
	{
		USB_DRV_WriteReg8(USB_RXINTERVAL_HCD(USB_BaseAddr[usb_ip_port]), interval);
	}
	else
	{
		USB_DRV_WriteReg8(USB_RXINTERVAL_HCD(USB_BaseAddr[usb_ip_port]), interval-3);
	}

	if(bDMA == KAL_TRUE)
	{
//		USB_DRV_ClearBits(USB_INTRRXE_HCD(USB_BaseAddr[usb_ip_port]), (USB_INTRE_EPEN<<ep_num));

		/* maybe double buffer, so flush twice */
		if((USB_DRV_Reg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]))&USB_RXCSR_RXPKTRDY) != 0)
			g_UsbHcdInfo[usb_ip_port].ep_rx_flush_intr[ep_num-1] = KAL_TRUE;

		USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), 0x00);
		USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
		USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));

		if(ep_type == USB_ENDPT_ISO)
		{
			USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_RX_CSR_ISO);
		}
		else
		{
			USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_HCD_DMA_RX_CSR);
		}

		if((g_UsbHcdInfo[usb_ip_port].dma_gpt_handle[ep_num-1] == 0)||(g_UsbHcdInfo[usb_ip_port].dma_gpt_handle[ep_num-1] == 0x7F))
			g_UsbHcdInfo[usb_ip_port].dma_gpt_handle[ep_num-1] = DclSGPT_Open(DCL_GPT_CB, 0);
//			GPTI_GetHandle(&g_UsbHcdInfo[usb_ip_port].dma_gpt_handle[ep_num-1]);
	}
#if (defined(DRV_USB_IP_V4))  //Unit IP
	else if(bDMAQ == KAL_TRUE)
	{
		DRV_WriteReg32(USB_DMAQ_QISAR, 0xFFFFFFFF); //write 1 clear		
		DRV_WriteReg32(USB_DMAQ_RQEIR, USB_DMAQ_QIMCR0 <<(ep_num-1));
		DRV_WriteReg32(USB_DMAQ_RQEMIMCR, USB_DMAQ_QIMCR0 <<(ep_num-1));
		DRV_WriteReg32(USB_DMAQ_RQEIR, USB_DMAQ_QIMCR0 <<(ep_num-1));		
		DRV_WriteReg32(USB_DMAQ_RQEIMCR, USB_DMAQ_QIMCR0<<(ep_num-1));
		DRV_WriteReg32(USB_DMAQ_REPEIR, USB_DMAQ_QIMCR0 <<(ep_num-1));		
		DRV_WriteReg32(USB_DMAQ_REPEIMCR, USB_DMAQ_QIMCR0 <<(ep_num-1));
		DRV_WriteReg32(USB_DMAQ_QIMCR, USB_DMAQ_QIMCR_RX_DONE(ep_num-1)|USB_DMAQ_QIMCR_RXEP_ERR|USB_DMAQ_QIMCR_RXQ_ERR|USB_DMAQ_QIMCR_RXQ_EMPTY);
	}
#endif	
	else // FIFO
	{
		/* Maybe double buffer, so flush twice */
		if((USB_DRV_Reg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]))&USB_RXCSR_RXPKTRDY) != 0)
			g_UsbHcdInfo[usb_ip_port].ep_rx_flush_intr[ep_num-1] = KAL_TRUE;

		USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), 0x00);
		USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
		USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));

//		USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), 0x00);
//		USB_DRV_SetBits(USB_INTRRXE_HCD(USB_BaseAddr[usb_ip_port]), (USB_INTRE_EPEN<<ep_num));
	}

	RestoreIRQMask(savedMask);
	
	return STATUS_OK;

}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_TxEPDis(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_EP_DISABLE_T *prep_disable;
	kal_uint32 savedMask;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;
	kal_bool bDMA;

	prep_disable = &data->rHCD_EP_Disable;
	
	common_str.if_num = (kal_uint32)prep_disable->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep_disable->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep_disable->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep_disable->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep_disable->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep_disable->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep_disable->usb_ep_str.direction;		
	
	bDMA = (kal_bool)prep_disable->fgbDMA;


/* Run in HISR */
	USB_HCD_EP_Check(common_str.usb_ip_port,usb_ep_str.ep_num, USB_EP_TX_DIR, 0);
	USB_HCD_EP_DMA_Running_Check(common_str.usb_ip_port,usb_ep_str.ep_num, USB_EP_TX_DIR, 0);

	g_UsbHcdInfo[common_str.usb_ip_port].ep_tx_info[usb_ep_str.ep_num -1].b_enable = KAL_FALSE;

	if(bDMA == KAL_TRUE)
	{
		USB_HCD_Stop_DMA_Channel(common_str.usb_ip_port,usb_ep_str.ep_num, usb_ep_str.direction);	
	}
	savedMask = SaveAndSetIRQMask();

	USB_DRV_ClearBits(USB_INTRTXE_HCD(USB_BaseAddr[common_str.usb_ip_port]), (USB_INTRE_EPEN << usb_ep_str.ep_num));

	USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[common_str.usb_ip_port]), usb_ep_str.ep_num);

	if((USB_DRV_Reg(USB_TXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]))&USB_TXCSR_FIFONOTEMPTY) != 0)
		g_UsbHcdInfo[common_str.usb_ip_port].ep_tx_flush_intr[usb_ep_str.ep_num-1] = KAL_TRUE;

	USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]), 0x00);
	USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]), (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
	USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]), (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
	RestoreIRQMask(savedMask);



	return STATUS_OK;

}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_RxEPDis(DCL_CTRL_DATA_T *data)
{
	DCL_HANDLE handle;
	USB_HCD_CTRL_EP_DISABLE_T *prep_disable;
	kal_uint32 savedMask;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;
	kal_bool bDMA;

	prep_disable = &data->rHCD_EP_Disable;
	
	common_str.if_num = (kal_uint32)prep_disable->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep_disable->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep_disable->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep_disable->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep_disable->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep_disable->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep_disable->usb_ep_str.direction;		
	
	bDMA = (kal_bool)prep_disable->fgbDMA;
		
		
/* Run in HISR */

	USB_HCD_EP_Check(common_str.usb_ip_port,usb_ep_str.ep_num, USB_EP_RX_DIR, 0);
	USB_HCD_EP_DMA_Running_Check(common_str.usb_ip_port,usb_ep_str.ep_num, USB_EP_RX_DIR, 0);

	g_UsbHcdInfo[common_str.usb_ip_port].ep_rx_info[usb_ep_str.ep_num-1].b_enable = KAL_FALSE;

	if(bDMA == KAL_TRUE)
	{
		USB_HCD_Stop_DMA_Channel(common_str.usb_ip_port,usb_ep_str.ep_num, usb_ep_str.direction);	
		
		handle = (DCL_HANDLE)g_UsbHcdInfo[common_str.usb_ip_port].dma_gpt_handle[usb_ep_str.ep_num-1];
		g_UsbHcdInfo[common_str.usb_ip_port].dma_gpt_handle[usb_ep_str.ep_num-1] = DclSGPT_Close(&handle);
	
//		GPTI_ReleaseHandle(&g_UsbHcdInfo[common_str.usb_ip_port].dma_gpt_handle[usb_ep_str.ep_num-1]);
	}

	savedMask = SaveAndSetIRQMask();

	USB_DRV_ClearBits(USB_INTRRXE_HCD(USB_BaseAddr[common_str.usb_ip_port]), (USB_INTRE_EPEN << usb_ep_str.ep_num));

	USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[common_str.usb_ip_port]), usb_ep_str.ep_num);

	if((USB_DRV_Reg(USB_RXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]))&USB_RXCSR_RXPKTRDY) != 0)
		g_UsbHcdInfo[common_str.usb_ip_port].ep_rx_flush_intr[usb_ep_str.ep_num-1] = KAL_TRUE;

	USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]), 0x00);
	USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]), (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
	USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port]), (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
	RestoreIRQMask(savedMask);


	return STATUS_OK;
}

DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Send_Resume(DCL_CTRL_DATA_T *data)
{
	SGPT_CTRL_START_T start;
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
	kal_uint8	usb_ip_port;
	kal_uint32 savedMask;	
		
	usb_ip = &data->rHCD_ip;
	usb_ip_port = (kal_uint8)usb_ip->ip;

#if defined(__IC_USB_ENABLE__)
	kal_uint8 icusb_remote_eint = 0x30;//custom_eint_get_channel(icusb_remote_eint_chann); QQ Test
#endif

	if (g_UsbHcdInfo[usb_ip_port].host_state  != USBH_STATE_SUSPEND)
			return STATUS_OK; // just receive remote wakeup from Device


	savedMask = SaveAndSetIRQMask();
		
	g_UsbHcdInfo[usb_ip_port].host_state  = USBH_STATE_HOST;			

#if defined(__IC_USB_ENABLE__)
	if (usb_ip_port >= USB_EXT_IP_NUM)  // ICUSB : Send Resume --> Disable Remote Wakeup detection interrupt
	{
		EINT_Mask(icusb_remote_eint);
		// clear EINT interrupt
	}
#endif

	USB_DRV_SetBits8(USB_POWER_HCD(USB_BaseAddr[usb_ip_port]), USB_POWER_RESUME);  //send K

	RestoreIRQMask(savedMask);

  	start.u2Tick = USB_HCD_RESUME_DELAY;					
  	start.pfCallback = USB_HCD_Resume_Recovery_Timeout;			
  	start.vPara = &g_UsbHcdInfo[usb_ip_port];							
  	DclSGPT_Control((DCL_HANDLE)(g_UsbHcdInfo[usb_ip_port].gpt_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	

//	GPTI_StartItem(g_UsbHcdInfo[usb_ip_port].gpt_handle, USB_HCD_RESUME_DELAY,USB_HCD_Resume_Recovery_Timeout, &g_UsbHcdInfo[usb_ip_port]);	

	return STATUS_OK;


}

DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Send_Suspend(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
	kal_uint8	usb_ip_port;
	usb_ip = &data->rHCD_ip;
	usb_ip_port = (kal_uint8)usb_ip->ip;


// This API is called by Task level : Host want to suspend device

#if defined(__IC_USB_ENABLE__)
	kal_uint8 icusb_remote_eint = 0x30;//custom_eint_get_channel(icusb_remote_eint_chann); QQ Test
#endif

	if (usb_ip_port >= USB_IP_NUM)
		ASSERT(0);
	
	
	USB_DRV_SetBits8(USB_POWER_HCD(USB_BaseAddr[usb_ip_port]), USB_POWER_SUSPENDMODE);
	
#if defined(__IC_USB_ENABLE__)
	if (usb_ip_port >= USB_EXT_IP_NUM)  // ICUSB Remoate Wakeup detection
	{
		EINT_Registration(icusb_remote_eint, KAL_FALSE, KAL_TRUE, USB_HCD_Remote_Wakeup, KAL_FALSE);
		EINT_UnMask(icusb_remote_eint);
	}
	
//	IRQ_Register_LISR(IRQ_EIT_CODE, IC_USB_Remote_Wakeup, "ICUSB_EINT"); // register ISR for the EINT 
//	IRQSensitivity(IRQ_EIT_CODE,LEVEL_SENSITIVE); // setup EINT's polarity	
//	SAL_EINT_Set_Sens(1, LEVEL_SENSITIVE); // EINT 1
//	SAL_EINT_EnableDomain(0, 1, 1);
//	SAL_EINT_Control(1, 0,10);
#endif
	
	g_UsbHcdInfo[usb_ip_port].host_state  = USBH_STATE_SUSPEND;

	return STATUS_OK;

}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Send_Req(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_EP_DATA_TXFER_T *prep_data_txfer;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;

	prep_data_txfer = &data->rHCD_EP_Data_Txfer;
	
	common_str.if_num = (kal_uint32)prep_data_txfer->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep_data_txfer->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep_data_txfer->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep_data_txfer->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep_data_txfer->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep_data_txfer->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep_data_txfer->usb_ep_str.direction;			
	
/* May run in app task */
	USB_HCD_EP_Check(common_str.usb_ip_port,usb_ep_str.ep_num, USB_EP_TX_DIR, 0);

	if(g_UsbHcdInfo[common_str.usb_ip_port].ep_tx_info[usb_ep_str.ep_num-1].b_enable == KAL_FALSE)
		prep_data_txfer->return_value = KAL_FALSE;
	else	
		prep_data_txfer->return_value = KAL_TRUE;

	g_UsbHcdInfo[common_str.usb_ip_port].ep_tx_info[usb_ep_str.ep_num-1].p_data = prep_data_txfer->pData;
	g_UsbHcdInfo[common_str.usb_ip_port].ep_tx_info[usb_ep_str.ep_num-1].data_length = prep_data_txfer->u2nBytes;
	g_UsbHcdInfo[common_str.usb_ip_port].ep_tx_info[usb_ep_str.ep_num-1].sofar = 0;


	USB_HCD_Send_Data(common_str,usb_ep_str);

	return STATUS_OK;

}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Recv_Req(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_EP_DATA_TXFER_T *prep_data_txfer;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;

	prep_data_txfer = &data->rHCD_EP_Data_Txfer;

	common_str.if_num = (kal_uint32)prep_data_txfer->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep_data_txfer->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep_data_txfer->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep_data_txfer->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep_data_txfer->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep_data_txfer->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep_data_txfer->usb_ep_str.direction;			

/* Run in HISR */
	USB_HCD_EP_Check(common_str.usb_ip_port,usb_ep_str.ep_num, USB_EP_RX_DIR, 0);

	if(g_UsbHcdInfo[common_str.usb_ip_port].ep_rx_info[usb_ep_str.ep_num-1].b_enable == KAL_FALSE)
		prep_data_txfer->return_value = KAL_FALSE;
	else	
		prep_data_txfer->return_value = KAL_TRUE;

	g_UsbHcdInfo[common_str.usb_ip_port].ep_rx_info[usb_ep_str.ep_num-1].p_data = prep_data_txfer->pData;
	g_UsbHcdInfo[common_str.usb_ip_port].ep_rx_info[usb_ep_str.ep_num-1].data_length = prep_data_txfer->u2nBytes;
	g_UsbHcdInfo[common_str.usb_ip_port].ep_rx_info[usb_ep_str.ep_num-1].sofar = 0;


	USB_HCD_Recv_Data(common_str,usb_ep_str);

	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_EP0_Setup_Req(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_EP0_SETUP_REQ_T *prep0_setup_req;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;

	prep0_setup_req = &data->rHCD_EP0_Setup_Req;

	common_str.if_num = (kal_uint32)prep0_setup_req->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep0_setup_req->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep0_setup_req->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep0_setup_req->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep0_setup_req->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep0_setup_req->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep0_setup_req->usb_ep_str.direction;			

/* May run in task */
	g_UsbHcdInfo[common_str.usb_ip_port].ep0_setup = KAL_TRUE;
	g_UsbHcdInfo[common_str.usb_ip_port].ep0_info.p_data = prep0_setup_req->pSrc;
	g_UsbHcdInfo[common_str.usb_ip_port].ep0_info.data_length = prep0_setup_req->u2nBytes;
	g_UsbHcdInfo[common_str.usb_ip_port].ep0_info.sofar = 0;


	USB_HCD_Send_Setup(common_str,usb_ep_str);
	
	USB_Dbg_Trace(USB_HCD_EP0_Setup,  0, (kal_uint32)g_UsbHcdInfo[common_str.usb_ip_port].ep0_info.data_length);
	
	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_EP0_Data_Req(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_EP0_DATA_REQ_T *prep0_data_req;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;

	prep0_data_req = &data->rHCD_EP0_Data_Req;

	common_str.if_num = (kal_uint32)prep0_data_req->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep0_data_req->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep0_data_req->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep0_data_req->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep0_data_req->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep0_data_req->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep0_data_req->usb_ep_str.direction;			
	
		
/* Run in HISR */
	g_UsbHcdInfo[common_str.usb_ip_port].ep0_info.direction = usb_ep_str.direction;
	g_UsbHcdInfo[common_str.usb_ip_port].ep0_info.p_data = prep0_data_req->pData;
	g_UsbHcdInfo[common_str.usb_ip_port].ep0_info.data_length = prep0_data_req->u2nBytes;
	g_UsbHcdInfo[common_str.usb_ip_port].ep0_info.sofar = 0;

	USB_Dbg_Trace(USB_HCD_EP0_Data,  0, (kal_uint32)g_UsbHcdInfo[common_str.usb_ip_port].ep0_info.data_length);
	

	
	if(usb_ep_str.direction == USB_EP_TX_DIR)
		USB_HCD_Send_Data(common_str,usb_ep_str);
	else
		USB_HCD_Recv_Data(common_str,usb_ep_str);

	return STATUS_OK;

}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_EP0_Status_Req(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_EP0_STATUS_REQ_T *prep0_status_req;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;
	kal_uint32 savedMask;

	prep0_status_req = &data->rHCD_EP0_Status_Req;

	common_str.if_num = (kal_uint32)prep0_status_req->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep0_status_req->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep0_status_req->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep0_status_req->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep0_status_req->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep0_status_req->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep0_status_req->usb_ep_str.direction;			
		
/* Run in HISR */
	g_UsbHcdInfo[common_str.usb_ip_port].ep0_status = KAL_TRUE;
	g_UsbHcdInfo[common_str.usb_ip_port].ep0_fifo_intr = KAL_TRUE;

	USB_Dbg_Trace(USB_HCD_EP0_Status,  0, (kal_uint32)usb_ep_str.direction);
	USB_Dbg_Trace(USB_HCD_EP0_CSR0,  3, USB_DRV_Reg8(USB_EPn_TXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port], 0)));


	if (USB_DRV_Reg8(USB_EPn_TXCSR_HCD(USB_BaseAddr[common_str.usb_ip_port], 0))  & USB_CSR0_STATUSPKT)
			ASSERT(0);
				
	savedMask = SaveAndSetIRQMask();

	USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[common_str.usb_ip_port]), 0);

	if(usb_ep_str.direction == USB_EP_TX_DIR)
	{
		USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[common_str.usb_ip_port]), (USB_CSR0_TXPKTRDY|USB_CSR0_STATUSPKT));
	}
	else
	{
		USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[common_str.usb_ip_port]), (USB_CSR0_REQPKT|USB_CSR0_STATUSPKT));
	}
	RestoreIRQMask(savedMask);
	
	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Switch_DMA_Burst_mode(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_SYSTEM_T *system_drv;
	kal_uint8	usb_ip_port;
	kal_bool	b_enable;
	
	system_drv = &data->rHCD_System_Set;
	usb_ip_port = (kal_uint8)system_drv->ip;
	b_enable = (kal_bool)system_drv->set;

	if(b_enable == KAL_TRUE)
		g_UsbHcdInfo[usb_ip_port].b_enable_dma_burst_auto_chge = KAL_TRUE;
	else
		g_UsbHcdInfo[usb_ip_port].b_enable_dma_burst_auto_chge = KAL_FALSE;

	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Register_DMA_Channel(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_DMA_CTRL_FUNC_1_T *prdma_ctrl_func_1;
	kal_uint8 usb_ip_port;
	kal_uint8 ep_num; 
	USB_EP_DIRECTION direction; 
	kal_uint8 chan_num; 
	kal_bool same_chan;

	prdma_ctrl_func_1 = &data->rHCD_DMA_Ctrl_Func_1;
	usb_ip_port = (kal_uint8)prdma_ctrl_func_1->ip;
	ep_num = (kal_uint8)prdma_ctrl_func_1->u1ep_num; 
	direction = (USB_EP_DIRECTION)prdma_ctrl_func_1->direction; 
	chan_num = (kal_uint8)prdma_ctrl_func_1->u1chan_num; 
	same_chan = (kal_bool)prdma_ctrl_func_1->fgsame_chan;

/* Register DMA channel number for logical endpoint */
	if (usb_ip_port < USB_EXT_IP_NUM)
	{
		if(g_UsbHcdInfo[usb_ip_port].dma_channel > MAX_DMA_NUM)
			EXT_ASSERT(0, g_UsbHcdInfo[usb_ip_port].dma_channel, MAX_DMA_NUM, 0);
	}
#if defined(__IC_USB_ENABLE__)	
	else
	{
		if(g_UsbHcdInfo[usb_ip_port].dma_channel > ICUSB_MAX_DMA_NUM)
			EXT_ASSERT(0, g_UsbHcdInfo[usb_ip_port].dma_channel, ICUSB_MAX_DMA_NUM, 0);
	}
#endif

	if(same_chan == KAL_TRUE)
	{
		USB_HCD_EP_Check(usb_ip_port,ep_num, USB_EP_TX_DIR, 0);
		USB_HCD_EP_Check(usb_ip_port,ep_num, USB_EP_RX_DIR, 0);

		g_UsbHcdInfo[usb_ip_port].is_bidirection_dma[chan_num-1] = KAL_TRUE;
		/* the same channel */
		g_UsbHcdInfo[usb_ip_port].dma_port[USB_EP_TX_DIR][ep_num-1] = chan_num;
		g_UsbHcdInfo[usb_ip_port].dma_port[USB_EP_RX_DIR][ep_num-1] = chan_num;
		g_UsbHcdInfo[usb_ip_port].dma_tx_ep_num[chan_num-1] = ep_num;
		g_UsbHcdInfo[usb_ip_port].dma_rx_ep_num[chan_num-1] = ep_num;
	}
	else
	{
		USB_HCD_EP_Check(usb_ip_port,ep_num, direction, 0);

		g_UsbHcdInfo[usb_ip_port].is_bidirection_dma[chan_num-1] = KAL_FALSE;
		g_UsbHcdInfo[usb_ip_port].dma_dir[chan_num-1] = direction;
		g_UsbHcdInfo[usb_ip_port].dma_port[direction][ep_num-1] = chan_num;

		if(direction == USB_EP_TX_DIR)
		{
			g_UsbHcdInfo[usb_ip_port].dma_tx_ep_num[chan_num-1] = ep_num;
		}
		else
		{
			g_UsbHcdInfo[usb_ip_port].dma_rx_ep_num[chan_num-1] = ep_num;
		}
	}

	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Get_DMA_Real_Count(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_DMA_CTRL_FUNC_2_T *prdma_ctrl_func_2;
	kal_uint8 usb_ip_port;
	kal_uint8 ep_num; 
	USB_EP_DIRECTION direction; 

	prdma_ctrl_func_2 = &data->rHCD_DMA_Ctrl_Func_2;
	usb_ip_port = (kal_uint8)prdma_ctrl_func_2->ip;
	ep_num = (kal_uint8)prdma_ctrl_func_2->u1ep_num; 
	direction = (USB_EP_DIRECTION)prdma_ctrl_func_2->direction; 



	USB_HCD_EP_Check(usb_ip_port,ep_num, direction, 0);
	prdma_ctrl_func_2->return_value =  USB_DRV_Reg32(USB_DMA_REALCNT_HCD(USB_BaseAddr[usb_ip_port],g_UsbHcdInfo[usb_ip_port].dma_port[direction][ep_num-1]));

	return STATUS_OK;

}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Get_DMA_Channel(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_DMA_CHANNEL_FUNC_T *prdma_func;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_tx_str;
	USBH_EP_Struct usb_rx_str;
	USB_EP_DIRECTION direction;
	kal_bool same_chan;
	kal_uint8 	usb_ip_port;
	kal_uint8 	ep_tx_num;
	kal_uint8 	ep_rx_num;

	prdma_func = &data->rHCD_DMA_Channel_Func;
	
	common_str.if_num = (kal_uint32)prdma_func->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prdma_func->common_str.usb_ip_port;			
	
	usb_tx_str.ep_max_pkt_size = (kal_uint16)prdma_func->usb_tx_str.ep_max_pkt_size;
	usb_tx_str.ep_num = (kal_uint8)prdma_func->usb_tx_str.ep_num;
	usb_tx_str.ep_real_num = (kal_uint8)prdma_func->usb_tx_str.ep_real_num;
	usb_tx_str.ep_type = (USB_ENDPT_TXFER_TYPE)prdma_func->usb_tx_str.ep_type;
	usb_tx_str.direction = (USB_EP_DIRECTION)prdma_func->usb_tx_str.direction;	
		
	usb_rx_str.ep_max_pkt_size = (kal_uint16)prdma_func->usb_rx_str.ep_max_pkt_size;
	usb_rx_str.ep_num = (kal_uint8)prdma_func->usb_rx_str.ep_num;
	usb_rx_str.ep_real_num = (kal_uint8)prdma_func->usb_rx_str.ep_real_num;
	usb_rx_str.ep_type = (USB_ENDPT_TXFER_TYPE)prdma_func->usb_rx_str.ep_type;
	usb_rx_str.direction = (USB_EP_DIRECTION)prdma_func->usb_rx_str.direction;	
		
	
	direction = (USB_EP_DIRECTION)prdma_func->direction;	
	same_chan = (kal_bool)prdma_func->same_chan;
	usb_ip_port = (kal_uint8)common_str.usb_ip_port;
	ep_tx_num = (kal_uint8)usb_tx_str.ep_num;
	ep_rx_num = (kal_uint8)usb_rx_str.ep_num;
	
	g_UsbHcdInfo[usb_ip_port].dma_channel++;

	if (usb_ip_port < USB_EXT_IP_NUM)
	{
		if(g_UsbHcdInfo[usb_ip_port].dma_channel > MAX_DMA_NUM)
			EXT_ASSERT(0, g_UsbHcdInfo[usb_ip_port].dma_channel, MAX_DMA_NUM, 0);
	}
#if defined(__IC_USB_ENABLE__)	
	else
	{
		if(g_UsbHcdInfo[usb_ip_port].dma_channel > ICUSB_MAX_DMA_NUM)
			EXT_ASSERT(0, g_UsbHcdInfo[usb_ip_port].dma_channel, ICUSB_MAX_DMA_NUM, 0);
	}
#endif

	if(same_chan == KAL_TRUE)
	{
		USB_HCD_EP_Check(usb_ip_port,ep_tx_num, USB_EP_TX_DIR, 0);
		USB_HCD_EP_Check(usb_ip_port,ep_rx_num, USB_EP_RX_DIR, 0);

		g_UsbHcdInfo[usb_ip_port].is_bidirection_dma[g_UsbHcdInfo[usb_ip_port].dma_channel-1] = KAL_TRUE;
		/* the same channel */
		g_UsbHcdInfo[usb_ip_port].dma_port[USB_EP_TX_DIR][ep_tx_num-1] = g_UsbHcdInfo[usb_ip_port].dma_channel;
		g_UsbHcdInfo[usb_ip_port].dma_port[USB_EP_RX_DIR][ep_rx_num-1] = g_UsbHcdInfo[usb_ip_port].dma_channel;
		g_UsbHcdInfo[usb_ip_port].dma_tx_ep_num[g_UsbHcdInfo[usb_ip_port].dma_channel-1] = ep_tx_num;
		g_UsbHcdInfo[usb_ip_port].dma_rx_ep_num[g_UsbHcdInfo[usb_ip_port].dma_channel-1] = ep_rx_num;
	}
	else
	{
		g_UsbHcdInfo[usb_ip_port].is_bidirection_dma[g_UsbHcdInfo[usb_ip_port].dma_channel-1] = KAL_FALSE;
		g_UsbHcdInfo[usb_ip_port].dma_dir[g_UsbHcdInfo[usb_ip_port].dma_channel-1] = direction;

		if(direction == USB_EP_TX_DIR)
		{
			USB_HCD_EP_Check(usb_ip_port,ep_tx_num, USB_EP_TX_DIR, 0);
			g_UsbHcdInfo[usb_ip_port].dma_port[direction][ep_tx_num-1] = g_UsbHcdInfo[usb_ip_port].dma_channel;
			g_UsbHcdInfo[usb_ip_port].dma_tx_ep_num[g_UsbHcdInfo[usb_ip_port].dma_channel-1] = ep_tx_num;
		}
		else
		{
			USB_HCD_EP_Check(usb_ip_port,ep_rx_num, USB_EP_RX_DIR, 0);
			g_UsbHcdInfo[usb_ip_port].dma_port[direction][ep_rx_num-1] = g_UsbHcdInfo[usb_ip_port].dma_channel;
			g_UsbHcdInfo[usb_ip_port].dma_rx_ep_num[g_UsbHcdInfo[usb_ip_port].dma_channel-1] = ep_rx_num;
		}
	}

	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Stop_DMA_Channel(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_EP_CTRL_FUNC_1_T *prep_ctrl_func_1;
//	kal_uint8 	dma_chan;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;

	prep_ctrl_func_1 = &data->rHCD_EP_Ctrl_Func_1;

	common_str.if_num = (kal_uint32)prep_ctrl_func_1->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep_ctrl_func_1->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep_ctrl_func_1->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep_ctrl_func_1->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep_ctrl_func_1->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep_ctrl_func_1->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep_ctrl_func_1->usb_ep_str.direction;		
	
	USB_HCD_Stop_DMA_Channel(common_str.usb_ip_port,usb_ep_str.ep_num, usb_ep_str.direction);	

	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Free_DMA_Channel(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_DMA_CHANNEL_FUNC_T *prdma_func;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_tx_str;
	USBH_EP_Struct usb_rx_str;
	USB_EP_DIRECTION direction;
	kal_bool 	same_chan;
	kal_uint8 	dma_chan;
	kal_uint8	usb_ip_port;
	kal_uint8	ep_tx_num;
	kal_uint8	ep_rx_num;

	prdma_func = &data->rHCD_DMA_Channel_Func;
	
	common_str.if_num = (kal_uint32)prdma_func->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prdma_func->common_str.usb_ip_port;	

	usb_tx_str.ep_max_pkt_size = (kal_uint16)prdma_func->usb_tx_str.ep_max_pkt_size;
	usb_tx_str.ep_num = (kal_uint8)prdma_func->usb_tx_str.ep_num;
	usb_tx_str.ep_real_num = (kal_uint8)prdma_func->usb_tx_str.ep_real_num;
	usb_tx_str.ep_type = (USB_ENDPT_TXFER_TYPE)prdma_func->usb_tx_str.ep_type;
	usb_tx_str.direction = (USB_EP_DIRECTION)prdma_func->usb_tx_str.direction;		
		
	usb_rx_str.ep_max_pkt_size = (kal_uint16)prdma_func->usb_rx_str.ep_max_pkt_size;
	usb_rx_str.ep_num = (kal_uint8)prdma_func->usb_rx_str.ep_num;
	usb_rx_str.ep_real_num = (kal_uint8)prdma_func->usb_rx_str.ep_real_num;
	usb_rx_str.ep_type = (USB_ENDPT_TXFER_TYPE)prdma_func->usb_rx_str.ep_type;
	usb_rx_str.direction = (USB_EP_DIRECTION)prdma_func->usb_rx_str.direction;	
	
	direction = (USB_EP_DIRECTION)prdma_func->direction;	
	same_chan = (kal_bool)prdma_func->same_chan;
	usb_ip_port = (kal_uint8)common_str.usb_ip_port;
	ep_tx_num = (kal_uint8)usb_tx_str.ep_num;
	ep_rx_num = (kal_uint8)usb_rx_str.ep_num;



/* Stop and free DMA channel resource */
	if(same_chan == KAL_TRUE)
	{
		USB_HCD_EP_Check(usb_ip_port,ep_tx_num, USB_EP_TX_DIR, 0);
		USB_HCD_EP_Check(usb_ip_port,ep_rx_num, USB_EP_RX_DIR, 0);

		dma_chan = g_UsbHcdInfo[usb_ip_port].dma_port[USB_EP_TX_DIR][ep_tx_num-1];

		/* Get DMA channel in start func, but free DMA clannel in detach func */
		if(dma_chan != 0)
		{
			USB_HCD_Stop_DMA_Channel(usb_ip_port,ep_tx_num, USB_EP_TX_DIR);

			if(g_UsbHcdInfo[usb_ip_port].is_bidirection_dma[dma_chan-1] == KAL_FALSE)
			{
				ASSERT(0);
			}

			g_UsbHcdInfo[usb_ip_port].dma_tx_ep_num[dma_chan-1] = 0;
			g_UsbHcdInfo[usb_ip_port].dma_rx_ep_num[dma_chan-1] = 0;
			/* Must clear two dma port */
			g_UsbHcdInfo[usb_ip_port].dma_port[USB_EP_TX_DIR][ep_tx_num-1] = 0;
			g_UsbHcdInfo[usb_ip_port].dma_port[USB_EP_RX_DIR][ep_rx_num-1] = 0;
		}
	}
	else
	{
		if(direction == USB_EP_TX_DIR)
		{
			USB_HCD_EP_Check(usb_ip_port,ep_tx_num, USB_EP_TX_DIR, 0);

			dma_chan = g_UsbHcdInfo[usb_ip_port].dma_port[USB_EP_TX_DIR][ep_tx_num-1];

			if(dma_chan != 0)
			{
				USB_HCD_Stop_DMA_Channel(usb_ip_port,ep_tx_num, USB_EP_TX_DIR);

				if(g_UsbHcdInfo[usb_ip_port].is_bidirection_dma[dma_chan-1] == KAL_TRUE)
				{
					ASSERT(0);
				}

				g_UsbHcdInfo[usb_ip_port].dma_tx_ep_num[dma_chan-1] = 0;
				g_UsbHcdInfo[usb_ip_port].dma_port[USB_EP_TX_DIR][ep_tx_num-1] = 0;
			}
		}
		else
		{
			USB_HCD_EP_Check(usb_ip_port,ep_rx_num, USB_EP_RX_DIR, 0);

			dma_chan = g_UsbHcdInfo[usb_ip_port].dma_port[USB_EP_RX_DIR][ep_rx_num-1];

			if(dma_chan != 0)
			{
				USB_HCD_Stop_DMA_Channel(usb_ip_port,ep_rx_num, USB_EP_RX_DIR);

				if(g_UsbHcdInfo[usb_ip_port].is_bidirection_dma[dma_chan-1] == KAL_TRUE)
				{
					ASSERT(0);
				}

				g_UsbHcdInfo[usb_ip_port].dma_rx_ep_num[dma_chan-1] = 0;
				g_UsbHcdInfo[usb_ip_port].dma_port[USB_EP_RX_DIR][ep_rx_num-1] = 0;
			}
		}
	}

	return STATUS_OK;
}

DCL_STATUS DCL_USB_CTRL_API_USB_HCD_EPFIFORead(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_EP_DATA_TXFER_T *prep_data_txfer;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;
	kal_uint16  nCount;
//	kal_uint8   *pby;
//	kal_uint32  nAddr;

	prep_data_txfer = &data->rHCD_EP_Data_Txfer;
	
	common_str.if_num = (kal_uint32)prep_data_txfer->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep_data_txfer->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep_data_txfer->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep_data_txfer->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep_data_txfer->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep_data_txfer->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep_data_txfer->usb_ep_str.direction;		
		
	nCount = (kal_uint16)prep_data_txfer->u2nBytes;


	USB_HCD_EPFIFORead(common_str,usb_ep_str,nCount,prep_data_txfer->pData);

	return STATUS_OK;
}

DCL_STATUS DCL_USB_CTRL_API_USB_HCD_EPFIFOWrite(DCL_CTRL_DATA_T *data)
{

	USB_HCD_CTRL_EP_DATA_TXFER_T *prep_data_txfer;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;
	kal_uint16  nCount;
//	kal_uint8   *pby;
//	kal_uint32  nAddr;

	prep_data_txfer = &data->rHCD_EP_Data_Txfer;
	
	common_str.if_num = (kal_uint32)prep_data_txfer->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prep_data_txfer->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prep_data_txfer->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prep_data_txfer->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prep_data_txfer->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prep_data_txfer->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prep_data_txfer->usb_ep_str.direction;		
		
	nCount = (kal_uint16)prep_data_txfer->u2nBytes;


	USB_HCD_EPFIFOWrite(common_str,usb_ep_str,nCount,prep_data_txfer->pData);	

	return STATUS_OK;

}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_DMA_Setup(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_DMA_SETUP_FUNC_T *prdma_setup_func;
//	kal_uint16  dma_ctrl;
//	kal_uint8    dma_chan;
//	kal_uint32  dma_burst_mode = 0;
//	kal_uint32  savedMask;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;
//	kal_uint8 usb_ip_port;
//	kal_uint8 ep_num ;	
//	USB_EP_DIRECTION direction;
//	USB_ENDPT_TXFER_TYPE ep_type;
	kal_uint32 addr;
	kal_uint32 length;
	usb_dma_callback callback;
	kal_bool callback_upd_run;
	kal_bool known_size;
	USB_DMA_TYPE dma_type;
	
	prdma_setup_func = &data->rHCD_DMA_Setup_Func;

	common_str.if_num = (kal_uint32)prdma_setup_func->common_str.if_num;
	common_str.usb_ip_port = (kal_uint8)prdma_setup_func->common_str.usb_ip_port;		
		
	usb_ep_str.ep_max_pkt_size = (kal_uint16)prdma_setup_func->usb_ep_str.ep_max_pkt_size;
	usb_ep_str.ep_num = (kal_uint8)prdma_setup_func->usb_ep_str.ep_num;
	usb_ep_str.ep_real_num = (kal_uint8)prdma_setup_func->usb_ep_str.ep_real_num;
	usb_ep_str.ep_type = (USB_ENDPT_TXFER_TYPE)prdma_setup_func->usb_ep_str.ep_type;
	usb_ep_str.direction = (USB_EP_DIRECTION)prdma_setup_func->usb_ep_str.direction;		
				
//	usb_ip_port = (kal_uint8)common_str.usb_ip_port;
//	ep_num = (kal_uint8)usb_ep_str.ep_num;	
//	direction = (USB_EP_DIRECTION)usb_ep_str.direction;
//	ep_type = (USB_ENDPT_TXFER_TYPE)usb_ep_str.ep_type;
	addr = (kal_uint32)prdma_setup_func->u4addr;
	length = (kal_uint32)prdma_setup_func->u4length;
	callback = (usb_dma_callback)prdma_setup_func->callback;
	callback_upd_run = (kal_bool)prdma_setup_func->fgcallback_upd_run;
	known_size = (kal_bool)prdma_setup_func->fgknown_size;
	dma_type = (USB_DMA_TYPE)prdma_setup_func->dma_type;


	USB_HCD_DMA_Setup(common_str,usb_ep_str,addr,length,callback,callback_upd_run,known_size,dma_type);

	return STATUS_OK;

}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Disconn_Hdlr(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
	kal_uint8	usb_ip_port;
	
	usb_ip = &data->rHCD_ip;
	usb_ip_port = (kal_uint8)usb_ip->ip;


	USB_HCD_Disconn_Hdlr(usb_ip_port);

	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_Conn_Hdlr(DCL_CTRL_DATA_T *data)
{
	USB_HCD_CTRL_IP_NUM_T *usb_ip;
	kal_uint8	usb_ip_port;
	
	usb_ip = &data->rHCD_ip;
	usb_ip_port = (kal_uint8)usb_ip->ip;
	
/* Although we stop all eps' activities when we process disconn hdlr, but there may be some eps still are accessed after disconn intr because APP layer did read/write cmds */

	USB_HCD_Conn_Hdlr(usb_ip_port);
	
	return STATUS_OK;

}


DCL_STATUS DCL_USB_CTRL_API_USB_HCD_VBUS_OFF(DCL_CTRL_DATA_T *data)
{
	USB_HCD_VBusEnable(0, KAL_FALSE);

	return STATUS_OK;
}


void USB_HCD_HISR(void)
{
	kal_uint8    IntrUSB;
	kal_uint16  IntrTx;
	kal_uint16  IntrRx;
	kal_uint16  CSR0;
	kal_uint16  TXCSR;
	kal_uint16  RXCSR;
	kal_uint32  ep_num = 0;
	kal_uint32  pkt_length;
	kal_uint16 todo;
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;	
	kal_uint8 usb_ip_port = 0;
	
	common_str.usb_ip_port = usb_ip_port;

	// Read and clear!!
	IntrUSB = OTG_Get_Intr_Status();


#if defined(DRV_USB_IP_V3)
	// Read and clear!!
	IntrTx = USB_DRV_Reg(USB_INTRTX_HCD(USB_BaseAddr[usb_ip_port]));
	// Write 0 clear
	IntrRx = USB_DRV_Reg(USB_INTRRX_HCD(USB_BaseAddr[usb_ip_port]));
	USB_DRV_WriteReg(USB_INTRRX_HCD(USB_BaseAddr[usb_ip_port]), ~IntrRx);
#else
	// Write 1 clear
	IntrTx = USB_DRV_Reg(USB_INTRTX_HCD(USB_BaseAddr[usb_ip_port]));
	USB_DRV_WriteReg(USB_INTRTX_HCD(USB_BaseAddr[usb_ip_port]), IntrTx);

	// Write 1 clear
	IntrRx = USB_DRV_Reg(USB_INTRRX_HCD(USB_BaseAddr[usb_ip_port]));
	USB_DRV_WriteReg(USB_INTRRX_HCD(USB_BaseAddr[usb_ip_port]), IntrRx);
#endif


	if((IntrUSB&USB_INTRUSB_RESUME) != 0)
	{
		if (USB_HCD_Is_RemoteWakeup_SUPPORT(usb_ip_port) == KAL_TRUE)
		{
			/* Remote wakeup */
			USB_Dbg_Trace(USB_HCD_RESUME,  0, 0);
			USB_HCD_Resume(usb_ip_port);
		}
	}

	if((IntrUSB&USB_INTRUSB_CONN) != 0)
	{
		/* A or B side plug out will both trigger this dis_conn interrupt */
		if((IntrUSB&USB_INTRUSB_DISCON) != 0)
		{
			USB_Dbg_Trace(USB_HCD_CONN_AND_DISCONN,  USB_DRV_Reg8(USB_LINE_STATE), 0);
			drv_trace0(TRACE_FUNC, (kal_uint32)USB_HCD_CONN_AND_DISCONN_INTR);
			IntrTx = 0;
			IntrRx = 0;
			OTG_Set_Disconn_Status();
			USB_HCD_Disconn_Hdlr(usb_ip_port);
			return;
		}

		USB_Dbg_Trace(USB_HCD_CONN,  USB_DRV_Reg8(USB_LINE_STATE), 0);
		drv_trace0(TRACE_FUNC, (kal_uint32)USB_HCD_CONN_INTR);
		USB_HCD_Conn_Hdlr(usb_ip_port);
	}

	if((IntrUSB&USB_INTRUSB_BABBLE) != 0)
	{
		if((OTG_Get_State() == OTG_STATE_A_HOST)||(OTG_Get_State() == OTG_STATE_B_HOST))
		{
			USB_Dbg_Trace(USB_HCD_BABBLE,  USB_DRV_Reg8(USB_OPSTATE_HCD(USB_BaseAddr[usb_ip_port])),USB_DRV_Reg8(USB_DEVCTL_HCD(USB_BaseAddr[usb_ip_port])));
			drv_trace0(TRACE_FUNC, (kal_uint32)USB_HCD_BABBLE_INTR);

			//B-Device doesn't need to clear session bit 
			if ((USB_DRV_Reg8(USB_DEVCTL_HCD(USB_BaseAddr[usb_ip_port])) & USB_DEVCTL_BDEVICE) == 0)
				USB_HCD_VBusEnable(usb_ip_port,KAL_FALSE);

			/* Disable all USB interrupts */
			USB_DRV_WriteReg8(USB_INTRUSBE_HCD(USB_BaseAddr[usb_ip_port]), 0x00);

			/* handle as disconnect intr to prevent upper laype still wait the events */
			USB_HCD_Disconn_Hdlr(usb_ip_port);
		}
	}

	/* Check for endpoint 0 interrupt */
	if(IntrTx&USB_INTRTX_EP0)
	{
		if(g_UsbHcdInfo[usb_ip_port].ep0_hdlr == NULL)
			ASSERT(0);

		USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), 0);
		CSR0 = USB_DRV_Reg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]));

		USB_Dbg_Trace(USB_HCD_EP0_INTR,  CSR0, 0);

		usb_ep_str.ep_num = 0;
		usb_ep_str.ep_type = USB_ENDPT_CTRL;

		if(CSR0&USB_CSR0_RXSTALL)
		{
			drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_TX_EPN_STALL, 0);

			g_UsbHcdInfo[usb_ip_port].ep0_fifo_intr = KAL_FALSE;
			g_UsbHcdInfo[usb_ip_port].ep0_setup = KAL_FALSE;
			g_UsbHcdInfo[usb_ip_port].ep0_status = KAL_FALSE;

			CSR0 &= ~USB_CSR0_RXSTALL;
			USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), CSR0);
			g_UsbHcdInfo[usb_ip_port].ep0_hdlr(usb_ip_port,USB_HCD_STALL, 0);
		}
		else if (CSR0&USB_CSR0_ERROR)
		{
			drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_TX_EPN_ERROR, 0);

			/* Bad cable */
			g_UsbHcdInfo[usb_ip_port].ep0_fifo_intr = KAL_FALSE;
			g_UsbHcdInfo[usb_ip_port].ep0_setup = KAL_FALSE;
			g_UsbHcdInfo[usb_ip_port].ep0_status = KAL_FALSE;

			USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), USB_CSR0_ERROR);
			USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), USB_CSR0_FLUSHFIFO);
			g_UsbHcdInfo[usb_ip_port].ep0_hdlr(usb_ip_port,USB_HCD_NO_RESPONSE, 0);
		}
		else if (CSR0&USB_CSR0_NAKTIMEOUT)
		{
			drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_TX_EPN_TIMEOUT, 0);

			g_UsbHcdInfo[usb_ip_port].ep0_fifo_intr = KAL_FALSE;
			g_UsbHcdInfo[usb_ip_port].ep0_setup = KAL_FALSE;
			g_UsbHcdInfo[usb_ip_port].ep0_status = KAL_FALSE;

			USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), USB_CSR0_NAKTIMEOUT);
			USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), USB_CSR0_FLUSHFIFO);
			g_UsbHcdInfo[usb_ip_port].ep0_hdlr(usb_ip_port,USB_HCD_TIMEOUT, 0);
		}
		else if (CSR0&USB_CSR0_RXSTALL)
		{
			drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_TX_EPN_STALL, 0);
			
			/* Clear STALL bit */
			CSR0 &= ~USB_CSR0_RXSTALL;
			USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), CSR0);

			g_UsbHcdInfo[usb_ip_port].ep0_hdlr(usb_ip_port,USB_HCD_STALL, 0);
			
		}
		else
		{
			USB_Dbg_Trace(USB_HCD_EP0_INTR,  (kal_uint32)g_UsbHcdInfo[usb_ip_port].ep0_setup, (kal_uint32)g_UsbHcdInfo[usb_ip_port].ep0_status);

			if(g_UsbHcdInfo[usb_ip_port].ep0_fifo_intr == KAL_TRUE)
			{
				g_UsbHcdInfo[usb_ip_port].ep0_fifo_intr = KAL_FALSE;

				if(g_UsbHcdInfo[usb_ip_port].ep0_setup == KAL_TRUE)
				{
					/* Setup and status packet must be single packet */
					g_UsbHcdInfo[usb_ip_port].ep0_setup = KAL_FALSE;

					if(CSR0&USB_CSR0_SETUPPKT)
					{
						CSR0 &= ~(USB_CSR0_SETUPPKT|USB_CSR0_TXPKTRDY);
						CSR0 |= USB_CSR0_FLUSHFIFO;
						USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), CSR0);
						g_UsbHcdInfo[usb_ip_port].ep0_hdlr(usb_ip_port,USB_HCD_NO_RESPONSE, 0);
					}
					else
					{
						g_UsbHcdInfo[usb_ip_port].ep0_hdlr(usb_ip_port,USB_HCD_OK, g_UsbHcdInfo[usb_ip_port].ep0_info.sofar);
					}
				}
				else if(g_UsbHcdInfo[usb_ip_port].ep0_status == KAL_TRUE)
				{
					g_UsbHcdInfo[usb_ip_port].ep0_status = KAL_FALSE;

					/* Clear status bit */
					USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), 0x00);
					g_UsbHcdInfo[usb_ip_port].ep0_hdlr(usb_ip_port,USB_HCD_OK, g_UsbHcdInfo[usb_ip_port].ep0_info.sofar);
				}
				else if(g_UsbHcdInfo[usb_ip_port].ep0_info.direction == USB_EP_RX_DIR)
				{
					/* Read the receive packet length */
					pkt_length = USB_HCD_EP0_Pkt_Len(common_str);

					if((g_UsbHcdInfo[usb_ip_port].ep0_info.sofar + pkt_length) > g_UsbHcdInfo[usb_ip_port].ep0_info.data_length)
					{
						pkt_length = g_UsbHcdInfo[usb_ip_port].ep0_info.data_length - g_UsbHcdInfo[usb_ip_port].ep0_info.sofar;
					}

					USB_HCD_EPFIFORead(common_str,usb_ep_str, pkt_length, &g_UsbHcdInfo[usb_ip_port].ep0_info.p_data[g_UsbHcdInfo[usb_ip_port].ep0_info.sofar]);

					g_UsbHcdInfo[usb_ip_port].ep0_info.sofar += pkt_length;

					USB_Dbg_Trace(USB_HCD_EP0_Data,  (kal_uint32)g_UsbHcdInfo[usb_ip_port].ep0_info.sofar, (kal_uint32)g_UsbHcdInfo[usb_ip_port].ep0_info.data_length);
					CSR0 &= ~USB_CSR0_RXPKTRDY;
					USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), CSR0);

					drv_trace2(TRACE_FUNC, (kal_uint32)USB_HCD_EP0,g_UsbHcdInfo[usb_ip_port].ep0_info.sofar, g_UsbHcdInfo[usb_ip_port].ep0_info.data_length);

					if((g_UsbHcdInfo[usb_ip_port].ep0_info.sofar == g_UsbHcdInfo[usb_ip_port].ep0_info.data_length)
						||(pkt_length < g_UsbHcdInfo[usb_ip_port].ep0_info.max_packet_size))
					{
						/* callback to USB stack */
						drv_trace4(TRACE_FUNC, (kal_uint32)USB_HCD_EP0_RX,g_UsbHcdInfo[usb_ip_port].ep0_info.sofar, g_UsbHcdInfo[usb_ip_port].ep0_info.data_length,g_UsbHcdInfo[usb_ip_port].ep0_info.max_packet_size,0);
						g_UsbHcdInfo[usb_ip_port].ep0_hdlr(usb_ip_port,USB_HCD_OK, g_UsbHcdInfo[usb_ip_port].ep0_info.sofar);
					}
					else
					{
						/* Receive this pcket, and request for next packet */
						g_UsbHcdInfo[usb_ip_port].ep0_fifo_intr = KAL_TRUE;
						CSR0 &= ~USB_CSR0_RXPKTRDY;
						USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), CSR0);
						USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), (CSR0|USB_CSR0_REQPKT));
					}
				}
				else if(g_UsbHcdInfo[usb_ip_port].ep0_info.direction == USB_EP_TX_DIR)
				{				
					if((g_UsbHcdInfo[usb_ip_port].ep0_info.data_length-g_UsbHcdInfo[usb_ip_port].ep0_info.sofar)
						>g_UsbHcdInfo[usb_ip_port].ep0_info.max_packet_size)
						pkt_length = g_UsbHcdInfo[usb_ip_port].ep0_info.max_packet_size;
					else
						pkt_length = g_UsbHcdInfo[usb_ip_port].ep0_info.data_length-g_UsbHcdInfo[usb_ip_port].ep0_info.sofar;

					if (pkt_length == 0) //all data has already sent out
					{
						g_UsbHcdInfo[usb_ip_port].ep0_hdlr(usb_ip_port,USB_HCD_OK, g_UsbHcdInfo[usb_ip_port].ep0_info.sofar);
					}
					else
					{
						/* Write data packet to FIFO */
						USB_HCD_EPFIFOWrite(common_str,usb_ep_str, pkt_length, &g_UsbHcdInfo[usb_ip_port].ep0_info.p_data[g_UsbHcdInfo[usb_ip_port].ep0_info.sofar]);
						g_UsbHcdInfo[usb_ip_port].ep0_info.sofar += pkt_length;
						g_UsbHcdInfo[usb_ip_port].ep0_fifo_intr = KAL_TRUE;

						USB_Dbg_Trace(USB_HCD_EP0_Data,  (kal_uint32)g_UsbHcdInfo[usb_ip_port].ep0_info.sofar, (kal_uint32)g_UsbHcdInfo[usb_ip_port].ep0_info.data_length);

						USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), 0);
						USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), USB_CSR0_TXPKTRDY);
					}

					USB_Dbg_Trace(USB_HCD_SEND_DATA_DONE,  ep_num, 0);
				}
			}
			else
			{
				USB_Dbg_Trace(USB_HCD_UNEXPECTED_EP0_INTR,  0, 0);
			}
		}
	}

	/* Check for Bulk TX interrupt */
	/* TX interrupt : 1.TxPktRdy is clear, 2. RXSTALL is set */
	for(ep_num = 1; ep_num <= MAX_TX_EP_NUM; ep_num++)
	{
		if (IntrTx&(0x01 <<ep_num))
		{
			USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);
			TXCSR = USB_DRV_Reg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]));

			USB_Dbg_Trace(USB_HCD_EPN_TX_INTR,  ep_num, TXCSR);

			usb_ep_str.ep_num = ep_num;
			usb_ep_str.direction = USB_EP_TX_DIR;

			if((TXCSR&USB_TXCSR_RXSTALL) != 0)
			{
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_TX_EPN_STALL, ep_num);

				g_UsbHcdInfo[usb_ip_port].ep_tx_fifo_intr[ep_num-1] = KAL_FALSE;

				/* Stop running DMA */
				USB_HCD_DMA_Stop(usb_ip_port,ep_num, USB_EP_TX_DIR);

				/* Clear RXSTALL bit */
				TXCSR &= ~USB_TXCSR_RXSTALL;
				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), TXCSR);

				if(g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1] != NULL)
					g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1](usb_ip_port,USB_HCD_STALL, (kal_uint32)USB_EP_TX_DIR);
			}
			else if((TXCSR&USB_TXCSR_ERROR) != 0)
			{
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_TX_EPN_ERROR, ep_num);

				g_UsbHcdInfo[usb_ip_port].ep_tx_fifo_intr[ep_num-1] = KAL_FALSE;

				/* Because of bad cable */
				/* Stop running DMA */
				USB_HCD_DMA_Stop(usb_ip_port,ep_num, USB_EP_TX_DIR);

				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_TXCSR_ERROR);
				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));

				g_UsbHcdInfo[usb_ip_port].ep_tx_flush_intr[ep_num-1] = KAL_TRUE;

				if(g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1] != NULL)
					g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1](usb_ip_port,USB_HCD_NO_RESPONSE, (kal_uint32)USB_EP_TX_DIR);
			}
			else if((TXCSR&USB_TXCSR_NAKTIMEOUT) != 0)
			{
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_TX_EPN_TIMEOUT, ep_num);

				g_UsbHcdInfo[usb_ip_port].ep_tx_fifo_intr[ep_num-1] = KAL_FALSE;

				/* Because of bad cable */
				/* Stop running DMA */
				USB_HCD_DMA_Stop(usb_ip_port,ep_num, USB_EP_TX_DIR);

				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_TXCSR_NAKTIMEOUT);
				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));

				g_UsbHcdInfo[usb_ip_port].ep_tx_flush_intr[ep_num-1] = KAL_TRUE;

				if(g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1] != NULL)
					g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1](usb_ip_port,USB_HCD_TIMEOUT, (kal_uint32)USB_EP_TX_DIR);
			}
			else
			{
				if(g_UsbHcdInfo[usb_ip_port].ep_tx_fifo_intr[ep_num-1] == KAL_TRUE)
				{
					g_UsbHcdInfo[usb_ip_port].ep_tx_fifo_intr[ep_num-1] = KAL_FALSE;

					if(g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].data_length == g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].sofar)
					{
						if(g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1] != NULL)
							g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1](usb_ip_port,USB_HCD_OK, g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].data_length);
					}
					else
					{
						if((g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].data_length-g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].sofar)
							>g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].max_packet_size)
							todo = g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].max_packet_size;
						else
							todo = g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].data_length-g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].sofar;

						/* Write data packet to FIFO */
						USB_HCD_EPFIFOWrite(common_str,usb_ep_str, todo, &g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].p_data[g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].sofar]);
//						USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);
						g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].sofar += todo;
						g_UsbHcdInfo[usb_ip_port].ep_tx_fifo_intr[ep_num-1] = KAL_TRUE;
						USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_TXCSR_TXPKTRDY);
					}
				}
				else if(g_UsbHcdInfo[usb_ip_port].ep_tx_flush_intr[ep_num-1] == KAL_TRUE)
				{
					g_UsbHcdInfo[usb_ip_port].ep_tx_flush_intr[ep_num-1] = KAL_FALSE;
				}
				else
				{
					USB_Dbg_Trace(USB_HCD_UNEXPECTED_TX_INTR,  0, 0);
				}
			}
		}
	}

	/* Check for Bulk RX interrupt */
	/* RX interrupt : 1.RxPktRdy is set, 2. RXSTALL is set */
	for(ep_num = 1; ep_num <= MAX_RX_EP_NUM; ep_num++)
	{
		if(IntrRx&(0x01<<ep_num))
{
			USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);
			RXCSR = USB_DRV_Reg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]));

			usb_ep_str.ep_num = ep_num;
			usb_ep_str.direction = USB_EP_RX_DIR;

			USB_Dbg_Trace(USB_HCD_EPN_RX_INTR,  ep_num, RXCSR);

			if((RXCSR&USB_RXCSR_RXSTALL) != 0)
			{
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_RX_EPN_STALL, ep_num);

				/* Stop running DMA */
				USB_HCD_DMA_Stop(usb_ip_port,ep_num, USB_EP_RX_DIR);

				RXCSR &= ~USB_RXCSR_RXSTALL;
				USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), RXCSR);

				if(g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1] != NULL)
					g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1](usb_ip_port,USB_HCD_STALL, (kal_uint32)USB_EP_RX_DIR);
			}
			else if((RXCSR&USB_RXCSR_ERROR) != 0)
			{
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_RX_EPN_ERROR, ep_num);

				/* Because of bad cable */
				/* Stop running DMA */
				USB_HCD_DMA_Stop(usb_ip_port,ep_num, USB_EP_RX_DIR);

				RXCSR &= ~USB_RXCSR_ERROR;
				USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), RXCSR);

				if(g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1] != NULL)
					g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1](usb_ip_port,USB_HCD_NO_RESPONSE, (kal_uint32)USB_EP_RX_DIR);
			}
			else if((RXCSR&USB_RXCSR_NAKTIMEOUT) != 0)
			{
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_RX_EPN_TIMEOUT, ep_num);

				/* Because of bad cable */
				/* Stop running DMA */
				USB_HCD_DMA_Stop(usb_ip_port,ep_num, USB_EP_RX_DIR);

				RXCSR &= ~(USB_RXCSR_NAKTIMEOUT|USB_RXCSR_REQPKT);
				USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), RXCSR);

				if(g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1] != NULL)
					g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1](usb_ip_port,USB_HCD_TIMEOUT, (kal_uint32)USB_EP_RX_DIR);
			}
			else if((RXCSR&USB_RXCSR_PIDERROR) != 0)
			{
					drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_RX_EPN_PID_ERROR, ep_num);		

					/* Stop running DMA */
					USB_HCD_DMA_Stop(usb_ip_port,ep_num, USB_EP_RX_DIR);
					
					RXCSR &= ~(USB_RXCSR_PIDERROR|USB_RXCSR_REQPKT);
					USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), RXCSR);
					
					if(g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1] != NULL)
						g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1](usb_ip_port,USB_HCD_PID_ERROR, (kal_uint32)USB_EP_RX_DIR);

			}			
			else if((RXCSR&USB_RXCSR_RXPKTRDY) != 0)
			{
				if(g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1] == NULL)
				ASSERT(0);
				
				todo = USB_HCD_EP_Rx_Pkt_Len(common_str,usb_ep_str);
				USB_HCD_EPFIFORead(common_str,usb_ep_str, todo, &g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].p_data[g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].sofar]);
				g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].sofar += todo;
				

				if((g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].data_length == g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].sofar)||(todo < g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].max_packet_size))
				{
					g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num -1](usb_ip_port,USB_HCD_OK, g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].sofar);
				}
				else
				{
					g_UsbHcdInfo[usb_ip_port].ep_rx_fifo_intr[ep_num-1] = KAL_TRUE;
					DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);
					DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_RXCSR_REQPKT);
				}

			}
			else
			{
				if(g_UsbHcdInfo[usb_ip_port].ep_rx_flush_intr[ep_num-1] == KAL_TRUE)
				{
					g_UsbHcdInfo[usb_ip_port].ep_rx_flush_intr[ep_num-1] = KAL_FALSE;
				}
				else
				{
					USB_Dbg_Trace(USB_HCD_UNEXPECTED_RX_INTR,  0, 0);
				}
			}
		}
	}

	/* A or B side plug out will both trigger this dis_conn interrupt */
	if((IntrUSB&USB_INTRUSB_DISCON) != 0)
	{
//		USB_DRV_WriteReg8(USB_INTRUSBE_HCD(USB_BaseAddr[usb_ip_port]), ~USB_INTRUSBE_SOF);
		USB_Dbg_Trace(USB_HCD_DISCONN,  USB_DRV_Reg8(USB_LINE_STATE), USB_DRV_Reg8(USB_OPSTATE_HCD(USB_BaseAddr[usb_ip_port])));
//		USB_Dbg_Trace(USB_HCD_DISCONN,  USB_DRV_Reg8(USB_DEVCTL),  0);
		drv_trace0(TRACE_FUNC, (kal_uint32)USB_HCD_DISCONN_INTR);
		USB_HCD_Disconn_Hdlr(usb_ip_port);
	}

	if((IntrUSB&USB_INTRUSB_SUSPEND) != 0)
	{

	}
}

DCL_STATUS DCL_USB_CTRL_API_USB_HCD_HISR(DCL_CTRL_DATA_T *data)
{
	USB_HCD_HISR();
	
	return STATUS_OK;
}

#if defined(__IC_USB_ENABLE__)


static void IC_USBDMA_HISR(void)
{
	kal_uint8  	DMAIntr;
	kal_uint32  index;
	kal_uint8 	usb_ip_port = ICUSB_PORT_1;  //IC USB Port
	
	DMAIntr = USB_DRV_Reg8(USB_DMAINTR_HCD(USB_BaseAddr[usb_ip_port]));

	while(DMAIntr != 0)
	{
		for(index = 0; index < ICUSB_MAX_DMA_NUM; index++)
		{
			if((DMAIntr&(1<<index)) != 0)
			{
				// write 0 clear first, then do call back function, order is very important !!!
				USB_DRV_WriteReg8(USB_DMAINTR_HCD(USB_BaseAddr[usb_ip_port]), ~(0x01<<index));

				/* DMA channel index+1 have interrupt */

				if(USB_DRV_Reg32((USB_DMA_REALCNT_HCD(USB_BaseAddr[usb_ip_port],index+1))) != 0)
				{
					if(g_UsbHcdInfo[usb_ip_port].dma_running[index] == KAL_TRUE)
					{
							USB_HCD_DMA_Callback(usb_ip_port,index+1);			
					}
					else
						ASSERT(0);
				}
				else
				{
					if(USB_Check_DMA_Time_Out(usb_ip_port,index+1) == KAL_TRUE)
					{
						if(g_UsbHcdInfo[usb_ip_port].dma_running[index] == KAL_TRUE)
						{
								USB_HCD_DMA_Callback(usb_ip_port,index+1);
						}
						else
							ASSERT(0);
					}
					else
					{
						ASSERT(0);
					}
				}
			}
		}

		/* Read register again to see if any interrupt is generated again */
		/* if pong pong buffer serve done, then we do call back function here */
		DMAIntr = USB_DRV_Reg8(USB_DMAINTR_HCD(USB_BaseAddr[usb_ip_port]));
	}

	IRQClearInt(IRQ_IC_USBDMA1_CODE);
	IRQUnmask(IRQ_IC_USBDMA1_CODE);
}


static void IC_USBDMA_LISR(void)
{
	kal_uint8  DMAIntr;
	kal_uint8 usb_ip_port = ICUSB_PORT_1;  //IC USB Port
	
	IRQMask(IRQ_IC_USBDMA1_CODE);
	drv_active_hisr(DRV_IC_USBDMA1_HISR_ID);
	DMAIntr = USB_DRV_Reg8(USB_DMAINTR_HCD(USB_BaseAddr[usb_ip_port]));
//	ICUSB_Dbg_Trace(IC_USB_DMA_LISR,  DMAIntr, 0);
	ASSERT(DMAIntr != 0);
}

static void IC_USB_LISR(void)
{
	IRQMask(IRQ_IC_USB1_CODE);

//	g_UsbHcdInfo[usb_ip_port].is_ProHISR = KAL_TRUE;
	drv_active_hisr(DRV_IC_USB1_HISR_ID);
}

static void IC_USB_HISR(void)
{
	kal_uint8   IntrUSB;
	kal_uint16  IntrTx;
	kal_uint16  IntrRx;
	kal_uint16  CSR0;
	kal_uint16  TXCSR;
	kal_uint16  RXCSR;
	kal_uint32  ep_num;
	kal_uint32  pkt_length;
	kal_uint16 todo;
	kal_bool	b_dev_unmask_irq = KAL_TRUE;
	kal_bool b_host_hisr_is_handled = KAL_FALSE;
	kal_uint8 usb_ip_port = ICUSB_PORT_1;  //IC USB Port
	USBH_Common_Struct common_str;
	USBH_EP_Struct usb_ep_str;
	common_str.usb_ip_port = usb_ip_port;

	
	// Read and clear!!
	IntrUSB = USB_DRV_Reg8(USB_INTRUSB_HCD(USB_BaseAddr[usb_ip_port]));
//	ICUSB_Dbg_Trace(IC_USB_DBG_HISR,  IntrUSB, USB_DRV_Reg8(USB_POWER_HCD(USB_BaseAddr[usb_ip_port])));
	IntrTx = USB_DRV_Reg(USB_INTRTX_HCD(USB_BaseAddr[usb_ip_port]));
	// Write 0 clear
	IntrRx = USB_DRV_Reg(USB_INTRRX_HCD(USB_BaseAddr[usb_ip_port]));
	USB_DRV_WriteReg(USB_INTRRX_HCD(USB_BaseAddr[usb_ip_port]), ~IntrRx);


	if(IntrUSB != 0)
	{
		b_host_hisr_is_handled = KAL_TRUE;
	}

	/* SRP detection, Only A-device */
	if((IntrUSB&USB_INTRUSB_SESSREQ) != 0)
	{
//		ASSERT(0);  // there should not have SRP detection  
	}

	/* VBUS error, A device only */
	if((IntrUSB&USB_INTRUSB_VBUSERROR) != 0)
	{
/* IP detect every 543ms, Vbus is still lower than 4.4V it will issue this intr and auto turn off Vbus */
//		USB_DRV_ClearBits8(USB_DEVCTL, USB_DEVCTL_SESSION);
// 		Power control by SIM Task , IC USB only notice SIM task

	}

	if((IntrUSB&USB_INTRUSB_RESUME) != 0)
	{
		// Remote wake up will be detected by EINT
//		USB_HCD_Resume(usb_ip_port);
		ASSERT(0);
	}

	if((IntrUSB&USB_INTRUSB_CONN) != 0)
	{
		/* plug out will both trigger this dis_conn interrupt */
		if((IntrUSB&USB_INTRUSB_DISCON) != 0)
		{
			ASSERT(0); // IC USB Cannot hot plug out
		}

		USB_Dbg_Trace(USB_HCD_CONN,  0, 0);
		drv_trace0(TRACE_FUNC, (kal_uint32)USB_HCD_CONN_INTR);
		USB_HCD_Conn_Hdlr(usb_ip_port);

		//QQ SW Work Around
//		USB_DRV_ClearBits8(USB_INTRUSBE_HCD(USB_BaseAddr[usb_ip_port]), USB_INTRUSBE_CONN);  // QQ SW : avoid Interrupt always trigger
//		USB_DRV_ClearBits8(USB_INTRUSBE_HCD(USB_BaseAddr[usb_ip_port]), USB_INTRUSBE_DISCON);  // QQ SW : avoid Interrupt always trigger				
	}

	if((IntrUSB&USB_INTRUSB_BABBLE) != 0)
	{
		USB_Dbg_Trace(USB_HCD_BABBLE,  0, 0);
		drv_trace0(TRACE_FUNC, (kal_uint32)USB_HCD_BABBLE_INTR);

		/* Close session */
		USB_DRV_ClearBits8(USB_DEVCTL_HCD(USB_BaseAddr[usb_ip_port]), USB_DEVCTL_SESSION);

		/* Disable all USB interrupts */
		USB_DRV_WriteReg8(USB_INTRUSBE_HCD(USB_BaseAddr[usb_ip_port]), 0x00);

		/* handle as disconnect intr to prevent upper laype still wait the events */
		USB_HCD_Disconn_Hdlr(usb_ip_port);

		ASSERT(0); //Debug	
		// 	IC USB only notice SIM task this serious error
		
	}

	/* Check for endpoint 0 interrupt */
	if(IntrTx&USB_INTRTX_EP0)
	{
		if(g_UsbHcdInfo[usb_ip_port].ep0_hdlr == NULL)
			ASSERT(0);

		USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), 0);
		CSR0 = USB_DRV_Reg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]));

		USB_Dbg_Trace(USB_HCD_EP0_INTR,  CSR0, 0);

		usb_ep_str.ep_num = 0;
		usb_ep_str.ep_type = USB_ENDPT_CTRL;

		if(CSR0&USB_CSR0_RXSTALL)
		{
			drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_TX_EPN_STALL, 0);

			g_UsbHcdInfo[usb_ip_port].ep0_fifo_intr = KAL_FALSE;
			g_UsbHcdInfo[usb_ip_port].ep0_setup = KAL_FALSE;
			g_UsbHcdInfo[usb_ip_port].ep0_status = KAL_FALSE;

			CSR0 &= ~USB_CSR0_RXSTALL;
			USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), CSR0);
			g_UsbHcdInfo[usb_ip_port].ep0_hdlr(usb_ip_port,USB_HCD_STALL, 0);
		}
		else if (CSR0&USB_CSR0_ERROR)
		{
			drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_TX_EPN_ERROR, 0);

			/* Bad cable */
			g_UsbHcdInfo[usb_ip_port].ep0_fifo_intr = KAL_FALSE;
			g_UsbHcdInfo[usb_ip_port].ep0_setup = KAL_FALSE;
			g_UsbHcdInfo[usb_ip_port].ep0_status = KAL_FALSE;

			USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), USB_CSR0_ERROR);
			USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), USB_CSR0_FLUSHFIFO);
			g_UsbHcdInfo[usb_ip_port].ep0_hdlr(usb_ip_port,USB_HCD_NO_RESPONSE, 0);
		}
		else if (CSR0&USB_CSR0_NAKTIMEOUT)
		{
			// QQ test  --> Host send more then 1 Setup packet & cause Device never response. Data sage may be IN or OUT.
			drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_TX_EPN_TIMEOUT, 0);
			USB_Dbg_Trace(USB_HCD_NAKTIMEOUT,  0, 0);
			
			g_UsbHcdInfo[usb_ip_port].ep0_fifo_intr = KAL_FALSE;
			g_UsbHcdInfo[usb_ip_port].ep0_setup = KAL_FALSE;
			g_UsbHcdInfo[usb_ip_port].ep0_status = KAL_FALSE;

			USB_DRV_WriteReg8(USB_NAKLIMIT0_HCD(USB_BaseAddr[usb_ip_port]),0x00); // QQ Test
			USB_DRV_ClearBits(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), USB_CSR0_NAKTIMEOUT);
			USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), USB_CSR0_FLUSHFIFO);
			g_UsbHcdInfo[usb_ip_port].ep0_hdlr(usb_ip_port,USB_HCD_TIMEOUT, 0);
		}
		else
		{
			USB_Dbg_Trace(USB_HCD_EP0_INTR,  (kal_uint32)g_UsbHcdInfo[usb_ip_port].ep0_setup, (kal_uint32)g_UsbHcdInfo[usb_ip_port].ep0_status);

			if(g_UsbHcdInfo[usb_ip_port].ep0_fifo_intr == KAL_TRUE)
			{
				g_UsbHcdInfo[usb_ip_port].ep0_fifo_intr = KAL_FALSE;

				if(g_UsbHcdInfo[usb_ip_port].ep0_setup == KAL_TRUE)
				{
					/* Setup and status packet must be single packet */
					g_UsbHcdInfo[usb_ip_port].ep0_setup = KAL_FALSE;

					if(CSR0&USB_CSR0_SETUPPKT)
					{
						CSR0 &= ~(USB_CSR0_SETUPPKT|USB_CSR0_TXPKTRDY);
						CSR0 |= USB_CSR0_FLUSHFIFO;
						USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), CSR0);
						g_UsbHcdInfo[usb_ip_port].ep0_hdlr(usb_ip_port,USB_HCD_NO_RESPONSE, 0);
					}
					else
					{
						g_UsbHcdInfo[usb_ip_port].ep0_hdlr(usb_ip_port,USB_HCD_OK, g_UsbHcdInfo[usb_ip_port].ep0_info.sofar);
					}
				}
				else if(g_UsbHcdInfo[usb_ip_port].ep0_status == KAL_TRUE)
				{
					g_UsbHcdInfo[usb_ip_port].ep0_status = KAL_FALSE;

					/* Clear status bit */
					USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), 0x00);
					g_UsbHcdInfo[usb_ip_port].ep0_hdlr(usb_ip_port,USB_HCD_OK, g_UsbHcdInfo[usb_ip_port].ep0_info.sofar);
				}
				else if(g_UsbHcdInfo[usb_ip_port].ep0_info.direction == USB_EP_RX_DIR)
				{
					/* Read the receive packet length */
					pkt_length = USB_HCD_EP0_Pkt_Len(common_str);

					if((g_UsbHcdInfo[usb_ip_port].ep0_info.sofar + pkt_length) > g_UsbHcdInfo[usb_ip_port].ep0_info.data_length)
					{
						pkt_length = g_UsbHcdInfo[usb_ip_port].ep0_info.data_length - g_UsbHcdInfo[usb_ip_port].ep0_info.sofar;
}

					USB_HCD_EPFIFORead(common_str,usb_ep_str, pkt_length, &g_UsbHcdInfo[usb_ip_port].ep0_info.p_data[g_UsbHcdInfo[usb_ip_port].ep0_info.sofar]);

					g_UsbHcdInfo[usb_ip_port].ep0_info.sofar += pkt_length;

					USB_Dbg_Trace(USB_HCD_EP0_Data,  (kal_uint32)g_UsbHcdInfo[usb_ip_port].ep0_info.sofar, (kal_uint32)g_UsbHcdInfo[usb_ip_port].ep0_info.data_length);

					CSR0 &= ~USB_CSR0_RXPKTRDY;  //QQ Test
					USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), CSR0);	// QQ Test	

						
					drv_trace2(TRACE_FUNC, (kal_uint32)USB_HCD_EP0,g_UsbHcdInfo[usb_ip_port].ep0_info.sofar, g_UsbHcdInfo[usb_ip_port].ep0_info.data_length);

					if((g_UsbHcdInfo[usb_ip_port].ep0_info.sofar == g_UsbHcdInfo[usb_ip_port].ep0_info.data_length)
						||(pkt_length < g_UsbHcdInfo[usb_ip_port].ep0_info.max_packet_size))
					{
						/* callback to USB stack */
				
//						drv_trace4(TRACE_FUNC, (kal_uint32)USB_HCD_EP0_RX,0,g_UsbHcdInfo[usb_ip_port].ep0_info.sofar, g_UsbHcdInfo[usb_ip_port].ep0_info.data_length,g_UsbHcdInfo[usb_ip_port].ep0_info.max_packet_size);
						g_UsbHcdInfo[usb_ip_port].ep0_hdlr(usb_ip_port,USB_HCD_OK, g_UsbHcdInfo[usb_ip_port].ep0_info.sofar);
					}
					else
					{
						/* Receive this pcket, and request for next packet */
						g_UsbHcdInfo[usb_ip_port].ep0_fifo_intr = KAL_TRUE;
						USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), (CSR0|USB_CSR0_REQPKT));
					}
				}
				else if(g_UsbHcdInfo[usb_ip_port].ep0_info.direction == USB_EP_TX_DIR)
				{				
					if((g_UsbHcdInfo[usb_ip_port].ep0_info.data_length-g_UsbHcdInfo[usb_ip_port].ep0_info.sofar)
						>g_UsbHcdInfo[usb_ip_port].ep0_info.max_packet_size)
						pkt_length = g_UsbHcdInfo[usb_ip_port].ep0_info.max_packet_size;
					else
						pkt_length = g_UsbHcdInfo[usb_ip_port].ep0_info.data_length-g_UsbHcdInfo[usb_ip_port].ep0_info.sofar;

					if (pkt_length == 0) //all data has already sent out
					{
						g_UsbHcdInfo[usb_ip_port].ep0_hdlr(usb_ip_port,USB_HCD_OK, g_UsbHcdInfo[usb_ip_port].ep0_info.sofar);
					}
					else
					{
						/* Write data packet to FIFO */
						USB_HCD_EPFIFOWrite(common_str,usb_ep_str, pkt_length, &g_UsbHcdInfo[usb_ip_port].ep0_info.p_data[g_UsbHcdInfo[usb_ip_port].ep0_info.sofar]);
						g_UsbHcdInfo[usb_ip_port].ep0_info.sofar += pkt_length;
						g_UsbHcdInfo[usb_ip_port].ep0_fifo_intr = KAL_TRUE;

						USB_Dbg_Trace(USB_HCD_EP0_Data,  (kal_uint32)g_UsbHcdInfo[usb_ip_port].ep0_info.sofar, (kal_uint32)g_UsbHcdInfo[usb_ip_port].ep0_info.data_length);

						USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), 0);
						USB_DRV_WriteReg(USB_CSR0_HCD(USB_BaseAddr[usb_ip_port]), USB_CSR0_TXPKTRDY);
					}

					USB_Dbg_Trace(USB_HCD_SEND_DATA_DONE,  ep_num, 0);
				}
			}
			else
			{
				USB_Dbg_Trace(USB_HCD_UNEXPECTED_EP0_INTR,  0, 0);
			}
		}
	}

	/* Check for Bulk TX interrupt */
	/* TX interrupt : 1.TxPktRdy is clear, 2. RXSTALL is set */
	for(ep_num = 1; ep_num <= MAX_TX_EP_NUM; ep_num++)
	{
		if (IntrTx&(0x01 <<ep_num))
		{
			USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);
			TXCSR = USB_DRV_Reg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]));

			USB_Dbg_Trace(USB_HCD_EPN_TX_INTR,  ep_num, TXCSR);

			if((TXCSR&USB_TXCSR_RXSTALL) != 0)
			{
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_TX_EPN_STALL, ep_num);

				g_UsbHcdInfo[usb_ip_port].ep_tx_fifo_intr[ep_num-1] = KAL_FALSE;

				/* Stop running DMA */
				USB_HCD_DMA_Stop(usb_ip_port,ep_num, USB_EP_TX_DIR);

				/* Clear RXSTALL bit */
				TXCSR &= ~USB_TXCSR_RXSTALL;
				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), TXCSR);

				if(g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1] != NULL)
					g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1](usb_ip_port,USB_HCD_STALL, (kal_uint32)USB_EP_TX_DIR);
			}
			else if((TXCSR&USB_TXCSR_ERROR) != 0)
			{
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_TX_EPN_ERROR, ep_num);

				g_UsbHcdInfo[usb_ip_port].ep_tx_fifo_intr[ep_num-1] = KAL_FALSE;

				/* Because of bad cable */
				/* Stop running DMA */
				USB_HCD_DMA_Stop(usb_ip_port,ep_num, USB_EP_TX_DIR);

				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_TXCSR_ERROR);
				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));

				g_UsbHcdInfo[usb_ip_port].ep_tx_flush_intr[ep_num-1] = KAL_TRUE;

				if(g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1] != NULL)
					g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1](usb_ip_port,USB_HCD_NO_RESPONSE, (kal_uint32)USB_EP_TX_DIR);
			}
			else if((TXCSR&USB_TXCSR_NAKTIMEOUT) != 0)
			{
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_TX_EPN_TIMEOUT, ep_num);

				g_UsbHcdInfo[usb_ip_port].ep_tx_fifo_intr[ep_num-1] = KAL_FALSE;

				/* Because of bad cable */
				/* Stop running DMA */
				USB_HCD_DMA_Stop(usb_ip_port,ep_num, USB_EP_TX_DIR);

				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_TXCSR_NAKTIMEOUT);
				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
				USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));

				g_UsbHcdInfo[usb_ip_port].ep_tx_flush_intr[ep_num-1] = KAL_TRUE;

				if(g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1] != NULL)
					g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1](usb_ip_port,USB_HCD_TIMEOUT, (kal_uint32)USB_EP_TX_DIR);
			}
			else
			{
				if(g_UsbHcdInfo[usb_ip_port].ep_tx_fifo_intr[ep_num-1] == KAL_TRUE)
				{
					g_UsbHcdInfo[usb_ip_port].ep_tx_fifo_intr[ep_num-1] = KAL_FALSE;

					if(g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].data_length == g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].sofar)
					{
						if(g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1] != NULL)
							g_UsbHcdInfo[usb_ip_port].ep_tx_hdlr[ep_num-1](usb_ip_port,USB_HCD_OK, g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].data_length);
					}
					else
					{
						if((g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].data_length-g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].sofar)
							>g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].max_packet_size)
							todo = g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].max_packet_size;
						else
							todo = g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].data_length-g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].sofar;

						/* Write data packet to FIFO */
						USB_HCD_EPFIFOWrite(common_str,usb_ep_str, todo, &g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].p_data[g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].sofar]);
//						USB_DRV_WriteReg8(USB_INDEX, ep_num);
						g_UsbHcdInfo[usb_ip_port].ep_tx_info[ep_num-1].sofar += todo;
						g_UsbHcdInfo[usb_ip_port].ep_tx_fifo_intr[ep_num-1] = KAL_TRUE;
						USB_DRV_WriteReg(USB_TXCSR_HCD(USB_BaseAddr[usb_ip_port]), USB_TXCSR_TXPKTRDY);
					}
				}
				else if(g_UsbHcdInfo[usb_ip_port].ep_tx_flush_intr[ep_num-1] == KAL_TRUE)
				{
					g_UsbHcdInfo[usb_ip_port].ep_tx_flush_intr[ep_num-1] = KAL_FALSE;
				}
				else
				{
					USB_Dbg_Trace(USB_HCD_UNEXPECTED_TX_INTR,  0, 0);
				}
			}
		}
	}

	/* Check for Bulk RX interrupt */
	/* RX interrupt : 1.RxPktRdy is set, 2. RXSTALL is set */
	for(ep_num = 1; ep_num <= MAX_RX_EP_NUM; ep_num++)
	{
		if(IntrRx&(0x01<<ep_num))
		{
			USB_DRV_WriteReg8(USB_INDEX_HCD(USB_BaseAddr[usb_ip_port]), ep_num);
			RXCSR = USB_DRV_Reg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]));

			USB_Dbg_Trace(USB_HCD_EPN_RX_INTR,  ep_num, RXCSR);

			if((RXCSR&USB_RXCSR_RXSTALL) != 0)
			{
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_RX_EPN_STALL, ep_num);

				/* Stop running DMA */
				USB_HCD_DMA_Stop(usb_ip_port,ep_num, USB_EP_RX_DIR);

				RXCSR &= ~USB_RXCSR_RXSTALL;
				USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), RXCSR);

				if(g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1] != NULL)
					g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1](usb_ip_port,USB_HCD_STALL, (kal_uint32)USB_EP_RX_DIR);
			}
			else if((RXCSR&USB_RXCSR_ERROR) != 0)
			{
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_RX_EPN_ERROR, ep_num);

				/* Because of bad cable */
				/* Stop running DMA */
				USB_HCD_DMA_Stop(usb_ip_port,ep_num, USB_EP_RX_DIR);

				RXCSR &= ~USB_RXCSR_ERROR;
				USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), RXCSR);

				if(g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1] != NULL)
					g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1](usb_ip_port,USB_HCD_NO_RESPONSE, (kal_uint32)USB_EP_RX_DIR);
			}
			else if((RXCSR&USB_RXCSR_NAKTIMEOUT) != 0)
			{
				drv_trace1(TRACE_FUNC, (kal_uint32)USB_HCD_RX_EPN_TIMEOUT, ep_num);

				/* Because of bad cable */
				/* Stop running DMA */
				USB_HCD_DMA_Stop(usb_ip_port,ep_num, USB_EP_RX_DIR);

				RXCSR &= ~(USB_RXCSR_NAKTIMEOUT|USB_RXCSR_REQPKT);
				USB_DRV_WriteReg(USB_RXCSR_HCD(USB_BaseAddr[usb_ip_port]), RXCSR);

				if(g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1] != NULL)
					g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1](usb_ip_port,USB_HCD_TIMEOUT, (kal_uint32)USB_EP_RX_DIR);
			}
			else if((RXCSR&USB_RXCSR_RXPKTRDY) != 0)
			{
				if(g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num-1] != NULL)
				{
					g_UsbHcdInfo[usb_ip_port].ep_rx_hdlr[ep_num -1](usb_ip_port,USB_HCD_OK, g_UsbHcdInfo[usb_ip_port].ep_rx_info[ep_num-1].sofar);
				}
				else
				{
					ASSERT(0);
				}
			}
			else
			{
				if(g_UsbHcdInfo[usb_ip_port].ep_rx_flush_intr[ep_num-1] == KAL_TRUE)
				{
					g_UsbHcdInfo[usb_ip_port].ep_rx_flush_intr[ep_num-1] = KAL_FALSE;
				}
				else
				{
					USB_Dbg_Trace(USB_HCD_UNEXPECTED_RX_INTR,  0, 0);
				}
			}
		}
	}

	/* A or B side plug out will both trigger this dis_conn interrupt */
	if((IntrUSB&USB_INTRUSB_DISCON) != 0)
	{
//		USB_DRV_WriteReg8(USB_INTRUSBE_HCD(USB_BaseAddr[usb_ip_port]), ~USB_INTRUSBE_SOF);
		USB_Dbg_Trace(USB_HCD_DISCONN,  0, USB_DRV_Reg8(USB_OPSTATE_HCD(USB_BaseAddr[usb_ip_port])));
		drv_trace0(TRACE_FUNC, (kal_uint32)USB_HCD_DISCONN_INTR);
		USB_HCD_Disconn_Hdlr(usb_ip_port);
	}

	b_dev_unmask_irq = USB_HCD_Get_UnMask_Irq(0);
	b_host_hisr_is_handled = KAL_TRUE;
	
	if((IntrUSB&USB_INTRUSB_DISCON) != 0)
	{
	}

	if((IntrUSB&USB_INTRUSB_SUSPEND) != 0)
	{
	}


	if((IntrUSB&USB_INTRUSB_SOF) != 0)
	{
	}

	if(b_host_hisr_is_handled == KAL_FALSE)
		EXT_ASSERT(0, USB_DRV_Reg(USB_INTRTX_HCD(USB_BaseAddr[usb_ip_port])), USB_DRV_Reg(USB_INTRRX_HCD(USB_BaseAddr[usb_ip_port])), 0);

	/* Clear interrupt and unmask interrupt */
   	IRQClearInt(IRQ_IC_USB1_CODE);
//   	g_UsbHcdInfo[usb_ip_port].is_ProHISR = KAL_FALSE;

	if((g_UsbHcdInfo[usb_ip_port].b_unmask_irq == KAL_TRUE)&&(b_dev_unmask_irq == KAL_TRUE))
	{
		IRQUnmask(IRQ_IC_USB1_CODE);
	}
	else
	{
//		USB_Dbg_Trace(USB_HCD_MASK_HISR,  (kal_uint32)g_UsbHcdInfo[usb_ip_port].b_unmask_irq, (kal_uint32)b_dev_unmask_irq);
	}		

}
#endif // IC USB 

//====================DCL API  =======================//
DCL_STATUS DCL_USB_CTRL_API_IC_USB_Drv_Create_ISR(DCL_CTRL_DATA_T *data)
{ 
#if defined(__IC_USB_ENABLE__)
	IRQ_Register_LISR(IRQ_IC_USB1_CODE, IC_USB_LISR,"ICUSB");
	DRV_Register_HISR(DRV_IC_USB1_HISR_ID, IC_USB_HISR);
#endif	
	return STATUS_OK;
}

DCL_STATUS DCL_USB_CTRL_API_IC_USB_Drv_Activate_ISR(DCL_CTRL_DATA_T *data)
{
#if defined(__IC_USB_ENABLE__)
	kal_uint8 usb_ip_port = ICUSB_PORT_1;  //IC USB Port
	
	g_UsbHcdInfo[usb_ip_port].b_unmask_irq = KAL_TRUE;	
	IRQSensitivity(IRQ_IC_USB1_CODE,LEVEL_SENSITIVE);
	IRQUnmask(IRQ_IC_USB1_CODE);
#endif	
	return STATUS_OK;
}

DCL_STATUS DCL_USB_CTRL_API_IC_USBDMA_Drv_Create_ISR(DCL_CTRL_DATA_T *data)
{
#if defined(__IC_USB_ENABLE__)
	IRQ_Register_LISR(IRQ_IC_USBDMA1_CODE, IC_USBDMA_LISR, "IC_USBDMA");
	DRV_Register_HISR(DRV_IC_USBDMA1_HISR_ID, IC_USBDMA_HISR);
#endif
	return STATUS_OK;
}


DCL_STATUS DCL_USB_CTRL_API_IC_USBDMA_Drv_Activate_ISR(DCL_CTRL_DATA_T *data)
{
#if defined(__IC_USB_ENABLE__)
	IRQSensitivity(IRQ_IC_USBDMA1_CODE, LEVEL_SENSITIVE);
	IRQUnmask(IRQ_IC_USBDMA1_CODE);	
#endif
	return STATUS_OK;
}

DCL_STATUS DCL_USB_CTRL_API_IC_USB_PDNmode(DCL_CTRL_DATA_T *data)
{
#if defined(__IC_USB_ENABLE__)
	USB_HCD_CTRL_SET_T *data;
	kal_bool	turn_off =&data->rHCD_Set;
		
#if defined(DRV_USB_IP_V3)

	if (turn_off == KAL_TRUE)
	{
		USB_DRV_ClearBits8(USB_U1PHYCR0_1, USB_U1PHYCR0_1_RG_USB11_FSLS_ENBGRI);
		USB_DRV_ClearBits8(0x610d0900,0x02);  // IC USB special clock source
	}
	else
	{
		USB_DRV_SetBits8(0x610d0320, 0x06);  //USB PDN : ICUSB & USB20
		USB_DRV_SetBits8(0x61140280, 0x80);  // UPLL CLock
		USB_DRV_SetBits8(0x610d0900,0x02);  // IC USB special clock source
		
		USB_DRV_ClearBits8(USB_U1PHYCR1_1, USB_U1PHYCR1_1_RG_USB11_USBRESERVED);  //switch to IC USB mode
		USB_DRV_SetBits8(USB_U1PHYCR0_1, USB_U1PHYCR0_1_RG_USB11_FSLS_ENBGRI);
	}
	
	return STATUS_OK;
#endif	
#endif
	return STATUS_INVALID_CMD;
}	




DCL_USB_CTRL_API DCL_USB_HCD_API_T[] =
{
	DCL_USB_CTRL_API_USB_HCD_HW_Mapping_EP,
	DCL_USB_CTRL_API_USB_HCD_Reset_Device,
	DCL_USB_CTRL_API_USB_HCD_SWRST,
	DCL_USB_CTRL_API_USB_HCD_EnSysIntr,
	DCL_USB_CTRL_API_USB_HCD_VBusEnable,
	DCL_USB_CTRL_API_USB_HCD_Host_Mode_Detect,
	DCL_USB_CTRL_API_USB_HCD_Is_HNP_SUPPORT,
	DCL_USB_CTRL_API_USB_HCD_Is_RemoteWakeup_SUPPORT,
	DCL_USB_CTRL_API_USB_HCD_Is_SRP_SUPPORT,
	DCL_USB_CTRL_API_USB_HCD_Is_High_Speed,
	DCL_USB_CTRL_API_USB_HCD_Reset_Resource,
	DCL_USB_CTRL_API_USB_HCD_Init_Drv_Info,
	DCL_USB_CTRL_API_USB_HCD_Release_Drv_Info,
	DCL_USB_CTRL_API_USB_HCD_Register_Drv_Info,
	DCL_USB_CTRL_API_USB_HCD_Set_UnMask_Irq,
	DCL_USB_CTRL_API_USB_HCD_Get_UnMask_Irq,
	DCL_USB_CTRL_API_USB_HCD_Dis_Attach,
	DCL_USB_CTRL_API_USB_HCD_En_Attach,
	DCL_USB_CTRL_API_USB_HCD_Initialize_Drv,
	DCL_USB_CTRL_API_USB_HCD_Release_Drv,
	DCL_USB_CTRL_API_USB_HCD_SetAddress,
	DCL_USB_CTRL_API_USB_HCD_Resume,
	DCL_USB_CTRL_API_USB_HCD_Suspend,
	DCL_USB_CTRL_API_USB_HCD_Delay_Reset_Device,
	DCL_USB_CTRL_API_USB_HCD_Set_EP_Max_Pkt,
	DCL_USB_CTRL_API_USB_HCD_Clear_Data01,
	DCL_USB_CTRL_API_USB_HCD_EP_Interval,
	DCL_USB_CTRL_API_USB_HCD_EP0En,
	DCL_USB_CTRL_API_USB_HCD_EP0_Data_Length,
	DCL_USB_CTRL_API_USB_HCD_EP_Rx_Pkt_Len,
	DCL_USB_CTRL_API_USB_HCD_Config_TxEP_Type,
	DCL_USB_CTRL_API_USB_HCD_TxEPInit,
	DCL_USB_CTRL_API_USB_HCD_Config_RxEP_Type,
	DCL_USB_CTRL_API_USB_HCD_RxEPInit,
	DCL_USB_CTRL_API_USB_HCD_TxEPEn,
	DCL_USB_CTRL_API_USB_HCD_RxEPEn,
	DCL_USB_CTRL_API_USB_HCD_TxEPDis,
	DCL_USB_CTRL_API_USB_HCD_RxEPDis,
	DCL_USB_CTRL_API_USB_HCD_Send_Resume,
	DCL_USB_CTRL_API_USB_HCD_Send_Suspend,
	DCL_USB_CTRL_API_USB_HCD_Send_Req,
	DCL_USB_CTRL_API_USB_HCD_Recv_Req,
	DCL_USB_CTRL_API_USB_HCD_EP0_Setup_Req,
	DCL_USB_CTRL_API_USB_HCD_EP0_Data_Req,
	DCL_USB_CTRL_API_USB_HCD_EP0_Status_Req,
	DCL_USB_CTRL_API_USB_HCD_Switch_DMA_Burst_mode,
	DCL_USB_CTRL_API_USB_HCD_Register_DMA_Channel,
	DCL_USB_CTRL_API_USB_HCD_Get_DMA_Real_Count,
	DCL_USB_CTRL_API_USB_HCD_Get_DMA_Channel,
	DCL_USB_CTRL_API_USB_HCD_Stop_DMA_Channel,
	DCL_USB_CTRL_API_USB_HCD_Free_DMA_Channel,
	DCL_USB_CTRL_API_USB_HCD_EPFIFORead,
	DCL_USB_CTRL_API_USB_HCD_EPFIFOWrite,
	DCL_USB_CTRL_API_USB_HCD_DMA_Setup,
	DCL_USB_CTRL_API_USB_HCD_Disconn_Hdlr,
	DCL_USB_CTRL_API_USB_HCD_Conn_Hdlr,
	DCL_USB_CTRL_API_USB_HCD_HISR,
	DCL_USB_CTRL_API_IC_USB_Drv_Create_ISR,
	DCL_USB_CTRL_API_IC_USB_Drv_Activate_ISR,
	DCL_USB_CTRL_API_IC_USBDMA_Drv_Create_ISR,
	DCL_USB_CTRL_API_IC_USBDMA_Drv_Activate_ISR,
	DCL_USB_CTRL_API_IC_USB_PDNmode,
	DCL_USB_CTRL_API_USB_HCD_VBUS_OFF
};


/*************************************************************************
* FUNCTION
*  DclUSB_HCD_Control
*
* DESCRIPTION
*  This function is to send command to control the USB host module.
*
* PARAMETERS
*  handle: A valid handle return by DclUSB_HCD_Open()
*  cmd: A control command for USB host module
// Should be added
*
*  data: The data of the control command
// Should be added
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
DCL_STATUS DclUSB_HCD_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	/* Check open or not and handle validity */
	if((g_USB_Hcd_Open == KAL_FALSE)||(DCL_USB_HCD_CHECK_HANDLE_IS_VALID(handle) == 0))
	{
		ASSERT(0);

		if(g_USB_Hcd_Open == KAL_FALSE)
			return STATUS_INVALID_OPERATION;
		else
			return STATUS_INVALID_DCL_HANDLE;
	}

	return DCL_USB_HCD_API_T[cmd](data);
}

#else

DCL_STATUS DclUSB_HCD_Initialize(void)
{
	return STATUS_OK;
}


DCL_HANDLE DclUSB_HCD_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	return (DCL_HANDLE)DCL_HANDLE_NONE;
}


DCL_STATUS DclUSB_HCD_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}


DCL_STATUS DclUSB_HCD_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}


DCL_STATUS DclUSB_HCD_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}


DCL_STATUS DclUSB_HCD_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_UNSUPPORTED;
}


DCL_STATUS DclUSB_HCD_Close(DCL_HANDLE handle)
{
	return STATUS_OK;
}


DCL_STATUS DclUSB_HCD_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	return STATUS_OK;
}

#endif	/* __OTG_ENABLE__ */

//#endif  /* DCL_USB_INTERFACE */

