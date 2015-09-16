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
 *   br_xboot_cmd.h
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *  X-booting command interface.
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __BR_XBOOT_CMD_H__
#define __BR_XBOOT_CMD_H__   

#include "br_sw_types.h"
     
#ifdef __cplusplus
     extern "C" {
#endif
     
//==============================================================================
// definition
//==============================================================================
//for the m_magic field
#define MD_CMD_MAGIC            0x444D434D  //"MCMD" : Modem CoMmanD
#define ACK_MD_MAGIC            0x4D4B4341  //"ACKM" : ACK Modem command
#define XBOOT_STR_LEN           (20)

//The index of command id must not be modified. It is pre-defined protocol between Host-Slave
//Use XBOOT_CMD_ID_END to make sure XBOOT_CMD_ID is 32 bits
//Keep the ack id be the command id+1
typedef enum {
     BIN_LOAD_START     = 0
    ,ACK_BIN_LOAD_START = 1
    ,GET_BIN            = 2
    ,ACK_GET_BIN        = 3
    ,BIN_LOAD_END       = 4
    ,ACK_BIN_LOAD_END   = 5
    ,MD_BOOT_END        = 6
    ,ACK_MD_BOOT_END    = 7
    ,MD_MSG_OUTPUT      = 8
    ,ACK_MD_MSG_OUTPUT  = 9
    ,MD_MSG_FLUSH       = 10
    ,ACK_MD_MSG_FLUSH   = 11
    ,MD_BUF_SIZE_CHANGE = 12
    ,ACK_BUF_SIZE_CHANGE = 13
    ,XBOOT_CMD_ID_END   = 0x0FFFFFFF
} XBOOT_CMD_ID;

//Status code. Error occurs when code>=0x1000
//Use XBOOT_STAUS_END to make sure XBOOT_STAUS is 32 bits
typedef enum {
     XBOOT_OK           = 0
    ,XBOOT_STAGE_BROM   = 1
    ,XBOOT_STAGE_BL     = 2
    ,XBOOT_STAGE_BL_EXT = 3
    ,XBOOT_STAGE_MAUI   = 4
    ,XBOOT_ERROR        = 0x1000
    ,XBOOT_STAUS_END    = 0x0FFFFFFF
} XBOOT_STAUS;

//For BIN_LOAD_START, ACK_BIN_LOAD_START, ACK_GET_BIN, BIN_LOAD_END, ACK_BIN_LOAD_END,
//MD_BOOT_END, ACK_MD_BOOT_END, ACK_MD_DBG_PRINT
typedef struct Xboot_CMD_status {
    U32                m_magic;
    XBOOT_CMD_ID       m_msg_id;
    XBOOT_STAUS        m_status;
    U32                m_reserve[5];
} Xboot_CMD_status;

//For GET_BIN
typedef struct Xboot_CMD_GetBin {
    U32                m_magic;
    XBOOT_CMD_ID       m_msg_id;
    U32                m_offset;
    U32                m_len;
    U32                m_reserve[4];
} Xboot_CMD_GetBin;

//For MD_DBG_PRINT
typedef struct Xboot_CMD_DBGprint {
    U32                m_magic;
    XBOOT_CMD_ID       m_msg_id;
    U32                m_str_len; //The actual string length
    U8                 m_str[XBOOT_STR_LEN]; //AP side should not pre-define the value of XBOOT_STR_LEN
} Xboot_CMD_DBGprint;

//For MD_BUF_SIZE_CHANGE
typedef struct Xboot_CMD_BufSize {
    U32                m_magic;
    XBOOT_CMD_ID       m_msg_id;
    U32                m_buf_size; //The buf size
    U32                m_reserve[5];
} Xboot_CMD_BufSize;


//For unio type of xboot command
typedef union Xboot_CMD_U {
    Xboot_CMD_status   m_cmd_Status;
    Xboot_CMD_GetBin   m_cmd_GetBin;
    Xboot_CMD_DBGprint m_cmd_DBGprint;
    Xboot_CMD_BufSize  m_cmd_BufSize;
} Xboot_CMD_U;

//==============================================================================
// function prototype
//==============================================================================
extern void Xboot_SetTimeout(kal_uint32 timeout);
extern uint32 XbootCmd_Status(XBOOT_CMD_ID msg_id, XBOOT_STAUS xboot_status);
extern uint32 XbootCmd_GetBin(uint32 offset, uint32 length, uint32 dest);
extern uint32 XbootCmd_DbgPrint(const char *str, uint32 len);
extern uint32 XbootCmd_BufSizeChange(uint32 bufSize);
extern void Xboot_BootTrace(kal_uint32 data);
     
#ifdef __cplusplus
     }
#endif
     
#endif

