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
 *   dcl_usb_hcd.h
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_USB_HCD_H_STRUCT__
#define __DCL_USB_HCD_H_STRUCT__

#include "dcl.h"
//#include "dcl_usb_drv.h"
    


#define USB_EXT_IP_NUM						1   


#ifdef __IC_USB_ENABLE__
#define USB_INT_IP_NUM						1
#else
#define USB_INT_IP_NUM						0
#endif

#define  USB_IP_NUM		(USB_INT_IP_NUM + USB_EXT_IP_NUM)

#define  ICUSB_PORT_1    USB_EXT_IP_NUM // naming rule : USB2.0 ip = 0, ICUSB1 = 1 ;ICUSB2 = 2

    

typedef enum
{
	USB_HCD_OK,
	USB_HCD_NO_RESPONSE,	
	USB_HCD_TIMEOUT,	
	USB_HCD_STALL, 
	USB_HCD_PID_ERROR, 	
	USB_HCD_DETATCH,
	USB_HCD_DMA_TIMEOUT
}USB_HCD_STATUS;

typedef enum
{
	USB_HCD_BUS_SUSPEND_SOF,
	USB_HCD_BUS_RESUME_SOF, 
	USB_HCD_BUS_ASSERT_RESUME
}USB_HCD_BUS_TYPE;


typedef struct
{
	kal_uint16				ep_max_pkt_size;
	kal_uint8				ep_num;			
	kal_uint8				ep_real_num;			
	USB_ENDPT_TXFER_TYPE	ep_type;	
	USB_EP_DIRECTION 		direction;
}USBH_EP_Struct;



typedef struct
{
	kal_uint32				if_num;
	kal_uint8				usb_ip_port;	
}USBH_Common_Struct;


typedef enum
{
	USB_HCD_HDLR_ATTACH,
	USB_HCD_HDLR_DETACH,
	USB_HCD_HDLR_RESUME,
	USB_HCD_HDLR_EP0,
	USB_HCD_HDLR_EP_TX,
	USB_HCD_HDLR_EP_RX,
	USB_HCD_HDLR_MAX
}USB_HCD_HDLR_TYPE;


/* application dma callback function type */
//typedef void (*usb_dma_callback)(void);

/* interrupt handler function type */
//typedef void (*usb_hcd_intr_handler_ptr)(kal_uint8 usb_ip_port,USB_HCD_STATUS result, kal_uint32 param);




typedef enum
{
	DCL_USB_HCD_HDLR_ATTACH,
	DCL_USB_HCD_HDLR_DETACH,
	DCL_USB_HCD_HDLR_RESUME,
	DCL_USB_HCD_HDLR_EP0,
	DCL_USB_HCD_HDLR_EP_TX,
	DCL_USB_HCD_HDLR_EP_RX,
	DCL_USB_HCD_HDLR_MAX
}DCL_USB_HCD_HDLR_TYPE;


typedef enum
{
	DCL_USB_HCD_ENDPT_CTRL,
	DCL_USB_HCD_ENDPT_BULK,
	DCL_USB_HCD_ENDPT_INTR,
	DCL_USB_HCD_ENDPT_ISO
}DCL_USB_HCD_ENDPT_TYPE;


typedef enum
{
	DCL_USB_HCD_PIPE_DIR_RX,
	DCL_USB_HCD_PIPE_DIR_TX
}DCL_USB_HCD_PIPE_DIRECTION;


typedef enum
{
	DCL_USB_HCD_OK,
	DCL_USB_HCD_NO_RESPONSE,	
	DCL_USB_HCD_TIMEOUT,	
	DCL_USB_HCD_STALL, 
	DCL_USB_HCD_PID_ERROR, 	
	DCL_USB_HCD_DETATCH,
	DCL_USB_HCD_DMA_TIMEOUT	
}DCL_USB_HCD_STATUS;


typedef enum
{
	DCL_USB_HCD_BUS_SUSPEND_SOF,
	DCL_USB_HCD_BUS_RESUME_SOF, 
	DCL_USB_HCD_BUS_ASSERT_RESUME
}DCL_USB_HCD_BUS_TYPE;



