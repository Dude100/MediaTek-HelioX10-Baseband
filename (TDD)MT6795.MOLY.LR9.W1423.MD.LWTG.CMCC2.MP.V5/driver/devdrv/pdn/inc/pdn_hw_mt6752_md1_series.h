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
 ****************************************************************************/

/*****************************************************************************
 * Filename:
 * ---------
 *   pdn_hw_mt6752_md1_series.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   PDN Driver Related HW Registers
 *
 * Author:
 * -------
 * -------
 *
 * ===========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * Fix some MD2 build error and code cleanup
 *
 ****************************************************************************/

#ifndef __PDN_HW_MT6752_MD1_SERIES_H__
#define __PDN_HW_MT6752_MD1_SERIES_H__

#include "reg_base.h"

#define MD_MCU_MISC1                        ((BASE_ADDR_MDCONFIG+0x304))
    #define CG_MDMCU_BUSMON_HF                  (1 << 2)  // After checked with DE, this is not related to PFB
    #define CG_MDMCU_BUSMON_HS                  (1 << 1)

#define MD_GLOBAL_CON0                      ((BASE_ADDR_MDCONFIG+0x450))
#define MD_GLOBAL_SET0                      ((BASE_ADDR_MDCONFIG+0x454))
#define MD_GLOBAL_CLR0                      ((BASE_ADDR_MDCONFIG+0x458))
    #define CG_PFB                              (1 << 18)
    #define CG_ALC                              (1 << 17)
    #define CG_ELM                              (1 << 16)
    #define CG_MDINFRA_BUSMON_HF                (1 << 15)
    #define CG_MDINFRA_BUSMON_HS                (1 << 14)
    #define CG_RSVD13                           (1 << 13)
    #define CG_CLDMA                            (1 << 12)
    #define CG_USIM2                            (1 << 11)
    #define CG_USIM1                            (1 << 10)
    #define CG_LPM                              (1 << 9)
    #define CG_TOPSM                            (1 << 8)
    #define CG_GPT                              (1 << 7)
    #define CG_OSTIMER                          (1 << 6)
    #define CG_DBG                              (1 << 5)
    #define CG_MDUART                           (1 << 4)
    #define CG_ADOE                             (1 << 3)
    #define CG_ABM                              (1 << 2)
    #define CG_BOOT_SLV                         (1 << 1)
    #define CG_MDGDMA                           (1 << 0)

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

#endif  /* !__PDN_HW_MT6752_MD1_SERIES_H__ */
