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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *  FlashConf.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to configure flash device for FAT.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef DRVFLASH_H
#define DRVFLASH_H

/*---------------------------------------------
 * Included Header Files
 *---------------------------------------------*/

#include "fs_type.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_internal_api.h"
#include "fs_gprot.h"

// default turn on FDM4 enhancement
#define __NOR_FDM_4_FLIPPING_TOLERABLE__

#ifdef FLASH_DISKDRV_DEBUG
#define __fs_packed_prefix
#define __fs_packed_postfix
#endif

// MTD driver
#define REGION_NUM 8
#define NON_BLOCK_STATUS  (0x8) //4 bit pattern for version check

//FOR FDM5
#define INVALID_BLOCK_ID 0xffff
#define INVALID_TABLE_ID 0xffff
#define INVALID_LOGICAL_NUM 0xffffff
#define INVALID_NOR_ADDR 0xffffffff
#define INVALID_PHY_PAGE 0xffffffff
#define INVALID_ENTRY 0xffff

//FOR FDM4
#define INVALID_BLOCK_INDEX   0xFFFFFFFF
#define INVALID_SECTOR_INDEX  0xFFFFFFFF
#define INVALID_ERASE_COUNT   0x00FFFFFF // we only have 24 bits
#define MAX_ERASE_COUNT       (INVALID_ERASE_COUNT-1)

/* Global defines */
#define SPARE_RESERVED_RATIO                    (10)
#define MINIMUM_SPARE_AMOUNT                    (2)
#define SLEEP_MODE_SPARE_AMOUNT                 (4)
#define GC_THRESHOLD_DIVISION                   (3)
#define GC_THRESHOLD_GAP                        (1)
#define RESERVED_SECTOR_FOR_MINIMUM_SPARE_SPACE (4) ///< The number of additional reserved sectors if erase queue size is set to the minimum value (2)
#define RESERVED_SECTOR_FOR_REPEATE_POWER_LOSS_DURING_RECLAIM (6) ///< The number of additional reserved sectors if erase queue size is set to the minimum value (2)
#define MINIMUM_SYSTEM_DRIVE_RESERVE_BLOCK      (3) ///< minimum System Drive Reserved Blocks (unit: block)

/******** RESULT for Single Bank ************/
#define RESULT_FLASH_DONE (1)
#define RESULT_FLASH_BUSY (0)
#define RESULT_FLASH_FAIL (-1)

#ifndef __MTK_TARGET__
#pragma pack(1)
#endif
typedef __fs_packed_prefix struct {
   kal_uint32 TotalBlocks;
   kal_uint32 BlockSize[REGION_NUM];
   kal_uint32 AvailInRegion[REGION_NUM];       ///< empty and the number of blocks in erase queue
   kal_uint32 RegionBlocks[REGION_NUM];
   kal_uint32 ActualRegionNum;
   WORD  PageSize;
   kal_uint32 baseUnlockBlock;                 ///< Add because FOTA need to unlock different region in INTEL flash
   kal_uint32 endUnlockBlock;                  ///< Add because FOTA need to unlock different region in INTEL flash
} __fs_packed_postfix NOR_MTD_FlashInfo;
#ifndef __MTK_TARGET__
#pragma pack()
#endif

/* add ONE_BYTE_ALIGN_ADS keyword to this struct so that it won't violate ARM's ADS compiler rule.
 * No need, since this structure is included into another ONE_BYTE_ALIGN_ADS structure in pointer form
 */
typedef struct {
   int     (* MountDevice)  (void * DriveData, void * Info);
   int     (* ShutDown)     (void * DriveData);
   void *  (* MapWindow)    (void * DriveData, kal_uint32 BlockIndex, kal_uint32 WindowIndex);
   int     (* EraseBlock)   (void * DriveData, kal_uint32 BlockIndex);
   int     (* ProgramData)  (void * DriveData, void * Address, void * Data, UINT Length);
   int     (*NonBlockEraseBlock) (void * DriveData, kal_uint32  BlockIndex); /* Added by Eric */
   int     (*CheckDeviceReady)   (void * DriveData, kal_uint32 BlockIndex); /* Added by Eric */
   int     (*SuspendErase)       (void * DriveData, kal_uint32 BlockIndex); /* Added by Eric */
   int     (*ResumeErase)        (void * DriveData, kal_uint32 BlockIndex); /* Added by Eric */
   int     (*BlankCheck)             (void * DriveData, kal_uint32 BlockIndex);
   int     (*OTPAccess)           (void * DriveData, int accesstype, UINT Offset, void * BufferPtr, UINT Length);
   int     (*OTPQueryLength)      (void * DriveData, UINT *Length);
   int     (*LockEraseBlkAddr)         (void * DriveData, void *Address,UINT Action);
   kal_bool (*IsEraseSuspended)     (void * DriveData, kal_uint32 BlockIndex);
   int     (*IOCtrl)        (void * DriveData, UINT CtrlAction, void * CtrlData); // For device IO control
   //mtk03694 : this is a new API for WAT chip, because we have NO forced suspend & resume function.
   //                 So if someone use direct read while the flash is erasing or programing, the value will be wrong.
   #ifdef __LTE_RAT__
   int     (* ReadData)  (void * DriveData, void * Address, void * Data, UINT Length);      
   #endif
} NOR_MTD_Driver;

/*LockEraseBlkAddr Action*/
#define ACTION_UNLOCK 0
#define ACTION_LOCK 1
#define ACTION_ERASE 2


// This is the file MTD for testing only

typedef struct {
   const  char * FileName;
   kal_uint32  FileSize;
   kal_uint32  BlockSize;
   kal_uint32  WindowSize;
   HANDLE H;
   BYTE * BaseAddr;
   void * CurrAddr;
} NORMtdFileData;


// Flash Info
typedef struct {
   kal_uint32 BlockSize;
   kal_uint32 RegionBlocks;
} FlashRegionInfo;
#define EndRegionInfo  {0, 0}

typedef struct {
   kal_uint32 BankSize;
   kal_uint32 Banks;
} FlashBankInfo;
#define EndBankInfo  {0, 0}

// Erase block Info
/* add ONE_BYTE_ALIGN_ADS keyword to this struct so that it won't violate ARM's ADS compiler rule.
 * No need, since this structure is included into another ONE_BYTE_ALIGN_ADS structure in pointer form
 */
typedef struct {
   kal_uint32 BlockIndex;
   kal_uint32 EraseCount;
} NOR_EraseInfo;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
// address look up buffer
#define LOOKUP_TABLE_SIZE  (8)
typedef struct {
   kal_uint32 BlockIndex;
   kal_uint32 BaseAddress;
} NOR_AddrLookup;
#endif

typedef struct {
   kal_uint32  Signature;
   BYTE * BaseAddr;
   kal_semid          DeviceLock;       // The device lock that keeps driver resource consistent
   kal_taskid         DeviceLockOwner;  // The owner of the deivce lock
   kal_int8           DeviceLockDepth;  // The depth of the deivce lock

   FlashRegionInfo * RegionInfo;
   BYTE * CurrAddr;
   FlashBankInfo *BankInfo;
   BYTE * CurrBankAddr;
   kal_uint32 CurrBankSize;
   BYTE * CurrPollAddr;
#ifndef __MTK_TARGET__
   const char        *FileName;
   void              *flash_device;
   BYTE              *rootMTDcache;
   BYTE              *MTDcache;
   kal_uint32             first;
   kal_uint32             last_WinAddr;
   kal_uint32             last_region;
#endif
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   NOR_AddrLookup  lookup_tbl[LOOKUP_TABLE_SIZE][2];
#endif
} NOR_Flash_MTD_Data;

#ifndef __MTK_TARGET__
   #ifndef FLASH_DISKDRV_DEBUG
      #define MakeMtdFlashData(a, b)   0x0, 0x000000, b, NULL, "..\\..\\fs\\flash_device.img", NULL, NULL, NULL
   #else
      #define MakeMtdFlashData(a, b)   0x0, 0x000000, b, NULL, "..\\flash_device.img", NULL, NULL, NULL
   #endif
#else
#define MakeMtdFlashData(a, b)   a, b, NULL
#endif

/* Multi-sector Protection Entry */
#ifndef __MTK_TARGET__
#pragma pack(1)
#endif

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
/* Erase queue data structure */
typedef __fs_packed_prefix struct {
   kal_uint32 head;
   kal_uint32 tail;
   kal_uint32* queue;
}__fs_packed_postfix NOR_EraseQueue;
/* Flash state maintainence */
typedef enum
{
	NOR_IN_READY = 0xF0,
	NOR_IN_PROGRAM,
	NOR_IN_SUSPENDED_PROGRAM,
	NOR_IN_ERASE,
	NOR_IN_SUSPENDED_ERASE,
	NOR_IN_ERROR
} NOR_Flash_State;

extern NOR_Flash_State FlashState;

#define Query_Flash_State(a) \
{\
   a = FlashState; \
}

#define Set_Flash_State(a) \
{\
   FlashState = a; \
}

#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

typedef __fs_packed_prefix struct {
   kal_uint32 LogicalSectorID;
   kal_uint32 PysicalSectorID_new;
}__fs_packed_postfix MS_ENTRY;


#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && !defined(__NOR_IDLE_SWEEP__)
   #define __ERASE_QUEUE_ENABLE__
#endif // __SINGLE_BANK_NOR_FLASH_SUPPORT__ && !__NOR_IDLE_SWEEP__

// Flash driver's data
typedef __fs_packed_prefix struct NOR_FLASH_DRV_Data{
   kal_uint32    TotalFATSectors;        ///< Total number of FAT sectors in flash (i.e., TotalPhysicalSectors - reserved sectors)
   NOR_MTD_Driver *MTDDriver;       ///< MTD driver
   void    *MTDData;                ///< MTD data
   WORD    *AvailSectorsInBlock;    ///< The number of SECTOR_AVAIL in each block
   WORD    *ValidSectorsInBlock;    ///< The number of valid sectors (not SECTOR_AVAIL && not SECTOR_DELETED)
   NOR_MTD_FlashInfo FlashInfo;     ///< Flash information
   kal_uint32    HeaderSize[REGION_NUM]; ///< Size (bytes) from the beginning of a block address to the first data sector (i.e., contains both block and sector headers)
   kal_uint32    SectorsPerBlock[REGION_NUM];    ///< Number of "physical" sectors (exclude sectors for header) in each block of the same region
   kal_uint32    ActiveBlock;            ///< Current active block ID
   kal_uint32    ReclaimEraseCount;      ///< Erase count of the reclaimed block
   kal_uint32    ReclaimBlockID;         ///< Block ID of the reclaimed block
   kal_uint32    TotalPhysicalSectors;   ///< Total number of "physical" sector (exclude sectors for header) in flash. (For each region, TotalPhysicalSectors += RegionBlocks[region] * SectorsPerBlock[region])
   kal_uint32    PartitionSectors;       ///< Size of the first FAT partition (unit: sectors)
   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   kal_uint32    GCBlockSectors;         ///< The maximum number of sectors of a block in flash (i.e., MaxSectorsPerBlock)
   #endif
   kal_uint32    GCThreshold;            ///< GC threshold for Multi-Bank (2 maximum block + sectors for MSP)
   kal_uint32    AvailSectors;           ///< Total SECTOR_AVAIL sectors in flash (of course, exclude sectors for headers)
   kal_uint32    DeletedSectors;         ///< The number of deleted sectors in system (Increased in DeletePhysicalSector, MountDevice, ResumeSectorStates)
   kal_uint32    StartSector;            ///< Start "logical sector ID" for write or marking to process
   kal_uint32    Sectors;                ///< Total number of logical sectors to be updated (set in MarkToProcess)
   kal_uint32    SectorsLeft;            ///< The number of logical sectors left to be updated. i.e., The number of sectors whose update bit is set. (set in MarkToProcess and be decreased in MarkProcessed)
   kal_uint32    BLOCKID_OFFSET;         ///< Block offset, calculated by MaxSectorsPerBlock
   kal_uint32    SECTORIDX_MASK;         ///< Mask for retrieve sector index inside a block
   kal_uint32    PHY_SECTOR_OFFSET;      ///< Offset for retriving first 7 bits of PhysicalSector (i.e., Block offset + Local sector offset - 7)

   kal_uint32    MSTABLE_ENTRY_NUM;
   kal_uint32    MS_count;               ///< The number of valid entries in MS Entry Table
   MS_ENTRY *MSEntryTable;
   BYTE    *SectorMap;              ///< Sector map, built in MountDevice
   BYTE    *Buffer;                 ///< FDM Buffer: SIBLEY(1024 bytes) / Others (512 bytes), used when source data is located in the same bank (ESB, movee sectors in ReclaimBlock_pre...)

   void (*CompleteErase)(struct NOR_FLASH_DRV_Data * D);

   kal_uint32    RegionMaxBlock;         ///< (The first) region ID which contains blocks that have maximum number of sectors (to not let such block is selected as active block when the block is the only one left in this region, which makes Program Fail handle properly)
   
   void    (*ProgramFailHandle)  (struct NOR_FLASH_DRV_Data * D);
   void    (*ReclaimBlock_post)  (struct NOR_FLASH_DRV_Data * D);
   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) || defined(__NOR_IDLE_SWEEP__)
   kal_uint32    IdleReclaimBlockID;     ///< Block ID to be reclaimed in IdleReclaim task (IDLER)
   kal_uint32   (*SelectReclaimTarget)(struct NOR_FLASH_DRV_Data * D);
   kal_uint32   (* ReclaimOneSector)  (struct NOR_FLASH_DRV_Data * D, kal_uint32 Target, kal_uint32 sector);
   #endif //__SINGLE_BANK_NOR_FLASH_SUPPORT__ || __NOR_IDLE_SWEEP__

   #ifdef __NOR_IDLE_SWEEP__
   kal_uint32    IdleSweepThreshold;     ///< Threshold to trigger Idle Sweep
   #endif

   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   WORD     queueSize;              ///< The size of EraseQueue, default size = 5 (SNOR_ERASE_QUEUE_SIZE)
   #else
   WORD     SystemDriveReservedUnits;   ///< The number of reserved unit (1 unit = 0.5 block), default size = 6 (NOR_SYSTEM_DRIVE_RESERVED_BLOCK * 2)
   #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

   #ifdef __NOR_IDLE_SWEEP__
   BYTE          BlockReclaimingMark;
   #endif
   kal_bool    ProgramFailRetry;

   

}__fs_packed_postfix NOR_FLASH_DRV_Data;

#ifdef __MTK_TARGET__

extern kal_mutexid fdm_reclaim_mutex;
extern kal_eventgrpid  nor_egid;
#define NOR_BRECL_EVENT 0x1
#define NOR_FRECL_EVENT 0x2
#define NOR_DMAN_EVENT 0x4

#endif

/* Flash Bank Info */
typedef struct {
   kal_uint32 BankSize;
   kal_uint32 Banks;
} NORBankInfo;
#define EndBankInfo  {0, 0}

/* Flash Layout Info */
typedef struct {
   kal_uint32 TotalLSMT;
   kal_uint32 BlkSize;
   kal_uint32 PageSize;
   NORBankInfo *BankInfo;
   WORD TblEntrys;
   WORD TotalBlks;
} NORLayoutInfo;

typedef struct {
   kal_uint32  Signature;
   BYTE * BaseAddr;
   kal_semid          DeviceLock;       // The device lock that protects driver resource 
   kal_taskid         DeviceLockOwner;  // The owner of the deivce lock
   kal_int8           DeviceLockDepth;  // The depth of the deivce lock

   NORLayoutInfo * LayoutInfo;
#ifndef __MTK_TARGET__
   const char        *FileName;
   void              *flash_device;
   BYTE              *rootMTDcache;
   BYTE              *MTDcache;
   kal_uint32             modify;                    //first time, don't need to write to file
   kal_uint32             last_WinAddr;    // next address calling mapwindow
   kal_uint32             last_region;        //next region calling mapwindow
#endif
} NOR_MTD_DATA;

typedef __fs_packed_prefix struct
{
   kal_uint32 MSCount;
   kal_uint32 *LogPageID;
   WORD *NewEntryID;
   WORD *OldEntryID;
}__fs_packed_postfix MS_TABLE;

typedef __fs_packed_prefix struct {
   WORD LogBlkID;
   WORD TblIDInBlk;
}__fs_packed_postfix LSMGEntry;

//flash driver data for FDM5.0
typedef __fs_packed_prefix struct {
   kal_uint32    TotalFATSectors;
   NOR_MTD_Driver * MTDDriver;
   void *      MTDData;
   int  (* DiscardSectors) (void * DriveData, UINT Sector, UINT Sectors);
   void (*ReclaimBlock) (void* DriveData, kal_bool isBackground);
   kal_uint32    SecondPartitionSectors;
   kal_uint32    HeaderSize[2];  //HeaderSize[0]: data block header size
                                        //HeaderSize[1]: table block header size
   kal_uint32    *InvalidEntryInTblBlk; //valid entry in table block
   kal_uint32    TotalAvail[2];   // TotalAvail[0]: total available pages in data block
                                         //TotalAvail[0]: total available tables in table block
                                         //not include empty block (2 spare block)
   kal_uint32    TotalInvalid[2]; // TotalInvalid[0]: total invalid pages in data block
                                        //TotalInvalid[0]: total invalid tables in table block
   kal_uint32    ReclHighThreshold[2]; //unit ReclHighThreshold[0]: Pages ReclHighThreshold[1]: Tables
   kal_uint32    ReclLowThreshold[2];
   kal_uint32    SystemThreshold[2];
   kal_bool   NeedResumeFlag;
   kal_bool   NeedFRecl;
   LSMGEntry    *LSMG;            // logical sector mapping group table
   WORD      ReclType;
   WORD      *LBM;              //logical block mapping table
   WORD      *AvailInBlk;     //available page in data block, available table in table block
   WORD      *InvalidInBlk;     //valid  page in data block, valid table in table block
   WORD      ActiveBlk[2];    // ActiveBlk[0]: active data block
                                        //ActiveBlk[1]: active table block
   WORD      ReclLogBlkID;  //ReclLogBlkID == INVALID_BLOCK_ID means no block need reclamation
   WORD      ErasingPhyBlk;
   WORD      ReclToPhyBlkID;
   WORD      ReclFromPhyBlkID;
   WORD      PageSizeShift;
   WORD      BlkIDShift;
   WORD      TblSizeShift;
   WORD      TblIDShift;
   WORD      PagesPerBlk;
   WORD      TblsPerBlk;
   WORD      TblBlks;
   WORD      SetTblBlks;
   WORD      DataBlks;
   kal_uint32 MSTABLE_ENTRY_NUM;
   MS_TABLE  MSTable;
   BYTE      *Buffer;
   BYTE      *CopyBuffer;
}__fs_packed_postfix NOR_FTL_DATA;


#ifndef __MTK_TARGET__
#pragma pack()
#endif

typedef struct {
   kal_uint32 Blocks;
   kal_uint32 BlockSize;
   kal_uint32 EraseCountMax;
   kal_uint32 EraseCountMin;
   kal_uint32 EraseCountAverage;
   kal_uint32 SectorsInUse;
   kal_uint32 SectorsDeleted;
   kal_uint32 SectorsAvail;
} NORFlashInfo;

/* Definition for power loss test */
#if defined(FLASH_DISKDRV_DEBUG) && defined(POWERLOSS_TEST)
#include <setjmp.h>
extern jmp_buf mark;
extern int Test_CD_Value;
#ifndef __NOR_FDM5__
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
enum
{
/* 1*/WriteSector_SECTOR_WRITING = 1,
/* 2*/WriteSector_SECTOR_WRITTEN,
/* 3*/WriteSector_SECTOR_DELETED,
/* 4*/WriteSector_SECTOR_VALID,
/* 5*/WriteSector_SECTOR_MS_WRITTEN,
/* 6*/ReclaimBlock_pre_BLOCK_RECLAIMING,
/* 7*/ReclaimBlock_pre_BLOCK_RECLAIMED,
/* 8*/ReclaimBlock_pre_BLOCK_VIRGINE,
/* 9*/ReclaimBlock_post_BLOCK_EMPTY,
/*10*/SetActiveBlock_BLOCK_FULL,
/*11*/SetActiveBlock_BLOCK_ACTIVE,
/*12*/ResumeSectorStates_SECTOR_MS_BEINGVALIDATED,
/*13*/WriteSector_SECTOR_MOVING,
/*14*/WriteSectors_Validate_MS_Sector,
/*15*/WriteSectors_Validate_MS_VALID_Sector,
/*16*/ReclaimEraseQueueItem_BLOCK_VIRGINE,
/*17*/IdleReclaimBlocks_BLOCK_RECLAIMING,
/*18*/IdleReclaimBlocks_BLOCK_RECLAIMING_COPYSECTOR,
/*19*/IdleReclaimBlocks_BLOCK_VIRGINE,
/*20*/IdleReclaimBlocks_RECALIM_ONE_MORE_BLOCK,
/*21*/IdleReclaimBlocks_BLOCK_RECLAIMED
};

#define TEST_POINT(a)\
   {\
      switch(a)\
      {\
         case WriteSector_SECTOR_MS_WRITTEN:\
         case ReclaimBlock_pre_BLOCK_RECLAIMING:\
         case ReclaimBlock_pre_BLOCK_RECLAIMED:\
         case ReclaimBlock_pre_BLOCK_VIRGINE:\
         case ReclaimBlock_post_BLOCK_EMPTY:\
         case SetActiveBlock_BLOCK_FULL:\
         case SetActiveBlock_BLOCK_ACTIVE:\
         case WriteSectors_Validate_MS_Sector:\
            Test_CD_Value -= 50;\
            break;\
         case ResumeSectorStates_SECTOR_MS_BEINGVALIDATED:\
            Test_CD_Value -= 50;\
            break;\
         case IdleReclaimBlocks_BLOCK_RECLAIMING:\
         case IdleReclaimBlocks_BLOCK_RECLAIMING_COPYSECTOR:\
         case IdleReclaimBlocks_BLOCK_VIRGINE:\
         case IdleReclaimBlocks_RECALIM_ONE_MORE_BLOCK:\
         case IdleReclaimBlocks_BLOCK_RECLAIMED:\
            Test_CD_Value -= 50;\
            break;\
         case WriteSectors_Validate_MS_Sector:\
         case WriteSectors_Validate_MS_VALID_Sector:\
            Test_CD_Value -= 50;\
            break;\
         default:\
            Test_CD_Value--;\
            break;\
       }\
      if(Test_CD_Value <= 0)\
         longjmp(mark, a);\
   }
#else /*!__SINGLE_BANK_NOR_FLASH_SUPPORT__*/
enum
{
/* 1*/WriteSector_SECTOR_WRITING = 1,
/* 2*/WriteSector_SECTOR_WRITTEN,
/* 3*/WriteSector_SECTOR_DELETED,
/* 4*/WriteSector_SECTOR_VALID,
/* 5*/WriteSector_SECTOR_MS_WRITTEN,
/* 6*/ReclaimBlock_pre_BLOCK_RECLAIM,
/* 7*/ReclaimBlock_pre_BLOCK_VIRGINE,
/* 8*/ReclaimBlock_post_BLOCK_EMPTY,
/* 9*/SetActiveBlock_BLOCK_FULL,
/*10*/SetActiveBlock_BLOCK_ACTIVE,
/*11*/ResumeSectorStates_SECTOR_MS_BEINGVALIDATED,
/*12*/WriteSector_SECTOR_MOVING,
/*13*/WriteSectors_Validate_MS_Sector
};

#define TEST_POINT(a)\
   {\
      switch(a)\
      {\
         case WriteSector_SECTOR_MS_WRITTEN:\
         case ReclaimBlock_pre_BLOCK_RECLAIM:\
         case ReclaimBlock_pre_BLOCK_VIRGINE:\
         case ReclaimBlock_post_BLOCK_EMPTY:\
         case SetActiveBlock_BLOCK_FULL:\
         case SetActiveBlock_BLOCK_ACTIVE:\
         case WriteSectors_Validate_MS_Sector:\
            Test_CD_Value -= 50;\
            break;\
         case ResumeSectorStates_SECTOR_MS_BEINGVALIDATED:\
            Test_CD_Value -= 50;\
            break;\
         default:\
            Test_CD_Value--;\
            break;\
       }\
      if(Test_CD_Value <= 0)\
         longjmp(mark, a);\
   }
#endif /*__SINGLE_BANK_NOR_FLASH_SUPPORT__*/
#else /*FDM5*/
enum
{
/* 1*/ReclaimBlock_MARK_BLOCK_RECLAIM = 1,
/* 2*/ReclaimBlock_MARK_BLOCK_COPYING,
/* 3*/ReclaimBlock_TABLE_BLOCK_COPYING,
/* 4*/ReclaimBlock_DATA_BLOCK_COPYING,
/* 5*/ReclaimBlock_MARK_BLOCK_ERASING,
/* 6*/ReclaimBlock_AFTER_ERASED,
/* 7*/CopyTable_MARK_COPYING,
/* 8*/CopyTable_MARK_ALLOCATING,
/* 9*/CopyTable_MARK_VALID,
/*10*/WritePage_MARK_TABLE_ENTRY_WRITING,
/*11*/WritePage_MARK_TABLE_ENTRY_WRITTEN,
/*12*/WritePage_MARK_PAGE_VALID,
/*13*/WritePage_MARD_TABLE_ENTRY_MS_WRITING,
/*14*/WritePage_MARD_TABLE_ENTRY_MS_BEGIN_VALID,
/*15*/SetActiveBlock_BLOCK_FULL,
/*16*/SetActiveBlock_BLOCK_ACTIVE
};


#define TEST_POINT(a)\
   {\
      switch(a)\
      {\
         case ReclaimBlock_MARK_BLOCK_RECLAIM:\
         case ReclaimBlock_MARK_BLOCK_COPYING:\
         case ReclaimBlock_TABLE_BLOCK_COPYING:\
         case ReclaimBlock_DATA_BLOCK_COPYING:\
         case ReclaimBlock_MARK_BLOCK_ERASING:\
		 case ReclaimBlock_AFTER_ERASED:\
		 case CopyTable_MARK_COPYING:\
		 case CopyTable_MARK_ALLOCATING:\
		 case CopyTable_MARK_VALID:\
		 case WritePage_MARK_TABLE_ENTRY_WRITING:\
		 case WritePage_MARK_TABLE_ENTRY_WRITTEN:\
		 case WritePage_MARK_PAGE_VALID:\
		 case WritePage_MARD_TABLE_ENTRY_MS_WRITING:\
		 case WritePage_MARD_TABLE_ENTRY_MS_BEGIN_VALID:\
		 case SetActiveBlock_BLOCK_FULL:\
		 case SetActiveBlock_BLOCK_ACTIVE:\
            Test_CD_Value -= 50;\
            break;\
         default:\
            Test_CD_Value--;\
            break;\
       }\
      if(Test_CD_Value <= 0)\
         longjmp(mark, a);\
   }
#endif /*__NOR_FDM5__*/
#define START_POINT  setjmp(mark)
#else
#define TEST_POINT(a)
#define START_POINT
#endif /* FLASH_DISKDRV_DEBUG */


/* Function Prototype */
int NOR_MountDevice(void * DriveData, int DeviceNumber, int DeviceType, kal_uint32 Flags);
int NOR_ShutDown(void * DriveData);
int NOR_ReadSectors(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int NOR_WriteSectors(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int NOR_MediaChanged(void * DriveData);
int NOR_DiscardSectors(void * DriveData, kal_uint32 Sector, UINT Sectors);
int NOR_GetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor);
int NOR_LowLevelFormat(void * DriveData, const char * DeviceName, FS_FormatCallback Progress, kal_uint32 Flags);
int NOR_NonBlockWriteSectors(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int NOR_RecoverableWriteSectors(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int NOR_ResumeSectorStates(void * DriveData);

int SIB_MountDevice(void * DriveData, int DeviceNumber, int DeviceType, kal_uint32 Flags);
int SIB_ReadSectors(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int SIB_WriteSectors(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int SIB_DiscardSectors(void * DriveData, kal_uint32 Sector, UINT Sectors);
int SIB_GetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor);
int SIB_LowLevelFormat(void * DriveData, const char * DeviceName, FS_FormatCallback Progress, kal_uint32 Flags);
int SIB_NonBlockWriteSectors(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int SIB_RecoverableWriteSectors(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int SIB_ResumeSectorStates(void * DriveData);

int nNOR_MountDevice(void * DriveData, int DeviceNumber, int DeviceType, kal_uint32 Flags);
int nNOR_ReadSectors(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int nNOR_WriteSectors(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int nNOR_MediaChanged(void * DriveData);
int nNOR_DiscardSectors(void * DriveData, kal_uint32 Sector, UINT Sectors);
int nNOR_LowLevelFormat(void * DriveData, const char * DeviceName, FS_FormatCallback Progress, kal_uint32 Flags);
int nNOR_NonBlockWriteSectors(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int nNOR_RecoverableWriteSectors(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int nNOR_ResumeSectorStates(void * DriveData);
void nNOR_ReclaimBlock(void* DriveData, kal_bool isBackground);

int nSIB_MountDevice(void * DriveData, int DeviceNumber, int DeviceType, kal_uint32 Flags);
int nSIB_ReadSectors(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int nSIB_WriteSectors(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int nSIB_DiscardSectors(void * DriveData, kal_uint32 Sector, UINT Sectors);
int nGetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor);
int nSIB_LowLevelFormat(void * DriveData, const char * DeviceName, FS_FormatCallback Progress, kal_uint32 Flags);
int nSIB_NonBlockWriteSectors(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int nSIB_RecoverableWriteSectors(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int nSIB_ResumeSectorStates(void * DriveData);
void nSIB_ReclaimBlock(void* DriveData, kal_bool isBackground);
int nShutDown(void * DriveData);

int NOR_MountDevice_ext(void * DriveData, int DeviceNumber, int DeviceType, kal_uint32 Flags);
int NOR_ShutDown_ext(void * DriveData);
int NOR_ReadSectors_ext(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int NOR_WriteSectors_ext(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int NOR_MediaChanged_ext(void * DriveData);
int NOR_DiscardSectors_ext(void * DriveData, kal_uint32 Sector, UINT Sectors);
int NOR_GetDiskGeometry_ext(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor);
int NOR_LowLevelFormat_ext(void * DriveData, const char * DeviceName, FS_FormatCallback Progress, kal_uint32 Flags);
int NOR_NonBlockWriteSectors_ext(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int NOR_RecoverableWriteSectors_ext(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer);
int NOR_ResumeSectorStates_ext(void * DriveData);

int OTPAccess(void * DriveData, int accesstype, UINT Offset, void * BufferPtr, UINT Length);
int OTPQueryLength(void * DriveData, UINT *Length);


// internal function for different version of FDM

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
extern void ESB_CompleteErase(NOR_FLASH_DRV_Data * D);
#else //!__SINGLE_BANK_NOR_FLASH_SUPPORT__
extern void MB_CompleteErase(NOR_FLASH_DRV_Data * D);
#endif //__SINGLE_BANK_NOR_FLASH_SUPPORT__


#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) || defined(__NOR_IDLE_SWEEP__)
   extern void GetFDMLock(void);
   extern void FreeFDMLock(void);
   #define retriveFDMLock GetFDMLock
   #define releaseFDMLock FreeFDMLock
#else // !__SINGLE_BANK_NOR_FLASH_SUPPORT__ && !__NOR_IDLE_SWEEP__
   extern void FDM_LOCK(void);
   extern void FDM_UNLOCK(void);
   #define retriveFDMLock FDM_LOCK
   #define releaseFDMLock FDM_UNLOCK  

#endif // __SINGLE_BANK_NOR_FLASH_SUPPORT__ || __NOR_IDLE_SWEEP__


#if defined(__NOR_IDLE_SWEEP__)
extern void setIdleSweepThreshold(NOR_FLASH_DRV_Data * D, kal_uint32 MaxSectorsPerBlock); //flash_mtd.c
#endif



#if ( defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
kal_uint32 SIB_LocateSector(NOR_FLASH_DRV_Data * D, kal_uint32 LogicalSector);
//kal_uint32 LocateSector(NOR_FLASH_DRV_Data * D, kal_uint32 LogicalSector);
#endif


#if (defined __UBL__) || (defined __FUE__)
   #define NORFDM_EXT_ASSERT(expr, e1, e2, e3) EXT_ASSERT(expr, e1, e2, e3)
   #define NORFDM_ASSERT(expr) ASSERT(expr)
#else
   extern kal_uint32 NOR_FDM_Get_current_PC(void);
   #define NORFDM_EXT_ASSERT(expr, e1, e2, e3) {if(!(expr)) {kal_fatal_error_handler(KAL_ERROR_FILESYS_NOR_FDM_INTERNAL_FAILED,  NOR_FDM_Get_current_PC());}}
   #if defined(DEBUG_KAL)
      #define NORFDM_ASSERT(x) {if(!(x)) {kal_fatal_error_handler(KAL_ERROR_FILESYS_NOR_FDM_INTERNAL_FAILED, NOR_FDM_Get_current_PC());}}
   #else
      #define NORFDM_ASSERT(x)
   #endif
#endif // __UBL__ || __FUE__


#if defined(__MTK_TARGET__)
#if defined(__UBL__) || defined(__FUE__)
#define __nor_section_RAM             __attribute__ ((section ("INTERNCODE")))
#define __nor_section_SECOND_PART     __attribute__ ((section ("SECOND_PART")))
#define __nor_section_EMIINITCODE     __attribute__ ((section ("EMIINITCODE")))    
#elif defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
#define __nor_section_RAM             __attribute__ ((section ("SNORCODE")))
#define __nor_section_SECOND_PART     __attribute__ ((section ("SECOND_PART")))
#define __nor_section_EMIINITCODE     __attribute__ ((section ("EMIINITCODE")))    
#else // __MTK_TARGET__ && !(__UBL__ ||__FUE__) && !__SINGLE_BANK_NOR_FLASH_SUPPORT__
#define __nor_section_RAM
#define __nor_section_SECOND_PART
#define __nor_section_EMIINITCODE
#endif
#else //!__MTK_TARGET__
/* Reserve for  MoDIS */
#define __nor_section_RAM
#define __nor_section_SECOND_PART
#define __nor_section_EMIINITCODE
#endif //__MTK_TARGET__


#endif   /* !DRVFLASH_H */
