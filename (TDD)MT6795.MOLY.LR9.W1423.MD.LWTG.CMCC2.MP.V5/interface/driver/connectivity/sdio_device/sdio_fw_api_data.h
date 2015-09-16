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

#ifndef SDIO_API_DATA_H
#define SDIO_API_DATA_H

#include "sdio_fw_maui_drv_config.h"

#if defined(SDIO_MAUI_ENV)
#include "kal_public_api.h"

#elif defined(SDIO_IVP_ENV)
#include "typedefs.h"

#endif


// ========================================
//
// Define hardware dependency limitation.
//
// ========================================
#define _2KB    (2024 * 4)
#define _4KB    (1024 * 4)
#define _64KB   (16 * _4KB)
#define SDIO_TX_PACKET_SIZE     _4KB
#define SDIO_TX_BUFFER_SIZE     _4KB
#define SDIO_RX_PACKET_SIZE     0xff80   //use 65408 to fit 512*128 limitation _64KB-1
#define SDIO_RX_BUFFER_SIZE     _64KB


// ========================================
//
// Macro for improving code readability
//
// ========================================
#define SDIO_RX 0
#define SDIO_TX 1


///////////////////////////////////////////////////////////////////
//
// Data Section
//
///////////////////////////////////////////////////////////////////

#define SDIO_MAX_TIMEOUT   0xFFFFFFFF
#define SDIO_TX_GPDB_SIZE  0x1000         //4kb


typedef enum _SDIO_STATUS {
    SDIO_SUCCESS = 0
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
    ,SDIO_QUEUE_PARTIALLY_ENQ     = SDIO_BASIS + 0xE
    ,SDIO_ABNORMAL_HOST_BEHAVIOR  = SDIO_BASIS + 0xF
    ,SDIO_ABNORMAL_SETTING        = SDIO_BASIS + 0x10
    ,SDIO_ERROR                   = SDIO_BASIS + 0x11
} SDIO_STATUS;

#define SDIO_FAILED(status) ((status) > SDIO_BASIS)


typedef enum _SDIO_FLAG {
    FLAG_PURE_BUFFER    = 0x0001     //Buffer contain no CCCI header and maynot fit GPD buffer limitation
    ,FLAG_GIO_BUFFER     = 0x0002     //Buffer contain GPD and CCCI header and fit size limitation of GPD buffer
    ,FLAG_NONGIO_BUFFER  = 0x0004     //Buffer contain CCCI header and fit size limitation of GPD buffer
  //,FLAG_POLLING_WAIT   = 0x0008
  //,FLAG_INTERRUPT_WAIT = 0x0010
    ,FLAG_TX             = 0x0020
    ,FLAG_RETURN         = 0x1000
    ,FLAG_ERROR          = 0x4000
} SDIO_FLAG;

typedef enum _SDIO_WDT_RESET_REASON {
    SDIO_WDT_RESET_HW   = 0x0001
    ,SDIO_WDT_RESET_SW   = 0x0002
} SDIO_WDT_RESET_REASON;



typedef struct _SDIO_USER_REQ_DESCRIPTOR {
    kal_uint8    User_Type;
    kal_uint8    TQ_Num_Req;
    kal_uint8    RQ_Num_Req;

} SDIO_USER_REQ_DESCRIPTOR, *PSDIO_USER_REQ_DESCRIPTOR;

#define SDIO_USER_REQ_SET_USER_TYPE(USER_REQ, TYPE) USER_REQ.User_Type=TYPE
#define SDIO_USER_REQ_SET_TQ_NUM(USER_REQ, NUM)     USER_REQ.TQ_Num_Req=NUM
#define SDIO_USER_REQ_SET_RQ_NUM(USER_REQ, NUM)     USER_REQ.RQ_Num_Req=NUM


typedef struct _SDIO_BUFFER_DESCRIPTOR {
    kal_uint8   priority;
    kal_uint32  address;
    kal_uint32  length;

} SDIO_BUFFER_DESCRIPTOR, *PSDIO_BUFFER_DESCRIPTOR;

#define SDIO_BUFFER_SET_PRIORITY(BD, PRIORITY)  BD.priority=PRIORITY
#define SDIO_BUFFER_SET_ADDRESS(BD, ADDRESS)    BD.address=ADDRESS
#define SDIO_BUFFER_SET_LENGTH(BD, LENGTH)      BD.length=LENGTH
#define SDIO_PBUFFER_SET_LENGTH(BD, LENGTH)     BD->length=LENGTH


typedef struct _SDIO_QUERY_INFO_ENTRY {
	kal_uint16  flags;                   //refer to _SDIO_FLAG
	kal_uint16  length;                   //refer to _SDIO_FLAG
	kal_uint32  buffer_addr;
} SDIO_QUERY_INFO_ENTRY, *PSDIO_QUERY_INFO_ENTRY;
// _SDIO_FLAG: Allow flag values
//   1. If 2nd MSB (2nd highest bit) of _SDIO_FLAG is 1, _SDIO_FLAG use defintion of enum _SDIO_FLAG.
//      Else, definition of enum _SDIO_STATUS is used to carry error status --> not used for TX
//   2. Queue index from user's view-point (not HW queue index) is placed at bit 24~27 --> abandon


#endif
