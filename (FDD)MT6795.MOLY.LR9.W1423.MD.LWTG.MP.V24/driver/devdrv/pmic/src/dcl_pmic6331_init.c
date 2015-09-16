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
 *     dcl_pmic6331_init.c
 *
 * Project:
 * --------
 *     MOLY Software
 *
 * Description:
 * ------------
 *     This file is for PMIC 6331
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

// MT6331 ECO_E1
void dcl_pmic6331_modem_only_init(void)
{
	// RG_EN_DRVSEL[4:4] = 0x1
	PMIC_DRV_SetData(0x4       , 0x10      , 0x10      , 0x0);

	// RG_RSTB_DRV_SEL[5:5] = 0x1
	PMIC_DRV_SetData(0x4       , 0x20      , 0x20      , 0x0);

	// VDVFS11_PG_H2L_EN[0:0] = 0x1
	PMIC_DRV_SetData(0xC       , 0x1       , 0x1       , 0x0);

	// VDVFS12_PG_H2L_EN[1:1] = 0x1
	PMIC_DRV_SetData(0xC       , 0x2       , 0x2       , 0x0);

	// VDVFS13_PG_H2L_EN[2:2] = 0x1
	PMIC_DRV_SetData(0xC       , 0x4       , 0x4       , 0x0);

	// VDVFS14_PG_H2L_EN[3:3] = 0x1
	PMIC_DRV_SetData(0xC       , 0x8       , 0x8       , 0x0);

	// VCORE1_PG_H2L_EN[4:4] = 0x1
	PMIC_DRV_SetData(0xC       , 0x10      , 0x10      , 0x0);

	// VCORE2_PG_H2L_EN[5:5] = 0x1
	PMIC_DRV_SetData(0xC       , 0x20      , 0x20      , 0x0);

	// VGPU_PG_H2L_EN[6:6] = 0x1
	PMIC_DRV_SetData(0xC       , 0x40      , 0x40      , 0x0);

	// VIO18_PG_H2L_EN[7:7] = 0x1
	PMIC_DRV_SetData(0xC       , 0x80      , 0x80      , 0x0);

	// VAUD32_PG_H2L_EN[8:8] = 0x1
	PMIC_DRV_SetData(0xC       , 0x100     , 0x100     , 0x0);

	// VTCXO1_PG_H2L_EN[9:9] = 0x1
	PMIC_DRV_SetData(0xC       , 0x200     , 0x200     , 0x0);

	// VUSB_PG_H2L_EN[10:10] = 0x1
	PMIC_DRV_SetData(0xC       , 0x400     , 0x400     , 0x0);

	// VSRAM_DVFS1_PG_H2L_EN[11:11] = 0x1
	PMIC_DRV_SetData(0xC       , 0x800     , 0x800     , 0x0);

	// VIO28_PG_H2L_EN[12:12] = 0x1
	PMIC_DRV_SetData(0xC       , 0x1000    , 0x1000    , 0x0);

	// UVLO_L2H_DEB_EN[5:5] = 0x1
	PMIC_DRV_SetData(0x10      , 0x20      , 0x20      , 0x0);

	// STRUP_PWROFF_SEQ_EN[0:0] = 0x1
	PMIC_DRV_SetData(0x16      , 0x1       , 0x1       , 0x0);

	// STRUP_PWROFF_PREOFF_EN[1:1] = 0x1
	PMIC_DRV_SetData(0x16      , 0x2       , 0x2       , 0x0);

	// RG_SRCLKEN_IN1_HW_MODE[4:4] = 0x1
	PMIC_DRV_SetData(0x106     , 0x10      , 0x10      , 0x0);

	// RG_SRCLKEN_IN2_HW_MODE[5:5] = 0x1
	PMIC_DRV_SetData(0x106     , 0x20      , 0x20      , 0x0);

	// RG_OSC_SEL_HW_MODE[6:6] = 0x1
	PMIC_DRV_SetData(0x106     , 0x40      , 0x40      , 0x0);

	// RG_SMT_WDTRSTB_IN[0:0] = 0x1
	PMIC_DRV_SetData(0x124     , 0x1       , 0x1       , 0x0);

	// RG_SMT_SRCLKEN_IN1[2:2] = 0x1
	PMIC_DRV_SetData(0x124     , 0x4       , 0x4       , 0x0);

	// RG_SMT_SRCLKEN_IN2[3:3] = 0x1
	PMIC_DRV_SetData(0x124     , 0x8       , 0x8       , 0x0);

	// RG_RTC_75K_CK_PDN[2:2] = 0x1
	PMIC_DRV_SetData(0x13E     , 0x4       , 0x4       , 0x0);

	// RG_RTCDET_CK_PDN[3:3] = 0x1
	PMIC_DRV_SetData(0x13E     , 0x8       , 0x8       , 0x0);

	// RG_STRUP_AUXADC_CK_PDN[6:6] = 0x1
	PMIC_DRV_SetData(0x144     , 0x40      , 0x40      , 0x0);

	// RG_75K_32K_SEL[10:10] = 0x1
	PMIC_DRV_SetData(0x14A     , 0x400     , 0x400     , 0x0);

	// VDVFS11_VOSEL[6:0] = 0x44
	PMIC_DRV_SetData(0x24C     , 0x7F      , 0x44      , 0x0);

	// VDVFS11_VOSEL_ON[6:0] = 0x44
	PMIC_DRV_SetData(0x24E     , 0x7F      , 0x44      , 0x0);

	// VCORE2_VOSEL[6:0] = 0x44
	PMIC_DRV_SetData(0x36A     , 0x7F      , 0x44      , 0x0);

	// VCORE2_VOSEL_ON[6:0] = 0x44
	PMIC_DRV_SetData(0x36C     , 0x7F      , 0x44      , 0x0);

	// VCORE2_VSLEEP_EN[8:8] = 0x1
	PMIC_DRV_SetData(0x378     , 0x100     , 0x100     , 0x0);

	// RG_VSRAM_DVFS1_VOSEL[15:9] = 0x44
	PMIC_DRV_SetData(0x534     , 0xFE00    , 0x8800    , 0x0);

	// AUXADC_TRIM_CH0_SEL[1:0] = 0x1
	PMIC_DRV_SetData(0x73E     , 0x3       , 0x1       , 0x0);

	// AUXADC_TRIM_CH1_SEL[3:2] = 0x1
	PMIC_DRV_SetData(0x73E     , 0xC       , 0x4       , 0x0);

	// AUXADC_TRIM_CH2_SEL[5:4] = 0x1
	PMIC_DRV_SetData(0x73E     , 0x30      , 0x10      , 0x0);

	// AUXADC_TRIM_CH3_SEL[7:6] = 0x1
	PMIC_DRV_SetData(0x73E     , 0xC0      , 0x40      , 0x0);

	// AUXADC_TRIM_CH4_SEL[9:8] = 0x1
	PMIC_DRV_SetData(0x73E     , 0x300     , 0x100     , 0x0);

	// AUXADC_TRIM_CH5_SEL[11:10] = 0x1
	PMIC_DRV_SetData(0x73E     , 0xC00     , 0x400     , 0x0);

	// AUXADC_TRIM_CH6_SEL[13:12] = 0x1
	PMIC_DRV_SetData(0x73E     , 0x3000    , 0x1000    , 0x0);

	// AUXADC_TRIM_CH7_SEL[15:14] = 0x2
	PMIC_DRV_SetData(0x73E     , 0xC000    , 0x8000    , 0x0);

	// AUXADC_TRIM_CH8_SEL[1:0] = 0x1
	PMIC_DRV_SetData(0x740     , 0x3       , 0x1       , 0x0);

	// AUXADC_TRIM_CH9_SEL[3:2] = 0x1
	PMIC_DRV_SetData(0x740     , 0xC       , 0x4       , 0x0);

	// AUXADC_TRIM_CH10_SEL[5:4] = 0x1
	PMIC_DRV_SetData(0x740     , 0x30      , 0x10      , 0x0);

	// AUXADC_TRIM_CH11_SEL[7:6] = 0x1
	PMIC_DRV_SetData(0x740     , 0xC0      , 0x40      , 0x0);

}
