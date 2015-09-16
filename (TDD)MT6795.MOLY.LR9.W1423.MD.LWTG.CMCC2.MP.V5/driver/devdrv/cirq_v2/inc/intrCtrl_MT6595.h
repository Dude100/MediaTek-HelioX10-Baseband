/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   intrCtrl_MT6595.h
 *
 * Project:
 * --------
 *   TATAKA
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

#ifndef __INTRCTRL_MT6595_H__
#define __INTRCTRL_MT6595_H__


#include "reg_base.h"
#include "irqid.h"
#include "drv_features_gpt.h"
#include "drv_mdcirq.h"
#include "hisr_config.h"

/*******************************************************************************
 * Define CIRQ Registers 
 *******************************************************************************/


/*
 * CIRQ Interrupt Sources
 */

#define NUM_IRQ_SOURCES          (MAX_ISR_NUM)

#define IRQ_SYS_TIMER_CODE          (MD_IRQID_MDGPTM_EVENT1 + DRV_GPT_SYSTEM_TIMER - 1)
#define IRQ_TOPSM_CODE              MD_IRQID_MD_TOPSM
#define IRQ_OSTIMER_ARM_CODE        MD_IRQID_OST
#define IRQ_UART1_CODE              MD_IRQID_MDUART
#define IRQ_UART2_CODE              MD_IRQID_PERIUART0
#define IRQ_UART3_CODE              MD_IRQID_PERIUART1
#define IRQ_MDGDMA0_CODE            MD_IRQID_MDGDMA0
#define IRQ_MDGDMA1_CODE            MD_IRQID_MDGDMA1
#define IRQ_MDGDMA2_CODE            MD_IRQID_MDGDMA2
#define IRQ_MDGDMA3_CODE            MD_IRQID_MDGDMA3
#define IRQ_EINT0_CODE              MD_IRQID_EINT0
#define IRQ_EINT1_CODE              MD_IRQID_EINT1
#define IRQ_EINT2_CODE              MD_IRQID_EINT2
#define IRQ_EINT3_CODE              MD_IRQID_EINT3
#define IRQ_EINT_SHARE_CODE         MD_IRQID_EINT_SHARE
#define IRQ_LTE2MD_PEER_WAKEUP_CODE MD_IRQID_LTE2MD_PEER_WAKEUP
#define IRQ_DSP_IRQ_EVENT_CODE      MD_IRQID_DSP_IRQ_EVENT
#define IRQ_DSP_TIMER_CODE          MD_IRQID_DSP_TIMER
#define IRQ_DSP_L1DMA_CODE          MD_IRQID_DSP_L1DMA
#define IRQ_L2COPRO_CODE            MD_IRQID_L2COPRO
#define IRQ_LMAC_RAR_CODE           MD_IRQID_LMAC_RAR
#define IRQ_LMAC_EAR_CODE           MD_IRQID_LMAC_EAR
#define IRQ_TDD_WAKEUP_CODE         MD_IRQID_TDD_WAKEUP
#define IRQ_TDD_CODE                MD_IRQID_TDD_IRQ
#define IRQ_ALC1_CODE               MD_IRQID_ALC1
#define IRQ_MD_WDT_CODE             MD_IRQID_MD_WDT
#define IRQ_CCIF_ACK_CODE           MD_IRQID_CCIF_ACK
#define IRQ_CCIF_VLD_CODE           MD_IRQID_CCIF_VLD
#define IRQ_CLDMA_CODE              MD_IRQID_CLDMA
//#define IRQ_USB2_CODE               MD_IRQID_USB2
#define IRQ_USB3_CODE               MD_IRQID_USB3
#define IRQ_GPTM1_CODE              MD_IRQID_MDGPTM_EVENT1
#define IRQ_GPTM2_CODE              MD_IRQID_MDGPTM_EVENT2
#define IRQ_GPTM3_CODE              MD_IRQID_MDGPTM_EVENT3
#define IRQ_GPTM4_CODE              MD_IRQID_MDGPTM_EVENT4
#define IRQ_GPTM5_CODE              MD_IRQID_MDGPTM_EVENT5
#define IRQ_GPTM6_CODE              MD_IRQID_MDGPTM_EVENT6
#define IRQ_BUSMON1_CODE             MD_IRQID_BUSMON
#define IRQ_BUSMON2_CODE             MD_IRQID_MDMCU_BUSMON
#define IRQ_PCMON_CODE              MD_IRQID_PCMON
#define IRQ_SIM_CODE                MD_IRQID_USIM1
#define IRQ_SIM2_CODE               MD_IRQID_USIM2
#define IRQ_CA_DL_LMAC_RAR_CODE     MD_IRQID_CA_DL_LMAC_RAR
#define IRQ_CA_DL_LMAC_EAR_CODE     MD_IRQID_CA_DL_LMAC_EAR
#define IRQ_BSICTRL_IMM_RDINT_CODE  MD_IRQID_BSICTRL_IMM_RDINT
#define IRQ_CAIF_VALID_CODE         MD_IRQID_CAIF_VALID
#define IRQ_CAIF_ACK_CODE           MD_IRQID_CAIF_ACK
#define IRQ_A7WDT_CODE              MD_IRQID_A7WDT
#define IRQ_C1_IRQ_T1_CODE          MD_IRQID_C1_IRQ_T1
#define IRQ_C1_IRQ_T6_CODE          MD_IRQID_C1_IRQ_T6
#define IRQ_IDC2ARM_CODE            MD_IRQID_IDC2ARM
#define IRQ_AUXADC_CODE             MD_IRQID_AUXADC


/* SW triggered Interrupt CODE definition */
#define IRQ_SW_LISR1_CODE          MD_IRQID_RSV_0
#define IRQ_SW_LISR2_CODE          MD_IRQID_RSV_1
#define IRQ_SW_LISR3_CODE          MD_IRQID_RSV_2
#define IRQ_SW_LISR4_CODE          MD_IRQID_RSV_3
#define IRQ_SW_LISR5_CODE          MD_IRQID_RSV_4
#define IRQ_SW_LISR6_CODE          MD_IRQID_RSV_5
#define IRQ_SW_LISR7_CODE          MD_IRQID_RSV_6
#define IRQ_SW_LISR8_CODE          MD_IRQID_RSV_7
#define IRQ_SW_LISR9_CODE          MD_IRQID_RSV_10
#define IRQ_SW_LISR10_CODE         MD_IRQID_RSV_11
#define IRQ_SW_LISR11_CODE         MD_IRQID_RSV_12
#define IRQ_SW_CODE_END            IRQ_SW_LISR11_CODE

#define IRQ_MDDBG_CODE             IRQ_SW_LISR6_CODE

#define IRQ_RXADC_OVLD_ANT1_CODE   MD_IRQID_MODEMSYS_00
#define IRQ_RXADC_OVLD_ANT0_CODE   MD_IRQID_MODEMSYS_01
#define IRQ_RXBRP_HS_CODE          MD_IRQID_MODEMSYS_02
#define IRQ_LOG3G_CODE             MD_IRQID_MODEMSYS_03   /* log3g_buf_irq_b */
#define IRQ_SEARCHER_CODE          MD_IRQID_MODEMSYS_04
#define IRQ_PI_CODE                MD_IRQID_MODEMSYS_05
#define IRQ_AI_CODE                MD_IRQID_MODEMSYS_06
#define IRQ_TFCI_1_CODE            MD_IRQID_MODEMSYS_07
#define IRQ_TFCI_0_CODE            MD_IRQID_MODEMSYS_08
#define IRQ_RXBRP_CCB_CODE         MD_IRQID_MODEMSYS_09
#define IRQ_RXBRP_CC1_CODE         MD_IRQID_MODEMSYS_10
#define IRQ_RXBRP_CC0_CODE         MD_IRQID_MODEMSYS_11
#define IRQ_F8F9_CODE              MD_IRQID_MODEMSYS_12   /* uea_uia_irq_b */
#define IRQ_L2DPA_CODE             MD_IRQID_MODEMSYS_13
#define IRQ_L2UPA_CODE             MD_IRQID_MODEMSYS_14
#define IRQ_BITCP_CODE             MD_IRQID_MODEMSYS_15
#define IRQ_TXUPC_DSP_CODE         MD_IRQID_MODEMSYS_16   /* txupc_dsp_irq_b */
#define IRQ_HSDPA_BC_CODE          MD_IRQID_MODEMSYS_17
#define IRQ_PFC_DEC_CODE           MD_IRQID_MODEMSYS_18
#define IRQ_PFC_ENC_CODE           MD_IRQID_MODEMSYS_19
#define IRQ_WTIMER_CODE            MD_IRQID_MODEMSYS_20
#define IRQ_RTR_SLT_CODE           MD_IRQID_MODEMSYS_21
#define IRQ_RTR_FRAME_CODE         MD_IRQID_MODEMSYS_22
#define IRQ_MODEM2G_TOPSM_CODE     MD_IRQID_MODEMSYS_23
#define IRQ_MD_SLEEP_CODE          MD_IRQID_MODEMSYS_24   /* topsm_irq_b, slp_ctrl_irq_b */
#define IRQ_CTIRQ3_CODE            MD_IRQID_MODEMSYS_25
#define IRQ_CTIRQ2_CODE            MD_IRQID_MODEMSYS_26
#define IRQ_CTIRQ1_CODE            MD_IRQID_MODEMSYS_27
#define IRQ_TDMA_CODE              MD_IRQID_MODEMSYS_28
#define IRQ_IRDEBUG_CODE           MD_IRQID_MODEMSYS_29
#define IRQ_DSP2CPU_CODE           MD_IRQID_MODEMSYS_30   /* share_d12_mint_B */

/* needed for esim */
#ifdef ESIM_BUILD_CONFIG
#define IRQ_EIT_CODE              (44) /* should be placed in irqid_MT7208.h !!!!, possibly use this #define MD_IRQID_EINT0  (46) */

#define IRQID_DSP_IRQ_EVENT   MD_IRQID_DSP_IRQ_EVENT
#define IRQID_DSP_TIMER       MD_IRQID_DSP_TIMER

#define CIRQ_base  BASE_ADDR_MDCIRQ

/* Taken fromintrCtrl_MT6280.h */
#define IRQ_FSEL0             ((volatile UINT32P)(CIRQ_base+0x0180)) /* FIQ Source selection 0x0 to 0x1F */
#define IRQ_FSEL1             ((volatile UINT32P)(CIRQ_base+0x0184)) /* FIQ Source selection 0x20 to 0x3F */
#define IRQ_FSEL2             ((volatile UINT32P)(CIRQ_base+0x0188)) /* FIQ Source selection 0x40 to 0x4F */

/* taken from mt6238.h */
#define IRQ_EOIL   ((UINT32P)(CIRQ_base+0x0058))
#define IRQ_EOIH   ((UINT32P)(CIRQ_base+0x005C))
#define IRQ_SENSL  ((UINT32P)(CIRQ_base+0x0060))
#define IRQ_SENSH  ((UINT32P)(CIRQ_base+0x0064))
#define IRQ_SOFTL  ((UINT32P)(CIRQ_base+0x0068))
#define IRQ_SOFTH  ((UINT32P)(CIRQ_base+0x006C))
#define FIQ_CON    ((UINT32P)(CIRQ_base+0x0070))
#define FIQ_EOI    ((UINT32P)(CIRQ_base+0x0074))
#define IRQ_STA2   ((UINT32P)(CIRQ_base+0x0078))

#endif





/*                          
 * Define IRQ selection register assignment
 */                         
#define IRQSel()
#define INVALID_ISR_ID           (0xFF)

#if defined(__UNIFIED_ISR_LEVEL__)

  #define IRQ_HISR0_CODE         (92)
  #define IRQ_HISR1_CODE         (93)
  #define IRQ_HISR2_CODE         (94)

  /* ID Mapping Changed Because Different Feature Setting */
  #if defined(__EVENT_BASED_TIMER__)
    #define CHANGE_MAPPING_BY_FEATURE_99 INVALID_ISR_ID
  #else /* __EVENT_BASED_TIMER__ */
    #define CHANGE_MAPPING_BY_FEATURE_99 IRQ_SYS_TIMER_CODE
  #endif /* __EVENT_BASED_TIMER__ */

  #if defined(USB30_ENABLE)
    #define CHANGE_MAPPING_BY_FEATURE_74 IRQ_USB3_CODE
  #elif defined(IRQ_USB2_CODE) /* USB30_ENABLE */
    #define CHANGE_MAPPING_BY_FEATURE_74 IRQ_USB2_CODE
  #else
    #define CHANGE_MAPPING_BY_FEATURE_74 INVALID_ISR_ID
  #endif /* USB30_ENABLE */

#define KAL_INTID_2_CODE_MAPPNG \
    /*  0 ~  3 */ INVALID_ISR_ID,     IRQ_WTIMER_CODE,            IRQ_RTR_SLT_CODE,        IRQ_AI_CODE, \
    /*  4 ~  7 */ IRQ_PI_CODE,        IRQ_LTE2MD_PEER_WAKEUP_CODE,IRQ_DSP_IRQ_EVENT_CODE,  IRQ_DSP_TIMER_CODE, \
    /*  8 ~ 11 */ IRQ_L2COPRO_CODE,   IRQ_SW_LISR5_CODE,          IRQ_LMAC_RAR_CODE,       IRQ_LMAC_EAR_CODE, \
    /* 12 ~ 15 */ IRQ_SEARCHER_CODE,  IRQ_TFCI_0_CODE,            IRQ_TFCI_1_CODE,         IRQ_RXBRP_CC0_CODE, \
    /* 16 ~ 19 */ IRQ_RXBRP_CC1_CODE, IRQ_RXBRP_CCB_CODE,         IRQ_TDMA_CODE,           IRQ_CTIRQ1_CODE, \
    /* 20 ~ 23 */ IRQ_CTIRQ2_CODE,    IRQ_RXBRP_HS_CODE,          IRQ_RXADC_OVLD_ANT0_CODE,IRQ_RXADC_OVLD_ANT1_CODE, \
    /* 24 ~ 27 */ IRQ_TDD_WAKEUP_CODE,IRQ_SW_LISR2_CODE,          IRQ_SW_LISR1_CODE,       IRQ_SW_LISR3_CODE, \
    /* 28 ~ 31 */ IRQ_SW_LISR4_CODE,  IRQ_RTR_FRAME_CODE,         IRQ_TOPSM_CODE,          IRQ_OSTIMER_ARM_CODE, \
    /* 32 ~ 35 */ IRQ_CTIRQ3_CODE,    IRQ_TDD_CODE,               IRQ_MODEM2G_TOPSM_CODE,  IRQ_HSDPA_BC_CODE, \
    /* 36 ~ 39 */ IRQ_L2DPA_CODE,     INVALID_ISR_ID,             IRQ_TXUPC_DSP_CODE,      INVALID_ISR_ID, \
    /* 40 ~ 43 */ IRQ_IRDEBUG_CODE,   IRQ_DSP2CPU_CODE,           IRQ_MD_SLEEP_CODE,       IRQ_LOG3G_CODE, \
    /* 44 ~ 47 */ IRQ_MDGDMA2_CODE,   IRQ_EINT0_CODE,             IRQ_EINT1_CODE,          IRQ_EINT2_CODE, \
    /* 48 ~ 51 */ IRQ_EINT3_CODE,     IRQ_EINT_SHARE_CODE,        INVALID_ISR_ID,          INVALID_ISR_ID, \
    /* 52 ~ 55 */ INVALID_ISR_ID,     IRQ_SIM_CODE,               IRQ_SIM2_CODE,           IRQ_DSP_L1DMA_CODE, \
    /* 56 ~ 59 */ IRQ_ALC1_CODE,      INVALID_ISR_ID,             IRQ_IDC2ARM_CODE,        INVALID_ISR_ID, \
    /* 60 ~ 63 */ IRQ_L2UPA_CODE,     IRQ_F8F9_CODE,              IRQ_BITCP_CODE,          INVALID_ISR_ID, \
    /* 64 ~ 67 */ INVALID_ISR_ID,     INVALID_ISR_ID,             INVALID_ISR_ID,          INVALID_ISR_ID, \
    /* 68 ~ 71 */ IRQ_MDDBG_CODE,     INVALID_ISR_ID,             INVALID_ISR_ID,          INVALID_ISR_ID, \
    /* 72 ~ 75 */ INVALID_ISR_ID,     INVALID_ISR_ID,             CHANGE_MAPPING_BY_FEATURE_74, INVALID_ISR_ID, \
    /* 76 ~ 79 */ IRQ_CLDMA_CODE,     INVALID_ISR_ID,             INVALID_ISR_ID,          IRQ_CCIF_VLD_CODE, \
    /* 80 ~ 83 */ IRQ_CCIF_ACK_CODE,  INVALID_ISR_ID,             INVALID_ISR_ID,          INVALID_ISR_ID, \
    /* 84 ~ 87 */ INVALID_ISR_ID,     INVALID_ISR_ID,             INVALID_ISR_ID,          INVALID_ISR_ID, \
    /* 88 ~ 91 */ INVALID_ISR_ID,     INVALID_ISR_ID,             INVALID_ISR_ID,          INVALID_ISR_ID, \
    /* 92 ~ 95 */ INVALID_ISR_ID,     INVALID_ISR_ID,             INVALID_ISR_ID,          INVALID_ISR_ID, \
    /* 96 ~ 99 */ INVALID_ISR_ID,     INVALID_ISR_ID,             INVALID_ISR_ID,          CHANGE_MAPPING_BY_FEATURE_99, \
    /*100 ~103 */ IRQ_GPTM1_CODE,     IRQ_GPTM2_CODE,             INVALID_ISR_ID,          IRQ_UART1_CODE, \
    /*104 ~107 */ IRQ_UART2_CODE,     IRQ_BUSMON1_CODE,            IRQ_GPTM3_CODE,          INVALID_ISR_ID, \
    /*108 ~111 */ IRQ_BUSMON2_CODE,     INVALID_ISR_ID,             INVALID_ISR_ID,          IRQ_MDGDMA0_CODE, \
    /*112 ~115 */ INVALID_ISR_ID,     INVALID_ISR_ID,             INVALID_ISR_ID,          INVALID_ISR_ID, \
    /*116 ~119 */ INVALID_ISR_ID,     INVALID_ISR_ID,             INVALID_ISR_ID,          INVALID_ISR_ID, \
    /*120 ~123 */ IRQ_HISR0_CODE,     IRQ_HISR1_CODE,             IRQ_HISR2_CODE,          INVALID_ISR_ID, \
    /*124 ~127 */ INVALID_ISR_ID,     INVALID_ISR_ID,             INVALID_ISR_ID,          INVALID_ISR_ID, \
    /*128 ~MAX */ INVALID_ISR_ID,     INVALID_ISR_ID

