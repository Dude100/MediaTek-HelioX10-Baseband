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
 *   ccmni_sm.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Header file for CCCI CCMNI state machine
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
 * 06 13 2014 ap.wang
 * removed!
 * Remove INITIALIZED state
 *
 * 05 14 2014 ap.wang
 * CCMNI Fast Ack Patch and linkdown fast reload
 *
 * removed!
 * 	[CCMNI ACK Fast Path]
 *
 * 01 10 2014 ap.wang
 * removed!
 * 	Fix IPv4/v6 linkdown issue
 *
 * removed!
 * removed!
 * [ccmni] split HIF UL QBM pool
 *
 * 03 27 2013 ap.wang
 * removed!
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
#ifndef _CCMNI_SM_H
#define _CCMNI_SM_H

#include "ccci_if.h"
#include "ipc_api.h"
#include "ccci_it_ctrl_if.h"

/*------------------------------------------------------------------------------
 * ENUMs
 *----------------------------------------------------------------------------*/
/*!
 *  @brief CCMNI_DEV_CNT defines the total number of CCMNI devices
 *         CCMNI1~3 for AP 
 */
typedef enum _ccmni_device_id {
    CCMNI_DEV_CCMNI1           = 0,  //4 <ccci ch> CCCI_CCMNI1_TX/RX
    CCMNI_DEV_CCMNI2           = 1,  //4 <ccci ch> CCCI_CCMNI2_TX/RX
    CCMNI_DEV_CCMNI3           = 2,  //4 <ccci ch> CCCI_CCMNI3_TX/RX
    CCMNI_DEV_CCMNI4           = 3,  //4 <ccci ch> CCCI_CCMNI4_TX/RX
    CCMNI_DEV_CCMNI5           = 4,  //4 <ccci ch> CCCI_CCMNI5_TX/RX
    CCMNI_DEV_CCMNI6           = 5,  //4 <ccci ch> CCCI_CCMNI6_TX/RX
    CCMNI_DEV_CCMNI7           = 6,  //4 <ccci ch> CCCI_CCMNI7_TX/RX
    CCMNI_DEV_CCMNI8           = 7,  //4 <ccci ch> CCCI_CCMNI8_TX/RX
    CCMNI_DEV_CNT              = 8   
} ccmni_device_id;

typedef enum _ccmni_ulq_id {
    CCMNI_ULQ_T_NORMAL         = 0,  
    CCMNI_ULQ_T_ACK            = 1,  //4 
    CCMNI_ULQ_MISC             = 2,  //4 
    CCMNI_ULQ_CNT              = 3   
} ccmni_ulq_id;

typedef enum _ccmni_dev_state {
    CCMNI_DEV_UNINITIALIZED,       /* Device hasn't initialized yet*/
    CCMNI_DEV_INITIALIZED,         /* INIT reuqest sent by HMU*/
    CCMNI_DEV_DISCONNECTED,        /* CCMNI dev has been disconnected from a IPcore session, MSG_ID_IPCORE_LINK_DOWN_REQ  */
    CCMNI_DEV_CONNECTED,           /* CCMNI dev has attached to a IPcore session, MSG_ID_IPCORE_LINK_UP_REQ */
    CCMNI_DEV_STATE_CNT
} ccmni_dev_state;

typedef enum _ccmni_dev_event {
    CCMNI_EVT_FUNC_ENABLE,        /* Enable CCMNI dev from HMU*/
    CCMNI_EVT_FUNC_DISABLE,       /* Disable CCMNI dev from HMU*/
    CCMNI_EVT_LINK_UP,            /* Network is connected, MSG_ID_IPCORE_LINK_UP_REQ, from IPcore */
    CCMNI_EVT_LINK_DOWN,          /* Network is disconnected, MSG_ID_IPCORE_LINK_DOWN_REQ, from IPcore */
    CCMNI_EVT_CNT,
    CCMNI_EVT_DUMMY = 0x7fff /* Make it a 2-byte enum */
} ccmni_dev_event;

typedef enum _ccmni_it_mode {
    CCMNI_IT_DISABLE = 0,
    CCMNI_IT_PING,         /* ICMP echo reply */ /* for PING test */
    CCMNI_IT_UDP_LB,       /* Loopback with src/dest IP swap */ /* for Iperf test*/
    CCMNI_IT_DL_UL,        /* Generate DL traffic while receiving UL, and drop UL packets */
    CCMNI_IT_PURE_LB,      /* Loopback without content change */
    CCMNI_IT_DL_ONLY,      /* Generate DL traffic in sdiocore, and drop UL packets */
    CCMNI_IT_DROP_UL,      /* Drop the packet immediately */
    CCMNI_IT_MODE_MAX                      
} ccmni_it_mode;


typedef enum _ccmni_it_msg {
    CCMNI_IT_DEVID_ERR = -1,
    CCMNI_IT_MODE_ERR = -2,
    CCMNI_IT_OP_ERR = -3,
    CCMNI_IT_NO_ERR = 0                      
} ccmni_it_msg;

typedef enum _ccmni_it_op {
    CCMNI_IT_READ_MODE = 1,
    CCMNI_IT_SET_MODE ,
    CCMNI_IT_OP_MAX                    
} ccmni_it_op;


/*------------------------------------------------------------------------------
 * Structures
 *----------------------------------------------------------------------------*/
typedef struct _ccci_ch_id_t {
    CCCI_CHANNEL_T      ccmni_ch_dl;
    CCCI_CHANNEL_T      ccmni_ch_ul;
    CCCI_CHANNEL_T      ccmni_ch_dl_ack;
    CCCI_CHANNEL_T      ccmni_ch_ul_ack;
    CCCI_CHANNEL_T      ccmni_ch_dlack_ul; /* fast path for dl ack */
} ccci_ch_id_t;

typedef struct _ccmni_ulq_id_t {
    ccmni_ulq_id      ccmni_normal_ulq;
    ccmni_ulq_id      ccmni_ack_ulq;
} ccmni_ulq_id_t;

typedef struct _ccmni_device_t {
    /* ccmni device state */
    ccmni_dev_state          state;
    /* for IPcore ipc_attach */
    module_type              module_id;
    /* used to identify CCMNI dev id when IPcore sent ilm*/
    ccmni_device_id          dev_id;
    /* the ipcore handle for the ipc_uplink callback*/
    ipc_handle_t             ipc_handle;
    /* the ccci channels this dev is attached to */
    ccci_ch_id_t             ccci_ch;
    ccmni_ulq_id_t           ulq;
    /* Debug Info: number of RGPDs is invalid */
    kal_uint32               ul_invalid_cnt;
    /* link up session count, for ipv4/ipv6/ipv4v6*/
    kal_int32               session_count;
#ifdef _CCMNI_CCCI_SEQ_NO_
    /* ALPS Rx sequence no check: 
        0: normal data channel sequence no check
        1: dlack channel sequence no check
     */
    kal_uint32  rx_seq_no[2]; 
#endif
#if (defined(__CCMNI_LB_IT__) || defined(__CCMNI_IT__))
    /* IT only: reload_retry flag.*/
    kal_bool                 dev_reload_retry;
    /* IT only: from IT mode switch*/
    ccmni_it_mode            it_mode;
#endif    
    /* sw_throughput_throttling_support */
    kal_bool                 sw_tput_throttling_support;
} ccmni_device_t;

/* 20140325 seperate ccmni ul queue for ack fast path */
typedef struct _ccmni_ulq_t {
    /* max number of RGPDs in HIF*/
    kal_int32                max_hwo_rgpd_cnt; 
    /* number of RGPD own by the HIF protected by CCMNI_DEV_LOCK/CCMNI_DEV_UNLOCK*/
    /* note this value doesn't impact by init/deinit/linkup/linkdown since NO FLUSH*/
    kal_int32                hwo_rgpd_cnt;         
    /* 20130813 split HIF UL QBM pool */    
    /* CCMNI UL QBM type */
    kal_uint32               ul_qbm_type;
} ccmni_ulq_t;
typedef struct _ccmni_inst_t {
    /* <CCMNI device handles> */
    ccmni_device_t      dev[CCMNI_DEV_CNT];
    /* <CCMNI> ulq handles> */
    ccmni_ulq_t         ulq[CCMNI_ULQ_CNT];
    /* <IPCore released APIs> */
    kal_bool            (*ipc_attach)(ipc_conf_t *config, ipc_handle_t* handle);
    kal_bool            (*ipc_detach)(ipc_handle_t handle);
    kal_bool            (*ipc_uplink)(ipc_handle_t handle, ipc_io_request_t *ior);
    kal_int32           (*ipc_get_ip_id)(ipc_handle_t handle);
    kal_uint32          (*free_gpd_list)(void *p_head, void *p_tail);
    /* <CCCI released APIs> */
    kal_int32           (*ccci_write_gpd)(CCCI_CHANNEL_T channel, ccci_io_request_t *p_ccci_DL_ior, ccci_io_ext_info_t* pextinfo);
    kal_int32           (*ccci_init_gpdior)(CCCI_CHANNEL_T channel, CCCI_IORCALLBACK ior_funp);
    kal_int32           (*ccci_deinit)(CCCI_CHANNEL_T channel);
} ccmni_inst_t;

typedef struct _ccmni_init_req_t {
    LOCAL_PARA_HDR
    kal_uint32         dev_indx;
} ccmni_init_req_t;


typedef struct _ccmni_dbg_status_t
{
    ccmni_dev_state state[CCMNI_DEV_CNT];
    kal_int32 session_count[CCMNI_DEV_CNT];
    kal_int32 max_hwo_rgpd_cnt[CCMNI_ULQ_CNT]; 
    kal_int32 hwo_rgpd_cnt[CCMNI_ULQ_CNT] ;
}ccmni_dbg_status_t;

/*------------------------------------------------------------------------------
 * Macors
 *----------------------------------------------------------------------------*/
/*!
 * @function        [Macro] ccmni_get_dev_state
 * @brief           Obtain the CCMNI device state 
 *
 * @param gpd       [IN] pointer to the CCMNI device, ccmni_device_t
 *
 * @return          Return (ccmni_dev_state) dev->state
 */
#define ccmni_get_dev_state(_dev) (_dev)->state
/*!
 * @function        [Macro] ccmni_dev_connected
 * @brief           Check if the CCMNI device state is connected
 *
 * @param gpd       [IN] pointer to the CCMNI device, ccmni_device_t
 *
 * @return          Return TRUE if device is connected, FALSE otherwise.
 */
#define ccmni_dev_connected(_dev) (CCMNI_DEV_CONNECTED == ccmni_get_dev_state(_dev))

extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32);
#define CCMNI_DEV_LOCK(_stack_var) _stack_var = SaveAndSetIRQMask()
#define CCMNI_DEV_UNLOCK(_stack_var) RestoreIRQMask(_stack_var)

/*------------------------------------------------------------------------------
 * Function definitions
 *----------------------------------------------------------------------------*/
ccmni_inst_t* ccmni_get_instance(void);
#ifdef __CCMNI_ACK_FAST_PATH__
kal_uint8 ccmni_is_dlack_ch(CCCI_CHANNEL_T ccci_ul_ch);
#endif
ccmni_device_id ccmni_get_ul_devid(CCCI_CHANNEL_T ccci_ul_ch);
kal_bool ccmni_session_deinit(ccmni_device_t *dev);
kal_bool ccmni_session_init(ccmni_device_t *dev);
kal_bool ccmni_session_linkup(ccmni_device_t *dev);
kal_bool ccmni_session_linkdown(ccmni_device_t *dev);    
ccmni_dev_state ccmni_on_dev_event(ccmni_device_t *dev, ccmni_dev_event event);

#endif //#ifndef _CCMNI_SM_H
