/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *   br_GFH_file_info.h
 *
 * Project:
 * --------
 *   GFH
 *
 * Description:
 * ------------
 *   FILE_INFO(the 1st GFH) GFH structure declaration
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __BR_GFH_FILE_INFO_H__
#define __BR_GFH_FILE_INFO_H__

#include "br_sw_types.h"
#include "br_GFH.h"

#ifdef __cplusplus
extern "C" {
#endif

//==============================================================================
// FILE_INFO definition (This is the 1st GFH header)
//==============================================================================

typedef enum {
     GFH_FILE_NONE          = 0x0000        //Recognized by BootROM
    ,ARM_BL                 = 0x0001
    ,ARM_EXT_BL             = 0x0002
    ,FCORE_BL               = 0x0003
    ,SCTRL_CERT             = 0x0004
    ,TOOL_AUTH              = 0x0005
    ,FILE_MTK_RESERVED1     = 0x0006
    ,EPP                    = 0x0007
    ,FILE_MTK_RESERVED2     = 0x0008
    ,FILE_MTK_RESERVED3     = 0x0009
    ,ROOT_CERT              = 0x000a

    ,V_MAUI_BINARY          = 0x0100         //MAUI binary group
    ,PRIMARY_MAUI           = V_MAUI_BINARY
    ,SECONDARY_MAUI         = 0x0101
    ,ON_DEMAND_PAGING       = 0x0102
    ,THIRD_ROM              = 0x0103
    ,DSP_ROM                = 0x0104
    ,V_MAUI_BINARY_END

    ,V_RESOURCE_BINARY      = 0x0180        //Resource binary group
    ,CUSTOM_PACK            = V_RESOURCE_BINARY
    ,LANGUAGE_PACK          = 0x0181
    ,JUMP_TABLE             = 0x0182
    ,V_RESOURCE_BINARY_END 

    ,V_MISC_BINARY          = 0x0200        //Binary not belonging MAUI
    ,FOTA_UE                = V_MISC_BINARY
    ,V_MISC_BINARY_END

    ,V_SECURE_RO            = 0x0300        //Secure structure group
    ,SECURE_RO_S            = V_SECURE_RO
    ,SECURE_RO_ME           = 0x0301
    ,V_SECURE_RO_END

    ,V_EXTERNAL_FILE        = 0x0400
    ,CARD_DOWNLOAD_PACKAGE  = V_EXTERNAL_FILE
    ,CONFIDENTIAL_BINARY    = 0x0401
    ,V_EXTERNAL_FILE_END
    
    ,V_FILE_SYSTEM_BINARY   = 0x0480        //File System
    ,FILE_SYSTEM            = V_FILE_SYSTEM_BINARY
    ,V_FILE_SYSTEM_BINARY_END

    ,BOOT_CERT              = 0x0500

	,V_CUSTOM_BIN			= 0x0600        //Custom group
	,CUTSOM_BIN_1			= V_CUSTOM_BIN
	,CUTSOM_BIN_2			= 0x0601
	,CUTSOM_BIN_3			= 0x0602
	,CUTSOM_BIN_4			= 0x0603
	,CUTSOM_BIN_5			= 0x0604
	,CUTSOM_BIN_6			= 0x0605
	,CUTSOM_BIN_7			= 0x0606
	,CUTSOM_BIN_8			= 0x0607
    ,V_CUSTOM_BIN_END

    ,GFH_FILE_END           = (U16)0xffff
} GFH_FILE_TYPE;

typedef enum {
     FLASH_DEV_NONE         = 0
    ,F_NOR                  = 1
    ,F_NAND_SEQUENTIAL      = 2
    ,F_NAND_TTBL            = 3
    ,F_NAND_FDM50           = 4
    ,F_EMMC_BOOT_REGION     = 5
    ,F_EMMC_DATA_REGION     = 6
    ,F_SF                   = 7
    ,FLASH_DEV_END          = (U8)255
} GFH_FLASH_DEV;

typedef enum {
     SIG_NONE               = 0
    ,SIG_PHASH              = 1
    ,SIG_SINGLE             = 2
    ,SIG_SINGLE_AND_PHASH   = 3
    ,SIG_MULTI              = 4
    ,SIG_TYPE_NUM
    ,SIG_TYPE_END           = (U8)255
} GFH_SIG_TYPE;

#define GFH_FILE_INFO_ID                "FILE_INFO"
#define GFH_MAX_CONTENT_OFFSET          0x100000    // 1MB
#define GFH_MAX_FILE_LEN                0x80000000  // 2GB (FAT16 max size)

#define GFH_LOAD_ADDR_NA                0xFFFFFFFF
#define GFH_FILE_SIZE_NA                0xFFFFFFFF

#define GFH_FILE_MAX_SIZE_IGNORED       0xFFFFFFFF
#define GFH_FILE_MAX_SIZE_BY_POST_BUILD 0x00000000

#define FILE_INFO_ATTR_POST_BUILD_DONE  0x00000001
#define FILE_INFO_ATTR_XIP              0x00000002

typedef struct GFH_FILE_INFO_v1 {
    GFH_Header      m_gfh_hdr;
    char            m_identifier[12];       // including '\0'
    U32             m_file_ver;
#if defined(WIN32)
    U16             m_file_type;
    U8              m_flash_dev;
    U8              m_sig_type;
#else
    GFH_FILE_TYPE   m_file_type;
    GFH_FLASH_DEV   m_flash_dev;
    GFH_SIG_TYPE    m_sig_type;
#endif
    U32             m_load_addr;
    U32             m_file_len;
    U32             m_max_size;
    U32             m_content_offset;
    U32             m_sig_len;
    U32             m_jump_offset;
    U32             m_attr;
} GFH_FILE_INFO_v1;

//==============================================================================
// Exported APIs
//==============================================================================
extern U32  GFH_FILE_INFO_BasicCheck(const GFH_FILE_INFO_v1 *  p_gfh_file_info);
extern U32  GFH_FILE_INFO_IsValid(const GFH_FILE_INFO_v1 *  p_gfh_file_info);

#if defined(__GFH_UTIL__)
//==============================================================================
// Exported utility APIs
//==============================================================================
extern const char * __WIN32_STDCALL GFH_GetFileTypeName(GFH_FILE_TYPE  file_type);
#endif

#ifdef __cplusplus
}
#endif

#endif
