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
 *    dcl_pmic6326_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMIC 6326
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#ifndef __DCL_PMU6326_SW_H_STRUCT__
#define __DCL_PMU6326_SW_H_STRUCT__

#include "dcl_pmic_features.h"

#ifdef PMIC_6326_REG_API


/*
// debug 1
// Define to keep chaging when assert
// This flag is only for debug purpose
//#define DRV_MISC_PMIC_ASSERT_KEEP_CHARGING
//#define DEBUG_PMIC6326_NO_CHARGER_WATCHDOG_TIMER


// debug 2
// Define to enable PMIC6326 charger watch dog timer kick
// When enable charger, PMIC6326 will enable a watch dog timer
// We need to kick the timer periodically, to ontify PMIC6326 that BB is alive
// If timeout, PMIC6326 will disable charge automatically
// #### If this is NOT enabled, we will disable the watch dog timer function at boot time
//#define ENABLE_PMIC_DRIVER_KICK_CHARGER_WATCHDOG_TIMER  ==> Move to be activated by BMT charging algorithm, do NOT use this anymore
*/


#define PMIC6326_ECO_1_VERSION		0x01
#define PMIC6326_ECO_2_VERSION		0x02
#define PMIC6326_ECO_3_VERSION		0x03
#define PMIC6326_ECO_4_VERSION		0x04


#ifndef PMIC_OLD_STRUCTURE
#define PMIC_OLD_STRUCTURE

typedef enum
{
   AC_CHR=0,
   USB_CHR
}chr_type;

// Common PMIC structures

// Charger type
typedef enum
{
   PMIC_AC_CHR=0,
   PMIC_USB_CHR
}pmic_chr_type;

typedef enum
{
   PMIC_ADPT_AC_CHR=0,
   PMIC_ADPT_USB_CHR,
   PMIC_ADPT_AC_NON_STD_CHR,
   PMIC_ADPT_USB_CHARGING_HOST_CHR,
   PMIC_ADPT_NO_CHR    // Indicate NO charger
}pmic_adpt_chr_type;


typedef enum
{
   PMIC_VSIM_1_8=0,
   PMIC_VSIM_3_0
}pmic_adpt_vsim_volt;


typedef enum
{
	PMIC_ADPT_VCAMA_1_5=0,
	PMIC_ADPT_VCAMA_1_8,
	PMIC_ADPT_VCAMA_2_5,
	PMIC_ADPT_VCAMA_2_8
}pmic_adpt_vcama_volt;

typedef enum
{
	PMIC_ADPT_VCAMD_1_3=0,
	PMIC_ADPT_VCAMD_1_5,
	PMIC_ADPT_VCAMD_1_8,
	PMIC_ADPT_VCAMD_2_5,
	PMIC_ADPT_VCAMD_2_8,
	PMIC_ADPT_VCAMD_3_0,
	PMIC_ADPT_VCAMD_3_3
}pmic_adpt_vcamd_volt;

typedef struct
{
	kal_uint32 chr_current;
	kal_uint32 reg_index;
}pmic_adpt_chr_curr_reg_idx_entry;

#define PMIC_ADPT_MAX_CHARGE_CURRENT_LEVEL_NUM    16
typedef struct
{
	kal_uint32 chr_current_level_num;
	pmic_adpt_chr_curr_reg_idx_entry entry_table[PMIC_ADPT_MAX_CHARGE_CURRENT_LEVEL_NUM];
}pmic_adpt_chr_curr_table;

typedef struct
{
	kal_int32 chr_current_offset;
	kal_uint32 reg_index;
}pmic_adpt_chr_curr_offset_reg_idx_entry;

#define PMIC_ADPT_MAX_CHARGE_CURRENT_OFFSET_NUM    8
typedef struct
{
	kal_uint32 chr_current_offset_num;
	pmic_adpt_chr_curr_offset_reg_idx_entry entry_table[PMIC_ADPT_MAX_CHARGE_CURRENT_OFFSET_NUM];
}pmic_adpt_chr_curr_offset_table;

////////////////////////////////////////////////////////

typedef enum
{
	PMIC_ADPT_LDO_CTRL_CONTROLLER = 0,
	PMIC_ADPT_LDO_CTRL_LDO_CON
}pmic_adpt_ldo_ctrl_mode_enum;

typedef enum
{
	PMIC_ADPT_BL_MODE_0 = 0,
	PMIC_ADPT_BL_MODE_1,
	PMIC_ADPT_BL_MODE_2,
	PMIC_ADPT_BL_MODE_3,
	PMIC_ADPT_BL_MODE_NUM
}pmic_adpt_bl_mode_enum;

typedef enum
{
	PMIC_ADPT_SPK_MODE_0 = 0,
	PMIC_ADPT_SPK_MODE_1,
	PMIC_ADPT_SPK_MODE_2,
	PMIC_ADPT_SPK_MODE_3,
	PMIC_ADPT_SPK_MODE_NUM
}pmic_adpt_spk_mode_enum;

typedef enum
{
	PMIC_ADPT_CHARGE_CURRENT_0_MA = 0,
	PMIC_ADPT_CHARGE_CURRENT_50_MA = 50,
	PMIC_ADPT_CHARGE_CURRENT_75_MA = 75,
	PMIC_ADPT_CHARGE_CURRENT_100_MA = 100,
	PMIC_ADPT_CHARGE_CURRENT_150_MA = 150,
	PMIC_ADPT_CHARGE_CURRENT_200_MA = 200,
	PMIC_ADPT_CHARGE_CURRENT_250_MA = 250,
	PMIC_ADPT_CHARGE_CURRENT_300_MA = 300,
	PMIC_ADPT_CHARGE_CURRENT_350_MA = 350,
	PMIC_ADPT_CHARGE_CURRENT_400_MA = 400,
	PMIC_ADPT_CHARGE_CURRENT_450_MA = 450,
	PMIC_ADPT_CHARGE_CURRENT_500_MA = 500,
	PMIC_ADPT_CHARGE_CURRENT_550_MA = 550,
	PMIC_ADPT_CHARGE_CURRENT_600_MA = 600,
	PMIC_ADPT_CHARGE_CURRENT_650_MA = 650,
	PMIC_ADPT_CHARGE_CURRENT_700_MA = 700,
	PMIC_ADPT_CHARGE_CURRENT_750_MA = 750,
	PMIC_ADPT_CHARGE_CURRENT_800_MA = 800,
	PMIC_ADPT_CHARGE_CURRENT_850_MA = 850,
	PMIC_ADPT_CHARGE_CURRENT_900_MA = 900,
	PMIC_ADPT_CHARGE_CURRENT_950_MA = 950,
	PMIC_ADPT_CHARGE_CURRENT_1000_MA = 1000,
	PMIC_ADPT_CHARGE_CURRENT_1200_MA = 1200,
	PMIC_ADPT_CHARGE_CURRENT_1500_MA = 1500,
	PMIC_ADPT_CHARGE_CURRENT_1800_MA = 1800,
	PMIC_ADPT_CHARGE_CURRENT_2000_MA = 2000,
	PMIC_ADPT_CHARGE_CURRENT_MAX
}pmic_adpt_chr_current_enum;




// Unified PMIC voltage data type
// The unit value is 1uV ==> 1000000 means 1V
typedef enum
{
	PMIC_ADPT_VOLT_00_000000_V =        0,
	PMIC_ADPT_VOLT_00_100000_V =   100000,
	PMIC_ADPT_VOLT_00_200000_V =   200000,
	PMIC_ADPT_VOLT_00_300000_V =   300000,
	PMIC_ADPT_VOLT_00_400000_V =   400000,
	PMIC_ADPT_VOLT_00_500000_V =   500000,
	PMIC_ADPT_VOLT_00_600000_V =   600000,
	PMIC_ADPT_VOLT_00_700000_V =   700000,
	PMIC_ADPT_VOLT_00_800000_V =   800000,
	PMIC_ADPT_VOLT_00_825000_V =   825000,
	PMIC_ADPT_VOLT_00_850000_V =   850000,
	PMIC_ADPT_VOLT_00_875000_V =   875000,
	PMIC_ADPT_VOLT_00_900000_V =   900000,
	PMIC_ADPT_VOLT_00_925000_V =   925000,
	PMIC_ADPT_VOLT_00_950000_V =   950000,
	PMIC_ADPT_VOLT_00_975000_V =   975000,
	PMIC_ADPT_VOLT_01_000000_V =  1000000,
	PMIC_ADPT_VOLT_01_025000_V =  1025000,
	PMIC_ADPT_VOLT_01_050000_V =  1050000,
	PMIC_ADPT_VOLT_01_075000_V =  1075000,
	PMIC_ADPT_VOLT_01_100000_V =  1100000,
	PMIC_ADPT_VOLT_01_125000_V =  1125000,
	PMIC_ADPT_VOLT_01_150000_V =  1150000,
	PMIC_ADPT_VOLT_01_175000_V =  1175000,
	PMIC_ADPT_VOLT_01_200000_V =  1200000,
	PMIC_ADPT_VOLT_01_225000_V =  1225000,
	PMIC_ADPT_VOLT_01_250000_V =  1250000,
	PMIC_ADPT_VOLT_01_275000_V =  1275000,
	PMIC_ADPT_VOLT_01_300000_V =  1300000,
	PMIC_ADPT_VOLT_01_325000_V =  1325000,
	PMIC_ADPT_VOLT_01_350000_V =  1350000,
	PMIC_ADPT_VOLT_01_375000_V =  1375000,
	PMIC_ADPT_VOLT_01_400000_V =  1400000,
	PMIC_ADPT_VOLT_01_425000_V =  1425000,
	PMIC_ADPT_VOLT_01_450000_V =  1450000,
	PMIC_ADPT_VOLT_01_475000_V =  1475000,
	PMIC_ADPT_VOLT_01_500000_V =  1500000,
	PMIC_ADPT_VOLT_01_525000_V =  1525000,
	PMIC_ADPT_VOLT_01_550000_V =  1550000,
	PMIC_ADPT_VOLT_01_575000_V =  1575000,
	PMIC_ADPT_VOLT_01_600000_V =  1600000,
	PMIC_ADPT_VOLT_01_625000_V =  1625000,
	PMIC_ADPT_VOLT_01_650000_V =  1650000,
	PMIC_ADPT_VOLT_01_675000_V =  1675000,
	PMIC_ADPT_VOLT_01_700000_V =  1700000,
	PMIC_ADPT_VOLT_01_725000_V =  1725000,
	PMIC_ADPT_VOLT_01_750000_V =  1750000,
	PMIC_ADPT_VOLT_01_775000_V =  1775000,
	PMIC_ADPT_VOLT_01_800000_V =  1800000,
	PMIC_ADPT_VOLT_01_825000_V =  1825000,
	PMIC_ADPT_VOLT_01_850000_V =  1850000,
	PMIC_ADPT_VOLT_01_875000_V =  1875000,
	PMIC_ADPT_VOLT_01_900000_V =  1900000,
	PMIC_ADPT_VOLT_01_925000_V =  1925000,
	PMIC_ADPT_VOLT_01_950000_V =  1950000,
	PMIC_ADPT_VOLT_01_975000_V =  1975000,
	PMIC_ADPT_VOLT_02_000000_V =  2000000,
	PMIC_ADPT_VOLT_02_500000_V =  2500000,
	PMIC_ADPT_VOLT_02_750000_V =  2750000,
	PMIC_ADPT_VOLT_02_800000_V =  2800000,
	PMIC_ADPT_VOLT_02_850000_V =  2850000,
	PMIC_ADPT_VOLT_02_900000_V =  2900000,
	PMIC_ADPT_VOLT_03_000000_V =  3000000,
	PMIC_ADPT_VOLT_03_100000_V =  3100000,
	PMIC_ADPT_VOLT_03_250000_V =  3250000,
	PMIC_ADPT_VOLT_03_275000_V =  3275000,
	PMIC_ADPT_VOLT_03_300000_V =  3300000,
	PMIC_ADPT_VOLT_03_325000_V =  3325000,
	PMIC_ADPT_VOLT_04_000000_V =  4000000,
	PMIC_ADPT_VOLT_04_012500_V =  4012500,
	PMIC_ADPT_VOLT_04_025000_V =  4025000,
	PMIC_ADPT_VOLT_04_037500_V =  4037500,
	PMIC_ADPT_VOLT_04_050000_V =  4050000,
	PMIC_ADPT_VOLT_04_062500_V =  4062500,
	PMIC_ADPT_VOLT_04_067500_V =  4067500,
	PMIC_ADPT_VOLT_04_075000_V =  4075000,
	PMIC_ADPT_VOLT_04_087500_V =  4087500,
	PMIC_ADPT_VOLT_04_100000_V =  4100000,
	PMIC_ADPT_VOLT_04_112500_V =  4112500,
	PMIC_ADPT_VOLT_04_116000_V =  4116000,
	PMIC_ADPT_VOLT_04_125000_V =  4125000,
	PMIC_ADPT_VOLT_04_137500_V =  4137500,
	PMIC_ADPT_VOLT_04_150000_V =  4150000,
	PMIC_ADPT_VOLT_04_162500_V =  4162500,
	PMIC_ADPT_VOLT_04_175000_V =  4175000,
	PMIC_ADPT_VOLT_04_187500_V =  4187500,
	PMIC_ADPT_VOLT_04_200000_V =  4200000,
	PMIC_ADPT_VOLT_04_212500_V =  4212500,
	PMIC_ADPT_VOLT_04_225000_V =  4225000,
	PMIC_ADPT_VOLT_04_237500_V =  4237500,
	PMIC_ADPT_VOLT_04_250000_V =  4250000,
	PMIC_ADPT_VOLT_04_262500_V =  4262500,
	PMIC_ADPT_VOLT_04_275000_V =  4275000,
	PMIC_ADPT_VOLT_04_287500_V =  4287500,
	PMIC_ADPT_VOLT_04_300000_V =  4300000,
	PMIC_ADPT_VOLT_04_325000_V =  4325000,
	PMIC_ADPT_VOLT_04_350000_V =  4350000,
	PMIC_ADPT_VOLT_04_375000_V =  4375000,
	PMIC_ADPT_VOLT_04_400000_V =  4400000,
	PMIC_ADPT_VOLT_04_411500_V =  4411500,
	PMIC_ADPT_VOLT_04_450000_V =  4450000,
	PMIC_ADPT_VOLT_04_500000_V =  4500000,
	PMIC_ADPT_VOLT_04_550000_V =  4550000,
	PMIC_ADPT_VOLT_04_600000_V =  4600000,
	PMIC_ADPT_VOLT_04_800000_V =  4800000,
	PMIC_ADPT_VOLT_04_950000_V =  4950000,
	PMIC_ADPT_VOLT_05_150000_V =  5150000,
	PMIC_ADPT_VOLT_05_250000_V =  5250000,
	PMIC_ADPT_VOLT_05_000000_V =  5000000,
	PMIC_ADPT_VOLT_06_000000_V =  6000000,
	PMIC_ADPT_VOLT_06_500000_V =  6500000,
	PMIC_ADPT_VOLT_06_750000_V =  6750000,
	PMIC_ADPT_VOLT_07_000000_V =  7000000,
	PMIC_ADPT_VOLT_07_250000_V =  7250000,
	PMIC_ADPT_VOLT_07_500000_V =  7500000,
	PMIC_ADPT_VOLT_08_000000_V =  8000000,
	PMIC_ADPT_VOLT_08_500000_V =  8500000,
	PMIC_ADPT_VOLT_09_500000_V =  9500000,
	PMIC_ADPT_VOLT_10_000000_V = 10000000,



	// Backward compatible
	PMIC_ADPT_VOLT_0_0        =        0,
	PMIC_ADPT_VOLT_0_1        =   100000,
	PMIC_ADPT_VOLT_0_2        =   200000,
	PMIC_ADPT_VOLT_0_3        =   300000,
	PMIC_ADPT_VOLT_0_4        =   400000,
	PMIC_ADPT_VOLT_0_5        =   500000,
	PMIC_ADPT_VOLT_0_6        =   600000,
	PMIC_ADPT_VOLT_0_7        =   700000,
	PMIC_ADPT_VOLT_0_8        =   800000,
	PMIC_ADPT_VOLT_0_9        =   900000,
	PMIC_ADPT_VOLT_1_0        =  1000000,
	PMIC_ADPT_VOLT_1_1        =  1100000,
	PMIC_ADPT_VOLT_1_2        =  1200000,
	PMIC_ADPT_VOLT_1_3        =  1300000,
	PMIC_ADPT_VOLT_1_4        =  1400000,
	PMIC_ADPT_VOLT_1_5        =  1500000,
	PMIC_ADPT_VOLT_1_6        =  1600000,
	PMIC_ADPT_VOLT_1_7        =  1700000,
	PMIC_ADPT_VOLT_1_8        =  1800000,
	PMIC_ADPT_VOLT_1_9        =  1900000,
	PMIC_ADPT_VOLT_2_0        =  2000000,
	PMIC_ADPT_VOLT_2_1        =  2100000,
	PMIC_ADPT_VOLT_2_2        =  2200000,
	PMIC_ADPT_VOLT_2_3        =  2300000,
	PMIC_ADPT_VOLT_2_4        =  2400000,
	PMIC_ADPT_VOLT_2_5        =  2500000,
	PMIC_ADPT_VOLT_2_6        =  2600000,
	PMIC_ADPT_VOLT_2_7        =  2700000,
	PMIC_ADPT_VOLT_2_8        =  2800000,
	PMIC_ADPT_VOLT_2_9        =  2900000,
	PMIC_ADPT_VOLT_3_0        =  3000000,
	PMIC_ADPT_VOLT_3_1        =  3100000,
	PMIC_ADPT_VOLT_3_2        =  3200000,
	PMIC_ADPT_VOLT_3_3        =  3300000,
	PMIC_ADPT_VOLT_3_4        =  3400000,
	PMIC_ADPT_VOLT_3_5        =  3500000,
	PMIC_ADPT_VOLT_3_6        =  3600000,
	PMIC_ADPT_VOLT_3_7        =  3700000,
	PMIC_ADPT_VOLT_3_8        =  3800000,
	PMIC_ADPT_VOLT_3_9        =  3900000,
	PMIC_ADPT_VOLT_4_0        =  4000000,
	PMIC_ADPT_VOLT_4_1        =  4100000,
	PMIC_ADPT_VOLT_4_2        =  4200000,
	PMIC_ADPT_VOLT_4_3        =  4300000,
	PMIC_ADPT_VOLT_4_4        =  4400000,
	PMIC_ADPT_VOLT_4_5        =  4500000,
	PMIC_ADPT_VOLT_4_6        =  4600000,
	PMIC_ADPT_VOLT_4_7        =  4700000,
	PMIC_ADPT_VOLT_4_8        =  4800000,
	PMIC_ADPT_VOLT_4_9        =  4900000,
	PMIC_ADPT_VOLT_5_0        =  5000000,
	PMIC_ADPT_VOLT_5_1        =  5100000,
	PMIC_ADPT_VOLT_5_2        =  5200000,
	PMIC_ADPT_VOLT_5_3        =  5300000,
	PMIC_ADPT_VOLT_5_4        =  5400000,
	PMIC_ADPT_VOLT_5_5        =  5500000,
	PMIC_ADPT_VOLT_5_6        =  5600000,
	PMIC_ADPT_VOLT_5_7        =  5700000,
	PMIC_ADPT_VOLT_5_8        =  5800000,
	PMIC_ADPT_VOLT_5_9        =  5900000,
	PMIC_ADPT_VOLT_6_0        =  6000000,
	PMIC_ADPT_VOLT_6_1        =  6100000,
	PMIC_ADPT_VOLT_6_2        =  6200000,
	PMIC_ADPT_VOLT_6_3        =  6300000,
	PMIC_ADPT_VOLT_6_4        =  6400000,
	PMIC_ADPT_VOLT_6_5        =  6500000,
	PMIC_ADPT_VOLT_6_6        =  6600000,
	PMIC_ADPT_VOLT_6_7        =  6700000,
	PMIC_ADPT_VOLT_6_8        =  6800000,
	PMIC_ADPT_VOLT_6_9        =  6900000,
	PMIC_ADPT_VOLT_7_0        =  7000000,
	PMIC_ADPT_VOLT_7_1        =  7100000,
	PMIC_ADPT_VOLT_7_2        =  7200000,
	PMIC_ADPT_VOLT_7_3        =  7300000,
	PMIC_ADPT_VOLT_7_4        =  7400000,
	PMIC_ADPT_VOLT_7_5        =  7500000,
	PMIC_ADPT_VOLT_7_6        =  7600000,
	PMIC_ADPT_VOLT_7_7        =  7700000,
	PMIC_ADPT_VOLT_7_8        =  7800000,
	PMIC_ADPT_VOLT_7_9        =  7900000,
	PMIC_ADPT_VOLT_8_0        =  8000000,

	PMIC_ADPT_VOLT_MAX         = 50000000

}pmic_adpt_voltage_enum;


// Unified PMIC speaker volume data type
typedef enum
{
	PMIC_ADPT_SPK_VOL_00_00_dB    =    0,
	PMIC_ADPT_SPK_VOL_00_50_dB    =   50,
	PMIC_ADPT_SPK_VOL_01_00_dB    =  100,
	PMIC_ADPT_SPK_VOL_01_50_dB    =  150,
	PMIC_ADPT_SPK_VOL_02_00_dB    =  200,
	PMIC_ADPT_SPK_VOL_02_50_dB    =  250,
	PMIC_ADPT_SPK_VOL_03_00_dB    =  300,
	PMIC_ADPT_SPK_VOL_03_50_dB    =  350,
	PMIC_ADPT_SPK_VOL_04_00_dB    =  400,
	PMIC_ADPT_SPK_VOL_04_50_dB    =  450,
	PMIC_ADPT_SPK_VOL_05_00_dB    =  500,
	PMIC_ADPT_SPK_VOL_05_50_dB    =  550,
	PMIC_ADPT_SPK_VOL_06_00_dB    =  600,
	PMIC_ADPT_SPK_VOL_06_50_dB    =  650,
	PMIC_ADPT_SPK_VOL_07_00_dB    =  700,
	PMIC_ADPT_SPK_VOL_07_50_dB    =  750,
	PMIC_ADPT_SPK_VOL_08_00_dB    =  800,
	PMIC_ADPT_SPK_VOL_08_50_dB    =  850,
	PMIC_ADPT_SPK_VOL_09_00_dB    =  900,
	PMIC_ADPT_SPK_VOL_09_50_dB    =  950,
	PMIC_ADPT_SPK_VOL_10_00_dB    = 1000,
	PMIC_ADPT_SPK_VOL_10_50_dB    = 1050,
	PMIC_ADPT_SPK_VOL_11_00_dB    = 1100,
	PMIC_ADPT_SPK_VOL_11_50_dB    = 1150,
	PMIC_ADPT_SPK_VOL_12_00_dB    = 1200,
	PMIC_ADPT_SPK_VOL_12_50_dB    = 1250,
	PMIC_ADPT_SPK_VOL_13_00_dB    = 1300,
	PMIC_ADPT_SPK_VOL_13_50_dB    = 1350,
	PMIC_ADPT_SPK_VOL_14_00_dB    = 1400,
	PMIC_ADPT_SPK_VOL_14_50_dB    = 1450,
	PMIC_ADPT_SPK_VOL_15_00_dB    = 1500,
	PMIC_ADPT_SPK_VOL_15_50_dB    = 1550,
	PMIC_ADPT_SPK_VOL_16_00_dB    = 1600,
	PMIC_ADPT_SPK_VOL_16_50_dB    = 1650,
	PMIC_ADPT_SPK_VOL_17_00_dB    = 1700,
	PMIC_ADPT_SPK_VOL_17_50_dB    = 1750,
	PMIC_ADPT_SPK_VOL_18_00_dB    = 1800,
	PMIC_ADPT_SPK_VOL_18_50_dB    = 1850,
	PMIC_ADPT_SPK_VOL_19_00_dB    = 1900,
	PMIC_ADPT_SPK_VOL_19_50_dB    = 1950,
	PMIC_ADPT_SPK_VOL_20_00_dB    = 2000,
	PMIC_ADPT_SPK_VOL_20_50_dB    = 2050,
	PMIC_ADPT_SPK_VOL_21_00_dB    = 2100,
	PMIC_ADPT_SPK_VOL_21_50_dB    = 2150,
	PMIC_ADPT_SPK_VOL_22_00_dB    = 2200,
	PMIC_ADPT_SPK_VOL_22_50_dB    = 2250,
	PMIC_ADPT_SPK_VOL_23_00_dB    = 2300,
	PMIC_ADPT_SPK_VOL_23_50_dB    = 2350,
	PMIC_ADPT_SPK_VOL_24_00_dB    = 2400,
	PMIC_ADPT_SPK_VOL_24_50_dB    = 2450,


	PMIC_ADPT_SPK_VOL_0_dB    =    0,
	PMIC_ADPT_SPK_VOL_1_dB    =  100,
	PMIC_ADPT_SPK_VOL_2_dB    =  200,
	PMIC_ADPT_SPK_VOL_3_dB    =  300,
	PMIC_ADPT_SPK_VOL_4_dB    =  400,
	PMIC_ADPT_SPK_VOL_5_dB    =  500,
	PMIC_ADPT_SPK_VOL_6_dB    =  600,
	PMIC_ADPT_SPK_VOL_7_dB    =  700,
	PMIC_ADPT_SPK_VOL_8_dB    =  800,
	PMIC_ADPT_SPK_VOL_9_dB    =  900,
	PMIC_ADPT_SPK_VOL_10_dB   = 1000,
	PMIC_ADPT_SPK_VOL_11_dB   = 1100,
	PMIC_ADPT_SPK_VOL_12_dB   = 1200,
	PMIC_ADPT_SPK_VOL_13_dB   = 1300,
	PMIC_ADPT_SPK_VOL_14_dB   = 1400,
	PMIC_ADPT_SPK_VOL_15_dB   = 1500,
	PMIC_ADPT_SPK_VOL_16_dB   = 1600,
	PMIC_ADPT_SPK_VOL_17_dB   = 1700,
	PMIC_ADPT_SPK_VOL_18_dB   = 1800,
	PMIC_ADPT_SPK_VOL_19_dB   = 1900,
	PMIC_ADPT_SPK_VOL_20_dB   = 2000,
	PMIC_ADPT_SPK_VOL_21_dB   = 2100,
	PMIC_ADPT_SPK_VOL_22_dB   = 2200,
	PMIC_ADPT_SPK_VOL_23_dB   = 2300,
	PMIC_ADPT_SPK_VOL_24_dB   = 2400,

	PMIC_ADPT_SPK_VOL_MAX     = 9900
}pmic_adpt_spk_vol_enum;

#endif //#define PMIC_OLD_STRUCTURE

typedef enum
{
   AC_CHR_CALLBACK=0,
   USB_CHR_CALLBACK
}chr_callback_type;

typedef struct 
{
	void (*pmic_ac_det)(void);
	void (*pmic_usb_det)(void); 
}pmic6326_chrdect_callbac_struct;



// TTTTTTTTTTTTTTTTT
// Implemented functions



// (0x0D) INT STATUS 3 (RO)
typedef enum
{
	VSDIO_OC_STAT 			= 0x01,	// BIT0
	VGP_OC_STAT 			= 0x02,	// BIT1
	VUSB_OC_STAT 			= 0x04,	// BIT2
	OVP_INT_STAT 			= 0x08,	// BIT3
	CHRDET_INT_STAT		= 0x10,	// BIT4
	PWRKEY_INT_STAT = 0x20 // BIT5
}int_state_3_enum;


// (0x1B) LDO CTRL 2 VRF
typedef enum
{
	VRF_BIAS_CURRENT_TIMES_1_0 = 0,
	VRF_BIAS_CURRENT_TIMES_0_5,
	VRF_BIAS_CURRENT_TIMES_2_0,
	VRF_BIAS_CURRENT_TIMES_3_0
}vrf_ical_en_enum;

// (0x1C) LDO CTRL 3 VRF
typedef enum
{
	VRF_MAX_SLEW_RATE_TIMES_1_OVER_17 = 0,
	VRF_MAX_SLEW_RATE_TIMES_1_OVER_21,
	VRF_MAX_SLEW_RATE,
	VRF_MAX_SLEW_RATE_TIMES_1_OVER_5
}vrf_calst_enum;
typedef enum
{
	VRF_OC_THRESHOLD_685MA = 0,
	VRF_OC_THRESHOLD_635MA,
	VRF_OC_THRESHOLD_785MA,
	VRF_OC_THRESHOLD_735MA
}vrf_caloc_enum;

typedef enum
{
	VRF_DEFAULT_MILLER_CAPACITOR = 0,
	VRF_INCREASE_MILLER_CAPACITOR
}vrf_cm_enum;

typedef enum
{
	VRF_ENABLE_WITH_SRCLKEN = 0,
	VRF_ENABLE_WITH_VRF_EN
}vrf_on_sel_enum;


// (0x1E) LDO CTRL 5 VTCXO
typedef enum
{
	VTCXO_BIAS_CURRENT_TIMES_1_0 = 0,
	VTCXO_BIAS_CURRENT_TIMES_0_5,
	VTCXO_BIAS_CURRENT_TIMES_2_0,
	VTCXO_BIAS_CURRENT_TIMES_3_0
}vtcxo_ical_en_enum;


// (0x1F) LDO CTRL 6 VTCXO
typedef enum
{
	VTCXO_MAX_SLEW_RATE_TIMES_1_OVER_17 = 0,
	VTCXO_MAX_SLEW_RATE_TIMES_1_OVER_21,
	VTCXO_MAX_SLEW_RATE,
	VTCXO_MAX_SLEW_RATE_TIMES_1_OVER_5
}vtcxo_calst_enum;
typedef enum
{
	VTCXO_OC_THRESHOLD_100MA = 0,
	VTCXO_OC_THRESHOLD_109MA,
	VTCXO_OC_THRESHOLD_82MA,
	VTCXO_OC_THRESHOLD_91MA
}vtcxo_caloc_enum;

typedef enum
{
	VTCXO_ENABLE_WITH_SRCLKEN = 0,
	VTCXO_ENABLE_WITH_VTCXO_EN
}vtcxo_on_sel_enum;

typedef enum
{
	VTCXO_DEFAULT_MILLER_CAPACITOR = 0,
	VTCXO_INCREASE_MILLER_CAPACITOR
}vtcxo_cm_enum;

// (0x21) LDO CTRL 8 V3GTX
typedef enum
{
	V3GTX_BIAS_CURRENT_TIMES_1_0 = 0,
	V3GTX_BIAS_CURRENT_TIMES_0_5,
	V3GTX_BIAS_CURRENT_TIMES_2_0,
	V3GTX_BIAS_CURRENT_TIMES_3_0
}v3gtx_ical_en_enum;

typedef enum 
{   
	V3GTX_2_8=0,
	V3GTX_3_0,
	V3GTX_3_3,
	V3GTX_2_5
}v3gtx_vol;


// (0x22) LDO CTRL 9 V3GTX
typedef enum
{
	V3GTX_MAX_SLEW_RATE_TIMES_1_OVER_17 = 0,
	V3GTX_MAX_SLEW_RATE_TIMES_1_OVER_21,
	V3GTX_MAX_SLEW_RATE,
	V3GTX_MAX_SLEW_RATE_TIMES_1_OVER_5
}v3gtx_calst_enum;

typedef enum
{
	V3GTX_OC_THRESHOLD_400MA = 0,
	V3GTX_OC_THRESHOLD_438MA,
	V3GTX_OC_THRESHOLD_324MA,
	V3GTX_OC_THRESHOLD_362MA
}v3gtx_caloc_enum;

typedef enum
{
	V3GTX_ENABLE_WITH_SRCLKEN = 0,
	V3GTX_ENABLE_WITH_V3GTX_EN
}v3gtx_on_sel_enum;


// (0x24) LDO CTRL 11 V3GRX
typedef enum 
{   
	V3GRX_2_8=0,
	V3GRX_3_0,
	V3GRX_3_3,
	V3GRX_2_5
}v3grx_vol;

typedef enum
{
	V3GRX_BIAS_CURRENT_TIMES_1_0 = 0,
	V3GRX_BIAS_CURRENT_TIMES_0_5,
	V3GRX_BIAS_CURRENT_TIMES_2_0,
	V3GRX_BIAS_CURRENT_TIMES_3_0
}v3grx_ical_en_enum;


// (0x25) LDO CTRL 12 V3GRX
typedef enum
{
	V3GRX_MAX_SLEW_RATE_TIMES_1_OVER_17 = 0,
	V3GRX_MAX_SLEW_RATE_TIMES_1_OVER_21,
	V3GRX_MAX_SLEW_RATE,
	V3GRX_MAX_SLEW_RATE_TIMES_1_OVER_5
}v3grx_calst_enum;

typedef enum
{
	V3GRX_OC_THRESHOLD_200MA = 0,
	V3GRX_OC_THRESHOLD_219MA,
	V3GRX_OC_THRESHOLD_162MA,
	V3GRX_OC_THRESHOLD_181MA
}v3grx_caloc_enum;


typedef enum
{
	V3GRX_ENABLE_WITH_SRCLKEN = 0,
	V3GRX_ENABLE_WITH_V3GRX_EN
}v3grx_on_sel_enum;


// (0x2E) LDO CTRL 21 VCAMA
typedef enum
{
	VCAMA_2_8 = 0,
	VCAMA_2_5,
	VCAMA_1_8,
	VCAMA_1_5
}vcama_sel_enum;
typedef enum
{
	VCAMA_BIAS_CURRENT_X_1_0 = 0,
	VCAMA_BIAS_CURRENT_X_0_5,
	VCAMA_BIAS_CURRENT_X_2_0,
	VCAMA_BIAS_CURRENT_X_3_0
}vcama_ical_en_enum;

// (0x2F) LDO CTRL 22 VCAMA
typedef enum
{
	VCAMA_MAX_SLEW_RATE_TIMES_1_OVER_17 = 0,
	VCAMA_MAX_SLEW_RATE_TIMES_1_OVER_21,
	VCAMA_MAX_SLEW_RATE,
	VCAMA_MAX_SLEW_RATE_TIMES_1_OVER_5
}vcama_calst_enum;
typedef enum
{
	VCAMA_OC_THRESHOLD_500MA = 0,
	VCAMA_OC_THRESHOLD_548MA,
	VCAMA_OC_THRESHOLD_405MA,
	VCAMA_OC_THRESHOLD_452MA
}vcama_caloc_enum;

typedef enum
{
	VCAMA_DEFAULT_MILLER_CAPACITOR = 0,
	VCAMA_INCREASE_MILLER_CAPACITOR
}vcama_cm_enum;

// (0x31) LDO CTRL 24 VWIFI3V3
typedef enum
{
	VWIFI3V3_2_8 = 0,
	VWIFI3V3_3_0,
	VWIFI3V3_3_3,
	VWIFI3V3_2_5
}vwifi3v3_sel_enum;
typedef enum
{
	VWIFI3V3_BIAS_CURRENT_X_1_0 = 0,
	VWIFI3V3_BIAS_CURRENT_X_0_5,
	VWIFI3V3_BIAS_CURRENT_X_2_0,
	VWIFI3V3_BIAS_CURRENT_X_3_0
}vwifi3v3_ical_en_enum;

// (0x32) LDO CTRL 25 VWIFI3V3
typedef enum
{
	VWIFI3V3_MAX_SLEW_RATE_TIMES_1_OVER_17 = 0,
	VWIFI3V3_MAX_SLEW_RATE_TIMES_1_OVER_21,
	VWIFI3V3_MAX_SLEW_RATE,
	VWIFI3V3_MAX_SLEW_RATE_TIMES_1_OVER_5
}vwifi3v3_calst_enum;
typedef enum
{
	VWIFI3V3_OC_THRESHOLD_600MA = 0,
	VWIFI3V3_OC_THRESHOLD_657MA,
	VWIFI3V3_OC_THRESHOLD_486MA,
	VWIFI3V3_OC_THRESHOLD_543MA
}vwifi3v3_caloc_enum;

typedef enum
{
	VWIFI3V3_DEFAULT_MILLER_CAPACITOR = 0,
	VWIFI3V3_INCREASE_MILLER_CAPACITOR
}vwifi3v3_cm_enum;

// (0x34) LDO CTRL 27 VWIFI2V8
typedef enum
{
	VWIFI2V8_2_8 = 0,
	VWIFI2V8_3_0,
	VWIFI2V8_3_3,
	VWIFI2V8_2_5
}vwifi2v8_sel_enum;
typedef enum
{
	VWIFI2V8_BIAS_CURRENT_X_1_0 = 0,
	VWIFI2V8_BIAS_CURRENT_X_0_5,
	VWIFI2V8_BIAS_CURRENT_X_2_0,
	VWIFI2V8_BIAS_CURRENT_X_3_0
}vwifi2v8_ical_en_enum;

// (0x35) LDO CTRL 28 VWIFI2V8
typedef enum
{
	VWIFI2V8_MAX_SLEW_RATE_TIMES_1_OVER_17 = 0,
	VWIFI2V8_MAX_SLEW_RATE_TIMES_1_OVER_21,
	VWIFI2V8_MAX_SLEW_RATE,
	VWIFI2V8_MAX_SLEW_RATE_TIMES_1_OVER_5
}vwifi2v8_calst_enum;
typedef enum
{
	VWIFI2V8_OC_THRESHOLD_300MA = 0,
	VWIFI2V8_OC_THRESHOLD_329MA,
	VWIFI2V8_OC_THRESHOLD_243MA,
	VWIFI2V8_OC_THRESHOLD_271MA
}vwifi2v8_caloc_enum;

typedef enum
{
	VWIFI2V8_DEFAULT_MILLER_CAPACITOR = 0,
	VWIFI2V8_INCREASE_MILLER_CAPACITOR
}vwifi2v8_cm_enum;

// (0x37) LDO CTRL 30 VSIM
typedef enum
{
	VSIM_1_3V = 0,
	VSIM_1_5V,
	VSIM_1_8V,
	VSIM_2_5V,
	VSIM_2_8V,
	VSIM_3_0V,
	VSIM_3_3V,
	VSIM_1_2V
}vsim_sel_enum;
typedef enum
{
	VSIM_BIAS_CURRENT_X_1_0 = 0,
	VSIM_BIAS_CURRENT_X_0_5,
	VSIM_BIAS_CURRENT_X_2_0,
	VSIM_BIAS_CURRENT_X_3_0
}vsim_ical_en_enum;

// (0x3A) LDO CTRL 33 VUSB
typedef enum
{
	VUSB_1_3 = 0,
	VUSB_1_5,
	VUSB_1_8,
	VUSB_2_5,
	VUSB_2_8,
	VUSB_3_0,
	VUSB_3_3,
	VUSB_1_2			// TTTTTTTTTTTTTT
}vusb_sel_enum;
typedef enum
{
	VUSB_BIAS_CURRENT_X_1_0 = 0,
	VUSB_BIAS_CURRENT_X_0_5,
	VUSB_BIAS_CURRENT_X_2_0,
	VUSB_BIAS_CURRENT_X_3_0
}vusb_ical_en_enum;

// (0x3B) LDO CTRL 34 VUSB
typedef enum
{
	VUSB_MAX_SLEW_RATE_TIMES_1_OVER_17 = 0,
	VUSB_MAX_SLEW_RATE_TIMES_1_OVER_21,
	VUSB_MAX_SLEW_RATE,
	VUSB_MAX_SLEW_RATE_TIMES_1_OVER_5
}vusb_calst_enum;
typedef enum
{
	VUSB_OC_THRESHOLD_200MA = 0,
	VUSB_OC_THRESHOLD_218MA,
	VUSB_OC_THRESHOLD_164MA,
	VUSB_OC_THRESHOLD_182MA
}vusb_caloc_enum;

// (0x3D) LDO CTRL 36 VBT
typedef enum
{
	VBT_1_3 = 0,
	VBT_1_5,
	VBT_1_8,
	VBT_2_5,
	VBT_2_8,
	VBT_3_0,
	VBT_3_3,
	VBT_1_2			// TTTTTTTTTTTTTT
}vbt_sel_enum;

typedef enum
{
	VBT_E3_1_5 = 0,	
	VBT_E3_1_3,
	VBT_E3_2_5,
	VBT_E3_1_8,
	VBT_E3_3_0,	
	VBT_E3_2_8,
	VBT_E3_3_3
	//VBT_E3_3_3
}vbt_e3_sel_enum;

typedef enum
{
	VBT_BIAS_CURRENT_X_1_0 = 0,
	VBT_BIAS_CURRENT_X_0_5,
	VBT_BIAS_CURRENT_X_2_0,
	VBT_BIAS_CURRENT_X_3_0
}vbt_ical_en_enum;

// (0x3E) LDO CTRL 37 VBT
typedef enum
{
	VBT_MAX_SLEW_RATE_TIMES_1_OVER_17 = 0,
	VBT_MAX_SLEW_RATE_TIMES_1_OVER_21,
	VBT_MAX_SLEW_RATE,
	VBT_MAX_SLEW_RATE_TIMES_1_OVER_5
}vbt_calst_enum;
typedef enum
{
	VBT_OC_THRESHOLD_200MA = 0,
	VBT_OC_THRESHOLD_218MA,
	VBT_OC_THRESHOLD_164MA,
	VBT_OC_THRESHOLD_182MA
}vbt_caloc_enum;

// (0x40) LDO CTRL 39 VCAMD
typedef enum
{
	VCAMD_1_3 = 0,
	VCAMD_1_5,
	VCAMD_1_8,
	VCAMD_2_5,
	VCAMD_2_8,
	VCAMD_3_0,
	VCAMD_3_3,
	VCAMD_1_2			// TTTTTTTTTTTTTT
}vcamd_sel_enum;
typedef enum
{
	VCAMD_BIAS_CURRENT_X_1_0 = 0,
	VCAMD_BIAS_CURRENT_X_0_5,
	VCAMD_BIAS_CURRENT_X_2_0,
	VCAMD_BIAS_CURRENT_X_3_0
}vcamd_ical_en_enum;

// (0x41) LDO CTRL 40 VCAMD
typedef enum
{
	VCAMD_MAX_SLEW_RATE_TIMES_1_OVER_17 = 0,
	VCAMD_MAX_SLEW_RATE_TIMES_1_OVER_21,
	VCAMD_MAX_SLEW_RATE,
	VCAMD_MAX_SLEW_RATE_TIMES_1_OVER_5
}vcamd_calst_enum;
typedef enum
{
	VCAMD_OC_THRESHOLD_200MA = 0,
	VCAMD_OC_THRESHOLD_218MA,
	VCAMD_OC_THRESHOLD_164MA,
	VCAMD_OC_THRESHOLD_182MA
}vcamd_caloc_enum;

// (0x43) LDO CTRL 42 VGP
typedef enum
{
	VGP_1_3 = 0,
	VGP_1_5,
	VGP_1_8,
	VGP_2_5,
	VGP_2_8,
	VGP_3_0,
	VGP_3_3
}vgp_sel_enum;

// (0x46) LDO CTRL 45 VSDIO
typedef enum
{
	VSDIO_BIAS_CURRENT_X_1_0 = 0,
	VSDIO_BIAS_CURRENT_X_0_5,
	VSDIO_BIAS_CURRENT_X_2_0,
	VSDIO_BIAS_CURRENT_X_3_0
}vsdio_ical_en_enum;

// (0x47) LDO CTRL 46 VSDIO
typedef enum
{
	VSDIO_MAX_SLEW_RATE_TIMES_1_OVER_17 = 0,
	VSDIO_MAX_SLEW_RATE_TIMES_1_OVER_21,
	VSDIO_MAX_SLEW_RATE,
	VSDIO_MAX_SLEW_RATE_TIMES_1_OVER_5
}vsdio_calst_enum;
typedef enum
{
	VSDIO_OC_THRESHOLD_700MA = 0,
	VSDIO_OC_THRESHOLD_767MA,
	VSDIO_OC_THRESHOLD_567MA,
	VSDIO_OC_THRESHOLD_633MA
}vsdio_caloc_enum;
typedef enum
{
	VSDIO_2_8 = 0,
	VSDIO_3_0
}vsdio_sel_enum;
typedef enum
{
	VSDIO_DEFAULT_MILLER_CAPACITOR = 0,
	VSDIO_INCREASE_MILLER_CAPACITOR
}vsdio_cm_enum;


// (0x53) BUCK CTRL 11 VCORE2
typedef enum
{
	VCORE2_ENABLE_WITH_EN_PASS = 0,
	VCORE2_ENABLE_WITH_VCORE2_EN
}vcore2_on_sel_enum;

// (0x5C) BOOST CTRL 1 BOOST1
typedef enum
{
	VBOOST1_VOL_3_20_V = 0,
	VBOOST1_VOL_3_35_V,
	VBOOST1_VOL_3_50_V,
	VBOOST1_VOL_3_65_V,
	VBOOST1_VOL_3_80_V,
	VBOOST1_VOL_3_95_V,
	VBOOST1_VOL_4_10_V,
	VBOOST1_VOL_4_25_V,
	VBOOST1_VOL_4_40_V,
	VBOOST1_VOL_4_55_V,
	VBOOST1_VOL_4_70_V,
	VBOOST1_VOL_4_85_V,
	VBOOST1_VOL_5_00_V,
	VBOOST1_VOL_5_15_V,
	VBOOST1_VOL_5_30_V,
	VBOOST1_VOL_5_45_V
}vboost1_tune_enum;

// (0x5D) BOOST CTRL 2 BOOST1
typedef enum
{
	BOOST1_SOFT_START_SPEED = 0,
	BOOST1_SOFT_START_SPEED_TIMES_2_OVER_3
}boost1_soft_st_speed_enum;

// (0x5F) BOOST CTRL 4 BOOST2
typedef enum
{
	VBOOST2_VOL_6_00_V = 0,
	VBOOST2_VOL_6_75_V,
	VBOOST2_VOL_7_50_V,
	VBOOST2_VOL_8_25_V,
	VBOOST2_VOL_9_00_V,
	VBOOST2_VOL_9_75_V,
	VBOOST2_VOL_10_05_V,
	VBOOST2_VOL_11_25_V,
	VBOOST2_VOL_12_00_V,
	VBOOST2_VOL_12_75_V,
	VBOOST2_VOL_13_50_V,
	VBOOST2_VOL_14_25_V,
	VBOOST2_VOL_15_00_V,
	VBOOST2_VOL_15_75_V,
	VBOOST2_VOL_16_50_V,
	VBOOST2_VOL_17_25_V
}vboost2_tune_enum;

typedef enum
{
	BOOST2_OC_THRESHOLD_5UA = 0,
	BOOST2_OC_THRESHOLD_2UA,
	BOOST2_OC_THRESHOLD_10UA,
	BOOST2_OC_THRESHOLD_7UA
}boost2_oc_th_enum;

typedef enum
{
	BOOST2_DIGITAL_DIMING = 0,
	BOOST2_ANALOG_DIMING
}boost2_dim_source_enum;

// (0x61) BOOST CTRL 6 BOOST2 and BOOST
typedef enum
{
	BOOST_MODE_TYPE_I = 0,
	BOOST_MODE_TYPE_II,
	BOOST_MODE_TYPE_III,
	BOOST_MODE_TYPE_IV
}boost_mode_sel_enum;

// (0x65) DRIVER CTRL 4 FLASH
//typedef enum
//{
//	FLASH_CURRENT_0MA=0,
//	FLASH_CURRENT_50MA,
//	FLASH_CURRENT_100MA,
//	FLASH_CURRENT_150MA,
//	FLASH_CURRENT_200MA,
//	FLASH_CURRENT_250MA,
//	FLASH_CURRENT_300MA,
//	FLASH_CURRENT_350MA,
//	FLASH_CURRENT_400MA,
//	FLASH_CURRENT_450MA,
//	FLASH_CURRENT_500MA,
//	FLASH_CURRENT_550MA
//}flash_i_tune_enum;

// (0x68) DRIVER CTRL 7 BL
typedef enum
{
	BL_I_CORSE_TUNE_4MA = 0,
	BL_I_CORSE_TUNE_8MA,
	BL_I_CORSE_TUNE_12MA,
	BL_I_CORSE_TUNE_16MA,
	BL_I_CORSE_TUNE_20MA,
	BL_I_CORSE_TUNE_24MA,
	BL_I_CORSE_TUNE_28MA,
	BL_I_CORSE_TUNE_32MA
}bl_i_corse_tune_enum;

typedef enum
{
	BL_I_FINE_TUNE_0MA = 0,
	BL_I_FINE_TUNE_MINUS_1MA,
	BL_I_FINE_TUNE_MINUS_2MA,
	BL_I_FINE_TUNE_MINUS_3MA,
	BL_I_FINE_TUNE_PLUS_4MA,
	BL_I_FINE_TUNE_PLUS_3MA,
	BL_I_FINE_TUNE_PLUS_2MA,
	BL_I_FINE_TUNE_PLUS_1MA
}bl_i_fine_tune_enum;

// (0x6D) DRIVER CTRL 12 BL
typedef enum
{
	BL_NUM_1 = 0,
	BL_NUM_2,
	BL_NUM_3,
	BL_NUM_4,
	BL_NUM_5,
	BL_NUM_6,
	BL_NUM_7,
	BL_NUM_8
}bl_number_enum;

// (0x74) CLASS_D CTRL 4 SPKL
typedef enum
{
	SPKL_FB_FORCED_DTIN_DTIP = 0,
	SPKL_FF_FORCED_DTIN_DTIP,
	SPKL_FB_AUTO_CAL_DTCN_DTCP,
	SPKL_FF_AUTO_CAL_DTCN_DTCP
}spkl_dmode_enum;

typedef enum
{
	SPKL_DTCAL_ENABLE_CLASS_D_R_READ_TIME_CAL = 0,
	SPKL_DTCAL_DISABLE_CLASS_D_R_READ_TIME_CAL
}spkl_dtcal_enum;

// (0x75) CLASS_D CATRL 5 SPKL
typedef enum
{
	SPKL_2_4_BUFFER = 0,
	SPKL_1_4_BUFFER = 1,
	SPKL_4_4_BUFFER = 2,
	SPKL_3_4_BUFFER = 3
}spkl_slew_enum;


// (0x76) CLASS_D CTRL 6 SPKL
typedef enum
{
	SPKL_VOL_6DB    = 0,
	SPKL_VOL_9DB    = 1,
	SPKL_VOL_12DB   = 2,
	SPKL_VOL_15DB	= 3,
	SPKL_VOL_18DB	= 4,
	SPKL_VOL_21DB	= 5,
	SPKL_VOL_24DB	= 6,
	SPKL_VOL_27DB	= 7
}spkl_vol_enum;


// (0x77) CLASS_D CTRL 7 SPKL
typedef enum
{
	SPKL_OC_DISABLE  = 0,
	SPKL_OC_ENABLE   = 1
}spkl_oc_enum;



// (0x79) CLASS_D CTRL 9 SPKR
typedef enum
{
	SPKR_FB_FORCED_DTIN_DTIP = 0,
	SPKR_FF_FORCED_DTIN_DTIP,
	SPKR_FB_AUTO_CAL_DTCN_DTCP,
	SPKR_FF_AUTO_CAL_DTCN_DTCP
}spkr_dmode_enum;

typedef enum
{
	SPKR_DTCAL_ENABLE_CLASS_D_R_READ_TIME_CAL = 0,
	SPKR_DTCAL_DISABLE_CLASS_D_R_READ_TIME_CAL
}spkr_dtcal_enum;

// (0x7A) CLASS_D CTRL 10 SPKR
typedef enum
{
	SPKR_2_4_BUFFER = 0,
	SPKR_1_4_BUFFER = 1,
	SPKR_4_4_BUFFER = 2,
	SPKR_3_4_BUFFER = 3
}spkr_slew_enum;



// (0x7B) CLASS_D CTRL 11 SPKR

typedef enum
{
	SPKR_VOL_6DB    = 0,
	SPKR_VOL_9DB    = 1,
	SPKR_VOL_12DB   = 2,
	SPKR_VOL_15DB	= 3,
	SPKR_VOL_18DB	= 4,
	SPKR_VOL_21DB	= 5,
	SPKR_VOL_24DB	= 6,
	SPKR_VOL_27DB	= 7
}spkr_vol_enum;

// (0x7C) CLASS_D CTRL 12 SPKL  Overcurrent setting
typedef enum
{
	SPKR_OC_DISABLE  = 0,
	SPKR_OC_ENABLE   = 1
}spkr_oc_enum;



// (0x81) CHARGER CTRL 1
typedef enum
{
	CHR_CURRENT_OFFSET_NO = 0,
	CHR_CURRENT_OFFSET_PLUS_1_STEP = 1,
	CHR_CURRENT_OFFSET_PLUS_2_STEP = 2,
	CHR_CURRENT_OFFSET_MINUS_2_STEP = 6,
	CHR_CURRENT_OFFSET_MINUS_1_STEP = 7
}cht_chr_offset_enum;

typedef enum
{
	CHR_CURRENT_50MA = 0,
	CHR_CURRENT_90MA,
	CHR_CURRENT_150MA,
	CHR_CURRENT_225MA,
	CHR_CURRENT_300MA,
	CHR_CURRENT_450MA,
	CHR_CURRENT_650MA,
	CHR_CURRENT_800MA
}chr_chr_current_enum;

// (0x83) TESTMODE CTRL 3 Analog Switch
//typedef enum
//{
//	ASW_ASEL_ASW_2_SETS = 0,
//	ASW_ASEL_SIMLS,
//	ASW_ASEL_ASW_1_SET,
//	ASW_ASEL_BL_CURRENT_SOURCE
//}asw_asel_enum;
typedef enum
{
	ASW_ASEL_ISINK_6_8_AS = 0,			// ISINK 6~8 used as Analog Switch, others for BL
	ASW_ASEL_ALL_ISINK_BL = 3				// All ISINK used for BL
}asw_asel_enum;


typedef enum
{
	HI_Z = 0,
	RECEIVER,
	TWO_OF_RGB_DRIVER
	// TODO, the last item value
}asw_bsel_enum;

// (0x84) TESTMODE CTRL 4 Testmode
typedef enum
{
	VGP2_ENABLE_WITH_SRCLKEN = 0,
	VGP2_ENABLE_WITH_VGP2_EN
}vgp2_on_sel_enum;


// (0x89) INT CTRL 1
typedef enum
{
	INT_EN_VCORE2_OC	= 0x01,
	INT_EN_VPA_OC		= 0x02,
	INT_EN_BOOST1_OC	= 0x04,
	INT_EN_BOOST2_OC	= 0x08,
	INT_EN_SPKL_OC		= 0x10,
	INT_EN_SPKR_OC		= 0x20,
	INT_EN_V3GTX_OC	= 0x40,
	INT_EN_V3GRX_OC	= 0x80,
	INT_EN_0X89_ALL	= 0xFF,
	INT1_EN_ALL			= 0xFF
}int_ctrl_1_enum;

// (0x8A) INT CTRL 2
typedef enum
{
	INT_EN_RF_OC			= 0x01,
	INT_EN_VTCXO_OC		= 0x02,
	INT_EN_VCAMA_OC		= 0x04,
	INT_EN_VWIFI3V3_OC	= 0x08,
	INT_EN_VWIFI2V8_OC	= 0x10,
	INT_EN_VSIM_OC			= 0x20,
	INT_EN_VBT_OC			= 0x40,
	INT_EN_VCAMD_OC		= 0x80,
	INT_EN_0X8A_ALL		= 0xFF,
	INT2_EN_ALL				= 0xFF
}int_ctrl_2_enum;

// (0x8B) INT CTRL 3
typedef enum
{
	INT_EN_VSDIO_OC		= 0x01,
	INT_EN_VGP_OC			= 0x02,
	INT_EN_VUSB_OC			= 0x04,
	INT_EN_CHRDET			= 0x08,
	INT_EN_OVP				= 0x10,
	INT_EN_WATCHDOG		= 0x20,
	INT_EN_PWRKEY		= 0x40,
	INT_EN_0X8B_ALL		= 0x7F,
	INT3_EN_ALL				= 0x7F
}int_ctrl_3_enum;


// (0x96) WATCHDOG CTRL and INT CTRL 4
typedef enum
{
	WDT_TIMEOUT_4_SEC = 0,
	WDT_TIMEOUT_8_SEC,
	WDT_TIMEOUT_16_SEC,
	WDT_TIMEOUT_32_SEC
}wdt_timout_enum;


// Combinational functions structures
typedef enum
{
	VGP2_1_3 = 0,
	VGP2_1_5,
	VGP2_1_8,
	VGP2_2_5,
	VGP2_2_8,
	VGP2_3_0,
	VGP2_3_3
}vgp2_sel_enum;


typedef enum
{
	ST_VWIFI3V3_200US = 0,
	ST_VWIFI3V3_400US,	
	ST_VWIFI3V3_600US,
	ST_VWIFI3V3_800US 
}st_gear_vwifi3v3;

typedef enum
{
	ST_VWIFI2V8_200US = 0,
	ST_VWIFI2V8_400US,	
	ST_VWIFI2V8_600US,
	ST_VWIFI2V8_800US 
}st_gear_vwifi2v8;

typedef enum
{
	ST_VSDIO_200US = 0,
	ST_VSDIO_400US,	
	ST_VSDIO_600US,
	ST_VSDIO_800US 
}st_gear_vsdio;

typedef enum
{
	OC_VWIFI3V3_100US = 0,
	OC_VWIFI3V3_200US,	
	OC_VWIFI3V3_400US,
	OC_VWIFI3V3_800US 
}oc_gear_vwifi3v3;

typedef enum
{
	OC_VWIFI2V8_100US = 0,
	OC_VWIFI2V8_200US,	
	OC_VWIFI2V8_400US,
	OC_VWIFI2V8_800US 
}oc_gear_vwifi2v8;

typedef enum
{
	OC_VSDIO_100US = 0,
	OC_VSDIO_200US,	
	OC_VSDIO_400US,
	OC_VSDIO_800US 
}oc_gear_vsdio;


extern void dcl_pmic6326_ChrDet_Registration(chr_callback_type type, void (*Callback)(void));

// (0x09) STATUS 6 (RO)
extern kal_bool dcl_pmic6326_boost2_oc_status(void);
extern kal_bool dcl_pmic6326_spkr_oc_det_status(void);
extern kal_bool dcl_pmic6326_spkl_oc_det_status(void);
extern kal_bool dcl_pmic6326_pwrkey_deb_status(void);
extern kal_bool dcl_pmic6326_ovp_status(void);
extern kal_bool dcl_pmic6326_chrdet_status(void);
extern kal_bool dcl_pmic6326_bat_on_status(void);
extern kal_bool dcl_pmic6326_cv_status(void);

// (0x0B) INT STATUS 1 (RO)
extern kal_uint8 dcl_pmic6326_int_status_1(void);

// (0x0C) INT STATUS 2 (RO)
extern kal_uint8 dcl_pmic6326_int_status_2(void);

// (0x0D) INT STATUS 3 (RO)
extern kal_uint8 dcl_pmic6326_int_status_3(void);
extern kal_bool dcl_pmic6326_vsdio_oc_int_status(void);
extern kal_bool dcl_pmic6326_vgp_oc_int_status(void);
extern kal_bool dcl_pmic6326_vusb_oc_int_status(void);
extern kal_bool dcl_pmic6326_ovp_int_status(void);
extern kal_bool dcl_pmic6326_chrdet_int_status(void);


// (0x0E) INT STATUS 4 (RO)
extern kal_uint8 dcl_pmic6326_int_status_4(void);
extern kal_bool dcl_pmic6326_watchdog_int_status(void);
extern void dcl_pmic6326_watchdog_clear(void);

// (0x1B) LDO CTRL 2 VRF
extern void dcl_pmic6326_vrf_ical_en(vrf_ical_en_enum sel);
extern void dcl_pmic6326_vrf_oc_auto_off(kal_bool auto_off);
extern void dcl_pmic6326_vrf_enable(kal_bool enable);
extern void dcl_pmic6326_vrf_cal(kal_uint8 val);

// (0x1C) LDO CTRL 3 VRF
extern void dcl_pmic6326_vrf_calst(vrf_calst_enum sel);
extern void dcl_pmic6326_vrf_caloc(vrf_caloc_enum sel);
extern void dcl_pmic6326_vrf_on_sel(vrf_on_sel_enum sel);
extern void dcl_pmic6326_vrf_en_force(kal_bool enable);
extern void dcl_pmic6326_vrf_plnmos_dis(kal_bool disable);
extern void dcl_pmic6326_vrf_cm(vrf_cm_enum sel);

// (0x1E) LDO CTRL 5 VTCXO
extern void dcl_pmic6326_vtcxo_ical_en(vtcxo_ical_en_enum sel);
extern void dcl_pmic6326_vtcxo_oc_auto_off(kal_bool auto_off);
extern void dcl_pmic6326_vtcxo_enable(kal_bool enable);
extern void dcl_pmic6326_vtcxo_cal(kal_uint8 val);

// (0x1F) LDO CTRL 6 VTCXO
extern void dcl_pmic6326_vtcxo_calst(vtcxo_calst_enum sel);
extern void dcl_pmic6326_vtcxo_caloc(vtcxo_caloc_enum sel);
extern void dcl_pmic6326_vtcxo_on_sel(vtcxo_on_sel_enum sel);
extern void dcl_pmic6326_vtcxo_en_force(kal_bool enable);
extern void dcl_pmic6326_vtcxo_plnmos_dis(kal_bool disable);
extern void dcl_pmic6326_vtcxo_cm(vtcxo_cm_enum sel);

// (0x21) LDO CTRL 8 V3GTX
extern void dcl_pmic6326_v3gtx_sel(v3gtx_vol vol);
extern void dcl_pmic6326_v3gtx_ical_en(v3gtx_ical_en_enum sel);
extern void dcl_pmic6326_v3gtx_cal(kal_uint8 val);

// (0x22) LDO CTRL 9 V3GTX
extern void dcl_pmic6326_v3gtx_calst(v3gtx_calst_enum sel);
extern void dcl_pmic6326_v3gtx_caloc(v3gtx_caloc_enum sel);
extern void dcl_pmic6326_v3gtx_oc_auto_off(kal_bool auto_off);
extern void dcl_pmic6326_v3gtx_enable(kal_bool enable);
extern void dcl_pmic6326_v3gtx_on_sel(v3gtx_on_sel_enum sel);
extern void dcl_pmic6326_v3gtx_en_force(kal_bool enable);

// (0x24) LDO CTRL 11 V3GRX
extern void dcl_pmic6326_v3grx_sel(v3grx_vol vol);
extern void dcl_pmic6326_3grx_ical_en(v3grx_ical_en_enum sel);
extern void dcl_pmic6326_v3grx_cal(kal_uint8 val);

// (0x25) LDO CTRL 12 V3GRX
extern void dcl_pmic6326_v3grx_calst(v3grx_calst_enum sel);
extern void dcl_pmic6326_v3grx_caloc(v3grx_caloc_enum sel);
extern void dcl_pmic6326_v3grx_oc_auto_off(kal_bool auto_off);
extern void dcl_pmic6326_v3grx_enable(kal_bool enable);
extern void dcl_pmic6326_v3grx_on_sel(v3grx_on_sel_enum sel);
extern void dcl_pmic6326_v3grx_en_force(kal_bool enable);

// (0x2E) LDO CTRL 21 VCAMA
extern void dcl_pmic6326_vcama_sel(vcama_sel_enum sel);
extern void dcl_pmic6326_vcama_ical_en(vcama_ical_en_enum sel);
extern void dcl_pmic6326_vcama_cal(kal_uint8 val);

// (0x2F) LDO CTRL 22 VCAMA
extern void dcl_pmic6326_vcama_calst(vcama_calst_enum sel);
extern void dcl_pmic6326_vcama_caloc(vcama_caloc_enum sel);
extern void dcl_pmic6326_vcama_enable(kal_bool enable);
extern void dcl_pmic6326_vcama_en_force(kal_bool enable);
extern void dcl_pmic6326_vcama_plnmos_dis(kal_bool disable);
extern void dcl_pmic6326_vcama_cm(vcama_cm_enum sel);

// (0x31) LDO CTRL 24 VWIFI3V3
extern void dcl_pmic6326_vwifi3v3_sel(vwifi3v3_sel_enum sel);
extern void dcl_pmic6326_vwifi3v3_ical_en(vwifi3v3_ical_en_enum sel);
extern void dcl_pmic6326_vwifi3v3_cal(kal_uint8 val);

// (0x32) LDO CTRL 25 VWIFI3V3
extern void dcl_pmic6326_vwifi3v3_calst(vwifi3v3_calst_enum sel);
extern void dcl_pmic6326_vwifi3v3_caloc(vwifi3v3_caloc_enum sel);
extern void dcl_pmic6326_vwifi3v3_enable(kal_bool enable);
extern void dcl_pmic6326_vwifi3v3_en_force(kal_bool enable);
extern void dcl_pmic6326_vwifi3v3_plnmos_dis(kal_bool disable);
extern void dcl_pmic6326_vwifi3v3_cm(vwifi3v3_cm_enum sel);

// (0x34) LDO CTRL 27 VWIFI2V8
extern void dcl_pmic6326_vwifi2v8_sel(vwifi2v8_sel_enum sel);
extern void dcl_pmic6326_vwifi2v8_ical_en(vwifi2v8_ical_en_enum sel);
extern void dcl_pmic6326_vwifi2v8_cal(kal_uint8 val);

// (0x35) LDO CTRL 28 VWIFI2V8
extern void dcl_pmic6326_vwifi2v8_calst(vwifi2v8_calst_enum sel);
extern void dcl_pmic6326_vwifi2v8_caloc(vwifi2v8_caloc_enum sel);
extern void dcl_pmic6326_vwifi2v8_enable(kal_bool enable);
extern void dcl_pmic6326_vwifi2v8_en_force(kal_bool enable);
extern void dcl_pmic6326_vwifi2v8_plnmos_dis(kal_bool disable);
extern void dcl_pmic6326_vwifi2v8_cm(vwifi2v8_cm_enum sel);

// (0x37) LDO CTRL 30 VSIM
//void dcl_pmic6326_vsim_sel(vsim_sel_enum sel);
extern void pmic6326_vsim_sel(vsim_sel_enum sel);
extern void pmic6326_vsim_sel(vsim_sel_enum sel);
extern void dcl_pmic6326_vsim_enable(kal_bool enable);
extern void dcl_pmic6326_vsim_ical_en(vsim_ical_en_enum sel);
extern void dcl_pmic6326_vsim_en_force(kal_bool enable);
extern void dcl_pmic6326_vsim_plnmos_dis(kal_bool disable);

// (0x38) LDO CTRL 31 VSIM
extern void dcl_pmic6326_vsim_cal(kal_uint8 val);

// (0x3A) LDO CTRL 33 VUSB
// USB voltage is NOT opened for change
//extern void dcl_pmic6326_vusb_sel(vusb_sel_enum sel);
extern void dcl_pmic6326_vusb_enable(kal_bool enable);
extern void dcl_pmic6326_vusb_ical_en(vusb_ical_en_enum sel);
extern void dcl_pmic6326_vusb_en_force(kal_bool enable);
extern void dcl_pmic6326_vusb_plnmos_dis(kal_bool disable);

// (0x3B) LDO CTRL 34 VUSB
extern void dcl_pmic6326_vusb_cal(kal_uint8 val);
extern void dcl_pmic6326_vusb_calst(vusb_calst_enum sel);
extern void dcl_pmic6326_vusb_caloc(vusb_caloc_enum sel);

// (0x3D) LDO CTRL 36 VBT
extern void dcl_pmic6326_vbt_sel(vbt_sel_enum sel);
extern void dcl_pmic6326_vbt_enable(kal_bool enable);
extern void dcl_pmic6326_vbt_ical_en(vbt_ical_en_enum sel);
extern void dcl_pmic6326_vbt_en_force(kal_bool enable);
extern void dcl_pmic6326_vbt_plnmos_dis(kal_bool disable);

// (0x3E) LDO CTRL 37 VBT
extern void dcl_pmic6326_vbt_cal(kal_uint8 val);
extern void dcl_pmic6326_vbt_calst(vbt_calst_enum sel);
extern void dcl_pmic6326_vbt_caloc(vbt_caloc_enum sel);

// (0x40) LDO CTRL 39 VCAMD
extern void dcl_pmic6326_vcamd_sel(vcamd_sel_enum sel);
extern void dcl_pmic6326_vcamd_enable(kal_bool enable);
extern void dcl_pmic6326_vcamd_ical_en(vcamd_ical_en_enum sel);
extern void dcl_pmic6326_vcamd_en_force(kal_bool enable);
extern void dcl_pmic6326_vcamd_plnmos_dis(kal_bool disable);

// (0x41) LDO CTRL 40 VCAMD
extern void dcl_pmic6326_vcamd_cal(kal_uint8 val);
extern void dcl_pmic6326_vcamd_calst(vcamd_calst_enum sel);
extern void dcl_pmic6326_vcamd_caloc(vcamd_caloc_enum sel);

// (0x43) LDO CTRL 42 VGP
extern void dcl_pmic6326_vgp_sel(vgp_sel_enum sel);
extern void dcl_pmic6326_vgp_enable(kal_bool enable);

// (0x44) LDO CTRL 43 VGP
extern void dcl_pmic6326_vgp_cal(kal_uint8 val);

// (0x46) LDO CTRL 45 VSDIO
extern void dcl_pmic6326_vsdio_ical_en(vsdio_ical_en_enum sel);
extern void dcl_pmic6326_vsdio_enable(kal_bool enable);
extern void dcl_pmic6326_vsdio_en_force(kal_bool enable);
extern void dcl_pmic6326_vsdio_cal(kal_uint8 val);

// (0x47) LDO CTRL 46 VSDIO
extern void dcl_pmic6326_vsdio_calst(vsdio_calst_enum sel);
extern void dcl_pmic6326_vsdio_caloc(vsdio_caloc_enum sel);
extern void dcl_pmic6326_vsdio_plnmos_dis(kal_bool disable);
extern void dcl_pmic6326_vsdio_sel(vsdio_sel_enum sel);
extern void dcl_pmic6326_vsdio_cm(vsdio_cm_enum sel);

// (0x48) LDO CTRL 47 VSDIO
extern void dcl_pmic6326_vcore1_dvfs_step_inc(kal_uint8 val);

// (0x4E) BUCK CTRL 6 VCORE1
extern void dcl_pmic6326_vcore1_dvfs_0_eco3(kal_uint8 val);

// (0x4F) BUCK CTRL 7 VCORE1
extern void dcl_pmic6326_vcore1_sleep_0_eco3(kal_uint8 val);
extern void dcl_pmic6326_vcore1_dvfs_ramp_enable(kal_bool enable);
extern void dcl_pmic6326_vcore1_dvfs_target_update(kal_bool update);

// (0x51) BUCK CTRL 9 VCORE2
extern void dcl_pmic6326_vcore2_dvfs_0_eco3(kal_uint8 val);


// (0x52) BUCK CTRL 10 VCORE2
extern void dcl_pmic6326_vcore2_enable(kal_bool enable);
extern void dcl_pmic6326_vcore2_sleep_0_eco3(kal_uint8 val);

// (0x53) BUCK CTRL 11 VCORE2
extern void dcl_pmic6326_vcore2_on_sel(vcore2_on_sel_enum sel);

// (0x54)
extern void dcl_pmic6326_vcore2_plnmos_dis(kal_bool disable);


// (0x57) BUCK CTRL 15 VMEM
extern void dcl_pmic6326_vcore1_sleep_1_eco3(kal_uint8 val);
extern void dcl_pmic6326_vcore1_dvfs_1_eco3(kal_uint8 val);

// (0x58) BUCK CTRL 16 VPA
extern void dcl_pmic6326_vpa_tuneh(kal_uint8 value);
extern void dcl_pmic6326_vpa_en_force(kal_bool enable);
extern void dcl_pmic6326_vpa_plnmos_dis(kal_bool disable);
extern void dcl_pmic6326_vpa_enable(kal_bool enable);

// (0x59) BUCK CTRL 17 VPA
extern void dcl_pmic6326_vpa_tunel(kal_uint8 value);

// (0x5A) BUCK CTRL 18 VPA
extern void dcl_pmic6326_vpa_oc_tune(kal_uint8 val);
extern void dcl_pmic6326_vpa_bat_low(kal_bool bat_low);

// (0x5C) BOOST CTRL 1 BOOST1
extern void dcl_pmic6326_vboost1_tune(vboost1_tune_enum sel);
extern void dcl_pmic6326_vboost1_tatt(kal_uint8 val);

// (0x5D) BOOST CTRL 2 BOOST1
extern void dcl_pmic6326_boost1_oc_th(kal_uint8 val);
extern void dcl_pmic6326_boost1_enable(kal_bool enable);
extern void dcl_pmic6326_boost1_pre_sr_con(kal_uint8 val);
extern void dcl_pmic6326_boost1_soft_st_speed(boost1_soft_st_speed_enum sel);

// (0x5E) BOOST CTRL 3 BOOST1
extern void dcl_pmic6326_boost1_dio_sr_con(kal_uint8 val);
extern void dcl_pmic6326_boost1_sync_enable(kal_bool enable);


// (0x5F) BOOST CTRL 4 BOOST2
extern void dcl_pmic6326_boost2_tune(vboost2_tune_enum sel);
extern void dcl_pmic6326_boots2_oc_th(boost2_oc_th_enum sel);
extern void dcl_pmic6326_boost2_dim_source(boost2_dim_source_enum sel);

// (0x60) BOOST CTRL 5 BOOST2
extern void dcl_pmic6326_boost2_pre_sr_con(kal_uint8 val);
extern void dcl_pmic6326_boost2_enable(kal_bool enable);

// (0x61) BOOST CTRL 6 BOOST2 and BOOST
extern void dcl_pmic6326_boost_mode(boost_mode_sel_enum sel);

extern void dcl_pmic6326_vbus_enable(kal_bool enable);

// (0x64) DRIVER CTRL 3 GEN
extern void dcl_pmic6326_igen_drv_isel(kal_uint8 sel);
extern void dcl_pmic6326_igen_drv_force(kal_bool force);
extern void dcl_pmic6326_vgen_drv_bgsel(kal_uint8 sel);

// (0x65) DRIVER CTRL 4 FLASH
extern void dcl_pmic6326_flash_i_tune(kal_uint8 val);
extern void dcl_pmic6326_flash_dim_div(kal_uint8 val);

// (0x66) DRIVER CTRL 5 FLASH
extern void dcl_pmic6326_flash_dim_duty(kal_uint8 duty);
extern void dcl_pmic6326_flash_enable(kal_bool enable);
extern void dcl_pmic6326_flash_bypass(kal_bool bypass);

// (0x67) DRIVER CTRL 6 BL
extern void dcl_pmic6326_bl_dim_duty(kal_uint8 duty);
extern void dcl_pmic6326_bl_enable(kal_bool enable);
extern void dcl_pmic6326_bl_i_cal_enable(kal_bool enable);
extern void dcl_pmic6326_bl_bypass(kal_bool bypass);

// (0x68) DRIVER CTRL 7 BL
extern void dcl_pmic6326_bl_i_corse_tune(bl_i_corse_tune_enum sel);
extern void dcl_pmic6326_bl_i_fine_tune(bl_i_fine_tune_enum sel);

// (0x6D) DRIVER CTRL 12 BL
extern void dcl_pmic6326_bl_dim_div(kal_uint8 val);
extern void dcl_pmic6326_bl_number(bl_number_enum num);

extern void dcl_pmic6326_init_bl(boost_mode_sel_enum boost_mode);

// (0x6E) DRIVER CTRL 13 KP
extern void dcl_pmic6326_kp_dim_div(kal_uint8 val);
extern void dcl_pmic6326_kp_enable(kal_bool enable);

// (0x6F) DRIVER CTRL 14 KP
extern void dcl_pmic6326_kp_dim_duty(kal_uint8 duty);

// (0x70) DRIVER CTRL 15 VIBR
extern void dcl_pmic6326_vibr_dim_div(kal_uint8 val);
extern void dcl_pmic6326_vibr_enable(kal_bool enable);

// (0x71) DRIVER CTRL 16 VIBR
extern void dcl_pmic6326_vibr_dim_duty(kal_uint8 duty);

// (0x72) DRIVER CTRL 17 dim_ck_force_on
extern void dcl_pmic6326_dim_ck_force_on(kal_bool enable);

// (0x73) CLASS_D CTRL 3 SPKL
extern void dcl_pmic6326_spkl_dtin(kal_uint8 val);
extern void dcl_pmic6326_spkl_dtip(kal_uint8 val);

// (0x74) CLASS_D CTRL 4 SPKL
extern void dcl_pmic6326_spkl_dmode(spkl_dmode_enum sel);
extern void dcl_pmic6326_spkl_enable(kal_bool enable);
extern void dcl_pmic6326_spkl_dtcal(spkl_dtcal_enum sel);

// (0x78) CLASS_D CTRL 8 SPKR
extern void dcl_pmic6326_spkr_dtin(kal_uint8 val);
extern void dcl_pmic6326_spkr_dtip(kal_uint8 val);

// (0x79) CLASS_D CTRL 9 SPKR
extern void dcl_pmic6326_spkr_dmode(spkr_dmode_enum sel);
extern void dcl_pmic6326_spkr_enable(kal_bool enable);
extern void dcl_pmic6326_spkr_dtcal(spkr_dtcal_enum sel);


// (0x81) CHARGER CTRL 1
extern void dcl_pmic6326_chr_offset(cht_chr_offset_enum sel);
extern void dcl_pmic6326_chr_ov_th_high(void);
extern void dcl_pmic6326_chr_current(chr_chr_current_enum current);
extern chr_chr_current_enum pmic_get_chr_current(void);

// (0x82) CHARGER CTRL 2
extern void dcl_pmic6326_chr_cv_rt(void);
extern void dcl_pmic6326_chr_force(kal_bool force);
extern void dcl_pmic6326_chr_chr_enable(kal_bool enable);
extern void dcl_pmic6326_chr_cv_tune(void);
// (0x83) TESTMODE CTRL 3 Analog Switch
extern void dcl_pmic6326_asw_asel(asw_asel_enum sel);
extern void dcl_pmic6326_asw_bsel(asw_bsel_enum sel);
extern void dcl_pmic6326_asw_a1sel(kal_uint8 sel);
extern void dcl_pmic6326_asw_a2sel(kal_uint8 sel);
// (0x86) TESTMODE CTRL 6 BB AUXADC Related
extern void dcl_pmic6326_adc_isense_enable(kal_bool enable);
extern void dcl_pmic6326_adc_vbat_enable(kal_bool enable);
extern void dcl_pmic6326_adc_meas_on(kal_bool on);		// exported for controling vbat, isense adc measure at same time

// (0x89) INT CTRL 1
extern void dcl_pmic6326_int_ctrl_1_enable(int_ctrl_1_enum sel, kal_bool enable);
// (0x8A) INT CTRL 2
extern void dcl_pmic6326_int_ctrl_2_enable(int_ctrl_2_enum sel, kal_bool enable);
// (0x8B) INT CTRL 2
extern void dcl_pmic6326_int_ctrl_3_enable(int_ctrl_3_enum sel, kal_bool enable);


// (0x8F) 
extern void dcl_pmic6326_st_gear_vwifi3v3(st_gear_vwifi3v3 gear);
extern void dcl_pmic6326_st_gear_vwifi2v8(st_gear_vwifi2v8 gear);
// (0x90)
extern void dcl_pmic6326_st_gear_vsdio(st_gear_vsdio gear);

// (0x92)
extern void dcl_pmic6326_oc_gear_vwifi3v3(oc_gear_vwifi3v3 gear);
extern void dcl_pmic6326_oc_gear_vwifi2v8(oc_gear_vwifi2v8 gear);
// (0x93)
extern void dcl_pmic6326_oc_gear_vsdio(oc_gear_vsdio gear);




// (0x96) WATCHDOG CTRL and INT CTRL 4
extern void dcl_pmic6326_wdt_timeout(wdt_timout_enum sel);
extern void dcl_pmic6326_intr_polarity(kal_bool is_assert);
extern void dcl_pmic6326_wdt_enable(kal_bool enable);


// Combinational functions
extern void dcl_pmic6326_vgp2_enable(kal_bool enable);
extern void dcl_pmic6326_vgp2_sel(vgp2_sel_enum sel);
extern void dcl_pmic6326_vgp2_on_sel(vgp2_on_sel_enum sel);
extern void dcl_pmic6326_vgp2_sell(kal_uint8 value);
extern void dcl_pmic6326_vgp2_selh(kal_uint8 value);
extern void dcl_pmic6326_vgp2_ocfb_enable(kal_bool enable);
extern void dcl_pmic6326_vsim2_enable(kal_bool enable);
extern void dcl_pmic6326_vsim2_sel(vsim_sel_enum sel);
extern void dcl_pmic6326_spk_enable(kal_bool enable);

extern void dcl_pmic6326_EM_reg_write(kal_uint8 reg, kal_uint8 val);
extern kal_uint8 dcl_pmic6326_EM_reg_read(kal_uint8 reg);

#if defined(DRV_MISC_PMIC_ASSERT_KEEP_CHARGING)
extern void dcl_pmic6326_assert_chaging_kick(void);
#endif // #if defined(DRV_MISC_PMIC_ASSERT_KEEP_CHARGING)

/*
// The following are implemented in custom files
// MoDIS parser skip start
extern void pmic6326_customization_init(void);
extern void pmic6326_cust_vspk_enable(kal_bool enable);
extern void pmic6326_csut_vsim_enable(kal_bool enable);
extern void pmic6326_csut_vsim_sel(pmic_adpt_vsim_volt volt);
extern void pmic6326_csut_vsim2_enable(kal_bool enable);
extern void pmic6326_csut_vsim2_sel(pmic_adpt_vsim_volt sel);
extern void pmic6326_csut_vusb_enable(kal_bool enable);
extern void pmic6326_csut_vcama_enable(kal_bool enable);
extern void pmic6326_csut_vcama_sel(pmic_adpt_vcama_volt vol);
extern void pmic6326_csut_vcamd_enable(kal_bool enable);
extern void pmic6326_csut_vcamd_sel(pmic_adpt_vcamd_volt volt);
// MoDIS parser skip end
*/


// =======================================================================================

/*
typedef enum
{
	VRF,
	VTCXO,
	V3GTX,
	V3GRX,
	VA,
	VIO,
	VRTC,
	VCAMA,
	VCAMD,
	VWIFI3V3,
	VWIFI2V8,
	VSIM,
	VBT,
	VUSB,
	VGP,
	VSIM2=VGP,
	VGP2,
	VSDIO,
	VCORE,
	VCORE1,
	VCORE2,
	VM,
	VMEM,
	VIBR,
	PMU_LDO_BUCK_MAX,
	VRF18,
	VFM,
	VMC
}PMU_LDO_BUCK_LIST_ENUM;

typedef enum
{
	VPA1,
	PMU_VPA_MAX
}PMU_VPA_LIST_ENUM;

typedef enum
{
	CHR,
	PMU_CHR_MAX
}PMU_CHR_LIST_ENUM;

typedef enum
{
	SPK,
	PMU_SPK_MAX
}PMU_SPK_LIST_ENUM;

typedef enum
{
	PMU_ISINK_MAX
}PMU_ISINK_LIST_ENUM;

typedef enum
{
	BOOST1,
	BOOST2,
	PMU_BOOST_MAX
}PMU_BOOST_LIST_ENUM;
*/


#endif // #ifdef PMIC_6326_REG_API
#endif // #ifndef __DCL_PMU6326_SW_H_STRUCT__



