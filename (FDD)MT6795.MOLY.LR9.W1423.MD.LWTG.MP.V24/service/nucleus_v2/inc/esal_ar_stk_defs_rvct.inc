;***********************************************************************
;*
;*             Copyright 1993-2006 Mentor Graphics Corporation
;*                         All Rights Reserved.
;*
;* THIS WORK CONTAINS TRADE SECRET AND PROPRIETARY INFORMATION WHICH IS
;* THE PROPERTY OF MENTOR GRAPHICS CORPORATION OR ITS LICENSORS AND IS
;* SUBJECT TO LICENSE TERMS.
;*
;***********************************************************************

;***********************************************************************
;*
;*  FILE NAME
;*
;*      esal_ar_stk_defs.inc
;*
;*  COMPONENT
;*
;*      ESAL - Embedded Software Abstraction Layer
;*
;*  DESCRIPTION
;*
;*      This file contains the architecture specific definitions,
;*      constants, etc, related to stacks
;*
;*  DATA STRUCTURES
;*
;*      None
;*
;*  DEPENDENCIES
;*
;*      None
;*
;*============================================================================
;*             HISTORY
;* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
;*------------------------------------------------------------------------------
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
;*------------------------------------------------------------------------------
;* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
;*============================================================================
;***********************************************************************

; Define if floating point registers will be saved during context switches
; NOTE:  The C define must be changed in esal_ar_stk_defs.h to
;        match this define.
; NOTE:  This define will dictate what registers are contained
;        within solicited (TS) and unsolicited (AR) stack frames.


   

; Startup / initialization stack size in bytes

ESAL_AR_STK_STARTUP_STACK_SIZE  EQU          1024

    
    #if defined(ESAL_AR_STK_FPU_SUPPORT)
    
; Size, in bytes, of max architecture stack frames (with floating point)
; for VFPv2, we need 32+4 more register space, FPSCR, FPEXC, FPINST, FPINST2, 32 General FP Regs ( + 144bytes)
ESAL_AR_STK_MAX_FRAME_SIZE  EQU              212
; Size, in bytes, of min architecture stack frames
ESAL_AR_STK_MIN_FRAME_SIZE  EQU              176

; Offsets, in bytes, of registers in minimum stack frame    
    #if defined(ARMV6_INST_ENABLE)
ESAL_AR_STK_MIN_LR_OFFSET  EQU               164
ESAL_AR_STK_MIN_PC_OFFSET  EQU               168
ESAL_AR_STK_MIN_SPSR_OFFSET  EQU             172
    #else
ESAL_AR_STK_MIN_PC_OFFSET  EQU               172
ESAL_AR_STK_MIN_LR_OFFSET  EQU               168
ESAL_AR_STK_MIN_SPSR_OFFSET  EQU             164
    #endif // ARMV6_INST_ENABLE
    
    #else

; Size, in bytes, of max architecture stack frames (without floating point)
ESAL_AR_STK_MAX_FRAME_SIZE  EQU              68
; Size, in bytes, of min architecture stack frames
ESAL_AR_STK_MIN_FRAME_SIZE  EQU              32

; Offsets, in bytes, of registers in minimum stack frame
    #if defined(ARMV6_INST_ENABLE)
ESAL_AR_STK_MIN_LR_OFFSET  EQU               20
ESAL_AR_STK_MIN_PC_OFFSET  EQU               24
ESAL_AR_STK_MIN_SPSR_OFFSET  EQU             28
    #else // ARMV6_INST_ENABLE
ESAL_AR_STK_MIN_PC_OFFSET  EQU               28
ESAL_AR_STK_MIN_LR_OFFSET  EQU               24
ESAL_AR_STK_MIN_SPSR_OFFSET  EQU             20
    #endif // ARMV6_INST_ENABLE
    #endif // ESAL_AR_STK_FPU_SUPPORT

; Offset, in bytes, of LR in full stack frame

    #if defined(ARMV6_INST_ENABLE)
