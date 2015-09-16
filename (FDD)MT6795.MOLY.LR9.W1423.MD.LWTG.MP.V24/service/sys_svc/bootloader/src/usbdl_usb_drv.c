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
 *    usb_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements usb hardware related functions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef  __USB_DOWNLOAD__

#if defined(__USBDL_BOOTROM__)
#include "usbdl_bootrom.h"
#else
//#include "kal_non_specific_general_types.h"
#include "drvpdn.h"
//#include "kal_release.h"
#include "kal_public_api.h"
#include "drv_features.h"

#include "drv_comm.h"
#include "reg_base.h"
//#include "config_hw.h"
#include "init.h"
//#include "gpio_sw.h"
#include "usb_hw.h"
#include "usbdl_usb_drv.h"
#include "usb_drv_pri.h"
#include "usb_custom.h"
//#include "usb_comm.h"
#include "wdt_hw.h"
#endif

/* usb driver information*/
USB_Drv_Info g_UsbDrvInfo;

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
/* EP0's FIFO address is fixed from 0~63 */
static kal_uint32 g_FIFOadd = USB_FIFO_START_ADDRESS;
#endif


#if !defined(__USBDL_BOOTROM__)
static kal_uint32 g_usb_pdn_owner = 0;
//static void USB_EnSysIntr(void);
extern void DRVPDN_ON(kal_uint32 addr,kal_uint16 code,PDN_DEVICE hanlde);
extern void USBDL_CLK_ON(kal_bool turn_on);
#endif

//for holding mode
extern const kal_bool usbdl_holding_mode;
extern kal_bool USBDL_WDTKICK;
#define WDT_Restart()  DRV_WriteReg(WDT_RESTART,WDT_RESTART_KEY)

/************************************************************
	driver debug utility
*************************************************************/
static void USB_EP_Check(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_uint32 line)
{
	if((ep_num == 0)||((direction == USB_EP_TX_DIR)&&(ep_num > MAX_TX_EP_NUM))||
		((direction == USB_EP_RX_DIR)&&(ep_num > MAX_RX_EP_NUM)))
	{
		EXT_ASSERT(0, ep_num, (kal_uint32)direction, line);
	}
}


/************************************************************
	driver info functions
*************************************************************/

/* initialize usb driver information, called at USB_Init() */
void USB_Init_Drv_Info(kal_bool is_ft_mode)
{
	kal_uint32 index;


	g_UsbDrvInfo.power_state = USB_STATE_NORMAL;
//	g_UsbDrvInfo.is_unMaskUSB = KAL_TRUE;
//	g_UsbDrvInfo.is_ProUSBHISR = KAL_FALSE;
	g_UsbDrvInfo.reset_hdlr = NULL;
	g_UsbDrvInfo.ep0_hdlr = NULL;

	for(index = 0; index < MAX_TX_EP_NUM; index++)
	{
		g_UsbDrvInfo.ep_tx_hdlr[index] = NULL;
		g_UsbDrvInfo.ep_tx_stall_status[index] = KAL_FALSE;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
		g_UsbDrvInfo.dma_port[USB_EP_TX_DIR][index] = 0;
#endif
	}

	for(index = 0; index < MAX_RX_EP_NUM; index++)
	{
		g_UsbDrvInfo.ep_rx_hdlr[index] = NULL;
		g_UsbDrvInfo.ep_rx_stall_status[index] = KAL_FALSE;
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
		g_UsbDrvInfo.dma_port[USB_EP_RX_DIR][index] = 0;
#endif
	}
#if defined(DRV_USB_IP_V2)
	/* dma and fast mode sequence parametes */
	g_UsbDrvInfo.dma_tx_ep = 0;
	g_UsbDrvInfo.dma_res_tx_ep = 0;
	g_UsbDrvInfo.fast_mode_tx_ep = 0;

	/* Error record */
	g_UsbDrvInfo.error_count = 0;
	g_UsbDrvInfo.error_reason = 0;
	g_UsbDrvInfo.fm_error_reason = 0;

	/* BDT */
	WRITE_EP0_BDT(USB_BDT_RX, USB_BDT_EVEN, (USB_BDT_PTR)USB_BDT_RX0_EVEN);
	WRITE_EP0_BDT(USB_BDT_RX, USB_BDT_ODD, (USB_BDT_PTR)USB_BDT_RX0_ODD);
	WRITE_EP0_BDT(USB_BDT_TX, USB_BDT_EVEN, (USB_BDT_PTR)USB_BDT_TX0_EVEN);
	WRITE_EP0_BDT(USB_BDT_TX, USB_BDT_ODD, (USB_BDT_PTR)USB_BDT_TX0_ODD);
	WRITE_EPN_BDT(1, USB_BDT_RX, (USB_BDT_PTR)USB_BDT_RX1);
	WRITE_EPN_BDT(1, USB_BDT_TX, (USB_BDT_PTR)USB_BDT_TX1);
	WRITE_EPN_BDT(2, USB_BDT_RX, (USB_BDT_PTR)USB_BDT_RX2);
	WRITE_EPN_BDT(2, USB_BDT_TX, (USB_BDT_PTR)USB_BDT_TX2);
	WRITE_EPN_BDT(3, USB_BDT_RX, (USB_BDT_PTR)USB_BDT_RX3);
	WRITE_EPN_BDT(3, USB_BDT_TX, (USB_BDT_PTR)USB_BDT_TX3);

	/* EP0 parametes */
	g_UsbDrvInfo.ep0_rx_even_odd = 0;
	g_UsbDrvInfo.ep0_tx_even_odd = 0;
	g_UsbDrvInfo.ep0_current_dir = 0;
	g_UsbDrvInfo.ep0_tx_data01 = 0;
	g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_NONE;

	/* EPn parametes */
	for(index = 0; index < MAX_TX_EP_NUM; index++)
	{
		g_UsbDrvInfo.ep_tx_enb_state[index] = USB_EP_STATE_DISABLE;
		g_UsbDrvInfo.ep_tx_max_data_size[index] = 0;
		g_UsbDrvInfo.ep_tx_data01[index] = 0;
	}

	for(index = 0; index < MAX_RX_EP_NUM; index++)
	{
		g_UsbDrvInfo.ep_rx_enb_state[index] = USB_EP_STATE_DISABLE;
		g_UsbDrvInfo.ep_rx_max_data_size[index] = 0;
		g_UsbDrvInfo.ep_rx_data01[index] = 0;
	}
#endif
}

void USB_ResetDrv_Info(void)
{
	kal_uint32 index;


	g_UsbDrvInfo.power_state = USB_STATE_NORMAL;
//	g_UsbDrvInfo.is_unMaskUSB = KAL_TRUE;
//	g_UsbDrvInfo.is_ProUSBHISR = KAL_FALSE;

	for(index = 0; index < MAX_TX_EP_NUM; index++)
	{
		g_UsbDrvInfo.ep_tx_stall_status[index] = KAL_FALSE;
	}

	for(index = 0; index < MAX_RX_EP_NUM; index++)
	{
		g_UsbDrvInfo.ep_rx_stall_status[index] = KAL_FALSE;
	}

	//clear interrupt. write 0 clear
#if defined(DRV_USB_IP_V4)
	DRV_WriteReg8(USB_DMA_INTR_STATUS, 0xFF);
#elif defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	DRV_WriteReg32(USB_DMAINTR, 0x00);
#endif

#if defined(DRV_USB_IP_V2)
	/* dma and fast mode sequence parametes */
	g_UsbDrvInfo.dma_tx_ep = 0;
	g_UsbDrvInfo.dma_res_tx_ep = 0;
	g_UsbDrvInfo.fast_mode_tx_ep = 0;

	/* Error record */
	g_UsbDrvInfo.error_count = 0;
	g_UsbDrvInfo.error_reason = 0;
	g_UsbDrvInfo.fm_error_reason = 0;

	/* EP0 parametes */
	g_UsbDrvInfo.ep0_rx_even_odd = 0;
	g_UsbDrvInfo.ep0_tx_even_odd = 0;
	g_UsbDrvInfo.ep0_current_dir = 0;
	g_UsbDrvInfo.ep0_tx_data01 = 0;
	g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_NONE;

	/* EPn parametes */
	for(index = 0; index < MAX_TX_EP_NUM; index++)
	{
		g_UsbDrvInfo.ep_tx_enb_state[index] = USB_EP_STATE_DISABLE;
		g_UsbDrvInfo.ep_tx_max_data_size[index] = 0;
		g_UsbDrvInfo.ep_tx_data01[index] = 0;
	}

	for(index = 0; index < MAX_RX_EP_NUM; index++)
	{
		g_UsbDrvInfo.ep_rx_enb_state[index] = USB_EP_STATE_DISABLE;
		g_UsbDrvInfo.ep_rx_max_data_size[index] = 0;
		g_UsbDrvInfo.ep_rx_data01[index] = 0;
	}
#endif
}

/* register interrupt handler*/
void USB_Register_Drv_Info(USB_DRV_HDLR_TYPE type, kal_uint32 ep_num, usb_drv_intr_handler_ptr hdlr)
{
	switch(type)
	{
	case USB_DRV_HDLR_RESET:
		g_UsbDrvInfo.reset_hdlr = hdlr;
		break;
	case USB_DRV_HDLR_EP0:
		g_UsbDrvInfo.ep0_hdlr = hdlr;
		break;
	case USB_DRV_HDLR_EP_TX:
		USB_EP_Check(ep_num, USB_EP_TX_DIR, __LINE__);
		g_UsbDrvInfo.ep_tx_hdlr[ep_num-1]= hdlr;
		break;
	case USB_DRV_HDLR_EP_RX:
		USB_EP_Check(ep_num, USB_EP_RX_DIR, __LINE__);
		g_UsbDrvInfo.ep_rx_hdlr[ep_num-1]= hdlr;
		break;	
	}
}


/* get stall status for endpoint */
kal_bool USB_Get_EP_Stall_Status(kal_uint8 ep_num, USB_EP_DIRECTION direction)
{
	USB_EP_Check(ep_num, direction, __LINE__);
	
	if(direction == USB_EP_TX_DIR)
	{
		return g_UsbDrvInfo.ep_tx_stall_status[ep_num-1];
	}
	else
	{
		return g_UsbDrvInfo.ep_rx_stall_status[ep_num-1];
	}
}

/************************************************************
	system ctrl functions
*************************************************************/
#if !defined(__USBDL_BOOTROM__)


/* USB PDN disable, other modules may need USB PDN*/
void USB_PDNDisable(USB_PDN_OWNER owner)
{
	kal_uint32 savedMask;
	kal_bool enable_power = KAL_FALSE;


	savedMask = SaveAndSetIRQMask();   
	if(g_usb_pdn_owner == 0)
	{
		enable_power = KAL_TRUE;
	}
	g_usb_pdn_owner |= (1<<owner);    
	RestoreIRQMask(savedMask);

	if(enable_power == KAL_TRUE)
	{
	#if defined(__OLD_PDN_ARCH__)
		#if defined(__OLD_PDN_DEFINE__)
		USB_DRV_WriteReg(DRVPDN_CON0_CLR, DRVPDN_CON0_USB);
		#elif defined(__CLKG_DEFINE__)
		USB_DRV_WriteReg(CG_CLR0, CG_CON0_USB);
		#endif
	#else
		DRVPDN_Disable(PDN_USB);
	#endif
	}
}

#endif


