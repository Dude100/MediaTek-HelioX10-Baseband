/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2014
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
 *     dcl_pmic6325_init.c
 *
 * Project:
 * --------
 *     MOLY Software
 *
 * Description:
 * ------------
 *     This file is for PMIC 6325
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
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

// MT6325 ECO_E1
void dcl_pmic6325_modem_only_init(void)
{
	// RG_EN_DRVSEL[4:4] = 0x1 => Ricky
	PMIC_DRV_SetData(0x4       , 0x10      , 0x10      , 0x0);

	// RG_RSTB_DRV_SEL[5:5] = 0x1 => Ricky
	PMIC_DRV_SetData(0x4       , 0x20      , 0x20      , 0x0);

	// DDUVLO_DEB_EN[0:0] = 0x1 => Ricky
	PMIC_DRV_SetData(0xA       , 0x1       , 0x1       , 0x0);

	// VDVFS11_PG_H2L_EN[0:0] = 0x1 => Ricky
	PMIC_DRV_SetData(0xC       , 0x1       , 0x1       , 0x0);

	// VDVFS12_PG_H2L_EN[1:1] = 0x1 => Ricky
	PMIC_DRV_SetData(0xC       , 0x2       , 0x2       , 0x0);

	// VCORE1_PG_H2L_EN[4:4] = 0x1 => Ricky
	PMIC_DRV_SetData(0xC       , 0x10      , 0x10      , 0x0);

	// VCORE2_PG_H2L_EN[5:5] = 0x1 => Ricky
	PMIC_DRV_SetData(0xC       , 0x20      , 0x20      , 0x0);

	// VGPU_PG_H2L_EN[6:6] = 0x1 => Ricky
	PMIC_DRV_SetData(0xC       , 0x40      , 0x40      , 0x0);

	// VIO18_PG_H2L_EN[7:7] = 0x1 => Ricky
	PMIC_DRV_SetData(0xC       , 0x80      , 0x80      , 0x0);

	// VAUD28_PG_H2L_EN[8:8] = 0x1 => Ricky
	PMIC_DRV_SetData(0xC       , 0x100     , 0x100     , 0x0);

	// VTCXO_PG_H2L_EN[9:9] = 0x1 => Ricky
	PMIC_DRV_SetData(0xC       , 0x200     , 0x200     , 0x0);

	// VUSB_PG_H2L_EN[10:10] = 0x1 => Ricky
	PMIC_DRV_SetData(0xC       , 0x400     , 0x400     , 0x0);

	// VSRAM_DVFS1_PG_H2L_EN[11:11] = 0x1 => Ricky
	PMIC_DRV_SetData(0xC       , 0x800     , 0x800     , 0x0);

	// VIO28_PG_H2L_EN[12:12] = 0x1
	PMIC_DRV_SetData(0xC       , 0x1000    , 0x1000    , 0x0);

	// VDRAM_PG_H2L_EN[13:13] = 0x1 => Ricky
	PMIC_DRV_SetData(0xC       , 0x2000    , 0x2000    , 0x0);

	// UVLO_L2H_DEB_EN[5:5] = 0x1 => Ricky
	PMIC_DRV_SetData(0x10      , 0x20      , 0x20      , 0x0);

	// STRUP_PWROFF_SEQ_EN[0:0] = 0x1 => Ricky
	PMIC_DRV_SetData(0x16      , 0x1       , 0x1       , 0x0);

	// STRUP_PWROFF_PREOFF_EN[1:1] = 0x1 => Ricky
	PMIC_DRV_SetData(0x16      , 0x2       , 0x2       , 0x0);

	// RG_TESTMODE_SWEN[11:11] = 0x0 => CC
	PMIC_DRV_SetData(0x1E      , 0x800     , 0x0       , 0x0);

	// RG_SRCLKEN_IN0_HW_MODE[4:4] = 0x1 => Juinn-Ting
	PMIC_DRV_SetData(0x204     , 0x10      , 0x10      , 0x0);

	// RG_SRCLKEN_IN1_HW_MODE[5:5] = 0x1 => Juinn-Ting
	PMIC_DRV_SetData(0x204     , 0x20      , 0x20      , 0x0);

	// RG_OSC_SEL_HW_MODE[6:6] = 0x1 => Juinn-Ting
	PMIC_DRV_SetData(0x204     , 0x40      , 0x40      , 0x0);

	// RG_SMT_WDTRSTB_IN[0:0] = 0x1 => Ricky
	PMIC_DRV_SetData(0x222     , 0x1       , 0x1       , 0x0);

	// RG_SMT_SRCLKEN_IN0[2:2] = 0x1 => Ricky
	PMIC_DRV_SetData(0x222     , 0x4       , 0x4       , 0x0);

	// RG_SMT_SRCLKEN_IN1[3:3] = 0x1 => Ricky
	PMIC_DRV_SetData(0x222     , 0x8       , 0x8       , 0x0);

	// RG_RTC_75K_CK_PDN[2:2] = 0x1 => Juinn-Ting
	PMIC_DRV_SetData(0x23E     , 0x4       , 0x4       , 0x0);

	// RG_RTCDET_CK_PDN[3:3] = 0x1 => Juinn-Ting
	PMIC_DRV_SetData(0x23E     , 0x8       , 0x8       , 0x0);

	// VDVFS11_SFCHG_FRATE[6:0] = 0x4
	PMIC_DRV_SetData(0x4B6     , 0x7F      , 0x4       , 0x0);

	// VDVFS11_SFCHG_RRATE[14:8] = 0x4
	PMIC_DRV_SetData(0x4B6     , 0x7F00    , 0x400     , 0x0);

	// VDVFS12_SFCHG_FRATE[6:0] = 0x4
	PMIC_DRV_SetData(0x4DC     , 0x7F      , 0x4       , 0x0);

	// VDVFS12_SFCHG_RRATE[14:8] = 0x4
	PMIC_DRV_SetData(0x4DC     , 0x7F00    , 0x400     , 0x0);

	// VSRAM_DVFS1_SFCHG_FRATE[6:0] = 0x4
	PMIC_DRV_SetData(0x502     , 0x7F      , 0x4       , 0x0);

	// VSRAM_DVFS1_SFCHG_RRATE[14:8] = 0x4
	PMIC_DRV_SetData(0x502     , 0x7F00    , 0x400     , 0x0);

	// VDRAM_EN_CTRL[0:0] = 0x0 => YP
	PMIC_DRV_SetData(0x522     , 0x1       , 0x0       , 0x0);

	// VDRAM_VOSEL_CTRL[1:1] = 0x1 => YP
	PMIC_DRV_SetData(0x522     , 0x2       , 0x2       , 0x0);

	// VDRAM_SFCHG_FRATE[6:0] = 0x23 => ShangYing; Falling slewrate=2.0us/step
	PMIC_DRV_SetData(0x528     , 0x7F      , 0x23      , 0x0);

	// VDRAM_SFCHG_FEN[7:7] = 0x1 => ShangYing; Soft change falling enable.
	PMIC_DRV_SetData(0x528     , 0x80      , 0x80      , 0x0);

	// VDRAM_SFCHG_RRATE[14:8] = 0x6 => ShangYing; Rising slewrate=0.4us/step
	PMIC_DRV_SetData(0x528     , 0x7F00    , 0x600     , 0x0);

	// VDRAM_SFCHG_REN[15:15] = 0x1 => ShangYing; Soft change raising enable.
	PMIC_DRV_SetData(0x528     , 0x8000    , 0x8000    , 0x0);

	// VDRAM_VOSEL_SLEEP[6:0] = 0x0 => YP
	PMIC_DRV_SetData(0x52E     , 0x7F      , 0x0       , 0x0);

	// VDRAM_TRANS_TD[1:0] = 0x3 => ShangYing; Pulse width=50uS
	PMIC_DRV_SetData(0x538     , 0x3       , 0x3       , 0x0);

	// VDRAM_TRANS_CTRL[5:4] = 0x1 => ShangYing; Force PWM when DVFS falling enable.
	PMIC_DRV_SetData(0x538     , 0x30      , 0x10      , 0x0);

	// VDRAM_VSLEEP_EN[8:8] = 0x1 => ShangYing; Sleep mode enable
	PMIC_DRV_SetData(0x538     , 0x100     , 0x100     , 0x0);

	// VRF18_0_SFCHG_FRATE[6:0] = 0x4
	PMIC_DRV_SetData(0x54E     , 0x7F      , 0x4       , 0x0);

	// VRF18_0_SFCHG_RRATE[14:8] = 0x4
	PMIC_DRV_SetData(0x54E     , 0x7F00    , 0x400     , 0x0);

	// VGPU_SFCHG_FRATE[6:0] = 0x4
	PMIC_DRV_SetData(0x614     , 0x7F      , 0x4       , 0x0);

	// VGPU_SFCHG_RRATE[14:8] = 0x4
	PMIC_DRV_SetData(0x614     , 0x7F00    , 0x400     , 0x0);

	// VCORE1_SFCHG_FRATE[6:0] = 0x4
	PMIC_DRV_SetData(0x63A     , 0x7F      , 0x4       , 0x0);

	// VCORE1_SFCHG_RRATE[14:8] = 0x4
	PMIC_DRV_SetData(0x63A     , 0x7F00    , 0x400     , 0x0);

	// VCORE2_VOSEL_CTRL[1:1] = 0x1 => YP
	PMIC_DRV_SetData(0x65A     , 0x2       , 0x2       , 0x0);

	// VCORE2_SFCHG_FRATE[6:0] = 0x23 => ShangYing; Falling slewrate=2.0us/step
	PMIC_DRV_SetData(0x660     , 0x7F      , 0x23      , 0x0);

	// VCORE2_SFCHG_FEN[7:7] = 0x1 => ShangYing; Soft change falling enable.
	PMIC_DRV_SetData(0x660     , 0x80      , 0x80      , 0x0);

	// VCORE2_SFCHG_RRATE[14:8] = 0x8 => ShangYing; Rising slewrate=0.5us/step
	PMIC_DRV_SetData(0x660     , 0x7F00    , 0x800     , 0x0);

	// VCORE2_SFCHG_REN[15:15] = 0x1 => ShangYing; Soft change raising enable.
	PMIC_DRV_SetData(0x660     , 0x8000    , 0x8000    , 0x0);

	// VCORE2_VOSEL[6:0] = 0x44 => YP
	PMIC_DRV_SetData(0x662     , 0x7F      , 0x44      , 0x0);

	// VCORE2_VOSEL_ON[6:0] = 0x44 => YP
	PMIC_DRV_SetData(0x664     , 0x7F      , 0x44      , 0x0);

	// VCORE2_VOSEL_SLEEP[6:0] = 0x0 => YP
	PMIC_DRV_SetData(0x666     , 0x7F      , 0x0       , 0x0);

	// VCORE2_TRANS_TD[1:0] = 0x3 => ShangYing; Pulse width=50uS
	PMIC_DRV_SetData(0x670     , 0x3       , 0x3       , 0x0);

	// VCORE2_TRANS_CTRL[5:4] = 0x1 => ShangYing; Force PWM when DVFS falling enable.
	PMIC_DRV_SetData(0x670     , 0x30      , 0x10      , 0x0);

	// VCORE2_VSLEEP_EN[8:8] = 0x1 => ShangYing; Sleep mode enable
	PMIC_DRV_SetData(0x670     , 0x100     , 0x100     , 0x0);

	// VIO18_SFCHG_FRATE[6:0] = 0x4
	PMIC_DRV_SetData(0x68A     , 0x7F      , 0x4       , 0x0);

	// VIO18_SFCHG_RRATE[14:8] = 0x4
	PMIC_DRV_SetData(0x68A     , 0x7F00    , 0x400     , 0x0);

	// VIO18_VSLEEP_EN[8:8] = 0x1 => Johnson; SLEEP mode setting
	PMIC_DRV_SetData(0x69A     , 0x100     , 0x100     , 0x0);

	// VPA_SFCHG_FRATE[6:0] = 0x4
	PMIC_DRV_SetData(0x6B0     , 0x7F      , 0x4       , 0x0);

	// VPA_SFCHG_RRATE[14:8] = 0x4
	PMIC_DRV_SetData(0x6B0     , 0x7F00    , 0x400     , 0x0);

	// QI_VPA_BURSTL[13:12] = 0x1 => Johnson; SLEEP mode setting
	PMIC_DRV_SetData(0x6C4     , 0x3000    , 0x1000    , 0x0);

	// RG_VBIASN_EN[1:1] = 0x0 => Fandy, disable
	PMIC_DRV_SetData(0xA38     , 0x2       , 0x0       , 0x0);

	// FG_SLP_EN[8:8] = 0x1 => Ricky
	PMIC_DRV_SetData(0xCBC     , 0x100     , 0x100     , 0x0);

	// FG_ZCV_DET_EN[9:9] = 0x1 => Ricky
	PMIC_DRV_SetData(0xCBC     , 0x200     , 0x200     , 0x0);

	// RG_FG_AUXADC_R[10:10] = 0x1 => Ricky
	PMIC_DRV_SetData(0xCBC     , 0x400     , 0x400     , 0x0);

	// FG_SLP_CUR_TH[15:0] = 0x24 => Ricky
	PMIC_DRV_SetData(0xCC0     , 0xFFFF    , 0x24      , 0x0);

	// FG_SLP_TIME[7:0] = 0x14 => Ricky
	PMIC_DRV_SetData(0xCC2     , 0xFF      , 0x14      , 0x0);

	// FG_DET_TIME[15:8] = 0xFF => Ricky
	PMIC_DRV_SetData(0xCC4     , 0xFF00    , 0xFF00    , 0x0);

}