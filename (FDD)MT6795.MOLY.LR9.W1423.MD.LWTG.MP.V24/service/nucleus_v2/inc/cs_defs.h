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
*       cs_defs.h
*
*   COMPONENT
*
*       CS - Common Services
*
*   DESCRIPTION
*
*       This file contains data structure definitions used in the common
*       service linked list routines.
*
*   DATA STRUCTURES
*
*       CS_NODE                             Link node structure
*
*   DEPENDENCIES
*
*       nucleus.h                           Nucleus PLUS constants
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

#include        "nucleus.h"            /* Include Nucleus constants */


/* Check to see if the file has been included already.  */
#ifndef CS_DEFS
#define CS_DEFS

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Define a common node data structure that can be included inside of
   other system data structures.  */

typedef struct  CS_NODE_STRUCT
{
    struct CS_NODE_STRUCT  *cs_previous;
    struct CS_NODE_STRUCT  *cs_next;
    NU_DATA_ELEMENT            cs_priority;

#if     PAD_1
    NU_DATA_ELEMENT            cs_padding[PAD_1];
#endif

}  CS_NODE;

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif /* CS_DEFS */
