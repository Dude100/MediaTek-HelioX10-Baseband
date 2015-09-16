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
 *   br_GFH_file_info.c
 *
 * Project:
 * --------
 *   GFH
 *
 * Description:
 * ------------
 *   FILE_INFO(the 1st GFH) GFH structure implementation 
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#include "br_sw_types.h"
#include "br_GFH.h"
#include "br_GFH_file_info.h"
#include "br_GFH_error.h"
#include <string.h>

//==============================================================================
// GFH: FILE_INFO exported APIs
//==============================================================================

U32  GFH_FILE_INFO_BasicCheck(const GFH_FILE_INFO_v1 *  p_gfh_file_info)
{
    // check if FILE_INFO exist 
    if( (GFH_HDR_MAGIC != GFH_GET_MAGIC(p_gfh_file_info->m_gfh_hdr.m_magic_ver))
     || (GFH_FILE_INFO != p_gfh_file_info->m_gfh_hdr.m_type)
     || strcmp(p_gfh_file_info->m_identifier, GFH_FILE_INFO_ID)
    ) {
        return E_GFH_FILE_INFO_NOT_FOUND;
    }

    // check if content offset is valid 
    if( (0 == p_gfh_file_info->m_content_offset)
     || (GFH_MAX_CONTENT_OFFSET < p_gfh_file_info->m_content_offset)
    ) {
        return E_GFH_FILE_INFO_INVALID_CONTENT_OFFSET;
    }

    // check file length vs content offset 
    if( (0 == p_gfh_file_info->m_file_len )
     || (GFH_MAX_FILE_LEN < p_gfh_file_info->m_file_len)
    ) {
        return E_GFH_FILE_INFO_INVALID_FILE_LEN;
    }
    else if( p_gfh_file_info->m_content_offset > p_gfh_file_info->m_file_len )
    {
        return E_GFH_FILE_INFO_INVALID_CONTENT_OFFSET;
    }

    return B_OK;
}

U32  GFH_FILE_INFO_IsValid(const GFH_FILE_INFO_v1 *  p_gfh_file_info)
{
    GFH_SIG_TYPE        sig_type;
    U32                 sig_len;
    U32                 status=B_OK;

    //-------------------------------------------------------------------------------------
    // WARNING!!! m_file_len, m_content_offset and sig_len must be validated here!
    // Once FILE_INFO is found, these 3 fields will be assumed correct in other functions!
    //-------------------------------------------------------------------------------------

    // perform basic check 
    status = GFH_FILE_INFO_BasicCheck(p_gfh_file_info);
    if( E_ERROR <= status )
    {
        return status;
    }

#ifndef __GFH_SKIP_MAX_SIZE_CHECK__ 
    // check max file size 
    if( (GFH_FILE_MAX_SIZE_IGNORED != p_gfh_file_info->m_max_size)
     && (p_gfh_file_info->m_max_size < p_gfh_file_info->m_file_len)
    ) {
        return E_GFH_FILE_INFO_FILE_LEN_EXCEED_MAX_SIZE;
    }
#endif

    // check signature length 
    sig_type = p_gfh_file_info->m_sig_type;
    sig_len  = p_gfh_file_info->m_sig_len;
    if( (SIG_NONE == sig_type) && (0 != sig_len) )
    {
        return E_GFH_FILE_INFO_INVALID_SIG_LEN;
    }
    else if( SIG_NONE != sig_type )
    {
        // check sig len 
        if( (0 == sig_len) ||
            (p_gfh_file_info->m_file_len <= sig_len) ||
            (p_gfh_file_info->m_content_offset > (p_gfh_file_info->m_file_len-sig_len))
        ) {
            return E_GFH_FILE_INFO_INVALID_SIG_LEN;
        }
    }

    // check jump offset 
    if( 0 != p_gfh_file_info->m_jump_offset )
    {
        // jump offset is activated, validate it 
        if( (p_gfh_file_info->m_content_offset > p_gfh_file_info->m_jump_offset)
         || ((p_gfh_file_info->m_file_len-sig_len) <= p_gfh_file_info->m_jump_offset)
        ) {
            return E_GFH_FILE_INFO_INVALID_JUMP_OFFSET;
        }
    }

    return B_OK;
}

#if defined(__GFH_UTIL__)
//==============================================================================
// Exported utility APIs
//==============================================================================
const char * __WIN32_STDCALL GFH_GetFileTypeName(GFH_FILE_TYPE file_type)
{
    switch(file_type) {

        BR_ENUM_TO_CASE_STRING(GFH_FILE_NONE)
        BR_ENUM_TO_CASE_STRING(ARM_BL)
        BR_ENUM_TO_CASE_STRING(ARM_EXT_BL)
        BR_ENUM_TO_CASE_STRING(DUALMAC_DSP_BL)
        BR_ENUM_TO_CASE_STRING(SCTRL_CERT)
        BR_ENUM_TO_CASE_STRING(TOOL_AUTH)
        BR_ENUM_TO_CASE_STRING(FILE_MTK_RESERVED1)
        BR_ENUM_TO_CASE_STRING(EPP)
        BR_ENUM_TO_CASE_STRING(FILE_MTK_RESERVED2)
        BR_ENUM_TO_CASE_STRING(FILE_MTK_RESERVED3)
        BR_ENUM_TO_CASE_STRING(ROOT_CERT)
    
        BR_ENUM_TO_CASE_STRING(PRIMARY_MAUI)
        BR_ENUM_TO_CASE_STRING(SECONDARY_MAUI)
        BR_ENUM_TO_CASE_STRING(ON_DEMAND_PAGING)
        BR_ENUM_TO_CASE_STRING(THIRD_ROM)
        BR_ENUM_TO_CASE_STRING(DSP_ROM)
        BR_ENUM_TO_CASE_STRING(CACHED_DSP_ROM)
    
        BR_ENUM_TO_CASE_STRING(CUSTOM_PACK)
        BR_ENUM_TO_CASE_STRING(LANGUAGE_PACK)
        BR_ENUM_TO_CASE_STRING(JUMP_TABLE)
    
        BR_ENUM_TO_CASE_STRING(FOTA_UE)
        
        BR_ENUM_TO_CASE_STRING(SECURE_RO_S)
        BR_ENUM_TO_CASE_STRING(SECURE_RO_ME)
    
        BR_ENUM_TO_CASE_STRING(CARD_DOWNLOAD_PACKAGE)
        BR_ENUM_TO_CASE_STRING(CONFIDENTIAL_BINARY)
        
        BR_ENUM_TO_CASE_STRING(FILE_SYSTEM)
    
        BR_ENUM_TO_CASE_STRING(BOOT_CERT_CTRL)

        default:
            return "UNKNOWN";
    }
}

const char * __WIN32_STDCALL GFH_GetFlashDevName(GFH_FLASH_DEV flash_type)
{
    switch(flash_type) {

        BR_ENUM_TO_CASE_STRING(FLASH_DEV_NONE)
        BR_ENUM_TO_CASE_STRING(F_NOR)
        BR_ENUM_TO_CASE_STRING(F_NAND_SEQUENTIAL)
        BR_ENUM_TO_CASE_STRING(F_NAND_TTBL)
        BR_ENUM_TO_CASE_STRING(F_NAND_FDM50)
        BR_ENUM_TO_CASE_STRING(F_EMMC_BOOT_REGION)
        BR_ENUM_TO_CASE_STRING(F_EMMC_DATA_REGION)
        BR_ENUM_TO_CASE_STRING(F_SF)
    
        default:
            return "UNKNOWN";
    }
}

const char * __WIN32_STDCALL GFH_GetSigTypeName(GFH_SIG_TYPE sig_type)
{
    switch(sig_type) {

        BR_ENUM_TO_CASE_STRING(SIG_NONE)
        BR_ENUM_TO_CASE_STRING(SIG_PHASH)
        BR_ENUM_TO_CASE_STRING(SIG_SINGLE)
        BR_ENUM_TO_CASE_STRING(SIG_SINGLE_AND_PHASH)
        BR_ENUM_TO_CASE_STRING(SIG_MULTI)
       
        default:
            return "UNKNOWN";
    }
}

#endif
