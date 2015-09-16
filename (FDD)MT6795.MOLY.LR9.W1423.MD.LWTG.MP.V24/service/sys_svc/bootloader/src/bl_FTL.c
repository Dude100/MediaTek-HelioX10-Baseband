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
 *   bl_FTL.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   Wrapper to flash translate layer
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
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "FTL.h"

#if defined(__16_3_SEG__) || defined(__32_32_SEG__)

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
#error "No NFB/eMMC with 16+3 or 32+32"
#endif

#define SF_BLOCK_SIZE (64*1024)
#define SF_PAGE_SIZE  (512)

FTL_STATUS_CODE FTL_Init(void *pArgv)
{
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_DeInit(void *pArgv)
{
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_ReadPage(kal_uint32 block, kal_uint32 page, kal_uint32 *pBuf, FTL_OptParam *opt_param)
{
   memcpy(pBuf, (const void*)((block*SF_BLOCK_SIZE+page*SF_PAGE_SIZE)|custom_get_NORFLASH_Base()), SF_PAGE_SIZE);
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_WritePage(kal_uint32 block, kal_uint32 page, kal_uint32 *pBuf, FTL_OptParam *opt_param)
{
   ASSERT(0);
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_CheckGoodBlock(kal_uint32 block, FTL_OptParam *opt_param)
{
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_MarkBadBlock(kal_uint32 block, FTL_OptParam *opt_param)
{
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_EraseBlock(kal_uint32 block, FTL_OptParam *opt_param)
{
   return FTL_SUCCESS;
}

kal_uint32 FTL_GetBlockSize(kal_uint32 block, FTL_OptParam *opt_param)
{
   return SF_BLOCK_SIZE;
}

kal_uint32 FTL_GetPageSize()
{
   return SF_PAGE_SIZE;
}

kal_uint32 FTL_AddrToBlockPage(kal_uint32 addr, kal_uint32 *pBlock, kal_uint32 *pPage, FTL_OptParam *opt_param)
{
   ASSERT(0);
   return FTL_SUCCESS;
}

kal_uint32 FTL_BlockPageToAddr(kal_uint32 Block, kal_uint32 Page, kal_uint32 *addr, FTL_OptParam *opt_param)
{
   ASSERT(0);
   return FTL_SUCCESS;
}

FTL_FuncTbl ftlFuncTbl =
{
   FTL_Init,
   FTL_DeInit,
   FTL_ReadPage,
   NULL,
   FTL_WritePage,
   FTL_CheckGoodBlock,
   FTL_MarkBadBlock,
   FTL_EraseBlock,
   FTL_GetBlockSize,
   FTL_GetPageSize,
   FTL_AddrToBlockPage,
   FTL_BlockPageToAddr
};

kal_bool FTL_isPollingMode()
{
   return KAL_FALSE;
}

#elif defined(_NAND_FLASH_BOOTING_)

#include "bl_nfi_wrapper.h"
#include "bl_FOTA.h"
#include "bl_loader.h"
#include "bl_sectiondef.h"

#include "fota_error.h"
#include "NAND_DAL.h"
#include "NAND_MTD.h"

extern BOOTL_HEADER     BLHeader;

#if defined(__MINI_BOOTLOADER__) && defined(__NFI_SHARED_DRV__) 
SD_Nand_FuncTable_v1 *g_pNfiFuncTbl = NULL;

__ext_un_init_zi__ SD_NAND_Handle g_sd_NFI_Drv_Handle;

#endif


FTL_STATUS_CODE NFB_ERR_2_FTL_ERR(kal_uint32 error)
{
#if defined(__MINI_BOOTLOADER__) && defined(__NFI_SHARED_DRV__) 

   switch(error)
   {
   case NFI_OPERATION_SUCCESS:  
       return FTL_SUCCESS;
       
   case NFI_READ_TIMEOUT:
       return FTL_ERROR_READ_FAILURE;
       
   case NFI_PROG_FAILED:
       return FTL_ERROR_WRITE_FAILURE;
       
   case NFI_ERASE_FAILED:
       return FTL_ERROR_ERASE_FAILURE;
       
   case NFI_BAD_BLOCK:
       return FTL_ERROR_BAD_BLOCK;
       
   case NFI_ECC_CORRECTED:
       return FTL_ERROR_ECC_CORRECTED;
   }

#else 

   switch(error)
   {
   case ERROR_NFB_SUCCESS:  
       return FTL_SUCCESS;
       
   case ERROR_NFB_READ:
       return FTL_ERROR_READ_FAILURE;
       
   case ERROR_NFB_PROGRAM:
       return FTL_ERROR_WRITE_FAILURE;
       
   case ERROR_NFB_ERASE:
       return FTL_ERROR_ERASE_FAILURE;
       
   case ERROR_NFB_BAD_BLOCK:
       return FTL_ERROR_BAD_BLOCK;
       
   case ERROR_NFB_ECC_CORRECTED:
       return FTL_ERROR_ECC_CORRECTED;
   }
#endif /* __NFI_SHARED_DRV__ */

   return FTL_ERROR_OTHER_ERROR;
}

#ifdef __SV5_ENABLED__

#ifdef __MINI_BOOTLOADER__

extern kal_int32 NFB_ReadPhysicalPageWithSpare_NoTT(kal_uint32 PhyBlock, kal_uint32 PhyPage, kal_uint32 *Data, kal_uint32 *Spare);
extern kal_int32 NFB_CheckGoodBlock_NoTT(kal_uint32 Block);

#ifdef __NFI_SHARED_DRV__

void FTL_SetNFISharedDrv(kal_uint32 funcTblAddr, kal_uint32 *pHandleBufAddr)
{
   g_pNfiFuncTbl = (SD_Nand_FuncTable_v1*)funcTblAddr;
   *pHandleBufAddr = (kal_uint32)&g_sd_NFI_Drv_Handle;
}

#endif /* __NFI_SHARED_DRV__ */

FTL_STATUS_CODE FTL_InitBL(void *pArgv)
{

#ifdef __NFI_SHARED_DRV__

   g_pNfiFuncTbl->m_handle_init(&g_sd_NFI_Drv_Handle);
   g_pNfiFuncTbl->m_init(FALSE, 0x00033333);
   g_pNfiFuncTbl->m_config_by_hdr((NFB_HEADER*)(pArgv));

#else

   NFB_HEADER *pNfbHeader = (NFB_HEADER*)pArgv;
   kal_uint32 page_size;
   kal_uint32 page_per_block;
   NFI_SUBMENU sub_menu;
   kal_uint32 sec_num = 0;

   page_size      = pNfbHeader->NFIinfo.pageSize;
   page_per_block = pNfbHeader->pagesPerBlock;

   /* configure NFI according to extracted bootloader header */
   sec_num = page_size/512;
   sub_menu.spareSize = pNfbHeader->spareSize/(sec_num ? sec_num : 1);
   sub_menu.blockSize = page_per_block;
   NFI_Config(&pNfbHeader->NFIinfo, &sub_menu);

#endif /* __NFI_SHARED_DRV__ */
   
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_DeInitBL(void *pArgv)
{
   return FTL_SUCCESS;
}

kal_uint32 FTL_GetBlockSize(kal_uint32 block, FTL_OptParam *opt_param)
{
   return BLHeader.pagesPerBlock*BLHeader.NFIinfo.pageSize;
}

kal_uint32 FTL_GetPageSize()
{
   return BLHeader.NFIinfo.pageSize;
}

FTL_STATUS_CODE FTL_ReadPageBL(kal_uint32 block, kal_uint32 page, kal_uint32 *pBuf, FTL_OptParam *opt_param)
{
   kal_int32 status;   

#ifdef __NFI_SHARED_DRV__ 

   status = g_pNfiFuncTbl->m_read_with_ecc(block*BLHeader.pagesPerBlock+page, pBuf, BLHeader.NFIinfo.pageSize, 0, NULL, NULL);

   if(status == NFI_ECC_CORRECTED || status == NFI_ECC_PIO_CORRECTED)
   {
      return FTL_SUCCESS;
   }
   
#else
   kal_uint32 spare[NFI_MAX_SPARE_SIZE_PER_PAGE>>2];

   status = NFB_ReadPhysicalPageWithSpare_NoTT(block, page, pBuf, spare);
   
   if(status == ERROR_NFB_SUCCESS || status == ERROR_NFB_ECC_CORRECTED)
   {
      return FTL_SUCCESS;
   }
   
#endif /* __NFI_SHARED_DRV__ */
   
   
   return NFB_ERR_2_FTL_ERR(status);
}

FTL_STATUS_CODE FTL_CheckGoodBlockBL(kal_uint32 block, FTL_OptParam *opt_param)
{

#ifdef __NFI_SHARED_DRV__ 

   if( g_pNfiFuncTbl->m_is_bad_block(block) != FALSE)
   {
      return FTL_ERROR_BAD_BLOCK;      
   }
   else
   {
      return FTL_SUCCESS;
   }

#else

   if( NFB_CheckGoodBlock_NoTT(block)==0 )
   {
      return FTL_SUCCESS;
   }
   else
   {
      return FTL_ERROR_BAD_BLOCK;
   }

#endif /* __NFI_SHARED_DRV__ */

}



FTL_FuncTbl ftlFuncTblBl =
{
   FTL_InitBL,
   FTL_DeInitBL,
   FTL_ReadPageBL,
   NULL,
   NULL,
   FTL_CheckGoodBlockBL,
   NULL,
   NULL,
   FTL_GetBlockSize,
   FTL_GetPageSize,
   NULL,
   NULL
};

#endif /* __MINI_BOOTLOADER */

#endif /* __SV5_ENABLED__ */

//ExtBootloader starts
#ifdef __EXT_BOOTLOADER__

int NFB_ProgramPhysicalPageWithSpareX(kal_uint32 PhyBlock, kal_uint32 PhyPage, void *Data, void *Spare, kal_bool bDal)
{
#ifdef __UBL_NAND_FULL_DRIVER__
   return NFB_ProgramPhysicalPageWithSpare(PhyBlock, PhyPage, Data, Spare, bDal);
#else
return 0;
#endif
}

int NFB_ErasePhysicalBlockX(kal_uint32 PhyBlock, kal_bool bDal)
{
#ifdef __UBL_NAND_FULL_DRIVER__
   return NFB_ErasePhysicalBlock(PhyBlock, bDal);
#else
   return 0;
#endif
}

FTL_STATUS_CODE FTL_Init(void *pArgv)
{
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_DeInit(void *pArgv)
{
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_ReadPage(kal_uint32 block, kal_uint32 page, kal_uint32 *pBuf, FTL_OptParam *opt_param)
{
   kal_int32 status = NFB_ReadPhysicalPage(block, page, pBuf);
   
   if(status > 0)
   {
      return FTL_SUCCESS;
   }
   return NFB_ERR_2_FTL_ERR(status);
}

FTL_STATUS_CODE FTL_WritePage(kal_uint32 block, kal_uint32 page, kal_uint32 *pBuf, FTL_OptParam *opt_param)
{
#ifdef __UBL_NAND_FULL_DRIVER__   
   kal_int32 status = NFB_ProgramPhysicalPage(block, page, pBuf, KAL_TRUE);
#else
   kal_int32 status = 0;
#endif

   if(status > 0)
   {
      return FTL_SUCCESS;
   }
   return NFB_ERR_2_FTL_ERR(status);   
}

FTL_STATUS_CODE FTL_CheckGoodBlock(kal_uint32 block, FTL_OptParam *opt_param)
{
   kal_uint32 status = NFB_CheckGoodBlock(block);

   if(status == 0)
      return FTL_SUCCESS;
   
   return FTL_ERROR_BAD_BLOCK;
}

FTL_STATUS_CODE FTL_MarkBadBlock(kal_uint32 block, FTL_OptParam *opt_param)
{
#ifdef __UBL_NAND_FULL_DRIVER__
   kal_uint32 status = NFB_MarkBadBlock(block, KAL_TRUE);
#else
   kal_uint32 status = 0;
#endif
   
   return NFB_ERR_2_FTL_ERR(status);   
}

FTL_STATUS_CODE FTL_EraseBlock(kal_uint32 block, FTL_OptParam *opt_param)
{
#ifdef __UBL_NAND_FULL_DRIVER__   
   kal_uint32 status = NFB_ErasePhysicalBlock(block, KAL_TRUE);
#else
   kal_uint32 status = 0;
#endif
   
   return NFB_ERR_2_FTL_ERR(status);   
}

kal_uint32 FTL_GetBlockSize(kal_uint32 block, FTL_OptParam *opt_param)
{
   return BLHeader.pagesPerBlock*BLHeader.NFIinfo.pageSize;
}

kal_uint32 FTL_GetPageSize()
{
   return BLHeader.NFIinfo.pageSize;
}


FTL_FuncTbl ftlFuncTbl =
{
   FTL_Init,
   FTL_DeInit,
   FTL_ReadPage,
   NULL,
   FTL_WritePage,
   FTL_CheckGoodBlock,
   FTL_MarkBadBlock,
   FTL_EraseBlock,
   FTL_GetBlockSize,
   FTL_GetPageSize,
   NULL,
   NULL
};

kal_bool FTL_isPollingMode()
{
   return KAL_FALSE;
}

#endif /* __EXT_BOOTLOADER__ */

#elif defined(__EMMC_BOOTING__)

#include "sd_adap.h"
#define EMMC_ID          MCDEV_SD0
#define EMMC_SECTOR_SIZE 512

kal_uint32 FTL_emmcGetBlockSize(kal_uint32 block,FTL_OptParam *opt_param);
kal_uint32 FTL_emmcGetPageSize();

static kal_bool initialized = KAL_FALSE;

FTL_STATUS_CODE EMMC_ERR_2_FTL_ERR(DRV_STATUS_CODE error)
{
   switch(error)
   {
   case DRV_SUCCESS:  
       return FTL_SUCCESS;
       
   case DRV_READ_FAILURE:
       return FTL_ERROR_READ_FAILURE;
       
   case DRV_WRITE_FAILURE:
       return FTL_ERROR_WRITE_FAILURE;
       
   case DRV_ERASE_FAILURE:
       return FTL_ERROR_ERASE_FAILURE;
       
   case DRV_ECC_CORRECTED:
       return FTL_ERROR_ECC_CORRECTED;

   default:
       return FTL_ERROR_OTHER_ERROR;
   }
   ASSERT(0);   
   return FTL_SUCCESS;
}


FTL_STATUS_CODE FTL_emmcInit(void *pArgv)
{
   DRV_STATUS_CODE status = DRV_SUCCESS;
   
   if(!initialized)
   {
      status = DRV_SD_Init();
      if(status == DRV_SUCCESS)
      {
         status = DRV_SD_MountDevice(EMMC_ID, 0);
         
         if(status == DRV_SUCCESS)
         {
            initialized = KAL_TRUE;
         }	
      }
   }
   
   return EMMC_ERR_2_FTL_ERR(status);
}

FTL_STATUS_CODE FTL_emmcDeInit(void *pArgv)
{
   DRV_STATUS_CODE status = DRV_SUCCESS;
   
   if(initialized)
   {
      status = DRV_SD_DeInit();
      if(status == DRV_SUCCESS)
      {
         initialized = KAL_FALSE;
      }
   }
   return EMMC_ERR_2_FTL_ERR(status);
}

FTL_STATUS_CODE FTL_emmcReadPage(kal_uint32 block, kal_uint32 page, kal_uint32 *pBuf, FTL_OptParam *opt_param)
{
   DRV_STATUS_CODE status;

   kal_uint32 sector = (block * FTL_emmcGetBlockSize(0, NULL))/EMMC_SECTOR_SIZE + (page * FTL_emmcGetPageSize())/EMMC_SECTOR_SIZE;
   
   status = DRV_SD_ReadSectors(EMMC_ID, sector, FTL_emmcGetPageSize()/EMMC_SECTOR_SIZE, pBuf, 0);
   
   return EMMC_ERR_2_FTL_ERR(status);
}

FTL_STATUS_CODE FTL_emmcWritePage(kal_uint32 block, kal_uint32 page, kal_uint32 *pBuf, FTL_OptParam *opt_param)
{
   DRV_STATUS_CODE status;

   kal_uint32 sector = (block * FTL_emmcGetBlockSize(0, NULL))/EMMC_SECTOR_SIZE + (page * FTL_emmcGetPageSize())/EMMC_SECTOR_SIZE;
   
   status = DRV_SD_WriteSectors(EMMC_ID, sector, FTL_emmcGetPageSize()/EMMC_SECTOR_SIZE, pBuf, 0);
   
   return EMMC_ERR_2_FTL_ERR(status);
}

FTL_STATUS_CODE FTL_emmcCheckGoodBlock(kal_uint32 block, FTL_OptParam *opt_param)
{
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_emmcMarkBadBlock(kal_uint32 block, FTL_OptParam *opt_param)
{
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_emmcEraseBlock(kal_uint32 block, FTL_OptParam *opt_param)
{
   DRV_STATUS_CODE status = DRV_SUCCESS;
   kal_uint32 i;
   kal_uint32 sector = (block * FTL_emmcGetBlockSize(0, NULL))/EMMC_SECTOR_SIZE;
   kal_uint32 sectorCount = FTL_emmcGetBlockSize(0, NULL)/EMMC_SECTOR_SIZE;
   static kal_uint32 dummyBuf[FTL_EMMC_PAGE_SIZE>>2];

   memset(dummyBuf, 0xff, sizeof(dummyBuf));
   for(i=0; i<sectorCount && status==DRV_SUCCESS; i+=sizeof(dummyBuf)/EMMC_SECTOR_SIZE)
   {
      status = DRV_SD_WriteSectors(EMMC_ID, sector+i, sizeof(dummyBuf)/EMMC_SECTOR_SIZE, dummyBuf, 0);
   }

   if(status != DRV_SUCCESS)
   {
      return FTL_ERROR_ERASE_FAILURE;
   }
   else
   {
      return FTL_SUCCESS;
   }
}

kal_uint32 FTL_emmcGetBlockSize(kal_uint32 block, FTL_OptParam *opt_param)
{
   return FTL_EMMC_BLOCK_SIZE;
}

kal_uint32 FTL_emmcGetPageSize()
{
   return FTL_EMMC_PAGE_SIZE;
}

FTL_FuncTbl ftlFuncTbl =
{
   FTL_emmcInit,
   FTL_emmcDeInit,
   FTL_emmcReadPage,
   NULL,
   FTL_emmcWritePage,
   FTL_emmcCheckGoodBlock,
   FTL_emmcMarkBadBlock,
   FTL_emmcEraseBlock,
   FTL_emmcGetBlockSize,
   FTL_emmcGetPageSize,
   NULL,
   NULL
};

kal_bool FTL_isPollingMode()
{
   return KAL_FALSE;
}

#elif defined(__MD_BOOTLOADER__)


FTL_STATUS_CODE FTL_Init(void *pArgv)
{
   ASSERT(0);
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_DeInit(void *pArgv)
{
   ASSERT(0);
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_ReadPage(kal_uint32 block, kal_uint32 page, kal_uint32 *pBuf, FTL_OptParam *opt_param)
{
   ASSERT(0);
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_WritePage(kal_uint32 block, kal_uint32 page, kal_uint32 *pBuf, FTL_OptParam *opt_param)
{
   ASSERT(0);
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_CheckGoodBlock(kal_uint32 block, FTL_OptParam *opt_param)
{
   ASSERT(0);
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_MarkBadBlock(kal_uint32 block, FTL_OptParam *opt_param)
{
   ASSERT(0);
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_EraseBlock(kal_uint32 block, FTL_OptParam *opt_param)
{
   ASSERT(0);
   return FTL_SUCCESS;
}

kal_uint32 FTL_GetBlockSize(kal_uint32 block, FTL_OptParam *opt_param)
{
   ASSERT(0);
   return 0;
}

kal_uint32 FTL_GetPageSize()
{
   ASSERT(0);
   return 0;
}

kal_uint32 FTL_AddrToBlockPage(kal_uint32 addr, kal_uint32 *pBlock, kal_uint32 *pPage, FTL_OptParam *opt_param)
{
   ASSERT(0);
   return FTL_SUCCESS;
}

kal_uint32 FTL_BlockPageToAddr(kal_uint32 Block, kal_uint32 Page, kal_uint32 *addr, FTL_OptParam *opt_param)
{
   ASSERT(0);
   return FTL_SUCCESS;
}

FTL_FuncTbl ftlFuncTbl =
{
   FTL_Init,
   FTL_DeInit,
   FTL_ReadPage,
   NULL,
   FTL_WritePage,
   FTL_CheckGoodBlock,
   FTL_MarkBadBlock,
   FTL_EraseBlock,
   FTL_GetBlockSize,
   FTL_GetPageSize,
   FTL_AddrToBlockPage,
   FTL_BlockPageToAddr
};

kal_bool FTL_isPollingMode()
{
   return KAL_FALSE;
}

#else

#include <flash_disk.h>

FTL_STATUS_CODE NOR_ERR_2_FTL_ERR(kal_uint32 error)
{
   switch(error)
   {
   case ERROR_NOR_SUCCESS:  
       return FTL_SUCCESS;
       
   case ERROR_NOR_READ:
       return FTL_ERROR_READ_FAILURE;
       
   case ERROR_NOR_PROGRAM:
       return FTL_ERROR_WRITE_FAILURE;
       
   case ERROR_NOR_ERASE:
       return FTL_ERROR_ERASE_FAILURE;

   }
   ASSERT(0);
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_Init(void *pArgv)
{
   kal_int32 status;
   static kal_bool initialized = KAL_FALSE;

   if(initialized)
   {
      return FTL_SUCCESS;
   }
   
   status = NOR_init();
   initialized = KAL_TRUE;
   
   return NOR_ERR_2_FTL_ERR(status);
}

FTL_STATUS_CODE FTL_DeInit(void *pArgv)
{
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_ReadPage(kal_uint32 block, kal_uint32 page, kal_uint32 *pBuf, FTL_OptParam *opt_param)
{
   kal_int32 status;

   status = NOR_ReadPhysicalPage(block, page, (kal_uint8*)pBuf);
   
   return NOR_ERR_2_FTL_ERR(status);
 }

FTL_STATUS_CODE FTL_WritePage(kal_uint32 block, kal_uint32 page, kal_uint32 *pBuf, FTL_OptParam *opt_param)
{
   kal_int32 status;

#if defined(__UBL_NOR_FULL_DRIVER__) && defined(__EXT_BOOTLOADER__)

   status = NOR_ProgramPhysicalPage(block, page, (kal_uint8*)pBuf);
   
   return NOR_ERR_2_FTL_ERR(status);

#else

   return FTL_ERROR_WRITE_FAILURE;

#endif   

 }

FTL_STATUS_CODE FTL_CheckGoodBlock(kal_uint32 block, FTL_OptParam *opt_param)
{
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_MarkBadBlock(kal_uint32 block, FTL_OptParam *opt_param)
{
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_EraseBlock(kal_uint32 block, FTL_OptParam *opt_param)
{
   kal_int32 status;
   
#if defined(__UBL_NOR_FULL_DRIVER__) && defined(__EXT_BOOTLOADER__)

   status = NOR_ErasePhysicalBlock(block);
   
   return NOR_ERR_2_FTL_ERR(status);

#else

   return FTL_ERROR_ERASE_FAILURE;

#endif   

}

kal_uint32 FTL_GetBlockSize(kal_uint32 block, FTL_OptParam *opt_param)
{
   return NOR_BlockSize(block);
}

kal_uint32 FTL_GetPageSize()
{
#ifdef __SERIAL_FLASH_EN__
   return 512;
#else
   return 2048;
#endif 
}

kal_uint32 FTL_AddrToBlockPage(kal_uint32 addr, kal_uint32 *pBlock, kal_uint32 *pPage, FTL_OptParam *opt_param)
{
   kal_int32 status;
   kal_uint32 offset;
   
   ASSERT(pBlock);

   status = NOR_Addr2BlockIndexOffset(addr, pBlock, &offset);

   if(status == ERROR_NOR_SUCCESS)
   {
      *pPage = offset / FTL_GetPageSize();
      return FTL_SUCCESS;
   }

   return NOR_ERR_2_FTL_ERR(status);
}

kal_uint32 FTL_BlockPageToAddr(kal_uint32 Block, kal_uint32 Page, kal_uint32 *addr, FTL_OptParam *opt_param)
{
   kal_uint32 offset;

   ASSERT(addr);

   offset = Page * FTL_GetPageSize();

   return NOR_BlockIndexOffset2Addr(Block, offset, addr);
}


FTL_FuncTbl ftlFuncTbl =
{
   FTL_Init,
   FTL_DeInit,
   FTL_ReadPage,
   NULL,
   FTL_WritePage,
   FTL_CheckGoodBlock,
   FTL_MarkBadBlock,
   FTL_EraseBlock,
   FTL_GetBlockSize,
   FTL_GetPageSize, 
   FTL_AddrToBlockPage,
   FTL_BlockPageToAddr
};

kal_bool FTL_isPollingMode()
{
   return KAL_FALSE;
}

#endif

