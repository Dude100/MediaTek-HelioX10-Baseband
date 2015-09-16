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
 *   ipc_if.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   IP Core public interface implementation.
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
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "kal_public_api.h"
#include "sysservice_msgid.h"
#include "em_struct.h"
#include "em_msgid.h"
#include "intrCtrl.h"
#include "mw_sap.h"
#include "ps_public_enum.h"

#include "upcm.h"
#include "ipcore_upcm_struct.h"
#include "upcm_msgid.h"
#if defined(__LTM_SIMULATION_SUPPORT__)
    #include "lms_api.h"
#endif
#include "qmu_bm.h"
#include "qmu_bm_size.h"
#include "qmu_bm_util.h"

#include "nmu.h"
#include "nmu_util.h"
#include "hmu.h"

#include "ccci_ipc_msgid.h"

#include "pfm_api.h"

#include "ipc_defs.h"
#include "ipc_debug.h"
#include "ipc_utils.h"
#include "ipc_filter.h"
#include "ipc_dhcp_adp.h"
#include "ipc_notify.h"

#include "hif_swla.h"

#if defined (__HIF_CCCI_SUPPORT__)
#include "ccci_if.h"
#endif

#if !defined(__MTK_TARGET__) && defined(_MSC_VER) && (_MSC_VER >= 1500)
#pragma warning( disable : 4100 )
#endif

/*------------------------------------------------------------------------------
 * Global variables.
 *----------------------------------------------------------------------------*/
static volatile kal_bool ipc_in_reset_s = KAL_FALSE;

/*------------------------------------------------------------------------------
 * Helper macro.
 *----------------------------------------------------------------------------*/
#if IPC_PEER==IPC_PEER_LTM_SIM
    #if defined(__LTM_SIMULATION_SUPPORT__)
        #define IPC_REG_CBK_DLVR_DL_SDU lms_reg_cbk_dlvr_dl_sdu
        #define IPC_REG_CBK_NOTIFY_LTE_TICK_SOURCE lms_reg_cbk_notify_tick_source
        #define IPC_FORWARD_UL_SDU lms_rcv_ul_sdu
        #define IPC_FORWARD_UL_SDU_BY_EBI lms_rcv_ul_sdu_by_ebi
    #else
        #define "Please define turn on LTM_SIMULATION_SUPPORT while setting IPC_PEER as IPC_PEER_LTM_SIM!"
    #endif
#elif IPC_PEER==IPC_PEER_UPCM
    #define IPC_REG_CBK_DLVR_DL_SDU upcm_reg_cbk_dlvr_dl_sdu
    #define IPC_REG_CBK_NOTIFY_LTE_TICK_SOURCE upcm_reg_cbk_notify_lte_tick
    #define IPC_FORWARD_UL_SDU upcm_rcv_ul_sdu
    #define IPC_FORWARD_UL_SDU_BY_EBI upcm_rcv_ul_sdu_by_ebi
#elif IPC_PEER==IPC_PEER_UT
    #define IPC_REG_CBK_DLVR_DL_SDU ipc_ut_reg_cbk_dlvr_dl_sdu
    #define IPC_REG_CBK_NOTIFY_LTE_TICK_SOURCE ipc_ut_reg_cbk_notify_tick_source
    #define IPC_FORWARD_UL_SDU ipc_ut_rcv_ul_sdu
    #define IPC_FORWARD_UL_SDU_BY_EBI ipc_ut_rcv_ul_sdu_by_ebi
#elif IPC_PEER==IPC_PEER_NULL_DROP || IPC_PEER==IPC_PEER_NULL_LOOPBACK
    #define IPC_REG_CBK_DLVR_DL_SDU(...) 
    #define IPC_REG_CBK_NOTIFY_LTE_TICK_SOURCE(...) 
    #define IPC_FORWARD_UL_SDU(...) 
    #define IPC_FORWARD_UL_SDU_BY_EBI(...) 
#else
    #error "Unknown peer module of IPCORE!"
#endif

/*------------------------------------------------------------------------------
 * Private data structure.
 *----------------------------------------------------------------------------*/
typedef struct _ipc_internal_ior_t {
    ipc_io_request_t    public;
    ipc_netif_t        *netif;
} ipc_internal_ior_t;

/*------------------------------------------------------------------------------
 * Private variables.
 *----------------------------------------------------------------------------*/
static ipc_internal_ior_t       *ipc_ul_ior_head_s = NULL;
static ipc_internal_ior_t       *ipc_ul_ior_tail_s = NULL;
static ipc_internal_ior_t       *ipc_ul_pending_ior_head_s = NULL;
static ipc_internal_ior_t       *ipc_ul_pending_ior_tail_s = NULL;
static kal_uint32                ipc_ul_pending_ior_cnt_s = 0;
static kal_bool                  ipc_ul_processing_s = KAL_FALSE;
static kal_bool                  ipc_ul_reload_retrying_s = KAL_FALSE;

#define IPC_ES_INDEX_UL_THROTTLE 2
static ipc_ul_throttle_state_e   ipc_ul_throttle_state_s = IPC_UL_THROTTLE_STATE_NONE;
static ipc_ul_throttle_conf_t    ipc_ul_throttle_conf_s = {0, 0, 0};
static stack_timer_struct       *ipc_stack_timer_s = NULL;
static event_scheduler          *ipc_es_ul_throttle_s = NULL; /* Timer for UL throttle mechanism. */
static eventid                   ipc_eid_ul_throttle_s = NULL; /* Timer for UL throttle mechanism. */

static kal_uint32                ipc_em_on_s = 0;
/*------------------------------------------------------------------------------
 * Private fucntions.
 *----------------------------------------------------------------------------*/

void ipc_dest_ior(
    ipc_io_request_t       *ior)
{
    ipc_io_request_t       *next_ior;

    IPC_ASSERT(ior);
    for (; ior; ior = next_ior) {
        next_ior = ior->next_request;
        if ( ior->first_gpd && ior->last_gpd ) {
            qbmt_dest_q(ior->first_gpd, ior->last_gpd);
        }
    }
}

/*
 * Assumption: netif read lock is acquired.
 */
void ipc_reload_uplink(ipc_netif_t *netif)
{
    kal_bool need_retry;

    hif_data_trace(IPC_UL_RELOAD_UPLINK, 0, netif, netif->config.netif_id, netif->config.ipc_ul_reload_callback_t);

    if (netif->config.ipc_ul_reload_callback_t) {
        /* Clear netif_ul_need_reload before call netif reload cbk */
        ipc_set_netif_ul_set_need_reload(netif, KAL_FALSE);
        need_retry = netif->config.ipc_ul_reload_callback_t(
                                        netif->config.ul_reload_context);

        hif_data_trace(IPC_UL_RELOAD_UPLINK_RESULT, 0, netif, netif->config.netif_id, need_retry);

        ipc_set_netif_ul_reload_retry(netif, need_retry);
    }
}

void ipc_on_downlink(kal_uint32 pdn_id, qbm_gpd *p_head, qbm_gpd *p_tail)
{
    ipc_session_t              *session;
    ipc_netif_t                *netif;
    ipc_io_request_t           *ior;
    kal_uint8                   session_type;
    kal_uint32                  netif_id;

    HIF_SWLA_START("ID1");

    IPC_ASSERT(p_head);
    IPC_ASSERT(p_tail);

    hif_data_trace(IPC_DL_ON_DOWNLINK, pdn_id, p_head, p_tail);

    session = ipc_find_session_by_context((kal_uint8)pdn_id);
    if (session) {
        netif = session->netif;
        session_type = session->type;
        IPC_R_UNLOCK_OBJECT(session);

        /* Get network interface information for following operations */
        IPC_R_LOCK_OBJECT(netif);
        if (netif)
        {
            netif_id = netif->config.netif_id;
            IPC_R_UNLOCK_OBJECT(netif);
        } else
        {
            kal_uint8   ip_id = 0xff;

            IPC_R_LOCK_OBJECT(session);
            if (session)
            {
                ip_id = (kal_uint8)session->ip_id;
                IPC_R_UNLOCK_OBJECT(session);
            }

            hif_trace_error(IPC_TR_DL_DROP_FOR_NETIF_INFO_LOCK_FAIL, pdn_id, ip_id, session_type, p_head, p_tail);
            goto drop;
        }

    #if (IPC_DL_INVALID_LEN_DROP_EN)
        // downlink valid packet check
        ipc_dl_invalid_len_chk(&p_head, &p_tail);
        if (NULL == p_head || NULL == p_tail)
        {
            hif_data_trace(IPC_DL_INVALID_LEN_DROP_ALL, 0, session_type, netif_id, p_head);
            IPC_ASSERT(NULL == p_head && NULL == p_tail);
            goto done;
        }        
    #endif

        /* Do DL filter */
        ipc_do_dl_filter(session_type, netif_id, pdn_id, &p_head, &p_tail);
        if (NULL == p_head || NULL == p_tail)
        {
            hif_data_trace(IPC_DL_ON_DOWNLINK_FILTER_OUT, 0, session_type, netif_id);
            IPC_ASSERT(NULL == p_head && NULL == p_tail);
            goto done;
        }

        /* Send DL traffic */
        IPC_R_LOCK_OBJECT(netif);
        if (netif)
        {
            ior = (ipc_io_request_t *)QBM_DES_GET_SW_CTRL_FIELD(p_head);
            ior->next_request = NULL;
            ior->first_gpd = p_head;
            ior->last_gpd = p_tail;
            ior->ip_type = session_type;
            ior->qos_priority = 0;

            hif_data_trace(IPC_DL_ON_DOWNLINK_CALLBACK_INFO, pdn_id, session_type, netif_id);
            hif_data_trace(IPC_DL_ON_DOWNLINK_CALLBACK_GPD, pdn_id, p_head, p_tail);

            netif->config.ipc_dlink_callback_t(
                netif->config.callback_context,
                ior);

            IPC_R_UNLOCK_OBJECT(netif);
            goto done;
        } else
        {
            kal_uint8   ip_id = 0xff;

            IPC_R_LOCK_OBJECT(session);
            if (session)
            {
                ip_id = (kal_uint8)session->ip_id;
                IPC_R_UNLOCK_OBJECT(session);
            }
            hif_trace_error(IPC_TR_DL_DROP_FOR_NETIF_DETACH, pdn_id, ip_id, session_type, p_head, p_tail);
            goto drop;
        }
    } else
    {
        hif_trace_error(IPC_TR_DL_DROP_FOR_INVALID_SESSION, pdn_id, p_head, p_tail);        
    }

drop:
    qbmt_dest_q(p_head, p_tail); /* Discard packets if something wrong. */
done:

    HIF_SWLA_STOP("ID1");
    return;
}

void ipc_on_lte_tick_source(kal_bool is_lte_tick)
{
    if (is_lte_tick) {
        hmu_switch_hif_timer(HMU_TIMER_SOURCE_DSP);
    } else {
        hmu_switch_hif_timer(HMU_TIMER_SOURCE_SYS);
    }
}

void ipc_on_pdn_bind(module_type src_mod_id, local_para_struct *local_para_ptr)
{
    ipcore_upcm_pdn_bind_ind_struct *param = (ipcore_upcm_pdn_bind_ind_struct *)local_para_ptr;
    ipc_netif_t                 *netif;
    ipc_session_t               *session;
    kal_uint32                   features;
    kal_uint32                   session_ip_id;
    kal_uint8                    ip_type;
    kal_bool                     trigger_linkup;
    ps_cause_enum                result;

    result = HIF_IPC_OK;

    hif_trace_info(IPC_TR_SESSION_BINDING_START);

    if (param) {
        IPC_ASSERT(local_para_ptr->msg_len == sizeof(ipcore_upcm_pdn_bind_ind_struct));
        hif_trace_info(IPC_TR_SESSION_BINDING_INFO, param->network_interface_id, param->pdn_id, param->ip_addr.ip_addr_type);

        switch (param->ip_addr.ip_addr_type) {
        case IPV4_ADDR_TYPE:
            ip_type = IPC_IP_TYPE_IPV4;
            break;
        case IPV6_ADDR_TYPE:
            ip_type = IPC_IP_TYPE_IPV6;
            break;
        case IPV4V6_ADDR_TYPE:
            ip_type = IPC_IP_TYPE_MIXED;
            break;
        default:
            hif_trace_error(IPC_TR_SESSION_BIND_UNSUPPORTED_IP_ADDR_TYPE, param->ip_addr.ip_addr_type, param->pdn_id);
            result = HIF_IPC_PDN_BIND_RSP_UNSUPPORTED_IP_ADDR_TYPE;
            goto rsp;
        }

        netif = ipc_find_netif(param->network_interface_id);
        if (netif) {
            session = ipc_new_session(netif, param->pdn_id, ip_type, IPC_SESSION_STATE_BIND);
            features = netif->config.features;
            IPC_R_UNLOCK_OBJECT(netif);

            if (session) {

                IPC_R_LOCK_OBJECT(session);
                if (session)
                {
                    session_ip_id = session->ip_id;
                    IPC_R_UNLOCK_OBJECT(session);

                    hif_trace_info(IPC_TR_SESSION_BINDING_CFG_IP_INFO, param->network_interface_id, param->pdn_id, param->ip_addr.ip_addr_type, session_ip_id);

                    trigger_linkup = KAL_TRUE;

                    /*
                                        Configure IPv6 address
                                        Always only configure network interface identifier /64
                                    */
                    if (IPC_IP_TYPE_IPV6 == ip_type || IPC_IP_TYPE_MIXED == ip_type)
                    {
                        kal_uint32 input_dns_idx;
                        kal_uint32 total_dns_cnt;

                        /* Set IPv6 information into nmu */
                        total_dns_cnt = 0;
                        for (input_dns_idx = 0 ; input_dns_idx < NUM_OF_DNS_ADDR ; input_dns_idx ++)
                        {
                            if (KAL_TRUE == param->dns.v6[input_dns_idx].is_dnsv6_present)
                            {
                                hif_trace_info(IPC_TR_SESSION_BINDING_CFG_IPV6_DNS,
                                                session_ip_id,
                                                total_dns_cnt,
                                                param->dns.v6[input_dns_idx].dnsv6[0],
                                                param->dns.v6[input_dns_idx].dnsv6[1],
                                                param->dns.v6[input_dns_idx].dnsv6[2],
                                                param->dns.v6[input_dns_idx].dnsv6[3],
                                                param->dns.v6[input_dns_idx].dnsv6[4],
                                                param->dns.v6[input_dns_idx].dnsv6[5],
                                                param->dns.v6[input_dns_idx].dnsv6[6],
                                                param->dns.v6[input_dns_idx].dnsv6[7],
                                                param->dns.v6[input_dns_idx].dnsv6[8],
                                                param->dns.v6[input_dns_idx].dnsv6[9],
                                                param->dns.v6[input_dns_idx].dnsv6[10],
                                                param->dns.v6[input_dns_idx].dnsv6[11],
                                                param->dns.v6[input_dns_idx].dnsv6[12],
                                                param->dns.v6[input_dns_idx].dnsv6[13],
                                                param->dns.v6[input_dns_idx].dnsv6[14],
                                                param->dns.v6[input_dns_idx].dnsv6[15]);
                                nmu_set_ip6_dns(session_ip_id, total_dns_cnt, param->dns.v6[input_dns_idx].dnsv6);
                                total_dns_cnt ++;
                            }
                        }
                        hif_trace_info(IPC_TR_SESSION_BINDING_CFG_IPV6_DNS_NUM, total_dns_cnt, session_ip_id);
                        nmu_set_ip6_dns_num(session_ip_id, total_dns_cnt);

                        if (IPC_IS_V6_UNSPECIFIED_ADDR(param->ip_addr.ipv6))
                        {
                            hif_trace_info(IPC_TR_SESSION_BINDING_CFG_IPV6_ZERO_IID_LEN, session_ip_id);
                            nmu_set_ip6_iid_len(session_ip_id, 0);

                            hif_trace_info(IPC_TR_SESSION_BINDING_CFG_IPV6_DOWN, session_ip_id);
                            nmu_set_ip6_down(session_ip_id);
                        } else
                        {
                            hif_trace_info(IPC_TR_SESSION_BINDING_CFG_IPV6_IID,
                                            session_ip_id,
                                            IPV6_VALID_IID_BITS,
                                            param->ip_addr.ipv6[0],
                                            param->ip_addr.ipv6[1],
                                            param->ip_addr.ipv6[2],
                                            param->ip_addr.ipv6[3],
                                            param->ip_addr.ipv6[4],
                                            param->ip_addr.ipv6[5],
                                            param->ip_addr.ipv6[6],
                                            param->ip_addr.ipv6[7],
                                            param->ip_addr.ipv6[8],
                                            param->ip_addr.ipv6[9],
                                            param->ip_addr.ipv6[10],
                                            param->ip_addr.ipv6[11],
                                            param->ip_addr.ipv6[12],
                                            param->ip_addr.ipv6[13],
                                            param->ip_addr.ipv6[14],
                                            param->ip_addr.ipv6[15]);
                            nmu_set_ip6_iid(session_ip_id, param->ip_addr.ipv6);
                            nmu_set_ip6_iid_len(session_ip_id, IPV6_VALID_IID_BITS);

                            hif_trace_info(IPC_TR_SESSION_BINDING_CFG_IPV6_UP, session_ip_id);
                            nmu_set_ip6_up(session_ip_id);
                        }
                    }

                    /*
                                        Configure IPv4 address
                                    */
                    if (IPC_IP_TYPE_IPV4 == ip_type || IPC_IP_TYPE_MIXED == ip_type)
                    {
                        kal_uint32 input_dns_idx;
                        kal_uint32 total_dns_cnt;

                        /* Set IPv4 information into nmu */
                        total_dns_cnt = 0;
                        for (input_dns_idx = 0 ; input_dns_idx < NUM_OF_DNS_ADDR ; input_dns_idx ++)
                        {
                            if (KAL_TRUE == param->dns.v4[input_dns_idx].is_dnsv4_present)
                            {
                                hif_trace_info(IPC_TR_SESSION_BINDING_CFG_IPV4_DNS,
                                                session_ip_id,
                                                total_dns_cnt,
                                                param->dns.v4[input_dns_idx].dnsv4[0],
                                                param->dns.v4[input_dns_idx].dnsv4[1],
                                                param->dns.v4[input_dns_idx].dnsv4[2],
                                                param->dns.v4[input_dns_idx].dnsv4[3]);
                                nmu_set_ip4_dns(session_ip_id, total_dns_cnt, param->dns.v4[input_dns_idx].dnsv4);
                                total_dns_cnt ++;
                            }
                        }
                        hif_trace_info(IPC_TR_SESSION_BINDING_CFG_IPV4_DNS_NUM, total_dns_cnt, session_ip_id);
                        nmu_set_ip4_dns_num(session_ip_id, total_dns_cnt);

                        hif_trace_info(IPC_TR_SESSION_BINDING_CFG_IPV4_ADDR,
                                        session_ip_id,
                                        param->ip_addr.ipv4[0],
                                        param->ip_addr.ipv4[1],
                                        param->ip_addr.ipv4[2],
                                        param->ip_addr.ipv4[3]);
                        nmu_set_ip4_ip(session_ip_id, param->ip_addr.ipv4);

                        hif_trace_info(IPC_TR_SESSION_BINDING_CFG_IPV4_FAKE_INFO,
                                        session_ip_id,
                                        param->ip_addr.ipv4[0],
                                        param->ip_addr.ipv4[1],
                                        param->ip_addr.ipv4[2],
                                        param->ip_addr.ipv4[3]);
                        nmu_set_ip4_fake_mask_and_gateway(session_ip_id, param->ip_addr.ipv4);

                        if (IPC_IS_V4_UNSPECIFIED_ADDR(param->ip_addr.ipv4))
                        {   /* IPv4 information is not complete in control path */

                            /* set IPv4 down */
                            hif_trace_info(IPC_TR_SESSION_BINDING_CFG_IPV4_DOWN, session_ip_id);
                            nmu_set_ip4_down(session_ip_id);

                            /* Trigger DHCPv4 client if needed */
                            if (features & IPC_F_DHCP4C)
                            {   /* enable DHCPv4 if necessary */
                                hif_trace_info(IPC_TR_SESSION_BINDING_DHCP4C, param->network_interface_id, features);
                                ipc_enable_dhcp4c(session);

                                /* Stop triggering link up if DHCPv4 client is enabled */
                                trigger_linkup = KAL_FALSE;
                            }
                        } else
                        {   /* IPv4 information is complete, set IPv4 up */
                            hif_trace_info(IPC_TR_SESSION_BINDING_CFG_IPV4_UP, session_ip_id);
                            nmu_set_ip4_up(session_ip_id);
                        }
                    }

                    if (KAL_TRUE == trigger_linkup)
                    {
                        ipc_update_session_state(session, IPC_SESSION_STATE_PRE_LINKUP);
                    }
                }else
                {
                    hif_trace_error(IPC_TR_SESSION_BIND_SESSION_RLOCK_FAIL, param->network_interface_id, param->pdn_id, ip_type);
                    result = HIF_IPC_PDN_BIND_RSP_SESSION_RLOCK_FAIL;
                }
            }else {
                hif_trace_error(IPC_TR_SESSION_BIND_NEW_SESSION_FAIL, param->network_interface_id, param->pdn_id, ip_type);
                result = HIF_IPC_PDN_BIND_RSP_NEW_SESSION_FAIL;
            }
        } else {
            hif_trace_error(IPC_TR_SESSION_BIND_INVALID_NETIF, param->network_interface_id);
            result = HIF_IPC_PDN_BIND_RSP_INVALID_NETIF;
        }
    } else {
        hif_trace_error(IPC_TR_SESSION_BIND_NULL_PARAM);
        result = HIF_IPC_PDN_BIND_RSP_NULL_PARAM;
    }

rsp:
    hif_trace_info(IPC_TR_SESSION_BINDING_RESULT, result);
    if (MOD_NIL != src_mod_id)
    {
        ipcore_upcm_pdn_bind_rsp_struct *rsp_msg_p;

        rsp_msg_p = (ipcore_upcm_pdn_bind_rsp_struct *)construct_local_para(sizeof(ipcore_upcm_pdn_bind_rsp_struct), TD_RESET);
        IPC_ASSERT(rsp_msg_p);

        /* Fill response from indication structure */
        if (param)
        {
            hif_trace_info( IPC_TR_SESSION_BINDING_RSP_PARAM_GEN,
                            param->network_interface_id,
                            param->pdn_id,
                            sizeof(ip_addr_struct),
                            sizeof(dns_struct),
                            sizeof(upcm_ipcore_back_info_t));

            rsp_msg_p->network_interface_id = param->network_interface_id;
            rsp_msg_p->pdn_id = param->pdn_id;
            kal_mem_cpy(&(rsp_msg_p->ip_addr), &(param->ip_addr), sizeof(ip_addr_struct));
            kal_mem_cpy(&(rsp_msg_p->dns), &(param->dns), sizeof(dns_struct));
            kal_mem_cpy(&(rsp_msg_p->back_info), &(param->back_info), sizeof(upcm_ipcore_back_info_t));
        }

        /* Fill result */
        rsp_msg_p->result = result;

        hif_trace_info(IPC_TR_SESSION_BINDING_RSP, result, src_mod_id);

#ifdef ATEST_SYS_IPCORE
        ipc_ut_msg_send6(
                MOD_IPCORE,
                src_mod_id, 
                IPCORE_SAP,
                MSG_ID_IPCORE_UPCM_PDN_BIND_RSP,
                (local_para_struct*)rsp_msg_p, 
                NULL
                );
#else
        msg_send6(
                MOD_IPCORE,
                src_mod_id, 
                IPCORE_SAP,
                MSG_ID_IPCORE_UPCM_PDN_BIND_RSP,
                (local_para_struct*)rsp_msg_p, 
                NULL
                );
#endif
    }
}

void ipc_on_pdn_deact(local_para_struct *local_para_ptr)
{
    ipcore_upcm_pdn_deact_ind_struct *param = (ipcore_upcm_pdn_deact_ind_struct *)local_para_ptr;
    ipc_session_t               *session;
    kal_uint32                  session_ip_id;
    kal_uint8                   session_type;

    if (param) {
        IPC_ASSERT(local_para_ptr->msg_len == sizeof(ipcore_upcm_pdn_deact_ind_struct));
        hif_trace_info(IPC_TR_SESSION_DEACTIVATING, param->pdn_id);

        session = ipc_find_session_by_context((kal_uint8)(param->pdn_id));
        if (session) {
            session_ip_id = session->ip_id;
            session_type = session->type;
            IPC_R_UNLOCK_OBJECT(session);

            if (IPC_IP_TYPE_IPV6 == session_type || IPC_IP_TYPE_MIXED == session_type) {
                nmu_set_ip6_dns_num(session_ip_id, 0);
                nmu_set_ip6_down(session_ip_id);
            }
            if (IPC_IP_TYPE_IPV4 == session_type || IPC_IP_TYPE_MIXED == session_type) {
                nmu_set_ip4_dns_num(session_ip_id, 0);
                nmu_set_ip4_down(session_ip_id);
            }

            ipc_disable_dhcp4c(session); /* disable DHCPv4 it's been enabled */
            ipc_update_session_state(session, IPC_SESSION_STATE_UNBIND);
            ipc_del_session(session);
        } else {
            hif_trace_error(IPC_TR_SESSION_DEACTIVATE_NO_SESSION_FOUND, param->pdn_id);
            ipc_ut_set_error(IPC_UT_SESSION_DEACTIVATE_NO_SESSION_FOUND);
        }
    } else {
        hif_trace_error(IPC_TR_SESSION_DEACTIVATE_NULL_PARAM);
    }
}

void ipc_on_query_info(module_type src_mod_id, local_para_struct *local_para_ptr)
{
    ipc_netif_list_t netif_list_info;

    hif_trace_info(IPC_TR_QUERY_INFO_START, src_mod_id, local_para_ptr);

    /* ---------- Initiate information for response ---------- */
    kal_mem_set(&netif_list_info, 0, sizeof(ipc_netif_list_t));

    /* ---------- Collect information ---------- */
    ipc_query_netif_list(&netif_list_info);

    /* ---------- Response ---------- */
    if (MOD_NIL != src_mod_id)
    {
        ipc_query_info_t *cnf_msg_p;

        cnf_msg_p = (ipc_query_info_t *)construct_local_para(sizeof(ipc_query_info_t), TD_RESET);
        IPC_ASSERT(cnf_msg_p);

        /* Fill response from indication structure */
        kal_mem_cpy(&(cnf_msg_p->netif), &netif_list_info, sizeof(ipc_netif_list_t));

        hif_trace_info(IPC_TR_QUERY_INFO_CNF, src_mod_id);

#ifdef ATEST_SYS_IPCORE
        ipc_ut_msg_send6(
                MOD_IPCORE,
                src_mod_id, 
                IPCORE_SAP,
                MSG_ID_IPCORE_QUERY_INFO_CNF,
                (local_para_struct*)cnf_msg_p, 
                NULL
                );
#else
        msg_send6(
                MOD_IPCORE,
                src_mod_id, 
                IPCORE_SAP,
                MSG_ID_IPCORE_QUERY_INFO_CNF,
                (local_para_struct*)cnf_msg_p, 
                NULL
                );
#endif
    }else
    {
        hif_trace_error(IPC_TR_QUERY_INFO_NO_MOD_ID_FOR_CFN, src_mod_id, MOD_NIL);
    }
    hif_trace_info(IPC_TR_QUERY_INFO_END);
}


static INLINE void
ipc_clarify_gpd(
    qbm_gpd *head_gpd,
    qbm_gpd *tail_gpd,
    qbm_gpd **ipv4_head_gpd,
    qbm_gpd **ipv4_tail_gpd,
    qbm_gpd **ipv6_head_gpd,
    qbm_gpd **ipv6_tail_gpd)
{
    kal_bool    end;
    qbm_gpd     *curr_gpd;
    qbm_gpd     *next_gpd;
    qbm_gpd     *curr_bd;
    kal_uint8   *first_buf;

    IPC_ASSERT(ipv4_head_gpd);
    IPC_ASSERT(ipv4_tail_gpd);
    IPC_ASSERT(ipv6_head_gpd);
    IPC_ASSERT(ipv6_tail_gpd);

    *ipv4_head_gpd = *ipv4_tail_gpd = NULL;
    *ipv6_head_gpd = *ipv6_tail_gpd = NULL;

    end = KAL_FALSE;
    for (curr_gpd = head_gpd; curr_gpd && !end; curr_gpd = next_gpd) {
        IPC_ASSERT(QBM_DES_GET_DATAPTR(curr_gpd));

        next_gpd = (qbm_gpd *)QBM_DES_GET_NEXT(curr_gpd);
        end = (curr_gpd == tail_gpd)?KAL_TRUE:KAL_FALSE;

        if (QBM_DES_GET_DATALEN(curr_gpd) == 0)
        {   /* Zero length packet ! Drop this packet ! */
            hif_trace_error(IPC_TR_CLARIFY_ZERO_LENGTH_PKT, curr_gpd, QBM_DES_GET_DATALEN(curr_gpd));
            first_buf = NULL;
        } else
        {
            if (QBM_DES_GET_BDP(curr_gpd))
            {
                curr_bd = (qbm_gpd *)QBM_DES_GET_DATAPTR(curr_gpd);
                /* Loop to trace 1st DL BD with data buffer */
                while (curr_bd && (QBM_DES_GET_DATALEN(curr_bd) == 0))
                {
                    curr_bd = (QBM_DES_GET_EOL(curr_bd))?(NULL):((qbm_gpd*)QBM_DES_GET_NEXT(curr_bd));
                }

                if (curr_bd)
                {
                    first_buf = (kal_uint8 *)QBM_DES_GET_DATAPTR(curr_bd);
                } else
                {
                    hif_trace_error(IPC_TR_CLARIFY_ZERO_LENGTH_BD, curr_gpd, QBM_DES_GET_DATALEN(curr_gpd));
                    first_buf = NULL;
                }
            } else
            {
                first_buf = (kal_uint8 *)QBM_DES_GET_DATAPTR(curr_gpd);
            }
        }

        if (first_buf)
        {
            if (IPC_HDR_IS_V4(first_buf)) {
                if (*ipv4_tail_gpd) {
                    QBM_DES_SET_NEXT((*ipv4_tail_gpd), curr_gpd);
                    *ipv4_tail_gpd = curr_gpd;
                } else {
                    *ipv4_head_gpd = curr_gpd;
                    *ipv4_tail_gpd = curr_gpd;
                }
            } else if (IPC_HDR_IS_V6(first_buf)) {
                if (*ipv6_tail_gpd) {
                    QBM_DES_SET_NEXT((*ipv6_tail_gpd), curr_gpd);
                    *ipv6_tail_gpd = curr_gpd;
                } else {
                    *ipv6_head_gpd = curr_gpd;
                    *ipv6_tail_gpd = curr_gpd;
                }
            } else {
                hif_trace_error(IPC_TR_CLARIFY_NONE_IP_PKT, curr_gpd, QBM_DES_GET_DATALEN(curr_gpd));
                qbmt_dest_q(curr_gpd, curr_gpd);
            }
        } else
        {   /* Always drop curr_gpd for parsing error case */
            hif_trace_info(IPC_TR_CLARIFY_ZERO_LENGTH_PKT_DROP, curr_gpd, QBM_DES_GET_DATALEN(curr_gpd));
            qbmt_dest_q(curr_gpd, curr_gpd);
        }
    }

}

/*
 * Assumption: netif read lock is acquired.
 */
static void ipc_forward_ul_ior(ipc_netif_t *netif, ipc_io_request_t *ior)
{
#if IPC_PEER == IPC_PEER_NULL_DROP
    /*
         * Drop all uplink packets (Only for test purpose).
         */
    hif_data_trace(IPC_UL_DROP_UL_IOR, 0, netif, ior);

    ipc_dest_ior(ior);
#elif IPC_PEER == IPC_PEER_NULL_LOOPBACK
    /*
         * Loopback uplink packets. (Only for test purpose).
         */
    if (NULL != netif->config.ipc_dlink_callback_t) {
        hif_data_trace(IPC_UL_LOOPBACK_UL_IOR, 0, netif, ior, netif->config.ipc_dlink_callback_t);
        netif->config.ipc_dlink_callback_t(netif->config.callback_context, ior);
    } else {
        hif_data_trace(IPC_UL_LOOPBACK_UL_IOR_DROP, 0, netif, ior, netif->config.ipc_dlink_callback_t);
        ipc_dest_ior(ior);
    }
#else
    ipc_session_t          *session;
    ipc_io_request_t       *next_ior;
    qbm_gpd                *ipv4_first_gpd;
    qbm_gpd                *ipv4_last_gpd;
    qbm_gpd                *ipv6_first_gpd;
    qbm_gpd                *ipv6_last_gpd;

    for (; ior; ior = next_ior) {
        next_ior = ior->next_request;
        if ( ior->first_gpd && ior->last_gpd ) {
            if (ior->ip_type != IPC_IP_TYPE_MIXED) {
                qbm_gpd *first_gpd;
                qbm_gpd *last_gpd;

                first_gpd = ior->first_gpd;
                last_gpd = ior->last_gpd;

                hif_data_trace(IPC_UL_HANDLE_UL_GPD_LIST, ior->ip_type, netif->config.netif_id, first_gpd, last_gpd);

                /*
                             * HIF network interface told IPv4 or IPv6 case.
                             */
                ipc_do_ul_filter(   ior->ip_type,
                                    netif->config.netif_id,
                                    &first_gpd,
                                    &last_gpd);
                if (first_gpd) {
                    session = ipc_find_session_by_netif(netif, ior->ip_type);
                    if (session) {

                        hif_data_trace(IPC_UL_FORWARD_UL_SDU, ior->ip_type, session->context, first_gpd, last_gpd);

                        IPC_FORWARD_UL_SDU(
                            (ip_type_e)ior->ip_type, /* ip_type */
                            session->context, /* pdn_id */
                            first_gpd, /* p_head */
                            last_gpd); /* p_tail */
                        IPC_R_UNLOCK_OBJECT(session);
                    } else {
                        hif_trace_error(IPC_TR_UL_DROP_FOR_SESSION_DEACT, netif->config.netif_id, ior, ior->ip_type);
                        qbmt_dest_q(first_gpd, last_gpd);
                    }
                }
            } else {
                /*
                              * HIF network interface cannot tell IPv4 or IPv6 case.
                              * Classify GPD into IPv4 and IPv6 lists, and then send them to wireless network respectively.
                              */
                /* ipv4_first_gpd / ipv4_last_gpd / ipv6_first_gpd / ipv6_last_gpd are initiated in this procedure */
                ipc_clarify_gpd(    ior->first_gpd,
                                    ior->last_gpd,
                                    &ipv4_first_gpd,
                                    &ipv4_last_gpd,
                                    &ipv6_first_gpd,
                                    &ipv6_last_gpd);

                if (ipv4_first_gpd) {

                    hif_data_trace(IPC_UL_HANDLE_IPV4_UL_GPD_LIST, ior->ip_type, netif->config.netif_id, ipv4_first_gpd, ipv4_last_gpd);

                    ipc_do_ul_filter(   IPC_IP_TYPE_IPV4,
                                        netif->config.netif_id,
                                        &ipv4_first_gpd,
                                        &ipv4_last_gpd);
                    if (ipv4_first_gpd) {
                        session = ipc_find_session_by_netif(netif, IPC_IP_TYPE_IPV4);
                        if (session) {

                            hif_data_trace(IPC_UL_FORWARD_IPV4_UL_SDU, ior->ip_type, session->context, ipv4_first_gpd, ipv4_last_gpd);

                            IPC_FORWARD_UL_SDU(
                                (ip_type_e)IPC_IP_TYPE_IPV4, /* ip_type */
                                session->context, /* pdn_id */
                                ipv4_first_gpd, /* p_head */
                                ipv4_last_gpd); /* p_tail */
                            IPC_R_UNLOCK_OBJECT(session);
                        } else {
                            hif_trace_error(IPC_TR_UL_DROP_FOR_SESSION_DEACT, netif->config.netif_id, ior, IPC_IP_TYPE_IPV4);
                            qbmt_dest_q(ipv4_first_gpd, ipv4_last_gpd);
                        }
                    }
                }

                if (ipv6_first_gpd) {

                    hif_data_trace(IPC_UL_HANDLE_IPV6_UL_GPD_LIST, ior->ip_type, netif->config.netif_id, ipv6_first_gpd, ipv6_last_gpd);

                    ipc_do_ul_filter(   IPC_IP_TYPE_IPV6,
                                        netif->config.netif_id,
                                        &ipv6_first_gpd,
                                        &ipv6_last_gpd);
                    if (ipv6_first_gpd) {
                        session = ipc_find_session_by_netif(netif, IPC_IP_TYPE_IPV6);
                        if (session) {

                            hif_data_trace(IPC_UL_FORWARD_IPV6_UL_SDU, ior->ip_type, session->context, ipv6_first_gpd, ipv6_last_gpd);

                            IPC_FORWARD_UL_SDU(
                                (ip_type_e)IPC_IP_TYPE_IPV6, /* ip_type */
                                session->context, /* pdn_id */
                                ipv6_first_gpd, /* p_head */
                                ipv6_last_gpd); /* p_tail */
                            IPC_R_UNLOCK_OBJECT(session);
                        } else {
                            hif_trace_error(IPC_TR_UL_DROP_FOR_SESSION_DEACT, netif->config.netif_id, ior, IPC_IP_TYPE_IPV6);
                            qbmt_dest_q(ipv6_first_gpd, ipv6_last_gpd);
                        }
                    }
                }
            } /* end of HIF network interface cannot tell IPv4 or IPv6 case. */
        } else {
            hif_trace_error(IPC_TR_UL_DROP_FOR_INVALID_IOR, netif->config.netif_id, ior, ior->first_gpd, ior->last_gpd);
            IPC_ASSERT(KAL_FALSE);
        }
    } /* end of for (ior) */
#endif
}

static void ipc_on_process_ul_queue(void)
{
    kal_uint32                  mask;
    ipc_internal_ior_t         *head_ior;
    ipc_internal_ior_t         *curr_ior;
    ipc_internal_ior_t         *next_ior;
    ipc_netif_t                *netif;
    ipc_ul_throttle_state_e     th_state;

    HIF_SWLA_START("IU2");
	hif_data_trace(IPC_UL_DEQUEUE_UPLINK_QUEUE, ipc_ul_throttle_state_s, ipc_ul_pending_ior_head_s, ipc_ul_pending_ior_tail_s, ipc_ul_ior_head_s);

    /*
     * 1. Dequeue the IOR list
     * 2. Insert pending queue into the head of process queue
     * if it's not in SUSPEND state and pending queue is not empty.
     */
    mask = SaveAndSetIRQMask();
    th_state = ipc_ul_throttle_state_s;

    head_ior = ipc_ul_ior_head_s;
    /* 2 */
    if ((th_state != IPC_UL_THROTTLE_STATE_SUSPEND) &&
        (NULL != ipc_ul_pending_ior_head_s)) {
        ipc_ul_pending_ior_tail_s->public.next_request = &(head_ior->public);
        head_ior = ipc_ul_pending_ior_head_s;
        ipc_ul_pending_ior_head_s = NULL;
        ipc_ul_pending_ior_tail_s = NULL;
        ipc_ul_pending_ior_cnt_s = 0;
    }
    ipc_ul_ior_head_s = NULL;
    ipc_ul_ior_tail_s = NULL;
    ipc_ul_processing_s = KAL_FALSE;
    RestoreIRQMask(mask);

    hif_data_trace(IPC_UL_DEQUEUE_UPLINK_QUEUE_DONE, th_state, ipc_ul_pending_ior_head_s, ipc_ul_pending_ior_tail_s, head_ior);

    for (curr_ior = head_ior; curr_ior; curr_ior = next_ior) {
        next_ior = (ipc_internal_ior_t *)(curr_ior->public.next_request);

        hif_data_trace(IPC_UL_ON_PROCESS_UPLINK_QUEUE_IN_LOOP, 0, curr_ior, curr_ior->netif);


        if ((NULL == next_ior) || 
           (head_ior->netif != next_ior->netif)) {

            curr_ior->public.next_request = NULL;

            netif = head_ior->netif;
            IPC_R_LOCK_OBJECT(netif);
            if (netif) {
                /*
                 * Reload uplink buffers for the network inteface.
                 */
                ipc_reload_uplink(netif);

                /*
                 * Forward uplink IP datagram to wireless network or pending_list depended on throttle state.
                 */
                if ((IPC_UL_THROTTLE_STATE_SUSPEND != th_state) ||
                    (netif->config.features & IPC_F_LATENCY_CONCERN)) {

                    /*
                     * Forward uplink IP datagrams to wireless network.
                     */
                    ipc_forward_ul_ior(
                        netif,
                        &(head_ior->public));

                    IPC_R_UNLOCK_OBJECT(netif);
                } else {
                    /*
                     * Move IORs into pending list if throttle state is in SUSPEND
                     * and there is no latency-concern in current interface.
                     */
                    if (ipc_ul_pending_ior_tail_s) {
                        ipc_ul_pending_ior_tail_s->public.next_request = &(head_ior->public);
                        ipc_ul_pending_ior_tail_s = curr_ior;
                    } else {
                        ipc_ul_pending_ior_head_s = head_ior;
                        ipc_ul_pending_ior_tail_s = curr_ior;
                    }
                    ipc_ul_pending_ior_cnt_s++;

                    IPC_R_UNLOCK_OBJECT(netif);

                    hif_data_trace(IPC_UL_ON_PROCESS_UPLINK_QUEUE_PENDING, ipc_ul_pending_ior_cnt_s, curr_ior, curr_ior->netif);
                }
            } else {
                hif_trace_error(IPC_TR_UL_DROP_FOR_INVALID_NETIF, head_ior->netif, &(head_ior->public));
                ipc_dest_ior(&(head_ior->public));
            }

            head_ior = next_ior;
        }
    }

    HIF_SWLA_STOP("IU2");
}

void ipc_on_retry_ul_reload(void)
{
    kal_uint32      netif_bit_ids;
    kal_uint32      lbs; /* least significant bit set to 1 */
    ipc_netif_t    *netif;
    kal_uint32      mask;
    
    mask = SaveAndSetIRQMask();
    ipc_ul_reload_retrying_s = KAL_FALSE;
    RestoreIRQMask(mask);

    netif_bit_ids = ipc_get_all_netif_ul_reload_retry();

    hif_data_trace(IPC_UL_ON_RETRY_RELOAD, 0, netif_bit_ids);

    while (netif_bit_ids) {
        lbs = netif_bit_ids & ((~netif_bit_ids) + 1);
        netif_bit_ids &= (~lbs);

        netif = ipc_find_netif_by_bit_id(lbs);

        hif_data_trace(IPC_UL_ON_RETRY_RELOAD_FOR_NETIF, 0, netif, lbs);

        if (netif) {
            ipc_reload_uplink(netif);
            IPC_R_UNLOCK_OBJECT(netif);
        }
    }
}

static void ipc_reg_callbacks(void)
{
    /*
     * Register the callback functions with UPCM.
     */
    IPC_REG_CBK_DLVR_DL_SDU(ipc_on_downlink); /* LTE downlink callback. */
    IPC_REG_CBK_NOTIFY_LTE_TICK_SOURCE(ipc_on_lte_tick_source); /* LTE change polling source */ 

#if defined (__HIF_CCCI_SUPPORT__)
    /*
     * Register the callback function with ccci_sysmsg for UL throttle.
     */
    IPC_ASSERT(ccci_register_sysmsgsvc_callback(CCMSG_ID_SYSMSGSVC_SW_TPUT_THROTTLING, ipc_ul_throttle_sysmsgsvc_cbk));
#endif
}

kal_uint16 ipc_calc_checksum16(
        kal_uint8  *data,
        kal_uint32  length)
{
    kal_uint32 odd = ((kal_uint32)data & 0x1);
    kal_uint32 offset;
    kal_uint32 sum32;
    kal_uint32 idx;
    kal_uint16 sum16;

    if (!odd) {
        sum32 = 0;
    } else {
#ifndef IPC_ON_BIG_ENDIAN_PLATFORM /* little-endian platform */
        sum32 = ((kal_uint16)(*data) << 8);
#else
        sum32 = (*data);
#endif
        data++;
        length--;
    }

    offset = ((length >> 1) << 1);
    for (idx = 0; idx < offset; idx += 2) {
        sum32 += *((kal_uint16 *)(data + idx));
    }
    if ((length & 0x1)) {
        sum32 += (kal_uint16)(*(data + length - 1));
    }

    sum32 = (sum32 & 0xffff) + (sum32 >> 16); /* add high word and low word. */
    sum16 = (kal_uint16)((sum32 & 0xffff) + (sum32 >> 16)); /* add carry */
    if (odd) {
        sum16 = (sum16 >> 8) | ((sum16 & 0xff) << 8);
    }
    return sum16;
}

kal_uint16 ipc_calc_tcp_checksum(
        kal_bool    is_ipv4,
        kal_uint8  *src_addr,
        kal_uint8  *dst_addr,
        kal_uint8  *tcp_header,
        kal_uint32  tcp_len)
{
    kal_uint32 sum32;
    kal_uint32 length;
    kal_uint16 sum16;

    /*
     * It's designed for length < 2^16.
     */
    IPC_ASSERT(tcp_len <= (kal_uint32)(is_ipv4 ? 65507 : 65487));

    /*
     * Pseudo-header.
     */
    sum32 = IPC_H2N_2B(tcp_len); /* TCP length, assue it's less than 2^16. */
    sum32 += IPC_H2N_2B(IPC_HDR_PROT_TCP); /* Next Header */
    length = ((is_ipv4) ? IPC_HDR_V4_ADDR_SIZE : IPC_HDR_V6_ADDR_SIZE);
    sum32 += ipc_calc_checksum16(src_addr, length);
    sum32 += ipc_calc_checksum16(dst_addr, length);

    /*
     * TCP header and data.
     */
    sum32 += ipc_calc_checksum16(tcp_header, tcp_len);

    sum32 = (sum32 & 0xffff) + (sum32 >> 16); /* add high word and low word. */
    sum16 = (kal_uint16)((sum32 & 0xffff) + (sum32 >> 16)); /* add carry */
    sum16 = ~sum16;
    return IPC_H2N_2B(sum16);
}

kal_uint16 ipc_calc_udp_checksum(
        kal_bool    is_ipv4,
        kal_uint8  *src_addr,
        kal_uint8  *dst_addr,
        kal_uint8  *udp_header,
        kal_uint32  udp_len)
{
    kal_uint32 sum32;
    kal_uint32 length;
    kal_uint16 sum16;

    /*
     * It's designed for length < 2^16.
     */
    IPC_ASSERT(udp_len <= (kal_uint32)(is_ipv4 ? 65507 : 65487));

    /*
     * Pseudo-header.
     */
    sum32 = IPC_H2N_2B(udp_len); /* UDP length, assue it's less than 2^16. */
    sum32 += IPC_H2N_2B(IPC_HDR_PROT_UDP); /* Next Header */
    length = ((is_ipv4) ? IPC_HDR_V4_ADDR_SIZE : IPC_HDR_V6_ADDR_SIZE);
    sum32 += ipc_calc_checksum16(src_addr, length);
    sum32 += ipc_calc_checksum16(dst_addr, length);

    /*
     * UDP header and data.
     */
    sum32 += ipc_calc_checksum16(udp_header, udp_len);

    sum32 = (sum32 & 0xffff) + (sum32 >> 16); /* add high word and low word. */
    sum16 = (kal_uint16)((sum32 & 0xffff) + (sum32 >> 16)); /* add carry */
    sum16 = ~sum16;
    return IPC_H2N_2B(sum16);
}

kal_uint16 ipc_calc_ipv4_checksum(kal_uint8  *ip_header)
{
    kal_uint16  sum16;

    sum16 = ipc_calc_checksum16(ip_header, IPC_HDR_V4_GET_IHL(ip_header));
    sum16 = ~sum16;
    return IPC_H2N_2B(sum16);
}

