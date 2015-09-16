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
*       esal_ge_com_defs.h
*
*   COMPONENT
*
*       ESAL - Embedded Software Abstraction Layer
*
*   DESCRIPTION
*
*       This file contains generic defines, structures, data types, etc
*       common to all Embedded Software Abstraction Layer components
*
*   DATA STRUCTURES
*
*       None
*
*   DEPENDENCIES
*
*       esal_ar_cfg.h                       Embedded Software
*                                           Abstraction Layer architecture
*                                           configuration settings
*       esal_co_cfg.h                       Embedded Software
*                                           Abstraction Layer core
*                                           configuration settings
*       esal_dp_cfg.h                       Embedded Software
*                                           Abstraction Layer dev platform
*                                           configuration settings
*       esal_ge_cfg.h                       Embedded Software
*                                           Abstraction Layer generic
*                                           configuration settings
*       esal_pr_cfg.h                       Embedded Software
*                                           Abstraction Layer processor
*                                           configuration settings
*       esal_ts_cfg.h                       Embedded Software
*                                           Abstraction Layer toolset
*                                           configuration settings
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

#ifndef         ESAL_GE_COM_DEFS_H
#define         ESAL_GE_COM_DEFS_H

/* Define NULL value */
#define         ESAL_NULL                       0

/* Defines for TRUE / FALSE conditions */
#define         ESAL_FALSE                      0
#define         ESAL_TRUE                       1

/* Define standard data types.  These definitions allow software components to
   perform in the same manner on different target platforms.  */
typedef         signed int                      ESAL_INT;
typedef         unsigned int                    ESAL_UINT;
typedef         signed char                     ESAL_INT8;
typedef         unsigned char                   ESAL_UINT8;
typedef         signed short                    ESAL_INT16;
typedef         unsigned short                  ESAL_UINT16;
typedef         signed long                     ESAL_INT32;
typedef         unsigned long                   ESAL_UINT32;
#define         ESAL_VOID                            void

/* Define type used to cast void pointers when doing pointer math */
typedef         ESAL_UINT8 *                          ESAL_VOID_CAST;

/* Define register variable definition.  This define
   can be used to specify local variables and parameters
   that could be placed into registers to increase performance
   (speed and size) */
#define         ESAL_REG                        register

/* Define macro to eliminate warnings for unused parameters */
#define         ESAL_UNUSED_PARAM(parameter)    (ESAL_VOID)parameter

/* Include configuration header files */
#include        "esal_ge_cfg.h"
#include        "esal_ar_cfg.h"
#include        "esal_ts_cfg.h"
#include        "esal_co_cfg.h"
#include        "esal_pr_cfg.h"
#include        "esal_dp_cfg.h"

/* Check if toolset supports 64-bit data types */
#if             (ESAL_TS_64BIT_SUPPORT == ESAL_TRUE)

#if defined(__MTK_TARGET__)
typedef         unsigned long long               ESAL_UINT64;
typedef         signed long long                 ESAL_INT64;
#else
typedef         unsigned __int64               ESAL_UINT64;
typedef         signed __int64                 ESAL_INT64;
#endif
#endif  /* ESAL_TS_64BIT_SUPPORT == ESAL_TRUE */

#endif  /* ESAL_GE_COM_DEFS_H */
