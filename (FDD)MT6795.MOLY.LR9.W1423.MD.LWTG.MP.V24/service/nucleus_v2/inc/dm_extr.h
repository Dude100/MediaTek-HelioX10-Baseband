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
*       dm_extr.h
*
*   COMPONENT
*
*       DM - Dynamic Memory Management
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
*       dm_defs.h                           Dynamic Management constants
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

#include        "dm_defs.h"        /* Include DM constants      */


/* Check to see if the file has been included already.  */

#ifndef DM_EXTR
#define DM_EXTR

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Error checking functions.  */

NU_STATE          DMCE_Create_Memory_Pool(NU_MEMORY_POOL *pool_ptr, NU_CHAR *name,
                        NU_VOID *start_address, NU_UNSIGNED pool_size,
                        NU_UNSIGNED min_allocation, NU_OPTION suspend_type);
NU_STATE          DMCE_Delete_Memory_Pool(NU_MEMORY_POOL *pool_ptr);
NU_STATE          DMCE_Allocate_Memory(NU_MEMORY_POOL *pool_ptr, NU_VOID **return_pointer,
                                NU_UNSIGNED size, NU_UNSIGNED suspend);
NU_STATE          DMCE_Deallocate_Memory(NU_VOID *memory);


/* Core processing functions.  */

NU_STATE          DMC_Create_Memory_Pool(NU_MEMORY_POOL *pool_ptr, NU_CHAR *name,
                        NU_VOID *start_address, NU_UNSIGNED pool_size,
                        NU_UNSIGNED min_allocation, NU_OPTION suspend_type);
NU_STATE          DMC_Delete_Memory_Pool(NU_MEMORY_POOL *pool_ptr);
NU_STATE          DMC_Allocate_Memory(NU_MEMORY_POOL *pool_ptr,
                     NU_VOID **return_pointer, NU_UNSIGNED size, NU_UNSIGNED suspend);
NU_STATE          DMC_Deallocate_Memory(NU_VOID *memory);


/* Supplemental service routines */
NU_STATE DMS_Allocate_Aligned_Memory(NU_MEMORY_POOL *pool_ptr,
                                   NU_VOID **return_pointer, NU_UNSIGNED size,
                                   NU_UNSIGNED alignment, NU_UNSIGNED suspend);


/* Information retrieval functions.  */

NU_UNSIGNED        DMF_Established_Memory_Pools(NU_VOID);
NU_STATE          DMF_Memory_Pool_Information(NU_MEMORY_POOL *pool_ptr,
                  NU_CHAR *name, NU_VOID **start_address, NU_UNSIGNED *pool_size,
                  NU_UNSIGNED *min_allocation, NU_UNSIGNED *available,
                  NU_OPTION *suspend_type, NU_UNSIGNED *tasks_waiting,
                  NU_TASK **first_task);
NU_UNSIGNED        DMF_Memory_Pool_Pointers(NU_MEMORY_POOL **pointer_list,
                                                NU_UNSIGNED maximum_pointers);

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif
