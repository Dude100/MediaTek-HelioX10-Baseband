/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   cache.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the functionality of Code and Data cache.
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
 * removed!
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
 * removed!
 * removed!
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
 *
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************************
 * README
 * Test platform after revision
 * [1] NOR Flash boot without remap , MT6229_EVB
 * [2] NAND Flash boot , MT6228_EVB
 * [3] NOR Flash boot with remap , MT6225 + Single Bank NOR Flash , for example CRYSTAL25 V3 SB
 ********************************************************************************************/

/*******************************************************************************
 * DRIVER Note
 *
 * [2012/01/16] Cache driver type major compile options: __ARM9_MMU__/__ARM11_MMU__/__MTK_MMU__/__CR4__ (Only one will be enabled at a time)
 *     [1] ARM9 MMU: for ARM9 platforms
 *     [2] ARM11 MMU: for ARM11 platforms
 *     [3] MTK_MMU: form ARM7 platforms, driving MTK designed cache hardware (cahce/TCM/remapping/MPU)
 *     [4] CR4: for CR4 platforms, driving ARM caches and MTK address remapping mechanism
 *******************************************************************************/

/*******************************************************************************
 * Include header files.
 *******************************************************************************/
#include "cache_drv_region.h"
#include "cache_hw_int.h"
#include "cache_sw_int.h"
#include "cache_sw.h"
#include "init.h"
#include "cp15.h"
#include "mmu.h"
#include "mmu_int.h"
#include "custom_scatstruct.h"
#if defined(__MTK_MMU__)
#include "custom_EMI_release.h"
#endif /* __MTK_MMU__ */
#include "system_trc.h"
#include "init_trc_api.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "drv_comm.h"
#include "config_hw.h"
#include "mpu.h"
#include "cache_dbg.h"

#ifdef __CACHE_DEBUG_EN__
SEC_INTSRAM_DATA_ZI CACHE_LOG_T g_cache_inv_log[CACHE_DBG_LOG_MAX];
SEC_INTSRAM_DATA_ZI CACHE_LOG_T g_cache_cln_log[CACHE_DBG_LOG_MAX];
SEC_INTSRAM_DATA_ZI CACHE_LOG_T g_cache_cln_inv_log[CACHE_DBG_LOG_MAX];
SEC_INTSRAM_DATA_ZI kal_uint32 g_cache_inv_log_idx = 0;
SEC_INTSRAM_DATA_ZI kal_uint32 g_cache_cln_log_idx = 0;
SEC_INTSRAM_DATA_ZI kal_uint32 g_cache_cln_inv_log_idx = 0;
#endif /*__CACHE_DEBUG_EN__*/

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || (__CR4__)
extern unsigned int cache_line_nr;
extern unsigned int cache_line_nr_per_way;
#endif /* __ARM9_MMU__ || __ARM11_MMU__ || __CR4__ */

extern kal_uint32 query_opposite_switchable_cacheaddr_ram(kal_uint32 addr);

/*******************************************************************************
 * Define import functions.
 *******************************************************************************/

extern void RestoreIRQMask(kal_uint32 ret);
extern kal_uint32 SaveAndSetIRQMask(void);
extern kal_uint32 custom_get_NORFLASH_ROMSpace(void);
extern kal_int32 query_is_l1cache_cacheable(kal_uint32 addr, kal_uint32 len, kal_uint32 query_ram);

#if defined(__MTK_TARGET__) 
/*******************************************************************************
 * Define global data.
 *******************************************************************************/

#if defined(__MTK_MMU__)
static kal_uint16 MPUChannelStatus = 0;
static kal_uint16 CodeCacheChannelStatus = 0;
#endif  /* __MTK_MMU__ */
/*************************************************************************
* FUNCTION
*  invalidate_arm9_icache
*
* DESCRIPTION
*  This function invalidates the buffer's data in ICache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr     -   address of the buffer
*  len      -   length of the buffer (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/

#if defined(__ARM9_MMU__)
kal_int32 invalidate_arm9_icache(kal_uint32 addr, kal_uint32 len)
{
    return invalidate_icache(addr, len);
}
#endif  /* __ARM9_MMU__ */

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
kal_int32 invalidate_icache(kal_uint32 addr, kal_uint32 len)
{
    /*
     * NoteXXX: Each cache line in ARM9/ARM11 ICache is 32B. Every invalidate operation
     *          must aligned in a 32B address.
     *
     */

    if (addr & CPU_CACHE_LINE_SIZE_MASK)
    {
        ASSERT(0);
    }
    else if (len & CPU_CACHE_LINE_SIZE_MASK)
    {
        ASSERT(0);
    }
    else
    {
#if defined(__MTK_MMU__) || defined(__MTK_MMU_V2__)
        invalidate_l1cache(addr, len);
#else /* __MTK_MMU__ || __MTK_MMU_V2__*/
        cp15_invalidate_icache_region(addr, len / CPU_CACHE_LINE_SIZE);
#endif /* __ARM9_MMU__ || __ARM11_MMU__ || __CR4__ */
    }

    return 0;
}
#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ */

/*************************************************************************
* FUNCTION
*  invalidate_arm9_dcache
*
* DESCRIPTION
*  This function invalidates the buffer's data in DCache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr     -   address of the buffer
*  len      -   length of the buffer (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/

#if defined(__ARM9_MMU__)
INVALIDATE_DCACHE_PLACEMENT
kal_int32 invalidate_arm9_dcache(kal_uint32 addr, kal_uint32 len)
{
    return invalidate_dcache(addr, len);
}
#endif  /* __ARM9_MMU__ */


#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
INVALIDATE_DCACHE_PLACEMENT
kal_int32 invalidate_dcache(kal_uint32 addr, kal_uint32 len)
{ 
    /*
     * NoteXXX: Each cache line in ARM9 DCache is 32B. Every invalidate operation
     *          must aligned in a 32B address.
     *
     */
    CACHE_DBG_LOG_ENQUEUE(CACHE_INV_LOG, CACHE_INV_LOG_IDX, addr, len);

    if ((addr & CPU_CACHE_LINE_SIZE_MASK) ||
        (len & CPU_CACHE_LINE_SIZE_MASK))
    {
        EXT_ASSERT(0, addr, len, 0);
    }
    else
    {
#if defined(__MTK_MMU__) || defined(__MTK_MMU_V2__)
        invalidate_l1cache(addr, len);
#else /* __MTK_MMU__ || __MTK_MMU_V2__ */
        /* ARM Cache Operation */
        kal_uint32 operate_line_nr;
        operate_line_nr=len / CPU_CACHE_LINE_SIZE;
        
        /* 
         * If operating length larger than cache size,
         * We will do a full cache clean+invalidate to improve the responsiveness
         * Note that we will do this no matter it is a MMv2 buffer or not
         */
        if(operate_line_nr>cache_line_nr)
        {
            cp15_clean_and_invalidate_all_dcache_by_setway();
            return 0;
        }
        cp15_invalidate_dcache_region(addr, len / CPU_CACHE_LINE_SIZE);
#endif /* __ARM9_MMU__ || __ARM11_MMU__ || __CR4__ */
    }

    return 0;
}
#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ */

/*************************************************************************
* FUNCTION
*  clean_arm9_dcache
*
* DESCRIPTION
*  This function cleans the buffer's data in DCache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr     -   address of the buffer
*  len      -   length of the buffer (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
#if defined(__ARM9_MMU__)
CLEAN_DCACHE_PLACEMENT
kal_int32 clean_arm9_dcache(kal_uint32 addr, kal_uint32 len)
{
    return clean_dcache(addr, len);
}
#endif  /* __ARM9_MMU__ */

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
CLEAN_DCACHE_PLACEMENT
kal_int32 clean_dcache(kal_uint32 addr, kal_uint32 len)
{
    /*
     * NoteXXX: Each cache line in ARM9 DCache is 32B. Every invalidate operation
     *          must aligned in a 32B address.
     *
     */
    CACHE_DBG_LOG_ENQUEUE(CACHE_CLN_LOG, CACHE_CLN_LOG_IDX, addr, len);

    if ((addr & CPU_CACHE_LINE_SIZE_MASK) ||
        (len & CPU_CACHE_LINE_SIZE_MASK))
    {
        EXT_ASSERT(0, addr, len, 0);
    }
    else
    {
#if defined(__MTK_MMU__) || defined(__MTK_MMU_V2__)
        clean_l1cache(addr, len);
#else /* __MTK_MMU__ || __MTK_MMU_V2__ */
        /* For ARM9/ARM11/CR4 */
        kal_uint32 operate_line_nr;
        operate_line_nr=len / CPU_CACHE_LINE_SIZE;
        /* 
         * If operating length larger than cache size,
         * We will do a full cache clean to improve the responsiveness
         * Note that we will do this no matter it is a MMv2 buffer or not
         */
        if(operate_line_nr>cache_line_nr)
        {
            cp15_clean_all_dcache_by_setway();
            cp15_drain_write_buffer();
            return 0;
        }
        cp15_clean_dcache_region(addr, len / CPU_CACHE_LINE_SIZE);
        cp15_drain_write_buffer();
#endif /* __ARM9_MMU__ || __ARM11_MMU__ || __CR4__ */
    }
    return 0;
}
#endif  /* __DYNAMIC_SWITCH_CACHEABILITY__ */

/*************************************************************************
* FUNCTION
*  clean_and_invalidate_arm9_dcache
*
* DESCRIPTION
*  This function cleans and invalidates the buffer's data in DCache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr     -   address of the buffer
*  len      -   length of the buffer (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
#if defined(__ARM9_MMU__)
CLEAN_AND_INVALIDATE_DCACHE_REGION_PLACEMENT
kal_int32 clean_and_invalidate_arm9_dcache(kal_uint32 addr, kal_uint32 len)
{
    return clean_and_invalidate_dcache(addr, len);
}

#endif  /* __ARM9_MMU__ */


#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
CLEAN_AND_INVALIDATE_DCACHE_REGION_PLACEMENT
kal_int32 clean_and_invalidate_dcache(kal_uint32 addr, kal_uint32 len)
{
    /*
     * NoteXXX: Each cache line in ARM9 DCache is 32B. Every invalidate operation
     *          must aligned in a 32B address.
     *
     */
    CACHE_DBG_LOG_ENQUEUE(CACHE_CLN_INV_LOG, CACHE_CLN_INV_LOG_IDX, addr, len);

    if ((addr & CPU_CACHE_LINE_SIZE_MASK) ||
        (len & CPU_CACHE_LINE_SIZE_MASK))
    {
        EXT_ASSERT(0, addr, len, 0);
    }
    else
    {
#if defined(__MTK_MMU__) || defined(__MTK_MMU_V2__)
        clean_l1cache(addr, len);
        invalidate_l1cache(addr, len);
#else /* __MTK_MMU__ || __MTK_MMU_V2__ */
        /* For ARM9/ARM11/CR4 */
        kal_uint32 operate_line_nr;
        operate_line_nr=len / CPU_CACHE_LINE_SIZE;
        /* 
         * If operating length larger than cache size,
         * We will do a full cache clean+invalidate to improve the responsiveness
         * Note that we will do this no matter it is a MMv2 buffer or not
         */
        if(operate_line_nr>cache_line_nr)
        {
            cp15_clean_and_invalidate_all_dcache_by_setway();
            cp15_drain_write_buffer();
            return 0;
        }
        cp15_clean_and_invalidate_dcache_region(addr, len / CPU_CACHE_LINE_SIZE);
        cp15_drain_write_buffer();
#endif /* __ARM9_MMU__ || __ARM11_MMU__ || __CR4__ */
    }
    return 0;
}
#endif  /* __DYNAMIC_SWITCH_CACHEABILITY__ */


/*************************************************************************
* FUNCTION
*  MPUGetChannel
*
* DESCRIPTION
*  This function used to get MPU channel
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  Channel is numbered from 0 up to 7
*
* RETURNS
*
*************************************************************************/
#if defined(__MTK_MMU__)

kal_bool MPUGetChannel(kal_uint16 *channel)
{
    kal_uint16 i, status;
    kal_uint32 interruptMask;

    interruptMask = SaveAndSetIRQMask();

    status = MPUChannelStatus;

    for (i = 0; i < MPU_CHANNEL_NUM; i++)
    {
        if (status & 0x01)
        {
            status >>= 1;
        }
        else
        {
            break;
        }
    }

    if (i >= MPU_CHANNEL_NUM)
    {
        RestoreIRQMask(interruptMask);
        return KAL_FALSE;
    }

    *channel = i;
    MPUChannelStatus |= (0x01 << i);

    RestoreIRQMask(interruptMask);

    return KAL_TRUE;
}
#endif /* __MTK_MMU__ */

/*************************************************************************
* FUNCTION
*  MPUFreeChannel
*
* DESCRIPTION
*  This function used to get MPU channel
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  Channel is numbered from 0 up to 7
*
*
* RETURNS
*
*************************************************************************/
#if defined(__MTK_MMU__)
kal_bool MPUFreeChannel(kal_uint16 *channel)
{
    kal_uint16 channel_no = *channel;
    kal_uint32 interruptMask;

    ASSERT(channel_no < MPU_CHANNEL_NUM);

    interruptMask = SaveAndSetIRQMask();

    MPUChannelStatus &= ~(0x01 << channel_no);

    RestoreIRQMask(interruptMask);

    return KAL_TRUE;
}

#endif /* __MTK_MMU__ */

/*************************************************************************
* FUNCTION
*  CodeCacheConifg
*
* DESCRIPTION
*   This function could be used to configure code cache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#if defined(__MTK_MMU__)
#ifdef __MTK_TARGET__
__attribute__ ((section("INTSRAM_ROCODE")))
#endif /* __MTK_TARGET__ */
void CodeCacheConfig(CacheType type, kal_bool enable)
{
    kal_uint32 interruptMask;

    interruptMask = SaveAndSetIRQMask();
    *CACHE_CON &= ~(0x0d);
    /* Invalid all cache line */
    *CACHE_OP = 0x03;
    /* Reset counters */
    *CACHE_HCNT0L = 0x00;
    *CACHE_HCNT0U = 0x00;
    *CACHE_CCNT0L = 0x00;
    *CACHE_CCNT0U = 0x00;
    *CACHE_HCNT1L = 0x00;
    *CACHE_HCNT1U = 0x00;
    *CACHE_CCNT1L = 0x00;
    *CACHE_CCNT1U = 0x00;

    if (enable && (type != NO_CACHE))
    {
        *CACHE_CON &= ~L1CACHE_GEN_CACHESIZE_MASK;
        *CACHE_CON |= (type | 0x808d);
    }
    RestoreIRQMask(interruptMask);
}


#endif /* __MTK_MMU__ */

/*************************************************************************
* FUNCTION
*  CodeCacheClearAllSetting
*
* DESCRIPTION
*  This function used to initialization a cache region.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  This sub-routine takes care of the range alignment, also the least
*  cacheable region.
*
* RETURNS
*
*************************************************************************/
#if defined(__MTK_MMU__)
#ifdef __MTK_TARGET__
__attribute__ ((section("INTSRAM_ROCODE")))
#endif /* __MTK_TARGET__ */
void CodeCacheClearAllSetting(void)
{
    kal_uint32 status, index;

    *CACHE_CON &= ~(0x01);
    status = CodeCacheChannelStatus;
    for (index = 0; index < CACHE_CHANNEL_NUM; index++)
    {
        if (status & 0x01)
        {
            *(MPU_CACHE0 + index) = 0;
        }
        status >>= 1;
    }
}
#endif /* __MTK_MMU__ */


/*************************************************************************
* FUNCTION
*  MPUSetting
*
* DESCRIPTION
*  This function used to initialization a cache region.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  This sub-routine takes care of the range alignment, also the least
*  protectable region.
*
* RETURNS
*
*************************************************************************/
#if defined(__MTK_MMU__)
#ifdef __MTK_TARGET__
__attribute__ ((section("INTSRAM_ROCODE")))
#endif /* __MTK_TARGET__ */
void MPUSetting(MPUMenuType *menu)
{
    kal_uint32 setting, range, index, size;
    kal_uint32 interruptMask;

    ASSERT(menu->m_channel < MPU_CHANNEL_NUM);
    ASSERT(menu->m_range <= MAX_MPU_CHANNEL_LEN);
    /* Look forward the least-fit range */
    index = MPU_SIZE_INDEX;
    size = MAX_MPU_CHANNEL_LEN;
    range = menu->m_range;
    while (range < size)
    {
        index--;
        size >>= 1;
        ASSERT(size >= MIN_MPU_CHANNEL_LEN);
    }

    range = (RegionSize)(index);
    setting = (menu->m_addr & 0xfffff000) | menu->m_attribute;
    if (menu->m_cacheable)
    {
        setting |= 0x00000100;
    }

    interruptMask = SaveAndSetIRQMask();
    *(MPU_PROT0 + menu->m_channel) = setting;
    *(MPU_PROT0_END+menu->m_channel) = menu->m_addr + menu->m_range;
    *MPU_CHANNEL_EN |= 1 << menu->m_channel;
    *CACHE_CON |= 0x02;
    RestoreIRQMask(interruptMask);
}
#endif /* __MTK_MMU__ */


/*************************************************************************
* FUNCTION
*  MPUClearAllSetting
*
* DESCRIPTION
*  This function used to initialization a cache region.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  This sub-routine takes care of the range alignment, also the least
*  protectable region.
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_MMU__)
#ifdef __MTK_TARGET__
__attribute__ ((section("INTSRAM_ROCODE")))
#endif /* __MTK_TARGET__ */
void MPUClearAllSetting(void)
{
    kal_uint32 status, index;

    *CACHE_CON &= ~(0x02);
    status = CodeCacheChannelStatus;
    for (index = 0; index < MPU_CHANNEL_NUM; index++)
    {
        if (status & 0x01)
        {
            *(MPU_PROT0 + index) = 0xc0;
        }
        status >>= 1;
    }
}
#endif /* __MTK_MMU__ */

/*************************************************************************
* FUNCTION
*  CacheAccessHitCount
*
* DESCRIPTION
*  Return the hit count on code cache, the first 4 regions are collected on
*  group 1, while others at group 2.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_MMU__)
#ifdef __MTK_TARGET__
__attribute__ ((section("INTSRAM_ROCODE")))
#endif /* __MTK_TARGET__ */
void CacheAccessHitCount(CodeCacheHitCount *ret)
{
    ret->hitCount1 = *(volatile kal_uint64*)(CACHE_HCNT0L);
    ret->accessCount1 = *(volatile kal_uint64*)(CACHE_CCNT0L);

    ret->hitCount2 = *(volatile kal_uint64*)(CACHE_HCNT1L);
    ret->accessCount2 = *(volatile kal_uint64*)(CACHE_CCNT1L);
}
#endif /* __MTK_MMU__ */

/*************************************************************************
* FUNCTION
*  SetupRemap
*
* DESCRIPTION
*  This function used to configure the Remap by Segment input
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*    start_addr
*    end_addr
*    total_size
*
* RETURNS
*
*************************************************************************/
#if defined(__MTK_MMU__)
static void SetupRemap(kal_uint32 phy_addr, kal_uint32 virt_addr, kal_uint32 total_size)
{
    kal_uint32 range, index;
    kal_uint32 channel_idx = 0;
    kal_uint32 size;

    while (total_size > 0)
    {
        /* try to find a max-fit size */
        for (size = MIN_MPU_CHANNEL_LEN; size <= MAX_MPU_CHANNEL_LEN; size <<= 1)
        {
            /* check if the start address is aligned to the size */
            if (phy_addr & (size - 1))
            {
                /* not aligned */

                /* revert to the previous size */
                size >>= 1;

                break;
            }

            /* check if size best hit */
            if (size == total_size)
            {
                break;
            }

            /* Now determine if coverage premitted or not */
            if (size > total_size)
            {
                ASSERT(0);
            }

            /* exit when reach max size */
            if (size == MAX_MPU_CHANNEL_LEN)
            {
                break;
            }
        } /* for ( size = MIN_MPU_CHANNEL_LEN ... MAX_MPU_CHANNEL_LEN ) */

        /* Look forward the least-fit range */
        index = MPU_SIZE_INDEX;
        range = size;
        size = MAX_MPU_CHANNEL_LEN;
        while (range < size)
        {
            index--;
            size >>= 1;
            ASSERT(size >= MIN_MPU_CHANNEL_LEN);
        }
        range = (RegionSize)((index) << 1);

        /* specify the start address of MPU setting */
        *(NCREMAP_LO0 + (channel_idx << 1)) = phy_addr;
        *(NCREMAP_HI0 + (channel_idx << 1)) = virt_addr | range | 1;
        channel_idx++;
        if (channel_idx >= REMAP_CHANNEL_NUM)
        {
            ASSERT(0);
        }

        /* move start_addr to the next address */
        virt_addr += size;
        phy_addr += size;

        /* calculate the remaining size of the remaining part */
        if (size >= total_size)
        {
            /* no remaining part */

            total_size = 0;
        }
        else
        {
            total_size -= size;
        }
    }
}
#endif /* __MTK_MMU__ */

/*************************************************************************
* FUNCTION
*  SetupMPUCacheByROMSegment
*
* DESCRIPTION
*  This function used to configure the MPU and Cache by Segment input
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*    start_addr
*    end_addr
*    total_size
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_MMU__)
static kal_uint32 SetupMPUCacheByROMSegment(kal_uint32 start_addr, kal_uint32 end_addr, kal_uint32 total_size, MPU_ATTRIBUTE mpu_attr, kal_uint32 cacheable)
{
    MPUMenuType MPUsetting;
    kal_uint32 size;
    kal_bool retval;
    kal_uint32 mpu_end_addr = 0;

    /* specify the attribute of MPU setting */
    MPUsetting.m_attribute = mpu_attr;

    /* specify the cacheability of MPU setting */
    if (PAGE_CACHEABLE == cacheable)
    {
        MPUsetting.m_cacheable = 1;
    }
    else
    {
        MPUsetting.m_cacheable = 0;
    }

    /* specify enable flag of MPU setting */
    MPUsetting.m_enable = 1;

    /* check start address align to MIN_MPU_CHANNEL_LEN */
    ASSERT((start_addr & (MIN_MPU_CHANNEL_LEN - 1)) == 0x0);

    /* check end address & start address + total_size */
    ASSERT(start_addr + total_size <= end_addr);

    /* Check start address 4KB align */
    ASSERT((start_addr & CACHE_CH_SIZE_4KB_MASK)==0);


    /* specify the start address of MPU setting */
    MPUsetting.m_addr = start_addr;
    
    /* specify the range of MPU setting */
    MPUsetting.m_range = total_size;
    
    /* update the end address of MPU coverage */
    mpu_end_addr = start_addr + total_size;
    
    /* Round-up 4KB for end address */
    ROUNDUP_4KB(mpu_end_addr);
    ASSERT(mpu_end_addr<=end_addr);
    MPUsetting.m_range = mpu_end_addr - MPUsetting.m_addr;
    
    /* get a MPU cahnnel */
    retval = MPUGetChannel(&MPUsetting.m_channel);
    
    /* ensure that a channel is available */
    ASSERT(retval == KAL_TRUE);
    
    /* configure the MPU */
    MPUSetting(&MPUsetting);


    return mpu_end_addr;
}

#endif /* __MTK_MMU__ */

/*************************************************************************
* FUNCTION
*  SetupMPUCacheByFeature
*
* DESCRIPTION
*  This function used to configure the CACHE by Segment input
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#if !defined(__FUE__) && !defined(__UBL__)
#if defined(__MTK_MMU__)
static void SetupMPUCacheByFeature(void)
{
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
    /*
     * Configure RAM code for single bank support as READABLE_BUT_NON_WRITEABLE.
     */
   {
      kal_uint32 endAddress = custom_get_SINGLEBANKCODE_End();
#if defined(__ALICE_SUPPORT__)
      endAddress = custom_get_EXTSRAM_ALICE_End();
#endif /* __ALICE_SUPPORT__ */
      SetupMPUCacheByROMSegment(0, endAddress, endAddress, PRIV_RO_USER_RO, PAGE_CACHEABLE);
   }
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
}
#endif /* __MTK_MMU__ */
#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  clean_l1cache
*
* DESCRIPTION
*  This function clean the buffer's data in L1Cache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr     -   address of the buffer
*  len      -   length of the buffer (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
#if defined(__MTK_MMU__) || defined(__MTK_MMU_V2__)

kal_int32 clean_l1cache(kal_uint32 addr, kal_uint32 len)
{
    kal_uint32 i = 0;

    /* NoteXXX: Each cache line in MTK L1 Cache is 32B. Every invalidate operation must aligned in a 32B address. */
    if ((addr & CPU_CACHE_LINE_SIZE_MASK) ||
        (len & CPU_CACHE_LINE_SIZE_MASK))
    {
        EXT_ASSERT(0, addr, len, 0);
    }
    else
    {
        for (i = 0; i < len / CPU_CACHE_LINE_SIZE; i++)
        {
            CleanCodeCacheByAlignedAddr(addr);
            addr += CPU_CACHE_LINE_SIZE;
        }
    }

    return 0;
}
#endif /* __MTK_MMU__ || __ MTK_MMU_V2__ */

/*************************************************************************
* FUNCTION
*  invalidate_l1cache
*
* DESCRIPTION
*  This function invalidates the buffer's data in L1Cache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr     -   address of the buffer
*  len      -   length of the buffer (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
#if defined(__MTK_MMU__) || defined(__MTK_MMU_V2__)
kal_int32 invalidate_l1cache(kal_uint32 addr, kal_uint32 len)
{
    kal_uint32 i = 0;

    /* NoteXXX: Each cache line in MTK L1 Cache is 32B. Every invalidate operation must aligned in a 32B address. */
    if ((addr & CPU_CACHE_LINE_SIZE_MASK) ||
        (len & CPU_CACHE_LINE_SIZE_MASK))
    {
        EXT_ASSERT(0, addr, len, 0);
    }
    else
    {
        for (i = 0; i < len / CPU_CACHE_LINE_SIZE; i++)
        {
            InvalidCodeCacheByAlignedAddr(addr);
            addr += CPU_CACHE_LINE_SIZE;
        }
    }

    return 0;
}
#endif /* __MTK_MMU__ || __MTK_MMU_V2__ */

/*************************************************************************
* FUNCTION
*  is_predef_dyna_c_region
*
* DESCRIPTION
*  This is used to determine whether the input region is a predefined dynamic switchable buffer.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  0
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
IS_PREDEF_DYNA_C_REGION_PLACEMENT
kal_uint32 is_predef_dyna_c_region(kal_uint32 vaddr, kal_uint32 len)
{
    kal_uint32 ret = 0;

    EXTSRAM_REGION_INFO_T *regionp;
    kal_uint32 buf_addr;
    kal_int32 buf_len;
    kal_uint32 i;
    kal_uint32 buf_start;

    for (i = 0; i < 2; i++)
    {
        if (i % 2 == 0)
        {
            vaddr = MAP2CREGPA(vaddr);
        }
        else
        {
            vaddr = MAP2CREGVA(vaddr);
        }

        custom_query_dynamic_cached_extsram_default_nc_region(&regionp);

        while (regionp->addr != 0 || regionp->len != 0)
        {
            if (regionp->len == 0)
            {
                regionp++;
                continue;
            }
            buf_start = regionp->addr;
            buf_addr = buf_start + regionp->len;
            buf_len = buf_addr - buf_start;

            if ((vaddr >= buf_start) &&
                (vaddr <= buf_start + buf_len))
            {
                ret = 1;
                return ret;
            }

            regionp++;
        }

        custom_query_dynamic_cached_extsram_default_c_region(&regionp);

        while (regionp->addr != 0 || regionp->len != 0)
        {
            if (regionp->len == 0)
            {
                regionp++;
                continue;
            }
            buf_start = regionp->addr;
            buf_addr = buf_start + regionp->len;
            buf_len = buf_addr - buf_start;

            if ((vaddr >= buf_start) &&
                (vaddr <= buf_start + buf_len))
            {
                ret = 1;
                return ret;
            }

            regionp++;
        }
    }

#if !defined(__MTK_MMU__)
    if (INT_QueryIsSysRAM(vaddr))
    {
        ret = 1;
        return ret;
    }
#endif /* __MTK_MMU__ */

    return ret;
}
#endif  /* __DYNAMIC_SWITCH_CACHEABILITY__ */
#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  dynamic_switch_cacheable_region
*
* DESCRIPTION
*  This is used to dynamically change a region's cacheable/noncacheable attribute.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  vaddr
*  len
*  cacheable
*
* RETURNS
*  0 for successfully switch.
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)
DYNAMIC_SWITCH_CACHEABLE_REGION_PLACEMENT
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
kal_uint32 dynamic_switch_cacheable_region(void *vaddr, kal_uint32 len, kal_uint32 cacheable)
{
    kal_uint32 c;
    kal_uint32 ret = 0;
    kal_uint32 is_sysram = 0;
    kal_uint32 op_addr;

    op_addr = (kal_uint32)(*(kal_uint32*)vaddr);
#if !defined(__MTK_MMU__)
    is_sysram = INT_QueryIsSysRAM(op_addr);
#endif /* __MTK_MMU__ */

    if (!is_predef_dyna_c_region(op_addr, len) ||
        !IS_CACHE_LINE_SIZE_ALIGNED(*(kal_uint32*)vaddr) ||
        !IS_CACHE_LINE_SIZE_ALIGNED(len))
    {
        ASSERT(0);
    }

    is_sysram == 0 ? (c = INT_QueryIsCachedRAM(op_addr, len)) : (c = INT_QueryIsCachedSysRAM(op_addr, len));

    if (c == cacheable)
    {
        return ret;
    }

#if !defined(__MTK_MMU__) && !defined(__MTK_MMU_V2__)
    if (PAGE_CACHEABLE == cacheable)
    {
        is_sysram == 0 ? (*(kal_uint32*)vaddr = MAP2CREGVA(*(kal_uint32*)vaddr)) : (*(kal_uint32*)vaddr = MAP2CREGVA_SYS(*(kal_uint32*)vaddr));
        is_sysram == 0 ? (op_addr = MAP2CREGVA(op_addr)) : (op_addr = MAP2CREGVA_SYS(op_addr));
        invalidate_dcache(op_addr, len);
        cp15_drain_write_buffer();
    }
    else if (PAGE_NO_CACHE == cacheable)
    {
        clean_dcache(op_addr, len);
        is_sysram == 0 ? (*(kal_uint32*)vaddr = MAP2CREGPA(*(kal_uint32*)vaddr)) : (*(kal_uint32*)vaddr = MAP2CREGPA_SYS(*(kal_uint32*)vaddr));
        cp15_drain_write_buffer();
    }
    else
    {
        ASSERT(0);
    }
#else
    if (PAGE_CACHEABLE == cacheable)
    {
        if (is_sysram == 0)
        {
            *(kal_uint32*)vaddr = MAP2CREGVA(*(kal_uint32*)vaddr);
            op_addr = MAP2CREGVA(op_addr);
        }
        else
        {
            ASSERT(0);
        }
        invalidate_dcache(op_addr, len);
    }
    else if (PAGE_NO_CACHE == cacheable)
    {
        clean_dcache(op_addr, len);
        if (is_sysram == 0)
        {
            *(kal_uint32*)vaddr = MAP2CREGPA(*(kal_uint32*)vaddr);
        }
        else
        {
            ASSERT(0);
        }
    }
    else
    {
        ASSERT(0);
    }
#endif /* __MTK_MMU__ && __MTK_MMU_V2__ */

    return ret;
}

#endif  /* __DYNAMIC_SWITCH_CACHEABILITY__ */

#endif /* !__FUE__ && !__UBL__ */


/*************************************************************************
* FUNCTION
*  CachePreInit
*
* DESCRIPTION
*  This function used to pre-configure the overall cache setting to use I-cache for speeding up the following ops.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#if !defined(__FUE__) && !defined(__UBL__)
void CachePreInit(void)
{
#if defined(__MTK_MMU__)
    /* setup MTK remap to map 0xFxxxxxxx to physical memory */
    SetupRemap(0x0, MAP2CREGVA(0x0), EMI_EXTSRAM_SIZE);

    *MPU_PROT0 = 0x100 | (custom_get_1st_ROM_ROMBase() & 0xF8000000); /* 2MB from 0x0 */
    *MPU_PROT0_END = ((custom_get_1st_ROM_ROMBase()& 0xF8000000) + SIZE_4KB)&(~CACHE_CH_SIZE_4KB_MASK);

    *MPU_CHANNEL_EN |= 1;
#endif /* __MTK_MMU__ */
    return;
}
#endif /* !__FUE__ && !__UBL__ */


/*************************************************************************
* FUNCTION
*  CustomizedCacheDeInit
*
* DESCRIPTION
*  This function used to clear the customized cache setting. Note that this function will not take care of MMU part.
*  For MMU customization, pease use customized_mmu_deinit().
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#if defined(__MTK_MMU__)
#ifdef __MTK_TARGET__
__attribute__ ((section("INTSRAM_ROCODE")))
#endif /* __MTK_TARGET__ */
void CustomizedCacheDeInit(void)
{
    /* Inv code cache */
    MTKL1CACHE_InvalidAllCacheLines();
    /* disable code cache. */
    CodeCacheClearAllSetting();
    /* disable code mpu. */
    MPUClearAllSetting();
}
#endif // __MTK_MMU__

/*************************************************************************
* FUNCTION
*  CustomizedCacheInit
*
* DESCRIPTION
*  This function used to configure the customized cache setting. Note that this function will not take care of MMU part.
*  For MMU customization, pease use customized_mmu_init().
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#if defined(__MTK_MMU__)
void CustomizedCacheInit(kal_uint32 rom_start_addr, kal_uint32 rom_end_addr, kal_uint32 rom_len)
{
    /*
     * MPU configuration.
     * Configure the region of code and RO as READABLE_BUT_NON_WRITEABLE.
     */
    SetupMPUCachebyROMSegment(rom_start_addr, rom_end_addr, rom_len);

    /* enable code cache */
    CodeCacheConfig(CACHE_4WAY, KAL_TRUE);
}
#endif // __MTK_MMU__

/*************************************************************************
* FUNCTION
*  CacheInit
*
* DESCRIPTION
*  This function used to configure the overall cache setting.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)
void CacheInit(void)
{
/*********************************
  *
  * MTK Cache
  *
  ********************************/
#if defined(__MTK_MMU__)
    kal_uint32 mpu_end_addr;
    kal_uint32 rom_start_addr = custom_get_1st_ROM_ROMBase();
    /* Ken: bootloader should be considered */
    kal_uint32 rom_end_addr = rom_start_addr + custom_get_NORFLASH_ROMSpace();
    kal_uint32 rom_len = (custom_get_1st_ROM_ROMBase() & ~0xf8000000) + custom_get_1st_ROM_ROMLength();

    print_bootup_trace(SST_INIT_L1CACHE_ENTER);

    /* make the EXTSRAM info table */
    custom_mk_ram_info();

    /*
     * MPU configuration.
     * Configure the region of code and RO as READABLE_BUT_NON_WRITEABLE and cacheable.
     */
    mpu_end_addr = SetupMPUCacheByROMSegment(rom_start_addr, rom_end_addr, rom_len, PRIV_RO_USER_RO, PAGE_CACHEABLE);
    SetupMPUCacheByROMSegment(MAP2CREGVA(RAM_BASE_ADDR), MAP2CREGVA(RAM_BASE_ADDR) + EMI_EXTSRAM_SIZE, EMI_EXTSRAM_SIZE, PRIV_RW_USER_RO, PAGE_CACHEABLE);
#if defined(__ALICE_SUPPORT__)
   {
      kal_uint32 alice_start_addr = custom_get_ALICE_Base();
      kal_uint32 alice_length = custom_get_ALICE_Length();
      kal_uint32 alice_end_addr = alice_start_addr + alice_length;

      alice_start_addr = alice_start_addr & ~((kal_uint32)(0x1000 - 1)); /* Round down */
      alice_end_addr = (alice_end_addr + (0x1000 - 1)) & ~((kal_uint32)(0x1000 - 1)); /* Round up */
      alice_length = alice_end_addr - alice_start_addr; /* Get the length after rounding */

      SetupMPUCacheByROMSegment(alice_start_addr, alice_end_addr, alice_length, PRIV_RO_USER_RO, PAGE_CACHEABLE);
   }
#endif /* __ALICE_SUPPORT__ */


    /*
     * Ken: verify the coverage of MPU/cache channels on ROM
     *      Note that here is an assumption that the coverage of
     *      MPU and cache channel on ROM are the same
     */
    ASSERT((rom_start_addr + rom_len) <= mpu_end_addr && mpu_end_addr <= rom_end_addr);

    SetupMPUCacheByFeature();

    CodeCacheConfig(CACHE_4WAY, KAL_TRUE);

    print_bootup_trace(SST_INIT_L1CACHE_EXIT);
#endif   /* __MTK_MMU__ */



/*********************************
  *
  * ARM9 L1 Cache / MMU Config
  *
  ********************************/

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
    {
        kal_uint32 cache_type;
        kal_uint32 cache_size;

        cache_type = cp15_read_cache_type();

#if defined(__ARM9_MMU__)
        cache_type = ((cache_type << 8) >> 26) - 3;
#elif defined(__ARM11_MMU__)
        cache_type = ((cache_type << 10) >> 28) - 3;
#else
    #error
#endif
        cache_size = 4096;
        while (cache_type--)
        {
            cache_size <<= 1;
        }
        cache_line_nr = cache_size / CPU_CACHE_LINE_SIZE;
        cache_line_nr_per_way = cache_line_nr / 4;
    }

    print_bootup_trace(SST_INIT_MMU_ENTER);
    MMU_Init();
    print_bootup_trace(SST_INIT_MMU_EXIT);
#endif  /* __ARM9_MMU__ || __ARM11_MMU__ */

/*********************************
  *
  * CR4 MPU config
  *
  ********************************/
#if defined(__CR4__)
    {
        kal_uint32 cache_type;
        kal_uint32 way_count;
        
        cache_type = cp15_read_dcache_info();
        cache_line_nr_per_way = ((cache_type<<4)>>17) + 1;
        way_count = ((cache_type<<19)>>22) + 1;
        cache_line_nr = cache_line_nr_per_way*way_count;
    }
    print_bootup_trace_enter(SST_INIT_MPU);
    custom_mk_ram_info(); //mk-ram_info for dynamic cacheability switch
    MPU_Init();
    print_bootup_trace_exit(SST_INIT_MPU);
#endif /* __CR4__ */

/*********************************
  *
  * MTK CACHE V2 MPU config
  *
  ********************************/
#if defined(__MTK_MMU_V2__)
    custom_mk_ram_info(); //mk-ram_info for dynamic cacheability switch
    MPU_Init();      
#endif /* __MTK_MMU_V2__ */

}

#endif /* !__FUE__ && !__UBL__ */


/*************************************************************************
* FUNCTION
*  meut_init_cache
*
* DESCRIPTION
*  This function initializes cache for MEUT.
*
* PARAMETERS
*  None
*
* RETURNS
*  0 for success; -1 for failure
*************************************************************************/

#if defined(__MEUT__)

kal_int32 meut_init_cache(void)
{
    CacheInit();

    return 0;
}

#endif  /* __MEUT__ */


/*************************************************************************
* FUNCTION
*  CacheInitBalancedMAUI
*
* DESCRIPTION
*  This function used to configure the overall cache setting.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)

#if defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__)

void CacheInitSecondaryMAUI(void)
{
/*********************************
  *
  * ARM9 L1 Cache / MMU Config
  *
  ********************************/

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
    MMU_InitSecondaryMAUI();
#endif  /* __ARM9_MMU__ || __ARM11_MMU__ */
}

#endif /* _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ || __EMMC_BOOTING__ */

#endif /* !__FUE__ && !__UBL__ */
#endif /* __MTK_TARGET__ */

/*************************************************************************
* FUNCTION
*  query_opposite_switchable_cacheaddr_ram
*
* DESCRIPTION
*  This function used to query the opposite cache-switchable address
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
#if !defined(__FUE__) && !defined(__UBL__)
kal_uint32 query_opposite_switchable_cacheaddr_ram(kal_uint32 addr)
{
#if (defined(__ARM9_MMU__) || defined(__DYNAMIC_SWITCH_CACHEABILITY__)) && defined(__MTK_TARGET__)
    EXTSRAM_REGION_INFO_T *regionp;
    kal_uint32 buf_start;
    kal_uint32 buf_addr;

    custom_query_dynamic_cached_extsram_default_nc_region(&regionp);
    while (regionp->addr != 0 || regionp->len != 0)
    {
        if (regionp->len == 0)
        {
            regionp++;
            continue;
        }
        buf_start = regionp->addr;
        buf_addr = regionp->addr + regionp->len;
        if ((addr >= buf_start) &&
            (addr <= buf_addr))
        {
            return MAP2CREGVA(addr);
        }
        if ((addr >= MAP2CREGVA(buf_start)) &&
            (addr <= MAP2CREGVA(buf_addr)))
        {
            return MAP2CREGPA(addr);
        }

        regionp++;
    }

    custom_query_dynamic_cached_extsram_default_c_region(&regionp);
    while (regionp->addr != 0 || regionp->len != 0)
    {
        if (regionp->len == 0)
        {
            regionp++;
            continue;
        }
        buf_start = regionp->addr;
        buf_addr = regionp->addr + regionp->len;
        if ((addr >= buf_start) &&
            (addr <= buf_addr))
        {
            return MAP2CREGPA(addr);
        }
        if ((addr >= MAP2CREGPA(buf_start)) &&
            (addr <= MAP2CREGPA(buf_addr)))
        {
            return MAP2CREGVA(addr);
        }

        regionp++;
    }

#if !defined(__MTK_MMU__)
    if (INT_QueryIsSysRAM(addr))
    {
        if (INT_QueryIsCachedSysRAM(addr, 0x4))
        {
            return MAP2CREGPA_SYS(addr);
        }

        return MAP2CREGVA_SYS(addr);
    }
#endif /* __MTK_MMU__ */

    /* assert if the input address is not cache-switchable */
    ASSERT(0);
#endif  /* (__ARM9_MMU__ || __DYNAMIC_SWITCH_CACHEABILITY__) && __MTK_TARGET__ */

    return addr;
}

#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  virt_to_phys
*
* DESCRIPTION
*  This function used to query the physical address of a virtual address
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

#if !defined(__FUE__) && !defined(__UBL__)

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
kal_uint32 virt_to_phys(void * address)
#if defined(__MTK_TARGET__)
{
    kal_uint32 retval = 0;
    kal_uint32 is_sysram = 0;

#if !defined(__MTK_MMU__)
    is_sysram = INT_QueryIsSysRAM(address);
#endif /* __MTK_MMU__ */

#if !defined(__MTK_MMU__)
    if (is_sysram == 0)
    {
        retval = MAP2CREGPA(address);
    }
    else
    {
        retval = MAP2CREGPA_SYS(address);
    }
#else
    if (is_sysram == 0)
    {
        retval = MAP2CREGPA(address);
    }
    else
    {
        ASSERT(0);
    }
#endif /* __MTK_MMU__ */

    return retval;
}
#else /* __MTK_TARGET__ */
{
    return 0;
}
#endif /* __MTK_TARGET__ */

#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ */

#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  phys_to_virt
*
* DESCRIPTION
*  This function used to query the physical address of a virtual address
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

#if !defined(__FUE__) && !defined(__UBL__)

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
kal_uint32 phys_to_virt(void * address)
#if defined(__MTK_TARGET__)
{
    kal_uint32 retval = 0;
    kal_uint32 is_sysram = 0;

#if !defined(__MTK_MMU__)
    is_sysram = INT_QueryIsSysRAM(address);
#endif /* __MTK_MMU__ */

#if !defined(__MTK_MMU__)
    if (is_sysram == 0)
    {
        retval = MAP2CREGVA(address);
    }
    else
    {
        retval = MAP2CREGVA_SYS(address);
    }
#else
    if (is_sysram == 0)
    {
        retval = MAP2CREGVA(address);
    }
    else
    {
        ASSERT(0);
    }
#endif /* __MTK_MMU__ */

    return retval;
}
#else /* __MTK_TARGET__ */
{
    return 0;
}
#endif /* __MTK_TARGET__ */

#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ */

#endif /* !__FUE__ && !__UBL__ */

#if !defined(__FUE__) && !defined(__UBL__)
#if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
void *map_back_memregion(void *ptr, void *region)
{
    return (void*)MAP2CREGNEWA(ptr, region);
}

#endif /* __MTK_TARGET__ && __DYNAMIC_SWITCH_CACHEABILITY__ */
#endif /* !__FUE__ && !__UBL__ */

extern kal_bool query_is_non_cached_ram(kal_uint32 addr, kal_uint32 len);

/*************************************************************************
* FUNCTION
*  query_is_noncached_ram
*
* DESCRIPTION
*  This function used to query if the memory is non-cacheable.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory.
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_noncached_ram(kal_uint32 addr, kal_uint32 len)
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__MTK_MMU__) || ((defined(__CR4__) || defined(__MTK_MMU_V2__)) && !defined(__BANK0_BANK4_REMAP__)))
{
    return ((((kal_uint32)(addr) & CREG_OFFSET) ^ CREG_OFFSET) == CREG_OFFSET);
}
#elif defined(__MTK_TARGET__) && ((defined(__CR4__) || defined(__MTK_MMU_V2__)) && defined(__BANK0_BANK4_REMAP__)) /* __MTK_TARGET__ && (__ARM9_MMU__ || __ARM11_MMU__ || __MTK_MMU__ || ((__CR4__ || __MTK_MMU_V2__) && !__BANK0_BANK4_REMAP__)) */
{
    return ((((kal_uint32)(addr) & CREG_OFFSET) ^ CREG_OFFSET) == 0);
}
#else /* __MTK_TARGET__ && ((__CR4__ || __MTK_MMU_V2__) && MT6290) */
{
    return 1;
}
#endif /* !__MTK_TARGET__ || Others */

/*************************************************************************
* FUNCTION
*  query_is_cached_ram
*
* DESCRIPTION
*  This function used to query if the memory is cacheable.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory.
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_cached_ram(kal_uint32 addr, kal_uint32 len)
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__MTK_MMU__) || ((defined(__CR4__) || defined(__MTK_MMU_V2__)) && !defined(__BANK0_BANK4_REMAP__)))
{
    return ((((kal_uint32)(addr) & CREG_OFFSET) ^ CREG_OFFSET) == 0);
}
#elif defined(__MTK_TARGET__) && ((defined(__CR4__) || defined(__MTK_MMU_V2__)) && defined(__BANK0_BANK4_REMAP__)) /* __MTK_TARGET__ && (__ARM9_MMU__ || __ARM11_MMU__ || __MTK_MMU__) || ((__CR4__ || __MTK_MMU_V2__) && !__BANK0_BANK4_REMAP__)) */
{
    return ((((kal_uint32)(addr) & CREG_OFFSET) ^ CREG_OFFSET) != 0);
}
#else /* __MTK_TARGET__ && ((__CR4__ || __MTK_MMU_V2__) && MT6290) */
{
    return 0;
}
#endif /* !__MTK_TARGET__ || Others */

/*************************************************************************
* FUNCTION
*  query_is_noncached_sys_ram
*
* DESCRIPTION
*  This function used to query if the sys ram is non-cacheable.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory.
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_noncached_sys_ram(kal_uint32 addr, kal_uint32 len)
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__MTK_MMU__))
{
    return ((((kal_uint32)(addr) & CREG_SYS_OFFSET) ^ CREG_SYS_OFFSET) != 0);
}
#elif defined(__MTK_TARGET__) && (defined(__CR4__) || defined(__MTK_MMU_V2__)) /* __MTK_TARGET__ && (__ARM9_MMU__ || __ARM11_MMU__ || __MTK_MMU__) */
{
    return 0;
}
#else /* __MTK_TARGET__ && (__CR4__ || __MTK_MMU_V2__) */
{
    return 1;
}
#endif /* !__MTK_TARGET__ || Others */

/*************************************************************************
* FUNCTION
*  query_is_cached_sys_ram
*
* DESCRIPTION
*  This function used to query if the sys ram is cacheable.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory.
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_cached_sys_ram(kal_uint32 addr, kal_uint32 len)
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__MTK_MMU__))
{
    return((((kal_uint32)(addr) & CREG_SYS_OFFSET) ^ CREG_SYS_OFFSET) == 0);
}
#elif defined(__MTK_TARGET__) && (defined(__CR4__) || defined(__MTK_MMU_V2__)) /* __MTK_TARGET__ && (__ARM9_MMU__ || __ARM11_MMU__ || __MTK_MMU__) */
{
    return 0;
}
#else /* __MTK_TARGET__ && (__CR4__ || __MTK_MMU_V2__) */
{
    return 0;
}
#endif /* !__MTK_TARGET__ || Others */

/*************************************************************************
* FUNCTION
*  query_is_sys_ram
*
* DESCRIPTION
*  This function used to query if the memory is sys ram.
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
kal_int32 query_is_sys_ram(kal_uint32 addr)
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__MTK_MMU__) || defined(__CR4__))
#if defined(__MTK_MMU__) || defined(__CR4__) || defined(__MTK_MMU_V2__)
{
    return 0;
}
#else /* __MTK_MMU__ || __CR4__ || __MTK_MMU_V2__ */
{
    #if !defined(__EXT_BOOTLOADER__)
    return(((((kal_uint32)(addr) & CREG_SYS_OFFSET) ^ CREG_SYS_OFFSET) == 0) || ((((kal_uint32)(addr) & CREG_SYS_OFFSET) ^ custom_get_SysRam_Base()) == 0));
    #else /* __EXT_BOOTLOADER__ */
    return 0;
    #endif /* __EXT_BOOTLOADER__ */
}
#endif /* __ARM9_MMU__ || __ARM11_MMU__ */
#else /* __MTK_TARGET__ && (__ARM9_MMU__ || __ARM11_MMU__ || __MTK_MMU__ || __CR4__ || __MTK_MMU_V2__) */
{
    return 0;
}
#endif /* !__MTK_TARGET__ || Others */

/*************************************************************************
* FUNCTION
*  query_is_non_mtkl1cached_ram
*
* DESCRIPTION
*  This function used to query if the memory is MTKL1 cacheabled
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_non_mtkl1cached_ram(kal_uint32 addr, kal_uint32 len)
{
    return 1;
}

/*************************************************************************
* FUNCTION
*  query_is_mtkl1cached_ram
*
* DESCRIPTION
*  This function used to query if the memory is MTKL1 cacheabled
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_mtkl1cached_ram(kal_uint32 addr, kal_uint32 len)
{
    return 0;
}

/*************************************************************************
* FUNCTION
*  query_is_writethroughcached_ram
*
* DESCRIPTION
*  This function used to query if the memory is write through cacheable.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_writethroughcached_ram(kal_uint32 addr, kal_uint32 len)
{
    return 0;
}

/*************************************************************************
* FUNCTION
*  Cache_Driver_Sanity_Test
*
* DESCRIPTION
*  This function test the correctness of each Cache Driver API for new chips
*  It is designed to be run after CacheInit()
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*  0: success
*  1: fail
*
*************************************************************************/
/*************************************************************************
 * !!!WARNING!!!
 * This function should NEVER be built in the official release 
 *************************************************************************/
//#define SS_CDST
#if defined(SS_CDST)
/* Test Options */
#define ASSERT_ON_ERROR   0

/* Sysram Option */
#if defined(MT6280) && defined(MT6290) && defined(MT6595)
#define CDST_SYSRAM_PLATFORM 0
#else
#define CDST_SYSRAM_PLATFORM 1
#endif

/* Helper macro */
#define CDST_INIT() \
    do { \
        CDST_ret = 0; \
    } while(0)
    
#define CDST_PASS(c) \
    do { \
        if(CDST_TEST_RESULT.c==WAIT) \
        { \
            CDST_TEST_RESULT.c=PASS; \
        } \
    } while(0)
    
#if ASSERT_ON_ERROR
#define CDST_FAIL(c) \
    do { \
        CDST_TEST_RESULT.c=FAIL; \
        CDST_ret = 1; \
        ASSERT(0);  \
    } while(0)

#else /* ASSERT_ON_ERROR */
#define CDST_FAIL(c) \
    do { \
        CDST_TEST_RESULT.c=FAIL; \
        CDST_ret = 1; \
    } while(0)
    
#endif /* ASSERT_ON_ERROR */

typedef enum
{
    WAIT=0,
    PASS,
    FAIL,
    BYPASS
} CDST_CASE;

struct {
    CDST_CASE Address_Remapping;          /* Check 0xF -> 0x0 remapping */
    
    CDST_CASE Invalidate_DCache_Small;    /* Invalidate D-Cache size <= cache size */
    CDST_CASE Invalidate_DCache_Large;    /* Invalidate D-Cache size > cache size */
    CDST_CASE Clean_DCache_Small;         /* Clean D-Cache size <= cache size */
    CDST_CASE Clean_DCache_Large;         /* Clean D-Cache size > cache size */
    CDST_CASE Clean_Inv_DCache_Small;     /* Clean and invalidate D-Cache size <= cache size */
    CDST_CASE Clean_Inv_DCache_Large;     /* Clean and invalidate D-Cache size > cache size */
    
    CDST_CASE Predef_Cache_Region;        /* is_predef_dyna_c_region */
    CDST_CASE Dynamic_Cache_Switch;       /* dynamic_switch_cacheable_region */    
    CDST_CASE Virt_to_Phys_to_Virt;       /* virt_to_phys, phys_to_virt */
    
    CDST_CASE Query_is_Non_Cached_Ram;    /* INT_QueryIsNonCachedRAM */
    CDST_CASE Query_is_Cached_Ram;        /* INT_QueryIsCachedRAM */
    CDST_CASE Query_is_Non_Cached_SysRAM; /* INT_QueryIsNonCachedSysRAM */
    CDST_CASE Query_is_Cached_SysRAM;     /* INT_QueryIsCachedSysRAM */
    CDST_CASE Query_is_SysRAM;            /* INT_QueryIsSysRAM */
} CDST_TEST_RESULT={0};


#ifdef __MTK_TARGET__
__attribute__ ((section("DYNAMICCACHEABLEZI_NC"), zero_init))
#endif /* __MTK_TARGET__ */
__attribute__ ((aligned(32*1024))) kal_uint32 CDST_DCDNC_array[64*1024];


#ifdef __MTK_TARGET__
__attribute__ ((section("NONCACHEDZI"), zero_init))
#endif /* __MTK_TARGET__ */
kal_uint32 CDST_NC_Var;

kal_uint32 CDST_C_Var;

kal_uint32 CDST_ret=0;

kal_uint32 Cache_Driver_Sanity_Test(void)
{
    kal_uint32 idx;
    kal_uint32 *ptr;
    
    CDST_INIT();
    
/**************************************************************************
*   ADDRESS REMAPPING TEST
***************************************************************************/
    if((kal_uint32)CDST_DCDNC_array==MAP2CREGVA((kal_uint32)CDST_DCDNC_array))
    {
        CDST_FAIL(Address_Remapping);   // PA == VA abnormal
    }
    clean_and_invalidate_dcache(MAP2CREGVA((kal_uint32)CDST_DCDNC_array), cache_line_nr);
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    
    /* Fill PA region with test pattern */
    for(idx=0;idx<cache_line_nr*32/4;idx++)
    {
        ptr[idx]=(kal_uint32)(ptr+idx);
    }
    
    /* Check VA and PA region read the same and correct test pattern */
    for(idx=0;idx<cache_line_nr*32/4;idx++)
    {
        if(*(kal_uint32*)MAP2CREGVA((kal_uint32)(CDST_DCDNC_array+idx))!=*(CDST_DCDNC_array+idx))
        {
              CDST_FAIL(Address_Remapping);
        }
        if(*(kal_uint32*)MAP2CREGVA((kal_uint32)(CDST_DCDNC_array+idx))!=(kal_uint32)(CDST_DCDNC_array+idx))
        {
              CDST_FAIL(Address_Remapping);
        }
    }
    CDST_PASS(Address_Remapping);

/**************************************************************************
*   DCache Operation Tests
***************************************************************************/
/* Invalidate DCache Small */
    /* Write VA with test pattern A */
    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<1024;idx++)
    {
        *(ptr+idx);
        *(ptr+idx)=0xDEADBEEF;
    }
    
    /* Invalidate VA DCache */
    invalidate_dcache((kal_uint32)ptr, 1024*4);
    
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    /* Write PA with test pattern B */
    for(idx=0;idx<1024;idx++)
    {
        *(ptr+idx)=(kal_uint32)(ptr+idx);
    }

    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    /* Read VA and the value should be test pattern B */
    for(idx=0;idx<1024;idx++)
    {
        if(*(ptr+idx)!=MAP2CREGPA(CDST_DCDNC_array+idx))
        {
              CDST_FAIL(Invalidate_DCache_Small);
        }          
    }
    CDST_PASS(Invalidate_DCache_Small);

/* Invalidate DCache Large */
    /* Write VA with test pattern A */
    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<64*1024;idx++)
    {
        *(ptr+idx);
        *(ptr+idx)=0xDEADBEEF;
    }
    
    /* Invalidate VA DCache */
    invalidate_dcache((kal_uint32)ptr, 64*1024*4);
    
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);    
    /* Read PA, it should be test pattern A, since large invalidate will do clean and invalidate */
    /* Write PA with test pattern B */
    for(idx=0;idx<64*1024;idx++)
    {
        if(*(ptr+idx)!=0xDEADBEEF)
        {
            CDST_FAIL(Invalidate_DCache_Large);
        }  
        *(ptr+idx)=(kal_uint32)(ptr+idx);
    }
    
    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    /* Read VA and the value should be test pattern B */
    for(idx=0;idx<64*1024;idx++)
    {
        if(*(ptr+idx)!=MAP2CREGPA(CDST_DCDNC_array+idx))
        {
              CDST_FAIL(Invalidate_DCache_Large);
        }          
    }
    CDST_PASS(Invalidate_DCache_Large);
    
/* Clean DCache Small */
    /* Write PA with test pattern A */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<1024;idx++)
    {
        *(ptr+idx)=0xDEADBEEF;
    }
    
    /* Write VA with test pattern B */
    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<1024;idx++)
    {
        *(ptr+idx);
        *(ptr+idx)=(kal_uint32)(ptr+idx);
    }
    
    /* Clean VA */
    clean_dcache((kal_uint32)ptr, 1024*4);
    
    /* Read PA and it should be test pattern B */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<1024;idx++)
    {
        if(*(ptr+idx)!=MAP2CREGVA(ptr+idx))
        {
            CDST_FAIL(Clean_DCache_Small);
        }
    }    
    CDST_PASS(Clean_DCache_Small);
    
/* Clean DCache Large */
    /* Write PA with test pattern A */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<64*1024;idx++)
    {
        *(ptr+idx)=0xDEADBEEF;
    }
    
    /* Write VA with test pattern B */
    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<64*1024;idx++)
    {
        *(ptr+idx);
        *(ptr+idx)=(kal_uint32)(ptr+idx);
    }
    
    /* Clean VA */
    clean_dcache((kal_uint32)ptr, 64*1024*4);
    
    /* Read PA and it should be test pattern B */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<64*1024;idx++)
    {
        if(*(ptr+idx)!=MAP2CREGVA(ptr+idx))
        {
            CDST_FAIL(Clean_DCache_Large);
        }
    }  
    CDST_PASS(Clean_DCache_Large);
    
/* Clean and Invalidate DCache Small */
    /* Write PA with test pattern A */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<1024;idx++)
    {
        *(ptr+idx)=0xDEADBEEF;
    }

    /* Write VA with test pattern B */
    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<1024;idx++)
    {
        *(ptr+idx);
        *(ptr+idx)=(kal_uint32)(ptr+idx);
    }
    
    /* Clean and invalidate VA */
    clean_and_invalidate_dcache((kal_uint32)ptr, 1024*4);    
    
    /* Read PA and it should be test pattern B */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<1024;idx++)
    {
        if(*(ptr+idx)!=MAP2CREGVA(ptr+idx))
        {
            CDST_FAIL(Clean_Inv_DCache_Small);
        }
    }    
    
    /* Write PA with test pattern A */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<1024;idx++)
    {
        *(ptr+idx)=0xDEADBEEF;
    }

    cp15_drain_write_buffer();

    /* Read VA and it should be test pattern A */
    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<1024;idx++)
    {
        if(*(ptr+idx)!=(kal_uint32)(0xDEADBEEF))
        {
            CDST_FAIL(Clean_Inv_DCache_Small);
        }
    }    
    CDST_PASS(Clean_Inv_DCache_Small);    

/* Clean and Invalidate DCache Large */
    /* Write PA with test pattern A */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<64*1024;idx++)
    {
        *(ptr+idx)=0xDEADBEEF;
    }
    
    /* Write VA with test pattern B */
    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<64*1024;idx++)
    {
        *(ptr+idx);
        *(ptr+idx)=(kal_uint32)(ptr+idx);
    }
    
    /* Clean and invalidate VA */
    clean_and_invalidate_dcache((kal_uint32)ptr, 64*1024*4);
    
    /* Read PA and it should be test pattern B */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<64*1024;idx++)
    {
        if(*(ptr+idx)!=MAP2CREGVA(ptr+idx))
        {
            CDST_FAIL(Clean_Inv_DCache_Large);
        }
    }    
    
    /* Write PA with test pattern A */
    ptr=(kal_uint32*)MAP2CREGPA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<64*1024;idx++)
    {
        *(ptr+idx)=0xDEADBEEF;
    }

    cp15_drain_write_buffer();

    /* Read VA and it should be test pattern A */
    ptr=(kal_uint32*)MAP2CREGVA((kal_uint32)CDST_DCDNC_array);
    for(idx=0;idx<64*1024;idx++)
    {
        if(*(ptr+idx)!=(kal_uint32)(0xDEADBEEF))
        {
            CDST_FAIL(Clean_Inv_DCache_Large);
        }
    }    
    CDST_PASS(Clean_Inv_DCache_Large);
    
/**************************************************************************
*   Dynamic Cacheablility APIs Test
***************************************************************************/
/* Predef_Cache_Region */
    /* Check Cached Ram symbol, it should not return 1 */
    if(is_predef_dyna_c_region((kal_uint32)(&CDST_C_Var), 4)==1)
    {
        CDST_FAIL(Predef_Cache_Region);
    }
    
    /* Check DCDNC symbol, it should not return 0 */
    if(is_predef_dyna_c_region((kal_uint32)(CDST_DCDNC_array), 4)==0)
    {
        CDST_FAIL(Predef_Cache_Region);
    }
    CDST_PASS(Predef_Cache_Region);
    
/* Dynamic_Cache_Switch */
    ptr=CDST_DCDNC_array;
    /* Fill NC with test pattern A */
    for(idx=0;idx<64*1024;idx++)
    {
        ptr[idx]=MAP2CREGPA(ptr+idx);
    }
       
    /* Switch to cacheable */
    dynamic_switch_cacheable_region(&ptr, 64*1024*4, PAGE_CACHEABLE);
    
    /* Read C and it should be test pattern A */
    /* Fill C with test pattern B */
    for(idx=0;idx<64*1024;idx++)
    {
        if(ptr[idx]!=MAP2CREGPA(ptr+idx))
        {
            CDST_FAIL(Dynamic_Cache_Switch);
        }
        ptr[idx]=MAP2CREGVA(ptr+idx);
    }

    /* Switch to non-cacheable */
    dynamic_switch_cacheable_region(&ptr, 64*1024*4, PAGE_NO_CACHE);

    /* Read NC and it should be test pattern B */    
    for(idx=0;idx<64*1024;idx++)
    {
        if(ptr[idx]!=MAP2CREGVA(ptr+idx))
        {
            CDST_FAIL(Dynamic_Cache_Switch);
        }
    }
    CDST_PASS(Dynamic_Cache_Switch);

/* Virt_to_Phys_to_Virt */
    if(virt_to_phys(CDST_DCDNC_array)!=MAP2CREGPA(CDST_DCDNC_array))
    {
        CDST_FAIL(Virt_to_Phys_to_Virt);
    }
    if(virt_to_phys(&CDST_NC_Var)!=MAP2CREGPA(&CDST_NC_Var))
    {
        CDST_FAIL(Virt_to_Phys_to_Virt);
    }
    if(virt_to_phys(&CDST_C_Var)!=MAP2CREGPA(&CDST_C_Var))
    {
        CDST_FAIL(Virt_to_Phys_to_Virt);
    }
    
    if(phys_to_virt(CDST_DCDNC_array)!=MAP2CREGVA(CDST_DCDNC_array))
    {
        CDST_FAIL(Virt_to_Phys_to_Virt);
    }
    if(phys_to_virt(&CDST_NC_Var)!=MAP2CREGVA(&CDST_NC_Var))
    {
        CDST_FAIL(Virt_to_Phys_to_Virt);
    }
    if(phys_to_virt(&CDST_C_Var)!=MAP2CREGVA(&CDST_C_Var))
    {
        CDST_FAIL(Virt_to_Phys_to_Virt);
    }
    CDST_PASS(Virt_to_Phys_to_Virt);

/**************************************************************************
*   Query APIs Test
***************************************************************************/
/* Query_is_Non_Cached_Ram */
    if(INT_QueryIsNonCachedRAM(&CDST_NC_Var, 4)!=1)
    {
        CDST_FAIL(Query_is_Non_Cached_Ram);  
    }
    if(INT_QueryIsNonCachedRAM(&CDST_C_Var, 4)!=0)
    {
        CDST_FAIL(Query_is_Non_Cached_Ram);  
    }
    CDST_PASS(Query_is_Non_Cached_Ram);  

/* Query_is_Cached_Ram */    
    if(INT_QueryIsCachedRAM(&CDST_NC_Var, 4)!=0)
    {
        CDST_FAIL(Query_is_Cached_Ram);  
    }
    if(INT_QueryIsCachedRAM(&CDST_C_Var, 4)!=1)
    {
        CDST_FAIL(Query_is_Cached_Ram);  
    }      
    CDST_PASS(Query_is_Cached_Ram);  

/* Sysram Related */
#if CDST_SYSRAM_PLATFORM
    /* TBD */
#else /* CDST_SYSRAM_PLATFORM */
/* Query_is_Non_Cached_SysRAM */
    if(INT_QueryIsNonCachedSysRAM(&CDST_NC_Var,4)!=0)
    {
        CDST_FAIL(Query_is_Non_Cached_SysRAM);
    }
    if(INT_QueryIsNonCachedSysRAM(&CDST_C_Var,4)!=0)
    {
        CDST_FAIL(Query_is_Non_Cached_SysRAM);
    }
    if(INT_QueryIsNonCachedSysRAM(CDST_DCDNC_array,4)!=0)
    {
        CDST_FAIL(Query_is_Non_Cached_SysRAM);
    }
    CDST_PASS(Query_is_Non_Cached_SysRAM);
    
/* Query_is_Cached_SysRAM */
    if(INT_QueryIsCachedSysRAM(&CDST_NC_Var,4)!=0)
    {
        CDST_FAIL(Query_is_Cached_SysRAM);
    }
    if(INT_QueryIsCachedSysRAM(&CDST_C_Var,4)!=0)
    {
        CDST_FAIL(Query_is_Cached_SysRAM);
    }
    if(INT_QueryIsCachedSysRAM(CDST_DCDNC_array,4)!=0)
    {
        CDST_FAIL(Query_is_Cached_SysRAM);
    }
    CDST_PASS(Query_is_Cached_SysRAM);
    
/* Query_is_SysRAM */
    if(INT_QueryIsSysRAM(&CDST_NC_Var)!=0)
    {
        CDST_FAIL(Query_is_SysRAM);
    }
    if(INT_QueryIsSysRAM(&CDST_C_Var)!=0)
    {
        CDST_FAIL(Query_is_SysRAM);
    }
    if(INT_QueryIsSysRAM(CDST_DCDNC_array)!=0)
    {
        CDST_FAIL(Query_is_SysRAM);
    }
    CDST_PASS(Query_is_SysRAM);
#endif 

    return CDST_ret;
}
#endif /* SS_CDST */
