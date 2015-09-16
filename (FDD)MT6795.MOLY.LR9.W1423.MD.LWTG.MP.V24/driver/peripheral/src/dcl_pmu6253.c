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
 *    dcl_pmu6253.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module is for PMU6253
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * removed!
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


#if defined(PMIC_6253_REG_API)

#ifndef __DRV_DEBUG_PMU_REG_READ_WRITE__
#define PMU_DRV_ClearBits16(addr, data)       DRV_ClearBits(addr,data)
#define PMU_DRV_SetBits16(addr, data)         DRV_SetBits(addr,data)
#define PMU_DRV_WriteReg16(addr, data)        DRV_WriteReg(addr, data)
#define PMU_DRV_ReadReg16(addr)               DRV_Reg(addr)
#define PMU_DRV_ReadReg32(addr)               DRV_Reg32(addr)
#else // #ifndef __DRV_DEBUG_PMU_REG_READ_WRITE__
#define PMU_DRV_ClearBits16(addr,data)        DRV_DBG_ClearBits(addr,data)
#define PMU_DRV_SetBits16(addr, data)         DRV_DBG_SetBits(addr, data))
#define PMU_DRV_WriteReg16(addr, data)        DRV_DBG_WriteReg(addr, data)
#define PMU_DRV_ReadReg16(addr)               DRV_DBG_Reg(addr)
#endif // #ifndef __DRV_DEBUG_PMU_REG_READ_WRITE__

#if defined(__DRV_PMU53_SPEC_V2__)
extern void PWM3_Output_High(void);
#endif // #if defined(__DRV_PMU53_SPEC_V2__)

extern void pmu6253_customization_init(void);
extern void dcl_pmu6253_spk_dtcal_noDisIRQ(kal_bool enable);
extern void dcl_pmu6253_spk_dmode_noDisIRQ(pmu6253_spk_dmode_enum sel);


#if defined(PMU6253_ENABLE_DRIVER_CHARGE_WDT)
#define KICK_PMU6253_WDT_PERIOD				200	// in (10ms) unit, 200 means 2 sec
kal_uint8 pmu6253_wdt_handle;
void dcl_pmu6253_kick_charger_wdt(void *parameter);
#endif // #if defined(PMU6253_ENABLE_DRIVER_CHARGE_WDT)


#if defined(PMU6253_ENABLE_DRIVER_CHARGE_WDT)
void dcl_pmu6253_kick_charger_wdt(void *parameter){
	pmu6253_chr_wdt_clear();
}
void dcl_pmu6253_kick_wdt(kal_bool enable){
	// current_state is used prevent that first entry is enable = KAL_FALSE, which will cause GPT release a un-init handle
	static kal_bool current_state = KAL_FALSE;
	if (!kal_query_systemInit()){
		if (current_state != enable){
			if (enable){
				GPTI_GetHandle(&pmu6253_wdt_handle);
				GPTI_StartItem(pmu6253_wdt_handle,
							KICK_PMU6253_WDT_PERIOD,
							pmu6253_kick_charger_wdt,
							NULL);
			}else{
				GPTI_StopItem(pmu6253_wdt_handle);
				GPTI_ReleaseHandle(&pmu6253_wdt_handle);
			}
			current_state = enable;
		}
	}
}
#endif // #if defined(PMU6253_ENABLE_DRIVER_CHARGE_WDT)


extern void dcl_pmu6253_cv_rt_extra_internal(kal_uint8 val);



// =====================================================================================
// (0x800) VRF CON
void dcl_pmu6253_vrf_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VRF_CON);
	reg_val16 &= (~VRF_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VRF_EN_SHIFT) & VRF_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VRF_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vrf_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VRF_CON);
	reg_val16 &= (~VRF_CAL_MASK);
	reg_val16 |= ((val << VRF_CAL_SHIFT) & VRF_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VRF_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vrf_on_sel(pmu6253_vrf_on_sel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VRF_CON);
	reg_val16 &= (~VRF_ON_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VRF_ON_SEL_SHIFT) & VRF_ON_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VRF_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vrf_ocfb_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VRF_CON);
	reg_val16 &= (~VRF_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VRF_OCFB_EN_SHIFT) & VRF_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VRF_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_bool dcl_pmu6253_vrf_status(void){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VRF_CON);
	if (reg_val16 & VRF_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;

}

// (0x804) VIO CON
void dcl_pmu6253_vio_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VIO_CON);
	reg_val16 &= (~VIO_CAL_MASK);
	reg_val16 |= ((val << VIO_CAL_SHIFT) & VIO_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VIO_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vio_vd_sense(pmu6253_vd_sense_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VIO_CON);
	reg_val16 &= (~VIO_VD_SENSE_MASK);
	reg_val16 |= (((kal_uint8)sel << VIO_VD_SENSE_SHIFT) & VIO_VD_SENSE_MASK);
	PMU_DRV_WriteReg16(PMIC_VIO_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vio_ocfb_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VIO_CON);
	reg_val16 &= (~VIO_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VIO_OCFB_EN_SHIFT) & VIO_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VIO_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_bool dcl_pmu6253_vio_status(void){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VIO_CON);
	if (reg_val16 & VRF_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x808) VM CON
void dcl_pmu6253_vm_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VM_CON);
	reg_val16 &= (~VM_CAL_MASK);
	reg_val16 |= ((val << VM_CAL_SHIFT) & VM_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VM_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vm_vd_sense(pmu6253_vd_sense_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VM_CON);
	reg_val16 &= (~VM_VD_SENSE_MASK);
	reg_val16 |= (((kal_uint8)sel << VM_VD_SENSE_SHIFT) & VM_VD_SENSE_MASK);
	PMU_DRV_WriteReg16(PMIC_VM_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vm_ocfb_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VM_CON);
	reg_val16 &= (~VM_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VM_OCFB_EN_SHIFT) & VM_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VM_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_bool dcl_pmu6253_vm_status(void){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VM_CON);
	if (reg_val16 & VM_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x80C) VRTC CON
void dcl_pmu6253_vrtc_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VRTC_CON);
	reg_val16 &= (~VRTC_CAL_MASK);
	reg_val16 |= ((val << VRTC_CAL_SHIFT) & VRTC_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VRTC_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_bool dcl_pmu6253_vrtc_status(void){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VRTC_CON);
	if (reg_val16 & VRTC_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}


// (0x810) VTCXO CON
void dcl_pmu6253_vtcxo_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VTCXO_CON);
	reg_val16 &= (~VTCXO_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VTCXO_EN_SHIFT) & VTCXO_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VTCXO_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vtcxo_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val <16 );

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VTCXO_CON);
	reg_val16 &= (~VTCXO_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VTCXO_CAL_SHIFT) & VTCXO_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VTCXO_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vtcxo_on_sel(pmu6253_vtcxo_on_sel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VTCXO_CON);
	reg_val16 &= (~VTCXO_ON_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VTCXO_ON_SEL_SHIFT) & VTCXO_ON_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VTCXO_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vtcxo_srclken(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VTCXO_CON);
	reg_val16 &= (~VTCXO_CCI_SRCLKEN_MASK);
	reg_val16 |= (((kal_uint8)enable << VTCXO_CCI_SRCLKEN_SHIFT) & VTCXO_CCI_SRCLKEN_MASK);
	PMU_DRV_WriteReg16(PMIC_VTCXO_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vtcxo_ocfb_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VTCXO_CON);
	reg_val16 &= (~VTCXO_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VTCXO_OCFB_EN_SHIFT) & VTCXO_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VTCXO_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_bool dcl_pmu6253_vtcxo_status(void){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VTCXO_CON);
	if (reg_val16 & VTCXO_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x814) VA CON
void dcl_pmu6253_va_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VA_CON);
	reg_val16 &= (~VA_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VA_CAL_SHIFT) & VA_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VA_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_va_vd_sense(pmu6253_vd_sense_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VA_CON);
	reg_val16 &= (~VA_VD_SENSE_MASK);
	reg_val16 |= (((kal_uint8)sel << VA_VD_SENSE_SHIFT) & VA_VD_SENSE_MASK);
	PMU_DRV_WriteReg16(PMIC_VA_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_va_on_sel(pmu6253_va_on_sel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VA_CON);
	reg_val16 &= (~VA_ON_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VA_ON_SEL_SHIFT) & VA_ON_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VA_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_va_ocfb_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VA_CON);
	reg_val16 &= (~VA_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VA_OCFB_EN_SHIFT) & VA_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VA_CON, reg_val16);

	RestoreIRQMask(savedMask);

}

kal_bool dcl_pmu6253_va_status(void){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VA_CON);
	if (reg_val16 & VA_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x818) VSIM CON
void dcl_pmu6253_vsim_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM_CON);
	reg_val16 &= (~VSIM_CCI_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM_CCI_EN_SHIFT) & VSIM_CCI_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vsim_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM_CON);
	reg_val16 &= (~VSIM_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VSIM_CAL_SHIFT) & VSIM_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vsim_datal(kal_bool pull_low){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM_CON);
	reg_val16 &= (~VSIM_DATAL_MASK);
	reg_val16 |= (((kal_uint8)pull_low << VSIM_DATAL_SHIFT) & VSIM_DATAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vsim_sel(pmu6253_vsim_sel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM_CON);
	reg_val16 &= (~VSIM_CCI_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VSIM_CCI_SEL_SHIFT) & VSIM_CCI_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vsim_pwr_saving(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM_CON);
	reg_val16 &= (~VSIM_CCI_PWR_SAVING_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM_CCI_PWR_SAVING_SHIFT) & VSIM_CCI_PWR_SAVING_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vsim_ocfb_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM_CON);
	reg_val16 &= (~VSIM_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM_OCFB_EN_SHIFT) & VSIM_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_bool dcl_pmu6253_vsim_status(void){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM_CON);
	if (reg_val16 & VSIM_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x81C) VSIM2 CON
void dcl_pmu6253_vsim2_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM2_CON);
	reg_val16 &= (~VSIM2_CCI_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM2_CCI_EN_SHIFT) & VSIM2_CCI_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM2_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vsim2_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM2_CON);
	reg_val16 &= (~VSIM2_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VSIM2_CAL_SHIFT) & VSIM2_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM2_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vsim2_datal(kal_bool pull_low){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM2_CON);
	reg_val16 &= (~VSIM2_DATAL_MASK);
	reg_val16 |= (((kal_uint8)pull_low << VSIM2_DATAL_SHIFT) & VSIM2_DATAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM2_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vsim2_sel(pmu6253_vsim_sel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM2_CON);
	reg_val16 &= (~VSIM2_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VSIM2_SEL_SHIFT) & VSIM2_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VSIM2_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_bool dcl_pmu6253_vsim2_status(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VSIM2_CON);
	if (reg_val16 & VSIM2_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x820) VUSB CON
void dcl_pmu6253_vusb_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VUSB_CON);
	reg_val16 &= (~VUSB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VUSB_EN_SHIFT) & VUSB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VUSB_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vusb_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VUSB_CON);
	reg_val16 &= (~VUSB_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VUSB_CAL_SHIFT) & VUSB_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VUSB_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vusb_ocfb_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VUSB_CON);
	reg_val16 &= (~VUSB_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VUSB_OCFB_EN_SHIFT) & VUSB_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VUSB_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_bool dcl_pmu6253_vusb_status(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VUSB_CON);
	if (reg_val16 & VUSB_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x824) VBT CON ==> PMU53 SPEC V10
// (0x890) VBT CON  ==> PMU53 SPEC V20
void dcl_pmu6253_vbt_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBT_CON);
	reg_val16 &= (~VBT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBT_EN_SHIFT) & VBT_EN_MASK);
	#if defined(__DRV_PMU53_SPEC_V2__)
	// ESD enhancement
	reg_val16 &= (~0x0002);
	reg_val16 |= (((kal_uint8)enable << 1) & 0x0002);
	#endif // #if defined(__DRV_PMU53_SPEC_V2__)
	PMU_DRV_WriteReg16(PMIC_VBT_CON, reg_val16);

	RestoreIRQMask(savedMask);
#if defined(__DRV_PMU53_SPEC_V2__)
	PWM3_Output_High();
#endif // #if defined(__DRV_PMU53_SPEC_V2__)
}

void dcl_pmu6253_vbt_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBT_CON);
	reg_val16 &= (~VBT_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VBT_CAL_SHIFT) & VBT_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VBT_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vbt_sel(pmu6253_vbt_sel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBT_CON);
	reg_val16 &= (~VBT_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VBT_SEL_SHIFT) & VBT_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VBT_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vbt_ocfb_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBT_CON);
	reg_val16 &= (~VBT_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBT_OCFB_EN_SHIFT) & VBT_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VBT_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_bool dcl_pmu6253_vbt_status(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VBT_CON);
	if (reg_val16 & VBT_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x828) VCAMD CON
void dcl_pmu6253_vcamd_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMD_CON);
	reg_val16 &= (~VCAMD_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMD_EN_SHIFT) & VCAMD_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMD_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcamd_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMD_CON);
	reg_val16 &= (~VCAMD_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VCAMD_CAL_SHIFT) & VCAMD_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMD_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcamd_sel(pmu6253_vcamd_sel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMD_CON);
	reg_val16 &= (~VCAMD_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VCAMD_SEL_SHIFT) & VCAMD_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMD_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcamd_ocfb_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMD_CON);
	reg_val16 &= (~VCAMD_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMD_OCFB_EN_SHIFT) & VCAMD_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMD_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_bool dcl_pmu6253_vcamd_status(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMD_CON);
	if (reg_val16 & VCAMD_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x82C) VCAMA CON
void dcl_pmu6253_vcama_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMA_CON);
	reg_val16 &= (~VCAMA_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMA_EN_SHIFT) & VCAMA_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMA_CON, reg_val16);

	RestoreIRQMask(savedMask);
}
void dcl_pmu6253_vcama_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val < 16);

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMA_CON);
	reg_val16 &= (~VCAMA_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VCAMA_CAL_SHIFT) & VCAMA_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMA_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcama_sel(pmu6253_vcama_sel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMA_CON);
	reg_val16 &= (~VCAMA_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VCAMA_SEL_SHIFT) & VCAMA_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMA_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcama_ocfb_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMA_CON);
	reg_val16 &= (~VCAMA_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMA_OCFB_EN_SHIFT) & VCAMA_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCAMA_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_bool dcl_pmu6253_vcama_status(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCAMA_CON);
	if (reg_val16 & VCAMA_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x834) GPIO CON
void dcl_pmu6253_gpio_drv(pmu6253_gpio_drv_sel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_GPIO_CON);
	reg_val16 &= (~GPIO_DRV_MASK);
	reg_val16 |= (((kal_uint8)sel << GPIO_DRV_SHIFT) & GPIO_DRV_MASK);
	PMU_DRV_WriteReg16(PMIC_GPIO_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_mtv_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_GPIO_CON);
	reg_val16 &= (~CCI_MTV_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << CCI_MTV_EN_SHIFT) & CCI_MTV_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_GPIO_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x840) VCORE CON
void dcl_pmu6253_vcore_en_force(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON);
	reg_val16 &= (~VCORE_EN_FORCE_MASK);
	reg_val16 |= (((kal_uint8)enable << VCORE_EN_FORCE_SHIFT) & VCORE_EN_FORCE_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcore_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(val <16);

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON);
	reg_val16 &= (~VCORE_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VCORE_CAL_SHIFT) & VCORE_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcore_vd_sense(pmu6253_vd_sense_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON);
	reg_val16 &= (~VCORE_VD_SENSE_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_VD_SENSE_SHIFT) & VCORE_VD_SENSE_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_bool dcl_pmu6253_vcore_status(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON);
	if (reg_val16 & VCORE_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x844) VCORE CON1
void dcl_pmu6253_vcore_modeset(pmu6253_vcore_modeset_enum mode){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON1);
	reg_val16 &= (~VCORE_MODE_SET_MASK);
	reg_val16 |= (((kal_uint8)mode << VCORE_MODE_SET_SHIFT) & VCORE_MODE_SET_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcore_adc_in_edge(pmu6253_vcore_adc_in_enum edge){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON1);
	reg_val16 &= (~VCORE_ADC_IN_EDGE_MASK);
	reg_val16 |= (((kal_uint8)edge << VCORE_ADC_IN_EDGE_SHIFT) & VCORE_ADC_IN_EDGE_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcore_fast_slow(pmu6253_vcore_fast_slow_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON1);
	reg_val16 &= (~VCORE_FAST_SLOW_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_FAST_SLOW_SHIFT) & VCORE_FAST_SLOW_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcore_pwmb(pmu_6253_vcore_pwmb_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON1);
	reg_val16 &= (~VCORE_PWMB_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_PWMB_SHIFT) & VCORE_PWMB_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

extern void dcl_pmu6253_vcore_acc_out_init(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON1);
	reg_val16 &= (~VCORE_ACC_OUT_INIT_MASK);
	reg_val16 |= (((kal_uint8)val << VCORE_ACC_OUT_INIT_SHIFT) & VCORE_ACC_OUT_INIT_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x848) VCORE CON2
void dcl_pmu6253_vcore_volsel(pmu6253_vcore_volsel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON2);
	reg_val16 &= (~VCORE_VOLSEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_VOLSEL_SHIFT) & VCORE_VOLSEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}
void dcl_pmu6253_vcore_fben(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON2);
	reg_val16 &= (~VCORE_FBEN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCORE_FBEN_SHIFT) & VCORE_FBEN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x84C) VCORE CON3
void dcl_pmu6253_vcore_vfbadj(pmu6253_vcore_vfbadj_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON3);
	reg_val16 &= (~VCORE_CCI_VFBADJ_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_CCI_VFBADJ_SHIFT) & VCORE_CCI_VFBADJ_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcore_direct_ctrl_en(pmu6253_vcore_direct_ctrl_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON3);
	reg_val16 &= (~VCORE_DIRECT_CTRL_EN_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_DIRECT_CTRL_EN_SHIFT) & VCORE_DIRECT_CTRL_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcore_dcvclksel(pmu6253_vcore_dcvclksel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON3);
	reg_val16 &= (~VCORE_DCVCKSEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_DCVCKSEL_SHIFT) & VCORE_DCVCKSEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcore_modeen(pmu6253_vcore_modeen_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON3);
	reg_val16 &= (~VCORE_MODEEN_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_MODEEN_SHIFT) & VCORE_MODEEN_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcore_modecmp(pmu6253_vcore_modecmp_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON3);
	reg_val16 &= (~VCORE_MODECMP_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_MODECMP_SHIFT) & VCORE_MODECMP_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcore_modesel1A(pmu6253_vcore_modesel1a_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON3);
	reg_val16 &= (~VCORE_MODESEL1A_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_MODESEL1A_SHIFT) & VCORE_MODESEL1A_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x854) VCORE CON5
void dcl_pmu6253_vcore_vfbadj_slp(pmu6253_vcore_vfbadj_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON5);
	reg_val16 &= (~VCORE_CCI_VFBADJ_SLP_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_CCI_VFBADJ_SLP_SHIFT) & VCORE_CCI_VFBADJ_SLP_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON5, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcore_clk_source_sel(pmu6253_vcore_clk_source_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_VCORE_CON5);
	reg_val16 &= (~VCORE_CLK_SRC_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VCORE_CLK_SRC_SEL_SHIFT) & VCORE_CLK_SRC_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_VCORE_CON5, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x860) STARTUP CON0
void dcl_pmu6253_uv_sel(pmu6253_uv_sel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_STARTUP_CON0);
	reg_val16 &= (~UV_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << UV_SEL_SHIFT) & UV_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_STARTUP_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_pwrkey_vcore(pmu6253_pwrkey_signal_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_STARTUP_CON0);
	reg_val16 &= (~PWRKEY_VCORE_MASK);
	reg_val16 |= (((kal_uint8)sel << PWRKEY_VCORE_SHIFT) & PWRKEY_VCORE_MASK);
	PMU_DRV_WriteReg16(PMIC_STARTUP_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_pwrkey_deb(pmu6253_pwrkey_signal_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_STARTUP_CON0);
	reg_val16 &= (~PWRKEY_DEB_MASK);
	reg_val16 |= (((kal_uint8)sel << PWRKEY_DEB_SHIFT) & PWRKEY_DEB_MASK);
	PMU_DRV_WriteReg16(PMIC_STARTUP_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x864) STARTUP CON1
void dcl_pmu6253_thr_sel(pmu6253_thr_sel_num sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_STARTUP_CON1);
	reg_val16 &= (~THR_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << THR_SEL_SHIFT) & THR_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_STARTUP_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x870) CHR CON0
void dcl_pmu6253_chr_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	dcl_pmu6253_chr_force_enable(enable);
		
	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON0);
	reg_val16 &= (~CHR_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << CHR_EN_SHIFT) & CHR_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON0, reg_val16);

	RestoreIRQMask(savedMask);

#if defined(PMU6253_ENABLE_DRIVER_CHARGE_WDT)
	pmu6253_kick_wdt(enable);
#endif // #if defined(PMU6253_ENABLE_DRIVER_CHARGE_WDT)

}

void dcl_pmu6253_chofst(pmu6253_chofst_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON0);
	reg_val16 &= (~CHOFST_MASK);
	reg_val16 |= (((kal_uint8)sel << CHOFST_SHIFT) & CHOFST_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

pmu6253_chofst_enum dcl_pmu6253_get_chofst(void){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON0);
	RestoreIRQMask(savedMask);
	reg_val16 &= CHOFST_MASK;
	return (pmu6253_chofst_enum)(reg_val16>>CHOFST_SHIFT);
	
}

pmu6253_chr_current_enum dcl_pmu6253_chr_get_current();
void dcl_pmu6253_chr_current(pmu6253_chr_current_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;
	kal_bool chr_enable_flag = KAL_FALSE;
	pmu6253_chr_current_enum current_level;

	// Turn off charging first before set from high current level to lower current level
	current_level = dcl_pmu6253_chr_get_current();
	//kal_prompt_trace(MOD_BMT,"PMIC6253: Charge current level #1: %d", current_level);
	if (current_level > sel)
	{
		reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON0);
		if (reg_val16 & CHR_EN_MASK)
		{
			chr_enable_flag = KAL_TRUE;
		}
		// turn off charger, prevent below case 1 happen.
		// level 6  change to level 4:  	6 -> 7 -> 0 -> 1 -> 2 -> 3 -> 4
		dcl_pmu6253_chr_enable(KAL_FALSE);
		// level 6  change to level 4:  	6 -> off -> 0 -> 1 -> 2 -> 3 -> 4
	}
	//Turn off charging first before set from high current level to lower current level	

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON0);
	reg_val16 &= (~CHR_CC_CURRENT_MASK);
	reg_val16 |= (((kal_uint8)sel << CHR_CC_CURRENT_SHIFT) & CHR_CC_CURRENT_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON0, reg_val16);

	RestoreIRQMask(savedMask);
	
	if (chr_enable_flag)
	{
		dcl_pmu6253_chr_enable(KAL_TRUE);
	}

}

pmu6253_chr_current_enum dcl_pmu6253_chr_get_current(void){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON0);
	RestoreIRQMask(savedMask);
	reg_val16 &= CHR_CC_CURRENT_MASK;
	return reg_val16>>CHR_CC_CURRENT_SHIFT;
}

void dcl_pmu6253_chr_force_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON0);
	reg_val16 &= (~CHRON_FORCE_MASK);
	reg_val16 |= (((kal_uint8)enable << CHRON_FORCE_SHIFT) & CHRON_FORCE_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_cv_rt(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON0);
	reg_val16 &= (~CV_RT_MASK);
	reg_val16 |= (((kal_uint8)val << CV_RT_SHIFT) & CV_RT_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_cv_tune(pmu6253_cv_tune_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON0);
	reg_val16 &= (~CV_TUNE_MASK);
	reg_val16 |= (((kal_uint8)sel << CV_TUNE_SHIFT) & CV_TUNE_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x874) CHR CON1
void dcl_pmu6253_cal_precc(pmu6253_cal_precc_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON1);
	reg_val16 &= (~CAL_PRE_CC_MASK);
	reg_val16 |= (((kal_uint8)sel << CAL_PRE_CC_SHIFT) & CAL_PRE_CC_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_ps_sel(pmu6253_ps_sel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON1);
	reg_val16 &= (~PS_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << PS_SEL_SHIFT) & PS_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}
void dcl_pmu6253_ps_set(pmu6253_ps_set_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON1);
	reg_val16 &= (~PS_SET_MASK);
	reg_val16 |= (((kal_uint8)sel << PS_SET_SHIFT) & PS_SET_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_chr_ov_sel(pmu6253_chr_ov_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON1);
	reg_val16 &= (~CHROV_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << CHROV_SEL_SHIFT) & CHROV_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x878) CHR CON2
void dcl_pmu6253_cv_rt_extra_internal(kal_uint8 val)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON2);
	reg_val16 &= (~CV_TRIM_EXTRA_MASK);
	reg_val16 |= (((kal_uint8)val << CV_TRIM_EXTRA_SHIFT) & CV_TRIM_EXTRA_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_bool dcl_pmu6253_ovp(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON2);
	if (reg_val16 & OVP_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

kal_bool dcl_pmu6253_chrdet(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON2);
	if (reg_val16 & CHRDET_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

kal_bool dcl_pmu6253_bat_on(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON2);
	if (reg_val16 & BAT_ON_MASK){
		return KAL_FALSE;
	}
	return KAL_TRUE;
}

kal_bool dcl_pmu6253_bad_bat(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON2);
	if (reg_val16 & BAD_BATT_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

kal_bool dcl_pmu6253_cv_mode(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON2);
	if (reg_val16 & CV_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x87C) CHR CON3
void dcl_pmu6253_chr_wdt_td(pmu6253_chr_wdt_td_enum sel)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	ASSERT(sel <= 3);
	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON3);
	reg_val16 &= (~WDTIMER_TD_MASK);
	reg_val16 |= (((kal_uint8)sel << WDTIMER_TD_SHIFT) & WDTIMER_TD_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_chr_wdt_enable(kal_bool enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON3);
	reg_val16 &= (~WDTIMER_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << WDTIMER_EN_SHIFT) & WDTIMER_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x8F0) CHR CON4
void dcl_pmu6253_chr_wdt_intr_enable(kal_bool enable)
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON4);
	reg_val16 &= (~WDTIMER_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << WDTIMER_INT_EN_SHIFT) & WDTIMER_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_CHR_CON4, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_bool dcl_pmu6253_chr_wdt_status()
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;
	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON4);

	RestoreIRQMask(savedMask);


	if ((reg_val16 & WDTIMER_FLAG_MASK) != 0)
	{
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

void dcl_pmu6253_chr_wdt_clear()
{
	kal_uint16  reg_val16;
	kal_uint32  savedMask;
	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON4);
	reg_val16 |= WDTIMER_FLAG_MASK;
	PMU_DRV_WriteReg16(PMIC_CHR_CON4, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x8F4) CHR CON5
// wdt cnt is read only, NOT for write, used to monitor if WDT is active or NOT
//void dcl_pmu6253_chr_wdt_cnt(kal_uint32 val32)
//{
//	kal_uint16  reg_val16;
//	kal_uint32  savedMask;
//
//	savedMask = SaveAndSetIRQMask();
//
//	// Get LSB 16 bits
//	reg_val16 = (kal_uint16)((val32&0x0000FFFF));
//	PMU_DRV_WriteReg16(PMIC_CHR_CON5, reg_val16);
//
//	reg_val16 = PMU_DRV_ReadReg16(PMIC_CHR_CON4);
//	reg_val16 &= (~WDTIMER_CNT_19_16_MASK);
//	reg_val16 |= (( ((val32&0x000F0000)>>16) << WDTIMER_CNT_19_16_SHIFT) & WDTIMER_CNT_19_16_MASK);
//	PMU_DRV_WriteReg16(PMIC_CHR_CON4, reg_val16);
//
//	RestoreIRQMask(savedMask);
//}


// (0x880) DRIVER CON0
void dcl_pmu6253_isinks_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON0);
	reg_val16 &= (~ISINKS_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << ISINKS_EN_SHIFT) & ISINKS_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_isinks_force_off(kal_bool off){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON0);
	reg_val16 &= (~ISINKS_FORCES_OFF_MASK);
	reg_val16 |= (((kal_uint8)off << ISINKS_FORCES_OFF_SHIFT) & ISINKS_FORCES_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_kpled_type(pmu6253_kpled_type_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON0);
	reg_val16 &= (~KPLED_TYPE_MASK);
	reg_val16 |= (((kal_uint8)sel << KPLED_TYPE_SHIFT) & KPLED_TYPE_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_kpled_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON0);
	reg_val16 &= (~CCI_KPLED_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << CCI_KPLED_EN_SHIFT) & CCI_KPLED_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_kpled_force_off(kal_bool off){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON0);
	reg_val16 &= (~KPLED_FORCE_OFF_MASK);
	reg_val16 |= (((kal_uint8)off << KPLED_FORCE_OFF_SHIFT) & KPLED_FORCE_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_kpled_sel(pmu6253_kpled_sel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON0);
	reg_val16 &= (~KPLED_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << KPLED_SEL_SHIFT) & KPLED_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_bool dcl_pmu6253_isink1_status(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON0);
	if (reg_val16 & ISINK1_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

kal_bool dcl_pmu6253_isink2_status(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON0);
	if (reg_val16 & ISINK2_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

kal_bool dcl_pmu6253_isink3_status(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON0);
	if (reg_val16 & ISINK3_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

kal_bool dcl_pmu6253_isink4_status(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON0);
	if (reg_val16 & ISINK4_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

kal_bool dcl_pmu6253_kpled_status(void){
	kal_uint16  reg_val16;
	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON0);
	if (reg_val16 & KPLED_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x884) DRIVER CON1
void dcl_pmu6253_isinks_dimm(kal_uint8 sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON1);
	reg_val16 &= (~ISINKS_DIMM_MASK);
	reg_val16 |= (((kal_uint8)sel << ISINKS_DIMM_SHIFT) & ISINKS_DIMM_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_isinks_chsel(pmu6253_isinks_chsel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON1);
	reg_val16 &= (~ISINKS_CHSEL_MASK);
	reg_val16 |= (((kal_uint8)sel << ISINKS_CHSEL_SHIFT) & ISINKS_CHSEL_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x888) DRIVER CON2
void dcl_pmu6253_sinks_irset_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON2);
	reg_val16 &= (~ISINKS_IRSET_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << ISINKS_IRSET_CAL_SHIFT) & ISINKS_IRSET_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_isinks_vled_step(pmu6253_isinks_vled_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON2);
	reg_val16 &= (~ISINKS_VLED_STEP_MASK);
	reg_val16 |= (((kal_uint8)sel << ISINKS_VLED_STEP_SHIFT) & ISINKS_VLED_STEP_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x88C) DRIVER CON3
void dcl_pmu6253_bl_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON3);
	reg_val16 &= (~VBL_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBL_EN_SHIFT) & VBL_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vboost_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON3);
	reg_val16 &= (~VBOOST_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBOOST_EN_SHIFT) & VBOOST_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_bl_vgen_forceon(kal_bool on){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON3);
	reg_val16 &= (~BL_VGEN_FORCEON_MASK);
	reg_val16 |= (((kal_uint8)on << BL_VGEN_FORCEON_SHIFT) & BL_VGEN_FORCEON_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_bl_mode(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON3);
	reg_val16 &= (~BL_MODE_MASK);
	reg_val16 |= (((kal_uint8)val << BL_MODE_SHIFT) & BL_MODE_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_dimm_duty(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON3);
	reg_val16 &= (~BL_DIMM_DUTY_MASK);
	reg_val16 |= (((kal_uint8)val << BL_DIMM_DUTY_SHIFT) & BL_DIMM_DUTY_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x890) DRIVER CON4 ==> PMU53 SPEC V10
// (0x824) DRIVER CON4 ==> PMU53 SPEC V20
void dcl_pmu6253_vibr_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON4);
	reg_val16 &= (~CCI_VIBR_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << CCI_VIBR_EN_SHIFT) & CCI_VIBR_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON4, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vibr_sel(pmu6253_vibr_sel_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON4);
	reg_val16 &= (~VIBR_SEL_MASK);
	reg_val16 |= (((kal_uint8)sel << VIBR_SEL_SHIFT) & VIBR_SEL_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON4, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vibr_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON4);
	reg_val16 &= (~VIBR_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VIBR_CAL_SHIFT) & VIBR_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON4, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vibr_ocfb_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON4);
	reg_val16 &= (~VIBR_OCFB_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VIBR_OCFB_EN_SHIFT) & VIBR_OCFB_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_DRIVER_CON4, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_bool dcl_pmu6253_vibr_status(void){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_DRIVER_CON4);
	if (reg_val16 & VIBR_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x8A0) BOOST CON0
void dcl_pmu6253_vboost_sync_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_BOOST_CON0);
	reg_val16 &= (~VBOOST_SYNC_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBOOST_SYNC_EN_SHIFT) & VBOOST_SYNC_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_BOOST_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vboost_ss_speed(pmu6253_vboost_ss_speed_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_BOOST_CON0);
	reg_val16 &= (~VBOOST_SS_SPEED_MASK);
	reg_val16 |= (((kal_uint8)sel << VBOOST_SS_SPEED_SHIFT) & VBOOST_SS_SPEED_MASK);
	PMU_DRV_WriteReg16(PMIC_BOOST_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vboost_tune(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_BOOST_CON0);
	reg_val16 &= (~VBOOST_TUNE_MASK);
	reg_val16 |= (((kal_uint8)val << VBOOST_TUNE_SHIFT) & VBOOST_TUNE_MASK);
	PMU_DRV_WriteReg16(PMIC_BOOST_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vboost_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_BOOST_CON0);
	reg_val16 &= (~VBOOST_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VBOOST_CAL_SHIFT) & VBOOST_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_BOOST_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_bool dcl_pmu6253_vboost_trk_status(void){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_BOOST_CON0);
	if (reg_val16 & VBOOST_TRK_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

kal_bool dcl_pmu6253_vboost_status(void){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_BOOST_CON0);
	if (reg_val16 & VBOOST_STATUS_MASK){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// (0x8A4) BOOST CON1
void dcl_pmu6253_isns_cal(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_BOOST_CON1);
	reg_val16 &= (~VBOOST_ISNS_CAL_MASK);
	reg_val16 |= (((kal_uint8)val << VBOOST_ISNS_CAL_SHIFT) & VBOOST_ISNS_CAL_MASK);
	PMU_DRV_WriteReg16(PMIC_BOOST_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x8A8) BOOST CON2
void dcl_pmu6253_vboost_forceon_clk(kal_bool forceon){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_BOOST_CON2);
	reg_val16 &= (~VBOOST_FORCEON_CLK_MASK);
	reg_val16 |= (((kal_uint8)forceon << VBOOST_FORCEON_CLK_SHIFT) & VBOOST_FORCEON_CLK_MASK);
	PMU_DRV_WriteReg16(PMIC_BOOST_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vboost_disclk(kal_bool forceoff){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_BOOST_CON2);
	reg_val16 &= (~VBOOST_DISCLK_MASK);
	reg_val16 |= (((kal_uint8)forceoff << VBOOST_DISCLK_SHIFT) & VBOOST_DISCLK_MASK);
	PMU_DRV_WriteReg16(PMIC_BOOST_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x8B0) CLASSD CON0
static kal_uint8 spk1stDeadTimeCalbStage = 0;
void dcl_pmu6253_spk_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	if ((KAL_FALSE == enable))
	{
		if (spk1stDeadTimeCalbStage == 1)
		{
			dcl_pmu6253_spk_dtcal_noDisIRQ(KAL_FALSE);		// Disable dead time calibration
			spk1stDeadTimeCalbStage ++;
		}
	}

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON0);
	reg_val16 &= (~SPK_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << SPK_EN_SHIFT) & SPK_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON0, reg_val16);

	if ((KAL_TRUE == enable))
	{
		if (spk1stDeadTimeCalbStage == 0)
		{
			dcl_pmu6253_spk_dmode_noDisIRQ(SPK_DMODE_FF_AUTO);
			dcl_pmu6253_spk_dtcal_noDisIRQ(KAL_TRUE);		// Enable dead time calibration
			spk1stDeadTimeCalbStage++;
		}
	}

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spk_reset(kal_bool reset){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON0);
	reg_val16 &= (~SPK_RST_MASK);
	reg_val16 |= (((kal_uint8)reset << SPK_RST_SHIFT) & SPK_RST_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spk_emode(pmu6253_spk_emode_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON0);
	reg_val16 &= (~SPK_EMODE_MASK);
	reg_val16 |= (((kal_uint8)sel << SPK_EMODE_SHIFT) & SPK_EMODE_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spk_mode(pmu6253_spk_mode_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON0);
	reg_val16 &= (~SPK_MODE_MASK);
	reg_val16 |= (((kal_uint8)sel << SPK_MODE_SHIFT) & SPK_MODE_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spkab_float(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON0);
	reg_val16 &= (~SPKAB_FLOAT_MASK);
	reg_val16 |= (((kal_uint8)enable << SPKAB_FLOAT_SHIFT) & SPKAB_FLOAT_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spkab_sended(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON0);
	reg_val16 &= (~SPKAB_SENDED_MASK);
	reg_val16 |= (((kal_uint8)enable << SPKAB_SENDED_SHIFT) & SPKAB_SENDED_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spkab_oc_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON0);
	reg_val16 &= (~SPKAB_OC_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << SPKAB_OC_EN_SHIFT) & SPKAB_OC_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spkab_depop_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON0);
	reg_val16 &= (~SPKAB_DEPOP_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << SPKAB_DEPOP_EN_SHIFT) & SPKAB_DEPOP_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spkab_obias(pmu6253_spkab_obias_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON0);
	reg_val16 &= (~SPKAB_OBIAS_MASK);
	reg_val16 |= (((kal_uint8)sel << SPKAB_OBIAS_SHIFT) & SPKAB_OBIAS_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x8B4) CLASSD CON1
void dcl_pmu6253_spk_dtin(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON1);
	reg_val16 &= (~SPK_DTIN_MASK);
	reg_val16 |= (((kal_uint8)val << SPK_DTIN_SHIFT) & SPK_DTIN_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spk_dtip(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON1);
	reg_val16 &= (~SPK_DTIP_MASK);
	reg_val16 |= (((kal_uint8)val << SPK_DTIP_SHIFT) & SPK_DTIP_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spk_dtcn(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON1);
	reg_val16 &= (~SPK_DTCN_MASK);
	reg_val16 |= (((kal_uint8)val << SPK_DTCN_SHIFT) & SPK_DTCN_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spk_dtcp(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON1);
	reg_val16 &= (~SPK_DTCP_MASK);
	reg_val16 |= (((kal_uint8)val << SPK_DTCP_SHIFT) & SPK_DTCP_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x8B8) CLASSD CON2
void dcl_pmu6253_spk_dmode(pmu6253_spk_dmode_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON2);
	reg_val16 &= (~SPK_DMODE_MASK);
	reg_val16 |= (((kal_uint8)sel << SPK_DMODE_SHIFT) & SPK_DMODE_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spk_dmode_noDisIRQ(pmu6253_spk_dmode_enum sel){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON2);
	reg_val16 &= (~SPK_DMODE_MASK);
	reg_val16 |= (((kal_uint8)sel << SPK_DMODE_SHIFT) & SPK_DMODE_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON2, reg_val16);
}



void dcl_pmu6253_spk_pchg(pmu6253_spk_pchg_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON2);
	reg_val16 &= (~SPK_PCHG_MASK);
	reg_val16 |= (((kal_uint8)sel << SPK_PCHG_SHIFT) & SPK_PCHG_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spk_dtcal(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON2);
	reg_val16 &= (~SPK_DTCAL_MASK);
	reg_val16 |= (((kal_uint8)enable << SPK_DTCAL_SHIFT) & SPK_DTCAL_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spk_dtcal_noDisIRQ(kal_bool enable){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON2);
	reg_val16 &= (~SPK_DTCAL_MASK);
	reg_val16 |= (((kal_uint8)enable << SPK_DTCAL_SHIFT) & SPK_DTCAL_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON2, reg_val16);
}

void dcl_pmu6253_spk_pmode_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON2);
	reg_val16 &= (~SPK_PMODE_MASK);
	reg_val16 |= (((kal_uint8)enable << SPK_PMODE_SHIFT) & SPK_PMODE_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spk_cmode(pmu6253_spk_freq_ctrl_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON2);
	reg_val16 &= (~SPK_CMODE_MASK);
	reg_val16 |= (((kal_uint8)sel << SPK_CMODE_SHIFT) & SPK_CMODE_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spk_ccode(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON2);
	reg_val16 &= (~SPK_CCODE_MASK);
	reg_val16 |= (((kal_uint8)val << SPK_CCODE_SHIFT) & SPK_CCODE_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x8BC) CLASSD CON3
void dcl_pmu6253_spk_enable_view_clk(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON3);
	reg_val16 &= (~SPK_EN_VIEW_CLK_MASK);
	reg_val16 |= (((kal_uint8)enable << SPK_EN_VIEW_CLK_SHIFT) & SPK_EN_VIEW_CLK_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spk_enable_view_vref(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON3);
	reg_val16 &= (~SPK_EN_VIEW_VREF_MASK);
	reg_val16 |= (((kal_uint8)enable << SPK_EN_VIEW_VREF_SHIFT) & SPK_EN_VIEW_VREF_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spk_slew(pmu6253_spk_slew_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON3);
	reg_val16 &= (~SPK_SLEW_MASK);
	reg_val16 |= (((kal_uint8)sel << SPK_SLEW_SHIFT) & SPK_SLEW_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spk_oc_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON3);
	reg_val16 &= (~SPK_OC_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << SPK_OC_EN_SHIFT) & SPK_OC_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spk_oscisel_half(kal_bool half){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON3);
	reg_val16 &= (~SPK_OSCISEL_MASK);
	reg_val16 |= (((kal_uint8)half << SPK_OSCISEL_SHIFT) & SPK_OSCISEL_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spk_vol(kal_uint8 val){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON3);
	reg_val16 &= (~SPK_VOL_MASK);
	reg_val16 |= (((kal_uint8)val << SPK_VOL_SHIFT) & SPK_VOL_MASK);
	PMU_DRV_WriteReg16(PMIC_CLASSD_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

kal_uint8 dcl_pmu6253_spk_get_vol(void){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();
	reg_val16 = PMU_DRV_ReadReg16(PMIC_CLASSD_CON3);
	RestoreIRQMask(savedMask);

	reg_val16 &= SPK_VOL_MASK;

	return (reg_val16 >> SPK_VOL_SHIFT);

}

// (0x8C8) TEST CON2
void dcl_pmu6253_adc_vol_divided_by_2(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_TEST_CON2);
	reg_val16 &= (~ADC_TMR_MASK);
	reg_val16 |= (((kal_uint8)enable << ADC_TMR_SHIFT) & ADC_TMR_MASK);
	PMU_DRV_WriteReg16(PMIC_TEST_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}
void dcl_pmu6253_adc_meas_on(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_TEST_CON2);
	reg_val16 &= (~(ADC_VBAT_OUT_EN_MASK | ADC_ISENSE_OUT_EN_MASK));
	if (enable){
		reg_val16 |= (ADC_VBAT_OUT_EN_MASK | ADC_ISENSE_OUT_EN_MASK);
	}

	PMU_DRV_WriteReg16(PMIC_TEST_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

#define ADC_TMR_MASK				0x0020
#define ADC_TMR_SHIFT				5
#define ADC_VBAT_OUT_EN_MASK		0x0040
#define ADC_VBAT_OUT_EN_SHIFT		6
#define ADC_ISENSE_OUT_EN_MASK		0x0080
#define ADC_ISENSE_OUT_EN_SHIFT		7

// (0x8D0) OC CON0
void dcl_pmu6253_vrf_oc_gear(pmu6253_gear_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VRF_OC_GEAR_MASK);
	reg_val16 |= (((kal_uint8)sel << VRF_OC_GEAR_SHIFT) & VRF_OC_GEAR_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vrf_oc_auto_off(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VRF_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VRF_OC_AUTO_OFF_SHIFT) & VRF_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vrf_oc_int_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VRF_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VRF_OC_INT_EN_SHIFT) & VRF_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vio_oc_gear(pmu6253_gear_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VIO_OC_GEAR_MASK);
	reg_val16 |= (((kal_uint8)sel << VIO_OC_GEAR_SHIFT) & VIO_OC_GEAR_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vio_oc_auto_off(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VIO_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VIO_OC_AUTO_OFF_SHIFT) & VIO_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vio_oc_int_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VIO_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VIO_OC_INT_EN_SHIFT) & VIO_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vm_oc_gear(pmu6253_gear_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VM_OC_GEAR_MASK);
	reg_val16 |= (((kal_uint8)sel << VM_OC_GEAR_SHIFT) & VM_OC_GEAR_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vm_oc_auto_off(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VM_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VM_OC_AUTO_OFF_SHIFT) & VM_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vm_oc_int_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VM_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VM_OC_INT_EN_SHIFT) & VM_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_va_oc_gear(pmu6253_gear_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VA_OC_GEAR_MASK);
	reg_val16 |= (((kal_uint8)sel << VA_OC_GEAR_SHIFT) & VA_OC_GEAR_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}
void dcl_pmu6253_va_oc_auto_off(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VA_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VA_OC_AUTO_OFF_SHIFT) & VA_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_va_oc_int_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON0);
	reg_val16 &= (~VA_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VA_OC_INT_EN_SHIFT) & VA_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON0, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x8D4) OC CON1
void dcl_pmu6253_vtcxo_oc_gear(pmu6253_gear_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON1);
	reg_val16 &= (~VTCXO_OC_GEAR_MASK);
	reg_val16 |= (((kal_uint8)sel << VTCXO_OC_GEAR_SHIFT) & VTCXO_OC_GEAR_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vtcxo_oc_auto_off(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON1);
	reg_val16 &= (~VTCXO_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VTCXO_OC_AUTO_OFF_SHIFT) & VTCXO_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vtcxo_oc_int_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON1);
	reg_val16 &= (~VTCXO_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VTCXO_OC_INT_EN_SHIFT) & VTCXO_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON1, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x8D8) OC CON2
void dcl_pmu6253_vbt_oc_gear(pmu6253_gear_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON2);
	reg_val16 &= (~VBT_OC_GEAR_MASK);
	reg_val16 |= (((kal_uint8)sel << VBT_OC_GEAR_SHIFT) & VBT_OC_GEAR_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vbt_oc_auto_off(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON2);
	reg_val16 &= (~VBT_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VBT_OC_AUTO_OFF_SHIFT) & VBT_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vbt_oc_int_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON2);
	reg_val16 &= (~VBT_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBT_OC_INT_EN_SHIFT) & VBT_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vusb_oc_gear(pmu6253_gear_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON2);
	reg_val16 &= (~VUSB_OC_GEAR_MASK);
	reg_val16 |= (((kal_uint8)sel << VUSB_OC_GEAR_SHIFT) & VUSB_OC_GEAR_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vusb_oc_auto_off(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON2);
	reg_val16 &= (~VUSB_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VUSB_OC_AUTO_OFF_SHIFT) & VUSB_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vusb_oc_int_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON2);
	reg_val16 &= (~VUSB_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VUSB_OC_INT_EN_SHIFT) & VUSB_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcamd_oc_gear(pmu6253_gear_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON2);
	reg_val16 &= (~VCAMD_OC_GEAR_MASK);
	reg_val16 |= (((kal_uint8)sel << VCAMD_OC_GEAR_SHIFT) & VCAMD_OC_GEAR_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcamd_oc_auto_off(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON2);
	reg_val16 &= (~VCAMD_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMD_OC_AUTO_OFF_SHIFT) & VCAMD_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcamd_oc_int_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON2);
	reg_val16 &= (~VCAMD_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMD_OC_INT_EN_SHIFT) & VCAMD_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcama_oc_gear(pmu6253_gear_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON2);
	reg_val16 &= (~VCAMA_OC_GEAR_MASK);
	reg_val16 |= (((kal_uint8)sel << VCAMA_OC_GEAR_SHIFT) & VCAMA_OC_GEAR_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcama_oc_auto_off(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON2);
	reg_val16 &= (~VCAMA_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMA_OC_AUTO_OFF_SHIFT) & VCAMA_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcama_oc_int_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON2);
	reg_val16 &= (~VCAMA_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VCAMA_OC_INT_EN_SHIFT) & VCAMA_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON2, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x8DC) OC CON3
void dcl_pmu6253_spk_oc_gear(pmu6253_gear_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON3);
	reg_val16 &= (~VSPK_OC_GEAR_MASK);
	reg_val16 |= (((kal_uint8)sel << VSPK_OC_GEAR_SHIFT) & VSPK_OC_GEAR_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spk_oc_auto_off(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON3);
	reg_val16 &= (~VSPK_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VSPK_OC_AUTO_OFF_SHIFT) & VSPK_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_spk_oc_int_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON3);
	reg_val16 &= (~VSPK_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VSPK_OC_INT_EN_SHIFT) & VSPK_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vibr_oc_gear(pmu6253_gear_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON3);
	reg_val16 &= (~VIBR_OC_GEAR_MASK);
	reg_val16 |= (((kal_uint8)sel << VIBR_OC_GEAR_SHIFT) & VIBR_OC_GEAR_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vibr_oc_auto_off(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON3);
	reg_val16 &= (~VIBR_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VIBR_OC_AUTO_OFF_SHIFT) & VIBR_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vibr_oc_int_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON3);
	reg_val16 &= (~VIBR_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VIBR_OC_INT_EN_SHIFT) & VIBR_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vboost_oc_gear(pmu6253_gear_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON3);
	reg_val16 &= (~VBOOST_OC_GEAR_MASK);
	reg_val16 |= (((kal_uint8)sel << VBOOST_OC_GEAR_SHIFT) & VBOOST_OC_GEAR_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vboost_oc_auto_off(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON3);
	reg_val16 &= (~VBOOST_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VBOOST_OC_AUTO_OFF_SHIFT) & VBOOST_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vboost_oc_int_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON3);
	reg_val16 &= (~VBOOST_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VBOOST_OC_INT_EN_SHIFT) & VBOOST_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vsim_oc_gear(pmu6253_gear_enum sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON3);
	reg_val16 &= (~VSIM_OC_GEAR_MASK);
	reg_val16 |= (((kal_uint8)sel << VSIM_OC_GEAR_SHIFT) & VSIM_OC_GEAR_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vsim_oc_auto_off(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON3);
	reg_val16 &= (~VSIM_OC_AUTO_OFF_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM_OC_AUTO_OFF_SHIFT) & VSIM_OC_AUTO_OFF_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vsim_oc_int_enable(kal_bool enable){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON3);
	reg_val16 &= (~VSIM_OC_INT_EN_MASK);
	reg_val16 |= (((kal_uint8)enable << VSIM_OC_INT_EN_SHIFT) & VSIM_OC_INT_EN_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON3, reg_val16);

	RestoreIRQMask(savedMask);
}

// (0x8E0) OC CON4
void dcl_pmu6253_vibr_stbtd(pmu6253_soft_start_delay sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON4);
	reg_val16 &= (~VIBR_STBTD_MASK);
	reg_val16 |= (((kal_uint8)sel << VIBR_STBTD_SHIFT) & VIBR_STBTD_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON4, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vsim_stbtd(pmu6253_soft_start_delay sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON4);
	reg_val16 &= (~VSIM_STBTD_MASK);
	reg_val16 |= (((kal_uint8)sel << VSIM_STBTD_SHIFT) & VSIM_STBTD_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON4, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vbt_stbtd(pmu6253_soft_start_delay sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON4);
	reg_val16 &= (~VBT_STBTD_MASK);
	reg_val16 |= (((kal_uint8)sel << VBT_STBTD_SHIFT) & VBT_STBTD_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON4, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vusb_stbtd(pmu6253_soft_start_delay sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON4);
	reg_val16 &= (~VUSB_STBTD_MASK);
	reg_val16 |= (((kal_uint8)sel << VUSB_STBTD_SHIFT) & VUSB_STBTD_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON4, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcamd_stbtd(pmu6253_soft_start_delay sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON4);
	reg_val16 &= (~VCAMD_STBTD_MASK);
	reg_val16 |= (((kal_uint8)sel << VCAMD_STBTD_SHIFT) & VCAMD_STBTD_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON4, reg_val16);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_vcama_stbtd(pmu6253_soft_start_delay sel){
	kal_uint16  reg_val16;
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON4);
	reg_val16 &= (~VCAMA_STBTD_MASK);
	reg_val16 |= (((kal_uint8)sel << VCAMA_STBTD_SHIFT) & VCAMA_STBTD_MASK);
	PMU_DRV_WriteReg16(PMIC_OC_CON4, reg_val16);

	RestoreIRQMask(savedMask);
}


// (0x8E4) OC CON5
kal_bool dcl_pmu6253_oc_flag(pmu6253_oc_bit_enum sel){
	kal_uint16  reg_val16;

	reg_val16 = PMU_DRV_ReadReg16(PMIC_OC_CON4);
	if (reg_val16 & sel){
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

void dcl_pmu6253_clear_oc_flag(pmu6253_oc_bit_enum sel){
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	PMU_DRV_WriteReg16(PMIC_OC_CON4, (kal_uint16)sel);

	RestoreIRQMask(savedMask);
}

void dcl_pmu6253_clear_all_oc_flag(){
	kal_uint32  savedMask;

	savedMask = SaveAndSetIRQMask();

	PMU_DRV_WriteReg16(PMIC_OC_CON4, 0xF8FF);

	RestoreIRQMask(savedMask);
}


// ====== Other exported APIs =============
//remove in the feature


//extern pmu6253_chr_current_enum pmu6253_ret_custom_current(chr_type chr);
pmu6253_chr_current_enum pmu6253_ret_chr_current(){
	//return pmu6253_ret_custom_current(AC_CHR);
	return CHR_CURR_650_0MA;

}
pmu6253_chr_current_enum pmu6253_ret_usb_current(){
	//return return pmu6253_ret_custom_current(USB_CHR);
	return CHR_CURR_450_0MA;
}





//CHR CURRENT
DCL_UINT32 cs_vth[]=
{
	PMU_CHARGE_CURRENT_50_00_MA,PMU_CHARGE_CURRENT_87_50_MA,
	PMU_CHARGE_CURRENT_150_00_MA,PMU_CHARGE_CURRENT_225_00_MA,
	PMU_CHARGE_CURRENT_300_00_MA,PMU_CHARGE_CURRENT_450_00_MA,
	PMU_CHARGE_CURRENT_650_00_MA,PMU_CHARGE_CURRENT_800_00_MA
};

		
DCL_UINT32 vcama_vosel[]=
{
      PMU_VOLT_01_500000_V, PMU_VOLT_01_800000_V, PMU_VOLT_02_500000_V, PMU_VOLT_02_800000_V
};

DCL_UINT32 vcamd_vosel[]=
{
      PMU_VOLT_01_300000_V, PMU_VOLT_01_500000_V, PMU_VOLT_01_800000_V, PMU_VOLT_02_800000_V
};

DCL_UINT32 vibr_vosel[]=
{
      PMU_VOLT_01_500000_V, PMU_VOLT_01_800000_V, PMU_VOLT_02_500000_V, PMU_VOLT_03_000000_V
};

DCL_UINT32 vbt_vosel[]=
{
      PMU_VOLT_02_800000_V, PMU_VOLT_03_000000_V
};

DCL_UINT32 vboost_vosel[]=
{
	PMU_VOLT_03_200000_V,PMU_VOLT_03_350000_V,PMU_VOLT_03_500000_V,PMU_VOLT_03_650000_V,
	PMU_VOLT_03_800000_V,PMU_VOLT_03_950000_V,PMU_VOLT_04_100000_V,PMU_VOLT_04_250000_V,
	PMU_VOLT_04_400000_V,PMU_VOLT_04_550000_V,PMU_VOLT_04_700000_V,PMU_VOLT_04_850000_V,
	PMU_VOLT_05_000000_V,PMU_VOLT_05_150000_V,PMU_VOLT_05_300000_V,PMU_VOLT_05_450000_V
};


PMU_PARAMETER_TABLE_ENTRY pmu_parameter_table[]=
{
/*
	//BUCK group
	{ENC(LDO_BUCK_SET_VOLTAGE,VSIM),		vsim_vosel,		NULL,				GETARRNUM(vsim_vosel)		},	
	{ENC(LDO_BUCK_SET_VOLTAGE,VSIM2),		vsim2_vosel,	NULL,				GETARRNUM(vsim2_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,VIBR),		vsim2_vosel,	NULL,				GETARRNUM(vsim2_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,VMC),		vsim2_vosel,	NULL,				GETARRNUM(vsim2_vosel)	},	
*/
	{ENC(LDO_BUCK_SET_VOLTAGE,VIBR),		vibr_vosel,		NULL,				GETARRNUM(vibr_vosel)		},
	{ENC(LDO_BUCK_SET_VOLTAGE,VCAMA),		vcama_vosel,	NULL,				GETARRNUM(vcama_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,VCAMD),		vcamd_vosel,	NULL,				GETARRNUM(vcamd_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,VBT),		vbt_vosel,		NULL,				GETARRNUM(vbt_vosel)	},
	//Boost
	{ENC(BOOST_SET_VOLTAGE,ALLMOD),		vboost_vosel,	NULL,				GETARRNUM(vboost_vosel)	},		
	//CHR
	{ENC(CHR_SET_CHR_CURRENT,ALLMOD),				cs_vth,				NULL,				GETARRNUM(cs_vth)		}
};


extern PMU_CONTROL_HANDLER pmu_control_handler;
DCL_UINT16 pmu_parameter_size=0;

DCL_STATUS dcl_pmu6253_Ldo_Set_En(PMU_LDO_BUCK_LIST_ENUM mod,DCL_BOOL enable)
{

	switch(mod)
	{
		case VIBR:
		{
			dcl_pmu6253_vibr_enable(enable);
		}
		break;	
		case VRF:
		{
			dcl_pmu6253_vrf_enable(enable);
		}
		break;	
		case VTCXO:
		{
			dcl_pmu6253_vtcxo_enable(enable);
		}
		break;		
		case VCAMA:
		{
			dcl_pmu6253_vcama_enable(enable);
		}
		break;	
		case VCAMD:
		{
			dcl_pmu6253_vcamd_enable(enable);
		}
		break;	
		case VUSB:
		{
			dcl_pmu6253_vusb_enable(enable);
		}
		break;	
		case VBT:
		{
			dcl_pmu6253_vbt_enable(enable);
		}
		break;			
		default:				
		return STATUS_UNSUPPORTED;
		break;			
	}

	return STATUS_OK;
}


DCL_STATUS dcl_pmu6253_Ldo_Set_Voltage(PMU_LDO_BUCK_LIST_ENUM mod,DCL_UINT16 regVal)
{
	switch(mod)
	{
		case VCAMA:
		{
			dcl_pmu6253_vcama_sel(regVal);
		}
		break;	
		case VCAMD:
		{
			dcl_pmu6253_vcamd_sel(regVal);
		}
		break;	
		case VIBR:
		{
			dcl_pmu6253_vibr_sel(regVal);
		}
		break;
		case VBT:
		{
			dcl_pmu6253_vbt_sel(regVal);
		}
		break;			
		default:				
		return STATUS_UNSUPPORTED;
		break;			
	}	

	return STATUS_OK;
}

DCL_STATUS dcl_pmu6253_control_handler(DCL_HANDLE handle,DCL_CTRL_CMD cmd,DCL_CTRL_DATA_T *data)
{
	DCL_UINT16	regVal;
	DCL_UINT32	val;


	switch(cmd)
	{
		//LDO,BUCK
		case LDO_BUCK_SET_EN:
		{
			PMU_CTRL_LDO_BUCK_SET_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetEn);
			return dcl_pmu6253_Ldo_Set_En(pLdoBuckCtrl->mod,pLdoBuckCtrl->enable);
		}
		break;	
		case LDO_BUCK_SET_VOLTAGE:
		{
			PMU_CTRL_LDO_BUCK_SET_VOLTAGE *pLdoBuckCtrl=&(data->rPMULdoBuckSetVoltage);			
			regVal=PMU_Parameter_to_Value(ENC(cmd,pLdoBuckCtrl->mod),pLdoBuckCtrl->voltage);
			return dcl_pmu6253_Ldo_Set_Voltage(pLdoBuckCtrl->mod,regVal);
		}	
		break;	
		case LDO_BUCK_SET_ON_SEL:
		{
			PMU_CTRL_LDO_BUCK_SET_ON_SEL *pLdoBuckCtrl=&(data->rPMULdoBuckSetOnSel);	
			switch(pLdoBuckCtrl->mod)
			{
				case VRF:
				{
					dcl_pmu6253_vrf_on_sel((pmu6253_vrf_on_sel_enum)pLdoBuckCtrl->onSel);
				}
				break;	
				case VTCXO:
				{
					dcl_pmu6253_vtcxo_on_sel((pmu6253_vrf_on_sel_enum)pLdoBuckCtrl->onSel);
				}
				break;		
				default:				
				return STATUS_UNSUPPORTED;
				break;			
			}				
		}
		//BOOST
		case BOOST_SET_EN:
		{
			PMU_CTRL_BOOST_SET_EN *pBoostCtrl=&(data->rPMUBoostSetEn);
			dcl_pmu6253_vboost_enable(pBoostCtrl->enable);
		}
		break;
		case BOOST_SET_SYNC_EN:
		{
			PMU_CTRL_BOOST_SET_SYNC_EN *pBoostCtrl=&(data->rPMUBoostSetSyncEn);
			dcl_pmu6253_vboost_sync_enable(pBoostCtrl->enable);
		}
		break;	
		case BOOST_SET_VOLTAGE:
		{
			PMU_CTRL_BOOST_SET_VOLTAGE *pBoostCtrl=&(data->rPMUBoostSetVoltage);
			regVal=PMU_Parameter_to_Value(ENC(cmd,pBoostCtrl->boost),pBoostCtrl->voltage);
			dcl_pmu6253_vboost_tune(regVal);
		}
		break;
		//KPLED
		case KPLED_SET_EN:
		{
			PMU_CTRL_KPLED_SET_EN *pKpledCtrl=&(data->rPMUKpledSetEn);
			dcl_pmu6253_kpled_enable(pKpledCtrl->enable);
		}
		break;
		//SPK
		case SPK_SET_EN:
		{
			PMU_CTRL_SPK_SET_EN *pSpkCtrl=&(data->rPMUSpkSetEn);
			dcl_pmu6253_spk_enable(pSpkCtrl->enable);
		}
		break;		
		case SPK_SET_VOL_VALUE:
		{
			PMU_CTRL_SPK_SET_VOL_VALUE *pSpkCtrl=&(data->rPMUSpkSetVolValue);
			dcl_pmu6253_spk_vol(pSpkCtrl->volValue);
		}
		break;
		case SPK_GET_VOL_VALUE:
		{
			PMU_CTRL_SPK_GET_VOL_VALUE *pSpkCtrl=&(data->rPMUSpkGetVolValue);
			pSpkCtrl->volValue=dcl_pmu6253_spk_get_vol();
		}
		break;		
		case SPK_SET_MODE:
		{
			PMU_CTRL_SPK_SET_MODE *pSpkCtrl=&(data->rPMUSpkSetMode);
			dcl_pmu6253_spk_mode(pSpkCtrl->mode);
		}
		break;	
		case SPK_SET_OC_AUTO_OFF:
		{
			PMU_CTRL_SPK_SET_OC_AUTO_OFF *pSpkCtrl=&(data->rPMUSpkSetOcAutoOff);
			dcl_pmu6253_spk_oc_enable(pSpkCtrl->enable);
		}
		break;			
		//CHR
		case CHR_GET_CHR_DET_STATUS:
		{
			PMU_CTRL_CHR_GET_CHR_DET_STATUS *pChrCtrl=&(data->rPMUChrGetChrDetStatus);
			pChrCtrl->enable=dcl_pmu6253_chrdet();			
		}
		break;
		case CHR_SET_CHR_EN:
		{
			PMU_CTRL_CHR_SET_CHR_EN *pChrCtrl=&(data->rPMUChrSetChrEn);
			dcl_pmu6253_chr_enable(pChrCtrl->enable);
		}
		break;
		case CHR_GET_CHR_CURRENT:
		{
			PMU_CTRL_CHR_GET_CHR_CURRENT *pChrCtrl=&(data->rPMUChrGetChrCurrent);
			pChrCtrl->current=(PMU_CHR_CURRENT_ENUM)PMU_Value_to_Parameter(ENC(CHR_SET_CHR_CURRENT,CHR),(DCL_UINT32)dcl_pmu6253_chr_get_current());
		}
		break;			
		case CHR_SET_CHR_CURRENT:
		{
			PMU_CTRL_CHR_SET_CHR_CURRENT *pChrCtrl=&(data->rPMUChrSetChrCurrent);	
			regVal=PMU_Parameter_to_Value(ENC(cmd,CHR),pChrCtrl->current);

			if (regVal==PARAMETER_UNKNOWN)
				ASSERT(0);

			dcl_pmu6253_chr_current(regVal);
		}
		break;		
		case CHR_GET_CHR_CURRENT_LIST:
		{
			PMU_CTRL_CHR_GET_CHR_CURRENT_LIST *pChrCtrl=&(data->rPMUChrGetChrCurrentList);
			pChrCtrl->pCurrentList=cs_vth;
			pChrCtrl->number=GETARRNUM(cs_vth);
		}
		break;			
		case CHR_GET_IS_CHR_VALID:
		{

			PMU_CTRL_CHR_GET_IS_CHR_VALID	*pChrCtrl=&(data->rPMUChrGetIsChrValid);
			pChrCtrl->enable=(DCL_BOOL)(!dcl_pmu6253_ovp());
		}
		break;			
		case CHR_SET_ADC_MEASURE_EN:
		{
			PMU_CTRL_CHR_SET_ADC_MEASURE_EN *pChrCtrl=&(data->rPMUChrSetAdcMeasureEn);		
			dcl_pmu6253_adc_meas_on(pChrCtrl->enable);
		}
		break;	
		case CHR_GET_IS_BATTERY_ON:
		{	//always return TRUE (why?)
			PMU_CTRL_CHR_GET_IS_BATTERY_ON *pChrCtrl=&(data->rPMUChrGetIsBatteryOn);		
			pChrCtrl->enable=dcl_pmu6253_bat_on();
		}
		break;			
		case CHR_SET_WDT_CLEAR:
		{	
			dcl_pmu6253_chr_wdt_clear();
		}
		break;		
		case CHR_SET_CHR_FORCE_EN:
		{
			PMU_CTRL_CHR_SET_CHR_FORCE_EN		*pChrCtrl=&(data->rPMUChrSetChrForceEn);
			dcl_pmu6253_chr_force_enable((kal_bool)pChrCtrl->enable);
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
		break;
	}

}	


void dcl_pmu6253_init(void)
{


	pmu_control_handler=dcl_pmu6253_control_handler;
	pmu_parameter_size=GETARRNUM(pmu_parameter_table);	


//	pmu6253_vsim_enable(KAL_TRUE);
//	pmu6253_vsim2_enable(KAL_TRUE);

	dcl_pmu6253_vio_vd_sense(VD_SENSE_FROM_REMOTE_VOLTAGE);
	dcl_pmu6253_vm_vd_sense(VD_SENSE_FROM_REMOTE_VOLTAGE);
	dcl_pmu6253_va_vd_sense(VD_SENSE_FROM_REMOTE_VOLTAGE);
//	pmu6253_vusb_enable(KAL_TRUE);		// Is this necessary?

	dcl_pmu6253_cv_tune(CV_TUNE_1_200V);
	dcl_pmu6253_cv_rt(1);

	dcl_pmu6253_vcore_acc_out_init(8);

	dcl_pmu6253_chr_wdt_td(CHR_WDT_32_SEC);
	dcl_pmu6253_chr_wdt_enable(KAL_TRUE);
#if defined(DEBUG_DISABLE_CHARGE_WDT)
	dcl_pmu6253_chr_wdt_enable(KAL_FALSE);
#endif // #if defined(DEBUG_DISABLE_CHARGE_WDT)


	dcl_pmu6253_vboost_cal(VBOOST_I_SINK_CURRECT_MATCH);

	dcl_pmu6253_vrf_ocfb_enable(KAL_TRUE);
	dcl_pmu6253_vio_ocfb_enable(KAL_TRUE);
	dcl_pmu6253_vm_ocfb_enable(KAL_TRUE);
	dcl_pmu6253_vtcxo_ocfb_enable(KAL_TRUE);
	dcl_pmu6253_va_ocfb_enable(KAL_TRUE);
	// pmu6253_vsim_ocfb_enable(KAL_TRUE);
	dcl_pmu6253_vusb_ocfb_enable(KAL_TRUE);
	dcl_pmu6253_vbt_ocfb_enable(KAL_TRUE);
	dcl_pmu6253_vcamd_ocfb_enable(KAL_TRUE);
	dcl_pmu6253_vcama_ocfb_enable(KAL_TRUE);
	dcl_pmu6253_vibr_ocfb_enable(KAL_TRUE);

	dcl_pmu6253_vcore_vd_sense(VD_SENSE_FROM_REMOTE_VOLTAGE);

	// Set sleep mode vcore to 1.0V
	//pmu6253_vcore_vfbadj_slp(VCORE_VFBADJ_1_00V);
	dcl_pmu6253_vcore_vfbadj_slp(VCORE_VFBADJ_1_25V);
	#if defined(MT6253_VCORE_1_3V)
	dcl_pmu6253_vcore_vfbadj(VCORE_VFBADJ_1_30V);
	#endif // #if defined(MT6253_VCORE_1_3V)

	pmu6253_customization_init();


#if defined(PMIC_6253_CV_TRIM_CALIBRATION)
	{
		kal_uint32 efuse_val;
		//efuse_val = *(volatile kal_uint32 *)(0x8000F018);
		efuse_val = PMU_DRV_ReadReg32(EFUSE_base + 0xF018);
		if ( (efuse_val & 0x01000000) != 0) // Bit24
		{
			//efuse_val = *(volatile kal_uint32 *)(0x8000F018);
			efuse_val = PMU_DRV_ReadReg32(EFUSE_base + 0xF018);
			// Bit[19..17]: CV_TUNE
			dcl_pmu6253_cv_tune((pmu6253_cv_tune_enum)((efuse_val&0x000E0000)>>17));
			// Bit[21..20]: CV_RT
			dcl_pmu6253_cv_rt((kal_uint8)((efuse_val&0x00300000) >> 20));
			// Bit[23]: CHR_RSV[0]  (CV_RT_EXTRA)
			dcl_pmu6253_cv_rt_extra_internal((kal_uint8)((efuse_val&0x00800000) >> 23));
		}
	}
#endif // #if defined(PMIC_6253_CV_TRIM_CALIBRATION)


}




#endif //#if (defined(PMIC_6253_REG_API))

