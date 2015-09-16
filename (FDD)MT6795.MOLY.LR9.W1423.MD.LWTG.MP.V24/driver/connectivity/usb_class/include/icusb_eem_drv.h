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
*  A. Patent Notice:
*  The software delivered hereunder, including any and all updates and upgrades, 
*  might be subject to patent rights of standard-setting organizations, patent pools 
*  or their respective patent owners, that will be necessarily infringed by the use 
*  and distribution of the products incorporating all or part of this software.  
*  According to the licensing terms of these patent holders, it is your sole 
*  obligation to obtain the necessary patent licenses from these patent holders 
*  before you can use or distribute the products incorporating all or part of this 
*  software. MediaTek shall not be liable for your failure to obtain or maintain such 
*  licenses.
*  
*    As a courtesy to our customers, the following are some of the software that might 
*    contain such patent licenses, but MediaTek does not warrant the accuracy or
*    completeness of the information below.  
*    (1) MPEG4/AAC/AACPLUS/AACVPLUSV2: essential patents license must be obtained
*        from Via Licensing: <www.vialicensing.com>
*    (2) WAP/MMS security RC5 algorithm belongs to RSA Data Security: 
*        <www.rsasecurity.com> 
*    Notice: Please contact RSA to get this license before shipping the products to 
*    USA which include RC5 security algorithm.
*  
*  B. In addition, customers must contact the respective licensors to obtain 
*  necessary software licenses before it can use or distribute the licensed 
*  products. 
*  
*    As a courtesy to our customers, the following are some of the software licensers 
*    and the notice or disclaimer required by their licenses, but MediaTek does not 
*    warrant the accuracy or completeness of the information below.  
*    (1) Microsoft Windows Media (WMA software): 
*        Microsoft: <www.microsoft.com> 
*        Approved OEM Manufacturers: <wmlicense.smdisp.net/oem_approved/>
*        Sample Windows Media Licensing Agreements: 
*        <www.microsoft.com/windows/windowsmedia/licensing/agreements.aspx>
*    Notice in header or documentation: "This product is protected by certain 
*    intellectual property rights of Microsoft and cannot be used or further 
*    distributed without a license from Microsoft."
*    
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   usb_host_eem_drv.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
  *   This file intends for host EEM class driver definitions
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef USB_HOST_EEM_DRV_H
#define USB_HOST_EEM_DRV_H

 //#include "icusb_drv.h"
 #include "drv_comm.h"
 #include "usb_host_default_drv.h"
/***********************************************
	eem class descriptor definition
************************************************/
#define USB_EEM_DEVICE_CODE						0x00
#define USB_EEM_SUBCLASS_CODE						0x00
#define USB_EEM_PROTOCOL_CODE						0x00

#define USB_EEM_DATA_INTERFACE_CLASS_CODE 		0x02
#define USB_EEM_DATA_INTERFACE_SUBCLASS_CODE 	0x0C
#define USB_EEM_DATA_INTERFACE_PROTOCOL_CODE 	0x07

/***********************************************
	eem class specific command definition
************************************************/
#define USB_EEM_Packet_Type_Mask 	0x8000
#define USB_EEM_Command 			0x3800
#define USB_EEM_Command_Param 	0x07FF

#define USB_EEM_DATA_CRC 			0x4000
#define USB_EEM_DATA_Length 		0x3FFF

#define USB_EEM_Header_Length 		2


#define USB_EEM_Command_TYPE		0x1000
#define USB_EEM_Data_TYPE			0x0000

#define USB_EEM_Data_CRC_SET			0x0000


/***********************************************
	eem class Buffer & Data Length 
************************************************/

#define USB_EEM_MAX_FRAME_SIZE			1518  // TCPIP protocol
#define USB_EEM_MIN_FRAME_SIZE			46 // TCPIP protocol 

#define EEM_TX_BUFFER_NUM  		10  // EEM task allocate buffer
#define EEM_RX_BUFFER_NUM  		10  // EEM task allocate buffer

#define USB_MAX_EEM_NUM   1


typedef enum 
{
	USB_EEM_DONE = 0,   	//Setup DMA 
	USB_EEM_TRANSFER,	 	// DMA Still Running --> last data hasn't send out
	USB_EEM_NEXT_TRANSFER,
	
	USB_EEM_NOT_READY, 	// USB config = F , Enumeraion not finish  or device removed
	
	USB_EEM_CRC_ERROR,  		// CRC_check_flag = T
	USB_EEM_LENGTH_ERROR,  	// Data length doesn't match  

	USB_EEM_HEADER_TYPE_ERROR, 		//  data or  command packet define
	USB_EEM_HEADER_PARAM_ERROR	 	//command parameter type	
	
} USB_EEM_RESPONSE;


