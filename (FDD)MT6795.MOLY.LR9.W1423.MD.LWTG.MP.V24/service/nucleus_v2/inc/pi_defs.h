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
*       pi_defs.h
*
*   COMPONENT
*
*       PI - Pipe Management
*
*   DESCRIPTION
*
*       This file contains data structure definitions and constants for
*       the message Pipe component.
*
*   DATA STRUCTURES
*
*       PI_PCB                              Pipe control block
*       PI_SUSPEND                          Pipe suspension block
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

#ifndef PI_DEFS
#define PI_DEFS

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Define constants local to this component.  */

#define         PI_PIPE_ID              0x50495045UL


/* Define the Pipe Control Block data type.  */

typedef struct PI_PCB_STRUCT
{
    CS_NODE             pi_created;            /* Node for linking to    */
                                               /*   created pipe list    */
    NU_UNSIGNED            pi_id;                 /* Internal PCB ID        */
    NU_CHAR                pi_name[NU_MAX_NAME];  /* Pipe name              */
    NU_BOOLEAN             pi_fixed_size;         /* Fixed-size messages?   */
    NU_BOOLEAN             pi_fifo_suspend;       /* Suspension type flag   */
#if     PAD_2
    NU_DATA_ELEMENT        pi_padding[PAD_2];
#endif
    NU_UNSIGNED            pi_pipe_size;          /* Total size of pipe     */
    NU_UNSIGNED            pi_messages;           /* Messages in pipe       */
    NU_UNSIGNED            pi_message_size;       /* Size of each message   */
    NU_UNSIGNED            pi_available;          /* Available bytes        */
    NU_BYTE_PTR            pi_start;              /* Start of pipe area     */
    NU_BYTE_PTR            pi_end;                /* End of pipe area + 1   */
    NU_BYTE_PTR            pi_read;               /* Read pointer           */
    NU_BYTE_PTR            pi_write;              /* Write pointer          */
    NU_UNSIGNED            pi_tasks_waiting;      /* Number of waiting tasks*/
    struct PI_SUSPEND_STRUCT
                       *pi_urgent_list;        /* Urgent message suspend */
    struct PI_SUSPEND_STRUCT
                       *pi_suspension_list;    /* Suspension list        */
} PI_PCB;


/* Define the Pipe suspension structure.  This structure is allocated off of
   the caller's stack.  */

typedef struct PI_SUSPEND_STRUCT
{
    CS_NODE             pi_suspend_link;       /* Link to suspend blocks */
    PI_PCB             *pi_pipe;               /* Pointer to the pipe    */
    TC_TCB             *pi_suspended_task;     /* Task suspended         */
    NU_BYTE_PTR            pi_message_area;       /* Pointer to message area*/
    NU_UNSIGNED            pi_message_size;       /* Message size requested */
    NU_UNSIGNED            pi_actual_size;        /* Actual size of message */
    NU_STATE              pi_return_status;      /* Return status          */
} PI_SUSPEND;

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif
