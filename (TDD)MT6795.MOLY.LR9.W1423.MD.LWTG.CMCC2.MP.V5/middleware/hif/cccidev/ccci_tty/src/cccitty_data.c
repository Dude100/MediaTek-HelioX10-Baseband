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
 *   cccitty_data.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Implements functions for CCCI TTY data path
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
 * 	Add cccitty sequence support(Merging from MP5 CL:641385 to MP6)
 *
 * removed!
 * removed!
 * 	add cccitty sequence support and status update support
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	reset num_gpd before reloading error ior to HIF
 *
 * 11 18 2013 ap.wang
 * removed!
 * 	Remove MD Log data path log
 *
 * 09 06 2013 ap.wang
 * removed!
 *
 * removed!
 * removed!
 * remove ccci DHL Tx data path log: CCCI_TTY, CCCI
 *
 * 03 27 2013 ap.wang
 * removed!
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#include "cccitty_common.h"
#include "cccitty_data.h"
#include "cccitty_if.h"
#include "cccitty_sm.h"
#include "cccitty_qbm.h"
#include "ccci_if.h"
#include "qmu_bm_util.h"

#define MIN(_a, _b) (((_a) <= (_b)) ? (_a) : (_b))

#define CCCITTY_DUMP_SIZE (32)
#define CCCITTY_DATA_TRACE_DUMP_ENABLE (1)
#if CCCITTY_DATA_TRACE_DUMP_ENABLE
static void cccitty_dump_data(void* p_data, kal_uint32 bytes){
    kal_int32 i = 0;
    kal_uint32* p_d = (kal_uint32*)((int)p_data & (~0X3));// 4bytes alignment 
    for (i=0; i*4 < bytes; i=i+4 ){
        cccitty_data_trace(CCCITTY_DATA_DUMP_TRACE,i*4 , p_d[i], p_d[i+1], p_d[i+2], p_d[i+3]);
    }
}
#endif

/*!
 * @function        [static] cccitty_check_ul_gpd_list_sequence
 * @brief           Traverse the input GPD list and check sequence in the CCCI header 
 *
 * @param first_gpd [IN] pointer to the first GPD in the GPD chain
 * @param last_gpd  [IN] pointer to the last GPD in the GPD chain
 *
 * @return          kal_uint32 return the gpd number in between first_gpd and last_gpd
 */
static kal_uint32 cccitty_check_ul_gpd_list_sequence(qbm_gpd* first_gpd, qbm_gpd* last_gpd)
{
    qbm_gpd *curr_gpd;
    qbm_gpd *next_gpd;
    kal_uint32 num_gpd;
    CCCI_BUFF_T *pdata;

    EXT_ASSERT((first_gpd && last_gpd),(kal_uint32)first_gpd, (kal_uint32)last_gpd,0);

    curr_gpd = first_gpd;

    do {
        next_gpd = QBM_DES_GET_NEXT(curr_gpd);
        pdata = CCCIDEV_GET_QBM_DATAPTR(curr_gpd);
        ccci_debug_check_seq(pdata);
        num_gpd ++;
        if ( curr_gpd == last_gpd )
        {
            break;
        }        
        curr_gpd = next_gpd;
    } while ( curr_gpd != NULL );

    return num_gpd;    
}

/*!
 * @function        [static] cccitty_process_dl_gpd_list
 * @brief           Traverse the input GPD list and insert the CCCI header on the first BD->data 
 *
 * @param pDevice   [IN] pointer to the CCCI_TTY device
 * @param first_gpd [IN] pointer to the first GPD in the GPD chain
 * @param last_gpd  [IN] pointer to the last GPD in the GPD chain
 *
 * @return          kal_uint32 return the gpd number in between first_gpd and last_gpd
 */
static kal_uint32 cccitty_process_dl_gpd_list(cccitty_dev_t* pDevice, qbm_gpd* first_gpd, qbm_gpd* last_gpd)
{  /*process_tx_gpd_list*/
    qbm_gpd*            current_gpd = NULL;
    kal_uint32          pkt_cnt   = 0;
    kal_uint32          byte_cnt  = 0;
    kal_uint32          ccci_h_size;
    CCCI_BUFF_T         *p_ccci_head;
    kal_int32           addseqrtn;
    
    //ASSERT(first_gpd && last_gpd);
    EXT_ASSERT((first_gpd && last_gpd), pDevice->dev_id, (kal_uint32)first_gpd, (kal_uint32)last_gpd);
  
    current_gpd = first_gpd;
    ccci_h_size = sizeof(CCCI_BUFF_T);
    ASSERT(ccci_h_size > 0);
    do {
        //4 <1> append CCCI header CCCI_BUFF_T
#ifdef __CCCI_N_USE_TGPD_EXT__ 
        /*move data buffer pointer forward for ccci header, increase the gpd, bd length*/
        CCCITTY_PUSH_QBM_DATAHEAD(current_gpd, ccci_h_size);
        p_ccci_head   = (CCCI_BUFF_T *)CCCITTY_GET_QBM_DATAPTR(current_gpd);
        CCCI_STREAM_SET_LEN(p_ccci_head, CCCITTY_GET_QBM_DATALEN(current_gpd));
#else
        /* Store the DL CCCI header in the GPD extention part */
        QBM_DES_SET_EXTLEN(current_gpd, ccci_h_size);
        p_ccci_head = (CCCI_BUFF_T *)QBM_DES_GET_EXT(current_gpd);
        CCCI_STREAM_SET_LEN(p_ccci_head, CCCITTY_GET_QBM_DATALEN(current_gpd)+ccci_h_size);
#endif
        /*Construct the CCCI header*/
        CCCI_SET_CH_NO(p_ccci_head, pDevice->ccci_ch.cccitty_ch_dl);

        /*Add CCCI sequence number*/
        addseqrtn = ccci_debug_add_seq(p_ccci_head, CCCI_DEBUG_ASSERT_BIT);
        if(addseqrtn != CCCI_SUCCESS) 
        {
            cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_DL, CCCI_TTY_ADD_DL_SEQ_FAIL, addseqrtn, pDevice->ccci_ch.cccitty_ch_dl);
        }

#if CCCITTY_DATA_TRACE_DUMP_ENABLE
        if(pDevice->ccci_ch.cccitty_ch_dl != CCCI_MD_LOG_RX){
            cccitty_dump_data(CCCITTY_GET_QBM_DATAPTR(current_gpd), CCCITTY_DUMP_SIZE);
        }
#endif

        QBM_CACHE_FLUSH(p_ccci_head, sizeof(CCCI_BUFF_T));
        
        pkt_cnt++;
        byte_cnt += QBM_DES_GET_DATALEN(current_gpd);

        if ( current_gpd == last_gpd )
        {
            break;
        }
        current_gpd = QBM_DES_GET_NEXT(current_gpd);

    } while ( current_gpd != NULL );

    return pkt_cnt;
}

/*!
 * @function        cccitty_ttyc_hdr_cmd_put_bytes_ior
 * @brief           Downlink handler while receiving TTY_CMD_PUT_BYTES_IOR
 *                  Context: user context e.x. MOD_L4C
 *                  Reference cdcacm_ttyhdr_cmd_put_bytes_ior /ccmni_ipc_dl
 *                  Process: <1> drop the ior if device is not connected
 *                           <2> append CCCI_HEADER
 *                           <3> pass the ior to CCCI by ccci_write_gpd
 *
 * @param port      [IN] UART port number
 * @param p_ior     [IN] Reload UL RGPD io_request
 * @param ownerid   [IN] module_type for the one opening this port, ex. MOD_xxx
 * @param pextinfo: [IN] pointer to the ccci io request extension information, ex.CCCI_IO_TX_NO_FLUSH
 *
 * @return          DCL_STATUS
 *                  STATUS_OK:   success
 *                  STATUS_FAIL: case 1. p_ior == NULL
 *                               case 2. ccci_write_gpd fail
 */
DCL_STATUS cccitty_ttyc_hdr_cmd_put_bytes_ior(UART_PORT port, ccci_io_request_t *p_ior, module_type ownerid, ccci_io_ext_info_t* pextinfo)
{
    cccitty_dev_t       *p_cccidev = cccitty_get_dev_instance(CCCITTY_UARTP_TO_DEVID(port));
    cccitty_inst_t      *p_cccitty = cccitty_get_instance();
    DCL_STATUS           dcl_ret;
    ccci_io_request_t    *cccitty_ior_curr;
    CCCI_RETURNVAL_T    ccci_ret;
    //CCCI_BUFF_T         *p_ccci_head;

#ifdef __CCCI_TTY_CONV_TX_DL_PERF__
    CCCI_PERF_GET_CYCLE(dl_prof[dl_prof_id].tty_conv_tx_cccih_s);
#endif

    if (NULL == p_ior){
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_DL, CCCI_TTY_TR_DL_EMPTY_IOR, p_cccidev->dev_id);
        return STATUS_FAIL;
    }

    //4 <1> drop the ior if device is not connected
    if(!cccitty_dev_active(p_cccidev)){
        ccci_dest_ior((ccci_io_request_t*)p_ior);
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_DL, CCCI_TTY_TR_DL_DEV_NOPEN, p_cccidev->dev_id, cccitty_get_dev_state(p_cccidev), CCCI_TTY_DEV_OPEN);
        return STATUS_FAIL;
    }

    dcl_ret = STATUS_FAIL;
    //ASSERT(NULL != p_ior);
    EXT_ASSERT(p_ior, port, ownerid, 0);

    //4 <2> append CCCI_HEADER
    cccitty_ior_curr = p_ior;
    do{
        ccci_io_request_t* next_ior = cccitty_ior_curr->next_request;
        CCCITTY_FIX_IOR_NULL_LAST(cccitty_ior_curr);
#ifdef __SDIOC_PULL_Q_ENH_DL__
        cccitty_ior_curr->num_gpd = cccitty_process_dl_gpd_list(p_cccidev, cccitty_ior_curr->first_gpd, cccitty_ior_curr->last_gpd);
#else
        cccitty_process_dl_gpd_list(p_cccidev, cccitty_ior_curr->first_gpd, cccitty_ior_curr->last_gpd);
#endif
        cccitty_ior_curr = next_ior;
    }while(NULL != cccitty_ior_curr);
/*    
#ifdef __CCCI_N_USE_TGPD_EXT__     
    p_ccci_head   = (CCCI_BUFF_T *)CCCITTY_GET_QBM_DATAPTR(p_ior->first_gpd);
#else
    p_ccci_head   = (CCCI_BUFF_T *)QBM_DES_GET_EXT(p_ior->first_gpd);
#endif
    cccitty_trace(CCCI_TTY_TRACE, CCCI_TTY_MOD_DL, CCCI_TTY_TR_DL_CCCIH_TRACE, p_cccidev->dev_id, p_ccci_head->data[0], p_ccci_head->data[1], p_ccci_head->channel, p_ccci_head->reserved);
*/
    //4 <3> pass the ior to CCCI by ccci_write_gpd
    ccci_ret = p_cccitty->ccci_write_gpd(p_cccidev->ccci_ch.cccitty_ch_dl, (ccci_io_request_t*)p_ior, pextinfo);
    if(CCCI_SUCCESS == ccci_ret){
        dcl_ret = STATUS_OK;
    }

#ifdef __CCCI_TTY_CONV_TX_DL_PERF__
    CCCI_PERF_GET_CYCLE(dl_prof[dl_prof_id].tty_conv_tx_cccih_e);
#endif

    return dcl_ret;
}

/*!
 * @function        cccitty_ccci_dl_cb
 * @brief           Downlink done handler, called while Tx done callback in HIF
 *                  Context: HIF context e.x. MOD_SIODCORE
 *                  Reference cdcacm_ttyhdr_cmd_put_bytes_ior /ccmni_ipc_dl
 *                  Process: <1> drop the ior if TTYCore doesn't request callback, tty_need_tx_done_cb == DCL_FALSE
 *                           <2> callback p_cccitty->dcl_txdone
 *
 * @param channel    [IN] ccci_channel id
 * @param io_request [IN] pointer to uplink io request 
 *
 * @return          void
 *
 */
void cccitty_ccci_dl_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* io_request){
    cccitty_inst_t      *p_cccitty = cccitty_get_instance();
    cccitty_dev_t       *p_cccidev;
    cccitty_device_id   dev_id = cccitty_get_dl_devid(channel);

    if(CCCI_TTY_DEV_CNT == dev_id){
        /* cannot find dev_id for channel, please check g_cccitty_ccci_ch_mappping */
        return;
    }
    
    if(NULL == io_request){
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_DL_TXDONE_NULL_IOR, dev_id, channel);
        return;
    }

//    dev_id = cccitty_get_dl_devid(channel);
    /* ASSERT if invalid channel number is received */
    EXT_ASSERT(dev_id < CCCI_TTY_DEV_CNT, channel, 0, 0);

    p_cccidev = cccitty_get_dev_instance(dev_id);

    if(DCL_TRUE == p_cccidev->tty_need_tx_done_cb){
        /* TTYCore/User requests Tx done callback */
        //cccitty_trace(CCCI_TTY_TRACE, CCCI_TTY_MOD_UL, CCCI_TTY_TR_DL_TXDONE_CB, dev_id, channel);
        p_cccitty->dcl_txdone(p_cccidev->tty_handler, MOD_CCCITTY, io_request);
    }else{
        //cccitty_trace(CCCI_TTY_TRACE, CCCI_TTY_MOD_UL, CCCI_TTY_TR_DL_TXDONE_CB_DIS, dev_id, channel);
        ccci_dest_ior(io_request);
    }

    return;
}

/*!
 * @function        cccitty_ccci_ul_cb
 * @brief           uplink callback function register to CCCI, CCCI will callback during uplink process
 *                  Context: HIF context e.x. MOD_SIODCORE
 *                  process: <1> update the RGPD count in HIF
 *                           <2> remove CCCI header, CCCI_BUFF_T
 *                           <3> enqueue the RGPD to hif_ul_q_h 
 *                               or loopback, CCCITTY_LB_ENABLE
 *                           <4> send MSG_ID_CCCI_TTY_UL_DEQUEUE_REQ, change to MOD_CCCITTY context for dequeue(MOD_CCCIDEV)
 *                           <5> Error Handling: reload RGPD number error_reload_cnt
 *                               Function might free RGPDs for the following cases
 *                                      case 1. CCCI header corrupts, CCCITTY_RM_CCCI_HEADERS return false
 *                                      case 2. cccitty device state != CCCI_TTY_DEV_OPEN, cccitty_dev_active return false
 *
 * @param channel    [IN] ccci_channel id
 * @param io_request [IN] pointer to uplink io request 
 *
 * @return          void
 */
void cccitty_ccci_ul_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* io_request){
    cccitty_inst_t      *p_cccitty = cccitty_get_instance();
    cccitty_dev_t       *p_cccidev;
    cccitty_device_id   dev_id = cccitty_get_ul_devid(channel);
    ccci_io_request_t   *curr_ior;
    ccci_io_request_t   *next_ior;
    kal_bool            end_of_list;

    qbm_gpd             *first_gpd;
    qbm_gpd             *last_gpd;
    qbm_gpd             *prev_gpd;
    qbm_gpd             *curr_gpd;
    qbm_gpd             *next_gpd;

    kal_int32           tmp;
    kal_uint32          num_gpd;
    kal_bool            valid_gpd = KAL_FALSE;
    kal_uint32          num_alloc;//, to_alloc; 
    CCCI_RETURNVAL_T    ccci_ret;
    kal_bool            ttydev_deq_msg = KAL_FALSE;
    cccitty_deq_req_t   *cccitty_deq_req;    

    /* error RPGD handling */
    ccci_io_request_t   err_reload_ior;
    kal_uint32          err_reload_cnt = 0;
    qbm_gpd             *err_gpd_h = NULL;
    qbm_gpd             *err_gpd_t = NULL;
    kal_uint32          NBPS_GPD_NUM = 0;
    CCCI_BUFF_T         *pdata;
    kal_int32           chkseqrtn = 0;

    if(CCCI_TTY_DEV_CNT == dev_id){
        /* cannot find dev_id for channel, please check g_cccitty_ccci_ch_mappping */
        return;
    }
    if(NULL == io_request){
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_UL_NULL_IOR, dev_id, channel);
        return;
    }
    /* ASSERT if invalid channel number is received */
    EXT_ASSERT(dev_id < CCCI_TTY_DEV_CNT, channel, 0, 0);

    p_cccidev = cccitty_get_dev_instance(dev_id);
    if(!cccitty_dev_active(p_cccidev)){
        /* device is not at CCCI_TTY_DEV_OPEN state*/
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_UL_DEV_NOT_OPEN,p_cccidev->dev_id, cccitty_get_dev_state(p_cccidev));

        /*for drop packet case, need to check sequence number first*/
        /*If there is mips issue, this action can be combined with reset function*/
        cccitty_check_ul_gpd_list_sequence(io_request->first_gpd, io_request->last_gpd);
        
        /* reset the gpds*/
        num_alloc = cccitty_reset_ccci_comm_gpd_list(io_request->first_gpd, io_request->last_gpd);
        //ASSERT (num_alloc == CCCITTY_GET_NONBPS_GPD_LIST_SIZE(io_request->first_gpd, io_request->last_gpd));
        NBPS_GPD_NUM = CCCITTY_GET_NONBPS_GPD_LIST_SIZE(io_request->first_gpd, io_request->last_gpd);
        EXT_ASSERT((num_alloc == NBPS_GPD_NUM), num_alloc, NBPS_GPD_NUM, 0);

        io_request->num_gpd = num_alloc;
        /* reload the gpds */
        ccci_ret = p_cccitty->ccci_write_gpd(p_cccidev->ccci_ch.cccitty_ch_ul, io_request, NULL);
        if(CCCI_SUCCESS != ccci_ret){
            /* NOTE!! might cause RGPD leackage here */
            cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_UL_CCCI_WRITE_FAIL,p_cccidev->dev_id, ccci_ret);
            qbmt_dest_q(io_request->first_gpd, io_request->last_gpd);
        }else{
            CCCI_TTY_LOCK(p_cccidev->cccitty_mutex);
            {
                 /* should not increase hwo_rgpd_cnt, since this is the RGPD belongs to other user */
                 //p_cccidev->hwo_rgpd_cnt += num_alloc;
                 /* to prevent interrupted by SDIOCORE context*/
                 tmp = p_cccidev->hwo_rgpd_cnt;
            }            
            CCCI_TTY_UNLOCK(p_cccidev->cccitty_mutex);
            cccitty_trace(CCCI_TTY_TRACE, CCCI_TTY_MOD_UL, CCCI_TTY_TR_HIF_RGPD_RELOAD5,p_cccidev->dev_id, num_alloc, tmp);    
        }
        return;
    }

    for (curr_ior = io_request; curr_ior; curr_ior = next_ior) {
        next_ior  = curr_ior->next_request;
        first_gpd = curr_ior->first_gpd;
        last_gpd  = curr_ior->last_gpd;
        //3 Note that, because GPD might be freeed in the following loop, we shall not access curr_ior from now.

        if (first_gpd && last_gpd){
            //4 <1> update the RGPD count in HIF
            num_gpd = CCCITTY_GET_GPD_LIST_SIZE(first_gpd, last_gpd);
            /* NOT allow BPS GPD inside */
            //ASSERT(num_gpd == CCCITTY_GET_NONBPS_GPD_LIST_SIZE(first_gpd, last_gpd));
            NBPS_GPD_NUM = CCCITTY_GET_NONBPS_GPD_LIST_SIZE(first_gpd, last_gpd);
            EXT_ASSERT((num_gpd == NBPS_GPD_NUM), num_gpd, NBPS_GPD_NUM, 0);

            CCCI_TTY_LOCK(p_cccidev->cccitty_mutex);
            {
                p_cccidev->hwo_rgpd_cnt -= num_gpd;
                tmp = p_cccidev->hwo_rgpd_cnt;
            }
            CCCI_TTY_UNLOCK(p_cccidev->cccitty_mutex);
            
            cccitty_trace(CCCI_TTY_TRACE, CCCI_TTY_MOD_UL, CCCI_TTY_TR_UL_RCV_GPD, p_cccidev->dev_id, num_gpd, tmp);
            if(p_cccidev->hwo_rgpd_cnt < 1){
                cccitty_trace(CCCI_TTY_WARN, CCCI_TTY_MOD_UL, CCCI_TTY_TR_UL_RGPD_EMPTY, p_cccidev->dev_id, tmp);
            }

            prev_gpd = NULL;
            end_of_list = KAL_FALSE;
            for (curr_gpd = first_gpd; curr_gpd && !end_of_list; curr_gpd = next_gpd) {
                next_gpd = QBM_DES_GET_NEXT(curr_gpd);
                end_of_list = (curr_gpd == last_gpd);

                /*Check sequence number here!*/
                pdata = CCCIDEV_GET_QBM_DATAPTR(curr_gpd);
                chkseqrtn = ccci_debug_check_seq(pdata);
                if(chkseqrtn != CCCI_SUCCESS)
                {
                    cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_CHK_UL_SEQ_FAIL, chkseqrtn, channel);
                }
                
                //4 <2> remove CCCI header, CCCI_BUFF_T
                valid_gpd = CCCITTY_RM_CCCI_HEADERS(channel, curr_gpd);
                if(KAL_TRUE == valid_gpd){
                    prev_gpd = curr_gpd;
                }else{
                    p_cccidev->ul_invalid_ttl_cnt++;
                    err_reload_cnt ++;
                    cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_UL_RPGD_ERR, err_reload_cnt, p_cccidev->ul_invalid_ttl_cnt);

                    if (curr_gpd == first_gpd) {
                        if (curr_gpd == last_gpd) {
                            first_gpd = NULL;
                            last_gpd = NULL;

                            EXT_ASSERT(end_of_list,0,0,0);
                            end_of_list = KAL_TRUE; /* All GPD's in the list are freed, exit the loop after curr_gpd released. */
                        } else {
                            EXT_ASSERT(next_gpd,0,0,0);
                            first_gpd = next_gpd;
                        }
                        prev_gpd = NULL;
                    } else {
                        EXT_ASSERT(prev_gpd,0,0,0);
                        if (curr_gpd == last_gpd) {
                            last_gpd = prev_gpd;
                            QBM_DES_SET_NEXT(prev_gpd, NULL);

                            EXT_ASSERT(end_of_list,0,0,0);
                            end_of_list = KAL_TRUE; /* To exit the loop after curr_gpd released. */
                        } else {
                            EXT_ASSERT(next_gpd,0,0,0);
                            QBM_DES_SET_NEXT(prev_gpd, next_gpd);
                        }

                        qbm_cal_set_checksum((kal_uint8 *)prev_gpd);
                        QBM_CACHE_FLUSH(prev_gpd, sizeof(qbm_gpd));
                    }

                    CCCITTY_QBM_ENQ(curr_gpd, curr_gpd, (void **)&err_gpd_h, (void **)&err_gpd_t);
                }
            } /* for (curr_gpd) */

            //4 <3> enqueue the RGPD to hif_ul_q_h
            if (first_gpd) {
                EXT_ASSERT(last_gpd,0,0,0);
                num_gpd = CCCITTY_GET_GPD_LIST_SIZE(first_gpd, last_gpd);
#if CCCITTY_LB_ENABLE
                // TODO: Provide the loopback function
                //4 nicc_ul2dl_loopback((ccci_io_request_t *)curr_ior, (nicc_dl_func)rndis_on_downlink, dev->ethc_inst);
#else
                /*enqueue to hif_ul_q*/
                CCCI_TTY_LOCK(p_cccidev->cccitty_mutex);
                {
                    CCCITTY_QBM_ENQ(first_gpd, last_gpd, (void **)&p_cccidev->hif_ul_q_h, (void **)&p_cccidev->hif_ul_q_t);
                    p_cccidev->hif_ul_rgpd_cnt += num_gpd;
                    tmp = p_cccidev->hif_ul_rgpd_cnt;
                }
                CCCI_TTY_UNLOCK(p_cccidev->cccitty_mutex);
                ttydev_deq_msg = KAL_TRUE;
#endif
            } else {
                EXT_ASSERT((NULL == last_gpd),0,0,0);
                cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_UL_EMPTY_IOR, p_cccidev->dev_id);
            }

        } else {/* if (first_gpd && last_gpd) */
            cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_UL_INVALID_IOR, p_cccidev->dev_id, curr_ior, first_gpd, last_gpd);
            EXT_ASSERT(KAL_FALSE, (kal_uint32)first_gpd, (kal_uint32)last_gpd, 0); /* Invalid IOR */
        }
    } /*for (curr_ior...*/

    //4 <4> send MSG_ID_CCCI_TTY_UL_DEQUEUE_REQ
    if(KAL_TRUE == ttydev_deq_msg){
        CCCI_TTY_LOCK(p_cccidev->cccitty_mutex);
        if(KAL_FALSE == p_cccidev->dev_ul_processing){
            {
                p_cccidev->dev_ul_processing = KAL_TRUE;
            }
            CCCI_TTY_UNLOCK(p_cccidev->cccitty_mutex);
            cccitty_deq_req = (cccitty_deq_req_t *)construct_local_para(sizeof(cccitty_deq_req_t), 0);
            cccitty_deq_req->dev = p_cccidev;
            msg_send6(MOD_CCCITTY,                                 /* src_mod_id, depending on the HIF type */
                      MOD_CCCITTY,                                  /* dest_mod_id */
                      0,                                            /* sap_id */
                      MSG_ID_CCCI_TTY_UL_DEQUEUE_REQ,               /* msg_id */
                      (struct local_para_struct *)cccitty_deq_req,  /* local_para_ptr */
                      NULL);                                        /* peer_buff_ptr */
            cccitty_trace(CCCI_TTY_TRACE, CCCI_TTY_MOD_UL, CCCI_TTY_TR_UL_SEND_DEQ, p_cccidev->dev_id);
        }else{
            CCCI_TTY_UNLOCK(p_cccidev->cccitty_mutex);
            /* there's MSG_ID_CCCI_TTY_UL_DEQUEUE_REQ message pending */
        }
    }
    //4 <5> Error Handling: reload RGPD number err_reload_cnt
    if (err_reload_cnt > 0){
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_UL_INVALID_PKT, p_cccidev->dev_id, err_reload_cnt, p_cccidev->ul_invalid_ttl_cnt);
        /* reset the rgpd content with HWO = 1*/
        num_alloc = cccitty_reset_ccci_comm_gpd_list(err_gpd_h, err_gpd_t);
    //    num_alloc = CCCITTY_GET_GPD_LIST_SIZE(err_gpd_h, err_gpd_t);
        if(num_alloc != err_reload_cnt){
            cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_TTYC_ERR_RGPD_LEAK, p_cccidev->dev_id, num_alloc, err_reload_cnt);
            EXT_ASSERT(num_alloc == err_reload_cnt, num_alloc, err_reload_cnt, 0);
        }
    
        err_reload_ior.next_request = NULL;
        err_reload_ior.first_gpd = err_gpd_h;
        err_reload_ior.last_gpd = err_gpd_t;
        /* reload the gpds */
        ccci_ret = p_cccitty->ccci_write_gpd(p_cccidev->ccci_ch.cccitty_ch_ul, &err_reload_ior, NULL);

        if(CCCI_SUCCESS != ccci_ret){
            /* NOTE!! might cause RGPD leackage here */
            cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_UL_CCCI_WRITE_FAIL,p_cccidev->dev_id, ccci_ret);
            qbmt_dest_q(err_reload_ior.first_gpd, err_reload_ior.last_gpd);
        }else{
            CCCI_TTY_LOCK(p_cccidev->cccitty_mutex);
            {
                 /* should not increase hwo_rgpd_cnt, since this is the RGPD belongs to other user */
                 p_cccidev->hwo_rgpd_cnt += num_alloc;
                 /* to prevent interrupted by SDIOCORE context*/
                 tmp = p_cccidev->hwo_rgpd_cnt;
            }            
            CCCI_TTY_UNLOCK(p_cccidev->cccitty_mutex);
            cccitty_trace(CCCI_TTY_TRACE, CCCI_TTY_MOD_UL, CCCI_TTY_TR_HIF_RGPD_RELOAD4,p_cccidev->dev_id, num_alloc, tmp);
        }
    }
    
    return;
}

