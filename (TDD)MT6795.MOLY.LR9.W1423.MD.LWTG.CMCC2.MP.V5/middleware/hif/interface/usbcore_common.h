/*!
 *  @file usbcore_common.h
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
 *  This file provides common definitions of usbcore
 */

#ifndef _USBCORE_COMMON_H
#define _USBCORE_COMMON_H

#include "qmu_bm.h"
#include "usbc_custom_def.h"
#include "usbc_custom.h"
#include "hif_usb.h"
#include "usbcore_usbstd.h"


/*!
 * @brief Swap the pointed-to 16-bit quantity from USB byte order
 *        (little-endian) to host byte order, in an alignment-safe manner.
 * @param _pData pointer (as unsigned char*)
 * @return quantity in host byte order
 */
#define USBC_EF16P(_pData)  ((*(_pData+1) << 8) | *(_pData))


/*!
 * @brief Swap the pointed-to 24-bit quantity from USB byte order
 *        (little-endian) to host byte order, in an alignment-safe manner.
 * @param _pData pointer (as unsigned char*)
 * @return quantity in host byte order
 */
#define USBC_EF24P(_pData)  ((*(_pData+2) << 16) | (*(_pData+1) << 8) | *(_pData))


/*!
 * @brief Swap the pointed-to 32-bit quantity from USB byte order
 *        (little-endian) to host byte order, in an alignment-safe manner.
 * @param _pData pointer (as unsigned char*)
 * @return quantity in host byte order
 */
#define USBC_EF32P(_pData)  ((*(_pData+3) << 24) | (*(_pData+2) << 16) | (*(_pData+1) << 8) | *(_pData))


/*!
 *  @brief MAX_USBCORE_CLASS_INTERFACE_NUM defines the maximum value of
 *         interface per class device that usbcore can support
 */
#define MAX_USBCORE_CLASS_INTERFACE_NUM     4


/*!
 *  @brief MAX_USBCORE_CLASS_PIPE_NUM defines the maximum value of pipe
 *         per class device that usbcore can support
 */
#define MAX_USBCORE_CLASS_PIPE_NUM          8


/*!
 *  @brief MAX_USBCORE_CONFIG_NUM defines the maximum value of configuration
 *         usbcore can handle
 */
#define MAX_USBCORE_CONFIG_NUM                      8


/*!
 *  @brief MAX_USBCORE_INTERFACE_NUM defines the maximum value of class
 *         interface usbcore can handle
 */
#define MAX_USBCORE_INTERFACE_NUM                   16


/*!
 *  @brief MAX_USBCORE_QUEUE_NUM defines the maximum value of QMU queues
 *         that usbcore can support
 */
#define MAX_USBCORE_QUEUE_NUM                       15


/*!
 *  @brief MAX_USBCORE_STRING_DESCRIPTOR_NUM defines the maximum value of string
 *         descriptors usbcore can handle
 */
#define MAX_USBCORE_STRING_DESCRIPTOR_NUM           254


/*!
 *  @brief MAX_USBCORE_CONTROL_REQUEST_BUFFER_SIZE defines the maximum value
 *         of control request buffer
 */
#define MAX_USBCORE_CONTROL_REQUEST_BUFFER_SIZE     64







#define MAX_USBCORE_CLASS_EPDESC_LENGTH             12
#define MAX_USBCORE_IFDESC_LENGTH                  258  // this will change depends on different class interface, refer to 6280
#define MAX_USBCORE_EPNUM_PER_IF                     3
#define MAX_USBCORE_IAD_NUM                          8



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



/*!
 *  @brief usbc_usb_state_e enumerate possible states of usb device
 *  @param USBC_USB_STATE_MIN           pseudo state
 *  @param USBC_USB_STATE_ATTACHING     start attaching to usb bus
 *  @param USBC_USB_STATE_ATTACHED      attach to usb bus already
 *  @param USBC_USB_STATE_DETACHING     start detaching from usb bus
 *  @param USBC_USB_STATE_DETACHED      detach from usb bus already
 *  @param USBC_USB_STATE_SUSPENDING    start suspending
 *  @param USBC_USB_STATE_SUSPENDED     suspend already
 *  @param USBC_USB_STATE_RESUME        recevie usb resume signal
 *  @param USBC_USB_STATE_RESET         recevie usb bus reset
 *  @param USBC_USB_STATE_MAX           pseudo state
 */
typedef enum _usbc_usb_state {
    USBC_USB_STATE_MIN                  = 0,
    USBC_USB_STATE_ATTACHING            = 1,
    USBC_USB_STATE_ATTACHED             = 2,
    USBC_USB_STATE_DETACHING            = 3,
    USBC_USB_STATE_DETACHED             = 4,
    USBC_USB_STATE_SUSPENDING           = 5,
    USBC_USB_STATE_SUSPENDED            = 6,
    USBC_USB_STATE_RESUME               = 7,
    USBC_USB_STATE_RESET                = 8,
    USBC_USB_STATE_MAX                  = 9,
} usbc_usb_state_e;

/*!
 *  @brief usbc_func_state_e indicate possible states of class device for function suspend
 *  @param USBC_FUNC_WK_ENABLE          to enable function remote wakeup
 *  @param USBC_FUNC_WK_DISABLE         to disable function remote wakeup
 *  @param USBC_FUNC_STATE_SUSPENDING   to suspend a class device
 *  @param USBC_FUNC_STATE_RESUME       to resume a suspended class device
 */
typedef enum _usbc_func_state {
    USBC_FUNC_WK_ENABLE                     = 0,
    USBC_FUNC_WK_DISABLE                    = 1,
    USBC_FUNC_STATE_SUSPENDING              = 5,
    USBC_FUNC_STATE_RESUME                  = 7,
    USBC_FUNC_WK_ENABLE_STATE_SUSPENDING    = 21,
    USBC_FUNC_WK_ENABLE_STATE_RESUME        = 22,
    USBC_FUNC_WK_DISABLE_STATE_SUSPENDING   = 23,
    USBC_FUNC_WK_DISABLE_STATE_RESUME       = 24,
    USBC_FUNC_SET_FEATURE_ERROR             = 25,
} usbc_func_state_e;


/*!
 *  @brief usbc_op_mode_e USB Core operation mode
 *  @param USBC_OP_MODE_UNKNOWN        unknown operation mode
 *  @param USBC_OP_MODE_DETECTION      host and driver detection mode
 *  @param USBC_OP_MODE_NORMAL         normal operation mode
 *  @param USBC_OP_MODE_EXCEPTION      exception mode
 */
typedef enum _usbc_op_mode {
    USBC_OP_MODE_UNKNOWN                = 0,
    USBC_OP_MODE_DETECTION              = 1,
    USBC_OP_MODE_NORMAL                 = 2,
    USBC_OP_MODE_EXCEPTION              = 3,
} usbc_op_mode_e;


/*!
 *  @brief usbc_usb_speed_e enumerate possible speed of usb device
 *  @param USBC_USB_SPEED_MIN           pseudo speed
 *  @param USBC_USB_SPEED_USB11         usb 1.1 full speed
 *  @param USBC_USB_SPEED_USB20         usb 2.0 high speed
 *  @param USBC_USB_SPEED_USB30         usb 3.0 super speed
 *  @param USBC_USB_SPEED_MAX           pseudo speed
 */
typedef enum _usbc_usb_speed {
    USBC_USB_SPEED_MIN                  = 0,
    USBC_USB_SPEED_USB11                = 1,
    USBC_USB_SPEED_USB20                = 2,
    USBC_USB_SPEED_USB30                = 3,
    USBC_USB_SPEED_MAX                  = 4,
} usbc_usb_speed_e;


/*!
 *  @brief usbc_request_owner_e enumerate all possible types of usb control
 *         request type
 *  @param USBC_CONTROL_REQUEST_TYPE_MIN        pseudo type
 *  @param USBC_CONTROL_REQUEST_TYPE_SEND       request to send
 *  @param USBC_CONTROL_REQUEST_TYPE_RECEIVE    request to receive
 *  @param USBC_CONTROL_REQUEST_TYPE_STALL      request to stall
 *  @param USBC_CONTROL_REQUEST_TYPE_MAX        pseudo type
 */
typedef enum _usbc_control_request_type {
    USBC_CONTROL_REQUEST_TYPE_MIN       = 0,
    USBC_CONTROL_REQUEST_TYPE_SEND      = 1,
    USBC_CONTROL_REQUEST_TYPE_RECEIVE   = 2,
    USBC_CONTROL_REQUEST_TYPE_STALL     = 3,
    USBC_CONTROL_REQUEST_TYPE_MAX       = 4,
} usbc_control_request_type_e;


/*!
 *  @brief usbc_interface_type_e enumerate support list of interface types
 *  @param USBC_INTERFACE_TYPE_MIN              pseudo interface
 *  @param USBC_INTERFACE_TYPE_CDC_ACM_CONTROL  CDC ACM control interface
 *  @param USBC_INTERFACE_TYPE_CDC_ACM_DATA     CDC ACM data interface
 *  @param USBC_INTERFACE_TYPE_RNDIS_CONTROL    RNDIS control interface
 *  @param USBC_INTERFACE_TYPE_RNDIS_DATA       RNDIS data interface
 *  @param USBC_INTERFACE_TYPE_MAX              pseudo interface
 */
typedef enum _usbc_interface_type {
    USBC_INTERFACE_TYPE_MIN                         = 0x0,
    USBC_INTERFACE_TYPE_CDC_ACM_CONTROL             = 0x1,
    USBC_INTERFACE_TYPE_CDC_ACM_DATA                = 0x2,
    USBC_INTERFACE_TYPE_RNDIS_CONTROL               = 0x3,
    USBC_INTERFACE_TYPE_RNDIS_DATA                  = 0x4,
    USBC_INTERFACE_TYPE_MBIM_CONTROL                = 0x5,
    USBC_INTERFACE_TYPE_MBIM_DATA                   = 0x6,
    USBC_INTERFACE_TYPE_MSD_CONTROL                 = 0x7,
    USBC_INTERFACE_TYPE_MSD_DATA                    = 0x8,
    USBC_INTERFACE_TYPE_CDC_ECM_CONTROL               = 0x9,
    USBC_INTERFACE_TYPE_CDC_ECM_DATA                  = 0xA,    
    USBC_INTERFACE_TYPE_MAX
} usbc_interface_type_e;


/*!
 *  @brief usbc_pipe_type_e enumerate all possible types of usb classs
 *         device pipe
 *  @param USBC_PIPE_TYPE_MIN                   pseudo type
 *  @param USBC_PIPE_TYPE_CDC_ACM_DATA_IN       CDC ACM data in pipe
 *  @param USBC_PIPE_TYPE_CDC_ACM_COMM_IN       CDC ACM comm in pipe
 *  @param USBC_PIPE_TYPE_CDC_ACM_DATA_OUT      CDC ACM data out pipe
 *  @param USBC_PIPE_TYPE_GCOM_DATA_IN          Generic COM data in pipe
 *  @param USBC_PIPE_TYPE_GCOM_DATA_OUT         Generic COM data out pipe
 *  @param USBC_PIPE_TYPE_CDC_ECM_DATA_IN       CDC ECM data in pipe
 *  @param USBC_PIPE_TYPE_CDC_ECM_COMM_IN       CDC ECM comm in pipe
 *  @param USBC_PIPE_TYPE_CDC_ECM_DATA_OUT      CDC ECM data out pipe
 *  @param USBC_PIPE_TYPE_RNDIS_DATA_IN         RNDIS data in pipe
 *  @param USBC_PIPE_TYPE_RNDIS_COMM_IN         RNDIS comm in pipe
 *  @param USBC_PIPE_TYPE_RNDIS_DATA_OUT        RNDIS data out pipe
 *  @param USBC_PIPE_TYPE_MASS_STORAGE_DATA_IN  Mass Storage data in pipe
 *  @param USBC_PIPE_TYPE_MASS_STORAGE_DATA_OUT Mass Storage data out pipe
 *  @param USBC_PIPE_TYPE_MAX                   pseudo type
 */
