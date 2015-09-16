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
#include "bl_trc_api.h"

#include "cache_sw_int.h"
#include "cache_sw.h"
#include "cache_hw_int.h"
#include "cache_hw.h"
#include "init.h"
#if defined(__CR4__)
#include "mpu.h"
#include "cp15.h"
#endif /* __CR4__ */
 
#include "br_time_stamp.h"
#ifdef __TIME_STAMP__ 
#include "br_time_stamp_cb.h"
#include "bl_time_stamp_id.h"
#endif

/*************************************************************************
 * MiniBootloader part
 *************************************************************************/

#ifdef __MINI_BOOTLOADER__

void CachePreInitMini(void)
{
#if defined(__CR4__)

    /*All the MPU setting reuses the setting set by BootROM, except enable cacheable and device type access region here*/

    /* Set DRAM cacheable region*/
    mpu_set_region_primitive(0, 0x0, RGN_SIZE_1GB, MPU_NORMAL_INWBWA_OUTWBWA | MPU_PRW_URW, 1);

    /* Set device type region for register access */
    mpu_set_region_primitive(2, 0x80000000, RGN_SIZE_2GB, MPU_DEVICE_INNS_OUTDEV|MPU_PRW_URW|MPU_XN, 1);

    /* Set strongly order region for register access */
    mpu_set_region_primitive(5, 0xF0000000, RGN_SIZE_256MB, MPU_SOM|MPU_PRW_URW|MPU_XN, 1);
    
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

}

void CacheDeInitMini(void)
{

}

#endif /* __MINI_BOOTLOADER */

/*************************************************************************
 * ExtBootloader part
 *************************************************************************/

#ifdef __EXT_BOOTLOADER__

#ifdef __MTK_TARGET__

void CacheDeinit(void)
{
    //Disable I/D Cache
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
}

void SwitchMAUIToCacheable(kal_uint32 on, kal_uint32 param)
{
    
}

void CacheInit(void)
{
    INT_Trace_Enter(BL_CACHE_INIT);

    if(!cp15_is_dcache_enabled())
    {
        cp15_invalidate_dcache();
        cp15_enable_dcache();
    }
    
    if(!cp15_is_icache_enabled())
    {
        cp15_invalidate_icache();
        cp15_enable_icache();
    }

    INT_Trace_Exit(BL_CACHE_INIT);
}

#endif /* __MTK_TARGET__ */

#endif /* __EXT_BOOTLOADER__ */

kal_int32 invalidate_dcache(kal_uint32 addr, kal_uint32 len)
{
    cp15_invalidate_dcache_region(addr, len / CPU_CACHE_LINE_SIZE);
    cp15_drain_write_buffer();    
    return 0;
}

kal_int32 clean_dcache(kal_uint32 addr, kal_uint32 len)
{
    cp15_clean_dcache_region(addr, len / CPU_CACHE_LINE_SIZE);
    cp15_drain_write_buffer();    
    return 0;
}

kal_int32 clean_and_invalidate_dcache(kal_uint32 addr, kal_uint32 len)
{
    cp15_clean_and_invalidate_dcache_region(addr, len / CPU_CACHE_LINE_SIZE);
    cp15_drain_write_buffer();
    return 0;
}

kal_int32 query_is_noncached_ram(kal_uint32 addr, kal_uint32 len)
{
    return ((((kal_uint32)(addr) & CREG_OFFSET) ^ CREG_OFFSET) == 0);
}

kal_int32 query_is_cached_ram(kal_uint32 addr, kal_uint32 len)
{
    return ((((kal_uint32)(addr) & CREG_OFFSET) ^ CREG_OFFSET) != 0);
}

/*************************************************************************
* FUNCTION
*  phys_to_virt
*
* DESCRIPTION
*  This function used to query the physical address (non-cacheable) of a virtual address
*  (cacheable)
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*
* RETURNS
*
*************************************************************************/
kal_uint32 virt_to_phys(void * address)
{
    return MAP2CREGPA(address);
}

/*************************************************************************
* FUNCTION
*  phys_to_virt
*
* DESCRIPTION
*  This function used to query the virtual  address (cacheable) of a physical address
*  (non-cacheable)
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*
* RETURNS
*
*************************************************************************/
kal_uint32 phys_to_virt(void * address)
{
    return MAP2CREGVA(address);
}
