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
 *   bl_ImageLoader.c
 *
 * Project:
 * --------
 *   NFB - Bootloader
 *
 * Description:
 * ------------
 *   Reponsible for loading image.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "kal_general_types.h" 

#if defined(__FOTA_DM__)
#include "fue_err.h"
#include "fota.h"
#include "custom_fota.h"
#include "custom_fota.h"
#include "custom_img_config.h"
#include "SSF_fue_support.h"
#include "fue.h"
#endif /* __FOTA_DM__ */

#include "bl_setting.h"
#include "bl_INIT.H"
#include "bl_FOTA.h"
#include "bl_nfi_wrapper.h"
#include "bl_loader.h"
#include "bl_sectiondef.h"

#include <string.h>
#include "SST_secure.h"

#include "bl_common.h"

#include "br_time_stamp.h"
#ifdef __TIME_STAMP__
#include "br_time_stamp_cb.h"
#include "bl_time_stamp_id.h"
#endif

#if defined(__EXT_BL_UPDATE__)
#include "custom_img_config.h"
#endif

#include "SSF_ROMInfo_type.h"

#ifndef __SV5_ENABLED__ 


/*************************************************************************
 * Global variables definition
*************************************************************************/
#define MAX_BOOTLOADER_SIZE 1024*1024

#if defined(_NAND_FLASH_BOOTING_)

#define TOTAL_BIN_PACK   20

const kal_char exblID[] = "EXT_BOOTLOADER!";

const kal_char   SUPER_BLOCK_PATTERN[]             = "MTK_FOTA_SUPER_BLOCK_HEADER_V01";
const kal_uint32 IMAGE_LIST_BLOCK_TAIL_PATTERN[]   = MTK_ILB_TAIL_TAG;
const kal_uint32 IMAGE_LIST_BLOCK_TEMP_PATTERN[]   = MTK_ILB_TEMP_TAG;
const kal_uint32 IMAGE_LIST_BLOCK_BACKUP_PATTERN[] = MTK_ILB_BAK_TAG;
const kal_uint32 IMAGE_LIST_BLOCK_FOTA_PATTERN[]   = MTK_ILB_FOTA_TAG;
const kal_uint32 IMAGE_LIST_BLOCK_DLPKG_PATTERN[]  = MTK_ILB_DLPKG_TAG;

/* FOTA on ENFB */
const kal_char IMAGE_ID_FOTA[]  = "FOTA";
const kal_char IMAGE_ID_ENFB[]  = "ENFB";
const kal_char IMAGE_ID_MTK[]   = "@MTK";
const kal_char IMAGE_ID_VERNO[] = "V01";

EXT_BOOTL_HEADER EBLHeader;

#endif /* _NAND_FLASH_BOOTING_ */

#if defined(__EXT_BL_UPDATE__)
const kal_uint32 EXT_BL_END_MARK[] = MTK_EXT_BL_END_MARK;
#endif /* __EXT_BL_UPDATE__ */

const kal_char BL_TAIL_PATTERN[] = "MTK_BL_ROMINFO_TAIL_V";
kal_uint32 g_ExtBootloaderLen = 0;

/*************************************************************************
 * Macro and const definition
 *************************************************************************/
#define IMGBLK_LOAD_ADDR (SYSRAM_BASE+0x1000)

/*************************************************************************
 * External reference definition
 *************************************************************************/
extern kal_bool bl_secure_nfb_usbdl;

extern const kal_uint32 CHECKSUM_SEED;
extern _RET_CODE NFI_PhyPageRead(kal_uint32 *destination, kal_uint32 *parity, kal_uint32 length,
                       kal_uint16 addr_no, kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize,
                       kal_bool ECC, kal_bool continous);

extern BL_Info_Wrapper_st BL_Shared_info;

extern const kal_char blID1[];
extern const kal_char blID2[];
extern kal_uint32 g_bootupStatus;
 
/*************************************************************************
 * Forward declaration
 *************************************************************************/
kal_int32 RelocateExtBootloader(kal_uint32 srcAddr, kal_uint32 srcLen, kal_uint32 searchAddr, kal_uint32 *pExtBootloaderLen);
kal_bool CheckExtBLChecksum(kal_uint32 eblAddr, kal_uint32 eblLen);


/*************************************************************************
 * Code region
 *************************************************************************/

#if defined(_NAND_FLASH_BOOTING_)
/**********************************************************
Description : Get the item in image list
Input       : None
Output      : None
***********************************************************/
Nand_ImageInfo_S *GetImageInfo(kal_uint32 n)
{
   if (n < 10)
      return &BL_Shared_info.m_bl_image_list.m_image[n];
   else
      return &BL_Shared_info.m_bl_image_list.m_image_ext[n-10];
}

/**********************************************************
Description : Get the first block next to bootloader region
Input       : None
Output      : None
***********************************************************/

kal_uint32 GetMainRegionStartBlock()
{
   return EBLHeader.lastLogicalBlock+1;
}

/**********************************************************
Description : Procedure to read NAND pages with logical addresses
Input       : None
Output      : None
***********************************************************/

kal_bool ReadPage(kal_uint32 *dest, kal_uint32 length, kal_uint32 pageNo, kal_uint32 type)
{
   _RET_CODE status;
   kal_uint32 spare[64>>2];
   kal_uint32 addr1 = pageNo << PAGE_SHIFT;
   kal_uint16 addr2 = 0;

   BL_DEBUG_PRINT("ReadPage dest=%x, pNo=%x, len=%d, type=%d\n\r", dest, pageNo, length, type);

   if ( BLHeader.NFIinfo.addressCycle>4 )
   {
      if ( pageNo&0xffff0000 )
         addr2 = (kal_uint32)(pageNo >> PAGE_SHIFT);
   }

#ifdef BIT_ERROR_TEST
   EmulateBitError(dest, spare, BLHeader.NFIinfo.addressCycle, addr1, addr2, BLHeader.NFIinfo.pageSize);
#endif

#ifdef BL_ECC_ENABLE

#ifdef __EXT_BOOTLOADER__
   if ( type == LOGICAL_BLOCK_ADDRESS )
   {
      status = NFI_PageRead(dest, spare, BLHeader.NFIinfo.pageSize, \
                            BLHeader.NFIinfo.addressCycle, addr1, addr2, \
                            BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_FALSE);
   }
   else
#endif /* __EXT_BOOTLOADER__ */  
   {
      status = NFI_PhyPageRead(dest, spare, BLHeader.NFIinfo.pageSize, \
                            BLHeader.NFIinfo.addressCycle, addr1, addr2, \
                            BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_FALSE);
   }

   if ( (status!=NFI_SUCCESS) && (status!=NFI_ECC_1BIT_CORRECT))
      _errorExit(status, pageNo, dest);
   
   #if (!defined (__NFI_VERSION2__) && !defined (__NFI_VERSION3__) && !defined(__NFI_VERSION3_1__))
   status = NFI_ParityCheck(dest, spare, BLHeader.NFIinfo.addressCycle, addr1, addr2, \
                            BLHeader.NFIinfo.pageSize, BLHeader.NFIinfo.IOInterface, \
                            BLHeader.NFIinfo.pageSize*BLHeader.pagesPerBlock);                          

   if (status == NFI_ECC_2BITS_ERR)
      return KAL_FALSE;
   
   if ( status<0)
      _errorExit(status, pageNo, dest);
   #endif
#else

#ifdef __EXT_BOOTLOADER__
   if ( type == LOGICAL_BLOCK_ADDRESS )
   {
      status = NFI_PageRead(dest, spare, BLHeader.NFIinfo.pageSize, \
                            BLHeader.NFIinfo.addressCycle, addr1, addr2, \
                            BLHeader.NFIinfo.pageSize, KAL_FALSE, KAL_FALSE);
   }
   else
#endif /* __EXT_BOOTLOADER__ */
   {
      status = NFI_PhyPageRead(dest, spare, BLHeader.NFIinfo.pageSize, \
                            BLHeader.NFIinfo.addressCycle, addr1, addr2, \
                            BLHeader.NFIinfo.pageSize, KAL_FALSE, KAL_FALSE);
   }

   if (status == NFI_ECC_2BITS_ERR)
      return KAL_FALSE;
   
   if ( status!=NFI_SUCCESS )
      _errorExit(status, pageNo, dest);
#endif /* BL_ECC_ENABLE */

   return KAL_TRUE;

}



/**********************************************************
Description : To remove some information before regionInit, or it will be destroyed
Input       : None
Output      : None
***********************************************************/

void PreserveExtBootloaderHeader()
{
   //Search and copy the EXT_Bootloader header to a temp space, or it may be destroyed in Region Init
   extern kal_uint32 Load$$DUMMY_END$$Base;
   extern kal_uint32 Image$$DUMMY_END$$Length;   

   //Search from the end of bootloader
   kal_uint32 *p = (kal_uint32*)((kal_uint32)(&Load$$DUMMY_END$$Base) + (kal_uint32)(&Image$$DUMMY_END$$Length));
   kal_uint32 *end = p + (512>>2);

   kal_uint32 *pEBLHAddr = ((kal_uint32*)BOOTLOADER_HEADER_ADDRESS) + (sizeof(BOOTL_HEADER)>>2);
   
   for (; p<end; p++)
   {
      if (*(p+0) == *((kal_uint32*)exblID+0) &&
          *(p+1) == *((kal_uint32*)exblID+1) &&
          *(p+2) == *((kal_uint32*)exblID+2) &&
          *(p+3) == *((kal_uint32*)exblID+3) )
      {
         end = p + (sizeof(EXT_BOOTL_HEADER)>>2);
         for (; p<end; p++, pEBLHAddr++)
         {
            *pEBLHAddr = *p;
         }
         return;
      }
   }

   //Not found
   *pEBLHAddr = 0x00587858;   //Debug tag
}



kal_uint32 LoadExtBootloaderBody(kal_uint32 *pBlLoadBase, EXT_BOOTL_LINKADDR *pLinkAddr, kal_uint32 linkAddrCount, kal_uint32 *pLen)
{
   kal_uint32 i;
   kal_uint32 curPosition; /* in terms of pages */
   kal_uint32 start_addr = INVALID_START_ADDR;
   kal_uint32 len = MAX_BOOTLOADER_SIZE;   
   kal_uint32 pagePerBlockShift = (BLHeader.blockShift - PAGE_SHIFT);
   kal_uint32 read;
   
   for (read=0, i=0; i<linkAddrCount && pLinkAddr[i].blockNo && read<len; i++)
   {
      kal_uint32 toRead;
      kal_uint32 j = BLHeader.pagesPerBlock;
      
      WacthDogRestart();

      if(NFB_CheckGoodBlock_NoTT(&BLHeader.NFIinfo, pLinkAddr[i].blockNo) != 0)
      {
         BL_PRINT(LOG_INFO, "Bad block found @ %d\n\r", pLinkAddr[i].blockNo);
         continue;
      }

      curPosition = (pLinkAddr[i].blockNo << pagePerBlockShift);

      while(j && read<len)
      {
         if (len-read > BLHeader.NFIinfo.pageSize)
         {
            toRead = BLHeader.NFIinfo.pageSize;
         }
         else
         {
            toRead = len-read;
         }

         if(ReadPage(pBlLoadBase+read/4, toRead, curPosition, PHYSICAL_BLOCK_ADDRESS) == KAL_FALSE)
         {
            BL_PRINT(LOG_ERROR, "Load ExtBootloader failed, flash error?\n\r");
            return INVALID_START_ADDR;
         }

         if(start_addr == INVALID_START_ADDR)
         {
            start_addr = RelocateExtBootloader((kal_uint32)pBlLoadBase, read+toRead, read, &len);
            
            if(start_addr != INVALID_START_ADDR)
            {
               pBlLoadBase = (kal_uint32*)start_addr;
            }
         }

         read += toRead;

         j--;
         curPosition++;
      }
   }

   if (read != len)
   {
      if(start_addr == INVALID_START_ADDR)
      {
         BL_PRINT(LOG_ERROR, "BL_ROM_INFO not found yet\n\r");
      }
      
      BL_PRINT(LOG_ERROR, "Failed when load ExtBootloader!, blAddr=%x, blLen=%d, read=%d\n\r", start_addr, len, read);
      
      return INVALID_START_ADDR;
   }  

   if(pLen)
   {
      *pLen = read;
   }
   
   return start_addr;
}

#if defined(__EXT_BL_UPDATE__)

kal_bool FindAndCompareExtBootloaderEndMark(EXT_BOOTL_LINKADDR *pExtBlLinkAddr)
{
   kal_int32 i;
   for(i=0; i<sizeof(EBLHeader.linkAddr)/sizeof(*EBLHeader.linkAddr) && pExtBlLinkAddr[i].blockNo; i++)
   {
      ;
   }

   for(i--; i>=0; i--)
   {
      if(NFB_CheckGoodBlock_NoTT(&BLHeader.NFIinfo, pExtBlLinkAddr[i].blockNo) == 0)
      {
         //Read the last page and check the mark
         kal_uint32 pagePerBlockShift = (BLHeader.blockShift - PAGE_SHIFT);
         kal_uint32 curPosition = ((pExtBlLinkAddr[i].blockNo+1) << pagePerBlockShift)-1;

         if(ReadPage((kal_uint32*)IMGBLK_LOAD_ADDR, BLHeader.NFIinfo.pageSize, curPosition, PHYSICAL_BLOCK_ADDRESS) == KAL_TRUE)
         {
            if(CompareEndMarkWithError((kal_uint32*)(IMGBLK_LOAD_ADDR+BLHeader.NFIinfo.pageSize-sizeof(EXT_BL_END_MARK)), EXT_BL_END_MARK, BIT_ERROR_THRESHOLD) == KAL_TRUE)
            {
               return KAL_TRUE;
            }
         }
      }
   }

   return KAL_FALSE;
}
#endif /* __EXT_BL_UPDATE__ */

/**********************************************************
Description : Find and load Ext Bootloader to external RAM
Input       : None
Output      : None
***********************************************************/

kal_int32 LoadExtBootloader(void)
{
   kal_uint32 i;
   kal_uint32 start_addr = INVALID_START_ADDR;
   kal_uint32 *ptr_source;
   kal_uint32 *ptr_dest;
   kal_uint32 len;

   TS_BEGIN(TSID_BL_LOAD_EXT_BOOTLOADER);

   BL_DEBUG_PRINT("LoadExBootloader %s\n\r", BootLDVerno);
  
   // Copy the Bootloader Header from predefined space
   ptr_source = (kal_uint32 *)(BOOTLOADER_HEADER_ADDRESS);
   ptr_dest = (kal_uint32 *)&BLHeader;
   for (i=0; i<(sizeof(BLHeader)>>2); i++)  // Need to make sure BLHeader is 4 bytes multiple.
      *ptr_dest++ = *ptr_source++;

   // Copy the EXT Bootloader Header from backup space
   ptr_dest = (kal_uint32 *)&EBLHeader;
   for (i=0; i<(sizeof(EBLHeader)>>2); i++)
      *ptr_dest++ = *ptr_source++;

   if ( strcmp(blID1, BLHeader.ID1) || strcmp(blID2, BLHeader.ID2) )
   {
      BL_PRINT(LOG_ERROR, "\nBootloader Header ID incorrect, quit!\n\r");
      BL_PRINT(LOG_ERROR, "\nID1(default %s) = %s\n\r", blID1, BLHeader.ID1);
      BL_PRINT(LOG_ERROR, "\nID2(default %s) = %s\n\n\n\r", blID2, BLHeader.ID2);
      return INVALID_START_ADDR;
   }

#if defined(__NFI_VERSION3__) || defined(__NFI_VERSION3_1__)
	{
	    NFI_SUBMENU   sub_menu;
	    kal_uint32    sec_num = 0;
	
     /* configure NFI according to extracted bootloader header */
     sec_num = BLHeader.NFIinfo.pageSize>>NAND_SECTOR_SHIFT;
     sub_menu.spareSize = BLHeader.spareSize/(sec_num ? sec_num : 1);
     sub_menu.blockSize = BLHeader.pagesPerBlock;
     NFI_Config(&BLHeader.NFIinfo, &sub_menu);   
	}
   
#endif
   
   if (strcmp(EBLHeader.ID, exblID) == 0)
   {
      kal_uint32 *pBlLoadBase;
      EXT_BOOTL_LINKADDR *pExtBlLinkAddr = EBLHeader.linkAddr;

      BL_DEBUG_PRINT("ExtBootloader Info:\n\r");
      BL_DEBUG_PRINT(" ID=%s\n\r version=%s\n\r", EBLHeader.ID, EBLHeader.version);

#if defined(__EBL_UPDATE_TOOL_SUPPORT_NAND__)

      if(memcmp(EBLHeader.version, "V006", 4) != 0)
      {
         BL_PRINT(LOG_ERROR, "EBL version mismatch(%d), possible old tool used?\r\n", BLHeader.version[3]);
         return INVALID_START_ADDR;
      }
   
#endif

      //Image list and Ex bootloader header are both ready. Go!
      BL_DEBUG_PRINT("Start loading ExtBootloader...\n\r");
      
      pBlLoadBase = (kal_uint32*)custom_EXTBL_baseaddr();

      //Find ExtBootloader and try to load it  
      for(i=0; i<2; i++)
      {
#if defined(__EXT_BL_UPDATE__)         
         if(FindAndCompareExtBootloaderEndMark(pExtBlLinkAddr) == KAL_FALSE)
         {
            BL_PRINT(LOG_INFO, "End mark is not found\r\n");
         }
         else
#endif /* __EXT_BL_UPDATE__ */
         {
            TS_BEGIN(TSID_BL_LOAD_EXT_BOOTLOADER_BODY);
            
            start_addr = LoadExtBootloaderBody(pBlLoadBase, pExtBlLinkAddr, sizeof(EBLHeader.linkAddr)/sizeof(*EBLHeader.linkAddr), &len);

            TS_END(TSID_BL_LOAD_EXT_BOOTLOADER_BODY);
            TS_INFO(TSID_BL_LOAD_EXT_BOOTLOADER_BODY, 0, read, 0);

            if(start_addr != INVALID_START_ADDR)
            {
               if(CheckExtBLChecksum(start_addr, len) == KAL_TRUE)
               {
#if !defined(__EBL_UPDATE_TOOL_SUPPORT_NAND__)
                  ASSERT(len == EBLHeader.length); //BL_TODO: Sanity test
#endif
               }
               else
               {
                  BL_PRINT(LOG_INFO, "Bad ExtBL checksum\r\n");
                  start_addr = INVALID_START_ADDR;
               }
            }
         }

#if defined(__EXT_BL_UPDATE__)

#ifdef __EBL_UPDATE_TOOL_SUPPORT_NAND__
         if(start_addr != INVALID_START_ADDR)
         {
            g_extBlUpdateInfo.m_current_bl          = (i==0) ? E_EXTBL_PRIMARY_REGION : E_EXTBL_BACKUP_REGION;
            g_extBlUpdateInfo.m_current_bl_size     = len;
            g_extBlUpdateInfo.m_ext_bl_addr         = EBLHeader.linkAddr[0].blockNo*BLOCK_SIZE;
            g_extBlUpdateInfo.m_ext_bl_max_size     = BL_IMG_MAX_SIZE;
            g_extBlUpdateInfo.m_ext_bl_bak_addr     = EBLHeader.linkAddrBak[0].blockNo*BLOCK_SIZE;
            g_extBlUpdateInfo.m_ext_bl_bak_max_size = BL_IMG_MAX_SIZE;
            break;
         }
         else
         {
            pExtBlLinkAddr = EBLHeader.linkAddrBak;
            BL_PRINT(LOG_INFO, "No valid ExtBl exists at region %d...\r\n", i);
         }
#else
         break;
#endif

#else
         //No need to to further process if ext bootloader is not going to be updated
         break;
#endif
      }
   }
   else
   {
      BL_PRINT(LOG_ERROR, "ExtBootloader Header ID incorrect, quit!\n\r");
      BL_PRINT(LOG_ERROR, "ID(default %s) = %s\n\r", exblID, EBLHeader.ID);
      return INVALID_START_ADDR;      
   }

   TS_END(TSID_BL_LOAD_EXT_BOOTLOADER);

   g_ExtBootloaderLen = len;

   return start_addr;
}


#else

kal_int32 LoadExtBootloader(void)
{
   kal_uint32 extblFlashAddr = custom_EXTBL_baseaddr();
   kal_uint32 extblAddr;
   kal_uint32 eblLen;
   kal_int32 i;

#if !defined(__EXT_BL_UPDATE__)

   extblAddr = RelocateExtBootloader(extblFlashAddr, MAX_BOOTLOADER_SIZE, extblFlashAddr, &eblLen);

#else

   for(i=0; i<2; i++)
   {
      if(CompareEndMarkWithError((kal_uint32*)(extblFlashAddr+BL_IMG_MAX_SIZE-sizeof(EXT_BL_END_MARK)), EXT_BL_END_MARK, BIT_ERROR_THRESHOLD) == KAL_TRUE)
      {
         extblAddr = RelocateExtBootloader(extblFlashAddr, MAX_BOOTLOADER_SIZE, extblFlashAddr, &eblLen);         

         if(extblAddr != INVALID_START_ADDR &&
            CheckExtBLChecksum(extblAddr, eblLen) == KAL_TRUE)
         {
            g_extBlUpdateInfo.m_current_bl      = (i==0) ? E_EXTBL_PRIMARY_REGION : E_EXTBL_BACKUP_REGION;
            g_extBlUpdateInfo.m_current_bl_size = eblLen;
            g_extBlUpdateInfo.m_ext_bl_addr     = extblFlashAddr;
            g_extBlUpdateInfo.m_ext_bl_size     = BL_IMG_MAX_SIZE;
            g_extBlUpdateInfo.m_ext_bl_bak_addr = extblFlashAddr + BL_IMG_MAX_SIZE;
            g_extBlUpdateInfo.m_ext_bl_bak_size = BL_IMG_MAX_SIZE;
            break;
         }
      }

      extblAddr = INVALID_START_ADDR;
      extblFlashAddr += BL_IMG_MAX_SIZE;
      
      BL_PRINT(LOG_INFO, "No valid ExtBl exists at region %d...\r\n", i);
   }

#endif /* __EXT_BL_UPDATE__ */

   g_ExtBootloaderLen = eblLen;

   if(extblAddr == INVALID_START_ADDR)
   {
      BL_PRINT(LOG_ERROR, "Can not find ExtBootloader\r\n");
   }

   return extblAddr;
}

#endif /*_NAND_FLASH_BOOTING_*/


#if defined(__EXT_BL_UPDATE__) || defined(_NAND_FLASH_BOOTING_)

__interndata__ static const kal_uint32 CRC_TBL_LEN = 256;
__interndata__ static kal_uint32 crc_init = 0;
__interndata__ static kal_uint32 crc_table[CRC_TBL_LEN]; /* Table of CRCs of all 8-bit messages. */

__interncode__ static void Build_CRC_TBL(void)
{
    kal_uint32 c;
    kal_int32 n, k;

    for (n = 0; n < CRC_TBL_LEN; n++)
    {

        c = (kal_uint32)n;

        for (k = 0; k < 8; k++)
        {

            if (c & 1)
            {

                c = 0xedb88320L ^ (c >> 1);
            }
            else
            {

                c = c >> 1;
            }
        }

        crc_table[n] = c;
    }
}

__interncode__ static kal_uint32 Update_CRC(kal_uint32 crc, kal_uint8 *buf, kal_uint32 len)
{
    kal_uint32 n, c = crc;
    kal_uint32 *p = (kal_uint32*)buf;
    
    //It's for checking ExtBL's integrity, which should be on 4B boundary
    ASSERT((kal_uint32)buf%4 == 0);
    
    if(!crc_init)
    {
       Build_CRC_TBL();
       crc_init = 702;
    }

    for (n = 0; n < len/4; n++)
    {
       kal_uint32 d = p[n];

       c = crc_table[(c ^ (d >>  0)) & 0xff] ^ (c >> 8);
       c = crc_table[(c ^ (d >>  8)) & 0xff] ^ (c >> 8);
       c = crc_table[(c ^ (d >> 16)) & 0xff] ^ (c >> 8);
       c = crc_table[(c ^ (d >> 24)) & 0xff] ^ (c >> 8);
    }
    
    for (n = 0; n < len%4; n++)
    {
        c = crc_table[(c ^ buf[(len/4)*4+n]) & 0xff] ^ (c >> 8);
    }

    return c;
}