typedef struct
{
	DCL_UINT16					ep_max_pkt_size;
	DCL_UINT8					ep_num;			
	DCL_UINT8					ep_real_num;			
	DCL_USB_ENDPT_TXFER_TYPE	ep_type;	
	DCL_USB_EP_DIRECTION 		direction;
}DCL_USBH_EP_Struct;



typedef struct
{
	DCL_UINT32				if_num;
	DCL_UINT8				usb_ip_port;	
}DCL_USBH_Common_Struct;



typedef void (*usb_hcd_intr_handler_ptr)(kal_uint8 usb_ip_port,USB_HCD_STATUS result, kal_uint32 param);
/* application dma callback function type */
typedef void (*DCL_USB_HCD_DMA_CALLBACK)(void);
typedef void (*DCL_USB_HCD_INTR_HDLR)(DCL_UINT8 usb_ip_port,DCL_USB_HCD_STATUS result, DCL_UINT32 param);
typedef void (*DCL_USB_HCD_REGISTRE_CALLBACK)(DCL_USB_HCD_HDLR_TYPE type, DCL_UINT32 ep_num, DCL_USB_HCD_INTR_HDLR hdlr);
typedef void (*DCL_USB_HCD_SET_ADDR)(DCL_UINT8 addr);
typedef DCL_BOOL (*DCL_USB_HCD_EP_DATA_TXFER)(DCL_UINT8 ep_num, DCL_UINT16 nBytes, void *pData);
typedef DCL_BOOL (*DCL_USB_HCD_EP_CTRL_FUNC_1)(DCL_UINT8 ep_num, DCL_USB_EP_DIRECTION direction, DCL_UINT16 max_pkt_size);
typedef void (*DCL_USB_HCD_EP_CTRL_FUNC_2)(DCL_UINT8 ep_num, DCL_USB_EP_DIRECTION direction);
typedef DCL_BOOL (*DCL_USB_HCD_EP_ENABLE)(DCL_UINT8 ep_num, DCL_USB_HCD_ENDPT_TYPE ep_type, DCL_UINT8 interval, DCL_BOOL bDMA);
typedef void (*DCL_USB_HCD_EP_DISABLE)(DCL_UINT8 ep_num, DCL_BOOL bDMA);
typedef void (*DCL_USB_HCD_EP_INIT)(DCL_UINT8 ep_num, DCL_UINT16 data_size, DCL_USB_ENDPT_TXFER_TYPE type);
typedef void (*DCL_USB_HCD_EP0_SETUP_REQ_FUNC)(DCL_UINT16 nBytes, void *pSrc);
typedef void (*DCL_USB_HCD_EP0_DATA_REQ_FUNC)(DCL_USB_HCD_PIPE_DIRECTION direction, DCL_UINT16 nBytes, void *pData);
typedef void (*DCL_USB_HCD_EP0_STATUS_REQ_FUNC)(DCL_USB_HCD_PIPE_DIRECTION direction);
typedef void (*DCL_USB_HCD_DMA_SETUP_FUNC)(DCL_UINT8 ep_num, DCL_USB_EP_DIRECTION direction, DCL_USB_ENDPT_TXFER_TYPE ep_type, 
						DCL_UINT32 addr, DCL_UINT32 length, DCL_BOOL callback_upd_run, 
						DCL_BOOL known_size, DCL_USB_DMA_TYPE dma_type);


/*******************************************************************************
 * DCL_OPTIONS for USB_HCD
 *******************************************************************************/
#define USB_HCD_OPTIONS


 /*******************************************************************************
 * DCL_CONFIGURE_T for USB_HCD
 *******************************************************************************/
#define USB_HCD_CONFIGS


/*******************************************************************************
 * DCL_EVENT for USB_HCD
 *******************************************************************************/
#define USB_HCD_EVENTS


