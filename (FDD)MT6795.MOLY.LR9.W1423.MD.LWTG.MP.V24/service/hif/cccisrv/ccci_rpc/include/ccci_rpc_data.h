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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ccci_rpc_data.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Header file of CCCI_RPC data path.
 *
 * Author:
 * -------
 * -------
 *
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
 * [CCCI] CCCI new debug mechanism
 *
 * removed!
 * removed!
 * [CCCI] Add & Maintain UT code
 *
 * removed!
 * removed!
 * [CCCI RPC] Debug enhancement & Add log.
 *
 * removed!
 * removed!
 * 	[CCCI RPC] Add init gpd list in wrapper function.
 *
 * 05 09 2013 ap.wang
 * removed!
 * [CCCI RPC] CCCI RPC IT modify and rx callback rule modify
 *
 * removed!
 * removed!
 * Integration change.
 *
 * removed!
 * removed!
 * fix compile warning and build error
 ****************************************************************************/

#ifndef __CCCI_RPC_DATA_H__
#define __CCCI_RPC_DATA_H__


#include "ccci_if.h"
#include "cccidev_qbm.h"
#include "ccci.h"
#include "ccci_rpc_if.h"
#include "us_timer.h"
#include "ccci_rpc_common.h"

/*******************************************************************************
 * Define marco or constant.
 *******************************************************************************/

#define RPC_MSGSVC_RVC_DONE 0x12344321

#ifdef __GEMINI__
#define MAX_NUM_IPC_TASKS   4
#else
#define MAX_NUM_IPC_TASKS   3
#endif

#define IPC_MSG_MAX_RETRY 	0xFFFF


#define CCCI_IPC_VALID_MSG_ID_MASK    0xFF
#define CCCI_IPC_TO_AP_MSG_START      (0x80000000)
#define CCCI_IPC_TO_KAL_MSG_START     (IPC_MSG_ID_INVALID_TYPE)

#define PUBLIC
#define PRIVATE
//#define IPC_RPC_EXCEPT_MAX_RETRY     7
//#define IPC_RPC_MAX_RETRY            0xFFFF
#define IPC_RPC_REQ_BUFFER_NUM       2 /* support 2 concurrently request*/
#define IPC_RPC_MAX_ARG_NUM          6 /* parameter number */
#define IPC_RPC_MAX_BUF_SIZE         2048

#define IPC_RPC_USE_DEFAULT_INDEX    -1
#define IPC_RPC_API_RESP_ID          0xFFFF0000
#define IPC_RPC_INC_BUF_INDEX(x)     (x = (x + 1) % IPC_RPC_REQ_BUFFER_NUM)


#define IPC_RPC_INPUT_TERM_PATTERN   0xFFFFFFFE
#define IPC_RPC_EOF_TERM_PATTERN     0xFFFFFFFF
#define IPC_RPC_USE_DEFAULT_INDEX    -1
#define IPC_RPC_API_RESP_ID          0xFFFF0000

/*******************************************************************************
 * Define data structure.
 *******************************************************************************/


typedef struct IPC_RPC_LV_STRUCT
{
    kal_uint32 len;
    void *val;
} IPC_RPC_LV_T;

typedef struct IPC_RPC_StreamBuffer_STRUCT
{
    CCCI_BUFF_T   ccci_header;
    kal_uint32    rpc_opid;
    kal_uint32	  num_para;
    kal_uint8     buffer[IPC_RPC_MAX_BUF_SIZE];
	
} IPC_RPC_StreamBuffer_T;
typedef IPC_RPC_StreamBuffer_T* pIPC_RPC_StreamBuffer_T;


typedef enum
{
    IPC_RPC_CCCI_WRITE_REQUEST,
    IPC_RPC_CCCI_WRITE_NO_PHYSICAL_CHANNEL,
    IPC_RPC_CCCI_READ_OPID_NOT_SYNC,
    IPC_RPC_CCCI_READ_RESULT_NO_NOT_SYNC,
    IPC_RPC_CCCI_READ_RESULT_LEN_NOT_ENOUGH,
    IPC_RPC_CCCI_CALLBACK_ADDR_NOT_SYNC,
    IPC_RPC_CCCI_WRITE_BUF_FUL
    
} IPC_RPC_ERROR_CODE;

typedef enum
{
    IPC_RPC_CCCI_WRITE_ONLY_UT,
    IPC_RPC_CCCI_WHOLE_PATH_UT
    
} UT_FLAG_CODE;

// CCCI RPC Polling mode trace, will store in share memory    FORMAT: OPID(2bytes) | STEP(2bytes) 
#define IPC_RPC_TRACE_FORMAT(_op, _step) ((_op << 16) | (kal_uint16)_step)
#define CCCI_RPC_ADD_CARRY(_a,_b,_carry) \
    do  {   \
        if( _a + _b < _a) _carry++;  \
    }   while(0)

typedef enum
{
    IPC_RPC_CCCI_TRACE_RPC_INIT = 0x0,
    IPC_RPC_CCCI_TRACE_START,
    IPC_RPC_CCCI_TRACE_WRITE_POLLING_START,
    IPC_RPC_CCCI_TRACE_WRITE_POLLING_END,
    IPC_RPC_CCCI_TRACE_READ_POLLING_START,
    IPC_RPC_CCCI_TRACE_READ_POLLING_END,
    IPC_RPC_CCCI_TRACE_END,
}IPC_RPC_CCCI_TRACE_T;

/* Struct to define the control channel of RPC service */
typedef struct CCCI_RPC_STRUCT
{
    kal_uint32 send_channel;            /* RPC channel for TX */
    kal_uint32 receive_channel;         /* RPC channel for RX */
    kal_eventgrpid event;               /* notify event */
    kal_semid semaphore;                /* Use to protect critical section */
    kal_int32 fake_semaphore;           /* Use to protect critical section befor TST_Schedule*/
    /* <CCCI released APIs> */
    kal_int32  (*ccci_write_gpd)(CCCI_CHANNEL_T channel, ccci_io_request_t *p_ccci_DL_ior, ccci_io_ext_info_t* pextinfo);
    kal_int32  (*ccci_init_gpdior)(CCCI_CHANNEL_T channel, CCCI_IORCALLBACK ior_funp);
    kal_int32  (*ccci_deinit)(CCCI_CHANNEL_T channel);
    kal_int32  (*ccci_rpc_polling_io)(CCCI_CHANNEL_T channel,qbm_gpd * p_gpd,kal_bool is_tx);
    kal_bool   (*check_kal_systemInit)(void);
    kal_uint32 ut_flag;
    qbm_gpd *p_polling_gpd;             /* polling mode GPD */
    kal_uint32 allocated_gpd_number;
    kal_uint32 polling_step_trace; // CCCI RPC Polling mode trace, will store in share memory
    kal_uint32 wait_ap_time_polling;
    kal_uint32 wait_ap_time_normal_carry;
    kal_uint32 wait_ap_time_normal;
} CCCI_RPC_T;

typedef struct RPC_GPDS_POOL_STRUCT
{
    qbm_gpd     *gpd_ptr;             /* RPC gpd pointer */
    kal_uint32  gpd_occupied;         /* RPC gpd occupied*/

} RPC_GPDS_POOL_T;

typedef struct CCCI_RPC_DEBUG_STATUS
{
  kal_uint32 allocated_gpd_number;
  RPC_GPDS_POOL_T rpc_gpd_pool[CCCI_RPC_GPD_NUMBER];
} CCCI_RPC_DEBUG_STATUS_T;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

extern IPC_RPC_StreamBuffer_T *RPC_REQ_BUF;


/*******************************************************************************
 * Define export function prototype.
 *******************************************************************************/
extern PUBLIC kal_semid       g_IPC_RPC_CSSemId;
extern PUBLIC kal_eventgrpid  g_IPC_RPC_CSEvgrp;


/*******************************************************************************
 * Declare function prototype.
 *******************************************************************************/
extern void ccci_rpc_init(void);
extern kal_int32 ccci_rpc_allocate_gpds();
extern kal_int32 IPC_RPC_Wrapper(IPC_RPC_OP_ID_T rpc_op,...);
extern kal_int32 IPC_RPC_CCCI_Write(kal_int32 *index, kal_uint32 op, IPC_RPC_LV_T *pLV, kal_uint32 num);
extern void ccci_rpc_receive_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* ior);
extern void ccci_rpc_send_cb(CCCI_CHANNEL_T channel, ccci_io_request_t* ior);
extern void IPC_RPC_Process_CMD(kal_int32 index);
extern kal_int32 IPC_RPC_CCCI_Read(kal_int32 index, kal_uint32 op, IPC_RPC_LV_T *pLV, kal_uint32 *num);

#define ccci_rpc_get_current_time ccci_get_current_time
#define ccci_rpc_get_duration ccci_get_duration

#ifdef __CCCI_IT_CTRL__
extern kal_bool ccci_rpc_it_create(void);
#endif

#endif // !__CCCI_RPC_DATA_H__
