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

/*******************************************************************************
 * Filename:
 * ---------
 *   pdn_hw_mt6290_series.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   PDN Driver Related HW Registers
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 ****************************************************************************/

#ifndef __PDN_HW_MT6290_SERIES_H__
#define __PDN_HW_MT6290_SERIES_H__

#include "reg_base.h"

#define REG_MDCLKCTL_MDCLKONCTL	            (BASE_MADDR_MDCLKCTL + 0x18)
    #define MD_ABM_CKEN                         (1 << 22)
    #define MD_LTEL2_CKEN                       (1 << 21)
    #define MD_TDD_CKEN                         (1 << 20)
    #define MD_MODEM3G_CKEN                     (1 << 19)
    #define MD_MODEM2G_CKEN                     (1 << 18)
    #define MD_MDCAIF_CKEN                      (1 << 17)
    #define MD_CR4PCMON_CKEN                    (1 << 16)
    #define MD_MDMCU_BUSMON_CKEN                (1 << 15)
    #define MD_MDINFRA_BUSMON_CKEN              (1 << 14)
    #define MD_RTC_CKEN                         (1 << 13)
    #define MD_MDCIRQ_CKEN                      (1 << 12)
    #define MD_MDGDMA_CKEN                      (1 << 11)
    #define MD_GPIO_CKEN                        (1 << 10)
    #define MD_MDGPTM_CKEN                      (1 << 9)
    #define MD_LED_CKEN                         (1 << 8)
    #define MD_I2C_CKEN                         (1 << 7)
    #define MD_SUART1_CKEN                      (1 << 6)
    #define MD_SUART0_CKEN                      (1 << 5)
    #define MD_MDUART_CKEN                      (1 << 4)
    #define MD_USIM2_CKEN                       (1 << 3)
    #define MD_USIM1_CKEN                       (1 << 2)
    #define MD_BOOTROM_CKEN                     (1 << 1)
    #define MD_SDIO_CKEN                        (1 << 0)
#define REG_MDCLKCTL_APCLKONCTL	            (BASE_MADDR_MDCLKCTL + 0x1C)
    #define MD_SDCTL_EHPI_CKEN                  (1 << 20)
    #define MD_SPI_CKEN                         (1 << 19)
    #define MD_APPERI_BUSMON_CKEN               (1 << 18)
    #define MD_APMCU_BUSMON_CKEN                (1 << 17)
    #define MD_APUART_CKEN                      (1 << 16)
    #define MD_APGDMA_CKEN                      (1 << 15)
    #define MD_APGPTM_CKEN                      (1 << 13)
    #define MD_CLDMA_CKEN                       (1 << 12)
    #define MD_CCIF_CKEN                        (1 << 11)
    #define MD_NIC_CKEN                         (1 << 10)
    #define MD_IPSEC_CKEN                       (1 << 9)
    #define MD_NLI_ARB_CKEN                     (1 << 8)
    #define MD_NFI_CKEN                         (1 << 7)
    #define MD_PFC_CKEN                         (1 << 6)
    #define MD_HIF_CKEN                         (1 << 5)
    #define MD_MSDC1_CKEN                       (1 << 4)
    #define MD_MSDC0_CKEN                       (1 << 3)
    #define MD_U2_CKEN                          (1 << 2)
    #define MD_U3_CKEN                          (1 << 0)
#define REG_MDCLKCTL_MDTOPSM_SW_CTL	        (BASE_MADDR_MDCLKCTL + 0x404)
    #define MDTOPSM_LTEL1_MIXEDCLK_REQ_SW_CTL   (1 << 25)
    #define MDTOPSM_TDD_MIXEDCLK_REQ_SW_CTL     (1 << 24)
    #define MDTOPSM_TDMA_MIXEDCLK_REQ_SW_CTL    (1 << 23)
    #define MDTOPSM_WCDMA_MIXEDCLK_REQ_SW_CTL   (1 << 22)
    #define MDTOPSM_DBG_CK_REQ_SW_CTL           (1 << 21)
    #define MDTOPSM_EMI_CK_REQ_SW_CTL           (1 << 20)
    #define MDTOPSM_BUS2X_CK_REQ_SW_CTL         (1 << 19)
    #define MDTOPSM_ARM7_CK_REQ_SW_CTL          (1 << 18)
    #define MDTOPSM_CR4_CK_REQ_SW_CTL           (1 << 17)
    #define MDTOPSM_SRCLKEN_SW_CTL              (1 << 16)
    #define MDTOPSM_LTEL1_MIXEDCLK_REQ_SW_OWN   (1 << 9)
    #define MDTOPSM_TDD_MIXEDCLK_REQ_SW_OWN     (1 << 8)
    #define MDTOPSM_TDMA_MIXEDCLK_REQ_SW_OWN    (1 << 7)
    #define MDTOPSM_WCDMA_MIXEDCLK_REQ_SW_OWN   (1 << 6)
    #define MDTOPSM_DBG_CK_REQ_SW_OWN           (1 << 5)
    #define MDTOPSM_EMI_CK_REQ_SW_OWN           (1 << 4)
    #define MDTOPSM_BUS2X_CK_REQ_SW_OWN         (1 << 3)
    #define MDTOPSM_ARM7_CK_REQ_SW_OWN          (1 << 2)
    #define MDTOPSM_CR4_CK_REQ_SW_OWN           (1 << 1)
    #define MDTOPSM_SRCLKEN_SW_OWN              (1 << 0)
#define REG_MDCLKCTL_APTOPSM_SW_CTL         (BASE_MADDR_MDCLKCTL + 0x408)
    #define APTOPSM_SSUSB_CK_REQ_SW_CTL         (1 << 25)
    #define APTOPSM_TRACE_CK_REQ_SW_CTL         (1 << 24)
    #define APTOPSM_SPI_CK_REQ_SW_CTL           (1 << 23)
    #define APTOPSM_NIC_CK_REQ_SW_CTL           (1 << 22)
    #define APTOPSM_USB_CK_REQ_SW_CTL           (1 << 21)
    #define APTOPSM_MSDC1P_CK_REQ_SW_CTL        (1 << 20)
    #define APTOPSM_MSDC0P_CK_REQ_SW_CTL        (1 << 19)
    #define APTOPSM_BUS2X_CK_REQ_SW_CTL         (1 << 18)
    #define APTOPSM_CA7_CK_REQ_SW_CTL           (1 << 17)
    #define APTOPSM_SRCLKEN_SW_CTL              (1 << 16)
    #define APTOPSM_SSUSB_CK_REQ_SW_OWN         (1 << 9)
    #define APTOPSM_TRACE_CK_REQ_SW_OWN         (1 << 8)
    #define APTOPSM_SPI_CK_REQ_SW_OWN           (1 << 7)
    #define APTOPSM_NIC_CK_REQ_SW_OWN           (1 << 6)
    #define APTOPSM_USB_CK_REQ_SW_OWN           (1 << 5)
    #define APTOPSM_MSDC1P_CK_REQ_SW_OWN        (1 << 4)
    #define APTOPSM_MSDC0P_CK_REQ_SW_OWN        (1 << 3)
    #define APTOPSM_BUS2X_CK_REQ_SW_OWN         (1 << 2)
    #define APTOPSM_CA7_CK_REQ_SW_OWN           (1 << 1)
    #define APTOPSM_SRCLKEN_SW_OWN              (1 << 0)
#define REG_MDCLKCTL_LTEL1_TOPSM_SW_CTL     (BASE_MADDR_MDCLKCTL + 0x40C)
    #define LTEL1_TOPSM_MIXEDSYS_CK_REQ_SW_CTL  (1 << 22)
    #define LTEL1_TOPSM_BSISPIC_CK_REQ_SW_CTL   (1 << 21)
    #define LTEL1_TOPSM_PHY_CK_REQ_SW_CTL       (1 << 20)
    #define LTEL1_TOPSM_DBGSYS_CK_REQ_SW_CTL    (1 << 19)
    #define LTEL1_TOPSM_BUS1X_CK_REQ_SW_CTL     (1 << 18)
    #define LTEL1_TOPSM_MEMSYS_CK_REQ_SW_CTL    (1 << 17)
    #define LTEL1_TOPSM_SYSCLK_SW_CTL           (1 << 16)
    #define LTEL1_TOPSM_MIXEDSYS_CK_REQ_SW_OWN  (1 << 6)
    #define LTEL1_TOPSM_BSISPIC_CK_REQ_SW_OWN   (1 << 5)
    #define LTEL1_TOPSM_PHY_CK_REQ_SW_OWN       (1 << 4)
    #define LTEL1_TOPSM_DBGSYS_CK_REQ_SW_OWN    (1 << 3)
    #define LTEL1_TOPSM_BUS1X_CK_REQ_SW_OWN     (1 << 2)
    #define LTEL1_TOPSM_MEMSYS_CK_REQ_SW_OWN    (1 << 1)
    #define LTEL1_TOPSM_SYSCLK_SW_OWN           (1 << 0)
#define REG_MDCLKCTL_MODEM_TOPSM_SW_CTL     (BASE_MADDR_MDCLKCTL + 0x410)
    #define TDD_TOPSM_CLKEN_REQ_SW_CTL          (1 << 25)
    #define MODEM2_X16GCLK_REQ_SW_CTL           (1 << 24)
    #define MODEM2_DSPCLK_REQ_SW_CTL            (1 << 23)
    #define MODEM2_BUSCLK_REQ_SW_CTL            (1 << 22)
    #define MODEM2_SYSCLK_REQ_SW_CTL            (1 << 21)
    #define MODEM_X64WCLK_REQ_SW_CTL            (1 << 20)
    #define MODEM_HX64WCLK_REQ_SW_CTL           (1 << 19)
    #define MODEM_X16GCLK_REQ_SW_CTL            (1 << 18)
    #define MODEM_BUSCLK_REQ_SW_CTL             (1 << 17)
    #define MODEM_SYSCLK_REQ_SW_CTL             (1 << 16)
    #define TDD_TOPSM_CLKEN_REQ_SW_OWN          (1 << 9)
    #define MODEM2_X16GCLK_REQ_SW_OWN           (1 << 8)
    #define MODEM2_DSPCLK_REQ_SW_OWN            (1 << 7)
    #define MODEM2_BUSCLK_REQ_SW_OWN            (1 << 6)
    #define MODEM2_SYSCLK_REQ_SW_OWN            (1 << 5)
    #define MODEM_X64WCLK_REQ_SW_OWN            (1 << 4)
    #define MODEM_HX64WCLK_REQ_SW_OWN           (1 << 3)
    #define MODEM_X16GCLK_REQ_SW_OWN            (1 << 2)
    #define MODEM_BUSCLK_REQ_SW_OWN             (1 << 1)
    #define MODEM_SYSCLK_REQ_SW_OWN             (1 << 0)

#define REG_APCLKCTL_MDCLKONCTL	            (BASE_MADDR_APCLKCTL + 0x18)
    #define AP_ABM_CKEN                         (1 << 22)
    #define AP_LTEL2_CKEN                       (1 << 21)
    #define AP_TDD_CKEN                         (1 << 20)
    #define AP_MODEM3G_CKEN                     (1 << 19)
    #define AP_MODEM2G_CKEN                     (1 << 18)
    #define AP_MDCAIF_CKEN                      (1 << 17)
    #define AP_CR4PCMON_CKEN                    (1 << 16)
    #define AP_MDMCU_BUSMON_CKEN                (1 << 15)
    #define AP_MDINFRA_BUSMON_CKEN              (1 << 14)
    #define AP_RTC_CKEN                         (1 << 13)
    #define AP_MDCIRQ_CKEN                      (1 << 12)
    #define AP_MDGDMA_CKEN                      (1 << 11)
    #define AP_GPIO_CKEN                        (1 << 10)
    #define AP_MDGPTM_CKEN                      (1 << 9)
    #define AP_LED_CKEN                         (1 << 8)
    #define AP_I2C_CKEN                         (1 << 7)
    #define AP_SUART1_CKEN                      (1 << 6)
    #define AP_SUART0_CKEN                      (1 << 5)
    #define AP_MDUART_CKEN                      (1 << 4)
    #define AP_USIM2_CKEN                       (1 << 3)
    #define AP_USIM1_CKEN                       (1 << 2)
    #define AP_BOOTROM_CKEN                     (1 << 1)
    #define AP_SDIO_CKEN                        (1 << 0)
#define REG_APCLKCTL_APCLKONCTL	            (BASE_MADDR_APCLKCTL + 0x1C)
    #define AP_SDCTL_EHPI_CKEN                  (1 << 20)
    #define AP_SPI_CKEN                         (1 << 19)
    #define AP_APPERI_BUSMON_CKEN               (1 << 18)
    #define AP_APMCU_BUSMON_CKEN                (1 << 17)
    #define AP_APUART_CKEN                      (1 << 16)
    #define AP_APGDMA_CKEN                      (1 << 15)
    #define AP_APGPTM_CKEN                      (1 << 13)
    #define AP_CLDMA_CKEN                       (1 << 12)
    #define AP_CCIF_CKEN                        (1 << 11)
    #define AP_NIC_CKEN                         (1 << 10)
    #define AP_IPSEC_CKEN                       (1 << 9)
    #define AP_NLI_ARB_CKEN                     (1 << 8)
    #define AP_NFI_CKEN                         (1 << 7)
    #define AP_PFC_CKEN                         (1 << 6)
    #define AP_HIF_CKEN                         (1 << 5)
    #define AP_MSDC1_CKEN                       (1 << 4)
    #define AP_MSDC0_CKEN                       (1 << 3)
    #define AP_U2_CKEN                          (1 << 2)
    #define AP_U3_CKEN                          (1 << 0)

#define REG_MODEM_CG_CON0                   (MDCONFIG_base + 0x0)
#define REG_MODEM_CG_CLR0                   (MDCONFIG_base + 0x10)
#define REG_MODEM_CG_SET0                   (MDCONFIG_base + 0x20)
    #define CG_PFC_ENC                          (1 << 30)
    #define CG_ATB                              (1 << 29)
    #define CG_BYC_ACC                          (1 << 9)
    #define CG_PFC_DEC                          (1 << 8)
    #define CG_AFC_3G                           (1 << 7)
    #define CG_WTIMER                           (1 << 6)
    #define CG_BPI_3G                           (1 << 5)
    #define CG_BSI_3G                           (1 << 4)
    #define CG_BPI_PMIC                         (1 << 3)
    #define CG_BSI_PMIC                         (1 << 2)

#define REG_MODEM_CG_CON2                   (MODEM2G_CONFG_base + 0x8)
#define REG_MODEM_CG_CLR2                   (MODEM2G_CONFG_base + 0x18)
#define REG_MODEM_CG_SET2                   (MODEM2G_CONFG_base + 0x28)
    #define CG_GCU                              (1 << 13)
    #define CG_FCS                              (1 << 12)
    #define CG_DIVIDER                          (1 << 11)
    #define CG_AFC_2G_T                         (1 << 4)
    #define CG_BPI_2G_T                         (1 << 3)
    #define CG_BSI_2G_T                         (1 << 2)
    #define CG_TDMA                             (1 << 0)

#define REG_MODEM_CG_CON4                   (MODEM2G_CONFG_base + 0x88)
#define REG_MODEM_CG_CLR4                   (MODEM2G_CONFG_base + 0x98)
#define REG_MODEM_CG_SET4                   (MODEM2G_CONFG_base + 0xA8)
    #define CG_AFC_2G                           (1 << 4)
    #define CG_BPI_2G                           (1 << 3)
    #define CG_BSI_2G                           (1 << 2)    
    
#define REG_MD2GSYS_CG_CON0                 (MD2GCONFG_base + 0x0)
#define REG_MD2GSYS_CG_SET0                 (MD2GCONFG_base + 0x10)
#define REG_MD2GSYS_CG_CLR0                 (MD2GCONFG_base + 0x20)
    #define CG_AHB2SDIO                         (1 << 15)
    #define CG_IRDBG                            (1 << 13)
    #define CG_TXBUF                            (1 << 9)
    #define CG_RXBUF                            (1 << 8)
    #define CG_IRDMA                            (1 << 6)
    #define CG_GCC                              (1 << 1)

#define REG_MD2GSYS_CG_CON2                 (MD2GCONFG_base + 0x8)
#define REG_MD2GSYS_CG_SET2                 (MD2GCONFG_base + 0x18)
#define REG_MD2GSYS_CG_CLR2                 (MD2GCONFG_base + 0x28)
    #define CG_BFE                              (1 << 9)
    #define CG_VAFE                             (1 << 8)
    #define CG_APC_PRE                          (1 << 5)

#define REG_MD2GSYS_CG_CON4                 (MD2GCONFG_base + 0x30)
#define REG_MD2GSYS_CG_SET4                 (MD2GCONFG_base + 0x34)
#define REG_MD2GSYS_CG_CLR4                 (MD2GCONFG_base + 0x38)
    #define CG_APC                              (1 << 5)
    
#endif  /* !__PDN_HW_MT6290_SERIES_H__ */
