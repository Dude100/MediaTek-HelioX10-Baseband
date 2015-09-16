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
 *    icusb_iccd_drv.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file intends for host mass storage class driver definitions
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
 *
 * removed!
 * removed!
 * removed!
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
 
#ifndef USB_HOST_ICCD_DRV_H
#define USB_HOST_ICCD_DRV_H

#include "usb_host_default_drv.h"

/***********************************************
	iccd class descriptor  definition
************************************************/
#define USB_ICCD_DEVICE_CODE						0x00
#define USB_ICCD_SUBCLASS_CODE					0x00
#define USB_ICCD_PROTOCOL_CODE					0x00
#define USB_ICCD_INTERFACE_CLASS_CODE 			0x0B
#define USB_ICCD_INTERFACE_SUBCLASS_CODE 		0x00
#define USB_ICCD_INTERFACE_PROTOCOL_CODE 		0x02


/************************************************************
	ICCD class parameter definition
*************************************************************/
#define USB_ICCD_POWER_ON			0x62
#define USB_ICCD_POWER_OFF		0x63
#define USB_ICCD_XFR_BLOCK		0x65
#define USB_ICCD_DATA_BLOCK		0x6F
#define USB_ICCD_SLOT_STATUS	0x81


//Data Block Parameter
#define USB_DATA_bResponse_APDU_DONE 		0x00
#define USB_DATA_bResponse_APDU_START_PACKET 	0x01
#define USB_DATA_bResponse_APDU_MIDDLE_PACKET 	0x02
#define USB_DATA_bResponse_APDU_LAST_PACKET 	0x03
#define USB_DATA_bResponse_NEXT_XFR 		0x10
#define USB_DATA_bResponse_Status_Info 	0x40
#define USB_DATA_bResponse_Polling 			0x80

//Status parameter
#define USB_bmIccStatus						0x03
#define USB_bmIccStatus_Active 				0
#define USB_bmIccStatus_Not_Active 		1
#define USB_bmIccStatus_Not_Present 	2

#define USB_bmCommandStatus						0xC0
#define USB_bmCommandStatus_Ready			0x00
#define USB_bmCommandStatus_Error			0x40

//Error Code
#define USB_ICC_MUTE						0xFE
#define USB_XFR_OVERRUN					0xFC
#define USB_HW_ERROR						0xFB


// Event flag. mith be handled in HISR level. This event is used when state complete to retrive waiting task
#define EVENT_USB_ICCD_DONE							((kal_uint32)0x00000001)
#define EVENT_USB_ICCD_DETATCH						((kal_uint32)0x00000002)
#define EVENT_ICUSB_ENUMERATION_DONE				((kal_uint32)0x00000004)  //notice SIM Drive
#define EVENT_ICUSB_ENUMERATION_FAIL					((kal_uint32)0x00000008)  //notice SIM Drive 

#define ICCD_ATR_REQ_LENGTH  50	

//  USB Host ICCD Support Number =  ICUSB  number
#define USB_MAX_ICCD_NUM  1



// ICCD state
typedef enum
{
	USB_HOST_ICCD_IDLE,
	USB_HOST_ICCD_SEND_COMMAND,
	USB_HOST_ICCD_REQUEST_COMMAND,
	USB_HOST_ICCD_SEND_CLEAR_STALL,
	USB_HOST_ICCD_REQUEST_CLEAR_STALL
}USB_HOST_ICCD_STATE;



// Result of the RESPONSE,REQUEST state (EP0 Setup, Data, Status stage complete)
typedef enum
{
	USB_HOST_ICCD_RESULT_OK,
	USB_HOST_ICCD_RESULT_TIMEOUT,
	USB_HOST_ICCD_RESULT_NO_RESPONSE,
	USB_HOST_ICCD_RESULT_NOT_CONFIG,
	USB_HOST_ICCD_RESULT_STALL
}USB_HOST_ICCD_RESULT;

// USB-ICC Status (use Data Command / Slot_Status command)
typedef enum
{
	USB_ICCD_DEVICE_Active,
	USB_ICCD_DEVICE_Cannot_Response,
	USB_ICCD_DEVICE_HW_ERROR,
	USB_ICCD_DEVICE_Not_Active,
	USB_ICCD_DEVICE_NOT_CONFIG,	
	USB_ICCD_DEVICE_Fail  //Ep0 contorl pipe transfer fail
}USB_HOST_ICCD_DEV_STATE;


