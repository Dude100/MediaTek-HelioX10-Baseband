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
*       in_defs.h
*
*   COMPONENT
*
*       IN - Initialization
*
*   DESCRIPTION
*
*       This file contains data structure definitions and constants for
*       the Initialization component.
*
*   DATA STRUCTURES
*
*       None
*
*   DEPENDENCIES
*
*       nucleus.h                           System definitions
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

#include        "nucleus.h"            /* Include system constants  */

/* Check to see if the file has been included already.  */

#ifndef IN_DEFS
#define IN_DEFS

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Constants used to indicate start and end of initialization for Nucleus PLUS. */
#define INC_START_INITIALIZE                0
#define INC_END_INITIALIZE                  2

/* Define the percent of memory that will be put into the uncached system memory pool
   if all memory is uncached.  The remaining memory will be put in the system memory pool.
   NOTE:  Since most applications utilize the system memory pool for the majority
          of the allocations, the uncached memory pool percentage is kept small.  The
          uncached memory pool is usually only used by drivers requiring uncached memory */
#define INC_USYS_MEMORY_PERCENT             20UL

/* Define the period of the Nucleus PLUS LV */
#define INC_LV_TIMEOUT_IN_MINUTES           60

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif /* IN_DEFS */
