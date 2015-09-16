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
 *   usbcore_notify_event.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   Helper routine to notify USBCLASS changes.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "kal_public_api.h"
#include "syscomp_config.h"
#include "usbcore_common.h"
#include "usbcore_main.h"
#include "usbcore_hif.h"
#include "usbcore_class_device.h"
#include "hif_ior.h"
#include "hif_mw_msgid.h"
#include "usbidle_if.h"
#include "usbcore_debug.h"
#include "hmu_conf_data.h"

/*------------------------------------------------------------------------------
 * Private implementation.
 *----------------------------------------------------------------------------*/
static void usbc_core_indicate_state(usbc_usb_state_e state)
{
    usbc_core_t    *pUsbCore = usbc_core_get_instance();
    kal_uint8       idx;

    pUsbCore->state = state;

    for (idx = 0; idx < pUsbCore->total_class_devices; idx++) {
        if ( USBC_CORE_CLASS_DEVICE_STATE_REGISTERED == pUsbCore->class_device[idx].state &&
             NULL != pUsbCore->class_device[idx].notify_usb_state )
        {
            if ( (state == USBC_USB_STATE_SUSPENDING || state == USBC_USB_STATE_SUSPENDED) &&
                 pUsbCore->class_device[idx].is_func_suspend )
            {
                // do not suspend the class device again if it has been in function suspend state
            }
            else if ( state == USBC_USB_STATE_RESUME && pUsbCore->class_device[idx].is_func_suspend )
            {
                // do not resume the class device which was function suspended while device resuming
                // the class device will be resumed later while function resuming
            }
            else
            {
                usbc_trace_info(USBCORE_NOTIFY_CLASS_START, pUsbCore->class_device[idx].class_type, state);
                pUsbCore->class_device[idx].notify_usb_state(idx,state);
                usbc_trace_info(USBCORE_NOTIFY_CLASS_END, pUsbCore->class_device[idx].class_type, state);
            }
        } 
    }
}


/*!
 *  @brief This function is used to notify function suspend or function resume to a specific class device
 */
static void usbc_core_indicate_function_state(kal_uint8 class_device_id, usbc_usb_state_e state)
{
    usbc_core_t *pUsbCore = usbc_core_get_instance();

    if ( state != USBC_USB_STATE_SUSPENDING &&
         state != USBC_USB_STATE_SUSPENDED &&
         state != USBC_USB_STATE_RESUME )
    {
        ASSERT(0);
        return;
    }

    if ( USBC_CORE_CLASS_DEVICE_STATE_REGISTERED == pUsbCore->class_device[class_device_id].state &&
         NULL != pUsbCore->class_device[class_device_id].notify_usb_state )
    {
        usbc_trace_info(USBCORE_NOTIFY_CLASS_START, pUsbCore->class_device[class_device_id].class_type, state);
        pUsbCore->class_device[class_device_id].notify_usb_state(class_device_id, state);
        usbc_trace_info(USBCORE_NOTIFY_CLASS_END, pUsbCore->class_device[class_device_id].class_type, state);

    }
}

/*------------------------------------------------------------------------------
 * Public interface.
 *----------------------------------------------------------------------------*/
void usbc_core_notify_state_attaching()
{
    usbc_core_indicate_state(USBC_USB_STATE_ATTACHING);
}


void usbc_core_notify_state_attached()
{
    usbc_core_indicate_state(USBC_USB_STATE_ATTACHED);
}


void usbc_core_notify_state_detaching()
{
    usbc_core_indicate_state(USBC_USB_STATE_DETACHING);
    usbc_core_indicate_state(USBC_USB_STATE_DETACHED);
}


void usbc_core_notify_state_suspending()
{
    kal_uint8 func_list;
    usbcore_usbidle_l4_power_saving_req_struct *rsp_msg_p;

    // notify USBCLASS of USB suspended
    usbc_core_indicate_state(USBC_USB_STATE_SUSPENDING);
    usbc_core_indicate_state(USBC_USB_STATE_SUSPENDED);

    if( USBC_IS_IN_EXCEPTION_MODE() )
    {
        return;
    }	    

    // Updatea function pointer for setting GPDs in DRAM buffer
    usbc_trace_info(USBCORE_UPDATE_API_BUFF_GPD, 1);
    usbc_suspended_hif_factory();

    // Notify USBIDLE task to gate USB clock
    usbc_trace_info(USBCORE_DEV_SUSPEND_CLOCK, 1, 1);
    usb_idle_set_clockGating(KAL_TRUE);         // notify USBIDLE that it has to gate the clock of USB IP
    msg_send4(MOD_USBCORE,  // src module
              MOD_USBIDLE,  // dst module
              0,       // sap id
              MSG_ID_USBCORE_SUSPEND_TO_IDLE); //msg id

    // Ask USBIDLE to notify L4 to turn RF power off or go to fast dormancy
    func_list = usbc_core_get_function_remote_wk_list();
    rsp_msg_p = (usbcore_usbidle_l4_power_saving_req_struct*)construct_local_para(sizeof(usbcore_usbidle_l4_power_saving_req_struct), TD_RESET);
    ASSERT(rsp_msg_p);
    rsp_msg_p->notify_suspend = KAL_TRUE;
    rsp_msg_p->notify_suspend_with_remote_wk = (func_list==0)? KAL_FALSE:KAL_TRUE;
    usbc_trace_info(USBCORE_DEV_SUSPEND_L4, 1, 1, 1, (rsp_msg_p->notify_suspend_with_remote_wk? 1:0));
    usb_idle_set_l4_power_saving(KAL_TRUE);
    msg_send6(MOD_USBCORE,  // src module
              MOD_USBIDLE,  // dst module
              0,       // sap id
              MSG_ID_USBCORE_IDLE_NOTIFY_TO_L4,
              (local_para_struct*)rsp_msg_p,
              0); //msg id
 
    // Set USBCORE task to wait for indication events only
    usbc_trace_info(USBCORE_SUSPEND_STOP_POLL);
    usbc_core_get_instance()->hmu_indication = HIF_DRV_EG_USBC_IND_EVENT;   // Set USBCORE task to wait for indication events only
}


void usbc_core_notify_state_resume()
{
    kal_bool remote_wakeup_enabled = (usbc_core_get_function_remote_wk_list()==0)? KAL_FALSE:KAL_TRUE;

    if( USBC_IS_IN_EXCEPTION_MODE() )
    {
        usbc_core_indicate_state(USBC_USB_STATE_RESUME);
        return;
    }


    // nofity USBIDLE that it does not have to gate the clock of USB IP
    usbc_trace_info(USBCORE_DEV_SUSPEND_CLOCK, 0, 0);
    usb_idle_set_clockGating(KAL_FALSE);

    // Notify USB resume event to USB classes
    usbc_core_indicate_state(USBC_USB_STATE_RESUME);

    // Update function pointer for set GPDs to hardware normally
    usbc_trace_info(USBCORE_UPDATE_API_BUFF_GPD, 0);
    usbc_normal_hif_factory();

    // Set GPDs that are buffered in DRAM to hardware
    usbc_normal_hif_restore_gpd_pwrsave();

    // Set USBCORE task to wait for both indication events and tick events
    usbc_trace_info(USBCORE_SUSPEND_START_POLL);
    usbc_core_get_instance()->hmu_indication = HIF_DRV_EG_HIF_TICK_EVENT | HIF_DRV_EG_USBC_IND_EVENT;

    // Ask USBIDLE to notify L4 to turn RF power on or go back to normal operation state
    usbc_trace_info(USBCORE_DEV_SUSPEND_L4, 0, 0, 0, (remote_wakeup_enabled? 1:0));
    usb_idle_set_l4_power_saving(KAL_FALSE);
    usb_idle_event_notify_to_l4(KAL_FALSE, remote_wakeup_enabled);
}


void usbc_core_notify_state_reset()
{
    kal_bool remote_wakeup_enabled = (usbc_core_get_function_remote_wk_list()==0)? KAL_FALSE:KAL_TRUE;

    if( USBC_IS_IN_EXCEPTION_MODE() )
    {
        usbc_core_indicate_state(USBC_USB_STATE_RESET);
        usbc_core_clear_status();
        return;
    }


    // nofity USBIDLE that it does not have to gate the clock of USB IP
    usbc_trace_info(USBCORE_DEV_SUSPEND_CLOCK, 0, 0);
    usb_idle_set_clockGating(KAL_FALSE);

    // Update function pointer for set GPDs to hardware normally
    usbc_trace_info(USBCORE_UPDATE_API_BUFF_GPD, 0);
    usbc_normal_hif_factory();

    // Notify USB reset event to USB classes and clear USB status
    usbc_core_indicate_state(USBC_USB_STATE_RESET);
    usbc_core_clear_status();

    // Ask USBIDLE to notify L4 to turn RF power on or go back to normal operation state
    usbc_trace_info(USBCORE_DEV_SUSPEND_L4, 0, 0, 0, (remote_wakeup_enabled? 1:0));
    usb_idle_set_l4_power_saving(KAL_FALSE);
    usb_idle_event_notify_to_l4(KAL_FALSE, remote_wakeup_enabled);
}


void usbc_core_notify_speed_change(usbc_usb_speed_e speed)
{
    usbc_core_t    *pUsbCore = usbc_core_get_instance();
    kal_uint8       idx = 0;

    for (idx = 0; idx < pUsbCore->total_class_devices; idx++) {
        if (USBC_CORE_CLASS_DEVICE_STATE_REGISTERED == pUsbCore->class_device[idx].state &&
            NULL != pUsbCore->class_device[idx].notify_usb_speed) {
            pUsbCore->class_device[idx].notify_usb_speed(idx, speed);
        }
    }
}

void usbc_core_notify_alternate_setting(kal_uint8 intf_idx, kal_uint8 alternate_setting)
{
    usbc_core_t    *pUsbCore = usbc_core_get_instance();
    usbc_core_class_interface_t *intf = &pUsbCore->class_interface[intf_idx];

    if (USBC_CORE_CLASS_INTERFACE_STATE_ACTIVE == intf->state &&
        NULL != intf->notify_alternate_setting) {
        intf->notify_alternate_setting(
                    intf->class_device_id,
                    intf->interface_type,
                    intf->alternate_setting);
    }
}

void usbc_core_notify_stall(kal_bool is_tx, kal_uint8 queue_idx, kal_bool stall)
{
    usbc_core_t    *pUsbCore = usbc_core_get_instance();
    usbc_core_queue_t   *pQueue;

    if (is_tx) {
        pQueue = &pUsbCore->tx_queue[queue_idx];
    } else {
        pQueue = &pUsbCore->rx_queue[queue_idx];
    }

    if (pQueue->state > USBC_CORE_QUEUE_STATE_INITIATED &&
        NULL != pQueue->notify_stall) {
        pQueue->notify_stall(pQueue->class_device_id, stall);
    }
}

void usbc_core_notify_function_state_suspending(kal_uint8 class_device_id)
{
    kal_uint8 func_suspend_list;
    kal_uint8 func_wk_list = usbc_core_get_function_remote_wk_list();
    usbc_core_t *pUsbCore = usbc_core_get_instance();
    usbcore_usbidle_l4_power_saving_req_struct *rsp_msg_p;

    // Notify the specific function of USB suspended
    if ( !pUsbCore->class_device[class_device_id].is_func_suspend )
    {
        usbc_core_indicate_function_state(class_device_id, USBC_USB_STATE_SUSPENDING);
        usbc_core_indicate_function_state(class_device_id, USBC_USB_STATE_SUSPENDED);
        pUsbCore->class_device[class_device_id].is_func_suspend = KAL_TRUE;
    }

    // If all functions of the device are suspended, we notify L4 to do power saving
    func_suspend_list = usbc_core_get_function_suspend_list();
    if( !USBC_IS_IN_EXCEPTION_MODE() &&
        func_suspend_list == ((0x01 << pUsbCore->total_class_devices)-1) )
    {
        rsp_msg_p = (usbcore_usbidle_l4_power_saving_req_struct*)construct_local_para(sizeof(usbcore_usbidle_l4_power_saving_req_struct), TD_RESET);
        ASSERT(rsp_msg_p);
        rsp_msg_p->notify_suspend = KAL_TRUE;
        rsp_msg_p->notify_suspend_with_remote_wk = (func_wk_list==0)? KAL_FALSE:KAL_TRUE;
        usbc_trace_info(USBCORE_DEV_SUSPEND_L4, 1, 1, 1, (rsp_msg_p->notify_suspend_with_remote_wk? 0:1));
        usb_idle_set_l4_power_saving(KAL_TRUE);
        msg_send6(MOD_USBCORE,  // src module
                  MOD_USBIDLE,  // dst module
                  0,       // sap id
                  MSG_ID_USBCORE_IDLE_NOTIFY_TO_L4,
                  (local_para_struct*)rsp_msg_p,
                  0); //msg id
    }
}

void usbc_core_notify_function_state_resume(kal_uint8 class_device_id)
{
    kal_uint8 func_suspend_list = usbc_core_get_function_suspend_list();
    kal_bool remote_wakeup_enabled = (usbc_core_get_function_remote_wk_list()==0)? KAL_FALSE:KAL_TRUE;

    usbc_core_t *pUsbCore = usbc_core_get_instance();

    // Notify the specific function of USB resuming
    if ( pUsbCore->class_device[class_device_id].is_func_suspend )
    {
        usbc_core_indicate_function_state(class_device_id, USBC_USB_STATE_RESUME);
        pUsbCore->class_device[class_device_id].is_func_suspend = KAL_FALSE;
    }

    // Notify L4 to go back to normal operation states if function resumes from the status that all functions are suspended before
    if( !USBC_IS_IN_EXCEPTION_MODE() &&
        func_suspend_list == ((0x01 << pUsbCore->total_class_devices)-1) )
    {
        usbc_trace_info(USBCORE_DEV_SUSPEND_L4, 0, 0, 0, (remote_wakeup_enabled? 0:1));
        usb_idle_set_l4_power_saving(KAL_FALSE);
        usb_idle_event_notify_to_l4(KAL_FALSE, remote_wakeup_enabled);
    }
}

void usbc_core_notify_func_wk_ability(kal_uint8 class_device_id, kal_bool ability)
{
    usbc_core_t    *pUsbCore = usbc_core_get_instance();
    kal_bool isCapableWk = KAL_FALSE;

    // check the capability of the class device
    if ( NULL != pUsbCore->class_device[class_device_id].query_func_wk_status)
    {
        isCapableWk = ((pUsbCore->class_device[class_device_id].query_func_wk_status(class_device_id) & (kal_uint8)0x01) == 0x01)? KAL_TRUE:KAL_FALSE;
    }
    if( ability && !isCapableWk )
    {
        usbc_trace_error(USBCORE_NOTIFY_WK_ABILITY_INVALID, pUsbCore->class_device[class_device_id].class_type);
        ASSERT(0);
        return;
    }

    if ( USBC_CORE_CLASS_DEVICE_STATE_REGISTERED == pUsbCore->class_device[class_device_id].state &&
         NULL != pUsbCore->class_device[class_device_id].notify_func_wk_ability )
    {
        usbc_trace_info(USBCORE_NOTIFY_WK_ABILITY_START, pUsbCore->class_device[class_device_id].class_type);
        pUsbCore->class_device[class_device_id].notify_func_wk_ability(class_device_id, ability);
        usbc_trace_info(USBCORE_NOTIFY_WK_ABILITY_END, pUsbCore->class_device[class_device_id].class_type);
    }
}
