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
*       mb_extr.h
*
*   COMPONENT
*
*       MB - Mailbox Management
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
*       mb_defs.h                           Mailbox Management constants
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

#include        "mb_defs.h"        /* Include MB constants      */


/* Check to see if the file has been included already.  */

#ifndef MB_EXTR
#define MB_EXTR

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Core error checking functions.  */

NU_STATE          MBCE_Create_Mailbox(NU_MAILBOX *mailbox_ptr, NU_CHAR *name,
                                                NU_OPTION suspend_type);
NU_STATE          MBCE_Delete_Mailbox(NU_MAILBOX *mailbox_ptr);
NU_STATE          MBCE_Send_To_Mailbox(NU_MAILBOX *mailbox_ptr, NU_VOID *message,
                                                        NU_UNSIGNED suspend);
NU_STATE          MBCE_Receive_From_Mailbox(NU_MAILBOX *mailbox_ptr,
                                        NU_VOID *message, NU_UNSIGNED suspend);

/* Supplemental error checking functions.  */

NU_STATE          MBSE_Reset_Mailbox(NU_MAILBOX *mailbox_ptr);
NU_STATE          MBSE_Broadcast_To_Mailbox(NU_MAILBOX *mailbox_ptr,
                                        NU_VOID *message, NU_UNSIGNED suspend);

/* Core processing functions.  */

NU_STATE          MBC_Create_Mailbox(NU_MAILBOX *mailbox_ptr, NU_CHAR *name,
                                                NU_OPTION suspend_type);
NU_STATE          MBC_Delete_Mailbox(NU_MAILBOX *mailbox_ptr);
NU_STATE          MBC_Send_To_Mailbox(NU_MAILBOX *mailbox_ptr, NU_VOID *message,
                                                        NU_UNSIGNED suspend);
NU_STATE          MBC_Receive_From_Mailbox(NU_MAILBOX *mailbox_ptr,
                                        NU_VOID *message, NU_UNSIGNED suspend);

/* Supplemental mailbox functions.  */

NU_STATE          MBS_Reset_Mailbox(NU_MAILBOX *mailbox_ptr);
NU_STATE          MBS_Broadcast_To_Mailbox(NU_MAILBOX *mailbox_ptr,
                                        NU_VOID *message, NU_UNSIGNED suspend);

/* Mailbox fact retrieval functions.  */

NU_UNSIGNED        MBF_Established_Mailboxes(NU_VOID);
NU_STATE          MBF_Mailbox_Information(NU_MAILBOX *mailbox_ptr, NU_CHAR *name,
                  NU_OPTION *suspend_type, NU_DATA_ELEMENT *message_present,
                  NU_UNSIGNED *tasks_waiting, NU_TASK **first_task);
NU_UNSIGNED        MBF_Mailbox_Pointers(NU_MAILBOX **pointer_list,
                                                NU_UNSIGNED maximum_pointers);

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif
