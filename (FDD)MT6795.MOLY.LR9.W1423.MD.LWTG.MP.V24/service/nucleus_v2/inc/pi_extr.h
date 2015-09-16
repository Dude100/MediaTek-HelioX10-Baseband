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
*       pi_extr.h
*
*   COMPONENT
*
*       PI - Pipe Management
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
*       pi_defs.h                           Pipe Management constants
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

#include        "pi_defs.h"        /* Include Pipe constants    */


/* Check to see if the file has been included already.  */

#ifndef PI_EXTR
#define PI_EXTR

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Error checking core functions.  */

NU_STATE          PICE_Create_Pipe(NU_PIPE *pipe_ptr, NU_CHAR *name,
                      NU_VOID *start_address, NU_UNSIGNED pipe_size,
                      NU_OPTION message_type, NU_UNSIGNED message_size,
                      NU_OPTION suspend_type);
NU_STATE          PICE_Delete_Pipe(NU_PIPE *pipe_ptr);
NU_STATE          PICE_Send_To_Pipe(NU_PIPE *pipe_ptr, NU_VOID *message,
                                        NU_UNSIGNED size, NU_UNSIGNED suspend);
NU_STATE          PICE_Receive_From_Pipe(NU_PIPE *pipe_ptr, NU_VOID *message,
                      NU_UNSIGNED size, NU_UNSIGNED *actual_size, NU_UNSIGNED suspend);


/* Error checking supplemental functions.  */

NU_STATE          PISE_Reset_Pipe(NU_PIPE *pipe_ptr);
NU_STATE          PISE_Send_To_Front_Of_Pipe(NU_PIPE *pipe_ptr, NU_VOID *message,
                                        NU_UNSIGNED size, NU_UNSIGNED suspend);
NU_STATE          PISE_Broadcast_To_Pipe(NU_PIPE *pipe_ptr, NU_VOID *message,
                                        NU_UNSIGNED size, NU_UNSIGNED suspend);


/* Core processing functions.  */

NU_STATE          PIC_Create_Pipe(NU_PIPE *pipe_ptr, NU_CHAR *name,
                      NU_VOID *start_address, NU_UNSIGNED pipe_size,
                      NU_OPTION message_type, NU_UNSIGNED message_size,
                      NU_OPTION suspend_type);
NU_STATE          PIC_Delete_Pipe(NU_PIPE *pipe_ptr);
NU_STATE          PIC_Send_To_Pipe(NU_PIPE *pipe_ptr, NU_VOID *message,
                                        NU_UNSIGNED size, NU_UNSIGNED suspend);
NU_STATE          PIC_Receive_From_Pipe(NU_PIPE *pipe_ptr, NU_VOID *message,
                      NU_UNSIGNED size, NU_UNSIGNED *actual_size, NU_UNSIGNED suspend);


/* Supplemental processing functions.  */

NU_STATE          PIS_Reset_Pipe(NU_PIPE *pipe_ptr);
NU_STATE          PIS_Send_To_Front_Of_Pipe(NU_PIPE *pipe_ptr, NU_VOID *message,
                                        NU_UNSIGNED size, NU_UNSIGNED suspend);
NU_STATE          PIS_Broadcast_To_Pipe(NU_PIPE *pipe_ptr, NU_VOID *message,
                                        NU_UNSIGNED size, NU_UNSIGNED suspend);


/* Information retrieval functions.  */

NU_UNSIGNED        PIF_Established_Pipes(NU_VOID);
NU_STATE          PIF_Pipe_Information(NU_PIPE *pipe_ptr, NU_CHAR *name,
                  NU_VOID **start_address, NU_UNSIGNED *pipe_size,
                  NU_UNSIGNED *available, NU_UNSIGNED *messages,
                  NU_OPTION *message_type, NU_UNSIGNED *message_size,
                  NU_OPTION *suspend_type, NU_UNSIGNED *tasks_waiting,
                  NU_TASK **first_task);
NU_UNSIGNED        PIF_Pipe_Pointers(NU_PIPE **pointer_list,
                                                NU_UNSIGNED maximum_pointers);

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif
