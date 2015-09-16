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
 *    dcl_pmu6276.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module is for PMU6276
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
#include "dcl.h"
#include "dcl_pmu_sw.h"

#if (defined(PMIC_6276_REG_API))

extern PMU_CONTROL_HANDLER pmu_control_handler;
DCL_UINT16 pmu_parameter_size=0;

PMU_MOD_BASEADDR_ENTRY pmu_ldo_bb_profile[]=
{
    {VA12,  		VA12_CON0},
    {VRTC,  		VRTC_CON0},
    {VMIC,  		VMIC_CON0},
    {VAUDN,  		VAUDN_CON0},
    {VAUDP,  		VAUDP_CON0},
    {VRF28,  		VRF_CON0},
    {VTCXO,  		VTCXO_CON0},
    {VA25,  		VA25_CON0},
    {VCAMA,  		VCAMA_CON0},
    {VCAMD,  		VCAMD_CON0},
    {VIO28,  		VIO_CON0},
    {VUSB,  		VUSB_CON0},
    {VBT,  		VBT_CON0},
    {VSIM,  		VSIM_CON0},
    {VSIM2,  		VSIM2_CON0},
    {VIBR,  		VIBR_CON0},
    {VMC,  		VMC_CON0},
    {VCAMA2, 		VCAMA2_CON0},
    {VCAMD2, 		VCAMD2_CON0},
    {VFM,		  	VFM_CON0},
    {VM12,	  	VM12_CON0},
    {VCORE, 		VCORE_CON0},
    {VIO18, 		VIO18_CON0},
    {VPROC, 		VPROC_CON0},
    {VRF18,	 	VRF18_CON0}
};

DCL_UINT16 pmu_ldo_bb_size;

DCL_UINT8 pmuModtoIdx[PMU_LDO_BUCK_MAX];


PMU_MOD_BASEADDR_ENTRY pmu_vpa_profile[]=
{
    {VPA,  		VPA_CON0}
};

PMU_MOD_BASEADDR_ENTRY pmu_kpled_profile[]=
{
    {KPLED,  		KPLED_CON0}
};

PMU_MOD_BASEADDR_ENTRY pmu_chr_profile[]=
{
    {CHR,  		CHR_CON0}
};

PMU_MOD_BASEADDR_ENTRY pmu_lposc_profile[] =
{
/* LPOSC */
  {LPOSC,  		 LPOSC_CON0}
};


// prarmeter table
DCL_UINT32 vcama_vosel[]=
{
	PMU_VOLT_01_500000_V,PMU_VOLT_01_800000_V,PMU_VOLT_02_500000_V,PMU_VOLT_02_800000_V
};
	
DCL_UINT32 vcamd_vosel[]=
{
	PMU_VOLT_01_300000_V,PMU_VOLT_01_500000_V,PMU_VOLT_01_800000_V,PMU_VOLT_02_500000_V,
	PMU_VOLT_02_800000_V,PMU_VOLT_03_000000_V,PMU_VOLT_03_300000_V
};

DCL_UINT32 vbt_vosel[]=
{
	PMU_VOLT_01_500000_V,PMU_VOLT_01_800000_V,PMU_VOLT_02_500000_V,PMU_VOLT_02_800000_V,
	PMU_VOLT_03_000000_V,PMU_VOLT_03_100000_V,PMU_VOLT_03_300000_V
};

DCL_UINT32 vsim_vosel[]=
{
	PMU_VOLT_01_800000_V,PMU_VOLT_03_000000_V
};


//VSIM2 , VIBR ,VMC ,VCAMD2 share the same array
DCL_UINT32 vsim2_vosel[]=
{
	PMU_VOLT_01_300000_V,PMU_VOLT_01_500000_V,PMU_VOLT_01_800000_V,PMU_VOLT_02_500000_V,
	PMU_VOLT_02_800000_V,PMU_VOLT_03_000000_V,PMU_VOLT_03_300000_V
};

DCL_UINT32 vcama2_vosel[]=
{
	PMU_VOLT_01_500000_V,PMU_VOLT_01_800000_V,PMU_VOLT_02_500000_V,PMU_VOLT_02_800000_V
};


DCL_UINT32 vcore_vosel[]=
{
      PMU_VOLT_01_200000_V, PMU_VOLT_01_225000_V, PMU_VOLT_01_250000_V, PMU_VOLT_01_275000_V,
      PMU_VOLT_01_300000_V, PMU_VOLT_01_325000_V, PMU_VOLT_01_350000_V, PMU_VOLT_01_375000_V,
      PMU_VOLT_01_375000_V, PMU_VOLT_01_375000_V, PMU_VOLT_01_375000_V, PMU_VOLT_01_375000_V,
      PMU_VOLT_01_375000_V, PMU_VOLT_01_375000_V, PMU_VOLT_01_375000_V, PMU_VOLT_01_375000_V,
      PMU_VOLT_00_800000_V, PMU_VOLT_00_825000_V, PMU_VOLT_00_850000_V, PMU_VOLT_00_875000_V,
      PMU_VOLT_00_900000_V, PMU_VOLT_00_925000_V, PMU_VOLT_00_950000_V, PMU_VOLT_00_975000_V,
      PMU_VOLT_01_000000_V, PMU_VOLT_01_025000_V, PMU_VOLT_01_050000_V, PMU_VOLT_01_075000_V,
      PMU_VOLT_01_100000_V, PMU_VOLT_01_125000_V, PMU_VOLT_01_150000_V, PMU_VOLT_01_175000_V
};

DCL_UINT32 vio18_vosel[]=
{
      PMU_VOLT_01_800000_V, PMU_VOLT_01_825000_V, PMU_VOLT_01_850000_V, PMU_VOLT_01_875000_V,
      PMU_VOLT_01_900000_V, PMU_VOLT_01_925000_V, PMU_VOLT_01_950000_V, PMU_VOLT_01_975000_V,
      PMU_VOLT_01_975000_V, PMU_VOLT_01_975000_V, PMU_VOLT_01_975000_V, PMU_VOLT_01_975000_V,
      PMU_VOLT_01_975000_V, PMU_VOLT_01_975000_V, PMU_VOLT_01_975000_V, PMU_VOLT_01_975000_V,
      PMU_VOLT_01_400000_V, PMU_VOLT_01_425000_V, PMU_VOLT_01_450000_V, PMU_VOLT_01_475000_V,
      PMU_VOLT_01_500000_V, PMU_VOLT_01_525000_V, PMU_VOLT_01_550000_V, PMU_VOLT_01_575000_V,
      PMU_VOLT_01_600000_V, PMU_VOLT_01_625000_V, PMU_VOLT_01_650000_V, PMU_VOLT_01_675000_V,
      PMU_VOLT_01_700000_V, PMU_VOLT_01_725000_V, PMU_VOLT_01_750000_V, PMU_VOLT_01_775000_V
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

DCL_UINT32 vpa_votune[]=
{
      PMU_VOLT_00_900000_V, PMU_VOLT_01_000000_V, PMU_VOLT_01_100000_V, PMU_VOLT_01_200000_V,    
      PMU_VOLT_01_300000_V, PMU_VOLT_01_400000_V, PMU_VOLT_01_500000_V, PMU_VOLT_01_600000_V,    
      PMU_VOLT_01_700000_V, PMU_VOLT_01_800000_V, PMU_VOLT_01_900000_V, PMU_VOLT_02_000000_V,    
      PMU_VOLT_02_100000_V, PMU_VOLT_02_200000_V, PMU_VOLT_02_300000_V, PMU_VOLT_02_400000_V,      
      PMU_VOLT_02_500000_V, PMU_VOLT_02_600000_V, PMU_VOLT_02_700000_V, PMU_VOLT_02_800000_V,        
      PMU_VOLT_02_900000_V, PMU_VOLT_03_000000_V, PMU_VOLT_03_100000_V, PMU_VOLT_03_200000_V,
      PMU_VOLT_03_300000_V, PMU_VOLT_03_400000_V       
};

//CHR CURRENT
DCL_UINT32 cs_vth[]=
{
	PMU_CHARGE_CURRENT_100_00_MA,PMU_CHARGE_CURRENT_200_00_MA,
	PMU_CHARGE_CURRENT_300_00_MA,PMU_CHARGE_CURRENT_400_00_MA,
	PMU_CHARGE_CURRENT_500_00_MA,PMU_CHARGE_CURRENT_600_00_MA,
	PMU_CHARGE_CURRENT_700_00_MA,PMU_CHARGE_CURRENT_800_00_MA
};

DCL_UINT16 cs_vth_reg_val[]=
{
	0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00
};
//CHR CURRENT end

DCL_UINT32 chr_wdt_td[]=
{
	PMU_CHR_WDT_TD_4SEC,PMU_CHR_WDT_TD_8SEC,PMU_CHR_WDT_TD_16SEC,PMU_CHR_WDT_TD_32SEC,
	PMU_CHR_WDT_TD_128SEC,PMU_CHR_WDT_TD_256SEC,PMU_CHR_WDT_TD_512SEC,PMU_CHR_WDT_TD_1024SEC,
	PMU_CHR_WDT_TD_3000SEC
};


DCL_UINT32 chr_hv_vth[]=
{
	PMU_VOLT_04_200000_V, PMU_VOLT_04_250000_V,PMU_VOLT_04_300000_V,PMU_VOLT_04_350000_V,
	PMU_VOLT_04_400000_V, PMU_VOLT_04_450000_V,PMU_VOLT_04_500000_V,PMU_VOLT_04_550000_V,
	PMU_VOLT_04_600000_V, PMU_VOLT_06_000000_V,PMU_VOLT_06_500000_V,PMU_VOLT_07_000000_V,
	PMU_VOLT_07_500000_V, PMU_VOLT_08_500000_V,PMU_VOLT_09_500000_V,PMU_VOLT_10_500000_V	
};

DCL_UINT32 vbat_ov_vth[]=
{
	PMU_VOLT_04_325000_V, PMU_VOLT_04_350000_V,PMU_VOLT_04_375000_V,PMU_VOLT_04_115000_V
};

PMU_PARAMETER_TABLE_ENTRY pmu_parameter_table[]=
{
	//VPA group , must put it at index 0 
	{ENC(VPA_SET_VOLTAGE,ALLMOD),					vpa_votune,			NULL,				GETARRNUM(vpa_votune)		},
	//BUCK group
	{ENC(LDO_BUCK_SET_VOLTAGE,VCORE),				vcore_vosel,		NULL,				GETARRNUM(vcore_vosel)		},
	{ENC(LDO_BUCK_SET_SLEEP_VOLTAGE,VCORE),		vcore_vosel,			NULL,				GETARRNUM(vcore_vosel)		},	
	{ENC(LDO_BUCK_SET_VOLTAGE,VIO18),				vio18_vosel,			NULL,				GETARRNUM(vio18_vosel)		},
	{ENC(LDO_BUCK_SET_SLEEP_VOLTAGE,VIO18),		vio18_vosel,			NULL,				GETARRNUM(vio18_vosel)		},	
	{ENC(LDO_BUCK_SET_VOLTAGE,VPROC),				vcore_vosel,			NULL,				GETARRNUM(vcore_vosel)		},
	{ENC(LDO_BUCK_SET_SLEEP_VOLTAGE,VPROC),		vcore_vosel,			NULL,				GETARRNUM(vcore_vosel)		},	
	{ENC(LDO_BUCK_SET_VOLTAGE,VRF18),				vio18_vosel,			NULL,				GETARRNUM(vcore_vosel)		},
	{ENC(LDO_BUCK_SET_SLEEP_VOLTAGE,VRF18),		vio18_vosel,			NULL,				GETARRNUM(vcore_vosel)		},
	//LDO group
	{ENC(LDO_BUCK_SET_VOLTAGE,VCAMA),				vcama_vosel,		NULL,				GETARRNUM(vcama_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,VCAMD),				vcamd_vosel,		NULL,				GETARRNUM(vcamd_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,VBT),				vbt_vosel,			NULL,				GETARRNUM(vbt_vosel)		},
	{ENC(LDO_BUCK_SET_VOLTAGE,VSIM),				vsim_vosel,			NULL,				GETARRNUM(vsim_vosel)		},
	{ENC(LDO_BUCK_SET_VOLTAGE,VSIM2),				vsim2_vosel,		NULL,				GETARRNUM(vsim2_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,VIBR),				vsim2_vosel,		NULL,				GETARRNUM(vsim2_vosel)	},//share vsim2
	{ENC(LDO_BUCK_SET_VOLTAGE,VMC),				vsim2_vosel,		NULL,				GETARRNUM(vsim2_vosel)	},//share vism2
	{ENC(LDO_BUCK_SET_VOLTAGE,VCAMA2),			vcama2_vosel,		NULL,				GETARRNUM(vcama2_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,VCAMD2),			vsim2_vosel,		NULL,				GETARRNUM(vsim2_vosel)	},//share vism2
	//CHR group
	{ENC(CHR_SET_HV_DETECTION_VOLTAGE,ALLMOD),	chr_hv_vth,			NULL,				GETARRNUM(chr_hv_vth)		},	
	{ENC(CHR_SET_VBAT_OV_DETECTION_VOLTAGE,ALLMOD),	vbat_ov_vth,	NULL,				GETARRNUM(vbat_ov_vth)	},		
	{ENC(CHR_SET_WDT_TIMER,ALLMOD),				chr_wdt_td,			NULL,				GETARRNUM(chr_wdt_td)		},
	{ENC(CHR_SET_CHR_CURRENT,ALLMOD),				cs_vth,				cs_vth_reg_val,		GETARRNUM(cs_vth)			},
	{ENC(CHR_SET_CV_DETECTION_VOLTAGE,ALLMOD),	chr_cv_det,			NULL,				GETARRNUM(chr_cv_det)		},
	
};

/*
E2 BASE: 0x810b_0000
PMU trimming fields:
*(BASE+0x104)[7:4]   RG_STRUP_IREF_TRIM (4b)

*(BASE+0x104)[21]         RG_VPROC_VFBADJ enable (1b)
*(BASE+0x104)[20:16]         RG_VPROC_VFBADJ (5b)

*(BASE+0x104)[22]       RG_OVP_TRIM enable (1b)
*(BASE+0x104)[3:0]   RG_OVP_TRIM (4b)

RG_VBAT_CV_VTH enable(1b)
*(BASE+0x104)[23]
*(BASE+0x100)[31:27]         RG_VBAT_CV_VTH (5b)
*/
#define EFUSE_BASE    0x810b0000
DCL_UINT8 pmu6276_cv_vth = 0;

void pmu6276_efuse_calibration(void)
{
	// E-FUSE calibration
	kal_uint32 val32;
	kal_uint16 val16;


	// 1. *(BASE+0x104)[7:4]   RG_STRUP_IREF_TRIM (4b)
	val32= PMU_DRV_ReadReg32((EFUSE_base+0x104));
	val16 = (kal_uint16)((val32 & 0x000000f0));  // [28..25]: IBIAS trim bits
	PMU_DRV_SetData16(MIX_PMU_base + 0x0214, 0x00f0, val16);	
	

	// 2. *(BASE+0x104)[21]         RG_VPROC_VFBADJ enable (1b)
	//     *(BASE+0x104)[20:16]         RG_VPROC_VFBADJ (5b)
	if (val32 & 0x00200000) // Bit28: Trim enable bit
	{
		val16 = (kal_uint16)((val32 & 0x001f0000)>>16); 
		PMU_DRV_SetData16(MIX_PMU_base + 0x0940, 0x01f0, val16<<4);
	}
	else
	{
		val16 = 7; // set proc to 1.375v
		PMU_DRV_SetData16(MIX_PMU_base + 0x0940, 0x01f0, val16<<4);	
	}


	// 3. *(BASE+0x104)[22]       RG_OVP_TRIM enable (1b)
	//	 *(BASE+0x104)[3:0]   RG_OVP_TRIM (4b)
	if (val32 & 0x00400000) // Bit28: Trim enable bit
	{
		val16 = (kal_uint16)((val32 & 0x0000000f)); 
		PMU_DRV_SetData16(MIX_PMU_base + 0x0a30, 0x00f0, val16<<4);
	}

	// 4. *(BASE+0x104)[23]              RG_VBAT_CV_VTH enable(1b)
	//     *(BASE+0x100)[31:27]         RG_VBAT_CV_VTH (5b)
	val32= PMU_DRV_ReadReg32((EFUSE_base+0x104));
	if (val32 & 0x00800000)
	{
	val32= PMU_DRV_ReadReg32((EFUSE_base+0x100));
	val16 = (kal_uint16)((val32 & 0xf8000000)>>27);  
	PMU_DRV_SetData16(MIX_PMU_base + 0x0a04, 0x001f, val16);	
	pmu6276_cv_vth=val16;
	}
	else
	{
		pmu6276_cv_vth=0x10;
	}


}


#if defined(__MT6276PMU_E1_VSIM2_VOLSEL_ISSUE__)
#define MT6276PMU_E1_VSIM2_VOLSEL_REG_ADDR       0x6115070C
#define MT6276PMU_E1_VSIM2_VOLSEL_MASK           0x0007
#define MT6276PMU_E1_VSIM2_VOLSEL_SHIFT          0
void pmu6276_vsim2_vol_sel(kal_uint8 vol_val)
{
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((MT6276PMU_E1_VSIM2_VOLSEL_REG_ADDR),
	           	MT6276PMU_E1_VSIM2_VOLSEL_MASK, ((kal_uint16)vol_val << MT6276PMU_E1_VSIM2_VOLSEL_SHIFT));
	PMU_RestoreIRQMask(savedMask);
}
#endif // #if defined(__MT6276PMU_E1_VSIM2_VOLSEL_ISSUE__)


DCL_STATUS PMU_buck_handler(DCL_CTRL_CMD cmd,DCL_CTRL_DATA_T *data)
{

		switch(cmd)
		{
			case LDO_BUCK_SET_EN:
			{
				PMU_CTRL_LDO_BUCK_SET_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetEn);
				buck_set_enable(pLdoBuckCtrl->mod,pLdoBuckCtrl->enable);
			}
			break;
			case LDO_BUCK_SET_RS:
			{
				PMU_CTRL_LDO_BUCK_SET_RS *pLdoBuckCtrl=&(data->rPMULdoBuckSetRs);
				buck_set_rs(pLdoBuckCtrl->mod,pLdoBuckCtrl->rs);
			}
			break;		
			case LDO_BUCK_SET_VOLTAGE:
			{
				PMU_CTRL_LDO_BUCK_SET_VOLTAGE *pLdoBuckCtrl=&(data->rPMULdoBuckSetVoltage);			
				buck_set_voltage(pLdoBuckCtrl->mod,pLdoBuckCtrl->voltage);
			}	
			break;
			case LDO_BUCK_SET_SLEEP_VOLTAGE:
			{
				PMU_CTRL_LDO_BUCK_SET_SLEEP_VOLTAGE *pLdoBuckCtrl=&(data->rPMULdoBuckSetSleepVoltage);	
				buck_set_sleep_voltage(pLdoBuckCtrl->mod,pLdoBuckCtrl->sleepVoltage);
			}		
			break;
			case LDO_BUCK_SET_BIAS_CURRENT_CALIBRATION_CODE:
			{
				PMU_CTRL_LDO_BUCK_SET_BIAS_CURRENT_CALIBRATION_CODE *pLdoBuckCtrl=&(data->rPMULdoBuckSetBiasCurrentCalibrationCode);
				buck_set_ical(pLdoBuckCtrl->mod,pLdoBuckCtrl->biasCurrentCalibrationCode);
			}
			break;
			case LDO_BUCK_SET_CURRENT_LIMIT:
			{
				PMU_CTRL_LDO_BUCK_SET_CURRENT_LIMIT *pLdoBuckCtrl=&(data->rPMULdoBuckSetCurrentLimit);
				buck_set_current_limit(pLdoBuckCtrl->mod,pLdoBuckCtrl->currentLimitIdx);
			}
			break;					
			case LDO_BUCK_SET_STB_TD:
			{
				PMU_CTRL_LDO_BUCK_SET_STB_TD *pLdoBuckCtrl=&(data->rPMULdoBuckSetStbTd);	
				buck_set_stb_td(pLdoBuckCtrl->mod,pLdoBuckCtrl->delayTimeIdx);
			}
			break;		
			case LDO_BUCK_SET_OC_TD:
			{	
				PMU_CTRL_LDO_BUCK_SET_OC_TD *pLdoBuckCtrl=&(data->rPMULdoBuckSetOcTd);
				buck_set_oc_td(pLdoBuckCtrl->mod,pLdoBuckCtrl->deglitchTimeIdx);
			}
			break;	
			case LDO_BUCK_SET_BURST_THRESHOLD:
			{
				PMU_CTRL_LDO_BUCK_SET_BURST_THRESHOLD *pLdoBuckCtrl=&(data->rPMULdoBuckSetBurstThreshold);
				buck_set_burst_threshold(pLdoBuckCtrl->mod,pLdoBuckCtrl->thresholdIdx);
			}
			break;	
			case LDO_BUCK_SET_OCFB_EN:
			{
				PMU_CTRL_LDO_BUCK_SET_OCFB_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetOcfbEn);
				buck_set_ocfb_enable(pLdoBuckCtrl->mod,pLdoBuckCtrl->enable);
			}					
			break;			
			default:
			return STATUS_UNSUPPORTED;
//			break;
		}

	return STATUS_OK;

}

DCL_STATUS PMU_ldo_handler(DCL_HANDLE handle,DCL_CTRL_CMD cmd,PMU_LDO_BUCK_LIST_ENUM ldo,DCL_CTRL_DATA_T *data)
{


		switch(cmd)
		{
			case LDO_BUCK_SET_EN:
			{		
				PMU_CTRL_LDO_BUCK_SET_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetEn);
#if defined(__DRV_UPMU_SHARE_LDO__)
				if ((LDO_SHARE_EN_BITMAP & M(pLdoBuckCtrl->mod))!=0)
				{
					ldoShare_set_enable(handle,pLdoBuckCtrl->mod,pLdoBuckCtrl->enable);
					//ldo_set_enable(pLdoBuckCtrl->mod, DCL_TRUE);
				}
				else
#endif //#if defined(__DRV_UPMU_SHARE_LDO__)
				{
					ldo_set_enable(pLdoBuckCtrl->mod, pLdoBuckCtrl->enable);
				}
			}
			break;
			case LDO_BUCK_SET_ON_SEL:
			{
				PMU_CTRL_LDO_BUCK_SET_ON_SEL *pLdoBuckCtrl=&(data->rPMULdoBuckSetOnSel);
				ldo_set_on_sel(pLdoBuckCtrl->mod,pLdoBuckCtrl->onSel);
				
			}
			break;			
			case LDO_BUCK_SET_VOLTAGE:
			{
				PMU_CTRL_LDO_BUCK_SET_VOLTAGE *pLdoBuckCtrl=&(data->rPMULdoBuckSetVoltage);	

				#if defined(__MT6276PMU_E1_VSIM2_VOLSEL_ISSUE__)
				if (ldo==VSIM2)
				{
					DCL_UINT16 val;
					val=PMU_Parameter_to_Value(ENC(LDO_BUCK_SET_VOLTAGE,ldo),pLdoBuckCtrl->voltage);				
					pmu6276_vsim2_vol_sel(val);	
				}
				#endif // #if defined(__MT6276PMU_E1_VSIM2_VOLSEL_ISSUE__)

				ldo_set_voltage(pLdoBuckCtrl->mod,pLdoBuckCtrl->voltage);

			}	
			break;
			case LDO_BUCK_SET_VOLTAGE_EN:
			{
				PMU_CTRL_LDO_BUCK_SET_VOLTAGE_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetVoltageEn);
				PMU_CTRL_LDO_BUCK_SET_VOLTAGE ldoBuckVoltage;
				PMU_CTRL_LDO_BUCK_SET_EN	ldoBuckEn;

				ldoBuckEn.mod=pLdoBuckCtrl->mod;
				ldoBuckEn.enable=DCL_TRUE;
				ldoBuckVoltage.mod=pLdoBuckCtrl->mod;
				ldoBuckVoltage.voltage=pLdoBuckCtrl->voltage;
				
				PMU_ldo_handler(handle,LDO_BUCK_SET_VOLTAGE,ldo,(DCL_CTRL_DATA_T *)&ldoBuckVoltage);
				PMU_ldo_handler(handle,LDO_BUCK_SET_EN,ldo,(DCL_CTRL_DATA_T *)&ldoBuckEn);
			}					
			break;
			case LDO_BUCK_SET_NDIS_EN:
			{
				PMU_CTRL_LDO_BUCK_SET_NDIS_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetNdisEn);
				ldo_set_ndis_enable(ldo,pLdoBuckCtrl->enable);			
			}					
			break;			
			case LDO_BUCK_SET_OC_AUTO_OFF:
			{
				PMU_CTRL_LDO_BUCK_SET_OC_AUTO_OFF *pLdoBuckCtrl=&(data->rPMULdoBuckSetOcAutoOff);
				ldo_set_oc_auto_off(ldo, pLdoBuckCtrl->enable);
			}					
			break;			
			case LDO_BUCK_SET_STB_EN:
			{
				PMU_CTRL_LDO_BUCK_SET_STB_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetStbEn);
				ldo_set_stb_enable(ldo,pLdoBuckCtrl->enable);
			}
			break;
			case LDO_BUCK_SET_OCFB_EN:
			{
				PMU_CTRL_LDO_BUCK_SET_OCFB_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetOcfbEn);
				ldo_set_ocfb_enable(ldo,pLdoBuckCtrl->enable);
			}					
			break;
			case LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE:
			{
				PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE *pLdoBuckCtrl=&(data->rPMULdoBuckSetVoltageCalibrationCode);
				ldo_set_voltage_calibration_code(ldo,pLdoBuckCtrl->voltageCalibrationCode);
			}					
			break;
			case LDO_BUCK_SET_STB_TD:
			{	
				PMU_CTRL_LDO_BUCK_SET_STB_TD *pLdoBuckCtrl=&(data->rPMULdoBuckSetStbTd);
				ldo_set_stb_td(ldo, pLdoBuckCtrl->delayTimeIdx);
			}					
			break;	
			case LDO_BUCK_SET_OC_TD:
			{
				PMU_CTRL_LDO_BUCK_SET_OC_TD *pLdoBuckCtrl=&(data->rPMULdoBuckSetOcTd);
				ldo_set_oc_td(ldo, pLdoBuckCtrl->deglitchTimeIdx);
			}					
			break;				
			default:
			return STATUS_UNSUPPORTED;
//			break;
		}
	return STATUS_OK;

}


void dcl_pmu6276_vpa_en(DCL_BOOL enable)
{
#if defined(MT6276_S00)
	if (enable==DCL_TRUE)
	{
		DRV_SetData(MIX_PMU_base + 0x0B04, 0x0001, (1 << 0));
		DRV_SetData(MIX_PMU_base + 0x0108, 0x080F, (0x0804));
		DRV_SetData(MIX_PMU_base + 0x0B00, 0xFFFF, (0x0309));			
	}
	else
	{
		DRV_SetData(MIX_PMU_base + 0x0B04, 0x0001, (0 << 0));
		DRV_SetData(MIX_PMU_base + 0x0108, 0x080F, (0x0004));			
	}
#endif //#if defined(MT6276_S00)

#if defined(MT6276_S01)
	vpa_set_enable(VPA,enable);

#endif //#if defined(MT6276_S01)
}

DCL_STATUS dcl_pmu6276_control_handler(DCL_HANDLE handle,DCL_CTRL_CMD cmd,DCL_CTRL_DATA_T *data)
{
	
	//ldo and buck
	if (cmd>LDO_BUCK_SET_CMDS_START && cmd <LDO_BUCK_SET_CMDS_END)
	{
		PMU_CTRL_LDO_BUCK_CTRL *pLdoBuckCtrl=&(data->rPMULdoBuckCtrl);
		PMU_LDO_BUCK_LIST_ENUM mod=pLdoBuckCtrl->mod;
		PMU_LDO_BUCK_INTERNAL_LIST_ENUM baseAddressIdx;
		
		if (mod>=PMU_LDO_BUCK_MAX)
			ASSERT(0);

		baseAddressIdx=(PMU_LDO_BUCK_INTERNAL_LIST_ENUM)pmuModtoIdx[mod];

		if (pmu_ldo_bb_profile[baseAddressIdx].modidx!=mod)
			ASSERT(0);

		if ((ISLDO(mod)))
		{
			return PMU_ldo_handler(handle,cmd,mod,data);
		}
		else
		{
			return PMU_buck_handler(cmd,data);
		}
	}


	switch(cmd)
	{
		case VPA_SET_EN:
		{
			PMU_CTRL_VPA_SET_EN *pVpaCtrl=&(data->rPMUVpaSetEn);
			 dcl_pmu6276_vpa_en(pVpaCtrl->enable);						
		}
		break;
		case VPA_SET_VOLTAGE:
		{
			PMU_CTRL_VPA_SET_VOLTAGE *pVpaCtrl=&(data->rPMUVpaSetVoltage);
			return vpa_set_votune(pVpaCtrl->vpa, pVpaCtrl->vpaIdx,pVpaCtrl->voltage);
		}
//		break;	
		case VPA_GET_VOLTAGE_LIST:
		{
			PMU_CTRL_VPA_GET_VOLTAGE_LIST *pVpaCtrl=&(data->rPMUVpaGetVoltageList);
			pVpaCtrl->pVoltageList=vpa_votune;
			pVpaCtrl->number=GETARRNUM(vpa_votune);			
		}
		break;
		case VPA_SET_FPWM:
		{
			PMU_CTRL_VPA_SET_FPWM *pVpaCtrl = &(data->rPMUVpaSetFpwm);
			if(pVpaCtrl->enable == DCL_TRUE)
			{
				PMU_DRV_SetData16(MIX_PMU_base + 0x0B04, 0x0100, 0x0100);
			}
			else
			{
				PMU_DRV_SetData16(MIX_PMU_base + 0x0B04, 0x0100, 0x0000);
			}
		}
		break;
		case KPLED_SET_EN:
		{
			PMU_CTRL_KPLED_SET_EN *pKpledCtrl=&(data->rPMUKpledSetEn);
			kpled_set_enable(KPLED, pKpledCtrl->enable);
		}
		break;
		case KPLED_SET_MODE:
		{
			PMU_CTRL_KPLED_SET_MODE *pKpledCtrl=&(data->rPMUKpledSetMode);
			kpled_set_mode(KPLED, pKpledCtrl->mode);
		}
		break;
		case KPLED_SET_SEL:
		{
			PMU_CTRL_KPLED_SET_SEL *pKpledCtrl=&(data->rPMUKpledSetSel);
			kpled_set_sel(KPLED, pKpledCtrl->sel);		
		}
		break;	
		case CHR_SET_ADC_MEASURE_EN:
		{
			PMU_CTRL_CHR_SET_ADC_MEASURE_EN *pChrCtrl=&(data->rPMUChrSetAdcMeasureEn);
			chr_set_adc_measure_enable(CHR, pChrCtrl->enable);
		}
		break;	
		case CHR_GET_IS_BATTERY_ON:
		{
			PMU_CTRL_CHR_GET_IS_BATTERY_ON *pChrCtrl=&(data->rPMUChrGetIsBatteryOn);
			pChrCtrl->enable=chr_get_is_bat_on(CHR);
		}
		break;	
		case CHR_SET_CSDAC_EN:
		{
			PMU_CTRL_CHR_SET_CSDAC_EN *pChrCtrl=&(data->rPMUChrSetCsdacEn);
			chr_set_csdac_enable(CHR, pChrCtrl->enable);
		}
		break;	
		case CHR_SET_CV_DETECTION_EN:
		{
			PMU_CTRL_CHR_SET_CV_DETECTION_EN	*pChrCtrl=&(data->rPMUChrSetCvDetectionEn);
			chr_set_vbat_cv_det_enable(CHR,pChrCtrl->enable);
		}
		break;	
		case CHR_SET_CV_DETECTION_VOLTAGE:
		{
			chr_set_vbat_cv_vth_value(CHR,pmu6276_cv_vth);
		}
		break;	
		case CHR_GET_CV_DETECTION_STATUS:
		{
			PMU_CTRL_CHR_GET_CV_DETECTION_STATUS *pChrCtrl=&(data->rPMUChrGetCvDetectionStatus); 
			pChrCtrl->enable=chr_get_is_vbat_cv_det(CHR);
		}
		break;	
		case CHR_SET_CHR_EN:
		{
			PMU_CTRL_CHR_SET_CHR_EN	*pChrCtrl=&(data->rPMUChrSetChrEn);

			chr_set_csdac_dly(CHR,3);
			chr_set_csdac_stp(CHR,0);
			chr_set_enable(CHR, pChrCtrl->enable);
		}
		break;	
		case CHR_GET_CHR_DET_STATUS:
		{
			PMU_CTRL_CHR_GET_CHR_DET_STATUS *pChrCtrl=&(data->rPMUChrGetChrDetStatus);
			pChrCtrl->enable=chr_get_is_chr_det(CHR);
		}	
		break;	
		case CHR_SET_WDT_CLEAR:
		{
			chr_set_wdt_clear(CHR);
		}
		break;	
		case CHR_SET_WDT_TIMER:
		{
			PMU_CTRL_CHR_SET_WDT_TIMER *pChrCtrl=&(data->rPMUChrSetWdtTimer);
			chr_set_wdt_td(CHR,pChrCtrl->secs);
		}
		break;	
		case CHR_SET_WDT_INT_EN:
		{
			PMU_CTRL_CHR_SET_WDT_INT_EN *pChrCtrl=&(data->rPMUChrSetWdtIntEn);
			chr_set_wdt_int_enable(CHR,pChrCtrl->enable);
		}
		break;
		case CHR_SET_WDT_EN:
		{
			PMU_CTRL_CHR_SET_WDT_EN *pChrCtrl=&(data->rPMUChrSetWdtEn);
			chr_set_wdt_enable(CHR, pChrCtrl->enable);

		}
		break;
		case CHR_GET_CHR_CURRENT:
		{
			PMU_CTRL_CHR_GET_CHR_CURRENT *pChrCtrl=&(data->rPMUChrGetChrCurrent);
			pChrCtrl->current=(PMU_CHR_CURRENT_ENUM)chr_get_cs_vth(CHR);
		}
		break;
		case CHR_SET_CHR_CURRENT:
		{
			PMU_CTRL_CHR_SET_CHR_CURRENT	*pChrCtrl=&(data->rPMUChrSetChrCurrent);
			return chr_set_cs_vth(CHR,pChrCtrl->current);
		}
//		break;	
		case CHR_GET_CHR_CURRENT_LIST:
		{
			PMU_CTRL_CHR_GET_CHR_CURRENT_LIST *pChrCtrl=&(data->rPMUChrGetChrCurrentList);
			pChrCtrl->pCurrentList=cs_vth;
			pChrCtrl->number=GETARRNUM(cs_vth);
		}
		break;		
		case CHR_SET_CV_DETECTION_VOLTAGE_CALIBRATION:
		{
			//chr_set_vbat_cv_vth_value(CHR,pmu6276_cv_vth);
		}
		break;		
		case CHR_SET_CHR_FORCE_EN:
		{

			return STATUS_UNSUPPORTED;
		}
//		break;	
		case CHR_GET_IS_CHR_VALID:
		{

			PMU_CTRL_CHR_GET_IS_CHR_VALID	*pChrCtrl=&(data->rPMUChrGetIsChrValid);
			pChrCtrl->enable=DCL_TRUE;
		}
		break;		
		case CHR_SET_HV_DETECTION_VOLTAGE:
		{

			PMU_CTRL_CHR_SET_HV_DETECTION_VOLTAGE	*pChrCtrl=&(data->rPMUChrSetHvDetectionVoltage);
			chr_set_vbat_hv_vth(CHR,pChrCtrl->voltage);
		}
		break;
		case CHR_GET_HV_DETECTION_VOLTAGE_LIST:
		{
			PMU_CTRL_CHR_GET_HV_DETECTION_VOLTAGE_LIST *pChrCtrl = &(data->rPMUChrGetHvDetectionVoltageList);
			pChrCtrl->pVoltageList = chr_hv_vth;
			pChrCtrl->number = GETARRNUM(chr_hv_vth);
		}
		break;	
		case CHR_SET_VBAT_OV_DETECTION_VOLTAGE:
		{

			PMU_CTRL_CHR_SET_VBAT_OV_DETECTION_VOLTAGE	*pChrCtrl=&(data->rPMUChrSetVbatOvDetectionVoltage);
			chr_set_vbat_ov_vth(CHR,pChrCtrl->voltage);
		}
		break;	
		case CHR_SET_BAT_HT_EN:
		{

			PMU_CTRL_CHR_SET_BAT_HT_EN	*pChrCtrl=&(data->rPMUChrSetBatHtEn);
			chr_set_baton_ht_en(CHR, pChrCtrl->enable);

		}
		break;	
		case CHR_SET_OTG_BVALID_EN:
		{

			PMU_CTRL_CHR_SET_OTG_BVALID_EN	*pChrCtrl=&(data->rPMUChrSetOtgBvalidEn);
			chr_set_otg_bvalid_en(CHR, pChrCtrl->enable);

		}
		break;			
		case CHR_SET_BC11_PULLUP_EN:
		{
			PMU_CTRL_CHR_SET_BC11_PULLUP_EN	*pChrCtrl=&(data->rPMUChrSetBc11PullupEn);

			if(pChrCtrl->enable)
			{
				chr_bc11_bb_ctrl(CHR);
				chr_bc11_vsrc_en_ctrl(CHR,VSRC_EN_ON_DPDM);
				chr_bc11_bias_enable(CHR, pChrCtrl->enable);
			}
			else
			{
				chr_bc11_bb_ctrl(CHR);
				chr_bc11_vsrc_en_ctrl(CHR,VSRC_DISABLE);
				chr_bc11_bias_enable(CHR, pChrCtrl->enable);			
			}			
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
//		break;
	}

	return STATUS_OK;
}



extern void pmu_customization_init(void);

void dcl_pmu6276_init(void)
{
	ECO_VERSION current_chip_ver = INT_ecoVersion();	
	pmu_control_handler=dcl_pmu6276_control_handler;
	pmu_parameter_size=GETARRNUM(pmu_parameter_table);
	
	pmu_ldo_bb_size=GETARRNUM(pmu_ldo_bb_profile);

	initLdoBuckMapping();

	//release keypad
	PMU_DRV_SetData16(MIX_PMU_base + 0x062C, 0x20,0); 

#if !defined(__UBL__)

	pmu6276_efuse_calibration();

	if (current_chip_ver == ECO_E2)
	{
		kal_uint32 i;
		for(i = 0; i < 6; i++)
		{
			vpa_votune[i]=PMU_VOLT_INVALID; // 0.9V~1.4V Invalid
		}
		
		// Charger
		chr_set_wdt_td(CHR, PMU_CHR_WDT_TD_32SEC);
		chr_set_wdt_int_enable(CHR, DCL_TRUE);
		chr_set_wdt_enable(CHR, DCL_TRUE);

		// BC11_RST
		PMU_DRV_SetData16(MIX_PMU_base + 0x0A24,0x0100,0x0100);
		
		// Set VCDT_HV_EN
		PMU_DRV_SetData16(MIX_PMU_base + 0x0a00, 0x0100,0x0100); 	
		
		// LDO, BUCK, BOOST
		// BUCK: VCORE
		buck_set_sleep_voltage(VCORE, PMU_VOLT_01_000000_V);
		buck_set_burst_threshold(VCORE, 2);
		buck_set_dis_antiunsh(VCORE,DCL_FALSE);
		buck_set_voltage(VCORE, PMU_VOLT_01_200000_V);
		buck_set_zx_pdn(VCORE,DCL_FALSE);		
		
		// BUCK: VAPROC
  		buck_set_dis_antiunsh(VPROC,DCL_FALSE);
		buck_set_sleep_voltage(VPROC, PMU_VOLT_01_000000_V);
  		buck_set_burst_threshold(VPROC, 2);
		//do not set VPROC voltage
		//buck_set_voltage(VPROC, PMU_VOLT_01_375000_V);		
  		buck_set_zx_pdn(VPROC,DCL_FALSE);
		
		// BUCK: VIO1V8
		buck_set_zx_pdn(VIO18,DCL_FALSE);  
		buck_set_dis_antiunsh(VIO18,DCL_FALSE);
		buck_set_sleep_voltage(VIO18, PMU_VOLT_01_800000_V);
		buck_set_burst_threshold(VIO18, 2);
		buck_set_voltage(VIO18, PMU_VOLT_01_800000_V);	
		
		// BUCK: VRF_1V8
		buck_set_zx_pdn(VRF18,DCL_FALSE);  
		buck_set_dis_antiunsh(VRF18,DCL_FALSE);	
		buck_set_burst_threshold(VRF18, 2);
		buck_set_sleep_voltage(VRF18, PMU_VOLT_01_800000_V);	
		
		// LDO: VPA			
		lposc_set_enable(LPOSC,DCL_TRUE);
		lposc_set_buckboost_enable(LPOSC,DCL_TRUE);
		//lposc_set_fd_res(LPOSC,1);
		//lposc_set_sw_mode_enable(LPOSC,DCL_TRUE);
		//lposc_set_freq(LPOSC,2);
		lposc_set_acali_enable(LPOSC,DCL_FALSE);
		lposc_set_buck_freq(LPOSC,2);
				
		//vpa_set_enable(VPA,DCL_FALSE);
		//vpa_set_antiring_enable(VPA,DCL_TRUE);
		//vpa_set_rc(VPA,2);
	
		// LDO: VRF28
		ldo_set_ocfb_enable(VRF,DCL_FALSE);
		ldo_set_oc_auto_off(VRF, DCL_FALSE);
		ldo_set_ndis_enable(VRF, DCL_TRUE);
		ldo_set_enable(VRF, DCL_FALSE);
		ldo_set_on_sel(VRF, ENABLE_LDO_BUCK_EN_REGISTER);
	
		// LDO: VTCXO , for E2 Hardware bug
		ldo_set_enable(VTCXO,DCL_TRUE);
		ldo_set_on_sel(VTCXO,ENABLE_LDO_BUCK_EN_REGISTER);
		PMU_DRV_SetData16(MIX_PMU_base + 0x0714,0x04,0);
	
		// LDO: VCAMA
		ldo_set_ocfb_enable(VCAMA,DCL_FALSE);
		ldo_set_oc_auto_off(VCAMA, DCL_FALSE);
		ldo_set_ndis_enable(VCAMA, DCL_TRUE);
		ldo_set_voltage(VCAMA, PMU_VOLT_01_800000_V);
		ldo_set_enable(VCAMA, DCL_FALSE);
	
		// LDO: VCAMD
		ldo_set_ocfb_enable(VCAMD,DCL_FALSE);
		ldo_set_oc_auto_off(VCAMD, DCL_FALSE);
		ldo_set_ndis_enable(VCAMD, DCL_TRUE);
		ldo_set_voltage(VCAMD, PMU_VOLT_01_300000_V);
		ldo_set_enable(VCAMD, DCL_FALSE);
	
		// LDO: VBT
		ldo_set_ocfb_enable(VBT,DCL_FALSE);
		ldo_set_oc_auto_off(VBT, DCL_FALSE);
		ldo_set_ndis_enable(VBT, DCL_TRUE);
		ldo_set_voltage(VBT, PMU_VOLT_03_100000_V);
		ldo_set_on_sel(VBT, ENABLE_WITH_SRCLKEN); //??
		ldo_set_enable(VBT, DCL_FALSE); //??
	
		// LDO: VSIM
		ldo_set_ocfb_enable(VSIM,DCL_FALSE);
		ldo_set_oc_auto_off(VSIM, DCL_FALSE);
		ldo_set_ndis_enable(VSIM, DCL_TRUE);
	
		// LDO: VSIM2
		ldo_set_ocfb_enable(VSIM2,DCL_FALSE);
		ldo_set_oc_auto_off(VSIM2, DCL_FALSE);
		ldo_set_ndis_enable(VSIM2, DCL_TRUE);
		ldo_set_voltage(VSIM2, PMU_VOLT_01_300000_V);
		ldo_set_enable(VSIM2, DCL_FALSE);
	
		// LDO: VIBR
		ldo_set_ocfb_enable(VIBR,DCL_FALSE);
		ldo_set_oc_auto_off(VIBR, DCL_FALSE);
		ldo_set_ndis_enable(VIBR, DCL_TRUE);
		ldo_set_voltage(VIBR, PMU_VOLT_01_300000_V);
		ldo_set_enable(VIBR, DCL_FALSE);
	
	    // LDO: VMC
		ldo_set_ocfb_enable(VMC, DCL_FALSE);
		ldo_set_oc_auto_off(VMC, DCL_FALSE);
		ldo_set_ndis_enable(VMC, DCL_TRUE);
		ldo_set_voltage(VMC, PMU_VOLT_03_300000_V);
		ldo_set_enable(VMC, DCL_TRUE);
	
	    // BUCK: VRF18
		buck_set_ocfb_enable(VRF18, DCL_FALSE);
		buck_set_oc_auto_off(VRF18, DCL_FALSE);
		buck_set_voltage(VRF18, PMU_VOLT_01_800000_V);
		buck_set_enable(VRF18, DCL_FALSE);
		buck_set_zx_pdn(VRF18,DCL_TRUE);
		buck_set_dis_antiunsh(VRF18,DCL_TRUE);		

	}
	else
	{		

		// Charger
		chr_set_wdt_td(CHR, PMU_CHR_WDT_TD_32SEC);
		chr_set_wdt_int_enable(CHR, DCL_TRUE);
		chr_set_wdt_enable(CHR, DCL_TRUE);

	    // BC11_RST
	    PMU_DRV_SetData16(MIX_PMU_base + 0x0A24,0x0100,0x0100);
	    
	    // Set VCDT_HV_EN
	    PMU_DRV_SetData16(MIX_PMU_base + 0x0a00, 0x0100,0x0100); 	

		// LDO, BUCK, BOOST
		// BUCK: VCORE
		buck_set_sleep_voltage(VCORE, PMU_VOLT_01_000000_V);
		buck_set_voltage(VCORE, PMU_VOLT_01_200000_V);
		
		// BUCK: VAPROC
		buck_set_sleep_voltage(VPROC, PMU_VOLT_01_000000_V);
		//do not set VPROC voltage
		//buck_set_voltage(VPROC, PMU_VOLT_01_375000_V);
	
		// BUCK: VIO1V8
		buck_set_sleep_voltage(VIO18, PMU_VOLT_01_800000_V);
		buck_set_voltage(VIO18, PMU_VOLT_01_800000_V);

		// BUCK: VRF_1V8
		// buck_set_sleep_voltage(VRF18, PMU_VOLT_01_800000_V);

		// LDO: VPA
		// Set VPA Channel Compenstation (RG_VPA_CC 0x8115_0B00[1:0] = 01'b)
		PMU_DRV_SetData16(0x81150B00, 0x0003,0x0001);
		lposc_set_enable(LPOSC,DCL_TRUE);
		lposc_set_buckboost_enable(LPOSC,DCL_TRUE);	
		lposc_set_sw_mode_enable(LPOSC,DCL_TRUE);		

		// LDO: VRF28
		ldo_set_ocfb_enable(VRF,DCL_FALSE);
		ldo_set_oc_auto_off(VRF, DCL_FALSE);
		ldo_set_ndis_enable(VRF, DCL_TRUE);
		ldo_set_enable(VRF, DCL_FALSE);
		ldo_set_on_sel(VRF, ENABLE_LDO_BUCK_EN_REGISTER);
	
		// LDO: VTCXO
		ldo_set_on_sel(VTCXO,ENABLE_WITH_SRCLKEN);
	
		// LDO: VCAMA
		ldo_set_ocfb_enable(VCAMA,DCL_FALSE);
		ldo_set_oc_auto_off(VCAMA, DCL_FALSE);
		ldo_set_ndis_enable(VCAMA, DCL_TRUE);
		ldo_set_voltage(VCAMA, PMU_VOLT_01_800000_V);
		ldo_set_enable(VCAMA, DCL_FALSE);
	
		// LDO: VCAMD
		ldo_set_ocfb_enable(VCAMD,DCL_FALSE);
		ldo_set_oc_auto_off(VCAMD, DCL_FALSE);
		ldo_set_ndis_enable(VCAMD, DCL_TRUE);
		ldo_set_voltage(VCAMD, PMU_VOLT_01_300000_V);
		ldo_set_enable(VCAMD, DCL_FALSE);
	
		// LDO: VBT
		ldo_set_ocfb_enable(VBT,DCL_FALSE);
		ldo_set_oc_auto_off(VBT, DCL_FALSE);
		ldo_set_ndis_enable(VBT, DCL_TRUE);
		ldo_set_voltage(VBT, PMU_VOLT_03_100000_V);
		ldo_set_on_sel(VBT, ENABLE_WITH_SRCLKEN);
		ldo_set_enable(VBT, DCL_FALSE);
	
		// LDO: VSIM
		ldo_set_ocfb_enable(VSIM,DCL_FALSE);
		ldo_set_oc_auto_off(VSIM, DCL_FALSE);
		ldo_set_ndis_enable(VSIM, DCL_TRUE);
	
		// LDO: VSIM2
		ldo_set_ocfb_enable(VSIM2,DCL_FALSE);
		ldo_set_oc_auto_off(VSIM2, DCL_FALSE);
		ldo_set_ndis_enable(VSIM2, DCL_TRUE);
		ldo_set_voltage(VSIM2, PMU_VOLT_01_300000_V);
		ldo_set_enable(VSIM2, DCL_FALSE);
	
		// LDO: VIBR
		ldo_set_ocfb_enable(VIBR,DCL_FALSE);
		ldo_set_oc_auto_off(VIBR, DCL_FALSE);
		ldo_set_ndis_enable(VIBR, DCL_TRUE);
		ldo_set_voltage(VIBR, PMU_VOLT_01_300000_V);
		ldo_set_enable(VIBR, DCL_FALSE);
	
	    // LDO: VMC
		ldo_set_ocfb_enable(VMC, DCL_FALSE);
		ldo_set_oc_auto_off(VMC, DCL_FALSE);
		ldo_set_ndis_enable(VMC, DCL_TRUE);
		ldo_set_voltage(VMC, PMU_VOLT_03_300000_V);
		ldo_set_enable(VMC, DCL_TRUE);
	
	    // BUCK: VRF18
		buck_set_ocfb_enable(VRF18, DCL_FALSE);
		buck_set_oc_auto_off(VRF18, DCL_FALSE);
		buck_set_on_sel(VRF18, ENABLE_LDO_BUCK_EN_REGISTER);
		buck_set_enable(VRF18, DCL_FALSE);
		
		// Disable Power Good Detection
		PMU_DRV_SetData16(0x81150204, 0x0008,0x0008);

		// Disable VA25 Lowe Power Mode
		PMU_DRV_SetData16(0x81150724, 0x0010,0x0010);
	} // End of if (current_chip_ver == ECO_E2)
	
	pmu_customization_init();

	
#endif //#if !defined(__UBL__)

}


#endif //#if (defined(PMIC_6276_REG_API))


