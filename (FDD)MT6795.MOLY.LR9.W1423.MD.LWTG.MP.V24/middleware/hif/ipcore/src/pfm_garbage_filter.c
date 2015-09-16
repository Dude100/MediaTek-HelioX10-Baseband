/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2014
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
 *   pfm_garbage_filter.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Packet Filter Manager customed functions for feature: Garbage Filter.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "qmu_bm.h"
#include "qmu_bm_util.h"
#include "ipc_api.h"
#include "ipc_enums.h"
#include "ipc_filter_priority.h"

#include "ipc_debug.h"

#include "pfm_defs.h"
#include "pfm_enums.h"


#define PFM_GARBAGE_FILTER_MAX_FILTER   128

extern kal_uint16 ipc_calc_tcp_checksum(kal_bool is_ipv4, kal_uint8 *src_addr, kal_uint8 *dst_addr, kal_uint8 *tcp_header, kal_uint32 tcp_len);
extern kal_uint16 ipc_calc_ipv4_checksum(kal_uint8 *ip_header);

/*------------------------------------------------------------------------------
 * Private data structure.
 *----------------------------------------------------------------------------*/
typedef struct _pfm_garbage_filter_t {
    kal_int32   filter_id;
    kal_uint8   ip_type;
    kal_uint8   protocol;
    kal_uint16  dst_port;
    kal_uint32  magic_code;
} pfm_garbage_filter_t;

/*------------------------------------------------------------------------------
 * Private variables.
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 * Private fucntions.
 *----------------------------------------------------------------------------*/

/*!
 * Callback function with packet information to process the IP datagram filtered.
 * Reply TCP RST packet to the sender of the garbage TCP SYN packet.
 *
 * @param   info_p [IN] Related information of filtered out GPDs.
 * @param   context [IN] A context specified while registering the filter.
 * @param   filter_id [IN] Corresponding registered filter ID.
 * @param   head_gpd [IN] Pointer head of the GPD list for the IP datagram filtered.
 * @param   tail_gpd [IN] Pointer tail of the GPD list for the IP datagram filtered.
 * @param   length [IN] Bytes of buffers used in the GPD list.
 */
void pfm_ipc_dl_filter_with_info_cb(
    ipc_filter_info_t      *info_p,
    void                   *context,
    kal_int32               filter_id,
    qbm_gpd                *head_gpd,
    qbm_gpd                *tail_gpd,
    kal_uint32              length)
{
    ipc_pkt_t       ipc_pkt;
    qbm_gpd        *ul_gpd;
    qbm_gpd        *bd;
    kal_uint8      *p_data;
    kal_uint8       next_header;
    kal_uint8      *p_packet;
    kal_uint8      *src_addr;
    kal_uint8      *dst_addr;
    kal_uint8      *p_tcp_header;
    kal_uint32      ip_header_len;
    kal_bool        is_ipv4;

    if (QBM_DES_GET_BDP(head_gpd)) {
        bd = QBM_DES_GET_DATAPTR(head_gpd);
        p_packet = QBM_DES_GET_DATAPTR(bd);
    } else {
        p_packet = QBM_DES_GET_DATAPTR(head_gpd);
    }

    if (IPC_HDR_IS_V4(p_packet)) {
        is_ipv4 = KAL_TRUE;

        if (IPC_HDR_PROT_TCP != IPC_HDR_V4_GET_PROTOCOL(p_packet)) {
            /* Only For TCP packet */
            goto free_gpd;
        }

        /* Send IPv4 TCP RST */
        ip_header_len = (kal_uint32)IPC_HDR_V4_GET_IHL(p_packet);
        p_tcp_header = p_packet + ip_header_len;

        src_addr = IPC_HDR_V4_GET_DST_ADDR(p_packet);
        dst_addr = IPC_HDR_V4_GET_SRC_ADDR(p_packet);
    } else if (IPC_HDR_IS_V6(p_packet)) {
        is_ipv4 = KAL_FALSE;

        /* Check if it's TCP or not */
        ip_header_len = IPC_HDR_V6_HEADER_SIZE; // fix
        next_header = IPC_HDR_V6_GET_NH_TYPE(p_packet);
        p_tcp_header = p_packet + ip_header_len;
        while (1) {
            if ((next_header == IPC_HDR_PROT_IPV6_HOP) ||
                (next_header == IPC_HDR_PROT_IPV6_ROUTE) ||
                (next_header == IPC_HDR_PROT_IPV6_DEST)) {

                // next header
                next_header = IPC_NE_GET_1B(p_tcp_header);
                // move pointer to next ext header
                p_tcp_header += (IPC_NE_GET_1B(p_tcp_header + 1) + 1)*8;
            } else if (next_header == IPC_HDR_PROT_AH) {

                // next header
                next_header = IPC_NE_GET_1B(p_tcp_header);
                // move pointer to next ext header
                p_tcp_header += (IPC_NE_GET_1B(p_tcp_header + 1) + 2)*4;
            } else if (next_header == IPC_HDR_PROT_TCP) {
                /* Found TCP header ! */
                break;
            } else {
                goto free_gpd;
            }
        }

        src_addr = IPC_HDR_V6_GET_DST_ADDR(p_packet);
        dst_addr = IPC_HDR_V6_GET_SRC_ADDR(p_packet);
    } else {
        goto free_gpd;
    }

    /* Allocate a UL GPD */
    ul_gpd = QBM_ALLOC_ONE(QBM_TYPE_HIF_UL_TYPE);
    if (!ul_gpd) {
        PFM_ASSERT(KAL_FALSE);
    }

    bd = QBM_DES_GET_DATAPTR(ul_gpd);
    p_data = QBM_DES_GET_DATAPTR(bd);

    /* Fill IP/TCP header */
    {
        kal_uint16          sum16;
        kal_uint32          tcp_header_len;
        kal_uint32          total_len;
        kal_uint8           *ip_header;     // ip_header for output packet
        kal_uint8           *tcp_header;    // tcp_header for output packet

        ip_header_len = ((is_ipv4) ? IPC_HDR_V4_HEADER_SIZE : IPC_HDR_V6_HEADER_SIZE);
        tcp_header_len = IPC_HDR_TCP_HEADER_SIZE;
        total_len = ip_header_len + tcp_header_len;

        ip_header = p_data;
        tcp_header = ip_header + ip_header_len;

        /* Fill TCP header */
        IPC_HDR_TCP_SET_SRC_PORT(tcp_header, IPC_HDR_TCP_GET_DST_PORT(p_tcp_header));
        IPC_HDR_TCP_SET_DST_PORT(tcp_header, IPC_HDR_TCP_GET_SRC_PORT(p_tcp_header));
        IPC_HDR_TCP_SET_SEQ_NUM(tcp_header, IPC_HDR_TCP_GET_ACK_NUM(p_tcp_header));
        IPC_HDR_TCP_SET_ACK_NUM(tcp_header, IPC_HDR_TCP_GET_SEQ_NUM(p_tcp_header) + 1);
        IPC_HDR_TCP_SET_OFFSET(tcp_header, IPC_HDR_TCP_HEADER_SIZE);
        IPC_HDR_TCP_SET_RESERVED(tcp_header, 0);
        IPC_HDR_TCP_SET_FLAGS(tcp_header, IPC_HDR_TCP_FLAG_RST | IPC_HDR_TCP_FLAG_ACK);
        IPC_HDR_TCP_SET_WINDOW(tcp_header, 0);
        IPC_HDR_TCP_SET_CHECKSUM(tcp_header, 0);
        IPC_HDR_TCP_SET_URGENT_PTR(tcp_header, 0);
        sum16 = ipc_calc_tcp_checksum(  is_ipv4,
                                        src_addr,
                                        dst_addr,
                                        tcp_header,
                                        tcp_header_len);
        IPC_HDR_TCP_SET_CHECKSUM(tcp_header, sum16);

        if (is_ipv4) {
            IPC_HDR_V4_RESET_VER_IHL_DSCP_ECN(ip_header);
            IPC_HDR_V4_SET_DSCP(ip_header, IPC_HDR_V4_GET_DSCP(p_packet));
            IPC_HDR_V4_SET_TOTAL_LENGTH(ip_header, total_len);
            IPC_HDR_V4_SET_IDENTITY(ip_header, 0);
            IPC_HDR_V4_SET_FLAGS(ip_header, 0);
            IPC_HDR_V4_SET_FRAG_OFFSET(ip_header, 0);
            IPC_HDR_V4_SET_TTL(ip_header, IPC_DEF_TTL);
            IPC_HDR_V4_SET_PROTOCOL(ip_header, IPC_HDR_PROT_TCP);
            IPC_HDR_V4_SET_HEADER_CHECKSUM(ip_header, 0);
            IPC_HDR_V4_SET_SRC_ADDR(ip_header, src_addr);
            IPC_HDR_V4_SET_DST_ADDR(ip_header, dst_addr);
            sum16 = ipc_calc_ipv4_checksum(ip_header);
            IPC_HDR_V4_SET_HEADER_CHECKSUM(ip_header, sum16);
        } else {
            IPC_HDR_V6_RESET_VER_TC_FL(ip_header);
            IPC_HDR_V6_SET_TC(ip_header, IPC_HDR_V6_GET_TC(p_packet));
            IPC_HDR_V6_SET_LENGTH(ip_header, total_len - ip_header_len/* TCP length */);
            IPC_HDR_V6_SET_NH_TYPE(ip_header, IPC_HDR_PROT_TCP);
            IPC_HDR_V6_SET_HOP_LIMIT(ip_header, IPC_DEF_TTL);
            IPC_HDR_V6_SET_SRC_ADDR(ip_header, src_addr);
            IPC_HDR_V6_SET_DST_ADDR(ip_header, dst_addr);
        }

        QBM_CACHE_FLUSH(ip_header, total_len);

        QBM_DES_SET_DATALEN(bd, total_len);
        qbm_cal_set_checksum(bd);

        QBM_DES_SET_DATALEN(ul_gpd, total_len);
        qbm_cal_set_checksum(ul_gpd);
    }

    kal_mem_set(&ipc_pkt, 0, sizeof(ipc_pkt));
    ipc_pkt.isGPD = KAL_TRUE;
    ipc_pkt.head = ul_gpd;
    ipc_pkt.tail = ul_gpd;
    ipc_send_ul_pkt(&ipc_pkt, NULL, info_p->ebi);

    hif_trace_info(PFM_TR_GARBAGE_FILTER_REPLY_RST, 0, IPC_HDR_TCP_GET_DST_PORT(p_tcp_header));

free_gpd:
    pfm_drop_packet_trace(info_p->ebi, p_packet, PFM_DROP_PACKET_DUMP_SIZE);
    qbmt_dest_q(head_gpd, tail_gpd);
}

void pfm_garbage_filter_register_parser(void *buf, kal_uint32 filter_cnt, kal_bool uplink)
{
    kal_uint32              idx;
    pfm_garbage_filter_t   *raw_filters = (pfm_garbage_filter_t *)buf;
    ipc_filter_rules_t      rules;

    for (idx = 0; idx < filter_cnt; idx++) {
        kal_mem_set(&rules, 0, sizeof(rules));

        if (PFM_FILTER_STRUCT_MAGIC_CODE != raw_filters[idx].magic_code) {
            hif_trace_error(PFM_TR_GARBAGE_FILTER_WRONG_MAGIC_CODE, idx);
            return;
        }

        hif_trace_info(PFM_TR_GARBAGE_FILTER_REG_PARSER, raw_filters[idx].filter_id,
                                                         raw_filters[idx].ip_type,
                                                         raw_filters[idx].protocol,
                                                         raw_filters[idx].dst_port);

        rules.features = IPC_FILTER_FEATURE_BWM;
        rules.priority = raw_filters[idx].filter_id + IPC_DL_FILTER_PRIORITY_PFM_GARBAGE_FILTER_BEGIN;
        rules.valid_fields = IPC_FILTER_BY_PROTOCOL | IPC_FILTER_BY_DST_PORT;
        rules.ip_type = raw_filters[idx].ip_type;
        rules.protocol = raw_filters[idx].protocol;
        rules.dst_port = raw_filters[idx].dst_port;

        if (PFM_GARBAGE_FILTER_MAX_FILTER < raw_filters[idx].filter_id) {
            hif_trace_error(PFM_TR_GARBAGE_FILTER_INVALID_FILTER_ID);
            PFM_ASSERT(KAL_FALSE);
        } else {
            pfm_register_filter_cbk(PFM_GARBAGE_FILTER_SET_ID,
                                    raw_filters[idx].filter_id,
                                    KAL_FALSE,
                                    &rules,
                                    NULL,
                                    NULL);
        }
    }

    kal_mem_set(&rules, 0, sizeof(rules));
    rules.features = IPC_FILTER_FEATURE_WC;
    rules.priority = IPC_DL_FILTER_PRIORITY_PFM_GARBAGE_FILTER_WC;
    pfm_register_filter_with_info_cbk(PFM_GARBAGE_FILTER_SET_ID,
                                      PFM_GARBAGE_FILTER_MAX_FILTER,
                                      KAL_FALSE,
                                      &rules,
                                      pfm_ipc_dl_filter_with_info_cb,
                                      NULL);
}

void pfm_garbage_filter_deregister_callback(kal_int32 filter_id)
{
    /* Do nothing */
    return;
}
