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
 *    usbd.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *    This file intends for usb1.1 host definitions.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef USBD_H
#define USBD_H

//#include "usb_hcd.h"
#include "dcl.h"
//#include "kal_non_specific_general_types.h"
#include "usb.h"
#include "usb_drv.h"
#include "usb_custom_def.h"


#define USBD_MAX_CFG_NUM			8
#define USBD_MAX_IF_PER_CFG		4
#define USBD_MAX_INTERFACE_NUM			(USBD_MAX_CFG_NUM * USBD_MAX_IF_PER_CFG)
#define USBD_MAX_EP_PER_IF			3
#define USBD_MAX_EP_NUM				(USBD_MAX_INTERFACE_NUM * USBD_MAX_EP_PER_IF)
#define USBD_MAX_CLASS_DRIVER		2

#define USBD_EP0_MAX_PKT_SIZE		64

#define USBD_ERROR_DELAY			35  /* 10ms unit*/

#define USBD_SET_ADDRESS_RECOVERY_DELAY 	1

#define USBD_TEST_MODE_DELAY			1500
//#define USBD_TEST_MODE_DELAY			300


#ifdef __OTG_ENABLE__
#define USB_EXT_HOST_NUM					1
#else
#define USB_EXT_HOST_NUM					0
#endif

#ifdef __IC_USB_ENABLE__
#define USB_INT_HOST_NUM					1
#else
#define USB_INT_HOST_NUM					0
#endif


#define  USB_HOST_NUM		(USB_EXT_HOST_NUM + USB_INT_HOST_NUM)


/* USBD test mode */
#define USBD_TEST_SE0_NAK									0x0101
#define USBD_TEST_J											0x0102
#define USBD_TEST_K											0x0103
#define USBD_TEST_PACKET									0x0104
#define USBD_TEST_HS_HOST_PORT_SUSPEND_RESUME			0x0106
#define USBD_TEST_SINGLE_STEP_GET_DEV_DESC				0x0107
#define USBD_TEST_SINGLE_STEP_SET_FEATURE				0x0108
#define USBD_TEST_UNSUPPORTED_DEVICE						0xBADD




#define EVENT_USBD_EP0_DONE					((kal_uint32)0x00000001)
#define EVENT_USBD_EP0_DETACH					((kal_uint32)0x00000002)
#define EVENT_USBD_EP0_ENUMERATION			((kal_uint32)0x00000004)
#define EVENT_USBD_RESUME_DONE				((kal_uint32)0x00000008)

typedef enum
{
	USBD_CH9_START,
	USBD_CH9_STOP,
	USBD_CH9_DELAY_SET_ADDR,
	USBD_CH9_SET_ADDR,
	USBD_CH9_GET_DEV_DESC_8,
	USBD_CH9_GET_DEV_DESC,
	USBD_CH9_GET_CONF_DESC_9,
	USBD_CH9_GET_CONF_DESC,
	USBD_CH9_SET_CONF,
	USBD_CH9_SET_HNP_ENABLE,
	USBD_CH9_ENUM_OK,
	USBD_CH9_ENUM_FAIL
}USBD_CH9_STATE;


typedef enum
{
	USBD_EP0_SETUP,
	USBD_EP0_DATA,
	USBD_EP0_STATUS,
	USBD_EP0_NONE
}USBD_EP0_STATE;


typedef enum
{
	USBD_EP0_DATA_RECV,
	USBD_EP0_DATA_SEND,
	USBD_EP0_DATA_NULL	/* no data phase is needed */
}USBD_EP0_DATA_DIR;


typedef enum
{
	USBD_HNP_NOT_SUPPORT,
	USBD_HNP_SUPPORT,
	USBD_HNP_ENABLE_STALL
}USBD_HNP_SUPPORT_TYPE;


typedef enum 
{
	USBD_TEST_MODE_NONE = 0,
	USBD_TEST_MODE_TYPE_SE0,
	USBD_TEST_MODE_TYPE_J,
	USBD_TEST_MODE_TYPE_K,
	USBD_TEST_MODE_TYPE_TEST_PACKET,
	USBD_TEST_MODE_TYPE_HS_HOST_PORT_SUSPEND_RESUME,
	USBD_TEST_MODE_TYPE_SINGLE_STEP_GET_DEV_DESC,
	USBD_TEST_MODE_TYPE_SINGLE_STEP_SET_FEATURE,
	USBD_TEST_MODE_TYPE_UNSUPPORTED_DEVICE
}USBD_TEST_MODE_TYPE;


/* EP0 status */
typedef struct 
{
	kal_uint8				device_addr;		/* new function address */
//	kal_uint8				max_packet_size;	
	Usb_Command				setup_cmd;			/* setup packet address */
	kal_uint8				*data_ptr;			/* data packet address */
	USBD_EP0_DATA_DIR		ep0_data_dir;		/* data phase direction */
	kal_uint32				sofar;				/* number of bytes sent/recv'd so far */
   	kal_uint32				todo;				/* number of bytes to send/recv */								
}USBD_EP0_Status;


/* Bulk IN endpoint status */
typedef struct 
{
	kal_uint8				max_packet_size;	
	kal_uint8				*data_ptr;			/* data packet address */
	kal_uint32				sofar;				/* number of bytes sent/recv'd so far */
   	kal_uint32				todo;				/* number of bytes to send/recv */		
}USBD_EPIN_Status;


/* Bulk OUT endpoint status */
typedef struct 
{
	kal_uint8				max_packet_size;	
	kal_uint8				*data_ptr;			/* data packet address */
	kal_uint32				sofar;				/* number of bytes sent/recv'd so far */
   	kal_uint32				todo;				/* number of bytes to send/recv */		
}USBD_EPOUT_Status;

/* endpoint information, including endpoint status */
typedef struct 
{
	Usb_Ep_Dscr				*p_stdep;			/* ep descriptor */
	union 
	{
		USBD_EPIN_Status	epin_status;
		USBD_EPOUT_Status	epout_status;
	}ep_status;			
}USBD_EP_Info;


typedef struct
{
	Usb_If_Dscr				*p_interface_desc;
	USBD_EP_Info			*p_ep_info[USBD_MAX_EP_PER_IF];
	kal_uint8				ep_number;
}USBD_IF_Info;


typedef struct
{
	Usb_Cfg_Dscr			*p_cfg_desc;
	USBD_IF_Info			*p_interface_info[USBD_MAX_IF_PER_CFG];
	kal_uint8				match_class_driver_index[USBD_MAX_IF_PER_CFG];	/* To store the class driver index for each interface */
	kal_uint8				match_class_driver_point;					/* To store the weighting of class driver index for each configuration */
	kal_uint8				active_if_index_map;				/* the index mapping that the active interface */
	kal_uint8			interface_number;
	kal_uint8				match_class_num;	/* the number that match class drivers, exclude default driver */
}USBD_CFG_Info;


typedef struct
{
	Usb_Dev_Dscr			dev_desc;
	USBD_CFG_Info			cfg_info[USBD_MAX_CFG_NUM];
//	Usb_IAD_Dscr					*iad_desc;
	USBD_IF_Info			interface_info[USBD_MAX_INTERFACE_NUM];
	USBD_EP_Info			ep_info[USBD_MAX_EP_NUM];
	Usb_String_Dscr				*string_desc;
	Usb_Otg_Dscr				*p_otg_desc[USBD_MAX_CFG_NUM];	
	Usb_Dev_Qual_Dscr			*dev_qual_dscr;
	Usb_Other_Speed_Cfg_Dscr	*other_speed_cfg_dscr;
//	Usb_OS_String_Dscr			*os_string_desc;
//	Usb_Ext_Compat_ID_OS_Feature_Dscr		*os_feature_desc;
	kal_uint8					*p_conf_data[USBD_MAX_CFG_NUM];	
	kal_uint8					cfg_number;
}USBD_Desc_Info;


typedef struct
{
	kal_bool (* match)(kal_uint8 usb_ip_port, USBD_Desc_Info *p_desc_info, kal_uint32 cfg_num, kal_uint32 if_num);
	void (* startup)(kal_uint8 usb_ip_port, USBD_Desc_Info *p_desc_info, kal_uint32 cfg_num, kal_uint32 if_num);
	void (* detach)(kal_uint8 usb_ip_port);
	void (* suspend)(kal_uint8 usb_ip_port);
	void (* resume)(kal_uint8 usb_ip_port);
}USBD_ClassDriver_Struct;


typedef void (*usbd_ep0_callback)(kal_uint8 usb_ip_port, USB_HCD_STATUS result, kal_uint32 param);


typedef struct 
{
	USBD_Desc_Info			desc_info;
	USBD_EP0_STATE			ep0_state;	//states machine
	USBD_EP0_Status			ep0_status;	
	USBD_CH9_STATE			ch9_state;
	USBD_ClassDriver_Struct	*class_driver_ptr[USBD_MAX_CLASS_DRIVER];
	usbd_ep0_callback		ep0_callback;
	kal_uint8				ch9_error_count;
	USBD_HNP_SUPPORT_TYPE		support_hnp;
	kal_uint8				default_class_driver_index;
	kal_bool				b_is_match_hub;
	kal_uint32				gpt_handle;    /*GPT handle*/
	kal_mutexid				usbd_ep0_mutex_id;			/* mutex used to protect ep0 setup command. */
	kal_mutexid				usbd_resume_mutex_id;			/* mutex used to protect ep0 setup command. */	
	kal_eventgrpid			usbd_ep0_event_id;			/* event used for ep0 command */
	kal_eventgrpid			usbd_resume_event_id;			/* event used for ep0 command */	
	kal_bool				b_suspend_mode;
	kal_uint8 				set_cfg_number;
	kal_uint8				usb_ip_port;
}USBD_Struct;


typedef struct
{
	kal_mutexid				usbd_com_ep0_mutex_id;			/* mutex used to let multiple IPs can be enumerated one by one*/
	kal_eventgrpid			usbd_com_ep0_event_id;			/* event used for waiting enumeration done */
	/* Customizable variables */
	const USB_HOST_MATCH_PARAM		*host_match_param;
}USBD_Common_Struct;



//extern void USBD_Deregister_Port_Info(kal_uint8 *usb_ip_port_ptr);
extern void USBD_Init_Status(kal_uint8 usb_ip_port);
extern void USBD_Init(kal_uint8 usb_ip_port);
extern void USBD_Release_Status(kal_uint8 usb_ip_port);
extern void USBD_Release(kal_uint8 usb_ip_port);
extern void USBD_Attatch_Hdlr(kal_uint8 usb_ip_port, USB_HCD_STATUS result, kal_uint32 param);
extern void USBD_Detach_Hdlr(kal_uint8 usb_ip_port, USB_HCD_STATUS result, kal_uint32 param);
extern void USBD_Suspend_Hdlr(kal_uint8 usb_ip_port, USB_HCD_STATUS result, kal_uint32 param);
extern USBD_HNP_SUPPORT_TYPE USBD_Get_HNP_Support(kal_uint8 usb_ip_port);
extern kal_bool USBD_Is_Match_Hub(kal_uint8 usb_ip_port);
extern void ICUSB_Drv_Init(void);
extern void USBD_Register_Port_Info(kal_uint8 usb_ip_port, kal_bool b_is_ext_ip);

// Class layer usage API
extern void USBD_Clear_Feature(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str,kal_bool b_is_from_class_drv, usbd_ep0_callback callback);
extern void USBD_Start_Setup_Cmd(USBH_Common_Struct common_str, Usb_Command *usbd_cmd, kal_uint8* data_ptr, USBD_EP0_DATA_DIR direction, kal_uint32 length, kal_bool b_is_from_class_drv, usbd_ep0_callback callback);
extern kal_bool USBD_Send_Req(USBH_Common_Struct common_str,USBH_EP_Struct ep_str, kal_uint16 nBytes, void *pSrc);
extern kal_bool USBD_Recv_Req(USBH_Common_Struct common_str,USBH_EP_Struct ep_str, kal_uint16 nBytes, void *pDst);
extern void USBD_Suspend_Req(USBH_Common_Struct common_str);
extern void USBD_Reset_Req(USBH_Common_Struct common_str);
extern void USBD_Register_Drv_Info(USBH_Common_Struct common_str,USB_HCD_HDLR_TYPE type, USBH_EP_Struct usb_ep_str, usb_hcd_intr_handler_ptr hdlr);
extern kal_uint8  USBD_HW_Mapping_EP(USBH_Common_Struct common_str,USB_EP_DIRECTION direction);
extern void USBD_Dis_Attach(USBH_Common_Struct common_str);
extern void USBD_En_Attach(USBH_Common_Struct common_str);
extern void USBD_Config_TxEP_Type(USBH_Common_Struct common_str,USBH_EP_Struct ep_str,kal_bool b_is_switch_to_dma);
extern void USBD_Config_RxEP_Type(USBH_Common_Struct common_str,USBH_EP_Struct ep_str,kal_bool b_is_switch_to_dma);
extern void USBD_EP_Interval(USBH_Common_Struct common_str,USBH_EP_Struct ep_str,kal_uint8 interval);
extern void USBD_RxEPInit(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str);
extern void USBD_TxEPInit(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str);
extern void USBD_RxEPEn(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str, kal_uint8 interval, kal_bool bDMA);
extern void USBD_TxEPEn(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str, kal_uint8 interval, kal_bool bDMA);
extern void USBD_TxEPDis(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str, kal_bool bDMA);
extern void USBD_RxEPDis(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str, kal_bool bDMA);
extern void USBD_EPFIFORead(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str, kal_uint16 nBytes, void *pDst);
extern void USBD_EPFIFOWrite(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str, kal_uint16 nBytes, void *pDst);
extern kal_uint16 USBD_EP0_Data_Length(USBH_Common_Struct common_str);
extern kal_uint32 USBD_EP_Rx_Pkt_Len(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str);
extern void USBD_Clear_Data01(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str);
extern void USBD_Get_DMA_Channel(USBH_Common_Struct common_str,USBH_EP_Struct usb_tx_str, USBH_EP_Struct usb_rx_str, USB_EP_DIRECTION direction, kal_bool same_chan);
extern void USBD_Free_DMA_Channel(USBH_Common_Struct common_str,USBH_EP_Struct usb_tx_str, USBH_EP_Struct usb_rx_str, USB_EP_DIRECTION direction, kal_bool same_chan);
extern void USBD_DMA_Setup(USBH_Common_Struct common_str,USBH_EP_Struct ep_str,kal_uint32 addr, kal_uint32 length,usb_dma_callback callback,kal_bool callback_upd_run, kal_bool known_size, USB_DMA_TYPE dma_type);			
extern void USBD_Set_EP_Max_Pkt(USBH_Common_Struct common_str,USBH_EP_Struct usb_ep_str);
extern kal_bool USBD_Get_UnMask_Irq(USBH_Common_Struct common_str);
extern kal_bool USBD_Is_High_Speed(USBH_Common_Struct common_str);
extern void USBD_VBusEnable(USBH_Common_Struct common_str,kal_bool enable);
extern kal_bool USBD_Bootup_Mode(void);
	

#endif /* USBD_H*/

