/*************************************************************************/
/*                                                                       */
/*          Copyright (c) 2001 Accelerated Technology, Inc.              */
/*                                                                       */
/* PROPRIETARY RIGHTS of Accelerated Technology are involved in the      */
/* subject matter of this material.  All manufacturing, reproduction,    */
/* use, and sales rights pertaining to this subject matter are governed  */
/* by the license agreement.  The recipient of this software implicitly  */
/* accepts the terms of the license.                                     */
/*                                                                       */
/*************************************************************************/

/*************************************************************************/
/*                                                                       */
/* FILE NAME                                        VERSION              */
/*                                                                       */
/*      sd_extr.h                               PLUS/ARM679/v1.13.21     */
/*                                                                       */
/* COMPONENT                                                             */
/*                                                                       */
/*      SD - Serial Driver                                               */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This file contains function prototypes for the Serial Driver     */
/*  module.                                                              */
/*                                                                       */
/* DATA STRUCTURES                                                       */
/*                                                                       */
/*      none                                                             */
/*                                                                       */
/* DEPENDENCIES                                                          */
/*                                                                       */
/*      sd_defs.h                                                        */
/*                                                                       */
/*************************************************************************/
/*=========================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*--------------------------------------------------------------------------
* $Revision$
* $Modtime$
* $Log$
*
* 03 19 2014 hc.yang
 * removed!
* .
*
*--------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*========================================================================*/
//#define PPP
#ifndef SD_EXTR
#define SD_EXTR

#include "sd_defs.h"

/* SDC function prototypes */
STATUS  SDC_Init_Port(SD_PORT *);
VOID    SDC_Put_Char(UNSIGNED_CHAR, SD_PORT *);
VOID    SDC_Put_String(CHAR *, SD_PORT *);
CHAR    SDC_Get_Char(SD_PORT *);
STATUS  SDC_Data_Ready(SD_PORT *);
VOID	SDC_Change_Communication_Mode(INT, SD_PORT *);
STATUS	SDC_Carrier(SD_PORT *);
VOID	SDC_Reset (SD_PORT *);
VOID    SDC_LISR(INT vector);

#endif


