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
 *
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
#include "reg_base.h"

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
#include "fota_error.h"
#include "NAND_DAL.h"

FTL_STATUS_CODE inline NFB_ERR_2_FTL_ERR(kal_uint32 error)
{
   switch(error)
   {
   case ERROR_NFB_SUCCESS:  
   case ERROR_NFB_ECC_CORRECTED:
       return FTL_SUCCESS;
       
   case ERROR_NFB_READ:
       return FTL_ERROR_READ_FAILURE;
       
   case ERROR_NFB_PROGRAM:
       return FTL_ERROR_WRITE_FAILURE;
       
   case ERROR_NFB_ERASE:
       return FTL_ERROR_ERASE_FAILURE;
       
   case ERROR_NFB_BAD_BLOCK:
       return FTL_ERROR_BAD_BLOCK;
       
   }
   return FTL_ERROR_OTHER_ERROR;
}

FTL_STATUS_CODE FTL_Init(void *pArgv)
{
   DAL_init();
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
   kal_uint32 status = NFB_CheckGoodBlock2(block, KAL_TRUE);
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
   return DAL_GetBlockSize();
}

kal_uint32 FTL_GetPageSize()
{
   return DAL_GetPageSize();
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

#include "drv_comm.h"

#define SF_BLOCK_SIZE (64*1024)
#define SF_PAGE_SIZE  (512)
#define FLASH_BASE_ADDR     (BASE_ADDR_SPI)

kal_bool setDriving = KAL_FALSE;
#if (defined(__USB_FW_DL_SUPPORT__) && !defined(__EXT_BOOTLOADER__))
#include "flash_disk.h"
kal_uint32 SPI_FLASH_SIZE = 0;
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
#endif
FTL_STATUS_CODE FTL_Init(void *pArgv)
{
   if(KAL_FALSE == setDriving)
   {
   	DRV_WriteReg32(0xBF8A0124, 0xC00);
	DRV_WriteReg32(0xBF8A0128, 0xC00);
	setDriving = KAL_TRUE;
   }
   #if (defined(__USB_FW_DL_SUPPORT__) && !defined(__EXT_BOOTLOADER__))
   kal_int32 status;
   static kal_bool initialized = KAL_FALSE;

   if(initialized)
   {
   return FTL_SUCCESS;
}

   status = NOR_init();
   initialized = KAL_TRUE;
   
   return NOR_ERR_2_FTL_ERR(status);
   
   #else//if defined(__USB_FW_DL_SUPPORT__)
   return FTL_SUCCESS;
   #endif//if defined(__USB_FW_DL_SUPPORT__)
}

FTL_STATUS_CODE FTL_DeInit(void *pArgv)
{
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_ReadPage(kal_uint32 block, kal_uint32 page, kal_uint32 *pBuf, FTL_OptParam *opt_param)
{
   memcpy(pBuf, (const void*)((block*SF_BLOCK_SIZE+page*SF_PAGE_SIZE)|FLASH_BASE_ADDR), SF_PAGE_SIZE);
   return FTL_SUCCESS;
}

FTL_STATUS_CODE FTL_WritePage(kal_uint32 block, kal_uint32 page, kal_uint32 *pBuf, FTL_OptParam *opt_param)
{
   #if (defined(__USB_FW_DL_SUPPORT__) && !defined(__EXT_BOOTLOADER__))
   kal_int32 status;
   
   status = NOR_ProgramPhysicalPage(block, page, (kal_uint8*)pBuf);
   
   return NOR_ERR_2_FTL_ERR(status);
   #else//if defined(__USB_FW_DL_SUPPORT__)
   ASSERT(0);
   return FTL_SUCCESS;
   #endif//if defined(__USB_FW_DL_SUPPORT__)
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
   #if (defined(__USB_FW_DL_SUPPORT__) && !defined(__EXT_BOOTLOADER__))
   kal_int32 status;
   
   status = NOR_ErasePhysicalBlock(block);
   
   return NOR_ERR_2_FTL_ERR(status);
   #else//if defined(__USB_FW_DL_SUPPORT__)
   return FTL_SUCCESS;
   #endif//if defined(__USB_FW_DL_SUPPORT__)
}

kal_uint32 FTL_GetBlockSize(kal_uint32 block, FTL_OptParam *opt_param)
{
   #if (defined(__USB_FW_DL_SUPPORT__) && !defined(__EXT_BOOTLOADER__))
   return NOR_BlockSize(block);
   #else//if defined(__USB_FW_DL_SUPPORT__)
   return SF_BLOCK_SIZE;
   #endif//if defined(__USB_FW_DL_SUPPORT__)
}

kal_uint32 FTL_GetPageSize()
{
   #if defined(__USB_FW_DL_SUPPORT__)
   
   #ifdef __SERIAL_FLASH_EN__
   return 512;
   #else
   return 2048;
   #endif
   
   #else//if defined(__USB_FW_DL_SUPPORT__)
   return SF_PAGE_SIZE;
   #endif//if defined(__USB_FW_DL_SUPPORT__)
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
   NULL,
   NULL
};

#endif

