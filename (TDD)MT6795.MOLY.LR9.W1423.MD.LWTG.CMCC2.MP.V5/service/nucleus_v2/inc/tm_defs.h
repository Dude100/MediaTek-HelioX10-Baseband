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
*       tm_defs.h
*
*   COMPONENT
*
*       TM - Timer Management
*
*   DESCRIPTION
*
*       This file contains data structure definitions and constants for
*       the Timer Management component.
*
*   DATA STRUCTURES
*
*       TM_TCB                              Timer control block
*       TM_APP_TCB                          Application timer control
*                                           block
*   DEPENDENCIES
*
*       cs_defs.h                           Common service definitions
*       tc_defs.h                           Thread control definitions
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


/* Check to see if the file has been included already.  */

#ifndef         TM_DEFS
#define         TM_DEFS

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Define constants local to this component.  */

#define         TM_TIMER_ID             0x54494d45UL
#define         TM_ACTIVE               0
#define         TM_NOT_ACTIVE           1
#define         TM_EXPIRED              2
#define         TM_TASK_TIMER           0
#define         TM_APPL_TIMER           1


#define OSTD_MAX_VALUE 0xffffffff

/* Define the Timer Control Block data type.  */

typedef struct TM_TCB_STRUCT
{
    NU_INT                 tm_timer_type;         /* Application/Task      */
    NU_UNSIGNED            tm_remaining_time;     /* Remaining time        */
    NU_VOID               *tm_information;        /* Information pointer   */
    struct TM_TCB_STRUCT
                       *tm_next_timer,         /* Next timer in list    */
                       *tm_previous_timer;     /* Previous timer in list*/
} TM_TCB;


/* Define Application's Timer Control Block data type.  */

typedef struct TM_APP_TCB_STRUCT
{
    CS_NODE             tm_created;            /* Node for linking to   */
                                               /*   created timer list  */
    NU_UNSIGNED            tm_id;                 /* Internal TCB ID       */
    NU_CHAR                tm_name[NU_MAX_NAME];  /* Timer name            */
    NU_VOID  (*tm_expiration_routine)(NU_UNSIGNED);  /* Expiration function   */
    NU_UNSIGNED            tm_expiration_id;      /* Expiration ID         */
    NU_BOOLEAN             tm_enabled;            /* Timer enabled flag    */

#if     PAD_1
    NU_DATA_ELEMENT        tc_padding[PAD_1];
#endif

    NU_UNSIGNED            tm_expirations;        /* Number of expirations */
    NU_UNSIGNED            tm_initial_time;       /* Initial time          */
    NU_UNSIGNED            tm_reschedule_time;    /* Reschedule time       */
    TM_TCB              tm_actual_timer;       /* Actual timer internals*/
} TM_APP_TCB;


/* Include this file here, since it contains references to the timer definition
   structure that is defined by this file.  */

#include        "tc_defs.h"

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif /* TM_DEFS */
