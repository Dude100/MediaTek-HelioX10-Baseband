@
@/*************************************************************************/
@/*                                                                       */
@/* FILE NAME                                            VERSION          */
@/*                                                                       */
@/*      irq.s                                        ARM 7/9/11/CR4      */
@/*                                                                       */
@/* COMPONENT                                                             */
@/*                                                                       */
@/*      Interrupt Control                                                */
@/*                                                                       */
@/* DESCRIPTION                                                           */
@/*                                                                       */
@/*      This file contains the irq functions                             */
@/*                                                                       */
@/*                                                                       */
@/* DATA STRUCTURES                                                       */
@/*                                                                       */
@/*                                                                       */
@/* FUNCTIONS                                                             */
@/*                                                                       */
@/*      INT_FIQ_Parse                                                    */
@/*      INT_IRQ_Parse                                                    */
@/*      DisableIRQ                                                       */
@/*      ReEnableIRQ                                                      */
@/*      LockIRQ                                                          */
@/*      RestoreIRQ                                                       */
@/*      CheckIRQLock                                                     */
@/*                                                                       */
@/*                                                                       */
@/*************************************************************************/


@ If assembled with TASM the variable {CONFIG} will be set to 16
@ If assembled with ARMASM the variable {CONFIG} will be set to 32
@ Set the variable THUMB to TRUE or false depending on whether the
@ file is being assembled with TASM or ARMASM.

@        GBLL    THUMB
@        GBLL    ARM
@    [ {CONFIG} = 16
.set     THUMB,   0
.set     ARM,     1

@ If assembling with TASM go into 32 bit mode as the Armulator will
@ start up the program in ARM state.

        .code 32
@    |
@THUMB   SETL    {FALSE}
@ARM     SETL    {TRUE}
@    ]


.equ  I_BIT, 0x80
.equ  F_BIT, 0x40
.equ  INT_BIT, 0xC0


@ /*----------------------------*/
@ /*  Import functions          */
@ /*----------------------------*/

   .extern  __rt_memcpy
   .extern   INT_FIQ_Lisr
   .extern   processing_irqlr
   .extern   processing_fiqlr
   .extern   isrC_Main

   #if defined(DCM_ENABLE)
   .extern  DCM_Recovery
   #endif

   #if defined(KAL_ON_NUCLEUS)

   #if defined(__NUCLEUS_VERSION_2__)
   @#include "nucleus_v2/inc/esal_ar_isr_defs_gcc.inc"
   #include "esal_ar_isr_defs_gcc.inc"
   @#include "nucleus_v2/inc/esal_ar_stk_defs_gcc.inc"
   #include "esal_ar_stk_defs_gcc.inc"
   #endif

   #ifdef __DEMAND_PAGING_PERFORMANCE_PROFILING__
   @.extern demp_preempt_time_end
   DEMP_PREEMPT_TIME_END:
    .word demp_preempt_time_end
   #endif
   
   #if defined(__NUCLEUS_VERSION_2__)
   .extern   ESAL_AR_STK_Unsolicited_Switch
   .extern   ESAL_GE_ISR_OS_Entry
   .extern   ESAL_GE_ISR_OS_Nested_Entry
   .extern   ESAL_GE_ISR_Executing
   .extern   ESAL_GE_STK_System_SP
   .extern   ESAL_GE_STK_Unsol_Switch_Req
   .extern   ESAL_GE_STK_System_SP
   .extern   No_Context_Switch
   
   #if defined(__TP_SUPPORT_TIMING_CHECK__)
   .extern   TP_Update_Preempted_Time
   #endif
   
   #else
   .extern   TCD_System_Stack
   .extern   TCT_System_Limit
   .extern   TCT_Interrupt_Context_Save
   .extern   TCT_Interrupt_Context_Restore
   #endif

   #else    /* defined(KAL_ON_NUCLEUS) */

   @.extern function for OS: ThreadX
   .extern   _tx_thread_system_stack_ptr
   .extern   _tx_thread_context_save
   .extern   _tx_thread_irq_nesting_start
   .extern   _tx_thread_irq_nesting_end
   .extern   _tx_thread_context_restore
   .extern   _tx_initialize_kernel_enter

   #endif    /* defined(KAL_ON_NUCLEUS) */

   
   #if defined(ESAL_AR_STK_FPU_SUPPORT)
   .extern   set_fpu_runfastmode
   #endif
   
   
@ /*----------------------------*/
@ /*  Export functions          */
@ /*----------------------------*/

   .global  INT_FIQ_Parse
   .global  INT_IRQ_Parse

   .global  DisableIRQ
   .global  ReEnableIRQ
   .global  LockIRQ
   .global  RestoreIRQ
   .global  CheckIRQLock

#if defined(__SSDVT_TEST__)
   .global  DisableFIQ
   .global  EnableFIQ
#endif
   
   #if defined(SINGLE_BANK_SUPPORT)
   .code 32
   
   .section "SNORCODE", "ax"

   .extern Flash_ReturnReady
   #endif

FIQ_RETURN_PTR:
   .word     processing_fiqlr

;
@}
/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      INT_FIQ_Parse                                                    */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This routine is the board-specific section for                   */
/*      fast interrupt handling                                          */
/*                                                                       */
/*************************************************************************/

   #if defined(__SSDVT_TEST__)
.equ   MODE_MASK               ,      0x1f         @ Processor Mode Mask

   #if defined(__NUCLEUS_VERSION_2__)
.equ   UNDEF_MODE               ,      0x1B         @ Kernel Running Mode
   #else                   
.equ   SYSTEM_MODE               ,      0x1F         @ Kernel Running Mode
   #endif

INT_FIQ_Parse:
   STMDB   sp!, {a2}
   MRS     a2, SPSR
   TST     a2, #F_BIT
   LDMIA   sp!, {a2}
   SUBNES  pc,lr,#4

   STMDB   sp!,{a1-a4}                      @ Save a1-a4 on temporary IRQ stack
   SUB     a4,lr,#4                         @ Save IRQ's lr (return address)


   
   STMDB   sp!, {v1-v3}                     @ Save more registers on current
                                            @ stack
   MRS     v1, SPSR                         @ Pickup and save current spSR
   MOV     v2, lr                           @ Save current lr
   MOV     v3, sp                           @ Save current sp
   ADD     sp, sp, #28                      @ Adjust sp for future interrupts
   MRS     a1, CPSR                         @ Pickup current CPSR
   BIC     a1, a1, #MODE_MASK               @ Clear the mode bits
   #if defined(__NUCLEUS_VERSION_2__)
   ORR     a1, a1, #UNDEF_MODE               @ Prepare to switch to supervisor
   #else
   ORR     a1, a1, #SYSTEM_MODE               @ Prepare to switch to supervisor   
   #endif
                                            @ mode (SVC)
   MSR     CPSR_cxsf, a1                    @ Switch to SVC mode
   MOV     a2, sp                           @ Use a non sp register
   NOP                                      @
   STR     a4, [a2, #-4]!                   @ Save interrupted pc on sys stack
   MOV     a4, v6                           @ Save sb in a4

   @ [MODIFY]   RVCT compiler warns this usage since this inst using SP is deprecated in ARMv7 architecture.
   STMDB   a2!, {v4-lr}                     @ Save v4-lr on the system stack
   
   MOV     sp, a2                           @ Setup sp again
   LDMIA   v3!, {v4-v6}                     @ Recover v1-v3 from int stack
   STMDB   sp!, {v4-v6}                     @ Save v1-v3 on the system stack
   MOV     v6, a4                           @ Recover sb
   LDMIA   v3, {a1-a4}                      @ Recover a1-a4
   STMDB   sp!, {a1-a4}                     @ Save a1-a4 on the system stack
   STR     v1, [sp, #-4]!                   @ Save CPSR on the stack


  
   BL      FIQ_C_ISR
   
   MRS     a2, CPSR                         @ Mask out I/F bit for critical section
   MOV     a1, a2                           @ We need critical section for below Interrupt return routine
   ORR     a2, a2, #I_BIT
   ORR     a2, a2, #F_BIT
   MSR     CPSR_cxsf, a2
    
   LDR     a1, [sp], #4                     @ Pickup the saved CPSR

   MSR     SPSR_cxsf, a1                    @ Place into saved spSR
   LDMIA   sp, {a1-pc}^                     @ Return to the point of interrupt
.size INT_FIQ_Parse, .-INT_FIQ_Parse  

   #else    /* #if defined(__SSDVT_TEST__) */

   #if defined(__NUCLEUS_VERSION_2__)

_INT_FIQ_Lisr:
   .word   INT_FIQ_Lisr
INT_FIQ_Parse:

    @ Adjust lr to interrupt address
    
    SUB     lr,lr,#4

    @ Save minimum architecture registers to stack for interrupt
    
    ESAL_AR_STK_MIN_INT_SAVE

    @ stack pointer in r1 (2nd parameter)
    
    MOV     r1,sp
    
    BL      _INT_FIQ_Lisr
    
    @ Never Come here
FIQ_LOOP_FOREVER:
    B       FIQ_LOOP_FOREVER

ESAL_AR_ISR_Nested_FIQ_Restore:

    @ Put the stack pointer in r0
    
    MOV     r0,sp

    @ Restore minimum registers from stack and return from interrupt
    
    ESAL_AR_STK_MIN_INT_RESTORE
.size INT_FIQ_Parse, .-INT_FIQ_Parse
    
    #else    /* defined(__NUCLEUS_VERSION_2__) */
_INT_FIQ_Lisr:
   .word   INT_FIQ_Lisr    
INT_FIQ_Parse:

    #if defined(KAL_ON_NUCLEUS)

    STMDB   sp!, {a2}
    MRS     a2, SPSR
    TST     a2, #F_BIT
    LDMIA   sp!, {a2}
    SUBNES  PC,lr,#4

    STMDB   sp!,{a1-a4}                     @ Save a1-a4 on temporary FIQ stack
    SUB     a4,lr,#4                        @ Save IRQ's lr (return address)
    
    LDR     a1, FIQ_RETURN_PTR
    STR     a4, [a1]                        @ Save IRQ's return address to global variable.    

   #if defined(SINGLE_BANK_SUPPORT)
    STMDB   sp!,{a1-a4,r12,r14}
    BL      Flash_ReturnReady               @ make flash enter ready state
    LDMIA   sp!,{a1-a4,r12,r14}             @ r12 is for veneer use
   #endif

    BL      TCT_Interrupt_Context_Save      @ Call context save routine
    BL      _INT_FIQ_Lisr
    B       TCT_Interrupt_Context_Restore

    #else    /* defined(KAL_ON_NULCEUS) */

    STMDB   sp!, {a2}
    MRS     a2, SPSR
    TST     a2, #F_BIT
    LDMIA   sp!, {a2}
    SUBNES  PC,lr,#4

    STMDB   sp!,{a1,a4}                     @ Save a1 and a4 on temporary FIQ stack

    SUB     a4,lr,#4                        @ Save IRQ's lr (return address)
    LDR     a1, FIQ_RETURN_PTR
    STR     a4, [a1]                        @ Save IRQ's return address to global variable.    

   #if defined(SINGLE_BANK_SUPPORT)
    STMDB   sp!,{a1-a4,r12,r14}
    BL      Flash_ReturnReady               @ make flash enter ready state
    LDMIA   sp!,{a1-a4,r12,r14}             @ r12 is for veneer use
   #endif

    LDMIA   sp!,{a1,a4}                     @ Restore a1 and a4

    BL      _INT_FIQ_Lisr

int_fiq_busy_loop:

    B       int_fiq_busy_loop

    #endif    /* defined(KAL_ON_NULCEUS) */
.size INT_FIQ_Parse, .-INT_FIQ_Parse
    #endif    /* defined(__NUCLEUS_VERSION_2__) */

    #endif    /* defined(__SSDVT_TEST__) */

   .code 32
   .section "INTSRAM_ROCODE", "ax"

@
@}
/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      INT_IRQ_Parse                                                    */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This routine is the board-specific section for                   */
/*      interrupt handling                                               */
/*                                                                       */
/*************************************************************************/
   #if defined(__NUCLEUS_VERSION_2__)

ESAL_AR_ISR_Executing:
    .word ESAL_GE_ISR_Executing
ESAL_AR_ISR_System_SP:
    .word ESAL_GE_STK_System_SP
ESAL_AR_ISR_OS_Entry:
    .word ESAL_GE_ISR_OS_Entry
ESAL_AR_ISR_OS_Nested_Entry:
    .word ESAL_GE_ISR_OS_Nested_Entry
ESAL_AR_ISR_Unsol_Switch_Req:
    .word ESAL_GE_STK_Unsol_Switch_Req
NO_CONTEXT_SWITCH_LOGGING:
    .word No_Context_Switch

   #if defined(__TP_SUPPORT_TIMING_CHECK__)   
UPDATE_PREEMPTED_TIME:
    .word TP_Update_Preempted_Time
   #endif
   
INT_IRQ_Parse:


    STMIA   sp!, {r1}
    MRS     r1, SPSR
    TST     r1, #ESAL_AR_ISR_CPSR_IRQ_BIT
    LDMDB   sp!, {r1}
    SUBNES  pc,lr,#4
   
    @ Adjust lr to interrupt address

    SUB     lr,lr,#4

    @ Save minimum architecture registers to stack for interrupt

    ESAL_AR_STK_MIN_INT_SAVE

    #if defined(ESAL_AR_STK_FPU_SUPPORT)
    @ set VFP to runfast for entire IRQ processing
    BL   set_fpu_runfastmode
    #endif    /* defined(ESAL_AR_STK_FPU_SUPPORT) */
    LDR     a1,=processing_irqlr
    LDR     a2, [sp,#ESAL_AR_STK_MIN_PC_OFFSET]
    STR     a2, [a1]                        @ Save IRQ's return address to global variable.

  #if defined(DCM_ENABLE)
    BL   DCM_Recovery 
  #endif
    
   #if defined(SINGLE_BANK_SUPPORT)
    BL      Flash_ReturnReady               @ make flash enter ready state
   #endif

    @ Put ESAL interrupt ID in r0 (1st parameter)

@    MOV     r0,#ESAL_AR_IRQ_INT_VECTOR_ID

    @ stack pointer in r1 (2nd parameter)

    MOV     r1,sp

    @ Check if this interrupt occurred during execution of
    @ another interrupt (nested)

    LDR     r2,ESAL_AR_ISR_Executing
    LDR     r2,[r2]
    CMP     r2,#0

    @ Switch stack if first interrupt (not nested)

    LDREQ   sp,ESAL_AR_ISR_System_SP
    LDREQ   sp,[sp]

    @ Get address of OS entry for correct interrupt handler
    @ (nested or non-nested)

    LDREQ   r2,ESAL_AR_ISR_OS_Entry
    LDRNE   r2,ESAL_AR_ISR_OS_Nested_Entry
    LDR     r2,[r2]

    @ Get return address and transfer
    @ control to OS entry for interrupt handling

    ADRNE   lr,ESAL_AR_ISR_Nested_IRQ_Restore
    MOVEQ   lr,pc    
    BX      r2

    @ Check if context switch is required as a result of 
    @ the interrupt service routine

    LDR     r2,ESAL_AR_ISR_Unsol_Switch_Req
    LDR     r2,[r2]
    CMP     r2,#0

    @ Perform context switch if required

    BNE     ESAL_AR_STK_Unsolicited_Switch

    @ No context switch required, restore minimal context and
    @ return to point of interrupt

    @ Get system stack pointer in r0

    LDR     r0,[r0]

    @ Save the r0 to the stack
    STMDB   sp!, {r0}
    LDR     r0,NO_CONTEXT_SWITCH_LOGGING
    BLX     r0

    #if defined(__TP_SUPPORT_TIMING_CHECK__)
    LDR     r0,UPDATE_PREEMPTED_TIME
    BLX     r0
    #endif
    
    #ifdef __DEMAND_PAGING_PERFORMANCE_PROFILING__
    LDR     r0,DEMP_PREEMPT_TIME_END
    BLX     r0
    #endif
    @ Restore r0 from the stack
    LDMIA   sp!, {r0}

    @ Restore minimum registers from stack and return from interrupt

    ESAL_AR_STK_MIN_INT_RESTORE

ESAL_AR_ISR_Nested_IRQ_Restore:

    @ Put the stack pointer in r0
   
    MOV     r0,sp

    @ Restore minimum registers from stack and return from interrupt

    ESAL_AR_STK_MIN_INT_RESTORE
.size INT_IRQ_Parse, .-INT_IRQ_Parse
    #else    /* defined(__NUCLEUS_VERSION_2__) */
    
INT_IRQ_Parse:

    #if defined(KAL_ON_NUCLEUS)

   /* 
    * NoteXXX: SW workaround for ARM7 family common bug 
    *          An interrupt may trigger when an MSR is executed to set I-bit.
    */
    STMDB   sp!, {a2}
    MRS     a2, SPSR
    TST     a2, #I_BIT
    LDMIA   sp!, {a2}
    SUBNES  pc,lr,#4

    STMDB   sp!,{a1-a4}                     @ Save a1-a4 on temporary IRQ stack
    SUB     a4,lr,#4                        @ Save IRQ's lr (return address)

    LDR     a1,=processing_irqlr
    STR     a4, [a1]                        @ Save IRQ's return address to global variable.

  #if defined(DCM_ENABLE)
    STMDB   sp!,{a1-a4}
    STMDB   sp!,{r12}
    STMDB   sp!,{r14}
    BL   DCM_Recovery 
    LDMIA   sp!,{r14}
    LDMIA   sp!,{r12}
    LDMIA   sp!,{a1-a4}  
  #endif

  #if defined(SINGLE_BANK_SUPPORT)
    STMDB   sp!,{a1-a4,r12,r14}
    BL      Flash_ReturnReady               @ make flash enter ready state
    LDMIA   sp!,{a1-a4,r12,r14}             @ r12 is for veneer use
  #endif

    BL      TCT_Interrupt_Context_Save      @ Call context save routine
    BL      isrC_Main
    B       TCT_Interrupt_Context_Restore

    #else    /* defined(KAL_ON_NUCLEUS) */

    STMDB   sp!, {a2}
    MRS     a2, SPSR
    TST     a2, #I_BIT
    LDMIA   sp!, {a2}
    SUBNES  pc,lr,#4

    STMDB   sp!,{a1,a4}                     @ Save a1 and a4 on temporary IRQ stack

    SUB     a4,lr,#4                        @ Save IRQ's lr (return address)
    LDR     a1,=processing_irqlr
    STR     a4, [a1]                        @ Save IRQ's return address to global variable.

    LDMIA   sp!,{a1,a4}                     @ Restore a1 and a4

  #if defined(DCM_ENABLE)
    STMDB   sp!,{a1-a4}
    STMDB   sp!,{r12}
    STMDB   sp!,{r14}
    BL   DCM_Recovery 
    LDMIA   sp!,{r14}
    LDMIA   sp!,{r12}
    LDMIA   sp!,{a1-a4}  
  #endif

    B       _tx_thread_context_save
__tx_irq_processing_return:
    BL      _tx_thread_irq_nesting_start
    BL      isrC_Main
    BL      _tx_thread_irq_nesting_end
    B       _tx_thread_context_restore
 
    #endif    /* defined(KAL_ON_NUCLEUS) */
.size INT_IRQ_Parse, .-INT_IRQ_Parse
    #endif    /* defined(__NUCLEUS_VERSION_2__) */

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*      DisableIRQ                                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*      Set I-bit and return the original values.                        */
/*      NoteXXX: for system internal use only                            */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/* INPUTS                                                                */
/*      None                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*      original values of I-bit and F-bit                               */
/*************************************************************************/
@ INT DisableIRQ(VOID)
@ {
DisableIRQ:
   STMDB    SP!,{R1}
   MRS      R0,CPSR
   MOV      R1,R0

   ORR      R0,R0,#I_BIT   
   MSR      CPSR_c, R0
   MOV      R0,R1
   LDMIA    SP!,{R1}
   
    BX      lr                              @ Return to caller
.size DisableIRQ, .-DisableIRQ
@}   



/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*      ReEnableIRQ                                                      */
/*                                                                       */
/* DESCRIPTION                                                           */
/*      Enable IRQ by clearing I bit.                                    */
/*      NoteXXX: for system internal use only                            */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/* INPUTS                                                                */
/*      None                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*      None                                                             */
/*************************************************************************/
@ VOID ReEnableIRQ( VOID)
@ {
ReEnableIRQ:
   STMDB    SP!, {R0}
   MRS      R0, CPSR
   BIC      R0, R0, #I_BIT
   MSR      CPSR_c, R0
   LDMIA    SP!, {R0}

   BX      lr                              @ Return to caller
.size ReEnableIRQ, .-ReEnableIRQ
@}



/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*      LockIRQ                                                          */
/*                                                                       */
/* DESCRIPTION                                                           */
/*      Set I-bit, F-bit and return their original values.               */
/*      NoteXXX: for system internal use only                            */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/* INPUTS                                                                */
/*      None                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*      original values of I-bit and F-bit                               */
/*************************************************************************/
@ INT LockIRQ(VOID)
@ {
LockIRQ:
   STMDB    SP!,{R1}
   MRS      R0,CPSR
   MOV      R1,R0

   ORR      R0,R0,#INT_BIT   
   MSR      CPSR_c, R0
   MOV      R0,R1
   LDMIA    SP!,{R1}

   BX      lr                              @ Return to caller
.size LockIRQ, .-LockIRQ
@}




/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*      RestoreIRQ                                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*      Restore I-bit and F-bit setting                                  */
/*      NoteXXX: for system internal use only                            */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/* INPUTS                                                                */
/*      None                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*      None                                                             */
/*************************************************************************/
@ VOID RestoreIRQ(INT)
@ {
RestoreIRQ:
   STMDB    SP!,{R1,R2}
   MRS      R1,CPSR
   AND      R2,R0,#INT_BIT
   BIC      R1,R1,#INT_BIT
   ORR      R0,R1,R2
   MSR      CPSR_c,R0
   LDMIA    SP!,{R1,R2}

   BX       lr                              @ Return to caller
.size RestoreIRQ, .-RestoreIRQ
@}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*      CheckIRQLock                                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*      Check if the IRQ is locked                                       */
/*                                                                       */
/* INPUTS                                                                */
/*      None                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*      0 if IRQ is not locked; non-zero if IRQ is locked                */
/*************************************************************************/
@ UINT CheckIRQLock(VOID)
@ {
CheckIRQLock:
   MRS      R0,CPSR
   AND      R0,R0,#INT_BIT   

   BX       lr                              @ Return to caller
.size CheckIRQLock, .-CheckIRQLock
@}

#if defined(__SSDVT_TEST__)
DisableFIQ:
   STMDB    SP!,{R1}
   MRS      R0,CPSR
   MOV      R1,R0

   ORR      R0,R0,#F_BIT   
   MSR      CPSR_c, R0
   MOV      R0,R1
   LDMIA    SP!,{R1}
   
    BX      lr                              @ Return to caller
.size DisableFIQ, .-DisableFIQ

EnableFIQ:
   STMDB    SP!, {R0}
   MRS      R0, CPSR
   BIC      R0, R0, #F_BIT
   MSR      CPSR_c, R0
   LDMIA    SP!, {R0}

   BX      lr                              @ Return to caller
.size EnableFIQ, .-EnableFIQ

#endif

   .end