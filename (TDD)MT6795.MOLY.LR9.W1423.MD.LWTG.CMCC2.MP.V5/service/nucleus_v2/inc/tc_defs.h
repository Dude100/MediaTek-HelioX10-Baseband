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
*       tc_defs.h
*
*   COMPONENT
*
*       TC - Thread Control
*
*   DESCRIPTION
*
*       This file contains data structure definitions and constants for
*       the component that controls the various threads of execution in
*       system.  Threads include tasks, HISRs, signal handlers, etc.
*
*   DATA STRUCTURES
*
*       TC_TCB                              Task Control Block
*       TC_HCB                              HISR Control Block
*       TC_PROTECT                          Task/HISR protection struct
*
*   DEPENDENCIES
*
*       cs_defs.h                           Common service definitions
*       tm_defs.h                           Timer control definitions
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

#include        "cs_defs.h"        /* Common service constants  */
#include        "tm_defs.h"        /* Timer control structures  */


/* Check to see if the file has been included already.  */

#ifndef TC_DEFS
#define TC_DEFS

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Define constants local to this component.  */

#define         TC_TASK_ID              0x5441534bUL
#define         TC_HISR_ID              0x48495352UL
#define         TC_PRIORITIES           256
#ifdef __UNIFIED_ISR_LEVEL__
#define         TC_HISR_PRIORITIES      64
#else
#define         TC_HISR_PRIORITIES      3
#endif
#define         TC_HISR_MAX_GROUPS      ((TC_HISR_PRIORITIES+(8-1))/8)
#define         TC_MAX_GROUPS           ((TC_PRIORITIES+(8-1))/8)
#define         TC_HIGHEST_MASK         0x000000FFUL
#define         TC_NEXT_HIGHEST_MASK    0x0000FF00UL
#define         TC_NEXT_LOWEST_MASK     0x00FF0000UL
#define         TC_LOWEST_MASK          0xFF000000UL
#define         TC_MAX_HISR_ACTIVATIONS 0xFFFFFFFFUL
#define         TC_NO_THREAD_WAITING    0
#define         TC_THREAD_WAITING       1

/* Define the Task Control Block data type.  */

typedef struct TC_TCB_STRUCT
{
    /* Standard thread information first.  This information is used by
       the target dependent portion of this component.  Changes made
       to this area of the structure can have undesirable side effects.  */

    CS_NODE             tc_created;            /* Node for linking to    */
                                               /*   created task list    */
    NU_UNSIGNED            tc_id;                 /* Internal TCB ID        */
    NU_CHAR                tc_name[NU_MAX_NAME];  /* Task name              */
    NU_DATA_ELEMENT        tc_status;             /* Task status            */
    NU_BOOLEAN             tc_delayed_suspend;    /* Delayed task suspension*/
    NU_DATA_ELEMENT        tc_priority;           /* Task priority          */
    NU_BOOLEAN             tc_preemption;         /* Task preemption enable */
    NU_UNSIGNED            tc_scheduled;          /* Task scheduled count   */
    NU_UNSIGNED            tc_cur_time_slice;     /* Current time slice     */
    NU_VOID               *tc_stack_start;        /* Stack starting address */
    NU_VOID               *tc_stack_end;          /* Stack ending address   */
    NU_VOID               *tc_stack_pointer;      /* Task stack pointer     */
    NU_UNSIGNED            tc_stack_size;         /* Task stack's size      */
    NU_UNSIGNED            tc_stack_minimum;      /* Minimum stack size     */
    struct TC_PROTECT_STRUCT
                       *tc_current_protect;    /* Current protection     */

#if ((NU_SUPERV_USER_MODE == NU_TRUE) || (NU_MODULE_SUPPORT == NU_TRUE))

    /* This information is accessed in assembly */
    NU_UNSIGNED            tc_su_mode;            /* Supervisor/User mode indicator */
    struct MS_MODULE*   tc_module;             /* Module identifier */

#endif  /* (NU_SUPERV_USER_MODE == NU_TRUE) || (NU_MODULE_SUPPORT == NU_TRUE) */

    NU_VOID               *tc_saved_stack_ptr;    /* Previous stack pointer */
    NU_UNSIGNED            tc_time_slice;         /* Task time slice value  */

    /* Information after this point is not used in the target dependent
       portion of this component.  Hence, changes in the following section
       should not impact assembly language routines.  */
    struct TC_TCB_STRUCT
                       *tc_ready_previous,     /* Previously ready TCB   */
                       *tc_ready_next;         /* next and previous ptrs */

    /* Task control information follows.  */

    NU_UNSIGNED            tc_priority_group;     /* Priority group mask bit*/
    struct TC_TCB_STRUCT
                      **tc_priority_head;      /* Pointer to list head   */
    NU_DATA_ELEMENT       *tc_sub_priority_ptr;   /* Pointer to sub-group   */
    NU_DATA_ELEMENT        tc_sub_priority;       /* Mask of sub-group bit  */
    NU_DATA_ELEMENT        tc_saved_status;       /* Previous task status   */
    NU_BOOLEAN             tc_signal_active;      /* Signal active flag     */

#if     PAD_3
    NU_DATA_ELEMENT        tc_padding[PAD_3];
#endif

                                               /* Task entry function    */
    NU_VOID                (*tc_entry)(NU_UNSIGNED, NU_VOID *);
    NU_UNSIGNED            tc_argc;               /* Optional task argument */
    NU_VOID               *tc_argv;               /* Optional task argument */
    NU_VOID                (*tc_cleanup) (NU_VOID *);/* Clean-up routine       */
    NU_VOID               *tc_cleanup_info;       /* Clean-up information   */
    struct TC_PROTECT_STRUCT
                       *tc_suspend_protect;    /* Protection at time of  */
                                               /*   task suspension      */

    /* Task timer information.  */
    NU_INT                 tc_timer_active;       /* Active timer flag      */
    TM_TCB              tc_timer_control;      /* Timer control block    */

    /* Task signal control information.  */

    NU_UNSIGNED            tc_signals;            /* Current signals        */
    NU_UNSIGNED            tc_enabled_signals;    /* Enabled signals        */

    /* tc_saved_status and tc_signal_active are now defined above in an
       attempt to keep NU_DATA_ELEMENT types together.  */

    /* Signal handling routine.  */
    NU_VOID                (*tc_signal_handler) (NU_UNSIGNED);

    /* Reserved words for the system and a single reserved word for the
       application.  */
    NU_UNSIGNED            tc_system_reserved_1;  /* System reserved word   */
    NU_UNSIGNED            tc_system_reserved_2;  /* System reserved word   */
    NU_UNSIGNED            tc_system_reserved_3;  /* System reserved word   */
    NU_UNSIGNED            tc_app_reserved_1;     /* Application reserved   */

} TC_TCB;


