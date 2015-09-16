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
*       ev_defs.h
*
*   COMPONENT
*
*       EV - Event Group Management
*
*   DESCRIPTION
*
*       This file contains data structure definitions and constants for
*       the Event Flag Group component.
*
*   DATA STRUCTURES
*
*       EV_GCB                              Event Group control block
*       EV_SUSPEND                          Event Group suspension block
*
*   DEPENDENCIES
*
*       cs_defs.h                           Common service definitions
*       tc_defs.h                           Thread Control definitions
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
#include        "tc_defs.h"        /* Thread control constants  */


/* Check to see if the file has been included already.  */

#ifndef EV_DEFS
#define EV_DEFS

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Define constants local to this component.  */

#define         EV_EVENT_ID         0x45564e54UL
#define         EV_AND              0x2
#define         EV_CONSUME          0x1


/* Define the Event Group Control Block data type.  */

typedef struct EV_GCB_STRUCT
{
    CS_NODE             ev_created;            /* Node for linking to    */
                                               /*   created Events list  */
    NU_UNSIGNED            ev_id;                 /* Internal EV ID         */
    NU_CHAR                ev_name[NU_MAX_NAME];  /* Event group name       */
    NU_UNSIGNED            ev_current_events;     /* Current event flags    */
    NU_UNSIGNED            ev_tasks_waiting;      /* Number of waiting tasks*/
    struct EV_SUSPEND_STRUCT
                       *ev_suspension_list;    /* Suspension list        */
} EV_GCB;


/* Define the Event Group suspension structure.  This structure is allocated
   off of the caller's stack.  */

typedef struct EV_SUSPEND_STRUCT
{
    CS_NODE             ev_suspend_link;       /* Link to suspend blocks */
    EV_GCB             *ev_event_group;        /* Pointer to Event group */
    NU_UNSIGNED            ev_requested_events;   /* Requested event flags  */
    NU_DATA_ELEMENT        ev_operation;          /* Event operation        */
#if     PAD_1
    NU_DATA_ELEMENT        ev_padding[PAD_1];
#endif
    TC_TCB             *ev_suspended_task;     /* Task suspended         */
    NU_STATE              ev_return_status;      /* Return status          */
    NU_UNSIGNED            ev_actual_events;      /* Event flags returned   */
} EV_SUSPEND;

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif
