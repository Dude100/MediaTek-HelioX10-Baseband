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
 *   ipc_session.c
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
 *
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

#include "kal_public_api.h"
#include "intrCtrl.h"
#include "mw_sap.h"

#include "qmu_bm.h"
#include "qmu_bm_size.h"
#include "qmu_bm_util.h"
#include "qmu_bm_flc.h"

#include "ipc_defs.h"
#include "ipc_debug.h"
#include "ipc_utils.h"
#include "ipc_filter.h"
#include "ipc_notify.h"

/*------------------------------------------------------------------------------
 * Global variables.
 *----------------------------------------------------------------------------*/
static ipc_netif_t      ipc_netifs_s[IPC_MAX_NETIF_CNT];

/*
 *  Prevent the race condition of UL reload:
 *      - ipc_netif_ul_reload_retry_s: modified in IPCORE context.
 *      - ipc_netif_ul_set_need_reload_s: modified by netifs in their context.
 */
static kal_uint32       ipc_netif_ul_reload_retry_s = 0;
static kal_uint32       ipc_netif_ul_set_need_reload_s = 0;

static ipc_session_t    ipc_sessions_s[IPC_MAX_SESSION_CNT];
static kal_bool         ipc_ids_s[IPC_MAX_IP_ID_CNT];

static const ipc_session_transition_action_case_e session_transition_action_table[IPC_SESSION_STATE_MAX /* ORG */][IPC_SESSION_STATE_MAX /* NEW */] =
{
/*                                              NEW                                                                                                                                                         ORG */
/*  MIN               UNBIND          BIND             PRE_LINKUP   PRE_LINKUP_IPV4_LEASE  LINKUP          IPV4_LEASE    PRE_IPV4_RELOCATE */
{  0,          0,          0,          0,          0,                    0,          0,          0                   /* MIN */                  },
{  0,          0,          IPC_SST_NA, 0,          0,                    0,          0,          0                   /* UNBIND */               },
{  0,          IPC_SST_NA, 0,          IPC_SST_LUI,0,                    0,          0,          0                   /* BIND */                 },
{  0,          IPC_SST_NA, 0,          0,          IPC_SST_NA,           IPC_SST_LUR,0,          0                   /* PRE_LINKUP */           },
{  0,          IPC_SST_NA, 0,          IPC_SST_LUI,0,                    0,          0,          0                   /* PRE_LINKUP_IPV4_LEASE */},
{  0,          IPC_SST_LDR,0,          0,          0,                    0,          IPC_SST_IDR,0                   /* LINKUP */               },
{  0,          IPC_SST_LDR,0,          0,          0,                    0,          0,          IPC_SST_IUI         /* IPV4_LEASE */           },
{  0,          IPC_SST_LDR,0,          0,          IPC_SST_NA,           IPC_SST_IUR,0,          0                   /* PRE_IPV4_RELOCATE */   },
};

static module_type ipc_link_up_indication_handler;
static module_type ipc_ip_up_indication_handler;

/*------------------------------------------------------------------------------
 * Helper macro.
 *----------------------------------------------------------------------------*/

#define ipc_session_type_hash(_session_type) \
            ((_session_type) & 0x1)

/*
 * 2011/12/16: SD1/Moja guarantees pdn_id falls in [0,15].
 */
#define IPC_CONTEXT_TO_SESSION(_context, _session) \
        IPC_ASSERT((_context) < IPC_MAX_SESSION_CNT); \
        (_session) = &(ipc_sessions_s[(_context)])

/*------------------------------------------------------------------------------
 * Private data structure.
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 * Private functions.
 *----------------------------------------------------------------------------*/
static kal_int32 ipc_new_id(ipc_netif_t *netif)
{
    kal_int32   ip_id = -1;
    kal_int32   idx;

    /*
     * No need to protect ipc_ids_s[] if only one possible context.
     */
    IPC_ASSERT(KAL_FALSE == kal_if_hisr());
    IPC_UT_ASSERT( (ipc_is_in_reset() || MOD_IPCORE == kal_get_active_module_id()), 
                    IPC_UT_NO_ERROR );

    /*
     * If the associated netif has a valid ip_id (e.g. IPv4 + IPv6 case), use it.
     */
    IPC_R_LOCK_OBJECT(netif);
    if (netif) {
        ip_id = ipc_map_netif_to_ip_id(netif);
        IPC_R_UNLOCK_OBJECT(netif);
    }

    /*
     * Otherwise, select minimal ip_id available.
     */
    if (ip_id < 0) {
        for (idx = 0; idx < IPC_MAX_IP_ID_CNT; idx++) {
            if (!ipc_ids_s[idx]) {
                ipc_ids_s[idx] = KAL_TRUE;
                ip_id = idx;
                break;
            }
        }
    }
    return ip_id;
}

static void ipc_del_id(kal_int32 ip_id)
{
    /*
     * No need to protect ipc_ids_s[] if only one possible context.
     */
    IPC_ASSERT(KAL_FALSE == kal_if_hisr());
    IPC_UT_ASSERT( (ipc_is_in_reset() || MOD_IPCORE == kal_get_active_module_id()), 
                    IPC_UT_NO_ERROR );

    if (ip_id < IPC_MAX_IP_ID_CNT) {
        ipc_ids_s[ip_id] = KAL_FALSE;
    }
}

/*------------------------------------------------------------------------------
 * Public fucntions.
 *----------------------------------------------------------------------------*/
void ipc_object_init(void)
{
    kal_uint32      idx;

    kal_mem_set( ipc_netifs_s, 0, sizeof(ipc_netifs_s) );
    for (idx = 0; idx < IPC_MAX_NETIF_CNT; idx++) {
        ipc_netifs_s[idx].bit_id = (1 << idx);
    }

    ipc_netif_ul_reload_retry_s = 0;

    kal_mem_set( ipc_sessions_s, 0, sizeof(ipc_sessions_s) );
    kal_mem_set( ipc_ids_s, 0, sizeof(ipc_ids_s) );

    ipc_link_up_indication_handler = MOD_IPCORE;
    ipc_ip_up_indication_handler = MOD_IPCORE;

    ipc_filter_init();
    ipc_ntfy_init();
}

ipc_netif_t *ipc_find_netif(kal_uint32 netif_id)
{
    ipc_netif_t     *netif;
    kal_uint32       idx;

    for (idx = 0; idx < IPC_MAX_NETIF_CNT; idx++) {
        netif = &(ipc_netifs_s[idx]);
        IPC_R_LOCK_OBJECT(netif);
        if (netif) {
            if (netif->config.netif_id == netif_id) {
                return netif;
            } else {
                IPC_R_UNLOCK_OBJECT(netif);
            }
        }
    }
    return NULL;
}

ipc_netif_t *ipc_find_netif_by_bit_id(kal_uint32 bit_id)
{
    ipc_netif_t     *netif;
    kal_uint32       min = 0;
    kal_uint32       max = IPC_MAX_NETIF_CNT - 1;
    kal_uint32       cut;

    do {
        cut = ((max + min) >> 1);
        netif = &(ipc_netifs_s[cut]);

        if (bit_id == netif->bit_id) {
            IPC_R_LOCK_OBJECT(netif);
            if (netif) {
                return netif;
            } else {
                break;
            }
        } else if (bit_id < netif->bit_id) {
            max = cut - 1;
        } else {
            min = cut + 1;
        }
    } while (min <= max);

    return NULL;
}

ipc_netif_t *ipc_new_netif(ipc_conf_t *config)
{
    ipc_netif_t     *netif;
    kal_uint32       idx;
    kal_uint32       mask;

    netif = ipc_find_netif(config->netif_id);
    if (NULL == netif) {
        for (idx = 0; idx < IPC_MAX_NETIF_CNT; idx++) {
            netif = &(ipc_netifs_s[idx]);
            if (!IPC_IS_VALID_OBJECT(netif)) {
                IPC_INIT_OBJECT_BEGIN(netif, mask);

                kal_mem_cpy( &(netif->config), config, sizeof(ipc_conf_t) );
                netif->session_cnt = 0;
                kal_mem_set( netif->session_map, 0, sizeof(netif->session_map) );

                IPC_INIT_OBJECT_END(netif, mask);

                ipc_set_netif_ul_reload_retry(netif, KAL_FALSE);
                hif_trace_info(IPC_TR_NETIF_ATTACHED, config->module_id, config->netif_id);
                return netif;
            }
        }
        hif_trace_error(IPC_TR_NETIF_ATTACH_OUT_OF_SPACE, config->module_id, config->netif_id);
    } else {
        IPC_R_UNLOCK_OBJECT(netif);
        hif_trace_error(IPC_TR_NETIF_ATTACH_DUPLICATED, config->module_id, config->netif_id);
    }

    return NULL;
}

kal_bool ipc_del_netif(ipc_netif_t *netif)
{
    kal_uint32      idx;
    ipc_session_t  *session;
    kal_uint32      mask;

    if (IPC_IS_VALID_OBJECT(netif)) {
        ipc_set_netif_ul_reload_retry(netif, KAL_FALSE);
        IPC_DEINIT_OBJECT_BEGIN(netif, mask);

        for (idx = 0; idx < IPC_SESSION_MAP_SIZE; idx++) {
            session =  netif->session_map[idx];

            IPC_W_LOCK_OBJECT(session, mask);
            if (session)
            {
                session->netif = NULL;
                IPC_W_UNLOCK_OBJECT(session, mask);
            }
        }

        hif_trace_info(IPC_TR_NETIF_DETACHED, netif->config.module_id, netif->config.netif_id);
        IPC_DEINIT_OBJECT_END(netif, mask);
        return KAL_TRUE;
    } else {
        hif_trace_error(IPC_TR_NETIF_DETACH_INVALID);
        return KAL_FALSE;
    }
}

kal_bool ipc_query_netif_list(ipc_netif_list_t *netif_list_p)
{
    ipc_netif_t *netif;
    kal_uint32 idx;

    IPC_ASSERT(netif_list_p);

    hif_trace_info(IPC_TR_QUERY_NETIF_LIST_START, netif_list_p);
    if (netif_list_p)
    {
        kal_mem_set(netif_list_p, 0, sizeof(ipc_netif_list_t));

        for (idx = 0; idx < IPC_MAX_NETIF_CNT; idx++) {
            netif = &(ipc_netifs_s[idx]);
            IPC_R_LOCK_OBJECT(netif);
            if (netif) {
                netif_list_p->list[netif_list_p->netif_cnt].netif_id = netif->config.netif_id;
                netif_list_p->netif_cnt ++;
                IPC_R_UNLOCK_OBJECT(netif);
                hif_trace_info(IPC_TR_QUERY_NETIF_LIST_INFO,    netif_list_p->netif_cnt,
                                                                netif_list_p->list[netif_list_p->netif_cnt-1].netif_id);
            }
        }

        hif_trace_info(IPC_TR_QUERY_NETIF_LIST_SUCCESS, netif_list_p->netif_cnt);
        return KAL_TRUE;
    }
    hif_trace_error(IPC_TR_QUERY_NETIF_LIST_FAILED);
    return KAL_FALSE;
}

void ipc_update_link_up_ind_handler(module_type module_id)
{
    hif_trace_info(IPC_TR_UPDATE_LINK_UP_IND_HDLR_START, module_id);
    ipc_link_up_indication_handler = module_id;
}

void ipc_update_ip_up_ind_handler(module_type module_id)
{
    hif_trace_info(IPC_TR_UPDATE_IP_UP_IND_HDLR_START, module_id);
    ipc_ip_up_indication_handler = module_id;
}

