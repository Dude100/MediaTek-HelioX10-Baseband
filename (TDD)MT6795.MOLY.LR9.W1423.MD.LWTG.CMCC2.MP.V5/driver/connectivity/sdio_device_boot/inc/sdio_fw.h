/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 * sdio_fw.h
 *
 * Project:
 * --------
 *   SDIO Device Firmware 
 *
 * Description:
 * ------------
 *   
 *
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef SDIO_FW_H
#define SDIO_FW_H

#include "sdio_fw_drv_config.h"

#if !defined(SDIO_UNIT_TEST) && defined(__BOOTROM__)
#include "br_MTK_BB.h"
#endif

#include "sdio_gpd.h"


// ========================================
//
// Define hardware limitation.
//
// ========================================
#define _2KB    (2024 * 4)
#define _4KB    (1024 * 4)
#define _64KB   (16 * _4KB)
#define SDIO_TX_PACKET_SIZE     _4KB
#define SDIO_RX_PACKET_SIZE     _64KB-1

#define SDIO_MAX_TX_QUEUE_NUM 1
#define SDIO_MAX_RX_QUEUE_NUM 1


// ========================================
//
// Macro for improving code readability
//
// ========================================
#define SDIO_RX 0
#define SDIO_TX 1

#define SDIO_DEFAULT_TQ_IDX 0
#define SDIO_DEFAULT_RQ_IDX 0

#define SDIO_SWINT_MB0_BROMSEND   0x00010000
#define SDIO_SWINT_MB0_BROMRECV   0x00020000
#define SDIO_SWINT_MB_SENDDATA    0x00010000
#define SDIO_SWINT_MB_RECVDATA    0x00020000
#define SDIO_SWINT_ERROR_BROMSEND 0x00040000
#define SDIO_SWINT_ERROR_BROMRECV 0x00080000


// ========================================
//
// Define driver data structures
//
// ========================================

typedef struct _SDIO_QUEUE_HANDLE {
    PSDIO_GPDH_Node pGPD_Enq;
    PSDIO_GPDH_Node pGPD_Deq;
    kal_uint8   Nodes_Limit;
    kal_uint8   Nodes_Current;
    kal_uint8   isTX;

	kal_uint8  *TX_USER_Buffer;
	kal_uint8  *TX_USER_Buffer_Write_Ptr;
} SDIO_QUEUE_HANDLE, *PSDIO_QUEUE_HANDLE;

#define SDIO_QUEUE_GET_GPD_ENQ(PQUEUE)        (PQUEUE->pGPD_Enq)
#define SDIO_QUEUE_SET_GPD_ENQ(PQUEUE, ENQ)   (PQUEUE->pGPD_Enq=ENQ)
#define SDIO_QUEUE_GET_GPD_DEQ(PQUEUE)        (PQUEUE->pGPD_Deq)
#define SDIO_QUEUE_SET_GPD_DEQ(PQUEUE, DEQ)   (PQUEUE->pGPD_Deq=DEQ)
#define SDIO_QUEUE_GET_Q_HW_IDX(PQUEUE)       (PQUEUE->Q_HW_Idx)
#define SDIO_QUEUE_SET_Q_HW_IDX(PQUEUE, IDX)  (PQUEUE->Q_HW_Idx=IDX)
#define SDIO_QUEUE_GET_NODES_LIMIT(PQUEUE)    (PQUEUE->Nodes_Limit)
#define SDIO_QUEUE_SET_NODES_LIMIT(PQUEUE, LIMIT) (PQUEUE->Nodes_Limit=LIMIT)
#define SDIO_QUEUE_GET_NODES_CURRENT(PQUEUE)  (PQUEUE->Nodes_Current)
#define SDIO_QUEUE_SET_NODES_CURRENT(PQUEUE, CUR) (PQUEUE->Nodes_Current=CUR)
#define SDIO_QUEUE_DEC_NODES_CURRENT(PQUEUE, DEC) (PQUEUE->Nodes_Current-=DEC)
#define SDIO_QUEUE_INC_NODES_CURRENT(PQUEUE, INC) (PQUEUE->Nodes_Current+=INC)
#define SDIO_QUEUE_GET_ISTX(PQUEUE)           (PQUEUE->isTX)
#define SDIO_QUEUE_SET_ISTX(PQUEUE, ISTX)     (PQUEUE->isTX=ISTX)
#define SDIO_QUEUE_GET_TX_USER_BUFFER(PQUEUE, BUF)         (PQUEUE->TX_USER_Buffer)
#define SDIO_QUEUE_SET_TX_USER_BUFFER(PQUEUE, BUF)         (PQUEUE->TX_USER_Buffer=BUF)
#define SDIO_QUEUE_GET_TX_USER_BUFFER_WR_PTR(PQUEUE)       (PQUEUE->TX_USER_Buffer_Write_Ptr)
#define SDIO_QUEUE_SET_TX_USER_BUFFER_WR_PTR(PQUEUE, PTR)  (PQUEUE->TX_USER_Buffer_Write_Ptr=PTR)
#define SDIO_QUEUE_INC_TX_USER_BUFFER_WR_PTR(PQUEUE, INC)  (PQUEUE->TX_USER_Buffer_Write_Ptr+=INC)


typedef struct _SDIO_INT_INFO {
    kal_uint32 HGFISR;
    kal_uint32 HWFISR;
    kal_uint32 HWFTE0SR;
    kal_uint32 HWFRE0SR;
    //kal_uint32 HWFRE01R;
} SDIO_INT_INFO, *PSDIO_INT_INFO;


typedef struct _SDIO_USER_HANDLE {
    PSDIO_GPDH_Node  pGPDH_List;
    kal_uint32       GPDH_Number;

	kal_uint32 *TX_GPDB_Pool;
    kal_uint32 *TX_GPDB_Pool_Head;
    kal_uint32 *TX_GPDB_Pool_Tail;
    kal_uint32  TX_GPDB_Backup_Num;

    SDIO_QUEUE_HANDLE TQ_Handles[SDIO_MAX_TX_QUEUE_NUM];
    SDIO_QUEUE_HANDLE RQ_Handles[SDIO_MAX_RX_QUEUE_NUM];

	SDIO_INT_INFO Int_Info;
	
	kal_uint16 TQ_start_threshold;
	kal_uint16 TQ_supplement_threshold;

    void  (*timer_callback)(kal_uint32);
} SDIO_USER_HANDLE, *PSDIO_USER_HANDLE;


typedef struct _SDIO_QUEUE_REQ_DESCRIPTOR {
    kal_uint8   Q_HW_Idx;
    kal_uint8   isTX;
} SDIO_QUEUE_REQ_DESCRIPTOR, *PSDIO_QUEUE_REQ_DESCRIPTOR;

#define SDIO_QUEUE_REQ_SET_Q_HW_IDX(QUEUE_REQ, IDX)       QUEUE_REQ.Q_HW_Idx=IDX
#define SDIO_QUEUE_REQ_SET_IS_TX(QUEUE_REQ, TX)           QUEUE_REQ.isTX=TX


// ========================================
//
// Define driver internal functions in sdio_fw.c
//
// ========================================
void sdio_error_processing(
    void
    );


#endif
