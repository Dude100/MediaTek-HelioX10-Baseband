/***********************************************************************
*
*             Copyright 1993-2006 Mentor Graphics Corporation
*                         All Rights Reserved.
*
* THIS WORK CONTAINS TRADE SECRET AND PROPRIETARY INFORMATION WHICH IS
* THE PROPERTY OF MENTOR GRAPHICS CORPORATION OR ITS LICENSORS AND IS
* SUBJECT TO LICENSE TERMS.
*
************************************************************************

************************************************************************
*
*   FILE NAME
*
*       esal_ar_stk_defs.h
*
*   COMPONENT
*
*       ESAL - Embedded Software Abstraction Layer
*
*   DESCRIPTION
*
*       This file contains the architecture specific definitions,
*       structures, assembly macros, etc, related to stacks
*
*   DATA STRUCTURES
*
*       ESAL_AR_STK_MIN                     Minimum stack-frame
*                                           structure for the given
*                                           architecture
*       ESAL_AR_STK                         Stack-frame structure for
*                                           the given architecture
*
*   DEPENDENCIES
*
*       None
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
***********************************************************************/

#ifndef         ESAL_AR_STK_DEFS_H
#define         ESAL_AR_STK_DEFS_H

/* Define if floating point registers will be saved during context switches
   NOTE:  The assembly define must be changed in esal_ar_stk_defs.inc to
          match this define
   NOTE:  This define will dictate what registers are contained
          within solicited (TS) and unsolicited (AR) stack frames. */
#ifndef __ARM_FPUV2__
#define         ESAL_AR_STK_FPU_SUPPORT         ESAL_FALSE
#else
#define         ESAL_AR_STK_FPU_SUPPORT         ESAL_TRUE
#endif
/* Define number of single-precision floating point registers */
#define         ESAL_AR_STK_NUM_FPU_REGS        32

/* KeTing: Define the VFP RunFast mode FPSCR content*/
#define         ESAL_AR_STK_VFP_FPSCR_RUNFAST   0x03000000
#define         ESAL_AR_STK_VFP_FPEXC_ENABLE    0x40000000

/* Define bit mask used to determine if THUMB state for a given code pointer */
#define         ESAL_AR_STK_THUMB_MASK          ESAL_GE_MEM_32BIT_SET(0)

/* Define stack frame structure for minimum architecture registers required
   to be saved in order to enter a C environment during in interrupt / exception.
   These registers are the "scratch" registers that will not be preserved across 
   a function call boundary and any interrupt state registers that must preserved
   to allow interrupt nesting. */
typedef struct
{
// KeTing: Move from ESAL_AR_STK_STRUCT since we will store the FPU registers while entering the interrupt handler
#if (ESAL_AR_STK_FPU_SUPPORT == ESAL_TRUE)
    ESAL_UINT32              s[ESAL_AR_STK_NUM_FPU_REGS];
    ESAL_UINT32              fpscr;
    ESAL_UINT32              fpinst2;
    ESAL_UINT32              fpinst;
    ESAL_UINT32              fpexc;
#endif  /* ESAL_AR_STK_FPU_SUPPORT == ESAL_TRUE */

    ESAL_UINT32              r0;
    ESAL_UINT32              r1;
    ESAL_UINT32              r2;
    ESAL_UINT32              r3;
    ESAL_UINT32              r12;
#ifdef ARMV6_INST_ENABLE
		ESAL_UINT32 			 lr;
		ESAL_UINT32 			 rtn_address;
		ESAL_UINT32 			 spsr;
	
#else  /* else of ARMV6_INST_ENABLE */
	
		ESAL_UINT32 			 spsr;
		ESAL_UINT32 			 lr;
		ESAL_UINT32 			 rtn_address;
		
#endif /* end of else of ARMV6_INST_ENABLE */

} ESAL_AR_STK_MIN;

/* Define stack frame structure for the architecture supported. 
   This stack frame contains all registers that must be preserved
   across an (unsolicited) interrupt context switch.
   NOTE:  This stack frame includes the minimum stack frame
          defined above AND all other registers for the given
          architecture. */
typedef struct  ESAL_AR_STK_STRUCT
{
    ESAL_UINT32              stack_type;
    ESAL_UINT32              r4;
    ESAL_UINT32              r5;
    ESAL_UINT32              r6;
    ESAL_UINT32              r7;
    ESAL_UINT32              r8;
    ESAL_UINT32              r9;
    ESAL_UINT32              r10;
    ESAL_UINT32              r11;

// KeTing: Move to ESAL_AR_STK_MIN since we will store the FPU registers while entering the interrupt handler
//#if (ESAL_AR_STK_FPU_SUPPORT == ESAL_TRUE)
//
//    ESAL_UINT32              fpscr;
//    ESAL_UINT32              s[ESAL_AR_STK_NUM_FPU_REGS];
//
//#endif  /* ESAL_AR_STK_FPU_SUPPORT == ESAL_TRUE */

    ESAL_AR_STK_MIN     min_stack;

} ESAL_AR_STK;

#endif  /* ESAL_AR_STK_DEFS_H */
