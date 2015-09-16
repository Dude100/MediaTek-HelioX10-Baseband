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

/*******************************************************************************
 * Filename:
 * ---------
 * nvram_enums.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for NVRAM.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef NVRAM_ENUMS_H
#define NVRAM_ENUMS_H


typedef enum
{
    NVRAM_POWERON_NORMAL,
    NVRAM_POWERON_CHARGER,
    NVRAM_POWERON_ALARM,
    NVRAM_POWERON_INVALID
} nvram_poweron_mode_enum;

typedef enum
{
    NVRAM_LOCK_DISABLE,
    NVRAM_LOCK_ENABLE,
    NVRAM_LOCK_TEMP_DISABLE,
    NVRAM_LOCK_OTP,
    NVRAM_LOCK_INVALID
} nvram_lock_state_enum;

typedef enum
{
    NVRAM_DEFAULT_VALUE_SUCCESS,
    NVRAM_DEFAULT_VALUE_FAIL,
    NVRAM_DEFAULT_VALUE_FF,
    NVRAM_DEFAULT_VALUE_ZERO,
    NVRAM_DEFAULT_VALUE_POINT,
    NVRAM_DEFAULT_VALUE_APPLICATION,

    NVRAM_DEFAULT_VALUE_MAX
} nvram_default_value_enum;

typedef enum
{
    NVRAM_RESET_ALL,
    NVRAM_RESET_USER,
    NVRAM_RESET_SYSTEM,
    NVRAM_RESET_CERTAIN,
    NVRAM_RESET_FACTORY,
    NVRAM_RESET_CUSTPACK,
    NVRAM_RESET_SECUPACK,
    NVRAM_RESET_BRANCH,
    NVRAM_RESET_PACKAGE,
    NVRAM_RESET_FAT,
    NVRAM_RESET_SDS,
    NVRAM_RESET_INVALID
} nvram_reset_category_enum;


typedef enum
{
    /* NVRAM generic error code */
    NVRAM_ERRNO_SUCCESS,
    NVRAM_IO_ERRNO_OK = NVRAM_ERRNO_SUCCESS,

    NVRAM_ERRNO_FAIL,
    NVRAM_ERRNO_INVALID,
    NVRAM_ERRNO_NOT_READY,

    /* NVRAM driver error code */
    NVRAM_IO_ERRNO_INVALID_LID,
    NVRAM_IO_ERRNO_INVALID_SIZE,
    NVRAM_IO_ERRNO_INVALID_RECORD,
    NVRAM_IO_ERRNO_EMPTY_RECORD,
    NVRAM_IO_ERRNO_STORAGE,
    NVRAM_IO_ERRNO_INIT,
    NVRAM_IO_ERRNO_CHK,
    NVRAM_IO_ERRNO_LOCKED,
    NVRAM_IO_ERRNO_WRONG_RINGLID,
    NVRAM_IO_ERRNO_ACCESS_DENIED,
    NVRAM_IO_ERRNO_DRV_BROKEN,
    NVRAM_IO_ERRNO_CONTENT_BROKEN,
    NVRAM_IO_ERRNO_SDS_FAIL,
    NVRAM_IO_ERRNO_SDS_MODE,

    /* OTP */
    NVRAM_ERRNO_OTP_UNKNOW,    /* FS_FLASH_OTP_UNKNOWERR -123 */
    NVRAM_ERRNO_OTP_OVERSCOPE, /* FS_FLASH_OTP_OVERSCOPE -124 */
    NVRAM_ERRNO_OTP_WRITEFAIL, /* FS_FLASH_OTP_WRITEFAIL -125 */
    NVRAM_ERRNO_OTP_LOCKED,    /* FS_FLASH_OTP_LOCK_ALREADY -125 */
    NVRAM_ERRNO_OTP_INVALID_INPUT,
    NVRAM_ERRNO_OTP_INVALID_RANGE,
    NVRAM_ERRNO_OTP_WRITETWICE,

    NVRAM_ERRNO_IMAGE_BROKEN,
    NVRAM_ERRNO_IMAGE_EMPTY,
    NVRAM_ERRNO_IMAGE_DATA_NOT_SYNC,
    NVRAM_ERRNO_IMAGE_DATA_NOT_EXIST,

    NVRAM_ERRNO_FOLDER_EXIST,

    NVRAM_ERRNO_SDS_READY,
    NVRAM_ERRNO_SDS_EMPTY,

    NVRAM_ERRNO_MAX
} nvram_errno_enum;




typedef kal_uint16 nvram_lid_enum;
typedef kal_uint16 nvram_app_id_enum;







typedef enum
{
    NVRAM_IMAGE_TYPE_EMPTY = 0x0000,
    NVRAM_IMAGE_TYPE_CALIBRAT = 0x0001,
    NVRAM_IMAGE_TYPE_IMEI = 0x0002
} nvram_image_type_enum;

#define NVRAM_IMAGE_TYPE_DEFAULT NVRAM_IMAGE_TYPE_CALIBRAT

typedef enum
{
    NVRAM_BIN_REGION_BACKUP,
    NVRAM_BIN_REGION_RESTORE,
} nvram_bin_region_access_enum;

typedef enum
{
    NVRAM_SDS_ACCESS_BACKUP,
    NVRAM_SDS_ACCESS_RESTORE,
} nvram_sds_access_enum;

typedef enum
{
    NVRAM_RESTORE_FALSE,
    NVRAM_RESTORE_TRUE
}nvram_restore_flag_enum;
#endif /* NVRAM_ENUMS_H */
