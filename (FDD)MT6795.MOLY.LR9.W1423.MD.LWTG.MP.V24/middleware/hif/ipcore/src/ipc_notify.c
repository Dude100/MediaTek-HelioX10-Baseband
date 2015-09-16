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
 *   ipc_notify.c
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

#include "kal_public_api.h"
#include "intrCtrl.h"
#include "mw_sap.h"
#include "ipcore_upcm_struct.h"

#include "ipc_defs.h"
#include "ipc_debug.h"
#include "ipc_utils.h"
#include "ipc_notify.h"

typedef struct _ipc_ntfy_t {
    IPC_DECLARE_OBJECT

    kal_int32           ntfy_id;

    ipc_ntfy_callback_t callback_func;
    void                *callback_context;  /**< The context pass with IP CORE notification. */
} ipc_ntfy_t;

typedef struct _ipc_ntfy_list_t {
    IPC_DECLARE_OBJECT

    kal_uint32      count;
    ipc_ntfy_t      *ntfys[IPC_MAX_NTFY_CNT];
} ipc_ntfy_list_t;

/*------------------------------------------------------------------------------
 * Global variables.
 *----------------------------------------------------------------------------*/
static ipc_ntfy_t       ipc_ntfy_pool_s[IPC_MAX_NTFY_CNT];
static ipc_ntfy_list_t  ipc_ntfy_list_s[1];

/*------------------------------------------------------------------------------
 * Helper macro.
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 * Private function.
 *----------------------------------------------------------------------------*/
static ipc_ntfy_t *
ipc_allocate_ntfy(
    ipc_ntfy_t              *ntfy_pool,
    kal_uint32              pool_size,
    ipc_ntfy_callback_t     callback_func,
    void                    *callback_context)
{
    ipc_ntfy_t  *ntfy;
    kal_uint32  idx;
    kal_uint32  mask;

   if (NULL == callback_func) {
        hif_trace_error(IPC_TR_ALLOCATE_NTFY_INVALID_PARAMS, callback_func, callback_context);
        return NULL;
    }

    for (idx = 0; idx < pool_size; idx++) {
        ntfy = ntfy_pool + idx;

        if (!IPC_IS_VALID_OBJECT(ntfy)) {
            IPC_INIT_OBJECT_BEGIN(ntfy, mask);

            ntfy->ntfy_id = idx;
            ntfy->callback_func= callback_func;
            ntfy->callback_context = callback_context;

            IPC_INIT_OBJECT_END(ntfy, mask);
            return ntfy;
        }
    }
    hif_trace_error(IPC_TR_ALLOCATE_NTFY_UNAVAILABLE, callback_func, callback_context);
    return NULL;
}

static void
ipc_free_ntfy(
    ipc_ntfy_t    *ntfy)
{
    kal_uint32  mask;

    if (IPC_IS_VALID_OBJECT(ntfy)) {
        IPC_DEINIT_OBJECT_BEGIN(ntfy, mask);
        IPC_DEINIT_OBJECT_END(ntfy, mask);
    } else {
        hif_trace_error(IPC_TR_FREE_NTFY_INVALID_OBJECT);
    }
}

static ipc_ntfy_t *
ipc_find_ntfy_by_id(
    ipc_ntfy_t  *ntfy_pool,
    kal_int32   ntfy_id)
{
    if ((0 > ntfy_id) || (IPC_MAX_NTFY_CNT <= ntfy_id)) {
        hif_trace_error(IPC_TR_FIND_NTFY_BY_ID_INVALID_ID, ntfy_id, 0, IPC_MAX_NTFY_CNT);
        IPC_ASSERT(0 <= ntfy_id && IPC_MAX_NTFY_CNT > ntfy_id);
    }
    return (ntfy_pool + ntfy_id);
}

static void
ipc_add_ntfy_to_list(
    ipc_ntfy_list_t *list,
    ipc_ntfy_t      *ntfy)
{
    kal_uint32  mask;

    IPC_W_LOCK_OBJECT(list, mask);
    if (list) {
        list->ntfys[list->count] = ntfy;
        list->count++;
        IPC_W_UNLOCK_OBJECT(list, mask);
    } else {
        hif_trace_error(IPC_TR_ADD_NTFY_TO_LIST_INVALID_LIST, list);
        IPC_ASSERT(KAL_FALSE);
    }
}

static void
ipc_remove_ntfy_from_list(
    ipc_ntfy_list_t     *list,
    ipc_ntfy_t          *ntfy)
{
    kal_uint32  mask;
    kal_uint32  idx1;
    kal_uint32  idx2;

    IPC_W_LOCK_OBJECT(list, mask);
    if (list) {
        for (idx1 = 0; idx1 < list->count; idx1++) {
            if (list->ntfys[idx1] == ntfy) {
                for (idx2 = idx1; idx2 < list->count - 1; idx2++) {
                    list->ntfys[idx2] = list->ntfys[idx2 + 1];
                }
    
                list->ntfys[idx2] = NULL;
                list->count--;
                break;
            }
        }
    
        IPC_W_UNLOCK_OBJECT(list, mask);
    } else {
        hif_trace_error(IPC_TR_REMOVE_NTFY_FROM_LIST_INVALID_LIST, list);
        IPC_ASSERT(KAL_FALSE);
    }
}

/*------------------------------------------------------------------------------
 * Public fucntions.
 *----------------------------------------------------------------------------*/
void ipc_ntfy_init(void)
{
    kal_uint32  mask;
    kal_uint32  idx;
    static ipc_ntfy_list_t  *nls_set[] = {ipc_ntfy_list_s};

#if defined(__MTK_TARGET__)
    IPC_ASSERT(sizeof(ipc_ntfy_t) % 4 == 0);
    IPC_ASSERT(sizeof(ipc_ntfy_list_t) % 4 == 0);
#endif

    hif_trace_info(IPC_TR_NTFY_INIT_POOL_INFO, ipc_ntfy_pool_s, sizeof(ipc_ntfy_pool_s)/sizeof(ipc_ntfy_t));
    kal_mem_set( ipc_ntfy_pool_s, 0, sizeof(ipc_ntfy_pool_s) );

    for (idx = 0; idx < sizeof(nls_set) / sizeof(ipc_ntfy_list_t*); idx++) {
        hif_trace_info(IPC_TR_NTFY_INIT_LIST_INFO, idx, nls_set[idx]);
        kal_mem_set( nls_set[idx], 0, sizeof(ipc_ntfy_list_t) );
        IPC_INIT_OBJECT_BEGIN( nls_set[idx], mask );
        IPC_INIT_OBJECT_END( nls_set[idx], mask );
    }
}

kal_int32
ipc_new_ntfy(
    ipc_ntfy_callback_t callback_func,
    void                *callback_context)
{
    ipc_ntfy_t  *ntfy;

    ntfy = ipc_allocate_ntfy(   ipc_ntfy_pool_s,
                                IPC_MAX_NTFY_CNT,
                                callback_func,
                                callback_context);

    if (ntfy) {
        ipc_add_ntfy_to_list(ipc_ntfy_list_s, ntfy);
        hif_trace_info(IPC_TR_NEW_NTFY_ADD_TO_LIST, ntfy->ntfy_id, callback_func, callback_context);

        return ntfy->ntfy_id;
    } else {
        hif_trace_info(IPC_TR_NEW_NTFY_NG, callback_func, callback_context);
        ipc_ut_set_error(IPC_UT_NEW_NTFY_NG);
        return -1;
    }
}

void
ipc_del_ntfy(
    kal_int32      ntfy_id)
{
    ipc_ntfy_t  *ntfy;

    if (0 > ntfy_id || IPC_MAX_NTFY_CNT <= ntfy_id) {
        hif_trace_error(IPC_TR_DEL_NTFY_WITH_INVALID_ID, ntfy_id);
        ipc_ut_set_error(IPC_UT_DEL_NTFY_WITH_INVALID_ID);
        return;
    }

    ntfy = ipc_find_ntfy_by_id(ipc_ntfy_pool_s, ntfy_id);
    IPC_R_LOCK_OBJECT(ntfy);
    if (ntfy) {
        hif_trace_info(IPC_TR_DEL_NTFY_INFO, ntfy_id, ntfy->callback_func, ntfy->callback_context);

        hif_trace_info(IPC_TR_DEL_NTFY_REMOVE_FROM_LIST, ntfy_id);
        ipc_remove_ntfy_from_list(ipc_ntfy_list_s, ntfy);

        IPC_R_UNLOCK_OBJECT(ntfy);
        hif_trace_info(IPC_TR_DEL_NTFY_FREE_NTFY, ntfy_id);
        ipc_free_ntfy(ntfy);
    } else {
        hif_trace_error(IPC_TR_DEL_NTFY_NOT_FOUND, ntfy_id);
        ipc_ut_set_error(IPC_UT_DEL_NTFY_NOT_FOUND);
    }
}

void
ipc_do_ntfy(
    ipc_netif_t     *netif,
    ipc_ntfy_type_e ntfy_type)
{
    ipc_ntfy_t      *ntfy;
    kal_uint32      ntfy_idx;
    kal_int32       ip_id;

    IPC_ASSERT(NULL != netif);
    IPC_ASSERT((IPC_NTFY_TYPE_MIN < ntfy_type) && (IPC_NTFY_TYPE_MAX > ntfy_type));

    IPC_R_LOCK_OBJECT(netif);
    if (netif) {
        ip_id = ipc_map_netif_to_ip_id(netif);
        IPC_R_UNLOCK_OBJECT(netif);

        for ( ntfy_idx = 0 ; ntfy_idx < ipc_ntfy_list_s->count ; ntfy_idx ++ ) {

            ipc_ntfy_param_t param;

            ntfy = ipc_ntfy_list_s->ntfys[ntfy_idx];

            IPC_ASSERT(NULL != ntfy);
            IPC_ASSERT(NULL != ntfy->callback_func);

            param.context = ntfy->callback_context;
            param.ntfy_id = ntfy->ntfy_id;
            param.ntfy_type = ntfy_type;
            param.netif_id = netif->config.netif_id;
            param.ip_id = ip_id;

            hif_trace_info(IPC_TR_DO_NTFY_INFO, ntfy->callback_func, param.context, param.ntfy_id);
            hif_trace_info(IPC_TR_DO_NTFY_NTFY_INFO, param.ntfy_type, param.netif_id, param.ip_id);

            /* execute callback function */
            ntfy->callback_func(&param);   
        }
    }
}

void ipc_on_ipcore_link_up_ind(void *link_handshake_msg_ind_ptr)
{
    ipc_link_handshake_msg_t    *link_handshake_msg_ind_p = (ipc_link_handshake_msg_t *)link_handshake_msg_ind_ptr;
    ipc_link_handshake_msg_t    *link_handshake_msg_rsp_p;

    hif_trace_info(IPC_TR_IPCORE_LINK_UP_IND_START, link_handshake_msg_ind_p->netif_id, link_handshake_msg_ind_p->ip_id, link_handshake_msg_ind_p->ip_type);

    /* Always response the indication with same handshake message */
    link_handshake_msg_rsp_p = (ipc_link_handshake_msg_t *)construct_local_para(sizeof(ipc_link_handshake_msg_t), TD_RESET);
    IPC_ASSERT(link_handshake_msg_rsp_p);

    kal_mem_cpy(link_handshake_msg_rsp_p, link_handshake_msg_ind_p, sizeof(ipc_link_handshake_msg_t));

    hif_trace_info(IPC_TR_IPCORE_LINK_UP_IND_SEND_LINK_UP_RSP, link_handshake_msg_ind_p->netif_id, link_handshake_msg_ind_p->ip_id, link_handshake_msg_ind_p->ip_type);

    msg_send6(  MOD_NIL, /* src_mod_id */
                MOD_IPCORE, /* dest_mod_id */
                IPCORE_SAP, /* sap_id */
                MSG_ID_IPCORE_LINK_UP_RSP, /* msg_id */
                (struct local_para_struct *)link_handshake_msg_rsp_p, /* local_para_ptr */
                NULL); /* peer_buff_ptr */

    hif_trace_info(IPC_TR_IPCORE_LINK_UP_IND_END, link_handshake_msg_ind_p->netif_id, link_handshake_msg_ind_p->ip_id, link_handshake_msg_ind_p->ip_type);
}

void ipc_on_ipcore_ip_up_ind(void *link_handshake_msg_ind_ptr)
{
    ipc_link_handshake_msg_t    *link_handshake_msg_ind_p = (ipc_link_handshake_msg_t *)link_handshake_msg_ind_ptr;
    ipc_link_handshake_msg_t    *link_handshake_msg_rsp_p;

    hif_trace_info(IPC_TR_IPCORE_IP_UP_IND_START, link_handshake_msg_ind_p->netif_id, link_handshake_msg_ind_p->ip_id, link_handshake_msg_ind_p->ip_type);

    /* Always response the indication with same handshake message */
    link_handshake_msg_rsp_p = (ipc_link_handshake_msg_t *)construct_local_para(sizeof(ipc_link_handshake_msg_t), TD_RESET);
    IPC_ASSERT(link_handshake_msg_rsp_p);

    kal_mem_cpy(link_handshake_msg_rsp_p, link_handshake_msg_ind_p, sizeof(ipc_link_handshake_msg_t));

    hif_trace_info(IPC_TR_IPCORE_IP_UP_IND_SEND_IP_UP_RSP, link_handshake_msg_ind_p->netif_id, link_handshake_msg_ind_p->ip_id, link_handshake_msg_ind_p->ip_type);

    msg_send6(  MOD_NIL, /* src_mod_id */
                MOD_IPCORE, /* dest_mod_id */
                IPCORE_SAP, /* sap_id */
                MSG_ID_IPCORE_IP_UP_RSP, /* msg_id */
                (struct local_para_struct *)link_handshake_msg_rsp_p, /* local_para_ptr */
                NULL); /* peer_buff_ptr */

    hif_trace_info(IPC_TR_IPCORE_IP_UP_IND_END, link_handshake_msg_ind_p->netif_id, link_handshake_msg_ind_p->ip_id, link_handshake_msg_ind_p->ip_type);
}

void ipc_on_ipcore_up_rsp(void *link_handshake_msg_rsp_ptr)
{
    ipc_link_handshake_msg_t    *link_handshake_msg_rsp_p = (ipc_link_handshake_msg_t *)link_handshake_msg_rsp_ptr;
    ipc_netif_t                 *netif;
    ipc_session_t               *session;

    hif_trace_info(IPC_TR_IPCORE_UP_RSP_START, link_handshake_msg_rsp_p->netif_id, link_handshake_msg_rsp_p->ip_id, link_handshake_msg_rsp_p->ip_type);

    netif = ipc_find_netif(link_handshake_msg_rsp_p->netif_id);
    if (netif)
    {
        session = ipc_find_session_by_netif(netif, link_handshake_msg_rsp_p->ip_type);
        IPC_R_UNLOCK_OBJECT(netif);

        if (session)
        {
            IPC_R_UNLOCK_OBJECT(session);
            hif_trace_info(IPC_TR_IPCORE_UP_RSP_UPDATE_SESSION_STATE_TO_LINKUP, session);
            ipc_update_session_state(session, IPC_SESSION_STATE_LINKUP);
        } else
        {
            hif_trace_error(IPC_TR_IPCORE_UP_RSP_SESSION_NOT_FOUND, netif, link_handshake_msg_rsp_p->netif_id, link_handshake_msg_rsp_p->ip_id, link_handshake_msg_rsp_p->ip_type);
        }
    } else
    {
        hif_trace_error(IPC_TR_IPCORE_UP_RSP_NETIF_NOT_FOUND, link_handshake_msg_rsp_p->netif_id, link_handshake_msg_rsp_p->ip_id, link_handshake_msg_rsp_p->ip_type);
    }

    hif_trace_info(IPC_TR_IPCORE_UP_RSP_END, link_handshake_msg_rsp_p->netif_id, link_handshake_msg_rsp_p->ip_id, link_handshake_msg_rsp_p->ip_type);
}

