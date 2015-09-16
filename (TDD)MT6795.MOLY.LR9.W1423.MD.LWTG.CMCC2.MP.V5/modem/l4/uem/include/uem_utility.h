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
 * uem_utility.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for UEM utility.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *==============================================================================
 *******************************************************************************/

#ifndef _UEM_UTILITY_H
#define _UEM_UTILITY_H

#include "kal_general_types.h"
    #include "uem_context.h"
    #include "kal_public_api.h"
    #include "device.h"
    #include "ps_public_struct.h"
#include "kal_public_defs.h" //MSBB change     #include "stack_msgs.h"
#include "dcl.h"

/***************************************************************************** 
* Typedef
*****************************************************************************/

#define FLAG_IS_ON(b, a)     ((b & (0x1 << a)) >> a)
#define FLAG_SET_ON(b, a)    (b |= (0x1 << a))
#define FLAG_SET_OFF(b, a)   (b &= ~(0x1 << a))

#if defined(PLUTO_MMI)
extern kal_bool is_status_matched(uem_accessory_status_enum type);
#endif /* defined(PLUTO_MMI) */ 

typedef void (*UEM_TIMER_FUNC_PRT) (void *);

typedef struct
{
    eventid eventID;
} UEM_TIMER_EVENTS;

/***************************************************************************** 
* Define the timer ID
*****************************************************************************/
#define LED_EVENT_TIMER    0
#define LCD_EVENT_TIMER    1
#define VIB_EVENT_TIMER    2
#define PWN_EVENT_TIMER    3
#define ADC_EVENT_TIMER    4
#define LCD_BK_OFF_TIMER    5
#define MAX_UEM_EVENT_TIMER   10

/***************************************************************************** 
* External Variable
*****************************************************************************/
extern UEM_TIMER_EVENTS uem_timer_table[MAX_UEM_EVENT_TIMER];
extern stack_timer_struct uem_base_timer;
extern event_scheduler *event_scheduler_uem_ptr;

#if 0
#if defined(__USB_IN_NORMAL_MODE__) || defined(PICTBRIDGE_SUPPORT)
/* under construction !*/
#endif /* defined(__USB_IN_NORMAL_MODE__) || defined(PICTBRIDGE_SUPPORT) */ 
#endif

#ifdef __CLASSAB_VOLUME_PROTECTION__
extern const kal_uint32 ADC_MED_QUICK_EVAL_PERIOD;  
extern const kal_uint32 ADC_MED_QUICK_EVAL_COUNT;
extern const kal_uint32 ADC_MED_NORMAL_EVAL_PERIOD;  
extern const kal_uint32 ADC_MED_NORMAL_EVAL_COUNT;
#endif

/***************************************************************************** 
* External Function
*****************************************************************************/
extern kal_uint8 uem_rtc_alarm_format_convert(rtc_alarm_format_enum rtc_alarm_id);

extern kal_uint8 uem_rtc_clock_format_convert(rtc_clock_format_enum rtc_clock_id);

extern battery_status_enum uem_battery_status_convert(kal_uint8 status_type);

extern void uem_set_poweron_mode(kal_uint8 mode);

extern kal_uint8 uem_get_poweron_mode(void);

extern void uem_set_bat_status(uem_bmt_struct bmt_status);

extern void uem_get_bat_status(uem_bmt_struct *bmt_status);

extern kal_uint8 uem_vbat_level_convert(kal_int32 vbat);

extern void uem_set_silent_mode(kal_bool silent_mode);

extern kal_uint8 uem_get_silent_mode(void);

extern void uem_set_alert_mode(kal_uint8 alert_mode);

extern kal_uint8 uem_get_alert_mode(void);

extern void uem_get_greeting_text
    (kal_uint8 *mode, kal_uint8 *text_dcs, kal_uint8 *greeting_text, kal_uint8 *text_no);

extern void uem_set_greeting_text(kal_bool mode, kal_uint8 text_dcs, kal_uint8 *greeting_text, kal_uint8 no_text);

extern void uem_get_equip_id(kal_uint8 equip_id, kal_uint8 *equip_string);

extern void uem_set_gpio_status(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level);

extern kal_uint8 uem_get_gpio_status(kal_uint8 gpio_dev_type);

extern void uem_audio_set_mute(kal_uint8 audio_device, kal_bool mute_onoff);

extern kal_bool uem_audio_get_mute(kal_uint8 audio_device);

extern void uem_set_datetime_format(kal_bool is_date_set, kal_uint8 format);

extern kal_uint8 uem_get_datetime_format(kal_bool is_date_set);

extern void uem_set_state(uem_status_enum state);

extern kal_uint8 uem_get_state(void);

extern void uem_alarm_set_time(kal_uint8 rtc_alarm_id, rtc_alarm_info_struct alarm_info);

extern void uem_rtc_delete(kal_uint8 rtc_type, kal_uint8 rtc_alarm_id);

extern kal_uint32 uem_get_vbat_percentage(void);

#ifdef __USB_ENABLE__
extern kal_uint8 uem2l4_usb_detect_action_convert(kal_uint8 action);
extern kal_uint8 uem2l4_usb_config_action_convert(kal_uint8 action);
extern kal_uint8 uem2drv_usb_config_action_convert(kal_uint8 action);
#endif /* __USB_ENABLE__ */ 

/* send message utility */
extern void uem_send_msg_to_l4c(msg_type msg_name, void *data_ptr);

extern void uem_send_msg_to_nvram(msg_type msg_name, kal_uint16 ef_id, void *data_ptr, kal_uint16 length);

extern void uem_send_msg_to_sat(kal_uint32 src_mod_id, msg_type msg_name, void *data_ptr);

extern void uem_send_msg_to_aud(kal_uint32 msg_name, ...);

extern void uem_send_msg_to_bmt(kal_uint32 msg_name, ...);

extern void uem_send_msg_to_aux(kal_uint32 msg_name, ...);

extern void uem_send_msg_to_usbms(kal_uint32 msg_name, ...);

extern void uem_send_msg_to_uem(kal_uint32 msg_name, ...);

/* UEM timer utility */
extern void uem_timer_init(void);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
extern void uem_start_timer(kal_uint8 nTimerId, UEM_TIMER_FUNC_PRT timer_expiry, kal_uint32 nTimeDurationInTicks);

extern void uem_stop_timer(kal_uint8 nTimerId);

extern void uem_send_msg_to_l1(msg_type msg_id, void *local_data_ptr);

extern void uem_genernal_send_msg(kal_uint16 msg_id, kal_uint32 src_mod, kal_uint16 dest_mod, void *data_ptr);

extern void uem_set_audio_loopback(audio_loopback_mode_enum mode);
extern void uem_set_gain(kal_uint8 type, kal_uint8 gain);
extern void uem_set_loopback(kal_bool on);

extern kal_bool uem_get_charging_complete_status(void);
extern kal_bool uem_get_charging_status(void);
extern kal_bool uem_get_clam_status(void);

/* For HAL*/
/* For RTC*/
extern void uem_rtc_config(kal_uint8 AL_EN,kal_uint8 TC_EN);
extern void uem_rtc_gettime(RTC_CTRL_GET_TIME_T *time);
extern kal_bool uem_rtc_getaltime(RTC_CTRL_GET_ALARM_TIME_T *time);
extern void uem_rtc_settime(RTC_CTRL_SET_TIME_T *time);
extern void uem_rtc_setalarmtime(RTC_CTRL_SET_ALARM_TIME_T *time);
extern kal_bool uem_rtc_istimevalid(RTC_CTRL_IS_TIME_VALID_T *time);
/* For PMU*/
extern void uem_drv_power_off(void);
extern void uem_drv_power_on(void);
extern void uem_drv_set_power_on_mode(kal_uint8 mode);
extern void uem_drv_switch2idle_flag(void);
/* UART*/
extern void uem_uart_turnon_power(UART_PORT port, kal_bool on);

#ifdef __VIBRATION_SPEAKER_SUPPORT__
extern void uem_gpio_spkvib_enable(kal_bool enable);
#endif

#endif /* _UEM_UTILITY_H */ /* uem_utility.h */

