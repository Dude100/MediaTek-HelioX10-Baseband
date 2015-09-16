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
 *    usbms_drv.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file intends for usb MASS STORAGE class driver definitions
 *
 * Author:
 * -------
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef USBMS_DRV_H
#define USBMS_DRV_H

//#include "kal_non_specific_general_types.h"
#include "usb_custom.h"
#include "usb_msdisk.h"
#include "usb.h"
#include "usb_adap.h"
#include "fs_type.h"
#include "usb_custom_def.h"



/***********************************************
	ms class specific command definition
************************************************/ 

#define USB_MS_DEVICE_CODE				0x00
#define USB_MS_SUBCLASS_CODE			0x00
#define USB_MS_PROTOCOL_CODE			0x00
#define USB_MS_INTERFACE_CLASS_CODE 	0x08
#define USB_MS_INTERFACE_SUBCLASS_CODE 	0x06
#define USB_MS_INTERFACE_SUBCLASS_CODE_2 	0x05
#define USB_MS_INTERFACE_PROTOCOL_CODE 	0x50

/*Class Requset Code, EP0 command*/
#define USB_MS_RESET         			0xff
#define USB_MS_GETMAXLUN     			0xfe

/*Mass storage command*/
#define USBMS_FORMAT_UNIT				0x04
#define USBMS_INQUIRY					0x12
#define USBMS_MODE_SENSE   				0x5a
#define USBMS_MODE_SENSE6   			0x1a
#define USBMS_MODE_SELECT     				0x55
#define USBMS_MODE_SELECT6     			0x15
#define USBMS_PREVALLOW_MEDIA_REMOVL	0x1e
#define USBMS_READ10 						0x28
#define USBMS_READ12 						0xa8
#define USBMS_READ_FORMATCAPACITY		0x23
#define USBMS_REQUESTSENSE				0x03
#define USBMS_START_STOP_UNIT			0x1b
#define USBMS_TEST_UNIT_READY			0x00
#define USBMS_VERIFY					0x2f
#define USBMS_WRITE10			   			0x2a
#define USBMS_WRITE12			   			0xaa
#define USBMS_READ_CAPACITY   			0x25


/*CD-ROM command*/
#define USBMS_READ_TOC  				0x43
#define USBMS_READ_DISC_INFO			0X51

/*Vendor Command*/
#define USBMS_VENDOR_READ10				0xD0
#define USBMS_VENDOR_WRITE10			0xD1
#define USBMS_VENDOR_CMD				0xF0
#define USBMS_VENDOR_CMD_SUB_SET		0x01
#define USBMS_VENDOR_CMD_SUB_GET		0x02
#define USBMS_VENDOR_CMD_SUB_META		0x03
#define USBMS_VENDOR_CMD_SUB_SET_WIN	0x01
#define USBMS_VENDOR_CMD_SUB_SET_MAC	0x02
#define USBMS_VENDOR_CMD_SUB_SET_LINUX	0x03



/***********************************************
	implement definition
************************************************/

#define USB_MS_EP_NUMBER				2 

#define MAX_DISK_DRVER              	4

#define USBMS_DMA_TIMEOUT 		480

#define USBMS_MAX_SINGLE_BUFFERSIZE     (USBMS_MAX_BUFFERSIZE/2)

#define USBMS_TX_THREADHOLD     		(16*1024)

#define USBMS_RX_MAX_SECTOR         	(USBMS_MAX_SINGLE_BUFFERSIZE/512)

#if USBMS_MAX_SINGLE_BUFFERSIZE > USBMS_TX_THREADHOLD
#define USBMS_TX_MAX_SECTOR         	(USBMS_TX_THREADHOLD/512)
#else
#define USBMS_TX_MAX_SECTOR          	(USBMS_MAX_SINGLE_BUFFERSIZE/512)
#endif

#define USBMS_READ_FAIL_TIMEOUT         50
#define USBMS_VENDOR_CMD_TIMEOUT         50
#define USBMS_UNKNOW_CMD_TIMEOUT         500

#define	USBMS_INVALID_MAX_LUN			0xFF

/***********************************************
	ms class specific descriptor structure
************************************************/

typedef struct
{
	kal_uint32 dCBWSignature;
	kal_uint32 dCBWTag;
	kal_uint32 dCBWDataTransferLength;
	kal_uint8  bmCBWFlags;
	kal_uint8  bCBWLUN;
	kal_uint8  bCBWCBLength;
	kal_uint8  CBWCB[16];
} UsbMs_CBW;


typedef struct
{
	kal_uint32 dCSWSignature;
	kal_uint32 dCSWTag;
	kal_uint32 dCSWDataResidue;    
	kal_uint8  bmCSWStatus;        	
	kal_uint8  padding[3];			/* padding to multiple of 4*/
} UsbMs_CSW;


/***********************************************
	implement enum and structure 
************************************************/

/*Mass storage state*/
typedef enum 
{
	USBMS_IDLE = 0,  		/*Receive Command*/
	USBMS_RX,  		/*Receive Data*/
	USBMS_TX,  		/*Transmit Data*/
	USBMS_ACK  		/*Transmit Data*/
//	USBMS_GETNEXTCMD,
//	USBMS_RESET_STATE
}USBMS_STATE;


/* read capacity command structure */
typedef struct
{
	kal_uint32 LastBA;	/*depend on the target*/
	kal_uint32 BlkLen;	/*512*/
} Read_Capacity_Info;     


/* maintain read/write status */
typedef struct
{
	kal_uint32	LBA;       /*Logical block address*/
	kal_uint32	BlkLen;    /*512*/
	kal_uint32	rwindex;   /*if (rwindex==BlkLen) transation done.*/
	kal_uint32	msdc_rwindex;
	kal_bool	rw_error_status;
	kal_uint8	rw_buffer_index;
} UsbMs_RW_Cmd;  


typedef struct
{
	kal_uint8	ms_buffer[2][USBMS_MAX_SINGLE_BUFFERSIZE];
}Usb_Disk_Buffer;


typedef struct
{
	USBMS_STATE			nState;
	kal_bool 			cbw_is_vaild;
	kal_bool 			ms_is_reset;				/* USB ep0 receive reset cmd */
	kal_bool			usb_reset;					/* USB receive reset signal */
	kal_bool			ms_read_write_reset;        /* USB bus reset vaule=True, After READ/WRITE10(12) = False */
	kal_uint8   		max_LUN;
	kal_uint8			current_LUN;
	kal_bool 			is_send_usb_reset_ilm; /* avoid to send reset messages too many times */
	kal_bool			power_off_state[MAX_DISK_DRVER];
	kal_bool			prev_write_fail[MAX_DISK_DRVER];	

#ifdef __USB_OTG_RX_TEST__
	kal_bool device_ms_rx_test_flag;
#endif
#ifdef __USB_OTG_TX_TEST__
	kal_bool device_ms_tx_test_flag;
#endif	
	kal_uint8  		    CSWStatusError;
	kal_uint32			CSWDataResidue;
	
	Usb_EpBIn_Status	*txpipe;
	Usb_EpBOut_Status	*rxpipe;
	kal_uint32			CBWdata[32/4];
//	UsbMs_CSW			CSW;
	UsbMs_RW_Cmd      	rw_cmd;

	Usb_Ep_Info			*ms_ep_in_info;
	Usb_Ep_Info			*ms_ep_out_info;
	Usb_Interface_Info	*ms_if_info;
	kal_uint8   		*sensePtr;


//	kal_uint8   		dma_timeout_handle; 	/* DMA time out timer */

#ifdef __USB_IN_NORMAL_MODE_IMPROVE__
	FS_HANDLE			system_drive_handle;
	USB_STORAGE_DEV_TYPE		device_type;
#endif
#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__
	FS_HANDLE			cdrom_drive_handle;
#endif

	/* buffer for read/write operation*/
	Usb_Disk_Buffer		*disk_buffer;

	/* customizable variables*/
   	const USB_MS_PARAM	*ms_param;

#ifdef __P_PROPRIETARY_COPYRIGHT__
	kal_bool			b_read_protect;
	kal_uint32			*read_protect_items;
	kal_uint32			*read_protect_second_items;
	kal_uint32			*read_protect_index;			
	kal_uint32			*read_protect_second_index;
	kal_uint32			read_protect_num;	
	USB_STORAGE_DEV_TYPE	read_protect_dev_type;
#endif

//	kal_bool 			b_ms_first_plugin;  /*whether it is first plug in or not in ms mode */
} UsbMs_Struct;


/***********************************************
	function and global variable
************************************************/
extern UsbMs_Struct g_UsbMS;

extern void USB_Ms_BuildRx(void *addr,kal_uint32 len);
extern void USB_Ms_BuildTx(void *addr, kal_uint32 len);

extern void USB_Ms_If_Create(void *ifname);
extern void USB_Ms_If_Reset(void);
extern void USB_Ms_If_Resume(void);

extern void USB_Ms_If_Enable(void);
extern void USB_Ms_If_Speed_Reset(kal_bool b_other_speed);

extern void USB_Init_Ms_Status(void);
extern void USB_Release_Ms_Status(void);

#endif /* USBMS_DRV_H */

