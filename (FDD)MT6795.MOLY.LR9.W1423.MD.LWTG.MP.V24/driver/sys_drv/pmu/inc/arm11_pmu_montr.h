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
 *   bus_monitor.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file for BUS monitor control.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__MT6276_CONCURRENCY_TEST__) || defined(__SLA_INST_COUNT_SUPPORT__) || defined(__MT6256_CONCURRENCY_TEST__) 

#if defined(MT6276) || defined(MT6256)
//ok
#else
#error "NON-SUPPORTED PLATFORM"
#endif

#if !defined(__ARM11_PMU_MONITOR_H__)
#define __ARM11_PMU_MONITOR_H__

/*****************************************
   *
   * High-level feature option.
   *
   ****************************************/

#define __ARM11_MONITOR_SUPPORT__

#define ARMEMI_MONTR_EMBEDDED_IN_SWLA


/*****************************************
   *
   * Include files.
   *
   ****************************************/

#include "kal_public_api.h" //MSBB change #include "kal_release.h"

#if defined(MT6276)
#include "emi_mt6276_montr.h"
#elif defined(MT6256)
#include "emi_mt6256_montr.h"
#endif

/*****************************************
   *
   * Constants
   *
   ****************************************/

#define ARM11_MONITOR_IRQ_NUM 13
#define ARM11_MONITOR_NUM 1000
#define ARM11_MONITOR_IDX_INC(idx) (idx = (idx+1)%ARM11_MONITOR_NUM)

/**
  * ARM11 system control coprocessor AUX register bit definition.
  */
#define ARM11_SYSCTRL_COPRO_AUXCTRLREG_FORCE_SPECULAR_DIS_MASK            0xBFFFFFFF
#define ARM11_SYSCTRL_COPRO_AUXCTRLREG_FORCE_SPECULAR_DIS_SHIFT           30
#define ARM11_SYSCTRL_COPRO_AUXCTRLREG_BRANCH_FOLD_DIS_MASK               0xDFFFFFFF
#define ARM11_SYSCTRL_COPRO_AUXCTRLREG_BRANCH_FOLD_DIS_SHIFT              29
#define ARM11_SYSCTRL_COPRO_AUXCTRLREG_INST_PREFETCH_HALT_DIS_MASK        0xEFFFFFFF
#define ARM11_SYSCTRL_COPRO_AUXCTRLREG_INST_PREFETCH_HALT_DIS_SHIFT       28
#define ARM11_SYSCTRL_COPRO_AUXCTRLREG_BLOCK_TRANS_CACHE_DIS_MASK         0xFFFFFFDF
#define ARM11_SYSCTRL_COPRO_AUXCTRLREG_BLOCK_TRANS_CACHE_DIS_SHIFT        5
#define ARM11_SYSCTRL_COPRO_AUXCTRLREG_STATIC_BRANCH_PREDICT_EN_MASK      0xFFFFFFFB
#define ARM11_SYSCTRL_COPRO_AUXCTRLREG_STATIC_BRANCH_PREDICT_EN_SHIFT     2
#define ARM11_SYSCTRL_COPRO_AUXCTRLREG_DYNAMIC_BRANCH_PREDICT_EN_MASK     0xFFFFFFFD
#define ARM11_SYSCTRL_COPRO_AUXCTRLREG_DYNAMIC_BRANCH_PREDICT_EN_SHIFT    1
#define ARM11_SYSCTRL_COPRO_AUXCTRLREG_RETURN_STACK_EN_MASK               0xFFFFFFFE
#define ARM11_SYSCTRL_COPRO_AUXCTRLREG_RETURN_STACK_EN_SHIFT              0

/**
  * ARM11 system control coprocessor AUX register bit definition.
  */
#define ARM11_PMUEVNT_RETURN_STACK_MISPREDICT                             0x26
#define ARM11_PMUEVNT_RETURN_STACK_PREDICT                                0x25
#define ARM11_PMUEVNT_RETURN_STACK_TTPOP                                  0x24
#define ARM11_PMUEVNT_RETURN_STACK_TTPUSH                                 0x23
#define ARM11_PMUEVNT_WRITEBUF_DRAIN                                      0x12
#define ARM11_PMUEVNT_LSU_STALL                                           0x11
#define ARM11_PMUEVNT_EXPLICIT_EXTDATA_ACES                               0x10
#define ARM11_PMUEVNT_MAINTLB_MISS                                        0xF
#define ARM11_PMUEVNT_SW_CHANGE_PC                                        0xD
#define ARM11_PMUEVNT_DCACHE_WRITEBACK                                    0xC
#define ARM11_PMUEVNT_DCACHE_MISS                                         0xB
#define ARM11_PMUEVNT_DCACHE_ACES_CNC                                     0xA
#define ARM11_PMUEVNT_DCACHE_ACES_C                                       0x9
#define ARM11_PMUEVNT_INST_EXE                                            0x7
#define ARM11_PMUEVNT_BRANCH_MISPREDICT                                   0x6
#define ARM11_PMUEVNT_BRANCH_EXE                                          0x5
#define ARM11_PMUEVNT_DMICROTLB_MISS                                      0x4
#define ARM11_PMUEVNT_IMICROTLB_MISS                                      0x3
#define ARM11_PMUEVNT_DATA_DEPENDENCY_STALL                               0x2
#define ARM11_PMUEVNT_INST_STALL                                          0x1
#define ARM11_PMUEVNT_ICACHE_MISS                                         0x0

#define ARM11_PMUEVNT_CNT0_CFG_MASK                                       0xF00FFFFF
#define ARM11_PMUEVNT_CNT0_CFG_SHIFT                                      20
#define ARM11_PMUEVNT_CNT1_CFG_MASK                                       0xFFF00FFF
#define ARM11_PMUEVNT_CNT1_CFG_SHIFT                                      12
#define ARM11_PMUEVNT_CORECYCCNT_RESET_MASK                               0xFFFFFFFB
#define ARM11_PMUEVNT_CORECYCCNT_RESET_SHIFT                              2
#define ARM11_PMUEVNT_EVNT01CNT_RESET_MASK                                0xFFFFFFFD
#define ARM11_PMUEVNT_EVNT01CNT_RESET_SHIFT                               1
#define ARM11_PMUEVNT_ALLCNT_EN_MASK                                      0xFFFFFFFE
#define ARM11_PMUEVNT_ALLCNT_EN_SHIFT                                     0

#define ARM11_DMA_CTRL_REG_TARGET_TCM_MASK                                0x7FFFFFFF
#define ARM11_DMA_CTRL_REG_TARGET_TCM_SHIFT                               31
#define ARM11_DMA_CTRL_REG_TRANSFER_DIR_MASK                              0xBFFFFFFF
#define ARM11_DMA_CTRL_REG_TRANSFER_DIR_SHIFT                             30
#define ARM11_DMA_CTRL_REG_COMPLETE_IRQ_MASK                              0xDFFFFFFF
#define ARM11_DMA_CTRL_REG_COMPLETE_IRQ_SHIFT                             29
#define ARM11_DMA_CTRL_REG_ERROR_IRQ_MASK                                 0xEFFFFFFF
#define ARM11_DMA_CTRL_REG_ERROR_IRQ_SHIFT                                28
#define ARM11_DMA_CTRL_REG_STRIDE_SIZE_MASK                               0xFFF000FF
#define ARM11_DMA_CTRL_REG_STRIDE_SIZE_SHIFT                              8
#define ARM11_DMA_CTRL_REG_TRANSACTION_SIZE_MASK                          0xFFFFFFFC
#define ARM11_DMA_CTRL_REG_TRANSACTION_SIZE_SHIFT                         0


/*****************************************
   *
   * Enum
   *
   ****************************************/

enum { 
    ARM11_PMU_EVNT_ICACHE_HIT_RATE = 0x0, 
    ARM11_PMU_EVNT_DCACHE_HIT_RATE = 0x1, 
    ARM11_PMU_EVNT_ICACHEMISS_INSTMICROTLBMISS = 0x2,
    ARM11_PMU_EVNT_DCACHEMISS_DATAMICROTLBMISS = 0x3,
    ARM11_PMU_EVNT_DCACHEWRITEBACK_MAINTLBMISS = 0x4,
    ARM11_PMU_EVNT_EXPEXTDATAACES_WRITEBUFDRAIN = 0x5,
    ARM11_PMU_EVNT_DCACHEACES_DCACHENONCACHEACES = 0x6,
    ARM11_PMU_EVNT_INSTEXE_BRANCHMISPREDICT = 0x7
    };


/*****************************************
   *
   * Data structure.
   *
   ****************************************/
 
typedef struct
{
    int arm11_sysctrl_dynamic_branch_en;
    int arm11_sysctrl_static_branch_en;
    int arm11_sysctrl_return_stack_en;
    int arm11_sysctrl_branch_folding_en;
    int arm11_sysctrl_force_speculative_en;
    int arm11_sysctrl_prefetch_halting_en;
    int arm11_sysctrl_block_transfer_cache_en;   
} ARM11_SYSCTRL_COPRO_CONFIG;


typedef struct
{
    unsigned int arm11_pmuevnt_core_cyccnt;
    //unsigned int arm11_pmuevnt_return_stack_mispredict_cnt;
    //unsigned int arm11_pmuevnt_return_stack_predict_cnt;
    //unsigned int arm11_pmuevnt_return_stack_ttpop_cnt;
    //unsigned int arm11_pmuevnt_return_stack_ttpush_cnt;
    //unsigned int arm11_pmuevnt_writebuf_drain_cnt;
    //unsigned int arm11_pmuevnt_loadstore_stall_cyccnt;   
    //unsigned int arm11_pmuevnt_explicit_extdata_aces_cnt;   
    //unsigned int arm11_pmuevnt_maintlb_miss_cnt;   
    //unsigned int arm11_pmuevnt_sw_change_pc_cnt;   
    //unsigned int arm11_pmuevnt_dcache_writeback_cnt;   
    unsigned int arm11_pmuevnt_dcache_miss_cnt;   
    //unsigned int arm11_pmuevnt_dcache_aces_cnc_cnt;   
    unsigned int arm11_pmuevnt_dcache_aces_c_cnt;   
    unsigned int arm11_pmuevnt_inst_exe_cnt;   
   // unsigned int arm11_pmuevnt_branch_mispredict_cnt;   
    //unsigned int arm11_pmuevnt_branch_exe_cnt;   
    //unsigned int arm11_pmuevnt_dmicrotlb_miss_cnt;   
    //unsigned int arm11_pmuevnt_imicrotlb_miss_cnt;   
    //unsigned int arm11_pmuevnt_data_dependency_stall_cyccnt;   
    //unsigned int arm11_pmuevnt_inst_stall_cyccnt;   
    unsigned int arm11_pmuevnt_icache_miss_cnt;  
    
    /**
      * Record the irq pending status.
      */     
    //unsigned int arm11_pmuevnt_pending_status;
} ARM11_PMUEVNT_STATISTICS;


/*****************************************
   *
   * Extern functions.
   *
   ****************************************/

extern int ARM11PMU_init_montr(void);
extern int ARM11PMU_start_montr(void);

#if defined(__SLA_INST_COUNT_SUPPORT__)
extern int ARM11PMU_stop_montr_with_log(ARM11_PMUEVNT_STATISTICS *arm11_pmu_log);
#elif defined(ARMEMI_MONTR_EMBEDDED_IN_SWLA)
extern int ARM11PMU_stop_montr_with_log(ARM11_PMUEVNT_STATISTICS *arm11_pmu_log, EMIMON_LOG_T *emi_log);
#else
extern int ARM11PMU_stop_montr_with_log(void);
#endif /* ARMEMI_MONTR_EMBEDDED_IN_SWLA */


/**
   * cp15 operation.
   */
extern unsigned int cp15_GetPerfMonitorControl(void);
extern void cp15_SetPerfMonitorControl(unsigned int u4PMC);
extern unsigned int cp15_GetCountRegister0(void);
extern void cp15_SetCountRegister0(unsigned int u4Val);
extern unsigned int cp15_GetCountRegister1(void);
extern void cp15_SetCountRegister1(unsigned int u4Val);
extern unsigned int cp15_GetCycCntRegister(void);


/*******************************************************************************
   *
   * Exposed global variables.
   *
   *******************************************************************************/


#endif  /* !__ARM11_PMU_MONITOR_H__ */

#endif /* MT6276 && __MT6276_CONCURRENCY_TEST__ */

