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
*       esal_pr_tmr_defs.h
*
*   COMPONENT
*
*       ESAL - Embedded Software Abstraction Layer
*
*   DESCRIPTION
*
*       This file contains the processor specific definitions,
*       structures, assembly macros, etc, related to timers
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

#ifndef         ESAL_PR_TMR_DEFS_H
#define         ESAL_PR_TMR_DEFS_H

/* The following definitions / macros / etc are only used if the processor
   is configured (this is only if the architecture is NOT configured to
   contain the OS timer in esal_ar_cfg.h) to use a processor level timer
   for the OS timer. */
#if (ESAL_AR_OS_TIMER_USED == ESAL_FALSE)

/* Define the processor OS timer type (count-down or count-up) */
#define         ESAL_PR_TMR_OS_COUNT_DIR                ESAL_COUNT_DOWN

/* Define for the processor OS timer interrupt vector */
#define         ESAL_PR_TMR_OS_VECTOR                   ESAL_DP_TIMERINT1_INT_VECTOR_ID

/* Define a macro to read the processor OS timer hardware count.  The
   resultant size of the count must be 32-bits, regardless of the actual
   size of the timer used (8-bit, 16-bit, 32-bit, etc). */
#define         ESAL_PR_TMR_OS_COUNT_READ()                                                 \
                    ESAL_GE_MEM_READ32(ESAL_PR_TMR_TIMER_BASE_ADDR + ESAL_PR_TMR_TIMER_VALUE_OFFSET)

/* Define the EOI logic for the processor OS timer */
#define         ESAL_PR_TMR_OS_TIMER_EOI(vector)                                            \
                    ESAL_GE_MEM_WRITE32(ESAL_PR_TMR_TIMER_BASE_ADDR +                       \
                                        ESAL_PR_TMR_TIMER_INTCLR_OFFSET,                    \
                                        ESAL_PR_TMR_TIMER_CLR)

#endif  /* ESAL_PR_OS_TIMER_USED == ESAL_TRUE */

#endif  /* ESAL_PR_TMR_DEFS_H */
