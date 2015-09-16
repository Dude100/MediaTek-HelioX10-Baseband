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
 *   br_GFH_dl_package_info.h
 *
 * Project:
 * --------
 *   GFH
 *
 * Description:
 * ------------
 *   DL PACKAGE GFH structure definition 
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __BR_GFH_DL_PACKAGE_INFO_H__
#define __BR_GFH_DL_PACKAGE_INFO_H__

#include "br_sw_types.h"
#include "br_GFH.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GFH_DL_PACKAGE_ID        "DL_PACKAGE_ID"

typedef enum {
    IM_NOR         = 0,
    IM_NAND        = 1
} IM_FORMAT;

typedef enum {
   IM_DOWNLOAD     = 0,
   IM_SKIP         = 1,
   IM_ERASE        = 2
} IM_OPERATION;

typedef struct GFH_DL_PACKAGE_INFO_v1 {
    GFH_Header     m_gfh_hdr;
    U8             m_identifier[16];    //including '\0'
    U8             m_platform_id[128];
    U8             m_project_id[64];
    
    U8             m_im_device;
    U8             m_reserve1[3];
    
    U32            m_sig_offset;
    U32            m_sig_len;   
    
    U32            m_customer_info[32];
    
    U32            m_reserve2[16];
} GFH_DL_PACKAGE_INFO_v1;

typedef struct
{
#if defined(WIN32)
    U16            m_bin_type;
#else
    GFH_FILE_TYPE  m_bin_type;
#endif
    U8             m_reserve[2];

    U32            m_bin_start_addr;
    U32            m_bin_length;
    U32            m_operation;
    U32            m_reserve2[4];
} GFH_DL_PACKAGE_EXTRA_INFO;

typedef struct
{
    GFH_Header     m_gfh_hdr;
    U8             m_identifier[16];    //including '\0'
    U8             m_platform_id[128];
    U8             m_project_id[64];
    
    U8             m_im_device;
    U8             m_reserve1[3];
    
    U32            m_sig_offset;
    U32            m_sig_len;

    U32            m_customer_info[32];
    
    U32            m_reserve2[16];

    // V2
    GFH_DL_PACKAGE_EXTRA_INFO m_extra_info[16];
    
} GFH_DL_PACKAGE_INFO_v2;


extern U32  GFH_DL_PACKAGE_IsValid(const GFH_FILE_INFO_v1 *p_gfh_file_info,
                                   const GFH_DL_PACKAGE_INFO_v1 *p_gfh_dl_package);

#ifdef __cplusplus
}
#endif

#endif

