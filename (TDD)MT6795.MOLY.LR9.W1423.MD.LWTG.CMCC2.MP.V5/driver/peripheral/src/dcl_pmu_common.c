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
 *    dcl_pmu_common.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module is for PMU common functions
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

#if defined(FPGA_CTP)
#include <common.h>
#endif

#include "drv_comm.h"
#include "reg_base.h"
#include "init.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"
#include "kal_public_api.h"

extern PMU_MOD_BASEADDR_ENTRY pmu_ldo_bb_profile[];
extern DCL_UINT8 pmuModtoIdx[];

extern PMU_PARAMETER_TABLE_ENTRY pmu_parameter_table[];
extern DCL_UINT16 pmu_parameter_size;

#if defined(PMIC_PRESENT)
DCL_UINT16 PMU_get_Parameter_Idx(DCL_CTRL_CMD cmd)
{
	PMU_PARAMETER_TABLE_ENTRY *ptable = pmu_parameter_table;
	DCL_UINT32 i,size = pmu_parameter_size;
	
	for(i = 0;i < size;i++)
	{
		if ((ptable[i].cmd & MODMASK) == ALLMOD)
		{
			if((ptable[i].cmd & CMDMASK) == (cmd & CMDMASK))
				break;
		}
		else
		{
			if (ptable[i].cmd == (DCL_UINT32)cmd)
				break;
		}
	}

	if (i >= size)
		return PARAMETER_UNKNOWN;

	return i;
}

DCL_UINT16 PMU_Parameter_to_Value(DCL_CTRL_CMD cmd,DCL_UINT32 val)
{
	PMU_PARAMETER_TABLE_ENTRY *ptable;
	DCL_UINT32 *parameter;
	DCL_UINT16 *pval;
	DCL_UINT32 idx,i,size = pmu_parameter_size;

	idx = PMU_get_Parameter_Idx(cmd);

	//沒有這組設定值
	if (idx ==PARAMETER_UNKNOWN)
		return PARAMETER_UNKNOWN;

	ptable = &pmu_parameter_table[idx];

	
	parameter = (DCL_UINT32 *)ptable->pVals;
	size = ptable->size;

	for(i = 0;i < size;i++)
	{
		if (val == parameter[i])
		{
			if (ptable->pRegVals == NULL)
			{
				return i;
			}
			else
			{
				pval = (DCL_UINT16 *)ptable->pRegVals;
				return pval[i];
			}
		}
	}

	//有這組設定值,但找不到match value
	ASSERT(0);
	return 0;
}

DCL_UINT32 PMU_Value_to_Parameter(DCL_CTRL_CMD cmd,DCL_UINT32 val)
{
	PMU_PARAMETER_TABLE_ENTRY *ptable;
	DCL_UINT32 *parameter;
	DCL_UINT16 *pval;
	DCL_UINT32 idx, i, size;

	idx = PMU_get_Parameter_Idx(cmd);

	//沒有這組設定值
	if (idx == PARAMETER_UNKNOWN)
		return PARAMETERVAL_UNKNOWN;

	ptable = &pmu_parameter_table[idx];

	parameter = (DCL_UINT32 *)ptable->pVals;
	pval = (DCL_UINT16 *)ptable->pRegVals;
	size = ptable->size;

	if (pval == NULL)
	{
		return parameter[val];
	}
	else
	{
		for(i = 0;i < size;i++)
		{
			if (pval[i] == val)
				return parameter[i];
		}
	}

	return PARAMETER_UNKNOWN;
}
#endif // End of #if defined(PMIC_PRESENT)

void PMU_SetData16(DCL_UINT32 Addr,DCL_UINT16 mask,DCL_UINT16 val)
{
	DCL_UINT32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
#if !defined(FPGA_CTP)
	PMU_DRV_SetData16(Addr,mask, val);
#endif
	PMU_RestoreIRQMask(savedMask);
}

#if defined(PMIC_SLIM_V3)

extern const PMU_FLAG_TABLE_ENTRY pmu_flags_table[];

DCL_STATUS pmu_set_register_value(DCL_UINT32 address,PMU_FLAGS_LIST_ENUM flagname,DCL_UINT32 val)
{
	const PMU_FLAG_TABLE_ENTRY *pFlag=&pmu_flags_table[flagname];
	kal_uint32 savedMask;

	if (pFlag->flagname!=flagname)
		ASSERT(0);

	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((address+pFlag->offset),
	                    pFlag->mask, ((kal_uint16)val << pFlag->shift));
	PMU_RestoreIRQMask(savedMask);

	return STATUS_OK;
}

DCL_UINT16 pmu_get_register_value(DCL_UINT32 address,PMU_FLAGS_LIST_ENUM flagname)
{
	const PMU_FLAG_TABLE_ENTRY *pFlag=&pmu_flags_table[flagname];
		kal_uint16 val;

	val = PMU_DRV_ReadReg16((address+pFlag->offset));

	return ((val&pFlag->mask)>>pFlag->shift);
}
#endif //#if defined(PMIC_SLIM_V3)


#if defined(__DRV_UPMU_SHARE_LDO__)
DCL_HANDLE LdoShareIdxTable[PMU_MULTIUSERS_HANDLE_NO];
DCL_UINT32 LdoShareIdxBitmap;

DCL_BOOL ldoShare_free_idx(DCL_HANDLE handle)
{
	kal_uint32 savedMask;
	DCL_UINT16 i;

	savedMask = SaveAndSetIRQMask();
	for (i=0;i<PMU_MULTIUSERS_HANDLE_NO;i++)
	{
		if (LdoShareIdxTable[i] == handle)
		{
			DCL_UINT32 bitmap=1<<i;
			LdoShareIdxTable[i]=0;
			LdoShareIdxBitmap &=~(bitmap);
			break;
		}
	}
	RestoreIRQMask(savedMask);


	return DCL_TRUE;
}

DCL_UINT16 ldoShare_get_idx(DCL_HANDLE handle)
{
	kal_uint32 savedMask;
	DCL_UINT16 i;

	for (i=0;i<PMU_MULTIUSERS_HANDLE_NO;i++)
	{
		if (LdoShareIdxTable[i] == handle)
			return i;
	}

	if (i>=PMU_MULTIUSERS_HANDLE_NO)
	{
		savedMask = SaveAndSetIRQMask();
		for (i=0;i<PMU_MULTIUSERS_HANDLE_NO;i++)
		{
			if (LdoShareIdxTable[i] == 0)
			{
				LdoShareIdxTable[i]=handle;
				LdoShareIdxBitmap|=(DCL_UINT32)1<<i;
				break;
			}
		}
		RestoreIRQMask(savedMask);
		//user who share ldo should open once to avoid out of bitmap
		if (i>=PMU_MULTIUSERS_HANDLE_NO)
			ASSERT(0);	
	}

	return i;
}

void ldoShare_set_bitmap(DCL_UINT16 idx,DCL_HANDLE handle,PMU_LDO_BUCK_LIST_ENUM ldo,DCL_BOOL enable)
{
		DCL_UINT32 *pEntry=&pmu_ldo_bb_profile[GETLDOIDX(ldo)].usageBitMap;
		kal_uint32 savedMask;
		DCL_UINT32 bitmap=1<<idx;
		savedMask = SaveAndSetIRQMask();
		if (LdoShareIdxTable[idx]!=handle)
			ASSERT(0);
		if (enable==DCL_TRUE)
		{
			*pEntry|=bitmap;
		}
		else
		{
			*pEntry &=~(bitmap);
		}

		RestoreIRQMask(savedMask);

}

DCL_STATUS ldoShare_set_enable(DCL_HANDLE handle,PMU_LDO_BUCK_LIST_ENUM ldo, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETLDOIDX(ldo)];
	DCL_UINT32 savedMask;
	DCL_UINT16 idx;

	idx=ldoShare_get_idx(handle);
	ldoShare_set_bitmap(idx,handle,ldo,enable);


	savedMask = PMU_SaveAndSetIRQMask();
	if ((pEntry->usageBitMap & LdoShareIdxBitmap)!=0)
	{
		PMU_DRV_SetData16((pEntry->addr+LDO_EN_OFFSET),
	                    LDO_EN_MASK, ((DCL_UINT16)1 << LDO_EN_SHIFT));
	}
	else
	{
		PMU_DRV_SetData16((pEntry->addr+LDO_EN_OFFSET),
	                    LDO_EN_MASK, ((DCL_UINT16)0 << LDO_EN_SHIFT));		
	}
	PMU_RestoreIRQMask(savedMask);	

	return STATUS_OK;
}
#endif //#if defined(__DRV_UPMU_SHARE_LDO__)


