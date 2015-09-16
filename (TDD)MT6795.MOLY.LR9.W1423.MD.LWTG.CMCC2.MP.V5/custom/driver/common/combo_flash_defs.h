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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   combo_flash_defs.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the data structures used in ComboMCP
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _COMBO_FLASH_DEFS_H_
#define _COMBO_FLASH_DEFS_H_

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "custom_MemoryDevice.h"
#include "DrvFlash.h"
#include "flash_opt.h"

#if (defined(__COMBO_MEMORY_SUPPORT__) || defined(__SERIAL_FLASH__)) || (defined(_NAND_FLASH_BOOTING_) && defined(__NAND_MDL_APPEND__))

#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
#include "br_sw_types.h"
#include "br_GFH.h"
#endif

#define CMEM_FLASH_ID_LEN_NOR  4
#define CMEM_FLASH_ID_LEN_NAND 8
#define CMEM_REGION_INFO_LEN   8
#define CMEM_BLOCK_INFO_LEN    8
#define CMEM_BANK_INFO_LEN     8
#define CMEM_BLOCK_INFO_LEN    8
#if defined(_NAND_FLASH_BOOTING_) && defined(__NAND_MDL_APPEND__)
#define COMBO_MEM_ID_VER       2  // identify block/page/spare size MDL format
#else
#define COMBO_MEM_ID_VER       1
#endif
#define COMBO_MEM_NOR_VER      2
#define COMBO_MEM_IDENTITY_ID     "COMBOMEM_ID"
#define COMBO_MEM_IDENTITY_NOR    "COMBOMEM_NOR"
#define COMBO_MEM_ID_GFH_HEADER   GFH_HEADER(GFH_CMEM_ID_INFO, 1)
#define COMBO_MEM_NOR_GFH_HEADER  GFH_HEADER(GFH_CMEM_NOR_INFO, 1)

#ifdef __SERIAL_FLASH__
#include "combo_sfi_defs.h"
#endif

#if defined(__COMBO_MEMORY_SUPPORT__)
  #if defined (SFI_COMBO_COUNT)  
    #define COMBO_MEM_DEVICE_COUNT SFI_COMBO_COUNT
  #else 
    #ifndef COMBO_MEM_ENTRY_COUNT
    #error "COMBO_MEM_ENTRY_COUNT was not defined"
    #endif
    #define COMBO_MEM_DEVICE_COUNT COMBO_MEM_ENTRY_COUNT
  #endif
#else
  #define COMBO_MEM_DEVICE_COUNT 1
#endif

//-----------------------------------------------------------------------------
// Combo MCP ID list
//-----------------------------------------------------------------------------

// Union: CMEMFlashID
typedef union   {
    kal_uint8  NAND[CMEM_FLASH_ID_LEN_NAND];
    kal_uint16 NOR[CMEM_FLASH_ID_LEN_NOR];
} CMEMFlashID;

#if defined(_NAND_FLASH_BOOTING_) && defined(__NAND_MDL_APPEND__)
typedef struct   {	
    kal_uint16  page_size;
    kal_uint16  spare_size;
	kal_uint16  block_size;
} CMEMFlashInfo;
#endif
// Type: CMEMEntryID
typedef struct {
    kal_uint8       DeviceType;  // rename to Flash Type: NOR / NAND /EMMC
    kal_uint8       IDLength;
#if defined(_NAND_FLASH_BOOTING_) && defined(__NAND_MDL_APPEND__)
		CMEMFlashInfo	FlashDevice_Info; //include block, page and spare size
#endif	
    #if defined(_NAND_FLASH_BOOTING_)|| defined(__SERIAL_FLASH__)
    kal_uint8       ID[CMEM_FLASH_ID_LEN_NAND];
    #else
    kal_uint16      ID[CMEM_FLASH_ID_LEN_NOR];
    #endif
} CMEMEntryID;

// Type: CMEMEntryIDList
typedef struct {
    #if !defined(__SV5_ENABLED__) && !defined(__SV5X_ENABLED__)
    char               m_identifier[16];   // MTK_CMB_ID_INFO
    #endif
    unsigned int       m_ver;
    unsigned int       Count;
    CMEMEntryID        List[COMBO_MEM_DEVICE_COUNT];
} CMEMEntryIDList;

//-----------------------------------------------------------------------------
// Combo MCP SW Settings
//-----------------------------------------------------------------------------
// Type: FlashBlockLayout
typedef struct  {
    kal_uint32  Offset;
    kal_uint32  Size;
} FlashBlockLayout;

// Type: CMEMEntryNOR
typedef struct {
    kal_uint16          FDMType;       // rename to Device Type: DEFAULT / SIB
    kal_uint16          PageBufferSize;   // Autogen from MDL
    kal_uint32          UniformBlocks;    // Uniform Block Layout
    FlashBlockLayout    BlockLayout[CMEM_REGION_INFO_LEN];
    FlashBankInfo       BankInfo[CMEM_BANK_INFO_LEN];
} CMEMEntryNOR;

// Type: CMEMEntryNORList
typedef struct {
    #if !defined(__SV5_ENABLED__) && !defined(__SV5X_ENABLED__)
    char               m_identifier[16];   // MTK_CMB_ID_INFO
    #endif
    unsigned int       m_ver;
    unsigned int       Count;
    CMEMEntryNOR       List[COMBO_MEM_DEVICE_COUNT];
} CMEMEntryNORList;


#endif // defined(__COMBO_MEMORY_SUPPORT__) || defined(__SERIAL_FLASH__)

#endif // ifndef _COMBO_FLASH_DEFS_H_

