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
 *   reg_base_mt6752.h
 *
 * Project:
 * --------
 *   MOLY_Software
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
 *
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


#ifndef __REG_BASE_MT6752_H__
#define __REG_BASE_MT6752_H__

#if defined(__MD1__)    /* MD1 case */

/* Copy from reg_base_mt6595.h */

/*================== Begin of designer's project.h =========================*/
// APB Module alc
#define ALC_BASE (0x60000000)

/* MD Peripheral System */

// APB Module md_config
#define MD_CONFIG_BASE (0x80000000)
// APB Module mdcirq
#define MD_CIRQ_BASE (0x80010000)
// APB Module gpiomux_mdapb
#define MD_EINT_BASE (0x80020000)
// APB Module topsm
#define MD_TOPSM_BASE (0x80030000)
// APB Module ostimer
#define MD_OST_BASE (0x80040000)
// APB Module md_rgu
#define MD_RGU_BASE (0x80050000)
// APB Module mdgptm
#define MD_GPT_BASE (0x80060000)
// APB Module md_suart
#define MD_UART0_BASE (0x80070000)
// APB Module debug_md
#define MD_DEBUG_BASE (0x80080000)
// APB Module md_suart
#define MD_UART1_BASE (0x800A0000)
// APB Module mdgdma
#define MD_P_DMA_BASE (0x800B0000)
// APB Module usim
#define SIMIF1_BASE (0x800C0000)
// APB Module usim
#define SIMIF2_BASE (0x800D0000)
// APB Module cldma_md_in_sim
#define MDCLDMAIN_BASE (0x800E0000)
// APB Module cldma_md_out_sim
#define MDCLDMAOUT_BASE (0x800E1000)
// APB Module cldma_md_misc_sim
#define MDCLDMAMISC_BASE (0x800E2000)
// APB Module cldma_ap_in_sim
#define APCLDMAIN_BASE (0x800F0000)
// APB Module cldma_ap_out_sim
#define APCLDMAOUT_BASE (0x800F1000)
// APB Module cldma_ap_misc_sim
#define APCLDMAMISC_BASE (0x800F2000)
// APB Module md_mbist_config
#define MD_MBIST_CONFIG_BASE (0x80110000)
// APB Module pll_mixed
#define MD_PLL_MIXEDSYS_BASE (0x80120000)
// APB Module abm
#define MD_ABM_BASE (0x80140000)
// APB Module adoe
#define MD_ADOE_BASE (0x80150000)
// APB Module md_aximon
#define MD_INFRA_BUSMON_BASE (0x801A0000)
// APB Module md_aximon
#define MDMCU_BUSMON_BASE (0x801B0000)
// APB Module ostimer
#define A7_OST_BASE (0x801C0000)
// APB Module mdccif
#define MD_CAIF_BASE (0x801D0000)
// APB Module etm_pc_monitor
#define MD_PCM_BASE (0x801F0000)
// APB Module pf_bsictrl_apb1
#define PF_BSI_APB1_BASE (0x80200000)
// APB Module pf_bsictrlapb2crf
#define PF_BSI_APB2_BASE (0x80201000)
// APB Module mml1_bsispi
#define RFIC1_BSISPI_BASE (0x80202000)
// APB Module mml1_bsispi
#define RFIC2_BSISPI_BASE (0x80203000)
// APB Module mml1_bsispi
#define MIPI0_BSISPI_BASE (0x80205000)
// APB Module mml1_bsispi
#define MIPI1_BSISPI_BASE (0x80206000)
// APB Module idc_suart
#define IDC_SUART_BASE (0x80207000)
// APB Module mml1_peri_misc
#define MDM_PSYS_MISC_BASE (0x8020D000)
// APB Module mml1_peri_mbist
#define MDM_PSYS_MBISTCON_BASE (0x8020E000)
// APB Module mixed
#define MD1_ABB_MIXEDSYS_BASE (0x8020C000)
// APB Module mixed
#define MD2_ABB_MIXEDSYS_BASE (0x8020C000)
// APB Module a7cirq
#define A7_CIRQ_BASE (0x80410000)
// APB Module a7wdt
#define A7_WDT_BASE (0x80420000)
// APB Module a7ccif
#define A7_CAIF_BASE (0x80430000)
// APB Module idma
#define IDMA_BASE (0x82000000)
// APB Module ahb2dspio
#define AHB2DSPIO_BASE (0x82800000)
// APB Module md2gsys_confg
#define MD2G_CONFG_BASE (0x82C00000)
// APB Module apc
#define APC_BASE (0x82C30000)
// APB Module csd_acc
#define CSD_ACC_BASE (0x82C70000)
// APB Module share
#define SHARE_D1_BASE (0x82CA0000)
// APB Module irdma
#define IRDMA_BASE (0x82CB0000)
// APB Module patch
#define PATCH_BASE (0x82CC0000)
// APB Module mdafe
#define MDAFE_BASE (0x82CD0000)
// APB Module bfe
#define BFE_BASE (0x82CE0000)
// APB Module modem_confg
#define MODEM_LITE_CONFG_BASE (0x83000000)
// APB Module 2G topsm
#define MODEM_LITE_TOPSM_BASE (0x83010000)
// APB Module tdma
#define TDMA_BASE (0x83020000)
// APB Module share
#define SHREG2_BASE (0x83030000)
// APB Module divider
#define DIVIDER_BASE (0x83040000)
// APB Module fcs
#define FCS_BASE (0x83050000)
// APB Module gcu
#define GCU_BASE (0x83060000)
// APB Module dual_bsi
#define BSI_2G_BASE (0x83070000)
// APB Module dual_bpi
#define BPI_2G_BASE (0x83080000)
// APB Module afc
#define AFC_2G_BASE (0x83090000)
// APB Module tddsys
#define TDD_BASE (0x84000000)
// APB Module ltel2_ul_sbdma
#define L2ULSBDMA_BASE (0x85000000)
// APB Module ltel2_ul_hbdma
#define L2ULHBDMA_BASE (0x85010000)
// APB Module ltel2_dl_sbdma
#define L2DLSBDMA_BASE (0x85020000)
// APB Module ltel2_dl_hbdma
#define L2DLHBDMA_BASE (0x85030000)
// APB Module ltel2_pseu_phy
#define L2PSEUPHY_BASE (0x85050000)
// APB Module ltel2_hwlog
#define L2HWLOG_BASE (0x85058000)
// APB Module ltel2_so_indma
#define L2SOINDMA_BASE (0x85060000)
// APB Module ltel2_so_outdma
#define L2SOOUTDMA_BASE (0x85070000)
// APB Module ltel2_ul_lmac
#define L2ULLMAC_BASE (0x85080000)
// APB Module ltel2_dl_lmac
#define L2DLLMAC_BASE (0x85090000)
// APB Module ltel2_ca_lmac_sim
#define L2CALMAC_BASE (0x85098000)
// APB Module ltel2_ul_fifomng
#define L2ULFIFOMNG_BASE (0x850A0000)
// APB Module ltel2_dl_fifomng
#define L2DLFIFOMNG_BASE (0x850A4000)
// APB Module ltel2_so_fifomng
#define L2SOFIFOMNG_BASE (0x850A8000)
// APB Module ltel2_sec
#define L2SEC_BASE (0x850B0000)
// APB Module ltel2_ul_secctl
#define L2ULSECCTL_BASE (0x850B4000)
// APB Module ltel2_dl_secctl
#define L2DLSECCTL_BASE (0x850B8000)
// APB Module ltel2_so_secctl
#define L2SOSECCTL_BASE (0x850BC000)
// APB Module ltel2_misc
#define L2MISC_BASE (0x850C0000)
// APB Module dbgmon
#define REG_L2DBGMON_BASE (0x850D0000)
// APB Module ltel2_bufmng
#define L2ULBUF_BASE (0x850E0000)
// APB Module ltel2_dl_bufmng_sim
#define L2DLBUF_BASE (0x850F0000)
// APB Module BASE_CORE_ICM_ADDR
#define BASE_CORE_ICM_ADDR (0x86200000)
// APB Module BASE_CORE_C2CRF_ADDR
#define BASE_CORE_C2CRF_ADDR (0x86300000)
// APB Module BASE_CORE_CDIF_ADDR
#define BASE_CORE_CDIF_ADDR (0x86400000)
// APB Module CORE_APB
#define BASE_ADDR_CORE_APB (0x86500000)
// APB Module modem_confg
#define MODEM_CONFG_BASE (0x87000000)
// APB Module 3G topsm
#define MODEM_TOPSM_BASE (0x87010000)
// APB Module dual_bsi
#define BSI_3G_BASE (0x87070000)
// APB Module dual_bpi
#define BPI_3G_BASE (0x87080000)
// APB Module afc
#define AFC_3G_BASE (0x87090000)
// APB Module wcdma_timer
#define WCDMA_TIMER_BASE (0x870A0000)
// APB Module dpa_bc
#define DPA_BC_BASE (0x870B0000)
// APB Module pfc_encode
#define PFC_ENCODE_BASE (0x870C0000)
// APB Module pfc_decode
#define PFC_DECODE_BASE (0x870D0000)
// APB Module hspasys_1_confg
#define HSPASYS_1_CONFG_BASE (0x87200000)
// APB Module hseq
#define HSEQ_BASE (0x87210000)
// APB Module hsce
#define HSCE_BASE (0x87220000)
// APB Module hspasys_1_mbist
#define HSPASYS_1_MBIST_BASE (0x87230000)
// APB Module hspasys_2_confg
#define HSPASYS_2_CONFG_BASE (0x87400000)
// APB Module hseq_dc
#define HSEQ_DC_BASE (0x87410000)
// APB Module hsce_dc
#define HSCE_DC_BASE (0x87420000)
// APB Module rake_dc
#define RAKE_DC_BASE (0x87430000)
// APB Module hspasys_2_mbist
#define HSPASYS_2_MBIST_BASE (0x87440000)
// APB Module uea_uia0
#define UEA_UIA_U0_BASE (0x87600000)
// APB Module uea_uia1
#define UEA_UIA_U1_BASE (0x87610000)
// APB Module dpa_rlc
#define DPA_RLC_BASE (0x87620000)
// APB Module dpa_mac
#define DPA_MAC_BASE (0x87630000)
// APB Module upa
#define UPA_BASE (0x87640000)
// APB Module h_rxbrp
#define H_RXBRP_BASE (0x87650000)
// APB Module rxbrp
#define RXBRP_BASE (0x87660000)
// APB Module hspasys_3_confg
#define HSPASYS_3_CONFG_BASE (0x87670000)
// APB Module txbrp
#define TXBRP_BASE (0x87680000)
// APB Module txcrp
#define TXCRP_BASE (0x87690000)
// APB Module h_txbrp
#define H_TXBRP_BASE (0x876A0000)
// APB Module txupc
#define TXUPC_BASE (0x876B0000)
// APB Module bc
#define BC_BASE (0x876C0000)
// APB Module dbg_tx
#define DBG_TX_BASE (0x876D0000)
// APB Module hspasys_3_mbist
#define HSPASYS_3_MBIST_BASE (0x876E0000)
// APB Module rxsrp
#define RXSRP_BASE (0x87800000)
// APB Module indec
#define INDEC_BASE (0x87810000)
// APB Module rake_0
#define RAKE_0_BASE (0x87820000)
// APB Module rake_1
#define RAKE_1_BASE (0x87830000)
// APB Module rake_2
#define RAKE_2_BASE (0x87840000)
// APB Module searcher
#define SEARCHER_BASE (0x87850000)
// APB Module rxdfe
#define RXDFE_BASE (0x87860000)
// APB Module hspasys_4_confg
#define HSPASYS_4_CONFG_BASE (0x87870000)
// APB Module dbg
#define DBG_BASE (0x87880000)
// APB Module dbg_wrapper0
#define DWRAP0_BASE (0x87890000)
// APB Module log3g
#define LOG3G_BASE (0x878A0000)
// APB Module hspasys_4_mbist
#define HSPASYS_4_MBIST_BASE (0x878B0000)
// APB Module dbg_wrapper1
#define DWRAP1_BASE (0x878C0000)

/*==================== End of designer's project.h =========================*/


/****************************************************************************/
/* Type Define                                                              */
/****************************************************************************/

#define DEVICE_TYPE_1 0x08000000    // (| DEVICE_TYPE_1) for stronly-order type 0x8000_0000~0x87FF_FFFF
                                    //                   map to device type     0x8800_0000~0x8FFF_FFFF
#define DEVICE_TYPE_2 0x10000000    // (| DEVICE_TYPE_2) for stronly-order type 0xA000_0000~0xAFFF_FFFF 
                                    //                   map to device type     0xB000_0000~0xBFFF_FFFF

/****************************************************************************/
/* For 4G Convention, Base Address Sybol Re-Definition                      */
/****************************************************************************/

/* Strongly Order Type */

/* MDSYS Registers */
#define BASE_MADDR_MDCONFIG         (MD_CONFIG_BASE)
#define BASE_MADDR_MDCIRQ           (MD_CIRQ_BASE)
#define BASE_MADDR_MDGPIOMUX        (MD_EINT_BASE)
#define BASE_MADDR_MDTOPSM          (MD_TOPSM_BASE)
#define BASE_MADDR_MDOSTIMER        (MD_OST_BASE)
#define BASE_MADDR_MDGPTM           (MD_GPT_BASE)
#define BASE_MADDR_MDUART           (MD_UART0_BASE)
#define BASE_MADDR_UART0            (MD_UART1_BASE)
#define BASE_MADDR_MDGDMA           (MD_P_DMA_BASE)
#define BASE_MADDR_MDCLDMAIN        (MDCLDMAIN_BASE)
#define BASE_MADDR_MDCLDMAOUT       (MDCLDMAOUT_BASE)
#define BASE_MADDR_MDCLDMAMISC      (MDCLDMAMISC_BASE)
#define BASE_MADDR_APCLDMAIN        (APCLDMAIN_BASE)
#define BASE_MADDR_APCLDMAOUT       (APCLDMAOUT_BASE)
#define BASE_MADDR_APCLDMAMISC      (APCLDMAMISC_BASE)
#define BASE_MADDR_MDABM            (MD_ABM_BASE)
#define BASE_MADDR_MDADOE           (MD_ADOE_BASE)
#define BASE_MADDR_MDCAIF           (MD_CAIF_BASE)
#define BASE_MADDR_PCMON            (MD_PCM_BASE)
#define BASE_MADDR_PLL_MIXEDSYS     (MD_PLL_MIXEDSYS_BASE)

/* L2 Registers */
#define BASE_MADDR_L2ULSBDMA        (L2ULSBDMA_BASE  )
#define BASE_MADDR_L2ULHBDMA        (L2ULHBDMA_BASE  )
#define BASE_MADDR_L2DLSBDMA        (L2DLSBDMA_BASE  )
#define BASE_MADDR_L2DLHBDMA        (L2DLHBDMA_BASE  )
#define BASE_MADDR_L2PSEUPHY        (L2PSEUPHY_BASE  )
#define BASE_MADDR_L2HWLOG          (L2HWLOG_BASE    )
#define BASE_MADDR_L2SOINDMA        (L2SOINDMA_BASE  )
#define BASE_MADDR_L2SOOUTDMA       (L2SOOUTDMA_BASE )
#define BASE_MADDR_L2ULLMAC         (L2ULLMAC_BASE   )
#define BASE_MADDR_L2DLLMAC         (L2DLLMAC_BASE   )
#define BASE_MADDR_L2CALMAC         (L2CALMAC_BASE   )
#define BASE_MADDR_L2ULFIFOMNG      (L2ULFIFOMNG_BASE)
#define BASE_MADDR_L2DLFIFOMNG      (L2DLFIFOMNG_BASE)
#define BASE_MADDR_L2SOFIFOMNG      (L2SOFIFOMNG_BASE)
#define BASE_MADDR_L2SEC            (L2SEC_BASE      )
#define BASE_MADDR_L2ULSECCTL       (L2ULSECCTL_BASE )
#define BASE_MADDR_L2DLSECCTL       (L2DLSECCTL_BASE )
#define BASE_MADDR_L2SOSECCTL       (L2SOSECCTL_BASE )
#define BASE_MADDR_L2MISC           (L2MISC_BASE     )
#define BASE_MADDR_L2ULBUFMNG       (L2ULBUF_BASE    )
#define BASE_MADDR_L2DLBUFMNG       (L2DLBUF_BASE    )

/* new setting for MT6595 */
#define BASE_MADDR_MD2G_CONFGE      (MD2G_CONFG_BASE)
#define BASE_MADDR_MODEM_LITE_CONFG (MODEM_LITE_CONFG_BASE)
#define BASE_MADDR_MODEM_CONFG      (MODEM_CONFG_BASE)


/* No Device Type Setting */

#define BASE_ADDR_ALC               (ALC_BASE)
#define BASE_MADDR_ALC              (ALC_BASE)
#define BASE_ADDR_MDTCM             (0x70000000)

/* ARM7 Registers */
#define BASE_ADDR_ARM7WDT           (A7_WDT_BASE)
#define BASE_MADDR_ARM7OST          (A7_OST_BASE)
#define BASE_ADDR_ARM7OST           (BASE_MADDR_ARM7OST | DEVICE_TYPE_1)
#define BASE_ADDR_ARM7CIRQ          (A7_CIRQ_BASE)
#define BASE_ADDR_ARM7CCIF          (A7_CAIF_BASE)
#define BASE_ADDR_ARM7TCM           (0xE1000000)
#define BASE_ADDR_ARM7CACHE         (0xEFFF0000)
#define BASE_ADDR_ARM7CACHE_MPU     (0xEFFF1000)
#define BASE_ADDR_ARM7CACHE_MCU     (0xEFFF1020)


/* Device Type */

/* MDSYS Registers */
#define BASE_ADDR_MDCONFIG          (BASE_MADDR_MDCONFIG     | DEVICE_TYPE_1)
#define BASE_ADDR_MDCIRQ            (BASE_MADDR_MDCIRQ       | DEVICE_TYPE_1)
#define BASE_ADDR_MDGPIOMUX         (BASE_MADDR_MDGPIOMUX    | DEVICE_TYPE_1)
#define BASE_ADDR_MDTOPSM           (BASE_MADDR_MDTOPSM      | DEVICE_TYPE_1)
#define BASE_ADDR_MDOSTIMER         (BASE_MADDR_MDOSTIMER    | DEVICE_TYPE_1)
#define BASE_ADDR_MDGPTM            (BASE_MADDR_MDGPTM       | DEVICE_TYPE_1)
#define BASE_ADDR_MDUART            (BASE_MADDR_MDUART       | DEVICE_TYPE_1)
#define BASE_ADDR_UART0             (BASE_MADDR_UART0        | DEVICE_TYPE_1)
#define BASE_ADDR_MDGDMA            (BASE_MADDR_MDGDMA       | DEVICE_TYPE_1)
#define BASE_ADDR_MDCLDMAIN         (BASE_MADDR_MDCLDMAIN    | DEVICE_TYPE_1)
#define BASE_ADDR_MDCLDMAOUT        (BASE_MADDR_MDCLDMAOUT   | DEVICE_TYPE_1)
#define BASE_ADDR_MDCLDMAMISC       (BASE_MADDR_MDCLDMAMISC  | DEVICE_TYPE_1)
#define BASE_ADDR_APCLDMAIN         (BASE_MADDR_APCLDMAIN    | DEVICE_TYPE_1)
#define BASE_ADDR_APCLDMAOUT        (BASE_MADDR_APCLDMAOUT   | DEVICE_TYPE_1)
#define BASE_ADDR_APCLDMAMISC       (BASE_MADDR_APCLDMAMISC  | DEVICE_TYPE_1)
#define BASE_ADDR_MDABM             (BASE_MADDR_MDABM        | DEVICE_TYPE_1)
#define BASE_ADDR_MDADOE            (BASE_MADDR_MDADOE       | DEVICE_TYPE_1)
#define BASE_ADDR_MDCAIF            (BASE_MADDR_MDCAIF       | DEVICE_TYPE_1)
#define BASE_ADDR_MDPCMON           (BASE_MADDR_PCMON        | DEVICE_TYPE_1)
#define BASE_ADDR_PLL_MIXEDSYS      (BASE_MADDR_PLL_MIXEDSYS | DEVICE_TYPE_1)

/* L2 Registers */
#define BASE_ADDR_L2ULSBDMA         (L2ULSBDMA_BASE  | DEVICE_TYPE_1)
#define BASE_ADDR_L2ULHBDMA         (L2ULHBDMA_BASE  | DEVICE_TYPE_1)
#define BASE_ADDR_L2DLSBDMA         (L2DLSBDMA_BASE  | DEVICE_TYPE_1)
#define BASE_ADDR_L2DLHBDMA         (L2DLHBDMA_BASE  | DEVICE_TYPE_1)
#define BASE_ADDR_L2PSEUPHY         (L2PSEUPHY_BASE  | DEVICE_TYPE_1)
#define BASE_ADDR_L2HWLOG           (L2HWLOG_BASE    | DEVICE_TYPE_1)
#define BASE_ADDR_L2SOINDMA         (L2SOINDMA_BASE  | DEVICE_TYPE_1)
#define BASE_ADDR_L2SOOUTDMA        (L2SOOUTDMA_BASE | DEVICE_TYPE_1)
#define BASE_ADDR_L2ULLMAC          (L2ULLMAC_BASE   | DEVICE_TYPE_1)
#define BASE_ADDR_L2DLLMAC          (L2DLLMAC_BASE   | DEVICE_TYPE_1)
#define BASE_ADDR_L2CALMAC          (L2CALMAC_BASE   | DEVICE_TYPE_1)
#define BASE_ADDR_L2ULFIFOMNG       (L2ULFIFOMNG_BASE| DEVICE_TYPE_1)
#define BASE_ADDR_L2DLFIFOMNG       (L2DLFIFOMNG_BASE| DEVICE_TYPE_1)
#define BASE_ADDR_L2SOFIFOMNG       (L2SOFIFOMNG_BASE| DEVICE_TYPE_1)
#define BASE_ADDR_L2SEC             (L2SEC_BASE      | DEVICE_TYPE_1)
#define BASE_ADDR_L2ULSECCTL        (L2ULSECCTL_BASE | DEVICE_TYPE_1)
#define BASE_ADDR_L2DLSECCTL        (L2DLSECCTL_BASE | DEVICE_TYPE_1)
#define BASE_ADDR_L2SOSECCTL        (L2SOSECCTL_BASE | DEVICE_TYPE_1)
#define BASE_ADDR_L2MISC            (L2MISC_BASE     | DEVICE_TYPE_1)
#define BASE_ADDR_L2ULBUFMNG        (L2ULBUF_BASE    | DEVICE_TYPE_1)
#define BASE_ADDR_L2DLBUFMNG        (L2DLBUF_BASE    | DEVICE_TYPE_1)


/* new setting for MT6595 */

/* Device Type */
/* MD */
#define BASE_ADDR_MD2G_CONFGE       (BASE_MADDR_MD2G_CONFGE | DEVICE_TYPE_1)
#define BASE_ADDR_MODEM_LITE_CONFG  (BASE_MADDR_MODEM_LITE_CONFG | DEVICE_TYPE_1)
#define BASE_ADDR_MODEM_CONFG       (BASE_MADDR_MODEM_CONFG | DEVICE_TYPE_1)
#define CORE_ICM_SD_base            (BASE_CORE_ICM_ADDR     | DEVICE_TYPE_1)    // DSP: APB Module BASE_CORE_ICM_ADDR
#define CORE_C2CRF_SD_base          (BASE_CORE_C2CRF_ADDR   | DEVICE_TYPE_1)    // DSP: APB Module BASE_CORE_C2CRF_ADDR
#define CORE_CDIF_SD_base           (BASE_CORE_CDIF_ADDR    | DEVICE_TYPE_1)    // DSP: APB Module BASE_CORE_CDIF_ADDR
#define CORE_APB_SD_base            (BASE_ADDR_CORE_APB     | DEVICE_TYPE_1)    // DSP: APB Module CORE_APB
/* AP */
#define PMIC_WRAP_SD_BASE           (PWRAP_BASE      | DEVICE_TYPE_2)           // new in 6595 AP Peripheral
#define EFUSE_SD_base               (EFUSEC_BASE     | DEVICE_TYPE_2)           // new in 6595 AP Peripheral
#define AP_AUDSYS_SD_base           (AUDIOSYS_BASE   | DEVICE_TYPE_2)           // AP Peripheral

/* Strongly Order Type */
/* MD */
#define CORE_ICM_base               (BASE_CORE_ICM_ADDR)                        // DSP: APB Module BASE_CORE_ICM_ADDR
#define CORE_C2CRF_base             (BASE_CORE_C2CRF_ADDR)                      // DSP: APB Module BASE_CORE_C2CRF_ADDR
#define CORE_CDIF_base              (BASE_CORE_CDIF_ADDR)                       // DSP: APB Module BASE_CORE_CDIF_ADDR
#define CORE_APB_base               (BASE_ADDR_CORE_APB)                        // DSP: APB Module CORE_APB
/* AP */
#define PMIC_WRAP_BASE              (PWRAP_BASE)                                // new in 6595 AP Peripheral
#define EFUSE_base                  (EFUSEC_BASE)                               // new in 6595 AP Peripheral


/* base register redefine by driver owner */

#define UART1_base                  (BASE_ADDR_MDUART)                          // The same as 6290 on the (value) side
#define UART2_base                  (BASE_ADDR_UART0)                           // The same as 6290 on the (value) side
#define SIM0_base                   (SIMIF1_BASE)                               // 6290: (BASE_MADDR_USIM0)
#define SIM1_base                   (SIMIF2_BASE)                               // 6290: (BASE_MADDR_USIM1)
#define CONFIG_base                 (BASE_ADDR_MDCONFIG)                        // 6290: (0x80000000)
#define SIM0_SD_base                (SIMIF1_BASE     | DEVICE_TYPE_1)           // 6290: (BASE_ADDR_USIM0)
#define SIM1_SD_base                (SIMIF2_BASE     | DEVICE_TYPE_1)           // 6290: (BASE_ADDR_USIM1)
//#define EFUSE_base                   BASE_ADDR_EFUSE                          // Not in 6595 from 6290
//#define CHE_base                     BASE_ADDR_IPSEC                          // Not in 6595 from 6290



/****************************************************************************/
/* For 2/3G Convention, Base Address Sybol Re-Definition                    */
/****************************************************************************/

/* Device Type */

#define IDMA_SD_base                (IDMA_BASE              | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_IDMA)
#define DPRAM_CPU_SD_base           (0x82200000             | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_DPRAM_CPU)
#define AHB2DSPIO_SD_base           (AHB2DSPIO_BASE         | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_AHB2DSPIO)
#define MD2GCONFG_SD_base           (MD2G_CONFG_BASE        | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_MD2G_CONFG)
#define APC_SD_base                 (APC_BASE               | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_APC)
#define CSD_ACC_SD_base             (CSD_ACC_BASE           | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_CSD_ACC)
#define SHARE_SD_base               (SHARE_D1_BASE          | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_SHARE_D1) SHARE_D1 for 2G
#define IRDMA_SD_base               (IRDMA_BASE             | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_IRDMA)
#define IRDBG_SD_base               (IRDMA_BASE             | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_IRDMA)
#define PATCH_SD_base               (PATCH_BASE             | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_PATCH)
#define AFE_SD_base                 (MDAFE_BASE             | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_MDAFE)
#define BFE_SD_base                 (BFE_BASE               | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_BFE)
#define TOPSM_SD_base               (BASE_ADDR_MDTOPSM)                         // The same as 6290 on the (value) side

/* Modem Peripherals */
#define MDCONFIG_SD_base            (MODEM_CONFG_BASE       | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_MODEM_CONFG)
#define MODEM2G_CONFG_SD_base       (MODEM_LITE_CONFG_BASE  | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_MODEM2G_CONFG)
#define SLP_CTRL_SD_base            (MODEM_TOPSM_BASE       | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_MODEM_TOPSM) // modem 3G topsm
#define SLP_2G_CTRL_SD_base         (MODEM_LITE_TOPSM_BASE  | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_MODEM2G_TOPSM) // modem 2G topsm
#define TDMA_SD_base                (TDMA_BASE              | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_TDMA)
#define SHAREG2_SD_base             (SHREG2_BASE            | DEVICE_TYPE_1)    // 6290: (0xB3030000) // SHREG2 for 2G
#define DIVIDER_SD_base             (0x87040000             | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_DIVIDER)
#define FCS_SD_base                 (0x87050000             | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_FCS)
#define GCU_SD_base                 (0x87060000             | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_GCU)
#define BSI_SD_base                 (BSI_3G_BASE            | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_BSI)
#define BSISPI_SD_base              (PF_BSI_APB1_BASE       | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_BSI_MAC_PMIC)
#define BPI_SD_base                 (BPI_3G_BASE            | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_BPI)
#define AFC_SD_base                 (AFC_3G_BASE            | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_AFC)
#define BASE_ADDR_AFC               (AFC_3G_BASE            | DEVICE_TYPE_1)
#define DIVIDER2G_SD_base           (DIVIDER_BASE           | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_DIVIDER2G)
#define FCS2G_SD_base               (FCS_BASE               | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_FCS2G)
#define GCU2G_SD_base               (GCU_BASE               | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_GCU2G)
#define BSI2G_SD_base               (BSI_2G_BASE            | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_BSI2G)
#define BPI2G_SD_base               (BPI_2G_BASE            | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_BPI2G)
#define AFC2G_SD_base               (AFC_2G_BASE            | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_AFC2G)
#define WCDMA_TIMER_SD_base         (WCDMA_TIMER_BASE       | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_WCDMA_TIMER)
#define DPA_BC_SD_base              (DPA_BC_BASE            | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_DPA_BC)
//#define PFC_ENCODE_SD_base        (PFC_ENCODE_BASE        | DEVICE_TYPE_1)    // Not in 6290 and 6595
//#define PFC_DECODE_SD_base        (PFC_DECODE_BASE        | DEVICE_TYPE_1)    // Not in 6290 and 6595

/* HSPA1 */
#define HSPASYS_CONFIG1_SD_base     (HSPASYS_1_CONFG_BASE   | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_HSPASYS_1_CONFG)
#define HSEQ_SD_base                (HSEQ_BASE              | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_HSEQ)
#define HSCE_SD_base                (HSCE_BASE              | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_HSCE)

/* HSPA2 */
#define HSPASYS_CONFIG2_SD_base     (HSPASYS_2_CONFG_BASE   | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_HSPASYS_2_CONFG)
#define HSEQ_DC_SD_base             (HSEQ_DC_BASE           | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_HSEQ_DC)
#define HSCE_DC_SD_base             (HSCE_DC_BASE           | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_HSCE_DC)
#define RAKEDC_SD_base              (RAKE_DC_BASE           | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_RAKE_DC)

/* HSPA3 */
#define F8F9_1_SD_base              (UEA_UIA_U0_BASE        | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_UEA_UIA_U0)
#define F8F9_SD_base                (UEA_UIA_U1_BASE        | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_UEA_UIA_U1)
#define F8F9_2_SD_base              (UEA_UIA_U1_BASE        | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_UEA_UIA_U1) // Request by Alfred Lee
#define DPA_RLC_SD_base             (DPA_RLC_BASE           | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_DPA_RLC)
#define DPA_MAC_SD_base             (DPA_MAC_BASE           | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_DPA_MAC)
#define HSUPA_SD_base               (UPA_BASE               | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_UPA)
#define UPA_SD_base                 (UPA_BASE               | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_UPA)
#define UPA_SRAM_SD_base            (0x87E00000             | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_UPA_SRAM)
#define HRXBRP_SD_base              (H_RXBRP_BASE           | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_H_RXBRP)
#define RXBRP_SD_base               (RXBRP_BASE             | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_RXBRP)
#define HSPASYS_CONFIG3_SD_base     (HSPASYS_3_CONFG_BASE   | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_HSPASYS_3_CONFG)
#define TXBRP_SD_base               (TXBRP_BASE             | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_TXBRP)
#define TXCRP_SD_base               (TXCRP_BASE             | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_TXCRP)
#define UTXBRP_SD_base              (H_TXBRP_BASE           | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_H_TXBRP)
#define TXUPC_SD_base               (TXUPC_BASE             | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_TXUPC)
#define BITCP_SD_base               (BC_BASE                | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_BC)
#define HSPA3_DBG_SD_base           (DBG_TX_BASE            | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_DBG_TX)

/* HSPA4 */
#define RXSRP_SD_base               (RXSRP_BASE             | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_RXSRP)
#define INDEC_SD_base               (INDEC_BASE             | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_INDEC)
#define RXCRP0_SD_base              (RAKE_0_BASE            | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_RAKE_0)
#define RXCRP1_SD_base              (RAKE_1_BASE            | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_RAKE_1)
#define RXCRP2_SD_base              (RAKE_2_BASE            | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_RAKE_2)
#define SRCHR_SD_base               (SEARCHER_BASE          | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_SEARCHER)
#define RXDFE_SD_base               (RXDFE_BASE             | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_RXDFE)
#define HSPASYS_CONFIG4_SD_base     (HSPASYS_4_CONFG_BASE   | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_HSPASYS_4_CONFG)
#define HSPA4_DBG_SD_base           (DBG_BASE               | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_DBG)
#define DBG_WRAPPER0_SD_base        (DWRAP0_BASE            | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_DWRAP0)
#define LOG3G_SD_base               (LOG3G_BASE             | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_LOG3G)
#define DBG_WRAPPER1_SD_base        (DWRAP1_BASE            | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_DWRAP1)
#define SIMPLE_DMA_SD_base          (0x878D0000             | DEVICE_TYPE_1)    // 6290: (0xB18D0000)

