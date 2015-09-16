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
*       ev_extr.h
*
*   COMPONENT
*
*       EV - Event Group Management
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
*       ev_defs.h                           Event Flag management consts
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

#include        "ev_defs.h"        /* Include EV constants      */


/* Check to see if the file has been included already.  */

#ifndef EV_EXTR
#define EV_EXTR

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Error checking functions.  */

NU_STATE          EVCE_Create_Event_Group(NU_EVENT_GROUP *group_ptr, NU_CHAR *name);
NU_STATE          EVCE_Delete_Event_Group(NU_EVENT_GROUP *group_ptr);
NU_STATE          EVCE_Set_Events(NU_EVENT_GROUP *group_ptr, NU_UNSIGNED events,
                                                NU_OPTION operation);
NU_STATE          EVCE_Retrieve_Events(NU_EVENT_GROUP *group_ptr,
                        NU_UNSIGNED requested_flags, NU_OPTION operation,
                        NU_UNSIGNED *retrieved_flags, NU_UNSIGNED suspend);

/* Core processing functions.  */


NU_STATE          EVC_Create_Event_Group(NU_EVENT_GROUP *group_ptr, NU_CHAR *name);
NU_STATE          EVC_Delete_Event_Group(NU_EVENT_GROUP *group_ptr);
NU_STATE          EVC_Set_Events(NU_EVENT_GROUP *group_ptr, NU_UNSIGNED events,
                                                NU_OPTION operation);
NU_STATE          EVC_Retrieve_Events(NU_EVENT_GROUP *group_ptr,
                        NU_UNSIGNED requested_flags, NU_OPTION operation,
                        NU_UNSIGNED *retrieved_flags, NU_UNSIGNED suspend);


/* Information retrieval functions.  */

NU_UNSIGNED        EVF_Established_Event_Groups(NU_VOID);
NU_STATE          EVF_Event_Group_Information(NU_EVENT_GROUP *group_ptr,
                        NU_CHAR *name, NU_UNSIGNED *event_flags,
                        NU_UNSIGNED *tasks_waiting, NU_TASK **first_task);
NU_UNSIGNED        EVF_Event_Group_Pointers(NU_EVENT_GROUP **pointer_list,
                                                NU_UNSIGNED maximum_pointers);

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif
