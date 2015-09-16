/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   custom_fota.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the FOTA (Firmware Over the Air) related setting.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************
*   Customization Part      
********************************************/
#ifdef __MTK_TARGET__

#ifdef __FOTA_ENABLE__

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "flash_opt.h"
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "fat_fs.h"
#include "DrvFlash.h"
#include "custom_fota.h"
#include "fota.h"
#if defined(__FOTA_DM__)
#include "custom_img_config.h"
#include "fue_err.h"
#include "fue.h"
#include "ssf_fue_support.h"
#include "fue_nand_lae_support.h"
#include "fue_update_support.h"
#include "bl_FOTA.h"
#include "fue_internal.h"
#endif /* __FOTA_DM__ */
#include "bl_loader.h"

#if defined(__FOTA_DM__)
/*******************************************
*  Data buffer declaration
********************************************/
#if defined(__UBL__)
//kal_uint32 sst_fue_header_buffer_bl[FOTA_INFO_BLOCK_SEARCH_ROUND][FOTA_FLASH_MAX_PAGE_SIZE>>2];
#endif /* __UBL__ */

#if defined(__FUE__)
//kal_uint32 ssf_page_buff_ua[FOTA_FLASH_MAX_PAGE_SIZE>>2];
#endif /* __FUE__ */

//kal_uint32 local_temp_page_buffer_ua[FOTA_FLASH_MAX_PAGE_SIZE>>2];

kal_uint32 fue_adm_buffer_pool[FOTA_FLASH_MAX_PAGE_SIZE];

FOTA_Package_List_st g_fota_package_blocks[FOTA_PACKAGE_BLOCK_NUMBER];

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
#pragma arm section zidata = "NONCACHEDZI"
#endif

kal_uint32 fue_pkg_page_buffer[FOTA_FLASH_MAX_PAGE_SIZE>>2];
kal_uint32 fue_record_header_buffer[FOTA_INFO_BLOCK_SEARCH_ROUND][FOTA_FLASH_MAX_PAGE_SIZE>>2];
kal_uint32 fue_update_page_buffer[FOTA_FLASH_MAX_PAGE_SIZE>>2];
kal_uint32 fue_temp_table_buffer_ua[FOTA_MAUI_MAPPING_TABLE_SIZE>>2];

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
#pragma arm section zidata
#endif

const kal_uint32  FOTA_PKG_BLOCKS = FOTA_PACKAGE_BLOCK_NUMBER;

const kal_uint32 FOTA_FUE_RESIDENT_SPACE =  FOTA_UE_RESIDENT_FLASH_SPACE_SIZE;

const kal_uint32 FOTA_FUE_BACKUP_SPACE =  FOTA_UE_BACKUP_FLASH_SPACE_SIZE;

const kal_uint32 FOTA_IMAGE_MAPPING_TABLE_SIZE = FOTA_MAUI_MAPPING_TABLE_SIZE;

const kal_uint32 FOTA_MAUI_INFO_SEARCH_RANGE=  MAUI_IMAGE_INFO_RANGE;

const kal_uint32 FOTA_FUE_PAGE_BUFFER_SIZE =  FOTA_FLASH_MAX_PAGE_SIZE;

const kal_uint32 FOTA_IMG_SPACE_INFO_PAGE =  IMAGE_SPACE_PAGE_INDEX;

const kal_uint32 FOTA_IMG_LIST_INFO_PAGE =  IMAGE_LIST_PAGE_INDEX;

const kal_uint32 FOTA_IMG_VERSION_INFO_PAGE =  VERSION_INFO_PAGE_INDEX;

const kal_uint32 FOTA_IMG_LIST_VALID_PAGES =  VALID_PAGE_NUMBER;

const kal_uint32 FOTA_MTK_ILB_TAIL[] = MTK_ILB_TAIL_TAG;

const kal_uint32 FOTA_MTK_ILB_FOTA[] = MTK_ILB_FOTA_TAG;

const kal_uint32 FOTA_MTK_ILB_TAG_SIZE = sizeof(FOTA_MTK_ILB_TAIL);

FOTA_Area_Info_Wrapper_st  FOTA_NFB_Area_Info;

#endif /* __FOTA_DM__ */

/*******************************************
*  Data structure declaration
********************************************/
#if defined(__FUE__)
extern kal_uint32 Image$$UA_CUSTOM_ZI$$Base;
const kal_uint32 fota_ua_heap_base = (kal_uint32)&Image$$UA_CUSTOM_ZI$$Base;
#endif

#if defined(__FOTA_DM__)
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

/* ROM image region information */
/* auto gen according to scatter file */
extern kal_uint32 Image$$SECONDARY_ROM$$Base;
extern kal_uint32 Load$$DUMMY_END$$Base;
extern kal_uint32 Load$$FOTA_ROM_TAIL$$Base;
extern kal_uint32 Load$$FOTA_FIXED$$Base;

/* Image execution region information */
FOTA_NFB_ROM_Image_Info FOTA_NFB_LOAD_INFO[FOTA_MAUI_IMAGE_AMOUNT];

const kal_uint32  FOTA_NFB_UE_SEARCH_RANGE = FOTA_UE_SEARCH_RANGE_SIZE;
#if defined(_NAND_FLASH_BOOTING_)
const kal_uint32  FOTA_FAT_BASE_ADDR        = NAND_FLASH_BASE_ADDRESS;
#else
const kal_uint32  FOTA_FAT_BASE_ADDR        = 0xffffffff;
#endif


#if defined(__FUE__)

#pragma arm section zidata = "NONCACHEDZI"

/* FUE NAND flash content cache */
FOTA_NAND_Cache_Entry_st FOTA_Page_Cache[FUE_CACHE_WAY][FUE_CACHE_ENTRIES];

/* FUE block mapping table */
kal_uint16 FUE_Map_Table[FOTA_MAUI_MAPPING_TABLE_SIZE>>1];

#pragma arm section zidata

/* FUE updateble area information */
FOTA_Flash_Alloc_Range_st  FUE_Update_Alloc_info[FOTA_MAUI_IMAGE_AMOUNT+1]; /* plus one for update agent itself */
FOTA_Image_Area_st         FUE_Update_Image_area[FOTA_MAUI_IMAGE_AMOUNT+1];

/* FUE mapping information of each image */
kal_uint32           FUE_NFB_Mapping_Block[FOTA_MAUI_IMAGE_AMOUNT+1];             /* plus 1 for UA image */
kal_uint32           FUE_NFB_Session_Record[FOTA_MAUI_IMAGE_AMOUNT+1];            /* for mapping block */
kal_uint32           FUE_NFB_Mapping_Session[FOTA_MAUI_IMAGE_AMOUNT+1];           /* for mapping table */
kal_uint32           FUE_NFB_Mapping_Page[FOTA_MAUI_IMAGE_AMOUNT+1];              /* starting page that contains current mappiong table */
kal_uint32           FUE_NFB_Next_Available_Page[FOTA_MAUI_IMAGE_AMOUNT+1];  /* available page next to the end page of current mapping table */
Nand_Update_Area_ST  FUE_NFB_Area[FOTA_MAUI_IMAGE_AMOUNT+1];

#endif /*__FUE__*/

#else /* !(_NAND_FLASH_BOOTING_||__EMMC_BOOTING__) */

/* For FOTA, these region information shoule be put on RAM */
FlashRegionInfo NORRegionInfo[] =
{
    CONFIG_FOTA_NOR_REGION_DEF
    EndRegionInfo /* Don't modify this line */
};

FlashBlockInfo NORBlockInfo[] =
{
    CONFIG_FOTA_NOR_BLOCK_DEF
    EndBlockInfo /* Don't modify this line */
};

FlashBankInfo FOTANORBankInfo[] =
{
    CONFIG_FOTA_NOR_BANK_DEF
    EndBankInfo /* Don't modify this line */
};

const kal_uint32  FOTA_FAT_BASE_ADDR        = NOR_FLASH_BASE_ADDRESS;

#endif /* _NAND_FLASH_BOOTING_||__EMMC_BOOTING__ */
#endif /* __FOTA_DM__ */

#if !defined(__FUE__) && !defined(__BL__)
/* ---------------------------------------------------------------------------------
DESCRIPTION
   FOTA Customization Initialization API
   FOTA_Initialize() will call this function, this is for customization.
   User can register their own customized authentication or 
   decryption function in this function
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: customization error
--------------------------------------------------------------------------------- */
#if !defined(__FOTA_DM__)
kal_int32 FOTA_CustomInitialize(void)
{
   kal_uint32 AddrLowBound=0, AddrUpperBound  = 0;
   kal_uint32 region = 0, StartBlkIndex = 0;

   FOTAData.SpareBaseAddr = FOTAData.FlashBaseAddr + FOTA_SPARE_BASE_ADDRESS;
   FOTAData.OriginalBaseAddr = FOTAData.FlashBaseAddr + FOTA_ORIGINAL_BASE_ADDRESS;
   FOTAData.TotalFOTALength = FOTA_SPARE_ALLOCATED_SIZE;
   FOTAData.NORRegionInfo = (FlashRegionInfo *)NORRegionInfo;
   FOTAData.SpareCurrAddr = FOTAData.SpareBaseAddr;
   FOTAData.NextBlockAddr = FOTAData.SpareBaseAddr;
   
   /*calculate the start block index*/
   AddrUpperBound = NORRegionInfo[0].RegionBlocks * NORRegionInfo[0].BlockSize;
   
   do{
      if (AddrUpperBound >= FOTA_SPARE_BASE_ADDRESS)
         break;
      else
      {
         StartBlkIndex += NORRegionInfo[region].RegionBlocks;
         region++;
         AddrLowBound = AddrUpperBound;
         AddrUpperBound = NORRegionInfo[region].RegionBlocks * NORRegionInfo[region].BlockSize;
      }
   }while(NORRegionInfo[region].RegionBlocks != 0);

   if(NORRegionInfo[region].RegionBlocks == 0 || (FOTA_SPARE_BASE_ADDRESS - AddrLowBound)%NORRegionInfo[region].BlockSize !=0)
   {
      return ERROR_FOTA_CUSTOMIZATION;
   }
   FOTAData.SpareStartBlkIndex = StartBlkIndex + (FOTA_SPARE_BASE_ADDRESS - AddrLowBound)/NORRegionInfo[region].BlockSize;

   /*register private authentication function or encryption function */
   FOTA_Reg_Auth((CALLBACK_Auth_FUNC)NULL);
   FOTA_Reg_Decrypt((CALLBACK_Decrypt_FUNC)NULL);
   
   return 0;
   
}
#else /* __FOTA_DM__ */
/* ---------------------------------------------------------------------------------
DESCRIPTION
   FOTA Customization Initialization API
   FOTA_Initialize() will call this function, this is for customization.
   User can register their own customized authentication or 
   decryption function in this function
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: customization error
--------------------------------------------------------------------------------- */
kal_int32 FOTA_CustomInitialize(void)
{
   return 0;
}

#endif /* __FOTA_DM__ */
#endif /* !__FUE__ && !__UBL__ */

#if defined(__FOTA_DM__)
/* ---------------------------------------------------------------------------------
DESCRIPTION
   return flash reserved area base address
PARAMETER
   NULL
RETURN
   NULL
--------------------------------------------------------------------------------- */
kal_uint32 FOTA_Reserved_Area_Base_Address(void)
{
   kal_uint32 start_addr = 0;
   if(FOTA_BACKUP_STORAGE_BASE != INVALID_DWORD)
   {
      start_addr = FOTA_BACKUP_STORAGE_BASE+FOTA_BACKUP_STORAGE_SIZE;
   }
   else
   {
      start_addr = FOTA_PACKAGE_STORAGE_BASE+FOTA_PACKAGE_STORAGE_SIZE;
   }
   return start_addr;
}

/* ---------------------------------------------------------------------------------
DESCRIPTION
   return package storage area space information
PARAMETER
   NULL
RETURN
   NULL
--------------------------------------------------------------------------------- */
void FOTA_GetPackageStorage(kal_uint32 *base_addr, kal_uint32 *len)
{
    ASSERT(base_addr != NULL);
    ASSERT(len != NULL);

    *base_addr = FOTA_PACKAGE_STORAGE_BASE;
    *len = FOTA_PACKAGE_STORAGE_SIZE;
}

