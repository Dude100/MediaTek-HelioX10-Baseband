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

/*******************************************************************************
 * Filename:
 * ---------
 *   bmt_trc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is trace map definition for BMT.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _BMT_TRC_H
#define _BMT_TRC_H


#ifndef GEN_FOR_PC

   #ifndef _STACK_CONFIG_H
   #error "stack_config.h should be included before tst_config.h"
   #endif

#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */

// For RHR ADD Usage
#include "stack_config.h"
#include "kal_trace.h"

#ifndef _KAL_TRACE_H
   #error "kal_trace.h should be included before tst_trace.h"
#endif

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "bmt_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_BMT)

    TRC_MSG(BMT_CTRL_CHARGE_TRC,"BMT: BMT_CtrlCharge = %d.")
    TRC_MSG(BMT_CHARGING_ALREADY_ON_TRC,"BMT: Charging is already on")
    TRC_MSG(BMT_CALL_STATE_TRC,"BMT_CallState: callState = %d.")
    TRC_MSG(BMT_INVALID_CHARGER_TRC,"Invalid Charger.")
    TRC_MSG(BMT_ICHARGE_OVER_TRC,"ICHARGE too high.")
    TRC_MSG(BMT_ICHARGE_LOW_TRC,"ICHARGE too low.")
    TRC_MSG(BMT_VBAT_OVER_TRC,"VBAT too high.")
    TRC_MSG(BMT_VTEMP_OVER_TRC,"BATTMP too high.")
    TRC_MSG(BMT_VTEMP_LOW_TRC,"BATTMP too low.")
    TRC_MSG(BMT_CHR_HOLD_TRC,"CHR_HOLD.")
    TRC_MSG(BMT_VBAT_TRC,"VBAT = %d.")
    TRC_MSG(BMT_VBATTMP_TRC,"VBATTMP = %d.")
    TRC_MSG(BMT_BATTMP_TRC,"BATTMP = %d.")
    TRC_MSG(BMT_ICHARGE_TRC,"ICHARGE = %d.")   
    TRC_MSG(BMT_VSENSE_TRC,"VSENSE = %d.")
    TRC_MSG(BMT_VSENSE_VBAT_OFFSET_TRC,"VSENSE - VBAT(OFFSET) = %d.")   
    TRC_MSG(BMT_VCHARGER_TRC,"VCHARGER = %d.")   
    TRC_MSG(BMT_CHRPRE_ON_STATE_TRC,"STATE = BMT_CHRPRE_ON.")
    TRC_MSG(BMT_CHRPRE_OFF_STATE_TRC,"STATE = BMT_CHRPRE_OFF.")
    TRC_MSG(BMT_FAST_CHARGE_CHANGE_TRC,"Chage state to FAST_CHARGE.")
    TRC_MSG(BMT_FAST_ON_STATE_TRC,"STATE = BMT_CHRFAST_ON.")
    TRC_MSG(BMT_FAST_OFF_STATE_TRC,"STATE = BMT_CHRFAST_OFF.")
    TRC_MSG(BMT_PMU_PULSECHR_TRC,"STATE = BMT_PMU_PULSECHR.")
    TRC_MSG(BMT_CHR_POSTFULL_CHANGE_TRC,"Chage state to CHR_POSTFULL.")
    TRC_MSG(BMT_CHR_BATFULL_CHANGE_TRC,"Chage state to CHR_BATFULL.")
    TRC_MSG(BMT_CHR_UNDER_EXTREMETMP_TRC,"Now it's under extreme temperature.")
    TRC_MSG(BMT_CHR_EXTREMETMP_BATFULL_CHANGE_TRC,"Chage state to CHR_BATFULL because of extreme temperature.")
    TRC_MSG(BMT_CHR_EXTREMETMP_CHARGE_RECHARGE_TRC,"Restart charging because of the voltage drop under extreme temperature.")
    TRC_MSG(BMT_CHR_TOPOFF_CHANGE_TRC,"Chage state to CHR_TOPOFF.")
    TRC_MSG(BMT_CHRTOPOFF_ON_STATE_TRC,"STATE = BMT_CHRTOPOFF_ON.")
    TRC_MSG(BMT_CHR_FAST_CHANGE_TRC,"Chage state to CHR_FAST.")   
    TRC_MSG(BMT_CHRTOPOFF_OFF_STATE_TRC,"STATE = BMT_CHRTOPOFF_OFF.")
    TRC_MSG(BMT_CHRBATPOSTFULL_ON_STATE_TRC,"STATE = CHR_POSTFULL_ON.")
    TRC_MSG(BMT_CHRBATPOSTFULL_OFF_STATE_TRC,"STATE = CHR_POSTFULL_OFF.")
    TRC_MSG(BMT_CHRBATFULL_ON_STATE_TRC,"STATE = BMT_CHRBATFULL_ON.")
    TRC_MSG(BMT_CHRBATFULL_OFF_STATE_TRC,"STATE = BMT_CHRBATFULL_OFF.")
    TRC_MSG(BMT_CHRHOLD_STATE_TRC,"STATE = BMT_CHRHOLD.")
    TRC_MSG(BMT_HIGH_BAT_FULL_TRC,"High Battery Full.")
    TRC_MSG(BMT_MEASURE_STOP_TRC,"BMT_MeasureStop.")
    TRC_MSG(BMT_PWRON_TRC,"BMT.PWRon = %d.")
    TRC_MSG(BMT_TASK_MAIN_TRC,"=====================BMT_task_main=====================.")
    TRC_MSG(BMT_CHARGE_GUARD_TIMER_EXPIRE_TRC,"Charging guard timer(%d minutes) expired.")  
    TRC_MSG(BMT_SAFETY_TIMER_EXPIRE_TRC,"Safety timer(%d minutes) expired.")  
    TRC_MSG(BMT_SAFETY_TIMER_START_TRC,"Safety timer(%d minutes) starts.")  
    TRC_MSG(BMT_SAFETY_AND_GUARD_TIMER_START_TRC,"Safety timer(%d minutes) and charging guard timer (%d minutes) starts.")
    TRC_MSG(BMT_SAFETY_TIMER_STOP_TRC,"Safety timer(%d minutes) stops.")  
    TRC_MSG(BMT_STOP_TIMER_EXPIRE_TRC,"Stop timer(30 min) expired.")  
    TRC_MSG(BMT_STOP_TIMER_START_TRC,"Stop timer(30 min) starts.")  
    TRC_MSG(BMT_STOP_TIMER_STOP_TRC,"Stop timer(30 min) stops.")  	
    TRC_MSG(BMT_ERROR_CHECK_TRC,"BMT_CHRERRORCHECK.")
    TRC_MSG(BMT_ULC_SW_PLUGOUT_TRC,"Ultra Low Cost S/W Plug Out Detected.")  	
    TRC_MSG(BMT_OBTAIN_PHY_STAT_TRC,"BMT_ObtainBMTPHYSTAT.")
	TRC_MSG(BMT_CHARGE_ENABLE_TRC,"BMT_Charge = %d.")
	
	// Error Check
	TRC_MSG(BMT_PMU_DO_NOT_SUPPORT_TRC,"PMU does not support this cmds = %d.")
	TRC_MSG(BMT_ERRORCHECK_AT_CHARGE_ON_TRC,"Error Check at Charge On.")
	TRC_MSG(BMT_ERRORCHECK_AT_CHARGE_OFF_TRC,"Error Check at Charge Off.")	
	TRC_MSG(BMT_ERRORCHECK_ON_COUNT_TRC,"Current Error Check On Count = %d.")
	TRC_MSG(BMT_ERRORCHECK_OFF_COUNT_TRC,"Current Error Check Off Count = %d.")
	TRC_MSG(BMT_SW_WORKAROUND_FLAG_TRUE_TRC,"SW_Workaround_Flag = TRUE.")
	TRC_MSG(BMT_SW_WORKAROUND_FLAG_FALSE_TRC,"SW_Workaround_Flag = FALSE.")
	TRC_MSG(BMT_INSIDE_SW_WORKAROUND_RANGE_TRC,"Inside SW Workaround Range.")
	TRC_MSG(BMT_OUTSIDE_SW_WORKAROUND_RANGE_TRC,"Outside SW Workaround Range.")
	TRC_MSG(BMT_MISSING_HW_PLUG_OUT_TRC,"Missing HW Plug Out.")
	TRC_MSG(BMT_SW_PLUG_OUT_TRC,"SW Plug Out.")
	TRC_MSG(BMT_PLUG_OUT_FALSE_ALARM_TRC,"Disable charge but hasn't detect plug out -> Plug out false alarm.")
	TRC_MSG(BMT_ENABLE_CHARGE_AT_CHARGE_ON_TRC,"Enable Charge @ ON State.")
	TRC_MSG(BMT_DISABLE_CHARGE_AT_CHARGE_ON_TRC,"Disable Charge @ ON State.")
	TRC_MSG(BMT_POSSIBLE_PLUG_OUT_TRC,"Possible plug out, need disable charge if we are at charge on state.")
	TRC_MSG(BMT_LOW_CHARGE_CURRENT_AT_CHARGE_OFF_TRC,"Low charge current is due to charge off state.")
	TRC_MSG(BMT_SW_POLLING_CHARGER_OV_TRC,"Charger OV by SW polling.")
		
	// Charge Current Settings
	TRC_MSG(BMT_SET_CUSTOMIZED_CURRENT_TRC,"bmt_set_customized_current.")
	TRC_MSG(BMT_SET_AC_CHARGE_CURRENT_TRC,"Set AC Charge Current.")
	TRC_MSG(BMT_SET_USB_CHARGE_CURRENT_TRC,"Set USB Charge Current.")
	TRC_MSG(BMT_FIND_AND_SET_THE_NEAREST_CURRENT_TRC,"The nearest charge current = %d.")
	TRC_MSG(BMT_CHARGE_CURRENT_AND_LEVEL_TRC,"Charge current = %d, Charge Level = %d.")
	TRC_MSG(BMT_TOTAL_CHARGE_CURRENT_LEVEL_TRC,"Total charge current level = %d.")	
	TRC_MSG(BMT_MIN_CHARGE_CURRENT_TRC,"Min charge current = %d.")		
	TRC_MSG(BMT_MAX_CHARGE_CURRENT_TRC,"Max charge current = %d.")	
	TRC_MSG(BMT_CURRENT_CHARGE_CURRENT_TRC,"Current charge current = %d.")
	
	TRC_MSG(BMT_PHY_CHECK_OVER_CHARGER_COUNT_TRC,"over_charger_count = %d.")
	TRC_MSG(BMT_PHY_CHECK_OVER_CURRENT_COUNT_TRC,"over_current_count = %d.")
	TRC_MSG(BMT_PHY_CHECK_LOW_CURRENT_COUNT_TRC, "low_current_count = %d.")
	TRC_MSG(BMT_PHY_CHECK_LOW_TRMPER_COUNT_TRC,  "low_temper_count = %d.")
	TRC_MSG(BMT_PHY_CHECK_OVER_TEMPER_COUNT_TRC, "over_temper_count = %d.")

	// ADC measurement
	TRC_MSG(BMT_ADC_MEASURE_WARNING_TRC,"ADC measure warning: Phy id: %d, pre measured volt: %d, curr measured volt: %d")
	TRC_MSG(BMT_ILLEGAL_PHY_ADC_CHANNEL_TRC,"Warning, ADC phy id is illegal, return value 0 only")
	TRC_MSG(BMT_ADC_CALIBRATION_FAIL_TRC,"ADC Calinration FAIL, when charge off, ICharger = %d")
	TRC_MSG(BMT_ADC_NO_CALIBRATION_TRC,"Warning, ADC using Default slope = %d and offset = %d ")
	TRC_MSG(BMT_ADC_CALLBACK_INFO_TRC,"ADC phyid=%d, period=%d, evlcount=%d")
	TRC_MSG(BMT_ADC_GET_ADC_INFO_TRC,"status=%d, channel=%d")
	
	// Cable handler
	TRC_MSG(BMT_CABLE_IN_TRC,"Cable in")
	TRC_MSG(BMT_AC_IN_TRC,"AC in") 
	TRC_MSG(BMT_NON_AC_IN_TRC,"Non Standard AC in") 
	TRC_MSG(BMT_CABLE_OUT_TRC,"Cable out")
	TRC_MSG(BMT_INV_AC_IN_TRC,"INV AC in")
	TRC_MSG(BMT_AC_OUT_TRC,"AC out") 
	TRC_MSG(BMT_USB_IN_TRC,"USB in")
	TRC_MSG(BMT_USB_CHARGING_HOST_IN_TRC,"USB Charging host in")
	TRC_MSG(BMT_USB_IN_WAIT_500_TRC,"USB in and wait for 500")
	TRC_MSG(BMT_USB_OUT_TRC,"USB out")
	TRC_MSG(BMT_USB_100_TRC,"USB 100")
	TRC_MSG(BMT_USB_500_TRC,"USB 500")
	TRC_MSG(BMT_CHR_STATUS_CHARGE_IN_TRC,"Charge Status = bmt_chr_in")
	TRC_MSG(BMT_CHR_STATUS_CHARGE_OUT_TRC,"Charge Status = bmt_chr_out")
	TRC_MSG(BMT_USB_STATE_TRC,"Usb State = %d.")	
	TRC_MSG(BMT_HW_PLUG_OUT_INSIDE_SW_WORKAROUND_RANGE_TRC,"H/W plug out detected inside S/W workaround range -> return use S/W to check.")     

	// Charging indicator
	TRC_MSG(BMT_CHARGING_START_TRC,"Charging start")
	TRC_MSG(BMT_CHARGING_END_TRC,"Charging end")
	TRC_MSG(BMT_CHARGING_CURRENT_NOT_SUPPORTED_STOP_CHARGING_TRC,"Charging current NOT supported, stop charging")
	TRC_MSG(BMT_CHARGING_WDT_CLR_TRC,"Charging WDT clear")
	
	TRC_MSG(BMT_AC_IN_AND_START_CHARGE_TRC,"AC in and start charging")
	TRC_MSG(BMT_INV_AC_IN_AND_START_CHARGE_TRC,"Invalid AC in and start charging")
	TRC_MSG(BMT_USB_IN_AND_START_CHARGE_TRC,"USB in and start charging")
	TRC_MSG(BMT_USB_500_AND_START_CHARGE_TRC,"USB 500 waited and start charging")
	TRC_MSG(BMT_AC_OUT_AND_STOP_CHARGE_TRC,"AC out and stop charging")
	TRC_MSG(BMT_USB_OUT_AND_STOP_CHARGE_TRC,"USB out and stop charging")
	TRC_MSG(BMT_USB_500_OUT_AND_STOP_CHARGE_TRC,"USB 500 out and stop charging")
	TRC_MSG(BMT_USB_100_OUT_AND_STOP_CHARGE_TRC,"USB 100 out and stop charging")
	TRC_MSG(BMT_USB_100_OUT_TRC,"USB 100 out")
	TRC_MSG(BMT_AC_OUT_USB_STILL_IN_KEEP_CHARGING_TRC,"AC out, USB still in, keep charging")
	TRC_MSG(BMT_AC_OUT_USB_500_STILL_IN_KEEP_CHARGING_TRC,"AC out, USB 500 still in, keep charging")
	TRC_MSG(BMT_USB_OUT_AC_STILL_IN_KEEP_CHARGING_TRC,"USB out, AC still in, keep charging")
	TRC_MSG(BMT_USB_IN_AC_ALREAY_IN_TRC,"USB in, AC already in")
	TRC_MSG(BMT_USB_500_AC_ALREAY_IN_TRC,"USB 500 waited, AC already in")
	
	
	// BMT message
	TRC_MSG(BMT_MSG_TIMER_EXPIRE_TRC,"MSG_ID_TIMER_EXPIRY")
	TRC_MSG(BMT_MSG_CHARGER_TRC,"MSG_ID_BMT_CHARGER_IND")
	TRC_MSG(BMT_MSG_USB_B_OUT,"MSG_ID_USB_B_PLUGOUT_IND")
	TRC_MSG(BMT_MSG_USB_B_IN,"MSG_ID_USB_B_PLUGIN_IND")
	TRC_MSG(BMT_MSG_USB,"MSG_ID_BMT_USB_IND")
	
	TRC_MSG(BMT_MSG_ADC_ADD,"MSG_ID_BMT_ADC_ADD_ITEM_REQ")
	TRC_MSG(BMT_MSG_ADC_REMOVE,"MSG_ID_BMT_ADC_REMOVE_ITEM_REQ")
	TRC_MSG(BMT_MSG_ADC_PARAM,"MSG_ID_BMT_ADC_MODIFY_PARAMETERS_REQ")
	TRC_MSG(BMT_MSG_ADC_NVRAM_READ_CNF,"MSG_ID_NVRAM_READ_CNF")
	TRC_MSG(BMT_MSG_ADC_NVRAM_SLOPE_OFFSET,"MSG_ID_NVRAM_READ_CNF slope: %d offset: %d")
	
	TRC_MSG(BMT_MSG_ADC_EFUSE,"MSG_ID_EFUSE_READ")
	TRC_MSG(BMT_MSG_ADC_EFUSE_SLOPE_OFFSET,"MSG_ID_EFUSE_READ slope: %d  offset: %d")
	TRC_MSG(BMT_MSG_ADC_EFUSE_AB,"MSG_ID_EFUSE_READ EFUSE_A: %d  EFUSE_B: %d")
	TRC_MSG(BMT_MSG_ADC_EFUSE_ADC_SLOPE_OFFSET,"MSG_ID_EFUSE_READ_ADC slope: %d  offset: %d")
	TRC_MSG(BMT_MSG_ADC_EFUSE_ADC_CALIBRATION_SLOPE_OFFSET,"MSG_ID_EFUSE_READ_ADC slope%d: %d  offset%d: %d")
	TRC_MSG(BMT_MSG_BATT_ON_DET,"BMT_MSG_BATT_ON_DET Batt detection timer timeout, batt state: %d")
	TRC_MSG(BMT_MSG_BATT_OFF_BLOCK,"BMT_MSG_BATT_ON_DET Batt NOT on, block all BMT messages except TIMER EXPIRATION")
	
	
	// Ext cable handler
	TRC_MSG(BMT_MSG_EXT_CABLE_INTR_ENABLE,"Ext cable det: intr enable(%d)")
	TRC_MSG(BMT_MSG_EXT_CABLE_IN,"Ext cable det: Cable in")
	TRC_MSG(BMT_MSG_EXT_CABLE_OUT,"Ext cable det: Cable out")
	TRC_MSG(BMT_MSG_EXT_CABLE_DBG_1,"Ext cable det: Debug: reg1: %x")
	TRC_MSG(BMT_MSG_EXT_CABLE_DBG_2,"Ext cable det: Debug: reg1: %x, reg2: %x")
	TRC_MSG(BMT_MSG_EXT_CABLE_DBG_3,"Ext cable det: Debug: reg1: %x, reg2: %x, reg3")
	TRC_MSG(BMT_MSG_EXT_CABLE_DBG_4,"Ext cable det: Debug: reg1: %x, reg2: %x, reg3: %x, reg4: %x")
	TRC_MSG(BMT_MSG_EXT_CABLE_REPEATED_IN,"Ext cable det: Repeated cable in")
	TRC_MSG(BMT_MSG_EXT_CABLE_REPEATED_OUT,"Ext cable det: Repeated cable out")
	TRC_MSG(BMT_MSG_EXT_CABLE_USB_IN,"Ext cable det: USB cable in")
	TRC_MSG(BMT_MSG_EXT_CABLE_USB_OUT,"Ext cable det: USB cable out")
	TRC_MSG(BMT_MSG_EXT_CABLE_AC_IN,"Ext cable det: AC cable in")
	TRC_MSG(BMT_MSG_EXT_CABLE_AC_OUT,"Ext cable det: AC cable out")
	TRC_MSG(BMT_MSG_EXT_CABLE_LGTA_IN,"Ext cable det: LGTA cable in")
	TRC_MSG(BMT_MSG_EXT_CABLE_LGTA_OUT,"Ext cable det: LGTA cable out")
	TRC_MSG(BMT_MSG_EXT_CABLE_FAC_USB_IN,"Ext cable det: Factory USB cable in")
	TRC_MSG(BMT_MSG_EXT_CABLE_FAC_USB_OUT,"Ext cable det: Factory USB cable out")
	TRC_MSG(BMT_MSG_EXT_CABLE_FAC_UART_IN,"Ext cable det: Factory UART cable in")
	TRC_MSG(BMT_MSG_EXT_CABLE_FAC_UART_OUT,"Ext cable det: Factory UART cable out")
	TRC_MSG(BMT_MSG_EXT_CABLE_EARPHONE_IN,"Ext cable det: Earphone cable in")
	TRC_MSG(BMT_MSG_EXT_CABLE_EARPHONE_OUT,"Ext cable det: Earphone cable out")
	TRC_MSG(BMT_MSG_EXT_CABLE_KEY_PRESSED,"Ext cable det: Earphone key pressed")
	TRC_MSG(BMT_MSG_EXT_CABLE_KEY_RELEASED,"Ext cable det: Earphone key released")
	TRC_MSG(BMT_MSG_EXT_CABLE_VIDEO_IN,"Ext cable det: Video cable in")
	TRC_MSG(BMT_MSG_EXT_CABLE_VIDEO_OUT,"Ext cable det: Video cable out")
	TRC_MSG(BMT_MSG_EXT_CABLE_OTG_IN,"Ext cable det: OTG cable in")
	TRC_MSG(BMT_MSG_EXT_CABLE_OTG_OUT,"Ext cable det: OTG cable out")
	TRC_MSG(BMT_MSG_EXT_CABLE_UNKNOWN_IN,"Ext cable det: Unknown cable in")
	TRC_MSG(BMT_MSG_EXT_CABLE_UNKNOWN_OUT,"Ext cable det: Unknown cable out")
	TRC_MSG(BMT_MSG_EXT_CABLE_FAC_MODE,"Ext cable det: In FAC mode")
	TRC_MSG(BMT_MSG_EXT_CABLE_FAC_MODE_AC_IN,"Ext cable det: FAC mode AC in")
	TRC_MSG(BMT_MSG_EXT_CABLE_FAC_MODE_AC_OUT,"Ext cable det: FAC mode AC out")
	TRC_MSG(BMT_MSG_EXT_CABLE_REPEATED_IN_HISR,"Ext cable det: Repeated cable in HISR")
	TRC_MSG(BMT_MSG_EXT_CABLE_FAC_MODE_DIS_SLEEP,"Ext cable det: FAC mode disable sleep mode")
	TRC_MSG(BMT_MSG_EXT_CABLE_FAC_MODE_EN_SLEEP,"Ext cable det: FAC mode enable sleep mode")
	TRC_MSG(BMT_MSG_EXT_CABLE_EXT_AUDIO_WA_TURN_OFF_EARPHONE_REQ,"Ext cable det: Ext Audio IC WA: Turn off Earphone path request")
	TRC_MSG(BMT_MSG_EXT_CABLE_EXT_AUDIO_WA_TURN_ON_EARPHONE_REQ,"Ext cable det: Ext Audio IC WA: Turn on Earphone path request")
	TRC_MSG(BMT_MSG_EXT_CABLE_EXT_AUDIO_WA_TURN_OFF_EARPHONE,"Ext cable det: Ext Audio IC WA: Turn off earphone path")
	TRC_MSG(BMT_MSG_EXT_CABLE_EXT_AUDIO_WA_TURN_ON_EARPHONE,"Ext cable det: Ext Audio IC WA: Turn on earphone path")
	
	// High VCHG Adaptive Charge Current
	TRC_MSG(BMT_HIGH_VCHG_FIRST_TIME_VCHG_TRC,"First Time VCharge_AVG = %d.")
	TRC_MSG(BMT_HIGH_VCHG_FIRST_TIME_CHARGER_ON_TRC,"First Time Charge ON.")
	TRC_MSG(BMT_HIGH_VCHG_CURRENT_VCHG_TRC,"Cur_VCHG = %d.")
	TRC_MSG(BMT_HIGH_VCHG_AVERAGE_TRC,"Average VCHG = %d.")
	TRC_MSG(BMT_HIGH_VCHG_TOO_HIGH_TRC,"VCHARGER too high.")
	TRC_MSG(BMT_HIGH_VCHG_LOWEST_THRESHOLD_TRC,"bmt_high_vchg_para->HIGH_VCHG_TABLE[0][0] = %d.")
	TRC_MSG(BMT_HIGH_VCHG_UPPER_THRESHOLD_TRC,"Upper Threshold: HIGH_VCHG_TABLE[i][0] = %d.")
	TRC_MSG(BMT_HIGH_VCHG_LOWER_THRESHOLD_TRC,"Lower Threshold: HIGH_VCHG_TABLE[i-1][0] = %d.")
	TRC_MSG(BMT_HIGH_VCHG_TABLE_INDEX_TRC,"Table Index = %d.")
	TRC_MSG(BMT_HIGH_VCHG_SET_USB_CHARGE_CURRENT_TRC,"Set USB Current  = %d for CHARGER_PRESENT_NON")
	TRC_MSG(BMT_HIGH_VCHG_USB_IN_USE_CUSTOM_CHARGE_CURRENT_TRC,"USB In->Use Custom Setting in pmu_custom.c.")
	TRC_MSG(BMT_HIGH_VCHG_CHARGE_CURRENT_TRC,"Set High VCHG Charge Current = %d.")
	TRC_MSG(BMT_HIGH_VCHG_RUNTIME_APPLY_CHARGE_CURRENT_TRC,"Runtime Apply High VCHG Charge Current = %d.")
	TRC_MSG(BMT_HIGH_VCHG_MAX_RESET_TO_ZERO_TRC,"Cur_VCharge_MAX Reset to 0.")	
	TRC_MSG(BMT_HIGH_VCHG_CUR_VCHG_MAX_TRC,"Cur_VCharge_MAX = %d.")
	TRC_MSG(BMT_HIGH_VCHG_VCHG_DIFF_TRC,"Current VCharger - Pre_VCharge_AVG = %d.")
	TRC_MSG(BMT_HIGH_VCHG_TOTAL_VCHG_TRC,"Accumate Total VCharger = %d.")
	TRC_MSG(BMT_HIGH_VCHG_CS_VTH_TRC,"Register: Charge Current = %d.")
	
	
	TRC_MSG(BMT_HIGH_VCHG_PRE_CURRENT_LEVEL_TRC,"Previous Current Level = %d.")
	TRC_MSG(BMT_HIGH_VCHG_CUR_CURRENT_LEVEL_TRC,"Current Current Level = %d.")
	TRC_MSG(BMT_HIGH_VCHG_HYSTERESIS_UPPER_BOUND_TRC,"Hysteresis Upper Bound = %d.")
	TRC_MSG(BMT_HIGH_VCHG_HYSTERESIS_LOWER_BOUND_TRC,"Hysteresis Lower Bound = %d.")
	
	TRC_MSG(BMT_CURRENT_PMIC_STATE_TRC,"BMT.pmictrl_state = %d.")

	
	// Ext charger	
	TRC_MSG(BMT_EXT_INVALID_CHARGER_TRC,"Ext charger: Invalid Charger.")
	TRC_MSG(BMT_EXT_ICHARGE_OVER_TRC,"Ext charger: ICHARGE too high.")
	TRC_MSG(BMT_EXT_ICHARGE_LOW_TRC,"Ext charger: ICHARGE too low.")
	TRC_MSG(BMT_EXT_VBAT_OVER_TRC,"Ext charger: VBAT too high.")
	TRC_MSG(BMT_EXT_VTEMP_OVER_TRC,"Ext charger: BATTMP too high.")
	TRC_MSG(BMT_EXT_VTEMP_LOW_TRC,"Ext charger: BATTMP too low.")
	TRC_MSG(BMT_EXT_CHR_HOLD_TRC,"Ext charger: CHR_HOLD.")
	TRC_MSG(BMT_EXT_VBAT_TRC,"Ext charger: VBAT = %d.")
	TRC_MSG(BMT_EXT_BATTMP_TRC,"Ext charger: BATTMP = %d.")
	TRC_MSG(BMT_EXT_ICHARGE_TRC,"Ext charger: ICHARGE = %d.") 
	TRC_MSG(BMT_EXT_VCHARGER_TRC,"Ext charger: VCHARGER = %d.")
	
	// Soft start
	TRC_MSG(BMT_SOFT_START_CURRENT_LEVEL,"BMT soft start get current level: %d")
	
END_TRACE_MAP(MOD_BMT)


#endif /* _BMT_TRC_H */


