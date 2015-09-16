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
 *   fs_internal_api.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the header of MTK file system internal common APIs.
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
#ifndef _FS_INTERNAL_API_H
#define _FS_INTERNAL_API_H

/*-----------------------------------
 * Included Header Files
 *-----------------------------------*/

#include "fs_gprot.h"
#include "fs_iprot.h"

/*-------------------------------------
 * Global Definitions
 *-------------------------------------*/

/*-------------------------------------
 * Exported Variables
 *-------------------------------------*/

/*-------------------------------------
 * Exported Functions
 *-------------------------------------*/

#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "kal_public_api.h"

extern msg_type             fs_job_api_to_msgid(fs_api_enum api);

extern FS_Device*           fs_conf_find_dev_by_devtype(FS_DEVICE_TYPE_ENUM dev_type, kal_uint32 serial);
extern FS_DEVICE_TYPE_ENUM  fs_conf_get_default_devtype(void);
extern kal_uint32           fs_conf_get_devflag_by_devtype(FS_DEVICE_TYPE_ENUM dev_type);
extern kal_uint32           fs_conf_get_devtype_by_devflag(kal_uint32 dev_flag);
extern FS_Drive*            fs_conf_get_drv_struct_by_drv_letter(WCHAR drv_letter);
extern FS_File*             fs_conf_get_file_by_fh(FS_HANDLE fh);
extern WCHAR                fs_conf_get_native_drive_letter(WCHAR drv_letter);
extern kal_bool             fs_conf_query_if_sys_drv(WCHAR drv_letter, WCHAR *native_drv_letter);
extern kal_uint32           fs_conf_get_first_drive_size(FS_Device *dev, kal_uint32 avail_sectors);
extern kal_uint32           fs_conf_get_tls_idx(void);

extern kal_bool             fs_fh_is_aborted(FS_File *f);

extern int                  fs_fmt_self_format(FS_Device *Dev, kal_uint32 DeviceType);

extern void                 fs_mem_init(void);
extern void *               fs_mem_alloc(fs_mem_type_enum type, kal_uint32 size, kal_uint32 options);
extern void                 fs_mem_free(fs_mem_type_enum type, void * addr, kal_uint32 size);

#endif // !_FS_INTERNAL_API_H
