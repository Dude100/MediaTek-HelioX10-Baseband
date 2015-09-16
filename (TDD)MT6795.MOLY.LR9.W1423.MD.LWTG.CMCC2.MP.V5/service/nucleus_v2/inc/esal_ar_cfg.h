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
*       esal_ar_cfg.h
*
*   COMPONENT
*
*       ESAL - Embedded Software Abstraction Layer
*
*   DESCRIPTION
*
*       This file contains required configuration settings for the
*       given architecture.  These configuration settings are used by
*       generic ESAL components and can be used by external components.
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

#ifndef         ESAL_AR_CFG_H
#define         ESAL_AR_CFG_H

/* Define if the OS timer is part of the architecture (ESAL_TRUE)
   NOTE:  The OS timer can be located at only one of the following levels of
          abstraction: the processor level or the architecture level. 
          If ESAL_AR_OS_TIMER_USED is ESAL_TRUE, the OS timer is contained
          within the architecture.  If ESAL_AR_OS_TIMER_USED is ESAL_FALSE,
          the OS timer is contained within the processor component. */
#define         ESAL_AR_OS_TIMER_USED                   ESAL_FALSE

/* Define if architecture supports unaligned 16-bit accesses to memory. */
#define         ESAL_AR_UNALIGNED_16BIT_SPT             ESAL_FALSE

/* Define if architecture supports unaligned 32-bit accesses to memory. */
#define         ESAL_AR_UNALIGNED_32BIT_SPT             ESAL_FALSE

/* Define number of accesses required to read or write a pointer */
#define         ESAL_AR_PTR_ACCESS                      1

/* Define number of accesses required to read or write a 32-bit value */
#define         ESAL_AR_32BIT_ACCESS                    1

/* Size, in bytes, of architecture system stack.  This stack will be
   utilized when servicing interrupts. */
#define         ESAL_AR_SYSTEM_STACK_SIZE               1024

/* Size, in bytes, of architecture exception stack.  This stack will be
   utilized when servicing exceptions. */
#define         ESAL_AR_EXCEPTION_STACK_SIZE            0

/* Define if interrupt servicing initialization is required at the 
   architecture level. */
#define         ESAL_AR_ISR_INIT_REQUIRED               ESAL_FALSE

/* Define if architecture mandates that all interrupt handlers perform a
   "return from interrupt" (RTI) instruction in order for the hardware to
   correctly restore the state of execution to the pre-interrupt condition.
   NOTE:  Most architectures allow the state of execution to be restored 
          without needing to perform an RTI.  In most cases, this will be set 
          to ESAL_FALSE */
#define         ESAL_AR_ISR_RTI_MANDATORY               ESAL_FALSE

/* Define bit values for the architecture's status register / machine state register /
   etc that are used to enable and disable interrupts for the given architecture. */
#define         ESAL_AR_INTERRUPTS_DISABLE_BITS         0x000000C0
#define         ESAL_AR_INTERRUPTS_ENABLE_BITS          0x00000000

#endif  /* ESAL_AR_CFG_H */
