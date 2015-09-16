/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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

/*******************************************************************************
 * Filename:
 * ---------
 *   brom_acm_drv.h
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *	This is the USB3.0 ACM driver header file
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 ****************************************************************************/
#ifndef __BROM_ACM_DRV_H__
#define __ROM_ACM_DRV_H__

#include "brom_u3mac_reg.h"
#include "string.h"


#define USB30_MAX_POWER_MA		900
#define USB20_MAX_POWER_MA		500
#define USB30_POWER_DESC_UINT	8 // 1unit = 8mA
#define USB20_POWER_DESC_UINT	2 // 1unit = 2mA


#define U3_USB20_MULTI_FIFO_CNT	4
#define U3_USB30_MULTI_FIFO_CNT	2
#define U3_USB30_MAX_BURST		U3_USB30_MULTI_FIFO_CNT

/*!
 *	@brief	USB3.0 BOS descriptor related definition
*/
#define USBC_BOS_DESC_TYPE				0x0F
#define USBC_DEV_CAP_DESC_TYPE			0x10
#define USBC_USB2_EXT_DEV_CAP_TYPE		0x02
#define USBC_SS_DEV_CAP_TYPE			0x03

/*!
 *  @brief hifusb_request_owner_e enumerate all possible types of usb control
 *         request type
 *  @param HIFUSB_CONTROL_REQUEST_TYPE_MIN        	pseudo type
	@param HIFUSB_CONTROL_REQUEST_TYPE_NODATA		request no data
 *  @param HIFUSB_CONTROL_REQUEST_TYPE_SEND       	request to send, Device->Host
 *  @param HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE    	request to receive, Host->Device
 *  @param HIFUSB_CONTROL_REQUEST_TYPE_STALL      	request to stall
 *  @param HIFUSB_CONTROL_REQUEST_TYPE_MAX        	pseudo type
 */
typedef enum _hifusb_control_request_type {
    HIFUSB_CONTROL_REQUEST_TYPE_MIN       	= 0,
    HIFUSB_CONTROL_REQUEST_TYPE_SEND      	= 1,
    HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE   	= 2,
    HIFUSB_CONTROL_REQUEST_TYPE_STALL     	= 3,
    HIFUSB_CONTROL_REQUEST_TYPE_MAX       	= 4,
} hifusb_control_request_type_e;


/*!
 *  @brief hifusb_state_e enumerate possible states of usb device
 *  @param HIFUSB_STATE_MIN				pseudo state
 *  @param HIFUSB_STATE_PWROFF			USB initial state , before VBUS valid
 *  @param HIFUSB_STATE_PWRON			after VBUS valid , before attach
 *  @param HIFUSB_STATE_ATTACHED     	after attach, before USB reset
 *  @param HIFUSB_STATE_DEFAULT      	after USB reset , this is the default normal state
 *  @param HIFUSB_STATE_ADDR      		after USB reset and set address 
 *  @param HIFUSB_STATE_CONFIG      	after set address and set configure
 *  @param HIFUSB_STATE_SUSPENDED     	after default state and stay in suspend
 *  @param HIFUSB_STATE_RESUME      	when receive resume, return to default immediately
 *  @param HIFUSB_STATE_MAX    			psuduo state
 */
typedef enum _hifusb_state {
    HIFUSB_STATE_MIN		 = 0,
    HIFUSB_STATE_PWROFF,
    HIFUSB_STATE_PWRON,
    HIFUSB_STATE_ATTACHED,
    HIFUSB_STATE_DEFAULT,
    HIFUSB_STATE_ADDR,
    HIFUSB_STATE_CONFIG,
    HIFUSB_STATE_SUSPENDED,
    HIFUSB_STATE_RESUME,
    HIFUSB_STATE_LPM_SUSPEND,    
    HIFUSB_STATE_MAX,
} hifusb_state_e;

/*!
 *  @brief hifusb_hw_info_t is used to record the USB IP information
 */
typedef enum _hifusb_ep0_state {
	HIFUSB_EP0_ST_IDLE,				/*idle, wait for SETUP*/
	HIFUSB_EP0_ST_SETUP,			/*received SETUP 8 bytes*/
	HIFUSB_EP0_ST_DATAIN,			/*data stage for IN data*/
	HIFUSB_EP0_ST_DATAOUT,			/*data stage for OUT data*/
	HIFUSB_EP0_ST_STATUSIN,			/*status stage after OUT data*/
	HIFUSB_EP0_ST_STATUSOUT,		/*status stage after IN data*/
	HIFUSB_EP0_ST_ACKWAIT,			/*status stage after zlp and before Status IN*/
	HIFUSB_EP0_ST_STALL,			/*stall state to trigger send stall and then go back IDLE*/
} hifusb_ep0_state_e;


/*!
 *  @brief hifusb_test_mode , the test mode which host expect, 
 *			the number sync the USB2.0 Test Mode Selector
 *			The test mode only used in USB2.0 transfer
 */
typedef enum _hifusb_test_mode {
	HIFUSB_HSET_NONE = 0,
	HIFUSB_HSET_TEST_J,
	HIFUSB_HSET_TEST_K,
	HIFUSB_HSET_TEST_SE0_NAK,
	HIFUSB_HSET_TEST_PACKET,
}hifusb_test_mode_e;


/*!
 *  @brief hifusb_usb_speed_e enumerate possible speed of usb device
 *  @param HIFUSB_USB_SPEED_MIN           pseudo speed
 *  @param HIFUSB_USB_SPEED_USB11         usb 1.1 full speed
 *  @param HIFUSB_USB_SPEED_USB20         usb 2.0 high speed
 *  @param HIFUSB_USB_SPEED_USB30         usb 3.0 super speed
 *  @param HIFUSB_USB_SPEED_MAX           pseudo speed
 */
typedef enum hifusb_usb_speed {
    HIFUSB_USB_SPEED_MIN                  = 0,
    HIFUSB_USB_SPEED_USB11                = 1,
    HIFUSB_USB_SPEED_USB20                = 2,
    HIFUSB_USB_SPEED_USB30                = 3,
    HIFUSB_USB_SPEED_MAX                  = 4,
} hifusb_usb_speed_e;


/*!
 *  @brief hifusb_usb_xfer_type enumerate all possible types of  USB
 *         transfer type
 *  @param HIFUSB_EP_XFER_TYPE_MIN          pseudo type
 *  @param HIFUSB_EP_XFER_TYPE_CONTROL      Control Transfer
 *  @param HIFUSB_EP_XFER_TYPE_ISOC      	Isochronous Transfer
 *  @param HIFUSB_EP_XFER_TYPE_BULK     	Bulk Transfer
 *  @param HIFUSB_EP_XFER_TYPE_INT     		Interrupt Out Transfer
 *  @param HIFUSB_EP_XFER_TYPE_MAX          pseudo type
 */
typedef enum _hifusb_usb_xfer_type {
	HIFUSB_EP_XFER_TYPE_MIN = 0,
	HIFUSB_EP_XFER_TYPE_CONTROL,
	HIFUSB_EP_XFER_TYPE_ISOC,
	HIFUSB_EP_XFER_TYPE_BULK,
	HIFUSB_EP_XFER_TYPE_INT,
	HIFUSB_EP_XFER_TYPE_MAX
}hifusb_usb_xfer_type_e;


/*!
 *  @brief hifusb_setup_packet_t describe the detail field definition of
 *         control setup packet
 */
typedef struct _hifusb_setup_packet {
    /*!
     *  @brief request type of setup packet
     *         Bit 7: Request direction
     *                (0=Host to device - Out, 1=Device to host - In)
     *         Bits 5-6: Request type
     *                (0=standard, 1=class, 2=vendor, 3=reserved)
     *         Bits 0-4: Recipient
     *                (0=device, 1=interface, 2=endpoint,3=other)
     */
    kal_uint8           bmRequestType;
    /*!
     *  @brief the actual request, see the Standard Device Request Codes table
     */
    kal_uint8           bRequest;
    /*!
     *  @brief a word-size value that varies according to the request
     */
    kal_uint16          wValue;
    /*!
     *  @brief a word-size value that varies according to the request,
     *         the index is generally used to specify an endpoint or
     *         an interface.
     */
    kal_uint16          wIndex;
    /*!
     *  @brief a word-size value that indicates the number of bytes to be
     *         transferred if there is a data stage
     */
    kal_uint16          wLength;
} hifusb_setup_packet_t;

/*
 *	USB EP0 request command related
*/
/*!
 * @brief USB Standard Requests
 */
#define USBC_REQ_GET_STATUS                 0x00
#define USBC_REQ_CLEAR_FEATURE              0x01
#define USBC_REQ_SET_FEATURE                0x03
#define USBC_REQ_SET_ADDRESS                0x05
#define USBC_REQ_GET_DESCRIPTOR             0x06
#define USBC_REQ_SET_DESCRIPTOR             0x07
#define USBC_REQ_GET_CONFIGURATION          0x08
#define USBC_REQ_SET_CONFIGURATION          0x09
#define USBC_REQ_GET_INTERFACE              0x0A
#define USBC_REQ_SET_INTERFACE              0x0B
#define USBC_REQ_SYNCH_FRAME                0x0C
#define USBC_REQ_SET_SEL					0x30
#define USBC_REQ_SET_ISOCH_DELAY			0x31

/*!
 * @brief USB Request Types
 */
#define USBC_REQUEST_TYPE_MASK              (0x03 << 5)
#define USBC_REQUEST_TYPE_STANDARD          (0x00 << 5)
#define USBC_REQUEST_TYPE_CLASS             (0x01 << 5)
#define USBC_REQUEST_TYPE_VENDOR            (0x02 << 5)
#define USBC_REQUEST_TYPE_RESERVED          (0x03 << 5)


/*!
 * @brief USB Request Recipients
 */
#define USBC_REQUEST_RECIP_MASK             0x1f
#define USBC_REQUEST_RECIP_DEVICE           0x00
#define USBC_REQUEST_RECIP_INTERFACE        0x01
#define USBC_REQUEST_RECIP_ENDPOINT         0x02
#define USBC_REQUEST_RECIP_OTHER            0x03


/*!
 * @breif USB Request Directions
 */
#define USBC_REQUEST_DIR_OUT                0
#define USBC_REQUEST_DIR_IN                 0x80

/*!
 * @brief USB Set Features
 */
#define USBC_FEATURE_ENDPOINT_HALT          0x00
#define USBC_FEATURE_IF_FUNC_SUS			0x00
#define USBC_FEATURE_DEVICE_REMOTE_WAKEUP   0x01
#define USBC_FEATURE_TEST_MODE              0x02
#define USBC_FEATURE_DEV_U1_EN				0x30
#define USBC_FEATURE_DEV_U2_EN				0x31
#define USBC_FEATURE_DEV_LTM_EN				0x32
#define USBC_FEATURE_DEV_B3_NTF_HST_REL		0x33 //USB3.0 OTG reserved


/*!
 *  @brief Device Descriptor Types
 */
#define USBC_DT_DEVICE                      0x01
#define USBC_DT_CONFIG                      0x02
#define USBC_DT_STRING                      0x03
#define USBC_DT_INTERFACE                   0x04
#define USBC_DT_ENDPOINT                    0x05
#define USBC_DT_DEVICE_QUALIFIER            0x06
#define USBC_DT_OTHER_SPEED                 0X07
#define USBC_DT_INTERFACE_POWER             0x08
#define USBC_DT_OTG                         0x09
#define USBC_DT_IAD                         0x0B
#define USBC_DT_BOS							0x0F //USB3.0 only
#define USBC_DT_DEV_CAPABILITY				0x10 //USB3.0 only
#define USBC_DT_SS_EP_COMP					0x30 //USB3.0 only



/*!
 *  @brief Device Status Field
 */
#define USBC_DEV_STATUS_SELF_PWR			(0x1 << 0)
#define USBC_DEV_STATUS_REMOTE_WK			(0x1 << 1)
#define USBC_DEV_STATUS_U1_EN				(0x1 << 2)
#define USBC_DEV_STATUS_U2_EN				(0x1 << 3)
#define USBC_DEV_STATUS_LTM_EN				(0x1 << 4)

/*!
 *  @brief Interface Status Field
 */
#define USBC_IF_STATUS_FUNC_RWE_CAP			(0x1 << 0)
#define USBC_IF_STATUS_FUNC_RWE_EN			(0x1 << 1)

/*!
 *  @brief Endpoint Status Field
 */
#define USBC_EP_STATUS_HALT					(0x1 << 0)


/*!
 * @breif USB Request Directions
 */
#define USBC_EP_ADDR_DIR_IN                 0x80
#define USBC_EP_ADDR_NUM_MASK               0x7F

#define USBC_DEV_ADDR_MASK					0x7F //MAX device address number is 127

/* Generic USB private definition*/
#define HIFUSB_MIN(_n1 , _n2) 	(_n2 < _n1 ? _n2 : _n1)
#define HIFUSB_MAX(_n1 , _n2) 	(_n2 > _n1 ? _n2 : _n1)




#define USB_ACM_IN_EP_NUM		2
#define USB_ACM_OUT_EP_NUM		1


#define USBC_DEF_VID                        0x0E8D
#define USBC_DEF_PID                        0x0003
#define USBC_TOTAL_INTERFACE_NUM            2
#define USBC_INTERFACE_MTK_COM_0            0
#define USBC_INTERFACE_MTK_COM_1            1
#define USBC_ACM_COMM_IN_EP					2
#define USBC_ACM_DATA_IN_EP					1
#define USBC_ACM_DATA_OUT_EP				1
#define USBC_DEV_CONFIG_ACM_VAL				1
#define USBC_DEV_CONFIG_DEF_VAL				0

/*endpoint descriptor bmAttributes definition*/
#define XFER_TYPE_MSK	(0x3)
#define XFER_TYPE_CTRL	(0x0)
#define XFER_TYPE_ISO	(0x1)
#define XFER_TYPE_BULK	(0x2)
#define XFER_TYPE_INTR	(0x3)

/*!
 *  @brief USBC_DEF_BCDDEV defines default bcd device
 */
#define USBC_DEF_BCDDEV                     0x0001


/*!
 *  @brief USBC_DEF_STR_IDX_LANGUAGE defines default language string index
 */
#define USBC_DEF_STR_IDX_LANGUAGE           0x00


/*!
 *  @brief USBC_DEF_IDX_MANUFACTURER defines default manufacturer string index
 */
#define USBC_DEF_STR_IDX_MANUFACTURER       0x01


/*!
 *  @brief USBC_DEF_IDX_PRODUCT defines default product string index
 */
#define USBC_DEF_STR_IDX_PRODUCT            0x02


/*!
 *  @brief USBC_DEF_IDX_SERIALNUM defines default serial number string index
 */
#define USBC_DEF_STR_IDX_SERIALNUM          0x03


/*!
 *  @brief USBC_USB11_MAX_PACKET_SIZE define maximum packet size in USB SPEED 1.1
 */
#define USBC_USB11_MAX_PACKET_SIZE          64


/*!
 *  @brief USBC_USB20_MAX_PACKET_SIZE define maximum packet size in USB SPEED 2.0
 */
#define USBC_USB20_MAX_PACKET_SIZE          512


/*!
 *  @brief USBC_USB30_MAX_PACKET_SIZE define maximum packet size in USB SPEED 3.0
 */
#define USBC_USB30_MAX_PACKET_SIZE          1024




#ifndef __GNUC__
#define __GNUC__
#endif

#if defined(__GNUC__)
#define __RVCT_PACKED__
#define __GCC_PACKED__      __attribute__((packed))
#elif defined(__RVCT__)
#define __RVCT_PACKED__     __packed
#define __GCC_PACKED__
#else
#define __RVCT_PACKED__
#define __GCC_PACKED__
#endif


/*!
 *  @brief usbc_setup_packet_t describe the detail field definition of
 *         control setup packet
 */
typedef __RVCT_PACKED__ struct _usbc_setup_packet {
    /*!
     *  @brief request type of setup packet
     *         Bit 7: Request direction
     *                (0=Host to device - Out, 1=Device to host - In)
     *         Bits 5-6: Request type
     *                (0=standard, 1=class, 2=vendor, 3=reserved)
     *         Bits 0-4: Recipient
     *                (0=device, 1=interface, 2=endpoint,3=other)
     */
    kal_uint8       bmRequestType;
    /*!
     *  @brief the actual request, see the Standard Device Request Codes table
     */
    kal_uint8       bRequest;
    /*!
     *  @brief a word-size value that varies according to the request
     */
    kal_uint16      wValue;
    /*!
     *  @brief a word-size value that varies according to the request,
     *         the index is generally used to specify an endpoint or
     *         an interface.
     */
    kal_uint16      wIndex;
    /*!
     *  @brief a word-size value that indicates the number of bytes to be
     *         transferred if there is a data stage
     */
    kal_uint16      wLength;
}  __GCC_PACKED__ usbc_setup_packet_t;


/*!
 *  @brief Device Descriptor Structure
 */
typedef __RVCT_PACKED__ struct _usbc_device_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint16      bcdUSB;
    kal_uint8       bDeviceClass;
    kal_uint8       bDeviceSubClass;
    kal_uint8       bDeviceProtocol;
    kal_uint8       bMaxPacketSize0;
    kal_uint16      idVendor;
    kal_uint16      idProduct;
    kal_uint16      bcdDevice;
    kal_uint8       iManufacturer;
    kal_uint8       iProduct;
    kal_uint8       iSerialNumber;
    kal_uint8       bNumConfigurations;
} __GCC_PACKED__ usbc_device_descriptor_t;


/*!
 *  @brief Configuration Descriptor Structure
 */
typedef __RVCT_PACKED__ struct _usbc_configuration_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint16      wTotalLength;
    kal_uint8       bNumInterfaces;
    kal_uint8       bConfigurationValue;
    kal_uint8       iConfiguration;
    kal_uint8       bmAttributes;
    kal_uint8       bMaxPower;
} __GCC_PACKED__ usbc_configuration_descriptor_t;


/*!
 *  @brief Interface Descriptor Structure
 */
typedef __RVCT_PACKED__ struct _usbc_interface_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8       bInterfaceNumber;
    kal_uint8       bAlternateSetting;
    kal_uint8       bNumEndpoints;
    kal_uint8       bInterfaceClass;
    kal_uint8       bInterfaceSubClass;
    kal_uint8       bInterfaceProtocol;
    kal_uint8       iInterface;
} __GCC_PACKED__ usbc_interface_descriptor_t;


/*!
 *  @brief Interface Association Descriptor Structure
 */
typedef __RVCT_PACKED__ struct _usbc_interface_association_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8       bFirstInterface;
    kal_uint8       bInterfaceCount;
    kal_uint8       bFunctionClass;
    kal_uint8       bFunctionSubClass;
    kal_uint8       bFunctionProtocol;
    kal_uint8       iFunction;
} __GCC_PACKED__ usbc_interface_association_descriptor_t;


/*!
 *  @brief Endpoint Descriptor Structure
 */
typedef __RVCT_PACKED__ struct _usbc_endpoint_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8       bEndpointAddress;
    kal_uint8       bmAttributes;
    kal_uint16      wMaxPacketSize;
    kal_uint8       bInterval;
} __GCC_PACKED__ usbc_endpoint_descriptor_t;


/*!
 *  @brief String Descriptor Structure
 */
typedef __RVCT_PACKED__ struct _usbc_string_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint16      wData[1];
} __GCC_PACKED__ usbc_string_descriptor_t;


/*!
 *  @brief Qualifier Descriptor Structure
 */
typedef __RVCT_PACKED__ struct _usbc_device_qualifier_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint16      bcdUSB;
    kal_uint8       bDeviceClass;
    kal_uint8       bDeviceSubClass;
    kal_uint8       bDeviceProtocol;
    kal_uint8       bMaxPacketSize0;
    kal_uint8       bNumConfigurations;
    kal_uint8       bRESERVED;
} __GCC_PACKED__ usbc_device_qualifier_descriptor_t;


/*!
 *  @brief CS Header Descriptor Structure
 */
typedef __RVCT_PACKED__ struct _usbc_cs_header_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8       bDescriptorSubType;
    kal_uint16      bcdCDC;
} __GCC_PACKED__ usbc_cs_header_descriptor_t;


/*!
 *  @brief CS Call Manage Descriptor Structure
 */
typedef __RVCT_PACKED__ struct _usbc_cs_call_manager_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8       bDescriptorSubType;
    kal_uint8       bmCapabilities;
    kal_uint8       bDataInterface;
} __GCC_PACKED__ usbc_cs_call_manage_descriptor_t;


/*!
 *  @brief CS Abstract Control Manage Descriptor Structure
 */
typedef __RVCT_PACKED__ struct _usbc_cs_abstract_control_manage_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8       bDescriptorSubType;
    kal_uint8       bmCapabilities;
} __GCC_PACKED__ usbc_cs_abstract_control_manage_descriptor_t;


/*!
 *  @brief CS Union Function Descriptor Structure
 */
typedef __RVCT_PACKED__ struct _usbc_cs_union_function_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8       bDescriptorSubType;
    kal_uint8       bMasterInterface;
    kal_uint8       bSlaveInterface;
} __GCC_PACKED__ usbc_cs_union_function_descriptor_t;


/*!
 *  @brief CS Ethernet Networking Function Descriptor Structure
 */
typedef __RVCT_PACKED__ struct _usbc_cs_ethernet_networking_function_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8       bDescriptorSubType;
    kal_uint8       iMACAddress;
    kal_uint32      bmEthernetStatistics;
    kal_uint16      wMaxSegmentSize;
    kal_uint16      wNumberMCFilters;
    kal_uint8       bNumberPowerFilters;
} __GCC_PACKED__ usbc_cs_ethernet_networking_function_descriptor_t;


/*!
 *  @brief USB3.0 Binary Device Object Store Descriptor (BOS)
 */
typedef __RVCT_PACKED__ struct _usbc_bos_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint16      wTotalLength;
    kal_uint8       bNumDeviceCaps;
} __GCC_PACKED__ usbc_bos_descriptor_t;


/*!
 *  @brief USB3.0 Device Capability Descriptor -- USB2.0 EXTENSION
 */
typedef __RVCT_PACKED__ struct _usbc_u2_ext_dev_cap_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8     	bDevCapabilityType;
    kal_uint32      bmAttributes;
} __GCC_PACKED__ usbc_u2_ext_dev_cap_descriptor_t;

/*!
 *  @brief USB3.0 Device Capability Descriptor -- SuperSpeed
 */
typedef __RVCT_PACKED__ struct _usbc_ss_dev_cap_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8     	bDevCapabilityType;
    kal_uint8      	bmAttributes;
    kal_uint16		wSpeedsSupported;
    kal_uint8		bFunctionalitySupport;
    kal_uint8		bU1DevExitLat;
    kal_uint16		wU2DevExitLat;    
} __GCC_PACKED__ usbc_ss_dev_cap_descriptor_t;

/*!
 *  @brief USB3.0 Device Capability Descriptor -- Container ID
 */
typedef __RVCT_PACKED__ struct _usbc_contid_dev_cap_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8     	bDevCapabilityType;
    kal_uint8      	bReserved;
    kal_uint8		ContainerID[16];
} __GCC_PACKED__ usbc_contid_dev_cap_descriptor_t;


/*!
 *  @brief USB3.0 Endpoint Companion Descriptor
 */
typedef __RVCT_PACKED__ struct _usbc_ep_companion_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8     	bMaxBurst;
    kal_uint8      	bmAttributes;
    kal_uint16		wBytesPerInterval;
} __GCC_PACKED__ usbc_ep_companion_descriptor_t;


/*!
 *  @brief ACM USB3.0 BOS descriptor
 */
typedef __RVCT_PACKED__ struct _usbc_bos_descriptor_cdc_acm {
	usbc_bos_descriptor_t						bos_descriptor;
	usbc_u2_ext_dev_cap_descriptor_t			u2_ext_dev_cap_descriptor;
	usbc_ss_dev_cap_descriptor_t				ss_dev_descriptor;
} __GCC_PACKED__ usbc_bos_descriptor_cdc_acm_t;


//#define __CDC_ACM_REPORT_IAD__

/* MODE CDC_ACM Configuration Descriptors */
typedef __RVCT_PACKED__ struct _usbc_configuration_descriptor_cdc_acm {
    usbc_configuration_descriptor_t                 configuration_descriptor;
#ifdef __CDC_ACM_REPORT_IAD__
    usbc_interface_association_descriptor_t         interface_association_descriptor;
#endif
    usbc_interface_descriptor_t                     control_interface_descriptor;
    usbc_cs_header_descriptor_t                     cs_header_descriptor;
    usbc_cs_call_manage_descriptor_t                cs_call_manage_descriptor;
    usbc_cs_abstract_control_manage_descriptor_t    cs_abstrac_control_manage_descriptor;
    usbc_cs_union_function_descriptor_t             cs_union_function_descriptor;
    usbc_endpoint_descriptor_t                      commin_endpoint_descriptor;
    usbc_ep_companion_descriptor_t					commin_ep_companion_descriptor;
    usbc_interface_descriptor_t                     data_interface_descriptor;
    usbc_endpoint_descriptor_t                      datain_endpoint_descriptor;
    usbc_ep_companion_descriptor_t					datain_ep_companion_descriptor;
    usbc_endpoint_descriptor_t                      dataout_endpoint_descriptor;
    usbc_ep_companion_descriptor_t					dataout_ep_companion_descriptor;
} __GCC_PACKED__ usbc_configuration_descriptor_cdc_acm_t;


extern usbc_device_descriptor_t usbc_device_descriptor_cdc_acm;
extern usbc_configuration_descriptor_cdc_acm_t usbc_configuration_descriptor_cdc_acm;
extern usbc_device_qualifier_descriptor_t usbc_device_qualifier_descriptor_cdc_acm;
extern usbc_bos_descriptor_cdc_acm_t usbc_bos_descriptor_cdc_acm;
extern usbc_string_descriptor_t *p_language_str_desc;
extern usbc_string_descriptor_t *p_manuf_str_desc;
extern usbc_string_descriptor_t *p_product_str_desc;
extern usbc_string_descriptor_t *p_sn_str_desc;
extern kal_uint16 acm_if_setting[USBC_TOTAL_INTERFACE_NUM];
extern kal_uint16 dev_status;
extern kal_uint16 interface_status[USBC_TOTAL_INTERFACE_NUM];

/*
 *	@brief	ACM class driver definition
*/

/* UART state bitmap values */
#define SERIAL_STATE_BRXCARRIER             0x01

/* Class-Specfic Codes ,EP0 */
#define USB_ACM_SEND_ENCAPSULATED_COMMAND   0x00
#define USB_ACM_GET_ENCAPSULATED_RESPONSE	0x01
#define USB_ACM_SET_COMM_FEATURE            0x02
#define USB_ACM_GET_COMM_FEATURE            0x03
#define USB_ACM_CLEAR_COMM_FEATURE          0x04
#define USB_ACM_SET_LINE_CODING             0x20
#define USB_ACM_GET_LINE_CODING             0x21
#define USB_ACM_SET_CONTROL_LINE_STATE		0x22
#define USB_ACM_SEND_BREAK                  0x23



/* ACM line coding element
 * Note: sizeof(line_coding) should be less than maxPacketSize,
 * or split data of line_coding into several control transaction.
 */
typedef __RVCT_PACKED__ struct
{
	kal_uint32  dwDTERate;
	kal_uint8   bCharFormat;
	kal_uint8   bParityType;
	kal_uint8   bDataBits;
} __GCC_PACKED__ cdcacm_line_coding_t;

/* ACM interrupt packet structure */
typedef __RVCT_PACKED__ struct
{
#define CDCACM_USB_INTR_DATA_REQ_TYPE        0xA1
	kal_uint8	bmRequestType;
	kal_uint8	bRequest;
	kal_uint16	wValue;
	kal_uint16	wIndex;
	kal_uint16	wLength;
	kal_uint16	data;
} __GCC_PACKED__ cdcacm_intr_data_t;

typedef struct _usb_acm_priv{
	cdcacm_line_coding_t 	line_coding;	/*ACM line coding*/
	cdcacm_intr_data_t 		intr_data;		/*ACM notification data of COM IF*/
} usb_acm_priv_t;


void usbc_mode_speed_change_cdc_acm_usb11(void);
void usbc_mode_speed_change_cdc_acm_usb20(void);
void usbc_mode_speed_change_cdc_acm_usb30(void);
hifusb_control_request_type_e usb_ep0_class_req_handle(hifusb_setup_packet_t *p_setup, void *p_buf, kal_uint32 *p_len);
kal_uint32 usbc_cpy_config_desc_by_speed(hifusb_usb_speed_e speed, kal_uint8 *p_buf, kal_uint16 wLength, kal_bool is_other_speed);
hifusb_control_request_type_e usb_ep0_vendor_req_handle(hifusb_setup_packet_t *p_setup, void *p_buf, kal_uint32 *p_len);
void usb_acm_init(void);
void usb_acm_patch_pid_vid(kal_uint16 patch_pid, kal_uint16 patch_vid);

#endif
