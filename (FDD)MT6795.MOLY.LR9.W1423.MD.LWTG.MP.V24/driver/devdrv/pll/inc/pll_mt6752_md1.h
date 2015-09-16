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
 *   pll_mt6752_md1.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   PLL Related Functions
 *
 * Author:
 * -------
 * -------
 *
 * ===========================================================================
 * $Log$
 *
 ****************************************************************************/

#ifndef __PLL_MT6752_MD1__
#define __PLL_MT6752_MD1__

#include "kal_general_types.h"
#include "reg_base.h"

/*****************************************************************************
 * Define exported function prototype
 ****************************************************************************/

/*****************************************************************************
 * Define HW register
 ****************************************************************************/
#define PLL_PLL_CON0                        (BASE_ADDR_PLL_MIXEDSYS+0x0020)
#define PLL_PLL_CON2_1                      (BASE_ADDR_PLL_MIXEDSYS+0x0024)
#define PLL_PLL_MTCMOS_CON0                 (BASE_ADDR_PLL_MIXEDSYS+0x0028)
#define PLL_MD_MDTOPSM_SW_CTL               (BASE_ADDR_PLL_MIXEDSYS+0x002C)
#define PLL_MD_LTEL1TOPSM_SW_CTL            (BASE_ADDR_PLL_MIXEDSYS+0x0030)
#define PLL_MD_MODEMTOPSM_SW_CTL            (BASE_ADDR_PLL_MIXEDSYS+0x0034)
#define PLL_MD_M2GTOPSM_SW_CTL              (BASE_ADDR_PLL_MIXEDSYS+0x0038)
#define PLL_MD_CR4PLL_DIV_CON               (BASE_ADDR_PLL_MIXEDSYS+0x003C)
#define PLL_MD_CR4PLL_DIV_CON1              (BASE_ADDR_PLL_MIXEDSYS+0x0040)
#define PLL_PLL_CON1                        (BASE_ADDR_PLL_MIXEDSYS+0x0044)
#define PLL_PLL_CON2                        (BASE_ADDR_PLL_MIXEDSYS+0x0048)
#define PLL_PLL_CON3                        (BASE_ADDR_PLL_MIXEDSYS+0x004C)
#define PLL_PLL_CON4                        (BASE_ADDR_PLL_MIXEDSYS+0x0050)
#define PLL_MD_SRCLKEN_CTL0                 (BASE_ADDR_PLL_MIXEDSYS+0x0054)
#define PLL_MD_SRCLKEN_CTL1                 (BASE_ADDR_PLL_MIXEDSYS+0x0058)
#define PLL_LTEMDPLL_TEST                   (BASE_ADDR_PLL_MIXEDSYS+0x005C)
#define PLL_CLKSW_CKSEL0                    (BASE_ADDR_PLL_MIXEDSYS+0x0060)
#define PLL_CLKSW_CKSEL1                    (BASE_ADDR_PLL_MIXEDSYS+0x0064)
#define PLL_CLKSW_CKSEL2                    (BASE_ADDR_PLL_MIXEDSYS+0x0068)
#define PLL_CLKSW_CKSEL3                    (BASE_ADDR_PLL_MIXEDSYS+0x006C)
#define PLL_CLKSW_FDIV0                     (BASE_ADDR_PLL_MIXEDSYS+0x0070)
#define PLL_CLKSW_FDIV1                     (BASE_ADDR_PLL_MIXEDSYS+0x0074)
#define PLL_CLKSW_FDIV2                     (BASE_ADDR_PLL_MIXEDSYS+0x0078)
#define PLL_CLKSW_FDIV3                     (BASE_ADDR_PLL_MIXEDSYS+0x007C)
#define PLL_CLKSW_FDIV4                     (BASE_ADDR_PLL_MIXEDSYS+0x0080)
#define PLL_CLKSW_FDIV5                     (BASE_ADDR_PLL_MIXEDSYS+0x0084)
#define PLL_CLKSW_FDIV6                     (BASE_ADDR_PLL_MIXEDSYS+0x0088)
#define PLL_CLKSW_FDIV7                     (BASE_ADDR_PLL_MIXEDSYS+0x008C)
#define PLL_CLKSW_CONN_CON0                 (BASE_ADDR_PLL_MIXEDSYS+0x0090)
#define PLL_CLKSW_CKSEL4                    (BASE_ADDR_PLL_MIXEDSYS+0x0094)
#define PLL_CLKSW_CKSEL5                    (BASE_ADDR_PLL_MIXEDSYS+0x0098)
#define PLL_CLKSW_CKSEL6                    (BASE_ADDR_PLL_MIXEDSYS+0x009C)
#define PLL_CLKSW_CKSEL7                    (BASE_ADDR_PLL_MIXEDSYS+0x00A0)
#define PLL_CLKSW_CKSEL8                    (BASE_ADDR_PLL_MIXEDSYS+0x00A4)
#define PLL_DFS_CON8_1                      (BASE_ADDR_PLL_MIXEDSYS+0x00A8)
#define PLL_DFS_CON7                        (BASE_ADDR_PLL_MIXEDSYS+0x00AC)
#define PLL_DFS_CON8                        (BASE_ADDR_PLL_MIXEDSYS+0x00B0)
#define PLL_DFS_CON9                        (BASE_ADDR_PLL_MIXEDSYS+0x00B4)
#define PLL_DPM_SEL_SW_CTL0                 (BASE_ADDR_PLL_MIXEDSYS+0x00B8)
#define PLL_DPM_SEL_SW_CTL1                 (BASE_ADDR_PLL_MIXEDSYS+0x00BC)
#define PLL_DPM_STB_TIME_CTRL0              (BASE_ADDR_PLL_MIXEDSYS+0x00C0)
#define PLL_MDPLL_CON0                      (BASE_ADDR_PLL_MIXEDSYS+0x0100)
#define PLL_MDPLL_CON1                      (BASE_ADDR_PLL_MIXEDSYS+0x0104)
#define PLL_MDPLL_CON2                      (BASE_ADDR_PLL_MIXEDSYS+0x0108)
#define PLL_MDPLL_CON3                      (BASE_ADDR_PLL_MIXEDSYS+0x010C)
#define PLL_MDPLL_CON4                      (BASE_ADDR_PLL_MIXEDSYS+0x0110)
#define PLL_TDPLL_CON0                      (BASE_ADDR_PLL_MIXEDSYS+0x0120)
#define PLL_TDPLL_CON1                      (BASE_ADDR_PLL_MIXEDSYS+0x0124)
#define PLL_TDPLL_CON2                      (BASE_ADDR_PLL_MIXEDSYS+0x0128)
#define PLL_TDPLL_CON3                      (BASE_ADDR_PLL_MIXEDSYS+0x012C)
#define PLL_TDPLL_CON4                      (BASE_ADDR_PLL_MIXEDSYS+0x0130)
#define PLL_MCUPLL_CON0                     (BASE_ADDR_PLL_MIXEDSYS+0x0140)
#define PLL_MCUPLL_CON1                     (BASE_ADDR_PLL_MIXEDSYS+0x0144)
#define PLL_MCUPLL_CON2                     (BASE_ADDR_PLL_MIXEDSYS+0x0148)
#define PLL_MCUPLL_CON3                     (BASE_ADDR_PLL_MIXEDSYS+0x014C)
#define PLL_ARM7PLL_CON0                    (BASE_ADDR_PLL_MIXEDSYS+0x0150)
#define PLL_ARM7PLL_CON1                    (BASE_ADDR_PLL_MIXEDSYS+0x0154)
#define PLL_ARM7PLL_CON2                    (BASE_ADDR_PLL_MIXEDSYS+0x0158)
#define PLL_ARM7PLL_CON3                    (BASE_ADDR_PLL_MIXEDSYS+0x015C)
#define PLL_WPLL_CON0                       (BASE_ADDR_PLL_MIXEDSYS+0x01C0)
#define PLL_WPLL_CON1                       (BASE_ADDR_PLL_MIXEDSYS+0x01C4)
#define PLL_WPLL_CON2                       (BASE_ADDR_PLL_MIXEDSYS+0x01C8)
#define PLL_WPLL_CON3                       (BASE_ADDR_PLL_MIXEDSYS+0x01CC)
#define PLL_OGTWPLL_CON0                    (BASE_ADDR_PLL_MIXEDSYS+0x01D0)
#define PLL_OGTWPLL_CON1                    (BASE_ADDR_PLL_MIXEDSYS+0x01D4)
#define PLL_OGTWPLL_CON2                    (BASE_ADDR_PLL_MIXEDSYS+0x01D8)
#define PLL_OGTWPLL_CON3                    (BASE_ADDR_PLL_MIXEDSYS+0x01DC)
#define PLL_CR4PLL2_CON0                    (BASE_ADDR_PLL_MIXEDSYS+0x01E0)
#define PLL_CR4PLL2_CON1                    (BASE_ADDR_PLL_MIXEDSYS+0x01E4)
#define PLL_CR4PLL2_CON2                    (BASE_ADDR_PLL_MIXEDSYS+0x01E8)
#define PLL_CR4PLL2_CON3                    (BASE_ADDR_PLL_MIXEDSYS+0x01EC)
#define PLL_CR4PLL2_CON4                    (BASE_ADDR_PLL_MIXEDSYS+0x01F0)
#define PLL_WHPLL_CON0                      (BASE_ADDR_PLL_MIXEDSYS+0x0200)
#define PLL_WHPLL_CON2                      (BASE_ADDR_PLL_MIXEDSYS+0x0208)
#define PLL_WHPLL_CON3                      (BASE_ADDR_PLL_MIXEDSYS+0x020C)
#define PLL_WHPLL_CON4                      (BASE_ADDR_PLL_MIXEDSYS+0x0210)
#define PLL_RSV_CON0                        (BASE_ADDR_PLL_MIXEDSYS+0x0360)
#define PLL_ABIST_FQMTR_CON0                (BASE_ADDR_PLL_MIXEDSYS+0x0400)
#define PLL_ABIST_FQMTR_CON1                (BASE_ADDR_PLL_MIXEDSYS+0x0404)
#define PLL_ABIST_FQMTR_CON2                (BASE_ADDR_PLL_MIXEDSYS+0x0408)
#define PLL_ABIST_FQMTR_DATA                (BASE_ADDR_PLL_MIXEDSYS+0x040C)
#define PLL_SYS_ABIST_MON_CON0              (BASE_ADDR_PLL_MIXEDSYS+0x0420)
#define PLL_SYS_ABIST_MON_CON1              (BASE_ADDR_PLL_MIXEDSYS+0x0424)
#define PLL_SYS_ABIST_MON_CON2              (BASE_ADDR_PLL_MIXEDSYS+0x0428)
#define PLL_ABIST_MON_DATA0                 (BASE_ADDR_PLL_MIXEDSYS+0x0440)
#define PLL_FH_CON0                         (BASE_ADDR_PLL_MIXEDSYS+0x0500)
#define PLL_FH_CON1                         (BASE_ADDR_PLL_MIXEDSYS+0x0504)
#define PLL_FH_CON2                         (BASE_ADDR_PLL_MIXEDSYS+0x0508)
#define PLL_FH_CON3                         (BASE_ADDR_PLL_MIXEDSYS+0x050C)
#define PLL_FH_CON4                         (BASE_ADDR_PLL_MIXEDSYS+0x0510)
#define PLL_FH_CON5                         (BASE_ADDR_PLL_MIXEDSYS+0x0514)
#define PLL_FH_CON6                         (BASE_ADDR_PLL_MIXEDSYS+0x0518)
#define PLL_FH_CON7                         (BASE_ADDR_PLL_MIXEDSYS+0x051C)
#define PLL_FH_CON9                         (BASE_ADDR_PLL_MIXEDSYS+0x0524)
#define PLL_FH_CON10                        (BASE_ADDR_PLL_MIXEDSYS+0x0528)
#define PLL_FH_CON11                        (BASE_ADDR_PLL_MIXEDSYS+0x052C)
#define PLL_FH_CON12                        (BASE_ADDR_PLL_MIXEDSYS+0x0530)
#define PLL_FH_CON13                        (BASE_ADDR_PLL_MIXEDSYS+0x0534)
#define PLL_FH_CON14                        (BASE_ADDR_PLL_MIXEDSYS+0x0538)
#define PLL_FH_CON15                        (BASE_ADDR_PLL_MIXEDSYS+0x053C)
#define PLL_FH_CON16                        (BASE_ADDR_PLL_MIXEDSYS+0x0540)
#define PLL_FH_CON17                        (BASE_ADDR_PLL_MIXEDSYS+0x0544)
#define PLL_FH_CON18                        (BASE_ADDR_PLL_MIXEDSYS+0x0548)
#define PLL_FH_CON19                        (BASE_ADDR_PLL_MIXEDSYS+0x054C)
#define PLL_FH_CON20                        (BASE_ADDR_PLL_MIXEDSYS+0x0550)
#define PLL_FH_CON21                        (BASE_ADDR_PLL_MIXEDSYS+0x0554)
#define PLL_FH_CON22                        (BASE_ADDR_PLL_MIXEDSYS+0x0558)
#define PLL_FH_CON23                        (BASE_ADDR_PLL_MIXEDSYS+0x055C)
#define PLL_FH_CON24                        (BASE_ADDR_PLL_MIXEDSYS+0x0560)
#define PLL_FH_CON25                        (BASE_ADDR_PLL_MIXEDSYS+0x0564)
#define PLL_FH_CON26                        (BASE_ADDR_PLL_MIXEDSYS+0x0568)
#define PLL_FH_CON27                        (BASE_ADDR_PLL_MIXEDSYS+0x056C)
#define PLL_FH_CON28                        (BASE_ADDR_PLL_MIXEDSYS+0x0570)
#define PLL_FH_CON29                        (BASE_ADDR_PLL_MIXEDSYS+0x0574)
#define PLL_FH_CON30                        (BASE_ADDR_PLL_MIXEDSYS+0x0578)
#define PLL_FH_CON31                        (BASE_ADDR_PLL_MIXEDSYS+0x057C)
#define PLL_FH_CON32                        (BASE_ADDR_PLL_MIXEDSYS+0x0580)
#define PLL_FH_CON8                         (BASE_ADDR_PLL_MIXEDSYS+0x0584)
#define PLL_FH_CON8_1                       (BASE_ADDR_PLL_MIXEDSYS+0x0588)
#define PLL_FH_CON_CR4PLL2                  (BASE_ADDR_PLL_MIXEDSYS+0x058C)
#define PLL_FH_CON_CR4PLL2_1                (BASE_ADDR_PLL_MIXEDSYS+0x0590)
#define PLL_FH_CON1_1                       (BASE_ADDR_PLL_MIXEDSYS+0x0594)
#define PLL_FH_CON_CR4PLL_SW_SEL            (BASE_ADDR_PLL_MIXEDSYS+0x0598)
#define PLL_PLL_DEBUG_CTL                   (BASE_ADDR_PLL_MIXEDSYS+0x059C)
#define PLL_PLLTD_CON0                      (BASE_ADDR_PLL_MIXEDSYS+0x0700)
#define PLL_PLLTD_CON1                      (BASE_ADDR_PLL_MIXEDSYS+0x0704)
#define PLL_PLLTD_CON2                      (BASE_ADDR_PLL_MIXEDSYS+0x0708)
#define PLL_PLLTD_CON3                      (BASE_ADDR_PLL_MIXEDSYS+0x070C)
#define PLL_PLLTD_CON4                      (BASE_ADDR_PLL_MIXEDSYS+0x0710)
#define PLL_PLLTD_CON5                      (BASE_ADDR_PLL_MIXEDSYS+0x0714)
#define PLL_PLLTD_CON6                      (BASE_ADDR_PLL_MIXEDSYS+0x0718)
#define PLL_PLLTD_CON7                      (BASE_ADDR_PLL_MIXEDSYS+0x071C)
#define PLL_PLLTD_CON8                      (BASE_ADDR_PLL_MIXEDSYS+0x0720)
#define PLL_PLL_RESERVE_REG                 (BASE_ADDR_PLL_MIXEDSYS+0x0800)

// Shall Be Internally Used, Or There Will be Multiple Definitions
#define PLL_MD_MCU_CON2                     (BASE_ADDR_MDCONFIG+0x108)
#define PLL_MD2EMI_ULTRA_HIGH_SET0          (BASE_ADDR_MDCONFIG+0x404)
#define PLL_MD2EMI_ULTRA_HIGH_SET1          (BASE_ADDR_MDCONFIG+0x414)
#define PLL_MD_GLOBAL_CLR0                  (BASE_ADDR_MDCONFIG+0x458)
#define PLL_MD_GLOBAL_CON1                  (BASE_ADDR_MDCONFIG+0x45C)
#define PLL_MD_DUAL_TALK                    (BASE_ADDR_MDCONFIG+0x604)

#define PLL_GDMA_FDCSR0                     (BASE_ADDR_MDGDMA+0x0010)
#define PLL_GDMA_FDCR0                      (BASE_ADDR_MDGDMA+0x0020)
#define PLL_GDMA_FDSAR0                     (BASE_ADDR_MDGDMA+0x0024)
#define PLL_GDMA_FDDAR0                     (BASE_ADDR_MDGDMA+0x0028)

#endif  /* !__PLL_MT6752_MD1__ */
