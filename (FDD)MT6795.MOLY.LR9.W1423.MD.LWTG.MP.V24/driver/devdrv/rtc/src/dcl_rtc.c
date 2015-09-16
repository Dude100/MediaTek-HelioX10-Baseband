/******************************************************************

  NOTICE : We have no HW for this IP now,
            But for SW complie request, temporarily add the 'fake api' to make compile success.
              
 *****************************************************************/
 
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
 *    dcl_rtc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the RTC driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_features.h"
#include "drv_comm.h" 
#include "dcl.h"   
#include "kal_general_types.h"
#include "kal_public_api.h"

// 
// #include "rtc_sw_new.h"
// #ifdef DCL_RTC_INTERFACE
// 
// #if !defined(DRV_RTC_OFF)
// // This API is exported by  rtc.c
// extern void RTC_TCintr(void);
// extern void RTC_ALintr(void);
// extern kal_bool RTC_FT_PowerOff(void);
// extern void RTC_HW_Init_(void);
// extern void RTC_reload(void);
// #ifdef RTC_TEST
// extern void RTC_delay(void);
// #endif
// extern kal_bool RTC_PWIC_Check_PowerOn(void);
// extern void RTC_setBBPU(kal_uint16 data);
// extern void RTC_PWIC_First_PowerOn_INIT_RTCTime(t_rtc *rtctime);
// extern void RTC_PWIC_Mask_AL(void);
// extern void RTC_PWIC_PowerOff_RTC_INIT(void);
// extern void RTC_PWIC_PowerOn_RTC_INIT(void);
// 
// #if defined(DRV_RTC_DBING)
// extern void RTC_wait_debounce(void);
// #endif //#if defined(DRV_RTC_DBING)
// extern void RTC_start_cali(void);
// extern rtc_callbac RTC_CALLBAC;
// 
// // Global variable for DCL RTC API usage
// #define DCL_RTC_DEV_MAGIC_NUM		(0x40000000)
// #define MAX_DCL_RTC_HANDLE			2
// kal_uint32 dcl_rtc_handle_count = 0;
// 
// // The event is presented by 32-bit variable
// #define MAX_DCL_RTC_EVENT_NUM		32
// PFN_DCL_CALLBACK dcl_rtc_event_callback[MAX_DCL_RTC_EVENT_NUM];
// 
// /*************************************************************************
// * Non-exported DCL internal functions
// *************************************************************************/
// void dcl_rtc_tc_intr_handler(void){
// 	kal_uint32 event_bit;
// 	kal_uint32 i;
// 	// Search event callback entry	
// 	for (i=0;i<MAX_DCL_RTC_EVENT_NUM;i++){
// 		event_bit = 1 << i;
// 		if (event_bit == EVENT_RTC_TC){
// 			if (dcl_rtc_event_callback[i] != NULL){
// 				dcl_rtc_event_callback[i](EVENT_RTC_TC);
// 			}
// 			break;
// 		}
// 	}
// }
// void dcl_rtc_al_intr_handler(void){
// 	kal_uint32 event_bit;
// 	kal_uint32 i;
// 	// Search event callback entry	
// 	for (i=0;i<MAX_DCL_RTC_EVENT_NUM;i++){
// 		event_bit = 1 << i;
// 		if (event_bit == EVENT_RTC_ALARM){
// 			if (dcl_rtc_event_callback[i] != NULL){
// 				dcl_rtc_event_callback[i](EVENT_RTC_ALARM);
// 			}
// 			break;
// 		}
// 	}
// }
// 
// /*************************************************************************
// * Non-exported DCL internal functions
// *************************************************************************/
// 
// 
// 
// /*************************************************************************
// * FUNCTION
// *  DclRTC_Initialize
// *
// * DESCRIPTION
// *  This function is to initialize RTC module
// *
// * PARAMETERS
// *  None
// *
// * RETURNS
// *  STATUS_OK
// *
// *************************************************************************/
// 
// 
// DCL_STATUS DclRTC_Initialize(void){
// 
// #if defined(DRV_RTC_HW_CALI)
// 	RTC_HW_Init_();
// #endif // #if defined(DRV_RTC_HW_CALI)
// 
// #if !defined(__FUE__) && !defined(__UBL__)
// 	RTC_init_(RTC_TCintr,RTC_ALintr);
// #endif
// 
// 	// Init event callback mapping array
// 	{
// 		kal_uint32 i;
// 		for (i=0;i<MAX_DCL_RTC_EVENT_NUM;i++){
// 			dcl_rtc_event_callback[i] = NULL;
// 		}
// 	}
// 
// 	// Hack/Register to RTC driver callback
// #if !defined(__FUE__) && !defined(__UBL__)	
// 	RTC_CALLBAC.rtc_tcfunc = dcl_rtc_tc_intr_handler;
// 	RTC_CALLBAC.rtc_alfunc = dcl_rtc_al_intr_handler;
// #endif
// 
// 	dcl_rtc_handle_count = 0;
// 
// 
// 	return STATUS_OK;
// 
// 
// 
// }
// 
// /*************************************************************************
// * FUNCTION
// *  DclRTC_Open
// *
// * DESCRIPTION
// *  This function is to open the RTC module and return a handle
// *
// * PARAMETERS
// *  dev: only valid for DCL_RTC
// *  flags: no sepcial flags is needed. Please use FLAGS_NONE
// *
// * RETURNS
// *  DCL_HANDLE_INVALID: Open failed
// *  Other value: A valid handle
// *
// *************************************************************************/
// 
// DCL_HANDLE DclRTC_Open(DCL_DEV dev, DCL_FLAGS flags)
// {
// 	kal_uint32 handle;
// 	kal_uint32 savedMask;
// 
// 	// Check device type
// 	if (dev != DCL_RTC){
// 		ASSERT(0);
// 		return DCL_HANDLE_INVALID;		// Incorrecr device ID
// 	}
// 
// 	// Check allowed open number
// 	if (dcl_rtc_handle_count >= MAX_DCL_RTC_HANDLE){
// 		ASSERT(0);
// 		return DCL_HANDLE_INVALID;		// Too many opened handles
// 	}
// 	
// 	savedMask = SaveAndSetIRQMask();
// //	dcl_rtc_handle_count ++;
//     dcl_rtc_handle_count = 1;
// 	handle = (DCL_RTC_DEV_MAGIC_NUM | dcl_rtc_handle_count);
// 	RestoreIRQMask(savedMask);
// 
// 	return handle;
// }
// 
// /*************************************************************************
// * FUNCTION
// *  DclRTC_ReadData
// *
// * DESCRIPTION
// *  This function is not supported for the RTC module now.
// *
// * PARAMETERS
// *	N/A
// *
// * RETURNS
// *	STATUS_UNSUPPORTED
// *
// *************************************************************************/
// DCL_STATUS DclRTC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options){
// 	return STATUS_UNSUPPORTED;
// }
// 
// /*************************************************************************
// * FUNCTION
// *  DclRTC_WriteData
// *
// * DESCRIPTION
// *  This function is not supported for the RTC module now.
// *
// * PARAMETERS
// *	N/A
// *
// * RETURNS
// *	STATUS_UNSUPPORTED
// *
// *************************************************************************/
// extern DCL_STATUS DclRTC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options){
// 	return STATUS_UNSUPPORTED;
// }
// 
// /*************************************************************************
// * FUNCTION
// *  DclRTC_Configure
// *
// * DESCRIPTION
// *  This function is not supported for the RTC module now.
// *
// * PARAMETERS
// *	N/A
// *
// * RETURNS
// *	STATUS_UNSUPPORTED
// *
// *************************************************************************/
// DCL_STATUS DclRTC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure){
// 	return STATUS_UNSUPPORTED;
// }
// 
// /*************************************************************************
// * FUNCTION
// *  DclRTC_RegisterCallback
// *
// * DESCRIPTION
// *  This function is to set callback function for the RTC module.
// *
// * PARAMETERS
// *  handle: the returned handle value of DclRTC_Open
// *  event: Supported events:
// *         EVENT_RTC_ALARM: RTC alarm interrupt
// *         EVENT_RTC_TC: RTC tick interrupt
// *  callback: the callback function for registered events
// *
// * RETURNS
// *  STATUS_OK: Successfully register the callback function.
// *  STATUS_INVALID_DCL_HANDLE: It's a invalid handle.
// *  STATUS_NOT_OPENED: The module has not been opened.
// *  STATUS_INVALID_EVENT: The event parameter is invalid.
// *
// *************************************************************************/
// DCL_STATUS DclRTC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback){
// 	
// 	// Check magic number
// 	if ((handle & DCL_RTC_DEV_MAGIC_NUM) != DCL_RTC_DEV_MAGIC_NUM){
// 		ASSERT(0);
// 		return STATUS_INVALID_DCL_HANDLE;
// 	}	
// 
// 	// Error check
// 	if (dcl_rtc_handle_count == 0){
// 		ASSERT(0);
// 		return STATUS_NOT_OPENED;
// 	}
// 	// Check if the passed-in event bitmap is supported or NOT
// 	if (((kal_uint32)event & (~(EVENT_RTC_ALARM | EVENT_RTC_TC))) != 0){
// 		ASSERT(0);
// 		return STATUS_INVALID_EVENT;
// 	}
// 
// 	// Search mapping array and assign callback to specofic array entry
// 	{
// 		kal_uint32 i;
// 		kal_uint32 event_bit;
// 		for (i=0;i<MAX_DCL_RTC_EVENT_NUM;i++){
// 			event_bit = 1 << i;
// 			if ((event_bit & event) != 0){
// 				// 1. Check if a callback has been registered for the event
// 				// Allow multiple registration for now
// 				//ASSERT(dcl_rtc_event_callback[i] != NULL);
// 				// 2. Register the callback
// 				dcl_rtc_event_callback[i] = callback;
// 			}
// 		}
// 	}
// 	return STATUS_OK;
// }
// 
// 
// /*************************************************************************
// * FUNCTION
// *  DclRTC_Control
// *
// * DESCRIPTION
// *  This function is to send command to control the RTC module.
// *
// * PARAMETERS
// *  handle: The handle value returned from DclRTC_Open
// *  cmd: A control command for RTC module
// *           1. RTC_CMD_BOOTLOADER_POWERON: to check RTC Power On in bootloader
// *           2. RTC_CMD_CLEAR_PDN_BITS: to clear RTC PDN bits
// *           3. RTC_CMD_CONFIG_AL_TC: to set alarm mask and tick mask
// *           4. RTC_CMD_DELAY: to Delay 2000 counts
// *           5. RTC_CMD_GET_ALARM_TIME: to get alarm time
// *           6. RTC_CMD_GET_TIME: to get time              
// *           7. RTC_CMD_GPIO_GET_INPUT: to get RTC_GPIO_GPI register value
// *           8. RTC_CMD_GPIO_SET_EXPORT_32K: to export 32.768KHz clock on RTC_GPIO
// *           9. RTC_CMD_GPIO_SET_EXPORT_COREDETB: to export COREDETB on RTC_GPIO
// *          10. RTC_CMD_GPIO_SET_INPUT_MODE: to set RTC_GPIO input mode
// *          11. RTC_CMD_GPIO_SET_OUTPUT_MODE: to set RTC_GPIO output mode
// *          12. RTC_CMD_HW_INIT: to initialize RTC hardware
// *          13. RTC_CMD_INIT: to initialize RTC software
// *          14. RTC_CMD_INIT_TC_AL_INTR: to initialize RTC TC & AL INTR
// *          15. RTC_CMD_IS_CONFIG_VALID: to check if RTC time and Alarm are valid
// *          16. RTC_CMD_IS_FIRST_ON: to check if device is first on               
// *          17. RTC_CMD_IS_MS_FIRSTPOWERON: to check whether RTC is first power on(for MMI)
// *          18. RTC_CMD_IS_TIME_VALID: to check if time are valid
// *          19. RTC_CMD_PWIC_CHECK_POWERON: to check if power on (for PWIC)
// *          20. RTC_CMD_PWIC_FIRST_POWERON_INIT_RTCTIME: to init RTC time at first power on (for PWIC)
// *          21. RTC_CMD_PWIC_MASK_AL: to control RTC Alarm mask (for PWIC)
// *          22. RTC_CMD_PWIC_POWEROFF_RTC_INIT: to init RTC at power off (for PWIC)
// *          23. RTC_CMD_PWIC_POWERON_RTC_INIT: to init RTC at power on (for PWIC)
// *          24. RTC_CMD_READ_PDN_BITS: to read RTC PDN bits
// *          25. RTC_CMD_READ_XOSC_REG: to read RTC XOSCCALI register
// *          26. RTC_CMD_RELOAD: to load RTC whole register info from RTC module
// *          27. RTC_CMD_SET_ALARM_TIME: to set alarm time
// *          28. RTC_CMD_SET_FIRST_POWERON: to set first power on
// *          29. RTC_CMD_SET_PDN_BITS: to set RTC PDN bits
// *          30. RTC_CMD_SET_PWR_KEY: to set PWR KEY
// *          31. RTC_CMD_SET_TIME: to set time
// *          32. RTC_CMD_SETBBPU: to set RTC_BBPU
// *          33. RTC_CMD_SETXOSC: to set RTC XOSCCALI register
// *          34. RTC_CMD_START_CALI: to start calibration process
// *          35. RTC_CMD_WAIT_DEBOUNCE: to wait until debounce bit becomes 0
// *          36. RTC_CMD_WRITE_PDN_BITS: to write RTC PDN bits
// *          37. RTC_CMD_WRITE_TRIGGER: to set write trigger
// *          38. RTC_CMD_WRITE_TRIGGER_WAIT: to set write trigger and wait until BUSY bit becomes 0
// *          39. RTC_CMD_WRITE_XOSC_REG: to write RTC XOSCCALI register
// *
// *  data: The data of the control command
// *           1. RTC_CMD_BOOTLOADER_POWERON: pointer to a RTC_CTRL_BOOTLOADER_POWERON_T structure
// *           2. RTC_CMD_CLEAR_PDN_BITS: pointer to a RTC_CTRL_CONFIG_PDN_BIT_T structure
// *           3. RTC_CMD_CONFIG_AL_TC: pointer to a RTC_CTRL_CONFIG_AL_TC_T structure
// *           4. RTC_CMD_DELAY: A null pointer
// *           5. RTC_CMD_GET_ALARM_TIME: pointer to a RTC_CTRL_GET_ALARM_TIME_T structure
// *           6. RTC_CMD_GET_TIME: pointer to a RTC_CTRL_GET_TIME_T structure       
// *           7. RTC_CMD_GPIO_GET_INPUT: pointer to a RTC_CTRL_GPIO_TIME_T structure
// *           8. RTC_CMD_GPIO_SET_EXPORT_32K: pointer to a RTC_CTRL_GPIO_TIME_T structure
// *           9. RTC_CMD_GPIO_SET_EXPORT_COREDETB: pointer to a RTC_CTRL_GPIO_TIME_T structure
// *          10. RTC_CMD_GPIO_SET_INPUT_MODE: pointer to a RTC_CTRL_GPIO_TIME_T structure
// *          11. RTC_CMD_GPIO_SET_OUTPUT_MODE: pointer to a RTC_CTRL_GPIO_TIME_T structure
// *          12. RTC_CMD_HW_INIT: A null pointer
// *          13. RTC_CMD_INIT: pointer to a RTC_CTRL_INIT_T structure
// *          14. RTC_CMD_INIT_TC_AL_INTR: A null pointer
// *          15. RTC_CMD_IS_CONFIG_VALID: pointer to a RTC_CTRL_IS_CONFIG_VALID_T structure
// *          16. RTC_CMD_IS_FIRST_ON: pointer to a RTC_CTRL_IS_FIRST_ON_T structure             
// *          17. RTC_CMD_IS_MS_FIRSTPOWERON: pointer to a RTC_CTRL_IS_MS_FIRSTPOWERON_T structure
// *          18. RTC_CMD_IS_TIME_VALID: pointer to a RTC_CTRL_IS_TIME_VALID_T structure
// *          19. RTC_CMD_PWIC_CHECK_POWERON: pointer to a RTC_CTRL_PWIC_CHECK_POWERON_T structure
// *          20. RTC_CMD_PWIC_FIRST_POWERON_INIT_RTCTIME: pointer to a RTC_CTRL_PWIC_FIRST_POWERON_INIT_RTCTIME_T structure
// *          21. RTC_CMD_PWIC_MASK_AL: A null pointer
// *          22. RTC_CMD_PWIC_POWEROFF_RTC_INIT: A null pointer
// *          23. RTC_CMD_PWIC_POWERON_RTC_INIT: A null pointer
// *          24. RTC_CMD_READ_PDN_BITS: pointer to a RTC_CTRL_CONFIG_PDN_BIT_T structure
// *          25. RTC_CMD_READ_XOSC_REG: pointer to a RTC_CTRL_READ_XOSC_REG_T structure
// *          26. RTC_CMD_RELOAD: A null pointer
// *          27. RTC_CMD_SET_ALARM_TIME: pointer to a RTC_CTRL_SET_ALARM_TIME_T structure
// *          28. RTC_CMD_SET_FIRST_POWERON: pointer to a RTC_CTRL_SET_FIRST_POWERON_T structure
// *          29. RTC_CMD_SET_PDN_BITS: pointer to a RTC_CTRL_CONFIG_PDN_BIT_T structure
// *          30. RTC_CMD_SET_PWR_KEY: A null pointer
// *          31. RTC_CMD_SET_TIME: pointer to a RTC_CTRL_SET_TIME_T structure
// *          32. RTC_CMD_SETBBPU: pointer to a RTC_CTRL_SETBBPU_T structure
// *          33. RTC_CMD_SETXOSC: A null pointer
// *          34. RTC_CMD_START_CALI: A null pointer
// *          35. RTC_CMD_WAIT_DEBOUNCE: A null pointer
// *          36. RTC_CMD_WRITE_PDN_BITS: pointer to a RTC_CTRL_CONFIG_PDN_BIT_T structure
// *          37. RTC_CMD_WRITE_TRIGGER: A null pointer
// *          38. RTC_CMD_WRITE_TRIGGER_WAIT: A null pointer
// *          39. RTC_CMD_WRITE_XOSC_REG: pointer to a RTC_CTRL_WRITE_XOSC_REG_T structure
// *
// * RETURNS
// *  STATUS_OK: command is executed successfully.
// *  STATUS_FAIL: command is failed.
// *  STATUS_INVALID_CMD: It's a invalid command.
// *
// *************************************************************************/
// DCL_STATUS DclRTC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
// {
//     DCL_STATUS return_status;
// 
// 	// Check magic number
// 	if ((handle & DCL_RTC_DEV_MAGIC_NUM) != DCL_RTC_DEV_MAGIC_NUM){
// 		ASSERT(0);
// 		return STATUS_INVALID_DCL_HANDLE;
// 	}
// 
// 	// Error check
// 	if (dcl_rtc_handle_count == 0){
// 		ASSERT(0);
// 		return STATUS_NOT_OPENED;
// 	}
// 
// 	switch (cmd)
// 	{
//         case RTC_CMD_BOOTLOADER_POWERON:
//         {
// 			RTC_CTRL_BOOTLOADER_POWERON_T *prBootloaderPowerOn;
// 			prBootloaderPowerOn = &(data->rBootloaderPowerOn);
// 			prBootloaderPowerOn->fgBootloaderPowerOn = (DCL_BOOLEAN)RTC_Bootloader_PowerOn_();            
//             return_status = STATUS_OK;
//         }
//         break;
//         
//         case RTC_CMD_CLEAR_PDN_BITS:
//         {
// 			RTC_CTRL_CONFIG_PDN_BIT_T *prConfigPDNBit;
// 			prConfigPDNBit = &(data->rConfigPDNBit);
// 			RTC_Clear_PDN_bits((RTC_PDN_INDEX)prConfigPDNBit->PDNIndex, prConfigPDNBit->fgConfigBit);            
//             return_status = STATUS_OK;
//         }
//         break;
//         
// 		case RTC_CMD_CONFIG_AL_TC:
// 		{
// #if !defined(__FUE__) && !defined(__UBL__)            
// 			RTC_CTRL_CONFIG_AL_TC_T  *prConfigALTC;
// 			prConfigALTC = &(data->rConfigALTC);
// 			RTC_Config_(prConfigALTC->u1ALEn, prConfigALTC->u1TCEn);
// 			return_status = STATUS_OK;
// #else
// 			return_status = STATUS_UNSUPPORTED;
// #endif            
// 		}
// 		break;
//         
//         case RTC_CMD_DELAY:
//         {
// #ifdef RTC_TEST            
//             RTC_delay();
//             return_status = STATUS_OK;
// #else
// 			return_status = STATUS_UNSUPPORTED;
// #endif
//         }
//         break;
//         
//         case RTC_CMD_FT_POWEROFF:
//         {
//             RTC_CTRL_FT_POWEROFF_T  *prFTPowerOff;
// 			prFTPowerOff = &(data->rFTPowerOff);
//             prFTPowerOff->fgMetaReset =(DCL_BOOLEAN)RTC_FT_PowerOff();
//             return_status = STATUS_OK;
//         }
//         break; 
//         
// 		case RTC_CMD_GET_ALARM_TIME:
// 		{
// 			t_rtc rtc;
// 			RTC_CTRL_GET_ALARM_TIME_T *prGetAlarmTime;
// 			prGetAlarmTime = &(data->rGetAlarmTime);
// 			prGetAlarmTime->ALEnBit = (DCL_BOOLEAN)RTC_GetALTime(&rtc);
// 			
// 			prGetAlarmTime->u1Sec = rtc.rtc_sec;
// 			prGetAlarmTime->u1Min = rtc.rtc_min;
// 			prGetAlarmTime->u1Hour = rtc.rtc_hour;
// 			prGetAlarmTime->u1Day = rtc.rtc_day;
// 			prGetAlarmTime->u1Mon = rtc.rtc_mon;
// 			prGetAlarmTime->u1WDay = rtc.rtc_wday;
// 			prGetAlarmTime->u1Year = rtc.rtc_year;
// 			
// 			return_status = STATUS_OK;
// 		}
// 		break;   
//         
// 		case RTC_CMD_GET_TIME:
// 		{
// 			t_rtc rtc;
// 			RTC_CTRL_GET_TIME_T *prGetTime;
// 			prGetTime = &(data->rGetTime);
// 			RTC_GetTime_(&rtc);  
// 
// 			prGetTime->u1Sec = rtc.rtc_sec;
// 			prGetTime->u1Min = rtc.rtc_min;
// 			prGetTime->u1Hour = rtc.rtc_hour;
// 			prGetTime->u1Day = rtc.rtc_day;
// 			prGetTime->u1Mon = rtc.rtc_mon;
// 			prGetTime->u1WDay = rtc.rtc_wday;
// 			prGetTime->u1Year = rtc.rtc_year;
// 
// 			return_status = STATUS_OK;
// 		}
// 		break;
//         
// #if defined(DRV_RTC_GPIO)
// 		case RTC_CMD_GPIO_GET_INPUT:
// 		{
// 			RTC_CTRL_GPIO_TIME_T *prGPIO;
// 			prGPIO = &(data->rGPIO);
// 			prGPIO->InputValue = (DCL_BOOLEAN)RTC_Get_GPIO_Input();
// 			return_status = STATUS_OK;
// 		}
// 		break;
//         
// 		case RTC_CMD_GPIO_SET_EXPORT_32K:
// 		{
// 			RTC_Set_GPIO_Mode(RTC_GPIO_EXPORT_32K);
// 			return_status = STATUS_OK;
// 		}
// 		break;
//         
// 		case RTC_CMD_GPIO_SET_EXPORT_COREDETB:
// 		{
// 			RTC_Set_GPIO_Mode(RTC_GPIO_EXPORT_COREDETB);
// 			return_status = STATUS_OK;
// 		}
// 		break; 
//         
// 		case RTC_CMD_GPIO_SET_INPUT_MODE:
// 		{
// 			RTC_CTRL_GPIO_TIME_T *prGPIO;
// 			prGPIO = &(data->rGPIO);
// 			RTC_Set_GPIO_Input_Mode((RTC_GPIO_PULL_TYPE_enum) prGPIO->rPullType,
// 				(RTC_GPIO_DRIVING_STRENGTH_enum) prGPIO->rPullStrength,(kal_bool)prGPIO->is_SmithTrigger);
// 			return_status = STATUS_OK;
// 		}
// 		break;
//         
// 		case RTC_CMD_GPIO_SET_OUTPUT_MODE:
// 		{
// 			RTC_CTRL_GPIO_TIME_T *prGPIO;
// 			prGPIO = &(data->rGPIO);
// 			RTC_Set_GPIO_Output_Mode((kal_bool)prGPIO->OutputValue,(kal_bool)prGPIO->is_SlewRateControl);
// 			return_status = STATUS_OK;
// 		}
// 		break;
//         
//  #endif //#if defined(DRV_RTC_GPIO)
//  		case RTC_CMD_HW_INIT:
// 		{
// 			RTC_HW_Init_();
// 			return_status = STATUS_OK;
// 		}
// 		break;
//         
//         case RTC_CMD_INIT:
//         {
// #if !defined(__FUE__) && !defined(__UBL__)            
//             RTC_CTRL_INIT_T *prInit;
//             prInit = &(data->rInit);
//             RTC_init_(prInit->RTC_TCCallback, prInit->RTC_ALCallback);
//             return_status = STATUS_OK;
// #else
// 			return_status = STATUS_UNSUPPORTED;
// #endif
//         }
//         break;
//         
//         case RTC_CMD_INIT_TC_AL_INTR:
//         {
// #if !defined(__FUE__) && !defined(__UBL__)              
//             RTC_init_(RTC_TCintr,RTC_ALintr);
//             return_status = STATUS_OK;
// #else
//             return_status = STATUS_UNSUPPORTED;
// #endif
//         }
//         break;
//         
//  		case RTC_CMD_IS_CONFIG_VALID:
// 		{
//             RTC_CTRL_IS_CONFIG_VALID_T *prIsConfigValid;
// 			prIsConfigValid = &(data->rIsConfigValid);
// 			prIsConfigValid->fgIsValid = (DCL_BOOLEAN)RTC_is_config_valid();
// 			return_status = STATUS_OK;
// 		}
// 		break;
//         
// 		case RTC_CMD_IS_FIRST_ON:
// 		{			
// 			RTC_CTRL_IS_FIRST_ON_T *prIsFirstOn;
// 			prIsFirstOn = &(data->rIsFirstOn);
// 			prIsFirstOn->fgFirstOn = (DCL_BOOLEAN)RTC_isFisrtOn();
// 			return_status = STATUS_OK;
// 		}
// 		break;  
//         
// 		case RTC_CMD_IS_MS_FIRSTPOWERON:
// 		{
// #if !defined(__FUE__) && !defined(__UBL__)            
// 			RTC_CTRL_IS_MS_FIRSTPOWERON_T *prIsMSFirstPowerOn;
// 			prIsMSFirstPowerOn = &(data->rIsMSFirstPowerOn);
// 			prIsMSFirstPowerOn->fgMSFirstPowerOn = (DCL_BOOLEAN)RTC_is_MS_FirstPowerOn_();
// 			return_status = STATUS_OK;
// #else
// 			return_status = STATUS_UNSUPPORTED;
// #endif
// 		}
// 		break;
//         
//         case RTC_CMD_IS_TIME_VALID:
//         {
// 			t_rtc rtc;
// 			RTC_CTRL_IS_TIME_VALID_T *prIsTimeValid;
// 			prIsTimeValid = &(data->rIsTimeValid);
//             
// 			rtc.rtc_sec = prIsTimeValid->u1Sec;
// 			rtc.rtc_min = prIsTimeValid->u1Min;
// 			rtc.rtc_hour = prIsTimeValid->u1Hour;
// 			rtc.rtc_day = prIsTimeValid->u1Day;
// 			rtc.rtc_mon = prIsTimeValid->u1Mon;
// 			rtc.rtc_wday = prIsTimeValid->u1WDay;
// 			rtc.rtc_year = prIsTimeValid->u1Year;
// 
//             prIsTimeValid->isTimeValid = (DCL_BOOLEAN)RTC_is_Time_Valid(&rtc);
// 
//             return_status = STATUS_OK;
//         }
//         break;
//         
//         case RTC_CMD_PWIC_CHECK_POWERON:
//         {
//             RTC_CTRL_PWIC_CHECK_POWERON_T *prPwicCheckPowerOn;
// 			prPwicCheckPowerOn = &(data->rPwicCheckPowerOn);
// 			prPwicCheckPowerOn->fgIsPowerOn = (DCL_BOOLEAN)RTC_PWIC_Check_PowerOn();            
// 			return_status = STATUS_OK;            
//         }
//         break;
//         
// 		case RTC_CMD_PWIC_FIRST_POWERON_INIT_RTCTIME:
// 		{
// 			t_rtc rtc;
// 			RTC_CTRL_PWIC_FIRST_POWERON_INIT_RTCTIME_T *prPwicFirstPowerOnInitRTCTime;
// 			prPwicFirstPowerOnInitRTCTime = &(data->rPwicFirstPowerOnInitRTCTime);
// 
// 			rtc.rtc_sec = prPwicFirstPowerOnInitRTCTime->u1Sec;
// 			rtc.rtc_min = prPwicFirstPowerOnInitRTCTime->u1Min;
// 			rtc.rtc_hour = prPwicFirstPowerOnInitRTCTime->u1Hour;
// 			rtc.rtc_day = prPwicFirstPowerOnInitRTCTime->u1Day;
// 			rtc.rtc_mon = prPwicFirstPowerOnInitRTCTime->u1Mon;
// 			rtc.rtc_wday = prPwicFirstPowerOnInitRTCTime->u1WDay;
// 			rtc.rtc_year = prPwicFirstPowerOnInitRTCTime->u1Year;
// 			
// 			RTC_PWIC_First_PowerOn_INIT_RTCTime(&rtc);
// 
// 			return_status = STATUS_OK;
// 		}
//         break;
//         
//         case RTC_CMD_PWIC_MASK_AL:
// 		{
// 			RTC_PWIC_Mask_AL();
// 			return_status = STATUS_OK;
// 		}
// 		break;
//         
//         case RTC_CMD_PWIC_POWEROFF_RTC_INIT:
// 		{
// 			RTC_PWIC_PowerOff_RTC_INIT();
// 			return_status = STATUS_OK;
// 		}
// 		break;
//         
//         case RTC_CMD_PWIC_POWERON_RTC_INIT:
// 		{
// 			RTC_PWIC_PowerOn_RTC_INIT();
// 			return_status = STATUS_OK;
// 		}
// 		break;
//         
//         case RTC_CMD_READ_PDN_BITS:
//         {
// 			RTC_CTRL_CONFIG_PDN_BIT_T *prConfigPDNBit;
// 			prConfigPDNBit = &(data->rConfigPDNBit);
// 			prConfigPDNBit->PDNValue = RTC_Read_PDN((RTC_PDN_INDEX)prConfigPDNBit->PDNIndex);            
//             return_status = STATUS_OK;
//         }        
//         break;
//         
//         case RTC_CMD_READ_SPAR:
//         {
// #if defined(DRV_RTC_REG_SPAR)               
// 			RTC_CTRL_CONFIG_SPAR_T *prConfigSPARReg;
// 			prConfigSPARReg = &(data->rConfigSPARReg);
// 			prConfigSPARReg->ReadValue = RTC_Read_SPAR((RTC_SPAR_INDEX)prConfigSPARReg->SPARIndex);            
//             return_status = STATUS_OK;
// #else
// 			return_status = STATUS_UNSUPPORTED;
// #endif // #if defined(DRV_RTC_REG_SPAR)
//         }        
//         break;     
//         
//         case RTC_CMD_READ_XOSC_REG:
//         {
// 			RTC_CTRL_READ_XOSC_REG_T *prReadXOSCReg;
// 			prReadXOSCReg = &(data->rReadXOSCReg);
// 			prReadXOSCReg->XOSCValue = RTC_read_xosc_reg();            
//             return_status = STATUS_OK;
//         }        
//         break; 
//         
// 		case RTC_CMD_RELOAD:
// 		{
// #if defined(DRV_RTC_HW_CALI)
// 			RTC_reload();
// 			return_status = STATUS_OK;
// #else
// 			return_status = STATUS_UNSUPPORTED;
// #endif // #if defined(DRV_RTC_HW_CALI)
// 		}
// 		break;   
//         
// 		case RTC_CMD_SET_ALARM_TIME:
// 		{
// 			t_rtc rtc;
// 			RTC_CTRL_SET_ALARM_TIME_T *prSetAlarmTime;
// 			prSetAlarmTime = &(data->rSetAlarmTime);
// 
// 			rtc.rtc_sec = prSetAlarmTime->u1Sec;
// 			rtc.rtc_min = prSetAlarmTime->u1Min;
// 			rtc.rtc_hour = prSetAlarmTime->u1Hour;
// 			rtc.rtc_day = prSetAlarmTime->u1Day;
// 			rtc.rtc_mon = prSetAlarmTime->u1Mon;
// 			rtc.rtc_wday = prSetAlarmTime->u1WDay;
// 			rtc.rtc_year = prSetAlarmTime->u1Year;
// 			
// 			RTC_SetAlarm(&rtc);
// 			return_status = STATUS_OK;
// 		}
// 		break;
//         
//         case RTC_CMD_SET_FIRST_POWERON:
//         {
// #if !defined(__FUE__) && !defined(__UBL__)            
//             RTC_CTRL_SET_FIRST_POWERON_T *prSetFirstPowerOn;
//             prSetFirstPowerOn = &(data->rSetFirstPowerOn);
//             RTC_set_First_PowerOn((kal_bool)prSetFirstPowerOn->fgPowerOn);
//             return_status = STATUS_OK;
// #else
//             return_status = STATUS_UNSUPPORTED;
// #endif
//         }
//         break;
//         
//         case RTC_CMD_SET_PDN_BITS:
//         {
// 			RTC_CTRL_CONFIG_PDN_BIT_T *prConfigPDNBit;
// 			prConfigPDNBit = &(data->rConfigPDNBit);
// 			RTC_Set_PDN_bits((RTC_PDN_INDEX)prConfigPDNBit->PDNIndex, prConfigPDNBit->fgConfigBit);            
//             return_status = STATUS_OK;
//         }
//         break;
//         
// 		case RTC_CMD_SET_PWR_KEY:
// 		{
// 			RTC_setPWRKey();
// 			return_status = STATUS_OK;
// 		}
// 		break;
//         
// 		case RTC_CMD_SET_TIME:
// 		{
// 			t_rtc rtc;
// 			RTC_CTRL_SET_TIME_T *prSetTime;
// 			prSetTime = &(data->rSetTime);
//             
// 			rtc.rtc_sec = prSetTime->u1Sec;
// 			rtc.rtc_min = prSetTime->u1Min;
// 			rtc.rtc_hour = prSetTime->u1Hour;
// 			rtc.rtc_day = prSetTime->u1Day;
// 			rtc.rtc_mon = prSetTime->u1Mon;
// 			rtc.rtc_wday = prSetTime->u1WDay;
// 			rtc.rtc_year = prSetTime->u1Year;
//             
// 			RTC_InitTC_Time(&rtc);
// 			return_status = STATUS_OK;
// 		}
// 		break;
//         
// 		case RTC_CMD_SETBBPU:
// 		{
// #ifdef RTC_Test            
// 			RTC_CTRL_SETBBPU_T *prSetBBPU;
// 			prSetBBPU = &(data->rSetBBPU);
// 			RTC_setBBPU(prSetBBPU->BBPUReg);   
// 			return_status = STATUS_OK;
// #else
//             return_status = STATUS_UNSUPPORTED;
// #endif
// 		}
// 		break;
//         
//         case RTC_CMD_SETXOSC:
//         {
//             RTC_setXOSC_();
//             return_status = STATUS_OK;
//         }
//         break;
//         
// 		case RTC_CMD_START_CALI:
// 		{
// #if !defined(__FUE__) && !defined(__UBL__)            
// 			RTC_start_cali();
// 			return_status = STATUS_OK;
// #else
//         	return_status = STATUS_UNSUPPORTED;
// #endif
// 		}
// 		break;
//         
// 		case RTC_CMD_WAIT_DEBOUNCE:
// 		{
// #if defined(DRV_RTC_DBING)
// 			RTC_wait_debounce();
// 			return_status = STATUS_OK;
// #else
// 			return_status = STATUS_UNSUPPORTED;
// #endif // #if defined(DRV_RTC_DBING)
// 		}
// 		break;
//         
//         case RTC_CMD_WRITE_PDN_BITS:
//         {
// 			RTC_CTRL_CONFIG_PDN_BIT_T *prConfigPDNBit;
// 			prConfigPDNBit = &(data->rConfigPDNBit);
// 			RTC_Write_PDN_bits((RTC_PDN_INDEX)prConfigPDNBit->PDNIndex, prConfigPDNBit->fgConfigBit);            
//             return_status = STATUS_OK;
//         }  
//         break;   
//         
// 		case RTC_CMD_WRITE_TRIGGER:
// 		{
// #if defined(DRV_RTC_HW_CALI)
// 			RTC_write_trigger();
// 			return_status = STATUS_OK;
// #else
// 			return_status = STATUS_UNSUPPORTED;
// #endif // #if defined(DRV_RTC_HW_CALI)
// 		}
// 		break;
//         
// 		case RTC_CMD_WRITE_TRIGGER_WAIT:
// 		{
// #if defined(DRV_RTC_HW_CALI)
// 			RTC_write_trigger_wait();
// 			return_status = STATUS_OK;
// #else
// 			return_status = STATUS_UNSUPPORTED;
// #endif // #if defined(DRV_RTC_HW_CALI)
// 		}
// 		break;
// 
//         case RTC_CMD_WRITE_SPAR:
//         {
// #if defined(DRV_RTC_REG_SPAR)               
// 			RTC_CTRL_CONFIG_SPAR_T *prConfigSPARReg;
// 			prConfigSPARReg = &(data->rConfigSPARReg);
// 			RTC_Write_SPAR((RTC_SPAR_INDEX)prConfigSPARReg->SPARIndex, prConfigSPARReg->WriteValue);            
//             return_status = STATUS_OK;
// #else
// 			return_status = STATUS_UNSUPPORTED;
// #endif // #if defined(DRV_RTC_REG_SPAR)
//         }        
//         break;
//         
//         case RTC_CMD_WRITE_XOSC_REG:
//         {
// 			RTC_CTRL_WRITE_XOSC_REG_T *prWriteXOSCReg;
// 			prWriteXOSCReg = &(data->rWriteXOSCRef);            
//             RTC_write_xosc_reg(prWriteXOSCReg->XOSC_Reg);
//             return_status = STATUS_OK;
//         }
//         break;
//         
// 		default:
// 			return_status = STATUS_INVALID_CMD;
// 		break;
// 	}
//     return return_status;
// //	return STATUS_FAIL;
// }
// 
// 
// /*************************************************************************
// * FUNCTION
// *  DclRTC_Close
// *
// * DESCRIPTION
// *  This function is to close the RTC module.
// *
// * PARAMETERS
// *  handle: the returned handle value of DclRTC_Open
// *
// * RETURNS
// *  STATUS_OK
// *
// *************************************************************************/
// DCL_STATUS DclRTC_Close(DCL_HANDLE handle)
// {
// 	kal_uint32 savedMask;
// 
// 	// Check magic number
// 	if ((handle & DCL_RTC_DEV_MAGIC_NUM) != DCL_RTC_DEV_MAGIC_NUM){
// 		ASSERT(0);
// 		return STATUS_INVALID_DCL_HANDLE;
// 	}
// 
// 	// Error check
// 	if (dcl_rtc_handle_count == 0){
// 		ASSERT(0);
// 		return STATUS_NOT_OPENED;
// 	}
// 	// Clear all registered event callbacks for the specific handle
// 	// Note: If we support multiple handles, we need to take care of the clear
// 	{
// 		kal_uint32 i;
// 		for (i=0;i<MAX_DCL_RTC_EVENT_NUM;i++){
// 			dcl_rtc_event_callback[i] = NULL;
// 		}
// 	}
// 
// 	savedMask = SaveAndSetIRQMask();
// 	// dcl_rtc_handle_count --;
// 	RestoreIRQMask(savedMask);
// 
// 	return STATUS_OK;
// }
// 
// #else /*!defined(DRV_RTC_OFF)*/
// 
// DCL_STATUS DclRTC_Initialize(void)
// {
// 	return STATUS_FAIL;
// }
// 
// DCL_HANDLE DclRTC_Open(DCL_DEV dev, DCL_FLAGS flags)
// {
//    return DCL_HANDLE_INVALID;
// }
// 
// DCL_STATUS DclRTC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
// {
// 	return STATUS_UNSUPPORTED;
// }
// 
// DCL_STATUS DclRTC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
// {
// 	return STATUS_UNSUPPORTED;
// }
// 
// DCL_STATUS DclRTC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
// {
// 	return STATUS_UNSUPPORTED;
// }
// 
// DCL_STATUS DclRTC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
// {
// 	return STATUS_FAIL;
// }
// 
// DCL_STATUS DclRTC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
// {
// 	return STATUS_FAIL;
// }
// 
// DCL_STATUS DclRTC_Close(DCL_HANDLE handle)
// {
// 	return STATUS_FAIL;
// }
// 
// 
// #endif /*!defined(DRV_RTC_OFF)*/
// 
// #else

DCL_STATUS DclRTC_Initialize(void)
{
	return STATUS_FAIL;
}

DCL_HANDLE DclRTC_Open(DCL_DEV dev, DCL_FLAGS flags)
{
   return STATUS_UNSUPPORTED;
}

DCL_STATUS DclRTC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclRTC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclRTC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclRTC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_FAIL;
}

DCL_STATUS DclRTC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	return STATUS_FAIL;
}

DCL_STATUS DclRTC_Close(DCL_HANDLE handle)
{
	return STATUS_FAIL;
}


// #endif //#ifdef DCL_RTC_INTERFACE

