
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
;*      Checked In          : $Date: 2008-03-07 14:21:27 +0000 (Fri, 07 Mar 2008) $
;*      Revision            : $Revision: 24966 $
;*      Release Information :
;*
;*
;******************************************************************************

  IMPORT enableVirtualMapping
  IMPORT enablePrefetchBuffer

; Important. Don't forget to include this:
		GET	driver\sys_drv\dormant\src\cortexr4_dorm_arch_macros_rvct.hs
;		GET	cortexr4_tcm_macros.hs

; Those are compile time configurable parameters that we need:
        GBLL    ATC_EXE
        GBLL    BTC_EXE
        GBLL    VFP_ENABLE
        GBLL    DORMANT_SW_FIX_500166
ATC_EXE			SETL    {FALSE}         ; executing from ATCM?
BTC_EXE			SETL    {TRUE}          ; executing fron BTCM?
VFP_ENABLE		SETL    {FALSE}         ; VFP is enabled? 
DORMANT_SW_FIX_500166	SETL    {FALSE}         ; Do we nees SW fix?

; Aliases for mode encodings - do not change
MODE_USR        EQU     0x10
MODE_FIQ        EQU     0x11
MODE_IRQ        EQU     0x12
MODE_SVC        EQU     0x13
MODE_ABT        EQU     0x17
MODE_UND        EQU     0x1B
MODE_SYS        EQU     0x1F

; Entry point offsets for key context variable and pointer values

