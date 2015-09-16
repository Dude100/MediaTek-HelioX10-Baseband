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
 *   custom_flash_norfdm5.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   defines prototypes and data structure which will be used in NOR FDM 5.0
 *
 * Author:
 * -------
 * -------
 *
 *   Memory Device database last modified on 2011/7/8
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "fat_fs.h"
#include "DrvFlash.h"
#include "flash_opt.h"
#include "custom_MemoryDevice.h"

#include "custom_nvram_int_config.h"  /* To get NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM for MSTABLE_ENTRY_NUM */


#ifdef __NOR_FDM5__
#include "custom_flash_norfdm5.h"

#define STORAGE_NO_PARTITION 0xFFFFFFFF


/*-------------------------------------------------------------------
 * MS table size
 *
 * MS table size should be synchronized with user's requirement. The only one user is NVRAM.
 *
 * NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM defines the maximum record size in NVRAM
 * (in custom_nvram_config.h). NVRAM should call NOR_ResumeSectorState (by FS_Commit)
 * after it writes maximum NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM sectors with protection
 * mode to ensure the integrity of a record.
 *
 * MSTABLE_ENTRY_NUM number is based on the worst senario: All FAT entries of clusters
 * of logical sectors are located in different physical sectors. In other word, we need
 * to write additional N sectors to update FAT after we write N data sectors. The other
 * 1 sector is for directory entry update.
 *
 * TODO: Use auto-gen to compute most suitable MS table size. Because the number of
 * sectors for FAT may be smaller than NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM. For example,
 * 64KB disk only needs 1 sector to store FAT.
 *---------------------------------------------------------- W08.50 --*/

#define MS_TABLE_ENTRY_NUM    (NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM * 2 + 1)


/*****************************************
 * Don't modify any code above this line *
 *****************************************/

/*******************************************************************************
   Follow the 4 steps below to configure flash memory
              
   Step 1. Fill the flash bank (partition) information table,
           flash device features flexible, multi-bank read-while-program and 
           read-while-erase capability, enabling background programming or erasing in 
           one bank simultaneously with code execution or data reads in another bank.
           Each element in the table is the format as below:
           {bank size, bank number},   
                          
   Step 2. Modify the value of LSMT, you can see MemoryDevice_FlashDisk_FAQ for 
           detail information
      
   Step 2. Define the toal sectors (512bytes) of system drive
           the remainder is the size of public drive
           If there is no partiton (just one drive, system drive)
           set this value to STORAGE_NO_PARTITION (0xFFFFFFFF) 
 
           
   Note : Code region and FAT region can not share the same bank (partition)
*******************************************************************************/


/***********
 * Step 1. *
 ***********/
static NORBankInfo BankInfo[] =
{
   NOR_FDM5_BANK_INFO_LAYOUT
   EndBankInfo /* Don't modify this line */
};


/*****************************************
 * Don't modify any code below this line *
 *****************************************/

#define NOR_TOTAL_BLOCKS (NOR_ALLOCATED_FAT_SPACE/NOR_BLOCK_SIZE)
#define NOR_TOTAL_TABLE_BLOCKS 32
NOR_FTL_DATA  FlashDriveData;
static NORLayoutInfo LayoutInfo;

static kal_uint32 LogPageID[MS_TABLE_ENTRY_NUM];
static WORD NewEntryID[MS_TABLE_ENTRY_NUM];
static WORD OldEntryID[MS_TABLE_ENTRY_NUM];

#ifndef __INTEL_SIBLEY__

#define NOR_PAGE_SIZE 512

FS_Driver NORFlashDriver = {
   nNOR_MountDevice,
   nShutDown,
   nNOR_ReadSectors,
   nNOR_WriteSectors,
   NOR_MediaChanged,
   nNOR_DiscardSectors,
   nGetDiskGeometry,
   nNOR_LowLevelFormat,
   nNOR_NonBlockWriteSectors,
   nNOR_RecoverableWriteSectors,
   nNOR_ResumeSectorStates,
   NULL, /*high level format*/
   NULL, /*flush data*/
   NULL  /*message ack*/
#ifdef __SECURITY_OTP__
   ,
   NULL, /*copy sector*/
   OTPAccess,
   OTPQueryLength
#endif
};
   
#else

#define NOR_PAGE_SIZE 1024

FS_Driver NORFlashDriver = {
   nSIB_MountDevice,
   nShutDown,
   nSIB_ReadSectors,
   nSIB_WriteSectors,
   NOR_MediaChanged,
   nSIB_DiscardSectors,
   nGetDiskGeometry,
   nSIB_LowLevelFormat,
   nSIB_NonBlockWriteSectors,
   nSIB_RecoverableWriteSectors,
   nSIB_ResumeSectorStates,
   NULL, /*high level format*/
   NULL, /*flush data*/
   NULL  /*message ack*/
#ifdef __SECURITY_OTP__
   ,
   NULL, /*copy sector*/
   OTPAccess,
   OTPQueryLength
#endif
};
#endif /*__INTEL_SIBLEY__*/


static kal_uint16  NOR_LBM[NOR_TOTAL_BLOCKS];
static LSMGEntry   NOR_LSMG[NOR_TOTAL_LSMT]; // need to check in the program
static kal_uint16  NOR_AvailInBlk[NOR_TOTAL_BLOCKS];
static kal_uint16  NOR_InvaildInBlk[NOR_TOTAL_BLOCKS];
static kal_uint32  NOR_InvalidEntryInTblBlk[NOR_TOTAL_TABLE_BLOCKS];
static kal_uint8 FDMBuffer[NOR_PAGE_SIZE];
static kal_uint8 CopyBuffer[NOR_PAGE_SIZE];
static NOR_MTD_DATA mtdflash;
kal_eventgrpid  nor_egid = NULL;

extern NOR_MTD_Driver NORFlashMtd;
extern kal_uint32 INT_RetrieveFlashBaseAddr(void);

void Initialize_FDD_tables(void)
{
#if ( !defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_) )
    /* Initialize MTD data table */
   mtdflash.Signature = ~((kal_uint32)&LayoutInfo);

#ifdef __MTK_TARGET__
   mtdflash.BaseAddr = (BYTE *)(INT_RetrieveFlashBaseAddr() + NOR_FLASH_BASE_ADDRESS);
#endif
   LayoutInfo.BankInfo = BankInfo;
   LayoutInfo.TotalBlks = NOR_TOTAL_BLOCKS;
   LayoutInfo.BlkSize = NOR_BLOCK_SIZE;
   LayoutInfo.PageSize = NOR_PAGE_SIZE;
   LayoutInfo.TotalLSMT= NOR_TOTAL_LSMT;
   mtdflash.LayoutInfo = (NORLayoutInfo *)&LayoutInfo;

   /* Initialize FDD data table */
   FlashDriveData.MTDDriver = &NORFlashMtd;
   FlashDriveData.MTDData = &mtdflash;
   FlashDriveData.LBM = NOR_LBM;
   FlashDriveData.LSMG = NOR_LSMG;
   FlashDriveData.AvailInBlk = NOR_AvailInBlk;
   FlashDriveData.InvalidInBlk = NOR_InvaildInBlk;
   FlashDriveData.InvalidEntryInTblBlk = NOR_InvalidEntryInTblBlk;

   FlashDriveData.MSTABLE_ENTRY_NUM = MS_TABLE_ENTRY_NUM;
   FlashDriveData.MSTable.LogPageID = LogPageID;
   FlashDriveData.MSTable.NewEntryID = NewEntryID;   
   FlashDriveData.MSTable.OldEntryID = OldEntryID;   
   
#if (NOR_SYSDRV_SECTORS==0)
 #if (NOR_PARTITION_SECTORS==0)
 FlashDriveData.SecondPartitionSectors = 0xffffffff;
 #else // (NOR_PARTITION_SECTORS==0)
 FlashDriveData.SecondPartitionSectors = 0xfe000000 | NOR_PARTITION_SECTORS;
 #endif // (NOR_PARTITION_SECTORS==0)
#else // (NOR_SYSDRV_SECTORS==0)
 FlashDriveData.SecondPartitionSectors = NOR_SYSDRV_SECTORS;
#endif // (NOR_SYSDRV_SECTORS==0)

   FlashDriveData.SetTblBlks = NOR_TOTAL_TABLE_BLOCKS;
   FlashDriveData.Buffer = FDMBuffer;
   FlashDriveData.CopyBuffer = CopyBuffer;
#ifndef __INTEL_SIBLEY__
   FlashDriveData.ReclaimBlock = nNOR_ReclaimBlock;
#else
   FlashDriveData.ReclaimBlock = nSIB_ReclaimBlock;
#endif /* __INTEL_SIBLEY__ */
#endif /* !__FS_SYSDRV_ON_NAND__ && !_NAND_FLASH_BOOTING_ */
}

#endif /*__NOR_FDM5__*/
