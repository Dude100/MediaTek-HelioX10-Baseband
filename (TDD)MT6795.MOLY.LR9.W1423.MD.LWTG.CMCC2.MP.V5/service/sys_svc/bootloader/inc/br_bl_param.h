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
 *   br_bl_param.h
 *
 * Project:
 * --------
 *   MBL
 *
 * Description:
 * ------------
 *   The structure declaration of parameters to pass to BL
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __BR_BL_PARAM_H__
#define __BR_BL_PARAM_H__

#include "br_sw_types.h"
#include "br_bl_location.h"
#include "br_me_identity.h"

//==============================================================================
// BL parameter
//==============================================================================

#define BL_PARAM_VER    3

typedef enum {
     BL_NOT_EXIST       = 0
    ,BL_NOT_LOADED_YET
    ,BL_LOAD_ABORTED
    ,BL_LOADED
    ,BL_VERIFIED
} BL_LOADING_STATE;

typedef struct BL_LoadInfo {
    BL_Location                 m_bl_location;
    U8                          m_bl_index;
    BL_LOADING_STATE            m_state;
    U16                         m_code_1;
    U16                         m_code_2;
} BL_LoadInfo;

#define BL_PARAM_BL_ALL_PASS            0x00000001
#define BL_PARAM_USB_COM_ENABLED        0x00000002
#define BL_PARAM_BOOT_RETRY_HAPPENED    0x00000004
#define BL_PARAM_JTAG_IS_DISABLED       0x00000008
#define BL_PARAM_BROM_USBDL_FAILED      0x00000010

typedef struct BL_Param_v3 {

    // WARNING! if any member of this structure is changed, version must be updated! 

    // BL param structure version 
    U32                         m_ver;  // this structure will directly export to others, version field is necessary

    // header block info 
    HeaderBlock_Info            m_hdrblk_info;

    // BL loading info 
    BL_LoadInfo                 m_bl_loadinfo[MAX_BL_NUM];

    // BOOTROM flags  
    U32                         m_brom_flags;

    // ME Identity
    ME_Identity                 m_me_identity;

    // SCTRL_CERT
    U32                         m_sctrl_cert_file_addr;
    U32                         m_sctrl_cert_file_len;

    // TOOL_AUTH
    U32                         m_tool_auth_file_addr;
    U32                         m_tool_auth_file_len;

    // ROOT_CERT
    U32                         m_root_cert_file_addr;
    U32                         m_root_cert_file_len;

    // shared flash driver general handle 
    U32                         m_sd_flash_drv_handle_addr;

    // shared NAND flash driver 
    U32                         m_sd_nand_flash_drv_tbl_addr;

    // shared crypto lib driver
    U32                         m_sd_crypto_lib_tbl_addr;

    // shared common functions 
    U32                         m_sd_common_func_tbl_addr;

    // shared SDIO driver
    U32                         m_sd_sdio_drv_tbl_addr;

    // shared xboot cmd functions
    U32                         m_sd_xboot_cmd_func_tbl_addr;
} BL_Param_v3;

#if defined(__BOOTROM__)
extern BL_Param_v3  g_BROM_BL_Param;
#endif

#endif
