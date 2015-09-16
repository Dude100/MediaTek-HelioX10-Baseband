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
 *    usbdl_usb.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements USB driver for USB download
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifdef  __USB_DOWNLOAD__

#if defined(__USBDL_BOOTROM__)
#include "usbdl_bootrom.h"
#else
//MSBB remove #include "kal_non_specific_general_types.h"
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "drv_comm.h"
//#include "reg_base.h"

//#include "drvpdn.h"
//#include "intrCtrl.h"
//#include "gpio_sw.h"

#include "usb_comm.h"
#include "usbdl_usb_drv.h"
#include "usbdl_usb.h"
#include "usbdl_usb_resource.h"
#include "usbdl_usbacm_drv.h"
//#include "usb_custom.h"
#include "usbdl_debug_tool.h"
#endif

/* Device structure, handle usb level data */
Usb_Device gUsbDevice;
extern void USB_Initialize_Drv(void);
extern void USB_Set_DP_Pull_High(kal_bool bset);

#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
extern void USB_Reset_FIFO(void);
#endif

/* static fuctions */
static void USB_Reset(void);
static void USB_Initialize(void);
static kal_bool USB_Cmd_SetAddress(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static kal_bool USB_Cmd_GetDescriptor(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static kal_bool USB_Cmd_SetConfiguration(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static kal_bool USB_Cmd_GetConfiguration(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static kal_bool USB_Cmd_SetFeature(Usb_Command *pcmd, kal_bool bset);
static kal_bool USB_Cmd_GetStatus(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static void USB_Stdcmd(Usb_Ep0_Status *pep0state, Usb_Command *pcmd);
static void USB_Endpoint0_Idle (void);
static void USB_Endpoint0_Rx(void);
static void USB_Endpoint0_Tx(void);
static void USB_Endpoint0_Hdlr(void);


/************************************************************
	gUsbDevice initialize and release functions
*************************************************************/

/* initialize the  global variable gUsbDevice */
void USB_Init_Device_Status(void)
{
	kal_uint8 index = 0;

	kal_mem_set(&gUsbDevice.cfg_info, 0, sizeof(Usb_Config_Info));
 
	for( index = 0; index < USB_MAX_INTERFACE; index++)
	{
		kal_mem_set(&gUsbDevice.if_info[index], 0, sizeof(Usb_Interface_Info));
	}

	for( index = 0; index < USB_MAX_EP_BULK_IN; index++)
	{
		kal_mem_set(&gUsbDevice.ep_bulkin_info[index], 0, sizeof(Usb_Ep_Info));
	}

	for( index = 0; index < USB_MAX_EP_BULK_OUT; index++)
	{
		kal_mem_set(&gUsbDevice.ep_bulkout_info[index], 0, sizeof(Usb_Ep_Info));
	}

	for( index = 0; index < USB_MAX_EP_INTR; index++)
	{
		kal_mem_set(&gUsbDevice.ep_intr_info[index], 0, sizeof(Usb_Ep_Info));
	}

	for( index = 0; index < USB_MAX_STRING; index++)
	{
		gUsbDevice.resource_string[index] = NULL;
	}

	gUsbDevice.conf = NULL;
	gUsbDevice.device_type = USB_UNKOWN;
	gUsbDevice.nDevState = DEVSTATE_DEFAULT;
	gUsbDevice.remoteWk = KAL_FALSE;
	gUsbDevice.self_powered = KAL_FALSE;
	gUsbDevice.config_num = 0;
	gUsbDevice.interface_num = 0;
	gUsbDevice.ep0_rx_handler = NULL;
//	gUsbDevice.ep0_class_cmd_handler.b_enable = KAL_FALSE;

   	gUsbDevice.resource_ep_bulkin_number = 0;		
   	gUsbDevice.resource_ep_bulkout_number = 0;		
   	gUsbDevice.resource_ep_intr_number = 0;
   	gUsbDevice.resource_interface_number = 0;
   	gUsbDevice.resource_string_number = 0; 
}



/* release the already get memory, and reset some parameter,
    note that hisr should not be reset to NULL since it may already be created*/
/*
void USB_Release_Device_Status(void)
{
	kal_uint8 index = 0;

	kal_mem_set(&gUsbDevice.cfg_info, 0, sizeof(Usb_Config_Info));
	
	for( index = 0; index < USB_MAX_INTERFACE; index++)
	{
		kal_mem_set(&gUsbDevice.if_info[index], 0, sizeof(Usb_Interface_Info));
	}

	for( index = 0; index < USB_MAX_EP_BULK_IN; index++)
	{
		kal_mem_set(&gUsbDevice.ep_bulkin_info[index], 0, sizeof(Usb_Ep_Info));
	}

	for( index = 0; index < USB_MAX_EP_BULK_OUT; index++)
	{
		kal_mem_set(&gUsbDevice.ep_bulkout_info[index], 0, sizeof(Usb_Ep_Info));
	}

	for( index = 0; index < USB_MAX_EP_INTR; index++)
	{
		kal_mem_set(&gUsbDevice.ep_intr_info[index], 0, sizeof(Usb_Ep_Info));
	}

	for( index = 0; index < USB_MAX_STRING; index++)
	{
		gUsbDevice.resource_string[index] = NULL;
	}

	gUsbDevice.conf = NULL;
	
	gUsbDevice.nDevState = DEVSTATE_DEFAULT;
	gUsbDevice.remoteWk = KAL_FALSE;
	gUsbDevice.self_powered = KAL_FALSE;
	gUsbDevice.config_num = 0;
	gUsbDevice.interface_num = 0;
	gUsbDevice.device_type = USB_UNKOWN;
	gUsbDevice.ep0_rx_handler = NULL;
//	gUsbDevice.ep0_class_cmd_handler.b_enable = KAL_FALSE;

	gUsbDevice.resource_ep_bulkin_number = 0;		
	gUsbDevice.resource_ep_bulkout_number = 0;		
	gUsbDevice.resource_ep_intr_number = 0;
	gUsbDevice.resource_interface_number = 0;
	gUsbDevice.resource_string_number = 0; 
}
*/


/************************************************************
	EP0 functions
*************************************************************/

/* register EP0 rx OUT token data handler */
void USB_Register_EP0_RxHdlr(usb_ep0_rx_ptr handler)
{
	gUsbDevice.ep0_rx_handler = handler;
}

/*
void USB_Register_EP0_Class_CmdHdlr(kal_uint8 cmd, usb_ep0_cmd_ptr handler)
{
	gUsbDevice.ep0_class_cmd_handler.cmd = cmd;
	gUsbDevice.ep0_class_cmd_handler.ep0_cmd_hdlr = handler;
	gUsbDevice.ep0_class_cmd_handler.b_enable = KAL_TRUE;
}
*/

/* prepare TX data infomration for pep0state, data is actually sent out in TX state handler */
void USB_Generate_EP0Data(Usb_Ep0_Status*pep0state, Usb_Command*pcmd, void *data, kal_int32 len)
{
	pep0state->nBytesLeft = len;
	pep0state->pData = (void*)data;
	/* only transmit at most command request */
	if (pcmd->wLength < pep0state->nBytesLeft)
		pep0state->nBytesLeft = pcmd->wLength;
	/* EP0 go to TX state */
	gUsbDevice.ep0_state = USB_EP0_TX;
}

/************************************************************
	system ctrl functions
*************************************************************/

/* init function, called when user select usb type, 
    entry function for task , B_eanble is D+ detection enable */
void USB_Init(USB_DEVICE_TYPE type, kal_bool b_enable, kal_bool is_ft_mode)
{
#if defined(DRV_USB_MCU_52M)
	#ifndef MCU_52M
		EXT_ASSERT(0, 0, 0, 0);  /* Must 52M */
	#endif   /* MCU_52M */
#endif 	/* MT6218||MT6218B||MT6219 */

	USB_Init_Drv_Info(KAL_FALSE);			/*initialize driver parameters*/
	USB_Init_Device_Status();	/*initialize global variable gUsbDevice*/

	USB_Init_Acm_Status();
	gUsbDevice.device_type = USB_CDC_ACM;

	/* register reset and ep0 interrupt handler to driver info*/
	USB_Register_Drv_Info(USB_DRV_HDLR_RESET, 0, USB_Reset);
	USB_Register_Drv_Info(USB_DRV_HDLR_EP0, 0, USB_Endpoint0_Hdlr);

	/* create descriptors */
	USB_Software_Create();

	if (is_ft_mode == KAL_TRUE)
	{
		/* reset and initialize system initial value and registers*/
		USB_Reset_Drv();  /* reset hw power register */
		USB_Initialize_Drv();

		/* initailize according to application*/
		USB_Initialize();
	
		USB_Set_DP_Pull_High(KAL_TRUE);
	}
	else
		USB_Software_Init();  
	
}

/*
void USB_Release(void)
{
	USB_Release_Drv();
}
*/

/* reset device, called when receive reset interrupt*/
static void USB_Reset(void)
{
	kal_uint8 ep_num;

//	gUsbDevice.is_configured_now = KAL_FALSE;

	// initialize driver info and system interrupt
	USB_ResetDrv_Info();
	USB_Initialize_Drv();
	USB_Initialize();        /* call class reset function */

	for(ep_num=0;ep_num<gUsbDevice.resource_ep_bulkin_number;ep_num++)
	{
		if(gUsbDevice.ep_bulkin_info[ep_num].ep_reset)
			gUsbDevice.ep_bulkin_info[ep_num].ep_reset();
	}

	for(ep_num=0;ep_num<gUsbDevice.resource_ep_bulkout_number;ep_num++)
	{
		if(gUsbDevice.ep_bulkout_info[ep_num].ep_reset)
			gUsbDevice.ep_bulkout_info[ep_num].ep_reset();
	}

	for(ep_num=0;ep_num<gUsbDevice.resource_ep_intr_number;ep_num++)
	{
		if(gUsbDevice.ep_intr_info[ep_num].ep_reset)
			gUsbDevice.ep_intr_info[ep_num].ep_reset();
	}
}

/* initialize system */
static void USB_Initialize(void)
{
	kal_uint8 index_ep;
	kal_uint16 wMaxPacketSize;

#ifdef __USB_HS_ENABLE__	
	/* initial class specific speed-related endpoint, and re-prepare descriptor */
	USB_Software_Speed_Init(KAL_FALSE);
#endif


#if defined(DRV_USB_IP_V3)||defined(DRV_USB_IP_V4)
	USB_Reset_FIFO();
#endif

	gUsbDevice.nDevState = DEVSTATE_DEFAULT;

	for( index_ep = 0; index_ep < gUsbDevice.resource_ep_bulkin_number; index_ep++)
	{
		wMaxPacketSize = (kal_uint8)gUsbDevice.ep_bulkin_info[index_ep].epdesc.stdep.wMaxPacketSize[1];
		wMaxPacketSize <<= 8;
		wMaxPacketSize |= (kal_uint8)gUsbDevice.ep_bulkin_info[index_ep].epdesc.stdep.wMaxPacketSize[0];
		
		USB_TxEPInit((gUsbDevice.ep_bulkin_info[index_ep].epdesc.stdep.bEndpointAddress&(~USB_EP_DIR)), 
						wMaxPacketSize, USB_ENDPT_BULK);
		gUsbDevice.ep_bulkin_info[index_ep].ep_status.epin_status.nBytesLeft = USB_EP_NODATA;
	}

	for( index_ep = 0; index_ep < gUsbDevice.resource_ep_bulkout_number; index_ep++)
	{
		wMaxPacketSize = (kal_uint8)gUsbDevice.ep_bulkout_info[index_ep].epdesc.stdep.wMaxPacketSize[1];
		wMaxPacketSize <<= 8;
		wMaxPacketSize |= (kal_uint8)gUsbDevice.ep_bulkout_info[index_ep].epdesc.stdep.wMaxPacketSize[0];
			
		USB_RxEPInit((gUsbDevice.ep_bulkout_info[index_ep].epdesc.stdep.bEndpointAddress&(~USB_EP_DIR)), 
						wMaxPacketSize, USB_ENDPT_BULK);
		gUsbDevice.ep_bulkout_info[index_ep].ep_status.epout_status.nBuffLen = 0;
		gUsbDevice.ep_bulkout_info[index_ep].ep_status.epout_status.nBytesRecv = 0;
	}

	for( index_ep = 0; index_ep < gUsbDevice.resource_ep_intr_number; index_ep++)
	{
		wMaxPacketSize = 	(kal_uint8)gUsbDevice.ep_intr_info[index_ep].epdesc.stdep.wMaxPacketSize[1];
		wMaxPacketSize <<= 8;
		wMaxPacketSize |= (kal_uint8)gUsbDevice.ep_intr_info[index_ep].epdesc.stdep.wMaxPacketSize[0];
			
		USB_TxEPInit((gUsbDevice.ep_intr_info[index_ep].epdesc.stdep.bEndpointAddress&(~USB_EP_DIR)), 
						wMaxPacketSize, USB_ENDPT_INTR);
		gUsbDevice.ep_intr_info[index_ep].ep_status.epin_status.nBytesLeft = USB_EP_NODATA;
	}


	/* Clear current configuration pointer */
	//gUsbDevice.pCurCfg = &gUsbDevice.cfg_info[0].stdcfg;  /* pointer point to configuration descriptor */
	gUsbDevice.self_powered = KAL_FALSE;
	gUsbDevice.remoteWk = KAL_FALSE;
	gUsbDevice.config_num = 0;        /*  set configuration command value  */
	gUsbDevice.interface_num = 0;    /*  set inferface command value  */
	gUsbDevice.ep0_state = USB_EP0_IDLE;
	gUsbDevice.ep0info.byFAddr = 0xff;   /*  device (function) address, no use, at HW still set 0x00 */

	/* initial class specific interface functions*/
	USB_Software_Init();
}

/************************************************************
	EP0 functions
*************************************************************/

/* parse command Set Address */
static kal_bool USB_Cmd_SetAddress(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;

	/* Store device function address until status stage of request */
	if (pcmd->bmRequestType != USB_CMD_STDDEVOUT)
	{
		bError = KAL_TRUE;
	}
	else
	{
		if (gUsbDevice.nDevState <= DEVSTATE_ADDRESS)
		{
			pep0state->byFAddr = (kal_uint8)pcmd->wValue;
			if ((gUsbDevice.nDevState == DEVSTATE_DEFAULT) && (pep0state->byFAddr<=127))
			{
				gUsbDevice.nDevState = DEVSTATE_SET_ADDRESS;
				USB_SetAddress(pep0state->byFAddr, USB_SET_ADDR_DATA);
			}
			else
			{
				gUsbDevice.nDevState = DEVSTATE_DEFAULT;
			}
		}
		else
		{
			bError = KAL_TRUE;
		}	
	}

	return bError;
}

/* parse command Get Descriptor */
static kal_bool USB_Cmd_GetDescriptor(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;
	kal_uint8 byConfig;
	kal_uint8 bystr;
	Usb_Cfg_Dscr *pcfg;


	/* Decode the required descriptor from the command */
	if (pcmd->bmRequestType != USB_CMD_STDDEVIN)
	{
		bError = KAL_TRUE;
	}
	else 
	{
		switch (pcmd->wValue & USB_CMD_DESCMASK) 
		{
		case USB_CMD_DEVICE:
			/* Prepare to return Standard Device Descriptor */
			USB_Generate_EP0Data(pep0state, pcmd, &gUsbDevice.devdscr, sizeof(Usb_Dev_Dscr));
			break;
		case USB_CMD_CONFIG:

	#ifdef __USB_HS_ENABLE__	
			USB_Software_Speed_Init(KAL_FALSE);
	#endif
			byConfig = (kal_uint8)(pcmd->wValue & 0x00FF);
			if (byConfig >= gUsbDevice.devdscr.bNumConfigurations)
			{
				bError = KAL_TRUE;
			}
			else 
			{
				/* Get pointer to request configuration descriptor */
				pcfg = (Usb_Cfg_Dscr*)gUsbDevice.conf;
				
				/* Prepare to return Configuration Descriptors */
				USB_Generate_EP0Data(pep0state, pcmd, pcfg, pcfg->wTotalLength);
			}
			break;    
		case USB_CMD_STRING:
			bystr = (kal_uint8)(pcmd->wValue & 0x00FF);
			if (bystr >= gUsbDevice.resource_string_number)
			{
				bError = KAL_TRUE;
			}
			else
			{
				/* Get pointer to requested string descriptor */
				USB_Generate_EP0Data(pep0state, pcmd, (void *)gUsbDevice.resource_string[bystr], 
							(*(kal_uint8 *)gUsbDevice.resource_string[bystr]));
			}
			break;
		default: 
			bError = KAL_TRUE;
			break;
		}
	}

	return bError;
}


/* Parse command Set Configuration */
static kal_bool USB_Cmd_SetConfiguration(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;
	kal_uint8 byConfig;
	
	byConfig = (kal_uint8)(pcmd->wValue & 0x00FF);

	if (gUsbDevice.nDevState == DEVSTATE_DEFAULT)
	{
		bError = KAL_TRUE;
	}	
	/* Assumes configurations are numbered from 1 to NumConfigurations */
	else 
	{
		if (byConfig > gUsbDevice.devdscr.bNumConfigurations)
		{
			bError = KAL_TRUE;
		}
		else if (byConfig == 0)
		{
			gUsbDevice.nDevState = DEVSTATE_ADDRESS;
			gUsbDevice.config_num = 0;
		}
		else 
		{
			gUsbDevice.nDevState = DEVSTATE_CONFIG;		
//			gUsbDevice.is_configured_now = KAL_TRUE;
			gUsbDevice.config_num = byConfig;	
		}
	}
	return bError;
}


/* parse command Get Configuration */
static kal_bool USB_Cmd_GetConfiguration(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;
	

	if( (gUsbDevice.nDevState == DEVSTATE_ADDRESS) && (!pcmd->wValue))
	{
		/* Prepare to return zero */
		USB_Generate_EP0Data(pep0state, pcmd, &pcmd->wValue, 1);
	}
	else if( gUsbDevice.nDevState == DEVSTATE_CONFIG) 
	{
		/* Prepare to return configuration value */
		//pcfg = (Usb_Cfg_Dscr *)gUsbDevice.pCurCfg;
		//USB_Generate_EP0Data(pep0state, pcmd, &pcfg->bConfigurationValue, 1);
		USB_Generate_EP0Data(pep0state, pcmd, &gUsbDevice.config_num, 1);
	}
	else
	{
		bError = KAL_TRUE;
	}
	return bError;
}

/* parse command Set Interface */
static kal_bool USB_Cmd_SetInterface(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;


	gUsbDevice.interface_num = (pcmd->wValue&0x00FF);
	return bError;
}

/* parse command Get Interface */
static kal_bool USB_Cmd_GetInterface(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;


	USB_Generate_EP0Data(pep0state, pcmd, &gUsbDevice.interface_num, 1);
	return bError;
}


/* parse command Set/Clear Feature */
/* bset  true means command SET_FETURE, false means command CLEAR_FEATURE */
static kal_bool USB_Cmd_SetFeature(Usb_Command *pcmd, kal_bool bset)
{
	kal_bool bError = KAL_FALSE;
	
	switch (pcmd->bmRequestType) 
	{
	/* device */
	case USB_CMD_STDDEVOUT:
		switch (pcmd->wValue) 
		{
		case USB_FTR_DEVREMWAKE:
			gUsbDevice.remoteWk = bset;
			break;
		default:
			bError = KAL_TRUE;
			break;
		}
		break;
	/* endpoint */	
	case USB_CMD_STDEPOUT:
		switch (pcmd->wValue) 
		{
		case USB_FTR_EPHALT:
			if (pcmd->wIndex == 0)
			{
				/* endpoint 0 */
			}
			else
			{
				/* command EP direction zero indicate OUT EP */
				if(pcmd->wIndex & 0x80)
				{
					/* TX EP */
					if(((pcmd->wIndex&0x0f) > MAX_TX_EP_NUM)||((pcmd->wIndex&0x0f) == 0x00))
					{
						bError = KAL_TRUE;
					}
					else
					{
						USB_CtrlEPStall((pcmd->wIndex& 0x0f), USB_EP_TX_DIR, bset, USB_CTRL_STALL_ENTRY_1);
					}
				}
				else
				{
					/* RX EP */
					if(((pcmd->wIndex&0x0f) > MAX_RX_EP_NUM)||((pcmd->wIndex&0x0f) == 0x00))
					{
						bError = KAL_TRUE;
					}
					else
					{
						USB_CtrlEPStall((pcmd->wIndex& 0x0f), USB_EP_RX_DIR, bset, USB_CTRL_STALL_ENTRY_1);
					}
					
				}
			}
			break;
		default:
			bError = KAL_TRUE;
			break;
		}
		break;
	case USB_CMD_STDIFOUT:
	default:
		bError = KAL_TRUE;
		break;
	}

	return bError;
}

/* parse command Get Status */
static kal_bool USB_Cmd_GetStatus(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool bError = KAL_FALSE;
	static kal_uint16 status = 0;
	switch (pcmd->bmRequestType) 
	{
	case USB_CMD_STDDEVIN:
		status = (kal_uint16)((gUsbDevice.remoteWk<<1)|(gUsbDevice.self_powered));
		USB_Generate_EP0Data( pep0state, pcmd, &status, 2);
		break;
	case USB_CMD_STDIFIN:
		USB_Generate_EP0Data( pep0state, pcmd, &status, 2);
		break; 
	case USB_CMD_STDEPIN:
		if(pcmd->wIndex & 0x80)
		{
			/* In EP*/
			status = (kal_uint16)USB_Get_EP_Stall_Status((pcmd->wIndex & 0x000f), USB_EP_TX_DIR);
		}
		else
		{
			/* Out EP*/
			status = (kal_uint16)USB_Get_EP_Stall_Status((pcmd->wIndex & 0x000f), USB_EP_RX_DIR);
		}
		USB_Generate_EP0Data( pep0state, pcmd, &status, 2);
		break;
	default:
		bError = KAL_TRUE;
		break;
	}

	return bError;
}


static void USB_Stdcmd(Usb_Ep0_Status *pep0state, Usb_Command *pcmd)
{
	kal_bool   bError = KAL_FALSE;


	switch (pcmd->bRequest) 
	{
	case USB_SET_ADDRESS:
		USB_Dbg_Trace(USB_EP0_SET_ADDRESS, drv_get_current_time(), (kal_uint32)pcmd->wValue, (kal_uint32)pcmd->wIndex);
		bError = USB_Cmd_SetAddress(pep0state, pcmd);
		break;
	case USB_GET_DESCRIPTOR:
		USB_Dbg_Trace(USB_EP0_GET_DESCRIPTOR, drv_get_current_time(), (kal_uint32)pcmd->wValue, (kal_uint32)pcmd->wIndex);
		bError = USB_Cmd_GetDescriptor(pep0state, pcmd);
		break;
	case USB_SET_CONFIGURATION:
		USB_Dbg_Trace(USB_EP0_SET_CONFIGURATION, drv_get_current_time(), (kal_uint32)pcmd->wValue, (kal_uint32)pcmd->wIndex);
		bError = USB_Cmd_SetConfiguration(pep0state, pcmd);
		break;
	case USB_SET_INTERFACE:
		USB_Dbg_Trace(USB_EP0_SET_INTERFACE, drv_get_current_time(), (kal_uint32)pcmd->wValue, (kal_uint32)pcmd->wIndex);
		bError = USB_Cmd_SetInterface(pep0state, pcmd);
		break;
	case USB_GET_CONFIGURATION:
		USB_Dbg_Trace(USB_EP0_GET_CONFIGURATION, drv_get_current_time(), (kal_uint32)pcmd->wValue, (kal_uint32)pcmd->wIndex);
		bError = USB_Cmd_GetConfiguration(pep0state, pcmd);
		break;
	case USB_GET_INTERFACE:
		USB_Dbg_Trace(USB_EP0_GET_INTERFACE, drv_get_current_time(), (kal_uint32)pcmd->wValue, (kal_uint32)pcmd->wIndex);
		bError = USB_Cmd_GetInterface(pep0state, pcmd);
		break;
	case USB_SET_FEATURE:
		USB_Dbg_Trace(USB_EP0_SET_FEATURE, drv_get_current_time(), (kal_uint32)pcmd->wValue, (kal_uint32)pcmd->wIndex);
		bError = USB_Cmd_SetFeature(pcmd, KAL_TRUE);
		break;
	case USB_CLEAR_FEATURE:
		USB_Dbg_Trace(USB_EP0_CLEAR_FEATURE, drv_get_current_time(), (kal_uint32)pcmd->wValue, (kal_uint32)pcmd->wIndex);
		bError = USB_Cmd_SetFeature(pcmd, KAL_FALSE);
		break;
	case USB_GET_STATUS:
		USB_Dbg_Trace(USB_EP0_GET_STATUS, drv_get_current_time(), (kal_uint32)pcmd->wValue, (kal_uint32)pcmd->wIndex);
		bError = USB_Cmd_GetStatus(pep0state, pcmd);
		break;
	/* Stall the command if an unrecognized request is received */	
	case USB_SYNCH_FRAME:   /*Only support for Isoc traffic*/
	case USB_SET_DESCRIPTOR:
	default:
		USB_Dbg_Trace(USB_EP0_CMD_ERROR, drv_get_current_time(), (kal_uint32)pcmd->wValue, (kal_uint32)pcmd->wIndex);
		bError = KAL_TRUE;
//		ASSERT(0);
		break;
	}


	if (gUsbDevice.ep0_state == USB_EP0_IDLE)	/* no data to transmit */
	{
		gUsbDevice.ep0_state = USB_EP0_RX_STATUS;
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_TRUE);
/*
		if((gUsbDevice.ep0_class_cmd_handler.b_enable == KAL_TRUE) &&
			(gUsbDevice.ep0_class_cmd_handler.cmd == pcmd->bRequest) ) 
		{
			gUsbDevice.ep0_class_cmd_handler.ep0_cmd_hdlr(pcmd);
		}	
*/
	}
	else
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, bError, KAL_FALSE);
	}
}


/* parse EP0 requested command */
static void USB_Endpoint0_Idle (void)
{
	/* read ep0 data*/
	USB_EPFIFORead(0, 8, &gUsbDevice.cmd);
	
	/* Check request type */
	switch (gUsbDevice.cmd.bmRequestType & USB_CMD_TYPEMASK) 
	{
	case USB_CMD_STDREQ:
		/* standard request */
		USB_Stdcmd(&gUsbDevice.ep0info, &gUsbDevice.cmd);
		break;
	case USB_CMD_CLASSREQ:
		/* class specific request */
		if((gUsbDevice.cmd.bmRequestType == USB_CMD_CLASSIFIN) || (gUsbDevice.cmd.bmRequestType == USB_CMD_CLASSIFOUT))
		{
			if(gUsbDevice.if_info[(gUsbDevice.cmd.wIndex & 0xff)].if_class_specific_hdlr != NULL)
			{
				gUsbDevice.if_info[(gUsbDevice.cmd.wIndex & 0xff)].if_class_specific_hdlr(&gUsbDevice.ep0info, &gUsbDevice.cmd);
			}
			else
			{
				/* error occur, stall endpoint*/
				USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_TRUE, KAL_FALSE);
			}
		}
		else
		{
			/* error occur, stall endpoint*/
			USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_TRUE, KAL_FALSE);
		}
		break;
	case USB_CMD_VENDREQ:
	default:
		/* Stall the command if a reserved request is received */
		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_TRUE, KAL_FALSE);
		break;
	}
}


/* EP0 RX handler, called when EP0 interrupt happened and in RX state */
static void USB_Endpoint0_Rx(void)
{
	if (gUsbDevice.ep0_rx_handler != NULL)
	{
		/* called rx handler to get data*/
		gUsbDevice.ep0_rx_handler(&gUsbDevice.ep0info);
	}
	else
	{
		/* this should not happened, user should register rx handler when set EP0 into RX state */
		/* error occur, stall endpoint*/
		ASSERT(0);
//		USB_Update_EP0_State(USB_EP0_DRV_STATE_READ_END, KAL_TRUE, KAL_FALSE);
	}
}


/* EP0 TX handler, called when EP0 interrupt happened and in TX state, 
     or EP0 just translate from IDLE to TX state */
static void USB_Endpoint0_Tx(void)
{
	kal_int32 nBytes;

	/* Determine number of bytes to send */
	if (gUsbDevice.ep0info.nBytesLeft <= USB_EP0_MAXP) 
	{
		nBytes = gUsbDevice.ep0info.nBytesLeft;
		gUsbDevice.ep0info.nBytesLeft = 0;
	}
	else 
	{
		nBytes = USB_EP0_MAXP;
		gUsbDevice.ep0info.nBytesLeft -= USB_EP0_MAXP;
	}

	/* send out data */
	USB_EPFIFOWrite (0, nBytes, gUsbDevice.ep0info.pData);

	/* update data pointer and  prepare for next transaction */
	gUsbDevice.ep0info.pData = (kal_uint8 *)gUsbDevice.ep0info.pData + nBytes;
	
	if (nBytes < USB_EP0_MAXP) 
	{
		gUsbDevice.ep0_state = USB_EP0_IDLE;
		/* last data, set end as true*/
		USB_Update_EP0_State(USB_EP0_DRV_STATE_WRITE_RDY, KAL_FALSE, KAL_TRUE);
	}
	else
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_WRITE_RDY, KAL_FALSE, KAL_FALSE);
	}
}


/* EP0 interrupt handler called by USB_HISR */
static void USB_Endpoint0_Hdlr(void)
{
	kal_bool b_transaction_end;
	kal_bool b_sent_stall;
	kal_uint32 nCount;

	USB_Get_EP0_Status(&b_transaction_end, &b_sent_stall);

	/* Check for SentStall */
	/* SentStall && SetupEnd are impossible to occur together*/
	if (b_sent_stall == KAL_TRUE) 
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_CLEAR_SENT_STALL, KAL_FALSE, KAL_FALSE);
		gUsbDevice.ep0_state = USB_EP0_IDLE;
	}

	/* Check for SetupEnd */
	if (b_transaction_end == KAL_TRUE) 
	{
		USB_Update_EP0_State(USB_EP0_DRV_STATE_TRANSACTION_END, KAL_FALSE, KAL_FALSE);
		gUsbDevice.ep0_state = USB_EP0_IDLE;
	}

	/* Call relevant routines for endpoint 0 state */
	if (gUsbDevice.ep0_state == USB_EP0_IDLE)
	{
		/* receive command request */
		nCount = USB_EP0_Pkt_Len();
		if (nCount > 0) 
		{
			/* idle state handler */
			USB_Endpoint0_Idle();
		}
	}
	else if (gUsbDevice.ep0_state == USB_EP0_RX)
	{
		/* Rx state handler */
		USB_Endpoint0_Rx();
	}
	else if (gUsbDevice.ep0_state == USB_EP0_RX_STATUS)
	{
		/* Data stage is RX, status stage is TX*/
		if(gUsbDevice.nDevState == DEVSTATE_SET_ADDRESS)
		{
			USB_SetAddress(gUsbDevice.ep0info.byFAddr, USB_SET_ADDR_STATUS);
			gUsbDevice.nDevState = DEVSTATE_ADDRESS;
		}
		gUsbDevice.ep0_state = USB_EP0_IDLE;
		
		/* In case next setup followed the previous status very fast and interrupt only happens once*/
		/* receive command request */
		nCount = USB_EP0_Pkt_Len();
		if (nCount > 0) 
		{
			/* idle state handler */
			USB_Endpoint0_Idle();
		}
	}

	/* must use if, not else if, EP0 may enter TX state in previous IDLE state handler */
	if (gUsbDevice.ep0_state == USB_EP0_TX)
	{
		/* Tx state handler */
		USB_Endpoint0_Tx();
	}
}

#endif   /* __USB_DOWNLOAD__ */

