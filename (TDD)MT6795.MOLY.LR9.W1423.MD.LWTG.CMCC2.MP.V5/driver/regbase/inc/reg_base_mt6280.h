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
 *   reg_base_mt6280.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Definition for chipset register base and global configuration registers
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
#ifndef __REG_base_MT6280_H__
#define __REG_base_MT6280_H__

/* MDSYS APB Registers */
#define CONFIG_base                  (0x80000000) /* MDMCU config: Version Code, Clock Gating, Bus control ... */
#define CIRQ_base                    (0x80010000) /* CIRQ */
#define CIRQ_EINT_base               (0x80020000) /* CIRQ EINT, no use in MT6280 */
#define TOPSM_base                   (0x80030000) /* TOPSM */
#define OSTIMER_base                 (0x80040000) /* OSTIMER */
#define RGU_base                     (0x80050000) /* MDMCU RGU */
#define GPT_base                     (0x80060000) /* GPT */
#define UART1_base                   (0x80070000) /* UART1 */
#define SEJ_base                     (0x80080000) /* SEJ */
#define DMA_base                     (0x800B0000) /* MD_P_SYS DMA */
#define SIM_base                     (0x800C0000) /* SIM */
#define SIM2_base                    (0x800D0000) /* SIM2 */
#define SFI_base                     (0x80100000) /* SF control */
#define ASM_base                     (0x80140000) /* ASM */
#define ADOE_base                    (0x80150000) /* ADOE */
#define TRACE_base                   (0x80160000) /* LMU Trace */
#define ATBBWL_base                  (0x80170000) /* LMU ATBBWL */
#define TIU_BUFFER_base              (0x80180000) /* TIU buffer */
#define SDCTL_SLV_base               (0x80800000) /* SD control slave */

/* APSYS APB Registers */
#define AP_CONFIG_base               (0xA0000000) /* APMCU config, DCM */
#define EFUSE_base                   (0xA0010000) /* EFUSE */
#define AP_BOOT_SLV_base             (0xA0020000) /* APMCU Boot Slave */
#define AP_RGU_base                  (0xA0030000) /* APMCU RGU */
#define AP_CIRQ_base                 (0xA0040000) /* APSYS CIRQ_base */
#define PWM_base                     (0xA0050000) /* PWM */
#define AP_GPT_base                  (0xA0060000) /* APSYS GPT */
#define GPIO_base                    (0xA0070000) /* GPIO control */
#define AP_DMA_base                  (0xA0080000) /* AP DMA */
#define AP_DEBUG_base                (0xA0090000) /* AP debug base */
#define CTI_base                     (0xA0092000) /* Cross-trigger interface */
#define COREBASE_base                (0xA0093000) /* CR4 APB slave base, for cmm gen */
#define AP_TRACE_base                (0xA00A0000) /* AP Trace */
#define DAPROM_base                  (0xA00A0000) /* DAP for trace */
#define DEM_base                     (0xA00AA000) /*MD ARM DEM Base Addr*/
#define AP_MDCCIF_base               (0xA00B0000) /* CCIF AP Control registers*/
#define MDCCIF_base                  (0xA00B0020) /* CCIF MD Control registers*/
#define MIX_ABB_base                 (0xA00C0000) /* Mixedsys, PLL */
#define AP_TOPSM_base                (0xA00D0000) /* APSYS topsm */
#define AP_OSTIMER_base              (0xA00E0000) /* APSYS OSTIMER */
#define MSDC_base                    (0xA00F0000) /* MSDC */
#define AP_UART1_base                (0xA0100000) /* AP uart 1 */
#define AP_UART2_base                (0xA0110000) /* AP uart 2 */
#define I2C_base                     (0xA0120000) /* I2C */
#define NFI_base                     (0xA0130000) /* NFI */
#define NFIECC_base                  (0xA0140000) /* NFIECC */
#define HIF_base                     (0xA0150000) /* HIF */
#define NLI_ARB_base                 (0xA0160000) /* NLI ARB */
#define SPI_base                     (0xA0170000) /* SPI */
#define EMI_base                     (0xA0180000) /* EMI */
#define LCD_base                     (0xA0800000) /* LCD */
#define USB_base                     (0xA0810000) /* USB */ 
#define USBSIF_base                  (0xA0820000) /* USBSIF */

/* LMU */
#define ALC_base                     (0x60000000) /* ALC */
#define LMU_ARM11_AXI_base           (0x62000000) /* LMU AXI Port for CR4 */
#define LMU_base                     (0x66000000) /* Log Message Unit */
#define LMU_ARM11_base               (LMU_base)   /* LMU_ARM11_base is for compatibiliity of legacy code */


/* MODEMSYS APB Registers */
/* MD2G */                        
#define IDMA_base                    (0x82000000) 
#define DPRAM_CPU_base               (0x82200000)
#define AHB2DSPIO_base               (0x82800000)
#define MD2GCONFG_base               (0x82C00000)
#define APC_base                     (0x82C30000)
#define CSD_ACC_base                 (0x82C70000)
#define SHARE_base                   (0x82CA0000) // SHARE_D1 for 2G
#define IRDMA_base                   (0x82CB0000)
#define IRDBG_base                   (IRDMA_base)
#define PATCH_base                   (0x82CC0000)
#define AFE_base                     (0x82CD0000)
#define BFE_base                     (0x82CE0000)
                                  
/* Modem Peripherals */           
#define MDCONFIG_base                (0x83000000)
#define SLP_CTRL_base                (0x83010000) // SLP_CTRL_base, modem topsm
#define TDMA_base                    (0x83020000)
#define SHAREG2_base                 (0x83030000) // SHREG2 for 2G
#define DIVIDER_base                 (0x83040000)
#define FCS_base                     (0x83050000)
#define GCU_base                     (0x83060000)
#define BSI_base                     (0x83070000)
#define BPI_base                     (0x83080000)
#define AFC_base                     (0x83090000)
#define WCDMA_TIMER_base             (0x830A0000)
#define DPA_BC_base                  (0x830B0000)
#define PFC_ENCODE_base              (0x830C0000)
#define PFC_DECODE_base              (0x830D0000)
                                  
/* HSPA1 */                       
#define HSPASYS_CONFIG1_base         (0x83200000)
#define HSEQ_base                    (0x83210000)
#define HSCE_base                    (0x83220000)
                                  
/* HSPA2 */                       
#define HSPASYS_CONFIG2_base         (0x83400000)
#define HSEQ_DC_base                 (0x83410000)
#define HSCE_DC_base                 (0x83420000)
#define RAKEDC_base                  (0x83430000)
                                  
/* HSPA3 */                       
#define F8F9_1_base                  (0x83600000)
#define F8F9_base                    (0x83610000)
#define F8F9_2_base                  (0x83610000) /* Request by Alfred Lee */
#define DPA_RLC_base                 (0x83620000)
#define DPA_MAC_base                 (0x83630000)
#define HSUPA_base                   (UPA_base)
#define UPA_base                     (0x83640000)
#define HRXBRP_base                  (0x83650000)
#define RXBRP_base                   (0x83660000)
#define HSPASYS_CONFIG3_base         (0x83670000)
#define TXBRP_base                   (0x83680000)
#define TXCRP_base                   (0x83690000)
#define UTXBRP_base                  (0x836A0000) /* HTXBRP -> UTXBRP requested by ChuYan */
#define TXUPC_base                   (0x836B0000)
#define BITCP_base                   (0x836C0000)
#define HSPA3_DBG_base               (0x836D0000)

/* HSPA4 */
#define RXSRP_base                   (0x83800000)
#define INDEC_base                   (0x83810000)
#define RXCRP0_base                  (0x83820000)
#define RXCRP1_base                  (0x83830000)
#define RXCRP2_base                  (0x83840000)
#define SRCHR_base                   (0x83850000)
#define RXDFE_base                   (0x83860000)
#define HSPASYS_CONFIG4_base         (0x83870000)
#define HSPA4_DBG_base               (0x83880000)
#define DBG_WRAPPER0_base            (0x83890000)
#define LOG3G_base                   (0x838A0000)
#define DBG_WRAPPER1_base            (0x838C0000)
#define SIMPLE_DMA_base              (0x838D0000)


/* Shared Device Type APB Register Remapping */

#define CONFIG_SD_base               (0x88000000) /* MDMCU config: Version Code, Clock Gating, Bus control ... */
#define CIRQ_SD_base                 (0x88010000) /* CIRQ */
#define CIRQ_EINT_SD_base            (0x88020000) /* CIRQ EINT, no use in MT6280 */
#define TOPSM_SD_base                (0x88030000) /* TOPSM */
#define OSTIMER_SD_base              (0x88040000) /* OSTIMER */
#define RGU_SD_base                  (0x88050000) /* MDMCU RGU */
#define GPT_SD_base                  (0x88060000) /* GPT */
#define UART1_SD_base                (0x88070000) /* UART1 */
#define SEJ_SD_base                  (0x88080000) /* SEJ */
#define DMA_SD_base                  (0x880B0000) /* MD_P_SYS DMA */
#define SIM_SD_base                  (0x880C0000) /* SIM */
#define SIM2_SD_base                 (0x880D0000) /* SIM2 */
#define SFI_SD_base                  (0x88100000) /* SF control */
#define ASM_SD_base                  (0x88140000) /* ASM */
#define ADOE_SD_base                 (0x88150000) /* ADOE */
#define TRACE_SD_base                (0x88160000) /* LMU Trace */
#define ATBBWL_SD_base               (0x88170000) /* LMU ATBBWL */
#define TIU_BUFFER_SD_base           (0x88180000) /* TIU buffer */
#define SDCTL_SLV_SD_base            (0x88800000) /* SD control slave */

/* APSYS APB Registers */
#define AP_CONFIG_SD_base            (0xA8000000) /* APMCU config, DCM */
#define EFUSE_SD_base                (0xA8010000) /* EFUSE */
#define AP_RGU_SD_base               (0xA8030000) /* APMCU RGU */
#define AP_CIRQ_SD_base              (0xA8040000) /* APSYS CIRQ_base */
#define PWM_SD_base                  (0xA8050000) /* PWM */
#define AP_GPT_SD_base               (0xA8060000) /* APSYS GPT */
#define GPIO_SD_base                 (0xA8070000) /* GPIO control */
#define AP_DMA_SD_base               (0xA8080000) /* AP DMA */
#define AP_DEBUG_SD_base             (0xA8090000) /* AP debug base */
#define CTI_SD_base                  (0xA8092000) /* Cross-trigger interface */
#define COREBASE_SD_base             (0xA8093000) /* CR4 APB slave base, for cmm gen */
#define AP_TRACE_SD_base             (0xA80A0000) /* AP Trace */
#define DAPROM_SD_base               (0xA80A0000) /* DAP for trace */
#define DEM_SD_base                  (0xA80AA000) /*MD ARM DEM Base Addr*/
#define AP_MDCCIF_SD_base            (0xA80B0000) /* CCIF AP Control registers*/
#define MDCCIF_SD_base               (0xA80B0020) /* CCIF MD Control registers*/
#define MIX_ABB_SD_base              (0xA80C0000) /* Mixedsys, PLL */
#define AP_TOPSM_SD_base             (0xA80D0000) /* APSYS topsm */
#define AP_OSTIMER_SD_base           (0xA80E0000) /* APSYS OSTIMER */
#define MSDC_SD_base                 (0xA80F0000) /* MSDC */
#define AP_UART1_SD_base             (0xA8100000) /* AP uart 1 */
#define AP_UART2_SD_base             (0xA8110000) /* AP uart 2 */
#define I2C_SD_base                  (0xA8120000) /* I2C */
#define NFI_SD_base                  (0xA8130000) /* NFI */
#define NFIECC_SD_base               (0xA8140000) /* NFIECC */
#define HIF_SD_base                  (0xA8150000) /* HIF */
#define NLI_ARB_SD_base              (0xA8160000) /* NLI ARB */
#define SPI_SD_base                  (0xA8170000) /* SPI */
#define EMI_SD_base                  (0xA8180000) /* EMI */
#define LCD_SD_base                  (0xA8800000) /* LCD */
#define USB_SD_base                  (0xA8810000) /* USB */ 
#define USBSIF_SD_base               (0xA8820000) /* USBSIF */

/* MODEMSYS APB Registers */
/* MD2G */                        
#define IDMA_SD_base                 (0x8A000000)
#define DPRAM_CPU_SD_base            (0x8A200000)
#define AHB2DSPIO_SD_base            (0x8A800000)
#define MD2GCONFG_SD_base            (0x8AC00000)
#define APC_SD_base                  (0x8AC30000)
#define CSD_ACC_SD_base              (0x8AC70000)
#define SHARE_SD_base                (0x8ACA0000) // SHARE_D1 for 2G
#define IRDMA_SD_base                (0x8ACB0000)
#define IRDBG_SD_base                (IRDMA_base)
#define PATCH_SD_base                (0x8ACC0000)
#define AFE_SD_base                  (0x8ACD0000)
#define BFE_SD_base                  (0x8ACE0000)
                                  
/* Modem Peripherals */           
#define MDCONFIG_SD_base             (0x8B000000)
#define SLP_CTRL_SD_base             (0x8B010000) // SLP_CTRL_base, modem topsm
#define TDMA_SD_base                 (0x8B020000)
#define SHAREG2_SD_base              (0x8B030000) // SHREG2 for 2G
#define DIVIDER_SD_base              (0x8B040000)
#define FCS_SD_base                  (0x8B050000)
#define GCU_SD_base                  (0x8B060000)
#define BSI_SD_base                  (0x8B070000)
#define BPI_SD_base                  (0x8B080000)
#define AFC_SD_base                  (0x8B090000)
#define WCDMA_TIMER_SD_base          (0x8B0A0000)
#define DPA_BC_SD_base               (0x8B0B0000)
#define PFC_ENCODE_SD_base           (0x8B0C0000)
#define PFC_DECODE_SD_base           (0x8B0D0000)
                                  
/* HSPA1 */                       
#define HSPASYS_CONFIG1_SD_base      (0x8B200000)
#define HSEQ_SD_base                 (0x8B210000)
#define HSCE_SD_base                 (0x8B220000)
                                  
/* HSPA2 */                       
#define HSPASYS_CONFIG2_SD_base      (0x8B400000)
#define HSEQ_DC_SD_base              (0x8B410000)
#define HSCE_DC_SD_base              (0x8B420000)
#define RAKEDC_SD_base               (0x8B430000)
                                  
/* HSPA3 */                       
#define F8F9_1_SD_base               (0x8B600000)
#define F8F9_SD_base                 (0x8B610000)
#define F8F9_2_SD_base               (0x8B610000) /* Request by Alfred Lee */
#define DPA_RLC_SD_base              (0x8B620000)
#define DPA_MAC_SD_base              (0x8B630000)
#define HSUPA_SD_base                (UPA_SD_base)
#define UPA_SD_base                  (0x8B640000)
#define HRXBRP_SD_base               (0x8B650000)
#define RXBRP_SD_base                (0x8B660000)
#define HSPASYS_CONFIG3_SD_base      (0x8B670000)
#define TXBRP_SD_base                (0x8B680000)
#define TXCRP_SD_base                (0x8B690000)
#define UTXBRP_SD_base               (0x8B6A0000)
#define TXUPC_SD_base                (0x8B6B0000)
#define BITCP_SD_base                (0x8B6C0000)
#define HSPA3_DBG_SD_base            (0x8B6D0000)

/* HSPA4 */
#define RXSRP_SD_base                (0x8B800000)
#define INDEC_SD_base                (0x8B810000)
#define RXCRP0_SD_base               (0x8B820000)
#define RXCRP1_SD_base               (0x8B830000)
#define RXCRP2_SD_base               (0x8B840000)
#define SRCHR_SD_base                (0x8B850000)
#define RXDFE_SD_base                (0x8B860000)
#define HSPASYS_CONFIG4_SD_base      (0x8B870000)
#define HSPA4_DBG_SD_base            (0x8B880000)
#define DBG_WRAPPER0_SD_base         (0x8B890000)
#define LOG3G_SD_base                (0x8B8A0000)
#define DBG_WRAPPER1_SD_base         (0x8B8C0000)
#define SIMPLE_DMA_SD_base           (0x8B8D0000)

/* LMU */
#define LMU_ARM11_AXI_SD_base        (LMU_ARM11_AXI_base)
#define LMU_ARM11_SD_base            (LMU_base)


#endif  /* __REG_base_MT6280_H__ */
