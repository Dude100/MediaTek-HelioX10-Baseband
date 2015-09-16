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
 *   ipc_dhcp_adp.c
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 *
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
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "kal_public_api.h"
#include "intrCtrl.h"
#include "mw_sap.h"
#include "dhcp4c_struct.h"
#include "ipcore_iph.h"

#include "ipc_defs.h"
#include "ipc_debug.h"
#include "ipc_utils.h"
#include "ipc_dhcp_adp.h"
#include "ipc_filter.h"
#include "ipc_notify.h"
#include "ipc_filter_priority.h"

/*------------------------------------------------------------------------------
 * Global variables.
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 * Helper macro.
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 * Privatate implementation.
 *----------------------------------------------------------------------------*/
void 
ipc_on_dl_dhcp4_packet(
        void       *context, 
        kal_int32   filter_id,
        qbm_gpd    *head_gpd, 
        qbm_gpd    *tail_gpd, 
        kal_uint32  length)
{
    ipc_session_t      *session = (ipc_session_t *)context;
    kal_int32           ip_id;
    dhcp4c_packet_req_struct   *packet_req;
    kal_uint8           dhcp_id;

    IPC_ASSERT(NULL != context && NULL != head_gpd && NULL != tail_gpd && 0 < length);

    IPC_R_LOCK_OBJECT(session);
    if (session) {
        ip_id   = session->ip_id;
        dhcp_id = session->dhcp4c_id;
        IPC_R_UNLOCK_OBJECT(session);

        if (head_gpd == tail_gpd) {
            packet_req = (dhcp4c_packet_req_struct *)construct_local_para(sizeof(dhcp4c_packet_req_struct), 0);
            packet_req->ip_id   = ip_id;
            packet_req->dhcp_id = dhcp_id;
            packet_req->gpd     = head_gpd;
    
            msg_send6(MOD_IPCORE, /* src_mod_id */
                      MOD_DHCP4C, /* dest_mod_id */
                      DHCP4C_SAP, /* sap_id */
                      MSG_ID_DHCP4C_PACKET_REQ, /* msg_id */
                      (local_para_struct *)packet_req, /* local_para_ptr */
                      NULL); /* peer_buff_ptr */
            return;
        } else {
            hif_trace_error(IPC_TR_DHCP4C_ON_DL_PACKET_INVALID_GPD_LIST, head_gpd, tail_gpd, length);
        }
    } else {
        hif_trace_error(IPC_TR_DHCP4C_ON_DL_PACKET_FIND_NO_SESSION, context);
    }

    /*
     * Free the downlink IP datagram filtered to BM if something wrong.
     */
    if (NULL != head_gpd && NULL != tail_gpd) {
        qbmt_dest_q(head_gpd, tail_gpd);
    }
}

/*------------------------------------------------------------------------------
 * Public fucntions.
 *----------------------------------------------------------------------------*/
void ipc_enable_dhcp4c(void *session_ptr)
{
    ipc_session_t      *session = (ipc_session_t *)session_ptr;
    ipc_filter_rules_t  rules;
    kal_int32           filter_id;
    kal_uint32          mask;
    dhcp4c_activate_req_struct  *activate_req;
    kal_int32           ip_id;
    kal_uint8           context;
    kal_uint8           type;
    static kal_uint8    hw_addr[] = {0x00, 0x0c, 0x7c, 0x00, 0x00, 0x00};

    IPC_R_LOCK_OBJECT(session);
    if (session) {
        context = session->context;
        type = session->type;
        ip_id = session->ip_id;
        IPC_R_UNLOCK_OBJECT(session);

        /*
         * Install a downlink filter for packet from DHCPv4 server.
         */
        kal_mem_set(&rules, 0, sizeof(rules));
        rules.priority = IPC_DL_FILTER_PRIORITY_IPC_DHCP_BEGIN;
        rules.valid_fields = ( IPC_FILTER_BY_PROTOCOL | 
                               IPC_FILTER_BY_SRC_PORT |
                               IPC_FILTER_BY_DST_PORT |
                               IPC_FILTER_BY_PDN_ID );
        rules.pdn_id = context;
        rules.ip_type = IPC_IP_TYPE_IPV4;
        rules.protocol = IPC_HDR_PROT_UDP;
        rules.src_port = IPC_PORT_BOOTPS;
        rules.dst_port = IPC_PORT_BOOTPC;
    
        filter_id = ipc_register_dl_filter_cbk(&rules, ipc_on_dl_dhcp4_packet, session);
        if (0 <= filter_id) {
            hif_trace_info(IPC_TR_DHCP4C_EN_REG_DL_FILTER_OK, context, type, filter_id);

            IPC_W_LOCK_OBJECT(session, mask);
            if (session) {
                session->dhcp4c_dl_filter_id = filter_id;
                IPC_W_UNLOCK_OBJECT(session, mask);
            }

            /*
             * Activate DHCPv4 client.
             */
            activate_req = (dhcp4c_activate_req_struct *)construct_local_para(sizeof(dhcp4c_activate_req_struct), 0);
            activate_req->ip_id = ip_id;
            activate_req->hardware_address_type = DHCP4C_HTYPE_ETHERNET;
            kal_mem_cpy(activate_req->hardware_address, hw_addr, sizeof(hw_addr));
            activate_req->hardware_address[5] = context;
    
            msg_send6(MOD_IPCORE, /* src_mod_id */
                      MOD_DHCP4C, /* dest_mod_id */
                      DHCP4C_SAP, /* sap_id */
                      MSG_ID_DHCP4C_ACTIVATE_REQ, /* msg_id */
                      (local_para_struct *)activate_req, /* local_para_ptr */
                      NULL); /* peer_buff_ptr */
        } else {
            hif_trace_error(IPC_TR_DHCP4C_EN_REG_DL_FILTER_NG, context, type, filter_id);
            IPC_ASSERT(KAL_FALSE);
        }
    } else {
        hif_trace_error(IPC_TR_DHCP4C_EN_FAILED_WITH_INVALID_PARAMETER);
    }
}

void ipc_on_dhcp4c_activate_rsp(void *activate_rsp_ptr)
{
    dhcp4c_activate_rsp_struct *activate_rsp = (dhcp4c_activate_rsp_struct *)activate_rsp_ptr;
    ipc_session_t      *session;
    kal_uint32          mask;
    kal_uint8           context;
    kal_uint8           type;
    kal_uint8           dhcp4c_id;

    session = ipc_find_session_by_ip_id(activate_rsp->ip_id, IPC_IP_TYPE_IPV4);
    if (session) {
        IPC_R_UNLOCK_OBJECT(session);
    
        if (DHCP4C_CAUSE_SUCCESS == activate_rsp->cause) {
            IPC_W_LOCK_OBJECT(session, mask);
            if (session) {
                context = session->context;
                type = session->type;
                dhcp4c_id = session->dhcp4c_id;
                session->dhcp4c_id = activate_rsp->dhcp_id;
                session->dhcp4c_running = KAL_TRUE;
                IPC_W_UNLOCK_OBJECT(session, mask);

                hif_trace_info(IPC_TR_DHCP4C_ACT_RSP_OK, context, type, dhcp4c_id);
                return;
            } else {
                hif_trace_error(IPC_TR_DHCP4C_ACT_RSP_INVALID_SESSION, activate_rsp->ip_id);
            }
        } else {
            hif_trace_error(IPC_TR_DHCP4C_ACT_RSP_NG, session->context, session->type);
        }

        ipc_disable_dhcp4c(session);
    } else {
        hif_trace_error(IPC_TR_DHCP4C_ACT_RSP_FIND_NO_SESSION, activate_rsp->ip_id);
    }
}

void ipc_disable_dhcp4c(void *session_ptr)
{
    ipc_session_t      *session = (ipc_session_t *)session_ptr;
    kal_uint32          mask;
    kal_int32           filter_id;
    kal_int32           ip_id;
    dhcp4c_deactivate_req_struct *deactivate_req;
    kal_bool            to_stop_dhcpc;
    kal_uint8           dhcp_id;
    kal_uint8           context;
    kal_uint8           type;

    IPC_W_LOCK_OBJECT(session, mask);
    if (session) {
        to_stop_dhcpc = session->dhcp4c_running;
        filter_id = session->dhcp4c_dl_filter_id;
        ip_id = session->ip_id;
        dhcp_id = session->dhcp4c_id;
        context = session->context;
        type = session->type;

        session->dhcp4c_running = KAL_FALSE;
        session->dhcp4c_dl_filter_id = -1;
        IPC_W_UNLOCK_OBJECT(session, mask);

        hif_trace_info(IPC_TR_DHCP4C_DIS_INFO, context, type, to_stop_dhcpc, dhcp_id, filter_id);

        /*
             * Deactivate DHCPv4 client.
             */
        if (to_stop_dhcpc) {
            deactivate_req = (dhcp4c_deactivate_req_struct *)construct_local_para(sizeof(dhcp4c_deactivate_req_struct), 0);
            deactivate_req->ip_id = ip_id;
            deactivate_req->dhcp_id = dhcp_id;

            msg_send6(MOD_IPCORE, /* src_mod_id */
                      MOD_DHCP4C, /* dest_mod_id */
                      DHCP4C_SAP, /* sap_id */
                      MSG_ID_DHCP4C_DEACTIVATE_REQ, /* msg_id */
                      (local_para_struct *)deactivate_req, /* local_para_ptr */
                      NULL); /* peer_buff_ptr */
        }

        /*
         * Uninstall the downlink filter.
         */
        if (0 <= filter_id) {
            ipc_deregister_dl_filter(filter_id);
            hif_trace_info(IPC_TR_DHCP4C_DIS_DEREG_DL_FILTER_OK, session->context, session->type, filter_id);
        }
    } else {
        hif_trace_error(IPC_TR_DHCP4C_DIS_FAILED_WITH_INVALID_PARAMETER);
    }
}

void ipc_on_dhcp4c_deactivate_rsp(void *deactivate_rsp_ptr)
{
    /* do nothing since we have done the clean up in ipc_disable_dhcp4c(). */
}

void ipc_on_dhcp4c_ip_up_ind(void *dhcp4c_ip_up_ind_ptr)
{
    dhcp4c_ip_up_ind_struct *ip_up_ind = (dhcp4c_ip_up_ind_struct *)dhcp4c_ip_up_ind_ptr;
    ipc_session_t      *session;
    ipc_session_state_e session_state;

    hif_trace_info(IPC_TR_DHCP4C_IP_UP_IND_START, dhcp4c_ip_up_ind_ptr);

    session = ipc_find_session_by_ip_id(ip_up_ind->ip_id, IPC_IP_TYPE_IPV4);

    hif_trace_info(IPC_TR_DHCP4C_IP_UP_IND_FIND_SESSION_RESULT, session, ip_up_ind->ip_id);

    if (session) {
        session_state = session->state;
        IPC_R_UNLOCK_OBJECT(session);

        hif_trace_info(IPC_TR_DHCP4C_IP_UP_IND_SESSION_STATE, session, session_state);

        /* Only handle following states */
        if (    session_state == IPC_SESSION_STATE_BIND ||
                session_state == IPC_SESSION_STATE_PRE_LINKUP_IPV4_LEASE ||
                session_state == IPC_SESSION_STATE_IPV4_LEASE)
        {

        if (    session_state == IPC_SESSION_STATE_BIND ||
                session_state == IPC_SESSION_STATE_PRE_LINKUP_IPV4_LEASE    )
        {   /* Not linkup for IPv4 yet : swtich to Pre-link up */
            ipc_update_session_state(session, IPC_SESSION_STATE_PRE_LINKUP);
        
        } else
        {   /* Already linkup for IPv4 before : swtich to Pre-IPv4 relocate */
            ipc_update_session_state(session, IPC_SESSION_STATE_PRE_IPV4_RELOCATE);
        }
        } else
        {
            hif_trace_error(IPC_TR_DHCP4C_IP_UP_IND_SESSION_STATE_INCORRECT, ip_up_ind->ip_id, session, session_state);
        }
    } else
    {
        hif_trace_error(IPC_TR_DHCP4C_IP_UP_IND_FIND_NO_SESSION, ip_up_ind->ip_id);
    }

    hif_trace_info(IPC_TR_DHCP4C_IP_UP_IND_END, dhcp4c_ip_up_ind_ptr);
}

void ipc_on_dhcp4c_ip_down_ind(void *dhcp4c_ip_down_ind_ptr)
{
    dhcp4c_ip_down_ind_struct *ip_down_ind = (dhcp4c_ip_down_ind_struct *)dhcp4c_ip_down_ind_ptr;
    ipc_session_t      *session;
    ipc_session_state_e session_state;

    hif_trace_info(IPC_TR_DHCP4C_IP_DOWN_IND_START, dhcp4c_ip_down_ind_ptr);


    session = ipc_find_session_by_ip_id(ip_down_ind->ip_id, IPC_IP_TYPE_IPV4);

    hif_trace_info(IPC_TR_DHCP4C_IP_DOWN_IND_FIND_SESSION_RESULT, session, ip_down_ind->ip_id);

    if (session) {
        session_state = session->state;
        IPC_R_UNLOCK_OBJECT(session);

        hif_trace_info(IPC_TR_DHCP4C_IP_DOWN_IND_SESSION_STATE, session, session_state);


        /* Only handle following states */
        if(     session_state == IPC_SESSION_STATE_PRE_LINKUP ||
                session_state == IPC_SESSION_STATE_PRE_IPV4_RELOCATE ||
                session_state == IPC_SESSION_STATE_LINKUP)
        {
        if (session_state == IPC_SESSION_STATE_PRE_LINKUP)
        {   /* Not linkup for IPv4 yet : swtich to Pre-link up lease state */
            ipc_update_session_state(session, IPC_SESSION_STATE_PRE_LINKUP_IPV4_LEASE);
        } else
        {   /* Already linkup for IPv4 before : swtich to IPv4 lease state */
            ipc_update_session_state(session, IPC_SESSION_STATE_IPV4_LEASE);
        }
        } else
        {
            hif_trace_error(IPC_TR_DHCP4C_IP_DOWN_IND_SESSION_STATE_INCORRECT, ip_down_ind->ip_id, session, session_state);
        }
    } else 
    {
        hif_trace_error(IPC_TR_DHCP4C_IP_DOWN_IND_FIND_NO_SESSION, ip_down_ind->ip_id);
    }

    hif_trace_info(IPC_TR_DHCP4C_IP_DOWN_IND_END, ip_down_ind);
}

void ipc_on_dhcp4c_packet_ind(void *dhcp4c_packet_ind_ptr)
{
    dhcp4c_packet_ind_struct   *packet_ind = (dhcp4c_packet_ind_struct *)dhcp4c_packet_ind_ptr;
    ipc_session_t              *session;
    ipc_netif_t                *netif;
    qbm_gpd                    *gpd;
    ipc_io_request_t           *ior;

    IPC_ASSERT(packet_ind);
    gpd = packet_ind->gpd;
    IPC_ASSERT(gpd);

    session = ipc_find_session_by_ip_id(packet_ind->ip_id, IPC_IP_TYPE_IPV4);

    hif_data_trace(IPC_UL_DHCP4C_PKT_SESSION, 0, gpd, packet_ind->ip_id, session);

    if (session)
    {
        netif = session->netif;
        IPC_R_UNLOCK_OBJECT(session);

        hif_data_trace(IPC_UL_DHCP4C_PKT_UPLINK, 0, gpd, session, netif->config.netif_id);

        ior = (ipc_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(gpd);
        kal_mem_set(ior, 0, sizeof(ipc_io_request_t));
        ior->first_gpd      = gpd;
        ior->last_gpd       = gpd;
        ior->ip_type        = IPC_IP_TYPE_IPV4;

        if (!ipc_uplink(netif, ior))
        {
            hif_trace_error(IPC_TR_DHCP4C_IP_PACKET_IND_UPLINK_NG, packet_ind->ip_id);
            qbmt_dest_q(gpd, gpd);
        }
    } else
    {
        hif_trace_error(IPC_TR_DHCP4C_IP_PACKET_IND_FIND_NO_SESSION, gpd, packet_ind->ip_id);
        qbmt_dest_q(gpd, gpd);
    }
}

