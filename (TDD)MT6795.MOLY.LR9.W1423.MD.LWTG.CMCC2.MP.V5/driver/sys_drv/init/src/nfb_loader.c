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
 *   NFB_loader.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the HW initialization.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/*******************************************************************************
 * Include header files.
 *******************************************************************************/
#include "bl_loader.h"
#include "dcl.h"
#include "nfb_loader.h"
#include "SST_secure.h"
#include "page.h"
#include "init.h"
#include "cache_sw_int.h"
#include "cache_sw.h"
#include "NAND_MTD.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "br_GFH_file_info.h"
#include "fota_error.h"
#include "string.h"
#include "custom_scatstruct.h"
#include "kal_public_defs.h"
#include "FTL.h"
 
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
#include "init.h"
#include "mmu_int.h"
#include "mmu.h"
#include "cp15.h"
#endif /* __ARM9_MMU__ || __ARM11_MMU__ */

#if defined(__SV5_ENABLED__)
#include "bl_BootInfo.h"
#include "br_GFH_error.h"
#include "maui_GFH_body.h"
#include "cbr.h"
#endif /* __SV5_ENABLED__ */

#if defined(__DSP_FCORE4__)
#include "dmdsp_init.h"
#endif /* __DSP_FCORE4__ */

#if defined(__EMMC_BOOTING__) && defined(__EMMC_DRV_UT__)
#include "msdc_def.h"
#include "sd_adap.h"
#include "fs_gprot.h"
#include "fat_fs.h"

extern FS_Driver FS_SdDrv;
FS_Driver *cardDrv = &FS_SdDrv;
kal_uint8 test_buf1[1024];
kal_uint8 test_buf2[1024];
#endif

#if (defined(_NAND_FLASH_BOOTING_) && !defined(__NFB_SINGLE_ROM__)) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__)

#pragma arm section rwdata = "NONCACHEDRW", zidata = "NONCACHEDZI"
/*******************************************************************************
 * Define global data.
 *******************************************************************************/

kal_bool NFB_SecondaryImageLoaded = KAL_FALSE;
extern const kal_uint32 g_SST_UAoffset;
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
kal_uint32 shock_dynamic_mmu_switch_duration = 0;	
extern kal_uint32 Image$$SECONDARY_ROM$$Base;
extern kal_uint32 custom_get_2nd_ROM_ROMLength(void);
#endif /* __ARM9_MMU__ || __ARM11_MMU__ */

/*******************************************************************************
 * Define import global data.
 *******************************************************************************/

extern kal_uint32 Image$$INTSRAM_MULTIMEDIA$$Base;
#ifdef __DEMAND_PAGING_PERFORMANCE_PROFILING__
#include "Us_timer.h"
extern void RestoreIRQMask(kal_uint32 ret);
extern kal_uint32 SaveAndSetIRQMask(void);
#endif


/*******************************************************************************
 * Define import function prototypes.
 *******************************************************************************/

#if defined(__NOR_FLASH_BOOTING__)
extern kal_uint32 Load$$SECONDARY_ROM$$Base;
extern kal_uint32 Image$$SECONDARY_ROM$$Base;
extern kal_uint32 Load$$SECONDARY_ROM$$Base;
extern kal_uint32 Load$$THIRD_ROM$$Base;
#endif   /* __NOR_FLASH_BOOTING__ */

extern void SYS_InitRegions(void);
extern void CacheInitSecondaryMAUI(void);
extern void ShowCategory401Screen(kal_uint16 percentage);
extern void NFBMBA_loader_iteration_callback(kal_uint32 addr, kal_uint32 length);
extern kal_uint32 NFBMBA_loader_getImageLength(void * Data);
extern kal_uint32 NFBMBA_loader_getImageExecViewAddress(void * Data);

#if defined(__SV5_ENABLED__)
extern kal_int32 CBRUtl_InitService(void);
extern kal_bool SST_VerifySecondaryMAUI(kal_uint32 *pParentBin, kal_uint32 *pMAUI);
#if defined(__CACHED_BASE_DSP__)
extern kal_bool SST_VerifyDspROM(kal_uint32 *pParentBin, kal_uint32 *pDSP);
#endif /* __CACHED_BASE_DSP__ */
#endif /* __SV5_ENABLED__ */

#if defined(__DEMAND_PAGING__)
extern kal_int32 demp_ReadPhysicalPage(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data);
#endif /* __DEMAND_PAGING__ */

extern FTL_FuncTbl ftlFuncTbl;

#if ( defined(__MAUI_BASIC__) || defined(__L1_STANDALONE__) || defined(EMPTY_MMI) || defined(EXTERNAL_MMI) || defined(__FAST_LOGO__) )
#define NFB_DisplayProgressBar(X)
#else /* __MAUI_BASIC__ || _L1_STANDALONE__ || EMPTY_MMI || EXTERNAL_MMI */
#define NFB_DisplayProgressBar(X) ShowCategory401Screen(X) 
#endif /* __MAUI_BASIC__ || _L1_STANDALONE__ || EMPTY_MMI || EXTERNAL_MMI */

#if defined(__NOR_FLASH_BOOTING__)
/*************************************************************************
* FUNCTION
*  NOR_BOOT_startLoadingSecondaryMAUI
*
* DESCRIPTION
*   MAUI is plitted into two portions, the smaller part is loaded by 
*   Boot-loader, the remaining is loaded here.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void NOR_BOOT_startLoadingSecondaryMAUI(void)
{
   volatile kal_uint32 *src, *dst;
   kal_uint32 len, i, progress, percent;
   DCL_HANDLE handle;


   src = (volatile kal_uint32 *)((kal_uint32)&Load$$SECONDARY_ROM$$Base | 0x08040000);
   dst = (volatile kal_uint32 *)&Image$$SECONDARY_ROM$$Base;
   len = (kal_uint32)&Load$$THIRD_ROM$$Base - (kal_uint32)&Load$$SECONDARY_ROM$$Base;
   len = (((len) + 3) >> 2) << 2;
   percent = 0;
   progress = len / 10;

   /* latch-up power */
   handle = DclPW_Open(DCL_PW, FLAGS_NONE);
   DclPW_Control(handle, PW_CMD_NFB_POWERON, NULL);
   DclPW_Close(handle);

   /* copy image */
   for (i = 0; i < len; i += 4, src++, dst++)
   {
      if (i >= progress)
      {
         percent += 10;
         NFB_DisplayProgressBar(percent);
         progress += len / 10;
      }
      *dst = *src;
   }

   NFB_DisplayProgressBar(100);
}
#endif /* __NOR_FLASH_BOOTING__ */

/*************************************************************************
* FUNCTION
*  NFB_SV5_startLoadingSecondaryMAUI
*
* DESCRIPTION
*   MAUI is plitted into two portions, the smaller part is loaded by 
*   Boot-loader, the remaining is loaded here.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#define SecondaryMAUIReadFailed          (0)
#define FTL_ERROR                        (0)
#if defined(__SV5_ENABLED__) 

#if defined(__DSP_FCORE4__)
extern kal_uint32 Load$$DSP_ROM$$Base;
#define DSP_START_ADDR &Load$$DSP_ROM$$Base
#endif /* __DSP_FCORE4__ */

#if defined(__CACHED_BASE_DSP__)
/* CACHED_DSP_ROM: load view = exe view */
/* load view link symbol is not available, thus we use exe view instead */
extern kal_uint32 Image$$DSP_ROM$$Base;
#define CACHED_DSP_START_ADDR &Image$$DSP_ROM$$Base
#endif /* __CACHED_BASE_DSP__ */

extern kal_uint32 Image$$ROM_GFH$$Base;
extern kal_uint32 Load$$SECONDARY_ROM_GFH$$Base;

static void NFB_SV5_startLoadingSecondaryMAUI(void)
{
   kal_bool   displayStatus=KAL_FALSE;
   kal_int32  ret;
   kal_int32  pagesize;
   kal_int32  length;   
   kal_uint16 percentage;
   kal_uint32 blockNo, index, start_index;
   kal_uint32 check_point, percentage_step;
   kal_uint32 accumulativeSize, totalLength;
   kal_uint32 *destinationPtr; 
   kal_uint32 pagesPerBlock=0, pageIndex=0;
   kal_uint32 loadAddr[MAX_FLASH_LAYOUT_REGION] = {0};
   kal_uint32 loadLen[MAX_FLASH_LAYOUT_REGION] = {0};
   FlashLayout *flashLayoutPtr;   
   kal_uint32 pageBuffer;
   DCL_HANDLE handle;
   kal_int32 prevResourceImage = -1;
   kal_uint8 demp_res_bin;
   
   // Initial FTL
   ftlFuncTbl.FTL_Init(NULL);
      
   //Init CBR service
   CBRUtl_InitService();
   
   start_index = 0;
   /* get page size. To revise */
   pagesize = ftlFuncTbl.FTL_GetPageSize();
   if (pagesize == 2048)
   {
      pagesPerBlock = 64;       
      set_demp_npage_shift(11);
      set_demp_blk_page_nr(64);
   }
   else if (pagesize == 4096)
   {
      pagesPerBlock = 64;       
      set_demp_npage_shift(12);
      set_demp_blk_page_nr(64);
   }   
   else if (pagesize == 512)
   {
      pagesPerBlock = 32;
      set_demp_npage_shift(9);
      set_demp_blk_page_nr(32);
   }
   else if (pagesize == 8192) {
      pagesPerBlock = 64;
      set_demp_npage_shift(13);
      set_demp_blk_page_nr(64);
   }
   else
   {
      //EXT_ASSERT(SecondaryMAUIReadFailed, pagesize, start_index, 0);
      ASSERT(SecondaryMAUIReadFailed);
   }

   /* Sum the total length of each image */
   index = start_index;
   accumulativeSize = 0;
   totalLength = 0;
   
   if(custom_get_SysRam_MaxSize() != 0)
   {
      /* there is SYSRAM */   
      flashLayoutPtr = (FlashLayout*)custom_get_SysRam_Base();   
      pageBuffer = (kal_uint32)custom_get_SysRam_Base() + 0x1000;      
   }
   else
   {
      /* TCM instead */
      flashLayoutPtr = (FlashLayout*)custom_get_INTSRAMCODE_Base();   
      pageBuffer = (kal_uint32)custom_get_INTSRAMCODE_Base() + 0x1000;         
   }
   
   while ( index<flashLayoutPtr->regionCount )
   {

#if defined(__FACTORY_BIN__)   
      if (flashLayoutPtr->region[index].binaryType != PRIMARY_MAUI && flashLayoutPtr->region[index].binaryType != SECONDARY_MAUI)
#else
      if (flashLayoutPtr->region[index].binaryType != PRIMARY_FACTORY_BIN && flashLayoutPtr->region[index].binaryType != SECONDARY_FACTORY_BIN)
#endif      
      {
          kal_uint32 blockIdx = flashLayoutPtr->region[index].u.nandEmmc.startPage / pagesPerBlock;
          kal_uint32 pageIdx  = flashLayoutPtr->region[index].u.nandEmmc.startPage % pagesPerBlock;
         
          GFH_FILE_INFO_v1 *pGFHFileInfo = (GFH_FILE_INFO_v1*)pageBuffer;

          do
          {
              ret = ftlFuncTbl.FTL_ReadPage(blockIdx, pageIdx, (kal_uint32*)pageBuffer, NULL);

              blockIdx++;
              pageIdx = 0;
          } while(ret == FTL_ERROR_BAD_BLOCK);

          if( ret == FTL_SUCCESS )
          {
              ASSERT( GFH_FILE_INFO_IsValid(pGFHFileInfo) == B_OK );

              if(  flashLayoutPtr->region[index].binaryType ==PRIMARY_MAUI)
              {
                  /* Get the length of Primary MAUI */
                  accumulativeSize = pGFHFileInfo->m_file_len;
              }
              else if(flashLayoutPtr->region[index].binaryType != ON_DEMAND_PAGING
#if defined(__MBA_ON_DEMAND__)
                      && flashLayoutPtr->region[index].binaryType != CUSTOM_PACK
                      && flashLayoutPtr->region[index].binaryType != LANGUAGE_PACK
#endif /* __MBA_ON_DEMAND__ */
              )
              {
                  /* bypass those on-demanded binary */
                  totalLength += pGFHFileInfo->m_file_len;
              }

#if defined(__DSP_FCORE4__)
              if( flashLayoutPtr->region[index].binaryType == DSP_ROM )
              {
                  loadAddr[index] = (kal_uint32)DSP_START_ADDR;
              }
              else
#endif

#if defined(__CACHED_BASE_DSP__)
              if ( flashLayoutPtr->region[index].binaryType == CACHED_DSP_ROM )
              {
                  loadAddr[index] = (kal_uint32)CACHED_DSP_START_ADDR;
              }
              else
#endif /* __CACHED_BASE_DSP__ */
              {
                  loadAddr[index] = pGFHFileInfo->m_load_addr;
              }
              loadLen[index]  = pGFHFileInfo->m_file_len;
          }
      }
      index++;
   }

   /* calculate percentage_step */
   percentage_step = totalLength / NFB_PERCENTAGE_STEP;
         
   percentage = 0;
   check_point = accumulativeSize + percentage_step;                               
      
   index = start_index;
   demp_res_bin = 1;

   while ( index<flashLayoutPtr->regionCount )
   {
      
      /* common variable init */
      destinationPtr = (kal_uint32 *)(loadAddr[index]);
      length = (kal_int32)(loadLen[index]) ;
      blockNo   = (flashLayoutPtr->region[index].u.nandEmmc.startPage) / pagesPerBlock;
      pageIndex = (flashLayoutPtr->region[index].u.nandEmmc.startPage) % pagesPerBlock;

      /* determine if demand paging region */
      if ( flashLayoutPtr->region[index].binaryType == ON_DEMAND_PAGING )
      {
         //Todo 1: skip the first page
         //Todo 2: Should on demand paging always block-aligned?
         set_demp_begin(DEMP_MAIN, MAP2CREGVA(loadAddr[index]));
         set_demp_end(DEMP_MAIN, MAP2CREGVA(loadAddr[index] + loadLen[index]));
         set_demp_block(DEMP_MAIN, flashLayoutPtr->region[index].u.nandEmmc.startPage/pagesPerBlock);
		 
         index++;
         continue;
      }
      /* Primary MAUI has been loaded */
#if defined(__FACTORY_BIN__) //skip primaray & secondary maui when in factory binary
      if( flashLayoutPtr->region[index].binaryType == PRIMARY_FACTORY_BIN || flashLayoutPtr->region[index].binaryType == PRIMARY_MAUI || flashLayoutPtr->region[index].binaryType == SECONDARY_MAUI)
      {
         index++;
         continue;
      }
#else // skip factory primary & secondary in factory binary 
      if( flashLayoutPtr->region[index].binaryType == PRIMARY_MAUI || flashLayoutPtr->region[index].binaryType == PRIMARY_FACTORY_BIN || flashLayoutPtr->region[index].binaryType == SECONDARY_FACTORY_BIN)
      {
         index++;
         continue;

      }
#endif /* __FACTORY_BIN__ */

      /* determine if MBA Resource Binary
       * Then the destination address and length will altered by resource image header content
       * accumulativeSize adjusted due to first page already loaded
       */
      else if (flashLayoutPtr->region[index].binaryType >= V_RESOURCE_BINARY &&
               flashLayoutPtr->region[index].binaryType <= V_RESOURCE_BINARY_END )
      {
#if defined(__MBA_ON_DEMAND__)
	  
         /* Do not shadow resource bin, but treat it as a demand paging bin */
         set_demp_begin(demp_res_bin, MAP2CREGVA(loadAddr[index]));
         set_demp_end(demp_res_bin, MAP2CREGVA(loadAddr[index] + loadLen[index]));
         set_demp_block(demp_res_bin, flashLayoutPtr->region[index].u.nandEmmc.startPage/pagesPerBlock);
		 
         index++;
         demp_res_bin++;
         continue;
		 
#else /* __MBA_ON_DEMAND__ */

         /* The first RESB loading dest address are fixed */
         if (prevResourceImage != -1)
         {
            loadAddr[index] = loadAddr[prevResourceImage] + loadLen[prevResourceImage];
            ///pImage->m_load_addr = pPrevResourceImage->m_load_addr + pPrevResourceImage->m_length;
            destinationPtr = (kal_uint32 *)(loadAddr[index]);
         }

         /* Retrieve the RESB header from the first page of start block */
         ret = ftlFuncTbl.FTL_ReadPage(blockNo, 0, destinationPtr, NULL);
         if (ret != FTL_SUCCESS)
         {
            EXT_ASSERT(SecondaryMAUIReadFailed, ret, index, 0);     
         } 
         
         /* The second or later RESB loading dest address need double confirm */
         if (prevResourceImage != -1)
         {
            loadAddr[index] = NFBMBA_loader_getImageExecViewAddress((void*)((kal_uint32)destinationPtr + sizeof(GFH_FILE_INFO_v1))) - sizeof(GFH_FILE_INFO_v1);

            /* Check and stop if RESB binary already overlap */
            if (loadAddr[index] < (kal_uint32)destinationPtr)
            {
               //EXT_ASSERT(SecondaryMAUIReadFailed, loadAddr[index], index, (kal_uint32)destinationPtr);
               ASSERT(SecondaryMAUIReadFailed);
            }
         }

         /* Setup the length required to load */
         loadLen[index]    = NFBMBA_loader_getImageLength((void*)((kal_uint32)destinationPtr + sizeof(GFH_FILE_INFO_v1))) + sizeof(GFH_FILE_INFO_v1);
         length            = (kal_int32)(loadLen[index]);


         /* Check the loaded page on correct address */
         if (loadAddr[index] != (kal_uint32)destinationPtr)
         {
            destinationPtr    = (kal_uint32 *)(loadAddr[index]);
            pageIndex         = 0;
         }
         else
         {
            destinationPtr   += (pagesize>>2);
            length           -= pagesize;
            accumulativeSize += pagesize;
            pageIndex         = 1;
         }
		 
#endif /* __MBA_ON_DEMAND__ */
      }
      
      /* start sequential loading */
      while ( length>0 )
      {            
         if ((displayStatus==KAL_FALSE))
         {
            /* Ready to latch-up power, BMT will do the final judgement! */
            handle = DclPW_Open(DCL_PW, FLAGS_NONE);
            DclPW_Control(handle, PW_CMD_NFB_POWERON, NULL);
            DclPW_Close(handle);
            /* Ready to show-up the first screen, MMI will do the final judgement! */
            NFB_DisplayProgressBar(percentage);            
            percentage += NFB_PERCENTAGE_STEP;
            displayStatus = KAL_TRUE;
         }
         
         /* Reading a block */
         while ( (pageIndex < pagesPerBlock) && (length>0) )
         {
            ret = ftlFuncTbl.FTL_ReadPage(blockNo, pageIndex, destinationPtr, NULL);
            
            if ( ret == FTL_SUCCESS )
            {
               accumulativeSize += pagesize;
               destinationPtr += (pagesize>>2);
               length -= pagesize;
               pageIndex++;
            }
            else if ( ret == FTL_ERROR_BAD_BLOCK )
            {
               break;
            }
            // Otherwise , Error
            else
            {
               EXT_ASSERT(FTL_ERROR, ret, blockNo, pageIndex);
            }
         }
         
         blockNo++;
         pageIndex = 0;
         
         if ((accumulativeSize >= check_point) && (displayStatus==KAL_TRUE))
         {
            /* Ready to show-up the first screen, MMI will do the final judgement! */
            percentage = (percentage < 100) ? percentage : 100;
            NFB_DisplayProgressBar(percentage);    
            percentage += NFB_PERCENTAGE_STEP;
            check_point = accumulativeSize + percentage_step;
         }
      }

#if defined(__DSP_BOOT_SEC__)
      if( flashLayoutPtr->region[index].binaryType == DSP_ROM )
      {
         /* dmdsp_init */
         dmdsp_init(loadAddr[index]);
         sync_status = dmdsp_sync_done();
      }
#endif /* __DSP_BOOT_SEC__ */

      /* determine if MBA Resource Binary */
      if (flashLayoutPtr->region[index].binaryType >= V_RESOURCE_BINARY &&
          flashLayoutPtr->region[index].binaryType <= V_RESOURCE_BINARY_END )
      {
         prevResourceImage = index;
         NFBMBA_loader_iteration_callback(loadAddr[index] + sizeof(GFH_FILE_INFO_v1), loadLen[index] - sizeof(GFH_FILE_INFO_v1));
      }

      index ++;
   }

   if ( displayStatus==KAL_FALSE )
   {
      /* Ready to latch-up power, BMT will do the final judgement! */
      handle = DclPW_Open(DCL_PW, FLAGS_NONE);
      DclPW_Control(handle, PW_CMD_NFB_POWERON, NULL);
      DclPW_Close(handle);
   }
   else
   {
      /* Ready to show-up the first screen, MMI will do the final judgement! */
      NFB_DisplayProgressBar(100);    
   }

   SST_VerifySecondaryMAUI((kal_uint32*)&Image$$ROM_GFH$$Base, (kal_uint32*)&Load$$SECONDARY_ROM_GFH$$Base);
   
#if defined(__CACHED_BASE_DSP__)
   SST_VerifyDspROM((kal_uint32*)&Image$$ROM_GFH$$Base, CACHED_DSP_START_ADDR);
#endif /* __CACHED_BASE_DSP__ */
}
#endif /* __SV5_ENABLED__ */

/*************************************************************************
* FUNCTION
*  NFB_startLoadingSecondaryMAUI
*
* DESCRIPTION
*   MAUI is plitted into two portions, the smaller part is loaded by 
*   Boot-loader, the remaining is loaded here.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#define SecondaryMAUIReadFailed          (0)
#define FPBR_ASCII 0x52424653
#if !defined(__SV5_ENABLED__) 
static kal_bool g_skip_done = KAL_FALSE;
static void NFB_startLoadingSecondaryMAUI(void)
{
   kal_bool   displayStatus=KAL_FALSE;
   kal_int32  ret;
   kal_int32  pagesize;
   kal_int32  length;   
   kal_uint16 percentage;
   kal_uint32 blockNo, index, start_index;
   kal_uint32 check_point, percentage_step;
   kal_uint32 accumulativeSize, totalLength;
   kal_uint32 *destinationPtr; 
   kal_uint32 pagesPerBlock=0, pageIndex=0;
   Nand_ImageInfo_S *pImage;
   Nand_ImageInfo_S *pPrevResourceImage;  

   kal_uint32 ext_start, ext_len;
   Nand_ImageList_S  *imageHeaderPtr;
   DCL_HANDLE handle;
   kal_uint8 demp_res_bin;
   
   if(custom_get_SysRam_MaxSize() != 0)
   {
      /* there is SYSRAM */   
      imageHeaderPtr = (Nand_ImageList_S *)custom_get_SysRam_Base();
   }
   else
   {
      /* TCM instead */
      imageHeaderPtr = (Nand_ImageList_S *)custom_get_INTSRAMCODE_Base();   
   }

   //EXT_ASSERT((imageHeaderPtr->m_image_count<MAX_IMAGE_NUMBER), imageHeaderPtr->m_image_count, 0, 0);      
   ASSERT(imageHeaderPtr->m_image_count<MAX_IMAGE_NUMBER);
      
   // Initial FTL
   ftlFuncTbl.FTL_Init(NULL);
     
   /* calculate the suitable index for further image loading */
   if( CHECK_PASS_ID  == imageHeaderPtr->m_image[0].m_reserved )
   {
      start_index = 4 + g_SST_UAoffset;
   }
   else
   {
      start_index = 2 + g_SST_UAoffset;
   }
     
   /* if factory binary exist */
#if !defined(__FACTORY_BIN__)   
   if (FPBR_ASCII == (imageHeaderPtr->m_image[start_index]).m_reserved)
   {
       start_index += 2;
   }
#endif
     
   /* Read the first page to get the NAND-flash configuration */
   pagesize = ftlFuncTbl.FTL_GetPageSize();
 
   if (pagesize == 2048)
   {
      pagesPerBlock = 64;       
      set_demp_npage_shift(11);
      set_demp_blk_page_nr(64);
   }
   else if (pagesize == 4096) {
      pagesPerBlock = 64;       
      set_demp_npage_shift(12);
      set_demp_blk_page_nr(64);
   }   
   else if (pagesize == 512)
   {
      pagesPerBlock = 32;
      set_demp_npage_shift(9);
      set_demp_blk_page_nr(32);
   }
   else
   {
      //EXT_ASSERT(SecondaryMAUIReadFailed, pagesize, start_index, 0);
      ASSERT(SecondaryMAUIReadFailed);
   }
   
   ext_start = custom_get_1st_ROM_ROMBase();
   custom_get_EXTSRAM_size(&ext_len);
   
   /* Sum the total length of each image */
   index = start_index;
   totalLength = 0;
   
   while ( index<imageHeaderPtr->m_image_count )
   {
      if ((imageHeaderPtr->m_image[index]).m_load_addr >= (ext_start + ext_len)) 
      {
         /* bypass demand paging region */
      } 
      else 
      {
         if (index < 10)
         {
            totalLength += (imageHeaderPtr->m_image[index]).m_length;
         }
         else
         {
            totalLength += (imageHeaderPtr->m_image_ext[index - 10]).m_length;
         }
      }
#if defined(__FACTORY_BIN__)   
      if (CHECK_PASS_ID  == imageHeaderPtr->m_image[0].m_reserved && KAL_FALSE == g_skip_done)
      {
        index = imageHeaderPtr->m_image_count-5;
        g_skip_done = TRUE;
      }
#endif
      index++;
   }
   
   /* Get the length of Primary MAUI */
   accumulativeSize = (imageHeaderPtr->m_image[start_index - 1]).m_length;   
   
   /* calculate percentage_step */
   percentage_step = totalLength / NFB_PERCENTAGE_STEP;
         
   percentage = 0;
   check_point = accumulativeSize + percentage_step;                               
      
   index = start_index;
   demp_res_bin = 1;
   g_skip_done = KAL_FALSE;

   pImage = NULL;
   pPrevResourceImage = NULL;
   while ( index<imageHeaderPtr->m_image_count )
   {
      if (index < 10)
      {
      	pImage = imageHeaderPtr->m_image + index;
      }
      else
      {
      	pImage = imageHeaderPtr->m_image_ext + (index - 10);
      }
      /* common variable init */
      destinationPtr = (kal_uint32 *)(pImage->m_load_addr);        
      length = (kal_int32)(pImage->m_length);
      blockNo = pImage->m_start_block;
      pageIndex = 0;
      
      /* Secure NFB assume Secondary MAUI as start Idx image
       * accumulativeSize adjusted due to first page already loaded
       */
      /* determine if MBA Resource Binary
       * Then the destination address and length will altered by resource image header content
       * accumulativeSize adjusted due to first page already loaded
       */
      if (pImage->m_reserved == RESB_ID_IMAGEHEADER )
      {
#if defined(__MBA_ON_DEMAND__)

         /* Do not shadow resource bin, but treat it as a demand paging bin */
         set_demp_begin(demp_res_bin, MAP2CREGVA(pImage->m_load_addr));
         set_demp_end(demp_res_bin, MAP2CREGVA(pImage->m_load_addr + pImage->m_length));
         set_demp_block(demp_res_bin, pImage->m_start_block);
		 
         index++;
         demp_res_bin++;
         continue;

#else /* __MBA_ON_DEMAND__ */

         /* The first RESB loading dest address are fixed */
         if (pPrevResourceImage != NULL)
         {
            pImage->m_load_addr = pPrevResourceImage->m_load_addr + pPrevResourceImage->m_length;
            destinationPtr = (kal_uint32 *)(pImage->m_load_addr);
         }

         /* Retrieve the RESB header from the first page of start block */
         ret = ftlFuncTbl.FTL_ReadPage(pImage->m_start_block, 0, destinationPtr, NULL);
         if (ret != FTL_SUCCESS)
         {
            EXT_ASSERT(SecondaryMAUIReadFailed, ret, index, 0);     
         } 
         
         /* The second or later RESB loading dest address need double confirm */
         if (pPrevResourceImage != NULL)
         {
            pImage->m_load_addr = NFBMBA_loader_getImageExecViewAddress(destinationPtr);

            /* Check and stop if RESB binary already overlap */
            if (pImage->m_load_addr < (kal_uint32)destinationPtr)
            {
               //EXT_ASSERT(SecondaryMAUIReadFailed, pImage->m_load_addr, index, (kal_uint32)destinationPtr);
               ASSERT(SecondaryMAUIReadFailed);
            }
         }

         /* Setup the length required to load */
         pImage->m_length    = NFBMBA_loader_getImageLength(destinationPtr);
         length            = (kal_int32)(pImage->m_length);


         /* Check the loaded page on correct address */
         if (pImage->m_load_addr != (kal_uint32)destinationPtr)
         {
            destinationPtr    = (kal_uint32 *)(pImage->m_load_addr);
            pageIndex         = 0;
         }
         else
         {
            destinationPtr   += (pagesize>>2);
            length           -= pagesize;
            accumulativeSize += pagesize;
            pageIndex         = 1;
         }
		 
#endif /* __MBA_ON_DEMAND__ */		 
      }
      /* determine if demand paging region */
      else if (pImage->m_load_addr >= (ext_start + ext_len))
      {
         set_demp_begin(DEMP_MAIN, MAP2CREGVA(pImage->m_load_addr));
         set_demp_end(DEMP_MAIN, MAP2CREGVA(pImage->m_load_addr + pImage->m_length));
         set_demp_block(DEMP_MAIN, pImage->m_start_block);
		 
         index++;
         continue;
      }
      
      /* start sequential loading */
      while ( length>0 )
      {            
         if (displayStatus==KAL_FALSE)
         {
            /* Ready to latch-up power, BMT will do the final judgement! */
            handle = DclPW_Open(DCL_PW, FLAGS_NONE);
            DclPW_Control(handle, PW_CMD_NFB_POWERON, NULL);
            DclPW_Close(handle);
            /* Ready to show-up the first screen, MMI will do the final judgement! */
            NFB_DisplayProgressBar(percentage);            
            percentage += NFB_PERCENTAGE_STEP;
            displayStatus = KAL_TRUE;
         }
         
         /* Reading a block */
         while ( (pageIndex < pagesPerBlock) && (length>0) )
         {
            ret = ftlFuncTbl.FTL_ReadPage(blockNo, pageIndex, destinationPtr, NULL);
            
            if ( ret == FTL_SUCCESS )
            {
               accumulativeSize += pagesize;
               destinationPtr += (pagesize>>2);
               length -= pagesize;
               pageIndex++;
            }
            else if ( ret == FTL_ERROR_BAD_BLOCK )
            {
               break;
            }
            // Otherwise , Error
            else
            {
               EXT_ASSERT(FTL_ERROR, ret, blockNo, pageIndex);
            }
         }
         
         blockNo++;
         pageIndex = 0;
         
         if ((accumulativeSize >= check_point) && (displayStatus==KAL_TRUE))
         {
            /* Ready to show-up the first screen, MMI will do the final judgement! */
            percentage = (percentage < 100) ? percentage : 100;			
            NFB_DisplayProgressBar(percentage);    
            percentage += NFB_PERCENTAGE_STEP;
            check_point = accumulativeSize + percentage_step;
         }
      }
      /* determine if MBA Resource Binary */
      if (pImage->m_reserved == RESB_ID_IMAGEHEADER )
      {
         pPrevResourceImage = pImage;
         NFBMBA_loader_iteration_callback(pImage->m_load_addr, pImage->m_length);
      }
      
#if defined(__FACTORY_BIN__)      
      if (CHECK_PASS_ID == imageHeaderPtr->m_image[0].m_reserved && KAL_FALSE == g_skip_done)
      {
        index = imageHeaderPtr->m_image_count -5 ;
        g_skip_done = TRUE;
      }
#endif      
      index ++;
   }
   
   if ( displayStatus==KAL_FALSE )
   {
      /* Ready to latch-up power, BMT will do the final judgement! */
      handle = DclPW_Open(DCL_PW, FLAGS_NONE);
      DclPW_Control(handle, PW_CMD_NFB_POWERON, NULL);
      DclPW_Close(handle);
   }
   else
   {
      /* Ready to show-up the first screen, MMI will do the final judgement! */
      NFB_DisplayProgressBar(100);    
   }

   /* verify the integrity of secondary MAUI */
#if defined(__FACTORY_BIN__) 
   SST_SetBootupMode(KAL_TRUE);
#endif

   SST_VerifyNFBSecondaryImage();

}
#endif /* !__SV5_ENABLED__ */

/*************************************************************************
* FUNCTION
*  NFB_LoadingSecondaryMAUI
*
* DESCRIPTION
*   MAUI is plitted into two portions, the smaller part is loaded by 
*   Boot-loader, the remaining is loaded here.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
extern kal_uint32 custom_get_BOOTCERT_StartAddr(void);
extern kal_uint32 custom_get_BOOTCERT_Length(void);
void NFB_LoadingSecondaryMAUI(void)
{  
#if defined(__EMMC_DRV_UT__)
   kal_uint32 status;
#endif /* defined(__EMMC_DRV_UT__) */

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
   kal_uint32 addr = 0;
   kal_uint32 len = 0;

   EXTSRAM_REGION_INFO_T *regionp, *regionp_bak;
   
   #if defined(__DSP_FCORE4__)
   kal_uint32 sec_rom_load_start_addr = custom_get_DSP_ROM_ROMBase();
   #else /* __DSP_FCORE4__ */
   kal_uint32 sec_rom_load_start_addr = custom_get_2nd_ROM_ROMBase();
   #endif /* __DSP_FCORE4__*/
   kal_uint32 sec_rom_start_addr = custom_get_2nd_ROM_ROMBase();
   kal_uint32 sec_rom_end_addr = sec_rom_start_addr + custom_get_2nd_ROM_ROMLength();
   kal_uint32 sec_maui_end_addr = custom_get_2nd_ROM_LoadEnd();

   /* switch 2nd MAUI to RW */
   addr = sec_maui_end_addr;
   ROUNDUP_4KB(addr);
   len = addr;
   addr = sec_rom_load_start_addr;
   ROUNDDOWN_4KB(addr);
   len = len - addr + MAX_NAND_DATA_SIZE;			

   if(cp15_is_dcache_enabled()) 
   {
      cp15_clean_dcache();
      cp15_drain_write_buffer();	 
      cp15_invalidate_dcache();	 	 
   }

   /* Ken: if we do not switch the whole 2nd MAUI to RW,              */
   /* there might be RO margin between 2nd ROM and DNC ZI       */
   dynamic_switch_mmu_permission_cb(addr, len, PRIV_RW, NONCACHEABLE_NONBUFFERABLE);

#if defined(__BOOT_CERT__)
   dynamic_switch_mmu_permission_cb(custom_get_BOOTCERT_StartAddr(), custom_get_BOOTCERT_Length(), PRIV_RW, NONCACHEABLE_NONBUFFERABLE);
#endif 

   /* switch Multiple ROM to RW */
   custom_query_multi_rom_load_region(&regionp);
   regionp_bak = regionp;
   while (regionp->addr != 0 || regionp->len != 0) {
      if (regionp->len == 0) {
         regionp++;
         continue;
      }

      dynamic_switch_mmu_permission_cb(regionp->addr, regionp->len, PRIV_RW, NONCACHEABLE_NONBUFFERABLE);      
      regionp++;
   }

#endif /* __ARM9_MMU__ || __ARM11_MMU__ */

   /* Start data transfer */

#if defined(__EMMC_DRV_UT__)
   status = DRV_SD_Init();
   status = DRV_SD_MountDevice(0, 0);
   status = DRV_SD_ReadSectors(0, 4096, 2, (void*)test_buf2, 0);
   status = DRV_SD_DeInit();

   status = DRV_SD_Init();
   status = DRV_SD_MountDevice(0, 0);
   status = DRV_SD_ReadSectors(0, 4096, 2, (void*)test_buf2, 0);
   status = DRV_SD_DeInit();
#endif /* defined(__EMMC_DRV_UT__) */

#if defined(__NOR_FLASH_BOOTING__)
   NOR_BOOT_startLoadingSecondaryMAUI();
#elif defined(__FOTA_DM__)
   Fota_NFB_startLoadingSecondaryMAUI();
#elif defined(__SV5_ENABLED__)
   NFB_SV5_startLoadingSecondaryMAUI();
#else
   NFB_startLoadingSecondaryMAUI();
#endif /* __FOTA_DM__ */


#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)

   if(cp15_is_icache_enabled()) 
   {
      cp15_invalidate_icache();	 
   }	 

   /* switch Multiple ROM to RO */
   addr = sec_rom_end_addr;
   ROUNDUP_4KB(addr);
   len = addr;
   addr = sec_rom_load_start_addr;
   ROUNDDOWN_4KB(addr);
   len = len - addr;

   dynamic_switch_mmu_permission_cb(addr, len, PRIV_RO, CACHEABLE_BUFFERABLE);   

   #if defined(__BOOT_CERT__)
   dynamic_switch_mmu_permission_cb(custom_get_BOOTCERT_StartAddr(), custom_get_BOOTCERT_Length(), PRIV_RO, CACHEABLE_BUFFERABLE);
   #endif

   /* switch Multiple ROM to RO */
   regionp = regionp_bak;
   while (regionp->addr != 0 || regionp->len != 0) {
      if (regionp->len == 0) {
         regionp++;
         continue;
      }

      dynamic_switch_mmu_permission_cb(regionp->addr, regionp->len, PRIV_RO, CACHEABLE_BUFFERABLE);      
      regionp++;
   }
   
#endif /* __ARM9_MMU__ || __ARM11_MMU__ */
   
   /* Initialize RW region for SECONDARY_EXTSRAM_RW */
   SYS_InitRegions();
  
   /* Cacheable the RO-CODE and RO-DATA area */
   CacheInitSecondaryMAUI();
   
   NFB_SecondaryImageLoaded = KAL_TRUE;    
}

/*************************************************************************
* FUNCTION
*  Swapin_Read
*
* DESCRIPTION
*  This function does SWAP-IN for the specified address.
*
* PARAMETERS
*  va    -    to swap-in address (virtual address)
*  pa    -    to be swapped in address (physical address)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
kal_int32 nfb_err_code;

kal_int32 Swapin_Read(kal_uint8 demp_bin, kal_uint32 va, kal_uint32 pa)
{
#if defined(__DEMAND_PAGING__)
    kal_uint32 offset, cnt, block, page, nr_page;
    kal_int32 ret;
    FTL_OptParam ftl_opt;
#ifdef __DEMAND_PAGING_PERFORMANCE_PROFILING__
    kal_uint32 irq, nfbTickStart, timeDur, i;

  if(dempProfiling == KAL_TRUE && demp_bin == 0){
	irq = SaveAndSetIRQMask();	
	nfbTickStart = ust_get_current_time();	
	RestoreIRQMask(irq);
  }
#endif

    nr_page = ((1 << PAGE_SHIFT_2K) << (PAGE_CLUSTER - 1)) >> demp_npage_shift();
    offset = (va - demp_begin(demp_bin)) >> demp_npage_shift();
    for (cnt = 0; cnt < nr_page; cnt++)
    {
        /* get the block number and the page number in NAND Flash */
        block = (offset + cnt) / demp_blk_page_nr();
        page = (offset + cnt) % demp_blk_page_nr();

        /* do swap in */
        ftl_opt.bypass_dal = KAL_FALSE;
        ftl_opt.is_polling = KAL_TRUE;
        ret = ftlFuncTbl.FTL_ReadPage(*(demp_img_tbl(demp_bin) + block), page, (kal_uint32 *)(pa + (cnt << demp_npage_shift())), &ftl_opt);
        if (ret < 0)
        {
            nfb_err_code = ret;
            return -1;
        }
    }
#ifdef __DEMAND_PAGING_PERFORMANCE_PROFILING__
    if(dempProfiling == KAL_TRUE && demp_bin == 0){
        irq = SaveAndSetIRQMask();
        timeDur = (ust_get_duration(nfbTickStart, ust_get_current_time()) - dempTaskInfo[kal_get_current_task_index()].preemptTime);
        if (timeDur/SWAPTIMERANK < SWAPTIMERANKNUM)
	  swapTime[timeDur/SWAPTIMERANK]++;
        else
  	  swapTime[SWAPTIMERANKNUM-1]++;
        dempPoolStats[(offset >> (PAGE_CLUSTER - 1))].nfbTime += timeDur;
        dempPoolStats[(offset >> (PAGE_CLUSTER - 1))].nfbCount++;
        RestoreIRQMask(irq);
    }
#endif

#endif /* __DEMAND_PAGING__ */

    return 0;
}

#endif /* (_NAND_FLASH_BOOTING_ && !__NFB_SINGLE_ROM__) || __NOR_FLASH_BOOTING__ || __EMMC_BOOTING__ */
