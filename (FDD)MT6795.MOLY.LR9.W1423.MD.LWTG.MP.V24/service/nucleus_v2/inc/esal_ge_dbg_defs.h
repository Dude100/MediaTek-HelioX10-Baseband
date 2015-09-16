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
*       esal_ge_dbg_defs.h
*
*   COMPONENT
*
*       ESAL - Embedded Software Abstraction Layer
*
*   DESCRIPTION
*
*       This file contains generic defines, structures, data types, etc
*       related to debugging
*
*   DATA STRUCTURES
*
*       None
*
*   DEPENDENCIES
*
*       esal_ar_dbg_defs.h                  Embedded Software
*                                           Abstraction Layer architecture
*                                           constants and defines for
*                                           debugging
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

#ifndef             ESAL_GE_DBG_DEFS_H
#define             ESAL_GE_DBG_DEFS_H

/* Include required header files */
#include            "esal_ar_dbg_defs.h"

/* Map generic opcode type to architecture specific opcode type */
typedef             ESAL_AR_DBG_OPCODE              ESAL_GE_DBG_OPCODE;
typedef             ESAL_AR_DBG_REG                 ESAL_GE_DBG_REG;

/* Map generic APIs to lower-level components */
#define             ESAL_GE_DBG_Reg_Read            ESAL_AR_DBG_Reg_Read
#define             ESAL_GE_DBG_Reg_Write           ESAL_AR_DBG_Reg_Write
#define             ESAL_GE_DBG_Opcode_Read         ESAL_AR_DBG_Opcode_Read
#define             ESAL_GE_DBG_Opcode_Write        ESAL_AR_DBG_Opcode_Write
#define             ESAL_GE_DBG_OPcode_Brk_Get      ESAL_AR_DBG_Opcode_Brk_Get
#define             ESAL_GE_DBG_Step_Addr_Get       ESAL_AR_DBG_Step_Addr_Get

/* Define all debugging related function prototypes */
ESAL_VOID                ESAL_GE_DBG_Initialize(ESAL_VOID **(*brk_handler)(ESAL_VOID *));
ESAL_VOID                ESAL_AR_DBG_Initialize(ESAL_VOID);
ESAL_INT                 ESAL_AR_DBG_Reg_Read(ESAL_VOID *stack_pointer, ESAL_INT reg_no, ESAL_GE_DBG_REG *reg_val);
ESAL_INT                 ESAL_AR_DBG_Reg_Write(ESAL_VOID *stack_pointer, ESAL_INT reg_no, ESAL_GE_DBG_REG *reg_val);
ESAL_GE_DBG_OPCODE  ESAL_AR_DBG_Opcode_Read(ESAL_VOID *read_addr);
ESAL_VOID                ESAL_AR_DBG_Opcode_Write(ESAL_VOID *write_addr, ESAL_GE_DBG_OPCODE value);
ESAL_GE_DBG_OPCODE  ESAL_AR_DBG_Opcode_Brk_Get(ESAL_VOID *addr);
ESAL_VOID                *ESAL_AR_DBG_Step_Addr_Get(ESAL_VOID *addr, ESAL_VOID *stack_frame);

/* Define used for registers that are not mapped in a stack frame */
#define             ESAL_GE_DBG_REG_NOT_MAPPED      -1

#endif  /* ESAL_GE_DBG_DEFS_H */
