#include "reg_base.h"
#include "drv_comm.h"
#include "init.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"
 
#if (defined(PMIC_6252_REG_API))

extern PMU_CONTROL_HANDLER pmu_control_handler;
DCL_UINT16 pmu_parameter_size=0;


const PMU_MOD_BASEADDR_ENTRY pmu_ldo_bb_profile[]=
{
    {VRF28,  		VRF_CON0},
    {VTCXO,  		VTCXO_CON0},
    {VA28,  		VA_CON0},
    {VCAMA,  		VCAMA_CON0},
    {VCAMD,  		VCAMD_CON0},
    {VIO28,  		VIO_CON0},
    {VUSB,  		VUSB_CON0},
    {VSIM,  		VSIM_CON0},
    {VSIM2,  		VSIM2_CON0},
    {VRTC,  		VRTC_CON0},
    {VIBR,  		VIBR_CON0},
    {VM,  			VM_CON0},
    {VCORE,  		VCORE_CON0},
};

DCL_UINT16 pmu_ldo_bb_size;

DCL_UINT8 pmuModtoIdx[PMU_LDO_BUCK_MAX];

const PMU_FLAG_TABLE_ENTRY pmu_flags_table[]=
{
    {LDO_BUCK_EN,			LDO_BUCK_EN_OFFSET,			LDO_BUCK_EN_MASK,				LDO_BUCK_EN_SHIFT		},	
    {LDO_BUCK_VOL_SEL,		LDO_BUCK_VOL_SEL_OFFSET,		LDO_BUCK_VOL_SEL_MASK,			LDO_BUCK_VOL_SEL_SHIFT	},			
    {LDO_BUCK_RS,			LDO_BUCK_RS_OFFSET,			LDO_BUCK_RS_MASK,				LDO_BUCK_RS_SHIFT	},	
    {LDO_BUCK_OC_AUTO_OFF,	LDO_BUCK_OC_AUTO_OFF_OFFSET,	LDO_BUCK_OC_AUTO_OFF_MASK,	LDO_BUCK_OC_AUTO_OFF_SHIFT},	
    //{LDO_BUCK_STB_EN,		LDO_BUCK_STB_EN_OFFSET,		LDO_BUCK_STB_EN_MASK,			LDO_BUCK_STB_EN_SHIFT},	  
    {LDO_BUCK_ON_SEL,		LDO_BUCK_ON_SEL_OFFSET,		LDO_BUCK_ON_SEL_MASK,			LDO_BUCK_ON_SEL_SHIFT},	  
    {LDO_BUCK_NDIS_EN,		LDO_BUCK_NDIS_EN_OFFSET,		LDO_BUCK_NDIS_EN_MASK,			LDO_BUCK_NDIS_EN_SHIFT},	   
    //{LDO_BUCK_OCFB_EN,		LDO_BUCK_OCFB_EN_OFFSET,		LDO_BUCK_OCFB_EN_MASK,		LDO_BUCK_OCFB_EN_SHIFT	},   
    {LDO_CAL,					LDO_CAL_OFFSET,					LDO_CAL_MASK,					LDO_CAL_SHIFT},
    {LDO_STB_TD,				LDO_STB_TD_OFFSET,				LDO_STB_TD_MASK,				LDO_STB_TD_SHIFT},    
    {LDO_OC_TD,				LDO_OC_TD_OFFSET,				LDO_OC_TD_MASK,				LDO_OC_TD_SHIFT}, 
    {BUCK_VFBADJ_SLEEP,		BUCK_VFBADJ_SLEEP_OFFSET,		BUCK_VFBADJ_SLEEP_MASK	,		BUCK_VFBADJ_SLEEP_SHIFT},
    {BUCK_ICAL_EN,			BUCK_ICAL_EN_OFFSET,			BUCK_ICAL_EN_MASK,				BUCK_ICAL_EN_SHIFT},
   // {BUCK_CSL,				BUCK_CSL_OFFSET,				BUCK_CSL_MASK	,				BUCK_CSL_SHIFT},      
   // {BUCK_STB_TD,			BUCK_STB_TD_OFFSET,			BUCK_STB_TD_MASK,				BUCK_STB_TD_SHIFT},
   // {BUCK_OC_THD,			BUCK_OC_THD_OFFSET,			BUCK_OC_THD_MASK,				BUCK_OC_THD_SHIFT},
   // {BUCK_BURST,				BUCK_BURST_OFFSET,				BUCK_BURST_MASK,				BUCK_BURST_SHIFT},  
    {SPK_EN,					SPK_EN_OFFSET,					SPK_EN_MASK	,				SPK_EN_SHIFT},      
    {SPK_OC_EN,				SPK_OC_EN_OFFSET,				SPK_OC_EN_MASK	,				SPK_OC_EN_SHIFT},   
    {SPK_OC_THD,				SPK_OC_THD_OFFSET,				SPK_OC_THD_MASK	,			SPK_OC_THD_SHIFT},       
    {SPK_OC_WND,				SPK_OC_WND_OFFSET,				SPK_OC_WND_MASK	,			SPK_OC_WND_SHIFT},   
    {SPK_VOL,					SPK_VOL_OFFSET,					SPK_VOL_MASK,					SPK_VOL_SHIFT},     
    {ISINK_EN,					ISINK_EN_OFFSET,					ISINK_EN_MASK,					ISINK_EN_SHIFT},         
    {ISINK_MODE,				ISINK_MODE_OFFSET,				ISINK_MODE_MASK,				ISINK_MODE_SHIFT},       
    {ISINK_STEP,				ISINK_STEP_OFFSET,				ISINK_STEP_MASK,				ISINK_STEP_SHIFT},       
    {ISINK_VREF_CAL,			ISINK_VREF_CAL_OFFSET,			ISINK_VREF_CAL_MASK,			ISINK_VREF_CAL_SHIFT},      
   // {BOOST_TYPE,				BOOST_TYPE_OFFSET,				BOOST_TYPE_MASK,				BOOST_TYPE_SHIFT},       
   // {BOOST_HW_SEL,			BOOST_HW_SEL_OFFSET,			BOOST_HW_SEL_MASK,				BOOST_HW_SEL_SHIFT},      
    {KPLED_EN,				KPLED_EN_OFFSET,				KPLED_EN_MASK,					KPLED_EN_SHIFT},      
    {KPLED_MODE,				KPLED_MODE_OFFSET,				KPLED_MODE_MASK,				KPLED_MODE_SHIFT},       
    {KPLED_SEL,				KPLED_SEL_OFFSET,				KPLED_SEL_MASK,					KPLED_SEL_SHIFT},   
    {ADC_EN,					ADC_EN_OFFSET,					ADC_EN_MASK,					ADC_EN_SHIFT},    
    {BATON_UNDET,			BATON_UNDET_OFFSET,			BATON_UNDET_MASK,				BATON_UNDET_SHIFT},  
    {CSDAC_EN,				CSDAC_EN_OFFSET,				CSDAC_EN_MASK,					CSDAC_EN_SHIFT},  
    {VBAT_CV_DET,			VBAT_CV_DET_OFFSET,				VBAT_CV_DET_MASK,				VBAT_CV_DET_SHIFT},   
    {VBAT_CV_EN,				VBAT_CV_EN_OFFSET,				VBAT_CV_EN_MASK,				VBAT_CV_EN_SHIFT},  
    {VBAT_CV_VTH,			VBAT_CV_VTH_OFFSET,				VBAT_CV_VTH_MASK,				VBAT_CV_VTH_SHIFT},   
    {CSDAC_DLY,				CSDAC_DLY_OFFSET,				CSDAC_DLY_MASK,				CSDAC_DLY_SHIFT},     
    {CSDAC_STP,				CSDAC_STP_OFFSET,				CSDAC_STP_MASK,				CSDAC_STP_SHIFT},   
    {CHR_EN,					CHR_EN_OFFSET,					CHR_EN_MASK,					CHR_EN_SHIFT},     
    {CHRDET,					CHRDET_OFFSET,					CHRDET_MASK,					CHRDET_SHIFT},   
    {CHRWDT_TD,				CHRWDT_TD_OFFSET,				CHRWDT_TD_MASK,				CHRWDT_TD_SHIFT},      
    {CS_VTH,					CS_VTH_OFFSET,					CS_VTH_MASK,					CS_VTH_SHIFT},    
    {CHRWDT_EN,				CHRWDT_EN_OFFSET,				CHRWDT_EN_MASK,				CHRWDT_EN_SHIFT},    
    {CHRWDT_INT_EN,			CHRWDT_INT_EN_OFFSET,			CHRWDT_INT_EN_MASK,			CHRWDT_INT_EN_SHIFT},    
    {VCDT_HV_VTH,			VCDT_HV_VTH_OFFSET,			VCDT_HV_VTH_MASK,				VCDT_HV_VTH_SHIFT},  
    {BATON_HT_EN,				BATON_HT_EN_OFFSET,				BATON_HT_EN_MASK,				BATON_HT_EN_SHIFT},  
    {OTG_BVALID_EN,			OTG_BVALID_EN_OFFSET,			OTG_BVALID_EN_MASK,			OTG_BVALID_EN_SHIFT},    
    {USBDL_EN,				USBDL_EN_OFFSET,				USBDL_EN_MASK,					USBDL_EN_SHIFT},      
    {CCI_SRCLKEN,				CCI_SRCLKEN_OFFSET,				CCI_SRCLKEN_MASK,				CCI_SRCLKEN_SHIFT},  
    {VCDT_HV_EN,				VCDT_HV_EN_OFFSET,				VCDT_HV_EN_MASK,				VCDT_HV_EN_SHIFT},         
   // {BOOST_CKS_PRG,			BOOST_CKS_PRG_OFFSET,			BOOST_CKS_PRG_MASK,			BOOST_CKS_PRG_SHIFT},    
    {BC11_VREF_VTH,			BC11_VREF_VTH_OFFSET,			BC11_VREF_VTH_MASK,			BC11_VREF_VTH_SHIFT},      
    {BC11_CMP_EN,			BC11_CMP_EN_OFFSET,				BC11_CMP_EN_MASK,				BC11_CMP_EN_SHIFT},      
    {BC11_IPD_EN,				BC11_IPD_EN_OFFSET,				BC11_IPD_EN_MASK,				BC11_IPD_EN_SHIFT},      
    {BC11_IPU_EN,				BC11_IPU_EN_OFFSET,				BC11_IPU_EN_MASK,				BC11_IPU_EN_SHIFT},      
    {BC11_BIAS_EN,			BC11_BIAS_EN_OFFSET,			BC11_BIAS_EN_MASK,				BC11_BIAS_EN_SHIFT},      
    {BC11_BB_CTRL,			BC11_BB_CTRL_OFFSET,			BC11_BB_CTRL_MASK,				BC11_BB_CTRL_SHIFT},    
    {BC11_RST,				BC11_RST_OFFSET,				BC11_RST_MASK,					BC11_RST_SHIFT},    
    {BC11_VSRC_EN,			BC11_VSRC_EN_OFFSET,			BC11_VSRC_EN_MASK,				BC11_VSRC_EN_SHIFT},        
    {BC11_CMP_OUT,			BC11_CMP_OUT_OFFSET,			BC11_CMP_OUT_MASK,				BC11_CMP_OUT_SHIFT},     
};

/*
PMU_MOD_BASEADDR_ENTRY pmu_strup_profile[] =
{
	{STRUP,		STRUP_CON0}
};

PMU_MOD_BASEADDR_ENTRY pmu_spk_profile[]=
{
	{SPK,		SPK_CON0}
};

PMU_MOD_BASEADDR_ENTRY pmu_kpled_profile[]=
{
    {KPLED,  		KPLED_CON0}
};
*/

const PMU_MOD_BASEADDR_ENTRY pmu_chr_profile[]=
{
    {CHR,  		CHR_CON0}
};


const PMU_MOD_BASEADDR_ENTRY pmu_isink_profile[]=
{
	{ISINK0,		ISINK0_CON0},
	{ISINK1,		ISINK1_CON0},
	{ISINK2,		ISINK2_CON0},	
	{ISINK3,		ISINK3_CON0}	
};

DCL_STATUS pmu_set_ldo_buck(PMU_LDO_BUCK_LIST_ENUM mod,PMU_FLAGS_LIST_ENUM flagname,DCL_UINT32 val)
{
		DCL_UINT8 baseAddressIdx;
		const PMU_MOD_BASEADDR_ENTRY *pEntry;
		
		if (mod>=PMU_LDO_BUCK_MAX)
			ASSERT(0);

		baseAddressIdx=pmuModtoIdx[mod];

		pEntry=&pmu_ldo_bb_profile[baseAddressIdx];

		if (pEntry->modidx!=mod)
			ASSERT(0);

		return pmu_set_register_value(pEntry->addr,flagname,val);
}

DCL_STATUS pmu_set_spk(PMU_FLAGS_LIST_ENUM flagname,DCL_UINT32 val)
{
		return pmu_set_register_value(SPK_CON0,flagname,val);
}

DCL_STATUS pmu_set_isink(PMU_ISINK_LIST_ENUM isink,PMU_FLAGS_LIST_ENUM flagname,DCL_UINT32 val)
{
		return pmu_set_register_value(pmu_isink_profile[isink].addr,flagname,val);
}

DCL_STATUS pmu_set_kpled(PMU_FLAGS_LIST_ENUM flagname,DCL_UINT32 val)
{
		return pmu_set_register_value(KPLED_CON0,flagname,val);
}

DCL_STATUS pmu_set_chr(PMU_FLAGS_LIST_ENUM flagname,DCL_UINT32 val)
{
		return pmu_set_register_value(CHR_CON0,flagname,val);
}

DCL_UINT16 pmu_get_chr(PMU_FLAGS_LIST_ENUM flagname)
{
		return pmu_get_register_value(CHR_CON0,flagname);
}

void pmu_set_chr_wdt_clear(PMU_CHR_LIST_ENUM chr)
{
	DCL_UINT16 val;
	DCL_UINT32 savedMask;

	// 1. If CHRWDT_OUT(CON7[15]) flag is NOT set
	//    ==> Just write CON6 to reset WDT (Charger MACRO)
	// 2. If CHRWDT_OUT(CON7[15]) flag is set
	//    ==> Write CON6 to reset WDT (Charger MACRO)
	//    ==> Polling CHRWDT_OUT(CON7[15]) until the bit from 1 to 0
	//    ==> Write CHRWDT_FLAG(CON7[1]) (Reset WDT flag in MixedSYS)

	// To reset Charger WDT counter (Charger MACRO), WRITE any bit of "CHR_CON6"
	savedMask = PMU_SaveAndSetIRQMask();
	val = PMU_DRV_ReadReg16((CHR_CON0+CON6_OFFSET));
	PMU_DRV_WriteReg16((CHR_CON0+CON6_OFFSET), val);
	PMU_RestoreIRQMask(savedMask);

	// The polling in 36, 76E1, 55E1, 51E1, 53EL E1 should be ~2ms (50% error ratio)
	// After MACRO modification, it will be 2us
	while (1)
	{
		val = PMU_DRV_ReadReg16((CHR_CON0+CON7_OFFSET));
		if (CHRWDT_OUT_MASK & val)
		{
			;
		}
		else
		{
			break;
		}

	}

	// Clear MixedSYS WDT flag
	savedMask = PMU_SaveAndSetIRQMask();
	val = PMU_DRV_ReadReg16((CHR_CON0+CON7_OFFSET));
	val |= CHRWDT_FLAG_WR_MASK;
	PMU_DRV_WriteReg16((CHR_CON0+CON7_OFFSET), val);
	PMU_RestoreIRQMask(savedMask);
}



