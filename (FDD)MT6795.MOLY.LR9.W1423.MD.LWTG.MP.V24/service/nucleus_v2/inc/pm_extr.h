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
*       pm_extr.h
*
*   COMPONENT
*
*       PM - Partition Memory Management
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
*       pm_defs.h                           Partition Management const.
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

#include        "pm_defs.h"        /* Include PM constants      */


/* Check to see if the file has been included already.  */

#ifndef PM_EXTR
#define PM_EXTR

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Core error checking functions.  */

NU_STATE          PMCE_Create_Partition_Pool(NU_PARTITION_POOL *pool_ptr,
                        NU_CHAR *name, NU_VOID *start_address, NU_UNSIGNED pool_size,
                        NU_UNSIGNED partition_size, NU_OPTION suspend_type);
NU_STATE          PMCE_Delete_Partition_Pool(NU_PARTITION_POOL *pool_ptr);
NU_STATE          PMCE_Allocate_Partition(NU_PARTITION_POOL *pool_ptr,
                        NU_VOID **return_pointer, NU_UNSIGNED suspend);
NU_STATE          PMCE_Deallocate_Partition(NU_VOID *partition);


/* Core processing functions.  */

NU_STATE          PMC_Create_Partition_Pool(NU_PARTITION_POOL *pool_ptr,
                        NU_CHAR *name, NU_VOID *start_address, NU_UNSIGNED pool_size,
                        NU_UNSIGNED partition_size, NU_OPTION suspend_type);
NU_STATE          PMC_Delete_Partition_Pool(NU_PARTITION_POOL *pool_ptr);
NU_STATE          PMC_Allocate_Partition(NU_PARTITION_POOL *pool_ptr,
                        NU_VOID **return_pointer, NU_UNSIGNED suspend);
NU_STATE          PMC_Deallocate_Partition(NU_VOID *partition);


/* Information retrieval functions.  */

NU_UNSIGNED        PMF_Established_Partition_Pools(NU_VOID);
NU_STATE          PMF_Partition_Pool_Information(NU_PARTITION_POOL *pool_ptr,
                  NU_CHAR *name, NU_VOID **start_address, NU_UNSIGNED *pool_size,
                  NU_UNSIGNED *partition_size, NU_UNSIGNED *available,
                  NU_UNSIGNED *allocated, NU_OPTION *suspend_type,
                  NU_UNSIGNED *tasks_waiting, NU_TASK **first_task);
NU_UNSIGNED        PMF_Partition_Pool_Pointers(NU_PARTITION_POOL **pointer_list,
                                                NU_UNSIGNED maximum_pointers);

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif
