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
 *   ccci_ipc_data.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Header file of CCCI_IPC data path.
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
 * 	[CCCI] Show CCCI IPC ILM's local parameter in ELT
 *
 * 03 11 2013 ap.wang
 * removed!
 * [CCCI_IPC] Modify for IT Loopback and compile warning fix
 ****************************************************************************/

#ifndef __CCCI_IPC_DATA_H__
#define __CCCI_IPC_DATA_H__


#include "ccci_if.h"
#include "cccidev_qbm.h"


/*******************************************************************************
 * Define constants.
 *******************************************************************************/

#define IPC_MSGSVC_RVC_DONE 0x12344321

#ifdef __GEMINI__
#define MAX_NUM_IPC_TASKS   4
#else
#define MAX_NUM_IPC_TASKS   3
#endif

#define IPC_MSG_MAX_RETRY 	0xFFFF


#define CCCI_IPC_VALID_MSG_ID_MASK    0xFF
#define CCCI_IPC_TO_AP_MSG_START      (0x80000000)
#define CCCI_IPC_TO_KAL_MSG_START     (MSG_ID_IPC_INVALID_TYPE)


/*******************************************************************************
 * Define data structures.
 *******************************************************************************/

typedef enum _ccci_ipc_it_mode {
    CCCI_IPC_IT_DISABLE = 0,
    CCCI_IPC_IT_LB,       /* Loopback with extq_id*/ 
    CCCI_IPC_IT_MAX                      
} CCCI_IPC_IT_MODE_T;


/* Struct to define the control channel of IPC msg service */
typedef struct CCCI_IPC_STRUCT
{
    kal_uint32 send_channel;            /* IPC channel for TX */
    kal_uint32 send_ack_channel;        /* IPC channel for TX ACK */
    kal_uint32 receive_channel;         /* IPC channel for RX */
    kal_uint32 receive_ack_channel;   	/* IPC channel for RX ACK */
    kal_eventgrpid event;               /* notify event */
    kal_semid semaphore;                /* Use to protect critical section */
    kal_int32 fake_semaphore;           /* Use to protect critical section befor TST_Schedule*/
    /* <CCCI released APIs> */
    kal_int32  (*ccci_write_gpd)(CCCI_CHANNEL_T channel, ccci_io_request_t *p_ccci_DL_ior, ccci_io_ext_info_t* pextinfo);
    kal_int32  (*ccci_init_gpdior)(CCCI_CHANNEL_T channel, CCCI_IORCALLBACK ior_funp);
    kal_int32  (*ccci_deinit)(CCCI_CHANNEL_T channel);

    qbm_gpd *p_polling_gpd;             /* polling mode GPD */
    kal_uint32 reload_rgpd_number;
    CCCI_IPC_IT_MODE_T it_mode;
} CCCI_IPC_T;


/* Struct to define the mapping between task and external label */
typedef struct IPC_MSGSVC_TASKMAP_STRUCT
{
    kal_uint32  extq_id;            /* IPC universal mapping external queue */
    kal_uint32  task_id;            /* IPC processor internal task id */

} IPC_MSGSVC_TASKMAP_T;


/* Struct to define the mapping between task and external label */
typedef struct CCCI_IPC_ILM_STRUCT
{
    ipc_ilm_t ipc_ilm;            /* IPC universal mapping external queue */
    kal_uint32 used;            /* Use to check is used or not */

} CCCI_IPC_ILM_T;

typedef struct CCCI_IPC_DEBUG_STATUS
{
    kal_uint32 reload_rgpd_number;
} CCCI_IPC_DEBUG_STATUS_T;

/*******************************************************************************
 * Define macros.
 *******************************************************************************/
#define CCCI_AP_MSG_TO_KAL_MSG(ap_msg_id, kal_msg_id)    do { \
        kal_msg_id = (ap_msg_id & CCCI_IPC_VALID_MSG_ID_MASK) | CCCI_IPC_TO_KAL_MSG_START; \
    } while(0)

#define CCCI_KAL_MSG_TO_AP_MSG(kal_msg_id, ap_msg_id)    do { \
        ap_msg_id = (kal_msg_id & CCCI_IPC_VALID_MSG_ID_MASK) | CCCI_IPC_TO_AP_MSG_START; \
    } while(0)

void ccci_ipc_init(void);

/* start from 0 */
#define GET_CCCI_IPC_MSGID_POS(_msgid) ((_msgid - MSG_ID_CCCI_MSG_CODE_BEGIN) & CCCI_IPC_VALID_MSG_ID_MASK)

#define ccci_ipc_get_current_time ccci_get_current_time
#define ccci_ipc_get_duration ccci_get_duration

#endif // !__CCCI_IPC_DATA_H__
