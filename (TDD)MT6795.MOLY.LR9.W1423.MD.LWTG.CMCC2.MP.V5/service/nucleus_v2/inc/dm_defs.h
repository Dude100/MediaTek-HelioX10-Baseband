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
*       dm_defs.h
*
*   COMPONENT
*
*       DM - Dynamic Memory Management
*
*   DESCRIPTION
*
*       This file contains data structure definitions and constants for
*       the Dynamic Memory component.
*
*   DATA STRUCTURES
*
*       DM_PCB                              Dynamic Pool control block
*       DM_HEADER                           Header of each memory block
*       DM_SUSPEND                          Memory suspension block
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

#ifndef DM_DEFS
#define DM_DEFS

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Adjust a size to something that is evenly divisible by the number of bytes
   in an NU_UNSIGNED data type.  */

#define DM_ADJUSTED_SIZE(size) \
  ((((size) + sizeof(NU_UNSIGNED) - 1)/sizeof(NU_UNSIGNED)) * sizeof(NU_UNSIGNED))

#define DM_ADJUSTED_ALIGNMENT(alignment) DM_ADJUSTED_SIZE(alignment)

/* Define constants local to this component.  */

#define         DM_DYNAMIC_ID          0x44594e41UL
#define         DM_OVERHEAD            ((sizeof(DM_HEADER) + sizeof(NU_UNSIGNED) \
                                        - 1)/sizeof(NU_UNSIGNED)) *    \
                                        sizeof(NU_UNSIGNED)


/* Define the Dynamic Pool Control Block data type.  */

typedef struct DM_PCB_STRUCT
{
    CS_NODE             dm_created;            /* Node for linking to    */
                                               /* created dynamic pools  */
    TC_PROTECT          dm_protect;            /* Protection structure   */
    NU_UNSIGNED            dm_id;                 /* Internal PCB ID        */
    NU_CHAR                dm_name[NU_MAX_NAME];  /* Dynamic Pool name      */
    NU_VOID               *dm_start_address;      /* Starting pool address  */
    NU_UNSIGNED            dm_pool_size;          /* Size of pool           */
    NU_UNSIGNED            dm_min_allocation;     /* Minimum allocate size  */
    NU_UNSIGNED            dm_available;          /* Total available bytes  */
    struct DM_HEADER_STRUCT
                       *dm_memory_list;        /* Memory list            */
    struct DM_HEADER_STRUCT
                       *dm_search_ptr;         /* Search pointer         */
    NU_BOOLEAN             dm_fifo_suspend;       /* Suspension type flag   */
#if     PAD_1
    NU_DATA_ELEMENT        dm_padding[PAD_1];
#endif
    NU_UNSIGNED            dm_tasks_waiting;      /* Number of waiting tasks*/
    struct DM_SUSPEND_STRUCT
                       *dm_suspension_list;    /* Suspension list        */
} DM_PCB;


/* Define the header structure that is in front of each memory block.  */

typedef struct DM_HEADER_STRUCT
{
    struct DM_HEADER_STRUCT
                       *dm_next_memory,        /* Next memory block      */
                       *dm_previous_memory;    /* Previous memory block  */
    NU_BOOLEAN             dm_memory_free;        /* Memory block free flag */
#if     PAD_1
    NU_DATA_ELEMENT        dm_padding[PAD_1];
#endif
    DM_PCB             *dm_memory_pool;        /* Dynamic pool pointer   */
} DM_HEADER;


/* Define the dynamic memory suspension structure.  This structure is
   allocated off of the caller's stack.  */

typedef struct DM_SUSPEND_STRUCT
{
    CS_NODE             dm_suspend_link;       /* Link to suspend blocks */
    DM_PCB             *dm_memory_pool;        /* Pointer to pool        */
    NU_UNSIGNED            dm_request_size;       /* Size of memory request */
    TC_TCB             *dm_suspended_task;     /* Task suspended         */
    NU_VOID               *dm_return_pointer;     /* Return memory address  */
    NU_STATE              dm_return_status;      /* Return status          */
} DM_SUSPEND;

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif
