/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 *     dcl_pmic6332_init.c
 *
 * Project:
 * --------
 *     MOLY Software
 *
 * Description:
 * ------------
 *     This file is for PMIC 6332
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
 *
 * removed!
 * removed!
 * removed!
 *
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

static void PMIC_DRV_SetData(DCL_UINT32 addr, DCL_UINT32 bitmask, DCL_UINT16 value, DCL_UINT32 bank)
{
   DCL_UINT32 temp;
   addr |= (bank << 31);
   temp = (~(bitmask)) & DRV_Read_PMIC_Data(addr);
   temp |= ((value) & (bitmask));
   DRV_Write_PMIC_Data(addr,temp);
}

// MT6332 ECO_E1
void dcl_pmic6332_modem_only_init(void)
{
	// RG_SRCLKEN_IN1_HW_MODE[4:4] = 0x1
	PMIC_DRV_SetData(0x8004    , 0x10      , 0x10      , 0x0);

	// RG_SRCLKEN_IN2_HW_MODE[5:5] = 0x1
	PMIC_DRV_SetData(0x8004    , 0x20      , 0x20      , 0x0);

	// RG_OSC_SEL_HW_MODE[6:6] = 0x1
	PMIC_DRV_SetData(0x8004    , 0x40      , 0x40      , 0x0);

	// RG_SMT_WDTRSTB_IN[0:0] = 0x1
	PMIC_DRV_SetData(0x801A    , 0x1       , 0x1       , 0x0);

	// RG_AUXADC_12M_CK_PDN[9:9] = 0x1
	PMIC_DRV_SetData(0x8094    , 0x200     , 0x200     , 0x0);

	// VDRAM_VSLEEP_EN[8:8] = 0x1
	PMIC_DRV_SetData(0x845C    , 0x100     , 0x100     , 0x0);

	// VSRAM_DVFS2_VSLEEP_EN[8:8] = 0x0
	PMIC_DRV_SetData(0x8498    , 0x100     , 0x0       , 0x0);

	// VRF1_EN_CTRL[0:0] = 0x1 => VRF1 Follow SRCLKEN1(A0)
	PMIC_DRV_SetData(0x84AA    , 0x1       , 0x1       , 0x0);

	// VRF1_VOSEL[6:0] = 0x53 => VRF=1.828V
	PMIC_DRV_SetData(0x84B2    , 0x7F      , 0x53      , 0x0);

	// VRF1_VOSEL_ON[6:0] = 0x53 => VRF=1.828V
	PMIC_DRV_SetData(0x84B4    , 0x7F      , 0x53      , 0x0);

	// VRF2_VOSEL[6:0] = 0x53 => VRF=1.828V
	PMIC_DRV_SetData(0x84DE    , 0x7F      , 0x53      , 0x0);

	// VRF2_VOSEL_ON[6:0] = 0x53 => VRF=1.828V
	PMIC_DRV_SetData(0x84E0    , 0x7F      , 0x53      , 0x0);

	// VPA_DVS_TRANS_CTRL[5:4] = 0x3 => DVS performance tuning
	PMIC_DRV_SetData(0x8526    , 0x30      , 0x30      , 0x0);

	// AUXADC_TRIM_CH2_SEL[5:4] = 0x1
	PMIC_DRV_SetData(0x886E    , 0x30      , 0x10      , 0x0);

	// AUXADC_TRIM_CH3_SEL[7:6] = 0x1
	PMIC_DRV_SetData(0x886E    , 0xC0      , 0x40      , 0x0);

	// AUXADC_TRIM_CH4_SEL[9:8] = 0x1
	PMIC_DRV_SetData(0x886E    , 0x300     , 0x100     , 0x0);

	// AUXADC_TRIM_CH5_SEL[11:10] = 0x1
	PMIC_DRV_SetData(0x886E    , 0xC00     , 0x400     , 0x0);

	// AUXADC_TRIM_CH6_SEL[13:12] = 0x1
	PMIC_DRV_SetData(0x886E    , 0x3000    , 0x1000    , 0x0);

	// AUXADC_TRIM_CH7_SEL[15:14] = 0x2
	PMIC_DRV_SetData(0x886E    , 0xC000    , 0x8000    , 0x0);

	// AUXADC_TRIM_CH8_SEL[1:0] = 0x1
	PMIC_DRV_SetData(0x8870    , 0x3       , 0x1       , 0x0);

	// AUXADC_TRIM_CH9_SEL[3:2] = 0x1
	PMIC_DRV_SetData(0x8870    , 0xC       , 0x4       , 0x0);

	// AUXADC_TRIM_CH10_SEL[5:4] = 0x1
	PMIC_DRV_SetData(0x8870    , 0x30      , 0x10      , 0x0);

	// AUXADC_TRIM_CH11_SEL[7:6] = 0x1
	PMIC_DRV_SetData(0x8870    , 0xC0      , 0x40      , 0x0);

	// RG_EN_DRVSEL[4:4] = 0x1
	PMIC_DRV_SetData(0x8C0A    , 0x10      , 0x10      , 0x0);

	// RG_RSTB_DRV_SEL[5:5] = 0x1
	PMIC_DRV_SetData(0x8C0A    , 0x20      , 0x20      , 0x0);

	// VSBST_PG_H2L_EN[8:8] = 0x1
	PMIC_DRV_SetData(0x8C12    , 0x100     , 0x100     , 0x0);

	// VUSB33_PG_H2L_EN[9:9] = 0x1
	PMIC_DRV_SetData(0x8C12    , 0x200     , 0x200     , 0x0);

	// VSRAM_DVFS2_PG_H2L_EN[10:10] = 0x1
	PMIC_DRV_SetData(0x8C12    , 0x400     , 0x400     , 0x0);

	// VDRAM_PG_H2L_EN[11:11] = 0x1
	PMIC_DRV_SetData(0x8C12    , 0x800     , 0x800     , 0x0);

	// VDVFS2_PG_H2L_EN[12:12] = 0x1
	PMIC_DRV_SetData(0x8C12    , 0x1000    , 0x1000    , 0x0);

	// EXT_PMIC_EN_INT_PG_H2L_EN[13:13] = 0x1
	PMIC_DRV_SetData(0x8C12    , 0x2000    , 0x2000    , 0x0);

	// VAUXB32_PG_H2L_EN[14:14] = 0x1
	PMIC_DRV_SetData(0x8C12    , 0x4000    , 0x4000    , 0x0);

	// STRUP_CON8_RSV0[14:8] = 0x1
	PMIC_DRV_SetData(0x8C16    , 0x7F00    , 0x100     , 0x0);

	// STRUP_AUXADC_RSTB_SEL[7:7] = 0x1
	PMIC_DRV_SetData(0x8C18    , 0x80      , 0x80      , 0x0);

	// STRUP_PWROFF_SEQ_EN[0:0] = 0x1
	PMIC_DRV_SetData(0x8C1A    , 0x1       , 0x1       , 0x0);

	// STRUP_PWROFF_PREOFF_EN[1:1] = 0x1
	PMIC_DRV_SetData(0x8C1A    , 0x2       , 0x2       , 0x0);

	// RG_VBIF28_ON_CTRL[11:11] = 0x1
	PMIC_DRV_SetData(0x8CB8    , 0x800     , 0x800     , 0x0);

}
