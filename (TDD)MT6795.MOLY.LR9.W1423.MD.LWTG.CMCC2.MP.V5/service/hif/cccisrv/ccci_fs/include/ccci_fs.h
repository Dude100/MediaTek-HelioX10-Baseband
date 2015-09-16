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
 *   ccci_fs.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI FS configuration and APIs
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
 * [CCCI] CCCI new debug mechanism
 *
 * removed!
 * removed!
 * [CCCI] Add ROME chip version by API instead compile option
 *
 * removed!
 * removed!
 * [CCCI FS] Add CCCI FS DL trace log & sequence number between PS & L2
 *
 * removed!
 * removed!
 * [CCCI] Add & Maintain UT code
 *
 * removed!
 * removed!
 * [CCCI FS] Debug enhancement & Add log.
 *
 * removed!
 * removed!
 * [CCCI] For MT6595, extend static polling buffer size to prevent memory corruption when CLDMA converts non-cacheable.
 *
 * removed!
 * removed!
 * 	CCCI_FS compact read and profile trace (sdio)
 *
 * removed!
 * removed!
 * 	CCCI_FS compact read and profile trace
 *
 * removed!
 * removed!
 * 	Shrink CCCI UL/DL buffer to 3.5KB
 *
 * removed!
 * removed!
 * a. Check-in cccifs new features (support 16KB I/O)
 * b. add __CCCIFS_SUPPORT__ option to related files
 *
 * removed!
 * removed!
 * MT6290 Rename CCCI Services
 *
 * removed!
 * removed!
 * sync latest version of new features
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#ifndef _CCCI_FS_H
#define _CCCI_FS_H

#include "ccci_if.h"
#include "ccci_fs_if.h"
#include "cccidev_qbm.h"
#include "ccci_fs_debug.h"
#include "kal_public_api.h"
#include "us_timer.h"

/* [mail] Nvram access in CCCI on SDIO */
#define __CCCI_FS_LT_4K_IO_ENABLE__ 

#define __CCCI_FS_PROFILE__

#define FS_CCCI_EXCEPT_MAX_RETRY        7
#define FS_CCCI_MAX_RETRY               0xFFFF
//#define FS_CCCI_REQ_BUFFER_NUM          5 /* support 5 concurrently request*/
//#define FS_CCCI_MAX_ARG_NUM	            6 /* parameter number */
//#define FS_CCCI_MAX_BUF_SIZE	        16384 

#define FS_CCCI_USE_DEFAULT_INDEX	    (-1)  /* ccci_fs api will find the fre index for you */
#define FS_CCCI_API_RESP_ID	            0xFFFF0000
#define FS_CCCI_INC_BUF_INDEX(x)	    (x = (x + 1) % FS_CCCI_REQ_BUFFER_NUM)

#define CCCI_FS_INIT_HWO_GPD_NUM        (16+1) /* add one for QBM tail */
#define CCCI_FS_UL_BUF_TYPE             QBM_TYPE_CCCI_COMM         /* Type of GPD used in uplink data path. */
#define CCCI_FS_UL_BUF_SZ               (3584) //3.5KB for UL MTU size (shall include ccci header and fs OPID) 
#define CCCI_FS_DL_BUF_TYPE             QBM_TYPE_CCCI_COMM         /* Type of GPD used in uplink data path. */
#define CCCI_FS_DL_BUF_SZ               (3584) //3.5KB for DL MTU size (shall include ccci header and fs OPID) 
#define CCCI_FS_OPID_SZ                 (4)  /* fs_operationID  sizeof(kal_uint32) */
#define CCCI_FS_DL_DUMMY_SZ             (108)  /* This is padding size to align DL Payload size (3584-128 Byte), 
                                                  DL size : CCCI_H(16)+FS_OPID(4)+ padding_sz(108) + payload < 3584 Byte */


#define CCCI_FS_TGPD_COUNT (5*2) /* max I/O = 16KB, allocate ping-pong buffer to make sure always avaliable */ 
#define CCCI_FS_TGPD_ALIGN_PAD (31)

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
#endif

typedef struct FS_StreamBuffer_STRUCT
{
	CCCI_BUFF_T ccci_header;	
	kal_uint32	fs_operationID;
	kal_uint8	buffer[FS_CCCI_MAX_BUF_SIZE];
} FS_StreamBuffer_T;

typedef struct FS_CCCI_LV_STRUCT
{
   kal_uint32 len;
   void *val;
} FS_CCCI_LV_T;

typedef struct CCCI_FS_PARA
{
    
    kal_int32     index;            /* port index */
    kal_uint32    op_id;            /* FS_CCCI_OP_ID_T */
    FS_CCCI_LV_T  *pLV_in;          /* [IN]  CCCI_FS local variable */
    kal_uint32    LV_in_para_cnt;   /* [IN]  parameter count in LV */
    FS_CCCI_LV_T  *pLV_out;         /* [OUT] CCCI_FS local variable */
    kal_uint32    LV_out_para_cnt;  /* [OUT] parameter count in LV */

    kal_uint32    start_time;
	kal_uint32    end_time;
	kal_uint32    duration;
	kal_uint32    us;
	kal_uint32    ms;
	kal_uint32    total_tick;
	kal_uint32    qbit;	

} CCCI_FS_PARA_T;

typedef enum _ccci_fs_dev_state {
    CCCI_FS_INIT,                  /* FS not ready */
    CCCI_FS_POLLING,               /* FS polling mode ready */
    CCCI_FS_NORMAL,                /* FS normal mode ready */
    CCCI_FS_EXCEPTION,             /* FS exception mode */
    CCCI_TTY_DEV_STATE_CNT
}ccci_fs_dev_state;

typedef enum _ccci_fs_buff_status {
    CCCI_FS_BUFF_IDLE = 0,         /* current port is not waiting for more data */
    CCCI_FS_BUFF_WAIT              /* current port is waiting for more data to come in */
}ccci_fs_buff_status;

typedef struct _fs_tgpd_pool {
    qbm_gpd* pool_head;
    qbm_gpd* pool_tail;
}fs_tgpd_pool;

// CCCI RPC Polling mode trace, will store in share memory    FORMAT: OPID(2bytes) | STEP(2bytes) 
#define CCCI_FS_TRACE_FORMAT(_op, _step) ((_op << 16) | (kal_uint16)_step)
#define CCCI_FS_ADD_CARRY(_a,_b,_carry) \
    do  {   \
        if( _a + _b < _a) _carry++;  \
    }   while(0)

typedef enum
{
    CCCI_FS_TRACE_RPC_INIT = 0x0,
    CCCI_FS_TRACE_START,
    CCCI_FS_TRACE_PUT_BUFF_START,
    CCCI_FS_TRACE_PUT_BUFF_END,
    CCCI_FS_TRACE_WAIT_RX_START,
    CCCI_FS_TRACE_WAIT_RX_END,
    CCCI_FS_TRACE_UL_BUFF_DONE,
    CCCI_FS_TRACE_END,
}CCCI_FS_TRACE_T;


typedef struct _ccci_fs_device_t {
    /* CCCI FS service state */
    ccci_fs_dev_state FS_state;
    
    /* FS request buffer FS_REQ_BUF[FS_CCCI_REQ_BUFFER_NUM][FS_CCCI_MAX_BUF_SIZE] */
    FS_StreamBuffer_T *FS_REQ_BUF;
    
    /* FS request buffer FS_REQ_BUF[FS_CCCI_REQ_BUFFER_NUM][FS_CCCI_MAX_BUF_SIZE] */
    /* should equal to FS_CCCI_MAX_BUF_SIZE*FS_CCCI_REQ_BUFFER_NUM */
    kal_uint32        FS_REQ_BUF_SZ;
    
    /* write bitmap of FS_REQ_BUF, set bitmap in ccci_fs_get_port, clear the bitmap in ccci_fs_put_port */
    /* protected by ccci_fs_emutex */
    kal_uint32 FS_WriteIndex;

    /* number of busy buffer count (or active request count) in FS_REQ_BUF, ++ in ccci_fs_get_port, -- in ccci_fs_put_port*/
    /* protected by ccci_fs_emutex */
    kal_uint32 FS_CCCIBufCount;

    /* event bitmap for the actie FS request, set in ccci_fs_ul_cb, retrive in every command lol.*/
    kal_eventgrpid	FS_CCCI_CSEvgrp;

    /* ccci_fs mutex */
    kal_enhmutexid ccci_fs_emutex;

    /* use to identify mutex lock during polling mode --> KAL not allow to use enhance mutex*/
    kal_bool  ccci_fs_fake_emutex;

    /* use to identify the current hwo rgpd count */
    /* protected by ccci_fs_emutex */
    kal_uint32 hwo_rgpd_count;

#ifdef __CCCI_FS_LT_4K_IO_ENABLE__
    /* use to identify the current hwo rgpd count, ccci_fs_buff_status */
    kal_uint8  ccci_fs_buff_state[FS_CCCI_REQ_BUFFER_NUM];

    /* recording the current buffer offset in FS_REQ_BUF */
    kal_uint32 ccci_fs_buff_offset[FS_CCCI_REQ_BUFFER_NUM];

   /* CCCI FS TGPD */
   fs_tgpd_pool tgpd_pool[FS_CCCI_REQ_BUFFER_NUM];
#endif
   kal_uint32 ccci_fs_dl_seq[FS_CCCI_REQ_BUFFER_NUM];
    /*************************************************************
     *              P O L L I N G     M O D E
     *************************************************************/
    /* polling mode GPD */
    qbm_gpd *p_polling_gpd;
    qbm_gpd *p_polling_gpd_rx1;
    qbm_gpd *p_polling_gpd_rx2;
    /*************************************************************
     *              E X C E P T I O N     M O D E
     *************************************************************/
    void *cccifs_tgpd_h;
    void *cccifs_tgpd_t;
    void *cccifs_tgpd_free_h;
    void *cccifs_tgpd_free_t;
    kal_uint32 wait_ap_time_polling;
    kal_uint32 wait_ap_time_normal;
    kal_uint32 wait_ap_time_normal_carry;
    kal_uint32 polling_step_trace;
} ccci_fs_device_t;

typedef struct CCCI_FS_DEBUG_STATUS
{
    /* CCCI FS service state */
    ccci_fs_dev_state FS_state;
    /* protected by ccci_fs_emutex */
    kal_uint32 FS_WriteIndex;
    /* protected by ccci_fs_emutex */
    kal_uint32 FS_CCCIBufCount;
    /* protected by ccci_fs_emutex */
    kal_uint32 hwo_rgpd_count;
#ifdef __CCCI_FS_LT_4K_IO_ENABLE__
    /* use to identify the current hwo rgpd count, ccci_fs_buff_status */
    kal_uint8  ccci_fs_buff_state[FS_CCCI_REQ_BUFFER_NUM];
    /* recording the current buffer offset in FS_REQ_BUF */
    kal_uint32 ccci_fs_buff_offset[FS_CCCI_REQ_BUFFER_NUM];
   /* CCCI FS TGPD */
   fs_tgpd_pool tgpd_pool[FS_CCCI_REQ_BUFFER_NUM];
#endif
} CCCI_FS_DEBUG_STATUS_T;

typedef enum
{
    CCCI_FS_NORMAL_ASSERT,
    CCCI_FS_EXT_ASSERT,
    CCCI_FS_EXT_ASSERT_DUMP,
}CCCI_FS_ASSERT_TYPE;

/*************************************************************
 *              I N T E R N A L     M A C R O S
 *************************************************************/
#define CCCI_FS_GET_QBM_DATALEN          CCCIDEV_GET_QBM_DATALEN
#define CCCI_FS_SET_QBM_DATALEN          CCCICOMM_SET_QBM_DATALEN
#define CCCI_FS_GET_QBM_DATAPTR          CCCIDEV_GET_QBM_DATAPTR
#define CCCI_FS_GET_GPD_LIST_SIZE        CCCIDEV_GET_GPD_LIST_SIZE
#define CCCI_FS_GET_NONBPS_GPD_LIST_SIZE CCCIDEV_GET_NONBPS_GPD_LIST_SIZE
#define CCCI_FS_FIX_IOR_NULL_LAST        CCCIDEV_FIX_IOR_NULL_LAST
#define CCCI_FS_RM_CCCI_HEADERS          CCCIDEV_RM_CCCI_HEADERS
#define CCCI_FS_RST_GPD_LIST             CCCIDEV_RST_CCCI_COMM_GPD_LIST
/*************************************************************
 *              I N T E R N A L     A P I S
 *************************************************************/
void ccci_fs_enter_cs(void);
void ccci_fs_exit_cs(void);
kal_int32 ccci_fs_get_port(kal_int32 *p_index);
kal_int32 ccci_fs_put_port(kal_int32 index);
kal_int32 ccci_fs_put_buff(kal_int32 index, kal_uint32 op, FS_CCCI_LV_T *pLV, kal_uint32 num);
kal_int32 ccci_fs_get_buff(kal_int32 index, kal_uint32 op, FS_CCCI_LV_T *pLV, kal_uint32 *num);
void ccci_fs_wait_rx(kal_int32 index);
void ccci_fs_wait_rx_exception(kal_int32 index);
void ccci_fs_exception_assert(CCCI_FS_ASSERT_TYPE type, kal_bool expr, kal_uint32 e1, kal_uint32 e2, kal_uint32 e3, void *param, kal_uint32 errorline);

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

/* For GPD it will reset flag and allowlen and clear checksum */
/* Because in descriptor, they are in the first 4 bytes */
#define CCCI_INIT_RESET_FLAG_CHECKSUM_ALLOWLEN(_p, allowlen, flag) *(kal_uint32*)_p = (allowlen << 16) | flag
          
#ifdef __CCCI_FS_LT_4K_IO_ENABLE__
/* AP raise ccci_h->addr[31] inidicating sending more UL buffer */
#define CCCI_FS_SEND_AGAIN 0x80000000
#define CCCI_FS_PEER_REQ_SEND_AGAIN(_p) (((CCCI_STREAM_ADDR(_p) & CCCI_FS_SEND_AGAIN) != 0)? 1: 0)
#endif

/*************************************************************
 *              E X C E P T I O N    M O D E
 *************************************************************/
extern kal_bool INT_QueryExceptionStatus(void);
kal_uint32 CCCI_FS_OP_Wrapper_Expt(CCCI_FS_PARA_T* fs_para);

extern ccci_fs_device_t g_ccci_fs_int;

// The reason + QBM_HEAD_SIZE is for ROME E1, cldma needs to record this buff whether is cacheable or non-cacheable
extern kal_uint8 g_fs_polling_req_buf[FS_CCCI_POLLING_BUFF_SIZE + QBM_HEAD_SIZE];
extern kal_uint8 g_fs_polling_req_buf_rx1[FS_CCCI_POLLING_BUFF_SIZE + QBM_HEAD_SIZE];
extern kal_uint8 g_fs_polling_req_buf_rx2[FS_CCCI_POLLING_BUFF_SIZE + QBM_HEAD_SIZE];

#define IS_CCCI_FS_NORMAL_MODE() (KAL_TRUE != kal_query_systemInit() && KAL_FALSE == INT_QueryExceptionStatus())
#define IS_CCCI_FS_POLLING_MODE() (KAL_TRUE == kal_query_systemInit() && KAL_FALSE == INT_QueryExceptionStatus())
#define IS_CCCI_FS_EXCEPTION_MODE() (KAL_TRUE == INT_QueryExceptionStatus())
#define CCCI_FS_ASSERT_DUMP_LENGTH 32
#define CCCI_FS_ASSERT(type, expr, e1, e2, e3, param, errorline) \
        do{ \
            if(!(expr)){ \
                if(IS_CCCI_FS_NORMAL_MODE() || IS_CCCI_FS_POLLING_MODE()){  \
                    if(type == CCCI_FS_NORMAL_ASSERT) ASSERT(expr); \
                    else if(type == CCCI_FS_EXT_ASSERT) EXT_ASSERT(expr,e1,e2,e3); \
                    else if(type == CCCI_FS_EXT_ASSERT_DUMP) EXT_ASSERT_DUMP(expr,e1,e2,e3,param); \
                } \
                else if(IS_CCCI_FS_EXCEPTION_MODE()){ \
                    ccci_fs_exception_assert(type, expr, e1, e2, e3, param, errorline); \
                } \
            } \
        }while(0) 

#define ccci_fs_get_current_time ccci_get_current_time
#define ccci_fs_get_duration ccci_get_duration

#endif //_CCCI_FS_H
