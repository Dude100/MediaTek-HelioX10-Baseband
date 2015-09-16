/*************************************************************************/
/*                                                                       */
/*        Copyright (c) 1993-2001 Accelerated Technology, Inc.           */
/*                                                                       */
/* PROPRIETARY RIGHTS of Accelerated Technology are involved in the      */
/* subject matter of this material.  All manufacturing, reproduction,    */
/* use, and sales rights pertaining to this subject matter are governed  */
/* by the license agreement.  The recipient of this software implicitly  */
/* accepts the terms of the license.                                     */
/*                                                                       */
/*************************************************************************/

/*************************************************************************/
/*                                                                       */
/* FILE NAME                                            VERSION          */
/*                                                                       */
/*      mb_extr.h                                       PLUS  1.13       */
/*                                                                       */
/* COMPONENT                                                             */
/*                                                                       */
/*      MB - Mailbox Management                                          */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This file contains function prototypes of all functions          */
/*      accessible to other components.                                  */
/*                                                                       */
/* AUTHOR                                                                */
/*                                                                       */
/*      Accelerated Technology, Inc.                                     */
/*                                                                       */
/* DATA STRUCTURES                                                       */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/* FUNCTIONS                                                             */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/* DEPENDENCIES                                                          */
/*                                                                       */
/*      mb_defs.h                           Mailbox Management constants */
/*                                                                       */
/* HISTORY                                                               */
/*                                                                       */
/*        DATE                    REMARKS                                */
/*                                                                       */
/*      03-01-1993      Created initial version 1.0                      */
/*      04-19-1993      Verified version 1.0                             */
/*      03-01-1994      Moved include files outside of                   */
/*                      the file #ifndef to allow the                    */
/*                      use of actual data structures,                   */
/*                      changed the names of several                     */
/*                      mailboxes services to reflect                    */
/*                      the new file structure,                          */
/*                      modified function interface to                   */
/*                      exactly match the prototype,                     */
/*                      resulting in version 1.1                         */
/*                                                                       */
/*      03-18-1994      Verified version 1.1                             */
/*      04-17-1996      updated to version 1.2                           */
/*      03-24-1998      Released version 1.3                             */
/*                                                                       */
/*************************************************************************/
/*=========================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*--------------------------------------------------------------------------
* $Revision$
* $Modtime$
* $Log$
*
* 03 19 2014 hc.yang
 * removed!
* .
*
*--------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*========================================================================*/

#include        "mb_defs.h"                 /* Include MB constants      */


/* Check to see if the file has been included already.  */

#ifndef MB_EXTR
#define MB_EXTR


/*  Initialization functions.  */

VOID            MBI_Initialize(VOID);


/* Core error checking functions.  */

STATUS          MBCE_Create_Mailbox(NU_MAILBOX *mailbox_ptr, CHAR *name, 
                                                OPTION suspend_type);
STATUS          MBCE_Delete_Mailbox(NU_MAILBOX *mailbox_ptr);
STATUS          MBCE_Send_To_Mailbox(NU_MAILBOX *mailbox_ptr, VOID *message, 
                                                        UNSIGNED suspend);
STATUS          MBCE_Receive_From_Mailbox(NU_MAILBOX *mailbox_ptr, 
                                        VOID *message, UNSIGNED suspend);

/* Supplemental error checking functions.  */

STATUS          MBSE_Reset_Mailbox(NU_MAILBOX *mailbox_ptr);
STATUS          MBSE_Broadcast_To_Mailbox(NU_MAILBOX *mailbox_ptr, 
                                        VOID *message, UNSIGNED suspend);

/* Core processing functions.  */

STATUS          MBC_Create_Mailbox(NU_MAILBOX *mailbox_ptr, CHAR *name, 
                                                OPTION suspend_type);
STATUS          MBC_Delete_Mailbox(NU_MAILBOX *mailbox_ptr);
STATUS          MBC_Send_To_Mailbox(NU_MAILBOX *mailbox_ptr, VOID *message, 
                                                        UNSIGNED suspend);
STATUS          MBC_Receive_From_Mailbox(NU_MAILBOX *mailbox_ptr, 
                                        VOID *message, UNSIGNED suspend);

/* Supplemental mailbox functions.  */

STATUS          MBS_Reset_Mailbox(NU_MAILBOX *mailbox_ptr);
STATUS          MBS_Broadcast_To_Mailbox(NU_MAILBOX *mailbox_ptr, 
                                        VOID *message, UNSIGNED suspend);

/* Mailbox fact retrieval functions.  */

UNSIGNED        MBF_Established_Mailboxes(VOID);
STATUS          MBF_Mailbox_Information(NU_MAILBOX *mailbox_ptr, CHAR *name, 
                  OPTION *suspend_type, DATA_ELEMENT *message_present,
                  UNSIGNED *tasks_waiting, NU_TASK **first_task);
UNSIGNED        MBF_Mailbox_Pointers(NU_MAILBOX **pointer_list, 
                                                UNSIGNED maximum_pointers);

#endif


