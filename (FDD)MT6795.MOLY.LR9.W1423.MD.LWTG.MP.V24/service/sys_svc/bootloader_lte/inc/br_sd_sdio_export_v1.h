/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *   br_sd_sdio_export_v1.h
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *   BOOTROM sdio shared driver version 1 (EXPORTED APIs)
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __BR_SD_SDIO_EXPORT_V1_H__
#define __BR_SD_SDIO_EXPORT_V1_H__

#include "br_sw_types.h"
#include "sdio_fw_api.h"
#include "sdio_fw.h"
#include "sdio_gpd.h"

#ifdef __cplusplus
extern "C" {
#endif

//for sdio handshake magic pattern
#define SDIOMAIL_BOOTING_REQ_MAGIC  0x53444254  //"SDBT"
#define SDIOMAIL_BOOTING_ACK_MAGIC  0x53425400  //"SBTx"
#define SDIOMAIL_DOWNLOAD_REQ_MAGIC 0x5344444C  //"SDDL"
#define SDIOMAIL_DOWNLOAD_ACK_MAGIC 0x53444C00  //"SDLx"
#define SDIOMAIL_REQ_REFUSE_MAGIC   0x52454655  //"REFU"
#define SDIOMAIL_ACK_TIMEOUT_MASK   0x000000FF  //time can be 0~255, unit is 10ms
#define SDIOMAIL_TIMEOUT_UNIT_MS    (10)        //unit is 10ms

//==============================================================================
// Shared SDIO driver function prototype
//==============================================================================

typedef SDIO_STATUS (*SD_SDIO_INIT_V1)(void (*timer_callback)(kal_uint32), kal_uint32 timeout);
typedef SDIO_STATUS (*SD_SDIO_OPEN_V1)(PSDIO_USER_HANDLE pUser_handle, PSDIO_USER_REQ_DESCRIPTOR pUser_Req);
typedef void        (*SD_SDIO_CLOSE_V1)(PSDIO_USER_HANDLE pUser_handle);
typedef SDIO_STATUS (*SD_SDIO_RX_V1)(PSDIO_USER_HANDLE pUser_handle, PSDIO_BUFFER_DESCRIPTOR bd, kal_uint32 timeout_ms);
typedef SDIO_STATUS (*SD_SDIO_TX_V1)(PSDIO_USER_HANDLE pUser_handle, PSDIO_BUFFER_DESCRIPTOR bd, kal_uint32 timeout_ms);  
typedef SDIO_STATUS (*SD_SDIO_D2H_SEND_MAILBOX_V1)(PSDIO_USER_HANDLE pUser_Handle, kal_uint32 cmd, kal_uint32 timeout_ms);
typedef SDIO_STATUS (*SD_SDIO_H2D_RECEIVE_MAILBOX_V1)(PSDIO_USER_HANDLE pUser_Handle, kal_uint32 *resp, kal_uint32 timeout_ms);

//==============================================================================
// Shared SDIO driver function table
//==============================================================================
typedef struct SD_R_SDIO_FuncTable_v1 {
    SD_SDIO_INIT_V1                 m_sdio_init;
    SD_SDIO_OPEN_V1                 m_sdio_open;
    SD_SDIO_CLOSE_V1                m_sdio_close;
    SD_SDIO_RX_V1                   m_sdio_rx;
    SD_SDIO_TX_V1                   m_sdio_tx;
    SD_SDIO_D2H_SEND_MAILBOX_V1     m_sdio_send_mailbox;
    SD_SDIO_H2D_RECEIVE_MAILBOX_V1  m_sdio_receive_mailbox;
} SD_R_SDIO_FuncTable_v1;

#ifdef __cplusplus
}
#endif

#endif


