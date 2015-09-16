@***********************************************************************
@*
@*             Copyright 1993-2006 Mentor Graphics Corporation
@*                         All Rights Reserved.
@*
@* THIS WORK CONTAINS TRADE SECRET AND PROPRIETARY INFORMATION WHICH IS
@* THE PROPERTY OF MENTOR GRAPHICS CORPORATION OR ITS LICENSORS AND IS
@* SUBJECT TO LICENSE TERMS.
@*
@***********************************************************************

@***********************************************************************
@*
@*  FILE NAME
@*
@*      esal_ar_isr_defs.inc
@*
@*  COMPONENT
@*
@*      ESAL - Embedded Software Abstraction Layer
@*
@*  DESCRIPTION
@*
@*      This file contains the architecture specific definitions,
@*      constants, etc, related to interrupt servicing
@*
@*  DATA STRUCTURES
@*
@*      None
@*
@*  DEPENDENCIES
@*
@*      None
@*
@*============================================================================
@*             HISTORY
@* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
@*------------------------------------------------------------------------------
@* $Revision$
@* $Modtime$
@* $Log$
@*
@* 03 19 2014 hc.yang
@* [MOLY00059827] [System Service][MOLY Kernel Internal Request]Add MTK header to each Nucleus Plus file for check-in history
@* .
@*
@*------------------------------------------------------------------------------
@* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
@*============================================================================
@***********************************************************************

@ Define to allow conditional assembling of lowlevel ISR hook.
@ Setting this to TRUE will allow a low-level hook to be executed in the
@ interrupt handlers

@    GBLL ESAL_AR_ISR_HOOK_ENABLED 
@ESAL_AR_ISR_HOOK_ENABLED SETL             {FALSE}
.equ ESAL_AR_ISR_HOOK_ENABLED, 0

@ Define to allow conditional assembling of reset vector type (branch versus load).
@ Setting this to TRUE will force the reset vector to utilize a branch instruction.
@ This is necessary for certain processors that re-map memory and require a PC
@ relative jump to the entry point versus a full 32-bit address (before remapping memory).

@    GBLL ESAL_AR_ISR_RESET_BRANCH 
@ESAL_AR_ISR_RESET_BRANCH SETL             {FALSE}
.equ ESAL_AR_ISR_RESET_BRANCH, 0

@ Define to allow conditional compilation for ARM7TDMI processor. Setting this
@ to TRUE will include necessary low-level interrupt handling code specific to
@ the ARM7TDMI and its pipeline architecture.

@    GBLL ESAL_AR_ISR_CPU7TDMI
@ESAL_AR_ISR_CPU7TDMI SETL                 {CPU} = "ARM7TDMI"

@ Define architecture interrupt handling constants,
@ register addresses, initialization values, structures, etc.

@ Define constants for CPSR interrupt / mode bits



.equ ESAL_AR_ISR_CPSR_MODE_MASK, 0x0000001F
.equ ESAL_AR_ISR_CPSR_SYS_MODE , 0x0000001F
.equ ESAL_AR_ISR_CPSR_SUP_MODE , 0x00000013
.equ ESAL_AR_ISR_CPSR_IRQ_MODE , 0x00000012
.equ ESAL_AR_ISR_CPSR_FIQ_MODE , 0x00000011
.equ ESAL_AR_ISR_CPSR_UND_MODE , 0x0000001B
.equ ESAL_AR_ISR_CPSR_ABT_MODE , 0x00000017
.equ ESAL_AR_ISR_CPSR_IRQ_BIT  , 0x00000080
.equ ESAL_AR_ISR_CPSR_FIQ_BIT  , 0x00000040

@ Define architecture ESAL interrupt vector IDs
@ These IDs match up with architecture interrupts.
@ Values correspond to the index of entries in ESAL_GE_ISR_Interrupt_Handler[].
@ Names are of the form ESAL_AR_<Name>_INT_VECTOR_ID, where <Name> comes
@ directly from the hardware documentation.

@ESAL_AR_IRQ_INT_VECTOR_ID  EQU              0
@ESAL_AR_FIQ_INT_VECTOR_ID  EQU              1

.equ ESAL_AR_IRQ_INT_VECTOR_ID, 0
.equ ESAL_AR_FIQ_INT_VECTOR_ID, 1


@ Define architecture ESAL exception vector IDs
@ These IDs match up with architecture exceptions.
@ Values correspond to the index of entries in ESAL_GE_ISR_Exception_Handler[].
@ Names are of the form ESAL_AR_<Name>_EXCEPT_VECTOR_ID, where <Name> comes
@ directly from the hardware documentation.

@ESAL_AR_UNDEF_EXCEPT_VECTOR_ID  EQU         0
@ESAL_AR_SWI_EXCEPT_VECTOR_ID  EQU           1
@ESAL_AR_PREFETCH_EXCEPT_VECTOR_ID  EQU      2
@ESAL_AR_DATA_EXCEPT_VECTOR_ID  EQU          3

.equ ESAL_AR_UNDEF_EXCEPT_VECTOR_ID,0
.equ ESAL_AR_SWI_EXCEPT_VECTOR_ID,1
.equ ESAL_AR_PREFETCH_EXCEPT_VECTOR_ID,2
.equ ESAL_AR_DATA_EXCEPT_VECTOR_ID,3

@    END
