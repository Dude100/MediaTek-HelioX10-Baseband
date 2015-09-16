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
 *   ccci_ims_it.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   CCCI_IMS IT Mode 
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 05 30 2013 ap.wang
 * removed!
 * [CCCI_IMS] Add IMS_DCTRL channel
 *
 * 03 27 2013 ap.wang
 * removed!
 *
 * removed!
 * removed!
 * [CCCI] CCCI_IMS 1st verison loopback support
 ****************************************************************************/
#include "ccci_ims_if.h"
#include "ccci_ims_common.h"
#include "ccci_it_ctrl_if.h"
#ifdef _CCCI_IMS_LB_IT_

typedef enum{
  IMS_IT_NORMAL,
  IMS_IT_LB,
  IMS_IT_DL,
  IMS_IT_UL,
} IMS_IT_MODE;

typedef struct  {
   IMS_IT_MODE it_mode;
   kal_uint32  ims_ch; 
} CCCI_IMS_IT_INST_T;

CCCI_IMS_IT_INST_T g_ccci_ims_it_inst[CCCI_IMS_CH_MAX]= {
    {IMS_IT_LB, CCCI_IMS_CTRL  },
    {IMS_IT_LB, CCCI_IMS_VIDEO },    
    {IMS_IT_LB, CCCI_IMS_AUD   },
    {IMS_IT_LB, CCCI_IMS_DCTRL },  
}
;

void ims_it_ctrl_cb(kal_uint8 ims_ch, ccci_io_request_t *p_ior){
    if (g_ccci_ims_it_inst[CCCI_IMS_CTRL].it_mode ==  IMS_IT_LB){
        ccci_ims_dl_req(ims_ch, p_ior);
    }
    else{
        qbmt_dest_q(p_ior->first_gpd, p_ior->last_gpd);
    }
    return;
}

void ims_it_video_cb(kal_uint8 ims_ch, ccci_io_request_t *p_ior){
    if (g_ccci_ims_it_inst[CCCI_IMS_VIDEO].it_mode ==  IMS_IT_LB){
        ccci_ims_dl_req(ims_ch, p_ior);
    }
    else{
        qbmt_dest_q(p_ior->first_gpd, p_ior->last_gpd);
    }
    return;
}

void ims_it_audio_cb(kal_uint8 ims_ch, ccci_io_request_t *p_ior){
    if (g_ccci_ims_it_inst[CCCI_IMS_AUD].it_mode ==  IMS_IT_LB){
        ccci_ims_dl_req(ims_ch, p_ior);
    }
    else{
        qbmt_dest_q(p_ior->first_gpd, p_ior->last_gpd);
    }
    return;
}

void ims_it_dctrl_cb(kal_uint8 ims_ch, ccci_io_request_t *p_ior){
    if (g_ccci_ims_it_inst[CCCI_IMS_DCTRL].it_mode ==  IMS_IT_LB){
        ccci_ims_dl_req(ims_ch, p_ior);
    }
    else{
        qbmt_dest_q(p_ior->first_gpd, p_ior->last_gpd);
    }
    return;
}

#ifdef __CCCI_IT_CTRL__

kal_bool ccci_ims_it_normal(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    
    g_ccci_ims_it_inst[(kal_uint32)p_param].it_mode = IMS_IT_LB;
    
    return KAL_TRUE;
}

kal_bool ccci_ims_it_loopback(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    
    g_ccci_ims_it_inst[(kal_uint32)p_param].it_mode = IMS_IT_LB;

    return KAL_TRUE;
}

kal_bool ccci_ims_it_downlink(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    ccci_io_request_t ior = {NULL};
    g_ccci_ims_it_inst[(kal_uint32)p_param].it_mode = IMS_IT_UL;

    ior = ccci_it_gen_packet(QBM_TYPE_CCCI_COMM);
    if(ior.first_gpd != NULL){
        ccci_ims_dl_req((kal_uint32)p_param, &ior);
    }
    
    return KAL_TRUE;
}


kal_bool ccci_ims_it_uplink(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    
     g_ccci_ims_it_inst[(kal_uint32)p_param].it_mode = IMS_IT_UL;
    
    return KAL_TRUE;
}

IT_MODE_T ccci_ims_ctrl_it_mode_table1[] = {
    {"CCCI IMS CTRL Normal Mode",      ccci_ims_it_normal,         (void*)CCCI_IMS_CTRL},
    {"CCCI IMS CTRL Loopback Mode",    ccci_ims_it_loopback,       (void*)CCCI_IMS_CTRL},
    {"CCCI IMS CTRL Downlink Mode",    ccci_ims_it_downlink,       (void*)CCCI_IMS_CTRL,   1},   
    {"CCCI IMS CTRL Uplink Mode",      ccci_ims_it_uplink,         (void*)CCCI_IMS_CTRL}, 
};

IT_MODE_T ccci_ims_video_it_mode_table1[] = {
    {"CCCI IMS VIDEO Normal Mode",      ccci_ims_it_normal,         (void*)CCCI_IMS_VIDEO},
    {"CCCI IMS VIDEO Loopback Mode",    ccci_ims_it_loopback,       (void*)CCCI_IMS_VIDEO},
    {"CCCI IMS VIDEO Downlink Mode",    ccci_ims_it_downlink,       (void*)CCCI_IMS_VIDEO,   1},   
    {"CCCI IMS VIDEO Uplink Mode",      ccci_ims_it_uplink,         (void*)CCCI_IMS_VIDEO}, 
};

IT_MODE_T ccci_ims_aud_it_mode_table1[] = {
    {"CCCI IMS AUD Normal Mode",      ccci_ims_it_normal,         (void*)CCCI_IMS_AUD},
    {"CCCI IMS AUD Loopback Mode",    ccci_ims_it_loopback,       (void*)CCCI_IMS_AUD},
    {"CCCI IMS AUD Downlink Mode",    ccci_ims_it_downlink,       (void*)CCCI_IMS_AUD,   1},   
    {"CCCI IMS AUD Uplink Mode",      ccci_ims_it_uplink,         (void*)CCCI_IMS_AUD}, 
};

IT_MODE_T ccci_ims_dctrl_it_mode_table1[] = {
    {"CCCI IMS DCTRL Normal Mode",      ccci_ims_it_normal,         (void*)CCCI_IMS_DCTRL},
    {"CCCI IMS DCTRL Loopback Mode",    ccci_ims_it_loopback,       (void*)CCCI_IMS_DCTRL},
    {"CCCI IMS DCTRL Downlink Mode",    ccci_ims_it_downlink,       (void*)CCCI_IMS_DCTRL,   1},   
    {"CCCI IMS DCTRL Uplink Mode",      ccci_ims_it_uplink,         (void*)CCCI_IMS_DCTRL}, 
};

kal_bool ccci_ims_it_create(){
   
    ccci_it_mode_control_table_reg("CCCI_IMS_CTRL", 
                         ccci_ims_ctrl_it_mode_table1, 
                         sizeof(ccci_ims_ctrl_it_mode_table1) / sizeof(IT_MODE_T) 
                        );
    ccci_it_mode_control_table_reg("CCCI_IMS_VIDEO", 
                         ccci_ims_video_it_mode_table1, 
                         sizeof(ccci_ims_video_it_mode_table1) / sizeof(IT_MODE_T) 
                        );
    ccci_it_mode_control_table_reg("CCCI_IMS_AUD", 
                         ccci_ims_aud_it_mode_table1, 
                         sizeof(ccci_ims_aud_it_mode_table1) / sizeof(IT_MODE_T) 
                        );
    ccci_it_mode_control_table_reg("CCCI_IMS_DCTRL", 
                         ccci_ims_dctrl_it_mode_table1, 
                         sizeof(ccci_ims_dctrl_it_mode_table1) / sizeof(IT_MODE_T) 
                        );
    return KAL_TRUE;
}

#endif //__CCCI_IT_CTRL__


void ims_lb_it_init(void)
{
    ccci_ims_ulcb_reg(CCCI_IMS_CTRL,  ims_it_ctrl_cb);
    ccci_ims_ulcb_reg(CCCI_IMS_VIDEO, ims_it_video_cb);
    ccci_ims_ulcb_reg(CCCI_IMS_AUD,   ims_it_audio_cb);
    ccci_ims_ulcb_reg(CCCI_IMS_DCTRL, ims_it_dctrl_cb);
#ifdef __CCCI_IT_CTRL__
    ccci_ims_it_create();
#endif
}



#endif //_CCCI_IMS_LB_IT_
