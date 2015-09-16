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
 *   mt_emi.c
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *  This file implements the mtxxxx emi setting
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
 * 	Enable EMI clock off by default
 *
 * removed!
 * removed!
 * 	temp disable EMI fine clock off because of power saving issue
 *
 * removed!
 * removed!
 * 	fix EMI clock off feature
 *
 * removed!
 * removed!
 * 1.add EMI/RAMC fine clock off feature
 * 2.update initial dram
 * 3.enable SSC with -8%
 *
 * removed!
 * removed!
 * 	SW patch for HK FT DRAMC AFIFO Issue
 * 	We retry to initialize DRAM because of DRAM AFIFO Issue
 *
 * removed!
 * removed!
 * 	Update SLT loader Macro: __IC_SLT__ change to __IC_SLT_LOADER__
 * 	Update SLT DRAMC Test Cases
 *
 * removed!
 * removed!
 * 	Update SLT loader Macro: __IC_SLT__ change to __IC_SLT_LOADER__
 * 	Update SLT DRAMC Test Cases
 *
 * removed!
 * removed!
 * initial dram always inverts o_ck and then disable o_ck inverse when accessing dram
 *
 * removed!
 * removed!
 * add E1 DRAMC AFIFO SW patch for trying initial DRAM
 *
 * removed!
 * removed!
 * 	revert o_ck inverse patch
 *
 * removed!
 * removed!
 * 	Add DRAMC SLT test cases
 *
 * removed!
 * removed!
 * 1. Enable MT6290E1 DRAMC AFIFO S/W Patch
 * 2. Set PMIC Vcore Voltage as 1.15v on MT6290E1 EVB
 *
 * removed!
 * removed!
 * 1. Add compile flag for sync to FlashTool and HVT
 *
 * removed!
 * removed!
 * 1. disable MT6290M E1 SW patch of DRAMC AFIFO Issue
 *
 * removed!
 * removed!
 * 1. We always invert o_ck to add SW patch
 * 2. fix compile warning for mt_emi.c
 *
 * removed!
 * removed!
 * add EMI Data transfer overhead feature for moly
 *
 * removed!
 * removed!
 * add AFIFO issue sw patch for MT6290E1.
 * initializing dram with non-invert clock at first.
 * If initializing failed, initializing dram with invert clock.
 *
 * removed!
 * removed!
 * add get dram info function in bootloader
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
 * update dram init for fixing to set ramc reorder function
 *
 * removed!
 * removed!
 * 1. add MR4 refresh rate update and derating ac timing
 * 2. add to set ap offset
 * 3. add dramc ssc
 *
 * removed!
 * removed!
 * update auto calibration code for MT6290M and MT6290
 *
 * removed!
 * removed!
 * fix dramc auto-k
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
/* ============================= */
/*   Included Files              */
/* ============================= */
#include "bl_dramc_drv.h"
#include "mtk_pll.h"
#include "dramc_calib.h"
#include "mt_emi.h"
#include "dcl.h"
#if defined(__IC_SLT_LOADER__)
#include "slt_dramc.h"
#endif

/* ============================= */
/*   Definitions                 */
/* ============================= */
#define HW_VERSION      (0x80000000+0x0)
#define SW_VERSION      (0x80000000+0x4)
#define HW_CODE_VERSION (0x80000000+0x8)
#define TOPMISC_DUMMY   (BASE_ADDR_TOPMISC+0x01D4)
#define CHIP_CONFIG_0   (BASE_ADDR_MDCFGCTL + 0xFF00)
    #define CHIP_CONFIG_0_BOPT_SIP      (1 << 31)

/* ============================= */
/*   Global Variables            */
/* ============================= */
unsigned int is_mt6290m;
#if defined(BL_ENABLE)
extern const LOG_LEVEL bootloader_debug_level;
#elif defined(__DOWNLOAD_AGENT__)
const RAMC_LOG_LEVEL bootloader_debug_level = LOG_INFO;
#else
const RAMC_LOG_LEVEL bootloader_debug_level = LOG_ERROR;
#endif

/* ============================= */
/*   Internal Functions          */
/* ============================= */
static void print_DBG_info(void)
{
    unsigned int addr;

    if (LOG_DEBUG == bootloader_debug_level) {
        BL_PRINT(LOG_DEBUG, "=====================DBG=====================\r\n");

        for(addr = 0x0; addr < 0x694; addr += 4){
            BL_PRINT(LOG_DEBUG, "addr:%x, value:%x\r\n",addr, DRV_Reg32(DRAMC_base+addr));
        }
        BL_PRINT(LOG_DEBUG, "=============================================\r\n");
    }
}

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

/* ============================= */
/*   External Functions          */
/* ============================= */
/*************************************************************************
* FUNCTION
*  drv_ramc_get_dram_info()
*
* DESCRIPTION
*   This routine aims to get EMI and DRAM information
*
* PARAMETERS
*  struct of drv_ramc_dram_info_t
*
* RETURNS
*  DRAM Size
*
*************************************************************************/
unsigned int drv_ramc_get_dram_info(drv_ramc_dram_info_t * drv_ramc_dram_info)
{
	unsigned int emi_cona, emi_rmpuv, size;
    drv_ramc_dram_info_t ramc_dram_info;
    drv_ramc_dram_info_t * p_ramc_dram_info;

    if (drv_ramc_dram_info) {
        p_ramc_dram_info = drv_ramc_dram_info;
    } else {
        p_ramc_dram_info = &ramc_dram_info;
    }

	emi_cona = DRV_Reg32(EMI_CONA);
    emi_rmpuv = DRV_Reg32(EMI_RMPUV);
	p_ramc_dram_info->dual_rank = (0 + ((emi_cona>>17)& 0x01));
	p_ramc_dram_info->row_num = (12 + ((emi_cona>>12)& 0x03));
	p_ramc_dram_info->bank_num = (2 + ((emi_cona>>8)& 0x01));
	p_ramc_dram_info->col_num = (8 + ((emi_cona>>4)& 0x03));
	p_ramc_dram_info->bus_width = (1 + ((emi_cona>>1)& 0x01));
	p_ramc_dram_info->apmcu_ofst = (emi_rmpuv & 0xFFFF) << 17;
	p_ramc_dram_info->apperi_ofst = ((emi_rmpuv >> 16) & 0xFFFF) << 17;
	size = 1<<(p_ramc_dram_info->dual_rank + p_ramc_dram_info->row_num + p_ramc_dram_info->bank_num + p_ramc_dram_info->col_num + p_ramc_dram_info->bus_width);
	
	return size;
}

/*
 * mt_set_emi: Set up EMI/DRAMC.
 * Return: return result
 *      - zero means successful
 */
dramc_cal_err_code mt_set_emi (void)
{
    unsigned int val;
    dramc_cal_err_code result = DRAMC_CAL_PASS;

    if (((DRV_Reg32(HW_CODE_VERSION) == 0x00006290) && (DRV_Reg32(CHIP_CONFIG_0) & CHIP_CONFIG_0_BOPT_SIP))) {
        is_mt6290m = TRUE;
    } else {
        is_mt6290m = FALSE;
    }
    //*** Init MEMPLL and do calibration.
    result = mt_pll_init();
    if (0 != result) {
        BL_PRINT(LOG_ERROR, "[EMI] MEMPLL calibration failed with %x\n\r", result);
        goto __end;
    }
    #if DRAMC_LOAD_BOARD_TEST
    DclGPIO_Control(slt_dramc_gpio[slt_dramc_gpio_idx++], GPIO_CMD_WRITE_HIGH, 0);
    #endif

    #if defined(MT6290_DEMO_BB)
    // MT6290E1 workaround
    if ((is_mt6290m == FALSE) && (DRV_Reg32(HW_CODE_VERSION) == 0x00006290) && (DRV_Reg32(HW_VERSION) == 0x0000CA00)) {
        DRV_WriteReg32_NPW(TOPMISC_DUMMY, DRV_Reg32(TOPMISC_DUMMY) | 0x00010000);
        /* Because of MT6290 EVB IR drop & DRAMC AFIFO issue, we need to change PMIC Vcore Setting to 1.15v */
        DCL_HANDLE handle;
        PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
        val.mod=VCORE;
        val.voltage = PMU_VOLT_01_150000_V;
        /*  PMU_VOLT_00_700000_V, PMU_VOLT_00_725000_V, PMU_VOLT_00_750000_V, PMU_VOLT_00_775000_V,
            PMU_VOLT_00_800000_V, PMU_VOLT_00_825000_V, PMU_VOLT_00_850000_V, PMU_VOLT_00_875000_V,
            PMU_VOLT_00_900000_V, PMU_VOLT_00_925000_V, PMU_VOLT_00_950000_V, PMU_VOLT_00_975000_V,
            PMU_VOLT_01_000000_V, PMU_VOLT_01_025000_V, PMU_VOLT_01_050000_V, PMU_VOLT_01_075000_V,
            PMU_VOLT_01_100000_V, PMU_VOLT_01_125000_V, PMU_VOLT_01_150000_V, PMU_VOLT_01_175000_V,
            PMU_VOLT_01_200000_V, PMU_VOLT_01_225000_V, PMU_VOLT_01_250000_V, PMU_VOLT_01_275000_V,
            PMU_VOLT_01_300000_V, PMU_VOLT_01_325000_V, PMU_VOLT_01_350000_V, PMU_VOLT_01_375000_V,      
            PMU_VOLT_01_400000_V, PMU_VOLT_01_425000_V, PMU_VOLT_01_450000_V, PMU_VOLT_01_475000_V, */
        DclPMU_Initialize();
        handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
        DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
        DclPMU_Close(handle);
    }
    #endif

    //*** DRAM init
    custom_InitDRAM();

    //*** Disable Some Functions before dramc calibration
    /* Disable Gating window HW calibration function */
    val = DRV_Reg32(DRAMC_DQSCAL0) & (~(0x1 << 31));
    DRV_WriteReg32(DRAMC_DQSCAL0, val);
    // Disable DRAMC fine clock off
    val = DRV_Reg32(DRAMC_PD_CTRL);
    if ((DRV_Reg32(HW_CODE_VERSION) == 0x00006290) && (DRV_Reg32(HW_VERSION) != 0x0000CA00)) { // MT6290(M), Not E1
        val &= ~DRAMC_PD_CTRL_DCMEN; 
    }
    DRV_WriteReg32(DRAMC_PD_CTRL /* 0x01DC */, val);
    // Disable EMI fine clock off
    UNLOCK_EMI_REG();
    val = DRV_Reg32(EMI_TESTC_1);
    if ((DRV_Reg32(HW_CODE_VERSION) == 0x00006290) && (DRV_Reg32(HW_VERSION) != 0x0000CA00)) { // MT6290(M), Not E1
        val &= ~0x80000000; // EMI fine clock off
    }
    DRV_WriteReg32(EMI_TESTC_1 /* 0x30F4 */, val);
    LOCK_EMI_REG();
    /* Disable R/W out of order function */
    UNLOCK_EMI_REG();
    DRV_WriteReg32(EMI_ARBT, 0x00000000);
    DRV_WriteReg32(EMI_ARBU, 0x00000000);
    DRV_WriteReg32(EMI_ARBV, 0x00000000);
    LOCK_EMI_REG();
    // EMI function related, utilization performance, r/w re-odering
    val = DRV_Reg32(DRAMC_PERFCTL0) & (~(DRAMC_PERFCTL0_RWAGEEN | \
                DRAMC_PERFCTL0_RWLLATEN | DRAMC_PERFCTL0_RWHPRIEN | \
                DRAMC_PERFCTL0_RWOFEN));
    DRV_WriteReg32(DRAMC_PERFCTL0, val);
    // disable MR4 Refresh Rate Update
    val = DRV_Reg32(DRAMC_ACTIM1 /* 0x1e8 */) & ~(DRAMC_ACTIM1_REFRCNT_MASK);
    DRV_WriteReg32_NPW(DRAMC_ACTIM1 /* 0x1e8 */, val);

    Data_Mem_Barrier();

    print_DBG_info();

    //*** Do calibration
    /* TO-BE-Porting for Combo MCP*/
    /* may not used in 6589*/
    /* To-Be-Porting should be enable in real chip*/
    /* DRAMC calibration */
    #if defined(MT6290_PDB)
    DCL_HANDLE handle;
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE pmic_vcore;
    pmic_vcore.mod = VCORE;
    pmic_vcore.voltage = PMU_VOLT_01_050000_V;
    DclPMU_Initialize();
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    while (1) {
        result = dramc_calib();
        if (DRAMC_CAL_FAIL <= result) {
            // MT6290E1 workaround
            if ((DRV_Reg32(HW_CODE_VERSION) == 0x00006290) && (DRV_Reg32(HW_VERSION) == 0x0000CA00)) {
                if (PMU_VOLT_01_050000_V == pmic_vcore.voltage) {
                    pmic_vcore.voltage = PMU_VOLT_01_100000_V;
                } else {
                    pmic_vcore.voltage = PMU_VOLT_01_050000_V;
                }
                /*  PMU_VOLT_00_700000_V, PMU_VOLT_00_725000_V, PMU_VOLT_00_750000_V, PMU_VOLT_00_775000_V,
                    PMU_VOLT_00_800000_V, PMU_VOLT_00_825000_V, PMU_VOLT_00_850000_V, PMU_VOLT_00_875000_V,
                    PMU_VOLT_00_900000_V, PMU_VOLT_00_925000_V, PMU_VOLT_00_950000_V, PMU_VOLT_00_975000_V,
                    PMU_VOLT_01_000000_V, PMU_VOLT_01_025000_V, PMU_VOLT_01_050000_V, PMU_VOLT_01_075000_V,
                    PMU_VOLT_01_100000_V, PMU_VOLT_01_125000_V, PMU_VOLT_01_150000_V, PMU_VOLT_01_175000_V,
                    PMU_VOLT_01_200000_V, PMU_VOLT_01_225000_V, PMU_VOLT_01_250000_V, PMU_VOLT_01_275000_V,
                    PMU_VOLT_01_300000_V, PMU_VOLT_01_325000_V, PMU_VOLT_01_350000_V, PMU_VOLT_01_375000_V,      
                    PMU_VOLT_01_400000_V, PMU_VOLT_01_425000_V, PMU_VOLT_01_450000_V, PMU_VOLT_01_475000_V, */
                DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&pmic_vcore);
                val = DRV_Reg32(DRAMC_MISCTL0 /* 0x00fc */) & ~DRAMC_MISCTL0_ASYNCEN;
                DRV_WriteReg32(DRAMC_MISCTL0 /* 0x00fc */, val);
                val |= DRAMC_MISCTL0_ASYNCEN;
                DRV_WriteReg32(DRAMC_MISCTL0 /* 0x00fc */, val);
            } else {
                BL_PRINT(LOG_ERROR, "[EMI] DRAMC calibration failed with %x\n\r", result);
                goto __end;
            }
        } else {
            BL_PRINT(LOG_INFO, "[EMI] DRAMC calibration passed\n\r");
            DclPMU_Close(handle);
            break;
        }
    }
    #else
    result = dramc_calib();
    if (DRAMC_CAL_FAIL <= result) {
        BL_PRINT(LOG_ERROR, "[EMI] DRAMC calibration failed with %x\n\r", result);
        goto __end;
    } else {
        BL_PRINT(LOG_INFO, "[EMI] DRAMC calibration passed\n\r");
    }
    #endif

#ifdef USE_DUAL_RANK_DDR
    //*** The following code is only for dual ranks.
    if ( DRV_Reg32(EMI_CONA)&EMI_CONA_DUAL_RANK_EN)      // Check dual ranks.
    {
        /*For 2RANK: Set RANKINCTL (REG.1C4[19:16]) = DQSINCTL + 2*/
        val = DRV_Reg32(DRAMC_DQSCTL1) & DRAMC_DQSCTL1_DQSINCTL_MASK;
        val = ((val >> 24)+2) <<16; 
        BL_PRINT(LOG_INFO, "[EMI] DQSINCTL:%x\n\r",val);
        val = (DRV_Reg32(DRAMC_DQSCAL1) & 0xFFF0FFFF) | val;
        DRV_WriteReg32(DRAMC_DQSCAL1, val);
    }
#endif // end of USE_DUAL_RANK_DDR

    //*** Enable Some Functions after dramc calibration
    /* Enable Gating window HW calibration function */
    val = (DRV_Reg32(DRAMC_DQSCAL0) & 0x7FFFFFFF) | (0x1 << 31);
    DRV_WriteReg32(DRAMC_DQSCAL0, val);
    // Enable DRAMC fine clock off
    val = DRV_Reg32(DRAMC_PD_CTRL);
    if ((DRV_Reg32(HW_CODE_VERSION) == 0x00006290) && (DRV_Reg32(HW_VERSION) != 0x0000CA00)) { // MT6290(M), Not E1
        val |= DRAMC_PD_CTRL_DCMEN; 
    }
    DRV_WriteReg32(DRAMC_PD_CTRL /* 0x01DC */, val);
    // Enable EMI fine clock off
    UNLOCK_EMI_REG();
    val = DRV_Reg32(EMI_TESTC_1);
    if ((DRV_Reg32(HW_CODE_VERSION) == 0x00006290) && (DRV_Reg32(HW_VERSION) != 0x0000CA00)) { // MT6290(M), Not E1
        val |= 0x80000000; // EMI fine clock off
    }
    DRV_WriteReg32(EMI_TESTC_1 /* 0x30F4 */, val);
    LOCK_EMI_REG();
    /* Enable R/W out of order function */
    UNLOCK_EMI_REG();
    DRV_WriteReg32(EMI_ARBT, 0x00000003);
    DRV_WriteReg32(EMI_ARBU, 0x0000003F);
    DRV_WriteReg32(EMI_ARBV, 0x0000003F);
    LOCK_EMI_REG();
    // EMI function related, utilization performance, r/w re-odering
    val = (DRV_Reg32(DRAMC_PERFCTL0) & (~(DRAMC_PERFCTL0_RWAGEEN | \
                DRAMC_PERFCTL0_RWLLATEN | DRAMC_PERFCTL0_RWHPRIEN | \
                DRAMC_PERFCTL0_RWOFEN))) | DRAMC_PERFCTL0_RWAGEEN | \
                DRAMC_PERFCTL0_RWLLATEN | DRAMC_PERFCTL0_RWHPRIEN | \
                DRAMC_PERFCTL0_RWOFEN;
    DRV_WriteReg32(DRAMC_PERFCTL0, val);
    // Enable MR4 Refresh Rate Update
    DRV_WriteReg32(DRAMC_MRS /* 0x88 */, DRAMC_MRS_MA(4));
    val = DRV_Reg32(DRAMC_ACTIM1 /* 0x1e8 */) & ~(DRAMC_ACTIM1_REFRCNT_MASK);
    val |= DRAMC_ACTIM1_REFRCNT(1);
    DRV_WriteReg32_NPW(DRAMC_ACTIM1 /* 0x1e8 */, val);

    Data_Mem_Barrier();

    /* Enable MEMPLL Spread Spectrum */
    mt_mempll_ssc();

    print_DBG_info();

__end:
    return result;
}