/* Define the High-Level Interrupt Service Routine Control Block data type.  */

typedef struct TC_HCB_STRUCT
{
    /* Standard thread information first.  This information is used by
       the target dependent portion of this component.  Changes made
       to this area of the structure can have undesirable side effects.  */

    CS_NODE             tc_created;            /* Node for linking to    */
                                               /*   created task list    */
    NU_UNSIGNED            tc_id;                 /* Internal TCB ID        */
    NU_CHAR                tc_name[NU_MAX_NAME];  /* HISR name              */
    NU_DATA_ELEMENT        tc_not_used_1;         /* Not used field         */
    NU_DATA_ELEMENT        tc_not_used_2;         /* Not used field         */
    NU_DATA_ELEMENT        tc_priority;           /* HISR priority          */
    NU_DATA_ELEMENT        tc_not_used_3;         /* Not used field         */
    NU_UNSIGNED            tc_scheduled;          /* HISR scheduled count   */
    NU_UNSIGNED            tc_cur_time_slice;     /* Not used in HISR       */
    NU_VOID               *tc_stack_start;        /* Stack starting address */
    NU_VOID               *tc_stack_end;          /* Stack ending address   */
    NU_VOID               *tc_stack_pointer;      /* HISR stack pointer     */
    NU_UNSIGNED            tc_stack_size;         /* HISR stack's size      */
    NU_UNSIGNED            tc_stack_minimum;      /* Minimum stack size     */
    struct TC_PROTECT_STRUCT
                       *tc_current_protect;    /* Current protection     */

#if ((NU_SUPERV_USER_MODE == NU_TRUE) || (NU_MODULE_SUPPORT == NU_TRUE))

    /* This information is accessed in assembly */
    NU_UNSIGNED            tc_su_mode;            /* Supervisor/User mode indicator */
    struct MS_MODULE*   tc_module;             /* Module identifier */

#endif  /* (NU_SUPERV_USER_MODE == NU_TRUE) || (NU_MODULE_SUPPORT == NU_TRUE) */

    struct TC_HCB_STRUCT
                       *tc_active_next;        /* Next activated HISR    */
    NU_UNSIGNED            tc_activation_count;   /* Activation counter     */
    NU_VOID                (*tc_entry)(NU_VOID);     /* HISR entry function    */

    /* Information after this point is not used in the target dependent
       portion of this component.  Hence, changes in the following section
       should not impact assembly language routines.  */


    /* Reserved words for the system and a single reserved word for the
       application.  */
#ifdef __PRIORITY_SEARCH_OPTIMIZE__
    NU_UNSIGNED            tc_priority_group;     /* Priority group mask bit*/
    NU_DATA_ELEMENT       *tc_sub_priority_ptr;   /* Pointer to sub-group   */
    NU_DATA_ELEMENT        tc_sub_priority;
    NU_DATA_ELEMENT        tc_padding[3];
#else
    NU_UNSIGNED            tc_system_reserved_1;  /* System reserved word   */
    NU_UNSIGNED            tc_system_reserved_2;  /* System reserved word   */
    NU_UNSIGNED            tc_system_reserved_3;  /* System reserved word   */
#endif    
    NU_UNSIGNED            tc_app_reserved_1;     /* Application reserved   */

} TC_HCB;


/* Define the Task/HISR protection structure type.  */

typedef struct TC_PROTECT_STRUCT
{
    TC_TCB             *tc_tcb_pointer;        /* Owner of the protection */
    NU_UNSIGNED            tc_thread_waiting;     /* Waiting thread flag     */
} TC_PROTECT;

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif
