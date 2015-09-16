/*************************************************************************/
/*                                                                       */
/*        Copyright (c) 1993-2001 Accelerated Technology, Inc.           */
/*                                                                       */
/* PROPRIETARY RIGHTS of Accelerated Technology are involved in the      */
/* subject matter of this material.  All manufacturing, reproduction,    */
/* use, and sales rights pertaining to this subject matter are governed  */
/* by the license agreement.  The recipient of this software implicitly  */
/* accepts the terms of the license.                                     */
/*                                                                       */
/*************************************************************************/

/*************************************************************************/
/*                                                                       */
/* FILE NAME                                            VERSION          */
/*                                                                       */
/*      hi_defs.h                                       PLUS  1.13       */
/*                                                                       */
/* COMPONENT                                                             */
/*                                                                       */
/*      HI - History Management                                          */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This file contains data structure definitions and constants for  */
/*      the History Management component.                                */
/*                                                                       */
/* AUTHOR                                                                */
/*                                                                       */
/*      Accelerated Technology, Inc.                                     */
/*                                                                       */
/* DATA STRUCTURES                                                       */
/*                                                                       */
/*      HI_HISTORY_ENTRY                    Entry in the history table   */
/*                                                                       */
/* FUNCTIONS                                                             */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/* DEPENDENCIES                                                          */
/*                                                                       */
/*      tc_defs.h                           Thread Control definitions   */
/*                                                                       */
/* HISTORY                                                               */
/*                                                                       */
/*         DATE                    REMARKS                               */
/*                                                                       */
/*      03-01-1993      Created initial version 1.0                      */
/*      04-19-1993      Verified version 1.0                             */
/*      03-01-1994      Moved include files outside of                   */
/*                      the file #ifndef to allow the                    */
/*                      use of actual data structures,                   */
/*                      resulting in version 1.1                         */
/*                                                                       */
/*      03-18-1994      Verified version 1.1                             */
/*      04-17-1996      updated to version 1.2                           */
/*      03-24-1998      Released version 1.3                             */
/*************************************************************************/
/*=========================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*--------------------------------------------------------------------------
* $Revision$
* $Modtime$
* $Log$
*
* 03 19 2014 hc.yang
 * removed!
* .
*
*--------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*========================================================================*/

#include        "tc_defs.h"                 /* Thread control constants  */


/* Check to see if the file has been included already.  */

#ifndef HI_DEFS
#define HI_DEFS


/* Define constants local to this component.  */

#define         HI_MAX_ENTRIES          30
#define         HI_TASK                 1
#define         HI_HISR                 2
#define         HI_INITIALIZE           3


/* Define the History Entry data type.  */

typedef struct HI_HISTORY_ENTRY_STRUCT 
{
    DATA_ELEMENT        hi_id;              /* ID of the history entry  */
    DATA_ELEMENT        hi_caller;          /* Task, HISR, or Initialize*/
    UNSIGNED            hi_param1;          /* First parameter          */
    UNSIGNED            hi_param2;          /* Second parameter         */
    UNSIGNED            hi_param3;          /* Third parameter          */
    UNSIGNED            hi_time;            /* Clock tick time for entry*/
    VOID               *hi_thread;          /* Calling thread's pointer */
} HI_HISTORY_ENTRY;    

#ifdef INCLUDE_PROVIEW

#include "svagent\inc\rtprofil.h"
#include "svagent\inc\nuc_prof.h"

#ifndef PLUS
#define PLUS
#endif

#include "svagent\inc\rtlib.h"

#endif /*INCLUDE_PROVIEW*/

#endif


