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
 *   mtk_pll.c
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *  This file implements the mempll setting
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
 * 	1. change MEMPLL phase calibration algorithm from 1-way method to 2-way method
 * 	2. keep running even if MEMPLL phase calibration failed
 *
 * removed!
 * removed!
 * 	revise DRAMC SSC from -8% to -4%
 *
 * removed!
 * removed!
 * 1.add EMI/RAMC fine clock off feature
 * 2.update initial dram
 * 3.enable SSC with -8%
 *
 * removed!
 * removed!
 * add MT6290(m) SSC -8% and -4% and turn off it by default
 *
 * removed!
 * removed!
 * update dram init for different frequency
 *
 * removed!
 * removed!
 * update auto-k for detecting RX/TX window size
 *
 * removed!
 * removed!
 * Rollback auto-k changelist 173182
 *
 * removed!
 * removed!
 * update mempll init flow
 *
 * removed!
 * removed!
 * Fix FPGA compile error
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
 * fix E1FPGA build error
 *
 * removed!
 * removed!
 * add mempll calib code
 *
 * removed!
 * removed!
 * 1. update emigen to auto-gen all header files
 * 2. update init mempll
 * 3. update cfggen
 *
 * removed!
 * removed!
 * update auto calibration code for MT6290 and MT6290M
 *
 * removed!
 * removed!
 * fix dramc auto-k
 *
 * removed!
 * removed!
 * fix mempll setting
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
 ****************************************************************************/

/**********************
 * INCLDUED FILES
 **********************/
#include "bl_dramc_drv.h"
#include "mtk_pll.h"

/***********************
 * Definitions
 ***********************/
#define HW_VERSION      (0x80000000+0x0)
#define SW_VERSION      (0x80000000+0x4)
#define HW_CODE_VERSION (0x80000000+0x8)
#define TOPMISC_DUMMY   (BASE_ADDR_TOPMISC+0x01D4)

/***********************
 * MEMPLL Configuration
 ***********************/
#define EMIDDS_SDM_PCW_CHG                  (0x1 << 31)
#define PCW_N_INFO_CHG                      (0x1 << 31)
#define POP_PCW_N_INFO_CHG                  (0x1 << 31)
#define PLL_C0_EN                           (0x1 << 28)
#define PLL_C2_RESERVE                      (0x00 << 24)
#define PLL_C2_DIV_EN                       (0x1 << 16)
#define POP_PLL_C0_EN                       (0x1 << 28)
#define POP_PLL_C2_DIV_EN                   (0x1 << 16)

#define PLL_C1_BIAS_EN                      (0x1 << 6)
#define PLL_C1_BIAS_LPF_EN                  (0x1 << 7)
#define POP_PLL_C1_BIAS_EN                  (0x1 << 6)
#define POP_PLL_C1_BIAS_LPF_EN              (0x1 << 7)
#define PLL2_C0_EN                          (0x1 << 0)
#define PLL3_C0_EN                          (0x1 << 0)
#define POP_PLL3_C0_EN                      (0x1 << 0)
#define PLL4_C0_EN                          (0x1 << 0)


#define PLL_C0_PREDIV                       (0x0 << 26)
#define PLL_C0_POSDIV                       (0x0 << 24)
#define PLL_C0_SDM_DI_EN                    (0x1 << 19)
#define PLL_C1_RESERVE1                     (0x0 << 0)
#define PLL_C2_DIV                          (0x52 << 17)
#define PLL_PCW_N_INFO                      (0x52 << 24)
#define EMIDDS_SDM_FRA_EN                   (0x1 << 28)
#define EMIDDS_POSDIV                       (0x4 << 25)
#define PLL2_C0_PREDIV                      (0x0 << 14)
#define PLL2_C0_POSDIV                      (0x0 << 12)
#define PLL2_C0_VCO_DIV_SEL                 (0x1 << 11)
#define PLL2_C1_RESERVE                     (0x0 << 16)
#define PLL2_C1_REF_DL                      (0x0 << 8)
#define PLL2_C1_FB_DL                       (0x0 << 0)

#define POP_PLL_C0_PREDIV                   (PLL_C0_PREDIV)
#define POP_PLL_C0_POSDIV                   (PLL_C0_POSDIV)
#define POP_PLL_C0_SDM_DI_EN                (PLL_C0_SDM_DI_EN)
#define POP_PLL_C2_RESERVE                  (PLL_C2_RESERVE)
#define POP_PLL_C2_DIV                      (PLL_C2_DIV)
#define POP_PLL_PCW_N_INFO                  (PLL_PCW_N_INFO)

#define POP_PLL_C1_RESERVE1                 (PLL_C1_RESERVE1)
#define PLL3_C0_PREDIV                      (PLL2_C0_PREDIV)
#define PLL3_C0_POSDIV                      (PLL2_C0_POSDIV)
#define PLL3_C0_VCO_DIV_SEL                 (PLL2_C0_VCO_DIV_SEL)
#define PLL3_C1_RESERVE                     (PLL2_C1_RESERVE)
#define PLL3_C1_REF_DL                      (PLL2_C1_REF_DL)
#define PLL3_C1_FB_DL                       (PLL2_C1_FB_DL)
#define POP_PLL3_C0_PREDIV                  (PLL2_C0_PREDIV)
#define POP_PLL3_C0_POSDIV                  (PLL2_C0_POSDIV)
#define POP_PLL3_C0_VCO_DIV_SEL             (PLL2_C0_VCO_DIV_SEL)
#define POP_PLL3_C1_RESERVE                 (PLL2_C1_RESERVE)
#define POP_PLL3_C1_REF_DL                  (PLL2_C1_REF_DL)
#define POP_PLL3_C1_FB_DL                   (PLL2_C1_FB_DL)
#define PLL4_C0_PREDIV                      (PLL2_C0_PREDIV)
#define PLL4_C0_POSDIV                      (PLL2_C0_POSDIV)
#define PLL4_C0_VCO_DIV_SEL                 (PLL2_C0_VCO_DIV_SEL)
#define PLL4_C1_RESERVE                     (PLL2_C1_RESERVE)
#define PLL4_C1_REF_DL                      (PLL2_C1_REF_DL)
#define PLL4_C1_FB_DL                       (PLL2_C1_FB_DL)

#if !defined(__FPGA__)
extern unsigned int is_mt6290m;
extern MTK_EMI_Info EMI_INFO[];
#endif

static void mt_mempll_init(void)
{
#if defined(__FPGA__)
    // Set Clock, temporary solution for FPGA Version: 20120814
    // Bit[3:0]      0: 1x RAMC clock
    //               1: 2x RAMC clock
    // Bit[11:8] 0x0: 17.25MHz
    //               0x1: 18.75MHz
    //               0x2: 20MHz
    //               0x3: 24MHz
    //               0x4: 25MHz
    //               0x5: 30MHz
    //               0x6: 37.5MHz
    //               0x7: 40MHz
    //               0x8: 34.5MHz
    //               0x9: 37.5Mhz
    //               0xA: 40MHz
    //               0xB: 48MHz
    //               0xC: 50MHz
    //               0xD: 60MHz
    //               0xE: 75MHz
    //               0xF: 80MHz
    DRV_WriteReg32(REG_MDCLKCTL_FPGA_EMICTL, 0x00000701);
#else // if !defined(__FPGA__)
    unsigned int reg_val;
    unsigned int pll234_fb_type;
    unsigned int pll234_c0_fbksel;
    unsigned int pll234_c1_fb_mck_sel;
    unsigned int bypass_mempll1;
    unsigned int ddrphy_multi_pll_mode;
    unsigned int seal_ring_mode;

    unsigned int emidds_sdm_pcw_400;
    unsigned int pll234_c0_fbdiv_400;
    unsigned int pll234_c1_m4pdiv_400;
    unsigned int emidds_sdm_pcw_333_5;
    unsigned int pll234_c0_fbdiv_333_5;
    unsigned int pll234_c1_m4pdiv_333_5;
    unsigned int emidds_sdm_pcw_266_5;
    unsigned int pll234_c0_fbdiv_266_5;
    unsigned int pll234_c1_m4pdiv_266_5;
    unsigned int emidds_sdm_pcw_200;
    unsigned int pll234_c0_fbdiv_200;
    unsigned int pll234_c1_m4pdiv_200;

    unsigned int emidds_sdm_pcw;
    unsigned int pll2_c0_fbdiv;
    unsigned int pll2_c1_m4pdiv;
    unsigned int pll3_c0_fbdiv;
    unsigned int pll3_c1_m4pdiv;
    unsigned int pop_pll3_c0_fbdiv;
    unsigned int pop_pll3_c1_m4pdiv;
    unsigned int pll4_c0_fbdiv;
    unsigned int pll4_c1_m4pdiv;

    /*************************************************************
     * (0) check mempll is enabled and initialize local variable.
     *************************************************************/
    // check MEMPLL_RDY_GATING is set to HW control mode.
    reg_val = DRV_Reg32(REG_MDCLKCTL_MEMPLL_CTL) & MEMPLL_CTL_MEMPLL_RDY_GATING;
    if (0 == reg_val) {
        return;
    }

    if (TRUE == is_mt6290m) {
        bypass_mempll1 = TRUE;    
        // NOTE!! With MT6290M, we must use multi-pll mode, because of HW limitation.
        ddrphy_multi_pll_mode = TRUE;
        seal_ring_mode = FALSE;
    } else {
        bypass_mempll1 = TRUE;
        ddrphy_multi_pll_mode = TRUE;
        seal_ring_mode = FALSE;
    }

    if (TRUE == ddrphy_multi_pll_mode) {
        // External Loop
        pll234_fb_type = 1;
    } else {
        // Internal Loop
        pll234_fb_type = 0;
    }

    if (1 == pll234_fb_type) {
        emidds_sdm_pcw_400 = 0xf6276 << 0; // 25 MHz
        pll234_c0_fbdiv_400 = 0x08 << 16;
        pll234_c1_m4pdiv_400 = 0x0 << 28;
        emidds_sdm_pcw_333_5 = 0x111a41 << 0; // 27.79167MHz
        pll234_c0_fbdiv_333_5 = 0x06 << 16;
        pll234_c1_m4pdiv_333_5 = 0x0 << 28;
        emidds_sdm_pcw_266_5 = 0x106666 << 0; // 26.65MHz
        pll234_c0_fbdiv_266_5 = 0x05 << 16;
        pll234_c1_m4pdiv_266_5 = 0x1 << 28;
        emidds_sdm_pcw_200 = 0xf6276 << 0; // 25MHz
        pll234_c0_fbdiv_200 = 0x04 << 16;
        pll234_c1_m4pdiv_200 = 0x1 << 28;
    } else {
        emidds_sdm_pcw_400 = 0xf6276 << 0; // 25 MHz
        pll234_c0_fbdiv_400 = 0x10 << 16;
        pll234_c1_m4pdiv_400 = 0x0 << 28;
        emidds_sdm_pcw_333_5 = 0xfc975 << 0; // 25.6538MHz
        pll234_c0_fbdiv_333_5 = 0x0d << 16;
        pll234_c1_m4pdiv_333_5 = 0x0 << 28;
        emidds_sdm_pcw_266_5 = 0xee8ba << 0; // 24.2272MHz
        pll234_c0_fbdiv_266_5 = 0x16 << 16;
        pll234_c1_m4pdiv_266_5 = 0x1 << 28;
        emidds_sdm_pcw_200 = 0xf6276 << 0; // 25MHz
        pll234_c0_fbdiv_200 = 0x10 << 16;
        pll234_c1_m4pdiv_200 = 0x1 << 28;
    }

    // Warning for set-but-not-used.
    if (emidds_sdm_pcw_400) {}
    if (pll234_c0_fbdiv_400) {}
    if (pll234_c1_m4pdiv_400) {}
    if (emidds_sdm_pcw_333_5) {}
    if (pll234_c0_fbdiv_333_5) {}
    if (pll234_c1_m4pdiv_333_5) {}
    if (emidds_sdm_pcw_266_5) {}
    if (pll234_c0_fbdiv_266_5) {}
    if (pll234_c1_m4pdiv_266_5) {}
    if (emidds_sdm_pcw_200) {}
    if (pll234_c0_fbdiv_200) {}
    if (pll234_c1_m4pdiv_200) {}

    /****************************************
     * (1) Setup Common Setting
     ****************************************/
    
    reg_val = PLL_C0_PREDIV | PLL_C0_POSDIV | PLL_C0_SDM_DI_EN;
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL_CTL0, reg_val);
    reg_val = POP_PLL_C0_PREDIV | POP_PLL_C0_POSDIV | POP_PLL_C0_SDM_DI_EN;
    DRV_WriteReg32(REG_MDCLKCTL_POP_MEMPLL_CTL0, reg_val);

    reg_val = PLL_C1_RESERVE1;
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL_CTL1, reg_val);
    reg_val = POP_PLL_C1_RESERVE1;
    DRV_WriteReg32(REG_MDCLKCTL_POP_MEMPLL_CTL1, reg_val);
   
    reg_val = PLL_C2_RESERVE | PLL_C2_DIV;
    if (FALSE == bypass_mempll1) {
        reg_val |= 0x04 << 24;
    }
    if (TRUE == seal_ring_mode) {
        reg_val |= 0x10 << 24;
    }
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL_CTL2, reg_val);
    reg_val = POP_PLL_C2_RESERVE | POP_PLL_C2_DIV;
    if (FALSE == bypass_mempll1) {
        reg_val |= 0x04 << 24;
    }
    if (TRUE == seal_ring_mode) {
        reg_val |= 0x10 << 24;
    }
    DRV_WriteReg32(REG_MDCLKCTL_POP_MEMPLL_CTL2, reg_val);

    reg_val = PLL_PCW_N_INFO;
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL_PCW, reg_val);
    reg_val = POP_PLL_PCW_N_INFO;
    DRV_WriteReg32(REG_MDCLKCTL_POP_MEMPLL_PCW, reg_val);

    reg_val = EMIDDS_SDM_FRA_EN | EMIDDS_POSDIV;
    DRV_WriteReg32(REG_MDCLKCTL_EMIDDS_CTL, reg_val);

    if (1 == pll234_fb_type) {
        // External Loop
        pll234_c0_fbksel = (0x0 << 24);
    } else {
        // Internal Loop
        pll234_c0_fbksel = (0x1 << 24);
    }
    reg_val = PLL2_C0_PREDIV | PLL2_C0_POSDIV | PLL2_C0_VCO_DIV_SEL;
    reg_val |= pll234_c0_fbksel; 
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL2_CTL0, reg_val);
    reg_val = PLL3_C0_PREDIV | PLL3_C0_POSDIV | PLL3_C0_VCO_DIV_SEL;
    reg_val |= pll234_c0_fbksel; 
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL3_CTL0, reg_val);
    reg_val = POP_PLL3_C0_PREDIV | POP_PLL3_C0_POSDIV | POP_PLL3_C0_VCO_DIV_SEL;
    reg_val |= pll234_c0_fbksel; 
    DRV_WriteReg32(REG_MDCLKCTL_POP_MEMPLL3_CTL0, reg_val);
    reg_val = PLL4_C0_PREDIV | PLL4_C0_POSDIV | PLL4_C0_VCO_DIV_SEL;
    reg_val |= pll234_c0_fbksel; 
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL4_CTL0, reg_val);

    if (1 == pll234_fb_type) {
        // External Loop
        pll234_c1_fb_mck_sel = (0x1 << 25);
    } else {
        // Internal Loop
        pll234_c1_fb_mck_sel = (0x0 << 25);
    }
    reg_val = PLL2_C1_RESERVE | PLL2_C1_REF_DL | PLL2_C1_FB_DL;
    reg_val |= pll234_c1_fb_mck_sel;
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL2_CTL1, reg_val);
    reg_val = PLL3_C1_RESERVE | PLL3_C1_REF_DL | PLL3_C1_FB_DL;
    reg_val |= pll234_c1_fb_mck_sel;
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL3_CTL1, reg_val);
    reg_val = POP_PLL3_C1_RESERVE | POP_PLL3_C1_REF_DL | POP_PLL3_C1_FB_DL;
    reg_val |= pll234_c1_fb_mck_sel;
    DRV_WriteReg32(REG_MDCLKCTL_POP_MEMPLL3_CTL1, reg_val);
    reg_val = PLL4_C1_RESERVE | PLL4_C1_REF_DL | PLL4_C1_FB_DL;
    reg_val |= pll234_c1_fb_mck_sel;
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL4_CTL1, reg_val);
 
    DRV_WriteReg32(DRAMC_ACTIM0, EMI_INFO[0].dramc_actim0_val);
    DRV_WriteReg32(DRAMC_DDR2CTL, EMI_INFO[0].dramc_ddr2ctl_val);

    /*******************************************************************************************
     * (2) Setup MEMPLL operation case & frequency, May set according to dram type & frequency
     *******************************************************************************************/
    if (TRUE == is_mt6290m) {
        #if 1
        emidds_sdm_pcw          = emidds_sdm_pcw_400;
        pll2_c0_fbdiv           = pll234_c0_fbdiv_400;
        pll2_c1_m4pdiv          = pll234_c1_m4pdiv_400;
        pll3_c0_fbdiv           = pll234_c0_fbdiv_400;
        pll3_c1_m4pdiv          = pll234_c1_m4pdiv_400;
        pop_pll3_c0_fbdiv       = pll234_c0_fbdiv_400;
        pop_pll3_c1_m4pdiv      = pll234_c1_m4pdiv_400;
        pll4_c0_fbdiv           = pll234_c0_fbdiv_400;
        pll4_c1_m4pdiv          = pll234_c1_m4pdiv_400;
        #endif
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
    } else {
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        #if 1
        emidds_sdm_pcw          = emidds_sdm_pcw_333_5;
        pll2_c0_fbdiv           = pll234_c0_fbdiv_333_5;
        pll2_c1_m4pdiv          = pll234_c1_m4pdiv_333_5;
        pll3_c0_fbdiv           = pll234_c0_fbdiv_333_5;
        pll3_c1_m4pdiv          = pll234_c1_m4pdiv_333_5;
        pop_pll3_c0_fbdiv       = pll234_c0_fbdiv_333_5;
        pop_pll3_c1_m4pdiv      = pll234_c1_m4pdiv_333_5;
        pll4_c0_fbdiv           = pll234_c0_fbdiv_333_5;
        pll4_c1_m4pdiv          = pll234_c1_m4pdiv_333_5;
        #endif
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
    }
    reg_val = DRV_Reg32(REG_MDCLKCTL_EMIDDS_CTL) | emidds_sdm_pcw;
    DRV_WriteReg32(REG_MDCLKCTL_EMIDDS_CTL, reg_val);
    
    reg_val = DRV_Reg32(REG_MDCLKCTL_MEMPLL2_CTL0) | pll2_c0_fbdiv;
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL2_CTL0, reg_val);
    reg_val = DRV_Reg32(REG_MDCLKCTL_MEMPLL3_CTL0) | pll3_c0_fbdiv;
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL3_CTL0, reg_val);
    reg_val = DRV_Reg32(REG_MDCLKCTL_POP_MEMPLL3_CTL0) | pop_pll3_c0_fbdiv;
    DRV_WriteReg32(REG_MDCLKCTL_POP_MEMPLL3_CTL0, reg_val);
    reg_val = DRV_Reg32(REG_MDCLKCTL_MEMPLL4_CTL0) | pll4_c0_fbdiv;
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL4_CTL0, reg_val);

    reg_val = DRV_Reg32(REG_MDCLKCTL_MEMPLL2_CTL1) | pll2_c1_m4pdiv;
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL2_CTL1, reg_val);
    reg_val = DRV_Reg32(REG_MDCLKCTL_MEMPLL3_CTL1) | pll3_c1_m4pdiv;
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL3_CTL1, reg_val);
    reg_val = DRV_Reg32(REG_MDCLKCTL_POP_MEMPLL3_CTL1) | pop_pll3_c1_m4pdiv;
    DRV_WriteReg32(REG_MDCLKCTL_POP_MEMPLL3_CTL1, reg_val);
    reg_val = DRV_Reg32(REG_MDCLKCTL_MEMPLL4_CTL1) | pll4_c1_m4pdiv;
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL4_CTL1, reg_val);

    /*************************************
     * (3) Setup MEMPLL power on sequence
     *************************************/
    reg_val = DRV_Reg32(DRAMC_MEMPLL_DIVIDER) | DRAMC_MEMPLL_DIVIDER_DMBYP_PLL4;
    if (1 == pll234_fb_type) {
        reg_val |= DRAMC_MEMPLL_DIVIDER_DMPLL2CLK_EN;
    }
    if (TRUE == ddrphy_multi_pll_mode) {
        reg_val &= ~DRAMC_MEMPLL_DIVIDER_DMBYP_PLL3_DDRPHY;
    } else {
        reg_val |= DRAMC_MEMPLL_DIVIDER_DMBYP_PLL3_DDRPHY;
    }
    DRV_WriteReg32(DRAMC_MEMPLL_DIVIDER, reg_val);

    reg_val = DRV_Reg32(REG_MDCLKCTL_MEMPLL_CTL) & (~(MEMPLL_CTL_MEMPLL_SW_MEMPLL_ISO_EN));
    if (TRUE == is_mt6290m) {
        reg_val &= ~(MEMPLL_CTL_MEMPLL_SW_POP_MEMPLL_ISO_EN);
    }
    reg_val |= MEMPLL_CTL_MEMPLL_RDY_GATING;
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL_CTL, reg_val);
    reg_val = DRV_Reg32(REG_MDCLKCTL_EMIDDS_FH_CTL1) | EMIDDS_FH_CTL1_EMIDDS_FSM_EN;
    DRV_WriteReg32(REG_MDCLKCTL_EMIDDS_FH_CTL1, reg_val);
    reg_val = DRV_Reg32(REG_MDCLKCTL_EMIDDS_CTL) | EMIDDS_SDM_PCW_CHG;
    DRV_WriteReg32_NPW(REG_MDCLKCTL_EMIDDS_CTL, reg_val);
    // Delay 20 us
    BL_GPT_UDELAY(20);

    if (FALSE == bypass_mempll1) {
        reg_val = DRV_Reg32(REG_MDCLKCTL_MEMPLL_PCW) | PCW_N_INFO_CHG;
        DRV_WriteReg32(REG_MDCLKCTL_MEMPLL_PCW, reg_val);
        if (TRUE == is_mt6290m) {
            reg_val = DRV_Reg32(REG_MDCLKCTL_POP_MEMPLL_PCW) | POP_PCW_N_INFO_CHG;
            DRV_WriteReg32(REG_MDCLKCTL_POP_MEMPLL_PCW, reg_val);
        }
        reg_val = DRV_Reg32(REG_MDCLKCTL_PLL_ON_CTL1) | PLL_ON_CTL1_SW_EMIDDS_PWR_ON;
        DRV_WriteReg32_NPW(REG_MDCLKCTL_PLL_ON_CTL1, reg_val);
        // Delay 30 ns
        BL_GPT_UDELAY(1);
    }

    reg_val = DRV_Reg32(REG_MDCLKCTL_MEMPLL_CTL1) | PLL_C1_BIAS_EN;
    DRV_WriteReg32_NPW(REG_MDCLKCTL_MEMPLL_CTL1, reg_val);
    if (TRUE == is_mt6290m) {
        reg_val = DRV_Reg32(REG_MDCLKCTL_POP_MEMPLL_CTL1) | POP_PLL_C1_BIAS_EN;
        DRV_WriteReg32_NPW(REG_MDCLKCTL_POP_MEMPLL_CTL1, reg_val);
    }
    // Delay 2 us
    BL_GPT_UDELAY(2);
    reg_val = DRV_Reg32(REG_MDCLKCTL_MEMPLL_CTL1) | PLL_C1_BIAS_LPF_EN;
    DRV_WriteReg32_NPW(REG_MDCLKCTL_MEMPLL_CTL1, reg_val);
    if (TRUE == is_mt6290m) {
        reg_val = DRV_Reg32(REG_MDCLKCTL_POP_MEMPLL_CTL1) | POP_PLL_C1_BIAS_LPF_EN;
        DRV_WriteReg32_NPW(REG_MDCLKCTL_POP_MEMPLL_CTL1, reg_val);
    }
    // Delay 1 ms
    BL_GPT_UDELAY(1000);
    if ((FALSE == bypass_mempll1) || (TRUE == seal_ring_mode)) {
        reg_val = DRV_Reg32(REG_MDCLKCTL_MEMPLL_CTL0) | PLL_C0_EN;
        DRV_WriteReg32_NPW(REG_MDCLKCTL_MEMPLL_CTL0, reg_val);
        if (TRUE == is_mt6290m) {
            reg_val = DRV_Reg32(REG_MDCLKCTL_POP_MEMPLL_CTL0) | POP_PLL_C0_EN;
            DRV_WriteReg32_NPW(REG_MDCLKCTL_POP_MEMPLL_CTL0, reg_val);
        }
        // Delay 20 us
        BL_GPT_UDELAY(20);
    }
    if (FALSE == bypass_mempll1) {
        reg_val = DRV_Reg32(REG_MDCLKCTL_MEMPLL_CTL2) | PLL_C2_DIV_EN;
        DRV_WriteReg32_NPW(REG_MDCLKCTL_MEMPLL_CTL2, reg_val);
        if (TRUE == is_mt6290m) {
            reg_val = DRV_Reg32(REG_MDCLKCTL_POP_MEMPLL_CTL2) | POP_PLL_C2_DIV_EN;
            DRV_WriteReg32_NPW(REG_MDCLKCTL_POP_MEMPLL_CTL2, reg_val);
        }
        // Delay 1 us
        BL_GPT_UDELAY(1);
    }
   
    reg_val = DRV_Reg32(REG_MDCLKCTL_MEMPLL2_CTL0) | PLL2_C0_EN;
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL2_CTL0, reg_val);
    if (TRUE == ddrphy_multi_pll_mode) {
        if (TRUE == is_mt6290m) {
            reg_val = DRV_Reg32(REG_MDCLKCTL_POP_MEMPLL3_CTL0) | POP_PLL3_C0_EN;
            DRV_WriteReg32_NPW(REG_MDCLKCTL_POP_MEMPLL3_CTL0, reg_val);
        } else {
            reg_val = DRV_Reg32(REG_MDCLKCTL_MEMPLL3_CTL0) | PLL3_C0_EN;
            DRV_WriteReg32_NPW(REG_MDCLKCTL_MEMPLL3_CTL0, reg_val);
        }
    }
    // Delay 20 us
    BL_GPT_UDELAY(20);

    reg_val = DRV_Reg32(DRAMC_MEMPLL_DIVIDER) | DRAMC_MEMPLL_DIVIDER_DMPLL2CLK_EN | DRAMC_MEMPLL_DIVIDER_DMALLCLK_EN;
    DRV_WriteReg32_NPW(DRAMC_MEMPLL_DIVIDER, reg_val);

    reg_val = DRV_Reg32(REG_MDCLKCTL_MEMPLL_CTL) & (~MEMPLL_CTL_MEMPLL_RDY_GATING);
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL_CTL, reg_val);
    // Simulation is about 1.1 us
    BL_GPT_UDELAY(3);
    reg_val = DRV_Reg32(REG_MDCLKCTL_MEMPLL_CTL) | MEMPLL_CTL_MEMPLL_MEMPLL_HW_CTL_MODE;
    if (TRUE == is_mt6290m) {
        reg_val |= MEMPLL_CTL_MEMPLL_POP_MEMPLL_HW_CTL_MODE;
    }
    DRV_WriteReg32_NPW(REG_MDCLKCTL_MEMPLL_CTL, reg_val); 

#endif // end if defined(__FPGA__)

    Data_Mem_Barrier();
}

#define MEMPLL_JMETER_CNT               1024
#define MEMPLL_JMETER_CONFIDENCE_CNT    (MEMPLL_JMETER_CNT/10)

static int mt_mempll_cali(void)
{
#if defined(__FPGA__)
    return 0;
#else // if !defined(__FPGA__)
    int one_count = 0, zero_count = 0;
    int pll2_done = 0, pll3_done = 0, pll4_done = 0, pop_pll3_done = 0, ret = 0;

    unsigned int temp = 0, pll2_dl = 0, pll3_dl = 0, pll4_dl = 0, pop_pll3_dl = 0;
    int pll2_phase=0, pll3_phase=0, pll4_phase=0, pop_pll3_phase=0;

    // [-Werror=unused-but-set-variable]
    if (one_count){}
    if (zero_count){}

    /***********************************************************
    * 1. Bypass some pll calibration because pll is turned off.
    ***********************************************************/
    if (0 == (DRV_Reg32(REG_MDCLKCTL_MEMPLL2_CTL0)&PLL2_C0_EN)) {
        pll2_done = 1;
    }
    if (0 == (DRV_Reg32(REG_MDCLKCTL_MEMPLL3_CTL0)&PLL3_C0_EN)) {
        pll3_done = 1;
    }
    if (0 == (DRV_Reg32(REG_MDCLKCTL_MEMPLL4_CTL0)&PLL4_C0_EN)) {
        pll4_done = 1;
    }
    if (0 == (DRV_Reg32(REG_MDCLKCTL_POP_MEMPLL3_CTL0)&POP_PLL3_C0_EN)) {
        pop_pll3_done = 1;
    }

    /***********************************************
    * 2. Set jitter meter count number
    ************************************************/
    // Set jitter meter count to 1024
    temp = (DRV_Reg32(REG_MDCLKCTL_MEMPLL_JMETER_CTL) & MEMPLL_JMETER_CTL_CNT_MASK) | MEMPLL_JMETER_CTL_CNT(MEMPLL_JMETER_CNT);
    DRV_WriteReg32(REG_MDCLKCTL_MEMPLL_JMETER_CTL, temp);

    while(1)
    { 
        /***********************************************
        * 3. Adjust delay chain tap number
        ************************************************/

        if (!pll2_done)
        {
            if (pll2_phase == 0)   // initial phase set to 0 for REF and FBK
            {
                temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL2_CTL1) & ~MEMPLL2_CTL1_REF_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_MEMPLL2_CTL1, (temp | MEMPLL2_CTL1_REF_DL(0x0)));

                temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL2_CTL1) & ~MEMPLL2_CTL1_FB_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_MEMPLL2_CTL1, (temp | MEMPLL2_CTL1_FB_DL(0x0)));
            }
            else if (pll2_phase == 1)   // REF lead FBK, delay FBK
            {
                temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL2_CTL1) & ~MEMPLL2_CTL1_REF_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_MEMPLL2_CTL1, (temp | MEMPLL2_CTL1_REF_DL(0x0)));

                temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL2_CTL1) & ~MEMPLL2_CTL1_FB_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_MEMPLL2_CTL1, (temp | MEMPLL2_CTL1_FB_DL(pll2_dl)));
            }
            else   // REF lag FBK, delay REF
            {
                temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL2_CTL1) & ~MEMPLL2_CTL1_REF_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_MEMPLL2_CTL1, (temp | MEMPLL2_CTL1_REF_DL(pll2_dl)));

                temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL2_CTL1) & ~MEMPLL2_CTL1_FB_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_MEMPLL2_CTL1, (temp | MEMPLL2_CTL1_FB_DL(0x0)));
            }
        }

        if (!pll3_done)
        {
            if (pll3_phase == 0)   // initial phase set to 0 for REF and FBK
            {
                temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL3_CTL1) & ~MEMPLL3_CTL1_REF_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_MEMPLL3_CTL1, (temp | MEMPLL3_CTL1_REF_DL(0x0))); 

                temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL3_CTL1) & ~MEMPLL3_CTL1_FB_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_MEMPLL3_CTL1, (temp | MEMPLL3_CTL1_FB_DL(0x0))); 
            }
            else if (pll3_phase == 1)   // REF lead FBK, delay FBK
            {
                temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL3_CTL1) & ~MEMPLL3_CTL1_REF_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_MEMPLL3_CTL1, (temp | MEMPLL3_CTL1_REF_DL(0x0)));

                temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL3_CTL1) & ~MEMPLL3_CTL1_FB_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_MEMPLL3_CTL1, (temp | MEMPLL3_CTL1_FB_DL(pll3_dl)));
            }
            else   // REF lag FBK, delay REF
            {
                temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL3_CTL1) & ~MEMPLL3_CTL1_REF_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_MEMPLL3_CTL1, (temp | MEMPLL3_CTL1_REF_DL(pll3_dl)));

                temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL3_CTL1) & ~MEMPLL3_CTL1_FB_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_MEMPLL3_CTL1, (temp | MEMPLL3_CTL1_FB_DL(0x0)));
            }
        }

        if (!pll4_done)
        {
            if (pll4_phase == 0)   // initial phase set to 0 for REF and FBK
            {
                temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL4_CTL1) & ~MEMPLL4_CTL1_REF_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_MEMPLL4_CTL1, (temp | MEMPLL4_CTL1_REF_DL(0x0)));

                temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL4_CTL1) & ~MEMPLL4_CTL1_FB_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_MEMPLL4_CTL1, (temp | MEMPLL4_CTL1_FB_DL(0x0)));
            }
            else if (pll4_phase == 1)   // REF lead FBK, delay FBK
            {
                temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL4_CTL1) & ~MEMPLL4_CTL1_REF_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_MEMPLL4_CTL1, (temp | MEMPLL4_CTL1_REF_DL(0x0)));

                temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL4_CTL1) & ~MEMPLL4_CTL1_FB_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_MEMPLL4_CTL1, (temp | MEMPLL4_CTL1_FB_DL(pll4_dl)));
            }
            else   // REF lag FBK, delay REF
            {
                temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL4_CTL1) & ~MEMPLL4_CTL1_REF_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_MEMPLL4_CTL1, (temp | MEMPLL4_CTL1_REF_DL(pll4_dl)));

                temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL4_CTL1) & ~MEMPLL4_CTL1_FB_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_MEMPLL4_CTL1, (temp | MEMPLL4_CTL1_FB_DL(0x0)));
            }
        }

        if (!pop_pll3_done)
        {
            if (pop_pll3_phase == 0)   // initial phase set to 0 for REF and FBK
            {
                temp = DRV_Reg32(REG_MDCLKCTL_POP_MEMPLL3_CTL1) & ~POP_MEMPLL3_CTL1_REF_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_POP_MEMPLL3_CTL1, (temp | POP_MEMPLL3_CTL1_REF_DL(0x0))); 

                temp = DRV_Reg32(REG_MDCLKCTL_POP_MEMPLL3_CTL1) & ~POP_MEMPLL3_CTL1_FB_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_POP_MEMPLL3_CTL1, (temp | POP_MEMPLL3_CTL1_FB_DL(0x0)));
            }
            else if (pop_pll3_phase == 1)   // REF lead FBK, delay FBK
            {
                temp = DRV_Reg32(REG_MDCLKCTL_POP_MEMPLL3_CTL1) & ~POP_MEMPLL3_CTL1_REF_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_POP_MEMPLL3_CTL1, (temp | POP_MEMPLL3_CTL1_REF_DL(0x0)));

                temp = DRV_Reg32(REG_MDCLKCTL_POP_MEMPLL3_CTL1) & ~POP_MEMPLL3_CTL1_FB_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_POP_MEMPLL3_CTL1, (temp | POP_MEMPLL3_CTL1_FB_DL(pop_pll3_dl)));
            }
            else   // REF lag FBK, delay REF
            {
                temp = DRV_Reg32(REG_MDCLKCTL_POP_MEMPLL3_CTL1) & ~POP_MEMPLL3_CTL1_REF_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_POP_MEMPLL3_CTL1, (temp | POP_MEMPLL3_CTL1_REF_DL(pop_pll3_dl)));

                temp = DRV_Reg32(REG_MDCLKCTL_POP_MEMPLL3_CTL1) & ~POP_MEMPLL3_CTL1_FB_DL_MASK;
                DRV_WriteReg32(REG_MDCLKCTL_POP_MEMPLL3_CTL1, (temp | POP_MEMPLL3_CTL1_FB_DL(0x0))); 
            }
        }
        // Delay 20 us
        BL_GPT_UDELAY(20);

        /***********************************************
        * 4. Enable jitter meter
        ************************************************/

        if (!pll2_done)
        {
            // enable pll2 jitter meter
            temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL_JMETER_CTL) | MEMPLL_JMETER_CTL_EN(0);
            DRV_WriteReg32(REG_MDCLKCTL_MEMPLL_JMETER_CTL, temp);
        }

        if (!pll3_done)
        {
            // enable pll3 jitter meter
            temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL_JMETER_CTL) | MEMPLL_JMETER_CTL_EN(1);
            DRV_WriteReg32(REG_MDCLKCTL_MEMPLL_JMETER_CTL, temp);
        }

        if (!pll4_done)
        {
            // enable pll4 jitter meter
            temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL_JMETER_CTL) | MEMPLL_JMETER_CTL_EN(2);
            DRV_WriteReg32(REG_MDCLKCTL_MEMPLL_JMETER_CTL, temp);
        }
        if (!pop_pll3_done)
        {
            // enable pop_pll3 jitter meter
            temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL_JMETER_CTL) | MEMPLL_JMETER_CTL_EN(3);
            DRV_WriteReg32(REG_MDCLKCTL_MEMPLL_JMETER_CTL, temp);
        }

        // wait for jitter meter done
        if (!pll2_done) {
            while (!(DRV_Reg32(REG_MDCLKCTL_MEMPLL_JMETER_CTL)&MEMPLL_JMETER_CTL_DONE(0)));
        }
        if (!pll3_done) {
            while (!(DRV_Reg32(REG_MDCLKCTL_MEMPLL_JMETER_CTL)&MEMPLL_JMETER_CTL_DONE(1)));
        }
        if (!pll4_done) {
            while (!(DRV_Reg32(REG_MDCLKCTL_MEMPLL_JMETER_CTL)&MEMPLL_JMETER_CTL_DONE(2)));
        }
        if (!pop_pll3_done) {
            while (!(DRV_Reg32(REG_MDCLKCTL_MEMPLL_JMETER_CTL)&MEMPLL_JMETER_CTL_DONE(3)));
        }

        /***********************************************
        * 5. Check jitter meter counter value
        ************************************************/

        if (!pll2_done)
        {
            one_count = MEMPLLn_JMETER_STS_ONES_CNT_VAL(0);
            zero_count = MEMPLLn_JMETER_STS_ZEROS_CNT_VAL(0);

            if (pll2_phase == 0)
            {                   
                if (zero_count > (one_count+MEMPLL_JMETER_CONFIDENCE_CNT))
                {
                    // REF lead FBK
                    pll2_phase = 1;
                    pll2_dl++;

                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] PLL2 initial phase: REF lead FBK, one_cnt/zero_cnt = %d/%d\r\n", one_count, zero_count);
                }
                else if (one_count > (zero_count+MEMPLL_JMETER_CONFIDENCE_CNT))
                {
                    // REF lag FBK
                    pll2_phase = 2;
                    pll2_dl++;

                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] PLL2 initial phase: REF lag FBK, one_cnt/zero_cnt = %d/%d\r\n", one_count, zero_count);
                }
                else
                {
                    // in phase at initial
                    pll2_done = 1;

                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] PLL2 initial phase: REF in-phase FBK, one_cnt/zero_cnt = %d/%d\r\n", one_count, zero_count);
                }
            }
            else if (pll2_phase == 1)
            {
                if ((one_count+MEMPLL_JMETER_CONFIDENCE_CNT) >= zero_count)
                {
                    pll2_done = 1;
                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] PLL2 REF_DL: 0x0, FBK_DL: 0x%x, one_cnt/zero_cnt = %d/%d\n", pll2_dl, one_count, zero_count);
                }
                else
                {
                    pll2_dl++;
                }
            }
            else
            {
                if ((zero_count+MEMPLL_JMETER_CONFIDENCE_CNT) >= one_count)
                {
                    pll2_done = 1;
                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] PLL2 REF_DL: 0x%x, FBK_DL: 0x0, one_cnt/zero_cnt = %d/%d\n", pll2_dl, one_count, zero_count);
                }
                else
                {
                    pll2_dl++;
                }
            }            
        }

        if (!pll3_done)
        {
            one_count = MEMPLLn_JMETER_STS_ONES_CNT_VAL(1);
            zero_count = MEMPLLn_JMETER_STS_ZEROS_CNT_VAL(1);

            if (pll3_phase == 0)
            {                   
                if (zero_count > (one_count+MEMPLL_JMETER_CONFIDENCE_CNT))
                {
                    // REF lead FBK
                    pll3_phase = 1;
                    pll3_dl++;

                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] PLL3 initial phase: REF lead FBK, one_cnt/zero_cnt = %d/%d\r\n", one_count, zero_count);
                }
                else if (one_count > (zero_count+MEMPLL_JMETER_CONFIDENCE_CNT))
                {
                    // REF lag FBK
                    pll3_phase = 2;
                    pll3_dl++;

                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] PLL3 initial phase: REF lag FBK, one_cnt/zero_cnt = %d/%d\r\n", one_count, zero_count);
                }
                else
                {
                    // in phase at initial
                    pll3_done = 1;

                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] PLL3 initial phase: REF in-phase FBK, one_cnt/zero_cnt = %d/%d\r\n", one_count, zero_count);
                }
            }
            else if (pll3_phase == 1)
            {
                if ((one_count+MEMPLL_JMETER_CONFIDENCE_CNT)  >= zero_count)
                {
                    pll3_done = 1;
                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] PLL3 REF_DL: 0x0, FBK_DL: 0x%x, one_cnt/zero_cnt = %d/%d\n", pll3_dl, one_count, zero_count);
                }
                else
                {
                    pll3_dl++;
                }
            }
            else
            {
                if ((zero_count+MEMPLL_JMETER_CONFIDENCE_CNT) >= one_count)
                {
                    pll3_done = 1;
                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] PLL3 REF_DL: 0x%x, FBK_DL: 0x0, one_cnt/zero_cnt = %d/%d\n", pll3_dl, one_count, zero_count);
                }
                else
                {
                    pll3_dl++;
                }
            } 
        }

        if (!pll4_done)
        {
            one_count = MEMPLLn_JMETER_STS_ONES_CNT_VAL(2);
            zero_count = MEMPLLn_JMETER_STS_ZEROS_CNT_VAL(2);

            if (pll4_phase == 0)
            {                   
                if (zero_count > (one_count+MEMPLL_JMETER_CONFIDENCE_CNT))
                {
                    // REF lead FBK
                    pll4_phase = 1;
                    pll4_dl++;

                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] PLL4 initial phase: REF lead FBK, one_cnt/zero_cnt = %d/%d\r\n", one_count, zero_count);
                }
                else if (one_count > (zero_count+MEMPLL_JMETER_CONFIDENCE_CNT))
                {
                    // REF lag FBK
                    pll4_phase = 2;
                    pll4_dl++;

                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] PLL4 initial phase: REF lag FBK, one_cnt/zero_cnt = %d/%d\r\n", one_count, zero_count);
                }
                else
                {
                    // in phase at initial
                    pll4_done = 1;

                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] PLL4 initial phase: REF in-phase FBK, one_cnt/zero_cnt = %d/%d\r\n", one_count, zero_count);
                }
            }
            else if (pll4_phase == 1)
            {
                if ((one_count+MEMPLL_JMETER_CONFIDENCE_CNT)  >= zero_count)
                {
                    pll4_done = 1;
                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] PLL4 REF_DL: 0x0, FBK_DL: 0x%x, one_cnt/zero_cnt = %d/%d\n", pll4_dl, one_count, zero_count);
                }
                else
                {
                    pll4_dl++;
                }
            }
            else
            {
                if ((zero_count+MEMPLL_JMETER_CONFIDENCE_CNT) >= one_count)
                {
                    pll4_done = 1;
                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] PLL4 REF_DL: 0x%x, FBK_DL: 0x0, one_cnt/zero_cnt = %d/%d\n", pll4_dl, one_count, zero_count);
                }
                else
                {
                    pll4_dl++;
                }
            } 
        }

        if (!pop_pll3_done)
        {
            one_count = MEMPLLn_JMETER_STS_ONES_CNT_VAL(3);
            zero_count = MEMPLLn_JMETER_STS_ZEROS_CNT_VAL(3);

            if (pop_pll3_phase == 0)
            {                   
                if (zero_count > (one_count+MEMPLL_JMETER_CONFIDENCE_CNT))
                {
                    // REF lead FBK
                    pop_pll3_phase = 1;
                    pop_pll3_dl++;

                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] POP_PLL3 initial phase: REF lead FBK, one_cnt/zero_cnt = %d/%d\r\n", one_count, zero_count);
                }
                else if (one_count > (zero_count+MEMPLL_JMETER_CONFIDENCE_CNT))
                {
                    // REF lag FBK
                    pop_pll3_phase = 2;
                    pop_pll3_dl++;

                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] POP_PLL3 initial phase: REF lag FBK, one_cnt/zero_cnt = %d/%d\r\n", one_count, zero_count);
                }
                else
                {
                    // in phase at initial
                    pop_pll3_done = 1;

                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] POP_PLL3 initial phase: REF in-phase FBK, one_cnt/zero_cnt = %d/%d\r\n", one_count, zero_count);
                }
            }
            else if (pop_pll3_phase == 1)
            {
                if ((one_count+MEMPLL_JMETER_CONFIDENCE_CNT)  >= zero_count)
                {
                    pop_pll3_done = 1;
                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] POP_PLL3 REF_DL: 0x0, FBK_DL: 0x%x, one_cnt/zero_cnt = %d/%d\n", pop_pll3_dl, one_count, zero_count);
                }
                else
                {
                    pop_pll3_dl++;
                }
            }
            else
            {
                if ((zero_count+MEMPLL_JMETER_CONFIDENCE_CNT) >= one_count)
                {
                    pop_pll3_done = 1;
                    BL_PRINT(LOG_INFO, "[PLL_Phase_Calib] POP_PLL3 REF_DL: 0x%x, FBK_DL: 0x0, one_cnt/zero_cnt = %d/%d\n", pop_pll3_dl, one_count, zero_count);
                }
                else
                {
                    pop_pll3_dl++;
                }
            }
        }

        /***********************************************
        * 6. Reset jitter meter value
        ************************************************/

        // disable pll jitter meter
        temp = DRV_Reg32(REG_MDCLKCTL_MEMPLL_JMETER_CTL) & 
            ~(MEMPLL_JMETER_CTL_EN(0) | MEMPLL_JMETER_CTL_EN(1) | MEMPLL_JMETER_CTL_EN(2) | MEMPLL_JMETER_CTL_EN(3));
        DRV_WriteReg32(REG_MDCLKCTL_MEMPLL_JMETER_CTL, temp);

        /*************************************************************
        * 7. Check Result
        * Return to step 1 to adjust next delay chain tap value.
        * Until we have ~ 50% of one or zero count on jitter meter
        **************************************************************/

        if (pll2_done && pll3_done && pll4_done && pop_pll3_done)
        {
            ret = 0;
            break;
        }

        if (pll2_dl >= 32 || pll3_dl >= 32 || pll4_dl >= 32 || pop_pll3_dl >= 32)
        {
            BL_PRINT(LOG_ERROR, "[mt_pll_init] MEMPLL calibration fail (%d-%d/%d-%d/%d-%d/%d-%d)\r\n", 
                pll2_done, pll2_dl, pll3_done, pll3_dl, pll4_done, pll4_dl, pop_pll3_done, pop_pll3_dl);
            // We always return pass even if MEMPLL phase calibration is failed.
            ret = 0;
            break;
        }
    }

    return ret;
#endif // end if defined(__FPGA__)

}

void mt_mempll_ssc(void)
{
#if !defined(__FPGA__) 
    kal_uint32 reg_val;

    // MT6290(M), Not E1, Because MT6290(M)E1 has WMHEC5471
    if ((DRV_Reg32(HW_CODE_VERSION) == 0x00006290) && (DRV_Reg32(HW_VERSION) != 0x0000CA00)) {
        reg_val = DRV_Reg32(REG_MDCLKCTL_EMIDDS_FH_CTL2) & ~(EMIDDS_FH_CTL2_FRDDS_DNLMT_MASK | EMIDDS_FH_CTL2_FRDDS_UPLMT_MASK);
        if (TRUE == is_mt6290m) {
            // -8%. For PCW is equal to 25MHz, down limit is 2 MHz, Up limit is 0 MHz
            //reg_val |= EMIDDS_FH_CTL2_FRDDS_DNLMT(0x9E) | EMIDDS_FH_CTL2_FRDDS_UPLMT(0x0);
            // -4%. For PCW is equal to 25MHz, down limit is 2 MHz, Up limit is 0 MHz
            reg_val |= EMIDDS_FH_CTL2_FRDDS_DNLMT(0x4F) | EMIDDS_FH_CTL2_FRDDS_UPLMT(0x0);
        } else {
            // -8%. For PCW is equal to 27.79167MHz, down limit is 2.2 MHz, Up limit is 0 MHz
            //reg_val |= EMIDDS_FH_CTL2_FRDDS_DNLMT(0xB0) | EMIDDS_FH_CTL2_FRDDS_UPLMT(0x0);
            // -4%. For PCW is equal to 27.79167MHz, down limit is 1.1 MHz, Up limit is 0 MHz
            reg_val |= EMIDDS_FH_CTL2_FRDDS_DNLMT(0x58) | EMIDDS_FH_CTL2_FRDDS_UPLMT(0x0);
        }
        DRV_WriteReg32(REG_MDCLKCTL_EMIDDS_FH_CTL2, reg_val);
        // Time Step is 0.5 us, Frequency Step is ~0.1MHz
        reg_val = DRV_Reg32(REG_MDCLKCTL_EMIDDS_FH_CTL1) & ~(EMIDDS_FH_CTL1_EMIDDS_FRDDS_DTS_MASK | EMIDDS_FH_CTL1_EMIDDS_FRDDS_DYS_MASK);
        reg_val |= EMIDDS_FH_CTL1_EMIDDS_FSM_EN | EMIDDS_FH_CTL1_EMIDDS_FRDDS_EN | \
                    EMIDDS_FH_CTL1_EMIDDS_FRDDS_DTS(0) | EMIDDS_FH_CTL1_EMIDDS_FRDDS_DYS(0);
        DRV_WriteReg32(REG_MDCLKCTL_EMIDDS_FH_CTL1, reg_val);
        // We need to write EMIDDS_CTL to mask sure that previous settings take effect
        reg_val = DRV_Reg32(REG_MDCLKCTL_EMIDDS_CTL) | EMIDDS_SDM_PCW_CHG;
        DRV_WriteReg32_NPW(REG_MDCLKCTL_EMIDDS_CTL, reg_val);

        Data_Mem_Barrier();
    }
#endif // end if !defined(__FPGA__)
}

int mt_pll_init(void)
{
    int ret = 0;

    /* MEMPLL Init */
    mt_mempll_init();

    /* MEMPLL Calibration */
    ret = mt_mempll_cali();

    return ret;
}
