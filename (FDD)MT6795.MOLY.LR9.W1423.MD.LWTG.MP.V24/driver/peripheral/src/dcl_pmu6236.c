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
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    dcl_pmu6236.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for PMIC 6236 driver.
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "reg_base.h"
#include "drv_comm.h"
#include "init.h"
#include "intrCtrl.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"
#include "custom_hw_default.h"

#if defined(PMIC_6236_REG_API)

#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)

#define BL_VBOOST_VOLTAGE_CONTROLLER_LEVEL      (PWM_MAX_BACKLIGHT_LEVEL)
#define BL_VBOOST_CURRENT_CONVERTER_LEVEL       (PWM_MAX_BACKLIGHT_LEVEL)
#define BL_ISINK_LEVEL                          (PWM_MAX_BACKLIGHT_LEVEL)

#else

#define BL_VBOOST_VOLTAGE_CONTROLLER_LEVEL      (PWM_MAX_LEVEL)
#define BL_VBOOST_CURRENT_CONVERTER_LEVEL       (PWM_MAX_LEVEL)
#define BL_ISINK_LEVEL                          (PWM_MAX_LEVEL)

#endif // End of #if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)

#ifndef __DRV_DEBUG_PMU_REG_READ_WRITE__
#define PMU_DRV_ClearBits16(addr, data)       DRV_ClearBits(addr,data)
#define PMU_DRV_SetBits16(addr, data)         DRV_SetBits(addr,data)
#define PMU_DRV_WriteReg16(addr, data)        DRV_WriteReg(addr, data)
#define PMU_DRV_ReadReg16(addr)               DRV_Reg(addr)
#define PMU_DRV_ReadReg32(addr)               DRV_Reg32(addr)
#define PMU_DRV_SetData16(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)
#else // #ifndef __DRV_DEBUG_PMU_REG_READ_WRITE__
#define PMU_DRV_ClearBits16(addr,data)        DRV_DBG_ClearBits(addr,data)
#define PMU_DRV_SetBits16(addr, data)         DRV_DBG_SetBits(addr,data)
#define PMU_DRV_WriteReg16(addr, data)        DRV_DBG_WriteReg(addr, data)
#define PMU_DRV_ReadReg16(addr)               DRV_DBG_Reg(addr)
#define PMU_DRV_ReadReg32(addr)               DRV_DBG_Reg32(addr)
#define PMU_DRV_SetData16(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)
#endif // #ifndef __DRV_DEBUG_PMU_REG_READ_WRITE__

extern void pmu6236_customization_init(void);


//extern void pmu6236_EM_reg_write(kal_uint32 reg, kal_uint16 val);
//extern kal_uint16 pmu6236_EM_reg_read(kal_uint32 reg);

#if defined(PMIC_6236_CV_TRIM_CALIBRATION)
pmu6236_chr_vbat_cv_enum mt6236_efuse_vbat_cv;
#endif // #if defined(PMIC_6236_CV_TRIM_CALIBRATION)

// Force SRCLKENAI. If this bit is set to 1, hardware would see effective SRCLKENAI becoming
// 1 even when SRCLKENAI from GPIO pin is 0.
// 0: Disable
// 1: Enable
#define MT6236_HW_MISC_REG_ADDR                   CONFIG_base + 0x0100
#define MT6236_HW_MISC_REG_FORCE_SRCLKENAI_MASK   0x2000
#define MT6236_HW_MISC_REG_FORCE_SRCLKENAI_SHIFT  13

// CLKSQ CLKSQ Internal Debug Signal
#define MT6236_IDN_SEL_REG_ADDR                   CONFIG_base + 0x060C
#define MT6236_IDN_SEL_REG_CLKSQ_MASK             0x0008
#define MT6236_IDN_SEL_REG_CLKSQ_SHIFT            3

/*
void dcl_pmu6236_LDO_enable(LDO_enum ldo, DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;
	kal_uint32  regShift;

	ASSERT(ldo < LDO_MAX_NUM);

	regShift = ldo * LDO_ADDRESS_BIAS;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_LDO_BASE0 + regShift);
	reg_val16 &= (~LDO_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << LD0_EN_SHIFT) & LDO_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_LDO_BASE0 + regShift, reg_val16);
	RestoreIRQMask(savedMask);
}


void dcl_pmu6236_LDO_on_sel(LDO_enum ldo, pmu6236_ldo_on_sel_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;
	kal_uint32  regShift;

	ASSERT(ldo < LDO_MAX_NUM);

	regShift = ldo * LDO_ADDRESS_BIAS;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_LDO_BASE0 + regShift);
	reg_val16 &= (~LDO_ON_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << LDO_ON_SEL_SHIFT) & LDO_ON_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_LDO_BASE0 + regShift, reg_val16);

	RestoreIRQMask(savedMask);
}


void dcl_pmu6236_LDO_sense(LDO_enum ldo, pmu6236_ldo_sense_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;
	kal_uint32  regShift;

	ASSERT(ldo < LDO_MAX_NUM);

	regShift = ldo * LDO_ADDRESS_BIAS;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_LDO_BASE0+ regShift);
	reg_val16 &= (~LDO_SENSE_MASK);
	reg_val16 |= (((kal_uint8)sel << LDO_SENSE_SHIFT) & LDO_SENSE_MASK);
	PMU_DRV_WriteReg16(PMIC_LDO_BASE0 + regShift, reg_val16);

	RestoreIRQMask(savedMask);
}


void dcl_pmu6236_LDO_ocfb_enable(LDO_enum ldo, DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;
	kal_uint32  regShift;

	ASSERT(ldo < LDO_MAX_NUM);

	regShift = ldo * LDO_ADDRESS_BIAS;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_LDO_BASE0 + regShift);
	reg_val16 &= (~LDO_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << LDO_OCFB_EN_SHIFT) & LDO_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_LDO_BASE0 + regShift, reg_val16);
	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_LOD_status(LDO_enum ldo)
{
	kal_uint16  reg_val16;
	kal_uint16  regShift;

	ASSERT(ldo < LDO_MAX_NUM);

	regShift = ldo * LDO_ADDRESS_BIAS;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_LDO_BASE0 + regShift);

	if (reg_val16 & LDO_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

void dcl_pmu6236_LDO_cal(LDO_enum ldo, kal_uint8 val)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;
	kal_uint32  regShift;

	ASSERT(ldo < LDO_MAX_NUM);
	ASSERT(val < CAL_MAX);


	regShift = ldo * LDO_ADDRESS_BIAS;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_LDO_BASE1+ regShift);
	reg_val16 &= (~LDO_CAL_MASK);
	reg_val16 |= ((val << LDO_CAL_SHIFT) & LDO_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_LDO_BASE1+ regShift, reg_val16);

	RestoreIRQMask(savedMask);
}
*/

// (0x800) VRF_CON0
void dcl_pmu6236_vrf_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VRF_CON0);
	reg_val16 &= (~VRF_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VRF_EN_SHIFT) & VRF_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VRF_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vrf_on_sel(pmu6236_vrf_on_sel_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VRF_CON0);
	reg_val16 &= (~VRF_ON_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VRF_ON_SEL_SHIFT) & VRF_ON_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VRF_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vrf_sense(pmu6236_sense_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VRF_CON0);
	reg_val16 &= (~VRF_REMOTE_SENSE_MASK);
	reg_val16 |= (((kal_uint8)sel << VRF_REMOTE_SENSE_SHIFT) & VRF_REMOTE_SENSE_MASK);
	PMU_DRV_WriteReg16(PMIC_VRF_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vrf_ndis_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VRF_CON0);
	reg_val16 &= (~VRF_NDIS_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VRF_NDIS_EN_SHIFT) & VRF_NDIS_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VRF_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vrf_stb_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VRF_CON0);
	reg_val16 &= (~VRF_STB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VRF_STB_EN_SHIFT) & VRF_STB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VRF_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vrf_oc_auto_off(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VRF_CON0);
	reg_val16 &= (~VRF_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VRF_OC_AUTO_OFF_SHIFT) & VRF_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_VRF_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vrf_ocfb_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VRF_CON0);
	reg_val16 &= (~VRF_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VRF_OCFB_EN_SHIFT) & VRF_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VRF_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_vrf_status(void){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VRF_CON0);
	if (reg_val16 & VRF_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

//  (0x804) VRF_CON1
void dcl_pmu6236_vrf_cal(kal_uint8 val)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VRF_CON1);
	reg_val16 &= (~VRF_CAL_MASK);
	reg_val16 |= ((val << VRF_CAL_SHIFT) & VRF_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VRF_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x810) VTCXO_CON0
void dcl_pmu6236_vtcxo_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
    kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VTCXO_CON0);
	reg_val16 &= (~VTCXO_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VTCXO_EN_SHIFT) & VTCXO_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VTCXO_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vtcxo_on_sel(pmu6236_vtcxo_on_sel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VTCXO_CON0);
	reg_val16 &= (~VTCXO_ON_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VTCXO_ON_SEL_SHIFT) & VTCXO_ON_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VTCXO_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vtcxo_ndis_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VTCXO_CON0);
	reg_val16 &= (~VTCXO_NDIS_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VTCXO_NDIS_EN_SHIFT) & VTCXO_NDIS_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VTCXO_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vtcxo_stb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VTCXO_CON0);
	reg_val16 &= (~VTCXO_STB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VTCXO_STB_EN_SHIFT) & VTCXO_STB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VTCXO_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vtcxo_oc_auto_off(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VTCXO_CON0);
	reg_val16 &= (~VTCXO_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VTCXO_OC_AUTO_OFF_SHIFT) & VTCXO_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_VTCXO_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vtcxo_ocfb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VTCXO_CON0);
	reg_val16 &= (~VTCXO_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VTCXO_OCFB_EN_SHIFT) & VTCXO_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VTCXO_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_vtcxo_status(void){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VTCXO_CON0);
	if (reg_val16 & VTCXO_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x814) TCXO_CON1
void dcl_pmu6236_vtcxo_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val <16 );

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VTCXO_CON1);
	reg_val16 &= (~VTCXO_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VTCXO_CAL_SHIFT) & VTCXO_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VTCXO_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x820) VA_CON0
void dcl_pmu6236_va_sense(pmu6236_sense_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VA_CON0);
	reg_val16 &= (~VA_REMOTE_SENSE_MASK);
	reg_val16 |= (((kal_uint8)sel << VA_REMOTE_SENSE_SHIFT) & VA_REMOTE_SENSE_MASK);
	PMU_DRV_WriteReg16(PMIC_VA_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_va_ndis_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VA_CON0);
	reg_val16 &= (~VA_NDIS_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VA_NDIS_EN_SHIFT) & VA_NDIS_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VA_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_va_stb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VA_CON0);
	reg_val16 &= (~VA_STB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VA_STB_EN_SHIFT) & VA_STB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VA_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_va_oc_auto_off(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VA_CON0);
	reg_val16 &= (~VA_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VA_OC_AUTO_OFF_SHIFT) & VA_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_VA_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_va_ocfb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VA_CON0);
	reg_val16 &= (~VA_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VA_OCFB_EN_SHIFT) & VA_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VA_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_va_status(void){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VA_CON0);
	if (reg_val16 & VA_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x824) VA_CON1
void dcl_pmu6236_va_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VA_CON1);
	reg_val16 &= (~VA_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VA_CAL_SHIFT) & VA_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VA_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x830) VCAMA_CON0
void dcl_pmu6236_vcama_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMA_CON0);
	reg_val16 &= (~VCAMA_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMA_EN_SHIFT) & VCAMA_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMA_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcama_vosel(pmu6236_vcama_vosel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMA_CON0);
	reg_val16 &= (~VCAMA_VOSEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VCAMA_VOSEL_SHIFT) & VCAMA_VOSEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMA_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcama_ndis_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMA_CON0);
	reg_val16 &= (~VCAMA_NDIS_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMA_NDIS_EN_SHIFT) & VCAMA_NDIS_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMA_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcama_stb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMA_CON0);
	reg_val16 &= (~VCAMA_STB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMA_STB_EN_SHIFT) & VCAMA_STB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMA_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcama_oc_auto_off(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMA_CON0);
	reg_val16 &= (~VCAMA_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMA_OC_AUTO_OFF_SHIFT) & VCAMA_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMA_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcama_ocfb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMA_CON0);
	reg_val16 &= (~VCAMA_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMA_OCFB_EN_SHIFT) & VCAMA_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMA_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_vcama_status(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMA_CON0);
	if (reg_val16 & VCAMA_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x834) VCAMA_CON1
void dcl_pmu6236_vcama_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMA_CON1);
	reg_val16 &= (~VCAMA_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VCAMA_CAL_SHIFT) & VCAMA_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMA_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x838) VCAMA_CON2
void dcl_pmu6236_vcama_oc_td(pmu6236_oc_td_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMA_CON2);
	reg_val16 &= (~VCAMA_OC_TD_MASK);
	reg_val16 |= (((kal_uint8)sel << VCAMA_OC_TD_SHIFT) & VCAMA_OC_TD_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMA_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcama_stb_td(pmu6236_stb_td_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMA_CON2);
	reg_val16 &= (~VCAMA_STB_TD_MASK);
	reg_val16 |= (((kal_uint8)sel << VCAMA_STB_TD_SHIFT) & VCAMA_STB_TD_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMA_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x840) VCAMD_CON0
void dcl_pmu6236_vcamd_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMD_CON0);
	reg_val16 &= (~VCAMD_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMD_EN_SHIFT) & VCAMD_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMD_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcamd_vosel(pmu6236_vcamd_vosel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMD_CON0);
	reg_val16 &= (~VCAMD_VOSEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VCAMD_VOSEL_SHIFT) & VCAMD_VOSEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMD_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcamd_ndis_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMD_CON0);
	reg_val16 &= (~VCAMD_NDIS_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMD_NDIS_EN_SHIFT) & VCAMD_NDIS_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMD_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcamd_stb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMD_CON0);
	reg_val16 &= (~VCAMD_STB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMD_STB_EN_SHIFT) & VCAMD_STB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMD_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcamd_oc_auto_off(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMD_CON0);
	reg_val16 &= (~VCAMD_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMD_OC_AUTO_OFF_SHIFT) & VCAMD_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMD_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcamd_ocfb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMD_CON0);
	reg_val16 &= (~VCAMD_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMD_OCFB_EN_SHIFT) & VCAMD_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMD_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_vcamd_status(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMD_CON0);
	if (reg_val16 & VCAMD_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x844) VCAMD_CON1
void dcl_pmu6236_vcamd_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMD_CON1);
	reg_val16 &= (~VCAMD_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VCAMD_CAL_SHIFT) & VCAMD_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMD_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x850) VIO_CON0
void dcl_pmu6236_vio_sense(pmu6236_sense_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VIO_CON0);
	reg_val16 &= (~VIO_REMOTE_SENSE_MASK);
	reg_val16 |= (((kal_uint8)sel << VIO_REMOTE_SENSE_SHIFT) & VIO_REMOTE_SENSE_MASK);
	PMU_DRV_WriteReg16(PMIC_VIO_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vio_ndis_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VIO_CON0);
	reg_val16 &= (~VIO_NDIS_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VIO_NDIS_EN_SHIFT) & VIO_NDIS_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VIO_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vio_stb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VIO_CON0);
	reg_val16 &= (~VIO_STB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VIO_STB_EN_SHIFT) & VIO_STB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VIO_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vio_oc_auto_off(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VIO_CON0);
	reg_val16 &= (~VIO_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VIO_OC_AUTO_OFF_SHIFT) & VIO_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_VIO_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vio_ocfb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VIO_CON0);
	reg_val16 &= (~VIO_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VIO_OCFB_EN_SHIFT) & VIO_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VIO_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_vio_status(void){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VIO_CON0);
	if (reg_val16 & VIO_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (Ox854) VIO_CON1
void dcl_pmu6236_vio_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VIO_CON1);
	reg_val16 &= (~VIO_CAL_MASK);
	reg_val16 |= ((val << VIO_CAL_SHIFT) & VIO_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VIO_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x858) VIO_CON2
void dcl_pmu6236_vio_oc_td(pmu6236_oc_td_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VIO_CON2);
	reg_val16 &= (~VIO_OC_TD_MASK);
	reg_val16 |= (((kal_uint8)sel << VIO_OC_TD_SHIFT) & VIO_OC_TD_MASK);
	PMU_DRV_WriteReg16(PMIC_VIO_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x860) VUSB_CON0
void dcl_pmu6236_vusb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VUSB_CON0);
	reg_val16 &= (~VUSB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VUSB_EN_SHIFT) & VUSB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VUSB_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vusb_ndis_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VUSB_CON0);
	reg_val16 &= (~VUSB_NDIS_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VUSB_NDIS_EN_SHIFT) & VUSB_NDIS_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VUSB_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vusb_stb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VUSB_CON0);
	reg_val16 &= (~VUSB_STB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VUSB_STB_EN_SHIFT) & VUSB_STB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VUSB_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vusb_oc_auto_off(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VUSB_CON0);
	reg_val16 &= (~VUSB_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VUSB_OC_AUTO_OFF_SHIFT) & VUSB_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_VUSB_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vusb_ocfb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VUSB_CON0);
	reg_val16 &= (~VUSB_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VUSB_OCFB_EN_SHIFT) & VUSB_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VUSB_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_vusb_status(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VUSB_CON0);
	if (reg_val16 & VUSB_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x864) VUSB_CON1
void dcl_pmu6236_vusb_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VUSB_CON1);
	reg_val16 &= (~VUSB_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VUSB_CAL_SHIFT) & VUSB_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VUSB_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}


// (0x868) VUSB_CON2
void dcl_pmu6236_vusb_oc_td(pmu6236_oc_td_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VUSB_CON2);
	reg_val16 &= (~VUSB_OC_TD_MASK);
	reg_val16 |= (((kal_uint8)sel << VUSB_OC_TD_SHIFT) & VUSB_OC_TD_MASK);
	PMU_DRV_WriteReg16(PMIC_VUSB_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x870) VBT_CON0
void dcl_pmu6236_vbt_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBT_CON0);
	reg_val16 &= (~VBT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBT_EN_SHIFT) & VBT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VBT_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vbt_vosel(pmu6236_vbt_sel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBT_CON0);
	reg_val16 &= (~VBT_VOSEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VBT_VOSEL_SHIFT) & VBT_VOSEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VBT_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vbt_ndis_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBT_CON0);
	reg_val16 &= (~VBT_NDIS_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBT_NDIS_EN_SHIFT) & VBT_NDIS_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VBT_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vbt_stb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBT_CON0);
	reg_val16 &= (~VBT_STB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBT_STB_EN_SHIFT) & VBT_STB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VBT_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vbt_oc_auto_off(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBT_CON0);
	reg_val16 &= (~VBT_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VBT_OC_AUTO_OFF_SHIFT) & VBT_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_VBT_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vbt_ocfb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBT_CON0);
	reg_val16 &= (~VBT_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBT_OCFB_EN_SHIFT) & VBT_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VBT_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_vbt_status(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBT_CON0);
	if (reg_val16 & VBT_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x874) VBT_CON1
void dcl_pmu6236_vbt_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBT_CON1);
	reg_val16 &= (~VBT_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VBT_CAL_SHIFT) & VBT_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VBT_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x878) VBT_CON2
void dcl_pmu6236_vbt_oc_td(pmu6236_oc_td_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBT_CON2);
	reg_val16 &= (~VBT_OC_TD_MASK);
	reg_val16 |= (((kal_uint8)sel << VBT_OC_TD_SHIFT) & VBT_OC_TD_MASK);
	PMU_DRV_WriteReg16(PMIC_VBT_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x880) VSIM_CON0
void dcl_pmu6236_vsim_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM_CON0);
	reg_val16 &= (~VSIM_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM_EN_SHIFT) & VSIM_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vsim_vosel(pmu6236_vsim_vosel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM_CON0);
	reg_val16 &= (~VSIM_VOSEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VSIM_VOSEL_SHIFT) & VSIM_VOSEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vsim_ndis_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM_CON0);
	reg_val16 &= (~VSIM_NDIS_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM_NDIS_EN_SHIFT) & VSIM_NDIS_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vsim_stb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM_CON0);
	reg_val16 &= (~VSIM_STB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM_STB_EN_SHIFT) & VSIM_STB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vsim_oc_auto_off(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM_CON0);
	reg_val16 &= (~VSIM_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM_OC_AUTO_OFF_SHIFT) & VSIM_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vsim_ocfb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM_CON0);
	reg_val16 &= (~VSIM_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM_OCFB_EN_SHIFT) & VSIM_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_vsim_status(void){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM_CON0);
	if (reg_val16 & VSIM_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x884) VSIM_CON1
void dcl_pmu6236_vsim_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM_CON1);
	reg_val16 &= (~VSIM_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VSIM_CAL_SHIFT) & VSIM_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x888) VSIM_CON2
void dcl_pmu6236_vsim_oc_td(pmu6236_oc_td_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM_CON2);
	reg_val16 &= (~VSIM_OC_TD_MASK);
	reg_val16 |= (((kal_uint8)sel << VSIM_OC_TD_SHIFT) & VSIM_OC_TD_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x890) VSIM2_CON0
void dcl_pmu6236_vsim2_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM2_CON0);
	reg_val16 &= (~VSIM2_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM2_EN_SHIFT) & VSIM2_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM2_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vsim2_vosel(pmu6236_vsim2_vosel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM2_CON0);
	reg_val16 &= (~VSIM2_VOSEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VSIM2_VOSEL_SHIFT) & VSIM2_VOSEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM2_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vsim2_ndis_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM2_CON0);
	reg_val16 &= (~VSIM2_NDIS_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM2_NDIS_EN_SHIFT) & VSIM2_NDIS_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM2_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vsim2_stb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM2_CON0);
	reg_val16 &= (~VSIM2_STB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM2_STB_EN_SHIFT) & VSIM2_STB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM2_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vsim2_oc_auto_off(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM2_CON0);
	reg_val16 &= (~VSIM2_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM2_OC_AUTO_OFF_SHIFT) & VSIM2_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM2_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vsim2_ocfb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM2_CON0);
	reg_val16 &= (~VSIM2_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM2_OCFB_EN_SHIFT) & VSIM2_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM2_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_vsim2_status(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM2_CON0);
	if (reg_val16 & VSIM2_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x894) VSIM2_CON1
void dcl_pmu6236_vsim2_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM2_CON1);
	reg_val16 &= (~VSIM2_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VSIM2_CAL_SHIFT) & VSIM2_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM2_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x898) VSIM2_CON2
void dcl_pmu6236_vsim2_gpldo_en(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM2_CON2);
	reg_val16 &= (~VSIM2_GPLDO_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM2_GPLDO_EN_SHIFT) & VSIM2_GPLDO_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM2_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x8A0) VBACKUP_CON0
void dcl_pmu6236_vbackup_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBACKUP_CON0);
	reg_val16 &= (~VBACKUP_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBACKUP_EN_SHIFT) & VBACKUP_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VBACKUP_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vbackup_ndis_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBACKUP_CON0);
	reg_val16 &= (~VBACKUP_NDIS_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBACKUP_NDIS_EN_SHIFT) & VBACKUP_NDIS_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VBACKUP_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vbackup_stb_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBACKUP_CON0);
	reg_val16 &= (~VBACKUP_STB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBACKUP_STB_EN_SHIFT) & VBACKUP_STB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VBACKUP_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vbackup_oc_auto_off(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBACKUP_CON0);
	reg_val16 &= (~VBACKUP_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VBACKUP_OC_AUTO_OFF_SHIFT) & VBACKUP_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_VBACKUP_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vbackup_ocfb_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBACKUP_CON0);
	reg_val16 &= (~VBACKUP_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBACKUP_OCFB_EN_SHIFT) & VBACKUP_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VBACKUP_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_vbackup_status(void)
{
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBACKUP_CON0);
	if (reg_val16 & VBACKUP_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x8B0) VIBR_CON0
void dcl_pmu6236_vibr_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBIR_CON0);
	reg_val16 &= (~VIBR_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VIBR_EN_SHIFT) & VIBR_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VBIR_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vibr_vosel(pmu6236_vibr_vosel_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBIR_CON0);
	reg_val16 &= (~VIBR_VOSEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VIBR_VOSEL_SHIFT) & VIBR_VOSEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VBIR_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vibr_ndis_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBIR_CON0);
	reg_val16 &= (~VIBR_NDIS_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VIBR_NDIS_EN_SHIFT) & VIBR_NDIS_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VBIR_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vibr_stb_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBIR_CON0);
	reg_val16 &= (~VIBR_STB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VIBR_STB_EN_SHIFT) & VIBR_STB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VBIR_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vibr_oc_auto_off(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBIR_CON0);
	reg_val16 &= (~VIBR_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VIBR_OC_AUTO_OFF_SHIFT) & VIBR_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_VBIR_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vibr_ocfb_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBIR_CON0);
	reg_val16 &= (~VIBR_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VIBR_OCFB_EN_SHIFT) & VIBR_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VBIR_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_vibr_status(void)
{
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBIR_CON0);
	if (reg_val16 & VIBR_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x8B4) VIBR_CON1
void dcl_pmu6236_vibr_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBIR_CON1);
	reg_val16 &= (~VIBR_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VIBR_CAL_SHIFT) & VIBR_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VBIR_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x8C0) VMC_CON0
void dcl_pmu6236_vmc_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

// MSDC and efuse share VMC LDO  , if MSDC turn off VMC ,it cause efuse data error
// so we always turn on VMC LDO
        if (enable!=KAL_TRUE)
            return;
	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VMC_CON0);
	reg_val16 &= (~VMC_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VMC_EN_SHIFT) & VMC_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VMC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vmc_vosel(pmu6236_vmc_vosel_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VMC_CON0);
	reg_val16 &= (~VMC_VOSEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VMC_VOSEL_SHIFT) & VMC_VOSEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VMC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vmc_ndis_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VMC_CON0);
	reg_val16 &= (~VMC_NDIS_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VMC_NDIS_EN_SHIFT) & VMC_NDIS_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VMC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vmc_stb_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VMC_CON0);
	reg_val16 &= (~VMC_STB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VMC_STB_EN_SHIFT) & VMC_STB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VMC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vmc_oc_auto_off(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VMC_CON0);
	reg_val16 &= (~VMC_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VMC_OC_AUTO_OFF_SHIFT) & VMC_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_VMC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vmc_ocfb_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VMC_CON0);
	reg_val16 &= (~VMC_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VMC_OCFB_EN_SHIFT) & VMC_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VMC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_vmc_status(void)
{
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VMC_CON0);
	if (reg_val16 & VMC_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x08C4) VMC_CON1
void dcl_pmu6236_vmc_cal(kal_uint8 val)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val <16);

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VMC_CON1);
	reg_val16 &= (~VMC_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VMC_CAL_SHIFT) & VMC_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VMC_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x900) VCORE_CON0
void dcl_pmu6236_vcore_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON0);
	reg_val16 &= (~VCORE_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCORE_EN_SHIFT) & VCORE_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcore_sense(pmu6236_sense_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON0);
	reg_val16 &= (~VCORE_REMOTE_SENSE_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_REMOTE_SENSE_SHIFT) & VCORE_REMOTE_SENSE_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcore_vfbadj(pmu6236_vcore_vfbadj_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON0);
	reg_val16 &= (~VCORE_VFBADJ_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_VFBADJ_SHIFT) & VCORE_VFBADJ_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_uint16 dcl_pmu6236_get_vcore_vfbadj(void)
{
	kal_uint16   value;
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON0);
	value = (reg_val16 & VCORE_VFBADJ_MASK) >> VCORE_VFBADJ_SHIFT;
	return value;
}

void dcl_pmu6236_vcore_stb_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON0);
	reg_val16 &= (~VCORE_STB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCORE_STB_EN_SHIFT) & VCORE_STB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}
void dcl_pmu6236_vcore_oc_auto_off(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON0);
	reg_val16 &= (~VCORE_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VCORE_OC_AUTO_OFF_SHIFT) & VCORE_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcore_ocfb_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON0);
	reg_val16 &= (~VCORE_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCORE_OCFB_EN_SHIFT) & VCORE_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_vcore_status(void)
{
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON0);
	if (reg_val16 & VCORE_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x904) VCORE_CON1
void dcl_pmu6236_vcore_modeset(pmu6236_vcore_modeset_enum mode){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON1);
	reg_val16 &= (~VCORE_MODE_SET_MASK);
	reg_val16 |= (((kal_uint8)mode << VCORE_MODE_SET_SHIFT) & VCORE_MODE_SET_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcore_vfbadj_slp(pmu6236_vcore_vfbadj_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON1);
	reg_val16 &= (~VCORE_VFBADJ_SLEEP_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_VFBADJ_SLEEP_SHIFT) & VCORE_VFBADJ_SLEEP_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_bl_control_WA(DCL_BOOL enable)
{
	kal_uint32  savedMask;
	if (enable)
	{
		savedMask = SaveAndSetIRQMask();
		PMU_DRV_SetData16(MT6236_HW_MISC_REG_ADDR, MT6236_HW_MISC_REG_FORCE_SRCLKENAI_MASK, (1 << MT6236_HW_MISC_REG_FORCE_SRCLKENAI_SHIFT));
		PMU_DRV_SetData16(MT6236_IDN_SEL_REG_ADDR, MT6236_IDN_SEL_REG_CLKSQ_MASK, (1 << MT6236_IDN_SEL_REG_CLKSQ_SHIFT));
		RestoreIRQMask(savedMask);
		// When backlight is enabled, limit DVS to 1.2V
		dcl_pmu6236_vcore_vfbadj_slp(VCORE_VFBADJ_1_2V);
	}
	else
	{
		savedMask = SaveAndSetIRQMask();
		PMU_DRV_SetData16(MT6236_HW_MISC_REG_ADDR, MT6236_HW_MISC_REG_FORCE_SRCLKENAI_MASK, (0 << MT6236_HW_MISC_REG_FORCE_SRCLKENAI_SHIFT));
		PMU_DRV_SetData16(MT6236_IDN_SEL_REG_ADDR, MT6236_IDN_SEL_REG_CLKSQ_MASK, (0 << MT6236_IDN_SEL_REG_CLKSQ_SHIFT));
		RestoreIRQMask(savedMask);
		// When backlight is enabled, allow DVS to 1.0V
#if defined(__AST2001__)
        dcl_pmu6236_vcore_vfbadj_slp(VCORE_VFBADJ_1_1V);
#else
        dcl_pmu6236_vcore_vfbadj_slp(VCORE_VFBADJ_1_0V);
#endif
		
	}
}


kal_uint16 dcl_pmu6236_get_vcore_vfbadj_slp(void)
{
	kal_uint16   value;
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON1);
	value = (reg_val16 & VCORE_VFBADJ_SLEEP_MASK) >> VCORE_VFBADJ_SLEEP_SHIFT;
	return value;
}

// (0x908) VCORE_CON2
void dcl_pmu6236_vcore_vosel(pmu6236_vcore_vosel_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON2);
	reg_val16 &= (~VCORE_VOSEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_VOSEL_SHIFT) & VCORE_VOSEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcore_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val <16);

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON2);
	reg_val16 &= (~VCORE_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VCORE_CAL_SHIFT) & VCORE_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x90C) VCORE_CON3
void dcl_pmu6236_vcore_ical_en(kal_uint8 sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON3);
	reg_val16 &= (~VCORE_ICAL_EN_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_ICAL_EN_SHIFT) & VCORE_ICAL_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x914) VCORE_CON5
void dcl_pmu6236_vcore_csl(pmu6236_vcore_csl_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON5);
	reg_val16 &= (~VCORE_CSL_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_CSL_SHIFT) & VCORE_CSL_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON5, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcore_burst(pmu6236_vcore_burst_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON5);
	reg_val16 &= (~VCORE_BURST_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_BURST_SHIFT) & VCORE_BURST_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON5, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x920) VM_CON0
void dcl_pmu6236_vm_sense(pmu6236_sense_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VM_CON0);
	reg_val16 &= (~VA_REMOTE_SENSE_MASK);
	reg_val16 |= (((kal_uint8)sel << VA_REMOTE_SENSE_SHIFT) & VA_REMOTE_SENSE_MASK);
	PMU_DRV_WriteReg16(PMIC_VM_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vm_stb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VM_CON0);
	reg_val16 &= (~VM_STB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VM_STB_EN_SHIFT) & VM_STB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VM_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vm_oc_auto_off(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VM_CON0);
	reg_val16 &= (~VM_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VM_OC_AUTO_OFF_SHIFT) & VM_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_VM_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vm_ocfb_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VM_CON0);
	reg_val16 &= (~VM_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VM_OCFB_EN_SHIFT) & VM_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VM_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_vm_status(void){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VM_CON0);
	if (reg_val16 & VM_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x928) VM_COM2
void dcl_pmu6236_vm_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VM_CON2);
	reg_val16 &= (~VM_CAL_MASK);
	reg_val16 |= ((val << VM_CAL_SHIFT) & VM_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VM_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x92C) VM_CON3
void dcl_pmu6236_vm_ical_en(kal_uint8 sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON3);
	reg_val16 &= (~VM_ICAL_EN_MASK);
	reg_val16 |= (((kal_uint8)sel << VM_ICAL_EN_SHIFT) & VM_ICAL_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x934) VM_CON5
void dcl_pmu6236_vm_csl(pmu6236_vm_csl_enum val)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VM_CON5);
	reg_val16 &= (~VM_CSL_MASK);
	reg_val16 |= ((val << VM_CSL_SHIFT) & VM_CSL_MASK);
	PMU_DRV_WriteReg16(PMIC_VM_CON5, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vm_burst(pmu6236_vm_burst_enum val)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VM_CON5);
	reg_val16 &= (~VM_BURST_MASK);
	reg_val16 |= ((val << VM_BURST_SHIFT) & VM_BURST_MASK);
	PMU_DRV_WriteReg16(PMIC_VM_CON5, reg_val16);

	RestoreIRQMask(savedMask);
}


// (0xA00) CHR_CON0
void dcl_pmu6236_chr_vcdt_lv_vth(kal_uint8 val)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON0);
	reg_val16 &= (~VCDT_LV_VTH_MASK);
	reg_val16 |= (((kal_uint16)val << VCDT_LV_VTH_SHIFT) & VCDT_LV_VTH_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_chr_vcdt_hv_vth(kal_uint8 val)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON0);
	reg_val16 &= (~VCDT_HV_VTH_MASK);
	reg_val16 |= (((kal_uint16)val << VCDT_HV_VTH_SHIFT) & VCDT_HV_VTH_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_chr_vcdt_hv_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON0);
	reg_val16 &= (~VCDT_HV_EN_MASK);
	reg_val16 |= (((kal_uint16)enable << VCDT_HV_EN_SHIFT) & VCDT_HV_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON0, reg_val16);

	RestoreIRQMask(savedMask);

}





DCL_BOOL dcl_pmu6236_chr_chrdet(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON0);
	if (reg_val16 & CHRDET_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

DCL_BOOL dcl_pmu6236_chr_ovp(void)
{
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON0);
	if (reg_val16 & VCDT_HV_DET_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0xA04) CHR_CON1
void dcl_pmu6236_chr_vbat_cv_vth(pmu6236_chr_vbat_cv_enum cv)
{
	kal_uint16  reg_val16;

#if defined(PMIC_6236_CV_TRIM_CALIBRATION)
    if(mt6236_efuse_vbat_cv >= 2)
    {
    	 cv=(pmu6236_chr_vbat_cv_enum)(mt6236_efuse_vbat_cv - 2);
    }
#endif // #if defined(PMIC_6236_CV_TRIM_CALIBRATION)

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON1);
	reg_val16 &= (~VBAT_CV_VTH_MASK);
	reg_val16 |= (((kal_uint16)cv << VBAT_CV_VTH_SHIFT) & VBAT_CV_VTH_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON1, reg_val16);
}

void dcl_pmu6236_chr_vbat_cc_vth(pmu6236_chr_vbat_cc_enum cc)
{
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON1);
	reg_val16 &= (~VBAT_CC_VTH_MASK);
	reg_val16 |= (((kal_uint16)cc << VBAT_CC_VTH_SHIFT) & VBAT_CC_VTH_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON1, reg_val16);
}

void dcl_pmu6236_chr_vbat_cv_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON1);
	reg_val16 &= (~VBAT_CV_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBAT_CV_EN_SHIFT) & VBAT_CV_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON1, reg_val16);
}

void dcl_pmu6236_chr_vbat_cc_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON1);
	reg_val16 &= (~VBAT_CC_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBAT_CC_EN_SHIFT) & VBAT_CC_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON1, reg_val16);
}

DCL_BOOL dcl_pmu6236_chr_cv_det(void)
{
	kal_uint16  reg_val16;

	dcl_pmu6236_chr_vbat_cv_enable(KAL_TRUE);
	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON1);
	if (reg_val16 & VBAT_CV_DET_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

DCL_BOOL dcl_pmu6236_chr_cc_det(void)
{
	kal_uint16  reg_val16;

	dcl_pmu6236_chr_vbat_cc_enable(KAL_TRUE); //prevent overwrite or clear by others..
	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON1);
	if (reg_val16 & VBAT_CC_DET_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0xA08) CHR_CON2
void dcl_pmu6236_chr_cs_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON2);
	reg_val16 &= (~CS_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << CS_EN_SHIFT) & CS_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON2, reg_val16);
}

void dcl_pmu6236_chr_current(pmu6236_chr_current_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON2);
	reg_val16 &= (~CS_VTH_MASK);
	reg_val16 |= (((kal_uint8)sel << CS_VTH_SHIFT) & CS_VTH_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0xA0C) CHR_CON3
void dcl_pmu6236_chr_csdac_dly(kal_uint32 sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON3);
	reg_val16 &= (~CSDAC_DLY_MASK);
	reg_val16 |= (((kal_uint8)sel << CSDAC_DLY_SHIFT) & CSDAC_DLY_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_chr_csdac_stp(kal_uint32 sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON3);
	reg_val16 &= (~CSDAC_STP_MASK);
	reg_val16 |= (((kal_uint8)sel << CSDAC_STP_SHIFT) & CSDAC_STP_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0xA14) CHR_CON5
kal_uint16 dcl_pmu6236_chr_control_state(kal_uint16 sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(sel <= 0xF);
	savedMask = SaveAndSetIRQMask();
	// When set select, also set EN bit
	PMU_DRV_WriteReg16(PMIC_CHR_CON5, (PCHR_FLAG_EN_MASK | ((sel & PCHR_FLAG_SEL_MASK) << PCHR_FLAG_SEL_SHIFT)));

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON5);
	RestoreIRQMask(savedMask);

	return reg_val16;
}

pmu6236_pchr_state_enum dcl_pmu6236_get_pchr_state(void)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	// When set select, also set EN bit
	PMU_DRV_WriteReg16(PMIC_CHR_CON5, (PCHR_FLAG_EN_MASK | ((PCHR_CMD_PCHR_STATE & PCHR_FLAG_SEL_MASK) << PCHR_FLAG_SEL_SHIFT)));

	// Need to wait till mechanism ready???
	// It is a MUX operation, just show out selected bits status

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON5);

	// After get result, disable EN bit
	reg_val16 &= ~PCHR_FLAG_EN_MASK;
	PMU_DRV_WriteReg16(PMIC_CHR_CON5, reg_val16);

	RestoreIRQMask(savedMask);

	return (pmu6236_pchr_state_enum)( ( ( (reg_val16 & PCHR_FLAG_OUT_MASK) >> PCHR_FLAG_OUT_SHIFT ) & PCHR_STATE_MASK) >> PCHR_STATE_SHIFT );
}

// (0xA18) CHR_CON6
void dcl_pmu6236_chr_wdt_td(pmu6236_chr_wdt_td_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(sel <= 3);
	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON6);
	reg_val16 &= (~CHRWDT_TD_MASK);
	reg_val16 |= (((kal_uint8)sel << CHRWDT_TD_SHIFT) & CHRWDT_TD_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON6, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_chr_wdt_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON6);
	reg_val16 &= (~CHRWDT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << CHRWDT_EN_SHIFT) & CHRWDT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON6, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0xA1C) CHR_CON7
void dcl_pmu6236_chr_wdt_intr_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON7);
	reg_val16 &= (~CHRWDT_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << CHRWDT_INT_EN_SHIFT) & CHRWDT_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON7, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_chr_wdt_status(void)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;
	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON7);

	RestoreIRQMask(savedMask);


	if ((reg_val16 & CHRWDT_FLAG_MASK) != 0)
	{
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

void dcl_pmu6236_chr_wdt_clear(void)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;
	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON7);
	reg_val16 |= CHRWDT_FLAG_MASK;
	PMU_DRV_WriteReg16(PMIC_CHR_CON7, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0xA20) CHR_CON8
void dcl_pmu6236_chr_adc_meas_on(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON8);
	reg_val16 |= ADCIN_VCHR_EN | ADCIN_VSEN_EN | ADCIN_VBAT_EN;
	PMU_DRV_WriteReg16(PMIC_CHR_CON8, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_chr_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	// kick CHR WDT
	dcl_pmu6236_chr_cs_enable(KAL_TRUE);
	dcl_pmu6236_chr_adc_meas_on(KAL_TRUE);

	dcl_pmu6236_chr_vbat_cc_vth(CHR_VBAT_CC_3_300V);

	#if defined(PMIC_6236_CV_TRIM_CALIBRATION)
	dcl_pmu6236_chr_vbat_cv_vth(mt6236_efuse_vbat_cv);
	#else // #if defined(PMIC_6236_CV_TRIM_CALIBRATION)
	dcl_pmu6236_chr_vbat_cv_vth(CHR_VBAT_CV_4_2000V);
	#endif // #if defined(PMIC_6236_CV_TRIM_CALIBRATION)

	dcl_pmu6236_chr_vbat_cc_enable(KAL_TRUE);
	dcl_pmu6236_chr_vbat_cv_enable(KAL_TRUE);
    dcl_pmu6236_chr_vcdt_hv_enable(KAL_TRUE);    

	dcl_pmu6236_chr_csdac_dly(0x3);
	dcl_pmu6236_chr_csdac_stp(0x0);

	dcl_pmu6236_chr_wdt_td(CHR_WDT_32_SEC);
	dcl_pmu6236_chr_wdt_intr_enable(KAL_TRUE);

	dcl_pmu6236_chr_wdt_enable(KAL_TRUE);
	dcl_pmu6236_chr_wdt_clear();

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON0);
	reg_val16 &= (~CHR_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << CHR_EN_SHIFT) & CHR_EN_MASK);
	reg_val16 &= (~CSDAC_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << CSDAC_EN_SHIFT) & CSDAC_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0xB00) BOOST_CON0
void dcl_pmu6236_vboost_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_BOOST_CON0);
	reg_val16 &= (~VBOOST_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBOOST_EN_SHIFT) & VBOOST_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_BOOST_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_get_vboost_enable(void)
{
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_BOOST_CON0);
	if (reg_val16 & VBOOST_EN_MASK)
	{
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

void dcl_pmu6236_vboost_type(pmu6236_vboost_type_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(sel <= 1);

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_BOOST_CON0);
	reg_val16 &= (~VBOOST_TYPE_MASK);
	reg_val16 |= (((kal_uint8)sel << VBOOST_TYPE_SHIFT) & VBOOST_TYPE_MASK);
	PMU_DRV_WriteReg16(PMIC_BOOST_CON0, reg_val16);
	RestoreIRQMask(savedMask);
}

pmu6236_vboost_type_enum dcl_pmu6236_get_vboost_type(void)
{
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_BOOST_CON0);

	return (pmu6236_vboost_type_enum) ( (reg_val16 & VBOOST_TYPE_MASK) >> VBOOST_TYPE_SHIFT );


	//if (reg_val16 & VBOOST_TYPE_MASK)
	//{
	//	return VBOOST_TYPE_VOLTAGE_CONTROLLER;
	//}
	//else
	//{
	//	return VBOOST_TYPE_CURRENT_CONVERTER;
	//}
}

void dcl_pmu6236_vboost_mode(pmu6236_vboost_mode_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(sel <= 1);

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_BOOST_CON0);
	reg_val16 &= (~VBOOST_MODE_MASK);
	reg_val16 |= (((kal_uint8)sel << VBOOST_MODE_SHIFT) & VBOOST_MODE_MASK);
	PMU_DRV_WriteReg16(PMIC_BOOST_CON0, reg_val16);
	RestoreIRQMask(savedMask);
}

pmu6236_vboost_mode_enum dcl_pmu6236_get_vboost_mode(void)
{
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_BOOST_CON0);

	return (pmu6236_vboost_mode_enum)( (reg_val16 & VBOOST_MODE_MASK) >> VBOOST_MODE_SHIFT );

	//if (reg_val16 & VBOOST_MODE_MASK)
	//{
	//	return VBOOST_NORMAL_MODE;
	//}
	//else
	//{
	//	return VBOOST_DIMMING_MODE;
	//}
}

void dcl_pmu6236_vboost_vrsel(kal_uint16 val)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_BOOST_CON0);
	reg_val16 &= (~VBOOST_VRSEL_MASK);
	reg_val16 |= (((kal_uint8)val << VBOOST_VRSEL_SHIFT) & VBOOST_VRSEL_MASK);
	PMU_DRV_WriteReg16(PMIC_BOOST_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_uint16 dcl_pmu6236_get_vboost_vrsel(void)
{
	kal_uint8   value;
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_BOOST_CON0);
	value = (reg_val16 & VBOOST_VRSEL_MASK) >> VBOOST_VRSEL_SHIFT;
	return value;
}

// (0xB0C) BOOST_CON3
void dcl_pmu6236_vboost_cks_prg(kal_uint8 val)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_BOOST_CON3);
	reg_val16 &= (~VBOOST_CKS_PRG_MASK);
	reg_val16 |= (((kal_uint8)val << VBOOST_CKS_PRG_SHIFT) & VBOOST_CKS_PRG_MASK);
	PMU_DRV_WriteReg16(PMIC_BOOST_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0xC00) ISINK0_CON0
void dcl_pmu6236_isink0_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK0_CON0);
	reg_val16 &= (~ISINK0_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << ISINK0_EN_SHIFT) & ISINK0_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_ISINK0_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_isink0_mode(pmu6236_isink_mode_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK0_CON0);
	reg_val16 &= (~ISINK0_MODE_MASK);
	reg_val16 |= (((kal_uint8)sel << ISINK0_MODE_SHIFT) & ISINK0_MODE_MASK);
	PMU_DRV_WriteReg16(PMIC_ISINK0_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_isink0_step(pmu6236_isink_step_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK0_CON0);
	reg_val16 &= (~ISINK0_STEP_MASK);
	reg_val16 |= (((kal_uint8)sel << ISINK0_STEP_SHIFT) & ISINK0_STEP_MASK);
	PMU_DRV_WriteReg16(PMIC_ISINK0_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_isink0_status(void)
{
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK0_CON0);
	if (reg_val16 & ISINK0_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}


// (0xC10) ISINK1_CON0
void dcl_pmu6236_isink1_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK1_CON0);
	reg_val16 &= (~ISINK1_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << ISINK1_EN_SHIFT) & ISINK1_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_ISINK1_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_isink1_mode(pmu6236_isink_mode_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK1_CON0);
	reg_val16 &= (~ISINK1_MODE_MASK);
	reg_val16 |= (((kal_uint8)sel << ISINK1_MODE_SHIFT) & ISINK1_MODE_MASK);
	PMU_DRV_WriteReg16(PMIC_ISINK1_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_isink1_step(pmu6236_isink_step_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK1_CON0);
	reg_val16 &= (~ISINK1_STEP_MASK);
	reg_val16 |= (((kal_uint8)sel << ISINK1_STEP_SHIFT) & ISINK1_STEP_MASK);
	PMU_DRV_WriteReg16(PMIC_ISINK1_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_isink1_status(void)
{
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK1_CON0);
	if (reg_val16 & ISINK1_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0xC20) ISINK2_CON0
void dcl_pmu6236_isink2_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK2_CON0);
	reg_val16 &= (~ISINK2_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << ISINK2_EN_SHIFT) & ISINK2_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_ISINK2_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_isink2_mode(pmu6236_isink_mode_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK2_CON0);
	reg_val16 &= (~ISINK2_MODE_MASK);
	reg_val16 |= (((kal_uint8)sel << ISINK2_MODE_SHIFT) & ISINK2_MODE_MASK);
	PMU_DRV_WriteReg16(PMIC_ISINK2_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_isink2_step(pmu6236_isink_step_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK2_CON0);
	reg_val16 &= (~ISINK2_STEP_MASK);
	reg_val16 |= (((kal_uint8)sel << ISINK2_STEP_SHIFT) & ISINK2_STEP_MASK);
	PMU_DRV_WriteReg16(PMIC_ISINK2_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_isink2_status(void)
{
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK2_CON0);
	if (reg_val16 & ISINK2_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0xC30) ISINK3_CON0
void dcl_pmu6236_isink3_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK3_CON0);
	reg_val16 &= (~ISINK3_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << ISINK3_EN_SHIFT) & ISINK3_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_ISINK3_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_isink3_mode(pmu6236_isink_mode_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK3_CON0);
	reg_val16 &= (~ISINK3_MODE_MASK);
	reg_val16 |= (((kal_uint8)sel << ISINK3_MODE_SHIFT) & ISINK3_MODE_MASK);
	PMU_DRV_WriteReg16(PMIC_ISINK3_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_isink3_step(pmu6236_isink_step_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK3_CON0);
	reg_val16 &= (~ISINK3_STEP_MASK);
	reg_val16 |= (((kal_uint8)sel << ISINK3_STEP_SHIFT) & ISINK3_STEP_MASK);
	PMU_DRV_WriteReg16(PMIC_ISINK3_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_isink3_status(void)
{
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK3_CON0);
	if (reg_val16 & ISINK3_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0xC40) ISINK4_CON0
void dcl_pmu6236_isink4_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK4_CON0);
	reg_val16 &= (~ISINK4_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << ISINK4_EN_SHIFT) & ISINK4_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_ISINK4_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_isink4_mode(pmu6236_isink_mode_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK4_CON0);
	reg_val16 &= (~ISINK4_MODE_MASK);
	reg_val16 |= (((kal_uint8)sel << ISINK4_MODE_SHIFT) & ISINK4_MODE_MASK);
	PMU_DRV_WriteReg16(PMIC_ISINK4_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_isink4_step(pmu6236_isink_step_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK4_CON0);
	reg_val16 &= (~ISINK4_STEP_MASK);
	reg_val16 |= (((kal_uint8)sel << ISINK4_STEP_SHIFT) & ISINK4_STEP_MASK);
	PMU_DRV_WriteReg16(PMIC_ISINK4_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_isink4_status(void)
{
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_ISINK4_CON0);
	if (reg_val16 & ISINK4_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0xC80) KPLED_CON0
void dcl_pmu6236_kpled_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_KPLED_CON0);
	reg_val16 &= (~KPLED_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << KPLED_EN_SHIFT) & KPLED_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_KPLED_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_kpled_mode(pmu6236_kpled_mode_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT((kal_uint8)sel < 2);

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_KPLED_CON0);
	reg_val16 &= (~KPLED_MODE_MASK);
	reg_val16 |= (((kal_uint8)sel << KPLED_MODE_SHIFT) & KPLED_MODE_MASK);
	PMU_DRV_WriteReg16(PMIC_KPLED_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_kpled_sel(kal_uint8 val)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val<7);

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_KPLED_CON0);
	reg_val16 &= (~KPLED_SEL_MASK);
	reg_val16 |= (((kal_uint8)val << KPLED_SEL_SHIFT) & KPLED_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_KPLED_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_kpled_status(void)
{
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_KPLED_CON0);
	if (reg_val16 & KPLED_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0xC90) FLASH_CON0
void dcl_pmu6236_flash_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_FLASH_CON0);
	reg_val16 &= (~FLASH_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << FLASH_EN_SHIFT) & FLASH_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_FLASH_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_flash_mode(pmu6236_flash_mode_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_FLASH_CON0);
	reg_val16 &= (~FLASH_MODE_MASK);
	reg_val16 |= (((kal_uint8)sel << FLASH_MODE_SHIFT) & FLASH_MODE_MASK);
	PMU_DRV_WriteReg16(PMIC_FLASH_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_flash_sel(kal_uint8 sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(sel<8);

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_FLASH_CON0);
	reg_val16 &= (~FLASH_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << FLASH_SEL_SHIFT) & FLASH_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_FLASH_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_flash_status(void)
{
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_FLASH_CON0);
	if (reg_val16 & FLASH_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0xD00) SPK_CON0
void dcl_pmu6236_spk_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_SPK_CON0);
	reg_val16 &= (~SPK_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << SPK_EN_SHIFT) & SPK_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_SPK_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6236_get_spk_enable(void)
{
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_SPK_CON0);

	return (DCL_BOOL) ( (reg_val16 & SPK_EN_MASK) >> SPK_EN_SHIFT);

	//if (reg_val16 & SPK_EN_MASK)
	//{
	//	return KAL_TRUE;
	//}
	//else
	//{
	//	return KAL_FALSE;
	//}
}

void dcl_pmu6236_spk_vol(pmu6236_spk_vol_enum val)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_SPK_CON0);
	reg_val16 &= (~SPK_VOL_MASK);
	reg_val16 |= (((kal_uint8)val << SPK_VOL_SHIFT) & SPK_VOL_MASK);
	PMU_DRV_WriteReg16(PMIC_SPK_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

pmu6236_spk_vol_enum dcl_pmu6236_get_spk_vol(void)
{
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_SPK_CON0);

	return (pmu6236_spk_vol_enum) ( (reg_val16 & SPK_VOL_MASK) >> SPK_VOL_SHIFT );

	//if (reg_val16 & SPK_VOL_MASK)
	//{
	//	return SPK_VOL_18DB;
	//}
	//else
	//{
	//	return SPK_VOL_12DB;
	//}
}

void dcl_pmu6236_spk_ocfb_enable(DCL_BOOL enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_SPK_CON0);
	reg_val16 &= (~SPK_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << SPK_OCFB_EN_SHIFT) & SPK_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_SPK_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0xE00) PMIC_OC_CON0
void dcl_pmu6236_vrf_oc_int_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VRF_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VRF_OC_INT_EN_SHIFT) & VRF_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vtcxo_oc_int_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VTCXO_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VTCXO_OC_INT_EN_SHIFT) & VTCXO_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_va_oc_int_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VA_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VA_OC_INT_EN_SHIFT) & VA_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcama_oc_int_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VCAMA_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMA_OC_INT_EN_SHIFT) & VCAMA_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vcamd_oc_int_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VCAMD_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMD_OC_INT_EN_SHIFT) & VCAMD_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vio_oc_int_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VIO_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VIO_OC_INT_EN_SHIFT) & VIO_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vusb_oc_int_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VUSB_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VUSB_OC_INT_EN_SHIFT) & VUSB_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vbt_oc_int_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VBT_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBT_OC_INT_EN_SHIFT) & VBT_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vsim_oc_int_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VSIM_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM_OC_INT_EN_SHIFT) & VSIM_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vsim2_oc_int_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VSIM2_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM2_OC_INT_EN_SHIFT) & VSIM2_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vbackup_oc_int_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VBACKUP_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBACKUP_OC_INT_EN_SHIFT) & VBACKUP_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vibr_oc_int_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VIBR_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VIBR_OC_INT_EN_SHIFT) & VIBR_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vmc_oc_int_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VMC_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VMC_OC_INT_EN_SHIFT) & VMC_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}


// (0xE04) PMIC_OC_CON1
void dcl_pmu6236_vcore_oc_int_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON1);
	reg_val16 &= (~VCORE_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCORE_OC_INT_EN_SHIFT) & VCORE_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6236_vm_oc_int_enable(DCL_BOOL enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON1);
	reg_val16 &= (~VM_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VM_OC_INT_EN_SHIFT) & VM_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// ======================================================================
// Other expoered APIs


DCL_BOOL pmu6236_cust_isink_en[5];
PMU_CTRL_BL_MODE_ENUM bl_mode_used;
DCL_UINT32 bl_support_level;
DCL_BOOL bl_use_pwm;
void dcl_pmu6236_init_bl(PMU_CTRL_BL_MODE_ENUM bl_mode)
{
	switch(bl_mode)
	{
		case BL_VBOOST_VOLTAGE_CONTROLLER_MODE:
			dcl_pmu6236_vboost_type(VBOOST_TYPE_VOLTAGE_CONTROLLER);
			dcl_pmu6236_vboost_vrsel(0xB);
            bl_support_level = BL_VBOOST_VOLTAGE_CONTROLLER_LEVEL;
            bl_use_pwm = DCL_TRUE;
		break;
		case BL_VBOOST_CURRENT_CONVERTER_MODE:
			dcl_pmu6236_vboost_type(VBOOST_TYPE_CURRENT_CONVERTER);
			dcl_pmu6236_vboost_vrsel(0x16);
            bl_support_level = BL_VBOOST_CURRENT_CONVERTER_LEVEL;
            bl_use_pwm = DCL_TRUE;
		break;
		case BL_ISINK_MODE:
			if (KAL_TRUE == pmu6236_cust_isink_en[0])
			{
				dcl_pmu6236_isink0_mode(PMU6236_ISINK_PWM_MODE);
			}
			if (KAL_TRUE == pmu6236_cust_isink_en[1])
			{
				dcl_pmu6236_isink1_mode(PMU6236_ISINK_PWM_MODE);
			}
			if (KAL_TRUE == pmu6236_cust_isink_en[2])
			{
				dcl_pmu6236_isink2_mode(PMU6236_ISINK_PWM_MODE);
			}
			if (KAL_TRUE == pmu6236_cust_isink_en[3])
			{
				dcl_pmu6236_isink3_mode(PMU6236_ISINK_PWM_MODE);
			}
			if (KAL_TRUE == pmu6236_cust_isink_en[4])
			{
				dcl_pmu6236_isink4_mode(PMU6236_ISINK_PWM_MODE);
			}
            bl_support_level = BL_ISINK_LEVEL;
            bl_use_pwm = DCL_TRUE;
		break;
		default:
			ASSERT(0);  // Not supported
		break;
	}
	bl_mode_used = bl_mode;
}

void dcl_pmu6236_enable_bl(DCL_BOOL enable)
{
	dcl_pmu6236_bl_control_WA(enable);
	switch (bl_mode_used)
	{
		case BL_VBOOST_VOLTAGE_CONTROLLER_MODE:
			dcl_pmu6236_vboost_enable(enable);
		break;
		case BL_VBOOST_CURRENT_CONVERTER_MODE:
			dcl_pmu6236_vboost_enable(enable);
		break;
		case BL_ISINK_MODE:
			if (KAL_TRUE == enable)
			{
				// Make sure boost is disabled, or BOOST will take control of isink
				dcl_pmu6236_vboost_enable(DCL_FALSE);
			}
			if (KAL_TRUE == pmu6236_cust_isink_en[0])
			{
				dcl_pmu6236_isink0_enable(enable);
			}
			if (KAL_TRUE == pmu6236_cust_isink_en[1])
			{
				dcl_pmu6236_isink1_enable(enable);
			}
			if (KAL_TRUE == pmu6236_cust_isink_en[2])
			{
				dcl_pmu6236_isink2_enable(enable);
			}
			if (KAL_TRUE == pmu6236_cust_isink_en[3])
			{
				dcl_pmu6236_isink3_enable(enable);
			}
			if (KAL_TRUE == pmu6236_cust_isink_en[4])
			{
				dcl_pmu6236_isink4_enable(enable);
			}
		break;
		default:
		break;
	}

}


// Exported for EM used
void dcl_pmu6236_EM_reg_write(kal_uint32 reg, kal_uint16 val)
{
	kal_uint32  savedMask;

	ASSERT(reg >= PMU_BASE && reg < PMU_END);

	savedMask = SaveAndSetIRQMask();
	PMU_DRV_WriteReg16(reg, val&0xFFFF);
	RestoreIRQMask(savedMask);
}

kal_uint16 dcl_pmu6236_EM_reg_read(kal_uint32 reg)
{
	kal_uint16  reg_val16;

	ASSERT(reg >= PMU_BASE && reg < PMU_END);

	reg_val16 = PMU_DRV_ReadReg16(reg);
	return reg_val16;
}


//CHR CURRENT
DCL_UINT32 cs_vth[]=
{
	PMU_CHARGE_CURRENT_100_00_MA,PMU_CHARGE_CURRENT_200_00_MA,
	PMU_CHARGE_CURRENT_400_00_MA,PMU_CHARGE_CURRENT_425_00_MA,
	PMU_CHARGE_CURRENT_550_00_MA,PMU_CHARGE_CURRENT_650_00_MA,
	PMU_CHARGE_CURRENT_700_00_MA,PMU_CHARGE_CURRENT_800_00_MA
};

DCL_UINT16 cs_vth_reg_val[]=
{
	0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00
};

DCL_UINT32 chr_cv_det[]=
{
      PMU_VOLT_04_000000_V, PMU_VOLT_04_012500_V, PMU_VOLT_04_025000_V, PMU_VOLT_04_037500_V,
      PMU_VOLT_04_050000_V, PMU_VOLT_04_062500_V, PMU_VOLT_04_075000_V, PMU_VOLT_04_087500_V,
      PMU_VOLT_04_100000_V, PMU_VOLT_04_112500_V, PMU_VOLT_04_125000_V, PMU_VOLT_04_137500_V,
      PMU_VOLT_04_150000_V, PMU_VOLT_04_162500_V, PMU_VOLT_04_175000_V, PMU_VOLT_04_187500_V,
      PMU_VOLT_04_200000_V, PMU_VOLT_04_212500_V, PMU_VOLT_04_225000_V, PMU_VOLT_04_237500_V,   
      PMU_VOLT_04_250000_V, PMU_VOLT_04_262500_V, PMU_VOLT_04_275000_V, PMU_VOLT_04_287500_V         
};

DCL_UINT32 chr_hv_vth[]=
{
	PMU_VOLT_04_200000_V, PMU_VOLT_04_250000_V,PMU_VOLT_04_300000_V,PMU_VOLT_04_350000_V,
	PMU_VOLT_04_400000_V, PMU_VOLT_04_450000_V,PMU_VOLT_04_500000_V,PMU_VOLT_04_550000_V,
	PMU_VOLT_04_600000_V, PMU_VOLT_06_000000_V,PMU_VOLT_06_500000_V,PMU_VOLT_07_000000_V,
	PMU_VOLT_07_500000_V, PMU_VOLT_08_500000_V,PMU_VOLT_09_500000_V,PMU_VOLT_10_500000_V	
};	

		
DCL_UINT32 vsim_vosel[]=
{
      PMU_VOLT_01_800000_V, PMU_VOLT_03_000000_V
};

DCL_UINT32 vsim2_vosel[]=
{
	PMU_VOLT_01_300000_V, PMU_VOLT_01_500000_V, PMU_VOLT_01_800000_V, PMU_VOLT_02_500000_V,
	PMU_VOLT_02_800000_V, PMU_VOLT_03_000000_V, PMU_VOLT_03_300000_V
};

DCL_UINT32 vcama_vosel[]=
{
      PMU_VOLT_01_500000_V, PMU_VOLT_01_800000_V, PMU_VOLT_02_500000_V, PMU_VOLT_02_800000_V
};

DCL_UINT32 vcamd_vosel[]=
{
      PMU_VOLT_01_300000_V, PMU_VOLT_01_500000_V, PMU_VOLT_01_800000_V, PMU_VOLT_02_800000_V
};

DCL_UINT32 vbt_vosel[]=
{
      PMU_VOLT_02_800000_V, PMU_VOLT_03_000000_V
};


DCL_UINT32 isink_step[]=
{
	ISINK_STEP_04_MA, ISINK_STEP_08_MA, ISINK_STEP_12_MA, 
	ISINK_STEP_16_MA,ISINK_STEP_20_MA,ISINK_STEP_24_MA
};

DCL_UINT32 spk_vol[]=
{
	PMU_SPK_VOL_12_00_dB, PMU_SPK_VOL_18_00_dB
};





PMU_PARAMETER_TABLE_ENTRY pmu_parameter_table[]=
{
	//BUCK group
	{ENC(LDO_BUCK_SET_VOLTAGE,VSIM),		vsim_vosel,		NULL,				GETARRNUM(vsim_vosel)		},	
	{ENC(LDO_BUCK_SET_VOLTAGE,VSIM2),		vsim2_vosel,	NULL,				GETARRNUM(vsim2_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,VIBR),		vsim2_vosel,	NULL,				GETARRNUM(vsim2_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,VMC),		vsim2_vosel,	NULL,				GETARRNUM(vsim2_vosel)	},	
	{ENC(LDO_BUCK_SET_VOLTAGE,VCAMA),		vcama_vosel,	NULL,				GETARRNUM(vcama_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,VCAMD),		vcamd_vosel,	NULL,				GETARRNUM(vcamd_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,VBT),		vbt_vosel,	NULL,				GETARRNUM(vbt_vosel)	},
	//SPK
	{ENC(SPK_SET_VOL,ALLMOD),				spk_vol,		NULL,				GETARRNUM(spk_vol)	},		
	//ISINK
	{ENC(ISINK_SET_STEP,ALLMOD),				isink_step,		NULL,				GETARRNUM(isink_step)	},	
	//CHR
	{ENC(CHR_SET_HV_DETECTION_VOLTAGE,ALLMOD),	chr_hv_vth,			NULL,				GETARRNUM(chr_hv_vth)		},
	{ENC(CHR_SET_CHR_CURRENT,ALLMOD),				cs_vth,		cs_vth_reg_val,				GETARRNUM(cs_vth)		},
	{ENC(CHR_SET_CV_DETECTION_VOLTAGE,ALLMOD),	chr_cv_det,			NULL,				GETARRNUM(chr_cv_det)	}
};


extern PMU_CONTROL_HANDLER pmu_control_handler;
DCL_UINT16 pmu_parameter_size=0;

DCL_STATUS dcl_pmu6236_Ldo_Set_En(PMU_LDO_BUCK_LIST_ENUM mod,DCL_BOOL enable)
{

	switch(mod)
	{
		case VRF:
		{
			dcl_pmu6236_vrf_enable(enable);
		}
		case VTCXO:
		{
			dcl_pmu6236_vtcxo_enable(enable);
		}
		case VCAMA:
		{
			dcl_pmu6236_vcama_enable(enable);
		}
		break;	
		case VCAMD:
		{
			dcl_pmu6236_vcamd_enable(enable);
		}
		break;	
		case VUSB:
		{
			dcl_pmu6236_vusb_enable(enable);
		}
		break;
		case VBT:
		{
			dcl_pmu6236_vbt_enable(enable);
		}
		case VSIM:
		{
			dcl_pmu6236_vsim_enable(enable);
		}
		break;
		case VSIM2:
		{
			dcl_pmu6236_vsim2_enable(enable);
		}
		break;
		case VBACKUP:
		{
			dcl_pmu6236_vbackup_enable(enable);
		}
		case VIBR:
		{
			dcl_pmu6236_vibr_enable(enable);
		}
		break;		
		case VMC:
		{
			dcl_pmu6236_vmc_enable(enable);
		}
		break;							
		default:				
		return STATUS_UNSUPPORTED;
		//break;			
	}

	return STATUS_OK;
}


DCL_STATUS dcl_pmu6236_Ldo_Set_Voltage(PMU_LDO_BUCK_LIST_ENUM mod,DCL_UINT16 regVal)
{
	switch(mod)
	{
		case VCAMA:
		{
			dcl_pmu6236_vcama_vosel((pmu6236_vcama_vosel_enum)regVal);
		}
		break;	
		case VCAMD:
		{
			dcl_pmu6236_vcamd_vosel((pmu6236_vcamd_vosel_enum)regVal);
		}
		break;	
		case VSIM:
		{
			dcl_pmu6236_vsim_vosel((pmu6236_vsim_vosel_enum)regVal);
		}
		break;	
		case VSIM2:
		{
			dcl_pmu6236_vsim2_vosel((pmu6236_vsim2_vosel_enum)regVal);
		}
		break;
		case VIBR:
		{
			dcl_pmu6236_vibr_vosel((pmu6236_vibr_vosel_enum)regVal);
		}
		break;	
		case VMC:
		{
			dcl_pmu6236_vmc_vosel((pmu6236_vmc_vosel_enum)regVal);
		}
		break;	
		case VBT:
		{
			dcl_pmu6236_vbt_vosel((pmu6236_vbt_sel_enum)regVal);
		}
		default:		
		return STATUS_UNSUPPORTED;
		//break;			
	}	

	return STATUS_OK;
}

DCL_STATUS dcl_pmu6236_Isink_Set_Step(PMU_ISINK_LIST_ENUM isink,DCL_UINT16 regVal)
{
	switch(isink)
	{
		case ISINK0:
		{
			dcl_pmu6236_isink0_step((pmu6236_isink_step_enum)regVal);
		}
		break;	
		case ISINK1:
		{
			dcl_pmu6236_isink1_step((pmu6236_isink_step_enum)regVal);
		}
		break;	
		case ISINK2:
		{
			dcl_pmu6236_isink2_step((pmu6236_isink_step_enum)regVal);
		}
		break;	
		case ISINK3:
		{
			dcl_pmu6236_isink3_step((pmu6236_isink_step_enum)regVal);
		}
		break;	
		case ISINK4:
		{
			dcl_pmu6236_isink4_step((pmu6236_isink_step_enum)regVal);
		}
		break;					
		default:				
		return STATUS_UNSUPPORTED;
		//break;			
	}

	return STATUS_OK;
}



DCL_STATUS dcl_pmu6236_control_handler(DCL_HANDLE handle,DCL_CTRL_CMD cmd,DCL_CTRL_DATA_T *data)
{
	DCL_UINT16	regVal;


	switch(cmd)
	{
		//LDO,BUCK
		case LDO_BUCK_SET_EN:
		{
			PMU_CTRL_LDO_BUCK_SET_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetEn);
			return dcl_pmu6236_Ldo_Set_En(pLdoBuckCtrl->mod,pLdoBuckCtrl->enable);
		}
		//break;	
		case LDO_BUCK_SET_VOLTAGE:
		{
			PMU_CTRL_LDO_BUCK_SET_VOLTAGE *pLdoBuckCtrl=&(data->rPMULdoBuckSetVoltage);			
			regVal=PMU_Parameter_to_Value(ENC(cmd,pLdoBuckCtrl->mod),pLdoBuckCtrl->voltage);
			return dcl_pmu6236_Ldo_Set_Voltage(pLdoBuckCtrl->mod,regVal);
		}	
//		break;
		case LDO_BUCK_SET_OCFB_EN:
		{
			
			PMU_CTRL_LDO_BUCK_SET_OCFB_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetOcfbEn);		
			switch(pLdoBuckCtrl->mod)
			{
				case VRF:
				{
					dcl_pmu6236_vrf_ocfb_enable(pLdoBuckCtrl->enable);
				}
				break;	
				case VTCXO:
				{
					dcl_pmu6236_vtcxo_ocfb_enable(pLdoBuckCtrl->enable);
				}
				break;
				case VA28:
				{
					dcl_pmu6236_va_ocfb_enable(pLdoBuckCtrl->enable);
				}
				break;		
				case VCAMA:
				{
					dcl_pmu6236_vcama_ocfb_enable(pLdoBuckCtrl->enable);
				}
				break;	
				case VCAMD:
				{
					dcl_pmu6236_vcamd_ocfb_enable(pLdoBuckCtrl->enable);
				}
				break;	
				case VIO28:
				{
					dcl_pmu6236_vio_ocfb_enable(pLdoBuckCtrl->enable);
				}
				break;	
				case VUSB:
				{
					dcl_pmu6236_vusb_ocfb_enable(pLdoBuckCtrl->enable);
				}
				break;	
				case VBT:
				{
					dcl_pmu6236_vbt_ocfb_enable(pLdoBuckCtrl->enable);
				}
				break;					
				case VSIM:
				{
					dcl_pmu6236_vsim_ocfb_enable(pLdoBuckCtrl->enable);
				}
				break;	
				case VSIM2:
				{
					dcl_pmu6236_vsim2_ocfb_enable(pLdoBuckCtrl->enable);
				}
				break;
				case VBACKUP:
				{
					dcl_pmu6236_vbackup_ocfb_enable(pLdoBuckCtrl->enable);
				}
				break;	
				case VIBR:
				{
					dcl_pmu6236_vibr_ocfb_enable(pLdoBuckCtrl->enable);
				}
				break;	
				case VMC:
				{
					dcl_pmu6236_vmc_ocfb_enable(pLdoBuckCtrl->enable);
				}
				break;	
				case VCORE:
				{
					dcl_pmu6236_vcore_ocfb_enable(pLdoBuckCtrl->enable);
				}
				break;
				case VM:
				{
					dcl_pmu6236_vm_ocfb_enable(pLdoBuckCtrl->enable);
				}
				break;					
				default:				
				return STATUS_UNSUPPORTED;
//				break;			
			}
		}	
		break;		
		case LDO_BUCK_SET_NDIS_EN:
		{	
			PMU_CTRL_LDO_BUCK_SET_NDIS_EN *pLdoCtrl=&(data->rPMULdoBuckSetNdisEn);
			switch(pLdoCtrl->mod)
			{
				case VRF:
				{
					dcl_pmu6236_vrf_ndis_enable(pLdoCtrl->enable);
				}
				break;	
				case VTCXO:
				{
					dcl_pmu6236_vtcxo_ndis_enable(pLdoCtrl->enable);
				}
				break;	
				case VA28:
				{
					dcl_pmu6236_va_ndis_enable(pLdoCtrl->enable);
				}
				break;	
				case VCAMA:
				{
					dcl_pmu6236_vcama_ndis_enable(pLdoCtrl->enable);
				}
				break;	
				case VCAMD:
				{
					dcl_pmu6236_vcamd_ndis_enable(pLdoCtrl->enable);
				}
				break;	
				case VIO28:
				{
					dcl_pmu6236_vio_ndis_enable(pLdoCtrl->enable);
				}
				break;	
				case VUSB:
				{
					dcl_pmu6236_vusb_ndis_enable(pLdoCtrl->enable);
				}
				break;	
				case VBT:
				{
					dcl_pmu6236_vbt_ndis_enable(pLdoCtrl->enable);
				}
				break;	
				case VSIM:
				{
					dcl_pmu6236_vsim_ndis_enable(pLdoCtrl->enable);
				}
				break;	
				case VSIM2:
				{
					dcl_pmu6236_vsim2_ndis_enable(pLdoCtrl->enable);
				}
				break;
				case VBACKUP:
				{
					dcl_pmu6236_vbackup_ndis_enable(pLdoCtrl->enable);
				}
				break;	
				case VIBR:
				{
					dcl_pmu6236_vibr_ndis_enable(pLdoCtrl->enable);
				}
				break;	
				case VMC:
				{
					dcl_pmu6236_vmc_ndis_enable(pLdoCtrl->enable);
				}
				break;						
				default:				
				return STATUS_UNSUPPORTED;
//				break;			
			}			
		}
		break;
		case LDO_BUCK_SET_STB_EN:
		{	
			PMU_CTRL_LDO_BUCK_SET_STB_EN *pLdoCtrl=&(data->rPMULdoBuckSetStbEn);
			switch(pLdoCtrl->mod)
			{
				case VRF:
				{
					dcl_pmu6236_vrf_stb_enable(pLdoCtrl->enable);
				}
				break;	
				case VTCXO:
				{
					dcl_pmu6236_vtcxo_stb_enable(pLdoCtrl->enable);
				}
				break;	
				case VA28:
				{
					dcl_pmu6236_va_stb_enable(pLdoCtrl->enable);
				}
				break;	
				case VCAMA:
				{
					dcl_pmu6236_vcama_stb_enable(pLdoCtrl->enable);
				}
				break;	
				case VCAMD:
				{
					dcl_pmu6236_vcamd_stb_enable(pLdoCtrl->enable);
				}
				break;	
				case VIO28:
				{
					dcl_pmu6236_vio_stb_enable(pLdoCtrl->enable);
				}
				break;	
				case VUSB:
				{
					dcl_pmu6236_vusb_stb_enable(pLdoCtrl->enable);
				}
				break;	
				case VBT:
				{
					dcl_pmu6236_vbt_stb_enable(pLdoCtrl->enable);
				}
				break;	
				case VSIM:
				{
					dcl_pmu6236_vsim_stb_enable(pLdoCtrl->enable);
				}
				break;	
				case VSIM2:
				{
					dcl_pmu6236_vsim2_stb_enable(pLdoCtrl->enable);
				}
				break;
				case VBACKUP:
				{
					dcl_pmu6236_vbackup_stb_enable(pLdoCtrl->enable);
				}
				break;	
				case VIBR:
				{
					dcl_pmu6236_vibr_stb_enable(pLdoCtrl->enable);
				}
				break;	
				case VMC:
				{
					dcl_pmu6236_vmc_stb_enable(pLdoCtrl->enable);
				}
				break;
				case VM:
				{
					dcl_pmu6236_vm_stb_enable(pLdoCtrl->enable);
				}
				break;	
				case VCORE:
				{
					dcl_pmu6236_vcore_stb_enable(pLdoCtrl->enable);
				}
				break;					
				default:				
				return STATUS_UNSUPPORTED;
//				break;			
			}			
		}			
		break;
		case LDO_BUCK_SET_OC_AUTO_OFF:
		{	
			PMU_CTRL_LDO_BUCK_SET_OC_AUTO_OFF *pLdoCtrl=&(data->rPMULdoBuckSetOcAutoOff);
			switch(pLdoCtrl->mod)
			{
				case VRF:
				{
					dcl_pmu6236_vrf_oc_auto_off(pLdoCtrl->enable);
				}
				break;	
				case VTCXO:
				{
					dcl_pmu6236_vtcxo_oc_auto_off(pLdoCtrl->enable);
				}
				break;	
				case VA28:
				{
					dcl_pmu6236_va_oc_auto_off(pLdoCtrl->enable);
				}
				break;	
				case VCAMA:
				{
					dcl_pmu6236_vcama_oc_auto_off(pLdoCtrl->enable);
				}
				break;	
				case VCAMD:
				{
					dcl_pmu6236_vcamd_oc_auto_off(pLdoCtrl->enable);
				}
				break;	
				case VIO28:
				{
					dcl_pmu6236_vio_oc_auto_off(pLdoCtrl->enable);
				}
				break;	
				case VUSB:
				{
					dcl_pmu6236_vusb_oc_auto_off(pLdoCtrl->enable);
				}
				break;	
				case VBT:
				{
					dcl_pmu6236_vbt_oc_auto_off(pLdoCtrl->enable);
				}
				break;	
				case VSIM:
				{
					dcl_pmu6236_vsim_oc_auto_off(pLdoCtrl->enable);
				}
				break;	
				case VSIM2:
				{
					dcl_pmu6236_vsim2_oc_auto_off(pLdoCtrl->enable);
				}
				break;
				case VBACKUP:
				{
					dcl_pmu6236_vbackup_oc_auto_off(pLdoCtrl->enable);
				}
				break;	
				case VIBR:
				{
					dcl_pmu6236_vibr_oc_auto_off(pLdoCtrl->enable);
				}
				break;	
				case VMC:
				{
					dcl_pmu6236_vmc_oc_auto_off(pLdoCtrl->enable);
				}
				break;	
				case VCORE:
				{
					dcl_pmu6236_vcore_oc_auto_off(pLdoCtrl->enable);
				}
				break;	
				case VM:
				{
					dcl_pmu6236_vm_oc_auto_off(pLdoCtrl->enable);
				}
				break;					
				default:				
				return STATUS_UNSUPPORTED;
//				break;			
			}			
		}	
		break;
		//BL
		case BL_SET_INIT:
		{	
			PMU_CTRL_BL_SET_INIT *pBlCtrl=&(data->rPMUBlSetInit);
			dcl_pmu6236_init_bl(pBlCtrl->blMode);
		}				
		break;			
		case BL_SET_EN:
		{
			PMU_CTRL_BL_SET_EN *pBlCtrl=&(data->rPMUBlSetEn);
			dcl_pmu6236_enable_bl(pBlCtrl->enable);
		}				
		break;	
        case BL_GET_SUPPORT_LEVEL:
        {
            PMU_CTRL_BL_GET_SUPPORT_LEVEL *pBlCtrl = &(data->rPMUBlGetSupportLevel);
            pBlCtrl->blSupportLevel = bl_support_level;
        }
        break;
        case BL_GET_USE_PWM_QUERY:
        {
            PMU_CTRL_BL_GET_USE_PWM_QUERY *pBlCtrl = &(data->rPMUBlGetUsePwmQuery);
            pBlCtrl->blUsePwmQuery = bl_use_pwm;            
        }
        break;
		case BOOST_SET_LEVEL:
		{
			PMU_CTRL_BOOST_SET_LEVEL *pBoostCtrl=&(data->rPMUBoostSetLevel);
			dcl_pmu6236_vboost_vrsel(pBoostCtrl->level);
		}
		break;
		//ISINK
		case ISINK_SET_EN:
		{
			PMU_CTRL_ISINK_SET_EN *pIsinkCtrl=&(data->rPMUIsinkSetEn);
			if (pIsinkCtrl->isink>=5)
				return STATUS_UNSUPPORTED;
			pmu6236_cust_isink_en[pIsinkCtrl->isink]=pIsinkCtrl->enable;
								
		}
		break;
		case ISINK_SET_STEP:
		{
			PMU_CTRL_ISINK_SET_STEP *pIsinkCtrl=&(data->rPMUIsinkSetStep);
			regVal=PMU_Parameter_to_Value(ENC(cmd,pIsinkCtrl->isink),pIsinkCtrl->step);
			return  dcl_pmu6236_Isink_Set_Step(pIsinkCtrl->isink,regVal);
		}		
//		break;
		//SPK
		case SPK_SET_EN:
		{
			PMU_CTRL_SPK_SET_EN *pSpkCtrl=&(data->rPMUSpkSetEn);
			dcl_pmu6236_spk_enable(pSpkCtrl->enable);
		}				
		break;
		//SPK
		case SPK_SET_VOL:
		{
		
			PMU_CTRL_SPK_SET_VOL *pSpkCtrl=&(data->rPMUSpkSetVol);
			regVal=PMU_Parameter_to_Value(ENC(cmd,SPK),pSpkCtrl->dbm);
			dcl_pmu6236_spk_vol((pmu6236_spk_vol_enum)regVal);
		}				
		break;	
		case SPK_SET_VOL_VALUE:
		{
			PMU_CTRL_SPK_SET_VOL_VALUE *pSpkCtrl=&(data->rPMUSpkSetVolValue);
			dcl_pmu6236_spk_vol((pmu6236_spk_vol_enum)pSpkCtrl->volValue);
		}				
		break;			
		//KPLED
		case KPLED_SET_EN:
		{
			PMU_CTRL_KPLED_SET_EN *pKpledCtrl=&(data->rPMUKpledSetEn);
			dcl_pmu6236_kpled_enable(pKpledCtrl->enable);
		}				
		break;		
		case KPLED_SET_MODE:
		{
			PMU_CTRL_KPLED_SET_MODE *pKpledCtrl=&(data->rPMUKpledSetMode);
			dcl_pmu6236_kpled_mode((pmu6236_kpled_mode_enum)pKpledCtrl->mode);
		}				
		break;	
		case KPLED_SET_SEL:
		{
			PMU_CTRL_KPLED_SET_SEL *pKpledCtrl=&(data->rPMUKpledSetSel);
			dcl_pmu6236_kpled_sel((pmu6236_kpled_mode_enum)pKpledCtrl->sel);
		}				
		break;	
		//FLASHLED
		case FLASHLED_SET_EN:
		{
			PMU_CTRL_FLASHLED_SET_EN *pFlashCtrl=&(data->rPMUFlashledSetEn);
			dcl_pmu6236_flash_enable(pFlashCtrl->enable);
		}				
		break;		
		case FLASHLED_SET_MODE:
		{
			PMU_CTRL_FLASHLED_SET_MODE *pFlashCtrl=&(data->rPMUFlashledSetMode);
			dcl_pmu6236_flash_mode((pmu6236_flash_mode_enum)pFlashCtrl->mode);
		}				
		break;	
		case FLASHLED_SET_SEL:
		{
			PMU_CTRL_FLASHLED_SET_SEL *pFlashCtrl=&(data->rPMUFlashledSetSel);
			dcl_pmu6236_flash_sel(pFlashCtrl->sel);
		}				
		break;			
		//CHR
		case CHR_SET_CHR_EN:
		{
			PMU_CTRL_CHR_SET_CHR_EN *pChrCtrl=&(data->rPMUChrSetChrEn);
			dcl_pmu6236_chr_enable(pChrCtrl->enable);
		}
		break;		
		case CHR_GET_CHR_DET_STATUS:
		{
			PMU_CTRL_CHR_GET_CHR_DET_STATUS *pChrCtrl=&(data->rPMUChrGetChrDetStatus);
			pChrCtrl->enable=dcl_pmu6236_chr_chrdet();
		}	
		break;
		case CHR_GET_IS_BATTERY_ON:
		{	//always return TRUE (why?)
			PMU_CTRL_CHR_GET_IS_BATTERY_ON *pChrCtrl=&(data->rPMUChrGetIsBatteryOn);		
			pChrCtrl->enable=DCL_TRUE;
		}
		break;			
		case CHR_SET_ADC_MEASURE_EN:
		{
			PMU_CTRL_CHR_SET_ADC_MEASURE_EN *pChrCtrl=&(data->rPMUChrSetAdcMeasureEn);		
			dcl_pmu6236_chr_adc_meas_on(pChrCtrl->enable);
		}
		break;
		case CHR_GET_CV_DETECTION_STATUS:
		{
			PMU_CTRL_CHR_GET_CV_DETECTION_STATUS *pChrCtrl=&(data->rPMUChrGetCvDetectionStatus);		
			pChrCtrl->enable=dcl_pmu6236_chr_cv_det();
		}
		break;
		case CHR_GET_CHR_CURRENT:
		{
			PMU_CTRL_CHR_GET_CHR_CURRENT *pChrCtrl=&(data->rPMUChrGetChrCurrent);
			pChrCtrl->current=(PMU_CHR_CURRENT_ENUM)PMU_Value_to_Parameter(ENC(CHR_SET_CHR_CURRENT,CHR),(DCL_UINT32)(pChrCtrl->current));
		}
		break;				
		case CHR_SET_CHR_CURRENT:
		{
			PMU_CTRL_CHR_SET_CHR_CURRENT *pChrCtrl=&(data->rPMUChrSetChrCurrent);	
			regVal=PMU_Parameter_to_Value(ENC(cmd,CHR),pChrCtrl->current);

			if (regVal==PARAMETER_UNKNOWN)
				ASSERT(0);

			dcl_pmu6236_chr_current((pmu6236_chr_current_enum)regVal);
		}
		break;
		case CHR_GET_CHR_CURRENT_LIST:
		{
			PMU_CTRL_CHR_GET_CHR_CURRENT_LIST *pChrCtrl=&(data->rPMUChrGetChrCurrentList);
			pChrCtrl->pCurrentList=cs_vth;
			pChrCtrl->number=GETARRNUM(cs_vth);
		}
		break;			
		case CHR_SET_CV_DETECTION_VOLTAGE:
		{
			PMU_CTRL_CHR_SET_CV_DETECTION_VOLTAGE *pChrCtrl=&(data->rPMUChrSetCvDetectionVoltage);	
			regVal=PMU_Parameter_to_Value(ENC(cmd,CHR),pChrCtrl->voltage);

			if (regVal==PARAMETER_UNKNOWN)
				ASSERT(0);
			
			dcl_pmu6236_chr_vbat_cv_vth((pmu6236_chr_vbat_cv_enum)regVal);
		}	
		break;
		case CHR_SET_HV_DETECTION_VOLTAGE:
		{
			PMU_CTRL_CHR_SET_HV_DETECTION_VOLTAGE	*pChrCtrl=&(data->rPMUChrSetHvDetectionVoltage);
			regVal = PMU_Parameter_to_Value(ENC(cmd,CHR),pChrCtrl->voltage);
			if (regVal==PARAMETER_UNKNOWN)
				ASSERT(0);
			dcl_pmu6236_chr_vcdt_hv_vth(regVal);
		}
		break;
		case CHR_GET_HV_DETECTION_VOLTAGE_LIST:
		{
			PMU_CTRL_CHR_GET_HV_DETECTION_VOLTAGE_LIST *pChrCtrl = &(data->rPMUChrGetHvDetectionVoltageList);
			pChrCtrl->pVoltageList = chr_hv_vth;
			pChrCtrl->number = GETARRNUM(chr_hv_vth);
		}
		break;
		case CHR_SET_WDT_CLEAR:
		{
			dcl_pmu6236_chr_wdt_clear();
		}
		break;
		case MISC_SET_REGISTER_VALUE:
		{
			PMU_CTRL_MISC_SET_REGISTER_VALUE	*pChrCtrl=&(data->rPMUMiscSetRegisterValue);
                        if ((PMU_BASE+pChrCtrl->offset)>PMU_END)
                              return STATUS_UNSUPPORTED;
			PWIC_DRV_WriteReg16((PMU_BASE+pChrCtrl->offset), pChrCtrl->value);
		}
		break;	
		case MISC_GET_REGISTER_VALUE:
		{
			PMU_CTRL_MISC_GET_REGISTER_VALUE	*pChrCtrl=&(data->rPMUMiscGetRegisterValue);
                        if ((PMU_BASE+pChrCtrl->offset)>PMU_END)
                              return STATUS_UNSUPPORTED;
			pChrCtrl->value= PWIC_DRV_ReadReg16((PMU_BASE+pChrCtrl->offset));
		}
		break;			
		default:				
		return STATUS_UNSUPPORTED;
		//break;
	}

		return STATUS_OK;
}	


void dcl_pmu6236_init(void)
{
	//kal_uint8 chr_status = 0;
	kal_uint32 count = 0;


	pmu_control_handler=dcl_pmu6236_control_handler;
	pmu_parameter_size=GETARRNUM(pmu_parameter_table);	

	// Wait only H/W mode charger mechnaism IDLE (Ex: Pre-charge for now)
	// then we can configure charger related registers
	// This operation should be done after every time H/W mode charging is enabled
	while(dcl_pmu6236_get_pchr_state() != PCHR_STATE_IDLE)
	{
		count++;
		if (count >= 100000)
		{
			break;
		}
	}


	// RP2 request: For E2, need to fine tune
#if defined(__AST2001__)
    dcl_pmu6236_vcore_vfbadj_slp(VCORE_VFBADJ_1_1V);
#else
    dcl_pmu6236_vcore_vfbadj_slp(VCORE_VFBADJ_1_0V);
#endif

// MSDC and efuse share VMC LDO  , if MSDC turn off VMC ,it cause efuse data error
// so we always turn on VMC LDO
	//pmu6236_vmc_enable(KAL_FALSE);
        dcl_pmu6236_vmc_vosel(pmu6236_VMC_3_3V);
	dcl_pmu6236_vsim2_ndis_enable(KAL_TRUE);

	// vcore buck mode initial
	dcl_pmu6236_vcore_csl(VCORE_CSL_60K);
	dcl_pmu6236_vcore_burst(VCORE_650_500);
	dcl_pmu6236_vcore_ical_en(0x3);

	// vm buck mode initial
	dcl_pmu6236_vm_csl(VM_CSL_60K);
	dcl_pmu6236_vm_burst(VM_650_500);
	dcl_pmu6236_vm_ical_en(0x3);

	dcl_pmu6236_vboost_cks_prg(0x1A);

	dcl_pmu6236_vboost_mode(VBOOST_PWM_MODE);

#if !defined(__UBL__) 	
	// LDO ocfb setting
	dcl_pmu6236_vsim_ocfb_enable(DCL_TRUE);
	dcl_pmu6236_vsim2_ocfb_enable(DCL_TRUE);
	dcl_pmu6236_vbackup_ocfb_enable(DCL_TRUE);
	dcl_pmu6236_vibr_ocfb_enable(DCL_TRUE);
	dcl_pmu6236_vmc_ocfb_enable(DCL_TRUE);

	// LDO oc auto off setting
	dcl_pmu6236_vrf_oc_auto_off(DCL_FALSE);
	dcl_pmu6236_vtcxo_oc_auto_off(DCL_FALSE);
	dcl_pmu6236_va_oc_auto_off(DCL_FALSE);
	dcl_pmu6236_vcama_oc_auto_off(DCL_FALSE);
	dcl_pmu6236_vcamd_oc_auto_off(DCL_FALSE);
	dcl_pmu6236_vio_oc_auto_off(DCL_FALSE);
	dcl_pmu6236_vusb_oc_auto_off(DCL_FALSE);
	dcl_pmu6236_vbt_oc_auto_off(DCL_FALSE);
	dcl_pmu6236_vsim_oc_auto_off(DCL_FALSE);
	dcl_pmu6236_vsim2_oc_auto_off(DCL_FALSE);
	dcl_pmu6236_vbackup_oc_auto_off(DCL_FALSE);
	dcl_pmu6236_vibr_oc_auto_off(DCL_FALSE);
	dcl_pmu6236_vmc_oc_auto_off(DCL_FALSE);

	// LDO NMOS discharge enable/disable setting
	dcl_pmu6236_vrf_ndis_enable(DCL_TRUE);
	dcl_pmu6236_vtcxo_ndis_enable(DCL_TRUE);
	dcl_pmu6236_va_ndis_enable(DCL_FALSE);
	dcl_pmu6236_vcama_ndis_enable(DCL_TRUE);
	dcl_pmu6236_vcamd_ndis_enable(DCL_TRUE);
	dcl_pmu6236_vio_ndis_enable(DCL_FALSE);
	dcl_pmu6236_vusb_ndis_enable(DCL_TRUE);
	dcl_pmu6236_vbt_ndis_enable(DCL_TRUE);
	dcl_pmu6236_vsim_ndis_enable(DCL_FALSE);
	dcl_pmu6236_vsim2_ndis_enable(DCL_TRUE);
	dcl_pmu6236_vbackup_ndis_enable(DCL_FALSE);
	dcl_pmu6236_vibr_ndis_enable(DCL_TRUE);
	dcl_pmu6236_vmc_ndis_enable(DCL_TRUE);

	// LDO soft start enable/disable setting
	dcl_pmu6236_vrf_stb_enable(DCL_TRUE);
	dcl_pmu6236_vtcxo_stb_enable(DCL_TRUE);
	dcl_pmu6236_va_stb_enable(DCL_TRUE);
	dcl_pmu6236_vcama_stb_enable(DCL_FALSE);
	dcl_pmu6236_vcamd_stb_enable(DCL_FALSE);
	dcl_pmu6236_vio_stb_enable(DCL_TRUE);
	dcl_pmu6236_vusb_stb_enable(DCL_TRUE);
	dcl_pmu6236_vbt_stb_enable(DCL_FALSE);
	dcl_pmu6236_vsim_stb_enable(DCL_FALSE);
	dcl_pmu6236_vsim2_stb_enable(DCL_FALSE);
	dcl_pmu6236_vbackup_stb_enable(DCL_TRUE);
	dcl_pmu6236_vibr_stb_enable(DCL_FALSE);
	dcl_pmu6236_vmc_stb_enable(DCL_TRUE);


	// LDOs voltage setting
	dcl_pmu6236_vcama_vosel(VCAMA_SEL_1_5V);
	dcl_pmu6236_vcamd_vosel(VCAMD_SEL_1_3V);
	dcl_pmu6236_vsim_vosel(pmu6236_VSIM_1_8V);
	dcl_pmu6236_vsim2_vosel(pmu6236_VSIM2_1_3V);
	dcl_pmu6236_vibr_vosel(VIBR_SEL_3_3V);
	dcl_pmu6236_vmc_vosel(pmu6236_VMC_3_3V);
	// LDOs enable/disable
	dcl_pmu6236_vcama_enable(DCL_FALSE);
	dcl_pmu6236_vcamd_enable(DCL_FALSE);
	dcl_pmu6236_vusb_enable(DCL_TRUE);
	dcl_pmu6236_vsim_enable(DCL_TRUE);
	dcl_pmu6236_vsim2_enable(DCL_FALSE);
	dcl_pmu6236_vibr_enable(DCL_FALSE);
	dcl_pmu6236_vmc_enable(DCL_FALSE);
#endif //#if !defined(__UBL__) 	

	pmu6236_customization_init();

#if defined(PMIC_6236_CV_TRIM_CALIBRATION)
	{
		// *(0x801CF018)[21] = CV_trim_en (1bit)
		// *(0x801CF018)[20:16] = VBAT_CV_VTH (5bits)
		kal_uint32 efuse_val;

		efuse_val = PMU_DRV_ReadReg32(EFUSE_base + 0xF018);
		if ( (efuse_val & 0x00200000) != 0) // Bit21
		{
			mt6236_efuse_vbat_cv = (pmu6236_chr_vbat_cv_enum) ((efuse_val & 0x001F0000) >> 16) ;
		}
		else
		{
			mt6236_efuse_vbat_cv = CHR_VBAT_CV_4_2000V;
		}
	}
#endif // #if defined(PMIC_6236_CV_TRIM_CALIBRATION)

	// Disable Power Good Detection
	// RG_TESTMODE_RSV 
	// Bit 3 power good disable (1: disable all power good function)
	PMU_DRV_SetData16(MIXED_base + 0x0F08,0x0800,0x0000);

}



#endif //#if (defined(PMIC_6236_REG_API))

