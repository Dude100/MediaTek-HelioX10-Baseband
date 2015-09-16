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
 *   intrCtrl_MT6280.h
 *
 * Project:
 * --------
 *   Maui_Software
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __INTRCTRL_MT6280_H__
#define __INTRCTRL_MT6280_H__

/*******************************************************************************
 * Define CIRQ Registers 
 *******************************************************************************/

#define IRQ_MASK0              ((volatile UINT32P)(CIRQ_base+0x0000)) /* IRQ Mask 0x00 to 0x1F */
#define IRQ_MASK1              ((volatile UINT32P)(CIRQ_base+0x0004)) /* IRQ Mask 0x20 to 0x3F */
#define IRQ_MASK2              ((volatile UINT32P)(CIRQ_base+0x0008)) /* IRQ Mask 0x40 to 0x4F */

#define IRQ_MASK_SET0          ((volatile UINT32P)(CIRQ_base+0x0020)) /* IRQ Mask SET 0x00 to 0x1F  */
#define IRQ_MASK_SET1          ((volatile UINT32P)(CIRQ_base+0x0024)) /* IRQ Mask SET 0x20 to 0x3F */
#define IRQ_MASK_SET2          ((volatile UINT32P)(CIRQ_base+0x0028)) /* IRQ Mask SET 0x40 to 0x4F */

#define IRQ_MASK_CLR0          ((volatile UINT32P)(CIRQ_base+0x0040)) /* IRQ Mask CLR 0x00 to 0x1F  */
#define IRQ_MASK_CLR1          ((volatile UINT32P)(CIRQ_base+0x0044)) /* IRQ Mask CLR 0x20 to 0x3F */
#define IRQ_MASK_CLR2          ((volatile UINT32P)(CIRQ_base+0x0048)) /* IRQ Mask CLR 0x40 to 0x4F */

#define IRQ_SENS0              ((volatile UINT32P)(CIRQ_base+0x0060)) /* IRQ sensitive 0x00 to 0x1F  */
#define IRQ_SENS1              ((volatile UINT32P)(CIRQ_base+0x0064)) /* IRQ sensitive 0x20 to 0x3F */
#define IRQ_SENS2              ((volatile UINT32P)(CIRQ_base+0x0068)) /* IRQ sensitive 0x40 to 0x4F */

#define IRQ_SENS_SET0          ((volatile UINT32P)(CIRQ_base+0x0080)) /* IRQ sensitive SET 0x00 to 0x1F  */
#define IRQ_SENS_SET1          ((volatile UINT32P)(CIRQ_base+0x0084)) /* IRQ sensitive SET 0x20 to 0x3F */
#define IRQ_SENS_SET2          ((volatile UINT32P)(CIRQ_base+0x0088)) /* IRQ sensitive SET 0x40 to 0x4F */

#define IRQ_SENS_CLR0          ((volatile UINT32P)(CIRQ_base+0x00A0)) /* IRQ sensitive CLR 0x00 to 0x1F  */
#define IRQ_SENS_CLR1          ((volatile UINT32P)(CIRQ_base+0x00A4)) /* IRQ sensitive CLR 0x20 to 0x3F */
#define IRQ_SENS_CLR2          ((volatile UINT32P)(CIRQ_base+0x00A8)) /* IRQ sensitive CLR 0x40 to 0x4F */

#define IRQ_SOFT0              ((volatile UINT32P)(CIRQ_base+0x00C0)) /* IRQ SW interrupt 0x00 to 0x1F  */
#define IRQ_SOFT1              ((volatile UINT32P)(CIRQ_base+0x00C4)) /* IRQ SW interrupt 0x20 to 0x3F */
#define IRQ_SOFT2              ((volatile UINT32P)(CIRQ_base+0x00C8)) /* IRQ SW interrupt 0x40 to 0x4F */

#define IRQ_SOFT_SET0          ((volatile UINT32P)(CIRQ_base+0x00E0)) /* IRQ SW interrupt SET 0x00 to 0x1F  */
#define IRQ_SOFT_SET1          ((volatile UINT32P)(CIRQ_base+0x00E4)) /* IRQ SW interrupt SET 0x20 to 0x3F */
#define IRQ_SOFT_SET2          ((volatile UINT32P)(CIRQ_base+0x00E8)) /* IRQ SW interrupt SET 0x40 to 0x4F */

#define IRQ_SOFT_CLR0          ((volatile UINT32P)(CIRQ_base+0x0100)) /* IRQ SW interrupt CLR 0x00 to 0x1F  */
#define IRQ_SOFT_CLR1          ((volatile UINT32P)(CIRQ_base+0x0104)) /* IRQ SW interrupt CLR 0x20 to 0x3F */
#define IRQ_SOFT_CLR2          ((volatile UINT32P)(CIRQ_base+0x0108)) /* IRQ SW interrupt CLR 0x40 to 0x4F */

#define IRQ_ASTA0              ((volatile UINT32P)(CIRQ_base+0x0120)) /* All IRQ status 0 */
#define IRQ_ASTA1              ((volatile UINT32P)(CIRQ_base+0x0124)) /* All IRQ status 1 */
#define IRQ_ASTA2              ((volatile UINT32P)(CIRQ_base+0x0128)) /* All IRQ status 2 */

#define FIQ_ASTA0              ((volatile UINT32P)(CIRQ_base+0x0140)) /* All FIQ status 0 */
#define FIQ_ASTA1              ((volatile UINT32P)(CIRQ_base+0x0144)) /* All FIQ status 1 */
#define FIQ_ASTA2              ((volatile UINT32P)(CIRQ_base+0x0148)) /* All FIQ status 2 */

#define IRQ_EOIOH0             ((volatile UINT32P)(CIRQ_base+0x0160)) /* IRQ end of interrupt 0x00 to 0x1F  */
#define IRQ_EOIOH1             ((volatile UINT32P)(CIRQ_base+0x0164)) /* IRQ end of interrupt 0x20 to 0x3F */
#define IRQ_EOIOH2             ((volatile UINT32P)(CIRQ_base+0x0168)) /* IRQ end of interrupt 0x40 to 0x4F */

#define IRQ_FSEL0              ((volatile UINT32P)(CIRQ_base+0x0180)) /* FIQ Source selection 0x0 to 0x1F*/
#define IRQ_FSEL1              ((volatile UINT32P)(CIRQ_base+0x0184)) /* FIQ Source selection 0x20 to 0x3F*/
#define IRQ_FSEL2              ((volatile UINT32P)(CIRQ_base+0x0188)) /* FIQ Source selection 0x40 to 0x4F*/

#define IRQ_STA2               ((volatile UINT32P)(CIRQ_base+0x01A0)) /* Binary Code Value of IRQ_STATUS */
#define FIQ_STA2               ((volatile UINT32P)(CIRQ_base+0x01A4)) /* Binary Code Value of FIQ_STATUS */
#define IRQ_EOI2               ((volatile UINT32P)(CIRQ_base+0x01A8)) /* Binary Code Value of IRQ_EOI */

#define IRQ_STV                ((volatile UINT32P)(CIRQ_base+0x01BC)) /* CIRQ Starvation Control */

#define IRQ_SEL0               ((volatile UINT32P)(CIRQ_base+0x0200)) /* Source selection 0 to 3 */
#define IRQ_SEL1               ((volatile UINT32P)(CIRQ_base+0x0204)) /* Source selection 4 to 7 */
#define IRQ_SEL2               ((volatile UINT32P)(CIRQ_base+0x0208)) /* Source selection 8 to 0xB */
#define IRQ_SEL3               ((volatile UINT32P)(CIRQ_base+0x020C)) /* Source selection 0xC to 0xF */
#define IRQ_SEL4               ((volatile UINT32P)(CIRQ_base+0x0210)) /* Source selection 0x10 to 0x13 */
#define IRQ_SEL5               ((volatile UINT32P)(CIRQ_base+0x0214)) /* Source selection 0x14 to 0x17 */
#define IRQ_SEL6               ((volatile UINT32P)(CIRQ_base+0x0218)) /* Source selection 0x18 to 0x1B */
#define IRQ_SEL7               ((volatile UINT32P)(CIRQ_base+0x021c)) /* Source selection 0x1C to 0x1F */
#define IRQ_SEL8               ((volatile UINT32P)(CIRQ_base+0x0220)) /* Source selection 0x20 to 0x23 */
#define IRQ_SEL9               ((volatile UINT32P)(CIRQ_base+0x0224)) /* Source selection 0x24 to 0x27 */
#define IRQ_SEL10              ((volatile UINT32P)(CIRQ_base+0x0228)) /* Source selection 0x28 to 0x2B */
#define IRQ_SEL11              ((volatile UINT32P)(CIRQ_base+0x022C)) /* Source selection 0x2C to 0x2F */
#define IRQ_SEL12              ((volatile UINT32P)(CIRQ_base+0x0230)) /* Source selection 0x30 to 0x33 */
#define IRQ_SEL13              ((volatile UINT32P)(CIRQ_base+0x0234)) /* Source selection 0x34 to 0x37 */
#define IRQ_SEL14              ((volatile UINT32P)(CIRQ_base+0x0238)) /* Source selection 0x38 to 0x3B */
#define IRQ_SEL15              ((volatile UINT32P)(CIRQ_base+0x023C)) /* Source selection 0x3C to 0x3F */
#define IRQ_SEL16              ((volatile UINT32P)(CIRQ_base+0x0240)) /* Source selection 0x40 to 0x43 */
#define IRQ_SEL17              ((volatile UINT32P)(CIRQ_base+0x0244)) /* Source selection 0x44 to 0x47 */
#define IRQ_SEL18              ((volatile UINT32P)(CIRQ_base+0x0248)) /* Source selection 0x48 to 0x4B */
#define IRQ_SEL19              ((volatile UINT32P)(CIRQ_base+0x024C)) /* Source selection 0x4C to 0x4F */

#define IRQ_SEL(x)             ((volatile UINT32P)(CIRQ_base+0x0200+0x0004*(x)))

#define EINT_STATUS            ((volatile UINT32P)(AP_CIRQ_base+0x0300))
#define EINT_INTACK            ((volatile UINT32P)(AP_CIRQ_base+0x0308))
#define EINT_EEVT              ((volatile UINT32P)(AP_CIRQ_base+0x0310))

#define EINT_MASK              ((volatile UINT32P)(AP_CIRQ_base+0x0318))
#define EINT_MASK_SET          ((volatile UINT32P)(AP_CIRQ_base+0x0320))
#define EINT_MASK_CLR          ((volatile UINT32P)(AP_CIRQ_base+0x0328))

#define EINT_SENS              ((volatile UINT32P)(AP_CIRQ_base+0x0330))
#define EINT_SENS_SET          ((volatile UINT32P)(AP_CIRQ_base+0x0338))
#define EINT_SENS_CLR          ((volatile UINT32P)(AP_CIRQ_base+0x0340))

#define EINT_SOFT              ((volatile UINT32P)(AP_CIRQ_base+0x0348))
#define EINT_SOFT_SET          ((volatile UINT32P)(AP_CIRQ_base+0x0350))
#define EINT_SOFT_CLR          ((volatile UINT32P)(AP_CIRQ_base+0x0358))

#define EINT_D0EN              ((volatile UINT32P)(AP_CIRQ_base+0x0360)) 
#define EINT_D1EN              ((volatile UINT32P)(AP_CIRQ_base+0x0368)) 

#define EINT0_CON              ((volatile UINT32P)(AP_CIRQ_base+0x0380))
#define EINT1_CON              ((volatile UINT32P)(AP_CIRQ_base+0x0384))
#define EINT2_CON              ((volatile UINT32P)(AP_CIRQ_base+0x0388))
#define EINT3_CON              ((volatile UINT32P)(AP_CIRQ_base+0x038C))
#define EINT4_CON              ((volatile UINT32P)(AP_CIRQ_base+0x0390))
#define EINT5_CON              ((volatile UINT32P)(AP_CIRQ_base+0x0394))         
#define EINT6_CON              ((volatile UINT32P)(AP_CIRQ_base+0x0398))         
#define EINT7_CON              ((volatile UINT32P)(AP_CIRQ_base+0x039C))         
#define EINT8_CON              ((volatile UINT32P)(AP_CIRQ_base+0x03A0))         
#define EINT9_CON              ((volatile UINT32P)(AP_CIRQ_base+0x03A4))         
#define EINT10_CON             ((volatile UINT32P)(AP_CIRQ_base+0x03A8))         
#define EINT11_CON             ((volatile UINT32P)(AP_CIRQ_base+0x03AC))         
#define EINT12_CON             ((volatile UINT32P)(AP_CIRQ_base+0x03B0))         
#define EINT13_CON             ((volatile UINT32P)(AP_CIRQ_base+0x03B4))         
#define EINT14_CON             ((volatile UINT32P)(AP_CIRQ_base+0x03B8))         
#define EINT15_CON             ((volatile UINT32P)(AP_CIRQ_base+0x03BC))  

#define EINT_CON(i)            ((volatile UINT32P)(EINT0_CON+0x4*i))

#if defined(MT6280_S00)

/*
 * CIRQ Interrupt Sources
 */
#define IRQ_SW_LISR1_CODE         (0)
#define IRQ_COMMTX_CODE           (1)    /* commtx_irq_b */    /* new */
#define IRQ_COMMRX_CODE           (2)    /* commrx_irq_b */    /* new */
#define IRQ_WDT_CODE              (3)
#define IRQ_SW_LISR2_CODE         (4) 
#define IRQ_SFI_CODE              (5)
#define IRQ_OSTIMER_ARM_CODE      (6) 
#define IRQ_GPT_CODE              (7) 
#define IRQ_TOPSM_CODE            (8) 
#define IRQ_SW_LISR3_CODE         (9) 
#define IRQ_PI_CODE               (10)
#define IRQ_AI_CODE               (11)
#define IRQ_TFCI_1_CODE           (12)
#define IRQ_TFCI_0_CODE           (13)
#define IRQ_TPC_CODE              (14)
#define IRQ_RXBRP_CCB_CODE        (15)
#define IRQ_RXBRP_CC1_CODE        (16)
#define IRQ_RXBRP_CC0_CODE        (17)
#define IRQ_F8F9_CODE             (18)
#define IRQ_HSDPA_BC_CODE         (19)
#define IRQ_L2DPA_CODE            (20)
#define IRQ_L2UPA_CODE            (21)
#define IRQ_TXUPC_DSP_CODE        (22)   /* txupc_dsp_irq_b */
#define IRQ_BITCP_CODE            (23)
#define IRQ_IRDEBUG_CODE          (24)
#define IRQ_DSP2CPU_CODE          (25)
#define IRQ_PFC_DEC_CODE          (26)
#define IRQ_PFC_ENC_CODE          (27)
#define IRQ_WTIMER_CODE           (28)
#define IRQ_RTR_SLT_CODE          (29)
#define IRQ_RTR_FRAME_CODE        (30)
#define IRQ_MD_SLEEP_CODE         (31)   /* slp_ctrl_irq_b */
#define IRQ_CTIRQ3_CODE           (32)
#define IRQ_CTIRQ2_CODE           (33)
#define IRQ_CTIRQ1_CODE           (34)
#define IRQ_SEARCHER_CODE         (35)
#define IRQ_TDMA_CODE             (36)
#define IRQ_SIM2_CODE             (37)
#define IRQ_SIM_CODE              (38)
#define IRQ_DMA_FIQ_CODE          (39)
#define IRQ_DMA_CODE              (40)
#define IRQ_SDIO_FW_CODE          (41)
#define IRQ_UART1_CODE            (42)
#define IRQ_CCIF_CODE             (43)
#define IRQ_EIT_CODE              (44)
#define IRQ_LMU_MD_CODE           (45)
#define IRQ_MDMCU_PMU_CODE        (46)
#define IRQ_MALMO_ADOE_CODE       (47)
#define IRQ_SW_LISR4_CODE         (48)
#define IRQ_SW_LISR5_CODE         (49)
#define IRQ_SW_LISR6_CODE         (50)
#define IRQ_SW_LISR7_CODE         (51)
#define IRQ_SW_LISR8_CODE         (52)
#define IRQ_CTI_CODE              (53)   /* ctirigout_3 */
#define IRQ_LOG3G_CODE            (54)   /* log3g_buf_irq_b */
#define IRQ_SW_LISR9_CODE         (55)
#define IRQ_SW_LISR10_CODE        (56)
#define IRQ_AP_WDT_CODE           (57)
#define IRQ_AP_GPT_CODE           (58)
#define IRQ_AP_OSTIMER_CODE       (59)
#define IRQ_AP_TOPSM_CODE         (60)
#define IRQ_SPI_CODE              (61)
#define IRQ_USB_CODE              (62)
#define IRQ_AP_CCIF_CODE          (63)
#define IRQ_CORESIGHT_DCC_MD_CODE (64)   /* ap_trace_irq_b */
#define IRQ_MSDC_CODE             (65)
#define IRQ_I2C_CODE              (66)
#define IRQ_LCD_CODE              (67)
#define IRQ_HIF_CODE              (68)
#define IRQ_NFIECC_CODE           (69)
#define IRQ_NFI_CODE              (70)
#define IRQ_AP_UART2_CODE         (71)
#define IRQ_AP_UART1_CODE         (72)
#define IRQ_AP_DMA_CODE           (73)
#define IRQ_AP_EIT_CODE           (74)
#define IRQ_AP_DMA_FIQ_CODE       (75)
#define IRQ_MSDC_CD_CODE          (76)
#define IRQ_CINT_0_CODE           (77)
#define IRQ_CINT_1_CODE           (78)
#define IRQ_SW_LISR11_CODE        (79)
#define NUM_IRQ_SOURCES           (80)

/*
 * IRQ Selection Register mapping
 */   
#define IRQ0_CODE           IRQ_WTIMER_CODE
#define IRQ1_CODE           IRQ_RTR_SLT_CODE
#define IRQ2_CODE           IRQ_AI_CODE
#define IRQ3_CODE           IRQ_PI_CODE
#define IRQ4_CODE           IRQ_SEARCHER_CODE 
#define IRQ5_CODE           IRQ_TFCI_0_CODE
#define IRQ6_CODE           IRQ_TFCI_1_CODE
#define IRQ7_CODE           IRQ_RXBRP_CC0_CODE
#define IRQ8_CODE           IRQ_RXBRP_CC1_CODE
#define IRQ9_CODE           IRQ_RXBRP_CCB_CODE
#define IRQA_CODE           IRQ_TDMA_CODE
#define IRQB_CODE           IRQ_CTIRQ1_CODE
#define IRQC_CODE           IRQ_CTIRQ2_CODE
#define IRQD_CODE           IRQ_SW_LISR2_CODE
#define IRQE_CODE           IRQ_SW_LISR1_CODE
#define IRQF_CODE           IRQ_SW_LISR3_CODE
#define IRQ10_CODE          IRQ_TPC_CODE      
#define IRQ11_CODE          IRQ_RTR_FRAME_CODE
#define IRQ12_CODE          IRQ_TOPSM_CODE
#define IRQ13_CODE          IRQ_OSTIMER_ARM_CODE
#define IRQ14_CODE          IRQ_CINT_0_CODE
#define IRQ15_CODE          IRQ_CINT_1_CODE
#define IRQ16_CODE          IRQ_COMMTX_CODE
#define IRQ17_CODE          IRQ_COMMRX_CODE
#define IRQ18_CODE          IRQ_WDT_CODE   
#define IRQ19_CODE          IRQ_SFI_CODE
#define IRQ1A_CODE          IRQ_GPT_CODE
#define IRQ1B_CODE          IRQ_F8F9_CODE
#define IRQ1C_CODE          IRQ_HSDPA_BC_CODE
#define IRQ1D_CODE          IRQ_L2DPA_CODE      
#define IRQ1E_CODE          IRQ_L2UPA_CODE      
#define IRQ1F_CODE          IRQ_TXUPC_DSP_CODE  
#define IRQ20_CODE          IRQ_BITCP_CODE      
#define IRQ21_CODE          IRQ_IRDEBUG_CODE     
#define IRQ22_CODE          IRQ_DSP2CPU_CODE
#define IRQ23_CODE          IRQ_PFC_DEC_CODE    
#define IRQ24_CODE          IRQ_PFC_ENC_CODE    
#define IRQ25_CODE          IRQ_MD_SLEEP_CODE
#define IRQ26_CODE          IRQ_CTIRQ3_CODE
#define IRQ27_CODE          IRQ_SIM2_CODE       
#define IRQ28_CODE          IRQ_SIM_CODE        
#define IRQ29_CODE          IRQ_DMA_FIQ_CODE    
#define IRQ2A_CODE          IRQ_DMA_CODE        
#define IRQ2B_CODE          IRQ_SDIO_FW_CODE    
#define IRQ2C_CODE          IRQ_UART1_CODE      
#define IRQ2D_CODE          IRQ_CCIF_CODE       
#define IRQ2E_CODE          IRQ_EIT_CODE        
#define IRQ2F_CODE          IRQ_LMU_MD_CODE     
#define IRQ30_CODE          IRQ_MDMCU_PMU_CODE  
#define IRQ31_CODE          IRQ_MALMO_ADOE_CODE 
#define IRQ32_CODE          IRQ_SW_LISR4_CODE   
#define IRQ33_CODE          IRQ_SW_LISR5_CODE   
#define IRQ34_CODE          IRQ_SW_LISR6_CODE   
#define IRQ35_CODE          IRQ_SW_LISR7_CODE   
#define IRQ36_CODE          IRQ_SW_LISR8_CODE   
#define IRQ37_CODE          IRQ_CTI_CODE
#define IRQ38_CODE          IRQ_LOG3G_CODE      
#define IRQ39_CODE          IRQ_SW_LISR9_CODE   
#define IRQ3A_CODE          IRQ_SW_LISR10_CODE  
#define IRQ3B_CODE          IRQ_AP_WDT_CODE     
#define IRQ3C_CODE          IRQ_AP_GPT_CODE     
#define IRQ3D_CODE          IRQ_AP_OSTIMER_CODE 
#define IRQ3E_CODE          IRQ_AP_TOPSM_CODE   
#define IRQ3F_CODE          IRQ_SPI_CODE        
#define IRQ40_CODE          IRQ_USB_CODE        
#define IRQ41_CODE          IRQ_AP_CCIF_CODE    
#define IRQ42_CODE          IRQ_CORESIGHT_DCC_MD_CODE
#define IRQ43_CODE          IRQ_MSDC_CODE      
#define IRQ44_CODE          IRQ_I2C_CODE       
#define IRQ45_CODE          IRQ_LCD_CODE       
#define IRQ46_CODE          IRQ_HIF_CODE       
#define IRQ47_CODE          IRQ_NFIECC_CODE    
#define IRQ48_CODE          IRQ_NFI_CODE       
#define IRQ49_CODE          IRQ_AP_UART2_CODE  
#define IRQ4A_CODE          IRQ_AP_UART1_CODE  
#define IRQ4B_CODE          IRQ_AP_DMA_CODE    
#define IRQ4C_CODE          IRQ_AP_EIT_CODE    
#define IRQ4D_CODE          IRQ_AP_DMA_FIQ_CODE
#define IRQ4E_CODE          IRQ_MSDC_CD_CODE   
#define IRQ4F_CODE          IRQ_SW_LISR11_CODE 
#define NUM_IRQ_LINES       (0x50)

#else

/*
 * CIRQ Interrupt Sources
 */
#define IRQ_RXADC_OVLD_ANT1_CODE  (0)    /* new */
#define IRQ_RXADC_OVLD_ANT0_CODE  (1)    /* new */
#define IRQ_RXBRP_HS_CODE         (2)    /* new */
#define IRQ_WDT_CODE              (3)
#define IRQ_EMI_DOMAIN_ABORT_CODE (4)    /* new */
#define IRQ_SFI_CODE              (5)
#define IRQ_OSTIMER_ARM_CODE      (6) 
#define IRQ_GPT_CODE              (7) 
#define IRQ_TOPSM_CODE            (8) 
#define IRQ_SW_LISR1_CODE         (9) 
#define IRQ_PI_CODE               (10)
#define IRQ_AI_CODE               (11)
#define IRQ_TFCI_1_CODE           (12)
#define IRQ_TFCI_0_CODE           (13)
#define IRQ_TPC_CODE              (14)
#define IRQ_RXBRP_CCB_CODE        (15)
#define IRQ_RXBRP_CC1_CODE        (16)
#define IRQ_RXBRP_CC0_CODE        (17)
#define IRQ_F8F9_CODE             (18)
#define IRQ_HSDPA_BC_CODE         (19)
#define IRQ_L2DPA_CODE            (20)
#define IRQ_L2UPA_CODE            (21)
#define IRQ_TXUPC_DSP_CODE        (22)   /* txupc_dsp_irq_b */
#define IRQ_BITCP_CODE            (23)
#define IRQ_IRDEBUG_CODE          (24)
#define IRQ_DSP2CPU_CODE          (25)
#define IRQ_PFC_DEC_CODE          (26)
#define IRQ_PFC_ENC_CODE          (27)
#define IRQ_WTIMER_CODE           (28)
#define IRQ_RTR_SLT_CODE          (29)
#define IRQ_RTR_FRAME_CODE        (30)
#define IRQ_MD_SLEEP_CODE         (31)   /* slp_ctrl_irq_b */
#define IRQ_CTIRQ3_CODE           (32)
#define IRQ_CTIRQ2_CODE           (33)
#define IRQ_CTIRQ1_CODE           (34)
#define IRQ_SEARCHER_CODE         (35)
#define IRQ_TDMA_CODE             (36)
#define IRQ_SIM2_CODE             (37)
#define IRQ_SIM_CODE              (38)
#define IRQ_DMA_FIQ_CODE          (39)
#define IRQ_DMA_CODE              (40)
#define IRQ_SDIO_FW_CODE          (41)
#define IRQ_UART1_CODE            (42)
#define IRQ_CCIF_CODE             (43)
#define IRQ_EIT_CODE              (44)
#define IRQ_LMU_MD_CODE           (45)
#define IRQ_MDMCU_PMU_CODE        (46)
#define IRQ_MALMO_ADOE_CODE       (47)
#define IRQ_SW_LISR2_CODE         (48)
#define IRQ_SW_LISR3_CODE         (49)
#define IRQ_SW_LISR4_CODE         (50)
#define IRQ_SW_LISR5_CODE         (51)
#define IRQ_SW_LISR6_CODE         (52)
#define IRQ_CTI_CODE              (53)   /* ctirigout_3 */
#define IRQ_LOG3G_CODE            (54)   /* log3g_buf_irq_b */
#define IRQ_SW_LISR7_CODE         (55)
#define IRQ_SW_LISR8_CODE         (56)
#define IRQ_AP_WDT_CODE           (57)
#define IRQ_AP_GPT_CODE           (58)
#define IRQ_AP_OSTIMER_CODE       (59)
#define IRQ_AP_TOPSM_CODE         (60)
#define IRQ_SPI_CODE              (61)
#define IRQ_USB_CODE              (62)
#define IRQ_AP_CCIF_CODE          (63)
#define IRQ_CORESIGHT_DCC_MD_CODE (64)   /* ap_trace_irq_b */
#define IRQ_MSDC_CODE             (65)
#define IRQ_I2C_CODE              (66)
#define IRQ_LCD_CODE              (67)
#define IRQ_HIF_CODE              (68)
#define IRQ_NFIECC_CODE           (69)
#define IRQ_NFI_CODE              (70)
#define IRQ_AP_UART2_CODE         (71)
#define IRQ_AP_UART1_CODE         (72)
#define IRQ_AP_DMA_CODE           (73)
#define IRQ_AP_EIT_CODE           (74)
#define IRQ_AP_DMA_FIQ_CODE       (75)
#define IRQ_MSDC_CD_CODE          (76)
#define IRQ_CINT_0_CODE           (77)
#define IRQ_CINT_1_CODE           (78)
#define IRQ_SW_LISR9_CODE         (79)
#define NUM_IRQ_SOURCES           (80)

/*
 * IRQ Selection Register mapping
 */   
#define IRQ0_CODE           IRQ_WTIMER_CODE
#define IRQ1_CODE           IRQ_RTR_SLT_CODE
#define IRQ2_CODE           IRQ_AI_CODE
#define IRQ3_CODE           IRQ_PI_CODE
#define IRQ4_CODE           IRQ_SEARCHER_CODE
#define IRQ5_CODE           IRQ_TFCI_0_CODE
#define IRQ6_CODE           IRQ_TFCI_1_CODE
#define IRQ7_CODE           IRQ_RXBRP_CC0_CODE
#define IRQ8_CODE           IRQ_RXBRP_CC1_CODE
#define IRQ9_CODE           IRQ_RXBRP_CCB_CODE
#define IRQA_CODE           IRQ_TDMA_CODE
#define IRQB_CODE           IRQ_CTIRQ1_CODE
#define IRQC_CODE           IRQ_CTIRQ2_CODE
#define IRQD_CODE           IRQ_RXBRP_HS_CODE
#define IRQE_CODE           IRQ_RXADC_OVLD_ANT0_CODE
#define IRQF_CODE           IRQ_RXADC_OVLD_ANT1_CODE
#define IRQ10_CODE          IRQ_SW_LISR2_CODE
#define IRQ11_CODE          IRQ_SW_LISR1_CODE
#define IRQ12_CODE          IRQ_SW_LISR3_CODE
#define IRQ13_CODE          IRQ_EMI_DOMAIN_ABORT_CODE
#define IRQ14_CODE          IRQ_TPC_CODE
#define IRQ15_CODE          IRQ_RTR_FRAME_CODE
#define IRQ16_CODE          IRQ_TOPSM_CODE
#define IRQ17_CODE          IRQ_OSTIMER_ARM_CODE
#define IRQ18_CODE          IRQ_CINT_0_CODE
#define IRQ19_CODE          IRQ_CINT_1_CODE
#define IRQ1A_CODE          IRQ_WDT_CODE
#define IRQ1B_CODE          IRQ_SFI_CODE
#define IRQ1C_CODE          IRQ_GPT_CODE
#define IRQ1D_CODE          IRQ_F8F9_CODE
#define IRQ1E_CODE          IRQ_HSDPA_BC_CODE
#define IRQ1F_CODE          IRQ_L2DPA_CODE
#define IRQ20_CODE          IRQ_L2UPA_CODE
#define IRQ21_CODE          IRQ_TXUPC_DSP_CODE
#define IRQ22_CODE          IRQ_BITCP_CODE
#define IRQ23_CODE          IRQ_IRDEBUG_CODE
#define IRQ24_CODE          IRQ_DSP2CPU_CODE
#define IRQ25_CODE          IRQ_PFC_DEC_CODE
#define IRQ26_CODE          IRQ_PFC_ENC_CODE
#define IRQ27_CODE          IRQ_MD_SLEEP_CODE
#define IRQ28_CODE          IRQ_CTIRQ3_CODE
#define IRQ29_CODE          IRQ_SIM2_CODE
#define IRQ2A_CODE          IRQ_SIM_CODE
#define IRQ2B_CODE          IRQ_DMA_FIQ_CODE
#define IRQ2C_CODE          IRQ_DMA_CODE
#define IRQ2D_CODE          IRQ_SDIO_FW_CODE
#define IRQ2E_CODE          IRQ_UART1_CODE
#define IRQ2F_CODE          IRQ_CCIF_CODE
#define IRQ30_CODE          IRQ_EIT_CODE
#define IRQ31_CODE          IRQ_LMU_MD_CODE
#define IRQ32_CODE          IRQ_MDMCU_PMU_CODE
#define IRQ33_CODE          IRQ_MALMO_ADOE_CODE
#define IRQ34_CODE          IRQ_SW_LISR4_CODE
#define IRQ35_CODE          IRQ_SW_LISR5_CODE
#define IRQ36_CODE          IRQ_SW_LISR6_CODE
#define IRQ37_CODE          IRQ_SW_LISR7_CODE
#define IRQ38_CODE          IRQ_SW_LISR8_CODE
#define IRQ39_CODE          IRQ_CTI_CODE
#define IRQ3A_CODE          IRQ_LOG3G_CODE
#define IRQ3B_CODE          IRQ_SW_LISR9_CODE
#define IRQ3C_CODE          IRQ_AP_WDT_CODE
#define IRQ3D_CODE          IRQ_AP_GPT_CODE
#define IRQ3E_CODE          IRQ_AP_OSTIMER_CODE
#define IRQ3F_CODE          IRQ_AP_TOPSM_CODE
#define IRQ40_CODE          IRQ_SPI_CODE
#define IRQ41_CODE          IRQ_USB_CODE
#define IRQ42_CODE          IRQ_AP_CCIF_CODE
#define IRQ43_CODE          IRQ_CORESIGHT_DCC_MD_CODE
#define IRQ44_CODE          IRQ_MSDC_CODE
#define IRQ45_CODE          IRQ_I2C_CODE
#define IRQ46_CODE          IRQ_LCD_CODE
#define IRQ47_CODE          IRQ_HIF_CODE
#define IRQ48_CODE          IRQ_NFIECC_CODE
#define IRQ49_CODE          IRQ_NFI_CODE
#define IRQ4A_CODE          IRQ_AP_UART2_CODE
#define IRQ4B_CODE          IRQ_AP_UART1_CODE
#define IRQ4C_CODE          IRQ_AP_DMA_CODE
#define IRQ4D_CODE          IRQ_AP_EIT_CODE
#define IRQ4E_CODE          IRQ_AP_DMA_FIQ_CODE
#define IRQ4F_CODE          IRQ_MSDC_CD_CODE
#define NUM_IRQ_LINES       (0x50)

#endif
                            
/*                          
 * IRQ code value in Selection Register
 */                         
#define IRQ0_SEL0             (IRQ0_CODE << 0)
#define IRQ1_SEL0             (IRQ1_CODE << 8)
#define IRQ2_SEL0             (IRQ2_CODE << 16)
#define IRQ3_SEL0             (IRQ3_CODE << 24)
                            
#define IRQ4_SEL1             (IRQ4_CODE << 0) 
#define IRQ5_SEL1             (IRQ5_CODE << 8) 
#define IRQ6_SEL1             (IRQ6_CODE << 16)
#define IRQ7_SEL1             (IRQ7_CODE << 24)
                            
#define IRQ8_SEL2             (IRQ8_CODE << 0) 
#define IRQ9_SEL2             (IRQ9_CODE << 8) 
#define IRQA_SEL2             (IRQA_CODE << 16)
#define IRQB_SEL2             (IRQB_CODE << 24)
                            
#define IRQC_SEL3             (IRQC_CODE << 0)
#define IRQD_SEL3             (IRQD_CODE << 8)
#define IRQE_SEL3             (IRQE_CODE << 16)
#define IRQF_SEL3             (IRQF_CODE << 24)
                            
#define IRQ10_SEL4            (IRQ10_CODE << 0) 
#define IRQ11_SEL4            (IRQ11_CODE << 8)  
#define IRQ12_SEL4            (IRQ12_CODE << 16)
#define IRQ13_SEL4            (IRQ13_CODE << 24)
                              
#define IRQ14_SEL5            (IRQ14_CODE << 0) 
#define IRQ15_SEL5            (IRQ15_CODE << 8) 
#define IRQ16_SEL5            (IRQ16_CODE << 16)
#define IRQ17_SEL5            (IRQ17_CODE << 24)  
                            
#define IRQ18_SEL6            (IRQ18_CODE << 0) 
#define IRQ19_SEL6            (IRQ19_CODE << 8) 
#define IRQ1A_SEL6            (IRQ1A_CODE << 16)
#define IRQ1B_SEL6            (IRQ1B_CODE << 24)
                            
#define IRQ1C_SEL7            (IRQ1C_CODE << 0) 
#define IRQ1D_SEL7            (IRQ1D_CODE << 8)  
#define IRQ1E_SEL7            (IRQ1E_CODE << 16)
#define IRQ1F_SEL7            (IRQ1F_CODE << 24)
                            
#define IRQ20_SEL8            (IRQ20_CODE << 0) 
#define IRQ21_SEL8            (IRQ21_CODE << 8) 
#define IRQ22_SEL8            (IRQ22_CODE << 16)
#define IRQ23_SEL8            (IRQ23_CODE << 24)

#define IRQ24_SEL9            (IRQ24_CODE << 0) 
#define IRQ25_SEL9            (IRQ25_CODE << 8) 
#define IRQ26_SEL9            (IRQ26_CODE << 16)
#define IRQ27_SEL9            (IRQ27_CODE << 24)

#define IRQ28_SEL10           (IRQ28_CODE << 0) 
#define IRQ29_SEL10           (IRQ29_CODE << 8) 
#define IRQ2A_SEL10           (IRQ2A_CODE << 16)
#define IRQ2B_SEL10           (IRQ2B_CODE << 24)

#define IRQ2C_SEL11           (IRQ2C_CODE << 0) 
#define IRQ2D_SEL11           (IRQ2D_CODE << 8) 
#define IRQ2E_SEL11           (IRQ2E_CODE << 16)
#define IRQ2F_SEL11           (IRQ2F_CODE << 24)

#define IRQ30_SEL12           (IRQ30_CODE << 0) 
#define IRQ31_SEL12           (IRQ31_CODE << 8) 
#define IRQ32_SEL12           (IRQ32_CODE << 16)
#define IRQ33_SEL12           (IRQ33_CODE << 24)

#define IRQ34_SEL13           (IRQ34_CODE << 0) 
#define IRQ35_SEL13           (IRQ35_CODE << 8) 
#define IRQ36_SEL13           (IRQ36_CODE << 16)
#define IRQ37_SEL13           (IRQ37_CODE << 24)

#define IRQ38_SEL14           (IRQ38_CODE << 0) 
#define IRQ39_SEL14           (IRQ39_CODE << 8) 
#define IRQ3A_SEL14           (IRQ3A_CODE << 16)
#define IRQ3B_SEL14           (IRQ3B_CODE << 24)

#define IRQ3C_SEL15           (IRQ3C_CODE << 0)
#define IRQ3D_SEL15           (IRQ3D_CODE << 8)
#define IRQ3E_SEL15           (IRQ3E_CODE << 16)
#define IRQ3F_SEL15           (IRQ3F_CODE << 24)

#define IRQ40_SEL16           (IRQ40_CODE << 0) 
#define IRQ41_SEL16           (IRQ41_CODE << 8) 
#define IRQ42_SEL16           (IRQ42_CODE << 16)
#define IRQ43_SEL16           (IRQ43_CODE << 24)

#define IRQ44_SEL17           (IRQ44_CODE << 0) 
#define IRQ45_SEL17           (IRQ45_CODE << 8) 
#define IRQ46_SEL17           (IRQ46_CODE << 16)
#define IRQ47_SEL17           (IRQ47_CODE << 24)

#define IRQ48_SEL18           (IRQ48_CODE << 0) 
#define IRQ49_SEL18           (IRQ49_CODE << 8) 
#define IRQ4A_SEL18           (IRQ4A_CODE << 16)
#define IRQ4B_SEL18           (IRQ4B_CODE << 24)

#define IRQ4C_SEL19           (IRQ4C_CODE << 0)
#define IRQ4D_SEL19           (IRQ4D_CODE << 8)
#define IRQ4E_SEL19           (IRQ4E_CODE << 16)
#define IRQ4F_SEL19           (IRQ4F_CODE << 24)


/*
 * Define IRQ line mapping table
 */
#define IRQ_LINE_MAPPING_TABLE \
	IRQ0_CODE,  IRQ1_CODE,  IRQ2_CODE,  IRQ3_CODE, \
	IRQ4_CODE,  IRQ5_CODE,  IRQ6_CODE,  IRQ7_CODE, \
	IRQ8_CODE,  IRQ9_CODE,  IRQA_CODE,  IRQB_CODE, \
	IRQC_CODE,  IRQD_CODE,  IRQE_CODE,  IRQF_CODE, \
	IRQ10_CODE, IRQ11_CODE, IRQ12_CODE, IRQ13_CODE, \
	IRQ14_CODE, IRQ15_CODE, IRQ16_CODE, IRQ17_CODE, \
	IRQ18_CODE, IRQ19_CODE, IRQ1A_CODE, IRQ1B_CODE, \
	IRQ1C_CODE, IRQ1D_CODE, IRQ1E_CODE, IRQ1F_CODE, \
	IRQ20_CODE, IRQ21_CODE, IRQ22_CODE, IRQ23_CODE, \
	IRQ24_CODE, IRQ25_CODE, IRQ26_CODE, IRQ27_CODE, \
	IRQ28_CODE, IRQ29_CODE, IRQ2A_CODE, IRQ2B_CODE, \
	IRQ2C_CODE, IRQ2D_CODE, IRQ2E_CODE, IRQ2F_CODE, \
	IRQ30_CODE, IRQ31_CODE, IRQ32_CODE, IRQ33_CODE, \
	IRQ34_CODE, IRQ35_CODE, IRQ36_CODE, IRQ37_CODE, \
	IRQ38_CODE, IRQ39_CODE, IRQ3A_CODE, IRQ3B_CODE, \
	IRQ3C_CODE, IRQ3D_CODE, IRQ3E_CODE, IRQ3F_CODE, \
	IRQ40_CODE, IRQ41_CODE, IRQ42_CODE, IRQ43_CODE, \
	IRQ44_CODE, IRQ45_CODE, IRQ46_CODE, IRQ47_CODE, \
	IRQ48_CODE, IRQ49_CODE, IRQ4A_CODE, IRQ4B_CODE, \
	IRQ4C_CODE, IRQ4D_CODE, IRQ4E_CODE, IRQ4F_CODE

/*
 * Define IRQ selection register assignment
 */
#define IRQSel()     do { \
   *IRQ_SEL0  = IRQ0_SEL0   | IRQ1_SEL0   | IRQ2_SEL0   | IRQ3_SEL0; \
   *IRQ_SEL1  = IRQ4_SEL1   | IRQ5_SEL1   | IRQ6_SEL1   | IRQ7_SEL1; \
   *IRQ_SEL2  = IRQ8_SEL2   | IRQ9_SEL2   | IRQA_SEL2   | IRQB_SEL2; \
   *IRQ_SEL3  = IRQC_SEL3   | IRQD_SEL3   | IRQE_SEL3   | IRQF_SEL3; \
   *IRQ_SEL4  = IRQ10_SEL4  | IRQ11_SEL4  | IRQ12_SEL4  | IRQ13_SEL4; \
   *IRQ_SEL5  = IRQ14_SEL5  | IRQ15_SEL5  | IRQ16_SEL5  | IRQ17_SEL5; \
   *IRQ_SEL6  = IRQ18_SEL6  | IRQ19_SEL6  | IRQ1A_SEL6  | IRQ1B_SEL6; \
   *IRQ_SEL7  = IRQ1C_SEL7  | IRQ1D_SEL7  | IRQ1E_SEL7  | IRQ1F_SEL7; \
   *IRQ_SEL8  = IRQ20_SEL8  | IRQ21_SEL8  | IRQ22_SEL8  | IRQ23_SEL8; \
   *IRQ_SEL9  = IRQ24_SEL9  | IRQ25_SEL9  | IRQ26_SEL9  | IRQ27_SEL9; \
   *IRQ_SEL10 = IRQ28_SEL10 | IRQ29_SEL10 | IRQ2A_SEL10 | IRQ2B_SEL10; \
   *IRQ_SEL11 = IRQ2C_SEL11 | IRQ2D_SEL11 | IRQ2E_SEL11 | IRQ2F_SEL11; \
   *IRQ_SEL12 = IRQ30_SEL12 | IRQ31_SEL12 | IRQ32_SEL12 | IRQ33_SEL12; \
   *IRQ_SEL13 = IRQ34_SEL13 | IRQ35_SEL13 | IRQ36_SEL13 | IRQ37_SEL13; \
   *IRQ_SEL14 = IRQ38_SEL14 | IRQ39_SEL14 | IRQ3A_SEL14 | IRQ3B_SEL14; \
   *IRQ_SEL15 = IRQ3C_SEL15 | IRQ3D_SEL15 | IRQ3E_SEL15 | IRQ3F_SEL15; \
   *IRQ_SEL16 = IRQ40_SEL16 | IRQ41_SEL16 | IRQ42_SEL16 | IRQ43_SEL16; \
   *IRQ_SEL17 = IRQ44_SEL17 | IRQ45_SEL17 | IRQ46_SEL17 | IRQ47_SEL17; \
   *IRQ_SEL18 = IRQ48_SEL18 | IRQ49_SEL18 | IRQ4A_SEL18 | IRQ4B_SEL18; \
   *IRQ_SEL19 = IRQ4C_SEL19 | IRQ4D_SEL19 | IRQ4E_SEL19 | IRQ4F_SEL19; \
   } while(0)

/*************************************************************************
 * EINT Configuration
 *************************************************************************/
#define  EINT_MAX_CHANNEL     16
#define  EINT_TOTAL_CHANNEL   16
#define  EINT_HARDWARE_DEBOUNCE      0x0000ffff

/*******************************************************************************
 * Special for display on SWDBG - MCU profiling
 *******************************************************************************/

#define __CIRQ_MASK_REG_NR_3_NEW__
#define __ENABLE_SW_TRIGGER_INTERRUPT__
#define __EINT_MD_DOMAIN_1__


typedef enum
{
   LISR_CTIRQ1    = IRQ_CTIRQ1_CODE,
   LISR_CTIRQ2    = IRQ_CTIRQ2_CODE,
   LISR_SIM       = IRQ_SIM_CODE,
   LISR_DMA       = IRQ_DMA_CODE,
   LISR_TDMA      = IRQ_TDMA_CODE,
   LISR_UART1     = IRQ_UART1_CODE,
   LISR_GPT       = IRQ_GPT_CODE,
   LISR_EIT       = IRQ_EIT_CODE,
   LISR_USB       = IRQ_USB_CODE,
   LISR_MSDC      = IRQ_MSDC_CODE,
   LISR_WDT       = IRQ_WDT_CODE,
   LISR_NFI          = IRQ_NFI_CODE,
   LISR_SPI        = IRQ_SPI_CODE,
   LISR_SEARCH = IRQ_SEARCHER_CODE,
   LISR_RXBRP_CC0 = IRQ_RXBRP_CC0_CODE,
   LISR_RXBRP_CC1 = IRQ_RXBRP_CC1_CODE,
   LISR_RXBRP_CCB = IRQ_RXBRP_CCB_CODE,
   LISR_LOG3G_IRQ1 = IRQ_LOG3G_CODE,
   LISR_BITCP = IRQ_BITCP_CODE,
   LISR_PI = IRQ_PI_CODE,
} LISR_IRQ_NO;

enum Irq_Code_Def_Enum
{
    Enum_IRQ_WTMR_CODE   =0x0,
    Enum_IRQ_RTRSLT_CODE =0x1,
    Enum_IRQ_AI_CODE     =0x2,
    Enum_IRQ_PI_CODE     =0x3,
    Enum_IRQ_SRCHR_CODE  =0x4,
    Enum_IRQ_TFCI0_CODE  =0x5,
    Enum_IRQ_TFCI1_CODE  =0x6,
    Enum_IRQ_RXBRP0_CODE =0x7,
    Enum_IRQ_RXBRP1_CODE =0x8,
    Enum_IRQ_RXBRPB_CODE =0x9,
    Enum_IRQ_TDMA_CODE   =0xA,
    Enum_IRQ_CTIRQ1_CODE =0xB,
    Enum_IRQ_CTIRQ2_CODE =0xC,
#if defined(MT6280_S00)
    Enum_IRQ_SISR2_CODE  =0xD,
    Enum_IRQ_SISR1_CODE  =0xE,
    Enum_IRQ_SISR3_CODE  =0xF,
#else
    Enum_IRQ_RXBRPHS_CODE =0xD,
    Enum_IRQ_RXADC0_CODE  =0xE,
    Enum_IRQ_RXADC1_CODE  =0xF,
    Enum_IRQ_SISR2_CODE   =0x10,
    Enum_IRQ_SISR1_CODE   =0x11,
    Enum_IRQ_SISR3_CODE   =0x12,
#endif
    Enum_IRQ_Code_End
};


#endif /* __INTRCTRL_MT6280_H__ */
