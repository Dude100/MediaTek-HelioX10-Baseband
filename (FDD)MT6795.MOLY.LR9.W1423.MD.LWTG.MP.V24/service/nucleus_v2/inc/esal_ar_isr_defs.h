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
*       esal_ar_isr_defs.h
*
*   COMPONENT
*
*       ESAL - Embedded Software Abstraction Layer
*
*   DESCRIPTION
*
*       This file contains the architecture specific definitions,
*       structures, assembly macros, etc related to interrupt servicing
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

#ifndef         ESAL_AR_ISR_DEFS_H
#define         ESAL_AR_ISR_DEFS_H

/* Vector table address for ARM when running from ROM */
#define         ESAL_AR_ISR_VECTOR_TABLE_DEST_ADDR_ROM  0x00000000

/* Size of ARM vector table (in bytes) */
#define         ESAL_AR_ISR_VECTOR_TABLE_SIZE           64

/* Number of 32-bit registers saved on interrupt stack */
#define         ESAL_AR_ISR_STACK_SIZE                  3

/* Size, in bytes, of supervisor stack */
#define         ESAL_AR_ISR_SUP_STACK_SIZE              256

/* Define breakpoint instruction used for XScale 
   processors (after vector table installation) */
#define         ESAL_AR_ISR_XSCALE_VECT_INSTALL_BRK     0x1234
   
#endif  /* ESAL_AR_ISR_DEFS_H */
