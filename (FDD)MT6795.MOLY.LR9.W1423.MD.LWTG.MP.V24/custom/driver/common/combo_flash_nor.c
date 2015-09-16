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
 *   combo_flash_nor.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the ComboMCP Init function for NAND/NOR FDM
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "custom_MemoryDevice.h"
#include "flash_opt.h"

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "combo_flash_init.h"
#include "fat_fs.h"
#include "combo_flash_defs.h"

#include "flash_mtd_sf_dal.h"
#include "flash_mtd_pf_dal.h"

#if defined(__COMBO_MEMORY_SUPPORT__) || defined(__SERIAL_FLASH__)
#if ( !defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__))

#include "flash_sf.h"
#include "DrvFlash.h"
#include "flash_disk_internal.h" 

#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
#include "br_GFH_cmem_nor_info.h"
#endif /* __SV5_ENABLED__ || __SV5X_ENABLED__ */

#include "DrvFlash_UT.h" //locateSector_ext for basic load
#include "flash_mtd_ut.h" //__BASIC_LOAD_FLASH_TEST__

#include "custom_nvram_int_config.h"  /* To get NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM for MSTABLE_ENTRY_NUM */




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


//-----------------------------------------------------------------------------
// Combo MCP related
//-----------------------------------------------------------------------------
static kal_int32 cmem_nor_index;        // Do not use this variabe during EMI init stage
const CMEMEntryID *cmem_id;

//-----------------------------------------------------------------------------
// MCP Serial/NOR Flash Driver settings
//-----------------------------------------------------------------------------

#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
#if defined(__UBL__)
#define __sf_section_RODATA_GFH     __attribute__ ((section ("BOOTLOADER_GFH_EXT")))
#if defined(__USB_FW_DL_SUPPORT__)
#define __sf_section_RAM
#else
#define __sf_section_RAM            __attribute__ ((section ("SECOND_PART")))
#endif
#else
#define __sf_section_RODATA_GFH     __attribute__ ((section ("MAUI_GFH_EXT")))
#define __sf_section_RAM            __attribute__ ((section ("SECOND_PART")))
#endif
#else  //__SV5_ENABLED__ || __SV5X_ENABLED__
/* SV3 */

// Method1
// #define __sf_section_RODATA_GFH    __attribute__ ((section ("SECOND_PART_RODATA")))
// Method2
#define __sf_section_RODATA_GFH

#define __sf_section_RAM           __attribute__ ((section ("SECOND_PART")))
#endif //__SV5_ENABLED__ || __SV5X_ENABLED__





#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
  #define  COMBO_MEM_TYPE_NAME  GFH_CMEM_NOR_INFO_v1
#else
  #define  COMBO_MEM_TYPE_NAME  CMEMEntryNORList
#endif

#define COMBO_MEM_INST_NAME combo_mem_sw_list
#define COMBO_MEM_TYPE_MODIFIER __sf_section_RODATA_GFH static const

#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
#define COMBO_MEM_STRUCT_HEAD  COMBO_MEM_NOR_GFH_HEADER, { COMBO_MEM_NOR_VER, COMBO_MEM_DEVICE_COUNT, {
#define COMBO_MEM_STRUCT_FOOT  } }
#else
#define COMBO_MEM_STRUCT_HEAD  COMBO_MEM_IDENTITY_NOR, COMBO_MEM_NOR_VER, COMBO_MEM_DEVICE_COUNT, {
#define COMBO_MEM_STRUCT_FOOT  }
#endif


#include "combo_flash_config.h"    // ==== Instantiate NOR flash table

static const CMEMEntryNOR *nor_list=NULL;


//-----------------------------------------------------------------------------
// Driver Interface and Driver Data
//-----------------------------------------------------------------------------
// System Info
#if !((defined(__FUE__) && defined(__FOTA_DM__)) || defined(__UBL__))
//---------------------------------------
// Part 1: NOR FDM Driver
//---------------------------------------
FS_Driver NORFlashDriver;           // FDM driver interface
NOR_FLASH_DRV_Data FlashDriveData;  // FDM driver data
kal_uint32 TOTAL_BLOCKS;            // Local define
kal_uint32 TOTAL_SECTORS;           // Local define
kal_uint32 NOR_LARGEST_BLOCK_SIZE;  // Local define (to replace NOR_BLOCK_SIZE)
static kal_uint16 PAGE_SIZE;        // Local define (CMEM only)
#ifdef __INTEL_SIBLEY__
kal_uint8 FDMBuffer[1024];          // FDM buffer
#else
kal_uint8 FDMBuffer[512];           // FDM buffer
#endif
static kal_uint16 AVAILSECTORS[CMEM_MAX_BLOCKS];     // Number of avail sectors in each block
static kal_uint16 VALIDSECTORS[CMEM_MAX_BLOCKS];     // Number of valid sectors in each block
static kal_uint8  SectorMap[CMEM_MAX_SECTORS];       // Address translation map

#if defined(__ERASE_QUEUE_ENABLE__)
static NOR_EraseInfo EraseBlockQueue[SNOR_ERASE_QUEUE_SIZE];   // Erase queue
#endif

static FlashRegionInfo RegionInfo[CMEM_REGION_INFO_LEN]; // RegionInfo[] assigned to FDM data

#elif (defined(__FUE__) || defined(__EXT_BOOTLOADER__)) && defined(__FOTA_DM__)
NOR_FLASH_DRV_Data FlashDriveData;
#endif // !((defined(__FUE__) && defined(__FOTA_DM__)) || defined(__UBL__))

static const FlashBlockLayout *BlockLayout;              // BlockLayout read from MCP list
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)           // BankInfo[] assigned to FDM data
static FlashBankInfo BankInfo[CMEM_REGION_INFO_LEN];
#else
const static FlashBankInfo *BankInfo;
#endif

static MS_ENTRY MSEntryTable[MS_TABLE_ENTRY_NUM];

//---------------------------------------
// Part 2: NOR MTD driver
//---------------------------------------
kal_uint32 PAGE_BUFFER_SIZE;              // Global Var. used by mtd driver

#ifdef __SERIAL_FLASH__
    NOR_MTD_Driver NORFlashMtd;           // SF driver interface
    SF_MTD_Data mtdflash;                 // SF driver data
    SF_Status StatusMap[SF_SR_COUNT];     // status map assigned to SF data (shall be read only after initialziation, it's shareable)
    SF_MTD_CMD sf_dal_data_cmd;           // command set assiged to SF data (shall be read only after initialziation, it's shareable)
#else
    NOR_MTD_Driver NORFlashMtd;           // ADM driver interface
    PF_MTD_Data mtdflash;                 // ADM driver data was instantiated in flash_mtd.amd.c or flash_mtd.intel.c.
    PF_Status StatusMap[PF_SR_COUNT];
    PF_MTD_CMD pf_dal_data_cmd; 		  // command set assiged to PF data (shall be read only after initialziation, it's shareable)
#endif

//---------------------------------------
// Part 3: NOR RAW Disk FDM/MTD driver
//---------------------------------------
#ifdef __NOR_SUPPORT_RAW_DISK__
PF_MTD_Data FlashDiskDriveData[NOR_BOOTING_NOR_DISK_NUM];
#ifdef __SERIAL_FLASH__
static SF_MTD_Data mtdFlashDisk[NOR_BOOTING_NOR_DISK_NUM];
#else  // __SERIAL_FLASH__
static NOR_Flash_MTD_Data mtdFlashDisk[NOR_BOOTING_NOR_DISK_NUM];
#endif // __SERIAL_FLASH__
#endif // __NOR_SUPPORT_RAW_DISK__

#if defined(__NOR_SUPPORT_RAW_DISK__) && defined(NOR_BOOTING_NOR_DISK_NUM)
#if (NOR_BOOTING_NOR_DISK_NUM>0)
FlashRegionInfo Disk0RegionInfo[CMEM_REGION_INFO_LEN];
#endif /* NOR_BOOTING_NOR_DISK_NUM>0 */
#if (NOR_BOOTING_NOR_DISK_NUM>1)
FlashRegionInfo Disk1RegionInfo[CMEM_REGION_INFO_LEN];
#endif // NOR_BOOTING_NOR_DISK_NUM
#endif // __NOR_SUPPORT_RAW_DISK__

//---------------------------------------
// Part 4: FOTA
//---------------------------------------

//---------------------------------------
// Part 5: NOR Full Driver
//---------------------------------------
// FDM driver data
static FlashRegionInfo EntireDiskRegionInfo[CMEM_REGION_INFO_LEN];
NOR_FLASH_DISK_Data EntireDiskDriveData;

#ifdef __SERIAL_FLASH__
    SF_MTD_Data EntireDiskMtdData;   // SF MTD driver data
#else
    PF_MTD_Data EntireDiskMtdData;   // ADM MTD driver data
#endif

//-----------------------------------------------------------------------------
// Internal Functions
//-----------------------------------------------------------------------------
// NOR Flash Driver Initialization

// 1. Entry Function
kal_int32 CMEM_Init_NOR(void);        // MAUI
kal_int32 CMEM_Init_FullDriver(void); // MAUI or BOOTLOADER (for Card Download and RAW disk)
kal_int32 CMEM_Init_FOTA(void);       // FOTA with MAUI
void      CMEM_Init_FUE(void);        // FOTA update engine

// 1.1 Common initilaization of the entry function
void      CMEM_Init_nor_list(void);

// ---<NOR>---
// 2. NOR FDM Initialization
kal_int32 CMEM_Init_NOR_FDM_Common(void);
kal_int32 CMEM_Init_NOR_FDM_NonSIB(void);
kal_int32 CMEM_Init_NOR_FDM_SIB(void);

// 3. NOR MTD Initialization
kal_int32 CMEM_Init_NOR_MTD_Common(void);
kal_int32 CMEM_Init_NOR_MTD_SF(void);
kal_int32 CMEM_Init_NOR_MTD_ADMUX(void);

// 4. NOR RAW Disk Initialization
kal_int32 CMEM_Init_NOR_RAWDisk_Common(void);
kal_int32 CMEM_Init_NOR_RAWDisk_SF(void);
kal_int32 CMEM_Init_NOR_RAWDisk_ADMUX(void);

// 5. EMI-INIT-NOR-driver
kal_uint32 EMIINIT_CMEM_BlockSize(kal_uint32 address);
kal_uint32 CMEM_NOR_Construct_RegionInfo_Internal(
        kal_uint32 baseaddr,
        kal_uint32 length,
        FlashRegionInfo *regioninfo,
        const FlashBlockLayout* blocklayout);
kal_int32 NOR_Construct_RegionInfo(kal_uint32 baseaddr, kal_uint32 length, FlashRegionInfo *regioninfo);
kal_int32 EMIINIT_CMEM_NOR_Construct_RegionInfo(kal_uint32 baseaddr, kal_uint32 length, FlashRegionInfo *regioninfo);

//-----------------------------------------------------------------------------
// External Function
//-----------------------------------------------------------------------------
extern kal_uint32 custom_get_fat_addr(void);
extern kal_uint32 INT_RetrieveFlashBaseAddr(void);
extern kal_uint32 custom_get_fat_len(void);
extern kal_uint32 custom_get_fat_addr(void);

#if !((defined(__FUE__) && defined(__FOTA_DM__)) || defined(__UBL__))

//-----------------------------------------------------------------------------
/*!
  @brief
    NOR Flash MTD interface/data common initialization
  @retval
    CMEM_NO_ERROR: Success
*/
kal_int32 CMEM_Init_NOR_MTD_Common(void)
{
    // 1. <DATA> Signature
    mtdflash.Signature = ~((kal_uint32)RegionInfo);

    // 2. <DATA> Page Buffer and Base Address
#if defined(__MTK_TARGET__)
   PAGE_BUFFER_SIZE = nor_list[cmem_nor_index].PageBufferSize;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   memset(mtdflash.lookup_tbl, 0xFF, sizeof(NOR_AddrLookup)*LOOKUP_TABLE_SIZE*2);
#endif // __SINGLE_BANK_NOR_FLASH_SUPPORT_
   mtdflash.BaseAddr = (BYTE *)(INT_RetrieveFlashBaseAddr() + NOR_FLASH_BASE_ADDRESS);
#endif // __MTK_TARGET__

    // 3. <DATA> RegionInfo and BankInfo
   mtdflash.RegionInfo = (FlashRegionInfo *)RegionInfo;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && (defined(__MULTI_BANK_NOR_DEVICE__) || defined(__ARM9_MMU__) || defined(__ARM11_MMU__))
   mtdflash.BankInfo = (FlashBankInfo*)BankInfo;
#endif  // __SINGLE_BANK_NOR_FLASH_SUPPORT__

   return CMEM_NO_ERROR;
}

#if defined(__SERIAL_FLASH__)
//-----------------------------------------------------------------------------
/*!
  @brief
    Serial NOR Flash MTD interface/data initialization
  @retval
    CMEM_NO_ERROR: Success
    CMEM_ERR_MTD_INIT_FAIL: Fail
*/
kal_int32 CMEM_Init_NOR_MTD_SF(void)
{
    kal_int32 result;

    // Assign MTD driver to FDM data
    FlashDriveData.MTDDriver = &NORFlashMtd;

    // Allocate status map and command for MTD data
    mtdflash.StatusMap = &StatusMap[0];
    mtdflash.CMD = &sf_dal_data_cmd;

    // serial Flash driver will initialize the interface/data by its own.
    result=SF_DAL_Init_Driver(
         &NORFlashMtd,   // Driver Interface (to FDM)
         &mtdflash,      // Driver Data
         (INT_RetrieveFlashBaseAddr() + NOR_FLASH_BASE_ADDRESS),   // Base Address
         nor_list[cmem_nor_index].UniformBlocks);                  // Uniform Block

    if (result==FS_FLASH_MOUNT_ERROR)    {
      return CMEM_ERR_MTD_INIT_FAIL;
    }
    return CMEM_NO_ERROR;
}

#else // __SERIAL_FLASH__

//-----------------------------------------------------------------------------
/*!
  @brief
    AMDUX NOR Flash MTD interface/data initialization
*/
kal_int32 CMEM_Init_NOR_MTD_ADMUX(void)
{

   kal_int32 result;

   // Assign MTD driver to FDM data
    FlashDriveData.MTDDriver = &NORFlashMtd;

   // Allocate status map and command for MTD data
   mtdflash.StatusMap = StatusMap;
   mtdflash.CMD = &pf_dal_data_cmd;

   // Admux NOR Flash driver will initialize the interface/data by its own.
   result=ADMUX_DAL_Init_Driver(
             &NORFlashMtd,   // Driver Interface (to FDM)
             &mtdflash,      // Driver Data
             (INT_RetrieveFlashBaseAddr() + NOR_FLASH_BASE_ADDRESS),   // Base Address
             nor_list[cmem_nor_index].FDMType);
   if (result==FS_FLASH_MOUNT_ERROR)
   {
      return CMEM_ERR_MTD_INIT_FAIL;
   }

    return CMEM_NO_ERROR;

}
#endif // __SERIAL_FLASH__

//-----------------------------------------------------------------------------
/*!
  @brief
    NOR Flash FDM 4.0 interface/data common initialization
*/
kal_int32 CMEM_Init_NOR_FDM_Common(void)
{
    // 1. <DATA> Assign MTD data to FDM
    FlashDriveData.MTDData = &mtdflash;

    // 2. <DATA> Common Data
    FlashDriveData.AvailSectorsInBlock = AVAILSECTORS;
    FlashDriveData.ValidSectorsInBlock = VALIDSECTORS;
    FlashDriveData.SectorMap = (kal_uint8*)SectorMap;
    FlashDriveData.PartitionSectors = NOR_PARTITION_SECTORS;
    FlashDriveData.Buffer = FDMBuffer;
    FlashDriveData.MSTABLE_ENTRY_NUM = MS_TABLE_ENTRY_NUM;	
    FlashDriveData.MSEntryTable = MSEntryTable;	

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
    FlashDriveData.queueSize = SNOR_ERASE_QUEUE_SIZE;
    #if defined (__ERASE_QUEUE_ENABLE__)
    FlashDriveData.EraseQueue = EraseBlockQueue;
    #endif
#else // !__SINGLE_BANK_NOR_FLASH_SUPPORT__
    FlashDriveData.SystemDriveReservedUnits = (kal_uint32)(NOR_SYSTEM_DRIVE_RESERVED_BLOCK * 2);  // The reserved unit is 0.5 block
#endif // __SINGLE_BANK_NOR_FLASH_SUPPORT__

    // 3. <INTERFACE> Common Interface
    NORFlashDriver.DiscardSectors=NULL;
#ifdef __SECURITY_OTP__
    NORFlashDriver.CopySectors=NULL; // copy sector
    NORFlashDriver.OTPAccess=OTPAccess;
    NORFlashDriver.OTPQueryLength=OTPQueryLength;
#endif
    NORFlashDriver.HighLevelFormat=NULL; // high level format
    NORFlashDriver.RecoverDisk=NULL;     // flush data
    NORFlashDriver.MessageAck=NULL;      // message ack
    NORFlashDriver.IOCtrl=NULL;

    return CMEM_NO_ERROR;
}

#if defined(__NON_INTEL_SIBLEY__)
//-----------------------------------------------------------------------------
/*!
  @brief
    NOR Flash FDM 4.0 interface/data initialization
*/
kal_int32 CMEM_Init_NOR_FDM_NonSIB(void)
{
    // FDM driver interface
    NORFlashDriver.MountDevice=NOR_MountDevice_ext;
    NORFlashDriver.ShutDown=NOR_ShutDown_ext;
    NORFlashDriver.ReadSectors=NOR_ReadSectors_ext;
    NORFlashDriver.WriteSectors=NOR_WriteSectors_ext;
    NORFlashDriver.MediaChanged=NOR_MediaChanged_ext;
    NORFlashDriver.DiscardSectors=NOR_DiscardSectors_ext;
    NORFlashDriver.GetDiskGeometry=NOR_GetDiskGeometry_ext;
    NORFlashDriver.LowLevelFormat=NOR_LowLevelFormat_ext;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
    NORFlashDriver.NonBlockWriteSectors=NULL;
#else
    NORFlashDriver.NonBlockWriteSectors=NOR_NonBlockWriteSectors_ext;
#endif // __SINGLE_BANK_NOR_FLASH_SUPPORT__
    NORFlashDriver.RecoverableWriteSectors=NOR_RecoverableWriteSectors_ext;
    NORFlashDriver.ResumeSectorStates=NOR_ResumeSectorStates_ext;

    // Sibley FDM driver data

#ifdef __BASIC_LOAD_FLASH_TEST__
    extern kal_uint32 LocateSector(NOR_FLASH_DRV_Data * D, kal_uint32 LogicalSector);
    LocateSector_ext = LocateSector;
#endif //__BASIC_LOAD_FLASH_TEST__

    return CMEM_NO_ERROR;
}
#endif

