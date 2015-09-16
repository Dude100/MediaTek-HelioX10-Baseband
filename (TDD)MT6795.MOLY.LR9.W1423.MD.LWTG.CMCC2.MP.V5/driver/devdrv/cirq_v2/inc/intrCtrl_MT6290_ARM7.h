/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 *   intrCtrl_MT6290_ARM7.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Definition for chipset interrupt table
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __INTRCTRL_MT6290_ARM7_H__
#define __INTRCTRL_MT6290_ARM7_H__


#include "reg_base.h"
#include "irqid.h"
#include "drv_features_gpt.h"

#include "drv_arm7cirq.h"


/*******************************************************************************
 * Define CIRQ Registers 
 *******************************************************************************/


/*
 * CIRQ Interrupt Sources
 */
#define IRQ_UART1_CODE            ARM7_IRQID_UART_MD  /* UART1 Peripheral */
#define IRQ_UART2_CODE            ARM7_IRQID_UART_SH0 /* UART2 Peripheral */

#define IRQ_SW_LISR1_CODE        (MAX_ISR_NUM-3)
#define IRQ_SW_LISR2_CODE        (MAX_ISR_NUM-2)
#define IRQ_SW_LISR3_CODE        (MAX_ISR_NUM-1)
#define NUM_IRQ_SOURCES          (MAX_ISR_NUM)

#define IRQ_SYS_TIMER_CODE    (ARM7_IRQID_MDGPTM3 + DRV_GPT_SYSTEM_TIMER - 3)
//#define IRQ_GPTM1_CODE         MD_IRQID_MDGPTM_EVENT1  /* For System Tick */
//#define IRQ_GPTM2_CODE         MD_IRQID_MDGPTM_EVENT2
#define IRQ_GPTM3_CODE          ARM7_IRQID_MDGPTM3
#define IRQ_GPTM4_CODE          ARM7_IRQID_MDGPTM4
#define IRQ_GPTM5_CODE          ARM7_IRQID_MDGPTM5
#define IRQ_GPTM6_CODE          ARM7_IRQID_MDGPTM6

#define IRQ_TOPSM_CODE         MD_IRQID_MD_TOPSM

#define IRQ_SW_CODE_END       (IRQ_SW_LISR3_CODE)

/* workaround for build usim code temporary */
#define IRQ_SIM_CODE            MD_IRQID_USIM1-1
#define IRQ_SIM2_CODE           MD_IRQID_USIM2-2

/*                          
 * Define IRQ selection register assignment
 */                         
#define IRQSel()

#define INTERRUPT_PRIORITY_LIST \
    /*  0 ~  7 */  1,  1,  6,  4,  4,  1,  1,  7, \
    /*  8 ~ 15 */  7,  7,  7, 10, 10, 10,  1,  1, \
    /* 16 ~ 23 */  1, 11, 11, 11, 11, 15, 15,  5, \
    /* 24 ~ 31 */  1, 15, 11,  8,  8, 14,  0,  8, \


/*******************************************************************************
 * Special for display on SWDBG - MCU profiling
 *******************************************************************************/
#if (MAX_ISR_NUM<=32)
#define __CIRQ_MASK_REG_NR_1_NEW__
#else
    #error "Unsupport mask number"
#endif

#define IRQ_OSTIMER_ARM_CODE ARM7_IRQID_OSTIMER_INT

#define __ENABLE_SW_TRIGGER_INTERRUPT__

//#define EINT_TOTAL_CHANNEL 16

#define IRQ_MASK0              ((volatile UINT32P)(ARM7CIRQ_IMKR3100_REG))
//#define IRQ_MASK1              ((volatile UINT32P)(MDCIRQ_IMKR_BASE+0x0004))
//#define IRQ_MASK2              ((volatile UINT32P)(MDCIRQ_IMKR_BASE+0x0008))
//#define IRQ_MASK3              ((volatile UINT32P)(MDCIRQ_IMKR_BASE+0x000C))


typedef enum
{
   LISR_UART1     = IRQ_UART1_CODE,
   LISR_UART2     = IRQ_UART2_CODE
} LISR_IRQ_NO;
/*
enum Irq_Code_Def_Enum
{
    Enum_IRQ_CTIRQ1_CODE=0xC,
    Enum_IRQ_Code_End
};*/

#endif /* __INTRCTRL_MT6290_ARM7_H__ */
