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
 *   ccci_fs.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Implements the CCCI FS Core
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
 * [CCCI FS] Support CCCI FS exception mode.
 *
 * removed!
 * removed!
 * [CCCI] CCCI new debug mechanism
 *
 * removed!
 * removed!
 * [CCCI] Add ROME chip version by API instead compile option
 *
 * removed!
 * removed!
 * [CCCI FS] Add CCCI FS DL trace log & sequence number between PS & L2
 *
 * removed!
 * removed!
 * [CCCI] Add & Maintain UT code
 *
 * removed!
 * removed!
 * [CCCI & RPC & FS] ASSERT enhancement
 *
 * removed!
 * removed!
 * [CCCI FS] Debug enhancement & Add log.
 *
 * removed!
 * removed!
 * [CCCI FS] For MT6595E1, change fs gpd & req buffer to non-cacheable address
 *
 * removed!
 * removed!
 * [CCCI] For MT6595, extend static polling buffer size to prevent memory corruption when CLDMA converts non-cacheable.
 *
 * removed!
 * removed!
 * 	CCCI_FS compact read and profile trace (sdio)
 *
 * removed!
 * removed!
 * [CCCI] Change feature: data[0] means send again or not.
 *
 * removed!
 * removed!
 * 	Shrink CCCI UL/DL buffer to 3.5KB
 *
 * removed!
 * removed!
 * [CCCI] Remove CCCI FS address check assert. 
 * Due to MT6595 used cache-able address (0xF) and conflict with send again command.
 *
 * removed!
 * removed!
 * Fix CCCIFS memory cpy offset issues
 *
 * removed!
 * removed!
 * fix modis build error
 *
 * removed!
 * removed!
 * a. Check-in cccifs new features (support 16KB I/O)
 * b. add __CCCIFS_SUPPORT__ option to related files
 *
 * removed!
 * removed!
 * MT6290 Rename CCCI Services
 *
 * removed!
 * removed!
 * [CCCI] CCCI_IMS 1st verison loopback support
 *
 * removed!
 * removed!
 * sync latest version of new features
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#include "fs_type.h"
#include "ccci_if.h"
#include "ccci_dev_if.h"
#include "ccci_fs.h"
#include "kal_public_api.h"  //for INLINE
#include "cache_sw.h"
#include "init.h"

kal_uint32 g_ccci_fs_ttt[10]; //total_tick
kal_uint32 g_ccci_fs_polling[2048];
kal_uint32 g_ccci_fs_ttc = 0; //total count

ccci_fs_device_t g_ccci_fs_int;
static CCCI_FS_DEBUG_STATUS_T ccci_fs_debug_status;

// The reason + QBM_HEAD_SIZE is for ROME E1, cldma needs to record this buff whether is cacheable or non-cacheable
kal_uint8 g_fs_polling_req_buf[FS_CCCI_POLLING_BUFF_SIZE + QBM_HEAD_SIZE];
// for exception mode rx gpd
kal_uint8 g_fs_polling_req_buf_rx1[FS_CCCI_POLLING_BUFF_SIZE + QBM_HEAD_SIZE];
kal_uint8 g_fs_polling_req_buf_rx2[FS_CCCI_POLLING_BUFF_SIZE + QBM_HEAD_SIZE];

/* non-free type TGPD poll for normal mode 16K MTU Tx */
static kal_uint8 ccci_fs_tgpd_pool[FS_CCCI_REQ_BUFFER_NUM][QBM_QUEUE_GET_MEM_SIZE(QBM_SIZE_TGPD, CCCI_FS_TGPD_COUNT) + CCCI_FS_TGPD_ALIGN_PAD];
static kal_uint8 ccci_fs_tbd_pool[FS_CCCI_REQ_BUFFER_NUM][QBM_QUEUE_GET_MEM_SIZE(QBM_SIZE_TGPD, CCCI_FS_TGPD_COUNT) + CCCI_FS_TGPD_ALIGN_PAD];

kal_uint32 ccci_fs_assert_dump_addr=0, ccci_fs_assert_dump_size =0;
CCCI_EXCEP_MEMORY_TYPE ccci_fs_assert_dump_type;

static __inline void CCCI_FS_SET_PORT_BUSY(kal_uint32 port_index){
    g_ccci_fs_int.FS_WriteIndex |= (0x1<<(port_index));
    g_ccci_fs_int.FS_CCCIBufCount++;     
}

static __inline void CCCI_FS_CLR_PORT_BUSY(kal_uint32 port_index){
    g_ccci_fs_int.FS_WriteIndex &= ~(0x1<<(port_index));
    g_ccci_fs_int.FS_CCCIBufCount--;     
}

static __inline kal_bool CCCI_FS_GET_PORT_BUSY(kal_uint32 port_index){
    return (((g_ccci_fs_int.FS_WriteIndex & (0x1<<(port_index))) != 0 )? KAL_TRUE : KAL_FALSE) ; 
}

static __inline kal_bool CCCI_FS_VALID_PORT_IDX(kal_uint32 port_index){
    return ((0 <= (port_index)) && (FS_CCCI_REQ_BUFFER_NUM > (port_index))? KAL_TRUE : KAL_FALSE) ; 
}

/*!
 * @function        ccci_fs_ior_init
 * @brief           initialize the pre-defined ior
 *
 * @return          void
 */
#if 0
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif
static void fs_pool_set_tgpd(kal_uint8 port_idx, kal_uint32 num_gpd, qbm_gpd *p_head, qbm_gpd *p_tail)
{
    CCCIDEV_QBM_ENQ((void*)p_head, (void*)p_tail, \
                    (void**)&g_ccci_fs_int.tgpd_pool[port_idx].pool_head, \
                    (void**)&g_ccci_fs_int.tgpd_pool[port_idx].pool_tail);
}
static kal_uint32 fs_pool_get_tgpd(kal_uint8 port_idx, kal_uint32 num_gpd, qbm_gpd **pp_head, qbm_gpd **pp_tail)
{
    kal_uint32 ret;
    ret = CCCIDEV_QBM_DEQ((void**)&g_ccci_fs_int.tgpd_pool[port_idx].pool_head, \
                    (void**)&g_ccci_fs_int.tgpd_pool[port_idx].pool_tail, \
                    num_gpd,\
                    (void**)pp_head, (void**)pp_tail);
	EXT_ASSERT(*pp_tail != NULL, 0,0,0);
    QBM_DES_SET_NEXT(*pp_tail, NULL);
    return ret;
}
static void ccci_fs_ior_init(void){
    bm_queue_config conf;
    kal_uint32 size;
    kal_uint8  *pool;
    kal_uint32 port_idx;
    qbm_gpd    *tmp_h, *tmp_t, *curr_gpd, *curr_bd, *next_gpd, *next_bd;

    kal_mem_set(&g_ccci_fs_int.tgpd_pool, 0, sizeof(fs_tgpd_pool));

    for(port_idx = 0; port_idx < FS_CCCI_REQ_BUFFER_NUM; port_idx ++ )
    {
        //4 <1> initialize the TBD pool
        kal_mem_set(&conf, 0, sizeof(bm_queue_config));
        qbm_init_q_config(&conf);
        size = qbm_queue_get_mem_size(QBM_TYPE_TBD, CCCI_FS_TGPD_COUNT);
        pool = ccci_fs_tbd_pool[port_idx];
        conf.buff_num = CCCI_FS_TGPD_COUNT;
        conf.p_mem_pool_str = pool;
        conf.p_mem_pool_end = pool + size;
        conf.b_cache_flush  = KAL_TRUE;
        conf.b_cache_invalid= KAL_TRUE;
        qbm_init_queue_non_free(QBM_TYPE_TBD, &conf, (void **)&tmp_h, (void **)&tmp_t);

        //4 <2> initialize the TGPD pool
        kal_mem_set(&conf, 0, sizeof(bm_queue_config));
        qbm_init_q_config(&conf);
        size = qbm_queue_get_mem_size(QBM_TYPE_TGPD, CCCI_FS_TGPD_COUNT);
        pool = ccci_fs_tgpd_pool[port_idx];
        conf.buff_num = CCCI_FS_TGPD_COUNT;
        conf.p_mem_pool_str = pool;
        conf.p_mem_pool_end = pool + size;
        conf.b_cache_flush  = KAL_TRUE;
        conf.b_cache_invalid= KAL_TRUE;
        qbm_init_queue_non_free(QBM_TYPE_TGPD, &conf, \
            (void **)&g_ccci_fs_int.tgpd_pool[port_idx].pool_head, \
            (void **)&g_ccci_fs_int.tgpd_pool[port_idx].pool_tail);
        QBM_DES_SET_NEXT(g_ccci_fs_int.tgpd_pool[port_idx].pool_tail, NULL);

        //4 <3>  format tgpd and tbd
        curr_gpd = g_ccci_fs_int.tgpd_pool[port_idx].pool_head;
        curr_bd = tmp_h;
        do
        {
            next_gpd = QBM_DES_GET_NEXT(curr_gpd);
            next_bd  = QBM_DES_GET_NEXT(curr_bd);

            QBM_DES_SET_HWO(curr_gpd);
            QBM_DES_SET_BDP(curr_gpd);
            QBM_DES_SET_DATAPTR(curr_gpd, curr_bd);
            QBM_DES_SET_HWO(curr_bd);
            QBM_DES_SET_EOL(curr_bd);
            QBM_DES_SET_NEXT(curr_bd, NULL);            

            QBM_CACHE_FLUSH(curr_bd, sizeof(qbm_gpd));
            QBM_CACHE_FLUSH(curr_gpd, sizeof(qbm_gpd));
            curr_gpd = next_gpd;
            curr_bd  = next_bd;

        }while(curr_gpd != NULL);
    }    
    
}

/*!
 * @function        ccci_fs_calc_buff_len
 * @brief           Calclulate the buffer length requirement 
 *
 * @param pLV       [IN] pointer to the array of local vaiable LV[num]
 * @param num       [IN] number of the local variables in pLV
 *
 * @return          total buffer length
 */
kal_uint32 ccci_fs_calc_buff_len(FS_CCCI_LV_T *pLV, kal_uint32 num)
{
    //FS_StreamBuffer_T fs_buf_tmp;
    FS_CCCI_LV_T      lv_t_tmp;
    kal_uint32 i;
    kal_uint32 curr_v_len;      /* current variable length */
    kal_uint32 total_len = 0;   /* total variable length */

    //4 <1> length FS_OP
    //total_len += sizeof(fs_buf_tmp.fs_operationID);

    //4 <2>  length argc
    total_len += sizeof(kal_uint32);

    for(i = 0; i < num; i++)
    { 
        /* WR8_DNR : adjusted to be 4-byte aligned */
        curr_v_len = ((pLV[i].len + 3) >> 2) << 2;
        //4 <3>  length arg_len and arg_value_len
        total_len += curr_v_len;
        total_len += sizeof(lv_t_tmp.len); /* additional kal_uint32 is for FS_CCCI_LV_T *p_curr_lv_t->len*/
    }

    //4 <4> length CCCI header
    //total_len += sizeof(CCCI_BUFF_T);

    return total_len;
}

/*!
 * @function        ccci_fs_enter_cs
 * @brief           Enter Critical Section
 *
 * @param void
 *
 * @return          void
 */
void ccci_fs_enter_cs(void)
{
    if (IS_CCCI_FS_NORMAL_MODE())
    {   
        /* [Normal Mode] */
        kal_take_enh_mutex(g_ccci_fs_int.ccci_fs_emutex);
    }else{
        /* [Polling Mode] or [Exception Mode] */
        g_ccci_fs_int.ccci_fs_fake_emutex++;
    }
}
/*!
 * @function        ccci_fs_enter_cs
 * @brief           Enter Critical Section
 *
 * @param void
 *
 * @return          void
 */
void ccci_fs_exit_cs(void)
{
    if (IS_CCCI_FS_NORMAL_MODE())
    {
        /* [Normal Mode] */
        kal_give_enh_mutex(g_ccci_fs_int.ccci_fs_emutex);
    }else{
        /* [Polling Mode] */
        g_ccci_fs_int.ccci_fs_fake_emutex--;
    }
}

/*!
 * @function        ccci_fs_dl_cb
 * @brief           FS channel downlink callback function
 *
 * @param channel   [IN] CCCI channel number
 * @param io_request[IN] io request callback
 *
 * @return          void
 */
void ccci_fs_dl_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* io_request){
#if 0
/* under construction !*/
#else
    qbm_gpd             *first_gpd;
    qbm_gpd             *last_gpd;
    qbm_gpd             *curr_gpd;
    qbm_gpd             *next_gpd;
    kal_bool            end_of_list = KAL_FALSE;
    ccci_io_request_t   *curr_ior;
    ccci_io_request_t   *next_ior;
    CCCI_BUFF_T         *pcccih;
    kal_uint32          port_idx;
    kal_uint32          num_gpd;

    for (curr_ior = io_request; curr_ior; curr_ior = next_ior) {
        next_ior  = curr_ior->next_request;
        first_gpd = curr_ior->first_gpd;
        last_gpd  = curr_ior->last_gpd;

        if (first_gpd && last_gpd){
            num_gpd = CCCIDEV_GET_GPD_LIST_SIZE(first_gpd, last_gpd);
            curr_ior->num_gpd = num_gpd;
            for (curr_gpd = first_gpd; curr_gpd && !end_of_list; curr_gpd = next_gpd) {
                next_gpd = QBM_DES_GET_NEXT(curr_gpd);
                end_of_list = (curr_gpd == last_gpd);

                //4 <1> obtain CCCI_H from GPD->ext
                if(0!=QBM_DES_GET_EXTLEN(curr_gpd)){
                    pcccih = (CCCI_BUFF_T *)QBM_DES_GET_EXT(curr_gpd);
                }else{
                    pcccih = (CCCI_BUFF_T *)CCCIDEV_GET_QBM_DATAPTR((void*)curr_gpd);
                }
                port_idx = pcccih->reserved;
                //4 <2> fs_pool_set_tgpd
                fs_pool_set_tgpd(port_idx, 1, curr_gpd, curr_gpd);

            } /* for (curr_gpd) */
        }else {/* if (first_gpd && last_gpd) */
            CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, KAL_FALSE,(kal_uint32)first_gpd, (kal_uint32)last_gpd, 0, 0, __LINE__);
        }
    } /*for (curr_ior...*/
#endif
}

kal_int32 ccci_fs_polling_io(CCCI_CHANNEL_T channel, qbm_gpd *p_gpd, kal_bool is_tx){
    kal_int32 ret = CCCI_FAIL;
    kal_uint32 gpd_num = 0;

    if(IS_CCCI_FS_POLLING_MODE()){ /* [Polling Mode] */
        ret = ccci_polling_io(channel, p_gpd, is_tx);
    }
    /* [Exception Mode] only support tx, rx implements in ccci_fs_wait_rx_exception */
    else if(IS_CCCI_FS_EXCEPTION_MODE() && is_tx == KAL_TRUE){ 
        ccci_except_set_gpd(channel, p_gpd, p_gpd);
        do{
            ccci_except_hif_st(channel);
            ccci_except_poll_gpd(channel, (void **)&p_gpd, (void **)&p_gpd, &gpd_num);
        }while(0 == gpd_num);
        ret = CCCI_SUCCESS;
    }
    else{ /* polling only support bootup stage & exception */
        CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, KAL_FALSE,kal_query_systemInit(), INT_QueryExceptionStatus(), is_tx, 0, __LINE__);
    }

    return ret;
}

void ccci_fs_ul_buff_process(CCCI_BUFF_T *p_buff){

    kal_uint32 *p_ccci_fs_buff;
    kal_uint32 port_index = p_buff->reserved;
    //kal_uint32 addr = CCCI_STREAM_ADDR(p_buff);

    //4 <0> NVRAM debug in MT6280
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
#endif
    //4 <1> copy the data in  RGPD to ( FS_REQ_BUF + buff->reserved )
    /* 
     * CCCI_H.reserved stores the CCCI_FS_REQ_BUF, this is the CCIF era usage.
     * Assigning the MD memory address by AP is a method might cause memory corruption issue.
     * After MT6290 we should be able to ma the p_buff->reserved = g_ccci_fs_int.FS_REQ_BUF[index] 
     * to prevent the memory corruption. 
     * 20121109 stay the legacy way, after dicussion with owner we might change to what i proposed above.
     *
     * CCCI_FS CCCI_H
     * data[0]  = FS buffer address; //g_ccci_fs_int.FS_REQ_BUF+p_buff->reserved
     * data[1]  = data length;      
     * channel  = ccci_channel; 
     * reserved = FS port index;
     */
    p_ccci_fs_buff = (kal_uint32*)(g_ccci_fs_int.FS_REQ_BUF + port_index);
    ccci_fs_trace(CCCI_FS_INFO, CCCI_FS_MOD_NORM_IO, CCCIFS_TR_RX_INFO, p_ccci_fs_buff, p_buff->data[0], p_buff->data[1], p_buff->channel, p_buff->reserved);

    /* assert if AP asks for accessing the memory out of region */
    /* ASSERT port index is valid */
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, CCCI_FS_VALID_PORT_IDX(port_index), port_index,0,0, 0, __LINE__);
    /* ASSERT: buffer size < max transfer size*/
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, (kal_uint32)p_buff->data[1] < FS_CCCI_MAX_BUF_SIZE,(kal_uint32)p_buff->data[1], FS_CCCI_MAX_BUF_SIZE,0, 0, __LINE__);
    ccci_debug_check_seq(p_buff); // check ccci seq
#ifdef __CCCI_FS_LT_4K_IO_ENABLE__
   /******************************************
    *
    *   FSM description for re-sent mechanism
    *	(ccci_fs_buff_state == CCCI_FS_BUFF_IDLE) ==> initial status & end status
    *	(ccci_fs_buff_state == CCCI_FS_BUFF_WAIT) ==> need to receive again
    *
    ******************************************/
    if(!CCCI_FS_PEER_REQ_SEND_AGAIN(p_buff)){

        if(g_ccci_fs_int.ccci_fs_buff_state[port_index] == CCCI_FS_BUFF_IDLE){
            // Due to MT6595 used cache-able address (0xF) and conflict with send again command.
            /* ASSERT addr (= data[0]) should assigned as buffer address, which should be equal to FS_REQ_BUF+p_buff->reserved */
            // ASSERT(addr == (kal_uint32)(g_ccci_fs_int.FS_REQ_BUF + port_index));
            /* copy data memory and CCCI header */
            kal_mem_cpy(p_ccci_fs_buff, (kal_uint32*)p_buff, p_buff->data[1]);
            /* don't need to update FS_Address */
        }else if(g_ccci_fs_int.ccci_fs_buff_state[port_index] == CCCI_FS_BUFF_WAIT){
            /* copy data memory and NULL, excluding CCCI header, OP id */
            kal_uint32 length = p_buff->data[1] - sizeof(CCCI_BUFF_T) - sizeof(kal_uint32);
            kal_mem_cpy((kal_uint32*)((kal_uint8*)p_ccci_fs_buff + g_ccci_fs_int.ccci_fs_buff_offset[port_index]),\
                        (kal_uint32*)((kal_uint8*)p_buff + sizeof(CCCI_BUFF_T) + sizeof(kal_uint32)),\
                        length);
            /* update CCCI header info */
            kal_mem_cpy((kal_uint32*)(p_ccci_fs_buff), (kal_uint32*)p_buff, sizeof(CCCI_BUFF_T));
        }else{
            /* No such ccci_fs_buff_state state */
            CCCI_FS_ASSERT(CCCI_FS_NORMAL_ASSERT, KAL_FALSE,0,0, 0, 0, __LINE__);
        }
        g_ccci_fs_int.ccci_fs_buff_state[port_index] = CCCI_FS_BUFF_IDLE;
        g_ccci_fs_int.ccci_fs_buff_offset[port_index] = 0;
        if (IS_CCCI_FS_NORMAL_MODE()){ 
            /*  
             * [Normal Mode]
             */
            kal_set_eg_events(g_ccci_fs_int.FS_CCCI_CSEvgrp, (1<<(port_index)), KAL_OR);
        }
        else{ /* [Polling Mode] or [Exception Mode]*/
	        g_ccci_fs_int.polling_step_trace = CCCI_FS_TRACE_FORMAT(port_index, CCCI_FS_TRACE_UL_BUFF_DONE);
	        ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_TRACE, (void *)&g_ccci_fs_int.polling_step_trace);
        }
        return;

    }else{

        if(g_ccci_fs_int.ccci_fs_buff_state[port_index] == CCCI_FS_BUFF_IDLE){
            /* only "OP id" and "data" size and "CCCI header", excluding the "tail NULL" */    
            //kal_uint32 length = p_buff->data[1] - sizeof(kal_uint32);
            kal_uint32 length = p_buff->data[1];
            kal_mem_cpy(p_ccci_fs_buff, (kal_uint32*)p_buff, length);
            g_ccci_fs_int.ccci_fs_buff_offset[port_index] += length;
        }else if(g_ccci_fs_int.ccci_fs_buff_state[port_index] == CCCI_FS_BUFF_WAIT){
            /* only "data" size, excluding CCCI header and OP id and the "tail NULL" */
            //kal_uint32 length = p_buff->data[1] - sizeof(CCCI_BUFF_T) - 2*sizeof(kal_uint32);
            kal_uint32 length = p_buff->data[1] - sizeof(CCCI_BUFF_T) - sizeof(kal_uint32);
            kal_mem_cpy((kal_uint32*)((kal_uint8*)p_ccci_fs_buff + g_ccci_fs_int.ccci_fs_buff_offset[port_index]),\
                  (kal_uint32*)((kal_uint8*)p_buff + sizeof(CCCI_BUFF_T) + sizeof(kal_uint32)),\
                         length);    /* CCCI_HEADER + FS_OP_ID */
            g_ccci_fs_int.ccci_fs_buff_offset[port_index] += length;
        }else{
            /* No such ccci_fs_buff_state state */
            CCCI_FS_ASSERT(CCCI_FS_NORMAL_ASSERT, KAL_FALSE,0,0, 0, 0, __LINE__);
        }
        g_ccci_fs_int.ccci_fs_buff_state[port_index] = CCCI_FS_BUFF_WAIT;

    }

    return;
#else    
    // Due to MT6595 used cache-able address (0xF) and conflict with send again command.
    /* ASSERT addr (= data[0]) should assigned as buffer address, which should be equal to FS_REQ_BUF+p_buff->reserved */
    // ASSERT(addr == (kal_uint32)(g_ccci_fs_int.FS_REQ_BUF + port_index));

    kal_mem_cpy(p_ccci_fs_buff, (kal_uint32*)p_buff+ sizeof(CCCI_BUFF_T), p_buff->data[1]- sizeof(CCCI_BUFF_T));
        
    //4 <3> set event, gFS_CCCI_CSEvgrp
    if (IS_CCCI_FS_NORMAL_MODE()){ 
        /*  
         * [Normal Mode]
         */
        kal_set_eg_events(g_ccci_fs_int.FS_CCCI_CSEvgrp, (1<<(port_index)), KAL_OR);
    }
    return;
#endif
}

/*!
 * @function        ccci_fs_ul_cb
 * @brief           FS channel uplink callback function, AP response
 *
 * @param channel   [IN] CCCI channel number
 * @param io_request[IN] io request callback
 *
 * @return          void
 */
void ccci_fs_ul_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* io_request){

    qbm_gpd             *first_gpd;
    qbm_gpd             *last_gpd;
    qbm_gpd             *curr_gpd;
    qbm_gpd             *next_gpd;
    kal_bool            end_of_list = KAL_FALSE;
    ccci_io_request_t   *curr_ior;
    ccci_io_request_t   *next_ior;
    kal_int32           ccci_ret;
    kal_uint32          rgpd_count = 0;
    kal_uint32          curr_hwo_rgpd, num_gpd;

    for (curr_ior = io_request; curr_ior; curr_ior = next_ior) {
        next_ior  = curr_ior->next_request;
        first_gpd = curr_ior->first_gpd;
        last_gpd  = curr_ior->last_gpd;
        //3 Note that, because GPD might be freeed in the following loop, we shall not access curr_ior from now.

        if (first_gpd && last_gpd){
            num_gpd = CCCIDEV_GET_GPD_LIST_SIZE(first_gpd, last_gpd);
            curr_ior->num_gpd = num_gpd;
            for (curr_gpd = first_gpd; curr_gpd && !end_of_list; curr_gpd = next_gpd) {
                next_gpd = QBM_DES_GET_NEXT(curr_gpd);
                end_of_list = (curr_gpd == last_gpd);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
                //4 <1> store rgpd buffer to CCCI_FS request buffer,  g_ccci_fs_int.FS_REQ_BUF[index]
                ccci_fs_ul_buff_process(CCCI_FS_GET_QBM_DATAPTR(curr_gpd));
                rgpd_count++;

            } /* for (curr_gpd) */
        }else {/* if (first_gpd && last_gpd) */
            CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, KAL_FALSE, (kal_uint32)first_gpd, (kal_uint32)last_gpd,0 , 0, __LINE__);
        }
        //4 <2> clear the entire gpd list for curr_ior, since the content has been copied to FS_REQ_BUF
        if (IS_CCCI_FS_NORMAL_MODE()){ 
            /* [Normal Mode] */
            CCCI_FS_RST_GPD_LIST(first_gpd, last_gpd);
        }
    } /*for (curr_ior...*/

    if (IS_CCCI_FS_NORMAL_MODE()){ 
        /* [Normal Mode] */
        ccci_fs_enter_cs();
        g_ccci_fs_int.hwo_rgpd_count -= rgpd_count;
        ccci_fs_exit_cs();
        
        //4 <3> reload the RGPD
        ccci_ret = ccci_write_gpd(channel, io_request, NULL);
        CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, CCCI_SUCCESS == ccci_ret, ccci_ret,0,0, 0, __LINE__);

	    ccci_fs_enter_cs();
        g_ccci_fs_int.hwo_rgpd_count += rgpd_count;
        curr_hwo_rgpd = g_ccci_fs_int.hwo_rgpd_count;
        ccci_fs_exit_cs();
        ccci_fs_trace(CCCI_FS_INFO, CCCI_FS_MOD_GPD, CCCIFS_TR_RGPD_RELOAD, rgpd_count, curr_hwo_rgpd);
    }
    return;
}

/*!
 * @function        ccci_fs_get_port
 * @brief           Obtain the CCCI FS port
 *
 * @param p_index   [IN/OUT] pointer to the fs port index  (<0: will be assgined a free one)
 *
 * @return          CCCI_RETURNVAL_T
 *                  CCCI_SUCCESS:   p_index contains the p_index assigned
 *                  CCCI_FAIL:  get port fail, p_index doesn't mean anything
 */  
kal_int32 ccci_fs_get_port(kal_int32 *p_index)
{

    kal_uint32 i, busy_port_cnt;
    kal_int32  ret = CCCI_FAIL;
    
    ccci_fs_enter_cs();
   
    if (FS_CCCI_USE_DEFAULT_INDEX == *p_index){

        busy_port_cnt = g_ccci_fs_int.FS_CCCIBufCount;

        CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, busy_port_cnt <= FS_CCCI_REQ_BUFFER_NUM, busy_port_cnt, FS_CCCI_REQ_BUFFER_NUM, 0, 0, __LINE__);
        if (FS_CCCI_REQ_BUFFER_NUM == busy_port_cnt){
            ccci_fs_exit_cs();
            ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_NORM_IO, CCCIFS_TR_GET_PORT_ERR, busy_port_cnt);
            return CCCI_FAIL;
        }

        for (i=0; i<FS_CCCI_REQ_BUFFER_NUM; i++){
            if(KAL_FALSE == CCCI_FS_GET_PORT_BUSY(i))
            {
                /* port i is avaliable */
                *p_index = i; 
                CCCI_FS_SET_PORT_BUSY(i);
                ret = CCCI_SUCCESS;
                break;
            }
        }
        
    }else{
    
    /* user specified the port index */
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, CCCI_FS_VALID_PORT_IDX(*p_index), *p_index,0,0, 0, __LINE__);
    if(KAL_FALSE == CCCI_FS_GET_PORT_BUSY(*p_index)){
            ret = CCCI_SUCCESS;
        }
    }
    ccci_fs_trace(CCCI_FS_TRACE, CCCI_FS_MOD_API, CCCIFS_TR_WRAPPER_DL_SEQ, g_ccci_fs_int.ccci_fs_dl_seq[*p_index]);
    ccci_fs_exit_cs();
    return ret;
}

/*!
 * @function        ccci_fs_put_port
 * @brief           Release the CCCI FS port
 *
 * @param index   [IN/OUT] the fs port index  (<0: will be assgined a free one)
 *
 * @return          CCCI_SUCCESS
 */  
kal_int32 ccci_fs_put_port(kal_int32 index)
{
    ccci_fs_enter_cs();
    CCCI_FS_CLR_PORT_BUSY(index);
    g_ccci_fs_int.ccci_fs_dl_seq[index]++;
    ccci_fs_exit_cs();
    return CCCI_SUCCESS;
}

/*!
 * @function        ccci_fs_put_buff
 * @brief           Fill the CCCI FS share memory FS_REQ_BUF for DL 
 *
 * @param index     [IN] fs port index (must be 0~FS_CCCI_REQ_BUFFER_NUM)
 * @param op        [IN] operation ID, FS_CCCI_OP_ID_T
 * @param pLV       [IN] pointer to the array of local vaiable LV[num]
 * @param num       [IN] number of the local variables in pLV
 *
 * @return          CCCI_RETURNVAL_T
 *                  CCCI_SUCCESS
 *                  CCCI_FAIL: fail to get TGPD
 */  
kal_int32 ccci_fs_put_buff(kal_int32 index, kal_uint32 op, FS_CCCI_LV_T *pLV, kal_uint32 num)
{

#ifdef __CCCI_FS_LT_4K_IO_ENABLE__
    /* 20121114 
     * After refering to MT6280 there's no LT 4KB CCCI_FS DL request,
     * but introducing the additional memcpy to CCCI_FS_BUF since
     * 1. flexibility to extend to support LT 4KB DL
     * 2. CCCI_FS no performance requirement
     */
    /* 20121219 from MT6280 current no request for DL LT 4KB application */
    FS_StreamBuffer_T *fs_buf;
    kal_uint8 *ptr;
    kal_uint32 *argc, *p_opid;
    kal_uint32 i;
    FS_CCCI_LV_T *p_curr_lv_t;  /* pointer of current local variable struct */
    kal_uint32 curr_v_len;      /* current variable length */
    kal_uint32 total_len = 0;   /* total variable length */
    kal_uint8  total_tgpd_num = 0;   /* total tgpd count */
    kal_uint32 to_alloc, num_alloc;
    kal_uint32 total_len_lv = 0;
    ccci_io_request_t  dl_ior = {0};
    qbm_gpd    *p_tgpd, *p_tbd;
    CCCI_BUFF_T *ccci_buff;
    kal_int32  ccci_ret;

    kal_uint32 gpd_payload_len;
    
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, CCCI_FS_VALID_PORT_IDX(index),index,0,0, 0, __LINE__);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, CCCI_FS_GET_PORT_BUSY(index),index,0,0, 0, __LINE__);

    total_len = ccci_fs_calc_buff_len(pLV, num);
    gpd_payload_len = (CCCI_FS_DL_BUF_SZ-sizeof(CCCI_BUFF_T)-CCCI_FS_OPID_SZ - CCCI_FS_DL_DUMMY_SZ);  /*DL MTU is 3584 - 128, bounded by AP*/
    total_tgpd_num = (total_len + gpd_payload_len - 1)/ gpd_payload_len;

    if (IS_CCCI_FS_NORMAL_MODE())
    {
        /* Only normal mode will need to allocate GPD */
        kal_mem_set(&dl_ior, 0 , sizeof(ccci_io_request_t));
        dl_ior.next_request = NULL;
        dl_ior.num_gpd = total_tgpd_num;
        to_alloc = total_tgpd_num;
        num_alloc = fs_pool_get_tgpd(index, to_alloc, &dl_ior.first_gpd, &dl_ior.last_gpd);
        /* it's a ping-pong buffer, gpd must enough */
        CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, num_alloc == to_alloc, num_alloc,to_alloc,0, 0, __LINE__);
    }

    //4 <1> fs_buf = CCCI_FS internal buffer for port[index]
    fs_buf = &g_ccci_fs_int.FS_REQ_BUF[index];

    //4 <2> initialize the fs_op
    fs_buf->fs_operationID = op;

    //4 <3> ptr = buffer pointer;
    ptr  = fs_buf->buffer;

    //4 <4> set the number of parameters
    argc = (kal_uint32 *)ptr;
    *argc = num;
    ptr += sizeof(kal_uint32);
    total_len_lv += sizeof(kal_uint32);
    
    //4 <5> set each parameter of pLV[i]
    for(i = 0; i < num; i++)
    { 
        /*
         * MAX size of pLV[i] = 2*sizeof(kal_uint32) + pLV[i].len
         * kal_uint32: data_len
         * pLV[i].len: real_data
         * kal_uint32: reserved space for 4B aligned
         */
        if ((ptr + sizeof(p_curr_lv_t->len) + sizeof(kal_uint32) + pLV[i].len ) > (fs_buf->buffer + FS_CCCI_MAX_BUF_SIZE))	
        {
            ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_SHM, CCCIFS_TR_PUT_BUF_ERR);
            /* CCCI_FS buffer size is 16KB */
            CCCI_FS_ASSERT(CCCI_FS_NORMAL_ASSERT, KAL_FALSE,0,0, 0, 0, __LINE__);
        }
        p_curr_lv_t = (FS_CCCI_LV_T *)ptr;

        //4 <5.1> set the data length
        p_curr_lv_t->len = pLV[i].len;
        /* WR8_DNR : adjusted to be 4-byte aligned */
        curr_v_len = ((pLV[i].len + 3) >> 2) << 2;
	    //4 
	    //4 <5.2> memcpy the data into CCCI_FS buffer
        kal_mem_cpy(&(p_curr_lv_t->val), pLV[i].val, pLV[i].len);

        //4 <5.3> update the total_len
        total_len_lv += curr_v_len;
        total_len_lv += sizeof(p_curr_lv_t->len); /* additional kal_uint32 is for p_curr_lv_t->len*/

        //4 <5.4> move ptr to next LV
        ptr += sizeof(p_curr_lv_t->len) + curr_v_len;
    }
    /* if this assert happen means there's memory corruption during the process*/
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, total_len_lv == total_len, total_len_lv, total_len,0, 0, __LINE__);

    // data[0] means send agian or not
    fs_buf->ccci_header.data[0] = 0x0;//(kal_uint32)(g_ccci_fs_int.FS_REQ_BUF+index); //&g_ccci_fs_int.FS_REQ_BUF[index]
    /* kal_uint32: op, kal_uint32: number of parameters */
    fs_buf->ccci_header.data[1] = total_len + sizeof(CCCI_BUFF_T) + CCCI_FS_OPID_SZ;  //fs_operationID
    fs_buf->ccci_header.reserved = index;
    fs_buf->ccci_header.channel = CCCI_FS_CHANNEL;

    if (IS_CCCI_FS_NORMAL_MODE()){ 
        /*  
         * [Normal Mode] ccci_write_gpd
         */
        kal_uint32 tx_len;
        kal_bool last_gpd;
        p_tgpd = dl_ior.first_gpd;
        ptr    = fs_buf->buffer;
        last_gpd = KAL_FALSE;
        for(i = 0; i < total_tgpd_num; i++)
        {
            CCCI_FS_ASSERT(CCCI_FS_NORMAL_ASSERT, NULL != p_tgpd,0,0, 0, 0, __LINE__);
            if(i == (total_tgpd_num -1)){
                /*last gpd*/
                tx_len = total_len;
                CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, tx_len <= CCCI_FS_DL_BUF_SZ - sizeof(CCCI_BUFF_T) - CCCI_FS_OPID_SZ - CCCI_FS_DL_DUMMY_SZ
                          ,tx_len, CCCI_FS_DL_BUF_SZ - sizeof(CCCI_BUFF_T) - CCCI_FS_OPID_SZ - CCCI_FS_DL_DUMMY_SZ, op, 0, __LINE__);
                last_gpd = KAL_TRUE;
            }else{
                tx_len = (CCCI_FS_DL_BUF_SZ - sizeof(CCCI_BUFF_T) - CCCI_FS_OPID_SZ - CCCI_FS_DL_DUMMY_SZ);
                total_len -= tx_len;
            }
            /* set the data ptr */
            p_tbd = QBM_DES_GET_DATAPTR(p_tgpd);
            CCCI_FS_ASSERT(CCCI_FS_NORMAL_ASSERT, NULL != p_tbd,0,0, 0, 0, __LINE__);
            p_tbd->p_data_tbd = ptr;
            ptr += tx_len;
            QBM_CACHE_FLUSH(p_tbd->p_data_tbd, tx_len);
            
            /* Store the DL CCCI header in the GPD extention part */
            ccci_buff = (CCCI_BUFF_T *)QBM_DES_GET_EXT(p_tgpd);
            QBM_DES_SET_EXTLEN(p_tgpd, sizeof(CCCI_BUFF_T));
            ccci_buff->data[0] = fs_buf->ccci_header.data[0];
            if(KAL_TRUE == last_gpd){
                ccci_buff->data[0] &= (~CCCI_FS_SEND_AGAIN);
            }else{
                ccci_buff->data[0] |= CCCI_FS_SEND_AGAIN;
            }
            ccci_buff->data[1]  = tx_len + sizeof(CCCI_BUFF_T) + CCCI_FS_OPID_SZ;
            ccci_buff->reserved = fs_buf->ccci_header.reserved;
            ccci_buff->channel  = fs_buf->ccci_header.channel;
            ccci_debug_add_seq(ccci_buff, CCCI_DEBUG_NOT_ASSERT_BIT); // add ccci seq
            QBM_DES_SET_DATALEN(p_tgpd, (tx_len+CCCI_FS_OPID_SZ));
            qbm_cal_set_checksum((kal_uint8 *)p_tgpd);
            QBM_CACHE_FLUSH(ccci_buff, sizeof(CCCI_BUFF_T));
            QBM_CACHE_FLUSH(p_tgpd, sizeof(qbm_gpd));
            
            /* Store the CCCI_FS Operation ID in p_tbd) */
            p_opid = (kal_uint32 *)QBM_DES_GET_EXT(p_tbd);
            QBM_DES_SET_EXTLEN(p_tbd, CCCI_FS_OPID_SZ);
            *p_opid = fs_buf->fs_operationID;
            QBM_DES_SET_DATALEN(p_tbd, tx_len);                        //only include local param length
            qbm_cal_set_checksum((kal_uint8 *)p_tbd);
            QBM_CACHE_FLUSH(p_opid, CCCI_FS_OPID_SZ);
            QBM_CACHE_FLUSH(p_tbd, sizeof(qbm_gpd));
            
            /* dump data*/
            ccci_fs_data_trace_dump(g_ccci_fs_int.ccci_fs_dl_seq[index],op, p_tbd->p_data_tbd, CCCI_FS_DL_DUMP_SIZE);
            /* copy to share memory */
            kal_mem_cpy((void *)ccci_fs_assert_dump_addr, (void *)p_tbd->p_data_tbd, ccci_fs_assert_dump_size);
            p_tgpd = QBM_DES_GET_NEXT(p_tgpd);
        }
    
        ccci_ret = ccci_write_gpd(CCCI_FS_CHANNEL, &dl_ior, NULL);

        if(CCCI_SUCCESS!= ccci_ret){
            /* release TGPD */
            fs_pool_set_tgpd(index, total_tgpd_num, dl_ior.first_gpd, dl_ior.last_gpd);
            ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_NORM_IO, CCCIFS_TR_DL_CCCI_W_ERR, ccci_ret);
            return CCCI_FAIL;
        }
    }else{
        /*  
         * [Polling Mode]ccci_polling_io
         */
        kal_int32 ret;
        qbm_gpd *p_gpd = g_ccci_fs_int.p_polling_gpd;
        kal_uint8 *cur_ptr;    /* pointer of start point of data buffer (exclud CCCI_H and OPID) */
        kal_uint32 tx_len;
        kal_bool last_gpd;

        //debug purpose
        //kal_uint32 tmp_len; 
       
        ptr = (kal_uint8 *) (g_ccci_fs_int.FS_REQ_BUF+index);
        last_gpd = KAL_FALSE;

        CCCI_FS_ASSERT(CCCI_FS_NORMAL_ASSERT, NULL != p_gpd,0,0, 0, 0, __LINE__);

        /* Reset Polling GPD */
        //*(kal_uint32*)p_gpd = (QBM_CCCI_COMM_DATA_LEN << 16) | 1;   /* For GPD it will set HWO = 1 and clear checksum */
        CCCI_INIT_RESET_FLAG_CHECKSUM_ALLOWLEN((kal_uint32 *)p_gpd, CCCI_FS_DL_BUF_SZ, DES_FLAG_BIT_HWO);
        CCCI_INIT_RESET_DATALEN_EXTLEN((kal_uint32 *)p_gpd);
        CCCI_INIT_RESET_COMMON_DATA((kal_uint32 *)p_gpd);

        /* Set CCCI header and FS Operation ID (this part is fixed for each transmission)*/
        //tmp_len = sizeof(CCCI_BUFF_T)+sizeof(kal_uint32);
        kal_mem_cpy(CCCI_FS_GET_QBM_DATAPTR(p_gpd), &(g_ccci_fs_int.FS_REQ_BUF[index]), (sizeof(CCCI_BUFF_T)+sizeof(kal_uint32)));
        ptr += (sizeof(CCCI_BUFF_T)+sizeof(kal_uint32));

        /* Update fixed part address */
        cur_ptr = (kal_uint8 *)CCCI_FS_GET_QBM_DATAPTR(p_gpd);
        cur_ptr += (sizeof(CCCI_BUFF_T)+sizeof(kal_uint32));
        
        for(i = 0; i < total_tgpd_num; i++)
        {
            if(i == (total_tgpd_num -1)){
                /*last gpd*/
                tx_len = total_len;
                CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, tx_len <= CCCI_FS_DL_BUF_SZ - sizeof(CCCI_BUFF_T) - CCCI_FS_OPID_SZ - CCCI_FS_DL_DUMMY_SZ,
                           tx_len,CCCI_FS_DL_BUF_SZ - sizeof(CCCI_BUFF_T) - CCCI_FS_OPID_SZ - CCCI_FS_DL_DUMMY_SZ,op, 0, __LINE__);
                last_gpd = KAL_TRUE;
            }else{
                tx_len = (CCCI_FS_DL_BUF_SZ - sizeof(CCCI_BUFF_T) - CCCI_FS_OPID_SZ - CCCI_FS_DL_DUMMY_SZ);
                total_len -= tx_len;
            }
    
            /*Copy data*/
            kal_mem_cpy(cur_ptr, ptr, tx_len);
            ptr += tx_len;

            ccci_buff = (CCCI_BUFF_T *) CCCI_FS_GET_QBM_DATAPTR(p_gpd);
            /* set the indication bit */
            if(KAL_TRUE == last_gpd){
                ccci_buff->data[0] &= (~CCCI_FS_SEND_AGAIN);
            }else{
                ccci_buff->data[0] |= CCCI_FS_SEND_AGAIN;
            }
            /* set total len in ccci header*/
            ccci_buff->data[1]  = tx_len + sizeof(CCCI_BUFF_T) + CCCI_FS_OPID_SZ;
            ccci_buff->channel  = fs_buf->ccci_header.channel;
            ccci_debug_add_seq(ccci_buff, CCCI_DEBUG_ASSERT_BIT); // add ccci seq
            QBM_DES_SET_DATALEN(p_gpd, (tx_len + CCCI_FS_OPID_SZ + sizeof(CCCI_BUFF_T)));            
            qbm_cal_set_checksum((kal_uint8 *)p_gpd);
            QBM_CACHE_FLUSH(p_gpd, sizeof(qbm_gpd));
            QBM_CACHE_FLUSH(CCCI_FS_GET_QBM_DATAPTR(p_gpd), (tx_len + CCCI_FS_OPID_SZ + sizeof(CCCI_BUFF_T)));
            
	        g_ccci_fs_int.polling_step_trace = CCCI_FS_TRACE_FORMAT(op, CCCI_FS_TRACE_PUT_BUFF_START) | (i << 12);
	        ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_TRACE, (void *)&g_ccci_fs_int.polling_step_trace);
			 
            ret = ccci_fs_polling_io(CCCI_FS_CHANNEL, p_gpd, KAL_TRUE);

            g_ccci_fs_int.polling_step_trace = CCCI_FS_TRACE_FORMAT(op, CCCI_FS_TRACE_PUT_BUFF_END) | (i << 12);
	        ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_TRACE, (void *)&g_ccci_fs_int.polling_step_trace);
            /* ASSERT while ccci_polling_io timeout @ 2sec*/
            CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, CCCI_SUCCESS == ret, ret,0,0, 0, __LINE__);
        }

    }
    return CCCI_SUCCESS;
    
#else
    FS_StreamBuffer_T *fs_buf;
    kal_uint8 *ptr;
    kal_uint32 *argc;
    kal_uint32 i;
    FS_CCCI_LV_T *p_curr_lv_t;  /* pointer of current local variable struct */
    kal_uint32 curr_v_len;      /* current variable length */
    kal_uint32 total_len = 0;   /* total variable length */
    kal_int32  retry = FS_CCCI_MAX_RETRY;
    kal_int32  ccci_ret;
    kal_uint32 to_alloc, num_alloc;
    ccci_io_request_t  dl_ior;
    qbm_gpd    *p_tgpd;
    void       *p_data;
    
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, CCCI_FS_VALID_PORT_IDX(index),index,0,0, 0, __LINE__);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, CCCI_FS_GET_PORT_BUSY(index),index,0,0, 0, __LINE__);
    //4 <1> fs_buf = CCCI_FS internal buffer for port[index]
    fs_buf = &g_ccci_fs_int.FS_REQ_BUF[index];

    //4 <2> initialize the fs_op
    fs_buf->fs_operationID = op;
    total_len += sizeof(fs_buf->fs_operationID);

    //4 <3> ptr = buffer pointer;
    ptr  = fs_buf->buffer;

    //4 <4> set the number of parameters
    argc = (kal_uint32 *)ptr;
    *argc = num;
    ptr += sizeof(kal_uint32);
    total_len += sizeof(kal_uint32);

    //4 <5> set each parameter of pLV[i]
    for(i = 0; i < num; i++)
    { 
        /*
         * MAX size of pLV[i] = 2*sizeof(kal_uint32) + pLV[i].len
         * kal_uint32: data_len
         * pLV[i].len: real_data
         * kal_uint32: reserved space for 4B aligned
         */
        if ((ptr + sizeof(p_curr_lv_t->len) + sizeof(kal_uint32) + pLV[i].len ) > (fs_buf->buffer + FS_CCCI_MAX_BUF_SIZE))	
        {
            ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_SHM, CCCIFS_TR_PUT_BUF_ERR);
            /* CCCI_FS buffer size is 16KB */
            CCCI_FS_ASSERT(CCCI_FS_NORMAL_ASSERT, KAL_FALSE,0,0, 0, 0, __LINE__);
        }
        p_curr_lv_t = (FS_CCCI_LV_T *)ptr;

        //4 <5.1> set the data length
        p_curr_lv_t->len = pLV[i].len;
        /* WR8_DNR : adjusted to be 4-byte aligned */
        curr_v_len = ((pLV[i].len + 3) >> 2) << 2;
	    //4 
	    //4 <5.2> memcpy the data into CCCI_FS buffer
        kal_mem_cpy(&(p_curr_lv_t->val), pLV[i].val, pLV[i].len);

        //4 <5.3> update the total_len
        total_len += curr_v_len;
        total_len += sizeof(p_curr_lv_t->len); /* additional kal_uint32 is for p_curr_lv_t->len*/

        //4 <5.4> move ptr to next LV
        ptr += sizeof(p_curr_lv_t->len) + curr_v_len;
    }


    total_len += sizeof(CCCI_BUFF_T);
    // data[0] means send agian or not
    fs_buf->ccci_header.data[0] = 0x0;//(kal_uint32)(g_ccci_fs_int.FS_REQ_BUF+index); //&g_ccci_fs_int.FS_REQ_BUF[index]
    /* kal_uint32: op, kal_uint32: number of parameters */
    fs_buf->ccci_header.data[1] = total_len; 
    fs_buf->ccci_header.reserved = index;
    fs_buf->ccci_header.channel = CCCI_FS_CHANNEL;

    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, total_len <= CCCI_FS_DL_BUF_SZ, total_len, CCCI_FS_DL_BUF_SZ, 0 , 0, __LINE__);
    if (IS_CCCI_FS_NORMAL_MODE()){ 
        /*  
         * [Normal Mode] ccci_write_gpd
         */
        //4 <6> allocate TGPD
        to_alloc = 1;

        dl_ior.next_request = NULL;
        dl_ior.num_gpd = 1; 

        do{
            num_alloc = qbmt_alloc_q_no_tail(CCCI_FS_DL_BUF_TYPE, to_alloc, (void **)&dl_ior.first_gpd, (void **)&dl_ior.last_gpd);
            retry--;
        }while((num_alloc != to_alloc) && (retry > 0));

        if (num_alloc != to_alloc)
        {
            ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_NORM_IO, CCCIFS_TR_RGPD_DL_GET_TGPD_ERR, to_alloc, num_alloc);
            return CCCI_FAIL;
        }
        QBM_DES_SET_NEXT(dl_ior.last_gpd, NULL);

        //4 <7> format and ccci_write_gpd
        p_tgpd = dl_ior.first_gpd;
        p_data = CCCI_FS_GET_QBM_DATAPTR(p_tgpd);
        CCCI_FS_SET_QBM_DATALEN(p_tgpd, total_len);
        kal_mem_cpy(p_data, &(g_ccci_fs_int.FS_REQ_BUF[index]), total_len);
        
        ccci_ret = ccci_write_gpd(CCCI_FS_CHANNEL, &dl_ior, NULL);

        if(CCCI_SUCCESS!= ccci_ret){
            /* release TGPD */
            qbmt_dest_q(dl_ior.first_gpd, dl_ior.last_gpd);
            ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_NORM_IO, CCCIFS_TR_DL_CCCI_W_ERR, ccci_ret);
            return CCCI_FAIL;
        }
    }else{
        /*  
         * [Polling Mode]ccci_polling_io
         */
        kal_int32 ret;
        qbm_gpd *p_gpd = g_ccci_fs_int.p_polling_gpd;
        CCCI_BUFF_T *ccci_buff;

        CCCI_INIT_RESET_DATALEN_EXTLEN((kal_uint32 *)p_gpd);
        CCCI_INIT_RESET_COMMON_DATA((kal_uint32 *)p_gpd);
        ccci_buff = QBM_DES_GET_DATAPTR(p_gpd);
        QBM_DES_SET_DATALEN(p_gpd, total_len);
        kal_mem_cpy(CCCI_FS_GET_QBM_DATAPTR(p_gpd), &(g_ccci_fs_int.FS_REQ_BUF[index]), total_len);
        QBM_CACHE_FLUSH(ccci_buff, total_len);
        
        ret = ccci_fs_polling_io(CCCI_FS_CHANNEL, p_gpd, KAL_TRUE);
        /* ASSERT while ccci_polling_io timeout @ 2sec*/
        CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, CCCI_SUCCESS == ret, ret,0,0, 0, __LINE__);

    }
    return CCCI_SUCCESS;
#endif

}

/*!
 * @function        ccci_fs_get_buff
 * @brief           Obtain the CCCI FS share memory FS_REQ_BUF which received from AP
 *
 * @param index     [IN] fs port index (must be 0~FS_CCCI_REQ_BUFFER_NUM)
 * @param op        [IN] operation ID, FS_CCCI_OP_ID_T
 * @param pLV       [IN/OUT] pointer to the array of variables returned by AP LV[num]
 * @param num       [IN/OUT] number of the variables in pLV user expected 
 *
 * @return          CCCI_SUCCESS
 *                     
 */  
kal_int32 ccci_fs_get_buff(kal_int32 index, kal_uint32 op, FS_CCCI_LV_T *pLV, kal_uint32 *num)
{
    kal_uint32 i, no_copy = 0;
    FS_StreamBuffer_T *fs_buf;
    kal_uint8 *ptr;
    FS_CCCI_LV_T *pTmp;
    volatile kal_uint32 opidbitmap = 0;
   
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, CCCI_FS_VALID_PORT_IDX(index),index,0,0, 0, __LINE__);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, CCCI_FS_GET_PORT_BUSY(index),index,0,0, 0, __LINE__);

    fs_buf = &g_ccci_fs_int.FS_REQ_BUF[index];

    if (op && (fs_buf->fs_operationID != (FS_CCCI_API_RESP_ID | op)))
    {
	    ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_SHM, CCCIFS_TR_OPID_NG);
        CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, KAL_FALSE, (FS_CCCI_API_RESP_ID | op), fs_buf->fs_operationID,index, 0, __LINE__);
    }

    ptr = fs_buf->buffer;
   
    // entry count
    pTmp = (FS_CCCI_LV_T *)ptr;
    if (op)
    {
        if(*num != pTmp->len){
            ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_SHM, CCCIFS_TR_OPID_NG);
            CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, KAL_FALSE, *num, pTmp->len,op, 0, __LINE__);
        }
    }else{
        *num = pTmp->len;
        no_copy = 1;
        ccci_fs_trace(CCCI_FS_WARN, CCCI_FS_MOD_SHM, CCCIFS_TR_NO_COPY);
    }

    if(op == FS_CCCI_OP_CMPTREAD)
    {
        //bypass the num memory size
        ptr += sizeof(kal_uint32);
        //fill bitmap and return value
        pTmp = (FS_CCCI_LV_T *)ptr;
        pLV[0].len = pTmp->len;
        kal_mem_cpy(pLV[0].val, ptr + sizeof(kal_uint32), pLV[0].len);
        //retrive bitmap
        opidbitmap = *((kal_uint32*)(pLV[0].val));
        //update ptr
        ptr += sizeof(kal_uint32) + (((pTmp->len + 3) >> 2) << 2);

        //Fill GETFILEESIZE result
        pTmp = (FS_CCCI_LV_T *)ptr;
        pLV[1].len = pTmp->len;
        if(opidbitmap & NVRAM_FS_CMPT_GETFILESIZE)
        {
            kal_mem_cpy(pLV[1].val, ptr + sizeof(kal_uint32), pLV[1].len);
        }
        //update ptr
        ptr += sizeof(kal_uint32) + (((pTmp->len + 3) >> 2) << 2);

        //Fill Read length
        pTmp = (FS_CCCI_LV_T *)ptr;
        pLV[2].len = pTmp->len;
        if(opidbitmap & NVRAM_FS_CMPT_READ)
        {
            kal_mem_cpy(pLV[2].val, ptr + sizeof(kal_uint32), pLV[2].len);
        }
        //update ptr
        ptr += sizeof(kal_uint32) + (((pTmp->len + 3) >> 2) << 2);

        //Fill Read Data
        pTmp = (FS_CCCI_LV_T *)ptr;
        pLV[3].len = pTmp->len;
        if(opidbitmap & NVRAM_FS_CMPT_READ)
        {
            kal_mem_cpy(pLV[3].val, ptr + sizeof(kal_uint32), pLV[3].len);
        }
        //update ptr
        ptr += sizeof(kal_uint32) + (((pTmp->len + 3) >> 2) << 2);

    }
    else
    {
        //bypass the num memory size
        ptr += sizeof(kal_uint32);
        for(i = 0; i < *num; i++)
        {
            pTmp = (FS_CCCI_LV_T *)ptr;
            if (op && (pLV[i].len < pTmp->len))
            {
                ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_SHM, CCCIFS_TR_LV_LEN_NG, i, pLV[i].len, pTmp->len);
                CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, KAL_FALSE, op, pLV[i].len, pTmp->len, 0, __LINE__);
            }

            pLV[i].len = pTmp->len;
            if (no_copy){
                pLV[i].val = (void *)(ptr + sizeof(kal_uint32));
            }else{
                kal_mem_cpy(pLV[i].val, ptr + sizeof(kal_uint32), pLV[i].len);
            }

            /* WR8_DNR : adjusted to be 4-byte aligned */
            ptr += sizeof(kal_uint32) + (((pTmp->len + 3) >> 2) << 2);
        }
    }
   
    return CCCI_SUCCESS;
}


/*!
 * @function        ccci_fs_get_buff
 * @brief           This is a blocking call, its returning means
 *                  Normal Mode: CCCI_SDIO UL callback and port event has been set
 *                  Polling Mode: There's ul data returned from AP. 
 *                               Since it only applies at single thread mode, CCCI FS should not have multiple port access
 *
 * @param index     [IN] fs port index (must be 0~FS_CCCI_REQ_BUFFER_NUM)
 *
 * @return          void
 */
void ccci_fs_wait_rx(kal_int32 index)
{
    kal_status ev_result        = KAL_NOT_PRESENT;
    kal_uint32 retrieved_events = 0;
    kal_int32  ret = CCCI_FAIL;
    kal_uint32 rcv_size;
    kal_uint8  *p_data = NULL;
    ccci_io_request_t io_request;

    if (IS_CCCI_FS_NORMAL_MODE()){ 
    /*  
     * [Normal Mode]
     * SDIOCore callback --> CCCI Callback --> ccci_fs_ul_cb ( store ul data to FS_REQ_BUF and set port event ) 
     */
        ev_result = kal_retrieve_eg_events(g_ccci_fs_int.FS_CCCI_CSEvgrp, (1<<index), KAL_AND_CONSUME, &retrieved_events, KAL_SUSPEND);
        if (KAL_SUCCESS != ev_result){
             ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_SHM, CCCIFS_TR_RXEVNT_NG, ev_result);   
        }
    }else{
    /*  
     * [Polling Mode]
     * ccci_polling_io --> ccci_fs_ul_cb ( store ul data to FS_REQ_BUF and set port event ) 
     */

#ifdef __CCCI_FS_LT_4K_IO_ENABLE__
        kal_bool next_polling;
        
        do
        {
            /*polling time out SDIO_POLLING_TIMOUT*/
            QBM_DES_SET_ALLOW_LEN(g_ccci_fs_int.p_polling_gpd, CCCI_FS_UL_BUF_SZ);

            g_ccci_fs_int.polling_step_trace = CCCI_FS_TRACE_FORMAT(index, CCCI_FS_TRACE_WAIT_RX_START);
            ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_TRACE, (void *)&g_ccci_fs_int.polling_step_trace);

            ret = ccci_fs_polling_io(CCCI_FS_ACK_CHANNEL, g_ccci_fs_int.p_polling_gpd, KAL_FALSE);
            CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, CCCI_SUCCESS == ret,ret,0,0, 0, __LINE__);

            g_ccci_fs_int.polling_step_trace = CCCI_FS_TRACE_FORMAT(index, CCCI_FS_TRACE_WAIT_RX_END);
            ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_TRACE, (void *)&g_ccci_fs_int.polling_step_trace);

            rcv_size = QBM_DES_GET_DATALEN(g_ccci_fs_int.p_polling_gpd);
            p_data = QBM_DES_GET_DATAPTR(g_ccci_fs_int.p_polling_gpd);
            QBM_CACHE_INVALID(p_data, rcv_size);

            /*check if it needs next polling*/
            next_polling = CCCI_FS_PEER_REQ_SEND_AGAIN(p_data);

            io_request.next_request = NULL;
            io_request.first_gpd = g_ccci_fs_int.p_polling_gpd;
            io_request.last_gpd = g_ccci_fs_int.p_polling_gpd;
            io_request.num_gpd = 1;
            // copy to share memory
            kal_mem_cpy((void *)ccci_fs_assert_dump_addr, (void *)QBM_DES_GET_DATAPTR(g_ccci_fs_int.p_polling_gpd), ccci_fs_assert_dump_size);
            ccci_fs_ul_cb(CCCI_FS_ACK_CHANNEL,  &io_request);
        }while(next_polling);
    
#else
        /*polling time out SDIO_POLLING_TIMOUT*/
        QBM_DES_SET_ALLOW_LEN(g_ccci_fs_int.p_polling_gpd, CCCI_FS_UL_BUF_SZ);
        ret = ccci_fs_polling_io(CCCI_FS_ACK_CHANNEL, g_ccci_fs_int.p_polling_gpd, KAL_FALSE);
        /* 20121213 ASSERT after timeout per HIF SDIO polling API limitation */
        /* ASSERT while ccci_polling_io timeout @ 2sec*/
        CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, CCCI_SUCCESS == ret, ret,0,0, 0, __LINE__);

        rcv_size = QBM_DES_GET_DATALEN(g_ccci_fs_int.p_polling_gpd);
        p_data = QBM_DES_GET_DATAPTR(g_ccci_fs_int.p_polling_gpd);
        QBM_CACHE_INVALID(p_data, rcv_size);

        io_request.next_request = NULL;
        io_request.first_gpd = g_ccci_fs_int.p_polling_gpd;
        io_request.last_gpd = g_ccci_fs_int.p_polling_gpd;
        io_request.num_gpd = 1;
            
        ccci_fs_ul_cb(CCCI_FS_ACK_CHANNEL,  &io_request);
#endif
    }
}

void ccci_fs_wait_rx_exception(kal_int32 index)
{
    kal_uint32 rcv_size;
    kal_uint8  *p_data = NULL;
    ccci_io_request_t io_request;
    qbm_gpd *ccci_fs_excep_rx_first_gpd;
    qbm_gpd *ccci_fs_excep_rx_last_gpd;
    static kal_uint32 ccci_fs_excep_first_reload_gpd =0;
    kal_uint32 gpd_num;
    kal_bool next_polling;

    // exception mode needs to reload 1 rgpd to hif first
    if(ccci_fs_excep_first_reload_gpd ==0){
        // Initial rx gpd1
        CCCI_INIT_RESET_FLAG_CHECKSUM_ALLOWLEN((kal_uint32 *)g_ccci_fs_int.p_polling_gpd_rx1, CCCI_FS_UL_BUF_SZ, DES_FLAG_BIT_HWO);
        CCCI_INIT_RESET_DATALEN_EXTLEN((kal_uint32 *)g_ccci_fs_int.p_polling_gpd_rx1);
        CCCI_INIT_RESET_COMMON_DATA((kal_uint32 *)g_ccci_fs_int.p_polling_gpd_rx1);
        QBM_DES_SET_ALLOW_LEN(g_ccci_fs_int.p_polling_gpd_rx1, CCCI_FS_UL_BUF_SZ);
        QBM_DES_SET_NEXT(g_ccci_fs_int.p_polling_gpd_rx1, g_ccci_fs_int.p_polling_gpd_rx2);   
        QBM_CACHE_FLUSH(g_ccci_fs_int.p_polling_gpd_rx1, sizeof(qbm_gpd));
        // Initial rx gpd2
        CCCI_INIT_RESET_FLAG_CHECKSUM_ALLOWLEN((kal_uint32 *)g_ccci_fs_int.p_polling_gpd_rx2, CCCI_FS_UL_BUF_SZ, DES_FLAG_BIT_HWO);
        CCCI_INIT_RESET_DATALEN_EXTLEN((kal_uint32 *)g_ccci_fs_int.p_polling_gpd_rx2);
        CCCI_INIT_RESET_COMMON_DATA((kal_uint32 *)g_ccci_fs_int.p_polling_gpd_rx2);
        QBM_DES_SET_ALLOW_LEN(g_ccci_fs_int.p_polling_gpd_rx2, CCCI_FS_UL_BUF_SZ);
        
        QBM_CACHE_FLUSH(g_ccci_fs_int.p_polling_gpd_rx2, sizeof(qbm_gpd));
        // reload to hif
        ccci_except_set_gpd(CCCI_FS_ACK_CHANNEL, g_ccci_fs_int.p_polling_gpd_rx1, g_ccci_fs_int.p_polling_gpd_rx2);
        ccci_fs_excep_first_reload_gpd = 1;
    }
#ifdef __CCCI_FS_LT_4K_IO_ENABLE__
    do
    {
        g_ccci_fs_int.polling_step_trace = CCCI_FS_TRACE_FORMAT(index, CCCI_FS_TRACE_WAIT_RX_START);
        ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_TRACE, (void *)&g_ccci_fs_int.polling_step_trace);

        gpd_num = 0;
        do{
            ccci_except_hif_st(CCCI_FS_ACK_CHANNEL);
            ccci_except_poll_gpd(CCCI_FS_ACK_CHANNEL, (void **)&ccci_fs_excep_rx_first_gpd, (void **)&ccci_fs_excep_rx_last_gpd, &gpd_num);
        }while(0 == gpd_num);
        CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, ccci_fs_excep_rx_first_gpd == ccci_fs_excep_rx_last_gpd,(kal_uint32)ccci_fs_excep_rx_first_gpd, (kal_uint32)ccci_fs_excep_rx_last_gpd,0, 0, __LINE__);
        
        g_ccci_fs_int.polling_step_trace = CCCI_FS_TRACE_FORMAT(index, CCCI_FS_TRACE_WAIT_RX_END);
        ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_TRACE, (void *)&g_ccci_fs_int.polling_step_trace);

        rcv_size = QBM_DES_GET_DATALEN(ccci_fs_excep_rx_first_gpd);
        p_data = QBM_DES_GET_DATAPTR(ccci_fs_excep_rx_first_gpd);
        QBM_CACHE_INVALID(p_data, rcv_size);

        /*check if it needs next polling*/
        next_polling = CCCI_FS_PEER_REQ_SEND_AGAIN(p_data);

        io_request.next_request = NULL;
        io_request.first_gpd = ccci_fs_excep_rx_first_gpd;
        io_request.last_gpd = ccci_fs_excep_rx_first_gpd;
        io_request.num_gpd = 1;
        // copy to share memory
        kal_mem_cpy((void *)ccci_fs_assert_dump_addr, (void *)QBM_DES_GET_DATAPTR(ccci_fs_excep_rx_first_gpd), ccci_fs_assert_dump_size);
        ccci_fs_ul_cb(CCCI_FS_ACK_CHANNEL,  &io_request);

        // reload rgpd
        CCCI_INIT_RESET_FLAG_CHECKSUM_ALLOWLEN((kal_uint32 *)ccci_fs_excep_rx_first_gpd, CCCI_FS_UL_BUF_SZ, DES_FLAG_BIT_HWO);
        CCCI_INIT_RESET_DATALEN_EXTLEN((kal_uint32 *)ccci_fs_excep_rx_first_gpd);
        CCCI_INIT_RESET_COMMON_DATA((kal_uint32 *)ccci_fs_excep_rx_first_gpd);
        QBM_DES_SET_ALLOW_LEN(ccci_fs_excep_rx_first_gpd, CCCI_FS_UL_BUF_SZ);
        QBM_CACHE_FLUSH(ccci_fs_excep_rx_first_gpd, sizeof(qbm_gpd));
        ccci_except_set_gpd(CCCI_FS_ACK_CHANNEL, ccci_fs_excep_rx_first_gpd, ccci_fs_excep_rx_first_gpd);
    }while(next_polling);
    
#else
    
    g_ccci_fs_int.polling_step_trace = CCCI_FS_TRACE_FORMAT(index, CCCI_FS_TRACE_WAIT_RX_START);
    ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_TRACE, (void *)&g_ccci_fs_int.polling_step_trace);

    gpd_num = 0;
    do{
        ccci_except_hif_st(CCCI_FS_ACK_CHANNEL);
        ccci_except_poll_gpd(CCCI_FS_ACK_CHANNEL, (void **)&ccci_fs_excep_rx_first_gpd, (void **)&ccci_fs_excep_rx_last_gpd, &gpd_num);
    }while(0 == gpd_num);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, ccci_fs_excep_rx_first_gpd == ccci_fs_excep_rx_last_gpd,(kal_uint32)ccci_fs_excep_rx_first_gpd, (kal_uint32)ccci_fs_excep_rx_last_gpd,0, 0, __LINE__);
    
    
    g_ccci_fs_int.polling_step_trace = CCCI_FS_TRACE_FORMAT(index, CCCI_FS_TRACE_WAIT_RX_END);
    ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_TRACE, (void *)&g_ccci_fs_int.polling_step_trace);

    rcv_size = QBM_DES_GET_DATALEN(ccci_fs_excep_rx_first_gpd);
    p_data = QBM_DES_GET_DATAPTR(ccci_fs_excep_rx_first_gpd);
    QBM_CACHE_INVALID(p_data, rcv_size);

    /*check if it needs next polling*/
    next_polling = CCCI_FS_PEER_REQ_SEND_AGAIN(p_data);

    io_request.next_request = NULL;
    io_request.first_gpd = ccci_fs_excep_rx_first_gpd;
    io_request.last_gpd = ccci_fs_excep_rx_first_gpd;
    io_request.num_gpd = 1;
        
    ccci_fs_ul_cb(CCCI_FS_ACK_CHANNEL,  &io_request);

    // reload rgpd
    CCCI_INIT_RESET_FLAG_CHECKSUM_ALLOWLEN((kal_uint32 *)ccci_fs_excep_rx_first_gpd, CCCI_FS_UL_BUF_SZ, DES_FLAG_BIT_HWO);
    CCCI_INIT_RESET_DATALEN_EXTLEN((kal_uint32 *)ccci_fs_excep_rx_first_gpd);
    CCCI_INIT_RESET_COMMON_DATA((kal_uint32 *)ccci_fs_excep_rx_first_gpd);
    QBM_DES_SET_ALLOW_LEN(ccci_fs_excep_rx_first_gpd, CCCI_FS_UL_BUF_SZ);
    QBM_CACHE_FLUSH(ccci_fs_excep_rx_first_gpd, sizeof(qbm_gpd));
    ccci_except_set_gpd(CCCI_FS_ACK_CHANNEL, ccci_fs_excep_rx_first_gpd, ccci_fs_excep_rx_first_gpd);
#endif
}


/*!
 * @function        [MOLY CCCI INIT] ccci_fs_ch_init
 * @brief           Initialize ccci channel
 *
 *                  After executing this function, users can use FS polling mode
 * @param void      
 *
 * @return          KAL_TRUE:  init PASS
 *                  KAL_FALSE: init NG
 */
kal_bool ccci_fs_ch_init(void)
{

    //[MOLY_INT] ian note should put in ccci_fs_task_init in MOLY
    kal_int32 ccci_ret;
    //ccci_ret = ccci_init_gpdior(CCCI_FS_CHANNEL, ccci_fs_dl_cb);
    /* Just release GPD don't callback for DL channel */
    ccci_ret = ccci_init_gpdior(CCCI_FS_CHANNEL, ccci_fs_dl_cb);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, CCCI_SUCCESS == ccci_ret,ccci_ret,0,0, 0, __LINE__);
    ccci_ret = ccci_init_gpdior(CCCI_FS_ACK_CHANNEL,ccci_fs_ul_cb);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, CCCI_SUCCESS == ccci_ret,ccci_ret,0,0, 0, __LINE__);

    return KAL_TRUE;
}


/*************************************************************************
* FUNCTION
*  kal_uint32 ccci_fs_get_debug_status
*
* DESCRIPTION
*  Get CCCI fs debug status and write to the write_ptr
*
*
* PARAMETERS
*  write_ptr : the write address of CCCI debug status
*  available_size : the available size of CCCI debug status
* RETURNS
*  kal_uint32 : the used size of CCCI fs debug status
*
*************************************************************************/
kal_uint32 ccci_fs_get_debug_status(kal_uint32 *write_ptr, kal_uint32 available_size)
{
    // If the available size is not enough, return size 0 
    if(available_size < sizeof(CCCI_FS_DEBUG_STATUS_T))
        return 0;
    
    ccci_fs_debug_status.FS_state           = g_ccci_fs_int.FS_state;
    ccci_fs_debug_status.FS_WriteIndex      = g_ccci_fs_int.FS_WriteIndex;
    ccci_fs_debug_status.FS_CCCIBufCount    = g_ccci_fs_int.FS_CCCIBufCount;
    ccci_fs_debug_status.hwo_rgpd_count     = g_ccci_fs_int.hwo_rgpd_count;
    
    kal_mem_cpy((void *)ccci_fs_debug_status.ccci_fs_buff_state, (void *)g_ccci_fs_int.ccci_fs_buff_state, sizeof(g_ccci_fs_int.ccci_fs_buff_state) );
    kal_mem_cpy((void *)ccci_fs_debug_status.ccci_fs_buff_offset, (void *)g_ccci_fs_int.ccci_fs_buff_offset, sizeof(g_ccci_fs_int.ccci_fs_buff_offset) );
    kal_mem_cpy((void *)ccci_fs_debug_status.tgpd_pool, (void *)g_ccci_fs_int.tgpd_pool, sizeof(g_ccci_fs_int.tgpd_pool) );

    kal_mem_cpy((void *)write_ptr, (void *)&ccci_fs_debug_status, sizeof(CCCI_FS_DEBUG_STATUS_T));
    return sizeof(CCCI_FS_DEBUG_STATUS_T);
}

#if defined (__CCCI_FS_IT__)
extern void cccifs_it_case();
#endif
/*!
 * @function        [MOLY CCCI INIT] ccci_fs_svc_init
 * @brief           Initialize ccci_fs_internal data structures
 *                  Execute in Drv_Init_Phase1 --> ccci_hal_init
 * @param void      
 *
 * @return          void
 *                  ASSERT if fail
 */
kal_bool ccci_fs_svc_init(void)
{
    kal_uint32 p_cache_aligned;  
    kal_int32 get_shm_ret = CCCI_FAIL;

    //4 <1> Initialize internal variables
    g_ccci_fs_int.FS_state = CCCI_FS_INIT;

    ccci_get_fs_shm_info((void **)&g_ccci_fs_int.FS_REQ_BUF, &g_ccci_fs_int.FS_REQ_BUF_SZ);

    /* ian ToDo in MOLY: after MOLY migration please turn on this flag*/
    /* ccci_sdio must reserve enough buffer space for ccci_fs */
    //ASSERT(FS_CCCI_MAX_BUF_SIZE*FS_CCCI_REQ_BUFFER_NUM <= g_ccci_fs_int.FS_REQ_BUF_SZ);
    
    g_ccci_fs_int.FS_CCCI_CSEvgrp = kal_create_event_group("FS_DRV");
    g_ccci_fs_int.FS_CCCIBufCount = 0;
    g_ccci_fs_int.FS_WriteIndex = 0;       
    g_ccci_fs_int.ccci_fs_emutex = kal_create_enh_mutex("cccifs_em");
    if(NULL == g_ccci_fs_int.ccci_fs_emutex){
        CCCI_FS_ASSERT(CCCI_FS_NORMAL_ASSERT, KAL_FALSE,0,0, 0, 0, __LINE__);
    }
    g_ccci_fs_int.ccci_fs_fake_emutex = 0;
    g_ccci_fs_int.hwo_rgpd_count = 0;

#ifdef __CCCI_FS_LT_4K_IO_ENABLE__
    {
        kal_uint32 idx;
        for(idx = FS_CCCI_REQ_BUFFER_NUM; idx!=0; idx--)
        {
            g_ccci_fs_int.ccci_fs_buff_offset[idx-1] = 0;
            g_ccci_fs_int.ccci_fs_buff_state[idx-1] = CCCI_FS_BUFF_IDLE;
            g_ccci_fs_int.ccci_fs_dl_seq[idx-1] = 0;
        }
    }
#endif

    /* initialize polling mode GPD */
    CCCI_FS_ASSERT(CCCI_FS_NORMAL_ASSERT, FS_CCCI_MAX_BUF_SIZE >= 2*CPU_CACHE_LINE_SIZE ,0,0, 0, 0, __LINE__);
    // Set polling gpd
    /*make p_gpd aligned to CPU_CACHE_LINE_SIZE_MASK*/
    p_cache_aligned = (kal_uint32)g_fs_polling_req_buf;
    if(p_cache_aligned&CPU_CACHE_LINE_SIZE_MASK) { 
        p_cache_aligned = ((kal_uint32)(g_fs_polling_req_buf)&~CPU_CACHE_LINE_SIZE_MASK);
        p_cache_aligned += CPU_CACHE_LINE_SIZE;
    }
    
    // The reason + QBM_HEAD_SIZE is for ROME E1, cldma needs to record this buff whether is cacheable or non-cacheable
    g_ccci_fs_int.p_polling_gpd = (qbm_gpd *)(p_cache_aligned + QBM_HEAD_SIZE);
    // Set excetion polling gpd1
    p_cache_aligned = (kal_uint32)g_fs_polling_req_buf_rx1;
    if(p_cache_aligned&CPU_CACHE_LINE_SIZE_MASK) { 
        p_cache_aligned = ((kal_uint32)(g_fs_polling_req_buf_rx1)&~CPU_CACHE_LINE_SIZE_MASK);
        p_cache_aligned += CPU_CACHE_LINE_SIZE;
    }
    
    // The reason + QBM_HEAD_SIZE is for ROME E1, cldma needs to record this buff whether is cacheable or non-cacheable
    g_ccci_fs_int.p_polling_gpd_rx1 = (qbm_gpd *)(p_cache_aligned + QBM_HEAD_SIZE);

    // Set excetion polling gpd1
    p_cache_aligned = (kal_uint32)g_fs_polling_req_buf_rx2;
    if(p_cache_aligned&CPU_CACHE_LINE_SIZE_MASK) { 
        p_cache_aligned = ((kal_uint32)(g_fs_polling_req_buf_rx2)&~CPU_CACHE_LINE_SIZE_MASK);
        p_cache_aligned += CPU_CACHE_LINE_SIZE;
    }
    
    // The reason + QBM_HEAD_SIZE is for ROME E1, cldma needs to record this buff whether is cacheable or non-cacheable
    g_ccci_fs_int.p_polling_gpd_rx2 = (qbm_gpd *)(p_cache_aligned + QBM_HEAD_SIZE);

    // ROME E1 need to convert non-cacheable address for solving cache coherence
#if defined(MT6595) && defined(__MTK_TARGET__)
    SW_SECVERSION ver = INT_SW_SecVersion();
    if(SW_SEC_0 == ver){
	    g_ccci_fs_int.FS_REQ_BUF    = (FS_StreamBuffer_T *)((kal_uint32)g_ccci_fs_int.FS_REQ_BUF & 0x0FFFFFFF); 
        g_ccci_fs_int.p_polling_gpd = (qbm_gpd *)((kal_uint32) g_ccci_fs_int.p_polling_gpd & 0x0FFFFFFF); 
        g_ccci_fs_int.p_polling_gpd_rx1 = (qbm_gpd *)((kal_uint32) g_ccci_fs_int.p_polling_gpd_rx1 & 0x0FFFFFFF);
        g_ccci_fs_int.p_polling_gpd_rx2 = (qbm_gpd *)((kal_uint32) g_ccci_fs_int.p_polling_gpd_rx2 & 0x0FFFFFFF);
    }
#endif
    
    //4 <2> Initialize CCCI channel
    ccci_fs_ch_init();

    //4 <3> Initialize ccci_fs tgpd pool
    ccci_fs_ior_init();

    g_ccci_fs_int.FS_state = CCCI_FS_POLLING;

    g_ccci_fs_int.polling_step_trace = (kal_uint32)CCCI_FS_TRACE_RPC_INIT;
    g_ccci_fs_int.wait_ap_time_polling= 0;
    g_ccci_fs_int.wait_ap_time_normal= 0;
    ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_TRACE, (void *)&g_ccci_fs_int.polling_step_trace);

    // register ccci debug get status cb funp
    ccci_debug_get_status_register(CCCI_DEBUG_GET_STATUS_MODULE_CCCIFS, ccci_fs_get_debug_status);    
    
    // Get ccci fs share memory
    get_shm_ret = ccci_excep_query_shm(CCCI_EXCEP_MEMORY_REGION_CCCIFS_DUMP, &ccci_fs_assert_dump_addr, &ccci_fs_assert_dump_size, &ccci_fs_assert_dump_type);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, get_shm_ret == CCCI_SUCCESS, ccci_fs_assert_dump_addr, ccci_fs_assert_dump_size, (kal_uint32) ccci_fs_assert_dump_type,0, __LINE__);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, (kal_uint32 *) ccci_fs_assert_dump_addr != NULL, ccci_fs_assert_dump_addr, ccci_fs_assert_dump_size, (kal_uint32) ccci_fs_assert_dump_type,0, __LINE__);

    return KAL_TRUE;
}

/*!
 * @function        [MOLY TASK MAIN] ccci_fs_rgpd_init
 * @brief           Initialize CCCI_FS_RGPD, must executre after TCT_Schedule
 *                  Execute in Task Main
 * @param void      
 *
 * @return          void
 *                  ASSERT while error
 */
void ccci_fs_rgpd_init(void){
    
    kal_uint32 curr_hwo_rgpd;
    kal_uint32 to_alloc, num_alloc;
    kal_int32  ccci_ret;
    ccci_io_request_t  reload_ior;

   //4 <3> 1st time reload TGPD CCCI_FS_INIT_HWO_GPD_NUM
    reload_ior.next_request = NULL;
    reload_ior.num_gpd = CCCI_FS_INIT_HWO_GPD_NUM; /* doesn't need to specified the ul num_gpd in ior*/
    to_alloc = CCCI_FS_INIT_HWO_GPD_NUM;
    
    num_alloc = qbmt_alloc_q_no_tail(CCCI_FS_UL_BUF_TYPE, to_alloc, (void **)&reload_ior.first_gpd, (void **)&reload_ior.last_gpd);
    /* ASSERT cannot allocate enough RGPD, CCCI_FS channel should pre-allocate enough RGPD*/
    if (num_alloc != to_alloc)
    {
        ccci_fs_trace(CCCI_FS_INFO, CCCI_FS_MOD_GPD, CCCIFS_TR_RGPD_RELOAD_1ST_ERR, to_alloc, num_alloc);
        CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, 0,num_alloc,to_alloc,0, 0, __LINE__);
    }   

    ccci_ret = ccci_write_gpd(CCCI_FS_ACK_CHANNEL, &reload_ior, NULL);
    CCCI_FS_ASSERT(CCCI_FS_EXT_ASSERT, CCCI_SUCCESS == ccci_ret,ccci_ret,0,0, 0, __LINE__);

    ccci_fs_enter_cs();
    g_ccci_fs_int.hwo_rgpd_count += num_alloc;
    curr_hwo_rgpd = g_ccci_fs_int.hwo_rgpd_count;
    ccci_fs_exit_cs();
    
    ccci_fs_trace(CCCI_FS_INFO, CCCI_FS_MOD_GPD, CCCIFS_TR_RGPD_RELOAD_1ST, num_alloc, curr_hwo_rgpd);

}

/*!
 * @function        ccci_fs_data_trace_dump
 * @brief             dump ccci fs trace data
 * @param void      
 *
 * @return          
 */
void ccci_fs_data_trace_dump(kal_uint32 seq, kal_uint32 opid, void* p_data, kal_uint32 bytes){
    kal_int32 i = 0;
    kal_uint32* p_d = (kal_uint32*)((int)p_data & (~0X3));// 4bytes alignment
    for (i=0; i*4 < bytes; i=i+4 ){
        ccci_fs_data_trace(CCCI_FS_DATA_DUMP_TRACE,seq,opid,i*4,p_d[i],p_d[i+1],p_d[i+2],p_d[i+3]);
    }
}

/*!
 * @function        CCCI_FS_ASSERT
 * @brief             ccci fs assert dump supports polling, normal and exception mode
 * @param 
 * type: defined in ccci_fs.h
 * expr,p1,p2,p3, param: please refer EXT_ASSERT and EXT_ASSERT_DUMP
 * errorline: this assert line for exception mode
 * @return          
 */
void ccci_fs_exception_assert(CCCI_FS_ASSERT_TYPE type, kal_bool expr, kal_uint32 e1, kal_uint32 e2, kal_uint32 e3, void *param, kal_uint32 errorline){
    static kal_uint32 ccci_fs_assert_first =0;
    // Record to share memory
    if(ccci_fs_assert_first ==0){ // Prevent nested assert
        ccci_fs_assert_first = 1;
        ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_ERROR_LINE, &errorline);
        ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_ERROR_PARAM1, &e1);
        ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_ERROR_PARAM2, &e2);
        ccci_excep_dbg_logging_InHS2(CCCI_EXCEP_DBG_HS_CCCI_FS_ERROR_PARAM3, &e3);
        if(param != NULL){
            kal_mem_cpy((void *)ccci_fs_assert_dump_addr, (void *)param, ccci_fs_assert_dump_size);
        }                
    }
}

/*!
 * @function        [MOLY TASK INIT] ccci_fs_task_init
 * @brief           Initialize function called by cccisrv_task_init
 *                  refer to cccidev_config.h
 *
 * @param channel   [IN] CCCI channel number
 * @param io_request[IN] io request callback
 *
 * @return          KAL_TRUE:  init PASS
 *                  KAL_FALSE: init NG
 */
kal_bool ccci_fs_task_init(void)
{
    ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_MISC, CCCIFS_TR_TASK_INIT, KAL_FALSE);
#if defined (__CCCI_FS_IT__)
        /* polling mode test */
        cccifs_it_case();
#endif

    return KAL_TRUE;
}

/*!
 * @function        [MOLY TASK MAIN INIT] ccci_fs_task_main_init
 * @brief           Initialize function called by cccisrv_task_main
 *
 * @param void 
 *
 * @return          KAL_TRUE:  init PASS
 *                  KAL_FALSE: init NG
 */
kal_bool ccci_fs_task_main_init(void)
{
    /* 
     *  The actual time for active CCCI_FS_NORMAL mode is before TCT_Schedule()
     *  The earilest timing CCCI_FS can sense is @ ccci_fs_get_port->ccci_fs_enter_cs->kal_query_systemInit
     *  There's some timing delay by change status, but since FS_state is a debug flag w/o reference,
     *  this timing delay won't affect the real SW flow.
     */

    g_ccci_fs_int.FS_state = CCCI_FS_NORMAL;
#if !defined(__CCCI_LB_IT__)
    //ccci_fs_svc_init(); // lte_ccci_hal_init
    ccci_fs_rgpd_init(); //task_main
#endif
    return KAL_TRUE;
}

void ccci_fs_test_init(void)
{
     kal_uint32 i;

    g_ccci_fs_ttc = 0;
	for(i=0;i<10;i++){
		g_ccci_fs_ttt[i] =0;
	}
	for(i=1;i<2048;i++){
	   g_ccci_fs_polling[i] = 0;
	}
	return; 
}
/*!
 * @function        ccci_fs_main
 * @brief           For cccidev_task to pass ilm if there's any
 *
 * @param ilm       pointer to ilm_struct
 *
 * @return          void
 */  
void ccci_fs_main(ilm_struct *ilm)
{
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
#endif
    ccci_fs_trace(CCCI_FS_ERR, CCCI_FS_MOD_MISC, CCCIFS_TR_TASK_INIT, 1);
}
