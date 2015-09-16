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
 * sdio_api.h
 *
 * Project:
 * --------
 *   SDIO Device Firmware 
 *
 * Description:
 * ------------
 *   This file list APIs provided to target environment in which no ISR and
 *   multi-tasking are available. Driver for the target environment does not
 *   share the same API and source/binary files with driver for environment 
 *   with ISR and multi-tasking.
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef _SDIO_FW_API_H_
#define _SDIO_FW_API_H_

#include "sdio_fw.h"


//////////////////////////////////////////////////////////////////////////////
//
// Data structure Section
//
//////////////////////////////////////////////////////////////////////////////

#define SDIO_MAX_TIMEOUT   0xFFFFFFFF
#define SDIO_TX_GPDB_SIZE  0x1000         //4kb
#define SDIO_DEFAULT_TX_START_THRESHOLD         0
#define SDIO_DEFAULT_TX_SUPPLEMENT_THRESHOLD    0
#define SDIO_DEFAULT_TX_NO_PRESTART             0xFFFF

typedef enum _SDIO_STATUS {
    SDIO_SUCCESS                  = 0
    ,SDIO_BASIS                   = SDIO_STATUS_BASIS
    ,SDIO_HW_WRITE_TIMEOUT        = SDIO_BASIS + 0x1
    ,SDIO_HW_READ_TIMEOUT         = SDIO_BASIS + 0x2
    ,SDIO_TX_CRC_ERROR            = SDIO_BASIS + 0x3
    ,SDIO_TX_OVERFLOW             = SDIO_BASIS + 0x4
    ,SDIO_RX_UNDERFLOW            = SDIO_BASIS + 0x5
    ,SDIO_RX_LEN_OVERFLOW         = SDIO_BASIS + 0x6
    ,SDIO_HOST_MOUNT_TIMEOUT      = SDIO_BASIS + 0x7
    ,SDIO_USER_TIMEOUT            = SDIO_BASIS + 0x8
    ,SDIO_ILLEGAL_ACCESS          = SDIO_BASIS + 0x9
    ,SDIO_RESOURCE_NOT_ENOUGH     = SDIO_BASIS + 0xA
    ,SDIO_RESOURCE_CONFLICT       = SDIO_BASIS + 0xB
    ,SDIO_QUEUE_FULL              = SDIO_BASIS + 0xC
    ,SDIO_QUEUE_EMPTY             = SDIO_BASIS + 0xD
    ,SDIO_ABNORMAL_HOST_BEHAVIOR  = SDIO_BASIS + 0xE
    ,SDIO_ABNORMAL_SETTING        = SDIO_BASIS + 0xF
    ,SDIO_ERROR                   = SDIO_BASIS + 0x10
} SDIO_STATUS;


typedef struct _SDIO_USER_REQ_DESCRIPTOR {
    // User shall pass information about memory space for GPD headers and number of GPD headers
    PSDIO_GPDH_Node  pGPDH_List;
    kal_uint16   TX_GPDH_Number;
	kal_uint16   RX_GPDH_Number;

    kal_uint16  TQ_start_threshold;
	kal_uint16  TQ_supplement_threshold;

    kal_uint32  *TX_GPDB_Pool;
    kal_uint32   TX_GPDB_Backup_Num;

    void        (*timer_callback)(kal_uint32);
} SDIO_USER_REQ_DESCRIPTOR, *PSDIO_USER_REQ_DESCRIPTOR;

#define SDIO_USER_REQ_SET_GPDH_LIST(USER_REQ, GPDH_LIST) USER_REQ.pGPDH_List=GPDH_LIST
#define SDIO_USER_REQ_SET_TX_GPDH_NUM(USER_REQ, GPDH_NUM) USER_REQ.TX_GPDH_Number=GPDH_NUM
#define SDIO_USER_REQ_SET_RX_GPDH_NUM(USER_REQ, GPDH_NUM) USER_REQ.RX_GPDH_Number=GPDH_NUM
#define SDIO_USER_REQ_SET_TIMER_CALLBACK(USER_REQ, FUNC) USER_REQ.timer_callback=FUNC
#define SDIO_USER_REQ_SET_TX_GPDB(USER_REQ, GPDB) USER_REQ.TX_GPDB_Pool=GPDB
#define SDIO_USER_REQ_SET_TX_GPDB_NUM(USER_REQ, GPDB_NUM) USER_REQ.TX_GPDB_Backup_Num=GPDB_NUM
#define SDIO_USER_REQ_SET_TX_START_THRESHOLD(USER_REQ, NUM) USER_REQ.TQ_start_threshold=NUM
#define SDIO_USER_REQ_SET_TX_SUPPLEMENT_THRESHOLD(USER_REQ, NUM) USER_REQ.TQ_supplement_threshold=NUM


typedef struct _SDIO_BUFFER_DESCRIPTOR {
    kal_uint32  address;
    kal_uint32  length;

} SDIO_BUFFER_DESCRIPTOR, *PSDIO_BUFFER_DESCRIPTOR;

#define SDIO_BUFFER_SET_ADDRESS(BD, ADDRESS) BD.address=ADDRESS;
#define SDIO_BUFFER_SET_LENGTH(BD, LENGTH)   BD.length=LENGTH;


//////////////////////////////////////////////////////////////////////////////
//
// API Section
//
//////////////////////////////////////////////////////////////////////////////

extern SDIO_STATUS sdio_init(
    void (*timer_callback)(kal_uint32),
    kal_uint32 timeout
    );


extern SDIO_STATUS sdio_open(
    PSDIO_USER_HANDLE         pUser_handle,
    PSDIO_USER_REQ_DESCRIPTOR pUser_Req
    );


extern void sdio_close(
    PSDIO_USER_HANDLE         pUser_handle
    );


extern SDIO_STATUS sdio_rx(
    PSDIO_USER_HANDLE         pUser_handle,
    PSDIO_BUFFER_DESCRIPTOR   bd,
    kal_uint32                timeout_period //in ms
    );


extern SDIO_STATUS sdio_tx(
    PSDIO_USER_HANDLE         pUser_handle,
    PSDIO_BUFFER_DESCRIPTOR   bd,
    kal_uint32                timeout_period //in ms
    );

   
extern SDIO_STATUS sdio_D2H_send_mailbox(
    PSDIO_USER_HANDLE pUser_Handle,
    kal_uint32 cmd,
    kal_uint32 timeout
    );


extern SDIO_STATUS sdio_H2D_receive_mailbox(
    PSDIO_USER_HANDLE pUser_Handle,
    kal_uint32 *resp,
    kal_uint32 timeout
    );

#endif
