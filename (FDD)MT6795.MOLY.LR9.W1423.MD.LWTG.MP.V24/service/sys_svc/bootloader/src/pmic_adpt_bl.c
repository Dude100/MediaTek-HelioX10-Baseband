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
 *    bl_pmic_adpt.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This module is the PMU/PMIC adaptation layer in bootloader
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

#include 	"drv_comm.h"
#include "dcl.h"

#if defined(__MINI_BOOTLOADER__)
extern void i2c_pmic_speedup(void);
extern kal_bool pmic6327_reg_write_fast(kal_uint8 reg, kal_uint8 val);

#ifdef __MTK_TARGET__
__attribute__ ((section ("EMIINITCODE"))) 
#endif /* __MTK_TARGET__ */
void pmic_swReset()
{
#if (defined(MT6327))
    i2c_pmic_speedup();
    pmic6327_reg_write_fast(0x0B, 0xBA);
#endif
}

#ifdef __MTK_TARGET__
__attribute__ ((section ("EMIINITCODE"))) 
#endif /* __MTK_TARGET__ */
void pmic_enableVmWithSpecificVol(PMU_VOLTAGE_ENUM vol)
{
#if (defined(MT6327))
    switch (vol)
    {
        case PMU_VOLT_01_200000_V:
            i2c_pmic_speedup();
            pmic6327_reg_write_fast(0x8A, 0x01);
            break;
        case PMU_VOLT_01_500000_V:
            i2c_pmic_speedup();
            pmic6327_reg_write_fast(0x8A, 0x11);
            break;
        case PMU_VOLT_01_800000_V:
            i2c_pmic_speedup();
            pmic6327_reg_write_fast(0x8A, 0x21);
            break;
        default:
            break;
    }
#endif
}

#ifdef __MTK_TARGET__
__attribute__ ((section ("EMIINITCODE"))) 
#endif /* __MTK_TARGET__ */
void pmic_setVmCaliVol(PMU_VOLTAGE_CALIBRATION_ENUM vol)
{
#if (defined(MT6327))
    int value = 0;
    
    switch (vol)
    {
    	  case PMU_VOLT_CAL_00_000000_V:
    	  	  value = 0;
    	  	  break;
    	  case PMU_VOLT_CAL_MINUS_00_020000_V:
    	  	  value = 1;
    	  	  break;
        case PMU_VOLT_CAL_MINUS_00_040000_V:
    	  	  value = 2;
    	  	  break;
        case PMU_VOLT_CAL_MINUS_00_060000_V:
    	  	  value = 3;
    	  	  break;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        case PMU_VOLT_CAL_00_060000_V:
    	  	  value = 13;
    	  	  break;
        case PMU_VOLT_CAL_00_040000_V:
    	  	  value = 14;
    	  	  break;
        case PMU_VOLT_CAL_00_020000_V:
    	  	  value = 15;
    	  	  break;
        default:
            break;
    }
    
    i2c_pmic_speedup();
    pmic6327_reg_write_fast(0x89, value);
#endif
}

#else
kal_bool pmic_adpt_charge_source(void)
{
	DCL_HANDLE handle;
	PMU_CTRL_CHR_GET_CHR_DET_STATUS chrStatus;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, CHR_GET_CHR_DET_STATUS, (DCL_CTRL_DATA_T *)&chrStatus);
	DclPMU_Close(handle);

	return (kal_bool)chrStatus.enable;

}
#endif

//kal_bool USBDL_Cable_IN(void)
//{
//	return pmic_adpt_charge_source();
//}

