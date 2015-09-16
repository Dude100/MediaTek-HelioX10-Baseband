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
 *   br_sd_xboot_Cmd_export_v1.h
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *   BOOTROM xboot command function version 1 (EXPORTED APIs)
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __BR_SD_XBOOT_CMD_EXPORT_V1_H__
#define __BR_SD_XBOOT_CMD_EXPORT_V1_H__

#include "br_sw_types.h"
#include "br_xboot_cmd.h"

#ifdef __cplusplus
extern "C" {
#endif

//==============================================================================
// Shared SDIO driver function prototype
//==============================================================================

typedef U32 (*SD_XBOOTCMD_STATUS_V1)(XBOOT_CMD_ID msg_id, XBOOT_STAUS status);
typedef U32 (*SD_XBOOTCMD_GETBIN_V1)(U32 offset, U32 len, U32 dest_addr);
typedef U32 (*SD_XBOOTCMD_DBGPRINT_V1)(const char *str, U32 len);

//==============================================================================
// Shared SDIO driver function table
//==============================================================================
typedef struct SD_R_XbootCmd_FuncTable_v1 {
    SD_XBOOTCMD_STATUS_V1      m_xbootcmd_status;
    SD_XBOOTCMD_GETBIN_V1      m_xbootcmd_getbin;
    SD_XBOOTCMD_DBGPRINT_V1    m_xbootcmd_dbgprint;
} SD_R_XbootCmd_FuncTable_v1;

#ifdef __cplusplus
}
#endif

#endif


