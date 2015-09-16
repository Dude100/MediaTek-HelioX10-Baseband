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
 ****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    pdn_hw_mt6752_md2_series.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines PDN HW registers for MT6752 series chips.
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
 *
 * removed!
 * removed!
 * Merging from CL#57228
 *
 * removed!
 * removed!
 * Remove MT6752 MD2 AP side PDN control (from MT6589)
 *
 * removed!
 * removed!
 * Comment 89 ap address for build error, this must be review later
 *
 * removed!
 * removed!
 * Fix some MD2 build error and code cleanup
 *
 * removed!
 * removed!
 * a special combination key to speed up  HIF PDN operation.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * rename MT6583 to MT6589.
 *
 * removed!
 * removed!
 * fix compile error of missed register definition.
 *
 * removed!
 * removed!
 * phase-in MT6583 support.
 *
 *****************************************************************************/

#include "reg_base.h"

#ifndef __PDN_HW_MT6752_MD2_SERIES_H__
#define __PDN_HW_MT6752_MD2_SERIES_H__

/* MDODEM 2G CONFIG */
/* 3G */
#define DRVPDN_MODEM2G_CONFIG_CG_CON0            (MDCONFIG_base+0x0000)
#define DRVPDN_MODEM2G_CONFIG_CG_CLR0            (MDCONFIG_base+0x0010)
#define DRVPDN_MODEM2G_CONFIG_CG_SET0            (MDCONFIG_base+0x0020)
    #define MODEM2G_CONFIG_CG_CON0_BSIPMIC       (1 <<  2)
    #define MODEM2G_CONFIG_CG_CON0_BPIPMIC       (1 <<  2)
    #define MODEM2G_CONFIG_CG_CON0_BSI3G         (1 <<  4)
    #define MODEM2G_CONFIG_CG_CON0_BPI3G         (1 <<  5)
    #define MODEM2G_CONFIG_CG_CON0_WCDMATIMER    (1 <<  6)
    #define MODEM2G_CONFIG_CG_CON0_AFC3G         (1 <<  7)
    #define MODEM2G_CONFIG_CG_CON0_PFCDEC        (1 <<  8)
    #define MODEM2G_CONFIG_CG_CON0_BYCACC        (1 <<  9)
    #define MODEM2G_CONFIG_CG_CON0_ATB           (1 << 29)
    #define MODEM2G_CONFIG_CG_CON0_PFCENC        (1 << 30)

/* 2G */
#define DRVPDN_MODEM2G_CONFIG_CG_CON2            (MDCONFIG_base+0x0008)
#define DRVPDN_MODEM2G_CONFIG_CG_CLR2            (MDCONFIG_base+0x0018)
#define DRVPDN_MODEM2G_CONFIG_CG_SET2            (MDCONFIG_base+0x0028)
    #define MODEM2G_CONFIG_CG_CON2_TDMA          (1 <<  0)
    #define MODEM2G_CONFIG_CG_CON2_BSI2G_T       (1 <<  2)
    #define MODEM2G_CONFIG_CG_CON2_BPI2G_T       (1 <<  3)
    #define MODEM2G_CONFIG_CG_CON2_AFC2G_T       (1 <<  4)
    #define MODEM2G_CONFIG_CG_CON2_DIV           (1 << 11)
    #define MODEM2G_CONFIG_CG_CON2_FCS           (1 << 12)
    #define MODEM2G_CONFIG_CG_CON2_GCU           (1 << 13)

#define DRVPDN_MODEM2G_CONFIG_CG_CON4            (MDCONFIG_base+0x0088)
#define DRVPDN_MODEM2G_CONFIG_CG_CLR4            (MDCONFIG_base+0x0098)
#define DRVPDN_MODEM2G_CONFIG_CG_SET4            (MDCONFIG_base+0x00A8)
    #define MODEM2G_CONFIG_CG_CON4_BSI2G         (1 <<  2)
    #define MODEM2G_CONFIG_CG_CON4_BPI2G         (1 <<  3)
    #define MODEM2G_CONFIG_CG_CON4_AFC2G         (1 <<  4)

/* MD2GSYS CONFIG */
#define REG_MD2GCONFIG_CG_CON0                   (MD2GCONFG_base + 0x00)
#define REG_MD2GCONFIG_CG_SET0                   (MD2GCONFG_base + 0x10)
#define REG_MD2GCONFIG_CG_CLR0                   (MD2GCONFG_base + 0x20)
    #define MD2GCONFIG_CG_CON0_GCC               (1 <<  1)
    #define MD2GCONFIG_CG_CON0_IRDMA             (1 <<  6)
    #define MD2GCONFIG_CG_CON0_RXBUF             (1 <<  8)
    #define MD2GCONFIG_CG_CON0_TXBUF             (1 <<  9)
    #define MD2GCONFIG_CG_CON0_IRDBG             (1 << 13)
    #define MD2GCONFIG_CG_CON0_AHB2SDIO          (1 << 15)

#define REG_MD2GCONFIG_CG_CON2                   (MD2GCONFG_base + 0x08)
#define REG_MD2GCONFIG_CG_SET2                   (MD2GCONFG_base + 0x18)
#define REG_MD2GCONFIG_CG_CLR2                   (MD2GCONFG_base + 0x28)
    #define MD2GCONFIG_CG_CON2_APC_PRE           (1 <<  5)
    #define MD2GCONFIG_CG_CON2_VAFE              (1 <<  8)
    #define MD2GCONFIG_CG_CON2_BFE               (1 <<  9)

#define REG_MD2GCONFIG_CG_CON4                   (MD2GCONFG_base + 0x30)
#define REG_MD2GCONFIG_CG_SET4                   (MD2GCONFG_base + 0x34)
#define REG_MD2GCONFIG_CG_CLR4                   (MD2GCONFG_base + 0x38)
    #define MD2GCONFIG_CG_CON4_APC               (1 <<  5)

/* MD sys global */
#define DRVPDN_MD_PWR_GLOBAL_CON0                (CONFIG_base+0x0450)
#define DRVPDN_MD_PWR_GLOBAL_SET0                (CONFIG_base+0x0454)
#define DRVPDN_MD_PWR_GLOBAL_CLR0                (CONFIG_base+0x0458)
    #define MD_PWR_GLOBAL_CON0_DMA               (1  <<  0)
    #define MD_PWR_GLOBAL_CON0_BOOT_SLV          (1  <<  1)
    #define MD_PWR_GLOBAL_CON0_ABM               (1  <<  2)
    #define MD_PWR_GLOBAL_CON0_ADOE              (1  <<  3)
    #define MD_PWR_GLOBAL_CON0_UART              (1  <<  4)
    #define MD_PWR_GLOBAL_CON0_DBG               (1  <<  5)
    #define MD_PWR_GLOBAL_CON0_OSTIMER           (1  <<  6)
    #define MD_PWR_GLOBAL_CON0_GPT               (1  <<  7)
    #define MD_PWR_GLOBAL_CON0_TOPSM             (1  <<  8)
    #define MD_PWR_GLOBAL_CON0_SIM1              (1  << 10)
    #define MD_PWR_GLOBAL_CON0_SIM2              (1  << 11)
    #define MD_PWR_GLOBAL_CON0_ELM               (1  << 16)
    #define MD_PWR_GLOBAL_CON0_ALC               (1  << 17)
    #define MD_PWR_GLOBAL_CON0_PF_BUFF           (1  << 18)

#endif  /* !__PDN_HW_MT6752_MD2_SERIES_H__ */
