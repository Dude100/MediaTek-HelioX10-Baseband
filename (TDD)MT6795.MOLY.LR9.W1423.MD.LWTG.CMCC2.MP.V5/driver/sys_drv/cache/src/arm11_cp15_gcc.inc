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
 *   arm11_cp15.inc
 * 
 * Project: 
 * -------- 
 *   MAUI 
 * 
 * Description: 
 * ------------ 
 *   CP15 related functions for ARM11
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
 *------------------------------------------------------------------------------ 
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================ 
 ****************************************************************************/ 
   
@/****************************************************************************
@ *     Define Constants
@ ****************************************************************************/  
      
    .equ C1_VBIT_MASK, 0x00002000  
    .equ C1_IBIT, 0x00001000 
    .equ C1_CBIT, 0x00000004 
    .equ C1_MBIT, 0x00000001 
    .equ C1_SBIT, 0x00000100 
    .equ C1_RBIT, 0x00000200 
    .equ C1_ABIT, 0x00000002 
    .equ C1_UBIT, 0x00400000
    .equ C1_XPBIT, 0x00800000
    .equ C1_ZBIT, 0x00000800
    .equ C9_ENABLE_BIT, 0x00000001 
    .equ C1_RRBIT, 0x00004000
    .equ C1_NSBIT, 0x00000001
    .equ TCM_BADDR_MASK, 0x0000003F

    .equ ARM_DMA_STATUS_MASK, 0x00000003
    .equ ARM_DMA_STATUS_DONE, 0x00000003
 
    .equ ICACHE_ENABLE,  0x1000
    .equ DCACHE_ENABLE,  0x4
    .equ RR_REPLACEMENT_ENABLE,   0x4000
    .equ FPU_COPRO,    0xF00000

@/****************************************************************************
@ *     Define Global Variables
@ ****************************************************************************/ 
@    AREA |INTSRAM_RW|, DATA, READWRITE
    .section "INTSRAM_RW","w",%progbits
    .global cache_line_nr
cache_line_nr:
    .word     0x1000  

    .global cache_line_nr_per_way
cache_line_nr_per_way:
    .word     0x400
 
@    AREA |NONCACHEDRW|, DATA, READWRITE
    .section "NONCACHEDRW","w",%progbits
C1_NSA:
    .word     0x00033FFF

@/****************************************************************************
@ *     CP15 APIs
@ ****************************************************************************/  
@    AREA |C$$code|, CODE, READONLY 
    .section ".text","ax"
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_cache_type                                              */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads the cache type.                               */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      cache type                                                        */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@UINT32 cp15_read_cache_type(VOID) 
@{ 
    .global cp15_read_cache_type 
    .type cp15_read_cache_type,STT_FUNC
cp15_read_cache_type:
 
    MRC p15,0,r0,c0,c0,1 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_enable_icache                                                */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function enables I-Cache.                                    */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_enable_icache(VOID) 
@{ 
    .global cp15_enable_icache 
    .type cp15_enable_icache,STT_FUNC
cp15_enable_icache:
 
    MRC p15,0,r0,c1,c0,0 
    ORR r0,r0,#C1_IBIT 
    MCR p15,0,r0,c1,c0,0 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_disable_icache                                               */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function disables I-Cache.                                   */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_disable_icache(VOID) 
@{ 
    .global cp15_disable_icache 
    .type cp15_disable_icache,STT_FUNC
cp15_disable_icache:
 
    MRC p15,0,r0,c1,c0,0 
    BIC r0,r0,#C1_IBIT 
    MCR p15,0,r0,c1,c0,0 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_invalidate_icache                                            */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function invalidates I-Cache.                                */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_invalidate_icache(VOID) 
@{ 
    .global cp15_invalidate_icache 
    .type cp15_invalidate_icache,STT_FUNC
cp15_invalidate_icache:
 
    MOV r0,#0 
    MCR p15,0,r0,c7,c5,0 
 
    BX lr 
@} 

@    AREA |INTERNCODE|, CODE, READONLY
    .section "INTSRAM_ROCODE","ax"

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
@/* AREA                                                                   */
@/*      INTERNCODE                                                        */
@/**************************************************************************/  
@VOID cp15_invalidate_icache_single(UINT32 MVA) 
@{ 
    .global cp15_invalidate_icache_single 
    .type cp15_invalidate_icache_single,STT_FUNC
cp15_invalidate_icache_single:

@   /* quarantee 8-word alignment */
    MOV r0,r0,LSR #5 
    MOV r0,r0,LSL #5 
    MCR p15,0,r0,c7,c5,1 
 
    BX lr 
@} 
 
@    AREA |C$$code|, CODE, READONLY 
    .section ".text","ax"
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_enable_dcache                                                */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function enables D-Cache.                                    */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_enable_dcache(VOID) 
@{ 
    .global cp15_enable_dcache 
    .type cp15_enable_dcache,STT_FUNC
cp15_enable_dcache:
 
    MRC p15,0,r0,c1,c0,0 
    ORR r0,r0,#C1_CBIT 
    MCR p15,0,r0,c1,c0,0 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_disable_dcache                                               */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function disables D-Cache.                                   */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_disable_dcache(VOID) 
@{ 
    .global cp15_disable_dcache 
    .type cp15_disable_dcache,STT_FUNC
cp15_disable_dcache:
 
    MRC p15,0,r0,c1,c0,0 
    BIC r0,r0,#C1_CBIT 
    MCR p15,0,r0,c1,c0,0 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_invalidate_dcache                                            */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function invalidates D-Cache.                                */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_invalidate_dcache(VOID) 
@{ 
    .global cp15_invalidate_dcache 
    .type cp15_invalidate_dcache,STT_FUNC
cp15_invalidate_dcache:
 
    MOV r0,#0 
    MCR p15,0,r0,c7,c6,0 
 
    BX lr 
@} 
 
@    AREA |INTERNCODE|, CODE, READONLY 
    .section "INTSRAM_ROCODE","ax"
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
@/* AREA                                                                   */
@/*      INTERNCODE                                                        */
@/**************************************************************************/  
@VOID cp15_invalidate_dcache_single(UINT32 MVA) 
@{ 
    .global cp15_invalidate_dcache_single 
    .type cp15_invalidate_dcache_single,STT_FUNC
cp15_invalidate_dcache_single:

@   /* quarantee 8-word alignment */
    MOV r0,r0,LSR #5 
    MOV r0,r0,LSL #5 
    MCR p15,0,r0,c7,c6,1 
 
    BX lr 
@}

@    AREA |C$$code|, CODE, READONLY 
    .section ".text","ax"
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
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_clean_dcache_single(UINT32 MVA) 
@{ 
    .global cp15_clean_dcache_single 
    .type cp15_clean_dcache_single,STT_FUNC
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
@/*      cp15_drain_write_buffer                                           */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function drains write buffer.                                */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_drain_write_buffer(VOID) 
@{ 
    .global cp15_drain_write_buffer 
    .type cp15_drain_write_buffer,STT_FUNC
cp15_drain_write_buffer:

    MOV r0,#0 
    MCR p15,0,r0,c7,c10,4
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_inst_synchronization_barrier                                 */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function flushes prefetch buffer.                            */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_inst_synchronization_barrier(VOID) 
@{ 
    .global cp15_inst_synchronization_barrier 
    .type cp15_inst_synchronization_barrier,STT_FUNC
cp15_inst_synchronization_barrier:

    MOV r0,#0 
    MCR p15,0,r0,c7,c5,4
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_tcm_status                                              */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads the TCM status register.                      */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      TCM status register                                               */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@UINT32 cp15_read_tcm_status(VOID) 
@{ 
    .global cp15_read_tcm_status 
    .type cp15_read_tcm_status,STT_FUNC
cp15_read_tcm_status:
 
    MRC p15,0,r0,c0,c0,2 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_itcm_region                                             */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads the I-TCM region register.                    */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      I-TCM region register                                             */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@UINT32 cp15_read_itcm_region(VOID) 
@{ 
    .global cp15_read_itcm_region 
    .type cp15_read_itcm_region,STT_FUNC
cp15_read_itcm_region:
 
    MRC p15,0,r0,c9,c1,1 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_dtcm_region                                             */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads the D-TCM region register.                    */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      D-TCM region register                                             */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@UINT32 cp15_read_dtcm_region(VOID) 
@{ 
    .global cp15_read_dtcm_region 
    .type cp15_read_dtcm_region,STT_FUNC
cp15_read_dtcm_region:
 
    MRC p15,0,r0,c9,c1,0 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_tcm_select                                                   */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function select the which tcm to be configured               */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      0: Configure TCM0                                                 */ 
@/*      1: Configure TCM1                                                 */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_tcm_select(UINT32 value) 
@{ 
    .global cp15_tcm_select
    .type cp15_tcm_select,STT_FUNC
cp15_tcm_select:
 
    MCR p15,0,r0,c9,c2,0 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_itcm_secure_access                                           */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function enable/disable secure                               */
@/*      access of ITCM Region Register                                    */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      0: ITCM Region Register can be accessed only in Secure mode       */ 
@/*      1: ITCM Region Register can be accessed in any mode               */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_itcm_secure_access(UINT32 value) 
@{ 
    .global cp15_itcm_secure_access
    .type cp15_itcm_secure_access,STT_FUNC
cp15_itcm_secure_access:
 
    MCR p15,0,r0,c9,c1,3 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_dtcm_secure_access                                           */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function enable/disable secure                               */
@/*      access of DTCM Region Register                                    */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      0: DTCM Region Register can be accessed only in Secure mode       */ 
@/*      1: DTCM Region Register can be accessed in any mode               */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_dtcm_secure_access(UINT32 value) 
@{ 
    .global cp15_dtcm_secure_access
    .type cp15_dtcm_secure_access,STT_FUNC
cp15_dtcm_secure_access:
 
    MCR p15,0,r0,c9,c1,2 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_enable_itcm                                                  */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function enables I-TCM.                                      */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      Base addr of I-TCM                                                */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_enable_itcm(UINT32 addr) 
@{ 
    .global cp15_enable_itcm 
    .type cp15_enable_itcm,STT_FUNC
cp15_enable_itcm:
 
    MRC p15,0,r1,c9,c1,1 
    AND r1,r1,#TCM_BADDR_MASK
    ORR r0,r0,#C9_ENABLE_BIT 
    ORR r0,r0,r1 
    MCR p15,0,r0,c9,c1,1 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_enable_dtcm                                                  */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function enables D-TCM.                                      */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      base address of D-TCM                                             */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_enable_dtcm(UINT32 addr) 
@{ 
    .global cp15_enable_dtcm 
    .type cp15_enable_dtcm,STT_FUNC
cp15_enable_dtcm:
 
    MRC p15,0,r1,c9,c1,0 
    AND r1,r1,#TCM_BADDR_MASK
    ORR r0,r0,#C9_ENABLE_BIT 
    ORR r0,r0,r1 
    MCR p15,0,r0,c9,c1,0 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_set_ttbcr                                                    */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function sets Translation Table Base Control Register        */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      TBBR                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_set_ttbcr(UINT32 ttbcr) 
@{ 
    .global cp15_set_ttbcr
    .type cp15_set_ttbcr,STT_FUNC
cp15_set_ttbcr:
 
    MRC p15,0,r0,c2,c0,2 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_tbbr                                                    */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads TBBR(Translation Table Base Register).        */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      TBBR                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@UINT32 cp15_read_tbbr(VOID) 
@{ 
    .global cp15_read_tbbr 
    .type cp15_read_tbbr,STT_FUNC
cp15_read_tbbr:
 
    MRC p15,0,r0,c2,c0,0 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_write_tbbr                                                   */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function writes TBBR(Translation Table Base Register).       */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      TBBR to write                                                     */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_write_tbbr(UINT32 tbbr) 
@{ 
    .global cp15_write_tbbr 
    .type cp15_write_tbbr,STT_FUNC
cp15_write_tbbr:
 
    MCR p15,0,r0,c2,c0,0 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_tbbr1                                                   */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads TBBR(Translation Table Base Register).        */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      TBBR                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@UINT32 cp15_read_tbbr1(VOID) 
@{ 
    .global cp15_read_tbbr1 
    .type cp15_read_tbbr1,STT_FUNC
cp15_read_tbbr1:
 
    MRC p15,0,r0,c2,c0,1 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_write_tbbr1                                                  */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function writes TBBR(Translation Table Base Register).       */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      TBBR to write                                                     */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_write_tbbr1(UINT32 tbbr) 
@{ 
    .global cp15_write_tbbr1
    .type cp15_write_tbbr1,STT_FUNC
cp15_write_tbbr1:
 
    MCR p15,0,r0,c2,c0,1 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_enable_mmu                                                   */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function enables MMU.                                        */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_enable_mmu(VOID) 
@{ 
    .global cp15_enable_mmu 
    .type cp15_enable_mmu,STT_FUNC
cp15_enable_mmu:
 
    MOV r0,#0 
    MCR p15,0,r0,c8,c7,0    @ invalidate TLB 
    
    @ read cp15 control register into r3
    MRC p15, 0, r3, c1, c0, 0
    
    TST r3, #ICACHE_ENABLE
    BIC r3, r3, #ICACHE_ENABLE @ clear ICache enable bit
    MCR p15, 0, r3, c1, c0, 0  @ disable ICache first
    MCR p15, 0, r0, c7, c5, 0  @ invalidate ICache
    ORRNE r3, r3, #ICACHE_ENABLE @ restore ICache enable bit
    
    TST r3, #DCACHE_ENABLE
    MCRNE p15, 0, r0, c7, c6, 0 @ invalidate DCache
    
    @ Enable MMU  
    ORR r3, r3, #C1_MBIT        @ Set MBIT
    MCR p15, 0, r3, c1, c0, 0   @ write back!
    NOP 
    NOP 
    NOP 
    NOP 
    NOP 
    NOP 
    NOP 
    NOP 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_disable_mmu                                                  */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function disables MMU.                                       */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_disable_mmu(VOID) 
@{ 
    .global cp15_disable_mmu 
    .type cp15_disable_mmu,STT_FUNC
cp15_disable_mmu:
 
    MOV r0,#0 
    MCR p15,0,r0,c8,c7,0    @ invalidate TLB 
    
    @ read cp15 control register into r3
    MRC p15, 0, r3, c1, c0, 0
    
    TST r3, #DCACHE_ENABLE
    MCRNE p15, 0, r0, c7, c14, 0  @ clean DCache
    MCR   p15, 0, r0, c7, c10, 4  @ flush (drain) write buffer
    BIC   r3, r3, #DCACHE_ENABLE      @ disable DCache at the same time
    
    @ Disable MMU
    BIC r3, r3, #C1_MBIT       @ clear MBit 
    MCR p15, 0, r3, c1, c0,0   @ write back
    NOP 
    NOP 
    NOP 
    NOP 
    NOP 
    NOP 
    NOP 
    NOP 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_domain_access                                           */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads domain access control register.               */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      domain access control register                                    */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@UINT32 cp15_read_domain_access(VOID) 
@{ 
    .global cp15_read_domain_access 
    .type cp15_read_domain_access,STT_FUNC
cp15_read_domain_access:
 
    MRC p15,0,r0,c3,c0,0 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_write_domain_access                                          */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function writes domain access control register.              */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      domain    -    domain number to write                             */ 
@/*      access    -    access control to write                            */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_write_domain_access(UINT32 domain, UINT32 access) 
@{ 
    .global cp15_write_domain_access 
    .type cp15_write_domain_access,STT_FUNC
cp15_write_domain_access:
 
    MOV r0,r0,LSL #1 
    MOV r1,r1,LSL r0 
    MRC p15,0,r2,c3,c0,0 
    MOV r3,#3 
    MOV r3,r3,LSL r0 
    BIC r2,r2,r3 
    ORR r2,r2,r1 
    MCR p15,0,r2,c3,c0,0 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_ifsr                                                    */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads IFSR(Instruction Fault Status Register).      */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      instruction fault status register                                 */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@UINT32 cp15_read_ifsr(VOID) 
@{ 
    .global cp15_read_ifsr 
    .type cp15_read_ifsr,STT_FUNC
cp15_read_ifsr:
 
    MRC p15,0,r0,c5,c0,1 
 
    BX lr 
@} 
 
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
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@UINT32 cp15_read_dfsr(VOID) 
@{ 
    .global cp15_read_dfsr 
    .type cp15_read_dfsr,STT_FUNC
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
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@UINT32 cp15_read_far(VOID) 
@{ 
    .global cp15_read_far 
    .type cp15_read_far,STT_FUNC
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
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@UINT32 cp15_read_ifar(VOID) 
@{ 
    .global cp15_read_ifar 
    .type cp15_read_ifar,STT_FUNC
cp15_read_ifar:
 
    MRC p15,0,r0,c6,c0,2 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_invalidate_tlb_single                                        */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function invalidates a sinel entry via MVA.                  */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      MVA                                                               */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      VOID                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@UINT32 cp15_invalidate_tlb_single(UINT32 MVA) 
@{ 
    .global cp15_invalidate_tlb_single 
    .type cp15_invalidate_tlb_single,STT_FUNC
cp15_invalidate_tlb_single:
 
@   /* quarantee 1KB alignment */
    MOV r0,r0,LSR #10
    MOV r0,r0,LSL #10
    MCR p15,0,r0,c8,c7,1 

    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_invalidate_tlb                                               */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function invalidates TLB.                                    */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_invalidate_tlb(VOID) 
@{ 
    .global cp15_invalidate_tlb
    .type cp15_invalidate_tlb,STT_FUNC
cp15_invalidate_tlb:
 
    MOV r0,#0
    MCR p15,0,r0,c8,c7,0

    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_enable_rom_protect                                           */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function enables ROM protection.                             */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_enable_rom_protect(VOID) 
@{ 
    .global cp15_enable_rom_protect 
    .type cp15_enable_rom_protect,STT_FUNC
cp15_enable_rom_protect:
 
    MRC p15,0,r0,c1,c0,0 
    ORR r0,r0,#C1_RBIT 
    MCR p15,0,r0,c1,c0,0 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_disable_rom_protect                                          */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function disables ROM protection.                            */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_disable_rom_protect(VOID) 
@{ 
    .global cp15_disable_rom_protect 
    .type cp15_disable_rom_protect,STT_FUNC
cp15_disable_rom_protect:
 
    MRC p15,0,r0,c1,c0,0 
    BIC r0,r0,#C1_RBIT 
    MCR p15,0,r0,c1,c0,0 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_enable_sys_protect                                           */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function enables system protection.                          */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_enable_sys_protect(VOID) 
@{ 
    .global cp15_enable_sys_protect 
    .type cp15_enable_sys_protect,STT_FUNC
cp15_enable_sys_protect:
 
    MRC p15,0,r0,c1,c0,0 
    ORR r0,r0,#C1_SBIT 
    MCR p15,0,r0,c1,c0,0 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_disable_sys_protect                                          */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function disables system protection.                         */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_disable_sys_protect(VOID) 
@{ 
    .global cp15_disable_sys_protect 
    .type cp15_disable_sys_protect,STT_FUNC
cp15_disable_sys_protect:
 
    MRC p15,0,r0,c1,c0,0 
    BIC r0,r0,#C1_SBIT 
    MCR p15,0,r0,c1,c0,0 
 
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
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_enable_alignment_fault(VOID) 
@{ 
    .global cp15_enable_alignment_fault
    .type cp15_enable_alignment_fault,STT_FUNC
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
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_disable_alignment_fault(VOID) 
@{ 
    .global cp15_disable_alignment_fault
    .type cp15_disable_alignment_fault,STT_FUNC
cp15_disable_alignment_fault:
 
    MRC p15,0,r0,c1,c0,0 
    BIC r0,r0,#C1_ABIT 
    MCR p15,0,r0,c1,c0,0 
 
    BX lr 
@} 

@    AREA |INTSRAM_ROCODE|, CODE, READONLY
    .section "INTSRAM_ROCODE","ax"
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
@/* AREA                                                                   */
@/*      INTSRAM_ROCODE                                                    */
@/**************************************************************************/  
@VOID cp15_enter_low_pwr_state(VOID) 
@{ 
    .global cp15_enter_low_pwr_state 
    .type cp15_enter_low_pwr_state,STT_FUNC
cp15_enter_low_pwr_state:
 
    MCR p15,0,r0,c7,c0,4 
 
    BX lr 
@} 

@    AREA |C$$code|, CODE, READONLY 
    .section ".text","ax"
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_invalidate_idcache_single                                    */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function invalidates ICache and DCache for the MVA           */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      MVA                                                               */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_invalidate_idcache_single(UINT32 MVA) 
@{ 
    .global cp15_invalidate_idcache_single 
    .type cp15_invalidate_idcache_single,STT_FUNC
cp15_invalidate_idcache_single:
 
@   /* quarantee 8-word alignment */
    MOV r0,r0,LSR #5 
    MOV r0,r0,LSL #5 

@   /* invalidate ICache */
    MCR p15,0,r0,c7,c5,1 

@   /* invalidate DCache */
    MCR p15,0,r0,c7,c6,1 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_invalidate_idcache_region                                    */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function invalidates ICache and DCache for the               */  
@/*      specified regions                                                 */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      addr        -   start address of the region                       */ 
@/*      nr_cache    -   number of cache entires                           */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_invalidate_idcache_region(UINT32 addr, UINT32 nr_cache) 
@{ 
    .global cp15_invalidate_idcache_region 
    .type cp15_invalidate_idcache_region,STT_FUNC
cp15_invalidate_idcache_region:

    CMP r1,#0
    BEQ invalidate_idcache_end

invalidate_idcache_begin:
    MCR p15,0,r0,c7,c5,1 
    MCR p15,0,r0,c7,c6,1 
    ADD r0,r0,#32
    SUBS r1,r1,#1    
    BNE invalidate_idcache_begin

invalidate_idcache_end:
    BX lr 
@} 


@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_invalidate_icache_region                                     */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function invalidates ICachefor the specified regions         */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      addr        -   start address of the region                       */ 
@/*      nr_cache    -   number of cache entires                           */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_invalidate_icache_region(UINT32 addr, UINT32 nr_cache) 
@{ 
    .global cp15_invalidate_icache_region 
    .type cp15_invalidate_icache_region,STT_FUNC
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
@/*      cp15_invalidate_dcache_region                                     */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function invalidates ICachefor the specified regions         */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      addr        -   start address of the region                       */ 
@/*      nr_cache    -   number of cache entires                           */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_invalidate_dcache_region(UINT32 addr, UINT32 nr_cache) 
@{ 
    .global cp15_invalidate_dcache_region 
    .type cp15_invalidate_dcache_region,STT_FUNC
cp15_invalidate_dcache_region:
    CMP r1,#0
    BEQ invalidate_dcache_end
    
    @ If region > cache size, do invalidate and clean all to improve responsiveness
    LDR r2,=cache_line_nr
    LDR r2,[r2]
    
    CMP r1,r2
    BGT cp15_clean_and_invalidate_all_dcache_by_setway

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
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
    .global cp15_clean_and_invalidate_dcache_by_setway
    .type cp15_clean_and_invalidate_dcache_by_setway,STT_FUNC
cp15_clean_and_invalidate_dcache_by_setway:
    LSL r1,r1,#30
    LSL r0,r0,#5
    ORR r0,r0,r1
    MCR p15,0,r0,c7,c14,2 @ Clean/Invalidate set way
    MOV r0,#0
    MCR p15,0,r0,c7,c10,4 @ Drain write buffer
    
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
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_clean_all_dcache_by_setway(void) 
@{ 
    .global cp15_clean_all_dcache_by_setway 
    .type cp15_clean_all_dcache_by_setway,STT_FUNC
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
    .global cp15_clean_and_invalidate_all_dcache_by_setway 
    .type cp15_clean_and_invalidate_all_dcache_by_setway,STT_FUNC
cp15_clean_and_invalidate_all_dcache_by_setway:
    MOV r2,#0xC0000000     @ the way number

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
@/*      cp15_clean_dcache_region                                          */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function clean DCache for the specified regions              */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      addr        -   start address of the region                       */ 
@/*      nr_cache    -   number of cache entires                           */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_clean_dcache_region(UINT32 addr, UINT32 nr_cache) 
@{ 
    .global cp15_clean_dcache_region 
    .type cp15_clean_dcache_region,STT_FUNC
cp15_clean_dcache_region:
    CMP r1,#0
    BEQ clean_dcache_end
    
    @ If the target region > cache size, clean all DCache to improve the response time
    LDR r2,=cache_line_nr
    LDR r2,[r2]
    
    CMP r1,r2
    BGT cp15_clean_all_dcache_by_setway

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
@/*      cp15_invalidate_idcache_region_ext                                */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function invalidates ICache and DCache for the               */  
@/*      specified regions                                                 */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      start_addr  -   start address of the region                       */ 
@/*      end_addr    -   end address of the region                         */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_invalidate_idcache_region_ext(UINT32 start_addr, UINT32 end_addr) 
@{ 
    .global cp15_invalidate_idcache_region_ext 
    .type cp15_invalidate_idcache_region_ext,STT_FUNC
cp15_invalidate_idcache_region_ext:

    SUB r1, r1, #1
    MCRR p15,0,r1,r0,c5 
    MCRR p15,0,r1,r0,c6 
    
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
@/*      This function clean and invalidates DCache for                    */
@/*      the specified regions                                             */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      addr        -   start address of the region                       */ 
@/*      nr_cache    -   number of cache entires                           */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
    .global cp15_clean_and_invalidate_dcache_region 
    .type cp15_clean_and_invalidate_dcache_region,STT_FUNC
cp15_clean_and_invalidate_dcache_region:

    CMP r1,#0
    BEQ clean_and_invalidate_dcache_end

    @ If region > cache size, do invalidate and clean all to improve responsiveness
    LDR r2,=cache_line_nr
    LDR r2,[r2]
    
    CMP r1,r2
    BGT cp15_clean_and_invalidate_all_dcache_by_setway

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
@/*      cp15_lockdown_TLB_entry                                           */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function configures ARM9 to lock down TLB entry.             */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      MVA                                                               */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/
@/**************************************************************************
@ * NOTE:
@ *     The TLB lockdown sequence is written according to ARM document.
@ *     There is one known-issue (limitation) for this sequence
@ *     
@ *     Current implementation cannot lockdown the TLB page which 
@ *     contains THIS function. (Usually the page starts at 0x0)
@ *     
@ **************************************************************************/  
@VOID cp15_lockdown_TLB_entry(unsigned int addr) 
@{ 
    .global cp15_lockdown_TLB_entry 
    .type cp15_lockdown_TLB_entry,STT_FUNC
cp15_lockdown_TLB_entry:
    MCR p15, 0, r0, c8, c7, 1
    MRC p15, 0, r1, c10, c0, 0
    ORR r1, r1, #1
    MCR p15, 0, r1, c10, c0, 0
    LDR r0, [r0]
    MRC p15, 0, r1, c10, c0, 0
    BIC r1, r1, #1
    MCR p15, 0, r1, c10, c0, 0
 
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
@/*      This function returns whether ICache is enabled                   */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*      1: Enabled                                                        */ 
@/*  Other: Disabled                                                       */
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@BOOL cp15_is_icache_enabled(VOID) 
@{ 
    .global cp15_is_icache_enabled 
    .type cp15_is_icache_enabled,STT_FUNC
cp15_is_icache_enabled:

    MRC      p15, 0, a4, c1, c0, 0
    ANDS     a1, a4, #ICACHE_ENABLE 
    MOVNE    a1, #1
   
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
@/*      This function returns whether DCache is enabled                   */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*      1: Enabled                                                        */ 
@/*  Other: Disabled                                                       */
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@BOOL cp15_is_dcache_enabled(VOID) 
@{ 
    .global cp15_is_dcache_enabled 
    .type cp15_is_dcache_enabled,STT_FUNC
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
@/*      cp15_set_idcache_replacement_policy                               */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*       This function set the Cache replacement policy to                */  
@/*       round-robin or Random                                            */
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      0: Random                                                         */ 
@/*  Other: Round-robin                                                    */
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_set_idcache_replacement_policy(VOID) 
@{ 
    .global cp15_set_idcache_replacement_policy  
    .type cp15_set_idcache_replacement_policy,STT_FUNC
    .global cp15_set_idcache_replacement  
    .type cp15_set_idcache_replacement,STT_FUNC
cp15_set_idcache_replacement:
cp15_set_idcache_replacement_policy:
    MCR     p15, 0, a4, c7, c5, 0            @ Invalidate I-Cache
                @ SHK: It is the command to flush the I-Cache, where c5 is only used to be explained
                @ by the Co-processor to know what this instruction want to do.   
    MRC     p15, 0, a4, c1, c0, 0
 
    CMP     a1, #0          @ SHK: If input is 0, set as Random policy.
    BICEQ   a4, a4, #RR_REPLACEMENT_ENABLE
    ORRNE   a4, a4, #RR_REPLACEMENT_ENABLE   @ SHK: Else, set as Round-robin policy.
    
    MCR     p15, 0, a4, c1, c0, 0
    
    NOP             @ SHK: Ensure that all instructions are returned from I-Cache after enabling it.
                  @   To prevent some instructions are pre-fetched in the pipeline.
    NOP
    NOP
    NOP
    NOP
    
    BX lr 
@} 


@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_clean_dcache                                                 */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function clean entire DCache                                 */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_clean_DCache(VOID) 
@{ 
    .global cp15_clean_dcache
    .type cp15_clean_dcache,STT_FUNC
cp15_clean_dcache:
    MOV      r0,#0
    MCR      p15,0,r0,c7,c14,0   
    MCR      p15, 0, r0, c7, c10, 4      @ Flush (drain) the write buffer
    
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_is_fpu_enabled                                               */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function checks whether ARM FPU is enabled                   */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      1: Enabled                                                        */ 
@/*      0: Disabled                                                       */
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@ Query if FPU is enabled
@ Return 1 if FPU is enabled, else return 0
@ BOOL cp15_is_fpu_enabled(VOID)
@ {
    .global cp15_is_fpu_enabled
    .type cp15_is_fpu_enabled,STT_FUNC
cp15_is_fpu_enabled:
    MRC    p15,0,r0,c1,c0,2
    AND    r0,r0,#FPU_COPRO         @ Check CP11 on
    CMP    r0,#FPU_COPRO
    MOVEQ  r0,#1
    MOVNE  r0,#0
    BX lr        
@ }

@    IF ESAL_AR_STK_FPU_SUPPORT
#if defined(ESAL_AR_STK_FPU_SUPPORT)
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_enable_cp                                                    */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function enables ARM cp10 and cp11 (VFP)                     */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/ 
@ Enable ARM VFP (cp11 and cp10)
@kal_uint32 cp15_enable_cp(VOID)
@{
    .global cp15_enable_cp
    .type cp15_enable_cp,STT_FUNC
cp15_enable_cp:
    LDR    r0, =0x00F00000
    MCR    p15,0,r0,c1,c0,2
    BX lr
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      set_fpu_runfastmode                                               */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function sets VFP as Runfast mode                            */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/ 
@VOID set_fpu_runfastmode(VOID)
@{
    .global set_fpu_runfastmode
    .type set_fpu_runfastmode,STT_FUNC
set_fpu_runfastmode:
    FMRX    r0, FPSCR
    BIC     r0, r0, #0x00009f00
    ORR     r0, r0, #0x03000000
    FMXR    FPSCR, r0
    BX lr
@}


@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      set_fpu_ieeenofenvmode                                            */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function sets VFP as ieee_no_fenv mode                       */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/ 
@VOID set_fpu_ieeenofenvmode(VOID)
@{
    .global set_fpu_ieeenofenvmode
    .type set_fpu_ieeenofenvmode,STT_FUNC
set_fpu_ieeenofenvmode:
    FMRX    r0, FPSCR
    BIC     r0, r0, #0x03000000
    BIC     r0, r0, #0x00009f00
    FMXR    FPSCR, r0
    BX lr
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      enable_arm_fpu                                                    */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function enables VFP                                         */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/ 
@VOID enable_arm_fpu(VOID)
@{
    .global enable_arm_fpu
    .type enable_arm_fpu,STT_FUNC
enable_arm_fpu:
    FMRX    r0, FPEXC
    ORR     r0, r0, #0x40000000
    FMXR    FPEXC, r0
    BX lr
@}
#endif // ESAL_AR_STK_FPU_SUPPORT
    
@    AREA |INTERNCODE|, CODE, READONLY
    .section "INTSRAM_ROCODE","ax"
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_lockdown_icache                                              */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function locks down I-CACHE.                                 */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*       L   -   L bit of C9                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      INTERNCODE                                                        */
@/**************************************************************************/  
@VOID cp15_lockdown_icache(UINT L)
@{ 
    .global cp15_lockdown_icache
    .type cp15_lockdown_icache,STT_FUNC
cp15_lockdown_icache:
    MCR p15,0,r0,c7,c10,4
    MRC p15,0,r1,c9,c0,1
    MOV r0,r0,LSL #28
    MOV r0,r0,LSR #28
    MOV r1,r1,LSR #4
    MOV r1,r1,LSL #4
    ORR r1,r1,r0
    MCR p15,0,r1,c9,c0,1
   
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_lockdown_dcache                                              */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function locks down D-CACHE.                                 */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*       L   -   L bit of C9                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      INTERNCODE                                                        */
@/**************************************************************************/  
@VOID cp15_lockdown_dcache(UINT L)
@{ 
    .global cp15_lockdown_dcache
    .type cp15_lockdown_dcache,STT_FUNC
cp15_lockdown_dcache:
    MCR p15,0,r0,c7,c10,4
    MRC p15,0,r1,c9,c0,0
    MOV r0,r0,LSL #28
    MOV r0,r0,LSR #28
    MOV r1,r1,LSR #4
    MOV r1,r1,LSL #4
    ORR r1,r1,r0
    MCR p15,0,r1,c9,c0,0
   
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_prefetch_icache_line                                         */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function pre-fetches I-CACHE line.                           */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*       mva   -   address to pre-fetch                                   */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */
@/*                                                                        */
@/* AREA                                                                   */
@/*      INTERNCODE                                                        */ 
@/**************************************************************************/  
@VOID cp15_prefetch_icache_line(UINT mva)
@{ 
    .global cp15_prefetch_icache_line
    .type cp15_prefetch_icache_line,STT_FUNC
cp15_prefetch_icache_line:

    MCR p15, 0, r0, c7, c13, 1
   
    BX lr 
@} 
@    AREA |C$$code|, CODE, READONLY
    .section ".text","ax"
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_disable_ap_subpage                                           */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function disable ap subpage.                                 */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/  
@VOID cp15_disable_ap_subpage(VOID) 
@{ 
    .global cp15_disable_ap_subpage
    .type cp15_disable_ap_subpage,STT_FUNC
cp15_disable_ap_subpage:
 
    MRC p15,0,r0,c1,c0,0 
    ORR r0,r0,#C1_XPBIT 
    MCR p15,0,r0,c1,c0,0 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_enable_branch_prediction                                     */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function enable branch prediction.                           */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/  
@VOID cp15_enable_branch_prediction(VOID) 
@{ 
    .global cp15_enable_branch_prediction
    .type cp15_enable_branch_prediction,STT_FUNC
cp15_enable_branch_prediction:
 
    MRC p15,0,r0,c1,c0,0 
    ORR r0,r0,#C1_ZBIT 
    MCR p15,0,r0,c1,c0,0 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_cache_size                                              */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function read tcm/cache size                                 */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/  
@kal_uint32 cp15_read_tcm_cache_size(VOID) 
@{ 
    .global cp15_read_tcm_cache_size
    .type cp15_read_tcm_cache_size,STT_FUNC
cp15_read_tcm_cache_size:
 
    MRC p15,0,r0,c15,c14,0 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_tcm_status                                                   */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads tcm status register                           */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/ 
@kal_uint32 cp15_tcm_status(void)
@{ 
    .global cp15_tcm_status
    .type cp15_tcm_status,STT_FUNC
cp15_tcm_status:

    MRC p15, 0, r0, c0, c0, 2
   
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_itcm                                                    */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads itcm region register                          */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/ 
@kal_uint32 cp15_read_itcm(void) 
@{ 
    .global cp15_read_itcm 
    .type cp15_read_itcm,STT_FUNC
cp15_read_itcm:
 
    MRC p15,0,r0,c9,c1,1 
 
    BX lr 
@} 
 
@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_dtcm                                                    */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads dtcm region register                          */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/ 
@kal_uint32 cp15_read_dtcm(void) 
@{ 
    .global cp15_read_dtcm 
    .type cp15_read_dtcm,STT_FUNC
cp15_read_dtcm:
 
    MRC p15,0,r0,c9,c1,0 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_switch_cache2RR                                              */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function set cache replacement policy to round-robin         */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/ 
@VOID cp15_switch_cache2RR(VOID) 
@{ 
    .global cp15_switch_cache2RR 
    .type cp15_switch_cache2RR,STT_FUNC
cp15_switch_cache2RR:
 
    MRC p15,0,r0,c1,c0,0 
    ORR r0,r0,#C1_RRBIT 
    MCR p15,0,r0,c1,c0,0 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_read_ctrl_register                                           */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads cp15 control register                         */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/ 
@VOID cp15_read_ctrl_register(VOID) 
@{ 
    .global cp15_read_ctrl_register 
    .type cp15_read_ctrl_register,STT_FUNC
cp15_read_ctrl_register:
 
    MRC p15,0,r0,c1,c0,0 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_set_ns_bit                                                   */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function sets CPU to Non-secure world                        */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/ 
@VOID cp15_set_ns_bit(VOID) 
@{ 
    .global cp15_set_ns_bit 
    .type cp15_set_ns_bit,STT_FUNC
cp15_set_ns_bit:
 
    MRC p15,0,r0,c1,c1,0 
    ORR r0,r0,#C1_NSBIT
    MCR p15,0,r0,c1,c1,0 

    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_Cache_Behavior                                               */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function reads cache behavior override register              */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/ 
@VOID cp15_Cache_Behavior(VOID) 
@{ 
    .global cp15_Cache_Behavior 
    .type cp15_Cache_Behavior,STT_FUNC
cp15_Cache_Behavior:
    MRC p15, 0, r0, c9, c8, 0
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_Non_Secure_Access                                            */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function WRITES Non-secure access control register           */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/ 
 @VOID cp15_Non_Secure_Access(VOID) 
@{ 
    .global cp15_Non_Secure_Access 
    .type cp15_Non_Secure_Access,STT_FUNC
cp15_Non_Secure_Access:
    LDR r0, =C1_NSA
    LDR r0, [r0]
    MCR p15, 0, r0, c1, c1, 2
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_enable_unaligned_access                                      */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function ebables unaligned access                            */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/ 
@VOID cp15_enable_unaligned_access(VOID) 
@{ 
    .global cp15_enable_unaligned_access
    .type cp15_enable_unaligned_access,STT_FUNC
cp15_enable_unaligned_access:
    MRC p15,0,r0,c1,c0,0 
    ORR r0,r0,#C1_UBIT 
    MCR p15,0,r0,c1,c0,0 
 
    BX lr 
@} 

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_switch_big_endian                                            */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function sets CPSR E bit for Big-endian configuration        */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/ 
@VOID cp15_switch_big_endian(VOID)
@{
    .global cp15_switch_big_endian
    .type cp15_switch_big_endian,STT_FUNC
cp15_switch_big_endian:
    SETEND BE
 
    BX lr 
@}

@/**************************************************************************/  
@/*                                                                        */  
@/*  FUNCTION                                                              */  
@/*                                                                        */  
@/*      cp15_switch_little_endian                                         */  
@/*                                                                        */  
@/*  DESCRIPTION                                                           */  
@/*                                                                        */  
@/*      This function clears CPSR E bit for little-endian configuration   */  
@/*                                                                        */  
@/* INPUTS                                                                 */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */ 
@/* OUTPUTS                                                                */ 
@/*                                                                        */ 
@/*      None                                                              */ 
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/ 
@VOID cp15_switch_little_endian(VOID)
@{
    .global cp15_switch_little_endian
    .type cp15_switch_little_endian,STT_FUNC
cp15_switch_little_endian:
    SETEND LE
 
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
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/  
@VOID cp15_data_memory_barrier(VOID) 
@{ 
    .global cp15_data_memory_barrier 
    .type cp15_data_memory_barrier,STT_FUNC
cp15_data_memory_barrier:
    MOV r0, #0
    MCR p15,0,r0,c7,c10,5
 
    BX lr 
@}

@/**************************************************************************
@*   ARM11 Performance Monitor APIs
@***************************************************************************/
@/**************************************************************************/
@/*                                                                        */
@/*  FUNCTION                                                              */
@/*                                                                        */
@/*      cp15_SetPerfMonitorControl                                        */
@/*                                                                        */
@/*  DESCRIPTION                                                           */
@/*                                                                        */
@/*      This function sets performance monitor control register           */
@/*                                                                        */
@/* INPUTS                                                                 */
@/*                                                                        */
@/*      CP15 C12 setting                                                  */
@/*                                                                        */
@/* OUTPUTS                                                                */
@/*                                                                        */
@/*      None                                                              */
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/
@VOID cp15_SetPerfMonitorControl(UINT32 u4PMC)
@{
    .global cp15_SetPerfMonitorControl
    .type cp15_SetPerfMonitorControl,STT_FUNC
cp15_SetPerfMonitorControl:
    MCR p15, 0, r0, c15, c12, 0

    BX lr        
@}

@/**************************************************************************/
@/*                                                                        */
@/*  FUNCTION                                                              */
@/*                                                                        */
@/*      cp15_GetCycCntRegister                                            */
@/*                                                                        */
@/*  DESCRIPTION                                                           */
@/*                                                                        */
@/*      This function gets cycle counter value                            */
@/*                                                                        */
@/* INPUTS                                                                 */
@/*                                                                        */
@/*      CP15 C12 setting                                                  */
@/*                                                                        */
@/* OUTPUTS                                                                */
@/*                                                                        */
@/*      None                                                              */
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/
@VOID cp15_GetCycCntRegister(void)
@{
    .global cp15_GetCycCntRegister
    .type cp15_GetCycCntRegister,STT_FUNC
cp15_GetCycCntRegister:
    MRC p15, 0, r0, c15, c12, 1
    
    BX lr 
@}

@/**************************************************************************/
@/*                                                                        */
@/*  FUNCTION                                                              */
@/*                                                                        */
@/*      cp15_GetPerfMonitorControl                                        */
@/*                                                                        */
@/*  DESCRIPTION                                                           */
@/*                                                                        */
@/*      This function reads performance monitor control register          */
@/*                                                                        */
@/* INPUTS                                                                 */
@/*                                                                        */
@/*      CP15 C12 setting                                                  */
@/*                                                                        */
@/* OUTPUTS                                                                */
@/*                                                                        */
@/*      None                                                              */
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/
@UINT32 cp15_GetPerfMonitorControl(void)
@{
    .global cp15_GetPerfMonitorControl
    .type cp15_GetPerfMonitorControl,STT_FUNC
cp15_GetPerfMonitorControl:
    MRC p15, 0, r0, c15, c12, 0

    BX lr
@}

@/**************************************************************************/
@/*                                                                        */
@/*  FUNCTION                                                              */
@/*                                                                        */
@/*      cp15_GetCountRegister0                                            */
@/*                                                                        */
@/*  DESCRIPTION                                                           */
@/*                                                                        */
@/*      This function reads performance counter0                          */
@/*                                                                        */
@/* INPUTS                                                                 */
@/*                                                                        */
@/*      CP15 C12 setting                                                  */
@/*                                                                        */
@/* OUTPUTS                                                                */
@/*                                                                        */
@/*      None                                                              */
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/
@UINT32 cp15_GetCountRegister0(void)
@{
    .global cp15_GetCountRegister0
    .type cp15_GetCountRegister0,STT_FUNC
cp15_GetCountRegister0:
    MRC p15, 0, r0, c15, c12, 2

    BX lr
@}

@/**************************************************************************/
@/*                                                                        */
@/*  FUNCTION                                                              */
@/*                                                                        */
@/*      cp15_SetCountRegister0                                            */
@/*                                                                        */
@/*  DESCRIPTION                                                           */
@/*                                                                        */
@/*      This function writes performance counter0                         */
@/*                                                                        */
@/* INPUTS                                                                 */
@/*                                                                        */
@/*      CP15 C12 setting                                                  */
@/*                                                                        */
@/* OUTPUTS                                                                */
@/*                                                                        */
@/*      None                                                              */
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/
@UINT32 cp15_SetCountRegister0(void)
@{
    .global cp15_SetCountRegister0
    .type cp15_SetCountRegister0,STT_FUNC
cp15_SetCountRegister0:
    MCR p15, 0, r0, c15, c12, 2

    BX lr
@}

@/**************************************************************************/
@/*                                                                        */
@/*  FUNCTION                                                              */
@/*                                                                        */
@/*      cp15_GetCountRegister1                                            */
@/*                                                                        */
@/*  DESCRIPTION                                                           */
@/*                                                                        */
@/*      This function reads performance counter1                          */
@/*                                                                        */
@/* INPUTS                                                                 */
@/*                                                                        */
@/*      CP15 C12 setting                                                  */
@/*                                                                        */
@/* OUTPUTS                                                                */
@/*                                                                        */
@/*      None                                                              */
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/
@UINT32 cp15_GetCountRegister1(void)
@{
    .global cp15_GetCountRegister1
    .type cp15_GetCountRegister1,STT_FUNC
cp15_GetCountRegister1:
    MRC p15, 0, r0, c15, c12, 3

    BX lr
@}

@/**************************************************************************/
@/*                                                                        */
@/*  FUNCTION                                                              */
@/*                                                                        */
@/*      cp15_SetCountRegister1                                            */
@/*                                                                        */
@/*  DESCRIPTION                                                           */
@/*                                                                        */
@/*      This function writes performance counter1                         */
@/*                                                                        */
@/* INPUTS                                                                 */
@/*                                                                        */
@/*      CP15 C12 setting                                                  */
@/*                                                                        */
@/* OUTPUTS                                                                */
@/*                                                                        */
@/*      None                                                              */
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/
@UINT32 cp15_SetCountRegister1(void)
@{
    .global cp15_SetCountRegister1
    .type cp15_SetCountRegister1,STT_FUNC
cp15_SetCountRegister1:
    MCR p15, 0, r0, c15, c12, 3

    BX lr
@}
@/**************************************************************************
@*   ARM11 Performance Monitor APIs END
@***************************************************************************/
@***************************************************************************/


@/**************************************************************************/
@/*                                                                        */
@/*  FUNCTION                                                              */
@/*                                                                        */
@/*      cp15_get_auxctrl_reg                                              */
@/*                                                                        */
@/*  DESCRIPTION                                                           */
@/*                                                                        */
@/*      This function reads auxiliary register                            */
@/*                                                                        */
@/* INPUTS                                                                 */
@/*                                                                        */
@/*      CP15 C1 setting                                                   */
@/*                                                                        */
@/* OUTPUTS                                                                */
@/*                                                                        */
@/*      None                                                              */
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/
@UINT32 cp15_get_auxctrl_reg(void)
@{
    .global cp15_get_auxctrl_reg
    .type cp15_get_auxctrl_reg,STT_FUNC
cp15_get_auxctrl_reg:
    MRC p15, 0, r0, c1, c0, 1

    BX lr
@}

@/**************************************************************************/
@/*                                                                        */
@/*  FUNCTION                                                              */
@/*                                                                        */
@/*      cp15_set_auxctrl_reg                                              */
@/*                                                                        */
@/*  DESCRIPTION                                                           */
@/*                                                                        */
@/*      This function sets auxiliary registers                            */
@/*                                                                        */
@/* INPUTS                                                                 */
@/*                                                                        */
@/*      CP15 C1 setting                                                   */
@/*                                                                        */
@/* OUTPUTS                                                                */
@/*                                                                        */
@/*      None                                                              */
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/
@UINT32 cp15_set_auxctrl_reg(void)
@{
    .global cp15_set_auxctrl_reg
    .type cp15_set_auxctrl_reg,STT_FUNC
cp15_set_auxctrl_reg:
    MCR p15, 0, r0, c1, c0, 1

    BX lr
@}

@/**************************************************************************
@*    ARM11 DMA APIs
@***************************************************************************/
@/**************************************************************************/
@/*                                                                        */
@/*  FUNCTION                                                              */
@/*                                                                        */
@/*      cp15_dma_sel_ch                                                   */
@/*                                                                        */
@/*  DESCRIPTION                                                           */
@/*                                                                        */
@/*      This function sets DMA channel number register (selcet channel)   */
@/*                                                                        */
@/* INPUTS                                                                 */
@/*                                                                        */
@/*                                                                        */
@/*                                                                        */
@/* OUTPUTS                                                                */
@/*                                                                        */
@/*      None                                                              */
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/
@UINT32 cp15_dma_sel_ch(unsigned int ch)
@{
    .global cp15_dma_sel_ch
    .type cp15_dma_sel_ch,STT_FUNC
cp15_dma_sel_ch:
    MCR p15, 0, r0, c11, c2, 0

    BX lr
@}

@/**************************************************************************/
@/*                                                                        */
@/*  FUNCTION                                                              */
@/*                                                                        */
@/*      cp15_dma_set_addr                                                 */
@/*                                                                        */
@/*  DESCRIPTION                                                           */
@/*                                                                        */
@/*      This function sets DMA src/dst address                            */
@/*                                                                        */
@/* INPUTS                                                                 */
@/*      r0: internal start                                                */
@/*      r1: internal end                                                  */
@/*      r2: external start                                                */
@/*                                                                        */
@/* OUTPUTS                                                                */
@/*                                                                        */
@/*      None                                                              */
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/
@UINT32 cp15_dma_set_addr(unsigned int int_str_addr, unsigned int int_end_addr, unsigned int ext_str_addr)
@{
    .global cp15_dma_set_addr
    .type cp15_dma_set_addr,STT_FUNC
cp15_dma_set_addr:
    MCR p15, 0, r0, c11, c5, 0
    MCR p15, 0, r1, c11, c7, 0
    MCR p15, 0, r2, c11, c6, 0    

    BX lr
@}

@/**************************************************************************/
@/*                                                                        */
@/*  FUNCTION                                                              */
@/*                                                                        */
@/*      cp15_dma_set_ctrl                                                 */
@/*                                                                        */
@/*  DESCRIPTION                                                           */
@/*                                                                        */
@/*      This function sets DMA control register                           */
@/*                                                                        */
@/* INPUTS                                                                 */
@/*                                                                        */
@/*                                                                        */
@/*                                                                        */
@/* OUTPUTS                                                                */
@/*                                                                        */
@/*      None                                                              */
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/
@UINT32 cp15_dma_set_ctrl(unsigned int ctrl_cfg)
@{
    .global cp15_dma_set_ctrl
    .type cp15_dma_set_ctrl,STT_FUNC
cp15_dma_set_ctrl:
    MCR p15, 0, r0, c11, c4, 0

    BX lr
@}

@/**************************************************************************/
@/*                                                                        */
@/*  FUNCTION                                                              */
@/*                                                                        */
@/*      cp15_dma_stop                                                     */
@/*                                                                        */
@/*  DESCRIPTION                                                           */
@/*                                                                        */
@/*      This function stops DMA                                           */
@/*                                                                        */
@/* INPUTS                                                                 */
@/*                                                                        */
@/*                                                                        */
@/*                                                                        */
@/* OUTPUTS                                                                */
@/*                                                                        */
@/*      None                                                              */
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/
@UINT32 cp15_dma_stop(void)
@{
        .global cp15_dma_stop
        .type cp15_dma_stop,STT_FUNC
cp15_dma_stop:
    MCR p15, 0, r0, c11, c3, 0

    BX lr
@}

@/**************************************************************************/
@/*                                                                        */
@/*  FUNCTION                                                              */
@/*                                                                        */
@/*      cp15_dma_start                                                    */
@/*                                                                        */
@/*  DESCRIPTION                                                           */
@/*                                                                        */
@/*      This function starts DMA                                          */
@/*                                                                        */
@/* INPUTS                                                                 */
@/*                                                                        */
@/*                                                                        */
@/*                                                                        */
@/* OUTPUTS                                                                */
@/*                                                                        */
@/*      None                                                              */
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/
@UINT32 cp15_dma_start(void)
@{
    .global cp15_dma_start
    .type cp15_dma_start,STT_FUNC
cp15_dma_start:
    MCR p15, 0, r0, c11, c3, 1

    BX lr
@}

@/**************************************************************************/
@/*                                                                        */
@/*  FUNCTION                                                              */
@/*                                                                        */
@/*      cp15_dma_clear                                                    */
@/*                                                                        */
@/*  DESCRIPTION                                                           */
@/*                                                                        */
@/*      This function clears DMA status                                   */
@/*                                                                        */
@/* INPUTS                                                                 */
@/*                                                                        */
@/*                                                                        */
@/*                                                                        */
@/* OUTPUTS                                                                */
@/*                                                                        */
@/*      None                                                              */
@/**************************************************************************/
@UINT32 cp15_dma_clear(void)
@{
    .global cp15_dma_clear
    .type cp15_dma_clear,STT_FUNC
cp15_dma_clear:
    MCR p15, 0, r0, c11, c3, 2

    BX lr
@}

@/**************************************************************************/
@/*                                                                        */
@/*  FUNCTION                                                              */
@/*                                                                        */
@/*      cp15_dma_polling_done                                             */
@/*                                                                        */
@/*  DESCRIPTION                                                           */
@/*                                                                        */
@/*      This function polls DMA done                                      */
@/*                                                                        */
@/* INPUTS                                                                 */
@/*                                                                        */
@/*                                                                        */
@/*                                                                        */
@/* OUTPUTS                                                                */
@/*                                                                        */
@/*      None                                                              */
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */ 
@/**************************************************************************/
@UINT32 cp15_dma_polling_done(void)
@{
    .global cp15_dma_polling_done
    .type cp15_dma_polling_done,STT_FUNC
cp15_dma_polling_done:
    MRC p15, 0, r0, c11, c8, 0
    LDR r1, =ARM_DMA_STATUS_MASK
    AND r0, r0, r1
    LDR r1, =ARM_DMA_STATUS_DONE    
    CMP r0, r1
    BNE cp15_dma_polling_done

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
@/*                                                                        */
@/* AREA                                                                   */
@/*      C$$code                                                           */
@/**************************************************************************/  
@VOID cp15_switch_vector(bool) 
@{ 
    .global cp15_switch_vector
    .type cp15_switch_vector,STT_FUNC
cp15_switch_vector:
    CMP r0,#0
    MRC p15,0,r0,c1,c0,0
    ORRNE r0,r0,#C1_VBIT_MASK
    BICEQ r0,r0,#C1_VBIT_MASK
    MCR p15,0,r0,c1,c0,0
    
    BX lr
@}
