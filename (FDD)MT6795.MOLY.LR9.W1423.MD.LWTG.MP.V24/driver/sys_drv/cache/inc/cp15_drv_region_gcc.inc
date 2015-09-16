/******************************************************************************* 
*  Copyright Statement: 
*  -------------------- 
*  This software is protected by Copyright and the information contained 
*  herein is confidential. The software may not be copied and the information 
*  contained herein may not be used or disclosed except with the written 
*  permission of MediaTek Inc. (C) 2001 
* 
*******************************************************************************/ 
 
/******************************************************************************* 
 * 
 * Filename: 
 * --------- 
 *   cp15_drv_region.inc
 * 
 * Project: 
 * -------- 
 *   MAUI 
 * 
 * Description: 
 * ------------ 
 *   CP15 API memory placement definition
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
 * removed!
 *
 *
 *------------------------------------------------------------------------------ 
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================ 
 ****************************************************************************/ 
@/******************************************************************************/
@ *  Common region pragma settings
@ ******************************************************************************/
    @ COMMON
    .macro INSTRUCTION_TCM
    .section "INTSRAM_ROCODE","ax"
    .endm
    
    @ COMMON
    .macro DATA_TCM_ZI 
    .section "INTSRAM_ZI","w", %nobits
    .endm
    
    @ COMMON
    .macro DATA_TCM_RW 
    .section "INTSRAM_RW","w", %progbits
    .endm
    
    @ COMMON
    .macro DEFAULT_CODE_REGION 
    .text
    .endm
    
    @ COMMON
    @ CACHED_EXTSRAM_RW 
    .macro DEFAULT_RWDATA_REGION 
    .section ".data","w", %progbits
    .endm
    
    @ COMMON
    .macro DEFAULT_ZIDATA_REGION 
    .section ".bss","w", %nobits
    .endm
    
    @ COMMON
    .macro NONCACHED_ZIDATA_REGION
    .section "NONCACHEDZI","w", %nobits
    .endm
    
@/******************************************************************************/
@ *  Placement Settings By Project
@ ******************************************************************************/
#if defined(MT6280) || (defined(MT6583) && defined(__MD1__))
    @/************************/
    @ * Data Placement       *
    @ ************************/
    .macro CACHE_LINE_NR_PLACEMENT @ MT6280
    DATA_TCM_RW
    .endm

    .macro CACHE_LINE_NR_PER_WAY_PLACEMENT @ MT6280
    DATA_TCM_RW
    .endm

#if defined(MT6280) && defined(__MODEM_CARD__)
@ Special code for MT6280 DataCard SW running on WIFI-router chips    
    .macro COPRO_WFI_FLAG_PLACEMENT @ MT6280
    NONCACHED_ZIDATA_REGION
    .endm
#endif /* MT6280 && __MODEM_CARD__ */
    
    @/************************/
    @ * Function Placement   *
    @ ************************/  
    .macro CP15_ENABLE_MPU_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_DISABLE_MPU_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_ENABLE_ALIGNMENT_FAULT_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_DISABLE_ALIGNMENT_FAULT_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_ABTCM_SELECT_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_BTCM_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_ATCM_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_MPU_SET_RGN_INDEX_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_MPU_SET_RGN_ADDR_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_MPU_SET_RGN_ACCCTRL_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_MPU_SET_RGN_SIZE_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_MPU_SET_RGN_ENABLE_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_MPU_SET_SUBREGION_DISABLE_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_ICACHE_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_DISABLE_ICACHE_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_DATA_SYNCHRONIZATION_BARRIER_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INST_SYNCHRONIZATION_BARRIER_PLACEMENT @ MT6280
    INSTRUCTION_TCM
    .endm
 
    .macro CP15_INVALIDATE_ICACHE_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_INVALIDATE_ICACHE_SINGLE_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_INVALIDATE_ICACHE_REGION_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_IS_ICACHE_ENABLED_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DRAIN_WRITE_BUFFER_PLACEMENT @ MT6280
    INSTRUCTION_TCM
    .endm
 
    .macro CP15_ENABLE_DCACHE_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_DISABLE_DCACHE_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_INVALIDATE_DCACHE_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_INVALIDATE_DCACHE_SINGLE_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_CLEAN_DCACHE_SINGLE_PLACEMENT @ MT6280
    INSTRUCTION_TCM
    .endm
 
    .macro CP15_INVALIDATE_DCACHE_REGION_PLACEMENT @ MT6280
    INSTRUCTION_TCM
    .endm

    .macro CP15_CLEAN_DCACHE_REGION_PLACEMENT @ MT6280
    INSTRUCTION_TCM
    .endm

    .macro CP15_CLEAN_AND_INVALIDATE_DCACHE_REGION_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_DCACHE_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_IS_DCACHE_ENABLED_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_AND_INVALIDATE_DCACHE_BY_SETWAY_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_ALL_DCACHE_BY_SETWAY_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_AND_INVALIDATE_ALL_DCACHE_BY_SETWAY_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_READ_DFSR_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_READ_FAR_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_READ_IFSR_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_READ_IFAR_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_ENTER_LOW_PWR_STATE_PLACEMENT @ MT6280
    INSTRUCTION_TCM
    .endm

    .macro CP15_DISABLE_ATCMRMW_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DISABLE_BTCMRMW_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DISABLE_LIL_STLDM_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_UNDEF_DIV_BY_ZERO_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_MPU_GET_RBAR_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_MPU_GET_RACR_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_MPU_GET_RSER_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DATA_MEMORY_BARRIER_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_SWITCH_VECTOR_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_SET_BP_POLICY_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_READ_ICACHE_INFO_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
    
    .macro CP15_READ_DCACHE_INFO_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
    
    .macro CP15_WRITE_CONTEXT_ID_PLACEMENT @ MT6280
    INSTRUCTION_TCM
    .endm
    
    .macro CP15_READ_CONTEXT_ID_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm    
    
    .macro CP15_PMU_READ_CONTROL_REGISTER_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PMU_WRITE_CONTROL_REGISTER_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PMU_WRITE_COUNTER_ENABLE_SET_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PMU_READ_COUNTER_ENABLE_SET_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PMU_WRITE_COUNTER_ENABLE_CLEAR_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PMU_READ_COUNTER_OVERFLOW_STATUS_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PMU_WRITE_EVENT_SELECTION_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PMU_READ_CYCLE_COUNTER_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
    
    .macro CP15_PMU_WRITE_CYCLE_COUNTER_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PMU_READ_EVENT_COUNTER_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PMU_WRITE_EVENT_COUNTER_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm

#if defined(MT6280) && defined(__MODEM_CARD__)
@ Special code for MT6280 DataCard SW running on WIFI-router chips        
    .macro CP15_ARM_WFI_LOOP_PLACEMENT @ MT6280
    DEFAULT_CODE_REGION
    .endm
#endif /* MT6280 && __MODEM_CARD__ */
    
    @/***************************/
    @ * End of MT6280 Placement *
    @ ***************************/
#elif (defined(MT6583) && defined(__MD2__))
    @/************************/
    @ * Data Placement       *
    @ ************************/
    .macro CACHE_LINE_NR_PLACEMENT @ MT6583_MD2
    DATA_TCM_RW
    .endm

    .macro CACHE_LINE_NR_PER_WAY_PLACEMENT @ MT6583_MD2
    DATA_TCM_RW
    .endm
    
    @/************************/
    @ * Function Placement   *
    @ ************************/
    .macro CP15_READ_CACHE_TYPE_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm
    
    .macro CP15_ENABLE_ICACHE_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DISABLE_ICACHE_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INVALIDATE_ICACHE_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INVALIDATE_ICACHE_SINGLE_PLACEMENT @ MT6583_MD2
    INSTRUCTION_TCM
    .endm

    .macro CP15_ENABLE_DCACHE_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DISABLE_DCACHE_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INVALIDATE_DCACHE_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INVALIDATE_DCACHE_SINGLE_PLACEMENT @ MT6583_MD2
    INSTRUCTION_TCM
    .endm

    .macro CP15_CLEAN_DCACHE_SINGLE_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DRAIN_WRITE_BUFFER_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_READ_TCM_STATUS_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_READ_ITCM_REGION_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_READ_DTCM_REGION_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_ITCM_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_DTCM_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_WRITE_TBBR_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm
    
    .macro CP15_READ_TBBR_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_MMU_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DISABLE_MMU_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_READ_DOMAIN_ACCESS_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_WRITE_DOMAIN_ACCESS_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_READ_IFSR_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_READ_DFSR_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_READ_FAR_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INVALIDATE_TLB_SINGLE_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INVALIDATE_TLB_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_ROM_PROTECT_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DISABLE_ROM_PROTECT_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_SYS_PROTECT_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DISABLE_SYS_PROTECT_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_ALIGNMENT_FAULT_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DISABLE_ALIGNMENT_FAULT_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENTER_LOW_PWR_STATE_PLACEMENT @ MT6583_MD2
    INSTRUCTION_TCM
    .endm

    .macro CP15_INVALIDATE_IDCACHE_SINGLE_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INVALIDATE_IDCACHE_REGION_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INVALIDATE_ICACHE_REGION_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INVALIDATE_DCACHE_REGION_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_AND_INVALIDATE_DCACHE_BY_SETWAY_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_ALL_DCACHE_BY_SETWAY_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_AND_INVALIDATE_ALL_DCACHE_BY_SETWAY_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_DCACHE_REGION_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_AND_INVALIDATE_DCACHE_REGION_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_LOCKDOWN_TLB_ENTRY_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_IS_ICACHE_ENABLED_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_IS_DCACHE_ENABLED_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_SET_IDCACHE_REPLACEMENT_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_DCACHE_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_IS_FPU_ENABLED_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_LOCKDOWN_ICACHE_PLACEMENT @ MT6583_MD2
    INSTRUCTION_TCM
    .endm

    .macro CP15_LOCKDOWN_DCACHE_PLACEMENT @ MT6583_MD2
    INSTRUCTION_TCM
    .endm

    .macro CP15_PREFETCH_ICACHE_LINE_PLACEMENT @ MT6583_MD2
    INSTRUCTION_TCM
    .endm
    
    .macro CP15_SWITCH_VECTOR_PLACEMENT @ MT6583_MD2
    DEFAULT_CODE_REGION
    .endm

    
    @/***************************/
    @ * End of MT6583MD2 Place  *
    @ ***************************/
#elif defined(MT6290) || defined(MT6595) || (defined(MT6752) && defined(__MD1__))
    @/************************/
    @ * Data Placement       *
    @ ************************/
    .macro CACHE_LINE_NR_PLACEMENT @ MT6290
    DATA_TCM_RW
    .endm

    .macro CACHE_LINE_NR_PER_WAY_PLACEMENT @ MT6290
    DATA_TCM_RW
    .endm
    
    @/************************/
    @ * Function Placement   *
    @ ************************/  
    .macro CP15_ENABLE_MPU_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_DISABLE_MPU_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_ENABLE_ALIGNMENT_FAULT_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_DISABLE_ALIGNMENT_FAULT_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_ABTCM_SELECT_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_BTCM_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_ATCM_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_MPU_SET_RGN_INDEX_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_MPU_SET_RGN_ADDR_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_MPU_SET_RGN_ACCCTRL_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_MPU_SET_RGN_SIZE_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_MPU_SET_RGN_ENABLE_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_MPU_SET_SUBREGION_DISABLE_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_ICACHE_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_DISABLE_ICACHE_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_DATA_SYNCHRONIZATION_BARRIER_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INST_SYNCHRONIZATION_BARRIER_PLACEMENT @ MT6290
    INSTRUCTION_TCM
    .endm
 
    .macro CP15_INVALIDATE_ICACHE_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_INVALIDATE_ICACHE_SINGLE_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_INVALIDATE_ICACHE_REGION_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_IS_ICACHE_ENABLED_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DRAIN_WRITE_BUFFER_PLACEMENT @ MT6290
    INSTRUCTION_TCM
    .endm
 
    .macro CP15_ENABLE_DCACHE_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_DISABLE_DCACHE_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_INVALIDATE_DCACHE_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_INVALIDATE_DCACHE_SINGLE_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_CLEAN_DCACHE_SINGLE_PLACEMENT @ MT6290
    INSTRUCTION_TCM
    .endm
 
    .macro CP15_INVALIDATE_DCACHE_REGION_PLACEMENT @ MT6290
    INSTRUCTION_TCM
    .endm

    .macro CP15_CLEAN_DCACHE_REGION_PLACEMENT @ MT6290
    INSTRUCTION_TCM
    .endm

    .macro CP15_CLEAN_AND_INVALIDATE_DCACHE_REGION_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_DCACHE_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_IS_DCACHE_ENABLED_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_AND_INVALIDATE_DCACHE_BY_SETWAY_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_ALL_DCACHE_BY_SETWAY_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_AND_INVALIDATE_ALL_DCACHE_BY_SETWAY_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_READ_DFSR_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_READ_FAR_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_READ_IFSR_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_READ_IFAR_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_ENTER_LOW_PWR_STATE_PLACEMENT @ MT6290
    INSTRUCTION_TCM
    .endm

    .macro CP15_DISABLE_ATCMRMW_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DISABLE_BTCMRMW_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DISABLE_LIL_STLDM_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_UNDEF_DIV_BY_ZERO_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_MPU_GET_RBAR_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_MPU_GET_RACR_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_MPU_GET_RSER_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DATA_MEMORY_BARRIER_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
 
    .macro CP15_SWITCH_VECTOR_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_SET_BP_POLICY_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_READ_ICACHE_INFO_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
    
    .macro CP15_READ_DCACHE_INFO_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
    
    .macro CP15_WRITE_CONTEXT_ID_PLACEMENT @ MT6290
    INSTRUCTION_TCM
    .endm
    
    .macro CP15_READ_CONTEXT_ID_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm    
    
    .macro CP15_PMU_READ_CONTROL_REGISTER_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
	
    .macro CP15_VECTOR_INTERRUPT_ENABLE_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PMU_WRITE_CONTROL_REGISTER_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PMU_WRITE_COUNTER_ENABLE_SET_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PMU_READ_COUNTER_ENABLE_SET_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PMU_WRITE_COUNTER_ENABLE_CLEAR_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PMU_READ_COUNTER_OVERFLOW_STATUS_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PMU_WRITE_EVENT_SELECTION_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PMU_READ_CYCLE_COUNTER_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
    
    .macro CP15_PMU_WRITE_CYCLE_COUNTER_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PMU_READ_EVENT_COUNTER_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PMU_WRITE_EVENT_COUNTER_PLACEMENT @ MT6290
    DEFAULT_CODE_REGION
    .endm
    
    @/***************************/
    @ * End of MT6290 Placement *
    @ ***************************/
#elif (defined(MT6752) && defined(__MD2__))
    @/************************/
    @ * Data Placement       *
    @ ************************/
    .macro CACHE_LINE_NR_PLACEMENT @ MT6589_MD2
    DEFAULT_RWDATA_REGION
    .endm

    .macro CACHE_LINE_NR_PER_WAY_PLACEMENT @ MT6589_MD2
    DEFAULT_RWDATA_REGION
    .endm
    
    @/************************/
    @ * Function Placement   *
    @ ************************/
    .macro CP15_READ_CACHE_TYPE_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm
    
    .macro CP15_ENABLE_ICACHE_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DISABLE_ICACHE_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INVALIDATE_ICACHE_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INVALIDATE_ICACHE_SINGLE_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_DCACHE_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DISABLE_DCACHE_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INVALIDATE_DCACHE_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INVALIDATE_DCACHE_SINGLE_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_DCACHE_SINGLE_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DRAIN_WRITE_BUFFER_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm
    
    .macro CP15_DATA_SYNCHRONIZATION_BARRIER_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm
    
    .macro CP15_READ_TCM_STATUS_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_READ_ITCM_REGION_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_READ_DTCM_REGION_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_ITCM_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_DTCM_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_WRITE_TBBR_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm
    
    .macro CP15_READ_TBBR_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_MMU_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DISABLE_MMU_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_READ_DOMAIN_ACCESS_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_WRITE_DOMAIN_ACCESS_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_READ_IFSR_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_READ_DFSR_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_READ_FAR_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INVALIDATE_TLB_SINGLE_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INVALIDATE_TLB_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_ROM_PROTECT_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DISABLE_ROM_PROTECT_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_SYS_PROTECT_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DISABLE_SYS_PROTECT_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENABLE_ALIGNMENT_FAULT_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_DISABLE_ALIGNMENT_FAULT_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_ENTER_LOW_PWR_STATE_PLACEMENT @ MT6589_MD2
    INSTRUCTION_TCM
    .endm

    .macro CP15_INVALIDATE_IDCACHE_SINGLE_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INVALIDATE_IDCACHE_REGION_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INVALIDATE_ICACHE_REGION_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_INVALIDATE_DCACHE_REGION_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_AND_INVALIDATE_DCACHE_BY_SETWAY_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_ALL_DCACHE_BY_SETWAY_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_AND_INVALIDATE_ALL_DCACHE_BY_SETWAY_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_DCACHE_REGION_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_AND_INVALIDATE_DCACHE_REGION_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_LOCKDOWN_TLB_ENTRY_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_IS_ICACHE_ENABLED_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_IS_DCACHE_ENABLED_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_SET_IDCACHE_REPLACEMENT_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_CLEAN_DCACHE_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_IS_FPU_ENABLED_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_LOCKDOWN_ICACHE_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_LOCKDOWN_DCACHE_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    .macro CP15_PREFETCH_ICACHE_LINE_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm
    
    .macro CP15_SWITCH_VECTOR_PLACEMENT @ MT6589_MD2
    DEFAULT_CODE_REGION
    .endm

    
    @/***************************/
    @ * End of MT6589MD2 Place  *
    @ ***************************/
#else
    @ Unknow project name, fall into assembly error here
    .error "Unknown project name"
@ MT6280
#endif
