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
 *   ccmni_hmu.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Implements the CCCI CCMNI initialize/De-Initialize flow
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 08 15 2014 ap.wang
 * removed!
 * [CCMNI] Add CCMNI sw tput throttling support for ipc_attach
 *
 * removed!
 * removed!
 * [CCMNI] init ipc_attach config
 *
 * 02 05 2013 ap.wang
 * removed!
 *
 * 01 11 2013 ap.wang
 * removed!
 * [CCCI_IT_CTRL] CCCI_IT_CTRL 1st version.
 *
 * removed!
 * removed!
 * sync latest version of new features
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#include "ccmni_common.h"
#include "ccmni_debug.h"
#include "ccmni_sm.h"
#include "ccmni_if.h"


/*!
 * @function        ccmni_dev_main_init
 * @brief           attach the device to ipcore and send ilm to do device resource init
 *
 * @param dev_mapping     [IN] CCMNI device ID
 *
 * @return          KAL_TRUE
 */
kal_int32 ccmni_dev_main_init(kal_uint32 dev_mapping)
{
    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    ccmni_init_req_t    *hmu_init_req;
    ipc_conf_t          config;
    kal_int32           ret;
    ccmni_device_t      *pdev;

    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_HMU, CCMNI_TR_HMU_INIT, dev_mapping);
    ASSERT(dev_mapping < CCMNI_DEV_CNT);    

    pdev = &p_ccmni->dev[dev_mapping];
    ASSERT(pdev->dev_id == dev_mapping);

    //4 <1> ipc_attach,   ASSERT if fail, refer to ethc_device_attach
    /* attach IP Core */
    kal_mem_set(&config, 0, sizeof(config));
    config.module_id = MOD_CCMNI;
    config.netif_id = pdev->dev_id;
    /* context provide the rgpd_reload_callback */
    config.ul_reload_context = pdev;                        /* e.g.  rndis_dev_g */
    config.ipc_ul_reload_callback_t = ccmni_reload_ul_gpds; /* e.g.  rndis_reload_ul_buffers */
    /* context provide the tx_submit  */
    config.callback_context = pdev;                         /* e.g.  gEthCore.device[i]*/
    config.ipc_dlink_callback_t = ccmni_ipc_dl;             /* e.g.  ethc_ipc_tx_submit */
    if (!pdev->sw_tput_throttling_support){
        config.features |= IPC_F_LATENCY_CONCERN;
    }

    ret = p_ccmni->ipc_attach(&config, &pdev->ipc_handle);
    if (KAL_FALSE == ret)
    {
        ccmni_trace(CCMNI_ERR, CCMNI_MOD_HMU, CCMNI_TR_SESSION_INIT_FATAL_ERROR, pdev->dev_id, ret); ASSERT(0); return KAL_FALSE;
    }

    //4 <2> send ilm to do ccci_init and reload RGPDs
    hmu_init_req = (ccmni_init_req_t *)construct_local_para(sizeof(ccmni_init_req_t), 0);
    hmu_init_req->dev_indx = dev_mapping;
    msg_send6(MOD_CCMNI,                                /* src_mod_id */
              MOD_CCMNI,                                /* dest_mod_id */
              0,                                        /* sap_id */
              MSG_ID_CCMNI_SESSION_INIT_REQ,            /* msg_id */
              (struct local_para_struct *)hmu_init_req, /* local_para_ptr */
              NULL);                                    /* peer_buff_ptr */

    return KAL_TRUE;
}

/*!
 * @function        ccmni_dev_deinit
 * @brief           send ilm to do resource deinit
 *
 * @param dev_mapping     [IN] CCMNI device ID
 *
 * @return          KAL_TRUE
 */
kal_int32 ccmni_dev_deinit(kal_uint32 dev_mapping)
{
    ccmni_init_req_t    *hmu_init_req;

    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_HMU, CCMNI_TR_HMU_DEINIT, dev_mapping);
    hmu_init_req = (ccmni_init_req_t *)construct_local_para(sizeof(ccmni_init_req_t), 0);
    hmu_init_req->dev_indx = dev_mapping;
    msg_send6(MOD_CCMNI,                                /* src_mod_id */
              MOD_CCMNI,                                /* dest_mod_id */
              0,                                        /* sap_id */
              MSG_ID_CCMNI_SESSION_DEINIT_REQ,          /* msg_id */
              (struct local_para_struct *)hmu_init_req, /* local_para_ptr */
              NULL);  

    return KAL_TRUE;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__CCMNI_LB_IT__)
/* under construction !*/
#endif
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
/* under construction !*/
#endif
