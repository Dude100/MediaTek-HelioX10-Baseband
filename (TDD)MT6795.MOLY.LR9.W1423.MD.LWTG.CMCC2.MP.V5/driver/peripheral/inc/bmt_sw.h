/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *    bmt_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for BMT driver and adaption.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _BMT_SW_H
#define _BMT_SW_H

#include "drv_features.h"
#include "chr_parameter.h"
#include "dcl.h"

// ============================================================ //
// Definitions for BMT Module Only
// ============================================================ //
#if defined(__EVB__)
#if !defined(DRV_MISC_ADC_FIXED_VBAT_WA)
#define DRV_MISC_ADC_FIXED_VBAT_WA
#endif
#endif

#if(CHR_BATTERY_TYPE == LI_ION_BATTERY)
#define CHR_WITH_LI_ION_BATTERY
#else
#define CHR_WITH_NI_MH_BATTERY
#endif

/* Battery State */
#define CHR_PRE								0
#define CHR_FAST							1
#define CHR_TOPOFF                       	2
#define CHR_BATFULL                      	3
#define CHR_ERROR                        	4
#define CHR_HOLD                         	5
#define CHR_POSTFULL                     	6
#define CHR_PRE_FULL_CHECK               	7

/* TON, TOFF */
#define CHRTON                           	0
#define CHRTOFF                          	1

/* Safety Timer Configuration */
#define BMT_SAFETY_TIMER_ON  			  	1
#define BMT_SAFETY_TIMER_OFF				0 

/* Counts of ADC Measurement */
#define BMT_EVALUATE_VALUE					10

/* __TC01__ Configuration */
#if defined(__TC01__)
#define __DRV_BMT_ALWAYS_PULSE_CHARGING__ // TC01 request pulse charging in CV
#define __DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__
#define __DRV_BMT_DISABLE_STOP_TIMER__
#define __DRV_BMT_CHARGING_COMPLETE_MSG__
#define __DRV_BMT_REPORT_VBAT_IN_BOOTING__

#if ((!defined(L4_NOT_PRESENT)) && (!defined(__MAUI_BASIC__)) )
#define __DRV_BATTERY_EXIST_DETECTION__
// #define BATTERY_EXIST_DETECTION_SW_POLLING_PERIOD_IN_TICK     (3250)  // 15 sec = (1000/4.615) * 15
#endif // #if ( (!defined(L4_NOT_PRESENT)) && (!defined(__MAUI_BASIC__)) )

#define __BMT_CHARGE_GUARD_TIME__
	#define BMT_TOTAL_CHARGE_TIME	(6 * 60) // 6 hours = 360 mins
   	#ifdef __BMT_CHARGE_GUARD_TIME__
    	#define BMT_CHARGE_GUARD_TIME_PERIOD	(2 * 60 + 50) // 2 hours and 50 mins = 170 mins  
      	#if (BMT_CHARGE_GUARD_TIME_PERIOD > BMT_TOTAL_CHARGE_TIME)
      	#error "[BMT]Error!! BMT_TOTAL_CHARGE_TIME should >= BMT_CHARGE_GUARD_TIME_PERIOD!!"
     	#endif
   	#endif // __BMT_CHARGE_GUARD_TIME__
   	
#if defined(__GENERAL_EXTERNAL_CHARGER__)

// Debug mode, take Fac.UART cable as charger
//#define DEBUG_TREAT_FAC_UART_CABLE_AS_CHARGER

#endif // #if defined(__GENERAL_EXTERNAL_CHARGER__)
   	
   	
#else // Else of #if defined(__TC01__)

#define __BMT_PAUSE_CHARGE_STOP_SAFETY_TIMER__

#if defined(__DRV_BMT_BATTERY_LARGER_1600MA__)
   	#define BMT_TOTAL_CHARGE_TIME	(12 * 60) // 12 hours = 720 mins
#elif defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)
   	#define BMT_TOTAL_CHARGE_TIME	(8 * 60) // 8 hours = 480 mins
#else
   	#define BMT_TOTAL_CHARGE_TIME	(6 * 60) // 6 hours = 360 mins
#endif //#if defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)

#endif // End of #if defined(__TC01__)

// ============================================================ //
// Useless Definitions
// ============================================================ //
/* Power key position */
#if 0
#ifndef CANNON
/* under construction !*/
#else
/* under construction !*/
#endif
#endif 

// ============================================================ //
// Data structures for BMT Module Only
// ============================================================ //
typedef void (* CHR_FUNC)(void);

typedef struct {
   kal_uint8    TON;/*sec*/
   kal_uint8    TOFF;/*sec*/
} CHRTStruct;

/* Customize Charging Parameters */
typedef struct {
   kal_int32 TYPICAL_LI_BATTYPE;
   kal_int32 TYPICAL_NI_BATTYPE;
   kal_uint32 BATT_EXIST_ADC_THRESHOLD;
   kal_int32 VCHARGER_HIGH;
   kal_int32 VCHARGER_LOW;
   kal_int32 BATTMP_MINUS_40C;
   kal_int32 BATTMP_0C;
   kal_int32 BATTMP_45C;
   kal_int32 ICHARGE_ON_HIGH;
   kal_int32 ICHARGE_ON_LOW;
   kal_int32 ICHARGE_OFF_HIGH;

   kal_int32 V_PRE2FAST_THRES;   
   kal_int32 FAST_ICHARGE_HIGHLEVEL; /* 600ma,for table search */
   kal_int32 FAST_ICHARGE_LOWLEVEL;  /* 400ma,for table search */
   kal_int32 I_TOPOFF2FAST_THRES; /* 250ma,TOPOFF->FAST */
   kal_int32 I_TOPOFF2FULL_THRES;  /* 120ma,TOPOFF->BATFULL */
   
#if defined(CHR_WITH_LI_ION_BATTERY)   
   kal_int32 V_FAST2TOPOFF_THRES;
   kal_int32 V_FULL2FAST_THRES; /* BATFULL->FAST */
   kal_int32 MAX_VBAT_LI;
   kal_int32 V_PROTECT_HIGH_LI;
   kal_int32 V_PROTECT_LOW_LI;
#endif

#if defined(CHR_WITH_NI_MH_BATTERY)
   kal_int32 V_TEMP_FAST2FULL_THRES_NI; /* 50oC,FAST->BATFULL */
   kal_int32 V_FULL2FAST_THRES_NI;
   kal_int32 MAX_VBAT_NI;
#endif

   /*Time delay*/
   /* PRE CHARGE ,search table*/
   /*TON = 3s,TOFF=2s*/
   kal_uint32 PRE_TON;
   kal_uint32 PRE_TOFF;

/* FAST CHARGE ,search table*/
/*TON = 3s,TOFF=0s*/
   kal_uint32 TOPOFF_TON;
   kal_uint32 TOPOFF_TOFF;
#if defined(DRV_BMT_PULSE_CHARGING)
   kal_uint32 BATPOSTFULL_TWAIT_LI;
   kal_uint32 BATPOSTFULL_TON_LI;
   kal_uint32 BATPOSTFULL_TOFF_LI;
#endif //#if defined(DRV_BMT_PULSE_CHARGING)

#if defined(CHR_WITH_LI_ION_BATTERY)   
   kal_uint32 BATFULL_TON_LI;  /*unit : second*/
   kal_uint32 BATFULL_TOFF_LI;
#else   
   kal_uint32 BATFULL_TON_NI;  /*unit : second*/
   kal_uint32 BATFULL_TOFF_NI;
#endif   
   kal_uint32 BATFULL_TOFF;
   kal_uint32 BATHOLD_OFF;   
   kal_uint32 bmt_measure_discard_time; /*24 ticks*/

   kal_int32 CurrOffset[3];
/*GPIO control*/   
#ifndef  __CUST_NEW__
   kal_uint8 GPIO_CHRCTRL;
   kal_uint8 GPIO_BATDET;
   kal_uint8 GPIO_VIBRATOR;
#endif  /* __CUST_NEW__ */   
   kal_uint8 TONOFFTABLE[6][2];
   kal_bool	 bmt_check_battery;   
   kal_bool	 bmt_check_charger;  
   kal_bool  bmt_check_temp;
   kal_bool  bmt_battery_type;   
} bmt_customized_struct;

// ============================================================ //
// Useless Data structures
// ============================================================ //
typedef struct{
	void (*measure_func)(kal_uint8);
	void (*read_back)(kal_uint8); 
}BMT_MeasFuncs;

// ============================================================ //
// Enumeration for BMT Module Only
// ============================================================ //
typedef enum{	
	USB_IN_STATE,
	USB100_STATE,
	USB500_STATE,
	USB_OUT_STATE,
	AC_IN_STATE,
	AC_OUT_STATE,
	USB_INIT_STATE
}bmt_usb_state_enum;

typedef enum{
	BMT_AC_IN,
	BMT_USB_IN	
}bmt_usb_charger_enum;

// ============================================================ //
// Useless Enumeration
// ============================================================ //
// Charging status enum
typedef enum
{
  BMT_CHR_STATUS_NONE                        = 0x00000000,
  BMT_CHR_STATUS_CHARGE_CURRENT_TOO_HIGH     = 0x00000001,  // BIT00
  BMT_CHR_STATUS_CHARGE_CURRENT_TOO_LOW      = 0x00000002,  // BIT01
  BMT_CHR_STATUS_DISCHARGE_CURRENT_TOO_HIGH  = 0x00000004,  // BIT02
  BMT_CHR_STATUS_CHARGE_VBATTEMP_TOO_HIGH    = 0x00000008,  // BIT03
  BMT_CHR_STATUS_CHARGE_VBATTEMP_TOO_LOW     = 0x00000010,  // BIT04
  BMT_CHR_STATUS_CHARGE_VBAT_TOO_HIGH        = 0x00000020,  // BIT05
  BMT_CHR_STATUS_CHARGE_VCHARGER_TOO_HIGH    = 0x00000040,  // BIT06
  BMT_CHR_STATUS_CHARGE_VCHARGER_TOO_LOW     = 0x00000080,  // BIT07
  BMT_CHR_STATUS_CHARGE_FULL                 = 0x00000100,  // BIT08
  BMT_CHR_STATUS_BATT_BAD_CONTACT            = 0x00000200,  // BIT09
  BMT_CHR_STATUS_TALK_HOLD                   = 0x00000400,  // BIT10

  BMT_CHR_STATUS_MAX                         = 0x10000000   // BIT31
}bmt_chr_status_enum;


// ============================================================
// Exported APIs (Only for BMT Module)

/* For ADC schedule & measure*/
extern kal_int32 adc_measureVoltage(kal_uint8 chann, double *adc_value);

#ifdef __BMT_CHARGE_GUARD_TIME__
extern void bmt_set_guardtimer(kal_uint32 tick);
extern void bmt_stop_guardtimer(void);
#endif // #ifdef __BMT_CHARGE_GUARD_TIME__
#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)
extern void bmt_set_estimativetimer(kal_uint32 tick);
extern void bmt_stop_estimativetimer(void);
#endif // #if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)

extern void bmt_stop_stoptimer(void);
extern void BMT_Charge(kal_bool data);  /* in drv directory */
extern void bmt_initialize(void);
extern void bmt_set_chr_current(void);
extern void bmt_Modify_PowerOn_Type(kal_uint8 power_type);
extern void bmt_find_and_set_the_nearest_current(PMU_CHR_CURRENT_ENUM SetCurrent);
extern void bmt_find_and_set_the_nearest_charger_high_voltage(DCL_UINT32 voltage);
extern kal_uint8 bmt_Get_PowerOn_Type(void);
extern kal_bool bmt_frequently_check_on_state(void);
#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
extern kal_bool bmt_frequently_check_off_state(void);
#endif
extern kal_bool BMT_VBatVoltageIsFull(kal_uint32 voltage);
extern kal_bool BMT_Current_Voltage(DCL_ADC_CHANNEL_TYPE_ENUM ch, kal_uint32 *voltage, double *adc_value);
extern kal_bool bmt_check_if_bat_on(void);
extern bmt_usb_charger_enum bmt_IsUSBorCharger(void);

#if defined(__DRV_BATTERY_EXIST_DETECTION__)
extern kal_uint32 bmt_get_batt_exist_det_period(void);
#endif // #if defined(__DRV_BATTERY_EXIST_DETECTION__)
extern DCL_STATUS bmt_get_customized_para(BMT_CTRL_GET_CUSTOMIZED_PARA_T *GetCustomizedPara);

// ============================================================
// External Variables
extern bmt_customized_struct *bmt_charging_para; 
extern bmt_customized_struct bmt_custom_chr_def;
#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
extern kal_bool SW_Workaround_Flag;
extern kal_bool Manual_Disable_Charge_Flag;
extern kal_uint8 HW_Plug_Status;
#endif

// ============================================================
// MoDIS parser skip start
// Exported functions, used by driver level functions

// MoDIS parser skip end

// ============================================================
// MoDIS parser skip start
// Unknown functions, maybe previous owner forgot to delete

// MoDIS parser skip end

#if !defined(DRV_BMT_OFF)

#else // !defined(DRV_BMT_OFF)

#endif // !defined(DRV_BMT_OFF)

#endif // End of #ifndef _BMT_SW_H

