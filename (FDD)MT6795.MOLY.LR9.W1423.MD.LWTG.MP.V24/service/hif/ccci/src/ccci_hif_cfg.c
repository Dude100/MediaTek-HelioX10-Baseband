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
 *   ccci_hif_cfg.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   ccci_hif_cfg.c defines the pre-defined transmissino HW callback function
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
 * [K2 MD2] Add CCCI/CCIF new feature for K2 MD2
 *
 * removed!
 * removed!
 * [CCCI] Add & Maintain UT code
 *
 * removed!
 * removed!
 * [CCCI] Change exception flow.
 *
 * removed!
 * removed!
 * [CCCI] CLDMA MoDIS support for 6595
 *
 * removed!
 * removed!
 * [DEV Lock Patch] Requested by Ian [CCCI_HIF] CLDMA MoDIS support for 6595
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	.
 *
 * 06 03 2013 box.wu
 * removed!
 * CCIFCore GPD support
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
 * [CCCI/CLDMA INT] 1. work around cldmacore initialization flow
 * 2. create CCCI DUMMY HIF interface for CCIF channels
 *
 * 01 28 2013 ap.wang
 * removed!
 * [CCCI] CCCI_IMS channel rename
 *
 * removed!
 * removed!
 * [ROUTER] fix link error when SDIO_SUPPORT  is not enabled
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#include "ccci_common.h"
#include "ccci_if.h"
#include "ccci_ut.h"
#ifdef __HIF_SDIO_SUPPORT__
#include "sdiocore_if.h"
#endif
#ifdef __HIF_CLDMA_SUPPORT__
#include "cldmacore_if.h"
#endif
#ifdef __CCIFCORE_SUPPORT__
#include "ccifcore_if.h"
#endif

/* static ccci_hw_apis ccci_null_apis = {NULL, NULL, NULL, NULL, NULL, NULL, CCCI_CH_HIFIO_MIN};*/

kal_bool dummy_submit_ior(kal_uint8 queue_type , kal_uint8 queue_no, void* ior)
{
    ccci_io_request_t* io_request = ior;
    /* this interface should not be used */
	if(NULL == io_request){ return KAL_FALSE; }
    ccci_trace(CCCI_ERR, CCCI_MOD_HIF, CCCI_TR_DUMMY_SIOR);
    qbmt_dest_q(io_request->first_gpd, io_request->last_gpd);
    return KAL_TRUE;
}
kal_bool dummy_q_attach(kal_uint8 queue_type, kal_uint8 queue_no, CCCI_CHANNEL_T channel, HIF_CCCI_GPD_CALLBACK funp)
{
    ccci_trace(CCCI_ERR, CCCI_MOD_HIF, CCCI_TR_DUMMY_QATT);
    return KAL_TRUE;
}
kal_bool dummy_q_detach(kal_uint8 queue_type, kal_uint8 queue_no, CCCI_CHANNEL_T channel)
{
    ccci_trace(CCCI_ERR, CCCI_MOD_HIF, CCCI_TR_DUMMY_QDEATT);
    return KAL_TRUE;
}
kal_bool dummy_polling_io(kal_uint8 queue_no, qbm_gpd *pgpd, kal_bool istx)
{
    ccci_trace(CCCI_ERR, CCCI_MOD_HIF, CCCI_TR_DUMMY_POLLING_IO);
    return KAL_TRUE;
}


static ccci_hif_expt_apis dummy_hif_expt_apis = {NULL, NULL, NULL, NULL, NULL, NULL};
static ccci_hw_apis ccci_dummy_apis = {
    dummy_submit_ior, 
    dummy_q_attach, 
    NULL,
    dummy_q_detach, 
    NULL, 
    dummy_polling_io, 
    CCCI_CH_HIFIO_GPD,
    /*===Exception Mode APIs===*/
    &dummy_hif_expt_apis
};

#ifdef __HIF_CLDMA_SUPPORT__
#if defined(__MTK_TARGET__)
static ccci_hif_expt_apis cldmac_expt_apis = {
    cldmac_except_init,
    NULL,
    cldmac_except_set_gpd,
    cldmac_except_poll_gpd,
    cldmac_except_hif_isr,
    cldmac_except_link_st
};


static ccci_hw_apis ccci_cldma_apis = {
    cldmac_submit_ior,
    cldmac_q_attach, 
    NULL,
    cldmac_q_detach, 
    NULL, 
    cldmac_polling_submit_one_gpd, 
    CCCI_CH_HIFIO_GPD,
    /*===Exception Mode APIs===*/
    &cldmac_expt_apis
};
#else
static ccci_hif_expt_apis cldmac_expt_apis = {NULL, NULL, NULL, NULL, NULL, NULL};
static ccci_hw_apis ccci_cldma_apis = {
    dummy_submit_ior, 
    dummy_q_attach, 
    NULL,
    dummy_q_detach, 
    NULL, 
    dummy_polling_io, 
    CCCI_CH_HIFIO_GPD,
    /*===Exception Mode APIs===*/
    &dummy_hif_expt_apis
};
#endif
#endif

#if defined(__CCIFCORE_SUPPORT__)
#if defined(__MTK_TARGET__)

static ccci_hif_expt_apis ccifc_expt_apis = {
    ccifc_except_init,
    NULL,
    ccifc_except_set_gpd,
    ccifc_except_poll_gpd,
    ccifc_except_hif_isr,
    ccifc_except_link_st
};


static ccci_hw_apis ccci_ccif_apis = {
    ccifc_submit_ior,
    ccifc_q_attach, 
    NULL,
    ccifc_q_detach, 
    NULL, 
    ccifc_polling_submit_one_gpd, 
    CCCI_CH_HIFIO_GPD,
    /*===Exception Mode APIs===*/
    &ccifc_expt_apis
};

#else
static ccci_hw_apis ccci_ccif_apis = {
    dummy_submit_ior,
    dummy_q_attach, 
    NULL,
    dummy_q_detach, 
    NULL, 
    NULL, 
    CCCI_CH_HIFIO_GPD,
    /*===Exception Mode APIs===*/
    &dummy_hif_expt_apis
};
#endif
#endif

#ifdef __HIF_SDIO_SUPPORT__
static ccci_hif_expt_apis sdioc_expt_apis = {
    sdioc_except_init,
    NULL,
    sdioc_except_set_gpd,
    sdioc_except_poll_gpd,
    sdioc_except_hif_isr,
    sdioc_except_link_st
};

static ccci_hw_apis ccci_sdio_apis = {
    sdioc_submit_ior,
    sdioc_q_attach, 
    NULL, 
    sdioc_q_detach, 
    NULL, 
    sdioc_polling_submit_one_gpd, 
    CCCI_CH_HIFIO_GPD,
    /*===Exception Mode APIs===*/
    &sdioc_expt_apis
};
#endif

static ccci_hw_apis ccci_hw_handle_apis[CCCI_TYPE_MAX];

void ccci_hif_init(void){
    kal_uint8 i;
    for(i = CCCI_TYPE_MIN; i<CCCI_TYPE_MAX; i++){	
        	ccci_hw_handle_apis[i] = ccci_dummy_apis;
    }
#ifdef __HIF_SDIO_SUPPORT__    
    ccci_hw_handle_apis[CCCI_TYPE_SDIO]  = ccci_sdio_apis;
#endif
#ifdef __HIF_CLDMA_SUPPORT__
    ccci_hw_handle_apis[CCCI_TYPE_CLDMA] = ccci_cldma_apis;
#endif
#if defined(__CCIFCORE_SUPPORT__)
	ccci_hw_handle_apis[CCCI_TYPE_CCIF_GPD_AP] = ccci_ccif_apis;
// TODO: Hook MD2 hw handle apis
	// ccci_hw_handle_apis[CCCI_TYPE_CCIF_GPD_MD] = ccci_ccif_apis;
#endif

#ifdef ATEST_SYS_CCCI
    ccci_hw_handle_apis[CCCI_TYPE_UT_GPD]  = ccci_ut_get_hif_apis(CCCI_TYPE_UT_GPD);
    ccci_hw_handle_apis[CCCI_TYPE_UT_BUFF] = ccci_ut_get_hif_apis(CCCI_TYPE_UT_BUFF);
#endif
}

ccci_hw_apis* ccci_get_hw_handle_api(CCCI_HIF_HW_TYPE_T hw_type){
    ASSERT(hw_type < CCCI_TYPE_MAX);
    ASSERT(hw_type != CCCI_TYPE_MIN);
    return &ccci_hw_handle_apis[hw_type];
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