/*******************************************************************************
 * DCL_CTRL_CMD for USB_HCD
 *******************************************************************************/
#define USB_HCD_CMDS \
	USB_HCD_CMD_USB_HCD_HW_Mapping_EP = 0, \
	USB_HCD_CMD_USB_HCD_Reset_Device, \
	USB_HCD_CMD_USB_HCD_SWRST, \
	USB_HCD_CMD_USB_HCD_EnSysIntr, \
	USB_HCD_CMD_USB_HCD_VBusEnable, \
	USB_HCD_CMD_USB_HCD_Host_Mode_Detect, \
	USB_HCD_CMD_USB_HCD_Is_HNP_SUPPORT, \
	USB_HCD_CMD_USB_HCD_Is_RemoteWakeup_SUPPORT, \
	USB_HCD_CMD_USB_HCD_Is_SRP_SUPPORT, \
	USB_HCD_CMD_USB_HCD_Is_High_Speed, \
	USB_HCD_CMD_USB_HCD_Reset_Resource, \
	USB_HCD_CMD_USB_HCD_Init_Drv_Info, \
	USB_HCD_CMD_USB_HCD_Release_Drv_Info, \
	USB_HCD_CMD_USB_HCD_Register_Drv_Info, \
	USB_HCD_CMD_USB_HCD_Set_UnMask_Irq, \
	USB_HCD_CMD_USB_HCD_Get_UnMask_Irq, \
	USB_HCD_CMD_USB_HCD_Dis_Attach, \
	USB_HCD_CMD_USB_HCD_En_Attach, \
	USB_HCD_CMD_USB_HCD_Initialize_Drv, \
	USB_HCD_CMD_USB_HCD_Release_Drv, \
	USB_HCD_CMD_USB_HCD_SetAddress, \
	USB_HCD_CMD_USB_HCD_Resume, \
	USB_HCD_CMD_USB_HCD_Suspend, \
	USB_HCD_CMD_USB_HCD_Delay_Reset_Device, \
	USB_HCD_CMD_USB_HCD_Set_EP_Max_Pkt, \
	USB_HCD_CMD_USB_HCD_Clear_Data01, \
	USB_HCD_CMD_USB_HCD_EP_Interval, \
	USB_HCD_CMD_USB_HCD_EP0En, \
	USB_HCD_CMD_USB_HCD_EP0_Data_Length, \
	USB_HCD_CMD_USB_HCD_EP_Rx_Pkt_Len, \
	USB_HCD_CMD_USB_HCD_Config_TxEP_Type, \
	USB_HCD_CMD_USB_HCD_TxEPInit, \
	USB_HCD_CMD_USB_HCD_Config_RxEP_Type, \
	USB_HCD_CMD_USB_HCD_RxEPInit, \
	USB_HCD_CMD_USB_HCD_TxEPEn, \
	USB_HCD_CMD_USB_HCD_RxEPEn, \
	USB_HCD_CMD_USB_HCD_TxEPDis, \
	USB_HCD_CMD_USB_HCD_RxEPDis, \
	USB_HCD_CMD_USB_HCD_Send_Resume, \
	USB_HCD_CMD_USB_HCD_Send_Suspend, \
	USB_HCD_CMD_USB_HCD_Send_Req, \
	USB_HCD_CMD_USB_HCD_Recv_Req, \
	USB_HCD_CMD_USB_HCD_EP0_Setup_Req, \
	USB_HCD_CMD_USB_HCD_EP0_Data_Req, \
	USB_HCD_CMD_USB_HCD_EP0_Status_Req, \
	USB_HCD_CMD_USB_HCD_Switch_DMA_Burst_mode, \
	USB_HCD_CMD_USB_HCD_Register_DMA_Channel, \
	USB_HCD_CMD_USB_HCD_Get_DMA_Real_Count, \
	USB_HCD_CMD_USB_HCD_Get_DMA_Channel, \
	USB_HCD_CMD_USB_HCD_Stop_DMA_Channel, \
	USB_HCD_CMD_USB_HCD_Free_DMA_Channel, \
	USB_HCD_CMD_USB_HCD_EPFIFORead, \
	USB_HCD_CMD_USB_HCD_EPFIFOWrite, \
	USB_HCD_CMD_USB_HCD_DMA_Setup, \
	USB_HCD_CMD_USB_HCD_Disconn_Hdlr, \
	USB_HCD_CMD_USB_HCD_Conn_Hdlr, \
	USB_HCD_CMD_USB_HCD_HISR, \
	USB_HCD_CMD_IC_USB_Drv_Create_ISR, \
	USB_HCD_CMD_IC_USB_Drv_Activate_ISR, \
	USB_HCD_CMD_IC_USBDMA_Drv_Create_ISR, \
	USB_HCD_CMD_IC_USBDMA_Drv_Activate_ISR, \
	USB_HCD_CMD_IC_USB_PDNmode, \
	USB_HCD_CMD_USB_HCD_VBUS_OFF, \



/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/

typedef struct
{
	DCL_UINT8	ip;
	DCL_USB_HCD_HDLR_TYPE type;
	DCL_UINT32 u4ep_num;
	DCL_USB_HCD_INTR_HDLR hdlr;
}USB_HCD_CTRL_REGISTER_DRV_INFO_T;



typedef struct
{
	DCL_UINT8	ip;
	DCL_UINT8 addr;
}USB_HCD_CTRL_SET_ADDRESS_T;


typedef struct
{
	DCL_UINT8	ip;
	DCL_UINT8	return_value;
	DCL_USB_EP_DIRECTION direction;
}USB_HCD_CTRL_EP_MAPPING_T;


typedef struct
{
	DCL_UINT8	ip;
	DCL_USB_HCD_STATUS reset_reason;
}USB_HCD_CTRL_RESET_T;


typedef struct
{
	DCL_UINT8	ip;
	DCL_BOOL 	set;
}USB_HCD_CTRL_SYSTEM_T;



typedef struct
{
	DCL_UINT8	ip;
	DCL_BOOL	return_value;	
}USB_HCD_CTRL_IP_NUM_T;


typedef struct
{
	DCL_BOOL 	set;
}USB_HCD_CTRL_SET_T;

typedef struct
{
	DCL_UINT8	ip;
	DCL_USB_HCD_STATUS result;
	DCL_UINT32 u4param;
}USB_HCD_CTRL_DELAY_RESET_DEVICE_T;


typedef struct
{
	DCL_USBH_Common_Struct common_str;
	DCL_USBH_EP_Struct usb_ep_str;
}USB_HCD_CTRL_EP_CTRL_FUNC_1_T;


typedef struct
{
	DCL_USBH_Common_Struct common_str;
	DCL_USBH_EP_Struct usb_ep_str;
	DCL_UINT8		interval;
}USB_HCD_CTRL_EP_CTRL_FUNC_2_T;


typedef struct
{
	DCL_USBH_Common_Struct common_str;
	DCL_UINT16	return_value;
}USB_HCD_CTRL_EP_CTRL_FUNC_3_T;


typedef struct
{
	DCL_USBH_Common_Struct common_str;
	DCL_USBH_EP_Struct usb_ep_str;
	DCL_UINT32	return_value;	
}USB_HCD_CTRL_EP_CTRL_FUNC_4_T;


typedef struct
{
	DCL_USBH_Common_Struct common_str;
	DCL_USBH_EP_Struct usb_ep_str;
	DCL_BOOL set;
}USB_HCD_CTRL_EP_CTRL_FUNC_5_T;


typedef struct
{
	DCL_USBH_Common_Struct common_str;
	DCL_USBH_EP_Struct usb_ep_str;
	DCL_UINT8 u1interval;
	DCL_BOOL fgbDMA;
	DCL_BOOL fgbDMAQ;	
}USB_HCD_CTRL_EP_ENABLE_T;


typedef struct
{
	DCL_USBH_Common_Struct common_str;
	DCL_USBH_EP_Struct usb_ep_str;
	DCL_BOOL fgbDMA;
	DCL_BOOL fgbDMAQ;	
}USB_HCD_CTRL_EP_DISABLE_T;


typedef struct
{
	DCL_USBH_Common_Struct common_str;
	DCL_USBH_EP_Struct usb_ep_str;
	DCL_UINT16 u2nBytes;
	DCL_BOOL return_value;	
	void *pData;
}USB_HCD_CTRL_EP_DATA_TXFER_T;


typedef struct
{
	DCL_USBH_Common_Struct common_str;
	DCL_USBH_EP_Struct usb_ep_str;
	DCL_UINT16 u2nBytes;
	void *pSrc;
}USB_HCD_CTRL_EP0_SETUP_REQ_T;


typedef struct
{
	DCL_USBH_Common_Struct common_str;
	DCL_USBH_EP_Struct usb_ep_str;
	DCL_UINT16 u2nBytes;
	void *pData;
}USB_HCD_CTRL_EP0_DATA_REQ_T;


typedef struct
{
	DCL_USBH_Common_Struct common_str;
	DCL_USBH_EP_Struct usb_ep_str;
}USB_HCD_CTRL_EP0_STATUS_REQ_T;


typedef struct
{
	DCL_UINT8  ip;
	DCL_UINT8 u1ep_num;
	DCL_USB_EP_DIRECTION direction;
	DCL_UINT8 u1chan_num; 
	DCL_BOOL fgsame_chan;
}USB_HCD_CTRL_DMA_CTRL_FUNC_1_T;


typedef struct
{
	DCL_UINT8  ip;
	DCL_UINT8 u1ep_num;
	DCL_UINT32 return_value;
	DCL_USB_EP_DIRECTION direction;
}USB_HCD_CTRL_DMA_CTRL_FUNC_2_T;


typedef struct
{
	DCL_USBH_Common_Struct common_str;
	DCL_USBH_EP_Struct usb_tx_str;
	DCL_USBH_EP_Struct usb_rx_str;
	DCL_USB_EP_DIRECTION direction;
	DCL_BOOL same_chan;
}USB_HCD_CTRL_DMA_CHANNEL_FUNC_T;


typedef struct
{
	DCL_USBH_Common_Struct common_str;
	DCL_USBH_EP_Struct usb_ep_str;
	DCL_UINT32 u4addr;
	DCL_UINT32 u4length;
	DCL_USB_HCD_DMA_CALLBACK callback;
	DCL_BOOL fgcallback_upd_run;
	DCL_BOOL fgknown_size;
	DCL_USB_DMA_TYPE dma_type;
}USB_HCD_CTRL_DMA_SETUP_FUNC_T;





#define USB_HCD_CTRLS \
   USB_HCD_CTRL_REGISTER_DRV_INFO_T   		rHCD_Drv_Info; \
   USB_HCD_CTRL_SET_ADDRESS_T   			rHCD_Set_Addr; \
   USB_HCD_CTRL_DELAY_RESET_DEVICE_T   		rHCD_Delay_Reset_Device; \
   USB_HCD_CTRL_EP_CTRL_FUNC_1_T   			rHCD_EP_Ctrl_Func_1; \
   USB_HCD_CTRL_EP_CTRL_FUNC_2_T   			rHCD_EP_Ctrl_Func_2; \
   USB_HCD_CTRL_EP_ENABLE_T   				rHCD_EP_Enable; \
   USB_HCD_CTRL_EP_DISABLE_T   				rHCD_EP_Disable; \
   USB_HCD_CTRL_EP_DATA_TXFER_T   			rHCD_EP_Data_Txfer; \
   USB_HCD_CTRL_EP0_SETUP_REQ_T   			rHCD_EP0_Setup_Req; \
   USB_HCD_CTRL_EP0_DATA_REQ_T   			rHCD_EP0_Data_Req; \
   USB_HCD_CTRL_EP0_STATUS_REQ_T   			rHCD_EP0_Status_Req; \
   USB_HCD_CTRL_DMA_SETUP_FUNC_T   			rHCD_DMA_Setup_Func; \
   USB_HCD_CTRL_EP_MAPPING_T              rHCD_EP_Set; \
   USB_HCD_CTRL_SET_T											rHCD_Set; \
   USB_HCD_CTRL_RESET_T										rHCD_RESET; \
   USB_HCD_CTRL_SYSTEM_T									rHCD_System_Set; \
   USB_HCD_CTRL_IP_NUM_T   								rHCD_ip; \
   USB_HCD_CTRL_EP_CTRL_FUNC_3_T					rHCD_EP_Ctrl_Func_3; \
   USB_HCD_CTRL_EP_CTRL_FUNC_4_T  				rHCD_EP_Ctrl_Func_4; \
   USB_HCD_CTRL_EP_CTRL_FUNC_5_T					rHCD_EP_Ctrl_Func_5; \
   USB_HCD_CTRL_DMA_CTRL_FUNC_1_T					rHCD_DMA_Ctrl_Func_1; \
   USB_HCD_CTRL_DMA_CTRL_FUNC_2_T					rHCD_DMA_Ctrl_Func_2; \
   USB_HCD_CTRL_DMA_CHANNEL_FUNC_T     	  rHCD_DMA_Channel_Func; \


#endif // #ifndef __DCL_USB_HCD_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT



#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_USB_HCD_H_PROTOTYPE__
#define __DCL_USB_HCD_H_PROTOTYPE__

/*************************************************************************
* FUNCTION
*  DclUSB_HCD_Initialize
*
* DESCRIPTION
*  This function is to initialize USB_HCD module
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclUSB_HCD_Initialize(void);
/*************************************************************************
* FUNCTION
*  DclUSB_HCD_Open
*
* DESCRIPTION
*  This function is to open the SW ADC module and return a handle
*
* PARAMETERS
*  dev: only valid for DCL_USB
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed
*  Other value: A valid handle
*
*************************************************************************/
extern DCL_HANDLE DclUSB_HCD_Open(DCL_DEV dev, DCL_FLAGS flags);
/*************************************************************************
* FUNCTION
*  DclUSB_HCD_ReadData
*
* DESCRIPTION
*  This function is not supported for the ADC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclUSB_HCD_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclUSB_HCD_WriteData
*
* DESCRIPTION
*  This function is not supported for the ADC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclUSB_HCD_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclUSB_HCD_Configure
*
* DESCRIPTION
*  This function is not supported for the ADC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclUSB_HCD_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION
*  DclUSB_HCD_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the ADC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclUSB_HCD_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);
/*************************************************************************
* FUNCTION
*  DclUSB_HCD_Control
*
* DESCRIPTION
*  This function is to send command to control the SW ADC module.
*
* PARAMETERS
*  handle: A valid handle return by DclSADC_Open()
*  cmd: A control command for ADC module
*          1. ADC_CMD_CREATE_OBJECT: to create measurement object
*          2. ADC_CMD_MODIFY_PARAM: to change measurement parameters
*          3. ADC_CMD_START_MEASURE: to start measurement item
*          4. ADC_CMD_STOP_MEASURE: to stop measurement item
*  data: The data of the control command
*          1. ADC_CMD_CREATE_OBJECT: pointer to a ADC_CTRL_CREATE_OBJECT_T structure
*          2. ADC_CMD_MODIFY_PARAM: pointer to a ADC_CTRL_MODIFY_PARAM_T structure
*          3. ADC_CMD_START_MEASURE: a null pointer
*          4. ADC_CMD_STOP_MEASURE: a null pointer
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
extern DCL_STATUS DclUSB_HCD_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION
*  DclUSB_HCD_Close
*
* DESCRIPTION
*  This function is to close the SW ADC module.
*
* PARAMETERS
*  handle: the returned handle value of DclSADC_Open
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclUSB_HCD_Close(DCL_HANDLE handle);


#endif // #ifndef __DCL_USB_HCD_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE



