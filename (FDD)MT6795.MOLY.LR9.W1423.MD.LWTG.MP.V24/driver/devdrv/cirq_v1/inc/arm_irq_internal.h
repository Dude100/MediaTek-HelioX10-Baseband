/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   arm_irq.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Definition for internal definition related to ARM IRQ and FIQ
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __ARM_IRQ_INTERNAL_H__
#define __ARM_IRQ_INTERNAL_H__
/*******************************************************************************
 * Define MACRO to enable/disable IRQ and FIQ
 *******************************************************************************/

#define ORG_FBIT_IS_UNMASKED(irq)    (((irq) & 0x40) == 0)
#define ORG_IBIT_IS_UNMASKED(irq)    (((irq) & 0x80) == 0)
 
#if defined(__RVCT__)
#if defined(__ARM9_MMU__) || defined(__CPU_ARM9EJ_S__) || defined(__CPU_ARM7EJ_S__)

#define INT_BIT_IMMEDIATE  #0xC0
#define GET_AND_MASK_INT(ret) \
    do { \
        __asm \
        { \
            MRS     r0,CPSR; \
            AND     ret,r0,INT_BIT_IMMEDIATE; \
            ORR     r0,r0,INT_BIT_IMMEDIATE; \
            MSR     CPSR_c,r0; \
        } \
    } while(0)
#define RESTORE_INT(irq) \
    do { \
        __asm \
        { \
            MRS     r0,CPSR; \
            BIC     r0,r0,INT_BIT_IMMEDIATE; \
            AND     r1,irq,INT_BIT_IMMEDIATE; \
            ORR     r0,r0,r1; \
            MSR     CPSR_c,r0; \
        } \
    } while(0)

#else    /* __ARM9_MMU__ || __CPU_ARM9EJ_S__ || __CPU_ARM7EJ_S__ */

#define GET_AND_MASK_INT(ret) \
    do { \
        ret = __disable_irq() | __disable_fiq(); \
    } while(0)
#define RESTORE_INT(irq) \
    do { \
        if(ORG_FBIT_IS_UNMASKED(irq)) \
            __enable_fiq(); \
        if(ORG_IBIT_IS_UNMASKED(irq)) \
            __enable_irq(); \
    } while(0)

#endif    /* __ARM9_MMU__ || __CPU_ARM9EJ_S__ || __CPU_ARM7EJ_S__ */

#elif defined(__GNUC__)    /* __RVCT__ */
#if defined(__CR4__)

#define GET_AND_MASK_INT(ret) \
    do { \
        __asm__ ( \
            "mrs %0, cpsr\n\t" \
            "cpsid if\n\t" \
            "and %0, %0, #0xC0\n\t" \
            : "=r" (ret) \
            : \
        ); \
    } while(0)
/* Instruction count of using cpsie to restore I/F bit is more than using mrs/msr method. */
/* Therefore, RESTORE_INT still use original solution */
#define RESTORE_INT(irq) \
    do { \
        __asm__ ( \
            "mrs r1, cpsr\n\t" \
            "bic r1, r1, #0xC0\n\t" \
            "orr r1, r1, %0\n\t" \
            "msr cpsr_c, r1\n\t" \
            : \
            : "r" (irq) \
        ); \
    } while(0)
    
#else    /* __CR4__  */

#define GET_AND_MASK_INT(ret) \
    do { \
        ret = LockIRQ() & 0xC0; \
    } while(0)
#define RESTORE_INT(irq) \
    do { \
        RestoreIRQ(irq); \
    } while(0)
    
#endif    /* __CR4__ */
#endif    /* __RVCT__ */
#endif /* __ARM_IRQ_INTERNAL_H__ */
