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
 *   bl_common.h
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   Bootloader header, common definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 [Note] 
 Following files/modules are currently shared by MAUI and Bootloader, or invoking MAUI components.
 Must consult with the owner if the behavior is changed
 
 For accessing cp15, initializing cache
 --------------------------------------------------
 cp15
     cp15_clean_dcache
     cp15_disable_alignment_fault
     cp15_disable_dcache
     cp15_disable_icache
     cp15_disable_mmu
     cp15_disable_rom_protect
     cp15_drain_write_buffer
     cp15_enable_dcache
     cp15_enable_icache
     cp15_enable_mmu
     cp15_invalidate_dcache
     cp15_invalidate_icache
     cp15_is_dcache_enabled
     cp15_is_icache_enabled
     cp15_write_domain_access
     cp15_write_tbbr
 
 To turn on code cache
 --------------------------------------------------
 cache
     MTKL1CACHE_InvalidAllCacheLines
     MPUClearAllSetting
     CodeCacheClearAllSetting
     CodeCacheGetChannel
     CodeCacheSetting
     CodeCacheConfig
     
 NAND driver
 --------------------------------------------------
 NAND_DevConfig, nand_dal
 
 Crypto/Hashing for security platform
 --------------------------------------------------
 md5_engine
     CHE_md5_init
     CHE_md5_append
     CHE_md5_finish
     
 rc4_engine
     che_rc4_set_key
     che_rc4
     
 sha1_engine
     CHE_sha1_Init
     CHE_sha1_append
     CHE_sha1_finish
 
     
 USBDL sharing USB driver with MAUI
 --------------------------------------------------
 usb_custom.obj              
 usbdl_debug_tool.obj        
 usbdl_pmu.obj               
 usbdl_usb.obj               
 usbdl_usb_drv.obj           
 usbdl_usb_resource.obj      
 usbdl_usbacm_adap.obj       
 usbdl_usbacm_drv.obj        
 
 
 Custom files for EMI/DRAM init
 --------------------------------------------------
 custom_emi
     custom_InitDRAM
     custom_setEMI
     
 custom_flash
     custom_get_NORFLASH_Base
     custom_get_NORFLASH_Size
 
*****************************************************************************/
 
#ifndef _BOOTLOADER_COMMON_H
#define _BOOTLOADER_COMMON_H

#include "kal_general_types.h"
#include "bl_loader.h"
#include "bl_features.h"
#include "bl_custom.h"
#include "bl_setting.h"
#include "bl_status.h"

extern kal_uint32 custom_ROM_baseaddr(void);
extern kal_uint32 Load$$EXT_READ_ONLY$$Base;


#if defined(__MTK_TARGET__)
#if defined(__ARMCC_VERSION)    
#define __BL_ALIGN(SIZE) __align(SIZE)
#elif defined(__GNUC__)
#define __BL_ALIGN(SIZE) __attribute__((aligned (SIZE)))
#endif
#else
#define __BL_ALIGN(...) 
#endif


//#define BL_DEBUG_PRINT dbg_print
#define BL_DEBUG_PRINT(...)

#if defined(BL_DEBUG)
#define BL_PRINT bl_print
#else
#define BL_PRINT(...)
#endif

#define INVALID_START_ADDR          (0xffffffff)
#define MAUI_START_ADDR_NOR         ((kal_uint32)custom_ROM_baseaddr())
#define FACTORY_BIN_START_ADDR_NOR  ((kal_uint32)custom_FACTORY_ROM_baseaddr())

#define BL_DA_SHARED_DATA_ID_FUNC_TBL_ADDR	1
#define BL_DA_SHARED_DATA_ID_SECURE_RO_ADDR	2
#define BL_DA_SHARED_DATA_ID_EXT_BL_UPDATE_INFO     3

#define BL_BOOTUP_FAIL_REASON_NONE                  0
#define BL_BOOTUP_FAIL_REASON_UPDATE_IN_PROGRESS    1
#define BL_BOOTUP_FAIL_REASON_UNABLE_TO_READ_ILB    2
#define BL_BOOTUP_FAIL_PAIRED_VER_MISMATCHED        3
#define BL_BOOTUP_FAIL_UNSUPPORTED_MAUI_FEAUTRE     4
#define BL_BOOTUP_FAIL_LOADING_MAUI_HEAD_ERROR      5
#define BL_BOOTUP_FAIL_LOADING_MAUI_BODY_ERROR      6
#define BL_BOOTUP_FAIL_BACKUP_BL_EXECUTING          7



extern const kal_int8 BootLDVerno[];
extern kal_uint32 g_mauiFeatureCombination;

#ifdef __CUST_NEW__
extern const kal_uint8  gpio_usbdl_pin;         //Defined by Drv Tool
#endif /* __CUST_NEW__ */


extern kal_uint32 g_maui_load_addr;

extern void CachePreInitMini(void);
extern void CacheDeInitMini(void);

extern void set_debug_level(LOG_LEVEL level);
extern void bl_print(LOG_LEVEL level, kal_char *fmt, ...);
extern void dbg_print(kal_char *fmt, ...);

extern kal_uint32 GetBootloaderRegionBound(void);
extern kal_bool CheckFeatureCompatibility(kal_uint32 mauiFeatureSet);
extern kal_uint32 BlFeatureCombination(void);
extern kal_uint32 MauiFeatureCombination(void);
extern kal_bool IsMetaModeEnabled(void);
extern kal_bool IsInWithOutBatteryMode(void);

typedef enum {
   BL_FREE_TO_DA               = 1,     // OK to load and execute DA
   BL_FREE_DURING_EXECUTION    = 2,     // OK to execute DA but not for loading (Free to DA after jumping)
   BL_EXCLUSIVE_TO_DA          = 3      // DA should not use it even in the DA's life cycle
} BL_MEM_PERM;

typedef struct
{
   kal_uint32  addr;
   kal_uint32  len;
   BL_MEM_PERM type;
} BL_MEM_REGION_INFO;


#endif /* _BOOTLOADER_COMMON_H */

