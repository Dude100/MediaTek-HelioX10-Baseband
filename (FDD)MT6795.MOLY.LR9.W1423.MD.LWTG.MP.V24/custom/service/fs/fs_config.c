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
 *   fs_config.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines all resource setting in file system
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__MTK_TARGET__) || defined(__FS_MODIS_FDM__)
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "flash_opt.h"
#include "fs_internal_def.h"
#include "fs_gprot.h"
#include "fs_iprot.h"

   /* IMPORT DEVICE DRIVER and DRIVER DATA */
#include "DrvFlash.h"
extern NOR_FLASH_DRV_Data  FlashDriveData;
extern FS_Driver NORFlashDriver;
extern FS_Driver            RAMDiskDriver;
extern kal_uint32           RAMDiskDriveData;

#ifdef NAND_SUPPORT
#include "NAND_FDM.h"
#if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
extern NAND_FLASH_DRV_DATA  NANDFlashDriveData[NAND_DISK_NUM];
#else   // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
extern NAND_FLASH_DRV_DATA  NANDFlashDriveData;
#endif  // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
extern FS_Driver NANDFlashDriver;
#endif

#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))
#include "msdc_def.h"
extern FS_Driver FS_MsDrv;
extern FS_Driver FS_SdDrv;
extern FS_Driver FS_MspDrvAll;
extern FS_Driver FS_SdDrv2;
#endif

#ifdef __OTG_ENABLE__
#include "usb_host_ms_adap.h"
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "kal_public_api.h"
#include "usb_host_ms_if.h"
extern kal_uint8 USBHost_Media_Handle[];
extern FS_Driver FS_OTGDrv;
#endif

#ifndef __MTK_TARGET__
#include "w32_file_disk.h"

extern FS_Driver FileDiskNorDriver;
extern FS_Driver FileDiskNandDriver;
extern FS_Driver FileDiskNandDriver1;
extern FS_Driver FileDiskCardDriver;
extern FILE_DISK_INFO_T file_disk_info[];
#endif

/************************ User Configuration ************************/
/* The nubmer of drive in file system: EXTRA_DRIVE_NUM + X;
 * X : partitions on (NOR/NAND) flash. 1 <= X <= 4
 *     3 in general (system drive + user drive on NOR + user drive on NAND)
 *     modify X to best-fit your case
 * EXTRA_DRIVE_NUM : number of external device other than flash device
 *                   auto calculated, don't remove
 */

/*--------------
 * Drives
 *--------------*/

//-- Default drive numbers
#if defined(MT6516)
    #define DEFAULT_DRIVE_NUM   (3)
#elif defined(__PUBLIC_DRIVE_AVAILABLE__)   // defined in flash_opt.h
    #if defined(__PUBLIC_DRIVE_2_AVAILABLE__)
        #define DEFAULT_DRIVE_NUM   (3)
    #else
        #define DEFAULT_DRIVE_NUM   (2)
    #endif
#else
    #define DEFAULT_DRIVE_NUM   (3)         // should not be here
#endif

//-- Extra drive numbers
#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))
    #define MSDC1_DRIVE_NUM (1)
#else
    #define MSDC1_DRIVE_NUM (0)
#endif

#ifdef __SIM_PLUS__
    #define SIMPLUS_DRIVE_NUM (1)
#else
    #define SIMPLUS_DRIVE_NUM (0)
#endif

#ifdef __MSDC2_SD_MMC__
    #define MSDC2_DRIVE_NUM (1)
#else
    #define MSDC2_DRIVE_NUM (0)
#endif

#ifdef __FS_CARD2_SUPPORT__ // Dual T-card support
    #define MSDC3_DRIVE_NUM (1)
#else
    #define MSDC3_DRIVE_NUM (0)
#endif

#ifdef __OTG_ENABLE__   // NOTE: The number of supported OTG devices is not configurable
    #define OTG_DRIVE_NUM  (USB_HOST_MS_SUPPORT_LUN)
#else
    #define OTG_DRIVE_NUM  (0)
#endif

#define EXTRA_DRIVE_NUM (MSDC1_DRIVE_NUM + SIMPLUS_DRIVE_NUM + MSDC2_DRIVE_NUM + MSDC3_DRIVE_NUM + OTG_DRIVE_NUM)

#ifdef __FS_CARD_DOWNLOAD__
    #define MAX_DRIVES 1
#elif defined(__NANDFDM_MULTI_INSTANCE__)
    #define MAX_DRIVES (EXTRA_DRIVE_NUM + NAND_DISK_NUM + DEFAULT_DRIVE_NUM)    // NAND_DISK_NUM is defined in flash_opt.h
#else // !defined(__NANDFDM_MULTI_INSTANCE__)
    #define MAX_DRIVES (EXTRA_DRIVE_NUM + DEFAULT_DRIVE_NUM)
#endif // defined(__NANDFDM_MULTI_INSTANCE__)

const UINT FS_MAX_DRIVES = MAX_DRIVES;

/*--------------
 * Buffers
 *--------------*/

/* The number of buffer in file system:  X >= 1 */

#if defined(__FS_CARD_DOWNLOAD__)
    #define MAX_BUFFERS  (2)
#elif defined(__PS_SERVICE__)           // GPRS capability
    #define MAX_BUFFERS  (16)
#elif !defined(LOW_COST_SUPPORT)
    #define MAX_BUFFERS   (8)           // GSM capability
#else
    #define MAX_BUFFERS   (4)           // GSM capability + low-cost
#endif

const UINT FS_MAX_BUFFERS = MAX_BUFFERS;

/*--------------
 * File handles
 *--------------*/

/* The number of file handle in file system: EXTRA_FH_NUM + X;
 * EXTRA_FH_NUM: number of file handle for downloadable application, don't remove
 * X >=  4 #if GSM
 * X >= 16 #if GPRS
 * Recommend Value For General Case: 24  # modify this value to best fit your case
 *
 *      24 =  9 (foreground app.) + 12 (basic background app. worst case) + 3 (optional)
 *
 * Table of Background File Handle Usage by optional application/feature
 * { 4,  BlueTooth FTP + OPP profile },
 * { 1,  IRDA Support                },
 * { 1,  DT Support (Phone Suite)    },
 * { 2,  IMPS                        },
 * { 1,  EMail                       },
 * { 1,  POC                         },
 * { 1,  SIP                         },
 */

//-- Default file handles
#if defined(__PS_SERVICE__)           // GPRS capability
    #define DEFAULT_FH_NUM  (24)
#elif !defined(LOW_COST_SUPPORT)        // GSM capability
    #define DEFAULT_FH_NUM  (16)
#else                                   // GSM capability + low-cost
    #define DEFAULT_FH_NUM  (8)
#endif

#ifdef __FS_CARD_DOWNLOAD__ // Bootloader w/ TinyFS
    #define MAX_FILES  1
#else
    #define MAX_FILES  DEFAULT_FH_NUM
#endif

UINT FS_MAX_FILES = MAX_FILES;

/*--------------
 * Threads
 *--------------*/

/* The number of tasks that will use file system: X >=  5 #if GSM
 *                                                X >= 10 #if GPRS
 * Default Value: 23 (GPRS), 35 (EDGE)
 * Common {NVRAM, MMI, MED, FMT, WAP, WPS, L4, L1AUDIO}
 * Discount 1 per feature OFF to optimize
 * {BLUETOOTH, DT, EMAIL, GDC, GDD, IMPS, JVM, JAM, POC, SIP}
 * {XDM, VOIP, DHCP, TFTP, SAF, SUPC, RTSP, DM, DRMT, CERTMAN}
 * {TLS, SYNCML, VRT, MMS, IVD, TR, USB, GADGET}
 */

//-- Default thread numbers
#if defined(__FS_CARD_DOWNLOAD__)
    #define MAX_THREAD  (1)
#elif defined(__EGPRS_MODE__)           // EDGE capability
    #define MAX_THREAD  (35)
#elif defined(__PS_SERVICE__)           // GPRS capability
    #define MAX_THREAD  (23)
#elif !defined(LOW_COST_SUPPORT)        // GSM capability
    #define MAX_THREAD  (14)
#else                                   // GSM capability + low-cost
    #define MAX_THREAD  (9)
#endif

const UINT FS_MAX_THREAD = MAX_THREAD;


/* The max number of continuous cluster for copy iteration
 *
 * Default value: 128 , 32 (MT6223P)
 */
#if defined(MT6223P)
const UINT FS_MAX_COPY_CLUSTER =  32;
#else /* MT6223P */
const UINT FS_MAX_COPY_CLUSTER = 128;
#endif /* MT6223P */

#if defined(__FS_SORT_SUPPORT__)
const UINT FS_SORTING_MAX_ENTRY = FS_SORT_MAX_ENTRY;
#endif /* FS_SORT_SUPPORT */

#if (defined __FS_SYSDRV_ON_NAND__) && !(defined _NAND_FLASH_BOOTING_)
        /* Treat __FS_SYSDRV_ON_NAND__ equal _NAND_FLASH_BOOTING_ */
#define _NAND_FLASH_BOOTING_
#endif

// FS internal open hint management - Resource configuration
#ifdef __FS_OPEN_HINT__
#if !defined(LOW_COST_SUPPORT)
#define MAX_OPEN_HINT_PATH 8
#define MAX_OPEN_HINT_LOCATION_PER_HINT 2
#else
#define MAX_OPEN_HINT_PATH 4
#define MAX_OPEN_HINT_LOCATION_PER_HINT 2
#endif
const UINT FS_MAX_OPEN_HINT_PATH               =  MAX_OPEN_HINT_PATH;
const UINT FS_MAX_OPEN_HINT_LOCATION_PER_HINT  =  MAX_OPEN_HINT_LOCATION_PER_HINT;
#endif /* __FS_OPEN_HINT__ */

#ifdef __FS_DEDICATED_BUFFER__
#define DEDICATED_BUFFER_SIZE (16 FS_KB)
const UINT FS_DEDICATED_BUFFER_SIZE = DEDICATED_BUFFER_SIZE;
#endif /* __FS_DEDICATED_BUFFER__ */

#ifdef _NAND_FLASH_BOOTING_
/* The size of sanity check buffer in byte */
/* It's for system drive on NAND flash booting type project */
/* If the size is not big enough, it will assert when booting up */
#define MAX_CHECK_BUFFER (5*1024)
#else
#define MAX_CHECK_BUFFER 4
#endif
const UINT FS_MAX_CHECK_BUFFER = MAX_CHECK_BUFFER;

#define DEV_DATA_ZERO  { NULL, NULL, 0, 0, 0, 0, 0, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0, 0, NULL, NULL, 0, 0, {0, 0, 0, 0, 0, 0}, 0, 0}

/* Device List Configuration */
FS_Device gFS_DeviceList[] = {
#ifdef __MTK_TARGET__
#ifndef __FS_CARD_DOWNLOAD__

#if defined(__RAMDISK__)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_RAM | FS_DEVICE_NOR_FLASH, &RAMDiskDriver, (void *)&RAMDiskDriveData, DEV_DATA_ZERO},
#else // !__RAMDISK__

#if defined(__EMMC_BOOTING__)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_EMMC
                           | FS_DEVICE_AUTO_FORMAT, &FS_SdDrv, (void *)&MSDC_Blk[0], NULL},
#elif !defined(_NAND_FLASH_BOOTING_)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NOR_FLASH, &NORFlashDriver, (void *)&FlashDriveData, DEV_DATA_ZERO},
#endif

#if defined(NAND_SUPPORT) && !defined(__EMMC_BOOTING__) // to avoid eMMC RST interference issue for MT6256
        #if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&(NANDFlashDriveData[0]), DEV_DATA_ZERO},
        #if (NAND_DISK_NUM > 1)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&(NANDFlashDriveData[1]), DEV_DATA_ZERO},
        #endif /* NAND_DISK_NUM > 1 */
        #if (NAND_DISK_NUM > 2)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&(NANDFlashDriveData[2]), DEV_DATA_ZERO},
        #endif /* NAND_DISK_NUM > 2 */
        #if (NAND_DISK_NUM > 3)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&(NANDFlashDriveData[3]), DEV_DATA_ZERO},
        #endif /* NAND_DISK_NUM > 3 */
        #if (NAND_DISK_NUM > 4)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&(NANDFlashDriveData[4]), DEV_DATA_ZERO},
        #endif /* NAND_DISK_NUM > 4 */
        #if (NAND_DISK_NUM > 5)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&(NANDFlashDriveData[5]), DEV_DATA_ZERO},
        #endif /* NAND_DISK_NUM > 5 */
        #if (NAND_DISK_NUM > 6)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&(NANDFlashDriveData[6]), DEV_DATA_ZERO},
        #endif /* NAND_DISK_NUM > 6 */
        #if (NAND_DISK_NUM > 7)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&(NANDFlashDriveData[7]), DEV_DATA_ZERO},
        #endif /* NAND_DISK_NUM > 7 */
        #else // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
        {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &NANDFlashDriver, (void *)&NANDFlashDriveData, DEV_DATA_ZERO},
        #endif // ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
#endif
#endif /* __RAMDISK__ */
#endif /* __FS_CARD_DOWNLOAD__ */

#ifdef __MSDC_MS__
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_MsDrv, (void *)&gMSDC_Handle, DEV_DATA_ZERO},
#elif (defined __MSDC_SD_MMC__)
        #if defined(__SIM_PLUS__)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_SdDrv, (void *)&MSDC_Blk[SD_EXT], DEV_DATA_ZERO},
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_SIMPLUS  , &FS_SdDrv, (void *)&MSDC_Blk[SD_SIM], DEV_DATA_ZERO},
        #elif defined(__MSDC2_SD_MMC__)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_SdDrv , (void *)&MSDC_Blk[0], DEV_DATA_ZERO},
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_SdDrv2, (void *)&MSDC_Blk[1], DEV_DATA_ZERO},

        #elif __FS_CARD2_SUPPORT__ // Dual T-Card Support
            #if !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
                {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE , &FS_SdDrv, (void *)&MSDC_Blk[1], DEV_DATA_ZERO},
                {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE , &FS_SdDrv, (void *)&MSDC_Blk[0], DEV_DATA_ZERO},
	        #else
                {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_SdDrv, (void *)&MSDC_Blk[0], DEV_DATA_ZERO},
                {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_SdDrv, (void *)&MSDC_Blk[1], DEV_DATA_ZERO},
		    #endif
        #else
        		{FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FS_SdDrv, (void *)&MSDC_Blk[0], DEV_DATA_ZERO},
        #endif

#elif (defined __MSDC_MSPRO__)
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_CHECK_PART
                           | FS_DEVICE_MEMORY_STICK, &FS_MspDrvAll, (void *)&gMSDC_Handle, DEV_DATA_ZERO},
#endif

#ifndef __FS_CARD_DOWNLOAD__
#ifdef __OTG_ENABLE__
  /* The number of supported OTG devices is not configurable */
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[0], DEV_DATA_ZERO},
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[1], DEV_DATA_ZERO},
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[2], DEV_DATA_ZERO},
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[3], DEV_DATA_ZERO},
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[4], DEV_DATA_ZERO},
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[5], DEV_DATA_ZERO},
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[6], DEV_DATA_ZERO},
        {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE
                           | FS_DEVICE_EXTERNAL  , &FS_OTGDrv, (void *) &USBHost_Media_Handle[7], DEV_DATA_ZERO},
#endif
#endif /* !__FS_CARD_DOWNLOAD__ */

#else   /* Modis */
    #ifndef _NAND_FLASH_BOOTING_
	   {FS_DEVICE_FDISK, 0, FS_DEVICE_NOR_FLASH, &FileDiskNorDriver, (void *)&file_disk_info[NOR_DISK], DEV_DATA_ZERO},
    #endif

    #ifdef NAND_SUPPORT
	   {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &FileDiskNandDriver, (void *)&file_disk_info[NAND_DISK], DEV_DATA_ZERO},
    #if ( defined(__NANDFDM_MULTI_INSTANCE__) && defined(__NAND_FDM_50__) )
    #if (NAND_DISK_NUM > 1)
	   {FS_DEVICE_FDISK, 0, FS_DEVICE_NAND_FLASH, &FileDiskNandDriver1, (void *)&file_disk_info[NAND_DISK1], DEV_DATA_ZERO},
    #endif
    #endif
    #endif

    #if (defined __MSDC_MS__) || (defined __MSDC_SD_MMC__) || (defined __MSDC_MSPRO__)
	   {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FileDiskCardDriver, (void *)&file_disk_info[CARD_DISK], DEV_DATA_ZERO},
       #ifdef __FS_CARD2_SUPPORT__ // Dual T-Card Support
       {FS_DEVICE_FDISK, 0, FS_DEVICE_REMOVABLE, &FileDiskCardDriver, (void *)&file_disk_info[CARD_DISK1], DEV_DATA_ZERO},
       #endif
    #endif
#endif
   { 0, 0, 0, NULL, NULL, DEV_DATA_ZERO }    // end of list marker
};

/************* Do not modify anything behind this line *************/
FS_Drive           gFS_DriveTable[MAX_DRIVES];
fs_file_tbl_struct gFS_FileTable[MAX_FILES];
FS_Buffer          gFS_BufferTable[MAX_BUFFERS];

#if !defined(__MTK_TARGET__) || defined(GEN_FOR_PC) || defined(__RESOURCE_GEN_) || defined(NVRAM_AUTO_GEN)
    #define __fs_cache_align(x)
#elif defined(__ARMCC_VERSION)
    #define __fs_cache_align(x)   __align(x)
#elif defined(__GNUC__)
    #if   defined(__UBL__)
    #define __fs_cache_align(x)   __attribute__ ((aligned(x), zero_init, section ("EXT_BOOTLOADER_ZI")))
    #elif defined(__DYNAMIC_SWITCH_CACHEABILITY_)
    #define __fs_cache_align(x)   __attribute__ ((aligned(x), zero_init, section ("NONCACHEDZI")))
    #else
    #define __fs_cache_align(x)   __attribute__ ((aligned(x)))
    #endif
#endif

#if !defined(__GNUC__)
#ifdef __DYNAMIC_SWITCH_CACHEABILITY__
#pragma arm section zidata = "NONCACHEDZI"
#endif // __DYNAMIC_SWITCH_CACHEABILITY__

#ifdef __UBL__
#pragma arm section zidata = "EXT_BOOTLOADER_ZI"
#endif // __UBL__
#endif // __GNUC__

__fs_cache_align(32) BYTE              gFS_BufferData[MAX_BUFFERS * FS_BUFFER_SIZE];

#ifdef __FS_DEDICATED_BUFFER__
UINT              gFS_DedicatedBufferPool[DEDICATED_BUFFER_SIZE / sizeof(UINT)];
#endif /* __FS_DEDICATED_BUFFER__ */

#if !defined(__GNUC__)
#ifdef __DYNAMIC_SWITCH_CACHEABILITY__
#pragma arm section zidata
#endif // __DYNAMIC_SWITCH_CACHEABILITY__
#endif // __GNUC__

kal_taskid        gFS_TaskList[MAX_THREAD];
FS_ExceptionData* gFS_TaskData[MAX_THREAD][MAX_TLS_INDEX];

#if defined(__FS_ASYNC_SUPPORT_ALONE__)
fs_tls_struct   _gfs_tls[MAX_THREAD];    // TLS (Now for FS async I/F alone version ONLY!)
#endif

#ifndef __FS_CARD_DOWNLOAD__
__fs_cache_align(4) BYTE              gFS_SanityCheckBuffer[MAX_CHECK_BUFFER];
#endif

#if defined(__NANDFDM_MULTI_INSTANCE__)
const int         gFS_DeviceNumOfSYSDRV = NAND_DISK_NUM;
#else  // defined(__NANDFDM_MULTI_INSTANCE__)
const int         gFS_DeviceNumOfSYSDRV = 1;
#endif // defined(__NANDFDM_MULTI_INSTANCE__)

#ifdef __FS_OPEN_HINT__
FS_OpenHintPath     gFS_OpenHintPath[MAX_OPEN_HINT_PATH];
FS_OpenHintInt      gFS_OpenHint[MAX_THREAD];
__fs_cache_align(4) BYTE                gFS_OpenHintLocationData[MAX_OPEN_HINT_PATH * MAX_OPEN_HINT_LOCATION_PER_HINT * sizeof(FS_OpenHintLocation)];
#endif /* __FS_OPEN_HINT__ */

#ifdef __FS_DEDICATED_BUFFER__
const UINT        FS_BUFF_SIZE_COUNT_FREE_CLUSTER = DEDICATED_BUFFER_SIZE;
const UINT        FS_BUFF_SIZE_MOVE               = DEDICATED_BUFFER_SIZE;
#endif /* __FS_DEDICATED_BUFFER__ */

FS_Tables gFS_Data  =
{
   gFS_DriveTable,
   gFS_FileTable,
   gFS_BufferTable,
   gFS_BufferData
};

#if defined(__EMMC_BOOTING__)
const kal_uint32    _gfs_system_drive_size = EMMC_FS_SYSTEM_DRIVE_SIZE; // system drive size, unit is #Sector (get from flash_opt.h)
#endif // __EMMC_BOOTING__

#endif /* __MTK_TARGET__ || __FS_MODIS_FDM__ */