typedef enum 
{
	IC_USB_SIM1 = 0,
	IC_USB_SIM2 
} IC_USB_NUM;

typedef enum
{
	USB_HOST_EEM_DATA_PAYLOAD = 0,
	USB_HOST_EEM_COMMAND
}USB_EEM_HEADER_TYPE;


typedef enum
{
	USB_HOST_EEM_CMD_ECHO = 0,
	USB_HOST_EEM_CMD_ECHO_RESPONSE,
	USB_HOST_EEM_CMD_SUSPEND_HINT,
	USB_HOST_EEM_CMD_RESPONSE_HINT,
	USB_HOST_EEM_CMD_RESPONSE_COMPLETE_HINT,
	USB_HOST_EEM_CMD_TICKLE
}USB_HOST_EEM_CMD;

typedef enum
{
	EEM_RX_FIRST_PACKET =0,
	EEM_RX_MIDDLE_PACKET,		
	EEM_RX_LAST_PACKET
}USBH_EEM_RX_STATE;

/* EEM Data header*/
typedef struct
{
	kal_bool				bmType;
	kal_bool        			bmCRC;
	kal_uint16			eem_frame_length;
}USBH_EEM_Data_Header;


/* EEM Command Header */
typedef struct
{
	kal_bool				bmType;
	USB_HOST_EEM_CMD        	bmEEMCmd;
	kal_uint16			eem_Cmd_Param;
}USBH_EEM_Command_Header;


typedef struct
{
	peer_buff_struct *buffer_ptr;
	kal_uint8     *data_ptr; 
	kal_uint16     data_length;
	kal_uint8 		 pool_id;
}EEM_Buffer_CONTROL;


typedef struct
{
	USBH_EP_Struct			ep_tx_info;
	USBH_EP_Struct			ep_rx_info;	
	USBH_Common_Struct		common_info;
	
	kal_uint8				dev_error_count;
	kal_bool				config;	//Descriptor match
	kal_bool				dev_attatch; //Vbus3.3 provide & Device class match	
	kal_bool				usb_command;
	kal_bool				reponse_hint;
	kal_bool				reponse_complete_hint;	
	kal_uint16			response_time;
	kal_uint16			response_complete_time;
  	
	kal_bool				dma_rx_running;
	kal_bool				dma_tx_running;

	kal_uint8				tx_sent_buff_index; //data is sending out
	kal_uint8				tx_wait_buff_index; // wait for next transfer
	EEM_Buffer_CONTROL   tx_buffer[EEM_TX_BUFFER_NUM];

	kal_uint8				rx_full_buff_index;  // receive Data 
	kal_uint8				rx_empty_buff_index; // empty buffer get from EEM Tsk
	EEM_Buffer_CONTROL   rx_buffer[EEM_RX_BUFFER_NUM];
	
	kal_uint16			rx_last_data_length;  //FIFO + DMA + FIFO
	kal_uint16			rx_dma_length;  //DMA transfer length
	USBH_EEM_RX_STATE   ep_rx_status;

	USB_EP_DIRECTION	stall_ep_dir;
   	kal_uint32				sleep_timer_handle;			/* use timer to check whether App need to use Device or not */
	
}USB_Host_EEM_Struct;

/************************************************************

	extern variables and functions

*************************************************************/
extern USBD_ClassDriver_Struct USB_Host_Eem_Drv;
extern USB_Host_EEM_Struct g_UsbHostEem[USB_MAX_EEM_NUM];

//extern kal_uint8 USB_EEM_Check_index(kal_uint8 usb_ip_port);
extern void USB_Host_EEM_State_Start(void);
extern void USB_Host_EEM_State_End(void);
extern void USB_Host_Eem_DMA_TX_Hdlr(void);
extern void USB_Host_Eem_DMA_RX_Hdlr(void);
extern void USB_Host_Eem_Data_Transfer(USB_EP_DIRECTION direction);
extern void USB_Host_Eem_ECHO_Command(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str, kal_uint16 nBytes, void *pDst);

#endif	/* USB_HOST_ACM_DRV_H */ 

 
