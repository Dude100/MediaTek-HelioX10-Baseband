; -*- asm -*-
;******************************************************************************
;*
;* The confidential and proprietary information contained in this file may
;* only be used by a person authorised under and to the extent permitted
;* by a subsisting licensing agreement from ARM Limited.
;*
;*                 (C) COPYRIGHT 2007-2008 ARM Limited.
;*                       ALL RIGHTS RESERVED
;*
;* This entire notice must be reproduced on all copies of this file
;* and copies of this file may only be made by a person if such person is
;* permitted to do so under the terms of a subsisting license agreement
;* from ARM Limited.
;*
;*               Dormant handling code 
;*              ======================
;*
;*      Origin: cortexr4_generic
;*      SVN Information
;*      Checked In          : $Date: 2008-03-14 13:47:27 +0000 (Fri, 14 Mar 2008) $
;*      Revision            : $Revision: 25059 $
;*      Release Information :
;*
;*
;******************************************************************************

;******************************************************************************
;* Dormant PMU_SAVE MACRO
;******************************************************************************


		MACRO
$label		PMU_SAVE
	; Save a pointer to the start of the PMU context offset
		STR	r0,[r12,#DM_PMU] ; save at fixed address 
	; Save Performance Monitor Registers - PMU. 
	; :ASSUMPTION: These should be saved as early as possible to make them
	; 'transparent' to power mangement overheads
	; Ignore:
	;        Count Enable Clear Register
	;        Software Increment Register
	;        Interrupt Enable Clear Register
		MRC	p15,0,r8,c9,c12,0  ; PMU: Control Register
		BIC	r1,r8,#1
		MCR	p15,0,r1,c9,c12,0  ; disable counter updates from here
		ISB                        ; 0b0 => PMCR<0>
		MRC	p15,0,r9,c9,c12,3  ; PMU: Overflow Flag Status Reg
		MRC	p15,0,r10,c9,c12,5 ; PMU: Event Counter Selection Reg
		STM	r0!,{r8-r10}

		UBFX	r9,r8,#11,#5        ; extract # of event counters, N
		TST	r9,r9
		BEQ	$label.continue
$label.loop	
		SUBS	r9,r9,#1            ; decrement N
		MCR	p15,0,r9,c9,c12,5   ; PMU: select CounterN
		ISB
		MRC	p15,0,r3,c9,c13,1   ; PMU: save Event Type register
		MRC	p15,0,r4,c9,c13,2   ; PMU: save Event Counter register
		STM	r0!,{r3,r4}
		BNE	$label.loop
$label.continue
		MRC	p15,0,r1,c9,c13,0   ; PMU: Cycle Count Register
		MRC	p15,0,r2,c9,c14,0   ; PMU: User Enable Register
		MRC	p15,0,r3,c9,c14,1   ; PMU: Interrupt Enable Set Register
		MRC	p15,0,r4,c9,c12,1   ; PMU: Count Enable Set Register
	
		STM	r0!,{r1-r4}

	; Restore the original value of the Selection Register
		MCR	p15,0,r10,c9,c12,5 ; Maintain Selection Reg
		MCR	p15,0,r8,c9,c12,0 ; Maintain control Register
	
		MEND

;******************************************************************************
;* Dormant PMU_RESTORE
;******************************************************************************
	
		MACRO
$label		PMU_RESTORE
	; NOTE: all counters disabled by PMCR<0> == 0 on reset
	;       Restore performance counters
		LDR	r0,[r12,#DM_PMU]   ; load the PMU saved context pointer
		LDM	r0!,{r8-r10}       ; recover first block of PMU context
					   ; (PMCR, PMOVSR, PMSELR)
		MOV	r1,#0              ; generate register of all 0's
		MVN	r2,#0              ; generate register of all 1's
		MCR	p15,0,r2,c9,c14,2  ; disable all counter related interrupts
		MCR	p15,0,r2,c9,c12,3  ; clear all overflow flags
		MCR	p15,0,r2,c15,c1,4  ; clear validation registers
		MCR	p15,0,r2,c15,c1,5
		MCR	p15,0,r2,c15,c1,6
		MCR	p15,0,r2,c15,c1,7
		ISB
	
		UBFX	r11,r8,#11,#5      ; extract # of event counters, N (0-31)
		TST	r11,r11
		BEQ	$label.continue
		MOV	r3,r11             ; for N >0, generate a 2nd copy of N
		MOV	r4,#1
		LSL	r4,r3
		SUB	r4,r4,#1           ; set bits<N-1:0> to all 1's   
$label.loop1
		SUBS	r3,r3,#1           ; decrement N
		MCR	p15,0,r3,c9,c12,5  ; select Event CounterN
		ISB
		MRC	p15,0,r5,c9,c13,1   ; read Event Type register
		BFC	r5,#0,#8
		MCR	p15,0,r5,c9,c13,1   ; set Event Type to 0x0
		MCR	p15,0,r2,c9,c13,2   ; set Event Counter to all 1's
		ISB
		BNE	$label.loop1
	
		MOV	r3,#1
		MCR	p15,0,r4,c9,c12,1   ; enable Event Counters
		MCR	p15,0,r3,c9,c12,0   ; set the PMCR global enable bit
		ISB
		MCR	p15,0,r9,c9,c12,4   ; set event count overflow bits
		ISB
		MCR	p15,0,r4,c9,c12,2   ; disable Event Counters
	
	; restore the event counters
$label.loop2
		SUBS	r11,r11,#1          ; decrement N
		MCR	p15,0,r11,c9,c12,5  ; select Event CounterN
		ISB
		LDM	r0!,{r3-r4}
		MCR	p15,0,r3,c9,c13,1   ; restore Event Type
		MCR	p15,0,r4,c9,c13,2   ; restore Event Counter
		ISB
		BNE	$label.loop2
$label.continue
		TST	r9,#0x80000000      ; check for cycle count overflow flag
		BEQ	$label.continue2
		MCR	p15,0,r2,c9,c13,0   ; set Cycle Counter to all 1's
		ISB
		MOV	r3,#0x80000000
		MCR	p15,0,r3,c9,c12,1   ; enable the Cycle Counter
		ISB
$label.loop3
		MRC	p15,0,r4,c9,c12,3   ; check cycle count overflow now set
		MOVS	r4,r4               ; test bit<31>
		BPL	$label.loop3
		MCR	p15,0,r3,c9,c12,2   ; disable the Cycle Counter
$label.continue2
	
		MCR	p15,0,r1,c9,c12,0   ; clear the PMCR global enable bit
		ISB
	
	; restore the remaining PMU registers
		LDM	r0!,{r1-r4}
		MCR	p15,0,r1,c9,c13,0   ; restore Cycle Count Register
		MCR	p15,0,r2,c9,c14,0   ; restore User Enable Register
		MCR	p15,0,r3,c9,c14,1   ; restore Interrupt Enable Set Register
		MCR	p15,0,r4,c9,c12,1   ; restore Count Enable Set Register
	
		MCR	p15,0,r10,c9,c12,5  ; restore Event Counter Selection
		ISB
		MCR	p15,0,r8,c9,c12,0   ; restore the PM Control Register
		ISB
	
		MEND

;******************************************************************************
;* Dormant PMU_DORMANT_DISABLE
;* Modifies r1. R0 should have Dormant Base address.
;******************************************************************************
	
		MACRO
		PMU_DORMANT_DISABLE
		MRC	p15,0,r1,c9,c12,0   ; PMU: save the Control Register
		STR	r1,[r0,#DM_PMU_ST]
		BIC	r1,#1	            ; Stop counting
		MCR	p15,0,r1,c9,c12,0   ; PMU: save the Control Register
		ISB
		MEND
	
;******************************************************************************
;* Dormant PMU_DORMANT_RESTORE
;* Modifies r0. R0 should have Dormant Base address.
;******************************************************************************
	
		MACRO
		PMU_DORMANT_RESTORE
		LDR	r0,[r0,#DM_PMU_ST]  ; load the PMU saved context pointer
		MCR	p15,0,r0,c9,c12,0   ; PMU: restore the Control Register
		ISB
		MEND
	
;******************************************************************************
;* Dormant MPU_SAVE MACRO
;******************************************************************************

		MACRO
$label		MPU_SAVE
		STR	r0,[r12, #DM_MPU] ; save at fixed address

	; fault address and status information
		MRC	p15,0,r2,c5,c0,0   ; DFSR
		MRC	p15,0,r3,c5,c0,1   ; IFSR
		MRC	p15,0,r4,c5,c1,0   ; ADFSR
		MRC	p15,0,r5,c5,c1,1   ; AIFSR
		MRC	p15,0,r6,c6,c0,0   ; DFAR
		MRC	p15,0,r7,c6,c0,2   ; IFAR
		STM	r0!,{r2-r7}        ; save fault status & address context

		MRC	p15,0,r7,c6,c2,0  ; read RGNR and store it to r7
		STR	r7,[r0], #4      ; save the RGNR

		MRC	p15,0,r1,c0,c0,4  ; read the MPU type register
		EOR	r2,r2		; clear r2
	; determine if unified or Harvard region support
		ANDS	r3,r1,#1
		IT	NE
		UBFXNE	r2,r1,#16,#8	; if Harvard,extract I.region field->r2
		UBFX	r1,r1,#8,#8	; extract U/D region field to r1

		; Save unified/data region context
		CMP	r1,#0              ; test for case of no MPU fitted 
		BEQ	$label.SaveIregionContext

		EOR	r3,r3              ; clear r3
$label.SaveDregionContextLoop
		MCR	p15,0,r3,c6,c2,0   ; write the RGNR 
		ISB
		MRC	p15,0,r4,c6,c1,0   ; read DRBAR
		MRC	p15,0,r5,c6,c1,2   ; read DRSR
		MRC	p15,0,r6,c6,c1,4   ; read DRACR
		STM	r0!, {r4-r6}       ; save Dregion context
		ADDS	r3,r3,#1 
		CMP	r1,r3 
		BNE	$label.SaveDregionContextLoop

$label.SaveIregionContext
	; test for case of unified regions or no MPU fitted 
		CMP	r2,#0
		BEQ	$label.ContinuePwrDwnSave

		EOR	r3,r3              ; clear r3
$label.SaveIregionContextLoop
		MCR	p15,0,r3,c6,c2,0   ; write the RGNR 
		ISB	
		MRC	p15,0,r4,c6,c1,1   ; read IRBAR 
		MRC	p15,0,r5,c6,c1,3   ; read IRSR 
		MRC	p15,0,r6,c6,c1,5   ; read IRACR 
		STM	r0!,{r4-r6}        ; save Iregion context
		ADDS	r3,r3, #1 
		CMP	r2,r3 
		BNE	$label.SaveIregionContextLoop

$label.ContinuePwrDwnSave
		MCR	p15,0,r7,c6,c2,0  ; Restore RGNR
	
		MEND


;******************************************************************************
;* Dormant MPU_RESTORE MACRO
;******************************************************************************

		MACRO
$label		MPU_RESTORE
		LDR	R0,[R12,#DM_MPU] ; Restore MPU configuration region

	; Fault status & address context
		LDM	r0!,{r2-r7}        ; Restore fault status & address context
		MCR	p15,0,r2,c5,c0,0   ; DFSR
		MCR	p15,0,r3,c5,c0,1   ; IFSR
		MCR	p15,0,r4,c5,c1,0   ; ADFSR
		MCR	p15,0,r5,c5,c1,1   ; AIFSR
		MCR	p15,0,r6,c6,c0,0   ; DFAR
		MCR	p15,0,r7,c6,c0,2   ; IFAR
		ISB
	
	; recover RGNR to r7. It will be restored later
		LDR	r7,[r0],#4

		MRC	p15,0,r1,c0,c0,4 ; read the MPU type register 
		EORS	r2,r2            ; initialise r2 to 0
	; determine if unified or Harvard region support 
		ANDS	r3,r1,#1
		IT	NE 
		UBFXNE	r2,r1,#16,#8     ;if Harvard,extract I region field->r2
		UBFX	r1,r1,#8,#8      ; extract U/D region field to r1

	; Restore unified/data region context
		CMP	r1,#0            ; test for case of no MPU fitted 
		BEQ	$label.RestoreIregionContext

		EORS	r3,r3            ; clear r3
$label.RestoreDregionContextLoop
		LDM	r0!,{r4-r6}      ; recover Dregion context 
		MCR	p15,0,r3,c6,c2,0 ; write the RGNR 
		ISB
		MCR	p15,0,r4,c6,c1,0 ; restore DRBAR 
		MCR	p15,0,r5,c6,c1,2 ; restore DRSR 
		MCR	p15,0,r6,c6,c1,4 ; restore DRACR 
		ADDS	r3,r3,#1 
		CMP	r1,r3 
		BNE	$label.RestoreDregionContextLoop
			
$label.RestoreIregionContext
	; test for case of unified regions or no MPU fitted 
		CMP	r2, #0
		BEQ	$label.ContinuePwrDwnRestore

		EORS	r3,r3              ; clear r3
$label.RestoreIregionContextLoop
		LDM	r0!,{r4-r6}        ; recover Iregion context
		MCR	p15,0,r3,c6,c2,0   ; write the RGNR 
		ISB	
		MCR	p15,0,r4,c6,c1,1   ; restore IRBAR 
		MCR	p15,0,r5,c6,c1,3   ; restore IRSR 
		MCR	p15,0,r6,c6,c1,5   ; restore IRACR 
		ADDS	r3,r3,#1 
		CMP	r2,r3 
		BNE	$label.RestoreIregionContextLoop
			
$label.ContinuePwrDwnRestore
		MCR	p15,0,r7,c6,c2,0   ; restore RGNR from R7
	
		MEND
	
;******************************************************************************
;* Dormant VFP_SAVE MACRO
;******************************************************************************

		MACRO
$label		VFP_SAVE
	[ VFP_ENABLE
	; Save a pointer to the start of the VFP context offset 
		STR	r0,[r12,#DM_VFP]   ; save at fixed address
	
	; FPU state save/restore.
	; FPSID,MVFR0 and MVFR1 don't get serialized (Read Only).
		MRC	p15,0,r10,c1,c0,2    ; CPACR:allow CP10 and CP11 access
		ORR	r2,r10,#0xF00000       
		MCR	p15,0,r2,c1,c0,2
		ISB
		MRC	p15,0,r2,c1,c0,2
		AND	r2,r2,#0xF00000
		CMP	r2,#0xF00000
		BEQ	$label.do_fpu_save
		EORS	r2,r2
	; Override to 0 to indicate that no FPU is present
		STR	r2,[r12,#DM_VFP]
		B	$label.exit_fpu_save
		
$label.do_fpu_save
	;	Save configuration registers and enable.
		VMRS	r11,FPEXC
		STR	r11,[r0],#4
	; Enable FPU access to save/restore the rest of registers.
		LDR	r2,=0x40000000
		VMSR	FPEXC,r2
		VMRS	r2,FPSCR           ; Store FPSCR
		STR	r2,[r0],#4
	; Store the VFP registers.
		VMOV	r2,r3,D0
		VMOV	r4,r5,D1
		VMOV	r6,r7,D2
		VMOV	r8,r9,D3
		STM	r0!,{r2-r9}
		VMOV	r2,r3,D4
		VMOV	r4,r5,D5
		VMOV	r6,r7,D6
		VMOV	r8,r9,D7
		STM	r0!,{r2-r9}
		VMOV	r2,r3,D8
		VMOV	r4,r5,D9
		VMOV	r6,r7,D10
		VMOV	r8,r9,D11
		STM	r0!,{r2-r9}
		VMOV	r2,r3,D12
		VMOV	r4,r5,D13
		VMOV	r6,r7,D14
		VMOV	r8,r9,D15
		STM	r0!,{r2-r9}
	; Don't change the order of this and the following instruction.
		VMSR	FPEXC,r11         ; Restore the original En bit of FPU.
$label.exit_fpu_save
		MCR	p15,0,r10,c1,c0,2 ; Restore the original CPACR value.
	] ; end of VFP_ENABLE
		MEND

;******************************************************************************
;* Dormant VFP_RESTORE
;******************************************************************************

		MACRO
$label		VFP_RESTORE
	[ VFP_ENABLE
	; load the VFP saved context pointer
		LDR	r0,[r12,#DM_VFP]
		CMP	r0,#0
		BEQ	$label.exit_fpu_restore
		
	; FPU state save/restore. Obviously FPSID,MVFR0 and MVFR1 don't get
	; serialized (RO).
	; Modify CPACR to allow CP10 and CP11 access
		MRC	p15,0,r2,c1,c0,2
		ORR	r2,r2,#0x00F00000       
		MCR	p15,0,r2,c1,c0,2
	; Enable FPU access to save/restore the rest of registers.
		LDR	r2,=0x40000000
		VMSR	FPEXC,r2
	; Restore FPEXC and FPSCR. These will be restored later.	
		LDM	r0!,{r13,r14}
	; Store all the VFP registers.
		LDM	r0!,{r2-r9}
		VMOV	D0,r2,r3
		VMOV	D1,r4,r5
		VMOV	D2,r6,r7
		VMOV	D3,r8,r9
		LDM	r0!,{r2-r9}
		VMOV	D4,r2,r3
		VMOV	D5,r4,r5
		VMOV	D6,r6,r7
		VMOV	D7,r8,r9
		LDM	r0!,{r2-r9}
		VMOV	D8,r2,r3
		VMOV	D9,r4,r5
		VMOV	D10,r6,r7
		VMOV	D11,r8,r9
		LDM	r0!,{r2-r9}
		VMOV	D12,r2,r3
		VMOV	D13,r4,r5
		VMOV	D14,r6,r7
		VMOV	D15,r8,r9
	; Restore configuration registers and enable.
	; Restore FPSCR.This should be done FPEXC since FPEXC could disable FPU
	; and make setting FPSCR unpredictable.
		VMSR	   FPSCR,r14	
		VMSR	   FPEXC,r13	; Restore FPEXC
	; Don't restore CPACR (c1,c0,2). It will get restored later.
		
$label.exit_fpu_restore
	] ; end of VFP_ENABLE
		MEND

;******************************************************************************
;* REG_BARRIER clears registers to make sure that macro doesn't rely on them
;******************************************************************************

		MACRO
		REG_BARRIER $dir
		[ :LNOT::DEF: SKIP_REG_BARRIER
		[ "$dir" = "RESTORE"
		MOV	r0,#0
		]
		MOV	r1,#0
		MOV	r2,#0
		MOV	r3,#0
		MOV	r4,#0
		MOV	r5,#0
		MOV	r6,#0
		MOV	r7,#0
		MOV	r8,#0
		MOV	r9,#0
		MOV	r10,#0
		MOV	r11,#0
		]
		MEND
	
		MACRO
		REG_BARRIER_SAVE
		REG_BARRIER SAVE
		MEND

		MACRO
		REG_BARRIER_RESTORE
		REG_BARRIER RESTORE
		MEND

; Kirk
; Following macros are used to make compile pass
; Need to check with aRM whether these codes are necessary

		MACRO
		DISABLE_ITCM_CTL $param1, $param2
		MEND

		MACRO
		ENABLE_ITCM_CTL $param1, $param2
		MEND

		MACRO
		DISABLE_DTCM_CTL $param1, $param2
		MEND

		MACRO
		ENABLE_DTCM_CTL $param1, $param2
		MEND

		MACRO
		SET_EXCEPTION $param1, $param2, $param3, $param4, $param5
		MEND


