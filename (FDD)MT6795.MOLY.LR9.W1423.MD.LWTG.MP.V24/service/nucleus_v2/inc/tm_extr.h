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
*       tm_extr.h
*
*   COMPONENT
*
*       TM - Timer Management
*
*   DESCRIPTION
*
*       This file contains function prototypes of all functions
*       accessible to other components.
*
*   DATA STRUCTURES
*
*       None
*
*   DEPENDENCIES
*
*       tm_defs.h                           Timer Management constants
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

#include        "tm_defs.h"        /* Include TM constants      */


/* Check to see if the file has been included already.  */

#ifndef TM_EXTR
#define TM_EXTR

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/*  Initialization functions.  */

NU_VOID            TMIT_Initialize(NU_VOID);


/* Error checking for supplemental functions.  */

NU_STATE          TMSE_Create_Timer(NU_TIMER *timer_ptr, NU_CHAR *name,
                        NU_VOID (*expiration_routine)(NU_UNSIGNED), NU_UNSIGNED id,
                        NU_UNSIGNED initial_time, NU_UNSIGNED reschedule_time,
                        NU_OPTION enable);
NU_STATE          TMSE_Delete_Timer(NU_TIMER *timer_ptr);
NU_STATE          TMSE_Reset_Timer(NU_TIMER *timer_ptr,
                        NU_VOID (*expiration_routine)(NU_UNSIGNED),
                        NU_UNSIGNED initial_time, NU_UNSIGNED reschedule_time,
                        NU_OPTION enable);
NU_STATE          TMSE_Control_Timer(NU_TIMER *timer_ptr, NU_OPTION enable);


/* Supplemental processing functions.  */

NU_STATE          TMS_Create_Timer(NU_TIMER *timer_ptr, NU_CHAR *name,
                        NU_VOID (*expiration_routine)(NU_UNSIGNED), NU_UNSIGNED id,
                        NU_UNSIGNED initial_time, NU_UNSIGNED reschedule_time,
                        NU_OPTION enable);
NU_STATE          TMS_Delete_Timer(NU_TIMER *timer_ptr);
NU_STATE          TMS_Reset_Timer(NU_TIMER *timer_ptr,
                        NU_VOID (*expiration_routine)(NU_UNSIGNED),
                        NU_UNSIGNED initial_time, NU_UNSIGNED reschedule_timer,
                        NU_OPTION enable);
NU_STATE          TMS_Control_Timer(NU_TIMER *timer_ptr, NU_OPTION enable);


/* Core processing functions.  */

NU_VOID            TMC_Init_Task_Timer(TM_TCB *timer, NU_VOID *information);
NU_VOID            TMC_Timer_HISR(NU_VOID);
NU_VOID            TMC_Stop_Timer(TM_TCB *timer);
NU_VOID            TMC_Start_Timer(TM_TCB *timer, NU_UNSIGNED time);

/* Information retrieval functions.  */

NU_UNSIGNED        TMF_Established_Timers(NU_VOID);
NU_STATE          TMF_Timer_Information(NU_TIMER *timer_ptr, NU_CHAR *name,
                  NU_OPTION *enable, NU_UNSIGNED *expirations, NU_UNSIGNED *id,
                  NU_UNSIGNED *initial_time, NU_UNSIGNED *reschedule_time);
NU_UNSIGNED        TMF_Timer_Pointers(NU_TIMER **pointer_list,
                                                NU_UNSIGNED maximum_pointers);
NU_STATE          TMF_Get_Remaining_Time(NU_TIMER *timer_ptr, NU_UNSIGNED
                                       *remaining_time);

/* Define macro for commonly used stop task timer functionality */
#define         TMC_Stop_Task_Timer(timer)                          \
                        if (((TM_TCB *)timer) -> tm_next_timer)     \
                        {                                           \
                            TMC_Stop_Timer((TM_TCB *)timer);        \
                        }

/* Define macro for commonly used start task timer functionality */
#define         TMC_Start_Task_Timer        TMC_Start_Timer

/* Target dependent functions.  */

NU_VOID            TMCT_Adjust_Timer(NU_UNSIGNED new_value);
NU_VOID            TMCT_Enable_Timer(NU_UNSIGNED);
NU_VOID            TMCT_Timer_Interrupt(NU_INT vector);

/* Externally reference global data */
extern volatile NU_UNSIGNED    TMD_Timer;
extern volatile NU_UNSIGNED    TMD_System_Clock;
extern volatile NU_INT         TMD_Timer_State;
extern TC_TCB * volatile    TMD_Time_Slice_Task;

/* Determine if pointers / 32-bit values are accessible with a single instruction.
   If so, just reference the pointer / 32-bit value directly.  Otherwise, call
   the target dependent service.  */
#if (ESAL_AR_32BIT_ACCESS == 1)

/* Macro definitions for architectures supporting single instruction
   access to 32-bit values */
#define         TMCT_Set_Clock(new_value)       TMD_System_Clock = new_value
#define         TMCT_Retrieve_Clock()           TMD_System_Clock
#define         TMCT_Increment_Clock()          TMD_System_Clock++
#define         TMCT_Read_Timer()               TMD_Timer

#else

/* Define function prototypes */
NU_VOID            TMCT_Set_Clock(NU_UNSIGNED);
NU_UNSIGNED        TMCT_Retrieve_Clock(NU_VOID);
NU_VOID            TMCT_Increment_Clock(NU_VOID);
NU_UNSIGNED        TMCT_Read_Timer(NU_VOID);

#endif  /* ESAL_AR_32BIT_ACCESS == 1 */

#if (ESAL_AR_PTR_ACCESS == 1)

/* Macro definitions for architectures supporting single instruction
   access to pointers */
#define         TMCT_Retrieve_TS_Task()         TMD_Time_Slice_Task

#else

/* Define function prototypes */
NU_TASK         *TMCT_Retrieve_TS_Task(NU_VOID);

#endif  /* ESAL_AR_PTR_ACCESS == 1 */

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif  /* !TM_EXTR */
