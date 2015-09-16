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
 *   GFH_defs.h
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *   Define values and structures for GFH body definition
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __GFH_DEFS_H__
#define __GFH_DEFS_H__

#include "br_GFH.h"
#include "sw_types.h"

//==============================================================================
// SIGNATURE version and size, depending on the platform
// CAUSION: DO NOT change these values at well
//==============================================================================

#define SIG_HASH_VER                (1)                 //Signature Configure V1, RSA2048 + SHA256
#define SIG_NONE_LEN                (0)
#define SIG_PHASH_LEN               (32)
#define SIG_SINGLE_LEN              (256)
#define SIG_SINGLE_AND_PHASH_LEN    (292)
#define SIG_MULTI_LEN               (932)

//==============================================================================
// GFH structures
// CAUSION: DO NOT change these definition at well
//==============================================================================

typedef struct {
    GFH_Header      m_gfh_hdr;
    U8              _reserved[524];
} GFH_BL_SEC_KEY_v1;

typedef struct {
    GFH_Header      m_gfh_hdr;
    U8              _reserved[524];
} GFH_MAUI_SEC_KEY_v1;

typedef GFH_MAUI_SEC_KEY_v1 GFH_MAUI_CODE_KEY_v1;
typedef GFH_MAUI_SEC_KEY_v1 GFH_MAUI_SECURE_RO_KEY_v1;
typedef GFH_MAUI_SEC_KEY_v1 GFH_MAUI_RESOURCE_KEY_v1;

typedef struct {
    GFH_Header      m_gfh_hdr;
    U8              _reserved[40];
} GFH_BROM_SEC_CFG_v1;

typedef struct {
    GFH_Header      m_gfh_hdr;
    U8              _reserved[8];
} GFH_BROM_CFG_v1;

typedef struct {
    GFH_Header      m_gfh_hdr;
    U8              _reserved[73];
} GFH_BROM_CFG_v2;

typedef struct {
    GFH_Header      m_gfh_hdr;
    U8              _reserved[92];
} GFH_BROM_CFG_v3;

#endif /* __GFH_DEFS_H__ */

