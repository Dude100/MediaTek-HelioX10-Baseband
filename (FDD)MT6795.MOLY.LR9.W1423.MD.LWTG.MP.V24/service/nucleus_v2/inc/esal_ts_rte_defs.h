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
*       esal_ts_rte_defs.h
*
*   COMPONENT
*
*       ESAL - Embedded Software Abstraction Layer
*
*   DESCRIPTION
*
*       This file contains the toolset specific definitions, structures,
*       macros, etc, related to run-time environment items
*
*   DATA STRUCTURES
*
*       None
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

#ifndef         ESAL_TS_RTE_DEFS_H
#define         ESAL_TS_RTE_DEFS_H

/* Extern function references */
extern ESAL_VOID     ESAL_TS_RTE_SP_Write(ESAL_VOID* stack_ptr);
extern ESAL_VOID     ESAL_TS_RTE_BRK_Execute(ESAL_UINT32 unused);

/* Define the size of the ARM run-time environment heap */
#define         ESAL_TS_RTE_HEAP_SIZE           ESAL_GE_MEM_1K

/* Coprocessor registers */
#define         ESAL_TS_RTE_CP0                 p0
#define         ESAL_TS_RTE_CP1                 p1
#define         ESAL_TS_RTE_CP2                 p2
#define         ESAL_TS_RTE_CP3                 p3
#define         ESAL_TS_RTE_CP4                 p4
#define         ESAL_TS_RTE_CP5                 p5
#define         ESAL_TS_RTE_CP6                 p6
#define         ESAL_TS_RTE_CP7                 p7
#define         ESAL_TS_RTE_CP8                 p8
#define         ESAL_TS_RTE_CP9                 p9
#define         ESAL_TS_RTE_CP10                p10
#define         ESAL_TS_RTE_CP11                p11
#define         ESAL_TS_RTE_CP12                p12
#define         ESAL_TS_RTE_CP13                p13
#define         ESAL_TS_RTE_CP14                p14
#define         ESAL_TS_RTE_CP15                p15

/* CRn and CRm register values */
#define         ESAL_TS_RTE_C0                  c0
#define         ESAL_TS_RTE_C1                  c1
#define         ESAL_TS_RTE_C2                  c2
#define         ESAL_TS_RTE_C3                  c3
#define         ESAL_TS_RTE_C4                  c4
#define         ESAL_TS_RTE_C5                  c5
#define         ESAL_TS_RTE_C6                  c6
#define         ESAL_TS_RTE_C7                  c7
#define         ESAL_TS_RTE_C8                  c8
#define         ESAL_TS_RTE_C9                  c9
#define         ESAL_TS_RTE_C10                 c10
#define         ESAL_TS_RTE_C11                 c11
#define         ESAL_TS_RTE_C12                 c12
#define         ESAL_TS_RTE_C13                 c13
#define         ESAL_TS_RTE_C14                 c14
#define         ESAL_TS_RTE_C15                 c15

/* This macro writes the stack pointer. */
#define         ESAL_TS_RTE_SP_WRITE(stack_ptr)                                     \
                {                                                                   \
                    /* Set hardware stack pointer to passed in address */           \
                    ESAL_TS_RTE_SP_Write(stack_ptr);                                \
                }

/* This macro reads the stack pointer. */
#define         ESAL_TS_RTE_SP_READ()                                               \
                    /* Get architecture stack pointer  */                           \
                    (ESAL_VOID *)__current_sp()

/* This macro reads the current program status register (CPSR - all fields) */
#define         ESAL_TS_RTE_CPSR_CXSF_READ(cpsr_cxsf_ptr)                           \
                {                                                                   \
                    __asm                                                           \
                    {                                                               \
                        MRS    *(cpsr_cxsf_ptr), CPSR                               \
                    }                                                               \
                }

/* This macro writes the current program status register (CPSR - all fields) */
#define         ESAL_TS_RTE_CPSR_CXSF_WRITE(cpsr_cxsf_value)                        \
                {                                                                   \
                    __asm                                                           \
                    {                                                               \
                        MSR     CPSR_cxsf, (cpsr_cxsf_value)                        \
                    }                                                               \
                }

/* This macro writes the c (control) bits of the current program status register (CPSR) */
#define         ESAL_TS_RTE_CPSR_C_WRITE(c_bits)                                    \
                {                                                                   \
                    __asm                                                           \
                    {                                                               \
                        MSR     CPSR_c, (c_bits)                                    \
                    }                                                               \
                }

/* This macro write to a coprocessor register */
#define         ESAL_TS_RTE_CP_WRITE(cp, op1, cp_value, crn, crm, op2)              \
                {                                                                   \
                    __asm                                                           \
                    {                                                               \
                        MCR     cp, op1, (cp_value), crn, crm, op2                  \
                    }                                                               \
                }

/* This macro read from a coprocessor register */
#define         ESAL_TS_RTE_CP_READ(cp, op1, cp_value_ptr, crn, crm, op2)           \
                {                                                                   \
                    __asm                                                           \
                    {                                                               \
                        MRC     cp, op1, *(ESAL_UINT32 *)(cp_value_ptr), crn, crm, op2   \
                    }                                                               \
                }

/* This macro executes a NOP instruction */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#define         ESAL_TS_RTE_NOP_EXECUTE()                                           \
                {                                                                   \
                  do{}while(0);                                                     \
                }                                                                   \

/* This macro executes a breakpoint instruction
   NOTE:  This instruction is only usable by ARM v5 cores. */
#define         ESAL_TS_RTE_BRK_EXECUTE(brk_point_val)                              \
                {                                                                   \
                    /* Call function - BKPT not allowed in inline asm */            \
                    ESAL_TS_RTE_BRK_Execute(brk_point_val);                         \
                }

#if (ESAL_TS_PIC_PID_SUPPORT == ESAL_TRUE)

/* Reserve an AAPCS callee-saved register (v6 = r9) for use by position-independent code (PIC)
   and postition-independent data (PID).  */
__global_reg(6) ESAL_UINT32 ESAL_TS_RTE_PIC_Base;

/* This macro sets the PIC/PID base address register */
#define         ESAL_TS_RTE_PIC_PID_BASE_SET(pic_base, pid_base)                    \
                {                                                                   \
                    /* Access unused param */                                       \
                    ESAL_UNUSED_PARAM(pic_base);                                    \
                                                                                    \
                    /* Set the PIC/PID register (r9) */                             \
                    ESAL_TS_RTE_PIC_Base = (ESAL_UINT32)pid_base;                        \
                }

/* This macro gets the PIC/PID base address register */
#define         ESAL_TS_RTE_PIC_PID_BASE_GET(pic_base_ptr, pid_base_ptr)            \
                {                                                                   \
                    ESAL_UINT32 *temp32_ptr = (ESAL_UINT32 *)pid_base_ptr;                    \
                                                                                    \
                    /* Access unused param */                                       \
                    ESAL_UNUSED_PARAM(pic_base_ptr);                                \
                                                                                    \
                    /* Read the PIC/PID register (r9) */                            \
                    *temp32_ptr = ESAL_TS_RTE_PIC_Base;                             \
                }

#endif  /* ESAL_TS_PIC_PID_SUPPORT == ESAL_TRUE */

#endif  /* ESAL_TS_RTE_DEFS_H */
