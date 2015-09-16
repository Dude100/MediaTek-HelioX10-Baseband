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
 *   ccci_if.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines the CCCI data structures and APIs
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
 * [CCCI IPC] Support Clibtime feature
 *
 * removed!
 * removed!
 * [CCCI FS] Support CCCI FS exception mode.
 *
 * removed!
 * removed!
 * [CCCI FS] Support CCCI FS exception mode.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * [CCCI] Fix Modis no share memory (connect ELT)
 *
 * removed!
 * removed!
 * [CCCI] CCCI new debug mechanism
 *
 * removed!
 * removed!
 * [CCCI] Add exception share memory size check.
 *
 * removed!
 * removed!
 * [CCCI] For SS debug info
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * [K2 MD2] Add CCCI/CCIF new feature for K2 MD2
 *
 * removed!
 * removed!
 * [CCCI] Provide CCCI direct write SM API
 *
 * removed!
 * removed!
 * [CCCI RPC] Debug enhancement & Add log.
 *
 * removed!
 * removed!
 * [CCCI] Provide CCCI writes ex_log_ptr to share memory API
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * [CCCI] Add exception debug info & boot trace.
 *
 * removed!
 * removed!
 * [CCCI] Add exception debug info & boot trace.
 *
 * removed!
 * removed!
 * [CCCI] Support CCCI MISC info.
 *
 * removed!
 * removed!
 * [CCCI] Support CCCI MISC info.
 *
 * removed!
 * removed!
 * 	[CCCI] CCCI MISC Info.
 *
 * removed!
 * removed!
 * 	1. revise ccci exception handshake I/O
 * 	2. add global variable state for debugging
 *
 * removed!
 * removed!
 * 	.
 *
 * 07 12 2013 ap.wang
 * removed!
 * [CCCI EXCEPTION] exception integration
 *
 * removed!
 * removed!
 * 1. add ccci system message integration test code
 * 2. move ccci_sysmsgsvc_conf.h to global interface
 *
 * 06 06 2013 ap.wang
 * removed!
 * [CCCI] Add ccci_register_sysmsgsvc_callback API
 *
 * 06 04 2013 ap.wang
 * removed!
 * Modify header file to include new CCCI header file for compatibility.
 * Add fake API
 *
 * removed!
 * removed!
 * a. Check-in cccifs new features (support 16KB I/O)
 * b. add __CCCIFS_SUPPORT__ option to related files
 *
 * removed!
 * removed!
 * [CCCI] CCCI/CLDMA INT
 *
 * 02 05 2013 ap.wang
 * removed!
 *
 * 01 16 2013 box.wu
 * removed!
 * integrate CCIF drv & CCIFCore from TATAKA.
 *
 * removed!
 * removed!
 * sync latest version of new features
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#ifndef _CCCI_IF_H
#define _CCCI_IF_H
#include "kal_public_api.h"
#include "hif_ior.h"
#include "qmu_bm.h"
#include "ccci_ch_cfg.h"

/*!
 *  @brief __CCCI_N_USE_TGPD_EXT__ 
 *           20120925 perfer to use TGPD extension for CCCI_HEADER
 *                    if defined __CCCI_N_USE_GPD_EXT__, use buff part.
 */
//#define __CCCI_N_USE_TGPD_EXT__

/*!
 *  @brief __CCCI_PERF_PROFILING__ 
 *           20120924 compile option for performance profiling
 */
//#define __CCCI_PERF_PROFILING__

/*!
 *  @brief __CCCI_LB_IT__ 
 *           20120805 compile option for Smartphone AP IT
 */
//#define __CCCI_LB_IT__ defined in hif_ccci.mak

/*!
 *  @brief __CCCI_GPD_LEAK_DBG__ debug for gpd leak
 *           20120604 solved the leak in HIF SDIO SIM
 */
//#define __CCCI_GPD_LEAK_DBG__

/*!
 *  @brief __SDIOC_PULL_Q_ENH_DL__ 
 *           20121001 enable this to enhance the hif poll DL queue performance
 *                    Do the poll queue only if the hwo gpd count > 0
 */
#define __SDIOC_PULL_Q_ENH_DL__ 

/*!
 *  @brief FS_CCCI_MAX_BUF_SIZE max buffer size of CCCI_FS
 *         Note: user cannot send/request buffer larger than this size
 *         (CCCI_Header) (FS_OP_ID) (ARGC) (MAX_ARG_NUM* Len) (MAX_ARG_NUM* value_len)(FS_BUFF)
 *         (16)          (4)        (4)    (6*4)              (6*4)                   (16KB)
 *         Tail buffer for 4B aligned: 128
 */
#define FS_CCCI_MAX_USER_BUFF           16384
#define FS_CCCI_REQ_BUFFER_NUM          5 /* support 5 concurrently request*/
#define FS_CCCI_MAX_ARG_NUM	            6 /* parameter number */
#define FS_CCCI_MAX_BUF_SIZE            (16+4+4+FS_CCCI_MAX_ARG_NUM*4*2+FS_CCCI_MAX_USER_BUFF+128)
#define FS_CCCI_POLLING_BUFF_SIZE       QBM_SIZE_CCCI_COMM

/*!
 *  @brief Current MT6280 design only defines 
 *            the max Tx/Rx GPD size as 4KB for non-network user
 *            the max Tx/Rx GPD size as 2KB for network user
 */
#define CCCI_UL_BUF_TYPE  QBM_TYPE_CCCI_COMM   // non-network user RGPD
#define CCCI_DL_BUF_TYPE  QBM_TYPE_CCCI_COMM   // non-network user TGPD, ccci_write won't flush data must bmcfg_cache_invalid(KAL_TRUE)

/*!
 *  @brief ccci_io_req_type_e Type of operation to for requests to submit to HIF.
 *  @param CCCI_IO_TX_NO_FLUSH                  Transmit operation without GPD checksum calcuation and cache flush.
 */
typedef enum _ccci_io_req_type {
     CCCI_IO_TX_NO_FLUSH        = 0x00000010,
     CCCI_IO_TYPE_DUMMY         = 0x7fffffff
} ccci_io_req_type_e;

/*!
 *  @brief ccci_io_ext_info_t Configurations apply to the requests to submit to HIF.
 *  @param type               Type of operation.
 */
typedef struct _ccci_io_ext_info {
     ccci_io_req_type_e   type;
} ccci_io_ext_info_t;

/*!
 *  @brief CCCI_MAILBOX_T CCCI mailbox channel structure struct
 */
typedef struct
{
    kal_uint32 magic;   /* 0xFFFFFFFF */
    kal_uint32 id;
} CCCI_MAILBOX_T;

/*!
 *  @brief CCCI_STREAM_T CCCI stream channel structure struct
 */
typedef struct
{
    kal_uint32 addr;
    kal_uint32 len;
} CCCI_STREAM_T;

/*!
 *  @brief CCCI_BUFF_T CCCI channel buffer structure struct
 */
typedef struct
{
    kal_uint32 data[2]; /* data[1]: length including the CCCI_BUFF_T*/
    kal_uint32 channel;
    kal_uint32 reserved;
} CCCI_BUFF_T;

/*!
 *  @brief CCCI_RETURNVAL_T CCCI API return value enum
 */
typedef enum
{
    CCCI_SUCCESS        = 0,
    CCCI_FAIL           = -1001,
    CCCI_IN_USE         = -1002,
    CCCI_NOT_OWNER      = -1003,
    CCCI_INVALID_PARAM  = -1004,
    CCCI_NO_PHY_CHANNEL = -1005,
    CCCI_IN_LISR        = -1006,
    CCCI_NO_DATA        = -1007
} CCCI_RETURNVAL_T;

/*!
 *  @brief CCCI_STATE_T CCCI status enum
 */
typedef enum
{
    CCCI_IDLE           = 0x00,
    CCCI_ACTIVE_READ    = 0x01,
    CCCI_ACTIVE_WRITE   = 0x02,
    CCCI_ACTIVE_ISR     = 0x04
} CCCI_STATE_T;

/*!
 *  @brief CCCI peer id enum for multi HIF
 */
typedef enum
{
	CCCI_PEER_ID_MIN	= 0,
// To AP HIF support
#if defined(__HIF_SDIO_SUPPORT__) || defined(__HIF_CLDMA_SUPPORT__) || defined(__HIF_WCCIF_SUPPORT__) || defined(ATEST_SYS_CCCI)
	CCCI_PEER_ID_AP_MD	= CCCI_PEER_ID_MIN,
#endif
// TODO: Need to confirm MD1 to MD2 HIF compile optioon
// MD1 & MD2 HIF support
#if defined(__HIF_WCCIF2_SUPPORT__) || defined(ATEST_SYS_CCCI)
	CCCI_PEER_ID_MD1_MD2,
#endif
	CCCI_PEER_ID_MAX,
} CCCI_PEER_ID_T;

#define PEER_ID_MASK 0xFF00 // each peer range 0x0~0xFF
#define PEER_CH_MASK 0x00FF // each channel range is 0x0~0xFF
#define CCCI_CH_MASK 0xFFFF

#define GET_PEER_ID(_ch) ((_ch & PEER_ID_MASK) >> 8 )
#define GET_PEER_CHANNEL(_ch) (_ch & PEER_CH_MASK)
#define GET_VIRTUAL_CHANNEL(_peer_id, _ch) ((_peer_id << 8) | _ch) // peer_id + channel
#define GET_CCCI_CHANNEL(_ch) (_ch & CCCI_CH_MASK)

/*!
 *  @brief CCCI_INIT_MAILBOX initialize a CCCI mailbox buffer
 */
#define CCCI_INIT_MAILBOX(buff, mailbox_id) \
        do {    \
            ((CCCI_MAILBOX_T *)(buff))->magic = 0xFFFFFFFF; \
            ((CCCI_MAILBOX_T *)(buff))->id = (mailbox_id);  \
            (buff)->channel = 0;  \
            (buff)->reserved = 0;    \
        } while (0)

/*!
 *  @brief CCCI_INIT_STREAM initialize a CCCI stream buffer
 */
#define CCCI_INIT_STREAM(buff, stream_addr, stream_len) \
        do {    \
            ((CCCI_STREAM_T *)(buff))->addr = (stream_addr); \
            ((CCCI_STREAM_T *)(buff))->len = (stream_len);  \
            (buff)->channel = 0;  \
            (buff)->reserved = 0;    \
        } while (0)
/*!
 *  @brief CCCI_IS_MAILBOX check the CCCI buffer type
 */
#define CCCI_IS_MAILBOX(buff)   ((((CCCI_MAILBOX_T *)(buff))->magic == 0xFFFFFFFF)? 1: 0)

/*!
 *  @brief CCCI_MAILBOX_ID get the id of the CCCI mailbox buffer
 */
#define CCCI_MAILBOX_ID(buff)   (((CCCI_MAILBOX_T *)(buff))->id)

/*!
 *  @brief CCCI_STREAM_ADDR get the addr of the CCCI stream buffer
 */
#define CCCI_STREAM_ADDR(buff)   (((CCCI_STREAM_T *)(buff))->addr)
/*!
 *  @brief CCCI_STREAM_LEN get the len of the CCCI stream buffer
 */
#define CCCI_STREAM_LEN(buff)   (((CCCI_STREAM_T *)(buff))->len)
/*!
 *  @brief CCCI_STREAM_SET_LEN get the len of the CCCI stream buffer
 */
#define CCCI_STREAM_SET_LEN(buff, stream_len) \
        do {    \
            ((CCCI_STREAM_T *)(buff))->len = (stream_len);  \
        } while (0)
/*!
 *  @brief CCCI_GET_CH_NO obtain the CCCI channel number
 */
#define CCCI_GET_CH_NO(buff)   (((CCCI_BUFF_T *)(buff))->channel)
/*!
 *  @brief CCCI_SET_CH_NO set the CCCI channel number
 */
#define CCCI_SET_CH_NO(buff, ch_no) \
        do {    \
            ((CCCI_BUFF_T *)(buff))->channel = ch_no;  \
        } while (0)
/*!
 *  @brief CCCI_SET_RESERVED set the CCCI reserved
 */
#define CCCI_SET_RESERVED(buff, reserved_d) \
        do {    \
            ((CCCI_BUFF_T *)(buff))->reserved = reserved_d;  \
        } while (0)
/*!
 *  @brief CCCI_GET_RESERVED get the CCCI reserved
 */
#define CCCI_GET_RESERVED(buff) (((CCCI_BUFF_T *)(buff))->reserved)

#ifdef __SDIOC_PULL_Q_ENH_DL__
/*!
 *  @brief ccci_io_request_t is a typedef of struct _ccci_io_request_t
 */
typedef struct _ccci_io_request_t ccci_io_request_t;
/*!
 *  @brief struct _ccci_io_request_t describe io request used to communicate
 *         between ccci_sdio modules
 */
struct _ccci_io_request_t {
    /*!
     *  @brief next io request
     */
    ccci_io_request_t*      next_request;
    /*!
     *  @brief pointer to current gpd of this io request
     */
    qbm_gpd*                first_gpd;
    /*!
     *  @brief pointer to last gpd of this io request
     */
    qbm_gpd*                last_gpd;
    /*!
     *  @brief number of the gpd in this ior
     */
    kal_int32               num_gpd;

};
#else
#define ccci_io_request_t hif_io_request_t
#endif

/*!
 *  @brief function pointer type for HIF CCCI callback function: called by HIF provided by CCCI
 *            The CCCI will registers HIF_CCCI_GPD_CALLBACK/HIF_CCCI_BUFF_CALLBACK depending on the HIG IO mode
 */
typedef void (*HIF_CCCI_CALLBACK)(kal_uint8 queue_no, void* pior_or_pbuff);
/*!
 *  @brief function pointer type for HIF CCCI callback function: called by HIF provided by CCCI for CCCI_CH_HIFIO_GPD
 */
typedef void (*HIF_CCCI_GPD_CALLBACK)(kal_uint8 queue_no, ccci_io_request_t* ior);
/*!
 *  @brief function pointer type for HIF CCCI callback function: called by HIF provided by CCCI for CCCI_CH_HIFIO_BUFF
 */
typedef void (*HIF_CCCI_BUFF_CALLBACK)(kal_uint8 queue_no, CCCI_BUFF_T* pbuff);


/*!
 *  @brief function pointer type for CCCI callback function: called by CCCI,  provided by device/user registered by ccci_init
 */
typedef void (*CCCI_CALLBACK)(CCCI_BUFF_T *buff);

/*!
 *  @brief function pointer type for CCCI IOR callback function: called by CCCI,  provided by GPD device (CCMNI/TTYCORE) registered by ccci_init_gpdior
 */
typedef void (*CCCI_IORCALLBACK )(CCCI_CHANNEL_T channel, ccci_io_request_t* ior);

/*!
 *  @brief function pointer type for CCCI IT reload GPD. 
 */
typedef void (*CCCI_RGPD_RELOAD_CALLBACK)();

/*!
 *  @brief function pointer type for CCCI IT to generate DL traffic
 */
typedef void (*CCCI_DL_PKTGEN_CALLBACK)();

//=================================CCCI APIS=================================================
/*!
 *  @brief ccci_init: This function initializes the buffer mode logical channel.
 *  @param channel:  logical channel
 *  @param funp:  CCCI callback function provided by user
 *  @return CCCI error code, CCCI_RETURNVAL_T
 */
kal_int32 ccci_init(CCCI_CHANNEL_T channel, CCCI_CALLBACK funp);
/*!
 *  @brief ccci_owner_init: Legacy MT6280 CCCI API, ccci_init the channel with task id set. But we don't check task id in MT6290
 *  @param channel:  logical channel
 *  @param kal_taskid: task id;
 *  @param funp:  CCCI callback function provided by user
 *  @return CCCI error code, CCCI_RETURNVAL_T
 */
kal_int32 ccci_owner_init(CCCI_CHANNEL_T channel, kal_taskid task, CCCI_CALLBACK funp);
/*!
 *  @brief ccci_init_gpdior: This function initializes the GPD mode logical channel.
 *  @param channel:  logical channel
 *  @param funp:  CCCI callback function provided by user
 *  @return CCCI error code, CCCI_RETURNVAL_T
 */
kal_int32 ccci_init_gpdior(CCCI_CHANNEL_T channel, CCCI_IORCALLBACK ior_funp);
/*!
 *  @brief ccci_deinit: This function de-initializes the Buffer and GPD mode logical channel.
 *  @param channel:  logical channel
 *  @return CCCI error code, CCCI_RETURNVAL_T
 */
kal_int32 ccci_deinit(CCCI_CHANNEL_T channel);
/*!
 *  @brief ccci_write provides the api for buffer mode user to send DL buffer to HIF transmission HW.
 *         It allocates ONE TGPD by qbmt_alloc_q_no_tail, if it fails returns CCCI_NO_PHY_CHANNEL
 *         The buff will be memcpy to TGPD->BD and submit the TGPD to HIF HW.
 *  @param channel:  logical channel
 *  @param buff:     pointer to buffer to be sent
 *  @return CCCI_RETURNVAL_T
 */
kal_int32 ccci_write(CCCI_CHANNEL_T channel, CCCI_BUFF_T *buff);
/*!
 *  @brief ccci_write_gpd provides the api for GPD mode user to send DL buffer to HIF transmission HW.
 *            There's no memcpy in this mode but it will traverse the GPD chain to add the CCCI header.
 *  @param channel:  logical channel
 *  @param buff:     pointer to buffer to be sent
 *  @param pextinfo: pointer to the ccci io request extension information, ex.CCCI_IO_TX_NO_FLUSH
 *  @return CCCI_RETURNVAL_T
 */
kal_int32 ccci_write_gpd(CCCI_CHANNEL_T channel, ccci_io_request_t *ccci_DL_ior, ccci_io_ext_info_t* pextinfo);

/*!
 * @function        ccci_polling_write_gpd
 * @brief           Hook up SDIO polling mode API
 *                  Current Usage: NVRAM-->CCCI_FS during mainp()
 *                                 CCCI_Handshake
 * @param channel   [IN] ccci_channel
 * @param p_gpd     [IN] pointer to the gpd
 * @param istx      [IN] KAL_TRUE: Downlink/Tx KAL_FASE: Uplink/Rx
 *
 * @return          KAL_TRUE: PASS
 *                  KAL_FALSE: NG
 */
kal_int32 ccci_polling_io(CCCI_CHANNEL_T channel, qbm_gpd *p_gpd, kal_bool is_tx);

/*!
 *  @brief ccci_ulbuff_cb is the MD side CCCI Rx callback function which registered to the buffer mode HIF driver by HIF_attach
 *                                  e.g. CCCI_CH_HIFIO_BUFF
 *  @param queue_no:  HW queue id, backward compatible with usb core
 *  @param pbuff:         pointer to Rx buffer CCCI header
 *  @return void
 */
void ccci_ulbuff_cb (kal_uint8 queue_no, CCCI_BUFF_T* pbuff);
/*!
 *  @brief ccci_ulior_cb is the MD side CCCI Rx callback function which registered to the GPD mode HIF driver by HIF_attach
 *                                  e.g. CCCI_CH_HIFIO_GPD
 *  @param queue_no:  HW queue id, backward compatible with usb core
 *  @param io_request:         pointer of ior
 *  @return void
 */
void ccci_ulior_cb (kal_uint8 queue_no, ccci_io_request_t* ior);

/*!
 *  @brief ccci_ulior_net_cb is the MD side CCCI CCMNI Rx callback function which registered to the GPD mode HIF driver by HIF_attach
 *                                  e.g. CCCI_CH_HIFIO_GPD
 *  @param queue_no:  HW queue id, backward compatible with usb core
 *  @param io_request:         pointer of ior
 *  @return void
 */
void ccci_ulior_net_cb (kal_uint8 queue_no, ccci_io_request_t* io_request);

#define ccci_dlior_cb ccci_dlior_agg_cb
/*!
 *  @brief ccci_dlior_agg_cb is the MD side CCCI Tx DONE aggregated callback function for deq the TGPD e.g. DHL
 *                               Unlike ccci_ulior_cb, this function does NOT handle the non-CCCI_CH_USER_GPD types
 *  @param queue_no:  HW queue id, backward compatible with usb core
 *  @param io_request:  pointer of ior
 *  @return void
 */
void ccci_dlior_agg_cb(kal_uint8 queue_no, ccci_io_request_t* io_request);
/*!
 *  @brief ccci_dlior_single_cb is the MD side CCCI Tx DONE callback function for deq the TGPD e.g. DHL
 *                               Unlike ccci_ulior_cb, this function does NOT handle the non-CCCI_CH_USER_GPD types
 *  @param queue_no:  HW queue id, backward compatible with usb core
 *  @param io_request:  pointer of ior
 *  @return void
 */
void ccci_dlior_single_cb(kal_uint8 queue_no, ccci_io_request_t* io_request);

/*!
 *  @brief ccci_mailbox_write formats a local buffer to mailbox format and call ccci_write
 *  @param channel:  logical channel
 *  @param id:          mailbox id
 *  @return CCCI_RETURNVAL_T
 */
kal_int32 ccci_mailbox_write(CCCI_CHANNEL_T channel, kal_uint32 id);
/*!
 *  @brief ccci_mailbox_write formats a local buffer to mailbox format and call ccci_write
 *  @param channel:     logical channel
 *  @param id:              mailbox id
 *  @param reserved:    ccci_header->reserved 
 *  @return CCCI_RETURNVAL_T
 */
kal_int32 ccci_mailbox_write_with_reserved(CCCI_CHANNEL_T channel, kal_uint32 id, kal_uint32 reserved);
/*!
 *  @brief ccci_stream_write formats a local buffer to stream format and call ccci_write
 *  @param channel:        logical channel
 *  @param addr:            start address of the user buffer
 *  @param len:              lenght of the user buffer 
 *  @return CCCI_RETURNVAL_T
 */
kal_int32 ccci_stream_write(CCCI_CHANNEL_T channel, kal_uint32 addr, kal_uint32 len);
/*!
 *  @brief ccci_stream_write_with_reserved formats a local buffer to stream format and call ccci_write
 *  @param channel:        logical channel
 *  @param addr:            start address of the user buffer
 *  @param len:              lenght of the user buffer 
 *  @param reserved      an additional parameter
 *  @return CCCI_RETURNVAL_T
 */
kal_int32 ccci_stream_write_with_reserved(CCCI_CHANNEL_T channel, kal_uint32 addr, kal_uint32 len,kal_uint32 reserved);
/*!
 *  @brief ccci_send_message send a message and reserved by ccci_mailbox_write_with_reserved
 *  @param message:  mailbox_id
 *  @param reserved: ccci_header->reserved 
 *  @return CCCI_RETURNVAL_T
 */
kal_bool ccci_send_message(kal_uint32 message, kal_uint32 reserved);

void ccci_ut_tx_direct_user_dl_ack_dbg(CCCI_BUFF_T *buff);

void lte_ccci_hw_init(void);
void lte_ccci_init_handshake_phase1(void);
void lte_ccci_hal_init(void);
void lte_ccci_init_handshake_phase2(kal_uint16 _boot_mode);
void lte_ccci_hw_init_phase2(void);
/*************************************************************************/
/*                     CCCI exception API                                */
/*************************************************************************
* FUNCTION
*  void ccci_exception_handshake
*
* DESCRIPTION
*  This function .
*
* PARAMETERS
*  channel    -    			logical channel
*  *
* RETURNS
*  The address of the share memory of the input logical channel
*
*************************************************************************/
void ccci_exception_handshake(void);

/*************************************************************************
* FUNCTION
*  void ccci_exception_info_passed
*
* DESCRIPTION
*  This function .
*
* PARAMETERS
*  channel    -    			logical channel
*  *
* RETURNS
*  The address of the share memory of the input logical channel
*
*************************************************************************/
void ccci_exception_info_passed(void);


#if defined (__CCCI_PERF_PROFILING__)
#include "cpu.h"
/*
 * Before you start to collec data , please follow the following step
 * step 1. change HMU_GPTIMER_PRIODIC_INTERVAL to 100000U in HMU. to make sure the process won't be interrupted
 * step 2. enable __CCCI_LB_IT__ in hif_ccci.mak, as we need to user the IT code.
 * step 3. for CCCI_CCMNI_DL_PERF please add monitor upcm_dlvr_dl_sdu 
 * step 4. for CCCI_CCMNI_UL_PERF please add monitor ipc_on_process_ul_queue --> upcm_rcv_ul_sdu 
 */
#define CCCI_PERF_GET_CYCLE cpu_event_counter_get_cycle
#define CCCI_PERF_GET_DURATION cpu_event_get_duration
#define __CCCI_TTY_NEW_TX_DL_PERF__     /* define to profile the ccci_tty new tx dl */
#define __CCCI_TTY_CONV_TX_DL_PERF__    /* define to profile the ccci_tty conventional tx dl */
#define __CCCI_TTY_CONV_RX_UL_PERF__    /* define to profile the ccci_tty conventional rx ul */
#define __CCCI_CCMNI_DL_PERF__          /* define to profile the ccmni dl */
#define __CCCI_CCMNI_UL_PERF__          /* define to profile the ccmni ul */
#define __CCCI_DUSER_DL_PERF__          /* define to profile the direct ccci user dl */
#define __CCCI_DUSER_UL_PERF__          /* define to profile the direct ccci user ul */
#define CCCI_PERF_REC_CNT      256
#define CCCI_PERF_REC_CNT_1    CCCI_PERF_REC_CNT-1

/* UL data structure*/
typedef struct _ccci_profile_ul_t{
    kal_uint32  sdioc_pq_num_gpd; 

    kal_uint32  sdioc_q_process_t; 
    
#ifdef __CCCI_CCMNI_UL_PERF__
    kal_uint32  ccmni_ipc_on_process_ul_s;
    kal_uint32  ccmni_upcm_rcv_ul_sdu_s;
    kal_uint32  ccmni_ipc2upcm_t;
#endif

#ifdef __CCCI_TTY_CONV_RX_UL_PERF__
    kal_uint32  tty_conv_rx_CMD_GB_s;
    kal_uint32  tty_conv_rx_CMD_GB_e;
    kal_uint32  tty_conv_rx_CMD_GB_t;
#endif

#ifdef __CCCI_DUSER_UL_PERF__
#endif

    
} ccci_profile_ul_t;

/* DL data structure*/
typedef struct _ccci_profile_dl_t{
    kal_uint32  sdioc_pq_num_gpd; 

    kal_uint32  sdioc_submit_ior_s;
    kal_uint32  sdioc_submit_ior_e;

//====================global end===========================


#ifdef __CCCI_CCMNI_DL_PERF__
    kal_uint32  ipc_on_process_ul_s;
    kal_uint32  upcm_rcv_ul_sdu_s;
#endif
    
#ifdef __CCCI_TTY_CONV_TX_DL_PERF__
    kal_uint32  tty_conv_tx_s;
    kal_uint32  tty_conv_tx_e;
    kal_uint32  tty_conv_tx_t; 
    kal_uint32  tty_conv_tx_cccih_s;
    kal_uint32  tty_conv_tx_cccih_e;
    kal_uint32  tty_conv_tx_cccih_t; 
    kal_uint32  tty_conv_tx_sdioc_submit_ior_t; 
#endif

#ifdef __CCCI_DUSER_DL_PERF__
    kal_uint32  duser_ccci_write_s;
    kal_uint32  duser_ccci_write_e;
    kal_uint32  duser_ccci_write_t;
    kal_uint32  duser_sdioc_submit_ior_t; 
#endif
    
} ccci_profile_dl_t;

extern ccci_profile_dl_t    dl_prof[CCCI_PERF_REC_CNT];
extern kal_uint32           dl_prof_id;
extern ccci_profile_ul_t    ul_prof[CCCI_PERF_REC_CNT];
extern kal_uint32           ul_prof_id;

#endif //__CCCI_PERF_PROFILING__

//====================MT6280 SYSTEM Service===========================

#undef	X_CCCI_SYSMSGSVC_CONF
#define	X_CCCI_SYSMSGSVC_CONF(mSGNO, mODE, iD)	mSGNO,
/*!
 *  @brief  CONTROL_CHANNEL_MSG
 *             CCCI Message ID Passing Through CONTROL_CHANNEL and SYSTEM_CHANNEL
 *             NOTICE: Negotiations With AP Owner Before Modification
 */
typedef enum
{
    CCMSG_ID_START_BOOT        = 0x00000000,
    CCMSG_ID_NORMAL_BOOT_READY = 0x00000001,
    CCMSG_ID_META_BOOT_READY   = 0x00000002,
    CCMSG_ID_RESET             = 0x00000003,
    CCMSG_ID_EXCEPTION_CHECK   = 0x00000004,
    CCMSG_ID_DRV_VERSION_ERR   = 0x00000005,
    CCMSG_ID_EXCEPTION_REC_OK  = 0x00000006,
    CCMSG_ID_EXCEPTION_PASS    = 0x00000008,
    /* System Channel */
    CCMSG_ID_MD_L4_MOD         = 0x0000000E,//add for RIL (AP task) and L4C (MD task) communication message
    CCMSG_ID_MD_L4_MAX_TX_PWR_RED_REQ = 0x0000000F,

    CCMSG_ID_MD_LEGACY_END     = 0x000000FF,
    CCMSG_ID_SYSMSGSVC_MASK    = 0x00000100,
    CCMSG_ID_SYSMSGSVC_START   = 0x00000100,
    CCMSG_ID_SYSMSGSVC_DUMMY   = 0x000000FF,
    //- section 0x100 ~ 0x1FF : reserved for system message service used
    #include "ccci_sysmsgsvc_conf.h"

    CCMSG_ID_SYSMSGSVC_END,

    CCMSG_ID_MD_WDT_FLAG       = 0x00001000, //- for MT6577/MT6589, AP cannot receive MD WDT interrupt issue. k2 md2 6589, for resolving wdt build error
	
}CONTROL_CHANNEL_MSG;
#undef	X_CCCI_SYSMSGSVC_CONF

#define BOOT_ATTR_IS_CLEAN_BOOT   0x00000001

kal_bool ccci_queryBootAttributes(kal_uint32 mask);

/*====================Exception Mode APIs===========================*/
typedef enum _CCCI_EXPT_STATE
{
    CCCI_EXPT_INVALID_ST,
    CCCI_EXPT_INIT_CCCITTY_DEV_ST,
    CCCI_EXPT_INIT_ST, 
    CCCI_EXPT_CLEAR_CH_ST,
    CCCI_EXPT_HANDSHAKE_ST,
    CCCI_EXPT_INFO_PASS_PRE_ST,
    CCCI_EXPT_INFO_PASS_ST,
    CCCI_EXPT_STATE_MAX
} CCCI_EXPT_STATE_E;

kal_int32 ccci_except_init_hmu(kal_uint32 dev_mapping, kal_uint32 ext_devinfo_len, kal_char * ext_devinfo);
kal_int32 ccci_except_init(kal_uint32 ch_dhl_dl, kal_uint32 ch_dhl_ul);
kal_int32 ccci_except_clear_ch(kal_uint32 ccci_ch);
kal_int32 ccci_except_set_gpd(kal_uint32 expt_ch, void *p_first_gpd, void *p_last_gpd);
kal_int32 ccci_except_poll_gpd(kal_uint32 expt_ch, void **pp_first_gpd, void **pp_last_gpd, kal_uint32 *gpd_num);
kal_int32 ccci_except_hif_st(kal_uint32 expt_dl_ch);
kal_int32 ccci_except_hif_isr(kal_uint32 expt_dl_ch);

kal_bool cccitty_dev_expt_init(void);
void ccci_fs_svc_expt_init(void);
void ccci_get_fs_shm_info(void **p_membase, kal_uint32 *p_memsize);
void ccci_get_ex_shm_info(void **p_membase, kal_uint32 *p_memsize);

kal_int32 ccci_write_except_share_memory();

/*===================FAKE API=======================================*/
#define ccci_init_handshake_phase1(...)
#define ccci_init_handshake_phase2(...)
#define ccci_hal_init(...)

/*===================CCCI SYSMSG====================================*/
typedef void (*CCCI_SYSMSGSVC_HISR_CALLBACK)(kal_uint32 param);
kal_int32 ccci_register_sysmsgsvc_callback(kal_uint32 msgno, CCCI_SYSMSGSVC_HISR_CALLBACK funp);
typedef struct
{
	kal_uint8		ref_count;
	kal_uint16		msg_len;
	kal_uint16		W0;
} CCCI_COMMON_ILM_4B;

typedef struct
{
	kal_uint8		ref_count;
	kal_uint16		msg_len;
	kal_uint16		HW0;
} CCCI_COMMON_ILM_2B;

/*===================CCCI MISC API=======================================*/
#define CCCI_MISC_INFO_NOT_EXIST   0x00000000
#define CCCI_MISC_INFO_NOT_SUPPORT 0x00000001
#define CCCI_MISC_INFO_SUPPORT     0x00000002
#define CCCI_MISC_INFO_PARTIALLY_SUPPORT 0x00000003

#undef     X_CCCI_MISCINFO_CONF
#define    X_CCCI_MISCINFO_CONF(mSGNO)    mSGNO,
typedef enum
{
#include "ccci_misc_data_conf.h"
    CCCI_MISC_INFO_QUERY_END
} CCCI_MISC_INFO_ID_T;
#undef    X_CCCI_MISCINFO_CONF

extern kal_int32 ccci_misc_data_feature_support(kal_uint32 op_id, kal_uint32 len, void *pReturn);

/*******************************************************************************
 * define index for CCCI EXCEP DBG Logging
 *******************************************************************************/
typedef enum {
    CCCI_EXCEP_DBG_HS_CCCI_FS_WAIT_TIME_POLLING = 0,
    CCCI_EXCEP_DBG_HS_CCCI_FS_WAIT_TIME_NORMAL_CARRY, // wait time is double, H32 is high 32 bit value
    CCCI_EXCEP_DBG_HS_CCCI_FS_WAIT_TIME_NORMAL, // wait time is double, L32 is low 32 bit value
    CCCI_EXCEP_DBG_HS_CCCI_FS_TRACE,
    CCCI_EXCEP_DBG_HS_CCCI_RPC_WAIT_TIME_POLLING,
    CCCI_EXCEP_DBG_HS_CCCI_RPC_WAIT_TIME_NORMAL_CARRY, // wait time is double, H32 is high 32 bit value
    CCCI_EXCEP_DBG_HS_CCCI_RPC_WAIT_TIME_NORMAL, // wait time is double, L32 is low 32 bit value
    CCCI_EXCEP_DBG_HS_CCCI_RPC_TRACE,
    CCCI_EXCEP_DBG_HS_BOOTTRC_WAIT_TIME,
    CCCI_EXCEP_DBG_HS_CCCI_DEBUG_CHANNEL,
    CCCI_EXCEP_DBG_HS_CCCI_DEBUG_CURRENT_SEQ_NUM,
    CCCI_EXCEP_DBG_HS_CCCI_DEBUG_EXPECTED_SEQ_NUM,
    CCCI_EXCEP_DBG_HS_CMUX_GPD_PROFILE_NUM,
    CCCI_EXCEP_DBG_HS_CCCI_FS_ERROR_LINE,
    CCCI_EXCEP_DBG_HS_CCCI_FS_ERROR_PARAM1,
    CCCI_EXCEP_DBG_HS_CCCI_FS_ERROR_PARAM2,
    CCCI_EXCEP_DBG_HS_CCCI_FS_ERROR_PARAM3,
    CCCI_EXCEP_DBG_HS_LOG_MAX,
} CCCI_EXCEP_DBG_HS_INDEX;

kal_int32 ccci_excep_dbg_logging_InHS2(kal_uint32 index, void* addr);

//#define __SP_BOOTTRC_ENABLE__
#if defined(__SP_BOOTTRC_ENABLE__)
extern void ccci_boottrc_send_log(kal_uint32 index, kal_uint32 value);
#endif

#undef     X_CCCI_EXCEP_MEMORY_CONF
#define    X_CCCI_EXCEP_MEMORY_CONF(region, length)    region,
typedef enum
{
#include "ccci_excep_memory_region.h"
    CCCI_EXCEP_MEMORY_REGION_MAX
} CCCI_EXCEP_MEMORY_REGION;
#undef    X_CCCI_EXCEP_MEMORY_CONF

typedef enum {
    CCCI_EXCEP_MEMORY_TYPE_SHM,
    CCCI_EXCEP_MEMORY_TYPE_STATIC_BUFFER,
    CCCI_EXCEP_MEMORY_TYPE_MAX
} CCCI_EXCEP_MEMORY_TYPE;

kal_int32 ccci_excep_query_shm(CCCI_EXCEP_MEMORY_REGION region, kal_uint32 *address, kal_uint32 *size, CCCI_EXCEP_MEMORY_TYPE *mem_type);
kal_int32 ccci_excep_init_shm(CCCI_EXCEP_MEMORY_TYPE mem_type);
kal_uint32 ccci_excep_shm_get_total_size();

void ccci_CalculateShareMem(kal_uint32 *start_addr, kal_uint32 *end_addr , kal_uint32 *size);


/*******************************************************************************
* CCCI DEBUG INFO
*******************************************************************************/
#define CCCI_DEBUG_ASSERT_BIT 1
#define CCCI_DEBUG_NOT_ASSERT_BIT 0

typedef enum
{
    CCCI_DEBUG_GET_STATUS_MODULE_L1TIME = 0x0,
    CCCI_DEBUG_GET_STATUS_MODULE_CCCIFS,
    CCCI_DEBUG_GET_STATUS_MODULE_CCCIRPC,
    CCCI_DEBUG_GET_STATUS_MODULE_CCCIIPC,
    CCCI_DEBUG_GET_STATUS_MODULE_CCMNI,
    CCCI_DEBUG_GET_STATUS_MODULE_CCCITTY,
    CCCI_DEBUG_GET_STATUS_MODULE_CCCIIMS,
    CCCI_DEBUG_GET_STATUS_MODULE_CCCISEQ,
    CCCI_DEBUG_GET_STATUS_MODULE_MAX
} CCCI_DEBUG_GET_STATUS_MODULE;

kal_int32 ccci_debug_add_seq(CCCI_BUFF_T *bufp, kal_uint32 assert_bit);
kal_int32 ccci_debug_check_seq(CCCI_BUFF_T *bufp);
void ccci_debug_reset_seq_data();
typedef kal_uint32 (*CCCI_DEBUG_GET_STATUS_CALLBACK)(kal_uint32 *write_ptr, kal_uint32 available_size);
kal_uint32 ccci_debug_get_status_register(CCCI_DEBUG_GET_STATUS_MODULE module_id, CCCI_DEBUG_GET_STATUS_CALLBACK funp);
kal_uint32 ccci_debug_get_status_worker();
void ccci_debug_set_feature();
kal_uint32 ccci_get_current_time();
kal_uint32 ccci_get_duration(kal_uint32 start, kal_uint32 end);

#endif //#ifndef _CCCI_IF_H
