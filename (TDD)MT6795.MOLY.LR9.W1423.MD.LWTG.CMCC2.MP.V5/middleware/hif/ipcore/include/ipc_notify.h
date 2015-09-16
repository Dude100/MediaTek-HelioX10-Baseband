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
 *   ipc_notify.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   IPCore notification.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __INC_IPC_NOTIFY_H
#define __INC_IPC_NOTIFY_H

#include "kal_public_api.h"

#include "ipc_api.h"
#include "ipc_object.h"


/*------------------------------------------------------------------------------
 * Data structure defintion.
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 * Function prototype.
 *----------------------------------------------------------------------------*/

/*!
 * Initialize IP CORE notification resources.
 */
void ipc_ntfy_init(void);

/*!
 * Create a notification.
 *
 * @param   callback_func [IN] Callback function pointer.
 * @param   callback_context [IN] Context to pass in the callback function.
 *
 * @return Zero or positive value as notification ID if registration succeeded, negative value otherwise.
 */
kal_int32
ipc_new_ntfy(
    ipc_ntfy_callback_t callback_func,
    void                *callback_context);

/*!
 * Remove the notification entry.
 *
 * @param   ntfy_id [IN] notification ID to remove.
 */
void
ipc_del_ntfy(kal_int32 ntfy_id);

/*!
 * Execute IP CORE notification callback.
 *
 * @param   netif [IN] Corresponding network interface for the notification.
 * @param   ntfy_type [IN] Notification type to indicate.
 */
void
ipc_do_ntfy(
    ipc_netif_t     *netif,
    ipc_ntfy_type_e ntfy_type);


/*!
 * Handler of the message MSG_ID_IPCORE_LINK_UP_IND.
 *
 * @param   link_handshake_msg_ind_ptr [IN] Pointer to a ipc_link_handshake_msg_t object.
 */
void ipc_on_ipcore_link_up_ind(void *link_handshake_msg_ind_ptr);

/*!
 * Handler of the message MSG_ID_IPCORE_IP_UP_IND.
 *
 * @param   link_handshake_msg_ind_ptr [IN] Pointer to a ipc_link_handshake_msg_t object.
 */
void ipc_on_ipcore_ip_up_ind(void *link_handshake_msg_ind_ptr);

/*!
 * Handler of the message MSG_ID_IPCORE_LINK_UP_RSP / MSG_ID_IPCORE_IP_UP_RSP.
 *
 * @param   link_handshake_msg_rsp_ptr [IN] Pointer to a ipc_link_handshake_msg_t object.
 */
void ipc_on_ipcore_up_rsp(void *link_handshake_msg_rsp_ptr);

#endif /* __INC_IPC_NOTIFY_H */
