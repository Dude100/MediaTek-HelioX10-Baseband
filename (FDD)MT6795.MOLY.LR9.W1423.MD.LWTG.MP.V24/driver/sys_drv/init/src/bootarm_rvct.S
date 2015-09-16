;/*****************************************************************************
;*  Copyright Statement:
;*  --------------------
;*  This software is protected by Copyright and the information contained
;*  herein is confidential. The software may not be copied and the information
;*  contained herein may not be used or disclosed except with the written
;*  permission of MediaTek Inc. (C) 2005
;*
;*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
;*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
;*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
;*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
;*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
;*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
;*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
;*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
;*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
;*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
;*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
;*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
;*
;*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
;*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
;*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
;*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
;*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
;*
;*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
;*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
;*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
;*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
;*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
;*
;*****************************************************************************/
;
;/*****************************************************************************
; *
; * Filename:
; * ---------
; *   bootarm.s
; *
; * Project:
; * --------
; *   Maui_Software
; *
; * Description:
; * ------------
; *   This Module defines the boot sequence of asm level.
; *
; * Author:
; * -------
; * -------
; * -------
; *
; *============================================================================
; *             HISTORY
; * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
; *------------------------------------------------------------------------------
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; * removed!
; *------------------------------------------------------------------------------
; * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
; *============================================================================
; ****************************************************************************/
;

;/*************************************************************************/
;/*                                                                       */
;/*            Copyright (c) 1994 -2000 Accelerated Technology, Inc.      */
;/*                                                                       */
;/* PROPRIETARY RIGHTS of Accelerated Technology are involved in the      */
;/* subject matter of this material.  All manufacturing, reproduction,    */
;/* use, and sales rights pertaining to this subject matter are governed  */
;/* by the license agreement.  The recipient of this software implicitly  */
;/* accepts the terms of the license.                                     */
;/*                                                                       */
;/*************************************************************************/
;
;/*************************************************************************/
;/*                                                                       */
;/* FILE NAME                                            VERSION          */
;/*                                                                       */
;/*      bootarm.s                                   ARM 6/7/9 1.11.19    */
;/*                                                                       */
;/* COMPONENT                                                             */
;/*                                                                       */
;/*      IN - Initialization                                              */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*                                                                       */
;/*      This file contains the target processor dependent initialization */
;/*      routines and data.                                               */
;/*                                                                       */
;/*                                                                       */
;/* DATA STRUCTURES                                                       */
;/*                                                                       */
;/*      INT_Vectors                         Interrupt vector table       */
;/*                                                                       */
;/* FUNCTIONS                                                             */
;/*                                                                       */
;/*      INT_Initialize                      Target initialization        */
;/*                                                                       */
;/*************************************************************************/


; If assembled with TASM the variable {CONFIG} will be set to 16
; If assembled with ARMASM the variable {CONFIG} will be set to 32
; Set the variable THUMB to TRUE or false depending on whether the
; file is being assembled with TASM or ARMASM.

        GBLL    THUMB
        GBLL    ARM
    [ {CONFIG} = 16
THUMB   SETL    {TRUE}
ARM     SETL    {FALSE}

; If assembling with TASM go into 32 bit mode as the Armulator will
; start up the program in ARM state.

        CODE32
    |
THUMB   SETL    {FALSE}
ARM     SETL    {TRUE}
    ]


   #include "reg_base.h"
   #include "bootarm.h"


;/* Define constants used in low-level initialization.  */
;
;
LOCKOUT                 EQU      &C0         ; Interrupt lockout value
LOCK_MSK                EQU      &C0         ; Interrupt lockout mask value
MODE_MASK               EQU      &1F         ; Processor Mode Mask
SUP_MODE                EQU      &13         ; Supervisor Mode (SVC)
   #if defined(__NUCLEUS_VERSION_2__)
KERN_MODE               EQU      &1f         ; Kernel Running Mode
   #else
KERN_MODE               EQU      &13         ; Kernel Running Mode
   #endif
IRQ_MODE                EQU      &12         ; Interrupt Mode (IRQ)
FIQ_MODE                EQU      &11         ; Fast Interrupt Mode (FIQ)
ABORT_MODE              EQU      &17         ; Abort Mode (Abort)
UND_MODE                EQU      &1b         ; Undefine Mode (Undefine)
SYS_MODE                EQU      &1f         ; System Mode (SYS)
                                            
TCM_SIZE_MASK           EQU      &7C

BOOTROM_FLASH_REMAP     EQU      &02
FLASH_SRAM_REMAP        EQU      &03

    #if defined(MT6251)
IRQ_STACK_SIZE          EQU      168
FIQ_STACK_SIZE          EQU      32
OTHER_STACK_SIZE        EQU      32          ; current max usage is 28B
    #else
IRQ_STACK_SIZE          EQU      168
FIQ_STACK_SIZE          EQU      128
OTHER_STACK_SIZE        EQU      128    
    #endif
    ; [BB Porting] For 3G project, use large EX_STACK_SIZE and SYS_STACK_SIZE
    #if defined(MT6276) || defined(MT6280) || defined(MT6573) || defined(MT6575) || defined(MT6577)
EX_STACK_SIZE           EQU      4096    
    #else
EX_STACK_SIZE           EQU      2048
    #endif
    #if defined(MT6268) || defined(MT6276) || defined(MT6280) || defined(MT6573) || defined(MT6575) || defined(MT6577)
SYS_STACK_SIZE          EQU      7196
    #else
SYS_STACK_SIZE          EQU      2048    
    #endif

; System stack in exception
EX_SYS_STACK_SIZE       EQU      256
ABNORMAL_POOL_SIZE      EQU      16

   PRESERVE8
   AREA |C$$data|, DATA, READWRITE
   
   EXPORT  INT_Loaded_Flag
INT_Loaded_Flag
   DCD      &00000000
   
;/* Define the global system stack variable.  This is setup by the
;   initialization routine.  */
;

   AREA |STACK_POOL_EXTSRAM|, DATA, READWRITE, ALIGN=3

ABT_Stack_Pool
   DCB      "STACKEND"
   SPACE    OTHER_STACK_SIZE-8

UND_Stack_Pool
   DCB      "STACKEND"
   SPACE    OTHER_STACK_SIZE-8

FIQ_Stack_Pool
   DCB      "STACKEND"
   SPACE    FIQ_STACK_SIZE-8

; /*
;  * NoteXXX: The exception stack space must be allocated in TCM for MT6235/8.
;  *          This is because the exception handler is special designed for MT6235/8.
;  */

EX_Stack_Pool
   DCB      "STACKEND"
   SPACE    EX_STACK_SIZE-8

   AREA |STACK_POOL_INTSRAM|, DATA, READWRITE, ALIGN=3

  
IRQ_Stack_Pool
   DCB      "STACKEND"
   SPACE    IRQ_STACK_SIZE-8

   EXPORT   SYS_Stack_Pool
SYS_Stack_Pool
   DCB      "STACKEND"
   #if defined(__ARM_FPUV2__)
   SPACE    SYS_STACK_SIZE+2432-8         ; Increase SYS stack size for saving FPU registers
   #else
   SPACE    SYS_STACK_SIZE-8
   #endif
      
EX_SYS_Stack_Pool
   DCB      "STACKEND"
   SPACE    EX_SYS_STACK_SIZE-8

Abnormal_info_Pool
   SPACE    ABNORMAL_POOL_SIZE

; ------------------------------------------------
; Dummy End pool for usage 
; -------------------------------------------------
   AREA |DUMMY_POOL|, DATA, READWRITE
DUMMY_END
   DCD      DUMMY_END_VAL
   
   AREA |DUMMY_DYNAMIC_CODE|, DATA, READWRITE
DYMANIC_CODE_DUMMY_END
   DCD      DUMMY_END_VAL

   AREA |DUMMY_ROM_HEAD|, DATA, READWRITE
DUMMY_ROM_RO_HEAD
   DCD      DUMMY_END_VAL
  
   AREA |INTSRAM_END|, DATA, READWRITE
INTSRAM_DUMMY_END
   DCD      DUMMY_END_VAL
  

   AREA |C$$code|, CODE, READONLY
|x$codeseg|

;
;
;/* Define the global data structures that need to be initialized by this
;   routine.  These structures are used to define the system timer management
;   HISR.  */
;
;
   IMPORT   Undef_Instr_ISR   
   IMPORT   SWI_ISR           
   IMPORT   Prefetch_Abort_ISR
   IMPORT   Data_Abort_ISR    
   IMPORT   INT_IRQ_Parse     
   IMPORT   INT_FIQ_Parse     
         
   ;Import function for OS: Nucleus
   #if defined(KAL_ON_NUCLEUS)

   #if defined(__NUCLEUS_VERSION_2__)
   IMPORT   ESAL_GE_STK_System_SP
   #else
   IMPORT   TCD_System_Stack
   IMPORT   TCT_System_Limit
   #endif

   IMPORT   INC_Initialize   

   #endif


   ;Import Initialize related function and data 
   IMPORT   g_WATCHDOG_RESTART_REG
   IMPORT   g_WATCHDOG_RESTART_VALUE
   
   #if !defined(MT6251)
   IMPORT   g_EMI_BASE_REG
   #endif
   
   IMPORT   g_ABNORMAL_RST_REG
   IMPORT   g_ABNORMAL_RST_VAL
   IMPORT   CachePreInit
   IMPORT   INT_SystemReset_Check 
   IMPORT   INT_GetRandomSeed
   IMPORT   INT_RetrieveBLShareinfo
   IMPORT   INT_BackupBLShareinfo
   IMPORT   INT_Config
   IMPORT   INT_InitRegions
   IMPORT   DCM_Prerequisite
   IMPORT   INT_InitEMIInitCode
   IMPORT   INT_InitPreInitData
   IMPORT   INT_InitMMRegions
   IMPORT   INT_ecoVersion
   IMPORT   CacheInit
   IMPORT   rand_num_seed
   IMPORT   eco_version

   IMPORT    PreInit_Seriport
   #if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)
   IMPORT   INT_InitBootupTrace
   #endif /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */

   IMPORT   gdb_init

   #if defined(MT6575) || defined(MT6577)  /* FCore + DSP_BOOT_SEC */
   IMPORT  dmdsp_init
   #endif

   #if defined(_NOR_LPSDRAM_MCP_)
   IMPORT   custom_InitDRAM
   #endif
   
   #if defined(__CHIP_VERSION_CHECK__)
   IMPORT   INT_Version_Check
   #endif

   IMPORT   SST_DTLB_Init

   #if defined(__ROMSA_SUPPORT__)
   IMPORT InitRegions2   
   IMPORT ROMSA_Init      
   #endif

   #if defined(ARM9_MMU) || defined(ARM11_MMU)
   IMPORT mk_tmp_pt
   #endif

   #if defined(ARM9_MMU) || defined(ARM11_MMU) || defined(__CR4__)
   IMPORT cp15_switch_vector
   #endif

   #if defined(__CR4__)
   IMPORT ||Image$$EMIINIT_CODE$$Base||
   IMPORT cp15_enable_atcm
   IMPORT ||Image$$INTSRAM_PHYSICAL_BOUNDARY$$Base||
   IMPORT cp15_enable_btcm
   
   IMPORT MpuPreInit
   
   IMPORT cp15_disable_atcmrmw
   IMPORT cp15_disable_btcmrmw
   
   #endif


   #if defined(ARM9_MMU)
   IMPORT cp15_enable_itcm
   IMPORT cp15_enable_dtcm
   IMPORT ||Image$$EMIINIT_CODE$$Base||
   IMPORT ||Image$$INTSRAM_DATA$$Base||
   #endif   /* ARM9_MMU */

   #if defined(ARM11_MMU)
   IMPORT cp15_enable_itcm
   IMPORT cp15_enable_dtcm
   IMPORT cp15_tcm_select
   IMPORT cp15_itcm_secure_access
   IMPORT cp15_dtcm_secure_access
   IMPORT cp15_read_itcm_region
   IMPORT cp15_read_dtcm_region

   IMPORT ||Image$$EMIINIT_CODE$$Base||
   IMPORT ||Image$$INTSRAM_DATA$$Base||
   #endif   /* ARM11_MMU */

   #if defined(__ARM_FPUV2__)
   IMPORT cp15_enable_cp
   IMPORT enable_arm_fpu
   IMPORT set_fpu_runfastmode
   IMPORT cp15_is_fpu_enabled
   #endif

   #if defined(MT6235) || defined(MT6235B)
   IMPORT sdram_sr_en
   #endif

   
   EXPORT  LDR_PC_Initialize ; used for vector table diagnosis
   EXPORT  MODE_MASK
   EXPORT  KERN_MODE
   EXPORT  BOOT_EX_Stack_End
   

;
;/* Define the ARM60 interrupt vector table, INT_Vectors.  This table is
;   assumed to be loaded or copied to address 0.  If coexistence with a
;   target-resident-monitor program is required, it is important to only
;   copy the IRQ and possibly the FIQ interrupt vectors in this table into
;   the actual table.  The idea is to not mess with the monitor's vectors.  */
;VOID    *INT_Vectors[NU_MAX_VECTORS];
;


   EXPORT  INT_Vectors
INT_Vectors
   #if defined(REMAPPING)
      B     INT_Initialize
   #else
      LDR   pc,INT_Table
   #endif
   LDR   pc,(INT_Table + 4)
   LDR   pc,(INT_Table + 8)
   LDR   pc,(INT_Table + 12)
   LDR   pc,(INT_Table + 16)
   LDR   pc,(INT_Table + 20)
   LDR   pc,(INT_Table + 24)
   LDR   pc,(INT_Table + 28)


   EXPORT   INT_Table
INT_Table

INT_Initialize_Addr  DCD   INT_Initialize
Undef_Instr_Addr     DCD   Undef_Instr_ISR
SWI_Addr             DCD   SWI_ISR
Prefetch_Abort_Addr  DCD   Prefetch_Abort_ISR
Data_Abort_Addr      DCD   Data_Abort_ISR
Undefined_Addr       DCD   0              ; NO LONGER USED
IRQ_Handler_Addr     DCD   INT_IRQ_Parse
FIQ_Handler_Addr     DCD   INT_FIQ_Parse

INT_Table_END

   #include "bootarm_rvct.inc"
   

LDR_PC_Initialize ; used to handle abnormal reset in remapping case
   DCD  PC_INITIALIZE_VAL ; ldr pc,INT_Table

   #if !defined(_NAND_FLASH_BOOTING_) && !defined(_NOR_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__)  
  
ROM_Base_Ptr
   IMPORT  |Image$$ROM$$Base|
   DCD     |Image$$ROM$$Base|

INT_Table_END_PTR
   DCD     INT_Table_END

   #else
   
   #if defined(__SV5_ENABLED__)
ROM_Base_Ptr
   IMPORT  |Image$$ROM$$Base|
   DCD     |Image$$ROM$$Base|

INT_Table_END_PTR
   DCD     INT_Table_END
   #endif
   
   #endif   


Loaded_Flag
   DCD     INT_Loaded_Flag



   #if defined(KAL_ON_NUCLEUS)
;
   #if defined(__NUCLEUS_VERSION_2__)
; Nucleus Plus2: rename TCD_System_Stack to ESAL_GE_STK_System_SP
; and remove TCT_System_Limit
System_Stack
   DCD     ESAL_GE_STK_System_SP
   #else
System_Stack
   DCD     TCD_System_Stack
;
System_Limit
   DCD     TCT_System_Limit
;
   #endif
   #else

System_Stack
   DCD     _tx_thread_system_stack_ptr
;
   #endif
   
BOOT_IRQ_Stack_End 
   DCD     IRQ_Stack_Pool+IRQ_STACK_SIZE-4
;
BOOT_FIQ_Stack_End 
   DCD     FIQ_Stack_Pool+FIQ_STACK_SIZE-4
;
BOOT_ABT_Stack_End 
   DCD     ABT_Stack_Pool+OTHER_STACK_SIZE-4
;
BOOT_UND_Stack_End 
   DCD     UND_Stack_Pool+OTHER_STACK_SIZE-4
;
   EXPORT   BOOT_SYS_Stack_End
BOOT_SYS_Stack_End 
   DCD     SYS_Stack_Pool+SYS_STACK_SIZE-4
;
BOOT_SYS_Stack
   DCD     SYS_Stack_Pool
;
BOOT_EX_Stack_End 
   DCD     EX_Stack_Pool+EX_STACK_SIZE-16
;
   EXPORT   BOOT_EX_SYS_Stack_End
BOOT_EX_SYS_Stack_End
   DCD     EX_SYS_Stack_Pool+EX_SYS_STACK_SIZE-4


   #if defined(MT6238) || defined(MT6239)
        IMPORT  mt6238_version
MT6238_VERSION
   DCD     mt6238_version    
   #endif  /* MT6238 || MT6239 */

   #if defined(MT6235) || defined(MT6235B)
        IMPORT  mt6235_version
MT6235_VERSION
   DCD     mt6235_version
   #endif  /* MT6235 || MT6235B */

	

   #if defined(REMAPPING)
MTK_INITIALIZE_PTR
   DCD     MTK_Initialize
   #endif
;
RAND_NUM_SEED_PTR
   DCD     rand_num_seed
;
ECO_VERSION_PTR
   DCD     eco_version
;
ABN_RST_PTR
   DCD     Abnormal_info_Pool
   DCD     DUMMY_END    ; dummy reference to ensure DUMMY_END won't be optimized
   DCD     DYMANIC_CODE_DUMMY_END    ; dummy reference to ensure DUMMY_END won't be optimized
   DCD     DUMMY_ROM_RO_HEAD          ; dummy reference to ensure DUMMY_END won't be optimized
   DCD     INTSRAM_DUMMY_END          ; dummy reference to ensure DUMMY_END won't be optimized

;
;
;/*************************************************************************/
;/*                                                                       */
;/* FUNCTION                                                              */
;/*                                                                       */
;/*      INT_Initialize                                                   */
;/*                                                                       */
;/* DESCRIPTION                                                           */
;/*                                                                       */
;/*      This function sets up the global system stack variable and       */
;/*      transfers control to the target independent initialization       */
;/*      function INC_Initialize.  Responsibilities of this function      */
;/*      include the following:                                           */
;/*                                                                       */
;/*             - Setup necessary processor/system control registers      */
;/*             - Initialize the vector table                             */
;/*             - Setup the system stack pointers                         */
;/*             - Setup the timer interrupt                               */
;/*             - Calculate the timer HISR stack and priority             */
;/*             - Calculate the first available memory address            */
;/*             - Transfer control to INC_Initialize to initialize all of */
;/*               the system components.                                  */
;/*                                                                       */
;/* CALLS                                                                 */
;/*                                                                       */
;/*      INC_Initialize                      Common initialization        */
;/*                                                                       */
;/* INPUTS                                                                */
;/*                                                                       */
;/*      None                                                             */
;/*                                                                       */
;/* OUTPUTS                                                               */
;/*                                                                       */
;/*      None                                                             */
;/*                                                                       */
;/*                                                                       */
;/*************************************************************************/
;VOID    INT_Initialize(void)
;{

   ENTRY

   EXPORT  INT_Initialize
INT_Initialize
;   /* Insure that the processor is in supervisor mode.  */
   MRS   a1,CPSR                            ; Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   ; Clear the mode bits
   ORR   a1,a1,#KERN_MODE                   ; Set the kernel mode bits
   ORR   a1,a1,#LOCKOUT                     ; Insure IRQ/FIQ interrupts are
                                            ; locked out
   MSR   CPSR_cxsf,a1                       ; Setup the new CPSR


   #if defined(REMAPPING)                           /* REMAPPING { */
 
   #if defined(MT6251)
 
   LDR   a4,SYSRAM_REMAP_REG
   LDR   a2,SYSRAM_REMAP_MASK
   LDR   a1,[a4]
   AND   a1,a1,a2
   CMP   a1,#0
   BNE   MTK_LoadPC
   
   #else
   
   LDR   a4,=EMI_base

   #if defined(EMI_REMAP_OFFSET_SUPPORT)
   LDR   a1,[a4,#REMAP_OFFSET]              ; Skip if it is an abnormal reset
   AND   a1,a1,#0x03                        ; under remapped configuration
   MOV   a2,#FLASH_SRAM_REMAP
   CMP   a1,a2
   #endif
   
   BEQ   MTK_LoadPC
   
   ; /* REMAPACTION */
   #if !(defined(__FOTA_ENABLE__) || defined(__BL_ENABLE__))
   
   #if defined(EMI_26MHZ_FILL)
   LDR   a1,EMI_26MHZ_SETTING               ; Setting EMI for 13MHz MCU clock
   STR   a1,[a4]                            ; C2WS=1, C2RS=1, WST=2, RLT=2
   STR   a1,[a4,#0x08]                      ; 16 bits device
   #endif

   MOV   a2,#BOOTROM_FLASH_REMAP            ; Restore remapping on \CS0 and \CS1
   
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
                                              

   #endif /* MT6251 */

   LDR   a1,ROM_Base_Ptr                    ; Copy Exception Vector table to RAM before remapping
   LDR   a2,REMAP_NOR_MASK
   AND   a1,a1,a2		    	    ; a1 will be the address with interrupt vector.
   LDR   v1,REMAP_NOR_ADDR
   LDR   a2,ROM_Base_Ptr                    ; use a2 and a3 to calculate the need address
   LDR   a3,INT_Table_END_PTR
   #if defined(MT6251)
    
   #else
   ORR   a3,a2,a3
   #endif
   
   LDR   a4, LDR_PC_Initialize
   STR   a4, [v1], #4
   ADD   a1,a1,#4
   ADD   a2,a2,#4
Copy_INT_Entry
   CMP   a2,a3  
   LDRLO a4,[a1], #4
   STRLO a4,[v1], #4
   ADDLO a2,a2,#4
   BLO   Copy_INT_Entry

   LDR   a1,ROM_Base_Ptr                    ; Copy needed code to avoid the code loss after remapping
   LDR   a2,REMAP_NOR_MASK		    ; a1 will be the address of NOR start address
   AND   a1,a1,a2
   LDR   a2,ROM_Base_Ptr

   #if defined(MT6251)
   ; adjust a2 to copy code before MTK_Initialize to SYSRAM
   LDR   a3,REMAP_NOR_MASK
   AND   a2,a2,a3
   LDR   a3,SYSRAM_Base_Ptr
   ORR   a2,a2,a3
   #endif
   
   LDR   a3,=MTK_Initialize
   
   #if defined(MT6251)
   ; mask leading bits representing bank address
   LDR   a4,REMAP_NOR_MASK
   AND   a3,a3,a4
   #endif
   
   ORR   a3,a2,a3
   LDR   a4,LDR_PC_Initialize
   STR   a4,[a2], #4
   ADD   a1,a1,#4
Copy_ROM_Entry
   CMP   a2,a3  
   LDRLO a4,[a1], #4
   STRLO a4,[a2], #4
   BLO   Copy_ROM_Entry

   ; DO REMAPPING
   #if defined(MT6251)

   LDR   a4,SYSRAM_REMAP_REG
   LDR   a2,SYSRAM_REMAP_KEY
   STR   a2,[a4] ; 1st write
   STR   a2,[a4] ; 2nd write
   
   ; make sure rempped
   LDR   a2,SYSRAM_REMAP_MASK
IS_REMAPPED
   LDR   a1,[a4]
   AND   a1,a1,a2
   CMP   a1,#0
   BEQ   IS_REMAPPED

   #else  /* MT6251 */

   LDR   a4,=EMI_base                 ; Remapping on \CS0 and \CS1
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
   
   #endif /* MT6251 */
   
   NOP
   NOP
   NOP
   NOP
   NOP
   NOP


MTK_LoadPC   
   LDR   pc,MTK_INITIALIZE_PTR   
   
MTK_Initialize   

   #endif                                    /*  REMAPPING  */

   #if defined(__SV5_ENABLED__)
   ; Check if abnromal reset first    
   LDR   a1,=g_ABNORMAL_RST_REG
   LDR   a1,[a1]
   LDR   a1,[a1]
   LDR   a2,=g_ABNORMAL_RST_VAL
   LDR   a2,[a2]
   CMP   a1,a2
   BEQ   Abnormal_RST
   ; SV5 Vector Copy
   LDR   a1,ROM_Base_Ptr                    ; Copy Exception Vector table to RAM before remapping
   MOV   v1,#0
   LDR   a2,ROM_Base_Ptr                    ; use a2 and a3 to calculate the need address
   LDR   a3,INT_Table_END_PTR
Copy_VEC_Entry
   CMP   a2,a3  
   LDRLO a4,[a1], #4
   STRLO a4,[v1], #4
   ADDLO a2,a2,#4
   BLO   Copy_VEC_Entry

Abnormal_RST
   #endif


   ; Restart watchdog in order to avoid the unexpected wdt reset when booting
   LDR   a1,=g_WATCHDOG_RESTART_REG            ; Restart watchdog
   LDR   a1,[a1]
   LDR   a2,=g_WATCHDOG_RESTART_VALUE
   LDR   a2,[a2]
   STR   a2,[a1]
      

;  /* Can not call any function which will use link register before save the abnormal reset value */ 
;  /* backup lr and sp for abnormal-reset scenario */
   MOV   v1,lr
   MOV   v2,sp

   ; /* MT6280 starts at high vector, set vector table to low address now. */
   #if defined(ARM9_MMU) || defined(ARM11_MMU) || defined(__CR4__)
   MOV r0, #0
   BL cp15_switch_vector   
   #endif

   ; Enable ARM9 TCM
   #if defined(ARM9_MMU)
   LDR r0, =||Image$$EMIINIT_CODE$$Base|| 
   BL cp15_enable_itcm

   LDR r0, =||Image$$INTSRAM_DATA$$Base||      
   BL cp15_enable_dtcm
   #endif

   ; Enable ARM11 TCM
   #if defined(ARM11_MMU)
;   /* Select I/DTCM0 */
      MOV r0, #0
      BL cp15_tcm_select
      
;   /* Enable access ITCM0 region register in security world*/
      MOV r0, #0
      BL cp15_itcm_secure_access
      
;   /* Enable access DTCM0 region register in security world*/
      MOV r0, #0
      BL cp15_dtcm_secure_access

;   /* Set base address of ITCM0*/
      LDR r0, =||Image$$EMIINIT_CODE$$Base|| 
      BL cp15_enable_itcm

;   /* Set base address of DTCM0*/
      LDR r0, =||Image$$INTSRAM_DATA$$Base||      
      BL cp15_enable_dtcm

;    /* Read itcm region register to get the size of ITCM bank0*/
      BL cp15_read_itcm_region
      AND r0, r0, #TCM_SIZE_MASK
;    /* if size equal 4KB, set r2=4 */
      CMP r0, #12
      MOVEQ r2, #4
;    /* if size equal 8KB, set r2=8 */
      CMP r0, #16
      MOVEQ r2, #8
;    /* if size equal 16KB, set r2=16 */
      CMP r0, #20
      MOVEQ r2, #16
;    /* if size equal 32KB, set r2=32 */
      CMP r0, #24
      MOVEQ r2, #32

;    /* Read dtcm region register to get the size of DTCM bank0*/
      BL cp15_read_dtcm_region
      AND r0, r0, #TCM_SIZE_MASK
;    /* if size equal 4KB, set r3=4 */
      CMP r0, #12
      MOVEQ r3, #4
;    /* if size equal 8KB, set r3=8 */
      CMP r0, #16
      MOVEQ r3, #8
;    /* if size equal 16KB, set r3=16 */
      CMP r0, #20
      MOVEQ r3, #16
;    /* if size equal 32KB, set r3=32 */
      CMP r0, #24
      MOVEQ r3, #32
      
;   /* Select I/DTCM1 */
      MOV r0, #1
      BL cp15_tcm_select
      
;   /* Enable access ITCM1 region register in security world*/
      MOV r0, #0
      BL cp15_itcm_secure_access
      
;   /* Enable access DTCM1 region register in security world*/
      MOV r0, #0
      BL cp15_dtcm_secure_access

;   /* Set base address of ITCM1 */
      LDR r0, =||Image$$EMIINIT_CODE$$Base|| 
      ADD r0, r0, r2, lsl #10
      BL cp15_enable_itcm

;   /* Set base address of DTCM1 */
      LDR r0, =||Image$$INTSRAM_DATA$$Base||      
      ADD r0, r0, r3, lsl #10
      BL cp15_enable_dtcm
 
   #endif

   #if defined(__CR4__)
      ; disable 64-bit read-modify-write of TCMs;
      BL cp15_disable_atcmrmw
      BL cp15_disable_btcmrmw
      
      ; MT6280: btcm placed before atcm
      #if defined(MT6280)
      LDR r0, =||Image$$EMIINIT_CODE$$Base|| 
      BL cp15_enable_btcm

      LDR r0, =||Image$$INTSRAM_PHYSICAL_BOUNDARY$$Base||
      BL cp15_enable_atcm
      
      ; TK6280: atcm placed before btcm
      #elif defined(TK6280
      LDR r0, =||Image$$EMIINIT_CODE$$Base|| 
      BL cp15_enable_atcm

      LDR r0, =||Image$$INTSRAM_PHYSICAL_BOUNDARY$$Base||
      BL cp15_enable_btcm     	
      #endif
      
   #endif

   #if defined(__ARM_FPUV2__)
   BL cp15_enable_cp
   BL enable_arm_fpu
   BL set_fpu_runfastmode
   #endif


;  /* save backup lr and sp for abnormal-reset scenario */
   LDR   a1,ABN_RST_PTR
   STR   v1,[a1]
   STR   v2,[a1,#0x4]

   LDR   a1,BOOT_SYS_Stack_End
   MOV   sp,a1                              ; Setup initial stack pointer

;  /* Check if abnormal reset */
   LDR   a1,ABN_RST_PTR
   BL    INT_SystemReset_Check

;  /* Version check should after abnormal reset check    */
;  /* to avoid calling tst_sys_trace when abnormal reset */
;  /* happends with interrupt disabled                   */
   #if defined(__CHIP_VERSION_CHECK__)
   LDR     a4,=INT_Version_Check
   MOV     lr, pc
   BX      a4
   #endif

   
   BL    SST_DTLB_Init
   
   BL    INT_GetRandomSeed
;  /*
;   * NoteXXX: Store the return value of INT_GetRandomSeed 
;   *          in r11 temporarily. Thus in the following program r11 should be
;   *          used before we store r11 back to rand_num_seed.
;   */
   MOV   r11,a1
      
;  /*
;   * NoteXXX: EMI initialized program is allocated at internal on MT6235.
;   *          We must initialize the code segment before initializing EMI.
;   */
;  /*
;   * NoteXXX: Not only for the HW bug of MT6235 series,
;   *          there is a potential bug in MT6253 EMI, and internal EMI initialization is also needed.
;   *          Finally, we determine to switch EMI to burst/page mode and setup PLL in internal memory regardless of platforms.
;   */
   #if defined(MT6252) || defined(MT6252H) || defined(MT6251) || defined(TK6280) || defined(MT6280)

   IMPORT   ||Image$$INTSRAM_DATA$$Base||
   LDR r0, =||Image$$INTSRAM_DATA$$Base|| 

   #else
   IMPORT   ||Image$$INTSRAM_MULTIMEDIA$$Base||, WEAK
   LDR r0, =||Image$$INTSRAM_MULTIMEDIA$$Base|| 


   #endif   
   BL    INT_BackupBLShareinfo

   BL    INT_InitEMIInitCode



;   /* used for PLL setting */
   BL     INT_ecoVersion
   LDR   a2, ECO_VERSION_PTR
   STR   a1,[a2]

;  /* configure EMI wait state after system stack is set up */
   BL    INT_Config

;  /* enable LPSDRAM */
   #if defined(_NOR_LPSDRAM_MCP_)
   #if !(defined(__FOTA_ENABLE__) || defined(__USB_DOWNLOAD__) || defined(__BL_ENABLE__))
   BL    custom_InitDRAM
   #endif
   #endif

;  /* make the temporary page table for the DCached region */
   #if defined(ARM9_MMU) || defined(ARM11_MMU)
   BLX   mk_tmp_pt
   #elif defined(__CR4__)
   BLX   MpuPreInit
   #else
   BLX   CachePreInit
   #endif

   BL   INT_InitPreInitData   

   LDR r0, =||Image$$INTSRAM_DATA$$Base||                     
                                                     
   BL    INT_RetrieveBLShareinfo            ; pass service		
;  /* Initialize regions */
;  /* Do NOT use any TCM data and global variable before here!!! */
   BL    INT_InitRegions                    ; in regioninit.s

;  /* Fixups before HW modules starting to acquire proper clock */
   BL    DCM_Prerequisite

;   /* must register HAL serial port for UART/USB EARLY usage */
;   /* (e.g. bootup trace, all time memory dump)              */
   BL    PreInit_Seriport
   #if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)
   BL    INT_InitBootupTrace
   #endif /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */

   BL    gdb_init
   
;  /* ROMSA */
   #if defined(__ROMSA_SUPPORT__)          
   BL    InitRegions2                      
   BL    ROMSA_Init                        
   #endif                                  

;  /* after INT_InitRegions, we can store the random number seed to rand_num_seed */
   LDR   a2,RAND_NUM_SEED_PTR
   STR   r11,[a2]

   #if defined(MT6238) || defined(MT6239)
   BL INT_ecoVersion			      
   LDR     a2, MT6238_VERSION
   STR     a1,[a2, #0]                        
   #endif

   #if defined(MT6235) || defined(MT6235B)
   BL INT_ecoVersion			      
   LDR     a2, MT6235_VERSION
   STR     a1,[a2, #0]
   #endif

;  /* use temp page table to initialize DMDSP execution environment */
;  /* for NAND Flash booting, dmdsp_init will be called in nfb_loader.c */
   #if !defined(_NAND_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__)
   #if defined(MT6575) || defined(MT6577)  /* FCore + DSP_BOOT_SEC */
   BL    dmdsp_init
   #endif
   #endif
   
   BL    CacheInit


;  /* initialize the multi-media region */
   BL    INT_InitMMRegions

   MOV   a1,#1                              ; All vectors are assumed loaded   
   LDR   a2, Loaded_Flag
   STR   a1,[a2,#0]                         ; Initialize loaded flag

   #if defined(KAL_ON_NUCLEUS)

   LDR   a1,BOOT_SYS_Stack            

   #if !defined(__NUCLEUS_VERSION_2__)
   LDR   a4,System_Limit                    ; Setup initial stack limit
   STR   a1,[a4, #0]                        ; Save stack limit   
   #endif

   #endif

   LDR   a4, System_Stack
   STR   sp,[a4, #0]                        ; Save stack pointer
   
   LDR   a3,BOOT_IRQ_Stack_End
   MRS   a1,CPSR                            ; Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   ; Clear the mode bits
   ORR   a1,a1,#IRQ_MODE                    ; Set the IRQ mode bits
   MSR   CPSR_cxsf,a1                       ; Move to IRQ mode
   MOV   sp,a3                              ; Setup IRQ stack pointer
   #if defined(__NUCLEUS_VERSION_2__)
   SUB   sp, #8                             ; Nucleus V2 sp adjust
   #endif

   LDR   a3,BOOT_FIQ_Stack_End
   MRS   a1,CPSR                            ; Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   ; Clear the mode bits
   ORR   a1,a1,#FIQ_MODE                    ; Set the FIQ mode bits
   MSR   CPSR_cxsf,a1                       ; Move to the FIQ mode
   MOV   sp,a3                              ; Setup FIQ stack pointer
   #if defined(__NUCLEUS_VERSION_2__)
   SUB   sp, #8                             ; Nucleus V2 sp adjust
   #endif

   LDR   a3,BOOT_ABT_Stack_End
   MRS   a1,CPSR                            ; Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   ; Clear the mode bits
   ORR   a1,a1,#ABORT_MODE                  ; Set the Abort mode bits
   MSR   CPSR_cxsf,a1                       ; Move to the Abort mode
   MOV   sp,a3                              ; Setup Abort stack pointer
   
   LDR   a3,BOOT_UND_Stack_End
   MRS   a1,CPSR                            ; Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   ; Clear the mode bits
   ORR   a1,a1,#UND_MODE                    ; Set the Undefine mode bits
   MSR   CPSR_cxsf,a1                       ; Move to the Undefine mode
   MOV   sp,a3                              ; Setup Undefine stack pointer

   LDR   a3,BOOT_SYS_Stack_End
   MRS   a1,CPSR                            ; Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   ; Clear the mode bits
   #if defined(__NUCLEUS_VERSION_2__)
   ORR   a1,a1,#SUP_MODE                    ; Set the Undefine mode bits
   #else
   ORR   a1,a1,#SYS_MODE                    ; Set the Undefine mode bits
   #endif
   MSR   CPSR_cxsf,a1                       ; Move to the Undefine mode
   MOV   sp,a3                              ; Setup Undefine stack pointer

   MRS   a1,CPSR                            ; Pickup current CPSR
   BIC   a1,a1,#MODE_MASK                   ; Clear mode bits
   ORR   a1,a1,#KERN_MODE                   ; Set the kernel running mode bits
   MSR   CPSR_cxsf,a1                       ; All interrupt stacks are setup,

   
   MOV   a1, #0

   #if defined(KAL_ON_NUCLEUS)

   [ THUMB
   LDR   a4,=INC_Initialize                 ; to high-level initialization
   BX    a4
   |
   B     INC_Initialize                     ; to high-level initialization
   ]

   #else

   [ THUMB
   LDR   a4,=_tx_initialize_kernel_enter    ; to high-level initialization
   BX    a4
   |
   B     _tx_initialize_kernel_enter        ; to high-level initialization
   ]

   #endif
;}


   END

