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
 *   MOLY
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
 ****************************************************************************/

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






