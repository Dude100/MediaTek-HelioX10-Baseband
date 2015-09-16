/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 * 
 * Filename:
 * ---------
 *   dcl_pmu.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for PMU.
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
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_PMU_H_STRUCT__
#define __DCL_PMU_H_STRUCT__


/*******************************************************************************
 * DCL_OPTIONS for PMU
 *******************************************************************************/
#define PMU_OPTIONS

 /*******************************************************************************
 * DCL_CONFIGURE_T for PMU
 *******************************************************************************/

#define PMU_CONFIGS

/*******************************************************************************
 * DCL_EVENT for PMU
 *******************************************************************************/
#define PMU_EVENTS

/* Enum of LDO/BUCK List */
typedef enum
{
	VA12,
	VRTC,
	VMIC,
	VAUDN,
	VAUDP,
	VRF28,
	VRF=VRF28,
	VRF28_1=VRF28,
	VRF28_2,
	VTCXO,
	VTCXO_1=VTCXO,
	VTCXO_2,
	VA25,
	VCAMA,
	VCAMD,
	VCAM_IO,
	VCAM_AF,
	VIO28,
	VUSB,
	VBT,
	VSIM,
	VSIM1 = VSIM,
	VSIM2,
	VIBR,
	VMC,
	VMC1,
	VMCH,
	VCAMA2,
	VCAMD2,
	VFM,
	VM12,
	VM12_1,
	VM12_2,
	VM12_INT,
	VCORE,
	VCORE2,
	VIO18,
	VPA_SW,
	VPROC,
	VRF18,
	VRF18_1=VRF18,
	VRF18_2,
	VRF1,
	VRF2,
	VA28,
	VM,
	VSF,
	VWIFI2V8,
	VWIFI3V3,
	V3GTX,
	V3GRX,
	VGP,
	VGP2,
	VSDIO,
	VDIG,	
	VBUS,
	VA1,
	VA2,
	VMIPI,
	VBACKUP,
	PMU_LDO_BUCK_MAX
}PMU_LDO_BUCK_LIST_ENUM;

/* Enum of VPA List */
typedef enum
{
	VPA,
	VPA1=VPA,
	PMU_VPA_MAX
}PMU_VPA_LIST_ENUM;

/* Enum of VRF18 List */
typedef enum
{
	PMIC_VRF18,
	PMIC_VRF18_1 = PMIC_VRF18,
	PMIC_VRF18_2,
	PMIC_VRF18_MAX
}PMIC_VRF18_LIST_ENUM;

/* Enum of VSIM List */
typedef enum
{
	PMIC_VSIM,
	PMIC_VSIM1 = PMIC_VSIM,
	PMIC_VSIM2,
	PMIC_VSIM_MAX
}PMIC_VSIM_LIST_ENUM;

/* Enum of KPLED List */
typedef enum
{
	KPLED,
	PMU_KPLED_MAX
}PMU_KPLED_LIST_ENUM;

/* Enum of CHR List */
typedef enum
{
	CHR,
	PMU_CHR_MAX
}PMU_CHR_LIST_ENUM;

/* Enum of STARTUP List */
typedef enum
{
	STRUP,
	PMU_STRUP_MAX
}PMU_STRUP_LIST_ENUM;

/* Enum of ISINK List */
typedef enum
{
	ISINK0,
	ISINK1,
	ISINK2,
	ISINK3,
	ISINK4,
    ISINK5,
	PMU_ISINK_MAX
}PMU_ISINK_LIST_ENUM;

/* Enum of BOOST List */
typedef enum
{
	BOOST,
	BOOST1=BOOST,
	BOOST2,
	PMU_BOOST_MAX
}PMU_BOOST_LIST_ENUM;

/* Enum of SPK List */
typedef enum
{
	SPK,
	PMU_SPK_MAX
}PMU_SPK_LIST_ENUM;

/* Enum of LPOSC List */
typedef enum
{
	LPOSC,
	PMU_LPOSC_MAX
}PMU_LPOSC_LIST_ENUM;

/* Enum of Voltage List */
typedef enum
{
	PMU_VOLT_00_000000_V =        0,
	PMU_VOLT_00_100000_V =   100000,
	PMU_VOLT_00_200000_V =   200000,
	PMU_VOLT_00_300000_V =   300000,
	PMU_VOLT_00_400000_V =   400000,
	PMU_VOLT_00_500000_V =   500000,
	PMU_VOLT_00_550000_V =   550000,
	PMU_VOLT_00_600000_V =   600000,
	PMU_VOLT_00_650000_V =   650000,	
	PMU_VOLT_00_700000_V =   700000,
	PMU_VOLT_00_725000_V =   725000,
	PMU_VOLT_00_750000_V =   750000,
	PMU_VOLT_00_775000_V =   775000,
	PMU_VOLT_00_800000_V =   800000,
	PMU_VOLT_00_825000_V =   825000,
	PMU_VOLT_00_850000_V =   850000,
	PMU_VOLT_00_875000_V =   875000,
	PMU_VOLT_00_900000_V =   900000,
	PMU_VOLT_00_925000_V =   925000,
	PMU_VOLT_00_950000_V =   950000,
	PMU_VOLT_00_975000_V =   975000,
	PMU_VOLT_01_000000_V =  1000000,
	PMU_VOLT_01_025000_V =  1025000,
	PMU_VOLT_01_050000_V =  1050000,
        PMU_VOLT_01_060000_V =  1060000,
	PMU_VOLT_01_075000_V =  1075000,
	PMU_VOLT_01_100000_V =  1100000,
	PMU_VOLT_01_125000_V =  1125000,
	PMU_VOLT_01_150000_V =  1150000,
	PMU_VOLT_01_175000_V =  1175000,
	PMU_VOLT_01_200000_V =  1200000,
	PMU_VOLT_01_225000_V =  1225000,
	PMU_VOLT_01_250000_V =  1250000,
	PMU_VOLT_01_275000_V =  1275000,
	PMU_VOLT_01_300000_V =  1300000,
	PMU_VOLT_01_325000_V =  1325000,
	PMU_VOLT_01_350000_V =  1350000,
	PMU_VOLT_01_375000_V =  1375000,
	PMU_VOLT_01_400000_V =  1400000,
	PMU_VOLT_01_425000_V =  1425000,
	PMU_VOLT_01_450000_V =  1450000,
	PMU_VOLT_01_475000_V =  1475000,
	PMU_VOLT_01_500000_V =  1500000,
	PMU_VOLT_01_520000_V =  1520000,
	PMU_VOLT_01_525000_V =  1525000,
	PMU_VOLT_01_540000_V =  1540000,
	PMU_VOLT_01_550000_V =  1550000,
	PMU_VOLT_01_560000_V =  1560000,
	PMU_VOLT_01_575000_V =  1575000,
	PMU_VOLT_01_580000_V =  1580000,
	PMU_VOLT_01_600000_V =  1600000,
	PMU_VOLT_01_620000_V =  1620000,
	PMU_VOLT_01_625000_V =  1625000,
	PMU_VOLT_01_640000_V =  1640000,
	PMU_VOLT_01_650000_V =  1650000,
	PMU_VOLT_01_660000_V =  1660000,
	PMU_VOLT_01_675000_V =  1675000,
	PMU_VOLT_01_680000_V =  1680000,
	PMU_VOLT_01_700000_V =  1700000,
	PMU_VOLT_01_720000_V =  1720000,
	PMU_VOLT_01_725000_V =  1725000,
	PMU_VOLT_01_740000_V =  1740000,
	PMU_VOLT_01_750000_V =  1750000,
	PMU_VOLT_01_760000_V =  1760000,
	PMU_VOLT_01_775000_V =  1775000,
	PMU_VOLT_01_780000_V =  1780000,
	PMU_VOLT_01_800000_V =  1800000,
	PMU_VOLT_01_820000_V =  1820000,
	PMU_VOLT_01_825000_V =  1825000,
	PMU_VOLT_01_840000_V =  1840000,
	PMU_VOLT_01_850000_V =  1850000,
	PMU_VOLT_01_860000_V =  1860000,
	PMU_VOLT_01_875000_V =  1875000,
	PMU_VOLT_01_880000_V =  1880000,
	PMU_VOLT_01_900000_V =  1900000,
	PMU_VOLT_01_920000_V =  1920000,
	PMU_VOLT_01_925000_V =  1925000,
	PMU_VOLT_01_940000_V =  1940000,
	PMU_VOLT_01_950000_V =  1950000,
	PMU_VOLT_01_960000_V =  1960000,
	PMU_VOLT_01_975000_V =  1975000,
	PMU_VOLT_01_980000_V =  1980000,
	PMU_VOLT_02_000000_V =  2000000,
	PMU_VOLT_02_020000_V =  2020000,
	PMU_VOLT_02_025000_V =  2025000,
	PMU_VOLT_02_040000_V =  2040000,
	PMU_VOLT_02_050000_V =  2050000,
	PMU_VOLT_02_060000_V =  2060000,
	PMU_VOLT_02_075000_V =  2075000,
	PMU_VOLT_02_080000_V =  2080000,
	PMU_VOLT_02_100000_V =  2100000,
	PMU_VOLT_02_120000_V =  2120000,
	PMU_VOLT_02_125000_V =  2125000,
	PMU_VOLT_02_140000_V =  2140000,	
	PMU_VOLT_02_150000_V =  2150000,
	PMU_VOLT_02_175000_V =  2175000,
	PMU_VOLT_02_200000_V =  2200000,
	PMU_VOLT_02_225000_V =  2225000,
	PMU_VOLT_02_250000_V =  2250000,
	PMU_VOLT_02_275000_V =  2275000,
	PMU_VOLT_02_300000_V =  2300000,
	PMU_VOLT_02_350000_V =  2350000,
	PMU_VOLT_02_425000_V =  2425000,
	PMU_VOLT_02_400000_V =  2400000,	
	PMU_VOLT_02_450000_V =  2450000,
	PMU_VOLT_02_500000_V =  2500000,
	PMU_VOLT_02_550000_V =  2550000,
	PMU_VOLT_02_575000_V =  2575000,
	PMU_VOLT_02_600000_V =  2600000,
	PMU_VOLT_02_650000_V =  2650000,
	PMU_VOLT_02_700000_V =  2700000,
	PMU_VOLT_02_725000_V =  2725000,
	PMU_VOLT_02_750000_V =  2750000,
	PMU_VOLT_02_760000_V =  2760000,	
	PMU_VOLT_02_800000_V =  2800000,
	PMU_VOLT_02_850000_V =  2850000,
	PMU_VOLT_02_875000_V =  2875000,
	PMU_VOLT_02_900000_V =  2900000,
	PMU_VOLT_02_950000_V =  2950000,
	PMU_VOLT_03_000000_V =  3000000,
	PMU_VOLT_03_025000_V =  3025000,
	PMU_VOLT_03_050000_V =  3050000,
	PMU_VOLT_03_100000_V =  3100000,
	PMU_VOLT_03_150000_V =  3150000,	
	PMU_VOLT_03_175000_V =  3175000,
	PMU_VOLT_03_200000_V =  3200000,	
	PMU_VOLT_03_250000_V =  3250000,
	PMU_VOLT_03_275000_V =  3275000,
	PMU_VOLT_03_300000_V =  3300000,
	PMU_VOLT_03_325000_V =  3325000,
	PMU_VOLT_03_350000_V =  3350000,
	PMU_VOLT_03_400000_V =  3400000,
	PMU_VOLT_03_450000_V =  3450000,	
	PMU_VOLT_03_500000_V =  3500000,
	PMU_VOLT_03_550000_V =  3550000,
	PMU_VOLT_03_600000_V =  3600000,
	PMU_VOLT_03_650000_V =  3650000,
	PMU_VOLT_03_800000_V =  3800000,
	PMU_VOLT_03_950000_V =  3950000,		
	PMU_VOLT_04_000000_V =  4000000,
	PMU_VOLT_04_012500_V =  4012500,
	PMU_VOLT_04_025000_V =  4025000,
	PMU_VOLT_04_037500_V =  4037500,
	PMU_VOLT_04_050000_V =  4050000,
	PMU_VOLT_04_062500_V =  4062500,
	PMU_VOLT_04_067500_V =  4067500,
	PMU_VOLT_04_075000_V =  4075000,
	PMU_VOLT_04_087500_V =  4087500,
	PMU_VOLT_04_100000_V =  4100000,
	PMU_VOLT_04_112500_V =  4112500,
	PMU_VOLT_04_115000_V =  4115000,
	PMU_VOLT_04_116000_V =  4116000,
	PMU_VOLT_04_125000_V =  4125000,
	PMU_VOLT_04_137500_V =  4137500,
	PMU_VOLT_04_150000_V =  4150000,
	PMU_VOLT_04_162500_V =  4162500,
	PMU_VOLT_04_175000_V =  4175000,
	PMU_VOLT_04_187500_V =  4187500,
	PMU_VOLT_04_200000_V =  4200000,
	PMU_VOLT_04_212500_V =  4212500,
	PMU_VOLT_04_225000_V =  4225000,
	PMU_VOLT_04_237500_V =  4237500,
	PMU_VOLT_04_250000_V =  4250000,
	PMU_VOLT_04_262500_V =  4262500,
	PMU_VOLT_04_275000_V =  4275000,
	PMU_VOLT_04_287500_V =  4287500,
	PMU_VOLT_04_300000_V =  4300000,
	PMU_VOLT_04_325000_V =  4325000,
	PMU_VOLT_04_350000_V =  4350000,
	PMU_VOLT_04_375000_V =  4375000,
	PMU_VOLT_04_400000_V =  4400000,
	PMU_VOLT_04_411500_V =  4411500,
	PMU_VOLT_04_450000_V =  4450000,
	PMU_VOLT_04_500000_V =  4500000,
	PMU_VOLT_04_550000_V =  4550000,
	PMU_VOLT_04_600000_V =  4600000,
	PMU_VOLT_04_700000_V =  4700000,
	PMU_VOLT_04_800000_V =  4800000,
	PMU_VOLT_04_850000_V =  4850000,	
	PMU_VOLT_04_950000_V =  4950000,
	PMU_VOLT_05_000000_V =  5000000,	
	PMU_VOLT_05_150000_V =  5150000,
	PMU_VOLT_05_250000_V =  5250000,
	PMU_VOLT_05_300000_V =  5300000,
	PMU_VOLT_05_450000_V =  5450000,
	PMU_VOLT_06_000000_V =  6000000,
	PMU_VOLT_06_500000_V =  6500000,
	PMU_VOLT_06_750000_V =  6750000,
	PMU_VOLT_07_000000_V =  7000000,
	PMU_VOLT_07_250000_V =  7250000,
	PMU_VOLT_07_500000_V =  7500000,
	PMU_VOLT_08_000000_V =  8000000,
	PMU_VOLT_08_500000_V =  8500000,
	PMU_VOLT_09_500000_V =  9500000,
	PMU_VOLT_10_000000_V = 10000000,
	PMU_VOLT_10_500000_V = 10500000,	
	PMU_VOLT_MAX,
	PMU_VOLT_INVALID

}PMU_VOLTAGE_ENUM;

typedef enum
{             
    PMU_VOLT_CAL_MINUS_00_140000_V  =   -140000,
    PMU_VOLT_CAL_MINUS_00_120000_V  =   -120000,
    PMU_VOLT_CAL_MINUS_00_100000_V  =   -100000,
    PMU_VOLT_CAL_MINUS_00_080000_V  =   -80000,
    PMU_VOLT_CAL_MINUS_00_060000_V  =   -60000,
    PMU_VOLT_CAL_MINUS_00_040000_V  =   -40000,    
    PMU_VOLT_CAL_MINUS_00_020000_V  =   -20000,
	PMU_VOLT_CAL_00_000000_V        =   0,
	PMU_VOLT_CAL_00_020000_V        =   20000,    
    PMU_VOLT_CAL_00_040000_V        =   40000,
    PMU_VOLT_CAL_00_060000_V        =   60000,
    PMU_VOLT_CAL_00_080000_V        =   80000,
    PMU_VOLT_CAL_00_100000_V        =   100000,    
    PMU_VOLT_CAL_00_120000_V        =   120000,    
    PMU_VOLT_CAL_00_140000_V        =   140000,        
    PMU_VOLT_CAL_00_160000_V        =   160000,      
	PMU_VOLT_CAL_MAX,
	PMU_VOLT_CAL_INVALID
} PMU_VOLTAGE_CALIBRATION_ENUM;

/* Enum of SPK db List */
typedef enum
{
	PMIC_SPK_VOL_00_00_dB    =    0,
	PMIC_SPK_VOL_00_50_dB    =   50,
	PMIC_SPK_VOL_01_00_dB    =  100,
	PMIC_SPK_VOL_01_50_dB    =  150,
	PMIC_SPK_VOL_02_00_dB    =  200,
	PMIC_SPK_VOL_02_50_dB    =  250,
	PMIC_SPK_VOL_03_00_dB    =  300,
	PMIC_SPK_VOL_03_50_dB    =  350,
	PMIC_SPK_VOL_04_00_dB    =  400,
	PMIC_SPK_VOL_04_50_dB    =  450,
	PMIC_SPK_VOL_05_00_dB    =  500,
	PMIC_SPK_VOL_05_50_dB    =  550,
	PMIC_SPK_VOL_06_00_dB    =  600,
	PMIC_SPK_VOL_06_50_dB    =  650,
	PMIC_SPK_VOL_07_00_dB    =  700,
	PMIC_SPK_VOL_07_50_dB    =  750,
	PMIC_SPK_VOL_08_00_dB    =  800,
	PMIC_SPK_VOL_08_50_dB    =  850,
	PMIC_SPK_VOL_09_00_dB    =  900,
	PMIC_SPK_VOL_09_50_dB    =  950,
	PMIC_SPK_VOL_10_00_dB    = 1000,
	PMIC_SPK_VOL_10_50_dB    = 1050,
	PMIC_SPK_VOL_11_00_dB    = 1100,
	PMIC_SPK_VOL_11_50_dB    = 1150,
	PMIC_SPK_VOL_12_00_dB    = 1200,
	PMIC_SPK_VOL_12_50_dB    = 1250,
	PMIC_SPK_VOL_13_00_dB    = 1300,
	PMIC_SPK_VOL_13_50_dB    = 1350,
	PMIC_SPK_VOL_14_00_dB    = 1400,
	PMIC_SPK_VOL_14_50_dB    = 1450,
	PMIC_SPK_VOL_15_00_dB    = 1500,
	PMIC_SPK_VOL_15_50_dB    = 1550,
	PMIC_SPK_VOL_16_00_dB    = 1600,
	PMIC_SPK_VOL_16_50_dB    = 1650,
	PMIC_SPK_VOL_17_00_dB    = 1700,
	PMIC_SPK_VOL_17_50_dB    = 1750,
	PMIC_SPK_VOL_18_00_dB    = 1800,
	PMIC_SPK_VOL_18_50_dB    = 1850,
	PMIC_SPK_VOL_19_00_dB    = 1900,
	PMIC_SPK_VOL_19_50_dB    = 1950,
	PMIC_SPK_VOL_20_00_dB    = 2000,
	PMIC_SPK_VOL_20_50_dB    = 2050,
	PMIC_SPK_VOL_21_00_dB    = 2100,
	PMIC_SPK_VOL_21_50_dB    = 2150,
	PMIC_SPK_VOL_22_00_dB    = 2200,
	PMIC_SPK_VOL_22_50_dB    = 2250,
	PMIC_SPK_VOL_23_00_dB    = 2300,
	PMIC_SPK_VOL_23_50_dB    = 2350,
	PMIC_SPK_VOL_24_00_dB    = 2400,
	PMIC_SPK_VOL_24_50_dB    = 2450,
	PMIC_SPK_VOL_MAX     = 9900,

	PMU_SPK_VOL_00_00_dB    =    0,
	PMU_SPK_VOL_00_50_dB    =   50,
	PMU_SPK_VOL_01_00_dB    =  100,
	PMU_SPK_VOL_01_50_dB    =  150,
	PMU_SPK_VOL_02_00_dB    =  200,
	PMU_SPK_VOL_02_50_dB    =  250,
	PMU_SPK_VOL_03_00_dB    =  300,
	PMU_SPK_VOL_03_50_dB    =  350,
	PMU_SPK_VOL_04_00_dB    =  400,
	PMU_SPK_VOL_04_50_dB    =  450,
	PMU_SPK_VOL_05_00_dB    =  500,
	PMU_SPK_VOL_05_50_dB    =  550,
	PMU_SPK_VOL_06_00_dB    =  600,
	PMU_SPK_VOL_06_50_dB    =  650,
	PMU_SPK_VOL_07_00_dB    =  700,
	PMU_SPK_VOL_07_50_dB    =  750,
	PMU_SPK_VOL_08_00_dB    =  800,
	PMU_SPK_VOL_08_50_dB    =  850,
	PMU_SPK_VOL_09_00_dB    =  900,
	PMU_SPK_VOL_09_50_dB    =  950,
	PMU_SPK_VOL_10_00_dB    = 1000,
	PMU_SPK_VOL_10_50_dB    = 1050,
	PMU_SPK_VOL_11_00_dB    = 1100,
	PMU_SPK_VOL_11_50_dB    = 1150,
	PMU_SPK_VOL_12_00_dB    = 1200,
	PMU_SPK_VOL_12_50_dB    = 1250,
	PMU_SPK_VOL_13_00_dB    = 1300,
	PMU_SPK_VOL_13_50_dB    = 1350,
	PMU_SPK_VOL_14_00_dB    = 1400,
	PMU_SPK_VOL_14_50_dB    = 1450,
	PMU_SPK_VOL_15_00_dB    = 1500,
	PMU_SPK_VOL_15_50_dB    = 1550,
	PMU_SPK_VOL_16_00_dB    = 1600,
	PMU_SPK_VOL_16_50_dB    = 1650,
	PMU_SPK_VOL_17_00_dB    = 1700,
	PMU_SPK_VOL_17_50_dB    = 1750,
	PMU_SPK_VOL_18_00_dB    = 1800,
	PMU_SPK_VOL_18_50_dB    = 1850,
	PMU_SPK_VOL_19_00_dB    = 1900,
	PMU_SPK_VOL_19_50_dB    = 1950,
	PMU_SPK_VOL_20_00_dB    = 2000,
	PMU_SPK_VOL_20_50_dB    = 2050,
	PMU_SPK_VOL_21_00_dB    = 2100,
	PMU_SPK_VOL_21_50_dB    = 2150,
	PMU_SPK_VOL_22_00_dB    = 2200,
	PMU_SPK_VOL_22_50_dB    = 2250,
	PMU_SPK_VOL_23_00_dB    = 2300,
	PMU_SPK_VOL_23_50_dB    = 2350,
	PMU_SPK_VOL_24_00_dB    = 2400,
	PMU_SPK_VOL_24_50_dB    = 2450,
	PMU_SPK_VOL_MAX     = 9900
}PMU_SPK_VOL_ENUM;

/* Enum of charger current List */
typedef enum
{
	PMU_CHARGE_CURRENT_0_00_MA = 0,
	PMU_CHARGE_CURRENT_50_00_MA = 5000,
	PMU_CHARGE_CURRENT_62_50_MA = 6250,
	PMU_CHARGE_CURRENT_70_00_MA = 7000,
	PMU_CHARGE_CURRENT_75_00_MA = 7500,
	PMU_CHARGE_CURRENT_87_50_MA = 8750,	
	PMU_CHARGE_CURRENT_100_00_MA = 10000,
	PMU_CHARGE_CURRENT_150_00_MA = 15000,
	PMU_CHARGE_CURRENT_200_00_MA = 20000,
	PMU_CHARGE_CURRENT_225_00_MA = 22500,	
	PMU_CHARGE_CURRENT_250_00_MA = 25000,
	PMU_CHARGE_CURRENT_300_00_MA = 30000,
	PMU_CHARGE_CURRENT_350_00_MA = 35000,
	PMU_CHARGE_CURRENT_400_00_MA = 40000,
	PMU_CHARGE_CURRENT_425_00_MA = 42500,	
	PMU_CHARGE_CURRENT_450_00_MA = 45000,
	PMU_CHARGE_CURRENT_500_00_MA = 50000,
	PMU_CHARGE_CURRENT_550_00_MA = 55000,
	PMU_CHARGE_CURRENT_600_00_MA = 60000,
	PMU_CHARGE_CURRENT_650_00_MA = 65000,
	PMU_CHARGE_CURRENT_700_00_MA = 70000,
	PMU_CHARGE_CURRENT_750_00_MA = 75000,
	PMU_CHARGE_CURRENT_800_00_MA = 80000,
	PMU_CHARGE_CURRENT_850_00_MA = 85000,
	PMU_CHARGE_CURRENT_900_00_MA = 90000,
	PMU_CHARGE_CURRENT_950_00_MA = 95000,
	PMU_CHARGE_CURRENT_1000_00_MA = 100000,
	PMU_CHARGE_CURRENT_1200_00_MA = 120000,
	PMU_CHARGE_CURRENT_1500_00_MA = 150000,
	PMU_CHARGE_CURRENT_1800_00_MA = 180000,
	PMU_CHARGE_CURRENT_2000_00_MA = 200000,
	PMU_CHARGE_CURRENT_MAX
}PMU_CHR_CURRENT_ENUM;


/* Enum of VPA output select List */
typedef enum
{
	PMU_VPA0,
	PMU_VPA1,
	PMU_VPA2,
	PMU_VPA3,
	PMU_VPA4,
	PMU_VPA5,
	PMU_VPA6,
	PMU_VPA7	
}PMU_VPA_ENUM;

/* Enum of on select List */
typedef enum
{
	ENABLE_WITH_SRCLKEN = 0,
	ENABLE_LDO_BUCK_EN_REGISTER = 1
}PMU_ON_SEL_ENUM;

/* Enum of on select(PMIC) List */
typedef enum
{
    SW_CONTROL = 0,
    SRCLKEN_CONTROL = 1
}PMIC_ON_SEL_ENUM;

/* Enum of on control(PMIC) List */
typedef enum
{
    SW_CONTROL_BY_REG = 0,
    HW_CONTROL = 1
}PMIC_ON_CTRL_ENUM;

#if defined(MT6320)
/* Enum of srclken select List */
typedef enum
{
	SRCVOLTEN = 0,
	SRCLKEN_PERI,
	SRCLKEN_MD2,
	SRCVOLTEN_OR_SRCLKEN_PERI,
	SRCVOLTEN_OR_SRCLKEN_MD2,
	SRCLKEN_PERI_OR_SRCLKEN_MD2,
	SRCVOLTEN_OR_SRCLKEN_PERI_OR_SRCLKEN_MD2
}PMU_SRCLKEN_SEL_ENUM;

#elif defined(MT6325)
/* Enum of srclken select List */
typedef enum
{
    SRCLKEN_IN0 = 0,
    SRCLKEN_IN1,
	SRCLKEN_IN0_OR_SRCLKEN_IN1,
	SRCLKEN_IN0_AND_SRCLKEN_IN1
}PMU_SRCLKEN_SEL_ENUM;

#else

/* Enum of srclken select List */
typedef enum
{
	SRCLKEN_IN1_AND_SRCLKEN_IN2 = 0,
	SRCLKEN_IN1,
	SRCLKEN_IN2,
	SRCLKEN_IN1_OR_SRCLKEN_IN2 
}PMU_SRCLKEN_SEL_ENUM;
#endif

/* Enum of srclken select List */
typedef enum
{
        SRCLKEN_IN1_SEL = 0,
        SRCLKEN_IN2_SEL,
        SRCLKEN_IN1_OR_SRCLKEN_IN2_SEL,
        SRCLKEN_IN1_AND_SRCLKEN_IN2_SEL
}PMIC_SIGNAL_SEL_ENUM;

/* Enum of remote sense List */
typedef enum
{
	DEFAULT_LOCAL_SENSE= 0,
	REMOTE_SENSE = 1
}PMU_RS_ENUM;

/* Enum of control mode List */
typedef enum
{
	KPLED_PWM_MODE = 0,
	KPLED_REGISTER_CTRL_MODE = 1
}PMU_CTRL_KPLED_MODE_ENUM;

/* Enum of control mode List */
typedef enum
{
	LDO_EN_SEL_BY_CONTROLLER = 0, // The LDO is connected to specific controller and can be controlled directly by the controller
	LDO_EN_SEL_BY_LDO_CON,
	LDO_EN_SEL_MAX = 0xFF
}PMU_CTRL_LDO_CTRL_MODE_ENUM;

/* Enum of control LDO/Buck mode List */
typedef enum
{
	BUCK_MODE = 0,
	LDO_MODE
}PMU_CTRL_BUCK_LDO_CTRL_MODE_ENUM;

/* Enum of control LDO/Buck MODESET list */
typedef enum
{
	AUTO_MODE = 0,
	FORCE_PWM_MODE
}PMU_CTRL_BUCK_LDO_CTRL_MODESET_ENUM;
/* Enum of STB SIO mode List */
typedef enum
{
	HW_ENABLE = 0,
	SW_ENABLE
}PMU_CTRL_STB_SIO_CTRL_MODE_ENUM;

/* Enum of kpled sel List */
typedef enum
{
	KPLED_SEL_1_SWITCH = 0,
	KPLED_SEL_2_SWITCH = 1,
	KPLED_SEL_3_SWITCH = 2,
	KPLED_SEL_4_SWITCH = 3,
	KPLED_SEL_5_SWITCH = 4,
	KPLED_SEL_6_SWITCH = 5,
	KPLED_SEL_7_SWITCH = 6,
	KPLED_SEL_8_SWITCH = 7
}PMU_CTRL_KPLED_SEL_ENUM;

/* Enum of control mode List */
typedef enum
{
	FLASHLED_PWM_MODE = 0,
	FLASHLED_REGISTER_CTRL_MODE = 1
}PMU_CTRL_FLASHLED_MODE_ENUM;

/* Enum of kpled sel List */
typedef enum
{
	FLASHLED_SEL_1_SWITCH = 0,
	FLASHLED_SEL_2_SWITCH = 1,
	FLASHLED_SEL_3_SWITCH = 2,
	FLASHLED_SEL_4_SWITCH = 3,
	FLASHLED_SEL_5_SWITCH = 4,
	FLASHLED_SEL_6_SWITCH = 5,
	FLASHLED_SEL_7_SWITCH = 6,
	FLASHLED_SEL_8_SWITCH = 7
}PMU_CTRL_FLASHLED_SEL_ENUM;

/* Enum of wdt interval List */
typedef enum
{
	PMU_CHR_WDT_TD_4SEC = 40,
	PMU_CHR_WDT_TD_8SEC = 80,
	PMU_CHR_WDT_TD_16SEC = 160,
	PMU_CHR_WDT_TD_32SEC = 320,
	PMU_CHR_WDT_TD_128SEC = 1280,
	PMU_CHR_WDT_TD_256SEC = 2560,
	PMU_CHR_WDT_TD_512SEC = 5120,
	PMU_CHR_WDT_TD_1024SEC = 10240,
	PMU_CHR_WDT_TD_3000SEC = 30000
}PMU_CHR_WDT_TD_ENUM;

/* Enum of control mode List */
typedef enum
{
	ISINK_PWM_MODE = 0,
	ISINK_REGISTER_CTRL_MODE = 1
}PMU_CTRL_ISINK_MODE_ENUM;

/* Enum of ISINK current List */
typedef enum
{
	ISINK_STEP_04_MA = 4,
	ISINK_STEP_05_MA = 5,
	ISINK_STEP_08_MA = 8,	
	ISINK_STEP_10_MA = 10,
	ISINK_STEP_12_MA = 12,
	ISINK_STEP_15_MA = 15,
	ISINK_STEP_16_MA = 16,
	ISINK_STEP_20_MA = 20,
	ISINK_STEP_24_MA = 24	
}PMU_CTRL_ISINK_STEP_ENUM;

/* Enum of spk mode List */
typedef enum{
	SPK_CLASS_D_MODE = 0,
	SPK_CLASS_AB_MODE
}PMU_CTRL_SPK_MODE_ENUM;

/* Enum of spk slew List */
typedef enum{
	SPK_SLEW_RATE_2_OVER_4 = 0,
	SPK_SLEW_RATE_1_OVER_4,
	SPK_SLEW_RATE_4_OVER_4,
	SPK_SLEW_RATE_3_OVER_4
}PMU_CTRL_SPK_SLEW_RATE_ENUM;

/* Enum of spk class D offset calibration pathList */
typedef enum{
	SPK_N = 0,
	SPK_P,        
}PMU_CTRL_SPK_CALI_PATH_ENUM;

/* Enum of control steps List */
typedef enum{
	PMU_CTRL_STEP1,
	PMU_CTRL_STEP2,
	PMU_CTRL_STEP3,
	PMU_CTRL_STEP4	
}PMU_CTRL_STEP_ENUM;

/* Enum of PMIC List */
typedef enum
{
	PMIC_MT_6320 = 0x6320,
	PMIC_MT_6323 = 0x6323,
	PMIC_MT_6325 = 0x6325,
        PMIC_MT_6329 = 0x6329,
  	PMIC_MT_6331 = 0x6331,
	PMIC_MT_6332 = 0x6332,
	PMIC_MT_6339 = 0x6339,	
	PMIC_CHIP_MAX
}PMIC_CHIP_LIST_ENUM;

/* For LDO_BUCK_SET_EN command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_BOOL	enable;
}PMU_CTRL_LDO_BUCK_SET_EN;

/* For LDO_BUCK_GET_EN_STATUS command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_BOOL	enable;
}PMU_CTRL_LDO_BUCK_GET_EN_STATUS;

/* For LDO_BUCK_GET_QI_MODE command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_BOOL	mode;
}PMU_CTRL_LDO_BUCK_GET_QI_MODE;

/* For LDO_BUCK_SET_EN_FORCE command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_BOOL	enable;
}PMU_CTRL_LDO_BUCK_SET_EN_FORCE;

/* For LDO_BUCK_SET_THER_SHDN_EN command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_BOOL	enable;
}PMU_CTRL_LDO_BUCK_SET_THER_SHDN_EN;

/* For LDO_BUCK_SET_VOLTAGE command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	PMU_VOLTAGE_ENUM	voltage;
}PMU_CTRL_LDO_BUCK_SET_VOLTAGE;

/* For LDO_BUCK_SET_SLEEP_VOLTAGE command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	PMU_VOLTAGE_ENUM	sleepVoltage;
}PMU_CTRL_LDO_BUCK_SET_SLEEP_VOLTAGE;

/* For LDO_BUCK_SET_VOLTAGE_EN command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	PMU_VOLTAGE_ENUM	voltage;
}PMU_CTRL_LDO_BUCK_SET_VOLTAGE_EN;

/* For LDO_BUCK_SET_RS command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	PMU_RS_ENUM	rs;
}PMU_CTRL_LDO_BUCK_SET_RS;

/* For LDO_BUCK_SET_BURST_THRESHOLD command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_UINT16					thresholdIdx;
}PMU_CTRL_LDO_BUCK_SET_BURST_THRESHOLD;

/* For LDO_BUCK_SET_CURRENT_LIMIT command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_UINT16					currentLimitIdx;
}PMU_CTRL_LDO_BUCK_SET_CURRENT_LIMIT;

/* For LDO_BUCK_SET_BIAS_CURRENT_CALIBRATION_CODE command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_UINT16					biasCurrentCalibrationCode;
}PMU_CTRL_LDO_BUCK_SET_BIAS_CURRENT_CALIBRATION_CODE;

/* For LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_UINT16					voltageCalibrationCode;
}PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE;

/* For LDO_BUCK_SET_STB_TD command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_UINT16		delayTimeIdx;
}PMU_CTRL_LDO_BUCK_SET_STB_TD;
	
/* For LDO_BUCK_SET_OC_TD command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_UINT16		deglitchTimeIdx;
}PMU_CTRL_LDO_BUCK_SET_OC_TD;

/* For LDO_BUCK_SET_OCFB_EN command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_BOOL	enable;
}PMU_CTRL_LDO_BUCK_SET_OCFB_EN;

/* For LDO_BUCK_SET_OC_AUTO_OFF command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_BOOL	enable;
}PMU_CTRL_LDO_BUCK_SET_OC_AUTO_OFF;

/* For LDO_BUCK_SET_ON_SEL command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	PMU_ON_SEL_ENUM	onSel;
}PMU_CTRL_LDO_BUCK_SET_ON_SEL;

/* For LDO_BUCK_SET_SRCLKEN_SEL command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	PMU_SRCLKEN_SEL_ENUM	SrclkenSel;
}PMU_CTRL_LDO_BUCK_SET_SRCLKEN_SEL;

/* For LDO_BUCK_SET_SRCLK_EN_SEL command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	PMIC_SIGNAL_SEL_ENUM	sel;
}PMU_CTRL_LDO_BUCK_SET_SRCLK_EN_SEL;

/* For LDO_BUCK_SET_STB_EN command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_BOOL	enable;
}PMU_CTRL_LDO_BUCK_SET_STB_EN;

/* For LDO_BUCK_SET_NDIS_EN command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_BOOL	enable;
}PMU_CTRL_LDO_BUCK_SET_NDIS_EN;

/* For LDO_BUCK_SET_VSIM_GPLDO_EN command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_BOOL	enable;
}PMU_CTRL_LDO_BUCK_SET_VSIM_GPLDO_EN;

/* For _LDO_BUCK_SET_VSIM2_GPLDO_EN command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_BOOL	enable;
}PMU_CTRL_LDO_BUCK_SET_VSIM2_GPLDO_EN;

/* For LDO_BUCK_SET_SIM2_GPIO_EN command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_BOOL	enable;
}PMU_CTRL_LDO_BUCK_SET_SIM2_GPIO_EN;

/* For LDO_BUCK_SET_CCI_SRCLKEN command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_BOOL	enable;
}PMU_CTRL_LDO_BUCK_SET_CCI_SRCLKEN;

/* For LDO_BUCK_GET_OC_STATUS command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_BOOL	status;
}PMU_CTRL_LDO_BUCK_GET_OC_STATUS;

/* For LDO_BUCK_GET_QI_OC_STATUS command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_BOOL	status;
}PMU_CTRL_LDO_BUCK_GET_QI_OC_STATUS;

/* For LDO_BUCK_SET_OC_INT_EN. */
typedef struct
{
    PMU_LDO_BUCK_LIST_ENUM		mod;
    DCL_BOOL oc_int_en;
}PMU_CTRL_LDO_BUCK_SET_OC_INT_EN;

/* For LDO_BUCK_CLEAR_OC_FLAG. */
typedef struct
{
    PMU_LDO_BUCK_LIST_ENUM		mod;
}PMU_CTRL_LDO_BUCK_CLEAR_OC_FLAG;

/* For LDO_BUCK_GET_OC_FLAG. */
typedef struct
{
    PMU_LDO_BUCK_LIST_ENUM		mod;
    DCL_BOOL oc_flag;
}PMU_CTRL_LDO_BUCK_GET_OC_FLAG;

/* For LDO_BUCK_GET_VOLTAGE_LIST. */
typedef struct
{
    PMU_LDO_BUCK_LIST_ENUM      mod;
    const DCL_UINT32            *pVals;
    DCL_UINT8                   size;
}PMU_CTRL_LDO_BUCK_GET_VOLTAGE_LIST;

/* For LDO_BUCK_SET_LP_MODE_SET command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	DCL_BOOL	enable;
}PMU_CTRL_LDO_BUCK_SET_LP_MODE_SET;

/* For LDO_BUCK_SET_LP_SEL command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	PMIC_ON_SEL_ENUM	onSel;
}PMU_CTRL_LDO_BUCK_SET_LP_SEL;

/* For LDO_BUCK_GET_LP_MODE. */
typedef struct
{
    PMU_LDO_BUCK_LIST_ENUM      mod;
    DCL_BOOL	                enable;
}PMU_CTRL_LDO_BUCK_GET_LP_MODE;

/* For LDO_BUCK_SET_ON_CTRL command. */
typedef struct
{
    PMU_LDO_BUCK_LIST_ENUM		mod;
    PMIC_ON_CTRL_ENUM mode;
}PMU_CTRL_LDO_BUCK_SET_ON_CTRL;

/* For LDO_BUCK_SET_MODESET command. */
typedef struct
{
    PMU_LDO_BUCK_LIST_ENUM      mod;
    PMU_CTRL_BUCK_LDO_CTRL_MODESET_ENUM     mode;
}PMU_CTRL_LDO_BUCK_SET_MODESET;

/* For LDO_BUCK_SET_EN_CTRL command. */
typedef struct
{
    PMU_LDO_BUCK_LIST_ENUM		mod;
    PMIC_ON_CTRL_ENUM mode;
}PMU_CTRL_LDO_BUCK_SET_EN_CTRL;

/* For LDO_BUCK_SET_EN_SEL command. */
typedef struct
{
    PMU_LDO_BUCK_LIST_ENUM		mod;
    PMIC_SIGNAL_SEL_ENUM sel;
}PMU_CTRL_LDO_BUCK_SET_EN_SEL;

/* For LDO_BUCK_SET_SRCLK_MODE_SEL command. */
typedef struct
{
    PMU_LDO_BUCK_LIST_ENUM		mod;
    PMIC_SIGNAL_SEL_ENUM sel;
}PMU_CTRL_LDO_BUCK_SET_SRCLK_MODE_SEL;

/* For LDO_SET_CAL command. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
	PMU_VOLTAGE_CALIBRATION_ENUM voltage;
}PMU_CTRL_LDO_SET_CAL;

/* For VPA_SET_VOSEL_MAP_EN command. */
typedef struct
{
	PMU_VPA_LIST_ENUM vpa;
	DCL_BOOL	enable;
}PMU_CTRL_VPA_SET_VOSEL_MAP_EN;

/* For VPA_SET_EN command. */
typedef struct
{
	PMU_VPA_LIST_ENUM vpa;
	DCL_BOOL	enable;
}PMU_CTRL_VPA_SET_EN;

/* For VPA_SET_VOLTAGE command. */
typedef struct
{
	PMU_VOLTAGE_ENUM	voltage;
	PMU_VPA_ENUM	vpaIdx;	
	PMU_VPA_LIST_ENUM vpa;
}PMU_CTRL_VPA_SET_VOLTAGE;

/* For VPA_CTRL_SEL command. */
typedef struct
{
	DCL_BOOL	byPASEL;
}PMU_CTRL_VPA_CTRL_SEL;

/* For VPA_GET_VOLTAGE_LIST command. */
typedef struct
{
	const DCL_UINT32 *pVoltageList;
	DCL_UINT32 number;
}PMU_CTRL_VPA_GET_VOLTAGE_LIST;

/* For VPA_SET_BAT_LOW command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_VPA_SET_BAT_LOW;

/* For VPA_SET_FPWM command. */
typedef struct
{
	PMU_VPA_LIST_ENUM vpa;
	DCL_BOOL	enable;
}PMU_CTRL_VPA_SET_FPWM;

/* For VPA_SET_VOLTAGE_SELECTION_TABLE command. */
typedef struct
{
        PMU_VPA_ENUM            table_entry;
	PMU_VOLTAGE_ENUM	voltage;
}PMU_CTRL_VPA_SET_VOLTAGE_SELECTION_TABLE;


/* For VPA_SET_MAP_SEL command. */
typedef struct
{
        PMU_VPA_ENUM table_entry;
}PMU_CTRL_VPA_SET_MAP_SEL;

/* For VIBR_SET_DIMMING_ON_DUTY command. */
typedef struct
{
	DCL_UINT16	duty;
}PMU_CTRL_VIBR_SET_DIMMING_ON_DUTY;

/* For VRF18_SET_FPWM command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_VRF18_SET_FPWM;

/* For VRF18_SET_MODESET command. */
typedef struct
{
    PMIC_VRF18_LIST_ENUM vrf18Idx;
	DCL_BOOL	enable;
}PMU_CTRL_VRF18_SET_MODESET;

/* For VRF18_SET_BUCK_LDO_MODE command. */
typedef struct
{
    PMIC_VRF18_LIST_ENUM vrf18Idx;
	PMU_CTRL_BUCK_LDO_CTRL_MODE_ENUM    mode;
}PMU_CTRL_VRF18_SET_BUCK_LDO_MODE;

/* For VRF1_SET_MODESET_CKPDN_SET command. */
typedef struct
{
    DCL_UINT16 regval;
}PMU_CTRL_VRF1_SET_MODESET_CKPDN_SET;

/* For VRF1_SET_MODESET_CKPDN_CLR command. */
typedef struct
{
    DCL_UINT16 regval;
}PMU_CTRL_VRF1_SET_MODESET_CKPDN_CLR;

/* For VRF1_GET_MODESET_CKPDN command. */
typedef struct
{
    DCL_UINT16 regval;
}PMU_CTRL_VRF1_GET_MODESET_CKPDN;

/* For SIMLS_SET_SRST_CONF command. */
typedef struct
{
    PMIC_VSIM_LIST_ENUM vsimIdx;
    DCL_UINT32 regval;
}PMU_CTRL_SIMLS_SET_SRST_CONF;

/* For SIMLS_SET_SCLK_CONF command. */
typedef struct
{
    PMIC_VSIM_LIST_ENUM vsimIdx;
    DCL_UINT32 regval;
}PMU_CTRL_SIMLS_SET_SCLK_CONF;

/* For SIMLS_SET_TDSEL command. */
typedef struct
{
    DCL_UINT32 regval;
}PMU_CTRL_SIMLS_SET_TDSEL;

/* For SIMAP_SET_TDSEL command. */
typedef struct
{
    DCL_UINT32 regval;
}PMU_CTRL_SIMAP_SET_TDSEL;

/* For SIMLS_SET_RDSEL command. */
typedef struct
{
    DCL_UINT32 regval;
}PMU_CTRL_SIMLS_SET_RDSEL;

/* For SIMAP_SET_RDSEL command. */
typedef struct
{
    DCL_UINT32 regval;
}PMU_CTRL_SIMAP_SET_RDSEL;

/* For OCTL_SET_SIM_AP_SRST command. */
typedef struct
{
    PMIC_VSIM_LIST_ENUM vsimIdx;
    DCL_UINT32 regval;
}PMU_CTRL_OCTL_SET_SIM_AP_SRST;

/* For OCTL_SET_SIM_AP_SCLK command. */
typedef struct
{
    PMIC_VSIM_LIST_ENUM vsimIdx;    
    DCL_UINT32 regval;
}PMU_CTRL_OCTL_SET_SIM_AP_SCLK;

/* For OCTL_SET_SIMLS_SRST command. */
typedef struct
{
    PMIC_VSIM_LIST_ENUM vsimIdx;    
    DCL_UINT32 regval;
}PMU_CTRL_OCTL_SET_SIMLS_SRST;

/* For OCTL_SET_SIMLS_SCLK command. */
typedef struct
{
    PMIC_VSIM_LIST_ENUM vsimIdx;    
    DCL_UINT32 regval;
}PMU_CTRL_OCTL_SET_SIMLS_SCLK;

/* For SIM_SET_STB_SIO_MODE command. */
typedef struct
{
    PMIC_VSIM_LIST_ENUM vsimIdx;
    PMU_CTRL_STB_SIO_CTRL_MODE_ENUM mode;
}PMU_CTRL_SIM_SET_STB_SIO_MODE;

/* For SIMRST_SET_GPIO_SET command. */
typedef struct
{
    PMIC_VSIM_LIST_ENUM vsimIdx;
}PMU_CTRL_SIMRST_SET_GPIO_SET;

/* For SIMRST_SET_GPIO_CLR command. */
typedef struct
{
    PMIC_VSIM_LIST_ENUM vsimIdx;
}PMU_CTRL_SIMRST_SET_GPIO_CLR;

/* For SPK_SET_EN command. */
typedef struct
{
	PMU_SPK_LIST_ENUM spk;
	DCL_BOOL	enable;
	PMU_CTRL_STEP_ENUM step;
}PMU_CTRL_SPK_SET_EN;

/* For SPK_SET_MODE command. */
typedef struct
{
	PMU_SPK_LIST_ENUM spk;
	PMU_CTRL_SPK_MODE_ENUM	mode;
}PMU_CTRL_SPK_SET_MODE;

/* For SPK_GET_MODE command. */
typedef struct
{
	PMU_SPK_LIST_ENUM spk;
	DCL_UINT16	mode;
}PMU_CTRL_SPK_GET_MODE;

/* For SPK_SET_SLEW_RATE command. */
typedef struct
{
	PMU_SPK_LIST_ENUM spk;
	PMU_CTRL_SPK_MODE_ENUM	mode;
}PMU_CTRL_SPK_SET_SLEW_RATE;

/* For SPK_SET_OC_AUTO_OFF command. */
typedef struct
{
	PMU_SPK_LIST_ENUM spk;
	DCL_BOOL	enable;
}PMU_CTRL_SPK_SET_OC_AUTO_OFF;

/* For SPK_SET_VOL_VALUE command. */
typedef struct
{
	PMU_SPK_LIST_ENUM spk;
	DCL_UINT16	volValue;
}PMU_CTRL_SPK_SET_VOL_VALUE;

/* For SPK_GET_VOL_VALUE command. */
typedef struct
{
	PMU_SPK_LIST_ENUM spk;
	DCL_UINT16	volValue;
}PMU_CTRL_SPK_GET_VOL_VALUE;	

/* For SPK_GET_VOL command. */
typedef struct
{
	PMU_SPK_LIST_ENUM spk;
	PMU_SPK_VOL_ENUM	dbm;
}PMU_CTRL_SPK_GET_VOL;	

/* For SPK_SET_VOL command. */
typedef struct
{
	PMU_SPK_LIST_ENUM spk;
	PMU_SPK_VOL_ENUM	dbm;
}PMU_CTRL_SPK_SET_VOL;	

/* For SPK_SET_CALIBR_EN command. */
typedef struct
{
	PMU_SPK_LIST_ENUM spk;
	DCL_BOOL	enable;
}PMU_CTRL_SPK_SET_CALIBR_EN;	

/* For SPK_SET_CALIBR_SEL command. */
typedef struct
{
	PMU_SPK_LIST_ENUM spk;
	PMU_CTRL_SPK_CALI_PATH_ENUM	path;
}PMU_CTRL_SPK_SET_CALIBR_SEL;	

/* For BL_SET_INIT command. */
typedef enum
{
	BL_VBOOST_VOLTAGE_CONTROLLER_MODE=0,
	BL_VBOOST_CURRENT_CONVERTER_MODE=1,
	BL_ISINK_MODE=2,	
	BL_MODE_1=0,
	BL_MODE_2=1,
	BL_MODE_3=2,
	BL_MODE0=0,
	BL_MODE1=1,
	BL_MODE2=2,
	BL_MODE3=3,
	BL_MODE_NUM
}PMU_CTRL_BL_MODE_ENUM;

/* For BL_SET_INIT command. */
typedef struct
{
	PMU_CTRL_BL_MODE_ENUM blMode;
}PMU_CTRL_BL_SET_INIT;

/* For BL_SET_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_BL_SET_EN;

/* For BL_GET_SUPPORT_LEVEL command */
typedef struct
{
    DCL_UINT32 blSupportLevel;
}PMU_CTRL_BL_GET_SUPPORT_LEVEL;

/* For BL_GET_USE_PWM_MODE command */
typedef struct
{
    DCL_UINT32 blUsePwmQuery;
}PMU_CTRL_BL_GET_USE_PWM_QUERY;

/* For FLASHLED_SET_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_FLASHLED_SET_EN;

/* For FLASHLED_SET_MODE command. */
typedef struct
{
	PMU_CTRL_FLASHLED_MODE_ENUM mode;
}PMU_CTRL_FLASHLED_SET_MODE;

/* For FLASHLED_SET_SEL command. */
typedef struct
{
	PMU_CTRL_FLASHLED_SEL_ENUM sel;
}PMU_CTRL_FLASHLED_SET_SEL;

/* For KPLED_SET_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_KPLED_SET_EN;

/* For KPLED_SET_MODE command. */
typedef struct
{
	PMU_CTRL_KPLED_MODE_ENUM mode;
}PMU_CTRL_KPLED_SET_MODE;

/* For KPLED_SET_SEL command. */
typedef struct
{
	PMU_CTRL_KPLED_SEL_ENUM sel;
}PMU_CTRL_KPLED_SET_SEL;

/* For KPLED_SET_FREQUENCY_DIVISION command. */
typedef struct
{
	DCL_UINT16 div;
}PMU_CTRL_KPLED_SET_FREQUENCY_DIVISION;

/* For KPLED_SET_DIMMING_ON_DUTY command. */
typedef struct
{
	DCL_UINT16 duty;
}PMU_CTRL_KPLED_SET_DIMMING_ON_DUTY;	

/* For CHR_SET_ADC_MEASURE_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_SET_ADC_MEASURE_EN;

/* For CHR_SET_CSDAC_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_SET_CSDAC_EN;

/* For CHR_SET_CHR_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_SET_CHR_EN;

/* For CHR_SET_CHR_FORCE_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_SET_CHR_FORCE_EN;

/* For CHR_GET_CHR_CURRENT command. */
typedef struct
{
	PMU_CHR_CURRENT_ENUM	current;
}PMU_CTRL_CHR_GET_CHR_CURRENT;

/* For CHR_GET_CHR_CURRENT_LIST command. */
typedef struct
{
	const DCL_UINT32 *pCurrentList;
	DCL_UINT32 number;
}PMU_CTRL_CHR_GET_CHR_CURRENT_LIST;

/* For CHR_SET_CHR_CURRENT command. */
typedef struct
{
	PMU_CHR_CURRENT_ENUM	current;
}PMU_CTRL_CHR_SET_CHR_CURRENT;

/* For CHR_GET_CHR_DET_STATUS command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_GET_CHR_DET_STATUS;

/* For CHR_GET_CV_DETECTION_STATUS command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_GET_CV_DETECTION_STATUS;

/* For CHR_SET_CV_DETECTION_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_SET_CV_DETECTION_EN;

/* For CHR_SET_CV_DETECTION_VOLTAGE command. */
typedef struct
{
	PMU_VOLTAGE_ENUM	voltage;
}PMU_CTRL_CHR_SET_CV_DETECTION_VOLTAGE;

/* For CHR_GET_IS_BATTERY_ON command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_GET_IS_BATTERY_ON;

/* For CHR_GET_IS_CHR_VALID command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_GET_IS_CHR_VALID;

/* For CHR_SET_WDT_INT_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_SET_WDT_INT_EN;

/* For CHR_SET_WDT_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_SET_WDT_EN;

/* For CHR_SET_WDT_TIMER command. */
typedef struct
{
	PMU_CHR_WDT_TD_ENUM	secs;
}PMU_CTRL_CHR_SET_WDT_TIMER;

/* For CHR_SET_HV_DETECTION_VOLTAGE command. */
typedef struct
{
	PMU_VOLTAGE_ENUM	voltage;
}PMU_CTRL_CHR_SET_HV_DETECTION_VOLTAGE;

/* For CHR_GET_HV_DETECTION_VOLTAGE_LIST command. */
typedef struct
{
	const DCL_UINT32 *pVoltageList;
	DCL_UINT32 number;
}PMU_CTRL_CHR_GET_HV_DETECTION_VOLTAGE_LIST;

/* For CHR_SET_VBAT_OV_DETECTION_VOLTAGE command. */
typedef struct
{
	PMU_VOLTAGE_ENUM	voltage;
}PMU_CTRL_CHR_SET_VBAT_OV_DETECTION_VOLTAGE;

/* For CHR_SET_BAT_HT_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_SET_BAT_HT_EN;

/* For CHR_SET_OTG_BVALID_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_SET_OTG_BVALID_EN;

/* For CHR_SET_BC11_PULLUP_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_SET_BC11_PULLUP_EN;

/* For CHR_SET_CV_MODE command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_SET_CV_MODE;

/* For CHR_SET_CSDAC_MODE command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_SET_CSDAC_MODE;

/* For CHR_SET_TRACKING_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_SET_TRACKING_EN;

/* For CHR_SET_HWCV_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_SET_HWCV_EN;

/* For CHR_SET_ULC_DET_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_CHR_SET_ULC_DET_EN;

/* For CHR_SET_LOW_ICH_DB command. */
typedef struct
{
	DCL_UINT16	debounceTime;
}PMU_CTRL_CHR_SET_LOW_ICH_DB;

/* For CHR_SET_VBAT_CV_CALIBRATION command. */
typedef struct
{
	DCL_INT32	vbat;
}PMU_CTRL_CHR_SET_VBAT_CV_CALIBRATION;

/* For CHR_GET_CC_DET command. */
typedef struct
{
	DCL_BOOL vbat_cc_det;
}PMU_CTRL_CHR_GET_CC_DET;

/* For BOOST_SET_EN command. */
typedef struct
{
	PMU_BOOST_LIST_ENUM boost;
	DCL_BOOL	enable;
}PMU_CTRL_BOOST_SET_EN;

/* For BOOST_SET_CURRENT_LIMIT command. */
typedef struct
{
	PMU_BOOST_LIST_ENUM boost;
	DCL_BOOL	currentLimit;
}PMU_CTRL_BOOST_SET_CURRENT_LIMIT;

/* For BOOST_SET_CLK_CAL command. */
typedef struct
{
	PMU_BOOST_LIST_ENUM boost;
	DCL_BOOL	clkCal;
}PMU_CTRL_BOOST_SET_CLK_CAL;

/* For BOOST_SET_SYNC_EN command. */
typedef struct
{
	PMU_BOOST_LIST_ENUM boost;
	DCL_BOOL	enable;
}PMU_CTRL_BOOST_SET_SYNC_EN;

/* For BOOST_SET_VOLTAGE command. */
typedef struct
{
	PMU_BOOST_LIST_ENUM boost;
	PMU_VOLTAGE_ENUM	voltage;
}PMU_CTRL_BOOST_SET_VOLTAGE;	

/* For BOOST_SET_LEVEL command. */
typedef struct
{
	PMU_BOOST_LIST_ENUM boost;
	DCL_UINT16	level;
}PMU_CTRL_BOOST_SET_LEVEL;

/* For ISINK_SET_EN command. */
typedef struct
{
	PMU_ISINK_LIST_ENUM		isink;
	DCL_BOOL	enable;
}PMU_CTRL_ISINK_SET_EN;

/* For ISINK_SET_MODE command. */
typedef struct
{
	PMU_ISINK_LIST_ENUM		isink;
	PMU_CTRL_ISINK_MODE_ENUM	mode;
}PMU_CTRL_ISINK_SET_MODE;

/* For ISINK_SET_STEP command. */
typedef struct
{
	PMU_ISINK_LIST_ENUM		isink;
	PMU_CTRL_ISINK_STEP_ENUM	step;
}PMU_CTRL_ISINK_SET_STEP;

/* For ISINK_SET_STEP command. */
typedef struct
{
	PMU_ISINK_LIST_ENUM		isink;
	DCL_BOOL    forceOff;
}PMU_CTRL_ISINK_SET_FORCE_OFF;

/* For ISINK_SET_DIMMING_ON_DUTY command. */
typedef struct
{
	PMU_ISINK_LIST_ENUM		isink;
	DCL_UINT16	duty;
}PMU_CTRL_ISINK_SET_DIMMING_ON_DUTY;

/* For ISINK_SET_FREQUENCY_DIVISION command. */
typedef struct
{
	PMU_ISINK_LIST_ENUM		isink;
	DCL_UINT16	div;
}PMU_CTRL_ISINK_SET_FREQUENCY_DIVISION;

/* For ADC_SET_RQST command. */
typedef struct
{
    DCL_BOOL    enable;

}PMU_CTRL_ADC_SET_RQST;

/* For ADC_GET_RDY_MD command. */
typedef struct
{
    DCL_BOOL    status;
}PMU_CTRL_ADC_GET_RDY_MD;

/* For ADC_GET_OUT_MD command. */
typedef struct
{
    DCL_UINT32 data;  
}PMU_CTRL_ADC_GET_OUT_MD;

/* For MISC_BLED_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_MISC_SET_BLED_EN;

/* For MISC_RLED_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_MISC_SET_RLED_EN;

/* For MISC_GLED_EN command. */
typedef struct
{
	DCL_BOOL	enable;
}PMU_CTRL_MISC_SET_GLED_EN;

/* For MISC_GET_CID command. */
typedef struct
{
	DCL_UINT32 cid_value;
}PMU_CTRL_MISC_GET_CID;

/* For MISC_GET_ECO_VERSION command. */
typedef struct
{
	DCL_UINT32 eco_version;
}PMU_CTRL_MISC_GET_ECO_VERSION;


/* For MISC_GET_HW_VERSION command. */
typedef struct
{
    PMIC_CHIP_LIST_ENUM chip_name;    
	DCL_UINT32 version;
}PMU_CTRL_MISC_GET_HW_VERSION;

/* For MISC_SET_REGISTER_VALUE command. */
typedef struct
{
	DCL_UINT32 offset;
	DCL_UINT16 value;
}PMU_CTRL_MISC_SET_REGISTER_VALUE;

/* For MISC_GET_REGISTER_VALUE command. */
typedef struct
{
	DCL_UINT32 offset;
	DCL_UINT16 value;
}PMU_CTRL_MISC_GET_REGISTER_VALUE;

/* internal use for buck and ldo. */
typedef struct
{
	PMU_LDO_BUCK_LIST_ENUM		mod;
}PMU_CTRL_LDO_BUCK_CTRL;


/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/
#ifdef __BUILD_DOM__
/* The PMU Command Parameter Data Structure for Each Command in DCL_CTRL_DATA_T Enum of dcl.h */
typedef struct
{
    PMU_CTRL_LDO_BUCK_CTRL rPMULdoBuckCtrl; /* Data Structure for Internal Use*/
    PMU_CTRL_LDO_BUCK_SET_EN rPMULdoBuckSetEn; /* Data Structure for LDO_BUCK_SET_EN */
    PMU_CTRL_LDO_BUCK_GET_EN_STATUS rPMULdoBuckGetEnStatus; /* Data Structure for LDO_BUCK_GET_EN_STATUS */
    PMU_CTRL_LDO_BUCK_GET_QI_MODE rPMULdoBuckGetQiMode; /* Data Structure for LDO_BUCK_GET_QI_MODE */
    PMU_CTRL_LDO_BUCK_SET_EN_FORCE rPMULdoBuckSetEnForce; /* Data Structure for LDO_BUCK_SET_EN_FORCE */
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE rPMULdoBuckSetVoltage; /* Data Structure for LDO_BUCK_SET_VOLTAGE */
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE_EN rPMULdoBuckSetVoltageEn; /* Data Structure for LDO_BUCK_SET_VOLTAGE_EN */
    PMU_CTRL_LDO_BUCK_SET_SLEEP_VOLTAGE rPMULdoBuckSetSleepVoltage; /* Data Structure for LDO_BUCK_SET_SLEEP_VOLTAGE */
    PMU_CTRL_LDO_BUCK_SET_BURST_THRESHOLD rPMULdoBuckSetBurstThreshold; /* Data Structure for LDO_BUCK_SET_BURST_THRESHOLD */
    PMU_CTRL_LDO_BUCK_SET_CURRENT_LIMIT rPMULdoBuckSetCurrentLimit; /* Data Structure for LDO_BUCK_SET_CURRENT_LIMIT */
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE rPMULdoBuckSetVoltageCalibrationCode; /* Data Structure for LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE */
    PMU_CTRL_LDO_BUCK_SET_BIAS_CURRENT_CALIBRATION_CODE rPMULdoBuckSetBiasCurrentCalibrationCode; /* Data Structure for LDO_BUCK_SET_BIAS_CURRENT_CALIBRATION_CODE */
    PMU_CTRL_LDO_BUCK_SET_STB_EN rPMULdoBuckSetStbEn; /* Data Structure for LDO_BUCK_SET_STB_EN */
    PMU_CTRL_LDO_BUCK_SET_OC_AUTO_OFF rPMULdoBuckSetOcAutoOff; /* Data Structure for LDO_BUCK_SET_OC_AUTO_OFF */
    PMU_CTRL_LDO_BUCK_SET_RS rPMULdoBuckSetRs; /* Data Structure for LDO_BUCK_SET_RS */
    PMU_CTRL_LDO_BUCK_SET_ON_SEL rPMULdoBuckSetOnSel; /* Data Structure for LDO_BUCK_SET_ON_SEL */
    PMU_CTRL_LDO_BUCK_SET_SRCLKEN_SEL rPMULdoBuckSetSrclkenSel; /* Data Structure for LDO_BUCK_SET_SRCLKEN_SEL */
    PMU_CTRL_LDO_BUCK_SET_STB_TD rPMULdoBuckSetStbTd; /* Data Structure for LDO_BUCK_SET_STB_TD */
    PMU_CTRL_LDO_BUCK_SET_NDIS_EN rPMULdoBuckSetNdisEn; /* Data Structure for LDO_BUCK_SET_NDIS_EN */
    PMU_CTRL_LDO_BUCK_SET_OC_TD rPMULdoBuckSetOcTd; /* Data Structure for LDO_BUCK_SET_OC_TD */
    PMU_CTRL_LDO_BUCK_SET_OCFB_EN rPMULdoBuckSetOcfbEn; /* Data Structure for LDO_BUCK_SET_OCFB_EN */
    PMU_CTRL_LDO_BUCK_SET_VSIM_GPLDO_EN rPMULdoBuckSetVsimGpldoEn; /* Data Structure for LDO_BUCK_SET_VSIM_GPLDO_EN */
    PMU_CTRL_LDO_BUCK_SET_VSIM2_GPLDO_EN rPMULdoBuckSetVsim2GpldoEn; /* Data Structure for LDO_BUCK_SET_VSIM2_GPLDO_EN */
    PMU_CTRL_LDO_BUCK_SET_SIM2_GPIO_EN rPMULdoBuckSetSim2GpioEn; /* Data Structure for LDO_BUCK_SET_SIM2_GPIO_EN */    
    PMU_CTRL_LDO_BUCK_SET_CCI_SRCLKEN rPMULdoBuckSetCciSrclken; /* Data Structure for LDO_BUCK_SET_CCI_SRCLKEN */    
    PMU_CTRL_LDO_BUCK_GET_OC_STATUS rPMULdoBuckGetOcStatus; /* Data Structure for LDO_BUCK_GET_OC_STATUS */
    PMU_CTRL_LDO_BUCK_GET_QI_OC_STATUS rPMULdoBuckGetQiOcStatus; /* Data Structure for LDO_BUCK_GET_QI_OC_STATUS */    
    PMU_CTRL_LDO_BUCK_SET_OC_INT_EN rPMULdoBuckSetOcIntEn; /* Data Structure for LDO_BUCK_SET_OC_INT_EN */
    PMU_CTRL_LDO_BUCK_CLEAR_OC_FLAG rPMULdoBuckClearOcFlag; /* Data Structure for LDO_BUCK_CLEAR_OC_FLAG */
    PMU_CTRL_LDO_BUCK_GET_OC_FLAG rPMULdoBuckGetOcFlag; /* Data Structure for LDO_BUCK_GET_OC_FLAG */
    PMU_CTRL_LDO_BUCK_GET_VOLTAGE_LIST rPMULdoBuckGetVoltageList; /* Data Structure for LDO_BUCK_GET_VOLTAGE_LIST */
    PMU_CTRL_LDO_BUCK_SET_THER_SHDN_EN rPMULdoBuckSetTherShdnEn; /* Data Structure for LDO_BUCK_SET_THER_SHDN_EN */    
    PMU_CTRL_LDO_BUCK_SET_LP_MODE_SET rPMULdoBuckSetLpModeSet; /* Data Structure for LDO_BUCK_SET_LP_MODE_SET */
    PMU_CTRL_LDO_BUCK_SET_LP_SEL rPMULdoBuckSetLpSel; /* Data Structure for LDO_BUCK_SET_LP_SEL */
    PMU_CTRL_LDO_BUCK_GET_LP_MODE rPMULdoBuckGetLpMode; /* Data Structure for LDO_BUCK_GET_LP_MODE */
    PMU_CTRL_LDO_BUCK_SET_ON_CTRL rPMULdoBuckSetOnCtrl; /* Data Structure for LDO_BUCK_SET_ON_CTRL */
    PMU_CTRL_LDO_BUCK_SET_MODESET rPMULdoBuckSetModeset; /* Data Structure for LDO_BUCK_SET_MODESET */
    PMU_CTRL_LDO_BUCK_SET_EN_CTRL rPMULdoBuckSetEnCtrl; /* Data Structure for LDO_BUCK_SET_EN_CTRL */    
    PMU_CTRL_LDO_BUCK_SET_EN_SEL rPMULdoBuckSetEnSel; /* Data Structure for LDO_BUCK_SET_EN_SEL */
    PMU_CTRL_LDO_BUCK_SET_SRCLK_MODE_SEL rPMULdoBuckSetSrclkModeSel; /* Data Structure for LDO_BUCK_SET_SRCLK_MODE_SEL */
    PMU_CTRL_LDO_BUCK_SET_SRCLK_EN_SEL rPMULdoBuckSetSrclkEnSel; /* Data Structure for LDO_BUCK_SET_SRCLK_EN_SEL */    
    PMU_CTRL_LDO_SET_CAL rPMULdoSetCal; /* Data Structure for LDO_SET_CAL */        
    PMU_CTRL_VPA_SET_VOSEL_MAP_EN rPMUVpaSetVoselMapEn; /* Data Structure for VPA_SET_VOSEL_MAP_EN */   
    PMU_CTRL_VPA_SET_EN rPMUVpaSetEn; /* Data Structure for VPA_SET_EN */
    PMU_CTRL_VPA_SET_VOLTAGE rPMUVpaSetVoltage; /* Data Structure for VPA_SET_VOLTAGE */
	PMU_CTRL_VPA_CTRL_SEL rPMUVpaCtrlSel; /* Data Structure for VPA_CTRL_SEL */
    PMU_CTRL_VPA_GET_VOLTAGE_LIST rPMUVpaGetVoltageList; /* Data Structure for VPA_GET_VOLTAGE_LIST */
    PMU_CTRL_VPA_SET_BAT_LOW rPMUVpaSetBatLow; /* Data Structure for VPA_SET_BAT_LOW */
	PMU_CTRL_VPA_SET_FPWM rPMUVpaSetFpwm; /* Data Structure for VPA_SET_FPWM */
    PMU_CTRL_VPA_SET_VOLTAGE_SELECTION_TABLE rPMUVpaSetVoltageSelectionTable; /* Data Structure for VPA_SET_VOLTAGE_SELECTION_TABLE */        
    PMU_CTRL_VPA_SET_MAP_SEL rPMUVpaSetMapSel; /* Data Structure for VPA_SET_MAP_SEL */  
    PMU_CTRL_VIBR_SET_DIMMING_ON_DUTY rPMUVibrSetDimmingOnDuty; /* Data Structure for VIBR_SET_DIMMING_ON_DUTY */
	PMU_CTRL_VRF18_SET_FPWM rPMUVrf18SetFpwm; /* Data Structure for VRF18_SET_FPWM */
    PMU_CTRL_VRF18_SET_MODESET rPMUVrf18SetModeset; /* Data Structure for VRF18_SET_FPWM */
    PMU_CTRL_VRF18_SET_BUCK_LDO_MODE rPMUVrf18SetBuckLdoMode; /* Data Structure for VRF18_SET_BUCK_LDO_MODE */
    PMU_CTRL_VRF1_SET_MODESET_CKPDN_SET rPMUVrf1SetModesetCkpdnSet; /* Data Structure for VRF1_SET_MODESET_CKPDN_SET */    
    PMU_CTRL_VRF1_SET_MODESET_CKPDN_CLR rPMUVrf1SetModesetCkpdnClr; /* Data Structure for VRF1_SET_MODESET_CKPDN_CLR */        
    PMU_CTRL_VRF1_GET_MODESET_CKPDN rPMUVrf1GetModesetCkpdn; /* Data Structure for VRF1_GET_MODESET_CKPDN */    
    PMU_CTRL_SIMLS_SET_SRST_CONF rPMUSimlsSetSrstConf; /* Data Structure for SIMLS_SET_SRST_CONF */    
    PMU_CTRL_SIMLS_SET_SCLK_CONF rPMUSimlsSetSclkConf; /* Data Structure for SIMLS_SET_SCLK_CONF */    
    PMU_CTRL_SIMLS_SET_TDSEL rPMUSimlsSetTdsel; /* Data Structure for SIMLS_SET_TDSEL */    
    PMU_CTRL_SIMAP_SET_TDSEL rPMUSimapSetTdsel; /* Data Structure for SIMAP_SET_TDSEL */    
    PMU_CTRL_SIMLS_SET_RDSEL rPMUSimlsSetRdsel; /* Data Structure for SIMLS_SET_RDSEL */    
    PMU_CTRL_SIMAP_SET_RDSEL rPMUSimapSetRdsel; /* Data Structure for SIMAP_SET_RDSEL */
    PMU_CTRL_SIM_SET_STB_SIO_MODE rPMUSimSetStbSioMode; /* Data Structure for SIM_SET_STB_SIO_MODE */
    PMU_CTRL_SIMRST_SET_GPIO_SET rPMUSimrstSetGpioSet; /* Data Structure for SIMRST_SET_GPIO_SET */
    PMU_CTRL_SIMRST_SET_GPIO_CLR rPMUSimrstSetGpioClr; /* Data Structure for SIMRST_SET_GPIO_CLR */
    PMU_CTRL_OCTL_SET_SIM_AP_SRST rPMUOctlSetSimApSrst; /* Data Structure for OCTL_SET_SIM_AP_SRST */
    PMU_CTRL_OCTL_SET_SIM_AP_SCLK rPMUOctlSetSimApSclk; /* Data Structure for OCTL_SET_SIM_AP_SCLK */
    PMU_CTRL_OCTL_SET_SIMLS_SRST rPMUOctlSetSimlsSrst; /* Data Structure for OCTL_SET_SIMLS_SRST */
    PMU_CTRL_OCTL_SET_SIMLS_SCLK rPMUOctlSetSimlsSclk; /* Data Structure for OCTL_SET_SIMLS_SCLK */    
    PMU_CTRL_SPK_SET_EN rPMUSpkSetEn; /* Data Structure for SPK_SET_EN */
    PMU_CTRL_SPK_SET_MODE rPMUSpkSetMode; /* Data Structure for SPK_SET_MODE */
    PMU_CTRL_SPK_GET_MODE rPMUSpkGetMode; /* Data Structure for SPK_GET_MODE */    
    PMU_CTRL_SPK_SET_OC_AUTO_OFF rPMUSpkSetOcAutoOff; /* Data Structure for SPK_SET_OC_AUTO_OFF */
    PMU_CTRL_SPK_SET_VOL_VALUE rPMUSpkSetVolValue; /* Data Structure for SPK_SET_VOL_VALUE */
    PMU_CTRL_SPK_GET_VOL_VALUE rPMUSpkGetVolValue; /* Data Structure for SPK_GET_VOL_VALUE */
    PMU_CTRL_SPK_SET_VOL rPMUSpkSetVol; /* Data Structure for SPK_SET_VOL */
    PMU_CTRL_SPK_GET_VOL rPMUSpkGetVol; /* Data Structure for SPK_GET_VOL */
    PMU_CTRL_SPK_SET_SLEW_RATE rPMUSpkSetSlewRate; /* Data Structure for SPK_SET_SLEW_RATE */
    PMU_CTRL_SPK_SET_CALIBR_EN rPMUSpkSetCalibrEn; /* Data Structure for SPK_SET_CALIBR_EN */
    PMU_CTRL_SPK_SET_CALIBR_SEL rPMUSpkSetCalibrSel; /* Data Structure for SPK_SET_CALIBR_SEL */
    PMU_CTRL_FLASHLED_SET_EN rPMUFlashledSetEn; /* Data Structure for FLASHLED_SET_EN */
    PMU_CTRL_FLASHLED_SET_MODE rPMUFlashledSetMode; /* Data Structure for FLASHLED_SET_MODE */
    PMU_CTRL_FLASHLED_SET_SEL rPMUFlashledSetSel; /* Data Structure for FLASHLED_SET_SEL */
    PMU_CTRL_KPLED_SET_EN rPMUKpledSetEn; /* Data Structure for KPLED_SET_EN */
    PMU_CTRL_KPLED_SET_MODE rPMUKpledSetMode; /* Data Structure for KPLED_SET_MODE */
    PMU_CTRL_KPLED_SET_SEL rPMUKpledSetSel; /* Data Structure for KPLED_SET_SEL */
    PMU_CTRL_KPLED_SET_FREQUENCY_DIVISION rPMUKpledSetFrequencyDivision; /* Data Structure for KPLED_SET_FREQUENCY_DIVISION */
    PMU_CTRL_KPLED_SET_DIMMING_ON_DUTY rPMUKpledSetDimmingOnDuty; /* Data Structure for KPLED_SET_DIMMING_ON_DUTY */
    PMU_CTRL_CHR_SET_ADC_MEASURE_EN rPMUChrSetAdcMeasureEn; /* Data Structure for CHR_SET_ADC_MEASURE_EN */
    PMU_CTRL_CHR_SET_WDT_TIMER rPMUChrSetWdtTimer; /* Data Structure for CHR_SET_WDT_TIMER */
    PMU_CTRL_CHR_SET_WDT_INT_EN rPMUChrSetWdtIntEn; /* Data Structure for CHR_SET_WDT_INT_EN */
    PMU_CTRL_CHR_SET_WDT_EN rPMUChrSetWdtEn; /* Data Structure for CHR_SET_WDT_EN */
    PMU_CTRL_CHR_SET_CHR_EN rPMUChrSetChrEn; /* Data Structure for CHR_SET_CHR_EN */
    PMU_CTRL_CHR_SET_CHR_FORCE_EN rPMUChrSetChrForceEn; /* Data Structure for CHR_SET_CHR_FORCE_EN */
    PMU_CTRL_CHR_GET_CHR_DET_STATUS rPMUChrGetChrDetStatus; /* Data Structure for CHR_GET_CHR_DET_STATUS */
    PMU_CTRL_CHR_GET_CHR_CURRENT rPMUChrGetChrCurrent; /* Data Structure for CHR_GET_CHR_CURRENT */
    PMU_CTRL_CHR_GET_CHR_CURRENT_LIST rPMUChrGetChrCurrentList; /* Data Structure for CHR_GET_CHR_CURRENT_LIST */
    PMU_CTRL_CHR_SET_CHR_CURRENT rPMUChrSetChrCurrent; /* Data Structure for CHR_SET_CHR_CURRENT */
    PMU_CTRL_CHR_GET_CV_DETECTION_STATUS rPMUChrGetCvDetectionStatus; /* Data Structure for CHR_GET_CV_DETECTION_STATUS */
    PMU_CTRL_CHR_SET_CV_DETECTION_EN rPMUChrSetCvDetectionEn; /* Data Structure for CHR_SET_CV_DETECTION_EN */
    PMU_CTRL_CHR_SET_CV_DETECTION_VOLTAGE rPMUChrSetCvDetectionVoltage; /* Data Structure for CHR_SET_CV_DETECTION_VOLTAGE */
    PMU_CTRL_CHR_SET_CSDAC_EN rPMUChrSetCsdacEn; /* Data Structure for CHR_SET_CSDAC_EN */
    PMU_CTRL_CHR_GET_IS_BATTERY_ON rPMUChrGetIsBatteryOn; /* Data Structure for CHR_GET_IS_BATTERY_ON */
    PMU_CTRL_CHR_GET_IS_CHR_VALID rPMUChrGetIsChrValid; /* Data Structure for CHR_GET_IS_CHR_VALID */
    PMU_CTRL_CHR_SET_HV_DETECTION_VOLTAGE rPMUChrSetHvDetectionVoltage; /* Data Structure for CHR_SET_HV_DETECTION_VOLTAGE */
	PMU_CTRL_CHR_GET_HV_DETECTION_VOLTAGE_LIST rPMUChrGetHvDetectionVoltageList; /* Data Structure for CHR_GET_HV_DETECTION_VOLTAGE_LIST */
    PMU_CTRL_CHR_SET_VBAT_OV_DETECTION_VOLTAGE rPMUChrSetVbatOvDetectionVoltage; /* Data Structure for CHR_SET_VBAT_OV_DETECTION_VOLTAGE */
    PMU_CTRL_CHR_SET_BAT_HT_EN rPMUChrSetBatHtEn; /* Data Structure for CHR_SET_BAT_HT_EN */
    PMU_CTRL_CHR_SET_OTG_BVALID_EN rPMUChrSetOtgBvalidEn; /* Data Structure for CHR_SET_OTG_BVALID_EN */
    PMU_CTRL_CHR_SET_CV_MODE rPMUChrSetCvMode; /* Data Structure for CHR_SET_CV_MODE */
    PMU_CTRL_CHR_SET_CSDAC_MODE rPMUChrSetCsdacMode; /* Data Structure for CHR_SET_CSDAC_MODE */
    PMU_CTRL_CHR_SET_TRACKING_EN rPMUChrSetTrackingEn; /* Data Structure for CHR_SET_TRACKING_EN */
    PMU_CTRL_CHR_SET_HWCV_EN rPMUChrSetHwcvEn; /* Data Structure for CHR_SET_HWCV_EN */
    PMU_CTRL_CHR_SET_ULC_DET_EN rPMUChrSetUlcDetEn; /* Data Structure for CHR_SET_ULC_DET_EN */
    PMU_CTRL_CHR_SET_BC11_PULLUP_EN	rPMUChrSetBc11PullupEn; /* Data Structure for CHR_SET_BC11_PULLUP_EN */
    PMU_CTRL_CHR_SET_LOW_ICH_DB rPMUChrSetLowIchDb; /* Data Structure for CHR_SET_LOW_ICH_DB */
	PMU_CTRL_CHR_SET_VBAT_CV_CALIBRATION rPMUChrSetVbatCvCalibration; /* Data Structure for CHR_SET_VBAT_CV_CALIBRATION */
    PMU_CTRL_CHR_GET_CC_DET rPMUChrGetCcDet; /* Data Structure for CHR_GET_CC_DET */
    PMU_CTRL_BL_SET_EN rPMUBlSetEn; /* Data Structure for BL_SET_EN */
    PMU_CTRL_BL_SET_INIT rPMUBlSetInit; /* Data Structure for BL_SET_INIT */
    PMU_CTRL_BL_GET_SUPPORT_LEVEL rPMUBlGetSupportLevel; /* Data Structure for BL_GET_SUPPPORT_LEVEL */
    PMU_CTRL_BL_GET_USE_PWM_QUERY rPMUBlGetUsePwmQuery; /* Data Structure for BL_GET_USE_PWM_QUERY */
    PMU_CTRL_BOOST_SET_EN rPMUBoostSetEn; /* Data Structure for BOOST_SET_EN */
    PMU_CTRL_BOOST_SET_CURRENT_LIMIT rPMUBoostSetCurrentLimit; /* Data Structure for BOOST_SET_CURRENT_LIMIT */
    PMU_CTRL_BOOST_SET_CLK_CAL rPMUBoostSetClkCal; /* Data Structure for BOOST_SET_CLK_CAL */
    PMU_CTRL_BOOST_SET_SYNC_EN rPMUBoostSetSyncEn; /* Data Structure for BOOST_SET_SYNC_EN */
    PMU_CTRL_BOOST_SET_VOLTAGE rPMUBoostSetVoltage; /* Data Structure for BOOST_SET_VOLTAGE */
    PMU_CTRL_BOOST_SET_LEVEL rPMUBoostSetLevel; /* Data Structure for BOOST_SET_LEVEL */
    PMU_CTRL_ISINK_SET_EN rPMUIsinkSetEn; /* Data Structure for ISINK_SET_EN */
    PMU_CTRL_ISINK_SET_MODE rPMUIsinkSetMode; /* Data Structure for ISINK_SET_MODE */
    PMU_CTRL_ISINK_SET_STEP rPMUIsinkSetStep; /* Data Structure for ISINK_SET_STEP */
    PMU_CTRL_ISINK_SET_FORCE_OFF rPMUIsinkSetForceOff; /* Data Structure for ISINK_SET_FORCE_OFF */
    PMU_CTRL_ISINK_SET_DIMMING_ON_DUTY rPMUIsinkSetDimmingOnDuty; /* Data Structure for ISINK_SET_DIMMING_ON_DUTY */
    PMU_CTRL_ISINK_SET_FREQUENCY_DIVISION rPMUIsinkSetFrequencyDivision; /* Data Structure for ISINK_SET_FREQUENCY_DIVISION */
    PMU_CTRL_ADC_SET_RQST rPMUAdcSetRqst; /* Data Structure for ADC_SET_RQST */
    PMU_CTRL_ADC_GET_RDY_MD rPMUAdcGetRdyMd; /* Data Structure for ADC_GET_RDY_MD */
    PMU_CTRL_ADC_GET_OUT_MD rPMUAdcGetOutMd; /* Data Structure for ADC_GET_OUT_MD */    
    PMU_CTRL_MISC_SET_RLED_EN rPMUMiscSetRledEn; /* Data Structure for MISC_SET_RLED_EN */
    PMU_CTRL_MISC_SET_GLED_EN rPMUMiscSetGledEn; /* Data Structure for MISC_SET_GLED_EN */
    PMU_CTRL_MISC_SET_BLED_EN rPMUMiscSetBledEn; /* Data Structure for MISC_SET_BLED_EN */
    PMU_CTRL_MISC_GET_CID rPMUMiscGetCid; /* Data Structure for MISC_GET_CID */
    PMU_CTRL_MISC_GET_ECO_VERSION rPMUMiscGetEcoVersion; /* Data Structure for MISC_GET_ECO_VERSION */
    PMU_CTRL_MISC_GET_HW_VERSION rPMUMiscGetHwVersion; /* Data Structure for MISC_GET_HW_VERISON */
    PMU_CTRL_MISC_SET_REGISTER_VALUE rPMUMiscSetRegisterValue; /* Data Structure for MISC_SET_REGISTER_VALUE */
    PMU_CTRL_MISC_GET_REGISTER_VALUE rPMUMiscGetRegisterValue; /* Data Structure for MISC_GET_REGISTER_VALUE */

}PMU_CTRL_DATA;
#else /* __BUILD_DOM__ */
#define PMU_CTRLS \
    PMU_CTRL_LDO_BUCK_CTRL rPMULdoBuckCtrl; \
    PMU_CTRL_LDO_BUCK_SET_EN rPMULdoBuckSetEn; \
    PMU_CTRL_LDO_BUCK_GET_EN_STATUS rPMULdoBuckGetEnStatus; \
    PMU_CTRL_LDO_BUCK_GET_QI_MODE rPMULdoBuckGetQiMode; \
    PMU_CTRL_LDO_BUCK_SET_EN_FORCE rPMULdoBuckSetEnForce; \
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE rPMULdoBuckSetVoltage; \
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE_EN rPMULdoBuckSetVoltageEn; \
    PMU_CTRL_LDO_BUCK_SET_SLEEP_VOLTAGE rPMULdoBuckSetSleepVoltage; \
    PMU_CTRL_LDO_BUCK_SET_BURST_THRESHOLD rPMULdoBuckSetBurstThreshold; \
    PMU_CTRL_LDO_BUCK_SET_CURRENT_LIMIT rPMULdoBuckSetCurrentLimit; \
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE rPMULdoBuckSetVoltageCalibrationCode; \
    PMU_CTRL_LDO_BUCK_SET_BIAS_CURRENT_CALIBRATION_CODE rPMULdoBuckSetBiasCurrentCalibrationCode; \
    PMU_CTRL_LDO_BUCK_SET_STB_EN rPMULdoBuckSetStbEn; \
    PMU_CTRL_LDO_BUCK_SET_OC_AUTO_OFF rPMULdoBuckSetOcAutoOff; \
    PMU_CTRL_LDO_BUCK_SET_RS rPMULdoBuckSetRs; \
    PMU_CTRL_LDO_BUCK_SET_ON_SEL rPMULdoBuckSetOnSel; \
    PMU_CTRL_LDO_BUCK_SET_SRCLKEN_SEL rPMULdoBuckSetSrclkenSel; \
    PMU_CTRL_LDO_BUCK_SET_STB_TD rPMULdoBuckSetStbTd; \
    PMU_CTRL_LDO_BUCK_SET_NDIS_EN rPMULdoBuckSetNdisEn; \
    PMU_CTRL_LDO_BUCK_SET_OC_TD rPMULdoBuckSetOcTd; \
    PMU_CTRL_LDO_BUCK_SET_OCFB_EN rPMULdoBuckSetOcfbEn; \
    PMU_CTRL_LDO_BUCK_SET_VSIM_GPLDO_EN rPMULdoBuckSetVsimGpldoEn; \
    PMU_CTRL_LDO_BUCK_SET_VSIM2_GPLDO_EN rPMULdoBuckSetVsim2GpldoEn; \
    PMU_CTRL_LDO_BUCK_SET_SIM2_GPIO_EN rPMULdoBuckSetSim2GpioEn; \
    PMU_CTRL_LDO_BUCK_SET_CCI_SRCLKEN rPMULdoBuckSetCciSrclken; \
    PMU_CTRL_LDO_BUCK_GET_OC_STATUS rPMULdoBuckGetOcStatus; \
    PMU_CTRL_LDO_BUCK_GET_QI_OC_STATUS rPMULdoBuckGetQiOcStatus; \
    PMU_CTRL_LDO_BUCK_SET_OC_INT_EN rPMULdoBuckSetOcIntEn; \
    PMU_CTRL_LDO_BUCK_CLEAR_OC_FLAG rPMULdoBuckClearOcFlag; \
    PMU_CTRL_LDO_BUCK_GET_OC_FLAG rPMULdoBuckGetOcFlag; \
    PMU_CTRL_LDO_BUCK_GET_VOLTAGE_LIST rPMULdoBuckGetVoltageList; \
    PMU_CTRL_LDO_BUCK_SET_THER_SHDN_EN rPMULdoBuckSetTherShdnEn; \
    PMU_CTRL_LDO_BUCK_SET_LP_MODE_SET rPMULdoBuckSetLpModeSet; \
    PMU_CTRL_LDO_BUCK_GET_LP_MODE rPMULdoBuckGetLpMode; \
    PMU_CTRL_LDO_BUCK_SET_LP_SEL rPMULdoBuckSetLpSel; \
    PMU_CTRL_LDO_BUCK_SET_ON_CTRL rPMULdoBuckSetOnCtrl; \
    PMU_CTRL_LDO_BUCK_SET_MODESET rPMULdoBuckSetModeset; \
    PMU_CTRL_LDO_BUCK_SET_EN_CTRL rPMULdoBuckSetEnCtrl; \
    PMU_CTRL_LDO_BUCK_SET_EN_SEL rPMULdoBuckSetEnSel; \
    PMU_CTRL_LDO_BUCK_SET_SRCLK_MODE_SEL rPMULdoBuckSetSrclkModeSel; \
    PMU_CTRL_LDO_BUCK_SET_SRCLK_EN_SEL rPMULdoBuckSetSrclkEnSel; \
    PMU_CTRL_LDO_SET_CAL rPMULdoSetCal; \
    PMU_CTRL_VPA_SET_VOSEL_MAP_EN rPMUVpaSetVoselMapEn; \
    PMU_CTRL_VPA_SET_EN rPMUVpaSetEn; \
    PMU_CTRL_VPA_SET_VOLTAGE rPMUVpaSetVoltage; \
	PMU_CTRL_VPA_CTRL_SEL rPMUVpaCtrlSel; \
    PMU_CTRL_VPA_GET_VOLTAGE_LIST rPMUVpaGetVoltageList; \
    PMU_CTRL_VPA_SET_BAT_LOW rPMUVpaSetBatLow; \
	PMU_CTRL_VPA_SET_FPWM rPMUVpaSetFpwm; \
    PMU_CTRL_VPA_SET_VOLTAGE_SELECTION_TABLE rPMUVpaSetVoltageSelectionTable; \
    PMU_CTRL_VPA_SET_MAP_SEL rPMUVpaSetMapSel; \
    PMU_CTRL_VIBR_SET_DIMMING_ON_DUTY rPMUVibrSetDimmingOnDuty; \
	PMU_CTRL_VRF18_SET_FPWM rPMUVrf18SetFpwm; \
    PMU_CTRL_VRF18_SET_MODESET rPMUVrf18SetModeset; \
    PMU_CTRL_VRF18_SET_BUCK_LDO_MODE rPMUVrf18SetBuckLdoMode; \
    PMU_CTRL_VRF1_SET_MODESET_CKPDN_SET rPMUVrf1SetModesetCkpdnSet; \
    PMU_CTRL_VRF1_SET_MODESET_CKPDN_CLR rPMUVrf1SetModesetCkpdnClr; \
    PMU_CTRL_VRF1_GET_MODESET_CKPDN rPMUVrf1GetModesetCkpdn; \
    PMU_CTRL_SIMLS_SET_SRST_CONF rPMUSimlsSetSrstConf; \
    PMU_CTRL_SIMLS_SET_SCLK_CONF rPMUSimlsSetSclkConf; \
    PMU_CTRL_SIMLS_SET_TDSEL rPMUSimlsSetTdsel; \
    PMU_CTRL_SIMAP_SET_TDSEL rPMUSimapSetTdsel; \
    PMU_CTRL_SIMLS_SET_RDSEL rPMUSimlsSetRdsel; \
    PMU_CTRL_SIMAP_SET_RDSEL rPMUSimapSetRdsel; \
    PMU_CTRL_SIM_SET_STB_SIO_MODE rPMUSimSetStbSioMode; \
    PMU_CTRL_SIMRST_SET_GPIO_SET rPMUSimrstSetGpioSet; \
    PMU_CTRL_SIMRST_SET_GPIO_CLR rPMUSimrstSetGpioClr; \
    PMU_CTRL_OCTL_SET_SIM_AP_SRST rPMUOctlSetSimApSrst; \
    PMU_CTRL_OCTL_SET_SIM_AP_SCLK rPMUOctlSetSimApSclk; \
    PMU_CTRL_OCTL_SET_SIMLS_SRST rPMUOctlSetSimlsSrst; \
    PMU_CTRL_OCTL_SET_SIMLS_SCLK rPMUOctlSetSimlsSclk; \
    PMU_CTRL_SPK_SET_EN rPMUSpkSetEn; \
    PMU_CTRL_SPK_SET_MODE rPMUSpkSetMode; \
    PMU_CTRL_SPK_GET_MODE rPMUSpkGetMode; \
    PMU_CTRL_SPK_SET_OC_AUTO_OFF rPMUSpkSetOcAutoOff; \
    PMU_CTRL_SPK_SET_VOL_VALUE rPMUSpkSetVolValue; \
    PMU_CTRL_SPK_GET_VOL_VALUE rPMUSpkGetVolValue; \
    PMU_CTRL_SPK_SET_VOL rPMUSpkSetVol; \
    PMU_CTRL_SPK_GET_VOL rPMUSpkGetVol; \
    PMU_CTRL_SPK_SET_SLEW_RATE rPMUSpkSetSlewRate; \
    PMU_CTRL_SPK_SET_CALIBR_EN rPMUSpkSetCalibrEn; \
    PMU_CTRL_SPK_SET_CALIBR_SEL rPMUSpkSetCalibrSel; \
    PMU_CTRL_FLASHLED_SET_EN rPMUFlashledSetEn; \
    PMU_CTRL_FLASHLED_SET_MODE rPMUFlashledSetMode; \
    PMU_CTRL_FLASHLED_SET_SEL rPMUFlashledSetSel; \
    PMU_CTRL_KPLED_SET_EN rPMUKpledSetEn; \
    PMU_CTRL_KPLED_SET_MODE rPMUKpledSetMode; \
    PMU_CTRL_KPLED_SET_SEL rPMUKpledSetSel; \
    PMU_CTRL_KPLED_SET_FREQUENCY_DIVISION rPMUKpledSetFrequencyDivision; \
    PMU_CTRL_KPLED_SET_DIMMING_ON_DUTY rPMUKpledSetDimmingOnDuty; \
    PMU_CTRL_CHR_SET_ADC_MEASURE_EN rPMUChrSetAdcMeasureEn; \
    PMU_CTRL_CHR_SET_WDT_TIMER rPMUChrSetWdtTimer; \
    PMU_CTRL_CHR_SET_WDT_INT_EN rPMUChrSetWdtIntEn; \
    PMU_CTRL_CHR_SET_WDT_EN rPMUChrSetWdtEn; \
    PMU_CTRL_CHR_SET_CHR_EN rPMUChrSetChrEn; \
    PMU_CTRL_CHR_SET_CHR_FORCE_EN rPMUChrSetChrForceEn; \
    PMU_CTRL_CHR_GET_CHR_DET_STATUS rPMUChrGetChrDetStatus; \
    PMU_CTRL_CHR_GET_CHR_CURRENT rPMUChrGetChrCurrent; \
    PMU_CTRL_CHR_GET_CHR_CURRENT_LIST rPMUChrGetChrCurrentList; \
    PMU_CTRL_CHR_SET_CHR_CURRENT rPMUChrSetChrCurrent; \
    PMU_CTRL_CHR_GET_CV_DETECTION_STATUS rPMUChrGetCvDetectionStatus; \
    PMU_CTRL_CHR_SET_CV_DETECTION_EN rPMUChrSetCvDetectionEn; \
    PMU_CTRL_CHR_SET_CV_DETECTION_VOLTAGE rPMUChrSetCvDetectionVoltage; \
    PMU_CTRL_CHR_SET_CSDAC_EN rPMUChrSetCsdacEn; \
    PMU_CTRL_CHR_GET_IS_BATTERY_ON rPMUChrGetIsBatteryOn; \
    PMU_CTRL_CHR_GET_IS_CHR_VALID rPMUChrGetIsChrValid; \
    PMU_CTRL_CHR_SET_HV_DETECTION_VOLTAGE rPMUChrSetHvDetectionVoltage; \
    PMU_CTRL_CHR_GET_HV_DETECTION_VOLTAGE_LIST rPMUChrGetHvDetectionVoltageList; \
    PMU_CTRL_CHR_SET_VBAT_OV_DETECTION_VOLTAGE rPMUChrSetVbatOvDetectionVoltage; \
    PMU_CTRL_CHR_SET_BAT_HT_EN rPMUChrSetBatHtEn; \
    PMU_CTRL_CHR_SET_OTG_BVALID_EN rPMUChrSetOtgBvalidEn; \
    PMU_CTRL_CHR_SET_CV_MODE rPMUChrSetCvMode; \
    PMU_CTRL_CHR_SET_CSDAC_MODE rPMUChrSetCsdacMode; \
    PMU_CTRL_CHR_SET_TRACKING_EN rPMUChrSetTrackingEn; \
    PMU_CTRL_CHR_SET_HWCV_EN rPMUChrSetHwcvEn; \
    PMU_CTRL_CHR_SET_ULC_DET_EN rPMUChrSetUlcDetEn; \
    PMU_CTRL_CHR_SET_BC11_PULLUP_EN rPMUChrSetBc11PullupEn; \
    PMU_CTRL_CHR_SET_LOW_ICH_DB rPMUChrSetLowIchDb; \
    PMU_CTRL_CHR_SET_VBAT_CV_CALIBRATION rPMUChrSetVbatCvCalibration; \
    PMU_CTRL_CHR_GET_CC_DET rPMUChrGetCcDet; \
    PMU_CTRL_BL_SET_EN rPMUBlSetEn; \
    PMU_CTRL_BL_SET_INIT rPMUBlSetInit; \
    PMU_CTRL_BL_GET_SUPPORT_LEVEL rPMUBlGetSupportLevel; \
    PMU_CTRL_BL_GET_USE_PWM_QUERY rPMUBlGetUsePwmQuery; \
    PMU_CTRL_BOOST_SET_EN rPMUBoostSetEn; \
    PMU_CTRL_BOOST_SET_CURRENT_LIMIT rPMUBoostSetCurrentLimit; \
    PMU_CTRL_BOOST_SET_CLK_CAL rPMUBoostSetClkCal; \
    PMU_CTRL_BOOST_SET_SYNC_EN rPMUBoostSetSyncEn; \
    PMU_CTRL_BOOST_SET_VOLTAGE rPMUBoostSetVoltage; \
    PMU_CTRL_BOOST_SET_LEVEL rPMUBoostSetLevel; \
    PMU_CTRL_ISINK_SET_EN rPMUIsinkSetEn; \
    PMU_CTRL_ISINK_SET_MODE rPMUIsinkSetMode; \
    PMU_CTRL_ISINK_SET_STEP rPMUIsinkSetStep; \
    PMU_CTRL_ISINK_SET_FORCE_OFF rPMUIsinkSetForceOff; \
    PMU_CTRL_ISINK_SET_DIMMING_ON_DUTY rPMUIsinkSetDimmingOnDuty; \
    PMU_CTRL_ISINK_SET_FREQUENCY_DIVISION rPMUIsinkSetFrequencyDivision; \
    PMU_CTRL_ADC_SET_RQST rPMUAdcSetRqst; \
    PMU_CTRL_ADC_GET_RDY_MD rPMUAdcGetRdyMd; \
    PMU_CTRL_ADC_GET_OUT_MD rPMUAdcGetOutMd; \
    PMU_CTRL_MISC_SET_RLED_EN rPMUMiscSetRledEn; \
    PMU_CTRL_MISC_SET_GLED_EN rPMUMiscSetGledEn; \
    PMU_CTRL_MISC_SET_BLED_EN rPMUMiscSetBledEn; \
    PMU_CTRL_MISC_GET_CID rPMUMiscGetCid; \
    PMU_CTRL_MISC_GET_ECO_VERSION rPMUMiscGetEcoVersion; \
    PMU_CTRL_MISC_GET_HW_VERSION rPMUMiscGetHwVersion; \
    PMU_CTRL_MISC_SET_REGISTER_VALUE rPMUMiscSetRegisterValue; \
    PMU_CTRL_MISC_GET_REGISTER_VALUE rPMUMiscGetRegisterValue; 
#endif /* __BUILD_DOM__ */

/*******************************************************************************
 * DCL_CTRL_CMD for PMU
 *******************************************************************************/
 #ifdef __BUILD_DOM__
/* The PMU Command Values in DCL_CTRL_CMD_T Enum of dcl.h */
typedef enum {
    LDO_BUCK_SET_CMDS_START = 0, /* For internal use  */
    LDO_BUCK_CTRL, /* For internal use  */
    LDO_BUCK_SET_EN, /* enable ldo/buck */
    LDO_BUCK_GET_EN_STATUS, /* Get LDO/BUCK Enable Status */    
    LDO_BUCK_GET_QI_MODE, /* Get LDO/BUCK QI Mode */     
    LDO_BUCK_SET_EN_FORCE, /* set ldo/buck force enable */
    LDO_BUCK_SET_VOLTAGE, /* set ldo/buck voltage */
    LDO_BUCK_SET_VOLTAGE_EN, /* set ldo/buck voltage and enable */
    LDO_BUCK_SET_SLEEP_VOLTAGE, /* set ldo/buck sleep voltage */
    LDO_BUCK_SET_BURST_THRESHOLD = 500, /* set ldo/buck burst threshold */
    LDO_BUCK_SET_CURRENT_LIMIT, /* set ldo/buck current limit */
    LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE, /* set ldo/buck voltage calibration code */
    LDO_BUCK_SET_BIAS_CURRENT_CALIBRATION_CODE, /* set ldo/buck bias current calibration code */
    LDO_BUCK_SET_STB_EN, /* enable ldo/buck soft start */
    LDO_BUCK_SET_OC_AUTO_OFF, /* enable to power-off automatically if oc_flag been asserted */
    LDO_BUCK_SET_RS, /* set ldo/buck local/remote sense */
    LDO_BUCK_SET_ON_SEL, /* enable control selection, hardware/software */
    LDO_BUCK_SET_SRCLKEN_SEL, /* h/w srclk enable selection */
    LDO_BUCK_SET_STB_TD, /* set ldo/buck deglitch delay time for soft start */
    LDO_BUCK_SET_NDIS_EN, /* enable ldo/buck NMOS discharge */
    LDO_BUCK_SET_OC_TD, /* set ldo/buck deglitch time constant for over-current status from PMU to generate oc_flag */
    LDO_BUCK_SET_OCFB_EN, /* enable ldo/buck over-current fold-back */
    LDO_BUCK_SET_VSIM_GPLDO_EN, /* select VSIM LDO enable & voltage controlled by SIM controller or register */
    LDO_BUCK_SET_VSIM2_GPLDO_EN, /* select VSIM2 LDO enable & voltage controlled by SIM2 controller or register */
    LDO_BUCK_SET_SIM2_GPIO_EN, /* set SIM2 GPIO enable */    
    LDO_BUCK_SET_CCI_SRCLKEN, /* enable SRCLKENA to PMIC force enable control signal */
    LDO_BUCK_GET_OC_STATUS, /* Get LDO/BUCK Over Current Status */
    LDO_BUCK_GET_QI_OC_STATUS, /* Get LDO/BUCK QI Over Current Status */    
    LDO_BUCK_SET_OC_INT_EN, /* enable oc interrupt of a ldo or buck */
    LDO_BUCK_CLEAR_OC_FLAG, /* clear oc flag of ldo or buck */
    LDO_BUCK_GET_OC_FLAG, /* get oc flag of ldo or buck */
    LDO_BUCK_GET_VOLTAGE_LIST, /* get voltage list of ldo or buck */
    LDO_BUCK_SET_THER_SHDN_EN, /* Set Low Power Mode */    
    LDO_BUCK_SET_LP_MODE_SET, /* Set Low Power Mode */
    LDO_BUCK_GET_LP_MODE, /* get lp mode of ldo or buck */
    LDO_BUCK_SET_LP_SEL, /* Set Low Power Mode Selection */
    LDO_BUCK_SET_ON_CTRL, /* Set On Control Mode */
    LDO_BUCK_SET_MODESET, /* Switch between force PWM mode and AUTO Mode */
    LDO_BUCK_SET_EN_CTRL, /* Enable Control */
    LDO_BUCK_SET_EN_SEL, /* Enable Selection */
    LDO_BUCK_SET_SRCLK_MODE_SEL, /* HW low power mode srclk selection */
    LDO_BUCK_SET_SRCLK_EN_SEL, /* Enable Selection */    
    LDO_SET_CAL, /* ldo output voltage calibration */    
    LDO_BUCK_SET_CMDS_END, /* For internal use  */
    VIBR_SET_DIMMING_ON_DUTY = 900, /* modify vibrator dimming duty */
    VPA_SET_VOLTAGE = 1000, /* set VPA0-7 voltage */
    VPA_SET_VOSEL_MAP_EN, /* enables voltage mapping to select VPA_VOSEL from vpa vosel table depending on vpa_table_sel */
    VPA_SET_EN, /* enable VPA */
	VPA_CTRL_SEL, /* Control the VPA Sourse */
    VPA_GET_VOLTAGE_LIST, /* get VPA supported voltage list */
    VPA_SET_BAT_LOW, /* BAT_LOW to indicate VPA by-pass mode (6326) */
	VPA_SET_FPWM, /* set VPA FPWM */
    VPA_SET_VOLTAGE_SELECTION_TABLE, /* voltage selection when vpa_vosel_map_en=1 */
    VPA_SET_MAP_SEL, /* Selects one entry in vpa vosel table to use for VPA_VOSEL */	
	VRF18_SET_MODESET, /* set VRF18 Force PWM Mode */
	VRF18_SET_FPWM, /* set VRF18 FPWM */
	VRF18_2_SET_FPWM, /* set VRF18_2 FPWM */
	VRF18_SET_BUCK_LDO_MODE, /* set VRF18 Buck/LDO Mode */
    VRF1_SET_MODESET_CKPDN_SET, /* VRF1 MODESET Clock SET */
    VRF1_SET_MODESET_CKPDN_CLR, /* VRF1 MODESET Clock CLR */
    VRF1_GET_MODESET_CKPDN, /* Enable Selection */    
    SIMLS_SET_SRST_CONF, /* Set SIMLS_SRST */	
    SIMLS_SET_SCLK_CONF, /* Set SIMLS_SCLK */ 
    SIMLS_SET_TDSEL, /* Set SIMLS_TDSEL */    
    SIMAP_SET_TDSEL, /* Set SIMAP_RDSEL */    
    SIMLS_SET_RDSEL, /* Set SIMLS_TDSEL */    
    SIMAP_SET_RDSEL, /* Set SIMAP_RDSEL */
    SIM_SET_STB_SIO_MODE, /* Set SIM STB SIO Mode */ 
    SIMRST_SET_GPIO_SET, /* Set SIMRST GPIO */
    SIMRST_SET_GPIO_CLR, /* Clear SIMRST GPIO */
    OCTL_SET_SIM_AP_SRST, /* Set OCTL_SIM_AP_SRST */ 
    OCTL_SET_SIM_AP_SCLK, /* Set OCTL_SIM_AP_SCLK */
    OCTL_SET_SIMLS_SRST, /* Set OCTL_SIMLS_SRST */
    OCTL_SET_SIMLS_SCLK, /* Set OCTL_SIMLS_SCLK */
    SPK_SET_EN = 2000, /* enable spk */
    SPK_SET_MODE, /* set spk mode */
    SPK_GET_MODE, /* get spk mode */    
    SPK_SET_OC_AUTO_OFF, /* enable spk over-current auto off */
    SPK_SET_VOL_VALUE, /* set spk volume (register value) */
    SPK_GET_VOL_VALUE, /* get spk volume (register value) */
    SPK_SET_VOL, /* set spk volume (dbm) */
    SPK_GET_VOL, /* get spk volume (dbm) */
    SPK_SET_SLEW_RATE, /* set spk slew rate */
    SPK_SET_CALIBR_EN, /* set spk Class D offset calibration enable */
    SPK_SET_CALIBR_SEL, /* set spk Class D offset calibration path */
    KPLED_SET_EN = 3000, /* enable kpled */
    KPLED_SET_MODE, /* set kpled mode (pwm/register) */
    KPLED_SET_SEL, /* kpled Turn On Resistor Select */
    KPLED_SET_FREQUENCY_DIVISION, /* set kpled frequency division */
    KPLED_SET_DIMMING_ON_DUTY, /* set kpled dimming duty */
    FLASHLED_SET_EN = 4000, /* enable flashled */
    FLASHLED_SET_MODE, /* set flashled mode (pwm/regsiter) */
    FLASHLED_SET_SEL, /* kpled Turn On Resistor Select */
    BL_SET_INIT = 5000, /* backlight init mode */
    BL_SET_EN, /* enable backlight */
    BL_GET_SUPPORT_LEVEL, /* get backlight support level */
    BL_GET_USE_PWM_QUERY, /* get backlight use pwm query */
    BOOST_SET_EN = 6000, /* enable boost */
    BOOST_SET_CURRENT_LIMIT, /* set boost current limit */
    BOOST_SET_CLK_CAL, /* set boost clock cal */
    BOOST_SET_SYNC_EN, /* enable boost sync */
    BOOST_SET_VOLTAGE, /* set boost voltage */
    BOOST_SET_LEVEL, /* set boost level */
    ISINK_SET_EN = 7000, /* enable isink */
    ISINK_SET_MODE, /* set isink mode */
    ISINK_SET_STEP, /* set isink step */
    ISINK_SET_FORCE_OFF, /* set isink force off */
    ISINK_SET_CHANNEL, /* set isink channel */
    ISINK_SET_DIMMING_ON_DUTY, /* set kpled dimming duty */
    ISINK_SET_FREQUENCY_DIVISION, /* set kpled frequency division */
    CHR_SET_ADC_MEASURE_EN = 8000, /* enable adc measure */
    CHR_SET_WDT_CLEAR, /* clear charger wdt */
    CHR_SET_WDT_TIMER, /* set charger wdt timer */
    CHR_SET_WDT_INT_EN, /* enable charger wdt interrupt */
    CHR_SET_WDT_EN, /* enable charger wdt */
    CHR_SET_CHR_EN, /* enable charger */
    CHR_SET_CHR_FORCE_EN, /* force enable charger */
    CHR_GET_CHR_DET_STATUS, /* get charger detection status */
    CHR_GET_CHR_CURRENT, /* get charger current */
    CHR_GET_CHR_CURRENT_LIST, /* get charger current list */
    CHR_SET_CHR_CURRENT, /* set charger current */
    CHR_GET_CV_DETECTION_STATUS, /* get CV detection status */
    CHR_SET_CV_DETECTION_EN, /* enable CV detection */
    CHR_SET_CV_DETECTION_VOLTAGE, /* set CV voltage */
    CHR_SET_CV_DETECTION_VOLTAGE_CALIBRATION, /* set CV voltage calibration */
    CHR_SET_CSDAC_EN, /* enable csdac */
    CHR_GET_IS_BATTERY_ON, /* check is battery on */
    CHR_GET_IS_CHR_VALID, /* check is charger valid */
    CHR_SET_HV_DETECTION_VOLTAGE, /* set HV detection voltage */
    CHR_GET_HV_DETECTION_VOLTAGE_LIST, /* get HV detection voltage list */
    CHR_SET_VBAT_OV_DETECTION_VOLTAGE, /* set battery OV detection voltage */
    CHR_SET_BAT_HT_EN, /* enable battery high tempture detection */
    CHR_SET_OTG_BVALID_EN, /* enable OTG BVALID */
    CHR_SET_CV_MODE, /* enable CV detect@ charging enable */
    CHR_SET_CSDAC_MODE, /* enable s/w control */
    CHR_SET_TRACKING_EN, /* enable HTH/LTH for current tracking */
    CHR_SET_HWCV_EN, /* enable H/W CV */
    CHR_SET_ULC_DET_EN, /* enable plug out HW detection */
    CHR_SET_LOW_ICH_DB, /* set plug out HW detection de-bounce time */
    CHR_SET_CHARGE_WITHOUT_BATTERY, /* enable charger without battery */
    CHR_SET_BC11_PULLUP_EN,	/* turn on/off BC11 pull up*/
    CHR_SET_VBAT_CV_CALIBRATION, /* do VBAT CV Calibration trimming */
    CHR_GET_CC_DET, /* get VBAT CC detection result */
    ADC_SET_RQST, /* AUXADC MD request */
    ADC_GET_RDY_MD, /* AUXADC MD Data Ready */
    ADC_GET_OUT_MD, /* AUXADC channel output data for MD */    
    MISC_SET_RLED_EN = 9000, /* enable Red led */
    MISC_SET_GLED_EN, /* enable green led */
    MISC_SET_BLED_EN, /* enable blue led */
    MISC_GET_CID, /* get pmu/pmic cid */
    MISC_GET_ECO_VERSION, /* get pmu/pmic eco version */
    MISC_GET_HW_VERSION, /* get pmu/pmic HW version */ 
    MISC_SET_REGISTER_VALUE, /* set pmu/pmic register value */
    MISC_GET_REGISTER_VALUE, /* get pmu/pmic register value */
	PMU_MOD_CMD_MAX,
} PMU_CTRL_CMD;
#else /* __BUILD_DOM__ */
#define PMU_CMDS \
    LDO_BUCK_SET_CMDS_START = 0, \
    LDO_BUCK_CTRL, \
    LDO_BUCK_SET_EN, \
    LDO_BUCK_GET_EN_STATUS, \
    LDO_BUCK_GET_QI_MODE, \
    LDO_BUCK_SET_EN_FORCE, \
    LDO_BUCK_SET_VOLTAGE, \
    LDO_BUCK_SET_VOLTAGE_EN, \
    LDO_BUCK_SET_SLEEP_VOLTAGE, \
    LDO_BUCK_SET_BURST_THRESHOLD = 500, \
    LDO_BUCK_SET_CURRENT_LIMIT, \
    LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE, \
    LDO_BUCK_SET_BIAS_CURRENT_CALIBRATION_CODE, \
    LDO_BUCK_SET_STB_EN, \
    LDO_BUCK_SET_OC_AUTO_OFF, \
    LDO_BUCK_SET_RS, \
    LDO_BUCK_SET_ON_SEL, \
    LDO_BUCK_SET_SRCLKEN_SEL, \
    LDO_BUCK_SET_STB_TD, \
    LDO_BUCK_SET_NDIS_EN, \
    LDO_BUCK_SET_OC_TD, \
    LDO_BUCK_SET_OCFB_EN, \
    LDO_BUCK_SET_VSIM_GPLDO_EN, \
    LDO_BUCK_SET_VSIM2_GPLDO_EN, \
    LDO_BUCK_SET_SIM2_GPIO_EN, \
    LDO_BUCK_SET_CCI_SRCLKEN, \
    LDO_BUCK_GET_OC_STATUS, \
    LDO_BUCK_GET_QI_OC_STATUS, \
    LDO_BUCK_SET_OC_INT_EN, \
    LDO_BUCK_CLEAR_OC_FLAG, \
    LDO_BUCK_GET_OC_FLAG, \
    LDO_BUCK_GET_VOLTAGE_LIST, \
    LDO_BUCK_SET_THER_SHDN_EN, \
    LDO_BUCK_SET_LP_MODE_SET, \
    LDO_BUCK_GET_LP_MODE, \
    LDO_BUCK_SET_LP_SEL, \
    LDO_BUCK_SET_ON_CTRL, \
    LDO_BUCK_SET_MODESET, \
    LDO_BUCK_SET_EN_CTRL, \
    LDO_BUCK_SET_SRCLK_MODE_SEL, \
    LDO_BUCK_SET_SRCLK_EN_SEL, \
    LDO_BUCK_SET_EN_SEL, \
    LDO_SET_CAL, \
    LDO_BUCK_SET_CMDS_END, \
    VIBR_SET_DIMMING_ON_DUTY = 900, \
    VPA_SET_VOLTAGE = 1000, \
    VPA_SET_VOSEL_MAP_EN, \
    VPA_SET_EN, \
	VPA_CTRL_SEL, \
    VPA_GET_VOLTAGE_LIST, \
    VPA_SET_BAT_LOW, \
	VPA_SET_FPWM, \
    VPA_SET_VOLTAGE_SELECTION_TABLE, \
    VPA_SET_MAP_SEL, \
	VRF18_SET_FPWM, \
	VRF18_SET_MODESET, \
	VRF18_2_SET_FPWM, \
	VRF18_SET_BUCK_LDO_MODE, \
    VRF1_SET_MODESET_CKPDN_SET, \
    VRF1_SET_MODESET_CKPDN_CLR, \
    VRF1_GET_MODESET_CKPDN, \
    SIMLS_SET_SRST_CONF, \
    SIMLS_SET_SCLK_CONF, \
    SIMLS_SET_TDSEL, \
    SIMAP_SET_TDSEL, \
    SIMLS_SET_RDSEL, \
    SIMAP_SET_RDSEL, \
    SIM_SET_STB_SIO_MODE, \
    SIMRST_SET_GPIO_SET, \
    SIMRST_SET_GPIO_CLR, \
    OCTL_SET_SIM_AP_SRST, \
    OCTL_SET_SIM_AP_SCLK, \
    OCTL_SET_SIMLS_SRST, \
    OCTL_SET_SIMLS_SCLK, \
    SPK_SET_EN = 2000, \
    SPK_SET_MODE, \
    SPK_GET_MODE, \
    SPK_SET_OC_AUTO_OFF, \
    SPK_SET_VOL_VALUE, \
    SPK_GET_VOL_VALUE, \
    SPK_SET_VOL, \
    SPK_GET_VOL, \
    SPK_SET_SLEW_RATE, \
    SPK_SET_CALIBR_EN, \
    SPK_SET_CALIBR_SEL, \
    KPLED_SET_EN = 3000, \
    KPLED_SET_MODE, \
    KPLED_SET_SEL, \
    KPLED_SET_FREQUENCY_DIVISION, \
    KPLED_SET_DIMMING_ON_DUTY, \
    FLASHLED_SET_EN = 4000, \
    FLASHLED_SET_MODE, \
    FLASHLED_SET_SEL, \
    BL_SET_INIT = 5000, \
    BL_SET_EN, \
    BL_GET_SUPPORT_LEVEL, \
    BL_GET_USE_PWM_QUERY, \
    BOOST_SET_EN = 6000, \
    BOOST_SET_CURRENT_LIMIT, \
    BOOST_SET_CLK_CAL, \
    BOOST_SET_SYNC_EN, \
    BOOST_SET_VOLTAGE, \
    BOOST_SET_LEVEL, \
    ISINK_SET_EN = 7000, \
    ISINK_SET_MODE, \
    ISINK_SET_STEP, \
    ISINK_SET_FORCE_OFF, \
    ISINK_SET_CHANNEL, \
    ISINK_SET_DIMMING_ON_DUTY, \
    ISINK_SET_FREQUENCY_DIVISION, \
    CHR_SET_ADC_MEASURE_EN = 8000, \
    CHR_SET_WDT_CLEAR, \
    CHR_SET_WDT_TIMER, \
    CHR_SET_WDT_INT_EN, \
    CHR_SET_WDT_EN, \
    CHR_SET_CHR_EN, \
    CHR_SET_CHR_FORCE_EN, \
    CHR_GET_CHR_DET_STATUS, \
    CHR_GET_CHR_CURRENT, \
    CHR_GET_CHR_CURRENT_LIST, \
    CHR_SET_CHR_CURRENT, \
    CHR_GET_CV_DETECTION_STATUS, \
    CHR_SET_CV_DETECTION_EN, \
    CHR_SET_CV_DETECTION_VOLTAGE, \
    CHR_SET_CV_DETECTION_VOLTAGE_CALIBRATION, \
    CHR_SET_CSDAC_EN, \
    CHR_GET_IS_BATTERY_ON, \
    CHR_GET_IS_CHR_VALID, \
    CHR_SET_HV_DETECTION_VOLTAGE, \
    CHR_GET_HV_DETECTION_VOLTAGE_LIST, \
    CHR_SET_VBAT_OV_DETECTION_VOLTAGE, \
    CHR_SET_BAT_HT_EN, \
    CHR_SET_OTG_BVALID_EN, \
    CHR_SET_CV_MODE, \
    CHR_SET_CSDAC_MODE, \
    CHR_SET_TRACKING_EN, \
    CHR_SET_HWCV_EN, \
    CHR_SET_ULC_DET_EN, \
    CHR_SET_LOW_ICH_DB, \
    CHR_SET_CHARGE_WITHOUT_BATTERY, \
    CHR_SET_BC11_PULLUP_EN, \
    CHR_SET_VBAT_CV_CALIBRATION, \
    CHR_GET_CC_DET, \
    ADC_SET_RQST, \
    ADC_GET_RDY_MD, \
    ADC_GET_OUT_MD, \
    MISC_SET_RLED_EN = 9000, \
    MISC_SET_GLED_EN, \
    MISC_SET_BLED_EN, \
    MISC_GET_CID, \
    MISC_GET_ECO_VERSION, \
    MISC_GET_HW_VERSION, \
    MISC_SET_REGISTER_VALUE, \
    MISC_GET_REGISTER_VALUE, \
	PMU_MOD_CMD_MAX,
#endif /* __BUILD_DOM__ */

#endif // #ifndef __DCL_PMU_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT

#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_PMU_H_PROTOTYPE__
#define __DCL_PMU_H_PROTOTYPE__

typedef DCL_STATUS (*PMU_CONTROL_HANDLER)(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);

/*************************************************************************
* FUNCTION
*  DclPMU_Initialize
*
* DESCRIPTION
*  This function is to initialize PMU module
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclPMU_Initialize(void);
/*************************************************************************
* FUNCTION
*  DclPMU_Open
*
* DESCRIPTION
*  This function is to open the PMU module and return a handle
*
* PARAMETERS
*  dev: only valid for DCL_PMU
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed.
*  other value: a valid handle
*
*************************************************************************/
extern DCL_HANDLE DclPMU_Open(DCL_DEV dev, DCL_FLAGS flags);
/*************************************************************************
* FUNCTION
*  DclPMU_ReadData
*
* DESCRIPTION
*  This function is not supported for the PMU module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclPMU_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclPMU_WriteData
*
* DESCRIPTION
*  This function is not supported for the PMU module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclPMU_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclPMU_Configure
*
* DESCRIPTION
*  This function is not supported for the PMU module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclPMU_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION
*  DclPMU_RegisterCallback
*
* DESCRIPTION
*   This function is not supported for the PMU module now.
*
* PARAMETERS
*  	N/A
*
* RETURNS
*  STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclPMU_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);
/*************************************************************************
* FUNCTION
*  DclPMU_Control
*
* DESCRIPTION
*  This function is to send command to control the PMU module.
*
* PARAMETERS
*  handle: The handle value returned from DclPMU_Open
*  cmd: a control command for PMU module
*          LDO_BUCK_SET_CMDS_START: For internal use 
*          LDO_BUCK_CTRL: For internal use 
*          LDO_BUCK_SET_EN: enable ldo/buck
*          LDO_BUCK_GET_EN_STATUS: Get LDO/BUCK Enable Status
*          LDO_BUCK_GET_QI_MODE: Get LDO/BUCK QI MODE
*          LDO_BUCK_SET_EN_FORCE: set ldo/buck force enable
*          LDO_BUCK_SET_VOLTAGE: set ldo/buck voltage
*          LDO_BUCK_SET_VOLTAGE_EN: set ldo/buck voltage and enable
*          LDO_BUCK_SET_SLEEP_VOLTAGE: set ldo/buck sleep voltage
*          LDO_BUCK_SET_BURST_THRESHOLD: set ldo/buck burst threshold
*          LDO_BUCK_SET_CURRENT_LIMIT: set ldo/buck current limit
*          LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE: set ldo/buck voltage calibration code
*          LDO_BUCK_SET_BIAS_CURRENT_CALIBRATION_CODE: set ldo/buck bias current calibration code
*          LDO_BUCK_SET_STB_EN: enable ldo/buck soft start
*          LDO_BUCK_SET_OC_AUTO_OFF: enable to power-off automatically if oc_flag been asserted
*          LDO_BUCK_SET_RS: set ldo/buck local/remote sense
*          LDO_BUCK_SET_ON_SEL: enable control selection, hardware/software
*          LDO_BUCK_SET_STB_TD: set ldo/buck deglitch delay time for soft start
*          LDO_BUCK_SET_NDIS_EN: enable ldo/buck NMOS discharge
*          LDO_BUCK_SET_OC_TD: set ldo/buck deglitch time constant for over-current status from PMU to generate oc_flag
*          LDO_BUCK_SET_OCFB_EN: enable ldo/buck over-current fold-back
*          LDO_BUCK_SET_VSIM_GPLDO_EN: select VSIM LDO enable & voltage controlled by SIM controller or register
*          LDO_BUCK_SET_VSIM2_GPLDO_EN: select VSIM2 LDO enable & voltage controlled by SIM2 controller or register
*          LDO_BUCK_SET_SIM2_GPIO_EN: set SIM2 GPIO enable
*          LDO_BUCK_SET_CCI_SRCLKEN: enable SRCLKENA to PMIC force enable control signal
*          LDO_BUCK_GET_OC_STATUS: Get LDO/BUCK Over Current Status
*          LDO_BUCK_GET_QI_OC_STATUS: Get LDO/BUCK QI Over Current Status
*          LDO_BUCK_SET_THER_SHDN_EN: Set Low Power Mode
*          LDO_BUCK_SET_LP_MODE_SET: Set Low Power Mode
*          LDO_BUCK_SET_LP_SEL: Set Low Power Mode Selection
*          LDO_BUCK_SET_ON_CTRL: On Control Mode
*          LDO_BUCK_SET_MODESET: Switch between force PWM mode and AUTO Mode
*          LDO_BUCK_SET_EN_CTRL: Enable Control
*          LDO_BUCK_SET_EN_SEL: Enable Selection
*          LDO_BUCK_SET_SRCLK_MODE_SEL: HW low power mode srclk selection
*          LDO_BUCK_SET_SRCLK_EN_SEL: SRCLK_EN Selection
*          LDO_BUCK_SET_CMDS_END: For internal use 
*          VIBR_SET_DIMMING_ON_DUTY: modify vibrator dimming duty
*          VPA_SET_VOLTAGE: set VPA0-7 voltage
*          VPA_SET_VOSEL_MAP_EN: enables voltage mapping to select VPA_VOSEL from vpa vosel table depending on vpa_table_sel
*          VPA_SET_EN: enable VPA
*          VPA_GET_VOLTAGE_LIST: get VPA supported voltage list
*          VPA_SET_BAT_LOW: BAT_LOW to indicate VPA by-pass mode (6326)
*          VPA_SET_VOLTAGE_SELECTION_TABLE: voltage selection when vpa_vosel_map_en=1
*          VPA_SET_MAP_SEL: Selects one entry in vpa vosel table to use for VPA_VOSEL
*          VRF1_SET_MODESET_CKPDN_SET: Enable VRF1 MODESET Clock
*          VRF1_SET_MODESET_CKPDN_CLR: Disable VRF1 MODESET Clock
*          VRF1_GET_MODESET_CKPDN: Readback VRF1 MODESET Clock
*          SIMLS_SET_SRST_CONF: Set SIMLS_SRST
*          SIMLS_SET_SCLK_CONF: Set SIMLS_SCLK
*          SIMLS_SET_TDSEL: Set SIMLS_TDSEL
*          SIMAP_SET_TDSEL: Set SIMAP_TDSEL
*          SIMLS_SET_RDSEL: Set SIMLS_RDSEL
*          SIMAP_SET_RDSEL: Set SIMAP_RDSEL
*          SIM_SET_STB_SIO_MODE: Set SIM STB SIO Mode
*          SIMRST_SET_GPIO_SET: Set SIMRST GPIO
*          SIMRST_SET_GPIO_CLR: Clear SIMRST GPIO
*          OCTL_SET_SIM_AP_SCLK: Set SIM_AP_SRST
*          OCTL_SET_SIM_AP_SCLK: Set SIM_AP_SCLK
*          OCTL_SET_SIMLS_SCLK: Set SIMLS_SRST
*          OCTL_SET_SIMLS_SCLK: Set SIMLS_SCLK
*          LDO_SET_CAL: ldo output voltage calibration
*          SPK_SET_EN: enable spk
*          SPK_SET_MODE: set spk mode
*          SPK_GET_MODE: get spk mode
*          SPK_SET_OC_AUTO_OFF: enable spk over-current auto off
*          SPK_SET_VOL_VALUE: set spk volume (register value)
*          SPK_GET_VOL_VALUE: get spk volume (register value)
*          SPK_SET_VOL: set spk volume (dbm)
*          SPK_GET_VOL: get spk volume (dbm)
*          SPK_SET_SLEW_RATE: set spk slew rate
*          SPK_SET_CALIBR_EN: set spk Class D offset calibration enable
*          SPK_SET_CALIBR_SEL: set spk Class D offset calibration path
*          KPLED_SET_EN: enable kpled
*          KPLED_SET_MODE: set kpled mode (pwm/register)
*          KPLED_SET_SEL: kpled Turn On Resistor Select
*          KPLED_SET_FREQUENCY_DIVISION: set kpled frequency division
*          KPLED_SET_DIMMING_ON_DUTY: set kpled dimming duty
*          FLASHLED_SET_EN: enable flashled
*          FLASHLED_SET_MODE: set flashled mode (pwm/regsiter)
*          FLASHLED_SET_SEL: kpled Turn On Resistor Select
*          BL_SET_INIT: backlight init mode
*          BL_SET_EN: enable backlight
*          BOOST_SET_EN: enable boost
*          BOOST_SET_CURRENT_LIMIT: set boost current limit
*          BOOST_SET_CLK_CAL: set boost clock cal
*          BOOST_SET_SYNC_EN: enable boost sync
*          BOOST_SET_VOLTAGE: set boost voltage
*          BOOST_SET_LEVEL: set boost level
*          ISINK_SET_EN: enable isink
*          ISINK_SET_MODE: set isink mode
*          ISINK_SET_STEP: set isink step
*          ISINK_SET_FORCE_OFF: set isink force off
*          ISINK_SET_CHANNEL: set isink channel
*          ISINK_SET_DIMMING_ON_DUTY: set kpled dimming duty
*          ISINK_SET_FREQUENCY_DIVISION: set kpled frequency division
*          CHR_SET_ADC_MEASURE_EN: enable adc measure
*          CHR_SET_WDT_CLEAR: clear charger wdt
*          CHR_SET_WDT_TIMER: set charger wdt timer
*          CHR_SET_WDT_INT_EN: enable charger wdt interrupt
*          CHR_SET_WDT_EN: enable charger wdt
*          CHR_SET_CHR_EN: enable charger
*          CHR_SET_CHR_FORCE_EN: force enable charger
*          CHR_GET_CHR_DET_STATUS: get charger detection status
*          CHR_GET_CHR_CURRENT: get charger current
*          CHR_GET_CHR_CURRENT_LIST: get charger current list
*          CHR_SET_CHR_CURRENT: set charger current
*          CHR_GET_CV_DETECTION_STATUS: get CV detection status
*          CHR_SET_CV_DETECTION_EN: enable CV detection
*          CHR_SET_CV_DETECTION_VOLTAGE: set CV voltage
*          CHR_SET_CV_DETECTION_VOLTAGE_CALIBRATION: set CV voltage calibration
*          CHR_SET_CSDAC_EN: enable csdac
*          CHR_GET_IS_BATTERY_ON: check is battery on
*          CHR_GET_IS_CHR_VALID: check is charger valid
*          CHR_SET_HV_DETECTION_VOLTAGE: set HV detection voltage
*          CHR_SET_VBAT_OV_DETECTION_VOLTAGE: set battery OV detection voltage
*          CHR_SET_BAT_HT_EN: enable battery high tempture detection
*          CHR_SET_OTG_BVALID_EN: enable OTG BVALID
*          CHR_SET_CV_MODE: enable CV detect@ charging enable
*          CHR_SET_CSDAC_MODE: enable s/w control
*          CHR_SET_TRACKING_EN: enable HTH/LTH for current tracking
*          CHR_SET_HWCV_EN: enable H/W CV
*          CHR_SET_ULC_DET_EN: enable plug out HW detection
*          CHR_SET_LOW_ICH_DB: set plug out HW detection de-bounce time
*          CHR_GET_CC_DET: get VBAT CC detection result
*          ADC_SET_RQST: AUXADC MD request
*          ADC_GET_RDY_MD: AUXADC MD Data Ready
*          ADC_GET_OUT_MD: AUXADC channel output data for MD
*          MISC_SET_RLED_EN: enable Red led
*          MISC_SET_GLED_EN: enable green led
*          MISC_SET_BLED_EN: enable blue led
*          MISC_SET_REGISTER_VALUE: set pmu/pmic register value
*          MISC_GET_REGISTER_VALUE: get pmu/pmic register value
*  data: The data of the control command
*          cmd: xxxx : pointer to a PMU_CTRL_xxxx structure
*          ex: LDO_BUCK_SET_EN:  pointer to a PMU_CTRL_LDO_BUCK_SET_EN structure
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*     STATUS_UNSUPPORTED: It's a unsupported command.
*
*************************************************************************/
extern DCL_STATUS DclPMU_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION
*  DclPMU_Close
*
* DESCRIPTION
*  This function is to close the PMU module.
*
* PARAMETERS
*  handle: the returned handle value of DclPMU_Open
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclPMU_Close(DCL_HANDLE handle);

#endif // #ifndef __DCL_PMU_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE
