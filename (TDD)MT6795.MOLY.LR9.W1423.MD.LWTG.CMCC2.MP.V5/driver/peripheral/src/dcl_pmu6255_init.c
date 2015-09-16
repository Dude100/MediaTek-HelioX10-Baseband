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
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "init.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"

//pmu6255_init_set.txt	
void dcl_pmu6255_internal_init(void)
{
	{
	//<ECO_E1>
	//address, mask, value,     ap shift, ap mask, ap value, bank
	//VCORE_CON1
	//AS MT6256
	//0x0904[8:4] = 0x18
		PMU_DRV_SetData16(0x801B0904,0x1F0,0x180);
	//VCORE_CON1
	//see register description
	//0x0904[1:1] = 0x1
		PMU_DRV_SetData16(0x801B0904,0x2,0x2);
	//CHR_CON4
	//set calibration step=1 code
	//0x0A10[10:8] = 0x0
		PMU_DRV_SetData16(0x801B0A10,0x700,0x0);
	//CHR_CON5
	//
	//0x0A14[5:4] = 0x0
		PMU_DRV_SetData16(0x801B0A14,0x30,0x0);
	//CHR_CON9
	//Set charging watchdog timer expire period to 32 sec
	//0x0A24[3:0] = 0x3
		PMU_DRV_SetData16(0x801B0A24,0xF,0x3);
	//CHR_CON11
	//reset timmer and clear previous flag
	//0x0A2C[11:11] = 0x1
		PMU_DRV_SetData16(0x801B0A2C,0x800,0x800);
	//CHR_CON11
	//BC11 circuit is controllable by register.
	//0x0A2C[10:10] = 0x1
		PMU_DRV_SetData16(0x801B0A2C,0x400,0x400);
	//CHR_CON14
	//
	//0x0A38[15:0] = 0x1600
		PMU_DRV_SetData16(0x801B0A38,0xFFFF,0x1600);
	//STRUP_CON0
	//Disable USBDL detection to let keypad KCOL0 & KROW0 work normally
	//0x0A80[4:4] = 0x0
		PMU_DRV_SetData16(0x801B0A80,0x10,0x0);
	//STRUP_CON1
	//disable power good detection after power-on
	//0x0A84[3:3] = 0x1
		PMU_DRV_SetData16(0x801B0A84,0x8,0x8);
	//</ECO_E1>
	}
}
	
