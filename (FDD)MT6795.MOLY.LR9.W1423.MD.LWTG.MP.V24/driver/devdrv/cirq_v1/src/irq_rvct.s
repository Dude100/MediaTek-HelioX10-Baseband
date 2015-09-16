;
;/*************************************************************************/
;/*                                                                       */
;/* FILE NAME                                            VERSION          */
;/*                                                                       */
;/*      irq.s                                        ARM 7/9/11/CR4      */
;/*                                                                       */
;/* COMPONENT                                                             */
;/*                                                                       */
;/*      Interrupt Control                                                */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*                                                                       */
;/*      This file contains the irq functions                             */
;/*                                                                       */
;/*                                                                       */
;/* DATA STRUCTURES                                                       */
;/*                                                                       */
;/*                                                                       */
;/* FUNCTIONS                                                             */
;/*                                                                       */
;/*      INT_FIQ_Parse                                                    */
;/*      INT_IRQ_Parse                                                    */
;/*      DisableIRQ                                                       */
;/*      ReEnableIRQ                                                      */
;/*      LockIRQ                                                          */
;/*      RestoreIRQ                                                       */
;/*      CheckIRQLock                                                     */
;/*                                                                       */
;/*                                                                       */
;/*************************************************************************/


; If assembled with TASM the variable {CONFIG} will be set to 16
; If assembled with ARMASM the variable {CONFIG} will be set to 32
; Set the variable THUMB to TRUE or false depending on whether the
; file is being assembled with TASM or ARMASM.

        GBLL    THUMB
        GBLL    ARM
    [ {CONFIG} = 16
THUMB   SETL    {TRUE}
ARM     SETL    {FALSE}

; If assembling with TASM go into 32 bit mode as the Armulator will
; start up the program in ARM state.

        CODE32
    |
THUMB   SETL    {FALSE}
ARM     SETL    {TRUE}
    ]


; /*----------------------------*/
; /*  Definitions               */
; /*----------------------------*/

   IF  (:LNOT: :DEF: SINGLE_BANK_SUPPORT)
      GBLL         SINGLE_BANK_SUPPORT
SINGLE_BANK_SUPPORT   SETL    {FALSE}
   ENDIF
   
   IF  (:LNOT: :DEF: KAL_ON_NUCLEUS)
      GBLL         KAL_ON_NUCLEUS
KAL_ON_NUCLEUS   SETL    {FALSE}
   ENDIF

   IF  (:LNOT: :DEF: __NUCLEUS_VERSION_2__)
      GBLL         __NUCLEUS_VERSION_2__
__NUCLEUS_VERSION_2__   SETL    {FALSE}
   ENDIF

   IF  (:LNOT: :DEF: __TP_SUPPORT_TIMING_CHECK__)
      GBLL   	   __TP_SUPPORT_TIMING_CHECK__
__TP_SUPPORT_TIMING_CHECK__ SETL    {FALSE}
   ENDIF

   IF  (:LNOT: :DEF: DCM_ENABLE)
      GBLL         DCM_ENABLE
DCM_ENABLE   SETL    {FALSE}
   ENDIF

I_BIT                   EQU      &80         ; Interrupt bit of CPSR and SPSR
F_BIT                   EQU      &40         ; Interrupt bit of CPSR and SPSR
INT_BIT                 EQU      &C0         ; Interrupt bits



; /*----------------------------*/
; /*  Import functions          */
; /*----------------------------*/

   IMPORT  __rt_memcpy
   IMPORT   INT_FIQ_Lisr
   IMPORT   processing_irqlr
   IMPORT   processing_fiqlr
   IMPORT   isrC_Main

   IF DCM_ENABLE
   IMPORT  DCM_Recovery
   ENDIF

   IF KAL_ON_NUCLEUS

   #if defined(__NUCLEUS_VERSION_2__)
   #include "esal_ar_isr_defs_rvct.inc"
   #include "esal_ar_stk_defs_rvct.inc"
   #endif

   IF :DEF: __DEMAND_PAGING_PERFORMANCE_PROFILING__
   IMPORT demp_preempt_time_end
   DEMP_PREEMPT_TIME_END
    DCD demp_preempt_time_end
   ENDIF
   
   IF __NUCLEUS_VERSION_2__
   IMPORT   ESAL_AR_STK_Unsolicited_Switch
   IMPORT   ESAL_GE_ISR_OS_Entry
   IMPORT   ESAL_GE_ISR_OS_Nested_Entry
   IMPORT   ESAL_GE_ISR_Executing
   IMPORT   ESAL_GE_STK_System_SP
   IMPORT   ESAL_GE_STK_Unsol_Switch_Req
   IMPORT   No_Context_Switch
   IF __TP_SUPPORT_TIMING_CHECK__
   IMPORT   TP_Update_Preempted_Time
   ENDIF

   ELSE
   IMPORT   TCT_Interrupt_Context_Save
   IMPORT   TCT_Interrupt_Context_Restore
   ENDIF

   ELSE

   ;Import function for OS: ThreadX
   IMPORT   _tx_thread_system_stack_ptr
   IMPORT   _tx_thread_context_save
   IMPORT   _tx_thread_irq_nesting_start
   IMPORT   _tx_thread_irq_nesting_end
   IMPORT   _tx_thread_context_restore
   IMPORT   _tx_initialize_kernel_enter

   ENDIF

   
   IF :DEF: ESAL_AR_STK_FPU_SUPPORT  
   IMPORT   set_fpu_runfastmode
   ENDIF
   
   
; /*----------------------------*/
; /*  Export functions          */
; /*----------------------------*/

   EXPORT  INT_FIQ_Parse
   EXPORT  INT_IRQ_Parse

   EXPORT  DisableIRQ
   EXPORT  ReEnableIRQ
   EXPORT  LockIRQ
   EXPORT  RestoreIRQ
   EXPORT  CheckIRQLock
   
   EXPORT  INT_BIT
   
   PRESERVE8
   AREA |C$$code|, CODE, READONLY
|x$codeseg|

   IF SINGLE_BANK_SUPPORT
   CODE32

   AREA |SNORCODE|, CODE, READONLY
   IMPORT Flash_ReturnReady
   ENDIF

FIQ_RETURN_PTR
   DCD     processing_fiqlr

;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*                                                                       */
;/*      INT_FIQ_Parse                                                    */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*                                                                       */
;/*      This routine is the board-specific section for                   */
;/*      fast interrupt handling                                          */
;/*                                                                       */
;/*************************************************************************/
   IF __NUCLEUS_VERSION_2__

INT_FIQ_Parse

    ; Adjust lr to interrupt address
    
    SUB     lr,lr,#4

    ; Save minimum architecture registers to stack for interrupt
    
    ESAL_AR_STK_MIN_INT_SAVE

    ; stack pointer in r1 (2nd parameter)
    
    MOV     r1,sp
    
    BL      INT_FIQ_Lisr
    
    ; Never Come here
FIQ_LOOP_FOREVER
    B       FIQ_LOOP_FOREVER

ESAL_AR_ISR_Nested_FIQ_Restore

    ; Put the stack pointer in r0
    
    MOV     r0,sp

    ; Restore minimum registers from stack and return from interrupt
    
    ESAL_AR_STK_MIN_INT_RESTORE
    
    ELSE
INT_FIQ_Parse

    IF KAL_ON_NUCLEUS

    STMDB   sp!, {a2}
    MRS     a2, SPSR
    TST     a2, #F_BIT
    LDMIA   sp!, {a2}
    SUBNES  PC,lr,#4

    STMDB   sp!,{a1-a4}                     ; Save a1-a4 on temporary FIQ stack
    SUB     a4,lr,#4                        ; Save IRQ's lr (return address)
    
    LDR     a1, FIQ_RETURN_PTR
    STR     a4, [a1]                        ; Save IRQ's return address to global variable.    

   IF SINGLE_BANK_SUPPORT
    STMDB   sp!,{a1-a4,r12,r14}
    BL      Flash_ReturnReady               ; make flash enter ready state
    LDMIA   sp!,{a1-a4,r12,r14}             ; r12 is for veneer use
   ENDIF

    BL      TCT_Interrupt_Context_Save      ; Call context save routine
    BL      INT_FIQ_Lisr
    B       TCT_Interrupt_Context_Restore

    ELSE

    STMDB   sp!, {a2}
    MRS     a2, SPSR
    TST     a2, #F_BIT
    LDMIA   sp!, {a2}
    SUBNES  PC,lr,#4

    STMDB   sp!,{a1,a4}                     ; Save a1 and a4 on temporary FIQ stack

    SUB     a4,lr,#4                        ; Save IRQ's lr (return address)
    LDR     a1, FIQ_RETURN_PTR
    STR     a4, [a1]                        ; Save IRQ's return address to global variable.    

   IF SINGLE_BANK_SUPPORT
    STMDB   sp!,{a1-a4,r12,r14}
    BL      Flash_ReturnReady               ; make flash enter ready state
    LDMIA   sp!,{a1-a4,r12,r14}             ; r12 is for veneer use
   ENDIF

    LDMIA   sp!,{a1,a4}                     ; Restore a1 and a4

    BL      INT_FIQ_Lisr

int_fiq_busy_loop

    B       int_fiq_busy_loop

    ENDIF

    ENDIF


   PRESERVE8
   CODE32
   AREA |INTSRAM_ROCODE|, CODE, READONLY
;
;}   
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*                                                                       */
;/*      INT_IRQ_Parse                                                    */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*                                                                       */
;/*      This routine is the board-specific section for                   */
;/*      interrupt handling                                               */
;/*                                                                       */
;/*************************************************************************/
   IF __NUCLEUS_VERSION_2__

ESAL_AR_ISR_Executing
    DCD ESAL_GE_ISR_Executing
ESAL_AR_ISR_System_SP
    DCD ESAL_GE_STK_System_SP
ESAL_AR_ISR_OS_Entry
    DCD ESAL_GE_ISR_OS_Entry
ESAL_AR_ISR_OS_Nested_Entry
    DCD ESAL_GE_ISR_OS_Nested_Entry
ESAL_AR_ISR_Unsol_Switch_Req
    DCD ESAL_GE_STK_Unsol_Switch_Req
NO_CONTEXT_SWITCH_LOGGING
    DCD No_Context_Switch

    IF __TP_SUPPORT_TIMING_CHECK__
UPDATE_PREEMPTED_TIME
    DCD TP_Update_Preempted_Time
    ENDIF

INT_IRQ_Parse


    STMIA   sp!, {r1}
    MRS     r1, SPSR
    TST     r1, #ESAL_AR_ISR_CPSR_IRQ_BIT
    LDMDB   sp!, {r1}
    SUBNES  pc,lr,#4
   
    ; Adjust lr to interrupt address

    SUB     lr,lr,#4

    ; Save minimum architecture registers to stack for interrupt

    ESAL_AR_STK_MIN_INT_SAVE

    IF :DEF: ESAL_AR_STK_FPU_SUPPORT
    ; set VFP to runfast for entire IRQ processing
    BL   set_fpu_runfastmode
    ENDIF ;IF ESAL_AR_STK_FPU_SUPPORT
    LDR     a1,=processing_irqlr
    LDR     a2, [sp,#ESAL_AR_STK_MIN_PC_OFFSET]
    STR     a2, [a1]                        ; Save IRQ's return address to global variable.

  IF DCM_ENABLE
    BL   DCM_Recovery 
  ENDIF
    
   IF SINGLE_BANK_SUPPORT
    BL      Flash_ReturnReady               ; make flash enter ready state
   ENDIF

    ; Put ESAL interrupt ID in r0 (1st parameter)

;    MOV     r0,#ESAL_AR_IRQ_INT_VECTOR_ID

    ; stack pointer in r1 (2nd parameter)

    MOV     r1,sp

    ; Check if this interrupt occurred during execution of
    ; another interrupt (nested)

    LDR     r2,ESAL_AR_ISR_Executing
    LDR     r2,[r2]
    CMP     r2,#0

    ; Switch stack if first interrupt (not nested)

    LDREQ   sp,ESAL_AR_ISR_System_SP
    LDREQ   sp,[sp]

    ; Get address of OS entry for correct interrupt handler
    ; (nested or non-nested)

    LDREQ   r2,ESAL_AR_ISR_OS_Entry
    LDRNE   r2,ESAL_AR_ISR_OS_Nested_Entry
    LDR     r2,[r2]

    ; Get return address and transfer
    ; control to OS entry for interrupt handling

    ADRNE   lr,ESAL_AR_ISR_Nested_IRQ_Restore
    MOVEQ   lr,pc    
    BX      r2

    ; Check if context switch is required as a result of 
    ; the interrupt service routine

    LDR     r2,ESAL_AR_ISR_Unsol_Switch_Req
    LDR     r2,[r2]
    CMP     r2,#0

    ; Perform context switch if required

    BNE     ESAL_AR_STK_Unsolicited_Switch

    ; No context switch required, restore minimal context and
    ; return to point of interrupt

    ; Get system stack pointer in r0

    LDR     r0,[r0]

    ; Save the r0 to the stack
    STMDB   sp!, {r0}
    LDR     r0,NO_CONTEXT_SWITCH_LOGGING
    BLX     r0
    
    IF __TP_SUPPORT_TIMING_CHECK__
    LDR     r0,UPDATE_PREEMPTED_TIME
    BLX     r0
    ENDIF
    IF :DEF: __DEMAND_PAGING_PERFORMANCE_PROFILING__
    LDR     r0,DEMP_PREEMPT_TIME_END
    BLX     r0
    ENDIF
    ; Restore r0 from the stack
    LDMIA   sp!, {r0}

    ; Restore minimum registers from stack and return from interrupt

    ESAL_AR_STK_MIN_INT_RESTORE

ESAL_AR_ISR_Nested_IRQ_Restore

    ; Put the stack pointer in r0
   
    MOV     r0,sp

    ; Restore minimum registers from stack and return from interrupt

    ESAL_AR_STK_MIN_INT_RESTORE

    ELSE
INT_IRQ_Parse

    IF KAL_ON_NUCLEUS

;   /* 
;    * NoteXXX: SW workaround for ARM7 family common bug 
;    *          An interrupt may trigger when an MSR is executed to set I-bit.
;    */
    STMDB   sp!, {a2}
    MRS     a2, SPSR
    TST     a2, #I_BIT
    LDMIA   sp!, {a2}
    SUBNES  pc,lr,#4

    STMDB   sp!,{a1-a4}                     ; Save a1-a4 on temporary IRQ stack
    SUB     a4,lr,#4                        ; Save IRQ's lr (return address)

    LDR     a1,=processing_irqlr
    STR     a4, [a1]                        ; Save IRQ's return address to global variable.

  IF DCM_ENABLE
    STMDB   sp!,{a1-a4}
    STMDB   sp!,{r12}
    STMDB   sp!,{r14}
    BL   DCM_Recovery 
    LDMIA   sp!,{r14}
    LDMIA   sp!,{r12}
    LDMIA   sp!,{a1-a4}  
  ENDIF

  IF SINGLE_BANK_SUPPORT
    STMDB   sp!,{a1-a4,r12,r14}
    BL      Flash_ReturnReady               ; make flash enter ready state
    LDMIA   sp!,{a1-a4,r12,r14}             ; r12 is for veneer use
  ENDIF

    BL      TCT_Interrupt_Context_Save      ; Call context save routine
    BL      isrC_Main
    B       TCT_Interrupt_Context_Restore

    ELSE

    STMDB   sp!, {a2}
    MRS     a2, SPSR
    TST     a2, #I_BIT
    LDMIA   sp!, {a2}
    SUBNES  pc,lr,#4

    STMDB   sp!,{a1,a4}                     ; Save a1 and a4 on temporary IRQ stack

    SUB     a4,lr,#4                        ; Save IRQ's lr (return address)
    LDR     a1,=processing_irqlr
    STR     a4, [a1]                        ; Save IRQ's return address to global variable.

    LDMIA   sp!,{a1,a4}                     ; Restore a1 and a4

  IF DCM_ENABLE
    STMDB   sp!,{a1-a4}
    STMDB   sp!,{r12}
    STMDB   sp!,{r14}
    BL   DCM_Recovery 
    LDMIA   sp!,{r14}
    LDMIA   sp!,{r12}
    LDMIA   sp!,{a1-a4}  
  ENDIF

    B       _tx_thread_context_save
__tx_irq_processing_return
    BL      _tx_thread_irq_nesting_start
    BL      isrC_Main
    BL      _tx_thread_irq_nesting_end
    B       _tx_thread_context_restore
 
    ENDIF

    ENDIF
;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*      DisableIRQ                                                       */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*      Set I-bit and return the original values.                        */
;/*      NoteXXX: for system internal use only                            */
;/*                                                                       */
;/* CALLS                                                                 */
;/*                                                                       */
;/* INPUTS                                                                */
;/*      None                                                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*      original values of I-bit and F-bit                               */
;/*************************************************************************/
; INT DisableIRQ(VOID)
; {
DisableIRQ
   STMDB    SP!,{R1}
   MRS      R0,CPSR
   MOV      R1,R0

   ORR      R0,R0,#I_BIT   
   MSR      CPSR_c, R0
   MOV      R0,R1
   LDMIA    SP!,{R1}
   [ THUMB
    BX      lr                              ; Return to caller
   |
   MOV      pc,lr                           ; Return to caller
   ]
;}


;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*      ReEnableIRQ                                                      */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*      Enable IRQ by clearing I bit.                                    */
;/*      NoteXXX: for system internal use only                            */
;/*                                                                       */
;/* CALLS                                                                 */
;/*                                                                       */
;/* INPUTS                                                                */
;/*      None                                                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*      None                                                             */
;/*************************************************************************/
; VOID ReEnableIRQ( VOID)
; {
ReEnableIRQ
   STMDB    SP!, {R0}
   MRS      R0, CPSR
   BIC      R0, R0, #I_BIT
   MSR      CPSR_c, R0
   LDMIA    SP!, {R0}
   [ THUMB
    BX      lr                              ; Return to caller
   |
   MOV      pc,lr                           ; Return to caller
   ]
;}


;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*      LockIRQ                                                          */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*      Set I-bit, F-bit and return their original values.               */
;/*      NoteXXX: for system internal use only                            */
;/*                                                                       */
;/* CALLS                                                                 */
;/*                                                                       */
;/* INPUTS                                                                */
;/*      None                                                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*      original values of I-bit and F-bit                               */
;/*************************************************************************/
; INT LockIRQ(VOID)
; {
LockIRQ
   STMDB    SP!,{R1}
   MRS      R0,CPSR
   MOV      R1,R0

   ORR      R0,R0,#INT_BIT   
   MSR      CPSR_c, R0
   MOV      R0,R1
   LDMIA    SP!,{R1}
   [ THUMB
    BX      lr                              ; Return to caller
   |
   MOV      pc,lr                           ; Return to caller
   ]
;}


;
;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*      RestoreIRQ                                                       */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*      Restore I-bit and F-bit setting                                  */
;/*      NoteXXX: for system internal use only                            */
;/*                                                                       */
;/* CALLS                                                                 */
;/*                                                                       */
;/* INPUTS                                                                */
;/*      None                                                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*      None                                                             */
;/*************************************************************************/
; VOID RestoreIRQ(INT)
; {
RestoreIRQ
   STMDB    SP!,{R1,R2}
   MRS      R1,CPSR
   AND      R2,R0,#INT_BIT
   BIC      R1,R1,#INT_BIT
   ORR      R0,R1,R2
   MSR      CPSR_c,R0
   LDMIA    SP!,{R1,R2}
    [ THUMB
   BX       lr                              ; Return to caller
   |
   MOV      pc,lr                           ; Return to caller
    ]
    
;}
;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*      CheckIRQLock                                                     */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*      Check if the IRQ is locked                                       */
;/*                                                                       */
;/* INPUTS                                                                */
;/*      None                                                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*      0 if IRQ is not locked; non-zero if IRQ is locked                */
;/*************************************************************************/
; UINT CheckIRQLock(VOID)
; {
CheckIRQLock
   MRS      R0,CPSR
   AND      R0,R0,#INT_BIT   
   [ THUMB
   BX       lr                              ; Return to caller
   |
   MOV      pc,lr                           ; Return to caller
   ]
;}

   END