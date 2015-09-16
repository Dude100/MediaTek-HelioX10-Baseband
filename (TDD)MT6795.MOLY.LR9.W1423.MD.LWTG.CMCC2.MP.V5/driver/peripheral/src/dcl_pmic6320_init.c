/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   pmic_init.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provide for pmic initial setting
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "init.h"
#include "dcl.h"

extern DCL_UINT32 DRV_Read_PMIC_Data(DCL_UINT32 pmic_addr);
extern void DRV_Write_PMIC_Data(DCL_UINT32 pmic_addr, DCL_UINT32 value);

void PMIC_DRV_SetData(DCL_UINT32 addr, DCL_UINT32 bitmask, DCL_UINT16 value, DCL_UINT32 bank)
{
   DCL_UINT32 temp;
   addr |= (bank << 31);
   temp = (~(bitmask)) & DRV_Read_PMIC_Data(addr);
   temp |= ((value) & (bitmask));
   DRV_Write_PMIC_Data(addr,temp);
}

//MT6320_init.txt
void dcl_pmic6320_internal_init(void)
{
	{
	// addr      , mask      , value     , ap shift  , ap mask   , ap value  , bank
	// VSRAM_VOSEL_ON_HB[14:8] = 0x58 => Set before 0x0236
		PMIC_DRV_SetData(0x254,0x7F00,0x5800,0x0);
	// VSRAM_VOSEL_ON_LB[6:0] = 0x38 => Set before 0x0236
		PMIC_DRV_SetData(0x254,0x7F,0x38,0x0);
	// VSRAM_VOSEL_SLEEP_LB[6:0] = 0x38 => Set before 0x0236
		PMIC_DRV_SetData(0x256,0x7F,0x38,0x0);
	// RG_VCDT_HV_VTH[7:4] = 0xB => 7V OVP
		PMIC_DRV_SetData(0x2,0xF0,0xB0,0x0);
	// RG_VBAT_OV_VTH[3:1] = 0x2 => VBAT_OV=4.3V
		PMIC_DRV_SetData(0xC,0xE,0x4,0x0);
	// RG_CHRWDT_TD[3:0] = 0x3 => align to 6250's
		PMIC_DRV_SetData(0x1A,0xF,0x3,0x0);
	// RG_CSDAC_STP[6:4] = 0x0 => align to 6250's setting
		PMIC_DRV_SetData(0x2A,0x70,0x0,0x0);
	// RG_ULC_DET_EN[7:7] = 0x1
		PMIC_DRV_SetData(0x2E,0x80,0x80,0x0);
	// RG_HWCV_EN[6:6] = 0x1
		PMIC_DRV_SetData(0x2E,0x40,0x40,0x0);
	// RG_CSDAC_MODE[2:2] = 0x1
		PMIC_DRV_SetData(0x2E,0x4,0x4,0x0);
	// RG_SIMLS2_SRST_CONF[15:12] = 0x0 => Set PAD_SIMLS2_SRST slow skew
		PMIC_DRV_SetData(0x14C,0xF000,0x0,0x0);
	// RG_SIMLS2_SCLK_CONF[11:8] = 0x0 => Set PAD_SIMLS2_SCLK slow skew
		PMIC_DRV_SetData(0x14C,0xF00,0x0,0x0);
	// RG_SIMLS1_SRST_CONF[7:4] = 0x0 => Set PAD_SIMLS1_SRST slow skew
		PMIC_DRV_SetData(0x14C,0xF0,0x0,0x0);
	// RG_SIMLS1_SCLK_CONF[3:0] = 0x0 => Set PAD_SIMLS1_SCLK slow skew
		PMIC_DRV_SetData(0x14C,0xF,0x0,0x0);
	// RG_SMT3[3:3] = 0x1 => SRCLKEN_MD2 SMT enable
		PMIC_DRV_SetData(0x156,0x8,0x8,0x0);
	// RG_SMT2[2:2] = 0x1 => SRCLKEN_PERI SMT enable
		PMIC_DRV_SetData(0x156,0x4,0x4,0x0);
	// RG_SMT1[1:1] = 0x1 => SRCVOLTEN SMT enable
		PMIC_DRV_SetData(0x156,0x2,0x2,0x0);
	// RG_SMT47[15:15] = 0x1 => Set PAD_SIMLS2_SCLK schmit input
		PMIC_DRV_SetData(0x15A,0x8000,0x8000,0x0);
	// RG_SMT46[14:14] = 0x1 => Set PAD_SIMLS1_SRST schmit input
		PMIC_DRV_SetData(0x15A,0x4000,0x4000,0x0);
	// RG_SMT45[13:13] = 0x1 => Set PAD_SIMLS1_SCLK schmit input
		PMIC_DRV_SetData(0x15A,0x2000,0x2000,0x0);
	// RG_SMT48[0:0] = 0x1 => Set PAD_SIMLS2_SRST schmit input
		PMIC_DRV_SetData(0x15C,0x1,0x1,0x0);
	// RG_OCTL_SIMLS1_SRST[15:12] = 0x2 => Set PAD_SIMLS1_SRST driving to 4mA
		PMIC_DRV_SetData(0x174,0xF000,0x2000,0x0);
	// RG_OCTL_SIMLS1_SCLK[11:8] = 0x2 => Set PAD_SIMLS1_SCLK driving to 4mA
		PMIC_DRV_SetData(0x174,0xF00,0x200,0x0);
	// RG_OCTL_SIMLS2_SRST[7:4] = 0x2 => Set PAD_SIMLS2_SRST driving to 4mA
		PMIC_DRV_SetData(0x176,0xF0,0x20,0x0);
	// RG_OCTL_SIMLS2_SCLK[3:0] = 0x2 => Set PAD_SIMLS2_SCLK driving to 4mA
		PMIC_DRV_SetData(0x176,0xF,0x2,0x0);
	// RG_INT_EN_THR_H[11:11] = 0x1 => Thermal INT enable
		PMIC_DRV_SetData(0x178,0x800,0x800,0x0);
	// RG_INT_EN_THR_L[10:10] = 0x1 => Thermal INT enable
		PMIC_DRV_SetData(0x178,0x400,0x400,0x0);
	// VCORE_PG_H2L_EN[2:2] = 0x1 => PG H2L debounce enable
		PMIC_DRV_SetData(0x204,0x4,0x4,0x0);
	// VSRAM_PG_H2L_EN[1:1] = 0x1 => PG H2L debounce enable
		PMIC_DRV_SetData(0x204,0x2,0x2,0x0);
	// VPROC_PG_H2L_EN[0:0] = 0x1 => PG H2L debounce enable
		PMIC_DRV_SetData(0x204,0x1,0x1,0x0);
	// QI_VPROC_VSLEEP[5:4] = 0x2
		PMIC_DRV_SetData(0x20C,0x30,0x20,0x0);
	// RG_VPROC_SLP[1:0] = 0x3
		PMIC_DRV_SetData(0x20C,0x3,0x3,0x0);
	// VPROC_TRACK_ON_CTRL[4:4] = 0x1
		PMIC_DRV_SetData(0x210,0x10,0x10,0x0);
	// VPROC_DLC_CTRL[2:2] = 0x1 => E1 only
		PMIC_DRV_SetData(0x210,0x4,0x4,0x0);
	// VPROC_VOSEL_CTRL[1:1] = 0x1 => after 0x0256
		PMIC_DRV_SetData(0x210,0x2,0x2,0x0);
	// VPROC_SFCHG_REN[15:15] = 0x1
		PMIC_DRV_SetData(0x216,0x8000,0x8000,0x0);
	// VPROC_SFCHG_RRATE[14:8] = 0x11
		PMIC_DRV_SetData(0x216,0x7F00,0x1100,0x0);
	// VPROC_SFCHG_FRATE[6:0] = 0x23
		PMIC_DRV_SetData(0x216,0x7F,0x23,0x0);
	// VPROC_DLC_N_SLEEP[9:8] = 0x0 => E1 only
		PMIC_DRV_SetData(0x224,0x300,0x0,0x0);
	// VPROC_VSLEEP_EN[8:8] = 0x1
		PMIC_DRV_SetData(0x22A,0x100,0x100,0x0);
	// VPROC_VOSEL_TRANS_EN[5:4] = 0x1
		PMIC_DRV_SetData(0x22A,0x30,0x10,0x0);
	// VPROC_TRANSTD[1:0] = 0x3
		PMIC_DRV_SetData(0x22A,0x3,0x3,0x0);
	// QI_VSRAM_VSLEEP[5:4] = 0x2
		PMIC_DRV_SetData(0x232,0x30,0x20,0x0);
	// RG_VSRAM_SLP[3:0] = 0x3
		PMIC_DRV_SetData(0x232,0xF,0x3,0x0);
	// VSRAM_TRACK_SLEEP_CTRL[5:5] = 0x1
		PMIC_DRV_SetData(0x236,0x20,0x20,0x0);
	// VSRAM_TRACK_ON_CTRL[4:4] = 0x1
		PMIC_DRV_SetData(0x236,0x10,0x10,0x0);
	// VSRAM_VOSEL_CTRL[1:1] = 0x1 => after 0x0256
		PMIC_DRV_SetData(0x236,0x2,0x2,0x0);
	// VSRAM_SFCHG_REN[15:15] = 0x1
		PMIC_DRV_SetData(0x23C,0x8000,0x8000,0x0);
	// VSRAM_SFCHG_RRATE[14:8] = 0x11
		PMIC_DRV_SetData(0x23C,0x7F00,0x1100,0x0);
	// VSRAM_SFCHG_FRATE[6:0] = 0x23
		PMIC_DRV_SetData(0x23C,0x7F,0x23,0x0);
	// VSRAM_VSLEEP_EN[8:8] = 0x1
		PMIC_DRV_SetData(0x250,0x100,0x100,0x0);
	// VSRAM_VOSEL_TRANS_EN[5:4] = 0x1
		PMIC_DRV_SetData(0x250,0x30,0x10,0x0);
	// VSRAM_TRANSTD[1:0] = 0x3
		PMIC_DRV_SetData(0x250,0x3,0x3,0x0);
	// RG_VCORE_RSV[7:0] = 0xF2
		PMIC_DRV_SetData(0x260,0xFF,0xF2,0x0);
	// VCORE_DLC_CTRL[2:2] = 0x1 => E1 only
		PMIC_DRV_SetData(0x262,0x4,0x4,0x0);
	// VCORE_VOSEL_CTRL[1:1] = 0x1
		PMIC_DRV_SetData(0x262,0x2,0x2,0x0);
	// VCORE_SFCHG_REN[15:15] = 0x1
		PMIC_DRV_SetData(0x268,0x8000,0x8000,0x0);
	// VCORE_SFCHG_RRATE[14:8] = 0x11
		PMIC_DRV_SetData(0x268,0x7F00,0x1100,0x0);
	// VCORE_SFCHG_FRATE[6:0] = 0x23
		PMIC_DRV_SetData(0x268,0x7F,0x23,0x0);
	// VCORE_DLC_N_SLEEP[9:8] = 0x0 => E1 only
		PMIC_DRV_SetData(0x276,0x300,0x0,0x0);
	// VCORE_VSLEEP_EN[8:8] = 0x1
		PMIC_DRV_SetData(0x27C,0x100,0x100,0x0);
	// VCORE_TRANSTD[1:0] = 0x1
		PMIC_DRV_SetData(0x27C,0x3,0x1,0x0);
	// VM_DLC_CTRL[2:2] = 0x1 => E1 only
		PMIC_DRV_SetData(0x288,0x4,0x4,0x0);
	// VM_DLC_N_SLEEP[9:8] = 0x0 => E1 only
		PMIC_DRV_SetData(0x29C,0x300,0x0,0x0);
	// VM_VSLEEP_EN[8:8] = 0x1
		PMIC_DRV_SetData(0x2A2,0x100,0x100,0x0);
	// VM_TRANSTD[1:0] = 0x1
		PMIC_DRV_SetData(0x2A2,0x3,0x1,0x0);
	// RG_VPA_SLEW_NMOS[11:10] = 0x1
		PMIC_DRV_SetData(0x328,0xC00,0x400,0x0);
	// RG_VPA_RZSEL[1:0] = 0x1
		PMIC_DRV_SetData(0x328,0x3,0x1,0x0);
	// RG_VPA_SLP[1:0] = 0x3
		PMIC_DRV_SetData(0x32C,0x3,0x3,0x0);
	// VPA_SFCHG_REN[15:15] = 0x1
		PMIC_DRV_SetData(0x336,0x8000,0x8000,0x0);
	// VPA_SFCHG_FEN[7:7] = 0x1
		PMIC_DRV_SetData(0x336,0x80,0x80,0x0);
	// VPA_DLC_ON[6:4] = 0x0 => DLC for each voltage setting
		PMIC_DRV_SetData(0x342,0x70,0x0,0x0);
	// VPA_DLC[2:0] = 0x0 => DLC for each voltage setting
		PMIC_DRV_SetData(0x342,0x7,0x0,0x0);
	// VPA_BURSTH[1:0] = 0x3
		PMIC_DRV_SetData(0x346,0x3,0x3,0x0);
	// RG_VSIM1_VOSEL[7:5] = 0x0 => PD team advice
		PMIC_DRV_SetData(0x45C,0xE0,0x0,0x0);
	// RG_VSIM2_VOSEL[7:5] = 0x0 => PD team advice
		PMIC_DRV_SetData(0x45E,0xE0,0x0,0x0);
	// THR_HWPDN_EN[5:5] = 0x1 => 125?C HW auto power down enable
		PMIC_DRV_SetData(0x500,0x20,0x20,0x0);
	// RG_RST_DRVSEL[3:3] = 0x1 => Driver capability select 15mA to improve ESD
		PMIC_DRV_SetData(0x502,0x8,0x8,0x0);
	// RG_EN_DRVSEL[2:2] = 0x1 => Driver capability select 15mA to improve ESD
		PMIC_DRV_SetData(0x502,0x4,0x4,0x0);
	// DDUVLO_DEB_EN[0:0] = 0x1 => UVLO debounce (100ns) enable
		PMIC_DRV_SetData(0x508,0x1,0x1,0x0);
	// UVLO_L2H_DEB_EN[5:5] = 0x1 => UVLO debounce (100ns) enable
		PMIC_DRV_SetData(0x50C,0x20,0x20,0x0);
	// STRUP_PWROFF_PREOFF_EN[1:1] = 0x1 => Power off sequence enable
		PMIC_DRV_SetData(0x510,0x2,0x2,0x0);
	// STRUP_PWROFF_SEQ_EN[0:0] = 0x1 => Power off sequence enable
		PMIC_DRV_SetData(0x510,0x1,0x1,0x0);
	// RG_AVG_NUM[6:4] = 0x3 => AUXADC average 16 sample selection
		PMIC_DRV_SetData(0x540,0x70,0x30,0x0);
	// RG_ADC_TRIM_CH_SEL[15:8] = 0xFC => Efuse trim select
		PMIC_DRV_SetData(0x55C,0xFF00,0xFC00,0x0);
	// FLASH_THER_SHDN_EN[1:1] = 0x1
		PMIC_DRV_SetData(0x55E,0x2,0x2,0x0);
	// KPLED_THER_SHDN_EN[1:1] = 0x1
		PMIC_DRV_SetData(0x564,0x2,0x2,0x0);
	// SPK_THER_SHDN_L_EN[9:9] = 0x1
		PMIC_DRV_SetData(0x600,0x200,0x200,0x0);
	// RG_SPK_INTG_RST_L[0:0] = 0x1
		PMIC_DRV_SetData(0x604,0x1,0x1,0x0);
	// SPK_THER_SHDN_R_EN[9:9] = 0x1
		PMIC_DRV_SetData(0x606,0x200,0x200,0x0);
	// RG_SPKPGA_GAIN[11:8] = 0x1
		PMIC_DRV_SetData(0x612,0xF00,0x100,0x0);
	// RG_LCLDO_ENC_REMOTE_SENSE_VA28[7:7] = 0x1
		PMIC_DRV_SetData(0x714,0x80,0x80,0x0);
	// RG_LCLDO_REMOTE_SENSE_VA33[4:4] = 0x1
		PMIC_DRV_SetData(0x714,0x10,0x10,0x0);
	// RG_HCLDO_REMOTE_SENSE_VA33[1:1] = 0x1
		PMIC_DRV_SetData(0x714,0x2,0x2,0x0);
	// RG_NCP_REMOTE_SENSE_VA18[15:15] = 0x1
		PMIC_DRV_SetData(0x71A,0x8000,0x8000,0x0);

		PMIC_DRV_SetData(0x0128,0xAF20,0x0F20,0x0);

		PMIC_DRV_SetData(0x0106,0x3,0x0003,0x0);
		PMIC_DRV_SetData(0x4026,0xFFFF,0x0000,0x0);
		PMIC_DRV_SetData(0x400e,0xFFFF,0x000A,0x0);
		PMIC_DRV_SetData(0x4010,0xFFFF,0x0600,0x0);
		PMIC_DRV_SetData(0x4038,0xFFFF,0x0006,0x0);
		PMIC_DRV_SetData(0x4034,0xFFFF,0xc3a1,0x0);
		PMIC_DRV_SetData(0x4038,0xFFFF,0x0003,0x0);
		PMIC_DRV_SetData(0x4038,0xFFFF,0x000b,0x0);
		PMIC_DRV_SetData(0x400C,0xFFFF,0x001e,0x0);
		PMIC_DRV_SetData(0x4002,0xFFFF,0x3300,0x0);
		PMIC_DRV_SetData(0x4004,0xFFFF,0x1820,0x0);
		PMIC_DRV_SetData(0x4006,0xFFFF,0x0000,0x0);
		PMIC_DRV_SetData(0x4008,0xFFFF,0x1000,0x0);
		PMIC_DRV_SetData(0x4000,0xFFFF,0x007f,0x0);
		PMIC_DRV_SetData(0x4010,0xFFFF,0x0601,0x0);
		PMIC_DRV_SetData(0x4004,0xFFFF,0x1821,0x0);
		PMIC_DRV_SetData(0x4020,0xFFFF,0x004F,0x0);
		PMIC_DRV_SetData(0x4022,0xFFFF,0x004f,0x0);
		PMIC_DRV_SetData(0x0712,0xFFFF,0x0002,0x0);
		PMIC_DRV_SetData(0x0714,0xFFFF,0x0D92,0x0);
		PMIC_DRV_SetData(0x071A,0xFFFF,0x9000,0x0);
		PMIC_DRV_SetData(0x071C,0xFFFF,0x0027,0x0);
		PMIC_DRV_SetData(0x071E,0xFFFF,0x0093,0x0);
		PMIC_DRV_SetData(0x072C,0xFFFF,0x0180,0x0);
		PMIC_DRV_SetData(0x0736,0xFFFF,0x0022,0x0);
		PMIC_DRV_SetData(0x0718,0xFFFF,0x000C,0x0);
		PMIC_DRV_SetData(0x071A,0xFFFF,0xF000,0x0);
		PMIC_DRV_SetData(0x0744,0xFFFF,0x102B,0x0);
		PMIC_DRV_SetData(0x0746,0xFFFF,0x0000,0x0);
		PMIC_DRV_SetData(0x0738,0xFFFF,0x0200,0x0);
		PMIC_DRV_SetData(0x070E,0xFFFF,0x0030,0x0);
		PMIC_DRV_SetData(0x0702,0xFFFF,0x0008,0x0);
		PMIC_DRV_SetData(0x070C,0xFFFF,0x0552,0x0);
		PMIC_DRV_SetData(0x073E,0xFFFF,0x000F,0x0);
		PMIC_DRV_SetData(0x0706,0xFFFF,0x00A2,0x0);
		PMIC_DRV_SetData(0x0702,0xFFFF,0x0001,0x0);
		PMIC_DRV_SetData(0x0706,0xFFFF,0x0022,0x0);
		PMIC_DRV_SetData(0x073E,0xFFFF,0x0008,0x0);
		PMIC_DRV_SetData(0x0712,0xFFFF,0x0003,0x0);
		PMIC_DRV_SetData(0x0700,0xFFFF,0x0009,0x0);
		PMIC_DRV_SetData(0x0702,0xFFFF,0x0011,0x0);
	}
}
	