/* Others */
#define MIX_ABB_SD_base             (MD1_ABB_MIXEDSYS_BASE  | DEVICE_TYPE_1)    // 6290: (BASE_ADDR_MIX_ABB)


/* Strongly Order Type */

#define IDMA_base                   (IDMA_BASE)
#define DPRAM_CPU_base              (0x82200000)
#define AHB2DSPIO_base              (AHB2DSPIO_BASE)
#define MD2GCONFG_base              (MD2G_CONFG_BASE)
#define APC_base                    (APC_BASE)
#define CSD_ACC_base                (CSD_ACC_BASE)
#define SHARE_base                  (SHARE_D1_BASE)    // SHARE_D1 for 2G
#define IRDMA_base                  (IRDMA_BASE)
#define IRDBG_base                  (IRDMA_BASE)
#define PATCH_base                  (PATCH_BASE)
#define AFE_base                    (MDAFE_BASE)
#define BFE_base                    (BFE_BASE)
#define TOPSM_base                  (BASE_MADDR_MDTOPSM)

/* Modem Peripherals */
#define MDCONFIG_base               (MODEM_CONFG_BASE)
#define MODEM2G_CONFG_base          (MODEM_LITE_CONFG_BASE)
#define SLP_CTRL_base               (MODEM_TOPSM_BASE)
#define SLP_2G_CTRL_base            (MODEM_LITE_TOPSM_BASE)
#define TDMA_base                   (TDMA_BASE)
#define SHAREG2_base                (SHREG2_BASE)
#define DIVIDER_base                (0x87040000)
#define FCS_base                    (0x87050000)
#define GCU_base                    (0x87060000)
#define BSI_base                    (BSI_3G_BASE)
#define BSISPI_base                 (PF_BSI_APB1_BASE)
#define BPI_base                    (BPI_3G_BASE)
#define AFC_base                    (AFC_3G_BASE)
#define BASE_MADDR_AFC              (AFC_3G_BASE)
#define DIVIDER2G_base              (DIVIDER_BASE)
#define FCS2G_base                  (FCS_BASE)
#define GCU2G_base                  (GCU_BASE)
#define BSI2G_base                  (BSI_2G_BASE)
#define BPI2G_base                  (BPI_2G_BASE)
#define AFC2G_base                  (AFC_2G_BASE)
#define WCDMA_TIMER_base            (WCDMA_TIMER_BASE)
#define DPA_BC_base                 (DPA_BC_BASE)
//#define PFC_ENCODE_base           (PFC_ENCODE_BASE) // Not in 6290
//#define PFC_DECODE_base           (PFC_DECODE_BASE) // Not in 6290

/* HSPA1 */
#define HSPASYS_CONFIG1_base        (HSPASYS_1_CONFG_BASE)
#define HSEQ_base                   (HSEQ_BASE)
#define HSCE_base                   (HSCE_BASE)

/* HSPA2 */
#define HSPASYS_CONFIG2_base        (HSPASYS_2_CONFG_BASE)
#define HSEQ_DC_base                (HSEQ_DC_BASE)
#define HSCE_DC_base                (HSCE_DC_BASE)
#define RAKEDC_base                 (RAKE_DC_BASE)

/* HSPA3 */
#define F8F9_1_base                 (UEA_UIA_U0_BASE)
#define F8F9_base                   (UEA_UIA_U1_BASE)
#define F8F9_2_base                 (UEA_UIA_U1_BASE) // Request by Alfred Lee
#define DPA_RLC_base                (DPA_RLC_BASE)
#define DPA_MAC_base                (DPA_MAC_BASE)
#define HSUPA_base                  (UPA_BASE)
#define UPA_base                    (UPA_BASE)
#define UPA_SRAM_base               (0x87E00000)
#define HRXBRP_base                 (H_RXBRP_BASE)
#define RXBRP_base                  (RXBRP_BASE)
#define HSPASYS_CONFIG3_base        (HSPASYS_3_CONFG_BASE)
#define TXBRP_base                  (TXBRP_BASE)
#define TXCRP_base                  (TXCRP_BASE)
#define UTXBRP_base                 (H_TXBRP_BASE)
#define TXUPC_base                  (TXUPC_BASE)
#define BITCP_base                  (BC_BASE)
#define HSPA3_DBG_base              (DBG_TX_BASE)

/* HSPA4 */
#define RXSRP_base                  (RXSRP_BASE)
#define INDEC_base                  (INDEC_BASE)
#define RXCRP0_base                 (RAKE_0_BASE)
#define RXCRP1_base                 (RAKE_1_BASE)
#define RXCRP2_base                 (RAKE_2_BASE)
#define SRCHR_base                  (SEARCHER_BASE)
#define RXDFE_base                  (RXDFE_BASE)
#define HSPASYS_CONFIG4_base        (HSPASYS_4_CONFG_BASE)
#define HSPA4_DBG_base              (DBG_BASE)
#define DBG_WRAPPER0_base           (DWRAP0_BASE)
#define LOG3G_base                  (LOG3G_BASE)
#define DBG_WRAPPER1_base           (DWRAP1_BASE)
#define SIMPLE_DMA_base             (0x878D0000)

/* Others */
#define MIX_ABB_base                (MD1_ABB_MIXEDSYS_BASE)

/*AP GPIO*/
#define GPIO_base                   (0xA0005000)
#define BASE_MADDR_U2MAC            (0xA1200000)
#define BASE_ADDR_U2PHY             (0xA1210000)


#else    /* MD2 case */

/********************************************
 * MT6752 MD2 Stronly Ordered Peripheral Base
 ********************************************/
//MD PSYS APB
#define CONFIG_base				    (0x80000000)
#define CIRQ_base				    (0x80010000)
#define CIRQ_EINT_base              (0x80010000) //not in mt6255
#define TOPSM_base				    (0x80030000) //not in mt6255
#define OSTIMER_base                (0x80040000) //not in mt6255
#define RGU_base				    (0x80050000)
#define GPT_base				    (0x80060000)
#define UART1_base				    (0x80070000)
#define DEBUG_MD_base               (0x80090000) //new one, not in mt6255 
#define DMA_base				    (0x800B0000)
#define SIM0_base				    (0x800C0000)
#define SIM1_base				    (0x800D0000)
#define MD_MBIST_CONFIG_base        (0x800E0000) //new one, not in mt6255
#define PLL_MIXEDSYS_base           (0x80120000) //new one, not in mt6255
#define ABB_MIXEDSYS_base           (0x80130000) //new one, not in mt6255 
#define ASM_base				    (0x80140000) //not in mt6255
#define ADOE_base				    (0x80150000) //not in mt6255
#define BOOT_SLAVE_base             (0x80190000) //not in mt6255
	
//MD2GSYS AHB
#define IDMA_base				    (0x82000000)
#define DPRAM_CPU_base              (0x82200000) //requested by sean yang
#define AHB2DSPIO_base              (0x82800000) //not in mt6255

//MD2G APB
#define MD2GCONFG_base              (0x82C00000)
#define MD2G_MBIST_CONFIG_base      (0x82C10000)
#define APC_base				    (0x82C30000)
#define CSD_ACC_base				(0x82C70000)
#define SHARE_base				    (0x82CA0000)
#define IRDMA_base				    (0x82CB0000)
#define IRDBG_base                  (IRDMA_base)
#define PATCH_base				    (0x82CC0000) //not in mt6255
#define AFE_base				    (0x82CD0000)
#define BFE_base				    (0x82CE0000)
	
//MODEMSYS_TOP APB
#define MDCONFIG_base				(0x83000000) //not in mt6255
#define SLP_CTRL_base				(0x83010000) //not in mt6255
#define TDMA_base				    (0x83020000)
#define SHAREG2_base				(0x83030000) //not in mt6255
#define DIVIDER_base				(0x83040000)
#define FCS_base				    (0x83050000)
#define GCU_base				    (0x83060000)
#define BSI_base				    (0x83070000)
#define BPI_base				    (0x83080000)
#define AFC_base				    (0x83090000)
#define WCDMA_TIMER_base			(0x830A0000) //not in mt6255
#define DPA_BC_base 				(0x830B0000) //not in mt6255
	
//HSPASYS_1 APB
#define HSPASYS_CONFIG1_base        (0x83200000) //not in mt6255
#define HSEQ_base                   (0x83210000) //not in mt6255
#define HSCE_base                   (0x83220000) //not in mt6255
#define HSPASYS_1_MBIST_base        (0x83230000) //new one, not in mt6255
	
//HSPASYS_2 APB
#define HSPASYS_CONFIG2_base    	(0x83400000) //not in mt6255
#define HSEQ_DC_base           		(0x83410000) //not in mt6255
#define HSCE_DC_base            	(0x83420000) //not in mt6255
#define RAKEDC_base             	(0x83430000) //not in mt6255
#define HSPASYS_2_MBIST_base		(0x83440000) //new one, not in mt6255
	
//HSPASYS_3 APB
#define F8F9_1_base             	(0x83600000) //not in mt6255
#define F8F9_base               	(0x83610000) //not in mt6255
#define F8F9_2_base             	(0x83610000) //not in mt6255 
#define DPA_RLC_base            	(0x83620000) //not in mt6255
#define DPA_MAC_base            	(0x83630000) //not in mt6255
#define HSUPA_base              	(UPA_base)   //not in mt6255
#define UPA_base                	(0x83640000) //not in mt6255
#define HRXBRP_base             	(0x83650000) //not in mt6255
#define RXBRP_base              	(0x83660000) //not in mt6255
#define HSPASYS_CONFIG3_base    	(0x83670000) //not in mt6255
#define TXBRP_base              	(0x83680000) //not in mt6255
#define TXCRP_base              	(0x83690000) //not in mt6255
#define UTXBRP_base             	(0x836A0000) //not in mt6255
#define TXUPC_base              	(0x836B0000) //not in mt6255
#define BITCP_base              	(0x836C0000) //not in mt6255
#define HSPA3_DBG_base          	(0x836D0000) //not in mt6255
#define HSPASYS_3_MBIST_base		(0x836E0000) //not in mt6255
	
//HSPASYS_4 APB
#define RXSRP_base				    (0x83800000) //not in mt6255
#define INDEC_base				    (0x83810000) //not in mt6255
#define RXCRP0_base				    (0x83820000) //not in mt6255
#define RXCRP1_base				    (0x83830000) //not in mt6255
#define RXCRP2_base				    (0x83840000) //not in mt6255
#define SRCHR_base				    (0x83850000) //not in mt6255
#define RXDFE_base				    (0x83860000) //not in mt6255
#define HSPASYS_CONFIG4_base		(0x83870000) //not in mt6255
#define HSPA4_DBG_base				(0x83880000) //not in mt6255
#define DBG_WRAPPER0_base			(0x83890000) //not in mt6255
#define LOG3G_base				    (0x838A0000) //not in mt6255
#define HSPASYS_4_MBIST_base		(0x838B0000) //not in mt6255
#define DBG_WRAPPER1_base			(0x838C0000) //not in mt6255
#define SIMPLE_DMA_base         	(0x838D0000) //not in mt6255

/********************************************
 * MT6752 MD2 Device Type Peripheral Base (TODO)
 ********************************************/
//MD PSYS APB
#define CONFIG_SD_base				(0x80000000)
#define CIRQ_SD_base				(0x80010000)
#define CIRQ_EINT_SD_base			(0x80010000) //not in mt6255
#define TOPSM_SD_base				(0x80030000) //not in mt6255
#define OSTIMER_SD_base				(0x80040000) //not in mt6255
#define RGU_SD_base				    (0x80050000)
#define GPT_SD_base				    (0x80060000)
#define UART1_SD_base				(0x80070000)
#define DEBUG_MD_SD_base			(0x80090000) //new one, not in mt6255 
#define DMA_SD_base				    (0x800B0000)
#define SIM0_SD_base				(0x800C0000)
#define SIM1_SD_base				(0x800D0000)
#define MD_MBIST_CONFIG_SD_base		(0x800E0000) //new one, not in mt6255
#define PLL_MIXEDSYS_SD_base		(0x80120000) //new one, not in mt6255
#define ABB_MIXEDSYS_SD_base		(0x80130000) //new one, not in mt6255 
#define ASM_SD_base				    (0x80140000) //not in mt6255
#define ADOE_SD_base				(0x80150000) //not in mt6255
#define BOOT_SLAVE_SD_base			(0x80190000) //not in mt6255
	
//MD2GSYS AHB
#define IDMA_SD_base				(0x82000000)
#define DPRAM_CPU_SD_base 			(0x82200000) //requested by sean yang
#define AHB2DSPIO_SD_base			(0x82800000) //not in mt6255

//MD2G APB
#define MD2GCONFG_SD_base			(0x82C00000)
#define MD2G_MBIST_CONFIG_SD_base	(0x82C10000)
#define APC_SD_base				    (0x82C30000)
#define CSD_ACC_SD_base				(0x82C70000)
#define SHARE_SD_base				(0x82CA0000)
#define IRDMA_SD_base				(0x82CB0000)
#define IRDBG_SD_base              	(IRDMA_SD_base)
#define PATCH_SD_base				(0x82CC0000) //not in mt6255
#define AFE_SD_base				    (0x82CD0000)
#define BFE_SD_base				    (0x82CE0000)
	
//MODEMSYS_TOP APB
#define MDCONFIG_SD_base			(0x83000000) //not in mt6255
#define SLP_CTRL_SD_base			(0x83010000) //not in mt6255
#define TDMA_SD_base				(0x83020000)
#define SHAREG2_SD_base				(0x83030000) //not in mt6255
#define DIVIDER_SD_base				(0x83040000)
#define FCS_SD_base				    (0x83050000)
#define GCU_SD_base				    (0x83060000)
#define BSI_SD_base				    (0x83070000)
#define BPI_SD_base				    (0x83080000)
#define AFC_SD_base				    (0x83090000)
#define WCDMA_TIMER_SD_base			(0x830A0000) //not in mt6255
#define DPA_BC_SD_base 				(0x830B0000) //not in mt6255
	
//HSPASYS_1 APB
#define HSPASYS_CONFIG1_SD_base    	(0x83200000) //not in mt6255
#define HSEQ_SD_base               	(0x83210000) //not in mt6255
#define HSCE_SD_base               	(0x83220000) //not in mt6255
#define HSPASYS_1_MBIST_SD_base		(0x83230000) //new one, not in mt6255
	
//HSPASYS_2 APB
#define HSPASYS_CONFIG2_SD_base    	(0x83400000) //not in mt6255
#define HSEQ_DC_SD_base           	(0x83410000) //not in mt6255
#define HSCE_DC_SD_base            	(0x83420000) //not in mt6255
#define RAKEDC_SD_base             	(0x83430000) //not in mt6255
#define HSPASYS_2_MBIST_SD_base		(0x83440000) //new one, not in mt6255
	
//HSPASYS_3 APB
#define F8F9_1_SD_base             	(0x83600000) //not in mt6255
#define F8F9_SD_base               	(0x83610000) //not in mt6255
#define F8F9_2_SD_base             	(0x83610000) //not in mt6255 
#define DPA_RLC_SD_base            	(0x83620000) //not in mt6255
#define DPA_MAC_SD_base            	(0x83630000) //not in mt6255
#define HSUPA_SD_base              	(UPA_SD_base)   //not in mt6255
#define UPA_SD_base                	(0x83640000) //not in mt6255
#define HRXBRP_SD_base             	(0x83650000) //not in mt6255
#define RXBRP_SD_base              	(0x83660000) //not in mt6255
#define HSPASYS_CONFIG3_SD_base    	(0x83670000) //not in mt6255
#define TXBRP_SD_base              	(0x83680000) //not in mt6255
#define TXCRP_SD_base              	(0x83690000) //not in mt6255
#define UTXBRP_SD_base             	(0x836A0000) //not in mt6255
#define TXUPC_SD_base              	(0x836B0000) //not in mt6255
#define BITCP_SD_base              	(0x836C0000) //not in mt6255
#define HSPA3_DBG_SD_base          	(0x836D0000) //not in mt6255
#define HSPASYS_3_MBIST_SD_base		(0x836E0000) //not in mt6255
	
//HSPASYS_4 APB
#define RXSRP_SD_base				(0x83800000) //not in mt6255
#define INDEC_SD_base				(0x83810000) //not in mt6255
#define RXCRP0_SD_base				(0x83820000) //not in mt6255
#define RXCRP1_SD_base				(0x83830000) //not in mt6255
#define RXCRP2_SD_base				(0x83840000) //not in mt6255
#define SRCHR_SD_base				(0x83850000) //not in mt6255
#define RXDFE_SD_base				(0x83860000) //not in mt6255
#define HSPASYS_CONFIG4_SD_base		(0x83870000) //not in mt6255
#define HSPA4_DBG_SD_base			(0x83880000) //not in mt6255
#define DBG_WRAPPER0_SD_base		(0x83890000) //not in mt6255
#define LOG3G_SD_base				(0x838A0000) //not in mt6255
#define HSPASYS_4_MBIST_SD_base		(0x838B0000) //not in mt6255
#define DBG_WRAPPER1_SD_base		(0x838C0000) //not in mt6255
#define SIMPLE_DMA_SD_base         	(0x838D0000) //not in mt6255


//USB APB setting requested by Arvin Wang
//#define USB_base				(0xa1200000)
//#define USBSIF_base				(0xa1220000)
#define AP_MDCCIF_base              (0xA0013000)	//AP CCIF2 (MDSYS LITE)
#define MDCCIF2_base                 (0xA0014000)	//MD CCIF2 (MDSYS LITE)

//********************************************
//MD2 user define transform, same as MD1 naming
//********************************************
#define GCU2G_base                  GCU_base
#define FCS2G_base                  FCS_base 
#define DIVIDER2G_base              DIVIDER_base
#define BASE_ADDR_MDTOPSM           TOPSM_base

#define EMI_base			        (AP_EMI_base)	//EMI Bus Interface
#define AP_EMI_base			        (0xA0203000)	//EMI Bus Interface
#define AP_GPIO_base			    (0xA0005000)	//GPIO Controller
#define EFUSE_base                  (EFUSEC_BASE)

#endif    /* end of MD2 case */



/********************************************
 * MT6752 AP Peripheral Register Base (MD1/MD2 common)
 ********************************************/
// APB Module cksys
#define CKSYS_BASE (0xA0000000)
// APB Module infracfg_ao
#define INFRACFG_AO_BASE (0xA0001000)
// APB Module toprgu
#define TOPRGU_BASE (0xA0007000)
// APB Module pmic_wrap
#define PWRAP_BASE (0xA000D000)
// APB Module efusec
#define EFUSEC_BASE (0xA0206000)
// APB Module ccif
#ifdef __MD1__
#define MD_CCIF0_BASE (0xA020A000)
#elif defined(__MD2__)
#define MD_CCIF0_BASE (0xA020C000)
#endif
// APB Module pccif
#define PCCIF_MD1_base (0xA0211000)
// APB Module pccif
#define PCCIF_MD2_base (0xA0213000)
// APB Module perisys_iommu
#define PERISYS_IOMMU_BASE (0xA0214000)
// APB Module audiosys
#define AUDIOSYS_BASE (0xA1220000)
// APB Module ssusb_top
#define USB3_BASE (0xA1270000)
// APB Module ssusb_top_sif
#define USB3_SIF_BASE (0xA1280000)
// APB Module ssusb_top_sif2
#define USB3_SIF2_BASE (0xA1290000)
// APB Module for BTPKT
#define BTPKT_base                (0xA8000000)  //BT SCO SW codec interface
// APB Module for BTSRAM
#define BTSRAM_base               (0xA8080000)  //BT SCO SW codec interface

#define AP_AUDSYS_base              (AUDIOSYS_BASE)                             // AP Peripheral


#endif /* end of __REG_BASE_MT6752_H__ */
