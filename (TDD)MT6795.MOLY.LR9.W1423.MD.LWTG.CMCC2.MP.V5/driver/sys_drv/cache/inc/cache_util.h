/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   cache_util.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implement cache profile APIs
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*******************************************************************************
 * Data cache performance analysis macros 
 *******************************************************************************/
/*******************************************************************************
* NOTE:
*   Functions provided here are used for debug/profiling
*   Official releases should not include these codes
*
* FEATURES:
*   1. Cache pollution (1 ~ 4 ways)
*   2. Cache miss rate profiling
*
* REQUIREMENT:
*   1. All macros are not ready to use until CacheInit() is finished
*
* SUPPORT PLATFORM:
*   ARM7 series(MT6252 later)
*   ARM9 series
*   ARM11 series
*   CR4 series
*
* API SUMMARY:
*   CACHE_RESET()
*     Invalidate and clean all cache lines. Cache will be at initial state.
*
*   CACHE_POLLUTE(kal_uint32 way, void * buffer)
*     Make the specified number of ways cache lines dirty. 
*     !!NOTE!! This function Disables Interrupt and Enables before return
*     User must provide a cacheable buffer in order to perform the "pollute" operation, the size of buffer must be larger than data cache size
*     For now, all platforms DCache are 4-way cache.
*     You can  pollute all cache by CACHE_POLLUTE(4, buffer);
*              pollute 1/4 cache by CACHE_POLLUTE(1, buffer);
*              pollute 1/2 cache by CACHE_POLLUTE(2, buffer);
*              pollute 3/4 cache by CACHE_POLLUTE(3, buffer);
*
*   CACHE_PROFILE_INIT(CACHE_SEL select)
*     Platform dependent cache profile counter initialize sequence.
*     [ARM7 Platform]   This function is unecessary. Data and code cache shares one counter and cannot be selected.
*     [ARM9 Platform]   This function is unecessary. Data and code cache has seperate counter.
*     [ARM11 Platform]  This function is NECESSARY. Data and code cache shares one counter and must be selected bye this function.
*     [CR4 Platform]    This function is NECESSARY. Data and code cache shares one counter and must be selected bye this function.
*
*   CACHE_PROFILE_START()
*     Start collecting cache access and miss count     
*
*   CACHE_PROFILE_PAUSE()
*     Pause collecting cache access and miss count   
*
*   CACHE_PROFILE_RESET()
*     Reset cache access and miss count
*
*   CACHE_PROFILE_GET_RESULT(CACHE_PROFILE_T info)
*     Return current cache profile result
*
* SAMPLE CODE:
* [Cache pollution]
*   kal_uint32 cached_buffer[16 * 1024 / 4];    //Cacheable buffer for cache pollute operation
*   void cache_profile()
*   {
*     CACHE_RESET();                            //Cache reset: clean and invalidate all cache lines
*     CACHE_POLLUTE(4, cached_buffer);          //Make all cache lines dirty
*   }
*
* [Cache miss rate profile]
*   CACHE_PROFILE_T cache_info;
*   CACHE_PROFILE_INIT(DATA);                   //Select data cache counter
*   CACHE_PROFILE_RESET();                      //Clear counter  
*   CACHE_PROFILE_START();                      //Start monitoring cache behavior
*   (do something....)
*   CACHE_PROFILE_PAUSE();                      //Stop monitoring cache behavior
*   CACHE_PROFILE_GET_RESULT(&cache_info);      //Read back cache miss and access count
********************************************************************************/
#ifndef __CACHE_UTIL_H__
#define __CACHE_UTIL_H__
#include "cache_sw_int.h"
#include "cache_hw_int.h"
#include "mcu_pmu_montr.h"

#define CACHE_ANALYSIS
#if defined(CACHE_ANALYSIS)
/*******************************************************
* Constants
********************************************************/
//ARM9 Performance Monitor Register Base
//Currently, support MT6255, MT6236
#if defined(__ARM9_MMU__)
#if defined(MT6255) || defined(MT6236)
#define ARM_PERF_base             0x80000800
#else // MT6255 || MT6236
#error "Unkown ARM9 Platform, or does not have performance monitor HW"
#endif // MT6255 || MT6236

//Control Bits
#define ARM_PERF_DCMON_EN         0x00000001
#define ARM_PERF_ICMON_EN         0x00000002
#define ARM_PERF_DCMON_CLR        0x00008000
#define ARM_PERF_ICMON_CLR        0x00010000

//Control Registers
#define ARM_PERF_CON              ((volatile kal_uint32 *)(ARM_PERF_base+0x0000))
#define ARM_PERF_SET              ((volatile kal_uint32 *)(ARM_PERF_base+0x0004))
#define ARM_PERF_CLR              ((volatile kal_uint32 *)(ARM_PERF_base+0x0008))

//Counters
#define ARM_PERF_DCREAD_REQ       ((volatile kal_uint64 *)(ARM_PERF_base+0x000C))
#define ARM_PERF_DCREAD_REQ_L     ((volatile kal_uint32 *)(ARM_PERF_base+0x000C))
#define ARM_PERF_DCREAD_REQ_H     ((volatile kal_uint32 *)(ARM_PERF_base+0x0010))

#define ARM_PERF_DCWRITE_REQ      ((volatile kal_uint64 *)(ARM_PERF_base+0x0014))
#define ARM_PERF_DCWRITE_REQ_L    ((volatile kal_uint32 *)(ARM_PERF_base+0x0014))
#define ARM_PERF_DCWRITE_REQ_H    ((volatile kal_uint32 *)(ARM_PERF_base+0x0018))

#define ARM_PERF_DCREAD_MISS      ((volatile kal_uint64 *)(ARM_PERF_base+0x001C))
#define ARM_PERF_DCREAD_MISS_L    ((volatile kal_uint32 *)(ARM_PERF_base+0x001C))
#define ARM_PERF_DCREAD_MISS_H    ((volatile kal_uint32 *)(ARM_PERF_base+0x0020))

#define ARM_PERF_DCWRITE_MISS     ((volatile kal_uint64 *)(ARM_PERF_base+0x0024))
#define ARM_PERF_DCWRITE_MISS_L   ((volatile kal_uint32 *)(ARM_PERF_base+0x0024))
#define ARM_PERF_DCWRITE_MISS_H   ((volatile kal_uint32 *)(ARM_PERF_base+0x0028))

#define ARM_PERF_ICREAD_REQ       ((volatile kal_uint64 *)(ARM_PERF_base+0x002C))
#define ARM_PERF_ICREAD_REQ_L     ((volatile kal_uint32 *)(ARM_PERF_base+0x002C))
#define ARM_PERF_ICREAD_REQ_H     ((volatile kal_uint32 *)(ARM_PERF_base+0x0030))

#define ARM_PERF_ICREAD_MISS      ((volatile kal_uint64 *)(ARM_PERF_base+0x0034))
#define ARM_PERF_ICREAD_MISS_L    ((volatile kal_uint32 *)(ARM_PERF_base+0x0034))
#define ARM_PERF_ICREAD_MISS_H    ((volatile kal_uint32 *)(ARM_PERF_base+0x0038))

#elif defined(__ARM11_MMU__) //__ARM9_MMU__
#define ARM11_PMUEVNT_DCACHE_MISS           0xB
#define ARM11_PMUEVNT_DCACHE_ACES_C         0x9
                                            
#define ARM11_PMUEVNT_ICACHE_MISS           0x0
#define ARM11_PMUEVNT_INST_EXE              0x7
                                            
#define ARM11_PMUEVNT_CNT0_CFG_MASK         0xF00FFFFF
#define ARM11_PMUEVNT_CNT0_CFG_SHIFT        20
#define ARM11_PMUEVNT_CNT1_CFG_MASK         0xFFF00FFF
#define ARM11_PMUEVNT_CNT1_CFG_SHIFT        12

#define ARM11_PMUEVNT_EVNT01CNT_RESET_MASK  0xFFFFFFFD
#define ARM11_PMUEVNT_EVNT01CNT_RESET_SHIFT 1
#define ARM11_PMUEVNT_ALLCNT_EN_MASK        0xFFFFFFFE
#define ARM11_PMUEVNT_ALLCNT_EN_SHIFT       0

#elif defined(__CR4__) //__ARM11_MMU__

#elif defined(__MTK_MMU__) // __CR4__
#define MTK_CACHE_COUNT0_BIT                0x4
#define MTK_CACHE_COUNT1_BIT                0x8

#elif defined(__MTK_MMU_V2__) // __MTK_MMU__
#define ARM7CACHE_CON_CNT_EN                (1UL << 4)   // CNTEN
#define ARM7CACHE_CON_CNTR_RESET            (1UL << 5)   // CNTR_RESET
#define ARM7CACHE_CON_CYC_EN                (1UL << 8)   // CYC_EN
#define ARM7CACHE_CON_CYC_CNTR_RESET        (1UL << 9)   // CYC_CNTR_RESET

#endif // __MTK_MMU_V2__

//For CACHE_PROFILE on ARM11 and CR4, we can only monitor either DATA or INSTRUCTION cache at a time
//This enum is used to select which type of cache to be monitored at CACHE_PROFILE_INIT()
typedef enum {
    DATA,
    INSTRUCTION
} CACHE_SEL;

/*******************************************************
* Extern Function / Variables
********************************************************/
extern void cp15_set_idcache_replacement(kal_uint32);

extern kal_uint32 cp15_GetPerfMonitorControl(void);
extern void cp15_SetPerfMonitorControl(kal_uint32 cfg);
extern kal_uint32 cp15_GetCountRegister0(void);
extern kal_uint32 cp15_GetCountRegister1(void);

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__CR4__)
extern kal_uint32 cache_line_nr;
extern kal_uint32 cache_line_nr_per_way;
#define CACHE_LINE_NUM (cache_line_nr)
#define CACHE_LINE_NUM_PER_WAY (cache_line_nr_per_way)
#define CPU_CACHE_WAY_COUNT 4
#elif defined(__MTK_MMU__) || defined(__MTK_MMU_V2__)
#define CACHE_LINE_NUM ((32 * 1024) / 32)
#define CACHE_LINE_NUM_PER_WAY (CACHE_LINE_NUM / 4)
#define CPU_CACHE_WAY_COUNT 4
#endif
extern kal_uint16 L1_ASSERT_BYPASS;
/*******************************************************
* Data Structures
********************************************************/
#if defined(__ARM9_MMU__)
typedef struct {
    kal_uint64 ICache_Access_Count;
    kal_uint64 DCache_Access_Count;
    kal_uint64 ICache_Miss_Count;
    kal_uint64 DCache_Miss_Count;  
} CACHE_PROFILE_T; 
#elif defined(__ARM11_MMU__) || defined(__CR4__) // __ARM9_MMU__
typedef struct {
    kal_uint32 Cache_Access_Count;
    kal_uint32 Cache_Miss_Count; 
} CACHE_PROFILE_T; 
#elif defined(__MTK_MMU__) //__ARM11_MMU__ || __CR4__
typedef struct {
    kal_uint64 Cache_Access_Count;
    kal_uint64 Cache_Miss_Count; 
} CACHE_PROFILE_T; 
#elif defined(__MTK_MMU_V2__) //__MTK_MMU__
typedef struct {
    kal_uint32 Cache_Access_Count;
    kal_uint32 Cache_Miss_Count;
    kal_uint32 Cache_Hit_Count;
    kal_uint32 Cache_Wbk_Fill_Cycle_Count; // External memory Access Cycle Counts
    kal_uint32 Tcm_Access_Count;
} CACHE_PROFILE_T; 
#else // __MTK_MMU_V2__
#error "Unknown platform"
#endif // "Unknown platform"

/*******************************************************
* INTERNAL APIs: Directly use is not recommended
********************************************************/
/*******************************************************
* CACHE_DATA_SYNC - Internal
********************************************************/
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__CR4__)
#define CACHE_DATA_SYNC() cp15_drain_write_buffer()
#elif defined(__MTK_MMU__) || defined(__MTK_MMU_V2__) /* __ARM9_MMU__ || __ARM11_MMU__ || __CR4__ */
#define CACHE_DATA_SYNC() do{}while(0)
#endif /* __MTK_MMU__ || __MTK_MMU_V2__ */

/*******************************************************
* CACHE_CLEAN_INVALIDATE_DC_SETWAY - Internal
********************************************************/
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__CR4__)
#define CACHE_CLEAN_INVALIDATE_DC_SETWAY(set,way) cp15_clean_and_invalidate_dcache_by_setway((set),(way))
#elif defined(__MTK_MMU__) /* __ARM9_MMU__ || __ARM11_MMU__ || __CR4__ */
#define CACHE_CLEAN_INVALIDATE_DC_SETWAY(set,way) \
        do { \
            *CACHE_OP = (kal_uint32)(((set)<<5)|((1<<way)<<16)|0x00000019); \
            *CACHE_OP = (kal_uint32)(((set)<<5)|((1<<way)<<16)|0x00000009); \
        } while(0) 
            
#elif defined(__MTK_MMU_V2__) /* __MTK_MMU__ */
#define CACHE_CLEAN_INVALIDATE_DC_SETWAY(set,way) \
        do { \
            DRV_WriteReg32(ARM7CACHE_OPERATION_REG, (kal_uint32)((set<<5) | ((1<<way)<<16) | 0x00000019)); \
            DRV_WriteReg32(ARM7CACHE_OPERATION_REG, (kal_uint32)((set<<5) | ((1<<way)<<16) | 0x00000018)); \
            DRV_WriteReg32(ARM7CACHE_OPERATION_REG, (kal_uint32)((set<<5) | ((1<<way)<<16) | 0x00000009)); \
            DRV_WriteReg32(ARM7CACHE_OPERATION_REG, (kal_uint32)((set<<5) | ((1<<way)<<16) | 0x00000008)); \
        } while(0)

#endif /* __MTK_MMU_V2__ */

/*******************************************************
* CACHE_POLLUTE_CONFIG_SET - Internal
********************************************************/
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__) 
#define CACHE_POLLUTE_CONFIG_SET() cp15_set_idcache_replacement(1)
#else /* __ARM9_MMU__ || __ARM11_MMU__ */
#define CACHE_POLLUTE_CONFIG_SET() do {} while(0)
#endif  /* __ARM9_MMU__ || __ARM11_MMU__ */

/*******************************************************
* CACHE_POLLUTE_CONFIG_CLEAR - Internal
********************************************************/
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__) 
#define CACHE_POLLUTE_CONFIG_CLEAR() cp15_set_idcache_replacement(0)
#else  /* __ARM9_MMU__ || __ARM11_MMU__ */
#define CACHE_POLLUTE_CONFIG_CLEAR() do {} while(0)
#endif   /* __ARM9_MMU__ || __ARM11_MMU__ */

/*******************************************************
* PUBLIC APIs
********************************************************/
/*******************************************************
* CACHE_RESET() - Public
*   Make all cache invalidate (and clean)
********************************************************/
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__CR4__)
#define CACHE_RESET() \
        do { \
            cp15_clean_and_invalidate_all_dcache_by_setway(); \
            CACHE_DATA_SYNC(); \
        } while(0) 
        
#elif defined(__MTK_MMU__) || defined(__MTK_MMU_V2__) /* __ARM9_MMU__ || __ARM11_MMU__ || __CR4__ */
#define CACHE_RESET() \
        do { \
            MTKL1CACHE_CleanAllCacheLines(); \
            MTKL1CACHE_InvalidAllCacheLines(); \
        } while(0) 
        
#endif /* __MTK_MMU__ || __MTK_MMU_V2__ */

/*******************************************************
* CACHE_POLLUTE(kal_uint32 way, void * buffer) - Public
*   Make a number of ways of cache line dirty
*   Input:
*     way     -     Number of way to be set as dirty
*     buffer  -     User provided buffer, must in CACHEABLE region 
*                   and size larger than D-Cache
********************************************************/
#define CACHE_POLLUTE(way, buffer) \
        do { \
            volatile kal_uint32 * ptr; \
            kal_uint32 i,j,irq; \
            kal_uint16 l1_bypass; \
            ptr = (volatile kal_uint32 *)(buffer); \
            if (((kal_uint32)(way))==0) \
                break; \
            else if(((kal_uint32)(way))>CPU_CACHE_WAY_COUNT) \
                ASSERT(0); \
            CACHE_POLLUTE_CONFIG_SET(); \
            l1_bypass = L1_ASSERT_BYPASS; \
            L1_ASSERT_BYPASS = 0x0003; \
            irq = LockIRQ(); \
            CACHE_RESET(); \
            for(i=0;i<CACHE_LINE_NUM;i++) \
            { \
                ptr[i*8+0] = ptr[i*8+0]|0x5A5AA5A5; \
                ptr[i*8+1] = ptr[i*8+1]|0x5A5AA5A5; \
                ptr[i*8+2] = ptr[i*8+2]|0x5A5AA5A5; \
                ptr[i*8+3] = ptr[i*8+3]|0x5A5AA5A5; \
                ptr[i*8+4] = ptr[i*8+4]|0x5A5AA5A5; \
                ptr[i*8+5] = ptr[i*8+5]|0x5A5AA5A5; \
                ptr[i*8+6] = ptr[i*8+6]|0x5A5AA5A5; \
                ptr[i*8+7] = ptr[i*8+7]|0x5A5AA5A5; \
            } \
            for(i=0;i<(CPU_CACHE_WAY_COUNT-way);i++) \
            { \
              for(j=0;j<CACHE_LINE_NUM_PER_WAY;j++) \
              { \
                CACHE_CLEAN_INVALIDATE_DC_SETWAY(j,i); \
              } \
            } \
            CACHE_DATA_SYNC(); \
            RestoreIRQ(irq); \
            L1_ASSERT_BYPASS = l1_bypass; \
            CACHE_POLLUTE_CONFIG_CLEAR(); \
        } while(0) 
#if defined __CACHE_POLLUTE_FLEXIBLE__
/*******************************************************
* CACHE_POLLUTE3(kal_uint32 way, void * buffer, bool disable_irq) - Public
*   Make a number of ways of cache line dirty
*   Input:
*     way     -     Number of way to be set as dirty
*     buffer  -     User provided buffer, must in CACHEABLE region 
*                   and size larger than D-Cache
*     disable_irq -  To disable irq or not
********************************************************/
#define CACHE_POLLUTE3(way, buffer, disable_irq) \
        do { \
            volatile kal_uint32 * ptr; \
            kal_uint32 i,j,irq; \
            kal_uint16 l1_bypass; \
            ptr = (volatile kal_uint32 *)(buffer); \
            if (((kal_uint32)(way))==0) \
                break; \
            else if(((kal_uint32)(way))>CPU_CACHE_WAY_COUNT) \
                ASSERT(0); \
            CACHE_POLLUTE_CONFIG_SET(); \
            l1_bypass = L1_ASSERT_BYPASS; \
            L1_ASSERT_BYPASS = 0x0003; \
            if (disable_irq) \
                irq = LockIRQ(); \
            CACHE_RESET(); \
            for(i=0;i<CACHE_LINE_NUM;i++) \
            { \
                ptr[i*8+0] = ptr[i*8+0]|0x5A5AA5A5; \
                ptr[i*8+1] = ptr[i*8+1]|0x5A5AA5A5; \
                ptr[i*8+2] = ptr[i*8+2]|0x5A5AA5A5; \
                ptr[i*8+3] = ptr[i*8+3]|0x5A5AA5A5; \
                ptr[i*8+4] = ptr[i*8+4]|0x5A5AA5A5; \
                ptr[i*8+5] = ptr[i*8+5]|0x5A5AA5A5; \
                ptr[i*8+6] = ptr[i*8+6]|0x5A5AA5A5; \
                ptr[i*8+7] = ptr[i*8+7]|0x5A5AA5A5; \
            } \
            for(i=0;i<(CPU_CACHE_WAY_COUNT-way);i++) \
            { \
              for(j=0;j<CACHE_LINE_NUM_PER_WAY;j++) \
              { \
                CACHE_CLEAN_INVALIDATE_DC_SETWAY(j,i); \
              } \
            } \
            CACHE_DATA_SYNC(); \
            if (disable_irq) \
                RestoreIRQ(irq); \
            L1_ASSERT_BYPASS = l1_bypass; \
            CACHE_POLLUTE_CONFIG_CLEAR(); \
        } while(0) 
#endif
        
/*******************************************************
* CACHE_PROFILE_INIT(CACHE_SEL select) - Public
*   Initialize cache profile counter    
********************************************************/
#if defined(__ARM9_MMU__)
#define CACHE_PROFILE_INIT(select) do {} while(0)

#elif defined(__ARM11_MMU__) // __ARM9_MMU__
#define CACHE_PROFILE_INIT(select) \
        do { \
            kal_uint32 pmuevnt_cfg; \
            pmuevnt_cfg = cp15_GetPerfMonitorControl(); \
            pmuevnt_cfg &= ARM11_PMUEVNT_CNT0_CFG_MASK; \
            pmuevnt_cfg &= ARM11_PMUEVNT_CNT1_CFG_MASK; \
            if((select) == DATA) \
            { \
                pmuevnt_cfg |= (ARM11_PMUEVNT_DCACHE_MISS << ARM11_PMUEVNT_CNT0_CFG_SHIFT); \
                pmuevnt_cfg |= (ARM11_PMUEVNT_DCACHE_ACES_C << ARM11_PMUEVNT_CNT1_CFG_SHIFT); \
            } \
            else if((select) == INSTRUCTION) \
            { \
                pmuevnt_cfg |= (ARM11_PMUEVNT_ICACHE_MISS << ARM11_PMUEVNT_CNT0_CFG_SHIFT); \
                pmuevnt_cfg |= (ARM11_PMUEVNT_INST_EXE << ARM11_PMUEVNT_CNT1_CFG_SHIFT); \
            } \
            else \
            { \
                ASSERT(0); \
            } \
            cp15_SetPerfMonitorControl(pmuevnt_cfg); \
        } while(0)
        
#elif defined(__CR4__) // __ARM11_MMU__
#define CACHE_PROFILE_INIT(select) \
        do { \
            if((select) == DATA) \
            { \
                MCU_PMU_StopCounter(PMU_EVENT_COUNTER_2 | PMU_EVENT_COUNTER_3); \
                MCU_PMU_ResetCounter(PMU_EVENT_COUNTER_2); \
                MCU_PMU_ResetCounter(PMU_EVENT_COUNTER_3); \
                MCU_PMU_SetEvent(PMU_EVENT_COUNTER_2, PMU_EVENT_DCACHE_MISS); \
                MCU_PMU_SetEvent(PMU_EVENT_COUNTER_3, PMU_EVENT_DCACHE_ACCESS); \
            } else \
            { \
                MCU_PMU_StopCounter(PMU_EVENT_COUNTER_2 | PMU_EVENT_COUNTER_3); \
                MCU_PMU_ResetCounter(PMU_EVENT_COUNTER_2); \
                MCU_PMU_ResetCounter(PMU_EVENT_COUNTER_3); \
                MCU_PMU_SetEvent(PMU_EVENT_COUNTER_2, PMU_EVENT_ICACHE_MISS); \
                MCU_PMU_SetEvent(PMU_EVENT_COUNTER_3, PMU_EVENT_ICACHE_ACCESS); \
            } \
        } while(0)
#elif defined(__MTK_MMU__) // __CR4__
#define CACHE_PROFILE_INIT(select) do {} while(0)

#elif defined(__MTK_MMU_V2__) //__MTK_MMU__
#define CACHE_PROFILE_INIT(select) \
        do { \
            DRV_WriteReg32(ARM7CACHE_CONTROL_REG, (DRV_Reg32(ARM7CACHE_CONTROL_REG) & (~0x00000010))); \
            DRV_WriteReg32(ARM7CACHE_CONTROL_REG, (DRV_Reg32(ARM7CACHE_CONTROL_REG) | 0x00000020)); \
            DRV_WriteReg32(ARM7CACHE_CONTROL_REG, (DRV_Reg32(ARM7CACHE_CONTROL_REG) & (~0x00000020)) ); \
        } while(0)

#endif //__MTK_MMU_V2__
        
/*******************************************************
* CACHE_PROFILE_START() - Public
*   Start collecting cache access and miss count     
********************************************************/
#if defined(__ARM9_MMU__)
#define CACHE_PROFILE_START() do {*ARM_PERF_SET = (ARM_PERF_DCMON_EN | ARM_PERF_ICMON_EN);} while(0)

#elif defined(__ARM11_MMU__) // __ARM9_MMU__
#define CACHE_PROFILE_START() \
        do { \
            kal_uint32 pmuevnt_cfg; \
            pmuevnt_cfg = cp15_GetPerfMonitorControl(); \
            pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_ALLCNT_EN_MASK) | (0x1 << ARM11_PMUEVNT_ALLCNT_EN_SHIFT); \
            cp15_SetPerfMonitorControl(pmuevnt_cfg); \
        } while(0)
        
#elif defined(__CR4__) // __ARM11_MMU__
#define CACHE_PROFILE_START() \
        do { \
            MCU_PMU_StartCounter(PMU_EVENT_COUNTER_2 | PMU_EVENT_COUNTER_3); \
        } while(0)

#elif defined(__MTK_MMU__) // __CR4__
#define CACHE_PROFILE_START() \
        do { \
            *CACHE_CON |= MTK_CACHE_COUNT0_BIT|MTK_CACHE_COUNT1_BIT; \
        } while(0)        
        
#elif defined(__MTK_MMU_V2__) //__MTK_MMU__
#define CACHE_PROFILE_START() \
        do { \
            DRV_WriteReg32(ARM7CACHE_CONTROL_REG, (DRV_Reg32(ARM7CACHE_CONTROL_REG) | 0x00000010)); \
        } while(0)
        
#endif //__MTK_MMU_V2__

/*******************************************************
* CACHE_PROFILE_PAUSE() - Public
*   Pause collecting cache access and miss count   
********************************************************/
#if defined(__ARM9_MMU__)
#define CACHE_PROFILE_PAUSE() do {*ARM_PERF_CLR = (ARM_PERF_DCMON_EN | ARM_PERF_ICMON_EN);} while(0)        

#elif defined(__ARM11_MMU__) // __ARM9_MMU__
#define CACHE_PROFILE_PAUSE() \
        do { \
            kal_uint32 pmuevnt_cfg; \
            pmuevnt_cfg = cp15_GetPerfMonitorControl(); \
            pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_ALLCNT_EN_MASK) | (0x0 << ARM11_PMUEVNT_ALLCNT_EN_SHIFT); \
            cp15_SetPerfMonitorControl(pmuevnt_cfg); \
        } while(0)
        
#elif defined(__CR4__) // __ARM11_MMU__
#define CACHE_PROFILE_PAUSE() \
        do { \
            MCU_PMU_StopCounter(PMU_EVENT_COUNTER_2 | PMU_EVENT_COUNTER_3); \
        } while(0)

#elif defined(__MTK_MMU__) // __CR4__
#define CACHE_PROFILE_PAUSE() \
        do { \
            *CACHE_CON &= ~(MTK_CACHE_COUNT0_BIT|MTK_CACHE_COUNT1_BIT); \
        } while(0)  

#elif defined(__MTK_MMU_V2__) //__MTK_MMU__
#define CACHE_PROFILE_PAUSE() \
        do { \
            DRV_WriteReg32(ARM7CACHE_CONTROL_REG, (DRV_Reg32(ARM7CACHE_CONTROL_REG) & (~0x00000010))); \
        } while(0)
        
#endif //__MTK_MMU_V2__

/*******************************************************
* CACHE_PROFILE_RESET() - Public
*   Reset cache access and miss count
********************************************************/
#if defined(__ARM9_MMU__)
#define CACHE_PROFILE_RESET() \
        do { \
            *ARM_PERF_CLR = (ARM_PERF_DCMON_CLR | ARM_PERF_ICMON_CLR); \
            *ARM_PERF_SET = (ARM_PERF_DCMON_CLR | ARM_PERF_ICMON_CLR); \
        } while(0)  
                 
#elif defined(__ARM11_MMU__) // __ARM9_MMU__
#define CACHE_PROFILE_RESET() \
        do { \
            kal_uint32 pmuevnt_cfg; \
            pmuevnt_cfg = cp15_GetPerfMonitorControl(); \
            pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_EVNT01CNT_RESET_MASK) | (0x0 << ARM11_PMUEVNT_EVNT01CNT_RESET_SHIFT); \
            cp15_SetPerfMonitorControl(pmuevnt_cfg); \
        } while(0)

#elif defined(__CR4__) // __ARM11_MMU__
#define CACHE_PROFILE_RESET() \
        do { \
            MCU_PMU_ResetCounter(PMU_EVENT_COUNTER_2); \
            MCU_PMU_ResetCounter(PMU_EVENT_COUNTER_3); \
        } while(0)  
        
#elif defined(__MTK_MMU__) // __CR4__
#define CACHE_PROFILE_RESET() \
        do { \
            *CACHE_HCNT0L=0; \
            *CACHE_HCNT0U=0; \
            *CACHE_CCNT0L=0; \
            *CACHE_CCNT0U=0; \
            *CACHE_HCNT1L=0; \
            *CACHE_HCNT1U=0; \
            *CACHE_CCNT1L=0; \
            *CACHE_CCNT1U=0; \
        } while(0)

#elif defined(__MTK_MMU_V2__) //__MTK_MMU__
#define CACHE_PROFILE_RESET() \
        do { \
            DRV_WriteReg32(ARM7CACHE_CONTROL_REG, (DRV_Reg32(ARM7CACHE_CONTROL_REG) | 0x00000020)); \
            DRV_WriteReg32(ARM7CACHE_CONTROL_REG, (DRV_Reg32(ARM7CACHE_CONTROL_REG) & (~0x00000020)) ); \
        } while(0)
        
#endif //__MTK_MMU_V2__

/*******************************************************
* CACHE_PROFILE_GET_RESULT(CACHE_PROFILE_T * info) - Public
*   Return current cache profile result
********************************************************/
#if defined(__ARM9_MMU__)
#define CACHE_PROFILE_GET_RESULT(info) \
        do { \
            (info)->ICache_Access_Count = (kal_uint64)(*ARM_PERF_ICREAD_REQ); \
            (info)->DCache_Access_Count = (kal_uint64)(*ARM_PERF_DCREAD_REQ); \
            (info)->DCache_Access_Count += (kal_uint64)(*ARM_PERF_DCWRITE_REQ); \
            (info)->ICache_Miss_Count = (kal_uint64)(*ARM_PERF_ICREAD_MISS); \
            (info)->DCache_Miss_Count = (kal_uint64)(*ARM_PERF_DCREAD_MISS); \
            (info)->DCache_Miss_Count += (kal_uint64)(*ARM_PERF_DCWRITE_MISS); \
        } while(0)
  
#elif defined(__ARM11_MMU__) // __ARM9_MMU__
#define CACHE_PROFILE_GET_RESULT(info) \
        do { \
            (info)->Cache_Miss_Count = cp15_GetCountRegister0(); \
            (info)->Cache_Access_Count = cp15_GetCountRegister1(); \
        } while(0)
         
#elif defined(__CR4__) // __ARM11_MMU__
#define CACHE_PROFILE_GET_RESULT(info) \
        do { \
            (info)->Cache_Miss_Count = MCU_PMU_ReadCounter(PMU_EVENT_COUNTER_2); \
            (info)->Cache_Access_Count = MCU_PMU_ReadCounter(PMU_EVENT_COUNTER_3); \
        } while(0)

#elif defined(__MTK_MMU__) // __CR4__
#define CACHE_PROFILE_GET_RESULT(info) \
        do { \
            kal_uint64 cache_hit_count, cache_access_count; \
            cache_access_count = *(volatile kal_uint64 *)(CACHE_CCNT0L); \
            cache_access_count += *(volatile kal_uint64 *)(CACHE_CCNT1L); \
            cache_hit_count = *(volatile kal_uint64 *)(CACHE_HCNT0L); \
            cache_hit_count += *(volatile kal_uint64 *)(CACHE_HCNT1L); \
            (info)->Cache_Miss_Count = cache_access_count - cache_hit_count; \
            (info)->Cache_Access_Count = cache_access_count; \
        } while(0)
        
#elif defined(__MTK_MMU_V2__) //__MTK_MMU__
#define CACHE_PROFILE_GET_RESULT(info) \
        do { \
            (info)->Cache_Access_Count = DRV_Reg32(ARM7CACHE_ACC_CNTR_REG); \
            (info)->Cache_Miss_Count = DRV_Reg32(ARM7CACHE_MISS_CNTR_REG); \
            (info)->Cache_Hit_Count = DRV_Reg32(ARM7CACHE_HIT_CNTR_REG); \
            (info)->Cache_Wbk_Fill_Cycle_Count = DRV_Reg32(ARM7CACHE_WBK_FILL_CYCLE_CNTR_REG); \
            (info)->Tcm_Access_Count = DRV_Reg32(ARM7CACHE_TCM_CNTR_REG); \
        } while(0)
        
#endif //__MTK_MMU_V2__


#endif /* CACHE_ANALYSIS */

#endif /* __CACHE_UTIL_H__ */
