/*!
 *  @file usbidle_task.c
 *  @author Bo-Kai Huang <bo-kai.haung@mediatek.com>
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
 *  This file provides main functions of usbidle
 */

#include "kal_public_api.h"
#include "syscomp_config.h"
#include "sysservice_msgid.h"
#include "usbidle_main.h"
#include "usbidle_hif.h"
#include "usbidle_if.h"
#include "hif_usb.h"

static usbidle_t usbidle_inst_s;

usbidle_t* usbidle_get_instance()
{
    return &usbidle_inst_s;
}

static void usb_idle_task_main(task_entry_struct* task_entry_ptr)
{
    ilm_struct current_ilm;
    usbcore_usbidle_l4_power_saving_req_struct *rsp_msg_l4_power_p;

    kal_set_active_module_id(MOD_USBIDLE);
    kal_mem_set(&current_ilm, 0, sizeof(ilm_struct));

    while (1)
    {
        /* msg_receive_extq will block, therefore we poll if any message
           exist first */
        if ( KAL_TRUE == msg_receive_extq(&current_ilm) )
        {
            kal_set_active_module_id(current_ilm.dest_mod_id);

            switch (current_ilm.msg_id)
            {
                case MSG_ID_USBCORE_SUSPEND_TO_IDLE:
                    usb_idle_suspend_done_handle();   // notification to HIF driver for the completion of USB suspending
                    break;

                case MSG_ID_USBCORE_IDLE_NOTIFY_TO_L4:
                    rsp_msg_l4_power_p = (usbcore_usbidle_l4_power_saving_req_struct*)current_ilm.local_para_ptr;
                    usb_idle_event_notify_to_l4(rsp_msg_l4_power_p->notify_suspend, rsp_msg_l4_power_p->notify_suspend_with_remote_wk);
                    break;

                default:
                    break;
            }
            
            destroy_ilm(&current_ilm);
        }
    }
}


static kal_bool usb_idle_task_init(void)
{
    usbidle_t *pUsbIdle;
    kal_char usbidle_mutex_name[50];

    kal_mem_set(usbidle_get_instance(), 0, sizeof(usbidle_t));

    pUsbIdle = usbidle_get_instance();

    pUsbIdle->usbidle_clock_off = KAL_FALSE;
    pUsbIdle->usbidle_l4_power_saving = KAL_FALSE;

    sprintf(usbidle_mutex_name, "USBIDLE_CLOCK_GATE_MUTEX");
    pUsbIdle->usbidle_clock_gating_mutex = kal_create_enh_mutex(usbidle_mutex_name);
    sprintf(usbidle_mutex_name, "USBIDLE_L4_POWER_SAVING_MUTEX");
    pUsbIdle->usbidle_l4_power_saving_mutex = kal_create_enh_mutex(usbidle_mutex_name);

    return KAL_TRUE;
}


static kal_bool usb_idle_task_reset(void)
{
    /* Do task's reset here.
     * Notice that: shouldn't execute modules reset handler since
     * stack_task_reset() will do. */
    return KAL_TRUE;
}


kal_bool usb_idle_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct usb_idle_handler_info =
    {
        usb_idle_task_main,        /* task entry function */
        usb_idle_task_init,        /* task initialization function */
        usb_idle_task_reset        /* task reset handler */
    };

    *handle = (comptask_handler_struct *)&usb_idle_handler_info;

    return KAL_TRUE;
}

