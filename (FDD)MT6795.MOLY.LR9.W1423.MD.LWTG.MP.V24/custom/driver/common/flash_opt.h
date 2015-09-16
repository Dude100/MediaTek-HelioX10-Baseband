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
 *   flash_opt.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   NOR flash related options
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
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "custom_MemoryDevice.h"
#include "custom_FeatureConfig.h"
#include "flash_opt_gen.h"
#if defined(__SECURE_DATA_STORAGE__)
#include "custom_secure_config.h"
#endif

/*
 *******************************************************************************
 PART 1:
   FLASH CONFIG Options Definition here
 *******************************************************************************
*/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
    #ifdef NOR_FLASH_TYPE_RENESAS_SERIES
        #error "custom\system\{project}\custom_MemoryDevice.h: Error! Enhanced single bank(ESB) does not support Renesas series flash! Please change device!"
    #endif
#endif

/*
 * RAM Disk is enabled and replaces any other flash-type (e.g., NOR or NAND) disk on smartphone moden-only load
 * NOTE. __SMART_PHONE_PLATFORM__ should be defined before (e.g., defined in flash_opt_gen.h)
 */
#if !(defined(__FUE__) || defined(__UBL__) || defined(__EXT_BOOTLOADER__))  // RAM Disk module is not necessary in Bootloader and FUE environment
    #if defined(__FS_RAMDISK__)
        #if !defined(__SMART_PHONE_PLATFORM__)
            #error "RAM Disk is allowed in SP modem-only project only! Please make sure __SMART_PHONE_PLATFORM__ is defined before!"
        #endif
        #define __RAMDISK__
    #endif
#endif

/*
 *******************************************************************************
 PART 2:
   FLASH FDM FEATURE CONFIG PARAMETERS translated from Manual custom_Memorydevice.h
 *******************************************************************************
*/
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

        /* NOTE:
           BUFFER_PROGRAM_ITERATION_LENGTH specifies the maximum interrupt 
           disabled period while buffer program operation is applied
        */

        /* NOTE:
           ERASE_QUEUE_SIZE specifies the number of reserved blocks, 
           to trade off between write throughput and available FAT space
        */
        #ifndef NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE
                #define SNOR_ERASE_QUEUE_SIZE   (5)
        #else  /* NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE */
                #define SNOR_ERASE_QUEUE_SIZE   (NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE)
        #endif /* NOR_FDM4_ESB_PARAMETER_ERASE_QUEUE_SIZE */

#else  /* !__SINGLE_BANK_NOR_FLASH_SUPPORT__ */
        #ifndef NOR_PARAMETER_SYSTEM_DRIVE_RESERVED_BLOCK
                #define NOR_SYSTEM_DRIVE_RESERVED_BLOCK   (3)
        #else
                #define NOR_SYSTEM_DRIVE_RESERVED_BLOCK   (NOR_PARAMETER_SYSTEM_DRIVE_RESERVED_BLOCK)
        #endif

#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */


/*
 *******************************************************************************
 PART 3:
   FLASH GEOMETRY translated from MEMORY DEVICE DATABASE
 *******************************************************************************
*/


/*
 *******************************************************************************
 PART 4:
   FLASH FAT CONFIG translated from Manual custom_Memorydevice.h
 *******************************************************************************
*/
#if defined(__NANDFDM_MULTI_INSTANCE__)
#define NAND_DISK_NUM (NAND_BOOTING_NAND_FS_DISK_NUMBER)
#else // defined(__NANDFDM_MULTI_INSTANCE__)
#define NAND_DISK_NUM (0)
#endif // defined(__NANDFDM_MULTI_INSTANCE__)
#if defined(__RAMDISK__)
    #include "ramdisk_gprot.h"
    #ifndef RAM_FS_SIZE
        #error "Error! Please assign RAM_FS_SIZE in ramdisk_gprot.h for RAM Disk!"
    #else
        #define RAM_FS_SIZE_INT (RAM_FS_SIZE)
    #endif
    #ifdef RAM_FS_FIRST_DRIVE_SECTORS
        #define RAM_FS_FIRST_DRIVE_SECTORS_INT (RAM_FS_FIRST_DRIVE_SECTORS)
    #else
        #define RAM_FS_FIRST_DRIVE_SECTORS_INT (0)
    #endif
#endif // defined(__NANDFDM_MULTI_INSTANCE__)

#if defined(__EMMC_BOOTING__)

    #ifndef EMMC_BOOTING_GP1_PARTITION_SIZE
        #error "custom\system\{project}\custom_MemoryDevice.h: Error! Please Manually Assign EMMC_BOOTING_GP1_PARTITION_SIZE in custom_Memorydevice.h for EMMC Booting!"
    #else
        #define EMMC_CODE_PARTITION_SIZE   (EMMC_BOOTING_GP1_PARTITION_SIZE)
    #endif   /* !EMMC_BOOTING_GP1_PARTITION_SIZE */

    #ifndef EMMC_BOOTING_UP_FS_BASE_ADDRESS
        #error "custom\system\{project}\custom_MemoryDevice.h: Error! Please Manually Assign EMMC_BOOTING_UP_FS_BASE_ADDRESS in custom_Memorydevice.h for EMMC Booting!"
    #else
        #define EMMC_FS_BASE_ADDRESS   (EMMC_BOOTING_UP_FS_BASE_ADDRESS)
    #endif   /* !EMMC_BOOTING_UP_FS_BASE_ADDRESS */

    #ifndef EMMC_BOOTING_UP_FS_SIZE
        #error "custom\system\{project}\custom_MemoryDevice.h: Error! Please Manually Assign EMMC_BOOTING_UP_FS_SIZE in custom_Memorydevice.h for EMMC Booting!"
    #else
        #define EMMC_FS_SIZE   (EMMC_BOOTING_UP_FS_SIZE)
    #endif   /* !EMMC_BOOTING_UP_FS_SIZE */

    #ifndef EMMC_BOOTING_UP_FS_SYSTEM_DRIVE_SIZE
        #error "custom\system\{project}\custom_MemoryDevice.h: Error! Please Manually Assign EMMC_BOOTING_UP_FS_SYSTEM_DRIVE_SIZE in custom_Memorydevice.h for EMMC Booting!"
    #else
        #define EMMC_FS_SYSTEM_DRIVE_SIZE   (EMMC_BOOTING_UP_FS_SYSTEM_DRIVE_SIZE)
    #endif   /* !EMMC_BOOTING_UP_FS_SYSTEM_DRIVE_SIZE */

#elif defined(_NAND_FLASH_BOOTING_)


        /*-----------------------------------------------------------------------------------------
         * FS base address is automatically adjusted with update package storage size as
         * NAND_BOOTING_NAND_FS_BASE_ADDRESS + FOTA_PACKAGE_STORAGE_SIZE (defined in custom_img_config.h)
         *-----------------------------------------------------------------------------------------*/

        #ifndef NAND_BOOTING_NAND_FS_BASE_ADDRESS
            #error "custom\system\{project}\custom_MemoryDevice.h: Error! Please Manually Assign NAND_BOOTING_NAND_FS_BASE_ADDRESS in custom_Memorydevice.h for NAND-Flash Booting!"
        #else
            #define NAND_FLASH_BASE_ADDRESS    (NAND_BOOTING_NAND_FS_BASE_ADDRESS + FOTA_DM_FS_OFFSET)
        #endif   /* !NAND_BOOTING_FLASH_BASE_ADDRESS */

        /*-----------------------------------------------------------------------------------------
         * FS size is automatically decreased by update package storage size as
         * NAND_BOOTING_NAND_FS_SIZE - FOTA_PACKAGE_STORAGE_SIZE (defined in custom_img_config.h)
         *-----------------------------------------------------------------------------------------*/

        #ifndef NAND_BOOTING_NAND_FS_SIZE
            #error "custom\system\{project}\custom_MemoryDevice.h: Error! Please Manually Assign NAND_BOOTING_NAND_FS_SIZE in custom_Memorydevice.h for NAND-Flash Booting!"
        #else
            #if defined(__SECURE_DATA_STORAGE__)
                #define NAND_ALLOCATED_FAT_SPACE   (NAND_BOOTING_NAND_FS_SIZE - FOTA_DM_FS_OFFSET - SDS_TOTAL_SIZE)
            #else
                #define NAND_ALLOCATED_FAT_SPACE   (NAND_BOOTING_NAND_FS_SIZE - FOTA_DM_FS_OFFSET)
            #endif
        #endif   /* !NAND_BOOTING_ALLOCATED_FAT_SPACE */

        /*-----------------------------------------------------------------------------------------
         * FS first drive size is automatically decreased by update package storage size as
         * NAND_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS - FOTA_PACKAGE_STORAGE_SIZE / 512 (defined in custom_img_config.h)
         *-----------------------------------------------------------------------------------------*/

        #ifndef NAND_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS
            #error "custom\system\{project}\custom_MemoryDevice.h: Error! Please Manually Assign NAND_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS in custom_Memorydevice.h for NAND-Flash Booting!"
        #else
            #if defined(__NANDFDM_MULTI_INSTANCE__)
                #define NAND_PARTITION_SECTORS   (0)
            #else /* __NANDFDM_MULTI_INSTANCE__ */
                #define NAND_PARTITION_SECTORS   (NAND_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS - FOTA_DM_FS_SECTOR_OFFSET)
            #endif /* __NANDFDM_MULTI_INSTANCE__ */
        #endif   /* !NAND_FAT_PARTITION_SECTORS */


#elif defined(__FS_SYSDRV_ON_NAND__ ) 

    #define NOR_FLASH_BASE_ADDRESS     (NOR_FLASH_BASE_ADDRESS_DEFAULT)
    #define NOR_ALLOCATED_FAT_SPACE    (NOR_ALLOCATED_FAT_SPACE_DEFAULT)
   
        /*-----------------------------------------------------------------------------------------
         * FS base address is automatically adjusted with update package storage size as
         * NOR_BOOTING_NAND_FS_BASE_ADDRESS + FOTA_PACKAGE_STORAGE_SIZE (defined in custom_img_config.h)
         *-----------------------------------------------------------------------------------------*/

        #ifndef NOR_BOOTING_NAND_FS_BASE_ADDRESS
            #error "custom\system\{project}\custom_MemoryDevice.h: Error! Please Manually Assign NOR_BOOTING_NAND_FS_BASE_ADDRESS in custom_Memorydevice.h for System Drive on NAND!"
        #else
            #define NAND_FLASH_BASE_ADDRESS     (NOR_BOOTING_NAND_FS_BASE_ADDRESS + FOTA_DM_FS_OFFSET)
        #endif   /* !NAND_BOOTING_FLASH_BASE_ADDRESS */
      
        /*-----------------------------------------------------------------------------------------
         * FS size is automatically decreased by update package storage size as
         * NOR_BOOTING_NAND_FS_SIZE - FOTA_PACKAGE_STORAGE_SIZE (defined in custom_img_config.h)
         *-----------------------------------------------------------------------------------------*/

        #ifndef NOR_BOOTING_NAND_FS_SIZE
            #error "custom\system\{project}\custom_MemoryDevice.h: Error! Please Manually Assign NOR_BOOTING_NAND_FS_SIZE in custom_Memorydevice.h for System Drive on NAND!"
        #else
            #define NAND_ALLOCATED_FAT_SPACE    (NOR_BOOTING_NAND_FS_SIZE - FOTA_DM_FS_OFFSET)
        #endif   /* !NAND_BOOTING_ALLOCATED_FAT_SPACE */
      
        /*-----------------------------------------------------------------------------------------
         * FS first drive size is automatically decreased by update package storage size as
         * NOR_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS - FOTA_PACKAGE_STORAGE_SIZE / 512 (defined in custom_img_config.h)
         *-----------------------------------------------------------------------------------------*/

        #ifndef NOR_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS
            #error "custom\system\{project}\custom_MemoryDevice.h: Error! Please Manually Assign NOR_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS in custom_Memorydevice.h for System Drive on NAND!"
        #else
            #if defined(__NANDFDM_MULTI_INSTANCE__)
                #define NAND_PARTITION_SECTORS      (0)
            #else /* __NANDFDM_MULTI_INSTANCE__ */
                #define NAND_PARTITION_SECTORS      (NOR_BOOTING_NAND_FS_FIRST_DRIVE_SECTORS - FOTA_DM_FS_SECTOR_OFFSET)
            #endif /* __NANDFDM_MULTI_INSTANCE__ */
        #endif   /* !NAND_FAT_PARTITION_SECTORS */
   
#else /* Generic NOR-XIP Case */

        #if defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT)
      
            #ifndef NOR_BOOTING_NOR_FS_BASE_ADDRESS
                #define NOR_FLASH_BASE_ADDRESS     (NOR_FLASH_BASE_ADDRESS_DEFAULT)
            #else
                #define NOR_FLASH_BASE_ADDRESS     (NOR_BOOTING_NOR_FS_BASE_ADDRESS)
            #endif   /* !NOR_FLASH_BASE_ADDRESS */
         
            #ifndef NOR_BOOTING_NOR_FS_SIZE
                #if defined(__SECURE_DATA_STORAGE__)
                    #define NOR_ALLOCATED_FAT_SPACE    (NOR_ALLOCATED_FAT_SPACE_DEFAULT - SDS_TOTAL_SIZE)
                #else
                    #define NOR_ALLOCATED_FAT_SPACE    (NOR_ALLOCATED_FAT_SPACE_DEFAULT)
                #endif
            #else
                #if defined(__SECURE_DATA_STORAGE__)
                    #define NOR_ALLOCATED_FAT_SPACE    (NOR_BOOTING_NOR_FS_SIZE - SDS_TOTAL_SIZE)
                #else
                    #define NOR_ALLOCATED_FAT_SPACE    (NOR_BOOTING_NOR_FS_SIZE)
                #endif
            #endif   /* !NOR_ALLOCATED_FAT_SPACE */
         
            #ifndef NOR_BOOTING_NOR_FS_FIRST_DRIVE_SECTORS
                #define NOR_PARTITION_SECTORS      (0)
            #else
                #define NOR_PARTITION_SECTORS      (NOR_BOOTING_NOR_FS_FIRST_DRIVE_SECTORS)
            #endif   /* !NOR_FAT_PARTITION_SECTORS */
         
            /*-----------------------------------------------------------------------------------------
             * FS base address is automatically adjusted with update package storage size as
             * NOR_BOOTING_NAND_FS_BASE_ADDRESS + FOTA_PACKAGE_STORAGE_SIZE (defined in custom_img_config.h)
             *-----------------------------------------------------------------------------------------*/

            #ifndef NOR_BOOTING_NAND_FS_BASE_ADDRESS
                #error "custom\system\{project}\custom_MemoryDevice.h: Error! Please Manually Assign NOR_BOOTING_NAND_FS_BASE_ADDRESS in custom_Memorydevice.h for FOTA Update Package on NAND!"
            #else
                #define NAND_FLASH_BASE_ADDRESS     (NOR_BOOTING_NAND_FS_BASE_ADDRESS + FOTA_DM_FS_OFFSET)
            #endif   /* !NAND_BOOTING_FLASH_BASE_ADDRESS */
         
            /*-----------------------------------------------------------------------------------------
             * FS size is automatically decreased by update package storage size as
             * NOR_BOOTING_NAND_FS_SIZE - FOTA_PACKAGE_STORAGE_SIZE (defined in custom_img_config.h)
             *-----------------------------------------------------------------------------------------*/

            #ifndef NOR_BOOTING_NAND_FS_SIZE
                #error "custom\system\{project}\custom_MemoryDevice.h: Error! Please Manually Assign NOR_BOOTING_NAND_FS_SIZE in custom_Memorydevice.h for FOTA Update Package on NAND!"
            #else
                #define NAND_ALLOCATED_FAT_SPACE    (NOR_BOOTING_NAND_FS_SIZE - FOTA_DM_FS_OFFSET)
            #endif   /* !NAND_BOOTING_ALLOCATED_FAT_SPACE */
         
            /* All NAND flash space is treated as one public drive */
            #define NAND_PARTITION_SECTORS          (0)
      
        #else    /* !__UP_PKG_ON_NAND__ || !NAND_SUPPORT */
      
            /*-----------------------------------------------------------------------------------------
             * FS base address is automatically adjusted with update package storage size as
             * NOR_BOOTING_NOR_FS_BASE_ADDRESS + FOTA_PACKAGE_STORAGE_SIZE (defined in custom_img_config.h)
             *-----------------------------------------------------------------------------------------*/

            #ifndef NOR_BOOTING_NOR_FS_BASE_ADDRESS
                #define NOR_FLASH_BASE_ADDRESS     (NOR_FLASH_BASE_ADDRESS_DEFAULT + FOTA_DM_FS_OFFSET)
            #else
                #define NOR_FLASH_BASE_ADDRESS     (NOR_BOOTING_NOR_FS_BASE_ADDRESS + FOTA_DM_FS_OFFSET)
            #endif   /* !NOR_FLASH_BASE_ADDRESS */
         
            /*-----------------------------------------------------------------------------------------
             * FS size is automatically decreased by update package storage size as
             * NOR_BOOTING_NOR_FS_SIZE - FOTA_PACKAGE_STORAGE_SIZE (defined in custom_img_config.h)
             *-----------------------------------------------------------------------------------------*/

            #ifndef NOR_BOOTING_NOR_FS_SIZE
                #if defined(__SECURE_DATA_STORAGE__)
                    #define NOR_ALLOCATED_FAT_SPACE    (NOR_ALLOCATED_FAT_SPACE_DEFAULT - FOTA_DM_FS_OFFSET - SDS_TOTAL_SIZE)
                #else
                    #define NOR_ALLOCATED_FAT_SPACE    (NOR_ALLOCATED_FAT_SPACE_DEFAULT - FOTA_DM_FS_OFFSET)
                #endif
            #else
                #if defined(__SECURE_DATA_STORAGE__)
                    #define NOR_ALLOCATED_FAT_SPACE    (NOR_BOOTING_NOR_FS_SIZE - FOTA_DM_FS_OFFSET - SDS_TOTAL_SIZE)
                #else
                    #define NOR_ALLOCATED_FAT_SPACE    (NOR_BOOTING_NOR_FS_SIZE - FOTA_DM_FS_OFFSET)
                #endif
            #endif   /* !NOR_ALLOCATED_FAT_SPACE */
         
            /*-----------------------------------------------------------------------------------------
             * FS first drive size is automatically decreased by update package storage size as
             * NOR_BOOTING_NOR_FS_FIRST_DRIVE_SECTORS - FOTA_PACKAGE_STORAGE_SIZE / 512 (defined in custom_img_config.h)
             *-----------------------------------------------------------------------------------------*/

            #ifndef NOR_BOOTING_NOR_FS_FIRST_DRIVE_SECTORS
                #define NOR_PARTITION_SECTORS      (0)
            #else
                #define NOR_PARTITION_SECTORS      (NOR_BOOTING_NOR_FS_FIRST_DRIVE_SECTORS - FOTA_DM_FS_SECTOR_OFFSET)
            #endif   /* !NOR_FAT_PARTITION_SECTORS */  
      
            /* If NAND_SUPPORT is enabled, all NAND flash space is treated as one public drive */
            #define NAND_PARTITION_SECTORS            (0)
      
        #endif   /* __UP_PKG_ON_NAND__ && NAND_SUPPORT */
   
        
