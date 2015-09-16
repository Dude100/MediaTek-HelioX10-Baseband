
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
 *    dcl_pmu6573.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMU6573
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "reg_base.h"
#include "drv_comm.h"
#include "init.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"

#if (defined(PMIC_6573_REG_API))

extern PMU_CONTROL_HANDLER pmu_control_handler;
DCL_UINT16 pmu_parameter_size=0;

PMU_MOD_BASEADDR_ENTRY pmu_ldo_bb_profile[]=
{
    {VRF28,  		VRF_CON0},
    {VTCXO,  		VTCXO_CON0},
    {VSIM,  		VSIM_CON0},
    {VSIM2,  		VSIM2_CON0},
    {VRF18,	 	VRF18_CON0}
};

DCL_UINT16 pmu_ldo_bb_size;
DCL_UINT8 pmuModtoIdx[PMU_LDO_BUCK_MAX];

PMU_MOD_BASEADDR_ENTRY pmu_vpa_profile[]=
{
    {VPA1,  		VPA_CON0}
};

DCL_UINT32 vsim_vosel[]=
{
	PMU_VOLT_01_800000_V,PMU_VOLT_03_000000_V
};


DCL_UINT32 vsim2_vosel[]=
{
	PMU_VOLT_01_300000_V,PMU_VOLT_01_500000_V,PMU_VOLT_01_800000_V,PMU_VOLT_02_500000_V,
	PMU_VOLT_02_800000_V,PMU_VOLT_03_000000_V,PMU_VOLT_03_300000_V
};

DCL_UINT32 vrf18_vosel[]=
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

PMU_PARAMETER_TABLE_ENTRY pmu_parameter_table[]=
{
	//LDO/BUCK
	{ENC(LDO_BUCK_SET_VOLTAGE,VSIM),				vsim_vosel,			NULL,				GETARRNUM(vsim_vosel)		},
	{ENC(LDO_BUCK_SET_VOLTAGE,VSIM2),				vsim2_vosel,		NULL,				GETARRNUM(vsim2_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,VRF18),				vrf18_vosel,			NULL,				GETARRNUM(vrf18_vosel)		},
	{ENC(LDO_BUCK_SET_SLEEP_VOLTAGE,VRF18),		vrf18_vosel,			NULL,				GETARRNUM(vrf18_vosel)		},
	//VPA group
	{ENC(VPA_SET_VOLTAGE,ALLMOD),					vpa_votune,			NULL,				GETARRNUM(vpa_votune)		}
};

#if defined(__MT6573PMU_E1_VSIM2_VOLSEL_ISSUE__)
#define MT6573PMU_E1_VSIM2_VOLSEL_REG_ADDR       MIX_PMU_base + 0x70C
#define MT6573PMU_E1_VSIM2_VOLSEL_MASK           0x0007
#define MT6573PMU_E1_VSIM2_VOLSEL_SHIFT          0
void pmu6573_vsim2_vol_sel(kal_uint8 vol_val)
{
	kal_uint32 savedMask;

	// The workaround is only applied in E1
	if (INT_ecoVersion() == ECO_E1)
	{

		savedMask = PMU_SaveAndSetIRQMask();
		PMU_DRV_SetData16((MT6573PMU_E1_VSIM2_VOLSEL_REG_ADDR),
	                   	MT6573PMU_E1_VSIM2_VOLSEL_MASK, ((kal_uint16)vol_val << MT6573PMU_E1_VSIM2_VOLSEL_SHIFT));
		PMU_RestoreIRQMask(savedMask);
	}
}
#endif // #if defined(__MT6573PMU_E1_VSIM2_VOLSEL_ISSUE__)

DCL_STATUS dcl_pmu6573_control_handler(DCL_HANDLE handle,DCL_CTRL_CMD cmd,DCL_CTRL_DATA_T *data)
{
	DCL_UINT16	regVal;

	switch(cmd)
	{
		//LDO,BUCK
		case LDO_BUCK_SET_EN:
		{
			PMU_CTRL_LDO_BUCK_SET_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetEn);
			PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(pLdoBuckCtrl->mod)];
			switch(pLdoBuckCtrl->mod)
			{
				case VTCXO:
				case VRF:		
				case VSIM:					
				case VSIM2:					
				case VRF18:
				{
					PMU_CTRL_LDO_BUCK_SET_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetEn);
					PMU_SetData16((pEntry->addr+BUCK_EN_OFFSET),BUCK_EN_MASK,
						((DCL_UINT16)pLdoBuckCtrl->enable << BUCK_EN_SHIFT));					
				}
				break;			
				default:				
				return STATUS_UNSUPPORTED;
				break;			
			}
		}
		break;	
		case LDO_BUCK_SET_VOLTAGE:
		{
			PMU_CTRL_LDO_BUCK_SET_VOLTAGE *pLdoBuckCtrl=&(data->rPMULdoBuckSetVoltage);	
			
			switch(pLdoBuckCtrl->mod)
			{
	
				case VSIM2:
				case VSIM:				
				case VRF18:
				{
					PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(pLdoBuckCtrl->mod)];
					regVal=PMU_Parameter_to_Value(ENC(cmd,pLdoBuckCtrl->mod),pLdoBuckCtrl->voltage);
					if (regVal==PARAMETER_UNKNOWN)
						ASSERT(0);			

					#if defined(__MT6573PMU_E1_VSIM2_VOLSEL_ISSUE__)
					if(pLdoBuckCtrl->mod==VSIM2)
						pmu6573_vsim2_vol_sel(regVal);	
					#endif // #if defined(__MT6276PMU_E1_VSIM2_VOLSEL_ISSUE__)	
					
					PMU_SetData16((pEntry->addr+BUCK_VFBADJ_OFFSET),
				                    BUCK_VFBADJ_MASK, ((DCL_UINT16)regVal << BUCK_VFBADJ_SHIFT));
				}
				break;			
				default:				
				return STATUS_UNSUPPORTED;
				break;			
			}			
		}
		break;	
		case LDO_BUCK_SET_SLEEP_VOLTAGE:
		{
			PMU_CTRL_LDO_BUCK_SET_SLEEP_VOLTAGE *pLdoBuckCtrl=&(data->rPMULdoBuckSetSleepVoltage);	
			PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(pLdoBuckCtrl->mod)];
			if (pLdoBuckCtrl->mod!=VRF18)
				return STATUS_UNSUPPORTED;
			
			regVal=PMU_Parameter_to_Value(ENC(cmd,pLdoBuckCtrl->mod),pLdoBuckCtrl->sleepVoltage);
			if (regVal==PARAMETER_UNKNOWN)
				ASSERT(0);
			
				PMU_SetData16((pEntry->addr+BUCK_VFBADJ_SLEEP_OFFSET),
	                    				BUCK_VFBADJ_SLEEP_MASK, ((DCL_UINT16)regVal << BUCK_VFBADJ_SLEEP_SHIFT));
		}		
		break;		
		case VPA_SET_EN:
		{
                       	PMU_CTRL_VPA_SET_EN *pVpaCtrl=&(data->rPMUVpaSetEn);
#if defined(MT6573_S00)			
/*
;enable VPA=3.4V
D.S SD:0x7002F100 %LE %WORD 0x1000
D.S SD:0x7002F104 %LE %WORD 0x408A
D.S SD:0x7002F108 %LE %WORD 0xcc02
D.S SD:0x7002FB00 %LE %WORD 0x1000
VPA voltage
D.S SD:0x7002FB08 %LE %WORD 0x0019
*/

			PMU_DRV_WriteReg16(MIX_PMU_base + 0x100,0x1000);
			PMU_DRV_WriteReg16(MIX_PMU_base + 0x104,0x408A);
			PMU_DRV_WriteReg16(MIX_PMU_base + 0x108,0xcc02);
			if (pVpaCtrl->enable==DCL_TRUE)
				PMU_DRV_WriteReg16(MIX_PMU_base + 0xB00,0x1000);
			else
				PMU_DRV_WriteReg16(MIX_PMU_base + 0xB00,0x0000);
#else
			if (pVpaCtrl->enable==DCL_TRUE)
				{PMU_DRV_SetData16(MIX_PMU_base + 0xB00,0x1000,0x1000);}
			else
				{PMU_DRV_SetData16(MIX_PMU_base + 0xB00,0x1000,0x0000);}
						
#endif // 	#if defined(MT6573_S00)						
		}
		break;
		case VPA_SET_VOLTAGE:
		{
			PMU_CTRL_VPA_SET_VOLTAGE *pVpaCtrl=&(data->rPMUVpaSetVoltage);
			return vpa_set_votune(pVpaCtrl->vpa, pVpaCtrl->vpaIdx,pVpaCtrl->voltage);
		}
		break;
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
				PMU_DRV_SetData16(MIX_PMU_base + 0xB04, 0x0100, 0x0100);
			}
			else
			{
				PMU_DRV_SetData16(MIX_PMU_base + 0xB04, 0x0100, 0x0000);
			}
		}
		break;			
		default:				
		return STATUS_UNSUPPORTED;
		break;
	}	

	return STATUS_OK;

}	

void initLdoBuckMapping(void)
{
	DCL_UINT16 i,j,size=pmu_ldo_bb_size;

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

void dcl_pmu6573_init(void)
{
	pmu_control_handler=dcl_pmu6573_control_handler;
	pmu_parameter_size=GETARRNUM(pmu_parameter_table);	

	pmu_ldo_bb_size=GETARRNUM(pmu_ldo_bb_profile);

	initLdoBuckMapping();

#if !defined(__SMART_PHONE_MODEM__) 
#if !defined(MT6573_S00)
	//LPOSC
	PMU_DRV_SetData16(MIX_PMU_base + 0x100, 0x0700, 1<<8);
	PMU_DRV_SetData16(MIX_PMU_base + 0x104, 0x3000, 2<<12);
	PMU_DRV_SetData16(MIX_PMU_base + 0x104, 0x0700, 3<<8);
	PMU_DRV_SetData16(MIX_PMU_base + 0x108, 0x0007, 2);
	PMU_DRV_SetData16(MIX_PMU_base + 0x114, 0x0100, 0<<8);
	PMU_DRV_SetData16(MIX_PMU_base + 0xe88, 0x0080, 1<<7);
	PMU_DRV_SetData16(MIX_PMU_base + 0x108, 0x0800, 1<<11);
	PMU_DRV_SetData16(MIX_PMU_base + 0x100, 0x1000, 0);

	//VPA
	PMU_DRV_SetData16(MIX_PMU_base + 0xb00, 0x0700, 4<<8);
	PMU_DRV_SetData16(MIX_PMU_base + 0xb00, 0x000c, 2<<2);
	PMU_DRV_SetData16(MIX_PMU_base + 0xb00, 0x0003, 0<<0);
	PMU_DRV_SetData16(MIX_PMU_base + 0xb04, 0x0100, 1<<8);
#endif //#if !defined(MT6573_S00)
#endif //#if defined(__SMART_PHONE_MODEM__) 

}

#endif //#if (defined(PMIC_6573_REG_API))


