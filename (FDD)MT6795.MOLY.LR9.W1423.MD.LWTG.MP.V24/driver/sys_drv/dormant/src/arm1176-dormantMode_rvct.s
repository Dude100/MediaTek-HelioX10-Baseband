;*******************************************************************************
;*
;* The confidential and proprietary information contained in this file may
;* only be used by a person authorised under and to the extent permitted
;* by a subsisting licensing agreement from ARM Limited.
;*
;*              (C) COPYRIGHT 2004 ARM Limited.
;*                      ALL RIGHTS RESERVED
;*
;* This entire notice must be reproduced on all copies of this file
;* and copies of this file may only be made by a person if such person is
;* permitted to do so under the terms of a subsisting license agreement
;* from ARM Limited.
;*
;*              Config to simulate the dormant mode
;*              ===================================
;*
;*      Origin: CPU Validation
;*   $Revision: 1.8 $
;*      $Date: Wed Oct 31 17:46:55 2007 $
;*
;*******************************************************************************

                AREA    |RO-CODE|, CODE, READONLY
                ARM

;*******************************************************************************
;*      Configuration and constants
;*******************************************************************************

  IMPORT dormant_dummy_wb_variable
  IMPORT dormant_tcm_storage
  IMPORT dormant_mode_storage
  IMPORT dormant_restore_begin
  IMPORT dormant_tcm_restore_begin
  IMPORT dormant_dma0_status
  IMPORT dormant_dma1_status
  IMPORT dormant_ctrl_backup
  IMPORT dormant_coproc_acc_ctrl

  IMPORT dormant_status_reg
  IMPORT dormant_power_ack_mask

  IMPORT dormant_mode_abort_entry
  IMPORT dormant_mode_abort_reset

  EXPORT arm_dormant_reset_handler
  EXPORT enter_dormant_mode
  EXPORT leave_dormant_mode

   IF  (:LNOT: :DEF: __NUCLEUS_VERSION_2__)
      GBLL         __NUCLEUS_VERSION_2__
__NUCLEUS_VERSION_2__   SETL    {FALSE}
   ENDIF

;                 GBLL    ARM_SECURE_MODE
;ARM_SECURE_MODE  SETL    {TRUE}

;                GBLL    ARM_COPROC_P14
;ARM_COPROC_P14  SETL    {TRUE}
                 GBLL    ARM_WFI_IN_ENTRY
ARM_WFI_IN_ENTRY SETL    {TRUE}

; Aliases for mode encodings - do not change
MODE_USR        EQU     0x10
MODE_FIQ        EQU     0x11
MODE_IRQ        EQU     0x12
MODE_SVC        EQU     0x13
MODE_ABT        EQU     0x17
MODE_UND        EQU     0x1B
MODE_MON        EQU     0x16
MODE_SYS        EQU     0x1F

MODE_MASK       EQU     0x1F

;*******************************************************************************
;*      Dormant mode reset handler
;*******************************************************************************
;void arm_dormant_reset_handler(void) 
arm_dormant_reset_handler
; infinite loop for debug
;   B   arm_dormant_reset_handler
; check whether dormant mode is triggered
   LDR r0,dormant_hw_status
   LDR r1,dormant_hw_ack
   LDR r0,[r0]
   LDR r1,[r1]
   AND r0,r0,r1
   BEQ arm_halt_loop
   BL  leave_dormant_mode

; unexpected reset
arm_halt_loop
   B arm_halt_loop

dormant_hw_status      
                    DCD     dormant_status_reg
dormant_hw_ack      
                    DCD     dormant_power_ack_mask
;*******************************************************************************
;*      Enter dormant mode
;*******************************************************************************

;void enter_dormant_mode(void) 

                EXPORT  enter_dormant_mode

enter_dormant_mode
                ; we are in Secure Monitor mode if secure mode support is enabled.
                ; And in sys/svc mode if secure mode is disabled.
                ; Save general purpose registers, current mode registers and SPSR

                PUSH    {r1}
                LDR     r1,dormant_backup
                STR     r0,[r1],#4                      ; save r0
                POP     {r0}
                STR     r0,[r1],#4                      ; save r1
                STMIA   r1!,{r2-r14}                    ; Save r2-r14 (gen/Mon)


                PUSH    {r1}
                ; Save TCM registers
                ; This code checks how many I and D TCMs are present by reading
                ; the TCM Status Register, and only saves registers for TCMs that
                ; exist.  (Saving registers for non-existent TCMs does no harm as
                ; the writes to restore the values are ignored by the processor,
                ; but it takes longer.)  If you know the number of TCMs in your
                ; system is constant, you can simplify or remove this code.
                LDR     r1,dormant_tcm_backup           ; get TCM setting back up buffer
                MOV     r0,#0
                MRC     p15,0,r0,c0,c0,2                ; Read TCM Status
                MOV     r10,r0,LSR #16                  ; Get # D TCMs (0-2)
                AND     r11,r0,#3                       ; Get # I TCMs (0-2)
                ADDS    r0,r10,r11                      ; 0 TCMs in total?
                BEQ     end_TCM                         ; Skip TCM register save

                MOV     r0,#0
                MCR     p15,0,r0,c9,c2,0                ; Select TCM bank 0
                CMP     r10,#0                          ; >0 D TCMs?
                MRCNE   p15,0,r2,c9,c1,0                ; D TCM 0 Region
                MRCNE   p15,0,r3,c9,c1,2                ; D TCM 0 NS ctrl access
                STMNEIA r1!,{r2-r3}                     ; Save
                CMP     r11,#0                          ; >0 I TCMs?
                MRCNE   p15,0,r4,c9,c1,1                ; I TCM 0 Region
                MRCNE   p15,0,r5,c9,c1,3                ; I TCM 0 NS ctrl access
                STMNEIA r1!,{r4-r5}                     ; Save

                ORR     r0,r10,r11
                TST     r0,#2                           ; 2 I TCMs or 2 D TCMs?
                BEQ     end_TCM                         ; No: skip TCM 1 save

                MOV     r0,#1
                MCR     p15,0,r0,c9,c2,0                ; Select TCM bank 1
                CMP     r10,#2                          ; 2 D TCMs?
                MRCEQ   p15,0,r6,c9,c1,0                ; D TCM 1 Region
                MRCEQ   p15,0,r7,c9,c1,2                ; D TCM 1 NS ctrl access
                STMEQIA r1!,{r6-r7}                     ; Save
                CMP     r11,#2                          ; 2 I TCMs?
                MRCEQ   p15,0,r8,c9,c1,1                ; I TCM 1 Region
                MRCEQ   p15,0,r9,c9,c1,3                ; I TCM 1 NS ctrl access
                STMEQIA r1!,{r8-r9}                     ; Save
                LDR     r0,dormant_tcm_restore          ; get TCM back up buffer
                STR     r1,[r0]
end_TCM
                POP     {r1}

    IF :DEF: ARM_DMA
                ; wait for DMA to idle and back up DMA related state.
                MRC     p15,0,r0,c11,c0,0               ; Read DMA ID & Status
                CMP     r0,#3                           ; Do we have a DMA?
                BNE     no_DMA                          ; No - skip DMA save

                MRC     p15,0,r2,c11,c1,0               ; User Accessibility Reg
                MRC     p15,0,r3,c11,c2,0               ; Channel Number

                MOV     r0,#0
                MCR     p15,0,r0,c11,c2,0               ; Select Channel 0
                MRC     p15,0,r4,c11,c8,0               ; DMA channel status
                CMP     r4,#3                           ; Is there an error?
                BHI     abort_enter_dormant_mode        ; Yes: quit
                MCR     p15,0,r0,c11,c3,0               ; No: stop the channel
                LDR     r0,dormant_dma0                  ; keep channel 0 status
                STR     r4,[r0]

                MOV     r0,#1
                MCR     p15,0,r0,c11,c2,0               ; Select Channel 1
                MRC     p15,0,r10,c11,c8,0              ; DMA channel status
                CMP     r10,#3                          ; Is there an error?
                BHI     abort_enter_dormant_mode        ; Yes: quit
                MCR     p15,0,r0,c11,c3,0               ; No: stop the channel
                LDR     r0,dormant_dma1                  ; keep channel 1 status
                STR     r10,[r0]

                MOV     r0,#0
                MCR     p15,0,r0,c11,c2,0               ; Select Channel 0