#else /* __UNIFIED_ISR_LEVEL__  */

#if defined(__FPGA__)
  #define INTERRUPT_PRIORITY_LIST \
    /*  0 ~  7 */  5, 10,  1,  1,  3,  3,  4,  4, \
    /*  8 ~ 15 */  4,  5,  5,  5,  6,  8,  8,  8, \
    /* 16 ~ 23 */  8,  8,  8,  8,  7,  7,  7,  7, \
    /* 24 ~ 31 */  7,  7,  7, 10, 10, 11, 11, 11, \
    /* 32 ~ 39 */ 12, 12, 12, 13, 13,  9,  1,  1, \
    /* 40 ~ 47 */ 10, 10, 11, 11, 11, 11,  8,  8, \
    /* 48 ~ 55 */  8,  8,  8,  8, 10, 15, 15, 15, \
    /* 56 ~ 63 */  0,  2,  4,  6,  8, 10, 12, 14
#else /* FPGA */
  #if defined(__AST_TL1_TDD__)
    #define INTERRUPT_PRIORITY_LIST \
    /*  0 ~  7 */ 35, 63, 13, 14, 63, 63, 63, 63, \
    /*  8 ~ 15 */ 63, 63, 63, 63, 11, 61, 63, 61, \
    /* 16 ~ 23 */ 63, 63, 63, 63, 63, 63, 63, 63, \
    /* 24 ~ 31 */ 63, 63, 63, 63, 63, 63, 63, 63, \
    /* 32 ~ 39 */ 63, 63, 63, 63, 63, 63,  9, 10, \
    /* 40 ~ 47 */ 63, 63, 63, 63, 63, 63, 63, 63, \
    /* 48 ~ 55 */ 63, 63, 63, 63, 63, 63, 34, 28, \
    /* 56 ~ 63 */ 27, 63, 63, 63, 29, 30, 31, 33, \
    /* 64 ~ 71 */ 12, 63, 63, 63, 63, 63, 63, 63, \
    /* 72 ~ 79 */ 63, 63, 63, 63, 63, 63, 63,  8, \
    /* 80 ~ 87 */ 63, 63, 63, 63, 63, 63, 63, 63, \
    /* 88 ~ 95 */ 63, 63, 63, 63, 61, 62, 63, 63, \
    /* 96 ~103 */ 26, 25, 24, 46, 15,  7,  6, 17, \
    /*104 ~111 */ 16, 20, 19, 18, 37, 39, 40, 42, \
    /*112 ~119 */ 41, 38, 63, 63,  4,  5, 32, 63, \
    /*120 ~127 */ 45, 36, 23, 22, 21, 43, 44, 63
  #else /* __AST_TL1_TDD__ */
    #define INTERRUPT_PRIORITY_LIST \
    /*  0 ~  7 */ 34, 63, 13, 14, 63, 63, 63, 63, \
    /*  8 ~ 15 */ 63, 63, 63, 63, 11, 61, 63, 61, \
    /* 16 ~ 23 */ 63, 63, 63, 63, 63, 63, 63, 63, \
    /* 24 ~ 31 */ 63, 63, 63, 63, 63, 63, 63, 63, \
    /* 32 ~ 39 */ 63, 63, 63, 63, 63, 63,  9, 10, \
    /* 40 ~ 47 */ 63, 63, 63, 63, 63, 63, 63, 63, \
    /* 48 ~ 55 */ 63, 63, 63, 63, 63, 63, 33, 36, \
    /* 56 ~ 63 */ 27, 63, 63, 63, 29, 28, 30, 31, \
    /* 64 ~ 71 */ 12, 63, 63, 63, 63, 63, 63, 63, \
    /* 72 ~ 79 */ 63, 63, 63, 63, 63, 63, 63,  8, \
    /* 80 ~ 87 */ 63, 63, 63, 63, 63, 63, 63, 63, \
    /* 88 ~ 95 */ 63, 63, 63, 63, 61, 62, 63, 63, \
    /* 96 ~103 */ 26, 25, 24, 46, 15,  7,  6, 17, \
    /*104 ~111 */ 16, 20, 19, 18, 37, 39, 40, 42, \
    /*112 ~119 */ 41, 38, 63, 63,  4,  5, 32, 63, \
    /*120 ~127 */ 45, 35, 23, 22, 21, 43, 44, 63

  #endif /* __AST_TL1_TDD__ */

#endif /* FPGA */

#endif /* __UNIFIED_ISR_LEVEL__  */


/*******************************************************************************
 * Special for display on SWDBG - MCU profiling
 *******************************************************************************/
#if (MAX_ISR_NUM<=32)
#define __CIRQ_MASK_REG_NR_1_NEW__
#elif (MAX_ISR_NUM<=64)
#define __CIRQ_MASK_REG_NR_2_NEW__
#elif (MAX_ISR_NUM<=96)
#define __CIRQ_MASK_REG_NR_3_NEW__
#elif (MAX_ISR_NUM<=128)
#define __CIRQ_MASK_REG_NR_4_NEW__
#else
    #error "Unsupport mask number"
#endif

#define __ENABLE_SW_TRIGGER_INTERRUPT__

#define EINT_TOTAL_CHANNEL 16

#define IRQ_MASK0              ((volatile UINT32P)(MDCIRQ_IMKR_BASE+0x0000))
#define IRQ_MASK1              ((volatile UINT32P)(MDCIRQ_IMKR_BASE+0x0004))
#define IRQ_MASK2              ((volatile UINT32P)(MDCIRQ_IMKR_BASE+0x0008))
#define IRQ_MASK3              ((volatile UINT32P)(MDCIRQ_IMKR_BASE+0x000C))


typedef enum
{
   LISR_UART1     = IRQ_UART1_CODE,
   LISR_UART2     = IRQ_UART2_CODE
} LISR_IRQ_NO;

enum Irq_Code_Def_Enum
{
    Enum_IRQ_WTMR_CODE               = IRQ_WTIMER_CODE,
    Enum_IRQ_RTRSLT_CODE             = IRQ_RTR_SLT_CODE,
    Enum_IRQ_AI_CODE                 = IRQ_AI_CODE,
    Enum_IRQ_PI_CODE                 = IRQ_PI_CODE,
    Enum_IRQ_SRCHR_CODE              = IRQ_SEARCHER_CODE,
    Enum_IRQ_TFCI0_CODE              = IRQ_TFCI_0_CODE,
    Enum_IRQ_TFCI1_CODE              = IRQ_TFCI_1_CODE,
    Enum_IRQ_RXBRP0_CODE             = IRQ_RXBRP_CC0_CODE,
    Enum_IRQ_RXBRP1_CODE             = IRQ_RXBRP_CC1_CODE,
    Enum_IRQ_RXBRPB_CODE             = IRQ_RXBRP_CCB_CODE,
    Enum_IRQ_TDMA_CODE               = IRQ_RXBRP_CC0_CODE,
    Enum_IRQ_CTIRQ1_CODE             = IRQ_CTIRQ1_CODE,
    Enum_IRQ_CTIRQ2_CODE             = IRQ_CTIRQ2_CODE,
#if defined(__AST_TL1_TDD__)
    Enum_IRQ_HIF_SW_CODE             = IRQ_SW_LISR2_CODE,
    Enum_IRQ_TL1_SW_CODE             = IRQ_SW_LISR1_CODE,
#else
    Enum_IRQ_SISR1_CODE              = IRQ_SW_LISR1_CODE,
    Enum_IRQ_SISR2_CODE              = IRQ_SW_LISR2_CODE,
#endif
    Enum_IRQ_SISR3_CODE              = IRQ_SW_LISR3_CODE,
    Enum_IRQ_SISR4_CODE              = IRQ_SW_LISR4_CODE,
    Enum_IRQ_SISR5_CODE              = IRQ_SW_LISR5_CODE,
    Enum_IRQ_RXBRPHS_CODE            = IRQ_RXBRP_HS_CODE,
    Enum_IRQ_RXADC0_CODE             = IRQ_RXADC_OVLD_ANT0_CODE,
    Enum_IRQ_RXADC1_CODE             = IRQ_RXADC_OVLD_ANT1_CODE,
    Enum_IRQ_OSTIMER_ARM_CODE        = IRQ_OSTIMER_ARM_CODE,
    Enum_IRQ_TDD_CODE                = IRQ_TDD_CODE,
    Enum_IRQ_TDD_WAKEUP_CODE         = IRQ_TDD_WAKEUP_CODE,
    Enum_IRQ_TOPSM_CODE	             = IRQ_TOPSM_CODE,
    Enum_IRQ_UART1_CODE              = IRQ_UART1_CODE,
    Enum_IRQ_UART2_CODE              = IRQ_UART2_CODE,
//    Enum_IRQ_UART3_CODE              = IRQ_UART3_CODE,
    Enum_IRQ_MDGDMA0_CODE            = IRQ_MDGDMA0_CODE,
    Enum_IRQ_MDGDMA1_CODE            = IRQ_MDGDMA1_CODE,
    Enum_IRQ_MDGDMA2_CODE            = IRQ_MDGDMA2_CODE,
    Enum_IRQ_MDGDMA3_CODE            = IRQ_MDGDMA3_CODE,
    Enum_IRQ_EINT0_CODE              = IRQ_EINT0_CODE,
    Enum_IRQ_EINT1_CODE              = IRQ_EINT1_CODE,
    Enum_IRQ_EINT2_CODE              = IRQ_EINT2_CODE,
    Enum_IRQ_EINT3_CODE              = IRQ_EINT3_CODE,
    Enum_IRQ_EINT_SHARE_CODE         = IRQ_EINT_SHARE_CODE,
    Enum_IRQ_LTE2MD_PEER_WAKEUP_CODE = IRQ_LTE2MD_PEER_WAKEUP_CODE,
    Enum_IRQ_DSP_IRQ_EVENT_CODE      = IRQ_DSP_IRQ_EVENT_CODE,
    Enum_IRQ_DSP_TIMER_CODE          = IRQ_DSP_TIMER_CODE,
    Enum_IRQ_DSP_L1DMA_CODE          = IRQ_DSP_L1DMA_CODE,
    Enum_IRQ_L2COPRO_CODE            = IRQ_L2COPRO_CODE,
    Enum_IRQ_LMAC_RAR_CODE           = IRQ_LMAC_RAR_CODE,
    Enum_IRQ_LMAC_EAR_CODE           = IRQ_LMAC_EAR_CODE,
    Enum_IRQ_ALC1_CODE               = IRQ_ALC1_CODE,
    Enum_IRQ_MD_WDT_CODE             = IRQ_MD_WDT_CODE,
    Enum_IRQ_CCIF_ACK_CODE           = IRQ_CCIF_ACK_CODE,
    Enum_IRQ_CCIF_VLD_CODE           = IRQ_CCIF_VLD_CODE,
    Enum_IRQ_CLDMA_CODE              = IRQ_CLDMA_CODE,
//    Enum_IRQ_USB2_CODE               = IRQ_USB2_CODE,
    Enum_IRQ_USB3_CODE               = IRQ_USB3_CODE,
    Enum_IRQ_GPTM1_CODE              = IRQ_GPTM1_CODE,
    Enum_IRQ_GPTM2_CODE              = IRQ_GPTM2_CODE,
    Enum_IRQ_GPTM3_CODE              = IRQ_GPTM3_CODE,
    Enum_IRQ_GPTM4_CODE              = IRQ_GPTM4_CODE,
    Enum_IRQ_GPTM5_CODE              = IRQ_GPTM5_CODE,
    Enum_IRQ_GPTM6_CODE              = IRQ_GPTM6_CODE,
    Enum_IRQ_BUSMON1_CODE             = IRQ_BUSMON1_CODE,
    Enum_IRQ_BUSMON2_CODE             = IRQ_BUSMON2_CODE,
    Enum_IRQ_PCMON_CODE              = IRQ_PCMON_CODE,
    Enum_IRQ_SIM_CODE                = IRQ_SIM_CODE,
    Enum_IRQ_SIM2_CODE               = IRQ_SIM2_CODE,
    Enum_IRQ_CA_DL_LMAC_RAR_CODE     = IRQ_CA_DL_LMAC_RAR_CODE,
    Enum_IRQ_CA_DL_LMAC_EAR_CODE     = IRQ_CA_DL_LMAC_EAR_CODE,
    Enum_IRQ_BSICTRL_IMM_RDINT_CODE  = IRQ_BSICTRL_IMM_RDINT_CODE,
    Enum_IRQ_CAIF_VALID_CODE         = IRQ_CAIF_VALID_CODE,
    Enum_IRQ_CAIF_ACK_CODE           = IRQ_CAIF_ACK_CODE,
    Enum_IRQ_A7WDT_CODE              = IRQ_A7WDT_CODE,
    Enum_IRQ_C1_IRQ_T1_CODE          = IRQ_C1_IRQ_T1_CODE,
    Enum_IRQ_C1_IRQ_T6_CODE          = IRQ_C1_IRQ_T6_CODE,
    Enum_IRQ_IDC2ARM_CODE            = IRQ_IDC2ARM_CODE,
    Enum_IRQ_AUXADC_CODE             = IRQ_AUXADC_CODE,
    Enum_IRQ_Code_End                = MAX_ISR_NUM
};

#endif /* end of __INTRCTRL_MT6595_H__ */

