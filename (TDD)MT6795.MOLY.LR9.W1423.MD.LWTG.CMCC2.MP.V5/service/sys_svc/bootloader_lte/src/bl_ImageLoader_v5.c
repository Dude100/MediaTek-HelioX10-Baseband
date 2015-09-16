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
 *   bl_ImageLoader_v5.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   Reponsible for loading image on SV5 platform
 *
 * Author:
 * -------
 *   
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
#include "sw_types.h"
#include "bl_common.h"
#include "br_GFH_file_info.h"
#include "br_GFH_bl_info.h"
#include "bl_GFH_body.h"
#include "bl_BootInfo.h"
#include "bl_common.h"
#include "bl_loader.h"
#include "bl_custom.h"
#include "bl_setting.h"
#include "bl_status.h"
#include "bl_INIT.H"
#include "bl_sectiondef.h"
#include "bl_GPT.h"
#include "SST_secure.h"

#include "custom_img_config.h"

#include "br_time_stamp.h"
#ifdef __TIME_STAMP__ 
#include "br_time_stamp_cb.h"
#include "bl_time_stamp_id.h"
#endif

#include "FTL.h"
#include "br_header_block.h"
#include "br_GFH_error.h"
#include "br_GFH_parser.h"
#include "cbr.h"
#include "Cbr_record_def.h"

#ifdef __X_BOOTING__
#include "br_xboot_cmd.h"
#include "brom_bm.h"
#include "brom_sdio_drv.h"
#endif /* __X_BOOTING__ */

#include "bl_trc_api.h"
#include "bl_share_param.h"
#include "bl_imgtbl.h"
#include "bl_cfgctl.h"
#include "bl_wdt.h"
#ifdef __AP_BOOTUP_BY_MDBL__
#include "bl_topsm.h"
#include "bl_apbl_share_param.h"
#endif

#ifdef _NAND_FLASH_BOOTING_
#include "NAND_DAL.h"
#endif

#ifdef __MINI_BOOTLOADER__
#include "mt_emi.h"
#include "pll.h"
#endif /*__MINI_BOOTLOADER__*/

#include <string.h>

/*************************************************************************
 * Feature definition
 *************************************************************************/
#define AP_BOOT_WITH_BROM_COM

/*************************************************************************
 * Macro and const definition
 *************************************************************************/
#define BL_MAX_PAGE         (2048)
#define BL_MAX_SIZE          (0x40000)  //256KB

#define MAX_FLASH_BOUNDARY (0xffffffff)

#define PAGE_BUFFER_ADDR ((kal_uint32)(&externalPageBuffer))

#define SDIO_TIMEOUT                   (5000)  //real BL need this

#define AP_FACTORY_ENTER_USB_DL          (0x24540001)
#define AP_FACTORY_TRIGGER_META          (0x24540002)
#define AP_WDT_CLEAR_TRIGGERED           (0x24540001)
#define AP_WDT_CLEAR_DONE                (0x24540002)

/*************************************************************************
 * Structure definition
 *************************************************************************/

/*************************************************************************
 * Global variables definition
 *************************************************************************/

kal_uint32 g_maui_load_addr = INVALID_START_ADDR;
FTL_FuncTbl *g_ftlFuncTbl = NULL;

__ext_un_init_zi__ static kal_uint32 externalPageBuffer[8192/4];

#ifdef __EXT_BOOTLOADER__

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) || defined(__XIP_SHADOWING__) || defined(__X_BOOTING__) || defined(__SERIAL_FLASH_EN__)
static kal_uint32 mauiReadLen = 0, restMauiFlashAddr = 0;
#endif

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) || defined(__SERIAL_FLASH_EN__)
__ext_un_init_zi__ static kal_uint32 g_mauiInfoBuf[1024/4];
static kal_bool g_mauiInfoRead = KAL_FALSE;
#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ || __SERIAL_FLASH_EN__*/ 

#endif /* __EXT_BOOTLOADER__ */

/*************************************************************************
 * External symbols
 *************************************************************************/
#if defined(__IC_SLT_LOADER__)
extern kal_uint32 bl_SLTReadHVTBody(GFH_FILE_INFO_v1 *pGFHFileInfo, kal_uint32 pageNo, kal_uint32 readPart);
#endif


extern FTL_FuncTbl ftlFuncTbl;
extern FTL_FuncTbl ftlFuncTblBl;
extern BL_Info_Wrapper_st BL_Shared_info;
extern kal_bool g_bootupDisabled;
extern kal_uint32 g_bootupStatus;

extern void TriggerBromDL(void);
extern void TriggerBlDL(void);
extern void TriggerMetaMode(void);
extern kal_bool IsBlUsbDLModeEnabled(void);
#ifdef __X_BOOTING__
extern U32 SDIO_BL_PutData(U8* buf, U32 len, U32 timeout);
extern U32 SDIO_BL_GetData(U8* buf, U32 len, U32 timeout);
#endif /* __X_BOOTING__ */

/*************************************************************************
 * Declaration
 *************************************************************************/

kal_bool GetBinaryRegionInFlash(GFH_FILE_TYPE type, kal_uint32 *pStart, kal_uint32 *pBoundary );
kal_uint32 GetBinaryStartInFlash(GFH_FILE_TYPE type);
kal_bool XBOOT_SyncWithAP(kal_uint32 *pTimeout);


/*************************************************************************
 * Main code
 *************************************************************************/

#ifdef __NAND_BOOT__
/**********************************************************
Description : Initialziation routines for each memory devices
Input       : None
Output      : None
***********************************************************/
BL_STATUS InitNFI(void)
{
    g_ftlFuncTbl = &ftlFuncTbl;

    g_ftlFuncTbl->FTL_Init(NULL);

    return BL_ERROR_NONE;
}

#endif /* __NAND_BOOT__ */

#ifdef __EMMC_BOOT__
/**********************************************************
Description : Exported API for loading ExtBootloader
Input       : None
Output      : None
***********************************************************/
BL_STATUS InitEMMC(void)
{
   g_ftlFuncTbl = &ftlFuncTbl;
    
   g_ftlFuncTbl->FTL_Init(NULL);
   
   return BL_ERROR_NONE;
}
#endif /* __EMMC_BOOT__ */

#ifdef __SF_BOOT__
/**********************************************************
Description : Exported API for loading ExtBootloader
Input       : None
Output      : None
***********************************************************/
BL_STATUS InitSF(void)
{
   g_ftlFuncTbl = &ftlFuncTbl;
    
   g_ftlFuncTbl->FTL_Init(NULL);
   
   return BL_ERROR_NONE;
}
#endif /* __SF_BOOT__ */

#ifdef __NOR_BOOT__
/**********************************************************
Description : Exported API for loading ExtBootloader
Input       : None
Output      : None
***********************************************************/
BL_STATUS InitNOR(void)
{
   g_ftlFuncTbl = &ftlFuncTbl;
    
   g_ftlFuncTbl->FTL_Init(NULL);
   
   return BL_ERROR_NONE;
}
#endif /* __NOR_BOOT__ */


#ifdef __X_BOOTING__
/**********************************************************
Description : X-Booting initialization
Input       : None
Output      : None
***********************************************************/
BL_STATUS InitXBooting(void)
{
    kal_uint32 status;
    kal_uint32 timeout;

    brom_bm_init(BROM_SDIO_RX_GPD_BUF_SZ, KAL_TRUE);

    //Sync with AP and get the timeout value
    if(XBOOT_SyncWithAP(&timeout) == KAL_FALSE)
    {
        BL_PRINT(LOG_ERROR, "ERROR: Sync with AP fail.\r\n");	
        return BL_ERROR;
    }

    Xboot_SetTimeout(timeout);

    status = XbootCmd_BufSizeChange(BROM_SDIO_RX_GPD_BUF_SZ);
    if(status != 0)
    {
        BL_PRINT(LOG_ERROR, "ERROR: BL change size fail. code:%x\r\n", status);
        return BL_ERROR;
    }

    return BL_ERROR_NONE;
}


#endif /* __X_BOOTING__ */

/**********************************************************
Description : Exported API for loading ExtBootloader
Input       : None
Output      : None
***********************************************************/
BL_STATUS InitFlashDriver(void)
{
    BL_STATUS status = BL_ERROR_NONE;

#if defined(__NAND_BOOT__)

   status = InitNFI();

#elif defined(__EMMC_BOOT__)

   status = InitEMMC();

#elif defined(__SF_BOOT__)

   status = InitSF();

#elif defined(__NOR_BOOT__)

   status = InitNOR();

#elif defined(__X_BOOTING__)

   status = InitXBooting();

#endif

    return status;
}


#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) || defined(__SERIAL_FLASH_EN__)

/**********************************************************
Description : Get the first block next to bootloader region
Input       : None
Output      : None
***********************************************************/
kal_bool ReadDataX(kal_uint32 ptr, kal_uint32 pageNo, kal_uint32 length, kal_bool bDAL, kal_uint32 *pNextPage)
{
   kal_uint32  page_size = g_ftlFuncTbl->FTL_GetPageSize();
   kal_uint32  page_per_block;
   FTL_OptParam ftl_opt;

   kal_bool goodBlockChecked = KAL_FALSE;

   ftl_opt.bypass_dal = (bDAL == KAL_TRUE) ? KAL_FALSE : KAL_TRUE;

   page_per_block = g_ftlFuncTbl->FTL_GetBlockSize(0, &ftl_opt)/page_size;

   ASSERT((length%page_size) == 0);

   if(length == 0)
   {
      return KAL_TRUE;
   }

   while(length)
   {
      if(!goodBlockChecked)
      {
         while( g_ftlFuncTbl->FTL_CheckGoodBlock(pageNo/page_per_block, &ftl_opt) == FTL_ERROR_BAD_BLOCK )
         {
            /* Skip the bad block */
            BL_PRINT(LOG_INFO, "\n\rBad block at block %d\n\r", pageNo/page_per_block);
            
            pageNo = (pageNo/page_per_block+1)*page_per_block;
         }

         goodBlockChecked = KAL_TRUE;
      }

      if( g_ftlFuncTbl->FTL_ReadPage(pageNo/page_per_block, pageNo%page_per_block, (kal_uint32*)ptr, &ftl_opt) != FTL_SUCCESS )
      {
         BL_PRINT(LOG_CRIT, "Read error at block %d, page %d\n\r", pageNo/page_per_block, pageNo%page_per_block);
         return KAL_FALSE;
      }

      pageNo++;
      length -= page_size;
      ptr += page_size;

      /* Looking for the next good block */
      if ( (pageNo % page_per_block)==0 )
      {
         goodBlockChecked = KAL_FALSE;
         BL_PRINT(LOG_INFO, "..");       
      }
   }

   if(pNextPage)
   {
      *pNextPage = pageNo;
   }

   return KAL_TRUE;
}

/**********************************************************
Description : Read the first page and check the GFH structure
Input       : None
Output      : None
***********************************************************/
kal_uint32 bl_ReadFileGFH(kal_uint32 flashBeginPage, kal_uint32 flashBoundPage, kal_uint32 *pNextPage, kal_uint32 *pReadLength)
{
   kal_uint32 target_addr;
   GFH_FILE_INFO_v1 *pGFHFileInfo;

   kal_uint32 page_no = flashBeginPage;
   kal_uint32 page_size = g_ftlFuncTbl->FTL_GetPageSize();
   kal_int32 to_read, read_part;

   pGFHFileInfo = (GFH_FILE_INFO_v1*)PAGE_BUFFER_ADDR;

   /* GFH_info should be smaller than one page */
   ASSERT(sizeof(GFH_FILE_INFO_v1) <= page_size);

   /* Read first page (GFH Info) to internal page buffer */
   if( ReadDataX((kal_uint32)pGFHFileInfo, page_no, page_size, KAL_TRUE, &page_no) == KAL_FALSE )
   {
      return INVALID_START_ADDR;
   }

   /* Sanity test of GFH */
   if( GFH_FILE_INFO_IsValid(pGFHFileInfo) != B_OK )
   {
      BL_PRINT(LOG_ERROR, "Invalid GFH File Info\n\r");
      return INVALID_START_ADDR;
   }

   /* Make sure the length of the data is still in the region */
   if( (pGFHFileInfo->m_file_len+page_size-1)/page_size + flashBeginPage > flashBoundPage )
   {
      BL_PRINT(LOG_ERROR, "file_len>bound_addr\n\r");
      return INVALID_START_ADDR;
   }

   target_addr = pGFHFileInfo->m_load_addr;
   
   /* Move the first page to its load address */
   memmove((kal_uint32*)(target_addr), (kal_uint32*)pGFHFileInfo, page_size);

   /* Read other GFHs */
   to_read = (kal_uint32)(((pGFHFileInfo->m_content_offset - page_size)+(page_size-1))/page_size)*page_size;
   
   read_part = to_read + page_size;
   
   if(to_read > 0)
   {
      if(ReadDataX(target_addr+page_size, page_no, to_read, KAL_TRUE, &page_no) == KAL_FALSE)
      {
         return INVALID_START_ADDR;
      }
   }

   if(pReadLength)
   {
      *pReadLength = read_part;
   }

   if(pNextPage)
   {
      *pNextPage = page_no;
   }
   
   return target_addr;
}

/**********************************************************
Description : Read the the binary body, with a given skiping length
Input       : pGFHFileInfo:   The binary load address. GFH has to be loaded already
              pageNo:         Starting page number
              readPart:       Read length
Output      : Original buffer address
***********************************************************/
kal_uint32 bl_ReadFileBody(GFH_FILE_INFO_v1 *pGFHFileInfo, kal_uint32 pageNo, kal_uint32 readPart)
{
   kal_uint32 page_size = g_ftlFuncTbl->FTL_GetPageSize();
   
   kal_uint32 to_read = (kal_uint32)(((pGFHFileInfo->m_file_len - readPart)+(page_size-1))/page_size)*page_size;
   
   if(to_read > 0)
   {
      if(ReadDataX(((kal_uint32)pGFHFileInfo)+readPart, pageNo, to_read, KAL_TRUE, NULL) == KAL_FALSE)
      {
         return INVALID_START_ADDR;
      }
   }

   return (kal_uint32)pGFHFileInfo;
}

#elif defined(__X_BOOTING__)
/**********************************************************
Description : Read the first page and check the GFH structure
Input       : None
Output      : None
***********************************************************/
kal_uint32 bl_ReadFileGFH(kal_uint32 flashBeginAddr, kal_uint32 flashBoundAddr, kal_uint32 *pNextAddr, kal_uint32 *pReadLength)
{
   kal_uint32 target_addr;
  
   GFH_FILE_INFO_v1 *pGFHFileInfo;
   kal_uint32 status;

   kal_int32 to_read, read_part;

   pGFHFileInfo = (GFH_FILE_INFO_v1*)PAGE_BUFFER_ADDR;

   //Send the get_bin command and measure the consuming time
   status = XbootCmd_GetBin(flashBeginAddr, sizeof(GFH_FILE_INFO_v1), (kal_uint32)pGFHFileInfo);
   
   if(status != 0)
   {
       BL_PRINT(LOG_ERROR, "ERROR: BL get bin fail. code:%x\r\n", status);
       return INVALID_START_ADDR;
   }
   
   BL_PRINT(LOG_DEBUG, "STATUS: BL get bin ok\r\n");

   /* Sanity test of GFH */
   if( GFH_FILE_INFO_IsValid(pGFHFileInfo) != B_OK )
   {
      BL_PRINT(LOG_ERROR, "Invalid GFH File Info\n\r");
      return INVALID_START_ADDR;
   }

   /* Make sure the length of the data is still in the region */
   if( pGFHFileInfo->m_file_len-1 + flashBeginAddr > flashBoundAddr )
   {
      BL_PRINT(LOG_ERROR, "file_len>bound_addr\n\r");
      return INVALID_START_ADDR;
   }

   target_addr = pGFHFileInfo->m_load_addr;
   
   /* Move the first part to its load address */
   memmove((kal_uint32*)(target_addr), (kal_uint32*)pGFHFileInfo, sizeof(GFH_FILE_INFO_v1));

   /* Read other GFHs */
   to_read = pGFHFileInfo->m_content_offset - sizeof(GFH_FILE_INFO_v1);
   
   read_part = pGFHFileInfo->m_content_offset;
   
   if(to_read > 0)
   {
      status = XbootCmd_GetBin(flashBeginAddr+sizeof(GFH_FILE_INFO_v1), to_read, target_addr+sizeof(GFH_FILE_INFO_v1));

      if(status != 0)
      {
         return INVALID_START_ADDR;
      }
   }

   if(pReadLength)
   {
      *pReadLength = read_part;
   }

   if(pNextAddr)
   {
      *pNextAddr = flashBeginAddr+read_part;
   }
   
   return target_addr;
}

/**********************************************************
Description : Read the the binary body, with a given skiping length
Input       : pGFHFileInfo:   The binary load address. GFH has to be loaded already
              pageNo:         Starting page number
              readPart:       Read length
Output      : Original buffer address
***********************************************************/
kal_uint32 bl_ReadFileBody(GFH_FILE_INFO_v1 *pGFHFileInfo, kal_uint32 flashAddr, kal_uint32 readPart)
{
   kal_uint32 status;
   kal_uint32 to_read = pGFHFileInfo->m_file_len - readPart;

   if(to_read > 0)
   {
      BL_PRINT(LOG_INFO, "Read file size %d Bytes\n\r",to_read);
      status = XbootCmd_GetBin(flashAddr, to_read, ((kal_uint32)pGFHFileInfo)+readPart);
      
      if(status != 0)
      {
         return INVALID_START_ADDR;
      }
   }

   return (kal_uint32)pGFHFileInfo;
}

#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ || __SERIAL_FLASH_EN__*/

#if defined(__X_BOOTING__)
/**********************************************************
Description : Function that sync AP side
Input       : None
Output      : None
***********************************************************/
kal_bool XBOOT_SyncWithAP(kal_uint32 *pTimeout)
{
    kal_uint32 cnt = 0;

    brom_sdio_sync_reset();      
    while(brom_sdio_sync()!=BROM_SDIO_SYNC_XBOOT){
        cnt++;
        if(cnt >= 10000){
            cnt = 0;
            BL_PRINT(LOG_WARN, "WARNING: BL sync with AP over 10000 times\r\n");
        }
    };
    BL_PRINT(LOG_DEBUG, "STATUS: BL sync with AP ok\r\n");

    *pTimeout = brom_sdio_get_timeout();

    return KAL_TRUE;
}

/**********************************************************
Description : Function that notifys AP side to load binary
Input       : None
Output      : None
***********************************************************/
kal_bool XBOOT_LoadBinaryStart(void)
{
   kal_uint32 status;
   
   // Let AP know we are going to load the binary
   status = XbootCmd_Status(BIN_LOAD_START, XBOOT_STAGE_BL);

   if(status != 0)
   {
      BL_PRINT(LOG_ERROR, "ERROR: BL start command fail. code:%x\r\n", status);
      return KAL_FALSE;
   }

   BL_PRINT(LOG_DEBUG, "STATUS: BL start command ok\r\n");
   return KAL_TRUE;   
}

/**********************************************************
Description : Function that notifys AP the loading process is done
Input       : None
Output      : None
***********************************************************/
kal_bool XBOOT_LoadBinaryEnd(void)
{
   kal_uint32 status;
   
   //4. Notify AP that binary-loading in BL is finished.
   status = XbootCmd_Status(BIN_LOAD_END, XBOOT_OK);
   if(status != B_OK)
   {
       BL_PRINT(LOG_ERROR, "ERROR: BL start command fail. code:%x\r\n",status);
       return KAL_FALSE;
   }
   
   BL_PRINT(LOG_DEBUG, "STATUS: BL bin load end command ok\r\n");
   return KAL_TRUE;
}

/**********************************************************
Description : Function that notifys AP the booting process is done
Input       : None
Output      : None
***********************************************************/
kal_bool XBOOT_BootEnd(void)
{
   kal_uint32 status;
   
   //Since the AP side is in the state where only it only accepts MAILBOX message
   //Need to resync to it and force it to Load Binary state
   if(XBOOT_SyncWithAP(NULL) == KAL_FALSE || XBOOT_LoadBinaryStart() == KAL_FALSE)
   {
      return KAL_FALSE;
   }

   //5. Notify AP that xbooting is finished, AP can leave "bootup MD mode"
   status = XbootCmd_Status(MD_BOOT_END, XBOOT_OK);
   if(status != B_OK)
   {
       BL_PRINT(LOG_ERROR, "ERROR: BL end command fail. code:%x\r\n",status);
       return KAL_FALSE;
   }
   
   BL_PRINT(LOG_DEBUG, "STATUS: BL MD boot end command ok\r\n");
   return KAL_TRUE;
}

#endif /* __X_BOOTING__ */

#if defined(__AP_BOOTUP_BY_MDBL__)
/**********************************************************
Description : Setup power/reset/clock to enable AP
Input       : None
Output      : None
***********************************************************/
void bl_BringUpAP()
{
    BL_PRINT(LOG_INFO, "Bring up AP\n\r");

    //Power on AP
    bl_topsm_power_on_ap();

    // Enable APCA7_CGEN
    enable_ap_clk();

    //unlock AP reset
    bl_wdt_unlock_ap_rst();
}
#endif /*__AP_BOOTUP_BY_MDBL__*/

#ifdef __MINI_BOOTLOADER__

/**********************************************************
Description : Read Ext Bootloader from bootloader
Input       : None
Output      : None
***********************************************************/
kal_uint32 bl_ReadExtBootloaderFromFlash(kal_uint32 flashBegin, kal_uint32 flashBound)
{
   kal_uint32 page, readLen;
   kal_uint32 targetAddr;
   GFH_FILE_INFO_v1* pExtBlGFH;

   targetAddr = bl_ReadFileGFH(flashBegin, flashBound, &page, &readLen);
   pExtBlGFH = (GFH_FILE_INFO_v1*)targetAddr;

   if(targetAddr == INVALID_START_ADDR)
   {
      BL_PRINT(LOG_CRIT, "No ExtBL GFH found\n\r");
      return INVALID_START_ADDR;
   }

   //Do sanity test again on loaded GFH to detect EMI failure
   if( GFH_FILE_INFO_IsValid(pExtBlGFH) != B_OK )
   {
      BL_PRINT(LOG_ERROR, "Re-check ExtBL GFH failed. May be EMI problem!!\r");
      return INVALID_START_ADDR;
   }

   targetAddr = bl_ReadFileBody(pExtBlGFH, page, readLen);
   if(targetAddr == INVALID_START_ADDR)
   {
      BL_PRINT(LOG_CRIT, "Read ExtBL Body failed\n\r");
      return INVALID_START_ADDR;
   }

   return targetAddr;
}

/**********************************************************
Description : Read Ext Bootloader from bootloader
Input       : None
Output      : None
***********************************************************/
kal_uint32 bl_ReadExtBootloaderContent()
{
    kal_uint32 target_addr = INVALID_START_ADDR;
    kal_uint32 ext_bl_start;

    INT_Trace_Enter(BL_LOAD_EXT_BOOTLOADER_BODY);

#ifdef __X_BOOTING__

    if(XBOOT_LoadBinaryStart() != KAL_FALSE)
    {
        if(bl_imgtbl_get_region_info(g_cs_bl_param->img_param, IMG_EXT_BL_VAL, &ext_bl_start) == KAL_FALSE){
            BL_PRINT(LOG_CRIT, "Error when loading ExtBootloader entry from image parameter\n\r");
            goto _end;
        }        

        //Need to mutiply offset read from img param with 256
        ext_bl_start = ext_bl_start << 8;
    
        target_addr = bl_ReadExtBootloaderFromFlash(ext_bl_start, ext_bl_start+BL_MAX_SIZE);

        if(XBOOT_LoadBinaryEnd() == KAL_FALSE)
        {
            target_addr = INVALID_START_ADDR;
        }
    }

#else  
    
    if(bl_imgtbl_get_region_info(g_cs_bl_param->img_param, IMG_EXT_BL_VAL, &ext_bl_start) == KAL_FALSE){
        BL_PRINT(LOG_CRIT, "Error when loading ExtBootloader entry from image parameter\n\r");
        goto _end;
    }

    // Todo: check page bound
    //Assume max page of BL
    target_addr = bl_ReadExtBootloaderFromFlash(ext_bl_start, ext_bl_start+BL_MAX_PAGE);

#endif
    
_end:

   if(target_addr != INVALID_START_ADDR)
   {
      TS_INFO(TSID_BL_LOAD_EXT_BOOTLOADER_BODY, 0, ((GFH_FILE_INFO_v1*)(target_addr))->m_file_len, 0);
   }

   INT_Trace_Exit(BL_LOAD_EXT_BOOTLOADER_BODY);
    
    return target_addr;
}

/**********************************************************
Description : Exported API for loading ExtBootloader
Input       : None
Output      : None
***********************************************************/
#if defined(__USB_FW_DL_SUPPORT__)
extern void FDA_Main(void);
kal_int32 LoadExtBootloader(void)
{
    //jumpt to FDA_Main() for FDA work
    FDA_Main();
    return KAL_TRUE;
}
#else /*__USB_FW_DL_SUPPORT__*/
kal_uint32 LoadExtBootloader()
{
    kal_uint32 ext_bl_addr = INVALID_START_ADDR;

   INT_Trace_Enter(BL_LOAD_EXT_BOOTLOADER);

    BL_PRINT(LOG_DEBUG, "Flash Driver Init\n\r");
    INT_Trace_Enter(BL_INIT_MINI_FLASH_DRV);
    InitFlashDriver();
    INT_Trace_Exit(BL_INIT_MINI_FLASH_DRV);
    
    ext_bl_addr = bl_ReadExtBootloaderContent();
    
    if( ext_bl_addr == INVALID_START_ADDR)
    {
        BL_PRINT(LOG_CRIT, "Error when loading ExtBootloader\n\r");
        return INVALID_START_ADDR;
    }

    if(ext_bl_addr != ((GFH_FILE_INFO_v1*)(ext_bl_addr))->m_load_addr)
    {
        BL_PRINT(LOG_ERROR, "Mismatched load address\n\r");
        return INVALID_START_ADDR;
    }

   INT_Trace_Exit(BL_LOAD_EXT_BOOTLOADER);

    return ext_bl_addr;

}
#endif /*__USB_FW_DL_SUPPORT__*/

#if defined(__AP_BOOTUP_BY_MDBL__)

/**********************************************************
Description : Get the first block next to bootloader region
Input       : None
Output      : Return 
***********************************************************/
kal_uint32 GetMainRegionStartBlock(void)
{
    kal_uint32 page_per_block = g_ftlFuncTbl->FTL_GetBlockSize(0, NULL)/g_ftlFuncTbl->FTL_GetPageSize();
    kal_uint32 page;

    if(bl_imgtbl_get_region_info(g_cs_bl_param->img_param, IMG_CBR_VAL, &page) == KAL_TRUE){
            return page/page_per_block;
    }

    return 0;
}

/**********************************************************
Description : load image list information.
Input       : start_blk: start block of searching
Output      : Return if Image List or backup is loaded
Assumptions : FUE image is programmed to flash in block aligned manner
***********************************************************/
kal_bool LoadFlashLayout(kal_uint32 start_blk, FlashLayout* layout)
{
    extern FTL_FuncTbl *g_ftlFuncTbl;

    kal_int32 status;
    kal_bool ret = KAL_TRUE;

    CBR_SetEnv(E_CBR_IDX_CBR, (kal_uint32*)PAGE_BUFFER_ADDR, 8192, g_ftlFuncTbl);
    
    status = CBR_Init(E_CBR_IDX_CBR, start_blk);
    if(status != CBR_SUCCESS)
    {
        if(status == CBR_NO_BLOCK_FOUND)
        {
             BL_PRINT(LOG_INFO, "No CBR is found\n\r");
             ret = KAL_FALSE;
             goto _error;
        }

        BL_PRINT(LOG_ERROR, "Serious error in CBR, %d\n\r", status);
        ret = KAL_FALSE;
        goto _error;

    }

    status = CBR_ReadRecord(E_CBR_IDX_CBR, CBR_RECORD_FLASH_LAYOUT, (kal_uint8*)layout, sizeof(FlashLayout), NULL);

    if(status < CBR_SUCCESS)
    {
        BL_PRINT(LOG_ERROR, "Unable to read FlashLayout, %d\n\r", status);
        ret = KAL_FALSE;
        goto _error;
    }

_error:

    return ret;
}

kal_bool GetRegionInfo(GFH_FILE_TYPE type, FlashLayout *pFlashLayout, kal_uint32 *pStart, kal_uint32 *pBoundary )
{
   kal_uint32 found = KAL_FALSE;
   kal_uint32 i;
   
   for( i=0 ;i<pFlashLayout->regionCount; i++ )
   {
      if( pFlashLayout->region[i].binaryType == type )
      {
         if(pStart)
         {
            *pStart = pFlashLayout->region[i].u.nandEmmc.startPage;
         }
         if(pBoundary)
         {
            *pBoundary = pFlashLayout->region[i].u.nandEmmc.boundPage;
         }
         found = KAL_TRUE;
         break;
      }
   }

   return found;
}

/**********************************************************
Description : Read Ap Bootloader from flash
Input       : None
Output      : None
***********************************************************/
kal_uint32 bl_ReadApBootloaderFromFlash(kal_uint32 flashBegin, kal_uint32 flashBound)
{
   kal_uint32 page, readLen;
   kal_uint32 targetAddr;
   GFH_FILE_INFO_v1* pApBlGFH;

   targetAddr = bl_ReadFileGFH(flashBegin, flashBound, &page, &readLen);
   pApBlGFH = (GFH_FILE_INFO_v1*)targetAddr;

   if(targetAddr == INVALID_START_ADDR)
   {
      BL_PRINT(LOG_CRIT, "No ApBL GFH found\n\r");
      return INVALID_START_ADDR;
   }

   //Do sanity test again on loaded GFH to detect EMI failure
   if( GFH_FILE_INFO_IsValid(pApBlGFH) != B_OK )
   {
      BL_PRINT(LOG_ERROR, "Re-check ApBL GFH failed. May be EMI problem!!\r");
      return INVALID_START_ADDR;
   }

   targetAddr = bl_ReadFileBody(pApBlGFH, page, readLen);
   if(targetAddr == INVALID_START_ADDR)
   {
      BL_PRINT(LOG_CRIT, "Read ApBL Body failed\n\r");
      return INVALID_START_ADDR;
   }

   return targetAddr;
}

/**********************************************************
Description : Read Ap Bootloader from bootloader
Input       : None
Output      : None
***********************************************************/
kal_uint32 bl_ReadApBootloaderContent()
{
    kal_uint32 target_addr = INVALID_START_ADDR;
    kal_uint32 ap_bl_start;
    
   INT_Trace_Enter(BL_LOAD_AP_BOOTLOADER_BODY);

    if(bl_imgtbl_get_region_info(g_cs_bl_param->img_param, IMG_AP_BL_VAL, &ap_bl_start) == KAL_FALSE){
        BL_PRINT(LOG_CRIT, "Error when loading Ap Bootloader entry from image parameter\n\r");
        goto _end;
    }

    // Todo: check page bound
    //Assume max page of BL
    target_addr = bl_ReadApBootloaderFromFlash(ap_bl_start, ap_bl_start+BL_MAX_PAGE);

_end:

    if(target_addr != INVALID_START_ADDR)
    {
        TS_INFO(TSID_BL_LOAD_AP_BOOTLOADER_BODY, 0, ((GFH_FILE_INFO_v1*)(target_addr))->m_file_len, 0);
    }

    INT_Trace_Exit(BL_LOAD_AP_BOOTLOADER_BODY);
    
    return target_addr;
}

/**********************************************************
Description : WDT counter clearing triggered by AP
Input       : None
Output      : None
***********************************************************/
void ApWdtClearProceture()
{
    kal_uint32 status;

    bl_topsm_get_retention(&status, RETENTION_CLEAR_WDT_REG_NUM);

    BL_PRINT(LOG_INFO, "AP WDT clear: %x\n\r", status);

    if(status == AP_WDT_CLEAR_TRIGGERED){

        //Clear AP reset conter 
        bl_wdt_clear_ap_cnt();
        bl_topsm_set_retention(AP_WDT_CLEAR_DONE, RETENTION_CLEAR_WDT_REG_NUM);
    }
}

/**********************************************************
Description : Factory procedure with AP
Input       : None
Output      : None
***********************************************************/
void ApFactoryProceture()
{
    kal_uint32 status;

    bl_topsm_get_retention(&status, RETENTION_META_REG_NUM);

    BL_PRINT(LOG_INFO, "AP Factory: %x\n\r", status);

    if(status == AP_FACTORY_ENTER_USB_DL){

#ifndef AP_BOOT_WITH_BROM_COM 

        BL_PRINT(LOG_INFO, "AP Factory: trigger meta mode\n\r");
        TriggerMetaMode();

        //Set the channel type to CCCI 
        g_cs_bl_param->sync_chl_type = CHL_CCCI;
        
#else /*AP_BOOT_WITH_BROM_COM*/ s

#ifdef __USB_DWONLOAD__

        BL_PRINT(LOG_INFO, "AP Factory: trigger bootloader usb mode\n\r");

        bl_topsm_set_retention(AP_FACTORY_TRIGGER_META, RETENTION_META_REG_NUM);

        TriggerBlDL();

#else /*__USB_DWONLOAD__*/
        BL_PRINT(LOG_INFO, "AP Factory: trigger bootrom usb mode\n\r");

        bl_topsm_set_retention(AP_FACTORY_TRIGGER_META, RETENTION_META_REG_NUM);

        TriggerBromDL();

        //Trigger WDT reset
        bl_wdt_force_reset(1);

        //Wait for WDT reset
        while(1);
#endif /*__USB_DWONLOAD__*/
        
#endif /*AP_BOOT_WITH_BROM_COM*/ 
        
    }else if(status == AP_FACTORY_TRIGGER_META){

        BL_PRINT(LOG_INFO, "AP Factory: trigger meta mode\n\r");

        //Set the channel type to CCCI 
        g_cs_bl_param->sync_chl_type = CHL_CCCI;

        TriggerMetaMode();
    } else if (IsMetaModeEnabled()) {
        
        BL_PRINT(LOG_INFO, "AP Factory: trigger meta mode\n\r");
        bl_topsm_set_retention(AP_FACTORY_TRIGGER_META, RETENTION_META_REG_NUM);

        //Set the channel type to CCCI 
        g_cs_bl_param->sync_chl_type = CHL_CCCI;
    }
}

/**********************************************************
Description : Init the share parameter shared with AP BL
Input       : None
Output      : None
***********************************************************/
kal_bool ApBlShareInfoInit(kal_uint32 ap_offset)
{
    BOOT_ARGUMENT *boot_arg = (BOOT_ARGUMENT *)(ap_offset+BOOT_ARGUMENT_LOCATION);
    FlashLayout layout;
    kal_uint32 start_page, bound_page;
    kal_uint32 idx = 0;

    boot_arg->magic_number = BOOT_ARGUMENT_MAGIC;

    /*
     * Pass MD flash layout to AP for firmware upgrade 
     */
    if(LoadFlashLayout(GetMainRegionStartBlock(), &layout) != KAL_TRUE){
        BL_PRINT(LOG_ERROR, "Cannot find flash layout\n\r");
        return KAL_FALSE;
    }

    if(GetRegionInfo(PRIMARY_MAUI, &layout, &start_page, &bound_page) != KAL_TRUE){
        BL_PRINT(LOG_ERROR, "Flash layout infor of primary rom\n\r");
        return KAL_FALSE;
    }

    //Info of primary rom
    boot_arg->mdbin_info[idx].index = SHARE_MEM_ITEM_LTE;
    boot_arg->mdbin_info[idx].version = BOOT_ARGUMENT_MDINFO_VERSION;
    boot_arg->mdbin_info[idx].start = start_page;
    boot_arg->mdbin_info[idx].bound = bound_page;
    idx++;

    if(GetRegionInfo(LTE_DSP_ROM, &layout, &start_page, &bound_page) != KAL_TRUE){
        BL_PRINT(LOG_ERROR, "Flash layout infor of lte dsp rom\n\r");
        return KAL_FALSE;
    }

    //Info of LTE dsp
    boot_arg->mdbin_info[idx].index = SHARE_MEM_ITEM_DSP;
    boot_arg->mdbin_info[idx].version = BOOT_ARGUMENT_MDINFO_VERSION;
    boot_arg->mdbin_info[idx].start = start_page;
    boot_arg->mdbin_info[idx].bound = bound_page;

#ifdef _NAND_FLASH_BOOTING_
    if(NFB_SyncFlashInfo((void *)&(boot_arg->nfi_info), sizeof(boot_arg->nfi_info)) != ERROR_NFB_SUCCESS){
        BL_PRINT(LOG_ERROR, "NAND driver info sync fail\n\r");
        return KAL_FALSE;
    }
#endif /*_NAND_FLASH_BOOTING_*/

    return KAL_TRUE;
}

/**********************************************************
Description : Exported API for loading and runing ApBootloader
Input       : None
Output      : None
***********************************************************/
kal_uint32 LoadAndRunApBootloader()
{
    kal_uint32 ap_bl_addr = INVALID_START_ADDR;
    drv_ramc_dram_info_t dram_info;

    INT_Trace_Enter(BL_LOAD_AP_BOOTLOADER);

    BL_PRINT(LOG_INFO, "Flash Driver Init\n\r");
    INT_Trace_Enter(BL_INIT_MINI_FLASH_DRV_FOR_AP);
    InitFlashDriver();
    INT_Trace_Exit(BL_INIT_MINI_FLASH_DRV_FOR_AP);

    ApWdtClearProceture();
    ApFactoryProceture();

    bl_wdt_restart();   

    ap_bl_addr = bl_ReadApBootloaderContent();
    
    bl_wdt_restart();   

    //Todo: check bootloader integrity
    
    if( ap_bl_addr == INVALID_START_ADDR)
    {
        BL_PRINT(LOG_CRIT, "Error when loading ApBootloader\n\r");
        return INVALID_START_ADDR;
    }

    if(ap_bl_addr != ((GFH_FILE_INFO_v1*)(ap_bl_addr))->m_load_addr)
    {
        BL_PRINT(LOG_ERROR, "Mismatched Ap Bootloader load address\n\r");
        return INVALID_START_ADDR;
    }

    //The load address should be the same as AP DRAM offset
    drv_ramc_get_dram_info(&dram_info);
    if(ap_bl_addr != dram_info.apmcu_ofst)
    {
         BL_PRINT(LOG_ERROR, "Mismatched Ap Bootloader load address and AP offset (%x)\n\r", dram_info.apmcu_ofst);
         return INVALID_START_ADDR;       
    }

    if(ApBlShareInfoInit(dram_info.apmcu_ofst) != KAL_TRUE){
        BL_PRINT(LOG_ERROR, "Fail to initializa parameters shared with AP\n\r");
        return INVALID_START_ADDR;       
    }

    //set AP jump instruction to 0x1000
    *(volatile unsigned *)ap_bl_addr = 0xbffef000;
    //set magic number to disable AP preloader waiting flow
    *(volatile unsigned *)(ap_bl_addr+0x4) = 0x24542454;

#if defined(__USB_DOWNLOAD__) || defined(__UART_DOWNLOAD__)
    if(IsBlUsbDLModeEnabled() == KAL_FALSE)
#endif /*__USB_DOWNLOAD__ || __UART_DOWNLOAD__*/
    {
        bl_BringUpAP();

        //Enable wdt interrupt mode to let AP handle the MD wdt reset
        bl_wdt_intr_enable();
    }

    INT_Trace_Exit(BL_LOAD_AP_BOOTLOADER);

    return ap_bl_addr;
}
#endif /* __AP_BOOTUP_BY_MDBL__ */

#endif /* __MINI_BOOTLOADER__ */

#ifdef __EXT_BOOTLOADER__

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) || defined(__SERIAL_FLASH_EN__)

/**********************************************************
Description : load image list information.
Input       : start_blk: start block of searching
Output      : Return if Image List or backup is loaded
Assumptions : FUE image is programmed to flash in block aligned manner
***********************************************************/
kal_bool LoadImageListblock(kal_uint32 start_blk)
{
    extern FTL_FuncTbl *g_ftlFuncTbl;

    kal_int32 status;
    kal_bool ret = KAL_TRUE;

    INT_Trace_Enter(BL_LOAD_ILB_CBR);

    CBR_SetEnv(E_CBR_IDX_CBR, (kal_uint32*)PAGE_BUFFER_ADDR, 8192, g_ftlFuncTbl);

    INT_Trace_Enter(BL_INIT_CBR);
    status = CBR_Init(E_CBR_IDX_CBR, start_blk);
    INT_Trace_Exit(BL_INIT_CBR);

    if(status != CBR_SUCCESS)
    {
        if(status == CBR_NO_BLOCK_FOUND)
        {
             BL_PRINT(LOG_INFO, "No CBR is found\n\r");
             goto _error;
        }

        BL_PRINT(LOG_ERROR, "Serious error in CBR, %d\n\r", status);
        ret = KAL_FALSE;
        goto _error;

    }

    INT_Trace_Enter(BL_READ_FLASH_LAYOUT_INFO);
    status = CBR_ReadRecord(E_CBR_IDX_CBR, CBR_RECORD_FLASH_LAYOUT, (kal_uint8*)&BL_Shared_info.m_bl_flash_layout, sizeof(FlashLayout), NULL);

    if(status < CBR_SUCCESS)
    {
        BL_PRINT(LOG_ERROR, "Unable to read FlashLayout, %d\n\r", status);
        goto _error;
    }

    status = CBR_ReadRecord(E_CBR_IDX_CBR, CBR_RECORD_MAUI_INFO, (kal_uint8*)&g_mauiInfoBuf, sizeof(g_mauiInfoBuf), NULL);

    if(status >= CBR_SUCCESS)
    {
        g_mauiInfoRead = KAL_TRUE;
    }

    INT_Trace_Exit(BL_READ_FLASH_LAYOUT_INFO);       

    INT_Trace_Exit(BL_LOAD_ILB_CBR);
    return ret;

_error:
    g_bootupDisabled = KAL_TRUE;   
    g_bootupStatus = BL_BOOTUP_FAIL_REASON_UNABLE_TO_READ_ILB;
    return ret;
}

#endif /* defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) || defined(__SERIAL_FLASH_EN__) */

/**********************************************************
Description : Load boot_cert 
Input       : None
Output      : None
***********************************************************/
static void bl_ReadBootCert(void)
{
    //todo: check after security    

#if 0 /*LTE TBD*/
#if defined(__NFB_SINGLE_ROM__) && defined(_NAND_FLASH_BOOTING_) && defined(__BOOT_CERT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /*LTE TBD*/

   return;
}

/**********************************************************
Description : Load rest part of Primary 
Input       : None
Output      : None
***********************************************************/
kal_uint32 LoadMauiBody(void)
{
   kal_uint32 addr;

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) || defined(__XIP_SHADOWING__) || defined(__X_BOOTING__) || defined(__SERIAL_FLASH_EN__)

    INT_Trace_Enter(BL_LOAD_MAUI_BODY);
    TS_INFO(TSID_BL_LOAD_MAUI_BODY, ((GFH_FILE_INFO_v1*)g_maui_load_addr)->m_file_len, ((GFH_FILE_INFO_v1*)g_maui_load_addr)->m_file_len-mauiReadLen, g_maui_load_addr);
#if !defined(__IC_SLT_LOADER__)
    addr = bl_ReadFileBody((GFH_FILE_INFO_v1*)g_maui_load_addr, restMauiFlashAddr, mauiReadLen);
#else
    addr = bl_SLTReadHVTBody((GFH_FILE_INFO_v1*)g_maui_load_addr, restMauiFlashAddr, mauiReadLen);
#endif
    INT_Trace_Exit(BL_LOAD_MAUI_BODY);

#if defined(__X_BOOTING__)
    if(XBOOT_LoadBinaryEnd() == KAL_FALSE)
    {
        addr = INVALID_START_ADDR;
    }
#endif /* __X_BOOTING__ */

    if(addr == INVALID_START_ADDR)
    {
        BL_PRINT(LOG_ERROR, "Loading MAUI body failed\n\r");
        g_bootupDisabled = KAL_TRUE;
        g_bootupStatus = BL_BOOTUP_FAIL_LOADING_MAUI_BODY_ERROR;
        return addr;
    }

#else

    addr = g_maui_load_addr;

#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ || __XIP_SHADOWING__ */

    bl_ReadBootCert();

#ifdef __MTK_SECURE_PLATFORM__

    if(addr != INVALID_START_ADDR)
    {
        BL_PRINT(LOG_INFO, "Verify MAUI body\n\r");
    
        SwitchMAUIToCacheable(KAL_TRUE, 0);

        /* Do check on the next binary */
        INT_Trace_Enter(BL_VERIFY_MAUI);
        SST_VerifyMAUI((kal_uint32*)&g_ext_bootloader_gfh, (kal_uint32*)addr);
        INT_Trace_Exit(BL_VERIFY_MAUI);

        SwitchMAUIToCacheable(KAL_FALSE, 0);
    }
 
#endif /* __MTK_SECURE_PLATFORM__ */

   return addr;
}

/**********************************************************
Description : Read MAUI's first GFH to its load address
Input       : None
Output      : None
***********************************************************/
BL_STATUS LoadMAUIFirstPart(void)
{
    kal_uint32 mauiFlashAddr = INVALID_START_ADDR;

    const kal_uint32 loadSequence[][2] = { 
      {PRIMARY_MAUI, PRIMARY_FACTORY_BIN},  //For Normal mode, try to lunch MAUI first
      {PRIMARY_FACTORY_BIN, PRIMARY_MAUI},  //For META mode, try to lunch FactoryBin first
    };

    kal_int32 currentLoadSequence = 0;
    kal_int32 i;

    INT_Trace_Enter(BL_LOAD_MAUI_FIRST_PART);

   //Find the proper binary to load -- MAUI or FACTORY bin
   if(IsMetaModeEnabled())
   {
      currentLoadSequence = 1;
   }

    for(i=0; i<sizeof(loadSequence[0])/sizeof(loadSequence[0][0]); i++)
    {
        mauiFlashAddr = GetBinaryStartInFlash(loadSequence[currentLoadSequence][i]);

        if(mauiFlashAddr != INVALID_START_ADDR)
        {
            if(loadSequence[currentLoadSequence][i] == PRIMARY_FACTORY_BIN)
            {
                BL_PRINT(LOG_INFO, "Launching FactoryBin in Combine mode...\r\n");
            }

            break;
        }  
    }

#if defined(__X_BOOTING__)
    if(XBOOT_LoadBinaryStart() == KAL_FALSE)
    {
        mauiFlashAddr = INVALID_START_ADDR;
    }
#endif /* __X_BOOTING__ */

   if(mauiFlashAddr != INVALID_START_ADDR)
   {
#if defined(__NAND_BOOT__) || defined(__EMMC_BOOT__) || defined(__XIP_SHADOWING__) || defined(__X_BOOTING__) || defined(__SF_BOOT__)

      g_maui_load_addr = bl_ReadFileGFH(mauiFlashAddr, MAX_FLASH_BOUNDARY, &restMauiFlashAddr, &mauiReadLen);

#elif defined(__NOR_BOOT__)

      if(GFH_FILE_INFO_IsValid((GFH_FILE_INFO_v1*)mauiFlashAddr) == 0)
      {
         g_maui_load_addr = mauiFlashAddr;
      }
      else
      {
         BL_PRINT(LOG_ERROR, "Invalid MAUI GFH, addr=%x\n\r", mauiFlashAddr);
      }

#endif

      if(g_maui_load_addr == INVALID_START_ADDR)
      {
         BL_PRINT(LOG_ERROR, "Failed to get MAUI's first part\n\r");
         return BL_ERROR;
      }
   }
   else
   {
      BL_PRINT(LOG_ERROR, "No MAUI binary in FlashLayout or Flash\n\r");

      g_bootupDisabled = KAL_TRUE;
      g_bootupStatus = BL_BOOTUP_FAIL_LOADING_MAUI_HEAD_ERROR;
   }

   INT_Trace_Exit(BL_LOAD_MAUI_FIRST_PART);

   return BL_ERROR_NONE;
}

/**********************************************************
Description : Get the first block next to bootloader region
Input       : None
Output      : Return 
***********************************************************/
kal_uint32 GetMainRegionStartBlock(void)
{
    kal_uint32 page_per_block = g_ftlFuncTbl->FTL_GetBlockSize(0, NULL)/g_ftlFuncTbl->FTL_GetPageSize();
    kal_uint32 page;

    if(bl_imgtbl_get_region_info(&g_mini_ext_bl_param.img_param, IMG_CBR_VAL, &page) == KAL_TRUE){
            return page/page_per_block;
    }

    return 0;
}

/**********************************************************
Description : Search the flash layout structure to find the binary region
Input       : Binary type
Output      : The region the binary may occupy
              NAND, eMMC => page index
              NOR, Serial flash => Address
***********************************************************/
kal_bool GetBinaryRegionInFlash(GFH_FILE_TYPE type, kal_uint32 *pStart, kal_uint32 *pBoundary )
{
   kal_uint32 found = KAL_FALSE;
   
#if defined(__NAND_BOOT__) || defined(__EMMC_BOOT__) || defined(__SF_BOOT__)
   kal_uint32 i;
   FlashLayout *pFlashLayout = (FlashLayout*)&BL_Shared_info.m_bl_flash_layout;
   
   for( i=0 ;i<pFlashLayout->regionCount; i++ )
   {
      if( pFlashLayout->region[i].binaryType == type )
      {
         if(pStart)
         {
            *pStart = pFlashLayout->region[i].u.nandEmmc.startPage;
         }
         if(pBoundary)
         {
            *pBoundary = pFlashLayout->region[i].u.nandEmmc.boundPage;
         }
         found = KAL_TRUE;
         break;
      }
   }
#elif defined(__NOR_BOOT__)

   kal_uint32 targetAddr = INVALID_START_ADDR;

   if(type == PRIMARY_MAUI)
   {
      targetAddr = MAUI_START_ADDR_NOR;
   }
   else if(type == PRIMARY_FACTORY_BIN)
   {
      targetAddr = FACTORY_BIN_START_ADDR_NOR;
   }

   if(targetAddr != INVALID_START_ADDR)
   {
      GFH_FILE_INFO_v1 *pGFHFileInfo = (GFH_FILE_INFO_v1*)MapToCurrentFlashAddr(targetAddr);

      if( GFH_FILE_INFO_IsValid(pGFHFileInfo) == B_OK )
      {
         kal_uint32 boundaryAddr;
         
         if(pGFHFileInfo->m_max_size != GFH_FILE_MAX_SIZE_IGNORED)
         {
            boundaryAddr = (kal_uint32)(pGFHFileInfo) + pGFHFileInfo->m_max_size - 1;
         }
         else
         {
            boundaryAddr = (kal_uint32)(pGFHFileInfo) + pGFHFileInfo->m_file_len - 1;
         }
            
         if( pGFHFileInfo->m_file_type == type )
         {
            if(pStart)
            {
               *pStart = (kal_uint32)pGFHFileInfo;
            }
            if(pBoundary)
            {
               *pBoundary = boundaryAddr;
            }
            found = KAL_TRUE;
         }
      }
   }
#elif defined(__X_BOOTING__)
    if(type == PRIMARY_MAUI)
    {    
        if(pStart)
        {
            if(bl_imgtbl_get_region_info(&g_mini_ext_bl_param.img_param, IMG_PRIMARY_ROM_VAL, pStart) == KAL_FALSE){
                BL_PRINT(LOG_CRIT, "Error when loading primary rom entry from image parameter\n\r");
                goto _end;
            }

            //Need to mutiply offset read from img param with 256
            *pStart = *pStart << 8;  
        }

        if(pBoundary)
        {
            *pBoundary = 0xffffffff;
        }
        found = KAL_TRUE;
    }

_end:
    
#endif

   return found;
}

/**********************************************************
Description : Get the starting address of specified binary type
Input       : None
Output      : Starting address
              NAND, eMMC => page index
              NOR, Serial flash => Address
***********************************************************/
kal_uint32 GetBinaryStartInFlash(GFH_FILE_TYPE type)
{
   kal_uint32 found = KAL_FALSE;
   kal_uint32 start;
   
   found = GetBinaryRegionInFlash(type, &start, NULL);

   return found ? start : INVALID_START_ADDR;

}

GFH_MAUI_INFO_v1 *bl_GetMAUIInfo(void)
{
   GFH_MAUI_INFO_v1 *pMauiInfo = NULL;
   kal_uint32 status;

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) || defined(__SERIAL_FLASH_EN__)
   if(g_mauiInfoRead)
   {
      pMauiInfo = (GFH_MAUI_INFO_v1*)&g_mauiInfoBuf;
   }
#endif   

   if(!pMauiInfo)
   {
      if(g_maui_load_addr != INVALID_START_ADDR)
      {
         status = GFH_Find(g_maui_load_addr, GFH_MAUI_INFO, (void*)&pMauiInfo);
         
         if(status != B_OK)
         {
            pMauiInfo = NULL;
         }
      }
   }

   if(!pMauiInfo)
   {
      BL_PRINT(LOG_INFO, "No MAUI INFO found in MAUI bin\n\r");
   }

   return pMauiInfo;
}

#ifdef __IC_SLT_LOADER__

void bl_SetRestFlashAddr(kal_uint32 FlashAddr)
{
    restMauiFlashAddr = FlashAddr;
}

void bl_SetReadLen(kal_uint32 ReadLen)
{
    mauiReadLen = ReadLen;
}

kal_uint32 bl_GetPageBufferAddr(void)
{
    return PAGE_BUFFER_ADDR;
}

#endif

#endif /* __EXT_BOOTLOADER__ */
