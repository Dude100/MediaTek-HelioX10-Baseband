#include "drv_mdcirq_reg.h"
#include "esal_ar_isr_defs_gcc.inc"
#include "esal_ar_stk_defs_gcc.inc"

.equ SVC_MODE  , 0x13         @ Supervisor Mode (SVC)
.equ IRQ_MODE  , 0x12         @ Interrupt Mode (IRQ)
.equ KERN_MODE , 0x1f         @ Kernel Running Mode
.equ SYS_MODE  , 0x1f         @ Kernel Running Mode
.data
.extern drv_mdcirq_dispatcher
.extern ESAL_GE_STK_System_SP
.extern ESAL_GE_ISR_OS_Entry
.extern ESAL_GE_ISR_OS_Nested_Entry
.extern ESAL_GE_STK_Unsol_Switch_Req
.extern TP_Update_Preempted_Time
.text
.global ISRRoutine_Default
.global ISRRoutine_1
.global ISRRoutine_2
.thumb
.section INTSRAM_ROCODE, "ax"
.syntax unified
.thumb_func
.align 2
.global ISRRoutines
ISRRoutines:
ISRRoutine_0:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #0
    B       ISRCommonRoutine
.align 2
ISRRoutine_1:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #1
    B       ISRCommonRoutine
.align 2
ISRRoutine_2:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #2
    B       ISRCommonRoutine
.align 2
ISRRoutine_3:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #3
    B       ISRCommonRoutine
.align 2
ISRRoutine_4:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #4
    B       ISRCommonRoutine
.align 2
ISRRoutine_5:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #5
    B       ISRCommonRoutine
.align 2
ISRRoutine_6:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #6
    B       ISRCommonRoutine
.align 2
ISRRoutine_7:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #7
    B       ISRCommonRoutine
.align 2
ISRRoutine_8:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #8
    B       ISRCommonRoutine
.align 2
ISRRoutine_9:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #9
    B       ISRCommonRoutine
.align 2
ISRRoutine_10:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #10
    B       ISRCommonRoutine
.align 2
ISRRoutine_11:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #11
    B       ISRCommonRoutine
.align 2
ISRRoutine_12:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #12
    B       ISRCommonRoutine
.align 2
ISRRoutine_13:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #13
    B       ISRCommonRoutine
.align 2
ISRRoutine_14:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #14
    B       ISRCommonRoutine
.align 2
ISRRoutine_15:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #15
    B       ISRCommonRoutine
.align 2
ISRRoutine_16:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #16
    B       ISRCommonRoutine
.align 2
ISRRoutine_17:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #17
    B       ISRCommonRoutine
.align 2
ISRRoutine_18:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #18
    B       ISRCommonRoutine
.align 2
ISRRoutine_19:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #19
    B       ISRCommonRoutine
.align 2
ISRRoutine_20:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #20
    B       ISRCommonRoutine
.align 2
ISRRoutine_21:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #21
    B       ISRCommonRoutine
.align 2
ISRRoutine_22:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #22
    B       ISRCommonRoutine
.align 2
ISRRoutine_23:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #23
    B       ISRCommonRoutine
.align 2
ISRRoutine_24:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #24
    B       ISRCommonRoutine
.align 2
ISRRoutine_25:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #25
    B       ISRCommonRoutine
.align 2
ISRRoutine_26:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #26
    B       ISRCommonRoutine
.align 2
ISRRoutine_27:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #27
    B       ISRCommonRoutine
.align 2
ISRRoutine_28:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #28
    B       ISRCommonRoutine
.align 2
ISRRoutine_29:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #29
    B       ISRCommonRoutine
.align 2
ISRRoutine_30:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #30
    B       ISRCommonRoutine
.align 2
ISRRoutine_31:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #31
    B       ISRCommonRoutine
.align 2
ISRRoutine_32:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #32
    B       ISRCommonRoutine
.align 2
ISRRoutine_33:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #33
    B       ISRCommonRoutine
.align 2
ISRRoutine_34:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #34
    B       ISRCommonRoutine
.align 2
ISRRoutine_35:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #35
    B       ISRCommonRoutine
.align 2
ISRRoutine_36:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #36
    B       ISRCommonRoutine
.align 2
ISRRoutine_37:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #37
    B       ISRCommonRoutine
.align 2
ISRRoutine_38:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #38
    B       ISRCommonRoutine
.align 2
ISRRoutine_39:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #39
    B       ISRCommonRoutine
.align 2
ISRRoutine_40:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #40
    B       ISRCommonRoutine
.align 2
ISRRoutine_41:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #41
    B       ISRCommonRoutine
.align 2
ISRRoutine_42:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #42
    B       ISRCommonRoutine
.align 2
ISRRoutine_43:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #43
    B       ISRCommonRoutine
.align 2
ISRRoutine_44:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #44
    B       ISRCommonRoutine
.align 2
ISRRoutine_45:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #45
    B       ISRCommonRoutine
.align 2
ISRRoutine_46:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #46
    B       ISRCommonRoutine
.align 2
ISRRoutine_47:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #47
    B       ISRCommonRoutine
.align 2
ISRRoutine_48:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #48
    B       ISRCommonRoutine
.align 2
ISRRoutine_49:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #49
    B       ISRCommonRoutine
.align 2
ISRRoutine_50:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #50
    B       ISRCommonRoutine
.align 2
ISRRoutine_51:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #51
    B       ISRCommonRoutine
.align 2
ISRRoutine_52:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #52
    B       ISRCommonRoutine
.align 2
ISRRoutine_53:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #53
    B       ISRCommonRoutine
.align 2
ISRRoutine_54:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #54
    B       ISRCommonRoutine
.align 2
ISRRoutine_55:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #55
    B       ISRCommonRoutine
.align 2
ISRRoutine_56:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #56
    B       ISRCommonRoutine
.align 2
ISRRoutine_57:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #57
    B       ISRCommonRoutine
.align 2
ISRRoutine_58:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #58
    B       ISRCommonRoutine
.align 2
ISRRoutine_59:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #59
    B       ISRCommonRoutine
.align 2
ISRRoutine_60:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #60
    B       ISRCommonRoutine
.align 2
ISRRoutine_61:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #61
    B       ISRCommonRoutine
.align 2
ISRRoutine_62:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #62
    B       ISRCommonRoutine
.align 2
ISRRoutine_63:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #63
    B       ISRCommonRoutine
.align 2
ISRRoutine_64:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #64
    B       ISRCommonRoutine
.align 2
ISRRoutine_65:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #65
    B       ISRCommonRoutine
.align 2
ISRRoutine_66:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #66
    B       ISRCommonRoutine
.align 2
ISRRoutine_67:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #67
    B       ISRCommonRoutine
.align 2
ISRRoutine_68:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #68
    B       ISRCommonRoutine
.align 2
ISRRoutine_69:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #69
    B       ISRCommonRoutine
.align 2
ISRRoutine_70:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #70
    B       ISRCommonRoutine
.align 2
ISRRoutine_71:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #71
    B       ISRCommonRoutine
.align 2
ISRRoutine_72:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #72
    B       ISRCommonRoutine
.align 2
ISRRoutine_73:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #73
    B       ISRCommonRoutine
.align 2
ISRRoutine_74:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #74
    B       ISRCommonRoutine
.align 2
ISRRoutine_75:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #75
    B       ISRCommonRoutine
.align 2
ISRRoutine_76:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #76
    B       ISRCommonRoutine
.align 2
ISRRoutine_77:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #77
    B       ISRCommonRoutine
.align 2
ISRRoutine_78:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #78
    B       ISRCommonRoutine
.align 2
ISRRoutine_79:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #79
    B       ISRCommonRoutine
.align 2
ISRRoutine_80:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #80
    B       ISRCommonRoutine
.align 2
ISRRoutine_81:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #81
    B       ISRCommonRoutine
.align 2
ISRRoutine_82:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #82
    B       ISRCommonRoutine
.align 2
ISRRoutine_83:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #83
    B       ISRCommonRoutine
.align 2
ISRRoutine_84:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #84
    B       ISRCommonRoutine
.align 2
ISRRoutine_85:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #85
    B       ISRCommonRoutine
.align 2
ISRRoutine_86:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #86
    B       ISRCommonRoutine
.align 2
ISRRoutine_87:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #87
    B       ISRCommonRoutine
.align 2
ISRRoutine_88:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #88
    B       ISRCommonRoutine
.align 2
ISRRoutine_89:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #89
    B       ISRCommonRoutine
.align 2
ISRRoutine_90:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #90
    B       ISRCommonRoutine
.align 2
ISRRoutine_91:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #91
    B       ISRCommonRoutine
.align 2
ISRRoutine_92:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #92
    B       ISRCommonRoutine
.align 2
ISRRoutine_93:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #93
    B       ISRCommonRoutine
.align 2
ISRRoutine_94:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #94
    B       ISRCommonRoutine
.align 2
ISRRoutine_95:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #95
    B       ISRCommonRoutine
.align 2
ISRRoutine_96:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #96
    B       ISRCommonRoutine
.align 2
ISRRoutine_97:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #97
    B       ISRCommonRoutine
.align 2
ISRRoutine_98:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #98
    B       ISRCommonRoutine
.align 2
ISRRoutine_99:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #99
    B       ISRCommonRoutine
.align 2
ISRRoutine_100:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #100
    B       ISRCommonRoutine
.align 2
ISRRoutine_101:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #101
    B       ISRCommonRoutine
.align 2
ISRRoutine_102:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #102
    B       ISRCommonRoutine
.align 2
ISRRoutine_103:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #103
    B       ISRCommonRoutine
.align 2
ISRRoutine_104:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #104
    B       ISRCommonRoutine
.align 2
ISRRoutine_105:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #105
    B       ISRCommonRoutine
.align 2
ISRRoutine_106:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #106
    B       ISRCommonRoutine
.align 2
ISRRoutine_107:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #107
    B       ISRCommonRoutine
.align 2
ISRRoutine_108:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #108
    B       ISRCommonRoutine
.align 2
ISRRoutine_109:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #109
    B       ISRCommonRoutine
.align 2
ISRRoutine_110:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #110
    B       ISRCommonRoutine
.align 2
ISRRoutine_111:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #111
    B       ISRCommonRoutine
.align 2
ISRRoutine_112:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #112
    B       ISRCommonRoutine
.align 2
ISRRoutine_113:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #113
    B       ISRCommonRoutine
.align 2
ISRRoutine_114:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #114
    B       ISRCommonRoutine
.align 2
ISRRoutine_115:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #115
    B       ISRCommonRoutine
.align 2
ISRRoutine_116:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #116
    B       ISRCommonRoutine
.align 2
ISRRoutine_117:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #117
    B       ISRCommonRoutine
.align 2
ISRRoutine_118:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #118
    B       ISRCommonRoutine
.align 2
ISRRoutine_119:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #119
    B       ISRCommonRoutine
.align 2
ISRRoutine_120:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #120
    B       ISRCommonRoutine
.align 2
ISRRoutine_121:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #121
    B       ISRCommonRoutine
.align 2
ISRRoutine_122:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #122
    B       ISRCommonRoutine
.align 2
ISRRoutine_123:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #123
    B       ISRCommonRoutine
.align 2
ISRRoutine_124:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #124
    B       ISRCommonRoutine
.align 2
ISRRoutine_125:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #125
    B       ISRCommonRoutine
.align 2
ISRRoutine_126:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #126
    B       ISRCommonRoutine
.align 2
ISRRoutine_127:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    MOV     lr, #127
    B       ISRCommonRoutine
.align 2
ESAL_AR_ISR_System_SP:
    .long ESAL_GE_STK_System_SP
ESAL_AR_ISR_Executing:
    .long ESAL_GE_ISR_Executing
ESAL_AR_ISR_OS_Entry:
    .long ESAL_GE_ISR_OS_Entry
ESAL_AR_ISR_OS_Nested_Entry:
    .long ESAL_GE_ISR_OS_Nested_Entry
ESAL_AR_ISR_Unsol_Switch_Req:
    .long ESAL_GE_STK_Unsol_Switch_Req
NO_CONTEXT_SWITCH_LOGGING:
    .long No_Context_Switch
#if defined(__TP_SUPPORT_TIMING_CHECK__)
UPDATE_PREEMPTED_TIME:
    .long TP_Update_Preempted_Time
#endif /* end of __TP_SUPPORT_TIMING_CHECK__ */
ISRCommonRoutine:
    ESAL_AR_STK_MIN_INT_SAVE
    
    CPSID   aif, #IRQ_MODE
    MOV     r0, lr               @ vector ID
    CPSID   aif, #SYS_MODE
    MOV     r1, sp               @ preempted task SP
    
    @ Check if this interrupt occurred during execution of
    @ another interrupt (nested)
    LDR     r2,ESAL_AR_ISR_Executing
    LDR     r2,[r2]
    CMP     r2, #0
    LDREQ   sp,ESAL_AR_ISR_System_SP
    LDREQ   sp,[sp]
    LDREQ   r2,ESAL_AR_ISR_OS_Entry
    LDRNE   r2,ESAL_AR_ISR_OS_Nested_Entry
    LDR     r2,[r2]
    ADRNE   lr,ESAL_AR_ISR_Nested_IRQ_Restore
    ADREQ   lr,ESAL_AR_ISR_NonNested_IRQ_Restore
    ORR     lr, lr, #1
    BX      r2
ESAL_AR_ISR_NonNested_IRQ_Restore:
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
    PUSH    {r0}
    LDR     r0,NO_CONTEXT_SWITCH_LOGGING
    BLX     r0
    
