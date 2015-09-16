/***********************************************************************
*
*            Copyright 1993 Mentor Graphics Corporation
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
*       esal_ge_tmr_defs.h
*
*   COMPONENT
*
*       ESAL - Embedded Software Abstraction Layer
*
*   DESCRIPTION
*
*       This file contains generic defines, structures, data types, etc
*       related to timers
*
*   DATA STRUCTURES
*
*       None
*
*   DEPENDENCIES
*
*       esal_ar_tmr_defs.h                  Embedded Software
*                                           Abstraction Layer architecture
*                                           timer related definitions
*       esal_pr_tmr_defs.h                  Embedded Software
*                                           Abstraction Layer processor
*                                           timer related definitions
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

#ifndef         ESAL_GE_TMR_DEFS_H
#define         ESAL_GE_TMR_DEFS_H

/* Include required header files */
#include        "esal_ar_tmr_defs.h"
#include        "esal_pr_tmr_defs.h"

/* Define all externally accessible, timer related function prototypes */
ESAL_VOID            ESAL_GE_TMR_OS_Timer_Start(ESAL_UINT32 ticks_per_sec);
ESAL_VOID            ESAL_GE_TMR_OS_ISR_Register(ESAL_VOID (*isr_func_ptr)(ESAL_INT));
ESAL_VOID            ESAL_AR_TMR_OS_Timer_Start(ESAL_UINT32 ticks_per_sec);
//ESAL_VOID            ESAL_PR_TMR_OS_Timer_Start(ESAL_UINT32 ticks_per_sec);

/* Generic macro to calculate timer count value for timer with a given clock rate,
   clock prescale and period.
   NOTE:  This macro will work for count-down (underflow) timers and match timers
          (count-up or count-down timers).  If using a count-up timer that generates
          an interrupt upon overflow, the value produced by this macro must be
          subtracted from the maximum timer count. */
#define         ESAL_GE_TMR_COUNT_CALC(clock_rate, clock_prescale, ticksPerSec)         \
                                           (ESAL_UINT32)( ((ESAL_UINT32)clock_rate) /             \
                                                     ((ESAL_UINT32)clock_prescale)  /        \
                                                      ((ESAL_UINT32)ticksPerSec) )

/* Defines for counter types (count-down or count-up) */
#define         ESAL_COUNT_DOWN             0
#define         ESAL_COUNT_UP               1

/* Define a generic macro for the OS clock rate and prescaler. */
#define         ESAL_GE_TMR_OS_CLOCK_RATE       ESAL_PR_TMR_OS_CLOCK_RATE
#define         ESAL_GE_TMR_OS_CLOCK_PRESCALE   ESAL_PR_TMR_OS_CLOCK_PRESCALE

/**********************
* ARCHITECTURE OS TIMER
**********************/
#if (ESAL_AR_OS_TIMER_USED == ESAL_TRUE)

/* Define a generic macro that reads the architecture OS timer hardware count */
#define         ESAL_GE_TMR_OS_COUNT_READ()     ESAL_AR_TMR_OS_COUNT_READ()

/* Define generic macro for count direction using the architecture settings */
#define         ESAL_GE_TMR_OS_COUNT_DIR        ESAL_AR_TMR_OS_COUNT_DIR

/* Define generic macro for OS timer end-of-interrupt */
#define         ESAL_GE_TMR_OS_TIMER_EOI        

/* Define generic macro for OS timer vector number */
#define         ESAL_GE_TMR_OS_VECTOR           ESAL_AR_TMR_OS_VECTOR

#else

/**********************
* PROCESSOR OS TIMER
**********************/

/* Define a generic macro that reads the processor OS timer hardware count */
#define         ESAL_GE_TMR_OS_COUNT_READ()     ESAL_PR_TMR_OS_COUNT_READ()

/* Define generic macro for count direction using the processor settings */
#define         ESAL_GE_TMR_OS_COUNT_DIR        ESAL_PR_TMR_OS_COUNT_DIR

/* Define generic macro for OS timer end-of-interrupt */
#define         ESAL_GE_TMR_OS_TIMER_EOI(a)     do{}while(0);        

/* Define generic macro for OS timer vector number */
#define         ESAL_GE_TMR_OS_VECTOR           ESAL_PR_TMR_OS_VECTOR

#endif  /* ESAL_AR_OS_TIMER_USED == ESAL_TRUE */

#endif  /* ESAL_GE_TMR_DEFS_H */
