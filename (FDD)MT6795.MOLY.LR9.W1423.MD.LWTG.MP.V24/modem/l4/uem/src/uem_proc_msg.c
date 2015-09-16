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
 * UEM_PROC_MSG.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for L4C<-UEM message using.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
* Include
*****************************************************************************/
#include "kal_general_types.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "ps_public_struct.h"
#include "kal_public_api.h"
#include "nvram_data_items.h"
//#include "stack_ltlcom.h"
#include "svc_sap.h"
#include "drv_msgid.h"
#include "l4_msgid.h"
#include "nvram_msgid.h"
#include "em_msgid.h"

#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_trace.h"
#include "ex_public.h"
#include "task_config.h"
#include "device.h"
#include "l4c_eq_msg.h"

#include "uem_context.h"
#include "uem_utility.h"
#include "uem_trc.h"

#include "custom_equipment.h"
#include "custom_hw_default.h"
#include "custom_uem.h"

#if defined (__WIFI_SUPPORT__)
#include "wndrv_ft_types.h"
#endif

#include "fs_func.h"

#if defined(__SMART_PHONE_MODEM__) && defined(__MTK_TARGET__)
#include "ccci.h"
#endif
#include "nvram_struct.h"
//#include "ex_item.h"


#include "dcl.h"
/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Global/Extern Function
*****************************************************************************/
#ifdef PLUTO_MMI    
extern void MMICheckDiskDisplay(void);
#elif defined(EXTERNAL_MMI)
extern void mmi_display_logo_in_early_time(void);
#else
#endif

#if !defined(__FS_CHECKDRIVE_SUPPORT__) && !defined(_LOW_COST_SINGLE_BANK_FLASH_)
    extern int FS_SetDiskFlag(void);
#endif /* !defined(__FS_CHECKDRIVE_SUPPORT__) && !defined(_LOW_COST_SINGLE_BANK_FLASH_) */ 


#ifdef __USB_ENABLE__
extern void l4cuem_usbconfig_cnf(kal_uint8 src_id, kal_bool result, kal_uint8 mode, kal_uint32 reserved);
#endif 

#if defined(__SMART_PHONE_MODEM__) && defined(__MTK_TARGET__)
extern UART_PORT TST_PORT;
extern UART_baudrate TST_BAUDRATE;
extern UART_PORT PS_UART_PORT;
extern UART_baudrate PS_BAUDRATE;
#endif

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void uem_pmic_power_on_if_needed(kal_uint8 vbat_level);

#if defined(__SMART_PHONE_MODEM__) && defined(__MTK_TARGET__)
UART_PORT g_uem_ccci_tst_port;
UART_baudrate g_uem_ccci_tst_baudrate;

kal_uint32 g_sleep_mode = 0;
kal_uint32 g_dcm_enable = 0;
#endif


/******************************************************************************/
/*******************   External Functions *************************************/
/******************************************************************************/
/*****************************************************************************
*   Function 
*      uemdrv_keypad_detect_ind
*   DESCRIPTION
*      The function is used to detect the user pressed or released keypad. 
*      The Driver will callback the function that the keypad is pressed or released and 
*      given the pressed or released key code value.
*   PARAMETERS
*      keypad_status   IN
*      keypad_code      IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_keypad_detect_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv_get_key_func        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_keypad_detect_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l4cuem_keypad_detect_ind(NULL);
}

/*****************************************************************************
*   Function 
*      uemdrv_alarm_detect_ind
*   DESCRIPTION
*      The function is used to detect the alarm time is up at power off point. 
*      The Driver will callback the function that the alarm is startup.
*   PARAMETERS
*      alarm_status   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_alarm_detect_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_alarm_detect_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uem_bmt_struct bmt_status;
    kal_uint8 poweron_mode = uem_get_poweron_mode();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_ALARM_DETECT);

    /* this is alarm power on case */
    uem_get_bat_status(&bmt_status);

    uem_rtc_config(uem_rtc_alarm_format_convert(DEVICE_AL_EN_None), uem_rtc_clock_format_convert(DEVICE_TC_EN_NoChange));

    if (POWERON(poweron_mode))
    {
        RTC_CTRL_GET_TIME_T lrtc = {0};
        rtc_format_struct rtc_time;

        //RTC_GetTime(&lrtc);
        uem_rtc_gettime(&lrtc);
        rtc_time.rtc_day = lrtc.u1Day;
        rtc_time.rtc_hour = lrtc.u1Hour;
        rtc_time.rtc_min = lrtc.u1Min;
        rtc_time.rtc_sec = lrtc.u1Sec;
        rtc_time.rtc_year = lrtc.u1Year;
        rtc_time.rtc_mon = lrtc.u1Mon;
        rtc_time.rtc_wday = lrtc.u1WDay;

        l4cuem_alarm_detect_ind(&rtc_time);
    }
}

/*****************************************************************************
*   Function 
*      uemdrv_rtc_period_ind
*   DESCRIPTION
*      The function is used to detect the RTC period time with one minute timer. 
*      The Driver will callback the function that the RTC within the specific time to 
*      generate RTC alarm interrupt.
*   PARAMETERS
*      rtc_type   IN/OUT   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_rtc_period_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_rtc_period_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    RTC_CTRL_GET_TIME_T lrtc = {0};
    rtc_format_struct rtc_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_RTC_PERIOD);

    //RTC_GetTime(&lrtc);
    uem_rtc_gettime(&lrtc);
    
    rtc_time.rtc_day = lrtc.u1Day;
    rtc_time.rtc_hour = lrtc.u1Hour;
    rtc_time.rtc_min = lrtc.u1Min;
    rtc_time.rtc_sec = lrtc.u1Sec;
    rtc_time.rtc_year = lrtc.u1Year;
    rtc_time.rtc_mon = lrtc.u1Mon;
    rtc_time.rtc_wday = lrtc.u1WDay;

    /* execute the callback function */
    l4cuem_rtc_period_ind(RTC_TIME_CLOCK_IND, &rtc_time);
}

/*****************************************************************************
*   Function 
*      uemdrv_keypad_power_on_ind
*   DESCRIPTION
*      The function is used to keypad power on.
*   PARAMETERS
*      void
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_keypad_power_on_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_keypad_power_on_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uem_bmt_struct bmt_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_KEYPAD_POWER_ON);

#if !defined(__MTK_TARGET__)
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
    /* show the logo */
    #if defined(EXTERNAL_MMI)
    mmi_display_logo_in_early_time();
    custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, 5);    
    #else
    MMICheckDiskDisplay();
    custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, 5);    
    #endif    

#endif /* !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) */ 
#endif

    /* set power on flag */
    uem_set_poweron_mode(POWER_ON_KEYPAD);
    uem_get_bat_status(&bmt_status);

    l4cuem_power_on_ind(POWER_ON_KEYPAD, uem_vbat_level_convert(bmt_status.volt));

    return;
}

/*****************************************************************************
*   Function 
*      uemdrv_exception_power_on_ind
*   DESCRIPTION
*      The function is used to excetption reboot.
*   PARAMETERS
*      void
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_exception_power_on_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_exception_power_on_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uem_bmt_struct bmt_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_set_poweron_mode(POWER_ON_EXCEPTION);
    uem_get_bat_status(&bmt_status);
    l4cuem_power_on_ind(POWER_ON_EXCEPTION, uem_vbat_level_convert(bmt_status.volt));
    return;
}

/*****************************************************************************
*   Function 
*      uemdrv_pmic_ind
*   DESCRIPTION
*      The function is used to notify the battery status from PMIC driver.
*   PARAMETERS
*      alarm_status   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_pmic_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_pmic_ind(kal_uint8 status_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uem_bmt_struct bmt_status;
    kal_uint8 vbat_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_PMIC_DETECT);
    /* reserve future to call back with message while the BMT indication notify */

    uem_get_bat_status(&bmt_status);

    if (status_type == PMIC_VBAT_STATUS)
    {
    #ifndef __LTE_RAT__
        vbat_level = custom_cfg_vbat_level_regulator(
                        bmt_status.volt,
                        &(g_uem_cntx_p->bmt_status.last_level),
                        &(g_uem_cntx_p->bmt_status.disp_level),
                        &(g_uem_cntx_p->bmt_status.hit_count));
    #else
        vbat_level = 0;
    #endif
    }
    else
    {
        vbat_level = g_uem_cntx_p->bmt_status.disp_level;
    }

    switch (status_type)
    {
        case PMIC_VBAT_STATUS:          /* Notify the battery voltage, pass */
        case PMIC_OVERVOLPROTECT:       /* The voltage of battery is too high, pass */
        case PMIC_OVERBATTEMP:          /* The temperature of battery is too high, pass */
        case PMIC_LOWBATTEMP:           /* The temperature of battery is too low, pass */
        case PMIC_OVERCHARGECURRENT:    /* Charge current is too large, pass */
        case PMIC_LOWCHARGECURRENT:     /* Charge current is too large, pass */
        case PMIC_INVALID_BATTERY:      /* invalid battery, pass */
        case PMIC_INVALID_CHARGER:      /* invalid charger, pass */
        case PMIC_CHARGING_TIMEOUT:     /* Bad battery, pass */
        case PMIC_CHARGE_BAD_CONTACT:   /* Charger Bad Contact, pass */
        case PMIC_BATTERY_BAD_CONTACT:  /* Battery Bad Contact, pass */
        case PMIC_BATTERY_IN:
        case PMIC_BATTERY_OUT:
            l4cuem_battery_status_ind(status_type, vbat_level);
            break;

        case PMIC_CHARGE_COMPLETE:      /* Charge is completed, pass */
            l4cuem_battery_status_ind(status_type, vbat_level);
            g_uem_cntx_p->is_charing_complete=KAL_TRUE;
            break;
        case PMIC_USB_NO_CHARGER_OUT:   /* pass */
        {
        #if defined(PLUTO_MMI)
            /* check if the accessory prev state is IN && it is not in progress */
            if (FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB_CHARGER) &&
                !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER))
            {
                l4cuem_battery_status_ind(status_type, vbat_level);     /* Notify MMI */

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER);
            }
            else if (g_uem_cntx_p->is_usb_charing == KAL_FALSE)
            {
               l4cuem_battery_status_ind(status_type, vbat_level);     /* Notify MMI */
            }
            /* update the latest status */
            FLAG_SET_OFF(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_USB_CHARGER);
        #else /* defined(PLUTO_MMI) */ 
            l4cuem_battery_status_ind(status_type, vbat_level);
        #endif /* defined(PLUTO_MMI) */ 

            break;
        }
        case PMIC_USB_CHARGER_OUT:      /* USB Charger out */
        {
        #if defined(PLUTO_MMI)
            /* check if the accessory prev state is IN && it is not in progress */
            if (FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB_CHARGER) &&
                !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER))
            {
                l4cuem_battery_status_ind(status_type, vbat_level);     /* Notify MMI */

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER);
            }
            else if (g_uem_cntx_p->is_usb_charing == KAL_TRUE)
            {
                l4cuem_battery_status_ind(status_type, vbat_level);     /* Notify MMI */
            }
            /* update the latest status */
            FLAG_SET_OFF(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_USB_CHARGER);
        #else /* defined(PLUTO_MMI) */ 
            l4cuem_battery_status_ind(status_type, vbat_level);
        #endif /* defined(PLUTO_MMI) */ 

            //if (status_type==PMIC_USB_CHARGER_OUT)
            {
                g_uem_cntx_p->is_charing_complete=KAL_FALSE;
            }
            g_uem_cntx_p->is_charing = KAL_FALSE;
            break;
        }
        case PMIC_USB_NO_CHARGER_IN:    /* pass */
        {
        #if defined(PLUTO_MMI)
            if (!FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB_CHARGER) &&
                !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER))
            {
                l4cuem_battery_status_ind(status_type, vbat_level);     /* Notify MMI */

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER);
            }
            else if (g_uem_cntx_p->is_usb_charing == KAL_TRUE)
            {
               l4cuem_battery_status_ind(status_type, vbat_level);     /* Notify MMI */
            }

            g_uem_cntx_p->is_usb_charing = KAL_FALSE;
            
            /* update the latest status */
            FLAG_SET_ON(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_USB_CHARGER);

            uem_pmic_power_on_if_needed(vbat_level);
        #else /* defined(PLUTO_MMI) */ 
            l4cuem_battery_status_ind(status_type, vbat_level);
            uem_pmic_power_on_if_needed(vbat_level);
        #endif /* defined(PLUTO_MMI) */ 

            g_uem_cntx_p->is_charing = KAL_FALSE;
            break;
        }
        case PMIC_USB_CHARGER_IN:       /* USB Charger in */
        {
        #if defined(PLUTO_MMI)
            /* check if the accessory prev state is OUT && it is not in progress */
            if (!FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB_CHARGER) &&
                !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER))
            {

                l4cuem_battery_status_ind(status_type, vbat_level);     /* Notify MMI */

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER);
            }
            else if (g_uem_cntx_p->is_usb_charing == KAL_FALSE)
            {
               l4cuem_battery_status_ind(status_type, vbat_level);     /* Notify MMI */
            }

            g_uem_cntx_p->is_usb_charing = KAL_TRUE;
            
            /* update the latest status */
            FLAG_SET_ON(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_USB_CHARGER);

            uem_pmic_power_on_if_needed(vbat_level);
        #else /* defined(PLUTO_MMI) */ 
            l4cuem_battery_status_ind(status_type, vbat_level);
            uem_pmic_power_on_if_needed(vbat_level);
        #endif /* defined(PLUTO_MMI) */ 

            g_uem_cntx_p->is_charing = KAL_TRUE;
            break;
        }

        case PMIC_CHARGER_OUT:
        {
        #if defined(PLUTO_MMI)
            /* check if the accessory prev state is IN && it is not in progress */
            if (FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_CHARGER) &&
                !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CHARGER))
            {
                l4cuem_battery_status_ind(status_type, vbat_level);     /* Notify MMI */

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CHARGER);
            }
            /* update the latest status */
            FLAG_SET_OFF(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_CHARGER);
        #else /* defined(PLUTO_MMI) */ 
            l4cuem_battery_status_ind(status_type, vbat_level);
        #endif /* defined(PLUTO_MMI) */ 

            g_uem_cntx_p->is_charing_complete=KAL_FALSE;
            g_uem_cntx_p->is_charing = KAL_FALSE;
            break;
        }

        case PMIC_CHARGER_IN:   /* Charger plug in */
        {
        #if defined(PLUTO_MMI)
            /* check if the accessory prev state is OUT && it is not in progress */
            if (!FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_CHARGER) &&
                !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CHARGER))
            {
                /* Always send charger-in indication to avoid fast repeating charger in-out b4 power-on completes */
                l4cuem_battery_status_ind(status_type, vbat_level);

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CHARGER);
            }

            /* update the latest status */
            FLAG_SET_ON(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_CHARGER);

            uem_pmic_power_on_if_needed(vbat_level);
        #else /* defined(PLUTO_MMI) */ 
            l4cuem_battery_status_ind(status_type, vbat_level);
            uem_pmic_power_on_if_needed(vbat_level);
        #endif /* defined(PLUTO_MMI) */ 

            g_uem_cntx_p->is_charing = KAL_TRUE;
            break;

        }

        default:
            break;
    }
}

/*****************************************************************************
*   Function 
*      uemdrv_gpio_detect_ind
*   DESCRIPTION
*      The function is used to detect the GPIO device including hand-free, and earphone. 
*      When the driver detect any earphone is plugged in, it will callback this function 
*      to notify MMI, if the driver detect the earphone is plugged out, it will callback 
*      this function to notify MMI too.
*   PARAMETERS
*      gpio_device      IN
*     on_off         IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_gpio_detect_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ext_gpio_device     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_gpio_detect_ind(kal_uint8 ext_gpio_device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_GPIO_DETECT);

    /* the gpio plug in */
    switch (ext_gpio_device)
    {
        case EXT_DEV_NONE:
        {
            /* set output path, audio_mode has been change at uemdrv_aux_id_hdlr() */
            //JhZhao HAL uem_send_msg_to_aud(MSG_ID_L4AUD_GPIO_DETECT_IND, (kal_uint32) ext_gpio_device);
            l4cuem_gpio_detect_ind(g_uem_cntx_p->ext_dev_status, KAL_FALSE);
            g_uem_cntx_p->ext_dev_status = EXT_DEV_NONE;
            /* l4cuem_gpio_detect_ind(EXT_DEV_NONE, KAL_FALSE); */
            break;
        }

        case EXT_DEV_HANDFREE:
        case EXT_DEV_EARPHONE:
        case EXT_DEV_CARKIT:
        {
            g_uem_cntx_p->ext_dev_status = ext_gpio_device;
            /* set output path, audio_mode has been change at uemdrv_aux_id_hdlr() */
            //JhZhao HAL uem_send_msg_to_aud(MSG_ID_L4AUD_GPIO_DETECT_IND, (kal_uint32) ext_gpio_device);
            l4cuem_gpio_detect_ind(ext_gpio_device, KAL_TRUE);
            break;
        }
        case EXT_DEV_UART:
        {
            /* Only accessory plug in/out change context */
            g_uem_cntx_p->ext_dev_status = ext_gpio_device;
            l4cuem_gpio_detect_ind(ext_gpio_device, KAL_TRUE);
            break;
        }
        case EXT_DEV_KEY_1:
        case EXT_DEV_KEY_2:
        {
            l4cuem_gpio_detect_ind(ext_gpio_device, KAL_TRUE);
            break;
        }
        case EXT_DEV_CLAM_OPEN:
        {
        #if defined(PLUTO_MMI)
            /* check if the accessory prev state is IN && it is not in progress */
            if (!FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_CLAM) &&
                !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CLAM))
            {
                l4cuem_gpio_detect_ind(ext_gpio_device, KAL_TRUE);

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CLAM);
            }
            /* update the latest status */
            FLAG_SET_ON(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_CLAM);
        #else /* defined(PLUTO_MMI) */ 
            l4cuem_gpio_detect_ind(ext_gpio_device, KAL_TRUE);
        #endif

        g_uem_cntx_p->clam_status = KAL_TRUE;
            break;
        }
        case EXT_DEV_CLAM_CLOSE:
        {
        #if defined(PLUTO_MMI)
            /* check if the accessory prev state is IN && it is not in progress */
            if (FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_CLAM) &&
                !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CLAM))
            {
                l4cuem_gpio_detect_ind(ext_gpio_device, KAL_TRUE);

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CLAM);
            }
            /* update the latest status */
            FLAG_SET_OFF(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_CLAM);
        #else /* defined(PLUTO_MMI) */ 
            l4cuem_gpio_detect_ind(ext_gpio_device, KAL_TRUE);
        #endif

        g_uem_cntx_p->clam_status = KAL_FALSE;
            break;
        }
        case EXT_DEV_TRANSMITTER_HOLD_ON:
        case EXT_DEV_TRANSMITTER_PUT_DOWN:
        case EXT_DEV_AUX_DETECT_DONE:
        {
            l4cuem_gpio_detect_ind(ext_gpio_device, KAL_TRUE);
            break;
        }
        default:
            break;
    }
}

/*****************************************************************************
*  Function 
*     uemdrv_audio_play_finish_ind
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_audio_play_finish_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  identifier      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_audio_play_finish_ind(kal_uint8 result, kal_uint16 identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l4cuem_audio_play_finish_ind(result, identifier);
}

#ifdef __USB_ENABLE__
/*****************************************************************************
*  Function 
*     uemdrv_usb_power_on_ind
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_usb_power_on_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_usb_power_on_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_set_poweron_mode(POWER_ON_USB);

   /***  2004/05/28 Robin
     *   Postpone latch power to uemdrv_usb_detect_ind() because driver will send power on indication
     * before SW debounce time finish. If user plug out usb device during the SW debounce time,
     * driver will not send out USB_DETECT_IND/plugout so wil not able to  power off
   ***/
#ifndef __NVRAM_IN_USB_MS__
    l4cuem_usb_power_on_ind();
#endif 
    return;
}

/*****************************************************************************
*  Function 
*     uemdrv_usb_detect_ind
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_usb_detect_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  action      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_usb_detect_ind(kal_uint8 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (action == DEVUSB_DETECT_ACTION_PLUGOUT)
    {
    #ifndef __NVRAM_IN_USB_MS__
        if (uem_get_poweron_mode() == POWER_ON_USB)
        {
            //DRV_POWEROFF();
            uem_drv_power_off();
        #if (defined(MT6318) || defined(MT6305))
#if 0
/* under construction !*/
#endif
        #endif 
            return;
        }
    #endif /* __NVRAM_IN_USB_MS__ */ 

        if ((uem_get_poweron_mode() == POWER_ON_USB) &&(uem_get_state() != UEM_STATE_READY))
        {
            //DRV_POWEROFF();
            uem_drv_power_off();
        #if (defined(MT6318) || defined(MT6305))
#if 0
/* under construction !*/
#endif
        #endif 
            return;
        }
#if 0
    #if (defined(__USB_IN_NORMAL_MODE__) || defined(PICTBRIDGE_SUPPORT)) && defined (APPMEM_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* (defined(__USB_IN_NORMAL_MODE__) || defined(PICTBRIDGE_SUPPORT) ) && defined (APPMEM_SUPPORT) */ 
#endif
    }
#ifndef __NVRAM_IN_USB_MS__
    else if ((action == DEVUSB_DETECT_ACTION_PLUGIN) && (uem_get_poweron_mode() == POWER_ON_USB))
    {
        //DRV_POWERON();
        uem_drv_power_on();
    }
#endif /* __NVRAM_IN_USB_MS__ */ 

#if defined(PLUTO_MMI)
    if (action == DEVUSB_DETECT_ACTION_PLUGOUT ||
        action == DEVUSB_DETECT_ACTION_USB_SUSPEND)
    {
        /* check if the accessory prev state is IN && it is not in progress */
        if (FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB) &&
            !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB))
        {
            l4cuem_usbdetect_ind(DEVUSB_DETECT_ACTION_PLUGOUT);   /* Notify MMI */

            /* Set in progress */
            FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB);
        }
        /* update the latest status */
        FLAG_SET_OFF(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_USB);
    }
    else if (action == DEVUSB_DETECT_ACTION_PLUGIN)
    {
        /* check if the accessory prev state is OUT && it is not in progress */
        if (!FLAG_IS_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB) &&
            !FLAG_IS_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB))
        {
            l4cuem_usbdetect_ind(action);   /* Notify MMI */

            /* Set in progress */
            FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB);
        }
        /* update the latest status */
        FLAG_SET_ON(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_USB);
    }
#else /* defined(PLUTO_MMI) */ 
    if (action == DEVUSB_DETECT_ACTION_PLUGIN)
    {
        g_uem_cntx_p->usb_out_suspend = 0;
        l4cuem_usbdetect_ind(action);
    }
    else if (action == DEVUSB_DETECT_ACTION_PLUGOUT ||
        action == DEVUSB_DETECT_ACTION_USB_SUSPEND)
    {
        /* Only notify MMI at for plugout/suspend*/
        if (g_uem_cntx_p->usb_out_suspend == 0)
        {
            l4cuem_usbdetect_ind(action);
            g_uem_cntx_p->usb_out_suspend = 1;
        }
    }
    
#endif /* defined(PLUTO_MMI) */ 

    return;
}

/*****************************************************************************
*  Function 
*     uemdrv_usb_config_cnf
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_usb_config_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode            [IN]        
 *  result          [IN]        
 *  reserved        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_usb_config_cnf(kal_uint8 mode, kal_bool result, kal_uint32 reserved)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l4cuem_usbconfig_cnf(g_uem_cntx_p->usb_msg_src_id, result, mode, reserved);
    return;
}
#endif /* __USB_ENABLE__ */ 

/*****************************************************************************
*  Function 
*     uemdrv_prechr_power_on_ind
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_prechr_power_on_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_prechr_power_on_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uem_bmt_struct bmt_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
    /* show the logo */
    #if defined(EXTERNAL_MMI)
    mmi_display_logo_in_early_time();
    custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, 5);    
    #else
    MMICheckDiskDisplay();
    custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, 5);
    #endif
#endif /* !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) */ 

    uem_get_bat_status(&bmt_status);
    uem_set_poweron_mode(POWER_ON_PRECHARGE);
    l4cuem_power_on_ind(POWER_ON_PRECHARGE, uem_vbat_level_convert(bmt_status.volt));
}

/*****************************************************************************
*  Function 
*     uemdrv_get_hw_level_pwm_info_req
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_get_hw_level_pwm_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  level       [IN]        
 *  info1       [?]         
 *  info2       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_get_hw_level_pwm_info_req(kal_uint8 type, kal_uint8 level, kal_uint8 *info1, kal_uint8 *info2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        default:
            break;
    }
}

/*****************************************************************************
*  Function 
*     uemdrv_get_hw_level_alter_info_req
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uemdrv_get_hw_level_alter_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  level       [IN]        
 *  info1       [?]         
 *  info2       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void uemdrv_get_hw_level_alter_info_req(kal_uint8 level, kal_uint8 *info1, kal_uint8 *info2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0 /* MODEM only*/
/* under construction !*/
/* under construction !*/
#endif /* MODEM only*/
    *info1 = 0;
    *info2 = 0;
}

/*****************************************************************************
*   Function 
*      uem_poweron_timer_expiry_hdlr
*   DESCRIPTION
*      handle the power on timer expire
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_poweron_timer_expiry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uem_poweron_timer_expiry_hdlr(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_stop_timer(PWN_EVENT_TIMER);

    /* Latch power and do the rest */
    //DRV_POWERON();
    uem_drv_power_on();

#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
    /* show the logo */
    #if defined(EXTERNAL_MMI)
    mmi_display_logo_in_early_time();
    custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, 5);    
    #else
        #ifdef PLUTO_MMI
        MMICheckDiskDisplay();
        #endif
    custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, 5); 
    #endif
#endif /* !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) */ 

#if defined(MT6223P)
     FS_LockFAT(FS_CARD_BUSY_NONBLOCK_ENUM);
#endif

#if !defined(__FS_CHECKDRIVE_SUPPORT__) && !defined(_LOW_COST_SINGLE_BANK_FLASH_)
    /* Before this point, releasing power key does not consider as "abnormal poweroff" */
    FS_SetDiskFlag();
#endif /* !defined(__FS_CHECKDRIVE_SUPPORT__) && !defined(_LOW_COST_SINGLE_BANK_FLASH_) */ 

    /* send message to L4/MMI */
    uemdrv_keypad_power_on_ind();
}

/*****************************************************************************
*   Function 
*      uem_poweron_timer_start
*   DESCRIPTION
*      start a timer to t
*   PARAMETERS
*     time left to power on
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_poweron_timer_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time_in_ms      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_poweron_timer_start(kal_uint32 time_in_ms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_start_timer(PWN_EVENT_TIMER, uem_poweron_timer_expiry_hdlr, time_in_ms);
}

/***************************************************************************** 
****************************************************************************** 
* Local Funcations 
******************************************************************************
*****************************************************************************/
/*****************************************************************************
*  Function 
*     uem_pmic_power_on_if_needed
*  DESCRIPTION
*     ...
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_pmic_power_on_if_needed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vbat_level      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void uem_pmic_power_on_if_needed(kal_uint8 vbat_level)
{
#if 0 /* MODEM only*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MTK_TARGET__
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
/* under construction !*/
        #endif /* __MTK_TARGET__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MODEM only*/
}


/*****************************************************************************
*	Function 
*		uemdrv_rf_test_gsm_powerscan_callback
*	DESCRIPTION
*		callback function for RF Test GSM
*	PARAMETERS
*	
*	
*	RETURNS
*		void
*	GLOBALS AFFECTED
*****************************************************************************/
void uemdrv_rf_test_gsm_powerscan_callback(kal_int16 *arfcn, kal_int16 *power)
{
    kal_uint8 i;
    rf_test_gsm_param_struct request;

    for (i=0; i<20; i++)
    {
        request.gsm_power_scan.arfcn_out[i] = arfcn[i];
        request.gsm_power_scan.power[i] = power[i];
    }
     
    l4cuem_rf_test_gsm_cnf(g_uem_cntx_p->src_id , RF_TEST_GSM_POWER_SCAN, request);
}
 
#if defined(__WIFI_SUPPORT__)
/*****************************************************************************
*	Function 
*		uemdrv_rf_test_wifi_rx_pkt_callback
*	DESCRIPTION
*		callback function for RF Test Wifi
*	PARAMETERS
*	
*	
*	RETURNS
*		void
*	GLOBALS AFFECTED
*****************************************************************************/
void uemdrv_rf_test_wifi_rx_pkt_callback(wndrv_test_rx_status_struct* result)
{
    rf_test_wifi_param_struct request={0};

    request.wifi_rx_cont_pkt.pau_total = result->pau_rx_pkt_count;
    request.wifi_rx_cont_pkt.pau_err = result->pau_crc_err_count;
    request.wifi_rx_cont_pkt.pau_ccca = result->pau_cca_count;
    request.wifi_rx_cont_pkt.pau_fifo_full = result->pau_rx_fifo_full_count;
    request.wifi_rx_cont_pkt.int_ok = result->int_rx_ok_num;
    request.wifi_rx_cont_pkt.int_err = result->int_crc_err_num;
    request.wifi_rx_cont_pkt.rssi_mean = result->int_rssi_mean;
    request.wifi_rx_cont_pkt.rssi_max = result->int_rssi_max;
    request.wifi_rx_cont_pkt.rssi_min = result->int_rssi_min;
    request.wifi_rx_cont_pkt.rssi_variance = result->int_rssi_variance;
    request.wifi_rx_cont_pkt.int_long_preamble = result->int_long_preamble_num;
    request.wifi_rx_cont_pkt.int_short_preamble = result->int_short_preamble_num;
     
    l4cuem_rf_test_wifi_cnf(g_uem_cntx_p->src_id , RF_TEST_WIFI_RX_CONT_PKT, request);
}
#endif /* defined(__WIFI_SUPPORT__) */



/*****************************************************************************
 * FUNCTION
 *  uem_ccci_ack_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
#if defined(__SMART_PHONE_MODEM__) && defined(__MTK_TARGET__)
void uem_ccci_ack_callback(CCCI_BUFF_T *buff_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 ccciMsg;
    void* local_data_ptr;
    CCCI_BUFF_T* bufp = (CCCI_BUFF_T*)buff_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    kal_trace(TRACE_FUNC, FUNC_UEM_CCCI_ACK_CALLBACK);
    
    /* confirm the channel buffer type */
    if (!CCCI_IS_MAILBOX(bufp)) 
    {
        ASSERT(0);
    }

    local_data_ptr = (uem_ccci_em_req_struct*) construct_local_para(sizeof(uem_ccci_em_req_struct), TD_CTRL);
    
    /* get the mailbox id */
    ccciMsg = CCCI_MAILBOX_ID(bufp);

    ((uem_ccci_em_req_struct*)local_data_ptr)->buff_id = ccciMsg;
    ((uem_ccci_em_req_struct*)local_data_ptr)->reserved = bufp->reserved;    

    //kal_trace(TRACE_INFO, FUNC_UEM_CCCI_ACK_CAlLBACK_INFO, ccciMsg);
    
    uem_genernal_send_msg(MSG_ID_DRVUEM_CCCI_EM_REQ_IND, 
                          MOD_CCCI_HISR, 
                          MOD_UEM, 
                          (void *)local_data_ptr);
   
}


/*****************************************************************************
 * FUNCTION
 *  uem_ccci_em_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vbat_level      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
 void uem_ccci_em_req_hdlr(kal_uint16 event_type, kal_uint16 param_1, kal_uint32 param_2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ccci_result;
    extern kal_bool l4c_em_sleep_mode_req(kal_bool on_off);
    extern void l4cuem_em_dcm_enable_req(kal_bool enable);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_CCCI_EM_REQ_HDLR, event_type);
    
    switch (event_type)
    {
        case UEM_CCCI_EM_REQ_GET_SLEEP_MODE:
        {                    
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_GET_SLEEP_INFO, g_sleep_mode);               
        	ccci_result = ccci_mailbox_write_with_reserved(CCCI_UEM_CHANNEL, 
                                             (kal_uint32)UEM_CCCI_EM_REQ_GET_SLEEP_MODE, 
                                             (kal_uint32)g_sleep_mode); /* success */   
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_GET_SLEEP_INFO, ccci_result); 
            break;
        }    
        case UEM_CCCI_EM_REQ_SET_SLEEP_MODE:
        {
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_SLEEP_INFO, param_2);            
            if (param_2)
            {
                l4c_em_sleep_mode_req(KAL_TRUE);  
                g_sleep_mode = 1;
            }
            else
            {
                l4c_em_sleep_mode_req(KAL_FALSE);    
                g_sleep_mode = 0;
            }
        	ccci_result = ccci_mailbox_write_with_reserved(CCCI_UEM_CHANNEL, 
                                             (kal_uint32)UEM_CCCI_EM_REQ_SET_SLEEP_MODE, 
                                             (kal_uint32)1); /* success */            
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_SLEEP_INFO, ccci_result);             
            break;
        }
        case UEM_CCCI_EM_REQ_GET_DCM_MODE:
        {
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_GET_DCM_INFO, g_dcm_enable);               
            
        	ccci_result = ccci_mailbox_write_with_reserved(CCCI_UEM_CHANNEL, 
                                             (kal_uint32)UEM_CCCI_EM_REQ_GET_DCM_MODE, 
                                             (kal_uint32)g_dcm_enable); /* success */
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_GET_DCM_INFO, ccci_result);             

            break;
        }            
        case UEM_CCCI_EM_REQ_SET_DCM_MODE:
        {
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_DCM_INFO, param_2);            
            
            /* param_2: buff->reserved. represent: On/Off */
            if (param_2)
            {
                l4cuem_em_dcm_enable_req(KAL_TRUE);
                g_dcm_enable = 1;
            }
            else
            {
                l4cuem_em_dcm_enable_req(KAL_FALSE);
                g_dcm_enable = 0;
            }
            
        	ccci_result = ccci_mailbox_write_with_reserved(CCCI_UEM_CHANNEL, 
                                             (kal_uint32)UEM_CCCI_EM_REQ_SET_DCM_MODE, 
                                             (kal_uint32)1); /* success */
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_DCM_INFO, ccci_result); 
            break;
        }
        case UEM_CCCI_EM_REQ_GET_MEMDUMP:
        {
            //ex_get_memorydump_flag(&memdump_flag);
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_GET_MEMDUMP_INFO, ex_is_forcememorydump());
            
        	ccci_result = ccci_mailbox_write_with_reserved(CCCI_UEM_CHANNEL, 
                                             (kal_uint32)UEM_CCCI_EM_REQ_GET_MEMDUMP, 
                                             (kal_uint32)ex_is_forcememorydump()); /* success */
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_GET_MEMDUMP_INFO, ccci_result); 
            break;
        }                    
        case UEM_CCCI_EM_REQ_SET_MEMDUMP:
        {
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_MEMDUMP_INFO, param_2);            
            
            /* param_2: buff->reserved. represent: On/Off */
            if (param_2)
            {
                ex_set_memorydump_flag();
            }
            else
            {
                ex_clear_memorydump_flag();
            }            
            
        	ccci_result = ccci_mailbox_write_with_reserved(CCCI_UEM_CHANNEL, 
                                             (kal_uint32)UEM_CCCI_EM_REQ_SET_MEMDUMP, 
                                             (kal_uint32)1); /* success */
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_MEMDUMP_INFO, ccci_result); 
            break;
        }
        case UEM_CCCI_EM_REQ_GET_UART:
        {
            kal_uint16 event_type;
            kal_uint16 uart_port;
            kal_uint32 baudrate, buff_id;
            
            event_type = UEM_CCCI_EM_REQ_GET_UART;
            uart_port = TST_PORT;
            baudrate = TST_BAUDRATE;

            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_GETUART_INFO, uart_port, baudrate);            

            buff_id = ((uart_port<<16)+event_type);

            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_GETUART_INFO2, buff_id, baudrate);            
            
        	ccci_result = ccci_mailbox_write_with_reserved(CCCI_UEM_CHANNEL, 
                                             (kal_uint32)buff_id, 
                                             (kal_uint32)baudrate); 
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_GET_SLEEP_INFO, ccci_result); 
            break;
        }
        case UEM_CCCI_EM_REQ_SET_UART:
        {
            g_uem_ccci_tst_port = (kal_uint16)(param_1);
            g_uem_ccci_tst_baudrate = param_2;
            
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_SETUART_INFO, g_uem_ccci_tst_port, g_uem_ccci_tst_baudrate);            
            
            uem_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_PORT_SETTING_LID, 0, 0);
   
            return;
                        
//        	ccci_result = ccci_mailbox_write_with_reserved(CCCI_UEM_CHANNEL, 
//                                             (kal_uint32)UEM_CCCI_EM_REQ_SET_UART, 
//                                             (kal_uint32)1); /* success */
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_GET_SLEEP_INFO, ccci_result); 
            break;
        }        
        case UEM_CCCI_EM_REQ_POWER_SCAN_REQ:
        {
            void* local_data_ptr;
			
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_GETUART_INFO, param_1, param_2);            

            local_data_ptr = (rf_test_gsm_power_scan_struct*) construct_local_para(sizeof(rf_test_gsm_power_scan_struct), TD_CTRL);

            ((rf_test_gsm_power_scan_struct*)local_data_ptr)->band = (kal_uint16)(param_1);
            ((rf_test_gsm_power_scan_struct*)local_data_ptr)->arfcn_in = param_2;
			
            uem_send_msg_to_l1(MSG_ID_L4CL1_EM_RF_TEST_GSM_POWER_SCAN_REQ, local_data_ptr);
           
            return;
            break;
        }
        default :
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  uem_ccci_em_uart_port_setting_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vbat_level      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_ccci_em_uart_port_setting_hdlr(kal_uint16 event_type, void *port_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ccci_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_UART_PORT_SETTING_INFO);
    
    switch (event_type)
    {
        case UEM_CCCI_EM_UART_PORT_READ:
        {
            port_setting_struct *info = (port_setting_struct*)port_setting;
            peer_buff_struct *data_stream;
            local_para_struct *parm_stream;
            kal_uint16 pdu_len;
            
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_UART_PORT_READ_INFO, info->ps_port, info->tst_port_ps, info->tst_baudrate_ps); 

            if (g_uem_ccci_tst_port != PS_UART_PORT)
            {

                info->tst_baudrate_ps = g_uem_ccci_tst_baudrate;
                info->tst_port_ps = g_uem_ccci_tst_port;            
                info->tst_baudrate_l1 = g_uem_ccci_tst_baudrate;
                info->tst_port_l1 = g_uem_ccci_tst_port;            
            }
            else
            {
                kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_UART_PORT_CONFLICT_INFO, PS_UART_PORT, g_uem_ccci_tst_port);  
                ASSERT(0);
            }

            parm_stream = construct_local_para(sizeof(nvram_write_req_struct), TD_CTRL);
            data_stream = construct_peer_buff(sizeof(port_setting_struct), 0, 0, TD_CTRL);

            ((nvram_write_req_struct*) parm_stream)->file_idx = NVRAM_EF_PORT_SETTING_LID;
            ((nvram_write_req_struct*) parm_stream)->para = 1;
            ((nvram_write_req_struct*) parm_stream)->access_id = g_uem_cntx_p->func_id;

            pdu_len = sizeof(port_setting_struct);
            kal_mem_cpy(get_peer_buff_pdu(data_stream, &pdu_len), port_setting, pdu_len);

//            SEND_ILM(MOD_UEM, MOD_NVRAM, PS_NVRAM_SAP, (&ilm_ptr));
            msg_send6(MOD_UEM, MOD_NVRAM, PS_NVRAM_SAP, MSG_ID_NVRAM_WRITE_REQ, parm_stream, data_stream);
            
            break;
        }        
        case UEM_CCCI_EM_UART_PORT_WRITE:
        {
            nvram_write_cnf_struct *result = (nvram_write_cnf_struct*)port_setting;
            
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_UART_PORT_WRITE_INFO, result->result);            

            if (result->result)
            {
                ccci_result = ccci_mailbox_write_with_reserved(CCCI_UEM_CHANNEL, 
                                             (kal_uint32)UEM_CCCI_EM_REQ_SET_UART, 
                                             (kal_uint32)1); /* success */
            }
            else
            {
                ccci_result = ccci_mailbox_write_with_reserved(CCCI_UEM_CHANNEL, 
                                             (kal_uint32)UEM_CCCI_EM_REQ_SET_UART, 
                                             (kal_uint32)0); /* fail */            
            }
            kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_GET_SLEEP_INFO, ccci_result);             
            break;
        }        
        default :
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  uem_ccci_em_gsm_power_scan_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vbat_level      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_ccci_em_gsm_power_scan_hdlr(kal_int16 *arfcn, kal_int16 *power)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 event_type;
    kal_uint16 arfcn_val,power_val;
    kal_uint32 buff_id;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_UART_PORT_SETTING_INFO);

    event_type = UEM_CCCI_EM_REQ_POWER_SCAN_REQ;
    arfcn_val = arfcn[0];
    power_val = power[0];

    buff_id = ((arfcn_val<<16)+event_type);

//    kal_trace(TRACE_INFO, FUNC_UEM_CCCI_EM_REQ_GETUART_INFO2, buff_id, arfcn_val);            
    
    ccci_mailbox_write_with_reserved(CCCI_UEM_CHANNEL, 
                                 (kal_uint32)buff_id, 
                                 (kal_uint32)power_val); 

}


#endif /* __SMART_PHONE_MODEM__ */


