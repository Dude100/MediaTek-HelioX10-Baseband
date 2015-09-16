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
 *   bl_Cache.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   This file defines the initializion code for cache
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
#include "bl_setting.h"
#include "bl_common.h"
#include "bl_sectiondef.h"

#include "cache_sw_int.h"
#include "cache_sw.h"
#include "cache_hw_int.h"
#include "cache_hw.h"
#include "init.h"
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__CR4__)
#include "mmu_int.h"
#include "mmu.h"
#include "cp15.h"
#endif /* __ARM9_MMU__ || __ARM11_MMU__ || __CR4__ */
#if defined(__CR4__)
#include "mpu.h"
#endif /* __CR4__ */
 
#include "br_time_stamp.h"
#ifdef __TIME_STAMP__ 
#include "br_time_stamp_cb.h"
#include "bl_time_stamp_id.h"
#endif

/*************************************************************************
 * Common part
 *************************************************************************/
#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

void SetupMPUCacheByFeature(void)
{
}

void SetupMPUonTCM(void)
{
}
#endif /* __MTK_L1CACHEABLE__ || __MTK_MMU__ */

/*************************************************************************
 * MiniBootloader part
 *************************************************************************/

#ifdef __MINI_BOOTLOADER__

void CachePreInitMini(void)
{
#if defined(__CR4__)

    //Disable MPU first
    //NOTE: this code should be put in default executable memory region!!
    cp15_disable_mpu();
    
    //mpu_set_region_primitive(INDEX, START_ADDRESS, REGION_SIZE, ATTRIBUTE, ENABLE)
    /* We cannot use MPU functions since SaveAndSetIRQMask() is not initialized (actually we don't need it now) */
    /* Set 4GB Read/Write Cacheable Normal */
    mpu_set_region_primitive(0, 0, RGN_SIZE_4GB, MPU_NORMAL_INWBWA_OUTWBWA|MPU_PRW_URW, 1);

    /* Set APB region as SOM */
    /* For UART bootupt init */
    mpu_set_region_primitive(1, APB_REGION_ADDR_MD, APB_REGION_SIZE, MPU_SOM | MPU_PRW_URW, 1);    
    mpu_set_region_primitive(2, 0xa0000000, APB_REGION_SIZE, MPU_SOM | MPU_PRW_URW, 1);  

    /* Set A/B TCM Read/Write Non-cacheable Normal (CR4 support max 8MB ATCM) */
    mpu_set_region_primitive(3, 0x70000000, RGN_SIZE_8MB, MPU_NORMAL_INNC_OUTNC|MPU_PRW_URW, 1);
    
    /* Enable MPU */
	  //Disable I/D Cach first as TRM described
    if(cp15_is_dcache_enabled())
    {
    	  cp15_clean_dcache();
    	  cp15_invalidate_dcache();
		  cp15_disable_dcache();
		    
    }
    if(cp15_is_icache_enabled())
    {
		  cp15_invalidate_icache();
		  cp15_disable_icache();
    }
    
    //Enable MPU
    cp15_enable_mpu();

#endif /* __CR4__ */

}

void CacheInitMini(void)
{
#if !defined(__BRINGUP_SUPPORT__)
   
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
   cp15_invalidate_icache();	 
   cp15_enable_icache();
#endif   

#if defined(__ARM11_MMU__)
//      cp15_enable_branch_prediction();
#endif /* __ARM11_MMU__ */

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

#if defined(__CRYPTO_SHARED_DRV__)
   CustomizedCacheInit(BOOTROM_BASE, BOOTROM_BASE+BOOTROM_LENGTH, BOOTROM_LENGTH);
#endif

#endif /* __MTK_L1CACHEABLE__ || __MTK_MMU__ */

#endif /* !__BRINGUP_SUPPORT__ */
}

void CacheDeInitMini(void)
{
#if !defined(__BRINGUP_SUPPORT__)

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
   if ( cp15_is_icache_enabled() )
   {
      cp15_disable_icache();	 
   }
#endif   

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

#if defined(__CRYPTO_SHARED_DRV__)
   CustomizedCacheDeInit();
#endif

#endif /* __MTK_L1CACHEABLE__ || __MTK_MMU__ */

#endif /* !__BRINGUP_SUPPORT__ */
}

#endif /* __MINI_BOOTLOADER */

/*************************************************************************
 * ExtBootloader part
 *************************************************************************/

#ifdef __EXT_BOOTLOADER__

__BL_ALIGN(16*1024) __ext_un_init_zi__ kal_uint32 page_tbl[4096];

#ifdef __MTK_TARGET__

void CacheDeinit(void)
{
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
   if ( cp15_is_dcache_enabled() )
   {
      cp15_clean_dcache();
	   cp15_drain_write_buffer();	 
      cp15_disable_dcache();	
   }
   
   if ( cp15_is_icache_enabled() )
   {
      cp15_disable_icache();	 
   }
   
   cp15_disable_mmu();
#if defined(__ARM9_MMU__)
   cp15_disable_rom_protect();
   cp15_disable_alignment_fault();
#endif /* __ARM9_MMU__ */
#else

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)
   /* Inv code cache */
   MTKL1CACHE_InvalidAllCacheLines();

   /* disable code cache. */
   CodeCacheClearAllSetting();

   /* disable code mpu. */
   MPUClearAllSetting();
#endif   /* __MTK_L1CACHEABLE__ || __MTK_MMU__ */

#endif
}

void SwitchMAUIToCacheable(kal_uint32 on, kal_uint32 param)
{
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)

   kal_uint32 end = 0;
   kal_int32 i;
   MMU_PAGE_CONFIG_T pagc;
   
   const kal_uint32 ONE_MB = 1024*1024;

   extern kal_uint32 Image$$EXT_UN_INIT$$Base;
   end = (kal_uint32)(&Image$$EXT_UN_INIT$$Base) & ~(ONE_MB-1);

   cp15_disable_mmu();

   /* make page table */
   if(on)
   {
      DEFAULT_RW_CB((MMU_PAGE_CONFIG_PTR)&pagc);
   }
   else
   {
      DEFAULT_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
   }
   
   for (i = 0; i < end; i+=ONE_MB)
   {
      page_tbl[i>>PAGE_SIZE_1MB_SHIFT] = mk_sd(i, (MMU_PAGE_CONFIG_PTR)&pagc);
   }

   cp15_enable_mmu(); 			
   cp15_invalidate_tlb();

#endif /* __ARM9_MMU__ || __ARM11_MMU__ */
#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */
}

void CacheInit(void)
{
   TS_BEGIN(TSID_BL_CACHE_INIT);

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
{
   kal_uint32 start, end;
   kal_int32 i;
   MMU_PAGE_CONFIG_T pagc;
   
   const kal_uint32 ONE_MB = 1024*1024;

   extern kal_uint32 Image$$EXT_READ_ONLY$$Base;
   extern kal_uint32 Image$$EXT_READ_WRITE$$ZI$$Limit;
   
   start = (kal_uint32)(&Image$$EXT_READ_ONLY$$Base) & ~(ONE_MB-1);
   end   = ((kal_uint32)(&Image$$EXT_READ_WRITE$$ZI$$Limit) + ONE_MB - 1) & ~(ONE_MB-1);

   CacheDeinit();

   /* make page table */
   DEFAULT_REGISTER_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
   for (i = 4095; i >= 0; i--)
   {
      page_tbl[i] = mk_sd(i << 20, (MMU_PAGE_CONFIG_PTR)&pagc);
   }

   /* TCM page configuration */
   EXE_RW_TCM((MMU_PAGE_CONFIG_PTR)&pagc);
   page_tbl[BOOTROM_ITCM_BASE>>PAGE_SIZE_1MB_SHIFT] = mk_sd(BOOTROM_ITCM_BASE, (MMU_PAGE_CONFIG_PTR)&pagc);
   page_tbl[BOOTROM_DTCM_BASE>>PAGE_SIZE_1MB_SHIFT] = mk_sd(BOOTROM_DTCM_BASE, (MMU_PAGE_CONFIG_PTR)&pagc);

   /* Turn on cache on ExtBootloader */
   DEFAULT_RW_CB((MMU_PAGE_CONFIG_PTR)&pagc);
   
#if defined(__EMMC_BOOTING__)

#if defined(__MTK_INTERNAL__)
//Note: do not turn on cache because eMMC drvier is using DMA now as a temp solution
//eMMC owner will change it to PIO
#endif

#else

   for (i = start; i < end; i+=ONE_MB)
   {
      page_tbl[i>>PAGE_SIZE_1MB_SHIFT] = mk_sd(i, (MMU_PAGE_CONFIG_PTR)&pagc);
   }
   
#endif

#if defined(MT6236) || defined(MT6236B)

   *((volatile unsigned int *)0x80000730) &= ~0x003FC000;
   *((volatile unsigned int *)0x80000730) |= 0x002A8000;

   /* set MUCSYS_DELSEL for E2 DCache bug */
   if(INT_ecoVersion() == ECO_E2) {
       *(volatile unsigned int *)0x80000730 &= ~0x3FC00000;
       *(volatile unsigned int *)0x80000730 |= 0x3FC00000; // D-caceh delsel = 3
   }

#endif  /* MT6218B */

   /* set translation table base */
   cp15_write_tbbr((kal_uint32)page_tbl);
  
   /* set domain 0 access control */
   cp15_write_domain_access(DOMAIN00, DOMAIN_CLIENT);

#if defined(__ARM11_MMU__)
//   cp15_enable_branch_prediction();
#endif /* __ARM11_MMU__ */

   cp15_invalidate_icache();	 
   cp15_enable_icache();

   cp15_invalidate_dcache();
   cp15_enable_dcache();
	
   /* enable MMU */
   cp15_enable_mmu();

}

#elif defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

{
   extern kal_uint32 Image$$EXT_READ_ONLY_TAIL$$Limit;
#ifdef __SV5_ENABLED__
   extern kal_uint32 Image$$EXT_BL_GFH_SECTION$$Base;
   kal_uint32 start = (kal_uint32)(&Image$$EXT_BL_GFH_SECTION$$Base);
#else
   extern kal_uint32 Image$$EXT_READ_ONLY$$Base;
   kal_uint32 start = (kal_uint32)(&Image$$EXT_READ_ONLY$$Base);
#endif
   kal_uint32 end   = (kal_uint32)(&Image$$EXT_READ_ONLY_TAIL$$Limit);
   kal_uint32 len;

   start = ((start + 4095)>>12)<<12;
   len = ((end>>12)<<12) - start;
   
   if(end > start && len)
   {
      CustomizedCacheInit(start, end, len);
   }  
}  
#endif

   TS_END(TSID_BL_CACHE_INIT);
}

#endif /* __MTK_TARGET__ */

#endif /* __EXT_BOOTLOADER__ */

