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
 * UEM_PROC_CMD.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for L4C->UEM command using.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#define NEW_FRAME

    #include "kal_general_types.h"
    #include "kal_public_api.h"
    #include "ps_public_struct.h"

#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "drv_msgid.h"
#include "med_msgid.h"
#include "nvram_msgid.h"
#include "em_msgid.h"
#include "l4_msgid.h"

#include "stack_msgs.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#include "l1audio.h"
//#include "rtc_sw.h"
//#include "pwic.h"
#include "device.h"
//#include "uart_sw.h"

#if defined (__WIFI_SUPPORT__)
#include "wndrv_ft_types.h"
#include "wndrv_ft_msg.h"
#endif

#include "nvram_editor_data_item.h"
#include "nvram_interface.h"

#include "l4c2uem_struct.h"
#include "l4c_eq_msg.h"


#include "custom_equipment.h"
//#include "custom_led_patterns.h"
#include "custom_hw_default.h"
#include "custom_uem.h"

#include "uem_context.h"
#include "uem_trc.h"
#include "uem_utility.h"
#include "uem_gpio_ctrl.h"

#if defined(MT6223PMU)
//#include "Pmu_sw.h"
#endif 

#ifdef __DRM_V02__
#include "app_datetime.h"
extern void DRM_update_local_time(applib_time_struct *old_time, applib_time_struct* new_time, kal_bool reliable);
#endif

#if defined(MT6238PMU) && defined(PLUTO_MMI)
#include "drvpdn.h"
#endif /* MT6238PMU */

#if defined(MT6326) && defined(PLUTO_MMI)
//#include "drv_features_option.h"
//#include "pmic_features.h"
//#include "pmic6326_sw.h"
#endif 

#include "fs_func.h"

#include "dcl.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define MINIMUM(A,B) (((A)<(B))?(A):(B))

/***************************************************************************** 
* Extern Functions
*****************************************************************************/
#ifdef __MTK_TARGET__
//.HAL extern DRV_RESET(void);
//.HAL extern void BMT_CallState(kal_uint8 callState);
#endif /* __MTK_TARGET__ */ 

#if defined(DCM_ENABLE)
extern kal_uint8 DCM_Disable(kal_uint8 handle);
extern kal_uint8 DCM_Enable(kal_uint8 handle);
#endif /* defined(DCM_ENABLE) */ 

//extern void UART_TurnOnPower(UART_PORT port, kal_bool enable);

#ifdef FM_RADIO_ENABLE
extern void FMR_Radio_EngineerMode(kal_uint16 group_idx, kal_uint16 item_idx, kal_uint32 item_value);
#endif /* #ifdef FM_RADIO_ENABLE */

#if defined(__WIFI_SUPPORT__)
extern void uemdrv_rf_test_wifi_rx_pkt_callback(wndrv_test_rx_status_struct* result);
#endif

#if defined(__AST2001__) && defined(__MTK_TARGET__)
extern void tl1_m_t_power_off(void);
#endif
extern int FS_ClearDiskFlag(void);
#ifndef __SMART_PHONE_MODEM__
    extern void FS_ShutDown(void);
#endif
/***************************************************************************** 
* Extern Variable
*****************************************************************************/

/***************************************************************************** 
* Global Variables
*****************************************************************************/
kal_uint8 uem_adc_on = 0;
eventid uem_adc_timer_id = 0;

/******************************************************************************/
/*******************   External Functions *************************************/
/******************************************************************************/
static void l4cuem_reset_watch_dog(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DCL_HANDLE dcl_wdt_handle; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	dcl_wdt_handle=DclWDT_Open(DCL_WDT,0);
   	DclWDT_Control(dcl_wdt_handle, WDT_CMD_DRV_RESET, 0);	 
    DclWDT_Close(dcl_wdt_handle);
}

/*****************************************************************************
 * FUNCTION
 *  l4cuem_bmt_set_callstate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  call_state          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void l4cuem_bmt_set_callstate(kal_bool call_state)  //.HAL
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

/*****************************************************************************
*   Function 
*      l4cuem_audio_play_req
*   DESCRIPTION
*      The function is used to play the audio device. Including keypad, tone, and melody play.
*   PARAMETERS
*      audio_device_id   IN   
*      audio_sound_id      IN
*      audio_volume      IN
*      audio_play_style   IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_audio_play_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_sound_id          [IN]        
 *  audio_play_style        [IN]        
 *  identifier              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_audio_play_req(kal_uint8 audio_sound_id, kal_uint8 audio_play_style, kal_uint16 identifier, kal_uint8 vol, kal_uint8 output_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_AUDIO_PLAY);

    uem_send_msg_to_aud(
        MSG_ID_MEDIA_AUD_PLAY_BY_ID_REQ,
        (kal_uint32) audio_sound_id,
        (kal_uint32) audio_play_style,
        (kal_uint32) identifier,
        (kal_uint64) vol,
        (kal_uint32)output_path);
}

/*****************************************************************************
*   Function 
*      l4cuem_audio_stop_req
*   DESCRIPTION
*      The function is used to stop the audio device play. Including keypad, tone, and melody stop.
*   PARAMETERS
*      audio_device   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_audio_stop_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_sound_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_audio_stop_req(kal_uint8 audio_sound_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_AUDIO_STOP);
    uem_send_msg_to_aud(MSG_ID_MEDIA_AUD_STOP_BY_ID_REQ, (kal_uint32) audio_sound_id);
}

/*****************************************************************************
*   Function 
*      l4cuem_audio_set_volume_req 
*   DESCRIPTION
*      The function is used to adjust audio volume.
*   PARAMETERS
*      audio_device   IN
*      volume_level   IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_audio_set_volume_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume_type         [IN]        
 *  volume_level        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_audio_set_volume_req(kal_uint8 volume_type, kal_uint8 volume_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (volume_type)
    {
        case VOL_TYPE_MEDIA:
        {
            uem_send_msg_to_aud(
                MSG_ID_MEDIA_AUD_SET_VOLUME_REQ,
                (kal_uint32) volume_type,
                (kal_uint32) volume_level,
                (kal_uint32) volume_level,
                (kal_uint32) 0);
            break;
        }
        case VOL_TYPE_SPH:
        {
            uem_send_msg_to_aud(
                MSG_ID_MEDIA_AUD_SET_VOLUME_REQ,
                (kal_uint32) volume_type,
                (kal_uint32) volume_level,
                (kal_uint32) volume_level,
                (kal_uint32) 0);
            break;
        }
        case VOL_TYPE_KEY:
        {
            uem_send_msg_to_aud(
                MSG_ID_MEDIA_AUD_SET_VOLUME_REQ,
                (kal_uint32) volume_type,
                (kal_uint32) volume_level,
                (kal_uint32) volume_level,
                (kal_uint32) 0);
            break;
        }
        case VOL_TYPE_MIC:
        {
            uem_send_msg_to_aud(
                MSG_ID_MEDIA_AUD_SET_VOLUME_REQ,
                (kal_uint32) volume_type,
                (kal_uint32) volume_level,
                (kal_uint32) volume_level,
                (kal_uint32) 0);
            break;
        }
        case VOL_TYPE_CTN:
        case VOL_TYPE_SID:
        default:
            break;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_audio_get_volume_req
*   DESCRIPTION
*      The function is used to get audio volume.
*   PARAMETERS
*      audio_device   IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_audio_get_volume_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_audio_get_volume_req(kal_uint8 src_id, kal_uint8 volume_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_send_msg_to_aud(MSG_ID_MEDIA_AUD_GET_VOLUME_REQ, volume_type, src_id);
    /* aud_audio_get_volume_req(volume_type, volume); */
}

/*****************************************************************************
*   Function 
*      l4cuem_demo_ext_imelody_ring_req
*   DESCRIPTION
*      Demo the extended imelody. The note stream can be used in EMS or 
*      Ring Composer.
*   PARAMETERS
*      imelody       IN
*      len               IN
*      play_style    IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_demo_ext_imelody_ring_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  imelody         [?]         
 *  len             [IN]        
 *  play_style      [IN]        
 *  identifier      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_demo_ext_imelody_ring_req(
        kal_uint8 *imelody,
        kal_uint16 len,
        kal_uint8 play_style,
        /* audio_play_style_enum */ kal_uint16 identifier)
{
    /* JhZhao HAL*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

/*****************************************************************************
*   Function 
*      l4cuem_power_off_req  
*   DESCRIPTION
*      The function is used to notify the MMI will power off. 
*   PARAMETERS
*   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_power_off_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_power_off_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_POEWR_OFF);

    #if defined(__AST2001__)  && defined(__MTK_TARGET__)
    tl1_m_t_power_off();/* Notify TL1 to turn off power to avoid power leakage */
    kal_sleep_task(4 * KAL_TICKS_100_MSEC);/* Sleep how many ticks n*4.615ms */
    #endif

    nvram_shutdown_handler();

#ifndef __DISABLE_MODEM_AUTO_POWER_OFF__
    FS_ClearDiskFlag();
#ifndef __SMART_PHONE_MODEM__
    FS_ShutDown();
#endif
#endif

    /* Turn off backlight */
    custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, 0);

    kal_trace(TRACE_FUNC, FUNC_UEM_POEWR_OFF);
    
    /* Turn off the power */
#ifndef __DISABLE_MODEM_AUTO_POWER_OFF__
    /* Turn off the power */
    uem_drv_power_off();
    kal_trace(TRACE_FUNC, FUNC_UEM_POEWR_OFF);
    l4cuem_reset_watch_dog();

#endif	
}

#if 0 //slim
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
*   Function 
*      l4cuem_rtc_get_time_req
*   DESCRIPTION
*      The function is used to retrieve the RTC alarm time value.
*   PARAMETERS
*      rtctime   OUT   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_rtc_get_time_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc_type            [IN]        
 *  rtc_alarm_id        [IN]        
 *  rtctime             [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_rtc_get_time_req(kal_uint8 rtc_type, kal_uint8 rtc_alarm_id, rtc_alarm_info_struct *rtctime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    RTC_CTRL_GET_TIME_T l_rtctime = {0};
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_RTC_GET_TIME);

    ASSERT(rtctime != NULL);    /* invalid address */

    switch (rtc_type)
    {
        case RTC_TIME_CLOCK_IND:
            //RTC_GetTime(&l_rtctime);
            uem_rtc_gettime(&l_rtctime);

            rtctime->data_time.rtc_day = l_rtctime.u1Day;
            rtctime->data_time.rtc_hour = l_rtctime.u1Hour;
            rtctime->data_time.rtc_min = l_rtctime.u1Min;
            rtctime->data_time.rtc_sec = l_rtctime.u1Sec;
            rtctime->data_time.rtc_year = (kal_uint8) l_rtctime.u1Year;
            rtctime->data_time.rtc_mon = l_rtctime.u1Mon;
            rtctime->data_time.rtc_wday = l_rtctime.u1WDay;

            result = KAL_TRUE;
            break;

        case RTC_ALARM_IND:
            if (rtc_alarm_id < MAX_ALARM_NUM)
            {
                /* return the alarm index */
                rtctime->alarm_index = rtc_alarm_id;

                kal_mem_cpy(rtctime, &(g_uem_cntx_p->rmi_data.alarm_info[rtc_alarm_id]), sizeof(rtc_alarm_info_struct));
                if (g_uem_cntx_p->rmi_data.alarm_info[rtc_alarm_id].alarm_format == DEVICE_AL_EN_None)
                {
                    result = KAL_FALSE;
                }
                else
                {
                    result = KAL_TRUE;
                }
            }
            else
            {
                kal_trace(TRACE_FUNC, WARNING_UEM_OUT_OF_RANGE);
                result = KAL_FALSE;
            }
            break;

        default:
            kal_trace(TRACE_FUNC, WARNING_UEM_OUT_OF_RANGE);
            break;
    }
    return result;
}

/*****************************************************************************
*  Function 
*     l4cuem_rtc_get_hw_time_req
*  DESCRIPTION
*     
*  PARAMETERS
*       ...  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_rtc_get_hw_time_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc_type            [IN]        
 *  rtc_alarm_id        [IN]        
 *  rtctime             [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_rtc_get_hw_time_req(kal_uint8 rtc_type, kal_uint8 rtc_alarm_id, rtc_alarm_info_struct *rtctime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    RTC_CTRL_GET_TIME_T l_rtctime = {0};
    RTC_CTRL_GET_ALARM_TIME_T almTime = {0};
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_RTC_GET_TIME);

    ASSERT(rtctime != NULL);    /* invalid address */

    switch (rtc_type)
    {
        case RTC_TIME_CLOCK_IND:
    #ifdef MMI_ON_WIN32

            rtctime->data_time.rtc_day = 1;
            rtctime->data_time.rtc_hour = 1;
            rtctime->data_time.rtc_min = 1;
            rtctime->data_time.rtc_sec = 1;
            rtctime->data_time.rtc_year = 3;
            rtctime->data_time.rtc_mon = 1;
            rtctime->data_time.rtc_wday = 1;
    #else /* MMI_ON_WIN32 */ 
            //RTC_GetTime(&l_rtctime);
            uem_rtc_gettime(&l_rtctime);
    
            rtctime->data_time.rtc_day = l_rtctime.u1Day;
            rtctime->data_time.rtc_hour = l_rtctime.u1Hour;
            rtctime->data_time.rtc_min = l_rtctime.u1Min;
            rtctime->data_time.rtc_sec = l_rtctime.u1Sec;
            rtctime->data_time.rtc_year = (kal_uint8) l_rtctime.u1Year;
            rtctime->data_time.rtc_mon = l_rtctime.u1Mon;
            rtctime->data_time.rtc_wday = l_rtctime.u1WDay;
    #endif /* MMI_ON_WIN32 */ 
            result = KAL_TRUE;
            break;

        case RTC_ALARM_IND:
            //result = RTC_GetALTime(&l_rtctime);
            result = uem_rtc_getaltime(&almTime);
            
            rtctime->data_time.rtc_day = almTime.u1Day;
            rtctime->data_time.rtc_hour = almTime.u1Hour;
            rtctime->data_time.rtc_min = almTime.u1Min;
            rtctime->data_time.rtc_sec = almTime.u1Sec;
            rtctime->data_time.rtc_year = (kal_uint8) almTime.u1Year;
            rtctime->data_time.rtc_mon = almTime.u1Mon;
            rtctime->data_time.rtc_wday = almTime.u1WDay;
            break;
        default:
            kal_trace(TRACE_FUNC, WARNING_UEM_OUT_OF_RANGE);
            break;
    }
    return result;
}

/*****************************************************************************
*  Function 
*     l4cuem_rtc_set_time_req
*  DESCRIPTION
*     
*  PARAMETERS
*       ...  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_rtc_set_time_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc_type            [IN]        
 *  rtctime             [IN]        
 *  setting_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool l4cuem_rtc_set_time_req(kal_uint8 rtc_type, rtc_alarm_info_struct rtctime, kal_uint8 setting_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    RTC_CTRL_GET_TIME_T l_rtctime = {0};
    RTC_CTRL_SET_TIME_T setTime;
    RTC_CTRL_SET_ALARM_TIME_T setAlarmTime;
    RTC_CTRL_IS_TIME_VALID_T validTime;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_RTC_SET_TIME);

    /* Validate the time*/
    validTime.u1Day = rtctime.data_time.rtc_day;
    validTime.u1Hour = rtctime.data_time.rtc_hour;
    validTime.u1Min = rtctime.data_time.rtc_min; 
    validTime.u1Sec = rtctime.data_time.rtc_sec;
    validTime.u1Year = rtctime.data_time.rtc_year;
    validTime.u1Mon = rtctime.data_time.rtc_mon;
    validTime.u1WDay = rtctime.data_time.rtc_wday;		
    validTime.isTimeValid = DCL_TRUE;
    
    if (!uem_rtc_istimevalid(&validTime))
    {
        return KAL_FALSE;
    }
    
    switch (setting_type)   /* rtc_setting_type_enum */
    {
        case RTC_SETTING_TYPE_DATE:
            //RTC_GetTime(&l_rtctime);
            uem_rtc_gettime(&l_rtctime);
            l_rtctime.u1Year= rtctime.data_time.rtc_year;
            l_rtctime.u1Mon= rtctime.data_time.rtc_mon;
            l_rtctime.u1Day= rtctime.data_time.rtc_day;
            l_rtctime.u1WDay= rtctime.data_time.rtc_wday;
            break;

        case RTC_SETTING_TYPE_TIME:
            //RTC_GetTime(&l_rtctime);
            uem_rtc_gettime(&l_rtctime);
            l_rtctime.u1Hour= rtctime.data_time.rtc_hour;
            l_rtctime.u1Min= rtctime.data_time.rtc_min;
            l_rtctime.u1Sec= rtctime.data_time.rtc_sec;
            break;

        case RTC_SETTING_TYPE_DATETIME:
        default:
            l_rtctime.u1Year = rtctime.data_time.rtc_year;
            l_rtctime.u1Mon = rtctime.data_time.rtc_mon;
            l_rtctime.u1Day = rtctime.data_time.rtc_day;
            l_rtctime.u1Hour = rtctime.data_time.rtc_hour;
            l_rtctime.u1Min = rtctime.data_time.rtc_min;
            l_rtctime.u1WDay = rtctime.data_time.rtc_wday;
            l_rtctime.u1Sec = rtctime.data_time.rtc_sec;
            break;
    }

    switch (rtc_type)
    {
        case RTC_TIME_CLOCK_IND:
    #ifdef __DRM_V02__
		{
			applib_time_struct old_time, new_time;

			applib_dt_get_rtc_time(&old_time);
			//RTC_InitTC_Time(&l_rtctime);
			setTime.u1Day = l_rtctime.u1Day;
                     setTime.u1Hour = l_rtctime.u1Hour;
                     setTime.u1Min = l_rtctime.u1Min;
                     setTime.u1Mon = l_rtctime.u1Mon;
                     setTime.u1Sec = l_rtctime.u1Sec;
                     setTime.u1WDay = l_rtctime.u1WDay;
                     setTime.u1Year = l_rtctime.u1Year;
                     uem_rtc_settime(&setTime);
                     
			applib_dt_get_rtc_time(&new_time);

			DRM_update_local_time(&old_time, &new_time, KAL_FALSE);
		}
    #else
        //RTC_InitTC_Time(&l_rtctime);
        setTime.u1Day = l_rtctime.u1Day;
         setTime.u1Hour = l_rtctime.u1Hour;
         setTime.u1Min = l_rtctime.u1Min;
         setTime.u1Mon = l_rtctime.u1Mon;
         setTime.u1Sec = l_rtctime.u1Sec;
         setTime.u1WDay = l_rtctime.u1WDay;
         setTime.u1Year = l_rtctime.u1Year;
         uem_rtc_settime(&setTime);

    #endif            



            uem_rtc_config(
                uem_rtc_alarm_format_convert(DEVICE_AL_EN_NoChange),
                uem_rtc_clock_format_convert(DEVICE_TC_EN_ChkM));
            break;
        case RTC_ALARM_IND:
            if (rtctime.alarm_index < MAX_ALARM_NUM)
            {
                //RTC_SetAlarm(&l_rtctime);
                setAlarmTime.u1Day = l_rtctime.u1Day;
                 setAlarmTime.u1Hour = l_rtctime.u1Hour;
                 setAlarmTime.u1Min = l_rtctime.u1Min;
                 setAlarmTime.u1Mon = l_rtctime.u1Mon;
                 setAlarmTime.u1Sec = l_rtctime.u1Sec;
                 setAlarmTime.u1WDay = l_rtctime.u1WDay;
                 setAlarmTime.u1Year = l_rtctime.u1Year;
                uem_rtc_setalarmtime(&setAlarmTime);
                
                uem_rtc_config(
                    uem_rtc_alarm_format_convert((rtc_alarm_format_enum)rtctime.alarm_format),
                    uem_rtc_clock_format_convert(DEVICE_TC_EN_NoChange));
            }
            else
            {
                kal_trace(TRACE_FUNC, WARNING_UEM_OUT_OF_RANGE);
            }
            break;
        default:
            kal_trace(TRACE_FUNC, WARNING_UEM_OUT_OF_RANGE);
            break;
    }
    return KAL_TRUE;
}

#if 0 //slim
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
*   Function 
*      l4cuem_rtc_cnfg_format_req
*   DESCRIPTION
*      The function is used to set the RTC format.
*   PARAMETERS
*      rtctime   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_rtc_cnfg_format_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc_type            [IN]        
 *  rtc_alarm_id        [IN]        
 *  rtc_format_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_rtc_cnfg_format_req(kal_uint8 rtc_type, kal_uint8 rtc_alarm_id, kal_uint8 rtc_format_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_RTC_CNFG_FORMAT);

    switch (rtc_type)
    {
        case RTC_TIME_CLOCK_IND:
            uem_rtc_config(
                uem_rtc_alarm_format_convert(DEVICE_AL_EN_NoChange),
                uem_rtc_clock_format_convert((rtc_clock_format_enum)rtc_format_id));
            break;
        case RTC_ALARM_IND:
            if (rtc_alarm_id < MAX_ALARM_NUM)
            {
                uem_rtc_config(
                    uem_rtc_alarm_format_convert((rtc_alarm_format_enum)rtc_format_id),
                    uem_rtc_clock_format_convert(DEVICE_TC_EN_NoChange));
            }
            break;
        default:
            break;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_rtc_delete_date_time_req
*   DESCRIPTION
*      The function is used to set the RTC format.
*   PARAMETERS
*      rtctime   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_rtc_delete_date_time_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc_type            [IN]        
 *  rtc_alarm_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_rtc_delete_date_time_req(kal_uint8 rtc_type, kal_uint8 rtc_alarm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_RTC_DELETE_DATE_TIME);

    switch (rtc_type)
    {
        case RTC_TIME_CLOCK_IND:
            l4cuem_rtc_cnfg_format_req(rtc_type, rtc_alarm_id, DEVICE_TC_EN_None);
            break;
        case RTC_ALARM_IND:
            l4cuem_rtc_cnfg_format_req(rtc_type, rtc_alarm_id, DEVICE_AL_EN_None);
            break;
        default:
            break;
    }
}

#if 0 //slim
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
*   Function 
*      l4cuem_speech_set_mode_req
*   DESCRIPTION
*      The function is used to set the speech mode on/off while there is in a call setup.
*   PARAMETERS
*      speech_mode_onoff   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_speech_set_mode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  speech_mode_onoff       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_speech_set_mode_req(kal_bool speech_mode_onoff, kal_uint8 rat_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, INFO_UEM_SPEECH_SET_MODE, speech_mode_onoff);

#ifdef __MTK_TARGET__
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0 //.HAL    

    l4cuem_bmt_set_callstate(speech_mode_onoff);
    
#endif /* __MTK_TARGET__ */ 

    uem_send_msg_to_aud(MSG_ID_MEDIA_AUD_SP_SET_MODE_REQ, (kal_uint32) speech_mode_onoff, (kal_uint8)rat_mode);
}

/*****************************************************************************
*   Function 
*      l4cuem_call_status_ind
*   DESCRIPTION
*      The function is used to inform AUX if a calling is being set, connected or disconected.
*   PARAMETERS
*      ind_type   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_call_status_req_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ind_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_call_status_req_ind(kal_uint8 ind_type)
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
#endif /* MODEM only*/

}

/*****************************************************************************
*   Function 
*      l4cuem_set_mute_req
*   DESCRIPTION
*      The function is used to turn on/off the microphone.
*   PARAMETERS
*      mute_onoff   IN   
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_set_mute_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_device        [IN]        
 *  mute_onoff          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_set_mute_req(kal_uint8 audio_device, kal_bool mute_onoff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_SET_MUTE);

    /* store the audio mute flag */
    uem_audio_set_mute(audio_device, mute_onoff);

    uem_send_msg_to_aud(MSG_ID_MEDIA_AUD_MUTE_REQ, (kal_uint32) audio_device, (kal_uint32) mute_onoff);
}

#if 0 //slim
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
#endif
/*****************************************************************************
*   Function 
*      l4cuem_gpio_set_level_req
*   DESCRIPTION
*      The function is used to set the level of the GPIO device including the vibrator.
*   PARAMETERS
*      gpio_dev_type      IN
*      gpio_dev_level      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_gpio_set_level_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gpio_dev_type       [IN]        
 *  gpio_dev_level      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_gpio_set_level_req(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_GPIO_SET_LEVEL, gpio_dev_type, gpio_dev_level);

//#if defined(__BK_LIGHT_20LEVEL_SUPPORT__) || defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)
#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)
    if (gpio_dev_type == GPIO_DEV_LED_BACKLIGHT_DIMMING)
    {
        uem_set_led_backlight_off(gpio_dev_type, gpio_dev_level);
        return;
    }

    if (gpio_dev_type == GPIO_DEV_LED_MAINLCD)
    {
        uem_stop_led_backlight_off();
    }
#endif    

    if (gpio_dev_type == GPIO_DEV_VIBRATOR)
    {
        uem_stop_pattern((PATTERN_ID)(VIB_PATTERN_3+1));
        if (gpio_dev_level != LED_LIGHT_LEVEL0)
        {
            uem_set_vib_state(KAL_TRUE);
        }
        else
        {
            uem_set_vib_state(KAL_FALSE);
        }
    }

    uem_set_gpio_status(gpio_dev_type, gpio_dev_level); /* Cylen 2005/08/23 GPIO Setting */
    custom_uem_gpio_set_level(gpio_dev_type, gpio_dev_level);
}

/*****************************************************************************
*   Function 
*      l4cuem_pattern_play_req
*   DESCRIPTION
*      The function is used to play vibrator pattern.
*   PARAMETERS
*      pattern      IN
*      action      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_pattern_play_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pattern     [IN]        
 *  action      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_pattern_play_req(kal_uint8 pattern, kal_uint8 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_play_pattern((PATTERN_ID)pattern, (PATTERN_TYPE)action);
}

/*****************************************************************************
*   Function 
*     l4cuem_pattern_stop_req
*   DESCRIPTION
*      The function is used to play led pattern.
*   PARAMETERS
*      pattern      IN
*      action      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_pattern_stop_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pattern     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_pattern_stop_req(kal_uint8 pattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_stop_pattern((PATTERN_ID)pattern);
}

/*****************************************************************************
*   Function 
*      l4cuem_get_equip_id_req
*   DESCRIPTION
*      Retrieve the string of the equipment ID.
*   PARAMETERS
*      equip_id      IN
*   RETURNS
*      kal_uint8*
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_equip_id_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  equip_id            [IN]        
 *  equip_string        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_equip_id_req(kal_uint8 equip_id, kal_uint8 *equip_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_GET_EQUIP_ID);

    ASSERT(equip_string != NULL);   /* invalid address */

    uem_get_equip_id(equip_id, equip_string);
}

/*****************************************************************************
*   Function 
*      l4cuem_get_battery_status_req
*   DESCRIPTION
*      Retrieve the battery status.
*   PARAMETERS
*      battery_status      OUT
*     battery_vol         OUT
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_battery_status_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  battery_status      [?]     
 *  battery_vol         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_battery_status_req(kal_uint8 *battery_status, kal_uint8 *battery_vol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    uem_bmt_struct bmt_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_GET_BATTERY_STATUS);

    ASSERT((battery_status != NULL) && (battery_vol != NULL));  /* invalid address */

    uem_get_bat_status(&bmt_status);
    *battery_status = bmt_status.status;
    *battery_vol = uem_vbat_level_convert(bmt_status.volt);
}

/*****************************************************************************
*   Function 
*      l4cuem_set_silent_mode_req
*   DESCRIPTION
*      Set the silent.
*   PARAMETERS
*      is_silent      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_set_silent_mode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_silent       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_set_silent_mode_req(kal_bool is_silent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_SET_SILENT_MODE);

    uem_set_silent_mode(is_silent);
}

/*****************************************************************************
*   Function 
*      l4cuem_get_silent_mode_req
*   DESCRIPTION
*      Set the silent.
*   PARAMETERS
*      mode  OUT
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_silent_mode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_silent       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_silent_mode_req(kal_uint8 *is_silent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_GET_SILENT_MODE);

    ASSERT(is_silent != NULL);  /* invalid address */

    *is_silent = uem_get_silent_mode();
}

/*****************************************************************************
*   Function 
*      l4cuem_set_alert_mode_req
*   DESCRIPTION
*      Set the alert mode.
*   PARAMETERS
*      void
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_set_alert_mode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  alert_mode      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_set_alert_mode_req(kal_uint8 alert_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_SET_ALERT_MODE);

    uem_set_alert_mode(alert_mode);
}

#if 0 //slim
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
#endif
/*****************************************************************************
*   Function 
*      l4cuem_set_greeting_text_req
*   DESCRIPTION
*      RMI requests L4C to set date format. Please reference the AT command "+CSDF".
*   PARAMETERS
*      mode      OUT
*      greeting_text       OUT
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_set_greeting_text_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode                [IN]        
 *  text_dcs            [IN]        
 *  greeting_text       [?]         
 *  no_text             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_set_greeting_text_req(kal_bool mode, kal_uint8 text_dcs, kal_uint8 *greeting_text, kal_uint8 no_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_SET_GREETING_TEXT);

    ASSERT(greeting_text != NULL);

    if (no_text >= UEM_GREETING_LEN)
    {
        no_text = UEM_GREETING_LEN - 1;
    }
    greeting_text[no_text] = '\0';

    uem_set_greeting_text(mode, text_dcs, greeting_text, no_text);
}

#if 0 //slim
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
#endif
/*****************************************************************************
*   Function 
*      l4cuem_gpio_get_level_req
*   DESCRIPTION
*      L4C requests UEM to get gpio value. Please reference the AT command "+CVIB".
*   PARAMETERS
*      mode      OUT
*      greeting_text       OUT
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_gpio_get_level_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gpio_device         [IN]        
 *  gpio_dev_level      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_gpio_get_level_req(kal_uint8 gpio_device, kal_uint8 *gpio_dev_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_GPIO_GET_LEVEL);

    ASSERT(gpio_dev_level != NULL); /* invalid address */

    if (gpio_device < MAX_GPIO_DEVICE_NUM)
    {
        *gpio_dev_level = uem_get_gpio_status(gpio_device);
    }
    else
    {
        *gpio_dev_level = 0;
        kal_trace(TRACE_WARNING, WARNING_UEM_OUT_OF_RANGE);
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_equip_set_cc_req
*   DESCRIPTION
*      L4C requests UEM to set the country code. Please reference the AT command "+GCI".
*   PARAMETERS
*      country_code      IN
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_equip_set_cc_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  country_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_equip_set_cc_req(kal_uint8 country_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_EQUIP_SET_CC);

    g_uem_cntx_p->rmi_data.country_code = country_code;
}

#if 0 //slim
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
#endif
/*****************************************************************************
*   Function 
*      l4cuem_set_date_time_format_req
*   DESCRIPTION
*      L4C requests UEM to store date format. Please reference the AT command "+CSDF".
*   PARAMETERS
*      lang_id      OUT
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_set_date_time_format_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_date_set     [IN]        
 *  mode            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_set_date_time_format_req(kal_bool is_date_set, kal_uint8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_SET_DATE_TIME_FORMAT);

    /* ref: date_format_enum/time_format_enum */
    uem_set_datetime_format(is_date_set, mode);
}

/*****************************************************************************
*   Function 
*      l4cuem_get_date_time_format_req
*   DESCRIPTION
*      L4C requests UEM to retrieve date format. Please reference the AT command "+CSDF".
*   PARAMETERS
*      lang_id      OUT
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_date_time_format_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_date_set     [IN]        
 *  mode            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_date_time_format_req(kal_bool is_date_set, kal_uint8 *mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_GET_DATE_TIME_FORMAT);

    ASSERT(mode != NULL);   /* invalid address */

    /* ref: date_format_enum/time_format_enum */
    *mode = uem_get_datetime_format(is_date_set);
}

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
#if 0 //slim
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
#endif
/* under construction !*/
/* under construction !*/
#endif

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
#if 0 //slim
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
#endif
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
*   Function 
*      l4cuem_power_reset
*   DESCRIPTION
*      power reset 
*   PARAMETERS
*      kal_uint8 reset_type
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_power_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  reset_type      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_power_reset(
            kal_uint8 reset_type /* pmic_reset_type_enum */ )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool res = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_POWER_RESET);

        	
    switch (reset_type)
    {
        case NORMAL_RESET:
        {
            /* Turn off backlight */
            custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, 0);        
        	
            /* New_USB_Mode */
            nvram_shutdown_handler();
            
            //PW_Set_Switch2Idle_Flag();
            uem_drv_switch2idle_flag();
            l4cuem_reset_watch_dog();
            break;
        }
        case CHARGING_RESET:
        {
            /* Turn off backlight */
            custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, 0);        
        	
            /* New_USB_Mode */
            nvram_shutdown_handler();

            //DRV_POWEROFF();
            uem_drv_power_off();
            //DRV_RESET();
            l4cuem_reset_watch_dog();

            break;
        }
        case ALARM_RESET:
        {
            /* New_USB_Mode */
        #ifdef __NVRAM_IN_USB_MS__
            nvram_shutdown_handler();
        #endif 
            if (POWER_ON_PRECHARGE != uem_get_poweron_mode())
            {
                uem_send_msg_to_l4c(MSG_ID_L4CUEM_STARTUP_CNF, NULL);
            }
            break;
        }
        default:
        {
            res = KAL_FALSE;
            kal_trace(TRACE_WARNING, WARNING_UEM_OUT_OF_RANGE);
            break;
        }
    }
    return res;
}

/*****************************************************************************
*  Function 
*     l4cuem_get_audio_profile_req
*  DESCRIPTION
*      
*  PARAMETERS
*      
*  RETURNS
*      
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_audio_profile_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_audio_profile_req(kal_uint8 src_id, kal_uint8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    uem_send_msg_to_aud(MSG_ID_MEDIA_AUD_GET_AUDIO_PROFILE_REQ, mode, src_id);
    //    aud_get_audio_profile_req(aud_profile);
    //    return KAL_TRUE;
}

/*****************************************************************************
*  Function 
*     l4cuem_get_audio_param_req
*  DESCRIPTION
*      
*  PARAMETERS
*      
*  RETURNS
*      
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_audio_param_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_audio_param_req(kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_send_msg_to_aud(MSG_ID_MEDIA_AUD_GET_AUDIO_PARAM_REQ, (kal_uint32) src_id);
    /* aud_get_audio_param_req( audio_param ); */
}


#if defined(__AMRWB_LINK_SUPPORT__)
void l4cuem_get_aduio_wb_param_req(kal_uint8 src_id, l4_wb_audio_para_action_enum option)
{
    kal_uint32 msg_id;
    switch(option)
    {
        case L4_WB_AUDIO_INPUT_FIR:
        {
            msg_id = MSG_ID_MEDIA_AUD_GET_AUDIO_WB_INPUT_FIR_PARAM_REQ;
            break;
        }
        case L4_WB_AUDIO_OUTPUT_FIR:
        {
            msg_id = MSG_ID_MEDIA_AUD_GET_AUDIO_WB_OUTPUT_FIR_PARAM_REQ;
            break;
        }
        case L4_WB_ADUIO_MODE_PARAM:
        {
            msg_id = MSG_ID_MEDIA_AUD_GET_AUDIO_WB_MODE_PARAM_REQ;
            break;
        }
        default:
            return;
    }
    uem_send_msg_to_aud(msg_id, (kal_uint32)src_id);
}


void l4cuem_set_aduio_wb_param_req(kal_uint8 src_id, l4_wb_audio_para_action_enum option, void *new_param)
{
    kal_uint32 msg_id;
    switch(option)
    {
        case L4_WB_AUDIO_INPUT_FIR:
        {
            msg_id = MSG_ID_MEDIA_AUD_SET_AUDIO_WB_INPUT_FIR_PARAM_REQ;
            break;
        }
        case L4_WB_AUDIO_OUTPUT_FIR:
        {
            msg_id = MSG_ID_MEDIA_AUD_SET_AUDIO_WB_OUTPUT_FIR_PARAM_REQ;
            break;
        }
        case L4_WB_ADUIO_MODE_PARAM:
        {
            msg_id = MSG_ID_MEDIA_AUD_SET_AUDIO_WB_MODE_PARAM_REQ;
            break;
        }
        default:
            return;
    }
    uem_send_msg_to_aud(msg_id, (kal_uint32)src_id, new_param);
}
#endif


/*****************************************************************************
*  Function 
*     l4cuem_set_audio_mode
*  DESCRIPTION
*      
*  PARAMETERS
*      
*  RETURNS
*      
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_set_audio_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_set_audio_mode(kal_uint8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_send_msg_to_aud(MSG_ID_MEDIA_AUD_SET_AUDIO_MODE_REQ, (kal_uint32) mode);
}

/*****************************************************************************
*  Function 
*     l4cuem_get_adc_all_channel_stop_req
*  DESCRIPTION
*      
*  PARAMETERS
*      
*  RETURNS
*      
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_adc_all_channel_stop_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_adc_all_channel_stop_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_adc_on = 0;
}

/*****************************************************************************
*  Function 
*     l4cuem_get_adc_all_channel_start_req
*  DESCRIPTION
*      
*  PARAMETERS
*      
*  RETURNS
*      
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_adc_all_channel_start_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_get_adc_all_channel_start_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    uem_adc_on = 1;
    uem_send_msg_to_aux(MSG_ID_READ_ALL_ADC_CHANNEL_REQ);
}

/*****************************************************************************
*  Function 
*     l4cuem_get_hw_level_req
*  DESCRIPTION
*      
*  PARAMETERS
*      
*  RETURNS
*      
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_get_hw_level_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hw_level        [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_get_hw_level_req(l4cuem_set_hw_level_req_struct *hw_level)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MULTI_LEVEL_BACKLIGHT_SUPPORT__
#if !defined(LED_MAINLCD_USE_PWM_NONE)      
/* under construction !*/
/* under construction !*/
#if defined(LED_MAINLCD_USE_PWM_1)            
/* under construction !*/
/* under construction !*/
#elif defined(LED_MAINLCD_USE_PWM_2)            
/* under construction !*/
/* under construction !*/
#elif defined(LED_MAINLCD_USE_PWM_3)            
/* under construction !*/
/* under construction !*/
#endif // End of #if defined(LED_MAINLCD_USE_PWM_1)
/* under construction !*/
#endif // End of #if !defined(LED_MAINLCD_USE_PWM_NONE)       
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef DUAL_LCD
/* under construction !*/
        #endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef DUAL_LCD
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* DUAL_LCD */ 
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
#endif
    return KAL_TRUE;
}

/*****************************************************************************
*  Function 
*     l4cuem_usbconfig_req
*  DESCRIPTION
*     Config USB
*  PARAMETERS
*  
*  
*  RETURNS
*     void
*  GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_usbconfig_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_id          [IN]        
 *  mode            [IN]        
 *  reserved        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_usbconfig_req(kal_uint8 src_id, kal_uint8 mode, kal_uint32 reserved)
{
#ifdef __USB_ENABLE__	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 usb_action_4_drv;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uem_cntx_p->usb_msg_src_id = src_id;

    usb_action_4_drv = (kal_uint32) uem2drv_usb_config_action_convert(mode);
    uem_send_msg_to_usbms(MSG_ID_DRVUEM_USBCFG_REQ, usb_action_4_drv, (kal_uint32) reserved);
#endif /* __USB_ENABLE__ */ 
}


/*****************************************************************************
*  Function 
*     ueml4c_em_pmic_config_hdlr
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
 *  l4cuem_em_pmic_config_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_id              [IN]        
 *  request_type        [IN]        
 *  request             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_em_pmic_config_req(kal_uint8 src_id, kal_uint8 request_type, pmic_config_param_struct request)
{
#if 0 /* MODEM only*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(MT6318) && defined(PLUTO_MMI)
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
            #ifdef DUAL_LCD
/* under construction !*/
            #endif /* DUAL_LCD */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef DUAL_LCD
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* DUAL_LCD */ 
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
#else
/* under construction !*/
#endif /* defined(MT6318) */ 
#endif /* MODEM only*/
}

/*****************************************************************************
*  Function 
*     l4cuem_battery_status_res_req
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
 *  l4cuem_battery_status_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_battery_status_res_req(kal_uint8 status_type)
{
#if defined(PLUTO_MMI)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (status_type)
    {
        case PMIC_USB_NO_CHARGER_OUT:
        case PMIC_USB_CHARGER_OUT:  /* USB Charger out */
        {
            /* set accessory state */
            FLAG_SET_OFF(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB_CHARGER);
            /* Set not in progress */
            FLAG_SET_OFF(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER);

            /* check if prev state is matched with latest state */
            if (!is_status_matched(UEM_ACCESSORY_TYPE_USB_CHARGER))
            {
                /* not matched, Notify MMI with the latest statue */
                l4cuem_battery_status_ind(PMIC_USB_CHARGER_IN, g_uem_cntx_p->bmt_status.disp_level);

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER);
            }
            break;
        }
        case PMIC_USB_NO_CHARGER_IN:
        case PMIC_USB_CHARGER_IN:   /* USB Charger in */
        {
            /* set accessory state */
            FLAG_SET_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB_CHARGER);
            /* Set not in progress */
            FLAG_SET_OFF(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER);

            /* check if prev state is matched with latest state */
            if (!is_status_matched(UEM_ACCESSORY_TYPE_USB_CHARGER))
            {
                /* not matched, Notify MMI with the latest statue */
                l4cuem_battery_status_ind(PMIC_USB_CHARGER_OUT, g_uem_cntx_p->bmt_status.disp_level);

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB_CHARGER);
            }
            break;
        }
        case PMIC_CHARGER_OUT:
        {
        #ifdef __MTK_TARGET__
            /* set accessory state */
            FLAG_SET_OFF(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_CHARGER);
            /* Set not in progress */
            FLAG_SET_OFF(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CHARGER);

            /* check if prev state is matched with latest state */
            if (!is_status_matched(UEM_ACCESSORY_TYPE_CHARGER))
            {
                /* not matched, Notify MMI with the latest statue */
                l4cuem_battery_status_ind(PMIC_CHARGER_IN, g_uem_cntx_p->bmt_status.disp_level);

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CHARGER);
            }
        #endif
            break;
        }
        case PMIC_CHARGER_IN:   /* Charger plug in */
        {
        #ifdef __MTK_TARGET__
            /* set accessory state */
            FLAG_SET_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_CHARGER);
            /* Set not in progress */
            FLAG_SET_OFF(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CHARGER);

            /* check if prev state is matched with latest state */
            if (!is_status_matched(UEM_ACCESSORY_TYPE_CHARGER))
            {
                /* not matched, Notify MMI with the latest statue */
                l4cuem_battery_status_ind(PMIC_CHARGER_OUT, g_uem_cntx_p->bmt_status.disp_level);

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CHARGER);
            }
        #endif
            break;
        }
    }
#endif /* defined(PLUTO_MMI) */ 
}

/*****************************************************************************
*  Function 
*     l4cuem_usbdetect_res_req
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
 *  l4cuem_usbdetect_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  action      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_usbdetect_res_req(kal_uint8 action)
{
#if defined(PLUTO_MMI)
#ifdef __USB_ENABLE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (action == DEVUSB_DETECT_ACTION_PLUGIN)
    {
        /* set accessory state */
        FLAG_SET_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB);
        /* Set not in progress */
        FLAG_SET_OFF(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB);

        /* check if prev state is matched with latest state */
        if (!is_status_matched(UEM_ACCESSORY_TYPE_USB))
        {
            /* not matched, Notify MMI with the latest statue */
            l4cuem_usbdetect_ind(DEVUSB_DETECT_ACTION_PLUGOUT);

            /* Set in progress */
            FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB);
        }
    }
    else if (action == DEVUSB_DETECT_ACTION_PLUGOUT)
    {
        /* set accessory state */
        FLAG_SET_OFF(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_USB);
        /* Set not in progress */
        FLAG_SET_OFF(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB);

        /* check if prev state is matched with latest state */
        if (!is_status_matched(UEM_ACCESSORY_TYPE_USB))
        {
            /* not matched, Notify MMI with the latest statue */
            l4cuem_usbdetect_ind(DEVUSB_DETECT_ACTION_PLUGIN);

            /* Set in progress */
            FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_USB);
        }
    }
#endif /* __USB_ENABLE__ */ 
#endif /* defined(PLUTO_MMI) */ 
}

/*****************************************************************************
*  Function 
*     l4cuem_em_dcm_enable_req
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
 *  l4cuem_em_dcm_enable_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  enable      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_em_dcm_enable_req(kal_bool enable)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(DCM_ENABLE)
    extern kal_uint8 uem_dcm_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable)
    {
        DCM_Enable(uem_dcm_handle);
    }
    else
    {
        DCM_Disable(uem_dcm_handle);
    }
#endif /* defined(DCM_ENABLE) */ 
#endif /* __MTK_TARGET__ */ 
}

/*****************************************************************************
*  Function 
*     l4cuem_em_uart_poweron_req
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
 *  l4cuem_em_uart_poweron_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  uart_power_setting      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_em_uart_poweron_req(kal_uint8 uart_power_setting)
{
#if 0
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
#endif /* __MTK_TARGET__ */ 
#endif
}


/*****************************************************************************
*	Function 
*		l4cuem_em_rf_test_gsm_req
*	DESCRIPTION
*		...
*	PARAMETERS
*	
*	
*	RETURNS
*		void
*	GLOBALS AFFECTED
*****************************************************************************/
void l4cuem_em_rf_test_gsm_req(kal_uint8 src_id, kal_uint8 request_type, rf_test_gsm_param_struct request)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void* local_data_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__    
    switch(request_type)
    {
        case RF_TEST_GSM_STOP:
        {
            local_data_ptr = NULL;
          
            uem_send_msg_to_l1(MSG_ID_L4CL1_EM_RF_TEST_GSM_STOP_REQ, local_data_ptr);
            
            //RFTool_GSM_Stop();
            break;		
        }
        case RF_TEST_GSM_TX_TEST:
        {
            rf_test_gsm_tx_test_struct *req = &(request.gsm_tx_test);
            
            local_data_ptr = (rf_test_gsm_tx_test_struct*) construct_local_para(sizeof(rf_test_gsm_tx_test_struct), TD_CTRL);
            
            ((rf_test_gsm_tx_test_struct*)local_data_ptr)->band = req->band;
            ((rf_test_gsm_tx_test_struct*)local_data_ptr)->arfcn = req->arfcn;
            ((rf_test_gsm_tx_test_struct*)local_data_ptr)->tsc = req->tsc;
            ((rf_test_gsm_tx_test_struct*)local_data_ptr)->pcl = req->pcl;
            ((rf_test_gsm_tx_test_struct*)local_data_ptr)->afc = req->afc;
            ((rf_test_gsm_tx_test_struct*)local_data_ptr)->pattern = req->pattern;
            
            uem_send_msg_to_l1(MSG_ID_L4CL1_EM_RF_TEST_GSM_TX_TEST_REQ, local_data_ptr);  
                      
            //RFTool_GSM_TxTest(req->band, req->arfcn, req->tsc, req->pcl, req->afc, req->pattern);
            break;
        }
        case RF_TEST_GSM_RX_TEST:
        {
            rf_test_gsm_rx_test_struct *req = &(request.gsm_rx_test);

            local_data_ptr = (rf_test_gsm_rx_test_struct*) construct_local_para(sizeof(rf_test_gsm_rx_test_struct), TD_CTRL);
            
            ((rf_test_gsm_rx_test_struct*)local_data_ptr)->band = req->band;
            ((rf_test_gsm_rx_test_struct*)local_data_ptr)->arfcn = req->arfcn;
            ((rf_test_gsm_rx_test_struct*)local_data_ptr)->gain = req->gain;
            ((rf_test_gsm_rx_test_struct*)local_data_ptr)->pattern = req->pattern;
            
            uem_send_msg_to_l1(MSG_ID_L4CL1_EM_RF_TEST_GSM_RX_TEST_REQ, local_data_ptr);
            //RFTool_GSM_RxTest(req->band, req->arfcn, req->gain, req->pattern);
            break;
        }
        case RF_TEST_GSM_POWER_SCAN:
        {
            rf_test_gsm_power_scan_struct *req = &(request.gsm_power_scan);
            
            local_data_ptr = (rf_test_gsm_power_scan_struct*) construct_local_para(sizeof(rf_test_gsm_power_scan_struct), TD_CTRL);
            
            ((rf_test_gsm_power_scan_struct*)local_data_ptr)->band = req->band;
            ((rf_test_gsm_power_scan_struct*)local_data_ptr)->arfcn_in = req->arfcn_in;
            
            uem_send_msg_to_l1(MSG_ID_L4CL1_EM_RF_TEST_GSM_POWER_SCAN_REQ, local_data_ptr);
            //RFTool_GSM_PowerScan(req->band, req->arfcn_in, uemdrv_rf_test_gsm_powerscan_callback);       
            return;
            
            break;
        }        
        default:
            break;
    }
#endif /* #ifdef __MTK_TARGET__ */

    l4cuem_rf_test_gsm_cnf(src_id, request_type, request);
}


/*****************************************************************************
*	Function 
*		l4cuem_em_rf_test_wifi_req
*	DESCRIPTION
*		...
*	PARAMETERS
*	
*	
*	RETURNS
*		void
*	GLOBALS AFFECTED
*****************************************************************************/
#if defined(__WIFI_SUPPORT__)
void l4cuem_em_rf_test_wifi_req(kal_uint8 src_id, kal_uint8 request_type, rf_test_wifi_param_struct request)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(request_type)
    {
        case RF_TEST_WIFI_STOP:
        {
            RFTool_WiFi_Stop();
            break;		
        }
        case RF_TEST_WIFI_TEST_MODE:
        {
            RFTool_WiFi_EnterTestMode();
            break;		
        }
        case RF_TEST_WIFI_NORMAL_MODE:
        {
            RFTool_WiFi_EnterNormalMode();
            break;
        }
        case RF_TEST_WIFI_TX_GET_DAC_OFFSET:
        {
            RFTool_WiFi_DacDCOffset(&(request.wifi_get_dac.ich), &(request.wifi_get_dac.qch));
            break;
        }        
        case RF_TEST_WIFI_TX_OUTPUT_POWER:
        {
            rf_test_wifi_tx_common_struct *req = &(request.wifi_tx_common);
            wndrv_test_tx_struct contx_tx;

            contx_tx.ch_freq = req->ch_freq;
            contx_tx.tx_rate = (wndrv_test_rate_enum)req->tx_rate;
            contx_tx.txAnt = req->tx_ant;
            contx_tx.tx_gain_dac = req->gain;
            contx_tx.txBw = req->txBw;
            contx_tx.txGI = req->txGI;
            contx_tx.txMode = req->txMode;

            RFTool_WiFi_ContTx(req->contry_code, contx_tx);
            
            break;
        }         
        case RF_TEST_WIFI_TX_CARRIER_SUPP:
        {
            rf_test_wifi_tx_common_struct *req = &(request.wifi_tx_common);
            wndrv_test_tx_struct carrier_supp;

            carrier_supp.ch_freq = req->ch_freq;
            carrier_supp.tx_rate = (wndrv_test_rate_enum)req->tx_rate;
            carrier_supp.txAnt = req->tx_ant;
            carrier_supp.tx_gain_dac = req->gain;
            
            RFTool_WiFi_CarrierSupp(req->contry_code, carrier_supp);
            break;
        }
        case RF_TEST_WIFI_TX_LOCAL_FREQ:
        {
            rf_test_wifi_tx_common_struct *req = &(request.wifi_tx_common);
            wndrv_test_tx_struct local_freq;

            local_freq.ch_freq = req->ch_freq;
            local_freq.tx_rate = (wndrv_test_rate_enum)req->tx_rate;
            local_freq.txAnt = req->tx_ant;
            local_freq.tx_gain_dac = req->gain;

            RFTool_WiFi_LocalFreq(req->contry_code, local_freq);
            break;
        }
        case RF_TEST_WIFI_TX_CONT_PKT:
        {
            rf_test_wifi_tx_cont_pkt_struct *req = &(request.wifi_tx_cont_pkt);
            wndrv_test_pkt_tx_struct cont_tx;
            kal_uint8 i;

            cont_tx.ch_freq = req->ch_freq;
            cont_tx.tx_rate = (wndrv_test_rate_enum)req->tx_rate;
            cont_tx.txAnt = req->tx_ant;
            cont_tx.tx_gain_dac = req->gain;
            cont_tx.pktCount = req->pkt_count;
            cont_tx.pktInterval = req->pkt_interval;
            cont_tx.pktLength = req->pkt_length;
            cont_tx.pattern = (wndrv_test_pkt_tx_pattern_enum)req->tx_pattern;
            cont_tx.is_short_preamble = req->short_peramble;
            cont_tx.txBw = req->txBw;
            cont_tx.txGI = req->txGI;
            cont_tx.txMode = req->txMode;

            for (i=0 ; i<24; i++)
                cont_tx.mac_header[i] = req->mac_header[i];
             
            RFTool_WiFi_PktTx(req->contry_code, cont_tx);
            break;
        }
        case RF_TEST_WIFI_RX_CONT_PKT:
        {
            rf_test_wifi_rx_cont_pkt_struct *req = &(request.wifi_rx_cont_pkt);

            g_uem_cntx_p->src_id = src_id;
           
            RFTool_WiFi_PktRx(req->ch_freq,  uemdrv_rf_test_wifi_rx_pkt_callback);       

            return;
            
            break;
        }
        case RF_TEST_WIFI_POWER_SAVE:
        {
            rf_test_wifi_power_save_struct *req = &(request.wifi_power_save);

            RFTool_WiFi_PwrMgt((wndrv_test_pwr_mgt_enum)req->pwr_mgt);        
            break;
        }        
        case RF_TEST_WIFI_REG_MCR32_WRITE:
        {
            rf_test_wifi_reg_mcr32_write_struct *req = &(request.wifi_mcr32_write);

            RFTool_WiFi_MCR32_Write(req->mcr_index, req->mcr32);        
            break;
        }        
        case RF_TEST_WIFI_REG_MCR32_READ:
        {
            rf_test_wifi_reg_mcr32_read_struct *req = &(request.wifi_mcr32_read);

            RFTool_WiFi_MCR32_Read(req->mcr_index, &(request.wifi_mcr32_read.mcr32));        

            break;
        }
        case RF_TEST_WIFI_REG_MCR16_WRITE:
        {
            rf_test_wifi_reg_mcr16_write_struct *req = &(request.wifi_mcr16_write);

            RFTool_WiFi_MCR16_Write (req->mcr_index, req->mcr16);              
            break;
        }
        case RF_TEST_WIFI_REG_MCR16_READ:
        {
            rf_test_wifi_reg_mcr16_read_struct *req = &(request.wifi_mcr16_read);

            RFTool_WiFi_MCR16_Read(req->mcr_index, &(request.wifi_mcr16_read.mcr16));  
            break;
        }
        case RF_TEST_WIFI_REG_BBCR_WRITE:
        {
            rf_test_wifi_reg_bbcr_write_struct *req = &(request.wifi_bbcr_write);

            RFTool_WiFi_BBCR_Write(req->bbcr_index, req->bbcr);               
            break;
        }
        case RF_TEST_WIFI_REG_BBCR_READ:
        {
            rf_test_wifi_reg_bbcr_read_struct *req = &(request.wifi_bbcr_read);

            RFTool_WiFi_BBCR_Read(req->bbcr_index, &(request.wifi_bbcr_read.bbcr));   
            break;
        }
        case RF_TEST_WIFI_REG_EEPROM_WRITE:
        {
            rf_test_wifi_reg_eeprom_write_struct *req = &(request.wifi_eeprom_write);

            RFTool_WiFi_EEPROM_Write(req->eeprom_index, req->eeprom);       
            break;
        }
        case RF_TEST_WIFI_REG_EEPROM_READ: 
        {
            rf_test_wifi_reg_eeprom_read_struct *req = &(request.wifi_eeprom_read);

            RFTool_WiFi_EEPROM_Read(req->eeprom_index, &(request.wifi_eeprom_read.eeprom));       
            break;
        }    
        case RF_TEST_WIFI_REG_EFUSE_WRITE:
        {
            rf_test_wifi_reg_efuse_write_struct *req = &(request.wifi_efuse_write);
            
            RFTool_WiFi_EFUSE_Write(req->efuse_index, req->efuse);
            break;
        }
        case RF_TEST_WIFI_REG_EFUSE_READ:
        {
            rf_test_wifi_reg_efuse_read_struct *req = &(request.wifi_efuse_read);
            
            RFTool_WiFi_EFUSE_Read(req->efuse_index, &(request.wifi_efuse_read.efuse));
            break;
        }
        default:
            break;
    }

    l4cuem_rf_test_wifi_cnf(src_id, request_type, request);
}
#endif  /* #if defined(__WIFI_SUPPORT__) */	


/*****************************************************************************
*	Function 
*		l4cuem_em_fm_radio_config_req
*	DESCRIPTION
*		...
*	PARAMETERS
*	
*	
*	RETURNS
*		void
*	GLOBALS AFFECTED
*****************************************************************************/
void l4cuem_em_fm_radio_config_req(kal_uint8 src_id, kal_uint8 request_type, fm_radio_config_param_struct request)
{
#ifdef FM_RADIO_ENABLE
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(request_type)
    {
        case FM_RADIO_CMD_MONO:
        {
            fm_radio_mono_struct *req = &(request.fm_radio_mono);
            FMR_Radio_EngineerMode((kal_uint16)request_type, 0 , (kal_uint32)req->mono_enable);
            break;		
        }
        case FM_RADIO_CMD_STEREO:
        {
            fm_radio_stereo_struct *req = &(request.fm_radio_stereo);
            FMR_Radio_EngineerMode((kal_uint16)request_type, (kal_uint16)req->sblend_onoff , (kal_uint32)req->stereo_enable);
            break;
        }
        case FM_RADIO_CMD_RSSI:
        {
            fm_radio_rssi_struct *req = &(request.fm_radio_rssi);
            FMR_Radio_EngineerMode((kal_uint16)request_type, 0 , (kal_uint32)req->level);
            break;
        }
        case FM_RADIO_CMD_IF_COUNT:
        {
            fm_radio_if_count_delta_struct *req = &(request.fm_radio_if);
            FMR_Radio_EngineerMode((kal_uint16)request_type, 0 , (kal_uint32)req->item_value);       
            break;
        }        
        default:
            break;
    }

    l4cuem_fm_radio_config_cnf(src_id, request_type, request);
    
#endif /* #ifdef FM_RADIO_ENABLE */
}

/*****************************************************************************
*	Function 
*		l4cuem_em_fm_radio_config_req
*	DESCRIPTION
*		...
*	PARAMETERS
*	
*	
*	RETURNS
*		void
*	GLOBALS AFFECTED
*****************************************************************************/
void l4cuem_startup_cnf_rsp(void)
{
#ifdef PLUTO_MMI

#endif /* PLUTO_MMI */ 
}


/*****************************************************************************
 * FUNCTION
 *  l4cuem_gpio_detect_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_gpio_detect_res_req(kal_uint8 ext_gpio_device)
{
#if defined(PLUTO_MMI) && defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ext_gpio_device)
    {
        case EXT_DEV_CLAM_CLOSE:  /* Clam Close */
        {
            /* set accessory state */
            FLAG_SET_OFF(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_CLAM);
            /* Set not in progress */
            FLAG_SET_OFF(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CLAM);

            /* check if prev state is matched with latest state */
            if (!is_status_matched(UEM_ACCESSORY_TYPE_CLAM))
            {
                /* not matched, Notify MMI with the latest statue */
                l4cuem_gpio_detect_ind(EXT_DEV_CLAM_OPEN, KAL_TRUE);

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CLAM);
            }
            break;
        }
        case EXT_DEV_CLAM_OPEN:   /* Clam Open */
        {
            /* set accessory state */
            FLAG_SET_ON(g_uem_cntx_p->acc_prev_state, UEM_ACCESSORY_TYPE_CLAM);
            /* Set not in progress */
            FLAG_SET_OFF(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CLAM);

            /* check if prev state is matched with latest state */
            if (!is_status_matched(UEM_ACCESSORY_TYPE_CLAM))
            {
                /* not matched, Notify MMI with the latest statue */
                l4cuem_gpio_detect_ind(EXT_DEV_CLAM_CLOSE, KAL_TRUE);

                /* Set in Progress */
                FLAG_SET_ON(g_uem_cntx_p->acc_progress, UEM_ACCESSORY_TYPE_CLAM);
            }
            break;
        }
        default:
            break;
    }
#endif /* defined(PLUTO_MMI) && defined(__MTK_TARGET__)*/ 
}

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(MT6223PMU) && defined(PLUTO_MMI)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* if 0 */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif /* defined(PMU6223) */ 
#endif
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
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (defined(MT6238PMU)) && defined(PLUTO_MMI)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif /* defined(PMU6223) */ 
#endif
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
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0 //defined(MT6326) && defined(PLUTO_MMI)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif /* defined(PMU6223) */ 
#endif
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  l4cuem_lcd_set_contrast_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_silent       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void l4cuem_lcd_set_contrast_req(kal_uint8 lcd_id, kal_uint8 contrastlevel)
{
#if 0 //slim
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef DUAL_LCD
/* under construction !*/
#endif
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
#ifdef DUAL_LCD
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
/* under construction !*/
/* under construction !*/
#endif
}

