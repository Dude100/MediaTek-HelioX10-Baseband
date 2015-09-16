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
 *   br_GFH_anti_clone.c
 *
 * Project:
 * --------
 *   GFH
 *
 * Description:
 * ------------
 *   ANTI_CLONE GFH structure implementation
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#include "br_GFH_anti_clone.h"
#include "br_bootrom_error.h"

//==============================================================================
// GFH: ANTI_CLONE exported APIs
//==============================================================================
U32  GFH_ANTI_CLONE_IsValid(const GFH_FILE_INFO_v1  *p_gfh_file_info,
                            const GFH_ANTI_CLONE_v1 *p_gfh_anti_clone)
{
    U32     ac_offset;
    U32     ac_len;
    U32     ac_valid_len;

    //-------------------------------------------------
    // check FILE_INFO
    //-------------------------------------------------
    if( NULL == p_gfh_file_info )
    {
        return E_GFH_FILE_INFO_NOT_FOUND;
    }

    //-------------------------------------------------
    // check ANTI_CLONE
    //-------------------------------------------------
    if( NULL == p_gfh_anti_clone )
    {
        return E_GFH_ANTI_CLONE_NOT_FOUND;
    }

    // get current BL AC_K_EN/AC_C_EN setting to check if Anti-clone is enabled 
    if( !(p_gfh_anti_clone->m_ac_b2k || p_gfh_anti_clone->m_ac_b2c) )
    {
        // Anti-clone is disabled 
        return B_OK;
    }

    //-------------------------------------------------
    // check AC offset and len 
    //-------------------------------------------------
    ac_offset       = p_gfh_anti_clone->m_ac_offset;
    ac_len              = p_gfh_anti_clone->m_ac_len;

    // check if file content length is valid 
    if( p_gfh_file_info->m_file_len <= p_gfh_file_info->m_content_offset + p_gfh_file_info->m_sig_len )
    {
        // file content length is invalid, there is no available anti-clone area 
        return E_AC_FILE_CONTENT_LEN_INVALID;
    }

    // calculate valid anti-clone area 
    ac_valid_len    = (p_gfh_file_info->m_file_len - p_gfh_file_info->m_content_offset - p_gfh_file_info->m_sig_len);

    // check if anti-clone area locates in valid region 
    if( (0 == ac_len)
     || (ac_valid_len <= ac_offset)
     || (ac_valid_len <= ac_len)
     || ((ac_valid_len-ac_offset) <= ac_len)
    ) {
        // Anti-clone area must locate between content offset and signature addr 
        return E_AC_OFFSET_OR_LEN_INVALID;
    }

    return B_OK;
}
