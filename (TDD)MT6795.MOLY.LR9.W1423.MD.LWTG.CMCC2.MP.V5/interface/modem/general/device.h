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
 * DEVICE.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for definition of all hardware device requirement.
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

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


#ifndef _DEVICE_H
#define _DEVICE_H

/***************************************************************************** 
* Include
*****************************************************************************/
#include "kal_general_types.h"
//#include "pmic6318_sw.h"
#include "ps_public_struct.h"
#include "dcl.h"

/***************************************************************************** 
* Define
*****************************************************************************/
/* Add by Yuchuan */
#define UEM_GREETING_LEN      62
#define UEM_EQUIP_ID_LEN      30

/* Define the ring compose capability */
#define MAX_RING_COMPOSE_NUM        5
#define MAX_RING_COMPOSE_LEN        300

/* Define the display text maximum len */
#define UEM_DISPLAY_TEXT_LEN  30
#define UEM_MAX_GREETING_LEN  30

/* For UEM GPIO*/
#define MAX_LED_GPIO       3    /* 3 LED lights */
#define MAX_LCD_BACKLIGHT  1    /* 1 backlight */
#define MAX_VIBRATOR       1    /* 1 vibrator */

#define GPIO_INVAILD   0x0
#define GPIO_VAILD     0x01
#define GPO_VAILD        0x02
#define MAX_NETNAME_TEXT 32

//#ifdef __CUST_NEW__
#define GPIO_INVALID   GPIO_INVAILD
#define GPIO_VALID     GPIO_VAILD
#define GPO_VALID      GPO_VAILD
//#endif /* __CUST_NEW__ */ 

/***************************************************************************** 
* Typedef
*****************************************************************************/
typedef enum {
   L4_BCD = 0x01,
   L4_ASCII = 0x04,
   L4_UCS2 = 0x08
} L4_charset_enum;


typedef enum {
   MMI_PS_AT_LANG_DEFAULT,
   MMI_PS_AT_LANG_UNKWN,
   MMI_PS_AT_LANG_EN,
   MMI_PS_AT_LANG_TW,
   MMI_PS_AT_LANG_ZH,
   MMI_PS_AT_LANG_LAST
} L4_AT_lang_enum;

typedef enum {
    L4_WB_AUDIO_INPUT_FIR,
    L4_WB_AUDIO_OUTPUT_FIR,
    L4_WB_ADUIO_MODE_PARAM
}l4_wb_audio_para_action_enum;
/***************************************************************************** 
* Audio Interface 
*****************************************************************************/
   
/* Define the audio device type */
typedef enum {
    AUDIO_DEVICE_SPEAKER = 0  ,     /* Tone, Keypad sound to play on audio device. */
    AUDIO_DEVICE_MICROPHONE   ,     /* Microphone sound to send on audio device. */
    AUDIO_DEVICE_BUZZER       ,     /* Ring tone sound to play on audio device. */
    AUDIO_DEVICE_GMI          ,     /* MIDI/Melody sound to play on audio device */
    AUDIO_DEVICE_SPEAKER2     ,     /* earphone, carkit */
    AUDIO_DEVICE_LOUDSPEAKER  ,     /* loudspeaker for free sound */
    AUDIO_DEVICE_SPEAKER_BOTH ,
    MAX_AUDIO_DEVICE_NUM      
}audio_type_enum;


/* Define the audio device type */
typedef enum {
    AUDIO_DEVICE_MIC1 = 0 ,    /* ME */
    AUDIO_DEVICE_MIC2     ,    /* Headset */
    AUDIO_DEVICE_FMRR     ,     /* FM Radio */
    AUDIO_DEVICE_MIC3          /* Loud Spkear */
}audio_input_path_enum;


/* Define volume category */
typedef enum {
    VOL_NORMAL   = 0 ,
    VOL_HEADSET      ,  
    VOL_HANDFREE     ,  
    MAX_VOL_CATE,
    VOL_TV_OUT = MAX_VOL_CATE
}volume_category_enum;


/* Define volume type.*/
typedef enum {
    VOL_TYPE_CTN  = 0 ,   /* MMI can apply to associate volume; call tone attribute */
    VOL_TYPE_KEY      ,   /* MMI can apply to associate volume; keypad tone attribute */
    VOL_TYPE_MIC      ,   /* microphone attribute */
    VOL_TYPE_GMI      ,   /* MMI can apply to associate volume; melody, imelody, midi attribute */
    VOL_TYPE_SPH      ,   /* MMI can apply to associate volume; speech sound attribute */
    VOL_TYPE_SID	  ,   /* side tone attribute */
    VOL_TYPE_MEDIA    ,   /* MMI can apply to associate volume; As MP3, Wave,... attribute */
    MAX_VOL_TYPE           
}volume_type_enum;


/* Volume level. based index is from 0..(MAX_VOL_LEVEL-1) */
#define MAX_VOL_LEVEL               7



/* Define the audio play style. */
typedef enum {
    DEVICE_AUDIO_PLAY_CRESCENDO  = 0 ,  /* Play sound for crescendo. */
    DEVICE_AUDIO_PLAY_INFINITE       ,  /* Play sound for infinite. */
    DEVICE_AUDIO_PLAY_ONCE           ,  /* Play sound for once. */
    DEVICE_AUDIO_PLAY_DESCENDO         /* Play sound for descendo. */
}audio_play_style_enum;


typedef struct {
   kal_uint8 first_out_amp[MAX_AUDIO_DEVICE_NUM][MAX_VOL_LEVEL];
   kal_uint8 second_out_amp[MAX_AUDIO_DEVICE_NUM][MAX_VOL_LEVEL];
   kal_uint8 side[MAX_AUDIO_DEVICE_NUM][MAX_VOL_LEVEL];
   kal_uint8 volume[MAX_AUDIO_DEVICE_NUM];
} acoustic_gain_struct;


/***************************************************************************** 
* Keypad  Interface 
*****************************************************************************/

/* Define the keypad status. */
typedef enum {
    KEY_PRESSED        = 0   /* Keypad is pressed. */
    ,KEY_RELEASED            /* Keypad is released. */
    ,KEY_LONGPRESS           /* Keypad is longpressed. */
    ,KEY_REPEATED            /* Keypad is repeated. */
#ifdef TWO_KEY_ENABLE
    ,KEY_PRESSED_TWOKEY      /* Two Keypad is pressed. */
    ,KEY_RELEASED_TWOKEY     /* Two Keypad is released. */
#endif   /*TWO_KEY_ENABLE*/
}keypad_status_enum;


/* Define the keypad code value. */
typedef kal_uint8 keypad_code_enum;


/***************************************************************************** 
* RTC  Interface 
*****************************************************************************/

/* Define the RTC type. */
typedef enum {
    RTC_TIME_CLOCK_IND  = 0 , /* The time clock indication. */
    RTC_ALARM_IND             /* The alarm indication */
}rtc_type_enum;


/* Define the type to setting RTC. */
typedef enum {
    RTC_SETTING_TYPE_DATETIME  = 0 , 
    RTC_SETTING_TYPE_DATE          ,
    RTC_SETTING_TYPE_TIME             
}rtc_setting_type_enum;

/* Define the RTC alarm id. */
typedef kal_uint8 rtc_alarm_id_enum;
#define RTC_ALARM1_IND     0 /* The alarm indication */
#define RTC_ALARM2_IND     1 /* The alarm indication */
#define RTC_ALARM3_IND     2 /* The alarm indication */
#define MAX_ALARM_NUM      3

/* Define the Alarm type */
typedef enum {
    RTC_ALARM_VIBRATOR  = 0x01 , 
    RTC_ALARM_LED       = 0x02 , 
    RTC_ALARM_SOUND     = 0x04 , 
    RTC_ALARM_SILENT    = 0x08 
}rtc_alarm_type_enum;


/* Define the Alarm recurr */
typedef enum {
 RTC_ALARM_DAY1    = 0x01 ,
 RTC_ALARM_DAY2    = 0x02 ,
 RTC_ALARM_DAY3    = 0x04 ,
 RTC_ALARM_DAY4    = 0x08 ,
 RTC_ALARM_DAY5    = 0x10 ,
 RTC_ALARM_DAY6    = 0x20 ,
 RTC_ALARM_DAY7    = 0x40 ,
 RTC_ALARM_DAY_ALL = 0x7F
}rtc_alarm_recurr_enum;

/* Define the Date/Time format type. */
typedef enum {
    DATE_DD_MMM_YYYY  = 1 
/*
    ,DATE_DD_MM_YY_H     
    ,DATE_MM_DD_YY       
    ,DATE_DD_MM_YY_S     
    ,DATE_DD_MM_YY_P     
    ,DATE_YYMMDD         
    ,DATE_YY_MM_DD       
*/

    ,DATE_DD_MM_YYYY_S 	  = 8
    ,DATE_MM_DD_YYYY_S		
    ,DATE_YYYY_MM_DD_S		
    ,DATE_YYYY_MM_DD_H		
    ,DATE_MMM_DD_YYYY		
}date_format_enum;


#define   DATE_AUX_YY_MM_DD   1
#define   DATE_AUX_YYYY_MM_DD 2


typedef enum {
    TIME_HH_MM_24 = 1 ,
    TIME_HH_MM_12    
}time_format_enum;


/* Define the RTC clock/alarm format type. */
/* Could be rtc_alarm_format_enum or rtc_clock_format_enum */
typedef kal_uint8 rtc_format_enum; 


/*Y:Year,M:Month,W:DOW,D:DOM,H:Hour,M:Min,S:SEC*/
typedef enum {
    DEVICE_AL_EN_None     = 0 ,
    DEVICE_AL_EN_ChkS         ,
    DEVICE_AL_EN_ChkMS        ,
    DEVICE_AL_EN_ChkHMS       ,
    DEVICE_AL_EN_ChkDHMS      ,
    DEVICE_AL_EN_ChkWHMS      ,
    DEVICE_AL_EN_ChkMDHMS     ,
    DEVICE_AL_EN_ChkYMDHMS    ,
    DEVICE_AL_EN_NoChange    
}rtc_alarm_format_enum;


typedef enum {
    DEVICE_TC_EN_None    = 0 ,
    DEVICE_TC_EN_ChkS        ,
    DEVICE_TC_EN_ChkM        ,
    DEVICE_TC_EN_ChkH        ,
    DEVICE_TC_EN_ChkD        ,
    DEVICE_TC_EN_ChkW        ,
    DEVICE_TC_EN_ChkMon      ,
    DEVICE_TC_EN_ChkY        ,
    DEVICE_TC_EN_NoChange        
}rtc_clock_format_enum;

/* Define the alarm status. */
typedef enum {
    ALARM_STATUS_ON_POWEROFF_CHARING  =0 , /* The alarm is started when it's power off with charging status. */
    ALARM_STATUS_ON_POWEROFF             , /* The alarm is started when it's power off status without charging. */
    ALARM_STATUS_ON_POWERON                /* The alarm is started when it's power on status. */
}alarm_status_enum;


/* Define the calling status */
typedef enum {
  UEM_CALL_UNKNOW     = 0 ,
  UEM_CALL_SETUP          , 
  UEM_CALL_CONNECT        ,
  UEM_CALL_DISCONNECT           
}uem_call_state_enum;


/***************************************************************************** 
* GPIO / EINT  Interface 
*****************************************************************************/

/* Define the internal GPIO device type. */
/* Becareful!!!! 
   MAX_GPIO_DEVICE_NUM Will impact the size of uem_context_rmi_struct data item !!!!! */

typedef enum {
    GPIO_DEV_LED_MAINLCD   = 0 ,  /* Main LCD backlight */
    GPIO_DEV_LED_SUBLCD        ,  /* Sub LCD backlight */
    GPIO_DEV_LED_STATUS_1      ,  /* Status LED  R*/
    GPIO_DEV_LED_STATUS_2      ,  /* Status LED  G*/
    GPIO_DEV_LED_STATUS_3      ,  /* Status LED   B*/
    GPIO_DEV_LED_KEY           ,  /* Keypad backlight */
    GPIO_DEV_VIBRATOR          ,  /* Vibrator */
    GPIO_DEV_FLASHLIGHT        ,  /* FlashLight */
    GPIO_DEV_FTE_FEEDBACK_VIB  ,  /* Reserve_1 */
    GPIO_DEV_LED_BACKLIGHT_DIMMING,  /* Reserve_2 */
    GPIO_DEV_RESERVED3         ,  /* Reserve_3 */
    GPIO_DEV_RESERVED4         ,  /* Reserve_4 */
    GPIO_DEV_RESERVED5         ,  /* Reserve_4 */
    GPIO_DEV_RESERVED6         ,  /* Reserve_4 */
    GPIO_DEV_RESERVED7         ,  /* Reserve_4 */
    GPIO_DEV_RESERVED8         ,  /* Reserve_4 */
    GPIO_DEV_RESERVED9         ,  /* Reserve_4 */
    GPIO_DEV_RESERVED10        ,  /* Reserve_4 */
    GPIO_DEV_RESERVED11        ,  /* Reserve_4 */
    GPIO_DEV_RESERVED12        ,  /* Reserve_4 */
    MAX_GPIO_DEVICE_NUM           
}gpio_device_enum;


/* Define the LED light level. For LCD bright level, Keypad backlight,  Flashlight */
typedef enum {
    LED_LIGHT_LEVEL0   =0  ,  /* turn off */
    LED_LIGHT_LEVEL1       ,
    LED_LIGHT_LEVEL2       ,
    LED_LIGHT_LEVEL3       ,
    LED_LIGHT_LEVEL4       ,
    LED_LIGHT_LEVEL5       ,
#if defined (WISDOM_MMI)
    LED_LIGHT_LEVEL6       ,
#endif
    LED_LIGHT_LEVEL_MAX     
}gpio_device_led_level_typedef;

typedef enum
{
    /* LED status pattern */
    LED_PATTERN_BEGIN,

    LED_POWER_ON = LED_PATTERN_BEGIN,
    LED_POWER_OFF,
    LED_BATTERY_WARNING,
    LED_BATTERY_LOW,
    LED_Connect900,
    LED_Connect1800,
    LED_OnCharging,
    LED_FullCharging,
    LED_MessageIn,
    LED_MessageRemind,
    LED_Caller1,
    LED_Caller2,
    LED_Caller3,
    LED_Caller4,
    LED_Caller5,
    LED_Caller6,
    LED_LimitService,
    LED_NoService,
    LED_Connect1900,
    LED_Roaming,
    LED_PATTERN_END = 50,

    /* lcd backlight pattern */
    LCD_PATTERN_BEGIN,
    LCD_PATTERN_1 = LCD_PATTERN_BEGIN,
    LCD_PATTERN_2,
    LCD_PATTERN_END = 100,

    /* vibrator pattern */
    VIB_PATTERN_BEGIN,
    VIB_PATTERN_1 = VIB_PATTERN_BEGIN,
    VIB_PATTERN_2,
    VIB_PATTERN_3,  /* Incomming SMS */
    VIB_PATTERN_4,  /* FTE feedback*/
    VIB_PATTERN_A,
    VIB_PATTERN_B,
    VIB_PATTERN_C,
    VIB_PATTERN_END = 150,

    MAX_PATTERN_ID = VIB_PATTERN_END
} PATTERN_ID;

typedef enum
{
    PLAY_STOP,
    PLAY_REPEAT,
    PLAY_ONCE,
    MAX_PATTERN_TYPE = PLAY_ONCE
} PATTERN_TYPE;

typedef struct
{
    kal_uint8 gpio_control[MAX_LED_GPIO];
    kal_uint16 duration_time;   /* max time 65535 msec */
} LED_PATTERN_STRUCT;

typedef struct
{
    kal_uint8 gpio_control[MAX_LCD_BACKLIGHT];
    kal_uint16 duration_time;   /* max time 65535 msec */
} LCD_PATTERN_STRUCT;

typedef struct
{
    kal_uint8 gpio_control[MAX_VIBRATOR];
    kal_uint16 duration_time;   /* max time 65535 msec */
} VIB_PATTERN_STRUCT;

extern LCD_PATTERN_STRUCT *custom_get_lcd_patterns(PATTERN_ID lcd_pattern_id);
extern LED_PATTERN_STRUCT *custom_get_led_patterns(PATTERN_ID led_pattern_id);
extern VIB_PATTERN_STRUCT *custom_get_vib_patterns(PATTERN_ID vib_pattern_id);
extern kal_bool uem_play_pattern(PATTERN_ID pattern_id, PATTERN_TYPE pattern_type);
extern kal_uint8 custom_get_led_label(kal_uint8 id);
extern kal_uint8 custom_get_lcd_label(kal_uint8 id);
extern kal_uint8 custom_get_vib_label(kal_uint8 id);
extern void custom_uem_set_rmi_lang_id(kal_uint8 *lang_id);
extern kal_bool custom_uem_gpio_set_level(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level);
extern kal_uint8* custom_uem_get_equip_id(kal_uint8 equip_id);
#ifdef __VIBRATION_SPEAKER_SUPPORT__
typedef  void (*custom_uem_spkvib_func)(kal_bool);
extern void custom_uem_set_spkvib_func(void (*func)(kal_bool));
#endif
extern kal_uint32 custom_uem_get_bl_level_num(void);
extern kal_uint32 custom_uem_get_pwm_bl_mode(kal_uint8 gpio_dev_type);

/* It is a time from backlight dimming to backlight drak*/
#define GPIO_BRIGHTNESS_DIMMING_TIME    5000

/* Define the Vibrator level. */
typedef enum {
    VIBRATOR_OFF  =0 ,  /* turn off */
    VIBRATOR_ON         /* turn on */     
}gpio_device_vibrator_level_typedef;


typedef enum {
    AUD_MODE_NORMAL   =0 , /* Normal Mode */
    AUD_MODE_HEADSET     , /* HeadSet (Earphone) Mode */
    AUD_MODE_LOUDSPK     , /* Loudspeaker Mode */
    MAX_AUD_MODE_NUM     
}audio_mode_enum;


/* Define the external GPIO device interrupt. */
typedef enum {
    EXT_DEV_NONE      = 0  , /* None, if there is no external device */
    EXT_DEV_HANDFREE       , /* Hand-free */
    EXT_DEV_EARPHONE       , /* Earphone */
    EXT_DEV_CARKIT         , /* Car-Kit */
    EXT_DEV_KEY_1          , /* Send Key */
    EXT_DEV_KEY_2          , /* Reserved */
    EXT_DEV_UART           , 
    EXT_DEV_CLAM_OPEN  = 8 ,
    EXT_DEV_CLAM_CLOSE     , 
    EXT_DEV_HOOK_ON	   , /* for FWP */
    EXT_DEV_HOOK_OFF	   , /* for FWP */
    EXT_DEV_AUX_DETECT_DONE	   , 
    EXT_DEV_TRANSMITTER_HOLD_ON,
    EXT_DEV_TRANSMITTER_PUT_DOWN,
    MAX_EXT_DEVICE_NUM   
}ext_device_enum;


typedef enum {
    AUD_LOOPBACK_MODE_NORMAL       =0 , /* Normal Mode */
    AUD_LOOPBACK_MODE_HEADSET_PREFER  , /* Loudspk_prefer */		
    AUD_LOOPBACK_MODE_HEADSET         , /* HeadSet (Earphone) Mode */
    AUD_LOOPBACK_MODE_LOUDSPK         , /* Loudspeaker Mode */
    MAX_AUD_LOOPBACK_MODE_NUM     
}audio_loopback_mode_enum;


/**************************************************************
  **
  **      Set UART Port Function Type
  ** 
  **************************************************************/
typedef enum
{
   UART_NVRAM_LID_FUNC_UART_CONFIG,
   UART_NVRAM_LID_FUNC_HIGH_SPEED_SIM,
   UART_NVRAM_LID_FUNC_SWDBG,
   UART_NVRAM_LID_FUNC_UART_POWER,
   UART_NVRAM_LID_FUNC_TST_OUTPUT_MODE,
   UART_NVRAM_LID_FUNC_USB_LOGGING
} uart_nvram_lid_function_enum;


/***************************************************************************** 
* PMIC  Interface 
*****************************************************************************/
typedef enum
{
   PMIC_VBAT_STATUS,    /* Notify the battery voltage, BMT_VBAT_STATUS */
   PMIC_CHARGER_IN,     /* Charger plug in, BMT_CHARGER_IN */
   PMIC_CHARGER_OUT,    /* Charger plug out, BMT_CHARGER_OUT */
   PMIC_OVERVOLPROTECT,    /* The voltage of battery is too high. BMT_OVERVOLPROTECT */
   PMIC_OVERBATTEMP,    /* The temperature of battery is too high. BMT_OVERBATTEMP */
   PMIC_LOWBATTEMP,     /* The temperature of battery is too low. BMT_LOWBATTEMP */
   PMIC_OVERCHARGECURRENT, /* Charge current is too large. BMT_OVERCHARGECURRENT */
   PMIC_CHARGE_COMPLETE,   /* Charge is completed. BMT_CHARGE_COMPLETE */
   PMIC_INVALID_BATTERY,    /* invalid battery  BMT_INVALID_BAT*/
   PMIC_INVALID_CHARGER,   /* invalid charger BMT_INVALID_CHARGER*/
   PMIC_CHARGING_TIMEOUT, /* Bad battery BMT_CHARGE_TIMEOUT */ 
   PMIC_LOWCHARGECURRENT, /* Charge current is too Low. BMT_LOWCHARGECURRENT */
   PMIC_CHARGE_BAD_CONTACT, /* Charger Bad Contact */
   PMIC_BATTERY_BAD_CONTACT, /* Battery Bad Contact */
   PMIC_USB_CHARGER_IN,   /* Usb Charger plug in */
   PMIC_USB_CHARGER_OUT,   /* Usb Charger plug out */
   PMIC_USB_NO_CHARGER_IN,
   PMIC_USB_NO_CHARGER_OUT,
   PMIC_BATTERY_IN,
   PMIC_BATTERY_OUT
} pmic_status_enum;
typedef pmic_status_enum battery_status_enum;

typedef enum 
{
   BATTERY_LOW_POWEROFF = 0,
   BATTERY_LOW_TX_PROHIBIT,
   BATTERY_LOW_WARNING,
   BATTERY_LEVEL_0,
   BATTERY_LEVEL_1,
   BATTERY_LEVEL_2,
   BATTERY_LEVEL_3, 
   BATTERY_LEVEL_4 = BATTERY_LEVEL_3, /* BATTERY_LEVEL_4 */
   BATTERY_LEVEL_5 = BATTERY_LEVEL_3, /* BATTERY_LEVEL_5 */
   BATTERY_LEVEL_6 = BATTERY_LEVEL_3, /* BATTERY_LEVEL_6 */
   BATTERY_LEVEL_LAST = 9

} battery_level_enum;


/* Define the power on status. */
typedef enum 
{
	POWER_ON_KEYPAD	     = 0 ,
	POWER_ON_ALARM			 ,
	POWER_ON_CHARGER_IN		 ,
	POWER_ON_EXCEPTION		 ,
	POWER_ON_USB			 ,
	POWER_ON_UNINIT			 ,
	POWER_ON_PRECHARGE	 = 8
} power_on_status_enum;

#define	POWERON(mode) (	(mode == POWER_ON_KEYPAD) || \
									(mode == POWER_ON_ALARM) || \
									(mode == POWER_ON_CHARGER_IN) ||\
									(mode == POWER_ON_USB) ||\
									(mode == POWER_ON_EXCEPTION) ||\
									(mode == POWER_ON_PRECHARGE) )

extern power_on_status_enum uem_get_power_on_mode(void);

/* Define the POWER reset type. This is to use for the power restablish, while it's on charging or alarm status. */
typedef enum
{
   NORMAL_RESET,
   CHARGING_RESET,
   ALARM_RESET,
   WM_RESET
} pmic_reset_type_enum;

typedef enum
{
	PMIC_GET_CHR_STATE
	,PMIC_GET_AC_USB
	,PMIC_GET_LED_CONFIG
	,PMIC_GET_RGB_DIM
	,PMIC_GET_BL_DIM
	,PMIC_GET_SPEAKER_STATE
	,PMIC_GET_SPEAKER_GAIN
	,PMIC_GET_MISC_LDO_STATE
	,PMIC_READ_REG
	,PMIC_WRITE_REG
	,PMIC_CHR_ENABLE
	,PMIC_CHR_CURRENT_CTRL
	,PMIC_USB_CHR_ENABLE
	,PMIC_LED_ENABLE
	,PMIC_LED_CONFIG
	,PMIC_RGB_DIM_CLK
	,PMIC_CHR_PUMP_ENABLE
	,PMIC_CHR_PUMP_CURRENT
	,PMIC_BL_DIM_CLK
	,PMIC_BL_DIV_BYPASS
	,PMIC_SPEAKER_ENABLE
	,PMIC_SPEAKER_GAIN
	,PMIC_VIBRATOR_ENABLE
	,PMIC_VIBRATOR_SEL
	,PMIC_VMC_ENABLE
	,PMIC_VMC_SEL
	,PMIC_VASW_ENABLE
	,PMIC_VASW_SEL
	,PMIC_USB_REG_ENABLE
	,PMIC_VBAT_ENABLE
	,PMIC_ISENSE_ENABLE
	,PMIC_BL_PWM
	,PMIC_MAX_NUM
}pmic_config_req_enum;

/***************************************************************
  **   FM Radio
  ***************************************************************/
typedef enum
{
    FM_RADIO_CMD_MONO = 0,
    FM_RADIO_CMD_STEREO,
    FM_RADIO_CMD_RSSI,
    FM_RADIO_CMD_IF_COUNT,
    FM_RADIO_CMD_RSSI_INFO
}fm_radio_config_cmd_enum;

typedef enum
{
    FM_RADIO_COMMON_DISABLE = 0,
    FM_RADIO_COMMON_ENABLE,      /* in mono, only represent enable; in stereo, represent enable + sblend On */
    FM_RADIO_COMMON_ENABLE_EXTRA   /* in stereo, represent enable + sblend Off */
}fm_radio_common_state_enum;

/***************************************************************
  **   RF Test Tool -- GSM 
  ***************************************************************/
typedef enum
{
    RF_TEST_GSM_TX_BAND_850,
    RF_TEST_GSM_TX_BAND_900,
    RF_TEST_GSM_TX_BAND_1800,
    RF_TEST_GSM_TX_BAND_1900
}rf_test_gsm_tx_band_enum;
  
typedef enum
{
    RF_TEST_GSM_STOP,
    RF_TEST_GSM_TX_TEST,
    RF_TEST_GSM_RX_TEST,
    RF_TEST_GSM_POWER_SCAN
}rf_test_gsm_req_enum;

/***************************************************************
  **   RF Test Tool -- WiFi 
  ***************************************************************/

typedef enum
{
    RF_TEST_WIFI_STOP,
    RF_TEST_WIFI_TEST_MODE,
    RF_TEST_WIFI_NORMAL_MODE,
    RF_TEST_WIFI_TX_GET_DAC_OFFSET,
    RF_TEST_WIFI_TX_OUTPUT_POWER,
    RF_TEST_WIFI_TX_CARRIER_SUPP,
    RF_TEST_WIFI_TX_LOCAL_FREQ,
    RF_TEST_WIFI_TX_CONT_PKT,
    RF_TEST_WIFI_RX_CONT_PKT,
    RF_TEST_WIFI_POWER_SAVE,
    RF_TEST_WIFI_REG_MCR32_WRITE,
    RF_TEST_WIFI_REG_MCR32_READ,
    RF_TEST_WIFI_REG_MCR16_WRITE,
    RF_TEST_WIFI_REG_MCR16_READ,
    RF_TEST_WIFI_REG_BBCR_WRITE,
    RF_TEST_WIFI_REG_BBCR_READ,
    RF_TEST_WIFI_REG_EEPROM_WRITE,
    RF_TEST_WIFI_REG_EEPROM_READ,
    RF_TEST_WIFI_REG_EFUSE_WRITE,
    RF_TEST_WIFI_REG_EFUSE_READ
}rf_test_wifi_req_enum;

/***************************************************************************** 
* Misc  Interface 
*****************************************************************************/
/* Indicator data type */
typedef enum 
{
    IND_BATTCHG  = 0 ,
    IND_SIGNAL       ,  
    IND_SERVICE      ,  
    IND_SOUNDER      ,  
    IND_MESSAGE      ,  
    IND_CALL         ,  
    IND_VOX          ,  
    IND_ROAM         ,  
    IND_SMSFULL       
} indicator_type_enum;


/* Define the equipment to return the string mapping. */
typedef enum 
{
    EQ_ME_MANUFACTURE_ID      = 0 ,
    EQ_ME_MODEL_ID                ,
    EQ_ME_REVISION_ID             ,
    EQ_ME_SERIAL_NUMBER_ID        ,
    EQ_ME_SERIAL_NUMBER_SIM2_ID   ,
    EQ_ME_GLOBAL_OBJECT_ID        ,
    EQ_ME_MANUFACTURE_INFO_ID     ,
    EQ_ME_COMP_CAP_LIST_ID        ,
    MAX_ME_ID_NUM                    
} equip_id_enum;


#define MAX_ME_ID_LEN               30


/* Define the device process status. */
typedef enum 
{
    DEV_OK                    = 0 , /* The device status is ok to process. */
    DEV_FAIL                      , /* The device status is fail to process*/
    DEV_FAIL_VM_NO_FREE_ENTRY     , /* voice mail fail cause */
    DEV_FAIL_VM_BUFFER_FULL       ,
    DEV_FAIL_VM_PLAY_NO_DATA     
} dev_status_enum;


/***************************************************************************** 
* USB  Interface 
*****************************************************************************/
typedef enum 
{
    DEVUSB_DETECT_ACTION_UNKNOWN = 0 ,
    DEVUSB_DETECT_ACTION_PLUGIN      , 
    DEVUSB_DETECT_ACTION_PLUGOUT     ,
    DEVUSB_DETECT_ACTION_USB_SUSPEND ,
    DEVUSB_DETECT_ACTION_MAX_ID   
} devusb_detect_action_enum;


typedef enum 
{
    DEVUSB_CFG_ACTION_UNKNOWN     =	0 ,
    DEVUSB_CFG_ACTION_CDC_ACM         ,
    DEVUSB_CFG_ACTION_MASS_STORAGE    ,
    DEVUSB_CFG_ACTION_MULTI_COM,
    DEVUSB_CFG_ACTION_WEBCAM          ,
    DEVUSB_CFG_ACTION_STOP_MS         ,
    DEVUSB_CFG_ACTION_IRDBG           ,
    DEVUSB_CFG_ACTION_PICTBRIGE       ,
    DEVUSB_CFG_ACTION_MTP       ,	
    DEVUSB_CFG_ACTION_STOP_MTP       ,	    
    DEVUSB_CFG_ACTION_MAX_ID			  
} devusb_cfg_action_enum;


typedef enum 
{
    USB_SWITCH_PORT_APP_DATA     = 0 ,
    USB_SWITCH_PORT_APP_DEBUG, 
    USB_SWITCH_PORT_APP_NULL 
} usb_switch_port_app_enum;

#if (defined(MT6229) || defined(MT6227) || defined(MT6228) || defined(MT6225) || defined(MT6268T) || defined(MT6268H) || defined(MT6230) || defined(MT6227D) || defined(MT6223)  || defined(MT6226D) || defined(MT6223P)) 
#if (defined(MT6227) || defined(MT6227D)  || defined(MT6226D))
typedef enum
{

    EM_SWDBG_OFF,
    EM_SWDBG_DSP_L1_PS,
    EM_SWDBG_L1_PS,
    EM_SWDBG_MCU,
    EM_SWDBG_RESET,
    EM_SWDBG_MAX
} EM_SWDBG_ITEM;

#elif defined(MT6228)
typedef enum
{

    EM_SWDBG_OFF,
    EM_SWDBG_DSP_L1_PS,
    EM_SWDBG_L1_PS,
    EM_SWDBG_MCU,
    EM_SWDBG_MCU_DSP,
    EM_SWDBG_RESET,
    EM_SWDBG_MAX
} EM_SWDBG_ITEM;

#else 
typedef enum
{

    EM_SWDBG_OFF,
    EM_SWDBG_DSP_L1,
    EM_SWDBG_DSP_PS,
    EM_SWDBG_L1_PS,
    EM_SWDBG_MCU,
    EM_SWDBG_MCU_DSP,
    EM_SWDBG_RESET,
    EM_SWDBG_MAX
} EM_SWDBG_ITEM;

#endif 
#endif /* #if (defined(MT6229) || defined(MT6227) || defined(MT6228) || defined(MT6225) || defined(MT6268T)|| defined(MT6268H) || defined(MT6230) || defined(MT6227D))  */ 

typedef enum
{
    EM_USB_LOGGING_NONE,
#ifdef __DSPIRDBG__    
    EM_USB_LOGGING_IRDBG,
#endif

#ifdef __MODEM_3G_LOGGING__
    EM_USB_LOGGING_3G_LOGGING,
#endif 

    EM_USB_LOGGING_MAX
} EM_USB_LOGGING_ITEM;


//#if defined(MT6223PMU)
/***************************************************************
  **   PMU6223
  ***************************************************************/
/* Enum */
typedef enum
{
    MT6223PMU_READ_REG
    ,MT6223PMU_WRITE_REG
    ,MT6223PMU_GET_CHR_STATUS
    ,MT6223PMU_SET_CHR_GET_CHR_EN
    ,MT6223PMU_SET_CHR_SET_CHR_EN
    ,MT6223PMU_SET_CHR_GET_CHR_CUR
    ,MT6223PMU_SET_CHR_SET_CHR_CUR    
    ,MT6223PMU_SET_CHR_GET_CHR_CUR_OFFSET
    ,MT6223PMU_SET_CHR_SET_CHR_CUR_OFFSET
//    ,MT6223PMU_SET_CHR_GET_OV_TH_FREEZE
//    ,MT6223PMU_SET_CHR_SET_OV_TH_FREEZE
    ,MT6223PMU_SET_CHR_GET_CV_THRESHOLD
    ,MT6223PMU_SET_CHR_SET_CV_THRESHOLD
    ,MT6223PMU_GET_DRIVER_INFO
    ,MT6223PMU_SET_DRIVER_INFO
    ,MT6223PMU_GET_LDO_VOLTAGE
    ,MT6223PMU_SET_LDO_VOLTAGE
    ,MT6223PMU_GET_LDO_ENABLE
    ,MT6223PMU_SET_LDO_ENABLE
    ,MT6223PMU_GET_BIAS_CURRENT
    ,MT6223PMU_SET_BIAS_CURRENT    
    
	,MT6223PMU_MAX_NUM
}EM_MT6223PMU_REQ_ENUM;


typedef enum 
{
   PMU6223_CHR_STATE_CHR_DET = 0,   
   PMU6223_CHR_STATE_BAT_ON,
   PMU6223_CHR_STATE_CV,
   PMU6223_CHR_STATE_CHR_OVP,
   PMU6223_CHR_STATE_CHARGING,
   PMU6223_CHR_STATE_MAX
}PMU6223_CHR_STATE;

typedef enum 
{
   PMU6223_CHR_CUR_OFFSET_P1 = 0,   
   PMU6223_CHR_CUR_OFFSET_P2,
   PMU6223_CHR_CUR_OFFSET_M2,
   PMU6223_CHR_CUR_OFFSET_M1
}PMU6223_CHR_CUR_OFFSET;

typedef enum 
{
   PMU6223_DRIVE_INFO_VIB = 0,   
   PMU6223_DRIVE_INFO_LED
}PMU6223_DRIVE_INFO;

typedef enum 
{
   PMU6223_LDO_VOLTAGE_VRF = 0,   
   PMU6223_LDO_VOLTAGE_VCORE,
   PMU6223_LDO_VOLTAGE_VM,
   PMU6223_LDO_VOLTAGE_VIO,
   PMU6223_LDO_VOLTAGE_VA,
   PMU6223_LDO_VOLTAGE_VTCXO,
   PMU6223_LDO_VOLTAGE_VSIM,
   PMU6223_LDO_VOLTAGE_VRTC1
//   PMU6223_LDO_VOLTAGE_VRTC2
}PMU6223_LDO_VOLTAGE_TYPE;

typedef enum 
{
   PMU6223_LDO_ENABLE_VRF = 0,   
   PMU6223_LDO_ENABLE_VTCXO,
   PMU6223_LDO_ENABLE_VSIM
}PMU6223_LDO_ENABLE;

typedef enum 
{
   PMU6223_BIAS_CALIBRATE_VRF = 0,   
   PMU6223_BIAS_CALIBRATE_VM,
   PMU6223_BIAS_CALIBRATE_VIO,
   PMU6223_BIAS_CALIBRATE_VSIM,
   PMU6223_BIAS_CALIBRATE_VCORE_CAL
}PMU6223_BIAS_CALIBRATE_TYPE;

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
#endif /* if 0 */

/***************************************************************
  **   PMU6238
  ***************************************************************/
/* Enum */
typedef enum
{
     MT6238PMU_READ_REG
    ,MT6238PMU_WRITE_REG
    ,MT6238PMU_GET_CHR_STATUS     
    ,MT6238PMU_SET_CHR_GET_CHR_EN
    ,MT6238PMU_SET_CHR_SET_CHR_EN
    ,MT6238PMU_SET_CHR_GET_CHR_CUR
    ,MT6238PMU_SET_CHR_SET_CHR_CUR    
    ,MT6238PMU_SET_CHR_GET_CHR_CUR_OFFSET
    ,MT6238PMU_SET_CHR_SET_CHR_CUR_OFFSET
    ,MT6238PMU_SET_CHR_GET_OV_TH_FREEZE    
    ,MT6238PMU_SET_CHR_SET_OV_TH_FREEZE
    ,MT6238PMU_SET_CHR_GET_CV_THRESHOLD
    ,MT6238PMU_SET_CHR_SET_CV_THRESHOLD
    ,MT6238PMU_GET_DRIVER_INFO
    ,MT6238PMU_SET_DRIVER_INFO
    ,MT6238PMU_GET_LDO_VOL_SEL_VBT    /* MC */
    ,MT6238PMU_SET_LDO_VOL_SEL_VBT    /* MC */
    ,MT6238PMU_GET_LDO_VOL_SEL_VCAMD  /* CAMERA */
    ,MT6238PMU_SET_LDO_VOL_SEL_VCAMD  /* CAMERA */
    ,MT6238PMU_GET_LDO_VOL_SEL_VCAMA  /* SW_A */
    ,MT6238PMU_SET_LDO_VOL_SEL_VCAMA  /* SW_A */
    ,MT6238PMU_GET_LDO_VOL_SEL_VSIM
    ,MT6238PMU_SET_LDO_VOL_SEL_VSIM
    ,MT6238PMU_GET_LDO_VOLTAGE_CAL
    ,MT6238PMU_SET_LDO_VOLTAGE_CAL
    ,MT6238PMU_GET_LDO_ENABLE
    ,MT6238PMU_SET_LDO_ENABLE
    ,MT6238PMU_GET_DC_CONTROL
    ,MT6238PMU_SET_DC_CONTROL
    ,MT6238PMU_GET_BIAS_CURRENT
    ,MT6238PMU_SET_BIAS_CURRENT    
    
	,MT6238PMU_MAX_NUM
}EM_MT6238PMU_REQ_ENUM;

typedef enum
{
    EM_MT6238PMU_OV_TH_FREEZE_AUTO = 0,
    EM_MT6238PMU_OV_TH_FREEZE_FIXED
} EM_MT6238PMU_OV_TH_FREEZE_TYPE;


typedef enum 
{
   PMU6238_CHR_CUR_OFFSET_P1 = 0,   
   PMU6238_CHR_CUR_OFFSET_P2,
   PMU6238_CHR_CUR_OFFSET_M2,
   PMU6238_CHR_CUR_OFFSET_M1
}PMU6238_CHR_CUR_OFFSET;

typedef enum 
{
   PMU6238_DRIVE_INFO_VIB = 0,   
   PMU6238_DRIVE_INFO_LED
}PMU6238_DRIVE_INFO;

typedef enum 
{
   PMU6238_LDO_VOLTAGE_VCORE = 0,    /* FBADJ */
   PMU6238_LDO_VOLTAGE_VCORE_SLEEP,  /* FBADJ_SLEEP */
   PMU6238_LDO_VOLTAGE_VRF,   
   PMU6238_LDO_VOLTAGE_VM,
   PMU6238_LDO_VOLTAGE_VIO,
   PMU6238_LDO_VOLTAGE_VA,
   PMU6238_LDO_VOLTAGE_VTCXO,
   PMU6238_LDO_VOLTAGE_VSIM,
   PMU6238_LDO_VOLTAGE_VRTC1,
   PMU6238_LDO_VOLTAGE_VRTC2,
   PMU6238_LDO_VOLTAGE_VUSB,   
   PMU6238_LDO_VOLTAGE_VBT,          /* VMC */
   PMU6238_LDO_VOLTAGE_VCAMD,        /* VCAMERA */
   PMU6238_LDO_VOLTAGE_VCAMA,        /* VSW_A */
   PMU6238_LDO_VOLTAGE_VSIM2
}PMU6238_LDO_VOLTAGE_TYPE;


typedef enum 
{
   PMU6238_LDO_ENABLE_VRF_ON_SEL = 0,   
   PMU6238_LDO_ENABLE_VRF_EN, 
   PMU6238_LDO_ENABLE_VTCXO_ON_SEL,
   PMU6238_LDO_ENABLE_VTCXO_EN,
   PMU6238_LDO_ENABLE_VUSB,
   PMU6238_LDO_ENABLE_VBT,          /* VMC */
   PMU6238_LDO_ENABLE_VCAM_D,       /* CAMERA */
   PMU6238_LDO_ENABLE_VCAM_A,       /* SW_A */
   PMU6238_LDO_ENABLE_VSIM1,
   PMU6238_LDO_ENABLE_VSIM2
}PMU6238_LDO_ENABLE;


typedef enum 
{
   PMU6238_DC_CONTROL_GAINP = 0,   
   PMU6238_DC_CONTROL_GAIN,
   PMU6238_DC_CONTROL_GAIND,
   PMU6238_DC_CONTROL_DIR_CTRL_EN,
   PMU6238_DC_CONTROL_DCVCK_SEL,
   PMU6238_DC_CONTROL_ISEL,
   PMU6238_DC_CONTROL_ADJCKSEL,
   PMU6238_DC_CONTROL_MODESET,
   PMU6238_DC_CONTROL_MODEEN,
   PMU6238_DC_CONTROL_PFMSEL_0_3,
   PMU6238_DC_CONTROL_PFMSEL_4_6,
   PMU6238_DC_CONTROL_IASEL,
   PMU6238_DC_CONTROL_SLEW_CTRL
}PMU6238_DC_CONTROL_TYPE;

typedef enum 
{
   PMU6238_BIAS_CALIBRATE_VRF = 0,   
   PMU6238_BIAS_CALIBRATE_VM,
   PMU6238_BIAS_CALIBRATE_VIO,
   PMU6238_BIAS_CALIBRATE_VA,
   PMU6238_BIAS_CALIBRATE_VTCXO,
   PMU6238_BIAS_CALIBRATE_VSIM,
   PMU6238_BIAS_CALIBRATE_VUSB,
   PMU6238_BIAS_CALIBRATE_VBT,
   PMU6238_BIAS_CALIBRATE_VCAMD,
   PMU6238_BIAS_CALIBRATE_VCAMA,
   PMU6238_BIAS_CALIBRATE_VSIM2
}PMU6238_BIAS_CALIBRATE_TYPE;

/***************************************************************
  **   PMU6326
  ***************************************************************/
/* Enum */
typedef enum
{
     MT6326PMU_READ_REG
    ,MT6326PMU_WRITE_REG    
	,MT6326PMU_MAX_NUM
}EM_MT6326PMU_REQ_ENUM;

/***************************************************************
  **   PMU6253
  ***************************************************************/
/* Enum */
typedef enum
{
     MT6253PMU_READ_REG
    ,MT6253PMU_WRITE_REG
    ,MT6253PMU_MAX_NUM    
}EM_MT6253PMU_REQ_ENUM;

#endif  /* _DEVICE_H */


