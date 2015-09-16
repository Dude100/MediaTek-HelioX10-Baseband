/*!
 *  @file usbcore_usbstd.h
 *  @author Roger Huang <chaomin.haung@mediatek.com>
 *  @version 1.0
 *  @section LICENSE
 *
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
 *  @section DESCRIPTION
 *  This file provides standard definitions of usb-if specification
 */

#ifndef _USBCORE_USBSTD_H
#define _USBCORE_USBSTD_H

#include "kal_public_api.h"

/*
 * Helper routines.
 */
#define USBC_GET_UINT8(_buf, _offset) \
            *((kal_uint8*)(_buf) + (_offset))

#define USBC_GET_UINT16(_buf, _offset) \
            (  ((kal_uint16)*((kal_uint8 *)(_buf) + (_offset))) | \
              (((kal_uint16)*((kal_uint8 *)(_buf) + (_offset) + 1)) << 8) )

#define USBC_GET_UINT32(_buf, _offset) \
            (  ((kal_uint32)*((kal_uint8 *)(_buf) + (_offset))) | \
              (((kal_uint32)*((kal_uint8 *)(_buf) + (_offset) + 1)) << 8) | \
              (((kal_uint32)*((kal_uint8 *)(_buf) + (_offset) + 2)) << 16) | \
              (((kal_uint32)*((kal_uint8 *)(_buf) + (_offset) + 3)) << 24) )

#define USBC_SET_UINT8(_buf, _offset, _value) \
            *((kal_uint8*)(_buf) + (_offset)) = (kal_uint8)(_value)

#define USBC_SET_UINT16(_buf, _offset, _value) \
            *((kal_uint8*)(_buf) + (_offset)) = (kal_uint8)(_value); \
            *((kal_uint8*)(_buf) + (_offset) + 1) = (kal_uint8)((_value) >> 8)

#define USBC_SET_UINT32(_buf, _offset, _value) \
            *((kal_uint8*)(_buf) + (_offset)) = (kal_uint8)(_value); \
            *((kal_uint8*)(_buf) + (_offset) + 1) = (kal_uint8)((_value) >> 8); \
            *((kal_uint8*)(_buf) + (_offset) + 2) = (kal_uint8)((_value) >> 16); \
            *((kal_uint8*)(_buf) + (_offset) + 3) = (kal_uint8)((_value) >> 24)

#define USBC_GET_DESC_LENGTH(_desc) \
            USBC_GET_UINT8(_desc, 0)

#define USBC_SET_DESC_LENGTH(_desc, _value) \
            USBC_SET_UINT8(_desc, 0, _value)

#define USBC_GET_DESC_TYPE(_desc) \
            USBC_GET_UINT8(_desc, 1)

#define USBC_SET_DESC_TYPE(_desc, _value) \
            USBC_SET_UINT8(_desc, 1, _value)


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
#define USBC_REQ_SET_SEL                    0x30
#define USBC_REQ_SET_ISOCHRONOUS_DELAY      0x31

/*!
 * @brief Vendor Request Codes
 */
#define USBC_REQ_GET_MS_DESCRIPTOR          0xCC

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
#define USBC_FEATURE_FUNCTION_SUSPEND       0x00
#define USBC_FEATURE_DEVICE_REMOTE_WAKEUP   0x01
#define USBC_FEATURE_TEST_MODE              0x02
#define USBC_FEATURE_U1_ENABLE              0x30
#define USBC_FEATURE_U2_ENABLE              0x31
#define USBC_FEATURE_LTM_ENABLE             0x32


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
#define USBC_DT_BOS                         0x0F
#define USBC_DT_DEVICE_CAPABILITY           0x10
#define USBC_DT_ENDPOINT_COMPANION          0x30


/*!
 * @breif USB Request Directions
 */
#define USBC_EP_ADDR_DIR_IN                 0x80
#define USBC_EP_ADDR_NUM_MASK               0x7F



/*!
 *  @brief usbc_setup_packet_t describe the detail field definition of
 *         control setup packet
 */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _usbc_setup_packet {
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
}  usbc_setup_packet_t;
PRAGMA_END_PACK_STRUCT


/*!
 *  @brief Device Descriptor Structure
 */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _usbc_device_descriptor {
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
} usbc_device_descriptor_t;
PRAGMA_END_PACK_STRUCT

#define USBC_DEVICE_DESC_SIZE sizeof(usbc_device_descriptor_t)

/*!
 *  @brief Configuration Descriptor Structure
 */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _usbc_configuration_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint16      wTotalLength;
    kal_uint8       bNumInterfaces;
    kal_uint8       bConfigurationValue;
    kal_uint8       iConfiguration;
    kal_uint8       bmAttributes;
    kal_uint8       bMaxPower;
} usbc_configuration_descriptor_t;
PRAGMA_END_PACK_STRUCT

#define USBC_CONFIGURATION_DESC_SIZE sizeof(usbc_configuration_descriptor_t)
#define USBC_MAX_CONF_SIZE 1024
#define USBC_USB20_POWER_DESC_UINT 2 /* 2 mA unit */
#define USBC_USB30_POWER_DESC_UINT 8 /* 8 mA unit */
#define USBC_USB30_EP0_PACKET_SIZE 9 /* in power of 2 */

#define USBC_GET_CONF_TOTAL_LENGTH(_desc) \
            USBC_GET_UINT16(_desc, 2)
#define USBC_SET_CONF_TOTAL_LENGTH(_desc, _value) \
            USBC_SET_UINT16(_desc, 2, _value)

#define USBC_GET_CONF_MAX_POWER(_desc) \
            USBC_GET_UINT8(_desc, 8)
#define USBC_SET_CONF_MAX_POWER(_desc, _value) \
            USBC_SET_UINT8(_desc, 8, _value)


/*!
 *  @brief Interface Descriptor Structure
 */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _usbc_interface_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8       bInterfaceNumber;
    kal_uint8       bAlternateSetting;
    kal_uint8       bNumEndpoints;
    kal_uint8       bInterfaceClass;
    kal_uint8       bInterfaceSubClass;
    kal_uint8       bInterfaceProtocol;
    kal_uint8       iInterface;
} usbc_interface_descriptor_t;
PRAGMA_END_PACK_STRUCT


/*!
 *  @brief Interface Association Descriptor Structure
 */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _usbc_interface_association_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8       bFirstInterface;
    kal_uint8       bInterfaceCount;
    kal_uint8       bFunctionClass;
    kal_uint8       bFunctionSubClass;
    kal_uint8       bFunctionProtocol;
    kal_uint8       iFunction;
} usbc_interface_association_descriptor_t;
PRAGMA_END_PACK_STRUCT


/*!
 *  @brief Endpoint Descriptor Structure
 */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _usbc_endpoint_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8       bEndpointAddress;
    kal_uint8       bmAttributes;
    kal_uint16      wMaxPacketSize;
    kal_uint8       bInterval;
} usbc_endpoint_descriptor_t;
PRAGMA_END_PACK_STRUCT

#define USBC_GET_EP_ATTRIBUTES(_desc) \
            USBC_GET_UINT8(_desc, 3)
#define USBC_SET_EP_ATTRIBUTES(_desc, _value) \
            USBC_SET_UINT8(_desc, 3, _value)

#define USBC_GET_EP_MAX_PACKET_SIZE(_desc) \
            USBC_GET_UINT16(_desc, 4)
#define USBC_SET_EP_MAX_PACKET_SIZE(_desc, _value) \
            USBC_SET_UINT16(_desc, 4, _value)

#define USBC_CONTROL_TRANSFER       0x00
#define USBC_ISOCHRONOUS_TRANSFER   0x01
#define USBC_BULK_TRANSFER          0x02
#define USBC_INTERRUPT_TRANSFER     0x03

#define USBC_GET_EP_TRANSFER_TYPE(_desc) \
            (USBC_GET_EP_ATTRIBUTES(_desc) & 0x03)

#define USBC_USB30_BULK_PACKET_SIZE 1024

/*!
 *  @brief String Descriptor Structure
 */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _usbc_string_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint16      wData[1];
} usbc_string_descriptor_t;
PRAGMA_END_PACK_STRUCT


/*!
 *  @brief Qualifier Descriptor Structure
 */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _usbc_device_qualifier_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint16      bcdUSB;
    kal_uint8       bDeviceClass;
    kal_uint8       bDeviceSubClass;
    kal_uint8       bDeviceProtocol;
    kal_uint8       bMaxPacketSize0;
    kal_uint8       bNumConfigurations;
    kal_uint8       bRESERVED;
} usbc_device_qualifier_descriptor_t;
PRAGMA_END_PACK_STRUCT


/*!
 *  @brief CS Header Descriptor Structure
 */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _usbc_cs_header_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8       bDescriptorSubType;
    kal_uint16      bcdCDC;
} usbc_cs_header_descriptor_t;
PRAGMA_END_PACK_STRUCT


