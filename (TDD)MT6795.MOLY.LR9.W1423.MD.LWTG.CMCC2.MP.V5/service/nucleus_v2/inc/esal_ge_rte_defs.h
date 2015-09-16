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
*       esal_ge_rte_defs.h
*
*   COMPONENT
*
*       ESAL - Embedded Software Abstraction Layer
*
*   DESCRIPTION
*
*       This file contains generic defines, structures, data types, etc
*       related to run-time environment requirements
*
*   DATA STRUCTURES
*
*       None
*
*   DEPENDENCIES
*
*       esal_ts_rte_defs.h                  Embedded Software
*                                           Abstraction Layer toolset
*                                           run-time environment defs
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

#ifndef             ESAL_GE_RTE_DEFS_H
#define             ESAL_GE_RTE_DEFS_H

/* Include required header files */
#include            "esal_ts_rte_defs.h"

/* Map generic APIs to lower-level component */
#define             ESAL_GE_RTE_SP_READ        ESAL_TS_RTE_SP_READ

/* Define all run-time environment related function prototypes */
ESAL_VOID                ESAL_GE_RTE_Initialize(ESAL_VOID);
ESAL_VOID                ESAL_TS_RTE_Lowlevel_Initialize(ESAL_VOID);
ESAL_VOID                ESAL_TS_RTE_Initialize(ESAL_VOID);

#endif  /* ESAL_GE_RTE_DEFS_H */
