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
 *    usbacm_drv.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file intends for usb CDC ACM class driver definitions
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef USBACM_DRV_H
#define USBACM_DRV_H

//#include "kal_non_specific_general_types.h"
#include "usb.h"
#include "dcl.h"
#include "usb_comm.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
//#include "uart_sw.h"
#include "bmd.h"
#include "usb_custom.h"
#include "usb_custom_def.h"

/***********************************************
	acm class specific command definition
************************************************/

#define USB_ACM_DEVICE_CODE			0x02
#define USB_ACM_SUBCLASS_CODE			0x00
#define USB_ACM_PROTOCOL_CODE			0x00

#define USB_ACM_COMM_INTERFACE_CLASS_CODE 	0x02
#define USB_ACM_COMM_INTERFACE_SUBCLASS_CODE 	0x02
#define USB_ACM_COMM_INTERFACE_PROTOCOL_CODE 	0x01

#define USB_ACM_DATA_INTERFACE_CLASS_CODE 	0x0a
#define USB_ACM_DATA_INTERFACE_SUBCLASS_CODE 	0x00
#define USB_ACM_DATA_INTERFACE_PROTOCOL_CODE 	0x00

#define USB_CDC_IF_LENGTH     			28   /* standard plus class */

/* Class-Specfic Codes ,EP0*/
#define USB_ACM_SEND_ENCAPSULATED_COMMAND	0x00
#define USB_ACM_GET_ENCAPSULATED_RESPONSE	0x01
#define USB_ACM_SET_COMM_FEATURE		0x02
#define USB_ACM_GET_COMM_FEATURE		0x03
#define USB_ACM_CLEAR_COMM_FEATURE		0x04
#define USB_ACM_SET_LINE_CODING			0x20
#define USB_ACM_GET_LINE_CODING			0x21
#define USB_ACM_SET_CONTROL_LINE_STATE		0x22
#define USB_ACM_SEND_BREAK			0x23

/* Class-Specfic Codes ,EP0 - NCM*/
#define USB_NCM_SEND_ENCAPSULATED_COMMAND	0x00
#define USB_NCM_GET_ENCAPSULATED_RESPONSE	0x01
#define USB_NCM_GET_NTB_PARAMETERS			0x80
#define USB_NCM_GET_NET_ADDRESS			0x81
#define USB_NCM_SET_NET_ADDRESS			0x82
#define USB_NCM_GET_NTB_INPUT_SIZE			0x85
#define USB_NCM_SET_NTB_INPUT_SIZE			0x86
#define USB_NCM_RESET						0x05


/*Notifications, interrupt pipe*/
#define USB_ACM_NOTIF_NETWORK_CONNECTION	0x00
#define USB_ACM_NOTIF_RESPONSE_AVAILABLE	0x01
#define USB_ACM_NOTIF_SERIAL_STATE		0x20

/* UART state bitmap values */
#define SERIAL_STATE_BRXCARRIER			0x01


/*USB_ACM_SET_CONTROL_LINE_STATE*/    /*  not use anywhere  */
#define CONTROL_LINE_SIGNAL_RTS			0x02  /*DCE's RTS,DTE's CTS*/
#define CONTROL_LINE_SIGNAL_DTR			0x01  /*DCE's DTR,DTE's DSR*/


// RNDIS Spec  //
#define USB_ISD_DEVICE_CODE			0xE0 //0x02	//0xE0
#define USB_ISD_SUBCLASS_CODE		0x01 //0x00	//0x01
#define USB_ISD_PROTOCOL_CODE		0x03 //0x00	//0x03

#define USB_ISD_COMM_INTERFACE_CLASS_CODE 		0xE0 //0x02 	//0xE0
#define USB_ISD_COMM_INTERFACE_SUBCLASS_CODE 	0x01 //0x02 	//0x01
#define USB_ISD_COMM_INTERFACE_PROTOCOL_CODE 	0x03 //0xff 	//0x03

#define USB_ISD_DATA_INTERFACE_CLASS_CODE 	0x0A
#define USB_ISD_DATA_INTERFACE_SUBCLASS_CODE 	0x00
#define USB_ISD_DATA_INTERFACE_PROTOCOL_CODE 	0x00

#define USB_RNDIS_RESPONSE_AVAILABL			0x01

#define RNDIS_RX_BUFFER_NUM  				USB_ACM_RX_BUFFER_NUM   // UPS : put 8 buffer
#ifdef __MBIM_SUPPORT__
#define RNDIS_RX_FLC_BUFFER_NUM  			16 // UPS : use 16 buffer in MBIM
#else
#define RNDIS_RX_FLC_BUFFER_NUM  			3 // UPS : use 3 buffer 
#endif
#define RNDIS_MAX_FRAME			1560

#define USB_RNDIS_RX_LOOP_COUNT  			16



//MBIM
#define USB_MBIM_IF_LENGTH     			31   /* standard plus class */

#define USB_MBIM_DEVICE_CODE		0xEF
#define USB_MBIM_SUBCLASS_CODE		0x02
#define USB_MBIM_PROTOCOL_CODE		0x01
#define USB_MBIM_DESCRIPTOR_CODE	0x1B	//MBIM functional descriptor


#define USB_MBIM_COMM_INTERFACE_CLASS_CODE		0x02
#define USB_MBIM_COMM_INTERFACE_SUBCLASS_CODE	0x0E
#define USB_MBIM_COMM_INTERFACE_PROTOCOL_CODE	0x00

#define USB_MBIM_DATA_INTERFACE_CLASS_CODE		0x0A
#define USB_MBIM_DATA_INTERFACE_SUBCLASS_CODE	0x00
#define USB_MBIM_DATA_INTERFACE_PROTOCOL_CODE	0x02

// MBIM Functional Descriptor
#define MBIM_MAX_CONTROL_MESSAGE        512
#define MBIM_NUMBER_FILTERS             16
#define MBIM_MAX_FILTER_SIZE            64
#define MBIM_MAX_SEGMENT_SIZE           2048



/***********************************************
	Implement definition
************************************************/

#define USB_CDC_ACM_IF_NUMBER      				2

#define USB_CDC_ACM_COMM_EP_NUMBER     		1  /*interrupt pipe*/
#define USB_CDC_ACM_DATA_EP_NUMBER     		2

#define USBACM_RING_BUFFER_TIMEOUT			25

#define USBACM_HIGH_SPEED_LOOP				100
#define USBACM_DIRECT_PATH_LOOP				500


#define USB_ACM_RX_HDLR_PACKET_NUM  			16


/***********************************************
	UART SW Implement definition
************************************************/
#define  UART_STAT_EscDet        0x01
#define  UART_STAT_Break         0x02

#define  UART_RecNormal          0
#define  UART_Get3EscChar        1
#define  UART_StartCheckESC      2

typedef void (*UART_TX_FUNC)(UART_PORT port); 
typedef void (*UART_RX_FUNC)(UART_PORT port) ; 

/***********************************************
	acm class specific descriptor structure
************************************************/

/* CDC ACM communication interface descriptor element */
typedef struct 
{
	kal_uint8    bLength;
	kal_uint8    bDescriptorType;
	kal_uint8    bInterfaceNumber;
	kal_uint8    bAlternateSetting;
	kal_uint8    bNumEndpoints;
	kal_uint8    bInterfaceClass;
	kal_uint8    bInterfaceSubClass;
	kal_uint8    bInterfaceProtocol;
	kal_uint8    iInterface;

	kal_uint8    HFbFunctionLength;		/*Header Functional Descriptor*/
	kal_uint8    HFbDescriptorType;
	kal_uint8    HFbDescriptorSubtype;
	kal_uint16   bcdCDC;

	kal_uint8    ACMFbFunctionLength;	/*Abstract Control Management Functional Descriptor*/
	kal_uint8    ACMFbDescriptorType;
	kal_uint8    ACMFbDescriptorSubtype;
	kal_uint8    ACMFbmCapabilities;

	kal_uint8    UFbFunctionLength;		/*Union Functional Descriptor*/
	kal_uint8    UFbDescriptorType;
	kal_uint8    UFbDescriptorSubtype;
	kal_uint8    bMasterInterface;
	kal_uint8    bSlaveInterface0;

	kal_uint8    CMFbFunctionLength;	/*Call Management Descriptor*/
	kal_uint8    CMFbDescriptorType;
	kal_uint8    CMFbDescriptorSubtype;
	kal_uint8    CMFbmCapabilities;
	kal_uint8    bDataInterface;
} Usb_Cdc_If_Dscr;


typedef struct 
{
	kal_uint8    bLength;
	kal_uint8    bDescriptorType;
	kal_uint8    bInterfaceNumber;
	kal_uint8    bAlternateSetting;
	kal_uint8    bNumEndpoints;
	kal_uint8    bInterfaceClass;
	kal_uint8    bInterfaceSubClass;
	kal_uint8    bInterfaceProtocol;
	kal_uint8    iInterface;

	kal_uint8    HFbFunctionLength;		/*Header Functional Descriptor*/
	kal_uint8    HFbDescriptorType;
	kal_uint8    HFbDescriptorSubtype;
	kal_uint16   bcdCDC;

	kal_uint8    UFbFunctionLength;		/*Union Functional Descriptor*/
	kal_uint8    UFbDescriptorType;
	kal_uint8    UFbDescriptorSubtype;
	kal_uint8    bMasterInterface;
	kal_uint8    bSlaveInterface0;
	
	kal_uint8    MBIMbFunctionLength;	/*MBIM Functional Descriptor*/
	kal_uint8    MBIMbDescriptorType;
	kal_uint8    MBIMbDescriptorSubtype;
	kal_uint16   MBIMbcdMBIMVersion;
	kal_uint16   MBIMwMaxControlMessage;
	kal_uint8    MBIMbNumberFiliters;
	kal_uint8    MBIMbMaxFiliterSize;
	kal_uint16   MBIMwMaxSegmentSize;
	kal_uint8    MBIMbmNetworkCapabilities;
} Usb_MBIM_If_Dscr;


/*  ACM line coding element */
typedef struct
{
	kal_uint32  dwDTERate;
	kal_uint8   bCharFormat;
	kal_uint8   bParityType;
	kal_uint8   bDataBits;
} UsbAcm_Line_Coding;


/* ACM interrupt packet structure */
typedef struct
{
	kal_uint8		bmRequestType;
	kal_uint8		bRequest;
	kal_uint16	wValue;
	kal_uint16	wIndex;
	kal_uint16	wLength;
	kal_uint16	Data;
}UsbAcm_Intr_Pkt;


/***********************************************
	implement enum and structure 
************************************************/

/* transmit buffer type */
typedef enum 
{
	USBTRX_MEM_UNKOWN = 0,
	USBTRX_MEM_ISR,
	USBTRX_MEM_TASK,
	USBTRX_MEM_MAX_TYPE
} USBTRX_MEM_TYPE;

typedef enum 
{
	ACM_INTR_IDLE = 0,
	ACM_INTR_SEND_ONE_PKT,
	ACM_INTR_SEND_LAST_PKT
}USB_ACM_INTR_PIPE_STATE;


/* Current ACM driver owner application */
typedef enum
{
	USB_ACM_OWNER_UART = 0,
	USB_ACM_OWNER_FT
//	USB_ACM_OWNER_LOGGING
}USB_ACM_OWNER_TYPE;



typedef enum 
{
	CDC_NORMAL = 0,  	    //  old transfer type, save data in ring buffer, and copy data to buffer by single interrupt    ex:USB2UART_GetBytes
	CDC_HIGH_SPEED,   	//  Only get data   ( there might be no FLC buffer anymore)
	CDC_HIGH_SPEED_FRAME,   	    //  use transfer as unit
	CDC_HIGH_SPEED_FRAME_DMAQ   	    //  use transfer as unit with DMAQ
}USB_Transfer_type;

/**
 * TGPD
 */
typedef struct _TGPD
{
	kal_uint8 flag;
    kal_uint8  chksum;
    kal_uint16  DataBufferLen; /*Rx Allow Length*/
    struct _TGPD* pNext;
    kal_uint8* pBuf;
    kal_uint16 bufLen;
    kal_uint8 ExtLength;
    kal_uint8 ZTepFlag;
}TGPD, *PGPD;

#define RXGPD_FLAGS_HWO           0x01
#define RXGPD_FLAGS_BDP       		 0x02
#define RXGPD_ENDPOINT          	0x0F
#define RXGPD_TGL          			0x10
#define RXGPD_ZLP          			0x20
#define RXGPD_FLAGS_IOC           0x80


#define TXGPD_FLAGS_HWO              0x01
#define TXGPD_FORMAT_BDP             0x02
#define TXGPD_FORMAT_TGL             0x10
#define TXGPD_FORMAT_ZLP             0x20
#define TXGPD_FLAG_IOC				0x40


typedef void (*usb_acm_rx_ptr)(void);

/* ACM device structure */
typedef struct
{
	kal_uint8		data_interface_id;	
	kal_bool 		send_Txilm;
	kal_bool 		send_Rxilm;
	kal_bool		send_UARTilm;
	kal_bool		config_send_Txilm;
	kal_bool		ring_buffer_timer_counting;		/* flag to check ring buffer timer running or not */
	kal_bool		threshold_enable;				/* enable ring buffer threshold and time out mechanism */
	kal_bool		setup_dma;						/* a flag to record DMA is triggered or not */
	kal_bool		is_intr_pending_pkt;				/* interrupt pipe has pending packet */
	kal_bool 		dma_txcb_just_done;			/*DMA TX Callback Function just done. It's clear by putbyte funtion*/
	kal_bool 		break_detect;
	kal_bool		put_start;
	kal_uint16      dmaf_setmember;	  /* Who set dma_false after putbyte and it does not finsih*/
	kal_uint16		line_state;
	UsbAcm_Intr_Pkt		intr_pkt;	

	kal_uint32		handle;    		/*GPT handle*/
	kal_uint32		dma_handle;    		/*for DMA timeout handle*/
	kal_uint32		ring_buffer_handle;	/* ring buffer's GPT handle */
	kal_uint32 		break_number;
	UsbAcm_Line_Coding	line_coding;		/* current line coding, just used to reply to host */	

	Usb_EpBIn_Status	*txpipe;		/* bulk in EP, Data interface */
	Usb_EpBOut_Status	*rxpipe;		/* bulk out EP, Data interface */
	Usb_EpBIn_Status	*intrpipe;		/* interrupt EP, Communication Interface */
	
	USB_ACM_INTR_PIPE_STATE	intr_state;				/* interrupt pipe state machine */
	Usb_Ep_Info			*comm_ep_intr_info;
	Usb_Ep_Info			*data_ep_in_info;
	Usb_Ep_Info			*data_ep_out_info;
	Usb_Interface_Info	*comm_if_info;
	Usb_Interface_Info	*data_if_info;
#ifdef  __MBIM_SUPPORT__
	Usb_Alternate_Interface_Info *mbim_if_alter_info;
#endif

	USB_Transfer_type	transfer_type;
	
#if defined(__USB_COMPOSITE_DEVICE_SUPPORT__)
		Usb_IAD_Dscr		*iad_desc;
#endif
	
#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
	kal_uint32	data_addr;
	kal_uint32	rx_buf_data_len[USB_ACM_RX_BUFFER_NUM];
	kal_uint16	tx_count;  		/* To store the TX count, debug only*/
	kal_bool		b_data_left; // left data due to 512N
	kal_bool		b_is_high_speed_enable;
	kal_bool		b_rc_index_move;
	kal_uint16		b_rc_get_count;	
	kal_uint8		rx_buf_rc_index;  /* read clear pointer */
	kal_uint8		rx_buf_r_index;  /* read pointer */
	kal_uint8		rx_buf_w_index;  /* write pointer */
	kal_uint8		rx_buf_count;  /* the buffer count with data */
#ifdef DRV_USB_DMA_QUEUE_SUPPORT
	kal_bool	ppp_txdmaq_first;
	kal_uint32	ppp_rdmaq_idx;
	kal_uint32	ppp_tdmaq_idx;
#endif
//#endif

//#ifdef __USB_TETHERING__
	kal_uint8 		*rx_buf_addr[RNDIS_RX_BUFFER_NUM+1];	//9 : 0 ~ 8
	kal_uint32		isd_rx_buf_data_len[RNDIS_RX_BUFFER_NUM+1];
	kal_uint8 		*rx_flc_buf_addr[RNDIS_RX_FLC_BUFFER_NUM+1];	 //3 //3:  0~2
	kal_uint32		rx_flc_buf_data_len[RNDIS_RX_FLC_BUFFER_NUM+1];
	kal_uint16		tx_flc_count;  		/* To store the TX count, debug only*/
	kal_uint8		*tx_flc_data_addr;
	kal_bool		rx_full_data;
	kal_bool		halt_flag;
	kal_bool		ctrl_data_done;
	kal_bool		send_ctrl_Txilm;  // Ctrl pipe --> TX message
	kal_bool		send_ctrl_Rxilm;  // ctrl pipe --> RX message
	
//	kal_bool		dma_rx_running;  //use  FIFO Read first 
//	kal_bool		dma_tx_running; //the dame as setup_dma

	kal_uint8		rx_full_buff_index;  // receive Data 
	kal_uint8		rx_empty_buff_index; // empty buffer
	kal_uint8		rx_flc_full_buff_index;  // receive Data 
	kal_uint8		rx_flc_empty_buff_index; // empty buffer 
//	kal_bool		b_flc_rc_index_move;
	kal_uint8		rx_flc_buf_rc_index;  /* read clear pointer */
	kal_uint8		rx_flc_buf_r_index;  /* read pointer */
	kal_uint8		rx_flc_buf_w_index;  /* write pointer: data write (bulk out handler) */
	kal_uint8		rx_flc_buf_count;  /* the buffer count with data */
	kal_uint8		rx_flc_temp_length;  /* for first time PC send data just before buffer push  (initial message) */
	kal_bool		rx_flc_temp;  /* for first time PC send data just before buffer push (initial message) */	
	kal_uint8		*rx_flc_temp_buf_addr;
#endif

#ifdef __USB_SW_DMA_DIV__
	kal_uint8 		*tx_temp_buf_addr;
#endif
	kal_bool		b_is_tx_direct_path_enable;

}UsbAcm_Struct;



