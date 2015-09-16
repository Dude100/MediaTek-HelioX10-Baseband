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
*       esal_ts_stk_defs.h
*
*   COMPONENT
*
*       ESAL - Embedded Software Abstraction Layer
*
*   DESCRIPTION
*
*       This file contains the toolset specific definitions, structures,
*       macros, etc, related to stacks
*
*   DATA STRUCTURES
*
*       ESAL_TS_STK_STRUCT                  Stack-frame structure for the
*                                           given toolset / architecture
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

#ifndef         ESAL_TS_STK_DEFS_H
#define         ESAL_TS_STK_DEFS_H

/* Define number of single-precision floating point registers required to
   be saved within a toolset stack frame (s16-s31) */
#define         ESAL_TS_STK_NUM_FPU_REGS        16

/* Define stack frame structure for the toolset / architecture supported. */
typedef struct  ESAL_TS_STK_STRUCT
{
    ESAL_UINT32          stack_type;
    ESAL_UINT32          r4;
    ESAL_UINT32          r5;
    ESAL_UINT32          r6;
    ESAL_UINT32          r7;
    ESAL_UINT32          r8;
    ESAL_UINT32          r9;
    ESAL_UINT32          r10;
    ESAL_UINT32          r11;
    ESAL_UINT32          rtn_address;

#if (ESAL_AR_STK_FPU_SUPPORT == ESAL_TRUE)

    ESAL_UINT32          fpscr;
    ESAL_UINT32          s[ESAL_TS_STK_NUM_FPU_REGS];
    ESAL_UINT32          fpexc;

#endif  /* ESAL_AR_STK_FPU_SUPPORT == ESAL_TRUE */

} ESAL_TS_STK;

#endif  /* ESAL_TS_STK_DEFS_H */