#if defined(__DRV_UPMU_LPOSC_V1__)
extern PMU_MOD_BASEADDR_ENTRY pmu_lposc_profile[];
// LPOSC 
void lposc_set_enable(PMU_LPOSC_LIST_ENUM lposc,DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_lposc_profile[(kal_uint16)lposc];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LPOSC_CON0_OFFSET),
	                   LPOSC_EN_MASK, ((kal_uint16)enable << LPOSC_EN_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}

void lposc_set_buckboost_enable(PMU_LPOSC_LIST_ENUM lposc,DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_lposc_profile[(kal_uint16)lposc];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LPOSC_CON2_OFFSET),
	                   LPOSC_RG_BUCK_BOOST_EN_MASK, ((kal_uint16)enable << LPOSC_RG_BUCK_BOOST_EN_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}



void lposc_set_freq(PMU_LPOSC_LIST_ENUM lposc,DCL_UINT16 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_lposc_profile[(kal_uint16)lposc];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LPOSC_CON1_OFFSET),
	                   LPOSC_FREQ_SET_MASK, ((kal_uint16)val << LPOSC_FREQ_SET_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}

void lposc_set_buck_freq(PMU_LPOSC_LIST_ENUM lposc,DCL_UINT16 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_lposc_profile[(kal_uint16)lposc];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LPOSC_CON1_OFFSET),
	                   LPOSC_BUCK_FREQ_SET_MASK, ((kal_uint16)val << LPOSC_BUCK_FREQ_SET_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}


void lposc_set_acali_enable(PMU_LPOSC_LIST_ENUM lposc,DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_lposc_profile[(kal_uint16)lposc];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LPOSC_CON1_OFFSET),
	                   LPOSC_ACALI_EN_MASK, ((kal_uint16)enable << LPOSC_ACALI_EN_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}


void lposc_set_freq_set(PMU_LPOSC_LIST_ENUM lposc,DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_lposc_profile[(kal_uint16)lposc];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LPOSC_CON1_OFFSET),
	                   LPOSC_FREQ_SET_MASK, ((kal_uint16)val << LPOSC_FREQ_SET_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}


// LPOSC CON2
void lposc_set_fd_res(PMU_LPOSC_LIST_ENUM lposc,DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_lposc_profile[(kal_uint16)lposc];
	kal_uint32 savedMask;
	
	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LPOSC_CON2_OFFSET),
	                   LPOSC_FD_RES_MASK, ((kal_uint16)val << LPOSC_FD_RES_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}

void lposc_set_ssc_enable(PMU_LPOSC_LIST_ENUM lposc,DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_lposc_profile[(kal_uint16)lposc];
	kal_uint32 savedMask;
	
	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LPOSC_CON2_OFFSET),
	                   LPOSC_SSC_EN_MASK, ((kal_uint16)enable << LPOSC_SSC_EN_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}

void lposc_set_ssc_mod_amp(PMU_LPOSC_LIST_ENUM lposc,DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_lposc_profile[(kal_uint16)lposc];
	kal_uint32 savedMask;
	
	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LPOSC_CON2_OFFSET),
	                   LPOSC_SSC_MOD_AMP_MASK, ((kal_uint16)val << LPOSC_SSC_MOD_AMP_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}

void lposc_set_ssc_code_dur(PMU_LPOSC_LIST_ENUM lposc,DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_lposc_profile[(kal_uint16)lposc];
	kal_uint32 savedMask;
	
	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LPOSC_CON2_OFFSET),
	                   LPOSC_SSC_CODE_DUR_MASK, ((kal_uint16)val << LPOSC_SSC_CODE_DUR_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}


void lposc_set_pg_enable(PMU_LPOSC_LIST_ENUM lposc,DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_lposc_profile[(kal_uint16)lposc];
	kal_uint32 savedMask;
	
	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LPOSC_CON2_OFFSET),
	                   LPOSC_LPOSC_PG_EN_MASK, ((kal_uint16)enable <<LPOSC_LPOSC_PG_EN_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}

void lposc_set_sw_mode_enable(PMU_LPOSC_LIST_ENUM lposc,DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_lposc_profile[(kal_uint16)lposc];
	kal_uint32 savedMask;
	
	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LPOSC_CON4_OFFSET),
	                   LPOSC_SW_MODE_EN_MASK, ((kal_uint16)enable <<LPOSC_SW_MODE_EN_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}

#endif //#if defined(__DRV_UPMU_LPOSC_V1__)


#if defined(__DRV_UPMU_LDO_V1__)
extern DCL_UINT16 pmu_ldo_bb_size;
void initLdoBuckMapping(void)
{
	DCL_UINT16 i, j, size = pmu_ldo_bb_size;

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

// LDO CON0
DCL_STATUS ldo_set_enable(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETLDOIDX(ldo)];
	DCL_UINT32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
		PMU_DRV_SetData16((pEntry->addr+LDO_EN_OFFSET),
	                    LDO_EN_MASK, ((DCL_UINT16)enable << LDO_EN_SHIFT));
	PMU_RestoreIRQMask(savedMask);	

	return STATUS_OK;
}

DCL_STATUS ldo_set_voltage(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT32 vol)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETLDOIDX(ldo)];
	DCL_UINT16 val;

	val=PMU_Parameter_to_Value(ENC(LDO_BUCK_SET_VOLTAGE,ldo),vol);

	if (val==PARAMETER_UNKNOWN)
		return STATUS_UNSUPPORTED;

	PMU_SetData16((pEntry->addr+LDO_CON0_OFFSET),LDO_VOL_SEL_MASK,
		((DCL_UINT16)val << LDO_VOL_SEL_SHIFT));

	return STATUS_OK;


}

void ldo_set_oc_auto_off(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_BOOL auto_off)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETLDOIDX(ldo)];

	kal_uint32 savedMask;
	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+LDO_OC_AUTO_OFF_OFFSET),
	                    LDO_OC_AUTO_OFF_MASK, ((kal_uint16)auto_off << LDO_OC_AUTO_OFF_SHIFT));
	PMU_RestoreIRQMask(savedMask);

}


void ldo_set_stb_enable(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETLDOIDX(ldo)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LDO_STB_EN_OFFSET),
	                    LDO_STB_EN_MASK, ((kal_uint16)enable << LDO_STB_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void ldo_set_on_sel(PMU_LDO_BUCK_LIST_ENUM ldo, PMU_ON_SEL_ENUM sel)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETLDOIDX(ldo)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LDO_ON_SEL_OFFSET),
	                    LDO_ON_SEL_MASK, ((kal_uint16)sel << LDO_ON_SEL_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void ldo_set_ocfb_enable(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETLDOIDX(ldo)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LDO_OCFB_EN_OFFSET),
	                    LDO_OCFB_EN_MASK, ((kal_uint16)enable << LDO_OCFB_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void ldo_set_ndis_enable(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETLDOIDX(ldo)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LDO_NDIS_EN_OFFSET),
	                    LDO_NDIS_EN_MASK, ((kal_uint16)enable << LDO_NDIS_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

//LDO CON1
void ldo_set_voltage_calibration_code(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT32 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETLDOIDX(ldo)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LDO_CAL_OFFSET),
	                    LDO_CAL_MASK, ((kal_uint16)val << LDO_CAL_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void ldo_set_current_limit(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT32 val)
{
   ldo_set_voltage_calibration_code(ldo,val);
}

// LDO CON2
void ldo_set_oc_td(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT32 sel)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETLDOIDX(ldo)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LDO_OC_TD_OFFSET),
	                    LDO_OC_TD_MASK, ((kal_uint16)sel << LDO_OC_TD_SHIFT));
	PMU_RestoreIRQMask(savedMask);
}

void ldo_set_stb_td(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT32 sel)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETLDOIDX(ldo)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LDO_STB_TD_OFFSET),
	                    LDO_STB_TD_MASK, ((kal_uint16)sel << LDO_STB_TD_SHIFT));
	PMU_RestoreIRQMask(savedMask);
}

void ldo_set_ctrl_sel(PMU_LDO_BUCK_LIST_ENUM ldo, PMU_CTRL_LDO_CTRL_MODE_ENUM sel)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_ldo_bb_profile[GETLDOIDX(ldo)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LDO_CON2_OFFSET),
	                    LDO_GP_LDOEN_MASK, ((kal_uint16)sel << LDO_GP_LDOEN_SHIFT));
	PMU_RestoreIRQMask(savedMask);
}


void ldo_set_sim_gpio_en(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_ldo_bb_profile[GETLDOIDX(ldo)];
	kal_uint32 savedMask;

	if (ldo!=VSIM || ldo!=VSIM2)
		return;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LDO_SIM_GPIO_EN_OFFSET),
	                   LDO_SIM_GPIO_EN_MASK, ((kal_uint16)enable << LDO_SIM_GPIO_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void ldo_set_simio_drv(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_ldo_bb_profile[GETLDOIDX(ldo)];
	kal_uint32 savedMask;

	if (ldo!=VSIM || ldo!=VSIM2)
		return;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LDO_SIM_SIMIO_DRV_OFFSET),
	                   LDO_SIM_SIMIO_DRV_MASK, ((kal_uint16)val << LDO_SIM_SIMIO_DRV_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void ldo_set_bias(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_ldo_bb_profile[GETLDOIDX(ldo)];
	kal_uint32 savedMask;

	if (ldo!=VSIM || ldo!=VSIM2)
		return;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LDO_SIM_SRN_OFFSET),
	                   LDO_SIM_SRN_MASK, ((kal_uint16)val << LDO_SIM_SRN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void ldo_set_srn(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_ldo_bb_profile[GETLDOIDX(ldo)];
	kal_uint32 savedMask;

	if (ldo!=VSIM || ldo!=VSIM2)
		return;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LDO_SIM_SRN_OFFSET),
	                   LDO_SIM_SRN_MASK, ((kal_uint16)val << LDO_SIM_SRN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void ldo_set_srp(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_ldo_bb_profile[GETLDOIDX(ldo)];
	kal_uint32 savedMask;

	if (ldo!=VSIM || ldo!=VSIM2)
		return;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+LDO_SIM_SRP_OFFSET),
	                   LDO_SIM_SRP_MASK, ((kal_uint16)val << LDO_SIM_SRP_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void ldo_set_cstop(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_ldo_bb_profile[GETLDOIDX(ldo)];
	kal_uint32 savedMask;

	if (ldo!=VSIM || ldo!=VSIM2)
		return;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr + LDO_SIM_CSTOP_OFFSET),
	                   LDO_SIM_CSTOP_MASK, ((kal_uint16)val << LDO_SIM_CSTOP_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

#endif //#if defined(__DRV_UPMU_LDO_V1__)



#if defined(__DRV_UPMU_BUCK_V1__)
// BUCK CON0
DCL_STATUS buck_set_enable(PMU_LDO_BUCK_LIST_ENUM buck, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(buck)];
	DCL_UINT32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BUCK_EN_OFFSET),
	                   BUCK_EN_MASK, ((DCL_UINT16)enable << BUCK_EN_SHIFT));
	PMU_RestoreIRQMask(savedMask);
	return STATUS_OK;
}


DCL_STATUS buck_set_voltage(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT32 vol)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(buck)];
	DCL_UINT32 savedMask;
	DCL_UINT16 val;

	val=PMU_Parameter_to_Value(ENC(LDO_BUCK_SET_VOLTAGE,buck),vol);

	if (val==PARAMETER_UNKNOWN)
		return STATUS_UNSUPPORTED;

	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+BUCK_VFBADJ_OFFSET),
	                    BUCK_VFBADJ_MASK, ((DCL_UINT16)val << BUCK_VFBADJ_SHIFT));
	PMU_RestoreIRQMask(savedMask);
	
	return STATUS_OK;

}

void buck_set_on_sel(PMU_LDO_BUCK_LIST_ENUM buck, PMU_ON_SEL_ENUM sel)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETLDOIDX(buck)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BUCK_ON_SEL_OFFSET),
	                    BUCK_ON_SEL_MASK, ((kal_uint16)sel << BUCK_ON_SEL_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void buck_set_rs(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT32 sel)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(buck)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BUCK_RS_OFFSET),
	                    BUCK_RS_MASK, ((kal_uint16)sel << BUCK_RS_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void buck_set_oc_auto_off(PMU_LDO_BUCK_LIST_ENUM buck, DCL_BOOL auto_off)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(buck)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BUCK_CON0_OFFSET),
	                    BUCK_OC_AUTO_OFF_MASK, ((kal_uint16)auto_off << BUCK_OC_AUTO_OFF_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void buck_set_dis_antiunsh(PMU_LDO_BUCK_LIST_ENUM buck, DCL_BOOL off)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(buck)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BUCK_CON0_OFFSET),
	                    BUCK_DIS_ANTIUNSH_MASK, ((kal_uint16)off << BUCK_DIS_ANTIUNSH_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}


//BUCK CON3
void buck_set_ical(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT32 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(buck)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BUCK_ICAL_EN_OFFSET),
	                    BUCK_ICAL_EN_MASK, ((kal_uint16)val << BUCK_ICAL_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void buck_set_oc_td(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT32 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(buck)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BUCK_OC_TD_OFFSET),
	                    BUCK_OC_TD_MASK, ((kal_uint16)val << BUCK_OC_TD_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void buck_set_stb_td(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT32 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(buck)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BUCK_STB_TD_OFFSET),
	                    BUCK_STB_TD_MASK, ((kal_uint16)val << BUCK_STB_TD_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

//BUCK CON5

DCL_STATUS buck_set_sleep_voltage(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT32 vol)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(buck)];
	DCL_UINT32 savedMask;
	DCL_UINT16 val;

	val=PMU_Parameter_to_Value(ENC(LDO_BUCK_SET_SLEEP_VOLTAGE,buck),vol);

	if (val==PARAMETER_UNKNOWN)
		return STATUS_UNSUPPORTED;

	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+BUCK_VFBADJ_SLEEP_OFFSET),
	                    BUCK_VFBADJ_SLEEP_MASK, ((DCL_UINT16)val << BUCK_VFBADJ_SLEEP_SHIFT));
	PMU_RestoreIRQMask(savedMask);
	
	return STATUS_OK;

}

void buck_set_burst_threshold(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT32 threshold)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(buck)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BUCK_BURST_OFFSET),
	                    BUCK_BURST_MASK, ((kal_uint16)threshold << BUCK_BURST_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void buck_set_current_limit(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT32 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(buck)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BUCK_CSL_OFFSET),
	                    BUCK_CSL_MASK, ((kal_uint16)val << BUCK_CSL_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void buck_set_ocfb_enable(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT32 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(buck)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_SetData16((pEntry->addr+BUCK_OCFB_EN_OFFSET),
            			BUCK_OCFB_EN_MASK, ((kal_uint16)val<< BUCK_OCFB_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void buck_set_adjcksel(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(buck)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BUCK_ADJCKSEL_OFFSET),
	                    BUCK_ADJCKSEL_MASK, ((kal_uint16)val << BULK_ADJCKSEL_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void buck_set_rzsel(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(buck)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BUCK_RZSEL_OFFSET),
	                    BUCK_RZSEL_MASK, ((kal_uint16)val << BULK_RZSEL_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void buck_set_csr(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(buck)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BUCK_CSR_OFFSET),
	                    BUCK_CSR_MASK, ((kal_uint16)val << BULK_CSR_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void buck_set_cks_prg(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(buck)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BUCK_CKS_PRG_OFFSET),
	                    BUCK_CKS_PRG_MASK, ((kal_uint16)val << BUCK_CKS_PRG_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void buck_set_gmsel(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(buck)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BUCK_GMSEL_OFFSET),
	                    BUCK_GMSEL_MASK, ((kal_uint16)val << BUCK_GMSEL_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void buck_set_zx_pdn(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_ldo_bb_profile[GETBUCKIDX(buck)];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BUCK_ZX_PDN_OFFSET),
	                    BUCK_ZX_PDN_MASK, ((kal_uint16)val << BUCK_ZX_PDN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}


#endif //#if defined(__DRV_UPMU_BUCK__)

#if defined(__DRV_UPMU_VPA_V1__)

extern PMU_MOD_BASEADDR_ENTRY pmu_vpa_profile[];

void vpa_set_enable(PMU_VPA_LIST_ENUM vpa,DCL_BOOL enable)
{
       PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_vpa_profile[vpa];
	kal_uint32 savedMask;
	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+VPA_EN_OFFSET),
	                  VPA_EN_MASK, ((kal_uint16)enable <<VPA_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);

}

void vpa_set_antiring_enable(PMU_VPA_LIST_ENUM vpa,DCL_BOOL enable)
{
       PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_vpa_profile[vpa];
	kal_uint32 savedMask;
	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+VPA_ANTI_RING_OFFSET),
	                  VPA_ANTI_RING_MASK, ((kal_uint16)enable <<VPA_ANTI_RING_SHIFT));

	PMU_RestoreIRQMask(savedMask);

}

void vpa_set_rc(PMU_VPA_LIST_ENUM vpa,DCL_BOOL val)
{
       PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_vpa_profile[vpa];
	kal_uint32 savedMask;
	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+VPA_RC_OFFSET),
	                  VPA_RC_MASK, ((kal_uint16)val <<VPA_RC_SHIFT));

	PMU_RestoreIRQMask(savedMask);

}


//VPA CON2
void vpa_set_votune0(PMU_VPA_LIST_ENUM vpa, DCL_UINT32 voltage)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_vpa_profile[vpa];
	DCL_UINT32 savedMask;
	DCL_UINT16 val;

	val=PMU_Parameter_to_Value(ENC(VPA_SET_VOLTAGE,vpa),voltage);

	if (val==PARAMETER_UNKNOWN)
		ASSERT(0);
	
	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+VPA_VOTUNE0_OFFSET),
	                   VPA_VOTUNE0_MASK, ((DCL_UINT16)val << VPA_VOTUNE0_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}

void vpa_set_votune1(PMU_VPA_LIST_ENUM vpa, DCL_UINT32 voltage)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_vpa_profile[vpa];
	DCL_UINT32 savedMask;
	DCL_UINT16 val;

	val=PMU_Parameter_to_Value(ENC(VPA_SET_VOLTAGE,vpa),voltage);

	if (val==PARAMETER_UNKNOWN)
		ASSERT(0);	
	
	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+VPA_VOTUNE1_OFFSET),
	                   VPA_VOTUNE1_MASK, ((DCL_UINT16)val << VPA_VOTUNE1_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}

//VPA CON3
void vpa_set_votune2(PMU_VPA_LIST_ENUM vpa, DCL_UINT32 voltage)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_vpa_profile[vpa];
	DCL_UINT32 savedMask;
	DCL_UINT16 val;

	val=PMU_Parameter_to_Value(ENC(VPA_SET_VOLTAGE,vpa),voltage);

	if (val==PARAMETER_UNKNOWN)
		ASSERT(0);
	
	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+VPA_VOTUNE2_OFFSET),
	                   VPA_VOTUNE2_MASK, ((DCL_UINT16)val << VPA_VOTUNE2_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}

void vpa_set_votune3(PMU_VPA_LIST_ENUM vpa, DCL_UINT32 voltage)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_vpa_profile[vpa];
	DCL_UINT32 savedMask;
	DCL_UINT16 val;

	val=PMU_Parameter_to_Value(ENC(VPA_SET_VOLTAGE,vpa),voltage);

	if (val==PARAMETER_UNKNOWN)
		ASSERT(0);	
	
	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+VPA_VOTUNE3_OFFSET),
	                   VPA_VOTUNE3_MASK, ((DCL_UINT16)val << VPA_VOTUNE3_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}

//VPA CON4
void vpa_set_votune4(PMU_VPA_LIST_ENUM vpa, DCL_UINT32 voltage)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_vpa_profile[vpa];
	DCL_UINT32 savedMask;
	DCL_UINT16 val;

	val=PMU_Parameter_to_Value(ENC(VPA_SET_VOLTAGE,vpa),voltage);

	if (val==PARAMETER_UNKNOWN)
		ASSERT(0);	
	
	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+VPA_VOTUNE4_OFFSET),
	                   VPA_VOTUNE4_MASK, ((DCL_UINT16)val << VPA_VOTUNE4_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}

void vpa_set_votune5(PMU_VPA_LIST_ENUM vpa, DCL_UINT32 voltage)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_vpa_profile[vpa];
	DCL_UINT32 savedMask;
	DCL_UINT16 val;

	val=PMU_Parameter_to_Value(ENC(VPA_SET_VOLTAGE,vpa),voltage);

	if (val==PARAMETER_UNKNOWN)
		ASSERT(0);
	
	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+VPA_VOTUNE5_OFFSET),
	                   VPA_VOTUNE5_MASK, ((DCL_UINT16)val << VPA_VOTUNE5_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}

//VPA CON5
void vpa_set_votune6(PMU_VPA_LIST_ENUM vpa, DCL_UINT32 voltage)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_vpa_profile[vpa];
	DCL_UINT32 savedMask;
	DCL_UINT16 val;

	val=PMU_Parameter_to_Value(ENC(VPA_SET_VOLTAGE,vpa),voltage);

	if (val==PARAMETER_UNKNOWN)
		ASSERT(0);
	
	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+VPA_VOTUNE6_OFFSET),
	                   VPA_VOTUNE6_MASK, ((DCL_UINT16)val << VPA_VOTUNE6_SHIFT));


	PMU_RestoreIRQMask(savedMask);
}

void vpa_set_votune7(PMU_VPA_LIST_ENUM vpa, DCL_UINT32 voltage)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_vpa_profile[vpa];
	DCL_UINT32 savedMask;
	DCL_UINT16 val;

	val=PMU_Parameter_to_Value(ENC(VPA_SET_VOLTAGE,vpa),voltage);

	if (val==PARAMETER_UNKNOWN)
		ASSERT(0);
	
	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+VPA_VOTUNE7_OFFSET),
	                   VPA_VOTUNE7_MASK, ((DCL_UINT16)val << VPA_VOTUNE7_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

DCL_STATUS vpa_set_votune(PMU_VPA_LIST_ENUM vpa, DCL_UINT32 idx,DCL_UINT32 val)
{
	ASSERT(idx<8);
	
	switch(idx)
	{
		case 0:
			vpa_set_votune0(vpa,val);
		break;
		case 1:
			vpa_set_votune1(vpa,val);
		break;
		case 2:
			vpa_set_votune2(vpa,val);
		break;
		case 3:
			vpa_set_votune3(vpa,val);
		break;
		case 4:
			vpa_set_votune4(vpa,val);
		break;
		case 5:
			vpa_set_votune5(vpa,val);
		break;
		case 6:
			vpa_set_votune6(vpa,val);
		break;
		case 7:
			vpa_set_votune7(vpa,val);
		break;
		default:
			ASSERT(0);
		break;
	}

	return STATUS_OK;

}
#endif //#if defined(__DRV_UPMU_VPA_V1__)

#if defined(__DRV_UPMU_KPLED_V1__)

extern PMU_MOD_BASEADDR_ENTRY pmu_kpled_profile[];
// KPLED CON0
void kpled_set_enable(PMU_KPLED_LIST_ENUM kpled, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_kpled_profile[kpled];
	DCL_UINT32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+KPLED_EN_OFFSET),
	                    KPLED_EN_MASK, ((DCL_UINT16)enable << KPLED_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void kpled_set_mode(PMU_KPLED_LIST_ENUM kpled, PMU_CTRL_KPLED_MODE_ENUM val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_kpled_profile[kpled];
	DCL_UINT32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+KPLED_MODE_OFFSET),
	                    KPLED_MODE_MASK, ((DCL_UINT16)val << KPLED_MODE_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void kpled_set_sel(PMU_KPLED_LIST_ENUM kpled, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_kpled_profile[kpled];
	DCL_UINT32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+KPLED_SEL_OFFSET),
	                    KPLED_SEL_MASK, ((DCL_UINT16)val << KPLED_SEL_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

/*
void kpled_set_sfstrt_c(PMU_KPLED_LIST_ENUM kpled, upmu_kpled_sf_start_time_constane_enum val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_kpled_profile[kpled];
	DCL_UINT32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+KPLED_SFSTRT_C_OFFSET),
	                    KPLED_SFSTRT_C_MASK, ((DCL_UINT16)val << KPLED_SFSTRT_C_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}
*/

DCL_BOOL kpled_get_status(PMU_KPLED_LIST_ENUM kpled)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry=&pmu_kpled_profile[kpled];
	DCL_UINT16 val;
	DCL_UINT32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
	val = PMU_DRV_ReadReg16((pEntry->addr+KPLED_STATUS_OFFSET));
	PMU_RestoreIRQMask(savedMask);

	if ((val & KPLED_STATUS_MASK) != 0)
	{
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

#endif // #if defined(__DRV_UPMU_KPLED_V1__)


#if defined(__DRV_UPMU_CHARGER_V1__)
extern PMU_MOD_BASEADDR_ENTRY pmu_chr_profile[];
// CHR_CON0
void chr_set_csdac_enable(PMU_CHR_LIST_ENUM chr, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+CSDAC_EN_OFFSET),
	                    CSDAC_EN_MASK, ((kal_uint16)enable << CSDAC_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

DCL_BOOL chr_get_is_chr_det(PMU_CHR_LIST_ENUM chr)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	kal_uint16 val;
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
	val = PMU_DRV_ReadReg16((pEntry->addr+CHRDET_OFFSET));
	PMU_RestoreIRQMask(savedMask);
	if ((val & CHRDET_MASK) != 0)
	{
		return DCL_TRUE;
	}
	return DCL_FALSE;
}

void chr_wdt_clear_internal(PMU_CHR_LIST_ENUM chr);
void chr_set_enable(PMU_CHR_LIST_ENUM chr, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	kal_uint32 savedMask;

	chr_wdt_clear_internal(chr);

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+CHR_EN_OFFSET),
	                    CHR_EN_MASK, ((kal_uint16)enable << CHR_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

DCL_STATUS chr_set_vbat_hv_vth(PMU_CHR_LIST_ENUM chr, DCL_UINT32 voltage)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	kal_uint32 savedMask;
	DCL_UINT16 val;

	val=PMU_Parameter_to_Value(ENC(CHR_SET_HV_DETECTION_VOLTAGE,CHR),voltage);

	if (val==PARAMETER_UNKNOWN)
		return STATUS_UNSUPPORTED;


	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+CON0_OFFSET),
	                    VCDT_HV_VTH_MASK, ((kal_uint16)val << VCDT_HV_VTH_SHIFT));
	PMU_RestoreIRQMask(savedMask);

	return STATUS_OK;

}


// CHR_CON1
DCL_BOOL chr_get_is_vbat_cv_det(PMU_CHR_LIST_ENUM chr)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	kal_uint16 val;
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
	val = PMU_DRV_ReadReg16((pEntry ->addr+VBAT_CV_DET_OFFSET));
	PMU_RestoreIRQMask(savedMask);
	if ((val & VBAT_CV_DET_MASK) != 0)
	{
		return KAL_TRUE;
	}
	return KAL_FALSE;
}


DCL_STATUS chr_set_vbat_cv_vth(PMU_CHR_LIST_ENUM chr, DCL_UINT32 voltage)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	kal_uint32 savedMask;
	DCL_UINT16 val;

	val=PMU_Parameter_to_Value(ENC(CHR_SET_CV_DETECTION_VOLTAGE,CHR),voltage);

	if (val==PARAMETER_UNKNOWN)
		return STATUS_UNSUPPORTED;


	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+VBAT_CV_VTH_OFFSET),
	                    VBAT_CV_VTH_MASK, ((kal_uint16)val << VBAT_CV_VTH_SHIFT));
	PMU_RestoreIRQMask(savedMask);

	return STATUS_OK;

}

DCL_STATUS chr_set_vbat_cv_vth_value(PMU_CHR_LIST_ENUM chr, DCL_UINT16 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+VBAT_CV_VTH_OFFSET),
	                    VBAT_CV_VTH_MASK, ((kal_uint16)val << VBAT_CV_VTH_SHIFT));
	PMU_RestoreIRQMask(savedMask);

	return STATUS_OK;

}


void chr_set_vbat_cv_det_enable(PMU_CHR_LIST_ENUM chr, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+VBAT_CV_EN_OFFSET),
	                    VBAT_CV_EN_MASK, ((kal_uint16)enable << VBAT_CV_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}


// CHR_CON2
DCL_UINT32 chr_get_cs_vth(PMU_CHR_LIST_ENUM chr)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	DCL_UINT16 regVal;
	DCL_UINT32 val;

	regVal = PMU_DRV_ReadReg16((pEntry->addr+CS_VTH_OFFSET));
	regVal = ((regVal & CS_VTH_MASK) >> CS_VTH_SHIFT);


	val=PMU_Value_to_Parameter(ENC(CHR_SET_CHR_CURRENT,CHR),regVal);

	if (val==PARAMETERVAL_UNKNOWN)
		ASSERT(0);

	return val;
}

DCL_STATUS chr_set_cs_vth(PMU_CHR_LIST_ENUM chr, DCL_UINT32 current)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	kal_uint32 savedMask;
	DCL_UINT16 val;

	val=PMU_Parameter_to_Value(ENC(CHR_SET_CHR_CURRENT,CHR),current);

	if (val==PARAMETER_UNKNOWN)
		return STATUS_UNSUPPORTED;

	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+CS_VTH_OFFSET),
	                    CS_VTH_MASK, ((kal_uint16)val << CS_VTH_SHIFT));
	PMU_RestoreIRQMask(savedMask);
	
	return STATUS_OK;

}

// CHR_CON3


void chr_set_csdac_stp(PMU_CHR_LIST_ENUM chr, DCL_UINT16 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+CON3_OFFSET),
	                    CSDAC_STP_MASK, ((kal_uint16)val << CSDAC_STP_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void chr_set_csdac_dly(PMU_CHR_LIST_ENUM chr, DCL_UINT16 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+CON3_OFFSET),
	                    CSDAC_DLY_MASK, ((kal_uint16)val << CSDAC_DLY_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

DCL_STATUS chr_set_vbat_ov_vth(PMU_CHR_LIST_ENUM chr, DCL_UINT32 voltage)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	kal_uint32 savedMask;
	DCL_UINT16 val;

	val=PMU_Parameter_to_Value(ENC(CHR_SET_VBAT_OV_DETECTION_VOLTAGE,CHR),voltage);

	if (val==PARAMETER_UNKNOWN)
		return STATUS_UNSUPPORTED;

	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+CON3_OFFSET),
	                    VBAT_OV_VTH_MASK, ((kal_uint16)val << VBAT_OV_VTH_SHIFT));
	PMU_RestoreIRQMask(savedMask);
	
	return STATUS_OK;

}


DCL_BOOL chr_get_is_bat_on(PMU_CHR_LIST_ENUM chr)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(kal_uint16)chr];
	kal_uint16 val;
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
	val = PMU_DRV_ReadReg16((pEntry->addr+CHR_CON3_OFFSET));
	PMU_RestoreIRQMask(savedMask);
	if ((val & BATON_UNDET_MASK) != 0)
	{
		// BATON_UNDET is 0 ==> Battery is attached
		// BATON_UNDET is 1 ==> Battery is NOT attached
		return DCL_FALSE;
	}
	return DCL_TRUE;
}

