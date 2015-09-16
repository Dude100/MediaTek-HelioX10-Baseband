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
 *   dramc_hw_internal.h
 *
 * Project:
 * --------
 *   MT7208
 *
 * Description:
 * ------------
 *  This file implement the emi test case conditions
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
 * 1.add EMI/RAMC fine clock off feature
 * 2.update initial dram
 * 3.enable SSC with -8%
 *
 * removed!
 * removed!
 * 	Update DRAMC Setting for Power Saving about PADRGEN
 * 	Update EMI Setting for LMAC Underflow
 *
 * removed!
 * removed!
 * update dramc auto-k for FF corner IC
 * fix ssc features
 *
 * removed!
 * removed!
 * 1. add MR4 refresh rate update and derating ac timing
 * 2. add to set ap offset
 * 3. add dramc ssc
 *
 * removed!
 * removed!
 * 1. update mempll init 
 * a. multi-pll mode
 * b. mempll1
 * c. seal-ring mode
 * d. auto detection to  distinguish between MT6290 and MT6290M.
 * 2. update dram ac timing for tRPab
 *
 * removed!
 * removed!
 * 1.update auto-k for SIP-Pin MUX and fix some bugs
 * 2.update MDL content
 *
 * removed!
 * removed!
 * 1. add custom folder for MT6290M
 * 2. update custom_EMI.h and custom_EMI_release.h with emigen
 * 3. update custom_EMI_INFO.h with manual check in
 * 4. update cfggen
 *
 * removed!
 * removed!
 * Initial version of MT6290 bootloader.
 *
 * removed!
 * removed!
 * Initial version of MT6290 bootloader.
 *
 * removed!
 * removed!
 * Initial version of MT6290 bootloader.
 *
 * removed!
 * removed!
 * Initial version of MT6290 bootloader.
 *
 * removed!
 * removed!
 * Initial version of MT6290 bootloader.
 *
 * removed!
 * removed!
 * Initial version of MT6290 bootloader.
 ****************************************************************************/

#ifndef __DRAMC_HW_INTERNAL_H__
#define __DRAMC_HW_INTERNAL_H__

#include "reg_base.h"

/* Register Address Definition */
#define DRAMC_base              (BASE_ADDR_DRAMC)

#define DRAMC_ACTIM0            ((volatile UINT32P)(DRAMC_base+0x000U))
    #define DRAMC_ACTIM0_TRCD_MASK  (0xF << 28)
    #define DRAMC_ACTIM0_TRCD(n)    (((n) << 28)&DRAMC_ACTIM0_TRCD_MASK)
    #define DRAMC_ACTIM0_TRP_MASK   (0xF << 24)
    #define DRAMC_ACTIM0_TRP(n)     (((n) << 24)&DRAMC_ACTIM0_TRP_MASK)
    #define DRAMC_ACTIM0_TFAW_MASK  (0xF << 20)
    #define DRAMC_ACTIM0_TFAW(n)    (((n) << 20)&DRAMC_ACTIM0_TFAW_MASK)
    #define DRAMC_ACTIM0_TWR_MASK   (0xF << 16)
    #define DRAMC_ACTIM0_TWR(n)     (((n) << 16)&DRAMC_ACTIM0_TWR_MASK)
    #define DRAMC_ACTIM0_BL2        (1 << 15)
    #define DRAMC_ACTIM0_CL2        (1 << 12)
    #define DRAMC_ACTIM0_TWTR_MASK  (0xF << 8)
    #define DRAMC_ACTIM0_TWTR(n)    (((n) << 8)&DRAMC_ACTIM0_TWTR_MASK)
    #define DRAMC_ACTIM0_TRC_MASK   (0xF << 4)
    #define DRAMC_ACTIM0_TRC(n)     (((n) << 4)&DRAMC_ACTIM0_TRC_MASK)
    #define DRAMC_ACTIM0_TRAS_MASK  (0xF << 0)
    #define DRAMC_ACTIM0_TRAS(n)    (((n) << 0)&DRAMC_ACTIM0_TRAS_MASK)
#define DRAMC_CONF1         ((volatile UINT32P)(DRAMC_base+0x004U))
    #define DRAMC_CONF1_EN_2ND_MRR  (1 << 31)
    #define DRAMC_CONF1_TESTLP      (1 << 27)
    #define DRAMC_CONF1_SELFREF     (1 << 26)
    #define DRAMC_CONF1_TCMD_MASK   (0x7 << 20)
    #define DRAMC_CONF1_TCMD(n)     (((n) << 20)&DRAMC_CONF1_TCMD_MASK)
    #define DRAMC_CONF1_CKEON       (1U << 15)
    #define DRAMC_CONF1_FW2R        (1U << 13)
    #define DRAMC_CONF1_BL4         (1U << 10)
    #define DRAMC_CONF1_MATYPE_MASK (0x3 << 8)
    #define DRAMC_CONF1_MATYPE(n)   (((n) << 8) &DRAMC_CONF1_MATYPE_MASK)
    #define DRAMC_CONF1_TRRD_MASK   (0x3 << 6)
    #define DRAMC_CONF1_TRRD(n)     (((n) << 6)&DRAMC_CONF1_TRRD_MASK)
    #define DRAMC_CONF1_PAGDIS      (1 << 3)
    #define DRAMC_CONF1_DATMOD      (1U << 2)
    #define DRAMC_CONF1_DM64BITEN   (1U << 0)
#define DRAMC_CONF2         ((volatile UINT32P)(DRAMC_base+0x008U))
    #define DRAMC_CONF2_TEST2W          (1U << 31)
    #define DRAMC_CONF2_TEST2R          (1U << 30)
    #define DRAMC_CONF2_TEST1           (1U << 29)
    #define DRAMC_CONF2_REFTHD_MASK     (0x7 << 24)
    #define DRAMC_CONF2_REFTHD(n)       (((n) << 24)&DRAMC_CONF2_REFTHD_MASK)
    #define DRAMC_CONF2_REFCNT_MASK     (0xFF << 0)
    #define DRAMC_CONF2_REFCNT(n)       (((n) << 0)&DRAMC_CONF2_REFCNT_MASK)
#define DRAMC_PADCTL1       ((volatile UINT32P)(DRAMC_base+0x00CU))
    #define DRAMC_PADCTL1_CS1DLY_MASK       (0xf << 28)
    #define DRAMC_PADCTL1_CS1DLY(n)         (((n) << 28)&DRAMC_PADCTL1_CS1DLY_MASK)
    #define DRAMC_PADCTL1_CLKDLY_MASK       (0xf << 24)
    #define DRAMC_PADCTL1_CLKDLY(n)         (((n) << 24)&DRAMC_PADCTL1_CLKDLY_MASK)
#define DRAMC_PADCTL2       ((volatile UINT32P)(DRAMC_base+0x010U))
    #define DRAMC_PADCTL2_DQM3DLY_MASK      (0xf << 12)
    #define DRAMC_PADCTL2_DQM3DLY(n)        (((n) << 12)&DRAMC_PADCTL2_DQM3DLY_MASK)
    #define DRAMC_PADCTL2_DQM2DLY_MASK      (0xf << 8)
    #define DRAMC_PADCTL2_DQM2DLY(n)        (((n) << 8)&DRAMC_PADCTL2_DQM2DLY_MASK)
    #define DRAMC_PADCTL2_DQM1DLY_MASK      (0xf << 4)
    #define DRAMC_PADCTL2_DQM1DLY(n)        (((n) << 4)&DRAMC_PADCTL2_DQM1DLY_MASK)
    #define DRAMC_PADCTL2_DQM0DLY_MASK      (0xf << 0)
    #define DRAMC_PADCTL2_DQM0DLY(n)        (((n) << 0)&DRAMC_PADCTL2_DQM0DLY_MASK)
    #define DRAMC_PADCTL2_DQMiDLY(i, val)   (DRAMC_PADCTL2_DQM0DLY((val)) << (i << 2))
    #define DRAMC_PADCTL2_DQMDLY_MASK       DRAMC_PADCTL2_DQM0DLY_MASK
#define DRAMC_PADCTL3       ((volatile UINT32P)(DRAMC_base+0x014U))
    #define DRAMC_PADCTL3_DQS3DLY_MASK      (0xf << 12)
    #define DRAMC_PADCTL3_DQS3DLY(n)        (((n) << 12)&DRAMC_PADCTL3_DQS3DLY_MASK)
    #define DRAMC_PADCTL3_DQS2DLY_MASK      (0xf << 8)
    #define DRAMC_PADCTL3_DQS2DLY(n)        (((n) << 8)&DRAMC_PADCTL3_DQS2DLY_MASK)
    #define DRAMC_PADCTL3_DQS1DLY_MASK      (0xf << 4)
    #define DRAMC_PADCTL3_DQS1DLY(n)        (((n) << 4)&DRAMC_PADCTL3_DQS1DLY_MASK)
    #define DRAMC_PADCTL3_DQS0DLY_MASK      (0xf << 0)
    #define DRAMC_PADCTL3_DQS0DLY(n)        (((n) << 0)&DRAMC_PADCTL3_DQS0DLY_MASK)
    #define DRAMC_PADCTL3_DQSiDLY(i, val)   (DRAMC_PADCTL3_DQS0DLY((val)) << (i << 2))
    #define DRAMC_PADCTL3_DQSDLY_MASK       DRAMC_PADCTL3_DQS0DLY_MASK
#define DRAMC_R0DELDLY      ((volatile UINT32P)(DRAMC_base+0x018U)) 
    #define DRAMC_R0DELDLY_DEL3DLY_MASK     (0x7f << 24)
    #define DRAMC_R0DELDLY_DEL3DLY(n)       (((n) << 24)&DRAMC_R0DELDLY_DEL3DLY_MASK)
    #define DRAMC_R0DELDLY_DEL2DLY_MASK     (0x7f << 16)
    #define DRAMC_R0DELDLY_DEL2DLY(n)       (((n) << 16)&DRAMC_R0DELDLY_DEL2DLY_MASK)
    #define DRAMC_R0DELDLY_DEL1DLY_MASK     (0x7f << 8)
    #define DRAMC_R0DELDLY_DEL1DLY(n)       (((n) << 8)&DRAMC_R0DELDLY_DEL1DLY_MASK)
    #define DRAMC_R0DELDLY_DEL0DLY_MASK     (0x7f << 0)
    #define DRAMC_R0DELDLY_DEL0DLY(n)       (((n) << 0)&DRAMC_R0DELDLY_DEL0DLY_MASK)
#define DRAMC_R1DELDLY      ((volatile UINT32P)(DRAMC_base+0x01CU))
    #define DRAMC_R1DELDLY_DEL3DLY_MASK     (0x7f << 24)
    #define DRAMC_R1DELDLY_DEL3DLY(n)       (((n) << 24)&DRAMC_R1DELDLY_DEL3DLY_MASK)
    #define DRAMC_R1DELDLY_DEL2DLY_MASK     (0x7f << 16)
    #define DRAMC_R1DELDLY_DEL2DLY(n)       (((n) << 16)&DRAMC_R1DELDLY_DEL2DLY_MASK)
    #define DRAMC_R1DELDLY_DEL1DLY_MASK     (0x7f << 8)
    #define DRAMC_R1DELDLY_DEL1DLY(n)       (((n) << 8)&DRAMC_R1DELDLY_DEL1DLY_MASK)
    #define DRAMC_R1DELDLY_DEL0DLY_MASK     (0x7f << 0)
    #define DRAMC_R1DELDLY_DEL0DLY(n)       (((n) << 0)&DRAMC_R1DELDLY_DEL0DLY_MASK)
    #define DRAMC_RxDELDLY_DEL_MASK         (0x7f)
    #define DRAMC_RxDELDLY_DELiDLY(i, val)  (((val)&DRAMC_RxDELDLY_DEL_MASK)<<((i)<<3))
#define DRAMC_R0DIFDLY      ((volatile UINT32P)(DRAMC_base+0x020U))
    #define DRAMC_R0DIFDLY_DIF3DLY_MASK     (0x7f << 24)
    #define DRAMC_R0DIFDLY_DIF3DLY(n)       (((n) << 24)&DRAMC_R0DIFDLY_DIF3DLY_MASK)
    #define DRAMC_R0DIFDLY_DIF2DLY_MASK     (0x7f << 16)
    #define DRAMC_R0DIFDLY_DIF2DLY(n)       (((n) << 16)&DRAMC_R0DIFDLY_DIF2DLY_MASK)
    #define DRAMC_R0DIFDLY_DIF1DLY_MASK     (0x7f << 8)
    #define DRAMC_R0DIFDLY_DIF1DLY(n)       (((n) << 8)&DRAMC_R0DIFDLY_DIF1DLY_MASK)
    #define DRAMC_R0DIFDLY_DIF0DLY_MASK     (0x7f << 0)
    #define DRAMC_R0DIFDLY_DIF0DLY(n)       (((n) << 0)&DRAMC_R0DIFDLY_DIF0DLY_MASK)
#define DRAMC_R1DIFDLY      ((volatile UINT32P)(DRAMC_base+0x024U))
    #define DRAMC_R1DIFDLY_DIF3DLY_MASK     (0x7f << 24)
    #define DRAMC_R1DIFDLY_DIF3DLY(n)       (((n) << 24)&DRAMC_R1DIFDLY_DIF3DLY_MASK)
    #define DRAMC_R1DIFDLY_DIF2DLY_MASK     (0x7f << 16)
    #define DRAMC_R1DIFDLY_DIF2DLY(n)       (((n) << 16)&DRAMC_R1DIFDLY_DIF2DLY_MASK)
    #define DRAMC_R1DIFDLY_DIF1DLY_MASK     (0x7f << 8)
    #define DRAMC_R1DIFDLY_DIF1DLY(n)       (((n) << 8)&DRAMC_R1DIFDLY_DIF1DLY_MASK)
    #define DRAMC_R1DIFDLY_DIF0DLY_MASK     (0x7f << 0)
    #define DRAMC_R1DIFDLY_DIF0DLY(n)       (((n) << 0)&DRAMC_R1DIFDLY_DIF0DLY_MASK)
    #define DRAMC_RxDIFDLY_DIF_MASK         (0x7f)
    #define DRAMC_RxDIFDLY_DIFiDLY(i, val)  (((val)&DRAMC_RxDIFDLY_DIF_MASK)<<((i)<<3))
#define DRAMC_DLLCONF       ((volatile UINT32P)(DRAMC_base+0x028U))
    #define DRAMC_DLLCONF_DLLFRZ            (1U << 30)
    #define DRAMC_DLLCONF_MDQS              (1U << 28)
    #define DRAMC_DLLCONF_WCKSEL2           (1U << 21)
#define DRAMC_TESTMODE      ((volatile UINT32P)(DRAMC_base+0x02CU))
    #define DRAMC_TESTMODE_PAT0_MASK        (0xFF << 24)
    #define DRAMC_TESTMODE_PAT0(n)          (((n) << 24)&DRAMC_TESTMODE_PAT0_MASK)
#define DRAMC_TEST2_1       ((volatile UINT32P)(DRAMC_base+0x03CU))
    #define DRAMC_TEST2_1_PAT0_SHIFT        (24)
    #define DRAMC_TEST2_1_PAT0_MASK         (0xff << DRAMC_TEST2_1_PAT0_SHIFT)
    #define DRAMC_TEST2_1_PAT0(n)           (((n) << DRAMC_TEST2_1_PAT0_SHIFT)&DRAMC_TEST2_1_PAT0_MASK)
    #define DRAMC_TEST2_1_BASE_MASK         (0xffffff << 0)
    #define DRAMC_TEST2_1_BASE(n)           (((n) << 0)&DRAMC_TEST2_1_BASE_MASK)
#define DRAMC_TEST2_2       ((volatile UINT32P)(DRAMC_base+0x040U))
    #define DRAMC_TEST2_2_PAT1_SHIFT        (24)
    #define DRAMC_TEST2_2_PAT1_MASK         (0xff << DRAMC_TEST2_2_PAT1_SHIFT)
    #define DRAMC_TEST2_2_PAT1(n)           (((n) << DRAMC_TEST2_2_PAT1_SHIFT)&DRAMC_TEST2_2_PAT1_MASK)
    #define DRAMC_TEST2_2_OFFSET_MASK       (0xffffff << 0)
    #define DRAMC_TEST2_2_OFFSET(n)         (((n) << 0)&DRAMC_TEST2_2_OFFSET_MASK)
#define DRAMC_TEST2_3       ((volatile UINT32P)(DRAMC_base+0x044U))
    #define DRAMC_TEST2_3_ADVPREEN          (1U << 31)
    #define DRAMC_TEST2_3_ADVREFEN          (1U << 30)
    #define DRAMC_TEST2_3_DMPGTIM_MASK      (0x3F << 24)
    #define DRAMC_TEST2_3_DMPGTIM(n)        (((n) << 24)&DRAMC_TEST2_3_DMPGTIM_MASK)
    #define DRAMC_TEST2_3_TRFC_BIT3_0_MASK  (0xF << 16)
    #define DRAMC_TEST2_3_TRFC_BIT3_0(n)    (((n) << 16)&DRAMC_TEST2_3_TRFC_BIT3_0_MASK)
    #define DRAMC_TEST2_3_PREBIT            (1U << 15)
    #define DRAMC_TEST2_3_DQSUPDMODE        (1U << 14)
    #define DRAMC_TEST2_3_MANUDQSUPD        (1U << 13)
    #define DRAMC_TEST2_3_MANUDLLFRZ        (1U << 12)
    #define DRAMC_TEST2_3_DQDLYAUTO         (1U << 11)
    #define DRAMC_TEST2_3_DQSICALSTP_MASK   (0x7 << 8)
    #define DRAMC_TEST2_3_DQSICALSTP(n)     (((n) << 8)&DRAMC_TEST2_3_DQSICALSTP_MASK)
    #define DRAMC_TEST2_3_TESTAUDPAT        (1U << 7)
    #define DRAMC_TEST2_3_DQSICALUPD        (1U << 5)
    #define DRAMC_TEST2_3_DQSICALEN         (1U << 4)
    #define DRAMC_TEST2_3_TESTCNT_MASK      (0xF << 0)
    #define DRAMC_TEST2_3_TESTCNT(n)        (((n) << 0)&DRAMC_TEST2_3_TESTCNT_MASK)
#define DRAMC_TEST2_4       ((volatile UINT32P)(DRAMC_base+0x048U))
#define DRAMC_DDR2CTL       ((volatile UINT32P)(DRAMC_base+0x07CU))
    #define DRAMC_DDR2CTL_RODTE             (1U << 31)
    #define DRAMC_DDR2CTL_WLAT_MASK         (0x7 << 28)
    #define DRAMC_DDR2CTL_WLAT(n)           (((n) << 28)&DRAMC_DDR2CTL_WLAT_MASK)
    #define DRAMC_DDR2CTL_FIXRODT           (1U << 27)
    #define DRAMC_DDR2CTL_TWODT_MASK        (0x7f << 16)
    #define DRAMC_DDR2CTL_TWODT(n)          (((n) << 16)&DRAMC_DDR2CTL_TWODT_MASK)
    #define DRAMC_DDR2CTL_TR2W_MASK         (0xF << 12)
    #define DRAMC_DDR2CTL_TR2W(n)           (((n) << 12)&DRAMC_DDR2CTL_TR2W_MASK)
    #define DRAMC_DDR2CTL_TRTP_MASK         (0x7 << 8)
    #define DRAMC_DDR2CTL_TRTP(n)           (((n) << 8)&DRAMC_DDR2CTL_TRTP_MASK)
    #define DRAMC_DDR2CTL_EROT              (1U << 7)
    #define DRAMC_DDR2CTL_DATLAT_MASK       (0x7 << 4)
    #define DRAMC_DDR2CTL_DATLAT(n)         (((n) << 4)&DRAMC_DDR2CTL_DATLAT_MASK)
    #define DRAMC_DDR2CTL_WOEN              (1U << 3)
    #define DRAMC_DDR2CTL_ROEN              (1U << 2)
    #define DRAMC_DDR2CTL_DDREN             (1U << 1)
    #define DRAMC_DDR2CTL_FDIV2             (1U << 0)
#define DRAMC_MRS           ((volatile UINT32P)(DRAMC_base+0x088U))
    #define DRAMC_MRS_OP_MASK               (0xFF << 16)
    #define DRAMC_MRS_OP(n)                 (((n) << 16)&DRAMC_MRS_OP_MASK)
    #define DRAMC_MRS_BA_MASK               (0x7 << 13)
    #define DRAMC_MRS_BA(n)                 (((n) << 13)&DRAMC_MRS_BA_MASK)
    #define DRAMC_MRS_MA_MASK               (0x1FFF << 0)
    #define DRAMC_MRS_MA(n)                 (((n) << 0)&DRAMC_MRS_MA_MASK)
#define DRAMC_CLK1DELAY ((volatile UINT32P)(DRAMC_base+0x08CU))
    #define DRAMC_CLK1DELAY_CLK1DLY_MASK    (0xF << 16)
    #define DRAMC_CLK1DELAY_CLK1DLY(n)      (((n) << 16)&(DRAMC_CLK1DELAY_CLK1DLY_MASK))
#define DRAMC_IOCTL         ((volatile UINT32P)(DRAMC_base+0x090U))
#define DRAMC_R0DQSIEN      ((volatile UINT32P)(DRAMC_base+0x094U))
    #define DRAMC_RxDQSIEN_DQS3IEN_MASK     (0x7f << 24)
    #define DRAMC_RxDQSIEN_DQS3IEN(n)       (((n) << 24)&(DRAMC_RxDQSIEN_DQS3IEN_MASK))
    #define DRAMC_RxDQSIEN_DQS2IEN_MASK     (0x7f << 16)
    #define DRAMC_RxDQSIEN_DQS2IEN(n)       (((n) << 16)&(DRAMC_RxDQSIEN_DQS2IEN_MASK))
    #define DRAMC_RxDQSIEN_DQS1IEN_MASK     (0x7f << 8)
    #define DRAMC_RxDQSIEN_DQS1IEN(n)       (((n) << 8)&(DRAMC_RxDQSIEN_DQS1IEN_MASK))
    #define DRAMC_RxDQSIEN_DQS0IEN_MASK     (0x7f << 0)
    #define DRAMC_RxDQSIEN_DQS0IEN(n)       (((n) << 0)&(DRAMC_RxDQSIEN_DQS0IEN_MASK))
    #define DRAMC_RxDQSIEN_DQSiIEN(i, v)    (((v)&DRAMC_RxDQSIEN_DQS0IEN_MASK)<<((i)<<3))
#define DRAMC_R1DQSIEN      ((volatile UINT32P)(DRAMC_base+0x098U))
#define DRAMC_DRVCTL0       ((volatile UINT32P)(DRAMC_base+0x0B8U))
    #define DRAMC_DRVCTL0_DQSDRVP_MASK      (0xF << 28)
    #define DRAMC_DRVCTL0_DQSDRVP(n)        (((n) << 28)&DRAMC_DRVCTL0_DQSDRVP_MASK)
    #define DRAMC_DRVCTL0_DQSDRVN_MASK      (0xF << 24)
    #define DRAMC_DRVCTL0_DQSDRVN(n)        (((n) << 24)&DRAMC_DRVCTL0_DQSDRVN_MASK)
    #define DRAMC_DRVCTL0_DQSRTTBPJ         (1 << 23)
    #define DRAMC_DRVCTL0_DSODTP_MASK       (0x7 << 20)
    #define DRAMC_DRVCTL0_DSODTP(n)         (((n) << 20)&DRAMC_DRVCTL0_DSODTP_MASK)
    #define DRAMC_DRVCTL0_DQSRTTBNJ         (1 << 19)
    #define DRAMC_DRVCTL0_DSODTN_MASK       (0x7 << 16)
    #define DRAMC_DRVCTL0_DSODTN(n)         (((n) << 16)&DRAMC_DRVCTL0_DSODTN_MASK)
    #define DRAMC_DRVCTL0_DQDRVP_MASK       (0xF << 12)
    #define DRAMC_DRVCTL0_DQDRVP(n)         (((n) << 12)&DRAMC_DRVCTL0_DQDRVP_MASK)
    #define DRAMC_DRVCTL0_DQDRVN_MASK       (0xF << 8)
    #define DRAMC_DRVCTL0_DQDRVN(n)         (((n) << 8)&DRAMC_DRVCTL0_DQDRVN_MASK)
    #define DRAMC_DRVCTL0_DQRTTBPJ          (1 << 7)
    #define DRAMC_DRVCTL0_DQODTP_MASK       (0x7 << 4)
    #define DRAMC_DRVCTL0_DQODTP(n)         (((n) << 4)&DRAMC_DRVCTL0_DQODTP_MASK)
    #define DRAMC_DRVCTL0_DQRTTBNJ          (1 << 3)
    #define DRAMC_DRVCTL0_DQODTN_MASK       (0x7 << 0)
    #define DRAMC_DRVCTL0_DQODTN(n)         (((n) << 0)&DRAMC_DRVCTL0_DQODTN_MASK)
#define DRAMC_DRVCTL1       ((volatile UINT32P)(DRAMC_base+0x0BCU))
    #define DRAMC_DRVCTL1_CLKDRVP_MASK      (0xF << 28)
    #define DRAMC_DRVCTL1_CLKDRVP(n)        (((n) << 28)&DRAMC_DRVCTL1_CLKDRVP_MASK)
    #define DRAMC_DRVCTL1_CLKDRVN_MASK      (0xF << 24)
    #define DRAMC_DRVCTL1_CLKDRVN(n)        (((n) << 24)&DRAMC_DRVCTL1_CLKDRVN_MASK)
    #define DRAMC_DRVCTL1_CLKRTTBPJ         (1 << 23)
    #define DRAMC_DRVCTL1_CKODTP_MASK       (0x7 << 20)
    #define DRAMC_DRVCTL1_CKODTP(n)         (((n) << 20)&DRAMC_DRVCTL1_CKODTP_MASK)
    #define DRAMC_DRVCTL1_CLKRTTBNJ         (1 << 19)
    #define DRAMC_DRVCTL1_CKODTN_MASK       (0x7 << 16)
    #define DRAMC_DRVCTL1_CKODTN(n)         (((n) << 16)&DRAMC_DRVCTL1_CKODTN_MASK)
    #define DRAMC_DRVCTL1_CMDDRVP_MASK      (0xF << 12)
    #define DRAMC_DRVCTL1_CMDDRVP(n)        (((n) << 12)&DRAMC_DRVCTL1_CMDDRVP_MASK)
    #define DRAMC_DRVCTL1_CMDDRVN_MASK      (0xF << 8)
    #define DRAMC_DRVCTL1_CMDDRVN(n)        (((n) << 8)&DRAMC_DRVCTL1_CMDDRVN_MASK)
#define DRAMC_DLLSEL        ((volatile UINT32P)(DRAMC_base+0x0C0U))
#define DRAMC_TDSEL0        ((volatile UINT32P)(DRAMC_base+0x0CCU))
#define DRAMC_TDSEL1        ((volatile UINT32P)(DRAMC_base+0x0D0U))
#define DRAMC_MCKDLY        ((volatile UINT32P)(DRAMC_base+0x0D8U))
    #define DRAMC_MCKDLY_PINMUX_MASK        (0x3 << 30)
    #define DRAMC_MCKDLY_PINMUX(n)          (((n) << 30)&DRAMC_MCKDLY_PINMUX_MASK)
    #define DRAMC_MCKDLY_16BITFULL          (1U << 28)
    #define DRAMC_MCKDLY_ODTREN             (1 << 22)
    #define DRAMC_MCKDLY_DISDQIEN_MASK      (0xf << 16)
    #define DRAMC_MCKDLY_DISDQIEN(n)        (((n) << 16)&DRAMC_MCKDLY_DISDQIEN_MASK)
    #define DRAMC_MCKDLY_FIXDQIEN_MASK      (0xf << 12)
    #define DRAMC_MCKDLY_FIXDQIEN(n)        (((n) << 12)&DRAMC_MCKDLY_FIXDQIEN_MASK)
#define DRAMC_DQSCTL0       ((volatile UINT32P)(DRAMC_base+0x0DCU))
#define DRAMC_DQSCTL1       ((volatile UINT32P)(DRAMC_base+0x0E0U))
    #define DRAMC_DQSCTL1_DQSIENMODE        (1 << 28)
    #define DRAMC_DQSCTL1_DQSINCTL_MASK     (0x7 << 24)
    #define DRAMC_DQSCTL1_DQSINCTL(n)       (((n) << 24)&DRAMC_DQSCTL1_DQSINCTL_MASK)
#define DRAMC_PADCTL4       ((volatile UINT32P)(DRAMC_base+0x0E4U))
    #define DRAMC_PADCTL4_DATLAT3           (1U << 4)
    #define DRAMC_PADCTL4_CKEFIXOFF         (1U << 3)
    #define DRAMC_PADCTL4_CKEFIXON          (1U << 2)
#define DRAMC_PADCTL5       ((volatile UINT32P)(DRAMC_base+0x0E8U))
#define DRAMC_PADCTL6       ((volatile UINT32P)(DRAMC_base+0x0ECU))
#define DRAMC_PHYCTL1       ((volatile UINT32P)(DRAMC_base+0x0F0U))
    #define DRAMC_PHYCTL1_DQ4BMUX           (1U << 31)
    #define DRAMC_PHYCTL1_CMDPHY0RST        (1U << 29)
    #define DRAMC_PHYCTL1_PHYRST            (1U << 28)
    #define DRAMC_PHYCTL1_MACRO1RST         (1U << 27)
    #define DRAMC_PHYCTL1_MACRO0RST         (1U << 26)
    #define DRAMC_PHYCTL1_CMDPHY1RST        (1U << 25)
    #define DRAMC_PHYCTL1_FIXDQSIEN         (1U << 24)
#define DRAMC_GDDR3CTL1     ((volatile UINT32P)(DRAMC_base+0x0F4U))
    #define DRAMC_GDDR3CTL1_SIP16DQMUX      (1U << 31)
    #define DRAMC_GDDR3CTL1_PHYSYNCM        (1U << 28)
    #define DRAMC_GDDR3CTL1_RDATRST         (1U << 25)
    #define DRAMC_GDDR3CTL1_8BKEN           (1U << 24)
#define DRAMC_PADCTL7       ((volatile UINT32P)(DRAMC_base+0x0F8U))
#define DRAMC_MISCTL0       ((volatile UINT32P)(DRAMC_base+0x0FCU))
    #define DRAMC_MISCTL0_TXP_MASK          (7 << 28)
    #define DRAMC_MISCTL0_TXP(n)            (((n) << 28) & DRAMC_MISCTL0_TXP_MASK)
    #define DRAMC_MISCTL0_REFP_ARB_EN       (1 << 26)
    #define DRAMC_MISCTL0_REFA_ARB_EN       (1 << 25)
    #define DRAMC_MISCTL0_PBC_ARB_EN        (1 << 24)
    #define DRAMC_MISCTL0_ASYNCEN           (1 << 20)
    #define DRAMC_MISCTL0_INTLBT            (1 << 17)
    #define DRAMC_MISCTL0_MODE18V           (1 << 16)
#define DRAMC_OCDK          ((volatile UINT32P)(DRAMC_base+0x100U))
    #define DRAMC_OCDK_KEY_MASK             (0xCCCC0000)
    #define DRAMC_OCDK_KEY(n)       \
        ((((((n)>>0)&0x3)<<18) | ((((n)>>2)&0x3)<<22) | ((((n)>>4)&0x3)<<26) | ((((n)>>6)&0x3)<<30))&DRAMC_OCDK_KEY_MASK)
    #define DRAMC_OCDK_WDATITLV (1U<<28)
#define DRAMC_LBWDAT0       ((volatile UINT32P)(DRAMC_base+0x104U))
#define DRAMC_LBWDAT1       ((volatile UINT32P)(DRAMC_base+0x108U))
#define DRAMC_LBWDAT2       ((volatile UINT32P)(DRAMC_base+0x10CU))
#define DRAMC_RKCFG         ((volatile UINT32P)(DRAMC_base+0x110U))
    #define DRAMC_RKCFG_XRTW2W_SHIFT        (18)
    #define DRAMC_RKCFG_XRTW2W_MASK         (0x3 << DRAMC_RKCFG_XRTW2W_SHIFT)
    #define DRAMC_RKCFG_XRTW2W(n)           (((n)<<DRAMC_RKCFG_XRTW2W_SHIFT)&DRAMC_RKCFG_XRTW2W_MASK)
    #define DRAMC_RKCFG_XRTW2R_SHIFT        (16)
    #define DRAMC_RKCFG_XRTW2R_MASK         (0x3 << DRAMC_RKCFG_XRTW2R_SHIFT)
    #define DRAMC_RKCFG_XRTW2R(n)           (((n)<<DRAMC_RKCFG_XRTW2R_SHIFT)&DRAMC_RKCFG_XRTW2R_MASK)
    #define DRAMC_RKCFG_XRTR2W_SHIFT        (12)
    #define DRAMC_RKCFG_XRTR2W_MASK         (0x7 << DRAMC_RKCFG_XRTR2W_SHIFT)
    #define DRAMC_RKCFG_XRTR2W(n)           (((n)<<DRAMC_RKCFG_XRTR2W_SHIFT)&DRAMC_RKCFG_XRTR2W_MASK)
    #define DRAMC_RKCFG_XRTR2R_SHIFT        (8)
    #define DRAMC_RKCFG_XRTR2R_MASK         (0x7 << DRAMC_RKCFG_XRTR2R_SHIFT)
    #define DRAMC_RKCFG_XRTR2R(n)           (((n)<<DRAMC_RKCFG_XRTR2R_SHIFT)&DRAMC_RKCFG_XRTR2R_MASK)
    #define DRAMC_RKCFG_PBREFEN             (1 << 7)
    #define DRAMC_RKCFG_MRS2RK              (1 << 4)
    #define DRAMC_RKCFG_RKSWAP              (1 << 3)
    #define DRAMC_RKCFG_RKMODE_MASK         (0x7 << 0)
    #define DRAMC_RKCFG_RKMODE(n)           (((n) << 0) & DRAMC_RKCFG_RKMODE_MASK)
#define DRAMC_CKPHDET       ((volatile UINT32P)(DRAMC_base+0x114U))
#define DRAMC_DQSGCTL       ((volatile UINT32P)(DRAMC_base+0x124U))
    #define DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANK1_COM1_MASK         (0x3 << 6)
    #define DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANK1_COM1(n)           (((n)<< 6)&DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANK1_COM1_MASK)
    #define DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANK0_COM1_MASK         (0x3 << 4)
    #define DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANK0_COM1(n)           (((n)<< 4)&DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANK0_COM1_MASK)
    #define DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANK1_COM0_MASK         (0x3 << 2)
    #define DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANK1_COM0(n)           (((n)<< 2)&DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANK1_COM0_MASK)
    #define DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANK0_COM0_MASK         (0x3 << 0)
    #define DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANK0_COM0(n)           (((n)<< 0)&DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANK0_COM0_MASK)
    #define DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANKn_COMi(n, i, v)     (((v)&DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANK0_COM0_MASK) << (((n)<<1)+((i)<<2)))
#define DRAMC_CLKENCTL      ((volatile UINT32P)(DRAMC_base+0x130U))
    #define DRAMC_CLKENCTL_CLK1EN       (1U << 29)
    #define DRAMC_CLKENCTL_CLK0EN       (1U << 28)
#define DRAMC_DQSGCTL1      ((volatile UINT32P)(DRAMC_base+0x140U))
#define DRAMC_DQSGCTL2      ((volatile UINT32P)(DRAMC_base+0x144U))
#define DRAMC_DQSI_SEL      ((volatile UINT32P)(DRAMC_base+0x158U))
#define DRAMC_ARBCTL0       ((volatile UINT32P)(DRAMC_base+0x168U))
#define DRAMC_CMDDLY0       ((volatile UINT32P)(DRAMC_base+0x1A8U))
    #define DRAMC_CMDDLY_RA3DLY_MASK        (0x1F << 24)
    #define DRAMC_CMDDLY_RA3DLY(n)          (((n) << 24)&DRAMC_CMDDLY_RA3DLY_MASK)
    #define DRAMC_CMDDLY_RA2DLY_MASK        (0x1F << 16)
    #define DRAMC_CMDDLY_RA2DLY(n)          (((n) << 16)&DRAMC_CMDDLY_RA2DLY_MASK)
    #define DRAMC_CMDDLY_RA1DLY_MASK        (0x1F << 8)
    #define DRAMC_CMDDLY_RA1DLY(n)          (((n) << 8)&DRAMC_CMDDLY_RA1DLY_MASK)
    #define DRAMC_CMDDLY_RA0DLY_MASK        (0x1F << 0)
    #define DRAMC_CMDDLY_RA0DLY(n)          (((n) << 0)&DRAMC_CMDDLY_RA0DLY_MASK)
#define DRAMC_CMDDLY1       ((volatile UINT32P)(DRAMC_base+0x1ACU))
    #define DRAMC_CMDDLY_RA7DLY_MASK        (0x1F << 24)
    #define DRAMC_CMDDLY_RA7DLY(n)          (((n) << 24)&DRAMC_CMDDLY_RA7DLY_MASK)
    #define DRAMC_CMDDLY_RA6DLY_MASK        (0x1F << 16)
    #define DRAMC_CMDDLY_RA6DLY(n)          (((n) << 16)&DRAMC_CMDDLY_RA6DLY_MASK)
    #define DRAMC_CMDDLY_RA5DLY_MASK        (0x1F << 8)
    #define DRAMC_CMDDLY_RA5DLY(n)          (((n) << 8)&DRAMC_CMDDLY_RA5DLY_MASK)
    #define DRAMC_CMDDLY_RA4DLY_MASK        (0x1F << 0)
    #define DRAMC_CMDDLY_RA4DLY(n)          (((n) << 0)&DRAMC_CMDDLY_RA4DLY_MASK)
#define DRAMC_CMDDLY2       ((volatile UINT32P)(DRAMC_base+0x1B0U))
    #define DRAMC_CMDDLY_RA11DLY_MASK       (0x1F << 24)
    #define DRAMC_CMDDLY_RA11DLY(n)         (((n) << 24)&DRAMC_CMDDLY_RA11DLY_MASK)
    #define DRAMC_CMDDLY_RA10DLY_MASK       (0x1F << 16)
    #define DRAMC_CMDDLY_RA10DLY(n)         (((n) << 16)&DRAMC_CMDDLY_RA10DLY_MASK)
    #define DRAMC_CMDDLY_RA9DLY_MASK        (0x1F << 8)
    #define DRAMC_CMDDLY_RA9DLY(n)          (((n) << 8)&DRAMC_CMDDLY_RA9DLY_MASK)
    #define DRAMC_CMDDLY_RA8DLY_MASK        (0x1F << 0)
    #define DRAMC_CMDDLY_RA8DLY(n)          (((n) << 0)&DRAMC_CMDDLY_RA8DLY_MASK)
#define DRAMC_CMDDLY3       ((volatile UINT32P)(DRAMC_base+0x1B4U))
    #define DRAMC_CMDDLY_BA2DLY_MASK        (0x1F << 24)
    #define DRAMC_CMDDLY_BA2DLY(n)          (((n) << 24)&DRAMC_CMDDLY_BA2DLY_MASK)
    #define DRAMC_CMDDLY_BA1DLY_MASK        (0x1F << 16)
    #define DRAMC_CMDDLY_BA1DLY(n)          (((n) << 16)&DRAMC_CMDDLY_BA1DLY_MASK)
    #define DRAMC_CMDDLY_BA0DLY_MASK        (0x1F << 8)
    #define DRAMC_CMDDLY_BA0DLY(n)          (((n) << 8)&DRAMC_CMDDLY_BA0DLY_MASK)
    #define DRAMC_CMDDLY_RA12DLY_MASK       (0x1F << 0)
    #define DRAMC_CMDDLY_RA12DLY(n)         (((n) << 0)&DRAMC_CMDDLY_RA12DLY_MASK)
#define DRAMC_CMDDLY4       ((volatile UINT32P)(DRAMC_base+0x1B8U))
    #define DRAMC_CMDDLY_CASDLY_MASK        (0x1F << 24)
    #define DRAMC_CMDDLY_CASDLY(n)          (((n) << 24)&DRAMC_CMDDLY_CASDLY_MASK)
    #define DRAMC_CMDDLY_RASDLY_MASK        (0x1F << 16)
    #define DRAMC_CMDDLY_RASDLY(n)          (((n) << 16)&DRAMC_CMDDLY_RASDLY_MASK)
    #define DRAMC_CMDDLY_CKEDLY_MASK        (0x1F << 8)
    #define DRAMC_CMDDLY_CKEDLY(n)          (((n) << 8)&DRAMC_CMDDLY_CKEDLY_MASK)
    #define DRAMC_CMDDLY_CSDLY_MASK         (0x1F << 0)
    #define DRAMC_CMDDLY_CSDLY(n)           (((n) << 0)&DRAMC_CMDDLY_CSDLY_MASK)
#define DRAMC_CMDDLY5       ((volatile UINT32P)(DRAMC_base+0x1BCU))
    #define DRAMC_CMDDLY_ODTDLY_MASK        (0x1F << 24)
    #define DRAMC_CMDDLY_ODTDLY(n)          (((n) << 24)&DRAMC_CMDDLY_ODTDLY_MASK)
    #define DRAMC_CMDDLY_RA13DLY_MASK       (0x1F << 16)
    #define DRAMC_CMDDLY_RA13DLY(n)         (((n) << 16)&DRAMC_CMDDLY_RA13DLY_MASK)
    #define DRAMC_CMDDLY_WEDLY_MASK         (0x1F << 8)
    #define DRAMC_CMDDLY_WEDLY(n)           (((n) << 8)&DRAMC_CMDDLY_WEDLY_MASK)
    #define DRAMC_CMDDLY_RESETDLY_MASK      (0x1F << 0)
    #define DRAMC_CMDDLY_RESETDLY(n)        (((n) << 0)&DRAMC_CMDDLY_RESETDLY_MASK)
#define DRAMC_DQSCAL0       ((volatile UINT32P)(DRAMC_base+0x1C0U))
    #define DRAMC_CMDDLY_RA14DLY_MASK       (0x1F << 24)
    #define DRAMC_CMDDLY_RA14DLY(n)         (((n) << 24)&DRAMC_CMDDLY_RA14DLY_MASK)
    #define DRAMC_CMDDLY_RA15DLY_MASK       (0x1F << 16)
    #define DRAMC_CMDDLY_RA15DLY(n)         (((n) << 16)&DRAMC_CMDDLY_RA15DLY_MASK)
    /* This macro is for DRAMC_CMDDLYx */
    #define DRAMC_CMDDLY(choice, val)       DRAMC_CMDDLY_##choice((val))
    #define DRAMC_CMMDLY_MASK               (0x1F)
#define DRAMC_DQSCAL1       ((volatile UINT32P)(DRAMC_base+0x1C4U))
#define DRAMC_DMMONITOR     ((volatile UINT32P)(DRAMC_base+0x1D8U))
    #define DRAMC_DMMONITOR_BUSMONEN_SW (1 << 3)
    #define DRAMC_DMMONITOR_MONPAUSE_SW (1 << 2)
#define DRAMC_PD_CTRL       ((volatile UINT32P)(DRAMC_base+0x1DCU))
    #define DRAMC_PD_CTRL_MIOCKCTRLOFF      (1 << 26)
    #define DRAMC_PD_CTRL_DCMEN             (1 << 25)
    #define DRAMC_PD_CTRL_REFFRERUN         (1 << 24)
    #define DRAMC_PD_CTRL_TXSR_MASK         (0xFF << 8)
    #define DRAMC_PD_CTRL_TXSR(n)           (((n) << 8) & DRAMC_PD_CTRL_TXSR_MASK)
    #define DRAMC_PD_CTRL_DCMDLYREF_MASK    (0x7 << 4)
    #define DRAMC_PD_CTRL_DCMDLYREF(n)      (((n) << 4) & DRAMC_PD_CTRL_DCMDLYREF_MASK)
#define DRAMC_LPDDR2        ((volatile UINT32P)(DRAMC_base+0x1E0U))
    #define DRAMC_LPDDR2_EN             (1 << 28)
#define DRAMC_SPCMD         ((volatile UINT32P)(DRAMC_base+0x1E4U))
    #define DRAMC_SPCMD_ZQCSCNT_MASK    (0xFF << 16)
    #define DRAMC_SPCMD_ZQCSCNT(n)      (((n) << 16) & DRAMC_SPCMD_ZQCSCNT_MASK)
    #define DRAMC_SPCMD_IORGCNTRST      (1 << 14)
    #define DRAMC_SPCMD_PADRGEN         (1 << 13)
    #define DRAMC_SPCMD_IORGCNTEN       (1 << 12)
    #define DRAMC_SPCMD_DQSGCNTRST      (1 << 9)
    #define DRAMC_SPCMD_DQSGCNTEN       (1 << 8)
    #define DRAMC_SPCMD_TCMDEN          (1 << 5)
    #define DRAMC_SPCMD_ZQCEN           (1 << 4)
    #define DRAMC_SPCMD_AREFEN          (1 << 3)
    #define DRAMC_SPCMD_PREAEN          (1 << 2)
    #define DRAMC_SPCMD_MRREN           (1 << 1)
    #define DRAMC_SPCMD_MRWEN           (1 << 0)
#define DRAMC_ACTIM1        ((volatile UINT32P)(DRAMC_base+0x1E8U))
    #define DRAMC_ACTIM1_TRPAB_MASK         (0x3 << 24)
    #define DRAMC_ACTIM1_TRPAB(n)           (((n) << 24) & DRAMC_ACTIM1_TRPAB_MASK)
    #define DRAMC_ACTIM1_REFRCNT_MASK       (0xff << 16)
    #define DRAMC_ACTIM1_REFRCNT(n)         (((n) << 16) & DRAMC_ACTIM1_REFRCNT_MASK)
    #define DRAMC_ACTIM1_TRFCPB_MASK        (0xFF << 8)
    #define DRAMC_ACTIM1_TRFCPB(n)          (((n) << 8) & DRAMC_ACTIM1_TRFCPB_MASK)
    #define DRAMC_ACTIM1_TRFC_BIT7_4_MASK   (0xF << 4)
    #define DRAMC_ACTIM1_TRFC_BIT7_4(n)     (((n) << 4) & DRAMC_ACTIM1_TRFC_BIT7_4_MASK)
    #define DRAMC_ACTIM1_TRRD2              (1 << 3)
    #define DRAMC_ACTIM1_TFAW_BIT4          (1 << 1)
    #define DRAMC_ACTIM1_TRC4               (1 << 0)
#define DRAMC_PERFCTL0      ((volatile UINT32P)(DRAMC_base+0x1ECU))
    #define DRAMC_PERFCTL0_DISDMOEDIS       (1 << 16)
    #define DRAMC_PERFCTL0_CS2RANK          (1 << 12)
    #define DRAMC_PERFCTL0_RWAGEEN          (1 << 10)
    #define DRAMC_PERFCTL0_RWLLATEN         (1 << 9)
    #define DRAMC_PERFCTL0_RWHPRIEN         (1 << 8)
    #define DRAMC_PERFCTL0_RWOFOWNUM_MASK   (0x7 << 5)
    #define DRAMC_PERFCTL0_RWOFOWNUM(n)     (((n) << 5) & DRAMC_PERFCTL0_RWOFOWNUM_MASK)
    #define DRAMC_PERFCTL0_RWOFEN           (1 << 4)
    #define DRAMC_PERFCTL0_DUALSCHEN        (1 << 0)
#define DRAMC_AC_DERATING   ((volatile UINT32P)(DRAMC_base+0x1F0U))
#define DRAMC_RRRATE_CTL    ((volatile UINT32P)(DRAMC_base+0x1F4U))
    #define DRAMC_RRRATE_CTL_RR_BIT2_SEL_MASK   (0x1f << 16)
    #define DRAMC_RRRATE_CTL_RR_BIT2_SEL(n)     (((n) << 16) & DRAMC_RRRATE_CTL_RR_BIT2_SEL_MASK)
    #define DRAMC_RRRATE_CTL_RR_BIT1_SEL_MASK   (0x1f << 8)
    #define DRAMC_RRRATE_CTL_RR_BIT1_SEL(n)     (((n) << 8) & DRAMC_RRRATE_CTL_RR_BIT1_SEL_MASK)
    #define DRAMC_RRRATE_CTL_RR_BIT0_SEL_MASK   (0x1f << 0)
    #define DRAMC_RRRATE_CTL_RR_BIT0_SEL(n)     (((n) << 0) & DRAMC_RRRATE_CTL_RR_BIT0_SEL_MASK)
#define DRAMC_DQODLY1       ((volatile UINT32P)(DRAMC_base+0x200U))
#define DRAMC_DQODLY2       ((volatile UINT32P)(DRAMC_base+0x204U))
#define DRAMC_DQODLY3       ((volatile UINT32P)(DRAMC_base+0x208U))
#define DRAMC_DQODLY4       ((volatile UINT32P)(DRAMC_base+0x20CU))
#define DRAMC_DQODLY(n)     ((volatile UINT32P)(DRAMC_base+0x200U + ((n) << 2)))
    #define DRAMC_DQnODLY(n, val)            (((val) & 0xF) << (((n) & 0x7) << 2))
#define DRAMC_DQIDLY1       ((volatile UINT32P)(DRAMC_base+0x210U))
#define DRAMC_DQIDLY2       ((volatile UINT32P)(DRAMC_base+0x214U))
#define DRAMC_DQIDLY3       ((volatile UINT32P)(DRAMC_base+0x218U))
#define DRAMC_DQIDLY4       ((volatile UINT32P)(DRAMC_base+0x21CU))
#define DRAMC_DQIDLY5       ((volatile UINT32P)(DRAMC_base+0x220U))
#define DRAMC_DQIDLY6       ((volatile UINT32P)(DRAMC_base+0x224U))
#define DRAMC_DQIDLY7       ((volatile UINT32P)(DRAMC_base+0x228U))
#define DRAMC_DQIDLY8       ((volatile UINT32P)(DRAMC_base+0x22CU))
#define DRAMC_DQIDLY(n)     ((volatile UINT32P)(DRAMC_base+0x210U + ((n) << 2)))
    #define DRAMC_DQnIDLY(n, val)            (((val) & 0xF) << (((n) & 0x3) << 3))

#define DRAMC_R2R_PAGE_HIT_CNT      ((volatile UINT32P)(DRAMC_base+0x280U))
#define DRAMC_R2R_PAGE_MISS_CNT     ((volatile UINT32P)(DRAMC_base+0x284U))
#define DRAMC_R2R_INTERBANK_CNT     ((volatile UINT32P)(DRAMC_base+0x288U))
#define DRAMC_R2W_PAGE_HIT_CNT      ((volatile UINT32P)(DRAMC_base+0x28CU))
#define DRAMC_R2W_PAGE_MISS_CNT     ((volatile UINT32P)(DRAMC_base+0x290U))
#define DRAMC_R2W_INTERBANK_CNT     ((volatile UINT32P)(DRAMC_base+0x294U))
#define DRAMC_W2R_PAGE_HIT_CNT      ((volatile UINT32P)(DRAMC_base+0x298U))
#define DRAMC_W2R_PAGE_MISS_CNT     ((volatile UINT32P)(DRAMC_base+0x29CU))
#define DRAMC_W2R_INTERBANK_CNT     ((volatile UINT32P)(DRAMC_base+0x2A0U))
#define DRAMC_W2W_PAGE_HIT_CNT      ((volatile UINT32P)(DRAMC_base+0x2A4U))
#define DRAMC_W2W_PAGE_MISS_CNT     ((volatile UINT32P)(DRAMC_base+0x2A8U))
#define DRAMC_W2W_INTERBANK_CNT     ((volatile UINT32P)(DRAMC_base+0x2ACU))

#define DRAMC_IDLE_CNT              ((volatile UINT32P)(DRAMC_base+0x2B0U))
#define DRAMC_FREERUN_26M_CNT       ((volatile UINT32P)(DRAMC_base+0x2B4U))
#define DRAMC_REFRESH_POP_CNT       ((volatile UINT32P)(DRAMC_base+0x2B8U))
#define DRAMC_JMETER_ST             ((volatile UINT32P)(DRAMC_base+0x2BCU))

#define DRAMC_DQ_CAL_MAX_0  ((volatile UINT32P)(DRAMC_base+0x2C0U))
#define DRAMC_DQ_CAL_MAX_1  ((volatile UINT32P)(DRAMC_base+0x2C4U))
#define DRAMC_DQ_CAL_MAX_2  ((volatile UINT32P)(DRAMC_base+0x2C8U))
#define DRAMC_DQ_CAL_MAX_3  ((volatile UINT32P)(DRAMC_base+0x2CCU))
#define DRAMC_DQ_CAL_MAX_4  ((volatile UINT32P)(DRAMC_base+0x2D0U))
#define DRAMC_DQ_CAL_MAX_5  ((volatile UINT32P)(DRAMC_base+0x2D4U))
#define DRAMC_DQ_CAL_MAX_6  ((volatile UINT32P)(DRAMC_base+0x2D8U))
#define DRAMC_DQ_CAL_MAX_7  ((volatile UINT32P)(DRAMC_base+0x2DCU))

#define DRAMC_DQS_CAL_MIN_0 ((volatile UINT32P)(DRAMC_base+0x2E0U))
#define DRAMC_DQS_CAL_MIN_1 ((volatile UINT32P)(DRAMC_base+0x2E4U))
#define DRAMC_DQS_CAL_MIN_2 ((volatile UINT32P)(DRAMC_base+0x2E8U))
#define DRAMC_DQS_CAL_MIN_3 ((volatile UINT32P)(DRAMC_base+0x2ECU))
#define DRAMC_DQS_CAL_MIN_4 ((volatile UINT32P)(DRAMC_base+0x2F0U))
#define DRAMC_DQS_CAL_MIN_5 ((volatile UINT32P)(DRAMC_base+0x2F4U))
#define DRAMC_DQS_CAL_MIN_6 ((volatile UINT32P)(DRAMC_base+0x2F8U))
#define DRAMC_DQS_CAL_MIN_7 ((volatile UINT32P)(DRAMC_base+0x2FCU))

#define DRAMC_DQS_CAL_MAX_0 ((volatile UINT32P)(DRAMC_base+0x300U))
#define DRAMC_DQS_CAL_MAX_1 ((volatile UINT32P)(DRAMC_base+0x304U))
#define DRAMC_DQS_CAL_MAX_2 ((volatile UINT32P)(DRAMC_base+0x308U))
#define DRAMC_DQS_CAL_MAX_3 ((volatile UINT32P)(DRAMC_base+0x30CU))
#define DRAMC_DQS_CAL_MAX_4 ((volatile UINT32P)(DRAMC_base+0x310U))
#define DRAMC_DQS_CAL_MAX_5 ((volatile UINT32P)(DRAMC_base+0x314U))
#define DRAMC_DQS_CAL_MAX_6 ((volatile UINT32P)(DRAMC_base+0x318U))
#define DRAMC_DQS_CAL_MAX_7 ((volatile UINT32P)(DRAMC_base+0x31CU))

#define DRAMC_DQICAL0       ((volatile UINT32P)(DRAMC_base+0x350U))
#define DRAMC_DQICAL1       ((volatile UINT32P)(DRAMC_base+0x354U))
#define DRAMC_DQICAL2       ((volatile UINT32P)(DRAMC_base+0x358U))
#define DRAMC_DQICAL3       ((volatile UINT32P)(DRAMC_base+0x35CU))

#define DRAMC_CMP_ERR       ((volatile UINT32P)(DRAMC_base+0x370U))
#define DRAMC_R0DQSIENDLY   ((volatile UINT32P)(DRAMC_base+0x374U))
#define DRAMC_R1DQSIENDLY   ((volatile UINT32P)(DRAMC_base+0x378U))
#define DRAMC_STBEN0        ((volatile UINT32P)(DRAMC_base+0x38CU))
#define DRAMC_STBEN1        ((volatile UINT32P)(DRAMC_base+0x390U))
#define DRAMC_STBEN2        ((volatile UINT32P)(DRAMC_base+0x394U))
#define DRAMC_STBEN3        ((volatile UINT32P)(DRAMC_base+0x398U))
#define DRAMC_DQSDLY0       ((volatile UINT32P)(DRAMC_base+0x3A0U))
#define DRAMC_SPCMDRESP     ((volatile UINT32P)(DRAMC_base+0x3B8U))
    //refer DRAMC_SPCMD
    #define DRAMC_SPCMDRESP_CKE     (1 << 13)
    #define DRAMC_SPCMDRESP_SR      (1 << 12)
#define DRAMC_IORGCNT       ((volatile UINT32P)(DRAMC_base+0x3BCU))
#define DRAMC_DQSGNWCNT0    ((volatile UINT32P)(DRAMC_base+0x3C0U))
#define DRAMC_DQSGNWCNT1    ((volatile UINT32P)(DRAMC_base+0x3C4U))
#define DRAMC_DQSGNWCNT2    ((volatile UINT32P)(DRAMC_base+0x3C8U))
#define DRAMC_DQSGNWCNT3    ((volatile UINT32P)(DRAMC_base+0x3CCU))
#define DRAMC_DQSGNWCNT4    ((volatile UINT32P)(DRAMC_base+0x3D0U))
#define DRAMC_DQSGNWCNT5    ((volatile UINT32P)(DRAMC_base+0x3D4U))
#define DRAMC_DQSSAMPLEV    ((volatile UINT32P)(DRAMC_base+0x3D8U))
#define DRAMC_DLLCNT0       ((volatile UINT32P)(DRAMC_base+0x3DCU))
    #define DRAMC_DLLCNT0_CMPOUT    (1 << 31)
#define DRAMC_CKPHCNT       ((volatile UINT32P)(DRAMC_base+0x3E8U))
#define DRAMC_TESTRPT       ((volatile UINT32P)(DRAMC_base+0x3FCU))
    #define DRAMC_TESTRPT_CALI_DONE_MON (1<<28)
    #define DRAMC_TESTRPT_LB_CMP_FAIL       (1<<24)
    #define DRAMC_TESTRPT_DLE_CNT_OK        (1<<18)
    #define DRAMC_TESTRPT_DM_CMP_ERR        (1<<14)
    #define DRAMC_TESTRPT_DM_CMP_CPT        (1<<10)

#define DRAMC_MEMPLL_DIVIDER    ((volatile UINT32P)(DRAMC_base+0x640U))
    #define DRAMC_MEMPLL_DIVIDER_DMBYP_PLL3_DMCMDPHY_WRAP   (0x1 << 6)
    #define DRAMC_MEMPLL_DIVIDER_DMPLL2CLK_EN               (0x1 << 5)
    #define DRAMC_MEMPLL_DIVIDER_DMALLCLK_EN                (0x1 << 4)
    #define DRAMC_MEMPLL_DIVIDER_DMBYP_PLL3_DDRPHY          (0x1 << 1)
    #define DRAMC_MEMPLL_DIVIDER_DMBYP_PLL4                 (0x1 << 0)
#define DRAMC_VREFCTL0          ((volatile UINT32P)(DRAMC_base+0x644U))

#endif  /* !___DRAMC_HW_INTERNAL_H__ */