typedef enum _usbc_pipe_type {
    USBC_PIPE_TYPE_MIN                      = 0,
    USBC_PIPE_TYPE_CDC_ACM_DATA_IN          = 1,
    USBC_PIPE_TYPE_CDC_ACM_COMM_IN          = 2,
    USBC_PIPE_TYPE_CDC_ACM_DATA_OUT         = 3,
    USBC_PIPE_TYPE_GCOM_DATA_IN             = 4,
    USBC_PIPE_TYPE_GCOM_DATA_OUT            = 5,
    USBC_PIPE_TYPE_CDC_ECM_DATA_IN          = 6,
    USBC_PIPE_TYPE_CDC_ECM_COMM_IN          = 7,
    USBC_PIPE_TYPE_CDC_ECM_DATA_OUT         = 8,
    USBC_PIPE_TYPE_RNDIS_DATA_IN            = 9,
    USBC_PIPE_TYPE_RNDIS_COMM_IN            = 10,
    USBC_PIPE_TYPE_RNDIS_DATA_OUT           = 11,
    USBC_PIPE_TYPE_MASS_STORAGE_DATA_IN     = 12,
    USBC_PIPE_TYPE_MASS_STORAGE_DATA_OUT    = 13,
    USBC_PIPE_TYPE_MBIM_DATA_IN             = 14,
    USBC_PIPE_TYPE_MBIM_COMM_IN             = 15,
    USBC_PIPE_TYPE_MBIM_DATA_OUT            = 16,
    USBC_PIPE_TYPE_MAX
} usbc_pipe_type_e;










/*!
 *  @brief usbc_core_class_device_state_e enumerate all possible states of
 *         class device in USBCORE module
 *  @param USBC_CORE_CLASS_DEVICE_STATE_MIN         pseudo state
 *  @param USBC_CORE_CLASS_DEVICE_STATE_NOTEXIST    this device is not existed
 *  @param USBC_CORE_CLASS_DEVICE_STATE_INITIATED   this device is initiated 
 *  @param USBC_CORE_CLASS_DEVICE_STATE_REGISTERED  this device is registered
 *  @param USBC_CORE_CLASS_DEVICE_STATE_MAX         pseudo state
 */
typedef enum _usbc_core_class_device_state {
    USBC_CORE_CLASS_DEVICE_STATE_MIN        = 0,
    USBC_CORE_CLASS_DEVICE_STATE_NOTEXIST   = 1,
    USBC_CORE_CLASS_DEVICE_STATE_INITIATED  = 2,
    USBC_CORE_CLASS_DEVICE_STATE_REGISTERED = 3,
    USBC_CORE_CLASS_DEVICE_STATE_MAX        = 4,
} usbc_core_class_device_state_e;


/*!
 *  @brief usbc_core_class_interface_state_e enumerate all possible states of
 *         class interface in USBCORE module
 *  @param USBC_CORE_CLASS_INTERFACE_STATE_MIN          pseudo state
 *  @param USBC_CORE_CLASS_INTERFACE_STATE_DISABLE      this interface is disabled
 *  @param USBC_CORE_CLASS_INTERFACE_STATE_INITIATED    this interface is initiated
 *  @param USBC_CORE_CLASS_INTERFACE_STATE_ACTIVE       this interface is actived
 *  @param USBC_CORE_CLASS_INTERFACE_STATE_MAX          pseudo state
 */
typedef enum _usbc_core_class_interface_state {
    USBC_CORE_CLASS_INTERFACE_STATE_MIN         = 0,
    USBC_CORE_CLASS_INTERFACE_STATE_DISABLE     = 1,
    USBC_CORE_CLASS_INTERFACE_STATE_INITIATED   = 2,
    USBC_CORE_CLASS_INTERFACE_STATE_ACTIVE      = 3,
    USBC_CORE_CLASS_INTERFACE_STATE_MAX         = 4,
} usbc_core_class_interface_state_e;


/*!
 *  @brief usbc_core_queue_state_e enumerate all possible states of QMU Queue
 *         in USBCORE module
 *  @param USBC_CORE_QUEUE_STATE_MIN        pseudo state
 *  @param USBC_CORE_QUEUE_STATE_DISABLE    this queue is not used
 *  @param USBC_CORE_QUEUE_STATE_INITIATED  this queue is initiated
 *  @param USBC_CORE_QUEUE_STATE_ACTIVE     this queue is enabled,and used
 *  @param USBC_CORE_QUEUE_STATE_STALL      this queue is enabled,but stalled
 *  @param USBC_CORE_QUEUE_STATE_MAX        pseudo state
 */
typedef enum _usbc_core_queue_state {
    USBC_CORE_QUEUE_STATE_MIN               = 0,
    USBC_CORE_QUEUE_STATE_DISABLE           = 1,
    USBC_CORE_QUEUE_STATE_INITIATED         = 2,
    USBC_CORE_QUEUE_STATE_ACTIVE            = 3,
    USBC_CORE_QUEUE_STATE_STALL             = 4,
    USBC_CORE_QUEUE_STATE_MAX               = 5,
} usbc_core_queue_state_e;


/*!
 *  @brief usbc_io_request_t is a typedef of struct _usbc_io_request
 */
typedef struct _usbc_io_request usbc_io_request_t;
/*!
 *  @brief struct _usbc_io_request describe usbc io request used to communicate
 *         usb class device and usbcore
 */
struct _usbc_io_request {
    /*!
     *  @brief next io request
     */
    usbc_io_request_t*      next_request;
    /*!
     *  @brief pointer to current gpd of this io request
     */
    qbm_gpd*                first_gpd;
    /*!
     *  @brief pointer to last gpd of this io request
     */
    qbm_gpd*                last_gpd;
};


/*!
 *  @brief usbc_core_queue_t describe queue information maintain within usbcore
 */
typedef struct _usbc_core_queue {

    /*!
     *  @brief current queue state of this queue
     */
    usbc_core_queue_state_e     state;
    /*!
     *  @brief id of class device that own this queue
     */
    kal_uint8                   class_device_id;
    /*!
     *  @brief pipe type of this queue
     */
    usbc_pipe_type_e            pipe_type;
    /*!
     *  @brief usb transfer type of this queue
     */
    hifusb_usb_xfer_type_e      xfer_type;
    /*!
     *  @brief endpoint number of this queue
     */
    kal_uint8                   ep_no;
    /*!
     *  @brief maximum packet size of this queue
     */
    kal_uint16                  max_packet_size;
    /*!
     *  @brief fifo type is DOUBLE FIFO or not
     */
    kal_bool                    double_fifo;
    kal_uint8                   rsvd[3];
    /*!
     *  @brief queue configuration
     */
    kal_uint32                  config;
    /*!
     *  @brief complete function to notify class device
     */
    void                        (*notify_complete)(kal_uint8 class_deivce_id, usbc_io_request_t* io_request);
    /*!
     *  @brief callback function to notify class device queue is stall or not
     */
    void                        (*notify_stall)(kal_uint8 class_device_id, kal_bool stall);
} usbc_core_queue_t;

typedef struct _usbc_endpoint_info_t {

    /*!
     *  @brief Descriptor length
     */
    kal_uint16                             epdscr_size;
    
    /*!
     *  @brief Endpoint descriptor
     */
    union {
        usbc_endpoint_descriptor_t         stdep;
        kal_uint8                          classep[MAX_USBCORE_CLASS_EPDESC_LENGTH];
    } epdscr;

    usbc_core_queue_t                      queue_info;
} usbc_endpoint_info_t;

typedef struct _usbc_alternate_interface_info_t {
    /*!
     *  @brief Descriptor length
     */
    kal_uint16                             ifdscr_size;

    union {
        usbc_interface_descriptor_t        stdif;
        kal_uint8                          classif[MAX_USBCORE_IFDESC_LENGTH];
    } ifdscr;

    usbc_endpoint_info_t                   *ep_info[MAX_USBCORE_EPNUM_PER_IF];
    
} usbc_alternate_interface_info_t;

/*!
 *  @brief usbc_core_class_interface_t describe class interface information
 *         maintain within usbcore
 */
typedef struct _usbc_core_class_interface_t {
    /*!
     *  @brief interace number of this interface
     */
    kal_uint8                           interface_no;
    /*!
     *  @brief interace type of this interface
     */
    usbc_interface_type_e               interface_type;
    /*!
     *  @brief id of class device that own this interface
     */
    kal_uint8                           class_device_id;
    /*!
     *  @brief current state of this interface
     */
    usbc_core_class_interface_state_e   state;
    /*!
     *  @brief bAlternateSetting of this interface
     */
    kal_uint8                           alternate_setting;
    kal_uint8                           rsvd[3];
    /*!
     *  @brief callback function while control tranfer for this device
     *         is received
     */
    void                                (*notify_control_setup_packet)(kal_uint8 class_device_id, usbc_setup_packet_t* packet);
    /*!
     *  @brief callback function while control tranfer is complete
     */
    void                                (*notify_control_complete)(kal_uint8 class_device_id);
    /*!
     *  @brief callback function while interface alternate setting is set
     */
    void                                (*notify_alternate_setting)(kal_uint8 class_device_id, usbc_interface_type_e inteface, kal_uint8 alternate_setting);

} usbc_core_class_interface_t;

/*!
 *  @brief usbc_core_class_interface_t describe class interface information
 *         maintain within usbcore
 */
typedef struct _usbc_interface_info_t {

    usb_class_type_e                       type;

    /*!
     *  @brief Descriptor length
     */
    kal_uint16                             ifdscr_size;

    /*!
     *  @brief Interface descriptor
     */
    union {
        usbc_interface_descriptor_t        stdif;
        kal_uint8                          classif[MAX_USBCORE_IFDESC_LENGTH];
    } ifdscr;

    usbc_endpoint_info_t                   *ep_info[MAX_USBCORE_EPNUM_PER_IF];

    kal_bool                               altn_surpport; // FALSE (no alternate setting) or TRUE (has alternate setting)
    usbc_alternate_interface_info_t        altn_if_info;

    usbc_core_class_interface_t            class_interface;

} usbc_interface_info_t;

/*!
 *  @brief usbc_class_device_instance_t describe instance of a
 *         generic usb class device
 */
typedef struct _usbc_class_device_instance {
    /*!
    *   @brief instance id of this device
    */
    kal_uint8               id;

    /*!
     *  @brief current usb speed of this device
     */
    kal_uint8               speed;
    /*!
     *  @brief total_interfaces for this class device
     */
    kal_uint8               total_interfaces;
    kal_uint8               rsvd[1];
    /*!
     *  @brief per class device context
     */
    void                   *context;
    /*!
     *  @brief qmu queue no for each pipe
     */
    kal_uint8               queue_no_for_pipe[MAX_USBCORE_CLASS_PIPE_NUM];
    /*!
     *  @brief interface type of each interface for this class device
     */
    usbc_interface_type_e   interface_type[MAX_USBCORE_CLASS_INTERFACE_NUM];
    /*!
     *  @brief interface number of each interface for this class device
     */
    kal_uint8               interface_no[MAX_USBCORE_CLASS_INTERFACE_NUM];
} usbc_class_device_instance_t;

/*!
 *  @brief usbc_io_req_type_e Type of operation to for requests to submit to USB HIF.
 *  @param USBC_IO_TX_NO_FLUSH                  Transmit operation without GPD checksum calcuation and cache flush.
 */
typedef enum _usbc_io_req_type {
     USBC_IO_TX_NO_FLUSH        = 0x00000010,
     USBC_IO_TYPE_DUMMY         = 0x7fffffff
} usbc_io_req_type_e;

/*!
 *  @brief usbc_io_ext_info_t Configurations apply to the requests to submit to USB HIF.
 *  @param type               Type of operation.
 */
typedef struct _usbc_io_ext_info {
     usbc_io_req_type_e   type;
} usbc_io_ext_info_t;


/*
 * @brief Settings of each type of node to checkin.
 */
typedef struct {
    void       *init_func; /* iniitialize descriptor function pointer. */
    void       *set_config_func; /* initialize configuration function pointer */
    void       *reinit_func; /* reinit function pointer */
    void       *query_func_wk_capability;   /*  callback function to remote wakeup capability of class device */
} usbc_node_reg_entry_t;

typedef kal_int32 (*usbc_class_init_func_t)(kal_uint8 class_device_id, usb_mode_e mode, kal_uint32 config_index, void *context, kal_uint32 flag);
typedef kal_int32 (*usbc_class_set_config_func_t)(kal_uint8 class_device_id, kal_uint32 config_index, void *context);
typedef void (*usbc_class_reinit_func_t)(kal_bool need_check_in);
typedef kal_uint16 (*usbc_class_query_func_wk_capability_func_t)(void);


usbc_class_set_config_func_t usbc_get_class_set_config_func(usb_class_type_e type);

/*!
 *  @brief  Add a node into USB stack, the USB stack will start loading configuration,
 *          initializing corresponding modules.
 *          Running Level: TASK INIT
 *  @param  node     Node of USB stack.
 *  @param  reg_table An array of settings. The last entry is ended with type=USBC_NODE_REG_ENTRY_END_TYPE.
 */
void usbc_stack_checkin(usb_class_type_e func_type, usbc_node_reg_entry_t *reg_table);

void usbc_mode_switch(usb_mode_e mode);

void usbc_reinit_class(void);

#endif  // _USBCORE_COMMON_H