#if defined(__TP_SUPPORT_TIMING_CHECK__)
    LDR     r1, UPDATE_PREEMPTED_TIME
    BLX     r1
    
#endif /* end of __TP_SUPPORT_TIMING_CHECK__ */
    @ Restore r0 from the stack
    POP     {r0}
    
    @ Restore minimum registers from stack and return from interrupt
    ESAL_AR_STK_MIN_INT_RESTORE
    
ESAL_AR_ISR_Nested_IRQ_Restore:
    @ Put the stack pointer in r0
    MOV   r0,sp
    
    @ Restore minimum registers from stack and return from interrupt
    ESAL_AR_STK_MIN_INT_RESTORE
.size ISRRoutines, .-ISRRoutines

.thumb
.text
.syntax unified
.thumb_func
.align 2
ESAL_AR_ISR_System_SP_Spurious:
    .long ESAL_GE_STK_System_SP
ESAL_AR_ISR_Executing_Spurious:
    .long ESAL_GE_ISR_Executing
ESAL_AR_ISR_OS_Entry_Spurious:
    .long ESAL_GE_ISR_OS_Entry
ESAL_AR_ISR_OS_Nested_Entry_Spurious:
    .long ESAL_GE_ISR_OS_Nested_Entry
ESAL_AR_ISR_Unsol_Switch_Req_Spurious:
    .long ESAL_GE_STK_Unsol_Switch_Req
NO_CONTEXT_SWITCH_LOGGING_Spurious:
    .long No_Context_Switch
#if defined(__TP_SUPPORT_TIMING_CHECK__)
UPDATE_PREEMPTED_TIME_Spurious:
    .long TP_Update_Preempted_Time
#endif /* end of __TP_SUPPORT_TIMING_CHECK__ */
ESAL_AR_STK_Unsolicited_Switch_Spurious:
    .long ESAL_AR_STK_Unsolicited_Switch

ISRRoutine_Default:
    SUB     lr,lr,#4
    SRSDB   sp!, #SYS_MODE
    ESAL_AR_STK_MIN_INT_SAVE
    MOV     r1, sp               @ preempted task SP
    LDR     r2,=MDCIRQ_INTID_SPUR
    LDR     r0,[r2]                    
    @ Check if this interrupt occurred during execution of
    @ another interrupt (nested)
    LDR     r2,ESAL_AR_ISR_Executing_Spurious
    LDR     r2,[r2]
    CMP     r2, #0
    LDREQ   sp,ESAL_AR_ISR_System_SP_Spurious
    LDREQ   sp,[sp]
    LDREQ   r2,ESAL_AR_ISR_OS_Entry_Spurious
    LDRNE   r2,ESAL_AR_ISR_OS_Nested_Entry_Spurious
    LDR     r2,[r2]
    ADRNE   lr,ESAL_AR_ISR_Nested_IRQ_Restore_Spurious
    ADREQ   lr,ESAL_AR_ISR_NonNested_IRQ_Restore_Spurious
    ORR     lr, lr, #1
    BX      r2
ESAL_AR_ISR_NonNested_IRQ_Restore_Spurious:
    LDR     r2,ESAL_AR_ISR_Unsol_Switch_Req_Spurious
    LDR     r2,[r2]
    CMP     r2,#0
    @ Perform context switch if required
    LDRNE   r3,ESAL_AR_STK_Unsolicited_Switch_Spurious
    BXNE    r3
    @ No context switch required, restore minimal context and
    @ return to point of interrupt
    
    @ Get system stack pointer in r0
    LDR     r0,[r0]
    
    @ Save the r0 to the stack
    PUSH    {r0}
    LDR     r0, NO_CONTEXT_SWITCH_LOGGING_Spurious
    BLX     r0
    
#if defined(__TP_SUPPORT_TIMING_CHECK__)
    LDR     r1, UPDATE_PREEMPTED_TIME_Spurious
    BLX     r1
    
#endif /* end of __TP_SUPPORT_TIMING_CHECK__ */
    @ Restore r0 from the stack
    POP     {r0}
    
    @ Restore minimum registers from stack and return from interrupt
    ESAL_AR_STK_MIN_INT_RESTORE
    
ESAL_AR_ISR_Nested_IRQ_Restore_Spurious:
    @ Put the stack pointer in r0
    MOV   r0,sp
    
    @ Restore minimum registers from stack and return from interrupt
    ESAL_AR_STK_MIN_INT_RESTORE
.size ISRRoutine_Default, .-ISRRoutine_Default

.end

