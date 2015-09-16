
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
 *    dcl_pw.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for power on init
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

#include	"reg_base.h"
#include	"init.h"
#include    "system_trc.h"
#include    "init_trc_api.h"
#include    "drv_features.h"
#include    "drv_comm.h"
#include    "intrCtrl.h"
#include    "adc.h"
#include    "bmt.h"
#include    "custom_hw_default.h"
#ifdef __OTG_ENABLE__
#include    "otg_if.h"
#endif // #ifdef __OTG_ENABLE__
#include    "usb_drv.h"
#include 		"dcl.h"
#include "gpio_sw.h"

#if defined (__MTK_UL1_FDD__)
#if !defined (UL1_NOT_PRESENT)
#include    "hal_ul1_def.h"
#endif /* #if !defined (UL1_NOT_PRESENT) */
#endif /* #if defined (__MTK_UL1_FDD__) */

#ifdef __USB_UART_MULTIPLEXED_WITH_EXT_SWITCH__
extern const char gpio_usb_uart_switch_pin;
#endif
extern kal_bool is_init_log_enable;
#include "kal_public_api.h"

#ifdef __MULTI_BOOT__
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif // #ifdef __MULTI_BOOT__

////////////////////////////////////DCL_PW internal use
//debug purpose
kal_uint32 pwic_powerOn_factor=0;
#define AUXADC_PDN_CLR()        adc_pwrdown_enable()
#define AUXADC_PDN_SET()        adc_pwrdown_disable()

#if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)
//extern void kal_bootup_trace(trace_class_enum trc_class, kal_uint32 msg_index, const kal_char* arg_type, ...);
void pw_print_bootup_trace0(kal_uint32 msg_index, const char *arg_type)
{
	kal_bootup_trace(TRACE_INFO, msg_index, arg_type);
}

void pw_print_bootup_trace1(kal_uint32 msg_index, const char *arg_type, kal_uint32 data1)
{
	kal_bootup_trace(TRACE_INFO, msg_index, arg_type, data1);
}
#else // #if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)
#define pw_print_bootup_trace0(...)
#define pw_print_bootup_trace1(...)
#endif // #if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)





//////////////////////////////////////DCL_PW internal use





#ifndef L1_NOT_PRESENT
extern void MD_DRV_L1D_Exit(void);
#endif // #ifndef L1_NOT_PRESENT

//WDT interface
extern kal_bool  WDT_RST;
kal_bool is_wdt_power=KAL_FALSE;
// WDT end

//BMT temp
extern BMTStruct BMT;	


//power on reason
PW_CTRL_POWER_ON_REASON               PWRon;
DCL_HANDLE pw_RtcHandler;
DCL_HANDLE pw_KeypadHandler;
DCL_HANDLE pw_AdcHandler;

extern void Drv_Deinit(void);


/*
* FUNCTION
*	DRV_POWERON
*
* DESCRIPTION
*   	This function is to power on the targer.
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	KAL_TRUE: MS is first power on of RTC has been reset
*	KAL_FALSE: otherwise.
*
* GLOBALS AFFECTED
*   None
*/
static kal_bool DclPW_DRV_POWERON(void)  /*PW_KEYPRESS*/
{
#if !defined(DRV_RTC_NOT_EXIST) && !defined(DRV_RTC_OFF)
	//kal_uint32 BBPU;
	//kal_uint16 status;

	kal_bool isFirstOn = KAL_FALSE;
	#ifdef BMT_DEBUG
	kal_uint32 count;
	#endif // #ifdef BMT_DEBUG

	#ifdef BMT_DEBUG
		dbg_printWithTime("DRV_POWERON..\r\n");
	#endif // #ifdef BMT_DEBUG


	#ifdef _SIMULATION
	isFirstOn = KAL_TRUE;
	#else // #ifdef _SIMULATION
	
	{
		RTC_CTRL_IS_FIRST_ON_T IsFirstOn;
		RTC_CTRL_IS_CONFIG_VALID_T IsConfigValid;

		DclRTC_Control(pw_RtcHandler, RTC_CMD_IS_FIRST_ON, (DCL_CTRL_DATA_T *)&IsFirstOn);	
		DclRTC_Control(pw_RtcHandler, RTC_CMD_IS_CONFIG_VALID, (DCL_CTRL_DATA_T *)&IsConfigValid);			
		if (IsFirstOn.fgFirstOn ||(IsConfigValid.fgIsValid==DCL_FALSE))
	{
		isFirstOn = KAL_TRUE;
	}
	}
	
	#if !defined(__FUE__) && !defined(__UBL__) /* !!CUATION!! for FOTA or bootloader support */
	#if defined(__LATCH_POWER_IN_BOOTLOADER__)
	if (INT_IsFirstPowerOnFromBL(BL_INFO_FROM_RTC))
	{
		isFirstOn = KAL_TRUE;
	}
	#endif // #if defined(__LATCH_POWER_IN_BOOTLOADER__)
	#endif // #if !defined(__FUE__) && !defined(__UBL__) /* !!CUATION!! for FOTA or bootloader support */
	#endif // #ifdef _SIMULATION


	if (KAL_TRUE == isFirstOn)
	{
		// PWIC Clear Plan(RTC)
		// 1. Init RTC time if first power on
		//isFirstOn = KAL_TRUE;

		RTC_CTRL_PWIC_FIRST_POWERON_INIT_RTCTIME_T rtc_cmd_data5;
		
		rtc_cmd_data5.u1Sec = 0;
		rtc_cmd_data5.u1Min = 0;	
		rtc_cmd_data5.u1Hour = 0;
		rtc_cmd_data5.u1Day = DEFAULT_HARDWARE_DAY;
		rtc_cmd_data5.u1WDay = 1;		
		rtc_cmd_data5.u1Mon = DEFAULT_HARDWARE_MON;
		rtc_cmd_data5.u1Year = DEFAULT_HARDWARE_YEAR;	

		DclRTC_Control(pw_RtcHandler, RTC_CMD_PWIC_FIRST_POWERON_INIT_RTCTIME, (DCL_CTRL_DATA_T *)&rtc_cmd_data5);
	}



	// Latch BB power (BBPU)
	DclRTC_Control(pw_RtcHandler, RTC_CMD_PWIC_POWERON_RTC_INIT, (DCL_CTRL_DATA_T *)NULL);

	return isFirstOn;
#else // #if !defined(DRV_RTC_NOT_EXIST) && !defined(DRV_RTC_OFF)
	return KAL_FALSE;
#endif // #if !defined(DRV_RTC_NOT_EXIST) && !defined(DRV_RTC_OFF)
}


static void DclPW_DRV_POWEROFF(void)  /*PW_KEYPRESS*/
{
	#if !defined(__FUE__) && !defined(__UBL__) /* !!CUATION!! for FOTA or bootloader support */
	kal_uint32 index;

	Drv_Deinit();
	#ifdef ORDNANCE
	*IRQ_MASK = (kal_uint16)(~(1 << IRQ_KPAD_CODE));
	#endif // #ifdef ORDNANCE

        #if defined (__MTK_UL1_FDD__)
        #if !defined (UL1_NOT_PRESENT)
        UL1D_EXIT();
        #endif
        #endif


	#if !defined (L1_NOT_PRESENT)
	MD_DRV_L1D_Exit();
	#endif // #ifndef L1_NOT_PRESENT

	/* for BBPU can't be modify twice in a very short period*/
	#if defined(DRV_RTC_NO_REG_COMM) || defined(FPGA)
	if (BMT.EINT2STATE == DETECTCHROUT)
	{
		return;
	}
	#endif // #if defined(DRV_RTC_NO_REG_COMM) || defined(FPGA)

	for (index=0;index<1000;index++);

	#ifdef BMT_DEBUG
	{
		kal_uint32 count=0;
		dbg_printWithTime("DRV_POWEROFF..\r\n");
		while(count++ < 1000000);
	}
	#endif // #ifdef BMT_DEBUG

	#if !defined(DRV_RTC_NOT_EXIST) && !defined(DRV_RTC_OFF)
	IRQMask(IRQ_RTC_CODE);
	#endif // #if !defined(DRV_RTC_NOT_EXIST) && !defined(DRV_RTC_OFF)
	#endif //#if !defined(__FUE__) && !defined(__UBL__) /* !!CUATION!! for FOTA or bootloader support */


   #if !defined(__FUE__) && !defined(__UBL__) /* !!CUATION!! for FOTA or bootloader support */
	// Do NOT include the setting in FOTA build, no need
	// move to HAL PMU
	#if defined(DRV_MISC_POWEROFF_VIO_2_96)
	{
		kal_uint16 val16;
		kal_uint32 count;

		// Turn off I bit
		count = SaveAndSetIRQMask(); //prevent lint error and build error, use count to catch the return value.

		// VIO register control
		//val16 = *(volatile kal_uint16 *)(0x83010808);
		val16 = PW_DRV_ReadReg16(0x83010808);
		val16 &= 0xFF0F;
		val16 |= 0x0080; // Set VIO to 2.96V
		//*(volatile kal_uint16 *)(0x83010808) = val16;
		PW_DRV_WriteReg16(0x83010808, val16);

		count = drv_get_current_time();
		while ( drv_get_duration_ms(count) <= 500 )
		{
			;
		}

	}
	#endif // #if defined(DRV_MISC_POWEROFF_VIO_2_96)
	#endif //#if !defined(__FUE__) && !defined(__UBL__) /* !!CUATION!! for FOTA or bootloader support */


#ifdef PMIC_PRESENT
#if !defined(DRV_RTC_NOT_EXIST) && !defined(DRV_RTC_OFF)
	// Normal power off,
	// 1. clear/set PDN bits acrroding to power off reason
	// 2. Control PPBU register
	DclRTC_Control(pw_RtcHandler, RTC_CMD_PWIC_POWEROFF_RTC_INIT, (DCL_CTRL_DATA_T *)NULL);
#endif // #if !defined(DRV_RTC_NOT_EXIST) && !defined(DRV_RTC_OFF)
#endif // #ifdef PMIC_PRESENT
}

#if (!defined(__FUE__) && !defined(__UBL__)) || defined(__FAST_LOGO__)
#if ( (!defined(__L1_STANDALONE__)) && (!defined(DRV_RTC_BBPU_AS_6208)) )
/*************************************************************************
* FUNCTION
*  PW_is_RTC_expired
*
* DESCRIPTION
*	Check if RTC alarm is expired.
*
* PARAMETERS
*	   None
*
* RETURNS
*  KAL_TRUE:	MS is powered on with RTC alarm expired.
*	KAL_FALSE:	vise versa,

* GLOBALS AFFECTED
*
*
*************************************************************************/
kal_bool DclPW_Is_RTC_Expired(void)
{
#if !defined(DRV_RTC_NOT_EXIST) && !defined(DRV_RTC_OFF)
	kal_uint32 currtime;
	kal_uint32 al_currtime;
	RTC_CTRL_GET_TIME_T  time_current;
	RTC_CTRL_GET_ALARM_TIME_T  time_alarm;
	RTC_CTRL_PWIC_CHECK_POWERON_T rtc_cmd_data14;

	// PWIC Clear Plan(RTC)
	// Check if RTC alarm power on condition
	DclRTC_Control(pw_RtcHandler, RTC_CMD_PWIC_CHECK_POWERON, (DCL_CTRL_DATA_T *)&rtc_cmd_data14); // New API with CMD & DATA
	if (rtc_cmd_data14.fgIsPowerOn)
	{
		DclRTC_Control(pw_RtcHandler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)&time_current);
		DclRTC_Control(pw_RtcHandler, RTC_CMD_GET_ALARM_TIME, (DCL_CTRL_DATA_T *)&time_alarm);

		currtime = (kal_uint32)(time_current.u1Hour*3600+time_current.u1Min*60+time_current.u1Sec);
		al_currtime = (kal_uint32)(time_alarm.u1Hour*3600+time_alarm.u1Min*60+time_alarm.u1Sec);

		// current time >= (alarm time + 20 seconds )
		if ((time_current.u1Year== time_alarm.u1Year) &&
		    (time_current.u1Mon== time_alarm.u1Mon) &&
		    (time_current.u1Day== time_alarm.u1Day) &&
		    (currtime >= (al_currtime)) &&
		    (currtime < (al_currtime+20))
		   )
		{
			#ifdef BMT_DEBUG
			dbg_printWithTime("RTCPWRON\r\n");
			#endif   /*BMT_DEBUG*/
			return KAL_TRUE;
		}
	}
#endif // #if !defined(DRV_RTC_NOT_EXIST) && !defined(DRV_RTC_OFF)
	return KAL_FALSE;
}

#endif //#if ( (!defined(__L1_STANDALONE__)) && (!defined(DRV_RTC_BBPU_AS_6208)) )
#endif //#if (!defined(__FUE__) && !defined(__UBL__)) || defined(__FAST_LOGO__)

#if !defined(__FUE__) && !defined(__UBL__)


/*************************************************************************
* FUNCTION
*  PW_update_flags
*
* DESCRIPTION
*	Update the current state of the nonvolatile flags.
*
* PARAMETERS
*	None
*
* RETURNS
*
* GLOBALS AFFECTED
*	DRV_COMM_REG2
*
*************************************************************************/
static void DclPW_Update_Flags(void)
{

#if !defined(DRV_RTC_NOT_EXIST) && !defined(DRV_RTC_OFF)
	kal_uint16 REG_COMM2;
	RTC_CTRL_CONFIG_PDN_BIT_T rtc_cmd_data18;


	// PWIC Clear Plan(RTC)
	// Read/Write RTC PDN bit

	rtc_cmd_data18.PDNIndex = DCL_RTC_PDN2;	
	DclRTC_Control(pw_RtcHandler, RTC_CMD_READ_PDN_BITS, (DCL_CTRL_DATA_T *)&rtc_cmd_data18); // New API with CMD & DATA
	REG_COMM2 = rtc_cmd_data18.PDNValue;

	if (PWRon == (kal_uint8)PWRKEYPWRON || PWRon == (kal_uint8)ABNRESET)
	{
		REG_COMM2 &= ~(DRV_COMM_REG2_NORMAL_RESET|DRV_COMM_REG2_CHRPWRON|DRV_COMM_REG2_RTCPWRON);
		#if defined(__USB_ENABLE__)
		REG_COMM2 &= ~(DRV_COMM_REG2_USBMS_PWRON);
		#endif // #if defined(__USB_ENABLE__)
	}
	else if (PWRon == (kal_uint8)CHRPWRON)
	{
		REG_COMM2  &= ~(DRV_COMM_REG2_NORMAL_RESET|DRV_COMM_REG2_RTCPWRON);
		#if defined(__USB_ENABLE__)
		REG_COMM2 &= ~(DRV_COMM_REG2_USBMS_PWRON);
		#endif // #if defined(__USB_ENABLE__)
		REG_COMM2 |=  DRV_COMM_REG2_CHRPWRON;
	}
	#if defined(__USB_ENABLE__)
	else if (PWRon == (kal_uint8)USBPWRON)
	{
		// 1. set when selecting mass storage.
		// 2. USB cable is plugged in and powered on.
		REG_COMM2  &= ~(DRV_COMM_REG2_NORMAL_RESET|DRV_COMM_REG2_CHRPWRON|DRV_COMM_REG2_RTCPWRON);
		REG_COMM2 |=  DRV_COMM_REG2_USBMS_PWRON;
	}
	#endif // #if defined(__USB_ENABLE__)
	else if (PWRon == (kal_uint8)RTCPWRON)
	{
		REG_COMM2 &= ~(DRV_COMM_REG2_NORMAL_RESET|DRV_COMM_REG2_CHRPWRON);
		#if defined(__USB_ENABLE__)
		REG_COMM2 &= ~(DRV_COMM_REG2_USBMS_PWRON);
		#endif // #if defined(__USB_ENABLE__)
		REG_COMM2 |= DRV_COMM_REG2_RTCPWRON;
	}

	// Clear Switch2Idle flag
	REG_COMM2 &= ~(DRV_COMM_REG2_SWITCH2IDLE_PWRON);

	// Write back new COMM_REG2 value
	{
		RTC_CTRL_CONFIG_PDN_BIT_T rtcPdnBit;
		rtcPdnBit.PDNIndex = DCL_RTC_PDN2;
		rtcPdnBit.fgConfigBit = REG_COMM2;
		DclRTC_Control(pw_RtcHandler, RTC_CMD_WRITE_PDN_BITS, (DCL_CTRL_DATA_T *)&rtcPdnBit); 
	}

#endif // #if !defined(DRV_RTC_NOT_EXIST) && !defined(DRV_RTC_OFF)

#ifdef BMT_DEBUG
	if (PWRon == PWRKEYPWRON)
	{
		DRV_POWERON();
	}
#endif // #ifdef BMT_DEBUG
	  {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}
}

#if ( (!defined(__L1_STANDALONE__)) && (!defined(DRV_RTC_BBPU_AS_6208)) )
/*************************************************************************
* FUNCTION
*  PW_is_precharge_on
*
* DESCRIPTION
*	check if phone is in precharge state
*
* PARAMETERS
*	None
*
* RETURNS
*  KAL_TRUE or KAL_FALSE
*
* GLOBALS AFFECTED
*	DRV_COMM_REG2
*
*************************************************************************/
//extern kal_uint16 ADC_GetData(kal_uint8 sel);
#if !defined(__DRV_NO_USB_CHARGER__)
static kal_bool DclPW_Is_Precharge_On(void)
{
#if defined(__USB_ENABLE__)
	USB_DRV_CTRL_PHY_FUNC_T  dcl_data;
	DCL_HANDLE  usb_dcl_handle;
#endif // #if defined(__USB_ENABLE__)

#if defined(__DRV_NO_CABLE_DETECTION__)
	return KAL_FALSE;
#endif // #if defined(__DRV_NO_CABLE_DETECTION__)

#ifndef __DRV_NO_CABLE_DETECTION__


	kal_uint8 channel;
	kal_uint16 adc;
	kal_int32 volt;
	ADC_CTRL_GET_PHYSICAL_CHANNEL_T adc_ch;
	ADC_CTRL_TRANSFORM_INTO_VOLT_T adcTransV;
	ADC_CTRL_GET_DATA_T adc_data;


	#if defined(DRV_MISC_ADC_CH0_BUG_WA)
	return KAL_FALSE;
	#endif // #if defined(DRV_MISC_ADC_CH0_BUG_WA)

	adc_ch.u2AdcName = DCL_VBAT_ADC_CHANNEL;
	DclSADC_Control( pw_AdcHandler, ADC_CMD_GET_CHANNEL,(DCL_CTRL_DATA_T *)& adc_ch);
        channel=adc_ch.u1AdcPhyCh;

	if (channel >= ADC_MAX_CHANNEL)
	{
		// TTTTTT TBD, should we assert??
		channel = 0;
	}
	#if defined(__USB_ENABLE__)
	//USB_Phy_Enable(USB_PHY_OWNER_BMT);//USB_PowerControl(KAL_TRUE);
	usb_dcl_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);
	dcl_data.owner = DCL_USB_PHY_OWNER_BMT;
	DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_PHY_ENABLE, (DCL_CTRL_DATA_T  *)&dcl_data);	
	#endif // #if defined(__USB_ENABLE__)

#ifndef DRV_ADC_NOT_EXIST
	adc_data.u1Channel = channel;
	DclHADC_Control( pw_AdcHandler, ADC_CMD_GET_DATA,(DCL_CTRL_DATA_T *)& adc_data);
	adc = (kal_uint16)adc_data.u4ADCData;
#endif // #ifndef DRV_ADC_NOT_EXIST

	adcTransV.u1AdcPhyCh = channel;
	adcTransV.d8AdcValue = adc;
	DclSADC_Control(pw_AdcHandler, ADC_CMD_TRANSFORM_INTO_VOLT, (DCL_CTRL_DATA_T *)&adcTransV);
	volt = adcTransV.u4Volt;

	#if defined(__USB_ENABLE__)
	//USB_Phy_Disable(USB_PHY_OWNER_BMT);//USB_PowerControl(KAL_FALSE);
	DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_PHY_DISABLE, (DCL_CTRL_DATA_T  *)&dcl_data);
	DclUSB_DRV_Close(usb_dcl_handle);	
	#endif // #if defined(__USB_ENABLE__)
	if (volt<=BMT_PRECHARGE_THRESHOLD)
	{
		return KAL_TRUE;
	}
	else
	{
		return KAL_FALSE;
	}

#endif // #ifndef __DRV_NO_CABLE_DETECTION__
}
#endif //#if !defined(__DRV_NO_USB_CHARGER__)