void chr_set_baton_ht_en(PMU_CHR_LIST_ENUM chr, DCL_UINT16 enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+CON3_OFFSET),
	                    BATON_HT_EN_MASK, ((kal_uint16)enable << BATON_HT_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void chr_set_otg_bvalid_en(PMU_CHR_LIST_ENUM chr, DCL_UINT16 enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+OTG_BVALID_EN_OFFSET),
	                    OTG_BVALID_EN_MASK, ((kal_uint16)enable << OTG_BVALID_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

// CHR_CON6

void chr_wdt_clear_internal(PMU_CHR_LIST_ENUM chr)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(kal_uint16)chr];
	kal_uint16 val;

	// To reset Charger WDT counter, just WRITE any bit of "CHR_CON6"
	val = PMU_DRV_ReadReg16((pEntry->addr+CHR_CON6_OFFSET));
	PMU_DRV_WriteReg16((pEntry->addr+CHR_CON6_OFFSET), val);

	// Need to wait 2 ms here (At least)
	// Before H/W fix the bug, need to put delay here
	// Here we use delay 200 tick is a experiment value on MT6255
	#if 0
/* under construction !*/
	#endif // #if 0
	#if defined(__DRV_CHR_WDT_CLEAR_WAIT_2MS__)
	{
		kal_uint32 tmp;
		tmp = drv_get_current_time();
		do{
			__nop();
		}while (200 > drv_get_duration_tick(tmp, drv_get_current_time()));
	}
	#endif // #if defined(__DRV_CHR_WDT_CLEAR_WAIT_2MS__)
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif // #if 0

	// CHRWDT_FLAG bit will gate CHR_EN, the way to clear CHRWDT_FLAG is to
	//    1. Write CHR_CON6
	//    2. Write CHR_CON7[1] (CHRWDT_FLAG bit)
	val = PMU_DRV_ReadReg16((pEntry->addr+CHR_CON7_OFFSET));
	val |= CHRWDT_FLAG_WR_MASK;
	PMU_DRV_WriteReg16((pEntry->addr+CHR_CON7_OFFSET), val);

}


void chr_set_wdt_td(PMU_CHR_LIST_ENUM chr,DCL_UINT32 sec)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	DCL_UINT32 savedMask;
	DCL_UINT16 val;
	
	val=PMU_Parameter_to_Value(ENC(CHR_SET_WDT_TIMER,chr),sec);

	if (val==PARAMETER_UNKNOWN)
		ASSERT(0);

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+CHRWDT_TD_OFFSET),
	                    CHRWDT_TD_MASK, ((DCL_UINT16)val << CHRWDT_TD_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void chr_set_wdt_clear(PMU_CHR_LIST_ENUM chr)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
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
	val = PMU_DRV_ReadReg16((pEntry->addr+CHR_CON6_OFFSET));
	PMU_DRV_WriteReg16((pEntry->addr+CHR_CON6_OFFSET), val);
	PMU_RestoreIRQMask(savedMask);

	// The polling in 36, 76E1, 55E1, 51E1, 53EL E1 should be ~2ms (50% error ratio)
	// After MACRO modification, it will be 2us
	while (1)
	{
		val = PMU_DRV_ReadReg16((pEntry->addr+CHR_CON7_OFFSET));
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
	val = PMU_DRV_ReadReg16((pEntry->addr+CHR_CON7_OFFSET));
	val |= CHRWDT_FLAG_WR_MASK;
	PMU_DRV_WriteReg16((pEntry->addr+CHR_CON7_OFFSET), val);
	PMU_RestoreIRQMask(savedMask);
}

void chr_set_wdt_enable(PMU_CHR_LIST_ENUM chr, DCL_UINT8 enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+CHRWDT_EN_OFFSET),
	                    CHRWDT_EN_MASK, ((kal_uint16)enable << CHRWDT_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

// CHR_CON7
void chr_set_wdt_int_enable(PMU_CHR_LIST_ENUM chr, DCL_UINT8 enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+CHRWDT_INT_EN_OFFSET),
	                    CHRWDT_INT_EN_MASK, ((kal_uint16)enable << CHRWDT_INT_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}


// CHR_CON8
void chr_set_adc_measure_enable(PMU_CHR_LIST_ENUM chr, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	DCL_UINT16 val = 0;
	DCL_UINT32 savedMask;

	if (KAL_TRUE == enable)
	{
		val = ADC_EN_MASK;
	}
	else
	{
		val = 0;
	}

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+CHR_CON8_OFFSET),
	                    ADC_EN_MASK, val);

	PMU_RestoreIRQMask(savedMask);
}

#if defined(__DRV_UPMU_BC11_V1__)
void chr_bc11_comp_vth(PMU_CHR_LIST_ENUM chr,PMU_CTRL_BC11_COMP_VTH_ENUM sel)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	//kal_uint16 val = 0;
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+BC11_VREF_VTH_OFFSET),
	                    BC11_VREF_VTH_MASK, ((kal_uint16)sel << BC11_VREF_VTH_SHIFT) );
	PMU_RestoreIRQMask(savedMask);

}

void chr_bc11_comp_en_ctrl(PMU_CHR_LIST_ENUM chr,PMU_CTRL_BC11_COMP_EN_ENUM sel)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	//kal_uint16 val = 0;
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+BC11_CMP_EN_OFFSET),
	                    BC11_CMP_EN_MASK, ((kal_uint16)sel << BC11_CMP_EN_SHIFT) );
	PMU_RestoreIRQMask(savedMask);

}

void chr_bc11_ipd_en_ctrl(PMU_CHR_LIST_ENUM chr,PMU_CTRL_BC11_IPD_EN_ENUM  sel)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	//kal_uint16 val = 0;
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+BC11_IPD_EN_OFFSET),
	                    BC11_IPD_EN_MASK, ((kal_uint16)sel << BC11_IPD_EN_SHIFT) );
	PMU_RestoreIRQMask(savedMask);

}

void chr_bc11_ipu_en_ctrl(PMU_CHR_LIST_ENUM chr,PMU_CTRL_BC11_IPU_EN_ENUM sel)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	//kal_uint16 val = 0;
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+BC11_IPU_EN_OFFSET),
	                    BC11_IPU_EN_MASK, ((kal_uint16)sel << BC11_IPU_EN_SHIFT) );
	PMU_RestoreIRQMask(savedMask);

}

void chr_bc11_bias_enable(PMU_CHR_LIST_ENUM chr, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	//kal_uint16 val = 0;
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+BC11_BIAS_EN_OFFSET),
	                    BC11_BIAS_EN_MASK, ((DCL_UINT16)enable << BC11_BIAS_EN_SHIFT) );
	PMU_RestoreIRQMask(savedMask);

}

void chr_bc11_bb_ctrl(PMU_CHR_LIST_ENUM chr)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	//kal_uint16 val = 0;
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+BC11_BB_CTRL_OFFSET),
	                    BC11_BB_CTRL_MASK, ((kal_uint16)1 << BC11_BB_CTRL_SHIFT) );
	PMU_RestoreIRQMask(savedMask);

}

void chr_bc11_reset(PMU_CHR_LIST_ENUM chr)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	kal_uint32 savedMask;


	// The control bit is WRITE
	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+BC11_RST_OFFSET),
	                    BC11_RST_MASK, ((kal_uint16)1 << BC11_RST_SHIFT) );
	PMU_RestoreIRQMask(savedMask);

}

void chr_bc11_vsrc_en_ctrl(PMU_CHR_LIST_ENUM chr,PMU_CTRL_BC11_VSRC_EN_ENUM sel)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	//kal_uint16 val = 0;
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+BC11_VSRC_EN_OFFSET),
	                    BC11_VSRC_EN_MASK, ((kal_uint16)sel << BC11_VSRC_EN_SHIFT) );
	PMU_RestoreIRQMask(savedMask);
}

DCL_BOOL chr_bc11_get_cmp_out(PMU_CHR_LIST_ENUM chr)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_chr_profile[(DCL_UINT16)chr];
	kal_uint16 val;
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
	val = PMU_DRV_ReadReg16((pEntry->addr+BC11_CMP_OUT_OFFSET));
	PMU_RestoreIRQMask(savedMask);
	if ((val & BC11_CMP_OUT_MASK) != 0)
	{
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

#endif // #if defined(__DRV_UPMU_BC11_V1__)
#endif //#if defined(__DRV_UPMU_CHARGER_V1__)

#if defined(__DRV_UPMU_STRUP_V1__)
extern PMU_MOD_BASEADDR_ENTRY pmu_strup_profile[];
void strup_usbdl_mode_enable(PMU_STRUP_LIST_ENUM strup,DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_strup_profile[strup];
	kal_uint16 val;
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+ USBDL_EN_OFFSET),
	                    USBDL_EN_MASK, ((kal_uint16)enable << USBDL_EN_SHIFT) );
	PMU_RestoreIRQMask(savedMask);

}

#endif // #if defined(__DRV_UPMU_STRUP_V1__)


#if defined(__DRV_UPMU_BOOST_V1__)
extern PMU_MOD_BASEADDR_ENTRY pmu_boost_profile[];

/*
// BOOST CON0
void boost_set_enable(PMU_BOOST_LIST_ENUM boost, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(DCL_UINT16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_EN_OFFSET),
	                    BOOST_EN_MASK, ((kal_uint16)enable << BOOST_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}


// BOOST CON1
void boost_set_current_limit(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(DCL_UINT16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CL_OFFSET),
	                    BOOST_CL_MASK, ((kal_uint16)val << BOOST_CL_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

// BOOST CON4
void boost_set_clk_cal(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(DCL_UINT16)boost];
	kal_uint32 savedMask;

	ASSERT(val < 8);

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CLK_CAL_OFFSET),
	                    BOOST_CLK_CAL_MASK, ((kal_uint16)val << BOOST_CLK_CAL_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}
*/

// BOOST CON0
void boost_set_enable(PMU_BOOST_LIST_ENUM boost, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_EN_OFFSET),
	                    BOOST_EN_MASK, ((kal_uint16)enable << BOOST_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void boost_set_type(PMU_BOOST_LIST_ENUM boost, upmu_boost_type_enum val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CON0_OFFSET),
	                    BOOST_TYPE_MASK, ((kal_uint16)val << BOOST_TYPE_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void boost_set_mode(PMU_BOOST_LIST_ENUM boost, upmu_boost_mode_enum val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CON0_OFFSET),
	                    BOOST_MODE_MASK, ((kal_uint16)val << BOOST_MODE_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void boost_set_vrsel(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CON0_OFFSET),
	                    BOOST_VRSEL_MASK, ((kal_uint16)val << BOOST_VRSEL_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void boost_set_oc_auto_off(PMU_BOOST_LIST_ENUM boost, DCL_BOOL auto_off)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CON0_OFFSET),
	                    BOOST_OC_AUTO_OFF_MASK, ((kal_uint16)auto_off << BOOST_OC_AUTO_OFF_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

DCL_BOOL boost_get_oc_status(PMU_BOOST_LIST_ENUM boost)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint16 val;
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
	val = PMU_DRV_ReadReg16((pEntry->addr+BOOST_CON0_OFFSET));
	PMU_RestoreIRQMask(savedMask);

	if ((val & BOOST_OC_FLAG_MASK) != 0)
	{
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// BOOST CON1
void boost_set_cl(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CON1_OFFSET),
	                    BOOST_CL_MASK, ((kal_uint16)val << BOOST_CL_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void boost_set_cs(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CON1_OFFSET),
	                    BOOST_CS_MASK, ((kal_uint16)val << BOOST_CS_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void boost_set_rc(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CON1_OFFSET),
	                    BOOST_RC_MASK, ((kal_uint16)val << BOOST_RC_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void boost_set_ss(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CON1_OFFSET),
	                    BOOST_SS_MASK, ((kal_uint16)val << BOOST_SS_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

// BOOST CON2
void boost_set_cksel(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CON2_OFFSET),
	                    BOOST_CKSEL_MASK, ((kal_uint16)val << BOOST_CKSEL_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void boost_set_sr_pmos(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CON2_OFFSET),
	                    BOOST_SR_PMOS_MASK, ((kal_uint16)val << BOOST_SR_PMOS_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void boost_set_sr_nmos(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CON2_OFFSET),
	                    BOOST_SR_NMOS_MASK, ((kal_uint16)val << BOOST_SR_NMOS_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void boost_set_slp(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CON2_OFFSET),
	                    BOOST_SLP_MASK, ((kal_uint16)val << BOOST_SLP_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}


// BOOST CON3
void boost_set_cks_prg(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CON3_OFFSET),
	                    BOOST_CKS_PRG_MASK, ((kal_uint16)val << BOOST_CKS_PRG_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

// BOOST CON4
void boost_set_oc_thd(PMU_BOOST_LIST_ENUM boost, upmu_boost_oc_thd_enum val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CON4_OFFSET),
	                    BOOST_OC_THD_MASK, ((kal_uint16)val << BOOST_OC_THD_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void boost_set_oc_wnd(PMU_BOOST_LIST_ENUM boost, upmu_boost_oc_wnd_enum val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CON4_OFFSET),
	                    BOOST_OC_WND_MASK, ((kal_uint16)val << BOOST_OC_WND_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void boost_set_clk_cal(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	ASSERT(val < 8);

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CON4_OFFSET),
	                    BOOST_CLK_CAL_MASK, ((kal_uint16)val << BOOST_CLK_CAL_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

// BOOST CON6
void boost_set_hw_sel(PMU_BOOST_LIST_ENUM boost, upmu_boost_hw_sel_enum val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CON6_OFFSET),
	                    BOOST_HW_SEL_MASK, ((kal_uint16)val << BOOST_HW_SEL_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void boost_set_cc(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_boost_profile[(kal_uint16)boost];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+BOOST_CON6_OFFSET),
	                    BOOST_CC_MASK, ((kal_uint16)val << BOOST_CC_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}





#endif //#if defined(__DRV_UPMU_BOOST_V1__)

#if defined(__DRV_UPMU_ISINK_V1__)
extern PMU_MOD_BASEADDR_ENTRY pmu_isink_profile[];
// ISINK CON0
void isink_set_enable(PMU_ISINK_LIST_ENUM isink, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_isink_profile[(kal_uint16)isink];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+ISINK_EN_OFFSET),
	                    ISINK_EN_MASK, ((kal_uint16)enable << ISINK_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void isinks_set_vref_cal(PMU_ISINK_LIST_ENUM isink, kal_uint8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_isink_profile[(kal_uint16)isink];
	kal_uint32 savedMask;

	ASSERT(isink == ISINK0); // The control register is only located in ISINK0

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+ISINK_CON1_OFFSET),
	                    ISINK_VREF_CAL_MASK, ((kal_uint16)val << ISINK_VREF_CAL_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void isink_set_mode(PMU_ISINK_LIST_ENUM isink, PMU_CTRL_ISINK_MODE_ENUM val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_isink_profile[(kal_uint16)isink];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+ISINK_MODE_OFFSET),
	                    ISINK_MODE_MASK, ((kal_uint16)val << ISINK_MODE_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void isink_set_step(PMU_ISINK_LIST_ENUM isink, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_isink_profile[(kal_uint16)isink];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+ISINK_STEP_OFFSET),
	                    ISINK_STEP_MASK, ((kal_uint16)val << ISINK_STEP_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

#endif //#if defined(__DRV_UPMU_ISINK_V1__)


#if defined(__DRV_UPMU_SPK_V1__)
extern PMU_MOD_BASEADDR_ENTRY pmu_spk_profile[];
// SPK CON0
void spk_set_enable(PMU_SPK_LIST_ENUM spk, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON0_OFFSET),
	                    SPK_EN_MASK, ((kal_uint16)enable << SPK_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void spk_set_reset(PMU_SPK_LIST_ENUM spk, DCL_BOOL reset)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON0_OFFSET),
	                    SPK_RST_MASK, ((kal_uint16)reset << SPK_RST_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

DCL_STATUS spk_set_vol(PMU_SPK_LIST_ENUM spk, PMU_SPK_VOL_ENUM vol)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;
	DCL_UINT16 val;

	val=PMU_Parameter_to_Value(ENC(SPK_SET_VOL,SPK),vol);

	if (val==PARAMETER_UNKNOWN)
		return STATUS_UNSUPPORTED;

	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+SPK_CON0_OFFSET),
	                    SPK_VOL_MASK, ((kal_uint16)val << SPK_VOL_SHIFT));
	PMU_RestoreIRQMask(savedMask);

}

/*
spk_set_vol_enum spk_set_get_vol(PMU_SPK_LIST_ENUM spk)
{
	PMU_SPK_LIST_ENUM *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;
	kal_uint16 val;

	// Only when configurable volume > 1 then we allow to configure volume
	ASSERT(pEntry->spk_vol_list_num > 1);  // TTTT

	savedMask = PMU_SaveAndSetIRQMask();
	val = PMU_DRV_ReadReg16((pEntry->addr+SPK_CON0_OFFSET));

	PMU_DRV_SetData16((pEntry->addr+SPK_CON0_OFFSET),
	                    SPK_VOL_MASK, ((kal_uint16)val << SPK_VOL_SHIFT));

	PMU_RestoreIRQMask(savedMask);
	val = (val & SPK_VOL_MASK) >> SPK_VOL_SHIFT;

	return pEntry->spk_vol_list[val];
}
*/

void spk_set_oc_auto_off(PMU_SPK_LIST_ENUM spk, DCL_BOOL auto_off)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON0_OFFSET),
	                    SPK_OC_AUTO_OFF_MASK, ((kal_uint16)auto_off << SPK_OC_AUTO_OFF_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void spk_set_ocfb_enable(PMU_SPK_LIST_ENUM spk, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON0_OFFSET),
	                    SPK_OCFB_EN_MASK, ((kal_uint16)enable << SPK_OCFB_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

DCL_BOOL spk_set_get_oc_status(PMU_SPK_LIST_ENUM spk)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint16 val;
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();
	val = PMU_DRV_ReadReg16((pEntry->addr+SPK_CON0_OFFSET));
	PMU_RestoreIRQMask(savedMask);

	if ((val & SPK_OC_FLAG_MASK) != 0)
	{
		return KAL_TRUE;
	}
	return KAL_FALSE;
}

// SPK CON1
void spk_set_pfd_mode_enable(PMU_SPK_LIST_ENUM spk, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON1_OFFSET),
	                    SPK_PFD_MODE_MASK, ((kal_uint16)enable << SPK_PFD_MODE_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void spk_set_cmode(PMU_SPK_LIST_ENUM spk, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON1_OFFSET),
	                    SPK_CMODE_MASK, ((kal_uint16)val << SPK_CMODE_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void spk_set_ccode(PMU_SPK_LIST_ENUM spk, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON1_OFFSET),
	                    SPK_CCODE_MASK, ((kal_uint16)val << SPK_CCODE_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

// SPK CON2
void spk_set_oc_thd(PMU_SPK_LIST_ENUM spk, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON2_OFFSET),
	                    SPK_OC_THD_MASK, ((kal_uint16)val << SPK_OC_THD_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void spk_set_oc_wnd(PMU_SPK_LIST_ENUM spk, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON2_OFFSET),
	                    SPK_OC_WND_MASK, ((kal_uint16)val << SPK_OC_WND_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

// SPK CON3
void spk_set_osc_isel(PMU_SPK_LIST_ENUM spk, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	ASSERT(val < 4);

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON3_OFFSET),
	                    SPK_OSC_ISEL_MASK, ((kal_uint16)val << SPK_OSC_ISEL_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void spk_set_oc_enable(PMU_SPK_LIST_ENUM spk, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON3_OFFSET),
	                    SPK_OC_EN_MASK, ((kal_uint16)enable << SPK_OC_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}


// SPK CON4
void spk_set_ng_dt_dly(PMU_SPK_LIST_ENUM spk, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;


	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON4_OFFSET),
	                    SPK_NG_DT_DLY_MASK, ((kal_uint16)val << SPK_NG_DT_DLY_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void spk_set_ocn_bias(PMU_SPK_LIST_ENUM spk, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	ASSERT(val < 4);

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON4_OFFSET),
	                    SPK_OCN_BIAS_MASK, ((kal_uint16)val << SPK_OCN_BIAS_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void spk_set_ocp_bias(PMU_SPK_LIST_ENUM spk, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	ASSERT(val < 4);

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON4_OFFSET),
	                    SPK_OCP_BIAS_MASK, ((kal_uint16)val << SPK_OCP_BIAS_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}


// SPK CON5

void spk_set_ng_slew_dly(PMU_SPK_LIST_ENUM spk,DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON5_OFFSET),
	                    SPK_NG_SLEW_DLY_MASK, ((kal_uint16)val << SPK_NG_SLEW_DLY_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}


void spk_set_pg_slew_dly(PMU_SPK_LIST_ENUM spk,DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON5_OFFSET),
	                    SPK_PG_SLEW_DLY_MASK, ((kal_uint16)val << SPK_PG_SLEW_DLY_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void spk_set_pg_slew_l(PMU_SPK_LIST_ENUM spk,DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON5_OFFSET),
	                    SPK_PG_SLEW_I_MASK, ((kal_uint16)val << SPK_PG_SLEW_I_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}


// SPK CON7
void spk_set_mode(PMU_SPK_LIST_ENUM spk, PMU_CTRL_SPK_MODE_ENUM val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	ASSERT(val < 4);

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON7_OFFSET),
	                    SPK_MODE_MASK, ((kal_uint16)val << SPK_MODE_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void spk_set_ab_obias(PMU_SPK_LIST_ENUM spk, DCL_UINT8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	ASSERT(val < 4);

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON7_OFFSET),
	                    SPK_AB_OBIAS_MASK, ((kal_uint16)val << SPK_AB_OBIAS_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void spk_set_ab_oc_enable(PMU_SPK_LIST_ENUM spk, DCL_BOOL enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON7_OFFSET),
	                    SPK_AB_OC_EN_MASK, ((kal_uint16)enable << SPK_AB_OC_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}


#endif // #if defined(__DRV_UPMU_SPK_V1__)

#if defined(__DRV_UPMU_SPK_V2__)
extern PMU_MOD_BASEADDR_ENTRY pmu_spk_profile[];
// SPK CON0
void spk_set_enable(PMU_SPK_LIST_ENUM spk, kal_bool enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON0_OFFSET),
	                    SPK_EN_MASK, ((kal_uint16)enable << SPK_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

DCL_STATUS spk_set_vol(PMU_SPK_LIST_ENUM spk, PMU_SPK_VOL_ENUM vol)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;
	DCL_UINT16 val;

	val=PMU_Parameter_to_Value(ENC(SPK_SET_VOL,SPK),vol);

	if (val==PARAMETER_UNKNOWN)
		return STATUS_UNSUPPORTED;

	savedMask = PMU_SaveAndSetIRQMask();
	PMU_DRV_SetData16((pEntry->addr+SPK_CON0_OFFSET),
	                    SPK_VOL_MASK, ((kal_uint16)val << SPK_VOL_SHIFT));
	PMU_RestoreIRQMask(savedMask);

}


void spk_set_oc_enable(PMU_SPK_LIST_ENUM spk, kal_bool enable)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON0_OFFSET),
	                    SPK_OC_EN_MASK, ((kal_uint16)enable << SPK_OC_EN_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void spk_set_obias(PMU_SPK_LIST_ENUM spk, kal_uint8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	ASSERT(val < 4);

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON0_OFFSET),
	                    SPK_OBIAS_MASK, ((kal_uint16)val << SPK_OBIAS_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void spk_set_oc_thd(PMU_SPK_LIST_ENUM spk, kal_uint8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON1_OFFSET),
	                    SPK_OC_THD_MASK, ((kal_uint16)val << SPK_OC_THD_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}

void spk_set_oc_wnd(PMU_SPK_LIST_ENUM spk, kal_uint8 val)
{
	PMU_MOD_BASEADDR_ENTRY *pEntry = &pmu_spk_profile[(kal_uint16)spk];
	kal_uint32 savedMask;

	savedMask = PMU_SaveAndSetIRQMask();

	PMU_DRV_SetData16((pEntry->addr+SPK_CON1_OFFSET),
	                    SPK_OC_WND_MASK, ((kal_uint16)val << SPK_OC_WND_SHIFT));

	PMU_RestoreIRQMask(savedMask);
}


#endif // #if defined(__DRV_UPMU_SPK_V2__)


