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
 *   br_GFH.h
 *
 * Project:
 * --------
 *   GFH
 *
 * Description:
 * ------------
 *   GFH(General File Header) header definition 
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __BR_GFH_H__
#define __BR_GFH_H__

#include "br_sw_types.h"

//==============================================================================
// GFH type definition 
//==============================================================================

typedef enum {

     GFH_FILE_INFO          = 0x0000
    ,GFH_BL_INFO            = 0x0001
    ,GFH_ANTI_CLONE         = 0x0002
    ,GFH_BL_SEC_KEY         = 0x0003
    ,GFH_SCTRL_CERT         = 0x0004
    ,GFH_TOOL_AUTH          = 0x0005
    ,GFH_MTK_RESERVED1      = 0x0006
    ,GFH_BROM_CFG           = 0x0007
    ,GFH_BROM_SEC_CFG       = 0x0008
    ,GFH_MTK_RESERVED2      = 0x0009
    ,GFH_MTK_RESERVED3      = 0x000a
    ,GFH_ROOT_CERT          = 0x000b
    ,GFH_EXP_CHK            = 0x000c
    ,GFH_EPP_PARAM          = 0x000d
    ,GFH_CHIP_VER           = 0x000e
    ,GFH_MTK_RESERVED4      = 0x000f
    
    ,GFH_EPP_INFO           = 0x0100

    ,GFH_MAUI_INFO          = 0x0200
    ,GFH_MAUI_SEC           = 0x0201    
    ,GFH_MAUI_CODE_KEY      = 0x0202    //MAUI_SEC_KEY for code part
    ,GFH_MAUI_SECURE_RO_KEY = 0x0203    //MAUI_SEC_KEY for secure ro part
    ,GFH_MAUI_RESOURCE_KEY  = 0x0204    //MAUI_SEC_KEY for resource part

    ,GFH_SECURE_RO_INFO     = 0x0205

    ,GFH_DL_PACKAGE_INFO    = 0x0206
    ,GFH_FLASH_INFO         = 0x0207
    ,GFH_MACR_INFO          = 0x0208
    ,GFH_ARM_BL_INFO        = 0x0209
    ,GFH_EMMC_BOOTING_INFO  = 0x020A
    ,GFH_FOTA_INFO          = 0x020B
    ,GFH_CBR_RECORD_INFO    = 0x020C
    ,GFH_CONFIDENTIAL_BIN_INFO = 0x020D
    ,GFH_CBR_INFO           = 0x020E    

    ,GFH_BOOT_CERT          = 0x0300

    ,GFH_TYPE_NUM
    ,GFH_TYPE_END           = (U16)0xffff
} GFH_TYPE;

//==============================================================================
// GFH header definition
//==============================================================================

#define GFH_HDR_MAGIC               0x004D4D4D  // "MMM"
#define GFH_HDR_MAGIC_END_MARK      0x45454545  // "EEEE"
#define GFH_GET_MAGIC(magic_ver)    ((magic_ver)&0x00FFFFFF)
#define GFH_GET_VER(magic_ver)      ((magic_ver)>>24)

// WARNING!! in order to guarantee all GFH structure is 4B aligned and size is multiple of 4B 
// the following rules must be guaranteed!
// 1. GFH_Header structure size must be multiple of 4B 
// 2. GFH_Header structure alignment must be 4B aligned 
// so that use m_magic_ver(U32) to guarantee that 
typedef struct GFH_Header {
    U32                 m_magic_ver;
    U16                 m_size;
    #if defined(WIN32)
    U16                 m_type;
    #else
    GFH_TYPE            m_type;
    #endif
} GFH_Header;

typedef struct GFH_End {
    U32                 m_magic_end;
} GFH_End;

#define GFH_HEADER(type, ver) { (GFH_HDR_MAGIC|((ver)<<24)) , sizeof(type##_v##ver), type}

//==============================================================================
// Misc definition
//==============================================================================

#define SECURE_CUST_NAME_LEN    32  // 32B
#define MAX_DA_BLOCKS           10

//==============================================================================
// FILE_INFO GFH definition
//==============================================================================
#include "br_GFH_file_info.h"

#endif