typedef struct
{
	/* FT mode param */
	USB_ACM_OWNER_TYPE	acm_owner;
#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__	
	kal_uint8 		*rx_buf_addr[RNDIS_RX_BUFFER_NUM+1];	//9 : 0 ~ 8
#endif
	kal_uint8                ft_port_num;

#ifdef __USB_HS_ENABLE__
	kal_uint8			ft_data[USB_EP_BULK_MAXP_HS];
#else
	kal_uint8			ft_data[USB_EP_BULK_MAXP];
#endif

	kal_uint16			ft_data_len;
	usb_acm_rx_ptr		ft_rx_cb;

	/* Customizable variables */
	const USB_ACM_PARAM	*acm_param;
}UsbAcm_Common_Struct;


typedef struct
{
      UART_PORT                      port_no;
      kal_bool                       initialized;
      kal_bool                       power_on;
      module_type                    ownerid;
      module_type                    UART_id;
      kal_bool                       breakDet;
      kal_bool                       EscFound;
      IO_level                       DSR;  

      kal_uint8                      EscCount;
      kal_uint8                      Rec_state; /**/

   /*detect Escape*/
      kal_uint32                      handle;    /*GPT handle*/
      UARTDCBStruct                  DCB;

      UART_ESCDetectStruct           ESCDet;
      UART_RingBufferStruct          RingBuffers;      
      BUFFER_INFO                    Rx_Buffer;  /* receive buffer */
      BUFFER_INFO                    Tx_Buffer;  /* transmit buffer */
      BUFFER_INFO                    Tx_Buffer_ISR; /* receive buffer */

      UART_TX_FUNC                  tx_cb;
      UART_RX_FUNC                  rx_cb;


//      kal_hisrid                     hisr;
//#ifdef __DMA_UART_VIRTUAL_FIFO__
//	kal_uint8 							Rx_DMA_Ch;
//	kal_uint8 							Tx_DMA_Ch;
//#endif
//#ifdef DCM_ENABLE
// UART_BAUD_AUTO conflict with rate fix, need to disable DCM
//      kal_uint32                      DCMHandle; 
//      kal_bool                       AutobaudDetection;
//#endif
//#if defined(DRV_UART_COMPENSATE_AT)
//      UART_Compensate_enum           CompensateAT;
//#endif	  
//      UART_SLEEP_ON_TX               sleep_on_tx;
//      kal_bool               		EnableTX;

} UsbUARTStruct;


/***********************************************
	function and global variable
************************************************/
extern UsbUARTStruct USB2UARTPort[MAX_USB_PORT_NUM];
extern UsbAcm_Struct g_UsbACM[MAX_USB_PORT_NUM];
extern UsbAcm_Common_Struct g_UsbACM_Comm;
extern kal_uint8 USB_PORT[uart_max_port];
extern kal_bool USB_IS_LOGGING_PORT[uart_max_port];

extern void usb_drv_trace4(module_type ownerid, kal_uint32 msg_index,const char *arg_type, kal_uint32 data1, kal_uint32 data2,kal_uint32 data3, kal_uint32 data4);
extern void usb_drv_trace2(module_type ownerid, kal_uint32 msg_index,const char *arg_type, kal_uint32 data1, kal_uint32 data2);
extern void usb_drv_trace1(module_type ownerid, kal_uint32 msg_index,const char *arg_type, kal_uint32 data1);
extern void usb_drv_trace0(module_type ownerid, kal_uint32 msg_index,const char *arg_type);
extern void USB_Acm_Exception_Check(void);

extern void USB_Check_Owner(module_type ownerid,module_type current_ownerid);

extern void USB_UnMask_COM_Intr(UART_PORT port);
extern void USB_Mask_COM_Intr(UART_PORT port);

extern void UART2USB_DCB2LineCoding(UARTDCBStruct *pDCB, UsbAcm_Line_Coding *pline_coding);

extern void USB2UART_Timeout(void *parameter);

extern void USB2UART_Dafault_Tx_Callback(UART_PORT port);
extern void USB2UART_Dafault_Rx_Callback(UART_PORT port);
extern void USB_Acm_Ring_Buffer_Threshold_Enable(UART_PORT port, kal_bool bset, module_type ownerid);

extern void USB2UART_Polling_Flush_Transmit_Data(UART_PORT port);
extern void USB2UART_Polling_Recv_Data(UART_PORT port);

#if defined(__USB_LIMIT__)
extern void USB2UART_Set_DMA_Limiter(kal_uint32 dma_limit_num);
extern void USB2UART_Clear_DMA_Limiter(void);
#endif

extern void USB2UART_DMATransmit(UART_PORT port, kal_bool b_force_isr_buffer);
extern void USB2UART_Tx_DMA1_Callback(void);

extern void USB_Acm_Rx_ClrFifo(UART_PORT port);
extern void USB_Acm1_CommIf_Create(void *ifname);
extern void USB_Acm1_CommIf_Reset(void);
extern void USB_Acm1_CommIf_Enable(void);
extern void USB_Acm1_CommIf_Speed_Reset(kal_bool b_other_speed);
extern void USB_Acm1_DataIf_Create(void *ifname);
extern void USB_Acm1_DataIf_Reset(void);
extern void USB_Acm1_DataIf_Enable(void);
extern void USB_Acm1_DataIf_Speed_Reset(kal_bool b_other_speed);

extern void USB_Acm_VendorIf_Create(void *ifname);
extern void USB_Acm_VendorIf_Reset(void);
extern void USB_Acm_VendorIf_Enable(void);
extern void USB_Acm_VendorIf_Speed_Reset(kal_bool b_other_speed);


#ifdef __USB_TETHERING__
extern void USB_ISD_CommIf_Create(void *ifname);
extern void USB_ISD_CommIf_Reset(void);
extern void USB_ISD_CommIf_Enable(void);
extern void USB_ISD_CommIf_Speed_Reset(kal_bool b_other_speed);
extern void USB_ISD_DataIf_Create(void *ifname);
extern void USB_ISD_DataIf_Reset(void);
extern void USB_ISD_DataIf_Enable(void);
extern void USB_ISD_DataIf_Speed_Reset(kal_bool b_other_speed);
extern void USB_ISD_Stop_Transfer(void);
#endif


extern void USB_Init_Acm_Status(void);
extern void USB_Release_Acm_Status(void);