void DclPW_PowerInit(void)
{
#if !defined(DRV_RTC_NOT_EXIST) && !defined(DRV_RTC_OFF)
#if !defined(DRV_MISC_TDMA_32K_CALI) || defined(FPGA)
	kal_uint32 delay;
#endif // #if !defined(DRV_MISC_TDMA_32K_CALI) || defined(FPGA)
#if defined(__LATCH_POWER_IN_BOOTLOADER__)
	kal_bool pw_is_powered_latched_in_bl = KAL_FALSE;
	kal_bool pw_is_rtc_first_on = KAL_FALSE;
#endif // #if defined(__LATCH_POWER_IN_BOOTLOADER__)	
	kal_uint8  RTC_Firston;
	RTC_CTRL_IS_FIRST_ON_T IsFirstOn;
	kal_uint16 REG_COMM2;
	kal_bool factors[PWR_FACTOR_MAX] = {KAL_FALSE};
#if !defined(__DRV_NO_USB_CHARGER__)
	CHR_DET_CTRL_QUERY_IS_CHR_IN_BY_PW CHRDETCtrlType;
#endif //#if !defined(__DRV_NO_USB_CHARGER__)
	RTC_CTRL_CONFIG_PDN_BIT_T rtc_cmd_data18;
	HKBD_CTRL_POWKEY_T powerkeyStatus;

    #if defined(__FAST_LOGO__)
    kal_uint8 power_detect_reason_bl;
    power_detect_reason_bl = INT_GetSysStaByCmd(SYS_CMD_GET_PWN_STA, NULL);
    #endif

	#if !defined(__FUE__) && !defined(__UBL__) /* !!CUATION!! for FOTA or bootloader support */
	#if defined(__LATCH_POWER_IN_BOOTLOADER__)
	if (INT_IsFirstPowerOnFromBL(BL_INFO_FROM_RTC))
	{
		pw_is_rtc_first_on = KAL_TRUE;
	}

	if (INT_IsPowerLatchedByBL())
	{
		pw_is_powered_latched_in_bl = KAL_TRUE;
	}
	#endif // #if defined(__LATCH_POWER_IN_BOOTLOADER__)
	#endif // #if !defined(__FUE__) && !defined(__UBL__) /* !!CUATION!! for FOTA or bootloader support */


	rtc_cmd_data18.PDNIndex = DCL_RTC_PDN2;	
	DclRTC_Control(pw_RtcHandler, RTC_CMD_READ_PDN_BITS, (DCL_CTRL_DATA_T *)&rtc_cmd_data18); // New API with CMD & DATA
	REG_COMM2 = rtc_cmd_data18.PDNValue;

	DclRTC_Control(pw_RtcHandler, RTC_CMD_IS_FIRST_ON, (DCL_CTRL_DATA_T *)&IsFirstOn);	

   	// If RTC first on, reset PDN bits to normal reset
	RTC_Firston = (kal_uint8)IsFirstOn.fgFirstOn;

	#if !defined(__FUE__) && !defined(__UBL__) /* !!CUATION!! for FOTA or bootloader support */
	#if defined(__LATCH_POWER_IN_BOOTLOADER__)

	RTC_Firston |= pw_is_rtc_first_on;

	if (pw_is_rtc_first_on)
	{
		RTC_set_First_PowerOn(KAL_TRUE); //
	}
	#endif // #if defined(__LATCH_POWER_IN_BOOTLOADER__)
	#endif // #if !defined(__FUE__) && !defined(__UBL__) /* !!CUATION!! for FOTA or bootloader support */


	if (RTC_Firston)
	{

		RTC_CTRL_CONFIG_PDN_BIT_T rtcPdnBit;
		REG_COMM2 = DRV_COMM_REG2_NORMAL_RESET; // REG_COMM2 will be refered in later check
		rtcPdnBit.PDNIndex = DCL_RTC_PDN2;
		rtcPdnBit.fgConfigBit = DRV_COMM_REG2_NORMAL_RESET; // REG_COMM2 will be refered in later check		
		DclRTC_Control(pw_RtcHandler, RTC_CMD_WRITE_PDN_BITS, (DCL_CTRL_DATA_T *)&rtcPdnBit);

		#if !defined(DRV_MISC_TDMA_32K_CALI)
		for(delay=0;delay<22030000;delay++);
		#endif // #if !defined(DRV_MISC_TDMA_32K_CALI)
	}



	#ifdef __MULTI_BOOT__
	if ((INT_BootMode() != MTK_NORMAL_MODE)||(INT_IsBootForUSBAT() == KAL_TRUE)||(is_init_log_enable == KAL_TRUE))
	{
                DCL_HANDLE dcl_bmt_handle = DclBMT_Open(DCL_BMT, FLAGS_NONE);
                BMT_CTRL_CHARGE_T ChargeControl;
		pw_print_bootup_trace0(SST_PW_POWERINIT_META_PWRON);

		//зяж^PWIC interface !!
		ChargeControl.bEnable = DCL_FALSE;
                DclBMT_Control(dcl_bmt_handle, BMT_CMD_CHARGE, (DCL_CTRL_DATA_T *)&ChargeControl);
                DclBMT_Close(dcl_bmt_handle);
		//tempBMT_Charge(KAL_FALSE);  // In BMT_Charge, we will decide whether to really enable or disable charge enable
		//BMT.PWRon = (kal_uint8)PWRKEYPWRON;
		PWRon=PWRKEYPWRON;
		DclPW_DRV_POWERON();
		return;
	}
	#endif   /*__MULTI_BOOT__*/


	// collect all factors
	// check RTC expired
	if (DclPW_Is_RTC_Expired())
	{
		factors[PWR_FACTOR_RTC_EXPIRE] = KAL_TRUE;
	}

	DclHKBD_Control(pw_KeypadHandler,HKBD_CMD_GET_POWER_KEY_STATUS , (DCL_CTRL_DATA_T*)&powerkeyStatus);
	
	// check power key pressed
    #if defined(__FAST_LOGO__)
    if (powerkeyStatus.fgPKP || (power_detect_reason_bl & PWR_FACTOR_BL_POWER_KEY))
    #else
	if (powerkeyStatus.fgPKP)
    #endif    
	{
		factors[PWR_FACTOR_POWER_KEY] = KAL_TRUE;
	}
	// check charger or usb existence
#if !defined(__DRV_NO_USB_CHARGER__)
#ifdef __USB_UART_MULTIPLEXED_WITH_EXT_SWITCH__
	GPIO_WriteIO(1, gpio_usb_uart_switch_pin);	//switch to usb mode before USB/CHR detect
#endif


	Dcl_Chr_Det_Control(NULL,CHR_DET_CMD_QUERY_IS_CHR_IN_BY_PW,(DCL_CTRL_DATA_T *)&CHRDETCtrlType);
	switch (CHRDETCtrlType.Chr_det_type)
	{
		case PW_AC_CHR:
		case PW_AC_NON_STD_CHR:
			factors[PWR_FACTOR_CHARGER_IN] = KAL_TRUE;
		break;			
		case PW_USB_CHR:
		case PW_USB_CHARGING_HOST_CHR:
			factors[PWR_FACTOR_USB_IN] = KAL_TRUE;
		break;			
		case PW_NO_CHR:
		break;
	}

	/*check Precharge*/
	if (factors[PWR_FACTOR_CHARGER_IN]==KAL_TRUE)
	{
		if (DclPW_Is_Precharge_On())
		{
			factors[PWR_FACTOR_PRECHRPWRON_FLG] = KAL_TRUE;
		}
	}

#ifdef __USB_UART_MULTIPLEXED_WITH_EXT_SWITCH__
	if(factors[PWR_FACTOR_USB_IN] != KAL_TRUE)
		GPIO_WriteIO(0, gpio_usb_uart_switch_pin);	//restore to UART mode
#endif

#endif /*  !defined(__DRV_NO_USB_CHARGER__) */


	// check watch dog reset
	if (WDT_RST)
	{
		factors[PWR_FACTOR_WDT_RESET] = KAL_TRUE;
		is_wdt_power=KAL_TRUE;/*for NFB*/
	}
	// check flags
	if (REG_COMM2 & DRV_COMM_REG2_NORMAL_RESET)
	{
		factors[PWR_FACTOR_NORMAL_RESET_FLG] = KAL_TRUE;
	}
	if (REG_COMM2 & DRV_COMM_REG2_CHRPWRON)
	{
		factors[PWR_FACTOR_CHRPWRON_FLG] = KAL_TRUE;
	}
	if (REG_COMM2 & DRV_COMM_REG2_USBMS_PWRON)
	{
		factors[PWR_FACTOR_USBMS_PWRON_FLG] = KAL_TRUE;
	}
	if (REG_COMM2 & DRV_COMM_REG2_RTCPWRON)
	{
		factors[PWR_FACTOR_RTCPWRON_FLG] = KAL_TRUE;
	}
	if (REG_COMM2 & DRV_COMM_REG2_SWITCH2IDLE_PWRON)
	{
		factors[PWR_FACTOR_SWITCH2IDLE_FLG] = KAL_TRUE;
	}
	// check power on type
	// priority: PWRKEYPWRON > ABNRESET > CHRPWRON > USBPWRON_WDT > USBPWRON > RTCPWRON


	#if defined(DRV_MISC_PWIC_FORCE_RETURN_PWRKEY_POWERON)
	{
		kal_uint32 tmp_i;
		for (tmp_i=0; tmp_i<PWR_FACTOR_MAX;tmp_i++){
			factors[tmp_i] = KAL_FALSE;
		}
		factors[PWR_FACTOR_SWITCH2IDLE_FLG] = KAL_TRUE;
	}
	#endif // #if defined(DRV_MISC_PWIC_FORCE_RETURN_PWRKEY_POWERON)


	#ifdef __CS_FAC_DET__
	{
		cs_fac_boot_mode_enum fac_boot_mode;
		fac_boot_mode = cs_fac_det->factory_det_get_boot_mode();
		switch (fac_boot_mode)
		{
			case CS_FAC_BOOT_IDLE:
				factors[PWR_FACTOR_SWITCH2IDLE_FLG] = KAL_TRUE;
			break;
			case CS_FAC_BOOT_CHARGING:
				factors[PWR_FACTOR_SWITCH2CHR_FLG] = KAL_TRUE;
			break;
			case CS_FAC_BOOT_USB_CHARGING:
				factors[PWR_FACTOR_SWITCH2USB_FLG] = KAL_TRUE;
			break;
			default:
			break;
		}
	}
	#endif // #ifdef __CS_FAC_DET__


	#if defined(__DRV_ALLOW_BOOT_ON_WITHOUT_BATTERY__)
	//if (!pmic_adpt_is_bat_on())
	if (!bmt_is_bat_on())
	{
		#if defined(__DRV_NO_BATTERY_FORCE_BOOT_TO_CHARGING__)
		factors[PWR_FACTOR_SWITCH2CHR_FLG] = KAL_TRUE;
		#endif // #if defined(__DRV_NO_BATTERY_FORCE_BOOT_TO_CHARGING__)
	}
	#endif // #if defined(__DRV_ALLOW_BOOT_ON_WITHOUT_BATTERY__)


	pw_print_bootup_trace1(SST_PW_POWERINIT_FACTOR_PWRKEY, factors[0]);
	pw_print_bootup_trace1(SST_PW_POWERINIT_FACTOR_CHRIN, factors[1]);
	pw_print_bootup_trace1(SST_PW_POWERINIT_FACTOR_USBIN, factors[2]);
	pw_print_bootup_trace1(SST_PW_POWERINIT_FACTOR_RTCALARM, factors[3]);
	pw_print_bootup_trace1(SST_PW_POWERINIT_FACTOR_WDT, factors[4]);
	pw_print_bootup_trace1(SST_PW_POWERINIT_FACTOR_NORMAL_RST, factors[5]);
	pw_print_bootup_trace1(SST_PW_POWERINIT_FACTOR_CHR_PWRON_FG, factors[6]);
	pw_print_bootup_trace1(SST_PW_POWERINIT_FACTOR_USBMS_PWRON_FG, factors[7]);
	pw_print_bootup_trace1(SST_PW_POWERINIT_FACTOR_RTC_PWRON_FG, factors[8]);
	pw_print_bootup_trace1(SST_PW_POWERINIT_FACTOR_PRECHR_PWRON_FG, factors[9]);
	pw_print_bootup_trace1(SST_PW_POWERINIT_FACTOR_FC2IDLE_FG, factors[10]);
	pw_print_bootup_trace1(SST_PW_POWERINIT_FACTOR_FC2CHR_FG, factors[11]);
	pw_print_bootup_trace1(SST_PW_POWERINIT_FACTOR_FC2USB_FG, factors[12]);


	if(factors[PWR_FACTOR_PRECHRPWRON_FLG])
	{
		//BMT.PWRon = (kal_uint8)CHRPWRON;//PRECHRPWRON
		PWRon=CHRPWRON;
	}
	else if (factors[PWR_FACTOR_SWITCH2IDLE_FLG])
	{
		//BMT.PWRon = (kal_uint8)PWRKEYPWRON;
		PWRon=PWRKEYPWRON;
	}
	else if (factors[PWR_FACTOR_SWITCH2CHR_FLG])
	{
		//BMT.PWRon = (kal_uint8)CHRPWRON;
		PWRon=CHRPWRON;
	}
	else if (factors[PWR_FACTOR_SWITCH2USB_FLG])
	{
		//BMT.PWRon = (kal_uint8)USBPWRON;
		PWRon=USBPWRON;
	}
	else if ((factors[PWR_FACTOR_POWER_KEY]&& !factors[PWR_FACTOR_CHARGER_IN]&& !factors[PWR_FACTOR_USB_IN])||
	         (factors[PWR_FACTOR_POWER_KEY]&& factors[PWR_FACTOR_CHARGER_IN]&& factors[PWR_FACTOR_WDT_RESET]&& factors[PWR_FACTOR_CHRPWRON_FLG])||
	         (factors[PWR_FACTOR_POWER_KEY]&& factors[PWR_FACTOR_USB_IN]&& factors[PWR_FACTOR_WDT_RESET]&& factors[PWR_FACTOR_USBMS_PWRON_FLG])||
	         (factors[PWR_FACTOR_POWER_KEY]&& factors[PWR_FACTOR_CHARGER_IN]&& !factors[PWR_FACTOR_WDT_RESET])||
	         (factors[PWR_FACTOR_POWER_KEY]&& factors[PWR_FACTOR_USB_IN]&& !factors[PWR_FACTOR_WDT_RESET]))
	{
		//BMT.PWRon = (kal_uint8)PWRKEYPWRON;
		PWRon=PWRKEYPWRON;
	}
	else if (factors[PWR_FACTOR_WDT_RESET]&&!factors[PWR_FACTOR_CHRPWRON_FLG]&&!factors[PWR_FACTOR_USBMS_PWRON_FLG]
	         &&!factors[PWR_FACTOR_RTCPWRON_FLG]&& !factors[PWR_FACTOR_NORMAL_RESET_FLG])
	{
		//BMT.PWRon = (kal_uint8)ABNRESET;
		PWRon=ABNRESET;
	}
	#ifdef __MA_L1__
	else if (factors[PWR_FACTOR_WDT_RESET]&&!factors[PWR_FACTOR_NORMAL_RESET_FLG]&&(KAL_TRUE == query_mas_mode()))
	{
		//BMT.PWRon = (kal_uint8)PWRKEYPWRON;
		PWRon=PWRKEYPWRON;
	}
	#endif // #ifdef __MA_L1__
	else if ((factors[PWR_FACTOR_CHARGER_IN]&&!factors[PWR_FACTOR_POWER_KEY])||
	         (factors[PWR_FACTOR_CHARGER_IN]&&factors[PWR_FACTOR_POWER_KEY]&&!factors[PWR_FACTOR_RTCPWRON_FLG]))
	{
		//BMT.PWRon = (kal_uint8)CHRPWRON;
		PWRon=CHRPWRON;
	}
	#ifdef __USB_ENABLE__
	else if ((factors[PWR_FACTOR_USB_IN]&&!factors[PWR_FACTOR_POWER_KEY]&&factors[PWR_FACTOR_WDT_RESET]&&
	         !factors[PWR_FACTOR_NORMAL_RESET_FLG]&&factors[PWR_FACTOR_USBMS_PWRON_FLG]))
	{
		#if defined(DRV_BMT_NONE_USB_POWER_ON)
		//BMT.PWRon = (kal_uint8)CHRPWRON;
		PWRon=CHRPWRON;
		#else //#if defined(DRV_BMT_NONE_USB_POWER_ON)
		//BMT.PWRon = (kal_uint8)USBPWRON_WDT;
		PWRon=USBPWRON_WDT;
		#endif //#if defined(DRV_BMT_NONE_USB_POWER_ON)
	}
	else if ((factors[PWR_FACTOR_USB_IN]&&!factors[PWR_FACTOR_POWER_KEY])||
	         (factors[PWR_FACTOR_USB_IN]&&factors[PWR_FACTOR_POWER_KEY]&&!factors[PWR_FACTOR_USBMS_PWRON_FLG])
	        )
	{
		#if defined(DRV_BMT_NONE_USB_POWER_ON)
		//BMT.PWRon = (kal_uint8)CHRPWRON;
		PWRon=CHRPWRON;
		#else //#if defined(DRV_BMT_NONE_USB_POWER_ON)
		//BMT.PWRon = (kal_uint8)USBPWRON;
		PWRon=USBPWRON;
		#endif //#if defined(DRV_BMT_NONE_USB_POWER_ON)
	}
	#endif // #ifdef __USB_ENABLE__
	else if ((factors[PWR_FACTOR_RTC_EXPIRE]&&!factors[PWR_FACTOR_RTCPWRON_FLG]))
	{
		//BMT.PWRon = (kal_uint8)RTCPWRON;
		PWRon=RTCPWRON;
	}
	#if !defined(__FUE__) && !defined(__UBL__) /* !!CUATION!! for FOTA or bootloader support */
	#if defined(__LATCH_POWER_IN_BOOTLOADER__)
	else if (pw_is_powered_latched_in_bl)
	{
		//BMT.PWRon = (kal_uint8)PWRKEYPWRON;
		PWRon=PWRKEYPWRON;
	}
	#endif // #if defined(__LATCH_POWER_IN_BOOTLOADER__)
	#endif // #if !defined(__FUE__) && !defined(__UBL__) /* !!CUATION!! for FOTA or bootloader support */
	else
	{
		kal_uint32 wait = 0;
		pw_print_bootup_trace0(SST_PW_POWERINIT_ABNORMAL_PWRON);

		while(1)/*to cover crstal oscillates too late case*/
		{

			// PWIC Clear Plan(RTC)
			// Abnormal power on, need to power off, disable RTC alarm
			DclRTC_Control(pw_RtcHandler, RTC_CMD_PWIC_MASK_AL, (DCL_CTRL_DATA_T *)NULL);
			DclPW_DRV_POWEROFF();
			for(wait=0;wait<50000;wait++){};
		}
	}

	pw_print_bootup_trace1(SST_PW_POWERINIT_PWRON_REASON, PWRon);

	// reset flags
	DclPW_Update_Flags();

	{
		kal_uint8 i;
		for (i=0;i<PWR_FACTOR_MAX;i++)
		{
			pwic_powerOn_factor=pwic_powerOn_factor|factors[i]<<i;
		}
	}

#else // #if !defined(DRV_RTC_NOT_EXIST) && !defined(DRV_RTC_OFF)
	//BMT.PWRon = PWRKEYPWRON;
	PWRon=PWRKEYPWRON;
#endif // #if !defined(DRV_RTC_NOT_EXIST) && !defined(DRV_RTC_OFF)

}

#endif //#if ( (!defined(__L1_STANDALONE__)) && (!defined(DRV_RTC_BBPU_AS_6208)) )
#endif //#if !defined(__FUE__) && !defined(__UBL__)

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
DCL_STATUS DclPW_Initialize(void)
{
	if (pw_RtcHandler==DCL_HANDLE_NONE)
	{
		pw_RtcHandler= DclRTC_Open(DCL_RTC,FLAGS_NONE);
	}

#if !defined(__FUE__) && !defined(__UBL__)
	if (pw_KeypadHandler==DCL_HANDLE_NONE)
	{
		pw_KeypadHandler = DclHKBD_Open(DCL_KBD, FLAGS_NONE);
	}

	if (pw_AdcHandler==DCL_HANDLE_NONE)
	{
		pw_AdcHandler = DclSADC_Open(DCL_ADC, FLAGS_NONE);
	}	
#endif // #if !defined(__FUE__) && !defined(__UBL__)


	return STATUS_OK;
}

/*************************************************************************
* FUNCTION
*  DclPMU_Open
*
* DESCRIPTION
*  This function is to open the PMU38 module and return a handle
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
DCL_HANDLE DclPW_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	if (dev != DCL_PW)
	{
		ASSERT(0);
		return DCL_HANDLE_INVALID;
	}

	return 1234;
}

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
DCL_STATUS DclPW_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

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
DCL_STATUS DclPW_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}
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
DCL_STATUS DclPW_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
    return STATUS_UNSUPPORTED;
}
/*************************************************************************
* FUNCTION
*  DclPMU_RegisterCallback
*
* DESCRIPTION
*  This function is to set callback function for the PMU module.
*
* PARAMETERS
*  handle: the returned handle value of DclPMU_Open
*  event: Supported events:
*         EVENT_WDT_TIMEOUT: Watch dog time out interrupt
*  callback: the callback function for registered events
*
* RETURNS
*  STATUS_OK: Successfully register the callback function.
*  STATUS_INVALID_HANDLE: It's a invalid handle.
*  STATUS_NOT_OPENED: The module has not been opened.
*  STATUS_INVALID_EVENT: The event parameter is invalid.
*
*************************************************************************/
DCL_STATUS DclPW_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
    return STATUS_UNSUPPORTED;
}
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
*          1. WDT_CMD_ENABLE: to enable/disable WDT
*          2. WDT_CMD_SET_EXT_POL: to set ploarity of external pin when WDT expired
*  data: The data of the control command
*          1. WDT_CMD_ENABLE: pointer to a WDT_CTRL_ENABLE_T structure
*          2. WDT_CMD_SET_EXT_POL: pointer to a WDT_CTRL_SET_EXT_POL_T structure
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
DCL_STATUS DclPW_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	RTC_CTRL_CONFIG_PDN_BIT_T rtcPdnBit;

	switch(cmd)
	{
		case PW_CMD_SET_SWITCH_TO_IDLE:
		{
			rtcPdnBit.PDNIndex = DCL_RTC_PDN2;
			rtcPdnBit.fgConfigBit = DRV_COMM_REG2_SWITCH2IDLE_PWRON;
			DclRTC_Control(pw_RtcHandler, RTC_CMD_SET_PDN_BITS, (DCL_CTRL_DATA_T *)&rtcPdnBit);
		}
		break;		
		case PW_CMD_POWERON:
		{
			DclPW_DRV_POWERON();
		}	
		break;		
		case PW_CMD_POWEROFF:
		{
			DclPW_DRV_POWEROFF();
		}
		break;
#if !defined(__FUE__) && !defined(__UBL__)			
		case PW_CMD_SET_POWERON_REASON:
		{					
			PW_CTRL_SET_POWERON_REASON *pCtrlVal=&(data->rPWSetPowerOnReason);
			PWRon = pCtrlVal->powerOnReason;
		 
			// PWIC Clear Plan(RTC)
			// read/write PDN bit
			if (PWRon == (kal_uint8)PWRKEYPWRON)
			{			
				// Clear RTC power on bit
				rtcPdnBit.PDNIndex = DCL_RTC_PDN2;
				rtcPdnBit.fgConfigBit = DRV_COMM_REG2_RTCPWRON;	
				DclRTC_Control(pw_RtcHandler, RTC_CMD_CLEAR_PDN_BITS, (DCL_CTRL_DATA_T *)&rtcPdnBit); 		
			}			 
		}
		break;
		case PW_CMD_GET_POWERON_REASON:
		{
			PW_CTRL_GET_POWERON_REASON *pCtrlVal=&(data->rPWGetPowerOnReason);
			pCtrlVal->powerOnReason=PWRon;
		}
		break;
		case PW_CMD_CLEAR_SWITCH_TO_IDLE:
		{
			rtcPdnBit.PDNIndex = DCL_RTC_PDN2;
			rtcPdnBit.fgConfigBit = DRV_COMM_REG2_SWITCH2IDLE_PWRON;		
			DclRTC_Control(pw_RtcHandler, RTC_CMD_CLEAR_PDN_BITS, (DCL_CTRL_DATA_T *)&rtcPdnBit); 
		}	
		break;
		case PW_CMD_POWER_INIT:
		{
#if ( (!defined(__L1_STANDALONE__)) && (!defined(DRV_RTC_BBPU_AS_6208)) )
			DclPW_PowerInit();
#endif //#if ( (!defined(__L1_STANDALONE__)) && (!defined(DRV_RTC_BBPU_AS_6208)) )
		}
		break;
		case PW_CMD_UPDATE_FLAGS:
		{
			DclPW_Update_Flags();
		}
		break;
		case PW_CMD_NFB_POWERON:
		{
			#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
			if (PWRon == PWRKEYPWRON)
			{
				DclPW_DRV_POWERON();
			}
			#endif // #ifdef _NAND_FLASH_BOOTING_
		}
		break;	
		case PW_CMD_IS_USB_BOOT:
		{
			PW_CTRL_IS_USB_BOOT *pCtrlVal=&(data->rPWIsUsbBoot);
			if ((PWRon == USBPWRON) || (PWRon ==USBPWRON_WDT))
			{
				pCtrlVal->val=DCL_TRUE;
			}
			else
			{
				pCtrlVal->val=DCL_FALSE;
			}
		}
		break;			
#endif //#if !defined(__FUE__) && !defined(__UBL__)		
	      default:
	       return STATUS_UNSUPPORTED;
	}

	return STATUS_OK;
}
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
DCL_STATUS DclPW_Close(DCL_HANDLE handle)
{
    return STATUS_OK;
}


