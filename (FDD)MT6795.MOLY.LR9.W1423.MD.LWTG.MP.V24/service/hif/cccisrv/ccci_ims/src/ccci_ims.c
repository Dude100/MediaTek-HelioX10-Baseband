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
 *   ccci_ims.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   CCCI_IMS 
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
 * [CCCI] CCCI new debug mechanism
 *
 * removed!
 * removed!
 * Submit CCCI L2 trace
 *
 * 09 06 2013 ap.wang
 * removed!
 *
 * 05 30 2013 ap.wang
 * removed!
 * [CCCI_IMS] Add IMS_DCTRL channel
 *
 * 01 28 2013 ap.wang
 * removed!
 * [CCCI] CCCI_IMS channel rename
 *
 * removed!
 * removed!
 * [CCCI_IT] 
 * 1. add uem channel it flow control
 * 2. IMS IT
 *
 * removed!
 * removed!
 * [CCCI] CCCI_IMS 1st verison loopback support
 ****************************************************************************/
#include "ccci_ims_if.h"
#include "ccci_ims_common.h"
#include "ccci_ims_debug.h"
#include "kal_trace.h"

static ccci_ims_inst_t ccci_ims_inst;
static CCCI_IMS_DEBUG_STATUS_T ccci_ims_debug_status;

#define CCCI_IMS_DUMP_SIZE (32)
#define CCCI_IMS_DATA_TRACE_DUMP_ENABLE (1)
#if CCCI_IMS_DATA_TRACE_DUMP_ENABLE
static void ccci_ims_dump_data(kal_uint32 ch, void* p_data, kal_uint32 bytes){
    kal_int32 i = 0;
    kal_uint32* p_d = (kal_uint32*)((int)p_data & (~0X3));// 4bytes alignment 
    for (i=0; i*4 < bytes; i=i+4 ){
        ccci_ims_data_trace(CCCI_IMS_DATA_DUMP_TRACE,ch, i*4 , p_d[i], p_d[i+1], p_d[i+2], p_d[i+3]);
    }
}
#endif

static kal_uint32 ccci_ims_ch2devid(kal_uint32 ccci_ch_num)
{
   kal_uint32  ims_dev_id=CCCI_IMS_CH_MAX;
    switch(ccci_ch_num)
    {
        case CCCI_IMSV_UL:
        case CCCI_IMSV_DL:
            ims_dev_id = CCCI_IMS_VIDEO;
            break;
        case CCCI_IMSC_UL:
        case CCCI_IMSC_DL:
            ims_dev_id = CCCI_IMS_CTRL;
            break;
        case CCCI_IMSA_UL:
        case CCCI_IMSA_DL:
            ims_dev_id = CCCI_IMS_AUD;
            break;
        case CCCI_IMSD_UL:
        case CCCI_IMSD_DL:
            ims_dev_id = CCCI_IMS_DCTRL;
            break;
        default:
            ASSERT(0);
            break;
    }
    return ims_dev_id;
}

void ccci_ims_ccci_ul_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* io_request)
{
    qbm_gpd             *first_gpd = NULL;
    qbm_gpd             *last_gpd = NULL;
    qbm_gpd             *prev_gpd;
    qbm_gpd             *curr_gpd;
    qbm_gpd             *next_gpd;
    kal_bool            end_of_list;
    
    kal_bool            valid_gpd = KAL_FALSE;    
    ccci_io_request_t   *curr_ior;
    ccci_io_request_t   *next_ior;
    
    kal_uint32 dev_id = ccci_ims_ch2devid(channel);
    ccci_ims_device_t   *curr_dev;

    ASSERT(NULL != io_request);
    curr_dev = &ccci_ims_inst.dev[dev_id];

    if(IMS_DEV_CONNECTED != curr_dev->state)
    {
        /* Drop Packet */
        ccci_dest_ior(io_request);
        ccci_ims_print(CCCI_IMS_ERR, CCCI_IMS_MOD_DATA, "[CCCI_IMS][ERR]!!PKT DROP!! ccci_ims_ccci_ul_cb wrong state (%d)",curr_dev->state);
        return;
    }

    for(curr_ior = io_request; curr_ior; curr_ior = next_ior) {
        next_ior  = curr_ior->next_request;
        first_gpd = curr_ior->first_gpd;
        last_gpd  = curr_ior->last_gpd;
        //3 Note that, because GPD might be freeed in the following loop, we shall not access curr_ior from now.

        ASSERT(NULL != first_gpd);
        ASSERT(NULL != last_gpd);

        prev_gpd = NULL;
        end_of_list = KAL_FALSE;
        for (curr_gpd = first_gpd; curr_gpd && !end_of_list; curr_gpd = next_gpd) {
            next_gpd = QBM_DES_GET_NEXT(curr_gpd);
            end_of_list = (curr_gpd == last_gpd);
            ccci_debug_check_seq((CCCI_BUFF_T *)CCCI_IMS_GET_QBM_DATAPTR(curr_gpd)); // check ccci seq
            valid_gpd = CCCI_IMS_RM_CCCI_HEADERS(channel, curr_gpd);
            //ASSERT(KAL_TRUE == valid_gpd);
            if(KAL_TRUE == valid_gpd){                                                                                               
                prev_gpd = curr_gpd;                                                                                                 
            }else{
                ccci_ims_print(CCCI_IMS_ERR, CCCI_IMS_MOD_DATA, "[CCCI_IMS][ERR]!!PKT DROP!! ccci_ims_ccci_ul_cb wrong gpd");
                /* RT queue doesn't need to reload */
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
                /* dest the error one, curr_gpd*/
                qbmt_dest_q(curr_gpd, curr_gpd);
            }
        }
    } /*for (curr_ior...*/
    if (first_gpd) {
        curr_dev->ch_set.rx_cb(dev_id, io_request);
    }else {
        ASSERT(NULL == last_gpd);
    }
    
    return;
}


void ccci_ims_dlcb_dummy(CCCI_CHANNEL_T channel, ccci_io_request_t* io_request){

    /* RT queue should not callback */
    ASSERT(KAL_FALSE);
    return;
}

kal_bool ccci_ims_ulcb_reg (kal_uint8 ims_ch, CCCI_IMSCALLBACK ulcb_funp)
{
    kal_uint8 dev_state;
    if(NULL == ulcb_funp){
        ccci_ims_print(CCCI_IMS_ERR, CCCI_IMS_MOD_DATA, "[CCCI_IMS][ERR]ccci_ims_ulcb_reg, NULL == ulcb_funp");
        return KAL_FALSE;
    }
    if(ims_ch >= CCCI_IMS_CH_MAX){
        ccci_ims_print(CCCI_IMS_ERR, CCCI_IMS_MOD_DATA, "[CCCI_IMS][ERR]ccci_ims_ulcb_reg, ims_ch(%d) >= CCCI_IMS_CH_MAX", ims_ch);
        return KAL_FALSE;
    }
    dev_state = ccci_ims_inst.dev[ims_ch].state;
    if(IMS_DEV_INITIALIZED != dev_state)
    {
        /* state == IMS_DEV_UNINITIALIZED: ccci_ims_ulcb_reg called before CCCI_IMS initialization */
        /* state == IMS_DEV_CONNECTED    : Channel registered twice */
        ccci_ims_print(CCCI_IMS_ERR, CCCI_IMS_MOD_DATA, "[CCCI_IMS][ERR]ulcb_reg wrong state, with device state %d",dev_state);
        return KAL_FALSE;
    }
    ccci_ims_inst.dev[ims_ch].ch_set.rx_cb = ulcb_funp;
    ccci_ims_inst.dev[ims_ch].state = IMS_DEV_CONNECTED;
    
    return KAL_TRUE;
}

static kal_uint32 ccci_ims_process_dl_gpd_list(ccci_ims_device_t *pDevice, qbm_gpd* first_gpd, qbm_gpd* last_gpd)
{  /*process_tx_gpd_list*/
    qbm_gpd*            current_gpd = NULL;
    kal_uint32          pkt_cnt   = 0;
    kal_uint32          byte_cnt  = 0;
    kal_uint32          ccci_h_size;
    CCCI_BUFF_T         *p_ccci_head;
    
    ASSERT(first_gpd && last_gpd);
  
    current_gpd = first_gpd;
    ccci_h_size = sizeof(CCCI_BUFF_T);
    ASSERT(ccci_h_size > 0);
    do {
        //4 <1> append CCCI header CCCI_BUFF_T
        /*move data buffer pointer forward for ccci header, increase the gpd, bd length*/
        CCCI_IMS_PUSH_QBM_DATAHEAD(current_gpd, ccci_h_size);
        p_ccci_head   = (CCCI_BUFF_T *)CCCI_IMS_GET_QBM_DATAPTR(current_gpd);
        /*Construct the CCCI header*/
        CCCI_SET_CH_NO(p_ccci_head, pDevice->ch_set.tx);
        ccci_debug_add_seq(p_ccci_head, CCCI_DEBUG_ASSERT_BIT); // add ccci seq
        /* 20120723 MT6575 AP side usage of ccci_header->length, ccci_h.data[1], to identify the length */
        CCCI_STREAM_SET_LEN(p_ccci_head, CCCI_IMS_GET_QBM_DATALEN(current_gpd));

#if CCCI_IMS_DATA_TRACE_DUMP_ENABLE        
        ccci_ims_dump_data(p_ccci_head->channel, CCCI_IMS_GET_QBM_DATAPTR(current_gpd), CCCI_IMS_DUMP_SIZE);
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

kal_bool ccci_ims_dl_req (kal_uint32 ims_ch, ccci_io_request_t *p_ior)
{
    kal_uint8           dev_state;
    kal_uint32          ccci_tx_ch;
    ccci_io_request_t   *ior_curr  = NULL;
    kal_int32           ccci_ret;
    kal_bool            ret = KAL_FALSE;
    CCCI_BUFF_T         *p_ccci_head;
    kal_int32           ior_pkt_cnt = 0;
    kal_int32           dl_ttl_pkt_cnt = 0;

    if(NULL == p_ior){
        ccci_ims_print(CCCI_IMS_ERR, CCCI_IMS_MOD_DATA, "[CCCI_IMS][ERR]ccci_ims_dl_req, NULL == p_ior");
        return KAL_FALSE;
    }
    if(ims_ch >= CCCI_IMS_CH_MAX){
        ccci_ims_print(CCCI_IMS_ERR, CCCI_IMS_MOD_DATA, "[CCCI_IMS][ERR]ccci_ims_dl_req, ims_ch(%d) >= CCCI_IMS_CH_MAX", ims_ch);
        return KAL_FALSE;
    }
    dev_state = ccci_ims_inst.dev[ims_ch].state;
    if(IMS_DEV_CONNECTED != dev_state)
    {
        /* state == IMS_DEV_UNINITIALIZED: ccci_ims_dl_req called before CCCI_IMS initialization */
        /* state == IMS_DEV_INITIALIZED  : DL before channel initialized */
        ccci_ims_print(CCCI_IMS_ERR, CCCI_IMS_MOD_DATA, "[CCCI_IMS][ERR]DL wrong state, DL request with device state %d",dev_state);
        return KAL_FALSE;
    }

    /* checking ior paremeters */
    ASSERT(NULL != p_ior->first_gpd);
    ASSERT(NULL != p_ior->last_gpd);
    
    /*ASSERT(0 < p_ior->num_gpd);*/
    /*p_ior->num_gpd = process dl_ior return*/

    //4 <1> Insert CCCI_H
    ior_curr = p_ior;
    do {

        ccci_io_request_t* next_ior = ior_curr->next_request;
        CCCI_IMS_FIX_IOR_NULL_LAST(ior_curr);
		EXT_ASSERT(ior_curr->first_gpd && ior_curr->last_gpd, (kal_uint32) ior_curr->first_gpd, (kal_uint32) ior_curr->last_gpd, 0);
        ior_pkt_cnt = ccci_ims_process_dl_gpd_list(&ccci_ims_inst.dev[ims_ch], ior_curr->first_gpd, ior_curr->last_gpd);
        dl_ttl_pkt_cnt += ior_pkt_cnt;
#ifdef __SDIOC_PULL_Q_ENH_DL__
        ior_curr->num_gpd = ior_pkt_cnt;
#endif
        ior_curr = next_ior;
    } while ( ior_curr != NULL );

    p_ccci_head   = (CCCI_BUFF_T *)CCCI_IMS_GET_QBM_DATAPTR(p_ior->first_gpd);
    ccci_ims_print(CCCI_IMS_TRACE, CCCI_IMS_MOD_DATA, "[CCCI_IMS][DL] Tx CH(%d) pkt_no(%d) CCCI_H(%x)(%x)(%x)(%x)" , ims_ch, dl_ttl_pkt_cnt, p_ccci_head->data[0], p_ccci_head->data[1], p_ccci_head->channel, p_ccci_head->reserved);

    //4 <2> Submit to CCCI
    ccci_tx_ch = ccci_ims_inst.dev[ims_ch].ch_set.tx;
    ccci_ret = ccci_ims_inst.ccci_write_gpd(ccci_tx_ch, p_ior, NULL);
    if(CCCI_SUCCESS == ccci_ret){
        ret = KAL_TRUE;
    }else{
        ret = KAL_FALSE;
    }
     
    return ret;
}

/*************************************************************************
* FUNCTION
*  kal_uint32 ccci_ims_get_debug_status
*
* DESCRIPTION
*  Get CCCI ims debug status and write to the write_ptr
*
*
* PARAMETERS
*  write_ptr : the write address of CCCI debug status
*  available_size : the available size of CCCI debug status
* RETURNS
*  kal_uint32 : the used size of CCCI ims debug status
*
*************************************************************************/
kal_uint32 ccci_ims_get_debug_status(kal_uint32 *write_ptr, kal_uint32 available_size)
{
    // If the available size is not enough, return size 0 
    if(available_size < sizeof(CCCI_IMS_DEBUG_STATUS_T))
        return 0;
    
    kal_mem_cpy((void *)ccci_ims_debug_status.dev, (void *)ccci_ims_inst.dev, sizeof(ccci_ims_inst.dev) );

    kal_mem_cpy((void *)write_ptr, (void *)&ccci_ims_debug_status, sizeof(CCCI_IMS_DEBUG_STATUS_T));

    return sizeof(CCCI_IMS_DEBUG_STATUS_T);
}

kal_bool ccci_ims_svc_init (void)
{
    kal_uint32 idx;
    kal_int32  ccci_ret;

    ccci_ims_inst.dev[CCCI_IMS_CTRL].ch_set.tx    = CCCI_IMSC_DL;
    ccci_ims_inst.dev[CCCI_IMS_CTRL].ch_set.rx    = CCCI_IMSC_UL;
    ccci_ims_inst.dev[CCCI_IMS_VIDEO].ch_set.tx   = CCCI_IMSV_DL;
    ccci_ims_inst.dev[CCCI_IMS_VIDEO].ch_set.rx   = CCCI_IMSV_UL;
    ccci_ims_inst.dev[CCCI_IMS_AUD].ch_set.tx     = CCCI_IMSA_DL;
    ccci_ims_inst.dev[CCCI_IMS_AUD].ch_set.rx     = CCCI_IMSA_UL;
    ccci_ims_inst.dev[CCCI_IMS_DCTRL].ch_set.tx   = CCCI_IMSD_DL;
    ccci_ims_inst.dev[CCCI_IMS_DCTRL].ch_set.rx   = CCCI_IMSD_UL;
  
    ccci_ims_inst.ccci_init_gpdior = ccci_init_gpdior;
    ccci_ims_inst.ccci_write_gpd   = ccci_write_gpd;

    for(idx = 0; idx < CCCI_IMS_CH_MAX; idx++){
        ccci_ims_inst.dev[idx].state = IMS_DEV_INITIALIZED;
        ccci_ims_inst.dev[idx].ch_set.rx_cb = NULL;
        ccci_ret = ccci_ims_inst.ccci_init_gpdior(ccci_ims_inst.dev[idx].ch_set.rx, ccci_ims_ccci_ul_cb);
        ASSERT(CCCI_SUCCESS == ccci_ret);
        ccci_ret = ccci_ims_inst.ccci_init_gpdior(ccci_ims_inst.dev[idx].ch_set.tx, ccci_ims_dlcb_dummy);
        ASSERT(CCCI_SUCCESS == ccci_ret);
    }

    // register ccci debug get status cb funp
    ccci_debug_get_status_register(CCCI_DEBUG_GET_STATUS_MODULE_CCCIIMS, ccci_ims_get_debug_status);   
    
    ccci_ims_print(CCCI_IMS_TRACE, CCCI_IMS_MOD_INIT, "[CCCI_IMS]ccci_ims_svc_init");

#ifdef _CCCI_IMS_LB_IT_
    ims_lb_it_init();
#endif
    
    return KAL_TRUE;
}


void ccci_ims_print(kal_uint8 level, kal_uint32 mod, const char *fmt, ...)
{
    kal_uint8 string_buff[128];
    if (level >= CCCI_IMS_DBG_TH) {
        if (mod & CCCI_IMS_DBG_MSK) {
            va_list args;
            va_start(args, fmt);
            vsprintf((char *)(&string_buff[0]), fmt, args);
            tst_sys_trace((kal_char*)(&string_buff[0]));
        }
    }
    return;
}