ESAL_AR_STK_LR_OFFSET  EQU                   (ESAL_AR_STK_MAX_FRAME_SIZE-12)
    #else // ARMV6_INST_ENABLE
ESAL_AR_STK_LR_OFFSET  EQU                   (ESAL_AR_STK_MAX_FRAME_SIZE-8)
    #endif // ARMV6_INST_ENABLE

; Based on ESAL_TS_REQ_STK_ALIGNMENT in esal_ts_cfg.h
 
ESAL_AR_STK_ALIGNMENT_MASK  EQU              0x00000007

; Offsets, in bytes, of registers on temp stack

ESAL_AR_STK_TMP_R0_OFFSET  EQU               0
ESAL_AR_STK_TMP_SPSR_OFFSET  EQU             4
ESAL_AR_STK_TMP_LR_OFFSET  EQU               8

; VFP enable value

ESAL_AR_STK_VFP_ENABLE  EQU                  0x40000000


    MACRO
    ESAL_AR_STK_FPU_SAVE 
#if defined(ESAL_AR_STK_FPU_SUPPORT)
    
    ; Save required floating point registers on the current stack.
    ; We need to save FPEXC first, and clear VFP exception state
    ; So that we can safely read/store other VFP registers
    MRS     r3,FPEXC                  ; Store FPEXC first
    STMDB   sp!,{r3}
    BIC     r3,#(1<<31)               
    MSR     FPEXC,r3                  ; Clear EX bit
    MRS     r3,FPINST
    STMDB   sp!,{r3}         
    MRS     r3,FPINST2
    STMDB   sp!,{r3}                      
    MRS     r3,FPSCR
    STMDB   sp!,{r3}
    VSTMDB  sp!,{s0-s31}

#endif // ESAL_AR_STK_FPU_SUPPORT
    MEND

    MACRO
    ESAL_AR_STK_FPU_RESTORE 
#if defined(ESAL_AR_STK_FPU_SUPPORT)
    
    ; Restore required floating point registers from the current stack.

    VLDMIA  sp!,{s0-s31}
    LDMIA   sp!,{r3}
    MSR     FPSCR,r3
    LDMIA   sp!,{r3}
    MSR     FPINST2,r3
    LDMIA   sp!,{r3}
    MSR     FPINST,r3
    LDMIA   sp!,{r3}
    MSR     FPEXC,r3

#endif // ESAL_AR_STK_FPU_SUPPORT

    MEND

;***********************************************************************
;* ESAL_AR_STK_MIN_INT_SAVE
;*
;* Save minimal amount of registers required for handling interrupts.
;* ESAL_AR_STK_Unsolicited_Switch() will save the rest.
;***********************************************************************

    MACRO
    ESAL_AR_STK_MIN_INT_SAVE 
#if defined(ARMV6_INST_ENABLE)
    CPSID   aif, #ESAL_AR_ISR_CPSR_SYS_MODE
    STMDB   sp!,{r0-r3, r12, r14}
#else  // else of ARMV6_INST_ENABLE
    
    ; Save lr on temporary stack
    
    STR     lr, [sp,#ESAL_AR_STK_TMP_LR_OFFSET]
    
    ; Get SPSR and save on temporary stack
    
    MRS     r14, SPSR
    STR     r14, [sp,#ESAL_AR_STK_TMP_SPSR_OFFSET]

    ; Save r0 on temporary stack
    
    STR     r0, [sp,#ESAL_AR_STK_TMP_R0_OFFSET]
    
    ; Save address of temporary stack into r0
    
    MOV     r0, sp
    
    ; Switch to system mode and keep all interrupts disabled
    
    MSR     CPSR_c,#(ESAL_AR_ISR_CPSR_SYS_MODE | ESAL_AR_ISR_CPSR_IRQ_BIT | ESAL_AR_ISR_CPSR_FIQ_BIT)
    
    ; Now in system mode, save the system mode lr
    ; on the current stack and save room for return pc
    
    STR     lr, [sp,#-8]!
    
    ; Get lr from temporary stack and save on
    ; system mode stack (in space provided by operation above)
    
    LDR     r14, [r0,#ESAL_AR_STK_TMP_LR_OFFSET]
    STR     r14, [sp,#4]
    
    ; Get SPSR and R0 from temporary stack
    
    LDR     r14, [r0,#ESAL_AR_STK_TMP_SPSR_OFFSET]
    LDR     r0, [r0,#ESAL_AR_STK_TMP_R0_OFFSET]

    ; Now save minimal context required to enter C (save only
    ; toolset scratch registers and necessary registers for
    ; interrupt nesting)
    
    STMDB   sp!,{r0-r3, r12, r14}
#endif // ARMV6_INST_ENABLE 
    ESAL_AR_STK_FPU_SAVE
    
    MEND


;***********************************************************************
;* ESAL_AR_STK_MIN_INT_RESTORE
;* 
;* Restore minimal amount of registers required for handling interrupts.
;***********************************************************************

    MACRO
    ESAL_AR_STK_MIN_INT_RESTORE 
#if defined(ARMV6_INST_ENABLE)
    MOV      sp,r0
    ESAL_AR_STK_FPU_RESTORE
    ; Restore minimal registers
    LDMIA   sp!,{r0-r3, r12, r14}
    RFEIA sp!
#else // else of ARMV6_INST_ENABLE

    ; Update system stack pointer to end-state
    
    ADD     sp,r0,#ESAL_AR_STK_MIN_FRAME_SIZE

    ; Update system link register to end-state
    
    LDR     lr,[r0,#ESAL_AR_STK_MIN_LR_OFFSET]

    ; Switch to supervisor mode - keep all interrupts disabled
    ; Use supervisor mode since we have to install VFP support code in UND mode
    MSR     CPSR_c,#(ESAL_AR_ISR_CPSR_SUP_MODE | ESAL_AR_ISR_CPSR_IRQ_BIT | ESAL_AR_ISR_CPSR_FIQ_BIT)

    ; Set supervisor mode stack pointer
    
    MOV     sp,r0

    ESAL_AR_STK_FPU_RESTORE

    ; Restore minimal registers
    
    LDMIA   sp!,{r0-r3, r12, r14}
    
    ; Update SPSR
    
    MSR     SPSR_cxsf, r14

    ; Skip lr on stack (already updated in system mode)
    
    ADD     sp,sp,#4
    
    ; Return to point of interrupt
    ; NOTE: {pc}^ also restores the CPSR from the SPSR
    
    LDMIA   sp,{pc}^
    
#endif // ARMV6_INST_ENABLE
    MEND


;***********************************************************************
;* ESAL_AR_STK_MIN_EXCEPT_SAVE
;* 
;* Save minimal amount of registers required for handling exceptions.
;***********************************************************************

    MACRO
    ESAL_AR_STK_MIN_EXCEPT_SAVE 

    ; Save exception return address on stack

    STR     lr,[sp,#-4]!

    ; No lr to save, so skip it on stack

    SUB     sp,sp,#4

    ; Put spsr in r14 and save remaining 
    ; minimal context on stack

    MRS     r14,spsr
    STMDB   sp!,{r0-r3, r12, r14}

    MEND


;***********************************************************************
;* ESAL_AR_STK_MIN_EXCEPT_RESTORE
;* 
;* Restore minimal amount of registers required for handling exceptions.
;***********************************************************************

    MACRO
    ESAL_AR_STK_MIN_EXCEPT_RESTORE 

    ; Restore min stack registers

    LDMIA   sp!,{r0-r3, r12, r14}

    ; Restore SPSR

    MSR     SPSR_cxsf,r14

    ; Skip lr on stack

    ADD     sp,sp,#4

    ; Return to point of interrupt
    ; NOTE: {pc}^ also restores the CPSR from the SPSR
    
    LDMIA   sp!,{pc}^

    MEND
    
;    END