; Maintain correlation with the offset comments/size on reserved space at the
; start of DORMANT_BASE.
DM_SYSCACHE     EQU     0x00
DM_DBG          EQU     0x04
DM_PMU          EQU     0x08
DM_ACTLR        EQU     0x0C
DM_SCTLR        EQU     0x10
DM_SACTLR       EQU     0x14
DM_CPACR        EQU     0x18
DM_AXISLVCR     EQU     0x1C
DM_VFP          EQU     0x20
DM_MPU          EQU     0x24
DM_SC           EQU     0x28
DM_C_OVER	EQU	0x2C
DM_ENDIAN       EQU     0x30
DM_OLD_VECTOR   EQU     0x34
DM_EXTRAS	EQU	0x38
DM_PMU_ST	EQU	0x3C
DM_BLOCK        EQU     0x40



	; DORMANT_SAVE should NOT modify the state of the processor (should be
	; able to be called independently of the DORMANT_RESTORE function.
	; Uses registers and the CPSR.
	; R0 base address to save content of registers other than TCM region
	; R1 base address to save TCM region registers
		MACRO
$label		DORMANT_SAVE

	; Save all Supervisor mode context for nucleus 1.x Or
	; Save all System mode context for nucleus 2.x
		IF __NUCLEUS_VERSION_2__
		CPS	#MODE_SVC         ; switch to Supervisor mode
		ENDIF
	; Account for a block to save some DM_* configurations (fixed offset).
		ADD	r0,r0,#DM_BLOCK
	; save ARM registers (but PC)
		STM	r0!,{r2-r14}
	; preserve a copy of DORMANT_BASE
		SUB	r12,r0, #(DM_BLOCK + 4*13)
		MRS	r4,CPSR
		MRS	r5,SPSR
	; Save endianness.
	; This creates a reg that is 0 when we have l.endian and 0xffffffff
	; for b. endian.This should be checked before restore to restore data
	; correctly.
		SBFX	r7,r4,#9,#1
		STR	r4,[r12,#DM_ENDIAN]
		STM	r0!,{r4-r5}	; save the current CPSR and SPSR
	; Make a dummy STREX to check if memory is locked.
	; If r6=1 it means that the lock was free if r6=0 it means that the
	; lock was held
		STREX	r6,r1,[r1]
	; Save TCM Region Registers (always present in Cortex-R4)
		MRC	p15,0,r4,c9,c1,0  ; BTCM Region Register 
		MRC	p15,0,r5,c9,c1,1  ; ATCM Region Register 
		STM	r1,{r4-r7}        ; save BTCM, ATCM region registers, EXCL and endianess
		STM	r0!,{r1,r6}       ; save EXCL to simplify restore procedure

	; Save banked ARM registers
		CPS	#MODE_SYS         ; switch to System mode
		STR	SP,[r0], #4       ; save the User SP
		STR	LR,[r0], #4       ; save the User LR

		CPS	#MODE_ABT         ; switch to Abort mode
		STR	SP,[r0], #4       ; save the current SP   
		MRS	r4,SPSR 
		STM	r0!,{r4,LR}       ; save the current SPSR, LR
		CPS	#MODE_UND         ; switch to Undefined mode
		STR	SP,[r0], #4       ; save the current SP
		MRS	r4,SPSR 
		STM	r0!,{r4,LR}       ; save the current SPSR, LR
		CPS	#MODE_IRQ         ; switch to IRQ mode
		STR	SP,[r0], #4       ; save the current SP
		MRS	r4,SPSR 
		STM	r0!,{r4,LR}       ; save the current SPSR, LR
		CPS	#MODE_FIQ         ; switch to FIQ mode
		STR	SP,[r0], #4       ; save the current SP
		MRS	r4,SPSR 
		STM	r0!,{r4,r8-r12,LR}; save the current SPSR,r8-r12,LR

		CPS	#MODE_SVC         ; switch to Supervisor mode


	; Save performance monitor registers.
		[ :DEF: DM_PMU
		REG_BARRIER_SAVE
PMUS$label	PMU_SAVE		 ; For profiling transparency save
		]		         ; PMU registers as early as possible

	; Save the Secondary Control Registers
	; IMPLEMENTATION DEFINED - proprietary features: CP15 register 15
	; SACTLR - Secondary Auxiliary Control Register
		MRC	p15,0,r3,c15,c0,0
	; Generic CP15 registers
	; ACTLR - Auxiliary Control Register
 		MRC	p15,0,r4,c1,c0,1
	; SCTLR - System Control Register
 		MRC	p15,0,r5,c1,c0,0
	; CPACR - Coprocessor Access Control Register
 		MRC	p15,0,r6,c1,c0,2
	; AXISLVCR - (AXI) Slave Port Control Register
		MRC	p15,0,r7,c11,c0,0
		STR	r3,[r12, #DM_SACTLR]	; fixed address
 		STR	r4,[r12, #DM_ACTLR]	; fixed address
 		STR	r5,[r12, #DM_SCTLR]	; fixed address
 		STR	r6,[r12, #DM_CPACR]	; fixed address
 		STR	r7,[r12, #DM_AXISLVCR]	; fixed address

	; Format and store the Cache override register.
 		STR	r0,[r12, #DM_C_OVER]	; save at fixed address
		MRC	p15,2,r3,c0,c0,0	; Save Cache Size Selection Reg
	
		MOV	r4,#0
		MCR	p15,2,r4,c0,c0,0	; Select data cache
	; Read the size from Cache Size Identification Register
		MRC	p15,1,r5,c0,c0,0
		LSR	r5,r5,#(13+5-4)
		AND	r2,r5,#0xF0

		MOV	r4,#1
		MCR	p15,2,r4,c0,c0,0	; Select instruction cache
	; Read the size from Cache Size Identification Register
		MRC	p15,1,r5,c0,c0,0
		LSR	r5,r5,#(13+5)
		AND	r5,r5,#0x0F
		ORR	r2,r2,r5
	
		STM	r0!,{r2-r3}

	; Set the cache size override register
		LDR	r0,[r12,#DM_C_OVER] ; Cache override
		LDM	r0!,{r2-r3}
		MCR	p15,2,r3,c0,c0,0    ; Restore Cache Size Selection Reg

	; Store TCM regions and Software and thread context
		STR	r0,[r12, #DM_SC]  ; save at fixed address 
		;	Save the software context and thread support registers
		MRC	p15,0,r4,c13,c0,1  ; CONTEXTIDR 
		MRC	p15,0,r5,c13,c0,2  ; TPIDRURW 
		MRC	p15,0,r6,c13,c0,3  ; TPIDRURO 
		MRC	p15,0,r7,c13,c0,4  ; TPIDRPRW
		STM	r0!,{r4-r7}
	
	; Extras
		STR	r0,[r12, #DM_EXTRAS]  ; save at fixed address 
		MRC	p15,0,r3,c15,c3,0 ; The ECC fault location register
		MRC	p15,0,r4,c15,c1,0 ; Validation registers (nVal) 0..7
		MRC	p15,0,r5,c15,c1,1
		MRC	p15,0,r6,c15,c1,2
		MRC	p15,0,r7,c15,c1,3
		STM	r0!, {r3-r7}


	; Save MPU configuration
		[ :DEF: DM_MPU
		REG_BARRIER_SAVE
MPUS$label	MPU_SAVE
		]
	
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; DEBUG: ARMv7 OS Lock support
;        ;;; OMITTED FOR CORTEX-R4 ;;;
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

		[ :DEF: DM_DBG
DBGS$label	; Substitute the next two lines with the DBG_SAVE macro if ARMv7 debug
		; (OS lock) is supported in dormant mode
		EORS	r1, r1             ; clear r1
		STR	r1,[r12,#DM_DBG]   ; clear debug context pointer
		]			   ; (indicates nothing saved)

		; FPU state save
		[ :DEF: DM_VFP
		[ VFP_ENABLE
		REG_BARRIER_SAVE
VFPS$label	VFP_SAVE
		|
		EORS	r2, r2             ; clear r2
		STR	r2,[r12,#DM_VFP]   ; clear VFP context pointer (indicates nothing saved)
		]
		]

	; Restore the exclusiveness (DORMANT_SAVE has to be transparent)
		ADD	r1,r12,#DM_BLOCK
		LDR	r1,[r1, #8]
		CMP	r1,#0
		LDREXEQ	r1,[r12]

	; R0 will have the number of bytes written
		SUB	r0,r0,r12

		MEND

;------------------------------------------------------------------------------
; Macro:	DORMANT_RESTORE
;
; Function:	Restores the values stored with the macro DORMANT_SAVE
		MACRO
$label		DORMANT_RESTORE	$clear
	; R12 is base address for dormant context stored in TCM.
	; R1 is base address for dormant context stored in EMI.
	; Restore endianess because after reset it could be BE or LE node
	; according to the pin configuration.
		LDR	r4,[r1,#12]        ; restore endian setting
		CMP	r4,#0
		BNE	$label.set_be
		SETEND	LE
		B	$label.setend_end
$label.set_be
		SETEND	BE
$label.setend_end
	; Restore TCM Region Registers (always present in Cortex-R4)
		LDM	r1!,{r5-r6}        ; recover TCM context 
		MCR	p15,0,r5,c9,c1,0   ; BTCM Region Register 
		MCR	p15,0,r6,c9,c1,1   ; ATCM Region Register
	; Now, we can use TCM.
		MOV	r12, r0

	; Software fix for the hardware L1 cache issue (500166).
		[ DORMANT_SW_FIX_500166
		R1P2_FIX_500166
		]
	
	; Restore the TCM error correction scheme
		DSB			   ; force completion of outstanding accesses
		MRC	p15,0,r1,c1,c0,1   ; Read Aux Ctl reg. 1
		BIC	r2,r1,#0x7<<25     ; Clear the TCM error correction bits
		LDR	r3,[r12,#DM_ACTLR] ; Load the restored value
		AND	r4,r3,#0x7<<25     ; Keep only the TCM error correction bits
		ORR	r2,r2,r4           ; Merge the two configurations
		MCR	p15,0,r2,c1,c0,1   ; Set the TCM error correction bits on Aux. Ctl reg.1

		MRC	p15,0,r2,c15,c0,0
		LDR	r3,[r12,#DM_SACTLR] ; recover SACTLR 64-bit and E-corr. disables.
		BIC	r2,#0x0f
		AND	r3,#0x0f
		ORR	r2,r2,r3
		MCR	p15,0,r2,c15,c0,0
	
		ISB

		LDR	r0,[r12,#DM_SC] ;Load the TCM saved context pointer
	; Restore the software context and thread support registers
		LDM	r0!,{r4-r7}
		MCR	p15,0,r4,c13,c0,1  ; CONTEXTIDR
		MCR	p15,0,r5,c13,c0,2  ; TPIDRURW
		MCR	p15,0,r6,c13,c0,3  ; TPIDRURO
		MCR	p15,0,r7,c13,c0,4  ; TPIDRPRW
	; Apply all the updates to the CP15 registers.
		ISB

	; Restore MPU configuration
		[ :DEF: DM_MPU
		REG_BARRIER_RESTORE
MPUR$label	MPU_RESTORE
		]

	; Set the cache size override register
		LDR	r0,[r12,#DM_C_OVER] ; Cache override
		LDM	r0!,{r2-r3}
		MCR	p15,0,r2,c15,c14,0  ; Restore Cache Size Override Reg
		MCR	p15,2,r3,c0,c0,0    ; Restore Cache Size Selection Reg
	
	; Enable the MPU if it was enabled before dormant.
		LDR	r2,[r12,#DM_SCTLR] ; Load SCTLR
                AND	r3,r2,#1           ; Keep only the MPU Enable bit
                MRC     p15,0,r4,c1,c0,0
		ORR	r4,r3
                DMB
                MCR     p15,0,r4,c1,c0,0
		ISB

	; Enable cache error correction before enabling caches.
		MRC	p15,0,r1,c1,c0,1   ; Read Aux Ctl reg. 1
		BIC	r2,r1,#7<<3        ; Clear the CEC bits
		LDR	r3,[r12,#DM_ACTLR] ; Load the restored value
		AND	r4,r3,#7<<3        ; Keep only the CEC bits
		ORR	r2,r2,r4           ; Merge the two configurations
		MCR	p15,0,r2,c1,c0,1   ; Set the CEC bits on Aux. Ctl reg.1
		ISB

	; - and is it critical where they are in the restore sequence?   
	; restore ACTLR and SCTLR, enables caches and MPU if their control
	; bits are set restore SACTLR & AXISLVCR enables ECC, FP and AXI slave
	; access features
	
		LDR	r3,[r12,#DM_SACTLR] ; recover SACTLR from fixed address
		LDR	r4,[r12,#DM_ACTLR]  ; recover ACTLR from fixed address
		LDR	r5,[r12,#DM_SCTLR]  ; recover SCTLR from fixed address
	; recover AXISLVCR from fixed address
		LDR	r7,[r12,#DM_AXISLVCR]
	; AXISLVCR - (AXI) Slave Port Control Register
		MCR	p15,0,r7,c11,c0,0
	; SACTLR - Secondary Auxiliary Control Register
 		BIC	r3,r3,#1<<21       ; Clear the err.inject. flag
		MCR	p15,0,r3,c15,c0,0
	; ACTLR - Auxiliary Control Register
		BIC	r4,r4,#1<<12	   ; Clear cache error injection
		MCR	p15,0,r4,c1,c0,1
		ISB
	; SCTLR - System Control Register
		BIC	r5,r5,#0x1000      ; Don't enable caches yet because
		BIC	r5,r5,#0x4         ; you want to finalize their conf
		MCR	p15,0,r5,c1,c0,0   ; iguration before enabling e.g
		ISB		           ; round-robin

	; Enable L1 caches if they were enabled before dormant.
		LDR	r2,[r12,#DM_SCTLR] ; Load SCTLR
		AND	r3,r2,#0x1000      ; I cache first
		MRC     p15,0,r4,c1,c0,0
		ORR	r4,r3
		DMB
		MCR	p15,0,r4,c1,c0,0
		ISB
		AND	r3,r2,#0x4         ; Then D/U cache
                MRC     p15,0,r4,c1,c0,0
		ORR	r4,r3
		DMB
		MCR	p15,0,r4,c1,c0,0
		ISB

	; Enable error injectors if they were enabled before.
		LDR	r3,[r12,#DM_SACTLR] ; recover SACTLR from fixed address
		LDR	r4,[r12,#DM_ACTLR]  ; recover ACTLR from fixed address
		MCR	p15,0,r3,c15,c0,0
		MCR	p15,0,r4,c1,c0,1
		ISB

	; SET_EXCEPTION shouldn't do any cache maintenance operations
	; Cache maintenance OPS on dormand code might cause imprecise
	; that aren't dormand's responsibility to handle e.g. cleaning
	; cache lines with tags with parity errors cause imp. aborts.
		SET_EXCEPTION	RESET,r0,r4,"NO_CLEAN","SKIP"

	;     Restore VFP
		[ :DEF: DM_VFP
		[ VFP_ENABLE
		REG_BARRIER_RESTORE
VFPR$label	VFP_RESTORE
		]
		]

	;	Restore banked ARM registers
		ADD	R0,R12,#(DM_BLOCK+4*17) ; update context block pointer
		CPS	#MODE_SYS               ; switch to System mode 
		LDR	SP,[r0],#4              ; restore the User SP 
		LDR	LR,[r0],#4              ; restore the User LR

		CPS	#MODE_ABT               ; switch to Abort mode 
		LDR	SP,[r0],#4              ; restore the current SP    
		LDM	r0!,{r4,LR}             ; restore the current LR 
		MSR	SPSR_fsxc,r4            ; restore the current SPSR
		CPS	#MODE_UND               ; switch to Undefined mode 
		LDR	SP,[r0],#4              ; restore the current SP    
		LDM	r0!,{r4,LR}             ; restore the current LR 
		MSR	SPSR_fsxc,r4            ; restore the current SPSR
		CPS	#MODE_IRQ               ; switch to IRQ mode 
		LDR	SP,[r0],#4              ; restore the current SP    
		LDM	r0!,{r4,LR}             ; restore the current LR 
		MSR	SPSR_fsxc,r4            ; restore the current SPSR
		CPS	#MODE_FIQ               ; switch to FIQ mode 
		LDR	SP,[r0],#4              ; restore the current SP    
		LDM	r0!,{r4,r8-r12,LR}      ; restore the current r8-r12,LR
		MSR	SPSR_fsxc,r4            ; restore the current SPSR

		CPS	#MODE_SVC               ; Switch to Supervisor mode

	; Restore CPACR. This must be done after configuring FPU
		LDR	r6,[r12,#DM_CPACR]
		MCR	p15,0,r6,c1,c0,2

	;	Restore performance counters
		[ :DEF: DM_PMU
		REG_BARRIER_RESTORE
PMUR$label	PMU_RESTORE		 ; For profiling transparency restore
		]		         ; PMU registers as late as possible

	; Restore extras (this should be after PMU that clears validation regs)
		LDR	r0,[r12,#DM_EXTRAS]   ; load extras saved context pointer
		LDM	r0!,{r3-r7}
		MCR	p15,0,r3,c15,c3,0 ; The ECC fault location register
		MCR	p15,0,r4,c15,c1,0 ; Validation registers (nVal) 0..7
		MCR	p15,0,r5,c15,c1,1
		MCR	p15,0,r6,c15,c1,2
		MCR	p15,0,r7,c15,c1,3
		ISB

	; Restore MTK HW platform setting
		DSB
		BLX	enableVirtualMapping
		BLX	enablePrefetchBuffer

	; Restore Supervisor mode context for nucleus 1.x Or
	; Restore System mode context for nucleus 2.x
	; initial restore of r0, DORMANT_BASE pointer
		ADD	r0,r12,#(DM_BLOCK+4*13)
		LDM	r0,{r1-r4}	  ; recover CPSR,SPSR & exclusive
		CMP	r4,#0
		LDREXEQ	r4,[r3]
		MSR	CPSR_fsxc,r1	  ; restore the CPSR
		MSR	SPSR_fsxc,r2	  ; restore the SPSR
		ADD	r0,r12,#DM_BLOCK
		LDM	r0,{r2-r14}	  ; restore ARM registers (but r0, r1, and PC)

		IF __NUCLEUS_VERSION_2__
		CPS	#MODE_SYS               ; switch back to System mode 
		ENDIF

		MEND


;------------------------------------------------------------------------------
; Macro:	R1P2_FIX_500166
;
; Function:	Software fix for the hardware L1 cache issue 500166.
; Assumes:	r12 has the DORMANT_BASE. Uses:	 r0,r1,r2.
; NOTE:	        TCMs are max 8Mb long and we would like to guarantee that
;               we hit WB (thus non-tcm) region so we do the trick in address,
;               address+8Mb and address+16Mb (to cover 2 tcms).
		MACRO
		R1P2_FIX_500166
		LDR	r0,[r12,#DM_C_OVER] ; Cache override
		LDR	r2,[r0]
		MCR	p15,0,r2,c15,c14,0  ; Restore Cache Size Override Reg
		DSB
		
	; a) Data cache and MPU already disabled so we clean and invalidate
		MOV32	r1,#0x01400000 ; Use address at 20Mb.
		MCR	p15,0,r1,c7,c14,1
		DSB

	; b) Enable data cache and DMB
		MRC	p15,0,r0,c1,c0,0
		ORR	r0,r0,#0x00000004
		MCR	p15,0,r0,c1,c0,0
		DSB

	; c) Load from address in r1 and DMB
		LDR	r0,[r1]
		DSB	; Here we should see the lfbs_need_ev_reg signal asserted

	; d) Disable data cache and DMB
		MRC	p15,0,r0,c1,c0,0
		BIC	r0,r0,#0x00000004
		MCR	p15,0,r0,c1,c0,0
		DSB

	; d) Invalidate line after the load.
		MCR	p15,0,r1,c7,c6,1
		DSB
		MEND

;------------------------------------------------------------------------------
; Macro:	[label] TCM_error_disable
;
; Function:	r1 should be 1 to disable the etm errors or 0 to re-enable them
;		Uses as temporaries r2, r3, r4, r5, r6
		MACRO
$label		TCM_error_disable

		AND	r1,#1

		MRC	p15,0,r2,c15,c2,1		; Read Build Opts Reg2
		UBFX	r2,r2,#13,#1			; extract bit[13] ATCM
		CMP	r2,#1
		BEQ	$label.ATCM_error_exit          ; No ATCM -> skip

        ; Step 1 : Enable ATCM validation wrapper 

	; Step 2 : Program ATCM Wrapper control registers. If the ATCM
	; is used as a fetch memory, the base address of the ATCM should
	; not be changed. Otherwise the ATCM is set-up at the address
	; location 0x6000000.
		ENABLE_ITCM_CTL r3,r4
		MRC	p15,0,r6,c9,c1,1		; save state in r6 
		[  ATC_EXE
		MOV	r2,r6				; keep base address 
		BIC	r2,r2,#0xff
		BIC	r2,r2,#0xf<<8			; r2 <- ATCM base
		MOV	r5,r2
		|
		MOV	r2,#0x6000000			; ATCM base address	
		MOV	r5,r2				
		]
		ORR	r5,r5,#1			; enable ATCM
		MCR	p15,0,r5,c9,c1,1
		LDR	r5,[r2,#0x610]                  ; write to wrapper ctl reg 3
		BIC	r5,r5,#(1<<30)
		ORR	r5,r5,r1,LSL #30
		STR	r5,[r2,#0x610]                  ; write to wrapper ctl reg 3
		DSB
		MCR	p15,0,r6,c9,c1,1		; restore ATCM region reg
		DISABLE_ITCM_CTL r3,r4

$label.ATCM_error_exit

		MRC	p15,0,r2,c15,c2,1		; Read Build Opts Reg2
		UBFX	r2,r2,#11,#2			; extract bits[12:11]
		CMP	r2,#3
		BEQ	$label.BTCM_error_exit         ; No BTCMs -> skip
	
	; Step 2 : Program B0TCM and B1TCM Wrapper control registers.
        ; If the BTCM is used as a fetch memory, the base address of 
        ; the BTCM should not be changed. Otherwise the BTCM is set-up 
        ; at the address location 0x6000000.
		ENABLE_DTCM_CTL r3,r4
		MRC	p15,0,r6,c9,c1,0		; save state in r6  
		[  BTC_EXE
		MOV	r2,r6				; keep base address 
		BIC     r2,r2,#0xff
		BIC     r2,r2,#0xf<<8			; r2 <- BTCM base
		MOV	r5,r2
		|
		MOV	r2,#0x6000000			; BTCM base address	
		MOV	r5,r2
		]
		ORR	r5,r5,#1			; enable BTCM 
		MCR	p15,0,r5,c9,c1,0
		LDR	r5,[r2,#0x610]                  ; write to wrapper ctl reg 3
		BIC	r5,r5,#(1<<30)
		ORR	r5,r5,r1,LSL #30
		STR	r5,[r2,#0x610]                  ; write to wrapper ctl reg 3
		DSB
		MCR	p15,0,r6,c9,c1,0		; restore BTCM region reg
		DISABLE_DTCM_CTL r3,r4

$label.BTCM_error_exit
	; Step 3 : Disable ITCM wrapper and enable DTCM wrapper
		MEND