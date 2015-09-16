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
 *   cccitty_sm.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Implements the CCCI TTY state machine
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
 * 	Add cccitty sequence support(Merging from MP5 CL:641385 to MP6)
 *
 * removed!
 * removed!
 * 	add cccitty sequence support and status update support
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
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * [CCCITTY] support for CCIFTTY
 *
 * removed!
 * removed!
 * checkin supporting buffer port features
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#include "cccitty_common.h"
#include "cccitty_sm.h"
#include "cccitty_data.h"
#include "cccitty_hdr.h"
#include "cccitty_if.h"
#include "syscomp_config.h"
#include "kal_public_api.h"

typedef kal_bool (*cccitty_dev_sm_action_t)(cccitty_dev_t *dev);
typedef struct _cccitty_dev_sm_entry_t {
    cccitty_dev_event         event;
    cccitty_dev_state         new_state;
    cccitty_dev_sm_action_t   pre_action; /* action b4 state change*/
    cccitty_dev_sm_action_t   post_action;/* action after state change*/
} cccitty_dev_sm_entry_t;

Seriport_HANDLER_T  Uart_CCCI_Drv_Handler = {DCL_UART_CCCI_TYPE, cccitty_ttyc_hdr};
/*------------------------------------------------------------------------------
 * Private variables.
 *----------------------------------------------------------------------------*/
#define CCCITTY_INVALID_CH CCCI_MAX_CHANNEL
static ccci_ch_id_t g_cccitty_ccci_ch_mappping[CCCI_TTY_DEV_CNT] = {
    /*{dl, ul, dl_ack, ul_ack}*/
    {CCCI_MD_LOG_RX,      CCCI_MD_LOG_TX,      CCCITTY_INVALID_CH,      CCCITTY_INVALID_CH,  CCCI_TTY_DHL_TTL_RGPD_CNT},     /*uart_port_dhl_ccci*/
    {CCCI_TST_CHANNEL,    CCCI_TR_CHANNEL,     CCCI_TST_ACK_CHANNEL,    CCCI_TR_ACK_CHANNEL, CCCI_TTY_TST_TTL_RGPD_CNT},     /*uart_port_tst_ccci*/
    {CCCI_AT_CHANNEL_TX,  CCCI_AT_CHANNEL_RX,  CCCI_AT_ACK_CHANNEL_TX,  CCCI_AT_ACK_CHANNEL_RX, CCCI_TTY_AT_TTL_RGPD_CNT},   /*uart_port_at_ccci*/
    {CCCI_GPS_CHANNEL_TX, CCCI_GPS_CHANNEL_RX, CCCI_GPS_ACK_CHANNEL_TX, CCCI_GPS_ACK_CHANNEL_RX, CCCI_TTY_GPS_TTL_RGPD_CNT}, /*uart_port_gps_ccci*/	
    {CCCI_SIM_CHANNEL_TX, CCCI_SIM_CHANNEL_RX, CCCITTY_INVALID_CH     , CCCITTY_INVALID_CH, CCCI_TTY_SIM_TTL_RGPD_CNT},      /*uart_port_sim_ccci*/
    // TODO: add imsctrl while requested, uart_port_imsctrl_ccci 
//    {CCCI_GPS_CHANNEL_TX, CCCI_GPS_CHANNEL_RX, CCCI_GPS_ACK_CHANNEL_TX, CCCI_GPS_ACK_CHANNEL_RX, CCCI_TTY_IMS_TTL_RGPD_CNT}, /*uart_port_gps_ccci*/
};

/*
 * CCCI_TTY global handle, use cccitty_get_instance to obtain the instance.
 */
static cccitty_inst_t g_cccittydev_int;

static cccitty_debug_status_t g_cccittydbg_status[CCCI_TTY_DEV_CNT];
/*
 * State machine for CCCI_TTY_DEV_DETACHED state.
 */
static cccitty_dev_sm_entry_t cccitty_detach_state_machine_s[] = {
    /* {event, new_state, pre-action, post_action} */
    {CCCI_TTY_EVT_FUNC_ENABLE,     CCCI_TTY_DEV_ATTACHED,    cccitty_session_init, NULL}, /* by hmu_init */
    {CCCI_TTY_EVT_FUNC_DISABLE,    CCCI_TTY_DEV_DETACHED,    NULL, NULL}, /* Do nothing. */
    {CCCI_TTY_EVT_DUMMY,           CCCI_TTY_DEV_DETACHED,    NULL, NULL}  /* End of the state machine. */
    };

/*
 * State machine for CCCI_TTY_DEV_ATTACHED state.
 */
static cccitty_dev_sm_entry_t cccitty_attach_state_machine_s[] = {
    /* {event, new_state, pre-action, post_action} */
    {CCCI_TTY_EVT_FUNC_DISABLE,    CCCI_TTY_DEV_DETACHED,    cccitty_session_deinit, NULL}, /* by hmu_deinit. */
    {CCCI_TTY_EVT_SIO_OPEN,        CCCI_TTY_DEV_OPEN,        NULL, NULL}, /* Do nothing. */
    {CCCI_TTY_EVT_SIO_CLOSE,       CCCI_TTY_DEV_ATTACHED,    NULL, NULL}, /* Do nothing. */
    {CCCI_TTY_EVT_DUMMY,           CCCI_TTY_DEV_ATTACHED,    NULL, NULL}  /* End of the state machine. */
    };

/*
 * State machine for CCCI_TTY_DEV_CLOSE state.
 */
static cccitty_dev_sm_entry_t cccitty_close_state_machine_s[] = {
    /* {event, new_state, pre-action, post_action} */
    {CCCI_TTY_EVT_FUNC_DISABLE,    CCCI_TTY_DEV_DETACHED,    cccitty_session_deinit, NULL}, /* Do nothing. */
    {CCCI_TTY_EVT_SIO_OPEN,        CCCI_TTY_DEV_OPEN,        NULL, NULL}, /* Do nothing. */
    {CCCI_TTY_EVT_SIO_CLOSE,       CCCI_TTY_DEV_CLOSE,       NULL, NULL}, /* Do nothing. */
    {CCCI_TTY_EVT_DUMMY,           CCCI_TTY_DEV_CLOSE,       NULL, NULL}  /* End of the state machine. */
    };

/*
 * State machine for CCCI_TTY_DEV_OPEN state.
 */
static cccitty_dev_sm_entry_t cccitty_open_state_machine_s[] = {
    /* {event, new_state, pre-action, post_action} */
    {CCCI_TTY_EVT_FUNC_DISABLE,    CCCI_TTY_DEV_DETACHED,    cccitty_session_deinit, NULL}, /* by TTYCore. */
    {CCCI_TTY_EVT_SIO_OPEN,        CCCI_TTY_DEV_OPEN,        NULL, NULL}, /* Do nothing.. */
    {CCCI_TTY_EVT_SIO_CLOSE,       CCCI_TTY_DEV_CLOSE,       NULL, NULL}, /* Do nothing.. */
    {CCCI_TTY_EVT_DUMMY,           CCCI_TTY_DEV_OPEN,        NULL, NULL}  /* End of the state machine. */
    };

static cccitty_dev_sm_entry_t *cccitty_dev_state_machines_s[CCCI_TTY_DEV_STATE_CNT] = {
    cccitty_detach_state_machine_s,       /* CCCI_TTY_DEV_DETACHED */
    cccitty_attach_state_machine_s,       /* CCCI_TTY_DEV_ATTACHED */
    cccitty_close_state_machine_s,        /* CCCI_TTY_DEV_CLOSE */
    cccitty_open_state_machine_s          /* CCCI_TTY_DEV_OPEN */
    };
/*!
 * @function        cccitty_set_dev_state
 * @brief           function to set the CCCI_TTY state with thread protection. 
 *
 * @param dev       [IN] pointer to CCCI_TTY device
 * @param state     [IN] new state
 *
 * @return          void
 */
void cccitty_set_dev_state(cccitty_dev_t *dev, cccitty_dev_state state)
{
    ASSERT(dev);
    if (KAL_FALSE == kal_query_systemInit()){
        CCCI_TTY_LOCK(dev->cccitty_mutex);
    }
    dev->state = state;
    if (KAL_FALSE == kal_query_systemInit()){
        CCCI_TTY_UNLOCK(dev->cccitty_mutex);
    }
}

/*!
 * @function        cccitty_on_dev_event
 * @brief           CCCI_TTY even handler, which adjust the state and called the correspoind function in cccitty_dev_state_machines_s
 *
 * @param dev       [IN] pointer to CCCI_TTY device
 * @param event     [IN] event received
 *
 * @return          returns the new state, cccitty_dev_state
 */
cccitty_dev_state cccitty_on_dev_event(cccitty_dev_t *dev, cccitty_dev_event event)
{
    cccitty_dev_sm_entry_t  *state_machine;
    cccitty_dev_sm_entry_t  *entry;
    kal_uint32              idx;
    cccitty_dev_state       old_state;
    cccitty_dev_state       new_state;
    kal_bool                ret;

    ASSERT(dev);
    ASSERT(dev->dev_id < CCCI_TTY_DEV_CNT);
    ASSERT((kal_uint16)event <= (kal_uint16)CCCI_TTY_EVT_CNT);

    old_state = cccitty_get_dev_state(dev);
    new_state = old_state;
    state_machine =  cccitty_dev_state_machines_s[old_state];

    for (idx = 0; idx < CCCI_TTY_EVT_CNT; idx++) { 
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
            cccitty_trace(CCCI_TTY_INFO, CCCI_TTY_MOD_SM, CCCI_TTY_TR_SM_VALID_EVENT, dev->dev_id, old_state, event, new_state);
            cccitty_set_dev_state(dev, new_state);
            //4 <3> process post_action after state changed
            if (entry->post_action) {
                ret = entry->post_action(dev);
                ASSERT(KAL_TRUE == ret);
            }
            ASSERT(new_state == cccitty_get_dev_state(dev));
            break;
        } else if (CCCI_TTY_EVT_DUMMY == entry->event) {
            /*It's an unexpected event for this state.*/
            cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_SM, CCCI_TTY_TR_SM_INVALID_EVENT, dev->dev_id, old_state, event);
            ASSERT(KAL_FALSE);
            break;
        }
    }
    return new_state;
}

/*!
 * @function        cccitty_get_instance
 * @brief           obtain the CCCI_TTY instance
 *
 * @return          pointer of CCCI_TTY instance, g_cccittydev_int
 */
cccitty_inst_t* cccitty_get_instance()
{

    return &g_cccittydev_int;
}

/*!
 * @function        cccitty_get_dev_instance
 * @brief           obtain the CCCI_TTY device instance
 *
 * @return          pointer of CCCI_TTY instance, g_cccittydev_int
 */
cccitty_dev_t* cccitty_get_dev_instance(cccitty_device_id devid)
{

    ASSERT((devid >= CCCI_TTY_DEV_MIN) && (devid < CCCI_TTY_DEV_CNT));
    return &g_cccittydev_int.dev[devid];
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
#endif

/*!
 * @function        cccitty_get_ul_devid
 * @brief           obtain the cccitty_device_id from uplink ccci channel, used in uplink data handling
 *
 * @return          cccitty_device_id
 */
cccitty_device_id cccitty_get_ul_devid(CCCI_CHANNEL_T ccci_ul_ch){
    kal_uint32 dev_idx = 0;

    ASSERT(ccci_ul_ch < CCCI_MAX_CHANNEL);
    
    for(dev_idx = 0; dev_idx < CCCI_TTY_DEV_CNT; dev_idx++){
        if(g_cccitty_ccci_ch_mappping[dev_idx].cccitty_ch_ul == ccci_ul_ch){
            break;
        }
    }

    if(CCCI_TTY_DEV_CNT == dev_idx){
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_UL, CCCI_TTY_TR_UL_CCCICH_ERR, ccci_ul_ch);
    }

    return dev_idx;
}

/*!
 * @function        cccitty_get_dl_devid
 * @brief           obtain the cccitty_device_id from downlink ccci channel, used in downlink Tx done data handling
 *
 * @return          cccitty_device_id
 */
cccitty_device_id cccitty_get_dl_devid(CCCI_CHANNEL_T ccci_dl_ch){
    kal_uint32 dev_idx = 0;

    ASSERT(ccci_dl_ch < CCCI_MAX_CHANNEL);
    
    for(dev_idx = 0; dev_idx < CCCI_TTY_DEV_CNT; dev_idx++){
        if(g_cccitty_ccci_ch_mappping[dev_idx].cccitty_ch_dl == ccci_dl_ch){
            break;
        }
    }

    if(CCCI_TTY_DEV_CNT == dev_idx){
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_DL, CCCI_TTY_TR_DL_CCCICH_ERR, ccci_dl_ch);
    }

    return dev_idx;
}

/*!
 * @function        cccitty_task_init
 * @brief           initial function for CCCI_TTY, called by cccidev_task_main.cccidev_init_func_list_g
 *
 * @param type      Reserved
 *
 * @return          KAL_TRUE
 */ 
kal_bool cccitty_task_init(void)
{
    cccitty_inst_t*     p_cccitty = cccitty_get_instance();
    kal_uint32          i;
    kal_char            cccitty_mutex_name[50];
    

    for(i = 0; i<CCCI_TTY_DEV_CNT ; i++){
        p_cccitty->dev[i].state = CCCI_TTY_DEV_DETACHED;
        p_cccitty->dev[i].module_id = MOD_CCCITTY;
        p_cccitty->dev[i].dev_id = i;  /* assigned accumulated by cccitty_device_id */
        p_cccitty->dev[i].dev_ul_processing = KAL_FALSE;
        sprintf(cccitty_mutex_name, "CCCITTY_MUTEX%d", i);
        p_cccitty->dev[i].cccitty_mutex = kal_create_enh_mutex(cccitty_mutex_name);
        if (p_cccitty->dev[i].cccitty_mutex == NULL) {
            ASSERT(0);
        }
        p_cccitty->dev[i].ownerid = MOD_NIL;
        p_cccitty->dev[i].tty_need_tx_done_cb = DCL_FALSE; /* change to DCL_TRUE while receiving TTY_CMD_NEED_TX_DONE_CB*/
        p_cccitty->dev[i].ccci_ch.cccitty_ch_dl     = g_cccitty_ccci_ch_mappping[i].cccitty_ch_dl;
        p_cccitty->dev[i].ccci_ch.cccitty_ch_ul     = g_cccitty_ccci_ch_mappping[i].cccitty_ch_ul;
        p_cccitty->dev[i].ccci_ch.cccitty_ch_dl_ack = g_cccitty_ccci_ch_mappping[i].cccitty_ch_dl_ack;
        p_cccitty->dev[i].ccci_ch.cccitty_ch_ul_ack = g_cccitty_ccci_ch_mappping[i].cccitty_ch_ul_ack;
        /* initalize the rgpd queue */
        p_cccitty->dev[i].ttyc_rgpd_q_h = NULL;
        p_cccitty->dev[i].ttyc_rgpd_q_t = NULL;
        p_cccitty->dev[i].ttyc_rgpd_cnt = 0;
        p_cccitty->dev[i].ttyc_rgpd_type = CCCI_TTY_INVALID_GPD_TYPE; //assign an invalid, set according to 1st rgpd reload     
        p_cccitty->dev[i].ttyc_rgpd_first_reload = KAL_TRUE;
        /* initalize the rgpd queue */
        p_cccitty->dev[i].hif_ul_q_h = NULL;
        p_cccitty->dev[i].hif_ul_q_t = NULL;
        p_cccitty->dev[i].hif_ul_rgpd_cnt = 0;
        p_cccitty->dev[i].hif_ul_rgpd_type = CCCI_TTY_UL_BUF_TYPE; // this is the type CCCI_TTY  reload
        p_cccitty->dev[i].hif_ul_ttl_rgpd_cnt = g_cccitty_ccci_ch_mappping[i].cccitty_ch_ul_ttl_hif_rgpd_cnt; //CCCI_TTY_UL_BUF_CNT_1ST_RELOAD;
        
        p_cccitty->dev[i].hwo_rgpd_cnt = 0;
        p_cccitty->dev[i].ul_invalid_ttl_cnt = 0;

        
    }
#if defined(ATEST_SYS_CCCI_TTY)    
    //4 <For Normal Case>
    /* <TTYCore released APIs> */
    p_cccitty->dcl_open         = DclSerialPort_Open;
    p_cccitty->dcl_regcb        = DclSerialPort_DrvRegisterCb;
    p_cccitty->dcl_attach       = DclSerialPort_DrvAttach;
    p_cccitty->dcl_detach       = DclSerialPort_DrvDetach;
    p_cccitty->dcl_txdone       = DclSerialPort_DrvTxDone;
    p_cccitty->dcl_rx           = DclSerialPort_DrvRx;
    /* <CCCI released APIs> */
    p_cccitty->ccci_write_gpd   = ccci_write_gpd;
    p_cccitty->ccci_init_gpdior = ccci_init_gpdior;
    p_cccitty->ccci_deinit      = ccci_deinit;
#else
    //4 <For UT>
    /* <TTYCore released APIs> */
    p_cccitty->dcl_open         = DclSerialPort_Open;
    p_cccitty->dcl_regcb        = DclSerialPort_DrvRegisterCb;
    p_cccitty->dcl_attach       = DclSerialPort_DrvAttach;
    p_cccitty->dcl_detach       = DclSerialPort_DrvDetach;
    p_cccitty->dcl_txdone       = DclSerialPort_DrvTxDone;
    p_cccitty->dcl_rx           = DclSerialPort_DrvRx;
    /* <CCCI released APIs> */
    p_cccitty->ccci_write_gpd   = ccci_write_gpd;
    p_cccitty->ccci_init_gpdior = ccci_init_gpdior;
    p_cccitty->ccci_deinit      = ccci_deinit;

#endif

    for(i = 0; i<CCCI_TTY_DEV_CNT ; i++){
        cccitty_dev_init(CCCITTY_DEVID_TO_UARTP(i));
    }
    
    return KAL_TRUE;
}


/*************************************************************************
* FUNCTION
*  kal_uint32 cccitty_get_debug_status
*
* DESCRIPTION
*  Get CCCI tty debug status and write to the write_ptr
*
*
* PARAMETERS
*  write_ptr : the write address of CCCI debug status
*  available_size : the available size of CCCI debug status
* RETURNS
*  kal_uint32 : the used size of CCCI tty debug status
*
*************************************************************************/
kal_uint32 cccitty_get_debug_status(kal_uint32 *write_ptr, kal_uint32 available_size)
{
    kal_uint32 i;
    cccitty_inst_t*     p_cccitty = cccitty_get_instance();

    if(available_size < sizeof(g_cccittydbg_status))
    {
        return 0;
    }

    //reset first
    kal_mem_set(g_cccittydbg_status, 0, sizeof(g_cccittydbg_status));

    for(i = 0 ; i < CCCI_TTY_DEV_CNT; i++)
    {
        g_cccittydbg_status[i].state = p_cccitty->dev[i].state;
        g_cccittydbg_status[i].dev_id = p_cccitty->dev[i].dev_id;
        g_cccittydbg_status[i].ownerid = p_cccitty->dev[i].ownerid;
        g_cccittydbg_status[i].ttyc_rgpd_cnt = p_cccitty->dev[i].ttyc_rgpd_cnt;
        g_cccittydbg_status[i].ttyc_rgpd_first_reload = p_cccitty->dev[i].ttyc_rgpd_first_reload;
        g_cccittydbg_status[i].hif_ul_rgpd_cnt = p_cccitty->dev[i].hif_ul_rgpd_cnt;
        g_cccittydbg_status[i].hwo_rgpd_cnt = p_cccitty->dev[i].hwo_rgpd_cnt;
        g_cccittydbg_status[i].dev_ul_processing = p_cccitty->dev[i].dev_ul_processing;
    }

    kal_mem_cpy( (void*)write_ptr, (void*)&g_cccittydbg_status, sizeof(g_cccittydbg_status));
    
    return sizeof(g_cccittydbg_status); 
}

/*!
 * @function        cccitty_main
 * @brief           the ilm handler for CCCI_TTY, used by cccidev_task_main.cccidev_ilm_func_list_g
 *
 * @param ilm       pointer to ilm_struct
 *
 * @return          void
 */  
void cccitty_main(ilm_struct *ilm)
{

    switch (ilm->msg_id) {

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
        case MSG_ID_CCCI_TTY_UL_DEQUEUE_REQ:
        {
//            cccitty_inst_t      *p_cccitty =  cccitty_get_instance();
            cccitty_deq_req_t   *cccitty_deq_req   = (cccitty_deq_req_t*)ilm->local_para_ptr;
            cccitty_dev_t       *dev       =  cccitty_deq_req->dev;
            cccitty_ul_deq_hdr(dev);
            break;
        }
    default:
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_SM, CCCI_TTY_TR_SM_UNHANDLED_MSG, ilm->msg_id);
        break;
    }
}

/*!
 * @function        cccitty_session_init
 * @brief           init the ccci sessions, and reload the RGPDs, called during hmu_init
 *                  cccitty_hmu_init -> CCCI_TTY_EVT_FUNC_ENABLE -> cccitty_session_init
 *
 * @param dev       [IN] pointer to CCCI_TTY device
 *
 * @return          KAL_TRUE
 */
kal_bool cccitty_session_init(cccitty_dev_t *dev)
{
    kal_int32           ccci_ret;
    cccitty_inst_t      *p_cccitty = cccitty_get_instance();
    DCL_FLAGS           flags = FLAGS_NONE;
    DCL_STATUS          dcl_ret;
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

    ASSERT(dev->dev_id < CCCI_TTY_DEV_CNT);

    //4 <1> ccci_init_gpdior Tx/Rx ccci ch,  ASSERT if fail 
    ccci_ret = p_cccitty->ccci_init_gpdior(dev->ccci_ch.cccitty_ch_ul, cccitty_ccci_ul_cb);
    if(CCCI_SUCCESS != ccci_ret){
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_SM, CCCI_TTY_TR_CCCI_CH_INIT_FATAL_ERROR, dev->dev_id, ccci_ret); ASSERT(0); return KAL_FALSE;
    }
    ccci_ret = p_cccitty->ccci_init_gpdior(dev->ccci_ch.cccitty_ch_dl, cccitty_ccci_dl_cb);
    if(CCCI_SUCCESS != ccci_ret){
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_SM, CCCI_TTY_TR_CCCI_CH_INIT_FATAL_ERROR, dev->dev_id, ccci_ret); ASSERT(0); return KAL_FALSE;
    }
    if(CCCITTY_INVALID_CH != dev->ccci_ch.cccitty_ch_dl_ack){
        ccci_ret = p_cccitty->ccci_init_gpdior(dev->ccci_ch.cccitty_ch_dl_ack, cccitty_ccci_dummy_cb);
        if(CCCI_SUCCESS != ccci_ret){
            cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_SM, CCCI_TTY_TR_CCCI_CH_INIT_FATAL_ERROR, dev->dev_id, ccci_ret); ASSERT(0); return KAL_FALSE;
        }
    }
    if(CCCITTY_INVALID_CH != dev->ccci_ch.cccitty_ch_ul_ack){
        ccci_ret = p_cccitty->ccci_init_gpdior(dev->ccci_ch.cccitty_ch_ul_ack, cccitty_ccci_dummy_cb);
        if(CCCI_SUCCESS != ccci_ret){
            cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_SM, CCCI_TTY_TR_CCCI_CH_INIT_FATAL_ERROR, dev->dev_id, ccci_ret); ASSERT(0); return KAL_FALSE;
        }
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
#endif


    //4 <2> DclSerialPort_Open, reference cdcacm_ttyhdr_reg_ttycore    
    dev->tty_handler = p_cccitty->dcl_open((DCL_DEV)CCCITTY_DEVID_TO_UARTP(dev->dev_id), flags);
    ASSERT(STATUS_INVALID_DEVICE != dev->tty_handler);

    //4 <3> DclSerialPort_DrvRegisterCb

    dcl_ret = p_cccitty->dcl_regcb(dev->tty_handler, &Uart_CCCI_Drv_Handler);
    
#if defined(__CCCITTY_UT__)
    /* TTYCore not allow driver to register callback again even after detached*/
#else
    if (STATUS_OK != dcl_ret) {
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_SM, CCCI_TTY_TR_TTYC_INIT_FATAL_ERROR, dev->dev_id, dcl_ret); ASSERT(0); return KAL_FALSE;
    }
#endif

#if defined (__CCCITTY_EXCEPT_TODO__)//????
    // In exception mode, CDC-ACM may already register to TTY_CORE in normal path.
    if (KAL_TRUE == cdcacm_st_in_except_mode_g && STATUS_ALREADY_OPENED == dcl_ret) {
        return KAL_TRUE;
    }
#endif


    //4 <4> Initialize DCB, reference cdcacm_ttyhdr_cmd_init
    dcl_ret = cccitty_ttyc_hdr((DCL_DEV)CCCITTY_DEVID_TO_UARTP(dev->dev_id), SIO_CMD_INIT, NULL);
    ASSERT(STATUS_OK == dcl_ret);
#if 0 
/* under construction !*/
#endif

    //4 <5> DclSerialPort_DrvAttach
    dcl_ret = p_cccitty->dcl_attach(dev->tty_handler);
    if (STATUS_OK != dcl_ret) {
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_SM, CCCI_TTY_TR_TTYC_INIT_FATAL_ERROR, dev->dev_id, dcl_ret); ASSERT(0); return KAL_FALSE;
    }

    /*Register CCCI debug status call back function*/
    ccci_debug_get_status_register(CCCI_DEBUG_GET_STATUS_MODULE_CCCITTY, cccitty_get_debug_status);

    return KAL_TRUE;
}

/*!
 * @function        cccitty_session_deinit
 * @brief           deinit the ccci sessions, called during hmu_deinit
 *                  cccitty_hmu_deinit -> CCCI_TTY_EVT_FUNC_DISABLE -> cccitty_session_deinit
 *
 * @param dev       [IN] pointer to CCCI_TTY device
 *
 * @return          KAL_TRUE
 */
kal_bool cccitty_session_deinit(cccitty_dev_t *dev)
{
    cccitty_inst_t*       p_cccitty = cccitty_get_instance();

    //4 <1> dcl_detach
    p_cccitty->dcl_detach(dev->tty_handler);

    //4 <2> ccci_deinit
    p_cccitty->ccci_deinit(dev->ccci_ch.cccitty_ch_dl);
    p_cccitty->ccci_deinit(dev->ccci_ch.cccitty_ch_dl_ack);
    p_cccitty->ccci_deinit(dev->ccci_ch.cccitty_ch_ul_ack);
    p_cccitty->ccci_deinit(dev->ccci_ch.cccitty_ch_ul);
        
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
#endif
