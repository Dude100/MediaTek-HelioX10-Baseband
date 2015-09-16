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
 *   Implements the CCCI CCMNI UT functions
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
 * [CCCI] Change the enum of init stage and fix CCCI IT load build fail
 *
 * removed!
 * removed!
 * Rename project name as MT6290
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
#include "ipc_api.h"
#include "ccmni_sm.h"
#include "ccmni_qbm.h"
#include "ccmni_if.h"
#include "ccmni_data.h"
#include "qmu_bm.h"
#include "qbm_config_num.h"
#if defined(ATEST_SYS_CCCI_CCMNI)
#include "sys_test.h"
#endif

#if (defined(__CCMNI_UT__) || defined(__CCCI_LB_IT__) || defined(__CCMNI_IT__))
//#endif

//#if defined(__CCMNI_UT__)
#define CMNII_UT_TIMEOUT_WAIT_LIMIT   500
#define MIN(_a, _b) (((_a) <= (_b)) ? (_a) : (_b))

#define CCMNI_UT_DL_GPD_TYPE QBM_TYPE_HIF_DL
#define CCMNI_UT_UL_GPD_TYPE QBM_TYPE_HIF_UL_TYPE


kal_bool ccmni_ut_linkup(ccmni_device_t* dev)
{

    ipc_link_req_t      *link_req;

    //4  <1> linkup CCMNI_DEV_CCMNIn 
    link_req = (ipc_link_req_t *)construct_local_para(sizeof(ipc_link_req_t), 0);
    link_req->callback_context = (void *) dev;

#ifdef __IPCORE_SUPPORT__
    msg_send6(MOD_IPCORE,                           /* src_mod_id */
              MOD_CCMNI,                            /* dest_mod_id */
              0,                                    /* sap_id */
              MSG_ID_IPCORE_LINK_UP_REQ,            /* msg_id */
              (struct local_para_struct *)link_req, /* local_para_ptr */
              NULL);                                /* peer_buff_ptr */
#else
    msg_send6(MOD_CCMNI,                            /* src_mod_id */
              MOD_CCMNI,                            /* dest_mod_id */
              0,                                    /* sap_id */
              MSG_ID_CCMNI_LINK_UP_REQ,             /* msg_id replace MSG_ID_IPCORE_LINK_UP_REQ*/
              (struct local_para_struct *)link_req, /* local_para_ptr */
              NULL);                                /* peer_buff_ptr */
#endif    
    return KAL_TRUE;
}

kal_bool ccmni_ut_linkdown(ccmni_device_t* dev)
{

    ipc_link_req_t      *link_req;

    //4  <1> linkdown CCMNI_DEV_CCMNIn 
    link_req = (ipc_link_req_t *)construct_local_para(sizeof(ipc_link_req_t), 0);
    link_req->callback_context = (void *) dev;

#ifdef __IPCORE_SUPPORT__
    msg_send6(MOD_IPCORE, /* src_mod_id */
              MOD_CCMNI, /* dest_mod_id */
              0, /* sap_id */
              MSG_ID_IPCORE_LINK_DOWN_REQ, /* msg_id replace MSG_ID_IPCORE_LINK_DOWN_REQ*/
              (struct local_para_struct *)link_req, /* local_para_ptr */
              NULL); /* peer_buff_ptr */
#else
    msg_send6(MOD_CCMNI, /* src_mod_id */
              MOD_CCMNI, /* dest_mod_id */
              0, /* sap_id */
              MSG_ID_CCMNI_LINK_DOWN_REQ, /* msg_id replace MSG_ID_IPCORE_LINK_DOWN_REQ*/
              (struct local_para_struct *)link_req, /* local_para_ptr */
              NULL); /* peer_buff_ptr */
#endif
    return KAL_TRUE;
}

kal_bool ccmni_dummy(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
        return KAL_TRUE;
}

/**
 *@Function        [UT] ccmni_ut_link_state
 *@Criteria
 *    1. CCMNI devices can handle IPC_LINK_UP_REQ and IPC_LINK_DOWN_REQ correctly and successfully
 *@Scenario
 *    1. After ccmni_hmu_init, the dev state is CCMNI_DEV_CONNECTED for UT case
 *    2. Send LINK_DOWN_REQ to CCMNI1~3
 *    3. Expect the state = CCMNI_DEV_DISCONNECTED  for CCMNI1~3
 *    4. Send LINK_UP_REQ to CCMNI1~3
 *    5. Expect the state = CCMNI_DEV_CONNECTED  for CCMNI1~3
 *@Expect result
 *    1. After receiving the LINK_DOWN_REQ, the CCMNI device state == CCMNI_DEV_DISCONNECTED
 *    2. After receiving the LINK_UP_REQ, the CCMNI device state == CCMNI_DEV_CONNECTED
 *@Steps
 *    1. Define the ATEST_SYS_CCCI_CCMNI in atest_sys.mak
 *    2. Define LTM_SIMULATION_SUPPORT = FALSE
 *    3. Rebuild and execute the MoDIS.exe
 *    4. After the success test, "[CCMNII_UT] ccmni_ut_link_state PASS" will be printed in the console    
 */
kal_bool ccmni_ut_link_state(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    kal_char            error_string[256];
    kal_uint32          dev_id, retry_num = 0;
    kal_uint32          test_step = 0;
    

    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_TRACE, __LINE__); 
    //4 <1> After ccmni_hmu_init, the dev state is CCMNI_DEV_CONNECTED for UT case

    //4 <2> Send LINK_DOWN_REQ to CCMNI1~3
    test_step = 2;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step); 
    for(dev_id = 0; dev_id < 3; dev_id++){
        ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_TR_LINK_DOWN_REQ, dev_id);
        ccmni_ut_linkdown(&p_ccmni->dev[dev_id]);
    }

    //4 <3> Expect the state = CCMNI_DEV_DISCONNECTED  for CCMNI1~3
    test_step = 3;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step);
    while(p_ccmni->dev[0].state != CCMNI_DEV_DISCONNECTED ||\
          p_ccmni->dev[1].state != CCMNI_DEV_DISCONNECTED ||\
          p_ccmni->dev[2].state != CCMNI_DEV_DISCONNECTED    )
    {

        retry_num++;
        if(retry_num>CMNII_UT_TIMEOUT_WAIT_LIMIT)
        {
            sprintf(error_string, "%s%s%d %s state_CCMNI[0]=%d state_CCMNI[1]=%d state_CCMNI[2]=%d\n",
            "[CCMNI_UT] ccmni_ut_link_state",
            "CCCI_CCMNI cannot finish the LINKDOWN_REQ process in:",
            retry_num*10, //KAL_TICKS_10_MSEC
            "ms",
            p_ccmni->dev[0].state,
            p_ccmni->dev[1].state,
            p_ccmni->dev[2].state);
			strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto ccmni_ut_link_state_err_out;
        }
        kal_sleep_task(KAL_TICKS_10_MSEC);
    }

    //4 <4> Send LINK_UP_REQ to CCMNI1~3
    test_step = 4;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step);
    for(dev_id = 0; dev_id < 3; dev_id++){
        ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_TR_LINK_UP_REQ, dev_id);
        ccmni_ut_linkup(&p_ccmni->dev[dev_id]);
    }

    //4 <5> Expect the state = CCMNI_DEV_CONNECTED  for CCMNI1~3
    test_step = 5;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step);
    while(p_ccmni->dev[0].state != CCMNI_DEV_CONNECTED ||\
          p_ccmni->dev[1].state != CCMNI_DEV_CONNECTED ||\
          p_ccmni->dev[2].state != CCMNI_DEV_CONNECTED    )
    {

        retry_num++;
        if(retry_num>CMNII_UT_TIMEOUT_WAIT_LIMIT)
        {
            sprintf(error_string, "%s%s%d %s state_CCMNI[0]=%d state_CCMNI[1]=%d state_CCMNI[2]=%d\n",
            "[CCMNI_UT] ccmni_ut_link_state",
            "CCCI_CCMNI cannot finish the LINKUP_REQ process in:",
            retry_num*10, //KAL_TICKS_10_MSEC
            "ms",
            p_ccmni->dev[0].state,
            p_ccmni->dev[1].state,
            p_ccmni->dev[2].state);
			strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto ccmni_ut_link_state_err_out;
        }
        kal_sleep_task(KAL_TICKS_10_MSEC);
    }

    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_PASS_TRACE, __LINE__);
    return KAL_TRUE;
    
ccmni_ut_link_state_err_out:
    ccmni_trace(CCMNI_ERR, CCMNI_MOD_UT, CCMNI_UT_ERR, __LINE__);
    return KAL_FALSE;    
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
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
kal_bool ccmni_ut_init_test(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){

    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    kal_char            error_string[256];
    kal_uint32          dev_id, retry_num = 0;
    kal_uint32          test_step = 0;

    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_TRACE, __LINE__); 
    //4 <1> While CCCI_UT is enabled, the ccmni_hmu_init and LINK_UP_REQ is executed b4 the test case. Thus the state of CCMNIx is CCMNI_DEV_CONNECTED
    
    //4 <2> Execute ccmni_hmu_deinit for CCMNI1~3 
    test_step = 2;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step); 
    for(dev_id = 0; dev_id < 3; dev_id++){
        ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_TR_HMU_DEINIT, dev_id);
        ASSERT(p_ccmni->dev[dev_id].dev_id == dev_id);
        ccmni_dev_deinit(dev_id);
    }
    //4 <3> Expect the state = CCMNI_DEV_UNINITIALIZED
    test_step = 3;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step); 
    
    while(p_ccmni->dev[0].state != CCMNI_DEV_UNINITIALIZED ||\
          p_ccmni->dev[1].state != CCMNI_DEV_UNINITIALIZED ||\
          p_ccmni->dev[2].state != CCMNI_DEV_UNINITIALIZED    )
    {

        retry_num++;
        if(retry_num>CMNII_UT_TIMEOUT_WAIT_LIMIT)
        {
            sprintf(error_string, "%s%s%d %s state_CCMNI[0]=%d state_CCMNI[1]=%d state_CCMNI[2]=%d\n",
            "[CCMNI_UT] ccmni_ut_init_test",
            "CCCI_CCMNI cannot finish the deinit process in:",
            retry_num*10, //KAL_TICKS_10_MSEC
            "ms",
            p_ccmni->dev[0].state,
            p_ccmni->dev[1].state,
            p_ccmni->dev[2].state);
			strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto ccmni_ut_de_init_err_out;
        }
        kal_sleep_task(KAL_TICKS_10_MSEC);
    }

    //4 <4> Execute ccmni_hmu_init for CCMNI1~3
    test_step = 4;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step); 
    for(dev_id = 0; dev_id < 3; dev_id++){
        ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_TR_HMU_INIT, dev_id);
        ASSERT(p_ccmni->dev[dev_id].dev_id == dev_id);
        ccmni_dev_main_init(dev_id);
    }

    //4 <5> Expect the state = CCMNI_DEV_CONNECTED, since LINK_UP_REQ will be sent during initialization
    test_step = 5;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step); 
    while(p_ccmni->dev[0].state != CCMNI_DEV_CONNECTED ||\
          p_ccmni->dev[1].state != CCMNI_DEV_CONNECTED ||\
          p_ccmni->dev[2].state != CCMNI_DEV_CONNECTED    )
    {

        retry_num++;
        if(retry_num>CMNII_UT_TIMEOUT_WAIT_LIMIT)
        {
            sprintf(error_string, "%s%s%d %s state_CCMNI[0]=%d state_CCMNI[1]=%d state_CCMNI[2]=%d\n",
            "[CCMNI_UT] ccmni_ut_init_test",
            "CCCI_CCMNI cannot finish the init process in:",
            retry_num*10, //KAL_TICKS_10_MSEC
            "ms",
            p_ccmni->dev[0].state,
            p_ccmni->dev[1].state,
            p_ccmni->dev[2].state);
			strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto ccmni_ut_de_init_err_out;
        }
        kal_sleep_task(KAL_TICKS_10_MSEC);
    }

    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_PASS_TRACE, __LINE__); 
    return KAL_TRUE;
ccmni_ut_de_init_err_out:
    ccmni_trace(CCMNI_ERR, CCMNI_MOD_UT, CCMNI_UT_ERR, __LINE__);
    return KAL_FALSE;
}
static void ccmni_ut_dest_ior(ccci_io_request_t *ior){
    ccci_io_request_t   *next_ior;
    qbm_gpd*            current_gpd;

    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_TRACE, __LINE__); 
    ASSERT(ior);
    for (; ior; ior = next_ior) {
        next_ior = ior->next_request;
        ASSERT(ior->first_gpd);

        /*  fix the last_gpd == NULL case */
        if (ior->last_gpd == NULL)
        {
            current_gpd = ior->first_gpd;
            while ( current_gpd->p_next != NULL )
            {
                current_gpd = current_gpd->p_next;
            }
            ior->last_gpd = current_gpd;
        }
        
        if ( ior->first_gpd && ior->last_gpd ) {
            qbmt_dest_q(ior->first_gpd, ior->last_gpd);
        }else{
            /*Does NOT accept ior with first_gpd or last_gpd == NULL*/
            ASSERT(0);
        }
    }
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_PASS_TRACE, __LINE__); 
}
static kal_int32 ccmni_ut_ccci_write_gpd(CCCI_CHANNEL_T channel, ccci_io_request_t *p_ccci_DL_ior, ccci_io_ext_info_t* pextinfo){
    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    CCCI_BUFF_T         *p_ccci_head;
    qbm_gpd             *current_gpd;
    kal_uint32          ret = CCCI_SUCCESS;
    CCCI_CHANNEL_T      hdr_ch, ccmni1_ch;

    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_TRACE, __LINE__); 
    ccmni1_ch = p_ccmni->dev[0].ccci_ch.ccmni_ch_dl;
    current_gpd = p_ccci_DL_ior->first_gpd;
    do {
        p_ccci_head   = (CCCI_BUFF_T *)CCMNI_GET_QBM_DATAPTR(current_gpd);
        hdr_ch = CCCI_GET_CH_NO(p_ccci_head);
        if(hdr_ch != ccmni1_ch){
            ret = CCCI_FAIL;
            break;
        }

        if ( current_gpd == p_ccci_DL_ior->last_gpd )
        {
            break;
        }
        current_gpd = QBM_DES_GET_NEXT(current_gpd);
    } while ( current_gpd != NULL );
    //qbmt_dest_q(p_ccci_DL_ior->first_gpd, p_ccci_DL_ior->last_gpd);

    QBM_DES_SET_NEXT(p_ccci_DL_ior->last_gpd, NULL);
    p_ccci_DL_ior->last_gpd = NULL;
    ccmni_ut_dest_ior(p_ccci_DL_ior);

    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_PASS_TRACE, __LINE__); 
    return ret;
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
#endif
kal_bool ccmni_ut_downlink(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){

    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    kal_char            error_string[256];
    ccmni_device_t      *pCCMNI1 = &(p_ccmni->dev[0]);
    ccmni_device_t      *pCCMNI2 = &(p_ccmni->dev[1]);
    ipc_io_request_t    ior;
    kal_uint32          to_alloc = 5;
    kal_uint32          num_alloc = 0;
    kal_bool            ret;
    kal_uint32          idx;
    kal_uint32          test_step = 0;
    
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_TRACE, __LINE__); 
    ior.next_request = NULL;
   
    //4 <1> Send NULL ior, expect well error handling no crash
    test_step = 1;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step); 
    ret = ccmni_ipc_dl(pCCMNI1, NULL);
    if(KAL_FALSE!=ret){
        sprintf(error_string, "%s%s \n",
        "[CCMNI_UT] ccmni_ut_downlink",
        "ccmni_ipc_dl return KAL_TRUE while ior == NULL \r\n");
        strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
        goto ccmni_ut_downlink_err_out;
    }
    
    //4 <2> Send NULL context, expect well error handling no crash
    test_step = 2;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step);
    ret = ccmni_ipc_dl(NULL, &ior);
    if(KAL_FALSE!=ret){
        sprintf(error_string, "%s%s \n",
        "[CCMNI_UT] ccmni_ut_downlink",
        "ccmni_ipc_dl return KAL_TRUE while context == NULL \r\n");
        strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
        goto ccmni_ut_downlink_err_out;
    }
    
    //4 <3> Disconnect the device and sent the valid ior list, expect ccmni_ipc_dl will free the ior/gpd/bd/buff
    test_step = 3;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step);
    pCCMNI1->state = CCMNI_DEV_DISCONNECTED;
    for(idx = 1024; idx !=0; idx--){
        num_alloc = qbmt_alloc_q_no_tail(
                        CCMNI_UT_DL_GPD_TYPE,      /* type */
                        to_alloc,                  /* buff_num */
                        (void **)(&ior.first_gpd), /* pp_head */
                        (void **)(&ior.last_gpd)); /* pp_tail */
        if(to_alloc != num_alloc) {ASSERT(0);}
        QBM_DES_SET_NEXT(ior.last_gpd, NULL);
        ior.last_gpd = NULL;
        ret = ccmni_ipc_dl(pCCMNI1, &ior);
        if(KAL_TRUE!=ret){
            sprintf(error_string, "%s%s \n",
            "[CCMNI_UT] ccmni_ut_downlink",
            "ccmni_ipc_dl(pCCMNI1, ior); return KAL_FALSE \r\n");
            strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto ccmni_ut_downlink_err_out;
        }

    }
    pCCMNI1->state = CCMNI_DEV_CONNECTED;

    test_step = 4;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step);
    //4 <4-1> Connect the device again
    pCCMNI1->state = CCMNI_DEV_CONNECTED;
    
    //4 <4-2> Set the p_ccmni->ccci_write_gpd as ccmmni_ut_ccci_write_gpd, which return KAL_TRUE if (ch == CCMNI1)
    p_ccmni->ccci_write_gpd = ccmni_ut_ccci_write_gpd;

    //4 <4-3> Send valid ior with CCMNI1, expect ccmni_ipc_dl returning KAL_TRUE
    num_alloc = qbmt_alloc_q_no_tail(
                    CCMNI_UT_DL_GPD_TYPE,      /* type */
                    to_alloc,                  /* buff_num */
                    (void **)(&ior.first_gpd), /* pp_head */
                    (void **)(&ior.last_gpd)); /* pp_tail */
    if(to_alloc != num_alloc) {ASSERT(0);}
    QBM_DES_SET_NEXT(ior.last_gpd, NULL);
    ior.last_gpd = NULL;
    ret = ccmni_ipc_dl(pCCMNI1, &ior);
    if(KAL_TRUE!=ret){
            sprintf(error_string, "%s%s \n",
            "[CCMNI_UT] ccmni_ut_downlink step 4-3",
            "ccmni_ipc_dl(pCCMNI1, ior); return KAL_FALSE \r\n");
            strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto ccmni_ut_downlink_err_out;
    }
    
    //4 <4-4> Send valid ior with CCMNI2, expect ccmni_ipc_dl returning KAL_FALSE
    num_alloc = qbmt_alloc_q_no_tail(
                    CCMNI_UT_DL_GPD_TYPE,      /* type */
                    to_alloc,                  /* buff_num */
                    (void **)(&ior.first_gpd), /* pp_head */
                    (void **)(&ior.last_gpd)); /* pp_tail */
    if(to_alloc != num_alloc) {ASSERT(0);}
    ret = ccmni_ipc_dl(pCCMNI2, &ior);
    if(KAL_FALSE!=ret){
            sprintf(error_string, "%s%s \n",
            "[CCMNI_UT] ccmni_ut_downlink step 4-4",
            "ccmni_ipc_dl(pCCMNI2, ior); return KAL_TRUE \r\n");
            strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
            goto ccmni_ut_downlink_err_out;
    }
    //4 <4-5> Restore the p_ccmni->ccci_write_gpd as ccci_write_gpd for next ut test
    p_ccmni->ccci_write_gpd = ccci_write_gpd;

    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_PASS_TRACE, __LINE__); 
    return KAL_TRUE;

ccmni_ut_downlink_err_out:
    ccmni_trace(CCMNI_ERR, CCMNI_MOD_UT, CCMNI_UT_ERR, __LINE__); 
    return KAL_FALSE;
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
#endif
#define CCMNI_UT_MAGIC  0xFF55FF55
static kal_bool ccmni_ut_ipc_uplink_CCMNI3(
    ipc_handle_t            handle,
    ipc_io_request_t       *ior)
{
    qbm_gpd             *current_gpd = ior->first_gpd;
//    kal_bool            ret;
    kal_uint32          *p_data;

    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_TRACE, __LINE__);
    do {
        p_data   = (kal_uint32 *)CCMNI_GET_QBM_DATAPTR(current_gpd);

        if(*p_data != CCMNI_UT_MAGIC){
            ASSERT(0);
//            ret = KAL_FALSE;
            break;
        }

        if ( current_gpd == ior->last_gpd )
        {
            break;
        }
        current_gpd = QBM_DES_GET_NEXT(current_gpd);
    } while ( current_gpd != NULL );
    ccmni_ut_dest_ior((ccci_io_request_t *)ior);
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_PASS_TRACE, __LINE__);
    return KAL_TRUE;
}
static void ccmni_ut_uplink_format_gpds(CCCI_CHANNEL_T ch, qbm_gpd *head_gpd, qbm_gpd *tail_gpd){
    qbm_gpd             *curr_gpd, *next_gpd;
    kal_bool            end_of_list = KAL_FALSE;
    CCCI_BUFF_T         *p_ccci_head;
    kal_char            *p_data;

    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_TRACE, __LINE__);
    for (curr_gpd = head_gpd; curr_gpd && !end_of_list; curr_gpd = next_gpd) {
        next_gpd = QBM_DES_GET_NEXT(curr_gpd);
        end_of_list = (curr_gpd == tail_gpd);
        
        CCMNI_PUSH_QBM_DATAHEAD(curr_gpd, sizeof(CCCI_BUFF_T));
        p_ccci_head   = (CCCI_BUFF_T *)CCMNI_GET_QBM_DATAPTR(curr_gpd);
        /*Construct the CCCI header*/
        CCCI_SET_CH_NO(p_ccci_head, ch);
        p_data = (kal_char *)p_ccci_head + sizeof(CCCI_BUFF_T);
        *(kal_uint32 *)p_data = CCMNI_UT_MAGIC;
        
        CCCI_STREAM_SET_LEN(p_ccci_head, CCMNI_GET_QBM_DATALEN(curr_gpd)+sizeof(CCMNI_UT_MAGIC));
        QBM_CACHE_FLUSH(p_ccci_head, 2*sizeof(CCCI_BUFF_T));

        curr_gpd = QBM_DES_GET_NEXT(curr_gpd);
    }
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_PASS_TRACE, __LINE__);
}
kal_bool ccmni_ut_uplink(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){

//    kal_char            error_string[256];
    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    ccmni_device_t      *pCCMNI3 = &(p_ccmni->dev[0]);
    ipc_io_request_t    ior;
    kal_uint32          to_alloc = 5;
    kal_uint32          num_alloc = 0;
    kal_uint32          idx = 0;
    qbm_gpd             *target_gpd;
    kal_uint32          mask;
    kal_uint32          test_step = 0;
    ccmni_ulq_t         *pulq;
    kal_bool            is_dlack = KAL_FALSE;

    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_PASS_TRACE, __LINE__);
    
    ior.next_request = NULL;
    //4 ccmni_ccci_ul_cb
    test_step = 1;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step);
    //4 <1> Set p_ccmni->ipc_uplink = ccmni_ut_ipc_uplink_CCMNI3
    p_ccmni->ipc_uplink = ccmni_ut_ipc_uplink_CCMNI3;

    is_dlack = ccmni_is_dlack_ch(pCCMNI3->ccci_ch.ccmni_ch_ul);
    if(KAL_TRUE == is_dlack){
        pulq = &p_ccmni->ulq[pCCMNI3->ulq.ccmni_ack_ulq];
    }else{
        pulq = &p_ccmni->ulq[pCCMNI3->ulq.ccmni_normal_ulq];
    }
    //4 <2> Send uplink to ccmni_ccci_ul_cb(ch, ...), with valid data, i.e. ch = (*CCCI_BUFF_T) -> channel
    for(idx = 1024; idx !=0; idx--){
        num_alloc = qbmt_alloc_q_no_tail(
                    CCMNI_UT_UL_GPD_TYPE,      /* type */
                    to_alloc,                  /* buff_num */
                    (void **)(&ior.first_gpd), /* pp_head */
                    (void **)(&ior.last_gpd)); /* pp_tail */
        if(to_alloc != num_alloc) {ASSERT(0);}
        CCMNI_DEV_LOCK(mask);
        pulq->hwo_rgpd_cnt += num_alloc;
        CCMNI_DEV_UNLOCK(mask);
        ccmni_ut_uplink_format_gpds(pCCMNI3->ccci_ch.ccmni_ch_ul, ior.first_gpd, ior.last_gpd);
        ccmni_ccci_ul_cb(pCCMNI3->ccci_ch.ccmni_ch_ul, (ccci_io_request_t*)&ior);
    }
    //4 <3> Send uplink to ccmni_ccci_ul_cb(ch, ...), with NULL ior
    ccmni_ccci_ul_cb(pCCMNI3->dev_id, NULL);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    //4 <4-1> Send uplink with NOT valid data, channel not match. IOR has only one GPD.
    test_step = 2;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step);
    to_alloc = 1;
    for(idx = 1024; idx !=0; idx--){
        num_alloc = qbmt_alloc_q_no_tail(
                    CCMNI_UT_UL_GPD_TYPE,      /* type */
                    to_alloc,                  /* buff_num */
                    (void **)(&ior.first_gpd), /* pp_head */
                    (void **)(&ior.last_gpd)); /* pp_tail */
        if(to_alloc != num_alloc) {ASSERT(0);}
        CCMNI_DEV_LOCK(mask);
        pulq->hwo_rgpd_cnt += num_alloc;
        CCMNI_DEV_UNLOCK(mask);        
        ccmni_ut_uplink_format_gpds(pCCMNI3->ccci_ch.ccmni_ch_ul+1, ior.first_gpd, ior.last_gpd);
        ccmni_ccci_ul_cb(pCCMNI3->ccci_ch.ccmni_ch_ul, (ccci_io_request_t*)&ior);
    }
    
    //4 <4-2> Send uplink with NOT valid data, channel not match. IOR has 5 GPDs, and the 1~4 GPDs are invalid.
    test_step = 3;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step);
    to_alloc = 5;
    for(idx = 1024; idx !=0; idx--){
        num_alloc = qbmt_alloc_q_no_tail(
                    CCMNI_UT_UL_GPD_TYPE,      /* type */
                    to_alloc,                  /* buff_num */
                    (void **)(&ior.first_gpd), /* pp_head */
                    (void **)(&ior.last_gpd)); /* pp_tail */
        if(to_alloc != num_alloc) {ASSERT(0);}
        CCMNI_DEV_LOCK(mask);
        pulq->hwo_rgpd_cnt += num_alloc;
        CCMNI_DEV_UNLOCK(mask);
        target_gpd = ior.first_gpd;
        ccmni_ut_uplink_format_gpds(pCCMNI3->ccci_ch.ccmni_ch_ul+1, target_gpd, target_gpd);
        target_gpd = QBM_DES_GET_NEXT(target_gpd);
        ccmni_ut_uplink_format_gpds(pCCMNI3->ccci_ch.ccmni_ch_ul+1, target_gpd, target_gpd);
        target_gpd = QBM_DES_GET_NEXT(target_gpd);
        ccmni_ut_uplink_format_gpds(pCCMNI3->ccci_ch.ccmni_ch_ul+1, target_gpd, target_gpd);
        target_gpd = QBM_DES_GET_NEXT(target_gpd);
        ccmni_ut_uplink_format_gpds(pCCMNI3->ccci_ch.ccmni_ch_ul+1, target_gpd, target_gpd);
        ccmni_ut_uplink_format_gpds(pCCMNI3->ccci_ch.ccmni_ch_ul, ior.last_gpd, ior.last_gpd);
        ccmni_ccci_ul_cb(pCCMNI3->ccci_ch.ccmni_ch_ul, (ccci_io_request_t*)&ior);
    }
    
    //4 <4-3> Send uplink with NOT valid data, channel not match. IOR has 5 GPDs, and the 3rd GPDs are invalid.
    test_step = 4;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step);
    to_alloc = 5;
    for(idx = 1024; idx !=0; idx--){
        num_alloc = qbmt_alloc_q_no_tail(
                    CCMNI_UT_UL_GPD_TYPE,      /* type */
                    to_alloc,                  /* buff_num */
                    (void **)(&ior.first_gpd), /* pp_head */
                    (void **)(&ior.last_gpd)); /* pp_tail */
        if(to_alloc != num_alloc) {ASSERT(0);}
        CCMNI_DEV_LOCK(mask);
        pulq->hwo_rgpd_cnt += num_alloc;
        CCMNI_DEV_UNLOCK(mask);        

        target_gpd = ior.first_gpd;
        ccmni_ut_uplink_format_gpds(pCCMNI3->ccci_ch.ccmni_ch_ul, target_gpd, target_gpd);
        target_gpd = QBM_DES_GET_NEXT(target_gpd);
        ccmni_ut_uplink_format_gpds(pCCMNI3->ccci_ch.ccmni_ch_ul, target_gpd, target_gpd);
        target_gpd = QBM_DES_GET_NEXT(target_gpd);
        ccmni_ut_uplink_format_gpds(pCCMNI3->ccci_ch.ccmni_ch_ul+1, target_gpd, target_gpd);
        target_gpd = QBM_DES_GET_NEXT(target_gpd);
        ccmni_ut_uplink_format_gpds(pCCMNI3->ccci_ch.ccmni_ch_ul, target_gpd, target_gpd);
        ccmni_ut_uplink_format_gpds(pCCMNI3->ccci_ch.ccmni_ch_ul, ior.last_gpd, ior.last_gpd);

        ccmni_ccci_ul_cb(pCCMNI3->ccci_ch.ccmni_ch_ul, (ccci_io_request_t*)&ior);
    }
    
    //4 <4-4> Send uplink with NOT valid data, channel not match. IOR has 5 GPDs, and the 3~5 GPDs are invalid.
    test_step = 5;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step);
    to_alloc = 5;
    for(idx = 1024; idx !=0; idx--){
        num_alloc = qbmt_alloc_q_no_tail(
                    CCMNI_UT_UL_GPD_TYPE,      /* type */
                    to_alloc,                  /* buff_num */
                    (void **)(&ior.first_gpd), /* pp_head */
                    (void **)(&ior.last_gpd)); /* pp_tail */
        if(to_alloc != num_alloc) {ASSERT(0);}
        CCMNI_DEV_LOCK(mask);
        pulq->hwo_rgpd_cnt += num_alloc;
        CCMNI_DEV_UNLOCK(mask);
        target_gpd = QBM_DES_GET_NEXT(ior.first_gpd);
        ccmni_ut_uplink_format_gpds(pCCMNI3->ccci_ch.ccmni_ch_ul, ior.first_gpd, target_gpd);
        target_gpd = QBM_DES_GET_NEXT(target_gpd);
        ccmni_ut_uplink_format_gpds(pCCMNI3->ccci_ch.ccmni_ch_ul+1, target_gpd, ior.last_gpd);
        ccmni_ccci_ul_cb(pCCMNI3->ccci_ch.ccmni_ch_ul, (ccci_io_request_t*)&ior);
    }


    //4 <5-1> Disconnect CCMNI1
    pCCMNI3->state = CCMNI_DEV_DISCONNECTED;
    //4 <5-2> Send uplink to ccmni_ccci_ul_cb(ch, ...), with valid data, expect GPDs are freed
    test_step = 6;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step);
    for(idx = 1024; idx !=0; idx--){
        num_alloc = qbmt_alloc_q_no_tail(
                    CCMNI_UT_UL_GPD_TYPE,      /* type */
                    to_alloc,                  /* buff_num */
                    (void **)(&ior.first_gpd), /* pp_head */
                    (void **)(&ior.last_gpd)); /* pp_tail */
        if(to_alloc != num_alloc) {ASSERT(0);}
        CCMNI_DEV_LOCK(mask);
        pulq->hwo_rgpd_cnt += num_alloc;
        CCMNI_DEV_UNLOCK(mask);        
        ccmni_ut_uplink_format_gpds(pCCMNI3->ccci_ch.ccmni_ch_ul, ior.first_gpd, ior.last_gpd);
        ccmni_ccci_ul_cb(pCCMNI3->ccci_ch.ccmni_ch_ul, (ccci_io_request_t*)&ior);
    }
    //4 <5-3> Connect CCMNI1
    pCCMNI3->state = CCMNI_DEV_CONNECTED;

    //4 <6> Set p_ccmni->ipc_uplink = ipc_uplink  
    p_ccmni->ipc_uplink = ipc_uplink;
    
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_PASS_TRACE, __LINE__);
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
#endif
static kal_int32 ccmni_ut_ccci_write_gpd_false(CCCI_CHANNEL_T channel, ccci_io_request_t *p_ccci_DL_ior, ccci_io_ext_info_t* pextinfo){
    //ccmni_ut_dest_ior(p_ccci_DL_ior);
    return CCCI_FAIL;
}
extern void ccmni_ccci_dummy_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* io_request);
extern ccmni_device_id ccmni_get_ul_devid(CCCI_CHANNEL_T ccci_ul_ch);
kal_bool ccmni_ut_misc(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){

    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    ccmni_device_t      *pCCMNI3;
    kal_char            error_string[256];
    kal_uint32          to_alloc = 0;
    kal_bool            ret;
    qbm_gpd             *first_gpd, *last_gpd;
    ccmni_device_id     test_dev_id;
    kal_uint32          test_step = 0;
    ccmni_ulq_t         *pulq;
    kal_bool            is_dlack = KAL_FALSE;    

    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_TRACE, __LINE__);
    //4 <2> Simulate the callback to dummy CCMNI channels and expect printing the error message
    test_step = 2;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step);
    ccmni_ccci_dummy_cb(5, NULL);

    //4 <3>Stress test for ccmni_reload_ul_gpds
    test_step = 3;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step);
    //allocate 800 QBM_TYPE_HIF_UL_TYPE
    pCCMNI3 = &p_ccmni->dev[2];
    to_alloc = QBM_NUM_HIF_UL_TYPE; //get all
    
    is_dlack = ccmni_is_dlack_ch(pCCMNI3->ccci_ch.ccmni_ch_ul);
    if(KAL_TRUE == is_dlack){
        pulq = &p_ccmni->ulq[pCCMNI3->ulq.ccmni_ack_ulq];
    }else{
        pulq = &p_ccmni->ulq[pCCMNI3->ulq.ccmni_normal_ulq];
    }

   qbmt_alloc_q_no_tail(
                        CCMNI_UT_UL_GPD_TYPE,      /* type */
                        to_alloc,                  /* buff_num */
                        (void **)(&first_gpd), /* pp_head */
                        (void **)(&last_gpd)); /* pp_tail */
    
    pulq->max_hwo_rgpd_cnt ++ ; 
    p_ccmni->ccci_write_gpd = ccmni_ut_ccci_write_gpd;
    ret = ccmni_reload_ul_gpds(pCCMNI3);

    if(KAL_TRUE!=ret){
        sprintf(error_string, "%s%s \n",
        "[CCMNI_UT] ccmni_ut_misc test 3 ",
        "ccmni_reload_ul_gpds should return KAL_TRUE for reload \r\n");
        strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
        goto ccmni_ut_misc_err_out;
    }
    
    qbmt_dest_q(first_gpd, last_gpd);
    pulq->max_hwo_rgpd_cnt -- ; 
    p_ccmni->ccci_write_gpd = ccci_write_gpd;

    //4 <4> Call ccmni_reload_ul_gpds with ccmni_ut_ccci_write_gpd_false return KAL_FASLE
    test_step = 4;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step);
    pCCMNI3 = &p_ccmni->dev[2];
    p_ccmni->ccci_write_gpd = ccmni_ut_ccci_write_gpd_false;
    pulq->max_hwo_rgpd_cnt ++ ;
    ret = ccmni_reload_ul_gpds(pCCMNI3);
    if(KAL_TRUE!=ret){
        sprintf(error_string, "%s%s \n",
        "[CCMNI_UT] ccmni_ut_misc test 4 ",
        "ccmni_reload_ul_gpds should return KAL_TRUE for reload \r\n");
        strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
        goto ccmni_ut_misc_err_out;
    }
    pulq->max_hwo_rgpd_cnt -- ;
    p_ccmni->ccci_write_gpd = ccci_write_gpd;

    //4 <5> Test ccmni_get_ul_devid with various inputs
    test_step = 5;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_STEP_TRACE, __LINE__, test_step);
    test_dev_id = ccmni_get_ul_devid(pCCMNI3->ccci_ch.ccmni_ch_ul);
    if(CCMNI_DEV_CCMNI3!=test_dev_id){
        sprintf(error_string, "%s%s:%d \n",
        "[CCMNI_UT] ccmni_ut_misc test 5 ",
        "ccmni_get_ul_devid(pCCMNI3ch) returns",
        test_dev_id);
        strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
        goto ccmni_ut_misc_err_out;
    }
    
    test_dev_id = ccmni_get_ul_devid(CCCI_IPC_RPC_CHANNEL);
    if(CCMNI_DEV_CNT!=test_dev_id){
        sprintf(error_string, "%s%s:%d \n",
        "[CCMNI_UT] ccmni_ut_misc test 5 ",
        "ccmni_get_ul_devid(IPCch) returns",
        test_dev_id);
        strncpy(p_ret_err_str, error_string, MIN(strlen(error_string), *p_ret_err_str_sz));
        goto ccmni_ut_misc_err_out;
    }
    
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_PASS_TRACE, __LINE__);
    return KAL_TRUE;

ccmni_ut_misc_err_out:
    ccmni_trace(CCMNI_ERR, CCMNI_MOD_UT, CCMNI_UT_ERR, __LINE__);
    return KAL_FALSE;
}

static void ccmni_ut_uplink_set_gpds_channel(CCCI_CHANNEL_T ch, qbm_gpd *head_gpd, qbm_gpd *tail_gpd){
    qbm_gpd             *curr_gpd, *next_gpd;
    kal_bool            end_of_list = KAL_FALSE;
    CCCI_BUFF_T         *p_ccci_head;
    kal_char            *p_data;

    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_TRACE, __LINE__);
    for (curr_gpd = head_gpd; curr_gpd && !end_of_list ; curr_gpd = next_gpd) {
        next_gpd = QBM_DES_GET_NEXT(curr_gpd);
        end_of_list = (curr_gpd == tail_gpd);
        
        p_ccci_head   = (CCCI_BUFF_T *)CCMNI_GET_QBM_DATAPTR(curr_gpd);
        /*Construct the CCCI header*/
        CCCI_SET_CH_NO(p_ccci_head, ch);
        p_data = (kal_char *)p_ccci_head + sizeof(CCCI_BUFF_T);
        *(kal_uint32 *)p_data = CCMNI_UT_MAGIC;
        
        CCCI_STREAM_SET_LEN(p_ccci_head, CCMNI_GET_QBM_DATALEN(curr_gpd)+sizeof(CCMNI_UT_MAGIC));
        QBM_CACHE_FLUSH(p_ccci_head, 2*sizeof(CCCI_BUFF_T));

        curr_gpd = QBM_DES_GET_NEXT(curr_gpd);
    }
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_PASS_TRACE, __LINE__);
}



/** @brief ccmni_ut_tool_get_gpd_list_size
 *
 * ccmni_ut_tool_get_gpd_list_size get gpd list size 
 *
 * @param head gpd list head pointer
 * @param tail gpd list head pointer
 * @return gpd count
 */
kal_uint32 ccmni_ut_tool_get_gpd_list_size(qbm_gpd *head, qbm_gpd *tail)
{
    kal_uint32          cnt = 0;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_TRACE, __LINE__);
    if (tail) {
        while (head) {
            cnt++;
            if (head != tail) {
                head = QBM_DES_GET_NEXT(head);
            } else {
                break;
            }
        }
    }
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_PASS_TRACE, __LINE__);
    return cnt;
}

/** @brief ccmni_ut_uplink_profiling fake ip_uplink
 *
 * ccmni_ut_uplink_profiling fake ip_uplink
 * call by ccmni_ccci_ul_cb
 * free the ior, check gpd number, count cycle
 *
 * @param handle is a ipc handle
 * @param ior is a GPD ior
 * @return an integer
 */
static kal_bool ccmni_ut_ipc_uplink_profiling_cb(
    ipc_handle_t            handle,
    ipc_io_request_t       *ior)
{
    kal_uint32          gpd_num = 0;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_TRACE, __LINE__);
    gpd_num=ccmni_ut_tool_get_gpd_list_size(ior->first_gpd, ior->last_gpd);
    ccmni_trace(CCMNI_INFO, CCMNI_MOD_UT, CCMNI_PROFILING_RGPD_TRACE, gpd_num);    
    ccmni_ut_dest_ior((ccci_io_request_t *)ior);
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_PASS_TRACE, __LINE__);
    return KAL_TRUE;
}