/* The ICCD APDU Response type*/
typedef enum
{
	USB_HOST_ICCD_APDU_RESPONSE, 	
	USB_HOST_ICCD_APDU_DONE,
	USB_HOST_ICCD_APDU_POLLING, 		
	USB_HOST_ICCD_CMD_FAIL,  // need to get Smart SIM Status
	USB_HOST_ICCD_NOT_CONFIG,	
	USB_HOST_ICCD_ERROR  //Ep0 contorl pipe transfer fail
}USB_HOST_ICCD_CMD_STATE;

/* Ctrl EP commands that may used after ICCD class driver is started 
    Note that it contains both standard and class specific request */
typedef enum
{
	USB_HOST_ICCD_EP0_CMD_NONE,
	USB_HOST_ICCD_EP0_CMD_POWER_ON,
	USB_HOST_ICCD_EP0_CMD_POWER_OFF,
	USB_HOST_ICCD_EP0_CMD_XFR_BLOCK,
	USB_HOST_ICCD_EP0_CMD_DATA_BLOCK,
	USB_HOST_ICCD_EP0_CMD_SLOT_STATUS,
	USB_HOST_ICCD_EP0_CMD_CLEAR_STALL
}USB_HOST_ICCD_EP0_CMD;

/************************************************************
	Implementation structures
*************************************************************/
typedef struct
{
	kal_uint8	bStatus;
	kal_uint8 bError;
	kal_uint8 bReserved;
}USB_Host_ICCD_Status_Struct;

typedef struct
{
	/* device level resource */	
	USBH_Common_Struct		common_info;
	
	kal_eventgrpid			event_id;			/* event used for (CBW, DATA, CSW) state machine to retrive waiting task */
	kal_eventgrpid			start_event_id;
	kal_mutexid				mutex_id;			/* mutex used to protect ms command. When USB task is polling state machine, read/write action from application task should be protected */
   														
  	kal_uint32					sleep_timer_handle;			/* use timer to check whether App need to use Device or not */
  	
	kal_uint8					dev_error_count;
	kal_bool					config;	//Descriptor match
	kal_bool					dev_attatch; //Vbus3.3 provide & Device class match
	
	USB_HOST_ICCD_DEV_STATE		dev_state;			//USB-ICC state: ready,active,error
	USB_HOST_ICCD_RESULT			ep0_result;				//Setup + Data + Stage Complete 
	USB_HOST_ICCD_CMD_STATE		apdu_response;			//using DATA_BLOCK query
	USB_HOST_ICCD_EP0_CMD			ep0_cmd;  // ICCD Class specific Command

	kal_uint8					atr_data[ICCD_ATR_REQ_LENGTH];				/* ATR Response*/
	kal_uint16				atr_length;
	kal_uint16 				sleep_time;
	kal_uint16				rx_real_length;
	kal_uint16*				rx_buffer;

}USB_Host_ICCD_Struct;


/************************************************************
	extern variables and functions
*************************************************************/

extern USBD_ClassDriver_Struct USB_Host_Iccd_Drv;
extern USB_Host_ICCD_Struct g_UsbHostIccd[USB_MAX_ICCD_NUM];

extern void USB_Host_ICCD_Reset_Card(kal_uint8 iccd_index);
extern void USB_Host_ICCD_Enumeration_Fail(kal_uint8 usb_ip_port);
	
extern USB_HOST_ICCD_RESULT USB_Host_ICCD_POWER_ON(kal_uint8 iccd_index);
extern USB_HOST_ICCD_RESULT USB_Host_ICCD_POWER_OFF(kal_uint8 iccd_index);
extern USB_HOST_ICCD_RESULT USB_Host_ICCD_XFR_BLOCK(kal_uint8 iccd_index,kal_uint16 buflen, kal_uint8 *buffer);
extern USB_HOST_ICCD_CMD_STATE USB_Host_ICCD_DATA_BLOCK(kal_uint8 iccd_index,kal_uint16 *rx_size, kal_uint8 *buffer);
extern USB_HOST_ICCD_DEV_STATE USB_Host_ICCD_SLOT_STATUS(kal_uint8 iccd_index);

extern void USB_Host_ICCD_Sleep_Timeout(void *parameter);



#endif	/* USB_HOST_MS_DRV_H */ 
 