void ipc_indicate_netif_link_change(ipc_netif_t *netif, kal_uint8 ip_type, kal_bool link_update, kal_bool is_up)
{
    ipc_link_handshake_msg_t    *link_handshake_msg_p;
    module_type                 src_mod_id;
    module_type                 dest_mod_id;
    msg_type                    message_type;
    kal_uint32                  netif_id;
    kal_int32                   ip_id;

    if (NULL == netif) return;

    /* IP CORE supports LINK_UP_IND / IP_UP_IND only */
    IPC_ASSERT(KAL_TRUE == is_up);

    IPC_R_LOCK_OBJECT(netif);
    if (netif) {
        netif_id = netif->config.netif_id;
        ip_id = ipc_map_netif_to_ip_id(netif);
        IPC_R_UNLOCK_OBJECT(netif);

        link_handshake_msg_p = (ipc_link_handshake_msg_t *)construct_local_para(sizeof(ipc_link_handshake_msg_t), TD_RESET);
        IPC_ASSERT(link_handshake_msg_p);

        link_handshake_msg_p->netif_id = netif_id;
        link_handshake_msg_p->ip_id = ip_id;
        link_handshake_msg_p->ip_type = ip_type;

        if (KAL_TRUE == link_update)
        {   /* To update Link status */
            src_mod_id      = (MOD_IPCORE == ipc_link_up_indication_handler)?MOD_NIL:MOD_IPCORE;
            dest_mod_id     = ipc_link_up_indication_handler;
            message_type    = MSG_ID_IPCORE_LINK_UP_IND;
        } else
        {   /* To update IP status */
            src_mod_id      = (MOD_IPCORE == ipc_ip_up_indication_handler)?MOD_NIL:MOD_IPCORE;
            dest_mod_id     = ipc_ip_up_indication_handler;
            message_type    = MSG_ID_IPCORE_IP_UP_IND;
        }

        msg_send6(src_mod_id, /* src_mod_id */
                  dest_mod_id, /* dest_mod_id */
                  IPCORE_SAP, /* sap_id */
                  message_type, /* msg_id */
                  (struct local_para_struct *)link_handshake_msg_p, /* local_para_ptr */
                  NULL); /* peer_buff_ptr */
    }
}


void ipc_notify_netif_link_change(ipc_netif_t *netif, kal_uint8 ip_type, kal_bool link_update, kal_bool is_up)
{
    ipc_link_req_t *link_req;
    void           *context;
    module_type     module_id;
    msg_type        message_type;
    ipc_ntfy_type_e notify_type;

    if (NULL == netif) return;

    IPC_R_LOCK_OBJECT(netif);
    if (netif) {
        context = netif->config.callback_context;
        module_id = netif->config.module_id;
        IPC_R_UNLOCK_OBJECT(netif);

        link_req = (ipc_link_req_t *)construct_local_para(sizeof(ipc_link_req_t), TD_RESET);
        IPC_ASSERT(link_req);

        link_req->callback_context = context;
        link_req->ip_type = ip_type;

        if (KAL_TRUE == link_update)
        {   /* To update Link status */
            message_type    = is_up ? MSG_ID_IPCORE_LINK_UP_REQ : MSG_ID_IPCORE_LINK_DOWN_REQ;
            notify_type     = is_up ? IPC_NTFY_TYPE_LINK_UP:IPC_NTFY_TYPE_LINK_DOWN;
        } else
        {   /* To update IP status */
            message_type    = is_up ? MSG_ID_IPCORE_IP_UP_REQ : MSG_ID_IPCORE_IP_DOWN_REQ;
            notify_type     = is_up ? IPC_NTFY_TYPE_IP_UP:IPC_NTFY_TYPE_IP_DOWN;
        }

        /* Callback for notifications */
        ipc_do_ntfy(netif, notify_type);

#ifdef ATEST_SYS_IPCORE
        ipc_ut_msg_send6(   MOD_IPCORE, /* src_mod_id */
                            module_id, /* dest_mod_id */
                            IPCORE_SAP, /* sap_id */
                            message_type, /* msg_id */
                            (struct local_para_struct *)link_req, /* local_para_ptr */
                            NULL); /* peer_buff_ptr */
#else
        msg_send6(MOD_IPCORE, /* src_mod_id */
                  module_id, /* dest_mod_id */
                  IPCORE_SAP, /* sap_id */
                  message_type, /* msg_id */
                  (struct local_para_struct *)link_req, /* local_para_ptr */
                  NULL); /* peer_buff_ptr */
#endif
    }
}

void ipc_notify_all_netif_link_change(kal_uint8 ip_type, kal_bool link_up)
{
    kal_uint32      idx;
    ipc_netif_t    *netif;

    for (idx = 0; idx < IPC_MAX_NETIF_CNT; idx++) {
        netif = &(ipc_netifs_s[idx]);

        IPC_R_LOCK_OBJECT(netif);
        if (netif) {
            IPC_R_UNLOCK_OBJECT(netif);

            ipc_notify_netif_link_change(netif, ip_type, KAL_TRUE, link_up);
        }
    }
}

kal_int32 ipc_map_netif_to_ip_id(ipc_netif_t *netif)
{
    ipc_session_t  *session;
    kal_uint32      idx;
    kal_int32       ip_id;

    IPC_ASSERT(IPC_IS_VALID_OBJECT(netif));

    if (netif->session_cnt > 0) {
        for (idx = 0; idx < IPC_SESSION_MAP_SIZE; idx++) {
            session =  netif->session_map[idx];
            IPC_R_LOCK_OBJECT(session);
            if (session) {
                ip_id = session->ip_id;
                IPC_R_UNLOCK_OBJECT(session);
                return ip_id;
            }
        }
    }

    return -1;
}

void ipc_set_netif_ul_reload_retry(ipc_netif_t *netif, kal_bool need_ul_reload)
{
    kal_uint32       mask;
    kal_uint32       netif_bit_id = netif->bit_id;
    kal_uint32       set_reload;

    IPC_ASSERT(IPC_IS_VALID_OBJECT(netif));

    hif_data_trace(IPC_UL_RELOAD_RETRY, need_ul_reload, netif, netif->config.netif_id, netif->config.ipc_ul_reload_callback_t, ipc_netif_ul_set_need_reload_s);

    mask = SaveAndSetIRQMask();

    /*
     * Check if netif_ul_set_need_reload has been set
     * since the last time IPCORE called the netif reload cbk.
     */
    set_reload = ipc_netif_ul_set_need_reload_s & netif_bit_id;
    if (  ((need_ul_reload) || (set_reload)) &&
          (netif->config.ipc_ul_reload_callback_t) )
    {
        ipc_netif_ul_reload_retry_s |= (netif_bit_id);
    } else
    {
        ipc_netif_ul_reload_retry_s &= (~(netif_bit_id));
    }
    RestoreIRQMask(mask);

    if ((!need_ul_reload) && (set_reload))
    {
        hif_data_trace(IPC_UL_RELOAD_RETRY_RACE_COND, 0, need_ul_reload, set_reload, ipc_netif_ul_reload_retry_s);
    } else
    {
        hif_data_trace(IPC_UL_RELOAD_RETRY_FLAG, 0, ipc_netif_ul_reload_retry_s, ipc_netif_ul_set_need_reload_s);
    }
}

void ipc_set_netif_ul_set_need_reload(ipc_netif_t *netif, kal_bool need_ul_reload)
{
    kal_uint32       mask;
    kal_uint32       netif_bit_id = netif->bit_id;

    IPC_ASSERT(IPC_IS_VALID_OBJECT(netif));

    hif_data_trace(IPC_UL_SET_NEED_RELOAD, need_ul_reload, netif, netif->config.netif_id, netif->config.ipc_ul_reload_callback_t);

    mask = SaveAndSetIRQMask();
    if ((need_ul_reload) && (netif->config.ipc_ul_reload_callback_t))
    {
        ipc_netif_ul_set_need_reload_s |= (netif_bit_id);
    } else
    {
        ipc_netif_ul_set_need_reload_s &= (~(netif_bit_id));
    }
    RestoreIRQMask(mask);

    hif_data_trace(IPC_UL_SET_NEED_RELOAD_FLAG, 0, ipc_netif_ul_set_need_reload_s);
}

kal_uint32 ipc_get_all_netif_ul_reload_retry(void)
{
    return ipc_netif_ul_reload_retry_s;
}

