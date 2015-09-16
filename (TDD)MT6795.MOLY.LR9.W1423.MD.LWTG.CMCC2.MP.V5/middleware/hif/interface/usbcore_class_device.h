/*!
 *  @file usbcore_class_device.h
 *  @author Roger Huang <chaomin.haung@mediatek.com>
 *  @version 1.2
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
 *  This file provides application interface of usbcore for class device
 */

#ifndef _USBCORE_CLASS_DEVICE_H
#define _USBCORE_CLASS_DEVICE_H

#include "usbcore_common.h"
#include "usbcore_usbstd.h"


/*!
 *  @brief usbc_class_device_info_t describe register information of a
 *         generic usb class device
 */
typedef struct _usbc_class_device_info {

    /*!
     *  @brief class type of this device
     */
    usb_class_type_e        class_type;
    /*!
     *  @brief total pipes of this device
     */
    kal_uint8               total_pipes;
    /*!
     *  @brief reserve for 4 bytes alignment
     */
    kal_uint8               reserve[2];
    /*!
     *  @brief per class device context
     */
    void                   *class_device_context;
    /*!
     *  @brief each pipe type of this device
     */
    usbc_pipe_type_e        pipe_type[MAX_USBCORE_CLASS_PIPE_NUM];
    /*!
     *  @brief callback function while usb state changed.
     *         Running Level: TASK
     */
    void                    (*notify_usb_state)(kal_uint8 class_device_id, usbc_usb_state_e state);
    /*!
     *  @brief callback function while usb speed changed.
     *         Running Level: TASK
     */
    void                    (*notify_usb_speed)(kal_uint8 class_device_id, usbc_usb_speed_e speed);
    /*!
     *  @brief callback function while control tranfer for this device
     *         is received
     *         Running Level: TASK
     */
    void                    (*notify_control_setup_packet)(kal_uint8 class_device_id, usbc_setup_packet_t* packet);
    /*!
     *  @brief callback function while control tranfer is complete
     *         Running Level: TASK
     */
    void                    (*notify_control_complete)(kal_uint8 class_device_id);
    /*!
     *  @brief callback function while interface alternate setting is set
     *         Running Level: TASK
     */
    void                    (*notify_alternate_setting)(kal_uint8 class_device_id, usbc_interface_type_e inteface, kal_uint8 alternate_setting);
    /*!
     *  @brief callback function while each pipe tranfer is complete
     *         Running Level: TASK
     */
    void                    (*notify_pipe_complete[MAX_USBCORE_CLASS_PIPE_NUM])(kal_uint8 class_device_id, usbc_io_request_t* io_request);
    /*!
     *  @brief callback function to indicate pipe is stall or not
     *         Running Level: TASK
     */
    void                    (*notify_pipe_stall[MAX_USBCORE_CLASS_PIPE_NUM])(kal_uint8 class_device_id, kal_bool stall);
    /*!
     *  @brief callback function to notify a function enable/disable function remote wakeup
     */
    void                    (*notify_func_wk_ability)(kal_uint8 class_device_id, kal_bool ability);
    /*!
     *  @brief callback function to query the status of class device
     */
    kal_uint16              (*query_func_wk_status)(kal_uint8 class_device_id);
} usbc_class_device_info_t;

typedef struct _usbc_class_device_esl_connect_parm {
    LOCAL_PARA_HDR
    kal_uint8   class_device_id;
} usbc_class_device_esl_connect_parm;

/*!
 *  @brief  register new usb class device to usbcore
 *          Running Level: TASK INIT/TASK 
 *  @param  class_device_id  device instance id to register
 *  @param  device_info class device information used to register
 *  @param  class_device_id device instance id obtained while register 
 *  @return new instance of usb class device if success, NULL if fail
 */
usbc_class_device_instance_t* usbc_class_device_register(kal_uint8 class_device_id, usbc_class_device_info_t* device_info);


/*!
 *  @brief  deregister usb class device from usbcore
 *          Running Level: TASK INIT/TASK
 *  @param  class_device_id  device instance id obtained while register
 *  @return KAL_TRUE if success, otherwise KAL_FALSE if fail
 */
kal_bool usbc_class_device_deregister(kal_uint8 class_device_id);

/*!
 *  @brief  retrieve per usb class device context registed in usbc_class_device_register()
 *          Running Level: ANY
 *  @param  class_device_id  device instance id obtained while register
 *  @return per usb class device context
 */
void* usbc_class_device_get_context(kal_uint8 class_device_id);

/*!
 *  @brief  submit control transfer request to usbcore
 *          Running Level: TASK
 *  @param  class_device_id     class device id obtained while register
 *  @param  buffer              pointer to byte array to send or receive data
 *  @param  length              length of buffer to send, or to receive
 *  @param  type                send or receive or stall
 *  @return KAL_TRUE if success, otherwise KAL_FALSE if fail
 */
kal_bool usbc_class_device_submit_control_request(kal_uint8 class_device_id, kal_uint8* buffer, kal_uint32 length, usbc_control_request_type_e type);


/*!
 *  @brief  submit io request to usbcore
 *          Running Level: TASK
 *  @param  class_device_id     device instance id obtained while register
 *  @param  queue_no            QMU queue no
 *  @param  io_request          io request submit to usbcore
 *  @return KAL_TRUE if success, otherwise KAL_FALSE if fail
 */
kal_bool usbc_class_device_submit_io_request(kal_uint8 class_device_id, kal_uint8 queue_no, usbc_io_request_t* io_request);

/*!
 *  @brief  submit io request to usbcore with more configurations
 *          Running Level: TASK
 *  @param  class_device_id     device instance id obtained while register
 *  @param  queue_no            QMU queue no
 *  @param  io_request          io request submit to usbcore
 *  @param  info                configurations apply to the requests
 *  @return KAL_TRUE if success, otherwise KAL_FALSE if fail
 */
kal_bool usbc_class_device_submit_io_request_ext(kal_uint8 class_device_id, kal_uint8 queue_no, usbc_io_request_t *io_request, usbc_io_ext_info_t *info);

/*!
 *  @brief  flush io request already submitted to usbcore
 *          Running Level: TASK
 *  @param  class_device_id     device instance id obtained while register
 *  @param  queue_no            QMU queue no
 *  @return KAL_TRUE if success, otherwise KAL_FALSE if fail
 */
kal_bool usbc_class_device_flush_io_request(kal_uint8 class_device_id, kal_uint8 queue_no);


/*!
 *  @brief  change notify complete function already registered to usbcore
 *          Running Level: TASK
 *  @param  class_device_id     device instance id obtained while register
 *  @param  queue_no            QMU queue no
 *  @param  notify_complete     notify complete callback function
 *  @return KAL_TRUE if success, otherwise KAL_FALSE if fail
 */
kal_bool usbc_class_device_change_notify_complete(kal_uint8 class_device_id, kal_uint8 queue_no, void (*notify_complete)(kal_uint8 class_device_id, usbc_io_request_t* io_request));


/*!
 *  @brief  ask usbcore to detach from bus
 *          Running Level: TASK
 *  @param  class_device_id     device instance id obtained while register
 *  @return KAL_TRUE if success, otherwise KAL_FALSE if fail
 */
kal_bool usbc_class_device_set_hif_disconnect(kal_uint8 class_device_id);



void
usbc_resource_reset(void);

usbc_interface_info_t*
usbc_get_interface_number(kal_uint8 config_num, kal_uint8 *if_num_p);

kal_uint8
usbc_get_string_number(void *string);

usbc_interface_association_descriptor_t*
usbc_get_iad_number(kal_uint8 config_num, kal_uint8 *iad_num_p);

usbc_endpoint_info_t*
usbc_get_endpoint_tx_number(kal_uint8 config_num, kal_uint8 *tx_ep_num_p);

usbc_endpoint_info_t*
usbc_get_endpoint_rx_number(kal_uint8 config_num, kal_uint8 *rx_ep_num_p);


/*!
 *  @brief  ask usbcore to send function remote wakeup notification to the host
 *          Running Level: TASK
 *  @param  class_device_id     device instance id obtained while register
 *  @return KAL_TRUE if success, otherwise KAL_FALSE if fail
 */
kal_bool usbc_class_device_func_remote_wk(kal_uint8 class_device_id);

/*!
 *  @brief  the handler for function remote wakeup notification timeout
 *  @param  class_device_id     device instance id obtained while register
 *  @return
 */
void usbc_wk_notify_timeout();

/*!
 *  @brief  set timer for sending function remote wakeup notification
 *  @param  class_device_id     device instance id obtained while register
 *  @return
 */
void usbc_set_wk_notify_timer(kal_uint8 class_device_id);

/*!
 *  @brief  The netwotk USB function uses the API to notify L4 that it has been in suspending states
 *  @param  class_device_id     device instance id obtained while register
 *  @parm   suspend             the network USB funtion is going to suspending or resuming
 *  @param  remote_wakeup       Is remote wakeup of the suspended function enabled
 *  @return
 */
void usbc_class_device_netifx_suspend_notify(kal_uint8 class_device_id, kal_bool suspend, kal_bool remote_wakeup);

#endif  // _USBCORE_CLASS_DEVICE_H