void USBDL_USBPowerON(kal_bool power_on)
{
	volatile kal_uint32 delay;
	volatile kal_uint8 IntrUSB;
	volatile kal_uint16 IntrTx;
	volatile kal_uint16 IntrRx;
	
	

if (power_on)
{
    USBDL_CLK_ON(KAL_TRUE);

    // USB power up 
    USB_PDNDisable(USB_PDN_OWNER_USB);

#if (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	// clear interrupt before previous power down PDN, the interrupts are read then clear
	IntrUSB = DRV_Reg8(USB_INTRUSB);
	IntrUSB = DRV_Reg8(USB_INTRIN1);
	IntrUSB = DRV_Reg8(USB_INTROUT1);	
	#if (defined(DRV_USB_PHY_U65_IP)) //MT6251 = MAC (IP_Plus) + PHY (unit PHY IP)
		DRV_SetBits8(USB_U1PHYCR1_1, USB_U1PHYCR1_1_RG_USB11_USBRESERVED); // USB PHY switch to USB1.1
		DRV_ClearBits8(USB_U1PHYCR1_1, USB_U1PHYCR1_1_RG_USB11_USBRESERVED_PMU); // USB PHY switch : turn off PMU
		DRV_SetBits8(USB_U1PHYCR0_1, USB_U1PHYCR0_1_RG_USB11_FSLS_ENBGRI); // USB PHY BIAS Current control
	#elif (defined(DRV_USB_PHY_T55_IP))
		USB_DRV_ClearBits32(USB_U1PHYCR1, U1PHYCR1_RG_USB11_PHY_REV_7);
		USB_DRV_SetBits32(USB_U1PHYCR0, U1PHYCR0_RG_USB11_FSLS_ENBGRI);  
		for(delay = 0; delay < 1000; delay++);	  	
	#else
		DRV_WriteReg8(USB_ENABLE, USB_ENABLE_EN);
	#endif
#elif defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)

	USB_PowerControl(KAL_TRUE);
	
#if (defined(__USB_AND_UART_WITH_ONE_GPIO__)||defined(__USB_AND_UART_WITH_ONE_PORT__))
	USB_UART_Share(KAL_TRUE);
#endif 

#ifdef DRV_USB_PHY_COST_DOWN  //focus on PHY setting

	DRV_WriteReg8(USB_PHYCR3_2, USB_PHY_CLEAR_MASK); //QQ
#if defined(DRV_MT6236_VERSION)
	DRV_WriteReg8(USB_PHYCR5_3, USB_PHYCR5_3_SUSPENDM); 
#else
	DRV_WriteReg8(USB_PHYCR5_3, USB_PHY_CLEAR_MASK); 	
#endif
	DRV_WriteReg8(USB_PHYCR4_0, USB_PHYCR4_0_FORCE_USB_CLKOFF);
	DRV_WriteReg8(USB_PHYCR3_3, USB_PHY_CLEAR_MASK);
//==================

	for(delay = 0; delay < 1000; delay++);	
		
	DRV_WriteReg8(USB_PHYCR1_0, (USB_PHYCR1_0_IADJ_MASK2|USB_PHYCR1_0_BGR_CHIP_EN));//BGI enable
	
#if defined(DRV_USB_PHY_65_INITIAL_VALUE) //6268 MP		
	DRV_WriteReg8(USB_PHYCR1_2, USB_PHYCR1_2_RG_PLL_DIV); 
			
#elif defined(DRV_USB_PHY_M110_INITIAL_VALUE) //6253

#if defined(DRV_MT6253_VERSION_CONTROL) //6253 MP
	if (INT_ecoVersion() < ECO_E5)  /*E2, E3, E4*/
	{
		DRV_WriteReg8(USB_PHYCR1_2, USB_PHYCR1_2_RG_PLL_DIV2); 
	}
	else
#endif		
	{
		DRV_WriteReg8(USB_PHYCR1_2, USB_PHYCR1_2_RG_PLL_DIV3); 
	}
#endif

	for(delay = 0; delay < 1000; delay++);
	DRV_WriteReg8(USB_PHYCR2_3, USB_PHYCR2_3_PLL_EN);//PLL enable
		
	//========initial value=======//		

#if defined(DRV_MT6253_VERSION_CONTROL) //6253 MP
	if (INT_ecoVersion() == ECO_E8)  /*E8*/
		DRV_WriteReg8(USB_PHYCR3_0, (USB_PHYCR3_0_CDR_FILT));	
	else
		DRV_WriteReg8(USB_PHYCR3_0, (USB_PHYCR3_0_HS_TX_ANA_SER_EN|USB_PHYCR3_0_CDR_FILT));	
#else
	DRV_WriteReg8(USB_PHYCR3_0, (USB_PHYCR3_0_HS_TX_ANA_SER_EN|USB_PHYCR3_0_CDR_FILT));	
#endif		

	DRV_WriteReg8(USB_PHYIR4_2, (USB_PHYIR4_2_RG_HSTX_DBIST0|USB_PHYIR4_2_RG_HSTX_SRCTRL0));
	DRV_WriteReg8(USB_PHYIR1_1, USB_PHYIR1_1_RG_DM1_ABIST_SELE);
	DRV_WriteReg8(USB_PHYIR5_1, USB_PHYIR5_1_RG_SQTH0);	
				
#if defined(DRV_USB_PHY_65_INITIAL_VALUE) //6268 MP		
		DRV_ClearBits8(USB_PHYIR4_3, 0x01); // bit[1:0] = 2'b 10 
		DRV_SetBits8(USB_PHYIR4_3, USB_PHYIR4_3_RG_DISCD);//Host mode
		
//MT6268  remove Vbus  resistor only for Device mode
#ifndef __OTG_ENABLE__
	DRV_WriteReg8(USB_PHYCR4_0, 0x3F);//Device mode [60C] = 0x3F
		DRV_ClearBits8(USB_PHYIR3_2, 0x1F); //bit[4:0] = 0x1D;
		DRV_SetBits8(USB_PHYIR3_2, 0x1D); //Device mode [61E] = 0xFD
#endif		
		
#elif defined(DRV_USB_PHY_M110_INITIAL_VALUE) //6253 MP
	// VRT voltage threshold 
		DRV_ClearBits8(USB_PHYCR1_0, USB_PHYCR1_0_IADJ_MASK);
		DRV_SetBits8(USB_PHYCR1_0, USB_PHYCR1_0_IADJ_MASK3);
		DRV_ClearBits8(USB_PHYIR4_0, USB_PHYIR4_0_HS_TERMC_MASK);
		DRV_SetBits8(USB_PHYIR4_0, USB_PHYIR4_0_RG_CALIB_SELE0);
#endif
	
	DRV_WriteReg8(USB_PHYIR6_0, USB_PHY_CLEAR_MASK);//remove DM 100K (UART function)	
	
	DRV_WriteReg8(USB_PHYIR6_1, (USB_PHYIR6_1_BGR_DIV_L|USB_PHYIR6_1_RG_OTG_VBUSTH|USB_PHYIR6_1_VBUSCMP_EN)); //Vbus_Cmp_Enable
	

	
#elif (defined(DRV_USB_PHY_U65_IP))  

	DRV_WriteReg8(USB_U2PHYDCR1_2,USB_U2PHYDCR1_2_RG_USB_CLKEN);
	
//========initial value ======
	DRV_ClearBits8(USB_U2PHYDCR0_0,USB_U2PHYDCR0_0_RG_EARLY_HSTX_I);
	DRV_SetBits8(USB_U2PHYDCR0_0,USB_U2PHYDCR0_0_RG_HSTX_ANA_SER_EN);
	
	DRV_ClearBits8(USB_U2PHYACR3_3,USB_U2PHYACR3_3_RG_USBRESERVED);
	
	DRV_ClearBits8(USB_U2PHYACR3_2,USB_U2PHYACR3_2_RG_USBRESERVED_10);
	DRV_WriteReg8(USB_U2PHYACR1_1,((DRV_Reg8(USB_U2PHYACR1_1)& 0xF8)|USB_U2PHYACR1_1_RG_HSTX_SRCTRL));
	DRV_WriteReg8(USB_U2PHYACR0_0,((DRV_Reg8(USB_U2PHYACR0_0)& 0xF0)|USB_U2PHYACR0_0_RG_LS_CROSS|USB_U2PHYACR0_0_RG_FS_CROSS));
	
	DRV_WriteReg8(USB_U2PHYACR2_0,((DRV_Reg8(USB_U2PHYACR2_0)& 0xF8)|USB_U2PHYACR2_0_RG_SQTH));
	DRV_WriteReg8(USB_U2PHYACR2_0,((DRV_Reg8(USB_U2PHYACR2_0)& 0x0F)|USB_U2PHYACR2_0_RG_SQB|USB_U2PHYACR2_0_RG_RCVB));	

	DRV_WriteReg8(USB_U2PHYACR1_2,((DRV_Reg8(USB_U2PHYACR1_2)& 0xFC)|USB_U2PHYACR1_2_RG_DISCD));
				
	DRV_WriteReg8(USB_U2PHYAC0_2,((DRV_Reg8(USB_U2PHYAC0_2)& 0xC0)|USB_U2PHYAC0_2_RG_PLL_DIV));

	//remove 100K
	DRV_WriteReg8(USB_U2PHYDCR1_2,USB_U2PHYDCR1_2_RG_USB_CLKEN);
	DRV_WriteReg8(USB_U2PHYDTM0_2,0x00);
	DRV_ClearBits8(USB_U2PHYACR2_3,USB_U2PHYACR2_3_RG_DM_100K_EN);
	DRV_ClearBits8(USB_U2PHYACR2_3,USB_U2PHYACR2_3_RG_DP_100K_EN);
	
//	USB_DRV_WriteReg8(USB_U2PHYDTM0_0,USB_U2PHYDTM0_0_RG_SUSPENDM|USB_U2PHYDTM0_0_RG_TERMSEL|USB_U2PHYDTM0_0_RG_OPMODE);
//	USB_DRV_WriteReg8(USB_U2PHYDTM0_1,USB_U2PHYDTM0_1_UTMI_MUSEL);
	//====================

	DRV_ClearBits8(USB_U2PHYDTM0_2,USB_U2PHYDTM0_2_FORCE_SUSPENDM);
	
	for(delay = 0; delay < 1000; delay++);
			
	DRV_SetBits8(USB_U2PHYAC0_0,(USB_U2PHYAC0_0_RG_BGR_CHP_EN|USB_U2PHYAC0_0_RG_BGR_ISRC_EN|USB_U2PHYAC0_0_RG_BGR_BGR_EN));

	for(delay = 0; delay < 1500; delay++);

//	DRV_WriteReg8(USB_U2PHYACR2_3,(DRV_Reg8(USB_U2PHYACR2_3)|USB_U2PHYACR2_3_RG_OTG_VBUSCMP_EN));
	DRV_SetBits8(USB_U2PHYACR2_3,USB_U2PHYACR2_3_RG_OTG_VBUSCMP_EN);


#elif (defined(DRV_USB_PHY_U40_IP))

#elif (defined(DRV_USB_PHY_M60_IP))
     USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_uart_en);
     USB_DRV_ClearBits32(USB_U2PHYDTM1, USB_U2PHYDTM1_RG_UART_EN);
     USB_DRV_ClearBits32(USB_U2PHYACR3, USB_U2PHYACR3_RG_USB20_PHY_REV_7);
     USB_DRV_WriteReg32(USB_U2PHYAC0, (USB_DRV_Reg32(USB_U2PHYAC0)&~USB_U2PHYAC0_RG_USB20_USBPLL_FBDIV_6_0_CLR)|USB_U2PHYAC0_RG_USB20_USBPLL_FBDIV_6_0);
     USB_DRV_SetBits32(USB_U2PHYAC0, USB_U2PHYAC0_RG_USB20_INTR_EN);	 	 
     USB_DRV_ClearBits32(USB_U2PHYACR4, USB_U2PHYACR4_RG_USB20_DP_100K_EN);
     USB_DRV_ClearBits32(USB_U2PHYACR4, USB_U2PHYACR4_RG_USB20_DM_100K_EN);
     USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_suspendm);	 	 
     USB_DRV_SetBits32(USB_U2PHYACR2, USB_U2PHYACR2_RG_USB20_OTG_VBUSCMP_EN);
     for(delay = 0; delay < 10000; delay++);

     USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_uart_en);
     USB_DRV_ClearBits32(USB_U2PHYDTM1, USB_U2PHYDTM1_RG_UART_EN);
     USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_suspendm);
     USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_RG_DPPULLDOWN);
     USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_RG_DMPULLDOWN);
     USB_DRV_WriteReg32(USB_U2PHYDTM0, (USB_DRV_Reg32(USB_U2PHYDTM0)&~USB_U2PHYDTM0_RG_XCVRSEL_1_0_CLR));
     USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_RG_TERMSEL);
     USB_DRV_WriteReg32(USB_U2PHYDTM0, (USB_DRV_Reg32(USB_U2PHYDTM0)&~USB_U2PHYDTM0_RG_DATAIN_3_0_CLR));
     USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_dp_pulldown);
     USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_dm_pulldown);
     USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_xcvrsel);
     USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_termsel);
     USB_DRV_ClearBits32(USB_U2PHYDTM0, USB_U2PHYDTM0_force_datain);
     USB_DRV_ClearBits32(USB_U2PHYACR3, USB_U2PHYACR3_RG_USB20_PHY_REV_7);
     USB_DRV_SetBits32(USB_U2PHYACR2, USB_U2PHYACR2_RG_USB20_OTG_VBUSCMP_EN);
     for(delay = 0; delay < 10000; delay++);
     #ifdef MT6255
     USB_DRV_WriteReg(USB_U2PHYDTM1, 0x3c2c);		//only for MT6255
     for(delay = 0; delay < 10000; delay++);
     #endif

#else
	
	#if defined(DRV_USB_PHY_SUPPORT_OTG)
		/* Only for 38 E2 and after chip */
		DRV_WriteReg8(USB_PHYCR2_3, DRV_Reg8(USB_PHYCR2_3)&~USB_PHYCR2_3_HS_TERMC_MASK);
		DRV_WriteReg8(USB_PHYCR3_0, DRV_Reg8(USB_PHYCR3_0)&~USB_PHYCR3_0_IADJ_MASK);

		DRV_WriteReg8(USB_PHYCR1_1, DRV_Reg8(USB_PHYCR1_1)&~USB_PHYCR1_1_PLL_CCP_MASK);
		DRV_WriteReg8(USB_PHYCR1_1, DRV_Reg8(USB_PHYCR1_1)|USB_PHYCR1_1_PLL_CCP_SET);

		DRV_WriteReg8(USB_PHYCR3_2, DRV_Reg8(USB_PHYCR3_2)&~USB_PHYCR3_2_TEST_CTRL_MASK);
		DRV_WriteReg8(USB_PHYCR3_2, DRV_Reg8(USB_PHYCR3_2)|USB_PHYCR3_2_TEST_CTRL2_SET);
	#else
		/* MT6235 Reset VBUSCMP_EN, its reset value is 1 */
		DRV_WriteReg8(USB_PHYCR5_0, DRV_Reg8(USB_PHYCR5_0)&~USB_PHYCR5_0_VBUSCMP_EN);
	#endif

	DRV_WriteReg8(USB_PHYCR1_2, DRV_Reg8(USB_PHYCR1_2)|USB_PHYCR1_2_PLL_VCOG_H);

	#if defined(DRV_USB_PHY_SUPPORT_OTG)
		DRV_WriteReg8(USB_PHYCR4_1, DRV_Reg8(USB_PHYCR4_1)|USB_PHYCR4_1_FORCE_BGR_ON);
	#else	
		// For MT6235 only
		DRV_WriteReg8(USB_PHYIR1_0, DRV_Reg8(USB_PHYIR1_0)|USB_PHYIR1_0_DRVVBUS);
		DRV_WriteReg8(USB_PHYCR2_3, DRV_Reg8(USB_PHYCR2_3)|USB_PHYCR2_3_FORCE_DRV_VBUS);
		DRV_WriteReg8(USB_PHYCR5_0, DRV_Reg8(USB_PHYCR5_0)|USB_PHYCR5_0_VBUSCMP_EN);
	#endif

	for(delay = 0; delay < 1000; delay++)  ;

	DRV_WriteReg8(USB_PHYCR5_2, DRV_Reg8(USB_PHYCR5_2)&~USB_PHYCR5_2_FORCE_SUSPENDM);

	for(delay = 0; delay < 1000; delay++)  ;

	DRV_WriteReg8(USB_PHYCR1_0, DRV_Reg8(USB_PHYCR1_0)|USB_PHYCR1_0_PLL_EN);

#endif
	DRV_Reg8(USB_INTRUSB);
	IntrUSB = USB_DRV_Reg8(USB_INTRUSB);
	#if defined(DRV_USB_IP_V4)
	USB_DRV_WriteReg8(USB_INTRUSB, IntrUSB);
	#endif
	
	// Write 1 clear
	IntrTx = USB_DRV_Reg(USB_INTRTX);
	USB_DRV_WriteReg(USB_INTRTX, IntrTx);
	
	#if defined(DRV_USB_IP_V4)
	USB_DRV_WriteReg(USB_INTRRX, 0xFFFF); // write 1 clear
	#else
	USB_DRV_WriteReg(USB_INTRRX, 0); // write 0 clear
	#endif
	
	DRV_WriteReg8(USB_DEVCTL, 0x00);
#endif  //USB IP V3
	}
	else  //power off
	{
	#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
		DRV_WriteReg8(USB_POWER, (DRV_Reg8(USB_POWER)&(~USB_POWER_SOFTCONN)));

		DRV_WriteReg(USB_INTRTXE, 0);
		DRV_WriteReg(USB_INTRRXE, 0);
		DRV_WriteReg8(USB_INTRUSBE, 0);

		DRV_Reg8(USB_INTRUSB);
		DRV_Reg(USB_INTRTX);
		// write 0 clear
		DRV_WriteReg(USB_INTRRX, 0);
		
		#if (defined(__USB_AND_UART_WITH_ONE_GPIO__)||defined(__USB_AND_UART_WITH_ONE_PORT__))
			USB_UART_Share(KAL_FALSE);
		#endif 
		USB_PowerControl(KAL_FALSE);
		
	#else  //USB IP V2 & V1
		/* disable sequence:1. GPIO(D+), 2. USB(USB register), 3. PDN_USB(USB power), 4. UPLL */
		USB_PowerControl(KAL_FALSE);

		#if defined(DRV_USB_IP_V2)
		DRV_WriteReg8(USB_CTL, 0x00);
		DRV_WriteReg8(USB_INT_ENB, 0x00);
		DRV_WriteReg8(OTG_INT_EN, 0x00);
		DRV_WriteReg8(USB_SOFT_RST, VUSB_SOFT_RST_EN);
		for(delay=0;delay<10;delay++) ; /* wait for stable*/
			
		#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
			#if (defined(DRV_USB_PHY_U65_IP)) //MT6251 = MAC (IP_Plus) + PHY (unit PHY IP)
		DRV_ClearBits8(USB_U1PHYCR0_1, USB_U1PHYCR0_1_RG_USB11_FSLS_ENBGRI);
		DRV_ClearBits8(USB_PHY_CONTROL, USB_PHY_CONTROL_PUB);
			#elif (defined(DRV_USB_PHY_T55_IP))
			DRV_ClearBits32(USB_U1PHYCR1, U1PHYCR1_RG_USB11_PHY_REV_7);		
			DRV_ClearBits32(USB_U1PHYCR0, U1PHYCR0_RG_USB11_FSLS_ENBGRI);  		
			DRV_ClearBits8(USB_PHY_CONTROL, USB_PHY_CONTROL_PUB);	
		#else  //DRV_USB_IP_V1
			DRV_WriteReg8(USB_ENABLE, USB_ENABLE_DIS);
			#endif
		#endif

	#endif  //USB IP V3
	}
}


void USB_Set_DP_Pull_High(kal_bool bset)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	if(bset == KAL_TRUE)
	{	
		DRV_WriteReg8(USB_POWER, (DRV_Reg8(USB_POWER)|USB_POWER_SOFTCONN));
//		DRV_WriteReg8(USB_POWER, 0x70);	
	}	
	else
		DRV_WriteReg8(USB_POWER, (DRV_Reg8(USB_POWER)&(~USB_POWER_SOFTCONN)));
#else
	if(bset == KAL_TRUE)
	USB_PowerControl(KAL_TRUE);
	else
		USB_PowerControl(KAL_FALSE);
	#if defined(DRV_USB_IP_V1_PLUS)
	DRV_SetBits8(USB_PHY_CONTROL, USB_PHY_CONTROL_PUB);
	#endif
#endif
}


/* reset hw power*/
void USB_Reset_Drv(void)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	/* Enable software reset, USB IP only can be reset by SW when detecting reset signal from bus */
	#if defined(DRV_USB_IP_V3)
	DRV_WriteReg(USB_SWRST, USB_SWRST_DISUSBRESET);
	#elif defined(DRV_USB_IP_V4)
	DRV_WriteReg(USB_BUSPERF3, USB_BUSPERF3_DISUSBRESET);
	#endif
	
	DRV_WriteReg8(USB_RSTINFO, 0xA6);
	/* Because softconn has be decided to set or not */
	DRV_WriteReg8(USB_POWER, (DRV_Reg8(USB_POWER)|USB_POWER_ISOUPDATE|USB_POWER_ENABLESUSPENDM));
#ifdef __USB_HS_ENABLE__
	USB_High_Speed_Enable(KAL_TRUE);
#else
	USB_High_Speed_Enable(KAL_FALSE);
#endif	
#elif defined(DRV_USB_IP_V2)
	WRITE_EP0_BDT_ADDR(USB_BDT_RX, USB_BDT_EVEN, USB_FIFO_RX0_EVEN);
	WRITE_EP0_BDT_ADDR(USB_BDT_RX, USB_BDT_ODD, USB_FIFO_RX0_ODD);
	WRITE_EP0_BDT_ADDR(USB_BDT_TX, USB_BDT_EVEN, USB_FIFO_TX0_ODD);
	WRITE_EP0_BDT_ADDR(USB_BDT_TX, USB_BDT_ODD, USB_FIFO_TX0_ODD);
	WRITE_EPN_BDT_ADDR(1, USB_BDT_RX, USB_FIFO_RX1);
	WRITE_EPN_BDT_ADDR(1, USB_BDT_TX, USB_FIFO_TX1);
	WRITE_EPN_BDT_ADDR(2, USB_BDT_RX, USB_FIFO_RX2);
	WRITE_EPN_BDT_ADDR(2, USB_BDT_TX, USB_FIFO_TX2);
	WRITE_EPN_BDT_ADDR(3, USB_BDT_RX, USB_FIFO_RX3);
	WRITE_EPN_BDT_ADDR(3, USB_BDT_TX, USB_FIFO_TX3);
	
	DRV_WriteReg8(USB_CTL, 0);
	DRV_WriteReg8(USB_ENDPT_CTL(0), VUSB_ENDPT_DISABLE);
	DRV_WriteReg8(USB_ENDPT_CTL(1), VUSB_ENDPT_DISABLE);
	DRV_WriteReg8(USB_ENDPT_CTL(2), VUSB_ENDPT_DISABLE);
	DRV_WriteReg8(USB_ENDPT_CTL(3), VUSB_ENDPT_DISABLE);

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	/* enable software reset, USB IP only can be reset by SW when detecting reset signal from bus */
	DRV_WriteReg8(USB_POWER, USB_POWER_SETSUSPEND|USB_POWER_SWRSTENAB);
#endif
}

/* initialize drv registers, including system global interrupt and EP0 interrupt*/
void USB_Initialize_Drv(void)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	/* software reset */
	#if defined(DRV_USB_IP_V3)	
	DRV_WriteReg(USB_SWRST, (USB_SWRST_DISUSBRESET|USB_SWRST_SWRST));
	#elif defined(DRV_USB_IP_V4)
	DRV_WriteReg(USB_BUSPERF3, USB_DRV_Reg(USB_BUSPERF3)|(USB_BUSPERF3_DISUSBRESET|USB_BUSPERF3_SWRST));
	/* Unmask USB L1 interrupt */
	DRV_WriteReg(USB_L1INTM, (USB_L1INTM_DMA_INT_UNMASK|USB_L1INTM_TX_INT_UNMASK|USB_L1INTM_RX_INT_UNMASK|USB_L1INTM_USBCOM_INT_UNMASK|USB_L1INTM_PSR_INT_UNMASK)|USB_L1INTM_QINT_UNMASK|USB_L1INTM_QHIF_INT_UNMASK);
	DRV_WriteReg8(USB_DMA_INTR_UNMASK_SET,  0xFF);
	#endif
	
	/* enable system interrupts, but disable all ep interrupts */
	USB_EnSysIntr();
	DRV_WriteReg8(USB_INDEX, 0);
	/* flush ep0 FIFO */
	DRV_WriteReg(USB_CSR0, USB_CSR0_FLUSHFIFO);
	/* enable EP0 interrupt */
	USB_EP0En();
#elif defined(DRV_USB_IP_V2)
	/*  
	This hardware has special hardware token done of 4 bytes deep FIFO
	Clear the status FIFOs
	*/
	DRV_WriteReg8(USB_INT_STAT, VUSB_INT_STAT_TOKEN_DONE);
	DRV_WriteReg8(USB_INT_STAT, VUSB_INT_STAT_TOKEN_DONE);
	DRV_WriteReg8(USB_INT_STAT, VUSB_INT_STAT_TOKEN_DONE);
	DRV_WriteReg8(USB_INT_STAT, VUSB_INT_STAT_TOKEN_DONE);

	/* FIFO deep 4*/
	DRV_WriteReg8(USB_FM_ERR_STAT, VUSB_FM_ERR_STAT_TOKEN_DONE);
	DRV_WriteReg8(USB_FM_ERR_STAT, VUSB_FM_ERR_STAT_TOKEN_DONE);
	DRV_WriteReg8(USB_FM_ERR_STAT, VUSB_FM_ERR_STAT_TOKEN_DONE);
	DRV_WriteReg8(USB_FM_ERR_STAT, VUSB_FM_ERR_STAT_TOKEN_DONE);

	/* clear all interrupts*/
	DRV_WriteReg8(USB_INT_STAT, 0xff);

	/* clear all endpoint ctrl */
	DRV_WriteReg8(USB_ENDPT_CTL(0), VUSB_ENDPT_DISABLE);
	DRV_WriteReg8(USB_ENDPT_CTL(1), VUSB_ENDPT_DISABLE);
	DRV_WriteReg8(USB_ENDPT_CTL(2), VUSB_ENDPT_DISABLE);
	DRV_WriteReg8(USB_ENDPT_CTL(3), VUSB_ENDPT_DISABLE);
	
	/* USB addr=0 (default) */
	DRV_WriteReg8(USB_ADDR, 0x00);

	WRITE_EP0_BDT_PID(USB_BDT_RX, USB_BDT_EVEN, 
							(USB_EP0_MAXP<<VUSB_BDT_BC_SHIFT)|VUSB_BDT_OWNS_BIT);
	WRITE_EP0_BDT_PID(USB_BDT_RX, USB_BDT_ODD, 
							(USB_EP0_MAXP<<VUSB_BDT_BC_SHIFT)|VUSB_BDT_OWNS_BIT);
	WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_EVEN, USB_EP0_MAXP<<VUSB_BDT_BC_SHIFT);
	WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_ODD, USB_EP0_MAXP<<VUSB_BDT_BC_SHIFT);
	WRITE_EPN_BDT_PID(1, USB_BDT_RX, USBDL_EP_BULK_MAXP<<VUSB_BDT_BC_SHIFT);
	WRITE_EPN_BDT_PID(1, USB_BDT_TX, USBDL_EP_BULK_MAXP<<VUSB_BDT_BC_SHIFT);
	WRITE_EPN_BDT_PID(2, USB_BDT_RX, USBDL_EP_BULK_MAXP<<VUSB_BDT_BC_SHIFT);
	WRITE_EPN_BDT_PID(2, USB_BDT_TX, USBDL_EP_BULK_MAXP<<VUSB_BDT_BC_SHIFT);
	WRITE_EPN_BDT_PID(3, USB_BDT_RX, USB_EP_INTR_MAXP<<VUSB_BDT_BC_SHIFT);
	WRITE_EPN_BDT_PID(3, USB_BDT_TX, USB_EP_INTR_MAXP<<VUSB_BDT_BC_SHIFT);

	DRV_WriteReg8(USB_BDT_PAGE_01, 0xBD);
	DRV_WriteReg8(USB_BDT_PAGE_02, 0xBD);
	DRV_WriteReg8(USB_BDT_PAGE_03, 0xBD);

	DRV_WriteReg8(USB_CTL, VUSB_CTL_ODD_RST|VUSB_CTL_USB_EN);
	DRV_WriteReg8(USB_CTL, VUSB_CTL_USB_EN);

	/* disable Fast mode*/
	DRV_WriteReg8(USB_FM_CTL, (DRV_Reg8(USB_FM_CTL)&(~VUSB_FM_CTL_FMENB)));
	DRV_WriteReg8(USB_FM_PKT_NUML, 0);
	DRV_WriteReg8(USB_FM_PKT_NUMH, 0);
	DRV_WriteReg8(USB_FM_PKT_CNTL, 0);
	DRV_WriteReg8(USB_FM_PKT_CNTH, 0);
	
	USB_EnSysIntr();
	USB_EP0En();	/* enable EP0 */
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	/* software reset */
	DRV_WriteReg8(USB_RSTCTRL, USB_RSTCTRL_SWRST);
	DRV_WriteReg8(USB_RSTCTRL, 0);	
	/* When mcu set SWRST, the USB_POWER register will be clear as 0 */
	DRV_WriteReg8(USB_POWER, USB_POWER_SETSUSPEND|USB_POWER_SWRSTENAB);
	USB_EnSysIntr();
	USB_EP0En();	/* enable EP0 */
#endif
}


/* enable system global interrupt*/
void USB_EnSysIntr(void)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	DRV_WriteReg(USB_INTRTXE, 0);
	DRV_WriteReg(USB_INTRRXE, 0);
	DRV_WriteReg8(USB_INTRUSBE, 0);
	DRV_WriteReg8(USB_INTRUSBE, (USB_INTRUSBE_SUSPEND|USB_INTRUSBE_RESUME|USB_INTRUSBE_RESET|USB_INTRUSBE_DISCON));
//	DRV_WriteReg8(USB_INTRUSBE, ~USB_INTRUSB_SOF);
#elif defined(DRV_USB_IP_V2)
	DRV_WriteReg8(USB_INT_ENB, 0xff&(~(VUSB_INT_ENB_SOF|VUSB_INT_ENB_RESUME)));
	DRV_WriteReg8(USB_ERR_ENB, 0xff);
	DRV_WriteReg8(USB_PHY_EXTRA, VUSB_PHY_RESUME_INT_ENB);
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	DRV_WriteReg8(USB_INTRIN1E, 0);
	DRV_WriteReg8(USB_INTROUT1E, 0);
	DRV_WriteReg8(USB_INTRUSBE, 0);
	DRV_WriteReg8(USB_INTRUSBE, (USB_INTRUSBE_SUSPEND|USB_INTRUSBE_RESUME|USB_INTRUSBE_RESET));
#endif
}


/* set address for hw*/
void USB_SetAddress(kal_uint8 addr, USB_SET_ADDR_STATE  state)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	if(state == USB_SET_ADDR_STATUS)	
		DRV_WriteReg8(USB_FADDR, addr);
#elif defined(DRV_USB_IP_V2)
	if(state==USB_SET_ADDR_STATUS)	
		DRV_WriteReg8(USB_ADDR, addr);
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	if(state==USB_SET_ADDR_DATA)	
	DRV_WriteReg8(USB_FADDR, addr);
#endif
}

kal_uint16 USB_GetFrameCount(void)
{
#if !(defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4))
	kal_uint8 count;
#endif
	kal_uint16 sof;

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	sof =  DRV_Reg(USB_FRAME);
#elif defined(DRV_USB_IP_V2)
	count = DRV_Reg8(USB_FRM_NUML);
	sof = (kal_uint16)count;
	count = DRV_Reg8(USB_FRM_NUMH);
	sof+=(count<<8);
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	count = DRV_Reg8(USB_FRAME1);
	sof = (kal_uint16)count;
	count = DRV_Reg8(USB_FRAME2);
	sof+=(count<<8);
#endif
	return sof;
}


/************************************************************
	EP ctrl functinos
*************************************************************/

/* initialize EP IN */
void USB_TxEPInit(kal_uint8 epno,kal_uint16 data_size, USB_ENDPT_TXFER_TYPE type)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	if(epno == 0)
		ASSERT(0);

	DRV_WriteReg8(USB_INDEX, epno);
	/* double buffers, so flush twice */
	DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
	DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
	DRV_WriteReg(USB_TXMAXP, data_size);

	/* set FIFO address here */
	if(type == USB_ENDPT_BULK)
	{
		//single  buffer
		DRV_WriteReg8(USB_TXFIFOSZ, (USB_FIFOSZ_SIZE_512));
		DRV_WriteReg(USB_TXFIFOADD, (g_FIFOadd/8));
		g_FIFOadd += USB_BULK_FIFO_UNIT_SIZE;
	}
	else if (type == USB_ENDPT_INTR)
	{
		DRV_WriteReg8(USB_TXFIFOSZ, USB_FIFOSZ_SIZE_64);
		DRV_WriteReg(USB_TXFIFOADD, (kal_uint16)(g_FIFOadd/8));
		g_FIFOadd += USB_INTR_FIFO_UNIT_SIZE;
	}

	if(g_FIFOadd > USB_MAX_FIFO_SIZE)
		ASSERT(0);

#elif defined(DRV_USB_IP_V2)
	kal_uint8	epctl_value = 0;

	/* check the packet size, FIFO only 8 bytes*/
	if((epno == 0)||((epno == 3)&&(data_size != 8)))
		EXT_ASSERT(0, (kal_uint32)epno, 0, 0);

	switch(type)
	{
	case USB_ENDPT_BULK:
		epctl_value = VUSB_ENDPT_BULK_TX;
		break;
	case USB_ENDPT_INTR:
		epctl_value = VUSB_ENDPT_BULK_TX;
		break;
	/* not support */
	case USB_ENDPT_CTRL:
	case USB_ENDPT_ISO:
		ASSERT(0);
		break;
	}

	g_UsbDrvInfo.ep_tx_max_data_size[epno-1] =  (kal_uint8)data_size;

	DRV_WriteReg8(USB_ENDPT_CTL(epno), DRV_Reg8(USB_ENDPT_CTL(epno))|epctl_value);

#elif defined(DRV_USB_IP_V1)
	if(epno==0)
		ASSERT(0);

	DRV_WriteReg8(USB_INDEX,epno);
	DRV_WriteReg8(USB_INCSR1,(USB_INCSR1_CLRDATATOG | USB_INCSR1_FLUSHFIFO));
	DRV_WriteReg8(USB_INMAXP, (kal_uint8)(data_size/8));

#elif defined(DRV_USB_IP_V1_PLUS)
	if(epno==0)
		ASSERT(0);

	DRV_WriteReg8(USB_INDEX,epno);
	DRV_WriteReg8(USB_INCSR1,(USB_INCSR1_CLRDATATOG | USB_INCSR1_FLUSHFIFO));
	DRV_WriteReg8(USB_INMAXP, (kal_uint8)(data_size));
	
#endif
}


/* initialize EP OUT */
void USB_RxEPInit(kal_uint8 epno,kal_uint16 data_size, USB_ENDPT_TXFER_TYPE type)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	if(epno == 0)
		ASSERT(0);

	DRV_WriteReg8(USB_INDEX, epno);
	DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
	DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
	DRV_WriteReg(USB_RXMAXP, data_size);

	/* set FIFO address here */
	if(type == USB_ENDPT_BULK)
	{
		//single buffer
		DRV_WriteReg8(USB_RXFIFOSZ, (USB_FIFOSZ_SIZE_512));
		DRV_WriteReg(USB_RXFIFOADD, (g_FIFOadd/8));
		g_FIFOadd += USB_BULK_FIFO_UNIT_SIZE;
	}
	else
	{
		ASSERT(0);
	}

	if(g_FIFOadd > USB_MAX_FIFO_SIZE)
		ASSERT(0);

#elif defined(DRV_USB_IP_V2)

	kal_uint8	epctl_value = 0;


	/* check the packet size, FIFO only 8 bytes*/
	if((epno == 0)||((epno == 3)&&(data_size != 8)))
		EXT_ASSERT(0, (kal_uint32)epno, 0, 0);

	switch(type)
	{
	case USB_ENDPT_BULK:
		epctl_value = VUSB_ENDPT_BULK_RX;
		break;
	case USB_ENDPT_INTR:
		epctl_value = VUSB_ENDPT_BULK_RX;
		break;
	/* not support */
	case USB_ENDPT_CTRL:
	case USB_ENDPT_ISO:
		ASSERT(0);
		break;
	}

	g_UsbDrvInfo.ep_rx_max_data_size[epno-1] =  (kal_uint8)data_size;
	
	DRV_WriteReg8(USB_ENDPT_CTL(epno), DRV_Reg8(USB_ENDPT_CTL(epno))|epctl_value);
	
#elif defined(DRV_USB_IP_V1)
	if(epno == 0)
		ASSERT(0);

	DRV_WriteReg8(USB_INDEX,epno);
	DRV_WriteReg8(USB_OUTCSR1,(USB_OUTCSR1_CLRDATATOG | USB_OUTCSR1_FLUSHFIFO));
	DRV_WriteReg8(USB_OUTMAXP, (kal_uint8)(data_size/8));
	
#elif defined(DRV_USB_IP_V1_PLUS)
	if(epno == 0)
		ASSERT(0);

	DRV_WriteReg8(USB_INDEX,epno);
	DRV_WriteReg8(USB_OUTCSR1,(USB_OUTCSR1_CLRDATATOG | USB_OUTCSR1_FLUSHFIFO));
	DRV_WriteReg8(USB_OUTMAXP, (kal_uint8)(data_size));
	
#endif
}


void USB_EP0En(void)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	/* default address is from 0 to 63  */
	DRV_WriteReg(USB_INTRTXE, DRV_Reg(USB_INTRTXE)|USB_INTRE_EPEN);
#elif defined(DRV_USB_IP_V2)
	DRV_WriteReg8(USB_ENDPT_CTL(0), VUSB_ENDPT_CONTROL);
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	DRV_Reg8(USB_INTRIN1E) |= USB_INTRIN1E_EPEN;
#endif
}


void USB_TxEPEn(kal_uint8 epno, USB_ENDPT_TXFER_TYPE ep_type, USB_ENDPT_DMA_USAGE dma_usage_type, kal_bool is_flush, kal_bool is_ft_mode)
{
	if(epno == 0)
		ASSERT(0);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)

	DRV_WriteReg8(USB_INDEX, epno);

	/* double buffers, so flush twice  */
	DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
	DRV_WriteReg(USB_TXCSR, (USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));

	if(dma_usage_type == USB_EP_USE_ONLY_DMA)
	{
		/* Only configure as multiple packet DMA TX mode */
		DRV_WriteReg(USB_TXCSR, USB_TXCSR_AUTOSET|USB_TXCSR_DMAREQENAB|USB_TXCSR_DMAREQMODE);
		DRV_WriteReg(USB_INTRTXE, DRV_Reg(USB_INTRTXE)&~(USB_INTRE_EPEN<<epno));
	}
	else
	{
		DRV_WriteReg(USB_INTRTXE, DRV_Reg(USB_INTRTXE)|USB_INTRE_EPEN<<epno);
	}

#elif defined(DRV_USB_IP_V2)

	/* The first expect sent packet is data0 */
	g_UsbDrvInfo.ep_tx_data01[epno-1] = 0;

	if(dma_usage_type == USB_EP_USE_ONLY_DMA)
	{
		g_UsbDrvInfo.ep_tx_enb_state[epno-1] = USB_EP_STATE_DMA;
	}	
	else
        {
		g_UsbDrvInfo.ep_tx_enb_state[epno-1] = USB_EP_STATE_FIFO;
	}

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))

	DRV_WriteReg8(USB_INDEX, epno);

	if(dma_usage_type == USB_EP_USE_ONLY_DMA)
	{
		DRV_WriteReg8(USB_INTRIN1E, DRV_Reg8(USB_INTRIN1E)&(~(USB_INTRIN1E_EPEN << epno)));

		DRV_WriteReg8(USB_INCSR1, (USB_INCSR1_CLRDATATOG | USB_INCSR1_FLUSHFIFO));
		DRV_WriteReg8(USB_INCSR1, (USB_INCSR1_CLRDATATOG | USB_INCSR1_FLUSHFIFO));

		DRV_WriteReg8(USB_INCSR2, 0);
		DRV_WriteReg8(USB_INCSR2, (USB_INCSR2_AUTOSET | USB_INCSR2_DMAENAB));
	}
	else
	{
		DRV_WriteReg8(USB_INCSR1,(USB_INCSR1_CLRDATATOG | USB_INCSR1_FLUSHFIFO));
		DRV_WriteReg8(USB_INCSR1,(USB_INCSR1_CLRDATATOG | USB_INCSR1_FLUSHFIFO));

		DRV_WriteReg8(USB_INCSR2,0);
		DRV_WriteReg8(USB_INTRIN1E, DRV_Reg8(USB_INTRIN1E)|(USB_INTRIN1E_EPEN << epno));
	}
#endif	
}


void USB_RxEPEn(kal_uint8 epno, USB_ENDPT_TXFER_TYPE ep_type, USB_ENDPT_DMA_USAGE dma_usage_type, kal_bool is_flush, kal_bool is_ft_mode)
{
	if(epno == 0)
		ASSERT(0);


#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)

	DRV_WriteReg8(USB_INDEX, epno);

	if(dma_usage_type == USB_EP_USE_ONLY_DMA)
	{
		DRV_WriteReg(USB_INTRRXE, DRV_Reg(USB_INTRRXE)&(~(USB_INTRE_EPEN<<epno)));

		/* maybe double buffer, so flush twice */
		DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
		DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
	}
	else
	{
		/* maybe double buffer, so flush twice  */
		DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
		DRV_WriteReg(USB_RXCSR, (USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));

		DRV_WriteReg(USB_INTRRXE, DRV_Reg(USB_INTRRXE)|USB_INTRE_EPEN<<epno);
	}

#elif defined(DRV_USB_IP_V2)

	/* The first expect received packet is data0 */
	g_UsbDrvInfo.ep_rx_data01[epno-1] = 0;

	if(dma_usage_type == USB_EP_USE_ONLY_DMA)
	{
		g_UsbDrvInfo.ep_rx_enb_state[epno-1] = USB_EP_STATE_DMA;
	}
	else
	{
		g_UsbDrvInfo.ep_rx_enb_state[epno-1] = USB_EP_STATE_FIFO;

		// configure BDT to receive data
		WRITE_EPN_BDT_PID(epno, USB_BDT_RX, 
				(g_UsbDrvInfo.ep_rx_max_data_size[epno-1] << VUSB_BDT_BC_SHIFT) |
				(g_UsbDrvInfo.ep_rx_data01[epno-1]<<VUSB_BDT_DATA01_SHIFT) |
				VUSB_BDT_DTS_BIT | VUSB_BDT_OWNS_BIT);
		g_UsbDrvInfo.ep_rx_data01[epno-1] ^= 1;
	}

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))

	DRV_WriteReg8(USB_INDEX, epno);

	if(dma_usage_type == USB_EP_USE_ONLY_DMA)
	{
		DRV_WriteReg8(USB_INTROUT1E, DRV_Reg8(USB_INTROUT1E)&(~(USB_INTROUT1E_EPEN<<epno)));

		DRV_WriteReg8(USB_OUTCSR1, (USB_OUTCSR1_CLRDATATOG | USB_OUTCSR1_FLUSHFIFO));
		DRV_WriteReg8(USB_OUTCSR1, (USB_OUTCSR1_CLRDATATOG | USB_OUTCSR1_FLUSHFIFO));

		// CR MAUI_00248052
		DRV_WriteReg8(USB_OUTCSR2, 0);
		DRV_WriteReg8(USB_OUTCSR2, (USB_OUTCSR2_AUTOCLEAR | USB_OUTCSR2_DMAENAB));
	}
	else
	{
		DRV_WriteReg8(USB_OUTCSR1, (USB_OUTCSR1_CLRDATATOG | USB_OUTCSR1_FLUSHFIFO));
		DRV_WriteReg8(USB_OUTCSR1, (USB_OUTCSR1_CLRDATATOG | USB_OUTCSR1_FLUSHFIFO));	

		DRV_WriteReg8(USB_OUTCSR2, 0);
		DRV_WriteReg8(USB_INTROUT1E, DRV_Reg8(USB_INTROUT1E)|USB_INTROUT1E_EPEN<<epno);
	}
#endif	
}


/*  read FIFO data from EP nEP with sfift */
void USB_EPFIFORead_Shift(kal_uint8 nEP, kal_uint16 nBytes, void *pDst, kal_uint32 shift)
{
#if defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)||defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint16  nCount = nBytes;
	kal_uint8   *pby;
	kal_uint32  nAddr;
#endif


	if((nBytes!=0) && (pDst==NULL))
		EXT_ASSERT(0, (kal_uint32)nBytes, 0, 0);
	
	if (pDst==NULL)
		return;

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	DRV_WriteReg8(USB_INDEX, nEP);
	nAddr = USB_EP0 + nEP*4;
	pby = (kal_uint8 *)pDst;

	/* read byte by byte */
	while (nCount) 
	{
		*pby++ = DRV_Reg8(nAddr); 
		nCount--;
	}
#elif defined(DRV_USB_IP_V2)
	// make sure this endpoint status belong to MCU
	if(nEP==0)
	{
		if((READ_EP0_BDT_PID(USB_BDT_RX, g_UsbDrvInfo.ep0_rx_even_odd)&VUSB_BDT_OWNS_BIT)!=0)
			ASSERT(0);

		kal_mem_cpy(pDst, (void*)(READ_EP0_BDT_ADDR(USB_BDT_RX, g_UsbDrvInfo.ep0_rx_even_odd) + shift), nBytes);
	}
	else
	{
		ASSERT(g_UsbDrvInfo.ep_rx_enb_state[nEP-1] != USB_EP_STATE_DISABLE);
		ASSERT(nBytes <= g_UsbDrvInfo.ep_rx_max_data_size[nEP-1]);
		
		if((READ_EPN_BDT_PID(nEP, USB_BDT_RX)&VUSB_BDT_OWNS_BIT)!=0)
			ASSERT(0);

		kal_mem_cpy(pDst, (void*)(READ_EPN_BDT_ADDR(nEP, USB_BDT_RX) + shift), nBytes);
	}
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	DRV_WriteReg8(USB_INDEX,nEP);
	nAddr = USB_EP0+nEP*4;
	pby = (kal_uint8 *)pDst;

	/* read byte by byte */
	while (nCount) 
	{
		*pby++ = DRV_Reg8(nAddr); 
		nCount--;
	}
#endif	
}


/* Read fifo data from EP nEP*/
void USB_EPFIFORead(kal_uint8 nEP, kal_uint16 nBytes, void *pDst)
{
	USB_EPFIFORead_Shift(nEP, nBytes, pDst, 0);
}


/*  write data to fifo EP nEP*/
void USB_EPFIFOWrite (kal_uint8 nEP, kal_uint16 nBytes, void *pSrc)
{
#if defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS)||defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint16 nCount = nBytes;
	kal_uint8 *pby;
	kal_uint32 nAddr;
#endif

	if((nBytes!=0) && (pSrc==NULL))
		EXT_ASSERT(0, (kal_uint32)nBytes, 0, 0);
			
	if (pSrc==NULL)
		return;
			
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	DRV_WriteReg8(USB_INDEX, nEP);
	nAddr = USB_EP0 + nEP*4;
	pby = (kal_uint8 *)pSrc;

	/* write byte by byte */
	while (nCount) 
	{
		DRV_WriteReg8(nAddr, *pby++);
		nCount--;
	}
#elif defined(DRV_USB_IP_V2)
	if(nEP==0)
	{
		// make sure this endpoint status belong to MCU
		if((READ_EP0_BDT_PID(USB_BDT_TX, g_UsbDrvInfo.ep0_tx_even_odd)&VUSB_BDT_OWNS_BIT)!=0)
			ASSERT(0);
		kal_mem_cpy((void*)READ_EP0_BDT_ADDR(USB_BDT_TX, g_UsbDrvInfo.ep0_tx_even_odd),
					pSrc, nBytes);
		WRITE_EP0_BDT_PID(USB_BDT_TX, g_UsbDrvInfo.ep0_tx_even_odd, nBytes<<VUSB_BDT_BC_SHIFT);
	}
	else
	{
		ASSERT(g_UsbDrvInfo.ep_tx_enb_state[nEP-1] != USB_EP_STATE_DISABLE);
		ASSERT(nBytes<=g_UsbDrvInfo.ep_tx_max_data_size[nEP-1]);
		
		// make sure this endpoint status belong to MCU
		if((READ_EPN_BDT_PID(nEP, USB_BDT_TX)&VUSB_BDT_OWNS_BIT)!=0)
			ASSERT(0);
		kal_mem_cpy((void*)READ_EPN_BDT_ADDR(nEP, USB_BDT_TX), pSrc, nBytes);
		WRITE_EPN_BDT_PID(nEP, USB_BDT_TX, nBytes<<VUSB_BDT_BC_SHIFT);
	}
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	DRV_WriteReg8(USB_INDEX,nEP);
	nAddr = USB_EP0+nEP*4;
	pby = (kal_uint8 *)pSrc;

	/* write by byte */
	while (nCount) 
	{
		DRV_WriteReg8(nAddr,*pby++);
		nCount--;
	}
#endif	
}


/* type == USB_TX_EP_TYPE or USB_RX_EP_TYPE 
    en == KAL_TRUE means stall this endpoint */
void USB_CtrlEPStall(kal_uint8 EPno, USB_EP_DIRECTION direction, kal_bool en, USB_CTRL_STALL_ENTRY entry)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint16  CSR;
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	kal_uint8 CSR1;
#endif

	USB_EP_Check(EPno, direction, __LINE__);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	if (en == KAL_TRUE)
	{
		/* stall endpoint */
		if(direction == USB_EP_RX_DIR)
		{
			DRV_WriteReg8(USB_INDEX,  EPno);
			CSR = DRV_Reg(USB_RXCSR);
			DRV_WriteReg(USB_RXCSR, (CSR|USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG|USB_RXCSR_SENDSTALL));
			g_UsbDrvInfo.ep_rx_stall_status[EPno-1] = KAL_TRUE;
		}
		else
		{
			DRV_WriteReg8(USB_INDEX, EPno);
			CSR = DRV_Reg(USB_TXCSR);
			DRV_WriteReg(USB_TXCSR, (CSR|USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG|USB_TXCSR_SENDSTALL));
			g_UsbDrvInfo.ep_tx_stall_status[EPno-1] = KAL_TRUE;
		}
	}
	else
	{
		/* clear stall */
		if (direction == USB_EP_RX_DIR)
		{
			DRV_WriteReg8(USB_INDEX, EPno);
			CSR = DRV_Reg(USB_RXCSR);
			CSR &= ~USB_RXCSR_SENDSTALL;			
			DRV_WriteReg(USB_RXCSR, (CSR|USB_RXCSR_FLUSHFIFO|USB_RXCSR_CLRDATATOG));
			g_UsbDrvInfo.ep_rx_stall_status[EPno-1] = KAL_FALSE;
		}
		else
		{
			DRV_WriteReg8(USB_INDEX, EPno);
			CSR = DRV_Reg(USB_TXCSR);
			CSR &= ~USB_TXCSR_SENDSTALL;
			DRV_WriteReg(USB_TXCSR,(CSR|USB_TXCSR_FLUSHFIFO|USB_TXCSR_CLRDATATOG));
			g_UsbDrvInfo.ep_tx_stall_status[EPno-1] = KAL_FALSE;
		}
	}
#elif defined(DRV_USB_IP_V2)
	if (en == KAL_TRUE)
	{
		/* stall endpoint */
		if (direction == USB_EP_RX_DIR)
		{
			WRITE_EPN_BDT_PID(EPno, USB_BDT_RX, VUSB_BDT_OWNS_BIT|VUSB_BDT_STALL_BIT);
			g_UsbDrvInfo.ep_rx_stall_status[EPno-1] = KAL_TRUE;
			g_UsbDrvInfo.ep_rx_data01[EPno-1] = 0;
		}
		else
		{
			WRITE_EPN_BDT_PID(EPno, USB_BDT_TX, VUSB_BDT_OWNS_BIT|VUSB_BDT_STALL_BIT);
			g_UsbDrvInfo.ep_tx_stall_status[EPno-1] = KAL_TRUE;
			g_UsbDrvInfo.ep_tx_data01[EPno-1] = 0;
		}
	}
	else
	{
		/* clear stall */
		if (direction == USB_EP_RX_DIR)
		{
			WRITE_EPN_BDT_PID(EPno, USB_BDT_RX, 0);
			g_UsbDrvInfo.ep_rx_stall_status[EPno-1] = KAL_FALSE;
			g_UsbDrvInfo.ep_rx_data01[EPno-1] = 0;
		}
		else
		{
			WRITE_EPN_BDT_PID(EPno, USB_BDT_TX, 0);
			g_UsbDrvInfo.ep_tx_stall_status[EPno-1] = KAL_FALSE;
			g_UsbDrvInfo.ep_tx_data01[EPno-1] = 0;
		}
	}
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))

	if (en == KAL_TRUE)
	{
		/* stall endpoint */
		if (direction == USB_EP_RX_DIR)
		{
			DRV_WriteReg8(USB_INDEX, EPno);
			CSR1 = DRV_Reg8(USB_OUTCSR1);
			CSR1 |= USB_OUTCSR1_SENDSTALL;
			DRV_WriteReg8(USB_OUTCSR1,(CSR1|USB_OUTCSR1_FLUSHFIFO|USB_OUTCSR1_CLRDATATOG));
			DRV_WriteReg8(USB_OUTCSR1, (CSR1|USB_OUTCSR1_FLUSHFIFO|USB_OUTCSR1_CLRDATATOG));
			g_UsbDrvInfo.ep_rx_stall_status[EPno-1] = KAL_TRUE;
		}
		else
		{
			DRV_WriteReg8(USB_INDEX, EPno);
			CSR1 = DRV_Reg8(USB_INCSR1);
			CSR1 |= USB_INCSR1_SENDSTALL;
			DRV_WriteReg8(USB_INCSR1,(CSR1|USB_INCSR1_FLUSHFIFO|USB_INCSR1_CLRDATATOG));
			DRV_WriteReg8(USB_INCSR1, (CSR1|USB_INCSR1_FLUSHFIFO|USB_INCSR1_CLRDATATOG));
			g_UsbDrvInfo.ep_tx_stall_status[EPno-1] = KAL_TRUE;
		}
	}
	else
	{
		/* clear stall */
		if (direction == USB_EP_RX_DIR)
		{
			DRV_WriteReg8(USB_INDEX, EPno);
			CSR1 = DRV_Reg8(USB_OUTCSR1);
			CSR1 &= ~USB_OUTCSR1_SENDSTALL;
			DRV_WriteReg8(USB_OUTCSR1,(CSR1|USB_OUTCSR1_FLUSHFIFO|USB_OUTCSR1_CLRDATATOG));
			DRV_WriteReg8(USB_OUTCSR1, (CSR1|USB_OUTCSR1_FLUSHFIFO|USB_OUTCSR1_CLRDATATOG));
			g_UsbDrvInfo.ep_rx_stall_status[EPno-1] = KAL_FALSE;
		}
		else
		{
			DRV_WriteReg8(USB_INDEX, EPno);
			CSR1 = DRV_Reg8(USB_INCSR1);
			CSR1 &= ~USB_INCSR1_SENDSTALL;
			DRV_WriteReg8(USB_INCSR1,(CSR1|USB_INCSR1_FLUSHFIFO|USB_INCSR1_CLRDATATOG));
			DRV_WriteReg8(USB_INCSR1, (CSR1|USB_INCSR1_FLUSHFIFO|USB_INCSR1_CLRDATATOG));
			g_UsbDrvInfo.ep_tx_stall_status[EPno-1] = KAL_FALSE;
		}
	}
#endif	
}

/* get endpoint 0 status. (if transaction end or sent stall interrupt received)  */
void USB_Get_EP0_Status(kal_bool *p_transaction_end, kal_bool *p_sent_stall)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint16  	CSR0;

	DRV_WriteReg8(USB_INDEX, 0);
	CSR0 = DRV_Reg(USB_CSR0);

	if (CSR0 & USB_CSR0_SENTSTALL) 
		*p_sent_stall = KAL_TRUE;
	else
		*p_sent_stall = KAL_FALSE;
	
	if (CSR0 & USB_CSR0_SETUPEND) 
		*p_transaction_end = KAL_TRUE;
	else
		*p_transaction_end = KAL_FALSE;
#elif defined(DRV_USB_IP_V2)
	if((READ_EP0_BDT_PID(USB_BDT_RX, g_UsbDrvInfo.ep0_rx_even_odd^1) &VUSB_BDT_STALL_BIT) 
		&& (DRV_Reg8(USB_CTL)&VUSB_CTL_TXD_SUSPEND))
		*p_sent_stall = KAL_TRUE;
	else
		*p_sent_stall = KAL_FALSE;

	if(g_UsbDrvInfo.ep0_transaction_type == USB_EP0_TRANS_END)
		*p_transaction_end = KAL_TRUE;
	else
		*p_transaction_end = KAL_FALSE;
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	kal_uint8 byCSR0;
	
	DRV_WriteReg8(USB_INDEX,0);
	byCSR0 = DRV_Reg8(USB_CSR0);

	if (byCSR0 & USB_CSR0_SENTSTALL) 
		*p_sent_stall = KAL_TRUE;
	else
		*p_sent_stall = KAL_FALSE;
	
	if (byCSR0 & USB_CSR0_SETUPEND) 
		*p_transaction_end = KAL_TRUE;
	else
		*p_transaction_end = KAL_FALSE;
#endif	
}


/* control endpoint 0 registers according to USB_EP0_DRV_STATE */
void USB_Update_EP0_State(USB_EP0_DRV_STATE state, kal_bool stall, kal_bool end)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint8   reg_state;
	kal_uint16   CSR0;

	/* clear sent stall */
	if(state == USB_EP0_DRV_STATE_CLEAR_SENT_STALL)
	{
		DRV_WriteReg8(USB_INDEX, 0);   
		CSR0 = DRV_Reg(USB_CSR0);
		DRV_WriteReg(USB_CSR0, CSR0&(~USB_CSR0_SENTSTALL));
		return;
	}

	/* clear transaction end*/
	if(state == USB_EP0_DRV_STATE_TRANSACTION_END)
	{
		DRV_WriteReg8(USB_INDEX, 0);   
		DRV_WriteReg(USB_CSR0, (USB_CSR0_SERVICEDSETUPEND));
		return;
	}

	/* ep0 read end or write ready*/
	if(state == USB_EP0_DRV_STATE_READ_END)
	{
		reg_state = USB_CSR0_SERVICEDRXPKTRDY;
	}
	else
	{
		reg_state = USB_CSR0_TXPKTRDY;
	}

	/* error occured, sent stall*/
	if(stall == KAL_TRUE)
	{
		reg_state |= USB_CSR0_SENDSTALL; 
	}

	/* last data for this transaction, set data end bit*/
	if(end == KAL_TRUE)
	{
		reg_state |= USB_CSR0_DATAEND; 
	}
	
	DRV_WriteReg8(USB_INDEX, 0);
	DRV_WriteReg(USB_CSR0, reg_state);

#elif defined(DRV_USB_IP_V2)
	/* clear sent stall*/
	if(state ==USB_EP0_DRV_STATE_CLEAR_SENT_STALL)
	{
		WRITE_EP0_BDT_PID(USB_BDT_RX, USB_BDT_EVEN, 
							READ_EP0_BDT_PID(USB_BDT_RX, USB_BDT_EVEN)&(~VUSB_BDT_STALL_BIT));
		WRITE_EP0_BDT_PID(USB_BDT_RX, USB_BDT_ODD, 
							READ_EP0_BDT_PID(USB_BDT_RX, USB_BDT_ODD)&(~VUSB_BDT_STALL_BIT));
		WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_EVEN, 
							READ_EP0_BDT_PID(USB_BDT_TX, USB_BDT_EVEN)&(~VUSB_BDT_STALL_BIT));
		WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_ODD, 
							READ_EP0_BDT_PID(USB_BDT_TX, USB_BDT_ODD)&(~VUSB_BDT_STALL_BIT));
		return;
	}

	/* clear transaction end*/
	if(state ==USB_EP0_DRV_STATE_TRANSACTION_END)
	{
		EXT_ASSERT((g_UsbDrvInfo.ep0_current_dir==0), 0, 0, 0);
		/* clear the data in sent buffer */
		WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_EVEN, 0);
		WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_ODD, 0);
		WRITE_EP0_BDT_PID(USB_BDT_RX, g_UsbDrvInfo.ep0_rx_even_odd, 
							(USB_EP0_MAXP << VUSB_BDT_BC_SHIFT) |VUSB_BDT_OWNS_BIT);
		g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_NONE;
		return;
	}

	/* ep0 read end or write ready*/
	if((state == USB_EP0_DRV_STATE_READ_END) && (stall==KAL_FALSE))
	{
		/* clear tx suspend for setupt packet*/
		if(DRV_Reg8(USB_CTL)&VUSB_CTL_TXD_SUSPEND)
		{
			g_UsbDrvInfo.ep0_tx_data01 = 0;
			/* clear the data in sent buffer */
			WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_EVEN, 0);
			WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_ODD, 0);
			DRV_Reg8(USB_CTL) = DRV_Reg8(USB_CTL)&(~VUSB_CTL_TXD_SUSPEND);
		}	

		WRITE_EP0_BDT_PID(USB_BDT_RX, g_UsbDrvInfo.ep0_rx_even_odd, 
							(USB_EP0_MAXP << VUSB_BDT_BC_SHIFT) |VUSB_BDT_OWNS_BIT);
		g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_RX_DATA;
	}
	else if((state == USB_EP0_DRV_STATE_WRITE_RDY) && (stall==KAL_FALSE))
	{
		/* toggle DATA01*/
		g_UsbDrvInfo.ep0_tx_data01^=1;
		WRITE_EP0_BDT_PID(USB_BDT_TX, g_UsbDrvInfo.ep0_tx_even_odd, 
							(READ_EP0_BDT_PID(USB_BDT_TX, g_UsbDrvInfo.ep0_tx_even_odd)&VUSB_BDT_BC_MASK) 
							|(g_UsbDrvInfo.ep0_tx_data01<<VUSB_BDT_DATA01_SHIFT) 
							| VUSB_BDT_DTS_BIT | VUSB_BDT_OWNS_BIT);
		g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_TX_DATA;
	}
	
	/* error occured, sent stall*/	
	if(stall == KAL_TRUE)
	{
		WRITE_EP0_BDT_PID(USB_BDT_RX, USB_BDT_EVEN, 
							READ_EP0_BDT_PID(USB_BDT_RX, USB_BDT_EVEN)|VUSB_BDT_STALL_BIT);
		WRITE_EP0_BDT_PID(USB_BDT_RX, USB_BDT_ODD, 
							READ_EP0_BDT_PID(USB_BDT_RX, USB_BDT_ODD)|VUSB_BDT_STALL_BIT);
		WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_EVEN, 
							READ_EP0_BDT_PID(USB_BDT_RX, USB_BDT_EVEN)|VUSB_BDT_STALL_BIT);
		WRITE_EP0_BDT_PID(USB_BDT_TX, USB_BDT_ODD, 
							READ_EP0_BDT_PID(USB_BDT_RX, USB_BDT_ODD)|VUSB_BDT_STALL_BIT);
		g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_NONE;
	}
	/* last data for this transaction, set data end bit*/
	else if(end == KAL_TRUE)
	{
		if(g_UsbDrvInfo.ep0_transaction_type==USB_EP0_TRANS_RX_DATA)
		{
			/* status data01 always 1*/
			g_UsbDrvInfo.ep0_tx_data01 = 1;
			/* byte count 0 */
			WRITE_EP0_BDT_PID(USB_BDT_TX, g_UsbDrvInfo.ep0_tx_even_odd, 
								(g_UsbDrvInfo.ep0_tx_data01<<VUSB_BDT_DATA01_SHIFT) |
								VUSB_BDT_DTS_BIT | VUSB_BDT_OWNS_BIT);
			g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_RX_STATUS;
		}
		else if(g_UsbDrvInfo.ep0_transaction_type==USB_EP0_TRANS_TX_DATA)
		{					
			g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_TX_DATA_END;
		}
		else
		{
			EXT_ASSERT(0, (kal_uint32)g_UsbDrvInfo.ep0_transaction_type, (kal_uint32)state, (kal_uint32)stall);
		}
	}
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	kal_uint8   reg_state;
	kal_uint8   byCSR0;

	/* clear sent stall*/
	if(state ==USB_EP0_DRV_STATE_CLEAR_SENT_STALL)
	{
		DRV_WriteReg8(USB_INDEX,0);   
		byCSR0 = DRV_Reg8(USB_CSR0);
		DRV_WriteReg8(USB_CSR0, byCSR0&(~USB_CSR0_SENTSTALL));
		return;
	}

	/* clear transaction end*/
	if(state ==USB_EP0_DRV_STATE_TRANSACTION_END)
	{
		DRV_WriteReg8(USB_INDEX,0);   
		DRV_WriteReg8(USB_CSR0, (USB_CSR0_SERVICESETUPEND));
		return;
	}

	/* ep0 read end or write ready*/
	if(state == USB_EP0_DRV_STATE_READ_END)
	{
		reg_state = USB_CSR0_SERVICEDOUTPKTRDY;
	}
	else
	{
		reg_state = USB_CSR0_INPKTRDY;
	}

	/* error occured, sent stall*/	
	if(stall == KAL_TRUE)
	{
		reg_state |= USB_CSR0_SENDSTALL; 
	}
	/* last data for this transaction, set data end bit*/
	if(end == KAL_TRUE)
	{
		reg_state |= USB_CSR0_DATAEND; 
	}
	
	DRV_WriteReg8(USB_INDEX,0);   
	DRV_WriteReg8(USB_CSR0, reg_state);
#endif		
}

/* return packet length for endpoint 0*/
kal_uint32 USB_EP0_Pkt_Len(void)
{
	kal_uint32 nCount = 0;
	
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint16  CSR0;
	
	DRV_WriteReg8(USB_INDEX, 0);
	CSR0 = DRV_Reg(USB_CSR0);
	
	if(CSR0&USB_CSR0_RXPKTRDY)
		nCount = (kal_uint32)DRV_Reg8(USB_COUNT0);
#elif defined(DRV_USB_IP_V2)
	if((READ_EP0_BDT_PID(USB_BDT_RX, g_UsbDrvInfo.ep0_rx_even_odd) &VUSB_BDT_OWNS_BIT)==0)
	{
		nCount = (READ_EP0_BDT_PID(USB_BDT_RX, g_UsbDrvInfo.ep0_rx_even_odd) & VUSB_BDT_BC_MASK)
				>>VUSB_BDT_BC_SHIFT;
	}
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	kal_uint8 byCSR0;
	
	DRV_WriteReg8(USB_INDEX,0);
	byCSR0 = DRV_Reg8(USB_CSR0);
	
	if(byCSR0 & USB_CSR0_OUTPKTRDY)
	{
		nCount = (kal_uint32)DRV_Reg8(USB_COUNT0);
	}
#endif

	return nCount;
}

/* ep in data prepared ready, set ready bit */
void USB_EP_Bulk_Tx_Ready(kal_uint8 ep_num)
{
	USB_EP_Check(ep_num, USB_EP_TX_DIR, __LINE__);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	DRV_WriteReg8(USB_INDEX, ep_num);

	if (DRV_Reg(USB_TXCSR)& USB_TXCSR_TXPKTRDY)
		ASSERT(0);
	DRV_WriteReg(USB_TXCSR, DRV_Reg(USB_TXCSR)|USB_TXCSR_TXPKTRDY);	
#elif defined(DRV_USB_IP_V2)
	WRITE_EPN_BDT_PID(ep_num, USB_BDT_TX, 
				(READ_EPN_BDT_PID(ep_num, USB_BDT_TX) & VUSB_BDT_BC_MASK) |
				(g_UsbDrvInfo.ep_tx_data01[ep_num-1]<<VUSB_BDT_DATA01_SHIFT) |
				VUSB_BDT_DTS_BIT | VUSB_BDT_OWNS_BIT);
	g_UsbDrvInfo.ep_tx_data01[ep_num-1] ^= 1;
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	DRV_WriteReg8(USB_INDEX,ep_num);
	DRV_WriteReg8(USB_INCSR1, USB_INCSR1_INPKTRDY);
#endif
}

/* return ep out received packet length*/
kal_uint32 USB_EP_Rx_Pkt_Len(kal_uint8 ep_num)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint16 CSR;
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	kal_uint8 byCSR;
#endif
	kal_uint32 nCount = 0;
	
	USB_EP_Check(ep_num, USB_EP_RX_DIR, __LINE__);
	
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	DRV_WriteReg8(USB_INDEX, ep_num);
	CSR = DRV_Reg(USB_RXCSR);
	
	if(CSR&USB_RXCSR_RXPKTRDY)
		nCount = (kal_uint32)DRV_Reg(USB_RXCOUNT);
#elif defined(DRV_USB_IP_V2)
	if((READ_EPN_BDT_PID(ep_num, USB_BDT_RX)&VUSB_BDT_OWNS_BIT)==0)
	{
		nCount = (READ_EPN_BDT_PID(ep_num, USB_BDT_RX)&VUSB_BDT_BC_MASK) 
				>> VUSB_BDT_BC_SHIFT;
	}
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	DRV_WriteReg8(USB_INDEX,ep_num);
	byCSR = DRV_Reg8(USB_OUTCSR1);
	
	if(byCSR & USB_OUTCSR1_OUTPKTRDY)
	{
		nCount = (kal_uint32)DRV_Reg8(USB_OUTCOUNT1);
	}
#endif
	return nCount;
}	


/* ep out data already read out, clear the data*/
void USB_EP_Bulk_Rx_Ready(kal_uint8 ep_num)
{
	USB_EP_Check(ep_num, USB_EP_RX_DIR, __LINE__);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	DRV_WriteReg8(USB_INDEX, ep_num);
	DRV_WriteReg(USB_RXCSR, DRV_Reg(USB_RXCSR)&(~USB_RXCSR_RXPKTRDY));
#elif defined(DRV_USB_IP_V2)
	WRITE_EPN_BDT_PID(ep_num, USB_BDT_RX, 
				(g_UsbDrvInfo.ep_rx_max_data_size[ep_num-1] << VUSB_BDT_BC_SHIFT) |
				(g_UsbDrvInfo.ep_rx_data01[ep_num-1]<<VUSB_BDT_DATA01_SHIFT) |
				VUSB_BDT_DTS_BIT | VUSB_BDT_OWNS_BIT);
	g_UsbDrvInfo.ep_rx_data01[ep_num-1] ^= 1;
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	DRV_WriteReg8(USB_INDEX,ep_num);
	DRV_WriteReg8(USB_OUTCSR1, 0);
#endif
}

/* Get status. See if ep in fifo is empty. 
   If false, it means some data in fifo still wait to send out */
kal_bool USB_Is_EP_Bulk_Tx_Empty(kal_uint8 ep_num)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint16  	CSR;
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	kal_uint8 byCSR;
#endif
	kal_bool bRet;
	
	USB_EP_Check(ep_num, USB_EP_TX_DIR, __LINE__);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	DRV_WriteReg8(USB_INDEX, ep_num);	
	CSR = DRV_Reg(USB_TXCSR);
	if(CSR&USB_TXCSR_FIFONOTEMPTY)
		bRet = KAL_FALSE;
	else
		bRet = KAL_TRUE;	
#elif defined(DRV_USB_IP_V2)
	/* own bit 1 means the data is still not sent out */
	if((READ_EPN_BDT_PID(ep_num, USB_BDT_TX)&VUSB_BDT_OWNS_BIT)!=0)
		bRet = KAL_FALSE;
	else
		bRet = KAL_TRUE;	
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	DRV_WriteReg8(USB_INDEX, ep_num);	
	byCSR = DRV_Reg8(USB_INCSR1);
	if(byCSR&USB_INCSR1_FIFONOTEMPTY)
		bRet = KAL_FALSE;
	else
		bRet = KAL_TRUE;	
#endif
	
	return bRet;
}


/* Clear the FIFO for TX ep */
void USB_Clear_Tx_EP_FIFO(kal_uint8 ep_num,USB_ENDPT_TXFER_TYPE ep_type, kal_bool b_reset_toggle)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	DRV_WriteReg8(USB_INDEX, ep_num);
	DRV_WriteReg(USB_TXCSR, DRV_Reg(USB_TXCSR)|USB_TXCSR_FLUSHFIFO);
	DRV_WriteReg(USB_TXCSR, DRV_Reg(USB_TXCSR)|USB_TXCSR_FLUSHFIFO);
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	DRV_WriteReg8(USB_INDEX, ep_num);
	DRV_WriteReg8(USB_INCSR1, (DRV_Reg8(USB_INCSR1)|USB_INCSR1_FLUSHFIFO|USB_INCSR1_CLRDATATOG));
	DRV_WriteReg8(USB_INCSR1, (DRV_Reg8(USB_INCSR1)|USB_INCSR1_FLUSHFIFO|USB_INCSR1_CLRDATATOG));
//	DRV_WriteReg8(USB_INCSR1, USB_INCSR1_FLUSHFIFO);
//	DRV_WriteReg8(USB_INCSR1, USB_INCSR1_FLUSHFIFO);
#endif
}


/* clear the fifo for ep OUT*/
void USB_Clear_Rx_EP_FIFO(kal_uint8 ep_num,USB_ENDPT_TXFER_TYPE ep_type, kal_bool b_reset_toggle)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	DRV_WriteReg8(USB_INDEX, ep_num);
	DRV_WriteReg(USB_RXCSR, DRV_Reg(USB_RXCSR)|USB_RXCSR_FLUSHFIFO);
	DRV_WriteReg(USB_RXCSR, DRV_Reg(USB_RXCSR)|USB_RXCSR_FLUSHFIFO);
#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))
	DRV_WriteReg8(USB_INDEX, ep_num);
	DRV_WriteReg8(USB_OUTCSR1, (DRV_Reg8(USB_OUTCSR1)|USB_OUTCSR1_FLUSHFIFO|USB_OUTCSR1_CLRDATATOG));
	DRV_WriteReg8(USB_OUTCSR1, (DRV_Reg8(USB_OUTCSR1)|USB_OUTCSR1_FLUSHFIFO|USB_OUTCSR1_CLRDATATOG));
//	DRV_WriteReg8(USB_OUTCSR1, USB_OUTCSR1_FLUSHFIFO);
//	DRV_WriteReg8(USB_OUTCSR1, USB_OUTCSR1_FLUSHFIFO);
#endif
}



#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
/************************************************************
	USB 2.0 utilities
*************************************************************/
/* Check is high speed or full speed mode, only vaild when USB reset completely */
kal_bool USB_Is_High_Speed(void)
{
	kal_uint8	  usbpower = DRV_Reg8(USB_POWER);

	if((usbpower&USB_POWER_HSMODE) != 0)
		return KAL_TRUE;
	else
		return KAL_FALSE;	
}

void USB_High_Speed_Enable(kal_bool enable)
{
	if (enable == KAL_TRUE)
	DRV_WriteReg8(USB_POWER, (DRV_Reg8(USB_POWER)|USB_POWER_HSENAB));
	else
		DRV_WriteReg8(USB_POWER, (DRV_Reg8(USB_POWER)& ~USB_POWER_HSENAB));
}

#ifdef __USB_WITH_OTG_DETECT_VBUS__
kal_bool USB_Vbus_Status(void)
{    //only for MT6268MP test
#if (defined(DRV_USB_PHY_COST_DOWN))  
    DRV_WriteReg8(USB_PHYIR6_1 ,(DRV_Reg8(USB_PHYIR6_1)|USB_PHYIR6_1_VBUSCMP_EN));
#elif (defined(DRV_USB_PHY_U65_IP))  

#elif (defined(DRV_USB_PHY_U40_IP))      
    
#elif (defined(DRV_USB_PHY_M60_IP)) 
#else    
    DRV_WriteReg8(USB_PHYCR5_0 ,(DRV_Reg8(USB_PHYCR5_0)|USB_PHYCR5_0_VBUSCMP_EN));
#endif 



#if (defined(DRV_USB_PHY_COST_DOWN))  
    if (DRV_Reg8(USB_PHYIR3_1) & 0x04)
    	
#elif (defined(DRV_USB_PHY_U65_IP))      	

#elif (defined(DRV_USB_PHY_U40_IP))
      	
#elif (defined(DRV_USB_PHY_M60_IP))       	
#else
    if (DRV_Reg8(USB_PHYIR2_0) & 0x04)
#endif    	
        return KAL_TRUE;
    else    
        return  KAL_FALSE;
}
#endif

#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__

/* After Charger EINT, BMT call this function to pull high D- 100k, remove DP/DM 15K to ground */
void USB_Charger_Detect_Init(void)
{
 #if (defined(__USB_AND_UART_WITH_ONE_GPIO__)||defined(__USB_AND_UART_WITH_ONE_PORT__))
	USB_UART_Share(KAL_TRUE);
#endif 


#ifdef DRV_USB_PHY_COST_DOWN  //focus on PHY setting
	/* add 100K*/
	DRV_WriteReg8(USB_PHYCR2_3, USB_PHY_CLEAR_MASK); 
	DRV_WriteReg8(USB_PHYIR6_0, (USB_PHYIR6_0_RG_DP_100K_EN|USB_PHYIR6_0_RG_DM_100K_EN)); 
#if defined(DRV_MT6236_VERSION_CONTROL)
	DRV_WriteReg8(USB_PHYCR5_3, (USB_PHYCR5_3_OP_MODE|USB_PHYCR5_3_TERM_SELECT)); 
#else
	DRV_WriteReg8(USB_PHYCR5_3, (USB_PHYCR5_3_SUSPENDM|USB_PHYCR5_3_OP_MODE|USB_PHYCR5_3_TERM_SELECT)); 
#endif
	DRV_WriteReg8(USB_PHYCR3_3, (USB_PHYCR3_3_FORCE_OP_MODE|USB_PHYCR3_3_FORCE_TERM_SELECT|USB_PHYCR3_3_FORCE_SUSPENDM));
	DRV_WriteReg8(USB_PHYCR3_2, USB_PHYCR3_2_FORCE_DP_DM_PULLDOWN);  //QQ 	

#elif (defined(DRV_USB_PHY_U65_IP))  

#elif (defined(DRV_USB_PHY_U40_IP))  
	
#elif (defined(DRV_USB_PHY_M60_IP)) 
#else  //New PHY

#if  defined(DRV_USB_PHY_CHARGER_DETECT)
	/* Only for 38 E2 series add 100K resistor to D- */
	DRV_WriteReg8(USB_PHYCR1_0, USB_PHY_CLEAR_MASK);
	DRV_WriteReg8(USB_PHYCR3_2, DRV_Reg8(USB_PHYCR3_2)|USB_PHYCR3_2_TEST_CTRL2_SET|USB_PHYCR3_2_TEST_CTRL1_SET);

	DRV_WriteReg8(USB_PHYCR4_1, USB_PHYCR4_1_FORCE_BGR_ON);
	DRV_WriteReg8(USB_PHYCR5_3, USB_PHYCR5_3_TERM_SELECT|USB_PHYCR5_3_OP_MODE);
	DRV_WriteReg8(USB_PHYIR1_0, USB_PHYIR1_0_TX_VALID);

#ifdef DRV_USB_PHY_USB_UART_SHARE_PAD 
	DRV_WriteReg8(USB_PHYCR5_2, USB_PHYCR5_2_FORCE_OP_MODE|USB_PHYCR5_2_FORCE_TERM_SELECT|USB_PHYCR5_2_FORCE_SUSPENDM); // force  these initial value (not include UART part)
#else
	DRV_WriteReg8(USB_PHYCR5_2, USB_PHYCR5_2_UTMI_MUXSEL); // force all initial value
#endif
#else
	USB_Connect_R_To_DM_Control(KAL_TRUE);
#endif

	/* Remove 15K ohm pull down resistor */
	DRV_WriteReg8(USB_PHYCR5_3, DRV_Reg8(USB_PHYCR5_3)&~USB_PHYCR5_3_DP_DM_PULL_DOWN);
	DRV_WriteReg8(USB_PHYCR2_3, DRV_Reg8(USB_PHYCR2_3)|USB_PHYCR2_3_FORCE_DP_DM_PULLDOWN);
	
#endif	
}


kal_bool USB_Detect_Is_Charger_In(void)
{
#ifdef DRV_USB_PHY_COST_DOWN  
	if((DRV_Reg8(USB_LINE_STATE)& USB_PHYIR3_0_LINESTATE_DM) != 0)
#elif (defined(DRV_USB_PHY_U65_IP)) 
	if((DRV_Reg8(USB_LINE_STATE)& USB_U2PHYDMON0_2_LINESTATE_DM) != 0) 		
#elif (defined(DRV_USB_PHY_M60_IP)) 
	#if defined(DRV_USB_IP_V3)
	USB_DRV_Reg8(USB_DUMMY);
	#endif);
	if((USB_DRV_Reg32(USB_LINE_STATE)&USB_U2PHYDMON1_USB20_LINE_STATE_DM) != 0)
#elif (defined(DRV_USB_PHY_U40_IP))  
	if (0)
#else
	if((DRV_Reg8(USB_LINE_STATE)& USB_PHYIR1_3_LINESTATE_DM) != 0)
#endif		
		
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

void USB_Charger_Detect_Release(void)
{
#ifdef DRV_USB_PHY_COST_DOWN  //focus on PHY setting

	/* remove 100K  & pull up & down resistor */ 
	DRV_WriteReg8(USB_PHYCR2_3, USB_PHYCR2_3_PLL_EN); 
	DRV_WriteReg8(USB_PHYIR6_0, USB_PHY_CLEAR_MASK); 
#if defined(DRV_MT6236_VERSION)
	DRV_WriteReg8(USB_PHYCR5_3, USB_PHYCR5_3_SUSPENDM);
#else
	DRV_WriteReg8(USB_PHYCR5_3, USB_PHY_CLEAR_MASK); 
#endif
	DRV_WriteReg8(USB_PHYCR3_2, USB_PHY_CLEAR_MASK);
	DRV_WriteReg8(USB_PHYCR3_3, USB_PHY_CLEAR_MASK); 

#elif (defined(DRV_USB_PHY_U65_IP))  

#elif (defined(DRV_USB_PHY_U40_IP))  

#elif (defined(DRV_USB_PHY_M60_IP)) 
#else //New PHY

#if  defined(DRV_USB_PHY_CHARGER_DETECT)
	/* For 38 E2, Remove 100K resistor to D- */
	DRV_WriteReg8(USB_PHYCR1_0, USB_PHYCR1_0_PLL_EN);

	DRV_WriteReg8(USB_PHYCR3_2, DRV_Reg8(USB_PHYCR3_2)&~USB_PHYCR3_2_TEST_CTRL_MASK);
	DRV_WriteReg8(USB_PHYCR3_2, DRV_Reg8(USB_PHYCR3_2)|USB_PHYCR3_2_TEST_CTRL1_SET);
	DRV_WriteReg8(USB_PHYCR4_1, USB_PHYCR4_1_FORCE_BGR_ON);
	DRV_WriteReg8(USB_PHYCR5_3, USB_PHY_CLEAR_MASK);
	DRV_WriteReg8(USB_PHYIR1_0, USB_PHY_CLEAR_MASK);
	DRV_WriteReg8(USB_PHYCR5_2, USB_PHY_CLEAR_MASK);
#else
	USB_Connect_R_To_DM_Control(KAL_FALSE);
#endif

	/* Remove 15K ohm pull down resistor */
	DRV_WriteReg8(USB_PHYCR2_3, DRV_Reg8(USB_PHYCR2_3)&~USB_PHYCR2_3_FORCE_DP_DM_PULLDOWN);

	/* Remove D+ 1.5K ohm pull up resistor */
	DRV_WriteReg8(USB_PHYCR5_2, DRV_Reg8(USB_PHYCR5_2)&~USB_PHYCR5_2_FORCE_DP_HIGH);
#endif
}

#endif

void USB_Reset_FIFO(void)
{
	g_FIFOadd = USB_FIFO_START_ADDRESS;
}

#endif

/************************************************************
	HISR/LISR   interrupt handler
*************************************************************/

#ifdef USBDL_DEBUG
//#pragma arm section zidata = "LARGE_BUFFER"
typedef struct
{
	kal_uint8 usb;
	kal_uint8 in;
	kal_uint8 out;
}usb_hisr_int;
#ifdef __MTK_TARGET__
__attribute__ ((section ("LARGE_BUFFER"))) 
#endif /* __MTK_TARGET__ */
usb_hisr_int intarray[256];
#ifdef __MTK_TARGET__
__attribute__ ((section ("LARGE_BUFFER"))) 
#endif /* __MTK_TARGET__ */
kal_uint8 int_index;
//#pragma arm section zidata
#endif



void USB_HISR(void)
{
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	kal_uint8    IntrUSB;
	kal_uint16  IntrTx;
	kal_uint16  TXCSR;
	kal_uint16  RXCSR;
	kal_uint16  IntrRx;
	kal_uint32  ep_num;
	//kal_uint8    USBMode;


	IntrUSB = DRV_Reg8(USB_INTRUSB);
	#if defined(DRV_USB_IP_V4)
	USB_DRV_WriteReg8(USB_INTRUSB, IntrUSB);
	#endif
	
	// Write 1 clear
	IntrTx = DRV_Reg(USB_INTRTX);
	DRV_WriteReg(USB_INTRTX, IntrTx);
	// Write 0 clear
	IntrRx = DRV_Reg(USB_INTRRX);
	#if defined(DRV_USB_IP_V4)
	USB_DRV_WriteReg(USB_INTRRX, IntrRx);
	#else
	USB_DRV_WriteReg(USB_INTRRX, ~IntrRx);
	#endif
	
	//USBMode = DRV_Reg8(USB_POWER);

//	USB_Dbg_Trace(USB_DBG_HISR, drv_get_current_time(), (kal_uint32)IntrUSB, (kal_uint32)USBMode);
	// Reset must be the highest priority ISR
	/* Check for reset interrupt */
	if(IntrUSB&USB_INTRUSB_RESET)
	{
		if(g_UsbDrvInfo.reset_hdlr == NULL)
			ASSERT(0);
		/* Set SW_RST bit here, so we do not care about any following ep interrupts */
		g_UsbDrvInfo.reset_hdlr();
		IntrTx = 0;
		IntrRx = 0;
	}

	/* Check for resume from suspend mode */
	if (IntrUSB & USB_INTRUSB_RESUME)
	{
		g_UsbDrvInfo.power_state = USB_STATE_NORMAL;
		
		if (USB_Is_High_Speed() == KAL_TRUE)
			g_UsbDrvInfo.Is_HS_mode = KAL_TRUE;
		else
			g_UsbDrvInfo.Is_HS_mode = KAL_FALSE;			

//		g_UsbDrvInfo.resume_hdlr();
		/* When from PERIPHERAL to SUSPEND, the device_up is still TRUE */

   	}
		/* Check for endpoint 0 interrupt */
		if(IntrTx&USB_INTRTX_EP0)
		{
			if(g_UsbDrvInfo.ep0_hdlr == NULL)
				ASSERT(0);

			g_UsbDrvInfo.ep0_hdlr();
		}

		/* Check for Bulk TX interrupt */
		/* TX interrupt : 1.TxPktRdy is clear, 2. SENTSTALL is set */
		for(ep_num = 1; ep_num <= MAX_TX_EP_NUM; ep_num++)
		{
			if (IntrTx&(0x01 <<ep_num))
			{
				DRV_WriteReg8(USB_INDEX, ep_num);
				TXCSR = DRV_Reg(USB_TXCSR);

				if((TXCSR&USB_TXCSR_SENTSTALL) != 0)
				{
					/* Only clear SENTSTALL bit */
					TXCSR &= ~USB_TXCSR_SENTSTALL;
					DRV_WriteReg(USB_TXCSR, TXCSR);
				}
				else
				{
					if(g_UsbDrvInfo.ep_tx_hdlr[ep_num-1] != NULL)
					{
						g_UsbDrvInfo.ep_tx_hdlr[ep_num -1]();
						
//						while(DRV_Reg(USB_TXCSR) & USB_TXCSR_TXPKTRDY);	
						if (DRV_Reg(USB_TXCSR)& USB_TXCSR_TXPKTRDY)
									ASSERT(0);						
					}
					else
					{
						if(g_UsbDrvInfo.ep_tx_flush_intr[ep_num -1] == KAL_TRUE)
						{
							g_UsbDrvInfo.ep_tx_flush_intr[ep_num -1] = KAL_FALSE;
						}
						else
						{
							/* Save debug info */
	//						USB_Dbg_Trace(USB_EPN_UNEXPECTED_TX_HISR, drv_get_current_time(), (kal_uint32)TXCSR, DRV_Reg8(USB_INTRTXE));
						}
					}
				}
			}
		}

		/* Check for Bulk RX interrupt */
		/* RX interrupt : 1.RxPktRdy is set, 2. SENTSTALL is set */
		for(ep_num = 1; ep_num <= MAX_RX_EP_NUM; ep_num++)
		{
			if(IntrRx&(0x01<<ep_num))
			{
				DRV_WriteReg8(USB_INDEX, ep_num);
				RXCSR = DRV_Reg(USB_RXCSR);

				if((RXCSR&USB_RXCSR_SENTSTALL) != 0)
				{
					RXCSR &= ~USB_RXCSR_SENTSTALL;
					DRV_WriteReg(USB_RXCSR, RXCSR);
				}
				else if((RXCSR&USB_RXCSR_RXPKTRDY) != 0)
				{
					if(g_UsbDrvInfo.ep_rx_hdlr[ep_num-1] != NULL)
					{
						g_UsbDrvInfo.ep_rx_hdlr[ep_num -1]();
					}
					else
					{
						/* No handler to receive this packet */
						ASSERT(0);
					}
				}
				else
				{
/*
					if(g_UsbDrvInfo.ep_rx_flush_intr[ep_num -1] == KAL_TRUE)
					{
						g_UsbDrvInfo.ep_rx_flush_intr[ep_num -1] = KAL_FALSE;
					}
					else
					{
						//Save debug info
						//USB_Dbg_Trace(USB_EPN_UNEXPECTED_RX_HISR, drv_get_current_time(), (kal_uint32)RXCSR, DRV_Reg8(USB_INTRRXE));
					}
*/
				}
			}
		}

#elif defined(DRV_USB_IP_V2)
	volatile kal_uint8	IntrStatus;
	volatile kal_uint8	FMStatus;
	volatile kal_uint8	ErrorStatus;
	volatile kal_uint8	PhyStatus;
	volatile kal_uint8	direction;
	volatile kal_uint8	even_odd;
	volatile kal_uint8	ep_num;	
	volatile kal_bool	fast_mode_enable;	  
	usb_dma_callback	callback;

	fast_mode_enable = (DRV_Reg8(USB_FM_CTL)&VUSB_FM_CTL_FMENB) ? KAL_TRUE : KAL_FALSE;
	IntrStatus = DRV_Reg8(USB_INT_STAT);
	FMStatus = DRV_Reg8(USB_FM_ERR_STAT);
	ErrorStatus = DRV_Reg8(USB_ERR_STAT);
	PhyStatus = DRV_Reg8(USB_PHY_EXTRA);

//	USB_Ms_Dbg_Trace(OTG_DEVICE_INTR, IntrStatus);

	if (PhyStatus & VUSB_PHY_RESUME_INT)
	{
		DRV_WriteReg8(USB_PHY_EXTRA, PhyStatus & (~VUSB_PHY_SUSPEND));
 		g_UsbDrvInfo.power_state = USB_STATE_NORMAL;		
// 		USB_Resume();
	} /* End resume */

	if (IntrStatus & VUSB_INT_STAT_RESET)
	{
		
//		USB_Resume();

		USB_Initialize_Drv();
		if(g_UsbDrvInfo.reset_hdlr == NULL)
			EXT_ASSERT(0, 0, 0, 0);
   		g_UsbDrvInfo.reset_hdlr();

   		/* Clear interrupt other than token done*/
		DRV_WriteReg8(USB_INT_STAT, IntrStatus);
		DRV_WriteReg8(USB_ERR_STAT, ErrorStatus);		

		return;
	} /* End VUSB_INT_STAT_RESET */

		/* Ignore VUSB_INT_STAT_TOKEN_DONE in fast mode */
		if(((IntrStatus&VUSB_INT_STAT_TOKEN_DONE)&&(fast_mode_enable==KAL_FALSE)) || (FMStatus&VUSB_FM_ERR_STAT_TOKEN_DONE))
		{
			/* Parse FM status first */		
			if(FMStatus&VUSB_FM_ERR_STAT_TOKEN_DONE)
			{
				direction = (DRV_Reg8(USB_FM_ADDITNL_STAT) >> 3) & 0x01;
				even_odd = (DRV_Reg8(USB_FM_ADDITNL_STAT) >> 2) & 0x01;
				ep_num = (DRV_Reg8(USB_FM_ADDITNL_STAT) >> 4) & 0x0f;
			}
			else
			{
				direction = (DRV_Reg8(USB_STAT) >> 3) & 0x01;
				even_odd = (DRV_Reg8(USB_STAT) >> 2) & 0x01;
				ep_num = (DRV_Reg8(USB_STAT) >> 4) & 0x0f;
			}

			/* Note that token done should be cleared here in case FM is set during ep handler, 
			     so that intr will move to fm_intr*/
			/* Ignore token done in fast mode, so no clear its intr status in FM */
			/* First handle VUSB_FM_ERR_STAT_TOKEN_DONE, so do not clear token done intr status */
			if((fast_mode_enable==KAL_TRUE) || (FMStatus&VUSB_FM_ERR_STAT_TOKEN_DONE)) 
			{
				DRV_Reg8(USB_FM_ERR_STAT) = FMStatus;
			}
			else
			{
				DRV_WriteReg8(USB_INT_STAT, (IntrStatus&VUSB_INT_STAT_TOKEN_DONE));
			}
			
			if(ep_num==0)
			{
				g_UsbDrvInfo.ep0_current_dir = direction;
				/* Receive*/
				if(direction==USB_BDT_RX)
				{
					/* This one is received, software should handle this packet*/
					g_UsbDrvInfo.ep0_rx_even_odd = even_odd;

					if((g_UsbDrvInfo.ep0_transaction_type==USB_EP0_TRANS_TX_DATA)
						||(g_UsbDrvInfo.ep0_transaction_type==USB_EP0_TRANS_TX_DATA_END))
					{
						/* Host send status stage before Device expects*/
						g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_END;
					}	

					if(g_UsbDrvInfo.ep0_transaction_type==USB_EP0_TRANS_TX_STATUS)
					{
						/* Host send status stage and match Device's expection */
						WRITE_EP0_BDT_PID(USB_BDT_RX, g_UsbDrvInfo.ep0_rx_even_odd, 
											(USB_EP0_MAXP << VUSB_BDT_BC_SHIFT) |VUSB_BDT_OWNS_BIT);
						g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_NONE;
					}
				}
				else
				{
					/* This one is transmitted, software will fill next packet*/
					g_UsbDrvInfo.ep0_tx_even_odd = even_odd^1;	

					if(g_UsbDrvInfo.ep0_transaction_type==USB_EP0_TRANS_RX_DATA)
					{
						g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_END;
					}	

					if(g_UsbDrvInfo.ep0_transaction_type==USB_EP0_TRANS_TX_DATA_END)
					{
						g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_TX_STATUS;
					}
					
					if(g_UsbDrvInfo.ep0_transaction_type==USB_EP0_TRANS_RX_STATUS)
					{
						g_UsbDrvInfo.ep0_transaction_type = USB_EP0_TRANS_NONE;
					}
				}

				if(g_UsbDrvInfo.ep0_hdlr == NULL)
					EXT_ASSERT(0, 0, 0, 0);
   				g_UsbDrvInfo.ep0_hdlr();
			}
			else if(direction == USB_BDT_RX)    /* Receive*/
			{
				if(g_UsbDrvInfo.ep_rx_hdlr[ep_num-1]!=NULL)
   					g_UsbDrvInfo.ep_rx_hdlr[ep_num -1]();
   				/* Not handle else because the fm token done may happen here */	
			}
			else	 	/* Send */
			{
				if(g_UsbDrvInfo.ep_tx_hdlr[ep_num-1]!=NULL)
   					g_UsbDrvInfo.ep_tx_hdlr[ep_num -1]();
				/* Not handle else because the fm token done may happen here */		

				if(g_UsbDrvInfo.fast_mode_tx_ep == ep_num)
				{
					/* This is Fast mode token done intr */
					g_UsbDrvInfo.fast_mode_tx_ep = 0;	

					if((g_UsbDrvInfo.dma_res_tx_ep==0)&&(g_UsbDrvInfo.dma_tx_ep ==0))
					{
						/* No TX data residue, and DMA callback function has been done */
						callback = g_UsbDrvInfo.dma_callback[ep_num-1];
						g_UsbDrvInfo.dma_callback[ep_num-1] = NULL;
						if(callback!=NULL)
							callback();
					}
				}
				else if(g_UsbDrvInfo.dma_res_tx_ep == ep_num)
				{
					/* This is the last residue packet token done intr*/
					g_UsbDrvInfo.dma_res_tx_ep = 0;
					
					callback = g_UsbDrvInfo.dma_callback[ep_num-1];
					g_UsbDrvInfo.dma_callback[ep_num-1] = NULL;
					if(callback!=NULL)
						callback();
				}
			}	
		} /* End VUSB_INT_STAT_TOKEN_DONE*/

	if (IntrStatus & VUSB_INT_STAT_SLEEP)
	{
		g_UsbDrvInfo.power_state = USB_STATE_SUSPEND;
		DRV_WriteReg8(USB_PHY_EXTRA, PhyStatus |VUSB_PHY_SUSPEND);
		//if(g_UsbDrvInfo.power_state != USB_STATE_SUSPEND)
//		USB_Suspend();
	} /* End VUSB_INT_STAT_SLEEP */

	if (IntrStatus & VUSB_INT_STAT_ERROR)
	{
	}/* End VUSB_INT_STAT_ERROR */

	if (IntrStatus & VUSB_INT_STAT_STALL)
	{
	}/* End VUSB_INT_STAT_STALL */

	/* Clear interrupt other than token done*/
	DRV_WriteReg8(USB_INT_STAT, (IntrStatus&(~VUSB_INT_STAT_TOKEN_DONE)));
	DRV_WriteReg8(USB_ERR_STAT, ErrorStatus);

#elif (defined(DRV_USB_IP_V1)||defined(DRV_USB_IP_V1_PLUS))

	kal_uint8    IntrUSB;
	kal_uint8    IntrIn;
	kal_uint8    IntrOut;
//	kal_uint32  ep_num;

	IntrUSB = DRV_Reg8(USB_INTRUSB);
	IntrIn = DRV_Reg8(USB_INTRIN1);
	IntrOut = DRV_Reg8(USB_INTROUT1);

	if((IntrUSB == 0)&&(IntrIn== 0)&&(IntrOut == 0))
		return;

#ifdef USBDL_DEBUG	
	intarray[int_index].usb = IntrUSB;
	intarray[int_index].in = IntrIn;
	intarray[int_index].out = IntrOut;
	int_index++;
#endif

   	/* Check for resume from suspend mode */
   	if (IntrUSB & USB_INTRUSB_RESUME)
   	{
//   		USB_Drv_Resume();
   		g_UsbDrvInfo.power_state = USB_STATE_NORMAL;
   	}

	/* Check for reset interrupts */
	if (IntrUSB & USB_INTRUSB_RESET)
	{
		USB_Initialize_Drv();
		if(g_UsbDrvInfo.reset_hdlr == NULL)
			ASSERT(0);
		g_UsbDrvInfo.reset_hdlr();
	}

	/* Check for endpoint 0 interrupt */
	if (IntrIn&USB_INTRIN1_EP0)
	{
		if(g_UsbDrvInfo.ep0_hdlr == NULL)
			EXT_ASSERT(0, 0, 0, 0);
		g_UsbDrvInfo.ep0_hdlr();
	}

	/* Check for Bulk TX interrupt */
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
	#endif

	if (IntrIn&USB_INTRIN1_EP1)
		g_UsbDrvInfo.ep_tx_hdlr[0]();
	
	/* Check for Bulk RX interrupt */
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
	#endif

	if (IntrOut&USB_INTROUT1_EP1)
		g_UsbDrvInfo.ep_rx_hdlr[0]();
	
   	/* Check for suspend mode */
   	if (IntrUSB &  USB_INTRUSB_SUSPEND)
   	{
//   		USB_Drv_Suspend();
		g_UsbDrvInfo.power_state = USB_STATE_SUSPEND;
   	}
#endif

	if(usbdl_holding_mode && USBDL_WDTKICK)
	{
		WDT_Restart();
	} 	
}

#if (defined(__USB_AND_UART_WITH_ONE_GPIO__)||defined(__USB_AND_UART_WITH_ONE_PORT__))
void USB_UART_Share(kal_bool USB_mode)
{	
#ifdef DRV_USB_PHY_USB_UART_SHARE_PAD  //USB IP3

#ifdef DRV_USB_PHY_COST_DOWN  //focus on PHY setting

	if (USB_mode)
	{
		DRV_WriteReg8(USB_PHYCR4_0, USB_PHYCR4_0_FORCE_USB_CLKOFF); 
		DRV_WriteReg8(USB_PHYCR3_3, USB_PHY_CLEAR_MASK); 
			
  	}
  	else
  	{
		DRV_WriteReg8(USB_PHYCR4_0, USB_PHYCR4_0_FORCE_AUX_EN); 
		DRV_WriteReg8(USB_PHYCR3_3, USB_PHYCR3_3_FORCE_SUSPENDM); 			

  	}
#elif (defined(DRV_USB_PHY_U65_IP))  

#elif (defined(DRV_USB_PHY_U40_IP))    	
  	
#elif (defined(DRV_USB_PHY_M60_IP)) 
#else  //focus on PHY setting
	if (USB_mode)
	{
		DRV_WriteReg8(USB_PHYIR2_3, USB_PHYIR2_3_FORCE_USB_CLKOFF);
  		DRV_WriteReg8(USB_PHYCR5_2, USB_PHY_CLEAR_MASK);
  	}
  	else
  	{
  		DRV_WriteReg8(USB_PHYIR2_3, USB_PHYIR2_3_FORCE_AUX_EN);
  		DRV_WriteReg8(USB_PHYCR5_2, USB_PHYCR5_2_FORCE_SUSPENDM);
  	}

#endif  	
  	
#else    //USB IP1 IP2 
     PMIC_Power_Control(KAL_FALSE);
     if (USB_mode)
     {
	   	UART_and_USB_Switch(KAL_TRUE);
     }
     else
     {
	   	UART_and_USB_Switch(KAL_FALSE);
     }
#endif	
}
#endif

#endif /* __USB_DOWNLOAD__ */


