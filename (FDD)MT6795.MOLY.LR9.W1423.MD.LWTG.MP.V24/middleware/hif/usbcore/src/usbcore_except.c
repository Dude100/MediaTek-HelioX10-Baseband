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

/*******************************************************************************
 * Filename:
 * ---------
 *   usbcore_except.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   USB Core exception mode wrapper.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                 HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "kal_public_api.h"
#include "syscomp_config.h"

#include "usbcore_common.h"
#include "usbcore_main.h"
#include "usbcore_class_device.h"
#include "usbcore_hif.h"
#include "usbcore_except.h"

#include "hifusb_qmu.h"
#include "hifusb_qmu_except.h"
#include "hif_usb_except.h"

#if (defined(__MTK_TARGET__) && defined(__PRODUCTION_RELEASE__))
#include "dcl.h"
#endif

#define CPU_PMU_CNT_WRAP  (0xFFFFFFFFUL)
#define CPU_GET_DURATION(_start, _end) \
    ((_end) >= (_start)) ? ((_end) - (_start)) : (CPU_PMU_CNT_WRAP - (_start) + (_end) + 1))

#ifdef __MTK_TARGET__
    #ifdef USE_US_TIMER
        #error "TODO: USE_US_TIMER"
    #else /*use CPU performance counter, it might be not compatible for MAUI platform*/
        //#include "cpu.h"

        #define GET_CURR_TICK(_curr_tick) \
                (_curr_tick) = kal_get_systicks()
                //cpu_event_counter_get_cycle(_curr_tick)
    
        #define GET_DURATION_MS(_start_tick, _end_tick) \
                kal_ticks_to_milli_secs((CPU_GET_DURATION(_start_tick, _end_tick))
                //CPU_PMUTICK2MS(cpu_event_get_duration(_start_tick, _end_tick))
    #endif
#else
    #define GET_CURR_TICK(_curr_tick) (_curr_tick) = 0

    #define GET_DURATION_MS(_start_tick, _end_tick) 0
#endif

/*------------------------------------------------------------------------------
 * Constant definition.
 *----------------------------------------------------------------------------*/
#define USBC_EXCEPT_INFINITE_TIMEOUT    0xffffffff /* No timeout. */

#define USBC_EXCEPT_MIN_ENUM_TIMEOUT    100 /* Minmal USB enumeration timeout in ms. */
#define USBC_EXCEPT_DEF_ENUM_TIMEOUT    20000 /* Minmal USB enumeration timeout in ms. */

#define USBC_EXCEPT_MIN_TX_TIMEOUT      100 /* Minmal USB tx transfer timeout in ms. */
#define USBC_EXCEPT_DEF_TX_TIMEOUT      5000 /* Minmal USB tx transfer timeout in ms. */

#define USBC_EXCEPT_CALL_EXCEPT_INIT     0x00000001
#define USBC_EXCEPT_CALL_CLEAR_CH        0x00000002
#define USBC_EXCEPT_CALL_RESET_CH        0x00000004
#define USBC_EXCEPT_CALL_ENUM_LOOP       0x00000008
#define USBC_EXCEPT_CALL_SUBMIT_GPD      0x00000010
#define USBC_EXCEPT_CALL_POLL_QUEUE      0x00000020
#define USBC_EXCEPT_CALL_HIF_STATE       0x00000040
#define USBC_EXCEPT_CALL_HIF_POLL        0x00000080

#define USBC_EXCEPT_NOTIFY_RESET         0x00000100
#define USBC_EXCEPT_NOTIFY_SPEED_CHANGE  0x00000200

#define USBC_EXCEPT_CALL_FLUSH           0x00001000

#define USBC_EXCEPT_CLEAR_CH_NG          0x00010000
#define USBC_EXCEPT_ENUM_LOOP_OK         0x00020000
#define USBC_EXCEPT_ENUM_LOOP_TO         0x00040000
#define USBC_EXCEPT_SUBMIT_GPD_NG        0x00080000
#define USBC_EXCEPT_POLL_QUEUE_NG        0x00100000
#define USBC_EXCEPT_HIF_STATE_NG         0x00200000
#define USBC_EXCEPT_HIF_STATE_TO         0x00400000
#define USBC_EXCEPT_FLUSH_NG             0x01000000


#define INVALID_CLASS_DEVICE_ID          0xff
#define INVALID_PIPE_QUEUE_ID            0xff
#define PIPE_QUEUE_RX_MASK               0x80


/*!
 *  @brief USB Core control transfer state in exception mode.
 */
typedef enum _usbc_except_ct_state {
    USBC_EXCEPT_CT_READY                = 0,
    USBC_EXCEPT_CT_SETUP                = 1,
    USBC_EXCEPT_CT_DATA                 = 2,
} usbc_except_ct_state_e;

/*!
 *  @brief USB Core exception mode data path information for troubleshooting.
 */
typedef struct _usbc_except_data_log {
    kal_uint32                          tx_submit_called;
    kal_uint32                          tx_poll_called;
    kal_uint32                          tx_completed;
    qbm_gpd                            *tx_last_gpd_submitted;
    qbm_gpd                            *tx_last_gpd_polled;
    kal_uint32                          rx_submit_called;
    kal_uint32                          rx_poll_called;
    kal_uint32                          rx_completed;
    qbm_gpd                            *rx_last_gpd_submitted;
    qbm_gpd                            *rx_last_gpd_polled;
} usbc_except_data_log;

/*!
 *  @brief USB Core exception mode context.
 */
typedef struct _usbc_except_doc {
    /*!
     *  @brief HIF driver allocated buffer for IN/OUT data of a control transfer in exception mode
     */
    kal_uint8                          *ct_data_ptr;
    /*!
     *  @brief Bytes used in except_ct_data_ptr
     */
    kal_uint32                          ct_data_len;
    /*!
     *  @brief Result of the control transfer.
     */
    hifusb_control_request_type_e       ct_result;
    /*!
     *  @brief Control transfer state.
     */
    usbc_except_ct_state_e              ct_state;
    kal_uint8                           rsvd[2];
    /*!
     *  @brief USB enumeration tiemout in unit of ms.
     */
    kal_uint32                          enum_timeout; 
    /*!
     *  @brief Tx transfer tiemout in unit of ms.
     */
    kal_uint32                          tx_timeout; 
} usbc_except_doc_t;

static usbc_except_doc_t                usbc_except_doc_s;
#define usbc_except_get_doc()           (&usbc_except_doc_s)

static volatile kal_uint32              usbc_except_flags_s = 0; /* For troubleshooting USBCORE exception mode API.*/
#define usbc_set_flag(_flag)            usbc_except_flags_s |= (_flag)

static usbc_except_data_log             usbc_except_dlog_s; /* For USBCORE exception mode data path troubleshooting.*/
#define usbc_dlog_reset() \
        kal_mem_set( &usbc_except_dlog_s, 0, sizeof(usbc_except_data_log) )
#define usbc_dlog_submit_gpd(_queue_type, _gpd) \
    do { \
        if (HIFQ_TYPE_TX == _queue_type) { \
            usbc_except_dlog_s.tx_submit_called++; \
            usbc_except_dlog_s.tx_last_gpd_submitted = (qbm_gpd *)(_gpd); \
        } else { \
            usbc_except_dlog_s.rx_submit_called++; \
            usbc_except_dlog_s.rx_last_gpd_submitted = (qbm_gpd *)(_gpd); \
        } \
    } while (0)
#define usbc_dlog_poll_queue(_queue_type, _gpd_cnt, _gpd) \
    do { \
        if (HIFQ_TYPE_TX == _queue_type) { \
            usbc_except_dlog_s.tx_poll_called++; \
            if (0 < (_gpd_cnt)) { \
                usbc_except_dlog_s.tx_completed += (_gpd_cnt); \
                usbc_except_dlog_s.tx_last_gpd_polled = (_gpd); \
            } \
        } else { \
            usbc_except_dlog_s.rx_poll_called++; \
            if (0 < (_gpd_cnt)) { \
                usbc_except_dlog_s.rx_completed += (_gpd_cnt); \
                usbc_except_dlog_s.rx_last_gpd_polled = (_gpd); \
            } \
        } \
    } while (0)

/*------------------------------------------------------------------------------
 * Device/configuration/interface/endpoint Descriptors
 *----------------------------------------------------------------------------*/
#define USBC_DEF_VID                        0x0E8D
#define USBC_DEF_PID                        0x7101
#define USBC_TOTAL_INTERFACE_NUM            2
#define USBC_INTERFACE_MTK_COM_0            0
#define USBC_INTERFACE_MTK_COM_1            1

#define USBC_DEF_STR_IDX_MANUFACTURER       0x01
#define USBC_DEF_STR_IDX_PRODUCT            0x02
#define USBC_DEF_STR_IDX_SERIALNUM          0x03

#define __CDC_ACM_REPORT_IAD__

/* MODE CDC_ACM Device Descriptors */
static usbc_device_descriptor_t usbc_device_descriptor_cdc_acm =
{
    /* Device Descriptor */
    0x12,                           /* bLength              */
    USBC_DT_DEVICE,                 /* DEVICE               */
    0x0200,                         /* USB 2.0              */
#ifdef __CDC_ACM_REPORT_IAD__
    0xEF,                           /* CLASS                */
    0x02,                           /* Subclass             */
    0x01,                           /* Protocol             */
#else
    0x02,                           /* CLASS                */
    0x00,                           /* Subclass             */
    0x00,                           /* Protocol             */
#endif
    0x40,                           /* bMaxPktSize0         */
    USBC_DEF_VID,                   /* idVendor             */
    USBC_DEF_PID,                   /* idProduct            */
    0x0001,                         /* bcdDevice            */
    USBC_DEF_STR_IDX_MANUFACTURER,  /* iManufacturer        */
    USBC_DEF_STR_IDX_PRODUCT,       /* iProduct             */
#ifdef __PRODUCTION_RELEASE__
    0x00,
#else
/* under construction !*/
#endif
    0x01                            /* One configuration    */
};


/* MODE CDC_ACM Configuration Descriptors */
static struct _usbc_configuration_descriptor_cdc_acm {
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
    usbc_interface_descriptor_t                     data_interface_descriptor;
    usbc_endpoint_descriptor_t                      datain_endpoint_descriptor;
    usbc_endpoint_descriptor_t                      dataout_endpoint_descriptor;
} usbc_configuration_descriptor_cdc_acm = {
{
    /* Configuration Descriptor */
    0x09,                       /* bLength              */
    0x02,                       /* CONFIGURATION        */
#ifdef __CDC_ACM_REPORT_IAD__
    0x004B,                     /* length               */
#else
    0x0043,                     /* length               */
#endif
    USBC_TOTAL_INTERFACE_NUM,   /* bNumInterfaces       */
    0x01,                       /* bConfigurationValue  */
    0x00,                       /* iConfiguration       */
    0x80,                       /* bmAttributes (required + self-powered) */
    0xFA                        /* power                */
},
#ifdef __CDC_ACM_REPORT_IAD__
{
    /* Interface Association Descriptor */
    0x08,                       /* bLength              */
    USBC_DT_IAD,                /* bDescriptorType      */
    USBC_INTERFACE_MTK_COM_0,   /* bFristInterface      */
    0x02,                       /* bInterfaceCount      */
    0x02,                       /* bFunctionClass       */
    0x02,                       /* bFunctionSubClass    */
    0x01,                       /* bFunctionProtocol    */
    0x00                        /* iFunction            */
},
#endif
{
    /* Comm Interface Descriptor */
    0x09,                       /* bLength              */
    USBC_DT_INTERFACE,          /* INTERFACE            */
    USBC_INTERFACE_MTK_COM_0,   /* bInterfaceNumber     */
    0x00,                       /* bAlternatSetting     */
    0x01,                       /* bNumberEnpoints      */
    0x02,                       /* bInterface Class     */
    0x02,                       /* SubClass             */
    0x01,                       /* Protocol             */
    0x00                        /* Index of String      */
},
{
    /* CS Header Descriptor */
    0x05,                       /* bLength;             */
    0x24,                       /* bDescriptorType;     */
    0x00,                       /* bDescriptorSubType;  */
    0x0110                      /* bcdCDC;              */
},
{
    /* CS Call Manage Descriptor */
    0x05,                       /* bLength              */
    0x24,                       /* bDescriptorType      */
    0x01,                       /* bDescriptorSubType   */
    0x03,                       /* bmCapabilities       */
    USBC_INTERFACE_MTK_COM_1    /* bDataInterface       */
},
{
    /* CS Abstract Control Manage Descriptor */
    0x04,                       /* bLength              */
    0x24,                       /* bDescriptorType      */
    0x02,                       /* bDescriptorSubType   */
    0x0F                        /* bmCapabilities       */
},
{
    /* CS Union Function Descriptor */
    0x05,                       /* bLength;             */
    0x24,                       /* bDescriptorType;     */
    0x06,                       /* bDescriptorSubType;  */
    USBC_INTERFACE_MTK_COM_0,   /* bMasterInterface;    */
    USBC_INTERFACE_MTK_COM_1    /* bSlaveInterface;     */
},
{
    /* Comm EndpointDescriptor */
    0x07,                       /* bLength              */
    0x05,                       /* bDescriptorType      */
    0x82,                       /* bEndpointAddress     */
    0x03,                       /* bmAttributes         */
    0x0040,                     /* wMaxPacketSize       */
    0x01                        /* bInterval            */
},
{
    /* Data Interface Descriptor */
    0x09,                       /* bLength              */
    USBC_DT_INTERFACE,          /* INTERFACE            */
    USBC_INTERFACE_MTK_COM_1,   /* bInterfaceNumber     */
    0x00,                       /* bAlternatSetting     */
    0x02,                       /* bNumberEnpoints      */
    0x0A,                       /* bInterface Class     */
    0x00,                       /* SubClass             */
    0x00,                       /* Protocol             */
    0x00                        /* Index of String      */
},
{
    /* Data In Endpoint Descriptor */
    0x07,                       /* bLength              */
    0x05,                       /* bDescriptorType      */
    0x81,                       /* bEndpointAddress     */
    0x02,                       /* bmAttributes         */
    0x0200,                     /* wMaxPacketSize       */
    0x00                        /* bInterval            */
},
{
    /* Data Out EndpointDescriptor */
    0x07,                       /* bLength              */
    0x05,                       /* bDescriptorType      */
    0x01,                       /* bEndpointAddress     */
    0x02,                       /* bmAttributes         */
    0x0200,                     /* wMaxPacketSize       */
    0x00                        /* bInterval            */
}
};

/* MODE CDC_ACM Device Qualifier Descriptors */
static usbc_device_qualifier_descriptor_t usbc_device_qualifier_descriptor_cdc_acm =
{
    /* Device Qualifier Descriptor */
    0x0A,                       /* bLength              */
    USBC_DT_DEVICE_QUALIFIER,   /* Device Qualifier     */
    0x0200,                     /* USB Version          */
#ifdef __CDC_ACM_REPORT_IAD__
    0xEF,                       /* CLASS                */
    0x02,                       /* Subclass             */
    0x01,                       /* Protocol             */
#else
    0x02,                       /* CLASS                */
    0x00,                       /* Subclass             */
    0x00,                       /* Protocol             */
#endif
    0x40,                       /* Max Packet Length    */
    0x01,                       /* Number of other speed config */
    0x00                        /* Reserved             */
};

/* Default String Descriptor Language ID */
static kal_uint8 usbc_string_descriptor_language_default[] =
{
    /* String Descriptor */
    0x04,                       /* bLength              */
    0x03,                       /* bDescriptorType      */
    0x09,0x04
};


/* Default String Descriptor Manufacturer */
static kal_uint8 usbc_string_descriptor_manufacturer_default[] =
{
    /* String Descriptor */
    0x1c,                       /* bLength              */
    0x03,                       /* bDescriptorType      */
    'M',0x00,'e',0x00,'d',0x00,'i',0x00,
    'a',0x00,'T',0x00,'e',0x00,'k',0x00,
    ' ',0x00,'I',0x00,'n',0x00,'c',0x00,
    '.',0x00
};


/* Default String Descriptor Product */
static kal_uint8 usbc_string_descriptor_product_default[] =
{
    /* String Descriptor */
    0x1a,                       /* bLength              */
    0x03,                       /* bDescriptorType      */
    'L',0x00,'T',0x00,'E',0x00,' ',0x00,
    'U',0x00,'S',0x00,'B',0x00,' ',0x00,
    'C',0x00,'A',0x00,'R',0x00,'D',0x00,
};


/* Default String Descriptor SerialNum */
static kal_uint8 usbc_string_descriptor_serialnum_default[] =
{
    /* String Descriptor Serial Number */
    0x1a,                       /* bLength              */
    0x03,                       /* bDescriptorType      */
    '1',0x00,'1',0x00,'2',0x00,'2',0x00,
    '3',0x00,'3',0x00,'4',0x00,'4',0x00,
    '5',0x00,'5',0x00,'6',0x00,'6',0x00
};

/*------------------------------------------------------------------------------
 * Private implementation.
 *----------------------------------------------------------------------------*/
#define USBC_EXCEPT_MAX_TRACE_NUM 30
#define USBC_EXCEPT_TRACE_SIG 0xBA000000

kal_uint32 usbc_except_trace[USBC_EXCEPT_MAX_TRACE_NUM];
kal_uint32 usbc_except_trace_idx = 0;
void usbc_excpet_log_trace (kal_uint16 func_flag, kal_uint8 ret)
{
    usbc_except_trace_idx %= USBC_EXCEPT_MAX_TRACE_NUM;

    usbc_except_trace[usbc_except_trace_idx] = USBC_EXCEPT_TRACE_SIG;
    usbc_except_trace[usbc_except_trace_idx] |= ((func_flag & 0xFFFF) << 8);
    usbc_except_trace[usbc_except_trace_idx] |= ret;

    usbc_except_trace_idx ++;
}

static kal_bool usbc_except_hif_indicate_control_setup_packet(kal_uint8 intf_idx, usbc_setup_packet_t *packet)
{
    usbc_core_t    *pUsbCore = usbc_core_get_instance();
    usbc_core_class_interface_t *intf = &pUsbCore->class_interface[intf_idx];

    intf->notify_control_setup_packet(intf->class_device_id, packet);
    return KAL_TRUE;
}

static void usbc_except_hif_indicate_control_complete(kal_uint8 intf_idx)
{
    usbc_core_t    *pUsbCore = usbc_core_get_instance();
    usbc_core_class_interface_t *intf = &pUsbCore->class_interface[intf_idx];

    intf->notify_control_complete(intf->class_device_id);
}

static void usbc_except_hif_set_control_request(kal_uint8 *buffer, kal_uint32 length, usbc_control_request_type_e type)
{
    ASSERT(USBC_EXCEPT_CT_SETUP == usbc_except_get_doc()->ct_state);
    usbc_except_get_doc()->ct_state = USBC_EXCEPT_CT_DATA;

    switch (type) {
    case USBC_CONTROL_REQUEST_TYPE_SEND:
        /*
         * Control IN.
         */
        ASSERT(HIFUSB_CONTROL_REQUEST_TYPE_SEND == usbc_except_get_doc()->ct_result);
        if (length > usbc_except_get_doc()->ct_data_len) {
            length = usbc_except_get_doc()->ct_data_len;
        }
        kal_mem_cpy(usbc_except_get_doc()->ct_data_ptr, buffer, length);
        usbc_except_get_doc()->ct_data_len = length;
        usbc_except_get_doc()->ct_result = HIFUSB_CONTROL_REQUEST_TYPE_SEND;
        break;

    case USBC_CONTROL_REQUEST_TYPE_RECEIVE:
        /*
         * Control OUT.
         */
        ASSERT(HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE == usbc_except_get_doc()->ct_result);
        if (usbc_except_get_doc()->ct_data_len > length) {
            usbc_except_get_doc()->ct_data_len = length;
        }
        kal_mem_cpy(buffer, usbc_except_get_doc()->ct_data_ptr, usbc_except_get_doc()->ct_data_len);
        usbc_except_get_doc()->ct_result = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;
        break;
    
    case USBC_CONTROL_REQUEST_TYPE_STALL:
        /*
         * HIF driver only allows control IN to return STALL
         */
        if (HIFUSB_CONTROL_REQUEST_TYPE_SEND == usbc_except_get_doc()->ct_result) {
            usbc_except_get_doc()->ct_result = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
        } else {
            usbc_except_get_doc()->ct_data_len = 0;
        }
        break;

    default:
        ASSERT(0);
        usbc_except_get_doc()->ct_data_len = 0;
        break;
    }
}

static kal_bool usbc_except_hif_set_usb_address(kal_uint8 address)
{
    usbc_core_t    *pUsbCore = usbc_core_get_instance();

    pUsbCore->usb_address = address;
    hifusb_except_set_usb_address(pUsbCore->usb_address);

    return KAL_TRUE;
}

static kal_bool usbc_except_hif_set_usb_configuration(kal_uint8 configuration)
{
    usbc_core_t    *pUsbCore = usbc_core_get_instance();

    pUsbCore->usb_configuration = configuration;
    hifusb_except_set_usb_configuration(pUsbCore->usb_configuration);

    if ( pUsbCore->usb_configuration > 0 ) {
        pUsbCore->state = USBC_USB_STATE_ATTACHED;
    } else {
        pUsbCore->state = USBC_USB_STATE_ATTACHING;
    }

    return KAL_TRUE;
}

static void usbc_except_hif_set_stall(kal_bool is_tx, kal_uint8 nEnd)
{
}


static void usbc_except_hif_clear_stall(kal_bool is_tx, kal_uint8 nEnd)
{
}

static kal_bool usbc_except_hif_set_usb_testmode(hifusb_test_mode_e testmode)
{
    return KAL_FALSE;
}

static void usbc_except_hif_factory(void)
{
    usbc_core_indicate_control_setup_packet = usbc_except_hif_indicate_control_setup_packet;
    usbc_core_indicate_control_complete = usbc_except_hif_indicate_control_complete;
    usbc_core_indicate_alternate_setting = usbc_core_notify_alternate_setting;
    usbc_core_indicate_stall = usbc_core_notify_stall;
    usbc_core_set_control_request = usbc_except_hif_set_control_request;
    usbc_core_set_property = hifusb_except_set_property;
    usbc_core_set_usb_address = usbc_except_hif_set_usb_address;
    usbc_core_set_usb_configuration = usbc_except_hif_set_usb_configuration;
    usbc_core_set_stall = usbc_except_hif_set_stall;
    usbc_core_clear_stall = usbc_except_hif_clear_stall;
    usbc_core_set_usb_testmode = usbc_except_hif_set_usb_testmode;
}

static void usbc_except_load_settings(void)
{
    if (usbc_core_get_hmu_info()->enum_timeout >= USBC_EXCEPT_MIN_ENUM_TIMEOUT) {
        usbc_except_get_doc()->enum_timeout = usbc_core_get_hmu_info()->enum_timeout;
    } else {
        usbc_except_get_doc()->enum_timeout = USBC_EXCEPT_DEF_ENUM_TIMEOUT;
    }
    if (usbc_core_get_hmu_info()->tx_timeout >= USBC_EXCEPT_MIN_TX_TIMEOUT) {
        usbc_except_get_doc()->tx_timeout = usbc_core_get_hmu_info()->tx_timeout;
    } else {
        usbc_except_get_doc()->tx_timeout = USBC_EXCEPT_DEF_TX_TIMEOUT;
    }
}

static void usbc_except_init_context(void)
{
    /*
     * Initialize USB Core context for exception mode.
     */
    kal_mem_set(usbc_except_get_doc(), 0, sizeof(usbc_except_doc_t));
    usbc_except_load_settings();

    usbc_set_op_mode(USBC_OP_MODE_EXCEPTION);
    kal_mem_set(usbc_core_get_instance(), 0, sizeof(usbc_core_t));

    usbc_except_hif_factory();
    usbc_resource_reset();
    usbc_core_clear_register();
    usbc_core_clear_status();
}

static void usbc_except_read_configuration(void)
{
    /*
     * Currently, we assume exception mode only uses 1 CDC/ACM COM port configuration.
     */
    usbc_core_t* pUsbCore = usbc_core_get_instance();

    /* configure descriptor */
    kal_mem_cpy(pUsbCore->descriptors.device, &usbc_device_descriptor_cdc_acm, USBC_DEVICE_DESC_SIZE);
    kal_mem_cpy(pUsbCore->descriptors.configuration[0], &usbc_configuration_descriptor_cdc_acm, sizeof(usbc_configuration_descriptor_cdc_acm));
    kal_mem_cpy(&pUsbCore->device_qualifier_descriptor   , &usbc_device_qualifier_descriptor_cdc_acm, sizeof(usbc_device_qualifier_descriptor_t));

    pUsbCore->total_class_devices           = 1;
    /* configure 1st class device */
    pUsbCore->class_device[0].class_type    = USB_CLASS_ACM2;
    pUsbCore->class_device[0].state         = USBC_CORE_CLASS_DEVICE_STATE_INITIATED;
    pUsbCore->class_device[0].total_pipes   = 3;

    pUsbCore->total_class_interfaces        = 2;
    /* configure 1st class interface */
    pUsbCore->class_interface[0].class_device_id    = 0;
    pUsbCore->class_interface[0].interface_no       = usbc_configuration_descriptor_cdc_acm.control_interface_descriptor.bInterfaceNumber;
    pUsbCore->class_interface[0].interface_type     = USBC_INTERFACE_TYPE_CDC_ACM_CONTROL;
    pUsbCore->class_interface[0].state              = USBC_CORE_CLASS_INTERFACE_STATE_INITIATED;
    pUsbCore->class_interface[0].alternate_setting  = 0;

    /* configure 2nd class interface */
    pUsbCore->class_interface[1].class_device_id    = 0;
    pUsbCore->class_interface[1].interface_no       = usbc_configuration_descriptor_cdc_acm.data_interface_descriptor.bInterfaceNumber;
    pUsbCore->class_interface[1].interface_type     = USBC_INTERFACE_TYPE_CDC_ACM_DATA;
    pUsbCore->class_interface[1].state              = USBC_CORE_CLASS_INTERFACE_STATE_INITIATED;
    pUsbCore->class_interface[1].alternate_setting  = 0;

    pUsbCore->total_tx_queues               = 2;
    /* configure 1st transmit queue */
    pUsbCore->tx_queue[0].class_device_id   = 0;
    pUsbCore->tx_queue[0].state             = USBC_CORE_QUEUE_STATE_INITIATED;
    pUsbCore->tx_queue[0].pipe_type         = USBC_PIPE_TYPE_CDC_ACM_DATA_IN;
    pUsbCore->tx_queue[0].xfer_type         = HIFUSB_EP_XFER_TYPE_BULK;
    pUsbCore->tx_queue[0].ep_no             = usbc_configuration_descriptor_cdc_acm.datain_endpoint_descriptor.bEndpointAddress & ~0x80;
    pUsbCore->tx_queue[0].max_packet_size   = usbc_configuration_descriptor_cdc_acm.datain_endpoint_descriptor.wMaxPacketSize;
    pUsbCore->tx_queue[0].double_fifo       = KAL_TRUE;
#ifdef ENABLE_QMU_CHECKSUM
    pUsbCore->tx_queue[0].config            = HIFUSB_QMU_EN | HIFUSB_QMU_CS_EN | HIFUSB_QMU_TXQ_ZLP | HIFUSB_QMU_TXQ_EMPTY_ENQ;
#else
    pUsbCore->tx_queue[0].config            = HIFUSB_QMU_EN | HIFUSB_QMU_TXQ_ZLP | HIFUSB_QMU_TXQ_EMPTY_ENQ;
#endif

    /* configure 2nd transmit queue */
    pUsbCore->tx_queue[1].class_device_id   = 0;
    pUsbCore->tx_queue[1].state             = USBC_CORE_QUEUE_STATE_INITIATED;
    pUsbCore->tx_queue[1].pipe_type         = USBC_PIPE_TYPE_CDC_ACM_COMM_IN;
    pUsbCore->tx_queue[1].xfer_type         = HIFUSB_EP_XFER_TYPE_INT;
    pUsbCore->tx_queue[1].ep_no             = usbc_configuration_descriptor_cdc_acm.commin_endpoint_descriptor.bEndpointAddress & ~0x80;
    pUsbCore->tx_queue[1].max_packet_size   = usbc_configuration_descriptor_cdc_acm.commin_endpoint_descriptor.wMaxPacketSize;
    pUsbCore->tx_queue[1].double_fifo       = KAL_FALSE;
#ifdef ENABLE_QMU_CHECKSUM
    pUsbCore->tx_queue[1].config            = HIFUSB_QMU_EN | HIFUSB_QMU_CS_EN;
#else
    pUsbCore->tx_queue[1].config            = HIFUSB_QMU_EN;
#endif

    pUsbCore->total_rx_queues   = 1;
    /* configure 1st receive queue */
    pUsbCore->rx_queue[0].class_device_id   = 0;
    pUsbCore->rx_queue[0].state             = USBC_CORE_QUEUE_STATE_INITIATED;
    pUsbCore->rx_queue[0].pipe_type         = USBC_PIPE_TYPE_CDC_ACM_DATA_OUT;
    pUsbCore->rx_queue[0].xfer_type         = HIFUSB_EP_XFER_TYPE_BULK;
    pUsbCore->rx_queue[0].ep_no             = usbc_configuration_descriptor_cdc_acm.dataout_endpoint_descriptor.bEndpointAddress & ~0x80;
    pUsbCore->rx_queue[0].max_packet_size   = usbc_configuration_descriptor_cdc_acm.dataout_endpoint_descriptor.wMaxPacketSize;
    pUsbCore->rx_queue[0].double_fifo       = KAL_TRUE;
#ifdef ENABLE_QMU_CHECKSUM
    pUsbCore->rx_queue[0].config            = HIFUSB_QMU_EN | HIFUSB_QMU_CS_EN;
#else
    pUsbCore->rx_queue[0].config            = HIFUSB_QMU_EN;
#endif

    /* String descriptor */
    pUsbCore->string_descriptor[0] = (usbc_string_descriptor_t*)usbc_string_descriptor_language_default;
    pUsbCore->string_descriptor[USBC_DEF_STR_IDX_MANUFACTURER] = (usbc_string_descriptor_t*)usbc_string_descriptor_manufacturer_default;
    pUsbCore->string_descriptor[USBC_DEF_STR_IDX_PRODUCT] = (usbc_string_descriptor_t*)usbc_string_descriptor_product_default;
    pUsbCore->string_descriptor[USBC_DEF_STR_IDX_SERIALNUM] = (usbc_string_descriptor_t*)usbc_string_descriptor_serialnum_default;
    pUsbCore->resource_string_number = 4;

    /* Reset speed */
    pUsbCore->speed = USBC_USB_SPEED_MIN;
}

static void usbc_except_restart_watchdog(void)
{
#if (defined(__MTK_TARGET__) && defined(__PRODUCTION_RELEASE__))
    DCL_HANDLE dcl_wdt_handle;

    dcl_wdt_handle = DclWDT_Open(DCL_WDT, 0);
    DclWDT_Control(dcl_wdt_handle,WDT_CMD_RESTART, 0);
    DclWDT_Close(dcl_wdt_handle);

#endif  // #if (defined(__MTK_TARGET__) && defined(__PRODUCTION_RELEASE__))
}

/*------------------------------------------------------------------------------
 * HIF callback functions.
 *----------------------------------------------------------------------------*/
static void usbc_except_compile_ep_companion(kal_uint8 *dst_desc, kal_uint8 transfer_type)
{
    USBC_SET_DESC_LENGTH(dst_desc, USBC_ENDPOINT_COMPANION_DESC_SIZE);
    USBC_SET_DESC_TYPE(dst_desc, USBC_DT_ENDPOINT_COMPANION);
    USBC_SET_EPC_ATTRIBUTES(dst_desc, 0);

    if (USBC_BULK_TRANSFER == transfer_type) {
        USBC_SET_EPC_MAX_BURST(dst_desc, 1);
        USBC_SET_EPC_BYTES_PER_INTERVAL(dst_desc, 0);
    } else {
        USBC_SET_EPC_MAX_BURST(dst_desc, 0);
        USBC_SET_EPC_BYTES_PER_INTERVAL(dst_desc, 0x40);
    }
}

static void usbc_except_configuration_speed_change(usbc_core_t *pUsbCore, usbc_usb_speed_e speed)
{
    kal_uint32 total_len;
    kal_uint32 bytes_read;
    kal_uint32 bytes_written;
    kal_uint8 *desc_read;
    kal_uint8 *desc_to_write;
    kal_uint32 desc_len;
    kal_uint32 idx_ep;
    kal_uint8  conf[USBC_MAX_CONF_SIZE];

    kal_mem_cpy(conf, pUsbCore->descriptors.configuration[0], USBC_MAX_CONF_SIZE);
    bytes_read = 0;
    bytes_written = 0;
    total_len = USBC_GET_CONF_TOTAL_LENGTH(conf);

    while (bytes_read < total_len)
    {
        desc_read = conf + bytes_read;
        desc_to_write = pUsbCore->descriptors.configuration[0] + bytes_written;
        desc_len = USBC_GET_DESC_LENGTH(desc_read);

        kal_mem_cpy(desc_to_write, desc_read, desc_len);
        bytes_written += desc_len;

        switch (USBC_GET_DESC_TYPE(desc_read))
        {
            case USBC_DT_ENDPOINT:
            {
                if (USBC_BULK_TRANSFER == USBC_GET_EP_TRANSFER_TYPE(desc_to_write))
                {
                    switch (speed) {
                        case USBC_USB_SPEED_USB11:
                        {
                            USBC_SET_EP_MAX_PACKET_SIZE(desc_to_write, USBC_USB11_MAX_PACKET_SIZE);
                            break;
                        }
                        case USBC_USB_SPEED_USB20:
                        {
                            USBC_SET_EP_MAX_PACKET_SIZE(desc_to_write, USBC_USB20_MAX_PACKET_SIZE);
                            break;
                        }
                        case USBC_USB_SPEED_USB30:
                        {
                            USBC_SET_EP_MAX_PACKET_SIZE(desc_to_write, USBC_USB30_MAX_PACKET_SIZE);
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                }
                if (speed == USBC_USB_SPEED_USB30) {
                    if (bytes_written + USBC_ENDPOINT_COMPANION_DESC_SIZE <= USBC_MAX_CONF_SIZE) {
                        usbc_except_compile_ep_companion(desc_to_write + desc_len, USBC_GET_EP_TRANSFER_TYPE(desc_to_write));
                        bytes_written += USBC_ENDPOINT_COMPANION_DESC_SIZE;
                    }
                }
                break;
            }  
            default:
               break;
        }
        bytes_read += desc_len;
    }

    /*
     * Patch configuration descriptor.
     */
    if (speed == USBC_USB_SPEED_USB30) {
        USBC_SET_CONF_MAX_POWER(pUsbCore->descriptors.configuration[0], (896 / USBC_USB30_POWER_DESC_UINT));
    }
    USBC_SET_CONF_TOTAL_LENGTH(pUsbCore->descriptors.configuration[0], bytes_written);

    /*
     * Modify max packet size in tx/rx endpoint queue info
     */
    for (idx_ep = 0; idx_ep < pUsbCore->total_tx_queues; idx_ep ++)
    {
        if (pUsbCore->tx_queue[idx_ep].xfer_type == HIFUSB_EP_XFER_TYPE_BULK)
        {
            switch (speed) {
                case USBC_USB_SPEED_USB11:
                {
                    pUsbCore->tx_queue[idx_ep].max_packet_size = USBC_USB11_MAX_PACKET_SIZE;
                    break;
                }
                case USBC_USB_SPEED_USB20:
                {
                    pUsbCore->tx_queue[idx_ep].max_packet_size = USBC_USB20_MAX_PACKET_SIZE;
                    break;
                }
                case USBC_USB_SPEED_USB30:
                {
                    pUsbCore->tx_queue[idx_ep].max_packet_size = USBC_USB30_MAX_PACKET_SIZE;
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
    }
    for (idx_ep = 0; idx_ep < pUsbCore->total_rx_queues; idx_ep ++)
    {
        if (pUsbCore->rx_queue[idx_ep].xfer_type != HIFUSB_EP_XFER_TYPE_BULK)
        {
            switch (speed) {
                case USBC_USB_SPEED_USB11:
                {
                    pUsbCore->rx_queue[idx_ep].max_packet_size = USBC_USB11_MAX_PACKET_SIZE;
                    break;
                }
                case USBC_USB_SPEED_USB20:
                {
                    pUsbCore->rx_queue[idx_ep].max_packet_size = USBC_USB20_MAX_PACKET_SIZE;
                    break;
                }
                case USBC_USB_SPEED_USB30:
                {
                    pUsbCore->rx_queue[idx_ep].max_packet_size = USBC_USB30_MAX_PACKET_SIZE;
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
    }
}
static void usbc_except_speed_change(usbc_core_t *pUsbCore, usbc_usb_speed_e speed)
{
	usbc_device_descriptor_t *dev_desc;

    pUsbCore->speed = speed;
    dev_desc = (usbc_device_descriptor_t *)pUsbCore->descriptors.device;

    /*
     *  Device descriptor speed change
     */
    switch (speed) {
        case USBC_USB_SPEED_USB30:
            dev_desc->bcdUSB = 0x0300;
            dev_desc->bMaxPacketSize0 = USBC_USB30_EP0_PACKET_SIZE;
            break;
    
        default:
            dev_desc->bcdUSB = 0x0210;
            dev_desc->bMaxPacketSize0 = 64;
            break;
    }
     
    /*
     *  Configuration descriptor speed change
     */
    usbc_except_configuration_speed_change(pUsbCore, speed);
}

static void usbc_core_notify_usb_event(hifusb_notify_evt_e event, void *data)
{
    usbc_core_t        *pUsbCore = usbc_core_get_instance();
    usbc_usb_speed_e    speed;

    USBC_EXCEPTION_MODE_CHECK();

    /*
     * In exception mode: 
     *
     * 1. For simplicity, we don't indicate any USB event to USB Class.
     * 2. When HIF driver indicates RESET event to USBCORE,
     * we will notify USB Class about the current USB speed and then 
     * set HIF IP related configruation.
     *
     */
    switch (event) {
    case HIFUSB_NOTIFY_EVT_RESET:
        usbc_set_flag(USBC_EXCEPT_NOTIFY_RESET);
        speed = *(usbc_usb_speed_e*)data;
        usbc_excpet_log_trace(USBC_EXCEPT_NOTIFY_RESET, 0);
        if (speed != pUsbCore->speed) {
            /*
             * Change USB link speed and related settings.
             */
            usbc_set_flag(USBC_EXCEPT_NOTIFY_SPEED_CHANGE);
            usbc_except_speed_change(pUsbCore, speed);
            usbc_core_notify_speed_change(speed);
            usbc_excpet_log_trace(USBC_EXCEPT_NOTIFY_SPEED_CHANGE, 0);
        }
        pUsbCore->state = USBC_USB_STATE_RESET;
        usbc_core_set_hif_configuration();
        usbc_core_notify_state_reset();
        pUsbCore->usb_configuration = 0;
        usbc_except_get_doc()->ct_state = USBC_EXCEPT_CT_READY;

        break;

    default:
        break;
    }
}

static hifusb_control_request_type_e usbc_except_notify_usb_except_control_in(hifusb_setup_packet_t *p_setup, void *p_buf, kal_uint32 *p_len)
{
    usbc_core_t                    *pUsbCore = usbc_core_get_instance();
    hifusb_control_request_type_e   result;

    USBC_EXCEPTION_MODE_CHECK();

    ASSERT(USBC_EXCEPT_CT_READY == usbc_except_get_doc()->ct_state);
    usbc_except_get_doc()->ct_data_ptr = (kal_uint8 *)p_buf;
    usbc_except_get_doc()->ct_data_len = HIFUSB_EXCEPT_EP_BUF_SZ;
    usbc_except_get_doc()->ct_result = HIFUSB_CONTROL_REQUEST_TYPE_SEND;
    usbc_except_get_doc()->ct_state = USBC_EXCEPT_CT_SETUP;

    usbc_core_dispatch_control_setup_packet(pUsbCore, p_setup);
    ASSERT(USBC_EXCEPT_CT_DATA == usbc_except_get_doc()->ct_state);

    *p_len = usbc_except_get_doc()->ct_data_len;
    result = usbc_except_get_doc()->ct_result;
    usbc_core_notify_control_complete(pUsbCore);
    usbc_except_get_doc()->ct_state = USBC_EXCEPT_CT_READY;

    return result;
}

static hifusb_control_request_type_e usbc_except_notify_usb_except_control_out(hifusb_setup_packet_t *p_setup, void *p_buf, kal_uint32 len)
{
    usbc_core_t                    *pUsbCore = usbc_core_get_instance();
    hifusb_control_request_type_e   result;

    USBC_EXCEPTION_MODE_CHECK();

    ASSERT(USBC_EXCEPT_CT_READY == usbc_except_get_doc()->ct_state);
    usbc_except_get_doc()->ct_data_ptr = (kal_uint8 *)p_buf;
    usbc_except_get_doc()->ct_data_len = len;
    usbc_except_get_doc()->ct_result = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;
    usbc_except_get_doc()->ct_state = USBC_EXCEPT_CT_SETUP;

    usbc_core_dispatch_control_setup_packet(pUsbCore, p_setup);
    ASSERT(USBC_EXCEPT_CT_DATA == usbc_except_get_doc()->ct_state);

    result = usbc_except_get_doc()->ct_result;
    usbc_core_notify_control_complete(pUsbCore);
    usbc_except_get_doc()->ct_state = USBC_EXCEPT_CT_READY;

    return result;
}

/*------------------------------------------------------------------------------
 * Public interface.
 *----------------------------------------------------------------------------*/

kal_bool usbc_except_init(void)
{
    usbc_set_flag(USBC_EXCEPT_CALL_EXCEPT_INIT);

    usbc_except_load_settings();
    hifusbq_except_initial();

    usbc_excpet_log_trace(USBC_EXCEPT_CALL_EXCEPT_INIT, 1);
    return KAL_TRUE;
}

kal_bool usbc_except_clear_ch(kal_uint8 class_device_id, kal_uint8 queue_no)
{
    usbc_core_queue_t  *queue;
    hif_queue_type_e    queue_type;

    usbc_set_flag(USBC_EXCEPT_CALL_CLEAR_CH);

    if (!usbc_core_get_queue_info(class_device_id, queue_no, &queue, &queue_type)) {
        usbc_set_flag(USBC_EXCEPT_CLEAR_CH_NG);
        usbc_excpet_log_trace(USBC_EXCEPT_CALL_CLEAR_CH, 0);
        return KAL_FALSE;
    }

    hifusbq_except_clear_q(queue_type, HIFUSB_EPNO_2_QNO(queue->ep_no));
    usbc_excpet_log_trace(USBC_EXCEPT_CALL_CLEAR_CH, 1);
    return KAL_TRUE;
}

static kal_uint8 usbc_except_acquire_pipe_queue(kal_uint8 class_device_id, usbc_pipe_type_e type)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8 pipe_queue = INVALID_PIPE_QUEUE_ID;
    kal_uint8 i = 0;

    for ( i=0; i< MAX_USBCORE_QUEUE_NUM; i++ )
    {
        if ( (pUsbCore->tx_queue[i].class_device_id == class_device_id) &&
             (pUsbCore->tx_queue[i].pipe_type == type) &&
             (pUsbCore->tx_queue[i].state == USBC_CORE_QUEUE_STATE_INITIATED))
        {
            pipe_queue = i;
            break;
        }
    }

    if ( pipe_queue != INVALID_PIPE_QUEUE_ID )
    {
        return pipe_queue;
    }

    for ( i=0; i< MAX_USBCORE_QUEUE_NUM; i++ )
    {
        if ( (pUsbCore->rx_queue[i].class_device_id == class_device_id) &&
             (pUsbCore->rx_queue[i].pipe_type == type) &&
             (pUsbCore->rx_queue[i].state == USBC_CORE_QUEUE_STATE_INITIATED))
        {
            pipe_queue = (i | PIPE_QUEUE_RX_MASK);
            break;
        }
    }

    return pipe_queue;
}

static usbc_class_device_instance_t*
usbc_except_device_register(
    usbc_core_t              *pUsbCore,
    usbc_class_device_info_t *device_info)
{
    usbc_core_class_device_t* pClassDevice = NULL;
    usbc_class_device_instance_t* pClassDeviceInstance = NULL;
    usbc_core_queue_t* pQueue = NULL;
    kal_uint8 acquire_queue = 0;
    kal_uint8 i = 0;

    if (device_info == NULL) {
        return NULL;
    }

    /* found available device instance, use it and apply register infromation */
    pClassDevice = &(pUsbCore->class_device[0]);
    if (device_info->total_pipes != pClassDevice->total_pipes) {
        // pipe number not match, return NULL
        return NULL;
    }

    pClassDeviceInstance                    = &(pClassDevice->device_instance);
    pClassDeviceInstance->id                = 0;
    pClassDeviceInstance->speed             = pUsbCore->speed;
    pClassDeviceInstance->total_interfaces  = 0;
    pClassDeviceInstance->context           = device_info->class_device_context;
    pClassDevice->state             = USBC_CORE_CLASS_DEVICE_STATE_REGISTERED;
    pClassDevice->notify_usb_state  = device_info->notify_usb_state;
    pClassDevice->notify_usb_speed  = device_info->notify_usb_speed;
    for ( i=0; i<pUsbCore->total_class_interfaces; i++ )
    {
        if ( (pUsbCore->class_interface[i].state == USBC_CORE_CLASS_INTERFACE_STATE_INITIATED) &&
             (pUsbCore->class_interface[i].class_device_id == 0) )
        {
            /* fill Device Instance interface information */
            pClassDeviceInstance->interface_type[pClassDeviceInstance->total_interfaces] = pUsbCore->class_interface[i].interface_type;
            pClassDeviceInstance->interface_no[pClassDeviceInstance->total_interfaces] = pUsbCore->class_interface[i].interface_no;
            pClassDeviceInstance->total_interfaces++;

            /* fill USB Core interface information */
            pUsbCore->class_interface[i].state = USBC_CORE_CLASS_INTERFACE_STATE_ACTIVE;
            pUsbCore->class_interface[i].notify_control_setup_packet = device_info->notify_control_setup_packet;
            pUsbCore->class_interface[i].notify_control_complete = device_info->notify_control_complete;
            pUsbCore->class_interface[i].notify_alternate_setting = device_info->notify_alternate_setting;
        }
    }

    for ( i=0; i<device_info->total_pipes; i++ )
    {
        acquire_queue = usbc_except_acquire_pipe_queue(0, device_info->pipe_type[i]);
        if ( acquire_queue == INVALID_PIPE_QUEUE_ID )
        {
            return NULL;
        }

        /* fill Device Instance Queue information */
        pClassDeviceInstance->queue_no_for_pipe[i] = acquire_queue;

        /* fill USB Core Queue information */
        if ( (acquire_queue & PIPE_QUEUE_RX_MASK) != PIPE_QUEUE_RX_MASK )
        {
            pQueue = &(pUsbCore->tx_queue[acquire_queue]);
        } else {
            pQueue = &(pUsbCore->rx_queue[acquire_queue & ~PIPE_QUEUE_RX_MASK]);
        }
        pQueue->state               = USBC_CORE_QUEUE_STATE_ACTIVE;
        pQueue->notify_complete     = device_info->notify_pipe_complete[i];
        pQueue->notify_stall        = device_info->notify_pipe_stall[i];
    }

    return pClassDeviceInstance;
}


usbc_class_device_instance_t *usbc_except_reset_ch(usbc_class_device_info_t *device_info)
{
    usbc_class_device_instance_t   *dev_inst;
    static hifusb_except_cb_t       except_cb;

    usbc_set_flag(USBC_EXCEPT_CALL_RESET_CH);
    usbc_dlog_reset();

    usbc_except_init_context();
    usbc_except_read_configuration();

    /*
     * Register exception mode callback function to HIF driver and 
     * disconnect and then connect to USB to trigger USB re-enumeration.
     */
    except_cb.notify_usb_except_evt = usbc_core_notify_usb_event;
    except_cb.notify_usb_except_control_in = usbc_except_notify_usb_except_control_in;
    except_cb.notify_usb_except_control_out = usbc_except_notify_usb_except_control_out;
    hifusb_except_change_ch(&except_cb);

    /*
     * Find the device instance for the USB CLASS in exception.
     */
    dev_inst = usbc_except_device_register(usbc_core_get_instance(), device_info);
    usbc_excpet_log_trace(USBC_EXCEPT_CALL_RESET_CH, 2);
    return dev_inst;
}

kal_bool usbc_except_enum_loop(void)
{
    usbc_core_t        *pUsbCore = usbc_core_get_instance();

    usbc_set_flag(USBC_EXCEPT_CALL_ENUM_LOOP);
    USBC_EXCEPTION_MODE_CHECK();

    /*
     * Wait untill SET_CONFIGURATION or timeout to make sure 
     * host side driver is ready.
     */
#if (defined(__MTK_TARGET__) && defined(__PRODUCTION_RELEASE__))
    kal_uint32          begin_tick;     
    GET_CURR_TICK(begin_tick);
#endif  // #if (defined(__MTK_TARGET__) && defined(__PRODUCTION_RELEASE__))
    do {
        usbc_except_restart_watchdog();     // Restart watchdog timer to avoid silient reboot

		hifusb_except_poll_isr();

#if (defined(__MTK_TARGET__) && defined(__PRODUCTION_RELEASE__))
        kal_uint32          curr_tick;
        kal_uint64          ms_passed;
        GET_CURR_TICK(curr_tick);
        ms_passed = GET_DURATION_MS(begin_tick, curr_tick);
        
        if (USBC_EXCEPT_INFINITE_TIMEOUT != usbc_except_get_doc()->enum_timeout && 
          ms_passed > usbc_except_get_doc()->enum_timeout) {
            usbc_set_flag(USBC_EXCEPT_ENUM_LOOP_TO);
            usbc_excpet_log_trace(USBC_EXCEPT_CALL_ENUM_LOOP, 0);
            return KAL_FALSE;
        }
#endif  // #if (defined(__MTK_TARGET__) && defined(__PRODUCTION_RELEASE__))
    } while (USBC_USB_STATE_ATTACHED != pUsbCore->state);
    usbc_set_flag(USBC_EXCEPT_ENUM_LOOP_OK);

    usbc_excpet_log_trace(USBC_EXCEPT_CALL_ENUM_LOOP, 1);
    return KAL_TRUE;
}

kal_bool usbc_except_hif_poll(kal_uint8 class_device_id)
{
    usbc_set_flag(USBC_EXCEPT_CALL_HIF_POLL);
    USBC_EXCEPTION_MODE_CHECK();

    hifusb_except_poll_isr();
//    usbc_excpet_log_trace(USBC_EXCEPT_CALL_HIF_POLL, 1);
    return KAL_TRUE;
}

kal_bool 
usbc_except_submit_gpd(
    kal_uint8       class_device_id, 
    kal_uint8       queue_no, 
    void           *p_first_gpd, 
    void           *p_last_gpd)
{
    usbc_core_queue_t  *queue;
    hif_queue_type_e    queue_type;

    usbc_set_flag(USBC_EXCEPT_CALL_SUBMIT_GPD);

    if (!usbc_core_get_queue_info(class_device_id, queue_no, &queue, &queue_type)) {
        usbc_set_flag(USBC_EXCEPT_SUBMIT_GPD_NG);
//        usbc_excpet_log_trace(USBC_EXCEPT_CALL_SUBMIT_GPD, 0);
        return KAL_FALSE;
    }
    usbc_dlog_submit_gpd(queue_type, p_last_gpd);

//    usbc_excpet_log_trace(USBC_EXCEPT_CALL_SUBMIT_GPD, 2);
    return hifusbq_except_set_gpd(queue_type, HIFUSB_EPNO_2_QNO(queue->ep_no), p_first_gpd, p_last_gpd);
}

kal_bool 
usbc_except_poll_queue(
    kal_uint8       class_device_id, 
    kal_uint8       queue_no, 
    void          **pp_first_gpd, 
    void          **pp_last_gpd, 
    kal_uint32     *gpd_num)
{
    usbc_core_queue_t  *queue;
    hif_queue_type_e    queue_type;
    hif_deq_info_t      deq_info;

    usbc_set_flag(USBC_EXCEPT_CALL_POLL_QUEUE);

    if (!usbc_core_get_queue_info(class_device_id, queue_no, &queue, &queue_type)) {
        usbc_set_flag(USBC_EXCEPT_POLL_QUEUE_NG);
//        usbc_excpet_log_trace(USBC_EXCEPT_CALL_POLL_QUEUE, 0);
        return KAL_FALSE;
    }

    kal_mem_set(&deq_info, 0, sizeof(hif_deq_info_t));
    deq_info.q_type = queue_type;
    deq_info.que_no = HIFUSB_EPNO_2_QNO(queue->ep_no);
    deq_info.deq_type = HIFQ_DEQ;

    *gpd_num = hifusbq_except_poll_queue(deq_info, pp_first_gpd, pp_last_gpd);
    usbc_dlog_poll_queue(queue_type, *gpd_num, *pp_last_gpd);

//    usbc_excpet_log_trace(USBC_EXCEPT_CALL_POLL_QUEUE, 1);
    return KAL_TRUE;
}


kal_bool 
usbc_except_hif_state(
    kal_uint8               class_device_id, 
    kal_uint8               queue_no, 
    usbc_except_link_st_e  *link_state)
{
    usbc_core_queue_t  *queue;
    hif_queue_type_e    queue_type;
    kal_uint32          inactive_interval;

    usbc_set_flag(USBC_EXCEPT_CALL_HIF_STATE);

    if (!usbc_core_get_queue_info(class_device_id, queue_no, &queue, &queue_type)) {
        usbc_set_flag(USBC_EXCEPT_HIF_STATE_NG);
//        usbc_excpet_log_trace(USBC_EXCEPT_CALL_HIF_STATE, 0);
        return KAL_FALSE;
    }

    inactive_interval = hifusbq_except_get_txq_timeout(HIFUSB_EPNO_2_QNO(queue->ep_no));
    if (inactive_interval > usbc_except_get_doc()->tx_timeout) {
        usbc_set_flag(USBC_EXCEPT_HIF_STATE_TO);
        *link_state = USBC_LINK_TX_TIMEOUT;
    } else {
        *link_state = USBC_LINK_NO_ERROR;
    }
//    usbc_excpet_log_trace(USBC_EXCEPT_CALL_HIF_STATE, 1);
    return KAL_TRUE;
}

kal_bool usbc_except_reset_flush(
    kal_uint8 class_device_id, kal_uint8 queue_no, void** first_gpd, void** last_gpd, kal_uint32* gpd_num)
{
    usbc_core_queue_t* pQueue = NULL;
    hif_queue_type_e core_queue_hif_type;
    hif_flush_type_e core_queue_flush_type = HIFQ_FLUSH_DEQ;

    usbc_set_flag(USBC_EXCEPT_CALL_FLUSH);
    usbc_except_restart_watchdog();     // Restart watchdog timer to avoid silient reboot

    if (usbc_core_get_queue_info(class_device_id, queue_no, &pQueue, &core_queue_hif_type))
    {
        *gpd_num = hifusbq_except_flush_gpd(core_queue_hif_type, HIFUSB_EPNO_2_QNO(pQueue->ep_no), 
                                            core_queue_flush_type, first_gpd, last_gpd);
    }
    else
    {
        usbc_set_flag(USBC_EXCEPT_FLUSH_NG);
        usbc_excpet_log_trace(USBC_EXCEPT_CALL_FLUSH, 0xFF);
        return KAL_FALSE;
    }

    usbc_excpet_log_trace(USBC_EXCEPT_CALL_FLUSH, (kal_uint8)*gpd_num);
    return KAL_TRUE;
}

