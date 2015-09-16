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
*       mb_defs.h
*
*   COMPONENT
*
*       MB - Mailbox Management
*
*   DESCRIPTION
*
*       This file contains data structure definitions and constants for
*       the message Mailbox component.
*
*   DATA STRUCTURES
*
*       MB_MCB                              Mailbox control block
*       MB_SUSPEND                          Mailbox suspension block
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

#ifndef MB_DEFS
#define MB_DEFS

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Define constants local to this component.  */

#define         MB_MAILBOX_ID           0x4d424f58UL
#define         MB_MESSAGE_SIZE         4


/* Define the Mailbox Control Block data type.  */

typedef struct MB_MCB_STRUCT
{
    CS_NODE             mb_created;            /* Node for linking to    */
                                               /*   created mailbox list */
    NU_UNSIGNED            mb_id;                 /* Internal MCB ID        */
    NU_CHAR                mb_name[NU_MAX_NAME];  /* Mailbox name           */
    NU_BOOLEAN             mb_message_present;    /* Message present flag   */
    NU_BOOLEAN             mb_fifo_suspend;       /* Suspension type flag   */
#if     PAD_2
    NU_DATA_ELEMENT        mb_padding[PAD_2];
#endif
    NU_UNSIGNED            mb_tasks_waiting;      /* Number of waiting tasks*/
    NU_UNSIGNED                                   /* Message area           */
                        mb_message_area[MB_MESSAGE_SIZE];
    struct MB_SUSPEND_STRUCT
                       *mb_suspension_list;    /* Suspension list        */
} MB_MCB;


/* Define the mailbox suspension structure.  This structure is allocated off of
   the caller's stack.  */

typedef struct MB_SUSPEND_STRUCT
{
    CS_NODE             mb_suspend_link;       /* Link to suspend blocks */
    MB_MCB             *mb_mailbox;            /* Pointer to the mailbox */
    TC_TCB             *mb_suspended_task;     /* Task suspended         */
    NU_UNSIGNED           *mb_message_area;       /* Pointer to message area*/
    NU_STATE              mb_return_status;      /* Return status          */
} MB_SUSPEND;

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif
