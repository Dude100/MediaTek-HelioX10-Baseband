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
*       sm_extr.h
*
*   COMPONENT
*
*       SM - Semaphore Management
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
*       sm_defs.h                           Semaphore Management
*                                           constant
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

#include        "sm_defs.h"        /* Include SM constants      */


/* Check to see if the file has been included already.  */

#ifndef SM_EXTR
#define SM_EXTR

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Error checking core functions.  */

NU_STATE          SMCE_Create_Semaphore(NU_SEMAPHORE *semaphore_ptr, NU_CHAR *name,
                        NU_UNSIGNED initial_count, NU_OPTION suspend_type);
NU_STATE          SMCE_Delete_Semaphore(NU_SEMAPHORE *semaphore_ptr);
NU_STATE          SMCE_Obtain_Semaphore(NU_SEMAPHORE *semaphore_ptr,
                                                        NU_UNSIGNED suspend);
NU_STATE          SMCE_Release_Semaphore(NU_SEMAPHORE *semaphore_ptr);


/* Error checking supplemental functions.  */

NU_STATE          SMSE_Reset_Semaphore(NU_SEMAPHORE *semaphore_ptr,
                                                    NU_UNSIGNED initial_count);


/* Core processing functions.  */

NU_STATE          SMC_Create_Semaphore(NU_SEMAPHORE *semaphore_ptr, NU_CHAR *name,
                        NU_UNSIGNED initial_count, NU_OPTION suspend_type);
NU_STATE          SMC_Delete_Semaphore(NU_SEMAPHORE *semaphore_ptr);
NU_STATE          SMC_Obtain_Semaphore(NU_SEMAPHORE *semaphore_ptr,
                                                        NU_UNSIGNED suspend);
NU_STATE          SMC_Release_Semaphore(NU_SEMAPHORE *semaphore_ptr);


/* Supplemental processing functions.  */

NU_STATE          SMS_Reset_Semaphore(NU_SEMAPHORE *semaphore_ptr,
                                                NU_UNSIGNED initial_count);


/* Information retrieval functions.  */

NU_UNSIGNED        SMF_Established_Semaphores(NU_VOID);
NU_STATE          SMF_Semaphore_Information(NU_SEMAPHORE *semaphore_ptr,
                  NU_CHAR *name, NU_UNSIGNED *current_count, NU_OPTION *suspend_type,
                  NU_UNSIGNED *tasks_waiting, NU_TASK **first_task);
NU_UNSIGNED        SMF_Semaphore_Pointers(NU_SEMAPHORE **pointer_list,
                                                NU_UNSIGNED maximum_pointers);

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif
