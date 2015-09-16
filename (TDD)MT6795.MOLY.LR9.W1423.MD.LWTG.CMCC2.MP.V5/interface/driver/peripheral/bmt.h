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
 *    bmt.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for Battery Management Task.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _BMT_H
#define _BMT_H

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "dcl.h"
#include "adc_cali.h"

#define ADC_BMT_VBAT            0
#define ADC_BMT_VISENSE         1
#define ADC_BMT_VBATTMP         2
#define ADC_BMT_VCHARGER	    3
#define ADC_BMT_MAX_CHANNEL_TOTAL   4
//#define BMT_MAX_CHANNEL_TOTAL       ADC_BMT_MAX_CHANNEL_TOTAL  // backward compatible

/*
#ifdef __BMT_CHECK_CHARGER__
#define BMT_MAX_CHANNEL    4
#else
#define BMT_MAX_CHANNEL    3
#endif
*/
#define BMT_ADC_VBAT            0
#define BMT_ADC_VISENSE         1
#define BMT_ADC_VBATTMP         2
#define BMT_ADC_VCHARGER	    3
#define BMT_ADC_MAX_CHANNEL_TOTAL   4

/*precharge threshold*/
#define BMT_PRECHARGE_THRESHOLD  3300000

#if defined(__TC01__)
#define DRV_BMT_NONE_USB_POWER_ON /* use charging power on instead of USB power on*/
#define __DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__
#endif // #if defined(__TC01__)

/*BatType*/
#define  LIBAT                            0
#define  NIBAT                            1

/*extern charger state*/
#define  DETECTCHRIN                      0x0
#define  DETECTCHROUT                     !DETECTCHRIN

/*BMT Minor STATE. When Charger is plugged in, charge is enable or not?*/
#define  PMIC_CHARGEOFF                   0   /*pmictrl_state*/
#define  PMIC_CHARGEON                    1   

/*MS Mode*/
#define idle_mode                         0
#define talk_mode                         1
#define swoff_mode                        2


#define BMT_HIGH_VCHG_THRESHOLD 100000

#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
#define VCHG_VOL_LEVEL      7
#define VCHG_PARAMTER_COUNT 3

typedef struct{
    kal_uint32 VCHG_HV_VTH;
    kal_int32 HIGH_VCHG_TABLE[VCHG_VOL_LEVEL][VCHG_PARAMTER_COUNT];
}bmt_customized_high_vchg_struct;

extern kal_bool High_Vchg_Safety_Timer_Set;
extern bmt_customized_high_vchg_struct *bmt_high_vchg_para;
extern kal_uint32 bmt_total_charge_time;
extern kal_bool bmt_safety_timer_config;
extern kal_int32 Pre_VCharge_AVG;
extern kal_int32 Cur_VCharge_MAX;
extern bmt_customized_high_vchg_struct *bmt_get_customized_high_vchg_para(void);

#endif // End of #if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)

typedef enum{
	CHARGER_PRESENT,
//#if defined(__CHINA_CHARGER_STANDARD__)
	CHARGER_PRESENT_NON,
//#endif
	USB_PRESENT,
	NO_PRESENT
}charger_usb_present_enum;

typedef enum{
	BMT_AC_CHR,
	BMT_USB_CHR
}bmt_charger_type;

typedef enum {
	bmt_chr_in=0,
   bmt_chr_out,
   bmt_chr_uninit = 0xff
}Charger_Status;

typedef enum {
	VBAT_UEM_CHR_OUT=0,
	VBAT_UEM_CHR_OUT_FIRST=1,
	VBAT_UEM_CHR_IN=2,
	VBAT_UEM_CHR_IN_FISRT=3
}VBAT_UEM_CHR_ENUM;

typedef enum 
{
   CHR_CURRENT_50=0,
   CHR_CURRENT_90,
   CHR_CURRENT_150,
   CHR_CURRENT_225,
   CHR_CURRENT_300,
   CHR_CURRENT_450,
   CHR_CURRENT_650,
   CHR_CURRENT_800
}pmic_charging_current;

typedef struct {
   kal_uint8               bat_state;
   kal_uint8               pmictrl_state;   /*pmic control on,off*/
   kal_uint8               call_state;   /*mobile state*/
  // kal_uint8               PWRon;
   kal_uint8               BatType;
   kal_uint8               EINT2STATE;
   kal_uint8               highfull;
   VBAT_UEM_CHR_ENUM		     VBAT_UEM; // state of UEM VBAT measurement 
   kal_hisrid              hisr;
} BMTStruct;

typedef struct {
   kal_int32 VBAT;
   kal_int32 ICHARGE;
   kal_int32 BATTMP;
   kal_int32 VCHARGER;
   kal_int32 ISense_Offset;
   //kal_uint8 BATTYPE;
} BATPHYStruct;

#if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
typedef struct{
	kal_bool chr_usb_state;	// indicate cable is plugged in or not for eint trigger level setting
	volatile charger_usb_present_enum chr_usb_present;	// is charger or usb presnet or not
	kal_int32 chr_usb_adc_handle;	// handle of dcl adc scheduler
	kal_uint8 chr_usb_eint;	// eint number for charger and usb
	kal_uint8 chr_usb_adc;	// adc channel to measure charger or usb
	kal_int32 chr_usb_volt;	// voltage to distinguish between charger with usb
}chr_usb_detect_struct;
#endif

// For external charger mechanism integration

// The enum is to indicate whether the charging factor is measured by HOST or Charger device
typedef enum
{
  CHR_FACTOR_MEASURE_NONE =             0x00000000,   // Both NOT support, TBD
  CHR_FACTOR_MEASURE_BY_HOST =          0x00000001,   // BIT00, HOST measure the specific charging factor
  CHR_FACTOR_MEASURE_BY_CHARGER_DEV =   0x00000002    // BIT01, Charger device measure the specific charging factor

}bmt_chr_fac_measure_support_enum;

// The enum is to indicate whether the charging factor error check is done by HOST or charger device
typedef enum
{
  BMT_CHR_FACTOR_CHECK_NONE =           0x00000000,   // Both NOT support, TBD
  BMT_CHR_FACTOR_CHECK_BY_HOST =        0x00000001,   // BIT00, HOST perform charging factor error check
  BMT_CHR_FACTOR_CHECK_BY_CHARGER_DEV = 0x00000002    // BIT01, Charger device perform charging facotr error check

}bmt_chr_fac_check_support_enum;

// The enum defines the charging factors that charging process need to check
typedef enum
{
  BMT_CHR_FACTOR_VBAT,               // Charging factor: VBAT
  BMT_CHR_FACTOR_ISENSE,             // Charging factor: VISENSE
  BMT_CHR_FACTOR_BATTMP,             // Charging factor: VBAT temperature
  BMT_CHR_FACTOR_VCHARGER,           // Charging factor: VCHARGER
  BMT_CHR_FACTOR_CHARGER_OVP,        // Charging factor: Charger OVP
  BMT_CHR_FACTOR_CHARGE_FULL,        // Charging factor: Charge full
  BMT_CHR_FACTOR_UNDER_EXTREMETMP,        // Charging factor: Extreme temperature
  BMT_CHR_FACTOR_CHARGE_EXTREMETMP_FULL,        // Charging factor: Charge full under extreme temperature
  BMT_CHR_FACTOR_CHARGE_EXTREMETMP_RECHARGE,        // Charging factor: Should recharge under extreme temperature
  BMT_CHR_FACTOR_HOLD,               // Charging factor: Charging hold
  BMT_CHR_FACTOR_CHR_BATT_STATE,     // Charging factor: charging state: PRE, FAST(CC), TOPOFF(CV), FULL ...

  BMT_CHR_FACTOR_MAX
}bmt_chr_fac_enum;

typedef struct
{

  // Driver init
  // Called at drv init phase
  void (*drv_init)(void);

  // Called at pmic adpt layer init phase
  // The phase what scheduler is running(BMT task is created)
  void (*enable_intr)(void);

  // Control charge enable/disable
  // Called at any time, any context
  kal_bool (*charge_enable)(kal_bool enable);

  // The unit is in mA ==> 1000 means 1A
  // Called at any time, any context
  // a most close, but not exceeded charge current will be selected
  // 500mA means can NOT large than 500mA, but most close to 500mA
  kal_bool (*set_charge_current)(kal_int32 charge_current);

  // Whether the external charger can measure the passed-in charging factor
  bmt_chr_fac_measure_support_enum (*get_chr_fac_measure_support)(bmt_chr_fac_enum chr_fac);

  // Whether the external charger can check the passed-in charging factor
  bmt_chr_fac_check_support_enum (*get_chr_fac_check_support)(bmt_chr_fac_enum chr_fac);

  // Pass information to charger device
  // Charger device can calculate the charger status through the passed-in info
  void (*check_chr_status)(BATPHYStruct *pBatPhysStat);

  // Charger return calculated charger status
  // Usually, charger device should keep the chr status before reset_chr_status() is called
  // The return kal_uint32 is union of all charging factors status
  kal_uint32 (*get_chr_status)(void);

  // The return unit is uV ==> 1000000 means 1.0V
  // The passed-in parameter is the information measured by HOST,
  // ext charger driver need this info to calculate
  kal_int32 (*get_vbat)(BATPHYStruct *pBatPhysStat);

  // The return unit is uA ==> 1000000 means 1A
  // The passed-in parameter is the information measured by HOST,
  // ext charger driver need this info to calculate
  kal_int32 (*get_isense)(BATPHYStruct *pBatPhysStat);

  // The return unit is uV ==> 1000000 means 1.0V
  // The passed-in parameter is the information measured by HOST,
  // ext charger driver need this info to calculate
  kal_int32 (*get_vcharger)(BATPHYStruct *pBatPhysStat);

  // Return the calculated NTC value of battery temperature
  // The passed-in parameter is the information measured by HOST,
  // ext charger driver need this info to calculate
  kal_int32 (*get_bat_temp)(BATPHYStruct *pBatPhysStat);

  // Return if charge full
  // The unit is vbat is uV ==> 1000000 means 1.0V
  // Return KAL_TRUE: Charge full
  // Return KAL_FALSE: Not charge full
  kal_bool (*get_charge_full)(kal_int32 vbat);

  // Return if it's under extreme temperature
  // Return KAL_TRUE: It's under extreme temperature
  // Return KAL_FALSE: It's NOT under extreme temperature
  kal_bool (*get_charge_under_extremetmp)(kal_int32 battmp);

  // Return if charge full when under extreme temperature
  // The unit is vbat is uV ==> 1000000 means 1.0V
  // Return KAL_TRUE: Charge full
  // Return KAL_FALSE: Not charge full
  kal_bool (*get_charge_extremetmp_full)(kal_int32 vbat);

  // Return if charge should recharge when under extreme temperature
  // The unit is vbat is uV ==> 1000000 means 1.0V
  // Return KAL_TRUE: Should recharge
  // Return KAL_FALSE: Should NT recharge
  kal_bool (*get_charge_extremetmp_recharge)(kal_int32 vbat);

  // Return KAL_TRUE: Need to hold charging
  // Return KAL_FALSE: Do NOT need to hold charging
  // The condition to hold charging: Talking mode ...
  kal_bool (*get_charge_hold)(BATPHYStruct *pBatPhysStat);

  // Whether the external charger can handle the specific charging battery state
  bmt_chr_fac_check_support_enum(*get_chr_batt_state_transit_support)(kal_uint32 curr_chr_batt_state);

  // Perform charging battery state transit
  // curr_chr_batt_state: Current state
  // chr_on: Current CHR_EN state
  void (*chr_batt_state_transit)(kal_uint32 curr_chr_batt_state, kal_bool chr_en);

  // Get current charging battery state PRE, FAST(CC), TOPOFF(CV), FULL, ...
  kal_uint32 (*get_curr_chr_batt_state)(BATPHYStruct *pBatPhysStat);

  // Get custom charge current according to specific charger
  kal_uint32 (*get_specific_chr_current)(bmt_charger_type charger);

  // Whether the vbat is higher than specific full check vaule or not
  // Return KAL_TRUE: higher than specific full voltage
  // Return KAL_FALSE: lower than specific full voltage
  kal_bool (*get_vbat_specific_full_voltage_state)(kal_int32 vbat); //__DRV_BMT_CHARGING_COMPLETE_MSG__

}bmt_ext_charger;

// External charger custom table V1.0
typedef struct{
  // Control enable/disable charger
  void (*charge_enable)(kal_bool enable);

  // Set charge current
  // The unit is mA ==> 1000 means 1A
  void (*charge_current)(kal_int32 current);

  // Return KAL_TRUE: Charger think battery is full
  // Return KAL_FALSE: Charger think battery is NOT full
  kal_bool (*charge_full_ind)(kal_int32 vbat);

  // Return KAL_TRUE: Charger thing it's under extreme temperature
  // Return KAL_FALSE: Charger thing it's NOT under extreme temperature
  kal_bool (*charge_under_extremetmp_ind)(kal_int32 battmp);

  // Return KAL_TRUE: Charger think battery is full if it's under extreme temperature
  // Return KAL_FALSE: Charger think battery is NOT if it's full under extreme temperature
  kal_bool (*charge_extremetmp_full_ind)(kal_int32 vbat);

  // Return KAL_TRUE: Charger think battery should be recharged if it's under extreme temperature
  // Return KAL_FALSE: Charger think battery should NOT be recharged if it's under extreme temperature
  kal_bool (*charge_extremetmp_recharge_ind)(kal_int32 vbat);

  // Number of charge current level (Ex: 100mA, 150mA, 500mA ...)
  kal_uint32 charge_current_num;

  // The current must be listed from largest to smallest
  // Ex: 0: 500mA; 1: 250mA; 2: 100mA ...
  kal_uint32 *charge_current_table;

  // Return the custom charge current for specific charger type, the unit is mA
  kal_uint32 (*get_custom_charge_current)(bmt_charger_type charger);

  // Whether the charge source is good
  // Return KAL_TRUE: Charge source is good
  // Return KAL_FALSE: Charge source is NOT good
  kal_bool (*charge_source_good)(void);

  // Whether the vbat is higher than specific full check vaule or not
  // Return KAL_TRUE: higher than specific full voltage
  // Return KAL_FALSE: lower than specific full voltage
  kal_bool (*vbat_specific_full_check_voltage)(kal_int32 vbat); //__DRV_BMT_CHARGING_COMPLETE_MSG__

}bmt_ext_charger_custom_config;


// For external charger mechanism integration


// For external charger detection integration
typedef struct
{
  // This API report charger in/out and AC or USB type together
  // This API may be called at anytime
  // Ex: Before scheduler is running (Boot init phase)
  //     Called at boot time (No scheduler is running)
  //     Called in HISR (Drv_HISR and system HISR)
  //     Called in Task
  charger_usb_present_enum (*det_charger_present)(void);

  // This API is for PWIC to register HISR handler for charger
  // PWIC will use det_charger_present() to determine whether it is in/out
  void (*reg_chr_hisr)(void (chr_hisr_callback)(void));

  // This API is for PWIC to register HISR handler for usb
  // PWIC will use det_charger_present() to determine whether it is in/out
  void (*reg_usb_hisr)(void (usb_hisr_callback)(void));

  // This API is to set S/W debounce time for charger cable
  // The uint of deb_time is in 10ms (GPT tick)
  void (*set_chr_deb_time)(kal_uint32 deb_time);

  // This API is to set S/W debounce time for usb cable
  // The uint of deb_time is in 10ms (GPT tick)
  void (*set_usb_deb_time)(kal_uint32 deb_time);

  // This API is to report whether USB detection is supported or NOT
  kal_bool (*support_usb_det)(void);

  // Init the external charger detection mechanism
  // The API is called at boot phase
  // After this call, we should be able to call det_charger_present()
  // Provider need to guarantee this
  void (*drv_init)(void);

  // The API is called at pmic adpt layer init phase
  void (*enable_intr)(void);

}bmt_ext_charger_det;

typedef enum
{
  EXT_CABLE_PATH_CHARGER,
  EXT_CABLE_PATH_STD_USB,
  EXT_CABLE_PATH_HIGH_CURRENT_USB,
  EXT_CABLE_PATH_UART,
  EXT_CABLE_PATH_EARPHONE,
  EXT_CABLE_PATH_TV_OUT,
  EXT_CABLE_PATH_USB_OTG,
  EXT_CABLE_PATH_FAC_UART,
  EXT_CABLE_PATH_FAC_USB,
  EXT_CABLE_PATH_CS_CHARGER,  // Customer specific charger
  EXT_CABLE_PATH_MAX
}ext_cable_path_enum;

typedef struct
{
  // Factory mode API
  // Force switch external cable to specific path for test
  void (*set_path)(ext_cable_path_enum path);

  // Factory mode API
  // Return current external cable path
  ext_cable_path_enum (*get_curr_path)(void);

  // ASSERT mode API
  // Called when system enter ASSERT, 
  // the ext cable mechanism should switch cable path for memory dump
  void (*ext_cable_force_set_path)(ext_cable_path_enum path);

  // API for specific workaround: Turn on/off ext cable path
  void (*ext_cable_WA_set_path)(ext_cable_path_enum path, kal_bool on);

}ext_cable_det_fac_if;


// For external charger detection integration

extern kal_uint8  bmt_bmtid_adc_handle[BMT_ADC_MAX_CHANNEL_TOTAL];
extern kal_uint8  bmt_adc_handle;

// MoDIS parser skip start
// The following APIs are impmemented in custom folder, which will be inclucded in MoDIS
/*usb charge*/
extern kal_bool bmt_support_usb_charge(void);
extern kal_int32 bmt_get_chr_usb_detect_volt(void);
// MoDIS parser skip end

// MoDIS parser skip start
/*charing parameters*/
// MoDIS parser skip end

#if defined(__GENERAL_EXTERNAL_CHARGER__)
extern bmt_ext_charger *ext_charger; // Variable in pwic.c
extern bmt_ext_charger *bmt_get_ext_charger(void);
extern bmt_ext_charger_custom_config *bmt_ext_charger_get_custom_config(void);
#endif // #if defined(__GENERAL_EXTERNAL_CHARGER__)

extern ext_cable_det_fac_if *custom_get_ext_cable_fac(void);

#if defined(__DRV_EXT_CHARGER_DETECTION__)
extern bmt_ext_charger_det *ext_charger_det;
extern bmt_ext_charger_det *bmt_custom_get_ext_charger_det(void);
#endif // #if defined(__DRV_EXT_CHARGER_DETECTION__)

extern kal_uint8 BMT_MAX_CHANNEL;      // The ADC channel number in BMT (Used for charging factor monitoring)
#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
extern chr_usb_detect_struct chr_usb_detect;
#endif
extern BMTStruct BMT;

#if defined(DRV_ADC_CALIBRATION_EFUSE)
extern kal_bool bmt_read_calibration_data(ADC_CALIDATA *adc_cali);
#endif //#if defined(DRV_ADC_CALIBRATION_EFUSE)

extern void BMT_VbatInHISR(void);
extern kal_bool bmt_is_bat_on(void);

extern kal_bool BMT_ObtainBMTPHYSTAT(BATPHYStruct *BATPHYS);
extern void bmt_chr_force_enable(kal_bool enable);
extern kal_bool bmt_is_chr_valid(void);
extern kal_bool bmt_get_chr_cv_det(void);
#endif // End of #ifndef _BMT_H

