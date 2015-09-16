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
 *   ccci_lb_it.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Impelements the CCCI Loopback IT
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
 * [CCCI] Disable CCCI IT LB when all HIF are disable.
 *
 * removed!
 * [MOLYxx] [] [CCCI_IT] Add CCCI loopback channel
 * [CCCI IT] Add IT loopback channel
 *
 ****************************************************************************/
#include "ccci_if.h"
//#if defined (__CCCI_LB_IT_ONLY__) /* in hif_ccci.mak */
#include "kal_public_api.h" //for INLINE
#include "syscomp_config.h"

#include "ccci_ch_cfg.h"
#include "ccci_common.h"

//#define _DUMP_COM_CONTENT_  //Dump the Tx/Rx content of COM PORT
#define CCCI_LB_IT_PORT_NUM  1

typedef struct CCCI_PORT_IT_CFG {
    CCCI_CHANNEL_T  ch_dl;
    CCCI_CHANNEL_T  ch_ul;
}ccci_port_it_cfg;

static ccci_port_it_cfg ccci_lb_it_port[CCCI_LB_IT_PORT_NUM] = {
        {CCCI_LB_IT_CHANNEL_TX, CCCI_LB_IT_CHANNEL_RX},  //TxQ0/RxQ0
};

void ccci_lb_it_buff_tx_cb(CCCI_BUFF_T *bufp){
    ccci_printf(CCCI_ERR, CCCI_MOD_IT, "==> ccci_it_buff_tx_cb The Tx dummy callback data0(%x) data1(len)(%x) ch(%x) reserve(%x)\n",bufp->data[0],bufp->data[1],bufp->channel,bufp->reserved);
    return;
}
void ccci_lb_it_buff_rx_lb(CCCI_BUFF_T *bufp)
{  

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

    return;
}

kal_bool ccci_lb_it_init(){
#if defined(__MTK_TARGET__)  //MODIS doesn't need CCCI IT loopback
    kal_uint32          idx; 
    CCCI_RETURNVAL_T    ccci_ret;
    
	ccci_printf(CCCI_TRACE, CCCI_MOD_IT, "===> ccci_it_init\n");

    for(idx = 0; idx < CCCI_LB_IT_PORT_NUM; idx++){
        ccci_printf(CCCI_TRACE, CCCI_MOD_IT, "===> ccci_it_init initialize ccci_duser_it_port[%d]\n", idx);
        ccci_ret = ccci_init(ccci_lb_it_port[idx].ch_dl,ccci_lb_it_buff_tx_cb);
        if(CCCI_IN_USE == ccci_ret){
            /* channel has been registered in normal process, deinit and reinit */
            ccci_deinit(ccci_lb_it_port[idx].ch_dl);
            ccci_ret = ccci_init(ccci_lb_it_port[idx].ch_dl,ccci_lb_it_buff_tx_cb);
        }
        ASSERT(CCCI_SUCCESS == ccci_ret);

        ccci_ret = ccci_init(ccci_lb_it_port[idx].ch_ul,ccci_lb_it_buff_rx_lb);
        if(CCCI_IN_USE == ccci_ret){
            /* channel has been registered in normal process, deinit and reinit */
            ccci_deinit(ccci_lb_it_port[idx].ch_ul);
            ccci_ret = ccci_init(ccci_lb_it_port[idx].ch_ul,ccci_lb_it_buff_rx_lb);
        }
        ASSERT(CCCI_SUCCESS == ccci_ret);
    }
#endif
    return KAL_TRUE;
}


/**************CCCITTY task********************/
kal_bool ccci_lb_it_task_init(void)
{
    return KAL_TRUE;
}

static void ccci_lb_it_1_task_main(task_entry_struct *task_entry_ptr)
{
   /*
     kal_uint32 idx, gpd_owe, rx_channel;
//     while (1){
     {
        for(idx = 0; idx < CCCI_LB_IT_PORT_NUM; idx ++)
        {
            rx_channel = ccci_gpduser_it_port[idx].ch_ul;
            gpd_owe = ccci_it_rpgd_owe[rx_channel];
            if(gpd_owe != 0){
                retry_reload_rgpd(gpd_owe, rx_channel);
            }
        }
        kal_sleep_task(KAL_TICKS_10_MSEC);
     }
     */

}

static void ccci_lb_it_2_task_main(task_entry_struct *task_entry_ptr)
{
}

static void ccci_lb_it_3_task_main(task_entry_struct *task_entry_ptr)
{
}

static void ccci_lb_it_4_task_main(task_entry_struct *task_entry_ptr)
{
}

kal_bool ccci_lb_it_1_task_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct ccciit_handler_info =
    {
        ccci_lb_it_1_task_main,        /* task entry function */
        ccci_lb_it_task_init,        /* task initialization function */
        NULL                        /* task reset handler */
    };
    ccci_printf(CCCI_ERR, CCCI_MOD_IT,"=========>ccci_lb_it_1_task_create\r\n");
    *handle = (comptask_handler_struct *)&ccciit_handler_info;
    return KAL_TRUE;
}

kal_bool ccci_lb_it_2_task_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct ccciit_handler_info =
    {
        ccci_lb_it_2_task_main,        /* task entry function */
        ccci_lb_it_task_init,        /* task initialization function */
        NULL                        /* task reset handler */
    };
    ccci_printf(CCCI_ERR, CCCI_MOD_IT,"=========>ccci_lb_it_2_task_create\r\n");
    *handle = (comptask_handler_struct *)&ccciit_handler_info;
    return KAL_TRUE;
}

kal_bool ccci_lb_it_3_task_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct ccciit_handler_info =
    {
        ccci_lb_it_3_task_main,        /* task entry function */
        ccci_lb_it_task_init,        /* task initialization function */
        NULL                        /* task reset handler */
    };
    ccci_printf(CCCI_ERR, CCCI_MOD_IT,"=========>ccci_lb_it_3_task_create\r\n");
    *handle = (comptask_handler_struct *)&ccciit_handler_info;
    return KAL_TRUE;
}

kal_bool ccci_lb_it_4_task_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct ccciit_handler_info =
    {
        ccci_lb_it_4_task_main,        /* task entry function */
        ccci_lb_it_task_init,        /* task initialization function */
        NULL                        /* task reset handler */
    };
    ccci_printf(CCCI_ERR, CCCI_MOD_IT,"=========>ccci_lb_it_4_task_create\r\n");
    *handle = (comptask_handler_struct *)&ccciit_handler_info;
    return KAL_TRUE;
}

//#endif  //__CCCI_LB_IT__
