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
 * nvram_internal.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef NVRAM_INTERNAL_H
#define NVRAM_INTERNAL_H

#include "nvram_config.h"
#include "nvram_enums.h"

/********************************************************************************
*                                                                               *
*   NVRAM internal LID                                                          *
*                                                                               *
********************************************************************************/
#define NVRAM_EF_SYS_SIZE                 34
#define NVRAM_EF_SYS_TOTAL                3

#define NVRAM_EF_BRANCH_VERNO_SIZE  NVRAM_EF_SYS_SIZE
#define NVRAM_EF_BRANCH_VERNO_TOTAL NVRAM_EF_SYS_TOTAL

#define NVRAM_EF_FLAVOR_VERNO_SIZE  NVRAM_EF_SYS_SIZE
#define NVRAM_EF_FLAVOR_VERNO_TOTAL NVRAM_EF_SYS_TOTAL

#define NVRAM_EF_CUSTPACK_VERNO_SIZE NVRAM_EF_SYS_SIZE
#define NVRAM_EF_CUSTPACK_VERNO_TOTAL NVRAM_EF_SYS_TOTAL

#define NVRAM_EF_SECUPACK_VERNO_SIZE  sizeof(kal_uint16)
#define NVRAM_EF_SECUPACK_VERNO_TOTAL NVRAM_EF_SYS_TOTAL

#define NVRAM_EF_NVRAM_CONFIG_SIZE  128
#define NVRAM_EF_NVRAM_CONFIG_TOTAL 1

/********************************************************************************
*                                                                               *
*   NVRAM state                                                                 *
*                                                                               *
********************************************************************************/
/* State definitions */
typedef enum
{
    NVRAM_STATE_NULL,
    NVRAM_STATE_NOT_READY,
    NVRAM_STATE_READY
} nvram_state_enum;


/********************************************************************************
*                                                                               *
*   NVRAM Boot-up type                                                          *
*                                                                               *
********************************************************************************/
typedef enum
{
    NVRAM_FIRST_BOOTUP,
    NVRAM_NORMAL_BOOTUP,
    NVRAM_NORMAL_SUCCESS_BOOTUP
}nvram_bootup_enum;
/********************************************************************************
*                                                                               *
*   NVRAM SW status                                                             *
*                                                                               *
********************************************************************************/
#define NVRAM_SW_VERSION_CHANGE     0x0001
#define NVRAM_SW_BRANCH_CHANGE      0x0002
#define NVRAM_SW_CUSTPACK_CHANGE    0x0004
#define NVRAM_SW_EMPTY_FAT          0x0008
#define NVRAM_SW_SOME_CORRUPT       0x0010
#define NVRAM_SW_PACKAGE_CHANGE     0x0020
#define NVRAM_SW_SECUPACK_CHANGE    0x0100
#define NVRAM_SW_EMPTY_SDS          0x0200

/********************************************************************************
*                                                                               *
*   NVRAM storage type                                                          *
*                                                                               *
********************************************************************************/
#define NVRAM_STORAGE_TYPE_FAT      0
#define NVRAM_STORAGE_TYPE_OTP      1
#define NVRAM_STORAGE_TYPE_SECRO    2


/********************************************************************************
*                                                                               *
*   Attribute                                                                   *
*                                                                               *
********************************************************************************/

#define NVRAM_IS_ATTR_MULTI_DEFAULT(x)	((x) & NVRAM_ATTR_MULTI_DEFAULT)
#define NVRAM_IS_ATTR_AVERAGE(x)        ((x) & NVRAM_ATTR_AVERAGE)
#define NVRAM_IS_ATTR_WRITEPROTECT(x)   ((x) & NVRAM_ATTR_WRITEPROTECT)
#define NVRAM_IS_ATTR_MULTIPLE(x)       ((x) & NVRAM_ATTR_MULTIPLE)
#define NVRAM_IS_ATTR_CONFIDENTIAL(x)   ((x) & NVRAM_ATTR_CONFIDENTIAL)
#define NVRAM_IS_ATTR_AUTORECOVER(x)    ((x) & NVRAM_ATTR_AUTO_RECOVER)
#define NVRAM_TURNOFF_ATTR_MULTIPLE(x)  ((x) &= ~(NVRAM_ATTR_MULTIPLE))
#define NVRAM_TURNOFF_ATTR_FACTOY_RESET(x)    ((x) &= ~(NVRAM_ATTR_FACTORY_RESET))

#ifdef __NVRAM_PSEUDO_MERGE__
#define NVRAM_IS_ATTR_PACKAGE(x)        ((x) & NVRAM_ATTR_PACKAGE)
#else
#define NVRAM_IS_ATTR_PACKAGE(x)        (0)
#endif

#ifdef __NVRAM_BACKUP_DISK_FAT__
#define NVRAM_IS_ATTR_BACKUP_FAT(x) ((x) & NVRAM_ATTR_BACKUP_FAT)
#else
#define NVRAM_IS_ATTR_BACKUP_FAT(x) (0)
#endif

#ifdef __NVRAM_BACKUP_DISK_RAW__
#define NVRAM_IS_ATTR_BACKUP_RAW(x) ((x) & NVRAM_ATTR_BACKUP_RAW)
#else
#define NVRAM_IS_ATTR_BACKUP_RAW(x) (0)
#endif

#ifdef __NVRAM_COMPRESS_SUPPORT__
#define NVRAM_IS_ATTR_ZIP_DEFAULT(x) ((x) & NVRAM_ATTR_ZIP_DEFAULT)
#define NVRAM_IS_ATTR_NOT_ZIP_DEFAULT(x) ((x) & NVRAM_ATTR_NOT_ZIP_DEFAULT)
#else
#define NVRAM_IS_ATTR_ZIP_DEFAULT(x) (0)
#define NVRAM_IS_ATTR_NOT_ZIP_DEFAULT(x) (1)
#endif

/********************************************************************************
*                                                                               *
*   Category                                                                    *
*                                                                               *
********************************************************************************/

#define NVRAM_IS_CATEGORY_INTERNAL(x)       ((x) & NVRAM_CATEGORY_INTERNAL)
#define NVRAM_IS_CATEGORY_CALIBRAT(x)       ((x) & NVRAM_CATEGORY_CALIBRAT)
#define NVRAM_IS_CATEGORY_IMPORTANT(x)      ((x) & NVRAM_CATEGORY_IMPORTANT)
#define NVRAM_IS_CATEGORY_SECUPACK(x)       ((x) & NVRAM_CATEGORY_SECUPACK)

#define NVRAM_IS_CATEGORY_CUSTPACK(x)       ((x) & NVRAM_CATEGORY_CUSTPACK)
#define NVRAM_IS_CATEGORY_SECUPACK(x)       ((x) & NVRAM_CATEGORY_SECUPACK)

#ifdef __NVRAM_OTP__
#define NVRAM_IS_CATEGORY_OTP(x)            ((x) & NVRAM_CATEGORY_OTP)
#else
#define NVRAM_IS_CATEGORY_OTP(x)            (0)
#endif

#if defined(__CCCIFS_SUPPORT__)
#define NVRAM_IS_CATEGORY_IMPORTANT_L4(x)   ((x) & NVRAM_CATEGORY_IMPORTANT_L4)
#else
#define NVRAM_IS_CATEGORY_IMPORTANT_L4(x)   (0)
#endif

#ifdef __NVRAM_CUSTOM_DISK__
#define NVRAM_IS_CATEGORY_CUSTOM_DISK(x)       (x & NVRAM_CATEGORY_CUSTOM_DISK)
#else
#define NVRAM_IS_CATEGORY_CUSTOM_DISK(x)       (0)
#endif

#ifdef __NVRAM_CUSTOM_SENSITIVE__
#define NVRAM_IS_CATEGORY_CUSTOM_SENSITIVE(x) (x & NVRAM_CATEGORY_CUSTOM_SENSITIVE)
#else
#define NVRAM_IS_CATEGORY_CUSTOM_SENSITIVE(x) (0)
#endif

#ifdef __NVRAM_SECURE_DATA_STORAGE__
#define NVRAM_IS_CATEGORY_BACKUP_SDS(x)            ((x) & NVRAM_CATEGORY_BACKUP_SDS)
#else
#define NVRAM_IS_CATEGORY_BACKUP_SDS(x)            (0)
#endif


/********************************************************************************
*                                                                               *
*   NVRAM folder enums                                                          *
*                                                                               *
********************************************************************************/
typedef enum
{
    NVRAM_FOLDER_BEGIN,
    NVRAM_NVD_DATA = NVRAM_FOLDER_BEGIN,
#ifdef __NVRAM_MULTI_FOLDERS__
    NVRAM_NVD_CORE,
    NVRAM_NVD_CALI,
    NVRAM_NVD_IMEI,
    #if defined(__CCCIFS_SUPPORT__)
    NVRAM_NVD_IMPNT,
    #if defined(__MTK_TARGET__) && defined(__NVRAM_IMPORTANT_PARTITIONS__)
    NVRAM_NVD_IMPNT2,
    NVRAM_NVD_IMPNT3,
    #endif
    #endif
    #ifdef __NVRAM_CUSTOM_SENSITIVE__
    NVRAM_NVD_CUST,
    #endif
#endif
    NVRAM_FOLDER_TOTAL
}nvram_folder_enum;

#ifdef __SYSDRV_BACKUP_DISK_FAT__
#define NVRAM_NVD_BAK (NVRAM_FOLDER_TOTAL + 1)
#endif


/********************************************************************************
*                                                                               *
*   Misc                                                                        *
*                                                                               *
********************************************************************************/
typedef kal_char NVRAM_FILE_NAME[9];

/* AES 16 byte alignment, must be power of 2*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#endif /* NVRAM_INTERNAL_H */
