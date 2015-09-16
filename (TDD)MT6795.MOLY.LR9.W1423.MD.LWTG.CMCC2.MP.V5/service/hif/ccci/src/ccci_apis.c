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
 *   ccci_apis.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Implements CCCI APIS
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
 * [CCCI IPC] Support Clibtime feature
 *
 * removed!
 * removed!
 * [CCCI] Fix CCCI ccci_dlior_cb only callback one gpd at one time in same channel
 *
 * removed!
 * removed!
 * [CCCI] Fix CCCI ccci_dlior_cb only callback one gpd at one time in same channel
 *
 * removed!
 * removed!
 * [CCCI] Fix CCCI ccci_ulior_cb only callback one gpd at one time in same channel
 *
 * removed!
 * removed!
 * [CCCI] Fix Modis no exception share memory error
 *
 * removed!
 * removed!
 * [CCCI] Fix Modis no exception share memory error
 *
 * removed!
 * removed!
 * [CCCI] CCCI new debug mechanism
 *
 * removed!
 * removed!
 * [CCCI] For SS debug info
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * [K2 MD2] Add CCCI/CCIF new feature for K2 MD2
 *
 * removed!
 * removed!
 * [CCCI & RPC & FS] ASSERT enhancement
 *
 * removed!
 * removed!
 * [CCCI APIS] Limit CCCI polling IO using time
 *
 * removed!
 * removed!
 * [CCCI RPC] Debug enhancement & Add log.
 *
 * removed!
 * removed!
 * 	sync ccci_send_message API from WR8
 *
 * removed!
 * removed!
 * 	[CCCI_SYSMSG] sync ccci_send_message return value from WR8
 *
 * removed!
 * removed!
 * 	Shrink CCCI UL/DL buffer to 3.5KB
 *
 * removed!
 * removed!
 * [CCCI] Add exception debug info & boot trace.
 *
 * removed!
 * removed!
 * [CCCI] Add exception debug info & boot trace.
 *
 * removed!
 * removed!
 * 	[CCCI] CCCI MISC Info.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	.
 * 11 18 2013 ap.wang
 * removed!
 * 	Remove MD Log data path log
 *
 * 11 07 2013 ap.wang
 * removed!
 * 	Fix klocwork warning:Suspicious dereference of pointer buff before NULL check at line 351
 * removed!
 * removed!
 * Submit CCCI L2 trace
 *
 * 09 23 2013 ap.wang
 * removed!
 * 	.
 *
 * 09 12 2013 ap.wang
 * removed!
 * 	Add CCCI Log
 *
 * 09 06 2013 ap.wang
 * removed!
 * Fix MODIS error
 *
 * 09 06 2013 ap.wang
 * removed!
 * 	[CCCI] Fix MODIS compile error
 *
 * 09 06 2013 ap.wang
 * removed!
 *
 * 07 12 2013 ap.wang
 * removed!
 * [CCCI EXCEPTION] exception integration
 *
 * removed!
 * removed!
 * [CCCI]CCCI_PCM support for audio driver
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * remove ccci DHL Tx data path log: CCCI_TTY, CCCI
 *
 * 06 06 2013 ap.wang
 * removed!
 * [CCCI] Add ccci_register_sysmsgsvc_callback API
 *
 * removed!
 * removed!
 * a. Check-in cccifs new features (support 16KB I/O)
 * b. add __CCCIFS_SUPPORT__ option to related files
 *
 * 04 12 2013 ap.wang
 * removed!
 * [CCCI] Add log for debug
 *
 * removed!
 * removed!
 * [CCCI] Cache coherence issue fix
 *
 * removed!
 * removed!
 * [CCCI] CCCI/CLDMA INT
 *
 * removed!
 * removed!
 * MT6290 Rename CCCI Services
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#include "ccci_common.h"
#include "ccci_if.h"
#include "qmu_bm.h"
#include "hif_svc_msgid.h"
#include "us_timer.h"

CCCI_CTRL_T ccci_ctrl_pool[CCCI_PEER_ID_MAX][CCCI_MAX_CHANNEL];
static CCCI_BOOT_STATE ccci_boot_state_g;

kal_uint32 MDExceShareMemBase[mExceShareMemSize / 4]; // must be 4byte alignment address
kal_uint8 MDFileShareMemBase[mFileShareMemSize];

/*!
 *  @brief  ap_md_share_data [CCCI_CCIF compatible] 
 *             MD retrieve shared memory info from AP side
 */
MODEM_RUNTIME_DATA ap_md_share_data;

#define CCCI_MTU_SIZE (3584)

extern kal_bool INT_QueryExceptionStatus(void);


//=================================MT6280 IOR function===========================

/*!
 *  @brief ccci_init: This function initializes the buffer mode logical channel.
 *  @param channel:  logical channel
 *  @param funp:  CCCI callback function provided by user
 *  @return CCCI error code, CCCI_RETURNVAL_T
 */
kal_int32 ccci_init(CCCI_CHANNEL_T channel, CCCI_CALLBACK funp)
{
    kal_int32           ret;
    kal_uint32          save_irqmask, hw_type;
    ccci_ch_handle*     pccci_ch_info; //ccci_ch_info
    ccci_hw_apis*       phw_handle_api;
    kal_bool            ret_hifattach;
	kal_uint8			peer_id;
	CCCI_CHANNEL_T		peer_channel;
    
	peer_id 		= GET_PEER_ID(channel);
	peer_channel 	= GET_PEER_CHANNEL(channel);

	//ccci_trace(CCCI_TRACE, CCCI_MOD_API, CCCI_INIT_TRACE, channel, kal_get_active_module_id());
    ret = CCCI_SUCCESS;

    if (peer_channel >= CCCI_MAX_CHANNEL){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_INITB_ERR_CH_NO, channel, kal_get_active_module_id());
        return CCCI_INVALID_PARAM;
    }
	
    pccci_ch_info = ccci_get_ch_info(channel);
    if (funp == NULL){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_INITB_ERR_FUNP, channel, kal_get_active_module_id());
        return CCCI_INVALID_PARAM;
    }
    /*ccci_init function is for user who send buffer pointer parameter, CCCI_CH_USER_LEGACY, CCCI_CH_USER_DIRECT*/
    if((pccci_ch_info->user_mode_predifined != CCCI_CH_USER_LEGACY) &&\
       (pccci_ch_info->user_mode_predifined != CCCI_CH_USER_DIRECT)){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_INITB_ERR_MODE,channel, kal_get_active_module_id());
        return CCCI_INVALID_PARAM;
    }
    if(pccci_ch_info->ccci_uldl_iorcb_funp != NULL && pccci_ch_info->ch_op_type_predifined == CCCI_TYPE_TX){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_INITB_ERR,channel);
        return CCCI_INVALID_PARAM;
    }
    hw_type = pccci_ch_info->hw_type_predifined;
    if((hw_type >= CCCI_TYPE_MAX)||(hw_type <= CCCI_TYPE_MIN)){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_INITB_ERR_TYPE, channel, kal_get_active_module_id(),hw_type);
        return CCCI_INVALID_PARAM;
    }
    phw_handle_api = ccci_get_hw_handle_api(hw_type);
    ASSERT(phw_handle_api);
    /*check if CCCI ch has been occupied, thread safe protection*/
    CCCI_LOCK(save_irqmask);
    {
        if (CCCI_CH_DISABLE != ccci_ctrl_pool[peer_id][peer_channel].owner){
			ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_INITB_ERR_INUSE, 
				channel, kal_get_active_module_id());
            ret = CCCI_IN_USE;
        }else{
            ccci_ctrl_pool[peer_id][peer_channel].owner = pccci_ch_info->user_mode_predifined;
        }
    }
    CCCI_UNLOCK(save_irqmask);
    if (ret != CCCI_SUCCESS){
        return ret;
    }

    ccci_ctrl_pool[peer_id][peer_channel].state = CCCI_IDLE;
    ccci_ctrl_pool[peer_id][peer_channel].ch_op_type = pccci_ch_info->ch_op_type_predifined;
    ccci_ctrl_pool[peer_id][peer_channel].hwq_id = pccci_ch_info->hwq_id_predifined;
    ccci_ctrl_pool[peer_id][peer_channel].cb_funp = funp;
    ccci_ctrl_pool[peer_id][peer_channel].iorcb_funp = NULL; //buffer mode user won't user iorcb_funp
    kal_mem_set(&(ccci_ctrl_pool[peer_id][peer_channel].buff), 0, sizeof(CCCI_BUFF_T));

    /*setup Transmission HW related info*/
    ccci_ctrl_pool[peer_id][peer_channel].ioreq_funp = phw_handle_api->ior_funp;
    ccci_ctrl_pool[peer_id][peer_channel].polling_funp = phw_handle_api->polling_funp;
    ccci_ctrl_pool[peer_id][peer_channel].hif_iomode = phw_handle_api->hwio_mode;
    /*Reserved*/
    ccci_ctrl_pool[peer_id][peer_channel].rxswq = NULL;
    /*[Reserved] kal_eventgrpid event;*/

    /*Attach to the HIF HW queue*/
    ret_hifattach = KAL_FALSE;
    if(CCCI_CH_HIFIO_GPD == ccci_ctrl_pool[peer_id][peer_channel].hif_iomode){
        /*unexpected gpdhwq_attach: please ask CCCI owner to check ccci_hw_handle_apis / gpdhwq_attach setting*/
        ASSERT(NULL != phw_handle_api->gpdhwq_attach);
        ret_hifattach = phw_handle_api->gpdhwq_attach(
                    ccci_ctrl_pool[peer_id][peer_channel].ch_op_type,
                    ccci_ctrl_pool[peer_id][peer_channel].hwq_id,
                    channel,
                    pccci_ch_info->ccci_uldl_iorcb_funp
                    );
    }else if(CCCI_CH_HIFIO_BUFF == ccci_ctrl_pool[peer_id][peer_channel].hif_iomode){
        /*unexpected gpdhwq_attach: please ask CCCI owner to check ccci_hw_handle_apis / gpdhwq_attach setting*/
        ASSERT(NULL != phw_handle_api->buffhwq_attach);
        ret_hifattach = phw_handle_api->buffhwq_attach(
                    ccci_ctrl_pool[peer_id][peer_channel].ch_op_type,
                    ccci_ctrl_pool[peer_id][peer_channel].hwq_id,
                    channel,
                    pccci_ch_info->ccci_uldl_buffcb_funp
                    );
    }else{
        ret_hifattach = KAL_FALSE;
        /*unexpected hwio_mode: please ask CCCI owner to check ccci_hw_handle_apis / hif_iomode setting*/
        EXT_ASSERT(0, (kal_uint32) ccci_ctrl_pool[peer_id][peer_channel].hif_iomode, 0, 0);
    }
    if(KAL_FALSE == ret_hifattach){
        ccci_ctrl_pool[peer_id][peer_channel].owner = CCCI_CH_DISABLE;
        ccci_ctrl_pool[peer_id][peer_channel].cb_funp = NULL;
        ccci_ctrl_pool[peer_id][peer_channel].iorcb_funp = NULL;
        ccci_ctrl_pool[peer_id][peer_channel].ioreq_funp = NULL;
        return CCCI_NO_PHY_CHANNEL;
    }
    return CCCI_SUCCESS;
}

/*!
 *  @brief ccci_owner_init: Legacy MT6280 CCCI API, ccci_init the channel with task id set. But we don't check task id in MT6290
 *  @param channel:  logical channel
 *  @param kal_taskid: task id;
 *  @param funp:  CCCI callback function provided by user
 *  @return CCCI error code, CCCI_RETURNVAL_T
 */
kal_int32 ccci_owner_init(CCCI_CHANNEL_T channel, kal_taskid task, CCCI_CALLBACK funp)
{
    return ccci_init(channel, funp);
}

/*!
 *  @brief ccci_deinit: This function de-initializes the Buffer and GPD mode logical channel.
 *  @param channel:  logical channel
 *  @return CCCI error code, CCCI_RETURNVAL_T
 */
kal_int32 ccci_deinit(CCCI_CHANNEL_T channel)
{
    kal_int32           ret;
    kal_uint32          save_irqmask, hw_type;
    ccci_ch_handle*     pccci_ch_info;
    ccci_hw_apis*       phw_handle_api;
    kal_bool            ret_hifdetach;
    kal_uint8			peer_id;
	CCCI_CHANNEL_T		peer_channel;

	peer_id 		= GET_PEER_ID(channel);
	peer_channel 	= GET_PEER_CHANNEL(channel);

    if (peer_channel >= CCCI_MAX_CHANNEL){
        return CCCI_INVALID_PARAM;
    }
    pccci_ch_info = ccci_get_ch_info(channel);
    hw_type = pccci_ch_info->hw_type_predifined;
    if((hw_type >= CCCI_TYPE_MAX)||(hw_type <= CCCI_TYPE_MIN)){
        return CCCI_INVALID_PARAM;
    }
    phw_handle_api = ccci_get_hw_handle_api(hw_type);

    if(CCCI_CH_DISABLE == ccci_ctrl_pool[peer_id][peer_channel].owner){
        /*No one attached to this channel*/
        return CCCI_SUCCESS;
    }

    /*check the channel state, MT6290 stays in CCCI_IDLE*/
    if (ccci_ctrl_pool[peer_id][peer_channel].state != CCCI_IDLE) {
        /*This should never happen on MT6290*/
        ccci_trace(CCCI_ERR, CCCI_MOD_API, \
            CCCI_TR_DEINIT_STATE_ERR,\
            channel,ccci_ctrl_pool[peer_id][peer_channel].state);
        return CCCI_FAIL; 
    }

    /*detach the HIF driver: e.g. sdiocore_q_detach*/
    ret_hifdetach = phw_handle_api->hwq_detach(
                ccci_ctrl_pool[peer_id][peer_channel].ch_op_type,
                ccci_ctrl_pool[peer_id][peer_channel].hwq_id,
                channel
                );
    if(KAL_FALSE == ret_hifdetach){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, \
        CCCI_TR_DEINIT_ATTCNT_ERR,\
         channel,ccci_ctrl_pool[peer_id][peer_channel].state,
         ccci_ctrl_pool[peer_id][peer_channel].ch_op_type,
         ccci_ctrl_pool[peer_id][peer_channel].hwq_id,
         channel);

        return CCCI_FAIL;
    }

    ret = CCCI_SUCCESS;

    /* modify ccci_channel status*/
    CCCI_LOCK(save_irqmask);
    {
        /* free the channel */
        ccci_ctrl_pool[peer_id][peer_channel].owner = CCCI_CH_DISABLE;
        ccci_ctrl_pool[peer_id][peer_channel].cb_funp = NULL;
        ccci_ctrl_pool[peer_id][peer_channel].iorcb_funp = NULL;
        ccci_ctrl_pool[peer_id][peer_channel].ioreq_funp = NULL;
        ccci_ctrl_pool[peer_id][peer_channel].polling_funp = NULL;
    }
    CCCI_UNLOCK(save_irqmask);
    
    return ret;
}

/*!
 *  @brief ccci_write provides the api for buffer mode user to send DL buffer to HIF transmission HW.
 *         It allocates ONE TGPD by qbmt_alloc_q_no_tail, if it fails returns CCCI_NO_PHY_CHANNEL
 *         The buff will be memcpy to TGPD->BD and submit the TGPD to HIF HW.
 *  @param channel:  logical channel
 *  @param buff:     pointer to buffer to be sent
 *  @return CCCI_RETURNVAL_T
 */
kal_int32 ccci_write(CCCI_CHANNEL_T channel, CCCI_BUFF_T *buff){
    ccci_io_request_t   ccci_DL_ior;
    kal_uint32          num_alloc, to_alloc, data_len, allow_len;
    void                *p_gpd, *p_bd, *p_data;
    CCCI_BUFF_T         *ccci_buff, *tx_ccci_h;
    kal_bool            ret;
	kal_uint8			peer_id;
	CCCI_CHANNEL_T		peer_channel;

	peer_id = GET_PEER_ID(channel);
	peer_channel = GET_PEER_CHANNEL(channel);

    /* check parameters */
    if (peer_channel >= CCCI_MAX_CHANNEL){
		ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_WRB_CH,
		    channel, kal_get_active_module_id());
        return CCCI_INVALID_PARAM;
    }
    if (buff == NULL){
		ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_WRB_BN,
		    channel, kal_get_active_module_id());
        return CCCI_INVALID_PARAM;
    }

    ccci_data_trace(CCCI_WRITE_DATA_TRACE, 
                    buff->channel,buff->data[0],buff->data[1],buff->reserved);
#if CCCI_DATA_TRACE_DUMP_ENABLE    
    ccci_data_trace_dump(buff->channel,buff+1, 32);
#endif   

    ccci_buff = (CCCI_BUFF_T * )(buff);
    if (ccci_ctrl_pool[peer_id][peer_channel].owner == CCCI_CH_DISABLE){
		ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_WRB_OWNDIS,
		    channel, kal_get_active_module_id());
        return CCCI_INVALID_PARAM;
    }
    /*ccci_write is for user who send buffer pointer parameter, CCCI_CH_USER_LEGACY, CCCI_CH_USER_DIRECT*/
    if((ccci_ctrl_pool[peer_id][peer_channel].owner != CCCI_CH_USER_LEGACY) &&\
       (ccci_ctrl_pool[peer_id][peer_channel].owner != CCCI_CH_USER_DIRECT)){
		ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_WRB_OWNDIS,
		    channel, kal_get_active_module_id(), ccci_ctrl_pool[peer_id][channel].owner);
        return CCCI_INVALID_PARAM;
    }
    
    /* if not mailbox, the user has to initialize the ccci_buff->data[1] 
            to declare the bd length including the sizeof(CCCI_BUFF_T) */
    if (!CCCI_IS_MAILBOX(ccci_buff)){
        if(ccci_buff->data[1] < sizeof(CCCI_BUFF_T)){
			ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_WRB_MBXLEN,
				channel, kal_get_active_module_id(), ccci_buff->data[1]);
            return CCCI_INVALID_PARAM;
        }
    }

    if(CCCI_CH_HIFIO_GPD == ccci_ctrl_pool[peer_id][peer_channel].hif_iomode){
        /*allocate TGPD*/
        to_alloc  = 1;
        num_alloc = qbmt_alloc_q_no_tail(
                    CCCI_DL_BUF_TYPE,                  /* type */
                    to_alloc,                          /* buff_num */
                    (void **)(&ccci_DL_ior.first_gpd), /* pp_head */
                    (void **)(&ccci_DL_ior.last_gpd)); /* pp_tail */
        if(num_alloc == 0){
            ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_WRITE_NO_TGPD_ERR, channel);
            return CCCI_NO_PHY_CHANNEL;
        }
        /*Since num_alloc !=0, it must return 1 with non-NULL first gpd*/ 
        EXT_ASSERT(num_alloc == to_alloc, num_alloc, to_alloc, 0);
        ASSERT(NULL!=ccci_DL_ior.first_gpd);
        QBM_DES_SET_NEXT(ccci_DL_ior.last_gpd, NULL);

        p_gpd  = ccci_DL_ior.first_gpd;
        p_bd   = QBM_DES_GET_DATAPTR(p_gpd);
        ASSERT(NULL!=p_bd);
        p_data = QBM_DES_GET_DATAPTR(p_bd);
        ASSERT(NULL!=p_data);
        
        /*Set the length of TGPD & BD*/
        if (!CCCI_IS_MAILBOX(ccci_buff)) 
    	{
            QBM_DES_SET_DATALEN(p_gpd, ccci_buff->data[1]);
            QBM_DES_SET_DATALEN(p_bd,  ccci_buff->data[1]);
            data_len = ccci_buff->data[1];
        }
        else
        {
            QBM_DES_SET_DATALEN(p_gpd, sizeof(CCCI_BUFF_T));
            QBM_DES_SET_DATALEN(p_bd,  sizeof(CCCI_BUFF_T));
            data_len = sizeof(CCCI_BUFF_T);
        }
        //allow_len = QBM_DES_GET_ALLOW_LEN(p_bd);
        //2013.12.27 allow_len shall be 3584, restricted by AP SKB buff
        allow_len = CCCI_MTU_SIZE;
        
        if(data_len > allow_len){
            qbmt_dest_q(ccci_DL_ior.first_gpd, ccci_DL_ior.last_gpd);
            ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_WRITE_LEN_ERR, channel, data_len, allow_len);
            return CCCI_INVALID_PARAM;
        }
        /*Copy the buff content to TGPD.BD*/
        kal_mem_cpy(p_data, ccci_buff, data_len);

        /*Construct the CCCI header*/
        /*Except for channel other CCCI header info should be done in ccci_stream_write* and ccci_mailbox_write*/
        tx_ccci_h = (CCCI_BUFF_T *)p_data;
        tx_ccci_h->channel = channel;
#ifndef ATEST_SYS_CCCI
        // ccci seq trace of lagacy user is added by ccci write
        ccci_debug_add_seq(tx_ccci_h, CCCI_DEBUG_ASSERT_BIT); // add ccci seq
#endif
        /* [20120925]
         * Because ccci_write might be used to send the CCCI message without buffer content, and
         * SDIO driver will report error while TGPD / TBD data_len == 0, 
         * we cannot implement __CCCI_N_USE_TGPD_EXT__ becasue HW limitation.
         *
         * [Wei-De] verification plan
         * Prepare device (DL_)TGPD/TBD with incorrect buffer length.
         * TGPD Ext = 0 , TGPD Len = 0
         * TGPD EXT = 10 , TGPD Len = 0 
         * TGPD Ext = 0 , TBD Ext = 0 , TBD Len = 0
         * TGPD Ext = 10 , TBD Ext = 10 , TBD Len = 0
         */

        /*20120806 FLUSH path review: flush the data content*/
        /*20120924 perfromance enhancement: since QBM_TYPE_CCCI_COMM will flush data during enqueue
                   remove the flush to save MIPS */
        //QBM_CACHE_FLUSH(p_data, data_len);

        ccci_DL_ior.next_request = NULL;
#ifdef __SDIOC_PULL_Q_ENH_DL__
        ccci_DL_ior.num_gpd = 1; /* there's only 1 tgpd allocated in ccci_write */
#endif
        if(ccci_ctrl_pool[peer_id][peer_channel].ioreq_funp != NULL){

            ret = ccci_ctrl_pool[peer_id][peer_channel].ioreq_funp(ccci_ctrl_pool[peer_id][peer_channel].ch_op_type,\
                                                      ccci_ctrl_pool[peer_id][peer_channel].hwq_id,\
                                                      &ccci_DL_ior);
            if(KAL_FALSE == ret){
                ASSERT(0);
                return CCCI_FAIL;
            }
        }else{
            /*channel de-inited during ccci_write*/
            qbmt_dest_q(ccci_DL_ior.first_gpd, ccci_DL_ior.last_gpd);
            ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_WRITE_IORCB_NULL_ERR, channel);
            return CCCI_NO_PHY_CHANNEL;
        }
        return CCCI_SUCCESS;
    }
    else if(CCCI_CH_HIFIO_BUFF == ccci_ctrl_pool[peer_id][peer_channel].hif_iomode){
        /*Construct the CCCI header*/
        /*other CCCI header info should be done in ccci_stream_write* and ccci_mailbox_write*/
        ccci_buff->channel = channel;
#ifndef ATEST_SYS_CCCI
        // ccci seq trace of lagacy user is added by ccci write
        ccci_debug_add_seq(ccci_buff, CCCI_DEBUG_ASSERT_BIT); // add ccci seq
#endif
        if(ccci_ctrl_pool[peer_id][peer_channel].ioreq_funp != NULL){
            ret = ccci_ctrl_pool[peer_id][peer_channel].ioreq_funp(ccci_ctrl_pool[peer_id][peer_channel].ch_op_type,\
                                                      ccci_ctrl_pool[peer_id][peer_channel].hwq_id,\
                                                      ccci_buff);
            if(KAL_FALSE == ret){
                ASSERT(0);
                return CCCI_FAIL;
            }
        }else{
            /*channel de-inited during ccci_write*/
            ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_WRITE_IORCB_NULL_ERR, channel);
            return CCCI_NO_PHY_CHANNEL;
        }
    }else{
        /*hif_iomode must be either CCCI_CH_HIFIO_GPD or CCCI_CH_HIFIO_BUFF*/
        EXT_ASSERT(0, (kal_uint32) ccci_ctrl_pool[peer_id][peer_channel].hif_iomode, 0,0);
        return CCCI_FAIL;
    }
    return CCCI_SUCCESS;
}

/*!
 *  @brief ccci_mailbox_write formats a local buffer to mailbox format and call ccci_write
 *  @param channel:  logical channel
 *  @param id:          mailbox id
 *  @return CCCI_RETURNVAL_T
 */
kal_int32 ccci_mailbox_write(CCCI_CHANNEL_T channel, kal_uint32 id)
{
    CCCI_BUFF_T buff;

    /* initialize a CCCI channel buffer */
    kal_mem_set(&buff, 0, sizeof(CCCI_BUFF_T));
    CCCI_INIT_MAILBOX(&buff, id);

    /* write */
    return ccci_write(channel, &buff);
}

/*!
 *  @brief ccci_mailbox_write formats a local buffer to mailbox format and call ccci_write
 *  @param channel:     logical channel
 *  @param id:              mailbox id
 *  @param reserved:    ccci_header->reserved 
 *  @return CCCI_RETURNVAL_T
 */
kal_int32 ccci_mailbox_write_with_reserved(CCCI_CHANNEL_T channel, kal_uint32 id, kal_uint32 reserved)
{
    CCCI_BUFF_T buff;
    /* initialize a CCCI channel buffer */
    kal_mem_set(&buff, 0, sizeof(CCCI_BUFF_T));
    CCCI_INIT_MAILBOX(&buff, id);
    buff.reserved = reserved;
    /* write */
    return ccci_write(channel, &buff);
}

/*!
 *  @brief ccci_send_message send a message and reserved by ccci_mailbox_write_with_reserved
 *  @param message:  mailbox_id
 *  @param reserved: ccci_header->reserved 
 *  @return CCCI_RETURNVAL_T
 */
kal_bool ccci_send_message(kal_uint32 message, kal_uint32 reserved) 
{
    if(CCCI_SUCCESS == ccci_mailbox_write_with_reserved(CCCI_SYSTEM_CHANNEL, message, reserved))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*!
 *  @brief ccci_stream_write formats a local buffer to stream format and call ccci_write
 *         User must reserve 16B header room in buffer pointed by addr.
 *  @param channel:		logical channel
 *  @param addr:		start address of the user buffer, with sizeof(CCCI_BUFF_T) CCCI header room
 *  @param len:			lenght of the user buffer 
 *  @return CCCI_RETURNVAL_T
 */
kal_int32 ccci_stream_write(CCCI_CHANNEL_T channel, kal_uint32 addr, kal_uint32 len)
{
	CCCI_BUFF_T *pcccih;

	pcccih = (CCCI_BUFF_T *)(addr);
	pcccih->data[0] = addr+sizeof(CCCI_BUFF_T);
	pcccih->data[1] = len;  
    pcccih->channel = channel;
	/* fixed reserved as 0 */	
	pcccih->reserved = 0;
  
    return ccci_write(channel, pcccih);
}

/*!
 *  @brief ccci_stream_write_with_reserved writes data through a stream channel.
 *         User must reserve 16B header room in buffer pointed by addr. 
 *  @param channel:		logical channel
 *  @param addr:		start address of the user buffer, with sizeof(CCCI_BUFF_T) CCCI header room
 *  @param len:			lenght of the user buffer 
 *  @param reserved:	an additional parameter
 *  @return CCCI_RETURNVAL_T
 */
kal_int32 ccci_stream_write_with_reserved(CCCI_CHANNEL_T channel, kal_uint32 addr, kal_uint32 len, kal_uint32 reserved)
{
	CCCI_BUFF_T *pcccih;

	pcccih = (CCCI_BUFF_T *)(addr);
	pcccih->data[0] = addr+sizeof(CCCI_BUFF_T);
	pcccih->data[1] = len;  
    pcccih->channel = channel;	
	pcccih->reserved = reserved;
  
    return ccci_write(channel, pcccih);
}

//=================================MT6290 IOR function for CCCI_CH_USER_GPD===========================
/*!
 *  @brief ccci_init_gpdior: This function initializes the GPD mode logical channel.
 *  @param channel:  logical channel
 *  @param funp:  CCCI callback function provided by user
 *  @return CCCI error code, CCCI_RETURNVAL_T
 */
kal_int32 ccci_init_gpdior(CCCI_CHANNEL_T channel, CCCI_IORCALLBACK ior_funp)
{
    kal_int32           ret;
    kal_uint32          save_irqmask, hw_type;
    ccci_ch_handle*     pccci_ch_info;
    ccci_hw_apis*       phw_handle_api;
    kal_bool            ret_hifattach;
	kal_uint8			peer_id;
	CCCI_CHANNEL_T		peer_channel;
		
	peer_id 		= GET_PEER_ID(channel);
	peer_channel	= GET_PEER_CHANNEL(channel);

    ret = CCCI_SUCCESS;

    if (peer_channel >= CCCI_MAX_CHANNEL){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_INIT_ERR_CH_NO, 
			channel, kal_get_active_module_id());
        return CCCI_INVALID_PARAM;
    }
    pccci_ch_info = ccci_get_ch_info(channel);
    if (ior_funp == NULL){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_INIT_ERR_FUNP, 
			channel, kal_get_active_module_id());
        return CCCI_INVALID_PARAM;
    }
    /*ccci_init_gpdior is for user who send GPDs, CCCI_CH_USER_GPD*/
    if(pccci_ch_info->user_mode_predifined != CCCI_CH_USER_GPD){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_INIT_ERR_USR, 
			channel, kal_get_active_module_id(),pccci_ch_info->user_mode_predifined);
        return CCCI_INVALID_PARAM;
    }
    hw_type = pccci_ch_info->hw_type_predifined;
    if((hw_type >= CCCI_TYPE_MAX)||(hw_type <= CCCI_TYPE_MIN)){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_INIT_ERR_TYPE, 
			channel, kal_get_active_module_id(),hw_type);
        return CCCI_INVALID_PARAM;
    }
    phw_handle_api = ccci_get_hw_handle_api(hw_type);
    
    CCCI_LOCK(save_irqmask);
    {
        if (CCCI_CH_DISABLE != ccci_ctrl_pool[peer_id][peer_channel].owner){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_INIT_ERR_INUSE, 
			channel, kal_get_active_module_id());
            ret = CCCI_IN_USE;
        }else{
            ccci_ctrl_pool[peer_id][peer_channel].owner = pccci_ch_info->user_mode_predifined;
        }
    }
    CCCI_UNLOCK(save_irqmask);

    if (ret != CCCI_SUCCESS){
        return ret;
    }
    ccci_ctrl_pool[peer_id][peer_channel].state = CCCI_IDLE;
    ccci_ctrl_pool[peer_id][peer_channel].ch_op_type = pccci_ch_info->ch_op_type_predifined;
    ccci_ctrl_pool[peer_id][peer_channel].hwq_id = pccci_ch_info->hwq_id_predifined;
    ccci_ctrl_pool[peer_id][peer_channel].cb_funp = NULL; //GPD mode user won't user cb_funp
    ccci_ctrl_pool[peer_id][peer_channel].iorcb_funp = ior_funp; 
    kal_mem_set(&(ccci_ctrl_pool[peer_id][peer_channel].buff), 0, sizeof(CCCI_BUFF_T));

    /*setup Transmission HW related info*/
    ccci_ctrl_pool[peer_id][peer_channel].ioreq_funp = phw_handle_api->ior_funp;
    ccci_ctrl_pool[peer_id][peer_channel].polling_funp = phw_handle_api->polling_funp;
    ccci_ctrl_pool[peer_id][peer_channel].hif_iomode = phw_handle_api->hwio_mode;
    ccci_ctrl_pool[peer_id][peer_channel].rxswq = NULL;
    /*[Reserved] kal_eventgrpid event;*/

    /*Attach to the HIF HW queue*/
    ret_hifattach = KAL_FALSE;
    if(CCCI_CH_HIFIO_GPD == ccci_ctrl_pool[peer_id][peer_channel].hif_iomode){
        /*unexpected gpdhwq_attach: please ask CCCI owner to check ccci_hw_handle_apis / gpdhwq_attach setting*/
        ASSERT(NULL != phw_handle_api->gpdhwq_attach);
        ret_hifattach = phw_handle_api->gpdhwq_attach(
                    ccci_ctrl_pool[peer_id][peer_channel].ch_op_type,
                    ccci_ctrl_pool[peer_id][peer_channel].hwq_id,
                    channel,
                    pccci_ch_info->ccci_uldl_iorcb_funp
                    );
    }else{
        /* MT6290 not support GPD user on buffer mode HIF driver*/
        ret_hifattach = KAL_FALSE;
        /*unexpected hwio_mode: please ask CCCI owner to check ccci_hw_handle_apis / hif_iomode setting*/
        EXT_ASSERT(0, (kal_uint32) ccci_ctrl_pool[peer_id][peer_channel].hif_iomode, 0 ,0);
    }

    if(KAL_FALSE == ret_hifattach){
        ccci_ctrl_pool[peer_id][peer_channel].owner      = CCCI_CH_DISABLE;
        ccci_ctrl_pool[peer_id][peer_channel].cb_funp    = NULL;
        ccci_ctrl_pool[peer_id][peer_channel].iorcb_funp = NULL;
        ccci_ctrl_pool[peer_id][peer_channel].ioreq_funp = NULL;        
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_INIT_ERR_HIFA, 
			channel, kal_get_active_module_id(), ret_hifattach);
        return CCCI_NO_PHY_CHANNEL;
    }
    return ret;
}

/*!
 *  @brief ccci_write_gpd provides the api for GPD mode user to send DL buffer to HIF transmission HW.
 *            There's no memcpy in this mode but it will traverse the GPD chain to add the CCCI header.
 *  @param channel:         logical channel
 *  @param p_ccci_DL_ior:   pointer to p_GPD and GPD number!!!
 *  @param pextinfo:        pointer to the ccci io request extension information, ex.CCCI_IO_TX_NO_FLUSH
 *  @return CCCI_RETURNVAL_T
 */
kal_int32 ccci_write_gpd(CCCI_CHANNEL_T channel, ccci_io_request_t *p_ccci_DL_ior, ccci_io_ext_info_t* pextinfo){
    kal_bool            ret;
    kal_uint8           dest_ch_op_type;
	kal_uint8			peer_id;
	CCCI_CHANNEL_T		peer_channel;

	peer_id 		= GET_PEER_ID(channel);
	peer_channel	= GET_PEER_CHANNEL(channel);

    /* check parameters */
    if (peer_channel >= CCCI_MAX_CHANNEL){
		ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_WR_CH,
		    channel, kal_get_active_module_id());
        return CCCI_INVALID_PARAM;
    }
    if (p_ccci_DL_ior->first_gpd == NULL){
        /*"partial" check: although there might be other ior, don't want to spend too much time on traversing*/
		ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_WR_FGPDN,
		    channel, kal_get_active_module_id());
        return CCCI_INVALID_PARAM;
    }
    if (p_ccci_DL_ior->last_gpd == NULL){
        /*"partial" check: although there might be other ior, don't want to spend too much time on traversing*/
		ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_WR_LGPDN,
		    channel, kal_get_active_module_id());
        return CCCI_INVALID_PARAM;
    }
    if (ccci_ctrl_pool[peer_id][peer_channel].owner == CCCI_CH_DISABLE){
		ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_WR_OWNDIS,
		    channel, kal_get_active_module_id());
        return CCCI_INVALID_PARAM;
    }
    /*ccci_write_gpd is for user who send GPDs, CCCI_CH_USER_GPD*/
    if (ccci_ctrl_pool[peer_id][peer_channel].owner != CCCI_CH_USER_GPD){
		ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_WR_OWNBUFF, 
			channel, kal_get_active_module_id());
        return CCCI_INVALID_PARAM;
    }

    dest_ch_op_type = ccci_ctrl_pool[peer_id][peer_channel].ch_op_type;

#ifdef __SDIOC_PULL_Q_ENH_DL__
    if (p_ccci_DL_ior->num_gpd < 0){
        ASSERT(0);
        return CCCI_INVALID_PARAM;
    }
#endif

    /* change dest_ch_op_type if user request CCCI_IO_TX_NO_FLUSH */
    if(pextinfo != NULL){
        switch(pextinfo->type){
            case CCCI_IO_TX_NO_FLUSH: 
                {
                    /* it must be a TxQ */
                    ASSERT(dest_ch_op_type == CCCI_TYPE_TX);
                    dest_ch_op_type = CCCI_TYPE_TX_NO_FLUSH;
                    //ccci_trace(CCCI_TRACE, CCCI_MOD_API, CCCI_TR_WRITE_NO_FLUSH);
                }
                break;
            default:
                ASSERT(KAL_FALSE);
        }
    }
    
    /* channel.owner == CCCI_CH_USER_GPD, ioreq_funp should not == NULL*/
    //ASSERT(ccci_ctrl_pool[channel].ioreq_funp != NULL);
    ret = ccci_ctrl_pool[peer_id][peer_channel].ioreq_funp(dest_ch_op_type,\
                                             ccci_ctrl_pool[peer_id][peer_channel].hwq_id,\
                                             p_ccci_DL_ior);
    if(channel != CCCI_MD_LOG_RX){
#ifdef __SDIOC_PULL_Q_ENH_DL__
//	    ccci_data_trace(CCCI_WRITE_GPD_RET_DATA_TRACE, 0 ,1,2,3);
    ccci_data_trace(CCCI_WRITE_GPD_RET_DATA_TRACE,
	     kal_get_active_module_id(), channel, ret, p_ccci_DL_ior->num_gpd );
#else
    ccci_data_trace(CCCI_WRITE_GPD_RET_DATA_TRACE,
	    kal_get_active_module_id(), channel, ret, 0 );
#endif 
    }
    /*HW ioreq_funp return fail*/
    if(KAL_FALSE == ret){
		ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_WR_HIFREQ_NG, 
			channel,kal_get_active_module_id(),ret);
        return CCCI_FAIL;
    }

    return CCCI_SUCCESS;
}

/*!
 * @function        ccci_polling_write_gpd
 * @brief           Hook up SDIO polling mode API
 *                  Current Usage: NVRAM-->CCCI_FS during mainp()
 *                                 CCCI_Handshake
 *                  polling time out 2ms, SDIO_POLLING_TIMOUT
 * @param channel   [IN] ccci_channel
 * @param p_gpd     [IN] pointer to the gpd
 * @param istx      [IN] KAL_TRUE: Downlink/Tx KAL_FASE: Uplink/Rx
 *
 * @return          KAL_TRUE: PASS
 *                  KAL_FALSE: NG
 */
kal_int32 ccci_polling_io(CCCI_CHANNEL_T channel, qbm_gpd *p_gpd, kal_bool is_tx){
    kal_bool            ret;
	kal_uint8			peer_id;
	CCCI_CHANNEL_T		peer_channel;
			
	peer_id 		= GET_PEER_ID(channel);
	peer_channel	= GET_PEER_CHANNEL(channel);

    /* check parameters */
    if (peer_channel >= CCCI_MAX_CHANNEL){
        return CCCI_INVALID_PARAM;
    }
    if (p_gpd == NULL){
        return CCCI_INVALID_PARAM;
    }
    if (ccci_ctrl_pool[peer_id][peer_channel].owner == CCCI_CH_DISABLE){
        return CCCI_INVALID_PARAM;
    }

    /* check using timing */
    // if user uses polling before ccci hal init done or after ccci hs2, it's forbiddance, expect exception mode
    if ((get_ccci_boot_state() < CCCI_HAL_INIT_DONE||  get_ccci_boot_state() >= CCCI_BOOT_DONE) && INT_QueryExceptionStatus() == KAL_FALSE){
	    EXT_ASSERT(0, get_ccci_boot_state(),(kal_uint32) channel, is_tx);
    }
    //if (ccci_ctrl_pool[channel].owner != CCCI_CH_USER_GPD){
    //    return CCCI_INVALID_PARAM;
    //}

    /* channel.owner == CCCI_CH_USER_GPD, ioreq_funp should not == NULL*/
    //ASSERT(ccci_ctrl_pool[channel].ioreq_funp != NULL);
    ret = ccci_ctrl_pool[peer_id][peer_channel].polling_funp(ccci_ctrl_pool[peer_id][peer_channel].hwq_id, p_gpd, is_tx);
        
    /*HW ioreq_funp return fail*/
    /*polling time out 2ms, SDIO_POLLING_TIMOUT*/
    if(KAL_FALSE == ret){
        return CCCI_FAIL;
    }

    return CCCI_SUCCESS;
}

//=================================CCCI callback APIs for HIF===========================
/*!
 *  @brief ccci_ulbuff_cb is the MD side CCCI Rx callback function which registered to the buffer mode HIF driver by HIF_attach
 *                                  e.g. CCCI_CH_HIFIO_BUFF
 *  @param queue_no:  HW queue id, backward compatible with usb core
 *  @param pbuff:         pointer to Rx buffer CCCI header
 *  @return void
 */
void ccci_ulbuff_cb (kal_uint8 queue_no, CCCI_BUFF_T* pbuff){
    kal_uint32          logic_channel;
    kal_uint8			peer_id;
	kal_uint32			peer_channel;
			
    /*check if pbuff == NULL*/ 
    if (pbuff == NULL){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_ULCB_BUFF_ERR);
        return;
    }
    ccci_data_trace(CCCI_ULBUFF_CB_DATA_TRACE,
        pbuff->channel,CCCI_DEBUG_GET_SEQ_IN_CH(pbuff->channel), pbuff->data[0], pbuff->data[1], pbuff->reserved);
#if CCCI_DATA_TRACE_DUMP_ENABLE    
    ccci_data_trace_dump(pbuff->channel,pbuff+1, 32);
#endif

    
    /*get the corresponding channel#*/
	logic_channel = pbuff->channel;

	peer_id 		= GET_PEER_ID(logic_channel);
	peer_channel	= GET_PEER_CHANNEL(logic_channel);

    // ccci seq trace of lagacy user is checked by ccci_ulbuff_cb
#ifndef ATEST_SYS_CCCI
    ccci_debug_check_seq(pbuff); // check ccci seq
#endif
	/* check the logic channel number info */
	if(logic_channel == CCCI_FORCE_RESET_MODEM_CHANNEL)
    {
    	//the AP side RIL module/QA will through the method to force MD reset
    	#define FORCE_RESET_MODEM   (0)
		ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_ULBUFF_RST_MD);
        EXT_ASSERT(FORCE_RESET_MODEM, logic_channel, 0, 0);
    }
    else if(peer_channel >= CCCI_MAX_CHANNEL)
    {
        ccci_trace(CCCI_ERR, CCCI_MOD_API,CCCI_TR_ULCB_CH_ERR,logic_channel,CCCI_MAX_CHANNEL);
        return;
    }
    
    /* execute the callback function :: ccci_ulbuff_cb can only pass the pbuff to "Buffer mode user", for GPD user, HIF driver has to exposes a GPD mode I/F*/
	if (ccci_ctrl_pool[peer_id][peer_channel].cb_funp == NULL)
	{
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_ULCB_FUNP_ERR,logic_channel);
        ASSERT(0); //2012015 Ian Rx data to an inactive channel
	} 
	else
	{
	    ccci_ctrl_pool[peer_id][peer_channel].cb_funp(pbuff);
    }
    return;
}

/*!
 *  @brief ccci_ulior_cb is the MD side CCCI Rx callback function which registered to the GPD mode HIF driver by HIF_attach
 *                                  e.g. CCCI_CH_HIFIO_GPD
 *  @param queue_no:  HW queue id, backward compatible with usb core
 *  @param io_request:         pointer of ior
 *  @return void
 */
void ccci_ulior_cb (kal_uint8 queue_no, ccci_io_request_t* io_request){
    qbm_gpd             *first_gpd;
    qbm_gpd             *last_gpd;
    qbm_gpd             *curr_gpd;
    qbm_gpd             *next_gpd;
    ccci_io_request_t   *next_io_request;
    kal_bool            done = KAL_FALSE;
    CCCI_BUFF_T         *pcccih;
//    void                *pbd;
    kal_uint32          logic_channel= CCCI_MAX_CHANNEL;
    /*local queue to collect the GPDs to be free and free once in the end*/
    qbm_gpd             *free_h=NULL, *free_t=NULL;
    /*local queue for continuous GPD with the same GPD type ccci channel*/
    kal_uint32          q_logic_channel = CCCI_MAX_CHANNEL;
    void                *q_gpd_h=NULL, *q_gpd_t=NULL;
    ccci_io_request_t   ccci_ior;
#ifdef __CCCI_GPD_LEAK_DBG__
    kal_uint32          ccci_ulior_gpd_cnt = 0;
    qbm_gpd             *dbg_pgpd_h, *dbg_pbd_h;
    CCCI_BUFF_T         *dbg_pccci_h;
    qbm_gpd             *dbg_pgpd_t, *dbg_pbd_t;
    CCCI_BUFF_T         *dbg_pccci_t;
#endif
	kal_uint8			peer_id, q_peer_id;
	kal_uint32			peer_channel = CCCI_MAX_CHANNEL;
	kal_uint32			q_peer_channel = CCCI_MAX_CHANNEL;


    /*check if io_request == NULL*/ 
    if (io_request == NULL){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_ULIORCB_IOR_ERR);
        return;
    }
    /*check if io_request->first_gpd == NULL*/
    if (io_request->first_gpd == NULL){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_ULIORCB_FGPD_ERR);
        return;
    }
    /*check if io_request->last_gpd == NULL*/
    if (io_request->last_gpd == NULL){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_ULIORCB_TGPD_ERR);
        return;
    }


    while (io_request) {
        next_io_request = io_request->next_request;
        first_gpd = io_request->first_gpd;
        last_gpd = io_request->last_gpd;

        done = KAL_FALSE;
        for (curr_gpd = first_gpd; curr_gpd && !done; curr_gpd = next_gpd) {
#ifdef __CCCI_GPD_LEAK_DBG__
            ccci_ulior_gpd_cnt++;
#endif
            next_gpd = QBM_DES_GET_NEXT(curr_gpd);
            done = (curr_gpd == last_gpd);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else            
            pcccih = CCCI_GET_QBM_DATAPTR(curr_gpd);
#endif
            ASSERT(pcccih);
            ccci_data_trace(CCCI_ULIOR_CB_DATA_TRACE,
                pcccih->channel,CCCI_DEBUG_GET_SEQ_IN_CH(pcccih->channel), pcccih->data[0], pcccih->data[1], pcccih->reserved);
#if CCCI_DATA_TRACE_DUMP_ENABLE    
            ccci_data_trace_dump(pcccih->channel, pcccih+1, 32);
#endif
            
            /*20120806 FLUSH path review: flush the data content*/
            QBM_CACHE_INVALID(pcccih, sizeof(CCCI_BUFF_T));

            /*get the corresponding channel#*/
        	logic_channel = pcccih->channel;

			peer_id 		= GET_PEER_ID(logic_channel);
			peer_channel	= GET_PEER_CHANNEL(logic_channel);

        	/* check the logic channel number info */
        	if(logic_channel == CCCI_FORCE_RESET_MODEM_CHANNEL)
            {
            	/*the AP side RIL module/QA will through the method to force MD reset*/
            	#define FORCE_RESET_MODEM   (0)
        		ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_ULIOR_RST_MD);
                EXT_ASSERT(FORCE_RESET_MODEM, logic_channel, 0, 0);
            }
            else if(peer_channel >= CCCI_MAX_CHANNEL)
            {
                ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_ULIORCB_CH_ERR,logic_channel,CCCI_MAX_CHANNEL);
                ccci_dump_data((void*)pcccih, 64);
                //QBM_DES_SET_NEXT(curr_gpd, NULL);
                QBM_FREE_ONE(curr_gpd);
                continue;
            }
#ifdef __CCCI_GPD_LEAK_DBG__
            /* 20120704 The UL HW queue must equal to the one which the logical channel is binded to */
            /* This case will cause RGPD reload to wrong Rx Queue, ex. CCMNI1, CCMNI2*/
            EXT_ASSERT(ccci_ctrl_pool[peer_id][peer_channel].hwq_id == queue_no, (kal_uint32)ccci_ctrl_pool[peer_id][peer_channel].hwq_id, (kal_uint32) queue_no,0);
#else
            if(ccci_ctrl_pool[peer_id][peer_channel].hwq_id!= queue_no){
                ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_ULIORCB_Q_ERR,queue_no,ccci_ctrl_pool[peer_id][peer_channel].hwq_id);
            }
#endif
            logic_channel = GET_CCCI_CHANNEL(logic_channel);
            if (ccci_ctrl_pool[peer_id][peer_channel].owner == CCCI_CH_USER_GPD){
                /*e.g. MT6290 SDIOC_RXQ_Q1*/
                /*Queue the GPDs in local queue q_gpd_h, q_gpd_t*/
                if(q_logic_channel == CCCI_MAX_CHANNEL){
                    /*nothing in the queue*/
                    EXT_ASSERT(NULL==q_gpd_h && NULL==q_gpd_t, (kal_uint32)q_gpd_h, (kal_uint32)q_gpd_t,0);
                    q_gpd_h = curr_gpd;
                    q_gpd_t = curr_gpd;
                    q_logic_channel = logic_channel;
                    /*ccci_trace(CCCI_TRACE, CCCI_MOD_API, CCCI_TR_ULIOR_CB_DBG\
                            ,logic_channel,CCCI_GET_GPD_LIST_SIZE(q_gpd_h, q_gpd_t));*/
                    QBM_DES_SET_NEXT(curr_gpd, NULL);
                    continue;
                }else if(logic_channel == q_logic_channel){
                    /*same ccci_user gpd -> add to local queue*/
                    QBM_DES_SET_NEXT(q_gpd_t, curr_gpd);
                    QBM_DES_SET_NEXT(curr_gpd, NULL);
                    q_gpd_t = curr_gpd;
                    continue;
                }else{
                    /*the first gpd belong to different user that the local queue*/
                    /*pass the local gpd queue by callback to CCCI user*/
					q_peer_id 		= GET_PEER_ID(q_logic_channel);
					q_peer_channel	= GET_PEER_CHANNEL(q_logic_channel);
                    if(ccci_ctrl_pool[q_peer_id][q_peer_channel].iorcb_funp != NULL){
                        ccci_ior.next_request = NULL;
                        ccci_ior.first_gpd = q_gpd_h;
                        ccci_ior.last_gpd  = q_gpd_t;
                        ccci_ctrl_pool[q_peer_id][q_peer_channel].iorcb_funp(q_logic_channel, &ccci_ior);
                    }else{
                        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_ULIORCB_FUNP_ERR,q_logic_channel);
                        CCCI_QBM_ENQ(q_gpd_h,q_gpd_t,(void**)&free_h, (void**)&free_t);
                        ASSERT(0); //20120615 ian: <Rx data to an inactive channel>, CCCI should assert or reload the gpds
                    }
                    /* en-queue current gpd*/
                    q_gpd_h = curr_gpd;
                    q_gpd_t = curr_gpd;
                    q_logic_channel = logic_channel;
                }
            }else if (ccci_ctrl_pool[peer_id][peer_channel].owner == CCCI_CH_USER_DIRECT \
                 || ccci_ctrl_pool[peer_id][peer_channel].owner == CCCI_CH_USER_LEGACY \
            ){
                if(ccci_ctrl_pool[peer_id][peer_channel].cb_funp != NULL){
#ifndef ATEST_SYS_CCCI
                    // ccci seq trace of lagacy user is checked by ccci_ulbuff_cb
                     ccci_debug_check_seq(pcccih); // check ccci seq
#endif
                    ccci_ctrl_pool[peer_id][peer_channel].cb_funp(pcccih);
                }else{
                    ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_ULIORCB_CH_INAC, logic_channel);
                }
                /* 20130208 invalidate the ccci data part for buffer mode user
                 * User might change the data in cache without flush to DRAM causing the cache coherence problem
                 */
                QBM_CACHE_INVALID(pcccih, curr_gpd->data_len);
                CCCI_QBM_ENQ(curr_gpd,curr_gpd,(void**)&free_h, (void**)&free_t);
            }else{
                ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_ULIORCB_TYPE_ERR,logic_channel, ccci_ctrl_pool[peer_id][peer_channel].owner);
                CCCI_QBM_ENQ(curr_gpd,curr_gpd,(void**)&free_h, (void**)&free_t);
            }
        }
        io_request = next_io_request;
    } 
#ifdef __CCCI_GPD_LEAK_DBG__
    dbg_pgpd_h   = first_gpd;
    dbg_pbd_h    = QBM_DES_GET_DATAPTR(dbg_pgpd_h);
    dbg_pccci_h  = (CCCI_BUFF_T *)QBM_DES_GET_DATAPTR(dbg_pbd_h);
    dbg_pgpd_t   = last_gpd;
    dbg_pbd_t    = QBM_DES_GET_DATAPTR(dbg_pgpd_t);
    dbg_pccci_t  = (CCCI_BUFF_T *)QBM_DES_GET_DATAPTR(dbg_pbd_t);
    ccci_dhl_print(CCCI_TRACE, CCCI_MOD_API, "[CCCI] __CCCI_GPD_LEAK_DBG__ ccci_ulior_cb HIF_Q[%d] ccci_ulior_gpd_cnt = %d",queue_no, ccci_ulior_gpd_cnt);
    ccci_dhl_print(CCCI_TRACE, CCCI_MOD_API, "first_gpd 0x%x last_gpd 0x%x \r\n",CCCI_GET_RESERVED(dbg_pccci_h), CCCI_GET_RESERVED(dbg_pccci_t));    
#endif
    if(q_logic_channel != CCCI_MAX_CHANNEL){
		q_peer_id 		= GET_PEER_ID(q_logic_channel);
		q_peer_channel	= GET_PEER_CHANNEL(q_logic_channel);
        /*pass the local gpd queue by callback to CCCI user*/
        if(ccci_ctrl_pool[q_peer_id][q_peer_channel].iorcb_funp != NULL){
            ccci_ior.next_request = NULL;
            ccci_ior.first_gpd = q_gpd_h;
            ccci_ior.last_gpd  = q_gpd_t;
            ccci_ctrl_pool[q_peer_id][q_peer_channel].iorcb_funp(q_logic_channel, &ccci_ior);
        }else{
            ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_ULIORCB_IORFUNP_ERR,q_logic_channel);
            CCCI_QBM_ENQ(q_gpd_h,q_gpd_t,(void**)&free_h, (void**)&free_t);
            ASSERT(0); //20120615 ian: <Rx data to an inactive channel>, CCCI should assert or reload the gpds
        }
    }
    /*for CCCI_CH_USER_DIRECT/CCCI_CH_USER_LEGACY the input ior contains valid gpd_head, thus there must be at least one gpd to be free*/
    /*for CCCI_CH_USER_GPD, the free_h might be NULL*/
    if(NULL!=free_h){
        ASSERT(NULL!=free_t);
        qbmt_dest_q(free_h, free_t);
    }
}

/*!
 *  @brief ccci_ulior_net_cb is the MD side CCCI CCMNI Rx callback function which registered to the GPD mode HIF driver by HIF_attach
 *                                  e.g. CCCI_CH_HIFIO_GPD
 *  @param queue_no:  HW queue id, backward compatible with usb core
 *  @param io_request:         pointer of ior
 *  @return void
 */
void ccci_ulior_net_cb (kal_uint8 queue_no, ccci_io_request_t* io_request){
    CCCI_BUFF_T         *pcccih;
    kal_uint32          logic_channel= CCCI_MAX_CHANNEL;
	kal_uint8			peer_id;
	kal_uint32			peer_channel = CCCI_MAX_CHANNEL;

    /*check if io_request == NULL*/ 
    if (io_request == NULL){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_ULIORNET_IOR_ERR);
        return;
    }
    /*check if io_request->first_gpd == NULL*/
    if (io_request->first_gpd == NULL){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_ULIORNET_HGPD_ERR);
        return;
    }
    /*check if io_request->last_gpd == NULL*/
    if (io_request->last_gpd == NULL){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_ULIORNET_TGPD_ERR);
        return;
    }

    pcccih = CCCI_GET_QBM_DATAPTR(io_request->first_gpd);
    ASSERT(pcccih);

    /*20120806 FLUSH path review: flush the data content*/
    QBM_CACHE_INVALID(pcccih, sizeof(CCCI_BUFF_T));

    /*get the corresponding channel#*/
	logic_channel = pcccih->channel;

	peer_id 		= GET_PEER_ID(logic_channel);
	peer_channel	= GET_PEER_CHANNEL(logic_channel);

    EXT_ASSERT(peer_channel < CCCI_MAX_CHANNEL,peer_channel, (kal_uint32)queue_no,0);
#ifndef ATEST_SYS_CCCI // Ignore the UT case
    /* must be used by network channel */
    ASSERT(peer_channel >= CCCI_CCMNI1_RX);
    ASSERT(peer_channel <= CCCI_CCMNI3_TX_ACK);
#endif

    ASSERT (ccci_ctrl_pool[peer_id][peer_channel].hwq_id == queue_no);
    EXT_ASSERT (ccci_ctrl_pool[peer_id][peer_channel].hwq_id == queue_no, (kal_uint32)ccci_ctrl_pool[peer_id][peer_channel].hwq_id, (kal_uint32)queue_no,logic_channel);
	logic_channel = GET_CCCI_CHANNEL(logic_channel);
    if(ccci_ctrl_pool[peer_id][peer_channel].iorcb_funp != NULL){
        ccci_ctrl_pool[peer_id][peer_channel].iorcb_funp(logic_channel, io_request);
    }else{
        /* must assert or reload the RGPD, if free invalid channel RGPD might cause GPD leakage */
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_ULIORNETCB_IORFUNP_ERR,logic_channel);
        ASSERT(0);
    }    

}

/*!
 *  @brief ccci_dlior_agg_cb is the MD side CCCI Tx DONE aggregated callback function for deq the TGPD e.g. DHL
 *                               Unlike ccci_ulior_cb, this function does NOT handle the non-CCCI_CH_USER_GPD types
 *  @param queue_no:  HW queue id, backward compatible with usb core
 *  @param io_request:  pointer of ior
 *  @return void
 */
void ccci_dlior_agg_cb(kal_uint8 queue_no, ccci_io_request_t* io_request){
    qbm_gpd             *first_gpd;
    qbm_gpd             *last_gpd;
    qbm_gpd             *curr_gpd;
    qbm_gpd             *next_gpd;
    ccci_io_request_t   *next_io_request;
    kal_bool            done = KAL_FALSE;
    CCCI_BUFF_T         *pcccih;
//    void                *pbd;
    kal_uint32          logic_channel;
    /*local queue to collect the GPDs to be free and free once in the end*/
    qbm_gpd             *free_h=NULL, *free_t=NULL;
    /*local queue for continuous GPD with the same GPD type ccci channel*/
    kal_uint32          q_logic_channel = CCCI_MAX_CHANNEL;
    void                *q_gpd_h=NULL, *q_gpd_t=NULL;
    ccci_io_request_t   ccci_ior;
	kal_uint8			peer_id, q_peer_id;
	kal_uint32			peer_channel = CCCI_MAX_CHANNEL;
	kal_uint32			q_peer_channel = CCCI_MAX_CHANNEL;

    /*check if io_request == NULL*/ 
    if (io_request == NULL){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_DLIOR_IOR_ERR);
        return;
    }
    /*check if io_request->first_gpd == NULL*/
    if (io_request->first_gpd == NULL){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_DLIOR_HGPD_ERR);
        return;
    }
    /*check if io_request->last_gpd == NULL*/
    if (io_request->last_gpd == NULL){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_DLIOR_TGPD_ERR);
        return;
    }

    while (io_request) {
        next_io_request = io_request->next_request;
        first_gpd = io_request->first_gpd;
        last_gpd = io_request->last_gpd;

        done = KAL_FALSE;
        for (curr_gpd = first_gpd; curr_gpd && !done; curr_gpd = next_gpd) {
            next_gpd = QBM_DES_GET_NEXT(curr_gpd);
            done = (curr_gpd == last_gpd);

#ifdef __CCCI_N_USE_TGPD_EXT__
            pcccih = CCCI_GET_QBM_DATAPTR(curr_gpd);
#else
            if(0!=QBM_DES_GET_EXTLEN(curr_gpd)){
                pcccih = (CCCI_BUFF_T *)QBM_DES_GET_EXT(curr_gpd);
            }else{
                pcccih = CCCI_GET_QBM_DATAPTR(curr_gpd);
            }
#endif
            ASSERT(pcccih);

            /*get the corresponding channel#*/
        	logic_channel = pcccih->channel;

			peer_id 		= GET_PEER_ID(logic_channel);
			peer_channel	= GET_PEER_CHANNEL(logic_channel);

        	/* check the logic channel number info */
            if(peer_channel >= CCCI_MAX_CHANNEL)
            {
                ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_DLIOR_RST_MD,logic_channel,CCCI_MAX_CHANNEL);
                //QBM_DES_SET_NEXT(curr_gpd, NULL);
                QBM_FREE_ONE(curr_gpd);
                continue;
            }
            if (ccci_ctrl_pool[peer_id][peer_channel].iorcb_funp == NULL){
                /*no need to do tx done*/
                CCCI_QBM_ENQ(curr_gpd,curr_gpd,(void**)&free_h, (void**)&free_t);
                continue;
            }else{
			    logic_channel = GET_CCCI_CHANNEL(logic_channel);
                /*Queue the GPDs in local queue q_gpd_h, q_gpd_t*/
                if(q_logic_channel == CCCI_MAX_CHANNEL){
                    /*nothing in the queue*/
                    EXT_ASSERT(NULL==q_gpd_h && NULL==q_gpd_t, (kal_uint32)q_gpd_h, (kal_uint32)q_gpd_t,0);
                    q_gpd_h = curr_gpd;
                    q_gpd_t = curr_gpd;
                    q_logic_channel = logic_channel;
                    /*ccci_trace(CCCI_TRACE, CCCI_MOD_API, CCCI_TR_DLIOR_AGG_CB_DBG\
                            ,logic_channel,CCCI_GET_GPD_LIST_SIZE(q_gpd_h, q_gpd_t));*/
                    QBM_DES_SET_NEXT(curr_gpd, NULL);
                    continue;
                }else if(logic_channel == q_logic_channel){
                    /*same ccci_user gpd -> add to local queue*/
                    QBM_DES_SET_NEXT(q_gpd_t, curr_gpd);
                    QBM_DES_SET_NEXT(curr_gpd, NULL);
                    q_gpd_t = curr_gpd;
                    continue;
                }else{
                    /*the first gpd belong to different user that the local queue*/
                    /*pass the local gpd queue by callback to CCCI user*/
					q_peer_id 		= GET_PEER_ID(q_logic_channel);
					q_peer_channel	= GET_PEER_CHANNEL(q_logic_channel);
                    if(ccci_ctrl_pool[q_peer_id][q_peer_channel].iorcb_funp != NULL){
                        ccci_ior.next_request = NULL;
                        ccci_ior.first_gpd = q_gpd_h;
                        ccci_ior.last_gpd  = q_gpd_t;
                        ccci_ctrl_pool[q_peer_id][q_peer_channel].iorcb_funp(q_logic_channel, &ccci_ior);
                    }else{
                        /* Case 1: tx done for de-initING channel */
                        /* Case 2: bug that corrupt the ccci channel info */
                        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_DLIOR_FUNP_ERR,q_logic_channel);
                        CCCI_QBM_ENQ(q_gpd_h,q_gpd_t,(void**)&free_h, (void**)&free_t);
                    }
                    /* en-queue current gpd*/
                    q_gpd_h = curr_gpd;
                    q_gpd_t = curr_gpd;
                    q_logic_channel = logic_channel;
                }
            }
        }
        io_request = next_io_request;
    } 
    if(q_logic_channel != CCCI_MAX_CHANNEL){
		q_peer_id 		= GET_PEER_ID(q_logic_channel);
		q_peer_channel	= GET_PEER_CHANNEL(q_logic_channel);
        /*pass the local gpd queue by callback to CCCI user*/
        if(ccci_ctrl_pool[q_peer_id][q_peer_channel].iorcb_funp != NULL){
            ccci_ior.next_request = NULL;
            ccci_ior.first_gpd = q_gpd_h;
            ccci_ior.last_gpd  = q_gpd_t;
            ccci_ctrl_pool[q_peer_id][q_peer_channel].iorcb_funp(q_logic_channel, &ccci_ior);
        }else{
            /* Case 1: tx done for de-initING channel */
            /* Case 2: bug that corrupt the ccci channel info */
            ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_DLIOR_IORFUNP_ERR,q_logic_channel);
            CCCI_QBM_ENQ(q_gpd_h,q_gpd_t,(void**)&free_h, (void**)&free_t);
        }
    }
    if(NULL!=free_h){
        ASSERT(NULL!=free_t);
        qbmt_dest_q(free_h, free_t);
    }
}

void ccci_dhl_print(kal_uint8 level, kal_uint32 mod, const char *fmt, ...)
{
    kal_uint8 string_buff[128];
    if (level >= CCCI_DBG_TH) {
        if (mod & CCCI_DBG_MSK) {
            va_list args;
            va_start(args, fmt);
            vsprintf((char *)(&string_buff[0]), fmt, args);
            tst_sys_trace((kal_char*)(&string_buff[0])); // Default^M
        }
    }
    return;
}

