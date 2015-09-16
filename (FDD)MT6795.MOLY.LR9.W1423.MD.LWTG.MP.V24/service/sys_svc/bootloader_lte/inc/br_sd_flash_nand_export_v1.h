/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   br_sd_flash_nand_export_v1.h
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *   BOOTROM NAND flash shared driver version 1 (EXPORTED APIs)
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __BR_SD_FLASH_NAND_EXPORT_V1_H__
#define __BR_SD_FLASH_NAND_EXPORT_V1_H__

#include "nfi_sw.h"

#ifdef __cplusplus
extern "C" {
#endif

//==============================================================================
// Shared NAND flash driver handle
//==============================================================================

#if defined(MT6276)
#define SD_NAND_HANDLE_SIZE     844
#elif defined(MT6256)
#define SD_NAND_HANDLE_SIZE     1112   //E1:860, E2, E3, E4: 1112
#elif defined(MT6255)
#define SD_NAND_HANDLE_SIZE     960
#else
#error Please define SD_NAND_HANDLE_SIZE!
#endif

typedef struct SD_NAND_Handle {
    // leading 32bits integer to make structure 4 bytes aligned 
    U32     m_dummy_u32;
    U8      m_dummy_data[SD_NAND_HANDLE_SIZE-4];
} SD_NAND_Handle;

//==============================================================================
// Shared NAND flash driver function prototype
//==============================================================================

typedef void            (*SD_NFI_HANDLE_INIT_V1)    (void * p_handle);
typedef void            (*SD_NFI_INIT_V1)           (bool bSpeedUp, U32 dwAcccon);
typedef void            (*SD_NFI_CONFIG_BY_HDR_V1)  (const NFB_HEADER *pNFB_header);
typedef void            (*SD_NFI_DEINIT_V1)         (void);
typedef bool            (*SD_NFI_IS_BAD_BLOCK_V1)   (U32 block_no);
typedef NFI_Error_Code  (*SD_NFI_READ_WITH_ECC_V1)  (U32 statr_page, void * p_buf, U32 buf_len, U32 attr, P_U32 p_last_page, P_U32 p_rest_len);
typedef void            (*SD_NFI_TTBL_ENABLE_V1)    (U32 num, P_U32 p_entry);
typedef void            (*SD_NFI_TTBL_DISABLE_V1)   (void);

//==============================================================================
// Shared NAND flash driver function table
//==============================================================================
typedef struct SD_Nand_FuncTable_v1 {
    SD_NFI_HANDLE_INIT_V1       m_handle_init;
    SD_NFI_INIT_V1              m_init;
    SD_NFI_CONFIG_BY_HDR_V1     m_config_by_hdr;
    SD_NFI_DEINIT_V1            m_de_init;
    SD_NFI_IS_BAD_BLOCK_V1      m_is_bad_block;
    SD_NFI_READ_WITH_ECC_V1     m_read_with_ecc;
    SD_NFI_TTBL_ENABLE_V1       m_ttbl_enable;
    SD_NFI_TTBL_DISABLE_V1      m_ttbl_disable;
} SD_Nand_FuncTable_v1;

#ifdef __cplusplus
}
#endif

#endif

