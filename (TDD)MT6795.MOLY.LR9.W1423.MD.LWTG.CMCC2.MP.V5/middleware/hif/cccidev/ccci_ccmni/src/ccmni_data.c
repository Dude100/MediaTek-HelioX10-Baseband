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
 *   ccmni_data.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Implements the CCCI CCMNI data path functions
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 08 12 2014 aj.tsai
 * removed!
 * 	zero ccci->header__reserved
 *
 * 07 22 2014 aj.tsai
 * removed!
 * 	Merging
 *  	
 * 	//MOLY/BRANCHES_LR9/LR9.W1421.MD.LWTG.MP/mcu/middleware/hif/cccidev/ccci_ccmni/...
 *  	
 * 	to //MOLY/BRANCHES_LR9/LR9.W1423.MD.LWTG.MP/mcu/middleware/hif/cccidev/ccci_ccmni/...
 *
 * 07 10 2014 aj.tsai
 * removed!
 * Add new ccci debug mechanism -CCMNI
 *
 * 06 27 2014 ap.wang
 * removed!
 * Add QBM pool status notify
 *
 * 05 14 2014 ap.wang
 * removed!
 * CCMNI Fast Ack Patch and linkdown fast reload
 *
 * removed!
 * removed!
 * 	[CCMNI ACK Fast Path]
 *
 * 03 21 2014 ap.wang
 * removed!
 * Add CCMNI UL RGPD reload SWLA label
 *
 * 03 21 2014 ap.wang
 * removed!
 * AddUL RGPD reload SWLA label
 *
 * 03 20 2014 ap.wang
 * removed!
 * Add SWLA label for CCMNI MCPS profiling
 *
 * 03 06 2014 ap.wang
 * removed!
 * CCMNI Log reduction
 *
 * 09 06 2013 ap.wang
 * removed!
 *
 * 08 27 2013 ap.wang
 * removed!
 * CCMNI L2 trace
 *
 * removed!
 * removed!
 * [ccmni] split HIF UL QBM pool
 *
 * 08 15 2013 ap.wang
 * removed!
 * [CCMNI] Move CCCI header to BD extension
 *
 * 05 10 2013 ap.wang
 * removed!
 * [CCCI_CCMNI] Modify Gen DL BW and IT reload retry
 *
 * 03 18 2013 ap.wang
 * removed!
 *
 * removed!
 * removed!
 * [CCCI] CCCI/CLDMA INT
 *
 * 02 05 2013 ap.wang
 * removed!
 *
 * removed!
 * removed!
 * sync latest version of new features
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#include "ccmni_common.h"
#include "ccmni_qbm.h"
#include "ccmni_data.h"
#include "ccmni_if.h"
#include "ccmni_sm.h"
#include "cache_sw.h"
#include "hif_swla.h"

//#include "SST_sla.h" /* set HIF_CONSOLE_TRACE_ENABLED = 0*/ //CCDL
#define CCMNI_DUMP_ENABLE (1)
#define CCMNI_DUMP_SIZE (48)
#define _CCMNI_CCCI_SEQ_NO_

#if (CCMNI_DUMP_ENABLE || defined(_CCMNI_CCCI_SEQ_NO_))
static void ccmni_dump_data(void* p_data, kal_uint32 bytes){
    kal_int32 i = 0;
    kal_uint32* p_d = (kal_uint32*)((int)p_data & (~0X3));// 4bytes alignment 
    for (i=0; i*4 < bytes; i=i+4 ){
        //ccmni_trace(CCMNI_TRACE, CCMNI_MOD_DL, CCMNI_DUMP_DATA_4HEX, p_d[i], p_d[i+1], p_d[i+2], p_d[i+3]);
        ccmni_data_trace(CCMNI_DATA_DUMP_TRACE,i*4 , p_d[i], p_d[i+1], p_d[i+2], p_d[i+3]);
    }
}
#endif


/*!
 * @function        [static] ccmni_process_dl_gpd_list
 * @brief           Traverse the input GPD list and insert the CCCI header on the first BD->data 
 *
 * @param pDevice   [IN] pointer to the CCMNI device
 * @param first_gpd [IN] pointer to the first GPD in the GPD chain
 * @param last_gpd  [IN] pointer to the last GPD in the GPD chain
 *
 * @return          number of gpd in between first_gpd and last_gpd
 */
static kal_uint32 ccmni_process_dl_gpd_list(ccmni_device_t* pDevice, qbm_gpd* first_gpd, qbm_gpd* last_gpd)
{  /*process_tx_gpd_list*/
    qbm_gpd*            current_gpd = NULL;
    kal_uint32          pkt_cnt   = 0;
    kal_uint32          byte_cnt  = 0;
    kal_uint32          ccci_h_size;
    CCCI_BUFF_T         *p_ccci_head;
#ifdef _CCMNI_CCCI_SEQ_NO_
    static kal_uint32   seq_no[CCMNI_DEV_CNT] = {0};
#endif

#if CCMNI_SWLA_ENABLE    
    SLA_CustomLogging("NDP", SA_start); 
#endif
    HIF_SWLA_START("CD2");
    ASSERT(first_gpd && last_gpd);
  
    current_gpd = first_gpd;
    ccci_h_size = sizeof(CCCI_BUFF_T);
    ASSERT(ccci_h_size > 0);
    do {
        //4 <1> append CCCI header CCCI_BUFF_T
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else
        /* Store the DL CCCI header in the BD extention part */
        if(0 != QBM_DES_GET_BDP(current_gpd)){
            //<case 1> GPD->BD->BUFF
            void* bd = QBM_DES_GET_DATAPTR(current_gpd);
            QBM_DES_SET_EXTLEN(bd, ccci_h_size);
            p_ccci_head = (CCCI_BUFF_T *)QBM_DES_GET_EXT(bd);
            qbm_cal_set_checksum(bd);
            QBM_CACHE_FLUSH(bd, sizeof(qbm_gpd));
            QBM_DES_SET_DATALEN(current_gpd, CCMNI_GET_QBM_DATALEN(current_gpd)+ccci_h_size);
            CCCI_STREAM_SET_LEN(p_ccci_head, CCMNI_GET_QBM_DATALEN(current_gpd));
            //hifsdioq_set_gpd will set HWO and set checksum
            //qbm_cal_set_checksum(current_gpd);
            //QBM_CACHE_FLUSH(current_gpd, sizeof(qbm_gpd));
        }
        else{
            //<case 2> GPD->BUFF
            QBM_DES_SET_EXTLEN(current_gpd, ccci_h_size);
            p_ccci_head = (CCCI_BUFF_T *)QBM_DES_GET_EXT(current_gpd);
            CCCI_STREAM_SET_LEN(p_ccci_head, CCMNI_GET_QBM_DATALEN(current_gpd)+ccci_h_size);
        }     
        
        #endif
        /*Construct the CCCI header*/
        CCCI_SET_CH_NO(p_ccci_head, pDevice->ccci_ch.ccmni_ch_dl);
        
#ifdef _CCMNI_CCCI_SEQ_NO_
        ccci_debug_add_seq(p_ccci_head, CCCI_DEBUG_NOT_ASSERT_BIT);
//        p_ccci_head->reserved = seq_no[pDevice->dev_id]++;
          p_ccci_head->reserved = 0;
#endif
            
        QBM_CACHE_FLUSH(p_ccci_head, sizeof(CCCI_BUFF_T));
        
#if CCMNI_PFP_ENABLE
    TODO add PFP header
#endif
        pkt_cnt++;
        byte_cnt += QBM_DES_GET_DATALEN(current_gpd);


        { //for ccmni GPD debug 
            void* gpd = current_gpd;
            kal_uint8* pdata = NULL;
            if(0 != QBM_DES_GET_BDP(current_gpd)){
                //<case 1> GPD->BD->BUFF
                gpd  = QBM_DES_GET_DATAPTR(current_gpd);
                if(0 == QBM_DES_GET_EOL(gpd)){
                    gpd = QBM_DES_GET_NEXT(gpd);
                }
            }
            //ccmni_trace(CCMNI_TRACE, CCMNI_MOD_DL, CCMNI_DUMP_GPD_PTR,
            //            current_gpd, QBM_DES_GET_DATAPTR(current_gpd), gpd, QBM_DES_GET_DATAPTR(gpd));
            ccmni_data_trace(CCMNI_DATA_DUMP_GPD_PTR, pDevice->dev_id,
                        current_gpd, QBM_DES_GET_DATAPTR(current_gpd), gpd, QBM_DES_GET_DATAPTR(gpd));
            
#if CCMNI_DUMP_ENABLE   //for ccmni network packet header debug    
            ccmni_dump_data(QBM_DES_GET_DATAPTR(gpd),CCMNI_DUMP_SIZE);
#endif
            pdata = (kal_uint8*) QBM_DES_GET_DATAPTR(gpd);
            //pdata = (kal_uint8*)((int)pdata & (~0X3)); // 4bytes alignment
            ccmni_data_trace(CCMNI_DL_DATA_PACKET_TRACE,pDevice->dev_id, 
                             p_ccci_head->reserved, (pdata[4]<<8|pdata[5]), (pdata[10]<<8|pdata[11]));
        }
        
        if ( current_gpd == last_gpd )
        {
            break;
        }
        current_gpd = QBM_DES_GET_NEXT(current_gpd);

    } while ( current_gpd != NULL );
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_DL, CCMNI_TR_DL_CCCIH_TRACE, pDevice->dev_id, pkt_cnt, p_ccci_head->data[0], p_ccci_head->data[1], p_ccci_head->channel, p_ccci_head->reserved);
#if CCMNI_SWLA_ENABLE    
    SLA_CustomLogging("NDP", SA_stop); 
#endif
    HIF_SWLA_STOP("CD2");
    return pkt_cnt;
}
/*!
 * @function        ccmni_ipc_dl
 * @brief           downlink function for IPcore
 *                  <1> drop the ior if device is not connected
 *                  <2> append the CCCI_HEADER in ccmni_process_dl_gpd_list
 *                  <3> pass the ior to CCCI by ccci_write_gpd
 *
 *                  For USB/RNDIS/ETHCore/IPCore, please refer to ethc_ipc_tx_submit
 *
 * @param context   [IN] pointer to the CCMNI device, ccmni_device_t
 * @param ior       [IN] pointer to the ior
 *
 * @return          KAL_TRUE
 */
kal_bool ccmni_ipc_dl(void* context, ipc_io_request_t* ior){   
    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    ccmni_device_t      *pDevice = context;
    ccci_io_request_t    *ccmni_ior_curr  = NULL;
    kal_bool            ret;
    kal_int32           ccci_ret;
#if CCMNI_SWLA_ENABLE    
    SLA_CustomLogging("NDL", SA_start); 
#endif
    HIF_SWLA_START("CD1");
    if (NULL == ior || NULL == context){
        return KAL_FALSE;
    }

    //4 <1> drop the ior if device is not connected
    //if ( pDevice->state != CCMNI_DEV_CONNECTED ){
    if(!ccmni_dev_connected(pDevice)){
        ccci_dest_ior((ccci_io_request_t*)ior);
        return KAL_TRUE;
    }

    ret = KAL_FALSE;
    ASSERT( ior != NULL );

    ccmni_ior_curr = (ccci_io_request_t*)ior;
    do {
        ccci_io_request_t* next_ior = ccmni_ior_curr->next_request;
        CCMNI_FIX_IOR_NULL_LAST(ccmni_ior_curr);
        //4 <2> append the CCCI_HEADER in ccmni_process_dl_gpd_list
#ifdef __SDIOC_PULL_Q_ENH_DL__
        ccmni_ior_curr->num_gpd = ccmni_process_dl_gpd_list(pDevice, ccmni_ior_curr->first_gpd, ccmni_ior_curr->last_gpd);
#else
        ccmni_process_dl_gpd_list(pDevice, ccmni_ior_curr->first_gpd, ccmni_ior_curr->last_gpd);
#endif
        ccmni_ior_curr = next_ior;
    } while ( ccmni_ior_curr != NULL );

//SLA_CustomLogging("CCDLH", SA_label); //CCDL
    //4 <3> pass the ior to CCCI by ccci_write_gpd
#if CCMNI_SWLA_ENABLE    
    SLA_CustomLogging("NCW", SA_start); 
#endif    
    HIF_SWLA_START("CD3");
    ccci_ret = p_ccmni->ccci_write_gpd(pDevice->ccci_ch.ccmni_ch_dl, (ccci_io_request_t*)ior, NULL);
    HIF_SWLA_STOP("CD3");
#if CCMNI_SWLA_ENABLE    
    SLA_CustomLogging("NCW", SA_stop); 
#endif
    if(CCCI_SUCCESS == ccci_ret){
        ret = KAL_TRUE;
    }
#if CCMNI_SWLA_ENABLE    
    SLA_CustomLogging("NDL", SA_stop); 
#endif
    HIF_SWLA_STOP("CD1");
    return ret;
}

/*!
 * @function        ccmni_ccci_ul_cb
 * @brief           uplink function for CCCI
 *                  <1> update the RGPD count in HIF
 *                  <2> remove CCCI header, CCCI_BUFF_T, by calling CCMNI_RM_CCCI_HEADERS
 *                  <3> callback to IPcore uplink callback function, ipc_uplink
 *
 *                  For USB/RNDIS/ETHCore/IPCore, please refer to     
 *                       rndis_on_bulk_out_complete->ethc_device_rx_need_reload
 *                       rndis_on_bulk_out_complete->ethc_device_rx_complete
 *
 * @param channel   [IN] CCCI channel for this uplink request
 * @param io_request[IN] pointer to the ior
 *
 * @return          void
 */

void ccmni_dhl_print(kal_uint32 mod, const char *fmt, ...)
{
    kal_uint8 string_buff[128];

    va_list args;
    va_start(args, fmt);
    vsprintf((char *)(&string_buff[0]), fmt, args);
    tst_sys_trace((kal_char*)(&string_buff[0])); // Default^M

    return;
}

void ccmni_ccci_ul_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* io_request){
    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    ccmni_device_t      *pdev;
    ccmni_ulq_t         *pulq;
    ccmni_ulq_t         *pdq, *paq;
    ccmni_device_id     dev_id;
    kal_uint32          num_gpd;
    qbm_gpd             *first_gpd;
    qbm_gpd             *last_gpd;
    qbm_gpd             *prev_gpd;
    qbm_gpd             *curr_gpd;
    qbm_gpd             *next_gpd;
    
    kal_bool            valid_gpd = KAL_FALSE;
    kal_bool            is_dlack = KAL_FALSE;
    ccci_io_request_t   *curr_ior;
    ccci_io_request_t   *next_ior;
    kal_uint32          mask;
    kal_bool            end_of_list;
    ipc_io_request_t    *ccmni_ul_ior_req;

    HIF_SWLA_START("CU1");
    if(NULL == io_request){
        ccmni_trace(CCMNI_ERR, CCMNI_MOD_UL, CCMNI_TR_UL_NULL_IOR, channel);
        return;
    }
    dev_id = ccmni_get_ul_devid(channel);
    /*Invalid CCMNI UL channel*/
    ASSERT(dev_id < CCMNI_DEV_CNT);
    pdev = &p_ccmni->dev[dev_id];
    
    is_dlack = ccmni_is_dlack_ch(channel);
    if(KAL_TRUE == is_dlack){
        pulq = &p_ccmni->ulq[pdev->ulq.ccmni_ack_ulq];
    }else{
        pulq = &p_ccmni->ulq[pdev->ulq.ccmni_normal_ulq];
    }

    paq = &p_ccmni->ulq[pdev->ulq.ccmni_ack_ulq];
    pdq = &p_ccmni->ulq[pdev->ulq.ccmni_normal_ulq];

    for (curr_ior = io_request; curr_ior; curr_ior = next_ior) {
        next_ior  = curr_ior->next_request;
        first_gpd = curr_ior->first_gpd;
        last_gpd  = curr_ior->last_gpd;
        //3 Note that, because GPD might be freeed in the following loop, we shall not access curr_ior from now.

        if (first_gpd && last_gpd){
            //4 <1> update the RGPD count in HIF
            num_gpd = CCMNI_GET_GPD_LIST_SIZE(first_gpd, last_gpd);
            ASSERT(num_gpd == CCMNI_GET_NONBPS_GPD_LIST_SIZE(first_gpd, last_gpd));
            CCMNI_DEV_LOCK(mask);
            pulq->hwo_rgpd_cnt -= num_gpd;
            CCMNI_DEV_UNLOCK(mask);
            ccmni_data_trace(CCMNI_UL_GPD_IN_HIF, dev_id, num_gpd, pulq->hwo_rgpd_cnt, pdq->hwo_rgpd_cnt, paq->hwo_rgpd_cnt);
                            
            ASSERT(pulq->hwo_rgpd_cnt >= 0);

#if 0 //CCMNI_RELOAD_ENABLE
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

            prev_gpd = NULL;
            end_of_list = KAL_FALSE;
            for (curr_gpd = first_gpd; curr_gpd && !end_of_list; curr_gpd = next_gpd) {
                next_gpd = QBM_DES_GET_NEXT(curr_gpd);
                end_of_list = (curr_gpd == last_gpd);

#ifdef _CCMNI_CCCI_SEQ_NO_
                {//check CCMNI SQENO
                    kal_uint8 is_dlack = 0;
                    CCCI_BUFF_T         *pdata;
                    kal_uint32 *seq_no;
                    is_dlack = ccmni_is_dlack_ch(channel);
                    pdata = CCCIDEV_GET_QBM_DATAPTR(curr_gpd);
                    if(KAL_TRUE == is_dlack){
                       seq_no = &pdev->rx_seq_no[1];
                       if(0 == ((*seq_no) % 100 )){
                            ccmni_dhl_print(CCMNI_MOD_UL," CCMNI ch(%d) SEQNO(%d)",channel, *seq_no);
                        }
                    }else{
                       seq_no = &pdev->rx_seq_no[0];
                    }
/*                    if(pdata->reserved != *seq_no){
                       ccmni_trace(CCMNI_ERR, CCMNI_MOD_UL, CCMNI_INDEX_ERROR,
                                       dev_id, pdata->reserved,  *seq_no);
                       ccmni_dump_data(pdata, CCMNI_DUMP_SIZE);
                    }
                    *seq_no = pdata->reserved + 1;*/

                    ccci_debug_check_seq(pdata);
                }
#endif

#if CCMNI_DUMP_ENABLE   //for ccmni network packet header debug    
                ccmni_dump_data(CCCIDEV_GET_QBM_DATAPTR(curr_gpd),CCMNI_DUMP_SIZE);
#endif
                {//for trace IP_ID
                    kal_uint8* pdata =(kal_uint8*) CCCIDEV_GET_QBM_DATAPTR(curr_gpd);
                    pdata = (kal_uint8*)((int)pdata & (~0X3)); // 4bytes alignment
                    ccmni_data_trace(CCMNI_UL_DATA_PACKET_TRACE, dev_id, 
                             *(kal_uint32*)(pdata+12), (pdata[20]<<8|pdata[21]), (pdata[26]<<8|pdata[27]));
                }
                //4 <2> remove CCCI header, CCCI_BUFF_T
                valid_gpd = CCMNI_RM_CCCI_HEADERS(channel, curr_gpd);
                if(KAL_TRUE == valid_gpd){
                    prev_gpd = curr_gpd;
                }else{
                    ccmni_trace(CCMNI_ERR, CCMNI_MOD_UL, CCMNI_TR_UL_FREE_INVALID_GPD, channel, curr_gpd, prev_gpd, next_gpd, first_gpd, last_gpd);
                    pdev->ul_invalid_cnt++;
                    if (curr_gpd == first_gpd) {
                        if (curr_gpd == last_gpd) {
                            first_gpd = NULL;
                            last_gpd = NULL;

                            ASSERT(end_of_list);
                            end_of_list = KAL_TRUE; /* All GPD's in the list are freed, exit the loop after curr_gpd released. */
                        } else {
                            ASSERT(next_gpd);
                            first_gpd = next_gpd;
                        }
                        prev_gpd = NULL;
                    } else {
                        ASSERT(prev_gpd);
                        if (curr_gpd == last_gpd) {
                            last_gpd = prev_gpd;
                            QBM_DES_SET_NEXT(prev_gpd, NULL);

                            ASSERT(end_of_list);
                            end_of_list = KAL_TRUE; /* To exit the loop after curr_gpd released. */
                        } else {
                            ASSERT(next_gpd);
                            QBM_DES_SET_NEXT(prev_gpd, next_gpd);
                        }

                        qbm_cal_set_checksum((kal_uint8 *)prev_gpd);
                        QBM_CACHE_FLUSH(prev_gpd, sizeof(qbm_gpd));
                    }

                    qbmt_dest_q(curr_gpd, curr_gpd);
                    ipc_need_ul_reload(pdev->ipc_handle);
                }
            } /* for (curr_gpd) */

            //4 <3> callback to ipc_uplink
            if (first_gpd) {
                ASSERT(last_gpd);
                if (ccmni_dev_connected(pdev)) {

                    ccmni_ul_ior_req = (ipc_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(first_gpd);
                    ccmni_ul_ior_req->next_request  = NULL;
                    ccmni_ul_ior_req->first_gpd     = first_gpd;
                    ccmni_ul_ior_req->last_gpd      = last_gpd;
                    ccmni_ul_ior_req->ip_type       = IPC_IP_TYPE_MIXED;
                    ccmni_ul_ior_req->qos_priority  = 0;
                    ccmni_ul_ior_req->reserved[0]   = 0;
                    ccmni_ul_ior_req->reserved[1]   = 0;

                    
#if defined(__CCMNI_IT__)                   
                    if (pdev->it_mode == CCMNI_IT_PURE_LB){
                        //nicc_ul2dl_loopback((hif_io_request_t *)curr_ior, (nicc_dl_func)rndis_on_downlink, dev->ethc_inst);
                        ccmni_ul2dl_loopback((ccci_io_request_t *)ccmni_ul_ior_req, (void*) pdev);
                        ccmni_trace(CCMNI_INFO, CCMNI_MOD_UL, CCMNI_UT_PURE_LB_MODE_TRACE, channel, num_gpd);
                    }
                    else if ((pdev->it_mode == CCMNI_IT_DROP_UL) || (pdev->it_mode == CCMNI_IT_DL_ONLY)){
                        qbmt_dest_q(first_gpd, last_gpd);
                        ipc_need_ul_reload(pdev->ipc_handle);
                    }
                    else if ((pdev->it_mode == CCMNI_IT_UDP_LB) || (pdev->it_mode == CCMNI_IT_PING)){
                        //ccmni_reload_ul_gpds((void*) pdev);
                        ccmni_it_udp_icmp_loopback((ccci_io_request_t *)ccmni_ul_ior_req, (void*) pdev);
                        ipc_need_ul_reload(pdev->ipc_handle);
                    }
                    else if (pdev->it_mode == CCMNI_IT_DL_UL){
                        qbmt_dest_q(first_gpd, last_gpd);
                        ipc_need_ul_reload(pdev->ipc_handle);
                        /*2Mbps 1+24pktsize*/
                        //ccmni_udp_pkt_gen_bw(50, CCMNI_IT_TX_PKT_SZ, CCMNI_EMCSNI0_PORT); //disable during //CCDL
                        ccmni_udp_pkt_gen_acnt(100, CCMNI_IT_TX_PKT_SZ, dev_id);  //CCDL
                    }
                    else
#endif //__CCCI_LB_IT__
                    {
                        p_ccmni->ipc_uplink(pdev->ipc_handle, (ipc_io_request_t*)ccmni_ul_ior_req);
                        //ethc_device_rx_complete(dev->ethc_inst, (hif_io_request_t *)&ccmni_ul_ior_req);
                    }

                } else {
                    ccmni_trace(CCMNI_ERR, CCMNI_MOD_UL, CCMNI_TR_UL_DISCARD_IN_DISCONNECTED, channel, num_gpd);
                    qbmt_dest_q(first_gpd, last_gpd);
                    ipc_need_ul_reload(pdev->ipc_handle);
                }
            } else {
                ASSERT(NULL == last_gpd);
                ccmni_trace(CCMNI_ERR, CCMNI_MOD_UL, CCMNI_TR_UL_EMPTY_IOR, channel);
            }
        } else {/* if (first_gpd && last_gpd) */
            ccmni_trace(CCMNI_ERR, CCMNI_MOD_UL, CCMNI_TR_UL_INVALID_IOR, channel, curr_ior, first_gpd, last_gpd);
            ASSERT(KAL_FALSE); /* Invalid IOR */
        }
    } /*for (curr_ior...*/
    HIF_SWLA_STOP("CU1");
    return;
}

kal_bool ccmni_reload_ulq(CCCI_CHANNEL_T reload_ch, ccmni_ulq_t *p_ulq, ccmni_device_t *p_dev, ccmni_inst_t *p_ccmni){
    qbm_gpd             *head;
    qbm_gpd             *tail;
    ccci_io_request_t   ior;
    
    kal_uint32          to_alloc;
    kal_uint32          num_alloc;
    kal_uint32          mask;
    kal_bool            need_retry = KAL_FALSE;
    kal_int32           ret;
    
    ASSERT(p_ulq);
    
    CCMNI_DEV_LOCK(mask);
    if (p_ulq->hwo_rgpd_cnt< p_ulq->max_hwo_rgpd_cnt) {
        /* Keep at most dev->max_hwo_rgpd_cnt for HIF queue. */
        to_alloc = p_ulq->max_hwo_rgpd_cnt - p_ulq->hwo_rgpd_cnt;
        CCMNI_DEV_UNLOCK(mask);
        /* 20130813 split HIF UL QBM pool */        
        num_alloc = qbmt_alloc_q_no_tail(
                        p_ulq->ul_qbm_type, /* type */
                        to_alloc, /* buff_num */
                        (void **)(&head), /* pp_head */
                        (void **)(&tail)); /* pp_tail */
        
        //ccmni_trace(CCMNI_TRACE, CCMNI_MOD_RGPDMGR, CCMNI_TR_UL_ALLOC_GPD, p_dev->dev_id, to_alloc, num_alloc, p_ulq->hwo_rgpd_cnt);
        ccmni_data_trace(CCMNI_UL_RELOAD_RGPD, p_dev->dev_id, to_alloc, num_alloc, p_ulq->hwo_rgpd_cnt);
        if((num_alloc != to_alloc) ||   /* Not enough RGPD, retry it again! */
           (num_alloc ==0))             /* No GPD allocated, retry it again!*/
        {
            need_retry = KAL_TRUE;
        }
        
        if (num_alloc > 0) {
                ASSERT(head != NULL && tail != NULL);
                ASSERT(num_alloc == CCMNI_GET_GPD_LIST_SIZE(head, tail));
            
                ior.next_request = NULL;
                ior.first_gpd = head;
                ior.last_gpd = tail;

                /*Submit UL GPD allocated to H/W to receive data from host.*/
#ifdef __SDIOC_PULL_Q_ENH_DL__
                ior.num_gpd = num_alloc; /* no use, just pass it */
#endif
                CCMNI_DEV_LOCK(mask);
                {
                    p_ulq->hwo_rgpd_cnt += num_alloc;
                }
                CCMNI_DEV_UNLOCK(mask);
                HIF_SWLA_START("CU3");
                ret = p_ccmni->ccci_write_gpd(reload_ch, &ior, NULL);
                HIF_SWLA_STOP("CU3");
                if(ret != CCCI_SUCCESS){
                    ccmni_trace(CCMNI_ERR, CCMNI_MOD_RGPDMGR, CCMNI_TR_UL_RGPD_SUBMITTED_FAIL, p_dev->dev_id, reload_ch, ret, &ior, &ior.first_gpd, &ior.last_gpd);
                    qbmt_dest_q(ior.first_gpd, ior.last_gpd);
                    need_retry = KAL_TRUE; /* NOT going to happen under SDIO */
                    CCMNI_DEV_LOCK(mask);
                    {
                        p_ulq->hwo_rgpd_cnt -= num_alloc;
                    }
                    CCMNI_DEV_UNLOCK(mask);
                }else{
                    //ccmni_trace(CCMNI_TRACE, CCMNI_MOD_RGPDMGR, CCMNI_TR_UL_RGPD_SUBMITTED, p_dev->dev_id, reload_ch, ret, &ior, &ior.first_gpd, &ior.last_gpd);
                }
         } 
    } else {
        /* HIF has got enough RGPD, no reload is required. */
        CCMNI_DEV_UNLOCK(mask);
    }
    
#if defined(__CCMNI_IT__)  
    p_dev->dev_reload_retry = need_retry;
#endif    
    return need_retry;
}

/*!
 * @function        ccmni_reload_ul_gpds
 * @brief           API to reload the uplink RGPDs to make sure the RGPD count = max_hwo_rgpd_cnt
 *                  For USB/RNDIS/ETHCore/IPCore, please refer to rndis_reload_ul_buffers
 *
 * @param context   [IN] pointer to the CCMNI device, ccmni_device_t
 *
 * @return          KAL_TRUE, need_retry, the RGPD count in HIF is < dev->max_hwo_rgpd_cnt
 *                  KAL_FALSE, doesn't need_retry, the RGPD count in HIF is == max_hwo_rgpd_cnt
 */
kal_bool ccmni_reload_ul_gpds(void *context)
{   
    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    ccmni_device_t      *dev = (ccmni_device_t *)context;
    ccmni_ulq_t         *p_nor_ulq = NULL;
    ccmni_ulq_t         *p_ack_ulq = NULL;
    kal_bool            nor_ulq_retry = KAL_FALSE;
    kal_bool            ack_ulq_retry = KAL_FALSE;    
    

    ASSERT(dev); 
    ASSERT(dev->dev_id < CCMNI_DEV_CNT);
    ASSERT(dev->ulq.ccmni_normal_ulq < CCMNI_ULQ_CNT);
    ASSERT(dev->ulq.ccmni_ack_ulq < CCMNI_ULQ_CNT);    
    HIF_SWLA_START("CU2");

    p_nor_ulq = &p_ccmni->ulq[dev->ulq.ccmni_normal_ulq];
    p_ack_ulq = &p_ccmni->ulq[dev->ulq.ccmni_ack_ulq];
    
    nor_ulq_retry = ccmni_reload_ulq(dev->ccci_ch.ccmni_ch_ul, p_nor_ulq, dev, p_ccmni);
    ack_ulq_retry = ccmni_reload_ulq(dev->ccci_ch.ccmni_ch_dlack_ul, p_ack_ulq, dev, p_ccmni);    
    ccmni_data_trace(CCMNI_UL_RELOAD_RGPD_IN_HIF, dev->dev_id, p_nor_ulq->hwo_rgpd_cnt, p_nor_ulq->max_hwo_rgpd_cnt
                                                , p_ack_ulq->hwo_rgpd_cnt, p_nor_ulq->max_hwo_rgpd_cnt);
    HIF_SWLA_STOP("CU2");

    return (((KAL_FALSE == nor_ulq_retry) && (KAL_FALSE == ack_ulq_retry)) ? KAL_FALSE : KAL_TRUE);
}

/*!
 * @function        ccmni_ccci_dummy_cb
 * @brief           This API is the dummy function for CCMNI CCCI channels doesn't need callback
 *                  Should not be called during execution
 *
 * @param channel   [IN] CCCI channel for this callback
 * @param io_request[IN] pointer to the ior
 *
 * @return          void
 */
void ccmni_ccci_dummy_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* io_request){
    /* dummy function for backword compatible to MT6280 CCCI*/

    ccmni_trace(CCMNI_ERR, CCMNI_MOD_DATA, CCMNI_TR_DATA_DUMMY_CH_TRIG, channel);
    return;
}


/*!
 * @function        ccmni_qbm_pool_status_cb
 * @brief           This API is the callback use to change MAX reload RGPD count,
 *                  when 2/3/4G inter rat.
 *
 * @param status    [IN] QMU_BM pool status 
 *                       QBM_POOL_SHRINK: 2G
 *                       QBM_POOL_NORMAL: 3/4G
 *
 * @return          void
 */

void ccmni_qbm_pool_status_cb(qbm_pool_status status){
    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    switch(status){
        case QBM_POOL_NORMAL:
            p_ccmni->ulq[CCMNI_ULQ_T_NORMAL].max_hwo_rgpd_cnt = QBM_NUM_HIF_UL_TYPE_IN_HIF;
            p_ccmni->ulq[CCMNI_ULQ_T_ACK].max_hwo_rgpd_cnt    = QBM_NUM_HIF_UL_TYPE_S_IN_HIF;
            p_ccmni->ulq[CCMNI_ULQ_MISC].max_hwo_rgpd_cnt     = QBM_NUM_HIF_UL_TYPE_02_IN_HIF;
            break;
        case QBM_POOL_SHRINK:
            p_ccmni->ulq[CCMNI_ULQ_T_NORMAL].max_hwo_rgpd_cnt = QBM_NUM_HIF_UL_TYPE_IN_HIF_SHRINK;
            p_ccmni->ulq[CCMNI_ULQ_T_ACK].max_hwo_rgpd_cnt    = QBM_NUM_HIF_UL_TYPE_S_IN_HIF_SHRINK;
            p_ccmni->ulq[CCMNI_ULQ_MISC].max_hwo_rgpd_cnt     = QBM_NUM_HIF_UL_TYPE_02_IN_HIF_SHRINK;
            break;
        default:
            break;
    }
    #ifdef __DHL_MODULE__
    ccmni_data_trace(CCMNI_MAX_RELOAD_RGPD_IN_HIF,
                     p_ccmni->ulq[CCMNI_ULQ_T_NORMAL].max_hwo_rgpd_cnt,
                     p_ccmni->ulq[CCMNI_ULQ_T_ACK].max_hwo_rgpd_cnt,
                     p_ccmni->ulq[CCMNI_ULQ_MISC].max_hwo_rgpd_cnt
                     );
    #endif
}
