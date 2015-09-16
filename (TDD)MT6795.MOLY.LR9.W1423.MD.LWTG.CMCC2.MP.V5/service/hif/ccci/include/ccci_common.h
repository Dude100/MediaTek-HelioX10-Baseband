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
 *   ccci_common.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines the CCCI common data structures
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
 * [CCCI] For SS debug info
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * [CCCI] Change the enum of init stage and fix CCCI IT load build fail
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
 * [CCCI APIS] Limit CCCI polling IO using time
 *
 * removed!
 * removed!
 * [CCCI RPC] Debug enhancement & Add log.
 *
 * removed!
 * removed!
 * [CCCI] Change exception flow.
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
 * 	[CCCI] CCCI MISC Info.
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
 * 	.
 *
 * 09 06 2013 ap.wang
 * removed!
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
#ifndef _CCCI_COMMON_H
#define _CCCI_COMMON_H
#include "kal_public_api.h"
#include "syscomp_config.h"
#include "ccci_if.h"
#include "ccci_debug.h"
#include "hif_common.h"
#include "qmu_bm.h"
#include "qmu_bm_util.h"

/*
 * 20130111 iwei: move to ccci_hif_cfg.c
 */
//#ifdef __HIF_CLDMA_SUPPORT__
//#include "cldmacore_if.h"
//#endif

/* Compile Options */

#define CCCI_DATA_TRACE_DUMP_ENABLE (1)

/*!
 *  @brief defines CCCI boot up mode
 */
#define CCCI_NORMAL_MODE    0
#define CCCI_META_MODE      1

/*!
 *  @brief __CCCI_BMODE_HW_SUPPORT__ support HW use buffer mode, eg. CAIF
 */
#define __CCCI_BMODE_HW_SUPPORT__

/*!
 *  @brief __CCCI_CCMNI_UPLINK_ENHANCE__ enable CCCI CCMNI UPLINK by ccci_ulior_net_cb
 */
#define __CCCI_CCMNI_UPLINK_ENHANCE__
#ifdef __CCCI_CCMNI_UPLINK_ENHANCE__
    #define ccci_ulior_net   ccci_ulior_net_cb
#else
    #define ccci_ulior_net   ccci_ulior_cb
#endif

/*!
 *  @brief CCCI_TYPE* CCCI channle operation type
 */
#define CCCI_TYPE_TX HIFQ_TYPE_TX
#define CCCI_TYPE_TX_NO_FLUSH HIFQ_TYPE_TX_NO_FLUSH
#define CCCI_TYPE_RX HIFQ_TYPE_RX

//define the size of ccci overhead, the 16 bytes in ccci descriptor
#define CCCI_HAL_OVERHEAD_WORD 4
#define CCCI_HAL_OVERHEAD sizeof(CCCI_BUFF_T)

#define CCCI_DUMMY_TX   0xff
#define CCCI_DUMMY_RX   0xff

/* DriverVersion */
#define CCCI_CURRENT_VERSION      0x20110118
#define BOOT_CHECK_ID             0x5555FFFF /* magic id : Placed on reserved field */

//#define mFileShareMemSize         82020 // (16+4+4+6*4 + 16384)*5 ==> (CCCI header, FS op, argc, 6*arg_len, FS buffer) * 5 concurrency task
#define mFileShareMemSize      FS_CCCI_MAX_BUF_SIZE*FS_CCCI_REQ_BUFFER_NUM
#define mExceShareMemSize         4*1024 

#define NORMAL_BOOT_ID            0
#define META_BOOT_ID              1

typedef enum
{
    CCCI_NOT_INIT          = 0x00000000,
    CCCI_HW_INIT           = 0x00000001,
    CCCI_HW_INIT_DONE      = 0x00000002,
    CCCI_INIT              = 0x00000003,
    CCCI_HANDSHAKE1        = 0x00000004,
    CCCI_HANDSHAKE1_AP_ACK = 0x00000005,
    CCCI_HAL_INIT          = 0x00000006,
    CCCI_HAL_INIT_DONE     = 0x00000007,
    CCCI_HANDSHAKE2        = 0x00000008,
    CCCI_BOOT_DONE         = 0x00000009
}CCCI_BOOT_STATE;

/*!
 *  @brief CCCI_HIF_HW_TYPE_T CCCI hif transmission hw type enum
 */
typedef enum
{
    CCCI_TYPE_MIN       	= 0,
    CCCI_TYPE_SDIO      	= 1,
    CCCI_TYPE_CLDMA     	= 2,
    CCCI_TYPE_CAIF_GPD  	= 3,
    CCCI_TYPE_CAIF_BUF  	= 4,    
    CCCI_TYPE_CCIF_GPD_AP  	= 5,
	CCCI_TYPE_CCIF_GPD_MD  	= 6,
    CCCI_TYPE_CCIF_BUF  	= 7,
    /* dummy interface is for those channels not used */
    CCCI_TYPE_DUMMY     	= 8,
    CCCI_TYPE_UT_GPD    	= 9,
    CCCI_TYPE_UT_BUFF   	= 10,    
    CCCI_TYPE_MAX       	= 11,
} CCCI_HIF_HW_TYPE_T;

/*!
 *  @brief CCCI_CH_USER_MODE_T CCCI channel user mode enum
 */
typedef enum
{
    CCCI_CH_DISABLE       = 0,
    CCCI_CH_USER_MIN      = 0,
    /*GPD mode CCCI user, use GPD ior as basic io unit, cb_funp   = NULL*/
    CCCI_CH_USER_GPD      = 1, 
    /*Buffer mode (Legacy) CCCI device  , use buff as basic io unit, reload RGPD by DEV, iorcb_funp = NULL*/
    CCCI_CH_USER_LEGACY   = 2, 
    /*Buffer mode Direct CCCI call user, use buff as basic io unit, reload RGPD by HIF_DRIVER, iorcb_funp = NULL*/
    CCCI_CH_USER_DIRECT   = 3, 
    CCCI_CH_USER_MAX      = 4    
} CCCI_CH_USER_MODE_T;

/*!
 *  @brief CCCI_CH_HIFIO_MODE_T CCCI channel hw mode enum
 */
typedef enum
{
    CCCI_CH_HIFIO_MIN      = 0,
    CCCI_CH_HIFIO_GPD      = 1, //GPD mode HW, e.g. SDIO/CLDMA
    CCCI_CH_HIFIO_BUFF     = 2, //Buffer mode HW, e.g. CAIF
    CCCI_CH_HIFIO_MAX      = 3    
} CCCI_CH_HIFIO_MODE_T;


typedef struct MISC_INFO_ELEMENT_T
{
    kal_uint32   Feature[4];
}MISC_INFO_ELEMENT;

typedef struct MISC_INFO_DATA_T
{
    kal_uint32   MiscPrefix;            // "MISC"
	kal_uint32   SupportMask;
	kal_uint32   Index;
	kal_uint32   Next;
    MISC_INFO_ELEMENT element[16];
	kal_uint32   Reserve[3];
	kal_uint32   MiscPostfix;          // "MISC"
}MISC_INFO_DATA;

/*!
 *  @brief MODEM_RUNTIME_DATA CCCI MD runtime enum
 */
typedef struct MODEM_RUNTIME_DATA_T
{
    kal_uint8    Prefix[4];            // "CCIF" for compatible to 6280
    kal_uint8    Platform[8];          // Hardware Platform String ex: "MT6516E1"
    kal_uint32   DriverVersion;        // 0x00000929 since W09.29
    kal_uint32   BootChannel;          // Channel to ACK AP with boot ready
    kal_uint32   BootingStartID;       // MD is booting. NORMAL_BOOT_ID or META_BOOT_ID or early exception memory dump
    kal_uint32   BootAttributes;       // Attributes passing from AP to MD Booting
    kal_uint32   BootReadyID;          // MD response ID if boot successful and ready ,
                                       // Cannot equal to CCMSG_ID_DRV_VERSION_ERR
    kal_uint32   FileShareMemBase;
    kal_uint32   FileShareMemSize;
    kal_uint32   ExceShareMemBase;
    kal_uint32   ExceShareMemSize;     // 512 Bytes Required 
    kal_uint32   CCIFShareMemBase;     
    kal_uint32   CCIFShareMemSize;     // CCIF share queue size
    kal_uint32   TotalShareMemBase;
    kal_uint32   TotalShareMemSize;
    kal_uint32   CheckSum;
    kal_uint8    Postfix[4];           //"CCIF" for compatible to 6280                       
    MISC_INFO_DATA MiscInfo;
}MODEM_RUNTIME_DATA;

/* struct to share ipc */
typedef struct IPC_ST
{
    kal_uint32 rx_offset;
    kal_uint32 tx_offset;
    kal_uint32 size;
    kal_uint8 *buffer;
}Ipcsvc_Share_ST;

/* API for CCCI device to obtain the share memory */
MODEM_RUNTIME_DATA* ccci_get_share_data(void);

/*!
 *  @brief function prototype for transmission HW submit ior API HIF_IOR_FUNP 
 *            For CCCI_CH_HIFIO_GPD:  (*HIF_IOR_FUNP)(kal_uint8 queue_type , kal_uint8 queue_no, ccci_io_request_t* pior) ;
 *            For CCCI_CH_HIFIO_BUFF: (*HIF_IOR_FUNP)(kal_uint8 queue_type , kal_uint8 queue_no, CCCI_BUFF_T * pbuff) ;
 */
typedef kal_bool (*HIF_IOR_FUNP)(kal_uint8 queue_type , kal_uint8 queue_no, void* pior_or_pbuff) ;

typedef kal_bool (*HIF_POLLING_FUNP)(kal_uint8 queue_no, qbm_gpd *pgpd, kal_bool istx);

typedef struct CCCI_HIF_EXPT_APIS{
    /*!
     *  @brief HIF expt initialization
     */
	kal_bool (*hif_expt_init)(kal_uint32 dhldl_q, kal_uint32 expt_q);
	/*!
     *  @brief HIF expt clear channel (reserved)
     *  Due to clear queue API is moved to HIF from W1408
     */
	kal_bool (*hif_expt_clear_q)(kal_uint8 queue_type, kal_uint8 queue_no);
	/*!
     *  @brief HIF expt set gpd
     */
	kal_bool (*hif_expt_set_gpd)(kal_uint8 queue_type, kal_uint8 queue_no, void *p_first_gpd, void *p_last_gpd);
	/*!
     *  @brief HIF expt poll gpd
     */
	kal_int32 (*hif_expt_poll_gpd)(kal_uint8 queue_type, kal_uint8 queue_no, void **pp_first_gpd, void **pp_last_gpd);
	/*!
     *  @brief HIF expt isr handler
     */
	kal_bool (*hif_expt_hif_isr)(void);
	/*!
     *  @brief HIF expt link state check
     */
	kal_bool (*hif_expt_link_st)(kal_uint8 queue_type, kal_uint8 queue_no);
}ccci_hif_expt_apis;

/*!
 *  @brief ccci_hw_apis CCCI hif tranmission hw api struct
 */
typedef struct CCCI_HW_APIS{
	/*!
     *  @brief transmission HW submit I/O request function
     */
	HIF_IOR_FUNP ior_funp;
	/*!
     *  @brief transmission HW CCCI_CH_HIFIO_GPD type attach for register callback
     */
	kal_bool (*gpdhwq_attach)(kal_uint8 queue_type, kal_uint8 queue_no, CCCI_CHANNEL_T channel, HIF_CCCI_GPD_CALLBACK funp);
	/*!
     *  @brief transmission HW CCCI_CH_HIFIO_BUFF type attach for register callback
     */
	kal_bool (*buffhwq_attach)(kal_uint8 queue_type, kal_uint8 queue_no, CCCI_CHANNEL_T channel, HIF_CCCI_BUFF_CALLBACK funp);
	/*!
     *  @brief transmission HW detach
     */
	kal_bool (*hwq_detach)(kal_uint8 queue_type, kal_uint8 queue_no, CCCI_CHANNEL_T channel);
	/*!
     *  @brief flush HIF GPDs, only valid for GPD mode HIF
     */
	kal_uint32 (*hwq_flush)(kal_uint8 queue_type, kal_uint8 queue_no);
	/*!
     *  @brief submit_ior_ext function has been removed in 20120921
     */
    HIF_POLLING_FUNP polling_funp;
	/*!
     *  @brief transmission HW mode, CCCI_CH_HIFIO_MODE_T
     */
    CCCI_CH_HIFIO_MODE_T hwio_mode;
 /*====================Exception Mode APIs===========================*/
	/*!
     *  @brief HIF expt APIs
     */
    ccci_hif_expt_apis *hif_expt_apis;
} ccci_hw_apis;

/*!
 *  @brief ccci_hw_apis CCCI hif tranmission hw api struct
 */
typedef struct CCCI_CH_HANDLE {
	/*!
     *  @brief the hw queue this channel is tided to SDIOC_TXQ_TYPE/SDIOC_RXQ_TYPE
     */
	kal_uint8	        hwq_id_predifined;     
	/*!
     *  @brief channel user mode: GPD, Buffer mode
     */
	CCCI_CH_USER_MODE_T	user_mode_predifined;  
	/*!
     *  @brief operating type for this ccci channel, CCCI_TYPE_TX/CCCI_TYPE_RX
     */    
	kal_uint8           ch_op_type_predifined;  
	/*!
     *  @brief ccci_cb_funp registered to CCCI_CH_HIFIO_GPD type HIF driver during attaching
     */
	// void (* ccci_uldl_iorcb_funp)(kal_uint8 queue_no, ccci_io_request_t* pior); 
	HIF_CCCI_GPD_CALLBACK ccci_uldl_iorcb_funp;
    /*!
     *  @brief ccci_cb_funp registered to CCCI_CH_HIFIO_BUFF type HIF driver during attaching
     */
	//void (* ccci_uldl_iorcb_funp)(kal_uint8 queue_no, CCCI_BUFF_T* pbuff);
	HIF_CCCI_BUFF_CALLBACK ccci_uldl_buffcb_funp;
	/*!
     *  @brief the transmission hw type for this CCCI ch
     */    
	CCCI_HIF_HW_TYPE_T  hw_type_predifined;
} ccci_ch_handle ;

/*!
 *  @brief CCCI_CTRL_T CCCI control structure
 */
typedef struct
{
	/*!
     *  @brief [Reserved] MT6290 HIF SDIO takes care of thread protection
     */      
    CCCI_STATE_T state;
    /*!
     *  @brief owner is used as channel enable/mode: 
     *            0: channel disable
     *            1: channel enable and user mode = CCCI_CH_USER_GPD
     *            2: channel enable and user mode = CCCI_CH_OP_MODE_LEGACY
     *            3: channel enable and user mode = CCCI_CH_OP_MODE_DIRECT
     */
    kal_uint32  owner;
	/*!
     *  @brief operating type for this ccci channel, CCCI_TYPE_TX/CCCI_TYPE_RX
     */      
    kal_uint8   ch_op_type;
    /*!
     *  @brief the hw queue this channel is tided to SDIOC_TXQ_TYPE/SDIOC_RXQ_TYPE
     */
	kal_uint8	hwq_id;
	/*!
     *  @brief callback function for Lagacy/Direct CCCI call channels
     */
    CCCI_CALLBACK cb_funp;
	/*!
     *  @brief callback function for GPD mode channels
     */
    CCCI_IORCALLBACK iorcb_funp;  
    /*!
     *  @brief [Reserved]
     */      
    CCCI_BUFF_T buff;
    /*!
     *  @brief Transmission HW submit function, Tx or Rx reload, pre-defined in ccci_hw_handle_apis
     */
    HIF_IOR_FUNP ioreq_funp; 
    /*!
     *  @brief Transmission HW polling mode function
     */
    HIF_POLLING_FUNP polling_funp; 
    /*!
     *  @brief HIF transmission HW io mode
     */     
    CCCI_CH_HIFIO_MODE_T hif_iomode;
    /*!
     *  @brief [Reserved] for event driven Rx
     */     
    kal_eventgrpid event;
    /*!
     *  @brief [Reserved] for event driven Rx : need thread safe protection "SDIOC v.s. user thread" 
     */
    void		   *rxswq;

    
} CCCI_CTRL_T;

/*!
 *  @brief ccci_ch_info CCCI channel information initialized by ccci_init / ccci_init_gpdior
 */
extern CCCI_CTRL_T ccci_ctrl_pool[CCCI_PEER_ID_MAX][CCCI_MAX_CHANNEL];

extern kal_uint32 MDExceShareMemBase[mExceShareMemSize / 4];
extern kal_uint8 MDFileShareMemBase[mFileShareMemSize];

/*Defined at ccci_except.c*/
extern kal_uint32 ccci_excep_dbg_log_base_hs2;
extern kal_uint32 ccci_excep_dbg_log_size_hs2;
extern CCCI_EXCEP_MEMORY_TYPE ccci_excep_dbg_log_type_hs2;

extern CCCI_EXCEP_MEMORY_TYPE ccci_excep_memory_type;

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
#endif

/*!
 * @function        [INLINE function] CCCI_GET_QBM_DATAPTR
 * @brief           Obtain the pointer of data. 
 *                  Reference CCCIDEV_GET_QBM_DATAPTR
 *
 * @param gpd       [IN] pointer to the GPD
 *
 * @return          Return gpd->1st_bd->p_data_tbd / gpd->p_data_tbd
 */
static __inline void* CCCI_GET_QBM_DATAPTR(void* gpd)
{
    void* bd = NULL;
    void* data_ptr = NULL;
    
    ASSERT(NULL!=gpd);
    if(0 != QBM_DES_GET_BDP(gpd)){
        //4 <case 1> GPD->BD->BUFF
        bd = QBM_DES_GET_DATAPTR(gpd);
        ASSERT(NULL!=bd);
        data_ptr = QBM_DES_GET_DATAPTR(bd);
    }else{
        //4 <case 2> GPD->BUFF        
        data_ptr = QBM_DES_GET_DATAPTR(gpd);
    }

    ASSERT(NULL!=data_ptr);
    return data_ptr;
}

static __inline void CCCI_QBM_ENQ(void *p_new_head, void *p_new_tail, void **pp_orig_head, void **pp_orig_tail)
{
    kal_uint8 *p_ori_tail;
    p_ori_tail = *pp_orig_tail;

    if(*pp_orig_head == NULL){
        *pp_orig_tail = p_new_tail;
        *pp_orig_head = p_new_head;
    }else{
        /* link new queue */
        QBM_DES_SET_NEXT(p_ori_tail, p_new_head);
        // change tail to new tail
        *pp_orig_tail = p_new_tail;
    }
}

/*use IRQMask api to protect thread safe*/
extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32);
#define CCCI_LOCK(_s) _s = SaveAndSetIRQMask()
#define CCCI_UNLOCK(_s)    RestoreIRQMask(_s)


/*!
 *  @brief  ccci_get_ch_info returns the pointer of channel information structure
 *  @param  CCCI_CH_NO    CCCI channel number
 *  @return   ccci_ch_handle
 */
ccci_ch_handle* ccci_get_ch_info(CCCI_CHANNEL_T CCCI_CH_NO);
ccci_hw_apis* ccci_get_hw_handle_api(CCCI_HIF_HW_TYPE_T hw_type);
void ccci_hif_init(void);

void set_ccci_boot_state(kal_uint32 new_state);
kal_uint32 get_ccci_boot_state();
void ccci_boot_ack(CCCI_BUFF_T *bufp);
void ccci_handshake1_ack(CCCI_BUFF_T *bufp, kal_uint32 cp_size);

void ccci_sdio_hs1(void);
void ccci_sdio_hs2(kal_uint16 _boot_mode);

void ccci_cldma_hs1(void);
void ccci_cldma_hs2(kal_uint16 _boot_mode);

void ccci_ccif_hs1(void);
void ccci_ccif_hs2(kal_uint16 _boot_mode);
/* Misc.*/

/* Get address by a offset of the PD */
#define CCCI_INIT_QBM_DES_GET_ADDR_BY_OFFSET(_p, _ofst)  \
          (void*)((kal_uint8*)(_p) + (_ofst))
/*  Used for buffer and descriptor are in continus memory address */
#define CCCI_INIT_QBM_DES_SET_DATA_BY_OFFSET(_p, _ofst)  \
          (QBM_GET_GPD_PTR(_p)->p_data_tbd = CCCI_INIT_QBM_DES_GET_ADDR_BY_OFFSET(_p, _ofst))

/* this code will set datalen and extlen to 0 */
/* Because in descriptor, they are in the 12 bytes */
#define CCCI_INIT_RESET_DATALEN_EXTLEN(_p) *(kal_uint32*)((kal_uint8*)(_p) + 12) = 0

/* reset data pointer for common case (most buffer type case) */
#define CCCI_INIT_RESET_COMMON_DATA(_p) \
    CCCI_INIT_QBM_DES_SET_DATA_BY_OFFSET(_p, sizeof(qbm_gpd) + COMMON_EXT_LEN)
 
#endif  //#ifndef _CCCI_COMMON_H
