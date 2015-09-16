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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "init.h"
#include "dcl.h"
#include "dcl_pmu_common_sw.h"

extern DCL_UINT32 DRV_Read_PMIC_Data(DCL_UINT32 pmic_addr);
extern void DRV_Write_PMIC_Data(DCL_UINT32 pmic_addr, DCL_UINT32 value);
extern PMU_CTRL_PMIC_ECO_VERSION_ENUM pmic_get_ECO_version(void);

void PMIC_DRV_SetData(DCL_UINT32 addr, DCL_UINT32 bitmask, DCL_UINT16 value, DCL_UINT32 bank)
{
   DCL_UINT32 temp;
   addr |= (bank << 31);
   temp = (~(bitmask)) & DRV_Read_PMIC_Data(addr);
   temp |= ((value) & (bitmask));
   DRV_Write_PMIC_Data(addr,temp);
}

//ECO_E1_ini_set.txt
void dcl_pmic6327_internal_init(void)
{
	{
	//<ECO_E1>
	//address,  mask, value, ap shift, ap mask, ap value,    bank
	//Disable PG after startup
	//bank0 0x20[0:0] = 0x1
		PMIC_DRV_SetData(0x20,0x1,0x1,0x0);
	//Improve BATSNS's ESD resistance; default still zero because JTAG's SRST easier to pull RST low 
	//Also, MT6280 project team would like set to 1 because of increased output loading
	//bank0 0x22[6:6] = 0x1
		PMIC_DRV_SetData(0x22,0x40,0x40,0x0);
	//For safety default 1.2V, sleep mode will use 0.9V as requested by MT6280
	//bank0 0x56[4:0] = 0x8
		PMIC_DRV_SetData(0x56,0x1F,0x8,0x0);
	//Soft step enable after reset; VMD control by SRCLKEN with Soft-Change
	//bank0 0x57[2:2] = 0x1
		PMIC_DRV_SetData(0x57,0x4,0x4,0x0);
	//Depend on SRCLKEN for sleep mode after reset
	//bank0 0x57[0:0] = 0x1
		PMIC_DRV_SetData(0x57,0x1,0x1,0x0);
	//
	//bank0 0x5A[1:1] = 0x1
		PMIC_DRV_SetData(0x5A,0x2,0x2,0x0);
	//soft change step 8us and 50mV
	//bank0 0x5A[0:0] = 0x1
		PMIC_DRV_SetData(0x5A,0x1,0x1,0x0);
	//PFM<=>PWM threshold
	//bank0 0x5B[6:4] = 0x2
		PMIC_DRV_SetData(0x5B,0x70,0x20,0x0);
	//
	//bank0 0x5B[3:1] = 0x3
		PMIC_DRV_SetData(0x5B,0xE,0x6,0x0);
	//
	//bank0 0x88[3:3] = 0x1
		PMIC_DRV_SetData(0x88,0x8,0x8,0x0);
	//
	//bank0 0x88[0:0] = 0x0
		PMIC_DRV_SetData(0x88,0x1,0x0,0x0);
	//To follow original specification
	//bank0 0xA6[0:0] = 0x1
		PMIC_DRV_SetData(0xA6,0x1,0x1,0x0);
	//
	//bank0 0xD0[1:1] = 0x1
		PMIC_DRV_SetData(0xD0,0x2,0x2,0x0);
	//
	//bank0 0xD1[1:1] = 0x1
		PMIC_DRV_SetData(0xD1,0x2,0x2,0x0);
	//</ECO_E1>
	}
}
	