/*!
 * @function        cccitty_ul_deq_hdr
 * @brief           MSG_ID_CCCI_TTY_UL_DEQUEUE_REQ message handler, deq hif_ul_q and callback to TTYcore
 *
 * @param pccci_dev [IN] pointer to cccitty device
 *
 * @return          void
 */
void cccitty_ul_deq_hdr(cccitty_dev_t *p_cccidev){
    cccitty_inst_t      *p_cccitty = cccitty_get_instance();
    kal_bool            need_memcpy = KAL_FALSE;
    kal_uint32          ttyc_rgpd_cnt, hif_ul_rgpd_cnt;
    kal_uint32          ul_count, deq_count;
    ccci_io_request_t   ul_ior, reload_ior;
    qbm_gpd             *hif_ul_q_pgpd_h, *hif_ul_q_pgpd_t;
    qbm_gpd             *ttyc_rgpd_q_pgpd_h, *ttyc_rgpd_q_pgpd_t;
    kal_uint32          num_alloc;//, to_alloc; 
    kal_int32           tmp;
    CCCI_RETURNVAL_T    ccci_ret;


    CCCI_TTY_LOCK(p_cccidev->cccitty_mutex);
    {
        p_cccidev->dev_ul_processing = KAL_FALSE;
    }
    CCCI_TTY_UNLOCK(p_cccidev->cccitty_mutex);

    ttyc_rgpd_cnt = p_cccidev->ttyc_rgpd_cnt - 1; /* reserved 1 for tail, like HIF Driver*/
    hif_ul_rgpd_cnt = p_cccidev->hif_ul_rgpd_cnt;
    ul_count = MIN(ttyc_rgpd_cnt, hif_ul_rgpd_cnt);
    
    if(ul_count == 0){
        /* Do nothing if there's no rgpd in ttyc_rgpd_q*/
        return;
    }

    cccitty_trace(CCCI_TTY_TRACE, CCCI_TTY_MOD_UL, CCCI_TTY_TR_RGPD_DEQ, 
                p_cccidev->dev_id, p_cccidev->ttyc_rgpd_cnt, p_cccidev->hif_ul_rgpd_cnt, ul_count);

    if(ttyc_rgpd_cnt!=0){
        /* if there's GPD in ttyc_rgpd_q, there should be a valid type defined*/
        if(CCCI_TTY_INVALID_GPD_TYPE == p_cccidev->ttyc_rgpd_type){
            cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_TTYC_RGPD_Q_TYPE_ERR, \
                p_cccidev->ccci_ch, CCCITTY_DEVID_TO_UARTP(p_cccidev->dev_id), p_cccidev->ttyc_rgpd_cnt, p_cccidev->ttyc_rgpd_type);
            EXT_ASSERT(KAL_FALSE, CCCI_TTY_INVALID_GPD_TYPE, p_cccidev->ttyc_rgpd_type, 0);
        }
    }

    EXT_ASSERT(CCCI_TTY_UL_BUF_TYPE == p_cccidev->hif_ul_rgpd_type, p_cccidev->ttyc_rgpd_type, 0, 0);

    need_memcpy = ( p_cccidev->hif_ul_rgpd_type == p_cccidev->ttyc_rgpd_type) ? (KAL_FALSE) : (KAL_TRUE);

    if(KAL_TRUE == need_memcpy){
        //4 <NOT support New Rx user>
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_TTYC_NEW_RX_ERR, \
             p_cccidev->ccci_ch, CCCITTY_DEVID_TO_UARTP(p_cccidev->dev_id), p_cccidev->ttyc_rgpd_cnt, p_cccidev->ttyc_rgpd_type);
        EXT_ASSERT(KAL_FALSE, need_memcpy, p_cccidev->ttyc_rgpd_type, 0);
    }
    ul_ior.next_request = NULL;
    reload_ior.next_request = NULL;
    
    //4 <1> dequeue hif_ul_q
    CCCI_TTY_LOCK(p_cccidev->cccitty_mutex);
    {
        deq_count = CCCIDEV_QBM_DEQ((void**)&p_cccidev->hif_ul_q_h, (void**)&p_cccidev->hif_ul_q_t, ul_count, (void**)&hif_ul_q_pgpd_h, (void**)&hif_ul_q_pgpd_t);
        EXT_ASSERT(deq_count == ul_count, deq_count, ul_count, 0);
        p_cccidev->hif_ul_rgpd_cnt -= ul_count;
    }
    CCCI_TTY_UNLOCK(p_cccidev->cccitty_mutex);
    QBM_DES_SET_NEXT(hif_ul_q_pgpd_t, NULL);
    
    //4 <2> dequeue ttyc_rgpd_q
    CCCI_TTY_LOCK(p_cccidev->cccitty_mutex);
    {
        deq_count = CCCIDEV_QBM_DEQ((void**)&p_cccidev->ttyc_rgpd_q_h, (void**)&p_cccidev->ttyc_rgpd_q_t, ul_count, (void**)&ttyc_rgpd_q_pgpd_h, (void**)&ttyc_rgpd_q_pgpd_t);
        EXT_ASSERT(deq_count == ul_count, deq_count, ul_count, 0);
        p_cccidev->ttyc_rgpd_cnt -= ul_count;
    }
    CCCI_TTY_UNLOCK(p_cccidev->cccitty_mutex);
    /* at least one tail rgpd will be in ttyc_rgpd_queue*/
    EXT_ASSERT(p_cccidev->ttyc_rgpd_cnt >= 1, p_cccidev->ttyc_rgpd_cnt, 0, 0);
    QBM_DES_SET_NEXT(hif_ul_q_pgpd_t, NULL);

    if(KAL_FALSE == need_memcpy){
        ul_ior.first_gpd = hif_ul_q_pgpd_h;
        ul_ior.last_gpd = hif_ul_q_pgpd_t;
//        /* Free the ttyc_rgpd_q dequeu entry, # of RGPDs = ul_count */
//        qbmt_dest_q(ttyc_rgpd_q_pgpd_h, ttyc_rgpd_q_pgpd_t);
    }else{
        //4 <NOT support New Rx user>
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_TTYC_NEW_RX_ERR, \
             p_cccidev->ccci_ch, CCCITTY_DEVID_TO_UARTP(p_cccidev->dev_id), p_cccidev->ttyc_rgpd_cnt, p_cccidev->ttyc_rgpd_type);
        EXT_ASSERT(KAL_FALSE, p_cccidev->dev_id, p_cccidev->ttyc_rgpd_type, 0);
    }

    //4 <4> p_cccitty->dcl_rx
    p_cccitty->dcl_rx(p_cccidev->tty_handler, MOD_CCCITTY, &ul_ior);
    //4 <5> Reload RGPD
    //to_alloc = ul_count;
    //num_alloc = qbmt_alloc_q_no_tail(CCCI_TTY_UL_BUF_TYPE, to_alloc, &reload_ior.first_gpd, &reload_ior.last_gpd);
    num_alloc = cccitty_reset_ccci_comm_gpd_list(ttyc_rgpd_q_pgpd_h, ttyc_rgpd_q_pgpd_t);
    if (num_alloc != ul_count)
    {
        /* just free ul_count RGPD in previous qbmt_dest_q, should be able to alloc the same number back */
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_TTYC_RGPD_LEAK, p_cccidev->dev_id, ul_count, num_alloc);
        EXT_ASSERT(KAL_FALSE, num_alloc, ul_count, 0);
    }
    reload_ior.first_gpd = ttyc_rgpd_q_pgpd_h;
    reload_ior.last_gpd = ttyc_rgpd_q_pgpd_t;
#ifdef __SDIOC_PULL_Q_ENH_DL__
    reload_ior.num_gpd = num_alloc; /* no use, just pass it */
#endif
    ccci_ret = p_cccitty->ccci_write_gpd(p_cccidev->ccci_ch.cccitty_ch_ul, &reload_ior, NULL);
    if(CCCI_SUCCESS != ccci_ret){
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_DEQ_CCCI_WRITE_FAIL,p_cccidev->dev_id, ccci_ret);
    }else{
        CCCI_TTY_LOCK(p_cccidev->cccitty_mutex);
        {
             p_cccidev->hwo_rgpd_cnt += num_alloc;
             /* to prevent interrupted by SDIOCORE context*/
             tmp = p_cccidev->hwo_rgpd_cnt;
        }            
        CCCI_TTY_UNLOCK(p_cccidev->cccitty_mutex);
        cccitty_trace(CCCI_TTY_TRACE, CCCI_TTY_MOD_UL, CCCI_TTY_TR_HIF_RGPD_RELOAD2,p_cccidev->dev_id, num_alloc, tmp);    
    }    
    return;
}

/*!
 * @function        cccitty_ttyc_hdr_cmd_assign_rx_ior
 * @brief           TTY Core UL RPGD reload command, TTY_CMD_ASSIGN_RX_IOR, handler
 *                  Reference cdcacm_ttyhdr_cmd_assign_rx_ior -> usbc_class_device_submit_io_request
 *                  Reference ccmni_ipc_dl
 * @param port      [IN] UART port number
 * @param p_ior     [IN] Reload UL RGPD io_request
 * @param ownerid   [IN] module_type for the one opening this port, ex. MOD_xxx
 *
 * @return          DCL_STATUS
 *                  STATUS_OK:   success
 *                  STATUS_FAIL: ccci_write_gpd fail
 */
DCL_STATUS cccitty_ttyc_hdr_cmd_assign_rx_ior(UART_PORT port, ccci_io_request_t *p_ior, module_type ownerid)
{
    cccitty_dev_t       *p_cccidev = cccitty_get_dev_instance(CCCITTY_UARTP_TO_DEVID(port));
    cccitty_inst_t      *p_cccitty = cccitty_get_instance();
    ccci_io_request_t   *p_curr_ior, *p_next_ior;
    ccci_io_request_t   reload_ior;
    kal_uint32          gpd_num, gpd_num_rec;
    qbm_gpd             *p_gpd_h, *p_gpd_t;
    cccitty_deq_req_t   *cccitty_deq_req;
    kal_uint32          to_alloc, num_alloc;
    kal_int32           tmp;
    kal_bool            first_reload = KAL_FALSE;
    CCCI_RETURNVAL_T    ccci_ret;

    if(!cccitty_dev_active(p_cccidev)){
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_ASSIGN_RX_IOR_STATE_ERR, p_cccidev->state);
        return STATUS_NOT_OPENED;
    }
    if(NULL == p_ior){
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_UL_RELOAD_NULL_IOR, port);
        return STATUS_OK;
    }
    if(NULL == p_ior->first_gpd){
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_UL_RELOAD_EMPTY_IOR, port);
        return STATUS_OK;
    }

    if(KAL_TRUE == p_cccidev->ttyc_rgpd_first_reload){
        first_reload = KAL_TRUE;
    }

    /*
    Reload RGPD to HIF before enqueue the RGPD to internal tty queue.
    Otherwise, RGPD may be returned while first reload is not finished yet.
    */
    //4 <1> 1st time Reload the same number RGPD to the HIF    
    if(first_reload){
        /* ASSERT if there's already RGPD loaded in HIF*/
        EXT_ASSERT(0 >= p_cccidev->hwo_rgpd_cnt, p_cccidev->hwo_rgpd_cnt, 0, 0);

        /* construct reload_ior for HIF reload*/
        to_alloc = p_cccidev->hif_ul_ttl_rgpd_cnt;
        reload_ior.next_request = NULL;
        num_alloc = qbmt_alloc_q_no_tail(CCCI_TTY_UL_BUF_TYPE, to_alloc, (void **)&reload_ior.first_gpd, (void **)&reload_ior.last_gpd);
        /* ASSERT cannot allocate enough RGPD, each TTY_CHANNEL should pre-allocate enough RGPD*/
        if (num_alloc != to_alloc)
        {
            cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_TTYC_RGPD_INIT_ERR, to_alloc, num_alloc);
            EXT_ASSERT(KAL_FALSE, to_alloc, num_alloc, 0);
        }
#ifdef __SDIOC_PULL_Q_ENH_DL__
        reload_ior.num_gpd = num_alloc;
#endif
        ccci_ret = p_cccitty->ccci_write_gpd(p_cccidev->ccci_ch.cccitty_ch_ul, &reload_ior, NULL);
        if(CCCI_SUCCESS != ccci_ret){
            cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_RLD_CCCI_WRITE_FAIL, ccci_ret);
            return STATUS_FAIL;
        }
        CCCI_TTY_LOCK(p_cccidev->cccitty_mutex);
        {
            p_cccidev->hwo_rgpd_cnt += num_alloc;
            /* to prevent interrupted by SDIOCORE context*/
            tmp = p_cccidev->hwo_rgpd_cnt;
            p_cccidev->ttyc_rgpd_first_reload = KAL_FALSE;
        }
        CCCI_TTY_UNLOCK(p_cccidev->cccitty_mutex);
        cccitty_trace(CCCI_TTY_TRACE, CCCI_TTY_MOD_UL, CCCI_TTY_TR_HIF_RGPD_RELOAD1,p_cccidev->dev_id, num_alloc, tmp);
    }
    
    //4 <2> check ttyc_rgpd_type
    if(CCCI_TTY_INVALID_GPD_TYPE == p_cccidev->ttyc_rgpd_type){
        /* if rgpd queue hasn't been initialized */
        p_cccidev->ttyc_rgpd_type = QBM_GET_TYPE(p_ior->first_gpd);
    }else{
        /* if rgpd type has been registered, new ior must match the type*/
        //4 <NOTE> only check the 1st gpd
        EXT_ASSERT(p_cccidev->ttyc_rgpd_type == QBM_GET_TYPE(p_ior->first_gpd), p_cccidev->ttyc_rgpd_type, QBM_GET_TYPE(p_ior->first_gpd), 0);
    }

    //4 <3> traverse the ior and queue all the gpd
    to_alloc = 0;
    p_curr_ior = (ccci_io_request_t*)p_ior;
    do {
        p_next_ior = p_curr_ior->next_request;
        CCCITTY_FIX_IOR_NULL_LAST(p_curr_ior);

        p_gpd_h = p_ior->first_gpd;
        p_gpd_t = p_ior->last_gpd;
        gpd_num = CCCITTY_GET_GPD_LIST_SIZE(p_gpd_h, p_gpd_t);
        to_alloc += gpd_num;
        
        CCCI_TTY_LOCK(p_cccidev->cccitty_mutex);
        {
            CCCITTY_QBM_ENQ(p_gpd_h, p_gpd_t, (void **)&p_cccidev->ttyc_rgpd_q_h, (void **)&p_cccidev->ttyc_rgpd_q_t);
            p_cccidev->ttyc_rgpd_cnt += gpd_num;
        }
        CCCI_TTY_UNLOCK(p_cccidev->cccitty_mutex);

        p_curr_ior = p_next_ior;
    } while ( p_curr_ior != NULL );

    //4 <4> check ttyc_rgpd_cnt matches ttyc_rgpd_q size
    CCCI_TTY_LOCK(p_cccidev->cccitty_mutex);
    {
        p_gpd_h = p_cccidev->ttyc_rgpd_q_h;
        p_gpd_t = p_cccidev->ttyc_rgpd_q_t;
        gpd_num_rec = p_cccidev->ttyc_rgpd_cnt;
        gpd_num = CCCITTY_GET_GPD_LIST_SIZE(p_gpd_h, p_gpd_t);
    }
    CCCI_TTY_UNLOCK(p_cccidev->cccitty_mutex);
    
    
    if(gpd_num_rec != gpd_num){
        /* warning the RGPD Q number is not match */
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_TTYC_RGPD_Q_NUM_ERR, gpd_num, gpd_num_rec);
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_TTYC_RGPD_Q_NUM_ERR_ACT1, gpd_num, gpd_num_rec);
    }

    //cccitty_trace(CCCI_TTY_TRACE, CCCI_TTY_MOD_UL, CCCI_TTY_TR_RGPD_RELOAD, CCCITTY_UARTP_TO_DEVID(port), to_alloc, p_cccidev->ttyc_rgpd_cnt);
    cccitty_trace(CCCI_TTY_TRACE, CCCI_TTY_MOD_UL, CCCI_TTY_TR_RGPD_RELOAD, CCCITTY_UARTP_TO_DEVID(port), to_alloc, gpd_num_rec);
       
    //4 <5> if ( hif_ul_rgpd_cnt != 0 ), sends MSG_ID_CCCI_TTY_UL_DEQUEUE_REQ to MOD_CCCITTY
    if(p_cccidev->hif_ul_rgpd_cnt){
        if(KAL_FALSE == p_cccidev->dev_ul_processing){
            CCCI_TTY_LOCK(p_cccidev->cccitty_mutex);
            {
                p_cccidev->dev_ul_processing = KAL_TRUE;
            }
            CCCI_TTY_UNLOCK(p_cccidev->cccitty_mutex);
            cccitty_deq_req = (cccitty_deq_req_t *)construct_local_para(sizeof(cccitty_deq_req_t), 0);
            cccitty_deq_req->dev = p_cccidev;
            msg_send6(MOD_CCCITTY,                                  /* src_mod_id */
                      MOD_CCCITTY,                                  /* dest_mod_id */
                      0,                                            /* sap_id */
                      MSG_ID_CCCI_TTY_UL_DEQUEUE_REQ,               /* msg_id */
                      (struct local_para_struct *)cccitty_deq_req,  /* local_para_ptr */
                      NULL);                                        /* peer_buff_ptr */
        }else{
            /* there's MSG_ID_CCCI_TTY_UL_DEQUEUE_REQ message pending */
        }
    }
    return STATUS_OK;
}


/*!
 * @function        cccitty_ttyc_hdr_cmd_clr_rx_buf
 * @brief           Rx Flush handler for CCCI TTY
 *                  Reference cdcacm_ttyhdr_cmd_clr_rx_buf
 * @param port      [IN] UART port number
 * @param ownerid   [IN] module_type for the one opening this port, ex. MOD_xxx
 * @param check_own [IN] check if the ownerid owns the p_cccidev
 *
 * @return          DCL_STATUS, always STATUS_OK
 */
DCL_STATUS cccitty_ttyc_hdr_cmd_clr_rx_buf(UART_PORT port, module_type ownerid, kal_bool check_own)
{
    cccitty_dev_t       *p_cccidev = cccitty_get_dev_instance(CCCITTY_UARTP_TO_DEVID(port));
    cccitty_inst_t      *p_cccitty = cccitty_get_instance();
    qbm_gpd             *p_gpd_h, *p_gpd_t;
    ccci_io_request_t   ior;
    CCCI_RETURNVAL_T    ccci_ret;
    kal_uint32          gpd_num, gpd_num_rec; 
    kal_int32           tmp;

    if(KAL_TRUE == check_own){
        EXT_ASSERT(ownerid == p_cccidev->ownerid, ownerid, p_cccidev->ownerid, port);
    }
    EXT_ASSERT(((p_cccidev->state > CCCI_TTY_DEV_DETACHED) && (p_cccidev->state < CCCI_TTY_DEV_STATE_CNT)), p_cccidev->state, port, ownerid);

    //4 <1> Clean up the TTY core RGPD queue, ttyc_rgpd_q , by p_cccitty->dcl_rx
    /* clean up the queue */
    CCCI_TTY_LOCK(p_cccidev->cccitty_mutex);
    {
        p_gpd_h = p_cccidev->ttyc_rgpd_q_h;
        p_gpd_t = p_cccidev->ttyc_rgpd_q_t;
        p_cccidev->ttyc_rgpd_q_h   = NULL;
        p_cccidev->ttyc_rgpd_q_t   = NULL;
        gpd_num_rec = p_cccidev->ttyc_rgpd_cnt;
        p_cccidev->ttyc_rgpd_cnt = 0;
        p_cccidev->ttyc_rgpd_type = CCCI_TTY_INVALID_GPD_TYPE; //assign an invalid, set according to next rgpd reload        
    }
    CCCI_TTY_UNLOCK(p_cccidev->cccitty_mutex);

    gpd_num = CCCITTY_GET_GPD_LIST_SIZE(p_gpd_h, p_gpd_t);    
    if(gpd_num_rec != gpd_num){
        /* warning gpd count not match*/
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_TTYC_RGPD_Q_NUM_ERR, gpd_num, gpd_num_rec);
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_TTYC_RGPD_Q_NUM_ERR_ACT2, gpd_num, gpd_num_rec);
    }

    if( 0!=gpd_num ){
        /* construct ior */
        ior.next_request = NULL;
        ior.first_gpd = p_gpd_h;
        ior.last_gpd = p_gpd_t;
        QBM_DES_SET_NEXT(p_gpd_t, NULL);
        p_cccitty->dcl_rx(p_cccidev->tty_handler, MOD_CCCITTY, &ior); //DclSerialPort_DrvRx
    }

    //4 <2> Clean up the HIF uplink queue, hif_ul_q, by ccci_write_gpd
    /* clean up the queue */
    CCCI_TTY_LOCK(p_cccidev->cccitty_mutex);
    {
        p_gpd_h = p_cccidev->hif_ul_q_h;
        p_gpd_t = p_cccidev->hif_ul_q_t;
        p_cccidev->hif_ul_q_h   = NULL;
        p_cccidev->hif_ul_q_t   = NULL;
        gpd_num_rec = p_cccidev->hif_ul_rgpd_cnt;
        p_cccidev->hif_ul_rgpd_cnt = 0;
    }
    CCCI_TTY_UNLOCK(p_cccidev->cccitty_mutex);

    gpd_num = CCCITTY_GET_GPD_LIST_SIZE(p_gpd_h, p_gpd_t);    
    if(gpd_num_rec != gpd_num){
        /* warning gpd count not match*/
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_HIF_UL_Q_NUM_ERR, gpd_num, gpd_num_rec);
    }
    
    if( 0!=gpd_num ){
        /* construct ior */
        ior.next_request = NULL;
        ior.first_gpd = p_gpd_h;
        ior.last_gpd = p_gpd_t;
        QBM_DES_SET_NEXT(p_gpd_t, NULL);
#ifdef __SDIOC_PULL_Q_ENH_DL__
        ior.num_gpd = gpd_num;
#endif
        ccci_ret = p_cccitty->ccci_write_gpd(p_cccidev->ccci_ch.cccitty_ch_ul, &ior, NULL); //ccci_write_gpd
        EXT_ASSERT(CCCI_SUCCESS == ccci_ret, ccci_ret, 0, 0); /* otherwise the input parameter is incorrect */
    }
    
    CCCI_TTY_LOCK(p_cccidev->cccitty_mutex);
    {
        /* since reload all the RGPD reloaded to HIF, RPGD count reset to the 1st reload state*/
        p_cccidev->hwo_rgpd_cnt = p_cccidev->hif_ul_ttl_rgpd_cnt;
        /* to prevent interrupted by SDIOCORE context*/
        tmp = p_cccidev->hwo_rgpd_cnt;
    }
    CCCI_TTY_UNLOCK(p_cccidev->cccitty_mutex);
    
    cccitty_trace(CCCI_TTY_TRACE, CCCI_TTY_MOD_UL, CCCI_TTY_TR_HIF_RGPD_RELOAD3,p_cccidev->dev_id, gpd_num, tmp);
    
    return STATUS_OK;
}

/*!
 * @function        cccitty_ccci_dummy_cb
 * @brief           This API is the dummy function for CCCI_TTY CCCI channels doesn't need callback
 *                  Should not be called during execution
 *
 * @param channel   [IN] CCCI channel for this callback
 * @param io_request[IN] pointer to the ior
 *
 * @return          void
 */
void cccitty_ccci_dummy_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* io_request){
    /* dummy function for backword compatible to MT6280 CCCI*/
    cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_MISC, CCCI_TTY_TR_DATA_DUMMY_CH_TRIG, channel);
    return;
}
