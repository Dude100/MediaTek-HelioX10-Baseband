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
 *    usbdl_pmu.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines functions that Power Management Unit can support
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include 	"kal_release.h"
//#include 	"stack_common.h"
#include "dcl_pmic_features.h"
//#include 	"stack_msgs.h"
//#include 	"app_ltlcom.h"       /* Task message communiction */
#include 	"drv_comm.h"
//#include    "drvsignals.h"
#include 	"reg_base.h"
#include "dcl.h"


extern kal_bool pmic_adpt_charge_source(void);

kal_bool USBDL_Cable_IN(void)
{
    return pmic_adpt_charge_source();
}


void BL_Raise_Charger_Current(void)
{
    DCL_HANDLE pmu_handle;
    PMU_CTRL_CHR_SET_CHR_EN CtrlChrEn;
    PMU_CTRL_CHR_GET_CHR_CURRENT_LIST get_chr_current_list;
    PMU_CTRL_CHR_SET_CHR_CURRENT set_chr_current;
    PMU_CTRL_CHR_SET_CSDAC_EN chr_csdac_en;
    PMU_CTRL_CHR_GET_CC_DET ChrCcDet;
    PMU_CTRL_CHR_GET_CHR_DET_STATUS chrStatus;
	kal_int32 i;
	
    DclPMU_Initialize();

	pmu_handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);

	DclPMU_Control(pmu_handle, CHR_GET_CC_DET, (DCL_CTRL_DATA_T *)&ChrCcDet);
	DclPMU_Control(pmu_handle, CHR_GET_CHR_DET_STATUS, (DCL_CTRL_DATA_T *)&chrStatus);
	
	
	if (ChrCcDet.vbat_cc_det == DCL_FALSE && chrStatus.enable == DCL_TRUE)
	{
		// 找接近電流檔位
		{
			DclPMU_Control(pmu_handle, CHR_GET_CHR_CURRENT_LIST, (DCL_CTRL_DATA_T *)&get_chr_current_list);

			for(i = (get_chr_current_list.number - 1); i >=0; i--)
			{
				if(get_chr_current_list.pCurrentList[i] <= PMU_CHARGE_CURRENT_500_00_MA)
				{
					set_chr_current.current = (PMU_CHR_CURRENT_ENUM)get_chr_current_list.pCurrentList[i];
					break;
				}    
			}

			if(i <= 0)
			{
				set_chr_current.current = (PMU_CHR_CURRENT_ENUM)get_chr_current_list.pCurrentList[0];
			}

			DclPMU_Control(pmu_handle, CHR_SET_CHR_CURRENT, (DCL_CTRL_DATA_T *)&set_chr_current);
		
		}
		
		chr_csdac_en.enable = DCL_TRUE;
		DclPMU_Control(pmu_handle, CHR_SET_CSDAC_EN, (DCL_CTRL_DATA_T *)&chr_csdac_en);		  

		CtrlChrEn.enable = DCL_TRUE;
		DclPMU_Control(pmu_handle, CHR_SET_CHR_EN, (DCL_CTRL_DATA_T *)&CtrlChrEn);
	}

	DclPMU_Close(pmu_handle);   
}
