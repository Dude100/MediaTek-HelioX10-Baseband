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
*       pm_defs.h
*
*   COMPONENT
*
*       PM - Partition Memory Management
*
*   DESCRIPTION
*
*       This file contains data structure definitions and constants for
*       the Partition Memory component.
*
*   DATA STRUCTURES
*
*       PM_PCB                              Partition Pool control
*                                           block
*       PM_HEADER                           Header of each partition
*       PM_SUSPEND                          Partition suspension block
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

#ifndef PM_DEFS
#define PM_DEFS

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Define constants local to this component.  */

#define         PM_PARTITION_ID         0x50415254UL
#define         PM_OVERHEAD             ((sizeof(PM_HEADER) + sizeof(NU_UNSIGNED) \
                                        - 1)/sizeof(NU_UNSIGNED)) *    \
                                        sizeof(NU_UNSIGNED)
#define         PM_PARTITION_ALLOCATED  0x50555345UL


/* Define the Partition Pool Control Block data type.  */

typedef struct PM_PCB_STRUCT
{
    CS_NODE             pm_created;            /* Node for linking to    */
                                               /* created partition list */
    NU_UNSIGNED            pm_id;                 /* Internal PCB ID        */
    NU_CHAR                pm_name[NU_MAX_NAME];  /* Partition Pool name    */
    NU_VOID               *pm_start_address;      /* Starting pool address  */
    NU_UNSIGNED            pm_pool_size;          /* Size of pool           */
    NU_UNSIGNED            pm_partition_size;     /* Size of each partition */
    NU_UNSIGNED            pm_available;          /* Available partitions   */
    NU_UNSIGNED            pm_allocated;          /* Allocated partitions   */
    struct PM_HEADER_STRUCT
                       *pm_available_list;     /* Available list         */
    NU_BOOLEAN             pm_fifo_suspend;       /* Suspension type flag   */
#if     PAD_1
    NU_DATA_ELEMENT        pm_padding[PAD_1];
#endif
    NU_UNSIGNED            pm_tasks_waiting;      /* Number of waiting tasks*/
    struct PM_SUSPEND_STRUCT
                       *pm_suspension_list;    /* Suspension list        */
} PM_PCB;


/* Define the header structure that is in front of each memory partition.  */

typedef struct PM_HEADER_STRUCT
{
    struct PM_HEADER_STRUCT
                       *pm_next_available;     /* Next available memory  */
                                               /*   partition            */
    PM_PCB             *pm_partition_pool;     /* Partition pool pointer */
} PM_HEADER;


/* Define the partition suspension structure.  This structure is allocated
   off of the caller's stack.  */

typedef struct PM_SUSPEND_STRUCT
{
    CS_NODE             pm_suspend_link;       /* Link to suspend blocks */
    PM_PCB             *pm_partition_pool;     /* Pointer to pool        */
    TC_TCB             *pm_suspended_task;     /* Task suspended         */
    NU_VOID               *pm_return_pointer;     /* Return memory address  */
    NU_STATE              pm_return_status;      /* Return status          */
} PM_SUSPEND;

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif
