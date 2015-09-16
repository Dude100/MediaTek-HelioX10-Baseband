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
 *   ccci_sm.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Implements the CCCI CCMNI state machine
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
 * 08 01 2014 ap.wang
 * removed!
 * .
 *
 * 07 22 2014 aj.tsai
 * removed!
 * 	Merging
 *  	
 * 	//MOLY/BRANCHES_LR9/LR9.W1421.MD.LWTG.MP/mcu/middleware/hif/cccidev/ccci_ccmni/...
 *  	
 * 	to //MOLY/BRANCHES_LR9/LR9.W1423.MD.LWTG.MP/mcu/middleware/hif/cccidev/ccci_ccmni/...
 *
 * 07 10 2014 aj.tsai
 * removed!
 * Add new ccci debug mechanism -CCMNI
 *
 * 06 27 2014 ap.wang
 * removed!
 * Add QBM pool status notify
 *
 * 06 13 2014 ap.wang
 * removed!
 * Remove INITIALIZED state
 *
 * 05 29 2014 ap.wang
 * removed!
 * .
 *
 * 05 14 2014 ap.wang
 * removed!
 * CCMNI Fast Ack Patch and linkdown fast reload
 *
 * removed!
 * removed!
 * 	[CCMNI ACK Fast Path]
 *
 * 03 06 2014 ap.wang
 * removed!
 * CCMNI Log reduction
 *
 * 01 14 2014 ap.wang
 * removed!
 * Fix ccmni state chage check assert
 *
 * 01 10 2014 ap.wang
 * removed!
 * 	Fix IPv4/v6 linkdown issue
 *
 * removed!
 * removed!
 * [ccmni] split HIF UL QBM pool
 *
 * 04 11 2013 ap.wang
 * removed!
 * [CCMNI_IT] Modify CCMNI IT RGPD reload flow
 *
 * 04 10 2013 ap.wang
 * removed!
 * [CCMNI_IT] Modify CCMNI IT RGPD reload flow
 *
 * 03 27 2013 ap.wang
 * removed!
 *
 * removed!
 * removed!
 * Rename project name as MT6290
 *
 * 01 29 2013 ap.wang
 * removed!
 * [CCMNI_IT] Modify RGPD reload method
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
#include "ccmni_sm.h"
#include "ccmni_if.h"
#include "qmu_bm.h"
#include "ipc_api.h"
#include "ccmni_data.h"

typedef kal_bool (*ccmni_dev_sm_action_t)(ccmni_device_t *dev);
typedef struct ccmni_dev_sm_entry_t {
    ccmni_dev_event         event;
    ccmni_dev_state         new_state;
    ccmni_dev_sm_action_t   pre_action; /* action b4 state change*/
    ccmni_dev_sm_action_t   post_action;/* action after state change*/
} ccmni_dev_sm_entry_t;

/*------------------------------------------------------------------------------
 * Private variables.
 *----------------------------------------------------------------------------*/
