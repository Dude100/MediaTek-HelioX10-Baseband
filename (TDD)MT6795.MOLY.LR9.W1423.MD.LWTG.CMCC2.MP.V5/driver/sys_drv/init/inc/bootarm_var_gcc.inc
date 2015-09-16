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
 *   bootarm_var_rvct.inc
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the constant used in assembly files.
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
 *****************************************************************************/

/* Define constants used in low-level initialization.  */

#define   LOCKOUT                       0xC0         // Interrupt lockout value
#define   LOCK_MSK                      0xC0         // Interrupt lockout mask value

#if defined(__THUMB2_UNIFIED__)
#define   MODE_MASK                     0x3F         // Processor Mode Mask
#define   SUP_MODE                      0x33         // Supervisor Mode (SVC)
   #if defined(__NUCLEUS_VERSION_2__)
#define   KERN_MODE                     0x3f         // Kernel Running Mode
   #else                   
#define   KERN_MODE                     0x33         // Kernel Running Mode
   #endif
#define   IRQ_MODE                      0x32         // Interrupt Mode (IRQ)
#define   FIQ_MODE                      0x31         // Fast Interrupt Mode (FIQ)
#define   ABORT_MODE                    0x37         // Abort Mode (Abort)
#define   UND_MODE                      0x3b         // Undefine Mode (Undefine)
#define   SYS_MODE                      0x3f         // System Mode (SYS)
#else /* else of __THUMB2_UNIFIED__ */
#define   MODE_MASK                     0x1F         // Processor Mode Mask
#define   SUP_MODE                      0x13         // Supervisor Mode (SVC)
   #if defined(__NUCLEUS_VERSION_2__)
#define   KERN_MODE                     0x1f         // Kernel Running Mode
   #else                   
#define   KERN_MODE                     0x13         // Kernel Running Mode
   #endif
#define   IRQ_MODE                      0x12         // Interrupt Mode (IRQ)
#define   FIQ_MODE                      0x11         // Fast Interrupt Mode (FIQ)
#define   ABORT_MODE                    0x17         // Abort Mode (Abort)
#define   UND_MODE                      0x1b         // Undefine Mode (Undefine)
#define   SYS_MODE                      0x1f         // System Mode (SYS)
                        
#endif /* __THUMB2_UNIFIED__ */                    
#define   TCM_SIZE_MASK                 0x7C
       
#define   BOOTROM_FLASH_REMAP           0x02
#define   FLASH_SRAM_REMAP              0x03
       
#define   IRQ_STACK_SIZE                168
#define   FIQ_STACK_SIZE                128
#define   OTHER_STACK_SIZE              128       

/* [BB Porting] */
   /* For SLT use large stack size for test*/
   #if defined(__IC_SLT__) && !defined(__MD2__)
   /* For 3G project use large EX_STACK_SIZE and SYS_STACK_SIZE */   
#define   EX_STACK_SIZE                 2048
#define   SYS_STACK_SIZE                (32*1024)
   #elif defined(MT6280) || defined(MT6575) || defined(MT6577)
#define   EX_STACK_SIZE                 4096    
#define   SYS_STACK_SIZE                7196
   #elif  defined(MT6290) || defined(MT6595) || (defined(MT6752) && defined(__MD1__))
#define   EX_STACK_SIZE                 4096    
#define   SYS_STACK_SIZE                8192
   #elif (defined(MT6752) && defined(__MD2__))
#define   EX_STACK_SIZE                 4096
#define   SYS_STACK_SIZE                2048
   #else
#error "Please define stack size for new chip"
   #endif
#define   EX_SYS_STACK_SIZE             256
#define   ABNORMAL_POOL_SIZE            16