// prarmeter table

const DCL_UINT32 vcama_vosel[]=
{
	PMU_VOLT_01_500000_V,PMU_VOLT_01_800000_V,PMU_VOLT_02_500000_V,PMU_VOLT_02_800000_V
};
	
const DCL_UINT32 vcamd_vosel[]=
{
	PMU_VOLT_01_300000_V,PMU_VOLT_01_500000_V,PMU_VOLT_01_800000_V,PMU_VOLT_02_500000_V,
	PMU_VOLT_02_800000_V,PMU_VOLT_03_000000_V,PMU_VOLT_03_300000_V
};

const DCL_UINT32 vbt_vosel[]=
{
	PMU_VOLT_01_300000_V,PMU_VOLT_01_500000_V,PMU_VOLT_01_800000_V,PMU_VOLT_02_500000_V,
	PMU_VOLT_02_800000_V,PMU_VOLT_03_000000_V,PMU_VOLT_03_300000_V
};


const DCL_UINT32 vsim_vosel[]=
{
	PMU_VOLT_01_800000_V,PMU_VOLT_03_000000_V
};

const DCL_UINT32 vsim2_vosel[]=
{
	PMU_VOLT_01_300000_V,PMU_VOLT_01_500000_V,PMU_VOLT_01_800000_V,PMU_VOLT_02_500000_V,
	PMU_VOLT_02_800000_V,PMU_VOLT_03_000000_V,PMU_VOLT_03_300000_V
};

const DCL_UINT32 vcore_vosel[]=
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


const DCL_UINT32 chr_cv_det[]=
{
      PMU_VOLT_04_000000_V, PMU_VOLT_04_012500_V, PMU_VOLT_04_025000_V, PMU_VOLT_04_037500_V,
      PMU_VOLT_04_050000_V, PMU_VOLT_04_062500_V, PMU_VOLT_04_075000_V, PMU_VOLT_04_087500_V,
      PMU_VOLT_04_100000_V, PMU_VOLT_04_112500_V, PMU_VOLT_04_125000_V, PMU_VOLT_04_137500_V,
      PMU_VOLT_04_150000_V, PMU_VOLT_04_162500_V, PMU_VOLT_04_175000_V, PMU_VOLT_04_187500_V,
      PMU_VOLT_04_200000_V, PMU_VOLT_04_212500_V, PMU_VOLT_04_225000_V, PMU_VOLT_04_237500_V,   
      PMU_VOLT_04_250000_V, PMU_VOLT_04_262500_V, PMU_VOLT_04_275000_V, PMU_VOLT_04_287500_V         
};

const DCL_UINT32 vpa_votune[]=
{
      PMU_VOLT_00_900000_V, PMU_VOLT_01_000000_V, PMU_VOLT_01_100000_V, PMU_VOLT_01_200000_V,    
      PMU_VOLT_01_300000_V, PMU_VOLT_01_400000_V, PMU_VOLT_01_500000_V, PMU_VOLT_01_600000_V,    
      PMU_VOLT_01_700000_V, PMU_VOLT_01_800000_V, PMU_VOLT_01_900000_V, PMU_VOLT_02_200000_V,    
      PMU_VOLT_02_100000_V, PMU_VOLT_02_200000_V, PMU_VOLT_02_300000_V, PMU_VOLT_02_400000_V,      
      PMU_VOLT_02_500000_V, PMU_VOLT_02_600000_V, PMU_VOLT_02_700000_V, PMU_VOLT_02_800000_V,        
      PMU_VOLT_02_900000_V, PMU_VOLT_03_000000_V, PMU_VOLT_03_100000_V, PMU_VOLT_03_200000_V,
      PMU_VOLT_03_300000_V, PMU_VOLT_03_400000_V       
};

//CHR CURRENT
const DCL_UINT32 cs_vth[]=
{
	PMU_CHARGE_CURRENT_100_00_MA,PMU_CHARGE_CURRENT_200_00_MA,
	PMU_CHARGE_CURRENT_300_00_MA,PMU_CHARGE_CURRENT_400_00_MA,
	PMU_CHARGE_CURRENT_500_00_MA,PMU_CHARGE_CURRENT_600_00_MA,
	PMU_CHARGE_CURRENT_700_00_MA,PMU_CHARGE_CURRENT_800_00_MA
};

const DCL_UINT16 cs_vth_reg_val[]=
{
	0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00
};
//CHR CURRENT end

const DCL_UINT32 spk_vol[]=
{
	PMIC_SPK_VOL_00_00_dB,PMIC_SPK_VOL_01_50_dB,PMIC_SPK_VOL_03_00_dB,PMIC_SPK_VOL_04_50_dB,
	PMIC_SPK_VOL_06_00_dB,PMIC_SPK_VOL_07_50_dB,PMIC_SPK_VOL_09_00_dB,PMIC_SPK_VOL_10_50_dB,	
	PMIC_SPK_VOL_12_00_dB,PMIC_SPK_VOL_13_50_dB,PMIC_SPK_VOL_15_00_dB,PMIC_SPK_VOL_16_50_dB,	
	PMIC_SPK_VOL_18_00_dB,PMIC_SPK_VOL_19_50_dB,PMIC_SPK_VOL_21_00_dB,PMIC_SPK_VOL_22_50_dB,		
};

const DCL_UINT32 chr_wdt_td[]=
{
	PMU_CHR_WDT_TD_4SEC,PMU_CHR_WDT_TD_8SEC,PMU_CHR_WDT_TD_16SEC,PMU_CHR_WDT_TD_32SEC
};

const DCL_UINT32 isink_step[]=
{
	ISINK_STEP_04_MA,ISINK_STEP_08_MA,ISINK_STEP_12_MA,ISINK_STEP_16_MA,ISINK_STEP_20_MA,ISINK_STEP_24_MA
};

const DCL_UINT32 chr_hv_vth[]=
{
	PMU_VOLT_04_200000_V, PMU_VOLT_04_250000_V,PMU_VOLT_04_300000_V,PMU_VOLT_04_350000_V,
	PMU_VOLT_04_400000_V, PMU_VOLT_04_450000_V,PMU_VOLT_04_500000_V,PMU_VOLT_04_550000_V,
	PMU_VOLT_04_600000_V, PMU_VOLT_06_000000_V,PMU_VOLT_06_500000_V,PMU_VOLT_07_000000_V,
	PMU_VOLT_07_500000_V, PMU_VOLT_08_500000_V,PMU_VOLT_09_500000_V,PMU_VOLT_10_500000_V	
};

const PMU_PARAMETER_TABLE_ENTRY pmu_parameter_table[]=
{
	//LDO group
	{ENC(LDO_BUCK_SET_VOLTAGE,VCAMA),				vcama_vosel,		NULL,				GETARRNUM(vcama_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,VCAMD),				vcamd_vosel,		NULL,				GETARRNUM(vcamd_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,VSIM),				vsim_vosel,		NULL,				GETARRNUM(vsim_vosel)		},
	{ENC(LDO_BUCK_SET_VOLTAGE,VSIM2),				vsim2_vosel,	NULL,				GETARRNUM(vsim2_vosel)	},	
	{ENC(LDO_BUCK_SET_VOLTAGE,VIBR),				vsim2_vosel,	NULL,				GETARRNUM(vsim2_vosel)	},//share vsim2	
	//BUCK group
	{ENC(LDO_BUCK_SET_VOLTAGE,VCORE),				vcore_vosel,		NULL,				GETARRNUM(vcore_vosel)		},
	{ENC(LDO_BUCK_SET_SLEEP_VOLTAGE,VCORE),		vcore_vosel,		NULL,				GETARRNUM(vcore_vosel)		},
	//CHR
	{ENC(CHR_SET_HV_DETECTION_VOLTAGE,ALLMOD),	chr_hv_vth,			NULL,				GETARRNUM(chr_hv_vth)		},	
	{ENC(CHR_SET_CHR_CURRENT,ALLMOD),				cs_vth,				cs_vth_reg_val,		GETARRNUM(cs_vth)			},
	{ENC(CHR_SET_CV_DETECTION_VOLTAGE,ALLMOD),	chr_cv_det,			NULL,				GETARRNUM(chr_cv_det)		},
	{ENC(CHR_SET_WDT_TIMER,ALLMOD),				chr_wdt_td,		NULL,				GETARRNUM(chr_wdt_td)		},	
	//ISINK
	{ENC(ISINK_SET_STEP,ALLMOD),					isink_step,		NULL,				GETARRNUM(isink_step)		},	
	//SPK
	{ENC(SPK_SET_VOL,SPK),							spk_vol,			NULL,				GETARRNUM(spk_vol)		}
};

const PMU_VOLTAGE_ENUM voltage_calibration_idx[]=
{PMU_VOLT_03_300000_V,PMU_VOLT_03_000000_V,PMU_VOLT_02_900000_V
 ,PMU_VOLT_02_800000_V,PMU_VOLT_02_500000_V,PMU_VOLT_01_800000_V
 ,PMU_VOLT_01_500000_V,PMU_VOLT_01_300000_V};

const DCL_UINT8 voltage_calibration_tab[8][24]=
{
// 3.3v
       { 0, 0,  7,  7, 6,  6, 5,  5,  4,  4, 3,  3,  2,  2, 1, 1, 0, 0,15,15,14,14,13,13},
// 3.0v
	{ 7, 7,  7,  6, 6, 5,  5,  4,  4,  3,  3, 2,  2,  1,  1,  1, 0, 0,15,15,14,14,13,13},
// 2.9v
	{ 7, 7,  6,  6,  5, 5, 5,  4,  4,  3,  3,  2, 2, 1, 1, 1, 0, 0, 15, 15, 14, 14, 13, 13},
// 2.8v	
	{ 7, 6,  6,  6,  5,  5, 4, 4, 4, 3, 3, 2, 2, 1, 1,0, 0, 0,15, 15, 14, 14, 14, 13}, 
// 2.5v
	{ 6, 6,  5,  5,  5,  4, 4, 3, 3, 3, 2, 2, 2, 1, 1,0, 0, 0,15, 15, 15, 14, 14, 13}, 
// 1.8v
	{ 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0,15,15,15,14,14},
// 1.5v
	{ 4, 3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0,15,15,15,15,14}, 
// 1.3v
	{ 3 , 3, 3, 3, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,15,15,15,15,15}
};
DCL_UINT8 voltage_calibration_size;

DCL_BOOL pmu_calibration_enable=DCL_FALSE;
DCL_UINT8 pmu_calibration_cv_val = 0;
DCL_UINT8 pmu6252_ovp_val = 0;

DCL_UINT8 pmu6252_ldo_cal(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT32 vol);

void pmu_6252_bl_enable(DCL_BOOL enable);

DCL_BOOL pmu6252_cust_isink_en[PMU_ISINK_MAX];

DCL_STATUS dcl_pmu6252_control_handler(DCL_HANDLE handle,DCL_CTRL_CMD cmd,DCL_CTRL_DATA_T *data)
{

	DCL_UINT16 val;
	
	//ldo and buck
	if (cmd>LDO_BUCK_SET_CMDS_START && cmd <LDO_BUCK_SET_CMDS_END)
	{
		
		PMU_CTRL_LDO_BUCK_CTRL *pLdoBuckCtrl=&(data->rPMULdoBuckCtrl);
		PMU_LDO_BUCK_LIST_ENUM mod=pLdoBuckCtrl->mod;

		switch(cmd)
		{

			case LDO_BUCK_SET_EN:
			{
				PMU_CTRL_LDO_BUCK_SET_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetEn);
				pmu_set_ldo_buck(mod,LDO_BUCK_EN,pLdoBuckCtrl->enable);			
			}
			break;	
			case LDO_BUCK_SET_ON_SEL:
			{
				PMU_CTRL_LDO_BUCK_SET_ON_SEL *pLdoBuckCtrl=&(data->rPMULdoBuckSetOnSel);
				pmu_set_ldo_buck(mod,LDO_BUCK_ON_SEL,pLdoBuckCtrl->onSel);
				
			}
			break;			
			case LDO_BUCK_SET_VOLTAGE:
			{
				PMU_CTRL_LDO_BUCK_SET_VOLTAGE *pLdoBuckCtrl=&(data->rPMULdoBuckSetVoltage);
				val=PMU_Parameter_to_Value(ENC(LDO_BUCK_SET_VOLTAGE,mod),pLdoBuckCtrl->voltage);

				if (val==PARAMETER_UNKNOWN)
					return STATUS_UNSUPPORTED;				
				pmu_set_ldo_buck(mod,LDO_BUCK_VOL_SEL,val);
				
				pmu6252_ldo_cal(pLdoBuckCtrl->mod,pLdoBuckCtrl->voltage);

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
				
				dcl_pmu6252_control_handler(handle,LDO_BUCK_SET_VOLTAGE,(DCL_CTRL_DATA_T *)&ldoBuckVoltage);
				dcl_pmu6252_control_handler(handle,LDO_BUCK_SET_EN,(DCL_CTRL_DATA_T *)&ldoBuckEn);
			}					
			break;
			case LDO_BUCK_SET_NDIS_EN:
			{
				PMU_CTRL_LDO_BUCK_SET_NDIS_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetNdisEn);
				pmu_set_ldo_buck(mod,LDO_BUCK_NDIS_EN,pLdoBuckCtrl->enable);
			}					
			break;			
			case LDO_BUCK_SET_OC_AUTO_OFF:
			{
				PMU_CTRL_LDO_BUCK_SET_OC_AUTO_OFF *pLdoBuckCtrl=&(data->rPMULdoBuckSetOcAutoOff);
				pmu_set_ldo_buck(mod,LDO_BUCK_OC_AUTO_OFF,pLdoBuckCtrl->enable);
			}					
			break;			
			/*
			case LDO_BUCK_SET_STB_EN:
			{
				PMU_CTRL_LDO_BUCK_SET_STB_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetStbEn);
				pmu_set_ldo_buck(mod,LDO_BUCK_STB_EN,pLdoBuckCtrl->enable);	
			}
			break;

			case LDO_BUCK_SET_OCFB_EN:
			{
				PMU_CTRL_LDO_BUCK_SET_OCFB_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetOcfbEn);
				pmu_set_ldo_buck(mod,LDO_BUCK_OCFB_EN,pLdoBuckCtrl->enable);	
			}					
			break;
			*/
			case LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE:
			{
				PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE *pLdoBuckCtrl=&(data->rPMULdoBuckSetVoltageCalibrationCode);
				pmu_set_ldo_buck(mod,LDO_CAL,pLdoBuckCtrl->voltageCalibrationCode);	
			}					
			break;
			case LDO_BUCK_SET_STB_TD:
			{	
				PMU_CTRL_LDO_BUCK_SET_STB_TD *pLdoBuckCtrl=&(data->rPMULdoBuckSetStbTd);
				if (ISLDO(mod))
				{
					pmu_set_ldo_buck(mod,LDO_STB_TD,pLdoBuckCtrl->delayTimeIdx);	
				}
				else
				{return STATUS_UNSUPPORTED;}	
			}					
			break;	
			case LDO_BUCK_SET_OC_TD:
			{
				PMU_CTRL_LDO_BUCK_SET_OC_TD *pLdoBuckCtrl=&(data->rPMULdoBuckSetOcTd);
				if (ISLDO(mod))
				{				
					pmu_set_ldo_buck(mod,LDO_OC_TD,pLdoBuckCtrl->deglitchTimeIdx);
				}
				else
				{return STATUS_UNSUPPORTED;}					
			}					
			break;		
			case LDO_BUCK_SET_SLEEP_VOLTAGE:
			{
				if (ISLDO(mod))
				{return STATUS_UNSUPPORTED;}	
				else
				{						
					PMU_CTRL_LDO_BUCK_SET_SLEEP_VOLTAGE *pLdoBuckCtrl=&(data->rPMULdoBuckSetSleepVoltage);	
					val=PMU_Parameter_to_Value(ENC(LDO_BUCK_SET_SLEEP_VOLTAGE,mod),pLdoBuckCtrl->sleepVoltage);

					if (val==PARAMETER_UNKNOWN)
						return STATUS_UNSUPPORTED;	
					pmu_set_ldo_buck(mod,BUCK_VFBADJ_SLEEP,val);
				}					
				
			}		
			break;
			case LDO_BUCK_SET_BIAS_CURRENT_CALIBRATION_CODE:
			{
				PMU_CTRL_LDO_BUCK_SET_BIAS_CURRENT_CALIBRATION_CODE *pLdoBuckCtrl=&(data->rPMULdoBuckSetBiasCurrentCalibrationCode);
				pmu_set_ldo_buck(mod,BUCK_ICAL_EN,pLdoBuckCtrl->biasCurrentCalibrationCode);
			}
			break;
			/*
			case LDO_BUCK_SET_CURRENT_LIMIT:
			{
				PMU_CTRL_LDO_BUCK_SET_CURRENT_LIMIT *pLdoBuckCtrl=&(data->rPMULdoBuckSetCurrentLimit);
				pmu_set_ldo_buck(mod,BUCK_CSL,pLdoBuckCtrl->currentLimitIdx);
			}
			break;					
			case LDO_BUCK_SET_BURST_THRESHOLD:
			{
				PMU_CTRL_LDO_BUCK_SET_BURST_THRESHOLD *pLdoBuckCtrl=&(data->rPMULdoBuckSetBurstThreshold);
				pmu_set_ldo_buck(mod,BUCK_BURST,pLdoBuckCtrl->thresholdIdx);
			}
			break;
			*/
			default:
			return STATUS_UNSUPPORTED;			
		}


	}

	switch(cmd)
	{
		case SPK_SET_EN:
		{
			PMU_CTRL_SPK_SET_EN *pSpkCtrl=&(data->rPMUSpkSetEn);
			pmu_set_spk(SPK_EN, pSpkCtrl->enable);
		}
		break;
		case SPK_SET_VOL: 
		{
			PMU_CTRL_SPK_SET_VOL *pSpkCtrl=&(data->rPMUSpkSetVol);
			val=PMU_Parameter_to_Value(ENC(SPK_SET_VOL,SPK),pSpkCtrl->dbm);

			if (val==PARAMETER_UNKNOWN)
				return STATUS_UNSUPPORTED;

			pmu_set_spk(SPK_VOL,val);
			
		}			
		break;
		case BL_SET_EN:
		{
			PMU_CTRL_BL_SET_EN *pBlCtrl=&(data->rPMUBlSetEn);
			pmu_6252_bl_enable(pBlCtrl->enable);
		}
		break;
		case ISINK_SET_EN:
		{
			PMU_CTRL_ISINK_SET_EN *pIsinkCtrl=&(data->rPMUIsinkSetEn);
			if (pIsinkCtrl->isink <PMU_ISINK_MAX)
				pmu6252_cust_isink_en[pIsinkCtrl->isink]=pIsinkCtrl->enable;
		}
		break;
		case ISINK_SET_STEP:
		{
			PMU_CTRL_ISINK_SET_STEP *pIsinkCtrl=&(data->rPMUIsinkSetStep);
			val=PMU_Parameter_to_Value(ENC(ISINK_SET_STEP,ALLMOD),pIsinkCtrl->step);

			if (val==PARAMETER_UNKNOWN)
				return STATUS_UNSUPPORTED;	
			
			pmu_set_isink(pIsinkCtrl->isink,ISINK_STEP,val);
		}
		break;		
		case KPLED_SET_EN:
		{
			PMU_CTRL_KPLED_SET_EN *pKpledCtrl=&(data->rPMUKpledSetEn);
			pmu_set_kpled(KPLED_EN, pKpledCtrl->enable);
		}
		break;
		case KPLED_SET_MODE:
		{
			PMU_CTRL_KPLED_SET_MODE *pKpledCtrl=&(data->rPMUKpledSetMode);
			pmu_set_kpled(KPLED_MODE, pKpledCtrl->mode);
		}
		break;
		case KPLED_SET_SEL:
		{
			PMU_CTRL_KPLED_SET_SEL *pKpledCtrl=&(data->rPMUKpledSetSel);
			pmu_set_kpled(KPLED_SEL, pKpledCtrl->sel);			
		}
		break;			
		case CHR_SET_ADC_MEASURE_EN:
		{
			PMU_CTRL_CHR_SET_ADC_MEASURE_EN *pChrCtrl=&(data->rPMUChrSetAdcMeasureEn);
			if (pChrCtrl->enable)
			{
				pmu_set_chr(ADC_EN, 7);	
			}
			else
			{
				pmu_set_chr(ADC_EN, 0);	
			}
			
		}
		break;	
		case CHR_GET_IS_BATTERY_ON:
		{
			PMU_CTRL_CHR_GET_IS_BATTERY_ON *pChrCtrl=&(data->rPMUChrGetIsBatteryOn);
						
			if (pmu_get_chr(BATON_UNDET)==0)
			{
				pChrCtrl->enable=DCL_TRUE;
			}
			else
			{
				pChrCtrl->enable=DCL_FALSE;
			}
			
		}
		break;	
		case CHR_SET_CSDAC_EN:
		{
			PMU_CTRL_CHR_SET_CSDAC_EN *pChrCtrl=&(data->rPMUChrSetCsdacEn);
			pmu_set_chr(CSDAC_EN, pChrCtrl->enable);		
		}
		break;	
		case CHR_SET_CV_DETECTION_EN:
		{
			PMU_CTRL_CHR_SET_CV_DETECTION_EN	*pChrCtrl=&(data->rPMUChrSetCvDetectionEn);
			pmu_set_chr(VBAT_CV_EN, pChrCtrl->enable);	
		}
		break;	
		case CHR_SET_CV_DETECTION_VOLTAGE:
		{
			PMU_CTRL_CHR_SET_CV_DETECTION_VOLTAGE	*pChrCtrl=&(data->rPMUChrSetCvDetectionVoltage);

			if (pmu_calibration_enable==DCL_TRUE)
            {
				pmu_set_chr(VBAT_CV_VTH, pmu_calibration_cv_val);
            }
            else
            {
				val=PMU_Parameter_to_Value(ENC(CHR_SET_CV_DETECTION_VOLTAGE,CHR),pChrCtrl->voltage);

				if (val==PARAMETER_UNKNOWN)
					return STATUS_UNSUPPORTED;	
				pmu_set_chr(VBAT_CV_VTH, val);	
			}
		}
		break;		
		case CHR_SET_CV_DETECTION_VOLTAGE_CALIBRATION:
		{
			/*
			if (pmu_calibration_enable==DCL_TRUE)
				pmu_set_chr(VBAT_CV_VTH, pmu_calibration_cv_val);
			else
				pmu_set_chr(VBAT_CV_VTH, 10);
			*/
		}
		break;
		case CHR_GET_CV_DETECTION_STATUS:
		{
			PMU_CTRL_CHR_GET_CV_DETECTION_STATUS *pChrCtrl=&(data->rPMUChrGetCvDetectionStatus); 
			pChrCtrl->enable=(DCL_BOOL)pmu_get_chr(VBAT_CV_DET);
		}
		break;	
		case CHR_SET_CHR_EN:
		{
			PMU_CTRL_CHR_SET_CHR_EN	*pChrCtrl=&(data->rPMUChrSetChrEn);
			pmu_set_chr(CSDAC_DLY, 3);
			pmu_set_chr(CSDAC_STP, 0);
			pmu_set_chr(CHR_EN, pChrCtrl->enable);
		}
		break;	
		case CHR_GET_CHR_DET_STATUS:
		{
			PMU_CTRL_CHR_GET_CHR_DET_STATUS *pChrCtrl=&(data->rPMUChrGetChrDetStatus);
			pChrCtrl->enable=pmu_get_chr(CHRDET);
		}	
		break;	
		case CHR_SET_WDT_CLEAR:
		{
			pmu_set_chr_wdt_clear(CHR);
		}
		break;	
		case CHR_SET_WDT_TIMER:
		{
			PMU_CTRL_CHR_SET_WDT_TIMER *pChrCtrl=&(data->rPMUChrSetWdtTimer);
			val=PMU_Parameter_to_Value(ENC(CHR_SET_WDT_TIMER,CHR),pChrCtrl->secs);

			if (val==PARAMETER_UNKNOWN)
				return STATUS_UNSUPPORTED;	

			pmu_set_chr(CHRWDT_TD, val);
		}
		break;	
		case CHR_SET_WDT_INT_EN:
		{
			PMU_CTRL_CHR_SET_WDT_INT_EN *pChrCtrl=&(data->rPMUChrSetWdtIntEn);
			pmu_set_chr(CHRWDT_INT_EN, pChrCtrl->enable);
		}
		break;
		case CHR_SET_WDT_EN:
		{
			PMU_CTRL_CHR_SET_WDT_EN *pChrCtrl=&(data->rPMUChrSetWdtEn);
			pmu_set_chr(CHRWDT_EN, pChrCtrl->enable);

		}
		break;
		case CHR_GET_CHR_CURRENT:
		{
			PMU_CTRL_CHR_GET_CHR_CURRENT *pChrCtrl=&(data->rPMUChrGetChrCurrent);
			DCL_UINT16 regVal;
			regVal=pmu_get_chr(CS_VTH);
			val=PMU_Value_to_Parameter(ENC(CHR_SET_CHR_CURRENT,CHR),regVal);

			if (val==PARAMETERVAL_UNKNOWN)
				return STATUS_UNSUPPORTED;
			
			pChrCtrl->current=(PMU_CHR_CURRENT_ENUM)val;
		}
		break;
		case CHR_SET_CHR_CURRENT:
		{
			PMU_CTRL_CHR_SET_CHR_CURRENT	*pChrCtrl=&(data->rPMUChrSetChrCurrent);
			val=PMU_Parameter_to_Value(ENC(CHR_SET_CHR_CURRENT,CHR),pChrCtrl->current);

			if (val==PARAMETER_UNKNOWN)
				return STATUS_UNSUPPORTED;

			pmu_set_chr(CS_VTH, val);

		}
		break;	
		case CHR_GET_CHR_CURRENT_LIST:
		{
			PMU_CTRL_CHR_GET_CHR_CURRENT_LIST *pChrCtrl=&(data->rPMUChrGetChrCurrentList);
			pChrCtrl->pCurrentList=cs_vth;
			pChrCtrl->number=GETARRNUM(cs_vth);
		}
		break;	
		case CHR_SET_HV_DETECTION_VOLTAGE:
		{
			PMU_CTRL_CHR_SET_HV_DETECTION_VOLTAGE	*pChrCtrl=&(data->rPMUChrSetHvDetectionVoltage);
			val=PMU_Parameter_to_Value(ENC(CHR_SET_HV_DETECTION_VOLTAGE,CHR),pChrCtrl->voltage);

			if (val==PARAMETER_UNKNOWN)
				return STATUS_UNSUPPORTED;

			pmu_set_chr(VCDT_HV_VTH, val);

		}
		break;

		case CHR_GET_HV_DETECTION_VOLTAGE_LIST:
		{
			PMU_CTRL_CHR_GET_HV_DETECTION_VOLTAGE_LIST *pChrCtrl = &(data->rPMUChrGetHvDetectionVoltageList);
			pChrCtrl->pVoltageList = chr_hv_vth;
			pChrCtrl->number = GETARRNUM(chr_hv_vth);
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
	}

	return STATUS_OK;
}

void pmu6252_bl_init(void);
void pmu_6252_spk_init(void);



DCL_UINT8 pmu6252_ldo_cal(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT32 vol)
{
	DCL_UINT32 i=0;

	if (pmu_calibration_enable==KAL_TRUE && ldo!=VCORE)
	{
		DCL_UINT8 size=voltage_calibration_size;
		for (i=0;i<size;i++)
		{
			if (voltage_calibration_idx[i]==vol)
			{
				pmu_set_ldo_buck(ldo,LDO_CAL,voltage_calibration_tab[i][pmu_calibration_cv_val]);
				//ldo_set_voltage_calibration_code(ldo, voltage_calibration_tab[i][pmu_calibration_cv_val]);
				break;
			}
		}
	}
	return 0;
}

void pmu6252_efuse_calibration(void)
{
	// E-FUSE calibration
	DCL_UINT32 val32;
	DCL_UINT16 val16;

	voltage_calibration_size=sizeof(voltage_calibration_idx)/sizeof(voltage_calibration_idx[0]);
	
	/*
	// 1. SIM1 LS calibration
	val32 = PMU_DRV_ReadReg32((EFUSE_base+0x0020));
	val8 = (DCL_UINT8)((val32 & 0x03000000) >> 24);
	upmu_ldo_sim_srn(LDO_VSIM, val8);
	val8 = (DCL_UINT8)((val32 & 0x00C00000) >> 22);
	upmu_ldo_sim_srp(LDO_VSIM, val8);
	val8 = (DCL_UINT8)((val32 & 0x00300000) >> 20);
	upmu_ldo_sim_bias(LDO_VSIM, val8);
	// 2. SIM2 LS calibration
	val32 = PMU_DRV_ReadReg32((EFUSE_base+0x0020));
	val8 = (DCL_UINT8)((val32 & 0xC0000000) >> 30);
	upmu_ldo_sim_srn(LDO_VSIM2, val8);
	val8 = (DCL_UINT8)((val32 & 0x30000000) >> 28);
	upmu_ldo_sim_srp(LDO_VSIM2, val8);
	val8 = (DCL_UINT8)((val32 & 0x0C000000) >> 26);
	upmu_ldo_sim_bias(LDO_VSIM2, val8);
	*/
	// 3. IBIAS of iSINK
	// Current comes from STRUP, so need to configure registrs in STRUP block
	// Here, we do NOT implment upmu_XXX utiliy for this
	val32 = PMU_DRV_ReadReg32((EFUSE_base+0xF018));
	if (val32 & 0x20000000) // Bit28: Trim enable bit
	{
		val16 = (DCL_UINT16)((val32 & 0x1E000000)>>25);  // [28..25]: IBIAS trim bits
		PMU_DRV_SetData16((STRUP_CON0+0x08), 0x000F, val16);
	}
	// 4. CV
	// (BASE+0xf018)[21:20]=[53:52] + (BASE+0xf018)[19:17]=[51:49] apply to RG_VBAT_CV_VTH[4:0]
	// (BASE+0xf018)[23]=[55] apply to RG_RD_MODE_RV[0] for future use
	// ######!!!!!!!!! Need to ask YK if E2 CV value will be reset when charger out
	// Ans:

	val32 = PMU_DRV_ReadReg32((EFUSE_base+0xF018));
	if (val32 & 0x01000000) // Bit24: Trim enable bit
	{
		pmu_calibration_enable=KAL_TRUE;
		pmu_calibration_cv_val = (DCL_UINT8)( (val32 & 0x003E0000) >> 17); // Bit[21..17]

		val16 = (DCL_UINT16)( (val32 & 0x00800000) >> 23);	// Bit23: Directly apply to RG_RD_MODE_RV[0]
		//PMU_DRV_SetData16((0x83010A3C), 1, val16);
	}

	// 4. VBAT OVP
	// OVPTRIM_EN (1b)     *(BASE+0x0020)[18]=[338]
	// OVP_VTH (4b)   *(BASE+0x0020)[17:14]=[337:334]
	// OVP_VTH[3:2] = OVP_TRIM[1:0] (RG_STRUP_RSV[1:0], PMIC_STARTUP_CON3[1:0])
	// OVP_VTH[1:0] = VBAT_OV_VTH[1:0] (PMIC_CHR_CON3[7:6])
	// ######!!!!!!!!! Need to ask YK if E2 OVP value will be reset when charger out
	// Ans:
	val32 = PMU_DRV_ReadReg32((EFUSE_base+0x0020));
	if (val32 & 0x00040000) // Bit18: Trim enable bit
	{
		val16 = (DCL_UINT16)( (val32 & 0x00030000) >> 16);	// Bit[17..16] OVP_VTH[3..2]
		PMU_DRV_SetData16((MIXED_base + 0x090C), 0x3, val16);  // PMIC_STARTUP_CON3[1:0]

		pmu6252_ovp_val = (DCL_UINT8)( (val32 & 0x0000C000) >> 14); // Bit[15..14]
		PMU_DRV_SetData16((MIXED_base + 0x0a0c), 0x00c0, pmu6252_ovp_val<<6);  // apply to VBAT_OV_VTH[1:0] (PMIC_CHR_CON3[7:6])
	}


	// 5.ldo cal
	// VM ?
	pmu6252_ldo_cal(VRF28,PMU_VOLT_02_800000_V);
	pmu6252_ldo_cal(VIO28,PMU_VOLT_02_800000_V);
	pmu6252_ldo_cal(VA28,PMU_VOLT_02_800000_V);
	pmu6252_ldo_cal(VRTC,PMU_VOLT_02_800000_V);
	pmu6252_ldo_cal(VTCXO,PMU_VOLT_02_800000_V);
	pmu6252_ldo_cal(VUSB,PMU_VOLT_03_300000_V);
}


