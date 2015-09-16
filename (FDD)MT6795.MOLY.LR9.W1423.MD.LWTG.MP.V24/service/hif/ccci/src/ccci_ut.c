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
 *   ccci_ut.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Implements the CCCI UT functions
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
 * [CCCI] CCCI new debug mechanism
 *
 * removed!
 * removed!
 * [CCCI] Fix Modis build error
 *
 * removed!
 * removed!
 * [CCCI] Add new CCCI debug mechanism
 *
 * removed!
 * removed!
 * [CCCI] Add CCCI UT for SS debug info
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
 * [CCCI] Add & Maintain UT code
 *
 * removed!
 * removed!
 * [CCCI RPC] Add CCCI RPC general query function.
 *
 * removed!
 * removed!
 * 	.
 *
 * 04 16 2013 ap.wang
 * removed!
 *
 * 04 16 2013 ap.wang
 * removed!
 * [CCCI_IT] Modify for ccci_dump_data function coverage
 *
 * removed!
 * removed!
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
 * [CCCI] modify ccci_ut compile option
 *
 * removed!
 * removed!
 * [CCCI] CCCI_IMS 1st verison loopback support
 *
 * 01 11 2013 ap.wang
 * removed!
 * [CCCI UT] Modify for ccci channel naming change
 ****************************************************************************/
#ifdef ATEST_SYS_CCCI
#include "ccci_if.h"
#include "ccci_common.h"
#include "ccci_debug.h"
#include "ccci_ut.h"
#include "cccidev_qbm.h"
#include "sys_test.h"
#include "ccci_dev_if.h"
#include "ccci_except.h"
/*------------------------------------------------------------------------------
 * Private Helper macros.
 *----------------------------------------------------------------------------*/

#define CCCI_UT_ERR_PREFIX __FILE__ ":" __LINE__ ": "

#if defined(__MTK_TARGET__)
#define _ccci_ut_printf(...) ccci_dhl_print(CCCI_ERR, CCCI_MOD_UT, __VA_ARGS__)
#else
#define _ccci_ut_printf printf
#endif

#define ccci_ut_printf(_fmts, ...) \
        _ccci_ut_printf("%s(): " _fmts, __FUNCTION__, ##__VA_ARGS__)

#define ccci_ut_format_err_str(_fmts, ...) \
        kal_sprintf(p_ret_err_str, "%s:%d: " _fmts, __FILE__, __LINE__, ##__VA_ARGS__); \
        _ccci_ut_printf("[FAILED] " _fmts, ##__VA_ARGS__)

typedef struct
{
    kal_uint32 ch_tx;
    kal_uint32 ch_rx;
    kal_uint32 mb_id;
    kal_int32  total_gpd_cnt;
    kal_int32  temp_gpd_cnt;
    kal_uint32 serial_no;
} CCCI_UT_CH_T;
#define CCCI_UT_MAGICW_TX       0x5a5a5a5a
#define CCCI_UT_MAGICW1_TX      0xaaaa5555
#define CCCI_TX_COUNT           1024*6
#define CCCI_RX_COUNT           1024*6
/*CCCI_UT_NIC_RGPD_RELOAD_CNT is 10 for the real application, set to 100 for faster ut execution*/
#define CCCI_UT_NIC_RGPD_RELOAD_CNT   10 //QBM_NUM_HIF_UL_TYPE_IN_HIF
//#define CCCI_TX_TIME            CCCI_TX_COUNT
//#define CCCI_RX_TIME            CCCI_RX_COUNT
#define CCCI_UT_TX_WAIT_LIMIT   1000
#define CCCI_UT_RX_WAIT_LIMIT   1000
#define CCCI_TXRX_SENT_CNT      2
static kal_uint32  LB_COUNTER[CCCI_UT_PEER_ID_MAX][CCCI_UT_MAX_CHANNEL];

/*------------------------------------------------------------------------------
 * Define CCCI UT channel configuration
 *----------------------------------------------------------------------------*/
static ccci_ch_handle ccci_ut_ch_info[CCCI_UT_PEER_ID_MAX][CCCI_UT_MAX_CHANNEL] = {
	{ // TO AP channel config
	    /* GPD HIF */
	    {UT_HIF_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,              NULL, CCCI_TYPE_UT_GPD }, // [00] CCCI_UT_BUFF_TX0     
	    {UT_HIF_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,     NULL, CCCI_TYPE_UT_GPD }, // [01] CCCI_UT_BUFF_RX0 
	    {UT_HIF_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,              NULL, CCCI_TYPE_UT_GPD }, // [02] CCCI_UT_BUFF_TX1     
	    {UT_HIF_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,     NULL, CCCI_TYPE_UT_GPD }, // [03] CCCI_UT_BUFF_RX1 
	    {UT_HIF_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,              NULL, CCCI_TYPE_UT_GPD }, // [04] CCCI_UT_GPD_NOCB_TX0     
	    {UT_HIF_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_net_cb, NULL, CCCI_TYPE_UT_GPD }, // [05] CCCI_UT_GPD_RX0 
	    {UT_HIF_TXQ_Q2, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,     NULL, CCCI_TYPE_UT_GPD }, // [06] CCCI_UT_GPD_TX1     
	    {UT_HIF_RXQ_Q2, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,     NULL, CCCI_TYPE_UT_GPD }, // [07] CCCI_UT_GPD_RX1 
	    {UT_HIF_TXQ_Q2, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,     NULL, CCCI_TYPE_UT_GPD }, // [08] CCCI_UT_GPD_TX2    
	    {UT_HIF_RXQ_Q2, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,     NULL, CCCI_TYPE_UT_GPD }, // [09] CCCI_UT_GPD_RX2
	    /* BUFF HIF */
	    {UT_HIF_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,              NULL, CCCI_TYPE_UT_BUFF },// [10] CCCI_UT_BUFF_TX2     
	    {UT_HIF_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, NULL,    ccci_ulbuff_cb, CCCI_TYPE_UT_BUFF },// [11] CCCI_UT_BUFF_RX2 
	},
	{ // TO MD2 channel config
		/* GPD HIF */
	    {UT_HIF_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,              NULL, CCCI_TYPE_UT_GPD }, // [00] CCCI_UT_BUFF_TX0     
	    {UT_HIF_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,     NULL, CCCI_TYPE_UT_GPD }, // [01] CCCI_UT_BUFF_RX0 
	    {UT_HIF_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,              NULL, CCCI_TYPE_UT_GPD }, // [02] CCCI_UT_BUFF_TX1     
	    {UT_HIF_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, ccci_ulior_cb,     NULL, CCCI_TYPE_UT_GPD }, // [03] CCCI_UT_BUFF_RX1 
	    {UT_HIF_TXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, NULL,              NULL, CCCI_TYPE_UT_GPD }, // [04] CCCI_UT_GPD_NOCB_TX0     
	    {UT_HIF_RXQ_Q1, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_net_cb, NULL, CCCI_TYPE_UT_GPD }, // [05] CCCI_UT_GPD_RX0 
	    {UT_HIF_TXQ_Q2, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,     NULL, CCCI_TYPE_UT_GPD }, // [06] CCCI_UT_GPD_TX1     
	    {UT_HIF_RXQ_Q2, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,     NULL, CCCI_TYPE_UT_GPD }, // [07] CCCI_UT_GPD_RX1 
	    {UT_HIF_TXQ_Q2, CCCI_CH_USER_GPD,    CCCI_TYPE_TX, ccci_dlior_cb,     NULL, CCCI_TYPE_UT_GPD }, // [08] CCCI_UT_GPD_TX2    
	    {UT_HIF_RXQ_Q2, CCCI_CH_USER_GPD,    CCCI_TYPE_RX, ccci_ulior_cb,     NULL, CCCI_TYPE_UT_GPD }, // [09] CCCI_UT_GPD_RX2
	    /* BUFF HIF */
	    {UT_HIF_TXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_TX, NULL,              NULL, CCCI_TYPE_UT_BUFF },// [10] CCCI_UT_BUFF_TX2     
	    {UT_HIF_RXQ_Q0, CCCI_CH_USER_DIRECT, CCCI_TYPE_RX, NULL,    ccci_ulbuff_cb, CCCI_TYPE_UT_BUFF },// [11] CCCI_UT_BUFF_RX2 


	}
	
};

/*------------------------------------------------------------------------------
 * Define CCCI UT HIF ccci_ut_gpd_hif_apis/ccci_ut_buff_hif_apis
 *----------------------------------------------------------------------------*/
/* ccci ut GPD hif */
static ccci_ut_hif_inst ccci_ut_gpd_hif_inst;
kal_bool ccci_ut_gpdhif_submit_ior(kal_uint8 queue_type , kal_uint8 queue_no, void* ior)
{
    ccci_io_request_t* io_request = ior;
    ccci_io_request_t ccci_DLCB_ior;
    kal_uint32 num_alloc, to_alloc;
    CCCI_BUFF_T *ccci_h;
    kal_uint32 serial_no, mb_id, tx_ch;

    if( CCCI_TYPE_RX == queue_type ){
        /*Rx channel free IOR*/   
        qbmt_dest_q(io_request->first_gpd, io_request->last_gpd);

    }else{
        /* Tx Channel */
        if(KAL_TRUE == ccci_ut_gpd_hif_inst.lb_mode &&
           NULL != ccci_ut_gpd_hif_inst.ccci_gpd_rx_cb_funp[queue_no]){
            to_alloc = CCCIDEV_GET_GPD_LIST_SIZE(io_request->first_gpd, io_request->last_gpd);
            num_alloc = qbmt_alloc_q_no_tail(
                        CCCI_DL_BUF_TYPE,                    /* type */
                        to_alloc,                            /* buff_num */
                        (void **)(&ccci_DLCB_ior.first_gpd), /* pp_head */
                        (void **)(&ccci_DLCB_ior.last_gpd)); /* pp_tail */
            if(to_alloc == num_alloc){
                ccci_h    = CCCIDEV_GET_QBM_DATAPTR(io_request->first_gpd);
                serial_no = CCCI_GET_RESERVED(ccci_h);
                mb_id     = CCCI_MAILBOX_ID(ccci_h);
                tx_ch     = CCCI_GET_CH_NO(ccci_h);
                ccci_DLCB_ior.next_request = NULL;
#ifdef __SDIOC_PULL_Q_ENH_DL__
                ccci_DLCB_ior.num_gpd = num_alloc;
#endif
                ccci_ut_format_mb_gpd(&ccci_DLCB_ior,num_alloc,serial_no,mb_id,ccci_ut_get_lb_rx_ch(tx_ch));
                ccci_ut_gpd_hif_inst.ccci_gpd_rx_cb_funp[queue_no](queue_no, &ccci_DLCB_ior);
                
            }else{
                ccci_ut_printf("%s::%d GPD leackage \r\n", __FUNCTION__, __LINE__);
            }
        }
        /* Tx Callback */
        if(NULL != ccci_ut_gpd_hif_inst.ccci_gpd_tx_cb_funp[queue_no]){
           ccci_ut_gpd_hif_inst.ccci_gpd_tx_cb_funp[queue_no](queue_no, ior);
        }else{
           qbmt_dest_q(io_request->first_gpd, io_request->last_gpd);
        }
    }
    return KAL_TRUE;
}
kal_bool ccci_ut_gpdhif_q_attach(kal_uint8 queue_type, kal_uint8 queue_no, CCCI_CHANNEL_T channel, HIF_CCCI_GPD_CALLBACK funp)
{
    if( CCCI_TYPE_RX == queue_type ){
        ccci_ut_gpd_hif_inst.ccci_gpd_rx_cb_funp[queue_no] = funp;
    }else{
        ccci_ut_gpd_hif_inst.ccci_gpd_tx_cb_funp[queue_no] = funp;
    }
    return KAL_TRUE;
}
kal_bool ccci_ut_gpdhif_q_detach(kal_uint8 queue_type, kal_uint8 queue_no, CCCI_CHANNEL_T channel)
{
    return KAL_TRUE;
}
kal_bool ccci_ut_gpdhif_polling(kal_uint8 queue_no, qbm_gpd *pgpd, kal_bool istx){
    return KAL_TRUE;
}
kal_bool ccci_ut_gpdhif_ex_init(kal_uint32 dhldl_q, kal_uint32 expt_q){
    return KAL_TRUE;
}  
kal_bool ccci_ut_gpdhif_ex_clear_q(kal_uint8 queue_type, kal_uint8 queue_no){
    return KAL_TRUE;
}
kal_bool ccci_ut_gpdhif_ex_set_gpd(kal_uint8 queue_type, kal_uint8 queue_no, void *p_first_gpd, void *p_last_gpd){
    return KAL_TRUE;
}
kal_int32 ccci_ut_gpdhif_ex_poll_gpd(kal_uint8 queue_type, kal_uint8 queue_no, void **pp_first_gpd, void **pp_last_gpd){
    return 0;
}
kal_bool ccci_ut_gpdhif_ex_hif_isr(void){
    return KAL_TRUE;
}
kal_bool ccci_ut_gpdhif_ex_link_st(kal_uint8 queue_type, kal_uint8 queue_no){
    return KAL_TRUE;
}

static ccci_hif_expt_apis ccci_ut_gpd_hif_expt_apis = {
    ccci_ut_gpdhif_ex_init, 
    ccci_ut_gpdhif_ex_clear_q, 
    ccci_ut_gpdhif_ex_set_gpd, 
    ccci_ut_gpdhif_ex_poll_gpd, 
    ccci_ut_gpdhif_ex_hif_isr, 
    ccci_ut_gpdhif_ex_link_st
};

static ccci_hw_apis ccci_ut_gpd_hif_apis = {
    ccci_ut_gpdhif_submit_ior, 
    ccci_ut_gpdhif_q_attach, 
    NULL,
    ccci_ut_gpdhif_q_detach, 
    NULL, 
    ccci_ut_gpdhif_polling, 
    CCCI_CH_HIFIO_GPD,
    /*===Exception Mode APIs===*/
    &ccci_ut_gpd_hif_expt_apis   
};
static ccci_ut_hif_inst ccci_ut_buff_hif_inst;
/* ccci ut BUFF hif */
kal_bool ccci_ut_buffhif_submit(kal_uint8 queue_type , kal_uint8 queue_no, void* buff)
{
    CCCI_BUFF_T *ccci_h = (CCCI_BUFF_T *) buff;
	kal_uint8 peer_id = GET_PEER_ID(ccci_h->channel);
	kal_uint8 peer_channel= GET_PEER_CHANNEL(ccci_h->channel);
    LB_COUNTER[peer_id][peer_channel]++;
    return KAL_TRUE;
}
kal_bool ccci_ut_buffhif_q_attach(kal_uint8 queue_type, kal_uint8 queue_no, CCCI_CHANNEL_T channel, HIF_CCCI_BUFF_CALLBACK funp)
{
    if( CCCI_TYPE_RX == queue_type ){
        ccci_ut_buff_hif_inst.ccci_buff_rx_cb_funp[queue_no] = funp;
    }else{
        ccci_ut_buff_hif_inst.ccci_buff_tx_cb_funp[queue_no] = funp;
    }
    return KAL_TRUE;
}
kal_bool ccci_ut_buffhif_q_detach(kal_uint8 queue_type, kal_uint8 queue_no, CCCI_CHANNEL_T channel)
{
    return KAL_TRUE;
}
static ccci_hif_expt_apis ccci_ut_buff_hif_expt_apis = {NULL, NULL, NULL, NULL, NULL, NULL};
static ccci_hw_apis ccci_ut_buff_hif_apis = {
    ccci_ut_buffhif_submit, 
    NULL, 
    ccci_ut_buffhif_q_attach,
    ccci_ut_buffhif_q_detach, 
    NULL, 
    NULL, 
    CCCI_CH_HIFIO_BUFF,
    &ccci_ut_buff_hif_expt_apis
};
ccci_hw_apis ccci_ut_get_hif_apis(kal_uint32 hif_type){
    if(hif_type == CCCI_TYPE_UT_GPD){
        return ccci_ut_gpd_hif_apis;
    }else if(hif_type == CCCI_TYPE_UT_BUFF){
        return ccci_ut_buff_hif_apis;
    }else{
        ASSERT(KAL_FALSE);
        return ccci_ut_buff_hif_apis;
    }
}
void ccci_ut_hif_lb_mode(kal_bool lb_mode)
{
    if(KAL_TRUE == lb_mode){
        ccci_ut_gpd_hif_inst.lb_mode  = KAL_TRUE;
        ccci_ut_buff_hif_inst.lb_mode = KAL_TRUE; 
    }else{
        ccci_ut_gpd_hif_inst.lb_mode  = KAL_FALSE;
        ccci_ut_buff_hif_inst.lb_mode = KAL_FALSE; 
    }
}

//#define MIN(_a, _b) (((_a) <= (_b)) ? (_a) : (_b))
/*------------------------------------------------------------------------------
 * Define CCCI UT cb function
 *----------------------------------------------------------------------------*/
void ccci_ut_test_cb(CCCI_BUFF_T *buff){
    return;
}
void ccci_ut_testior_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* ior){
    return;
}
void ccci_ut_tx_buff_dummy_cb(CCCI_BUFF_T *buff){
    ASSERT(0);
    return;
}
void ccci_ut_tx_gpd_dummy_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* ior){
    ASSERT(0);
    return;
}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
kal_bool hifq_gpd_attach_fail(kal_uint8 queue_type, kal_uint8 queue_no, CCCI_CHANNEL_T channel, HIF_CCCI_GPD_CALLBACK funp){
    return KAL_FALSE;
}
kal_bool hifq_detach_fail(kal_uint8 queue_type, kal_uint8 queue_no, CCCI_CHANNEL_T channel){
    return KAL_FALSE;
}
void ccci_ut_gpd_cb_magic(CCCI_CHANNEL_T channel, ccci_io_request_t* ior)
{
    /*find magic word CCCI_UT_MAGICW_TX*/
    CCCI_BUFF_T         *buff;
    qbm_gpd             *p_gpd_h, *p_gpd_t, *p_gpd_cur;
    qbm_gpd             *p_bd;    
    ccci_io_request_t   *p_cur_ior = ior;
	kal_uint8 			peer_id;
	kal_uint32 			peer_channel;
    if(NULL==p_cur_ior){
        return;
    }
    p_gpd_h =  p_cur_ior->first_gpd;
    p_gpd_t =  p_cur_ior->last_gpd;
    if(NULL==p_gpd_h){
        return;
    }
    if (p_gpd_t){
        QBM_DES_SET_NEXT(p_gpd_t, NULL);
    }

    while(p_cur_ior){
        p_gpd_cur = p_gpd_h;
        while(p_gpd_cur){
            p_bd = QBM_DES_GET_DATAPTR(p_gpd_cur);
            buff = QBM_DES_GET_DATAPTR(p_bd); 

            if((CCCI_IS_MAILBOX(buff)) && \
               (CCCI_MAILBOX_ID(buff)== CCCI_UT_MAGICW_TX)){
				peer_id = GET_PEER_ID(channel);	
				peer_channel= GET_PEER_CHANNEL(channel);
                LB_COUNTER[peer_id][peer_channel]++;
            }else{
                ccci_ut_printf("%s::%d [CCCI_ERR][CCCI_UT] %d MAGIC ID error **** %x#%x#%x#%x \r\n" \
                    , __FUNCTION__, __LINE__, \
                    buff->data[0],buff->data[1],buff->channel, buff->reserved);
            }

            p_gpd_cur = QBM_DES_GET_NEXT(p_gpd_cur);
        }
        qbmt_dest_q(p_cur_ior->first_gpd, p_cur_ior->last_gpd);
        p_cur_ior = p_cur_ior->next_request;
    }
    
    return;
}

void ccci_ut_buff_cb(CCCI_BUFF_T *buff){
	kal_uint8 peer_id = GET_PEER_ID(buff->channel);	
	kal_uint32 peer_channel= GET_PEER_CHANNEL(buff->channel);
    LB_COUNTER[peer_id][peer_channel]++;
    return;
}

void ccci_ut_buff_cb_magic(CCCI_BUFF_T *buff)
{
	kal_uint8 peer_id = GET_PEER_ID(buff->channel);	
	kal_uint32 peer_channel= GET_PEER_CHANNEL(buff->channel);
    if((CCCI_IS_MAILBOX(buff)) && \
       (CCCI_MAILBOX_ID(buff)== CCCI_UT_MAGICW_TX)){
            LB_COUNTER[peer_id][peer_channel]++;
    }else{
        ccci_ut_printf("%s::%d [CCCI_ERR][CCCI_UT] %d MAGIC ID error **** %x#%x#%x#%x \r\n" \
            , __FUNCTION__, __LINE__, \
            buff->data[0],buff->data[1],buff->channel, buff->reserved);
    }
   
    return;
}
void ccci_ut_gpd_cb_magic1(CCCI_CHANNEL_T channel, ccci_io_request_t* ior)
{
    /*find magic word CCCI_UT_MAGICW_TX*/
    CCCI_BUFF_T         *buff;
    qbm_gpd             *p_gpd_h, *p_gpd_t, *p_gpd_cur;
    qbm_gpd             *p_bd;    
    ccci_io_request_t   *p_cur_ior = ior;
	kal_uint8 			peer_id;
	kal_uint32 			peer_channel;
    if(NULL==p_cur_ior){
        return;
    }

    p_gpd_h =  p_cur_ior->first_gpd;
    p_gpd_t =  p_cur_ior->last_gpd;

    if(NULL==p_gpd_h){
        return;
    }
    if (p_gpd_t){
        QBM_DES_SET_NEXT(p_gpd_t, NULL);
    }

    while(p_cur_ior){
        p_gpd_cur = p_gpd_h;
        while(p_gpd_cur){
            p_bd = QBM_DES_GET_DATAPTR(p_gpd_cur);
            buff = QBM_DES_GET_DATAPTR(p_bd); 

            if((CCCI_IS_MAILBOX(buff)) && \
               (CCCI_MAILBOX_ID(buff)== CCCI_UT_MAGICW1_TX)){
				peer_id = GET_PEER_ID(buff->channel);	
				peer_channel= GET_PEER_CHANNEL(buff->channel);
                LB_COUNTER[peer_id][peer_channel]++;
            }else{
                ccci_ut_printf("%s::%d [CCCI_ERR][CCCI_UT] %d MAGIC ID error **** %x#%x#%x#%x \r\n" \
                        , __FUNCTION__, __LINE__, \
                        buff->data[0],buff->data[1],buff->channel, buff->reserved);
            }

            p_gpd_cur = QBM_DES_GET_NEXT(p_gpd_cur);
        }
        qbmt_dest_q(p_cur_ior->first_gpd, p_cur_ior->last_gpd);
        p_cur_ior = p_cur_ior->next_request;
    }
    
    return;
}
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
#endif
static __inline void CCCI_UT_PUSH_QBM_DATAHEAD(void* gpd, kal_uint32 offset)
{
    void* bd = NULL;
    kal_uint8* data_ptr = NULL;
    kal_uint32 data_len = 0;

    ASSERT(QBM_DES_GET_BDP(gpd) != 0);

    /* set bd data ptr */
    bd = QBM_DES_GET_DATAPTR(gpd);
    data_ptr =  (kal_uint8*)QBM_DES_GET_DATAPTR(bd);
    QBM_DES_SET_DATAPTR(bd, data_ptr-offset);
    /* set bd data len */
    data_len = QBM_DES_GET_DATALEN(bd);
    QBM_DES_SET_DATALEN(bd, data_len+offset);
    /* set bd checksum */
    qbm_cal_set_checksum(bd);

    /* set gpd data len */
    data_len = QBM_DES_GET_DATALEN(gpd);
    QBM_DES_SET_DATALEN(gpd, data_len+offset);
    /* set gpd checksum */
    //qbm_cal_set_checksum(gpd);
}

void ccci_ut_format_mb_gpd(ccci_io_request_t* ior, kal_uint32 gpd_num, kal_uint32 start_serial, kal_uint32 mb_id, CCCI_CHANNEL_T ch){
    qbm_gpd             *p_gpd_h, *p_gpd_t, *p_gpd_cur;
    CCCI_BUFF_T         *buff;
    kal_uint32          gpd_count= 0;
    ccci_io_request_t   *p_cur_ior = ior;
    kal_uint32          sno = start_serial;
    kal_uint32          ccci_h_size = sizeof(CCCI_BUFF_T);

    ASSERT(NULL != ior);
    
    p_gpd_h =  p_cur_ior->first_gpd;
    p_gpd_t =  p_cur_ior->last_gpd;

    if(NULL==p_gpd_h){
        return;
    }
    if (p_gpd_t){
        QBM_DES_SET_NEXT(p_gpd_t, NULL);
    }

    while(p_cur_ior){
        p_gpd_cur = p_gpd_h;
        while(p_gpd_cur){
            /*move data buffer pointer forward for ccci header, increase the gpd, bd length*/
            CCCI_UT_PUSH_QBM_DATAHEAD(p_gpd_cur, ccci_h_size);
            buff = (CCCI_BUFF_T *)CCCI_GET_QBM_DATAPTR(p_gpd_cur);
            CCCI_INIT_MAILBOX(buff,mb_id);
            CCCI_SET_CH_NO(buff, ch);
            CCCI_SET_RESERVED(buff, sno++);

            QBM_CACHE_FLUSH(buff, sizeof(CCCI_BUFF_T));
            p_gpd_cur = QBM_DES_GET_NEXT(p_gpd_cur);
            gpd_count++;
        }
        p_cur_ior = p_cur_ior->next_request;
    }
    ASSERT(gpd_count == gpd_num);
    return;
}
kal_uint32 ccci_ut_get_lb_rx_ch(kal_uint32 tx_ch_id)
{
    return (tx_ch_id + 1);
}
void ccci_ut_reset_counter(void){
    kal_uint32 i;
	kal_uint8 peer_id;
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){	
	    for(i = 0; i< CCCI_UT_MAX_CHANNEL; i++){
	        LB_COUNTER[peer_id][i] = 0;
	    }
	}
}
/*------------------------------------------------------------------------------
 * Define CCCI UT test cases
 *----------------------------------------------------------------------------*/
 kal_bool ccci_buff_user_gpd_hif_example(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    CCCI_RETURNVAL_T ret;
    kal_uint32 test_step = 0xF0000000;
    kal_uint32 test_tx0=CCCI_UT_BUFF_TX0; 
    kal_uint32 test_rx0=CCCI_UT_BUFF_RX0;
	static kal_uint32 test_stream_write_start_addr[16 + 0xFF]; // ccci_header size + buffer size
	kal_uint8			peer_id;
	
    //4 1. buffer mode user init 
    test_step ++; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
   	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    ret = ccci_init(GET_VIRTUAL_CHANNEL(peer_id,test_tx0), ccci_ut_test_cb);  
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_init error !!\r\n");
	        goto fail_exit;
	    }
	    
	    ret = ccci_init(GET_VIRTUAL_CHANNEL(peer_id,test_rx0), ccci_ut_test_cb);  
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_init error !!\r\n");
	        goto fail_exit;
	    }
    }
    //4 2. buffer mode user Tx
    test_step ++; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    ccci_mailbox_write(GET_VIRTUAL_CHANNEL(peer_id,test_tx0), 32);
	    ccci_mailbox_write_with_reserved(GET_VIRTUAL_CHANNEL(peer_id,test_tx0), 32, 0xff);

	    ccci_stream_write(GET_VIRTUAL_CHANNEL(peer_id,test_tx0), (kal_uint32)&test_stream_write_start_addr, 0xFF);
	    ccci_stream_write_with_reserved(GET_VIRTUAL_CHANNEL(peer_id,test_tx0), (kal_uint32)&test_stream_write_start_addr, 0xFF,32);
    }
    //4 3. buffer mode user Rx
    test_step ++; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
    //ctrl_ch_h->ccci_uldl_iorcb_funp

    //4 4. buffer mode user deinit 
    test_step ++; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    ret = ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,test_tx0));
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_deinit error !!\r\n");
	        goto fail_exit;
	    }
	    
	    ret = ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,test_rx0));  
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_deinit error !!\r\n");
	        goto fail_exit;
	    }
    }
    test_step += 1; ccci_ut_printf("[PASS] %s::%d test PASS!!\r\n", __FUNCTION__, __LINE__);    
    return KAL_TRUE;

fail_exit:	
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,test_tx0));
	    ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,test_rx0));
	}
    return KAL_FALSE;
}

kal_bool ccci_ut_configure(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    kal_uint32 test_step = 0x00000000;
    kal_uint8  ch,peer_id;
    ccci_ch_handle *ctrl_ch_h;
    CCCI_CHANNEL_T      curr_ch = 0;
    kal_uint32          ch_idx;
    CCCI_RETURNVAL_T    ret;

    //4 0. configure the ut hif
    ccci_ut_gpd_hif_inst.lb_mode = KAL_FALSE;
    ccci_ut_buff_hif_inst.lb_mode = KAL_FALSE;

    //4 1. reset all ccci_ch_info hif hw type as CCCI_TYPE_DUMMY
    test_step ++; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
    for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
		for(ch=0; ch < CCCI_UT_MAX_CHANNEL ; ch++){
	        ctrl_ch_h = ccci_get_ch_info(GET_VIRTUAL_CHANNEL(peer_id,ch));
	        ctrl_ch_h->hw_type_predifined = CCCI_TYPE_DUMMY;
	    }
	}
    //4 2. set ccci_ch_info
    test_step ++; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
    for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	for(ch=0; ch < CCCI_UT_MAX_CHANNEL ; ch++){
	    ctrl_ch_h = ccci_get_ch_info(GET_VIRTUAL_CHANNEL(peer_id,ch));
	    ctrl_ch_h->hwq_id_predifined     = ccci_ut_ch_info[peer_id][ch].hwq_id_predifined;
	    ctrl_ch_h->user_mode_predifined  = ccci_ut_ch_info[peer_id][ch].user_mode_predifined;
	    ctrl_ch_h->ch_op_type_predifined = ccci_ut_ch_info[peer_id][ch].ch_op_type_predifined;
	    ctrl_ch_h->ccci_uldl_iorcb_funp  = ccci_ut_ch_info[peer_id][ch].ccci_uldl_iorcb_funp;
	    ctrl_ch_h->ccci_uldl_buffcb_funp = ccci_ut_ch_info[peer_id][ch].ccci_uldl_buffcb_funp;
	    ctrl_ch_h->hw_type_predifined    = ccci_ut_ch_info[peer_id][ch].hw_type_predifined;
	}
    }

    // deinit all channel for testing
    for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	for (ch_idx=(CCCI_MAX_CHANNEL); ch_idx != 0 ; ch_idx --){
	    curr_ch = ch_idx-1;
		    curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	    ret = ccci_deinit(curr_ch);
	}
    }

    ccci_ut_printf("[PASS] %s::%d test PASS!!\r\n", __FUNCTION__, __LINE__);    
    return KAL_TRUE;
}

void ccci_ut_expt_configure(void){
    ccci_ch_handle *ctrl_ch_h;
    
    ctrl_ch_h = ccci_get_ch_info(CCCI_MD_LOG_RX);
    ctrl_ch_h->hw_type_predifined = CCCI_TYPE_UT_GPD;
    ctrl_ch_h = ccci_get_ch_info(CCCI_MD_LOG_TX);
    ctrl_ch_h->hw_type_predifined = CCCI_TYPE_UT_GPD;

    ctrl_ch_h = ccci_get_ch_info(CCCI_FS_CHANNEL);
    ctrl_ch_h->hw_type_predifined = CCCI_TYPE_UT_GPD;
    ctrl_ch_h = ccci_get_ch_info(CCCI_FS_ACK_CHANNEL);
    ctrl_ch_h->hw_type_predifined = CCCI_TYPE_UT_GPD;


    ctrl_ch_h = ccci_get_ch_info(CCCI_TST_CHANNEL);
    ctrl_ch_h->hw_type_predifined = CCCI_TYPE_UT_GPD;
    ctrl_ch_h = ccci_get_ch_info(CCCI_TR_CHANNEL);
    ctrl_ch_h->hw_type_predifined = CCCI_TYPE_UT_GPD;
}
/*
ccci_ut_init checks the CCCI initialization flow
Step 
1. ccci_init/ccci_init_gpdior with CCCI_MAX_CHANNEL channel number: expect to return CCCI_INVALID_PARAM
2. ccci_init/ccci_init_gpdior with funp=NULL: expect to return CCCI_INVALID_PARAM
3. perform ccci_init (for legacy) on GPD user channel: expect to return CCCI_INVALID_PARAM
4. ccci_init_gpdior with non GPD user channel: expect to return CCCI_INVALID_PARAM
5. ccci_init/ccci_init_gpdior with the same channel number twice: expect to return CCCI_IN_USE
6. ccci_deinit an non-registered ccci_channel should return CCCI_SUCCESS
7. ccci_init/ccci_init_gpd with all ccci channel defined in CCCI_CHANNEL_T should  return CCCI_SUCCESS
8. ccci_deinit all registered ccci_channel registered in 8 should return CCCI_SUCCESS
*/
kal_bool ccci_ut_init(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz)
{
    CCCI_RETURNVAL_T    ret;
    CCCI_CHANNEL_T      curr_ch = 0;
    kal_uint32          ch_idx;
    ccci_ch_handle*     pccci_ch_info; //ccci_ch_info
    ccci_hw_apis        *phw_handle_api;
    kal_uint32          test_step = 0x10000000;
    CCCI_HIF_HW_TYPE_T  backup_hw_type;
	kal_uint8			peer_id;
	kal_uint32			peer_channel;

    //4 1. ccci_init/ccci_init_gpdior with CCCI_MAX_CHANNEL channel number: expect to return CCCI_INVALID_PARAM
    test_step ++; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);    
    
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
		curr_ch = CCCI_MAX_CHANNEL;
		curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	    ret = ccci_init(curr_ch, NULL);
	    if(ret!=CCCI_INVALID_PARAM) {
	        ccci_ut_format_err_str("ccci_init error, return CCCI_SUCCESS for CCCI_MAX_CHANNEL !!\r\n");
	        return KAL_FALSE;
	    }
	    curr_ch = CCCI_MAX_CHANNEL;
		curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	    ret = ccci_init_gpdior(curr_ch, NULL);
	    if(ret!=CCCI_INVALID_PARAM) {
	        ccci_ut_format_err_str("ccci_init error, return CCCI_SUCCESS for CCCI_MAX_CHANNEL !!\r\n");
	        return KAL_FALSE;
	    }
	    curr_ch = CCCI_MAX_CHANNEL;
		curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	    ret = ccci_deinit(curr_ch);
	    if(ret!=CCCI_INVALID_PARAM) {
	        ccci_ut_format_err_str("ccci_deinit error, return CCCI_SUCCESS for CCCI_MAX_CHANNEL !!\r\n");
	        return KAL_FALSE;
	    }
	    curr_ch = UT_HIF_TXQ_Q0;
		curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	    ret = ccci_init(curr_ch, ccci_ut_test_cb);  
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_init error, ret=%d !!\r\n", ret);
	        return KAL_FALSE;

	    }
		
		//peer_id = GET_PEER_ID(curr_ch);
		peer_channel = GET_PEER_CHANNEL(curr_ch);
	    ccci_ctrl_pool[peer_id][peer_channel].state = CCCI_ACTIVE_READ;
	    ret = ccci_deinit(curr_ch);
	    ccci_ctrl_pool[peer_id][peer_channel].state = CCCI_IDLE;
	    if(ret!=CCCI_FAIL) {
	        ccci_ut_format_err_str("ccci_deinit error, ret=%d!!\r\n", ret);
	        return KAL_FALSE;
	    }
	    phw_handle_api = ccci_get_hw_handle_api(CCCI_TYPE_UT_GPD);
	    phw_handle_api->hwq_detach = hifq_detach_fail;
	    ret = ccci_deinit(curr_ch);
	    phw_handle_api->hwq_detach = ccci_ut_gpdhif_q_detach;
	    if(ret!=CCCI_FAIL) {
	        ccci_ut_format_err_str("ccci_deinit error, ret=%d while hif return KAL_FALSE!!\r\n", ret);
	        return KAL_FALSE;
	    }
	    ret = ccci_deinit(curr_ch);  
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_deinit error, ret=%d !!\r\n", ret);
	        return KAL_FALSE;
	    }
	}
    //4 2. ccci_init/ccci_init_gpdior with funp=NULL: expect to return CCCI_INVALID_PARAM
    test_step ++; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);    
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
		curr_ch = UT_HIF_TXQ_Q0;
		curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	    ret = ccci_init(curr_ch, NULL);
	    if(ret!=CCCI_INVALID_PARAM) {
	        ccci_ut_format_err_str("ccci_init error, ret=%d while funp == NULL!!\r\n", ret);
	        return KAL_FALSE;
	    }
	    curr_ch = CCCI_UT_GPD_NOCB_TX0;
		curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	    ret = ccci_init_gpdior(curr_ch, NULL);
	    if(ret!=CCCI_INVALID_PARAM) {
	        ccci_ut_format_err_str("ccci_init_gpdior error, ret=%d while funp == NULL!!\r\n", ret);
	        return KAL_FALSE;
	    }
	}
    //4 3. perform ccci_init (for legacy) on GPD user channel: expect to return CCCI_INVALID_PARAM
    test_step ++; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);    
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
		curr_ch = CCCI_UT_GPD_NOCB_TX0;
		curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	    ret = ccci_init(curr_ch   ,ccci_ut_test_cb);  
	    if(ret!=CCCI_INVALID_PARAM) {
	        ccci_ut_format_err_str("ccci_init error, ret=%d !!\r\n", ret);
	        return KAL_FALSE;
	    }
	    curr_ch = CCCI_UT_GPD_RX0;
		curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	    ret = ccci_init(curr_ch   ,ccci_ut_test_cb);  
	    if(ret!=CCCI_INVALID_PARAM) {
	        ccci_ut_format_err_str("ccci_init error, ret=%d !!\r\n", ret);
	        return KAL_FALSE;
	    }
	}

    //4 4. ccci_init_gpdior with non GPD user channel: expect to return CCCI_INVALID_PARAM
    test_step ++; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);    
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    curr_ch = CCCI_UT_GPD_NOCB_TX0;
		curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	    pccci_ch_info = ccci_get_ch_info(curr_ch);
	    backup_hw_type = pccci_ch_info->hw_type_predifined;
	    pccci_ch_info->hw_type_predifined = CCCI_TYPE_MAX;
	    ret = ccci_init_gpdior(curr_ch, ccci_ut_testior_cb);
	    pccci_ch_info->hw_type_predifined = backup_hw_type;
	    if(ret!=CCCI_INVALID_PARAM) {
	        ccci_ut_format_err_str("ccci_init_gpdior error, ret=%d hw_type invalid!!\r\n", ret);
	        return KAL_FALSE;
	    }

	    backup_hw_type = pccci_ch_info->hw_type_predifined;
	    pccci_ch_info->hw_type_predifined = CCCI_TYPE_MIN;
	    ret = ccci_init_gpdior(curr_ch, ccci_ut_testior_cb);
	    pccci_ch_info->hw_type_predifined = backup_hw_type;    
	    if(ret!=CCCI_INVALID_PARAM) {
	        ccci_ut_format_err_str("ccci_init_gpdior error, ret=%d hw_type invalid!!\r\n", ret);
	        return KAL_FALSE;
	    }

	    phw_handle_api = ccci_get_hw_handle_api(CCCI_TYPE_UT_GPD);
	    phw_handle_api->gpdhwq_attach = hifq_gpd_attach_fail;
	    ret = ccci_init_gpdior(curr_ch, ccci_ut_testior_cb);
	    phw_handle_api->gpdhwq_attach = ccci_ut_gpdhif_q_attach;
	    if(ret!=CCCI_NO_PHY_CHANNEL) {
	        ccci_ut_format_err_str("ccci_init_gpdior error, ret=%d while hif return fail for attach!!\r\n", ret);
	        return KAL_FALSE;
	    }

	    curr_ch = CCCI_UT_BUFF_TX0;
		curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	    ret = ccci_init_gpdior(curr_ch, ccci_ut_testior_cb);   //CCCI_IORCALLBACK
	    if(ret!=CCCI_INVALID_PARAM) {
	        ccci_ut_format_err_str("ccci_init_gpdior error, ret=%d for buffer mode user !\r\n", ret);
	        return KAL_FALSE;
	    }
	    curr_ch = CCCI_UT_BUFF_RX0;
		curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	    ret = ccci_init_gpdior(curr_ch, ccci_ut_testior_cb);  
	    if(ret!=CCCI_INVALID_PARAM) {
	        ccci_ut_format_err_str("ccci_init_gpdior error, ret=%d for buffer mode user !\r\n", ret);
	        return KAL_FALSE;
	    }
	}
    //4 5. ccci_init/ccci_init_gpdior with the same channel number twice: expect to return CCCI_IN_USE
    test_step ++; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);    
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    curr_ch = CCCI_UT_BUFF_TX0;
		curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	    ret = ccci_init(curr_ch, ccci_ut_test_cb);  
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_init error, ret=%d !\r\n", ret);
	        return KAL_FALSE;
	    }

	    curr_ch = CCCI_UT_BUFF_TX0;
		curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	    ret = ccci_init(curr_ch       ,ccci_ut_test_cb);      
	    if(ret!=CCCI_IN_USE) {
	        ccci_ut_format_err_str("ccci_init error, ret=%d for twice ccci_init!\r\n", ret);
	        return KAL_FALSE;
	    }
	    curr_ch = CCCI_UT_BUFF_TX0;
		curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	    ret = ccci_deinit(curr_ch);  
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_deinit error, ret=%d !\r\n", ret);
	        return KAL_FALSE;
	    }

	    curr_ch = CCCI_UT_GPD_NOCB_TX0;
		curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	    ret = ccci_init_gpdior(curr_ch, ccci_ut_testior_cb);  
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_init_gpdior error, ret=%d !\r\n", ret);
	        return KAL_FALSE;
	    }
	    curr_ch = CCCI_UT_GPD_NOCB_TX0;
		curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	    ret = ccci_init_gpdior(curr_ch, ccci_ut_testior_cb);      
	    if(ret!=CCCI_IN_USE) {
	        ccci_ut_format_err_str("ccci_init_gpdior error, ret=%d for twice ccci_init!\r\n", ret);
	        return KAL_FALSE;
	    }
	    curr_ch = CCCI_UT_GPD_NOCB_TX0;
		curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	    ret = ccci_deinit(curr_ch);  
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_deinit error, ret=%d !\r\n", ret);
	        return KAL_FALSE;
	    }
	}
    //4 6. ccci_deinit an non-registered ccci_channel should return CCCI_SUCCESS
	ccci_deinit(14);
	test_step ++; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    for (ch_idx=(CCCI_UT_MAX_CHANNEL); ch_idx != 0 ; ch_idx --){
	        curr_ch = ch_idx-1;
			curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	        ret = ccci_deinit(curr_ch);
	        if(ret!=CCCI_SUCCESS) {
	            ccci_ut_format_err_str("ccci_deinit error, ret=%d, expect to return CCCI_SUCCESS for non-registered ch !\r\n", ret);
	            return KAL_FALSE;
	        }        
	    }
	}

    //4 7. ccci_init/ccci_init_gpd with all ccci channel defined in CCCI_CHANNEL_T should  return CCCI_SUCCESS
    test_step ++; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
		for (ch_idx=0; ch_idx < CCCI_UT_MAX_CHANNEL ; ch_idx++){
	        curr_ch = ch_idx;
			curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
			pccci_ch_info = ccci_get_ch_info(curr_ch);
	        if(CCCI_CH_USER_GPD == pccci_ch_info->user_mode_predifined){
	            ret = ccci_init_gpdior(curr_ch, ccci_ut_testior_cb);
	        }else{
	            ret = ccci_init(curr_ch,  ccci_ut_test_cb);
	        }
	        if(ret!=CCCI_SUCCESS) {
	            ccci_ut_format_err_str("ccci_deinit error, FAIL to init all ccci channel (%d) ret (%d)!\r\n", curr_ch, ret);
	            return KAL_FALSE;
	        }        
	    }
	}
    
    //4 8. ccci_deinit all registered ccci_channel registered in 8 should return CCCI_SUCCESS
    test_step ++; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    for (ch_idx=(CCCI_UT_MAX_CHANNEL); ch_idx != 0 ; ch_idx --){
	        curr_ch = ch_idx-1;
			curr_ch = GET_VIRTUAL_CHANNEL(peer_id,curr_ch);
	        ret = ccci_deinit(curr_ch);
	        if(ret!=CCCI_SUCCESS) {
	            ccci_ut_format_err_str("ccci_deinit error, FAIL to deinit all ccci channel (%d) ret (%d)!\r\n", curr_ch, ret);
	            return KAL_FALSE;
	        }    
	    }
	}
    test_step += 1; ccci_ut_printf("[PASS] %s::%d test PASS!!\r\n", __FUNCTION__, __LINE__);    
    return KAL_TRUE;

}

/*
ccci_ut_lb_gpd_usr_gpd_hw checks the GPD user on GPD HW Tx callback and loopback correctness
GPD mode users send Tx to GPD HIF with Tx callback function registered and loopback mode enabled. 
Expecting the TGPDs which has been processed can be collected by Tx callback function and the TGPDs loopback to Rx channels in order.
Steps
1. Initialize the CCCI_MD_LOG  Tx channel by ccci_init_gpdior. Expecting the initialization correctly.
 2. Reload RGPD for CCCI_MD_LOG  Rx channel. Expecting the reload successfully
 3. Send TGPDs request to Tx channels and expecting the Tx done callback received the processed TGPDs in order and Rx channel receives the loopback RGPDs correctly
 4. De-initialize the channels and expecting the de-initialization successfully
*/
kal_bool ccci_ut_lb_gpd_usr_gpd_hw(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    CCCI_RETURNVAL_T    ret;
    kal_uint32          testing_ch_cnt = 2;
    kal_uint32          test_step=0x20000000;
    kal_uint32          to_alloc, num_alloc;
    ccci_io_request_t   ccci_DL_ior;
    kal_uint32          i;
	kal_uint8			peer_id;
	kal_uint32			peer_channel;

    CCCI_UT_CH_T test_ch[CCCI_UT_PEER_ID_MAX][2] = {
		{
	        {CCCI_UT_GPD_TX1, CCCI_UT_GPD_RX1, CCCI_UT_MAGICW_TX,  CCCI_TX_COUNT, CCCI_TX_COUNT, 0},
	        {CCCI_UT_GPD_TX2, CCCI_UT_GPD_RX2, CCCI_UT_MAGICW1_TX, CCCI_TX_COUNT, CCCI_TX_COUNT, 0},
		},
		{
	        {CCCI_UT_GPD_TX1, CCCI_UT_GPD_RX1, CCCI_UT_MAGICW_TX,  CCCI_TX_COUNT, CCCI_TX_COUNT, 0},
	        {CCCI_UT_GPD_TX2, CCCI_UT_GPD_RX2, CCCI_UT_MAGICW1_TX, CCCI_TX_COUNT, CCCI_TX_COUNT, 0},
		}
    };
    
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
    /*initialization*/    
    ccci_DL_ior.next_request = NULL;

    //4 1. Initialize the CCCI_MD_LOG  Tx channel by ccci_init_gpdior. Expecting the initialization correctly.
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
    	ret = ccci_init_gpdior(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][0].ch_tx),ccci_ut_gpd_cb_magic);
	    if(CCCI_SUCCESS != ret){
	        ccci_ut_format_err_str("ccci_init_gpdior ERROR \r\n");
	        goto ccci_ut_txdone_cb_error;
	    }
	    ret = ccci_init_gpdior(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][0].ch_rx),ccci_ut_gpd_cb_magic);
	    if(CCCI_SUCCESS != ret){
	        ccci_ut_format_err_str("ccci_init_gpdior ERROR \r\n");
	        goto ccci_ut_txdone_cb_error;
	    }
	    ret = ccci_init_gpdior(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][1].ch_tx),ccci_ut_gpd_cb_magic1);
	    if(CCCI_SUCCESS != ret){
	        ccci_ut_format_err_str("ccci_init_gpdior ERROR \r\n");
	        goto ccci_ut_txdone_cb_error;
	    }
	    ret = ccci_init_gpdior(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][1].ch_rx),ccci_ut_gpd_cb_magic1);
	    if(CCCI_SUCCESS != ret){
	        ccci_ut_format_err_str("ccci_init_gpdior ERROR \r\n");
	        goto ccci_ut_txdone_cb_error;
	    }
	}

    //4 2. Reload RGPD for CCCI_MD_LOG  Rx channel. Expecting the reload successfully
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    to_alloc  = CCCI_UT_NIC_RGPD_RELOAD_CNT; 
	    for(i=0; i<testing_ch_cnt; i++){
	        num_alloc = qbmt_alloc_q_no_tail(
	                        CCCI_UL_BUF_TYPE,                  /* type */
	                        to_alloc,                          /* buff_num */
	                        (void **)(&ccci_DL_ior.first_gpd), /* pp_head */
	                        (void **)(&ccci_DL_ior.last_gpd)); /* pp_tail */
	        
	        
	        ASSERT(num_alloc == to_alloc); //or GPD leak in previous test cases
#ifdef __SDIOC_PULL_Q_ENH_DL__
	        ccci_DL_ior.num_gpd = num_alloc;
#endif
	        ret = ccci_write_gpd(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_rx), &ccci_DL_ior, NULL);
	        if(CCCI_SUCCESS != ret){
	            ccci_ut_format_err_str("ccci_write_gpd ERROR (%d)\r\n", ret);
	            goto ccci_ut_txdone_cb_error;
	        }
	    }
	}

    //4 3. Send TGPDs request to Tx channels and expecting the Tx done callback received the 
    //4         processed TGPDs in order and Rx channel receives the loopback RGPDs correctly
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
    
    ccci_ut_reset_counter();
    ccci_ut_hif_lb_mode(KAL_TRUE);
    for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    /*test_gpd_cnt_chx, serial_no_chx*/
	    while(test_ch[peer_id][0].temp_gpd_cnt > 0 ||\
	          test_ch[peer_id][1].temp_gpd_cnt > 0)
	    {
	         for (i = 0; i<testing_ch_cnt; i++){
	            if(test_ch[peer_id][i].temp_gpd_cnt > 0){
	                    if(CCCI_TXRX_SENT_CNT > test_ch[peer_id][i].temp_gpd_cnt){
	                        to_alloc = test_ch[peer_id][i].temp_gpd_cnt;
	                    }else{
	                        to_alloc = CCCI_TXRX_SENT_CNT;
	                    }
	            }else{
	                    continue;
	            }
	            num_alloc = qbmt_alloc_q_no_tail(
	                        CCCI_DL_BUF_TYPE,                  /* type */
	                        to_alloc,                          /* buff_num */
	                        (void **)(&ccci_DL_ior.first_gpd), /* pp_head */
	                        (void **)(&ccci_DL_ior.last_gpd)); /* pp_tail */
	            if(num_alloc != 0){
	                /*format TGPDs*/
#ifdef __SDIOC_PULL_Q_ENH_DL__
	                ccci_DL_ior.num_gpd = num_alloc;
#endif
	                ccci_ut_format_mb_gpd(&ccci_DL_ior,num_alloc,test_ch[peer_id][i].serial_no,test_ch[peer_id][i].mb_id, GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_tx));
	                test_ch[peer_id][i].serial_no += num_alloc;
	                ret = ccci_write_gpd(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_tx), &ccci_DL_ior, NULL);
	                if(CCCI_SUCCESS != ret){
	                    ccci_ut_format_err_str("ccci_write_gpd ERROR (%d)\r\n", ret);
	                    goto ccci_ut_txdone_cb_error;
	                }
	                test_ch[peer_id][i].temp_gpd_cnt-= num_alloc;
	            }else{
	                ccci_ut_format_err_str( 
	                    "ccci_write_gpd fail step(%d) cannot allocate TGPD %d##%d##%d##%d##%d##%d",
	                    test_step, 
	                    test_ch[peer_id][i].ch_tx,
	                    test_ch[peer_id][i].ch_rx,
	                    test_ch[peer_id][i].mb_id,
	                    test_ch[peer_id][i].total_gpd_cnt,
	                    test_ch[peer_id][i].temp_gpd_cnt,
	                    test_ch[peer_id][i].serial_no);
	                goto ccci_ut_txdone_cb_error;
	            }

	         }
	    }
	}
    //4 4. Check the loopback result
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    for(i=0;i<testing_ch_cnt;i++){
	        if(ccci_ut_ch_info[peer_id][test_ch[peer_id][i].ch_tx].ccci_uldl_iorcb_funp != NULL){
				peer_channel = GET_PEER_CHANNEL(test_ch[peer_id][i].ch_tx);
	            if(LB_COUNTER[peer_id][peer_channel] != test_ch[peer_id][i].total_gpd_cnt){
	                ccci_ut_format_err_str("Tx callback error ch(%d) expecting(%d) get(%d)\r\n", \
	                    test_ch[peer_id][i].ch_tx, test_ch[peer_id][i].total_gpd_cnt, LB_COUNTER[peer_id][peer_channel]);
	                goto ccci_ut_txdone_cb_error;
	            }
	        }
	        if(ccci_ut_ch_info[peer_id][test_ch[peer_id][i].ch_rx].ccci_uldl_iorcb_funp != NULL){
				peer_channel = GET_PEER_CHANNEL(test_ch[peer_id][i].ch_tx);
	            if(LB_COUNTER[peer_id][peer_channel] != test_ch[peer_id][i].total_gpd_cnt){
	                ccci_ut_format_err_str("Rx loopback error ch(%d) expecting(%d) get(%d)\r\n", \
	                    test_ch[peer_id][i].ch_rx, test_ch[peer_id][i].total_gpd_cnt, LB_COUNTER[peer_id][peer_channel]);
	                goto ccci_ut_txdone_cb_error;
	            }

	        }
	    }
	}
    
    ccci_ut_hif_lb_mode(KAL_FALSE);

    //4 5. De-initialize the channels and expecting the de-initialization successfully
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    for(i = 0; i<testing_ch_cnt ; i++){
	        ret = ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_tx));
	        if(CCCI_SUCCESS != ret){
	            ccci_ut_format_err_str("ccci_deinit error, ret=%d !\r\n", ret);
	            return KAL_FALSE;
	        }
	        ret = ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_rx));
	        if(CCCI_SUCCESS != ret){
	            ccci_ut_format_err_str("ccci_deinit error, ret=%d !\r\n", ret);
	            return KAL_FALSE;
	        }
	    }
	}
    test_step += 1; ccci_ut_printf("[PASS] %s::%d test PASS!!\r\n", __FUNCTION__, __LINE__);
    return KAL_TRUE;
    
ccci_ut_txdone_cb_error:
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    for(i = 0; i<testing_ch_cnt ; i++){
	        ret = ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_tx));
	        ret = ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_rx));
	    }
	}
    return KAL_FALSE;  

}
/*
ccci_ut_lb_mix_gpd_hw checks the BUFF/GPD user on GPD HW loopback correctness
1. Initialize the CCCI channels
2. Reload RGPD for GPD channels
3. Send TGPDs request to TOTAL_TEST_CH channels expect the result corret and RGPD reload correctly
4. Check the loopback result
5. deinit the channels
*/
kal_bool ccci_ut_lb_mix_gpd_hw(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    CCCI_RETURNVAL_T    ret;
    kal_uint32          test_step = 0x30000000;
    kal_uint32          testing_ch_cnt = 5;
    kal_char            data_buff[256];
    CCCI_BUFF_T         *ccci_buff;
    kal_uint32          to_alloc, num_alloc;
    ccci_io_request_t   ccci_DL_ior;
    kal_uint32          i;
    kal_bool            tx_finished;
	kal_uint8			peer_id;
	kal_uint32			peer_channel;

    CCCI_UT_CH_T test_ch[CCCI_UT_PEER_ID_MAX][5] = {
		{
	        {CCCI_UT_BUFF_TX0,  CCCI_UT_BUFF_RX0,  CCCI_UT_MAGICW_TX,  CCCI_TX_COUNT, CCCI_TX_COUNT, 0},
	        {CCCI_UT_BUFF_TX1,  CCCI_UT_BUFF_RX1,  CCCI_UT_MAGICW_TX,  CCCI_TX_COUNT, CCCI_TX_COUNT, 0},
	        {CCCI_UT_GPD_NOCB_TX0,   CCCI_UT_GPD_RX0,   CCCI_UT_MAGICW1_TX, CCCI_TX_COUNT, CCCI_TX_COUNT, 0},
	        {CCCI_UT_GPD_TX1,   CCCI_UT_GPD_RX1,   CCCI_UT_MAGICW_TX,  CCCI_TX_COUNT, CCCI_TX_COUNT, 0},
	        {CCCI_UT_GPD_TX2,   CCCI_UT_GPD_RX2,   CCCI_UT_MAGICW1_TX, CCCI_TX_COUNT, CCCI_TX_COUNT, 0},
		},
		{
	        {CCCI_UT_BUFF_TX0,  CCCI_UT_BUFF_RX0,  CCCI_UT_MAGICW_TX,  CCCI_TX_COUNT, CCCI_TX_COUNT, 0},
	        {CCCI_UT_BUFF_TX1,  CCCI_UT_BUFF_RX1,  CCCI_UT_MAGICW_TX,  CCCI_TX_COUNT, CCCI_TX_COUNT, 0},
	        {CCCI_UT_GPD_NOCB_TX0,   CCCI_UT_GPD_RX0,   CCCI_UT_MAGICW1_TX, CCCI_TX_COUNT, CCCI_TX_COUNT, 0},
	        {CCCI_UT_GPD_TX1,   CCCI_UT_GPD_RX1,   CCCI_UT_MAGICW_TX,  CCCI_TX_COUNT, CCCI_TX_COUNT, 0},
	        {CCCI_UT_GPD_TX2,   CCCI_UT_GPD_RX2,   CCCI_UT_MAGICW1_TX, CCCI_TX_COUNT, CCCI_TX_COUNT, 0},
		}
    };	

    /*initialization*/    
    ccci_DL_ior.next_request = NULL;
    memset(data_buff, 0, sizeof(data_buff));
    ccci_buff = (CCCI_BUFF_T*)data_buff;
    testing_ch_cnt = sizeof(test_ch)/sizeof(CCCI_UT_CH_T)/CCCI_UT_PEER_ID_MAX;
    
    //4 1. Initialize the CCCI channels
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    ret = ccci_init(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][0].ch_tx),ccci_ut_tx_buff_dummy_cb);
	    if(CCCI_SUCCESS != ret){
	        ccci_ut_format_err_str("ccci_init ERROR (%d)\r\n", ret);
	        goto error_exit;
	    }
	    ret = ccci_init(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][1].ch_tx),ccci_ut_tx_buff_dummy_cb);
	    if(CCCI_SUCCESS != ret){
	        ccci_ut_format_err_str("ccci_init ERROR (%d)\r\n", ret);
	        goto error_exit;
	    }
	    ret = ccci_init_gpdior(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][2].ch_tx),ccci_ut_tx_gpd_dummy_cb);
	    if(CCCI_SUCCESS != ret){
	        ccci_ut_format_err_str("ccci_init_gpdior ERROR (%d)\r\n", ret);
	        goto error_exit;
	    }
	    ret = ccci_init_gpdior(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][3].ch_tx),ccci_ut_gpd_cb_magic);
	    if(CCCI_SUCCESS != ret){
	        ccci_ut_format_err_str("ccci_init_gpdior ERROR (%d)\r\n", ret);
	        goto error_exit;
	    }
	    ret = ccci_init_gpdior(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][4].ch_tx),ccci_ut_gpd_cb_magic1);
	    if(CCCI_SUCCESS != ret){
	        ccci_ut_format_err_str("ccci_init_gpdior ERROR (%d)\r\n", ret);
	        goto error_exit;
	    }

	    ret = ccci_init(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][0].ch_rx),ccci_ut_buff_cb_magic);
	    if(CCCI_SUCCESS != ret){
	        ccci_ut_format_err_str("ccci_init ERROR (%d)\r\n", ret);
	        goto error_exit;
	    }
	    ret = ccci_init(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][1].ch_rx),ccci_ut_buff_cb_magic);
	    if(CCCI_SUCCESS != ret){
	        ccci_ut_format_err_str("ccci_init ERROR (%d)\r\n", ret);
	        goto error_exit;
	    }
	    ret = ccci_init_gpdior(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][2].ch_rx),ccci_ut_gpd_cb_magic1);
	    if(CCCI_SUCCESS != ret){
	        ccci_ut_format_err_str("ccci_init_gpdior ERROR (%d)\r\n", ret);
	        goto error_exit;
	    }
	    ret = ccci_init_gpdior(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][3].ch_rx), ccci_ut_gpd_cb_magic);
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_init_gpdior ERROR (%d)\r\n", ret);
	        goto error_exit;
	    }
	    ret = ccci_init_gpdior(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][4].ch_rx), ccci_ut_gpd_cb_magic1);
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_init_gpdior ERROR (%d)\r\n", ret);
	        goto error_exit;
	    }
	}

    //4 2. Reload RGPD for GPD channels
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
    for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
		to_alloc  = CCCI_UT_NIC_RGPD_RELOAD_CNT;
	    
	    for(i=0; i<testing_ch_cnt; i++){
	        if(ccci_ut_ch_info[peer_id][test_ch[peer_id][i].ch_rx].user_mode_predifined == CCCI_CH_USER_GPD){
	            num_alloc = qbmt_alloc_q_no_tail(
	                            CCCI_UL_BUF_TYPE,                  /* type */
	                            to_alloc,                          /* buff_num */
	                            (void **)(&ccci_DL_ior.first_gpd), /* pp_head */
	                            (void **)(&ccci_DL_ior.last_gpd)); /* pp_tail */
	            
	            ASSERT(num_alloc == to_alloc); //or GPD leak in previous test cases
#ifdef __SDIOC_PULL_Q_ENH_DL__
	            ccci_DL_ior.num_gpd = num_alloc;
#endif
	            ret = ccci_write_gpd(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_rx), &ccci_DL_ior, NULL);
	            if(CCCI_SUCCESS != ret){
	                ccci_ut_format_err_str("reload RGPD ccci_write_gpd ERROR (%d)\r\n", ret);
	                goto error_exit;
	            }          
	        }
	    }
	}
    //4 3. Send TGPDs request to TOTAL_TEST_CH channels expect the result corret and RGPD reload correctly
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);

    ccci_ut_reset_counter();
    ccci_ut_hif_lb_mode(KAL_TRUE);

    /*test_gpd_cnt_chx, serial_no_chx*/
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    tx_finished = KAL_FALSE;
	    while(KAL_FALSE == tx_finished)
	    {

	        for(i=0; i<testing_ch_cnt; i++){
	            if(ccci_ut_ch_info[peer_id][test_ch[peer_id][i].ch_rx].user_mode_predifined == CCCI_CH_USER_GPD){
	                if(test_ch[peer_id][i].temp_gpd_cnt > 0){
	                    if(CCCI_TXRX_SENT_CNT > test_ch[peer_id][i].temp_gpd_cnt){
	                        to_alloc = test_ch[peer_id][i].temp_gpd_cnt;
	                    }else{
	                        to_alloc = CCCI_TXRX_SENT_CNT;
	                    }
	                }else{
	                    continue;
	                }
	                num_alloc = qbmt_alloc_q_no_tail(
	                            CCCI_DL_BUF_TYPE,                  /* type */
	                            to_alloc,                          /* buff_num */
	                            (void **)(&ccci_DL_ior.first_gpd), /* pp_head */
	                            (void **)(&ccci_DL_ior.last_gpd)); /* pp_tail */
	                if(num_alloc != 0){
	                    /*format TGPDs*/
#ifdef __SDIOC_PULL_Q_ENH_DL__
	                    ccci_DL_ior.num_gpd = num_alloc;
#endif
	                    ccci_ut_format_mb_gpd(&ccci_DL_ior,num_alloc,test_ch[peer_id][i].serial_no,test_ch[peer_id][i].mb_id, GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_tx));
	                    test_ch[peer_id][i].serial_no += num_alloc;
	                    ret = ccci_write_gpd(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_tx), &ccci_DL_ior, NULL);
	                    if(CCCI_SUCCESS != ret){
	                        ccci_ut_format_err_str("ccci_write_gpd ERROR (%d)\r\n", ret);
	                        goto error_exit;
	                    }
	                    test_ch[peer_id][i].temp_gpd_cnt-= num_alloc;
	                }else{
	                    ccci_ut_format_err_str( 
	                        "ccci_write_gpd fail step(%d) cannot allocate TGPD %d##%d##%d##%d##%d##%d",
	                        test_step, 
	                        test_ch[peer_id][i].ch_tx,
	                        test_ch[peer_id][i].ch_rx,
	                        test_ch[peer_id][i].mb_id,
	                        test_ch[peer_id][i].total_gpd_cnt,
	                        test_ch[peer_id][i].temp_gpd_cnt,
	                        test_ch[peer_id][i].serial_no);
	                    goto error_exit;
	                }
	            }else{
	                if(test_ch[peer_id][i].temp_gpd_cnt > 0){
	                    CCCI_INIT_MAILBOX(ccci_buff, test_ch[peer_id][i].mb_id);
	                    CCCI_SET_RESERVED(ccci_buff, test_ch[peer_id][i].serial_no);
	                    ret = ccci_write(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_tx), ccci_buff);
	                    if(ret!=CCCI_SUCCESS){
	                        ccci_ut_format_err_str("ccci_write ERROR (%d)\r\n", ret);
	                        goto error_exit;
	                     }else{
	                        test_ch[peer_id][i].serial_no++;
	                        test_ch[peer_id][i].temp_gpd_cnt-= 1;
	                     }
	                }
	            }
	        }
	        
	        for(i=0; i<testing_ch_cnt; i++){
	            if(0 == test_ch[peer_id][i].temp_gpd_cnt){
	                tx_finished = KAL_TRUE;
	            }else{
	                tx_finished = KAL_FALSE;
	                break;
	            }
	        }
	    }
	}
    //4 4. Check the loopback result
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    for(i=0;i<testing_ch_cnt;i++){
	        if(ccci_ut_ch_info[peer_id][test_ch[peer_id][i].ch_tx].ccci_uldl_iorcb_funp != NULL){
				peer_channel = GET_PEER_CHANNEL(test_ch[peer_id][i].ch_tx);
	            if(LB_COUNTER[peer_id][peer_channel] != test_ch[peer_id][i].total_gpd_cnt){
	                ccci_ut_format_err_str("Tx callback error ch(%d) expecting(%d) get(%d) \r\n", \
	                    test_ch[peer_id][i].ch_tx, test_ch[peer_id][i].total_gpd_cnt, LB_COUNTER[peer_id][peer_channel]);
	                goto error_exit;
	            }
	        }
	        if(ccci_ut_ch_info[peer_id][test_ch[peer_id][i].ch_rx].ccci_uldl_iorcb_funp != NULL){
				peer_channel = GET_PEER_CHANNEL(test_ch[peer_id][i].ch_rx);
	            if(LB_COUNTER[peer_id][peer_channel] != test_ch[peer_id][i].total_gpd_cnt){
	                ccci_ut_format_err_str("Rx loopback error ch(%d) expecting(%d) get(%d) \r\n", \
	                    test_ch[peer_id][i].ch_rx, test_ch[peer_id][i].total_gpd_cnt, LB_COUNTER[peer_id][peer_channel]);
	                goto error_exit;
	            }

	        }
	    }
	}

    ccci_ut_hif_lb_mode(KAL_FALSE);

    //4 5. deinit the channels
	test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    
	    for(i = 0; i<testing_ch_cnt ; i++){
	        ret = ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_tx));
	        if(CCCI_SUCCESS != ret){
	            ccci_ut_format_err_str("ccci_deinit error, ret=%d !\r\n", ret);
	            goto error_exit;
	        }
	        ret = ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_rx));
	        if(CCCI_SUCCESS != ret){
	            ccci_ut_format_err_str("ccci_deinit error, ret=%d !\r\n", ret);
	            goto error_exit;
	        }
	    }
   	}
    test_step += 1; ccci_ut_printf("[PASS] %s::%d test PASS!!\r\n", __FUNCTION__, __LINE__);
    return KAL_TRUE;

error_exit:
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    for(i = 0; i<testing_ch_cnt ; i++){
	        ret = ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_tx));
	        ret = ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_rx));
	    }
	}
    return KAL_FALSE;

}

/*
ccci_ut_rx_mix_gpd_hw checks the RX functin for GPD/Buffer user on GPD HIF

1. Initialize the CCCI channels
2. insert 2 rgpd for each channel and check the result
3. Check the loopback result
4. deinit the channels
*/
#define CCCI_UT_RX_TEST_CNT 20
kal_bool ccci_ut_rx_mix_gpd_hw(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){

    CCCI_RETURNVAL_T    ret;
    kal_uint32          test_step = 0x40000000;
    kal_uint32          testing_ch_cnt;
    kal_uint32          to_alloc, num_alloc;
    ccci_io_request_t   ccci_UL_ior;
    ccci_io_request_t   ccci_UL_ior_tmp;
    kal_uint32          i, j;
	kal_uint8			peer_id;
	kal_uint32			peer_channel;
//    kal_bool            tx_finished;

    
    CCCI_UT_CH_T test_ch[CCCI_UT_PEER_ID_MAX][4] = {
		{
	        {CCCI_UT_BUFF_TX0,  CCCI_UT_BUFF_RX0,  CCCI_UT_MAGICW_TX,  CCCI_UT_RX_TEST_CNT, CCCI_UT_RX_TEST_CNT, 0},
	        {CCCI_UT_BUFF_TX1,  CCCI_UT_BUFF_RX1,  CCCI_UT_MAGICW_TX,  CCCI_UT_RX_TEST_CNT, CCCI_UT_RX_TEST_CNT, 0},
	        {CCCI_UT_GPD_TX1,   CCCI_UT_GPD_RX1,   CCCI_UT_MAGICW_TX,  CCCI_UT_RX_TEST_CNT, CCCI_UT_RX_TEST_CNT, 0},
	        {CCCI_UT_GPD_TX2,   CCCI_UT_GPD_RX2,   CCCI_UT_MAGICW1_TX, CCCI_UT_RX_TEST_CNT, CCCI_UT_RX_TEST_CNT, 0},
    	},
		{
			{CCCI_UT_BUFF_TX0,  CCCI_UT_BUFF_RX0,  CCCI_UT_MAGICW_TX,  CCCI_UT_RX_TEST_CNT, CCCI_UT_RX_TEST_CNT, 0},
	        {CCCI_UT_BUFF_TX1,  CCCI_UT_BUFF_RX1,  CCCI_UT_MAGICW_TX,  CCCI_UT_RX_TEST_CNT, CCCI_UT_RX_TEST_CNT, 0},
	        {CCCI_UT_GPD_TX1,   CCCI_UT_GPD_RX1,   CCCI_UT_MAGICW_TX,  CCCI_UT_RX_TEST_CNT, CCCI_UT_RX_TEST_CNT, 0},
	        {CCCI_UT_GPD_TX2,   CCCI_UT_GPD_RX2,   CCCI_UT_MAGICW1_TX, CCCI_UT_RX_TEST_CNT, CCCI_UT_RX_TEST_CNT, 0},
		}
	};

    //4 0.initialization    
    testing_ch_cnt = sizeof(test_ch)/sizeof(CCCI_UT_CH_T)/CCCI_UT_PEER_ID_MAX;

    //4 1. Initialize the CCCI channels
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    ret = ccci_init(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][0].ch_rx),ccci_ut_buff_cb_magic);
	    if(CCCI_SUCCESS != ret){
	        ccci_ut_format_err_str("ccci_init ERROR (%d)\r\n", ret);
	        goto error_exit;
	    }
	    ret = ccci_init(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][1].ch_rx),ccci_ut_buff_cb_magic);
	    if(CCCI_SUCCESS != ret){
	        ccci_ut_format_err_str("ccci_init ERROR (%d)\r\n", ret);
	        goto error_exit;
	    }
	    ret = ccci_init_gpdior(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][2].ch_rx), ccci_ut_gpd_cb_magic);
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_init_gpdior ERROR (%d)\r\n", ret);
	        goto error_exit;
	    }
	    ret = ccci_init_gpdior(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][3].ch_rx), ccci_ut_gpd_cb_magic1);
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_init_gpdior ERROR (%d)\r\n", ret);
	        goto error_exit;
	    }
	}

    //4 2. insert 2 rgpd for each channel and check the result
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
    ccci_ut_reset_counter();
    ccci_ut_hif_lb_mode(KAL_FALSE);

	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    ccci_UL_ior_tmp.next_request = NULL;
		ccci_UL_ior.next_request = NULL;
		ccci_UL_ior.first_gpd    = NULL;
		ccci_UL_ior.last_gpd     = NULL;
		ccci_UL_ior.num_gpd      = 0;
	    for(j = 0 ; j< CCCI_UT_RX_TEST_CNT; j++){
	        for(i = 0 ; i< testing_ch_cnt; i++){

	            to_alloc = 1; //test_ch[i].total_gpd_cnt;
	            num_alloc = qbmt_alloc_q_no_tail(
	                                CCCI_UL_BUF_TYPE,                      /* type */
	                                to_alloc,                              /* buff_num */
	                                (void **)(&ccci_UL_ior_tmp.first_gpd), /* pp_head */
	                                (void **)(&ccci_UL_ior_tmp.last_gpd)); /* pp_tail */
	                
	            ASSERT(num_alloc == to_alloc); //or GPD leak in previous test cases

#ifdef __SDIOC_PULL_Q_ENH_DL__
	            ccci_UL_ior.num_gpd += num_alloc;
#endif
	            ccci_ut_format_mb_gpd(&ccci_UL_ior_tmp,num_alloc,test_ch[peer_id][i].serial_no,test_ch[peer_id][i].mb_id, GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_rx));
	            QBM_DES_SET_NEXT(ccci_UL_ior_tmp.last_gpd, NULL);
	            
	            test_ch[peer_id][i].serial_no    += num_alloc;
	            test_ch[peer_id][i].temp_gpd_cnt -= num_alloc;

	            if( NULL == ccci_UL_ior.first_gpd ){
	                ccci_UL_ior.first_gpd = ccci_UL_ior_tmp.first_gpd;
	                ccci_UL_ior.last_gpd  = ccci_UL_ior_tmp.last_gpd;
	            }else{
	                QBM_DES_SET_NEXT(ccci_UL_ior.last_gpd, ccci_UL_ior_tmp.first_gpd);
	                ccci_UL_ior.last_gpd = ccci_UL_ior_tmp.last_gpd;
	            }

	        }

	        /* insert invalid GPD, dropped the disable channel GPDs*/
	        num_alloc = qbmt_alloc_q_no_tail(
	            CCCI_UL_BUF_TYPE,                      /* type */
	            to_alloc,                              /* buff_num */
	            (void **)(&ccci_UL_ior_tmp.first_gpd), /* pp_head */
	            (void **)(&ccci_UL_ior_tmp.last_gpd)); /* pp_tail */
	        ASSERT(num_alloc == to_alloc); //or GPD leak in previous test cases
#ifdef __SDIOC_PULL_Q_ENH_DL__
	        ccci_UL_ior.num_gpd += num_alloc;
#endif
	        ccci_ut_format_mb_gpd(&ccci_UL_ior_tmp,num_alloc,0,0, GET_VIRTUAL_CHANNEL(peer_id,CCCI_UT_BUFF_TX0));
	        QBM_DES_SET_NEXT(ccci_UL_ior_tmp.last_gpd, NULL);

	        QBM_DES_SET_NEXT(ccci_UL_ior.last_gpd, ccci_UL_ior_tmp.first_gpd);
	        ccci_UL_ior.last_gpd = ccci_UL_ior_tmp.last_gpd;

	    }    
	    ccci_ulior_cb(0, &ccci_UL_ior);
	}
    //4 3. Check the loopback result
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    for(i=0;i<testing_ch_cnt;i++){
	         if(ccci_ut_ch_info[peer_id][test_ch[peer_id][i].ch_rx].ccci_uldl_iorcb_funp != NULL){
				peer_channel = GET_PEER_CHANNEL(test_ch[peer_id][i].ch_rx);
	            if(LB_COUNTER[peer_id][peer_channel] != test_ch[peer_id][i].total_gpd_cnt){
	                ccci_ut_format_err_str("Rx loopback error ch(%d) expecting(%d) get(%d) \r\n", \
	                    test_ch[peer_id][i].ch_rx, test_ch[peer_id][i].total_gpd_cnt, LB_COUNTER[peer_id][peer_channel]);
	                goto error_exit;
	            }

	        }
	    }
	}

    //4 4. deinit the channels
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
    
    ccci_ut_hif_lb_mode(KAL_FALSE);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    for(i = 0; i<testing_ch_cnt ; i++){
	        ret = ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_tx));
	        if(CCCI_SUCCESS != ret){
	            ccci_ut_format_err_str("ccci_deinit error, ret=%d !\r\n", ret);
	            goto error_exit;
	        }
	        ret = ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_rx));
	        if(CCCI_SUCCESS != ret){
	            ccci_ut_format_err_str("ccci_deinit error, ret=%d !\r\n", ret);
	            goto error_exit;
	        }
	    }
	}
   
    test_step += 1; ccci_ut_printf("[PASS] %s::%d test PASS!!\r\n", __FUNCTION__, __LINE__);
    return KAL_TRUE;

error_exit:
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    for(i = 0; i<testing_ch_cnt ; i++){
	        ret = ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_tx));
	        ret = ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][i].ch_rx));
	    }
	}
    return KAL_FALSE;

}

/*
ccci_ut_rx_direct_user_buff_hw checks the buffer user Rx related function on buffer mode HIF Driver
*/
void ccci_ut_inject_rx_packet_buff_hw(kal_uint32 pkt_cnt, kal_uint32 ccci_ch_no, kal_uint32 mb_id){
    kal_uint32          i;
    kal_char            data_buff[256];
    CCCI_BUFF_T         *ccci_buff;

    memset(data_buff, 0, sizeof(data_buff));
    ccci_buff = (CCCI_BUFF_T*)data_buff;
    CCCI_INIT_MAILBOX(ccci_buff, mb_id);
    CCCI_SET_CH_NO(ccci_buff, ccci_ch_no);
    for (i = 0; i< pkt_cnt; i++){
        CCCI_SET_RESERVED(ccci_buff, i);
        ccci_ulbuff_cb(0, ccci_buff);
    }
    return;
}
kal_bool ccci_ut_rx_buff_user_buff_hw(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz)
{
    CCCI_RETURNVAL_T    ret;
    kal_uint32          test_step = 0x50000000;
	kal_uint8			peer_id;
	kal_uint32			peer_channel;
	
    CCCI_UT_CH_T test_ch[CCCI_UT_PEER_ID_MAX][1] = {
        {
			{CCCI_UT_BUFF_TX2,  CCCI_UT_BUFF_RX2,  CCCI_UT_MAGICW_TX,  CCCI_RX_COUNT, CCCI_RX_COUNT, 0}
		},
		{
			{CCCI_UT_BUFF_TX2,  CCCI_UT_BUFF_RX2,  CCCI_UT_MAGICW_TX,  CCCI_RX_COUNT, CCCI_RX_COUNT, 0}
		}	
    };
    
    //4 1. ccci_init for buff user on buff HIF
    test_step += 1; ccci_ut_printf("[PASS] %s::%d test PASS!!\r\n", __FUNCTION__, __LINE__);
	
    ccci_ut_reset_counter();
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    ret = ccci_init(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][0].ch_rx), ccci_ut_buff_cb_magic);
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_init error (%d) \r\n", ret);
	        goto error_exit;
	    }

	    ccci_ut_inject_rx_packet_buff_hw(test_ch[peer_id][0].temp_gpd_cnt,GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][0].ch_rx),test_ch[peer_id][0].mb_id);
		peer_channel = GET_PEER_CHANNEL(test_ch[peer_id][0].ch_rx);
	    if(LB_COUNTER[CCCI_PEER_ID_AP_MD][peer_channel] != test_ch[peer_id][0].total_gpd_cnt){
	        ccci_ut_format_err_str("Buff HIF Rx error ch(%d) expecting(%d) get(%d) \r\n", \
	             test_ch[peer_id][0].ch_rx, test_ch[peer_id][0].total_gpd_cnt, LB_COUNTER[peer_id][peer_channel]);
	        goto error_exit;
	    }

	    ret = ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][0].ch_rx));
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_deinit error (%d) \r\n", ret);
	        goto error_exit;
	    }
	}
    test_step += 1; ccci_ut_printf("[PASS] %s::%d test PASS!!\r\n", __FUNCTION__, __LINE__);
    return KAL_TRUE;

error_exit:
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
   		 ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,test_ch[peer_id][0].ch_rx));
	}
    return KAL_FALSE;
}

/*
ccci_ut_tx_buff_user_buff_hw the buffer user Tx related function on buffer mode HIF Driver
*/
kal_bool ccci_ut_tx_buff_user_buff_hw(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz)
{
    kal_char            data_buff[256];
    CCCI_RETURNVAL_T    ret;
    CCCI_CHANNEL_T      curr_txch = 0;
    CCCI_CHANNEL_T      curr_rxch = 0;
    CCCI_BUFF_T         *ccci_buff;
    kal_uint32          test_step = 0x60000000;
    kal_uint32          testing_ch_cnt, test_i, test_pkt_cnt;
	kal_uint8			peer_id;
	kal_uint32			peer_channel;

    CCCI_UT_CH_T test_ch[CCCI_UT_PEER_ID_MAX][1] = {
		{
        	{CCCI_UT_BUFF_TX2,  CCCI_UT_BUFF_RX2,  CCCI_UT_MAGICW_TX,  CCCI_TX_COUNT, CCCI_TX_COUNT, 0},
    	},
		{
			{CCCI_UT_BUFF_TX2,  CCCI_UT_BUFF_RX2,  CCCI_UT_MAGICW_TX,  CCCI_TX_COUNT, CCCI_TX_COUNT, 0},
		}
	};
    testing_ch_cnt = sizeof(test_ch)/sizeof(CCCI_UT_CH_T)/CCCI_UT_PEER_ID_MAX;
    memset(data_buff, 0, sizeof(data_buff));
    ccci_buff = (CCCI_BUFF_T*)data_buff;    

    //4 1. Buffer mode user call ccci_write
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	
	ccci_ut_reset_counter();
    for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    curr_txch    = test_ch[peer_id][0].ch_tx;
	    curr_rxch    = test_ch[peer_id][0].ch_rx;
	    test_pkt_cnt = test_ch[peer_id][0].total_gpd_cnt;
	    
	    ret = ccci_init(GET_VIRTUAL_CHANNEL(peer_id,curr_txch), ccci_ut_buff_cb);
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_init error (%d) \r\n", ret);
	        goto error_exit;
	    }
	    ret = ccci_init(GET_VIRTUAL_CHANNEL(peer_id,curr_rxch), ccci_ut_buff_cb);
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_init error (%d) \r\n", ret);
	        goto error_exit;
	    }
	}

    //4 2. Buffer mode user Tx test with ccci_write
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
		peer_channel = GET_PEER_CHANNEL(curr_txch);
	    ccci_ctrl_pool[peer_id][peer_channel].ioreq_funp = NULL; 
	    CCCI_INIT_MAILBOX(ccci_buff, CCCI_UT_MAGICW_TX);
	    ret = ccci_write(GET_VIRTUAL_CHANNEL(peer_id,peer_channel), ccci_buff);
	    if(CCCI_NO_PHY_CHANNEL != ret){
	        ccci_ut_format_err_str("ccci_write error (%d) \r\n", ret);
	        goto error_exit;
	    }
	    ccci_ctrl_pool[peer_id][peer_channel].ioreq_funp = ccci_ut_buffhif_submit;
	}

    //4 3. Test buff mode Tx flow
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
    /*test mailbox with content CCCI_UT_MAGICW_TX*/
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    CCCI_INIT_MAILBOX(ccci_buff, CCCI_UT_MAGICW_TX);   
		peer_channel = GET_PEER_CHANNEL(curr_txch); 
	    for(test_i = 0;test_i<test_pkt_cnt;test_i++){
	        CCCI_SET_RESERVED(ccci_buff, test_i);
	        ret = ccci_write(GET_VIRTUAL_CHANNEL(peer_id,peer_channel), ccci_buff);
	        if(ret!=CCCI_SUCCESS){
	            ccci_ut_format_err_str("[CCCI_UT] step %d: loop %d curr_txch return %d LB_COUNT %d##%d \r\n", \
	                 test_step, test_i, ret, LB_COUNTER[peer_id][peer_channel], LB_COUNTER[peer_id][peer_channel]);
	            goto error_exit;
	        }
	    }    
	}

    //4 4. Check the Tx Number
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
		peer_channel = GET_PEER_CHANNEL(curr_txch); 
	    if(LB_COUNTER[peer_id][peer_channel] != test_pkt_cnt){
	        ccci_ut_format_err_str("[CCCI_UT] ccci_ut_tx_buff_user_buff_hwccci cannot finish the tx \r\n", \
	                     test_step, test_i, ret, LB_COUNTER[peer_id][peer_channel], LB_COUNTER[peer_id][peer_channel]);
	        goto error_exit;
	    }
	}

    //4 5. Deinit the channel
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    ret = ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,curr_txch));
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_deinit error (%d) \r\n", ret);
	        goto error_exit;
	    }
	    ret = ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,curr_rxch));
	    if(ret!=CCCI_SUCCESS) {
	        ccci_ut_format_err_str("ccci_deinit error (%d) \r\n", ret);
	        goto error_exit;
	    }
	}
    test_step += 1; ccci_ut_printf("[PASS] %s::%d test PASS!!\r\n", __FUNCTION__, __LINE__);
    return KAL_TRUE;


error_exit:
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,curr_rxch));
	    ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,curr_txch));
	}
    return KAL_FALSE;
}

kal_bool ccci_ut_sdio_if(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz)
{
    //4 <1> ccci_init_handshake_phase1
    lte_ccci_init_handshake_phase1();
    //4 <2> ccci_init_handshake_phase2
    lte_ccci_init_handshake_phase2(0);
    return KAL_TRUE;
}

kal_bool ccci_ut_polling_io(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    CCCI_CHANNEL_T channel_tx = CCCI_UT_GPD_TX1;
    CCCI_CHANNEL_T channel_rx = CCCI_UT_GPD_RX1;
    qbm_gpd p_gpd;
    CCCI_RETURNVAL_T    ret;
    kal_bool is_tx = KAL_TRUE;
    kal_uint32 test_step = 0x70000000;
	kal_uint8			peer_id;

    //1.init FS channel
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    ret = ccci_init_gpdior(GET_VIRTUAL_CHANNEL(peer_id,channel_tx),ccci_ut_tx_gpd_dummy_cb);
	    if (ret != CCCI_SUCCESS){
	        ccci_ut_format_err_str("ccci_init_gpdior error (%d) \r\n", ret);
	        goto ccci_polling_mode_fail;
	    }
	    ret = ccci_init_gpdior(GET_VIRTUAL_CHANNEL(peer_id,channel_rx),ccci_ut_tx_gpd_dummy_cb);
	    if (ret != CCCI_SUCCESS){
	        ccci_ut_format_err_str("ccci_init_gpdior error (%d) \r\n", ret);
	        goto ccci_polling_mode_fail;
	    }
	}
    
    //2.error test
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    ret = ccci_polling_io(GET_VIRTUAL_CHANNEL(peer_id,CCCI_MAX_CHANNEL), &p_gpd, is_tx);
	    if (ret != CCCI_INVALID_PARAM){
	        ccci_ut_format_err_str("ccci_polling_io with CCCI_MAX_CHANNEL error (%d) \r\n", ret);
	        goto ccci_polling_mode_fail;
	    }
	    ret = ccci_polling_io(GET_VIRTUAL_CHANNEL(peer_id,channel_tx), NULL, is_tx);
	    if (ret != CCCI_INVALID_PARAM){
	        ccci_ut_format_err_str("ccci_polling_io with NULL p_gpd error (%d) \r\n", ret);
	        goto ccci_polling_mode_fail;
	    }
	    ret = ccci_polling_io(GET_VIRTUAL_CHANNEL(peer_id,CCCI_UT_BUFF_RX2), &p_gpd, is_tx);
	    if (ret != CCCI_INVALID_PARAM){
	        ccci_ut_format_err_str("ccci_polling_io with non-registered ch error (%d) \r\n", ret);
	        goto ccci_polling_mode_fail;
	    }
	}

    //3.Tx RX test
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    ret = ccci_polling_io(GET_VIRTUAL_CHANNEL(peer_id,channel_tx), &p_gpd, is_tx);
	    if (ret != CCCI_SUCCESS){
	        ccci_ut_format_err_str("[CCCI_UT] ccci_ut_polling_io Tx Fail \r\n");
	        goto ccci_polling_mode_fail;
	    }
	    is_tx=KAL_FALSE;
	    ret = ccci_polling_io(GET_VIRTUAL_CHANNEL(peer_id,channel_rx), &p_gpd, is_tx);
	    if (ret != CCCI_SUCCESS){
	        ccci_ut_format_err_str("[CCCI_UT] ccci_ut_polling_io Rx Fail \r\n");
	        goto ccci_polling_mode_fail;
	    }
		
	   
	    ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,channel_tx));
	    ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,channel_rx));
	}

    test_step += 1; ccci_ut_printf("[PASS] %s::%d test PASS!!\r\n", __FUNCTION__, __LINE__);
    return KAL_TRUE;

ccci_polling_mode_fail:	
	for(peer_id=CCCI_UT_PEER_ID_MIN; peer_id< CCCI_UT_PEER_ID_MAX; peer_id++){
	    ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,channel_tx));
	    ccci_deinit(GET_VIRTUAL_CHANNEL(peer_id,channel_rx));
	}
    return KAL_FALSE;
}
extern kal_bool dummy_submit_ior(kal_uint8 queue_type , kal_uint8 queue_no, void* ior);
kal_bool ccci_ut_misc(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    ccci_io_request_t   ccci_ior;
    qbm_gpd             test_gpd;
    CCCI_BUFF_T         test_head;
    kal_uint32          to_alloc, num_alloc;
    CCCI_BUFF_T         *pccci_head;
    kal_uint32          idx;
    kal_uint32          ccci_fs_shm_size;
    void                *ccci_fs_shm_base;
    kal_uint32 test_step = 0x80000000;
	kal_uint8			peer_id;
	kal_uint32			peer_channel;

    ccci_trace(CCCI_TRACE, CCCI_MOD_UT, CCCI_UT_FUNC_TRA, __LINE__);

    //4 <0> Toggle unsued function
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
    lte_ccci_hal_init();
	lte_ccci_hw_init_phase2();
    ccci_get_fs_shm_info(&ccci_fs_shm_base, &ccci_fs_shm_size);
    ccci_dhl_print(CCCI_TRACE, CCCI_MOD_UT, "Toogle ccci_dhl_print function\n");
    ccci_dump_data("Dummy CCCI_DATA_DUMP TEST", 24);

    //4 <1> ccci_ulior_cb error handling
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
	dummy_submit_ior(0,0,NULL);
    ccci_ulior_cb(0, NULL);
    ccci_ior.first_gpd = NULL;
    ccci_ior.last_gpd = &test_gpd;
    ccci_ulior_cb(0, &ccci_ior);
    ccci_ior.first_gpd = &test_gpd;
    ccci_ior.last_gpd = NULL;
    ccci_ulior_cb(0, &ccci_ior);

    //4 <2> ccci_dlior_agg_cb error handling
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
    ccci_dlior_agg_cb(0, NULL);
    ccci_ior.first_gpd = NULL;
    ccci_ior.last_gpd = &test_gpd;
    ccci_dlior_agg_cb(0, &ccci_ior);
    ccci_ior.first_gpd = &test_gpd;
    ccci_ior.last_gpd = NULL;
    ccci_dlior_agg_cb(0, &ccci_ior);   

    //4 <3> test ccci_ulbuff_cb error handling 
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
    ccci_ulbuff_cb(0, NULL);
    test_head.channel = CCCI_MAX_CHANNEL;
    ccci_ulbuff_cb(0, &test_head);  

    //4 <4> test ccci_ulior_cb error handling
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
    peer_id = GET_PEER_ID(CCCI_UT_BUFF_RX0);
	peer_channel = GET_PEER_CHANNEL(CCCI_UT_BUFF_RX0);
	for(idx = 0; idx < 1000; idx ++){
        ccci_ior.next_request = NULL;
        ccci_ior.first_gpd = NULL;
        ccci_ior.last_gpd = NULL;  
        to_alloc = 3;
        num_alloc = qbmt_alloc_q_no_tail(
                            QBM_TYPE_HIF_UL_TYPE,           /* type */
                            to_alloc,                       /* buff_num */
                            (void **)(&ccci_ior.first_gpd), /* pp_head */
                            (void **)(&ccci_ior.last_gpd)); /* pp_tail */    
        //Must allocate enough GPD, or you have GPD leakage, should assert  and find out right the way
        ASSERT(num_alloc == to_alloc); 
        pccci_head = CCCI_GET_QBM_DATAPTR(ccci_ior.first_gpd);
        pccci_head->channel = CCCI_UT_BUFF_TX0;
        pccci_head = CCCI_GET_QBM_DATAPTR(ccci_ior.first_gpd->p_next);
        pccci_head->channel = CCCI_UT_BUFF_RX0;
        pccci_head = CCCI_GET_QBM_DATAPTR(ccci_ior.last_gpd);
        pccci_head->channel = CCCI_UT_BUFF_RX0;
        ccci_init(CCCI_UT_BUFF_RX0, ccci_ut_test_cb);
        ccci_ctrl_pool[peer_id][peer_channel].cb_funp = NULL;
        ccci_ulior_cb(0, &ccci_ior);
        ccci_deinit(CCCI_UT_BUFF_RX0);
    }
    
    //4 <5> test ccci_dlior_agg_cb error handling
    test_step += 1; ccci_ut_printf("%s::%d test 0x%08x\r\n", __FUNCTION__, __LINE__, test_step);
    peer_id = GET_PEER_ID(CCCI_ARM7_RESERVED3_TX);
	peer_channel = GET_PEER_CHANNEL(CCCI_ARM7_RESERVED3_TX);
	for(idx = 0; idx < 1000; idx ++){
        ccci_ior.next_request = NULL;
        ccci_ior.first_gpd = NULL;
        ccci_ior.last_gpd = NULL;  
        to_alloc = 2;
        num_alloc = qbmt_alloc_q_no_tail(
                            QBM_TYPE_HIF_UL_TYPE,           /* type */
                            to_alloc,                       /* buff_num */
                            (void **)(&ccci_ior.first_gpd), /* pp_head */
                            (void **)(&ccci_ior.last_gpd)); /* pp_tail */    
        //Must allocate enough GPD, or you have GPD leakage, should assert  and find out right the way
        ASSERT(num_alloc == to_alloc); 
        pccci_head = CCCI_GET_QBM_DATAPTR(ccci_ior.first_gpd);
        pccci_head->channel = CCCI_MAX_CHANNEL;
        pccci_head = CCCI_GET_QBM_DATAPTR(ccci_ior.last_gpd);
        pccci_head->channel = CCCI_UT_BUFF_RX0;
        ccci_init(CCCI_UT_BUFF_TX0, ccci_ut_test_cb);
        ccci_ctrl_pool[peer_id][peer_channel].cb_funp = NULL;
        ccci_dlior_agg_cb(0, &ccci_ior);
        ccci_deinit(CCCI_UT_BUFF_TX0);
    }    

    test_step += 1; ccci_ut_printf("[PASS] %s::%d test PASS!!\r\n", __FUNCTION__, __LINE__);
    return KAL_TRUE;    
}

kal_bool ccci_ut_except(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    kal_uint32 test_step = 0x90000000;
    kal_int32  ccci_ret;
    qbm_gpd    tpgd;
    qbm_gpd    *rgpd_h, *rgpd_t;
    kal_uint32 rgpd_num;

    ccci_ut_expt_configure();

    ccci_ret = ccci_except_init_hmu((kal_uint32)NULL,(kal_uint32)NULL,(kal_uint32)NULL);
    if (ccci_ret != CCCI_SUCCESS){
        ccci_ut_format_err_str("[CCCI_UT] ccci_except_init_hmu Fail \r\n");
        return KAL_FALSE;
    }
    
    ccci_ret = ccci_except_clear_ch(CCCI_MD_LOG_TX);
    if (ccci_ret != CCCI_SUCCESS){
        ccci_ut_format_err_str("[CCCI_UT] ccci_except_clear_ch Fail \r\n");
        return KAL_FALSE;
    }
    /* Ut case pass the set gpd to ccci_ut_gpdhif_ex_set_gpd,
       so we use NULL as the gpd pointer.
       In the notmal case, please insert the non-NULL GPD */
    kal_mem_set(&tpgd, 0, sizeof(qbm_gpd));
    ccci_ret = ccci_except_set_gpd(CCCI_MD_LOG_TX, &tpgd, &tpgd);
    if (ccci_ret != CCCI_SUCCESS){
        ccci_ut_format_err_str("[CCCI_UT] ccci_except_set_gpd Fail \r\n");
        return KAL_FALSE;
    }
    
    rgpd_h = NULL;
    rgpd_t = NULL;
    ccci_ret = ccci_except_poll_gpd(CCCI_MD_LOG_RX, (void **)&rgpd_h, (void **)&rgpd_t, &rgpd_num);
    if (ccci_ret != CCCI_SUCCESS){
        ccci_ut_format_err_str("[CCCI_UT] ccci_except_poll_gpd Fail \r\n");
        return KAL_FALSE;
    }

    ccci_ret = ccci_except_hif_st(CCCI_MD_LOG_TX);
    if (ccci_ret != CCCI_SUCCESS){
        ccci_ut_format_err_str("[CCCI_UT] ccci_except_hif_st Fail \r\n");
        return KAL_FALSE;
    }

    ccci_ret = ccci_except_hif_isr(CCCI_MD_LOG_TX);
    if (ccci_ret != CCCI_SUCCESS){
        ccci_ut_format_err_str("[CCCI_UT] ccci_except_hif_isr Fail \r\n");
        return KAL_FALSE;
    }

    test_step += 1; ccci_ut_printf("[PASS] %s::%d test PASS!!\r\n", __FUNCTION__, __LINE__);
    return KAL_TRUE;       
}

static kal_uint32 ccci_misc_data_it_1;
static kal_uint32 ccci_misc_data_it_2[4];
kal_bool ccci_ut_except_memory(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    kal_uint32 test_step = 0xA0000000;
    kal_uint32 get_shm_ret, set_shm_ret;
    kal_uint32 ccci_debug_info_test_val_1 = 0xFFEEDDCC;
    kal_uint32 ccci_debug_info_test_val_2 = 0x11111111;
    kal_uint32 ccci_debug_info_test_val_3 = 0x22222222;    
    kal_uint32 ccci_debug_info_test_val_4 = 0x33333333;
    kal_uint32 kal_base, kal_size;
    kal_uint32 total_shm_size =0;
    CCCI_EXCEP_MEMORY_TYPE kal_type;
    MODEM_RUNTIME_DATA *ap_md_share_data = ccci_get_share_data();
    
    test_step += 1; ccci_ut_printf("[PASS] %s::%d test PASS!!\r\n", __FUNCTION__, __LINE__);

	ap_md_share_data->ExceShareMemBase = (kal_uint32) &MDExceShareMemBase;
    ap_md_share_data->ExceShareMemSize = mExceShareMemSize;

    // CCCI EXCEP MEMORY TEST
    set_shm_ret=  ccci_excep_init_shm(CCCI_EXCEP_MEMORY_TYPE_SHM);
    get_shm_ret = ccci_excep_query_shm(CCCI_EXCEP_MEMORY_REGION_CCCI, &ccci_excep_dbg_log_base_hs2, &ccci_excep_dbg_log_size_hs2, &ccci_excep_dbg_log_type_hs2);
    get_shm_ret = ccci_excep_query_shm(CCCI_EXCEP_MEMORY_REGION_KAL, &kal_base, &kal_size, &kal_type);
    
    set_shm_ret=  ccci_excep_init_shm(CCCI_EXCEP_MEMORY_TYPE_STATIC_BUFFER);
    get_shm_ret = ccci_excep_query_shm(CCCI_EXCEP_MEMORY_REGION_CCCI, &ccci_excep_dbg_log_base_hs2, &ccci_excep_dbg_log_size_hs2, &ccci_excep_dbg_log_type_hs2);
    get_shm_ret = ccci_excep_query_shm(CCCI_EXCEP_MEMORY_REGION_KAL, &kal_base, &kal_size, &kal_type);

    total_shm_size = ccci_excep_shm_get_total_size();     

    test_step += 1; ccci_ut_printf("[PASS] %s::%d CCCI EXCEP MEMORY test PASS!!\r\n", __FUNCTION__, __LINE__);
    
    // CCCI DEBUG INFO
    ccci_excep_dbg_logging_InHS2(0, &ccci_debug_info_test_val_1);
    ccci_excep_dbg_logging_InHS2(1, &ccci_debug_info_test_val_2);
    ccci_excep_dbg_logging_InHS2(2, &ccci_debug_info_test_val_3);
    ccci_excep_dbg_logging_InHS2(10, &ccci_debug_info_test_val_4);

    test_step += 1; ccci_ut_printf("[PASS] %s::%d CCCI Debug info test PASS!!\r\n", __FUNCTION__, __LINE__);

    // CCCI MISC DATA
	ccci_misc_data_feature_support(2, 4, &ccci_misc_data_it_1);
    ccci_misc_data_feature_support(15, 16, &ccci_misc_data_it_2);

    test_step += 1; ccci_ut_printf("[PASS] %s::%d CCCI MISC DATA test PASS!!\r\n", __FUNCTION__, __LINE__);

    

    return KAL_TRUE;  
}


kal_bool ccci_ut_seq_trace(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    CCCI_BUFF_T bufp;
    kal_uint32 add_seq_rtn, check_seq_rtn;
    kal_uint32 test_step = 0xA0000000;
    kal_uint32 i;
	kal_uint32 seq;
    kal_uint32 peer_id,peer_channel;
	// Test Add seq
    ccci_debug_reset_seq_data();
    
    for(peer_id =0 ; peer_id < CCCI_PEER_ID_MAX; peer_id++){
         for(peer_channel =0 ; peer_channel < CCCI_MAX_CHANNEL; peer_channel++){
		    for(i=0; i< 100000; i++){
                bufp.channel = GET_VIRTUAL_CHANNEL(peer_id, peer_channel);
                add_seq_rtn = ccci_debug_add_seq(&bufp, CCCI_DEBUG_ASSERT_BIT);
		        if(add_seq_rtn == CCCI_FAIL)
                    return KAL_FALSE;
             }
        }
    }
	test_step += 1; ccci_ut_printf("[PASS] %s::%d Add CCCI Seq Trace test PASS!!\r\n", __FUNCTION__, __LINE__);
    
	// Test check seq
    ccci_debug_reset_seq_data();
	
	bufp.channel =0;
    for(peer_id =0 ; peer_id < CCCI_PEER_ID_MAX; peer_id++){
         for(peer_channel =0 ; peer_channel < CCCI_MAX_CHANNEL; peer_channel++){
		    seq =0;
            bufp.channel = GET_VIRTUAL_CHANNEL(peer_id,peer_channel);
			for(i=0; i< 100000; i++){
                CCCI_DEBUG_CLR_SEQ_IN_CH(bufp.channel);
				CCCI_DEBUG_ADD_ASSERT_BIT_IN_CH(bufp.channel, CCCI_DEBUG_ASSERT_BIT);
				CCCI_DEBUG_ADD_SEQ_IN_CH(bufp.channel,seq);
				check_seq_rtn = ccci_debug_check_seq(&bufp);
    			CCCI_DEBUG_INCREASE_SEQ_NUM(seq);	
				if(check_seq_rtn == CCCI_FAIL)
					return KAL_FALSE;
			}
         }
    }
    
	test_step += 1; ccci_ut_printf("[PASS] %s::%d Check CCCI Seq Trace test PASS!!\r\n", __FUNCTION__, __LINE__);

	// Test if Seq is wrong, but assert bit =0
    ccci_debug_reset_seq_data();
    bufp.channel = CCCI_CONTROL_CHANNEL;
    CCCI_DEBUG_INCREASE_SEQ_NUM(seq);
	CCCI_DEBUG_ADD_SEQ_IN_CH(bufp.channel,seq);
	CCCI_DEBUG_ADD_ASSERT_BIT_IN_CH(bufp.channel, CCCI_DEBUG_NOT_ASSERT_BIT);
    check_seq_rtn = ccci_debug_check_seq(&bufp);
    test_step += 1; ccci_ut_printf("[PASS] %s::%d CCCI Seq Trace test PASS!!\r\n", __FUNCTION__, __LINE__);

	return KAL_TRUE;
}

extern kal_uint32 ccci_debug_get_status_L1Time_funp(kal_uint32 *write_ptr, kal_uint32 available_size);
extern kal_uint32 ccci_debug_get_status_ccciseq_funp(kal_uint32 *write_ptr, kal_uint32 available_size);
extern kal_uint32 ccci_rpc_get_debug_status(kal_uint32 *write_ptr, kal_uint32 available_size);
extern kal_uint32 ccci_ipc_get_debug_status(kal_uint32 *write_ptr, kal_uint32 available_size);
extern kal_uint32 ccci_fs_get_debug_status(kal_uint32 *write_ptr, kal_uint32 available_size);
extern kal_uint32 ccci_ims_get_debug_status(kal_uint32 *write_ptr, kal_uint32 available_size);

kal_bool ccci_ut_get_status(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    kal_uint32 test_step = 0xB0000000;
    kal_bool   rtn;
    // Test init
    rtn =  ccci_debug_init();
    if(rtn == KAL_FALSE)
        return KAL_FALSE;
    test_step += 1; ccci_ut_printf("[PASS] %s::%d Check get status init PASS!!\r\n", __FUNCTION__, __LINE__);

    // Test register
    rtn =  ccci_debug_get_status_register(CCCI_DEBUG_GET_STATUS_MODULE_L1TIME, ccci_debug_get_status_L1Time_funp);
    rtn =  ccci_debug_get_status_register(CCCI_DEBUG_GET_STATUS_MODULE_CCCIFS, ccci_fs_get_debug_status);
    rtn =  ccci_debug_get_status_register(CCCI_DEBUG_GET_STATUS_MODULE_CCCIRPC, ccci_rpc_get_debug_status);
    rtn =  ccci_debug_get_status_register(CCCI_DEBUG_GET_STATUS_MODULE_CCCIIPC, ccci_ipc_get_debug_status);
    rtn =  ccci_debug_get_status_register(CCCI_DEBUG_GET_STATUS_MODULE_CCCIIMS, ccci_ims_get_debug_status);
    rtn =  ccci_debug_get_status_register(CCCI_DEBUG_GET_STATUS_MODULE_CCCISEQ, ccci_debug_get_status_ccciseq_funp);
    test_step += 1; ccci_ut_printf("[PASS] %s::%d Check get status register PASS!!\r\n", __FUNCTION__, __LINE__);
    if(rtn == CCCI_FAIL)
        return KAL_FALSE;
   
    return KAL_TRUE;
}

extern kal_bool st_reg_test(kal_char *p_mod_name, ST_TCASE_T *p_tcase, kal_uint32 tcase_num);
#define CCCI_UT_CASE(_func, _param) { #_func, _func, _param }
kal_bool ccci_ut_st_create(void)
{
    static ST_TCASE_T ccci_ut_cases_s[] = {
        CCCI_UT_CASE(ccci_ut_configure, NULL),
        CCCI_UT_CASE(ccci_ut_init, NULL),
        /* GPD hif test */
        CCCI_UT_CASE(ccci_ut_lb_gpd_usr_gpd_hw, NULL),
        CCCI_UT_CASE(ccci_ut_rx_mix_gpd_hw, NULL),
        CCCI_UT_CASE(ccci_ut_lb_mix_gpd_hw, NULL),
        /*dummy buff hif test, might*/
        CCCI_UT_CASE(ccci_ut_rx_buff_user_buff_hw, NULL),
        CCCI_UT_CASE(ccci_ut_tx_buff_user_buff_hw, NULL),
        /*polling mode test*/
        CCCI_UT_CASE(ccci_ut_polling_io, NULL),
        /* misc_test */
        CCCI_UT_CASE(ccci_ut_sdio_if, NULL),
        CCCI_UT_CASE(ccci_buff_user_gpd_hif_example, NULL),
        CCCI_UT_CASE(ccci_ut_misc, NULL),
        /* ccci_except ut --> change ch config in ccci_ut_expt_configure*/
        CCCI_UT_CASE(ccci_ut_except, NULL),
        CCCI_UT_CASE(ccci_ut_except_memory, NULL),
        CCCI_UT_CASE(ccci_ut_seq_trace, NULL),
        CCCI_UT_CASE(ccci_ut_get_status, NULL),
    };

    return st_reg_test("CCCI", &(ccci_ut_cases_s[0]), (sizeof(ccci_ut_cases_s)/sizeof(ST_TCASE_T)));
}
#endif  //ATEST_SYS_CCCI

