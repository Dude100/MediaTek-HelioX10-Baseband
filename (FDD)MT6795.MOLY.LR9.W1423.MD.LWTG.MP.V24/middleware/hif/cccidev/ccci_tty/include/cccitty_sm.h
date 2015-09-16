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
 *   cccitty_sm.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Header file for CCCI TTY state machine
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
 * add ICUSB feature, compile option = ICUSB_SUPPORT
 *
 *
 * removed!
 * removed!
 * checkin supporting buffer port features
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#ifndef _CCCITTY_SM_H
#define _CCCITTY_SM_H
#include "dcl.h"
#include "ccci_if.h"

/*!
 *  @brief CCCI_TTY_DEV_CNT defines the total number of CCCI_TTY devices
 */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
typedef enum _cccitty_device_id {
    CCCI_TTY_DEV_MIN           = 0,
    CCCI_TTY_DEV_DHL           = 0,  //4 <ccci ch> CCCI_DHL_CHANNEL
    CCCI_TTY_DEV_TST           = 1,  //4 <ccci ch> CCCI_TST_CHANNEL
    CCCI_TTY_DEV_AT            = 2,  //4 <ccci ch> CCCI_AT_CHANNEL_TX
    CCCI_TTY_DEV_GPD           = 3,  //4 <ccci ch> CCCI_GPS_CHANNEL_TX
    CCCI_TTY_DEV_IMSCTRL       = 4,  //4 <ccci ch> CCCI_ARM7_IMSCTRL_TX [TBD]
    CCCI_TTY_DEV_SIM           = 5,  //4 <ccci ch> CCCI_SIM_CHANNEL_TX
    CCCI_TTY_DEV_CNT           = 5
}cccitty_device_id;
#endif
typedef enum _cccitty_dev_state {
    CCCI_TTY_DEV_DETACHED,         /* Device hasn't initialized yet*/
    CCCI_TTY_DEV_ATTACHED,         /* HMU init make this device attache to TTYCore*/
    CCCI_TTY_DEV_CLOSE,            /* CCCI_TTY dev attached to TTYCore but not receive SIO_CMD_OPEN yet */
    CCCI_TTY_DEV_OPEN,             /* TTYCore sent SIO_CMD_OPEN, ready to do Tx/Rx*/
    CCCI_TTY_DEV_STATE_CNT
}cccitty_dev_state;

typedef enum _cccitty_dev_event {
    CCCI_TTY_EVT_FUNC_ENABLE,        /* Enable CCCI_TTY dev from HMU*/
    CCCI_TTY_EVT_FUNC_DISABLE,       /* Disable CCCI_TTY dev from HMU*/
    CCCI_TTY_EVT_SIO_OPEN,           /* User request COM port open, SIO_CMD_OPEN */
    CCCI_TTY_EVT_SIO_CLOSE,          /* User request COM port close, SIO_CMD_CLOSE */
    CCCI_TTY_EVT_CNT,
    CCCI_TTY_EVT_DUMMY = 0x7fff /* Make it a 2-byte enum */
}cccitty_dev_event;

typedef struct _ccci_ch_id_t {
    CCCI_CHANNEL_T      cccitty_ch_dl;
    CCCI_CHANNEL_T      cccitty_ch_ul;
    CCCI_CHANNEL_T      cccitty_ch_dl_ack;
    CCCI_CHANNEL_T      cccitty_ch_ul_ack;
    kal_uint32          cccitty_ch_ul_ttl_hif_rgpd_cnt;
} ccci_ch_id_t;

typedef struct _cccitty_dev_t
{
    cccitty_dev_state   state;                  /* CCCI_TTY device state*/
    module_type         module_id;              /* MOD_CCCITTY, module_id for identify the cccidev context */
    cccitty_device_id   dev_id;                 /* used to identify CCCI_TTY dev id when receiving ilm*/
    ccci_ch_id_t        ccci_ch;                /* the ccci channels this dev is attached to */
    kal_bool            dev_ul_processing;      /* KAL_TRUE: at leate one MSG_ID_CCCI_TTY_UL_DEQUEUE_REQ is pending for processing
    
                                                   KAL_FALSE: need to send MSG to wake up MODE_CCCIDEV to process ul request*/ 

    kal_enhmutexid      cccitty_mutex;
    /* TTY */
    module_type         ownerid;                /* TTY ownerid. */
    DCL_HANDLE          tty_handler;            /* TTY handler. */
    DCL_BOOL            tty_need_tx_done_cb;    /* TTY need_tx_done_cb flag. */
    UART_CONFIG_T       dcb;

    /* TTYCore/User layer RGPD queue */
    qbm_gpd*            ttyc_rgpd_q_h;          /* Queue for TTYCore/User to reload RGPD */
    qbm_gpd*            ttyc_rgpd_q_t;          /* Queue for TTYCore/User to reload RGPD */
    kal_uint32          ttyc_rgpd_cnt;          /* Number of RGPD in Queue */
    qbm_type            ttyc_rgpd_type;         /* Reload RGPD_TYPE */
    kal_bool            ttyc_rgpd_first_reload; /* KAL_TRUE: need to do hif_ul_rgpd reload, KAL_FALSE: alreadt initlized hif_ul_rgpd reload*/

    /* HIF layer UL RGPD queue */
    qbm_gpd*            hif_ul_q_h;             /* Queue for receiving HIF RGPD */
    qbm_gpd*            hif_ul_q_t;             /* Queue for receiving HIF RGPD */
    kal_uint32          hif_ul_rgpd_cnt;        /* Number of RGPD in Queue */
    qbm_type            hif_ul_rgpd_type;       /* HIF RGPD_TYPE = QBM_TYPE_CCCI_COMM */
    kal_uint32          hif_ul_ttl_rgpd_cnt;    /* Pre-defined total HIF RGPD count */
    
    /* DEBUG info */
    kal_int32           hwo_rgpd_cnt;           /* [Debug Info] number of RGPD own by the HIF protected by CCCI_TTY_LOCK */
                                                /* if hwo_rgpd_cnt < 1 (num_of_tail_rgpd) means device use other devices' RGPD */ 
    kal_uint32          ul_invalid_ttl_cnt;     /* [Debug Info] number of invalid RGPDs received */
} cccitty_dev_t;

typedef struct _cccitty_inst_t {
    /* <CCCI_TTY device handles> */
    cccitty_dev_t       dev[CCCI_TTY_DEV_CNT];
    /* <TTYCore released APIs> */
    DCL_HANDLE          (*dcl_open)(DCL_DEV dev, DCL_FLAGS flags);                             /* DclSerialPort_Open */
    DCL_STATUS          (*dcl_regcb)(DCL_HANDLE handle, Seriport_HANDLER_T* seriport_handler);  /* DclSerialPort_DrvRegisterCb */
    DCL_STATUS          (*dcl_attach)(DCL_HANDLE handle);                                      /* DclSerialPort_DrvAttach */
    DCL_STATUS          (*dcl_detach)(DCL_HANDLE handle);                                      /* DclSerialPort_DrvDetach */
    DCL_STATUS          (*dcl_txdone)(DCL_HANDLE handle, module_type source_id, void *tx_ior); /* DclSerialPort_DrvTxDone */
    DCL_STATUS          (*dcl_rx)(DCL_HANDLE handle, module_type source_id, void *rx_ior);     /* DclSerialPort_DrvRx */
    /* <CCCI released APIs> */
    kal_int32           (*ccci_write_gpd)(CCCI_CHANNEL_T channel, ccci_io_request_t *p_ccci_DL_ior, ccci_io_ext_info_t* pextinfo);
    kal_int32           (*ccci_init_gpdior)(CCCI_CHANNEL_T channel, CCCI_IORCALLBACK ior_funp);
    kal_int32           (*ccci_deinit)(CCCI_CHANNEL_T channel);
    // TODO: ccci_write_gpd_ext

} cccitty_inst_t;

typedef struct _cccitty_debug_status_t
{
    cccitty_dev_state   state; 
    cccitty_device_id   dev_id;  
    kal_bool            dev_ul_processing;
    module_type         ownerid;
    kal_uint32          ttyc_rgpd_cnt;          
    kal_bool            ttyc_rgpd_first_reload;      
    kal_uint32          hif_ul_rgpd_cnt;        
    kal_int32           hwo_rgpd_cnt;   
}cccitty_debug_status_t;

typedef struct _cccitty_init_req_t {
    LOCAL_PARA_HDR
    kal_uint32         dev_indx;
} cccitty_init_req_t;

typedef struct _cccitty_deq_req_t {
    LOCAL_PARA_HDR
    cccitty_dev_t       *dev;
} cccitty_deq_req_t;

/*!
 * @function        [Macro] cccitty_get_dev_state
 * @brief           Obtain the CCCI_TTY device state 
 *
 * @param gpd       [IN] pointer to the CCCI_TTY device, cccitty_dev_t
 *
 * @return          Return (cccitty_dev_state) dev->state
 */
#define cccitty_get_dev_state(_dev) (_dev)->state
#define cccitty_dev_active(_dev) (CCCI_TTY_DEV_OPEN == cccitty_get_dev_state(_dev))

kal_bool cccitty_session_init(cccitty_dev_t *dev);
kal_bool cccitty_session_deinit(cccitty_dev_t *dev);
kal_bool cccitty_session_close(cccitty_dev_t *dev);
cccitty_inst_t* cccitty_get_instance();
cccitty_dev_t* cccitty_get_dev_instance(cccitty_device_id devid);
cccitty_dev_state cccitty_on_dev_event(cccitty_dev_t *dev, cccitty_dev_event event);
cccitty_device_id cccitty_get_ul_devid(CCCI_CHANNEL_T ccci_ul_ch);
cccitty_device_id cccitty_get_dl_devid(CCCI_CHANNEL_T ccci_dl_ch);

#endif //#ifndef _CCCITTY_SM_H