#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

/*
 * Define __PUBLIC_DRIVE_AVAILABLE__ if public drive is available.
 * This definition will be referenced by File System. Please inform FS owner if any changes.
 */
#if defined(__NANDFDM_MULTI_INSTANCE__)
    #ifndef __PUBLIC_DRIVE_AVAILABLE__
    #define __PUBLIC_DRIVE_AVAILABLE__  // NAND FDM Multi-Instance always has public drive
    #endif
#endif

#if defined(NOR_PARTITION_SECTORS)  // NOR flash has public drive
    #if (NOR_PARTITION_SECTORS > 0)
        #if ((NOR_BOOTING_NOR_FS_FIRST_DRIVE_SECTORS - 0) < 21)
            #error "custom\system\{project}\custom_MemoryDevice.h: NOR_BOOTING_NOR_FS_FIRST_DRIVE_SECTORS should be zero Or (NOR_BOOTING_NOR_FS_FIRST_DRIVE_SECTORS - 0) should be more than 20 sectors."
        #endif

        #ifndef __PUBLIC_DRIVE_AVAILABLE__
        #define __PUBLIC_DRIVE_AVAILABLE__
        #endif
    #endif
#endif

#if defined(NAND_PARTITION_SECTORS) // NAND flash has public drive (including __FS_SYSDRV_ON_NAND__)
    #if (NAND_PARTITION_SECTORS > 0)
        #ifndef __PUBLIC_DRIVE_AVAILABLE__
        #define __PUBLIC_DRIVE_AVAILABLE__
        #endif
    #endif
#endif

#if defined(__EMMC_BOOTING__) // EMMC has public drive
    #ifndef __PUBLIC_DRIVE_AVAILABLE__
    #define __PUBLIC_DRIVE_AVAILABLE__
    #endif
#endif

#if !defined(_NAND_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__) && !defined(__FS_SYSDRV_ON_NAND__) && defined(NAND_SUPPORT)
    /*
     * NOR booting / System drive on NOR / NAND flash is existed
     * NAND_PARTITION_SECTORS is 0 but all NAND flash space is treated as one public drive
     *
     * Note. Please ensure NAND_SUPPORT is correctly DISABLED if NAND flash is NOT existed,
     *       otherwise __PUBLIC_DRIVE_AVAILABLE__ will be incorrectly defined but public drive is not existed!
     */
    #ifndef __PUBLIC_DRIVE_AVAILABLE__
    #define __PUBLIC_DRIVE_AVAILABLE__
    #endif
    
    #ifndef __PUBLIC_DRIVE_2_AVAILABLE__
    #define __PUBLIC_DRIVE_2_AVAILABLE__
    #endif
#endif

/*
 *******************************************************************************
 PART 5:
   FLASH TYPE CATEGORY below to configure flash memory command
 *******************************************************************************
*/
#ifdef NOR_FLASH_TYPE_INTEL_SERIES
#define __INTEL_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_INTEL
#define __INTEL_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_RENESAS_SERIES
#define __RENESAS_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_RENESAS
#define __RENESAS_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_INTEL_SIBLEY
#define __INTEL_SERIES_NOR__
#define __INTEL_SIBLEY__

#endif

#ifdef NOR_FLASH_TYPE_SST
#define __AMD_SERIES_NOR__
#define __SST_NOR__
#endif

#ifdef NOR_FLASH_TYPE_ST_AMD_LIKE
#define __AMD_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_ST_INTEL_LIKE
#define __INTEL_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_AMD_SERIES
#define __AMD_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_PL_J
#define __AMD_SERIES_NOR__
#define NOR_SUSPEND_LATENCY         (35)
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_PL_N
#define __AMD_SERIES_NOR__
#define __SPANSION_PL_N__
#define NOR_SUSPEND_LATENCY         (20)
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_WS_N
#define __AMD_SERIES_NOR__
#define __SPANSION_WS_N__
#define __SPANSION_PL_N__
#define NOR_SUSPEND_LATENCY         (20)
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_WS_P
#define __AMD_SERIES_NOR__
#define __SPANSION_WS_P__
#define NOR_SUSPEND_LATENCY         (40)
#define NOR_RESUME_SUSPEND_INTERVAL (40)
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_GL_A
#define __AMD_SERIES_NOR__
#define __SPANSION_GL_A__
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_GL_N
#define __AMD_SERIES_NOR__
#define __SPANSION_GL_N__
#define NOR_SUSPEND_LATENCY         (20)
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_NS_N
#define __AMD_SERIES_NOR__
#define __SPANSION_NS_N__
#define NOR_SUSPEND_LATENCY         (35)
#define NOR_RESUME_SUSPEND_INTERVAL (30)
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_NS_P
#define __AMD_SERIES_NOR__
#define __SPANSION_NS_N__
#define NOR_SUSPEND_LATENCY         (20)
#define NOR_RESUME_SUSPEND_INTERVAL (30)
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_NS_J
#define __AMD_SERIES_NOR__
#define __SPANSION_NS_J__
#define NOR_SUSPEND_LATENCY         (35)
#endif

#ifdef NOR_FLASH_TYPE_TOSHIBA
#define __AMD_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_TOSHIBA_TV
#define __AMD_SERIES_NOR__
#define __TOSHIBA_TV__
#endif

#ifdef NOR_FLASH_TYPE_TOSHIBA_TY
#define __AMD_SERIES_NOR__
#define __TOSHIBA_TY__
#endif

#ifdef NOR_FLASH_TYPE_SILICON7
#define __RENESAS_SERIES_NOR__
#endif

#ifdef NOR_FLASH_TYPE_SAMSUNG_SPANSION_NS_J_LIKE
#define __AMD_SERIES_NOR__
#define __SAMSUNG_SPANSION_NS_J_LIKE__
#define NOR_SUSPEND_LATENCY         (20)
#define NOR_RESUME_SUSPEND_INTERVAL (30)
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_VS_R
#define __AMD_SERIES_NOR__
#define __SPANSION_VS_R__
#define NOR_SUSPEND_LATENCY         (30)
#define NOR_RESUME_SUSPEND_INTERVAL (30)
#define __NOR_FDM_4_FLIPPING_TOLERABLE__
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_VS_R64
#define __AMD_SERIES_NOR__
#define __SPANSION_VS_R64__
#define __SPANSION_NS_N__
#define NOR_SUSPEND_LATENCY         (30)
#define __NOR_FDM_4_FLIPPING_TOLERABLE__
#endif

#ifdef NOR_FLASH_TYPE_SPANSION_WS_R
#define __AMD_SERIES_NOR__
#define __SPANSION_WS_R__
#define NOR_SUSPEND_LATENCY         (30)
#define NOR_RESUME_SUSPEND_INTERVAL (30)
#define __NOR_FDM_4_FLIPPING_TOLERABLE__
#endif

/*
 *******************************************************************************
 PART 6:
   FOTA UPDATABLE FLASH AREA
 *******************************************************************************
*/
#ifdef __FOTA_DM__
        #ifndef CONFIG_FOTA_UE_FLASH_SPACE
                #error "custom\system\{project}\custom_FeatureConfig.h: Error! Please define CONFIG_FOTA_UE_FLASH_SPACE in custom_FeatureConfig.h!"
        #endif /* CONFIG_FOTA_UE_FLASH_SPACE */
        
        #ifndef CONFIG_FOTA_PACKAGE_BLOCK_NUMBER
                #error "custom\system\{project}\custom_FeatureConfig.h: Error! Please define CONFIG_FOTA_PACKAGE_BLOCK_NUMBER in custom_FeatureConfig.h!"
        #endif /* CONFIG_FOTA_PACKAGE_BLOCK_NUMBER */
#endif /* __FOTA_DM__ */


