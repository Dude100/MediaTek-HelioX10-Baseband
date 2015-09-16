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
 *   ccci_hmu.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Implements the CCCI initialize APIs (was through HMU in TATAKA)
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
 * [CCCI] Change the enum of init stage and fix CCCI IT load build fail
 *
 * removed!
 * removed!
 * [K2 MD2] Add CCCI/CCIF new feature for K2 MD2
 *
 * 04 22 2014 box.wu
 * removed!
 * ccif define
 *
 * removed!
 * removed!
 * [CCCI APIS] Limit CCCI polling IO using time
 *
 * removed!
 * removed!
 * 	fix build error if not define ccci_fs_support
 *
 * removed!
 * removed!
 * 	CCCI_FS compact read and profile trace (sdio)
 *
 * 01 06 2014 box.wu
 * removed!
 * CLDMA non-cacheable for E1 & adjust init sequence to hs2.
 *
 * 12 24 2013 box.wu
 * removed!
 * fix MdDIS error.
 *
 * 12 24 2013 box.wu
 * removed!
 * for SP to read NVRAM via CCCI FS first.
 *
 * removed!
 * removed!
 * [DEV Lock Patch] Requested by Ian [CCCI_HIF] CLDMA MoDIS support for 6595
 *
 * removed!
 * removed!
 * [CCCI] Add ICUSB feature.
 *
 * 11 26 2013 box.wu
 * removed!
 * add exception, tty, ICUSB.
 *
 * removed!
 * [MOLY] [CCCI LB IT] Add CCCI LB IT
 *
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * a. Check-in cccifs new features (support 16KB I/O)
 * b. add __CCCIFS_SUPPORT__ option to related files
 *
 * removed!
 * removed!
 *
 * 03 13 2013 box.wu
 * removed!
 * .add back ccci_hif_init()
 *
 * 03 12 2013 box.wu
 * removed!
 * 1. CCIF handshake with AP
 * 2. .integrate with TTYCore
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
 * [CCCI] CCCI_IMS 1st verison loopback support
 *
 * removed!
 * removed!
 * [ROUTER] fix link error when SDIO_SUPPORT  is not enabled
 *
 * removed!
 * removed!
 * sync latest version of new features
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#include "ccci_common.h"
#include "ccci_if.h"
#include "ccci_sdio.h"
#include "ccci_dev_if.h"
#include "ccci_ims_if.h"
#include "ccci_rpc_if.h"
#ifdef __HIF_SDIO_SUPPORT__
#include "sdiocore_if.h" //sdioc_init
#endif
#ifdef __HIF_CLDMA_SUPPORT__
#include "cldmacore_if.h" //cldmac_hifcldma_init
#endif
#ifdef __CCIFCORE_SUPPORT__
#include "ccifcore_if.h" //ccifc_hif_init
#endif


#if defined (__CCCI_PERF_PROFILING__) /* in ccci_if.h */
ccci_profile_dl_t   dl_prof[CCCI_PERF_REC_CNT];
kal_uint32          dl_prof_id;
ccci_profile_ul_t   ul_prof[CCCI_PERF_REC_CNT];
kal_uint32          ul_prof_id;
#endif

#if defined (__CCCI_LB_IT__) /* in hif_ccci.mak */
extern kal_bool ccci_it_init();
#endif
extern kal_bool ccci_lb_it_init();

static kal_uint32 ccci_inst_init(void){
#if defined (__CCCI_PERF_PROFILING__)
    dl_prof_id = 0;
    ul_prof_id = 0;
    kal_mem_set(&dl_prof, 0, sizeof(ccci_profile_dl_t)*CCCI_PERF_REC_CNT);
    kal_mem_set(&ul_prof, 0, sizeof(ccci_profile_ul_t)*CCCI_PERF_REC_CNT);
#endif

    ccci_trace(CCCI_TRACE, CCCI_MOD_HMU, CCCI_ISNT_INIT);
    kal_mem_set(&ccci_ctrl_pool, 0, CCCI_MAX_CHANNEL*sizeof(CCCI_CTRL_T)*CCCI_PEER_ID_MAX);
    
//#if defined (__HIF_SDIO_SUPPORT__)
//    ccci_init_handshake_phase1();
//    /* Please note that MT6290 only support Normal mode for now */
//    /* TODO: Meta Mode boot up flow */
//    ccci_init_handshake_phase2(CCCI_NORMAL_MODE);
//#endif

    ccci_hif_init();

#if defined (__CCCI_LB_IT__) /* in hif_ccci.mak */
    ccci_it_init();
#endif
	ccci_lb_it_init();

    ccci_debug_init();
    return 0;    
}


/*
 * ./driver/sys_drv/init/src/init.c
 * void Application_Initialize
 */
void lte_ccci_hw_init(void){
    set_ccci_boot_state(CCCI_HW_INIT);
#ifdef __HIF_SDIO_SUPPORT__
    sdioc_normal_init();
    sdioc_init();
#endif    

#if defined(__HIF_CLDMA_SUPPORT__) && defined(__MTK_TARGET__)
    cldmac_hifcldma_init();
#endif  

#if defined(__CCIFCORE_SUPPORT__) && defined(__MTK_TARGET__)
    ccifc_hif_init();
#endif

    ccci_inst_init();
    set_ccci_boot_state(CCCI_HW_INIT_DONE);
}
#if defined(__CCCIFS_SUPPORT__)  
extern void ccci_fs_test_init(void);
#endif
/*  ./driver/devdrv/common/src/devdrv_common.c
 *  void Drv_Init_Phase1(void)
 */
void lte_ccci_hal_init(void){
    set_ccci_boot_state(CCCI_HAL_INIT);

#if defined(__CCCIDEV_SUPPORT__)
 /*
  * 20121228 iwei
  * In CCCI or SDIOC atest environment, CCCIDEV is disabled.
  * As a result, we skip the fs initialization.
  */
#if defined(__CCCIFS_SUPPORT__)  
    ccci_fs_svc_init();
    ccci_fs_test_init();
#endif
    ccci_ims_svc_init();
    ccci_rpc_svc_init();
    ccci_sys_msg_svc_init();
#endif
    set_ccci_boot_state(CCCI_HAL_INIT_DONE);
    return;
}

/*
 * ./driver/sys_drv/init/src/init.c
 * void Application_Initialize
 */
void lte_ccci_hw_init_phase2(void){

#ifdef __HIF_SDIO_SUPPORT__
    sdioc_init_phase2();
#endif  
#if defined(__CCIFCORE_SUPPORT__) && defined(__MTK_TARGET__)
    ccifc_init_phase2();
#endif
#if defined(__HIF_CLDMA_SUPPORT__) && defined(__MTK_TARGET__)
    cldmac_init_phase2();
#endif

}
