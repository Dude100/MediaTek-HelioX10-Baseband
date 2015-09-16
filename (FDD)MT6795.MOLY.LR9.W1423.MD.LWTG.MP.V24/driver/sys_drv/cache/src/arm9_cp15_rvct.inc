;/******************************************************************************* 
;*  Copyright Statement: 
;*  -------------------- 
;*  This software is protected by Copyright and the information contained 
;*  herein is confidential. The software may not be copied and the information 
;*  contained herein may not be used or disclosed except with the written 
;*  permission of MediaTek Inc. (C) 2001 
;* 
;*******************************************************************************/ 
; 
;/******************************************************************************* 
; * 
; * Filename: 
; * --------- 
; *   arm9_cp15.inc
; * 
; * Project: 
; * -------- 
; *   MAUI 
; * 
; * Description: 
; * ------------ 
; *   CP15 related functions for ARM9
; * 
; * Author: 
; * ------- 
; * -------
; * 
; *============================================================================ 
; *             HISTORY 
; * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
; *------------------------------------------------------------------------------ 
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; *------------------------------------------------------------------------------ 
; * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
; *============================================================================ 
; ****************************************************************************/ 

        GBLL    THUMB 
        GBLL    ARM 
    [ {CONFIG} = 16 
THUMB   SETL    {TRUE} 
ARM     SETL    {FALSE} 
        CODE32 
    | 
THUMB   SETL    {FALSE} 
ARM     SETL    {TRUE} 
    ] 
    
;/****************************************************************************
; *     Define Constants
; ****************************************************************************/      
C1_IBIT                 EQU &00001000 
C1_CBIT                 EQU &00000004 
C1_MBIT                 EQU &00000001 
C1_SBIT                 EQU &00000100 
C1_RBIT                 EQU &00000200 
C1_ABIT                 EQU &00000002 
C1_UBIT                 EQU &00400000
C1_XPBIT                EQU &00800000
C1_ZBIT                 EQU &00000800
C9_ENABLE_BIT           EQU &00000001 
C1_RRBIT                EQU &00004000
C1_NSBIT                EQU &00000001
TCM_BADDR_MASK          EQU &0000003F
                        
ARM_DMA_STATUS_MASK     EQU &00000003
ARM_DMA_STATUS_DONE     EQU &00000003
 
ICACHE_ENABLE           EQU &1000
DCACHE_ENABLE           EQU &4
RR_REPLACEMENT_ENABLE   EQU &4000
FPU_COPRO               EQU 0xF00000

;/****************************************************************************
; *     Define Global Variables
; ****************************************************************************/ 
    CACHE_LINE_NR_PLACEMENT
    EXPORT cache_line_nr
cache_line_nr
    DCD     &1000  
    
    CACHE_LINE_NR_PER_WAY_PLACEMENT
cache_line_nr_per_way
    DCD     &400
    
;/****************************************************************************
; *     CP15 APIs
; ****************************************************************************/  
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_read_cache_type                                              */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function reads the cache type.                               */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      cache type                                                        */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;UINT32 cp15_read_cache_type(VOID) 
;{ 
    CP15_READ_CACHE_TYPE_PLACEMENT
    EXPORT cp15_read_cache_type
cp15_read_cache_type 
 
    MRC p15,0,r0,c0,c0,1 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_enable_icache                                                */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function enables I-Cache.                                    */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_enable_icache(VOID) 
;{ 
    CP15_ENABLE_ICACHE_PLACEMENT
    EXPORT cp15_enable_icache
cp15_enable_icache 
 
    MRC p15,0,r0,c1,c0,0 
    ORR r0,r0,#C1_IBIT 
    MCR p15,0,r0,c1,c0,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_disable_icache                                               */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function disables I-Cache.                                   */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_disable_icache(VOID) 
;{ 
    CP15_DISABLE_ICACHE_PLACEMENT
    EXPORT cp15_disable_icache
cp15_disable_icache 
 
    MRC p15,0,r0,c1,c0,0 
    BIC r0,r0,#C1_IBIT 
    MCR p15,0,r0,c1,c0,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_invalidate_icache                                            */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function invalidates I-Cache.                                */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_invalidate_icache(VOID) 
;{ 
    CP15_INVALIDATE_ICACHE_PLACEMENT
    EXPORT cp15_invalidate_icache
cp15_invalidate_icache 
 
    MOV r0,#0 
    MCR p15,0,r0,c7,c5,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_invalidate_icache_single                                     */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function invalidates I-Cache single entry via MVA.           */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      MVA                                                               */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      INTERNCODE                                                        */
;/**************************************************************************/  
;VOID cp15_invalidate_icache_single(UINT32 MVA) 
;{ 
    CP15_INVALIDATE_ICACHE_SINGLE_PLACEMENT
    EXPORT cp15_invalidate_icache_single
cp15_invalidate_icache_single 

;   /* quarantee 8-word alignment */
    MOV r0,r0,LSR #5 
    MOV r0,r0,LSL #5 
    MCR p15,0,r0,c7,c5,1 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_enable_dcache                                                */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function enables D-Cache.                                    */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_enable_dcache(VOID) 
;{ 
    CP15_ENABLE_DCACHE_PLACEMENT
    EXPORT cp15_enable_dcache
cp15_enable_dcache 
 
    MRC p15,0,r0,c1,c0,0 
    ORR r0,r0,#C1_CBIT 
    MCR p15,0,r0,c1,c0,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_disable_dcache                                               */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function disables D-Cache.                                   */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_disable_dcache(VOID) 
;{ 
    CP15_DISABLE_DCACHE_PLACEMENT
    EXPORT cp15_disable_dcache
cp15_disable_dcache 
 
    MRC p15,0,r0,c1,c0,0 
    BIC r0,r0,#C1_CBIT 
    MCR p15,0,r0,c1,c0,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_invalidate_dcache                                            */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function invalidates D-Cache.                                */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_invalidate_dcache(VOID) 
;{ 
    CP15_INVALIDATE_DCACHE_PLACEMENT
    EXPORT cp15_invalidate_dcache
cp15_invalidate_dcache 
 
    MOV r0,#0 
    MCR p15,0,r0,c7,c6,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_invalidate_dcache_single                                     */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function invalidates D-Cache single entry via MVA.           */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      MVA                                                               */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      INTERNCODE                                                        */
;/**************************************************************************/  
;VOID cp15_invalidate_dcache_single(UINT32 MVA) 
;{ 
    CP15_INVALIDATE_DCACHE_SINGLE_PLACEMENT
    EXPORT cp15_invalidate_dcache_single
cp15_invalidate_dcache_single 

;   /* quarantee 8-word alignment */
    MOV r0,r0,LSR #5 
    MOV r0,r0,LSL #5 
    MCR p15,0,r0,c7,c6,1 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;}

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_clean_dcache_single                                          */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function cleans D-Cache single entry via MVA.                */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      MVA                                                               */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_clean_dcache_single(UINT32 MVA) 
;{ 
    CP15_CLEAN_DCACHE_SINGLE_PLACEMENT
    EXPORT cp15_clean_dcache_single
cp15_clean_dcache_single 
 
;   /* quarantee 8-word alignment */
    MOV r0,r0,LSR #5 
    MOV r0,r0,LSL #5 
    MCR p15,0,r0,c7,c10,1 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;}

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_drain_write_buffer                                           */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function drains write buffer.                                */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_drain_write_buffer(VOID) 
;{ 
    CP15_DRAIN_WRITE_BUFFER_PLACEMENT
    EXPORT cp15_drain_write_buffer
cp15_drain_write_buffer 

    MOV r0,#0 
    MCR p15,0,r0,c7,c10,4
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_read_tcm_status                                              */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function reads the TCM status register.                      */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      TCM status register                                               */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;UINT32 cp15_read_tcm_status(VOID) 
;{ 
    CP15_READ_TCM_STATUS_PLACEMENT
    EXPORT cp15_read_tcm_status
cp15_read_tcm_status 
 
    MRC p15,0,r0,c0,c0,2 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_read_itcm_region                                             */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function reads the I-TCM region register.                    */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      I-TCM region register                                             */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;UINT32 cp15_read_itcm_region(VOID) 
;{ 
    CP15_READ_ITCM_REGION_PLACEMENT
    EXPORT cp15_read_itcm_region
cp15_read_itcm_region 
 
    MRC p15,0,r0,c9,c1,1 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_read_dtcm_region                                             */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function reads the D-TCM region register.                    */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      D-TCM region register                                             */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;UINT32 cp15_read_dtcm_region(VOID) 
;{ 
    CP15_READ_DTCM_REGION_PLACEMENT
    EXPORT cp15_read_dtcm_region
cp15_read_dtcm_region 
 
    MRC p15,0,r0,c9,c1,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_enable_itcm                                                  */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function enables I-TCM.                                      */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      Base addr of I-TCM                                                */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_enable_itcm(UINT32 addr) 
;{ 
    CP15_ENABLE_ITCM_PLACEMENT
    EXPORT cp15_enable_itcm
cp15_enable_itcm 
 
    MRC p15,0,r1,c9,c1,1 
    AND r1,r1,#TCM_BADDR_MASK
    ORR r0,r0,#C9_ENABLE_BIT 
    ORR r0,r0,r1 
    MCR p15,0,r0,c9,c1,1 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_enable_dtcm                                                  */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function enables D-TCM.                                      */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      base address of D-TCM                                             */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_enable_dtcm(UINT32 addr) 
;{ 
    CP15_ENABLE_DTCM_PLACEMENT
    EXPORT cp15_enable_dtcm
cp15_enable_dtcm 
 
    MRC p15,0,r1,c9,c1,0 
    AND r1,r1,#TCM_BADDR_MASK
    ORR r0,r0,#C9_ENABLE_BIT 
    ORR r0,r0,r1 
    MCR p15,0,r0,c9,c1,0 
 
    [ THUMB
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_write_tbbr                                                   */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function writes TBBR(Translation Table Base Register).       */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      TBBR to write                                                     */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_write_tbbr(UINT32 tbbr) 
;{ 
    CP15_WRITE_TBBR_PLACEMENT
    EXPORT cp15_write_tbbr
cp15_write_tbbr 
 
    MCR p15,0,r0,c2,c0,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_read_tbbr                                                    */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function read TBBR(Translation Table Base Register).         */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      TBBR                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;UINT32 cp15_read_tbbr(void) 
;{ 
    CP15_READ_TBBR_PLACEMENT
    EXPORT cp15_read_tbbr 
cp15_read_tbbr 
 
    MRC p15,0,r0,c2,c0,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_enable_mmu                                                   */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function enables MMU.                                        */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_enable_mmu(VOID) 
;{ 
    CP15_ENABLE_MMU_PLACEMENT
    EXPORT cp15_enable_mmu
cp15_enable_mmu 
 
    MOV r0,#0 
    MCR p15,0,r0,c8,c7,0    ; invalidate TLB 
    
    ; read cp15 control register into r3
    MRC p15, 0, r3, c1, c0, 0
    
    ; Enable MMU  
    ORR r3, r3, #C1_MBIT        ; Set MBIT
    MCR p15, 0, r3, c1, c0, 0   ; write back!
    NOP 
    NOP 
    NOP 
    NOP 
    NOP 
    NOP 
    NOP 
    NOP 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_disable_mmu                                                  */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function disables MMU.                                       */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_disable_mmu(VOID) 
;{ 
    CP15_DISABLE_MMU_PLACEMENT
    EXPORT cp15_disable_mmu
cp15_disable_mmu 
 
    MOV r0,#0 
    MCR p15,0,r0,c8,c7,0    ; invalidate TLB 
    
    ; read cp15 control register into r3
    MRC p15, 0, r3, c1, c0, 0
    
    ; Disable MMU
    BIC r3, r3, #C1_MBIT       ; clear MBit 
    MCR p15, 0, r3, c1, c0,0   ; write back
    NOP 
    NOP 
    NOP 
    NOP 
    NOP 
    NOP 
    NOP 
    NOP 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_read_domain_access                                           */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function reads domain access control register.               */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      domain access control register                                    */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;UINT32 cp15_read_domain_access(VOID) 
;{ 
    CP15_READ_DOMAIN_ACCESS_PLACEMENT
    EXPORT cp15_read_domain_access
cp15_read_domain_access 
 
    MRC p15,0,r0,c3,c0,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_write_domain_access                                          */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function writes domain access control register.              */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      domain    -    domain number to write                             */ 
;/*      access    -    access control to write                            */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_write_domain_access(UINT32 domain, UINT32 access) 
;{ 
    CP15_WRITE_DOMAIN_ACCESS_PLACEMENT
    EXPORT cp15_write_domain_access
cp15_write_domain_access 
 
    MOV r0,r0,LSL #1 
    MOV r1,r1,LSL r0 
    MRC p15,0,r2,c3,c0,0 
    MOV r3,#3 
    MOV r3,r3,LSL r0 
    BIC r2,r2,r3 
    ORR r2,r2,r1 
    MCR p15,0,r2,c3,c0,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_read_ifsr                                                    */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function reads IFSR(Instruction Fault Status Register).      */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      instruction fault status register                                 */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;UINT32 cp15_read_ifsr(VOID) 
;{ 
    CP15_READ_IFSR_PLACEMENT
    EXPORT cp15_read_ifsr
cp15_read_ifsr 
 
    MRC p15,0,r0,c5,c0,1 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_read_dfsr                                                    */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function reads DFSR(Data Fault Status Register).             */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      data fault status register                                        */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;UINT32 cp15_read_dfsr(VOID) 
;{ 
    CP15_READ_DFSR_PLACEMENT
    EXPORT cp15_read_dfsr
cp15_read_dfsr 
 
    MRC p15,0,r0,c5,c0,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_read_far                                                     */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function reads FAR(Fault Address Register).                  */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      fault address register                                            */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;UINT32 cp15_read_far(VOID) 
;{ 
    CP15_READ_FAR_PLACEMENT
    EXPORT cp15_read_far
cp15_read_far 
 
    MRC p15,0,r0,c6,c0,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_invalidate_tlb_single                                        */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function invalidates a sinel entry via MVA.                  */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      MVA                                                               */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      VOID                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;UINT32 cp15_invalidate_tlb_single(UINT32 MVA) 
;{ 
    CP15_INVALIDATE_TLB_SINGLE_PLACEMENT
    EXPORT cp15_invalidate_tlb_single
cp15_invalidate_tlb_single 
 
;   /* quarantee 1KB alignment */
    MOV r0,r0,LSR #10
    MOV r0,r0,LSL #10
    MCR p15,0,r0,c8,c7,1 

    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_invalidate_tlb                                               */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function invalidates TLB.                                    */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_invalidate_tlb(VOID) 
;{ 
    CP15_INVALIDATE_TLB_PLACEMENT
    EXPORT cp15_invalidate_tlb
cp15_invalidate_tlb
 
    MOV r0,#0
    MCR p15,0,r0,c8,c7,0

    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_enable_rom_protect                                           */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function enables ROM protection.                             */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_enable_rom_protect(VOID) 
;{ 
    CP15_ENABLE_ROM_PROTECT_PLACEMENT
    EXPORT cp15_enable_rom_protect
cp15_enable_rom_protect 
 
    MRC p15,0,r0,c1,c0,0 
    ORR r0,r0,#C1_RBIT 
    MCR p15,0,r0,c1,c0,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_disable_rom_protect                                          */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function disables ROM protection.                            */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_disable_rom_protect(VOID) 
;{ 
    CP15_DISABLE_ROM_PROTECT_PLACEMENT
    EXPORT cp15_disable_rom_protect
cp15_disable_rom_protect 
 
    MRC p15,0,r0,c1,c0,0 
    BIC r0,r0,#C1_RBIT 
    MCR p15,0,r0,c1,c0,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_enable_sys_protect                                           */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function enables system protection.                          */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_enable_sys_protect(VOID) 
;{ 
    CP15_ENABLE_SYS_PROTECT_PLACEMENT
    EXPORT cp15_enable_sys_protect
cp15_enable_sys_protect 
 
    MRC p15,0,r0,c1,c0,0 
    ORR r0,r0,#C1_SBIT 
    MCR p15,0,r0,c1,c0,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_disable_sys_protect                                          */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function disables system protection.                         */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_disable_sys_protect(VOID) 
;{ 
    CP15_DISABLE_SYS_PROTECT_PLACEMENT
    EXPORT cp15_disable_sys_protect
cp15_disable_sys_protect 
 
    MRC p15,0,r0,c1,c0,0 
    BIC r0,r0,#C1_SBIT 
    MCR p15,0,r0,c1,c0,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 
 
;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_enable_alignment_fault                                       */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function enables alignment fault.                            */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_enable_alignment_fault(VOID) 
;{ 
    CP15_ENABLE_ALIGNMENT_FAULT_PLACEMENT
    EXPORT cp15_enable_alignment_fault
cp15_enable_alignment_fault 
 
    MRC p15,0,r0,c1,c0,0 
    ORR r0,r0,#C1_ABIT 
    MCR p15,0,r0,c1,c0,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_disable_alignment_fault                                      */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function disables alignment fault.                           */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_disable_alignment_fault(VOID) 
;{ 
    CP15_DISABLE_ALIGNMENT_FAULT_PLACEMENT
    EXPORT cp15_disable_alignment_fault
cp15_disable_alignment_fault 
 
    MRC p15,0,r0,c1,c0,0 
    BIC r0,r0,#C1_ABIT 
    MCR p15,0,r0,c1,c0,0 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_enter_low_pwr_state                                          */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function configures ARM9 to enter low power state.           */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      INTSRAM_ROCODE                                                    */
;/**************************************************************************/  
;VOID cp15_enter_low_pwr_state(VOID) 
;{ 
    CP15_ENTER_LOW_PWR_STATE_PLACEMENT
    EXPORT cp15_enter_low_pwr_state
cp15_enter_low_pwr_state
 
    MCR p15,0,r0,c7,c0,4 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_invalidate_idcache_single                                    */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function invalidates ICache and DCache for the MVA           */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      MVA                                                               */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_invalidate_idcache_single(UINT32 MVA) 
;{ 
    CP15_INVALIDATE_IDCACHE_SINGLE_PLACEMENT
    EXPORT cp15_invalidate_idcache_single
cp15_invalidate_idcache_single
 
;   /* quarantee 8-word alignment */
    MOV r0,r0,LSR #5 
    MOV r0,r0,LSL #5 

;   /* invalidate ICache */
    MCR p15,0,r0,c7,c5,1 

;   /* invalidate DCache */
    MCR p15,0,r0,c7,c6,1 
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_invalidate_idcache_region                                    */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function invalidates ICache and DCache for the               */  
;/*      specified regions                                                 */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      addr        -   start address of the region                       */ 
;/*      nr_cache    -   number of cache entires                           */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_invalidate_idcache_region(UINT32 addr, UINT32 nr_cache) 
;{ 
    CP15_INVALIDATE_IDCACHE_REGION_PLACEMENT
    EXPORT cp15_invalidate_idcache_region
cp15_invalidate_idcache_region 

    CMP r1,#0
    BEQ invalidate_idcache_end

invalidate_idcache_begin
    MCR p15,0,r0,c7,c5,1 
    MCR p15,0,r0,c7,c6,1 
    ADD r0,r0,#32
    SUBS r1,r1,#1    
    BNE invalidate_idcache_begin

invalidate_idcache_end
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 


;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_invalidate_icache_region                                     */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function invalidates ICachefor the specified regions         */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      addr        -   start address of the region                       */ 
;/*      nr_cache    -   number of cache entires                           */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_invalidate_icache_region(UINT32 addr, UINT32 nr_cache) 
;{ 
    CP15_INVALIDATE_ICACHE_REGION_PLACEMENT
    EXPORT cp15_invalidate_icache_region
cp15_invalidate_icache_region

    CMP r1,#0
    BEQ invalidate_icache_end

invalidate_icache_begin
    MCR p15,0,r0,c7,c5,1 
    ADD r0,r0,#32
    SUBS r1,r1,#1    
    BNE invalidate_icache_begin

invalidate_icache_end
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 


;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_invalidate_dcache_region                                     */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function invalidates ICachefor the specified regions         */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      addr        -   start address of the region                       */ 
;/*      nr_cache    -   number of cache entires                           */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_invalidate_dcache_region(UINT32 addr, UINT32 nr_cache) 
;{ 
    CP15_INVALIDATE_DCACHE_REGION_PLACEMENT
    EXPORT cp15_invalidate_dcache_region
cp15_invalidate_dcache_region
    CMP r1,#0
    BEQ invalidate_dcache_end
    
    ; If region > cache size, do invalidate and clean all to improve responsiveness
    LDR r2,=cache_line_nr
    LDR r2,[r2]
    
    CMP r1,r2
    BGT cp15_clean_and_invalidate_all_dcache_by_setway

invalidate_dcache_begin
    MCR p15,0,r0,c7,c6,1 
    ADD r0,r0,#32
    SUBS r1,r1,#1
    BNE invalidate_dcache_begin

invalidate_dcache_end
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_clean_and_invalidate_dcache_by_setway                        */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function invalidate and clean dcache by set/way              */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      r0: set                                                           */ 
;/*      r1: way                                                           */
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
    CP15_CLEAN_AND_INVALIDATE_DCACHE_BY_SETWAY_PLACEMENT
    EXPORT cp15_clean_and_invalidate_dcache_by_setway
cp15_clean_and_invalidate_dcache_by_setway
    LSL r1,r1,#30
    LSL r0,r0,#5
    ORR r0,r0,r1
    MCR p15,0,r0,c7,c14,2 ; Clean/Invalidate set way
    MOV r0,#0
    MCR p15,0,r0,c7,c10,4 ; Drain write buffer
    
    BX lr

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_clean_all_dcache_by_setway                                   */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function clean entire D-Cache by Set/way                     */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_clean_all_dcache_by_setway(void) 
;{ 
    CP15_CLEAN_ALL_DCACHE_BY_SETWAY_PLACEMENT
    EXPORT cp15_clean_all_dcache_by_setway
cp15_clean_all_dcache_by_setway
    
    MOV r2,#0xC0000000     ; the way number

clean_all_dcache_init
    LDR r1,=cache_line_nr_per_way
    LDR r1,[r1]               ; total cache number in the way
    MOV r0,r2                 ; start address of the way
            
clean_all_dcache_begin
    MCR p15,0,r0,c7,c10,2
    ADD r0,r0,#32
    SUBS r1,r1,#1
    BNE clean_all_dcache_begin
    
    CMP r2,#0
    BEQ clean_all_dcache_end
    
    SUBS r2,r2,#0x40000000
    B clean_all_dcache_init

clean_all_dcache_end
    
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_clean_and_invalidate_all_dcache_by_setway                    */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function invalidate and clean all dcache by set/way          */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/**************************************************************************/  
    CP15_CLEAN_AND_INVALIDATE_ALL_DCACHE_BY_SETWAY_PLACEMENT
    EXPORT cp15_clean_and_invalidate_all_dcache_by_setway
cp15_clean_and_invalidate_all_dcache_by_setway
    MOV r2,#0xC0000000     ; the way number

clean_invalidate_all_dcache_init
    LDR r1,=cache_line_nr_per_way
    LDR r1,[r1]               ; total cache number in the way
    MOV r0,r2                 ; start address of the way
            
clean_invalidate_all_dcache_begin
    MCR p15,0,r0,c7,c14,2
    ADD r0,r0,#32
    SUBS r1,r1,#1
    BNE clean_invalidate_all_dcache_begin
    
    CMP r2,#0
    BEQ clean_invalidate_all_dcache_end
    
    SUBS r2,r2,#0x40000000
    B clean_invalidate_all_dcache_init

clean_invalidate_all_dcache_end
    
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_clean_dcache_region                                          */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function clean DCache for the specified regions              */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      addr        -   start address of the region                       */ 
;/*      nr_cache    -   number of cache entires                           */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_clean_dcache_region(UINT32 addr, UINT32 nr_cache) 
;{ 
    CP15_CLEAN_DCACHE_REGION_PLACEMENT
    EXPORT cp15_clean_dcache_region
cp15_clean_dcache_region
    CMP r1,#0
    BEQ clean_dcache_end
    
    ; If the target region > cache size, clean all DCache to improve the response time
    LDR r2,=cache_line_nr
    LDR r2,[r2]
    
    CMP r1,r2
    BGT cp15_clean_all_dcache_by_setway

clean_dcache_begin  
    MCR p15,0,r0,c7,c10,1 
    ADD r0,r0,#32
    SUBS r1,r1,#1
    BNE clean_dcache_begin

clean_dcache_end
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_clean_and_invalidate_dcache_region                           */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function clean and invalidates DCache for                    */
;/*      the specified regions                                             */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      addr        -   start address of the region                       */ 
;/*      nr_cache    -   number of cache entires                           */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
    CP15_CLEAN_AND_INVALIDATE_DCACHE_REGION_PLACEMENT
    EXPORT cp15_clean_and_invalidate_dcache_region
cp15_clean_and_invalidate_dcache_region

    CMP r1,#0
    BEQ clean_and_invalidate_dcache_end

    ; If region > cache size, do invalidate and clean all to improve responsiveness
    LDR r2,=cache_line_nr
    LDR r2,[r2]
    
    CMP r1,r2
    BGT cp15_clean_and_invalidate_all_dcache_by_setway

clean_and_invalidate_dcache_begin  
    MCR p15,0,r0,c7,c14,1 
    ADD r0,r0,#32
    SUBS r1,r1,#1
    BNE clean_and_invalidate_dcache_begin

clean_and_invalidate_dcache_end
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 


;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_lockdown_TLB_entry                                           */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function configures ARM9 to lock down TLB entry.             */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      MVA                                                               */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/
;/**************************************************************************
; * NOTE:
; *     The TLB lockdown sequence is written according to ARM document.
; *     There is one known-issue (limitation) for this sequence
; *     
; *     Current implementation cannot lockdown the TLB page which 
; *     contains THIS function. (Usually the page starts at 0x0)
; *     
; **************************************************************************/  
;VOID cp15_lockdown_TLB_entry(unsigned int addr) 
;{ 
    CP15_LOCKDOWN_TLB_ENTRY_PLACEMENT
    EXPORT cp15_lockdown_TLB_entry
cp15_lockdown_TLB_entry
    MCR p15, 0, r0, c8, c7, 1
    MRC p15, 0, r1, c10, c0, 0
    ORR r1, r1, #1
    MCR p15, 0, r1, c10, c0, 0
    LDR r0, [r0]
    MRC p15, 0, r1, c10, c0, 0
    BIC r1, r1, #1
    MCR p15, 0, r1, c10, c0, 0
 
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ]     
;} 


;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_is_icache_enabled                                            */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function returns whether ICache is enabled                   */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*      1: Enabled                                                        */ 
;/*  Other: Disabled                                                       */
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;BOOL cp15_is_icache_enabled(VOID) 
;{ 
    CP15_IS_ICACHE_ENABLED_PLACEMENT
    EXPORT cp15_is_icache_enabled
cp15_is_icache_enabled

    MRC      p15, 0, a4, c1, c0, 0
    ANDS     a1, a4, #ICACHE_ENABLE	
    MOVNE    a1, #1
   
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 


;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_is_dcache_enabled                                            */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function returns whether DCache is enabled                   */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*      1: Enabled                                                        */ 
;/*  Other: Disabled                                                       */
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;BOOL cp15_is_dcache_enabled(VOID) 
;{ 
    CP15_IS_DCACHE_ENABLED_PLACEMENT
    EXPORT cp15_is_dcache_enabled
cp15_is_dcache_enabled

    MRC     p15, 0, a4, c1, c0, 0
    ANDS     a1, a4, #DCACHE_ENABLE
    MOVNE    a1, #1
   
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 


;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_set_idcache_replacement_policy                               */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*       This function set the Cache replacement policy to                */  
;/*       round-robin or Random                                            */
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      0: Random                                                         */ 
;/*  Other: Round-robin                                                    */
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_set_idcache_replacement_policy(VOID) 
;{ 
    CP15_SET_IDCACHE_REPLACEMENT_PLACEMENT
    EXPORT cp15_set_idcache_replacement_policy
    EXPORT cp15_set_idcache_replacement
cp15_set_idcache_replacement
cp15_set_idcache_replacement_policy
    MCR     p15, 0, a4, c7, c5, 0            ; Invalidate I-Cache
   					    ; SHK: It is the command to flush the I-Cache, where c5 is only used to be explained
   					    ;	by the Co-processor to know what this instruction want to do.   
    MRC     p15, 0, a4, c1, c0, 0
 
    CMP     a1, #0			    ; SHK: If input is 0, set as Random policy.
    BICEQ   a4, a4, #RR_REPLACEMENT_ENABLE
    ORRNE   a4, a4, #RR_REPLACEMENT_ENABLE   ; SHK: Else, set as Round-robin policy.
    
    MCR     p15, 0, a4, c1, c0, 0
    
    NOP					    ; SHK: Ensure that all instructions are returned from I-Cache after enabling it.
    					    ; 	To prevent some instructions are pre-fetched in the pipeline.
    NOP
    NOP
    NOP
    NOP
    
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 


;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_clean_dcache                                                 */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function clean entire DCache                                 */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
;VOID cp15_clean_DCache(VOID) 
;{ 
    CP15_CLEAN_DCACHE_PLACEMENT
    EXPORT cp15_clean_dcache
cp15_clean_dcache
_tci_loop
    MRC     p15, 0, pc, c7, c14, 3 	; Test clean and invalidate D-Cache.
    BNE     _tci_loop
    
    MCR     p15, 0, a4, c7, c10, 4      ; Flush (drain) the write buffer
    
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_is_fpu_enabled                                               */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function checks whether ARM FPU is enabled                   */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      1: Enabled                                                        */ 
;/*      0: Disabled                                                       */
;/*                                                                        */
;/* AREA                                                                   */
;/*      C$$code                                                           */
;/**************************************************************************/  
; Query if FPU is enabled
; Return 1 if FPU is enabled, else return 0
; BOOL cp15_is_fpu_enabled(VOID)
; {
    CP15_IS_FPU_ENABLED_PLACEMENT
    EXPORT cp15_is_fpu_enabled
cp15_is_fpu_enabled
    MRC    p15,0,r0,c1,c0,2
    AND    r0,r0,#FPU_COPRO         ; Check CP11 on
    CMP    r0,#FPU_COPRO
    MOVEQ  r0,#1
    MOVNE  r0,#0
    [ THUMB
    BX lr
    |
    MOV pc,lr
    ]        
; }

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_lockdown_icache                                              */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function locks down I-CACHE.                                 */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*       L   -   L bit of C9                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      INTERNCODE                                                        */
;/**************************************************************************/  
;VOID cp15_lockdown_icache(UINT L)
;{ 
    CP15_LOCKDOWN_ICACHE_PLACEMENT
    EXPORT cp15_lockdown_icache
cp15_lockdown_icache
    MRC p15,0,r1,c9,c0,1
    MOV r0,r0,LSL #28
    MOV r0,r0,LSR #28
    MOV r1,r1,LSR #4
    MOV r1,r1,LSL #4
    ORR r1,r1,r0
    MCR p15,0,r1,c9,c0,1
   
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_lockdown_dcache                                              */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function locks down D-CACHE.                                 */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*       L   -   L bit of C9                                              */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/*                                                                        */
;/* AREA                                                                   */
;/*      INTERNCODE                                                        */
;/**************************************************************************/  
;VOID cp15_lockdown_dcache(UINT L)
;{ 
    CP15_LOCKDOWN_DCACHE_PLACEMENT
    EXPORT cp15_lockdown_dcache
cp15_lockdown_dcache
    MRC p15,0,r1,c9,c0,0
    MOV r0,r0,LSL #28
    MOV r0,r0,LSR #28
    MOV r1,r1,LSR #4
    MOV r1,r1,LSL #4
    ORR r1,r1,r0
    MCR p15,0,r1,c9,c0,0
   
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_prefetch_icache_line                                         */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function pre-fetches I-CACHE line.                           */  
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*       mva   -   address to pre-fetch                                   */ 
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */
;/*                                                                        */
;/* AREA                                                                   */
;/*      INTERNCODE                                                        */ 
;/**************************************************************************/  
;VOID cp15_prefetch_icache_line(UINT mva)
;{ 
    CP15_PREFETCH_ICACHE_LINE_PLACEMENT
    EXPORT cp15_prefetch_icache_line
cp15_prefetch_icache_line

    MCR p15, 0, r0, c7, c13, 1
   
    [ THUMB 
    BX lr 
    | 
    MOV pc,lr 
    ] 
;} 

;/**************************************************************************/  
;/*                                                                        */  
;/*  FUNCTION                                                              */  
;/*                                                                        */  
;/*      cp15_switch_vector                                                */  
;/*                                                                        */  
;/*  DESCRIPTION                                                           */  
;/*                                                                        */  
;/*      This function switch exception vector to high or low address      */
;/*                                                                        */  
;/* INPUTS                                                                 */ 
;/*                                                                        */ 
;/*      0: low vector (0x00000000)                                        */ 
;/*      1: high vector (0xFFFF0000)                                       */
;/*                                                                        */ 
;/* OUTPUTS                                                                */ 
;/*                                                                        */ 
;/*      None                                                              */ 
;/**************************************************************************/  
;VOID cp15_switch_vector(bool) 
;{ 
    CP15_SWITCH_VECTOR_PLACEMENT
    EXPORT cp15_switch_vector
cp15_switch_vector
    CMP r0,#0
    MRC p15,0,r0,c1,c0,0
    ORRNE r0,r0,#C1_VBIT_MASK
    BICEQ r0,r0,#C1_VBIT_MASK
    MCR p15,0,r0,c1,c0,0
    
    BX lr
;}

    END
    
