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
 *   ipc_dhcp_adp.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   DHCP adaption.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __INC_IPC_DHCP_ADP_H
#define __INC_IPC_DHCP_ADP_H

/*------------------------------------------------------------------------------
 * Data structure defintion.
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 * Function prototype.
 *----------------------------------------------------------------------------*/
/*!
 * Enable DHCPv4 client for a IPv4 or IPv4v6 session.
 *
 * @param   session_ptr [IN] The session object.
 */
void ipc_enable_dhcp4c(void *session_ptr);

/*!
 * Handler of the message MSG_ID_DHCP4C_ACTIVATE_RSP.
 *
 * @param   activate_rsp_ptr [IN] Pointer to a dhcp4c_activate_rsp_struct object.
 */
void ipc_on_dhcp4c_activate_rsp(void *activate_rsp_ptr);

/*!
 * Disable DHCPv4 client for a IPv4 or IPv4v6 session.
 *
 * @param   session_ptr [IN] The session object.
 */
void ipc_disable_dhcp4c(void *session_ptr);

/*!
 * Handler of the message MSG_ID_DHCP4C_DEACTIVATE_RSP.
 *
 * @param   deactivate_rsp_ptr [IN] Pointer to a dhcp4c_deactivate_rsp_struct object.
 */
void ipc_on_dhcp4c_deactivate_rsp(void *deactivate_rsp_ptr);

/*!
 * Handler of the message MSG_ID_DHCP4C_IP_UP_IND.
 *
 * @param   dhcp4c_ip_up_ind_ptr [IN] Pointer to a dhcp4c_ip_up_ind_struct object.
 */
void ipc_on_dhcp4c_ip_up_ind(void *dhcp4c_ip_up_ind_ptr);

/*!
 * Handler of the message MSG_ID_DHCP4C_IP_DOWN_IND.
 *
 * @param   dhcp4c_ip_down_ind_ptr [IN] Pointer to a dhcp4c_ip_down_ind_struct object.
 */
void ipc_on_dhcp4c_ip_down_ind(void *dhcp4c_ip_down_ind_ptr);

/*!
 * Handler of the message MSG_ID_DHCP4C_PACKET_IND.
 *
 * @param   dhcp4c_packet_ind_ptr [IN] Pointer to a dhcp4c_packet_ind_struct object.
 */
void ipc_on_dhcp4c_packet_ind(void *dhcp4c_packet_ind_ptr);

#endif /* __INC_IPC_DHCP_ADP_H */
