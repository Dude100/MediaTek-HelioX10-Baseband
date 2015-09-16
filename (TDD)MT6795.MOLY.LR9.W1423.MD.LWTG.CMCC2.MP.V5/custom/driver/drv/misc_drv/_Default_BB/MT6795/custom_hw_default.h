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

/* Configure which backlight source we use */
#define EXTERNAL_BL_DRIVER_SOURCE
//#define INTERNAL_BL_DRIVER_SOURCE

/* LED_MAINLCD PWM Configuration */
#define PWM_MAX_LEVEL 5

#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)
#define PWM_MAX_BACKLIGHT_LEVEL     20
#else
#define PWM_MAX_BACKLIGHT_LEVEL     PWM_MAX_LEVEL
#endif // End of #if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)

#if defined(EXTERNAL_BL_DRIVER_SOURCE)

// #define LED_MAINLCD_USE_PWM_1
// #define LED_MAINLCD_USE_PWM_2
#define LED_MAINLCD_USE_PWM_3
//#define LED_MAINLCD_USE_PWM_NONE

#if !defined(LED_MAINLCD_USE_PWM_NONE)

#define EXTERNAL_BL_DRIVER_STEPS    PWM_MAX_BACKLIGHT_LEVEL

#else

#define EXTERNAL_BL_DRIVER_STEPS    (16)

#endif

#elif defined(INTERNAL_BL_DRIVER_SOURCE)

// #define LED_MAINLCD_USE_PWM_1
#define LED_MAINLCD_USE_PWM_2
// #define LED_MAINLCD_USE_PWM_3
// #define LED_MAINLCD_USE_PWM_NONE

#endif // End of #if defined(__EXTERNAL_BL_DRIVER_SOURCE__)

/* LED_SUBLCD PWM Configuration */
// #define LED_SUBLCD_USE_PWM_1
// #define LED_SUBLCD_USE_PWM_2
// #define LED_SUBLCD_USE_PWM_3
#define LED_SUBLCD_USE_PWM_NONE

/* LED_KEY PWM Configuration */
#define LED_KEY_USE_PWM_1
// #define LED_KEY_USE_PWM_2
// #define LED_KEY_USE_PWM_3
// #define LED_KEY_USE_PWM_NONE

/* VIBRATOR PWM Configuration */
// #define VIBRATOR_USE_PWM_1
// #define VIBRATOR_USE_PWM_2
// #define VIBRATOR_USE_PWM_3
#define VIBRATOR_USE_PWM_NONE

#define LCD_CONTRAST_MAX_LEVEL 15
#define LCD_PARAM_MAX_LEVEL 5
#define BATTERY_MAX_LEVEL 10

extern const kal_uint8 DEFAULT_HARDWARE_YEAR;
extern const kal_uint8 DEFAULT_HARDWARE_MON;
extern const kal_uint8 DEFAULT_HARDWARE_DAY;

/* For AT command query voltage percentage */
#define BATLEV_MAX_IDX          0 /* 0: turn off, reference to BATLEV_MAX_VOLTAGE directly */
#define BATLEV_MAX_VOLTAGE 4200000


extern const kal_uint32 ADC_BOOTUP_EVAL_PERIOD;
extern const kal_uint32 ADC_BOOTUP_EVAL_COUNT;
extern const kal_uint32 ADC_IDLE_EVAL_PERIOD;
extern const kal_uint32 ADC_IDLE_EVAL_COUNT;
extern const kal_uint32 ADC_TALKING_EVAL_PERIOD;
extern const kal_uint32 ADC_TALKING_EVAL_COUNT;

extern const kal_uint32 KPD_LONGPRESS_PERIOD;
extern const kal_uint32 KPD_REPEAT_PERIOD;

#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__) && defined(LED_MAINLCD_USE_PWM_1)
extern kal_uint32 PWM1_Level_Info[PWM_MAX_BACKLIGHT_LEVEL][2];
#else
extern kal_uint32 PWM1_Level_Info[PWM_MAX_LEVEL][2];
#endif

#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__) && defined(LED_MAINLCD_USE_PWM_2)
extern kal_uint32 PWM2_Level_Info[PWM_MAX_BACKLIGHT_LEVEL][2];
#else
extern kal_uint32 PWM2_Level_Info[PWM_MAX_LEVEL][2];
#endif

#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__) && defined(LED_MAINLCD_USE_PWM_3)
extern kal_uint32 PWM3_Level_Info[PWM_MAX_BACKLIGHT_LEVEL][2];
#else
extern kal_uint32 PWM3_Level_Info[PWM_MAX_LEVEL][2];
#endif

// PWM4, 5, 6 for old PWN configuration begin
extern kal_uint32 PWM4_Level_Info[PWM_MAX_LEVEL][2];
extern kal_uint32 PWM5_Level_Info[PWM_MAX_LEVEL][2];
extern kal_uint32 PWM6_Level_Info[PWM_MAX_LEVEL][2];
// PWM4, 5, 6 for old PWN configuration end

extern kal_uint32 Alter_Level_Info[PWM_MAX_LEVEL][2];

extern kal_uint8   MainLCD_Contrast_Level_Info[LCD_CONTRAST_MAX_LEVEL];
extern kal_uint8   MainLCD_Bias_Level_Info[LCD_PARAM_MAX_LEVEL];
extern kal_uint8   MainLCD_Linerate_Level_Info[LCD_PARAM_MAX_LEVEL];
extern kal_uint8   MainLCD_Temp_Level_Info[LCD_PARAM_MAX_LEVEL];
   
#ifdef DUAL_LCD
extern kal_uint8   SubLCD_Contrast_Level_Info[LCD_CONTRAST_MAX_LEVEL];
extern kal_uint8   SubLCD_Bias_Level_Info[LCD_PARAM_MAX_LEVEL];
extern kal_uint8   SubLCD_Linerate_Level_Info[LCD_PARAM_MAX_LEVEL];
extern kal_uint8   SubLCD_Temp_Level_Info[LCD_PARAM_MAX_LEVEL];
#endif

extern kal_uint32   Battery_Level_Info[BATTERY_MAX_LEVEL];

#if defined(MT6318)
extern kal_uint32 PMIC6318_PWM_Level_Info[PWM_MAX_LEVEL][2];
extern kal_uint16 pmic_custom_get_bl_pmw_type(void);
#endif

