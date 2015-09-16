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
 *   ccci_it.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Impelements the CCCI IT for SP integration test
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 04 11 2013 ap.wang
 * removed!
 * [CCCI IT] Add IT loopback channel
 *
 * 04 10 2013 ap.wang
 * removed!
 * [CCCI IT] Add IT loopback channel
 *
 * 03 18 2013 ap.wang
 * removed!
 * [CCCI_IT] Change RGPD reload flow
 *
 * 03 11 2013 ap.wang
 * removed!
 * [CCCI IT] Modify CCCI_IT GPD reload task, add sleep to release task resource
 *
 * removed!
 * removed!
 * MT6290 Rename CCCI Services
 *
 * removed!
 * removed!
 * [CCCI/CLDMA INT] 1. work around cldmacore initialization flow
 * 2. create CCCI DUMMY HIF interface for CCIF channels
 *
 * removed!
 * removed!
 * [CCCI_IT] 
 * 1. add uem channel it flow control
 * 2. IMS IT
 *
 * removed!
 * removed!
 * sync latest version of new features
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#include "ccci_if.h"
#if defined (__CCCI_LB_IT__) /* in hif_ccci.mak */
#include "kal_public_api.h" //for INLINE
#include "syscomp_config.h"

#include "ccci_ch_cfg.h"
#include "ccci_common.h"
#include "cccidev_qbm.h"
#include "qmu_bm.h"
#include "qmu_bm_util.h"
#include "dcl_uart.h"
#include "dcl.h"
#include "drv_msgid.h"

//#define _DUMP_COM_CONTENT_  //Dump the Tx/Rx content of COM PORT
#define CCCI_DIRECT_USR_IT_PORT_NUM  3
#define CCCI_DIRECT_GPD_USR_IT_PORT_NUM 3
#define CCCI_GPD_USR_IT_PORT_NUM     9

typedef struct CCCI_PORT_IT_CFG {
    CCCI_CHANNEL_T  ch_dl;
    CCCI_CHANNEL_T  ch_ul;
}ccci_port_it_cfg;

static kal_uint32 ccci_it_rpgd_owe[CCCI_MAX_CHANNEL];

static ccci_port_it_cfg ccci_duser_it_port[CCCI_DIRECT_USR_IT_PORT_NUM] = {
        {CCCI_CONTROL_CHANNEL, CCCI_CONTROL_CHANNEL_ACK},  //TxQ0/RxQ0
        {CCCI_SYSTEM_CHANNEL, CCCI_SYSTEM_CHANNEL_ACK},    //TxQ0/RxQ0
        {CCCI_PCM_CHANNEL, CCCI_PCM_CHANNEL_ACK},          //TxQ0/RxQ0
};

static ccci_port_it_cfg ccci_dgpduser_it_port[CCCI_DIRECT_GPD_USR_IT_PORT_NUM] = {
        {CCCI_IMSV_DL, CCCI_IMSV_UL},
        {CCCI_IMSA_DL, CCCI_IMSA_UL},
        {CCCI_IMSC_DL, CCCI_IMSC_UL},
};

static ccci_port_it_cfg ccci_gpduser_it_port[CCCI_GPD_USR_IT_PORT_NUM] = {
        {CCCI_PMIC_CHANNEL, CCCI_PMIC_ACK_CHANNEL},          //TxQ1/RxQ1
        {CCCI_UEM_CHANNEL, CCCI_UEM_ACK_CHANNEL},            //TxQ1/RxQ1
        {CCCI_IPC_RPC_CHANNEL, CCCI_IPC_RPC_ACK_CHANNEL},    //TxQ1/RxQ1
        {CCCI_MSGSVC_SEND_CHANNEL, CCCI_MSGSVC_RCV_CHANNEL}, //TxQ1/RxQ1
        {CCCI_FS_CHANNEL , CCCI_FS_ACK_CHANNEL},             //TxQ1/RxQ1
        {CCCI_AT_CHANNEL_TX, CCCI_AT_CHANNEL_RX},
        {CCCI_MD_LOG_RX, CCCI_MD_LOG_TX},
        {CCCI_TST_CHANNEL, CCCI_TR_CHANNEL},
        {CCCI_GPS_CHANNEL_TX, CCCI_GPS_CHANNEL_RX}
};
static void retry_reload_rgpd(kal_uint32 num_alloc, kal_uint32 channel);

void ccci_it_buff_tx_cb(CCCI_BUFF_T *bufp){
    ccci_printf(CCCI_ERR, CCCI_MOD_IT, "==> ccci_it_buff_tx_cb The Tx dummy callback data0(%x) data1(len)(%x) ch(%x) reserve(%x)\n",bufp->data[0],bufp->data[1],bufp->channel,bufp->reserved);
    return;
}
void ccci_it_buff_rx_lb(CCCI_BUFF_T *bufp)
{
    //4 < Rx Debug Message  >
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
#endif    

#ifdef __CCCI_DUSER_UL_PERF__
    ul_prof_id++;
    if(ul_prof_id >= CCCI_PERF_REC_CNT_1) ul_prof_id = 0;
#endif

    bufp->channel = bufp->channel-1;

#ifdef __CCCI_DUSER_DL_PERF__
    CCCI_PERF_GET_CYCLE(dl_prof[dl_prof_id].duser_ccci_write_s);
    ccci_write(bufp->channel, bufp);
    CCCI_PERF_GET_CYCLE(dl_prof[dl_prof_id].duser_ccci_write_e);

    dl_prof[dl_prof_id].duser_ccci_write_t = CCCI_PERF_GET_DURATION(dl_prof[dl_prof_id].duser_ccci_write_s,dl_prof[dl_prof_id].duser_ccci_write_e);
    dl_prof[dl_prof_id].duser_sdioc_submit_ior_t = CCCI_PERF_GET_DURATION(dl_prof[dl_prof_id].sdioc_submit_ior_s,dl_prof[dl_prof_id].sdioc_submit_ior_e);

    dl_prof_id++;
    if(dl_prof_id >= CCCI_PERF_REC_CNT_1) dl_prof_id = 0;
#else
    ccci_write(bufp->channel, bufp);
#endif

    //4 < Tx Debug Message  >
    /* print CCCI header content */
    ccci_printf(CCCI_TRACE, CCCI_MOD_IT, "\r\n Tx_LB: data0(%X) data1(len)(%X) ch(%X) reserve(%X)\r\n",bufp->data[0],bufp->data[1],bufp->channel,bufp->reserved);        

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
#endif
    return;
}
CCCI_CHANNEL_T _ccci_it_get_lb_ch(CCCI_CHANNEL_T channel){
    CCCI_CHANNEL_T      ccci_lb_ch = 0;

    switch (channel){
        case CCCI_MSGSVC_RCV_CHANNEL:
            ccci_lb_ch = CCCI_MSGSVC_SEND_CHANNEL;
            break;
        case CCCI_IPC_RPC_ACK_CHANNEL:
            ccci_lb_ch = CCCI_IPC_RPC_CHANNEL;
            break;   
        case CCCI_UEM_ACK_CHANNEL:
            ccci_lb_ch = CCCI_UEM_CHANNEL;
            break;
        case CCCI_PMIC_ACK_CHANNEL:
            ccci_lb_ch = CCCI_PMIC_CHANNEL;
            break;
        case CCCI_FS_ACK_CHANNEL:
            ccci_lb_ch = CCCI_FS_CHANNEL;
            break;
        case CCCI_AT_CHANNEL_RX:
            ccci_lb_ch = CCCI_AT_CHANNEL_TX;
            break;
        case CCCI_MD_LOG_TX:
            ccci_lb_ch = CCCI_MD_LOG_RX;
            break;
        case CCCI_TR_CHANNEL:
            ccci_lb_ch = CCCI_TST_CHANNEL;
            break;
        case CCCI_GPS_CHANNEL_RX:
            ccci_lb_ch = CCCI_GPS_CHANNEL_TX;
            break;
        case CCCI_IMSV_UL:
            ccci_lb_ch = CCCI_IMSV_DL;
            break;     
        case CCCI_IMSA_UL:
            ccci_lb_ch = CCCI_IMSA_DL;
            break;               
        case CCCI_IMSC_UL:
            ccci_lb_ch = CCCI_IMSC_DL;
            break;               
        default:
            ccci_printf(CCCI_ERR, CCCI_MOD_IT, "==> _ccci_it_get_lb_ch Invalid Rx ccci_ch(%X) \n",channel);
            ASSERT(0);
    }
    return ccci_lb_ch;
}

void ccci_it_gpd_tx_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* io_request){

    kal_uint32          idx, rx_channel;
    ccci_io_request_t   dl_reload_ior;
    qbm_gpd             *first_gpd;
    qbm_gpd             *last_gpd;   
    kal_uint32          num_gpd;
    kal_int32           ccci_ret;
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
#else

    ASSERT(NULL!=io_request);
    first_gpd = io_request->first_gpd;
    last_gpd = io_request->last_gpd;
    num_gpd = CCCIDEV_GET_GPD_LIST_SIZE(first_gpd, last_gpd);

    CCCIDEV_RST_CCCI_COMM_GPD_LIST(io_request->first_gpd,io_request->last_gpd);
    
//    dl_reload_ior = (ccci_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(first_gpd);
    dl_reload_ior.next_request = NULL;
    dl_reload_ior.first_gpd = first_gpd;
    dl_reload_ior.last_gpd = last_gpd;
#ifdef __SDIOC_PULL_Q_ENH_DL__
    dl_reload_ior.num_gpd = num_gpd;
#endif


    for(idx = 0; idx < CCCI_GPD_USR_IT_PORT_NUM; idx ++)
    {
        if( channel == ccci_gpduser_it_port[idx].ch_dl){
            rx_channel = ccci_gpduser_it_port[idx].ch_ul;
            break;
        }
    }
    if (CCCI_GPD_USR_IT_PORT_NUM == idx){
        /* callback from a non-exist channel */
        ASSERT(0);
    }

    ccci_ret=ccci_write_gpd(rx_channel, &dl_reload_ior, NULL);  
    ASSERT(CCCI_SUCCESS == ccci_ret);
#endif
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
#endif
    return;
}

void ccci_it_gpd_rx_lb(CCCI_CHANNEL_T channel, ccci_io_request_t* io_request){
    kal_uint32          num_gpd, to_alloc, num_alloc;
    kal_bool            end_of_list;
    CCCI_BUFF_T         *p_cccih_src;
#if 0 //ndef __CCCI_N_USE_TGPD_EXT__   
/* under construction !*/
#endif
    qbm_gpd             *first_gpd = NULL;
    qbm_gpd             *last_gpd = NULL;
    qbm_gpd             *curr_gpd = NULL;
    qbm_gpd             *next_gpd = NULL;
    
    ccci_io_request_t   *curr_ior = NULL;
    ccci_io_request_t   *next_ior = NULL;
//    ccci_io_request_t   *dl_reload_ior = NULL;

    CCCI_CHANNEL_T      loop_back_ccci_ch;
    kal_uint32          save_irqmask;

    num_gpd = 0;
    ASSERT(NULL!=io_request);
    loop_back_ccci_ch = _ccci_it_get_lb_ch(channel);
    for (curr_ior = io_request; curr_ior; curr_ior = next_ior) {
        next_ior  = curr_ior->next_request;
        first_gpd = curr_ior->first_gpd;
        last_gpd  = curr_ior->last_gpd;

        if (first_gpd && last_gpd){
            //4 <1> update the RGPD count in HIF
            num_gpd = CCCIDEV_GET_GPD_LIST_SIZE(first_gpd, last_gpd);
            ASSERT(num_gpd == CCCIDEV_GET_NONBPS_GPD_LIST_SIZE(first_gpd, last_gpd));

            ccci_printf(CCCI_TRACE, CCCI_MOD_IT, "[ccci_it_gpd_rx_lb] CCCI_CH (%d) Receive UL RGPD: %d\n",channel, num_gpd);
#ifdef __SDIOC_PULL_Q_ENH_DL__
            curr_ior->num_gpd = num_gpd;
#endif
            end_of_list = KAL_FALSE;
            for (curr_gpd = first_gpd; curr_gpd && !end_of_list; curr_gpd = next_gpd) {
                next_gpd = QBM_DES_GET_NEXT(curr_gpd);
                end_of_list = (curr_gpd == last_gpd);

                //4 <2> modify CCCI header, CCCI_BUFF_T
                p_cccih_src = CCCIDEV_GET_QBM_DATAPTR(curr_gpd);
                ASSERT (p_cccih_src->channel == channel);
#if 1 //def __CCCI_N_USE_TGPD_EXT__                
                p_cccih_src->channel = loop_back_ccci_ch;
                /* ian GPD type is QBM_TYPE_CCCI_COMM qbm auto invalidate/flush*/
#else
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
            } /* for (curr_gpd) */

        } else {/* if (first_gpd && last_gpd) */
            ccci_printf(CCCI_ERR, CCCI_MOD_IT, "[ccci_it_gpd_rx_lb] CCCI_CH (%d) Receive invalid IOR\n",channel);
            ASSERT(KAL_FALSE); /* Invalid IOR */
        }
    } /*for (curr_ior...*/
    ccci_write_gpd(loop_back_ccci_ch, io_request, NULL);

    to_alloc = num_gpd;

    CCCI_LOCK(save_irqmask);
    {
        ccci_it_rpgd_owe[channel] += to_alloc;
    }
    CCCI_UNLOCK(save_irqmask);

    ccci_printf(CCCI_TRACE, CCCI_MOD_IT, "[ccci_it_gpd_rx_lb] CCCI_CH (%d) owe rgpd (%d)/(%d)\n",channel, to_alloc, ccci_it_rpgd_owe[channel]);
    
    return;
}

kal_bool ccci_it_init(){
    kal_uint32          idx; 
    CCCI_RETURNVAL_T    ccci_ret;
    
    ccci_printf(CCCI_TRACE, CCCI_MOD_IT, "===> ccci_it_init\n");

    //4 <1> Initialize all direct user port
    for(idx = 0; idx < CCCI_DIRECT_USR_IT_PORT_NUM; idx++){
        ccci_printf(CCCI_TRACE, CCCI_MOD_IT, "===> ccci_it_init initialize ccci_duser_it_port[%d]\n", idx);
        ccci_ret = ccci_init(ccci_duser_it_port[idx].ch_dl,ccci_it_buff_tx_cb);
        if(CCCI_IN_USE == ccci_ret){
            /* channel has been registered in normal process, deinit and reinit */
            ccci_deinit(ccci_duser_it_port[idx].ch_dl);
            ccci_ret = ccci_init(ccci_duser_it_port[idx].ch_dl,ccci_it_buff_tx_cb);
        }
        ASSERT(CCCI_SUCCESS == ccci_ret);

        ccci_ret = ccci_init(ccci_duser_it_port[idx].ch_ul,ccci_it_buff_rx_lb);
        if(CCCI_IN_USE == ccci_ret){
            /* channel has been registered in normal process, deinit and reinit */
            ccci_deinit(ccci_duser_it_port[idx].ch_ul);
            ccci_ret = ccci_init(ccci_duser_it_port[idx].ch_ul,ccci_it_buff_rx_lb);
        }
        ASSERT(CCCI_SUCCESS == ccci_ret);
    }
    //4 <2> Initialize all GPD user port
    for(idx = 0; idx < CCCI_GPD_USR_IT_PORT_NUM; idx++){
        ccci_printf(CCCI_TRACE, CCCI_MOD_IT, "===> ccci_it_init initialize ccci_gpduser_it_port[%d]\n", idx);
        ccci_ret = ccci_init_gpdior(ccci_gpduser_it_port[idx].ch_dl,ccci_it_gpd_tx_cb); 
        if(CCCI_IN_USE == ccci_ret){
            /* channel has been registered in normal process, deinit and reinit */
            ccci_deinit(ccci_gpduser_it_port[idx].ch_dl);
            ccci_ret = ccci_init_gpdior(ccci_gpduser_it_port[idx].ch_dl,ccci_it_gpd_tx_cb); 
        }
        ASSERT(CCCI_SUCCESS == ccci_ret);

        ccci_ret = ccci_init_gpdior(ccci_gpduser_it_port[idx].ch_ul,ccci_it_gpd_rx_lb);
        if(CCCI_IN_USE == ccci_ret){
            /* channel has been registered in normal process, deinit and reinit */
            ccci_deinit(ccci_gpduser_it_port[idx].ch_ul);
            ccci_ret = ccci_init_gpdior(ccci_gpduser_it_port[idx].ch_ul,ccci_it_gpd_rx_lb);
        }
        ASSERT(CCCI_SUCCESS == ccci_ret);
    }
    
    //4 <3> Initialize all Direct GPD user port
    for(idx = 0; idx < CCCI_DIRECT_GPD_USR_IT_PORT_NUM; idx++){
        ccci_printf(CCCI_TRACE, CCCI_MOD_IT, "===> ccci_it_init initialize ccci_dgpduser_it_port[%d]\n", idx);
        ccci_ret = ccci_init_gpdior(ccci_dgpduser_it_port[idx].ch_dl,ccci_it_gpd_tx_cb); 
        if(CCCI_IN_USE == ccci_ret){
            /* channel has been registered in normal process, deinit and reinit */
            ccci_deinit(ccci_dgpduser_it_port[idx].ch_dl);
            ccci_ret = ccci_init_gpdior(ccci_dgpduser_it_port[idx].ch_dl,ccci_it_gpd_tx_cb); 
        }
        ASSERT(CCCI_SUCCESS == ccci_ret);

        ccci_ret = ccci_init_gpdior(ccci_dgpduser_it_port[idx].ch_ul,ccci_it_gpd_rx_lb);
        if(CCCI_IN_USE == ccci_ret){
            /* channel has been registered in normal process, deinit and reinit */
            ccci_deinit(ccci_dgpduser_it_port[idx].ch_ul);
            ccci_ret = ccci_init_gpdior(ccci_dgpduser_it_port[idx].ch_ul,ccci_it_gpd_rx_lb);
        }
        ASSERT(CCCI_SUCCESS == ccci_ret);
    }

    //4 <3> Initialize TTY port user
    /* TTY port is enabled at ccciitdev_task_main during MOD_CCCIITDEV1~4 task init */

    //4 <4> Initialize CCMNI port user
    /* enable CCMNI loop back */

    for(idx = 0; idx < CCCI_MAX_CHANNEL-1; idx ++)
    {
        ccci_it_rpgd_owe[idx] = 0;
    }
    /* set reload RGPD */
    for(idx = 0; idx < CCCI_GPD_USR_IT_PORT_NUM; idx++)
    {
        ccci_it_rpgd_owe[ccci_gpduser_it_port[idx].ch_ul] = 6;
    }
    return KAL_TRUE;
}

static void retry_reload_rgpd(kal_uint32 num_alloc, kal_uint32 channel){
    kal_uint32          to_alloc;
    kal_uint32          save_irqmask;
    qbm_gpd             *first_gpd = NULL;
    qbm_gpd             *last_gpd = NULL;
   
    ccci_io_request_t   *dl_reload_ior = NULL;

    to_alloc = num_alloc;
    {
        num_alloc = qbmt_alloc_q_no_tail(
                       QBM_TYPE_CCCI_COMM,       /* type */
                       to_alloc,                 /* buff_num */
                       (void **)(&first_gpd),    /* pp_head */
                       (void **)(&last_gpd));    /* pp_tail */

        if(0!=num_alloc){
            dl_reload_ior = (ccci_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(first_gpd);
            dl_reload_ior->next_request = NULL;
            dl_reload_ior->first_gpd = first_gpd;
            dl_reload_ior->last_gpd = last_gpd;
#ifdef __SDIOC_PULL_Q_ENH_DL__
            dl_reload_ior->num_gpd = num_alloc;
#endif
            ccci_write_gpd(channel, dl_reload_ior, NULL);
            to_alloc -= num_alloc;
            CCCI_LOCK(save_irqmask);
            {
                ccci_it_rpgd_owe[channel] -= num_alloc;
            }
            CCCI_UNLOCK(save_irqmask);        
        }
    }
    ccci_printf(CCCI_TRACE, CCCI_MOD_IT, "[ccci_it_gpd_rx_lb] CCCI_CH (%d) reload rgpd (%d)/(%d)\n",channel, num_alloc, ccci_it_rpgd_owe[channel]);
    
}

/**************CCCITTY task********************/
kal_bool ccciitdev_task_init(void)
{
    return KAL_TRUE;
}

static void ccciitdev1_task_main(task_entry_struct *task_entry_ptr)
{
     kal_uint32 idx, gpd_owe, rx_channel;
//     while (1){
     {
        for(idx = 0; idx < CCCI_GPD_USR_IT_PORT_NUM; idx ++)
        {
            rx_channel = ccci_gpduser_it_port[idx].ch_ul;
            gpd_owe = ccci_it_rpgd_owe[rx_channel];
            if(gpd_owe != 0){
                retry_reload_rgpd(gpd_owe, rx_channel);
            }
        }
        kal_sleep_task(KAL_TICKS_10_MSEC);
     }

}

static void ccciitdev2_task_main(task_entry_struct *task_entry_ptr)
{
}

static void ccciitdev3_task_main(task_entry_struct *task_entry_ptr)
{
}

static void ccciitdev4_task_main(task_entry_struct *task_entry_ptr)
{
}

kal_bool ccciitdev1_task_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct ccciit_handler_info =
    {
        ccciitdev1_task_main,        /* task entry function */
        ccciitdev_task_init,        /* task initialization function */
        NULL                        /* task reset handler */
    };
    ccci_printf(CCCI_ERR, CCCI_MOD_IT,"=========>ccciitdev1_task_create\r\n");
    *handle = (comptask_handler_struct *)&ccciit_handler_info;
    return KAL_TRUE;
}

kal_bool ccciitdev2_task_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct ccciit_handler_info =
    {
        ccciitdev2_task_main,        /* task entry function */
        ccciitdev_task_init,        /* task initialization function */
        NULL                        /* task reset handler */
    };
    ccci_printf(CCCI_ERR, CCCI_MOD_IT,"=========>ccciitdev2_task_create\r\n");
    *handle = (comptask_handler_struct *)&ccciit_handler_info;
    return KAL_TRUE;
}

kal_bool ccciitdev3_task_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct ccciit_handler_info =
    {
        ccciitdev3_task_main,        /* task entry function */
        ccciitdev_task_init,        /* task initialization function */
        NULL                        /* task reset handler */
    };
    ccci_printf(CCCI_ERR, CCCI_MOD_IT,"=========>ccciitdev3_task_create\r\n");
    *handle = (comptask_handler_struct *)&ccciit_handler_info;
    return KAL_TRUE;
}

kal_bool ccciitdev4_task_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct ccciit_handler_info =
    {
        ccciitdev4_task_main,        /* task entry function */
        ccciitdev_task_init,        /* task initialization function */
        NULL                        /* task reset handler */
    };
    ccci_printf(CCCI_ERR, CCCI_MOD_IT,"=========>ccciitdev4_task_create\r\n");
    *handle = (comptask_handler_struct *)&ccciit_handler_info;
    return KAL_TRUE;
}

#endif  //__CCCI_LB_IT__
