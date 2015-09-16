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
 *   ccci_debug.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Implements the CCCI debug API
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
 * [CCCI] Fix Klocwork warnings
 *
 * removed!
 * removed!
 * [CCCI] Fix Klocwork warnings
 *
 * removed!
 * removed!
 * [CCCI] Fix Klocwork warnings
 *
 * removed!
 * removed!
 * 	[CCCI Debug] Change data type for writing exception share memory
 *
 * removed!
 * removed!
 * [CCCI] Fix Modis no share memory (connect ELT)
 *
 * removed!
 * removed!
 * [CCCI] Remove the ccci seq info in AP polling MD status
 *
 * removed!
 * removed!
 * [CCCI] Fix Modis build error
 *
 * removed!
 * removed!
 * [CCCI] Fix MT6752 build fail
 *
 * removed!
 * removed!
 * [CCCI] Fix MoDIS build error
 *
 ****************************************************************************/
#include "ccci_if.h"
#include "ccci_common.h"
#include "cccidev_qbm.h"
#include "ccci_debug.h"
#include "init.h"
#include "hif_svc_msgid.h"

#if defined(__MTK_TARGET__)
#if defined(__HIF_SDIO_SUPPORT__)
#include "hif_sdio.h"
#include "hifsdio_qmu_except.h"
#elif defined(__HIF_CLDMA_SUPPORT__)
#include "cldmacore_except_if.h" 
#elif defined(__CCIFCORE_SUPPORT__)
#include "ccifcore_except_if.h"     
#endif
#endif

// switch to open/close seq trace capability
#if defined(__MTK_TARGET__) || defined(ATEST_SYS_CCCI)
#define CCCI_DEBUG_SEQ_TRACE_ENABLE
#endif

#ifdef CCCI_DEBUG_SEQ_TRACE_ENABLE
static kal_uint16 ccci_debug_seq_num[CCCI_PEER_ID_MAX][CCCI_MAX_CHANNEL];
static CCCI_DEBUG_GET_STATUS_CALLBACK ccci_debug_get_status_cb[CCCI_DEBUG_GET_STATUS_MODULE_MAX] = {0};
#define MAX_CCCI_DEBUG_STATUS_SIZE 3584
static kal_uint32 g_ccci_debug_status[MAX_CCCI_DEBUG_STATUS_SIZE] = {0};
kal_uint8 *ccci_debug_status = (kal_uint8 *) g_ccci_debug_status;
static ccci_io_request_t ccci_debug_io_request;

#define CCCI_DEBUG_STATUS_GPD_TYPE QBM_TYPE_CCCI_COMM

#define CCCI_DEBUG_BUFF_RECORD_SIZE 16 // ccci header 
#define CCCI_DEBUG_BUFF_HDR_SIZE 16
#define CCCI_DEBUG_BUFF_GUARD_PATTERN 0xCCCDEBFF
#define CCCI_DEBUG_BUFF_EXCEP_GUARD_PATTERN 0xEECCDBFF
#define CCCI_DEBUG_BUFF_EXCEP_SIZE 512

kal_uint32 ccci_debug_buff;
kal_uint8 *ccci_debug_buff_addr;
kal_uint32 ccci_debug_buff_size;
CCCI_EXCEP_MEMORY_TYPE ccci_debug_buff_type = CCCI_EXCEP_MEMORY_TYPE_MAX;

#define CCCI_DEBUG_FEATURE_CCCI_ALL_ON 0xFFFFFFFF // ccci debug feature is 4 bytes
#define CCCI_DEBUG_FEATURE_CCCI_SEQ    0x1 // bit0 is ccci seq on
#define CCCI_DEBUG_FEATURE_CCCI_STATUS 0x2 // bit1 is ccci status on
static kal_uint32 ccci_debug_feature = CCCI_DEBUG_FEATURE_CCCI_ALL_ON; // default all feature are all on.

#endif
extern kal_bool INT_QueryExceptionStatus(void);

/*!
 * @function        ccci_debug_add_seq
 * @brief           This function provides to add the sequence number to CCCI header. The sequence is maintained by CCCI. 
 * @param
 * bufp- the CCCI header pointer
 * assert_bit V If you want to AP assert MD when the seq num is wrong, input CCCI_DEBUG_ASSERT_BIT. If not, input CCCI_DEBUG_NOT_ASSERT_BIT
 * @return          
 * CCCI_SUCCESS : Add sequence successfully
 * CCCI_FAIL: Add sequence fail
 */
kal_int32 ccci_debug_add_seq(CCCI_BUFF_T *bufp, kal_uint32 assert_bit)
{
#ifdef CCCI_DEBUG_SEQ_TRACE_ENABLE
    kal_uint8 peer_id;
    kal_uint32 peer_channel,logic_channel;

    // Not support the feature
    if((ccci_debug_feature & CCCI_DEBUG_FEATURE_CCCI_SEQ) == 0){
        return CCCI_SUCCESS;
    }
    if(bufp == NULL)
        return CCCI_FAIL;

    // Get channel info
    logic_channel   = bufp->channel;
    peer_id 		= GET_PEER_ID(logic_channel);
	peer_channel	= GET_PEER_CHANNEL(logic_channel);
    // Add seq & assert bit to ccci header
    CCCI_DEBUG_CLR_SEQ_IN_CH(bufp->channel);
    CCCI_DEBUG_ADD_SEQ_IN_CH(bufp->channel, ccci_debug_seq_num[peer_id][peer_channel]);
    CCCI_DEBUG_ADD_ASSERT_BIT_IN_CH(bufp->channel, assert_bit);
    // increase expected seq
    CCCI_DEBUG_INCREASE_SEQ_NUM(ccci_debug_seq_num[peer_id][peer_channel]);
    if(KAL_TRUE != kal_query_systemInit())
        ccci_data_trace(CCCI_DEBUG_ADD_SEQ_TRACE, bufp->channel, bufp->data[0], bufp->data[1], bufp->channel, bufp->reserved);
    // record data in memory
    ccci_debug_write_record((void *)bufp);
#endif
    return CCCI_SUCCESS;
}

/*!
 * @function        ccci_debug_check_seq
 * @brief           This function provides to check the sequence number to CCCI header. The sequence is maintained by CCCI. If the seq is wrong, will check the assert bit to assert MD.
 * @param
 * bufp- the CCCI header pointer
 * @return          
 * CCCI_SUCCESS : Check sequence successfully
 * CCCI_FAIL: Check sequence fail
 */
kal_int32 ccci_debug_check_seq(CCCI_BUFF_T *bufp)
{
#ifdef CCCI_DEBUG_SEQ_TRACE_ENABLE
    kal_uint8 peer_id;
    kal_uint32 peer_channel,logic_channel;
    kal_uint32 expected_seq_num, current_seq_num;
    // Not support the feature
    if((ccci_debug_feature & CCCI_DEBUG_FEATURE_CCCI_SEQ) == 0){
        return CCCI_SUCCESS;
    }
    if(bufp == NULL)
        return CCCI_FAIL;
    
    if(KAL_TRUE != kal_query_systemInit())
        ccci_data_trace(CCCI_DEBUG_CHECK_SEQ_TRACE, bufp->channel, bufp->data[0], bufp->data[1], bufp->channel, bufp->reserved);
    // record data in memory
    ccci_debug_write_record((void *)bufp); 
    // Get channel info
    logic_channel   = bufp->channel;
    peer_id 		= GET_PEER_ID(logic_channel);
	peer_channel	= GET_PEER_CHANNEL(logic_channel);
    current_seq_num = (kal_uint32) CCCI_DEBUG_GET_SEQ_IN_CH(logic_channel);
    expected_seq_num = (kal_uint32) ccci_debug_seq_num[peer_id][peer_channel];
    // check excepted & current seq
    if ( expected_seq_num != current_seq_num){ // seq is wrong
        if(CCCI_DEBUG_GET_ASSERT_BIT_IN_CH(logic_channel) == CCCI_DEBUG_ASSERT_BIT){
             // put info to share memory
             ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_DEBUG_CHANNEL, &logic_channel);
             ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_DEBUG_CURRENT_SEQ_NUM, (void *)&current_seq_num);
             ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_DEBUG_EXPECTED_SEQ_NUM, (void *)&expected_seq_num);

             // Inform AP
             if(INT_QueryExceptionStatus() == KAL_TRUE){// in exception mode
#if defined(__MTK_TARGET__)
#if defined(__HIF_SDIO_SUPPORT__)
                 hifsdio_except_write_seq_to_mb(current_seq_num);
                 hifsdio_except_CCCI_wrong_seq_int();
#elif defined(__HIF_CLDMA_SUPPORT__)
                 hifcldma_write_seq(current_seq_num); 
                 hifcldma_seq_err_D2H_int();
#elif defined(__CCIFCORE_SUPPORT__)
                 wccif_write_seq(current_seq_num); 
                 hifccif_seq_err_D2H_int();
#endif
#endif
             }
             else{
                 EXT_ASSERT_DUMP(KAL_FALSE, bufp->channel, current_seq_num, expected_seq_num,(void *)bufp);
             }
        }          
    }
    // increase expected seq
    CCCI_DEBUG_INCREASE_SEQ_NUM(ccci_debug_seq_num[peer_id][peer_channel]);
#endif
    return CCCI_SUCCESS;
}

/*!
 * @function       ccci_debug_reset_seq_data
 * @brief           This function reset will all ccci seq
 * @param
 * NA
 * @return          
 * NA
 */
void ccci_debug_reset_seq_data()
{
#ifdef CCCI_DEBUG_SEQ_TRACE_ENABLE
    kal_uint32 peer_id,peer_channel;
    for(peer_id =0 ; peer_id < CCCI_PEER_ID_MAX; peer_id++)
        for(peer_channel =0 ; peer_channel < CCCI_MAX_CHANNEL; peer_channel++)
            ccci_debug_seq_num[peer_id][peer_channel] = 0;
#endif
}

/*!
 * @function       ccci_debug_get_status_register
 * @brief           This function provides to register the callback function to collect modules status
 *
 * @param
 * module_id - the index of module, defined in ccci_if.h
 * funp V the callback function, the prototype is as below:
 * typedef kal_uint32 (*CCCI_DEBUG_GET_STATUS_CALLBACK)(kal_uint32 *write_ptr, kal_uint32 available_size);
 *   CCCI will input the write ptr address of CCCI status buffer and available size of CCCI status buffer (remaining size of one gpd), you must return the used size after you wrote in CCCI status buffer.  
 * @return          
 * CCCI_SUCCESS : Register successfully
 * CCCI_FAIL: Register fail
 */
kal_uint32 ccci_debug_get_status_register(CCCI_DEBUG_GET_STATUS_MODULE module_id, CCCI_DEBUG_GET_STATUS_CALLBACK funp)
{
#ifdef CCCI_DEBUG_SEQ_TRACE_ENABLE
    if(module_id > CCCI_DEBUG_GET_STATUS_MODULE_MAX || funp== NULL)
        return CCCI_FAIL;
    
    ccci_debug_get_status_cb[module_id] = funp;
#endif
    return CCCI_SUCCESS;
}

/*!
 * @function       ccci_debug_get_status_worker
 * @brief            This function collect all modules  status to one gpd if the module already register callback function , and will send one gpd to AP. 
 *                      User should NOT call this function, the function is triggered by ccci debug channel rx callback.
 * @param
 * NA
 * @return          
 * NA
 */
kal_uint32 ccci_debug_get_status_worker()
{
#ifdef CCCI_DEBUG_SEQ_TRACE_ENABLE
    kal_uint32 i =0;
    kal_uint32 avail_size, total_size;
    kal_uint32 return_size =0;
    kal_uint32 align_len=0;
    kal_uint32 *current_ptr;
    qbm_gpd    *tgpd, *tbd;
    CCCI_BUFF_T *ccci_buff;
    ccci_io_request_t *ior;
    kal_uint32 ccci_ret;

    ccci_trace(CCCI_TRACE, CCCI_MOD_DEBUG, CCCI_TR_DEBUG_GETSTATUS_START);
    ior = &ccci_debug_io_request;
	EXT_ASSERT(ior->first_gpd && ior->last_gpd, (kal_uint32)ior->first_gpd, (kal_uint32)ior->last_gpd, ior->num_gpd);
    // Not support the feature
    if((ccci_debug_feature & CCCI_DEBUG_FEATURE_CCCI_STATUS) == 0){
        qbmt_dest_q(ior->first_gpd,ior->last_gpd);
        return CCCI_FAIL;
    }
    // ROME E1 need to convert non-cacheable address for solving cache coherence
#if defined(MT6595) && defined(__MTK_TARGET__)
    SW_SECVERSION ver = INT_SW_SecVersion();
    if(SW_SEC_0 == ver){
         ccci_debug_status = (kal_uint8 *)((kal_uint32)ccci_debug_status & 0x0FFFFFFF);
    }
#endif

    kal_mem_set((void*)ccci_debug_status, 0, sizeof(ccci_debug_status));
    // collect all ccci debug info
    avail_size = MAX_CCCI_DEBUG_STATUS_SIZE;
    current_ptr = (kal_uint32 *) ccci_debug_status;
    tgpd = ior->first_gpd;
	tbd = QBM_DES_GET_DATAPTR(tgpd);
    QBM_DES_SET_DATAPTR(tbd,current_ptr);
    // collect all ccci modules
    for(i=0; i< CCCI_DEBUG_GET_STATUS_MODULE_MAX; i++){
        if(ccci_debug_get_status_cb[i]){ // not null
            *current_ptr = CCCI_DEBUG_STATUS_GUARD_PATTERN_START(i);
            current_ptr++;
            // execute cb funp
            return_size = ccci_debug_get_status_cb[i](current_ptr, avail_size);
            align_len = CCCI_DEBUG_4BYTE_ALIGN(return_size) / sizeof(current_ptr); // 4bytes align
            current_ptr += align_len;
            *current_ptr = CCCI_DEBUG_STATUS_GUARD_PATTERN_START(i);
            current_ptr++;
            avail_size -= (CCCI_DEBUG_4BYTE_ALIGN(return_size) + 2*sizeof(kal_uint32)); // 4bytes align + 2 guard patterns

            // no available size
            if(avail_size <= 0)
                EXT_ASSERT(KAL_FALSE, avail_size, 0 ,0);
        }
    }
    total_size = MAX_CCCI_DEBUG_STATUS_SIZE - avail_size;
    
    QBM_DES_SET_EXTLEN(tgpd, sizeof(CCCI_BUFF_T));
    /* Store the DL CCCI header in the GPD extention part */
    ccci_buff = (CCCI_BUFF_T *)QBM_DES_GET_EXT(tgpd);
    
    ccci_buff->data[1]  = total_size;
    ccci_buff->channel  = CCCI_DEBUG_STATUS_CHANNEL_TX;
    ccci_debug_add_seq(ccci_buff, CCCI_DEBUG_ASSERT_BIT); // add ccci seq

    QBM_DES_SET_DATALEN(tbd, total_size);    
    QBM_DES_SET_DATALEN(tgpd, total_size);
    qbm_cal_set_checksum((kal_uint8 *)tbd);
    qbm_cal_set_checksum((kal_uint8 *)tgpd);
    QBM_CACHE_FLUSH(tbd->p_data_tbd, total_size);
    QBM_CACHE_FLUSH(tbd, sizeof(qbm_gpd));
    QBM_CACHE_FLUSH(tgpd, sizeof(qbm_gpd));
    QBM_CACHE_FLUSH(ccci_buff, sizeof(CCCI_BUFF_T));
   
    // write ccci debug info in one gpd to ap
    ccci_ret = ccci_write_gpd(CCCI_DEBUG_STATUS_CHANNEL_TX, ior, NULL);
    if(ccci_ret == CCCI_FAIL){
        ccci_trace(CCCI_ERR, CCCI_MOD_DEBUG, CCCI_TR_DEBUG_GETSTATUS_WRITE_FAIL);
        return CCCI_FAIL;
    }
    else{
        ccci_trace(CCCI_TRACE, CCCI_MOD_DEBUG, CCCI_TR_DEBUG_GETSTATUS_DONE);
    }
    // reset ccci_debug_io_request
    kal_mem_set((void *)&ccci_debug_io_request, 0, sizeof(ccci_debug_io_request));
#endif
    return CCCI_SUCCESS;
}

/*!
 * @function       ccci_debug_write_record
 * @brief            Save 16bytes ccci header in memory
 * @param
 * NA
 * @return          
 * CCCI SUCCESS or CCCI FAIL
 */
kal_int32 ccci_debug_write_record(void *record_ptr)
{
#ifdef CCCI_DEBUG_SEQ_TRACE_ENABLE
    static kal_uint32 add_ccci_debug_header =0;
    static kal_uint32 add_ccci_debug_num =0, add_ccci_debug_excep_num =0;
    static kal_uint8 *ccci_debug_buff_current_addr, *ccci_debug_buff_excep_current_addr;
    static ccci_debug_record_hdr_t *ccci_debug_record_hdr, *ccci_debug_record_excep_hdr;
    kal_uint32 get_shm_ret;
    // can't write to memory before CCCI HS1
    if(record_ptr == NULL || get_ccci_boot_state() < CCCI_HAL_INIT)
        return CCCI_FAIL;
    // set ccci debug record header
    if(add_ccci_debug_header ==0){
        add_ccci_debug_header = 1;
        // get memory
        get_shm_ret = ccci_excep_query_shm(CCCI_EXCEP_MEMORY_REGION_CCCI_SEQ_DEBUG, &ccci_debug_buff, &ccci_debug_buff_size, &ccci_debug_buff_type);
        ASSERT(get_shm_ret == CCCI_SUCCESS);
        ccci_debug_buff_addr = (kal_uint8 *)ccci_debug_buff;
		EXT_ASSERT(ccci_debug_buff_addr != NULL,0,0,0);
        EXT_ASSERT(ccci_debug_buff_size != 0,ccci_debug_buff_size,0,0);
        // normal record
        ccci_debug_record_hdr = (ccci_debug_record_hdr_t *)ccci_debug_buff_addr;
        ccci_debug_record_hdr->start_pattern = CCCI_DEBUG_BUFF_GUARD_PATTERN;
        ccci_debug_record_hdr->number  = add_ccci_debug_num;
        ccci_debug_record_hdr->end_pattern = CCCI_DEBUG_BUFF_GUARD_PATTERN;
        ccci_debug_buff_current_addr = ccci_debug_buff_addr + CCCI_DEBUG_BUFF_HDR_SIZE;
        // exception record
        ccci_debug_record_excep_hdr = (ccci_debug_record_hdr_t *)(ccci_debug_buff_addr + ccci_debug_buff_size - CCCI_DEBUG_BUFF_EXCEP_SIZE);
        ccci_debug_record_excep_hdr->start_pattern = CCCI_DEBUG_BUFF_EXCEP_GUARD_PATTERN;
        ccci_debug_record_excep_hdr->number  = add_ccci_debug_num;
        ccci_debug_record_excep_hdr->end_pattern = CCCI_DEBUG_BUFF_EXCEP_GUARD_PATTERN;
        ccci_debug_buff_excep_current_addr = ccci_debug_buff_addr + ccci_debug_buff_size - CCCI_DEBUG_BUFF_EXCEP_SIZE + CCCI_DEBUG_BUFF_HDR_SIZE;
    }
    if(INT_QueryExceptionStatus() == KAL_FALSE){ // in polling or normal mode
        // cycle case 
        if(ccci_debug_buff_current_addr + CCCI_DEBUG_BUFF_RECORD_SIZE >= 
           ccci_debug_buff_addr + ccci_debug_buff_size - CCCI_DEBUG_BUFF_EXCEP_SIZE){
            ccci_debug_buff_current_addr = ccci_debug_buff_addr + CCCI_DEBUG_BUFF_HDR_SIZE;
            add_ccci_debug_num = 0;     
        }
        if(ccci_debug_buff_current_addr == NULL)
            return CCCI_FAIL;
        // copy data to memory
        ccci_debug_record_hdr->number  = add_ccci_debug_num++; 
        ccci_debug_record_hdr->current_addr= (kal_uint32)ccci_debug_buff_current_addr;
        kal_mem_cpy((void *)ccci_debug_buff_current_addr, (void *) record_ptr, CCCI_DEBUG_BUFF_RECORD_SIZE);

        ccci_debug_buff_current_addr += CCCI_DEBUG_BUFF_RECORD_SIZE;
    }
    else { // in exception mode
        // cycle case 
        if(ccci_debug_buff_excep_current_addr + CCCI_DEBUG_BUFF_RECORD_SIZE >= 
           ccci_debug_buff_addr + ccci_debug_buff_size){
            ccci_debug_buff_excep_current_addr = ccci_debug_buff_addr + ccci_debug_buff_size - CCCI_DEBUG_BUFF_EXCEP_SIZE + CCCI_DEBUG_BUFF_HDR_SIZE;
            add_ccci_debug_excep_num = 0;     
        }
        if(ccci_debug_buff_excep_current_addr == NULL)
            return CCCI_FAIL;
        // copy data to memory
        ccci_debug_record_excep_hdr->number  = add_ccci_debug_excep_num++; 
        ccci_debug_record_excep_hdr->current_addr= (kal_uint32)ccci_debug_buff_excep_current_addr;
        kal_mem_cpy((void *)ccci_debug_buff_excep_current_addr, (void *) record_ptr, CCCI_DEBUG_BUFF_RECORD_SIZE);

        ccci_debug_buff_excep_current_addr += CCCI_DEBUG_BUFF_RECORD_SIZE;
    }
#endif
    return CCCI_SUCCESS;
}

/*!
 * @function       ccci_debug_ap_force_assert_md
 * @brief            This function is triggered by HIF when HIF receive a sw int
 * @param
 * NA
 * @return          
 * NA
 */
void ccci_debug_ap_force_assert_md(void)
{
#ifdef CCCI_DEBUG_SEQ_TRACE_ENABLE
    // Not support all the ccci feature
    if((ccci_debug_feature & CCCI_DEBUG_FEATURE_CCCI_ALL_ON) == 0){
        return;
    }
    ASSERT(0);
#endif
}

/*!
 * @function       ccci_debug_tx_cb
 * @brief            CCCI debug channel tx callback
 * @param
 * NA
 * @return          
 * NA
 */
void ccci_debug_tx_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* io_request)
{
    // Not tx cb
    ccci_trace(CCCI_ERR, CCCI_MOD_DEBUG, CCCI_TR_DEBUG_TX_CB, channel);
}

/*!
 * @function       ccci_debug_rx_cb
 * @brief            CCCI debug channel rx callback
 * @param
 * NA
 * @return          
 * NA
 */
void ccci_debug_rx_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* io_request)
{      
#ifdef CCCI_DEBUG_SEQ_TRACE_ENABLE 
    qbm_gpd             *first_gpd = NULL;
    qbm_gpd             *last_gpd  = NULL;
    ccci_io_request_t   *curr_ior;
    ccci_io_request_t   *next_ior;
    kal_uint32          ul_gpd_num = 0;
    ccci_trace(CCCI_TRACE, CCCI_MOD_DEBUG, CCCI_TR_DEBUG_RX_CB_START, channel);
    // reset rgpd from rx callback
    for (curr_ior = io_request; curr_ior; curr_ior = next_ior) {
        next_ior  = curr_ior->next_request;
        first_gpd = curr_ior->first_gpd;
        last_gpd  = curr_ior->last_gpd;
        ccci_debug_check_seq((CCCI_BUFF_T *)CCCIDEV_GET_QBM_DATAPTR(first_gpd)); // check ccci seq
        if (KAL_TRUE != kal_query_systemInit()){ 
            /* [Normal Mode] */
            ul_gpd_num = CCCIDEV_RST_CCCI_COMM_GPD_LIST(first_gpd, last_gpd);
            EXT_ASSERT(CCCI_DEBUG_RELOAD_GPD_COUNT == ul_gpd_num, 
                       ul_gpd_num, (kal_uint32) first_gpd, (kal_uint32) last_gpd);
        }
    } 
    // set ior
    ccci_debug_io_request.first_gpd = first_gpd;
    ccci_debug_io_request.last_gpd = last_gpd;
    ccci_debug_io_request.num_gpd = CCCI_DEBUG_RELOAD_GPD_COUNT;
    EXT_ASSERT(ccci_debug_io_request.first_gpd != NULL , channel, 0, 0);

    // send ilm to trigger return md status to AP
    msg_send4(kal_get_active_module_id(), MOD_CCCI, 0, MSG_ID_CCCI_DEBUG_QUERY_MD_STATUS);

    ccci_trace(CCCI_TRACE, CCCI_MOD_DEBUG, CCCI_TR_DEBUG_RX_CB_DONE, channel);
#endif
}

extern kal_uint32 tst_cur_timestamp;
kal_uint32 ccci_debug_get_status_L1Time_funp(kal_uint32 *write_ptr, kal_uint32 available_size)
{
#ifdef CCCI_DEBUG_SEQ_TRACE_ENABLE
    kal_uint32 l1_time;
    l1_time = tst_cur_timestamp;
    kal_mem_cpy((void *) write_ptr , (void *)&l1_time,sizeof(kal_uint32));
    return sizeof(kal_uint32);
#endif
}

kal_uint32 ccci_debug_get_status_ccciseq_funp(kal_uint32 *write_ptr, kal_uint32 available_size)
{
#ifdef CCCI_DEBUG_SEQ_TRACE_ENABLE
    kal_mem_cpy((void *) write_ptr , (void *)ccci_debug_seq_num, sizeof(ccci_debug_seq_num));
    return sizeof(ccci_debug_seq_num);
#endif
}

/*!
 * @function       ccci_debug_set_feature
 * @brief            This function sets ccci debug feature option
 * @param
 * NA
 * @return          
 * NA
 */
void ccci_debug_set_feature()
{
#ifdef CCCI_DEBUG_SEQ_TRACE_ENABLE
    kal_int32 feature_support =0;
    feature_support = ccci_misc_data_feature_support(CCMSG_ID_MISCINFO_CCCI, sizeof(ccci_debug_feature), &ccci_debug_feature);
    if(feature_support == CCCI_MISC_INFO_NOT_EXIST || feature_support == CCCI_MISC_INFO_NOT_SUPPORT)
        ccci_debug_feature =0;
#endif
}

/*!
 * @function       ccci_debug_init
 * @brief            This function initialize the ccci debug channel 
                        User should NOT call this function, this function is triggered by lte_ccci_hw_init() in ccci_hmu.c
 * @param
 * NA
 * @return          
 * NA
 */
kal_bool ccci_debug_init()
{
#ifdef CCCI_DEBUG_SEQ_TRACE_ENABLE
    CCCI_RETURNVAL_T    ccci_ret;    
    // Init tx channel
    ccci_ret = ccci_init_gpdior(CCCI_DEBUG_STATUS_CHANNEL_TX,ccci_debug_tx_cb);
    if(CCCI_IN_USE == ccci_ret){
        /* channel has been registered in normal process, deinit and reinit */
        ccci_deinit(CCCI_DEBUG_STATUS_CHANNEL_TX);
        ccci_ret = ccci_init_gpdior(CCCI_DEBUG_STATUS_CHANNEL_TX,ccci_debug_tx_cb);
    }
    ASSERT(CCCI_SUCCESS == ccci_ret);
    // Init rx channel
    ccci_ret = ccci_init_gpdior(CCCI_DEBUG_STATUS_CHANNEL_RX,ccci_debug_rx_cb);
    if(CCCI_IN_USE == ccci_ret){
        /* channel has been registered in normal process, deinit and reinit */
        ccci_deinit(CCCI_DEBUG_STATUS_CHANNEL_RX);
        ccci_ret = ccci_init_gpdior(CCCI_DEBUG_STATUS_CHANNEL_RX,ccci_debug_rx_cb);
    }
    ASSERT(CCCI_SUCCESS == ccci_ret);
    
    // Reset all seq
    ccci_debug_reset_seq_data();
    // Register ccci debug cb funp
    ccci_debug_get_status_register(CCCI_DEBUG_GET_STATUS_MODULE_L1TIME, ccci_debug_get_status_L1Time_funp);
    // Due to AP log needs to be shrinked, remove this info (can shrink ch num * 2bytes)
    //ccci_debug_get_status_register(CCCI_DEBUG_GET_STATUS_MODULE_CCCISEQ, ccci_debug_get_status_ccciseq_funp);

#if defined(__MTK_TARGET__)
    // Register AP force assert MD cb funp
#if defined(__HIF_SDIO_SUPPORT__)
    hifsdio_register_AP_force_assert_callback(ccci_debug_ap_force_assert_md);
#elif defined(__HIF_CLDMA_SUPPORT__)
    hifcldma_register_seq_err_assert_callback(ccci_debug_ap_force_assert_md);
#elif defined(__CCIFCORE_SUPPORT__)
    hifccif_register_seq_err_assert_callback(ccci_debug_ap_force_assert_md);    
#endif
#endif
    
#endif
    return KAL_TRUE;
}


