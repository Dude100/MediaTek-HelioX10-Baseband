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
 *   combo_flash_init.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the ComboMCP Init function
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __COMBO_FLASH_INIT_H__
#define __COMBO_FLASH_INIT_H__

#include "flash_opt.h"
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "combo_flash_defs.h"

#if (defined(__COMBO_MEMORY_SUPPORT__) || defined(__SERIAL_FLASH__)) || (defined(_NAND_FLASH_BOOTING_) && defined(__NAND_MDL_APPEND__))

#include "custom_MemoryDevice.h"
#include "fat_fs.h"
#include "DrvFlash.h"

// Naming Rule: Camo
typedef enum   {
    CMEM_NO_ERROR=0,
    CMEM_ERR_ID_NOT_FOUND,
    CMEM_ERR_FDM_MISMATCH,
    CMEM_ERR_MTD_MISMATCH,
    CMEM_ERR_FDM_INIT_FAIL,
    CMEM_ERR_MTD_INIT_FAIL,
    CMEM_ERR_FDM_REGION_INFO_OVERFLOW
} Enum_CMEM_StatusCode;

typedef enum   {
    CMEM_TYPE_END_OF_LIST=0,
    CMEM_TYPE_NAND,
    CMEM_TYPE_NOR,
    CMEM_TYPE_SERIAL_NOR_FLASH
} Enum_CMEM_Type;


//Sync with original flash_opt.h and MemoryDeviceList
//Ransense series is phase out
typedef enum   {
    CMEM_FDM_NOR_DEFAULT=0,	//for serial flash
    CMEM_NOR_CS_INTEL_SERIES,
    CMEM_NOR_CS_INTEL_SIBLEY,
    CMEM_NOR_CS_RAM_DISK,
    CMEM_NOR_CS_SST,
    CMEM_NOR_CS_AMD_SERIES,
    CMEM_NOR_CS_SPANSION_PL_J,
    CMEM_NOR_CS_SPANSION_PL_N,
    CMEM_NOR_CS_SPANSION_WS_N,
    CMEM_NOR_CS_SPANSION_WS_P,
    CMEM_NOR_CS_SPANSION_GL_A,
    CMEM_NOR_CS_SPANSION_GL_N,
    CMEM_NOR_CS_SPANSION_NS_N,
    CMEM_NOR_CS_SPANSION_NS_P,
    CMEM_NOR_CS_SPANSION_NS_J,
    CMEM_NOR_CS_TOSHIBA,
    CMEM_NOR_CS_TOSHIBA_TV,
    CMEM_NOR_CS_TOSHIBA_TY,
    CMEM_NOR_CS_SILICON7,
    CMEM_NOR_CS_SAMSUNG_SPANSION_NS_J_LIKE,
    CMEM_NOR_CS_SPANSION_VS_R,
    CMEM_NOR_CS_SPANSION_VS_R64,
    CMEM_NOR_CS_SPANSION_WS_R
   
} Enum_CMEM_CommSeries;

// Functions Exported to MAUI
extern kal_int32 ComboMem_Initialize(void);
extern kal_int32 CMEM_Init_FullDriver(void);
extern kal_uint32 CMEM_BlockSize(kal_uint32 address);

kal_int32 CMEM_Index(void);
const CMEMEntryID *CMEM_GetIDEntry(kal_uint32 index);

#endif // (defined(__COMBO_MEMORY_SUPPORT__) || defined(__SERIAL_FLASH__))

// Function exported to EMI/SFI
kal_int32 CMEM_EMIINIT_Index(void);
kal_bool CMEM_CheckValidDeviceID(kal_uint8 *id);
kal_bool CMEM_EMIINIT_CheckValidDeviceID(kal_uint8 *id);

#if defined(_NAND_FLASH_BOOTING_) && defined(__NAND_MDL_APPEND__)
kal_bool CMEM_GetflashInfo(kal_uint8* id, CMEMFlashInfo* st);
#endif

#endif // __COMBO_FLASH_INIT_H__