kal_bool ipc_update_session_state(ipc_session_t *session, ipc_session_state_e session_state)
{
    ipc_session_state_e org_session_state;
    ipc_netif_t        *netif;
    kal_uint8           type;
    kal_uint32          mask;
    kal_bool            retval = KAL_TRUE;

    hif_trace_info(IPC_TR_UPDATE_SESSION_STATE_START, session, session_state);

    if (session)
    {
        IPC_R_LOCK_OBJECT(session);
        if (session)
        {
            org_session_state = session->state;
            netif = session->netif;
            type = session->type;
            IPC_R_UNLOCK_OBJECT(session);

            hif_trace_info(IPC_TR_UPDATE_SESSION_STATE_ORG_AND_NEW, session, type, netif, org_session_state, session_state);

            /* Update state */
            IPC_W_LOCK_OBJECT(session, mask);
            if (session) {
                session->state = session_state;
                IPC_W_UNLOCK_OBJECT(session, mask);
                hif_trace_info(IPC_TR_UPDATE_SESSION_STATE_TRANSITION_SUCCESS, session, session_state);
            } else
            {   /* Session write fail */
                hif_trace_error(IPC_TR_UPDATE_SESSION_STATE_WRITE_FAIL, session, session_state);
                IPC_ASSERT(0);
                retval = KAL_FALSE;
            }

            /* Run corresponding state transition action */
            if (    (org_session_state > IPC_SESSION_STATE_MIN) &&
                    (org_session_state < IPC_SESSION_STATE_MAX) &&
                    (session_state > IPC_SESSION_STATE_MIN) &&
                    (session_state < IPC_SESSION_STATE_MAX)         )
            {
                switch (session_transition_action_table[org_session_state][session_state])
                {
                    case IPC_SST_NA:
                        hif_trace_info(IPC_TR_UPDATE_SESSION_STATE_SST_NA, session, org_session_state, session_state);
                        break;
                    case IPC_SST_LUI:
                        hif_trace_info(IPC_TR_UPDATE_SESSION_STATE_SST_LUI, session, org_session_state, session_state);
                        ipc_indicate_netif_link_change(netif, type, KAL_TRUE, KAL_TRUE);
                        break;
                    case IPC_SST_LUR:
                        hif_trace_info(IPC_TR_UPDATE_SESSION_STATE_SST_LUR, session, org_session_state, session_state, netif, type);
                        ipc_notify_netif_link_change(netif, type, KAL_TRUE, KAL_TRUE);
                        break;
                    case IPC_SST_LDR:
                        hif_trace_info(IPC_TR_UPDATE_SESSION_STATE_SST_LDR, session, org_session_state, session_state, netif, type);
                        ipc_notify_netif_link_change(netif, type, KAL_TRUE, KAL_FALSE);
#ifdef __QBM_USE_FLC__
                        qbm_release_to_flc();
#endif
                        break;
                    case IPC_SST_IUI:
                        hif_trace_info(IPC_TR_UPDATE_SESSION_STATE_SST_IUI, session, org_session_state, session_state);
                        ipc_indicate_netif_link_change(netif, type, KAL_FALSE, KAL_TRUE);
                        break;
                    case IPC_SST_IUR:
                        hif_trace_info(IPC_TR_UPDATE_SESSION_STATE_SST_IUR, session, org_session_state, session_state, netif, type);
                        ipc_notify_netif_link_change(netif, type, KAL_FALSE, KAL_TRUE);
                        break;
                    case IPC_SST_IDR:
                        hif_trace_info(IPC_TR_UPDATE_SESSION_STATE_SST_IDR, session, org_session_state, session_state, netif, type);
                        ipc_notify_netif_link_change(netif, type, KAL_FALSE, KAL_FALSE);
                        break;
                    default:
                        /* Illegal state transition */
                        hif_trace_error(IPC_TR_UPDATE_SESSION_STATE_ILLEGAL_TRANSITION, session, org_session_state, session_state, session_transition_action_table[org_session_state][session_state]);
                        IPC_ASSERT(0);
                        retval = KAL_FALSE;
                }
            } else
            {   /* Invalid state */
                hif_trace_error(IPC_TR_UPDATE_SESSION_STATE_OUT_OF_RANGE, session, org_session_state, session_state, IPC_SESSION_STATE_MIN, IPC_SESSION_STATE_MAX);
                IPC_ASSERT(0);
                retval = KAL_FALSE;
            }

        } else
        {   /* Session read fail */
            hif_trace_error(IPC_TR_UPDATE_SESSION_STATE_READ_FAIL, session);
            retval = KAL_FALSE;
        }
    }else
    {   /* Session check fail */
        hif_trace_error(IPC_TR_UPDATE_SESSION_STATE_CHK_FAIL, session);
        retval = KAL_FALSE;
    }

    hif_trace_info(IPC_TR_UPDATE_SESSION_STATE_END, session, session_state, retval);

    return retval;
}

