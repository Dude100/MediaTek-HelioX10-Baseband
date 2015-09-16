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
*       hi_defs.h
*
*   COMPONENT
*
*       HI - History Management
*
*   DESCRIPTION
*
*       This file contains data structure definitions and constants for
*       the History Management component.
*
*   DATA STRUCTURES
*
*       HI_HISTORY_ENTRY                    Entry in the history table
*
*   DEPENDENCIES
*
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

#include        "tc_defs.h"        /* Thread control constants  */


/* Check to see if the file has been included already.  */

#ifndef HI_DEFS
#define HI_DEFS

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Define constants local to this component.  */

#define         HI_MAX_ENTRIES          30
#define         HI_TASK                 1
#define         HI_HISR                 2
#define         HI_INITIALIZE           3


/* Define the History Entry data type.  */

typedef struct HI_HISTORY_ENTRY_STRUCT
{
    NU_DATA_ELEMENT        hi_id;              /* ID of the history entry  */
    NU_DATA_ELEMENT        hi_caller;          /* Task, HISR, or Initialize*/
    NU_UNSIGNED            hi_param1;          /* First parameter          */
    NU_UNSIGNED            hi_param2;          /* Second parameter         */
    NU_UNSIGNED            hi_param3;          /* Third parameter          */
    NU_UNSIGNED            hi_time;            /* Clock tick time for entry*/
    NU_VOID               *hi_thread;          /* Calling thread's pointer */
} HI_HISTORY_ENTRY;

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif
