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
 *   custom_flash.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines flash related settings.
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
 * removed!
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
MT6280 SIP_MDSP link fail.
[Solution]
Modify EXTSRAM_type_7() to switch $ram_disk_size become 0x40000 if it's MT6280
[Verification]
m sys_auto_gen on MT6280_EVB_R7R8_HSPA(SIP_MDSP).W12.17
and the generated EXTSRAM_FS maxsize becomes 0x40000 and dummy_end base is correct as well.
[Phase-in Branch]
MT6280_DVT_DEV
MODEM_DEV
[Version]
scatGenLib.pl m0.03
[Requester]
Stanley Chu

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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define FLASHCONF_C

#if defined(__SMART_MD_NFI_DRIVER__)    // Smart phone start alone driver
	#ifndef _NAND_FLASH_BOOTING_
		#define _NAND_FLASH_BOOTING_
	#endif
#endif

#include "kal_general_types.h"
#include "fs_type.h"
#include "custom_MemoryDevice.h"
#include "flash_sf.h"
#include "string.h"

#ifdef FLASH_DISKDRV_DEBUG
#include <stdlib.h>
#endif

#include "flash_opt.h"
#include "DrvFlash.h"
#include "NAND_FDM.h"
#include "custom_fota.h"
#include "flash_disk.h"
#include "flash_disk_internal.h"
#include "combo_flash_init.h"

#include "custom_flash.h"

#include "flash_mtd_ut.h"  //__BASIC_LOAD_FLASH_TEST__
#include "DrvFlash_UT.h"

#include "custom_nvram_int_config.h"  /* To get NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM for MSTABLE_ENTRY_NUM */


#if !(defined(__SMART_PHONE_PLATFORM__) && defined(__SMART_PHONE_MODEM__))



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

/*
 ****************************************************************************
 PART 1:
 Rules to Prevent Wrong Configuration
 ****************************************************************************
*/
#ifdef NAND_PARTITION_SECTORS

 #if (NAND_PARTITION_SECTORS > 0 && NAND_PARTITION_SECTORS < NAND_MINIMUM_PARTITION_SIZE)
  #error "custom\system\{project}\custom_MemoryDevice.h: Error! NAND_FS_FIRST_DRIVE_SECTORS MUST be larger than NAND_MINIMUM_PARTITION_SIZE!"
 #endif

 #if (defined(_NAND_FLASH_BOOTING_))
  #if ( (NAND_PARTITION_SECTORS << 9) > NAND_ALLOCATED_FAT_SPACE)
   #error "custom\system\{project}\custom_MemoryDevice.h: Error! NAND_FS_FIRST_DRIVE_SECTORS MUST be less than NAND_FS_SIZE!"
  #endif
 #endif /* _NAND_FLASH_BOOTING_ */

#endif /* NAND_PARTITION_SECTORS */


#if defined(__SINGLE_BANK_NOR_DEVICE__)

  #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
  #else
        #error "custom\system\{project}\custom_MemoryDevice.h: Error! Single Bank device with non Single Bank load! Please modify device or makefile option!"
  #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#endif /* __SINGLE_BANK_NOR_DEVICE__ */


#if !defined(_NAND_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__)
   #ifndef __NOR_FDM5__
      #if (TOTAL_BLOCKS > 127)
         #error "TOTAL_BLOCKS > 127 , recommend enable Pseudo Sized Block feature for serial flash project. Enable FDM5.0 feature for NOR flash project."
      #endif
   #endif
#endif

/*
 ****************************************************************************
 PART 2:
 Essential Information of NOR Flash Geometry Layout Information
 ****************************************************************************
*/
/*******************************************************************************
   NOTICE: Fill the flash region information table, a region is the memory space
           that contains continuous sectors of equal size. Each region element
           in the table is the format as below:
           {S_sector, N_sector},
               S_sector: the size of sector in the region
               N_sector: the number of sectors in the region
 *******************************************************************************/

#if !(defined(__FUE__) || defined(__UBL__) || defined(__EXT_BOOTLOADER__))
#define __MAUI_LOAD__
#endif //!__FUE__ && !__UBL__ && !__EXT_BOOTLOADER__

#if !defined(_NAND_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__) && !defined(__RAMDISK__)
#define _NOR_FLASH_BOOTING_
#endif // !_NAND_FLASH_BOOTING_ && !__EMMC_BOOTING__


#ifdef _NOR_FLASH_BOOTING_

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#define FLASH_REGIONINFO_VAR_MODIFIER  static
#else /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
#define FLASH_REGIONINFO_VAR_MODIFIER  static const
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

#if (defined(__MAUI_LOAD__) && defined(_NOR_FLASH_BOOTING_) && !defined(__NOR_FDM5__))
#define __MAUI_NOR_FDM4__
#endif

#if defined(__MAUI_NOR_FDM4__) 
FLASH_REGIONINFO_VAR_MODIFIER FlashRegionInfo RegionInfo[]= /* Don't modify this line */
{
   REGION_INFO_LAYOUT
   EndRegionInfo /* Don't modify this line */
};
#endif //__MAUI_NOR_FDM4__ 

#if (!defined(__COMBO_MEMORY_SUPPORT__) && !defined(__SERIAL_FLASH__))
#ifdef __NOR_SUPPORT_RAW_DISK__

#ifndef NOR_BOOTING_NOR_DISK_NUM
#error "custom\system\{project}\custom_MemoryDevice.h: Error! NOR_BOOTING_NOR_DISK_NUM be defined when __NOR_SUPPORT_RAW_DISK__ is defined."
#endif //NOR_BOOTING_NOR_DISK_NUM

#if (NOR_BOOTING_NOR_DISK_NUM>0)
FLASH_REGIONINFO_VAR_MODIFIER FlashRegionInfo Disk0RegionInfo[]= /* Don't modify this line */
{
   DISK0_REGION_INFO_LAYOUT
   EndRegionInfo /* Don't modify this line */
};
#endif /* NOR_BOOTING_NOR_DISK_NUM>0 */

#if (NOR_BOOTING_NOR_DISK_NUM>1)
FLASH_REGIONINFO_VAR_MODIFIER FlashRegionInfo Disk1RegionInfo[]= /* Don't modify this line */
{
   DISK1_REGION_INFO_LAYOUT
   EndRegionInfo /* Don't modify this line */
};
#endif /* NOR_BOOTING_NOR_DISK_NUM>1 */
#endif // __NOR_SUPPORT_RAW_DISK__

FLASH_REGIONINFO_VAR_MODIFIER FlashRegionInfo EntireDiskRegionInfo[]= /* Don't modify this line */
{
   ENTIRE_DISK_REGION_INFO_LAYOUT
   EndRegionInfo /* Don't modify this line */
};

NOR_FLASH_DISK_Data EntireDiskDriveData;
static NOR_Flash_MTD_Data EntireDiskMtdData; 

/*******************************************************************************
   NOTICE. Modify the value of page buffer size in WORD for page buffer program
 *******************************************************************************/
kal_uint32 PAGE_BUFFER_SIZE = BUFFER_PROGRAM_ITERATION_LENGTH;

/*******************************************************************************
   NOTICE. This is for the Enhanced Signle Bank Support, when this feature is
           turned on and still use multi-bank device, this table should be filled
           with correct value.
 
           This Table define the flash bank information which starts from 
           FLASH_BASE_ADDRESS, please fill the flash bank information table, every
           entry defines the memory space that contains continuous banks of equal size.
           Each entry element in the table is the format as below:
           {S_Bank, N_Bank},
               S_Bank: the size of bank in the entry
               N_Bank: the number of banks in the entry
 *******************************************************************************/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__MULTI_BANK_NOR_DEVICE__)

#ifdef __MAUI_LOAD__
FLASH_REGIONINFO_VAR_MODIFIER FlashBankInfo BankInfo[] =
{
   BANK_INFO_LAYOUT
   EndBankInfo /* Don't modify this line */
};
#endif //__MAUI_LOAD__

#endif //__SINGLE_BANK_NOR_FLASH_SUPPORT__ && __MULTI_BANK_NOR_DEVICE__
#endif /* !__COMBO_MEMORY_SUPPORT__ && !__SERIAL_FLASH__ */

#endif // _NOR_FLASH_BOOTING_

/*
 ****************************************************************************
 PART 3:
 Essential Declarations for NOR-Flash Disk
 ****************************************************************************
*/

extern NOR_MTD_Driver NORFlashMtd;

#ifdef __MAUI_NOR_FDM4__

static MS_ENTRY MSEntryTable[MS_TABLE_ENTRY_NUM];


#if (!defined(__COMBO_MEMORY_SUPPORT__) && !defined(__SERIAL_FLASH__))

#ifndef __INTEL_SIBLEY__

/* Each FAT sector is 512bytes (0x200) */
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#define TOTAL_SECTORS   ((NOR_ALLOCATED_FAT_SPACE - NOR_BLOCK_SIZE * SNOR_ERASE_QUEUE_SIZE) / 0x200)
#else
#define TOTAL_SECTORS   ((NOR_ALLOCATED_FAT_SPACE -NOR_BLOCK_SIZE * NOR_SYSTEM_DRIVE_RESERVED_BLOCK) / 0x200)
#endif

kal_uint8 FDMBuffer[512];


FS_Driver NORFlashDriver =
{
   NOR_MountDevice_ext,
   NOR_ShutDown,
   NOR_ReadSectors_ext,
   NOR_WriteSectors_ext,
   NOR_MediaChanged_ext,
   NOR_DiscardSectors_ext,
   NOR_GetDiskGeometry_ext,
   NOR_LowLevelFormat_ext,
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NULL,
#else
   NOR_NonBlockWriteSectors_ext,
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
   NOR_RecoverableWriteSectors_ext,
   NOR_ResumeSectorStates_ext,
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

#else /* __INTEL_SIBLEY__ */

/* Each FAT sector is 1024bytes (0x200) */
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#define TOTAL_SECTORS   ((NOR_ALLOCATED_FAT_SPACE - NOR_BLOCK_SIZE * SNOR_ERASE_QUEUE_SIZE) / 0x400)
#else
#define TOTAL_SECTORS   ((NOR_ALLOCATED_FAT_SPACE - NOR_BLOCK_SIZE * NOR_SYSTEM_DRIVE_RESERVED_BLOCK) / 0x400)
#endif

kal_uint8 FDMBuffer[1024];


FS_Driver NORFlashDriver =
{
   SIB_MountDevice,
   NOR_ShutDown,
   SIB_ReadSectors,
   SIB_WriteSectors,
   NOR_MediaChanged,
   SIB_DiscardSectors,
   SIB_GetDiskGeometry,
   SIB_LowLevelFormat,
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NULL,
#else
   SIB_NonBlockWriteSectors,
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
   SIB_RecoverableWriteSectors,
   SIB_ResumeSectorStates,
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

#endif /* __INTEL_SIBLEY__ */

static WORD AVAILSECTORS[TOTAL_BLOCKS];
static WORD VALIDSECTORS[TOTAL_BLOCKS];
static BYTE SectorMap[TOTAL_SECTORS];
NOR_FLASH_DRV_Data  FlashDriveData;


#ifdef __MTK_TARGET__

static NOR_Flash_MTD_Data mtdflash;

#ifdef __NOR_SUPPORT_RAW_DISK__
NOR_FLASH_DISK_Data FlashDiskDriveData[NOR_BOOTING_NOR_DISK_NUM];
static NOR_Flash_MTD_Data mtdFlashDisk[NOR_BOOTING_NOR_DISK_NUM]; 
#endif // __NOR_SUPPORT_RAW_DISK__

extern kal_uint32 INT_RetrieveFlashBaseAddr(void);

#else

static NOR_Flash_MTD_Data mtdflash =
{
   MakeMtdFlashData((BYTE *)NOR_FLASH_BASE_ADDRESS, RegionInfo)
};

#endif /* __MTK_TARGET__ */

#endif /* !(__COMBO_MEMORY_SUPPORT__) && !(__SERIAL_FLASH__) */

#endif /* __MAUI_NOR_FDM4__ */



/*
 ****************************************************************************
 PART 4:
 Public Functions For NOR Flash Information Retrieve, Initial routine, and
 other misc routines.
 ****************************************************************************
*/
kal_uint32 custom_get_NORFLASH_Base(void);

/*
 ****************************************************************************
 PART 5:
 Essential Declarations for NAND-Flash Disk
 ****************************************************************************
*/
#if (!(defined(__FUE__) && defined(__FOTA_DM__)) && (!defined(__UBL__)||(defined(__UBL__)&&defined(__NAND_SUPPORT_RAW_DISK__))))
  // 1. NAND FDM variable compile option 
  //   a. In general, FOTA and Boot loader don't need to include NAND FDM variable. 
  //   b. In TC01 Raw disk case, boot loader need to call FDM function, it will need raw disk configuration 
  // 2. Declare NAND variable structue
  //   a. In general, NFBxxx is only used for NAND_BOOTING 
  //   b. UP_PKG_ON_NAND will also need NFBxxx.

#if defined(__EMMC_BOOTING__)


#elif defined(_NAND_FLASH_BOOTING_)
  /* System Drive on NAND-flash */
  #if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
  kal_uint32 NFB_BASE_ADDRESS[NAND_DISK_NUM];
  kal_uint32 NFB_ALLOCATED_FAT_SPACE[NAND_DISK_NUM];
  kal_uint16 FS_DISK_REPLACE_RATIO[NAND_DISK_NUM];
  const kal_uint8 NANDDiskNum = NAND_DISK_NUM;
  #if ( defined(__NANDFDM_TOTAL_BBM__))
  kal_uint32 FS_DISK_START_SECTION[NAND_DISK_NUM];
  kal_uint32 NFB_REPLACE_BASE_ADDRESS;
  kal_uint32 NFB_REPLACE_SPACE;
  BBM_BRMT_INFO NAND_BRMT_Info;
  #endif  
  #else // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
  const kal_uint32 NFB_BASE_ADDRESS = NAND_FLASH_BASE_ADDRESS;
  const kal_uint32 NFB_ALLOCATED_FAT_SPACE = NAND_ALLOCATED_FAT_SPACE;
  #endif // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )

#else /* !_NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */
  #if (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT)) || (defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__))  
    /* update package storage on NAND flash */
    #if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
      kal_uint32 NFB_BASE_ADDRESS[NAND_DISK_NUM];
      kal_uint32 NFB_ALLOCATED_FAT_SPACE[NAND_DISK_NUM];
      kal_uint16 FS_DISK_REPLACE_RATIO[NAND_DISK_NUM];
      const kal_uint8 NANDDiskNum = NAND_DISK_NUM;
    #else // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
      const kal_uint32 NFB_BASE_ADDRESS = NAND_FLASH_BASE_ADDRESS;
      const kal_uint32 NFB_ALLOCATED_FAT_SPACE = NAND_ALLOCATED_FAT_SPACE;
    #endif // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
  #endif
#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

#if defined(__NAND_FDM_50__)
  #ifdef  NAND_BOOTING_NAND_MAX_REPLACE_COUNT
   kal_uint16 wNandMaxReplaceCount = NAND_BOOTING_NAND_MAX_REPLACE_COUNT;
  #else
   kal_uint16 wNandMaxReplaceCount = 28;
  #endif
#endif //defined(__NAND_FDM_50__)

#ifdef __EMMC_BOOTING__
kal_uint32 custom_part_secs = 0;
#else
kal_uint32 custom_part_secs = NAND_PARTITION_SECTORS;
#endif

#if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
  #if (defined(__UBL__)&&defined(__NAND_SUPPORT_RAW_DISK__))
  NAND_FLASH_DRV_DATA  NANDFlashDriveData[1];   // To save ZI Space
  #else
  NAND_FLASH_DRV_DATA  NANDFlashDriveData[NAND_DISK_NUM];
  #endif
#else // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
NAND_FLASH_DRV_DATA  NANDFlashDriveData;
#endif // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )

#endif /* (!(__FOTA_DM__ && __FUE__) || !__UBL__)) || (UBL&&RAW) */
/*************************************************************************
* FUNCTION
*  custom_get_NORFLASH_ROMSpace()
*
* DESCRIPTION
*  Query the of space configured for NORFLASH ROM
*
* PARAMETERS
*
* RETURNS
*  BASE ADDRESS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32
custom_get_NORFLASH_ROMSpace(void)
{
#if   defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) || defined(__RAMDISK__)
   return 0;
#elif defined(__FS_SYSDRV_ON_NAND__) || (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT))
   return NOR_FLASH_BASE_ADDRESS + NOR_ALLOCATED_FAT_SPACE;
#else
   return NOR_FLASH_BASE_ADDRESS;
#endif
}


/*************************************************************************
* FUNCTION
*  custom_get_NORFLASH_Size()
*
* DESCRIPTION
*  Query the size of NORFLASH ROM
*
* PARAMETERS
*
* RETURNS
*  SIZE
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32
custom_get_NORFLASH_Size(void)
{
#if   defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) || defined(__RAMDISK__)
   return 0;
#else
   return NOR_FLASH_SIZE;
#endif
}

/*************************************************************************
* FUNCTION
*  Initialize_FDD_tables
*
* DESCRIPTION
*  Initialize important information for NOR-flash disk
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if defined(__MAUI_LOAD__)

#if defined(__RAMDISK__)
extern kal_uint8 ram_disk[];       
void Initialize_FDD_tables(void)
{
    return;
}
#elif ((defined(__COMBO_MEMORY_SUPPORT__) || defined(__SERIAL_FLASH__)) && defined(_NOR_FLASH_BOOTING_))
void Initialize_FDD_tables(void)
{
#if !defined(ATEST_DRV_ENABLE) && !defined(ATEST_DRV_ENVIRON)
    ComboMem_Initialize();
#endif /* end of ATEST_DRV_ENABLE */
    return;
}

#else /* (!(__COMBO_MEMORY_SUPPORT__) && !(__SERIAL_FLASH__)) && !(_NOR_FLASH_BOOTING_) */

#ifndef __NOR_FDM5__

#ifdef __NONE_FLASH_EXIST__

NOR_MTD_Driver NORFlashMtd;

#endif

void Initialize_FDD_tables(void)
{
#if ( !defined(__FS_SYSDRV_ON_NAND__) && defined(_NOR_FLASH_BOOTING_))

   /* Initialize MTD data table */
   mtdflash.Signature = ~((kal_uint32)RegionInfo);

#ifdef __MTK_TARGET__
#if defined(__SMART_PHONE_PLATFORM__) && !defined(__SMART_PHONE_MODEM__)
   mtdflash.BaseAddr = (kal_uint8 *)ram_disk;
#else
   mtdflash.BaseAddr = (BYTE *)(INT_RetrieveFlashBaseAddr() + NOR_FLASH_BASE_ADDRESS);
#endif

#endif /* __MTK_TARGET__ */

   mtdflash.RegionInfo = (FlashRegionInfo *)RegionInfo;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && (defined(__MULTI_BANK_NOR_DEVICE__) || defined(__ARM9_MMU__) || defined(__ARM11_MMU__))
   mtdflash.BankInfo = (FlashBankInfo*)BankInfo;
#endif

   /* Initialize FDD data table */
   FlashDriveData.MTDDriver = &NORFlashMtd;
   FlashDriveData.MTDData = &mtdflash;
   FlashDriveData.AvailSectorsInBlock = AVAILSECTORS;
   FlashDriveData.ValidSectorsInBlock = VALIDSECTORS;
   FlashDriveData.SectorMap = (BYTE*)SectorMap;
   FlashDriveData.PartitionSectors = NOR_PARTITION_SECTORS;
   FlashDriveData.Buffer = FDMBuffer;
   FlashDriveData.MSTABLE_ENTRY_NUM = MS_TABLE_ENTRY_NUM;
   FlashDriveData.MSEntryTable = MSEntryTable;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   FlashDriveData.queueSize = SNOR_ERASE_QUEUE_SIZE;
   /* align page buffer size for iteration */
   #if defined(__PAGE_BUFFER_PROGRAM__) && ! (defined(__SPANSION_VS_R__) || defined(__SPANSION_VS_R64__))
   PAGE_BUFFER_SIZE = BUFFER_PROGRAM_ITERATION_LENGTH;
   #endif /* __PAGE_BUFFER_PROGRAM__ */
   /* initialize address look up table */
   memset(mtdflash.lookup_tbl, 0xFF, sizeof(NOR_AddrLookup)*LOOKUP_TABLE_SIZE*2);

#else /* !__SINGLE_BANK_NOR_FLASH_SUPPORT__ */
   /* The reserved unit is 0.5 block.*/
   FlashDriveData.SystemDriveReservedUnits = (kal_uint32)(NOR_SYSTEM_DRIVE_RESERVED_BLOCK * 2);
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

   
#ifdef __NOR_SUPPORT_RAW_DISK__
   mtdFlashDisk[0].Signature = ~((kal_uint32)Disk0RegionInfo);
   mtdFlashDisk[0].BaseAddr = (BYTE *)(INT_RetrieveFlashBaseAddr() + NOR_BOOTING_NOR_DISK0_BASE_ADDRESS); 
   mtdFlashDisk[0].RegionInfo = (FlashRegionInfo *)Disk0RegionInfo;
   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   memset(mtdFlashDisk[0].lookup_tbl, 0xFF, sizeof(NOR_AddrLookup)*LOOKUP_TABLE_SIZE*2);
   #endif
   FlashDiskDriveData[0].DiskSize = NOR_BOOTING_NOR_DISK0_SIZE; 
   FlashDiskDriveData[0].MTDDriver = &NORFlashMtd; 
   FlashDiskDriveData[0].MTDData = &mtdFlashDisk[0]; 
#if (NOR_BOOTING_NOR_DISK_NUM > 1)
   mtdFlashDisk[1].Signature = ~((kal_uint32)Disk1RegionInfo);
   mtdFlashDisk[1].BaseAddr = (BYTE *)(INT_RetrieveFlashBaseAddr() + NOR_BOOTING_NOR_DISK1_BASE_ADDRESS); 
   mtdFlashDisk[1].RegionInfo = (FlashRegionInfo *)Disk1RegionInfo;
   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   memset(mtdFlashDisk[1].lookup_tbl, 0xFF, sizeof(NOR_AddrLookup)*LOOKUP_TABLE_SIZE*2);
   #endif
   FlashDiskDriveData[1].DiskSize = NOR_BOOTING_NOR_DISK1_SIZE; 
   FlashDiskDriveData[1].MTDDriver = &NORFlashMtd; 
   FlashDiskDriveData[1].MTDData = &mtdFlashDisk[1]; 
#endif // NOR_BOOTING_NOR_DISK_NUM > 1
#endif // __NOR_SUPPORT_RAW_DISK__

#ifdef __FOTA_DM__
   FlashDriveData.FlashInfo.baseUnlockBlock = INVALID_BLOCK_INDEX;
   FlashDriveData.FlashInfo.endUnlockBlock = INVALID_BLOCK_INDEX;
#endif


#ifdef __BASIC_LOAD_FLASH_TEST__
#ifdef __INTEL_SIBLEY__
   LocateSector_ext = SIB_LocateSector;
#else
   LocateSector_ext = LocateSector;
#endif //__INTEL_SIBLEY__
#endif //__BASIC_LOAD_FLASH_TEST__


#endif /* !__FS_SYSDRV_ON_NAND__ && _NOR_FLASH_BOOTING_ */

 #if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
 {
  kal_uint32 DiskIndex;

  for (DiskIndex=0; DiskIndex<NAND_DISK_NUM; DiskIndex++) 
  {
   #if (defined(__UBL__)&&defined(__NAND_SUPPORT_RAW_DISK__))
   if(DiskIndex==RAW_DISK_INDEX){
     NANDFlashDriveData[0].NAND_FDMData.DiskIndex = RAW_DISK_INDEX;
   }
   #else
   NANDFlashDriveData[DiskIndex].NAND_FDMData.DiskIndex = DiskIndex;
   #endif
   switch (DiskIndex) 
   {
    case 0:
     NFB_BASE_ADDRESS[0] = NAND_BOOTING_NAND_FS_DISK0_BASE_ADDRESS;
     NFB_ALLOCATED_FAT_SPACE[0] = NAND_BOOTING_NAND_FS_DISK0_SIZE;
     FS_DISK_REPLACE_RATIO[0] = NAND_BOOTING_NAND_FS_DISK0_REPLACE_RATIO;
     break;
                                #if (NAND_DISK_NUM > 1)
    case 1:
     NFB_BASE_ADDRESS[1] = NAND_BOOTING_NAND_FS_DISK1_BASE_ADDRESS;
     NFB_ALLOCATED_FAT_SPACE[1] = NAND_BOOTING_NAND_FS_DISK1_SIZE;
     FS_DISK_REPLACE_RATIO[1] = NAND_BOOTING_NAND_FS_DISK1_REPLACE_RATIO;     
     break;
    #endif /* NAND_DISK_NUM > 1 */
                                #if (NAND_DISK_NUM > 2)
    case 2:
     NFB_BASE_ADDRESS[2] = NAND_BOOTING_NAND_FS_DISK2_BASE_ADDRESS;
     NFB_ALLOCATED_FAT_SPACE[2] = NAND_BOOTING_NAND_FS_DISK2_SIZE;
     FS_DISK_REPLACE_RATIO[2] = NAND_BOOTING_NAND_FS_DISK2_REPLACE_RATIO;     
     break;
    #endif /* NAND_DISK_NUM > 2 */
                                #if (NAND_DISK_NUM > 3)
    case 3:
     NFB_BASE_ADDRESS[3] = NAND_BOOTING_NAND_FS_DISK3_BASE_ADDRESS;
     NFB_ALLOCATED_FAT_SPACE[3] = NAND_BOOTING_NAND_FS_DISK3_SIZE;
     FS_DISK_REPLACE_RATIO[3] = NAND_BOOTING_NAND_FS_DISK3_REPLACE_RATIO;     
     break;
    #endif /* NAND_DISK_NUM > 3 */
                                #if (NAND_DISK_NUM > 4)
    case 4:
     NFB_BASE_ADDRESS[4] = NAND_BOOTING_NAND_FS_DISK4_BASE_ADDRESS;
     NFB_ALLOCATED_FAT_SPACE[4] = NAND_BOOTING_NAND_FS_DISK4_SIZE;
     FS_DISK_REPLACE_RATIO[4] = NAND_BOOTING_NAND_FS_DISK4_REPLACE_RATIO;     
     break;
    #endif /* NAND_DISK_NUM > 4 */
                                #if (NAND_DISK_NUM > 5)
    case 5:
     NFB_BASE_ADDRESS[5] = NAND_BOOTING_NAND_FS_DISK5_BASE_ADDRESS;
     NFB_ALLOCATED_FAT_SPACE[5] = NAND_BOOTING_NAND_FS_DISK5_SIZE;
     FS_DISK_REPLACE_RATIO[5] = NAND_BOOTING_NAND_FS_DISK5_REPLACE_RATIO;     
     break;
    #endif /* NAND_DISK_NUM > 5 */
                                #if (NAND_DISK_NUM > 6)
    case 6:
     NFB_BASE_ADDRESS[6] = NAND_BOOTING_NAND_FS_DISK6_BASE_ADDRESS;
     NFB_ALLOCATED_FAT_SPACE[6] = NAND_BOOTING_NAND_FS_DISK6_SIZE;
     FS_DISK_REPLACE_RATIO[6] = NAND_BOOTING_NAND_FS_DISK6_REPLACE_RATIO;     
     break;
    #endif /* NAND_DISK_NUM > 6 */
                                #if (NAND_DISK_NUM > 7)
    case 7:
     NFB_BASE_ADDRESS[7] = NAND_BOOTING_NAND_FS_DISK7_BASE_ADDRESS;
     NFB_ALLOCATED_FAT_SPACE[7] = NAND_BOOTING_NAND_FS_DISK7_SIZE;
     FS_DISK_REPLACE_RATIO[7] = NAND_BOOTING_NAND_FS_DISK7_REPLACE_RATIO;     
     break;
    #endif /* NAND_DISK_NUM > 7 */
   }
  }
 }
    #if ( defined(__NANDFDM_TOTAL_BBM__))
    NFB_REPLACE_BASE_ADDRESS = NAND_BOOTING_NAND_FS_REPLACE_BASE_ADDRESS;
    NFB_REPLACE_SPACE = NAND_BOOTING_NAND_FS_REPLACE_SIZE;
    NAND_BRMT_Info.ParameterReady = KAL_FALSE;
    NAND_BRMT_Info.NoReplace = KAL_FALSE;
    NAND_BRMT_Info.BRMT_Addr = 0;
    NAND_BRMT_Info.CurSectorInRAM = 0xff;
    #endif 

 #endif // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
}
#endif /*__NOR_FDM5__*/
#endif /* !(__COMBO_MEMORY_SUPPORT__) && !(__SERIAL_FLASH__) */

void nor_sweep_device(void)
{
#ifdef __NOR_FDM5__
   kal_set_eg_events(nor_egid, NOR_DMAN_EVENT, KAL_OR);
#endif
   return;
}

void nor_manual_reclaim(void)
{
#ifdef __NOR_FDM5__
   kal_set_eg_events(nor_egid, NOR_BRECL_EVENT, KAL_OR);
#endif
   return;
}

/*************************************************************************
* FUNCTION
*  custom_get_fat_addr()
*
* DESCRIPTION
*  This function gets the start address of FAT.
*
* PARAMETERS
*  none
*
* RETURNS
*  FAT start address
*
*************************************************************************/
kal_uint32 custom_get_fat_addr()
{
   #if defined(__RAMDISK__) 
      return &ram_disk;
   #elif defined(__EMMC_BOOTING__)
      return EMMC_CODE_PARTITION_SIZE;
   #elif defined(_NAND_FLASH_BOOTING_)
      return NAND_FLASH_BASE_ADDRESS;
   #else
      return NOR_FLASH_BASE_ADDRESS;
   #endif   /* _NAND_FLASH_BOOTING_ */
}

/*************************************************************************
* FUNCTION
*  custom_get_fat_len()
*
* DESCRIPTION
*  This function gets the len of FAT.
*
* PARAMETERS
*  none
*
* RETURNS
*  FAT length
*
*************************************************************************/
kal_uint32 custom_get_fat_len()
{
   #if defined(__RAMDISK__)    
      return RAM_FS_SIZE_INT;
   #elif defined(__EMMC_BOOTING__)
      return 0;
   #elif defined(_NAND_FLASH_BOOTING_)
      return NAND_ALLOCATED_FAT_SPACE;
   #else
      return NOR_ALLOCATED_FAT_SPACE;
   #endif   /* _NAND_FLASH_BOOTING_ */
}
#endif // __MAUI_LOAD__

/*************************************************************************
* FUNCTION
*  Custom_NAND_Init
*
* DESCRIPTION
*  Initialize important information for NAND-flash disk
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if ((defined(__UBL__)&&defined(__NAND_SUPPORT_RAW_DISK__))||(!defined(__UBL__))) && !defined(__FUE__)
kal_bool NANDParameterInitialized = KAL_FALSE;
void Custom_NAND_Init(void)
{
 #if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
 {
  kal_uint32 DiskIndex;
  if(NANDParameterInitialized==KAL_TRUE){
    return;
  }
  NANDParameterInitialized = KAL_TRUE;

  for (DiskIndex=0; DiskIndex<NAND_DISK_NUM; DiskIndex++) 
  {
   #if (defined(__UBL__)&&defined(__NAND_SUPPORT_RAW_DISK__))
   if(DiskIndex==RAW_DISK_INDEX){
     NANDFlashDriveData[0].NAND_FDMData.DiskIndex = RAW_DISK_INDEX;
   }
   #else
   NANDFlashDriveData[DiskIndex].NAND_FDMData.DiskIndex = DiskIndex;
   #endif   
   switch (DiskIndex) 
   {
    case 0:
     NFB_BASE_ADDRESS[0] = NAND_BOOTING_NAND_FS_DISK0_BASE_ADDRESS;
     NFB_ALLOCATED_FAT_SPACE[0] = NAND_BOOTING_NAND_FS_DISK0_SIZE;
     FS_DISK_REPLACE_RATIO[0] = NAND_BOOTING_NAND_FS_DISK0_REPLACE_RATIO;
     break;
    #if (NAND_DISK_NUM > 1)
    case 1:
     NFB_BASE_ADDRESS[1] = NAND_BOOTING_NAND_FS_DISK1_BASE_ADDRESS;
     NFB_ALLOCATED_FAT_SPACE[1] = NAND_BOOTING_NAND_FS_DISK1_SIZE;
     FS_DISK_REPLACE_RATIO[1] = NAND_BOOTING_NAND_FS_DISK1_REPLACE_RATIO;     
     break;
    #endif /* NAND_DISK_NUM > 1 */
    #if (NAND_DISK_NUM > 2)
    case 2:
     NFB_BASE_ADDRESS[2] = NAND_BOOTING_NAND_FS_DISK2_BASE_ADDRESS;
     NFB_ALLOCATED_FAT_SPACE[2] = NAND_BOOTING_NAND_FS_DISK2_SIZE;
     FS_DISK_REPLACE_RATIO[2] = NAND_BOOTING_NAND_FS_DISK2_REPLACE_RATIO;     
     break;
    #endif /* NAND_DISK_NUM > 2 */
    #if (NAND_DISK_NUM > 3)
    case 3:
     NFB_BASE_ADDRESS[3] = NAND_BOOTING_NAND_FS_DISK3_BASE_ADDRESS;
     NFB_ALLOCATED_FAT_SPACE[3] = NAND_BOOTING_NAND_FS_DISK3_SIZE;
     FS_DISK_REPLACE_RATIO[3] = NAND_BOOTING_NAND_FS_DISK3_REPLACE_RATIO;     
     break;
    #endif /* NAND_DISK_NUM > 3 */
    #if (NAND_DISK_NUM > 4)
    case 4:
     NFB_BASE_ADDRESS[4] = NAND_BOOTING_NAND_FS_DISK4_BASE_ADDRESS;
     NFB_ALLOCATED_FAT_SPACE[4] = NAND_BOOTING_NAND_FS_DISK4_SIZE;
     FS_DISK_REPLACE_RATIO[4] = NAND_BOOTING_NAND_FS_DISK4_REPLACE_RATIO;     
     break;
    #endif /* NAND_DISK_NUM > 4 */
    #if (NAND_DISK_NUM > 5)
    case 5:
     NFB_BASE_ADDRESS[5] = NAND_BOOTING_NAND_FS_DISK5_BASE_ADDRESS;
     NFB_ALLOCATED_FAT_SPACE[5] = NAND_BOOTING_NAND_FS_DISK5_SIZE;
     FS_DISK_REPLACE_RATIO[5] = NAND_BOOTING_NAND_FS_DISK5_REPLACE_RATIO;     
     break;
    #endif /* NAND_DISK_NUM > 5 */
    #if (NAND_DISK_NUM > 6)
    case 6:
     NFB_BASE_ADDRESS[6] = NAND_BOOTING_NAND_FS_DISK6_BASE_ADDRESS;
     NFB_ALLOCATED_FAT_SPACE[6] = NAND_BOOTING_NAND_FS_DISK6_SIZE;
     FS_DISK_REPLACE_RATIO[6] = NAND_BOOTING_NAND_FS_DISK6_REPLACE_RATIO;     
     break;
    #endif /* NAND_DISK_NUM > 6 */
    #if (NAND_DISK_NUM > 7)
    case 7:
     NFB_BASE_ADDRESS[7] = NAND_BOOTING_NAND_FS_DISK7_BASE_ADDRESS;
     NFB_ALLOCATED_FAT_SPACE[7] = NAND_BOOTING_NAND_FS_DISK7_SIZE;
     FS_DISK_REPLACE_RATIO[7] = NAND_BOOTING_NAND_FS_DISK7_REPLACE_RATIO;     
     break;
    #endif /* NAND_DISK_NUM > 7 */
   }
  }
 }
    #if ( defined(__NANDFDM_TOTAL_BBM__))
    NFB_REPLACE_BASE_ADDRESS = NAND_BOOTING_NAND_FS_REPLACE_BASE_ADDRESS;
    NFB_REPLACE_SPACE = NAND_BOOTING_NAND_FS_REPLACE_SIZE;
    NAND_BRMT_Info.ParameterReady = KAL_FALSE;
    NAND_BRMT_Info.NoReplace = KAL_FALSE;
    NAND_BRMT_Info.BRMT_Addr = 0;
    NAND_BRMT_Info.CurSectorInRAM = 0xff;
    #endif

 #endif // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
}
#endif /* (!__UBL__ && !__FUE__)|| (UBL&&RAW) */

extern kal_int32 EMI_QueryIsRemapped(void);

void Custom_NOR_Init(void)
{
#if (!(defined(__FS_SYSDRV_ON_NAND__) || defined( _NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__))) && !defined(__RAMDISK__)
 #if (defined(__COMBO_MEMORY_SUPPORT__) || defined(__SERIAL_FLASH__))
   CMEM_Init_FullDriver();
 #else // (defined(__COMBO_MEMORY_SUPPORT__) || defined(__SERIAL_FLASH__))
   EntireDiskMtdData.Signature = ~((kal_uint32)EntireDiskRegionInfo);
   #if defined(__UBL__)
     if(EMI_QueryIsRemapped())
        EntireDiskMtdData.BaseAddr = (BYTE *)0x10000000;
     else 
        EntireDiskMtdData.BaseAddr = (BYTE *)0; 
   #else
   EntireDiskMtdData.BaseAddr = (BYTE *)INT_RetrieveFlashBaseAddr(); 
   #endif
   EntireDiskMtdData.RegionInfo = (FlashRegionInfo *)EntireDiskRegionInfo;
   EntireDiskDriveData.DiskSize = NOR_FLASH_SIZE;
   EntireDiskDriveData.MTDDriver = &NORFlashMtd;    
   EntireDiskDriveData.MTDData = &EntireDiskMtdData;
   EntireDiskDriveData.is_mount = KAL_FALSE;    
 #endif // (defined(__COMBO_MEMORY_SUPPORT__) || defined(__SERIAL_FLASH__))
#endif /* !__FS_SYSDRV_ON_NAND__ && !_NAND_FLASH_BOOTING_ */
}

#if (defined(__FUE__) || defined(__EXT_BOOTLOADER__)) && defined(__FOTA_DM__)
#if (defined(__COMBO_MEMORY_SUPPORT__) || defined(__SERIAL_FLASH__))

void Initialize_NOR_Info(void)
{
	CMEM_Init_FUE();
}


#else //!__COMBO_MEMORY_SUPPORT__ && !__SERIAL_FLASH__

#include "custom_fota.h"

NOR_Flash_MTD_Data fue_nor_mtdflash;

extern NOR_MTD_Driver NORFlashMtd;

NOR_FLASH_DRV_Data  FlashDriveData;

void Initialize_NOR_Info(void)
{
#if defined(_NOR_FLASH_BOOTING_)
   kal_uint32 blk_addr = 0;

   /* Initialize MTD data table */
   fue_nor_mtdflash.Signature = ~((kal_uint32)NORRegionInfo);

   #if !defined(__UBL__)
   FlashDriveData.MTDDriver = &NORFlashMtd;
   #endif /* __UBL__ */
   FlashDriveData.MTDData = &fue_nor_mtdflash;

#ifdef __MTK_TARGET__
   #if defined(MT6238) || defined(MT6235) || defined(MT6239) || defined(MT6235B)
   fue_nor_mtdflash.BaseAddr = (BYTE *)(custom_get_NORFLASH_Base()|0x08000000);
   #elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T)
   fue_nor_mtdflash.BaseAddr = (BYTE *)(custom_get_NORFLASH_Base()|0x04000000);
   #else
   fue_nor_mtdflash.BaseAddr = (BYTE *)custom_get_NORFLASH_Base();
   #endif
#endif /* __MTK_TARGET__ */

   fue_nor_mtdflash.RegionInfo = (FlashRegionInfo *)NORRegionInfo;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && (defined(__MULTI_BANK_NOR_DEVICE__) || defined(__ARM9_MMU__) || defined(__ARM11_MMU__))
   fue_nor_mtdflash.BankInfo = (FlashBankInfo*)FOTANORBankInfo;
#endif

#ifdef __FOTA_DM__
   blk_addr = SSF_GetUAImageLoadAddress()|custom_get_NORFLASH_Base();
   #if defined(MT6238) || defined(MT6235) || defined(MT6239) || defined(MT6235B)
   blk_addr |= 0x08000000;
   #elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T)
   blk_addr |= 0x04000000;
   #else
   blk_addr |= 0x0;
   #endif
   blk_addr -= (kal_uint32)fue_nor_mtdflash.BaseAddr;
   FlashDriveData.FlashInfo.baseUnlockBlock = BlockIndex(&fue_nor_mtdflash, blk_addr);

   #if (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT))
   blk_addr =  (custom_get_NORFLASH_ROMSpace() - 1) | custom_get_NORFLASH_Base();
   #else
   blk_addr =  FOTA_GetPackageStorageBase()+FOTA_GetPackageStorageSize();
   #endif /* __UP_PKG_ON_NAND__ && NAND_SUPPORT */

   #if defined(MT6238) || defined(MT6235) || defined(MT6239) || defined(MT6235B)
   blk_addr |= 0x08000000;
   #elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T)
   blk_addr |= 0x04000000;
   #else
   blk_addr |= 0x0;
   #endif

   blk_addr -= (kal_uint32)fue_nor_mtdflash.BaseAddr;
   FlashDriveData.FlashInfo.endUnlockBlock = BlockIndex(&fue_nor_mtdflash, blk_addr);
#endif

#endif // _NOR_FLASH_BOOTING_ 
}

