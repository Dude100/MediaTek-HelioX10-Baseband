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
 *   custom_emi.c
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *  This file implements custom EMI
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
 * 	EMI Arbitration Setting
 *
 * removed!
 * removed!
 * *: Update EMI arbitration parameters for SZFT. This is an urgent and temporary soluton.
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
 * initial dram always inverts o_ck and then disable o_ck inverse when accessing dram
 *
 * removed!
 * removed!
 * 	Update DRAMC Setting for Power Saving about PADRGEN
 * 	Update EMI Setting for LMAC Underflow
 *
 * removed!
 * removed!
 * 1. fix MT6290M MRR SW PATCH
 *
 * removed!
 * removed!
 * 1. Add compile flag for sync to FlashTool and HVT
 *
 * removed!
 * removed!
 * 1.add auto cke power down
 * 2.disable DRAMC clk 1 for MT6290(m)
 *
 * removed!
 * removed!
 * add EMI Data transfer overhead feature for moly
 *
 * removed!
 * removed!
 * disable M5 early response and Order-Tuning feature
 *
 * removed!
 * removed!
 * update dram init for different frequency
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
/* ======================== */
/*   Include Header Files   */
/* ======================== */
#include "bl_dramc_drv.h"
#include "custom_EMI_INFO.h"
#include "custom_emi_offset.h"

/* ======================== */
/*   Definitions            */
/* ======================== */
#define HW_VERSION      (0x80000000+0x0)
#define SW_VERSION      (0x80000000+0x4)
#define HW_CODE_VERSION (0x80000000+0x8)
#define TOPMISC_DUMMY   (BASE_ADDR_TOPMISC+0x01D4)

#define DRAMC_SEND_SPCMD(val)   \
do {    \
    DRV_WriteReg32(DRAMC_SPCMD, val);   \
    while(val != (DRV_Reg32(DRAMC_SPCMDRESP) & 0x3F));  \
    DRV_WriteReg32(DRAMC_SPCMD, 0); \
    while(0 != (DRV_Reg32(DRAMC_SPCMDRESP) & 0x3F));    \
} while (0)

#ifdef __EMI_DEVICE_LPDDR2__
#define DRAMC_MRW(addr, op) \
    do {                        \
        DRV_WriteReg32(DRAMC_MRS, DRAMC_MRS_OP(op) | DRAMC_MRS_MA(addr));   \
        DRV_WriteReg32(DRAMC_SPCMD, DRAMC_SPCMD_MRWEN);                     \
        while(!(DRV_Reg32(DRAMC_SPCMDRESP) & DRAMC_SPCMD_MRWEN));           \
        DRV_WriteReg32(DRAMC_SPCMD, 0x0);                                   \
        while(DRV_Reg32(DRAMC_SPCMDRESP) & DRAMC_SPCMD_MRWEN);              \
    } while(0)

#define DRAMC_MRR_MT6290M_SW_PATCH_BIT_SWAP(val, tmp)   \
    do {    \
        tmp = val;  \
        val = 0;    \
        val |= (tmp & 0x01) << 3;   \
        val |= (tmp & 0x02) << 1;   \
        val |= (tmp & 0x0c) >> 2;   \
        val |= (tmp & 0x30) << 2;   \
        val |= (tmp & 0xc0) >> 2;   \
    } while(0)

#define DRAMC_MRR(addr, op) \
    do {                    \
        register unsigned int tmp_val;                                  \
        DRV_WriteReg32(DRAMC_MRS, DRAMC_MRS_MA(addr));                  \
        DRV_WriteReg32(DRAMC_SPCMD, DRAMC_SPCMD_MRREN);                 \
        while(!(DRV_Reg32(DRAMC_SPCMDRESP) & DRAMC_SPCMD_MRREN));       \
        op = (DRV_Reg32(DRAMC_SPCMDRESP) >> 24);                        \
        if (((DRV_Reg32(HW_CODE_VERSION) == 0x00006290) && (DRV_Reg32(CHIP_CONFIG_0) & CHIP_CONFIG_0_BOPT_SIP))) {  \
            DRAMC_MRR_MT6290M_SW_PATCH_BIT_SWAP(op, tmp_val);           \
        }                                                               \
        DRV_WriteReg32(DRAMC_SPCMD, 0x0);                               \
        while(DRV_Reg32(DRAMC_SPCMDRESP) & DRAMC_SPCMD_MRREN);          \
    } while(0)
#elif defined(__EMI_DEVICE_LPDDR1__)
#define DRAMC_MRW(ba, addr) \
    do {                    \
        DRV_WriteReg32(DRAMC_MRS, DRAMC_MRS_BA(ba) | DRAMC_MRS_MA(addr));                   \
        DRV_WriteReg32(DRAMC_SPCMD, DRAMC_SPCMD_MRWEN);                 \
        while(!(DRV_Reg32(DRAMC_SPCMDRESP) & DRAMC_SPCMD_MRWEN));       \
        DRV_WriteReg32(DRAMC_SPCMD, 0x0);                               \
        while(DRV_Reg32(DRAMC_SPCMDRESP) & DRAMC_SPCMD_MRWEN);          \
    }while(0)
#endif // end of defined(__EMI_DEVICE_LPDDR1__)

enum {
    DRAM_VENDER_ID_ELPIDA = 0x03,
    DRAM_VENDER_ID_AP = 0xfd,
    DRAM_VENDER_ID_MICRON = 0xff,
    DRAM_VENDER_ID_END
} dram_vender_id;

/*************************************
  *
  * Imported APIs.
  *
  *************************************/


/*************************************
  *
  * Global Variables.
  *
  *************************************/
static unsigned int mcp_dram_idx = 0;
extern MTK_EMI_Info EMI_INFO[];
extern unsigned int is_mt6290m;

/*************************************************************************
* FUNCTION
*  custom_Init_EMIARB()
*
* DESCRIPTION
*   This routine aims to configure EMI Arbitration Seeting
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int32 custom_Init_EMIARB(void)
{

#if defined (MT6290)
	UNLOCK_EMI_REG();
	// Data transfer overhead
	DRV_WriteReg32(EMI_CONB /* 0x3008 */, 0x42656FAD);
	DRV_WriteReg32(EMI_CONC /* 0x3010 */, 0x313E3857);
	DRV_WriteReg32(EMI_COND /* 0x3018 */, 0x42656FAD);
	DRV_WriteReg32(EMI_CONE /* 0x3020 */, 0x313E3857);

	// BWL Setting
	DRV_WriteReg32(EMI_ARBA /* 0x3100 */, 0x0505303F);
	DRV_WriteReg32(EMI_ARBB /* 0x3108 */, 0xFFFF1002);
	DRV_WriteReg32(EMI_ARBC /* 0x3110 */, 0xFFFF1000);
	DRV_WriteReg32(EMI_ARBD /* 0x3118 */, 0xFFFF1000);
	DRV_WriteReg32(EMI_ARBE /* 0x3120 */, 0x32FF1010);
	DRV_WriteReg32(EMI_ARBF /* 0x3128 */, 0xFFFF1013);

	// Favor Ultra Signal priority (bit 7)
	DRV_WriteReg32(EMI_ARBI /* 0x3140 */, DRV_Reg32(EMI_ARBI) | (1 << 7));
	// Age priority (bit6)
	DRV_WriteReg32(EMI_ARBI /* 0x3140 */, DRV_Reg32(EMI_ARBI) | (1 << 14));
	// BWL priority (bit5)
	DRV_WriteReg32(EMI_ARBI /* 0x3140 */, DRV_Reg32(EMI_ARBI) | (1 << 21));
	// Page Hit priority (bit3)
	DRV_WriteReg32(EMI_ARBI /* 0x3140 */, DRV_Reg32(EMI_ARBI) | (1 << 27));
	// Page Miss priority (bit2)
	DRV_WriteReg32(EMI_ARBI_1 /* 0x3144 */, DRV_Reg32(EMI_ARBI_1) | (1 << 2));
	// Page Urgent priority (bit4)
	DRV_WriteReg32(EMI_ARBI_1 /* 0x3144 */, DRV_Reg32(EMI_ARBI_1) | (1 << 12));
	// Distant priority (bit1)
	DRV_WriteReg32(EMI_ARBI_1 /* 0x3144 */, DRV_Reg32(EMI_ARBI_1) | (1 << 17));

	// High Priority Layer Setting
	DRV_WriteReg32(EMI_ARBV /* 0x3210 */, 0x00000000);

	// Urgent Threshold
	DRV_WriteReg32(EMI_ARBO /* 0x3178 */, 0x000002B0);
	
	// Page Miss Control
	DRV_WriteReg32(EMI_ARBK /* 0x3150 */, 0x0000000F);

	LOCK_EMI_REG();
#endif

	return 0;
}

/*************************************************************************
* FUNCTION
*  custom_InitDRAM()
*
* DESCRIPTION
*   This routine aims to set EMI and initialize LPSDRAM
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int8 custom_InitDRAM(void)
{
    unsigned int reg_val;
    
    #if defined __EMI_DEVICE_LPDDR1__
    #if defined __FPGA__
    DRV_WriteReg32(BASE_ADDR_MDCLKCTL + 0x4000, 0x00000A00);
    DRV_WriteReg32(DRAMC_ACTIM0, EMI_INFO[mcp_dram_idx].dramc_actim0_val);
    DRV_WriteReg32(DRAMC_CONF1, EMI_INFO[mcp_dram_idx].dramc_conf1_val);
    DRV_WriteReg32(DRAMC_DLLCONF, 0x00200000);
    DRV_WriteReg32(DRAMC_TEST2_3, EMI_INFO[mcp_dram_idx].dramc_test2_3_val);
    DRV_WriteReg32(DRAMC_DDR2CTL, EMI_INFO[mcp_dram_idx].dramc_ddr2ctl_val);
    DRV_WriteReg32(DRAMC_IOCTL, 0x80000000);
    DRV_WriteReg32(DRAMC_DQSCTL1, 0x11000000);
    DRV_WriteReg32(DRAMC_MISCTL0, EMI_INFO[mcp_dram_idx].dramc_misctl0_val);
    DRV_WriteReg32(DRAMC_DQSGCTL, 0x80000000);
    DRV_WriteReg32(DRAMC_CLKENCTL, 0x30000000);
    DRV_WriteReg32(DRAMC_LPDDR2, 0x44000000);
    DRV_WriteReg32(DRAMC_ACTIM1, EMI_INFO[mcp_dram_idx].dramc_actim1_val);
    DRV_WriteReg32(DRAMC_RKCFG, 0x00051107);
    DRV_WriteReg32(DRAMC_PADCTL4, 0x00000004);
    BL_GPT_UDELAY(200);
    DRAMC_SEND_SPCMD(0x00000004);
    DRAMC_SEND_SPCMD(0x00000008);
    DRAMC_SEND_SPCMD(0x00000008);
    DRV_WriteReg32(DRAMC_MRS, 0x00000032);
    DRAMC_SEND_SPCMD(0x00000001);
    DRV_WriteReg32(DRAMC_MRS, 0x00004000);
    DRAMC_SEND_SPCMD(0x00000001);
    DRV_WriteReg32(DRAMC_PADCTL4, 0x00000000);
    DRV_WriteReg32_NPW(DRAMC_CONF2, EMI_INFO[mcp_dram_idx].dramc_conf2_val);

    UNLOCK_EMI_REG();
    DRV_WriteReg32(EMI_CONA, EMI_INFO[mcp_dram_idx].emi_cona_val);
    DRV_WriteReg32(EMI_CONM, 0x00000400);
    DRV_WriteReg32(EMI_TESTD, EMI_INFO[mcp_dram_idx].emi_testd_val);

    // Unit is 128KB.
    reg_val = EMI_RMPUV_APPERI_OFFSET(EMI_APPERI_OFFSET >> 17) | EMI_RMPUV_APMCU_OFFSET(EMI_APMCU_OFFSET >> 17);
    DRV_WriteReg32(EMI_RMPUV, reg_val);

    LOCK_EMI_REG();
    #endif // end if defined __FPGA__
    #elif defined __EMI_DEVICE_LPDDR2__
    DRV_WriteReg32(DRAMC_ACTIM0 /* 0x0000 */, EMI_INFO[mcp_dram_idx].dramc_actim0_val);
    DRV_WriteReg32(DRAMC_CONF1 /* 0x0004 */, EMI_INFO[mcp_dram_idx].dramc_conf1_val);
    reg_val = DRV_Reg32(DRAMC_PADCTL1) & ~(DRAMC_PADCTL1_CLKDLY_MASK | DRAMC_PADCTL1_CS1DLY_MASK);
    reg_val |= DRAMC_PADCTL1_CLKDLY(EMI_INFO[mcp_dram_idx].dramc_clkodly_val);
    reg_val |= DRAMC_PADCTL1_CS1DLY(EMI_INFO[mcp_dram_idx].dramc_addrodly_val);
    DRV_WriteReg32(DRAMC_PADCTL1 /* 0x000c */, reg_val);
    DRV_WriteReg32(DRAMC_PADCTL2 /* 0x0010 */, EMI_INFO[mcp_dram_idx].dramc_dqodly_val);
    DRV_WriteReg32(DRAMC_PADCTL3 /* 0x0014 */, EMI_INFO[mcp_dram_idx].dramc_dqsodly_val);
    DRV_WriteReg32(DRAMC_R0DELDLY /* 0x0018 */, 0x44444444);
    DRV_WriteReg32(DRAMC_DLLCONF /* 0x0028 */, 0x50200000);
    DRV_WriteReg32(DRAMC_TEST2_3 /* 0x0044 */, EMI_INFO[mcp_dram_idx].dramc_test2_3_val);
    #if defined __FPGA__
    DRV_WriteReg32(DRAMC_DDR2CTL /* 0x007C */, 0x20001161);
    #else // if !defined __FPGA__
    DRV_WriteReg32(DRAMC_DDR2CTL /* 0x007C */, EMI_INFO[mcp_dram_idx].dramc_ddr2ctl_val);
    #endif // end if defined __FPGA__
    DRV_WriteReg32(DRAMC_DRVCTL0 /* 0x00B8 */, EMI_INFO[mcp_dram_idx].dramc_drvctl0_val);
    DRV_WriteReg32(DRAMC_DRVCTL1 /* 0x00BC */, EMI_INFO[mcp_dram_idx].dramc_drvctl1_val);
    #if defined __FPGA__
    DRV_WriteReg32(DRAMC_DQSCTL1 /* 0x00E0 */, 0x11000000);
    #else // if !defined __FPGA__
    DRV_WriteReg32(DRAMC_DQSCTL1 /* 0x00E0 */, 0x12000000);
    #endif // end if defined __FPGA__
    DRV_WriteReg32(DRAMC_GDDR3CTL1 /* 0x00F4 */, EMI_INFO[mcp_dram_idx].dramc_gddr3ctl1_val);
    DRV_WriteReg32(DRAMC_MISCTL0 /* 0x00FC */, EMI_INFO[mcp_dram_idx].dramc_misctl0_val);
    DRV_WriteReg32(DRAMC_RKCFG /* 0x0110 */, 0x00051107);
    #if defined __FPGA__
    DRV_WriteReg32(DRAMC_DQSGCTL /* 0x0124 */, 0x800000FF);
    #else // if !defined __FPGA__
    DRV_WriteReg32(DRAMC_DQSGCTL /* 0x0124 */, 0x80000055);
    #endif // end if defined __FPGA__
    if (TRUE == is_mt6290m) {
        DRV_WriteReg32(DRAMC_CLKENCTL /* 0x0130 */, 0x20000000);
    } else {
        DRV_WriteReg32(DRAMC_CLKENCTL /* 0x0130 */, 0x10000000);
    }
    DRV_WriteReg32(DRAMC_CMDDLY0 /* 0x01A8 */, 
        DRAMC_CMDDLY(RA0DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val) |
        DRAMC_CMDDLY(RA1DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val) |
        DRAMC_CMDDLY(RA2DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val) |
        DRAMC_CMDDLY(RA3DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val)
        );
    DRV_WriteReg32(DRAMC_CMDDLY1 /* 0x01AC */, 
        DRAMC_CMDDLY(RA4DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val) |
        DRAMC_CMDDLY(RA5DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val) |
        DRAMC_CMDDLY(RA6DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val) |
        DRAMC_CMDDLY(RA7DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val)
        );
    DRV_WriteReg32(DRAMC_CMDDLY2 /* 0x01B0 */, 
        DRAMC_CMDDLY(RA8DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val) |
        DRAMC_CMDDLY(RA9DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val) |
        DRAMC_CMDDLY(RA10DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val) |
        DRAMC_CMDDLY(RA11DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val)
        );
    DRV_WriteReg32(DRAMC_CMDDLY3 /* 0x01B4 */, 
        DRAMC_CMDDLY(RA12DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val) |
        DRAMC_CMDDLY(BA0DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val) |
        DRAMC_CMDDLY(BA1DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val) |
        DRAMC_CMDDLY(BA2DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val)
        );
    DRV_WriteReg32(DRAMC_CMDDLY4 /* 0x01B8 */, 
        DRAMC_CMDDLY(CSDLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val) |
        DRAMC_CMDDLY(CKEDLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val) |
        DRAMC_CMDDLY(RASDLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val) |
        DRAMC_CMDDLY(CASDLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val)
        );
    DRV_WriteReg32(DRAMC_CMDDLY5 /* 0x01BC */, 
        DRAMC_CMDDLY(RESETDLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val) |
        DRAMC_CMDDLY(WEDLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val) |
        DRAMC_CMDDLY(RA13DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val) |
        DRAMC_CMDDLY(ODTDLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val)
        );
    reg_val = DRV_Reg32(DRAMC_DQSCAL0) & ~(DRAMC_CMDDLY_RA14DLY_MASK | DRAMC_CMDDLY_RA15DLY_MASK);
    reg_val |= DRAMC_CMDDLY(RA14DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val);
    reg_val |= DRAMC_CMDDLY(RA15DLY, EMI_INFO[mcp_dram_idx].dramc_addrodly_val);
    DRV_WriteReg32(DRAMC_DQSCAL0 /* 0x01C0 */, reg_val);
    DRV_WriteReg32(DRAMC_PD_CTRL /* 0x01DC */, EMI_INFO[mcp_dram_idx].dramc_pd_ctrl_val);
    #if defined __FPGA__
    DRV_WriteReg32(DRAMC_LPDDR2 /* 0x01E0 */, 0x100003FF);
    #else // if !defined __FPGA__
    if (TRUE == is_mt6290m) {
        DRV_WriteReg32(DRAMC_LPDDR2 /* 0x01E0 */, 0x100003FF);
    } else {
        DRV_WriteReg32(DRAMC_LPDDR2 /* 0x01E0 */, 0x1004fbc0);
    }
    #endif // end if defined __FPGA__
    DRV_WriteReg32(DRAMC_ACTIM1 /* 0x01E8 */, EMI_INFO[mcp_dram_idx].dramc_actim1_val);
    DRV_WriteReg32(DRAMC_PERFCTL0 /* 0x01EC */, 0x00000001);
    reg_val = (EMI_INFO[mcp_dram_idx].dramc_dqodly_val>>0)&0xf;
    DRV_WriteReg32(DRAMC_DQODLY(0) /* 0x0200 */, 
        DRAMC_DQnODLY(0, reg_val) |
        DRAMC_DQnODLY(1, reg_val) |
        DRAMC_DQnODLY(2, reg_val) |
        DRAMC_DQnODLY(3, reg_val) |
        DRAMC_DQnODLY(4, reg_val) |
        DRAMC_DQnODLY(5, reg_val) |
        DRAMC_DQnODLY(6, reg_val) |
        DRAMC_DQnODLY(7, reg_val)
        );
    reg_val = (EMI_INFO[mcp_dram_idx].dramc_dqodly_val>>4)&0xf;
    DRV_WriteReg32(DRAMC_DQODLY(1) /* 0x0204 */, 
        DRAMC_DQnODLY(8, reg_val) | 
        DRAMC_DQnODLY(9, reg_val) | 
        DRAMC_DQnODLY(10, reg_val) | 
        DRAMC_DQnODLY(11, reg_val) | 
        DRAMC_DQnODLY(12, reg_val) | 
        DRAMC_DQnODLY(13, reg_val) | 
        DRAMC_DQnODLY(14, reg_val) | 
        DRAMC_DQnODLY(15, reg_val)
        );
    reg_val = (EMI_INFO[mcp_dram_idx].dramc_dqodly_val>>8)&0xf;
    DRV_WriteReg32(DRAMC_DQODLY(2) /* 0x0208*/, 
        DRAMC_DQnODLY(16, reg_val) | 
        DRAMC_DQnODLY(17, reg_val) | 
        DRAMC_DQnODLY(18, reg_val) | 
        DRAMC_DQnODLY(19, reg_val) | 
        DRAMC_DQnODLY(20, reg_val) | 
        DRAMC_DQnODLY(21, reg_val) | 
        DRAMC_DQnODLY(22, reg_val) | 
        DRAMC_DQnODLY(23, reg_val)
        );
    reg_val = (EMI_INFO[mcp_dram_idx].dramc_dqodly_val>>12)&0xf;
    DRV_WriteReg32(DRAMC_DQODLY(3) /* 0x020c */, 
        DRAMC_DQnODLY(24, reg_val) | 
        DRAMC_DQnODLY(25, reg_val) | 
        DRAMC_DQnODLY(26, reg_val) | 
        DRAMC_DQnODLY(27, reg_val) | 
        DRAMC_DQnODLY(28, reg_val) | 
        DRAMC_DQnODLY(29, reg_val) | 
        DRAMC_DQnODLY(30, reg_val) | 
        DRAMC_DQnODLY(31, reg_val)
        );
    #if !defined __FPGA__
    if (TRUE == is_mt6290m) {
        DRV_WriteReg32(DRAMC_DQSI_SEL /* 0x0158 */, 0x0FF00FF0);
        DRV_WriteReg32(DRAMC_MCKDLY /* 0x00D8 */, 0x00000000);
    } else {
        DRV_WriteReg32(DRAMC_MCKDLY /* 0x00D8 */, 0x40000000);
    }
    #endif // end if defined __FPGA__

    // --------------------------
    //  LPDDR2 Initial Flow
    // --------------------------
    DRV_WriteReg32(DRAMC_PADCTL4, 0x00000004);
    BL_GPT_UDELAY(200);
    DRAMC_MRW(0x3F, 0x0); // MR Reset
    BL_GPT_UDELAY(10);
    DRAMC_MRW(0x0A, 0xFF); // ZQ Init
    BL_GPT_UDELAY(1);
    // workaround for MT6290ME1 SIP DRAM APMEMORY
    if ((TRUE == is_mt6290m) && (0x0000CA00 == DRV_Reg32(HW_VERSION))) {
        DRAMC_MRW(0x0A, 0xFF); // ZQ Init
        BL_GPT_UDELAY(1);
    }
    if (TRUE == is_mt6290m) {
        DRAMC_MRW(0x01, 0x83); // MR1: BL=8, Sequential, wrap, nWR=6
    } else {
        DRAMC_MRW(0x01, 0x82); // MR1: BL=4, Sequential, wrap, nWR=6
    }
    DRAMC_MRW(0x02, EMI_INFO[mcp_dram_idx].dram_lpddr2_mr2_val); // MR2: RL=5/WL=2
    DRAMC_MRW(0x03, EMI_INFO[mcp_dram_idx].dram_lpddr2_mr3_val); // MR3: 40-ohm typical
    DRV_WriteReg32(DRAMC_PADCTL4, EMI_INFO[mcp_dram_idx].dramc_padctl4_val);
    // --------------------------
    //  LPDDR2 Initial Flow
    // --------------------------
    DRV_WriteReg32(DRAMC_CONF2 /* 0x0008 */, EMI_INFO[mcp_dram_idx].dramc_conf2_val);
    reg_val = DRV_Reg32(DRAMC_SPCMD) | DRAMC_SPCMD_PADRGEN;
    DRV_WriteReg32(DRAMC_SPCMD, reg_val);
    DRV_WriteReg32(DRAMC_AC_DERATING /* 0x01F0 */, EMI_INFO[mcp_dram_idx].dram_ac_derating_val);
    if (TRUE == is_mt6290m) {
        reg_val = DRAMC_RRRATE_CTL_RR_BIT2_SEL(14) | DRAMC_RRRATE_CTL_RR_BIT1_SEL(12) | DRAMC_RRRATE_CTL_RR_BIT0_SEL(13);
    } else {
        reg_val = DRAMC_RRRATE_CTL_RR_BIT2_SEL(7) | DRAMC_RRRATE_CTL_RR_BIT1_SEL(2) | DRAMC_RRRATE_CTL_RR_BIT0_SEL(4);
    }
    DRV_WriteReg32(DRAMC_RRRATE_CTL /* 0x01F4 */, reg_val);

    UNLOCK_EMI_REG();
    // Address Mapping
    DRV_WriteReg32(EMI_CONA /* 0x3004 */, EMI_INFO[mcp_dram_idx].emi_cona_val);
    // EMI MISC
    DRV_WriteReg32(EMI_CONM /* 0x3060 */, EMI_CONM_EMI_EN);
    // EMI Test mode D
    DRV_WriteReg32(EMI_TESTD /* 0x30F8 */, EMI_INFO[mcp_dram_idx].emi_testd_val);
    // MT6290E1 workaround
    if ((DRV_Reg32(HW_CODE_VERSION) == 0x00006290) && (DRV_Reg32(HW_VERSION) == 0x0000CA00)) {
        // Early Response
        DRV_WriteReg32(EMI_ARBS /* 0x3198 */, DRV_Reg32(EMI_ARBS) & 0xFFFFFFDF);
    }
    // EMI_RMPU
    DRV_WriteReg32(EMI_RMPUM /* 0x4200 */, 0x10000000);
    DRV_WriteReg32(EMI_RMPUN /* 0x4210 */, 0x10000000);
    DRV_WriteReg32(EMI_RMPUO /* 0x4220 */, 0x10000000);
    DRV_WriteReg32(EMI_RMPUP /* 0x4230 */, 0x10000000);
    DRV_WriteReg32(EMI_RMPUM_1 /* 0x4208 */, 0x10000000);
    DRV_WriteReg32(EMI_RMPUN_1 /* 0x4218 */, 0x10000000);
    DRV_WriteReg32(EMI_RMPUO_1 /* 0x4228 */, 0x10000000);
    DRV_WriteReg32(EMI_RMPUP_1 /* 0x4238 */, 0x10000000);

    // Unit is 128KB.
    reg_val = EMI_RMPUV_APPERI_OFFSET(EMI_APPERI_OFFSET >> 17) | EMI_RMPUV_APMCU_OFFSET(EMI_APMCU_OFFSET >> 17);
    DRV_WriteReg32(EMI_RMPUV /* 0x4320 */, reg_val);

    LOCK_EMI_REG();

	if (0 != custom_Init_EMIARB()) {
		BL_PRINT(LOG_ERROR, "[EMI] Failed to set EMI Arbitration Settings!\r\n");
		return -1;
	}

    #else // if !defined __EMI_DEVICE_LPDDR1__ && !defined __EMI_DEVICE_LPDDR2__
    #error "Please define correct DRAM Type!!"
    #endif // end if defined __EMI_DEVICE_LPDDR1__

    Data_Mem_Barrier();

    return 0;

}
