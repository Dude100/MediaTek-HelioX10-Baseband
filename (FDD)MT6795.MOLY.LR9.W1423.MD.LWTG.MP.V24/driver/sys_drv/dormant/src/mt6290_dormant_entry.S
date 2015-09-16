/* to avoid the MT6290 CPE watchdog issue */

.data
.extern arm_dormant_reset_handler
.text
.global ISRRoutine_Default

.thumb
.section INTSRAM_ROCODE, "ax"
.syntax unified
.thumb_func
.align 2
.global dormant_tcm_reset_entry
dormant_tcm_reset_entry:
    /* Hardcode addess because this issue is for MT6290 Only */

	/* Get WDT Status, If not WDT timeout, jump to normal dormant flow */
    LDR   R0, =0xBF820134
	LDR   R1, [R0]
	AND   R1, R1, #0x1C
	CBZ   R1, dormant_normal_flow

	/* Clear WDT Status */
	LDR   R1, =0x76620040
	STR   R1, [R0]

	/* Set MD WDT Reset Mode */
	LDR   R0, =0xBF820100
	LDR   R1, [R0]
	BIC   R1, #0x8
	LDR   R2, =0x55000000
	ORR   R1, R1, R2
	STR   R1, [R0]

	/* Disable Dormant */
	LDR   R0, =0xFF830B08
	LDR   R1, =0x72080000
	LDR   R2, =0xFF830C00
	LDR   R3, =0xFFFF0001
	STR   R1, [R0]
	STR   R3, [R2]
	DSB
	ISB

	/* Trigger WDT again */
	LDR   R0, =0xBF820304
	LDR   R1, =0x16880001
	STR   R1, [R0]
	DSB
	ISB
dormant_wait_wdt_timeout:
    B dormant_wait_wdt_timeout

dormant_normal_flow:
	LDR   R1,dormant_normal_flow_address
    BX    R1
.size dormant_tcm_reset_entry, .-dormant_tcm_reset_entry

.align 2
dormant_normal_flow_address:
    .long arm_dormant_reset_handler

.end