/*!
 *  @brief CS Call Manage Descriptor Structure
 */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _usbc_cs_call_manager_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8       bDescriptorSubType;
    kal_uint8       bmCapabilities;
    kal_uint8       bDataInterface;
} usbc_cs_call_manage_descriptor_t;
PRAGMA_END_PACK_STRUCT


/*!
 *  @brief CS Abstract Control Manage Descriptor Structure
 */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _usbc_cs_abstract_control_manage_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8       bDescriptorSubType;
    kal_uint8       bmCapabilities;
} usbc_cs_abstract_control_manage_descriptor_t;
PRAGMA_END_PACK_STRUCT


/*!
 *  @brief CS Union Function Descriptor Structure
 */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _usbc_cs_union_function_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8       bDescriptorSubType;
    kal_uint8       bMasterInterface;
    kal_uint8       bSlaveInterface;
} usbc_cs_union_function_descriptor_t;
PRAGMA_END_PACK_STRUCT


/*!
 *  @brief CS Ethernet Networking Function Descriptor Structure
 */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _usbc_cs_ethernet_networking_function_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8       bDescriptorSubType;
    kal_uint8       iMACAddress;
    kal_uint32      bmEthernetStatistics;
    kal_uint16      wMaxSegmentSize;
    kal_uint16      wNumberMCFilters;
    kal_uint8       bNumberPowerFilters;
} usbc_cs_ethernet_networking_function_descriptor_t;
PRAGMA_END_PACK_STRUCT

/*!
 *  @brief Microsoft OS String Descriptor Structure
 */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _usbc_os_string_descriptor {
    kal_uint8       bLength;
    kal_uint8       bDescriptorType;
    kal_uint8       qwSignature[14];
    kal_uint8       bMS_VendorCode;
    kal_uint8       bPad;
} usbc_os_string_descriptor_t;
PRAGMA_END_PACK_STRUCT

/*!
 *  @brief Microsoft OS String Descriptor Structure
 */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _usbc_ext_compat_id_os_feature_descriptor {
    kal_uint32      dwLength;
    kal_uint16      bcdVersion;
    kal_uint16      wIndex;
    kal_uint8       bCount;
    kal_uint8       bPads_1[7];
    kal_uint8       bFirstInterfaceNumber;
    kal_uint8       bInterfaceCount;
    kal_uint8       compatibleID[8];
    kal_uint8       subcompatibleID[8];
    kal_uint8       bPads_2[6];
} usbc_ext_compat_id_os_feature_descriptor_t;
PRAGMA_END_PACK_STRUCT

/*
 * USB 3.0 BOS descriptor.
 */
#define USBC_BOS_DESC_SIZE                          5
#define USBC_MAX_BOS_SIZE \
            ( USBC_BOS_DESC_SIZE + \
              USBC_SUPERSPEED_USB_DEV_CAP_DESC_SIZE + \
              USBC_USB20_EXT_DEV_CAP_DESC_SIZE )

#define USBC_GET_BOS_TOTAL_LENGTH(_desc) \
            USBC_GET_UINT16(_desc, 2)
#define USBC_SET_BOS_TOTAL_LENGTH(_desc, _value) \
            USBC_SET_UINT16(_desc, 2, _value)

/*
 * USB 2.0 Extension descriptor.
 */
#define USBC_USB20_EXT_DEV_CAP_DESC_SIZE            7

/*
 * SuperSpeed USB Device Capabilities descriptor.
 */
#define USBC_SUPERSPEED_USB_DEV_CAP_DESC_SIZE       10

/*
 * SuperSpeed Endpoint Companion descriptor.
 */
#define USBC_ENDPOINT_COMPANION_DESC_SIZE           6

#define USBC_GET_EPC_MAX_BURST(_desc) \
            USBC_GET_UINT8(_desc, 2)
#define USBC_SET_EPC_MAX_BURST(_desc, _value) \
            USBC_SET_UINT8(_desc, 2, _value)

#define USBC_GET_EPC_ATTRIBUTES(_desc) \
            USBC_GET_UINT8(_desc, 3)
#define USBC_SET_EPC_ATTRIBUTES(_desc, _value) \
            USBC_SET_UINT8(_desc, 3, _value)

#define USBC_GET_EPC_BYTES_PER_INTERVAL(_desc) \
            USBC_GET_UINT16(_desc, 4)
#define USBC_SET_EPC_BYTES_PER_INTERVAL(_desc, _value) \
            USBC_SET_UINT16(_desc, 4, _value)

#endif  // _USBCORE_USBSTD_H
