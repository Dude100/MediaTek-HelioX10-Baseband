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
 *   bl_bootarm_gcc.s
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   This Module defines the boot sequence of asm level for unified bootloader
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

                
@        GBLL    THUMB
@        GBLL    ARM
@    [ {CONFIG} = 16
@THUMB   SETL    {TRUE}
@ARM     SETL    {FALSE}
@
@@ If assembling with TASM go into 32 bit mode as the Armulator will
@@ start up the program in ARM state.
@
@        .code 32
@    |
@THUMB   SETL    {FALSE}
@ARM     SETL    {TRUE}
@    ]
                
.set        Mode_USR,          0x10
.set        Mode_FIQ,          0x11
.set        Mode_IRQ,          0x12
.set        Mode_SVC,          0x13
.set        Mode_ABT,          0x17
.set        Mode_UNDEF,        0x1B
.set        Mode_SYS,          0x1F    

.set        SUP_MODE,          0x13                 @ Supervisor Mode (SVC)
.set        LOCKOUT,           0xC0                 @ Interrupt lockout value
.set        LOCK_MSK,          0xC0                 @ Interrupt lockout mask value
.set        MODE_MASK,         0x1F                 @ Processor Mode Mask
.set        I_BIT,             0x80                 @ Interrupt bit of CPSR and SPSR
.set        F_BIT,             0x40                 @ Interrupt bit of CPSR and SPSR
.set        INT_BIT,           0xC0                 @ Interrupt bits

#if defined(__MINI_BOOTLOADER__) && defined(__TIME_STAMP__)

.set        SPV_STACK_SIZE,    2048

#else

.set        SPV_STACK_SIZE,    4096

#endif

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

@   IF  (:LNOT: :DEF: __CHIP_VERSION_CHECK__)
@      GBLL         __CHIP_VERSION_CHECK__
@__CHIP_VERSION_CHECK__   SETL    {FALSE}
@   ENDIF
@
@   IF  (:LNOT: :DEF: __FOTA_ENABLE__)
@      GBLL         __FOTA_ENABLE__
@__FOTA_ENABLE__   SETL    {FALSE}
@   ENDIF
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
      @GCC_TODO:space without ZI AREA |STACK_POOL_INTSRAM|, DATA, NOINIT, ALIGN=3
      .align 3
      .section "STACK_POOL_INTSRAM", "w"
SPV_Stack_Pool:
   .space    SPV_STACK_SIZE

@      @AREA |DUMMY_POOL|, DATA, READWRITE
@      .section "DUMMY_POOL", "w", %progbits
@DUMMY_END:
@   .word      0x454E4400


      .align 3
@      AREA |C$$code|, CODE, READONLY
@      AREA |VECTOR_TBL|, CODE, READONLY
      .section "VECTOR_TBL", "ax"
      
@        .TEXT
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

_start:
   .global  INT_Vectors
INT_Vectors:
    B     ResetHandler
    
Undefined_Handler:
    B   Undefined_Handler
    
SWIHandler:
    B   SWIHandler

Prefetch_Handler:
    B   Prefetch_Handler

Abort_Handler:
    B   Abort_Handler
    
Reserved_vector:
    B   Reserved_vector

IrqHandler:
    B   IrqHandler

FiqHandler:   
    B   FiqHandler
    
      .section "C$$code", "ax"
   
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
   .global   JumpCmd

#if defined(__MINI_BOOTLOADER__)
#if defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6270A) || defined(MT6276) || defined(MT6256) || defined(MT6255) || defined(MT6280)
   .global   store_8word
   .global   load_8word
#endif
   
   .extern   TimeStampInit
   .extern   INT_ecoVersion
   .extern   eco_version
   .extern   Init_DTLB
   .extern   PreInit
   .extern   USBDLPreSet
   .extern   SetPLLEMI   
   .extern   Init
   .extern   GenerateRandomSeed
   .extern   custom_InitDRAM
   .extern   InitRegions

#if !defined(__SV5_ENABLED__)
#if defined(_NAND_FLASH_BOOTING_)
   .extern   PreserveExtBootloaderHeader
#endif
#endif

#if defined(__CHIP_VERSION_CHECK__)
#if !defined(__SKIP_VERSION_CHECK_FOR_BTMT__)
   .extern   INT_Version_Check
#endif
#endif

   .extern   LoadExtBootloader
   .extern   VerifyExtBootloader
   .extern   JumpToExtBootloader
   .extern   MiniBLErrorHandler
#endif


#if defined(__EXT_BOOTLOADER__)
   .extern   InitRegionsExt
   .extern   ExtBootloader
#endif


BOOT_Stack_End:
   .word   SPV_Stack_Pool+SPV_STACK_SIZE-4 

BOOT_Stack_Start:
   .word   SPV_Stack_Pool

@DUMMY_PTR:   @ dummy reference for dummy_end
@   .word   DUMMY_END

#if defined(__MINI_BOOTLOADER__)
ECO_VERSION_PTR:
   .word     eco_version
#endif

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#if defined(__MINI_BOOTLOADER__)
    
ResetHandler:
   @ Currently , system is not Remap yet

   @ Turn off I BIT , F BIT
   MRS   r0, CPSR
   ORR   r0, r0,#LOCKOUT
   MSR   CPSR_cxsf, r0

   MOV   r10, r4

   BL    USBDLPreSet

   @ Chip version check
#if defined(__CHIP_VERSION_CHECK__)
#if !defined(__SKIP_VERSION_CHECK_FOR_BTMT__)
   ;BL    INT_Version_Check
#endif
#endif

   @ Init TCM
   @ We directly use the D-TCM initialized by BootROM to make sure the base address is aligned
   BL    PreInit

   @ Initialize stack pointer for Supervisor Mode Stack
   LDR   r0, BOOT_Stack_End
   MOV   sp, r0

   @ initialize stack content as 0xFF
@   MOV   r2, #0xFFFFFFFF
@   LDR   r1, BOOT_Stack_Start
@stack_fill_ff:
@   CMP   r1, r0          @ loop whilst r0 < r1
@   STR   r2, [r0]
@   SUB   r0, r0, #4
@   BLO   stack_fill_ff 

   BL    Init_DTLB

   BL    TimeStampInit
   
@  /*
@   * NoteXXX: EMI initialized program is allocated at internal on MT6235, MT6238, and NOR platform (for MT6225. MT6253)
@   *          We must initialize the code segment before initializing EMI.
@   */
   .extern INT_InitEMIInitCode
   BL    INT_InitEMIInitCode

   @   /* used for PLL setting */
   BL    INT_ecoVersion
   LDR   r1, ECO_VERSION_PTR
   STR   r0,[r1]

   @  Unified Main Body for feature combination

   MOV  r0, r10
   BL   SetPLLEMI

   BL   custom_InitDRAM

#if !defined(__SV5_ENABLED__)
#if defined(_NAND_FLASH_BOOTING_)
   BL   PreserveExtBootloaderHeader
#endif
#endif

   BL   GenerateRandomSeed
   @ keep the seed in a unused register
   MOV  r11, r0
 
   BL   InitRegions

   MOV  r0, r11
   MOV  r1, r10
   BL   Init

   .extern CacheInitMini
   BL  CacheInitMini

   BL   LoadExtBootloader
   CMP  r0, #0xffffffff
   BEQ  End_BootLoader

   MOV  r4, r0   
   BL   VerifyExtBootloader
   CMP  r0, #0
   MOV  r0, r4

   BLNE JumpToExtBootloader

End_BootLoader:
   BL   MiniBLErrorHandler
   B    End_BootLoader

#endif


#if defined(__EXT_BOOTLOADER__)
    
ResetHandler:

   @ Initialize stack pointer for Supervisor Mode Stack
   LDR   r0, BOOT_Stack_End
   MOV   sp, r0

   @ initialize stack content as 0xFF
   MOV   r2, #0xFFFFFFFF
   LDR   r1, BOOT_Stack_Start
stack_fill_ff:
   CMP   r1, r0          @ loop whilst r0 < r1
   STR   r2, [r0]
   SUB   r0, r0, #4
   BLO   stack_fill_ff 

   BL    InitRegionsExt

   BL    ExtBootloader    @ Goto ExtBootloader

End_ExtBootLoader:
   B     End_ExtBootLoader

#endif
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

      .section "INTERNCODE", "ax"

JumpCmd:
   BX      r0

      .section "EMIINITCODE", "ax"


#if defined(__MINI_BOOTLOADER__)

#if defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6270A) || defined(MT6276) || defined(MT6256) || defined(MT6255) || defined(MT6280)
   
store_8word:

   STMDB   sp!, {r4,r5,r6,r7,r8,r9}
   MVN r3,r1
   ADD r4, r1, r1
   ADD r5, r3, r3
   ADD r6, r4, r4
   ADD r7, r5, r5
   ADD r8, r6, r6
   ADD r9, r7, r7
   STMIA   r0, {r1,r3,r4,r5,r6,r7,r8,r9}   
   
StoreEnd:
   LDMIA   sp!, {r4,r5,r6,r7,r8,r9}
   BX lr


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

load_8word:

   STMDB   sp!, {r4-r12}
   MOV r12,#0
   MVN r3,r1
   LDMIA   r0, {r4,r5,r6,r7,r8,r9,r10,r11}   
   CMP r4, r1
   MOVNE r12, #9
   BNE LoadEnd
   CMP r5, r3
   MOVNE r12, #10
   BNE LoadEnd
   ADD r1, r1, r1
   CMP r6, r1
   MOVNE r12, #11
   BNE LoadEnd
   ADD r3, r3, r3
   CMP r7, r3
   MOVNE r12, #12
   BNE LoadEnd
   
   ADD r1, r1, r1
   CMP r8, r1
   MOVNE r12, #13
   BNE LoadEnd
   ADD r3, r3, r3
   CMP r9, r3
   MOVNE r12, #14
   BNE LoadEnd
   ADD r1, r1, r1
   CMP r10, r1
   MOVNE r12, #15
   BNE LoadEnd
   ADD r3, r3, r3
   CMP r11, r3
   MOVNE r12, #16
   
LoadEnd:
   mov r0, r12
   LDMIA   sp!, {r4-r12}
   BX lr
   
#endif
      
#endif
      
   .end
