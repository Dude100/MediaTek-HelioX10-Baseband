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
*       tc_extr.h
*
*   COMPONENT
*
*       TC - Thread Control
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
*       tc_defs.h                           Thread Control constants
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

#include        "tc_defs.h"        /* Include TC constants      */


/* Check to see if the file has been included already.  */

#ifndef TC_EXTR
#define TC_EXTR


#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Define externally referenced variables.   */

extern TC_PROTECT           TCD_System_Protect;
extern NU_VOID * volatile      TCD_Current_Thread;
extern TC_HCB               TCD_Init_Thread;
extern TC_TCB * volatile    TCD_Execute_Task;

/* Initialization functions.  */

NU_VOID            TCIT_Initialize(NU_VOID);


/* Core error checking functions.  */

#if (NU_ERROR_CHECKING == NU_TRUE)

NU_BOOLEAN         TCC_Validate_Resume(NU_OPTION resume_type, NU_TASK *task_ptr);

#endif  /* NU_ERROR_CHECKING == NU_TRUE */
NU_STATE          TCCE_Activate_HISR(NU_HISR *hisr_ptr);
NU_STATE          TCCE_Create_Task(NU_TASK *task_ptr, NU_CHAR *name,
                                 NU_VOID (*task_entry)(NU_UNSIGNED, NU_VOID *),
                                 NU_UNSIGNED argc,
                                 NU_VOID *argv, NU_VOID *stack_address,
                                 NU_UNSIGNED stack_size,
                                 NU_OPTION priority, NU_UNSIGNED time_slice,
                                 NU_OPTION preempt, NU_OPTION auto_start);
NU_STATE          TCCE_Reset_Task(NU_TASK *task_ptr, NU_UNSIGNED argc, NU_VOID *argv);
NU_STATE          TCCE_Create_HISR(NU_HISR *hisr_ptr, NU_CHAR *name,
                                 NU_VOID (*hisr_entry)(NU_VOID), NU_OPTION priority,
                                 NU_VOID *stack_address, NU_UNSIGNED stack_size);
NU_STATE          TCCE_Terminate_Task(NU_TASK *task_ptr);
NU_STATE          TCCE_Delete_Task(NU_TASK *task_ptr);
NU_STATE          TCCE_Delete_HISR(NU_HISR *hisr_ptr);
NU_STATE          TCCE_Resume_Service(NU_TASK *task_ptr);
NU_STATE          TCCE_Suspend_Service(NU_TASK *task_ptr);
NU_VOID            TCCE_Relinquish(NU_VOID);
NU_VOID            TCCE_Task_Sleep(NU_UNSIGNED ticks);
NU_STATE          TCCE_Validate_Resume(NU_OPTION resume_type, NU_TASK *task_ptr);
NU_INT             TCCE_Suspend_Error(NU_VOID);
NU_STATE          TCCE_Register_LISR(NU_INT vector, NU_VOID (*new_lisr)(NU_INT),
                                   NU_VOID (**old_lisr)(NU_INT));
NU_STATE          TCFE_Task_Information(NU_TASK *task_ptr, NU_CHAR *name,
                    NU_DATA_ELEMENT *status, NU_UNSIGNED *scheduled_count,
                    NU_DATA_ELEMENT *priority, NU_OPTION *preempt, NU_UNSIGNED *time_slice,
                    NU_VOID **stack_base, NU_UNSIGNED *stack_size,
                    NU_UNSIGNED *minimum_stack);


/* Supplemental error checking functions.  */

NU_OPTION          TCSE_Change_Priority(NU_TASK *task_ptr, NU_OPTION new_priority);
NU_OPTION          TCSE_Change_Preemption(NU_OPTION preempt);
NU_UNSIGNED        TCSE_Change_Time_Slice(NU_TASK *task_ptr, NU_UNSIGNED time_slice);
NU_UNSIGNED        TCSE_Control_Signals(NU_UNSIGNED signal_enable_mask);
NU_UNSIGNED        TCSE_Receive_Signals(NU_VOID);
NU_STATE          TCSE_Register_Signal_Handler(NU_VOID (*signal_handler)(NU_UNSIGNED));
NU_STATE          TCSE_Send_Signals(NU_TASK *task_ptr, NU_UNSIGNED signals);


/* Core processing functions.  */

NU_STATE          TCC_Terminate_Task(NU_TASK *task_ptr);
NU_STATE          TCC_Delete_Task(NU_TASK *task_ptr);
NU_STATE          TCC_Delete_HISR(NU_HISR *hisr_ptr);
NU_STATE          TCC_Resume_Task(NU_TASK *task_ptr, NU_OPTION suspend_type);
NU_STATE          TCC_Resume_Service(NU_TASK *task_ptr);
NU_VOID            TCC_Suspend_Task(NU_TASK *task_ptr, NU_OPTION suspend_type,
                                 NU_VOID (*cleanup)(NU_VOID *),
                                 NU_VOID *information, NU_UNSIGNED timeout);
NU_STATE          TCC_Suspend_Service(NU_TASK *task_ptr);
NU_VOID            TCC_Task_Timeout(NU_TASK *task_ptr);
NU_VOID            TCC_Task_Sleep(NU_UNSIGNED ticks);
NU_VOID            TCC_Relinquish(NU_VOID);
NU_VOID            TCC_Time_Slice(NU_TASK *task_ptr);
NU_TASK        *TCC_Current_Task_Pointer(NU_VOID);
NU_HISR        *TCC_Current_HISR_Pointer(NU_VOID);


/* Supplemental functions.  */

NU_OPTION          TCS_Change_Priority(NU_TASK *task_ptr, NU_OPTION new_priority);
NU_OPTION          TCS_Change_Preemption(NU_OPTION preempt);
NU_UNSIGNED        TCS_Change_Time_Slice(NU_TASK *task_ptr, NU_UNSIGNED time_slice);
NU_UNSIGNED        TCS_Control_Signals(NU_UNSIGNED signal_enable_mask);
NU_UNSIGNED        TCS_Receive_Signals(NU_VOID);
NU_STATE          TCS_Register_Signal_Handler(NU_VOID (*signal_handler)(NU_UNSIGNED));


/* Information retrieval functions.  */

NU_UNSIGNED        TCF_Established_Tasks(NU_VOID);
NU_UNSIGNED        TCF_Established_HISRs(NU_VOID);
NU_STATE          TCF_Task_Information(NU_TASK *task, NU_CHAR *name,
                                     NU_DATA_ELEMENT *status,
                                     NU_UNSIGNED *scheduled_count,
                                     NU_OPTION *priority, NU_OPTION *preempt,
                                     NU_UNSIGNED *time_slice, NU_VOID **stack_base,
                                     NU_UNSIGNED *stack_size, NU_UNSIGNED *minimum_stack);
NU_STATE          TCF_HISR_Information(NU_HISR *hisr, NU_CHAR *name,
                                     NU_UNSIGNED *scheduled_count,
                                     NU_DATA_ELEMENT *priority,
                                     NU_VOID **stack_base, NU_UNSIGNED *stack_size,
                                     NU_UNSIGNED *minimum_stack);
NU_UNSIGNED        TCF_Task_Pointers(NU_TASK **pointer_list,
                                  NU_UNSIGNED maximum_pointers);
NU_UNSIGNED        TCF_HISR_Pointers(NU_HISR **pointer_list,
                                  NU_UNSIGNED maximum_pointers);

/* Core functions with target dependencies */

NU_STATE          TCCT_Create_Task(NU_TASK *task_ptr, NU_CHAR *name,
                                 NU_VOID (*task_entry)(NU_UNSIGNED, NU_VOID *), NU_UNSIGNED argc,
                                 NU_VOID *argv, NU_VOID *stack_address, NU_UNSIGNED stack_size,
                                 NU_OPTION priority, NU_UNSIGNED time_slice,
                                 NU_OPTION preempt, NU_OPTION auto_start);
NU_STATE          TCCT_Create_HISR(NU_HISR *hisr_ptr, NU_CHAR *name,
                                 NU_VOID (*hisr_entry)(NU_VOID), NU_OPTION priority,
                                 NU_VOID *stack_address, NU_UNSIGNED stack_size);
NU_STATE          TCCT_Reset_Task(NU_TASK *task_ptr, NU_UNSIGNED argc, NU_VOID *argv);
NU_STATE          TCCT_Register_LISR(NU_INT vector, NU_VOID (*new_lisr)(NU_INT),
                                   NU_VOID (**old_lisr)(NU_INT));
