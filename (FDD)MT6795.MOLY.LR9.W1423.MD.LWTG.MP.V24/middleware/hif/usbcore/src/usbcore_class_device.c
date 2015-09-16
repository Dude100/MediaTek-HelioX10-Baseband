/*!
 *  @file usbcore_class_device.c
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
 *  This file provides functions of usbcore class device interface
 */

#include "kal_public_api.h"
#include "syscomp_config.h"
#include "usbcore_common.h"
#include "usbcore_main.h"
#include "usbcore_class_device.h"
#include "usbcore_hif.h"
#include "hifusb_qmu.h"
#include "hif_ior.h"
#include "usbcore_ind_q.h"
#include "hmu.h"
#include "usbcore_debug.h"
#include "usbidle_if.h"
#include "hif_swla.h"
#include "usbidle_if.h"
#include "hif_mw_msgid.h"

#ifdef ATEST_SYS_USBCORE
#include "usbcore_ut.h"
#endif

#define INVALID_CLASS_DEVICE_ID         0xff
#define INVALID_PIPE_QUEUE_ID           0xff
#define PIPE_QUEUE_RX_MASK              0x80


static void release_class_device(kal_uint8 class_device_id)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8 i = 0;

    pUsbCore->class_device[class_device_id].state = USBC_CORE_CLASS_DEVICE_STATE_INITIATED;

    for ( i=0; i<pUsbCore->total_class_interfaces; i++ )
    {
        if (pUsbCore->class_interface[i].class_device_id == class_device_id)
        {
            pUsbCore->class_interface[i].state = USBC_CORE_CLASS_INTERFACE_STATE_INITIATED;
        }
    }
}


static kal_uint8 acquire_pipe_queue(kal_uint8 class_device_id, usbc_pipe_type_e type)
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


static void release_pipe_queue(kal_uint8 class_device_id)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8 i = 0;

    for ( i=0; i< MAX_USBCORE_QUEUE_NUM; i++ )
    {
        if (pUsbCore->tx_queue[i].class_device_id == class_device_id)
        {
            pUsbCore->tx_queue[i].state = USBC_CORE_QUEUE_STATE_INITIATED;
        }
        if (pUsbCore->rx_queue[i].class_device_id == class_device_id)
        {
            pUsbCore->rx_queue[i].state = USBC_CORE_QUEUE_STATE_INITIATED;
        }
    }
}

static kal_bool usbc_class_device_submit_io_request_priv(hif_queue_type_e core_queue_hif_type, usbc_core_queue_t *pQueue, usbc_io_request_t *io_request)
{
    usbc_io_request_t  *current_request = io_request;
    usbc_io_request_t  *next_request;
    qbm_gpd            *first_gpd      = NULL;
    qbm_gpd            *last_gpd       = NULL;
    qbm_gpd            *current_gpd    = NULL;

    while ( current_request != NULL )
    {
        next_request = current_request->next_request;

        first_gpd = current_request->first_gpd;
        last_gpd = current_request->last_gpd;
        current_gpd = first_gpd;
        /* try to traverse gpd list if last_gpd is not filled */
        if (last_gpd == NULL)
        {
            while ( current_gpd->p_next != NULL )
            {
                current_gpd = current_gpd->p_next;
            }
            last_gpd = current_gpd;
        }

#ifdef __USBCORE_DEBUG__
        usbc_core_printf("[USBCORE] submit type %d queue no %d first gpd %x last gpd %x\r\n", core_queue_hif_type, HIFUSB_EPNO_2_QNO(pQueue->ep_no), first_gpd, last_gpd);
        //usbc_core_dump_gpd_list(first_gpd, last_gpd);
#endif

        usbc_core_set_usbhifq_gpd(core_queue_hif_type, HIFUSB_EPNO_2_QNO(pQueue->ep_no), first_gpd, last_gpd);

        current_request = next_request;
    }

    return KAL_TRUE;
}



kal_bool
usbc_core_get_queue_info(
    kal_uint8           class_device_id,
    kal_uint8           queue_no,
    usbc_core_queue_t **queue,
    hif_queue_type_e   *queue_type)
{
    usbc_core_t        *pUsbCore = usbc_core_get_instance();
    kal_uint8           core_queue_no;

    if ((class_device_id >= pUsbCore->total_class_devices) ||
        (pUsbCore->class_device[class_device_id].state != USBC_CORE_CLASS_DEVICE_STATE_REGISTERED)) {
        ASSERT(0);
        return KAL_FALSE;
    }

    if ((queue_no & ~PIPE_QUEUE_RX_MASK) > MAX_USBCORE_QUEUE_NUM) {
        ASSERT(0);
        return KAL_FALSE;
    }

    if ((queue_no & PIPE_QUEUE_RX_MASK) != PIPE_QUEUE_RX_MASK) {
        core_queue_no = queue_no;
        *queue_type = HIFQ_TYPE_TX;
        *queue = &(pUsbCore->tx_queue[core_queue_no]);
    } else {
        core_queue_no = queue_no & ~PIPE_QUEUE_RX_MASK;
        *queue_type = HIFQ_TYPE_RX;
        *queue = &(pUsbCore->rx_queue[core_queue_no]);
    }

    if ((*queue)->class_device_id != class_device_id) {
        ASSERT(0);
        return KAL_FALSE;
    }

    if ((*queue)->state != USBC_CORE_QUEUE_STATE_ACTIVE) {
        ASSERT(0);
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

usbc_class_device_instance_t* usbc_class_device_register(
    kal_uint8                 class_device_id,
    usbc_class_device_info_t *device_info)
{
    usbc_core_t *pUsbCore = usbc_core_get_instance();
    if (pUsbCore == NULL) {
        ASSERT(0);
        return NULL;
    }
    USBC_NON_EXCEPTION_MODE_CHECK();

    return usbc_core_device_register(class_device_id, pUsbCore, device_info);
}

usbc_class_device_instance_t* usbc_core_device_register(
    kal_uint8                 class_device_id,
    usbc_core_t              *pUsbCore,
    usbc_class_device_info_t *device_info)
{
    usbc_core_class_device_t* pClassDevice = NULL;
    usbc_class_device_instance_t* pClassDeviceInstance = NULL;
    usbc_core_queue_t* pQueue = NULL;
    kal_uint8 acquire_queue = 0;
    kal_uint8 i = 0;

    if (device_info == NULL) {
        ASSERT(0);
        return NULL;
    }

    /* Check state of class device -> it should be initiated state */
    if (pUsbCore->class_device[class_device_id].state != USBC_CORE_CLASS_DEVICE_STATE_INITIATED) {
        ASSERT(0);
        return NULL;
    }

    /* found available device instance, use it and apply register infromation */
    pClassDevice = &(pUsbCore->class_device[class_device_id]);
    if (device_info->total_pipes != pClassDevice->total_pipes) {
        // pipe number not match, return NULL
        ASSERT(0);
        return NULL;
    }

    pClassDeviceInstance                    = &(pClassDevice->device_instance);
    pClassDeviceInstance->id                = class_device_id;
    pClassDeviceInstance->speed             = pUsbCore->speed;
    pClassDeviceInstance->total_interfaces  = 0;
    pClassDeviceInstance->context           = device_info->class_device_context;
    pClassDevice->state             = USBC_CORE_CLASS_DEVICE_STATE_REGISTERED;
    pClassDevice->notify_usb_state  = device_info->notify_usb_state;
    pClassDevice->notify_usb_speed  = device_info->notify_usb_speed;
#ifdef ATEST_SYS_USBCORE
  #if USBC_UT_FAKE_CLASS_CALLBACK
    pClassDevice->notify_func_wk_ability    = usbc_ut_fake_notify_func_wk_ability;
    pClassDevice->query_func_wk_status      = usbc_ut_fake_query_func_wk_status;
  #else
    pClassDevice->notify_func_wk_ability    = device_info->notify_func_wk_ability;
    pClassDevice->query_func_wk_status      = device_info->query_func_wk_status;
  #endif
#else
    pClassDevice->notify_func_wk_ability    = device_info->notify_func_wk_ability;
    pClassDevice->query_func_wk_status      = device_info->query_func_wk_status;
#endif

    for ( i=0; i<pUsbCore->total_class_interfaces; i++ )
    {
        if ( (pUsbCore->class_interface[i].state == USBC_CORE_CLASS_INTERFACE_STATE_INITIATED) &&
             (pUsbCore->class_interface[i].class_device_id == class_device_id) )
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
        acquire_queue = acquire_pipe_queue(class_device_id, device_info->pipe_type[i]);
        if ( acquire_queue == INVALID_PIPE_QUEUE_ID )
        {
            //can't satisfy, release acquired resource if any
            release_pipe_queue(class_device_id);
            release_class_device(class_device_id);
            ASSERT(0);
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


kal_bool usbc_class_device_deregister(kal_uint8 class_device_id)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();

    USBC_NON_EXCEPTION_MODE_CHECK();

    if ( (class_device_id >= pUsbCore->total_class_devices) ||
         (pUsbCore->class_device[class_device_id].state != USBC_CORE_CLASS_DEVICE_STATE_REGISTERED) )
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    release_pipe_queue(class_device_id);
    release_class_device(class_device_id);

    return KAL_TRUE;
}


void* usbc_class_device_get_context(kal_uint8 class_device_id)
{
    usbc_core_t *pUsbCore = usbc_core_get_instance();
    usbc_core_class_device_t *pClassDevice = &(pUsbCore->class_device[class_device_id]);
    usbc_class_device_instance_t *pClassDeviceInstance = &(pClassDevice->device_instance);

    return pClassDeviceInstance->context;
}


kal_bool usbc_class_device_submit_control_request(
    kal_uint8 class_device_id, kal_uint8* buffer, kal_uint32 length,
    usbc_control_request_type_e type)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();

    if (!USBC_IS_IN_EXCEPTION_MODE())
    {
        USBC_CLASS_DEVICE_CONTEXT_CHECK();
    }

    if ( (class_device_id >= pUsbCore->total_class_devices) ||
         (pUsbCore->class_device[class_device_id].state != USBC_CORE_CLASS_DEVICE_STATE_REGISTERED) )
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    usbc_core_set_control_request(buffer, length, type);

    return KAL_TRUE;
}


kal_bool usbc_class_device_submit_io_request(
    kal_uint8 class_device_id, kal_uint8 queue_no,
    usbc_io_request_t* io_request)
{
    usbc_core_queue_t  *pQueue = NULL;
    hif_queue_type_e    core_queue_hif_type;

    HIF_SWLA_START("UD1");

    USBC_NON_EXCEPTION_MODE_CHECK();
    USBC_CLASS_DEVICE_CONTEXT_CHECK();

    if (!usbc_core_get_queue_info(class_device_id, queue_no, &pQueue, &core_queue_hif_type)) {
        HIF_SWLA_STOP("UD1");
        return KAL_FALSE;
    }

    HIF_SWLA_STOP("UD1");
    return usbc_class_device_submit_io_request_priv(core_queue_hif_type, pQueue, io_request);
}


kal_bool usbc_class_device_submit_io_request_ext(
    kal_uint8 class_device_id, kal_uint8 queue_no,
    usbc_io_request_t  *io_request, 
    usbc_io_ext_info_t *info)
{
    usbc_core_queue_t  *pQueue = NULL;
    hif_queue_type_e    core_queue_hif_type;

    USBC_NON_EXCEPTION_MODE_CHECK();
    USBC_CLASS_DEVICE_CONTEXT_CHECK();

    if (!usbc_core_get_queue_info(class_device_id, queue_no, &pQueue, &core_queue_hif_type)) {
        return KAL_FALSE;
    }

    switch (info->type) {
    case USBC_IO_TX_NO_FLUSH:
        core_queue_hif_type = HIFQ_TYPE_TX_NO_FLUSH;
        break;

    default:
        ASSERT(KAL_FALSE);
        return KAL_FALSE;
    }

    return usbc_class_device_submit_io_request_priv(core_queue_hif_type, pQueue, io_request);
}


kal_bool usbc_class_device_flush_io_request(
    kal_uint8 class_device_id, kal_uint8 queue_no)
{
    usbc_core_queue_t* pQueue = NULL;
    hif_queue_type_e core_queue_hif_type;
    hif_flush_type_e core_queue_flush_type;
    qbm_gpd* first_gpd  = NULL;
    qbm_gpd* last_gpd   = NULL;
    kal_uint32 num = 0;

    USBC_NON_EXCEPTION_MODE_CHECK();
    USBC_CLASS_DEVICE_CONTEXT_CHECK();

    if (!usbc_core_get_queue_info(class_device_id, queue_no, &pQueue, &core_queue_hif_type)) {
        return KAL_FALSE;
    }

    if ( pQueue->notify_complete == NULL )
    {
        core_queue_flush_type = HIFQ_FLUSH_FREE;
    } else {
        core_queue_flush_type = HIFQ_FLUSH_DEQ;
    }

    // Flush GPDs that are buffered in DRAM, and give GPDs back to uppoer layers
    num = hifusbq_pwrsave_flush_gpd(core_queue_hif_type, HIFUSB_EPNO_2_QNO(pQueue->ep_no), core_queue_flush_type, (void**)&first_gpd, (void**)&last_gpd);
    if ( num != 0 )
    {
#ifdef __USBCORE_DEBUG__
        usbc_core_printf("[USBCORE] flush type %d queue no %d first gpd %x last gpd %x\r\n", core_queue_hif_type, HIFUSB_EPNO_2_QNO(pQueue->ep_no), first_gpd, last_gpd);
        //usbc_core_dump_gpd_list(first_gpd, last_gpd);
#endif
        if ( pQueue->notify_complete != NULL )
        {
            if ( first_gpd == NULL )
            {
                /* just indicate a notification */
                usbc_data_trace(USBCORE_CLASS_FLUSH_SW_QUEUE, queue_no, num, 0x00, 0x00);
                pQueue->notify_complete(pQueue->class_device_id, NULL);
            } else {
                usbc_io_request_t* request = NULL;
                usbc_data_trace(USBCORE_CLASS_FLUSH_SW_QUEUE, queue_no, num, first_gpd, last_gpd);
                request = (usbc_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(first_gpd);
                request->next_request = NULL;
                request->first_gpd = first_gpd;
                request->last_gpd = last_gpd;
                pQueue->notify_complete(pQueue->class_device_id, request);
            }
        }
    }

    // Flush GPDs that are configured in hardware, and give GPDs back to uppoer layers
    num = hifusbq_flush_gpd(core_queue_hif_type, HIFUSB_EPNO_2_QNO(pQueue->ep_no), core_queue_flush_type, (void**)&first_gpd, (void**)&last_gpd);
    if ( num != 0 )
    {
#ifdef __USBCORE_DEBUG__
        usbc_core_printf("[USBCORE] flush type %d queue no %d first gpd %x last gpd %x\r\n", core_queue_hif_type, HIFUSB_EPNO_2_QNO(pQueue->ep_no), first_gpd, last_gpd);
        //usbc_core_dump_gpd_list(first_gpd, last_gpd);
#endif
        if ( pQueue->notify_complete != NULL )
        {
            if ( first_gpd == NULL )
            {
                /* just indicate a notification */
                usbc_data_trace(USBCORE_CLASS_FLUSH_HW_QUEUE, queue_no, num, 0x00, 0x00);
                pQueue->notify_complete(pQueue->class_device_id, NULL);
            } else {
                usbc_io_request_t* request = NULL;
                usbc_data_trace(USBCORE_CLASS_FLUSH_HW_QUEUE, queue_no, num, first_gpd, last_gpd);
                request = (usbc_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(first_gpd);
                request->next_request = NULL;
                request->first_gpd = first_gpd;
                request->last_gpd = last_gpd;
                pQueue->notify_complete(pQueue->class_device_id, request);
            }
        }
    }

    return KAL_TRUE;
}


kal_bool usbc_class_device_change_notify_complete(
    kal_uint8 class_device_id, kal_uint8 queue_no,
    void (*notify_complete)(kal_uint8 class_device_id, usbc_io_request_t* io_request))
{
    usbc_core_queue_t* pQueue = NULL;
    hif_queue_type_e core_queue_hif_type;

    USBC_NON_EXCEPTION_MODE_CHECK();
    USBC_CLASS_DEVICE_CONTEXT_CHECK();

    if (!usbc_core_get_queue_info(class_device_id, queue_no, &pQueue, &core_queue_hif_type)) {
        return KAL_FALSE;
    }

    pQueue->notify_complete = notify_complete;

    return KAL_TRUE;
}


kal_bool usbc_class_device_set_hif_disconnect(kal_uint8 class_device_id)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();

    USBC_NON_EXCEPTION_MODE_CHECK();
    USBC_CLASS_DEVICE_CONTEXT_CHECK();

    if ( (class_device_id >= pUsbCore->total_class_devices) ||
         (pUsbCore->class_device[class_device_id].state != USBC_CORE_CLASS_DEVICE_STATE_REGISTERED) )
    {
        ASSERT(0);
        return KAL_FALSE;
    }

    usbc_normal_hif_disconnect();

    return KAL_TRUE;
}


void usbc_wk_notify_timeout()
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8 class_device_id = 0;
    kal_uint8 i;

    USBC_CLASS_REMOTE_WK_LOCK(pUsbCore->usbc_class_renotify_mutex);
    for(i=0; i<pUsbCore->total_class_devices; i++)
    {
        if(pUsbCore->func_notify_list[i] == KAL_TRUE)
        {
            class_device_id = i;
            pUsbCore->func_notify_list[i] = KAL_FALSE;
            break;
        }
    }

    if (i == pUsbCore->total_class_devices)
    {
        pUsbCore->wk_eventid = NULL;
        USBC_CLASS_REMOTE_WK_UNLOCK(pUsbCore->usbc_class_renotify_mutex);
        return;
    }
    USBC_CLASS_REMOTE_WK_UNLOCK(pUsbCore->usbc_class_renotify_mutex);

    // check the access of the function
    if ( !pUsbCore->is_func_be_accessed[class_device_id] )
    {
        usbc_set_wk_notify_timer(class_device_id);
    }
}


void usbc_set_wk_notify_timer(kal_uint8 class_device_id)
{
    eventid         eid;
    kal_uint8       nInterface;
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    /*
     * To prevent race condition of event cancelling and set,
     * there shall be only one such event for simplicity.
     */
    ASSERT(NULL != pUsbCore->usbc_es_wk_notify_g);

    usbc_trace_info(USBCORE_REMOTE_WK_SET_NOTIFY_TIMER, class_device_id);

    USBC_CLASS_REMOTE_WK_LOCK(pUsbCore->usbc_class_renotify_mutex);

    // usb a bitmap to maintain the list of function wakeup notification
    pUsbCore->func_notify_list[class_device_id] = KAL_TRUE;

    // get the firtst interface ot the function
    nInterface = usbc_class_device_get_1st_interface(class_device_id);
    // send function remote wakeup notification via HIF driver
    usbc_normal_hif_ss_wk_notify(nInterface); 

    if (NULL == pUsbCore->wk_eventid)
    {
        eid = evshed_set_event(
                pUsbCore->usbc_es_wk_notify_g,
                usbc_wk_notify_timeout,     // timeout handler
                NULL, /* event_hf_param */
                USBC_WK_NOTIFY_CHECK_TICKS); /* elapse_time */
        ASSERT(eid);
    }

    USBC_CLASS_REMOTE_WK_UNLOCK(pUsbCore->usbc_class_renotify_mutex);
}


kal_bool usbc_class_device_func_remote_wk(kal_uint8 class_device_id)
{

    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_bool isDeviceSuspend;
    usbc_ind_t          ind_to_enqueue;
    usbc_func_state_e    state;

    usbc_trace_info(USBCORE_REMOTE_WK_START, class_device_id);

    USBC_NON_EXCEPTION_MODE_CHECK();
    USBC_CLASS_DEVICE_CONTEXT_CHECK();

    /* Check whether the requested function is capable to wakeup the host and remote wakeup is enabled.
       Return KAL_FALSE if the function is not valid to wakeup host
     */
    if ( pUsbCore->class_device[class_device_id].query_func_wk_status(class_device_id) != 0x03 )
    {
        usbc_trace_error(USBCORE_REMOTE_WK_INVALID, class_device_id, pUsbCore->class_device[class_device_id].query_func_wk_status(class_device_id));
        ASSERT(0);
        return KAL_FALSE;
    }

    // check for the remote wakeup once a function at the same time
    USBC_CLASS_REMOTE_WK_LOCK(pUsbCore->usbc_class_remote_wk_mutex);

    // reset the status of function accessing of class device id
    USBC_CLASS_REMOTE_WK_LOCK(pUsbCore->usbc_class_func_access_mutex);
    pUsbCore->is_func_be_accessed[class_device_id] = KAL_FALSE;
    USBC_CLASS_REMOTE_WK_UNLOCK(pUsbCore->usbc_class_func_access_mutex);

    isDeviceSuspend = (pUsbCore->state == USBC_USB_STATE_SUSPENDED)? KAL_TRUE:KAL_FALSE;

    /* If it is resumed from device suspend,
            then send hifusb_remote_wakeup first and wait for the resume callback to know LPM state to U0.
       If it is resumed from function suspend,
            then send notification to resume the suspended function in USB Core context.
     */
    if ( isDeviceSuspend )
    {
        usbc_trace_info(USBCORE_REMOTE_WK_DEVICE, class_device_id);
        usb_idle_set_clockGating(KAL_FALSE);    // nofity USBIDLE that it does not have to gate the clock of USB IP 
        usbc_normal_hif_remote_wakeup();
    }

    //else if ( pUsbCore->class_device[class_device_id].is_func_suspend )
    if ( pUsbCore->class_device[class_device_id].is_func_suspend )
    {
        // block until device resume
        while ( isDeviceSuspend )
        {
            kal_sleep_task(USBC_DEV_RESUME_DURATION_TICK);
            isDeviceSuspend = (pUsbCore->state == USBC_USB_STATE_SUSPENDED)? KAL_TRUE:KAL_FALSE;
            usbc_trace_warn(USBCORE_REMOTE_WK_DEVICE_WAIT, class_device_id);
        }

        usbc_trace_info(USBCORE_REMOTE_WK_FUNC, class_device_id);
        // send callback to notify class device of resuming
        state = USBC_FUNC_STATE_RESUME;
        // Enqueue USB function state which will be handled in USB context later.
        ind_to_enqueue.type = USBC_IND_FUNC_EVENT;
        ind_to_enqueue.ext = class_device_id;
        ind_to_enqueue.data = (kal_uint8)state;
        usbc_enqueue_ind(&ind_to_enqueue);
        // Wake up USBCORE task to process indications.
        hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);
    }

    // release for the remote wakeup of a function
    USBC_CLASS_REMOTE_WK_UNLOCK(pUsbCore->usbc_class_remote_wk_mutex);

    // call HIF driver API to send function wakeup notification, and resend if needed
    if ( pUsbCore->speed == USBC_USB_SPEED_USB30 )
    {
        usbc_set_wk_notify_timer(class_device_id);
    }

    return KAL_TRUE;
}

void usbc_class_device_netifx_suspend_notify(kal_uint8 class_device_id, kal_bool suspend, kal_bool remote_wakeup)
{
    usbcore_usbidle_l4_power_saving_req_struct *rsp_msg_p;
    usbc_core_t* pUsbCore = usbc_core_get_instance();

    if ( 1 
#ifdef __USB_RNDIS_SUPPORT__    
         && (pUsbCore->class_device[class_device_id].class_type != USB_CLASS_RNDIS)
#endif
#ifdef __USB_MBIM_SUPPORT__
         && (pUsbCore->class_device[class_device_id].class_type != USB_CLASS_MBIM)
#endif
#ifdef __USB_ECM_SUPPORT__
         && (pUsbCore->class_device[class_device_id].class_type != USB_CLASS_ECM)
#endif
       )
    {
        ASSERT(0);
        return;
    }       

    // In current implemnntation, only notifying L4 of USB suspended/resuming with remote wakeup is allowed
    ASSERT(remote_wakeup);
    if( suspend )
    {
        rsp_msg_p = (usbcore_usbidle_l4_power_saving_req_struct*)construct_local_para(sizeof(usbcore_usbidle_l4_power_saving_req_struct), TD_RESET);
        ASSERT(rsp_msg_p);
        rsp_msg_p->notify_suspend = suspend;
        rsp_msg_p->notify_suspend_with_remote_wk = remote_wakeup;
        usb_idle_set_l4_power_saving(KAL_TRUE);
        msg_send6(MOD_USBCORE,  // src module
                  MOD_USBIDLE,  // dst module
                  0,       // sap id
                  MSG_ID_USBCORE_IDLE_NOTIFY_TO_L4,
                  (local_para_struct*)rsp_msg_p,
                  0);    
    }
    else
    {
        usb_idle_set_l4_power_saving(KAL_FALSE);
        usb_idle_event_notify_to_l4(suspend, remote_wakeup);
    }        
}