#if defined(__INTEL_SIBLEY__)
//-----------------------------------------------------------------------------
/*!
  @brief
    NOR Flash Sibley FDM 4.0 interface/data initialization
*/
kal_int32 CMEM_Init_NOR_FDM_SIB(void)
{
    // FDM driver interface
    NORFlashDriver.MountDevice=SIB_MountDevice;
    NORFlashDriver.ShutDown=NOR_ShutDown;
    NORFlashDriver.ReadSectors=SIB_ReadSectors;
    NORFlashDriver.WriteSectors=SIB_WriteSectors;
    NORFlashDriver.MediaChanged=NOR_MediaChanged;
    NORFlashDriver.DiscardSectors=SIB_DiscardSectors;
    NORFlashDriver.GetDiskGeometry=SIB_GetDiskGeometry;
    NORFlashDriver.LowLevelFormat=SIB_LowLevelFormat;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
    NORFlashDriver.NonBlockWriteSectors=NULL;
#else
    NORFlashDriver.NonBlockWriteSectors=SIB_NonBlockWriteSectors;
#endif // __SINGLE_BANK_NOR_FLASH_SUPPORT__
    NORFlashDriver.RecoverableWriteSectors=SIB_RecoverableWriteSectors;
    NORFlashDriver.ResumeSectorStates=SIB_ResumeSectorStates;

    // FDM driver data

#ifdef __BASIC_LOAD_FLASH_TEST__
    LocateSector_ext = SIB_LocateSector;
#endif //__BASIC_LOAD_FLASH_TEST__


    return CMEM_NO_ERROR;
}
#endif

#endif // !((defined(__FUE__) && defined(__FOTA_DM__)) || defined(__UBL__))


