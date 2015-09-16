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

/*******************************************************************************
 * Filename:
 * ---------
 * nvram_errcode.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Error code header file for NVRAM
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef NVRAM_ERRCODE_H
#define NVRAM_ERRCODE_H

/*---------------------------------------------------------------------------
 * Error Codes
 *---------------------------------------------------------------------------*/
typedef enum
{
    NVRAM_LOC_DEFAULT,                               // No error
    NVRAM_LOC_OPEN_NV_FOLDER_FAIL,                   // (1) Open Nvram root directory fail
    NVRAM_LOC_CALIBRATION_SIZE_CHANGE,               // (2) (Smart phone only) MP upgrade modem issue; calibration size is not allow to change after smart phone chip MP, it's because data will lost while upgrade modem; before chip MP, just format FS to make new setting to take effect
    NVRAM_LOC_RESTORE_SUCCESS_READ_FAIL,             // (3) (Smart phone only) Read fail after bin region restore success (bin region data may corrupted)
    NVRAM_LOC_BIN_REGION_RESTORE_FAIL,               // (4) (Smart phone only) AP bin region restore fail; transfer to AP NVRAM
    NVRAM_LOC_OTP_INIT_FAIL,                         // (5) Query OTP size fail or OTP size is not enough
    NVRAM_LOC_SPACE_NOT_ENOUGH,                      // Space not enough for upgrade, config storage for more space
    NVRAM_LOC_OPEN_BACKUP_DISK_FAIL,                  //(Feature phone only) open backup partition folder fail
    NVRAM_LOC_READ_IMPORTANT_DATA_FAIL,              //(Feature phone only)
    NVRAM_LOC_READ_AND_RESET_FAIL,                   //Read fail and then reset to default value also fail
    NVRAM_LOC_READ_SYS_CACHE_FAIL,                   //Read SYS_CACHE_OCTET_LID fail
    NVRAM_LOC_READ_PACKED_FILE_FAIL,
    NVRAM_LOC_WRITE_IMPORTANT_DATA_FAIL,
    NVRAM_LOC_WRITE_AND_RESET_FAIL,                  //Write fail and then reset to default value also fail
    NVRAM_LOC_WRITE_SYS_LID_FAIL,                    // Write NVRAM_EF_SYS_LID fail due to nvram_ptr->state != ready
    NVRAM_LOC_GET_DEFAULT_WITH_WRONG_PARAM,          // Nvram internal error; buffer size is not enough
    NVRAM_LOC_GET_DEFAULT_FROM_SDS_FAIL,             //(Feature phone only) Get important data default value from SDS fail
    NVRAM_LOC_GEN_TARGET_ASYNC_CUSTPACK,
    NVRAM_LOC_SECRO_CHKSUM_FAIL                  //Secupack checksum not match: default value checksum from secupack != secupack item checksum store in fs
} nvram_error_location_enum;

#define DISPLAY_ERROR(NVRAM_ERROR) ((nvram_drv_fat_get_last_err())?(nvram_drv_fat_get_last_err()):NVRAM_ERROR)


#define LID_OWNER_ERR(LID)         ((1<<16) | LID)
#define NVRAM_INTERNAL_ERR(LID)    ((2<<16) | LID)


#endif /* NVRAM_ERRCODE_H */

