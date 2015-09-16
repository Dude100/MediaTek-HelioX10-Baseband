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
*       esal_ge_cfg.h
*
*   COMPONENT
*
*       ESAL - Embedded Software Abstraction Layer
*
*   DESCRIPTION
*
*       This file contains required configuration settings generic to
*       all components of ESAL.  These configuration settings may be
*       used by external components.
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

#ifndef         ESAL_GE_CFG_H
#define         ESAL_GE_CFG_H

/* Define if code / data necessary to execute from ROM is enabled within
   the Embedded Software Abstraction Layer */
#ifndef ESAL_GE_ROM_SUPPORT_ENABLED
#define         ESAL_GE_ROM_SUPPORT_ENABLED             ESAL_FALSE
#endif /* ESAL_GE_ROM_SUPPORT_ENABLED */

/* Define if code is set-up to be optimized for size.  If set to
   ESAL_TRUE, generic code will be optimized for size when possible.
   When set to ESAL_FALSE, generic code will be optimized for speed.  */
#define         ESAL_GE_OPTIMIZE_SIZE                   ESAL_FALSE

/* Define if memory related utility functions are included.  If set to
   ESAL_TRUE, the utility functions will be included.  If set to ESAL_FALSE,
   these functions will not be included. */
#define         ESAL_GE_MEM_UTIL_INCLUDE                ESAL_TRUE

#define         ESAL_GE_32BIT_ACCESS                    1

#endif  /* ESAL_GE_CFG_H */
