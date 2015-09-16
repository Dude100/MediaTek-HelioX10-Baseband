/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   ccmni_it.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Implements the CCCI CCMNI IT functions
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * [K2 MD2] Add CCCI/CCIF new feature for K2 MD2
 *
 * removed!
 * removed!
 * [CCCI] Change the source of sending ilm from MOD_NIL to right source due to need to reduce system trace log
 *
 * removed!
 * removed!
 * [ccmni] split HIF UL QBM pool
 *
 * 05 10 2013 ap.wang
 * removed!
 * [CCCI_CCMNI] Modify Gen DL BW and IT reload retry
 *
 * 04 11 2013 ap.wang
 * removed!
 * [CCMNI_IT] Modify DL gen GPD mechanism
 *
 * 03 27 2013 ap.wang
 * removed!
 *
 * 03 18 2013 ap.wang
 * removed!
 *
 * 02 05 2013 ap.wang
 * removed!
 *
 * 01 29 2013 ap.wang
 * removed!
 * [CCMNI_IT] Modify RGPD reload method
 *
 * 01 24 2013 ap.wang
 * removed!
 * [CCMNI] Modify DHL log
 *
 * 01 22 2013 ap.wang
 * removed!
 * .
 *
 * removed!
 * removed!
 * [ROUTER] fix link error when SDIO_SUPPORT  is not enabled
 *
 * 01 11 2013 ap.wang
 * removed!
 * [CCCI_IT_CTRL] CCCI_IT_CTRL 1st version.
 *
 * removed!
 * removed!
 * [CCMNI] fixed link error in CCCI_LB_IT
 *
 * removed!
 * removed!
 * sync latest version of new features
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#if (defined(__CCMNI_LB_IT__) || defined(__CCMNI_IT__))
#include "ccmni_common.h"
#include "ipcore_iph.h"
#include "ipcore_icmph.h"
#include "ipcore_udph.h"
#include "ipc_api.h"
#include "qmu_bm.h"
#include "ccmni_qbm.h"
#include "ccmni_sm.h"
#include "ccci_if.h"
#include "mw_sap.h"
#include <stdlib.h>
#include <ctype.h>

#ifdef __HIF_SDIO_SUPPORT__
#include "sdiocore_if.h"
#endif
//#include "SST_sla.h"  //CCDL
//typedef void (*ccmni_dl_func)(void* param, hif_io_request_t* ior);

#define CCMNI_IT_DL_GPD_TYPE QBM_TYPE_HIF_DL
#define NET_MPU 1472

extern kal_bool ccmni_reload_ul_gpds(void *context);
kal_uint32 ccmni_pkt_gen_target_bw;
kal_uint32 ccmni_pkt_gen_pkt_sz;
kal_uint32 ccmni_pkt_gen_target_ch;

static INLINE void _ccmni_it_flush_qbm_data_all(void* gpd)
{
    void* bd = NULL;
    void* data_ptr = NULL;
    kal_uint32 data_len = 0;

    ASSERT(QBM_DES_GET_BDP(gpd) != 0);

    bd = QBM_DES_GET_DATAPTR(gpd);
    do {
        data_ptr = QBM_DES_GET_DATAPTR(bd);
        data_len = QBM_DES_GET_DATALEN(bd);
        QBM_CACHE_FLUSH(data_ptr, data_len);
        if ( QBM_DES_GET_EOL(bd) )
        {
            break;
        }
        bd = QBM_DES_GET_NEXT(bd);
    } while ( bd != NULL );
}

static INLINE void _ccmni_it_set_qbm_dl_datasize(void* gpd, kal_uint32 size)
{
    void* bd = NULL;

    ASSERT(QBM_DES_GET_BDP(gpd) != 0);

    /* set gpd data len */
    QBM_DES_SET_DATALEN(gpd, size);
    /* set gpd checksum */
    //qbm_cal_set_checksum(gpd);

    /* set bd data len */
    bd = QBM_DES_GET_DATAPTR(gpd);
    QBM_DES_SET_DATALEN(bd, size);
    /* set bd checksum */
    //qbm_cal_set_checksum(bd);
}
extern kal_bool ccmni_ipc_dl(void* context, ipc_io_request_t* ior);
kal_bool ccmni_it_ip4_ping(qbm_gpd* gpd, void* context)
{
    ccmni_device_t                  *pDevice = context;
    kal_bool result                 = KAL_TRUE;
    ipc_ip4_header_t* pIp           = (ipc_ip4_header_t*)CCMNI_GET_QBM_DATAPTR(gpd);
    ipc_icmp_echo_header_t* pIcmp   = NULL;
    kal_uint16 total_length         = IPC_HTONS(pIp->ip_len);
    kal_uint32 offset               = 0;
    ipc_ip4_header_t* ip4_reply     = NULL;
    ipc_icmp_echo_header_t* icmp_reply = NULL;
    kal_uint32 ip4_total_len        = 0;
    qbm_gpd* tx_gpd                 = NULL;
    static kal_uint32 ip4_identifier = 0;
    ipc_ip4_addr_t ori_src_ip_tmp; //for ip swap

    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_IT, CCMNI_TR_IT_PING_TRACE);
    ipc_find_ipv4_data_header(pIp, &offset);
    pIcmp = (ipc_icmp_echo_header_t*)((kal_uint8*)pIp + offset);
    offset += sizeof(ipc_icmp_header_t);

    do {
        /* Not ICMP Echo Request Packet */
        if ( pIcmp->icmp_type != IPC_ICMP_ECHO_REQUEST )
        {
            break;
        }

        /* Not Code Zero */
        if ( pIcmp->icmp_code != 0 )
        {
            break;
        }

        tx_gpd = gpd;

        if(0 == (ip4_identifier % 10)){
            ccmni_trace(CCMNI_INFO, CCMNI_MOD_IT, CCMNI_TR_IT_ICMP_SEQ, pDevice->dev_id, ip4_identifier);
        }
        
        ip4_reply = (ipc_ip4_header_t*)CCMNI_GET_QBM_DATAPTR(tx_gpd);
        ip4_reply->ip_ver   = IPC_IP4_VERSION;
        ip4_reply->ip_hl    = 5;
        ip4_reply->ip_tos   = 0;
        ip4_reply->ip_len   = 0;    // fill later
        ip4_reply->ip_id    = IPC_NTOHS(ip4_identifier); ip4_identifier++;
        ip4_reply->ip_off   = pIp->ip_off;
        ip4_reply->ip_ttl   = 128;
        ip4_reply->ip_pro   = IPC_IPPROTO_ICMP;
        ip4_reply->ip_sum   = 0;    // calculate later

        /* swap ip */
        kal_mem_cpy(&ori_src_ip_tmp, &pIp->ip_src, sizeof(ipc_ip4_addr_t));
        kal_mem_cpy(&ip4_reply->ip_src, &pIp->ip_dst, sizeof(ipc_ip4_addr_t));
        kal_mem_cpy(&ip4_reply->ip_dst, &ori_src_ip_tmp, sizeof(ipc_ip4_addr_t));
        
        ip4_total_len      += sizeof(ipc_ip4_header_t);

        icmp_reply = (ipc_icmp_echo_header_t*)((kal_uint8*)ip4_reply + ip4_total_len);
        icmp_reply->icmp_type   = IPC_ICMP_ECHO_REPLY;
        icmp_reply->icmp_code   = 0;
        icmp_reply->icmp_cksum  = 0;    //fill later
        icmp_reply->icmp_id     = pIcmp->icmp_id;
        icmp_reply->icmp_seq    = pIcmp->icmp_seq;
        ip4_total_len          += sizeof(ipc_icmp_echo_header_t);

        /* copy icmp echo data */
        {
            void* src_bd        = NULL;
            kal_uint8* src_data = NULL;
            kal_uint32 src_len  = 0;
            void* dst_bd        = NULL;
            kal_uint8* dst_data = NULL;
            kal_int32 to_copy_len = total_length - ip4_total_len;

            src_bd      = QBM_DES_GET_DATAPTR(gpd);
            src_data    = QBM_DES_GET_DATAPTR(src_bd);
            src_len     = QBM_DES_GET_DATALEN(src_bd);
            src_data   += ip4_total_len;
            src_len    -= ip4_total_len;

            dst_bd      = QBM_DES_GET_DATAPTR(tx_gpd);
            dst_data    = QBM_DES_GET_DATAPTR(dst_bd);
            dst_data   += ip4_total_len;

            while ( to_copy_len > 0 )
            {
                if ( to_copy_len > src_len )
                {
                    kal_mem_cpy(dst_data, src_data, src_len);
                    ip4_total_len += src_len;
                    to_copy_len    -= src_len;
                    dst_data       += src_len;
                    if ( QBM_DES_GET_EOL(src_bd) )
                    {
                        break;
                    }
                    src_bd          = QBM_DES_GET_NEXT(src_bd);
                    src_data        = QBM_DES_GET_DATAPTR(src_bd);
                    src_len         = QBM_DES_GET_DATALEN(src_bd);
                } else {
                    kal_mem_cpy(dst_data, src_data, to_copy_len);
                    ip4_total_len += to_copy_len;
                    to_copy_len     = 0;
                }
            }
        }

        /* calculate IP checksum */
        ip4_reply->ip_len = IPC_NTOHS(ip4_total_len);
        ip4_reply->ip_sum = IPC_NTOHS((ipc_ip4_cksum(ip4_reply, sizeof(ipc_ip4_header_t))));

        /* calculate ICMP checksum */
        icmp_reply->icmp_cksum = IPC_NTOHS((ipc_icmp_cksum((ipc_icmp_header_t*)icmp_reply, (ip4_total_len-sizeof(ipc_ip4_header_t)))));

        /* call send out func() */
        _ccmni_it_set_qbm_dl_datasize(tx_gpd, ip4_total_len);
        _ccmni_it_flush_qbm_data_all(tx_gpd);

    } while (0);
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_IT, CCMNI_TR_IT_PING_PASS_TRACE);
    return result;
}   

static void ccmni_lb_cp_ior(ccmni_device_t* pDevice, ccci_io_request_t* p_ul_ior, ccci_io_request_t* p_dl_ior)
{  
    ccci_io_request_t    *p_curr_ul_ior;
    qbm_gpd             *p_curr_src_gpd, *p_curr_dest_gpd;
    kal_char            *p_src_data_buf, *p_dest_data_buf;
    qbm_gpd             *first_gpd, *last_gpd;
    
    p_curr_ul_ior = p_ul_ior;
    p_curr_dest_gpd = p_dl_ior->first_gpd;
    do {
        ccci_io_request_t* p_next_ul_ior = p_curr_ul_ior->next_request;
        
        // kal_mem_cpy();
        first_gpd = p_curr_ul_ior->first_gpd;
        last_gpd = p_curr_ul_ior->last_gpd;
        ASSERT(first_gpd && last_gpd);
        p_curr_src_gpd = p_curr_ul_ior->first_gpd;
        do {
            ASSERT(NULL != p_curr_dest_gpd);
            p_src_data_buf = CCMNI_GET_QBM_DATAPTR(p_curr_src_gpd);
            p_dest_data_buf = CCMNI_GET_QBM_DATAPTR(p_curr_dest_gpd);
            
            kal_mem_cpy((void *)p_dest_data_buf, (void *)p_src_data_buf, CCMNI_GET_QBM_DATALEN(p_curr_src_gpd));
        
            if ( p_curr_src_gpd == last_gpd )
            {
                break;
            }
            p_curr_src_gpd = QBM_DES_GET_NEXT(p_curr_src_gpd);
            p_curr_dest_gpd = QBM_DES_GET_NEXT(p_curr_dest_gpd); 
        } while ( p_curr_src_gpd != NULL );

        p_curr_ul_ior = p_next_ul_ior;
    } while ( p_curr_ul_ior != NULL );
}

/*!
 * @function        ccmni_ul2dl_loopback
 * @brief           looback api for CCCI IT
 *
 * @param ul_ior    [IN] uplink io_request function, might be casted from ipc_io_request_t
 * @param dl_func   [IN] pointer to the downlink function, ccmni_ipc_dl
 * @param context   [IN] ccmni device context, passed to dl_func later
 *
 * @return          void
 */
void ccmni_ul2dl_loopback(ccci_io_request_t *p_ul_ior, void* context){
//	    ccmni_device_t      *pDevice = context;
//	    ccci_io_request_t    *ccmni_ior_curr;
//	    kal_uint32          gpd_num = 0;
//	    kal_uint32          to_alloc;
//	    kal_uint32          num_alloc;
//	    ccci_io_request_t    dl_ior;
//	    
//	    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_IT, CCMNI_TR_IT_LB, pDevice->dev_id);
//	    ASSERT(NULL!=p_ul_ior);
//	    
//	    ccmni_ior_curr = (ccci_io_request_t*)p_ul_ior;
//	    do {
//	        ccci_io_request_t* next_ior = ccmni_ior_curr->next_request;
//	        gpd_num += CCMNI_GET_GPD_LIST_SIZE(ccmni_ior_curr->first_gpd, ccmni_ior_curr->last_gpd);
//	        ccmni_ior_curr = next_ior;
//	    } while ( ccmni_ior_curr != NULL );
//	    ccmni_trace(CCMNI_INFO, CCMNI_MOD_IT, CCMNI_TR_IT_RGPD_CNT,pDevice->dev_id, gpd_num);
//	
//	    to_alloc = gpd_num;
//	    num_alloc = qbmt_alloc_q_no_tail(
//	                   QBM_TYPE_CCCI_COMM,               /* type */
//	                   to_alloc,                         /* buff_num */
//	                   (void **)(&dl_ior.first_gpd),    /* pp_head */
//	                   (void **)(&dl_ior.last_gpd));    /* pp_tail */
//	    ASSERT(num_alloc == to_alloc);
//	    
//	    dl_ior.next_request = NULL;
//	    ccmni_lb_cp_ior(pDevice, p_ul_ior, &dl_ior);
    ccmni_ipc_dl(context, (ipc_io_request_t*) &p_ul_ior);

//	    ccci_dest_ior(p_ul_ior);
    
    ccmni_reload_ul_gpds(context);
    return;
}

//extern void sdioc_gpd_leak_dbg();
kal_bool ccmni_it_udp_process_gpd(qbm_gpd* gpd, void* context)
{
    ccmni_device_t *pDevice         = context;
    kal_bool result                 = KAL_TRUE;
    ipc_ip4_header_t* pIp           = (ipc_ip4_header_t*)CCMNI_GET_QBM_DATAPTR(gpd);
//	    ipc_udp_header_t* pUdp          = NULL;
    ipc_ip4_header_t ip4_reply;
//    ipc_ip4_addr_t ip4_dst;
//    kal_uint16 udp_port_tmp         = 0;
//	    kal_uint32 ip4_total_len        = 0;
    kal_uint32 offset               = 0;
    qbm_gpd* tx_gpd                 = NULL;

    ipc_find_ipv4_data_header(pIp, &offset);
//	    pUdp = (ipc_udp_header_t*)((kal_uint8*)pIp + offset);

    do {
        
        /* Reuse RGPD as TGPD, freed while hif_set_gpd*/
        tx_gpd = gpd;

        if(0 == (IPC_NTOHS(pIp->ip_id) % 10))
        {
            kal_uint32 temp = qbm_get_buff_remain_num(QBM_TYPE_TGPD_BPS);
            ccmni_trace(CCMNI_INFO, CCMNI_MOD_IT, CCMNI_TR_IT_UDP_SEQ, pDevice->dev_id, IPC_NTOHS(pIp->ip_id));
            ccmni_trace(CCMNI_INFO, CCMNI_MOD_IT, CCMNI_TR_IT_UDP_SEQ, temp, temp);
            //sdioc_gpd_leak_dbg();
        }
        
        ip4_reply.ip_ver   = IPC_IP4_VERSION;
        ip4_reply.ip_hl    = 5;
        ip4_reply.ip_tos   = 0;
        ip4_reply.ip_len   = 0;    // fill later
        ip4_reply.ip_id    = pIp->ip_id;
        ip4_reply.ip_off   = pIp->ip_off;
        ip4_reply.ip_ttl   = pIp->ip_ttl;
        ip4_reply.ip_pro   = IPC_IPPROTO_UDP;
        ip4_reply.ip_sum   = 0;    // calculate later
        kal_mem_cpy(&ip4_reply.ip_src, &pIp->ip_dst, sizeof(ipc_ip4_addr_t));
        kal_mem_cpy(&ip4_reply.ip_dst, &pIp->ip_src, sizeof(ipc_ip4_addr_t));
//	        ip4_total_len = IPC_NTOHS(pIp->ip_len);
        /* calculate IP checksum */
        ip4_reply.ip_len = pIp->ip_len;
        ip4_reply.ip_sum = IPC_NTOHS((ipc_ip4_cksum(&ip4_reply, sizeof(ipc_ip4_header_t))));
        kal_mem_cpy(pIp, &ip4_reply, sizeof(ipc_ip4_header_t));

#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        _ccmni_it_flush_qbm_data_all(tx_gpd);

    } while (0);

    return result;
}   

void ccmni_it_udp_icmp_loopback(ccci_io_request_t *p_ul_ior, void* context){
    static kal_uint32   cons_skip_num_bps = 0;
    ccmni_device_t      *pDevice = context;
    ccci_io_request_t    *p_curr_ul_ior;
    qbm_gpd             *p_curr_src_gpd;
    qbm_gpd             *p_next_src_gpd;
    qbm_gpd             *first_gpd, *last_gpd;
    kal_uint32          gpd_num = 0;
    kal_uint32          bps_gpd_num = 0;
    
    qbm_gpd             *gpd_free_h = NULL; 
    qbm_gpd             *gpd_free_t = NULL;
    qbm_gpd             *gpd_dl_h   = NULL; 
    qbm_gpd             *gpd_dl_t   = NULL;
    kal_uint32          nbpsgpd     = 0;

    ccci_io_request_t    tx_ior;

    if (pDevice->it_mode == CCMNI_IT_UDP_LB){
        ccmni_trace(CCMNI_TRACE, CCMNI_MOD_IT, CCMNI_TR_IT_UDP, pDevice->dev_id);
    }
    else if(pDevice->it_mode == CCMNI_IT_PING){
        ccmni_trace(CCMNI_TRACE, CCMNI_MOD_IT, CCMNI_TR_IT_PING, pDevice->dev_id);
    }

    ASSERT(NULL!=p_ul_ior);
#if 1
    nbpsgpd = qbm_get_buff_remain_num(QBM_TYPE_TGPD_BPS);
    if(0 == nbpsgpd){
        ccci_dest_ior(p_ul_ior);
        if(0 == (++cons_skip_num_bps % 10)){
            /* print out the debug message every 10 times */
            ccmni_trace(CCMNI_WARN, CCMNI_MOD_IT, CCMNI_TR_PG_NO_BPS, cons_skip_num_bps);
        }
        pDevice->dev_reload_retry = ccmni_reload_ul_gpds(context);
        return;
    }else{
        cons_skip_num_bps = 0;
    }
#endif
    
    p_curr_ul_ior = p_ul_ior;
    do {
        ccci_io_request_t* p_next_ul_ior = p_curr_ul_ior->next_request;
        
        first_gpd = p_curr_ul_ior->first_gpd;
        last_gpd = p_curr_ul_ior->last_gpd;
        ASSERT(first_gpd && last_gpd);
        p_curr_src_gpd = p_curr_ul_ior->first_gpd;
        do {

            pDevice->dev_reload_retry = ccmni_reload_ul_gpds(context);
            p_next_src_gpd = QBM_DES_GET_NEXT(p_curr_src_gpd);
            /* 20120905 there should not have BPS GPD in CCMNI UL data path */
            ASSERT(!QBM_DES_GET_BPS(p_curr_src_gpd));    
        if (pDevice->it_mode == CCMNI_IT_UDP_LB){
            ccmni_it_udp_process_gpd(p_curr_src_gpd, context);
        }
        else if(pDevice->it_mode == CCMNI_IT_PING){
            ccmni_it_ip4_ping(p_curr_src_gpd, context);
        }
        else{
            /* CCMNI_IT_MODE definition error */
            /* ccmni_it_udp_icmp_loopback only handles CCMNI_PING_IT and CCMNI_IT_UDP_LB*/
            ASSERT(0);
        }
         
            CCCIDEV_QBM_ENQ(p_curr_src_gpd, p_curr_src_gpd, (void**)&gpd_dl_h, (void**)&gpd_dl_t);
            gpd_num++;

            if ( p_curr_src_gpd == last_gpd )
            {
                break;
            }
            p_curr_src_gpd = p_next_src_gpd;

        } while ( p_curr_src_gpd != NULL );

        p_curr_ul_ior = p_next_ul_ior;
    } while ( p_curr_ul_ior != NULL );

    if(NULL!=gpd_free_h){
        qbmt_dest_q(gpd_free_h, gpd_free_t);
    }

    if(NULL != gpd_dl_h){
        tx_ior.next_request    = NULL;
        tx_ior.first_gpd       = gpd_dl_h;
        tx_ior.last_gpd        = gpd_dl_t;    
        QBM_DES_SET_NEXT(gpd_dl_t, NULL);
        ccmni_ipc_dl(pDevice, (ipc_io_request_t*) &tx_ior);

        ccmni_trace(CCMNI_TRACE, CCMNI_MOD_IT, CCMNI_TR_IT_RGPD_CNT,pDevice->dev_id, gpd_num, bps_gpd_num);    
    }
    return;
}


/*!
 * @function        _ccmni_it_format_ipudp_h
 * @brief           This function generate UDP packet for iperf server
 *
 * @param p_iph      [IN] ip packet header
 * @param emcsni_port[IN] connect to which emcsni port, current mapping emcsni0: 0, emcsni1: 1, emcsni2: 2
 *
 * @return          void
 */
void _ccmni_it_format_ipudp_h(ipc_ip4_header_t *pIp, kal_uint8 emcsni_port){
    static kal_uint8  ipv4_header[IPC_HDR_V4_HEADER_SIZE] = {
            0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x80, 0xff, 0x00, 0x00, 
            0xC0, 0xA8, 0x00, 0x17,   //192.168.0.23 src
            0xC0, 0xA8, 0x00, 0x01 }; //192.168.0.2   dst

    static kal_uint32 ip_seq_num = 0;
    kal_uint32 offset            = 0;
    ipc_udp_header_t *pUdp;

    kal_mem_cpy(pIp, &ipv4_header, sizeof(ipv4_header));

    pIp->ip_id    = IPC_NTOHS(ip_seq_num);
    ip_seq_num ++ ;
    pIp->ip_pro   = IPC_IPPROTO_UDP;
    pIp->ip_sum   = 0;    // calculate later
    pIp->ip_src._u4_addr._u4_addr8[2] = emcsni_port;
    pIp->ip_dst._u4_addr._u4_addr8[2] = emcsni_port;

    ipc_find_ipv4_data_header(pIp, &offset);
    pUdp = (ipc_udp_header_t*)((kal_uint8*)pIp + offset);

    pUdp->udp_src_port = IPC_NTOHS(56984);
    pUdp->udp_dst_port = IPC_NTOHS(5001);
    pUdp->udp_len      = 0; //fill up later
    pUdp->udp_sum      = 0; //fill up later
    return;
}

/*!
 * @function        ccmni_udp_pkt_gen_bw
 * @brief           This function generate UDP packet for iperf server
 *
 * @param target_bw  [IN] UDP packet target BW in Mbps (150~1)
 * @param payload_len[IN] UDP packet payload length in Bytes (0~NET_MPU) 
 * @param emcsni_port[IN] connect to which emcsni port, current mapping emcsni0: 0, emcsni1: 1, emcsni2: 2
 *
 * @return          void
 */
#define _LTE_TICK  20  //ms     /* Assume this function will be called every LTE tick, by enough UL packets */
void ccmni_udp_pkt_gen_bw(kal_uint32 target_bw, kal_uint32 payload_len,kal_uint8 emcsni_port){

    static kal_uint32 cons_skip_num_bps = 0;
    static kal_uint32 cons_skip_num_tgpd = 0;
    kal_uint32 ntgpd, nbpsgpd;
    kal_uint32 to_alloc, num_alloc;
    kal_uint32 offset               = 0;
    kal_uint32 ip4_total_len        = 0;
    ccmni_inst_t        *p_ccmni    = ccmni_get_instance();
    ccmni_device_t      *pDevice    = &p_ccmni->dev[emcsni_port];
    qbm_gpd *first_gpd              = NULL;
    qbm_gpd *last_gpd               = NULL;
    qbm_gpd *p_curr_gpd             = NULL;
    ipc_ip4_header_t *pIp           = NULL;
    ipc_udp_header_t *pUdp          = NULL;
    ipc_io_request_t *tx_ior        = NULL;
    
    if(CCMNI_DEV_CONNECTED != pDevice->state){
        return;
    }

    if(800 < target_bw || 1 > target_bw){
        ccmni_trace(CCMNI_ERR, CCMNI_MOD_IT, CCMNI_TR_PG_BW_ERR, target_bw);
        target_bw = 800;
    }

    if(NET_MPU < payload_len){
        ccmni_trace(CCMNI_ERR, CCMNI_MOD_IT, CCMNI_TR_PG_LEN_ERR, payload_len);
        payload_len = NET_MPU;
    }

    //4 <1> check if there's at least one BPS_GPD
    nbpsgpd = qbm_get_buff_remain_num(QBM_TYPE_TGPD_BPS);
    if(0 == nbpsgpd){
        if(0 == (++cons_skip_num_bps % 10)){
            /* print out the debug message every 10 times */
            ccmni_trace(CCMNI_WARN, CCMNI_MOD_IT, CCMNI_TR_PG_NO_BPS, cons_skip_num_bps);
        }
        return;
    }else{
        cons_skip_num_bps = 0;
    }

    //4 <2> Calculate the TGPD number. QBM_TYPE_NET_DL.
    ntgpd =((target_bw*1024*1024) / (payload_len*8) ) / (1000/_LTE_TICK);

    if(0 == ntgpd){
        ccmni_trace(CCMNI_WARN, CCMNI_MOD_IT, CCMNI_TR_PG_NOT_ENOUG_BW, 0, (payload_len*8*1000/1024/1024));
        ntgpd = 1;
    }


    to_alloc = ntgpd;
    if (to_alloc >= qbm_get_buff_remain_num(CCMNI_IT_DL_GPD_TYPE)){
        to_alloc = qbm_get_buff_remain_num(CCMNI_IT_DL_GPD_TYPE) - 5;
        if (to_alloc <= 0){
            to_alloc = 1;
        }
    }
    num_alloc = qbmt_alloc_q_no_tail(
                   CCMNI_IT_DL_GPD_TYPE,          /* type */
                   to_alloc,                 /* buff_num */
                   (void **)(&first_gpd),    /* pp_head */
                   (void **)(&last_gpd));    /* pp_tail */

    if(0 == num_alloc){
        if(0 == (++cons_skip_num_tgpd % 10)){
            /* print out the debug message every 10 times */
            ccmni_trace(CCMNI_WARN, CCMNI_MOD_IT, CCMNI_TR_PG_NO_TGPD, cons_skip_num_tgpd);
        }
        return;
    }else{
        cons_skip_num_tgpd = 0;
    }

    if(to_alloc!=num_alloc){
        /* cannot send enough TGPD in this run */
        ccmni_trace(CCMNI_WARN, CCMNI_MOD_IT, CCMNI_TR_PG_NOT_ENOUG_TGPD, to_alloc, num_alloc);
    }

    ASSERT(NULL!=first_gpd);
    ASSERT(NULL!=last_gpd);

    QBM_DES_SET_NEXT(last_gpd, NULL);
    p_curr_gpd = first_gpd;
    /* Format Tx IO request */
    tx_ior = (ipc_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(first_gpd);
    tx_ior->first_gpd    = first_gpd;
    tx_ior->last_gpd     = last_gpd;
    tx_ior->next_request = NULL;
    ip4_total_len = payload_len + sizeof(ipc_ip4_header_t)+ sizeof(ipc_udp_header_t);

    //4 <3> Format each TGPD as a ip packet
    do{
        pIp = (ipc_ip4_header_t*)CCMNI_GET_QBM_DATAPTR(p_curr_gpd);

        /* set up IP/UDP header */
        _ccmni_it_format_ipudp_h(pIp, emcsni_port);

        ipc_find_ipv4_data_header(pIp, &offset);
        pUdp = (ipc_udp_header_t*)((kal_uint8*)pIp + offset);

        /* Don't care about the packet content */

        /* calculate IP checksum */
        pIp->ip_len = IPC_NTOHS(ip4_total_len);
        pIp->ip_sum = IPC_NTOHS((ipc_ip4_cksum(pIp, sizeof(ipc_ip4_header_t))));

        /* disable UPD checksum */
        pUdp->udp_len = IPC_NTOHS((ip4_total_len - sizeof(ipc_ip4_header_t)));
        pUdp->udp_sum = 0;
        //pUdp->udp_sum = IPC_NTOHS((ipc_udp_cksum(pUdp, (ip4_total_len - sizeof(ipc_ip4_header_t)), &pIp->ip_src, &pIp->ip_dst)));

        /* set up gpd/bd info & flush*/
        _ccmni_it_set_qbm_dl_datasize(p_curr_gpd, ip4_total_len);
        _ccmni_it_flush_qbm_data_all(p_curr_gpd);
        
        p_curr_gpd = QBM_DES_GET_NEXT(p_curr_gpd);
    } while ( p_curr_gpd != NULL );

    ccmni_ipc_dl(pDevice, (ipc_io_request_t*) tx_ior);
    
}
//extern int fake_print(const char *fmt, ...); //CCDL
/*!
 * @function        ccmni_udp_pkt_gen_acnt
 * @brief           This function generate UDP packet for iperf server by aggregation count
 *
 * @param target_acnt[IN] UDP packet target aggregated count
 * @param payload_len[IN] UDP packet payload length in Bytes (0~NET_MPU) 
 * @param emcsni_port[IN] connect to which emcsni port, current mapping emcsni0: 0, emcsni1: 1, emcsni2: 2
 *
 * @return          void
 */
void ccmni_udp_pkt_gen_acnt(kal_uint32 target_acnt, kal_uint32 payload_len,kal_uint8 emcsni_port){

    static kal_uint32 cons_skip_num_bps = 0;
    static kal_uint32 cons_skip_num_tgpd = 0;
    kal_uint32 ntgpd, nbpsgpd;
    kal_uint32 to_alloc, num_alloc;
    kal_uint32 offset               = 0;
    kal_uint32 ip4_total_len        = 0;
    ccmni_inst_t        *p_ccmni    = ccmni_get_instance();
    ccmni_device_t      *pDevice    = &p_ccmni->dev[emcsni_port];
    qbm_gpd *first_gpd              = NULL;
    qbm_gpd *last_gpd               = NULL;
    qbm_gpd *p_curr_gpd             = NULL;
    ipc_ip4_header_t *pIp           = NULL;
    ipc_udp_header_t *pUdp          = NULL;
    ipc_io_request_t *tx_ior        = NULL;

    if(CCMNI_DEV_CONNECTED != pDevice->state){
        return;
    }
    
    if(NET_MPU < payload_len){
        ccmni_trace(CCMNI_ERR, CCMNI_MOD_IT, CCMNI_TR_PG_LEN_ERR, payload_len);
        payload_len = NET_MPU;
    }

    //4 <1> check if there's at least one BPS_GPD
    nbpsgpd = qbm_get_buff_remain_num(QBM_TYPE_TGPD_BPS);
    if(0 == nbpsgpd){
        if(0 == (++cons_skip_num_bps % 10)){
            /* print out the debug message every 10 times */
            ccmni_trace(CCMNI_WARN, CCMNI_MOD_IT, CCMNI_TR_PG_NO_BPS, cons_skip_num_bps);
        }
        return;
    }else{
        cons_skip_num_bps = 0;
    }

    //4 <2> Calculate the TGPD number. QBM_TYPE_NET_DL.
    ntgpd = target_acnt;

    if(0 == ntgpd){
        ccmni_trace(CCMNI_WARN, CCMNI_MOD_IT, CCMNI_TR_PG_NOT_ENOUG_BW, 0, (payload_len*8*1000/1024/1024));
        ntgpd = 1;
    }

    to_alloc = ntgpd;
    num_alloc = qbmt_alloc_q_no_tail(
                   CCMNI_IT_DL_GPD_TYPE,          /* type */
                   to_alloc,                 /* buff_num */
                   (void **)(&first_gpd),    /* pp_head */
                   (void **)(&last_gpd));    /* pp_tail */

    if(0 == num_alloc){
        if(0 == (++cons_skip_num_tgpd % 10)){
            /* print out the debug message every 10 times */
            ccmni_trace(CCMNI_WARN, CCMNI_MOD_IT, CCMNI_TR_PG_NO_TGPD, cons_skip_num_tgpd);
        }
        return;
    }else{
        cons_skip_num_tgpd = 0;
    }

    if(to_alloc!=num_alloc){
        /* cannot send enough TGPD in this run */
        ccmni_trace(CCMNI_WARN, CCMNI_MOD_IT, CCMNI_TR_PG_NOT_ENOUG_TGPD, to_alloc, num_alloc);
        /* won't send if GPD is not enough */
        qbmt_dest_q(first_gpd, last_gpd);
        return;
    }

    ASSERT(NULL!=first_gpd);
    ASSERT(NULL!=last_gpd);

    QBM_DES_SET_NEXT(last_gpd, NULL);
    p_curr_gpd = first_gpd;
    /* Format Tx IO request */
    tx_ior = (ipc_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(first_gpd);
    tx_ior->first_gpd    = first_gpd;
    tx_ior->last_gpd     = last_gpd;
    tx_ior->next_request = NULL;
    ip4_total_len = payload_len + sizeof(ipc_ip4_header_t)+ sizeof(ipc_udp_header_t);

    //4 <3> Format each TGPD as a ip packet
    do{
        pIp = (ipc_ip4_header_t*)CCMNI_GET_QBM_DATAPTR(p_curr_gpd);

        /* set up IP/UDP header */
        _ccmni_it_format_ipudp_h(pIp, emcsni_port);

        ipc_find_ipv4_data_header(pIp, &offset);
        pUdp = (ipc_udp_header_t*)((kal_uint8*)pIp + offset);

        /* Don't care about the packet content */

        /* calculate IP checksum */
        pIp->ip_len = IPC_NTOHS(ip4_total_len);
        pIp->ip_sum = IPC_NTOHS((ipc_ip4_cksum(pIp, sizeof(ipc_ip4_header_t))));

        /* disable UPD checksum */
        pUdp->udp_len = IPC_NTOHS((ip4_total_len - sizeof(ipc_ip4_header_t)));
        pUdp->udp_sum = 0;
        //pUdp->udp_sum = IPC_NTOHS((ipc_udp_cksum(pUdp, (ip4_total_len - sizeof(ipc_ip4_header_t)), &pIp->ip_src, &pIp->ip_dst)));

        /* set up gpd/bd info & flush*/
        _ccmni_it_set_qbm_dl_datasize(p_curr_gpd, ip4_total_len);
        _ccmni_it_flush_qbm_data_all(p_curr_gpd);
        
        p_curr_gpd = QBM_DES_GET_NEXT(p_curr_gpd);
    } while ( p_curr_gpd != NULL );
    
    ccmni_ipc_dl(pDevice, (ipc_io_request_t*) tx_ior); //disable this for CCDL

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

}

void ccmni_udp_pkt_gen_bw_cb()
{
    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    ccmni_device_t      *pDevice;
    kal_uint32          idx;

    for(idx = 0; idx < CCMNI_DEV_CNT; idx ++){
        pDevice = &p_ccmni->dev[idx];
        if(pDevice->it_mode == CCMNI_IT_DL_ONLY){
            ccmni_udp_pkt_gen_bw(ccmni_pkt_gen_target_bw, ccmni_pkt_gen_pkt_sz, idx);
        }
    }   
    return;
}

#define CCMNI_IT_GPTIMER_PRIODIC_INTERVAL 1	// 10ms 
static volatile kal_uint8 mode_switching = 0; //use for CCMNI IT mode switch : ccmni_process_mode_switch
static kal_bool ccmni_it_gpt_timer_enable = KAL_FALSE ;
static DCL_HANDLE ccmni_it_gpt_handle = 0 ;

static void ccmni_it_gpt_timer_cb(){
    SGPT_CTRL_START_T re_schedule;

	if (ccmni_it_gpt_timer_enable == KAL_TRUE ){
		re_schedule.u4Tick=CCMNI_IT_GPTIMER_PRIODIC_INTERVAL ;
		re_schedule.pfCallback=ccmni_it_gpt_timer_cb;
		re_schedule.vPara=NULL;

	    DclSGPT_Control(ccmni_it_gpt_handle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&re_schedule) ;
   	}
}

static void ccmni_it_gpt_timer_init()
{
    
    SGPT_CTRL_START_T start;

	start.u4Tick=CCMNI_IT_GPTIMER_PRIODIC_INTERVAL;
	start.pfCallback=ccmni_it_gpt_timer_cb;
	start.vPara=NULL;
    ccmni_it_gpt_timer_enable = KAL_FALSE;
    if (ccmni_it_gpt_handle == 0) {
		ccmni_it_gpt_handle = DclSGPT_Open(DCL_GPT_CB, FLAGS_NONE);
		
		if (ccmni_it_gpt_handle == DCL_HANDLE_INVALID || ccmni_it_gpt_handle == DCL_HANDLE_OCCUPIED){
			ASSERT(0);
		}
	}
    DclSGPT_Control(ccmni_it_gpt_handle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start) ;
}

kal_bool ccmni_reload_retry = KAL_FALSE;
void ccmni_it_reload_rgpds(){
    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    ccmni_device_t      *pDevice;
    kal_uint32          idx;
    kal_uint32          mask;

//	    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_IT, CCMNI_TR_IT_RL_TRACE);
    for(idx = 0; idx < CCMNI_DEV_CNT; idx ++){
        pDevice = &p_ccmni->dev[idx];
        if((KAL_TRUE == pDevice->dev_reload_retry) && (ccmni_reload_retry == KAL_FALSE)){
            CCMNI_DEV_LOCK(mask);
            ccmni_reload_retry = KAL_TRUE;
            CCMNI_DEV_UNLOCK(mask);
            msg_send6(MOD_CCMNI,   /* src_mod_id */
                      MOD_CCMNI, /* dest_mod_id */
                      CCMNI_SAP, /* sap_id */
                      MSG_ID_CCMNI_RETRY_UL_RELOAD_REQ, /* msg_id */
                      NULL,  /* local_para_ptr */
                      NULL); /* peer_buff_ptr */
        }
        if ((pDevice->it_mode == CCMNI_IT_DROP_UL) && mode_switching != 0){
        CCMNI_DEV_LOCK(mask);
        mode_switching--;
        CCMNI_DEV_UNLOCK(mask);
        }

    }
//	    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_IT, CCMNI_TR_IT_RL_PASS_TRACE);
}

/*!
 * @function        ccmni_process_mode_switch
 * @brief           This function process AT command IT mode switch request,
 *                  need to handle the packets in the path before change mode.
 *
 * @param context[IN] ccmni device context
 * @param mode[IN]    mode to change from AT command renage in ccmni_it_mode
 *
 * @return          0 success
 */
kal_int32 ccmni_process_mode_switch(void *context, kal_uint32  mode){
    ccmni_device_t      *pdev = (ccmni_device_t *)context;
    kal_uint32          mask;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_IT, CCMNI_TR_IT_MS_TRACE);
    /* For gen packet by ccci_it_ctrl */
    if ((pdev->it_mode == CCMNI_IT_DL_ONLY) && (mode == CCMNI_IT_DL_ONLY) ){
        ccmni_udp_pkt_gen_bw(ccmni_pkt_gen_target_bw, ccmni_pkt_gen_pkt_sz, pdev->dev_id);
        return 0;
    }

    
//	    if (pdev->it_mode == CCMNI_IT_DL_ONLY){
//	        ccmni_it_gpt_timer_enable = KAL_FALSE ;
//	    }
    
    CCMNI_DEV_LOCK(mask);
    mode_switching = 10;       //mode_switching value mean sdio poll queue count
    pdev->it_mode = CCMNI_IT_DROP_UL;
    CCMNI_DEV_UNLOCK(mask);
    while (mode_switching > 0){
        pdev->it_mode = CCMNI_IT_DROP_UL;
    }
    pdev->it_mode = mode;
    
//	    if (pdev->it_mode == CCMNI_IT_DL_ONLY){
//	        ccmni_it_gpt_timer_enable = KAL_TRUE ;
//	        ccmni_it_gpt_timer_cb();
//	    }
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_IT, CCMNI_TR_IT_MS_PASS_TRACE);
    return 0;
}

/*!
 * @function        ccmni_it_mode_switch
 * @brief           This function handle AT command IT mode switch request,
 *                  call by ccmni_AT_process in custom_at_command.c
 *                  
 *
 * @param devid[IN]   ccmni device id form AT command
 * @param mode[IN]    mode to change from AT command renage in ccmni_it_mode
 * @param op[IN]      AT command mode - read = 1, set = 2.
 *
 * @return          <0 error, >=0 mode, 
 */

kal_int32 ccmni_it_mode_switch(kal_uint32  devid, kal_uint32  mode, kal_uint32 op){
    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    ccmni_device_t      *pDevice = &p_ccmni->dev[devid-1];
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_IT, CCMNI_TR_IT_AT_INFO, devid, mode, op);
    if (devid - 1 >= CCMNI_DEV_CNT){
        ccmni_trace(CCMNI_ERR, CCMNI_MOD_IT, CCMNI_TR_IT_AT_DEV_ERR, CCMNI_DEV_CNT, devid);
        return CCMNI_IT_DEVID_ERR;
    }
    if (mode >= CCMNI_IT_MODE_MAX){
        ccmni_trace(CCMNI_ERR, CCMNI_MOD_IT, CCMNI_TR_IT_AT_MODE_ERR, CCMNI_IT_MODE_MAX, mode);
        return CCMNI_IT_MODE_ERR;
    }
    switch(op){
        case CCMNI_IT_READ_MODE: //read
            ccmni_trace(CCMNI_TRACE, CCMNI_MOD_IT, CCMNI_TR_IT_AT_OP_READ, devid, pDevice->it_mode); 
            return pDevice->it_mode;
            break;
        case CCMNI_IT_SET_MODE: //set
            ccmni_process_mode_switch((void *)pDevice , mode);
            ccmni_trace(CCMNI_TRACE, CCMNI_MOD_IT, CCMNI_TR_IT_AT_OP_SET, devid, mode);    
            return pDevice->it_mode;
            break;
        default:
            ccmni_trace(CCMNI_ERR, CCMNI_MOD_IT, CCMNI_TR_IT_AT_OP_ERR, devid, op);
            return CCMNI_IT_OP_ERR;
    }
}


#ifdef CCCI_IT_MODE_CONTROL_CCCI_CCMNI
#include "ccci_it_ctrl_if.h"
kal_bool ccmni_it_mode_switch1(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    ccmni_device_t      *pDevice = &p_ccmni->dev[0];
    ccmni_process_mode_switch((void *)pDevice , (kal_uint32)p_param);
    return KAL_TRUE;
}
kal_bool ccmni_it_mode_switch2(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    ccmni_device_t      *pDevice = &p_ccmni->dev[1];    
    ccmni_process_mode_switch((void *)pDevice , (kal_uint32)p_param);
    return KAL_TRUE;
}
kal_bool ccmni_it_mode_switch3(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    ccmni_device_t      *pDevice = &p_ccmni->dev[2];    
    ccmni_process_mode_switch((void *)pDevice , (kal_uint32)p_param);
    return KAL_TRUE;
}

kal_bool ccmni_it_gen_bw_setting(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    if(!isdigit((kal_int32)*(kal_char*)p_param)){
        ccmni_pkt_gen_target_bw = (kal_uint32)p_param;
    }else{
        ccmni_pkt_gen_target_bw = (kal_uint32)atoi((kal_char*)p_param);
    }
    return KAL_TRUE;
}

kal_bool ccmni_it_gen_size_setting(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    if(!isdigit((kal_int32)*(kal_char*)p_param)){
        ccmni_pkt_gen_pkt_sz = (kal_uint32)p_param;
    }else{
        ccmni_pkt_gen_pkt_sz = (kal_uint32)atoi((kal_char*)p_param);
    }
    return KAL_TRUE;
}

IT_MODE_T ccci_ccmni1_it_mode_table[] = {
    {"CCMNI1 Normal Mode",      ccmni_it_mode_switch1, (void*)CCMNI_IT_DISABLE},
    {"CCMNI1 Loopback",         ccmni_it_mode_switch1, (void*)CCMNI_IT_UDP_LB},
    {"CCMNI1 Downlink Mode",    ccmni_it_mode_switch1, (void*)CCMNI_IT_DL_ONLY, 1},
    {"CCMNI1 Uplink Mode",      ccmni_it_mode_switch1, (void*)CCMNI_IT_DROP_UL},
    {"CCMNI1 Ping",             ccmni_it_mode_switch1, (void*)CCMNI_IT_PING},      
};

IT_MODE_T ccci_ccmni2_it_mode_table[] = {
    {"CCMNI2 Normal Mode",      ccmni_it_mode_switch2, (void*)CCMNI_IT_DISABLE},
    {"CCMNI2 Loopback",         ccmni_it_mode_switch2, (void*)CCMNI_IT_UDP_LB},
    {"CCMNI2 Downlink Mode",    ccmni_it_mode_switch2, (void*)CCMNI_IT_DL_ONLY, 1},
    {"CCMNI2 Uplink Mode",      ccmni_it_mode_switch2, (void*)CCMNI_IT_DROP_UL},
    {"CCMNI2 Ping",             ccmni_it_mode_switch2, (void*)CCMNI_IT_PING},  
};

IT_MODE_T ccci_ccmni3_it_mode_table[] = {
    {"CCMNI3 Normal Mode",      ccmni_it_mode_switch3, (void*)CCMNI_IT_DISABLE},
    {"CCMNI3 Loopback",         ccmni_it_mode_switch3, (void*)CCMNI_IT_UDP_LB},
    {"CCMNI3 Downlink Mode",    ccmni_it_mode_switch3, (void*)CCMNI_IT_DL_ONLY, 1},
    {"CCMNI3 Uplink Mode",      ccmni_it_mode_switch3, (void*)CCMNI_IT_DROP_UL},
    {"CCMNI3 Ping",             ccmni_it_mode_switch3, (void*)CCMNI_IT_PING},  
};

IT_MODE_T ccci_ccmni_it_mode_table[] = {
    {"CCMNI Genpacket Bandwidth :  10",     ccmni_it_gen_bw_setting, (void*)8},
    {"CCMNI Genpacket Bandwidth :  20",     ccmni_it_gen_bw_setting, (void*)15},
    {"CCMNI Genpacket Bandwidth :  30",     ccmni_it_gen_bw_setting, (void*)22},
    {"CCMNI Genpacket Bandwidth :  40",     ccmni_it_gen_bw_setting, (void*)30},
    {"CCMNI Genpacket Bandwidth :  50",     ccmni_it_gen_bw_setting, (void*)40},
    {"CCMNI Genpacket Bandwidth : 150",     ccmni_it_gen_bw_setting, (void*)75},
    {"CCMNI Genpacket Size  :   64",     ccmni_it_gen_size_setting, (void*)64},
    {"CCMNI Genpacket Size  :  768",     ccmni_it_gen_size_setting, (void*)768},
    {"CCMNI Genpacket Size  : NET_MPU",     ccmni_it_gen_size_setting, (void*)NET_MPU},
};

kal_bool ccci_ccmni_it_create(){
    ccci_it_mode_control_table_reg("CCCI_CCMNI1", 
                     ccci_ccmni1_it_mode_table, 
                     sizeof(ccci_ccmni1_it_mode_table) / sizeof(IT_MODE_T) 
                    );
    ccci_it_mode_control_table_reg("CCCI_CCMNI2", 
                     ccci_ccmni2_it_mode_table, 
                     sizeof(ccci_ccmni2_it_mode_table) / sizeof(IT_MODE_T) 
                    );
    ccci_it_mode_control_table_reg("CCCI_CCMNI3", 
                     ccci_ccmni3_it_mode_table, 
                     sizeof(ccci_ccmni3_it_mode_table) / sizeof(IT_MODE_T) 
                    );
    ccci_it_mode_control_table_reg("CCCI_CCMNI", 
                     ccci_ccmni_it_mode_table, 
                     sizeof(ccci_ccmni_it_mode_table) / sizeof(IT_MODE_T) 
                    );
    return KAL_TRUE;
}
 
#endif //CCCI_IT_MODE_CONTROL_CCCI_IPC



void ccmni_it_init(){
    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    ccmni_device_t      *pDevice;
    kal_uint32          idx;
    
    ccmni_pkt_gen_target_bw = 150;
    ccmni_pkt_gen_pkt_sz = NET_MPU;
    ccmni_pkt_gen_target_ch = 0;
    //sdioc_reg_reload_rgpd_cb(ccmni_it_reload_rgpds);
    for(idx = 0; idx < CCMNI_DEV_CNT; idx ++){
        pDevice = &p_ccmni->dev[idx];
        pDevice->dev_reload_retry = KAL_FALSE;
        pDevice->it_mode = CCMNI_IT_UDP_LB;
    }
    //sdioc_reg_pkt_gen_cb(ccmni_udp_pkt_gen_bw_cb); //remove by mtk05304
    ccmni_it_gpt_timer_init();

#ifdef CCCI_IT_MODE_CONTROL_CCCI_CCMNI
    ccci_ccmni_it_create();
#endif
    
}

#endif //__CCMNI_LB_IT__
