/******************************************************************************
#*
#* The confidential and proprietary information contained in this file may
#* only be used by a person authorised under and to the extent permitted
#* by a subsisting licensing agreement from ARM Limited.
#*
#*                 (C) COPYRIGHT 2007-2008 ARM Limited.
#*                       ALL RIGHTS RESERVED
#*
#* This entire notice must be reproduced on all copies of this file
#* and copies of this file may only be made by a person if such person is
#* permitted to do so under the terms of a subsisting license agreement
#* from ARM Limited.
#*
#*               Dormant handling code 
#*              ======================
#*
#*      Origin: cortexr4_generic
#*      SVN Information
#*      Checked In          : $Date: 2008-03-11 14:56:14 +0000 (Tue, 11 Mar 2008) $
#*      Revision            : $Revision: 25009 $
#*      Release Information :
#*
#*
#******************************************************************************/
/* Important. Don't forget to include: */
#include "cortexr4_dorm_macros_gcc.hs"
/* To get 3G RTR time, turn-on this option definition in dormant_service.c and cortexr4-dormantMode_gcc.S */
/*#define MODEM_3G_RTR_TIME_CHECK 1*/

				.text
                .arm
				.align 2
/*******************************************************************************
*      Configuration and constants
*******************************************************************************/

  .extern dormant_tcm_storage
  .extern dormant_mode_storage
  .extern dormant_reset_frc
  .extern dormant_standby_frc
  .extern dormant_abort_frc
  .extern dormant_reset_count
  .extern dormant_abort_count

  .extern dormant_status_reg
  .extern dormant_power_ack_mask
  .extern dormant_frc_val
  .extern dormant_remapping_val
  .extern dormant_mode_stack

  .extern disableVirtualMapping
  .extern enableVirtualMapping
  .extern disablePrefetchBuffer
  .extern enablePrefetchBuffer
  .extern dormant_mode_abort_reset
  .extern mddbg_restore
	
  .extern dormant_alc_reg
  
#if defined(MT6290)||defined(MT6595)||defined(MT6752)
  .extern dormant_cache_flush_start_frc
  .extern dormant_cache_flush_end_frc
#endif /* MT6290||MT6595 */
#if defined(MT6290)
  .extern dormant_reset_end_frc
  .extern dormant_emi_code_storage
  .extern dormant_tcm_code_start
  .extern dormant_tcm_code_end
  .extern md_bus_err_ctl_addr
  .extern md_bus_err_ctl_value
  .extern md_bus_err_type_addr
  .extern md_bus_err_type_value
#endif /* MT6290 */

/*******************************************************************************
*      Dormant mode reset handler
*******************************************************************************/
@void arm_dormant_reset_handler(void) 
    .global arm_dormant_reset_handler

arm_dormant_reset_handler:
/* infinite loop for debug */
/*   B   arm_dormant_reset_handler */

#if defined(MODEM_3G_RTR_TIME_CHECK)
/* get current RTR value */
   LDR r0, dormant_hw_rtr_val
   MOV r1, #0x0
   LDR r0, [r0]
   STR r1, [r0]
   LDR r0, [r0, #0x4]
   LDR r1, dormant_sw_reset_rtr
   STR r0, [r1]
#endif /* MODEM_3G_RTR_TIME_CHECK */

/* get current FRC value */
   LDR r0, dormant_hw_frc_val
   LDR r1, dormant_sw_reset_frc
   LDR r0, [r0]
   LDR r0, [r0]
   STR r0, [r1]

/* ALC needs at most 1us, enable as soon as possibly */
   LDR r0, dormant_hw_alc_val
   LDR r0, [r0]
   LDR r1, [r0]
   ORR r1, r1, #1
   STR r1, [r0]

#if defined(MT6290)
   /* Clean bus err status in mt6290 Bootrom */
   LDR r0, dormant_md_bus_err_ctl_addr
   LDR r0, [r0]
   LDR r1, dormant_md_bus_err_ctl_value
   LDR r1, [r1]
   STR r1, [r0]

   LDR r0, dormant_md_bus_err_type_addr
   LDR r0, [r0]
   LDR r1, dormant_md_bus_err_type_value
   LDR r1, [r1]
   STR r1, [r0]

   /* Disable the MPU that enabled by Bootrom */
   /* ATCM code can not be executed after MPU is disabled */
   MRC p15, 0, r1, c1, c0, 0 /* read CP15 register 1 */
   BIC r1, r1, #0x1
   DSB
   MCR p15, 0, r1, c1, c0, 0 /* disable MPU */
   ISB
#endif /* MT6290 */

#if defined(MT6290)||defined(MT6595)||defined(MT6752)
/* Invalidate D-cache, I-cache */
    MOV r0,#0 

    MCR p15, 0, r0, c15, c5, 0
    DSB

    MCR p15, 0, r0, c7, c5, 0
    ISB
#endif /* MT6290||MT6595 */

#if defined(MT6290)
/* 
 * Restore TCM code used by bootrom
 *   r0: src start addr
 *   r1: dst start addr
 *   r2: dst end addr
 */
   LDR r0, dormant_tcm_code_backup
   LDR r1, dormant_tcm_code_restore_start
   LDR r1, [r1]
   LDR r2, dormant_tcm_code_restore_end
   LDR r2, [r2]

   CMP r1, r2
   BEQ code_copy_end
copy_loop:
   LDR r3, [r0], #4
   STR r3, [r1], #4
   CMP r1, r2
   BNE copy_loop
code_copy_end:

#endif /* MT6290 */

# record reset times
   LDR r0, dormant_reset_round
   LDR r1, [r0]
   ADD r1, #0x1
   STR r1, [r0]

# switch to dormant mode stack
   LDR r0, dormant_stack_point
   LDR r0, [r0]
   MOV sp, r0
   BLX mddbg_restore

# check whether dormant mode is triggered
   LDR r0,dormant_hw_status
   LDR r1,dormant_hw_ack
   LDR r0,[r0]
   LDR r0,[r0]
   LDR r1,[r1]
   ANDS r0,r0,r1
   BEQ arm_halt_loop
   BL  leave_dormant_mode

# unexpected reset
arm_halt_loop:
   B arm_halt_loop
.size arm_dormant_reset_handler, .-arm_dormant_reset_handler

dormant_hw_status:      
                    .long     dormant_status_reg
dormant_hw_ack:      
                    .long     dormant_power_ack_mask
dormant_hw_frc_val:     
                    .long     dormant_frc_val
#if defined(MODEM_3G_RTR_TIME_CHECK)
dormant_hw_rtr_val:     
                    .long     dormant_rtr_val
dormant_sw_reset_rtr:   
                    .long     dormant_reset_rtr
#endif /* MODEM_3G_RTR_TIME_CHECK */
dormant_sw_reset_frc:   
                    .long     dormant_reset_frc
dormant_sw_standby_frc:   
                    .long     dormant_standby_frc
dormant_sw_abort_frc:
                    .long     dormant_abort_frc
dormant_stack_point:   
                    .long     dormant_mode_stack
dormant_reset_round:
                    .long     dormant_reset_count
dormant_abort_round:
                    .long     dormant_abort_count
dormant_interrupt_func:
                    .long     dormant_mode_abort_reset
dormant_hw_alc_val:
                    .long     dormant_alc_reg
#if defined(MT6290)||defined(MT6595)||defined(MT6752)
dormant_sw_cache_flush_start_frc:
                    .long     dormant_cache_flush_start_frc
dormant_sw_cache_flush_end_frc:
                    .long     dormant_cache_flush_end_frc
#endif /* MT6290||MT6595 */
#if defined(MT6290)                        
dormant_sw_reset_end_frc:
                    .long     dormant_reset_end_frc
 dormant_tcm_code_backup:
                    .long     dormant_emi_code_storage
 dormant_tcm_code_restore_start:
                    .long     dormant_tcm_code_start
 dormant_tcm_code_restore_end:
                    .long     dormant_tcm_code_end
 dormant_md_bus_err_ctl_addr:
                    .long     md_bus_err_ctl_addr 
 dormant_md_bus_err_ctl_value:
                    .long     md_bus_err_ctl_value
 dormant_md_bus_err_type_addr:
                      .long md_bus_err_type_addr
 dormant_md_bus_err_type_value:
                      .long md_bus_err_type_value
#else
dormant_hw_remapping_val:
                    .long     dormant_remapping_val
#endif /* MT6290 */
#if defined(__HIF_CLDMA_SUPPORT__)
dormant_dbg_ptr_local:
                    .long     dormant_dbg_ptr
#endif

/*------------------------------------------------------------------------------
#     Cortex-R4 dormant mode entry
#     # 
#     The dormant mode DormantSupport() function uses a block of 
#     memory with base address DORMANT_BASE. 
#  
# 
# Assumptions:
# =========== 
#     A Cortex-R4 (ARMv7-R compliant) system
#
#     DORMANT_BASE memory is configured as non-cacheable 
#
#     The primary code support for dormant save/restore is consistent with a 
#     function call from supervisor mode:
#     - DORMANT_BASE passed as an argument in r0
#     - function entered by a BL instruction
#     - function return uses BX lr
#     - execution starts in Supervisor mode 
#
#
#     Instructions are 'clean' and can be read from cache or main memory 
#     Execution of the save context code will not generate an abort
#     There is no saving of debug context
#
# Cortex-R4 and debug through powerdown
# # PLEASE NOTE: Cortex-R4 does _not_ support the ARMv7 OS lock mechanism
#              (DBGOSLSR, DBGPRSR and DBGOSSRR).
#              In addition, the cpu and debug share a single power domain. 
# To maintain a debug connection through the execution of dormant mode save 
# and restore code, power must be maintained to the resources accessed by
# the debugger. 
#
# The ARM debug architecture supports the following mechanisms for this:
# (a) PRCR.DBGNOPWRDWN - part of the core. When asserted, a system power 
#                        controller must not remove power from the 
#                        associated core.
# (b) CDBGPWRUPREQ/ACK - signals in the Debug Access Port (DAP).
#     The signals are global to the debug control domain. The signals
#     are used by a debugger to ensure debug specific resources are
#     powered up and available to it. 
# (c) CSYSPWRUPREQ/ACK - signals in the Debug Access Port (DAP).
#     The signals are redundant in a single power domain. They are used
#     in a split power domain for a debugger to communicate with more 
#     than debug specific resources in a system.
#
#
# System level assumptions:
# #     WFI wakeup events not required for dormant exit are inhibited at 
#     the system level where necessary.
#
#     External AXI activity to the TCMs is suppressed.
#
#     Handshake of power controller, STANDBYWFI, the PL310 IDLE signal
#     and debug (PRCR.DBGNOPWRDWN and CDBGPWRUPREQ/ACK) external to the core.
*/

/*******************************************************************************/
/*      Enter dormant mode */
/*******************************************************************************/

/*void enter_dormant_mode(void) */

                .global  enter_dormant_mode

enter_dormant_mode:

	PUSH {r0, r1}

	LDR r0,dormant_backup                /* TCM region to keep other register content for lower latency */
	LDR r1,dormant_tcm_backup            /* non-cached EMI region to keep information */
                                             /* needed before TCM has been configured. */

	DORMANT_SAVE

	LDR r0, dormant_hw_frc_val
	LDR r1, dormant_sw_standby_frc
	LDR r0, [r0]
	LDR r0, [r0]
	STR r0, [r1]

# switch to dormant mode stack
	LDR r0, dormant_stack_point
	LDR r0, [r0]
	MOV sp, r0

# keep virtual mapping register address in arm register to avoid D-cache access when dormant is abot.
#if defined(__HIF_CLDMA_SUPPORT__)
	LDR r4, dormant_dbg_ptr_local
	LDR r4, [r4]
	MOVW r5, #DORMANT_DPFB_IN
	MOVW r6, #DORMANT_DPFB_OUT
	STR r5, [r4]
#endif /* __HIF_CLDMA_SUPPORT__ */
	BLX disablePrefetchBuffer
#if defined(__HIF_CLDMA_SUPPORT__)
	STR r6, [r4]
#endif /* __HIF_CLDMA_SUPPORT__ */

#if defined(MT6290)||defined(MT6595)||defined(MT6752)
/* get current FRC value */
   LDR r0, dormant_hw_frc_val
   LDR r1, dormant_sw_cache_flush_start_frc
   LDR r0, [r0]
   LDR r0, [r0]
   STR r0, [r1]
   
/* Clean D-cache */
    BLX cp15_clean_dcache
    DSB
	
/* get current FRC value */
   LDR r0, dormant_hw_frc_val
   LDR r1, dormant_sw_cache_flush_end_frc
   LDR r0, [r0]
   LDR r0, [r0]
   STR r0, [r1]
#endif /* MT6290||MT6595 */

#if !defined(MT6290)
#if defined(__HIF_CLDMA_SUPPORT__)
	MOVW r5, #DORMANT_REMAP_BSV_IN
	MOVW r6, #DORMANT_REMAP_BSV_OUT
	STR r5, [r4]
#endif /* __HIF_CLDMA_SUPPORT__ */
	LDR r0, dormant_hw_remapping_val
	LDR r7, [r0]
	BLX disableVirtualMapping
#if defined(__HIF_CLDMA_SUPPORT__)
	STR r6, [r4]
#endif /* __HIF_CLDMA_SUPPORT__ */

	DSB
	ISB
#endif /* !MT6290 */

	WFI

	# dormant mode debug loop for pause abort
#dbg_loop:
#	B dbg_loop
#if !defined(MT6290)
	DSB
	LDR r0, [r7]                    /* enable virtual mapping without D-cache access */
	MOV r1, #0xC
	BIC r0, r0, r1, LSL #28
	STR r0, [r7]
#endif /* !MT6290 */

# record reset times
	LDR r0, dormant_abort_round
	LDR r1, [r0]
	ADD r1, #0x1
	STR r1, [r0]

	# MCU MTCMOS mode is not triggered due to pause abort
	LDR r0, dormant_hw_frc_val
	LDR r1, dormant_sw_abort_frc
	LDR r0, [r0]
	LDR r0, [r0]
	STR r0, [r1]

#if defined(__HIF_CLDMA_SUPPORT__)
	LDR r4, dormant_dbg_ptr_local
	LDR r4, [r4]
	MOVW r5, #DORMANT_ABT_EPFB_IN
	MOVW r6, #DORMANT_ABT_EPFB_OUT
	STR r5, [r4]
#endif /* __HIF_CLDMA_SUPPORT__ */
	DSB
	BLX enablePrefetchBuffer
#if defined(__HIF_CLDMA_SUPPORT__)
	STR r6, [r4]
#endif /* __HIF_CLDMA_SUPPORT__ */

	# add a log for pause abort event, i.e. MCU did not enter MTCMOS mode
	LDR     r1,dormant_interrupt_func
	BLX     r1

	# restore register content before DORMAN_SAVE
	LDR r12,dormant_backup          /* TCM region to keep other register content for lower latency */

	ADD     r0,r12,#(DM_BLOCK+4*13)
	LDM     r0,{r1-r4}              /* recover CPSR,SPSR & exclusive */
	CMP     r4,#0
	LDREXEQ r4,[r3]
	MSR     CPSR_fsxc,r1            /* restore the CPSR */
	MSR     SPSR_fsxc,r2            /* restore the SPSR */
	ADD     r0,r12,#DM_BLOCK
	LDM     r0,{r2-r14}             /* restore ARM registers (but r0, r1 and PC) */

	#if defined(__NUCLEUS_VERSION_2__)
	CPS	#MODE_SYS               /* switch back to System mode */
	#endif
	POP {r0, r1}
	# return to caller
	BX lr
.size enter_dormant_mode, .-enter_dormant_mode

#*******************************************************************************
#*      Leave dormant mode
#*******************************************************************************

#void leave_dormant_mode(void) 

                .global  leave_dormant_mode

leave_dormant_mode:

	LDR r0,dormant_backup       /* TCM region to keep other register content for lower latency */

	LDR r1,dormant_tcm_backup   /* non-cachedable EMI region to keep information */
                                    /* needed before TCM has been configured. */

	DORMANT_RESTORE

#if defined(MT6290)
   LDR r0, dormant_hw_frc_val
   LDR r1, dormant_sw_reset_end_frc
   LDR r0, [r0]
   LDR r0, [r0]
   STR r0, [r1]
#endif

	POP {r0, r1}
	BX r14
.size leave_dormant_mode, .-leave_dormant_mode

#*******************************************************************************
#*      backup and restore routine test mode
#*******************************************************************************

#void dormant_backup_test(void)

               .global dormant_backup_test

dormant_backup_test:
	BL    enter_dormant_mode
	BL    leave_dormant_mode
.size dormant_backup_test, .-dormant_backup_test

# Data pool
dormant_backup:      
                    .long     dormant_mode_storage
dormant_tcm_backup:  
                    .long     dormant_tcm_storage

#*******************************************************************************
#*      End of code
#*******************************************************************************

		.end
