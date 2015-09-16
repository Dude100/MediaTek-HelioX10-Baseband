@/*****************************************************************************
@*  Copyright Statement:
@*  --------------------
@*  This software is protected by Copyright and the information contained
@*  herein is confidential. The software may not be copied and the information
@*  contained herein may not be used or disclosed except with the written
@*  permission of MediaTek Inc. (C) 2005
@*
@*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
@*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
@*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
@*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
@*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
@*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
@*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
@*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
@*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
@*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
@*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
@*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
@*
@*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
@*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
@*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
@*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
@*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
@*
@*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
@*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
@*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
@*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
@*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
@*
@*****************************************************************************/
@
@/*****************************************************************************
@ *
@ * Filename:
@ * ---------
@ *   ex_hdlr.s
@ *
@ * Project:
@ * --------
@ *   Maui_Software
@ *
@ * Description:
@ * ------------
@ *   This file provides exception related APIs in assembly.
@ *
@ * Author:
@ * -------
@ *   Ken Lin  (mtk02554)
@ *
@ *============================================================================
@ *             HISTORY
@ * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
@ *------------------------------------------------------------------------------
@ * $Revision:   1.38  $
@ * $Modtime:   Aug 15 2005 18:13:06  $
@ * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/SST/src/ex_hdlr.s-arc  $
@ *
@ * 05 20 2014 carl.kao
@ * [MOLY00066129] [SYSTEM SERVICE] [Region Init] Assembly Code Add Size Info for MPPT
@ * .
@ *
@ * 04 04 2013 qmei.yang
@ * [MOLY00013594] [SystemService] To remove useless input section in exception handling by requests
@ * .
@ *
@ * 09 30 2011 ken.lin
@ * [MAUI_03040331] [ChangeFeature][SST] dump ARM cp15 FSR/FAR registers
@ * .
@ *
@ * 11 03 2010 ken.lin
@ * [MAUI_02833592] [SystemService][ChangeFeature] remove exception-related APIs from init
@ * .
@ *
@ * 11 03 2010 ken.lin
@ * [MAUI_02833592] [SystemService][ChangeFeature] remove exception-related APIs from init
@ * .
@ *------------------------------------------------------------------------------
@ * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
@ *============================================================================
@ ****************************************************************************/
@

@/*************************************************************************/
@/*                                                                       */
@/*            Copyright (c) 1994 -2000 Accelerated Technology, Inc.      */
@/*                                                                       */
@/* PROPRIETARY RIGHTS of Accelerated Technology are involved in the      */
@/* subject matter of this material.  All manufacturing, reproduction,    */
@/* use, and sales rights pertaining to this subject matter are governed  */
@/* by the license agreement.  The recipient of this software implicitly  */
@/* accepts the terms of the license.                                     */
@/*                                                                       */
@/*************************************************************************/
@
@/*************************************************************************/
@/*                                                                       */
@/* FILE NAME                                            VERSION          */
@/*                                                                       */
@/*      stack.s                                   ARM 7/9/11 1.11.19     */
@/*                                                                       */
@/* COMPONENT                                                             */
@/*                                                                       */
@/*      EX - Exception Handler                                           */
@/*                                                                       */
@/* DESCRIPTION                                                           */
@/*                                                                       */
@/*      This file provides switching stcak and running in assembly.      */
@/*                                                                       */
@/*                                                                       */
@/* DATA STRUCTURES                                                       */
@/*                                                                       */
@/*                                                                       */
@/* FUNCTIONS                                                             */
@/*                                                                       */
@/*      INT_GetCurrentSP                                                 */
@/*      INT_SwitchStackAndBranch                                         */
@/*                                                                       */
@/*                                                                       */
@/*************************************************************************/

        .global    THUMB 
        .global    ARM 
/*    .if CONFIG == 16 
.set THUMB , 0
.set ARM   , 1
        .code 32 
    .else
.set THUMB , 1
.set ARM   , 0
    .endif */

@ /*----------------------------*/
@ /*  Definitions               */
@ /*----------------------------*/
@/* for single bank support */
#if defined(SINGLE_BANK_SUPPORT)
      .global         SINGLE_BANK_SUPPORT
.set SINGLE_BANK_SUPPORT,   1
#endif /* SINGLE_BANK_SUPPORT */


@ /*----------------------------*/
@ /*  Export functions          */
@ /*----------------------------*/
   .global  INT_GetCurrentSP
   .global  INT_SwitchStackAndBranch
   .type  INT_GetCurrentSP,STT_FUNC
   .type  INT_SwitchStackAndBranch,STT_FUNC

#if defined(SINGLE_BANK_SUPPORT)
   @AREA |SNORCODE|, CODE, READONLY
   .section "SNORCODE"@, "ax", %nobits
#endif /* SINGLE_BANK_SUPPORT */  

@/*************************************************************************/
@/*                                                                       */
@/* FUNCTION                                                              */
@/*      INT_GetCurrentSP                                                 */
@/*                                                                       */
@/* DESCRIPTION                                                           */
@/*      Get the value of the current sp register.                        */
@/* CALLS                                                                 */
@/*                                                                       */
@/* INPUTS                                                                */
@/*      None                                                             */
@/*                                                                       */
@/* OUTPUTS                                                               */
@/*      current sp                                                       */
@/*************************************************************************/
@ int INT_GetCurrentSP(VOID)
@ {
INT_GetCurrentSP:
   
   MOV   r0, sp                             @ get the current stack pointer

   BX       lr                              @ Return to caller
.size INT_GetCurrentSP, .-INT_GetCurrentSP
@}

@/*************************************************************************/
@/*                                                                       */
@/* FUNCTION                                                              */
@/*      INT_SwitchStackAndBranch                                         */
@/*                                                                       */
@/* DESCRIPTION                                                           */
@/*      Switch current stack pointer to new_stack and then run           */
@/*      func(argv).                                                      */
@/*                                                                       */
@/* CALLED BY                                                             */
@/*      INT_SwitchStackToRun                                             */
@/*                                                                       */
@/* CALLS                                                                 */
@/*      None                                                             */
@/*                                                                       */
@/* INPUTS                                                                */
@/*      new_stack      the new stack pointer which want to switch to     */
@/*      func           the pointer of function which want to run         */
@/*      argc           the number of arguments of func                   */
@/*      argv           the list of arguments                             */
@/*                                                                       */
@/* OUTPUTS                                                               */
@/*      The reture value of func                                         */
@/*************************************************************************/
@ kal_uint32 INT_SwitchStackAndBranch(kal_uint32 new_stack, kal_func_ptr func, kal_uint32 argc, va_list argv)
@ {
INT_SwitchStackAndBranch:
   
   STMDB    SP!, {R4-R7, LR}

   MOV      R7, SP                          @ Backup original SP in R7
   MOV      R6, R3                          @ Load the poitner of argv
   MOV      R5, R0                          @ Backup new SP in R5
   SUBS     R2, R2, #4                      @ Check if need to copy stack?
   BLS      skip_copy_stack

   ADD      R6, R6, #16
   SUB      R5, R0, R2, LSL #2              @ Reserve new stack to store arg4~n

copy_stack:
   LDRHI    R4, [R6], #4                    @ Copy arg4~n from argv to new stack
   STRHI    R4, [R5], #4
   CMP      R0, R5
   BHI      copy_stack

   SUB      R5, R0, R2, LSL #2              @ Change new stack pointer

skip_copy_stack:
   MOV      R6, R1                          @ Backup function pointer
   MOV      R4, R3                          @ Backup the pointer of argv;

   LDR      R0, [R4]                        @ Setup arguments of procedure call
   LDR      R1, [R4, #4]
   LDR      R2, [R4, #8]
   LDR      R3, [R4, #12]

   MOV      SP, R5                          @ Switch to new stack
   ADR      lr, func_return
   BX       R6                              @ Procedure call
func_return:
   MOV      SP, R7                          @ Switch back to old stack

   LDMIA    SP!, {R4-R7, PC}
.size INT_SwitchStackAndBranch, .-INT_SwitchStackAndBranch
@}


   .end
