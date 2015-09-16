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
*       esal_ts_cfg.h
*
*   COMPONENT
*
*       ESAL - Embedded Software Abstraction Layer
*
*   DESCRIPTION
*
*       This file contains required configuration settings for the
*       given toolset.  These configuration settings are used by
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

#ifndef         ESAL_TS_CFG_H
#define         ESAL_TS_CFG_H

/* Define required stack pointer alignment for the given toolset.*/
#define         ESAL_TS_REQ_STK_ALIGNMENT               8

/* Defines if toolset supports 64-bit data types (long long) */
#define         ESAL_TS_64BIT_SUPPORT                   ESAL_TRUE

/* Defines, in bytes, toolset minimum required alignment for structures */
#define         ESAL_TS_STRUCT_ALIGNMENT                4

/* Size, in bits, of integers for the given toolset / architecture */
#define         ESAL_TS_INTEGER_SIZE                    32

/* Size, in bits, of code pointer for the given toolset / architecture */
#define         ESAL_TS_CODE_PTR_SIZE                   32

/* Size, in bits, of data pointer for the given toolset / architecture */
#define         ESAL_TS_DATA_PTR_SIZE                   32

/* Defines used to enforce alignment of data structure members (if necessary). */


/* Define tool specific type for HUGE and FAR data pointers - these will usually
   be defined to nothing.  Some 16-bit architectures may require these
   to be defined differently to access data across memory pages */
#define         ESAL_TS_HUGE_PTR_TYPE
#define         ESAL_TS_FAR_PTR_TYPE

/* Define if position-independent code / data (PIC/PID) support (if available)
   is enabled.
   NOTE:  This may be required to be set to ESAL_TRUE when utilizing any
          OS components requiring position-independent code / data */
#define         ESAL_TS_PIC_PID_SUPPORT                 ESAL_FALSE

#endif  /* ESAL_TS_CFG_H */