extern void USB2UART_Tx_DMA2_Callback(void);
extern void USB_Acm2_CommIf_Create(void *ifname);
extern void USB_Acm2_CommIf_Reset(void);
extern void USB_Acm2_CommIf_Enable(void);
extern void USB_Acm2_CommIf_Speed_Reset(kal_bool b_other_speed);
extern void USB_Acm2_DataIf_Create(void *ifname);
extern void USB_Acm2_DataIf_Reset(void);
extern void USB_Acm2_DataIf_Enable(void);
extern void USB_Acm2_DataIf_Speed_Reset(kal_bool b_other_speed);

#if defined (__USB_MODEM_CARD_SUPPORT__)
extern void USB_Acm_DataCommIf_Create(void *ifname);
extern void USB_Acm_DataCommIf_Reset(void);
extern void USB_Acm_DataCommIf_Enable(void);
extern void USB_Acm_DataCommIf_Speed_Reset(kal_bool b_other_speed);
extern void USB_Acm2_DataCommIf_Create(void *ifname);
extern void USB_Acm2_DataCommIf_Reset(void);
extern void USB_Acm2_DataCommIf_Enable(void);
extern void USB_Acm2_DataCommIf_Speed_Reset(kal_bool b_other_speed);
extern void USB2UART_Tx_DMA3_Callback(void);
extern void USB_Acm3_DataIf_Create(void *ifname);
extern void USB_Acm3_DataIf_Reset(void);
extern void USB_Acm3_DataIf_Enable(void);
extern void USB_Acm3_DataIf_Speed_Reset(kal_bool b_other_speed);
extern void USB2UART_Tx_DMA4_Callback(void);
extern void USB_Acm4_DataIf_Create(void *ifname);
extern void USB_Acm4_DataIf_Reset(void);
extern void USB_Acm4_DataIf_Enable(void);
extern void USB_Acm4_DataIf_Speed_Reset(kal_bool b_other_speed);
extern void USB2UART_Tx_DMA5_Callback(void);
extern void USB_Acm5_DataIf_Create(void *ifname);
extern void USB_Acm5_DataIf_Reset(void);
extern void USB_Acm5_DataIf_Enable(void);
extern void USB_Acm5_DataIf_Speed_Reset(kal_bool b_other_speed);
#endif

extern void USB_Acm_FT_Register_Rx_Cb(usb_acm_rx_ptr cb);

#if defined (DRV_USB_DMA_QUEUE_SUPPORT)
extern void USB_DMAQ_Setup(kal_uint32 ep_num, USB_EP_DIRECTION direction, kal_bool first, kal_uint32 addr, usb_dmaq_callback callback, usb_dmaq_callback empty_callback);
extern void USB_DMAQ_Stop(kal_uint32 ep_num, USB_EP_DIRECTION direction);
extern void USB_TxEP_DMAQ_En(kal_uint8 epno, kal_bool bQMU);
extern void USB_RxEP_DMAQ_En(kal_uint8 epno, kal_bool bQMU);

extern void USB2UART_PPPRX_DMAQ_Callback(kal_uint32 usb_port);
extern void USB2UART_PPPTX_DMAQ_Callback(kal_uint32 usb_port);
#endif

#ifdef __MBIM_SUPPORT__
extern void USB2UART_MBIMRX_DMAQ_Callback(kal_uint32 usb_port);
extern void USB2UART_MBIMTX_DMAQ_Callback(kal_uint32 usb_port);
extern void USB2UART_MBIMRX_DMAQ_Empty_Callback(kal_uint32 usb_port);
extern void USB2UART_MBIMTX_DMAQ_Empty_Callback(kal_uint32 usb_port);
extern void USB_MBIM_CommIf_Create(void *ifname);
extern void USB_MBIM_CommIf_Reset(void);
extern void USB_MBIM_CommIf_Enable(void);
extern void USB_MBIM_CommIf_Speed_Reset(kal_bool b_other_speed);
extern void USB_MBIM_DataIf_Create(void *ifname);
extern void USB_MBIM_DataIf_Reset(void);
extern void USB_MBIM_DataIf_Enable(void);
extern void USB_MBIM_DataIf_Speed_Reset(kal_bool b_other_speed);
extern void USB_MBIM_Stop_Transfer(void);
#endif
#endif /* USBACM_DRV_H */