/* ---------------------------------------------------------------------------------
DESCRIPTION
   return package storage area space base address
PARAMETER
   NULL
RETURN
   NULL
--------------------------------------------------------------------------------- */
kal_uint32 FOTA_GetPackageStorageBase(void)
{
    return FOTA_PACKAGE_STORAGE_BASE;
}

/* ---------------------------------------------------------------------------------
DESCRIPTION
   return package storage area space size
PARAMETER
   NULL
RETURN
   NULL
--------------------------------------------------------------------------------- */
kal_uint32 FOTA_GetPackageStorageSize(void)
{
    return FOTA_PACKAGE_STORAGE_SIZE;
}

/* ---------------------------------------------------------------------------------
DESCRIPTION
   return FAT area base address
PARAMETER
   NULL
RETURN
   NULL
--------------------------------------------------------------------------------- */
kal_uint32 FOTA_GetFATBaseAddr(void)
{
#if defined(_NAND_FLASH_BOOTING_) || defined(__UP_PKG_ON_NAND__)
    return NAND_FLASH_BASE_ADDRESS;
#elif defined(__EMMC_BOOTING__) 
    return 0xffffffff;
#else
    return NOR_FLASH_BASE_ADDRESS;
#endif
}

#if defined(__FUE__)

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
/* ---------------------------------------------------------------------------------
DESCRIPTION
   return FAT area base address
PARAMETER
   NULL
RETURN
   NULL
--------------------------------------------------------------------------------- */
void FOTA_InitNFBControl(FOTA_NFB_Control *fota_ctrl)
{
    ASSERT(fota_ctrl != NULL);

    kal_mem_set(FUE_Map_Table, 0xFF, FOTA_MAUI_MAPPING_TABLE_SIZE);

    kal_mem_set(FUE_NFB_Mapping_Block, 0xFF, (FOTA_MAUI_IMAGE_AMOUNT+1)<<2);
    kal_mem_set(FUE_NFB_Session_Record, 0xFF, (FOTA_MAUI_IMAGE_AMOUNT+1)<<2);
    kal_mem_set(FUE_NFB_Mapping_Session, 0xFF, (FOTA_MAUI_IMAGE_AMOUNT+1)<<2);
    kal_mem_set(FUE_NFB_Mapping_Page, 0xFF, (FOTA_MAUI_IMAGE_AMOUNT+1)<<2);
    kal_mem_set(FUE_NFB_Next_Available_Page, 0xFF, (FOTA_MAUI_IMAGE_AMOUNT+1)<<2);
    
    kal_mem_set(FUE_NFB_Area, 0xFF, sizeof(Nand_Update_Area_ST)*(FOTA_MAUI_IMAGE_AMOUNT+1));
    kal_mem_set(FUE_Update_Alloc_info, 0xFF, sizeof(FOTA_Flash_Alloc_Range_st)*(FOTA_MAUI_IMAGE_AMOUNT+1));
    kal_mem_set(FUE_Update_Image_area, 0xFF, sizeof(FOTA_Image_Area_st)*(FOTA_MAUI_IMAGE_AMOUNT+1));

    fota_ctrl->FOTA_NFB_LTP_Table       = FUE_Map_Table;
    fota_ctrl->FOTA_NFB_Area            = FUE_NFB_Area;
    
    fota_ctrl->NFB_Mapping_Block        = FUE_NFB_Mapping_Block;
    fota_ctrl->NFB_Session_Record       = FUE_NFB_Session_Record;
    fota_ctrl->NFB_Mapping_Session      = FUE_NFB_Mapping_Session;
    fota_ctrl->NFB_Mapping_Page         = FUE_NFB_Mapping_Page;
    fota_ctrl->NFB_Next_Available_Page  = FUE_NFB_Next_Available_Page;

    fota_ctrl->NFB_FUE_Info.m_update_alloc = FUE_Update_Alloc_info;
    fota_ctrl->NFB_FUE_Info.m_update_area  = FUE_Update_Image_area;
}

#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

#endif /* __FUE__ */

#endif /* __FOTA_DM__ */

#endif /*__FOTA_ENABLE__*/

#endif
