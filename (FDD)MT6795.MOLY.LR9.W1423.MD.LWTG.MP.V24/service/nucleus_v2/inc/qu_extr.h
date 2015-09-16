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
*       qu_extr.h
*
*   COMPONENT
*
*       QU - Queue Management
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
*       qu_defs.h                           Queue Management constants
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

#include        "qu_defs.h"        /* Include QU constants      */


/* Check to see if the file has been included already.  */

#ifndef QU_EXTR
#define QU_EXTR

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Core error checking functions.  */

NU_STATE          QUCE_Create_Queue(NU_QUEUE *queue_ptr, NU_CHAR *name,
                      NU_VOID *start_address, NU_UNSIGNED queue_size,
                      NU_OPTION message_type, NU_UNSIGNED message_size,
                      NU_OPTION suspend_type);
NU_STATE          QUCE_Delete_Queue(NU_QUEUE *queue_ptr);
NU_STATE          QUCE_Send_To_Queue(NU_QUEUE *queue_ptr, NU_VOID *message,
                                        NU_UNSIGNED size, NU_UNSIGNED suspend);
NU_STATE          QUCE_Receive_From_Queue(NU_QUEUE *queue_ptr, NU_VOID *message,
                      NU_UNSIGNED size, NU_UNSIGNED *actual_size, NU_UNSIGNED suspend);

/* Supplemental error checking functions.  */

NU_STATE          QUSE_Reset_Queue(NU_QUEUE *queue_ptr);
NU_STATE          QUSE_Send_To_Front_Of_Queue(NU_QUEUE *queue_ptr, NU_VOID *message,
                                        NU_UNSIGNED size, NU_UNSIGNED suspend);
NU_STATE          QUSE_Broadcast_To_Queue(NU_QUEUE *queue_ptr, NU_VOID *message,
                                        NU_UNSIGNED size, NU_UNSIGNED suspend);

/* Core processing functions.  */

NU_STATE          QUC_Create_Queue(NU_QUEUE *queue_ptr, NU_CHAR *name,
                      NU_VOID *start_address, NU_UNSIGNED queue_size,
                      NU_OPTION message_type, NU_UNSIGNED message_size,
                      NU_OPTION suspend_type);
NU_STATE          QUC_Delete_Queue(NU_QUEUE *queue_ptr);
NU_STATE          QUC_Send_To_Queue(NU_QUEUE *queue_ptr, NU_VOID *message,
                                        NU_UNSIGNED size, NU_UNSIGNED suspend);
NU_STATE          QUC_Receive_From_Queue(NU_QUEUE *queue_ptr, NU_VOID *message,
                      NU_UNSIGNED size, NU_UNSIGNED *actual_size, NU_UNSIGNED suspend);

/* Supplemental processing functions.  */

NU_STATE          QUS_Reset_Queue(NU_QUEUE *queue_ptr);
NU_STATE          QUS_Send_To_Front_Of_Queue(NU_QUEUE *queue_ptr, NU_VOID *message,
                                        NU_UNSIGNED size, NU_UNSIGNED suspend);
NU_STATE          QUS_Broadcast_To_Queue(NU_QUEUE *queue_ptr, NU_VOID *message,
                                        NU_UNSIGNED size, NU_UNSIGNED suspend);

/* Information gathering functions.  */


NU_UNSIGNED        QUF_Established_Queues(NU_VOID);
NU_STATE          QUF_Queue_Information(NU_QUEUE *queue_ptr, NU_CHAR *name,
                  NU_VOID **start_address, NU_UNSIGNED *queue_size,
                  NU_UNSIGNED *available, NU_UNSIGNED *messages,
                  NU_OPTION *message_type, NU_UNSIGNED *message_size,
                  NU_OPTION *suspend_type, NU_UNSIGNED *tasks_waiting,
                  NU_TASK **first_task);
NU_UNSIGNED        QUF_Queue_Pointers(NU_QUEUE **pointer_list,
                                                NU_UNSIGNED maximum_pointers);

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif
