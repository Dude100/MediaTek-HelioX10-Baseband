

#include    "drv_features.h"
#include    "drv_comm.h"
#include    "dcl.h"
#include	  "pwic.h"
#include    "bmt.h"

extern BMTStruct BMT;			 /*Main BMT struct*/



#if ( (defined(PMIC_6326_REG_API))  )
void pmic_vgp2_on_sel(vgp2_on_sel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_ON_SEL val;
	val.onSel=sel;
	val.mod=VGP2;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_ON_SEL, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}	

void pmic_vcore2_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VCORE2;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}


void pmic_vgp2_sel(vgp2_sel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(sel)
	{
		case VGP2_1_3:
			val.voltage=PMU_VOLT_01_300000_V;
			break;
		case VGP2_1_5:
			val.voltage=PMU_VOLT_01_500000_V;
			break;			
		case VGP2_1_8:
			val.voltage=PMU_VOLT_01_800000_V;
			break;				
		case VGP2_2_5:
			val.voltage=PMU_VOLT_02_500000_V;
			break;		
		case VGP2_2_8:
			val.voltage=PMU_VOLT_02_800000_V;
			break;
		case VGP2_3_0:
			val.voltage=PMU_VOLT_03_000000_V;
			break;		
		case VGP2_3_3:
			val.voltage=PMU_VOLT_03_300000_V;
			break;
			default:
			ASSERT(0);
			break;			
	}

	
	val.mod=VGP2;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

}

void pmic_vpa_bat_low(kal_bool bat_low)
{
	DCL_HANDLE handle;
	PMU_CTRL_VPA_SET_BAT_LOW val;
	val.enable=bat_low;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, VPA_SET_BAT_LOW, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vpa_tuneh(kal_uint8 value)
{
	DCL_HANDLE handle;
	PMU_CTRL_VPA_SET_VOLTAGE val;
	val.vpa=VPA1;
	val.vpaIdx=PMU_VPA0;
	val.voltage=PMU_VOLT_01_075000_V+75000*value;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, VPA_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vpa_tunel(kal_uint8 value)
{
	DCL_HANDLE handle;
	PMU_CTRL_VPA_SET_VOLTAGE val;
	val.vpa=VPA1;
	val.vpaIdx=PMU_VPA1;
	val.voltage=PMU_VOLT_01_075000_V+75000*value;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, VPA_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vrf_on_sel(vrf_on_sel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_ON_SEL val;
	val.onSel=sel;
	val.mod=VRF;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_ON_SEL, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

}

pmic_vtcxo_on_sel(vtcxo_on_sel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_ON_SEL val;
	val.onSel=sel;
	val.mod=VTCXO;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_ON_SEL, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}






void pmic_adpt_speaker_enable(kal_bool enable)
{
	//pmic6326_cust_vspk_enable(enable);
	DCL_HANDLE handle;
	PMU_CTRL_SPK_SET_EN val;
	val.enable=enable;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, SPK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);	
}

void pmic_vbt_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VBT;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vbt_sel(vbt_sel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(sel)
	{
		case VBT_1_3:
			val.voltage=PMU_VOLT_01_300000_V;
			break;
		case VBT_1_5:
			val.voltage=PMU_VOLT_01_500000_V;
			break;			
		case VBT_1_8:
			val.voltage=PMU_VOLT_01_800000_V;
			break;				
		case VBT_2_5:
			val.voltage=PMU_VOLT_02_500000_V;
			break;		
		case VBT_2_8:
			val.voltage=PMU_VOLT_02_800000_V;
			break;
		case VBT_3_0:
			val.voltage=PMU_VOLT_03_000000_V;
			break;		
		case VBT_3_3:
			val.voltage=PMU_VOLT_03_300000_V;
			break;
		case VBT_1_2:
			val.voltage=PMU_VOLT_01_200000_V;
			break;			
			default:
			ASSERT(0);
			break;			
	}

	
	val.mod=VBT;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);


}	

void pmic_vcama_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VCAMA;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vcama_sel(vcama_sel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(sel)
	{
		case VCAMA_2_8:
			val.voltage=PMU_VOLT_02_800000_V;
			break;
		case VCAMA_2_5:
			val.voltage=PMU_VOLT_02_500000_V;
			break;			
		case VCAMA_1_8:
			val.voltage=PMU_VOLT_01_800000_V;
			break;				
		case VCAMA_1_5:
			val.voltage=PMU_VOLT_01_500000_V;
			break;			
			default:
			ASSERT(0);
			break;			
	}

	val.mod=VCAMA;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

}	

void pmic_vcamd_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VCAMD;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vcamd_sel(vcamd_sel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(sel)
	{
		case VCAMD_1_3:
			val.voltage=PMU_VOLT_01_300000_V;
			break;
		case VCAMD_1_5:
			val.voltage=PMU_VOLT_01_500000_V;
			break;			
		case VCAMD_1_8:
			val.voltage=PMU_VOLT_01_800000_V;
			break;				
		case VCAMD_2_5:
			val.voltage=PMU_VOLT_02_500000_V;
			break;
		case VCAMD_2_8:
			val.voltage=PMU_VOLT_02_800000_V;
			break;
		case VCAMD_3_0:
			val.voltage=PMU_VOLT_03_000000_V;
			break;			
		case VCAMD_3_3:
			val.voltage=PMU_VOLT_03_300000_V;
			break;				
		case VCAMD_1_2:
			val.voltage=PMU_VOLT_01_500000_V;
			break;				
			default:
			ASSERT(0);
			break;			
	}

	val.mod=VCAMD;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

}	

void pmic_vwifi2v8_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VWIFI2V8;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vwifi2v8_sel(vwifi2v8_sel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(sel)
	{
		case VWIFI2V8_2_8:
			val.voltage=PMU_VOLT_02_800000_V;
			break;
		case VWIFI2V8_3_0:
			val.voltage=PMU_VOLT_03_000000_V;
			break;			
		case VWIFI2V8_3_3:
			val.voltage=PMU_VOLT_03_300000_V;
			break;				
		case VWIFI2V8_2_5:
			val.voltage=PMU_VOLT_02_500000_V;
			break;	
			default:
			ASSERT(0);
			break;			
	}

	val.mod=VWIFI2V8;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}


void pmic_vgp_sel(vgp_sel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(sel)
	{
		case VGP_1_3:
			val.voltage=PMU_VOLT_01_300000_V;
			break;
		case VGP_1_5:
			val.voltage=PMU_VOLT_01_500000_V;
			break;			
		case VGP_1_8:
			val.voltage=PMU_VOLT_01_800000_V;
			break;				
		case VGP_2_5:
			val.voltage=PMU_VOLT_02_500000_V;
			break;
		case VGP_2_8:
			val.voltage=PMU_VOLT_02_800000_V;
			break;
		case VGP_3_0:
			val.voltage=PMU_VOLT_03_000000_V;
			break;			
		case VGP_3_3:
			val.voltage=PMU_VOLT_03_300000_V;
			break;						
			default:
			ASSERT(0);
			break;			
	}

	val.mod=VGP;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vsdio_sel(vsdio_sel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(sel)
	{
		case VSDIO_2_8:
			val.voltage=PMU_VOLT_02_800000_V;
			break;
		case VSDIO_3_0:
			val.voltage=PMU_VOLT_03_000000_V;
			break;			
			default:
			ASSERT(0);
			break;			
	}

	val.mod=VSDIO;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}



void pmic_vwifi3v3_sel(vwifi3v3_sel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(sel)
	{
		case VWIFI3V3_2_8:
			val.voltage=PMU_VOLT_02_800000_V;
			break;
		case VWIFI3V3_3_0:
			val.voltage=PMU_VOLT_03_000000_V;
			break;			
		case VWIFI3V3_3_3:
			val.voltage=PMU_VOLT_03_300000_V;
			break;				
		case VWIFI3V3_2_5:
			val.voltage=PMU_VOLT_02_500000_V;
			break;	
			default:
			ASSERT(0);
			break;			
	}

	val.mod=VWIFI3V3;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_v3grx_sel(v3grx_vol sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(sel)
	{
		case V3GRX_2_8:
			val.voltage=PMU_VOLT_02_800000_V;
			break;
		case V3GRX_3_0:
			val.voltage=PMU_VOLT_03_000000_V;
			break;			
		case V3GRX_3_3:
			val.voltage=PMU_VOLT_03_300000_V;
			break;				
		case V3GRX_2_5:
			val.voltage=PMU_VOLT_02_500000_V;
			break;	
			default:
			ASSERT(0);
			break;			
	}

	val.mod=V3GRX;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_v3gtx_sel(v3gtx_vol sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(sel)
	{
		case V3GTX_2_8:
			val.voltage=PMU_VOLT_02_800000_V;
			break;
		case V3GTX_3_0:
			val.voltage=PMU_VOLT_03_000000_V;
			break;			
		case V3GTX_3_3:
			val.voltage=PMU_VOLT_03_300000_V;
			break;				
		case V3GTX_2_5:
			val.voltage=PMU_VOLT_02_500000_V;
			break;	
			default:
			ASSERT(0);
			break;			
	}

	val.mod=V3GTX;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}


void pmic_bl_dim_duty(kal_uint8 duty)
{
	DCL_HANDLE handle;
	PMU_CTRL_ISINK_SET_DIMMING_ON_DUTY val;
	val.duty=duty;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, ISINK_SET_DIMMING_ON_DUTY, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

}

void pmic_boost2_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_BOOST_SET_EN val;
	val.boost=BOOST2;
	val.enable=enable;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, BOOST_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}	


void pmic_kp_dim_div(kal_uint8 div)
{
	DCL_HANDLE handle;
	PMU_CTRL_KPLED_SET_FREQUENCY_DIVISION val;
	val.div=div;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, KPLED_SET_FREQUENCY_DIVISION, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_kp_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_KPLED_SET_EN val;
	val.enable=enable;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, KPLED_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_kp_dim_duty(kal_uint8 duty)
{
	DCL_HANDLE handle;
	PMU_CTRL_KPLED_SET_DIMMING_ON_DUTY val;
	val.duty=duty;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, KPLED_SET_DIMMING_ON_DUTY, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_v3gtx_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=V3GTX;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_v3gtx_on_sel(v3gtx_on_sel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_ON_SEL val;
	val.onSel=sel;
	val.mod=V3GTX;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_ON_SEL, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

}

void pmic_v3grx_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=V3GRX;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vgp2_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VGP2;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vgp_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VGP;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}	

void pmic_vsdio_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VSDIO;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vsim_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VSIM;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vusb_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VUSB;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}


void pmic_vpa_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_VPA_SET_EN val;
	val.enable=enable;
	val.vpa=VPA1;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, VPA_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_v3grx_cal(kal_uint8 cal)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE val;
	val.voltageCalibrationCode=cal;
	val.mod=V3GRX;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_v3gtx_cal(kal_uint8 cal)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE val;
	val.voltageCalibrationCode=cal;
	val.mod=V3GTX;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vbt_cal(kal_uint8 cal)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE val;
	val.voltageCalibrationCode=cal;
	val.mod=VBT;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vcama_cal(kal_uint8 cal)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE val;
	val.voltageCalibrationCode=cal;
	val.mod=VCAMA;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vcamd_cal(kal_uint8 cal)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE val;
	val.voltageCalibrationCode=cal;
	val.mod=VCAMD;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vgp_cal(kal_uint8 cal)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE val;
	val.voltageCalibrationCode=cal;
	val.mod=VGP;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}
void pmic_vrf_cal(kal_uint8 cal)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE val;
	val.voltageCalibrationCode=cal;
	val.mod=VRF;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vsdio_cal(kal_uint8 cal)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE val;
	val.voltageCalibrationCode=cal;
	val.mod=VSDIO;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vsim_cal(kal_uint8 cal)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE val;
	val.voltageCalibrationCode=cal;
	val.mod=VSIM;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vtcxo_cal(kal_uint8 cal)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE val;
	val.voltageCalibrationCode=cal;
	val.mod=VTCXO;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vwifi2v8_cal(kal_uint8 cal)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE val;
	val.voltageCalibrationCode=cal;
	val.mod=VWIFI2V8;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vwifi3v3_cal(kal_uint8 cal)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE val;
	val.voltageCalibrationCode=cal;
	val.mod=VWIFI3V3;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vibr_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VIBR;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_vibr_dim_duty(kal_uint8 duty)
{
	DCL_HANDLE handle;
	PMU_CTRL_VIBR_SET_DIMMING_ON_DUTY val;
	val.duty=duty;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, VIBR_SET_DIMMING_ON_DUTY, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}


#endif //#if ( (defined(PMIC_6326_REG_API))  )

#if (defined(PMIC_6236_REG_API))

kal_bool pmu6236_chr_cv_det(void)
{
	DCL_HANDLE handle;
	PMU_CTRL_CHR_GET_CV_DETECTION_STATUS chr;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, CHR_GET_CV_DETECTION_STATUS, (DCL_CTRL_DATA_T *)&chr);
	DclPMU_Close(handle);
	return (kal_bool)chr.enable;
}

void pmu6236_chr_vbat_cv_vth(pmu6236_chr_vbat_cv_enum cv)
{
	DCL_HANDLE handle;
	PMU_CTRL_CHR_SET_CV_DETECTION_VOLTAGE chr;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	chr.voltage=PMU_VOLT_04_000000_V+cv*12500;
	DclPMU_Control(handle, CHR_SET_CV_DETECTION_VOLTAGE, (DCL_CTRL_DATA_T *)&chr);
	DclPMU_Close(handle);
}

void pmu6236_spk_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_SPK_SET_EN val;
	val.enable=enable;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, SPK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu6236_vcamd_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VCAMD;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}
	
void pmu6236_vcama_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VCAMA;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu6236_vboost_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_BOOST_SET_EN val;
	val.boost=BOOST1;
	val.enable=enable;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, BOOST_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu6236_vusb_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VUSB;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu6236_vcama_vosel(pmu6236_vcama_vosel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(sel)
	{
		case VCAMA_SEL_1_5V:
			val.voltage=PMU_VOLT_01_500000_V;
			break;
		case VCAMA_SEL_1_8V:
			val.voltage=PMU_VOLT_01_800000_V;
			break;			
		case VCAMA_SEL_2_5V:
			val.voltage=PMU_VOLT_02_500000_V;
			break;				
		case VCAMA_SEL_2_8V:
			val.voltage=PMU_VOLT_02_800000_V;
			break;	
			default:
			ASSERT(0);
			break;			
	}

	val.mod=VCAMA;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

}

void pmu6236_vcamd_vosel(pmu6236_vcamd_vosel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(sel)
	{
		case VCAMD_SEL_1_3V:
			val.voltage=PMU_VOLT_01_500000_V;
			break;
		case VCAMD_SEL_1_5V:
			val.voltage=PMU_VOLT_01_800000_V;
			break;			
		case VCAMD_SEL_1_8V:
			val.voltage=PMU_VOLT_02_500000_V;
			break;				
		case VCAMD_SEL_2_8V:
			val.voltage=PMU_VOLT_02_800000_V;
			break;	
			default:
			ASSERT(0);
			break;			
	}

	val.mod=VCAMD;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

}

#endif //#if (defined(PMIC_6236_REG_API))

#if ( (defined(PMIC_6253_REG_API))  )

void pmu6253_vrf_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VRF;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}



void pmu6253_vrf_on_sel(pmu6253_vrf_on_sel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_ON_SEL val;
	val.onSel=sel;
	val.mod=VRF;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_ON_SEL, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu6253_vtcxo_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VTCXO;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}


void pmu6253_vtcxo_on_sel(pmu6253_vtcxo_on_sel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_ON_SEL val;
	val.onSel=sel;
	val.mod=VTCXO;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_ON_SEL, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu6253_vibr_sel(pmu6253_vibr_sel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(sel)
	{
		case VIBR_SEL_1_5V:
			val.voltage=PMU_VOLT_01_500000_V;
			break;
		case VIBR_SEL_1_8V:
			val.voltage=PMU_VOLT_01_800000_V;
			break;			
		case VIBR_SEL_2_5V:
			val.voltage=PMU_VOLT_02_500000_V;
			break;				
		case VIBR_SEL_3_0V:
			val.voltage=PMU_VOLT_03_000000_V;
			break;	
			default:
			ASSERT(0);
			break;			
	}

	val.mod=VIBR;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

}
void pmu6253_vcamd_sel(pmu6253_vcamd_sel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(sel)
	{
		case VCAMD_SEL_1_3V:
			val.voltage=PMU_VOLT_01_300000_V;
			break;
		case VCAMD_SEL_1_5V:
			val.voltage=PMU_VOLT_01_500000_V;
			break;			
		case VCAMD_SEL_1_8V:
			val.voltage=PMU_VOLT_01_800000_V;
			break;				
		case VCAMD_SEL_2_8V:
			val.voltage=PMU_VOLT_02_800000_V;
			break;	
			default:
			ASSERT(0);
			break;			
	}

	val.mod=VCAMD;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

}

void pmu6253_vcama_sel(pmu6253_vcama_sel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(sel)
	{
		case VCAMA_SEL_1_5V:
			val.voltage=PMU_VOLT_01_500000_V;
			break;
		case VCAMA_SEL_1_8V:
			val.voltage=PMU_VOLT_01_800000_V;
			break;			
		case VCAMA_SEL_2_5V:
			val.voltage=PMU_VOLT_02_500000_V;
			break;				
		case VCAMA_SEL_2_8V:
			val.voltage=PMU_VOLT_02_800000_V;
			break;	
			default:
			ASSERT(0);
			break;			
	}

	val.mod=VCAMA;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

}

void pmu6253_vcama_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VCAMA;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu6253_vcamd_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VCAMD;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu6253_vibr_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VIBR;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu6253_vusb_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VUSB;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}


void pmu6253_vbt_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VBT;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

}

void pmu6253_vbt_sel(pmu6253_vbt_sel_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(sel)
	{
#if defined(__DRV_PMU53_SPEC_V1__)	
		case VBT_SEL_2_8V:
			val.voltage=PMU_VOLT_02_800000_V;
			break;
		case VBT_SEL_3_0V:
			val.voltage=PMU_VOLT_03_000000_V;
			break;			
#else // #if defined(__DRV_PMU53_SPEC_V1__)	
		case VBT_SEL_1_5V:
			val.voltage=PMU_VOLT_01_500000_V;
			break;
		case VBT_SEL_1_8V:
			val.voltage=PMU_VOLT_01_800000_V;
			break;	
		case VBT_SEL_2_5V:
			val.voltage=PMU_VOLT_02_500000_V;
			break;
		case VBT_SEL_3_0V:
			val.voltage=PMU_VOLT_03_000000_V;
			break;				
#endif // #if defined(__DRV_PMU53_SPEC_V1__)
			default:
			ASSERT(0);
			break;			
	}

	val.mod=VBT;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);


}

void pmu6253_vboost_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_BOOST_SET_EN val;
	val.enable=enable;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, BOOST_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}


void pmu6253_vboost_sync_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_BOOST_SET_SYNC_EN val;
	val.enable=enable;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, BOOST_SET_SYNC_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}


void pmu6253_vboost_tune(kal_uint8 sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_BOOST_SET_VOLTAGE val;

	switch(sel)
	{
		case 0:
			val.voltage=PMU_VOLT_03_200000_V;
			break;
		case 1:
			val.voltage=PMU_VOLT_03_350000_V;
			break;
		case 2:
			val.voltage=PMU_VOLT_03_500000_V;
			break;
		case 3:
			val.voltage=PMU_VOLT_03_650000_V;
			break;
		case 4:
			val.voltage=PMU_VOLT_03_800000_V;
			break;
		case 5:
			val.voltage=PMU_VOLT_03_950000_V;
			break;
		case 6:
			val.voltage=PMU_VOLT_04_100000_V;
			break;
		case 7:
			val.voltage=PMU_VOLT_04_250000_V;
			break;
		case 8:
			val.voltage=PMU_VOLT_04_400000_V;
			break;
		case 9:
			val.voltage=PMU_VOLT_04_550000_V;
			break;
		case 10:
			val.voltage=PMU_VOLT_04_700000_V;
			break;
		case 11:
			val.voltage=PMU_VOLT_04_850000_V;
			break;
		case 12:
			val.voltage=PMU_VOLT_05_000000_V;
			break;
		case 13:
			val.voltage=PMU_VOLT_05_150000_V;
			break;
		case 14:
			val.voltage=PMU_VOLT_05_300000_V;
			break;
		case 15:
			val.voltage=PMU_VOLT_05_450000_V;
			break;
		
			default:
			ASSERT(0);
			break;			
	}


	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, BOOST_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu6253_kpled_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_KPLED_SET_EN val;
	val.enable=enable;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, KPLED_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

/*
pmu6253_spk_enable
pmu6253_spk_mode
pmu6253_spk_oc_enable
pmu6253_spk_vol
pmu6253_spk_get_vol
pmu6253_spk_slew
*/

void pmu6253_spk_slew(pmu6253_spk_slew_enum sel)
{

}

void pmu6253_spk_vol(kal_uint8 vol)
{
	DCL_HANDLE handle;
	PMU_CTRL_SPK_SET_VOL_VALUE val;
	val.volValue=vol;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, SPK_SET_VOL_VALUE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

kal_uint8 pmu6253_spk_get_vol(void)
{
	DCL_HANDLE handle;
	PMU_CTRL_SPK_GET_VOL_VALUE val;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, SPK_GET_VOL_VALUE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

	return (kal_uint8)val.volValue;
}

void pmu6253_spk_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_SPK_SET_EN val;
	val.enable=enable;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, SPK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu6253_spk_mode(pmu6253_spk_mode_enum sel)
{
	DCL_HANDLE handle;
	PMU_CTRL_SPK_SET_MODE val;
	val.mode=sel;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, SPK_SET_MODE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu6253_spk_oc_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_SPK_SET_OC_AUTO_OFF val;
	val.enable=enable;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, SPK_SET_OC_AUTO_OFF, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);	
}

#endif //#if ( (defined(PMIC_6253_REG_API))  )


void pmic_adpt_set_chr_current_level(kal_uint32 level)
{
	//pmic_chr_current(level);
	PMU_CTRL_CHR_SET_CHR_CURRENT val;
	DCL_HANDLE handle;

	switch(level)
	{
		case 0:
			val.current=PMU_CHARGE_CURRENT_62_50_MA;
			break;
		case 1:
			val.current=PMU_CHARGE_CURRENT_87_50_MA;
			break;			
		case 2:
			val.current=PMU_CHARGE_CURRENT_150_00_MA;
			break;				
		case 3:
			val.current=PMU_CHARGE_CURRENT_225_00_MA;
			break;		
		case 4:
			val.current=PMU_CHARGE_CURRENT_300_00_MA;
			break;
		case 5:
			val.current=PMU_CHARGE_CURRENT_450_00_MA;
			break;		
		case 6:
			val.current=PMU_CHARGE_CURRENT_650_00_MA;
			break;
		case 7:
			val.current=PMU_CHARGE_CURRENT_800_00_MA;
			break;			
			default:
			ASSERT(0);
			break;			
	}	
	
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, CHR_SET_CHR_CURRENT, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_adpt_vmc_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VMC;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_adpt2_chr_cv_th(pmic_adpt_voltage_enum vol)
{
	DCL_HANDLE handle;
	PMU_CTRL_CHR_SET_CV_DETECTION_VOLTAGE chr;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	chr.voltage=vol;
	DclPMU_Control(handle, CHR_SET_CV_DETECTION_VOLTAGE, (DCL_CTRL_DATA_T *)&chr);
	DclPMU_Close(handle);
}

kal_bool pmic_adpt2_get_chr_cv_det(void)
{
	DCL_HANDLE handle;
	PMU_CTRL_CHR_GET_CV_DETECTION_STATUS chr;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, CHR_GET_CV_DETECTION_STATUS, (DCL_CTRL_DATA_T *)&chr);
	DclPMU_Close(handle);
	return (kal_bool)chr.enable;
}


void pmic_adpt_vsim_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VSIM;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_adpt2_vrf_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VRF;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}


void pmic_adpt_vsim2_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VSIM2;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}	

void pmic_adpt2_vibr_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VIBR;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_adpt2_kpled_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_KPLED_SET_EN val;
	val.enable=enable;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, KPLED_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_adpt2_bl_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_BL_SET_EN val;
	val.enable=enable;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, BL_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_adpt2_spk_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_SPK_SET_EN val;
	val.enable=enable;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, SPK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_adpt_set_vcama(pmic_adpt_vcama_volt volt)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
	if (volt == PMIC_ADPT_VCAMA_1_5)
	{
		val.voltage=PMU_VOLT_01_500000_V;
	}else if (volt == PMIC_ADPT_VCAMA_1_8){
		val.voltage=PMU_VOLT_01_800000_V;
	}else if (volt == PMIC_ADPT_VCAMA_2_5){
		val.voltage=PMU_VOLT_02_500000_V;
	}else if (volt == PMIC_ADPT_VCAMA_2_8){
		val.voltage=PMU_VOLT_02_800000_V;
	}else{
		ASSERT(0);	// No mapping voltage level
	}


	val.mod=VCAMA;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

}

void pmic_adpt_set_vcamd(pmic_adpt_vcamd_volt volt){

	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
	if (volt == PMIC_ADPT_VCAMD_1_3){
		val.voltage=PMU_VOLT_01_300000_V;
	}else if (volt == PMIC_ADPT_VCAMD_1_5){
		val.voltage=PMU_VOLT_01_500000_V;
	}else if (volt == PMIC_ADPT_VCAMD_1_8){
		val.voltage=PMU_VOLT_01_800000_V;
	}else if (volt == PMIC_ADPT_VCAMD_2_8){
		val.voltage=PMU_VOLT_02_800000_V;
	}else{
		ASSERT(0);		// Not supported
	}

	val.mod=VCAMD;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

}

void pmic_adpt_vcama_enable(kal_bool enable){
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VCAMA;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_adpt_vcamd_enable(kal_bool enable){
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VCAMD;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_adpt_set_vsim(pmic_adpt_vsim_volt  volt)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(volt)
	{
		case PMIC_VSIM_1_8:
			val.voltage=PMU_VOLT_01_800000_V;
			break;
		case PMIC_VSIM_3_0:
			val.voltage=PMU_VOLT_03_000000_V;
			break;			
			default:
			ASSERT(0);
			break;			
	}

	val.mod=VSIM;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

kal_bool INT_USBBoot(void) // Backward compatible
{
	PW_CTRL_IS_USB_BOOT CtrlVal;
	DCL_HANDLE handle;
	handle=DclPW_Open(DCL_PW, FLAGS_NONE);
	DclPW_Control(handle, PW_CMD_IS_USB_BOOT,(DCL_CTRL_DATA_T *)&CtrlVal);
	DclPW_Close(handle);
	return CtrlVal.val;
}

kal_bool PW_Is_Charging_On(void)
{
	if (BMT.pmictrl_state == PMIC_CHARGEON)
	{
		return KAL_TRUE;
	}
	else
	{
		return KAL_FALSE;
	}
}

kal_bool bmt_is_charging_on(void) // Backward compatible
{
	return PW_Is_Charging_On();
}

void PW_PowerInit(void)
{
	DCL_HANDLE handle;
	Dcl_Chr_Det_Initialize();
	handle=DclPW_Open(DCL_PW, FLAGS_NONE);
	DclPW_Control(handle, PW_CMD_POWER_INIT, NULL);
	DclPW_Close(handle);
}

void pmic_adpt_init(void)
{
	DclPMU_Initialize();	
}

kal_bool DRV_NFB_POWERON(void)  /*power function for NFB*/
{
	DCL_HANDLE handle;
	handle=DclPW_Open(DCL_PW, FLAGS_NONE);
	DclPW_Control(handle,PW_CMD_NFB_POWERON,NULL);
	DclPW_Close(handle);
	return KAL_TRUE;
}

kal_bool DRV_POWERON(void) 
{
	DCL_HANDLE handle;
	handle=DclPW_Open(DCL_PW, FLAGS_NONE);
	DclPW_Control(handle,PW_CMD_POWERON,NULL);
	DclPW_Close(handle);
	return KAL_TRUE;
}

void DRV_POWEROFF(void) 
{
	DCL_HANDLE handle;
	handle=DclPW_Open(DCL_PW, FLAGS_NONE);
	DclPW_Control(handle,PW_CMD_POWEROFF,NULL);
	DclPW_Close(handle);
}

void PW_Set_Switch2Idle_Flag(void)
{
	DCL_HANDLE handle;
	handle=DclPW_Open(DCL_PW, FLAGS_NONE);
	DclPW_Control(handle,PW_CMD_SET_SWITCH_TO_IDLE,NULL);
	DclPW_Close(handle);
}	

void PW_Modify_PowerOn_Type(kal_uint8 powen_type)
{
	PW_CTRL_SET_POWERON_REASON CtrlVal;
	DCL_HANDLE handle;
	CtrlVal.powerOnReason=powen_type; 
	handle=DclPW_Open(DCL_PW, FLAGS_NONE);
	DclPW_Control(NULL,PW_CMD_SET_POWERON_REASON,(DCL_CTRL_DATA_T *)&CtrlVal);
	DclPW_Close(handle);
}

void Modify_PowerOn_Type(kal_uint8 powen_type) // Backward compatible
{
	PW_Modify_PowerOn_Type(powen_type);
}

void PW_update_flags(void)
{
	DCL_HANDLE handle;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPW_Control(handle,PW_CMD_UPDATE_FLAGS,NULL);
	DclPMU_Close(handle);
}

kal_bool pmic_adpt_is_chr_det(pmic_chr_type type)
{
	return KAL_FALSE;
}


void pmic_adpt_adc_measure(kal_bool on)
{
	DCL_HANDLE handle;
	PMU_CTRL_CHR_SET_ADC_MEASURE_EN val;
	val.enable=DCL_TRUE;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, CHR_SET_ADC_MEASURE_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_adpt2_set_vsim2(pmic_adpt_voltage_enum vol)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
	val.voltage=vol;
	val.mod=VSIM2;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
	
}

void pmic_adpt_set_vsim2(pmic_adpt_vsim_volt  volt)
{
	if (volt == PMIC_VSIM_1_8)
	{
		pmic_adpt2_set_vsim2(PMIC_ADPT_VOLT_01_800000_V);
	}
	else
	{
		pmic_adpt2_set_vsim2(PMIC_ADPT_VOLT_03_000000_V);
	}
}

void pmic_adpt2_vrf1v8_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VRF18;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_adpt2_vfm_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VFM;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);	
}

void pmic_adpt2_set_vfm(pmic_adpt_voltage_enum vol)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
	val.voltage=vol;
	val.mod=VFM;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_adpt2_set_vmc(pmic_adpt_voltage_enum vol)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
	val.voltage=vol;
	val.mod=VMC;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_adpt2_vmc_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VMC;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);		
}

void pmic_adpt2_vcama_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VCAMA;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);	
}

void pmic_adpt2_set_vcama(pmic_adpt_voltage_enum vol)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
	val.voltage=vol;
	val.mod=VCAMA;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_adpt2_vcamd_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VCAMD;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);	
}

void pmic_adpt2_set_vcamd(pmic_adpt_voltage_enum vol)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
	val.voltage=vol;
	val.mod=VCAMD;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmic_adpt2_clear_chr_wdt(void)
{
	DCL_HANDLE handle;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, CHR_SET_WDT_CLEAR, NULL);	
	DclPMU_Close(handle);
}

void pmic_adpt_clear_charge_wdt(void)
{
	pmic_adpt2_clear_chr_wdt();
}




kal_bool bmt_is_chr_exist(kal_uint8 power_on)
{

}

kal_bool pmic_adpt_is_bat_on(void)
{
	DCL_HANDLE handle;
	PMU_CTRL_CHR_GET_IS_BATTERY_ON chr;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, CHR_GET_IS_BATTERY_ON, (DCL_CTRL_DATA_T *)&chr);
	DclPMU_Close(handle);
	return (kal_bool)chr.enable;
}

void pmic_adpt2_chr_csdac_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_CHR_SET_CSDAC_EN chr;
	chr.enable=enable;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, CHR_SET_CSDAC_EN, (DCL_CTRL_DATA_T *)&chr);
	DclPMU_Close(handle);
}

void pmic_adpt2_chr_cv_det_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_CHR_SET_CV_DETECTION_EN chr;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	chr.enable=enable;
	DclPMU_Control(handle, CHR_SET_CV_DETECTION_EN, (DCL_CTRL_DATA_T *)&chr);
	DclPMU_Close(handle);
}


void pmic_adpt_reg_chr_usb(void)
{
	DCL_HANDLE handle;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	Dcl_Chr_Det_Control(handle, CHR_DET_CMD_REGISTER_CHR_USB, NULL);
	DclPMU_Close(handle);
}

void BMT_Charge(char data)  // Backward compatible
{
	//PW_Charge_Enable((kal_bool)data);
	tempBMT_Charge((kal_bool)data);
}

void pmic_adpt2_set_buckboost(kal_uint8 index, kal_uint8 vol)
{
	PMU_CTRL_VPA_SET_VOLTAGE	voltage;
	DCL_HANDLE handle;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	
	voltage.vpaIdx=index;
	voltage.voltage=PMU_VOLT_00_900000_V+vol*100000;
	voltage.vpa=VPA1;

	ASSERT(index<8);
	ASSERT(vol<=25);


	
	switch(index)
	{
		case 0:
			DclPMU_Control(handle, VPA_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&voltage);	
		break;
		case 1:
			DclPMU_Control(handle, VPA_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&voltage);	
		break;
		case 2:
			DclPMU_Control(handle, VPA_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&voltage);	
		break;
		case 3:
			DclPMU_Control(handle, VPA_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&voltage);	
		break;
		case 4:
			DclPMU_Control(handle, VPA_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&voltage);	
		break;
		case 5:
			DclPMU_Control(handle, VPA_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&voltage);	
		break;
		case 6:
			DclPMU_Control(handle, VPA_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&voltage);	
		break;
		case 7:
			DclPMU_Control(handle, VPA_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&voltage);	
		break;
		default:
			ASSERT(0);
		break;
		
	}
	DclPMU_Close(handle);
}

void pmic_adpt2_buckboost_enable(kal_bool enable)
{
	PMU_CTRL_VPA_SET_EN	val;
	DCL_HANDLE handle;
	val.enable=enable;
	val.vpa=VPA1;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);

	DclPMU_Control(handle, VPA_SET_EN, (DCL_CTRL_DATA_T *)&val);	
	DclPMU_Close(handle);
}

void pmic_adpt2_set_chr_current_level(pmic_adpt_chr_current_enum current)
{
	PMU_CTRL_CHR_SET_CHR_CURRENT chr;
	DCL_HANDLE handle;
	chr.current=current;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(NULL, CHR_SET_CHR_CURRENT, (DCL_CTRL_DATA_T *)&chr);
	DclPMU_Close(handle);
}

void pmic_adpt_chr_force_enable(kal_bool enable)
{
}

void pmic_adpt_reg_usb_int(kal_bool ACT_Polarity, void (reg_hisr)(void))
{
}

void pmic_adpt_set_chr_current(void)
{
}


kal_uint32 pmic_adpt_get_chr_current()
{
	PMU_CTRL_CHR_GET_CHR_CURRENT val;
	DCL_HANDLE handle;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, CHR_GET_CHR_CURRENT, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

	switch(val.current)
	{
		case PMU_CHARGE_CURRENT_62_50_MA:
			return 0;
			break;
		case PMU_CHARGE_CURRENT_87_50_MA:
			return 1;
			break;			
		case PMU_CHARGE_CURRENT_150_00_MA:
			return 2;
			break;				
		case PMU_CHARGE_CURRENT_225_00_MA:
			return 3;
			break;		
		case PMU_CHARGE_CURRENT_300_00_MA:
			return 4;
			break;
		case PMU_CHARGE_CURRENT_450_00_MA:
			return 5;
			break;		
		case PMU_CHARGE_CURRENT_650_00_MA:
			return 6;
			break;
		case PMU_CHARGE_CURRENT_800_00_MA:
			return 7;
			break;			
			default:
			ASSERT(0);
			break;			
	}	
	
}


void pmic6326_ccci_vsim_enable(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;

	val.enable=enable;
	val.mod=VSIM;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

}

void pmic_adpt_set_vsim_and_enable(pmic_adpt_vsim_volt volt)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE_EN val;

	switch(volt)
	{
		case PMIC_VSIM_1_8:
			val.voltage=PMU_VOLT_01_800000_V;
			break;
		case PMIC_VSIM_3_0:
			val.voltage=PMU_VOLT_03_000000_V;
			break;			
			default:
			ASSERT(0);
			break;			
	}

	val.mod=VSIM;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

#if defined(PMIC_62XX_REG_API) || defined(PMIC_62XX_REG_API)

void pmu_set_rled(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_MISC_SET_RLED_EN val;
	val.enable=enable;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, MISC_SET_RLED_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);	
}


void pmu_set_gled(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_MISC_SET_GLED_EN val;
	val.enable=enable;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, MISC_SET_GLED_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);	
}


void pmu_set_bled(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_MISC_SET_BLED_EN val;
	val.enable=enable;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, MISC_SET_BLED_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);	
}


void pmu_set_chr_cur_level(pmu_chr_cur_level level)
{
	PMU_CTRL_CHR_SET_CHR_CURRENT val;
	DCL_HANDLE handle;

	switch(level)
	{
		case CHR_CUR_50:
			val.current=PMU_CHARGE_CURRENT_50_00_MA;
			break;
		case CHR_CUR_87_5:
			val.current=PMU_CHARGE_CURRENT_87_50_MA;
			break;			
		case CHR_CUR_150:
			val.current=PMU_CHARGE_CURRENT_150_00_MA;
			break;				
		case CHR_CUR_225:
			val.current=PMU_CHARGE_CURRENT_225_00_MA;
			break;		
		case CHR_CUR_300:
			val.current=PMU_CHARGE_CURRENT_300_00_MA;
			break;
		case CHR_CUR_450:
			val.current=PMU_CHARGE_CURRENT_450_00_MA;
			break;		
		case CHR_CUR_650:
			val.current=PMU_CHARGE_CURRENT_650_00_MA;
			break;
		case CHR_CUR_800:
			val.current=PMU_CHARGE_CURRENT_800_00_MA;
			break;			
			default:
			ASSERT(0);
			break;			
	}	
	
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, CHR_SET_CHR_CURRENT, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);	


}

pmu_chr_cur_level pmu_get_chr_cur_level(void)
{
	return pmic_adpt_get_chr_current();
}

kal_bool pmu_is_bat_on(void)
{
	return pmic_adpt_is_bat_on();
}


void pmu_set_kpled(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_KPLED_SET_EN val;
	val.enable=enable;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, KPLED_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu_set_vbt_en(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VBT;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu_set_vcam_a_en(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VCAMA;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu_set_vcam_a_sel(pmu_vcam_a_volt volt)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(volt)
	{
		case VCAM_A_SEL_1_3:
			val.voltage=PMU_VOLT_01_300000_V;
			break;
		case VCAM_A_SEL_1_5:
			val.voltage=PMU_VOLT_01_500000_V;
			break;	
		case VCAM_A_SEL_1_8:
			val.voltage=PMU_VOLT_01_800000_V;
			break;	
		case VCAM_A_SEL_2_8:
			val.voltage=PMU_VOLT_02_800000_V;
			break;				
			default:
			ASSERT(0);
			break;			
	}

	val.mod=VCAMA;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu_set_vcam_d_en(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VCAMD;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu_set_vcam_d_sel(pmu_vcam_d_volt volt)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	switch(volt)
	{
		case VCAM_D_SEL_1_3:
			val.voltage=PMU_VOLT_01_300000_V;
			break;
		case VCAM_D_SEL_1_5:
			val.voltage=PMU_VOLT_01_500000_V;
			break;	
		case VCAM_D_SEL_1_8:
			val.voltage=PMU_VOLT_01_800000_V;
			break;	
		case VCAM_D_SEL_2_8:
			val.voltage=PMU_VOLT_02_800000_V;
			break;				
			default:
			ASSERT(0);
			break;			
	}

	val.mod=VCAMD;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu_set_vibr(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VIBR;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu_set_vusb_en(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	val.enable=enable;
	val.mod=VUSB;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}


void pmu_set_vsim_force(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN_FORCE val;
	val.enable=enable;
	val.mod=VSIM;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN_FORCE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

void pmu_set_vsim2_en_force(kal_bool enable)
{
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN_FORCE val;
	val.enable=enable;
	val.mod=VSIM2;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN_FORCE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

#endif //#if defined(PMIC_6223_REG_API) || defined(PMIC_6238_REG_API)