static void ccmni_ut_ccci_ul_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* io_request){
    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    kal_uint32          gpd_num = 0;
    kal_uint32      mask;
    ccmni_device_id dev_id;
    ccmni_device_t      *pdev;
    ccmni_ulq_t         *pulq;
    kal_bool            is_dlack = KAL_FALSE;    

#ifdef __CCMNI_PERF__
    cpu_event_counter_get_cycle(ccmni_prof_rec[CCMNI_prof_idx].ccmni_normal_hif_poll_queue_e);
    ccmni_prof_rec[CCMNI_prof_idx].ccmni_normal_hif_poll_queue_t = \
                cpu_event_get_duration( \
                    ccmni_prof_rec[CCMNI_prof_idx].ccmni_normal_hif_poll_queue_s, \
                    ccmni_prof_rec[CCMNI_prof_idx].ccmni_normal_hif_poll_queue_e  \
                );
    ccmni_trace(CCMNI_OFF, CCMNI_MOD_UT, CCMNI_PROFILING_CYCLE_TRACE, ccmni_prof_rec[CCMNI_prof_idx].ccmni_normal_hif_poll_queue_t);
#endif     
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_TRACE, __LINE__);
    dev_id = ccmni_get_ul_devid(channel);
    /*Invalid CCMNI UL channel*/
    ASSERT(dev_id < CCMNI_DEV_CNT);

    pdev = &p_ccmni->dev[dev_id];
    
    is_dlack = ccmni_is_dlack_ch(channel);
    if(KAL_TRUE == is_dlack){
        pulq = &p_ccmni->ulq[pdev->ulq.ccmni_ack_ulq];
    }else{
        pulq = &p_ccmni->ulq[pdev->ulq.ccmni_normal_ulq];
    }

    gpd_num=ccmni_ut_tool_get_gpd_list_size(io_request->first_gpd, io_request->last_gpd);
    ccmni_trace(CCMNI_INFO, CCMNI_MOD_UT, CCMNI_PROFILING_RGPD_TRACE, gpd_num);   
    ccmni_ut_dest_ior((ccci_io_request_t *)io_request);
    CCMNI_DEV_LOCK(mask);
    pulq->hwo_rgpd_cnt -= gpd_num;
    CCMNI_DEV_UNLOCK(mask);
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_PASS_TRACE, __LINE__);
}


void ccmni_ut_tool_clr_hwo(void *p_head, void *p_tail){
    void *p_curr;

    if(NULL==p_head){
        return;
    }
    if (p_tail){
        QBM_DES_SET_NEXT(p_tail, NULL);
        QBM_CACHE_FLUSH(p_tail, sizeof(qbm_gpd));
    }

    p_curr = p_head;
    while (p_curr){
        QBM_DES_CLR_HWO(p_curr);
        QBM_CACHE_FLUSH(p_curr, sizeof(qbm_gpd));
        p_curr = QBM_DES_GET_NEXT(p_curr);
    }
}


#if defined(__MTK_TARGET__)
extern void hif_get_que_list(kal_bool is_tx , kal_uint8 q_no, void **pp_head, void **pp_tail);
#else
extern void hif_sim_get_que_list(kal_bool is_tx , kal_uint8 q_no, void **pp_head, void **pp_tail);
extern kal_uint32 Rx_receive_cnt[5];
#endif
kal_bool ccmni_ut_uplink_profiling(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    ccmni_device_t      *pCCMNI_dev = &(p_ccmni->dev[0]);
    ccci_io_request_t    ior;
    kal_uint32          to_reload = 800;
    kal_uint32          num_alloc = 0;
    kal_uint32          mask;
    kal_bool            ret = KAL_FALSE;
    kal_uint32          retry_count;
    kal_uint32          reload_array[]={1,9,19}, index = 0;
    kal_uint32          reload_array_size = sizeof(reload_array)/sizeof(kal_uint32);
    ccmni_ulq_t         *pulq;
    kal_bool            is_dlack = KAL_FALSE;    
 
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_TRACE, __LINE__);    
    ior.next_request = NULL;
    //4 <1> Set p_ccmni->ipc_uplink = ccmni_ut_ipc_uplink_profiling_cb
    p_ccmni->ipc_uplink = ccmni_ut_ipc_uplink_profiling_cb;

    p_ccmni->ccci_deinit(pCCMNI_dev->ccci_ch.ccmni_ch_ul);
    p_ccmni->ccci_init_gpdior(pCCMNI_dev->ccci_ch.ccmni_ch_ul,ccmni_ut_ccci_ul_cb);
    
    is_dlack = ccmni_is_dlack_ch(pCCMNI_dev->ccci_ch.ccmni_ch_ul);
    if(KAL_TRUE == is_dlack){
        pulq = &p_ccmni->ulq[pCCMNI_dev->ulq.ccmni_ack_ulq];
    }else{
        pulq = &p_ccmni->ulq[pCCMNI_dev->ulq.ccmni_normal_ulq];
    }
    //4 <4> Send LINK_UP_REQ to CCMNI1~3
