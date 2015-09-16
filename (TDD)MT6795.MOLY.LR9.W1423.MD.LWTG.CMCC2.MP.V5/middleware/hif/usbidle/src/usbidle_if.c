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
#include "usbidle_if.h"
#include "ps_public_l4_msgid.h"
#include "ps_public_struct.h"

void usb_idle_set_clockGating(kal_bool gatingValue)
{
    usbidle_t* pUsbIdle = usbidle_get_instance();

    USBIDLE_MUTEX_LOCK(pUsbIdle->usbidle_clock_gating_mutex);
    pUsbIdle->usbidle_clock_off = gatingValue;
    USBIDLE_MUTEX_UNLOCK(pUsbIdle->usbidle_clock_gating_mutex);
}

void usb_idle_set_l4_power_saving(kal_bool gatingValue)
{
    usbidle_t* pUsbIdle = usbidle_get_instance();

    USBIDLE_MUTEX_LOCK(pUsbIdle->usbidle_l4_power_saving_mutex);
    pUsbIdle->usbidle_l4_power_saving = gatingValue;
    USBIDLE_MUTEX_UNLOCK(pUsbIdle->usbidle_l4_power_saving_mutex);
}

void usb_idle_event_notify_to_l4(kal_bool usb_suspend, kal_bool remote_wk)
{
#ifndef L4_NOT_PRESENT
    l4c_usb_suspend_req_struct *rsp_msg_p;
    msg_type msg_id;
    usbidle_t* pUsbIdle = usbidle_get_instance();

    msg_id = usb_suspend? MSG_ID_L4C_USB_SUSPEND_REQ:MSG_ID_L4C_USB_RESUME_REQ;
    rsp_msg_p = (l4c_usb_suspend_req_struct*)construct_local_para(sizeof(l4c_usb_suspend_req_struct), TD_RESET);
    ASSERT(rsp_msg_p);
    rsp_msg_p->remote_wakeup_enable = remote_wk;

    if(usb_suspend && !pUsbIdle->usbidle_l4_power_saving)
    {
        return;
    }

    /*
     *  Send ILM to L4 to notify power saving
     */
    msg_send6(MOD_USBIDLE,  // src module
              MOD_L4C,  // dst module
              0,       // sap id
              msg_id,
              (local_para_struct*)rsp_msg_p,
              0); //msg id
#endif
}
