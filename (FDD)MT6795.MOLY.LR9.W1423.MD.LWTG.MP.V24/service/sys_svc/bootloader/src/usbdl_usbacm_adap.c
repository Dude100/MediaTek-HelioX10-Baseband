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
 *    usbacm_adap.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements usb adaption layer for UART API
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef  __USB_DOWNLOAD__

#if defined(__USBDL_BOOTROM__)
#include "usbdl_bootrom.h"
#else
#include "drv_comm.h"
//#include "intrCtrl.h"

#include "usb_comm.h"
#include "usbdl_usb.h"
#include "usbdl_usbacm_drv.h"
#include "usbdl_usb_resource.h"
#include "usb_custom.h"

#include "reg_base.h"
//#include "config_hw.h"
#include "wdt_hw.h"
#include "uart_sw.h"
//#include "kal_non_specific_general_types.h"
#include "usbdl_usb_drv.h"
#endif

//==========================
//customer will use Production Release,Watchdog should be kicked to prevent watchdog reset
#define WDT_Restart()  DRV_WriteReg(WDT_RESTART,WDT_RESTART_KEY)
//==========================

extern void GPIO_init(void);
extern void DRV_RESET(void);
extern void InitUSBDLGPIO(void);
extern void USB_Release_Acm_Status(void);
extern kal_bool USBDL_Is_Timeout(void);

#ifdef __SECURE_COSIM__
#define Delay_Count      1080
#else
#define Delay_Count      324675
#endif //__SECURE_COSIM__

usbacm_buf_struct usbacm_tx_buf;
usbacm_buf_struct usbacm_rx_buf;

static kal_bool USBDL_Mode;
kal_bool USBDL_WDTKICK = KAL_TRUE;

extern void USBDL_USBPowerON(kal_bool power_on);
extern kal_bool USBDLKey_Pressed(void);

kal_bool USBDL_Update_USB_Download_Mode(void)
{
	extern kal_bool USBDL_Ready_To_Enter_DLMode();

	if (USBDL_Ready_To_Enter_DLMode()== KAL_TRUE)
	{
		if(gUsbDevice.nDevState == DEVSTATE_CONFIG)
			USBDL_Mode = KAL_TRUE;
		else
			USBDL_Mode = KAL_FALSE;

		return KAL_TRUE;
	}
	else
	{
		USBDL_Mode = KAL_FALSE;
		return KAL_FALSE;	
	}
}


kal_bool USBDL_Is_USB_Download_Mode(void)
{
	return USBDL_Mode;
}

void USBDL_SetWDTMode(kal_bool wdtkick)
{
    USBDL_WDTKICK = wdtkick;
}
/*
	Initialize power down fuction, DMA and USB comport
*/
void USBDL_hwInit(void)
{
	volatile kal_uint32 delay;

	// configure GPIO/GPO for D+
	// 1. GPIO/GPO is used as D+
	// 2. the reset value of GPIO/GPO is not GPIO/GPO mode and the level is high
	// 3. set the mode to GPIO/GPO mode and set the output to low level
	/* After GPIO_init, D+ will be pulled low */
	
#ifndef __USBDL_IN_BOOTROM__	
	GPIO_init();  //Because MAUI will check GPIO to decided Factory mode, GPIO should not be changed.(Setup Com Port second time)
#endif
	
/*
#ifdef __USB_AND_UART_WITH_ONE_GPIO__
	USB_UART_Share(KAL_TRUE);
#else
	USB_PowerControl(KAL_FALSE);
#endif
*/
	/* turn on USB controller and UPLL, but not pull high D+!!*/
	USBDL_USBPowerON(KAL_TRUE);	
	// delay for a while to make host identify the D+ low, or the host will ignore it.
	for(delay = 0; delay < 1000; delay++);
}

/* 
	1. initialize the cdc acm for usb download
	2. there is no USB task, NVRAM task and no interrupt
*/
void USBDL_ACMInit(kal_bool pull_up)
{

	/* get customize parameters*/
	gUsbDevice.device_param = USB_GetCustomFunc()->get_device_param_func();
	g_UsbACM.acm_param = USB_GetCustomFunc()->get_acm_param_func();

#ifdef  __USB_COMPORT_SUPPORT_TC01_DRIVER__
	USB_Register_CreateFunc("ACM COMMU.", USB_Acm_CommIf_Create,USB_Acm_CommIf_Reset, USB_Acm_CommIf_Speed_Reset);
	USB_Register_CreateFunc("ACM DATA", USB_Acm_DataIf_Create,USB_Acm_DataIf_Reset,USB_Acm_DataIf_Speed_Reset); //use modem port
	USB_Register_CreateFunc("ACM VIRTUALCOM", USB_Acm_VirtualIf_Create,USB_Acm_VirtualIf_Reset,USB_Acm_VirtualIf_Speed_Reset);  //diagnostic port for USBDL
#else
	USB_Register_CreateFunc("ACM DATA", USB_Acm_DataIf_Create,USB_Acm_DataIf_Reset,USB_Acm_DataIf_Speed_Reset);
	USB_Register_CreateFunc("ACM COMMU.", USB_Acm_CommIf_Create,USB_Acm_CommIf_Reset, USB_Acm_CommIf_Speed_Reset);
#endif
	USB_Register_Device_Code(USB_ACM_DEVICE_CODE, USB_ACM_SUBCLASS_CODE, 
								USB_ACM_PROTOCOL_CODE, g_UsbACM.acm_param->desc_product);

	if (pull_up == KAL_TRUE)
	{							
		USB_Init(USB_CDC_ACM, KAL_TRUE, KAL_TRUE);
	}	
	else
	{
		USB_Init(USB_CDC_ACM, KAL_TRUE, KAL_FALSE);
	}
}


kal_bool  USBDL_UART_Init(void)
{
	volatile kal_uint32 delay=0;
	kal_bool result = KAL_FALSE;
	gUsbDevice.nDevState = DEVSTATE_DEFAULT;
	USBDL_Mode = KAL_FALSE;
	WDT_Restart();
	
//#ifndef __USBDL_IN_BOOTROM__
	USBDL_hwInit();
//#endif

	InitUSBDLGPIO();
	
	USBDL_ACMInit(KAL_TRUE);

	/* wait PC set_config or DL key or  DL GPIO or DL timer  is un-pressed */
	while((USBDL_Update_USB_Download_Mode() == KAL_TRUE) && (gUsbDevice.nDevState != DEVSTATE_CONFIG))
	{
		delay ++;
		USB_HISR();
		if (delay == 5000)
		{			
			WDT_Restart();
			delay = 0;
		}
	}
	WDT_Restart();	
	g_UsbACM.line_coding.dwDTERate = 115200;
	g_UsbACM.line_coding.bCharFormat = 0;
	g_UsbACM.line_coding.bParityType = 0;	
	g_UsbACM.line_coding.bDataBits = 8;
	   	
	USB2UARTPort.initialized = KAL_TRUE;	   	

	USB_TxEPEn(g_UsbACM.txpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_NO_DMA, KAL_TRUE, KAL_FALSE);
	USB_RxEPEn(g_UsbACM.rxpipe->byEP, USB_ENDPT_BULK, USB_EP_USE_NO_DMA, KAL_TRUE, KAL_FALSE);

	if (gUsbDevice.nDevState == DEVSTATE_CONFIG)
	{
//		USB_timeout = KAL_TRUE;
		result = KAL_TRUE;
	}	
	
	return result;
}

void USBDL_Release(void)
{
#if (defined(__USB_AND_UART_WITH_ONE_GPIO__)||defined(__USB_AND_UART_WITH_ONE_PORT__))
    USB_UART_Share(KAL_FALSE);
#endif

		USB_Release_Acm_Status();
        		
		USB_DeRegister_CreateFunc();
		USB_DeRegister_Device_Code();
			
    // turn off USB controller and UPLL 
	USBDL_USBPowerON(KAL_FALSE);	

    // restore original GPIO setting 
//	GPIO_deinit();

	USBDL_Mode = KAL_FALSE;
	//jump to MAUI load (doesn't have to release SW variable)
}

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
kal_bool USB_Charger_Detect(void)
{
	volatile kal_uint32 delay;
	kal_bool  plugin_type;
	
	//USBDL_hwInit();  //USB Power on
	
	USB_Charger_Detect_Init();
	
	for (delay = 0;delay < 1000;delay++);
	
	plugin_type = USB_Detect_Is_Charger_In(); 
	USB_Charger_Detect_Release();  //Release detect resistor
	//USBDL_USBPowerON(KAL_FALSE);   //USB Power off	 
	return plugin_type;
}
#endif
#endif

void USBDL_PutUARTByte_Ext(kal_uint8 data,kal_bool blocking_api)
{
	kal_uint8 	ep_num;
	kal_uint32      Data_Packet_Length;


	if ((blocking_api == KAL_FALSE) && (USBDL_Is_Timeout()==KAL_TRUE))
		return;

				
#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	if (USB_Is_High_Speed() == KAL_TRUE)
		Data_Packet_Length = USBDL_EP_BULK_MAXP;
	else
		Data_Packet_Length = USB_EP_BULK_MAXP_FS;
#else
 	Data_Packet_Length = USBDL_EP_BULK_MAXP;
#endif

	if(gUsbDevice.nDevState == DEVSTATE_CONFIG)
	{
		usbacm_tx_buf.data[usbacm_tx_buf.len] = data;
		usbacm_tx_buf.len++;

		if(usbacm_tx_buf.len != Data_Packet_Length )
		{
			/* gather the data until one USB MAX packet size */
			return;
		}
		else
		{
			ep_num = g_UsbACM.txpipe->byEP;
			gUSBAcm_IsInEPComplete = KAL_FALSE;		
			USB_EPFIFOWrite(ep_num, Data_Packet_Length , usbacm_tx_buf.data);
			USB_EP_Bulk_Tx_Ready(ep_num);

			while(gUSBAcm_IsInEPComplete == KAL_FALSE)
			{
				USB_HISR();
				
			
				if ((blocking_api == KAL_FALSE) && (USBDL_Is_Timeout()==KAL_TRUE))
				{
					break;
				}	
			}
			usbacm_tx_buf.len = 0;
		}
	}	
}

void USBDL_PutUARTByte(kal_uint8 data)
{
	USBDL_PutUARTByte_Ext(data, KAL_TRUE);
}


/*
	It is called by bootloader to flush the tx buffer into USB FIFO
*/



void USBDL_PutUARTByte_Complete_Ext(kal_bool blocking_api)
{
	kal_uint8 	ep_num;

	if ((blocking_api == KAL_FALSE) && (USBDL_Is_Timeout()==KAL_TRUE))
		return;
	
	if ((gUsbDevice.nDevState == DEVSTATE_CONFIG)&&(usbacm_tx_buf.len != 0))
	{
		ep_num = g_UsbACM.txpipe->byEP;
		gUSBAcm_IsInEPComplete = KAL_FALSE;		
		USB_EPFIFOWrite(ep_num, (kal_uint16)usbacm_tx_buf.len, usbacm_tx_buf.data);
		USB_EP_Bulk_Tx_Ready(ep_num);

		while(gUSBAcm_IsInEPComplete == KAL_FALSE)
		{
			USB_HISR();
			
			if ((blocking_api == KAL_FALSE) && (USBDL_Is_Timeout()==KAL_TRUE))
			{
				usbacm_tx_buf.len = 0;			
				return;
			}	
		}
		usbacm_tx_buf.len = 0;
	}
}
void USBDL_PutUARTByte_Complete(void)
{
	USBDL_PutUARTByte_Complete_Ext(KAL_TRUE);
}



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
#else

kal_uint8 USBDL_GetUARTByte_Ext(kal_bool blocking_api)
{
	static kal_uint32 index = 0;
	 
	if ((blocking_api == KAL_FALSE) && (USBDL_Is_Timeout()==KAL_TRUE))
		return 0;
 
	if(index == usbacm_rx_buf.len)
	{
		/* All data have been read */
		usbacm_rx_buf.len = 0;
		index = 0;
	}

	/* Get data from FIFO only when local buffer is empty  */
	while(usbacm_rx_buf.len == 0)
	{
		USB_HISR();
				
		if ((blocking_api == KAL_FALSE) && (USBDL_Is_Timeout()==KAL_TRUE))
		{
			break;
		}
	}
	
	return usbacm_rx_buf.data[index++];
}


kal_uint8 USBDL_GetUARTByte(void)
{
	return USBDL_GetUARTByte_Ext(KAL_TRUE);
}


#endif



// this can be omited for USB COM
void USBDL_CheckUARTSendEnd(void)
{
}



//////////////////////////////////// USB has allready setup in BootRom  //////////////////////////////

void USBDL_USB_Config_Init(void)
{
	USBDL_ACMInit(KAL_FALSE);
	WDT_Restart();	
	
	g_UsbACM.line_coding.dwDTERate = 115200;
	g_UsbACM.line_coding.bCharFormat = 0;
	g_UsbACM.line_coding.bParityType = 0;	
	g_UsbACM.line_coding.bDataBits = 8;
	   	
	USB2UARTPort.initialized = KAL_TRUE;	  

	gUsbDevice.nDevState = DEVSTATE_CONFIG;
	USBDL_Mode = KAL_TRUE;
}

#ifdef __USBDL_IN_BOOTROM__
kal_bool USBDL_GetUARTByte_ONCE(kal_uint8* data)
{
  // read TXIntr / RXIntr for EP0 Command & Start_Command(data)
   	 
	USB_HISR();
		
	if (usbacm_rx_buf.len == 0)
	{
		*data = 0;			
		return KAL_FALSE;
	}
	else
	{	
		*data = usbacm_rx_buf.data[0];	
		usbacm_rx_buf.len = 0;
		return KAL_TRUE;
	}
}

#endif


#endif  /* __USB_DOWNLOAD__ */