//	    for(dev_id = 0; dev_id < 3; dev_id++){
//	        ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_TR_LINK_UP_REQ, dev_id);
//	        ccmni_ut_linkup(&p_ccmni->dev[dev_id]);
//	    }
    //4 <2> Send uplink to gpds and clear hwo    
//	    pCCMNI_dev->max_hwo_rgpd_cnt = to_reload ;
//	    to_alloc = pCCMNI_dev->max_hwo_rgpd_cnt - pCCMNI_dev->hwo_rgpd_cnt;
    
    //ret = ccmni_reload_ul_gpds(pCCMNI3);
    while(index<reload_array_size){
        to_reload = reload_array[index++];
        num_alloc = qbmt_alloc_q_no_tail(
                    CCMNI_UT_UL_GPD_TYPE, /* type */
                    to_reload, /* buff_num */
                    (void **)(&ior.first_gpd), /* pp_head */
                    (void **)(&ior.last_gpd)); /* pp_tail */
#ifdef __SDIOC_PULL_Q_ENH_DL__
        ior.num_gpd = num_alloc;
#endif
        ccmni_trace(CCMNI_INFO, CCMNI_MOD_UT, CCMNI_PROFILING_RELOAD_TRACE, num_alloc); 
        CCMNI_DEV_LOCK(mask);
        pulq->hwo_rgpd_cnt += num_alloc;
        CCMNI_DEV_UNLOCK(mask);
        ccmni_ut_uplink_format_gpds(pCCMNI_dev->ccci_ch.ccmni_ch_ul, ior.first_gpd, ior.last_gpd);
        p_ccmni->ccci_write_gpd(pCCMNI_dev->ccci_ch.ccmni_ch_ul, &ior, NULL);
#if defined(__MTK_TARGET__)
//	        CCMNI_DEV_LOCK(mask);
        hif_get_que_list(KAL_FALSE, 0x02,(void**)&ior.first_gpd, (void**)&ior.last_gpd);
        ccmni_ut_uplink_set_gpds_channel(pCCMNI_dev->ccci_ch.ccmni_ch_ul, ior.first_gpd, ior.last_gpd);
        ccmni_ut_tool_clr_hwo(ior.first_gpd, ior.last_gpd);
//	        CCMNI_DEV_UNLOCK(mask);
#else
        hif_sim_get_que_list(KAL_FALSE, 0x02,(void**)&ior.first_gpd, (void**)&ior.last_gpd);
        ccmni_ut_uplink_set_gpds_channel(pCCMNI_dev->ccci_ch.ccmni_ch_ul, ior.first_gpd, ior.last_gpd);
        CCMNI_DEV_LOCK(mask);
        Rx_receive_cnt[2] = num_alloc;
        CCMNI_DEV_UNLOCK(mask);
#endif
        retry_count = 0;
        do{
            kal_sleep_task(KAL_TICKS_10_MSEC);   
            if (pulq->hwo_rgpd_cnt == 0){
                ret = KAL_TRUE;
                break;
            }
            retry_count++;

        }while(retry_count < 100);
    }
//	    pCCMNI_dev->max_hwo_rgpd_cnt = NICC_MAX_UL_BUF_IN_HIF;
    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_PASS_TRACE, __LINE__);  
    return ret;
}

kal_bool ccmni_ut_atci_mode_switch(void *p_param, kal_char *p_ret_err_str, kal_uint32 *p_ret_err_str_sz){
    kal_uint32          num_alloc = 0;
    ccci_io_request_t   ior;
    kal_char            *p_data;
    CCCI_BUFF_T         *p_ccci_head;
    kal_uint32          mask;

    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_TRACE, __LINE__);  
    num_alloc = qbmt_alloc_q_no_tail(
                QBM_TYPE_CCCI_COMM, /* type */
                1, /* buff_num */
                (void **)(&ior.first_gpd), /* pp_head */
                (void **)(&ior.last_gpd)); /* pp_tail */
#ifdef __SDIOC_PULL_Q_ENH_DL__
    ior.num_gpd = num_alloc;
#endif
    CCMNI_PUSH_QBM_DATAHEAD(ior.first_gpd, sizeof(CCCI_BUFF_T));
    p_ccci_head   = (CCCI_BUFF_T *)CCMNI_GET_QBM_DATAPTR(ior.first_gpd);
    /*Construct the CCCI header*/
    CCCI_SET_CH_NO(p_ccci_head, CCCI_AT_CHANNEL_RX);
    p_data = (kal_char *)p_ccci_head + sizeof(CCCI_BUFF_T);
    strcpy(p_data,"AT+CCMNI1=1\r");
    
    CCCI_STREAM_SET_LEN(p_ccci_head, CCMNI_GET_QBM_DATALEN(ior.first_gpd)+13);
    QBM_CACHE_FLUSH(p_ccci_head, 2*sizeof(CCCI_BUFF_T));
    ccci_write_gpd(CCCI_AT_CHANNEL_RX, &ior, NULL);
#if defined(__MTK_TARGET__)
        CCMNI_DEV_LOCK(mask);
        hif_get_que_list(KAL_FALSE, 0x01,(void**)&ior.first_gpd, (void**)&ior.last_gpd);
        ccmni_ut_tool_clr_hwo(ior.first_gpd, ior.last_gpd);
        CCMNI_DEV_UNLOCK(mask);
#else
        Rx_receive_cnt[1] = num_alloc;
#endif

    ccmni_trace(CCMNI_TRACE, CCMNI_MOD_UT, CCMNI_UT_FUNC_PASS_TRACE, __LINE__);  
    return KAL_TRUE;
}



#if defined(ATEST_SYS_CCCI_CCMNI)
extern kal_bool st_reg_test(kal_char *p_mod_name, ST_TCASE_T *p_tcase, kal_uint32 tcase_num);

ST_TCASE_T st_tcase_ccmni_g[] = {
    {"1.1 ccmni_ut_init_test",    ccmni_ut_init_test,       NULL}, 
    {"1.2 ccmni_ut_link_state",   ccmni_ut_link_state,      NULL},  
    {"1.3 ccmni_ut_downlink",     ccmni_ut_downlink,        NULL},
    {"1.4 ccmni_ut_uplink",       ccmni_ut_uplink,          NULL},
    {"1.5 ccmni_ut_misc",         ccmni_ut_misc,            NULL},
//	    {"2.1 ccmni_ut_uplink_profiling",         ccmni_ut_uplink_profiling,            NULL},
    {"ccmni_dummy",               ccmni_dummy,              NULL}
};
kal_uint32 st_tcase_count_ccciccmni_g = sizeof(st_tcase_ccmni_g) / sizeof(ST_TCASE_T);

kal_bool ccmni_ut_st_create()
{
    return st_reg_test("CCMNI", st_tcase_ccmni_g, st_tcase_count_ccciccmni_g);
}
#endif
#endif //#if defined(__CCMNI_UT__)
