#!/usr/bin/perl -w
use strict;

my $entryNum = 64;

my $i = 0;
print "\n";
print "SVC_MODE  EQU 0x13         ; Supervisor Mode (SVC)\n";
print "IRQ_MODE  EQU 0x12         ; Interrupt Mode (IRQ)\n";
print "KERN_MODE EQU 0x1f		 ; Kernel Running Mode\n";
print "SYS_MODE  EQU 0x1f		 ; Kernel Running Mode\n";
print "\n";
print "    PRESERVE8\n";
print "   AREA |INTERNDATA|, DATA, READWRITE\n";
print "   IMPORT drv_mdcirq_dispatcher\n";
print "   IMPORT ESAL_GE_STK_System_SP\n";
print "   IMPORT ESAL_GE_ISR_OS_Nested_Entry\n";
print "   IMPORT ESAL_GE_ISR_OS_Entry\n";
print "   IMPORT ESAL_GE_ISR_OS_Nested_Entry\n";
print "   IMPORT ESAL_GE_STK_Unsol_Switch_Req\n";
print "   IMPORT ESAL_GE_ISR_Executing\n";
print "   IMPORT ESAL_AR_STK_Unsolicited_Switch\n";
print "   IMPORT TP_Update_Preempted_Time\n";
print "\n";
print "   AREA |INTERNCODE|, CODE, READONLY\n";
print "   INCLUDE nucleus_v2/inc/rvct_type/esal_ar_isr_defs.inc\n";
print "   INCLUDE nucleus_v2/inc/rvct_type/esal_ar_stk_defs.inc\n";
print "   EXPORT ISRRoutine_1\n";
print "   EXPORT ISRRoutine_2\n";
print "   EXPORT ISRRoutines\n";
#print "   THUMB\n";
print "   ALIGN 4\n";
print "ISRRoutines\n";
while($i < $entryNum){
	print "ISRRoutine_$i\n";                  #
	print "    SUB     lr,lr,#4\n";            # 4 bytes
	print "    ORR     lr,lr,#1\n";            # 4 bytes
	print "    SRSDB   sp!, #SYS_MODE\n";      # 4 bytes
	print "    MOV     lr, #$i\n";             # 2 bytes
	print "    B       ISRCommonRoutine\n";    # 
	print "    ALIGN 4\n";
	$i += 1;
}

print "ESAL_AR_ISR_System_SP\n";
print "    DCD ESAL_GE_STK_System_SP\n";
print "ESAL_AR_ISR_Executing\n";
print "    DCD ESAL_GE_ISR_Executing\n";
print "ESAL_AR_ISR_OS_Entry\n";
print "    DCD ESAL_GE_ISR_OS_Entry\n";
print "ESAL_AR_ISR_OS_Nested_Entry\n";
print "	   DCD ESAL_GE_ISR_OS_Nested_Entry\n";
print "ESAL_AR_ISR_Unsol_Switch_Req\n";
print "	   DCD ESAL_GE_STK_Unsol_Switch_Req\n";
print "UPDATE_PREEMPTED_TIME\n";
print "	   DCD TP_Update_Preempted_Time\n";
print "ISRCommonRoutine\n";

print "    ESAL_AR_STK_MIN_INT_SAVE\n";
print "    \n";
print "    CPSID   aif, #IRQ_MODE\n";
print "    MOV     r0, lr               ; vector ID\n";
print "    CPSID   aif, #SYS_MODE\n";
print "    MOV     r1, sp               ; preempted task SP\n";
print "    \n";
print "    ; Check if this interrupt occurred during execution of\n";
print "    ; another interrupt (nested)\n";
print "    LDR     r2,ESAL_AR_ISR_Executing\n";
print "    LDR     r2,[r2]\n";
print "    CMP     r2, #0\n";
print "    LDREQ   sp,ESAL_AR_ISR_System_SP\n";
print "    LDREQ   sp,[sp]\n";
print "    LDREQ   r2,ESAL_AR_ISR_OS_Entry\n";
print "    LDRNE   r2,ESAL_AR_ISR_OS_Nested_Entry\n";
print "    LDR     r2,[r2]\n";
print "    ADRNE   lr,ESAL_AR_ISR_Nested_IRQ_Restore\n";
print "    ADREQ   lr,ESAL_AR_ISR_NonNested_IRQ_Restore\n";
print "    ORR     lr, lr, #1\n";
print "    BX      r2\n";
print "ESAL_AR_ISR_NonNested_IRQ_Restore\n";
print "    LDR     r2,ESAL_AR_ISR_Unsol_Switch_Req\n";
print "    LDR     r2,[r2]\n";
print "    CMP     r2,#0\n";
print "    ; Perform context switch if required\n";
print "    BNE     ESAL_AR_STK_Unsolicited_Switch\n";
print "    ; No context switch required, restore minimal context and\n";
print "    ; return to point of interrupt\n";
print "    \n";
print "    ; Get system stack pointer in r0\n";
print "    LDR     r0,[r0]\n";
print "    \n";
print "    ; Save the r0 to the stack\n";
print "    PUSH    {r0}\n";
print "    ;    LDR     r0,NO_CONTEXT_SWITCH_LOGGING\n";
print "    ;    BLX     r0\n";
print "    \n";
print "    LDR     r1, UPDATE_PREEMPTED_TIME\n";
print "    BLX     r1\n";
print "    \n";
print "    ; Restore r0 from the stack\n";
print "    POP     {r0}\n";
print "    \n";
print "    ; Restore minimum registers from stack and return from interrupt\n";
print "    ESAL_AR_STK_MIN_INT_RESTORE\n";
print "    \n";
print "ESAL_AR_ISR_Nested_IRQ_Restore\n";
print "    ; Put the stack pointer in r0\n";
print "    MOV   r0,sp\n";
print "    \n";
print "    ; Restore minimum registers from stack and return from interrupt\n";
print "    ESAL_AR_STK_MIN_INT_RESTORE\n";
print "    \n";
print "    ; LDR   lr, =drv_mdcirq_dispatcher\n";
print "    ; BLX   lr\n";
print "    ; MOV   sp, r0\n";
print "    ; POP   {r0-r12,r14}\n";
print "    ; RFEIA sp!\n";
print "\n";
print "   END\n";
print "\n";
