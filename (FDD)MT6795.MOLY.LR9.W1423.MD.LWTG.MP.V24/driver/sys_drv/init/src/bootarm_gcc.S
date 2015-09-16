/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   bootarm_gcc.S
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the boot sequence of asm level.
 *
 * Author:
 * -------
 * -------
 * -------
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 ****************************************************************************/


/*************************************************************************/
/*                                                                       */
/*            Copyright (c) 1994 -2000 Accelerated Technology, Inc.      */
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
/* FILE NAME                                            VERSION          */
/*                                                                       */
/*      bootarm.s                                   ARM 6/7/9 1.11.19    */
/*                                                                       */
/* COMPONENT                                                             */
/*                                                                       */
/*      IN - Initialization                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This file contains the target processor dependent initialization */
/*      routines and data.                                               */
/*                                                                       */
/*                                                                       */
/* DATA STRUCTURES                                                       */
/*                                                                       */
/*      INT_Vectors                         Interrupt vector table       */
/*                                                                       */
/* FUNCTIONS                                                             */
/*                                                                       */
/*      INT_Initialize                      Target initialization        */
/*      INT_Vectors_Loaded                  Returns a NU_TRUE if all the */
/*                                            default vectors are loaded */
/*      INT_Setup_Vector                    Sets up an actual vector     */
/*                                                                       */
/*                                                                       */
/*************************************************************************/
   #include "asm_def.h"

   CPU_ISA()
   ISA_UNIFIED_SETTING()

#include "reg_base.h"
#include "bootarm.h"

/* Define constants used in low-level initialization.  */

#include "bootarm_var_gcc.inc"

/*************************************************************************
 * Macro definition
 *************************************************************************/
.macro  INT_TRC trace_id
#if defined(__SP_BOOTTRC_ENABLE__)
    LDR a1, =Init_Magic_Num
    LDR a1, [a1]
    MOV a2, #\trace_id
    BL INC_TRC
#endif
.endm

   .section ".rodata"
   .align 3

/* used for vector table diagnosis */
/* used to handle abnormal reset in remapping case  */
   .global  LDR_PC_Initialize    
LDR_PC_Initialize:               
   .word  PC_INITIALIZE_VAL      @ ldr pc,INT_Table

/*************************************************************************
 *   Global system stack variable (Setup by the initialization routine)  *
 *************************************************************************/

    .data
    .align 3

    .global  INT_Loaded_Flag
INT_Loaded_Flag:
    .word      0x00000000

/* External ram stack */  
   .align STACK_ALIGN_NUM
ABT_Stack_Pool:
   .ascii      "STACKEND"
   .space    OTHER_STACK_SIZE-8

   .align STACK_ALIGN_NUM
UND_Stack_Pool:
   .ascii      "STACKEND"
   .space    OTHER_STACK_SIZE-8

   .align STACK_ALIGN_NUM
FIQ_Stack_Pool:
   .ascii      "STACKEND"
   .space    FIQ_STACK_SIZE-8

#if (defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__)
   .align STACK_ALIGN_NUM
   .global   SYS_Stack_Pool
SYS_Stack_Pool:
   .ascii      "STACKEND"
   #if defined(__ARM_FPUV2__)
   .space    SYS_STACK_SIZE+2432-8         @ Increase SYS stack size for saving FPU registers
   #else
   .space    SYS_STACK_SIZE-8
   #endif
#endif /* end of "(defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__)" */
      
 /*
  * NoteXXX: The exception stack space must be allocated in TCM for MT6235/8.
  *          This is because the exception handler is special designed for MT6235/8.
  */

   .align STACK_ALIGN_NUM
   .global   EX_Stack_Pool
EX_Stack_Pool:
   .ascii      "STACKEND"
   .space    EX_STACK_SIZE-8

#if !((defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__))
   .section "INTSRAM_RW", "w", %progbits
#else /* end of !((defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__)) */
   .section "COPRO_INTSRAM_RW", "w", %progbits
#endif /* end of else of "!((defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__))" */

  
   .align STACK_ALIGN_NUM
IRQ_Stack_Pool:
   .ascii      "STACKEND"
   .space    IRQ_STACK_SIZE-8

#if !((defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__))
   .global   SYS_Stack_Pool
   .align STACK_ALIGN_NUM
SYS_Stack_Pool:
   .ascii      "STACKEND"
   #if defined(__ARM_FPUV2__)
   .space    SYS_STACK_SIZE+2432-8         @ Increase SYS stack size for saving FPU registers
   #else
   .space    SYS_STACK_SIZE-8
   #endif
#endif /* end of "!((defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__))" */
      
   .align STACK_ALIGN_NUM
EX_SYS_Stack_Pool:
   .ascii      "STACKEND"
   .space    EX_SYS_STACK_SIZE-8
      
Abnormal_info_Pool:
   .space    ABNORMAL_POOL_SIZE
     
   .section "INT_VECTOR_CODE", "ax"
   .align 2

/* Define the global data structures that need to be initialized by this
   routine.  These structures are used to define the system timer management
   HISR.  */


   .global  BOOT_EX_Stack_End


/* Define the ARM60 interrupt vector table, INT_Vectors.  This table is
   assumed to be loaded or copied to address 0.  If coexistence with a
   target-resident-monitor program is required, it is externant to only
   copy the IRQ and possibly the FIQ interrupt vectors in this table into
   the actual table.  The idea is to not mess with the monitor's vectors.  */
@VOID    *INT_Vectors[NU_MAX_VECTORS];

   CPU_ISA()
   ISA_UNIFIED_SETTING()
   FUNC_ATTR(INT_Vectors)
   .global  INT_Vectors
INT_Vectors:
   #if defined(REMAPPING)
      B     INT_Initialize
   #else
      LDR   pc,INT_Table_Local
   #endif
   LDR   pc,(INT_Table_Local + 4)
   LDR   pc,(INT_Table_Local + 8)
   LDR   pc,(INT_Table_Local + 12)
   LDR   pc,(INT_Table_Local + 16)
   LDR   pc,(INT_Table_Local + 20)
   LDR   pc,(INT_Table_Local + 24)
   LDR   pc,(INT_Table_Local + 28)
.size INT_Vectors, .-INT_Vectors

   .global   INT_Table
   
INT_Table:
INT_Table_Local:
INT_Initialize_Addr:  .word   INT_Initialize
Undef_Instr_Addr:     .word   Undef_Instr_ISR
SWI_Addr:             .word   SWI_ISR
Prefetch_Abort_Addr:  .word   Prefetch_Abort_ISR
Data_Abort_Addr:      .word   Data_Abort_ISR
Undefined_Addr:       .word   0              @ NO LONGER USED
IRQ_Handler_Addr:     .word   INT_IRQ_Parse
FIQ_Handler_Addr:     .word   INT_FIQ_Parse

INT_Table_End:

    .text
    .align 3

#include "bootarm_gcc.inc"
   

#if !defined(_NAND_FLASH_BOOTING_) && !defined(_NOR_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__)
  
ROM_Base_Ptr:
   .word     Image$$ROM$$Base

INT_Table_End_PTR:
   .word     INT_Table_End

#else
   
   #if defined(__SV5_ENABLED__)||defined(__SV5X_ENABLED__)
ROM_Base_Ptr:
   .word     Image$$ROM$$Base

INT_Table_End_PTR:
   .word     INT_Table_End

#endif /* __SV5_ENABLED__ || __SV5X_ENABLED__ */
   
#endif   


Loaded_Flag:
   .word     INT_Loaded_Flag



   #if defined(KAL_ON_NUCLEUS)

   #if defined(__NUCLEUS_VERSION_2__)
@ Nucleus Plus2: rename TCD_System_Stack to ESAL_GE_STK_System_SP
@ and remove TCT_System_Limit
System_Stack:
   .word     ESAL_GE_STK_System_SP
   #else
System_Stack:
   .word     TCD_System_Stack

System_Limit:
   .word     TCT_System_Limit

   #endif
   #else     /* KAL_ON_NUCLEUS */

System_Stack:
   .word     _tx_thread_system_stack_ptr

   #endif   /* KAL_ON_NUCLEUS */

   
BOOT_IRQ_Stack_End:
   .word     IRQ_Stack_Pool+IRQ_STACK_SIZE-4

BOOT_FIQ_Stack_End:
   .word     FIQ_Stack_Pool+FIQ_STACK_SIZE-4

BOOT_ABT_Stack_End:
   .word     ABT_Stack_Pool+OTHER_STACK_SIZE-4

BOOT_UND_Stack_End:
   .word     UND_Stack_Pool+OTHER_STACK_SIZE-4

   .global   BOOT_SYS_Stack_End
