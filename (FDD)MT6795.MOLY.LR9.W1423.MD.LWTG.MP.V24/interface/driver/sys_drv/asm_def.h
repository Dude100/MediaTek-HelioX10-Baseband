#ifndef _ASM_DEF_H
#define _ASM_DEF_H


#ifdef __THUMB2_UNIFIED__
#define FUNC_ATTR(name)  .thumb_func
#define CPU_ISA() .thumb
#define ISA_UNIFIED_SETTING()          .syntax unified
#else
#define FUNC_ATTR(name)  .type name, %function
#define CPU_ISA() .arm
#define ISA_UNIFIED_SETTING()
#endif

#ifdef __STACK_ALIGN_MPU__
#define STACK_ALIGN_NUM   5
#else
#define STACK_ALIGN_NUM   3
#endif


#endif

