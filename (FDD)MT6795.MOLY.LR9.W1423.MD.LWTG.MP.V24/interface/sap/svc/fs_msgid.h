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
 *   fs_sap.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   File System Task related message identity definition
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "module_msg_range.h"

#ifndef FS_MSGID_H
#define FS_MSGID_H

MODULE_MSG_BEGIN( MSG_ID_FS_CODE_BEGIN )
    MSG_ID_FS_STARTUP_REQ = MSG_ID_FS_CODE_BEGIN,

    //--- Service Request ---
    MSG_ID_FS_SERVICE_REQ_BEGIN = MSG_ID_FS_STARTUP_REQ,

    MSG_ID_FS_ABORT_REQ,
    MSG_ID_FS_OPEN_REQ,
    MSG_ID_FS_GET_FOLDER_SIZE_REQ,
    MSG_ID_FS_WRITE_REQ,
    MSG_ID_FS_DELETE_REQ,
    MSG_ID_FS_READ_REQ,
    MSG_ID_FS_SEEK_REQ,
    MSG_ID_FS_FIND_FIRST_REQ,
    MSG_ID_FS_FIND_FIRST_N_REQ,

    MSG_ID_FS_SERVICE_REQ_END   = MSG_ID_FS_FIND_FIRST_N_REQ,

    //--- Service Response ---
    MSG_ID_FS_SERVICE_RSP_BEGIN = MSG_ID_FS_SERVICE_REQ_END + 1,

    MSG_ID_FS_OPEN_RSP,
    MSG_ID_FS_GET_FOLDER_SIZE_RSP,
    MSG_ID_FS_WRITE_RSP,
    MSG_ID_FS_DELETE_RSP,
    MSG_ID_FS_READ_RSP,
    MSG_ID_FS_SEEK_RSP,
    MSG_ID_FS_FIND_FIRST_RSP,
    MSG_ID_FS_FIND_FIRST_N_RSP,

    MSG_ID_FS_SERVICE_RSP_END   = MSG_ID_FS_FIND_FIRST_N_RSP,

    MSG_ID_FS_CODE_END,
MODULE_MSG_END( MSG_ID_FS_CODE_TAIL )
#endif  //FS_MSGID_H	
