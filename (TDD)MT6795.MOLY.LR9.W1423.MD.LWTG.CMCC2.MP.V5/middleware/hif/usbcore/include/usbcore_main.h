/*!
 *  @file usbcore_main.h
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
 *  This file provides main definitions of usbcore
 */

#ifndef _USBCORE_MAIN_H
#define _USBCORE_MAIN_H

#include "usbcore_common.h"
#include "hif_usb.h"
#include "usbcore_usbstd.h"
#include "usbcore_class_device.h"
#include "hifusb_qmu.h"

//#define __USBCORE_DEBUG__

#ifdef __USBCORE_DEBUG__
#define usbc_core_printf        kal_printf
#else
#if defined(__MTK_TARGET__)
#define usbc_core_printf(fmt, args...)
#else
#define usbc_core_printf(fmt, ...)
#endif
#endif

#define __USBCORE_CHECK__
#ifdef __USBCORE_CHECK__
    #define USBC_IS_IN_EXCEPTION_MODE() \
                ( USBC_OP_MODE_EXCEPTION == usbc_get_op_mode() )
    
    #define USBC_EXCEPTION_MODE_CHECK() \
                ASSERT( USBC_IS_IN_EXCEPTION_MODE() )
    
    #define USBC_NON_EXCEPTION_MODE_CHECK() \
                ASSERT( !USBC_IS_IN_EXCEPTION_MODE() )
    
    #define USBC_CORE_INSTANCE_CHECK(_inst) \
                ASSERT( NULL != (_inst))
#else
    #define USBC_IS_IN_EXCEPTION_MODE() 
    
    #define USBC_EXCEPTION_MODE_CHECK() 
    
    #define USBC_NON_EXCEPTION_MODE_CHECK()
    
    #define USBC_CORE_INSTANCE_CHECK(_inst) 
#endif

#define USBC_CLASS_DEVICE_CONTEXT_CHECK() \
            ASSERT(!kal_if_hisr())

/*!
 *  @brief MAX_USBCORE_DEVICE_NUM defines the maximum value of class
 *         devices usbcore can handle
 */
#define MAX_USBCORE_DEVICE_NUM                      8

/*!
 *  @brief KAL ticks for resending function remote wakeup notification
 */
#define USBC_WK_NOTIFY_CHECK_TICKS                  542


/*!
 *  @brief KAL ticks duration for checking device resuming
 */
#define USBC_DEV_RESUME_DURATION_TICK               2

/*!
 *  @brief KAL event scheduler for function wakreup notification tiemout
 */
#define USBC_WK_NOTIFY_INDEX                        1

/*!
 * @breif Warpper for KAL enhanced mutex
 */
#define USBC_CLASS_REMOTE_WK_LOCK(_s)   kal_take_enh_mutex(_s)
#define USBC_CLASS_REMOTE_WK_UNLOCK(_s) kal_give_enh_mutex(_s)


/*!
 * @brief configruation read from HMU.
 */
typedef struct _usbc_hmu_info {
    /*!
     *  @brief USB enumeration tiemout in unit of ms.
     */
    kal_uint32                          enum_timeout; 
    /*!
     *  @brief Tx transfer tiemout in unit of ms.
     */
    kal_uint32                          tx_timeout; 
} usbc_hmu_info_t;

/*
 *  @brief USB descriptors compiled.
 */
typedef struct _usbc_descriptors_t {
    kal_uint8                   device[USBC_DEVICE_DESC_SIZE];
    kal_uint8                   configuration[MAX_USBCORE_CONFIG_NUM][USBC_MAX_CONF_SIZE];
} usbc_descriptors_t;


/*!
 *  @brief usbc_core_class_device_t describe class device information maintain
 *         within usbcore
 */
typedef struct _usbc_core_class_device_t {
    /*!
     *  @brief class type of this device
     */
    usb_class_type_e                    class_type;
    /*!
     *  @brief current state of this device
     */
    usbc_core_class_device_state_e      state;
    /*!
     *  @brief total pipes of this device
     */
    kal_uint8                           total_pipes;
    kal_uint8                           rsvd[1];
    /*!
     *  @brief returning device instance to class driver
     */
    usbc_class_device_instance_t        device_instance;
    /*!
     *  @brief callback function while usb state changed
     */
    void                                (*notify_usb_state)(kal_uint8 class_device_id, usbc_usb_state_e state);
    /*!
     *  @brief callback function while usb speed changed
     */
    void                                (*notify_usb_speed)(kal_uint8 class_device, usbc_usb_speed_e speed);
    /*!
     *  @brief the status of the class device
     */
    kal_bool                            is_func_suspend;
    /*!
     *  @brief callback function while set or clear function remote wakeup ability
     */
     void                               (*notify_func_wk_ability)(kal_uint8 class_device_id, kal_bool ability);
    /*!
     *  @brief callback function to known the class device status
     */
     kal_uint16                         (*query_func_wk_status)(kal_uint8 class_device_id);
} usbc_core_class_device_t;

/*!
 *  @brief usbc_core_t describe main structure of usbcore
 */
typedef struct _usbc_core {
    /*!
     * @brief HMU events indication that USBCORE task is going to wait
     */
    kal_uint32                          hmu_indication;

    usb_mode_e                          mode;
    kal_bool                            is_mode_switch;

    /*!
     *  @brief current usb speed
     */
    usbc_usb_speed_e                    speed;
    /*!
     *  @brief current usb state
     */
    usbc_usb_state_e                    state;
    /*!
     *  @brief KAL_TRUE if the setup_packet will be handled by USBCLASS; KAL_FALSE if it has been handled by USBCORE.
     */
    kal_bool                            setup_indicated;
    kal_uint8                           rsvd0[1];
    /*!
     *  @brief current setup packet
     */
    usbc_setup_packet_t                 setup_packet;
    /*!
     *  @brief control request buffer to send or receive
     */
    kal_uint8                           control_request_buffer[MAX_USBCORE_CONTROL_REQUEST_BUFFER_SIZE];

    /*!
     *  @brief current device qualifier descriptor
     */
    usbc_device_qualifier_descriptor_t  device_qualifier_descriptor;

    /* device parameter got from usb custom */
	usb_dev_param_t*                    dev_param;

    /* get the ability of morhping from NVRAM */
    kal_bool                            morphing_enable;

    /* Resource */
    kal_uint8                           resource_interface_number[MAX_USBCORE_CONFIG_NUM];
    kal_uint8                           resource_string_number;
    kal_uint8                           resource_iad_number[MAX_USBCORE_CONFIG_NUM];
    kal_uint8                           resource_ep_tx_number[MAX_USBCORE_CONFIG_NUM];
    kal_uint8                           resource_ep_rx_number[MAX_USBCORE_CONFIG_NUM];
    usbc_interface_info_t               if_info[MAX_USBCORE_CONFIG_NUM][MAX_USBCORE_INTERFACE_NUM];
    usbc_interface_association_descriptor_t   iad_descriptor[MAX_USBCORE_CONFIG_NUM][MAX_USBCORE_IAD_NUM];
    usbc_endpoint_info_t                ep_tx_info[MAX_USBCORE_CONFIG_NUM][MAX_USBCORE_QUEUE_NUM];
    usbc_endpoint_info_t                ep_rx_info[MAX_USBCORE_CONFIG_NUM][MAX_USBCORE_QUEUE_NUM];

    /*!
     *  @brief current string descriptor
     */
    usbc_string_descriptor_t*           string_descriptor[MAX_USBCORE_STRING_DESCRIPTOR_NUM];

    /*!
     *  @brief current usb address in Set Address Request
     */
    kal_uint8                           usb_address;
    /*!
     *  @brief current selected configuration in Set Configuration Request
     */
    kal_uint8                           usb_configuration;

    /*!
     *  @brief total configurated class devices
     */
    kal_uint8                           total_class_devices;
    /*!
     *  @brief total configurated class interfaces
     */
    kal_uint8                           total_class_interfaces;
    /*!
     *  @brief total configurated transmit queues
     */
    kal_uint8                           total_tx_queues;
    /*!
     *  @brief total configurated receive queues
     */
    kal_uint8                           total_rx_queues;

    /*!
     *  @brief class device information
     */
    usbc_core_class_device_t            class_device[MAX_USBCORE_DEVICE_NUM];

    /*!
     *  @brief class interface information
     */
    usbc_core_class_interface_t         class_interface[MAX_USBCORE_INTERFACE_NUM];
    /*!
     *  @brief transmit queue information
     */
    usbc_core_queue_t                   tx_queue[MAX_USBCORE_QUEUE_NUM];
    /*!
     *  @brief receive queue information
     */
    usbc_core_queue_t                   rx_queue[MAX_USBCORE_QUEUE_NUM];

    /*!
     *  @brief USB descriptors compiled.
     */
    usbc_descriptors_t                  descriptors;

    kal_bool                            morph_active;

    /*!
     *  @brief current status of device
     */
    kal_bool                            is_device_u1_enable;
    kal_bool                            is_device_u2_enable;
    kal_bool                            is_device_ltm_enable;

    /*!
     *  @brief MUTEX for remote wakeup
     */
    kal_enhmutexid                      usbc_class_remote_wk_mutex;

    /*!
     * @brief keep the information for device suspend after function suspend
     */
    event_scheduler*                    usbc_es_wk_notify_g;
    kal_bool                            func_notify_list[MAX_USBCORE_DEVICE_NUM];
    eventid                             wk_eventid;
    kal_enhmutexid                      usbc_class_renotify_mutex;
    kal_bool                            is_func_be_accessed[MAX_USBCORE_DEVICE_NUM];
    kal_enhmutexid                      usbc_class_func_access_mutex;

    /*!
     * @brief Check for META mode
     */
    kal_bool                            is_mode_meta;
    kal_bool                            is_mode_meta_reused;

    /*!
     * @brief bMaxPower for USB 3.0 configuratyion
     */
    kal_uint8                           u3ConfMaxPower;
} usbc_core_t;


/*!
 *  @brief  switch USBCORE operation mode.
 *  @return current USBCORE operation mode, see usbc_op_mode_e for more information.
 */
usbc_op_mode_e usbc_get_op_mode(void);


/*!
 *  @brief  set USBCORE operation mode.
 *  @param op_mode USBCORE operation mode to set, see usbc_op_mode_e for more information.
 */
void usbc_set_op_mode(usbc_op_mode_e op_mode);


/*!
 *  @brief  get instance of USBCORE module
 *  @return pointer to usbc_core_t* instance if success, NULL if fail
 */
usbc_core_t *usbc_core_get_instance(void);


/*!
 *  @brief  get settings read from HMU
 *  @return pointer the usbc_hmu_info_t object for these setting.
 */
usbc_hmu_info_t *usbc_core_get_hmu_info(void);


/*!
 *  @brief force returning to non-register state
 */
void usbc_core_clear_register(void);


/*!
 *  @brief notify all existed class drivers that usb state is changed to
 *         attaching
 */
void usbc_core_notify_state_attaching(void);


/*!
 *  @brief notify all existed class drivers that usb state is changed to
 *         attached
 */
void usbc_core_notify_state_attached(void);


/*!
 *  @brief notify all existed class drivers that usb state is changed to
 *         detaching
 */
void usbc_core_notify_state_detaching(void);


/*!
 *  @brief notify all existed class drivers that usb state is changed to
 *         suspending
 */
void usbc_core_notify_state_suspending(void);


/*!
 *  @brief notify all existed class drivers that usb state is changed to
 *         resume
 */
void usbc_core_notify_state_resume(void);


/*!
 *  @brief notify all existed class drivers that usb state is changed to
 *         reset
 */
void usbc_core_notify_state_reset(void);


/*!
 *  @brief notify all existed class drivers that usb speed is changed
 *  @param  speed new USB link speed
 */
void usbc_core_notify_speed_change(usbc_usb_speed_e speed);


/*!
 *  @brief notify the interface that its alternate setting is set by host
 *  @param  intf_idx indext to the interface
 *  @param  alternate_setting alternate setting set by host
 */
void usbc_core_notify_alternate_setting(kal_uint8 intf_idx, kal_uint8 alternate_setting);


/*!
 *  @brief notify the endpoint that its HALT state is changed by host
 *  @param  is_tx KAL_TURE for OUT endpoint; KAL_FALSE for IN endpoint
 *  @param  queue_idx internal queue index of the endpoint
 *  @param  stall KAL_TRUE if it's been set STALL; KAL_FALSE if it's been cleared STALL
 */
void usbc_core_notify_stall(kal_bool is_tx, kal_uint8 queue_idx, kal_bool stall);


/*!
 *  @brief handle usb standard request
 */
kal_bool usbc_core_handle_standard_request(void);

/*!
 *  @brief handle usb vendor request
 */
void usbc_core_handle_vendor_request(void);


/*!
 *  @brief  Modify descriptors according to current USB speed.
 *  @param  pUsbCore USB Core context
 *  @param  speed Current USB speed
 */
void usbc_core_descriptors_speed_change(usbc_core_t *pUsbCore, usbc_usb_speed_e speed);


/*!
 *  @brief  Internal implementaion of usb class device registration
 *  @param class_device_id  [IN] USB class device instance id
 *  @param  pUsbCore USB Core context
 *  @param  device_info class device information used to register
 *  @return new instance of usb class device if success, NULL if fail
 */
usbc_class_device_instance_t *usbc_core_device_register(kal_uint8 class_device_id, usbc_core_t *pUsbCore, usbc_class_device_info_t *device_info);


/*!
 *  @brief  Query information about the queue of an USB calss device instance.
 *  @param class_device_id  [IN] USB class device instance id
 *  @param queue_no         [IN] Queue number to query
 *  @param queue            [OUT] Caller allocated space for a pointer to the queue object. Its value is invalid if no matched queue found.
 *  @param queue_type       [OUT] Type of the queue. Its value is invalid if no matched queue found.
 *  @return KAL_TURE if matched queue found; KAL_FALSE otherwise.
 */
kal_bool usbc_core_get_queue_info(kal_uint8 class_device_id, kal_uint8 queue_no, usbc_core_queue_t **queue, hif_queue_type_e *queue_type);


/*!
 *  @brief clear device status and function status to default setting
 */
void usbc_core_clear_status(void);


/*!
 *  @brief check if the given interface is the first one of any functions
 */
kal_bool usbc_core_is_1st_interface(kal_uint8 idx);


/*!
 *  @brief get the first interface of the given function
 */
kal_uint8 usbc_class_device_get_1st_interface(kal_uint8 class_device_id);


/*!
 *  @brief Notify the requested class driver that usb state is changed to suspending
 *  @param idx              [IN] USB class_device_id
 */
void usbc_core_notify_function_state_suspending(kal_uint8 class_device_id);


/*!
 *  @brief notify the requested class driver that usb state is changed to resume
 *  @param idx              [IN] USB class_device_id
 */
void usbc_core_notify_function_state_resume(kal_uint8 class_device_id);


/*!
 *  @brief notify the requested class driver to enable or disable function remote wakeup
 *  @param idx              [IN] USB class_device_id
 *  @param ability          [IN] Enable or disable the function remote wakeup capability. KAL_TRUE for enable, and KAL_FALSE for disable.
 */
void usbc_core_notify_func_wk_ability(kal_uint8 class_device_id, kal_bool ability);


/*!
 *  @brief get the bitmap of functions that enable remote wakeup
 *  @return the bit map of funtions that enable remote wakeup
 */
kal_uint8 usbc_core_get_function_remote_wk_list(void);

/*!
 *  @brief get the bitmap of functions that are suspended
 *  @return the bit map of funtions that are suspended
 */
kal_uint8 usbc_core_get_function_suspend_list(void);

/*!
 *  @brief set IMEI as the serial number of USB device descriptor
 */
kal_bool usbc_core_set_serial_number(void);
#endif  // _USBCORE_MAIN_H

