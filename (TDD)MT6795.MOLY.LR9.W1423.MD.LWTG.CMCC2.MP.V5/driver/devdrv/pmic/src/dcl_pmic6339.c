/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  dcl_pmic6339.c
 *
 * Project:
 * --------
 *  MOLY
 *
 * Description:
 * ------------
 *	This is pmic6339 driver
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 ****************************************************************************/

#include "reg_base.h"
#include "intrCtrl.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"
#include "kal_public_api.h"
#include "drv_bsi.h"
#include "i2c_pmic.h"

#include "bl_common.h"


#define PMIC_MAX_REG_NUM	PMIC_REG_NUM

#ifdef PMIC_6339_DEBUG
static kal_uint16 pmic6339_reg[PMIC_MAX_REG_NUM];
#endif

static const DCL_UINT32 vio28_vosel[] =
{
	PMU_VOLT_01_200000_V, PMU_VOLT_01_300000_V, PMU_VOLT_01_500000_V, PMU_VOLT_01_800000_V,
	PMU_VOLT_02_500000_V, PMU_VOLT_02_800000_V, PMU_VOLT_03_000000_V, PMU_VOLT_03_300000_V,
};

static const DCL_UINT32 vcore_vosel[]=
{
      PMU_VOLT_00_700000_V, PMU_VOLT_00_725000_V, PMU_VOLT_00_775000_V, PMU_VOLT_00_750000_V,
      PMU_VOLT_00_875000_V, PMU_VOLT_00_850000_V, PMU_VOLT_00_800000_V, PMU_VOLT_00_825000_V,
      PMU_VOLT_01_075000_V, PMU_VOLT_01_050000_V, PMU_VOLT_01_000000_V, PMU_VOLT_01_025000_V,
      PMU_VOLT_00_900000_V, PMU_VOLT_00_925000_V, PMU_VOLT_00_975000_V, PMU_VOLT_00_950000_V,
      PMU_VOLT_01_475000_V, PMU_VOLT_01_450000_V, PMU_VOLT_01_400000_V, PMU_VOLT_01_425000_V,
      PMU_VOLT_01_300000_V, PMU_VOLT_01_325000_V, PMU_VOLT_01_375000_V, PMU_VOLT_01_350000_V,
      PMU_VOLT_01_100000_V, PMU_VOLT_01_125000_V, PMU_VOLT_01_175000_V, PMU_VOLT_01_150000_V,      
      PMU_VOLT_01_275000_V, PMU_VOLT_01_250000_V, PMU_VOLT_01_200000_V, PMU_VOLT_01_225000_V,           
};

static const DCL_UINT32 vsim_vosel[] =
{
	PMU_VOLT_01_200000_V, PMU_VOLT_01_300000_V, PMU_VOLT_01_500000_V, PMU_VOLT_01_800000_V,
	PMU_VOLT_02_500000_V, PMU_VOLT_02_800000_V, PMU_VOLT_03_000000_V, PMU_VOLT_03_300000_V,
	PMU_VOLT_01_060000_V
};

static const DCL_UINT32 vmc_io_vosel[] =
{
    PMU_VOLT_01_200000_V,   PMU_VOLT_01_300000_V,   PMU_VOLT_01_500000_V,   PMU_VOLT_01_800000_V,
    PMU_VOLT_02_000000_V,   PMU_VOLT_02_800000_V,   PMU_VOLT_03_000000_V,   PMU_VOLT_03_300000_V,
};

static const DCL_UINT32 vmch_vosel[] =
{
    PMU_VOLT_01_200000_V,   PMU_VOLT_01_300000_V,   PMU_VOLT_01_500000_V,   PMU_VOLT_01_800000_V,
    PMU_VOLT_02_500000_V,   PMU_VOLT_02_800000_V,   PMU_VOLT_03_000000_V,   PMU_VOLT_03_300000_V,
};

static const DCL_UINT32 vpa_vosel[] =
{
        PMU_VOLT_00_500000_V,   PMU_VOLT_INVALID,   PMU_VOLT_00_600000_V,   PMU_VOLT_INVALID,   
        PMU_VOLT_00_700000_V,   PMU_VOLT_INVALID,   PMU_VOLT_00_800000_V,   PMU_VOLT_INVALID,   
        PMU_VOLT_00_900000_V,   PMU_VOLT_INVALID,   PMU_VOLT_01_000000_V,   PMU_VOLT_INVALID,   
        PMU_VOLT_01_100000_V,   PMU_VOLT_INVALID,   PMU_VOLT_01_200000_V,   PMU_VOLT_INVALID,   
        PMU_VOLT_01_300000_V,   PMU_VOLT_INVALID,   PMU_VOLT_01_400000_V,   PMU_VOLT_INVALID,   
        PMU_VOLT_01_500000_V,   PMU_VOLT_INVALID,   PMU_VOLT_01_600000_V,   PMU_VOLT_INVALID,   
        PMU_VOLT_01_700000_V,   PMU_VOLT_INVALID,   PMU_VOLT_01_800000_V,   PMU_VOLT_INVALID,   
        PMU_VOLT_01_900000_V,   PMU_VOLT_INVALID,   PMU_VOLT_02_000000_V,   PMU_VOLT_INVALID, 
        PMU_VOLT_02_100000_V,   PMU_VOLT_INVALID,   PMU_VOLT_02_200000_V,   PMU_VOLT_INVALID,   
        PMU_VOLT_02_300000_V,   PMU_VOLT_INVALID,   PMU_VOLT_02_400000_V,   PMU_VOLT_INVALID,   
        PMU_VOLT_02_500000_V,   PMU_VOLT_INVALID,   PMU_VOLT_02_600000_V,   PMU_VOLT_INVALID,   
        PMU_VOLT_02_700000_V,   PMU_VOLT_INVALID,   PMU_VOLT_02_800000_V,   PMU_VOLT_INVALID,   
        PMU_VOLT_02_900000_V,   PMU_VOLT_INVALID,   PMU_VOLT_03_000000_V,   PMU_VOLT_INVALID,   
        PMU_VOLT_03_100000_V,   PMU_VOLT_INVALID,   PMU_VOLT_03_200000_V,   PMU_VOLT_INVALID,   
        PMU_VOLT_03_300000_V,   PMU_VOLT_INVALID,   PMU_VOLT_03_400000_V,   PMU_VOLT_INVALID,   
        PMU_VOLT_03_500000_V,   PMU_VOLT_INVALID,   PMU_VOLT_03_600000_V,   PMU_VOLT_INVALID,   

};

PMU_PARAMETER_TABLE_ENTRY pmu_parameter_table[]=
{
        {ENC(LDO_BUCK_SET_VOLTAGE, VIO28),		vio28_vosel,		NULL,				GETARRNUM(vio28_vosel)},
        {ENC(LDO_BUCK_SET_VOLTAGE, VCORE),		vcore_vosel,		NULL,				GETARRNUM(vcore_vosel)},                
	{ENC(LDO_BUCK_SET_VOLTAGE, VSIM),		vsim_vosel,		NULL,				GETARRNUM(vsim_vosel)},
	{ENC(LDO_BUCK_SET_VOLTAGE, VSIM2),		vsim_vosel,		NULL,				GETARRNUM(vsim_vosel)},
	{ENC(LDO_BUCK_SET_VOLTAGE, VMC),		vmc_io_vosel,		NULL,			GETARRNUM(vmc_io_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE, VMCH),		vmch_vosel,		NULL,				GETARRNUM(vmch_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE, VPA),		vpa_vosel,		NULL,				GETARRNUM(vpa_vosel)	},                
        {ENC(VPA_SET_VOLTAGE_SELECTION_TABLE, VPA),     vpa_vosel,		NULL,				GETARRNUM(vpa_vosel)	},                                
};
DCL_UINT16 pmu_parameter_size=0;
DCL_UINT16 pmic_CID0 = 0xFFFF;
DCL_UINT16 pmic_ECO_VERSION = 0xFFFF;


const PMU_FLAG_TABLE_ENTRY pmic_flags_table[] = 
{
        {CID0,		                CID0_ADDR,		        CID0_MASK,		CID0_SHIFT},        
        {ECO_VERSION,                   ECO_VERSION_ADDR,               ECO_VERSION_MASK,       	ECO_VERSION_SHIFT},
        {RG_VIO28_VOSEL,		RG_VIO28_VOSEL_ADDR,		RG_VIO28_VOSEL_MASK,		RG_VIO28_VOSEL_SHIFT},
        {RG_VIO28_EN,		        RG_VIO28_EN_ADDR,		RG_VIO28_EN_MASK,		RG_VIO28_EN_SHIFT},                
        {RG_VUSB11_EN,		        RG_VUSB11_EN_ADDR,		RG_VUSB11_EN_MASK,		RG_VUSB11_EN_SHIFT},                
        {RG_VCORE_VOSEL,		RG_VCORE_VOSEL_ADDR,		RG_VCORE_VOSEL_MASK,		RG_VCORE_VOSEL_SHIFT},                
	{RG_VRF18_MODESET,      RG_VRF18_MODESET_ADDR,		RG_VRF18_MODESET_MASK,		RG_VRF18_MODESET_SHIFT},
	{RG_VRF18_ON_CTRL,		RG_VRF18_ON_CTRL_ADDR,      RG_VRF18_ON_CTRL_MASK,		RG_VRF18_ON_CTRL_SHIFT},
	{RG_VRF18_EN,			RG_VRF18_EN_ADDR,      		RG_VRF18_EN_MASK,      		RG_VRF18_EN_SHIFT},
	{VRF18_srclken_sel,		VRF18_srclken_sel_ADDR,     VRF18_srclken_sel_MASK,		VRF18_srclken_sel_SHIFT},
	{RG_VRF18_2_MODESET,	RG_VRF18_2_MODESET_ADDR,	RG_VRF18_2_MODESET_MASK,	RG_VRF18_2_MODESET_SHIFT},
	{RG_VRF18_2_ON_CTRL,	RG_VRF18_2_ON_CTRL_ADDR,	RG_VRF18_2_ON_CTRL_MASK,	RG_VRF18_2_ON_CTRL_SHIFT},
	{RG_VRF18_2_EN,			RG_VRF18_2_EN_ADDR,      	RG_VRF18_2_EN_MASK,      	RG_VRF18_2_EN_SHIFT},
	{VRF18_2_srclken_sel,	VRF18_2_srclken_sel_ADDR,	VRF18_2_srclken_sel_MASK,	VRF18_2_srclken_sel_SHIFT},
	{RG_VPA_MODESET,		RG_VPA_MODESET_ADDR, 		RG_VPA_MODESET_MASK,		RG_VPA_MODESET_SHIFT},
	{VPA_VOSEL_MAP_EN,              VPA_VOSEL_MAP_EN_ADDR,          VPA_VOSEL_MAP_EN_MASK,          VPA_VOSEL_MAP_EN_SHIFT},                
	{RG_VPA_EN,				RG_VPA_EN_ADDR,      		RG_VPA_EN_MASK,				RG_VPA_EN_SHIFT},
	{VPA_VOSEL,				VPA_VOSEL_ADDR,      		VPA_VOSEL_MASK,				VPA_VOSEL_SHIFT},
	{RG_VRF18_BK_LDO,		RG_VRF18_BK_LDO_ADDR,		RG_VRF18_BK_LDO_MASK,		RG_VRF18_BK_LDO_SHIFT},
	{RG_VRF18_2_BK_LDO,		RG_VRF18_2_BK_LDO_ADDR,		RG_VRF18_2_BK_LDO_MASK,		RG_VRF18_2_BK_LDO_SHIFT},
	{RG_VSIM1_EN,			RG_VSIM1_EN_ADDR,			RG_VSIM1_EN_MASK,			RG_VSIM1_EN_SHIFT},
	{RG_VSIM2_EN,			RG_VSIM2_EN_ADDR,			RG_VSIM2_EN_MASK,			RG_VSIM2_EN_SHIFT},
	{RG_VSIM1_VOSEL,		RG_VSIM1_VOSEL_ADDR,		RG_VSIM1_VOSEL_MASK,		RG_VSIM1_VOSEL_SHIFT},
	{RG_VSIM2_VOSEL,		RG_VSIM2_VOSEL_ADDR,		RG_VSIM2_VOSEL_MASK,		RG_VSIM2_VOSEL_SHIFT},
	{RG_VSIM1_CAL,		    RG_VSIM1_CAL_ADDR,		    RG_VSIM1_CAL_MASK,		    RG_VSIM1_VOSEL_SHIFT},
	{RG_VSIM2_CAL,		    RG_VSIM2_CAL_ADDR,		    RG_VSIM2_CAL_MASK,		    RG_VSIM2_VOSEL_SHIFT},	
	{RG_VMC_VOSEL,			RG_VMC_VOSEL_ADDR,			RG_VMC_VOSEL_MASK,			RG_VMC_VOSEL_SHIFT},
	{RG_VMC_EN,				RG_VMC_EN_ADDR,				RG_VMC_EN_MASK,				RG_VMC_EN_SHIFT},
	{RG_VMCH_VOSEL,			RG_VMCH_VOSEL_ADDR,			RG_VMCH_VOSEL_MASK,			RG_VMCH_VOSEL_SHIFT},
	{RG_VMCH_EN,			RG_VMCH_EN_ADDR,			RG_VMCH_EN_MASK,			RG_VMCH_EN_SHIFT},
	{RG_VMIPI_EN,			RG_VMIPI_EN_ADDR,			RG_VMIPI_EN_MASK,			RG_VMIPI_EN_SHIFT},                
        {VPA_TABLE0,                    VPA_TABLE0_ADDR,                        VPA_TABLE0_MASK,                        VPA_TABLE0_SHIFT},
        {VPA_TABLE1,                    VPA_TABLE1_ADDR,                        VPA_TABLE1_MASK,                        VPA_TABLE1_SHIFT},
        {VPA_TABLE2,                    VPA_TABLE2_ADDR,                        VPA_TABLE2_MASK,                        VPA_TABLE2_SHIFT},
        {VPA_TABLE3,                    VPA_TABLE3_ADDR,                        VPA_TABLE3_MASK,                        VPA_TABLE3_SHIFT},
        {VPA_TABLE4,                    VPA_TABLE4_ADDR,                        VPA_TABLE4_MASK,                        VPA_TABLE4_SHIFT},
        {VPA_TABLE5,                    VPA_TABLE5_ADDR,                        VPA_TABLE5_MASK,                        VPA_TABLE5_SHIFT},
        {VPA_TABLE6,                    VPA_TABLE6_ADDR,                        VPA_TABLE6_MASK,                        VPA_TABLE6_SHIFT},
        {VPA_TABLE7,                    VPA_TABLE7_ADDR,                        VPA_TABLE7_MASK,                        VPA_TABLE7_SHIFT},                
        {VPA_MAP_SEL,			VPA_MAP_SEL_ADDR,			VPA_MAP_SEL_MASK,			VPA_MAP_SEL_SHIFT},                              
};

//////////////////////////////////////////////////
//                  WRITE APIs                  //
//////////////////////////////////////////////////
// Write Whole Bytes
static void dcl_pmic6339_write_reg(DCL_UINT8 addr, DCL_UINT16 val)
{
	drv_bsi_pmic6339_reg_write(addr,val);
    #ifdef PMIC_6339_DEBUG
	pmic6339_reg[addr]=val;
	#endif
}

//////////////////////////////////////////////////
//                  READ APIs                   //
//////////////////////////////////////////////////

// Read Whole Bytes
static DCL_UINT16 dcl_pmic6339_read_reg(DCL_UINT8 addr)
{
	kal_uint16 val;
	val=drv_bsi_pmic6339_reg_read(addr);
	#ifdef PMIC_6339_DEBUG
	pmic6339_reg[addr]=val;
	#endif
    return val;
}

// Write register field
static void dcl_pmic6339_field_write(PMU_FLAGS_LIST_ENUM flag, kal_uint16 sel)
{
	kal_uint32 i, table_size = 0,mask;
	kal_uint16 val;

	table_size = GETARRNUM(pmic_flags_table);
	for (i = 0; i < table_size; i++)
	{
		if (flag == pmic_flags_table[i].flagname)
		{
			break;
		}
	}
	if (i >= table_size){ ASSERT(0); }// Flag Unknown
	
	mask=SaveAndSetIRQMask();
	val=dcl_pmic6339_read_reg(pmic_flags_table[i].offset)&(~(pmic_flags_table[i].mask));
	val|=(sel<<pmic_flags_table[i].shift)&pmic_flags_table[i].mask;
	dcl_pmic6339_write_reg(pmic_flags_table[i].offset,val);
	RestoreIRQMask(mask);
	return;
}
DCL_STATUS PMIC6339_control_handler(DCL_HANDLE handle,DCL_CTRL_CMD cmd,DCL_CTRL_DATA_T *data)
{
	DCL_UINT16	regVal;
	DCL_INT32	return_val = STATUS_FAIL;
	switch(cmd)
    {
    	case LDO_BUCK_SET_EN:
        {
            PMU_CTRL_LDO_BUCK_SET_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetEn);

            switch(pLdoBuckCtrl->mod)
            {
				case VRF18:
				{
					dcl_pmic6339_field_write(RG_VRF18_EN, pLdoBuckCtrl->enable);
					return_val = STATUS_OK;
				}
				break;
				case VRF18_2:
				{
					dcl_pmic6339_field_write(RG_VRF18_2_EN, pLdoBuckCtrl->enable);
					return_val = STATUS_OK;
				}
				break;
                case VSIM:
				{
					dcl_pmic6339_field_write(RG_VSIM1_EN, pLdoBuckCtrl->enable);
					return_val = STATUS_OK;
				}
                break;
                case VSIM2:
                {
					dcl_pmic6339_field_write(RG_VSIM2_EN, pLdoBuckCtrl->enable);
					return_val = STATUS_OK;
				}
                break;
				case VMC:
				{
					dcl_pmic6339_field_write(RG_VMC_EN, pLdoBuckCtrl->enable);
					return_val = STATUS_OK;
				}
				break;
				case VMCH:
				{
					dcl_pmic6339_field_write(RG_VMCH_EN, pLdoBuckCtrl->enable);
					return_val = STATUS_OK;
				}
				break;
				case VMIPI:
				{
					dcl_pmic6339_field_write(RG_VMIPI_EN, pLdoBuckCtrl->enable);
					return_val = STATUS_OK;
				}
				break;                                
				default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;
        case LDO_BUCK_SET_VOLTAGE:
        {
            PMU_CTRL_LDO_BUCK_SET_VOLTAGE *pLdoBuckCtrl = &(data->rPMULdoBuckSetVoltage);
            regVal = PMU_Parameter_to_Value(ENC(cmd, pLdoBuckCtrl->mod), pLdoBuckCtrl->voltage);
            switch(pLdoBuckCtrl->mod)
            {
                case VIO28:
                {
                    dcl_pmic6339_field_write(RG_VIO28_VOSEL, regVal);
                    return_val = STATUS_OK;
                }
                break;    
                case VCORE:
                {
                    dcl_pmic6339_field_write(RG_VCORE_VOSEL, regVal);
                    return_val = STATUS_OK;
                }
                break;                      
                case VSIM:
                {
                    kal_uint32 cal_value = 0;
                    // This for MT6290 Rio-5 FTA 5.1.3 Failed Workaround
                    // Add 1.06V Output
                    if(regVal == 8)
                    {
                        regVal = 0; // 1.2V
                        cal_value = 0x7; // -140mV
                    }
                    else
                    {
                        cal_value = 0; // 0mV
                    }
                    dcl_pmic6339_field_write(RG_VSIM1_CAL, cal_value);                       
                    dcl_pmic6339_field_write(RG_VSIM1_VOSEL, regVal);
                    return_val = STATUS_OK;
                }
                break;
                case VSIM2:
                {
                    kal_uint32 cal_value = 0;
                    // This for MT6290 Rio-5 FTA 5.1.3 Failed Workaround
                    // Add 1.06V Output
                    if(regVal == 8)
                    {
                        regVal = 0; // 1.2V
                        cal_value = 0x7; // -140mV
                    }
                    else
                    {
                        cal_value = 0; // 0mV
                    }  
                    dcl_pmic6339_field_write(RG_VSIM2_CAL, cal_value);                  
                    dcl_pmic6339_field_write(RG_VSIM2_VOSEL, regVal);
                    return_val = STATUS_OK;
                }
                break;
		case VMC:
                {
                    dcl_pmic6339_field_write(RG_VMC_VOSEL, regVal);
                    return_val = STATUS_OK;
                }
                break;
		case VMCH:
                {
                    dcl_pmic6339_field_write(RG_VMCH_VOSEL, regVal);
                    return_val = STATUS_OK;
                }
                break;
                case VPA:
                {
                    dcl_pmic6339_field_write(VPA_VOSEL, regVal);
                    return_val = STATUS_OK;
                }
                break;                
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;
        case VRF18_SET_BUCK_LDO_MODE:
        {
        	PMU_CTRL_VRF18_SET_BUCK_LDO_MODE *pVrf18Ctrl = &(data->rPMUVrf18SetBuckLdoMode);
			switch(pVrf18Ctrl->vrf18Idx)
			{
				case PMIC_VRF18_1:
				{
                    dcl_pmic6339_field_write(RG_VRF18_BK_LDO, pVrf18Ctrl->mode);
                    return_val = STATUS_OK;
				}
				break;
				case PMIC_VRF18_2:
				{
					dcl_pmic6339_field_write(RG_VRF18_2_BK_LDO, pVrf18Ctrl->mode);
                    return_val = STATUS_OK;
				}
				break;
				default:
				return_val = STATUS_UNSUPPORTED;
				break;
			}
        }
        break;
		case VRF18_SET_FPWM:
		{
			PMU_CTRL_VRF18_SET_FPWM *pVrf18SetFpwm = (PMU_CTRL_VRF18_SET_FPWM *)data;
			dcl_pmic6339_field_write(RG_VRF18_MODESET, pVrf18SetFpwm->enable);
			return_val = STATUS_OK;
		}
		break;
		case VRF18_2_SET_FPWM:
		{
			PMU_CTRL_VRF18_SET_FPWM *pVrf18SetFpwm = (PMU_CTRL_VRF18_SET_FPWM *)data;
			dcl_pmic6339_field_write(RG_VRF18_2_MODESET, pVrf18SetFpwm->enable);
			return_val = STATUS_OK;
		}
		break;
        case VPA_SET_FPWM:
        {
            PMU_CTRL_VPA_SET_FPWM *pVpaSetFpwm = (PMU_CTRL_VPA_SET_FPWM *)data;
            dcl_pmic6339_field_write(RG_VPA_MODESET, pVpaSetFpwm->enable);
            return_val = STATUS_OK;
        }
        break;
        case LDO_BUCK_SET_ON_SEL:
        {
            PMU_CTRL_LDO_BUCK_SET_ON_SEL *pLdoBuckCtrl=&(data->rPMULdoBuckSetOnSel);
            switch(pLdoBuckCtrl->mod)
            {
                case VRF18:
                {
                	// ENABLE_WITH_SRCLKEN = 0, but 6329 SRCLKEN = 1, therefore we need NOT pLdoBuckCtrl->onsel
                    dcl_pmic6339_field_write(RG_VRF18_ON_CTRL, !(pLdoBuckCtrl->onSel));
					return_val = STATUS_OK;
                }
                break;
                case VRF18_2:
                {
                	// ENABLE_WITH_SRCLKEN = 0, but 6329 SRCLKEN = 1, therefore we need NOT pLdoBuckCtrl->onsel
                    dcl_pmic6339_field_write(RG_VRF18_2_ON_CTRL, !(pLdoBuckCtrl->onSel));
					return_val = STATUS_OK;
                }
                break;
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;
        case LDO_BUCK_SET_SRCLKEN_SEL:
        {
			PMU_CTRL_LDO_BUCK_SET_SRCLKEN_SEL *pLdoBuckCtrl=&(data->rPMULdoBuckSetSrclkenSel);
            switch(pLdoBuckCtrl->mod)
            {
                case VRF18:
                {
					dcl_pmic6339_field_write(VRF18_srclken_sel, pLdoBuckCtrl->SrclkenSel);
                    return_val = STATUS_OK;
                }
                break;
                case VRF18_2:
                {
					dcl_pmic6339_field_write(VRF18_2_srclken_sel, pLdoBuckCtrl->SrclkenSel);
                    return_val = STATUS_OK;
                }
                break;
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;
        case VPA_SET_EN:
		{
			PMU_CTRL_VPA_SET_EN *pVpaCtrl = &(data->rPMUVpaSetEn);
			dcl_pmic6339_field_write(RG_VPA_EN, pVpaCtrl->enable);
                        return_val = STATUS_OK;
		}
		break;
        case VPA_SET_VOSEL_MAP_EN:
                {
                        PMU_CTRL_VPA_SET_VOSEL_MAP_EN *pVpaCtrl = &(data->rPMUVpaSetVoselMapEn);
        		dcl_pmic6339_field_write(VPA_VOSEL_MAP_EN, pVpaCtrl->enable);
                        return_val = STATUS_OK;
                }
        break;
                
	case VPA_GET_VOLTAGE_LIST:
		{
			PMU_CTRL_VPA_GET_VOLTAGE_LIST *pVpaCtrl = &(data->rPMUVpaGetVoltageList);
			pVpaCtrl->pVoltageList = vpa_vosel;
			pVpaCtrl->number = GETARRNUM(vpa_vosel);			
                        return_val = STATUS_OK;
		}
	break;   
        case VPA_SET_VOLTAGE_SELECTION_TABLE:
        {
                PMU_CTRL_VPA_SET_VOLTAGE_SELECTION_TABLE *pVpaCtrl = &(data->rPMUVpaSetVoltageSelectionTable);
                regVal = PMU_Parameter_to_Value(ENC(VPA_SET_VOLTAGE_SELECTION_TABLE, VPA), pVpaCtrl->voltage);                
                switch(pVpaCtrl->table_entry)
                {
                        case PMU_VPA0:
                        {
                                dcl_pmic6339_field_write(VPA_TABLE0, regVal);
                        	return_val = STATUS_OK;
                        }
                        break;
                        case PMU_VPA1:
                        {
                                dcl_pmic6339_field_write(VPA_TABLE1, regVal);
                        	return_val = STATUS_OK;
                        }
                        break;
                        case PMU_VPA2:
                        {
                                dcl_pmic6339_field_write(VPA_TABLE2, regVal);
                        	return_val = STATUS_OK;
                        }
                        break;

                        case PMU_VPA3:
                        {
                                dcl_pmic6339_field_write(VPA_TABLE3, regVal);
                        	return_val = STATUS_OK;
                        }

                        break;                        
                        case PMU_VPA4:
                        {
                                dcl_pmic6339_field_write(VPA_TABLE4, regVal);
                        	return_val = STATUS_OK;
                        }
                        break;
                        case PMU_VPA5:
                        {
                                dcl_pmic6339_field_write(VPA_TABLE5, regVal);
                        	return_val = STATUS_OK;
                        }
                        break;
                        case PMU_VPA6:
                        {
                                dcl_pmic6339_field_write(VPA_TABLE6, regVal);
                        	return_val = STATUS_OK;
                        }
                        break;
                        case PMU_VPA7:
                        {
                                dcl_pmic6339_field_write(VPA_TABLE7, regVal);
                        	return_val = STATUS_OK;
                        }
                        break;                        

                        default:
                                return_val = STATUS_UNSUPPORTED;
                        break;
                }                

        }
        break;

        case VPA_SET_MAP_SEL:
                {
                        PMU_CTRL_VPA_SET_MAP_SEL *pVpaCtrl = &(data->rPMUVpaSetMapSel);
                        dcl_pmic6339_field_write(VPA_MAP_SEL, pVpaCtrl->table_entry);
                }
        break;

        
/*		case VPA_SET_VOLTAGE: // VPA voltage will be auto set by HW, this command is not necessary for HW driver
		{		
			PMU_CTRL_VPA_SET_VOLTAGE *pVpaCtrl = &(data->rPMUVpaSetVoltage);
			
			regVal = PMU_Parameter_to_Value(ENC(cmd,0), pVpaCtrl->voltage);
			dcl_pmic6339_field_write(VPA_VOSEL, regVal);
		}
		break;*/
        case MISC_GET_CID:
        {			
            PMU_CTRL_MISC_GET_CID	*pMiscCtrl = &(data->rPMUMiscGetCid);
            pMiscCtrl->cid_value = pmic_CID0;
            return_val = STATUS_OK;
        }
        break;
        
        case MISC_GET_ECO_VERSION:
        {			
            PMU_CTRL_MISC_GET_ECO_VERSION *pMiscCtrl = &(data->rPMUMiscGetEcoVersion);
            pMiscCtrl->eco_version = pmic_ECO_VERSION;
            return_val = STATUS_OK;
        }
        break;
        
        case MISC_SET_REGISTER_VALUE:
        {			
            PMU_CTRL_MISC_SET_REGISTER_VALUE	*pChrCtrl = &(data->rPMUMiscSetRegisterValue);
            dcl_pmic6339_write_reg(pChrCtrl->offset, pChrCtrl->value);
            return_val = STATUS_OK;
        }
        break;
        
        case MISC_GET_REGISTER_VALUE:
        {
            PMU_CTRL_MISC_GET_REGISTER_VALUE	*pChrCtrl=&(data->rPMUMiscGetRegisterValue);
            pChrCtrl->value = dcl_pmic6339_read_reg(pChrCtrl->offset);
            return_val = STATUS_OK;
        }
        break;		
        default:				
            return_val = STATUS_UNSUPPORTED;
        break;
    }
	return return_val;

}

// extern void dcl_pmic6339_internal_init(void); // Move to bootloader
extern void pmu_drv_tool_customization_init(void);
extern void PMIC_Read_All(void);
extern void PMIC_VCORE_INIT(kal_uint32 value, kal_uint32 ver);

extern PMU_CONTROL_HANDLER pmu_control_handler;
//DCL_UINT16 pmu_parameter_size=0;

void dcl_pmic6339_init(void){
	static kal_uint8 pmic6339_init=0;
	if(0==pmic6339_init){
		pmu_control_handler = PMIC6339_control_handler;
		pmu_parameter_size = GETARRNUM(pmu_parameter_table);
		pmic6339_init=1;
		drv_bsi_pmic_init();//init BSI
		pmic_CID0 = dcl_pmic6339_read_reg(CID0_ADDR);
		pmic_ECO_VERSION = dcl_pmic6339_read_reg(ECO_VERSION_ADDR);
                if(pmic_ECO_VERSION == 0x01)
                {
                    // Turn on VIO28_EN as long as E1.
                    dcl_pmic6339_field_write(RG_VIO28_EN, 0x01);
                }
#if defined(PMIC_INIT_PHONE)
#if !defined(MT6290M_SP_BB) && !defined(MT6290ME2_SP)
                // Turn off VUSB11 for Custom Phone Project
                dcl_pmic6339_field_write(RG_VUSB11_EN, 0x00);
#endif
#endif
                // dcl_pmic6339_internal_init(); // Move to bootloader
//		pmic6339_customization_init();
		pmu_drv_tool_customization_init();
		#ifdef PMIC_6339_DEBUG
		{
			kal_uint32 i;
			for (i = 0;i < PMIC_MAX_REG_NUM;i++){
				pmic6339_reg[i] = dcl_pmic6339_read_reg(i); 
		    }
		}
		#endif
    }
}


void PMIC_Read_All(void)
{
    volatile kal_uint32 i;
    for (i = 0; i < PMIC_MAX_REG_NUM; i++){
        pmic6339_reg[i] = dcl_pmic6339_read_reg(i); 
    }
}
#if defined(MT6290_DEMO_BB) || defined(MT6290M_DEMO_BB) || defined(MT6290E2_EVB) || defined(MT6290ME2_EVB) // EVB
void PMIC_VCORE_INIT(kal_uint32 value, kal_uint32 ver)
{
    value = 0;
    ver = 0;
}
#else
extern const char EXTbuck_i2cdev_exist;
void PMIC_VCORE_INIT(kal_uint32 value, kal_uint32 ver)
{
#include "i2c_pmic.h"
extern kal_bool extbuck_6335_exist(void);                        
extern kal_bool extbuck_53555_exist(void);

#define NCP6335_SLAVE_ADDR      0x1C
#define FAN53555_SLAVE_ADDR     0x60

#define FAN53555UC08X_PID 	0x88
#define FAN53555UC09X_PID	0x8C
#define NCP6335G            0x10
#define NCP6335D            0x10

        kal_uint32 sts_ncp6335 = 0xFFFF;
    	kal_uint32 sts_fan53555 = 0xFFFF;
        int gpio15;
        GPIO_CTRL_READ_T data;
        DCL_HANDLE handle = DclGPIO_Open(DCL_GPIO, EXTbuck_i2cdev_exist & (~0x80));
        DclGPIO_Control(handle, GPIO_CMD_READ, (DCL_CTRL_DATA_T *)&data);
        gpio15 = data.u1IOData;
        
        // 判斷完就拉到High, 以免漏電
        if(gpio15 == 1) 
        {
            DclGPIO_Control(handle,GPIO_CMD_SET_PULL_HIGH, (DCL_CTRL_DATA_T *)&data);
        }
        /* read NCP6335 reg 0*/
        sts_ncp6335 = extbuck_6335_exist();
	if(sts_ncp6335 != NCP6335G)
	{
            sts_fan53555 = extbuck_53555_exist();
	}
        if (sts_ncp6335 == KAL_FALSE && sts_fan53555 == KAL_FALSE)  
        {
            /* 
             * Error Handing.
             * 例如 如果是ACK_ERR , 可以再讀一次double check 一下 ， 如果還是KAL_FALSE , 可認為 slave 不存在
            */
            sts_ncp6335 = extbuck_6335_exist();
	    if(sts_ncp6335 != NCP6335G)
	    {
                sts_fan53555 = extbuck_53555_exist();
            }
            if (sts_ncp6335 == KAL_FALSE && sts_fan53555 == KAL_FALSE)   
            {
                if(ver == 1 && gpio15 == 1)
                {
                    // If we use External LDO, should not get KAL_FALSE
                    ASSERT(0);
                }
                else
                { 
                    // Both NCP6335 & FAN53555 are Not Exist
                    switch(value)
                    {
                        case 0:
                        case 1:
                            dcl_pmic6339_write_reg(0x65, 0x09); // 1.05V
                            break;
                        case 2:
                        case 3:
                            dcl_pmic6339_write_reg(0x65, 0x0A); // 1.0V
                            break;
                        default:
                            break;
                    }
                }
            }
            else
            {
                ASSERT(0);
            }    
        }
        else if(sts_fan53555 == FAN53555UC08X_PID || sts_fan53555 == FAN53555UC09X_PID)
        {
	    if(sts_fan53555 == FAN53555UC08X_PID) // 0x88
	    {
                // FAN53555 Exist
                // 1.05V, Depend on binning IC E-fuse
                i2c_pmic_reg_write(FAN53555_SLAVE_ADDR, 0x01, 0xAD);
                // 0.85V, initial setting
                i2c_pmic_reg_write(FAN53555_SLAVE_ADDR, 0x00, 0x99);
                // Common register initial
                i2c_pmic_reg_write(FAN53555_SLAVE_ADDR, 0x02, 0xA0);
                switch(value)
                {
                    case 0:
                    case 1:
                        i2c_pmic_reg_write(FAN53555_SLAVE_ADDR, 0x01, 0xAD); // 1.05V
                        dcl_pmic6339_write_reg(0x65, 0x09); // 1.05V
                        dcl_pmic6339_write_reg(0x63, 0x00); // Shutdown VCORE
                        break;
                    case 2:
                    case 3:
                        i2c_pmic_reg_write(FAN53555_SLAVE_ADDR, 0x01, 0xA8); // 1.00V
                        dcl_pmic6339_write_reg(0x65, 0x0A); // 1.0V
                        dcl_pmic6339_write_reg(0x63, 0x00); // Shutdown VCORE
                        break;
                    default:
                        break;
	        }   
	    }
            else if(sts_fan53555 == FAN53555UC09X_PID) // 0x8C
	    {
                // FAN53555 Exist
                // 1.05V, Depend on binning IC E-fuse
                i2c_pmic_reg_write(FAN53555_SLAVE_ADDR, 0x01, 0xA3);
                // 0.85V, initial setting
                i2c_pmic_reg_write(FAN53555_SLAVE_ADDR, 0x00, 0x94);
                // Common register initial
                i2c_pmic_reg_write(FAN53555_SLAVE_ADDR, 0x02, 0xA0);
                switch(value)
                {
                    case 0:
                    case 1:
                        i2c_pmic_reg_write(FAN53555_SLAVE_ADDR, 0x01, 0xA3); // 1.05V
                        dcl_pmic6339_write_reg(0x65, 0x09); // 1.05V
                        dcl_pmic6339_write_reg(0x63, 0x00); // Shutdown VCORE
                        break;
                    case 2:
                    case 3:
                        i2c_pmic_reg_write(FAN53555_SLAVE_ADDR, 0x01, 0x9F); // 1.00V
                        dcl_pmic6339_write_reg(0x65, 0x0A); // 1.0V
                        dcl_pmic6339_write_reg(0x63, 0x00); // Shutdown VCORE
                        break;
                    default:
                        break;         
	        }
	    }
	}
	else if(sts_ncp6335 == NCP6335G)
        {
	    kal_uint8 readback_value = 0;
            // NCP6335 Exist
            BL_PRINT(LOG_DEBUG,"NCP6335 EXIST");
            // 1.05V, Depend on binning IC E-fuse
            i2c_pmic_reg_write(NCP6335_SLAVE_ADDR, 0x10, 0xC8);
	    i2c_pmic_reg_read(NCP6335_SLAVE_ADDR, 0x10, &readback_value);
            BL_PRINT(LOG_DEBUG,"ncp6335 write reg[%x] = %x", 0x10, readback_value);
            // 0.85V, initial setting
            i2c_pmic_reg_write(NCP6335_SLAVE_ADDR, 0x11, 0xA8);
            i2c_pmic_reg_read(NCP6335_SLAVE_ADDR, 0x11, &readback_value);
            BL_PRINT(LOG_DEBUG,"ncp6335 write reg[%x] = %x", 0x11, readback_value);
            // Common register initial
            i2c_pmic_reg_write(NCP6335_SLAVE_ADDR, 0x14, 0x01);
	    i2c_pmic_reg_read(NCP6335_SLAVE_ADDR, 0x14, &readback_value);
            BL_PRINT(LOG_DEBUG,"ncp6335 write reg[%x] = %x", 0x14, readback_value);
            i2c_pmic_reg_write(NCP6335_SLAVE_ADDR, 0x13, 0x19);
	    i2c_pmic_reg_read(NCP6335_SLAVE_ADDR, 0x13, &readback_value);
            BL_PRINT(LOG_DEBUG,"ncp6335 write reg[%x] = %x", 0x13, readback_value);
            switch(value)
            {
                case 0:
                case 1:
                    i2c_pmic_reg_write(NCP6335_SLAVE_ADDR, 0x10, 0xC8); // 1.05V
	            i2c_pmic_reg_read(NCP6335_SLAVE_ADDR, 0x10, &readback_value);
                    BL_PRINT(LOG_DEBUG,"ncp6335 write reg[%x] = %x", 0x10, readback_value);
                    dcl_pmic6339_write_reg(0x65, 0x09); // 1.05V
                    dcl_pmic6339_write_reg(0x63, 0x00); // Shutdown VCORE
                    break;
                case 2:
                case 3:
                    i2c_pmic_reg_write(NCP6335_SLAVE_ADDR, 0x10, 0xC0); // 1.00V
	            i2c_pmic_reg_read(NCP6335_SLAVE_ADDR, 0x10, &readback_value);
                    BL_PRINT(LOG_DEBUG,"ncp6335 write reg[%x] = %x", 0x10, readback_value);
                    dcl_pmic6339_write_reg(0x65, 0x0A); // 1.0V
                    dcl_pmic6339_write_reg(0x63, 0x00); // Shutdown VCORE
                    break;
                default:
                    break;         
            }
        }

}
#endif // End of #if defined(MT6290_DEMO_BB) || defined(MT6290M_DEMO_BB) || defined(MT6290E2_EVB) || defined(MT6290ME2_EVB) // EVB