static void ipc_get_qbm_datahead(void* gpd, kal_uint32 *datalen_ptr, void **payload_ptr)
{
    IPC_ASSERT(gpd && datalen_ptr && payload_ptr);

    /* Get total data length */
    *datalen_ptr = QBM_DES_GET_DATALEN(gpd);

    /* Get first data pointer */
    if (QBM_DES_GET_BDP(gpd))
    {
        if (*datalen_ptr)   /* GPD with data : get 1st BD with-data for payload head */
        {
            qbm_gpd* bd;

            /* get bd data ptr */
            bd = QBM_DES_GET_DATAPTR(gpd);

            /* Loop to trace 1st DL BD with data buffer */
            while (bd && (QBM_DES_GET_DATALEN(bd) == 0))
            {
                bd = (QBM_DES_GET_EOL(bd))?(NULL):((qbm_gpd*)QBM_DES_GET_NEXT(bd));
            }
            
            if (bd)
            {
                *payload_ptr = (kal_uint8 *)QBM_DES_GET_DATAPTR(bd);
            } else
            {
                hif_trace_error(IPC_TR_GET_QBM_DATAHEAD_ZERO_LENGTH_BD, gpd, QBM_DES_GET_DATALEN(gpd));
                *payload_ptr = NULL;
            }
        }else   /* GPD without data : get 1st BD */
        {
            void* bd;

            /* get bd data ptr */
            bd = QBM_DES_GET_DATAPTR(gpd);

            *payload_ptr = (kal_uint8 *)QBM_DES_GET_DATAPTR(bd);
        }
    } else {
        *payload_ptr = (kal_uint8*)QBM_DES_GET_DATAPTR(gpd);
    }
}


static void ipc_push_qbm_datahead(void* gpd, kal_uint32 offset, kal_uint32 *datalen_ptr, void **payload_ptr)
{
    kal_uint8* data_ptr = NULL;
    kal_uint32 data_len = 0;

    IPC_ASSERT(gpd && datalen_ptr && payload_ptr);

    if (QBM_DES_GET_BDP(gpd)) {
        void* bd;

        /* set bd data ptr */
        bd = QBM_DES_GET_DATAPTR(gpd);

        data_ptr = (kal_uint8*)QBM_DES_GET_DATAPTR(bd);
        QBM_DES_SET_DATAPTR(bd, data_ptr-offset);

        /* set bd data len */
        data_len = QBM_DES_GET_DATALEN(bd);
        QBM_DES_SET_DATALEN(bd, data_len+offset);

        /* set bd checksum */
        qbm_cal_set_checksum(bd);
    } else {
        data_ptr = (kal_uint8*)QBM_DES_GET_DATAPTR(gpd);
        QBM_DES_SET_DATAPTR(gpd, data_ptr-offset);
    }

    /* set gpd data len */
    data_len = QBM_DES_GET_DATALEN(gpd);
    QBM_DES_SET_DATALEN(gpd, data_len+offset);

    /* set gpd checksum */
    qbm_cal_set_checksum(gpd);

    *datalen_ptr = data_len + offset;
    *payload_ptr = (void*)(data_ptr - offset);
}


static void ipc_timer_init()
{
    ipc_stack_timer_s = stack_create_timer("IPC_T", MOD_IPCORE);
    if (NULL == ipc_stack_timer_s) {
        IPC_ASSERT(KAL_FALSE);
        return;
    }

    ipc_es_ul_throttle_s = evshed_create(
                            "IPC_UL_THROTTLE", /* timer_name: event scheduler name */
                            MOD_IPCORE, /* dest_mod_id: system sends timeout message to this module when event scheduler timeout happens */
                            0, /* fuzz */
                            0); /* max_delay_ticks */

    if (ipc_es_ul_throttle_s) {
        evshed_set_index(ipc_es_ul_throttle_s, IPC_ES_INDEX_UL_THROTTLE);
    } else {
        IPC_ASSERT(KAL_FALSE);
    }
}

static void ipc_em_send_ul_throttle_status(void)
{
#ifdef __EM_MODE__
    em_ipc_ul_throttle_status_ind_struct_t *em_info_ptr;
    ilm_struct ilm;

    if (ipc_em_on_s) {
        em_info_ptr = (em_ipc_ul_throttle_status_ind_struct_t *)
                        construct_local_para(sizeof(em_ipc_ul_throttle_status_ind_struct_t), TD_RESET);

        kal_mem_cpy(&(em_info_ptr->throttle_conf), &ipc_ul_throttle_conf_s, sizeof(ipc_ul_throttle_conf_t));
        em_info_ptr->throttle_state = ipc_ul_throttle_state_s;

        ilm.src_mod_id     = MOD_IPCORE;
        ilm.dest_mod_id    = MOD_DHL;
        ilm.msg_id         = MSG_ID_EM_IPC_UL_THROTTLE_STATUS_IND;
        ilm.sap_id         = IPCORE_SAP;
        ilm.local_para_ptr = (local_para_struct *)em_info_ptr;
        ilm.peer_buff_ptr  = NULL;

        dhl_EM_logger(&ilm);
        destroy_ilm(&ilm);
    }
#endif
}

static void ipc_em_update_req_hdlr(local_para_struct *local_para_ptr)
{
    l4cps_em_update_req_struct *p_req = (l4cps_em_update_req_struct *)local_para_ptr;

    /*
     * only process Tool source,
     * Ingore AP.
     * AP EM needed to be discussed.
     */
    if (p_req->em_src == EM_FROM_ELT) {
        switch (p_req->info_request[IPC_EM_UL_THROTTLE_STATUS]) {
            case EM_ON:
                ipc_em_on_s = 1;
                break;

            case EM_OFF:
                ipc_em_on_s = 0;
                break;

            case EM_NC:
                /* no change */
                break;

            default:
                /*can't reach here*/
                IPC_ASSERT(KAL_FALSE);
        }

        /* For EM ELT update info*/
        ipc_em_send_ul_throttle_status();
    }
}

static void ipc_start_ul_throttle_timer(kal_uint32 elapse_time);
static void ipc_ul_throttle_timeout(void *event_hf_param)
{
    kal_uint32              mask;
    kal_bool                to_send_msg;

    hif_data_trace(IPC_TR_TIMER_UL_THROTTLE_TIMEOUT, kal_get_systicks(),
                    ipc_ul_throttle_state_s,
                    ipc_ul_throttle_conf_s.enabled,
                    ipc_ul_throttle_conf_s.active_period_100ms,
                    ipc_ul_throttle_conf_s.suspend_period_100ms);

    if (ipc_ul_throttle_conf_s.enabled) {
        if (IPC_UL_THROTTLE_STATE_ACTIVE == ipc_ul_throttle_state_s) {
            /* UL throttle state: ACTIVE -> SUSPEND */
            ipc_start_ul_throttle_timer(ipc_ul_throttle_conf_s.suspend_period_100ms * KAL_TICKS_100_MSEC);
            ipc_ul_throttle_state_s = IPC_UL_THROTTLE_STATE_SUSPEND;
        } else if (IPC_UL_THROTTLE_STATE_SUSPEND == ipc_ul_throttle_state_s) {
            /* UL throttle state: SUSPEND -> ACTIVE */
            ipc_start_ul_throttle_timer(ipc_ul_throttle_conf_s.active_period_100ms * KAL_TICKS_100_MSEC);
            ipc_ul_throttle_state_s = IPC_UL_THROTTLE_STATE_ACTIVE;

            /*
             * IPCORE need to process ul queue if ul pending queue is not empty
             */
            mask = SaveAndSetIRQMask();
            to_send_msg = (!ipc_ul_processing_s && ipc_ul_pending_ior_head_s);
            if (to_send_msg) {
                ipc_ul_processing_s = KAL_TRUE;
            }
            RestoreIRQMask(mask);

            /*
             * Switch to IPCORE context.
             */
            if (to_send_msg) {
                msg_send6(MOD_NIL, /* src_mod_id */
                          MOD_IPCORE, /* dest_mod_id */
                          IPCORE_SAP, /* sap_id */
                          MSG_ID_IPCORE_PROCESS_UL_QUEUE_REQ, /* msg_id */
                          NULL, /* local_para_ptr */
                          NULL); /* peer_buff_ptr */
            }
        } else {
            IPC_ASSERT(KAL_FALSE);
        }

        /* For EM ELT update info*/
        ipc_em_send_ul_throttle_status();
    }
}


static void ipc_start_ul_throttle_timer(kal_uint32 elapse_time)
{
#ifndef ATEST_SYS_IPCORE
    IPC_ASSERT(ipc_es_ul_throttle_s && elapse_time);

    ipc_eid_ul_throttle_s =
        evshed_set_event(ipc_es_ul_throttle_s,
                         ipc_ul_throttle_timeout,
                         NULL,
                         elapse_time);

    IPC_ASSERT(ipc_eid_ul_throttle_s);
    hif_data_trace(IPC_TR_START_UL_THROTTLE_TIMER, kal_get_systicks(), elapse_time);
#endif
}

/*------------------------------------------------------------------------------
 * Public fucntions.
 *----------------------------------------------------------------------------*/
kal_bool ipc_init(void)
{
    nmu_init();
    hmu_boot_init();

    ipc_object_init();
    ipc_reg_callbacks();
    ipc_timer_init();

    pfm_init();

    return KAL_TRUE;
}

void ipc_on_ilm(ilm_struct *ilm)
{
    switch (ilm->msg_id) {
    case MSG_ID_IPCORE_PROCESS_UL_QUEUE_REQ:
        ipc_on_process_ul_queue();
        break;

    case MSG_ID_IPCORE_RETRY_UL_RELOAD_REQ:
        ipc_on_retry_ul_reload();
        break;

    case MSG_ID_IPCORE_UPCM_PDN_BIND_IND:
        ipc_on_pdn_bind(ilm->src_mod_id, ilm->local_para_ptr);
        break;

    case MSG_ID_IPCORE_UPCM_PDN_DEACT_IND:
        ipc_on_pdn_deact(ilm->local_para_ptr);
        break;

    case MSG_ID_DHCP4C_ACTIVATE_RSP:
        ipc_on_dhcp4c_activate_rsp(ilm->local_para_ptr);
        break;

    case MSG_ID_DHCP4C_DEACTIVATE_RSP:
        ipc_on_dhcp4c_deactivate_rsp(ilm->local_para_ptr);
        break;

    case MSG_ID_DHCP4C_IP_UP_IND:
        ipc_on_dhcp4c_ip_up_ind(ilm->local_para_ptr);
        break;

    case MSG_ID_DHCP4C_IP_DOWN_IND:
        ipc_on_dhcp4c_ip_down_ind(ilm->local_para_ptr);
        break;

    case MSG_ID_DHCP4C_PACKET_IND:
        ipc_on_dhcp4c_packet_ind(ilm->local_para_ptr);
        break;

#ifdef ATEST_SYS_IPCORE
    case MSG_ID_IPCORE_UL_PACKET_FILTERED_REQ:
        ipc_ut_on_ul_packet_filtered_req(ilm->local_para_ptr);
        break;

    case MSG_ID_IPCORE_DL_PACKET_FILTERED_REQ:
        ipc_ut_on_dl_packet_filtered_req(ilm->local_para_ptr);
        break;

    case MSG_ID_IPCORE_UL_PACKET_FILTERED_WITH_INFO_REQ:
        ipc_ut_on_ul_packet_filtered_with_info_req(ilm->local_para_ptr);
        break;

    case MSG_ID_IPCORE_DL_PACKET_FILTERED_WITH_INFO_REQ:
        ipc_ut_on_dl_packet_filtered_with_info_req(ilm->local_para_ptr);
        break;

#endif

    case MSG_ID_IPCORE_LINK_UP_IND:
        ipc_on_ipcore_link_up_ind(ilm->local_para_ptr);
        break;

    case MSG_ID_IPCORE_IP_UP_IND:
        ipc_on_ipcore_ip_up_ind(ilm->local_para_ptr);
        break;

    case MSG_ID_IPCORE_LINK_UP_RSP:
        ipc_on_ipcore_up_rsp(ilm->local_para_ptr);
        break;

    case MSG_ID_IPCORE_IP_UP_RSP:
        ipc_on_ipcore_up_rsp(ilm->local_para_ptr);
        break;

    case MSG_ID_IPCORE_QUERY_INFO_REQ:
        ipc_on_query_info(ilm->src_mod_id, ilm->local_para_ptr);
        break;

    case MSG_ID_IPCORE_SET_UL_THROTTLE:
        ipc_set_ul_throttle(ilm->local_para_ptr);
        break;

    case MSG_ID_TIMER_EXPIRY:
    {
#ifndef ATEST_SYS_IPCORE
        if (stack_is_time_out_valid(ipc_stack_timer_s)) {
            switch (evshed_get_index(ilm)) {
            case IPC_ES_INDEX_UL_THROTTLE:
                evshed_timer_handler(ipc_es_ul_throttle_s);
                break;
            default:
                IPC_ASSERT(0);
                break;
            }

            stack_process_time_out(ipc_stack_timer_s);
        }
#else
        ipc_ul_throttle_timeout(NULL);
#endif
        break;
    }

    case MSG_ID_L4CPS_EM_UPDATE_REQ:
        ipc_em_update_req_hdlr(ilm->local_para_ptr);
        break;

    /* MSG to PFM (Packet Filter Manager) */
    case MSG_ID_PFM_REGISTER_FILTER_REQ:
    case MSG_ID_PFM_DEREGISTER_FILTER_REQ:
        pfm_on_ilm(ilm);
        break;

    default:
        IPC_UT_ASSERT(KAL_FALSE, IPC_UT_NO_ERROR);
        break;
    }
}

kal_bool ipc_reset(void)
{
    kal_uint8       idx;
    ipc_session_t  *session;
    kal_uint32     session_ip_id;
    kal_uint8      session_type;

    hif_trace_info(IPC_TR_RESET_START);

    ipc_in_reset_s = KAL_TRUE;

    /*
     * 2012/07/24, per moja.hsu MoDIS unit test requirement,
     * deactivate all sessions and register callback functions with UPCM at reset.
     */
    for (idx = 0; idx < IPC_MAX_SESSION_CNT; idx++) {
        session = ipc_find_session_by_context(idx);

        hif_trace_info(IPC_TR_DEL_SESSION, session, idx);

        if (session) {
            session_ip_id = session->ip_id;
            session_type = session->type;
            IPC_R_UNLOCK_OBJECT(session);

            hif_trace_info(IPC_TR_DEL_SESSION_INFO, session_type, session->ip_id, idx);

            if (IPC_IP_TYPE_IPV6 == session_type || IPC_IP_TYPE_MIXED == session_type) {
                nmu_set_ip6_dns_num(session_ip_id, 0);
                nmu_set_ip6_down(session_ip_id);
            }
            if (IPC_IP_TYPE_IPV4 == session_type || IPC_IP_TYPE_MIXED == session_type) {
                nmu_set_ip4_dns_num(session_ip_id, 0);
                nmu_set_ip4_down(session_ip_id);
            }

            ipc_disable_dhcp4c(session); /* disable DHCPv4 it's been enabled */
            ipc_update_session_state(session, IPC_SESSION_STATE_UNBIND);
            ipc_del_session(session);
        }
    }

    /* Remove all attached network interface during reset */
    for (idx = 0 ; idx < IPC_MAX_NETIF_CNT ; idx ++)
    {
        ipc_netif_t *netif;

        netif = ipc_find_netif_by_bit_id(1 << idx);

        hif_trace_info(IPC_TR_DEL_NETIF, netif, idx);

        if (netif) {
            IPC_R_UNLOCK_OBJECT(netif);
            ipc_del_netif(netif);
        }
    }

    ipc_filter_init();
    ipc_ntfy_init();

    ipc_reg_callbacks();

    ipc_in_reset_s = KAL_FALSE;

    hif_trace_info(IPC_TR_RESET_END);

    return KAL_TRUE;
}

kal_bool ipc_is_in_reset(void)
{
    return ipc_in_reset_s;
}

kal_bool ipc_attach(
    ipc_conf_t             *config,
    ipc_handle_t           *handle)
{
    ipc_netif_t     *netif;

    *handle = IPC_INVALID_HANDLE;

    if (NULL == config) {
        IPC_ASSERT(KAL_FALSE);
        return KAL_FALSE;
    }
    hif_trace_info(IPC_TR_NETIF_ATTACHING, config->module_id, config->netif_id, config->callback_context, config->features);

    netif = ipc_new_netif(config);
    if (netif) {
        *handle = (ipc_handle_t)netif;

        /* In ESL environment, IPCore needs to send ILM to UPCM to request binding if network interface is attached */
#ifdef __ESL_COSIM_LTE__
        {
            ipcore_upcm_esl_pdn_bind_req_struct *req;

            req = (ipcore_upcm_esl_pdn_bind_req_struct *)construct_local_para(sizeof(ipcore_upcm_esl_pdn_bind_req_struct), TD_RESET);
            IPC_ASSERT(req);

            req->network_interface_id = config->netif_id;

            msg_send6(MOD_IPCORE, /* src_mod_id */
                      MOD_UPCM, /* dest_mod_id */
                      IPCORE_SAP, /* sap_id */
                      MSG_ID_IPCORE_UPCM_ESL_PDN_BIND_REQ, /* msg_id */
                      (local_para_struct *)req, /* local_para_ptr */
                      NULL); /* peer_buff_ptr */
        }
#endif

        /* Notify for attach event */
        ipc_do_ntfy(netif, IPC_NTFY_TYPE_ATTACH);

        return KAL_TRUE;
    } else {
        return KAL_FALSE;
    }
}

kal_bool ipc_detach(
    ipc_handle_t           handle)
{
    hif_trace_info(IPC_TR_NETIF_DETACHING, handle);

    /* Notify for detach event "before" actually detach network interface */
    ipc_do_ntfy((ipc_netif_t *)handle, IPC_NTFY_TYPE_DETACH);

    return ipc_del_netif((ipc_netif_t *)handle);
}

kal_bool ipc_uplink(
    ipc_handle_t            handle,
    ipc_io_request_t       *ior)
{
    ipc_io_request_t   *curr_ior;
    ipc_io_request_t   *tail_ior;
    kal_uint32          mask;
    kal_bool            to_send_msg;

    HIF_SWLA_START("IU1");

    /*
     * Note that, since we reload UL buffers in IPCORE context (ipc_on_process_ul_queue()),
     * all exception cases reuquired for dropping UL packets discard will be done there 
     * for simplicity. So, netif lock is not required here.
     */

    if (ior) {
        /*
         * Enqueue the IOR list and keep the information about the corresponding netif.
         */
        curr_ior = ior;
        do {
            ((ipc_internal_ior_t *)curr_ior)->netif = (ipc_netif_t *)handle;
            tail_ior = curr_ior;
    
            curr_ior = curr_ior->next_request;
        } while (curr_ior);

        hif_data_trace(IPC_UL_UPLINK_CALLBACK, 0, ior, handle);

        mask = SaveAndSetIRQMask();
        if (ipc_ul_ior_tail_s) {
            ipc_ul_ior_tail_s->public.next_request = ior;
            ipc_ul_ior_tail_s = (ipc_internal_ior_t *)tail_ior;
        } else {
            ipc_ul_ior_head_s = (ipc_internal_ior_t *)ior;
            ipc_ul_ior_tail_s = (ipc_internal_ior_t *)tail_ior;
        }

        to_send_msg = (!ipc_ul_processing_s);
        ipc_ul_processing_s = KAL_TRUE;
        RestoreIRQMask(mask);
    
        /*
         * Switch to IPCORE context.
         */
        if (to_send_msg) {
            msg_send6(  MOD_NIL, /* src_mod_id */
                        MOD_IPCORE, /* dest_mod_id */
                        IPCORE_DATAPATH_SAP, /* sap_id */
                        MSG_ID_IPCORE_PROCESS_UL_QUEUE_REQ, /* msg_id */
                        NULL, /* local_para_ptr */
                        NULL); /* peer_buff_ptr */
        }
    
        HIF_SWLA_STOP("IU1");
        return KAL_TRUE;
    } else {
        hif_trace_error(IPC_TR_UL_INVALID_PARAM, handle, ior);
        HIF_SWLA_STOP("IU1");
        return KAL_FALSE;
    }
}

kal_int32 ipc_get_ip_id(
    ipc_handle_t            handle)
{
    ipc_netif_t *netif = (ipc_netif_t *)handle;
    kal_int32   ip_id;

    IPC_R_LOCK_OBJECT(netif);
    if (netif) {
        ip_id = ipc_map_netif_to_ip_id(netif);
        IPC_R_UNLOCK_OBJECT(netif);
    } else {
        ip_id = -1;
    }

    return ip_id;
}

void ipc_need_ul_reload(
    ipc_handle_t            handle)
{
    ipc_netif_t *netif = (ipc_netif_t *)handle;

    IPC_R_LOCK_OBJECT(netif);
    if (netif) {
        ipc_set_netif_ul_reload_retry(netif, KAL_TRUE);
        ipc_set_netif_ul_set_need_reload(netif, KAL_TRUE);
        IPC_R_UNLOCK_OBJECT(netif);
    }
}

void ipc_check_ul_reload_retry(void)
{
    kal_uint32      netif_ul_reload_retry;
    kal_uint32      mask;
    kal_bool        to_send_msg;

    netif_ul_reload_retry = ipc_get_all_netif_ul_reload_retry();

    if (0 != netif_ul_reload_retry)
    {
        hif_data_trace(IPC_UL_CHECK_UL_RELOAD_RETRY, 0, netif_ul_reload_retry);

        mask = SaveAndSetIRQMask();
        to_send_msg = (!ipc_ul_reload_retrying_s);
        ipc_ul_reload_retrying_s = KAL_TRUE;
        RestoreIRQMask(mask);

        if (to_send_msg) {
            msg_send6(  MOD_NIL, /* src_mod_id */
                        MOD_IPCORE, /* dest_mod_id */
                        IPCORE_DATAPATH_SAP, /* sap_id */
                        MSG_ID_IPCORE_RETRY_UL_RELOAD_REQ, /* msg_id */
                        NULL, /* local_para_ptr */
                        NULL); /* peer_buff_ptr */
        }
    }
}

void ipc_notify_link_change(kal_uint32 netif_id, kal_uint8 ip_type, kal_bool link_update, kal_bool is_up)
{
    ipc_netif_t *netif;

    hif_trace_info(IPC_TR_NOTIFY_LINK_CHANGE_BEGIN, netif_id, ip_type, link_update, is_up);

    netif = ipc_find_netif(netif_id);
    if (netif)
    {
        IPC_R_UNLOCK_OBJECT(netif);

        hif_trace_info(IPC_TR_NOTIFY_LINK_CHANGE_FOR_NETIF_BEGIN, netif, netif_id, ip_type, link_update, is_up);
        ipc_notify_netif_link_change(netif, ip_type, link_update, is_up);
        hif_trace_info(IPC_TR_NOTIFY_LINK_CHANGE_FOR_NETIF_END, netif, netif_id, ip_type, link_update, is_up);
    } else
    {
        hif_trace_info(IPC_TR_NOTIFY_LINK_CHANGE_UNKNOWN_NETIF, netif_id);
    }

    hif_trace_info(IPC_TR_NOTIFY_LINK_CHANGE_END, netif_id, ip_type, link_update, is_up);
}

kal_int32 
ipc_register_ul_filter_cbk(
    ipc_filter_rules_t     *rules, 
    ipc_filter_callback_t   callback_func, 
    void                   *callback_context)
{
    hif_trace_info(IPC_TR_REG_UL_FILTER_CBK_BEGIN, rules, callback_func, callback_context);
    return ipc_register_filter(KAL_TRUE, KAL_FALSE, rules, callback_func, callback_context, MOD_NIL);
}

kal_int32 
ipc_register_dl_filter_cbk(
    ipc_filter_rules_t     *rules, 
    ipc_filter_callback_t   callback_func, 
    void                   *callback_context)
{
    hif_trace_info(IPC_TR_REG_DL_FILTER_CBK_BEGIN, rules, callback_func, callback_context);
    return ipc_register_filter(KAL_FALSE, KAL_FALSE, rules, callback_func, callback_context, MOD_NIL);
}

kal_int32 
ipc_register_ul_filter_msg(
    ipc_filter_rules_t     *rules,
    module_type             callback_module,
    void                   *callback_context)
{
    hif_trace_info(IPC_TR_REG_UL_FILTER_MSG_BEGIN, rules, callback_module, callback_context);
    return ipc_register_filter(KAL_TRUE, KAL_FALSE, rules, ipc_forward_ul_packet_by_msg, callback_context, callback_module);
}

kal_int32 
ipc_register_dl_filter_msg(
    ipc_filter_rules_t     *rules,
    module_type             callback_module,
    void                   *callback_context)
{
    hif_trace_info(IPC_TR_REG_DL_FILTER_MSG_BEGIN, rules, callback_module, callback_context);
    return ipc_register_filter(KAL_FALSE, KAL_FALSE, rules, ipc_forward_dl_packet_by_msg, callback_context, callback_module);
}

kal_int32 
ipc_register_ul_filter_with_info_cbk(
    ipc_filter_rules_t               *rules, 
    ipc_filter_with_info_callback_t   callback_func, 
    void                             *callback_context)
{
    hif_trace_info(IPC_TR_REG_UL_FILTER_WITH_INFO_CBK_BEGIN, rules, callback_func, callback_context);
    return ipc_register_filter(KAL_TRUE, KAL_TRUE, rules, callback_func, callback_context, MOD_NIL);
}

kal_int32 
ipc_register_dl_filter_with_info_cbk(
    ipc_filter_rules_t               *rules, 
    ipc_filter_with_info_callback_t   callback_func, 
    void                             *callback_context)
{
    hif_trace_info(IPC_TR_REG_DL_FILTER_WITH_INFO_CBK_BEGIN, rules, callback_func, callback_context);
    return ipc_register_filter(KAL_FALSE, KAL_TRUE, rules, callback_func, callback_context, MOD_NIL);
}

kal_int32 
ipc_register_ul_filter_with_info_msg(
    ipc_filter_rules_t     *rules,
    module_type             callback_module,
    void                   *callback_context)
{
    hif_trace_info(IPC_TR_REG_UL_FILTER_WITH_INFO_MSG_BEGIN, rules, callback_module, callback_context);
    return ipc_register_filter(KAL_TRUE, KAL_TRUE, rules, ipc_forward_ul_packet_with_info_by_msg, callback_context, callback_module);
}

kal_int32 
ipc_register_dl_filter_with_info_msg(
    ipc_filter_rules_t     *rules,
    module_type             callback_module,
    void                   *callback_context)
{
    hif_trace_info(IPC_TR_REG_DL_FILTER_WITH_INFO_MSG_BEGIN, rules, callback_module, callback_context);
    return ipc_register_filter(KAL_FALSE, KAL_TRUE, rules, ipc_forward_dl_packet_with_info_by_msg, callback_context, callback_module);
}

void 
ipc_deregister_ul_filter(
    kal_int32               filter_id)
{
    hif_trace_info(IPC_TR_DEREG_UL_FILTER_BEGIN, filter_id);
    ipc_deregister_filter(filter_id);
}

void 
ipc_deregister_dl_filter(
    kal_int32               filter_id)
{
    hif_trace_info(IPC_TR_DEREG_DL_FILTER_BEGIN, filter_id);
    ipc_deregister_filter(filter_id);
}

kal_bool 
ipc_gpd_copy(
    kal_uint8              *dst_buffer,
    kal_uint32              dst_max_len,
    kal_uint32             *dst_len_copied,
    qbm_gpd                *src_head_gpd,
    qbm_gpd                *src_tail_gpd)
{
    kal_bool retval;

    IPC_ASSERT(dst_buffer);
    IPC_ASSERT(dst_len_copied);
    IPC_ASSERT(src_head_gpd);
    IPC_ASSERT(src_tail_gpd);

    hif_trace_info(IPC_TR_GPD_COPY_BEGIN, dst_buffer, dst_max_len, dst_len_copied, src_head_gpd, src_tail_gpd);
    retval = ipc_do_gpd_copy(dst_buffer, dst_max_len, dst_len_copied, src_head_gpd, src_tail_gpd);
    hif_trace_info(IPC_TR_GPD_COPY_END, retval, dst_max_len, *dst_len_copied);

    return retval;
}

static INLINE kal_bool
ipc_pack_pkt(
    kal_bool    uplink,
    ipc_pkt_t   *pkt,
    ipc_hdr_t   *hdr,
    qbm_gpd     **head_gpd,
    qbm_gpd     **tail_gpd)
{
    kal_bool    fill_in_headroom = KAL_FALSE;

    IPC_ASSERT(pkt);
    IPC_ASSERT(head_gpd);
    IPC_ASSERT(tail_gpd);

    if (NULL == pkt) {
        return KAL_FALSE;
    }

    if (KAL_TRUE == pkt->isGPD) {

        hif_data_trace(IPC_GE_HANDLE_GPD, 0, pkt->head, pkt->tail);

        /* For GPD TX : Set GPD pointer */
        *head_gpd = pkt->head;
        *tail_gpd = pkt->tail;

        /* Per-discussion with user (IMS), caller does NOT reserve IP/UDP header fields in GPD, and IP Core needs to fill them using headroom */
        fill_in_headroom = KAL_TRUE;
    } else {
        /* For Buffer TX : Allocate single GPD and execute memory copy */
        kal_uint32      ip_header_len;
        kal_uint32      udp_header_len;
        kal_uint32      total_len;
        kal_uint8       *ip_header;

        /* Check total packet length */
        if (hdr) {
            /* Reserve for IP/UDP header fields if needed */
            ip_header_len = ((IPC_IP_TYPE_IPV4 == hdr->ip_type) ? IPC_HDR_V4_HEADER_SIZE : IPC_HDR_V6_HEADER_SIZE);
            udp_header_len = IPC_HDR_UDP_HEADER_SIZE;
        } else {
            ip_header_len = 0;
            udp_header_len = 0;
        }

        total_len = ip_header_len + udp_header_len + pkt->data_len;

        hif_data_trace(IPC_GE_SET_ALLOC_DATA, pkt->data_len, pkt->data, ip_header_len, udp_header_len);

        if (total_len > ((KAL_TRUE == uplink)?((kal_uint32)QBM_SIZE_NET_UL_SHRD):((kal_uint32)QBM_SIZE_HIF_DL)))
        {
            hif_trace_error(IPC_TR_PACK_PKT_UDP_SIZE_NG, 
                    uplink, ip_header_len, udp_header_len, pkt->data_len, ((KAL_TRUE == uplink)?QBM_SIZE_NET_UL_SHRD:QBM_SIZE_HIF_DL));
            return KAL_FALSE;
        }

        /* Allocate single GPD */
        if (1 != qbmt_alloc_q_no_tail(
                        (KAL_TRUE == uplink)?QBM_TYPE_NET_UL_SHRD/*UL*/:QBM_TYPE_HIF_DL/*DL*/, /* type */
                        1, /* buff_num */
                        (void**)head_gpd, /* pp_head */
                        (void**)tail_gpd)) { /* pp_tail */
            hif_trace_error(IPC_TR_PACK_PKT_ALLOC_GPD_NG, total_len);
            return KAL_FALSE;
        }

        ipc_set_gpd_datalen(*head_gpd, total_len, (void**)&ip_header);

        /* IP/UDP header has reserved in payload field, no more headroom is needed in following header fill */
        fill_in_headroom = KAL_FALSE;

        /* Memory copy from data buffer to GPD */
        kal_mem_cpy(ip_header + (ip_header_len + udp_header_len), pkt->data, pkt->data_len);

        QBM_CACHE_FLUSH(ip_header + (ip_header_len + udp_header_len), pkt->data_len);

    }

    /* Fill header */
    if (hdr) {
        qbm_gpd     *curr_gpd;
        kal_bool    end_of_gpd_list = KAL_FALSE;

        /* Trace GPD list to configure UDP/IP headers one-by-one */
        for (   curr_gpd = *head_gpd;
                curr_gpd && (KAL_FALSE == end_of_gpd_list);
                curr_gpd = (qbm_gpd *)QBM_DES_GET_NEXT(curr_gpd)) {

            /* Fill IP/UDP header */
            static kal_uint32   ip_v4_local_id_s = 0;
            kal_uint16          sum16;
            kal_uint32          ip_header_len;
            kal_uint32          udp_header_len;
            kal_uint32          total_len;
            kal_uint8           *ip_header;
            kal_uint8           *udp_header;

            ip_header_len = ((IPC_IP_TYPE_IPV4 == hdr->ip_type) ? IPC_HDR_V4_HEADER_SIZE : IPC_HDR_V6_HEADER_SIZE);
            udp_header_len = IPC_HDR_UDP_HEADER_SIZE;

            /* Push and get IP/UDP header pointers */
            if (KAL_TRUE == fill_in_headroom) {
                ipc_push_qbm_datahead(curr_gpd, ip_header_len + udp_header_len, &total_len, (void**)&ip_header);
            } else {
                ipc_get_qbm_datahead(curr_gpd, &total_len, (void**)&ip_header);
            }

            if (ip_header)
            {
                udp_header = ip_header + ip_header_len;

                hif_data_trace(IPC_GE_FILL_HEADER, total_len, curr_gpd, ip_header_len, udp_header_len);

                IPC_ASSERT(total_len >= (ip_header_len + udp_header_len));

                /* Fill UDP header */
                IPC_HDR_UDP_SET_SRC_PORT(udp_header, hdr->src_port);
                IPC_HDR_UDP_SET_DST_PORT(udp_header, hdr->dst_port);
                IPC_HDR_UDP_SET_LENGTH(udp_header, total_len - ip_header_len/* UDP length */);
                IPC_HDR_UDP_SET_CHECKSUM(udp_header, 0);
                sum16 = ipc_calc_udp_checksum(  (IPC_IP_TYPE_IPV4 == hdr->ip_type)?KAL_TRUE:KAL_FALSE,
                                                hdr->src_addr,
                                                hdr->dst_addr,
                                                udp_header,
                                                total_len - ip_header_len/* UDP length */);
                IPC_HDR_UDP_SET_CHECKSUM(udp_header, sum16);

                if (IPC_IP_TYPE_IPV4 == hdr->ip_type) {
                    IPC_HDR_V4_RESET_VER_IHL_DSCP_ECN(ip_header);
                    IPC_HDR_V4_SET_DSCP(ip_header, hdr->dscp_tc);
                    IPC_HDR_V4_SET_TOTAL_LENGTH(ip_header, total_len);
                    IPC_HDR_V4_SET_IDENTITY(ip_header, ip_v4_local_id_s);
                    ip_v4_local_id_s++;
                    IPC_HDR_V4_SET_FLAGS(ip_header, 0);
                    IPC_HDR_V4_SET_FRAG_OFFSET(ip_header, 0);
                    IPC_HDR_V4_SET_TTL(ip_header, IPC_DEF_TTL);
                    IPC_HDR_V4_SET_PROTOCOL(ip_header, IPC_HDR_PROT_UDP);
                    IPC_HDR_V4_SET_HEADER_CHECKSUM(ip_header, 0);
                    IPC_HDR_V4_SET_SRC_ADDR(ip_header, hdr->src_addr);
                    IPC_HDR_V4_SET_DST_ADDR(ip_header, hdr->dst_addr);
                    sum16 = ipc_calc_ipv4_checksum(ip_header);
                    IPC_HDR_V4_SET_HEADER_CHECKSUM(ip_header, sum16);
                } else {
                    IPC_HDR_V6_RESET_VER_TC_FL(ip_header);
                    IPC_HDR_V6_SET_TC(ip_header, hdr->dscp_tc);
                    IPC_HDR_V6_SET_LENGTH(ip_header, total_len - ip_header_len/* UDP length */);
                    IPC_HDR_V6_SET_NH_TYPE(ip_header, IPC_HDR_PROT_UDP);
                    IPC_HDR_V6_SET_HOP_LIMIT(ip_header, IPC_DEF_TTL);
                    IPC_HDR_V6_SET_SRC_ADDR(ip_header, hdr->src_addr);
                    IPC_HDR_V6_SET_DST_ADDR(ip_header, hdr->dst_addr);
                }

                QBM_CACHE_FLUSH(ip_header, total_len);
            } else
            {
                hif_trace_error(IPC_TR_PACK_PKT_SKIP_INVALID_GPD, curr_gpd, QBM_DES_GET_DATALEN(curr_gpd));
            }

            /* Check if current GPD is last one or not */
            end_of_gpd_list = (curr_gpd == (*tail_gpd))?KAL_TRUE:KAL_FALSE;
        }
    }

    return KAL_TRUE;
}

kal_bool 
ipc_send_ul_pkt (
    ipc_pkt_t   *pkt,
    ipc_hdr_t   *hdr,
    kal_uint8   ebi)
{
    qbm_gpd *head_gpd;
    qbm_gpd *tail_gpd;

    IPC_ASSERT(pkt);

    if (KAL_FALSE == ipc_pack_pkt(  KAL_TRUE,
                                    pkt,
                                    hdr,
                                    &head_gpd,
                                    &tail_gpd))
    {
        hif_trace_error(IPC_TR_UL_PKT_PKT_PACK_FAILED, pkt->isGPD, hdr);
        return KAL_FALSE;
    }

    hif_data_trace(IPC_UL_SEND_PKT, ebi, head_gpd, tail_gpd);

    /* Sent to UPCM */
    IPC_FORWARD_UL_SDU_BY_EBI(ebi, head_gpd, tail_gpd);

    return KAL_TRUE;
}

kal_bool
ipc_send_ul_pkt_by_pdn (
    ipc_pkt_t   *pkt,
    ipc_hdr_t   *hdr,
    kal_uint8   pdn,
    kal_uint8   ip_type)
{
    qbm_gpd *head_gpd;
    qbm_gpd *tail_gpd;

    IPC_ASSERT(pkt);
    IPC_ASSERT( (ip_type == IPC_IP_TYPE_IPV4) || (ip_type == IPC_IP_TYPE_IPV6) );

    if (KAL_FALSE == ipc_pack_pkt(  KAL_TRUE,
                                    pkt,
                                    hdr,
                                    &head_gpd,
                                    &tail_gpd))
    {
        hif_trace_error(IPC_TR_UL_PKT_PKT_PACK_FAILED, pkt->isGPD, hdr);
        return KAL_FALSE;
    }

    hif_data_trace(IPC_UL_SEND_PKT_BY_PDN, pdn, ip_type, head_gpd, tail_gpd);

    /* Sent to UPCM */
    IPC_FORWARD_UL_SDU(ip_type, pdn, head_gpd, tail_gpd);

    return KAL_TRUE;
}

kal_bool
ipc_send_dl_pkt(
    ipc_pkt_t   *pkt,
    ipc_hdr_t   *hdr,
    kal_uint32  netif_id)
{
    ipc_netif_t *netif;
    qbm_gpd     *head_gpd;
    qbm_gpd     *tail_gpd;
    qbm_gpd     *ipv4_first_gpd;
    qbm_gpd     *ipv4_last_gpd;
    qbm_gpd     *ipv6_first_gpd;
    qbm_gpd     *ipv6_last_gpd;

    IPC_ASSERT(pkt);

    /* Packet and Clarify IPv4/IPv6 GPDs */
    if (KAL_FALSE == ipc_pack_pkt(  KAL_FALSE,
                                    pkt,
                                    hdr,
                                    &head_gpd,
                                    &tail_gpd))
    {
        hif_trace_error(IPC_TR_DL_PKT_PKT_PACK_FAILED, pkt->isGPD, hdr);

        if (KAL_TRUE == pkt->isGPD)
        {
            qbmt_dest_q(pkt->head, pkt->tail);
        }

        return KAL_FALSE;
    }

    ipc_clarify_gpd(    head_gpd,
                        tail_gpd,
                        &ipv4_first_gpd,
                        &ipv4_last_gpd,
                        &ipv6_first_gpd,
                        &ipv6_last_gpd);

    netif = ipc_find_netif(netif_id);
    if (netif)
    {
        ipc_io_request_t *ior;

        hif_data_trace(IPC_DL_SEND_IPV4_PKT, 0, netif->config.netif_id, ipv4_first_gpd, ipv4_last_gpd);

        /* Sent to corresponding network interface */
        if (ipv4_first_gpd)
        {
            ior = (ipc_io_request_t *)QBM_DES_GET_SW_CTRL_FIELD(ipv4_first_gpd);
            ior->next_request = NULL;
            ior->first_gpd = ipv4_first_gpd;
            ior->last_gpd = ipv4_last_gpd;
            ior->ip_type = IPC_IP_TYPE_IPV4;
            ior->qos_priority = 0;
        
            netif->config.ipc_dlink_callback_t(
                netif->config.callback_context,
                ior);
        }

        hif_data_trace(IPC_DL_SEND_IPV6_PKT, 0, netif->config.netif_id, ipv6_first_gpd, ipv6_last_gpd);

        if (ipv6_first_gpd)
        {
            ior = (ipc_io_request_t *)QBM_DES_GET_SW_CTRL_FIELD(ipv6_first_gpd);
            ior->next_request = NULL;
            ior->first_gpd = ipv6_first_gpd;
            ior->last_gpd = ipv6_last_gpd;
            ior->ip_type = IPC_IP_TYPE_IPV6;
            ior->qos_priority = 0;
        
            netif->config.ipc_dlink_callback_t(
                netif->config.callback_context,
                ior);
        }

        IPC_R_UNLOCK_OBJECT(netif);
        return KAL_TRUE;
    }

    hif_trace_error(IPC_TR_DL_PKT_NETIF_NOT_FOUND, netif_id);
    IPC_UT_ASSERT(KAL_FALSE, IPC_UT_DL_PKT_NETIF_NOT_FOUND);

    if (ipv4_first_gpd)
    {
        qbmt_dest_q(ipv4_first_gpd, ipv4_last_gpd);
    }
    if (ipv6_first_gpd)
    {
        qbmt_dest_q(ipv6_first_gpd, ipv6_last_gpd);
    }

    /* Network interface is not found */
    return KAL_FALSE;

}

kal_int32 ipc_register_ntfy(
    ipc_ntfy_callback_t callback_func,
    void                *callback_context){
    kal_int32 ntfy_id;

    hif_trace_info(IPC_TR_REG_NTFY_BEGIN, callback_func, callback_context);
    ntfy_id = ipc_new_ntfy(callback_func, callback_context);
    hif_trace_info(IPC_TR_REG_NTFY_END, ntfy_id);

    return ntfy_id;
}

void ipc_deregister_ntfy(kal_int32 ntfy_id){

    hif_trace_info(IPC_TR_DEREG_NTFY_BEGIN, ntfy_id);
    ipc_del_ntfy(ntfy_id);
    hif_trace_info(IPC_TR_DEREG_NTFY_END, ntfy_id);
}

kal_bool ipc_register_link_up_ind_handler(module_type module_id)
{
    hif_trace_info(IPC_TR_REG_LINK_UP_IND_HDLR_BEGIN, module_id);
    ipc_update_link_up_ind_handler(module_id);
    hif_trace_info(IPC_TR_REG_LINK_UP_IND_HDLR_END, module_id);
    return KAL_TRUE;
}

void ipc_deregister_link_up_ind_handler(void)
{
    hif_trace_info(IPC_TR_DEREG_LINK_UP_IND_HDLR_BEGIN);
    ipc_update_link_up_ind_handler(MOD_IPCORE);
    hif_trace_info(IPC_TR_DEREG_LINK_UP_IND_HDLR_END);
}

kal_bool ipc_register_ip_up_ind_handler(module_type module_id)
{
    hif_trace_info(IPC_TR_REG_IP_UP_IND_HDLR_BEGIN, module_id);
    ipc_update_ip_up_ind_handler(module_id);
    hif_trace_info(IPC_TR_REG_IP_UP_IND_HDLR_END, module_id);
    return KAL_TRUE;
}

void ipc_deregister_ip_up_ind_handler(void)
{
    hif_trace_info(IPC_TR_DEREG_IP_UP_IND_HDLR_BEGIN);
    ipc_update_ip_up_ind_handler(MOD_IPCORE);
    hif_trace_info(IPC_TR_DEREG_IP_UP_IND_HDLR_END);
}

void ipc_set_ul_throttle(local_para_struct *local_para_ptr)
{
    ipc_set_ul_throttle_param_t *param = (ipc_set_ul_throttle_param_t *)local_para_ptr;
    ipc_ul_throttle_conf_t *conf = (ipc_ul_throttle_conf_t *)(&(param->conf));
    kal_uint32              mask;
    kal_bool                to_send_msg;

    hif_trace_info(IPC_TR_SET_UL_THROTTLE_BEGIN, ipc_ul_throttle_state_s, conf->enabled, conf->active_period_100ms, conf->suspend_period_100ms);

    // Cancel original timer.
    if (NULL != ipc_eid_ul_throttle_s) {
        ipc_ul_throttle_conf_s.enabled = KAL_FALSE;
        evshed_cancel_event(ipc_es_ul_throttle_s, &ipc_eid_ul_throttle_s);
        ipc_eid_ul_throttle_s = NULL;
    }

    if (conf->enabled) {
        /* Enable IPC UL throttle. */
        IPC_ASSERT(conf->active_period_100ms && conf->suspend_period_100ms);

        kal_mem_cpy(&ipc_ul_throttle_conf_s, conf, sizeof(ipc_ul_throttle_conf_t));
        /* Check if its the SUSPEND-FOREVER mode. (active:suspend = 1:255) */
        if ( (1 == ipc_ul_throttle_conf_s.active_period_100ms) &&
             (255 == ipc_ul_throttle_conf_s.suspend_period_100ms) ) {
            /* It's SUSPEND-FOREVER mode */
            ipc_ul_throttle_state_s = IPC_UL_THROTTLE_STATE_SUSPEND;
        } else {
            // Start new timer.
            ipc_start_ul_throttle_timer(ipc_ul_throttle_conf_s.active_period_100ms * KAL_TICKS_100_MSEC);
            ipc_ul_throttle_state_s = IPC_UL_THROTTLE_STATE_ACTIVE;
        }
    } else {
        /* Disable IPC UL throttle. */
        kal_mem_set(&ipc_ul_throttle_conf_s, 0, sizeof(ipc_ul_throttle_conf_t));

        ipc_ul_throttle_state_s = IPC_UL_THROTTLE_STATE_NONE;

        /*
         * IPCORE need to process ul queue if ul pending queue is not empty
         */
        mask = SaveAndSetIRQMask();
        to_send_msg = (!ipc_ul_processing_s && ipc_ul_pending_ior_head_s);
        if (to_send_msg) {
            ipc_ul_processing_s = KAL_TRUE;
        }
        RestoreIRQMask(mask);

        /*
         * Switch to IPCORE context.
         */
        if (to_send_msg) {
            msg_send6(MOD_NIL, /* src_mod_id */
                      MOD_IPCORE, /* dest_mod_id */
                      IPCORE_SAP, /* sap_id */
                      MSG_ID_IPCORE_PROCESS_UL_QUEUE_REQ, /* msg_id */
                      NULL, /* local_para_ptr */
                      NULL); /* peer_buff_ptr */
        }
    }
    hif_trace_info(IPC_TR_SET_UL_THROTTLE_END, ipc_ul_throttle_state_s, ipc_ul_throttle_conf_s.enabled, ipc_ul_throttle_conf_s.active_period_100ms, ipc_ul_throttle_conf_s.suspend_period_100ms);

    /* For EM ELT update info*/
    ipc_em_send_ul_throttle_status();
}

void ipc_ul_throttle_sysmsgsvc_cbk(kal_uint32 ap_param)
{
    ipc_set_ul_throttle_param_t *local_para_ptr;
    ipc_ul_throttle_conf_t *conf;

    local_para_ptr = (ipc_set_ul_throttle_param_t *)construct_local_para(sizeof(ipc_set_ul_throttle_param_t), TD_RESET);
    IPC_ASSERT(local_para_ptr);

    conf = &(local_para_ptr->conf);
    kal_mem_cpy(conf, &ap_param, sizeof(ipc_ul_throttle_conf_t));

    msg_send6(MOD_NIL, /* src_mod_id */
              MOD_IPCORE, /* dest_mod_id */
              IPCORE_SAP, /* sap_id */
              MSG_ID_IPCORE_SET_UL_THROTTLE, /* msg_id */
              (struct local_para_struct *)local_para_ptr, /* local_para_ptr */
              NULL); /* peer_buff_ptr */

    hif_trace_info(IPC_TR_UL_THROTTLE_SYSMSGSRV_CBK, ipc_ul_throttle_state_s, conf->enabled, conf->active_period_100ms, conf->suspend_period_100ms);
}