kal_bool CheckExtBLChecksum(kal_uint32 eblAddr, kal_uint32 eblLen)
{
   kal_bool ret = KAL_FALSE;
   
   if(eblAddr != INVALID_START_ADDR)
   {
      //Check the CRC of the body of ExtBootloader
      kal_uint32 bodyLen = eblLen - sizeof(MTK_BL_ROMInfo_Tail_v1_ST);

      MTK_BL_ROMInfo_Tail_v1_ST *pTail = (MTK_BL_ROMInfo_Tail_v1_ST*)(eblAddr + bodyLen);

      if(memcmp(pTail->m_bl_header.m_super_identifier, BL_TAIL_PATTERN, sizeof(BL_TAIL_PATTERN)-1) == 0)
      {
         kal_uint32 calCrc;

         TS_BEGIN(TSID_CALC_EXT_BOOTLOADER_CRC);
            
         calCrc = Update_CRC(288, (kal_uint8*)eblAddr, bodyLen);

         TS_END(TSID_CALC_EXT_BOOTLOADER_CRC);
         TS_INFO(TSID_CALC_EXT_BOOTLOADER_CRC, 0, bodyLen, eblAddr);         

         if(calCrc == pTail->m_bl_tail_info.m_bl_crc)
         {
            ret = KAL_TRUE;
         }
         else
         {
            BL_PRINT(LOG_ERROR, "ExtBl's CRC check failed, crc=%x, calCrc=%x\n\r", pTail->m_bl_tail_info.m_bl_crc, calCrc);
         }
      }
      else
      {
         BL_PRINT(LOG_ERROR, "Cannot find the ExtBL ROM Info tail\n\r");
      }
   }

   return ret;
}

#endif /* __EXT_BL_UPDATE__ || _NAND_FLASH_BOOTING_ */

static kal_uint32 Calc_Chksum(kal_uint32 buff_addr, kal_uint32 buff_len)
{
   kal_uint32   idx       = 0;
   kal_uint32   sum_val   = 0;
   kal_uint32   tmp_val   = 0;
   kal_uint8    *byte_tmp = (kal_uint8 *)&tmp_val;
   kal_uint8    *byte_ptr = 0;
   kal_uint32   *buff_ptr = (kal_uint32 *)buff_addr;

   ASSERT(!(buff_len & 0x03));

   if( ((kal_uint32)buff_ptr) & 0x03 )
   {
      byte_ptr = (kal_uint8 *)buff_ptr;
      for( idx = 0 ; idx < (buff_len>>2) ; idx++)
      {
         byte_tmp[0] = byte_ptr[0];
         byte_tmp[1] = byte_ptr[1];
         byte_tmp[2] = byte_ptr[2];
         byte_tmp[3] = byte_ptr[3];
         sum_val += tmp_val;;
      }
   }
   else
   {
      for( idx = 0 ; idx < (buff_len>>2) ; idx++)
      {
         sum_val += buff_ptr[idx];
      }
   }
   return sum_val;
}

/**********************************************************
Description : Find the marker to know where to move the Ext Bootloader
Input       : Current Ext Bootloader location, read len
Output      : 0xffffffff: No marker found/no relocation done
              other:      The new location of bootloader
***********************************************************/
kal_int32 RelocateExtBootloader(kal_uint32 srcAddr, kal_uint32 srcLen, kal_uint32 searchAddr, kal_uint32 *pExtBootloaderLen)
{
   MTK_BL_ROMInfo_v1_ST *pBlRomInfo = NULL;

   kal_uint32 extblLoadAddr = INVALID_START_ADDR;
   kal_uint32 extblLoadLen  = 0;

   kal_uint32 *p = (kal_uint32*)searchAddr;
   kal_uint32 *pSearchEnd = (kal_uint32*)(srcAddr + srcLen - sizeof(MTK_BL_ROMInfo_v1_ST));

   if(srcLen < sizeof(MTK_BL_ROMInfo_v1_ST))
   {
      return INVALID_START_ADDR;
   }

   //Rewind for the partial read
   if(p  >= (kal_uint32*)(srcAddr + sizeof(MTK_BL_ROMInfo_v1_ST)))
   {
      p -= sizeof(MTK_BL_ROMInfo_v1_ST)/4;
   }
   else
   {
      p = (kal_uint32*)srcAddr;
   }

   for(; p<=pSearchEnd; p++)
   {
      if(memcmp(p, "MTK_BOOT_LOADER_ROMINFO_V01", sizeof("MTK_BOOT_LOADER_ROMINFO_V01")) == 0)
      {
         kal_uint32 calcChecksum = Calc_Chksum((kal_uint32)p, PATTERN_ID_LEN);
         MTK_BL_ROMInfo_v1_ST *pBlRomInfo = (MTK_BL_ROMInfo_v1_ST*)p;

         BL_PRINT(LOG_DEBUG, "Addr=%x, calc=%d, val=%d\n\r", p, calcChecksum, pBlRomInfo->m_bl_header.m_super_id_chksum);
         BL_PRINT(LOG_DEBUG, "length=%d, addr=%x\n\r", pBlRomInfo->m_bl_length, pBlRomInfo->m_bl_load_address);

         if(calcChecksum == pBlRomInfo->m_bl_header.m_super_id_chksum)
         {
            extblLoadAddr = pBlRomInfo->m_bl_load_address;
            extblLoadLen  = pBlRomInfo->m_bl_length + sizeof(MTK_BL_ROMInfo_Tail_v1_ST);
            break;
         }
      }
   }

   if(extblLoadAddr != INVALID_START_ADDR)
   {
      if(extblLoadAddr != srcAddr)
      {
         kal_uint32 copyLen = extblLoadLen<srcLen ? extblLoadLen : srcLen;
         
         /* Make sure the load address is in bank 0 */
         if(extblLoadAddr >= 0x10000000 && extblLoadAddr+copyLen > 0x10000000)
         {
            BL_PRINT(LOG_ERROR, "Invalad load addr %x\n\r", extblLoadAddr);
            return INVALID_START_ADDR;
         }

         memmove((void*)extblLoadAddr, (void*)srcAddr, copyLen);
      }

      if(pExtBootloaderLen)
      {
         *pExtBootloaderLen = extblLoadLen;
      }
   }

   return extblLoadAddr;

}



#ifdef __EXT_BOOTLOADER__

#if defined(_NAND_FLASH_BOOTING_)
/**********************************************************
Description : Recognize the ILB tail by computing their distance
Input       : tags of tail1 and tail2
Output      : return if they are the same
***********************************************************/
kal_bool CompareILBTailTag(const kal_uint32 *pTag1, const kal_uint32 *pTag2)
{
   return CompareEndMarkWithError(pTag1, pTag2, BIT_ERROR_THRESHOLD);
}

/**********************************************************
Description : load image list information.
Input       : start_blk: start block of searching
Output      : Return if Image List or backup is loaded
Assumptions : FUE image is programmed to flash in block aligned manner
***********************************************************/
kal_bool LoadImageListblock(kal_uint32 start_blk)
{
   extern kal_bool g_bootupDisabled;
   extern kal_bool g_usbdlDisabled;
   extern kal_bool g_carddlDisabled;
   extern kal_bool g_enterCarddl;
   
   kal_uint32 blk_idx      = 0;
   kal_uint32 end_blk      = 0;
   kal_uint32 curPosition; /* in terms of pages */
   kal_uint32 addr1;
   kal_uint16 addr2;
   kal_uint32 target_ilb = 0;
   kal_bool   finished = KAL_FALSE;

   kal_uint32 main_ILB_pos   = 0;
   kal_uint32 temp_ILB_pos   = 0;
   kal_uint32 backup_ILB_pos = 0;
   kal_uint32 fota_ILB_pos   = 0;
   kal_uint32 dlpkg_ILB_pos  = 0;

   kal_int32 i;

   TS_BEGIN(TSID_BL_LOAD_ILB_CBR);

   BL_Shared_info.m_bl_ilb_info.m_bl_ilb_start = start_blk;

   end_blk = start_blk + BL_SEARCH_IMAGE_BLOCK_RANGE/BLOCK_SIZE;

   for ( blk_idx = start_blk ; blk_idx < end_blk && finished==KAL_FALSE ; blk_idx++ )
   {
      BL_DEBUG_PRINT("Procressing block %x\n\r", blk_idx);          
      /* Current position in terms of page */
      curPosition = blk_idx << PAGE_PER_BLOCK_SHIFT;
      
      /* Exact position in terms of pages */
      addr1 = curPosition << PAGE_SHIFT;
      addr2 = 0;
      if ( BLHeader.NFIinfo.addressCycle>4 )
      {
         if ( curPosition&0xffff0000 )
           addr2 = (kal_uint32)(curPosition >> PAGE_SHIFT);
      }
      
      if ( GoodBlockChecking(&BLHeader.NFIinfo, addr1, addr2) == KAL_FALSE )
      {
         dbg_print("Bad block found @ %d\n\r", blk_idx);
         continue;
      }

      if ( main_ILB_pos != 0)
      {
         //This is the last block of searching
         finished = KAL_TRUE;
      }

      if ( ReadPage((kal_uint32 *)IMGBLK_LOAD_ADDR, BLHeader.NFIinfo.pageSize, curPosition+ILB_HEADER_PAGE_INDEX, LOGICAL_BLOCK_ADDRESS) == KAL_FALSE)
      {
         BL_DEBUG_PRINT("Empty block found?\n\r", blk_idx);
         continue;
      }

      // detect if it is a image list block
      if (0 != strcmp((kal_char *)IMGBLK_LOAD_ADDR, SUPER_BLOCK_PATTERN))
      {
         //Not image list block
         BL_DEBUG_PRINT("Unrecognized block, skip it\n\r");
         continue;
      }

      //Read the tail
      if ( ReadPage((kal_uint32 *)IMGBLK_LOAD_ADDR, BLHeader.NFIinfo.pageSize, curPosition+BLHeader.pagesPerBlock-1, LOGICAL_BLOCK_ADDRESS) == KAL_FALSE )
      {
         dbg_print("ILB tail read failed\n\r");
         continue;
      }

      if( !main_ILB_pos && CompareILBTailTag((kal_uint32*)IMGBLK_LOAD_ADDR, IMAGE_LIST_BLOCK_TAIL_PATTERN) )
      {
         main_ILB_pos = blk_idx;
         BL_Shared_info.m_bl_ilb_info.m_bl_ilb_blk = blk_idx;

      }
      else if( !temp_ILB_pos && CompareILBTailTag((kal_uint32*)IMGBLK_LOAD_ADDR, IMAGE_LIST_BLOCK_TEMP_PATTERN) )
      {
         temp_ILB_pos = blk_idx;
      }
      else if( !backup_ILB_pos && CompareILBTailTag((kal_uint32*)IMGBLK_LOAD_ADDR, IMAGE_LIST_BLOCK_BACKUP_PATTERN) )      
      {
         backup_ILB_pos = blk_idx;
         BL_Shared_info.m_bl_ilb_info.m_bl_ilb_start = blk_idx+1;
      }
      else if( !fota_ILB_pos && CompareILBTailTag((kal_uint32*)IMGBLK_LOAD_ADDR, IMAGE_LIST_BLOCK_FOTA_PATTERN) )
      {
         fota_ILB_pos = blk_idx;
      }
      else if( !fota_ILB_pos && CompareILBTailTag((kal_uint32*)IMGBLK_LOAD_ADDR, IMAGE_LIST_BLOCK_DLPKG_PATTERN) )
      {
         dlpkg_ILB_pos = blk_idx;
      }
      else
      {
         dbg_print("Corrupted ILB found @ %d\n\r", blk_idx); 
      }
   }

   dbg_print("Main=%x, Tmp=%x, Fota=%x, DL=%x, Bak=%x\n\r", main_ILB_pos, temp_ILB_pos, fota_ILB_pos, dlpkg_ILB_pos, backup_ILB_pos);

   //Little check
   if ( main_ILB_pos && backup_ILB_pos && (backup_ILB_pos > main_ILB_pos))
   {
      return KAL_FALSE;
   }

   //Determine what we can do according what we have
   
   if ( fota_ILB_pos )
   {
      if ( temp_ILB_pos || dlpkg_ILB_pos )
      {
         //Impossible case
         return KAL_FALSE;
      }
      else
      {
         //FOTA is under procressing, suppress USBDL
         target_ilb = fota_ILB_pos;
         g_usbdlDisabled = KAL_TRUE;
         g_carddlDisabled = KAL_TRUE;
      }
   }
   else
   {
      if ( main_ILB_pos && !temp_ILB_pos && !dlpkg_ILB_pos)
      {
         //Normal bootup case
         target_ilb = main_ILB_pos;
      }
      else
      {
         //USBDL/Secure USBDL/CARD Download is under procressing, or after first download BL in factory => suppress Bootup & FOTA
         g_bootupDisabled = KAL_TRUE;
         g_bootupStatus = BL_BOOTUP_FAIL_REASON_UPDATE_IN_PROGRESS;

         if( temp_ILB_pos && dlpkg_ILB_pos)
         {
            //Impossible case
            return KAL_FALSE;
         }

         if( dlpkg_ILB_pos )
         {
            //Card download needs the version info
            target_ilb = dlpkg_ILB_pos;
            g_enterCarddl = KAL_TRUE;
         }
         else if( backup_ILB_pos )
         {
            //Secure USBDL enabled, load image list for it
            target_ilb = temp_ILB_pos ? temp_ILB_pos : backup_ILB_pos;
         }

         if( !main_ILB_pos && !dlpkg_ILB_pos)
         {
            g_carddlDisabled = KAL_TRUE;
         }
      }
      
      if( backup_ILB_pos )
      {
         bl_secure_nfb_usbdl = KAL_TRUE;            
      }
      
   }

   if(target_ilb != 0)
   {
      TS_BEGIN(TSID_BL_READ_FLASH_LAYOUT_INFO);
      
      curPosition = target_ilb << PAGE_PER_BLOCK_SHIFT;

      //Read ImageList from the 3rd page
      if ( ReadPage((kal_uint32 *)IMGBLK_LOAD_ADDR, BLHeader.NFIinfo.pageSize, curPosition+IMAGE_LIST_PAGE_INDEX, LOGICAL_BLOCK_ADDRESS) == KAL_FALSE )
      {
         return KAL_FALSE;
      }
      memcpy(&BL_Shared_info.m_bl_image_list, (kal_uint32*)IMGBLK_LOAD_ADDR, sizeof(BL_Shared_info.m_bl_image_list));
      
      if ( BL_Shared_info.m_bl_image_list.m_image_count > TOTAL_BIN_PACK )
      {
         dbg_print("Illegal Image Header Found (image count=%d), Quit!\n\r", BL_Shared_info.m_bl_image_list.m_image_count);
         return KAL_FALSE;
      }
      
      dbg_print("\nNumber of image segments = %d\n\r", BL_Shared_info.m_bl_image_list.m_image_count);
      for (i=0; i<BL_Shared_info.m_bl_image_list.m_image_count; i++)
      {
         Nand_ImageInfo_S *pImageInfo = GetImageInfo(i);
         dbg_print("..[%d] Image size = %dBytes, start addr. =%x\n\r", i, pImageInfo->m_length, pImageInfo->m_load_addr);
      }

      //Read Version Info from the 4th page
      if ( ReadPage((kal_uint32 *)IMGBLK_LOAD_ADDR, BLHeader.NFIinfo.pageSize, curPosition+VERSION_INFO_PAGE_INDEX, LOGICAL_BLOCK_ADDRESS) == KAL_FALSE )
      {
         return KAL_FALSE;         
      }
      memcpy((kal_uint32*)GetImageInfo(ROMINFO_INDEX)->m_load_addr, (kal_uint32*)IMGBLK_LOAD_ADDR, GetImageInfo(ROMINFO_INDEX)->m_length);

#if defined(__FOTA_DM__)
      //Read Space Info from the 2nd page
      if (ReadPage((kal_uint32 *)IMGBLK_LOAD_ADDR, BLHeader.NFIinfo.pageSize, curPosition+IMAGE_SPACE_PAGE_INDEX, LOGICAL_BLOCK_ADDRESS) == KAL_FALSE )
      {
         return KAL_FALSE;         
      }
      memcpy(&BL_Shared_info.m_bl_image_space, (kal_uint32*)IMGBLK_LOAD_ADDR, sizeof(BL_Shared_info.m_bl_image_space));
#endif /* __FOTA_DM__ */

      if(bl_secure_nfb_usbdl)
      {
         if(ReadPage((kal_uint32 *)IMGBLK_LOAD_ADDR, BLHeader.NFIinfo.pageSize, curPosition+EXTRA_INFO_PAGE_INDEX, LOGICAL_BLOCK_ADDRESS) == KAL_FALSE)
         {
            return KAL_FALSE;         
         }
         memcpy((kal_uint32*)GetImageInfo(0)->m_load_addr, (kal_uint32*)IMGBLK_LOAD_ADDR, GetImageInfo(0)->m_length);
      }

      TS_END(TSID_BL_READ_FLASH_LAYOUT_INFO);
   }

   TS_END(TSID_BL_LOAD_ILB_CBR);

   return KAL_TRUE;
}

/**********************************************************
Description : MultiPageReading
Input       : None
Output      : None
***********************************************************/
static kal_uint32 MultiPageReading(kal_uint8 index, kal_uint32 startPage)
{
   _RET_CODE   status;
   kal_uint32  *ptr;
   kal_int32   length;
   kal_uint32  blockNo, maskI;
   kal_uint32  curPosition; /* in terms of pages */
   kal_uint32  addr1;
   kal_uint16  addr2;   
   kal_uint32  spare[64>>2];
   kal_uint32  offset = 0;
   Nand_ImageInfo_S *pImageInfo = GetImageInfo(index);
   
   TS_BEGIN(TSID_BL_MULTIPLE_PAGE_READ);
   
   blockNo = pImageInfo->m_start_block;
   
   maskI = (0xffffffff >> (32-(BLHeader.blockShift - PAGE_SHIFT)));
   /* Current position in terms of page */
   curPosition = (blockNo << (BLHeader.blockShift - PAGE_SHIFT)) + startPage;

   if(pImageInfo->m_reserved && pImageInfo->m_reserved != FFBR_ID_IMAGEHEADER)
   {
      curPosition += (pImageInfo->m_reserved / BLHeader.NFIinfo.pageSize);
      offset = pImageInfo->m_reserved % BLHeader.NFIinfo.pageSize;
   }

   length = pImageInfo->m_length;   
   ptr = (kal_uint32 *)pImageInfo->m_load_addr;   
      
   TS_INFO(TSID_BL_MULTIPLE_PAGE_READ, index, length, (kal_uint32)ptr);
   
   /* Exact position in terms of pages */
   addr1 = curPosition << PAGE_SHIFT;
   addr2 = 0;
   if ( BLHeader.NFIinfo.addressCycle>4 )
   {
      if ( curPosition&0xffff0000 )
         addr2 = (kal_uint32)(curPosition >> PAGE_SHIFT);
   }
   
   WacthDogRestart();
   while ( length>0 )
   {

#ifdef BIT_ERROR_TEST
      EmulateBitError((kal_uint32 *)ptr, (kal_uint32 *)&spare[0], 
      BLHeader.NFIinfo.addressCycle, addr1, addr2, BLHeader.NFIinfo.pageSize);
#endif

#ifdef BL_ECC_ENABLE     
      status = NFI_PageRead(ptr, &spare[0], BLHeader.NFIinfo.pageSize, \
                            BLHeader.NFIinfo.addressCycle, addr1, addr2, \
                            BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_FALSE);
      if ( (status!=NFI_SUCCESS)&& (status!=NFI_ECC_1BIT_CORRECT))
         _errorExit(status, curPosition, ptr);
     #if (!defined (__NFI_VERSION2__) && !defined (__NFI_VERSION3__) && !defined(__NFI_VERSION3_1__))
      status = NFI_ParityCheck(ptr, &spare[0], BLHeader.NFIinfo.addressCycle, addr1, addr2, \
                               BLHeader.NFIinfo.pageSize, BLHeader.NFIinfo.IOInterface, \
                               BLHeader.NFIinfo.pageSize*BLHeader.pagesPerBlock);                          
      if ( status<0 )
         _errorExit(status, curPosition, ptr);
      #endif
#else
      status = NFI_PageRead(ptr, &spare[0], BLHeader.NFIinfo.pageSize, \
                            BLHeader.NFIinfo.addressCycle, addr1, addr2, \
                            BLHeader.NFIinfo.pageSize, KAL_FALSE, KAL_FALSE);
      if ( status!=NFI_SUCCESS )
         _errorExit(status, curPosition, ptr);
#endif /* BL_ECC_ENABLE */     
         
      if(offset)
      {
         memmove((kal_uint8 *)ptr, (kal_uint8 *)ptr+offset, BLHeader.NFIinfo.pageSize-offset);
         length -= (BLHeader.NFIinfo.pageSize - offset);
         offset = 0;
         ptr = (kal_uint32 *)((kal_uint32)ptr + BLHeader.NFIinfo.pageSize - offset);
      }
      else
      {
         ptr = (kal_uint32 *)((kal_uint32)ptr + BLHeader.NFIinfo.pageSize);
         length -= BLHeader.NFIinfo.pageSize;
      }

      curPosition++;
      
      /* Looking for the next good block */
      if ( (curPosition & maskI)==0 )
      {
         do
         {
            WacthDogRestart();

            blockNo++;
            
            curPosition = (blockNo << (BLHeader.blockShift - PAGE_SHIFT));
            addr1 = curPosition << PAGE_SHIFT;
            addr2 = 0;      
            
            if ( BLHeader.NFIinfo.addressCycle>4 )
            {
               if ( curPosition&0xffff0000 )
                  addr2 = (kal_uint32)(curPosition >> PAGE_SHIFT);
            }
            
            if ( GoodBlockChecking(&BLHeader.NFIinfo, addr1, addr2) == KAL_TRUE )  
               break;

#ifdef BL_DEBUG               
            dbg_print("\n\rBad block at block %d\n\r", blockNo);
#endif /* BL_DEBUG */               
               /* Skip the bad block */
         } while ( 1 );
         
         dbg_print("..");       
      }
      else
      {
         addr1 = curPosition << PAGE_SHIFT;      
         addr2 = 0;      
         if ( BLHeader.NFIinfo.addressCycle>4 )
         {
            if ( curPosition&0xffff0000 )
               addr2 = (kal_uint32)(curPosition >> PAGE_SHIFT);
         }
      }
      
   } 
      
   TS_END(TSID_BL_MULTIPLE_PAGE_READ);
      
   return blockNo;
}



/**********************************************************
Description : Load and verify P-MAUI
Input       : None
Output      : None
***********************************************************/

kal_uint32 LoadPrimariMAUI(void)
{
   extern void SwitchMAUIToCacheable(kal_uint32 on, kal_uint32 param);
   
   kal_uint32 start_index, i;

   kal_uint32 targetBinary = 0;

   if(IsMetaModeEnabled())
   {
      targetBinary = FFBR_ID_IMAGEHEADER;
   }

   TS_BEGIN(TSID_BL_VERIFY_NFB_IMAGE_CONTENT);
   start_index = SST_VerifyNFBImageContent((void *)MultiPageReading, (void*)SwitchMAUIToCacheable, targetBinary);
   TS_END(TSID_BL_VERIFY_NFB_IMAGE_CONTENT);
   
   dbg_print("NFB image index: %d...\n\r", start_index);
   if ((kal_int32)start_index < 0)
   {
      return 0xffffffff;
   }

   if(BL_Shared_info.m_bl_image_list.m_image[start_index].m_reserved == FFBR_ID_IMAGEHEADER)
   {
      BL_PRINT(LOG_INFO, "Launching FactoryBin in Combine mode...\r\n");
   }

#if defined(__APPLICATION_PROCESSOR__)
   /* If Running on AP Core, Load all other images */
   for (i=start_index+1 ; i < BL_Shared_info.m_bl_image_list.m_image_count; i++)
   {
      dbg_print("AP Core BootLoader -- Loading image index: %d...\n\r", i);
      MultiPageReading(i, 0);
   }
#endif /* __APPLICATION_PROCESSOR__ */

   return BL_Shared_info.m_bl_image_list.m_image[start_index].m_load_addr;
   
}

/* Utilities */
void* GetVersionInfoAddress()
{
   return (void*)(GetImageInfo(ROMINFO_INDEX)->m_load_addr);
}

#endif /* _NAND_FLASH_BOOTING_ */



#if defined(__NOR_FLASH_BOOTING__)
void NorFlashBooting()
{
   volatile kal_uint32 *src, *dst;
   kal_uint32 i;

   /* copy 8MB from NOR to SDRAM */
   src = (volatile kal_uint32 *)0x40000;
   dst = (volatile kal_uint32 *)0x08000000;
   for (i = 0x800000; i > 0; i -= 4, src++, dst++) {
      *dst = *src;
   }

   WacthDogRestart();
}
#endif //__NOR_FLASH_BOOTING__   

#if defined(__MTK_SECURE_PLATFORM__) && defined(_NAND_FLASH_BOOTING_)
void LoadDataForSecureUSBDL(void)
{
   if ( bl_secure_nfb_usbdl )
   {
      SST_Load_Data_For_SUSBDL((void *)MultiPageReading);
   }
}
#endif /* __MTK_SECURE_PLATFORM__ && _NAND_FLASH_BOOTING_ */


#endif /* __EXT_BOOTLOADER__ */


#endif /* __SV5_ENABLED__ */