static ccci_ch_id_t g_ccmni_ccci_ch_mappping[CCMNI_DEV_CNT] = {
    /*{dl, ul, dl_ack, ul_ack, dlack_ul}*/
    {CCCI_CCMNI1_RX, CCCI_CCMNI1_TX, CCCI_CCMNI1_RX_ACK, CCCI_CCMNI1_TX_ACK, CCCI_CCMNI1_DLACK_RX}, /*CCMNI_DEV_CCMNI1*/
    {CCCI_CCMNI2_RX, CCCI_CCMNI2_TX, CCCI_CCMNI2_RX_ACK, CCCI_CCMNI2_TX_ACK, CCCI_CCMNI2_DLACK_RX}, /*CCMNI_DEV_CCMNI2*/
    {CCCI_CCMNI3_RX, CCCI_CCMNI3_TX, CCCI_CCMNI3_RX_ACK, CCCI_CCMNI3_TX_ACK, CCCI_CCMNI3_DLACK_RX}, /*CCMNI_DEV_CCMNI3*/
    {CCCI_CCMNI4_RX, CCCI_CCMNI4_TX, CCCI_CCMNI4_RX_ACK, CCCI_CCMNI4_TX_ACK, CCCI_CCMNI4_DLACK_RX}, /*CCMNI_DEV_CCMNI4*/
    {CCCI_CCMNI5_RX, CCCI_CCMNI5_TX, CCCI_CCMNI5_RX_ACK, CCCI_CCMNI5_TX_ACK, CCCI_CCMNI5_DLACK_RX}, /*CCMNI_DEV_CCMNI5*/
    {CCCI_CCMNI6_RX, CCCI_CCMNI6_TX, CCCI_CCMNI6_RX_ACK, CCCI_CCMNI6_TX_ACK, CCCI_CCMNI6_DLACK_RX}, /*CCMNI_DEV_CCMNI6*/
    {CCCI_CCMNI7_RX, CCCI_CCMNI7_TX, CCCI_CCMNI7_RX_ACK, CCCI_CCMNI7_TX_ACK, CCCI_CCMNI7_DLACK_RX}, /*CCMNI_DEV_CCMNI7*/
    {CCCI_CCMNI8_RX, CCCI_CCMNI8_TX, CCCI_CCMNI8_RX_ACK, CCCI_CCMNI8_TX_ACK, CCCI_CCMNI8_DLACK_RX}, /*CCMNI_DEV_CCMNI8*/    
};
static ccmni_ulq_id_t g_ccmni_ulq_mappping[CCMNI_DEV_CNT] = {
    /*{ccmni_normal_ulq, ccmni_ack_ulq}*/
    {CCMNI_ULQ_T_NORMAL, CCMNI_ULQ_T_ACK}, /*CCMNI_DEV_CCMNI1*/
    {CCMNI_ULQ_T_NORMAL, CCMNI_ULQ_T_ACK}, /*CCMNI_DEV_CCMNI2*/
    {CCMNI_ULQ_MISC,     CCMNI_ULQ_MISC},  /*CCMNI_DEV_CCMNI3*/
    {CCMNI_ULQ_MISC,     CCMNI_ULQ_MISC},  /*CCMNI_DEV_CCMNI4*/
    {CCMNI_ULQ_MISC,     CCMNI_ULQ_MISC},  /*CCMNI_DEV_CCMNI5*/
    {CCMNI_ULQ_MISC,     CCMNI_ULQ_MISC},  /*CCMNI_DEV_CCMNI6*/
    {CCMNI_ULQ_MISC,     CCMNI_ULQ_MISC},  /*CCMNI_DEV_CCMNI7*/
    {CCMNI_ULQ_MISC,     CCMNI_ULQ_MISC},  /*CCMNI_DEV_CCMNI8*/    
};
static kal_bool g_sw_throughput_throttling_support[CCMNI_DEV_CNT] = {
    KAL_TRUE,   /*CCMNI_DEV_CCMNI1*/
    KAL_TRUE,   /*CCMNI_DEV_CCMNI2*/   
    KAL_FALSE,  /*CCMNI_DEV_CCMNI3*/
    KAL_FALSE,  /*CCMNI_DEV_CCMNI4*/
    KAL_FALSE,  /*CCMNI_DEV_CCMNI5*/
    KAL_FALSE,  /*CCMNI_DEV_CCMNI6*/
    KAL_FALSE,  /*CCMNI_DEV_CCMNI7*/
    KAL_FALSE,  /*CCMNI_DEV_CCMNI8*/
};
static ccmni_inst_t g_ccmnidev_int;
static ccmni_dbg_status_t g_ccmni_dbg_status;


/*
 * State machine for CCMNI_DEV_UNINITIALIZED state.
 */
static ccmni_dev_sm_entry_t ccmni_uninit_state_machine_s[] = {
    /* {event, new_state, pre-action, post_action} */
    {CCMNI_EVT_FUNC_ENABLE,     CCMNI_DEV_DISCONNECTED,     NULL, ccmni_session_init}, /* triggered by ccmni_dev_main_init->MSG_ID_CCMNI_SESSION_INIT_REQ */
    {CCMNI_EVT_FUNC_DISABLE,    CCMNI_DEV_UNINITIALIZED,    NULL, NULL}, /* Do nothing. */
    {CCMNI_EVT_LINK_UP,         CCMNI_DEV_UNINITIALIZED,    NULL, NULL}, /* Do nothing. */
    {CCMNI_EVT_LINK_DOWN,       CCMNI_DEV_UNINITIALIZED,    NULL, NULL}, /* Do nothing. */
    {CCMNI_EVT_DUMMY,           CCMNI_DEV_UNINITIALIZED,    NULL, NULL}  /* End of the state machine. */
    };

/*
 * State machine for CCMNI_DEV_INITIALIZED state.
 */
static ccmni_dev_sm_entry_t ccmni_init_state_machine_s[] = {
    /* {event, new_state, pre-action, post_action} */
    {CCMNI_EVT_FUNC_DISABLE,    CCMNI_DEV_UNINITIALIZED,    NULL, ccmni_session_deinit}, /* detach IPcore and CCCI ch. */
    {CCMNI_EVT_LINK_UP,         CCMNI_DEV_CONNECTED,        NULL, NULL}, /* Do nothing. */
    {CCMNI_EVT_LINK_DOWN,       CCMNI_DEV_INITIALIZED,      NULL, NULL}, /* Do nothing. */
    {CCMNI_EVT_DUMMY,           CCMNI_DEV_INITIALIZED,      NULL, NULL}  /* End of the state machine. */
    };

/*
 * State machine for CCMNI_DEV_DISCONNECTED state.
 */
static ccmni_dev_sm_entry_t ccmni_disconn_state_machine_s[] = {
    /* {event, new_state, pre-action, post_action} */
    {CCMNI_EVT_FUNC_DISABLE,    CCMNI_DEV_UNINITIALIZED,    NULL, ccmni_session_deinit}, /* detach IPcore and CCCI ch. */
    {CCMNI_EVT_LINK_UP,         CCMNI_DEV_CONNECTED,        NULL, ccmni_session_linkup}, /* linkup() add session count */
    {CCMNI_EVT_LINK_DOWN,       CCMNI_DEV_DISCONNECTED,     NULL, NULL}, /* Do nothing. */
    {CCMNI_EVT_DUMMY,           CCMNI_DEV_DISCONNECTED,     NULL, NULL}  /* End of the state machine. */
    };

/*
 * State machine for CCMNI_DEV_CONNECTED state.
 */
static ccmni_dev_sm_entry_t ccmni_conn_state_machine_s[] = {
    /* {event, new_state, pre-action, post_action} */
    {CCMNI_EVT_FUNC_DISABLE,    CCMNI_DEV_UNINITIALIZED,    NULL, ccmni_session_deinit}, /* detach IPcore and CCCI ch. */
    {CCMNI_EVT_LINK_UP,         CCMNI_DEV_CONNECTED,        NULL, ccmni_session_linkup}, /* linkup() add session count */
    {CCMNI_EVT_LINK_DOWN,       CCMNI_DEV_CONNECTED,        NULL, ccmni_session_linkdown}, /* linkdown() may chagne state */
    {CCMNI_EVT_DUMMY,           CCMNI_DEV_CONNECTED,        NULL, NULL}  /* End of the state machine. */
    };

static ccmni_dev_sm_entry_t *ccmni_dev_state_machines_s[CCMNI_DEV_STATE_CNT] = {
    ccmni_uninit_state_machine_s,       /* CCMNI_DEV_UNINITIALIZED */
    ccmni_init_state_machine_s,         /* CCMNI_DEV_INITIALIZED */
    ccmni_disconn_state_machine_s,      /* CCMNI_DEV_DISCONNECTED */
    ccmni_conn_state_machine_s          /* CCMNI_DEV_CONNECTED */
    };

/*!
 * @function        ccmni_set_dev_state
 * @brief           function to set the CCMNI state with DEV_LOCK. 
 *
 * @param dev       [IN] pointer to CCMNI device
 * @param state     [IN] new state
 *
 * @return          void
 */
void ccmni_set_dev_state(ccmni_device_t *dev, ccmni_dev_state state)
{
    kal_uint32          mask;

    ASSERT(dev);
    CCMNI_DEV_LOCK(mask);
    dev->state = state;
    CCMNI_DEV_UNLOCK(mask);
}
/*!
 * @function        ccmni_on_dev_event
 * @brief           CCMNI even handler, which adjust the state and called the correspoind function in ccmni_dev_state_machines_s
 *
 * @param dev       [IN] pointer to CCMNI device
 * @param event     [IN] event received
 *
 * @return          returns the new state, ccmni_dev_state
 */
ccmni_dev_state ccmni_on_dev_event(ccmni_device_t *dev, ccmni_dev_event event)
{
    ccmni_dev_sm_entry_t   *state_machine;
    ccmni_dev_sm_entry_t   *entry;
    kal_uint32              idx;
    ccmni_dev_state         old_state;
    ccmni_dev_state         new_state;
    kal_bool                ret;

    ASSERT(dev);
    ASSERT(dev->dev_id < CCMNI_DEV_CNT);
    ASSERT((kal_uint16)event <= (kal_uint16)CCMNI_EVT_CNT);

    old_state = ccmni_get_dev_state(dev);
    new_state = old_state;
    state_machine = ccmni_dev_state_machines_s[old_state];

    for (idx = 0; idx < CCMNI_EVT_CNT; idx++) { 
        entry = state_machine + idx;
        if (event == entry->event) {
            /* It's a valid event for this state. */
            new_state = entry->new_state;
            //4 <1> process pre_action b4 state changed
            if (entry->pre_action) {
                ret = entry->pre_action(dev);
                ASSERT(KAL_TRUE == ret);
            }
            //4 <2> change state
            ccmni_trace(CCMNI_INFO, CCMNI_MOD_SM, CCMNI_TR_SM_VALID_EVENT, dev->dev_id, old_state, event, new_state);
            ccmni_set_dev_state(dev, new_state);
            //4 <3> process post_action after state changed
            if (entry->post_action) {
                ret = entry->post_action(dev);
                ASSERT(KAL_TRUE == ret);
            }
            //ASSERT(new_state == ccmni_get_dev_state(dev));
            break;
        } else if (CCMNI_EVT_DUMMY == entry->event) {
            /*It's an unexpected event for this state.*/
            ccmni_trace(CCMNI_ERR, CCMNI_MOD_SM, CCMNI_TR_SM_INVALID_EVENT, dev->dev_id, old_state, event);
            ASSERT(KAL_FALSE);
            break;
        }
    }
    ccmni_data_trace(CCMNI_DEVICE_STATUS, dev->dev_id, event, old_state, dev->state);
    return new_state;
}

/*!
 * @function        ccmni_session_deinit
 * @brief           deinit the ccci sessions, called during hmu_deinit
 *                  ccmni_hmu_deinit -> MSG_ID_CCMNI_SESSION_DEINIT_REQ ->
 *                  CCMNI_EVT_FUNC_DISABLE -> ccmni_session_deinit
 *
 * @param dev       [IN] pointer to CCMNI device
 *
 * @return          KAL_TRUE
 */
kal_bool ccmni_session_deinit(ccmni_device_t *dev)
{
    ccmni_inst_t*       p_ccmni = ccmni_get_instance();

    //4 <1> ipc_detach
    p_ccmni->ipc_detach(dev->ipc_handle);

    //4 <2> ccci_deinit
    p_ccmni->ccci_deinit(dev->ccci_ch.ccmni_ch_dl);
    p_ccmni->ccci_deinit(dev->ccci_ch.ccmni_ch_dl_ack);
    p_ccmni->ccci_deinit(dev->ccci_ch.ccmni_ch_ul_ack);
    p_ccmni->ccci_deinit(dev->ccci_ch.ccmni_ch_ul);
    p_ccmni->ccci_deinit(dev->ccci_ch.ccmni_ch_dlack_ul);
        
    return KAL_TRUE;    
}

/*!
 * @function        ccmni_session_deinit
 * @brief           deinit the ccci sessions, called during hmu_deinit
 *                  ccmni_hmu_deinit -> MSG_ID_CCMNI_SESSION_DEINIT_REQ ->
 *                  CCMNI_EVT_FUNC_DISABLE -> ccmni_session_deinit
 *
 * @param dev       [IN] pointer to CCMNI device
 *
 * @return          KAL_TRUE
 */
kal_bool ccmni_session_linkup(ccmni_device_t *dev)
{
    kal_uint32          mask;
    
    //4 <1> add session count
    ASSERT(dev);

    CCMNI_DEV_LOCK(mask);
    dev->session_count++;
    CCMNI_DEV_UNLOCK(mask);
       
    return KAL_TRUE;    
}

/*!
 * @function        ccmni_session_deinit
 * @brief           deinit the ccci sessions, called during hmu_deinit
 *                  ccmni_hmu_deinit -> MSG_ID_CCMNI_SESSION_DEINIT_REQ ->
 *                  CCMNI_EVT_FUNC_DISABLE -> ccmni_session_deinit
 *
 * @param dev       [IN] pointer to CCMNI device
 *
 * @return          KAL_TRUE
 */
kal_bool ccmni_session_linkdown(ccmni_device_t *dev)
{
    kal_uint32          mask;

    //4 <1> sub session count
    ASSERT(dev);

    CCMNI_DEV_LOCK(mask);
    dev->session_count--;
    
    if(dev->session_count <= 0){
        dev->session_count = 0;
        dev->state = CCMNI_DEV_DISCONNECTED;        
    }
    CCMNI_DEV_UNLOCK(mask);
    return KAL_TRUE;    
}

/*!
 * @function        ccmni_get_instance
 * @brief           obtain the CCMNI instance
 *
 * @return          pointer of CCMNI instance, g_ccmnidev_int
 */
ccmni_inst_t* ccmni_get_instance()
{

    return &g_ccmnidev_int;
}

#ifdef __CCMNI_ACK_FAST_PATH__
/*!
 * @function        ccmni_is_dlack_ch
 * @brief           identify if the input ul ch type
 *
 * @return          KAL_TRUE: dlack channel
 *                  KAL_FALSE: normal channel
 */
kal_uint8 ccmni_is_dlack_ch(CCCI_CHANNEL_T ccci_ul_ch){
    kal_uint32 is_dlack = KAL_FALSE;
    kal_uint32 dev_idx = 0;
    for(dev_idx = 0; dev_idx < CCMNI_DEV_CNT; dev_idx++){
        if(g_ccmni_ccci_ch_mappping[dev_idx].ccmni_ch_dlack_ul == ccci_ul_ch){
            is_dlack = KAL_TRUE;
            break;
        }
    }
    return is_dlack;
}
#endif

/*!
 * @function        ccmni_get_ul_devid
 * @brief           obtain the ccmni_dev_id from ccci channel, used in uplink data handling
 *
 * @return          ccmni_device_id
 */
ccmni_device_id ccmni_get_ul_devid(CCCI_CHANNEL_T ccci_ul_ch){
    kal_uint32 dev_idx = 0;
    for(dev_idx = 0; dev_idx < CCMNI_DEV_CNT; dev_idx++){
        if(g_ccmni_ccci_ch_mappping[dev_idx].ccmni_ch_ul == ccci_ul_ch){
            break;
        }
#ifdef __CCMNI_ACK_FAST_PATH__
        if(g_ccmni_ccci_ch_mappping[dev_idx].ccmni_ch_dlack_ul == ccci_ul_ch){
            break;
        }
#endif
    }
    return dev_idx;
}


kal_uint32 ccmni_get_debug_status(kal_uint32 *write_ptr, kal_uint32 available_size)
{
    kal_uint32 i;
    ccmni_inst_t*     p_ccmni =ccmni_get_instance();


    //reset first                    
    kal_mem_set((void*)&g_ccmni_dbg_status, 0, sizeof(g_ccmni_dbg_status));
    
    for(i = 0 ; i < CCMNI_DEV_CNT ; i++)
    {
        g_ccmni_dbg_status.state[i] = p_ccmni->dev[i].state;
        g_ccmni_dbg_status.session_count[i] = p_ccmni->dev[i].session_count;
    }
    for(i = 0; i < CCMNI_ULQ_CNT ; i++)
    {
        g_ccmni_dbg_status.max_hwo_rgpd_cnt[i] = p_ccmni->ulq[i].max_hwo_rgpd_cnt;
        g_ccmni_dbg_status.hwo_rgpd_cnt[i] = p_ccmni->ulq[i].hwo_rgpd_cnt;
    }
    kal_mem_cpy( (void*)write_ptr, (void*)&g_ccmni_dbg_status, sizeof(g_ccmni_dbg_status));
    return sizeof(g_ccmni_dbg_status);
}

/*!
 * @function        ccmni_session_init
 * @brief           init the ccci sessions, and reload the RGPDs, called during hmu_init
 *                  ccmni_dev_main_init -> MSG_ID_CCMNI_SESSION_INIT_REQ ->
 *                  CCMNI_EVT_FUNC_ENABLE -> ccmni_session_init
 *
 *                  Note: for the UT case, ccmni_ut_linkup is called to fake the IPC_LINK_UP_REQ
 *
 * @param dev       [IN] pointer to CCMNI device
 *
 * @return          KAL_TRUE
 */
#if (defined(__CCMNI_UT__) || defined(__CCCI_LB_IT__) || defined(__CCMNI_IT__))
extern kal_bool ccmni_ut_linkup(ccmni_device_t* dev);
#endif
kal_bool ccmni_session_init(ccmni_device_t *dev)
{
    kal_int32           ret;
    static kal_bool    registered = KAL_FALSE;
    ccmni_inst_t        *p_ccmni = ccmni_get_instance();
    kal_bool            need_retry;

    ASSERT(dev->dev_id < CCMNI_DEV_CNT);

    //4 <1> ccci_init_gpdior Tx/Rx ccci ch,  ASSERT if fail 
    ret = p_ccmni->ccci_init_gpdior(dev->ccci_ch.ccmni_ch_ul, ccmni_ccci_ul_cb);
    if(CCCI_SUCCESS != ret){
        ccmni_trace(CCMNI_ERR, CCMNI_MOD_SM, CCMNI_TR_SESSION_INIT_FATAL_ERROR, dev->dev_id, ret); ASSERT(0); return KAL_FALSE;
    }
    ret = p_ccmni->ccci_init_gpdior(dev->ccci_ch.ccmni_ch_dl, ccmni_ccci_dummy_cb);
    if(CCCI_SUCCESS != ret){
        ccmni_trace(CCMNI_ERR, CCMNI_MOD_SM, CCMNI_TR_SESSION_INIT_FATAL_ERROR, dev->dev_id, ret); ASSERT(0); return KAL_FALSE;
    }
    ret = p_ccmni->ccci_init_gpdior(dev->ccci_ch.ccmni_ch_dl_ack, ccmni_ccci_dummy_cb);
    if(CCCI_SUCCESS != ret){
        ccmni_trace(CCMNI_ERR, CCMNI_MOD_SM, CCMNI_TR_SESSION_INIT_FATAL_ERROR, dev->dev_id, ret); ASSERT(0); return KAL_FALSE;
    }
    ret = p_ccmni->ccci_init_gpdior(dev->ccci_ch.ccmni_ch_ul_ack, ccmni_ccci_dummy_cb);
    if(CCCI_SUCCESS != ret){
        ccmni_trace(CCMNI_ERR, CCMNI_MOD_SM, CCMNI_TR_SESSION_INIT_FATAL_ERROR, dev->dev_id, ret); ASSERT(0); return KAL_FALSE;
    }
    ret = p_ccmni->ccci_init_gpdior(dev->ccci_ch.ccmni_ch_dlack_ul, ccmni_ccci_ul_cb);
    if(CCCI_SUCCESS != ret){
        ccmni_trace(CCMNI_ERR, CCMNI_MOD_SM, CCMNI_TR_SESSION_INIT_FATAL_ERROR, dev->dev_id, ret); ASSERT(0); return KAL_FALSE;
    }
    
    //4 <2> reload RGPDs for IPCore,  ASSERT if fail,  function is called at HMU init, should have enough RGPDs   
    /* e.g. rndis_start_data_path*/
    ccmni_trace(CCMNI_INFO, CCMNI_MOD_RGPDMGR, CCMNI_TR_RGPD_RELOAD_BY_INIT, dev->dev_id);
    need_retry = ccmni_reload_ul_gpds(dev);
    if(need_retry){
        ccmni_ulq_t    *p_nor_ulq = NULL;
        ccmni_ulq_t    *p_ack_ulq = NULL;
        p_nor_ulq = &p_ccmni->ulq[dev->ulq.ccmni_normal_ulq];
        p_ack_ulq = &p_ccmni->ulq[dev->ulq.ccmni_ack_ulq];
        if ((p_nor_ulq->hwo_rgpd_cnt < 2) || (p_ack_ulq->hwo_rgpd_cnt < 2)){
            ccmni_trace(CCMNI_ERR, CCMNI_MOD_SM, CCMNI_TR_SESSION_INIT_FATAL_ERROR, dev->dev_id, need_retry); ASSERT(0); return KAL_FALSE;
        } else {
            // reset max hwo rgpd count for not have LTE_RAT define
            p_nor_ulq->max_hwo_rgpd_cnt = p_nor_ulq->hwo_rgpd_cnt;
            p_ack_ulq->max_hwo_rgpd_cnt = p_ack_ulq->hwo_rgpd_cnt;
        }
    }

    //4 <3> init session count
    dev->session_count = 0;
    
#if (defined(__CCMNI_UT__) || defined(__CCCI_LB_IT__) || defined(__CCMNI_IT__))
    //4 <3> Fake the ipcore link up request
    ccmni_ut_linkup(dev);
#endif
    if(KAL_FALSE == registered)
        ccci_debug_get_status_register(CCCI_DEBUG_GET_STATUS_MODULE_CCMNI, ccmni_get_debug_status);
    return KAL_TRUE;
}

#ifndef  __IPCORE_SUPPORT__
/* defined the dummy IP Core function if IPCORE is not defined*/
static kal_bool _ccmni_fake_ipc_attach(
    ipc_conf_t             *config,
    ipc_handle_t           *handle){
    return KAL_TRUE;
}
static kal_bool _ccmni_fake_ipc_detach(
    ipc_handle_t           handle){
    return KAL_TRUE;    
}
static kal_bool _ccmni_fake_ipc_uplink(
    ipc_handle_t            handle,
    ipc_io_request_t       *ior){
    return KAL_TRUE;
}
static kal_int32 _ccmni_fake_ipc_get_ip_id(
    ipc_handle_t            handle){
    return 0;
}
#endif

/*!
 * @function        ccmni_task_init
 * @brief           initial function for CCMNI, called by cccidev_task_main.cccidev_init_func_list_g
 *
 * @param type      Reserved
 *
 * @return          KAL_TRUE
 */ 
kal_bool ccmni_task_init(void)
{
    ccmni_inst_t*       p_ccmni = ccmni_get_instance();
    kal_uint32          i;

    for(i = CCMNI_DEV_CCMNI1; i<CCMNI_DEV_CNT ; i++){
        p_ccmni->dev[i].state = CCMNI_DEV_UNINITIALIZED;
        p_ccmni->dev[i].module_id = MOD_CCMNI;
        p_ccmni->dev[i].dev_id = i; /*assign CCMNI_DEV_CCMNIx*/
        p_ccmni->dev[i].ipc_handle = NULL;
        p_ccmni->dev[i].ccci_ch.ccmni_ch_dl         = g_ccmni_ccci_ch_mappping[i].ccmni_ch_dl;
        p_ccmni->dev[i].ccci_ch.ccmni_ch_ul         = g_ccmni_ccci_ch_mappping[i].ccmni_ch_ul;
        p_ccmni->dev[i].ccci_ch.ccmni_ch_dl_ack     = g_ccmni_ccci_ch_mappping[i].ccmni_ch_dl_ack;
        p_ccmni->dev[i].ccci_ch.ccmni_ch_ul_ack     = g_ccmni_ccci_ch_mappping[i].ccmni_ch_ul_ack;
        p_ccmni->dev[i].ccci_ch.ccmni_ch_dlack_ul   = g_ccmni_ccci_ch_mappping[i].ccmni_ch_dlack_ul; 
        p_ccmni->dev[i].ul_invalid_cnt = 0;
        /* 20130813 maintain the ccmni to ulq mapping */
        p_ccmni->dev[i].ulq.ccmni_normal_ulq        = g_ccmni_ulq_mappping[i].ccmni_normal_ulq;
        p_ccmni->dev[i].ulq.ccmni_ack_ulq           = g_ccmni_ulq_mappping[i].ccmni_ack_ulq;
        p_ccmni->dev[i].sw_tput_throttling_support  = g_sw_throughput_throttling_support[i];
#ifdef _CCMNI_CCCI_SEQ_NO_
        p_ccmni->dev[i].rx_seq_no[0] = 0;
        p_ccmni->dev[i].rx_seq_no[1] = 0;
#endif
    }
    
    /* 20130813 split HIF UL QBM pool */
    for(i = CCMNI_DEV_CCMNI1; i<CCMNI_DEV_CNT ; i++){
        p_ccmni->ulq[i].hwo_rgpd_cnt = 0;
    }
    p_ccmni->ulq[CCMNI_ULQ_T_NORMAL].ul_qbm_type      = QBM_TYPE_HIF_UL_TYPE;
    p_ccmni->ulq[CCMNI_ULQ_T_NORMAL].max_hwo_rgpd_cnt = QBM_NUM_HIF_UL_TYPE_IN_HIF;
    p_ccmni->ulq[CCMNI_ULQ_T_ACK].ul_qbm_type         = QBM_TYPE_HIF_UL_TYPE_S;
    p_ccmni->ulq[CCMNI_ULQ_T_ACK].max_hwo_rgpd_cnt    = QBM_NUM_HIF_UL_TYPE_S_IN_HIF;
    p_ccmni->ulq[CCMNI_ULQ_MISC].ul_qbm_type          = QBM_TYPE_HIF_UL_TYPE_02;
    p_ccmni->ulq[CCMNI_ULQ_MISC].max_hwo_rgpd_cnt     = QBM_NUM_HIF_UL_TYPE_02_IN_HIF;
    
#ifdef __IPCORE_SUPPORT__    
    p_ccmni->ipc_attach         = ipc_attach;
    p_ccmni->ipc_detach         = ipc_detach;
    p_ccmni->ipc_uplink         = ipc_uplink;
    p_ccmni->ipc_get_ip_id      = ipc_get_ip_id;
#else
    p_ccmni->ipc_attach         = _ccmni_fake_ipc_attach;
    p_ccmni->ipc_detach         = _ccmni_fake_ipc_detach;
    p_ccmni->ipc_uplink         = _ccmni_fake_ipc_uplink;
    p_ccmni->ipc_get_ip_id      = _ccmni_fake_ipc_get_ip_id;
#endif
    p_ccmni->free_gpd_list      = qbmt_dest_q;
    p_ccmni->ccci_write_gpd     = ccci_write_gpd;
    p_ccmni->ccci_init_gpdior   = ccci_init_gpdior;
    p_ccmni->ccci_deinit        = ccci_deinit;

    for(i = 0; i < CCMNI_DEV_CNT; i++){
        ccmni_dev_main_init(i);
    }
    qbm_reg_cbk_notify_pool_status(ccmni_qbm_pool_status_cb);
#if (defined(__CCMNI_LB_IT__) || defined(__CCMNI_IT__))
    ccmni_it_init();
#endif

    return KAL_TRUE;
}

/*!
 * @function        ccmni_main
 * @brief           the ilm handler for CCMNI, used by cccidev_task_main.cccidev_ilm_func_list_g
 *
 * @param ilm       pointer to ilm_struct
 *
 * @return          void
 */  
#ifdef __CCMNI_IT__ 
extern kal_bool ccmni_reload_retry;
#endif
void ccmni_main(ilm_struct *ilm)
{

    switch (ilm->msg_id) {
#ifdef __IPCORE_SUPPORT__
        case MSG_ID_IPCORE_LINK_UP_REQ:
#else
        /* for the IT case that doesn't have IPcore enable*/
        /* Target linkup should issued by IPCore */
        case MSG_ID_CCMNI_LINK_UP_REQ: 
#endif
        {
           ipc_link_req_t* link_req = (ipc_link_req_t*)ilm->local_para_ptr;
           ccmni_device_t* pDevice = (ccmni_device_t*) link_req->callback_context;
           ccmni_on_dev_event(pDevice, CCMNI_EVT_LINK_UP);
           break;
        }
#ifdef __IPCORE_SUPPORT__
        case MSG_ID_IPCORE_LINK_DOWN_REQ:
#else
        /* for the IT case that doesn't have IPcore enable*/
        /* Target linkup should issued by IPCore */
        case MSG_ID_CCMNI_LINK_DOWN_REQ: /* for the IT case that doesn't have IPcore enable*/
#endif
        {
           ipc_link_req_t* link_req = (ipc_link_req_t*)ilm->local_para_ptr;
           ccmni_device_t* pDevice = (ccmni_device_t*) link_req->callback_context;
           ccmni_on_dev_event(pDevice, CCMNI_EVT_LINK_DOWN);
           break;
         }
        case MSG_ID_CCMNI_SESSION_INIT_REQ:
        {
            ccmni_inst_t        *p_ccmni =  ccmni_get_instance();
            ccmni_init_req_t    *hmu_init_req   = (ccmni_init_req_t*)ilm->local_para_ptr;
            kal_uint32          dev_index       =  hmu_init_req->dev_indx;
            ccmni_on_dev_event(&p_ccmni->dev[dev_index], CCMNI_EVT_FUNC_ENABLE);
            break;
        }
        case MSG_ID_CCMNI_SESSION_DEINIT_REQ:
        {
            ccmni_inst_t        *p_ccmni =  ccmni_get_instance();
            ccmni_init_req_t    *hmu_init_req   = (ccmni_init_req_t*)ilm->local_para_ptr;
            kal_uint32          dev_index       =  hmu_init_req->dev_indx;
            ccmni_on_dev_event(&p_ccmni->dev[dev_index], CCMNI_EVT_FUNC_DISABLE);
            break;
        }
#ifdef __CCMNI_IT__         
        case MSG_ID_CCMNI_RETRY_UL_RELOAD_REQ:
        {
            ccmni_inst_t        *p_ccmni =  ccmni_get_instance();
            ccmni_device_t      *pDevice;
            kal_uint32          idx;
            kal_uint32          mask;
            static kal_uint32   reload_idex = 0;
            for(idx = 0; idx < CCMNI_DEV_CNT; idx ++){
                pDevice = &p_ccmni->dev[(idx+reload_idex)%CCMNI_DEV_CNT];
                if(KAL_TRUE == pDevice->dev_reload_retry){
                    pDevice->dev_reload_retry = ccmni_reload_ul_gpds(pDevice);
                }
                
            }
            CCMNI_DEV_LOCK(mask);
            reload_idex = (reload_idex+ 1)%CCMNI_DEV_CNT;
            ccmni_reload_retry = KAL_FALSE;
            CCMNI_DEV_UNLOCK(mask);
            break;
        }
#endif        
    default:
        ccmni_trace(CCMNI_ERR, CCMNI_MOD_SM, CCMNI_TR_SM_UNHANDLED_MSG, ilm->msg_id);
        break;
    }
}