#endif //__COMBO_MEMORY_SUPPORT__ || __SERIAL_FLASH__
#endif /* (__FUE__ || __EXT_BOOTLOADER__) && __FOTA_DM__ */





/*************************************************************************
* FUNCTION
*  custom_get_FLASH_Size()
*
* DESCRIPTION
*  Query the of space configured for ROM
*
* PARAMETERS
*
* RETURNS
*  BASE ADDRESS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 custom_get_FLASH_Size(void)
{
#if defined(__RAMDISK__)
   return RAM_FS_SIZE_INT;
#elif defined(__EMMC_BOOTING__)
   return 0;
#elif defined(_NAND_FLASH_BOOTING_)
   return NAND_TOTAL_SIZE << 20;
#else
   return NOR_FLASH_SIZE;
#endif
}

#if defined(__RAMDISK__)
#include "ramdisk_gprot.h"    // for RAM Disk FDM APIs
kal_uint32 RAMDiskDriveData;
FS_Driver RAMDiskDriver =
{
   ramdisk_fdm_mount_device,
   ramdisk_fdm_shutdown,
   ramdisk_fdm_read_sectors,
   ramdisk_fdm_write_sectors,
   ramdisk_fdm_media_changed,
   NULL,
   ramdisk_fdm_get_disk_geometry,
   NULL,
   NULL,
   ramdisk_fdm_recoverable_write_sectors,
   ramdisk_fdm_resume_sector_states,
   NULL,
   NULL, /*flush data*/
   NULL, /*message ack*/
   NULL, /*copy sector*/
   NULL,
   NULL
};
#endif // __RAMDISK__
#else // __SMART_PHONE_PLATFORM__ && __SMART_PHONE_MODEM__
void Initialize_FDD_tables(void)
{
    return;
}

kal_uint32 custom_get_fat_addr()
{
      return 0;
}

kal_uint32 custom_get_fat_len()
{
      return 0;
}


/*************************************************************************
* FUNCTION
*  custom_get_NORFLASH_Base()
*
* DESCRIPTION
*  Query the of space configured for NORFLASH ROM
*
* PARAMETERS
*
* RETURNS
*  BASE ADDRESS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 custom_get_NORFLASH_Base(void)
{
#if   defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
   return 0;
#else
   return NOR_FLASH_BASE_ADDR;
#endif
}


#endif //!__SMART_PHONE_PLATFORM__ || !__SMART_PHONE_MODEM__



/*************************************************************************
* FUNCTION
*  INT_QueryIsROMSpace()
*
* DESCRIPTION
*  Query the address in Flash address space or not
*
* PARAMETERS
*  address to check
*
* RETURNS
*  KAL_TRUE if address is in Flash address space
*  KAL_FALSE if not
*
* Only apply to ADMUX MT6255 for DMA to check whether the address to be copied in flash or not. 
* To avoid DMA accessing Single bank flash when it is busy.
* 
*************************************************************************/

kal_bool INT_QueryIsROMSpace(kal_uint32 addr)
{
#if defined(MT6250)
   if((addr>=NOR_FLASH_BASE_ADDR && addr<(NOR_FLASH_BASE_ADDR+NOR_FLASH_SIZE)) || (addr>=0x90000000 && addr<(0x90000000+NOR_FLASH_SIZE)))
       return KAL_TRUE;
   else
       return KAL_FALSE;
#elif !defined(MT6255)|| defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) || !defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   return KAL_FALSE;
#else
   return (addr>=NOR_FLASH_BASE_ADDR && addr<(NOR_FLASH_BASE_ADDR+NOR_FLASH_SIZE))?KAL_TRUE:KAL_FALSE;
#endif
}

