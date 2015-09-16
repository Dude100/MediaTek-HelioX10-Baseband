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
 *   br_GFH_maui_info.h
 *
 * Project:
 * --------
 *   GFH
 *
 * Description:
 * ------------
 *   MAUI_INFO(MAUI ROM information) GFH structure definition 
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __BR_GFH_MAUI_INFO_H__
#define __BR_GFH_MAUI_INFO_H__

#include "br_sw_types.h"
#include "br_GFH.h"

//==============================================================================
// MAUI_INFO definition 
//==============================================================================

typedef struct GFH_MAUI_INFO_v1 {
    GFH_Header      m_gfh_hdr;
    U8              m_platform_id[128];
    U8              m_project_id[64];

    U32             m_bl_maui_paired_ver;
    U32             m_feature_combination;
    U32             m_feature_combination_ex;
    U32             m_extsram_size;

    U32             m_sw_minor_ver;
    U32             m_sds_base_addr; /* For flash tool to check overlap region */
    U32             m_sds_len;       /* For flash tool to check overlap region */
    U32             m_flashtool_ver_req;
} GFH_MAUI_INFO_v1;


typedef struct GFH_MAUI_INFO_v2 {
    GFH_Header      m_gfh_hdr;
    U8              m_platform_id[128];
    U8              m_project_id[64];

    U32             m_bl_maui_paired_ver;
    U32             m_feature_combination;
    U32             m_feature_combination_ex;
    U32             m_extsram_size;

    U32             m_sw_minor_ver;
    U32             m_sds_base_addr; /* For flash tool to check overlap region */
    U32             m_sds_len;       /* For flash tool to check overlap region */
    U32             m_flashtool_ver_req;
    U32             m_boot_cert_addr;
    U32             m_boot_cert_len;
    U8              m_platform_for_check[16];
 #ifdef __USB_FW_DL_SUPPORT__   
    U32             m_extsram_dsp_data;
    U32             m_reserved[11];
 #else
    U32             m_reserved[12];  
 #endif   
} GFH_MAUI_INFO_v2;

#endif

