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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 * Include header files.
 *******************************************************************************/

#ifdef __MTK_TARGET__

#if defined(MT6276) && defined(__MT6276_CONCURRENCY_TEST__)

/******************************
   *
   * Include files
   *
   *****************************/

#include "arm11_pmu_montr.h"


/******************************
   *
   * Define constant.
   *
   *****************************/

#if defined(ARMEMI_MONTR_EMBEDDED_IN_SWLA)
    /* do nothing */
#else /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */
#define ARM11_MON_BUF_SIZE 100
#define ARM11_MON_INC_IDX(idx) (idx = (idx+1)%ARM11_MON_BUF_SIZE)
#endif /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */


/******************************
   *
   * Define import global data.
   *
   *****************************/


/******************************
   *
   * Define import functions.
   *
   *****************************/


/******************************
   *
   * Define global data.
   *
   *****************************/


#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE_TEST", rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */

/**
  * Record the current monitoring event.
  * ARM11_PMU_EVNT_ICACHE_HIT_RATE = 0x0, 
  * ARM11_PMU_EVNT_DCACHE_HIT_RATE = 0x1, 
  * 
  * The following event is only available when you enable corresponding field on ARM11_PMUEVNT_STATISTICS structure.
  * ARM11_PMU_EVNT_ICACHEMISS_INSTMICROTLBMISS = 0x2,
  * ARM11_PMU_EVNT_DCACHEMISS_DATAMICROTLBMISS = 0x3,
  * ARM11_PMU_EVNT_DCACHEWRITEBACK_MAINTLBMISS = 0x4,
  * ARM11_PMU_EVNT_EXPEXTDATAACES_WRITEBUFDRAIN = 0x5,
  * ARM11_PMU_EVNT_DCACHEACES_DCACHENONCACHEACES = 0x6,
  * ARM11_PMU_EVNT_INSTEXE_BRANCHMISPREDICT = 0x7
  */
kal_uint32 arm11_pmu_montr_evnt = ARM11_PMU_EVNT_ICACHE_HIT_RATE;


#if defined(ARMEMI_MONTR_EMBEDDED_IN_SWLA)
/* do nothing. */
#else /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */
/**
   * Buffer that record ARM11 events.
   */
ARM11_PMUEVNT_STATISTICS arm11_mon_buf[ARM11_MON_BUF_SIZE];
EMIMON_LOG_T emi_mon_buf[ARM11_MON_BUF_SIZE];
kal_uint32 arm11_mon_buf_idx = 0;
kal_uint32 arm11_mon_log_cnt = 0;
kal_uint32 arm11_mon_log_cnt_overrun = 0;
#endif /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */

#ifdef __MTK_TARGET__
#pragma arm section
#endif /* __MTK_TARGET__ */



/**
  * @brief this function is used to initialize ARM11 PMU by performing the ARM11 PMU event configuration.
  *
  * @remarks function:  
  * @remarks category: 
  * @remarks sub_category:  
  *
  * @return None
  */

#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE_TEST", rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */

int ARM11PMU_init_montr()
{
    unsigned int pmuevnt_cfg;
    unsigned int emievnt_cfg;

    /**
       * Enable MT6276 E1 ARM11 PMU.
       */
#if defined(MT6276)
    *(volatile unsigned int*)(0x610F0000) = 0x00001F00;
#elif defined(MT6256)

#else
#error "NON-supported platform"
#endif


    /**
       * Read/modify/write-back the ARM11 CP15 performance control register.
       */
    pmuevnt_cfg = cp15_GetPerfMonitorControl();
    {
        /**
           * Clear previous event.
           */
        pmuevnt_cfg &= ARM11_PMUEVNT_CNT0_CFG_MASK;
        pmuevnt_cfg &= ARM11_PMUEVNT_CNT1_CFG_MASK;
    
        /**
           * Get profiling events.
           */
        switch(arm11_pmu_montr_evnt)
        {
            case ARM11_PMU_EVNT_ICACHE_HIT_RATE:
                pmuevnt_cfg |= (ARM11_PMUEVNT_ICACHE_MISS << ARM11_PMUEVNT_CNT0_CFG_SHIFT);
                pmuevnt_cfg |= (ARM11_PMUEVNT_INST_EXE << ARM11_PMUEVNT_CNT1_CFG_SHIFT);
                break;
        
            case ARM11_PMU_EVNT_DCACHE_HIT_RATE:
                pmuevnt_cfg |= (ARM11_PMUEVNT_DCACHE_MISS << ARM11_PMUEVNT_CNT0_CFG_SHIFT);
                pmuevnt_cfg |= (ARM11_PMUEVNT_DCACHE_ACES_C << ARM11_PMUEVNT_CNT1_CFG_SHIFT);
                break;

            case ARM11_PMU_EVNT_ICACHEMISS_INSTMICROTLBMISS:
                pmuevnt_cfg |= (ARM11_PMUEVNT_ICACHE_MISS << ARM11_PMUEVNT_CNT0_CFG_SHIFT);
                pmuevnt_cfg |= (ARM11_PMUEVNT_IMICROTLB_MISS << ARM11_PMUEVNT_CNT1_CFG_SHIFT);
                break;
        
            case ARM11_PMU_EVNT_DCACHEMISS_DATAMICROTLBMISS:
                pmuevnt_cfg |= (ARM11_PMUEVNT_DCACHE_MISS << ARM11_PMUEVNT_CNT0_CFG_SHIFT);
                pmuevnt_cfg |= (ARM11_PMUEVNT_DMICROTLB_MISS << ARM11_PMUEVNT_CNT1_CFG_SHIFT);
                break;
    
            case ARM11_PMU_EVNT_DCACHEWRITEBACK_MAINTLBMISS:
                pmuevnt_cfg |= (ARM11_PMUEVNT_DCACHE_WRITEBACK << ARM11_PMUEVNT_CNT0_CFG_SHIFT);
                pmuevnt_cfg |= (ARM11_PMUEVNT_MAINTLB_MISS << ARM11_PMUEVNT_CNT1_CFG_SHIFT);
                break;
        
            case ARM11_PMU_EVNT_EXPEXTDATAACES_WRITEBUFDRAIN:
                pmuevnt_cfg |= (ARM11_PMUEVNT_EXPLICIT_EXTDATA_ACES << ARM11_PMUEVNT_CNT0_CFG_SHIFT);
                pmuevnt_cfg |= (ARM11_PMUEVNT_WRITEBUF_DRAIN << ARM11_PMUEVNT_CNT1_CFG_SHIFT);
                break;

            case ARM11_PMU_EVNT_DCACHEACES_DCACHENONCACHEACES:
                pmuevnt_cfg |= (ARM11_PMUEVNT_DCACHE_ACES_C << ARM11_PMUEVNT_CNT0_CFG_SHIFT);
                pmuevnt_cfg |= (ARM11_PMUEVNT_DCACHE_ACES_CNC << ARM11_PMUEVNT_CNT1_CFG_SHIFT);
                break;

            case ARM11_PMU_EVNT_INSTEXE_BRANCHMISPREDICT:
                pmuevnt_cfg |= (ARM11_PMUEVNT_INST_EXE << ARM11_PMUEVNT_CNT0_CFG_SHIFT);
                pmuevnt_cfg |= (ARM11_PMUEVNT_BRANCH_MISPREDICT << ARM11_PMUEVNT_CNT1_CFG_SHIFT);
                break;
        
            default:
                ASSERT(0);
        }
    }
    cp15_SetPerfMonitorControl(pmuevnt_cfg);


    /**
       * Configure EMI monitor event.
       */
    {
        emievnt_cfg = 0;
        emievnt_cfg &= EMIMON_SEL_RWOP_MASK;
        emievnt_cfg |= (EMIMON_OP_SEL_RW << EMIMON_SEL_RWOP_SHIFT);
        emievnt_cfg &= EMIMON_SEL_SLICE_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_SLICE_OFFSET);
        emievnt_cfg &= EMIMON_SEL_SLICE_ALL_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_SLICE_ALL_OFFSET);
        emievnt_cfg &= EMIMON_SEL_EMICYC_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_EMICYC_OFFSET);
        emievnt_cfg &= EMIMON_SEL_ROW_HIT_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_ROW_HIT_OFFSET);
        emievnt_cfg &= EMIMON_SEL_ROW_START_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_ROW_START_OFFSET);
        emievnt_cfg &= EMIMON_SEL_ROW_CONFLICT_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_ROW_CONFLICT_OFFSET);
        emievnt_cfg &= EMIMON_SEL_INTER_BANK_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_INTER_BANK_OFFSET);
        
        /**
           * We use CNT1 to monitor all transaction type & word cnt for ARM.
           */
        emievnt_cfg &= EMIMON_CNT1_SEL_TRANSTYP_MASK;
        emievnt_cfg |= (EMIMON_TRANSTYPE_SEL_INCR48 << EMIMON_CNT1_SEL_TRANSTYP_SHIFT);
        emievnt_cfg &= EMIMON_CNT1_SEL_MASTER_MASK;
        emievnt_cfg |= (EMIMON_MASTER_SEL_ARM << EMIMON_CNT1_SEL_MASTER_SHIFT);  
        *EMI_BMEN = emievnt_cfg;

        emievnt_cfg = 0;
        /**
           * We use CNT2 to monitor all transaction type & word cnt for all master excluding dummy read to avoid the result is influenced by HWDCM bugs.
           */
        emievnt_cfg &= EMIMON_CNT2_SEL_TRANSTYP_MASK;
        emievnt_cfg |= (EMIMON_TRANSTYPE_SEL_WRAP48 << EMIMON_CNT2_SEL_TRANSTYP_SHIFT);
        emievnt_cfg &= EMIMON_CNT2_SEL_MASTER_MASK;
        emievnt_cfg |= (EMIMON_MASTER_SEL_ALL << EMIMON_CNT2_SEL_MASTER_SHIFT);

        /**
           * We set CNT1~9 to monitor different transaction type for ARM.
           */
        emievnt_cfg &= EMIMON_CNT3_SEL_TRANSTYP_MASK;
        emievnt_cfg |= (EMIMON_TRANSTYPE_SEL_INCR28 << EMIMON_CNT3_SEL_TRANSTYP_SHIFT);        
        emievnt_cfg &= EMIMON_CNT3_SEL_MASTER_MASK;
        emievnt_cfg |= (EMIMON_MASTER_SEL_ARM << EMIMON_CNT3_SEL_MASTER_SHIFT);
        *EMI_MSEL = emievnt_cfg;

        emievnt_cfg = 0;
        emievnt_cfg &= EMIMON_CNT4_SEL_TRANSTYP_MASK;
        emievnt_cfg |= (EMIMON_TRANSTYPE_SEL_WRAP28 << EMIMON_CNT4_SEL_TRANSTYP_SHIFT);
        emievnt_cfg &= EMIMON_CNT4_SEL_MASTER_MASK;
        emievnt_cfg |= (EMIMON_MASTER_SEL_ARM << EMIMON_CNT4_SEL_MASTER_SHIFT);        
        emievnt_cfg &= EMIMON_CNT5_SEL_TRANSTYP_MASK;
        emievnt_cfg |= (EMIMON_TRANSTYPE_SEL_INCR11 << EMIMON_CNT5_SEL_TRANSTYP_SHIFT);        
        emievnt_cfg &= EMIMON_CNT5_SEL_MASTER_MASK;
        emievnt_cfg |= (EMIMON_MASTER_SEL_ARM << EMIMON_CNT5_SEL_MASTER_SHIFT);        
        *EMI_MSEL2 = emievnt_cfg;

        emievnt_cfg = 0;
        emievnt_cfg &= EMIMON_CNT6_SEL_TRANSTYP_MASK;
        emievnt_cfg |= (EMIMON_TRANSTYPE_SEL_INCR12 << EMIMON_CNT6_SEL_TRANSTYP_SHIFT);
        emievnt_cfg &= EMIMON_CNT6_SEL_MASTER_MASK;
        emievnt_cfg |= (EMIMON_MASTER_SEL_ARM << EMIMON_CNT6_SEL_MASTER_SHIFT);        
        emievnt_cfg &= EMIMON_CNT7_SEL_TRANSTYP_MASK;
        emievnt_cfg |= (EMIMON_TRANSTYPE_SEL_INCR14 << EMIMON_CNT7_SEL_TRANSTYP_SHIFT);        
        emievnt_cfg &= EMIMON_CNT7_SEL_MASTER_MASK;
        emievnt_cfg |= (EMIMON_MASTER_SEL_ARM << EMIMON_CNT7_SEL_MASTER_SHIFT);        
        *EMI_MSEL3 = emievnt_cfg;

        emievnt_cfg = 0;
        emievnt_cfg &= EMIMON_CNT8_SEL_TRANSTYP_MASK;
        emievnt_cfg |= (EMIMON_TRANSTYPE_SEL_INCR18 << EMIMON_CNT8_SEL_TRANSTYP_SHIFT);        
        emievnt_cfg &= EMIMON_CNT8_SEL_MASTER_MASK;
        emievnt_cfg |= (EMIMON_MASTER_SEL_ARM << EMIMON_CNT8_SEL_MASTER_SHIFT);        
        emievnt_cfg &= EMIMON_CNT9_SEL_TRANSTYP_MASK;
        emievnt_cfg |= (EMIMON_TRANSTYPE_SEL_WRAP48 << EMIMON_CNT9_SEL_TRANSTYP_SHIFT);        
        emievnt_cfg &= EMIMON_CNT9_SEL_MASTER_MASK;
        emievnt_cfg |= (EMIMON_MASTER_SEL_ARM << EMIMON_CNT9_SEL_MASTER_SHIFT);        
        *EMI_MSEL4 = emievnt_cfg;                        
    }

    return 0;	
}


#ifdef __MTK_TARGET__
#pragma arm section
#endif /* __MTK_TARGET__ */



/**
  * @brief this function is used to perform the start the ARM11 PMU.
  *
  * @remarks function:  
  * @remarks category: 
  * @remarks sub_category:  
  *
  * @return None
  */


#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE_TEST", rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */


int ARM11PMU_start_montr(void)
{
    unsigned int pmuevnt_cfg;

    /**
       * Read/modify/write-back the ARM11 CP15 performance control register.
       */
    pmuevnt_cfg = cp15_GetPerfMonitorControl();
    {
        /**
           * Configure PMU cfg value.
           */
        pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_ALLCNT_EN_MASK) | (0x1 << ARM11_PMUEVNT_ALLCNT_EN_SHIFT);    
    }
    cp15_SetPerfMonitorControl(pmuevnt_cfg);

    /**
       * Start EMI monitor.
       */
    __EMIMON_ADV_START_CNT();

    return 0;
}

#ifdef __MTK_TARGET__
#pragma arm section
#endif /* __MTK_TARGET__ */



/**
  * @brief this function is used to perform the stop and get logs of ARM11 PMU.
  *
  * @remarks function:  MMU
  * @remarks category: Protect
  * @remarks sub_category:  
  *
  * @return None
  */


#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE_TEST", rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */

#if defined(ARMEMI_MONTR_EMBEDDED_IN_SWLA)
int ARM11PMU_stop_montr_with_log(ARM11_PMUEVNT_STATISTICS *arm11_pmu_log, EMIMON_LOG_T *emi_log)
#else
int ARM11PMU_stop_montr_with_log(void)
#endif /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */
{
    /**
       * Stop PMU.
       */
    unsigned int pmuevnt_cfg;
    ARM11_PMUEVNT_STATISTICS *arm11_pmu_sta;
    EMIMON_LOG_T *emi_mon_sta;

    /**
       * Pause ARM11 monitor by read/modify/write-back the ARM11 CP15 performance control register.
       */
    pmuevnt_cfg = cp15_GetPerfMonitorControl();
    {
        /**
           * Configure PMU cfg value.
           */
        pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_ALLCNT_EN_MASK) | (0x0 << ARM11_PMUEVNT_ALLCNT_EN_SHIFT);    
    }
    cp15_SetPerfMonitorControl(pmuevnt_cfg);

    /**
       * Pause EMI monitor.
       */
    __EMIMON_ADV_PAUSE_CNT();

    /**
       * Get monitor address.
       */
#if defined(ARMEMI_MONTR_EMBEDDED_IN_SWLA)       
    arm11_pmu_sta = arm11_pmu_log;
    emi_mon_sta = emi_log;
#else /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */
    arm11_pmu_sta = &(arm11_mon_buf[arm11_mon_buf_idx]);
    emi_mon_sta = &(emi_mon_buf[arm11_mon_buf_idx]);
#endif /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */

    /**
       * Get PMU statistics.
       */
    switch(arm11_pmu_montr_evnt)
    {
        case ARM11_PMU_EVNT_ICACHE_HIT_RATE:
            arm11_pmu_sta->arm11_pmuevnt_core_cyccnt = cp15_GetCycCntRegister();
            arm11_pmu_sta->arm11_pmuevnt_icache_miss_cnt = cp15_GetCountRegister0();
            arm11_pmu_sta->arm11_pmuevnt_inst_exe_cnt = cp15_GetCountRegister1();
            break;
    
        case ARM11_PMU_EVNT_DCACHE_HIT_RATE:
            arm11_pmu_sta->arm11_pmuevnt_core_cyccnt = cp15_GetCycCntRegister();        	
            arm11_pmu_sta->arm11_pmuevnt_dcache_miss_cnt = cp15_GetCountRegister0();
            arm11_pmu_sta->arm11_pmuevnt_dcache_aces_c_cnt = cp15_GetCountRegister1();
            break;

        case ARM11_PMU_EVNT_ICACHEMISS_INSTMICROTLBMISS:
            //arm11_pmu_sta->arm11_pmuevnt_core_cyccnt = cp15_GetCycCntRegister();        	
            //arm11_pmu_sta->arm11_pmuevnt_icache_miss_cnt = cp15_GetCountRegister0();
            //arm11_pmu_sta->arm11_pmuevnt_imicrotlb_miss_cnt = cp15_GetCountRegister1();
            break;
    
        case ARM11_PMU_EVNT_DCACHEMISS_DATAMICROTLBMISS:
            //arm11_pmu_sta->arm11_pmuevnt_core_cyccnt = cp15_GetCycCntRegister();        	
            //arm11_pmu_sta->arm11_pmuevnt_dcache_miss_cnt = cp15_GetCountRegister0();
            //arm11_pmu_sta->arm11_pmuevnt_dmicrotlb_miss_cnt = cp15_GetCountRegister1();
            break;

        case ARM11_PMU_EVNT_DCACHEWRITEBACK_MAINTLBMISS:
            //arm11_pmu_sta->arm11_pmuevnt_core_cyccnt = cp15_GetCycCntRegister();        	
            //arm11_pmu_sta->arm11_pmuevnt_dcache_writeback_cnt = cp15_GetCountRegister0();
            //arm11_pmu_sta->arm11_pmuevnt_maintlb_miss_cnt = cp15_GetCountRegister1();
            break;
    
        case ARM11_PMU_EVNT_EXPEXTDATAACES_WRITEBUFDRAIN:
            //arm11_pmu_sta->arm11_pmuevnt_core_cyccnt = cp15_GetCycCntRegister();        	
            //arm11_pmu_sta->arm11_pmuevnt_explicit_extdata_aces_cnt = cp15_GetCountRegister0();
            //arm11_pmu_sta->arm11_pmuevnt_writebuf_drain_cnt = cp15_GetCountRegister1();
            break;

        case ARM11_PMU_EVNT_DCACHEACES_DCACHENONCACHEACES:
            //arm11_pmu_sta->arm11_pmuevnt_core_cyccnt = cp15_GetCycCntRegister();        	
            //arm11_pmu_sta->arm11_pmuevnt_dcache_aces_c_cnt = cp15_GetCountRegister0();
            //arm11_pmu_sta->arm11_pmuevnt_dcache_aces_cnc_cnt = cp15_GetCountRegister1();
            break;

        case ARM11_PMU_EVNT_INSTEXE_BRANCHMISPREDICT:
            //arm11_pmu_sta->arm11_pmuevnt_core_cyccnt = cp15_GetCycCntRegister();        	
            //arm11_pmu_sta->arm11_pmuevnt_inst_exe_cnt = cp15_GetCountRegister0();
            //arm11_pmu_sta->arm11_pmuevnt_branch_mispredict_cnt = cp15_GetCountRegister1();
            break;

        default:
            ASSERT(0);
    }

    /**
       * Get emi montr counter.
       */
    {   
    	  kal_uint32 emievnt_cfg = 0;
    	  
        emi_mon_sta->emi_total_fixed_cyccnt = *EMI_BCNT;
        /* avoid using TACT and WACT to prevent getting dummy read's transaction. */
        //emi_mon_sta->emi_total_trans_cnt = *EMI_TACT;
        //emi_mon_sta->emi_total_dword_cnt = *EMI_WACT;
        emi_mon_sta->emi_total_trans_cnt = *EMI_TSCT2;
        emi_mon_sta->emi_total_dword_cnt = *EMI_WSCT2;
        emi_mon_sta->emi_total_busy_cyccnt = *EMI_BACT;    

        emi_mon_sta->emi_massel_busy_cyccnt = *EMI_BSCT;
        emi_mon_sta->emi_massel_trans_cnt = *EMI_TSCT;
        emi_mon_sta->emi_massel_dword_cnt = *EMI_WSCT;

        emi_mon_sta->emi_mastransel_trans_cnt_wrap48 = *EMI_TTYPE1;
        emi_mon_sta->emi_mastransel_trans_cnt_incr48 = *EMI_TTYPE9;
        emi_mon_sta->emi_mastransel_trans_cnt_wrap28 = *EMI_TTYPE3;
        emi_mon_sta->emi_mastransel_trans_cnt_incr28 = *EMI_TTYPE4;
        emi_mon_sta->emi_mastransel_trans_cnt_incr11 = *EMI_TTYPE5;
        emi_mon_sta->emi_mastransel_trans_cnt_incr12 = *EMI_TTYPE6;
        emi_mon_sta->emi_mastransel_trans_cnt_incr14 = *EMI_TTYPE7;
        emi_mon_sta->emi_mastransel_trans_cnt_incr18 = *EMI_TTYPE8;

        /**
          * Switch to EMI status counter mode.
          */
        emievnt_cfg = *EMI_BMEN;
        /* do not change slice mask. */
        emievnt_cfg &= EMIMON_SEL_SLICE_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_SLICE_OFFSET);
        emievnt_cfg &= EMIMON_SEL_SLICE_ALL_MASK;
        emievnt_cfg |= (0x1 << EMIMON_SEL_SLICE_ALL_OFFSET);
        emievnt_cfg &= EMIMON_SEL_EMICYC_MASK;
        emievnt_cfg |= (0x1 << EMIMON_SEL_EMICYC_OFFSET);
        emievnt_cfg &= EMIMON_SEL_ROW_HIT_MASK;
        emievnt_cfg |= (0x1 << EMIMON_SEL_ROW_HIT_OFFSET);
        emievnt_cfg &= EMIMON_SEL_ROW_START_MASK;
        emievnt_cfg |= (0x1 << EMIMON_SEL_ROW_START_OFFSET);
        emievnt_cfg &= EMIMON_SEL_ROW_CONFLICT_MASK;
        emievnt_cfg |= (0x1 << EMIMON_SEL_ROW_CONFLICT_OFFSET);
        emievnt_cfg &= EMIMON_SEL_INTER_BANK_MASK;
        emievnt_cfg |= (0x1 << EMIMON_SEL_INTER_BANK_OFFSET);
        *EMI_BMEN = emievnt_cfg;

        emi_mon_sta->emi_total_bus_cyccnt = *EMI_TSCT;
        emi_mon_sta->emi_total_slice_cnt = *EMI_TACT;
        emi_mon_sta->emi_total_row_hit_cnt = *EMI_WACT;
        emi_mon_sta->emi_total_row_start_cnt = *EMI_WSCT;
        emi_mon_sta->emi_total_row_conflict_cnt = *EMI_BACT;
        emi_mon_sta->emi_total_inter_bank_cnt = *EMI_BSCT;                                

        /**
          * Switch back to original EMI BW counter mode.
          */
        emievnt_cfg = *EMI_BMEN;
        emievnt_cfg &= EMIMON_SEL_SLICE_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_SLICE_OFFSET);
        emievnt_cfg &= EMIMON_SEL_SLICE_ALL_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_SLICE_ALL_OFFSET);
        emievnt_cfg &= EMIMON_SEL_EMICYC_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_EMICYC_OFFSET);
        emievnt_cfg &= EMIMON_SEL_ROW_HIT_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_ROW_HIT_OFFSET);
        emievnt_cfg &= EMIMON_SEL_ROW_START_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_ROW_START_OFFSET);
        emievnt_cfg &= EMIMON_SEL_ROW_CONFLICT_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_ROW_CONFLICT_OFFSET);
        emievnt_cfg &= EMIMON_SEL_INTER_BANK_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_INTER_BANK_OFFSET);        
        *EMI_BMEN = emievnt_cfg;        
    }
    
    /**
       * Increase the monitor index.
       */
#if defined(ARMEMI_MONTR_EMBEDDED_IN_SWLA)       
    /* do nothing. */
#else /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */
    ARM11_MON_INC_IDX(arm11_mon_buf_idx);
#endif /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */
       

    /**
       * Reset all PMU counters.
       */
    pmuevnt_cfg = cp15_GetPerfMonitorControl();
    {
        /**
           * Configure PMU cfg value.
           */
        pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_CORECYCCNT_RESET_MASK) | (0x1 << ARM11_PMUEVNT_CORECYCCNT_RESET_SHIFT);    
        pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_ALLCNT_EN_MASK) | (0x1 << ARM11_PMUEVNT_EVNT01CNT_RESET_SHIFT);    
    }
    cp15_SetPerfMonitorControl(pmuevnt_cfg);

    /**
       * We explicitly set the reset bit back to 0 since ARM11 TRM does not state the programming sequence clearly.
       */
    pmuevnt_cfg = cp15_GetPerfMonitorControl();
    {
        /**
           * Configure PMU cfg value.
           */
        pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_CORECYCCNT_RESET_MASK) | (0x0 << ARM11_PMUEVNT_CORECYCCNT_RESET_SHIFT);    
        pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_ALLCNT_EN_MASK) | (0x0 << ARM11_PMUEVNT_EVNT01CNT_RESET_SHIFT);    
    }
    cp15_SetPerfMonitorControl(pmuevnt_cfg);

    /**
       * Reset EMI monitor counter.
       */
    __EMIMON_ADV_STOP_AND_CLR_CNT();

    /**
       * Increase log counter.
       */
#if defined(ARMEMI_MONTR_EMBEDDED_IN_SWLA)       
    /* do nothing. */
#else /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */
    if(arm11_mon_log_cnt < 0xFFFFFFF)
    {
        arm11_mon_log_cnt++;
    }
    else
    {
        arm11_mon_log_cnt = 0;    
        arm11_mon_log_cnt_overrun = 1;
    }
#endif /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */
       

    return 0;
}

#ifdef __MTK_TARGET__
#pragma arm section
#endif /* __MTK_TARGET__ */


#elif defined(__SLA_INST_COUNT_SUPPORT__)

#include "arm11_pmu_montr.h"

/**
  * @brief this function is used to initialize ARM11 PMU by performing the ARM11 PMU event configuration.
  *
  * @remarks function:  
  * @remarks category: 
  * @remarks sub_category:  
  *
  * @return None
  */

#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE_TEST", rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */

int ARM11PMU_init_montr()
{
    unsigned int pmuevnt_cfg;

    /**
       * EnableARM11 PMU.
       */
#if defined(MT6276)
    *(volatile unsigned int*)(0x810F0000) = 0x00001F00;
#elif defined(MT6256)

#else
#error "NON-supported platform"
#endif

    /**
       * Read/modify/write-back the ARM11 CP15 performance control register.
       */
    pmuevnt_cfg = cp15_GetPerfMonitorControl();

    /**
       * Clear previous event.
       */
    pmuevnt_cfg &= ARM11_PMUEVNT_CNT0_CFG_MASK;
    pmuevnt_cfg &= ARM11_PMUEVNT_CNT1_CFG_MASK;

    /**
       * Get profiling events.
       */  
    pmuevnt_cfg |= (ARM11_PMUEVNT_ICACHE_MISS << ARM11_PMUEVNT_CNT0_CFG_SHIFT);
    pmuevnt_cfg |= (ARM11_PMUEVNT_INST_EXE << ARM11_PMUEVNT_CNT1_CFG_SHIFT);

    cp15_SetPerfMonitorControl(pmuevnt_cfg);

    return 0;	
}


#ifdef __MTK_TARGET__
#pragma arm section
#endif /* __MTK_TARGET__ */


/**
  * @brief this function is used to perform the start the ARM11 PMU.
  *
  * @remarks function:  
  * @remarks category: 
  * @remarks sub_category:  
  *
  * @return None
  */


#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE_TEST", rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */


int ARM11PMU_start_montr(void)
{
    unsigned int pmuevnt_cfg;

    /**
       * Read/modify/write-back the ARM11 CP15 performance control register.
       */
    pmuevnt_cfg = cp15_GetPerfMonitorControl();
    {
        /**
           * Configure PMU cfg value.
           */
        pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_ALLCNT_EN_MASK) | (0x1 << ARM11_PMUEVNT_ALLCNT_EN_SHIFT);    
    }
    cp15_SetPerfMonitorControl(pmuevnt_cfg);

    return 0;
}

#ifdef __MTK_TARGET__
#pragma arm section
#endif /* __MTK_TARGET__ */

/**
  * @brief this function is used to perform the stop and get logs of ARM11 PMU.
  *
  * @remarks function:  MMU
  * @remarks category: Protect
  * @remarks sub_category:  
  *
  * @return None
  */


#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE_TEST", rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */

int ARM11PMU_stop_montr_with_log(ARM11_PMUEVNT_STATISTICS *arm11_pmu_log)
{
    /**
       * Stop PMU.
       */
    unsigned int pmuevnt_cfg;
    ARM11_PMUEVNT_STATISTICS *arm11_pmu_sta;

    /**
       * Pause ARM11 monitor by read/modify/write-back the ARM11 CP15 performance control register.
       */
    pmuevnt_cfg = cp15_GetPerfMonitorControl();
    {
        /**
           * Configure PMU cfg value.
           */
        pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_ALLCNT_EN_MASK) | (0x0 << ARM11_PMUEVNT_ALLCNT_EN_SHIFT);    
    }
    cp15_SetPerfMonitorControl(pmuevnt_cfg);

    /**
       * Get monitor address.
       */   
    arm11_pmu_sta = arm11_pmu_log;

    /**
       * Get PMU statistics.
       */

    arm11_pmu_sta->arm11_pmuevnt_core_cyccnt = cp15_GetCycCntRegister();
    arm11_pmu_sta->arm11_pmuevnt_icache_miss_cnt = cp15_GetCountRegister0();
    arm11_pmu_sta->arm11_pmuevnt_inst_exe_cnt = cp15_GetCountRegister1();

    /**
       * Reset all PMU counters.
       */
    pmuevnt_cfg = cp15_GetPerfMonitorControl();
    {
        /**
           * Configure PMU cfg value.
           */
        pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_CORECYCCNT_RESET_MASK) | (0x1 << ARM11_PMUEVNT_CORECYCCNT_RESET_SHIFT);    
        pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_ALLCNT_EN_MASK) | (0x1 << ARM11_PMUEVNT_EVNT01CNT_RESET_SHIFT);    
    }
    cp15_SetPerfMonitorControl(pmuevnt_cfg);

    /**
       * We explicitly set the reset bit back to 0 since ARM11 TRM does not state the programming sequence clearly.
       */
    pmuevnt_cfg = cp15_GetPerfMonitorControl();
    {
        /**
           * Configure PMU cfg value.
           */
        pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_CORECYCCNT_RESET_MASK) | (0x0 << ARM11_PMUEVNT_CORECYCCNT_RESET_SHIFT);    
        pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_ALLCNT_EN_MASK) | (0x0 << ARM11_PMUEVNT_EVNT01CNT_RESET_SHIFT);    
    }
    cp15_SetPerfMonitorControl(pmuevnt_cfg); 

    return 0;
}

#ifdef __MTK_TARGET__
#pragma arm section
#endif /* __MTK_TARGET__ */

#elif defined(__MT6256_CONCURRENCY_TEST__) //add 20110831

/******************************
   *
   * Include files
   *
   *****************************/

#include "arm11_pmu_montr.h"


/******************************
   *
   * Define constant.
   *
   *****************************/

#if defined(ARMEMI_MONTR_EMBEDDED_IN_SWLA)
    /* do nothing */
#else /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */
#define ARM11_MON_BUF_SIZE 100
#define ARM11_MON_INC_IDX(idx) (idx = (idx+1)%ARM11_MON_BUF_SIZE)
#endif /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */


/******************************
   *
   * Define import global data.
   *
   *****************************/


/******************************
   *
   * Define import functions.
   *
   *****************************/


/******************************
   *
   * Define global data.
   *
   *****************************/


#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE_TEST", rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */

/**
  * Record the current monitoring event.
  * ARM11_PMU_EVNT_ICACHE_HIT_RATE = 0x0, 
  * ARM11_PMU_EVNT_DCACHE_HIT_RATE = 0x1, 
  * 
  * The following event is only available when you enable corresponding field on ARM11_PMUEVNT_STATISTICS structure.
  * ARM11_PMU_EVNT_ICACHEMISS_INSTMICROTLBMISS = 0x2,
  * ARM11_PMU_EVNT_DCACHEMISS_DATAMICROTLBMISS = 0x3,
  * ARM11_PMU_EVNT_DCACHEWRITEBACK_MAINTLBMISS = 0x4,
  * ARM11_PMU_EVNT_EXPEXTDATAACES_WRITEBUFDRAIN = 0x5,
  * ARM11_PMU_EVNT_DCACHEACES_DCACHENONCACHEACES = 0x6,
  * ARM11_PMU_EVNT_INSTEXE_BRANCHMISPREDICT = 0x7
  */
kal_uint32 arm11_pmu_montr_evnt = ARM11_PMU_EVNT_ICACHE_HIT_RATE;


#if defined(ARMEMI_MONTR_EMBEDDED_IN_SWLA)
/* do nothing. */
#else /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */
/**
   * Buffer that record ARM11 events.
   */
ARM11_PMUEVNT_STATISTICS arm11_mon_buf[ARM11_MON_BUF_SIZE];
EMIMON_LOG_T emi_mon_buf[ARM11_MON_BUF_SIZE];
kal_uint32 arm11_mon_buf_idx = 0;
kal_uint32 arm11_mon_log_cnt = 0;
kal_uint32 arm11_mon_log_cnt_overrun = 0;
#endif /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */

#ifdef __MTK_TARGET__
#pragma arm section
#endif /* __MTK_TARGET__ */



/**
  * @brief this function is used to initialize ARM11 PMU by performing the ARM11 PMU event configuration.
  *
  * @remarks function:  
  * @remarks category: 
  * @remarks sub_category:  
  *
  * @return None
  */

#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE_TEST", rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */

int ARM11PMU_init_montr()
{
    unsigned int pmuevnt_cfg;
    unsigned int emievnt_cfg;

    /**
       * Enable MT6276 E1 ARM11 PMU.
       */
#if defined(MT6276)
    *(volatile unsigned int*)(0x610F0000) = 0x00001F00;
#elif defined(MT6256)

#else
#error "NON-supported platform"
#endif


    /**
       * Read/modify/write-back the ARM11 CP15 performance control register.
       */
    pmuevnt_cfg = cp15_GetPerfMonitorControl();
    {
        /**
           * Clear previous event.
           */
        pmuevnt_cfg &= ARM11_PMUEVNT_CNT0_CFG_MASK;
        pmuevnt_cfg &= ARM11_PMUEVNT_CNT1_CFG_MASK;
    
        /**
           * Get profiling events.
           */
        switch(arm11_pmu_montr_evnt)
        {
            case ARM11_PMU_EVNT_ICACHE_HIT_RATE:
                pmuevnt_cfg |= (ARM11_PMUEVNT_ICACHE_MISS << ARM11_PMUEVNT_CNT0_CFG_SHIFT);
                pmuevnt_cfg |= (ARM11_PMUEVNT_INST_EXE << ARM11_PMUEVNT_CNT1_CFG_SHIFT);
                break;
        
            case ARM11_PMU_EVNT_DCACHE_HIT_RATE:
                pmuevnt_cfg |= (ARM11_PMUEVNT_DCACHE_MISS << ARM11_PMUEVNT_CNT0_CFG_SHIFT);
                pmuevnt_cfg |= (ARM11_PMUEVNT_DCACHE_ACES_C << ARM11_PMUEVNT_CNT1_CFG_SHIFT);
                break;

            case ARM11_PMU_EVNT_ICACHEMISS_INSTMICROTLBMISS:
                pmuevnt_cfg |= (ARM11_PMUEVNT_ICACHE_MISS << ARM11_PMUEVNT_CNT0_CFG_SHIFT);
                pmuevnt_cfg |= (ARM11_PMUEVNT_IMICROTLB_MISS << ARM11_PMUEVNT_CNT1_CFG_SHIFT);
                break;
        
            case ARM11_PMU_EVNT_DCACHEMISS_DATAMICROTLBMISS:
                pmuevnt_cfg |= (ARM11_PMUEVNT_DCACHE_MISS << ARM11_PMUEVNT_CNT0_CFG_SHIFT);
                pmuevnt_cfg |= (ARM11_PMUEVNT_DMICROTLB_MISS << ARM11_PMUEVNT_CNT1_CFG_SHIFT);
                break;
    
            case ARM11_PMU_EVNT_DCACHEWRITEBACK_MAINTLBMISS:
                pmuevnt_cfg |= (ARM11_PMUEVNT_DCACHE_WRITEBACK << ARM11_PMUEVNT_CNT0_CFG_SHIFT);
                pmuevnt_cfg |= (ARM11_PMUEVNT_MAINTLB_MISS << ARM11_PMUEVNT_CNT1_CFG_SHIFT);
                break;
        
            case ARM11_PMU_EVNT_EXPEXTDATAACES_WRITEBUFDRAIN:
                pmuevnt_cfg |= (ARM11_PMUEVNT_EXPLICIT_EXTDATA_ACES << ARM11_PMUEVNT_CNT0_CFG_SHIFT);
                pmuevnt_cfg |= (ARM11_PMUEVNT_WRITEBUF_DRAIN << ARM11_PMUEVNT_CNT1_CFG_SHIFT);
                break;

            case ARM11_PMU_EVNT_DCACHEACES_DCACHENONCACHEACES:
                pmuevnt_cfg |= (ARM11_PMUEVNT_DCACHE_ACES_C << ARM11_PMUEVNT_CNT0_CFG_SHIFT);
                pmuevnt_cfg |= (ARM11_PMUEVNT_DCACHE_ACES_CNC << ARM11_PMUEVNT_CNT1_CFG_SHIFT);
                break;

            case ARM11_PMU_EVNT_INSTEXE_BRANCHMISPREDICT:
                pmuevnt_cfg |= (ARM11_PMUEVNT_INST_EXE << ARM11_PMUEVNT_CNT0_CFG_SHIFT);
                pmuevnt_cfg |= (ARM11_PMUEVNT_BRANCH_MISPREDICT << ARM11_PMUEVNT_CNT1_CFG_SHIFT);
                break;
        
            default:
                ASSERT(0);
        }
    }
    cp15_SetPerfMonitorControl(pmuevnt_cfg);


    /**
       * Configure EMI monitor event.
       */
    {
        emievnt_cfg = 0;
        emievnt_cfg &= EMIMON_SEL_RWOP_MASK;
        emievnt_cfg |= (EMIMON_OP_SEL_RW << EMIMON_SEL_RWOP_SHIFT);
        emievnt_cfg &= EMIMON_SEL_SLICE_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_SLICE_OFFSET);
        emievnt_cfg &= EMIMON_SEL_SLICE_ALL_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_SLICE_ALL_OFFSET);
        emievnt_cfg &= EMIMON_SEL_EMICYC_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_EMICYC_OFFSET);
        emievnt_cfg &= EMIMON_SEL_ROW_HIT_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_ROW_HIT_OFFSET);
        emievnt_cfg &= EMIMON_SEL_ROW_START_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_ROW_START_OFFSET);
        emievnt_cfg &= EMIMON_SEL_ROW_CONFLICT_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_ROW_CONFLICT_OFFSET);
        emievnt_cfg &= EMIMON_SEL_INTER_BANK_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_INTER_BANK_OFFSET);
        
        /**
           * We use CNT1 to monitor all transaction type & word cnt for MM.
           */
        emievnt_cfg &= EMIMON_CNT1_SEL_TRANSTYP_MASK;
        emievnt_cfg |= (EMIMON_TRANSTYPE_SEL_INCR48 << EMIMON_CNT1_SEL_TRANSTYP_SHIFT);
        emievnt_cfg &= EMIMON_CNT1_SEL_MASTER_MASK;
        emievnt_cfg |= (EMIMON_MASTER_SEL_MM << EMIMON_CNT1_SEL_MASTER_SHIFT);  
        *EMI_BMEN = emievnt_cfg;

        emievnt_cfg = 0;
        /**
           * We use CNT2 to monitor all transaction type & word cnt for all master excluding dummy read to avoid the result is influenced by HWDCM bugs.
           */
        emievnt_cfg &= EMIMON_CNT2_SEL_TRANSTYP_MASK;
        emievnt_cfg |= (EMIMON_TRANSTYPE_SEL_WRAP48 << EMIMON_CNT2_SEL_TRANSTYP_SHIFT);
        emievnt_cfg &= EMIMON_CNT2_SEL_MASTER_MASK;
        emievnt_cfg |= (EMIMON_MASTER_SEL_ALL << EMIMON_CNT2_SEL_MASTER_SHIFT);

        /**
           * We set CNT1~9 to monitor different transaction type for MM.
           */
        emievnt_cfg &= EMIMON_CNT3_SEL_TRANSTYP_MASK;
        emievnt_cfg |= (EMIMON_TRANSTYPE_SEL_INCR28 << EMIMON_CNT3_SEL_TRANSTYP_SHIFT);        
        emievnt_cfg &= EMIMON_CNT3_SEL_MASTER_MASK;
        emievnt_cfg |= (EMIMON_MASTER_SEL_MM << EMIMON_CNT3_SEL_MASTER_SHIFT);
        *EMI_MSEL = emievnt_cfg;

        emievnt_cfg = 0;
        emievnt_cfg &= EMIMON_CNT4_SEL_TRANSTYP_MASK;
        emievnt_cfg |= (EMIMON_TRANSTYPE_SEL_WRAP28 << EMIMON_CNT4_SEL_TRANSTYP_SHIFT);
        emievnt_cfg &= EMIMON_CNT4_SEL_MASTER_MASK;
        emievnt_cfg |= (EMIMON_MASTER_SEL_MM << EMIMON_CNT4_SEL_MASTER_SHIFT);        
        emievnt_cfg &= EMIMON_CNT5_SEL_TRANSTYP_MASK;
        emievnt_cfg |= (EMIMON_TRANSTYPE_SEL_INCR11 << EMIMON_CNT5_SEL_TRANSTYP_SHIFT);        
        emievnt_cfg &= EMIMON_CNT5_SEL_MASTER_MASK;
        emievnt_cfg |= (EMIMON_MASTER_SEL_MM << EMIMON_CNT5_SEL_MASTER_SHIFT);        
        *EMI_MSEL2 = emievnt_cfg;

        emievnt_cfg = 0;
        emievnt_cfg &= EMIMON_CNT6_SEL_TRANSTYP_MASK;
        emievnt_cfg |= (EMIMON_TRANSTYPE_SEL_INCR12 << EMIMON_CNT6_SEL_TRANSTYP_SHIFT);
        emievnt_cfg &= EMIMON_CNT6_SEL_MASTER_MASK;
        emievnt_cfg |= (EMIMON_MASTER_SEL_MM << EMIMON_CNT6_SEL_MASTER_SHIFT);        
        emievnt_cfg &= EMIMON_CNT7_SEL_TRANSTYP_MASK;
        emievnt_cfg |= (EMIMON_TRANSTYPE_SEL_INCR14 << EMIMON_CNT7_SEL_TRANSTYP_SHIFT);        
        emievnt_cfg &= EMIMON_CNT7_SEL_MASTER_MASK;
        emievnt_cfg |= (EMIMON_MASTER_SEL_MM << EMIMON_CNT7_SEL_MASTER_SHIFT);        
        *EMI_MSEL3 = emievnt_cfg;

        emievnt_cfg = 0;
        emievnt_cfg &= EMIMON_CNT8_SEL_TRANSTYP_MASK;
        emievnt_cfg |= (EMIMON_TRANSTYPE_SEL_INCR18 << EMIMON_CNT8_SEL_TRANSTYP_SHIFT);        
        emievnt_cfg &= EMIMON_CNT8_SEL_MASTER_MASK;
        emievnt_cfg |= (EMIMON_MASTER_SEL_MM << EMIMON_CNT8_SEL_MASTER_SHIFT);        
        emievnt_cfg &= EMIMON_CNT9_SEL_TRANSTYP_MASK;
        emievnt_cfg |= (EMIMON_TRANSTYPE_SEL_WRAP48 << EMIMON_CNT9_SEL_TRANSTYP_SHIFT);        
        emievnt_cfg &= EMIMON_CNT9_SEL_MASTER_MASK;
        emievnt_cfg |= (EMIMON_MASTER_SEL_MM << EMIMON_CNT9_SEL_MASTER_SHIFT);        
        *EMI_MSEL4 = emievnt_cfg;                        
    }

    return 0;	
}


#ifdef __MTK_TARGET__
#pragma arm section
#endif /* __MTK_TARGET__ */



/**
  * @brief this function is used to perform the start the ARM11 PMU.
  *
  * @remarks function:  
  * @remarks category: 
  * @remarks sub_category:  
  *
  * @return None
  */


#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE_TEST", rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */


int ARM11PMU_start_montr(void)
{
    unsigned int pmuevnt_cfg;

    /**
       * Read/modify/write-back the ARM11 CP15 performance control register.
       */
    pmuevnt_cfg = cp15_GetPerfMonitorControl();
    {
        /**
           * Configure PMU cfg value.
           */
        pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_ALLCNT_EN_MASK) | (0x1 << ARM11_PMUEVNT_ALLCNT_EN_SHIFT);    
    }
    cp15_SetPerfMonitorControl(pmuevnt_cfg);

    /**
       * Start EMI monitor.
       */
    __EMIMON_ADV_START_CNT();

    return 0;
}

#ifdef __MTK_TARGET__
#pragma arm section
#endif /* __MTK_TARGET__ */



/**
  * @brief this function is used to perform the stop and get logs of ARM11 PMU.
  *
  * @remarks function:  MMU
  * @remarks category: Protect
  * @remarks sub_category:  
  *
  * @return None
  */


#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE_TEST", rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */

#if defined(ARMEMI_MONTR_EMBEDDED_IN_SWLA)
int ARM11PMU_stop_montr_with_log(ARM11_PMUEVNT_STATISTICS *arm11_pmu_log, EMIMON_LOG_T *emi_log)
#else
int ARM11PMU_stop_montr_with_log(void)
#endif /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */
{
    /**
       * Stop PMU.
       */
    unsigned int pmuevnt_cfg;
    ARM11_PMUEVNT_STATISTICS *arm11_pmu_sta;
    EMIMON_LOG_T *emi_mon_sta;

    /**
       * Pause ARM11 monitor by read/modify/write-back the ARM11 CP15 performance control register.
       */
    pmuevnt_cfg = cp15_GetPerfMonitorControl();
    {
        /**
           * Configure PMU cfg value.
           */
        pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_ALLCNT_EN_MASK) | (0x0 << ARM11_PMUEVNT_ALLCNT_EN_SHIFT);    
    }
    cp15_SetPerfMonitorControl(pmuevnt_cfg);

    /**
       * Pause EMI monitor.
       */
    __EMIMON_ADV_PAUSE_CNT();

    /**
       * Get monitor address.
       */
#if defined(ARMEMI_MONTR_EMBEDDED_IN_SWLA)       
    arm11_pmu_sta = arm11_pmu_log;
    emi_mon_sta = emi_log;
#else /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */
    arm11_pmu_sta = &(arm11_mon_buf[arm11_mon_buf_idx]);
    emi_mon_sta = &(emi_mon_buf[arm11_mon_buf_idx]);
#endif /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */

    /**
       * Get PMU statistics.
       */
    switch(arm11_pmu_montr_evnt)
    {
        case ARM11_PMU_EVNT_ICACHE_HIT_RATE:
            arm11_pmu_sta->arm11_pmuevnt_core_cyccnt = cp15_GetCycCntRegister();
            arm11_pmu_sta->arm11_pmuevnt_icache_miss_cnt = cp15_GetCountRegister0();
            arm11_pmu_sta->arm11_pmuevnt_inst_exe_cnt = cp15_GetCountRegister1();
            break;
    
        case ARM11_PMU_EVNT_DCACHE_HIT_RATE:
            arm11_pmu_sta->arm11_pmuevnt_core_cyccnt = cp15_GetCycCntRegister();        	
            arm11_pmu_sta->arm11_pmuevnt_dcache_miss_cnt = cp15_GetCountRegister0();
            arm11_pmu_sta->arm11_pmuevnt_dcache_aces_c_cnt = cp15_GetCountRegister1();
            break;

        case ARM11_PMU_EVNT_ICACHEMISS_INSTMICROTLBMISS:
            //arm11_pmu_sta->arm11_pmuevnt_core_cyccnt = cp15_GetCycCntRegister();        	
            //arm11_pmu_sta->arm11_pmuevnt_icache_miss_cnt = cp15_GetCountRegister0();
            //arm11_pmu_sta->arm11_pmuevnt_imicrotlb_miss_cnt = cp15_GetCountRegister1();
            break;
    
        case ARM11_PMU_EVNT_DCACHEMISS_DATAMICROTLBMISS:
            //arm11_pmu_sta->arm11_pmuevnt_core_cyccnt = cp15_GetCycCntRegister();        	
            //arm11_pmu_sta->arm11_pmuevnt_dcache_miss_cnt = cp15_GetCountRegister0();
            //arm11_pmu_sta->arm11_pmuevnt_dmicrotlb_miss_cnt = cp15_GetCountRegister1();
            break;

        case ARM11_PMU_EVNT_DCACHEWRITEBACK_MAINTLBMISS:
            //arm11_pmu_sta->arm11_pmuevnt_core_cyccnt = cp15_GetCycCntRegister();        	
            //arm11_pmu_sta->arm11_pmuevnt_dcache_writeback_cnt = cp15_GetCountRegister0();
            //arm11_pmu_sta->arm11_pmuevnt_maintlb_miss_cnt = cp15_GetCountRegister1();
            break;
    
        case ARM11_PMU_EVNT_EXPEXTDATAACES_WRITEBUFDRAIN:
            //arm11_pmu_sta->arm11_pmuevnt_core_cyccnt = cp15_GetCycCntRegister();        	
            //arm11_pmu_sta->arm11_pmuevnt_explicit_extdata_aces_cnt = cp15_GetCountRegister0();
            //arm11_pmu_sta->arm11_pmuevnt_writebuf_drain_cnt = cp15_GetCountRegister1();
            break;

        case ARM11_PMU_EVNT_DCACHEACES_DCACHENONCACHEACES:
            //arm11_pmu_sta->arm11_pmuevnt_core_cyccnt = cp15_GetCycCntRegister();        	
            //arm11_pmu_sta->arm11_pmuevnt_dcache_aces_c_cnt = cp15_GetCountRegister0();
            //arm11_pmu_sta->arm11_pmuevnt_dcache_aces_cnc_cnt = cp15_GetCountRegister1();
            break;

        case ARM11_PMU_EVNT_INSTEXE_BRANCHMISPREDICT:
            //arm11_pmu_sta->arm11_pmuevnt_core_cyccnt = cp15_GetCycCntRegister();        	
            //arm11_pmu_sta->arm11_pmuevnt_inst_exe_cnt = cp15_GetCountRegister0();
            //arm11_pmu_sta->arm11_pmuevnt_branch_mispredict_cnt = cp15_GetCountRegister1();
            break;

        default:
            ASSERT(0);
    }

    /**
       * Get emi montr counter.
       */
    {   
    	  kal_uint32 emievnt_cfg = 0;
    	  
        emi_mon_sta->emi_total_fixed_cyccnt = *EMI_BCNT;
        /* avoid using TACT and WACT to prevent getting dummy read's transaction. */
        //emi_mon_sta->emi_total_trans_cnt = *EMI_TACT;
        //emi_mon_sta->emi_total_dword_cnt = *EMI_WACT;
        emi_mon_sta->emi_total_trans_cnt = *EMI_TSCT2;
        emi_mon_sta->emi_total_dword_cnt = *EMI_WSCT2;
        emi_mon_sta->emi_total_busy_cyccnt = *EMI_BACT;    

        emi_mon_sta->emi_massel_busy_cyccnt = *EMI_BSCT;
        emi_mon_sta->emi_massel_trans_cnt = *EMI_TSCT;
        emi_mon_sta->emi_massel_dword_cnt = *EMI_WSCT;

        emi_mon_sta->emi_mastransel_trans_cnt_wrap48 = *EMI_TTYPE1;
        emi_mon_sta->emi_mastransel_trans_cnt_incr48 = *EMI_TTYPE9;
        emi_mon_sta->emi_mastransel_trans_cnt_wrap28 = *EMI_TTYPE3;
        emi_mon_sta->emi_mastransel_trans_cnt_incr28 = *EMI_TTYPE4;
        emi_mon_sta->emi_mastransel_trans_cnt_incr11 = *EMI_TTYPE5;
        emi_mon_sta->emi_mastransel_trans_cnt_incr12 = *EMI_TTYPE6;
        emi_mon_sta->emi_mastransel_trans_cnt_incr14 = *EMI_TTYPE7;
        emi_mon_sta->emi_mastransel_trans_cnt_incr18 = *EMI_TTYPE8;

        /**
          * Switch to EMI status counter mode.
          */
        emievnt_cfg = *EMI_BMEN;
        /* do not change slice mask. */
        emievnt_cfg &= EMIMON_SEL_SLICE_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_SLICE_OFFSET);
        emievnt_cfg &= EMIMON_SEL_SLICE_ALL_MASK;
        emievnt_cfg |= (0x1 << EMIMON_SEL_SLICE_ALL_OFFSET);
        emievnt_cfg &= EMIMON_SEL_EMICYC_MASK;
        emievnt_cfg |= (0x1 << EMIMON_SEL_EMICYC_OFFSET);
        emievnt_cfg &= EMIMON_SEL_ROW_HIT_MASK;
        emievnt_cfg |= (0x1 << EMIMON_SEL_ROW_HIT_OFFSET);
        emievnt_cfg &= EMIMON_SEL_ROW_START_MASK;
        emievnt_cfg |= (0x1 << EMIMON_SEL_ROW_START_OFFSET);
        emievnt_cfg &= EMIMON_SEL_ROW_CONFLICT_MASK;
        emievnt_cfg |= (0x1 << EMIMON_SEL_ROW_CONFLICT_OFFSET);
        emievnt_cfg &= EMIMON_SEL_INTER_BANK_MASK;
        emievnt_cfg |= (0x1 << EMIMON_SEL_INTER_BANK_OFFSET);
        *EMI_BMEN = emievnt_cfg;

        emi_mon_sta->emi_total_bus_cyccnt = *EMI_TSCT;
        emi_mon_sta->emi_total_slice_cnt = *EMI_TACT;
        emi_mon_sta->emi_total_row_hit_cnt = *EMI_WACT;
        emi_mon_sta->emi_total_row_start_cnt = *EMI_WSCT;
        emi_mon_sta->emi_total_row_conflict_cnt = *EMI_BACT;
        emi_mon_sta->emi_total_inter_bank_cnt = *EMI_BSCT;                                

        /**
          * Switch back to original EMI BW counter mode.
          */
        emievnt_cfg = *EMI_BMEN;
        emievnt_cfg &= EMIMON_SEL_SLICE_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_SLICE_OFFSET);
        emievnt_cfg &= EMIMON_SEL_SLICE_ALL_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_SLICE_ALL_OFFSET);
        emievnt_cfg &= EMIMON_SEL_EMICYC_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_EMICYC_OFFSET);
        emievnt_cfg &= EMIMON_SEL_ROW_HIT_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_ROW_HIT_OFFSET);
        emievnt_cfg &= EMIMON_SEL_ROW_START_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_ROW_START_OFFSET);
        emievnt_cfg &= EMIMON_SEL_ROW_CONFLICT_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_ROW_CONFLICT_OFFSET);
        emievnt_cfg &= EMIMON_SEL_INTER_BANK_MASK;
        emievnt_cfg |= (0x0 << EMIMON_SEL_INTER_BANK_OFFSET);        
        *EMI_BMEN = emievnt_cfg;        
    }
    
    /**
       * Increase the monitor index.
       */
#if defined(ARMEMI_MONTR_EMBEDDED_IN_SWLA)       
    /* do nothing. */
#else /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */
    ARM11_MON_INC_IDX(arm11_mon_buf_idx);
#endif /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */
       

    /**
       * Reset all PMU counters.
       */
    pmuevnt_cfg = cp15_GetPerfMonitorControl();
    {
        /**
           * Configure PMU cfg value.
           */
        pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_CORECYCCNT_RESET_MASK) | (0x1 << ARM11_PMUEVNT_CORECYCCNT_RESET_SHIFT);    
        pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_ALLCNT_EN_MASK) | (0x1 << ARM11_PMUEVNT_EVNT01CNT_RESET_SHIFT);    
    }
    cp15_SetPerfMonitorControl(pmuevnt_cfg);

    /**
       * We explicitly set the reset bit back to 0 since ARM11 TRM does not state the programming sequence clearly.
       */
    pmuevnt_cfg = cp15_GetPerfMonitorControl();
    {
        /**
           * Configure PMU cfg value.
           */
        pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_CORECYCCNT_RESET_MASK) | (0x0 << ARM11_PMUEVNT_CORECYCCNT_RESET_SHIFT);    
        pmuevnt_cfg = (pmuevnt_cfg & ARM11_PMUEVNT_ALLCNT_EN_MASK) | (0x0 << ARM11_PMUEVNT_EVNT01CNT_RESET_SHIFT);    
    }
    cp15_SetPerfMonitorControl(pmuevnt_cfg);

    /**
       * Reset EMI monitor counter.
       */
    __EMIMON_ADV_STOP_AND_CLR_CNT();

    /**
       * Increase log counter.
       */
#if defined(ARMEMI_MONTR_EMBEDDED_IN_SWLA)       
    /* do nothing. */
#else /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */
    if(arm11_mon_log_cnt < 0xFFFFFFF)
    {
        arm11_mon_log_cnt++;
    }
    else
    {
        arm11_mon_log_cnt = 0;    
        arm11_mon_log_cnt_overrun = 1;
    }
#endif /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */
       

    return 0;
}

#ifdef __MTK_TARGET__
#pragma arm section
#endif /* __MTK_TARGET__ */



#endif /* MT6276 && __MT6276_CONCURRENCY_TEST__ */

#endif /* __MTK_TARGET__ */