void ccci_dump_data(void* p_data, kal_uint32 bytes){
    kal_uint32 i = 0;
    kal_uint32* p_d = (kal_uint32*)p_data;
    for (i=0; i <= bytes; i=i+4 ){
        ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_DUMP_DATA_4HEX, p_d[i], p_d[i+1], p_d[i+2], p_d[i+3]);
    }
}

void ccci_data_trace_dump(kal_uint32 ch, void* p_data, kal_uint32 bytes){
    kal_uint32 i = 0;
    kal_uint32* p_d = (kal_uint32*)((int)p_data & (~0X3));// 4bytes alignment
	for (i=0; i*4 < bytes; i=i+4 ){
        ccci_data_trace(CCCI_DATA_DUMP_TRACE,ch,CCCI_DEBUG_GET_SEQ_IN_CH(ch),i*4,p_d[i],p_d[i+1],p_d[i+2],p_d[i+3]);
    }
}

/*!
 *  @brief ccci_get_current_time is to get current time
 *  @param NA
 *  @return kal_uint32 current time
 *  Unit: micro second
 *
 */
kal_uint32 ccci_get_current_time()
{
#if defined(__MTK_TARGET__)
    return ust_get_current_time();
#else // MODIS
    return 0;
#endif
}

/*!
 *  @brief ccci_get_duration is to calculate the duration between start time and end time
 *  @param start: start time
 *              end:   end time
 *  @return kal_uint32 time duration
 *  Unit: micro second
 *
 */
kal_uint32 ccci_get_duration(kal_uint32 start, kal_uint32 end)
{
#if defined(__MTK_TARGET__)
    return ust_get_duration(start, end);
#else // MODIS
    return 0;
#endif
}

/********************CCCI_HS_APIS******************/
/*!
 * @function        ccci_get_fs_shm_info
 * @brief           API to release the share memory information to ccci_fs
 *
 * @param p_membase [IN/OUT] return the share memory address to caller
 * @param p_memsize [IN/OUT] return the share memory size to caller
 *
 * @return          void 
 */
void ccci_get_fs_shm_info(void **p_membase, kal_uint32 *p_memsize){
    *p_membase = (void *)ap_md_share_data.FileShareMemBase;
    *p_memsize = ap_md_share_data.FileShareMemSize;
    return ;
}

void ccci_get_ex_shm_info(void **p_membase, kal_uint32 *p_memsize){
    ap_md_share_data.ExceShareMemBase = (kal_uint32) &MDExceShareMemBase;
    ap_md_share_data.ExceShareMemSize = mExceShareMemSize;

    *p_membase = (void *)ap_md_share_data.ExceShareMemBase;
    *p_memsize = ap_md_share_data.ExceShareMemSize;
    return;
}

extern CCCI_EXCEP_MEMORY_TYPE ccci_excep_memory_type;
void ccci_CalculateShareMem(kal_uint32 *start_addr, kal_uint32 *end_addr , kal_uint32 *size)
{
    MODEM_RUNTIME_DATA *ap_md_share_data = ccci_get_share_data();

    if(ccci_excep_memory_type == CCCI_EXCEP_MEMORY_TYPE_SHM){
        *start_addr = ap_md_share_data->TotalShareMemBase;
        *end_addr   = ap_md_share_data->TotalShareMemBase + ap_md_share_data->TotalShareMemSize;
        *size       = ap_md_share_data->TotalShareMemSize;
    }
}

kal_bool ccci_queryBootAttributes(kal_uint32 mask)
{
    if ((ap_md_share_data.BootAttributes & mask) != 0x0)
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}
/*!
 *  @brief  ccci_get_share_data returns the pointer of share data
 *  @return   &ap_md_share_data
 */
MODEM_RUNTIME_DATA* ccci_get_share_data(){
    return &ap_md_share_data;
}

void set_ccci_boot_state(kal_uint32 new_state)
{
  ccci_boot_state_g = new_state;
}

kal_uint32 get_ccci_boot_state()
{
  return ccci_boot_state_g;
}

/*!
 *  @brief   ccci_handshake1_ack to receive ap_md_share_data from AP
 *  @param   bufp - AP data with ap_md_share_data
 *  @return  void
 */
void ccci_handshake1_ack(CCCI_BUFF_T *bufp, kal_uint32 cp_size)
{
    kal_uint32 i;
    if (bufp->reserved == BOOT_CHECK_ID)
    {
        /* copy the run-time data to MD global structure to initialized shared memory info.*/
	    for (i=0; i < (cp_size+3) >> 2; i++)
	    {
		    /* attach the shared memory info. */
		    *(((volatile unsigned long *)&(ap_md_share_data)) + i) = *((volatile unsigned long *)bufp+CCCI_HAL_OVERHEAD_WORD+i);
	    }
        ccci_boot_state_g = CCCI_HANDSHAKE1_AP_ACK;
    }else{
	    ccci_trace(CCCI_ERR, CCCI_MOD_SDIO, CCCI_TR_HSHK1_ERR,\
            bufp->data[0], bufp->data[1], bufp->channel, bufp->reserved);
    }
	return;
}

/*!
 *  @brief     ccci_boot_ack dummy ack cb
 *  @param   bufp - poitner to the CCCI_SYSTEM_CHANNEL mailbox buffer
 *  @return   void
 */
void ccci_boot_ack(CCCI_BUFF_T *bufp)
{
	ccci_trace(CCCI_ERR, CCCI_MOD_SDIO, CCCI_TR_BOOTACK_ERR,bufp->channel,bufp->data[1]);
	return;
}

#if !defined(__MTK_TARGET__) 
void ccci_modis_hs1(void) 
{
    /* MODIS should be set ccci share memory */
    MODEM_RUNTIME_DATA *share_data = ccci_get_share_data();
    kal_uint32          get_shm_ret, set_shm_ret;
	
	share_data->ExceShareMemBase = (kal_uint32) &MDExceShareMemBase;
	share_data->ExceShareMemSize = mExceShareMemSize;
	share_data->FileShareMemBase = (kal_uint32) &MDFileShareMemBase;
	share_data->FileShareMemSize = mFileShareMemSize;

	if((kal_uint32 *)share_data->ExceShareMemBase != NULL){
		set_shm_ret=  ccci_excep_init_shm(CCCI_EXCEP_MEMORY_TYPE_SHM);
		ASSERT(set_shm_ret == CCCI_SUCCESS);
		get_shm_ret = ccci_excep_query_shm(CCCI_EXCEP_MEMORY_REGION_CCCI, &ccci_excep_dbg_log_base_hs2, &ccci_excep_dbg_log_size_hs2, &ccci_excep_dbg_log_type_hs2);
		ASSERT(get_shm_ret == CCCI_SUCCESS);
	}
}

void ccci_modis_hs2(kal_uint16 _boot_mode) 
{
}
#endif

void lte_ccci_init_handshake_phase1(void)
{
    MODEM_RUNTIME_DATA *share_data = ccci_get_share_data();

    /* CCCI HS1 & CCCI HS1 ACK */
#if defined(__HIF_CLDMA_SUPPORT__)
	ccci_cldma_hs1();	
#elif defined(__CCIFCORE_SUPPORT__)
	ccci_ccif_hs1();	
#elif defined (__HIF_SDIO_SUPPORT__)
	ccci_sdio_hs1();
#endif
#if !defined(__MTK_TARGET__) 
    ccci_modis_hs1();
#endif  

    /* Check the driver version from AP CCCI */
#if defined(__MTK_TARGET__)
    EXT_ASSERT(share_data->DriverVersion == CCCI_CURRENT_VERSION, share_data->DriverVersion, CCCI_CURRENT_VERSION, 0);
#endif

	return;
}

void lte_ccci_init_handshake_phase2(kal_uint16 _boot_mode) 
{
//#if (defined(__HIF_CLDMA_SUPPORT__)&& !defined(MT6290))
#if defined(__HIF_CLDMA_SUPPORT__)
	ccci_cldma_hs2(_boot_mode);	
#elif defined(__CCIFCORE_SUPPORT__)
	ccci_ccif_hs2(_boot_mode);	
#elif defined (__HIF_SDIO_SUPPORT__)
	ccci_sdio_hs2(_boot_mode);
#endif  
#if !defined(__MTK_TARGET__) 
    ccci_modis_hs2(_boot_mode);
#endif  

	return;
}

/*!
 * @function        ccci_task_init
 * @brief           
 *
 * @param 
 *
 * @return          kal_bool
 */  
kal_bool ccci_task_init(){
    return KAL_TRUE;
}

/*!
 * @function        ccci_task_main_init
 * @brief          
 *
 * @param 
 *
 * @return          kal_bool
 */  
kal_bool ccci_task_main_init(){
    return KAL_TRUE;
}


/*!
 * @function        ccci_main
 * @brief           For cccidev_task to pass ilm if there's any
 *
 * @param ilm       pointer to ilm_struct
 *
 * @return          void
 */  
void ccci_main(ilm_struct *ilm)
{
    ccci_trace(CCCI_TRACE, CCCI_MOD_API, CCCI_TR_RECEIVE_ILM, ilm->msg_id);
    switch (ilm->msg_id) {
        case MSG_ID_CCCI_DEBUG_QUERY_MD_STATUS:
        {
            // get ccci debug status
            ccci_debug_get_status_worker(); 
            break;
        }
        default:
            ccci_trace(CCCI_ERR, CCCI_MOD_API, CCCI_TR_ILM_MSG_ERR, ilm->msg_id);
        break;
    }  
}