wait_DMA0idle   MRC     p15,0,r0,c11,c8,0               ; DMA channel status
                ANDS    r0,r0,#3                        ; Is the channel idle
                CMPNE   r0,#3                           ; or Complete/Error?
                BNE     wait_DMA0idle                   ; Poll until it is
                MRC     p15,0,r5,c11,c4,0               ; Control Register
                MRC     p15,0,r6,c11,c5,0               ; Internal Start Address
                MRC     p15,0,r7,c11,c6,0               ; External Start Address
                MRC     p15,0,r8,c11,c7,0               ; Internal End Address
                MRC     p15,0,r9,c11,c15,0              ; Context ID
                STMIA   r1!,{r2-r9}                     ; Save
                MCR     p15,0,r0,c11,c3,2               ; Clear channel 0

                MOV     r0,#1
                MCR     p15,0,r0,c11,c2,0               ; Select Channel 1
                MOV     r4,r10                          ; Prior channel status
wait_DMA1idle   MRC     p15,0,r0,c11,c8,0               ; DMA channel status
                ANDS    r0,r0,#3                        ; Is the channel idle
                CMPNE   r0,#3                           ; or Complete/Error?
                BNE     wait_DMA1idle                   ; Poll until it is
                MRC     p15,0,r5,c11,c4,0               ; Control Register
                MRC     p15,0,r6,c11,c5,0               ; Internal Start Address
                MRC     p15,0,r7,c11,c6,0               ; External Start Address
                MRC     p15,0,r8,c11,c7,0               ; Internal End Address
                MRC     p15,0,r9,c11,c15,0              ; Context ID
                STMIA   r1!,{r4-r9}                     ; Save
                MCR     p15,0,r0,c11,c3,2               ; Clear channel 1
no_DMA

    ENDIF       ; ARM_DMA

                IF :DEF: ARM_SECURE_MODE

                MRS     r0,SPSR                         ; Get SPSR (Mon)
                STR     r0,[r1],#4                      ; Save SPSR

                ; Save the Secure Configuration register, then clear the NS bit
                ; to remain in the Secure world and select Secure versions of
                ; banked registers
                MRC     p15,0,r0,c1,c1,0                ; Read S Config
                STR     r0,[r1],#4                      ; Save
                BIC     r0,r0,#1                        ; Clear NS bit
                MCR     p15,0,r0,c1,c1,0                ; Write S Config

                ; Save the CPSR of secure mode
                MRS     r0,CPSR                         ; Get CPSR
                STR     r0,[r1],#4                      ; Save CPSR
                
                ; Also change to System mode to back up registers of other mode
                IF __NUCLEUS_VERSION_2__
                CPS      #MODE_SYS
                ELSE ; !__NUCLEUS_VERSION_2__
                CPS      #MODE_SVC
                ENDIF ; __NUCLEUS_VERSION_2__

                ; Save System/User mode registers
                STMIA   r1!,{r13-r14}                   ; Save r13-r14 (Sys/User)

                ELSE ; :DEF: ARM_SECURE_MODE

                ; already in system mode with NU v2, Save the CPSR of system mode
                MRS     r0,CPSR                         ; Get CPSR
                STR     r0,[r1],#4                      ; Save CPSR

                ENDIF ; :DEF: ARM_SECURE_MODE

                ; Save FIQ mode registers and SPSR
                CPS     #MODE_FIQ
                STMIA   r1!,{r8-r14}                    ; Save r8-r14 (FIQ)
                MRS     r0,SPSR                         ; Get SPSR
                STR     r0,[r1],#4                      ; Save SPSR

                ; Save IRQ mode registers and SPSR
                CPS     #MODE_IRQ
                STMIA   r1!,{r13-r14}                   ; Save r13-r14 (IRQ)
                MRS     r0,SPSR                         ; Get SPSR
                STR     r0,[r1],#4                      ; Save SPSR

                ; Save Abort mode registers and SPSR
                CPS     #MODE_ABT
                STMIA   r1!,{r13-r14}                   ; Save r13-r14 (Abort)
                MRS     r0,SPSR                         ; Get SPSR
                STR     r0,[r1],#4                      ; Save SPSR

                ; Save Supervisor/system mode registers and SPSR
                IF __NUCLEUS_VERSION_2__
                CPS     #MODE_SVC
                ELSE ; __NUCLEUS_VERSION_2__
                CPS     #MODE_SYS
                ENDIF ; __NUCLEUS_VERSION_2__

                STMIA   r1!,{r13-r14}                   ; Save r13-r14 (SVC)
                MRS     r0,SPSR                         ; Get SPSR
                STR     r0,[r1],#4                      ; Save SPSR

                ; Save Undefined mode registers and SPSR
                CPS     #MODE_UND
                STMIA   r1!,{r13-r14}                   ; Save r13-r14 (Undef)
                MRS     r0,SPSR                         ; Get SPSR
                STR     r0,[r1],#4                      ; Save SPSR

                IF :DEF: ARM_SECURE_MODE

                ; Switch back to secure monitor mode 
                CPS     #MODE_MON

                ELSE

                ; Switch back to system mode 
                IF __NUCLEUS_VERSION_2__
                CPS     #MODE_SYS
                ELSE ; __NUCLEUS_VERSION_2__
                CPS     #MODE_SVC
                ENDIF ; __NUCLEUS_VERSION_2__

                ENDIF ; :DEF: ARM_SECURE_MODE

                ; Save TLB lockdown register which is common to secure and non-secure world, 
                ; then force page table walks to write into the associative region of the TLB, 
                ; to avoid changing the lockdown region
                MRC     p15,0,r2,c10,c0,0               ; TLB Lockdown
                STR     r2,[r1],#4                      ; Save
                BIC     r2,r2,#1                        ; Clear P bit
                MCR     p15,0,r2,c10,c0,0               ; Write TLB Lockdown

                IF :DEF: ARM_SECURE_MODE
                ; Save remaining CP15 Secure registers
                MRC     p15,0,r2,c1,c1,1                ; S Debug Enable
                MRC     p15,0,r3,c1,c1,2                ; NS access control
                MRC     p15,0,r4,c5,c0,0                ; S DFSR
                MRC     p15,0,r5,c5,c0,1                ; S IFSR
                MRC     p15,0,r6,c6,c0,0                ; S FAR
                MRC     p15,0,r7,c6,c0,2                ; S IFAR
                MRC     p15,0,r8,c7,c4,0                ; S PA
                MRC     p15,0,r9,c9,c2,0                ; S TCM Selection
                MRC     p15,0,r10,c13,c0,2              ; S User R/W Thread/PID
                MRC     p15,0,r11,c13,c0,3              ; S User RO Thread/PID
                MRC     p15,0,r12,c13,c0,4              ; S Priv Only Thread/PID
                MRC     p15,0,r13,c1,c0,2               ; Coproc Access Control - read in secure state only
                STMIA   r1!,{r2-r13}                    ; Save

                ; Switch to non-secure mode
                MRC     p15,0,r0,c1,c1,0                ; Read S Config
                ORR     r0,r0,#1                        ; Set NS bit
                MCR     p15,0,r0,c1,c1,0                ; Write S Config

                ENDIF ; :DEF: ARM_SECURE_MODE

                ; Save Non-secure memory system control registers
                MRC     p15,0,r2,c7,c10,6               ; NS Cache Dirty Status
                MRC     p15,0,r3,c1,c0,0                ; NS Control
                MRC     p15,0,r4,c2,c0,0                ; NS TTBR0
                MRC     p15,0,r5,c2,c0,1                ; NS TTBR1
                MRC     p15,0,r6,c2,c0,2                ; NS TTBCR
                MRC     p15,0,r7,c3,c0,0                ; NS DAC
                MRC     p15,0,r8,c13,c0,0               ; NS FCSE PID
                MRC     p15,0,r9,c13,c0,1               ; NS Context ID
                MRC     p15,0,r10,c10,c2,0              ; NS Primary Region Remap
                MRC     p15,0,r11,c10,c2,1              ; NS Normal Memory Remap
                MRC     p15,0,r12,c15,c2,4              ; NS PP Memory Remap
                STMIA   r1!,{r2-r12}                    ; Save

                ; Save remaining CP15 Non-secure registers
                MRC     p15,0,r2,c5,c0,0                ; NS DFSR
                MRC     p15,0,r3,c5,c0,1                ; NS IFSR
                MRC     p15,0,r4,c6,c0,0                ; NS FAR
                MRC     p15,0,r5,c6,c0,2                ; NS IFAR
                MRC     p15,0,r6,c7,c4,0                ; NS PA
                MRC     p15,0,r7,c9,c2,0                ; NS TCM Selection
                MRC     p15,0,r8,c13,c0,2               ; NS User R/W Thread/PID
                MRC     p15,0,r9,c13,c0,3               ; NS User RO Thread/PID
                MRC     p15,0,r10,c13,c0,4              ; NS Priv Only Thread/PID
                MRC     p15,0,r11,c12,c0,0              ; NS Vector Base Address
                MRC     p15,0,r12,c1,c0,1               ; Auxiliary Control
                STMIA   r1!,{r2-r12}                    ; Save

                IF :DEF: ARM_SECURE_MODE

                ; Switch back to secure monitor mode.
                MRC     p15,0,r0,c1,c1,0                ; Read S Config
                BIC     r0,r0,#1                        ; Clear NS bit
                MCR     p15,0,r0,c1,c1,0                ; Write S Config

                ENDIF ; :DEF: ARM_SECURE_MODE

                ; Jazelle-DBX registers (CP14) should not be saved or restored 
                ; by this routine. The Virtual Machine should be relied upon 
                ; to re-initialize Jazelle-DBX state.

                ; Save TLB Lockdown Index
                MRC     p15,5,r5,c15,c4,2               ; TLB Lockdown Index
                STMIA   r1!,{r5}                        ; Save

                ; Save lockdown region of TLB
                MOV     r0,#0
                MCR     p15,5,r0,c15,c4,2               ; Select lockdown entry 0
                MRC     p15,5,r2,c15,c5,2               ; Read Main TLB VA
                MRC     p15,5,r3,c15,c6,2               ; Read Main TLB PA
                MRC     p15,5,r4,c15,c7,2               ; Read Main TLB Attr

                MOV     r0,#1
                MCR     p15,5,r0,c15,c4,2               ; Select lockdown entry 1
                MRC     p15,5,r5,c15,c5,2               ; Read Main TLB VA
                MRC     p15,5,r6,c15,c6,2               ; Read Main TLB PA
                MRC     p15,5,r7,c15,c7,2               ; Read Main TLB Attr

                MOV     r0,#2
                MCR     p15,5,r0,c15,c4,2               ; Select lockdown entry 2
                MRC     p15,5,r8,c15,c5,2               ; Read Main TLB VA
                MRC     p15,5,r9,c15,c6,2               ; Read Main TLB PA
                MRC     p15,5,r10,c15,c7,2              ; Read Main TLB Attr

                MOV     r0,#3
                MCR     p15,5,r0,c15,c4,2               ; Select lockdown entry 3
                MRC     p15,5,r11,c15,c5,2              ; Read Main TLB VA
                MRC     p15,5,r12,c15,c6,2              ; Read Main TLB PA
                MRC     p15,5,r13,c15,c7,2              ; Read Main TLB Attr

                STMIA   r1!,{r2-r13}                    ; Save

                MOV     r0,#4
                MCR     p15,5,r0,c15,c4,2               ; Select lockdown entry 4
                MRC     p15,5,r2,c15,c5,2               ; Read Main TLB VA
                MRC     p15,5,r3,c15,c6,2               ; Read Main TLB PA
                MRC     p15,5,r4,c15,c7,2               ; Read Main TLB Attr

                MOV     r0,#5
                MCR     p15,5,r0,c15,c4,2               ; Select lockdown entry 5
                MRC     p15,5,r5,c15,c5,2               ; Read Main TLB VA
                MRC     p15,5,r6,c15,c6,2               ; Read Main TLB PA
                MRC     p15,5,r7,c15,c7,2               ; Read Main TLB Attr

                MOV     r0,#6
                MCR     p15,5,r0,c15,c4,2               ; Select lockdown entry 6
                MRC     p15,5,r8,c15,c5,2               ; Read Main TLB VA
                MRC     p15,5,r9,c15,c6,2               ; Read Main TLB PA
                MRC     p15,5,r10,c15,c7,2              ; Read Main TLB Attr

                MOV     r0,#7
                MCR     p15,5,r0,c15,c4,2               ; Select lockdown entry 7
                MRC     p15,5,r11,c15,c5,2              ; Read Main TLB VA
                MRC     p15,5,r12,c15,c6,2              ; Read Main TLB PA
                MRC     p15,5,r13,c15,c7,2              ; Read Main TLB Attr

                STMIA   r1!,{r2-r13}                    ; Save

                ; Enable access to all coprocessors to save coproc & VFP state
                ; This register is common to secure and non-secure world.
                ; Write access in non-secure mode is ignored.
                MRC     p15,0,r0,c1,c0,2                ; back up coproc acc ctrl
                LDR     r2,dormant_coproc_acc
                STR     r0,[r2]
                LDR     r0,=0xFFFFFFFF                  ; Enable all coprocs
                MCR     p15,0,r0,c1,c0,2                ; Write coproc acc ctrl

    IF :DEF: ARM_VFP
                ; If we have a VFP coprocessor, save the VFP system regs and
                ; register bank.
                ; This code checks if the VFP is present by reading the
                ; coprocessor access control reg bits 23-20. If your code runs
                ; on a system that never has a VFP, you can remove this code.
                ; If your system always has a VFP, you can remove the check.
                MRC     p15,0,r0,c1,c0,2                ; Coproc access ctrl
                ANDS    r0,r0,#0xF << 20                ; VFP present?
                BEQ     no_VFP                          ; No - skip VFP save
                FMRX    r2,FPEXC                        ; VFP Exception
                ORR     r0,r2,#1 << 30                  ; Enable VFP
                FMXR    FPEXC,r0                        ; Write VFP Exception
                FMRX    r3,FPSCR                        ; VFP Status & Control
                FMRX    r4,FPINST                       ; VFP Instruction
                FMRX    r5,FPINST2                      ; VFP Instruction 2
                STMIA   r1!,{r2-r5}                     ; Save
                FSTMIAX r1!,{d0-d15}                    ; Save VFP register bank
no_VFP
    ENDIF

                ; Save the registers of all other coprocessors.
                ; Note: you can test for the presence of coprocessors by reading
                ; the appropriate bits of the coprocessor access control reg,
                ; but you still need to know what state must be saved for each
                ; individual coprocessor present in the system.

                ; Save the Performance Monitor registers
                ; Note: that performance monitor counts will be restarted from
                ; these saved values on exiting dormant mode, but not
                ; immediately, so the counts of events may not be correct.
                ; They are common to secure and non-secure world
                MRC     p15,0,r2,c15,c12,0              ; Performance mon ctrl
                MRC     p15,0,r3,c15,c12,1              ; Cycle counter
                MRC     p15,0,r4,c15,c12,2              ; Count register 0
                MRC     p15,0,r5,c15,c12,3              ; Count register 1
                STMIA   r1!,{r2-r5}                     ; Save

    IF :DEF: ARM_COPROC_P14
                ; Save the Debug registers
                MRC     p14,0,r2,c0,c1,0                ; DSCR
                ORR     r0,r2,#1 << 15                  ; Select & enable Debug
                BIC     r0,r0,#1 << 14                  ; monitor mode
                MCR     p14,0,r0,c0,c1,0                ; Write DSCR

                MRC     p14,0,r3,c0,c0,4                ; BVR0
                MRC     p14,0,r4,c0,c1,4                ; BVR1
                MRC     p14,0,r5,c0,c2,4                ; BVR2
                MRC     p14,0,r6,c0,c3,4                ; BVR3
                MRC     p14,0,r7,c0,c4,4                ; BVR4
                MRC     p14,0,r8,c0,c5,4                ; BVR5

                MRC     p14,0,r9,c0,c0,5                ; BCR0
                MRC     p14,0,r10,c0,c1,5               ; BCR1
                MRC     p14,0,r11,c0,c2,5               ; BCR2
                MRC     p14,0,r12,c0,c3,5               ; BCR3
                MRC     p14,0,r13,c0,c4,5               ; BCR4
                MRC     p14,0,r14,c0,c5,5               ; BCR5
                STMIA   r1!,{r2-r14}                    ; Save

                MRC     p14,0,r2,c0,c0,6                ; WVR0
                MRC     p14,0,r3,c0,c1,6                ; WVR1
                MRC     p14,0,r4,c0,c0,7                ; WCR0
                MRC     p14,0,r5,c0,c1,7                ; WCR1
                MRC     p14,0,r6,c0,c6,0                ; WFAR
                MRC     p14,0,r7,c0,c7,0                ; VCR
                MRC     p14,0,r8,c0,c10,0               ; DSCCR
                MRC     p14,0,r9,c0,c11,0               ; DSMCR
                STMIA   r1!,{r2-r9}                     ; Save
    ENDIF

                IF :DEF: ARM_SECURE_MODE

                ; Save the Secure and Monitor Vector Base Address registers
                ; Note: the NS bit must be clear at this point: this code clears
                ; it after saving the NS versions of banked registers.  If you
                ; alter this code, ensure that the NS bit is clear before saving
                ; the Secure Vector Base Address register.
                ; We must also save the Secure Configuration register here,
                ; even though we have already saved it, so that we can restore it
                ; to correctly handle interrupts that may occur during the
                ; dormant mode restore code.  It doesn't matter that we've
                ; cleared the NS bit in this register, as we restore the whole
                ; register including the NS bit at the end of the dormant mode
                ; restore code.
                MRC     p15,0,r2,c12,c0,0               ; S Vector Base Address
                MRC     p15,0,r3,c12,c0,1               ; Mon Vector Base Address
                MRC     p15,0,r4,c1,c1,0                ; S Config (NS bit = 0)
                STMIA   r1!,{r2-r4}                     ; Save

                ENDIF ; :DEF: ARM_SECURE_MODE

                ; Disable MMU and caches to save state that must be restored
                ; before the MMU and caches can be enabled.
                ; This ensures that this state is not saved into the cache.
                ; You may also need to change your Level 2 memory
                ; Secure/Non-secure memory mapping to allow the system to work
                ; correctly with the MMU disabled.
                ; Note: the NS bit must be clear at this point, to ensure that
                ; we access the Secure bank of the Control register if secure support 
                ; is enabled.

                MRC     p15,0,r2,c1,c0,0                ; Read current ctrl reg
                BIC     r10,r2,#1<<12                   ; Disable Icache
                BIC     r10,r10,#2_101                  ; Disable Dcache & MMU
                MCR     p15,0,r10,c1,c0,0               ; Write current ctrl reg
                LDR     r3,dormant_ctrl_reg             ; keep current ctrl reg
                STR     r2,[r3]

                ; We read the S Control reg into r2 before modifying it above.
                ; save mnemory system control register
                MRC     p15,0,r3,c2,c0,0                ; S TTBR0
                MRC     p15,0,r4,c2,c0,1                ; S TTBR1
                MRC     p15,0,r5,c2,c0,2                ; S TTBCR
                MRC     p15,0,r6,c3,c0,0                ; S DAC
                MRC     p15,0,r7,c13,c0,0               ; S FCSE PID
                MRC     p15,0,r8,c13,c0,1               ; S Context ID
                MRC     p15,0,r9,c10,c2,0               ; S Primary Region Remap
                MRC     p15,0,r10,c10,c2,1              ; S Normal Memory Remap
                MRC     p15,0,r11,c15,c2,4              ; S PP Memory Remap
                MRC     p15,0,r12,c9,c0,0               ; D Cache Lockdown
                MRC     p15,0,r13,c9,c0,1               ; I Cache Lockdown
                MRC     p15,0,r14,c9,c8,0               ; Cache Behavior Override
                STMIA   r1!,{r2-r14}                    ; Save

                ; Save the cache master valid registers
                ; Number of registers to save depends on the cache size:
                ; 4k cache: save reg 0
                ; 8k      :          0
                ; 16k     :          0-1
                ; 32k     :          0-3
                ; 64k     :          0-7
                ; Here we get the cache sizes from the cache type reg.
                ; If you know that your cache sizes are fixed you can remove
                ; the checking and just save the regs you need.
                ; Alternatively you can save all regs 0-7 regardless of the
                ; cache size - restoring unused regs has no effect. However,
                ; this impacts the performance due to extra MRCs and stores.
                ; D cache master valid bits
                MRC     p15,0,r0,c0,c0,1                ; Cache type
                AND     r10,r0,#7 << 18                 ; Dcache size in [20:18]
                MRC     p15,3,r2,c15,c12,0              ; Dcache master valid 0
                STR     r2,[r1],#4                      ; Save
                CMP     r10,#5 << 18                    ; Dcache >= 16k?
                MRCHS   p15,3,r3,c15,c12,1              ; Dcache master valid 1
                STRHS   r3,[r1],#4                      ; Save
                CMP     r10,#6 << 18                    ; Dcache >= 32k?
                MRCHS   p15,3,r4,c15,c12,2              ; Dcache master valid 2
                MRCHS   p15,3,r5,c15,c12,3              ; Dcache master valid 3
                STMHSIA r1!,{r4-r5}                     ; Save
                CMP     r10,#7 << 18                    ; Dcache = 64k?
                MRCHS   p15,3,r6,c15,c12,4              ; Dcache master valid 4
                MRCHS   p15,3,r7,c15,c12,5              ; Dcache master valid 5
                MRCHS   p15,3,r8,c15,c12,6              ; Dcache master valid 6
                MRCHS   p15,3,r9,c15,c12,7              ; Dcache master valid 7
                STMHSIA r1!,{r6-r9}                     ; Save

                ; I cache master valid bits
                AND     r10,r0,#7 << 6                  ; Icache size in [8:6]
                MRC     p15,3,r2,c15,c8,0               ; Icache master valid 0
                STR     r2,[r1],#4                      ; Save
                CMP     r10,#5 << 6                     ; Icache >= 16k?
                MRCHS   p15,3,r3,c15,c8,1               ; Icache master valid 1
                STRHS   r3,[r1],#4                      ; Save
                CMP     r10,#6 << 6                     ; Icache >= 32k?
                MRCHS   p15,3,r4,c15,c8,2               ; Icache master valid 2
                MRCHS   p15,3,r5,c15,c8,3               ; Icache master valid 3
                STMHSIA r1!,{r4-r5}                     ; Save
                CMP     r10,#7 << 6                     ; Icache = 64k?
                MRCHS   p15,3,r6,c15,c8,4               ; Icache master valid 4
                MRCHS   p15,3,r7,c15,c8,5               ; Icache master valid 5
                MRCHS   p15,3,r8,c15,c8,6               ; Icache master valid 6
                MRCHS   p15,3,r9,c15,c8,7               ; Icache master valid 7
                STMHSIA r1!,{r6-r9}                     ; Save

                ; Save the address at the end of the state saving.
                ; Save this at a known fixed address so we can restore from it.
                LDR     r0,dormant_restore
                STR     r1,[r0]

    IF :DEF: ARM_WFI_IN_ENTRY
                ; Drain the write buffer
                MCR     p15,0,r0,c7,c10,4

                ; Wait for interrupt (asserts STANDBYWFI macrocell output)
                MCR     p15,0,r0,c7,c0,4
    ENDIF
                ; dormant mode is abort since wake up event is triggered before entering standby mode

                ; restore cache and MMU setting
                LDR     r0,dormant_ctrl_reg             ; get backed up current ctrl reg
                LDR     r2,[r0]
                MRS     r4, CPSR
                MSR     CPSR_f, #&20000000
                MCR     p15,0,r2,c1,c0,0                ; restore current ctrl reg
                MCR     p15,0,r2,c7,c5,4                ; Prefetch flush
                DCI     0x950f07ee                      ; Pf flush inverted
                MSR     CPSR_f, r4 

                ; restore co-proc access setting
                LDR     r2,dormant_coproc_acc
                LDR     r0,[r2]
                MCR     p15,0,r0,c1,c0,2                ; Restore coproc acc ctrl

    IF :DEF: ARM_DMA
                ; restart unfinished DMA channel
                MOV     r0,#1
                MCR     p15,0,r0,c11,c2,0               ; Select Channel 1
                LDR     r1,dormant_dma1
                LDR     r8,[r1]
                CMP     r8,#3                           ; Was channel 1 complete?
                MCREQ   p15,0,r0,c11,c3,1               ; Yes: start the channel
                ; If the channel was queued or running, start it after channel 0.

                MOV     r0,#0
                MCR     p15,0,r0,c11,c2,0               ; Select Channel 0
                LDR     r1,dormant_dma0
                LDR     r2,[r1]
                TST     r2,#2                           ; Was channel 0 complete
                                                        ;  or running?
                MCRNE   p15,0,r0,c11,c3,1               ; Yes: start the channel

                MOV     r0,#1
                CMP     r8,#1                           ; Was channel 1 queued?
                CMPNE   r8,#2                           ; No: was it running?
                MCREQ   p15,0,r0,c11,c2,0               ; Yes: select channel 1;
                MCREQ   p15,0,r0,c11,c3,1               ;      start the channel

                MOV     r0,#0
                CMP     r2,#1                           ; Was channel 0 queued?
                MCREQ   p15,0,r0,c11,c2,0               ; Yes: select channel 0;
                MCREQ   p15,0,r0,c11,c3,1               ;      start the channel
    ENDIF

                ; restore register content before trying to enter dormanr mode
                LDR     r1,dormant_backup
                ADD     r1,#&3C
                LDMDB   r1,{r0-r14}                     ; Restore r0-r14 (gp/Mon)
                PUSH    {r1, r14}
                LDR     r1,dormant_interrupt_func       ; dormant mode reset is aborted - idle task's stack
                BLX     r1
                POP     {r1, r14}
                ; Return from dormant mode entry/exit
                BLX      r14

abort_enter_dormant_mode
  ; We come here if either DMA channel has stopped with an error.
  ; Restore any registers we have changed and return.

                MCR     p15,0,r3,c11,c2,0               ; Restore DMA channel no
                SUB     r1, r1, #56
                LDMIA   r1,{r0-r14}                     ; Restore r0-r14 (MON)
                PUSH    {r1, r14}
                LDR     r1, dormant_abort_func          ; entry to dormant mode is aborted - idle task's stack
                BLX     r1                              ;
                POP     {r1, r14}
                BX      r14                             ; Return

; Data pool
dormant_backup      
                    DCD     dormant_mode_storage
dormant_tcm_backup  
                    DCD     dormant_tcm_storage
dormant_tcm_restore 
                    DCD     dormant_tcm_restore_begin
dormant_restore     
                    DCD     dormant_restore_begin
dormant_dma0
                    DCD     dormant_dma0_status
dormant_dma1
                    DCD     dormant_dma1_status
dormant_ctrl_reg
                    DCD     dormant_ctrl_backup
dormant_coproc_acc
                    DCD     dormant_coproc_acc_ctrl
dormant_wb_dummy    
                    DCD     dormant_dummy_wb_variable
dormant_abort_func
                    DCD     dormant_mode_abort_entry
dormant_interrupt_func
                    DCD     dormant_mode_abort_reset

tcm_backup_mark     DCD     0x4D435457
                LTORG

;*******************************************************************************
;*      Leave dormant mode
;*******************************************************************************

  ; The dormant mode exit code restores all required state in the correct order
  ; (generally the opposite order from that in which it was saved).
  ; You must make some modifications to this code as explained by the comments
  ; within it.  When all state is restored, the dormant mode exit code restores
  ; the original CPSR, and returns to the instruction after the the
  ; original call to the dormant mode entry code.

;void leave_dormant_mode(void) 

                EXPORT  leave_dormant_mode

leave_dormant_mode
                ; Assume we are in a Secure privileged mode (as at reset).

                IF :DEF: ARM_SECURE_MODE
                ; Enter Monitor mode and ensure interrupts are disabled
                ; Note that we enter Monitor mode by modifying the CPSR
                ; directly, rather than relying on a SMI handler that may not
                ; be set up yet.
                CPS     #MODE_MON

                ; Make sure that the NS bit is clear so we can restore secure
                ; versions of banked registers.
                MRC     p15,0,r0,c1,c1,0                ; Read S Config
                BIC     r0,r0,#1                        ; Clear NS bit
                MCR     p15,0,r0,c1,c1,0                ; Write S Config
                ELSE

                IF __NUCLEUS_VERSION_2__
                CPS     #MODE_SYS                       ; switch back to system mode
                ELSE
                ; already in supervisor mode after reset
                ENDIF ; __NUCLEUS_VERSION_2__

                ENDIF ; :DEF: ARM_SECURE_MODE

                ; Restore TCM registers
                ; This code checks how many I and D TCMs are present by reading
                ; the TCM Status Register, and only restores registers for TCMs
                ; that exist.  (Saving registers for non-existent TCMs does no
                ; harm as the writes to restore the values are ignored by the
                ; processor, but it takes longer.)  If you know the number of
                ; TCMs in your system is constant, you can simplify or remove
                ; this code.
                MRC     p15,0,r0,c0,c0,2                ; Read TCM Status
                MOV     r10,r0,LSR #16                  ; Get # D TCMs (0-2)
                AND     r11,r0,#3                       ; Get # I TCMs (0-2)
                ADDS    r0,r10,r11                      ; 0 TCMs in total?
                BEQ     end_TCM_rst                     ; Skip TCM reg restore
                LDR     r0,dormant_tcm_restore          ; get TCM back up buffer
                LDR     r1,[r0]

                ORR     r0,r10,r11
                TST     r0,#2                           ; 2 I TCMs or 2 D TCMs?
                BEQ     TCM0_rst                        ; No: skip TCM 1 restore

                MOV     r0,#1
                MCR     p15,0,r0,c9,c2,0                ; Select TCM bank 1
                CMP     r11,#2                          ; 2 I TCMs?
                LDMEQDB r1!,{r8-r9}                     ; Save
                MCREQ   p15,0,r9,c9,c1,3                ; I TCM 1 NS ctrl access
                MCREQ   p15,0,r8,c9,c1,1                ; I TCM 1 Region
                CMP     r10,#2                          ; 2 D TCMs?
                LDMEQDB r1!,{r6-r7}                     ; Save
                MCREQ   p15,0,r7,c9,c1,2                ; D TCM 1 NS ctrl access
                MCREQ   p15,0,r6,c9,c1,0                ; D TCM 1 Region
TCM0_rst
                MOV     r0,#0
                MCR     p15,0,r0,c9,c2,0                ; Select TCM bank 0
                CMP     r11,#0                          ; >0 I TCMs?
                LDMNEDB r1!,{r4-r5}                     ; Save
                MCRNE   p15,0,r5,c9,c1,3                ; I TCM 0 NS ctrl access
                MCRNE   p15,0,r4,c9,c1,1                ; I TCM 0 Region
                CMP     r10,#0                          ; >0 D TCMs?
                LDMNEDB r1!,{r2-r3}                     ; Save
                MCRNE   p15,0,r3,c9,c1,2                ; D TCM 0 NS ctrl access
                MCRNE   p15,0,r2,c9,c1,0                ; D TCM 0 Region
end_TCM_rst

                ; Load the address at the end of the state save memory region
                LDR     r0,dormant_restore
                LDR     r1,[r0]
                MOV     r0,#0

                ; Restore the cache master valid registers
                ; Number of registers to restore depends on the cache size:
                ; 4k cache: restore reg 0
                ; 8k      :             0
                ; 16k     :             0-1
                ; 32k     :             0-3
                ; 64k     :             0-7
                ; Here we get the cache sizes from the cache type reg.
                ; If you know that your cache sizes are fixed you can remove
                ; the checking and just restore the regs you need.
                ; Alternatively you can restore all regs 0-7 regardless of the
                ; cache size - restoring unused regs has no effect. However,
                ; this impacts the performance due to extra MCRs and reads.
                ; I cache master valid bits
                MRC     p15,0,r0,c0,c0,1                ; Cache type
                AND     r10,r0,#7 << 6                  ; Icache size in [8:6]
                CMP     r10,#7 << 6                     ; Icache = 64k?
                LDMHSDB r1!,{r6-r9}                     ; Load
                MCRHS   p15,3,r9,c15,c8,7               ; Icache master valid 7
                MCRHS   p15,3,r8,c15,c8,6               ; Icache master valid 6
                MCRHS   p15,3,r7,c15,c8,5               ; Icache master valid 5
                MCRHS   p15,3,r6,c15,c8,4               ; Icache master valid 4
                CMP     r10,#6 << 6                     ; Icache >= 32k?
                LDMHSDB r1!,{r4-r5}                     ; Load
                MCRHS   p15,3,r5,c15,c8,3               ; Icache master valid 3
                MCRHS   p15,3,r4,c15,c8,2               ; Icache master valid 2
                CMP     r10,#5 << 6                     ; Icache >= 16k?
                LDRHS   r3,[r1,#-4]!                    ; Load
                MCRHS   p15,3,r3,c15,c8,1               ; Icache master valid 1
                LDR     r2,[r1,#-4]!                    ; Load
                MCR     p15,3,r2,c15,c8,0               ; Icache master valid 0

                ; D cache master valid bits
                AND     r10,r0,#7 << 18                 ; Dcache size in [8:6]
                CMP     r10,#7 << 18                    ; Dcache = 64k?
                LDMHSDB r1!,{r6-r9}                     ; Load
                MCRHS   p15,3,r9,c15,c12,7              ; Dcache master valid 7
                MCRHS   p15,3,r8,c15,c12,6              ; Dcache master valid 6
                MCRHS   p15,3,r7,c15,c12,5              ; Dcache master valid 5
                MCRHS   p15,3,r6,c15,c12,4              ; Dcache master valid 4
                CMP     r10,#6 << 18                    ; Dcache >= 32k?
                LDMHSDB r1!,{r4-r5}                     ; Load
                MCRHS   p15,3,r5,c15,c12,3              ; Dcache master valid 3
                MCRHS   p15,3,r4,c15,c12,2              ; Dcache master valid 2
                CMP     r10,#5 << 18                    ; Dcache >= 16k?
                LDRHS   r3,[r1,#-4]!                    ; Load
                MCRHS   p15,3,r3,c15,c12,1              ; Dcache master valid 1
                LDR     r2,[r1,#-4]!                    ; Load
                MCR     p15,3,r2,c15,c12,0              ; Dcache master valid 0

                ; memory system control register
                LDMDB   r1!,{r2-r14}                    ; Load
                MCR     p15,0,r14,c9,c8,0               ; Cache Behavior Override
                MCR     p15,0,r13,c9,c0,1               ; I Cache Lockdown
                MCR     p15,0,r12,c9,c0,0               ; D Cache Lockdown
                MCR     p15,0,r11,c15,c2,4              ; S PP Memory Remap
                MCR     p15,0,r10,c10,c2,1              ; S Normal Memory Remap
                MCR     p15,0,r9,c10,c2,0               ; S Primary Region Remap
                MCR     p15,0,r8,c13,c0,1               ; S Context ID
                MCR     p15,0,r7,c13,c0,0               ; S FCSE PID
                MCR     p15,0,r6,c3,c0,0                ; S DAC
                MCR     p15,0,r5,c2,c0,2                ; S TTBCR
                MCR     p15,0,r4,c2,c0,1                ; S TTBR1
                MCR     p15,0,r3,c2,c0,0                ; S TTBR0

                MRS     r4, CPSR
                MSR     CPSR_f, #&20000000
                MCR     p15,0,r2,c1,c0,0                ; S Control
                MCR     p15,0,r2,c7,c5,4                ; Prefetch flush
                DCI     0x950f07ee                      ; Pf flush inverted
                MSR     CPSR_f, r4 

                IF :DEF: ARM_SECURE_MODE
                ; Restore the Secure and Monitor Vector Base Address registers
                ; Also restore the Secure Configuration register (with the NS bit
                ; cleared) so that interrupts during this restore code will be
                ; handled correctly.
                LDMDB   r1!,{r2-r4}                     ; Load
                MCR     p15,0,r4,c1,c1,0                ; S Config (NS bit = 0)
                MCR     p15,0,r3,c12,c0,1               ; Mon Vector Base Address
                MCR     p15,0,r2,c12,c0,0               ; S Vector Base Address
                ENDIF ; :DEF: ARM_SECURE_MODE

    IF :DEF: ARM_COPROC_P14
                ; Restore the Debug registers
                MRC     p14,0,r0,c0,c1,0                ; Read DSCR
                ORR     r0,r0,#1 << 15                  ; Select & enable Debug
                BIC     r0,r0,#1 << 14                  ;  monitor mode
                MCR     p14,0,r0,c0,c1,0                ; Write DSCR

                LDMDB   r1!,{r2-r9}                     ; Load
                MCR     p14,0,r9,c0,c11,0               ; DSMCR
                MCR     p14,0,r8,c0,c10,0               ; DSCCR
                MCR     p14,0,r7,c0,c7,0                ; VCR
                MCR     p14,0,r6,c0,c6,0                ; WFAR
                MCR     p14,0,r5,c0,c1,7                ; WCR1
                MCR     p14,0,r4,c0,c0,7                ; WCR0
                MCR     p14,0,r3,c0,c1,6                ; WVR1
                MCR     p14,0,r2,c0,c0,6                ; WVR0
                LDMDB   r1!,{r2-r14}                    ; Load
                MCR     p14,0,r14,c0,c5,5               ; BCR5
                MCR     p14,0,r13,c0,c4,5               ; BCR4
                MCR     p14,0,r12,c0,c3,5               ; BCR3
                MCR     p14,0,r11,c0,c2,5               ; BCR2
                MCR     p14,0,r10,c0,c1,5               ; BCR1
                MCR     p14,0,r9,c0,c0,5                ; BCR0
                MCR     p14,0,r8,c0,c5,4                ; BVR5
                MCR     p14,0,r7,c0,c4,4                ; BVR4
                MCR     p14,0,r6,c0,c3,4                ; BVR3
                MCR     p14,0,r5,c0,c2,4                ; BVR2
                MCR     p14,0,r4,c0,c1,4                ; BVR1
                MCR     p14,0,r3,c0,c0,4                ; BVR0
                MCR     p14,0,r2,c0,c1,0                ; DSCR
    ENDIF

                ; Restore the Performance Monitor registers
                ; Note: performance monitor counts will now restart from
                ; their saved values.  They have not counted events between the
                ; time these registers were saved and this point in time, so the
                ; counts of events may not be correct.
                ; Note: Bits [10:8] of the performance monitor control register
                ; are overflow/interrupt flags.  These flags cannot be saved
                ; and restored correctly, and the flags will all be cleared
                ; after restoring these registers.
                LDMDB   r1!,{r2-r5}                     ; Load
                MCR     p15,0,r5,c15,c12,3              ; Count register 1
                MCR     p15,0,r4,c15,c12,2              ; Count register 0
                MCR     p15,0,r3,c15,c12,1              ; Cycle counter
                MCR     p15,0,r2,c15,c12,0              ; Performance mon ctrl

                ; Enable access to all coprocessors to restore coproc & VFP
                ; state
                LDR     r0,=0xFFFFFFFF                  ; Enable all coprocs
                MCR     p15,0,r0,c1,c0,2                ; Write coproc acc ctrl

    IF :DEF: ARM_VFP
                ; If we have a VFP coprocessor, restore the VFP system regs and
                ; register bank.
                ; This code checks if the VFP is present by reading the
                ; coprocessor access control reg bits 23-20. If your code runs
                ; on a system that never has a VFP, you can remove this code.
                ; If your system always has a VFP, you can remove the check.
                MRC     p15,0,r0,c1,c0,2                ; Coproc access ctrl
                ANDS    r0,r0,#0xF << 20                ; VFP present?
                BEQ     no_VFP_rst                      ; No - skip VFP restore
                FMRX    r0,FPEXC                        ; VFP Exception
                ORR     r0,r0,#1 << 30                  ; Enable VFP
                FMXR    FPEXC,r0                        ; Write VFP Exception
                FLDMDBX r1!,{d0-d15}                    ; Restore VFP reg bank
                LDMDB   r1!,{r2-r5}                     ; Restore
                FMXR    FPINST2,r5                      ; VFP Instruction 2
                FMXR    FPINST,r4                       ; VFP Instruction
                FMXR    FPSCR,r3                        ; VFP Status & Control
                FMXR    FPEXC,r2                        ; Write VFP Exception
no_VFP_rst
    ENDIF

                ; Restore lockdown region of TLB
                ; Restore the PA register for each lockdown entry last, as this
                ; register contains the Valid bit for the entry.
                LDMDB   r1!,{r2-r13}                    ; Load

                MOV     r0,#7
                MCR     p15,5,r0,c15,c4,2               ; Select lockdown entry 7
                MCR     p15,5,r13,c15,c7,2              ; Write Main TLB Attr
                MCR     p15,5,r11,c15,c5,2              ; Write Main TLB VA
                MCR     p15,5,r12,c15,c6,2              ; Write Main TLB PA

                MOV     r0,#6
                MCR     p15,5,r0,c15,c4,2               ; Select lockdown entry 6
                MCR     p15,5,r10,c15,c7,2              ; Write Main TLB Attr
                MCR     p15,5,r8,c15,c5,2               ; Write Main TLB VA
                MCR     p15,5,r9,c15,c6,2               ; Write Main TLB PA

                MOV     r0,#5
                MCR     p15,5,r0,c15,c4,2               ; Select lockdown entry 5
                MCR     p15,5,r7,c15,c7,2               ; Write Main TLB Attr
                MCR     p15,5,r5,c15,c5,2               ; Write Main TLB VA
                MCR     p15,5,r6,c15,c6,2               ; Write Main TLB PA

                MOV     r0,#4
                MCR     p15,5,r0,c15,c4,2               ; Select lockdown entry 4
                MCR     p15,5,r4,c15,c7,2               ; Write Main TLB Attr
                MCR     p15,5,r2,c15,c5,2               ; Write Main TLB VA
                MCR     p15,5,r3,c15,c6,2               ; Write Main TLB PA

                LDMDB   r1!,{r2-r13}                    ; Load

                MOV     r0,#3
                MCR     p15,5,r0,c15,c4,2               ; Select lockdown entry 3
                MCR     p15,5,r13,c15,c7,2              ; Write Main TLB Attr
                MCR     p15,5,r11,c15,c5,2              ; Write Main TLB VA
                MCR     p15,5,r12,c15,c6,2              ; Write Main TLB PA

                MOV     r0,#2
                MCR     p15,5,r0,c15,c4,2               ; Select lockdown entry 2
                MCR     p15,5,r10,c15,c7,2              ; Write Main TLB Attr
                MCR     p15,5,r8,c15,c5,2               ; Write Main TLB VA
                MCR     p15,5,r9,c15,c6,2               ; Write Main TLB PA

                MOV     r0,#1
                MCR     p15,5,r0,c15,c4,2               ; Select lockdown entry 1
                MCR     p15,5,r7,c15,c7,2               ; Write Main TLB Attr
                MCR     p15,5,r5,c15,c5,2               ; Write Main TLB VA
                MCR     p15,5,r6,c15,c6,2               ; Write Main TLB PA

                MOV     r0,#0
                MCR     p15,5,r0,c15,c4,2               ; Select lockdown entry 0
                MCR     p15,5,r4,c15,c7,2               ; Write Main TLB Attr
                MCR     p15,5,r2,c15,c5,2               ; Write Main TLB VA
                MCR     p15,5,r3,c15,c6,2               ; Write Main TLB PA

                ; Restore TLB Lockdown Index. 
                LDMDB   r1!,{r5}                        ; Load
                MCR     p15,5,r5,c15,c4,2               ; TLB Lockdown Index

                IF :DEF: ARM_SECURE_MODE
  ; Set the NS bit to select NS versions of banked registers
  ; Note: if an interrupt occurs during this code's execution (in Monitor mode
  ; with the NS bit set), the NS bit will be automatically cleared to ensure
  ; that the processor remains in the Secure world. Your interrupt handler must
  ; recognise this, and if it decides to continue exit from Dormant mode, it must
  ; re-enter Monitor mode and set the NS bit before returning to this code.
  ; Alternatively, disable interrupts during this section of code.
                MRC     p15,0,r0,c1,c1,0                ; Read S Config
                ORR     r0,r0,#1                        ; Set NS bit
                MCR     p15,0,r0,c1,c1,0                ; Write S Config

                ENDIF ; :DEF: ARM_SECURE_MODE

                ; Restore common Aux ctrl and Coprocessor access ctrl registers,
                ; and CP15 Non-secure registers
                LDMDB   r1!,{r2-r12}                    ; Load
                MCR     p15,0,r12,c1,c0,1               ; Auxiliary Control
                MCR     p15,0,r11,c12,c0,0              ; NS Vector Base Address
                MCR     p15,0,r10,c13,c0,4              ; NS Priv Only Thread/PID
                MCR     p15,0,r9,c13,c0,3               ; NS User RO Thread/PID
                MCR     p15,0,r8,c13,c0,2               ; NS User R/W Thread/PID
                MCR     p15,0,r7,c9,c2,0                ; NS TCM Selection
                MCR     p15,0,r6,c7,c4,0                ; NS PA
                MCR     p15,0,r5,c6,c0,2                ; NS IFAR
                MCR     p15,0,r4,c6,c0,0                ; NS FAR
                MCR     p15,0,r3,c5,c0,1                ; NS IFSR
                MCR     p15,0,r2,c5,c0,0                ; NS DFSR

                ; Restore Non-secure memory system control registers
                LDMDB   r1!,{r2-r12}                    ; Load
                MCR     p15,0,r12,c15,c2,4              ; NS PP Memory Remap
                MCR     p15,0,r11,c10,c2,1              ; NS Normal Memory Remap
                MCR     p15,0,r10,c10,c2,0              ; NS Primary Region Remap
                MCR     p15,0,r9,c13,c0,1               ; NS Context ID
                MCR     p15,0,r8,c13,c0,0               ; NS FCSE PID
                MCR     p15,0,r7,c3,c0,0                ; NS DAC
                MCR     p15,0,r6,c2,c0,2                ; NS TTBCR
                MCR     p15,0,r5,c2,c0,1                ; NS TTBR1
                MCR     p15,0,r4,c2,c0,0                ; NS TTBR0

                MRS     r4, CPSR
                MSR     CPSR_f, #&20000000
                MCR     p15,0,r3,c1,c0,0                ; NS Control
                MCR     p15,0,r3,c7,c5,4                ; Prefetch flush
                DCI     0x950f07ee                      ; Pf flush inverted
                MSR     CPSR_f, r4 

                ; Restore Non-secure Cache Dirty Status Register
                ; This cannot be restored directly as the register is
                ; architecturally read only. If it was set on entry to Dormant
                ; mode, set it here by dirtying a Non-secure line in the cache.
                ; This can be achieved by performing a store instruction in a
                ; writeback region of the cache. 
                ; You may need to force the data cache and MMU to be enabled for this: 
                ; you can restore the original setup afterwards. 
                ; Note that because we are doing this from Monitor mode, the data cache 
                ; must be enabled in the Secure world as well as in the Non-secure world 
                ; to get a cache linefill to occur.
                ; To ensure that the store instruction hits in the cache,
                ; disable interrupts for this code sequence.
                ; If the NS Cache Dirty Status Register was clear, there is no
                ; need to clear it now.

                ; You must define an address which is guaranteed to be in a Non-secure
                ; writeback region of memory. The data at this address will not be modified
                ; when dirtying the cache.
                ; Note that we only need to restore the Non-secure Cache Dirty
                ; Status Register, as the Secure version is set automatically by
                ; writing the cache master valid bits which we have already done.

                ; Test saved Cache Dirty Status Register (in r2) against current
                MRC     p15,0,r0,c7,c10,6               ; Read NS Cache Dirty St
                CMP     r2,r0                           ; Loaded set, read clear?
                BLS     no_dirty_cache                  ; No: skip cache dirtying
                ; Force-set the NS Cache Dirty Status Register
                LDR     r3,dormant_wb_dummy             ; Get target address
                BIC     r5,r3,#0x1F                     ; 1st word in cache line
                LDR     r0,[r5]                         ; Load (causes linefill)
                LDR     r0,[r5,#0x1C]                   ; Load last word in line
                MCR     p15,0,r0,c7,c10,5               ; Data memory barrier
                LDR     r4,[r3]                         ; Load the data
                ADD     r4,#1
                STR     r4,[r3]                         ; Dirty the cache
                ; The NS Cache Dirty Status Register is now set.

                ; If you have modified your memory system setup for this cache
                ; dirtying operation, restore it now.
no_dirty_cache

                IF :DEF: ARM_SECURE_MODE
                ; Clear the NS bit to select Secure versions of banked registers.
                ; (If you disabled interrupts while the NS bit was set,
                ; you can re-enable them now.)
                MRC     p15,0,r0,c1,c1,0                ; Read S Config
                BIC     r0,r0,#1                        ; Clear NS bit
                MCR     p15,0,r0,c1,c1,0                ; Write S Config

                ; Restore CP15 Secure registers
                LDMDB   r1!,{r2-r13}                    ; Load
                MCR     p15,0,r13,c1,c0,2               ; Coproc Access Control - secure state write only
                MCR     p15,0,r12,c13,c0,4              ; S Priv Only Thread/PID
                MCR     p15,0,r11,c13,c0,3              ; S User RO Thread/PID
                MCR     p15,0,r10,c13,c0,2              ; S User R/W Thread/PID
                MCR     p15,0,r9,c9,c2,0                ; S TCM Selection
                MCR     p15,0,r8,c7,c4,0                ; S PA
                MCR     p15,0,r7,c6,c0,2                ; S IFAR
                MCR     p15,0,r6,c6,c0,0                ; S FAR
                MCR     p15,0,r5,c5,c0,1                ; S IFSR
                MCR     p15,0,r4,c5,c0,0                ; S DFSR
                MCR     p15,0,r3,c1,c1,2                ; NS access control
                MCR     p15,0,r2,c1,c1,1                ; S Debug Enable

                ENDIF ; :DEF: ARM_SECURE_MODE

                ; Restore TLB lockdown register
                LDR     r2,[r1,#-4]!                    ; Load
                MCR     p15,0,r2,c10,c0,0               ; TLB Lockdown

                ; Disable interrupts while we restore mode SPSRs and regs
                ; Also change to Undefined mode for the first SPSR/reg restore
                CPSID   if,#MODE_UND

                ; Restore Undefined mode SPSR and registers
                LDR     r0,[r1,#-4]!                    ; Load SPSR
                MSR     SPSR_cxsf,r0                    ; Restore SPSR
                LDMDB   r1!,{r13-r14}                   ; Restore r13-r14 (UND)

                ; Restore Supervisor/system mode SPSR and registers
                IF __NUCLEUS_VERSION_2__
                CPS     #MODE_SVC
                ELSE  ; !__NUCLEUS_VERSION_2__
                CPS     #MODE_SYS
                ENDIF ; __NUCLEUS_VERSION_2__
                LDR     r0,[r1,#-4]!                    ; Load SPSR
                MSR     SPSR_cxsf,r0                    ; Restore SPSR
                LDMDB   r1!,{r13-r14}                   ; Restore r13-r14 (SVC)

                ; Restore Abort mode SPSR and registers
                CPS     #MODE_ABT
                LDR     r0,[r1,#-4]!                    ; Load SPSR
                MSR     SPSR_cxsf,r0                    ; Restore SPSR
                LDMDB   r1!,{r13-r14}                   ; Restore r13-r14 (Abt)

                ; Restore IRQ mode SPSR and registers
                CPS     #MODE_IRQ
                LDR     r0,[r1,#-4]!                    ; Load SPSR
                MSR     SPSR_cxsf,r0                    ; Restore SPSR
                LDMDB   r1!,{r13-r14}                   ; Restore r13-r14 (IRQ)

                ; Restore FIQ mode SPSR and registers
                CPS     #MODE_FIQ
                LDR     r0,[r1,#-4]!                    ; Load SPSR
                MSR     SPSR_cxsf,r0                    ; Restore SPSR
                LDMDB   r1!,{r8-r14}                    ; Restore r8-r14 (FIQ)

                IF :DEF: ARM_SECURE_MODE

                ; Restore System/User mode registers
                IF __NUCLEUS_VERSION_2__
                CPS     #MODE_SYS
                ELSE  ; !__NUCLEUS_VERSION_2__
                CPS     #MODE_SVC
                ENDIF ; __NUCLEUS_VERSION_2__

                LDMDB   r1!,{r13-r14}                   ; Restore r13-r14 (Sys)

                ; Restore CPSR (puts us into Secure Monitor mode)
                LDR     r0,[r1,#-4]!                    ; Load CPSR
                MSR     CPSR_cxsf,r0                    ; Restore CPSR
                ; Now in Monitor mode, with enabling of interrupts restored.
                
                ; Restore Secure Configuration register (this may set the NS bit)
                LDR     r2,[r1,#-4]!                    ; Load
                MCR     p15,0,r2,c1,c1,0                ; S Config

                ; Restore Monitor mode SPSR and registers, and general registers
                LDR     r0,[r1,#-4]!                    ; Load SPSR
                MSR     SPSR_cxsf,r0                    ; Restore SPSR

                ELSE

                ; already in system mode with NU v2, Save the CPSR of system mode
                LDR     r0,[r1,#-4]!                    ; Load CPSR
                MSR     CPSR_cxsf,r0                    ; Restore CPSR

                ENDIF ; :DEF: ARM_SECURE_MODE
                

    IF :DEF: ARM_DMA
                ; If we have a DMA, restore DMA state (both channels) and
                ; restart any previously running and queued DMA channels
                ; This code checks if the DMA is present by reading the DMA ID
                ; & Status reg.  If your code runs on a system that never has
                ; an internal DMA engine you can remove this code section.
                MRC     p15,0,r0,c11,c0,0               ; Read DMA ID & Status
                CMP     r0,#3                           ; Do we have a DMA?
                BNE     no_DMA_rst                      ; No - skip DMA restore

                LDMDB   r1!,{r2-r13}                    ; Load
                MOV     r0,#1
                MCR     p15,0,r0,c11,c2,0               ; Select Channel 1
                MCR     p15,0,r13,c11,c15,0             ; Context ID
                MCR     p15,0,r12,c11,c7,0              ; Internal End Address
                MCR     p15,0,r11,c11,c6,0              ; External Start Address
                MCR     p15,0,r10,c11,c5,0              ; Internal Start Address
                MCR     p15,0,r9,c11,c4,0               ; Control Register
                CMP     r8,#3                           ; Was channel 1 complete?
                MCREQ   p15,0,r0,c11,c3,1               ; Yes: start the channel
                ; If the channel was queued or running, start it after channel 0.

                MOV     r0,#0
                MCR     p15,0,r0,c11,c2,0               ; Select Channel 0
                MCR     p15,0,r7,c11,c15,0              ; Context ID
                MCR     p15,0,r6,c11,c7,0               ; Internal End Address
                MCR     p15,0,r5,c11,c6,0               ; External Start Address
                MCR     p15,0,r4,c11,c5,0               ; Internal Start Address
                MCR     p15,0,r3,c11,c4,0               ; Control Register
                TST     r2,#2                           ; Was channel 0 complete
                                                        ;  or running?
                MCRNE   p15,0,r0,c11,c3,1               ; Yes: start the channel

                MOV     r0,#1
                CMP     r8,#1                           ; Was channel 1 queued?
                CMPNE   r8,#2                           ; No: was it running?
                MCREQ   p15,0,r0,c11,c2,0               ; Yes: select channel 1;
                MCREQ   p15,0,r0,c11,c3,1               ;      start the channel

                MOV     r0,#0
                CMP     r2,#1                           ; Was channel 0 queued?
                MCREQ   p15,0,r0,c11,c2,0               ; Yes: select channel 0;
                MCREQ   p15,0,r0,c11,c3,1               ;      start the channel

                LDMDB   r1!,{r2-r3}                     ; Load
                MCR     p15,0,r3,c11,c2,0               ; Channel Number
                MCR     p15,0,r2,c11,c1,0               ; User Accessibility Reg
no_DMA_rst
    ENDIF

                LDMDB   r1,{r0-r14}                     ; Restore r0-r14 (gp/Mon)

                ; Return from dormant mode entry/exit
                ;MOV     pc,r14
                BLX      r14


  ; END OF DORMANT MODE EXIT CODE

;*******************************************************************************
;*      End of code
;*******************************************************************************

                END
