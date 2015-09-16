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
 *   cr4_cp15.inc
 * 
 * Project: 
 * -------- 
 *   MAUI 
 * 
 * Description: 
 * ------------ 
 *   CP15 related functions for CR4
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
 *------------------------------------------------------------------------------ 
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================ 
 ****************************************************************************/    
    
    CPU_ISA()
    ISA_UNIFIED_SETTING()
@/****************************************************************************
@ *     Define Constants
@ ****************************************************************************/         
    .equ MPU_RGNNUM_MASK,    0x0000000F
    .equ MPU_BADDR_MASK,	   0x0000001F
    .equ MPU_SIZE_MASK,	     0xFFFF00C1
    .equ MPU_ENABLE_MASK,    0xFFFFFFFE
    .equ MPU_ACCTRL_MASK,    0xFFFFE8C0
    .equ MPU_SUBREGION_MASK, 0xFFFF00FF

    .equ NUM_OF_SET_MASK,    0x0FFFE000
    .equ NUM_OF_SET_OFFSET,  0x0000000D

    .equ C1_VBIT_MASK,       0x00002000
    .equ C1_DZ_BIT,          0x00080000
    .equ C1_DILSM_BIT,       0x00400000
    .equ C1_VE,              0x01000000
    .equ C1_NMFI_MASK,       0x08000000
    .equ C1_TE,              0x40000000
    .equ C1_MBIT,            0x00000001
    .equ C1_ABIT,            0x00000002
    .equ C1_CBIT,            0x00000004 
    .equ C1_IBIT,            0x00001000
    .equ C1_VINITHI,         0x00002000
    
    .equ C1_CSSELR_InD_BIT,  0x00000001
                   
    .equ C9_ENABLE_BIT,      0x00000001 
                   
    .equ C15_ATCMRMW_MASK,   0x00000001
    .equ C15_BTCMRMW_MASK,   0x00000002
                   
    .equ TCM_BADDR_MASK,     0x0000003F
                   
    .equ ICACHE_ENABLE,      0x1000
    .equ DCACHE_ENABLE,      0x4

    .equ BP_MASK,            0xFFFE7FFF
    .equ BP_ALWAYS_NOT_TAKEN,0x00010000
    .equ BP_NORMAL_OPERATION,0x00000000

    .global cache_line_nr
    .global cache_line_nr_per_way

@/****************************************************************************
@ *     Define Global Variables
@ ****************************************************************************/ 
    CACHE_LINE_NR_PLACEMENT
	
	.balign 4
	
    .global cache_line_nr
cache_line_nr:
    .word     0x1000  
    
    CACHE_LINE_NR_PER_WAY_PLACEMENT
    .global cache_line_nr_per_way
cache_line_nr_per_way:
    .word     0x400
    
#if defined(MT6280) && defined(__MODEM_CARD__)
@ Special code for MT6280 DataCard SW running on WIFI-router chips
@ This flag indicates whether ARM9 has entered WFI
    COPRO_WFI_FLAG_PLACEMENT
    .global copro_wfi_flag
copro_wfi_flag:
    .word     0x0
#endif /* MT6280 && __MODEM_CARD__ */
  
@/****************************************************************************
@ *     CP15 APIs
@ ****************************************************************************/
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_enable_mpu                                                     */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    This function enables MPU.                                          */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_enable_mpu(VOID) 
@{ 
    CP15_ENABLE_MPU_PLACEMENT
	.global cp15_enable_mpu
    FUNC_ATTR(cp15_enable_mpu) 
	
cp15_enable_mpu:
    MRC p15,0,r0,c1,c0,0 
    ORR r0,r0,#C1_MBIT 
    DSB
    MCR p15,0,r0,c1,c0,0 
    ISB
     
    BX lr 
@}
   
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_disable_mpu                                                    */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    This function disables MPU.                                         */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_disable_mpu(VOID) 
@{ 
    CP15_DISABLE_MPU_PLACEMENT
	.global cp15_disable_mpu
    FUNC_ATTR(cp15_disable_mpu) 
	
cp15_disable_mpu:
    MRC p15,0,r0,c1,c0,0 
    BIC r0,r0,#C1_MBIT 
    DSB
    MCR p15,0,r0,c1,c0,0 
    ISB
    
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_enable_alignment_fault                                       */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function enables alignment fault.                            */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */
@/*                                                                        */ 
@/**************************************************************************/  
@VOID cp15_enable_alignment_fault(VOID) 
@{ 
@    CP15_ENABLE_ALIGNMENT_FAULT_PLACEMENT
	.global cp15_enable_alignment_fault
    FUNC_ATTR(cp15_enable_alignment_fault)
	
cp15_enable_alignment_fault:
    MRC p15,0,r0,c1,c0,0 
    ORR r0,r0,#C1_ABIT 
    MCR p15,0,r0,c1,c0,0 
 
    BX lr
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_disable_alignment_fault                                      */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function disables alignment fault.                           */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_disable_alignment_fault(VOID) 
@{ 
    CP15_DISABLE_ALIGNMENT_FAULT_PLACEMENT
	.global cp15_disable_alignment_fault
    FUNC_ATTR(cp15_disable_alignment_fault)
	
cp15_disable_alignment_fault:
    MRC p15,0,r0,c1,c0,0 
    BIC r0,r0,#C1_ABIT 
    MCR p15,0,r0,c1,c0,0 
 
    BX lr
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_abtcm_select                                                   */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*                                                                        */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@BOOL cp15_abtcm_select(value)  ;useless in CR4 because A and B TCM both have TCM interface
@{ 
    CP15_ABTCM_SELECT_PLACEMENT
	.global cp15_abtcm_select
    FUNC_ATTR(cp15_abtcm_select) 
	
cp15_abtcm_select:
    MCR p15,0,r0,c9,c2,0 
     
    BX lr
@}
  
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_enable_btcm                                                    */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*                                                                        */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    B-TCM base address                                                  */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@BOOL cp15_enable_btcm(UINT32 addr) 
@{ 
    CP15_ENABLE_BTCM_PLACEMENT
	.global cp15_enable_btcm
    FUNC_ATTR(cp15_enable_btcm)   
	
cp15_enable_btcm:
  
    MRC p15,0,r1,c9,c1,0 
    LDR r2, =TCM_BADDR_MASK
    AND r1,r1,r2
    ORR r0,r0,#C9_ENABLE_BIT 
    ORR r0,r0,r1 
    MCR p15,0,r0,c9,c1,0 

     
    BX lr

@}
  
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_enable_atcm                                                    */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*                                                                        */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    A-TCM base address                                                  */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@BOOL cp15_enable_atcm(UINT32 addr) 
@{ 
    CP15_ENABLE_ATCM_PLACEMENT
	.global cp15_enable_atcm
    FUNC_ATTR(cp15_enable_atcm) 
        
cp15_enable_atcm:
    
    MRC p15,0,r1,c9,c1,1 
    LDR r2, =TCM_BADDR_MASK
    AND r1,r1,r2
    ORR r0,r0,#C9_ENABLE_BIT 
    ORR r0,r0,r1 
    MCR p15,0,r0,c9,c1,1 
    
    BX lr

@}
  
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_mpu_set_rgn_index                                              */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    This functions selects the number of MPU region to be configure     */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    Region number                                                       */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@BOOL cp15_mpu_set_rgn_index(num) 
@{ 
    CP15_MPU_SET_RGN_INDEX_PLACEMENT
	.global cp15_mpu_set_rgn_index
    FUNC_ATTR(cp15_mpu_set_rgn_index) 
      
cp15_mpu_set_rgn_index:
  
    LDR r2, =MPU_RGNNUM_MASK
    AND r0,r0,r2    
    MCR p15,0,r0,c6,c2,0 
   
    BX lr

@}
  
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_mpu_set_rgn_addr                                               */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    This fuction sets MPU region start address                          */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    Start address                                                       */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@BOOL cp15_mpu_set_rgn_addr(addr) 
@{ 
    CP15_MPU_SET_RGN_ADDR_PLACEMENT
	.global cp15_mpu_set_rgn_addr
    FUNC_ATTR(cp15_mpu_set_rgn_addr)
    
cp15_mpu_set_rgn_addr:
  
    MRC p15,0,r1,c6,c1,0 
    LDR r2, =MPU_BADDR_MASK
    AND r1,r1,r2
    ORR r0,r0,r1 
    MCR p15,0,r0,c6,c1,0 
     
    BX lr

@}
  
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_mpu_set_rgn_accctrl                                            */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    this fuction sets MPU region access control bits                    */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    Control bits                                                        */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/**************************************************************************/  
@BOOL cp15_mpu_set_rgn_accctrl(UINT32 acctrl) 
@{ 
    CP15_MPU_SET_RGN_ACCCTRL_PLACEMENT
	.global cp15_mpu_set_rgn_accctrl
    FUNC_ATTR(cp15_mpu_set_rgn_accctrl) 
        
cp15_mpu_set_rgn_accctrl:
    
    MRC p15,0,r1,c6,c1,4
    LDR r2, =MPU_ACCTRL_MASK
    AND r1,r1,r2
    ORR r1,r1,r0
    ISB
    MCR p15,0,r1,c6,c1,4
    
         
    BX lr

@}
  
  
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_mpu_set_rgn_size                                               */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    this function sets MPU region size                                  */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    Size                                                                */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/**************************************************************************/  
@BOOL cp15_mpu_set_rgn_size(UINT32 size) 
@{ 
    CP15_MPU_SET_RGN_SIZE_PLACEMENT
	.global cp15_mpu_set_rgn_size
    FUNC_ATTR(cp15_mpu_set_rgn_size) 
        
cp15_mpu_set_rgn_size:
    
    MRC p15,0,r1,c6,c1,2
    LDR r2, =MPU_SIZE_MASK
    AND r1,r1,r2
    ORR r1,r1,r0,LSL #1
    MCR p15,0,r1,c6,c1,2
    
         
    BX lr

@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_mpu_set_rgn_enable                                             */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    This function sets MPU region enable bit                            */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    Enable bit                                                          */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@BOOL cp15_mpu_set_rgn_enable(UINT32 en) 
@{ 
    CP15_MPU_SET_RGN_ENABLE_PLACEMENT
	.global cp15_mpu_set_rgn_enable
    FUNC_ATTR(cp15_mpu_set_rgn_enable) 
        
cp15_mpu_set_rgn_enable:
    AND r0, #C9_ENABLE_BIT
    CMP r0, #C9_ENABLE_BIT
    MRC p15,0,r1,c6,c1,2
    ORREQ r1,r0,r1
    BICNE r1,r1,#C9_ENABLE_BIT 
    MCR p15,0,r1,c6,c1,2
       
    BX lr

@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_mpu_set_subregion_disable                                    */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function configures the MPU sub-region disable bits          */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      kal_uint32 region_size                                            */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      none                                                              */ 
@/*                                                                        */
@/**************************************************************************/  
    CP15_MPU_SET_SUBREGION_DISABLE_PLACEMENT
	.global cp15_mpu_set_subregion_disable
    FUNC_ATTR(cp15_mpu_set_subregion_disable) 
        
cp15_mpu_set_subregion_disable:
    MRC p15,0,r1,c6,c1,2
    LDR r2, =MPU_SUBREGION_MASK
    AND r1,r1,r2
    MOV r0,r0,LSL #8
    ORR r1,r1,r0
    MCR p15,0,r1,c6,c1,2
    
    BX lr    

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_enable_icache                                                  */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    This function enables I-Cache.                                      */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_enable_icache(VOID) 
@{ 
    CP15_ENABLE_ICACHE_PLACEMENT
	.global cp15_enable_icache
    FUNC_ATTR(cp15_enable_icache) 

cp15_enable_icache:
    MRC p15, 0, r0, c1, c0, 0 
    ORR r0,r0,#C1_IBIT
    MOV r1,#0
    MCR p15, 0, r1, c7, c5, 0 @Invalidate I-Cache
    MCR p15, 0, r0, c1, c0, 0 
    ISB

    BX lr 
  
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_disable_icache                                                 */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    This function disables I-Cache.                                     */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_disable_icache(VOID) 
@{ 
    CP15_DISABLE_ICACHE_PLACEMENT
	.global cp15_disable_icache
    FUNC_ATTR(cp15_disable_icache) 

cp15_disable_icache:

    MRC p15,0,r0,c1,c0,0 
    BIC r0,r0,#C1_IBIT 
    MCR p15,0,r0,c1,c0,0
     
    ISB
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_data_synchronization_barrier                                   */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    This function acts as a data synchronizatin berrier.                */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_data_synchronization_barrier(void) 
@{ 
    CP15_DATA_SYNCHRONIZATION_BARRIER_PLACEMENT
	.global cp15_data_synchronization_barrier
    FUNC_ATTR(cp15_data_synchronization_barrier) 

cp15_data_synchronization_barrier:
 
    DSB
 
    BX lr 
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_inst_synchronization_barrier                                   */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    This function acts as a inst sync berrier.                          */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_inst_synchronization_barrier(void) 
@{ 
    CP15_INST_SYNCHRONIZATION_BARRIER_PLACEMENT
	.global cp15_inst_synchronization_barrier
    FUNC_ATTR(cp15_inst_synchronization_barrier) 

cp15_inst_synchronization_barrier:
 
    ISB
 
    BX lr 
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_invalidate_icache                                              */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    This function invalidates I-Cache.                                  */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/**************************************************************************/  
@VOID cp15_invalidate_icache(VOID) 
@{ 
    CP15_INVALIDATE_ICACHE_PLACEMENT
	.global cp15_invalidate_icache
    FUNC_ATTR(cp15_invalidate_icache) 

cp15_invalidate_icache:
 
    MOV r0,#0 
    MCR p15,0,r0,c7,c5,0 
 
    BX lr

@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_invalidate_icache_single                                     */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function invalidates I-Cache single entry via MVA.           */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      MVA                                                               */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_invalidate_icache_single(UINT32 MVA) 
@{ 
    CP15_INVALIDATE_ICACHE_SINGLE_PLACEMENT
	.global cp15_invalidate_icache_single
    FUNC_ATTR(cp15_invalidate_icache_single) 

cp15_invalidate_icache_single:

@   /* quarantee 8-word alignment */
    MOV r0,r0,LSR #5 
    MOV r0,r0,LSL #5 
    MCR p15,0,r0,c7,c5,1 
 
    BX lr 
@} 


@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_invalidate_icache_region                                       */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    This function invalidates ICachefor the specified regions           */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    addr    -   start address of the region                             */ 
@/*    nr_cache  -   number of cache entires                               */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_invalidate_icache_region(UINT32 addr, UINT32 nr_cache) 
@{ 
    CP15_INVALIDATE_ICACHE_REGION_PLACEMENT
	.global cp15_invalidate_icache_region
    FUNC_ATTR(cp15_invalidate_icache_region) 

cp15_invalidate_icache_region:

    CMP r1,#0
    BEQ invalidate_icache_end

invalidate_icache_begin:
    MCR p15,0,r0,c7,c5,1 
    ADD r0,r0,#32
    SUBS r1,r1,#1  
    BNE invalidate_icache_begin

invalidate_icache_end:
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_is_icache_enabled                                            */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      this function checks if icache is enabled                         */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/**************************************************************************/  
@BOOL cp15_is_icache_enabled(VOID) 
@{ 
    CP15_IS_ICACHE_ENABLED_PLACEMENT
	.global cp15_is_icache_enabled
    FUNC_ATTR(cp15_is_icache_enabled) 
        
cp15_is_icache_enabled:

    MRC     p15, 0, a4, c1, c0, 0
    ANDS     a1, a4, #ICACHE_ENABLE  
    MOVNE    a1, #1
   
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_drain_write_buffer                                             */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    This function drains write buffer.                                  */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_drain_write_buffer(VOID) 
@{ 
    CP15_DRAIN_WRITE_BUFFER_PLACEMENT
	.global cp15_drain_write_buffer
    FUNC_ATTR(cp15_drain_write_buffer) 

cp15_drain_write_buffer:
  
    DSB
   
    BX lr 
@} 


@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_enable_dcache                                                  */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    This function enables D-Cache.                                      */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_enable_dcache(VOID) 
@{ 
    CP15_ENABLE_DCACHE_PLACEMENT
	.global cp15_enable_dcache
    FUNC_ATTR(cp15_enable_dcache) 

cp15_enable_dcache:

    MOV r1,#0 
    MRC p15,0,r0,c1,c0,0 
    ORR r0,r0,#C1_CBIT 
    DSB
    MCR p15, 0, r1, c15, c5, 0 @ Invalidate entire data cache
    MCR p15, 0, r0, c1, c0, 0 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_disable_dcache                                                 */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    This function disables D-Cache.                                     */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_disable_dcache(VOID) 
@{ 
    CP15_DISABLE_DCACHE_PLACEMENT
	.global cp15_disable_dcache
    FUNC_ATTR(cp15_disable_dcache) 

cp15_disable_dcache:
 
    MRC p15,0,r0,c1,c0,0 
    BIC r0,r0,#C1_CBIT 
    DSB
    MCR p15,0,r0,c1,c0,0 
    
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_invalidate_dcache                                              */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    This function invalidates D-Cache.                                  */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_invalidate_dcache(VOID) 
@{ 
    CP15_INVALIDATE_DCACHE_PLACEMENT
	.global cp15_invalidate_dcache
    FUNC_ATTR(cp15_invalidate_dcache) 

cp15_invalidate_dcache:
 
    MOV r0,#0 
    MCR p15,0,r0,c15,c5,0 
    
    BX lr

@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_invalidate_dcache_single                                     */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function invalidates D-Cache single entry via MVA.           */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      MVA                                                               */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_invalidate_dcache_single(UINT32 MVA) 
@{ 
    CP15_INVALIDATE_DCACHE_SINGLE_PLACEMENT
	.global cp15_invalidate_dcache_single
    FUNC_ATTR(cp15_invalidate_dcache_single) 

cp15_invalidate_dcache_single:

@   /* quarantee 8-word alignment */
    MOV r0,r0,LSR #5 
    MOV r0,r0,LSL #5 
    MCR p15,0,r0,c7,c6,1 
 
    BX lr 
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_clean_dcache_single                                          */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function cleans D-Cache single entry via MVA.                */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      MVA                                                               */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_clean_dcache_single(UINT32 MVA) 
@{ 
    CP15_CLEAN_DCACHE_SINGLE_PLACEMENT
	.global cp15_clean_dcache_single
    FUNC_ATTR(cp15_clean_dcache_single) 

cp15_clean_dcache_single:
 
@   /* quarantee 8-word alignment */
    MOV r0,r0,LSR #5 
    MOV r0,r0,LSL #5 
    MCR p15,0,r0,c7,c10,1 
 
    BX lr 
@}


@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_invalidate_dcache_region                                       */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    This function invalidates DCache for the specified regions          */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    addr    -   start address of the region                             */ 
@/*    nr_cache  -   number of cache entires                               */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */
@/*                                                                        */ 
@/**************************************************************************/  
@VOID cp15_invalidate_dcache_region(UINT32 addr, UINT32 nr_cache) 
@{ 
    CP15_INVALIDATE_DCACHE_REGION_PLACEMENT
	.global cp15_invalidate_dcache_region
    FUNC_ATTR(cp15_invalidate_dcache_region) 

cp15_invalidate_dcache_region:
    CMP r1,#0
    BEQ invalidate_dcache_end
    
    @ If region > cache size, do invalidate and clean all to improve responsiveness
    LDR r2,=cache_line_nr
    LDR r2,[r2]
    
    CMP r1,r2
    LDR r3, =cp15_clean_and_invalidate_all_dcache_by_setway
    BXGT r3

invalidate_dcache_begin:
    MCR p15,0,r0,c7,c6,1 
    ADD r0,r0,#32
    SUBS r1,r1,#1
    BNE invalidate_dcache_begin

invalidate_dcache_end:
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_clean_dcache_region                                            */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    This function clean DCache for the specified regions                */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    addr    -   start address of the region                             */ 
@/*    nr_cache  -   number of cache entires                               */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_clean_dcache_region(UINT32 addr, UINT32 nr_cache) 
@{ 
    CP15_CLEAN_DCACHE_REGION_PLACEMENT
	.global cp15_clean_dcache_region
    FUNC_ATTR(cp15_clean_dcache_region) 

cp15_clean_dcache_region:
    CMP r1,#0
    BEQ clean_dcache_end
    
    @ If the target region > cache size, clean all DCache to improve the response time
    LDR r2,=cache_line_nr
    LDR r2,[r2]
    
    CMP r1,r2
    LDR r3, =cp15_clean_all_dcache_by_setway
    BXGT r3

clean_dcache_begin:
    MCR p15,0,r0,c7,c10,1 
    ADD r0,r0,#32
    SUBS r1,r1,#1
    BNE clean_dcache_begin

clean_dcache_end:
    BX lr 
@} 


@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_clean_and_invalidate_dcache_region                           */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function clean and invalidates DCache for the specified      */
@/*      regions                                                           */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      addr        -   start address of the region                       */ 
@/*      nr_cache    -   number of cache entires                           */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/**************************************************************************/  
    CP15_CLEAN_AND_INVALIDATE_DCACHE_REGION_PLACEMENT
    .global cp15_clean_and_invalidate_dcache_region 
    FUNC_ATTR(cp15_clean_and_invalidate_dcache_region)
	
cp15_clean_and_invalidate_dcache_region:

    CMP r1,#0
    BEQ clean_and_invalidate_dcache_end
    
    @ If region > cache size, do invalidate and clean all to improve responsiveness
    LDR r2,=cache_line_nr
    LDR r2,[r2]
    
    CMP r1,r2
    LDR r3, =cp15_clean_and_invalidate_all_dcache_by_setway
    BXGT r3

clean_and_invalidate_dcache_begin:
    MCR p15,0,r0,c7,c14,1 
    ADD r0,r0,#32
    SUBS r1,r1,#1
    BNE clean_and_invalidate_dcache_begin

clean_and_invalidate_dcache_end:
    BX lr 
    

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*    cp15_clean_dcache                                                   */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*    This functions cleans entire dcache                                 */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*    None                                                                */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_clean_dcache(VOID) 
@{ 
    CP15_CLEAN_DCACHE_PLACEMENT
    .global cp15_clean_dcache
    FUNC_ATTR(cp15_clean_dcache)

cp15_clean_dcache:

    MRC p15, 1, r0, c0, c0, 0 @ read current cache size identification register
    LDR r1 , =NUM_OF_SET_MASK
    AND r0 , r0, r1
    MOV r0 , r0, LSR #NUM_OF_SET_OFFSET

clean_loop:
    MOV r1, #0
    MOV r2, r1, LSL #30
    ORR r2, r2, r0, LSL #5
    MCR p15, 0, r2, c7, c10, 2
    
    ADD r1, r1, #1
    MOV r2, r1, LSL #30
    ORR r2, r2, r0, LSL #5
    MCR p15, 0, r2, c7, c10, 2
    
    ADD r1, r1, #1
    MOV r2, r1, LSL #30
    ORR r2, r2, r0, LSL #5
    MCR p15, 0, r2, c7, c10, 2
    
    ADD r1, r1, #1
    MOV r2, r1, LSL #30
    ORR r2, r2, r0, LSL #5
    MCR p15, 0, r2, c7, c10, 2
    
    SUBS r0, r0, #1
    BCS clean_loop
    
    BX lr

@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_is_dcache_enabled                                            */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      this function checks if dcache is enable                          */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/**************************************************************************/  
@BOOL cp15_is_dcache_enabled(VOID) 
@{ 
    CP15_IS_DCACHE_ENABLED_PLACEMENT
    .global cp15_is_dcache_enabled 
    FUNC_ATTR(cp15_is_dcache_enabled)
        
cp15_is_dcache_enabled:

    MRC     p15, 0, a4, c1, c0, 0
    ANDS     a1, a4, #DCACHE_ENABLE
    MOVNE    a1, #1
   
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_clean_and_invalidate_dcache_by_setway                        */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function invalidate and clean dcache by set/way              */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      r0: set                                                           */ 
@/*      r1: way                                                           */
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/**************************************************************************/  
    CP15_CLEAN_AND_INVALIDATE_DCACHE_BY_SETWAY_PLACEMENT
    .global cp15_clean_and_invalidate_dcache_by_setway
    FUNC_ATTR(cp15_clean_and_invalidate_dcache_by_setway)
	
cp15_clean_and_invalidate_dcache_by_setway:
    LSL r1,r1,#30
    LSL r0,r0,#5
    ORR r0,r0,r1
    MCR p15,0,r0,c7,c14,2 @ Clean/Invalidate set way
    MOV r0,#0
    
    BX lr

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_clean_all_dcache_by_setway                                   */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function clean entire D-Cache by Set/way                     */  
@/*      [NOTE] Only safe after CacheInit()                                */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_clean_all_dcache_by_setway(void) 
@{ 
    CP15_CLEAN_ALL_DCACHE_BY_SETWAY_PLACEMENT
    .global cp15_clean_all_dcache_by_setway 
    FUNC_ATTR(cp15_clean_all_dcache_by_setway)
	
cp15_clean_all_dcache_by_setway:
    
    MOV r2,#0xC0000000     @ the way number

clean_all_dcache_init:
    LDR r1,=cache_line_nr_per_way
    LDR r1,[r1]               @ total cache number in the way
    MOV r0,r2                 @ start address of the way
            
clean_all_dcache_begin:
    MCR p15,0,r0,c7,c10,2
    ADD r0,r0,#32
    SUBS r1,r1,#1
    BNE clean_all_dcache_begin
    
    CMP r2,#0
    BEQ clean_all_dcache_end
    
    SUBS r2,r2,#0x40000000
    B clean_all_dcache_init

clean_all_dcache_end:
    
    BX lr
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_clean_and_invalidate_all_dcache_by_setway                    */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function invalidate and clean all dcache by set/way          */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/**************************************************************************/  
    CP15_CLEAN_AND_INVALIDATE_ALL_DCACHE_BY_SETWAY_PLACEMENT
    .global cp15_clean_and_invalidate_all_dcache_by_setway 
    FUNC_ATTR(cp15_clean_and_invalidate_all_dcache_by_setway)
	
cp15_clean_and_invalidate_all_dcache_by_setway:
    MOV r2,#0xC0000000        @ the way number

clean_invalidate_all_dcache_init:
    LDR r1,=cache_line_nr_per_way
    LDR r1,[r1]               @ total cache number in the way
    MOV r0,r2                 @ start address of the way
            
clean_invalidate_all_dcache_begin:
    MCR p15,0,r0,c7,c14,2
    ADD r0,r0,#32
    SUBS r1,r1,#1
    BNE clean_invalidate_all_dcache_begin
    
    CMP r2,#0
    BEQ clean_invalidate_all_dcache_end
    
    SUBS r2,r2,#0x40000000
    B clean_invalidate_all_dcache_init

clean_invalidate_all_dcache_end:
    
    BX lr

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_dfsr                                                    */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads DFSR(Data Fault Status Register).             */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      data fault status register                                        */ 
@/*                                                                        */
@/**************************************************************************/  
@UINT32 cp15_read_dfsr(VOID) 
@{ 
    CP15_READ_DFSR_PLACEMENT
    .global cp15_read_dfsr 
    FUNC_ATTR(cp15_read_dfsr)
	
cp15_read_dfsr:
 
    MRC p15,0,r0,c5,c0,0 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_far                                                     */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads FAR(Fault Address Register).                  */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      fault address register                                            */ 
@/*                                                                        */
@/**************************************************************************/  
@UINT32 cp15_read_far(VOID) 
@{ 
    CP15_READ_FAR_PLACEMENT
    .global cp15_read_far 
    FUNC_ATTR(cp15_read_far)
	
cp15_read_far:
 
    MRC p15,0,r0,c6,c0,0 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_ifar                                                    */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads IFSR(Instruction Fault Status Register).      */  
@/*      for prefetch abort                                                */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      fault address register                                            */ 
@/*                                                                        */
@/**************************************************************************/  
@UINT32 cp15_read_ifsr(VOID) 
@{ 
    CP15_READ_IFSR_PLACEMENT
    .global cp15_read_ifsr 
    FUNC_ATTR(cp15_read_ifsr)
	
cp15_read_ifsr:
 
    MRC p15,0,r0,c5,c0,1 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_ifar                                                    */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads IFAR(Instruction Fault Address Register).     */  
@/*      for prefetch abort                                                */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      fault address register                                            */ 
@/*                                                                        */
@/**************************************************************************/  
@UINT32 cp15_read_ifar(VOID) 
@{ 
    CP15_READ_IFAR_PLACEMENT
    .global cp15_read_ifar 
    FUNC_ATTR(cp15_read_ifar)
	
cp15_read_ifar:
 
    MRC p15,0,r0,c6,c0,2 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_enter_low_pwr_state                                          */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function configures ARM9 to enter low power state.           */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_enter_low_pwr_state(VOID) 
@{ 
    CP15_ENTER_LOW_PWR_STATE_PLACEMENT
    .global cp15_enter_low_pwr_state 
    FUNC_ATTR(cp15_enter_low_pwr_state)
	
cp15_enter_low_pwr_state:
 
    DSB
    WFI 
    DSB
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_disable_atcmrmw                                              */
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function disables 64 bits read-modify-write behavior of ATCM */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_disable_atcmrmw(void) 
@{ 
    CP15_DISABLE_ATCMRMW_PLACEMENT
    .global cp15_disable_atcmrmw
    FUNC_ATTR(cp15_disable_atcmrmw)
	
cp15_disable_atcmrmw:
 
    MRC p15,0,r0,c15,c0,0 
    BIC r0,r0,#C15_ATCMRMW_MASK
    MCR p15,0,r0,c15,c0,0 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_disable_btcmrmw                                              */
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function disables 64 bits read-modify-write behavior of BTCM */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_disable_btcmrmw(void) 
@{ 
    CP15_DISABLE_BTCMRMW_PLACEMENT
    .global cp15_disable_btcmrmw
    FUNC_ATTR(cp15_disable_btcmrmw)
	
cp15_disable_btcmrmw:
 
    MRC p15,0,r0,c15,c0,0 
    BIC r0,r0,#C15_BTCMRMW_MASK
    MCR p15,0,r0,c15,c0,0 
 
    BX lr
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_disable_LIL_STLDM                                            */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function disables low interrupt latency on LD/ST multiples   */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_disable_LIL_STLDM(void) 
@{ 
    CP15_DISABLE_LIL_STLDM_PLACEMENT
    .global cp15_disable_LIL_STLDM
    FUNC_ATTR(cp15_disable_LIL_STLDM)
	
cp15_disable_LIL_STLDM:
 
    MRC p15,0,r0,c1,c0,1 
    ORR r0,r0,#C1_DILSM_BIT
    MCR p15,0,r0,c1,c0,1 
 
    BX lr

@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_enable_undef_div_by_zero                                     */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function enables undefined exception for divide by zero      */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_enable_undef_div_by_zero(void) 
@{ 
    CP15_ENABLE_UNDEF_DIV_BY_ZERO_PLACEMENT
    .global cp15_enable_undef_div_by_zero
    FUNC_ATTR(cp15_enable_undef_div_by_zero)
	
cp15_enable_undef_div_by_zero:
 
    MRC p15,0,r0,c1,c0,0 
    ORR r0,r0,#C1_DZ_BIT
    MCR p15,0,r0,c1,c0,0 
 
    BX lr

@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_mpu_get_rbar                                                 */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function returns current Region Base Address Register        */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      RBAR                                                              */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_mpu_get_rbar(void) 
@{ 
    CP15_MPU_GET_RBAR_PLACEMENT
    .global cp15_mpu_get_rbar
    FUNC_ATTR(cp15_mpu_get_rbar)
	
cp15_mpu_get_rbar:
    MRC p15,0,r0,c6,c1,0
    
    BX lr
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_mpu_get_racr                                                 */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function returns current Region Access Control Register      */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      RBAR                                                              */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_mpu_get_racr(void) 
@{ 
    CP15_MPU_GET_RACR_PLACEMENT
    .global cp15_mpu_get_racr
    FUNC_ATTR(cp15_mpu_get_racr)
	
cp15_mpu_get_racr:
    MRC p15,0,r0,c6,c1,4
    
    BX lr
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_mpu_get_rser                                                 */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function returns current Region Size and Enable Register     */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      RBAR                                                              */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_mpu_get_rser(void) 
@{ 
    CP15_MPU_GET_RSER_PLACEMENT
    .global cp15_mpu_get_rser
    FUNC_ATTR(cp15_mpu_get_rser)
	
cp15_mpu_get_rser:
    MRC p15,0,r0,c6,c1,2
    
    BX lr
@}


@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_data_memory_barrier                                          */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function acts as a data memory barrier.                      */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      MVA                                                               */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/**************************************************************************/  
@VOID cp15_data_memory_barrier(VOID) 
@{ 
    CP15_DATA_MEMORY_BARRIER_PLACEMENT
    .global cp15_data_memory_barrier 
    FUNC_ATTR(cp15_data_memory_barrier)
	
cp15_data_memory_barrier:
    MOV r0, #0
    MCR p15,0,r0,c7,c10,5
 
    BX lr
@}


@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_switch_vector                                                */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function switch exception vector to high or low address      */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      0: low vector (0x00000000)                                        */ 
@/*      1: high vector (0xFFFF0000)                                       */
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/**************************************************************************/  
@VOID cp15_switch_vector(bool) 
@{ 
    CP15_SWITCH_VECTOR_PLACEMENT
    .global cp15_switch_vector
    FUNC_ATTR(cp15_switch_vector)
	
cp15_switch_vector:
    CMP r0,#0
    MRC p15,0,r0,c1,c0,0
    ORRNE r0,r0,#C1_VBIT_MASK
    BICEQ r0,r0,#C1_VBIT_MASK
    MCR p15,0,r0,c1,c0,0
    
    BX lr
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_set_bp_policy                                                */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function select branch prediction policy                     */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      0: normal operation                                               */ 
@/*      1: branch always taken                                            */
@/*      2: branch always not taken                                        */
@/*      3: reserved                                                       */
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/**************************************************************************/  
@VOID cp15_set_bp_policy(bool) 
@{ 
    CP15_SET_BP_POLICY_PLACEMENT
    .global cp15_set_bp_policy
    FUNC_ATTR(cp15_set_bp_policy)

cp15_set_bp_policy:
    MRC p15,0,r1,c1,c0,1
    AND r1,r1,#BP_MASK
    ORR r1,r1,r0, LSL #15
    MCR p15,0,r1,c1,c0,1

    BX lr
@}
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_icache_info                                             */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function read the Instruction cache info                     */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      CCIDR of instruction cache                                        */ 
@/**************************************************************************/  
@VOID cp15_switch_vector(bool) 
@{ 
    CP15_READ_ICACHE_INFO_PLACEMENT
    .global cp15_read_icache_info
    FUNC_ATTR(cp15_read_icache_info)
	
cp15_read_icache_info:
    MRC p15, 2, r0, c0, c0, 0     @ Select instruction cache info
    ORR r0,r0,#C1_CSSELR_InD_BIT  @ Select instruction cache info
    MCR p15, 2, r0, c0, c0, 0     @ Select instruction cache info
    MRC p15, 1, r0, c0, c0, 0     @ Read CCIDR
    
    BX lr
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_dcache_info                                             */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function read the Data cache info                            */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      CCIDR of data cache                                               */ 
@/**************************************************************************/  
@VOID cp15_switch_vector(bool) 
@{ 
    CP15_READ_DCACHE_INFO_PLACEMENT
    .global cp15_read_dcache_info
    FUNC_ATTR(cp15_read_dcache_info)
	
cp15_read_dcache_info:
    MRC p15, 2, r0, c0, c0, 0     @ Select instruction cache info
    BIC r0,r0,#C1_CSSELR_InD_BIT  @ Select instruction cache info
    MCR p15, 2, r0, c0, c0, 0     @ Select instruction cache info
    MRC p15, 1, r0, c0, c0, 0     @ Read CCIDR
    
    BX lr
@}
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_write_context_id                                             */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function writes CONTEXTIDR                                   */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      kal_uint32 contextid - The value to be written into CONTEXTIDR    */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/**************************************************************************/  
@VOID cp15_write_context_id(kal_uint32) 
@{ 
    CP15_WRITE_CONTEXT_ID_PLACEMENT
    .global cp15_write_context_id
    FUNC_ATTR(cp15_write_context_id)
	
cp15_write_context_id:
    MCR p15,0,r0,c13,c0,1
    BX lr

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_context_id                                              */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads CONTEXTIDR                                    */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      Current CONTEXTIDR                                                */ 
@/**************************************************************************/  
@kal_uint32 cp15_read_context_id(void) 
@{
    CP15_READ_CONTEXT_ID_PLACEMENT
    .global cp15_read_context_id
    FUNC_ATTR(cp15_read_context_id)
	
cp15_read_context_id:
    MRC p15,0,r0,c13,c0,1
    BX lr
    
@}
#if defined(MT6290) || defined(MT6595) || (defined(MT6752) && defined(__MD1__))
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_vector_interrupt_enable                                      */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function enable vector interrupt.                            */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/**************************************************************************/  
@kal_uint32 cp15_vector_interrupt_enable(void) 
@{
    CP15_VECTOR_INTERRUPT_ENABLE_PLACEMENT
    .global cp15_vector_interrupt_enable
    FUNC_ATTR(cp15_vector_interrupt_enable)
	
cp15_vector_interrupt_enable:

    MRC  p15, 0, r0, c1, c0, 0
	BIC	 r0, r0, #C1_VINITHI		 @ Vector base = 0x0
	ORRS r0, #C1_VE
    MCR  p15, 0, r0, c1, c0, 0
 
    BX lr 
    
@}
#endif /* MT6290 || MT6595  || (MT6752 && __MD1__) */
@/**************************************************************************/
@ * Performance Monitor APIs -->
@ **************************************************************************/
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_PMU_read_control_register                                    */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads the PMU control register                      */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      value of PMU control register                                     */ 
@/**************************************************************************/  
@kal_uint32 cp15_PMU_read_control_register(void) 
@{ 
    CP15_PMU_READ_CONTROL_REGISTER_PLACEMENT
    .global cp15_PMU_read_control_register
    FUNC_ATTR(cp15_PMU_read_control_register)
	
cp15_PMU_read_control_register:
    MRC p15,0,r0,c9,c12,0
    
    BX lr
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_PMU_write_control_register                                   */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function writes the PMU control register                     */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      value to be written to PMU ctrl                                   */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/**************************************************************************/  
@void cp15_PMU_write_control_register(kal_uint32) 
@{ 
    CP15_PMU_WRITE_CONTROL_REGISTER_PLACEMENT
    .global cp15_PMU_write_control_register
    FUNC_ATTR(cp15_PMU_write_control_register)
	
cp15_PMU_write_control_register:
    MCR p15,0,r0,c9,c12,0
    
    BX lr
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_PMU_write_counter_enable_set                                 */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function writes value to PMU counter enable set register     */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      value to be written to PMU counter enable set register            */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/**************************************************************************/  
@void cp15_PMU_write_counter_enable_set(kal_uint32) 
@{ 
    CP15_PMU_WRITE_COUNTER_ENABLE_SET_PLACEMENT
    .global cp15_PMU_write_counter_enable_set
    FUNC_ATTR(cp15_PMU_write_counter_enable_set)
	
cp15_PMU_write_counter_enable_set:
    MCR p15,0,r0,c9,c12,1
    
    BX lr
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_PMU_read_counter_enable_set                                  */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads value of PMU counter enable set register      */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      Value of PMU counter enable                                       */ 
@/**************************************************************************/  
@void cp15_PMU_read_counter_enable_set(kal_uint32) 
@{ 
    CP15_PMU_READ_COUNTER_ENABLE_SET_PLACEMENT
    .global cp15_PMU_read_counter_enable_set
    FUNC_ATTR(cp15_PMU_read_counter_enable_set)
	
cp15_PMU_read_counter_enable_set:
    MRC p15,0,r0,c9,c12,1
    
    BX lr
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_PMU_write_counter_enable_clear                               */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function writes value to PMU counter enable clear register   */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      value to be written to PMU counter enable clear register          */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/**************************************************************************/  
@void cp15_PMU_write_counter_enable_clear(kal_uint32) 
@{ 
    CP15_PMU_WRITE_COUNTER_ENABLE_CLEAR_PLACEMENT
    .global cp15_PMU_write_counter_enable_clear
    FUNC_ATTR(cp15_PMU_write_counter_enable_clear)
	
cp15_PMU_write_counter_enable_clear:
    MCR p15,0,r0,c9,c12,2
    
    BX lr
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_PMU_read_counter_overflow_status                             */ 
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads PMU counter overflow status                   */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      Overflow status flag                                              */ 
@/**************************************************************************/  
@kal_uint32 cp15_PMU_write_counter_enable_clear(void) 
@{ 
    CP15_PMU_READ_COUNTER_OVERFLOW_STATUS_PLACEMENT
    .global cp15_PMU_read_counter_overflow_status
    FUNC_ATTR(cp15_PMU_read_counter_overflow_status)
	
cp15_PMU_read_counter_overflow_status:
    MRC p15,0,r0,c9,c12,3
    
    BX lr
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_PMU_write_event_selection                                    */ 
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function sets PMU event counter for logging certain event    */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      Event counter number (0~2)                                        */ 
@/*      Event number                                                      */
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/**************************************************************************/  
@void cp15_PMU_read_cycle_counter(kal_uint32, kal_uint32) 
@{ 
    CP15_PMU_WRITE_EVENT_SELECTION_PLACEMENT
    .global cp15_PMU_write_event_selection
    FUNC_ATTR(cp15_PMU_write_event_selection)
	
cp15_PMU_write_event_selection:
    MCR p15,0,r0,c9,c12,5    @ Counter selection
    MCR p15,0,r1,c9,c13,1    @ Event selection
    
    BX lr
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_PMU_read_cycle_counter                                       */ 
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads PMU cycle counter                             */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      PMU cycle counter                                                 */ 
@/**************************************************************************/  
@kal_uint32 cp15_PMU_read_cycle_counter(void) 
@{ 
    CP15_PMU_READ_CYCLE_COUNTER_PLACEMENT
    .global cp15_PMU_read_cycle_counter
    FUNC_ATTR(cp15_PMU_read_cycle_counter)
	
cp15_PMU_read_cycle_counter:
    MRC p15,0,r0,c9,c13,0
    
    BX lr
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_PMU_write_cycle_counter                                      */ 
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function writes PMU cycle counter                            */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      Write value                                                       */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/**************************************************************************/  
@void cp15_PMU_write_cycle_counter(kal_uint32) 
@{ 
    CP15_PMU_WRITE_CYCLE_COUNTER_PLACEMENT
    .global cp15_PMU_write_cycle_counter
    FUNC_ATTR(cp15_PMU_write_cycle_counter)
	
cp15_PMU_write_cycle_counter:
    MCR p15,0,r0,c9,c13,0
    
    BX lr
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_PMU_read_event_counter                                       */ 
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads PMU event counter                             */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      Event counter number                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/**************************************************************************/  
@kal_uint32 cp15_PMU_read_cycle_counter(void) 
@{ 
    CP15_PMU_READ_EVENT_COUNTER_PLACEMENT
    .global cp15_PMU_read_event_counter
    FUNC_ATTR(cp15_PMU_read_event_counter)
	
cp15_PMU_read_event_counter:
    MCR p15,0,r0,c9,c12,5    @ Counter selection
    MRC p15,0,r0,c9,c13,2    @ Event counter value
    
    BX lr
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_PMU_write_event_counter                                      */ 
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function writes PMU event counter                            */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      Event counter number                                              */ 
@/*      write value                                                       */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/**************************************************************************/  
@void cp15_PMU_read_cycle_counter(kal_uint32, kal_uint32) 
@{ 
    CP15_PMU_WRITE_EVENT_COUNTER_PLACEMENT
    .global cp15_PMU_write_event_counter
    FUNC_ATTR(cp15_PMU_write_event_counter)
	
cp15_PMU_write_event_counter:
    MCR p15,0,r0,c9,c12,5    @ Counter selection
    MCR p15,0,r1,c9,c13,2    @ Event counter value
    
    BX lr
@}

@/**************************************************************************/
@ * Performance Monitor APIs <--
@ **************************************************************************/
#if defined(MT6280) && defined(__MODEM_CARD__)
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_arm_wfi_loop                                                 */ 
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function traps arm core in a WFI loop                        */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/**************************************************************************/  
@ NOTE: Special code for MT6280 DataCard SW running on WIFI-router chips
@       In this function, we set the flag and then goes into WFI
@       If ARM core unexpectedly wake up, clear the flag and loop back to WFI again
@
@       For MT6280, this code is compiled with CR4 environment, but should be running by ARM9. 
@       The assumption is that the ISAs are compatible between CR4 and ARM9
    .code 32
    CP15_ARM_WFI_LOOP_PLACEMENT
    .global cp15_arm_wfi_loop
    FUNC_ATTR(cp15_arm_wfi_loop)
	
cp15_arm_wfi_loop:
    LDR r0,=copro_wfi_flag
    MOV r1,#0x1
    STR r1,[r0]
    MOV r0, #0
    MCR p15,0,r0,c7,c0,4
    LDR r0,=copro_wfi_flag
    MOV r1,#0x0
    STR r1,[r0]
    B cp15_arm_wfi_loop

#endif /* MT6280 && __MODEM_CARD__ */