NU_UNSIGNED        TCCT_Check_Stack(NU_VOID);
NU_VOID            TCCT_Schedule(NU_VOID);
NU_VOID            TCCT_Protect(TC_PROTECT *protect);
NU_VOID            TCCT_Unprotect(NU_VOID);
NU_VOID            TCCT_Unprotect_Specific(TC_PROTECT *protect);
NU_VOID            TCCT_Control_To_System(NU_VOID);
NU_INT             TCCT_Control_Interrupts(NU_INT new_level);
NU_STATE          TCCT_Activate_HISR(NU_HISR *hisr_ptr);

#if (NU_STACK_CHECKING == NU_TRUE)

#define NU_CHECK_STACK() TCCT_Check_Stack()

#else /* no stack checking */

#define NU_CHECK_STACK() ((NU_VOID)0)

#endif /* NU_STACK_CHECKING == NU_TRUE */

/* Supplementary functions with target dependencies */

NU_STATE          TCST_Send_Signals(NU_TASK *task, NU_UNSIGNED signals);

/* Determine if pointers are accessible with a single instruction.  If so,
   just reference the pointer directly.  Otherwise, call the target dependent
   service */

#if (ESAL_AR_PTR_ACCESS == 1)

/* Macro definitions for architectures supporting single instruction
   access to pointers */
#define         TCCT_Current_Thread()               TCD_Current_Thread
#define         TCCT_Set_Execute_Task(task)         TCD_Execute_Task =  task
#define         TCCT_Set_Current_Protect(protect)   \
                    ((TC_TCB *)TCD_Current_Thread) -> tc_current_protect = protect
#define         TCCT_Get_Current_Protect()          \
                   ((TC_TCB *) TCD_Current_Thread) -> tc_current_protect

#else

NU_VOID            *TCCT_Current_Thread(NU_VOID);
NU_VOID            TCCT_Set_Execute_Task(TC_TCB *task);
NU_VOID            TCCT_Set_Current_Protect(TC_PROTECT *protect);
TC_PROTECT      *TCCT_Get_Current_Protect(NU_VOID);

#endif /* ESAL_AR_PTR_ACCESS == 1 */

/* Define pseudo function used by internal components of the system.  */

#define         TCCT_System_Protect()                                           \
                   TCCT_Protect(&TCD_System_Protect)
#define         TCCT_System_Unprotect()                                         \
                   TCCT_Unprotect_Specific(&TCD_System_Protect)
#define         TCCT_Set_Suspend_Protect(protect)                               \
                   ((TC_TCB *) TCD_Current_Thread) -> tc_suspend_protect =      \
                   (TC_PROTECT *) protect
#define         TCC_Task_Priority(task)                                         \
                    ((TC_TCB *) (task)) -> tc_priority

/* Define macro, for internal components, to access current HISR pointer */

#define         TCC_CURRENT_HISR_PTR                                            \
                    ((TC_HCB *)TCD_Current_Thread)

/* Define interrupt locking / unlocking macros based on the interrupt locking
   method used */
#if (NU_GLOBAL_INT_LOCKING == NU_TRUE)

/* The following macro sets the interrupt lock-out level to the globally defined
   level (TCD_Interrupt_Level).  This macro is used in the scheduler and within
   the HISR shell routine. */
#define         TCC_INTERRUPTS_GLOBAL_ENABLE()                                  \
                        ESAL_GE_INT_BITS_SET(TCD_Interrupt_Level)

/* The following macro locks out interrupts without saving the state before
   locking-out.  It is used to guard critical sections of code and is always
   paired with the macro TCC_INTERRUPTS_RESTORE defined below. */
#if defined(__PROTECT_OPTIMIZE__) && defined(__GNUC__)
#define         TCC_INTERRUPTS_DISABLE()                                        \
                do{                                                             \
                    NU_UNSIGNED write_cpsr = ESAL_AR_INT_CPSR_SYS_DISABLED;     \
                    asm volatile(                                               \
                        "MSR   CPSR_c, %0\n\r"                                  \
                        :                                                       \
                        :"r"(write_cpsr)                                        \
                    );                                                          \
                }while(0)
#else  /* __PROTECT_OPTIMIZE__ && __GNUC__ */
#define         TCC_INTERRUPTS_DISABLE()                                        \
                        ESAL_GE_INT_FAST_ALL_DISABLE()
#endif /* __PROTECT_OPTIMIZE__ && __GNUC__ */

/* The following macro sets the interrupt lock-out level to the globally defined
   level (TCD_Interrupt_Level).  This macro is used at the end of critical
   sections where a context switch may have occurred.  This macro is always
   paired with the macro TCC_INTERRUPTS_ENABLE defined above. */
#if defined(__PROTECT_OPTIMIZE__) && defined(__GNUC__)
#define         TCC_INTERRUPTS_RESTORE()                                        \
                do{                                                             \
                    NU_UNSIGNED write_cpsr = TCD_Interrupt_Level;               \
                    NU_UNSIGNED read_cpsr = 0;                                  \
                    asm volatile(                                               \
                        "MRS    %0, CPSR\n\r"                                   \
                        "BIC    %0, %0, 0xC0\n\r"                               \
                        "ORR    %0, %0, %2\n\r"                                 \
                        "MSR     CPSR_c, %0\n\r"                                \
                        :"=r"(read_cpsr)                                        \
                        :"0"(read_cpsr), "r"(write_cpsr)                        \
                    );                                                          \
                }while(0)
#else  /* __PROTECT_OPTIMIZE__ && __GNUC__ */
#define         TCC_INTERRUPTS_RESTORE()                                        \
                        ESAL_GE_INT_BITS_SET(TCD_Interrupt_Level)
#endif /* __PROTECT_OPTIMIZE__ && __GNUC__ */
#else /* (NU_GLOBAL_INT_LOCKING == NU_TRUE) */

/* The following macro is used to enable interrupts globally.  This macro is used
   in the scheduler and within the HISR shell routine. */
#define         TCC_INTERRUPTS_GLOBAL_ENABLE()                                  \
                        ESAL_GE_INT_FAST_ALL_ENABLE()

/* The following macro locks out interrupts and saves the state before
   locking-out.  It is used to guard critical sections of code and is always
   paired with the macro TCC_INTERRUPTS_RESTORE defined below. */
#if defined(__PROTECT_OPTIMIZE__) && defined(__GNUC__)
#define         TCC_INTERRUPTS_DISABLE()                                        \
                do{                                                             \
                    NU_UNSIGNED write_cpsr = ESAL_AR_INT_CPSR_SYS_DISABLED;     \
                    asm volatile(                                               \
                        "MRS    %0, CPSR\n\r"                                   \
                        "MSR	 CPSR_c, %1\n\r"                                \
                        :"=r"(esal_ar_int_tmp), "=r"(write_cpsr)                \
                        :"1"(write_cpsr)                                        \
                        :"memory"                                               \
                    );                                                          \
                }while(0)
#else  /* __PROTECT_OPTIMIZE__ && __GNUC__ */
#define         TCC_INTERRUPTS_DISABLE()                                        \
                        ESAL_GE_INT_ALL_DISABLE()
#endif /* __PROTECT_OPTIMIZE__ && __GNUC__ */


/* The following macro sets the interrupt lock-out level to entry level saved
   by TCC_INTERRUPTS_LOCK.  This macro is used at the end of critical
   sections where a context switch may have occurred.  This macro is always
   paired with the macro TCC_INTERRUPTS_LOCK defined above. */
#if defined(__PROTECT_OPTIMIZE__) && defined(__GNUC__)
#define         TCC_INTERRUPTS_RESTORE()                                        \
                do{                                                             \
                    asm volatile(                                               \
                        "MSR     CPSR_c, %0\n\r"                                \
                        :                                                       \
                        :"r"(esal_ar_int_tmp)                                   \
                    );                                                          \
                }while(0);
#else  /* __PROTECT_OPTIMIZE__ && __GNUC__ */
#define         TCC_INTERRUPTS_RESTORE()                                        \
                        ESAL_GE_INT_ALL_RESTORE()
#endif /* __PROTECT_OPTIMIZE__ && __GNUC__ */

#endif  /* NU_GLOBAL_INT_LOCKING == NU_TRUE */

/* Nucleus PLUS Timing Test 2 macros / external declarations */
#if (NU_TIME_TEST2_ENABLE == NU_TRUE)

/* Include timing test header file */
#include        "plus_timing/test2/test2_defs.h"

#else

/* Define macro to do nothing */
#define         NU_PLUS_TIMING_TEST2()      (NU_VOID)0

#endif  /* (NU_TIME_TEST2_ENABLE == NU_TRUE) */

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif  /* !TC_EXTR */