ipc_session_t *ipc_find_session_by_context(kal_uint8 session_context)
{
    ipc_session_t   *session;

    IPC_CONTEXT_TO_SESSION(session_context, session);
    IPC_R_LOCK_OBJECT(session);
    if (session) {
        IPC_ASSERT(session->context == session_context);
        return session;
    }
    return NULL;
}

ipc_session_t *ipc_find_session_by_netif(ipc_netif_t *netif, kal_uint8 session_type)
{
    kal_uint32     idx;
    ipc_session_t *session;
    ipc_netif_t   *netif_local;

    session = NULL;
    netif_local = netif;

    IPC_R_LOCK_OBJECT(netif_local);
    if (netif_local)
    {
        idx = ipc_session_type_hash((session_type == IPC_IP_TYPE_MIXED) ? IPC_IP_TYPE_IPV4: session_type);
        IPC_ASSERT(idx < IPC_SESSION_MAP_SIZE);
        session = netif_local->session_map[idx];
        IPC_R_LOCK_OBJECT(session);
        IPC_R_UNLOCK_OBJECT(netif_local);
    }

    return session;
}

ipc_session_t *ipc_find_session_by_ip_id(kal_int32 ip_id, kal_uint8 session_type)
{
    ipc_netif_t     *netif;
    ipc_session_t   *session;
    ipc_session_t   *session_found = NULL;
    kal_uint32       idx1, idx2;

    IPC_ASSERT(0 <= ip_id);

    for (idx1 = 0; idx1 < IPC_MAX_NETIF_CNT && NULL == session_found; idx1++) {
        netif = &(ipc_netifs_s[idx1]);

        IPC_R_LOCK_OBJECT(netif);
        if (netif) {

            idx2 = ipc_session_type_hash((session_type == IPC_IP_TYPE_MIXED) ? IPC_IP_TYPE_IPV4: session_type);
            session = netif->session_map[idx2];
            IPC_R_LOCK_OBJECT(session);
            if (session) {
                if ( session->ip_id == ip_id) {
                    session_found = session;
                    /* 
                     * Caller is expected to release session's read lock, 
                     * so don't release it here.
                     */
                } else {
                    IPC_R_UNLOCK_OBJECT(session);
                }
            }

            IPC_R_UNLOCK_OBJECT(netif);
        }
    }

    return session_found;
}

ipc_session_t *ipc_new_session(ipc_netif_t *netif, kal_uint8 session_context, kal_uint8 session_type, ipc_session_state_e session_state)
{
    ipc_session_t   *session;
    kal_uint32       idx;
    kal_uint32       mask;

    IPC_ASSERT(IPC_IS_VALID_OBJECT(netif));
    IPC_ASSERT(session_type == IPC_IP_TYPE_IPV4 || 
           session_type == IPC_IP_TYPE_IPV6 || 
           session_type == IPC_IP_TYPE_MIXED );
    IPC_ASSERT( (session_state > IPC_SESSION_STATE_MIN) &&
                (session_state < IPC_SESSION_STATE_MAX));

    hif_trace_info(IPC_TR_SESSION_BIND_START, session_context, session_type, session_state);

    /*
        *   If netif already bind session, return NULL directly
        */
    if (session_type == IPC_IP_TYPE_MIXED)
    {
        if (netif->session_map[0] || netif->session_map[1])
        {
            hif_trace_error(    IPC_TR_SESSION_BIND_NETIF_BOUND_MIXED,
                                netif,
                                netif->config.netif_id,
                                netif->session_map[ipc_session_type_hash(IPC_IP_TYPE_IPV4)],
                                netif->session_map[ipc_session_type_hash(IPC_IP_TYPE_IPV6)],
                                session_context,
                                session_type,
                                session_state);
            return NULL;
        }
    } else
    {
        idx = ipc_session_type_hash(session_type);
        if (netif->session_map[idx])
        {
            hif_trace_error(    IPC_TR_SESSION_BIND_NETIF_BOUND_SPECIFIC_IP_VER,
                                netif,
                                netif->config.netif_id,
                                netif->session_map[ipc_session_type_hash(IPC_IP_TYPE_IPV4)],
                                netif->session_map[ipc_session_type_hash(IPC_IP_TYPE_IPV6)],
                                session_context,
                                session_type,
                                session_state);
            return NULL;
        }
    }

    /*
        *       Allocate and configure new session
        */
    session = ipc_find_session_by_context(session_context);
    if (NULL == session) {
        IPC_CONTEXT_TO_SESSION(session_context, session);
        if (!IPC_IS_VALID_OBJECT(session)) {
            IPC_INIT_OBJECT_BEGIN(session, mask);

            session->context = session_context;
            session->type = session_type;
            session->dhcp4c_running = KAL_FALSE;
            session->dhcp4c_id = 0xff;
            session->dhcp4c_dl_filter_id = -1;
            session->ip_id = ipc_new_id(netif);
            session->netif = netif;
            session->state = session_state;

            /*
                     * If there's no IP session conflict (i.e. the same type), 
                     * no need to acquire a write lock on netif.
                     */
            if (session_type != IPC_IP_TYPE_MIXED) {
                idx = ipc_session_type_hash(session_type);
                IPC_ASSERT(netif->session_map[idx] == NULL);
                netif->session_map[idx] = session;
                netif->session_cnt++;
            } else {
                IPC_ASSERT(netif->session_map[0] == NULL && netif->session_map[1] == NULL);
                netif->session_map[0] = session;
                netif->session_map[1] = session;
                netif->session_cnt += 2;
            }

            IPC_INIT_OBJECT_END(session, mask);
            hif_trace_info(IPC_TR_SESSION_BOUND, session_context, session_type, session->ip_id, session_state);
            return session;
        } else {
            hif_trace_error(IPC_TR_SESSION_BIND_OUT_OF_SPACE, session_context, session_type,session_state);
        }
    } else {
        IPC_R_UNLOCK_OBJECT(session);
        hif_trace_error(IPC_TR_SESSION_BIND_DUPLICATED, session_context, session_type, session_state);
    }

    return NULL;
}

void ipc_del_session(ipc_session_t *session)
{
    ipc_netif_t    *netif;
    kal_uint32      mask;
    kal_uint32      idx;
    kal_bool        to_del_ip_id = KAL_TRUE;

    if (IPC_IS_VALID_OBJECT(session)) {
        IPC_DEINIT_OBJECT_BEGIN(session, mask);

        netif = session->netif;
        IPC_W_LOCK_OBJECT(netif, mask);
        if (netif) {
            if (session->type != IPC_IP_TYPE_MIXED) {
                idx = ipc_session_type_hash(session->type);
                IPC_ASSERT(netif->session_map[idx] == session);
                netif->session_map[idx] = NULL;
                netif->session_cnt--;
            } else {
                IPC_ASSERT(netif->session_map[0] == session && netif->session_map[1] == session);
                netif->session_map[0] = NULL;
                netif->session_map[1] = NULL;
                netif->session_cnt = 0;
            }
            to_del_ip_id = (netif->session_cnt == 0);

            IPC_W_UNLOCK_OBJECT(netif, mask);
        }

        if (to_del_ip_id) {
            ipc_del_id(session->ip_id);
        }

        hif_trace_info(IPC_TR_SESSION_DEACTIVATED, session->context, session->type, session->ip_id);
        IPC_DEINIT_OBJECT_END(session, mask);
    } else {
        hif_trace_error(IPC_TR_SESSION_DEACTIVATE_INVALID_SESSION);
    }
}