//-----------------------------------------------------------------------------
// Begin of SECOND_PART
//
// Put those functions in second part to avoid leakage near to the FS
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/*!
  @brief
    Returns the size of the block located at given address.
  @remarks
    This is a internal function placed in SECOND part, which can be called by FOTA, MAUI, and Bootloader
*/
__sf_section_RAM kal_uint32 CMEM_BlockSize_Internal(kal_uint32 address, const FlashBlockLayout* blocklayout)
{
    kal_uint16 i;

	address = address & (0x08000000-1);

    for (i=0; blocklayout[i+1].Size!=0; i++)   {
        if (address >= blocklayout[i].Offset &&
            address < blocklayout[i+1].Offset)  {
            break;
        }
    }
    return blocklayout[i].Size;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Returns the size of the block located at given address.
*/
__sf_section_RAM kal_uint32 CMEM_BlockSize(kal_uint32 address)
{
    return CMEM_BlockSize_Internal(address, BlockLayout);
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Returns the size of the block located at given address.
  @remarks
    For EMI init stage only, it will compare ID and match the correct settings.
*/
__sf_section_RAM kal_uint32 EMIINIT_CMEM_BlockSize(kal_uint32 address)
{
    kal_uint32 index=CMEM_EMIINIT_Index();
    const CMEMEntryNOR *list=NULL;

    #if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
        list=combo_mem_sw_list.m_data.List;
    #else
        list=combo_mem_sw_list.List;
    #endif  //__SV5_ENABLED__ || __SV5X_ENABLED__

    return CMEM_BlockSize_Internal(address, list[index].BlockLayout);
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Construct region info by combo MCP block info
*/
__sf_section_RAM kal_int32 NOR_Get_FlashSizeFromBankInfo(const FlashBankInfo *bankinfo)
{
	kal_uint32 result=0, i;

	// For all entries in the geometry info
    for (i=0; bankinfo[i].BankSize!=0; i++)   {
		result += bankinfo[i].Banks * bankinfo[i].BankSize;
    }
	return result;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Construct region info by combo MCP block info
  @remarks
    This is a internal function placed in SECOND part, which can be called by FOTA, MAUI, and Bootloader
*/
__sf_section_RAM kal_uint32 CMEM_NOR_Construct_RegionInfo_Internal(
    kal_uint32 baseaddr,
    kal_uint32 length,
    FlashRegionInfo *regioninfo,
    const FlashBlockLayout *blocklayout)
{
    kal_uint32 addr, ptr, blksize, total_blocks;
    kal_uint32 endaddr = baseaddr + length;

    // iterates all blocks
    for (addr=baseaddr, ptr=0, total_blocks=0; addr<endaddr; )   {
        blksize=CMEM_BlockSize_Internal(addr, blocklayout);
        // the block is the first entry of the first region
        if (total_blocks==0)   {
            regioninfo[ptr].BlockSize=blksize;
            regioninfo[ptr].RegionBlocks=1;
        }
        // the block belongs to the same region
        else if (blksize==regioninfo[ptr].BlockSize)    {
            regioninfo[ptr].RegionBlocks++;
        }
        // the block belongs to a new region
        else {
            ptr++;
            if (ptr==(CMEM_REGION_INFO_LEN+1))  {
                return CMEM_ERR_FDM_REGION_INFO_OVERFLOW;
            }
            regioninfo[ptr].BlockSize=blksize;
            regioninfo[ptr].RegionBlocks=1;
        }
        addr+=blksize;
        total_blocks++;
    }

    // TODO: Add bank boundary check and block boundary check

    return CMEM_NO_ERROR;
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Construct region info by combo MCP block info
*/
__sf_section_RAM kal_int32 NOR_Construct_RegionInfo(kal_uint32 baseaddr, kal_uint32 length, FlashRegionInfo *regioninfo)
{
    kal_mem_set(regioninfo, 0, sizeof(FlashRegionInfo)*CMEM_REGION_INFO_LEN);

    return CMEM_NOR_Construct_RegionInfo_Internal(baseaddr, length, regioninfo, BlockLayout);
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Construct region info by combo MCP block info
  @remarks
    For EMI init stage only, it will compare ID and match the correct settings.
*/
__sf_section_RAM kal_int32 EMIINIT_CMEM_NOR_Construct_RegionInfo(kal_uint32 baseaddr, kal_uint32 length, FlashRegionInfo *regioninfo)
{
    kal_uint32 index=CMEM_EMIINIT_Index();
    const CMEMEntryNOR *list=NULL;

    #if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
        list=combo_mem_sw_list.m_data.List;
    #else
        list=combo_mem_sw_list.List;
    #endif  //__SV5_ENABLED__ || __SV5X_ENABLED__

    return CMEM_NOR_Construct_RegionInfo_Internal(baseaddr, length, regioninfo, list[index].BlockLayout);
}

//-----------------------------------------------------------------------------
/*!
  @brief
    Retrieve Uniform block size
  @remarks
    For EMI init stage only, it will compare ID and match the correct settings.
*/
__sf_section_RAM kal_uint32 EMIINIT_CMEM_NOR_GetUniformBlock(void)
{
    kal_uint32 index=CMEM_EMIINIT_Index();
    const CMEMEntryNOR *list=NULL;

    #if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
        list=combo_mem_sw_list.m_data.List;
    #else
        list=combo_mem_sw_list.List;
    #endif  //__SV5_ENABLED__ || __SV5X_ENABLED__

    return list[index].UniformBlocks;
}

//-----------------------------------------------------------------------------
// End of SECOND_PART
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/*!
  @brief
    This function is used to construct bank info, and the caller is
    CMEM_NOR_Construct_BankInfo()
*/
void CMEM_NOR_AddBankInfo(FlashBankInfo *bankInfo, kal_uint32 *index, kal_uint32 bankSize)
{
   if(bankInfo[*index].BankSize == bankSize)
   {
      bankInfo[*index].Banks ++;
   }
   else
   {
      *index ++;
      bankInfo[*index].Banks = 1;
	  bankInfo[*index].BankSize= bankSize;
   }

}

//-----------------------------------------------------------------------------
/*!
  @brief
    Construct bank info of the given address/lenth according to the
    combo MCP bank info
*/
kal_uint32 CMEM_NOR_Construct_BankInfo(
    kal_uint32 baseaddr,
    kal_uint32 length,
    FlashBankInfo *bankInfo,
    const FlashBankInfo *cmemBankInfo)
{
	kal_uint32 Partition = 0;
	kal_int32 Index = 0;
	kal_uint32 bankSize;
	kal_uint32 NextBankAddr,srcBankIdx;

    kal_mem_set(bankInfo, 0, sizeof(FlashBankInfo)*CMEM_BANK_INFO_LEN);

    for(srcBankIdx = 0, NextBankAddr=0; length>0; srcBankIdx++)
    {
	   if(srcBankIdx >= cmemBankInfo[Partition].Banks)
	   {
	      srcBankIdx = 0; //BankIndex in current partition
		  Partition++;
	   }

	   NextBankAddr += cmemBankInfo[Partition].BankSize;

       if(baseaddr <= NextBankAddr) {
	      bankSize = NextBankAddr - baseaddr;
		  if(length < bankSize)
		     bankSize = length;

          //Add One Bank Info
		  if(bankInfo[Index].BankSize == bankSize)
		  {
			 bankInfo[Index].Banks ++;
		  }
		  else
		  {
		     if(bankInfo[Index].BankSize != 0) Index++;
			 bankInfo[Index].Banks = 1;
			 bankInfo[Index].BankSize= bankSize;
		  }

		  baseaddr += bankSize;
		  length -= bankSize;
	   }

    }


    return CMEM_NO_ERROR;
}



#if !((defined(__FUE__) && defined(__FOTA_DM__)) || defined(__UBL__))

//-----------------------------------------------------------------------------
/*!
  @brief
    NOR Flash initialization of MAUI
*/
kal_int32 CMEM_Init_NOR(void)
{
    kal_int32 result;
    kal_int32 i;

    // Total Blocks := Blocks in Region Info
    // Block Size := MAX(RegionInfo[i].BlockSize)
    BlockLayout=nor_list[cmem_nor_index].BlockLayout;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
    CMEM_NOR_Construct_BankInfo(custom_get_fat_addr(), custom_get_fat_len(), BankInfo, nor_list[cmem_nor_index].BankInfo);
#else
    BankInfo=nor_list[cmem_nor_index].BankInfo;
#endif

    // construct RegionInfo from block info and bank info
    result=NOR_Construct_RegionInfo(custom_get_fat_addr(), custom_get_fat_len(), RegionInfo);

    if (result!=CMEM_NO_ERROR)   {
        return result;
    }

    for (i=0, TOTAL_BLOCKS=0, NOR_LARGEST_BLOCK_SIZE=0 ;RegionInfo[i].BlockSize!=0;i++)    {
        TOTAL_BLOCKS += RegionInfo[i].RegionBlocks;
        if (RegionInfo[i].BlockSize > NOR_LARGEST_BLOCK_SIZE)
            NOR_LARGEST_BLOCK_SIZE = RegionInfo[i].BlockSize;
    }

    // 1. FDM data/interface initialization
    result=CMEM_Init_NOR_FDM_Common();
    if (result!=CMEM_NO_ERROR) return result;

    switch (nor_list[cmem_nor_index].FDMType)    {
        #if defined(__INTEL_SIBLEY__)
      case CMEM_NOR_CS_INTEL_SIBLEY:
            PAGE_SIZE=0x400;
            result=CMEM_Init_NOR_FDM_SIB();
            break;
        #endif
        #if defined(__NON_INTEL_SIBLEY__)
      default:
            PAGE_SIZE=0x200;
            result=CMEM_Init_NOR_FDM_NonSIB();
            break;
        #endif
#if !(defined(__INTEL_SIBLEY__) || defined(__NON_INTEL_SIBLEY__))
        default:
            result=CMEM_ERR_FDM_MISMATCH;
            break;
#endif
    }

    // Total Sectors := Flash Area / Page Size
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
    TOTAL_SECTORS =  ((NOR_ALLOCATED_FAT_SPACE - NOR_LARGEST_BLOCK_SIZE * SNOR_ERASE_QUEUE_SIZE) / PAGE_SIZE);
#else
    TOTAL_SECTORS =  (NOR_ALLOCATED_FAT_SPACE / PAGE_SIZE);
#endif

    if (result!=CMEM_NO_ERROR) return result;

    // 2. MTD data/interface initialization

    result=CMEM_Init_NOR_MTD_Common();
    if (result!=CMEM_NO_ERROR) return result;

    switch (cmem_id->DeviceType) {
        #if !defined(__SERIAL_FLASH__)
        case CMEM_TYPE_NOR:
            result=CMEM_Init_NOR_MTD_ADMUX();
            break;
        #else // __SERIAL_FLASH__
        case CMEM_TYPE_SERIAL_NOR_FLASH:
            result=CMEM_Init_NOR_MTD_SF();
            break;
        #endif // __SERIAL_FLASH__
        default:
            result=CMEM_ERR_MTD_MISMATCH;
            break;
    }

    if (result!=CMEM_NO_ERROR) return result;

    // 3. RAW disk initialization
    #ifdef __NOR_SUPPORT_RAW_DISK__
    result=CMEM_Init_NOR_RAWDisk_Common();
    switch (cmem_id->DeviceType) {
        #if !defined(__SERIAL_FLASH__)
        case CMEM_TYPE_NOR:
            result=CMEM_Init_NOR_RAWDisk_ADMUX();
            break;
        #else // __SERIAL_FLASH__
        case CMEM_TYPE_SERIAL_NOR_FLASH:
            result=CMEM_Init_NOR_RAWDisk_SF();
            break;
        #endif // __SERIAL_FLASH__
        default:
            result=CMEM_ERR_MTD_MISMATCH;
            break;
    }
    #endif

    return result;
}

#endif // !((defined(__FUE__) && defined(__FOTA_DM__)) || defined(__UBL__))


//-----------------------------------------------------------------------------
/*!
  @brief
    Compare device ID and retrieve the correspond NOR flash settings
*/
void CMEM_Init_nor_list(void)
{
#if ((!defined __FS_SYSDRV_ON_NAND__) && (!defined(_NAND_FLASH_BOOTING_)))
    cmem_nor_index=CMEM_Index();
    if (cmem_nor_index<0) ASSERT(0);//return CMEM_ERR_ID_NOT_FOUND;
    cmem_id=CMEM_GetIDEntry(cmem_nor_index);
#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__)
    nor_list=combo_mem_sw_list.m_data.List;  // SV5
#else
    nor_list=combo_mem_sw_list.List;         // SV3
#endif  //__SV5_ENABLED__ || __SV5X_ENABLED__

#endif //! __FS_SYSDRV_ON_NAND__ && !_NAND_FLASH_BOOTING_
}


//-----------------------------------------------------------------------------
// MCP Initialization Function
//-----------------------------------------------------------------------------
#if !((defined(__FUE__) && defined(__FOTA_DM__)) || defined(__UBL__))
//-----------------------------------------------------------------------------
/*!
  @brief
    Combo MCP intialization function for MAUI
  @param[in] type The type of initialization (reserved)
  @retval
    CMEM_NO_ERROR: Success
    otherwise: Fail
*/
kal_int32 ComboMem_Initialize(void)
{
#if ((!defined __FS_SYSDRV_ON_NAND__) && (!defined(_NAND_FLASH_BOOTING_)))
    CMEM_Init_nor_list();
        return CMEM_Init_NOR();
#else
        // NAND Flash driver has its own init functions
        return CMEM_NO_ERROR;
#endif
}
#endif // !((defined(__FUE__) && defined(__FOTA_DM__)) || defined(__UBL__))

//-----------------------------------------------------------------------------
/*!
  @brief
    NOR Flash RAW Disk initialization
*/
#ifdef __NOR_SUPPORT_RAW_DISK__
kal_int32 CMEM_Init_NOR_RAWDisk_Common(void)
{
   mtdFlashDisk[0].Signature = ~((kal_uint32)Disk0RegionInfo);
   mtdFlashDisk[0].BaseAddr = (BYTE *)(INT_RetrieveFlashBaseAddr() + NOR_BOOTING_NOR_DISK0_BASE_ADDRESS);
   mtdFlashDisk[0].RegionInfo = (FlashRegionInfo *)Disk0RegionInfo;
   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   memset(mtdFlashDisk[0].lookup_tbl, 0xFF, sizeof(NOR_AddrLookup)*LOOKUP_TABLE_SIZE*2);
   #endif
   FlashDiskDriveData[0].DiskSize = NOR_BOOTING_NOR_DISK0_SIZE;

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
    return CMEM_NO_ERROR;
}



#if !defined(__SERIAL_FLASH__)
//-----------------------------------------------------------------------------
/*!
  @brief
    ADMUX NOR Flash RAW Disk initialization
*/
kal_int32 CMEM_Init_NOR_RAWDisk_ADMUX(void)
{

   kal_int32 result;

   NOR_Construct_RegionInfo(NOR_BOOTING_NOR_DISK0_BASE_ADDRESS, NOR_BOOTING_NOR_DISK0_SIZE, Disk0RegionInfo);
   NOR_Construct_RegionInfo(NOR_BOOTING_NOR_DISK1_BASE_ADDRESS, NOR_BOOTING_NOR_DISK1_SIZE, Disk1RegionInfo);

   // Assign RAW Disk 0 interface
    FlashDiskDriveData[0].MTDDriver = &NORFlashMtd;
    mtdFlashDisk[0].CMD=&sf_dal_data_cmd;
    mtdFlashDisk[0].StatusMap=&StatusMap[0];

   // RAW Disk 0 MTD
   result=ADMUX_DAL_Init_Driver(
             &NORFlashMtd,			 // Driver Interface
             &mtdFlashDisk[0],		// Driver Data
             (INT_RetrieveFlashBaseAddr() + NOR_BOOTING_NOR_DISK0_BASE_ADDRESS),   // Base Address
             0);					// Reserved: Driver Type

   if (result==FS_FLASH_MOUNT_ERROR)
   {
      return CMEM_ERR_MTD_INIT_FAIL;
   }

#if (NOR_BOOTING_NOR_DISK_NUM > 1)
   // Assign RAW Disk 1 interface
    FlashDiskDriveData[1].MTDDriver = &NORFlashMtd;
    mtdFlashDisk[1].CMD=&sf_dal_data_cmd;
    mtdFlashDisk[1].StatusMap=&StatusMap[0];


   // RAW Disk 0 MTD
   result=ADMUX_DAL_Init_Driver(
             &NORFlashMtd,			 // Driver Interface
             &mtdFlashDisk[1],		// Driver Data
             (INT_RetrieveFlashBaseAddr() + NOR_BOOTING_NOR_DISK1_BASE_ADDRESS),   // Base Address
             0);					// Reserved: Driver Type
#endif
    return CMEM_NO_ERROR;
}

#else // __SERIAL_FLASH__

//-----------------------------------------------------------------------------
/*!
  @brief
    Serial NOR Flash RAW Disk initialization
*/
kal_int32 CMEM_Init_NOR_RAWDisk_SF(void)
{
    kal_int32 result;

    NOR_Construct_RegionInfo(NOR_BOOTING_NOR_DISK0_BASE_ADDRESS, NOR_BOOTING_NOR_DISK0_SIZE, Disk0RegionInfo);
    NOR_Construct_RegionInfo(NOR_BOOTING_NOR_DISK1_BASE_ADDRESS, NOR_BOOTING_NOR_DISK1_SIZE, Disk1RegionInfo);

    // Assign RAW Disk 0 interface
    FlashDiskDriveData[0].MTDDriver = &NORFlashMtd;

    mtdFlashDisk[0].CMD=&sf_dal_data_cmd;
    mtdFlashDisk[0].StatusMap=&StatusMap[0];

    // RAW Disk 0 MTD
    result=SF_DAL_Init_Driver(
         &NORFlashMtd,           // Driver Interface
         &mtdFlashDisk[0],      // Driver Data
         (INT_RetrieveFlashBaseAddr() + NOR_BOOTING_NOR_DISK0_BASE_ADDRESS),   // Base Address
         nor_list[cmem_nor_index].UniformBlocks);                  // Uniform Block

    if (result==FS_FLASH_MOUNT_ERROR)    {
      return CMEM_ERR_MTD_INIT_FAIL;
    }

#if (NOR_BOOTING_NOR_DISK_NUM > 1)
    // Assign RAW Disk 1 interface
    FlashDiskDriveData[1].MTDDriver = &NORFlashMtd;

    mtdFlashDisk[1].CMD=&sf_dal_data_cmd;
    mtdFlashDisk[1].StatusMap=&StatusMap[0];

    // RAW Disk 0 MTD
    result=SF_DAL_Init_Driver(
         &NORFlashMtd,           // Driver Interface
         &mtdFlashDisk[1],      // Driver Data
         (INT_RetrieveFlashBaseAddr() + NOR_BOOTING_NOR_DISK1_BASE_ADDRESS),   // Base Address
         nor_list[cmem_nor_index].UniformBlocks);                  // Uniform Block
#endif
    return CMEM_NO_ERROR;

}
#endif // __SERIAL_FLASH__
#endif // __NOR_SUPPORT_RAW_DISK__

//-----------------------------------------------------------------------------
/*!
  @brief
    NOR Flash FOTA initialization
*/
#ifdef __FOTA_DM__
#if (!defined(__UBL__) && !defined(__FUE__))

extern NOR_FLASH_DRV_Data    NORFlashDriveData; //fota_partial.c

#if defined(__SERIAL_FLASH__)
SF_MTD_Data CMEM_FOTA_nor_mtdflash;
#else
PF_MTD_Data CMEM_FOTA_nor_mtdflash;
#endif

FlashRegionInfo CMEM_FOTA_NORRegionInfo[CMEM_REGION_INFO_LEN];

//-----------------------------------------------------------------------------
/*!
  @brief
    FOTA initialization Entry Function
*/
kal_int32 CMEM_Init_FOTA(void)
{

    kal_int32 result;

    CMEM_Init_nor_list();

    /* Initialize MTD data table */
    CMEM_FOTA_nor_mtdflash.Signature = ~((kal_uint32)CMEM_FOTA_NORRegionInfo);

    NORFlashDriveData.MTDDriver = &NORFlashMtd;
    NORFlashDriveData.MTDData = &CMEM_FOTA_nor_mtdflash;

    PAGE_BUFFER_SIZE = nor_list[cmem_nor_index].PageBufferSize;

    BlockLayout=nor_list[cmem_nor_index].BlockLayout;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
    kal_mem_cpy(BankInfo, nor_list[cmem_nor_index].BankInfo, sizeof(FlashBankInfo)*CMEM_REGION_INFO_LEN);
#else
    BankInfo=nor_list[cmem_nor_index].BankInfo;
#endif


#ifdef __MTK_TARGET__
    CMEM_FOTA_nor_mtdflash.BaseAddr = (BYTE *)INT_RetrieveFlashBaseAddr();
#endif /* __MTK_TARGET__ */


    CMEM_FOTA_nor_mtdflash.RegionInfo = (FlashRegionInfo *)CMEM_FOTA_NORRegionInfo;
    NOR_Construct_RegionInfo(0, custom_get_NORFLASH_Size(), CMEM_FOTA_NORRegionInfo);

#if  defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__MULTI_BANK_NOR_DEVICE__)
    CMEM_FOTA_nor_mtdflash.BankInfo = nor_list[cmem_nor_index].BankInfo;
#endif

		// Allocate status map and command for MTD data
		CMEM_FOTA_nor_mtdflash.StatusMap = StatusMap;

#if defined(__SERIAL_FLASH__)

		// serial Flash driver will initialize the interface/data by its own.

		CMEM_FOTA_nor_mtdflash.CMD = &sf_dal_data_cmd;

		result=SF_DAL_Init_Driver(
				   &NORFlashMtd,			// Driver Interface (to FDM)
				   &CMEM_FOTA_nor_mtdflash,		// Driver Data
				   (kal_uint32)CMEM_FOTA_nor_mtdflash.BaseAddr,	 // Base Address
				   nor_list[cmem_nor_index].UniformBlocks);                 // Uniform Block
#else //ADMUX flash
		CMEM_FOTA_nor_mtdflash.CMD = &pf_dal_data_cmd;

		result=ADMUX_DAL_Init_Driver(
				   &NORFlashMtd,			// Driver Interface (to FDM)
				   &CMEM_FOTA_nor_mtdflash,		// Driver Data
				   (kal_uint32)CMEM_FOTA_nor_mtdflash.BaseAddr,	 // Base Address
				   nor_list[cmem_nor_index].FDMType);					   // Reserved: Driver Type

#endif // __SERIAL_FLASH__

    return CMEM_NO_ERROR;
}
#endif // !(__UBL__) && !(__FUE__)
#endif // __FOTA_DM__

extern kal_int32 EMI_QueryIsRemapped(void);

//-----------------------------------------------------------------------------
/*!
  @brief
    Full driver  initialization Entry Function
  @remarks
    EntireFlashDisk (SecurDisk, Card Download)
*/
kal_int32 CMEM_Init_FullDriver(void)
{
   kal_int32 result;

    CMEM_Init_nor_list();

    PAGE_BUFFER_SIZE = nor_list[cmem_nor_index].PageBufferSize;

    BlockLayout=nor_list[cmem_nor_index].BlockLayout;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_mem_cpy(BankInfo, nor_list[cmem_nor_index].BankInfo, sizeof(FlashBankInfo)*CMEM_REGION_INFO_LEN);
#else
   BankInfo=nor_list[cmem_nor_index].BankInfo;
#endif

   // Allocate status map and command for MTD data
   EntireDiskMtdData.StatusMap = &StatusMap[0];
#ifdef __SERIAL_FLASH__
   EntireDiskMtdData.CMD = &sf_dal_data_cmd;
#else
   EntireDiskMtdData.CMD = &pf_dal_data_cmd;
#endif

   EntireDiskMtdData.Signature = ~((kal_uint32)EntireDiskRegionInfo);
   #if defined(MT6290)
   //For MT6290, No EMI driver
       #ifdef __UBL__
	EntireDiskMtdData.BaseAddr = (BYTE *)0xA0000000;
       #else
       EntireDiskMtdData.BaseAddr = (BYTE *)INT_RetrieveFlashBaseAddr();
       #endif
   #else
   #ifdef __UBL__
   //begin from MT6255, remapping is done before NOR_ReadID
   if(EMI_QueryIsRemapped())
       EntireDiskMtdData.BaseAddr = (BYTE *)0x10000000;
   else
       EntireDiskMtdData.BaseAddr = (BYTE *)0;
   
   #else
   EntireDiskMtdData.BaseAddr = (BYTE *)INT_RetrieveFlashBaseAddr();
   #endif
   #endif

#if defined(__SERIAL_FLASH__)
   // serial Flash driver will initialize the interface/data by its own.
   result=SF_DAL_Init_Driver(
        &NORFlashMtd,            // Driver Interface (to FDM)
        &EntireDiskMtdData,      // Driver Data
        (kal_uint32)EntireDiskMtdData.BaseAddr,   // Base Address
        nor_list[cmem_nor_index].UniformBlocks);                 // Uniform Block
#else //ADMUX flash

   result=ADMUX_DAL_Init_Driver(
        &NORFlashMtd,            // Driver Interface (to FDM)
        &EntireDiskMtdData,      // Driver Data
        (kal_uint32)EntireDiskMtdData.BaseAddr,   // Base Address
        nor_list[cmem_nor_index].FDMType);                      // Reserved: Driver Type

#endif // __SERIAL_FLASH__

   ASSERT(result!=FS_FLASH_MOUNT_ERROR);

   EntireDiskDriveData.DiskSize = NOR_Get_FlashSizeFromBankInfo(BankInfo);
   NOR_Construct_RegionInfo(0, EntireDiskDriveData.DiskSize, EntireDiskRegionInfo);
   EntireDiskMtdData.RegionInfo = (FlashRegionInfo *)EntireDiskRegionInfo;

   EntireDiskDriveData.MTDDriver = &NORFlashMtd;
   EntireDiskDriveData.MTDData = &EntireDiskMtdData;
   EntireDiskDriveData.is_mount = KAL_FALSE;

   return CMEM_NO_ERROR;
}

#if (defined(__FUE__) || defined(__EXT_BOOTLOADER__)) && defined(__FOTA_DM__)
#include "custom_fota.h"

extern kal_uint32 SSF_GetUAImageLoadAddress(void);

#ifdef __SERIAL_FLASH__
SF_MTD_Data fue_nor_mtdflash;
SF_Status fue_sf_srmap[SF_SR_COUNT];
SF_MTD_CMD fue_sf_cmd;
#else
PF_MTD_Data fue_nor_mtdflash;
PF_Status fue_pf_srmap[SF_SR_COUNT];
PF_MTD_CMD fue_pf_cmd;
#endif // __SERIAL_FLASH__

extern NOR_MTD_Driver NORFlashMtd;

void CMEM_Init_FUE(void)
{
    kal_int32 result;
    kal_uint32 blk_addr = 0;

    CMEM_Init_nor_list();

    PAGE_BUFFER_SIZE = nor_list[cmem_nor_index].PageBufferSize;

    BlockLayout=nor_list[cmem_nor_index].BlockLayout;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
    kal_mem_cpy(BankInfo, nor_list[cmem_nor_index].BankInfo, sizeof(FlashBankInfo)*CMEM_REGION_INFO_LEN);
#else
    BankInfo=nor_list[cmem_nor_index].BankInfo;
#endif

    // construct NORRegionInfo from block info and bank info
    // ***Note: NORRegionInfo[] body is instantiated in custom_fota.c
    result=NOR_Construct_RegionInfo(0, custom_get_NORFLASH_Size(), NORRegionInfo);

    ASSERT(result==CMEM_NO_ERROR);

    /* Initialize MTD data table */
    fue_nor_mtdflash.Signature = ~((kal_uint32)NORRegionInfo);

    FlashDriveData.MTDDriver = &NORFlashMtd;
    FlashDriveData.MTDData = &fue_nor_mtdflash;

#ifdef __MTK_TARGET__

   #if defined(MT6238) || defined(MT6235) || defined(MT6239) || defined(MT6235B)
   fue_nor_mtdflash.BaseAddr = (BYTE *)(custom_get_NORFLASH_Base()|0x08000000);
   #elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(MT6268T)
   fue_nor_mtdflash.BaseAddr = (BYTE *)(custom_get_NORFLASH_Base()|0x04000000);
   #else
   fue_nor_mtdflash.BaseAddr = (BYTE *)custom_get_NORFLASH_Base();
   #endif

   #ifdef __SERIAL_FLASH__
   fue_nor_mtdflash.CMD = &fue_sf_cmd;
   fue_nor_mtdflash.StatusMap = fue_sf_srmap;
   SF_DAL_Init_Driver(&NORFlashMtd, &fue_nor_mtdflash, (kal_uint32)fue_nor_mtdflash.BaseAddr, nor_list[cmem_nor_index].UniformBlocks);
   #else //ADMUX with combo memory support on
   fue_nor_mtdflash.CMD = &fue_pf_cmd;
   fue_nor_mtdflash.StatusMap = fue_pf_srmap;
   ADMUX_DAL_Init_Driver(&NORFlashMtd, &fue_nor_mtdflash, (kal_uint32)fue_nor_mtdflash.BaseAddr, nor_list[cmem_nor_index].FDMType);
   #endif // __SERIAL_FLASH__

#endif /* __MTK_TARGET__ */

   fue_nor_mtdflash.RegionInfo = (FlashRegionInfo *)NORRegionInfo;
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__MULTI_BANK_NOR_DEVICE__)
   fue_nor_mtdflash.BankInfo = (FlashBankInfo*)FOTANORBankInfo;
#endif

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

}

#endif // (__FUE__ || __EXT_BOOTLOADER__) && __FOTA_DM__


#endif // ( !defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_) )

#endif // (__COMBO_MEMORY_SUPPORT__) || defined(__SERIAL_FLASH__)

