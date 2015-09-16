/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *   ckSysDrv_flash_cfg_preproc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   To calculate System Drive Disk Space accuratly in build time utilities ckSysDrv.pl ,
 *   flash configuration parameters is required by C pre-processor with this temporal C source code.
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
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
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *============================================================================
 ****************************************************************************/

#include "flash_opt.h"
#include "custom_flash.c"  // for including flash configurations, e.g., RegionInfo...
#include "custom_nvram_int_config.h"

/*--------------------------------------------------
 * ckSysDrv Switch On/Off
 *--------------------------------------------------*/

#if defined(__CCCIFS_SUPPORT__) || defined(__RAMDISK__)
    int cksysdrv_enabled = 0;   // ckSysDrv is disabled on Smart Phone project
#else
    int cksysdrv_enabled = 1;
#endif

/*--------------------------------------------------
 * Auto adjust On/Off
 *--------------------------------------------------*/
#if defined(__FS_AUTO_CONFIG_SUPPORT__)
   int fs_auto_config_support = 1;
#else
   int fs_auto_config_support = 0;
#endif /* __FS_AUTO_CONFIG_SUPPORT__ */

/*--------------------------------------------------
 * Get system drive information by compile options
 *--------------------------------------------------*/

#if defined(APP_STORAGE_IN_SYS_DRV)
        int app_storage_in_sys_drv = 1;
#else
        int app_storage_in_sys_drv = 0;
#endif
    

#if defined(__EMMC_BOOTING__)

int system_drive_size      = EMMC_FS_SYSTEM_DRIVE_SIZE;
int system_drive_location  = 3;  // EMMC

int allocated_fat_space    = EMMC_FS_SIZE / 512;
int partition_sectors      = 0;
int flash_base_address     = EMMC_FS_BASE_ADDRESS / 512;

#elif defined(_NAND_FLASH_BOOTING_) || defined(__FS_SYSDRV_ON_NAND__)  // system drive on NAND

int allocated_fat_space    = NAND_ALLOCATED_FAT_SPACE;
int partition_sectors      = NAND_PARTITION_SECTORS;
int flash_base_address     = NAND_FLASH_BASE_ADDRESS;
int system_drive_location  = 1;  // NAND

#else /* !_NAND_FLASH_BOOTING_ && !__FS_SYSDRV_ON_NAND__ */          // system drive on NOR

int allocated_fat_space    = NOR_ALLOCATED_FAT_SPACE;
int partition_sectors      = NOR_PARTITION_SECTORS;
int flash_base_address     = NOR_FLASH_BASE_ADDRESS;
int system_drive_location  = 2;  // NOR

#endif /* _NAND_FLASH_BOOTING_ || __FS_SYSDRV_ON_NAND__ */

/*----------------------------------------------------------
 * File system format information for FlashTool Auto Format
 *----------------------------------------------------------*/

#if defined(__EMMC_BOOTING__)

    int fs_nand_base_address   = 0;
    int fs_nand_length         = 0;
    int fs_nor_base_address    = 0;
    int fs_nor_length          = 0;
    int fs_emmc_base_address   = EMMC_FS_BASE_ADDRESS / 512;
    
    #if (EMMC_FS_SIZE == 0)
        int fs_emmc_length         = 0xFFFFFFFF;
    #else
        int fs_emmc_length         = EMMC_FS_SIZE / 512;
    #endif

#else   // !__EMMC_BOOTING__

    #if defined(_NAND_FLASH_BOOTING_) || defined(__FS_SYSDRV_ON_NAND__) || (defined(__FOTA_DM__) && defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT))

        int fs_nand_base_address   = NAND_FLASH_BASE_ADDRESS;
        int fs_nand_length         = NAND_ALLOCATED_FAT_SPACE;

    #endif /* _NAND_FLASH_BOOTING_ || __FS_SYSDRV_ON_NAND__ && (__FOTA_DM__ && __UP_PKG_ON_NAND__ && NAND_SUPPORT) */

    #if !defined(_NAND_FLASH_BOOTING_) && !defined(__FS_SYSDRV_ON_NAND__)

        int fs_nor_base_address    = NOR_FLASH_BASE_ADDRESS;

        /*
         * If __NOR_SUPPORT_RAW_DISK__ is defined, there are at most 2 additional disks behind system and user drives.
         * We must ensure that these additional disks could be auto-formatted by FlashTool.
         */

        #ifndef __NOR_SUPPORT_RAW_DISK__
        int fs_nor_length          = NOR_ALLOCATED_FAT_SPACE;
        #else // __NOR_SUPPORT_RAW_DISK__

        #if (2 == NOR_BOOTING_NOR_DISK_NUM)
        int fs_nor_length          = NOR_BOOTING_NOR_DISK1_BASE_ADDRESS + NOR_BOOTING_NOR_DISK1_SIZE - NOR_FLASH_BASE_ADDRESS;
        #elif (1 == NOR_BOOTING_NOR_DISK_NUM)
        int fs_nor_length          = NOR_BOOTING_NOR_DISK0_BASE_ADDRESS + NOR_BOOTING_NOR_DISK0_SIZE - NOR_FLASH_BASE_ADDRESS;
        #else
        int fs_nor_length          = NOR_ALLOCATED_FAT_SPACE;
        #endif
        #endif // !__NOR_SUPPORT_RAW_DISK__

    #endif /* !_NAND_FLASH_BOOTING_ && !__FS_SYSDRV_ON_NAND__ */

#endif // __EMMC_BOOTING__


/*--------------------------------------------------
 * File system information
 *--------------------------------------------------*/

#if !defined(__LOW_COST_SUPPORT_ULC__)
   int fs_low_cost_support = 0;
#else
   int fs_low_cost_support = 1;
#endif /* __LOW_COST_SUPPORT_ULC__ */

/*--------------------------------------------------
 * Flash geometry
 *--------------------------------------------------*/

#if defined(NAND_TOTAL_SIZE) && defined(NAND_BLOCK_SIZE)
   int nand_total_size = NAND_TOTAL_SIZE;    // (MB)
   int nand_block_size = NAND_BLOCK_SIZE;    // (KB)
#else
   int nand_total_size = 0;
   int nand_block_size = 0;
#endif

/*--------------------------------------------------
 * NAND FDM information
 *--------------------------------------------------*/

#if defined(__NAND_FDM_50__)
   int nand_fdm_version = 5;
#else
   int nand_fdm_version = 4;
#endif

/*--------------------------------------------------
 * NOR FDM information
 *--------------------------------------------------*/

// NRVAM max number of record sectors
int nvram_custom_cfg_max_record_sector_num = NVRAM_CUSTOM_CFG_MAX_RECORD_SECTOR_NUM;

// reserved blocks in NOR FDM
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   int nor_reserved_blocks = SNOR_ERASE_QUEUE_SIZE;
   int nor_single_bank_support = 1;
#else  /* multi-bank */
   float nor_reserved_blocks = NOR_SYSTEM_DRIVE_RESERVED_BLOCK;
   int nor_single_bank_support = 0;
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

// FDM sector size
#if defined(__INTEL_SIBLEY__)
   int nor_sector_size = 1024;
#else
   int nor_sector_size = 512;
#endif /* __INTEL_SIBLEY__ */

