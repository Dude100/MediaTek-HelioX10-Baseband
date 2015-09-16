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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "init.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"

//pmu6256_init_set.txt	
void dcl_pmu6256_internal_init(void)
{
	{
	//<ECO_E2>
	//address, mask, value,     ap shift, ap mask, ap value, bank
	//VRF_CON1
	//request from RF
	//0x0804[7:4] = 0xE
		PMU_DRV_SetData16(0x801B0804,0xF0,0xE0);
	//VTCXO_CON2
	//Sleep-mode control in a_func_mode. Please program it to 0 after power-up
	//0x0818[1:1] = 0x1
		PMU_DRV_SetData16(0x801B0818,0x2,0x2);
	//VCORE_CON1                                           
	//Confirm by RTC Level Shifter Changing Discussion     
	//0x0904[8:4] = 0x1B                                   
		PMU_DRV_SetData16(0x801B0904,0x1F0,0x1B0);
	//VCORE_CON1
	//see register description
	//0x0904[1:1] = 0x1
		PMU_DRV_SetData16(0x801B0904,0x2,0x2);
	//VCORE_CON3
	//For HQA setting
	//0x090C[13:12] = 0x0
		PMU_DRV_SetData16(0x801B090C,0x3000,0x0000);
	//VCORE_CON5
	//For HQA setting
	//0x0914[13:12] = 0x0
		PMU_DRV_SetData16(0x801B0914,0x3000,0x0000);
	//VCORE_CON5
	//For HQA setting
	//0x0914[3:0] = 0x1
		PMU_DRV_SetData16(0x801B0914,0xF,0x1);
	//VCORE_CON6
	//For HQA setting
	//0x0918[3:0] = 0x9
		PMU_DRV_SetData16(0x801B0918,0xF,0x9);
	//CHR_CON0
	//set VCDT_HV_EN = 1
	//0x0A00[0:0] = 0x1
		PMU_DRV_SetData16(0x801B0A00,0x1,0x1);
	//CHR_CON4
	//set calibration step=1 code
	//0x0A10[10:8] = 0x0
		PMU_DRV_SetData16(0x801B0A10,0x700,0x0);
	//CHR_CON5
	//set VBAT_OV_VTH to 0
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
	//SPK_CON0
	//confirm by Guile, set to 1
	//0x0D00[12:12] = 0x1
		PMU_DRV_SetData16(0x801B0D00,0x1000,0x1000);
	//SPK_CON3
	//set Fsw to 0.5*Fnom typical
	//0x0D0C[7:6] = 0x1
		PMU_DRV_SetData16(0x801B0D0C,0xC0,0x40);
	//SPK_CON4
	//set classD OCP threshold
	//0x0D10[14:12] = 0x1
		PMU_DRV_SetData16(0x801B0D10,0x7000,0x1000);
	//SPK_CON4
	//set classD OCN threshold
	//0x0D10[10:8] = 0x1
		PMU_DRV_SetData16(0x801B0D10,0x700,0x100);
	//SPK_CON4
	//increase AB mode driver translinear loop P-bias strength
	//0x0D10[7:4] = 0x7
		PMU_DRV_SetData16(0x801B0D10,0xF0,0x70);
	//SPK_CON4
	//ABamp. VCM generation circuit bias current control
	//0x0D10[3:0] = 0x0
		PMU_DRV_SetData16(0x801B0D10,0xF,0x0);
	//STRUP_CON0
	//Disable USBDL detection to let keypad KCOL0 & KROW0 work normally
	//0x0A80[4:4] = 0x0
		PMU_DRV_SetData16(0x801B0A80,0x10,0x0);
	//STRUP_CON1
	//disable power good detection after power-on
	//0x0A84[3:3] = 0x1
		PMU_DRV_SetData16(0x801B0A84,0x8,0x8);
	//</ECO_E2>
	}
}
	
