/***********************************************************************
*
*             Copyright 1993-2006 Mentor Graphics Corporation
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
*       esal_ar_tmr_defs.h
*
*   COMPONENT
*
*       ESAL - Embedded Software Abstraction Layer
*
*   DESCRIPTION
*
*       This file contains the architecture specific definitions,
*       structures, assembly macros, etc, related to timers
*
*   DATA STRUCTURES
*
*       None
*
*   DEPENDENCIES
*
*       None
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

#ifndef         ESAL_AR_TMR_DEFS_H
#define         ESAL_AR_TMR_DEFS_H

/* The following definitions / macros / etc are only used if the architecture
   is configured (in esal_ar_cfg.h) to use an architecture level timer for
   the OS timer. */
#if (ESAL_AR_OS_TIMER_USED == ESAL_TRUE)

#error  No Architecture level timer exists for ARM.  Please check settings in esal_ar_cfg.h

#endif  /* ESAL_AR_OS_TIMER_USED == ESAL_TRUE */

#endif  /* ESAL_AR_TMR_DEFS_H */
