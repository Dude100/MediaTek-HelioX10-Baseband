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
 *   ipc_session.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   IP session management.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __INC_IPC_SESSION_H
#define __INC_IPC_SESSION_H

#include "kal_public_api.h"

#include "ipc_api.h"
#include "ipc_object.h"

/*------------------------------------------------------------------------------
 * Data structure defintion.
 *----------------------------------------------------------------------------*/
#define IPC_SESSION_MAP_SIZE        2

typedef enum _ipc_session_state_e {
    IPC_SESSION_STATE_MIN = 0,
    IPC_SESSION_STATE_UNBIND,
    IPC_SESSION_STATE_BIND,
    IPC_SESSION_STATE_PRE_LINKUP,
    IPC_SESSION_STATE_PRE_LINKUP_IPV4_LEASE,
    IPC_SESSION_STATE_LINKUP,
    IPC_SESSION_STATE_IPV4_LEASE,
    IPC_SESSION_STATE_PRE_IPV4_RELOCATE,
    IPC_SESSION_STATE_MAX,
    IPC_SESSION_STATE_INVALID,
} ipc_session_state_e;

typedef enum _ipc_session_transition_action_case_e {
    IPC_SST_NULL = 0,
    IPC_SST_MIN,
    IPC_SST_NA,     /* Do nothing excepting state transition */
    IPC_SST_LUI,    /* Send Link up indication to handler */
    IPC_SST_LUR,    /* Send Link up request to network interface */
    IPC_SST_LDR,    /* Send Link down request to network interface */
    IPC_SST_IUI,    /* Send IPv4 up indication to handler */
    IPC_SST_IUR,    /* Send IPv4 up request to network interface */
    IPC_SST_IDR,    /* Send IPv4 down request to network interface */
    IPC_SST_MAX,
} ipc_session_transition_action_case_e;

typedef struct _ipc_netif_t {
    IPC_DECLARE_OBJECT

    kal_uint32      bit_id;
    ipc_conf_t      config;
    kal_uint32      session_cnt;
    void           *session_map[IPC_SESSION_MAP_SIZE];
} ipc_netif_t;

typedef struct _ipc_session_t {
    IPC_DECLARE_OBJECT

    kal_uint8       context; /**< Key to identify the IP session. */
    kal_uint8       type; /**< Type of the IP session, including IPC_IP_TYPE_IPV4, IPC_IP_TYPE_IPV6, IPC_IP_TYPE_MIXED. */
    ipc_session_state_e state;  /**< FSM state of session */
    kal_bool        dhcp4c_running; /**< Indicate if DHCPv4 client is running or not. */
    kal_uint8       dhcp4c_id; /**< DHCPv4 client instance ID if dhcp4c_running is KAL_TRUE. */
    kal_int32       dhcp4c_dl_filter_id; /**< Zero or positive value for a downlink filter installed DHCPv4; Negative value otherwise. */

    kal_int32       ip_id; /**< An ID for an HIF network interface to tell the associated IP session(s). */
    ipc_netif_t    *netif; /**< Associated HIF network interface. */
} ipc_session_t;

/*------------------------------------------------------------------------------
 * Function prototype.
 *----------------------------------------------------------------------------*/

/*!
 * Initialize all objects.
 */
void ipc_object_init(void);

/*!
 * Find an HIF network interface.
 * Note that, caller MUST release the control to network interface 
 * through IPC_R_UNLOCK_OBJECT() once done with it.
 *
 * @param   netif_id [IN] ID of the network interface interested.
 *
 * @return An ipc_netif_t object if found, NULL otherwise.
 */
ipc_netif_t *ipc_find_netif(kal_uint32 netif_id);

/*!
 * Find an HIF network interface through a bit index.
 * Note that, caller MUST release the control to network interface 
 * through IPC_R_UNLOCK_OBJECT() once done with it.
 *
 * @param   bit_id [IN] bit index.
 *
 * @return An ipc_netif_t object if found, NULL otherwise.
 */
ipc_netif_t *ipc_find_netif_by_bit_id(kal_uint32 bit_id);

/*!
 * Create an ipc_netif_t object for an HIF network interface attached.
 * Note that, if the network interface is already attached, this function will return NULL.
 *
 * @param   config [IN] Configuration of the netowrk interface attached.
 *
 * @return An ipc_netif_t object if succeeded, NULL otherwise.
 */
ipc_netif_t *ipc_new_netif(ipc_conf_t *config);

/*!
 * Destroy the ipc_netif_t object for the HIF network interface to detach.
 * Note that, if the netowrk interface is not a valid one, this function wll fail. 
 *
 * @param   netif [IN] The netowrk interface to detach.
 *
 * @return  KAL_TRUE if succeed, KAL_FALSE otherwise.
 */
kal_bool ipc_del_netif(ipc_netif_t *netif);

/*!
 * Query netif list to get latest status.
 *
 * @param   netif_list_p [IN] The network interface list strcture to collect status.
 *
 * @return  KAL_TRUE if succeed, KAL_FALSE otherwise.
 */
kal_bool ipc_query_netif_list(ipc_netif_list_t *netif_list_p);

/*!
 * Update handling module of LINK_UP_IND ILM 
 *
 * @param   module_id [IN] Module ID to handle MSG_ID_IPCORE_LINK_UP_IND and send MSG_ID_IPCORE_LINK_UP_RSP as response.
 */
void ipc_update_link_up_ind_handler(module_type module_id);

/*!
 * Update handling module of IP_UP_IND ILM 
 *
 * @param   module_id [IN] Module ID to handle MSG_ID_IPCORE_IP_UP_IND and send MSG_ID_IPCORE_IP_UP_RSP as response.
 */
void ipc_update_ip_up_ind_handler(module_type module_id);

/*!
 * Indicate the HIF network interface link/IP status changed for handler process. Real IPCORE operation will done after handler response for the indication.
 *
 * @param   netif [IN] The netowrk interface.
 * @param   ip_type [IN] Type of the PDN, IPC_IP_TYPE_IPV4, IPC_IP_TYPE_IPV6, or IPC_IP_TYPE_MIXED.
 * @param   link_update[IN] KAL_TRUE if an IP session is established/deactived and link status is changed. KAL_FALSE if an IP information is updated for an activated IP session.
 * @param   link_up [IN] (If link_update is KAL_TRUE) KAL_TRUE if an IP session is established, KAL_FALSE if an IP session is deactived ;
                                    (If link_update is KAL_FALSE) KAL_TRUE if new IP information is available, KAL_FALSE if original IP information is obsoleted
 */
void ipc_indicate_netif_link_change(ipc_netif_t *netif, kal_uint8 ip_type, kal_bool link_update, kal_bool is_up);

/*!
 * Notify the HIF network interface link/IP status changed.
 *
 * @param   netif [IN] The netowrk interface.
 * @param   ip_type [IN] Type of the PDN, IPC_IP_TYPE_IPV4, IPC_IP_TYPE_IPV6, or IPC_IP_TYPE_MIXED.
 * @param   link_update[IN] KAL_TRUE if an IP session is established/deactived and link status is changed. KAL_FALSE if an IP information is updated for an activated IP session.
 * @param   link_up [IN] (If link_update is KAL_TRUE) KAL_TRUE if an IP session is established, KAL_FALSE if an IP session is deactived ;
                                    (If link_update is KAL_FALSE) KAL_TRUE if new IP information is available, KAL_FALSE if original IP information is obsoleted
 */
void ipc_notify_netif_link_change(ipc_netif_t *netif, kal_uint8 ip_type, kal_bool link_update, kal_bool is_up);

/*!
 * Find index of the associated IP session.
 *
 * @param   netif [IN] The netowrk interface.
 *
 * @return Index of the associated IP session, <0 means no associated IP session is found.
 */
kal_int32 ipc_map_netif_to_ip_id(ipc_netif_t *netif);

/*!
 * Specify the network interface needs UL reload retry or not.
 *
 * @param   netif [IN] The netowrk interface.
 * @param   need_ul_reload [IN] KAL_TRUE if it needs UL reload retry, KAL_FALSE otherwise.
 */
void ipc_set_netif_ul_reload_retry(ipc_netif_t *netif, kal_bool need_ul_reload);

/*!
 * Specify if the network interface calls ipc_need_ul_retry between netif's reload cbk and ul_reload_retry be set.
 *
 * @param   netif [IN] The netowrk interface.
 * @param   need_ul_reload [IN] KAL_TRUE if it needs UL reload retry, KAL_FALSE otherwise.
 */
void ipc_set_netif_ul_set_need_reload(ipc_netif_t *netif, kal_bool need_ul_reload);

/*!
 * Get UL reload status of all network interfaces.
 *
 * @return Each bit indicate if the corresponding network interface needs UL reload retry.
 */
kal_uint32 ipc_get_all_netif_ul_reload_retry(void);

/*!
 * Execute session state transition and corresponding behavior.
 *
 * @param   session [IN] The netowrk session.
 * @param   session_state [IN] New session type to translate.
 * @return KAL_TRUE if succeed, KAL_FALSE otherwise.
 */
kal_bool ipc_update_session_state(ipc_session_t *session, ipc_session_state_e session_state);

/*!
 * Find an IP session with specified session_context.
 * Note that, caller MUST release the control to IP session 
 * through IPC_R_UNLOCK_OBJECT() once done with it.
 *
 * @param   session_context [IN] Key to identify the IP session.
 *
 * @return An ipc_session_t object if found, NULL otherwise.
 */
ipc_session_t *ipc_find_session_by_context(kal_uint8 session_context);

/*!
 * Find the session object associated with specified HIF network interface and session_type.
 * Note that, caller MUST release the control to IP session 
 * through IPC_R_UNLOCK_OBJECT() once done with it.
 *
 * @param   netif [IN] The netowrk interface.
 * @param   session_type [IN] Type of the IP session, either IPC_IP_TYPE_IPV4 or IPC_IP_TYPE_IPV6.
 *
 * @return An ipc_session_t object if found, NULL otherwise.
 */
ipc_session_t *ipc_find_session_by_netif(ipc_netif_t *netif, kal_uint8 session_type);

/*!
 * Find the session object associated with specified ip_id and session type.
 * Note that, caller MUST release the control to IP session 
 * through IPC_R_UNLOCK_OBJECT() once done with it.
 *
 * @param   ip_id [IN] An ID for an HIF network interface to tell the associated IP session(s).
 * @param   session_type [IN] Type of the IP session, either IPC_IP_TYPE_IPV4 or IPC_IP_TYPE_IPV6.
 *
 * @return An ipc_session_t object if found, NULL otherwise.
 */
ipc_session_t *ipc_find_session_by_ip_id(kal_int32 ip_id, kal_uint8 session_type);

/*!
 * Create an ipc_session_t object for the IP session established.
 *
 * @param   netif [IN] HIF network interface associated with the IP sesion.
 * @param   session_context [IN] Key to identify the IP session.
 * @param   session_type [IN] Type of the IP session: IPC_IP_TYPE_IPV4, IPC_IP_TYPE_IPV6, or IPC_IP_TYPE_MIXED.
 * @param   session_state [IN] Initial state of the IP session.
 *
 * @return An ipc_session_t object if succeeded, NULL otherwise.
 */
ipc_session_t *ipc_new_session(ipc_netif_t *netif, kal_uint8 session_context, kal_uint8 session_type, ipc_session_state_e session_state);

/*!
 * Destroy the ipc_session_t object for the IP session deactivated.
 *
 * @param   session [IN] IP session deactivated.
 */
void ipc_del_session(ipc_session_t *session);

#endif /* __INC_IPC_SESSION_H */