extern void pmu6252_customization_init(void);

void initLdoBuckMapping(void)
{
	DCL_UINT32 i,j,size=pmu_ldo_bb_size;

	for (i=0;i<PMU_LDO_BUCK_MAX;i++)
	{
		for (j=0;j<size;j++)
		{
			if (pmu_ldo_bb_profile[j].modidx==i)
			{	
				pmuModtoIdx[i]=j;
			}
		}
	}
}

void dcl_pmu6252_init(void)
{

	pmu_control_handler=dcl_pmu6252_control_handler;
	pmu_parameter_size=GETARRNUM(pmu_parameter_table);

	pmu_ldo_bb_size=GETARRNUM(pmu_ldo_bb_profile);
	initLdoBuckMapping();
	pmu6252_efuse_calibration();

	// 1. Reset BC11 and charger
	pmu_set_chr(BC11_RST, 1);

	// 2. BB take control of BC11 circuit
	pmu_set_chr(BC11_BB_CTRL, 1);

	pmu_set_chr(CHRWDT_INT_EN, KAL_TRUE);	
	pmu_set_chr(CHRWDT_TD, 3);
	pmu_set_chr(CHRWDT_EN, KAL_TRUE);	

	// Enable charger interrupt
	PMU_DRV_SetData16(INT_EN1, INT_CHR_DET_MASK, ((DCL_UINT16)(1<<INT_CHR_DET_SHIFT)));

	//cci_srclken
	//PMU_DRV_SetData16(0x83010818,0x0002,0x0000);	
	pmu_set_ldo_buck(VTCXO,CCI_SRCLKEN,0);

	//VRF28
	pmu_set_ldo_buck(VRF28,LDO_BUCK_EN,DCL_TRUE);	
	pmu_set_ldo_buck(VRF28,LDO_BUCK_RS,1);

	//VTCXO
	pmu_set_ldo_buck(VTCXO,LDO_BUCK_EN,DCL_TRUE);		
	pmu_set_ldo_buck(VTCXO,LDO_BUCK_NDIS_EN,DCL_TRUE);

	//VA28
	pmu_set_ldo_buck(VA28,LDO_BUCK_RS,1);

	//VCAMD
	pmu_set_ldo_buck(VCAMD,LDO_BUCK_VOL_SEL,4);//PMU_VOLT_01_300000_V

	//VCORE
	pmu_set_ldo_buck(VCORE,BUCK_VFBADJ_SLEEP,20);//PMU_VOLT_00_900000_V	

	//VSIM1
	pmu_set_ldo_buck(VSIM,LDO_BUCK_EN,DCL_TRUE);	

	//VSIM2
	pmu_set_ldo_buck(VSIM2,LDO_BUCK_NDIS_EN,DCL_TRUE);

	//VIBR
	pmu_set_ldo_buck(VIBR,LDO_BUCK_VOL_SEL,0);//PMU_VOLT_01_300000_V

	
/*
	// Charger
	chr_set_wdt_td(CHR, PMU_CHR_WDT_TD_32SEC);
	chr_set_wdt_int_enable(CHR, KAL_TRUE);
	chr_set_wdt_enable(CHR, KAL_TRUE);

	buck_set_sleep_voltage(VCORE, PMU_VOLT_01_200000_V);
	buck_set_voltage(VCORE, PMU_VOLT_01_200000_V);
	buck_set_stb_td(VCORE, 0); // Actually 213uS
	buck_set_oc_td(VCORE, 0); // Actually 91 uS

	
	ldo_set_oc_td(VIO28, 0); // Actually 91 uS
	ldo_set_oc_td(VUSB, 0); // Actually 91 uS
	ldo_set_oc_td(VA28, 0); // Actually 91 uS
	ldo_set_oc_td(VM, 0); // Actually 91 uS


	ldo_set_oc_auto_off(VRF, VRF_OC_AUTO_OFF);
	ldo_set_ndis_enable(VRF, VRF_NSID_EN);
	#if (!defined(__CUST_NEW_PMIC__)) // The items are exclusive with the items defined in custom tool PMIC page
	ldo_set_enable(VRF, VRF_EN);
	//ldo_set_current_limit(VRF, VRF_CAL);
	#endif // #if (!defined(__CUST_NEW_PMIC__))
	ldo_set_stb_td(VRF, VRF_STB_TD);
	ldo_set_oc_td(VRF, VRF_OC_TD);

	ldo_set_oc_auto_off(VTCXO, VTCXO_OC_AUTO_OFF);
	ldo_set_ndis_enable(VTCXO, VTCXO_NSID_EN);
	#if (!defined(__CUST_NEW_PMIC__)) // The items are exclusive with the items defined in custom tool PMIC page
	ldo_set_enable(VTCXO, VTCXO_EN);
	//ldo_set_current_limit(VTCXO, VTCXO_CAL);
	#endif // #if (!defined(__CUST_NEW_PMIC__))
	ldo_set_stb_td(VTCXO, VTCXO_STB_TD);
	ldo_set_oc_td(VTCXO, VTCXO_OC_TD);



	ldo_set_oc_auto_off(VCAMA, VCAMA_OC_AUTO_OFF);
	ldo_set_ndis_enable(VCAMA, VCAMA_NSID_EN);
	#if (!defined(__CUST_NEW_PMIC__)) // The items are exclusive with the items defined in custom tool PMIC page
	ldo_set_voltage(VCAMA, VCAMA_VOSEL);
	pmu6252_ldo_cal(VCAMA,VCAMA_VOSEL);
	ldo_set_enable(VCAMA, VCAMA_EN);
	//ldo_set_current_limit(VCAMA, VCAMA_CAL);
	#endif // #if (!defined(__CUST_NEW_PMIC__))
	ldo_set_stb_td(VCAMA, VCAMA_STB_TD);
	ldo_set_oc_td(VCAMA, VCAMA_OC_TD);


	#if !defined(MT6252_NO_VCAMD)
	ldo_set_oc_auto_off(VCAMD, VCAMD_OC_AUTO_OFF);
	ldo_set_ndis_enable(VCAMD, VCAMD_NSID_EN);
	#if (!defined(__CUST_NEW_PMIC__)) // The items are exclusive with the items defined in custom tool PMIC page
	ldo_set_voltage(VCAMD, VCAMD_VOSEL);
	pmu6252_ldo_cal(VCAMD,VCAMD_VOSEL);
	ldo_set_enable(VCAMD, VCAMD_EN);
	//ldo_set_current_limit(VCAMD, VCAMD_CAL);
	#endif // #if (!defined(__CUST_NEW_PMIC__))
	ldo_set_stb_td(VCAMD, VCAMD_STB_TD);
	ldo_set_oc_td(VCAMD, VCAMD_OC_TD);
	#endif // #if !defined(MT6252_NO_VCAMD)

	ldo_set_oc_auto_off(VSIM, VSIM_OC_AUTO_OFF);
	ldo_set_ndis_enable(VSIM, VSIM_NSID_EN);
	#if (!defined(__CUST_NEW_PMIC__)) // The items are exclusive with the items defined in custom tool PMIC page
	ldo_set_voltage(VSIM, VSIM_VOSEL);
	pmu6252_ldo_cal(VSIM,VSIM_VOSEL);	
	ldo_set_enable(VSIM, VSIM_EN);
	//ldo_set_current_limit(VSIM, VSIM_CAL);
	#endif // #if (!defined(__CUST_NEW_PMIC__))
	ldo_set_stb_td(VSIM, VSIM_STB_TD);
	ldo_set_ctrl_sel(VSIM, VSIM_LDO_EN_SEL);
	ldo_set_oc_td(VSIM, VSIM_OC_TD);

	ldo_set_oc_auto_off(VSIM2, VSIM2_OC_AUTO_OFF);
	ldo_set_ndis_enable(VSIM2, VSIM2_NSID_EN);
	#if (!defined(__CUST_NEW_PMIC__)) // The items are exclusive with the items defined in custom tool PMIC page
	ldo_set_voltage(VSIM2, VSIM2_VOSEL);
	pmu6252_ldo_cal(VSIM2,VSIM2_VOSEL);
	ldo_set_enable(VSIM2, VSIM2_EN);
	//ldo_set_current_limit(VSIM2, VSIM2_CAL);
	#endif // #if (!defined(__CUST_NEW_PMIC__))
	ldo_set_stb_td(VSIM2, VSIM2_STB_TD);
	ldo_set_ctrl_sel(VSIM2, VSIM2_LDO_EN_SEL);
	ldo_set_oc_td(VSIM2, VSIM2_OC_TD);

	ldo_set_oc_auto_off(VIBR, VIBR_OC_AUTO_OFF);
	ldo_set_ndis_enable(VIBR, VIBR_NSID_EN);
	#if (!defined(__CUST_NEW_PMIC__)) // The items are exclusive with the items defined in custom tool PMIC page
	ldo_set_voltage(VIBR, VIBR_VOSEL);
	pmu6252_ldo_cal(VIBR,VIBR_VOSEL);
	ldo_set_enable(VIBR, VIBR_EN);
	//ldo_set_current_limit(VIBR, VIBR_CAL);
	#endif // #if (!defined(__CUST_NEW_PMIC__))
	ldo_set_stb_td(VIBR, VIBR_STB_TD);
	ldo_set_oc_td(VIBR, VIBR_OC_TD);

	// SPK
	// Only support Class-AB mode, init function is called in pmu init function
	spk_set_vol(SPK, SPK_VOL);
	spk_set_oc_enable(SPK, SPK_OC_EN);
	spk_set_obias(SPK, SPK_OBIAS);
	
*/
	pmu6252_customization_init();

	pmu6252_bl_init();

	pmu_6252_spk_init();

        //voltage calibration 
        if (INT_ecoVersion()==ECO_E1 || INT_ecoVersion()==ECO_E2)
        {				
		pmu_set_ldo_buck(VM,LDO_CAL,4);
		  // VCORE, 830108D0h[8:4] to 11110
		pmu_set_ldo_buck(VCORE,LDO_BUCK_VOL_SEL,30);
        }

	// Disable Power Good Detection
	// 0x8301090C[7:0] = 0x3F
	PMU_DRV_SetData16(MIXED_base + 0x090C,0x00FF,0x003F);

}


//static pmic_adpt_bl_mode_enum bl_mode;
void pmu6252_bl_init(void)
{
	pmu_set_isink(ISINK0, ISINK_VREF_CAL,0);
	pmu_set_isink(ISINK0, ISINK_MODE,ISINK_PWM_MODE);
	pmu_set_isink(ISINK1, ISINK_MODE,ISINK_PWM_MODE);
	pmu_set_isink(ISINK2, ISINK_MODE,ISINK_PWM_MODE);
	pmu_set_isink(ISINK3, ISINK_MODE,ISINK_PWM_MODE);	
}

void pmu_6252_bl_enable(DCL_BOOL enable)
{
	DCL_UINT32 i;
	for (i=0;i<PMU_ISINK_MAX;i++)
	{
		if (pmu6252_cust_isink_en[i])
		{
			pmu_set_isink((PMU_ISINK_LIST_ENUM)i,ISINK_EN,(DCL_UINT32)enable);
		}
	}
}

//static pmic_adpt_spk_mode_enum spk_mode;
void pmu_6252_spk_init(void)
{
	pmu_set_spk(SPK_OC_WND, 0);
	pmu_set_spk(SPK_OC_THD, 0);
	pmu_set_spk(SPK_OC_EN, DCL_FALSE);
}



#endif //#if (defined(PMIC_6252_REG_API))
