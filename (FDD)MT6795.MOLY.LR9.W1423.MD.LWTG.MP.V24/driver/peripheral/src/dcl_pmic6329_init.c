/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   pmu_init.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provide for pmu initial setting
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "init.h"
#include "dcl.h"

extern DCL_UINT32 DRV_Read_PMIC_Data(DCL_UINT32 pmic_addr);
extern void DRV_Write_PMIC_Data(DCL_UINT32 pmic_addr, DCL_UINT32 value);

void PMIC_DRV_SetData(DCL_UINT32 addr, DCL_UINT32 bitmask, DCL_UINT16 value, DCL_UINT32 bank)
{
   DCL_UINT32 temp;
   addr |= (bank << 31);
   temp = (~(bitmask)) & DRV_Read_PMIC_Data(addr);
   temp |= ((value) & (bitmask));
   DRV_Write_PMIC_Data(addr,temp);
}
	
//6329_init_setting.txt
void dcl_pmic6329_internal_init(void)
{
	{
	//<ECO_E1>
	//address,  mask, value, ap shift, ap mask, ap value,    bank
	//
	//bank0 0x3F[7:6] = 0x1
		PMIC_DRV_SetData(0x3F,0xC0,0x40,0x0);
	//
	//bank0 0x40[7:6] = 0x2
		PMIC_DRV_SetData(0x40,0xC0,0x80,0x0);
	//
	//bank0 0x43[5:4] = 0x3
		PMIC_DRV_SetData(0x43,0x30,0x30,0x0);
	//
	//bank0 0x43[0:0] = 0x0
		PMIC_DRV_SetData(0x43,0x1,0x0,0x0);
	//
	//bank0 0x52[5:4] = 0x3
		PMIC_DRV_SetData(0x52,0x30,0x30,0x0);
	//
	//bank0 0x56[5:4] = 0x3
		PMIC_DRV_SetData(0x56,0x30,0x30,0x0);
	//
	//bank0 0x56[0:0] = 0x0
		PMIC_DRV_SetData(0x56,0x1,0x0,0x0);
	//
	//bank0 0x59[0:0] = 0x1
		PMIC_DRV_SetData(0x59,0x1,0x1,0x0);
	//
	//bank0 0x6B[5:4] = 0x3
		PMIC_DRV_SetData(0x6B,0x30,0x30,0x0);
	//
	//bank0 0x6B[0:0] = 0x0
		PMIC_DRV_SetData(0x6B,0x1,0x0,0x0);
	//
	//bank0 0x70[5:4] = 0x2
		PMIC_DRV_SetData(0x70,0x30,0x20,0x0);
	//
	//bank0 0x71[7:6] = 0x2
		PMIC_DRV_SetData(0x71,0xC0,0x80,0x0);
	//
	//bank0 0x74[5:4] = 0x3
		PMIC_DRV_SetData(0x74,0x30,0x30,0x0);
	//20110525 VPA control setting
	//bank0 0x7E[0:0] = 0x1
		PMIC_DRV_SetData(0x7E,0x1,0x1,0x0);
	//Turn on GPIO hysteresis enable
	//bank1 0x4[5:5] = 0x1
		PMIC_DRV_SetData(0x4,0x20,0x20,0x1);
		
		PMIC_DRV_SetData(0xBE,0x02,0x02,0x0);
		
		PMIC_DRV_SetData(0x60,0x02,0x02,0x0);				
	//</ECO_E1>
	}

	//bank0 0x60[0:0] = 0x1, VRF18_EN = 1'b1
	//PMIC_DRV_SetData(0x60,0x1,0x1,0x0);

	//bank0 0x73[0:0] = 0x1, VPA_EN = 1'b1
	//PMIC_DRV_SetData(0x73,0x1,0x1,0x0);

	//bank0 0x95[0:0] = 0x1, VSIM_EN = 1'b1
	//PMIC_DRV_SetData(0x95,0x1,0x1,0x0);
    
	//bank0 0x98[0:0] = 0x1, VSIM2_EN = 1'b1
	//PMIC_DRV_SetData(0x98,0x1,0x1,0x0);    

	//bank0 0xBE[0:0] = 0x1, VRF_EN = 1'b1
	//PMIC_DRV_SetData(0xBE,0x1,0x1,0x0);   

#if defined(__UMTS_TDD128_MODE__)
	// TDD need VRF28 on/off with SRCLKENA (Requested by CS Wu)
	// bank0 0xBE[1:1] = 0x1, VRF_ON_CTRL = 1'b1
	PMIC_DRV_SetData(0xBE,0x2,0x2,0x0);   
#endif
}
	