BOOT_SYS_Stack_End:
   .word     SYS_Stack_Pool+SYS_STACK_SIZE-4

BOOT_SYS_Stack_End_Local: 
   #if (defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__)
   .word     IRQ_Stack_Pool+IRQ_STACK_SIZE-4
   #else /* end of "(defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__)" */
   .word     SYS_Stack_Pool+SYS_STACK_SIZE-4
   #endif /* end of else of "(defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__)" */


BOOT_SYS_Stack:
   .word     SYS_Stack_Pool

BOOT_EX_Stack_End:
   .word     EX_Stack_Pool+EX_STACK_SIZE-0x44

   .global   BOOT_EX_SYS_Stack_End
BOOT_EX_SYS_Stack_End:
   .word     EX_SYS_Stack_Pool+EX_SYS_STACK_SIZE-4

   #if defined(REMAPPING)
MTK_INITIALIZE_PTR:
   .word     MTK_Initialize
   #endif

RAND_NUM_SEED_PTR:
   .word     rand_num_seed

ECO_VERSION_PTR:
   .word     eco_version

ABN_RST_PTR:
   .word     Abnormal_info_Pool

/* Literal Pool */
.global Init_Magic_Num
Init_Magic_Num:
    .word  INIT_MAGIC

@ void INC_TRC(kal_uint32 trace_log1, kal_uint32 trace_log2)
@ {

.global INC_TRC
.type   INC_TRC, %function

INC_TRC:
    MOV     r7, lr
    #if defined(__SP_BOOTTRC_ENABLE__)
    LDR a3, =g_EMM_BOOTTRC_ADDR
    #if defined(__X_BOOTING__)    
    LDR a3, [a3]
    ORR a1, a1, a2
    STR a1, [a3]
    #else
    LDR a3, [a3]
    STR a1, [a3]
    STR a2, [a3, #4]
    #endif
    #endif
    BX      lr 
.size INC_TRC, .-INC_TRC
@ } /* INC_TRC */

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      INT_Initialize                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function sets up the global system stack variable and       */
/*      transfers control to the target independent initialization       */
/*      function INC_Initialize.  Responsibilities of this function      */
/*      include the following:                                           */
/*                                                                       */
/*             - Setup necessary processor/system control registers      */
/*             - Initialize the vector table                             */
/*             - Setup the system stack pointers                         */
/*             - Setup the timer interrupt                               */
/*             - Calculate the timer HISR stack and priority             */
/*             - Calculate the first available memory address            */
/*             - Transfer control to INC_Initialize to initialize all of */
/*               the system components.                                  */
/*                                                                       */
/* CALLS                                                                 */
/*                                                                       */
/*      INC_Initialize                      Common initialization        */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/*                                                                       */
/*************************************************************************/
@VOID    INT_Initialize(void)
@{

   .global  INT_Initialize
.type INT_Initialize, %function
INT_Initialize:
@   /* Insure that the processor is in supervisor mode.  */
   MRS   a1,CPSR                            @ Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   @ Clear the mode bits
   ORR   a1,a1,#KERN_MODE                   @ Set the kernel mode bits
   ORR   a1,a1,#LOCKOUT                     @ Insure IRQ/FIQ interrupts are
                                            @ locked out
   MSR   CPSR_cxsf,a1                       @ Setup the new CPSR


#if defined(REMAPPING)                           
   @ REMAPPING {
 
   LDR   a4,=EMI_base

#if defined(EMI_REMAP_OFFSET_SUPPORT)
   LDR   a1,[a4,#REMAP_OFFSET]              @ Skip if it is an abnormal reset
   AND   a1,a1,#0x03                        @ under remapped configuration
   MOV   a2,#FLASH_SRAM_REMAP
   CMP   a1,a2
#endif
   
   BEQ   MTK_LoadPC
   
   /* REMAPACTION */
#if !(defined(__FOTA_ENABLE__) || defined(__BL_ENABLE__))
   
#if defined(EMI_26MHZ_FILL)
   LDR   a1,EMI_26MHZ_SETTING               @ Setting EMI for 13MHz MCU clock
   STR   a1,[a4]                            @ C2WS=1, C2RS=1, WST=2, RLT=2
   STR   a1,[a4,#0x08]                      @ 16 bits device
#endif

   MOV   a2,#BOOTROM_FLASH_REMAP            @ Restore remapping on \CS0 and \CS1
   
#if defined(EMI_REMAP_OFFSET_SUPPORT)

#if defined(EMI_REMAP_OFFSET_MIXED)
   LDR   a1,[a4,#REMAP_OFFSET]                      
   BIC   a1, a1, #3
   ORR   a2, a2, a1
   STR   a2,[a4,#REMAP_OFFSET]
#else
   STRH  a2,[a4,#REMAP_OFFSET]
#endif
#endif
 
#endif   /* !(__FOTA_ENABLE__ || __BL_ENABLE__) */
                                              

   LDR   a1,ROM_Base_Ptr                    @ Copy Exception Vector table to RAM before remapping
   LDR   a2,REMAP_NOR_MASK
   AND   a1,a1,a2		    	    @ a1 will be the address with interrupt vector.
   LDR   v1,REMAP_NOR_ADDR
   LDR   a2,ROM_Base_Ptr                    @ use a2 and a3 to calculate the need address
   LDR   a3,INT_Table_End_PTR

   ORR   a3,a2,a3
   
   LDR   a4, =LDR_PC_Initialize
   STR   a4, [v1], #4
   ADD   a1,a1,#4
   ADD   a2,a2,#4
Copy_INT_Entry:
   CMP   a2,a3  
   LDRLO a4,[a1], #4
   STRLO a4,[v1], #4
   ADDLO a2,a2,#4
   BLO   Copy_INT_Entry

   LDR   a1,ROM_Base_Ptr          @ Copy needed code to avoid the code loss after remapping
   LDR   a2,REMAP_NOR_MASK		    @ a1 will be the address of NOR start address
   AND   a1,a1,a2
   LDR   a2,ROM_Base_Ptr

   LDR   a3,=MTK_Initialize
   
   ORR   a3,a2,a3
   LDR   a4,=LDR_PC_Initialize
   STR   a4,[a2], #4
   ADD   a1,a1,#4
Copy_ROM_Entry:
   CMP   a2,a3  
   LDRLO a4,[a1], #4
   STRLO a4,[a2], #4
   BLO   Copy_ROM_Entry

   LDR   a4,=EMI_base                 @ Remapping on \CS0 and \CS1
   MOV   a2,#FLASH_SRAM_REMAP   
   
#if defined(EMI_REMAP_OFFSET_SUPPORT)
   
#if defined(EMI_REMAP_OFFSET_MIXED)
   LDR   a1,[a4,#REMAP_OFFSET]                     
   BIC   a1, a1, #3
   ORR   a2, a2, a1
   STR   a2,[a4,#REMAP_OFFSET]
#else
   STRH  a2,[a4,#REMAP_OFFSET]
#endif
#endif
   
   
   NOP
   NOP
   NOP
   NOP
   NOP
   NOP


MTK_LoadPC:
   LDR   pc,MTK_INITIALIZE_PTR   
   
MTK_Initialize: 

#endif                                    /* REMAPPING */

#if defined(__SV5_ENABLED__)|| defined(__SV5X_ENABLED__)
   @ Check if abnromal reset first    
#if !defined(DRV_WDT_OFF)
   LDR   a1,=g_ABNORMAL_RST_REG
   LDR   a1,[a1]
   LDR   a1,[a1]
   LDR   a2,=g_ABNORMAL_RST_VAL
   LDR   a2,[a2]
   CMP   a1,a2
   BEQ   Abnormal_RST
#endif
   @ SV5 Vector Copy
   LDR   a1,ROM_Base_Ptr                    @ Copy Exception Vector table to RAM before remapping
   MOV   v1,#0
   LDR   a2,ROM_Base_Ptr                    @ use a2 and a3 to calculate the need address
   LDR   a3,INT_Table_End_PTR
Copy_VEC_Entry:
   CMP   a2,a3  
   LDRLO a4,[a1], #4
   STRLO a4,[v1], #4
   ADDLO a2,a2,#4
   BLO   Copy_VEC_Entry

Abnormal_RST:
#endif /* __SV5_ENABLED__ ||  __SV5X_ENABLED__ */


   @ Restart watchdog in order to avoid the unexpected wdt reset when booting
   LDR   a1,=g_WATCHDOG_RESTART_REG            @ Restart watchdog
   LDR   a1,[a1]
   LDR   a2,=g_WATCHDOG_RESTART_VALUE
   LDR   a2,[a2]
   STR   a2,[a1]
      

  /* Can not call any function which will use link register before save the abnormal reset value */ 
  /* backup lr and sp for abnormal-reset scenario */
   MOV   v1,lr
   MOV   v2,sp

   INT_TRC LABEL_START_INIT
   /* Set the Normal Exception Vector Selection (0x0) */
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__CR4__)
   MOV r0, #0
   BL cp15_switch_vector   
#endif /* __ARM9_MMU__ || __ARM11_MMU__ || __CR4__*/

#if defined(__CR4__)
   @ /* disable branch prediction (branch always not taken) */
   MOV r0, #0x2
   BL cp15_set_bp_policy
#endif

   INT_TRC LABEL_TCM_INIT
   @ Enable ARM9 TCM
#if defined(__ARM9_MMU__)
   LDR r0, =Image$$EMIINIT_CODE$$Base 
   BL cp15_enable_itcm

   LDR r0, =Image$$INTSRAM_DATA$$Base      
   BL cp15_enable_dtcm
#endif /* __ARM9_MMU__ */

   @ Enable ARM11 TCM
#if defined(__ARM11_MMU__)
   /* Select I/DTCM0 */
      MOV r0, #0
      BL cp15_tcm_select
      
   /* Enable access ITCM0 region register in security world*/
      MOV r0, #0
      BL cp15_itcm_secure_access
      
   /* Enable access DTCM0 region register in security world*/
      MOV r0, #0
      BL cp15_dtcm_secure_access

   /* Set base address of ITCM0*/
      LDR r0, =Image$$EMIINIT_CODE$$Base
      BL cp15_enable_itcm

   /* Set base address of DTCM0*/
      LDR r0, =Image$$INTSRAM_DATA$$Base
      BL cp15_enable_dtcm

    /* Read itcm region register to get the size of ITCM bank0*/
      BL cp15_read_itcm_region
      AND r0, r0, #TCM_SIZE_MASK
    /* if size equal 4KB, set r2=4 */
      CMP r0, #12
      MOVEQ r2, #4
    /* if size equal 8KB, set r2=8 */
      CMP r0, #16
      MOVEQ r2, #8
    /* if size equal 16KB, set r2=16 */
      CMP r0, #20
      MOVEQ r2, #16
    /* if size equal 32KB, set r2=32 */
      CMP r0, #24
      MOVEQ r2, #32

    /* Read dtcm region register to get the size of DTCM bank0*/
      BL cp15_read_dtcm_region
      AND r0, r0, #TCM_SIZE_MASK
    /* if size equal 4KB, set r3=4 */
      CMP r0, #12
      MOVEQ r3, #4
    /* if size equal 8KB, set r3=8 */
      CMP r0, #16
      MOVEQ r3, #8
    /* if size equal 16KB, set r3=16 */
      CMP r0, #20
      MOVEQ r3, #16
    /* if size equal 32KB, set r3=32 */
      CMP r0, #24
      MOVEQ r3, #32
      
   /* Select I/DTCM1 */
      MOV r0, #1
      BL cp15_tcm_select
      
   /* Enable access ITCM1 region register in security world*/
      MOV r0, #0
      BL cp15_itcm_secure_access
      
   /* Enable access DTCM1 region register in security world*/
      MOV r0, #0
      BL cp15_dtcm_secure_access

   /* Set base address of ITCM1 */
      LDR r0, =Image$$EMIINIT_CODE$$Base
      ADD r0, r0, r2, lsl #10
      BL cp15_enable_itcm

   /* Set base address of DTCM1 */
      LDR r0, =Image$$INTSRAM_DATA$$Base
      ADD r0, r0, r3, lsl #10
      BL cp15_enable_dtcm
 
#endif  /* __ARM11_MMU__ */

#if defined(__CR4__)
      @ disable 64-bit read-modify-write of TCMs;
      BL cp15_disable_atcmrmw
      BL cp15_disable_btcmrmw

      @ MT6595: atcm placed before btcm
      #if defined(MT6595)  || (defined(MT6752) && defined(__MD1__))
      LDR r0, =Image$$EMIINIT_CODE$$Base
      BL cp15_enable_atcm

      LDR r0, =Image$$INTSRAM_PHYSICAL_BOUNDARY$$Base
      BL cp15_enable_btcm
      #endif 
      
#endif /* __CR4__ */

#if defined(__ARM_FPUV2__)
   BL cp15_enable_cp
   BL enable_arm_fpu
   BL set_fpu_runfastmode
#endif


  /* save backup lr and sp for abnormal-reset scenario */
   INT_TRC  LABEL_SAVE_LRSP
   LDR   a1,ABN_RST_PTR
   STR   v1,[a1]
   STR   v2,[a1,#0x4]

   LDR   a1, BOOT_SYS_Stack_End_Local
   MOV   sp,a1                              @ Setup initial stack pointer

  /* Check if abnormal reset */
   INT_TRC  LABEL_ABN_RST_CHECK
   LDR   a1,ABN_RST_PTR
   BL    INT_SystemReset_Check

  /* Version check should after abnormal reset check    */
  /* to avoid calling tst_sys_trace when abnormal reset */
  /* happends with interrupt disabled                   */
#if defined(__CHIP_VERSION_CHECK__)
   INT_TRC  LABEL_VER_CHECK
   BL    INT_Version_Check
#endif

   
   BL    SST_DTLB_Init
   
   INT_TRC  LABEL_GET_RAND_SEED
   BL    INT_GetRandomSeed
  /*
   * NoteXXX: Store the return value of INT_GetRandomSeed 
   *          in r11 temporarily. Thus in the following program r11 should be
   *          used before we store r11 back to rand_num_seed.
   */
   MOV   r11,a1
      
   
#if !((defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__))
   @ /* Backup bootloader-passed information in ITCM base */
   LDR r0, =Image$$INTSRAM_DATA$$Base
   BL    INT_BackupBLShareinfo
#endif /* end of "!((defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__))" */
   
   INT_TRC  LABEL_REG_INIT_EMI
   BL    INT_InitEMIInitCode

   /* used for PLL setting */
   BL     INT_ecoVersion
   LDR   a2, ECO_VERSION_PTR
   STR   a1,[a2]

  /* configure EMI wait state after system stack is set up */
   INT_TRC  LABEL_INT_CONFIG
   BL    INT_Config

  /* enable LPSDRAM */
#if defined(_NOR_LPSDRAM_MCP_)
#if !(defined(__FOTA_ENABLE__) || defined(__USB_DOWNLOAD__) || defined(__BL_ENABLE__))
   BL    custom_InitDRAM
#endif
#endif

  /* make the temporary page table for the DCached region */
   INT_TRC  LABEL_CACHE_PRE_INIT
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
   BLX   mk_tmp_pt
#elif defined(__CR4__) || defined(__MTK_MMU_V2__)
   BLX   MpuPreInit
#else /* defined(__MTK_MMU__) */
   BLX   CachePreInit
#endif

   BL    INT_InitPreInitData
#if !((defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__))
   LDR r0, =Image$$INTSRAM_DATA$$Base
   BL    INT_RetrieveBLShareinfo            @ pass service		
#endif /* end of "!((defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__))" */

  /* Initialize regions */
  /* Do NOT use any TCM data and global variable before here!!! */
   INT_TRC  LABEL_REG_INIT_MAIN
   BL    INT_InitRegions                    @ in regioninit.s

#if defined(MT6595)
   BLX   INT_Init_MT6595_Eco_Magic
#endif

   BLX   mddbg_init

   /* Fixups before HW modules starting to acquire proper clock */
   INT_TRC  LABEL_DCM_PREINIT
   BL    DCM_Prerequisite

   /* must register HAL serial port for UART/USB EARLY usage */
   /* (e.g. bootup trace, all time memory dump)              */
#if !(defined(MT6290) || defined(MT6595) || (defined(MT6752) && defined(__MD1__)))
   INT_TRC  LABEL_SERIPORT_PREINIT
   BL    PreInit_Seriport
#endif /* MT6290 || MT6595 */
#if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)
   INT_TRC  LABEL_BOOTTRC_INIT
   BL    INT_InitBootupTrace
#endif   /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */
   
   /* ROMSA */
#if defined(__ROMSA_SUPPORT__)
   BL    InitRegions2
   BL    ROMSA_Init
#endif

  /* after INT_InitRegions, we can store the random number seed to rand_num_seed */
   LDR   a2,RAND_NUM_SEED_PTR
   STR   r11,[a2]

  /* use temp page table to initialize DMDSP execution environment */
  /* for NAND Flash booting, dmdsp_init will be called in nfb_loader.c */
#if !defined(_NAND_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__)
#if defined(MT6575) || defined(MT6577)  /* FCore + DSP_BOOT_SEC */
   BL    dmdsp_init
#endif
#endif
   
   @ /* Initialize Cache/MMU/MPU */
   INT_TRC  LABEL_CACHE_INIT
   BL    CacheInit


#if defined(__CR4__)
   @ /* enable branch prediction (normal operation) */
   MOV r0, #0x0
   BL cp15_set_bp_policy
#endif

  /* initialize the multi-media region */
   BL    INT_InitMMRegions

   MOV   a1,#1                              @ All vectors are assumed loaded   
   LDR   a2, Loaded_Flag
   STR   a1,[a2,#0]                         @ Initialize loaded flag

   @ /* Setup system stacks */
   INT_TRC  LABEL_STACK_INIT
#if defined(KAL_ON_NUCLEUS)

   LDR   a1, BOOT_SYS_Stack            

#if !defined(__NUCLEUS_VERSION_2__)
   LDR   a4,System_Limit                    @ Setup initial stack limit
   STR   a1,[a4, #0]                        @ Save stack limit   
#endif

#endif

#if (defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__)
   LDR   a1, BOOT_SYS_Stack_End
   MOV   sp,a1                              @ Setup external stack pointer
#endif /* end of "(defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__)" */

   LDR   a4, System_Stack
   STR   sp,[a4, #0]                        @ Save stack pointer
   
   LDR   a3,BOOT_IRQ_Stack_End
   MRS   a1,CPSR                            @ Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   @ Clear the mode bits
   ORR   a1,a1,#IRQ_MODE                    @ Set the IRQ mode bits
   MSR   CPSR_cxsf,a1                       @ Move to IRQ mode
   MOV   sp,a3                              @ Setup IRQ stack pointer
#if defined(__NUCLEUS_VERSION_2__)
   SUB   sp, #8                             @ Nucleus V2 sp adjust
#endif

   LDR   a3,BOOT_FIQ_Stack_End
   MRS   a1,CPSR                            @ Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   @ Clear the mode bits
   ORR   a1,a1,#FIQ_MODE                    @ Set the FIQ mode bits
   MSR   CPSR_cxsf,a1                       @ Move to the FIQ mode
   MOV   sp,a3                              @ Setup FIQ stack pointer
#if defined(__NUCLEUS_VERSION_2__)
   SUB   sp, #8                             @ Nucleus V2 sp adjust
#endif

   LDR   a3,BOOT_ABT_Stack_End
   MRS   a1,CPSR                            @ Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   @ Clear the mode bits
   ORR   a1,a1,#ABORT_MODE                  @ Set the Abort mode bits
   MSR   CPSR_cxsf,a1                       @ Move to the Abort mode
   MOV   sp,a3                              @ Setup Abort stack pointer
   
   LDR   a3,BOOT_UND_Stack_End
   MRS   a1,CPSR                            @ Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   @ Clear the mode bits
   ORR   a1,a1,#UND_MODE                    @ Set the Undefine mode bits
   MSR   CPSR_cxsf,a1                       @ Move to the Undefine mode
   MOV   sp,a3                              @ Setup Undefine stack pointer

#if !((defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__))
   LDR   a3,BOOT_SYS_Stack_End_Local
#else /* end of "!((defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__))" */
   LDR   a3,BOOT_SYS_Stack_End
#endif /* end of "(defined(MT6290) || defined(MT6595)) && defined(__ARM7EJ_S__)" */
   MRS   a1,CPSR                            @ Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   @ Clear the mode bits
#if defined(__NUCLEUS_VERSION_2__)
   ORR   a1,a1,#SUP_MODE                    @ Set the Supervisor mode bits
#else
   ORR   a1,a1,#SYS_MODE                    @ Set the System mode bits
#endif
   MSR   CPSR_cxsf,a1                       @ Move to the System/Supervisor mode
   MOV   sp,a3                              @ Setup System/Supervisor stack pointer

   MRS   a1,CPSR                            @ Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   @ Clear mode bits
   ORR   a1,a1,#KERN_MODE                   @ Set the kernel running mode bits
   MSR   CPSR_cxsf,a1                       @ All interrupt stacks are setup,

   INT_TRC  LABEL_ASM_DONE
   MOV   a1, #0

#if defined(KAL_ON_NUCLEUS)

   LDR   a4,=INC_Initialize                 @ to high-level initialization
   BX    a4

#else

   LDR   a4,=_tx_initialize_kernel_enter    @ to high-level initialization
   BX    a4
#endif
.size INT_Initialize, .-INT_Initialize
@}



   .end

