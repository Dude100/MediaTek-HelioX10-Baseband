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
*       esal_dp_cfg.h
*
*   COMPONENT
*
*       ESAL - Embedded Software Abstraction Layer
*
*   DESCRIPTION
*
*       This file contains required configuration settings for the
*       given development platform.  These configuration settings are
*       used by generic ESAL components and may be used by external
*       components.
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

#ifndef         ESAL_DP_CFG_H
#define         ESAL_DP_CFG_H

/* Define if an interrupt controller (off processor) exists on the board and
   controlling / handling of interrupts from this interrupt controller must
   be accommodated for.  Setting this to ESAL_FALSE means off-chip interrupts
   will NOT be controlled or handled.  Setting this to ESAL_TRUE means off-chip
   interrupts will be controlled and handled */
#define         ESAL_DP_INTERRUPTS_AVAILABLE            ESAL_FALSE

#endif  /* ESAL_DP_CFG_H */
