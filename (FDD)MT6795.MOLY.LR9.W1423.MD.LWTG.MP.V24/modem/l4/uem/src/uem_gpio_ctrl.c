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
 * uem_gpio_ctrl.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for control LED/LCM/Vibrator pattern.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
* Include
*****************************************************************************/
#define NEW_FRAME

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_trace.h"
#include "device.h"

#include "nvram_editor_data_item.h"

//#include "custom_led_patterns.h"
#include "custom_equipment.h"
#include "custom_uem.h"

#include "uem_context.h"
#include "uem_gpio_ctrl.h"
#include "uem_utility.h"
#include "uem_trc.h"

/***************************************************************************** 
* Extern Function
*****************************************************************************/
extern void MMICheckDiskDisplay(void);

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void uem_play_led_pattern_callback(void *ptr);
static void uem_play_lcd_pattern_callback(void *ptr);
static void uem_play_vib_pattern_callback(void *ptr);
static void uem_play_led_pattern(void);
static void uem_play_lcd_pattern(void);
static void uem_play_vib_pattern(void);
static void uem_set_led_level(kal_uint8 led_id, kal_uint8 level);
static void uem_set_lcd_level(kal_uint8 lcd_id, kal_uint8 level);
static void uem_set_vib_level(kal_uint8 vib_id, kal_uint8 level);
static void uem_stop_led_level(kal_uint8 led_id);
static void uem_stop_lcd_level(kal_uint8 lcd_id);
static void uem_stop_vib_level(kal_uint8 vib_id);
static kal_uint8 uem_get_vib_pattern_level(const VIB_PATTERN_STRUCT *pattern, kal_uint8 level);

/***************************************************************************** 
* Local Variable
*****************************************************************************/
static kal_uint8 led_ptn_idx = 0, lcd_ptn_idx = 0, vib_ptn_idx = 0;
static PATTERN_TYPE led_ptn_type = PLAY_ONCE, lcd_ptn_type = PLAY_ONCE, vib_ptn_type = PLAY_ONCE;

static const LED_PATTERN_STRUCT *led_play_pattern;
static const LCD_PATTERN_STRUCT *lcd_play_pattern;
static const VIB_PATTERN_STRUCT *vib_play_pattern;
//static PATTERN_ID vib_ptn_id;

static kal_uint8 g_uem_vib_state;

extern VIB_PATTERN_STRUCT vib_gpio_ptn4[];

/***************************************************************************** 
****************************************************************************** 
* External Funcations 
******************************************************************************
******************************************************************************/
/*****************************************************************************
*   Function 
*      uem_play_pattern
*   DESCRIPTION
*      get the accustic gain value
*   PARAMETERS
*      kal_uint8 volume_type,
*      kal_uint8 volume_level,
*      kal_uint8 volume_gain
*   RETURNS
*      kal_uint8
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_play_pattern
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pattern_id          [IN]        
 *  pattern_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool uem_play_pattern(PATTERN_ID pattern_id, PATTERN_TYPE pattern_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool res = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_PLAY_PATTERN, pattern_id, pattern_type);
#ifndef __LTE_RAT__    
    /* out of range */
    if ((pattern_type > MAX_PATTERN_TYPE) || (pattern_id > MAX_PATTERN_ID))
    {
        ASSERT(0);
    }

    /* play stop */
    if (pattern_type == PLAY_STOP)
    {
        uem_stop_pattern(pattern_id);
        return KAL_TRUE;
    }

    /* play LED pattern */
    if (pattern_id <= LED_PATTERN_END)  /* pattern_id always >= LED_PATTERN_BEGIN */
    {
        /* always to stop previous */
        uem_stop_pattern(pattern_id);

        led_play_pattern = custom_get_led_patterns(pattern_id);
        led_ptn_type = pattern_type;

        uem_play_led_pattern();

        res = KAL_TRUE;
    }
    /* play LCD backlight pattern */
    else if ((pattern_id >= LCD_PATTERN_BEGIN) && (pattern_id <= LCD_PATTERN_END))
    {
        /* always to stop previous */
        uem_stop_pattern(pattern_id);
        lcd_play_pattern = custom_get_lcd_patterns(pattern_id);
        lcd_ptn_type = pattern_type;
        uem_play_lcd_pattern();

        res = KAL_TRUE;
    }
    /* play vibrator pattern */
    else if ((pattern_id >= VIB_PATTERN_BEGIN) && (pattern_id <= VIB_PATTERN_END))
    {
        kal_trace(TRACE_FUNC, FUNC_UEM_VIB);
        
        if (pattern_id > VIB_PATTERN_3 && pattern_id <= VIB_PATTERN_END)
        {
            kal_trace(TRACE_FUNC, FUNC_UEM_CHECK_VIB_PTN_ID, vib_play_pattern, vib_gpio_ptn4, custom_cfg_gpio_is_vib_on());
            
            /* For touch feedback pattern, only play when no patterning playing*/
            if ((vib_play_pattern && (vib_play_pattern != vib_gpio_ptn4)) ||
                custom_cfg_gpio_is_vib_on())
            {
                return KAL_TRUE;
            }
            uem_stop_pattern(pattern_id);
            vib_play_pattern = vib_gpio_ptn4;
        }
        else
        {
            kal_trace(TRACE_FUNC, FUNC_UEM_OTHER_VIB_PTN);
            /* always to stop previous */
            uem_stop_pattern(pattern_id);
            vib_play_pattern = custom_get_vib_patterns(pattern_id);
        }
        kal_trace(TRACE_FUNC, FUNC_UEM_CONTINUE_PLAY_VIB);
        //vib_ptn_id = pattern_id;
        vib_ptn_type = pattern_type;
        uem_play_vib_pattern();

        res = KAL_TRUE;
    }
#endif
    return res;
}

/*****************************************************************************
*   Function 
*      uem_stop_pattern
*   DESCRIPTION
*      get the accustic gain value
*   PARAMETERS
*      kal_uint8 volume_type,
*      kal_uint8 volume_level,
*      kal_uint8 volume_gain
*   RETURNS
*      kal_uint8
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_stop_pattern
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pattern_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool uem_stop_pattern(PATTERN_ID pattern_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool res = KAL_FALSE;
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_STOP_PATTERN, pattern_id);
    
    /* stop timer */
    if (pattern_id <= LED_PATTERN_END)  /* pattern_id always >= LED_PATTERN_BEGIN */
    {
        led_ptn_idx = 0;
        uem_stop_timer(LED_EVENT_TIMER);
        for (i = 0; i < MAX_LED_GPIO; i++)
        {
            uem_stop_led_level(i);
        }
        res = KAL_TRUE;
    }
    else if ((pattern_id >= LCD_PATTERN_BEGIN) && (pattern_id <= LCD_PATTERN_END))
    {
        lcd_ptn_idx = 0;
        uem_stop_timer(LCD_EVENT_TIMER);
        for (i = 0; i < MAX_LCD_BACKLIGHT; i++)
        {
            uem_stop_lcd_level(i);
        }
        res = KAL_TRUE;
    }
    else if ((pattern_id >= VIB_PATTERN_BEGIN) && (pattern_id <= VIB_PATTERN_END))
    {
        vib_ptn_idx = 0;
        vib_play_pattern = NULL;
        uem_stop_timer(VIB_EVENT_TIMER);
        for (i = 0; i < MAX_VIBRATOR; i++)
        {
            uem_stop_vib_level(i);
        }
        res = KAL_TRUE;
    }
    return res;
}

/***************************************************************************** 
****************************************************************************** 
* Local Funcations 
******************************************************************************
******************************************************************************/
/*****************************************************************************
*   Function 
*      uem_play_led_pattern_callback
*   DESCRIPTION
*      get the accustic gain value
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_play_led_pattern_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uem_play_led_pattern_callback(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    led_ptn_idx++;
    uem_timer_table[LED_EVENT_TIMER].eventID = NULL;
    uem_play_led_pattern();
}

/*****************************************************************************
*   Function 
*      uem_play_led_pattern
*   DESCRIPTION
*      get the accustic gain value
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_play_led_pattern
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uem_play_led_pattern(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (led_ptn_idx == 0)
    {
        /* only one time */
        if (led_play_pattern[led_ptn_idx].duration_time == 0)
        {
            for (i = 0; i < MAX_LED_GPIO; i++)
            {
                uem_set_led_level(i, led_play_pattern[led_ptn_idx].gpio_control[i]);
            }
            return;
        }
    }

    for (i = 0; i < MAX_LED_GPIO; i++)
    {
        /* below is dummy function for led light control */
        uem_set_led_level(i, led_play_pattern[led_ptn_idx].gpio_control[i]);
    }

    /* start timer to do next pattern */
    if (led_play_pattern[led_ptn_idx].duration_time != 0)
    {
        uem_start_timer(LED_EVENT_TIMER, uem_play_led_pattern_callback, led_play_pattern[led_ptn_idx].duration_time);
    }
    else    /* end of pattern */
    {
        /* restart from base index 0 */
        led_ptn_idx = 0;
        if (led_ptn_type == PLAY_REPEAT)
        {
            uem_play_led_pattern();
        }
        else
        {
            /* no case to run */
        }
    }
}

/*****************************************************************************
*   Function 
*      uem_play_lcd_pattern_callback
*   DESCRIPTION
*      get the accustic gain value
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_play_lcd_pattern_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uem_play_lcd_pattern_callback(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lcd_ptn_idx++;
    uem_timer_table[LCD_EVENT_TIMER].eventID = NULL;
    uem_play_lcd_pattern();
}

/*****************************************************************************
*   Function 
*      uem_play_lcd_pattern
*   DESCRIPTION
*      get the accustic gain value
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_play_lcd_pattern
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uem_play_lcd_pattern(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lcd_ptn_idx == 0)
    {
        /* only one time */
        if (lcd_play_pattern[lcd_ptn_idx].duration_time == 0)
        {
            for (i = 0; i < MAX_LCD_BACKLIGHT; i++)
            {
                uem_set_lcd_level(i, lcd_play_pattern[lcd_ptn_idx].gpio_control[i]);
            }
            return;
        }
    }

    for (i = 0; i < MAX_LCD_BACKLIGHT; i++)
    {
        /* below is dummy function for led light control */
        uem_set_lcd_level(i, lcd_play_pattern[lcd_ptn_idx].gpio_control[i]);
    }

    if (lcd_play_pattern[lcd_ptn_idx].duration_time != 0)
    {
        uem_start_timer(LCD_EVENT_TIMER, uem_play_lcd_pattern_callback, lcd_play_pattern[lcd_ptn_idx].duration_time);
    }
    else    /* end of pattern */
    {
        /* restart from base index 0 */
        lcd_ptn_idx = 0;
        if (lcd_ptn_type == PLAY_REPEAT)
        {
            uem_play_lcd_pattern();
        }
        else
        {
            /* no case to run */
        }
    }
}

/*****************************************************************************
*   Function 
*      uem_play_vib_pattern_callback
*   DESCRIPTION
*      get the accustic gain value
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_play_vib_pattern_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void uem_play_vib_pattern_callback(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_PLAY_VIB_PATTERN_CALLBACK, vib_play_pattern);
    if (!vib_play_pattern)
    {
        return;
    }
    vib_ptn_idx++;
    uem_timer_table[VIB_EVENT_TIMER].eventID = NULL;
    uem_play_vib_pattern();
}

/*****************************************************************************
*   Function 
*      uem_play_lcd_pattern
*   DESCRIPTION
*      get the accustic gain value
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_play_vib_pattern
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uem_play_vib_pattern(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_UEM_PLAY_VIB_PATTERN);
    
    if (vib_ptn_idx == 0)
    {
        /* only one time */
        if (vib_play_pattern[vib_ptn_idx].duration_time == 0)
        {
            for (i = 0; i < MAX_VIBRATOR; i++)
            {
                uem_set_vib_level(i, 
                    uem_get_vib_pattern_level(vib_play_pattern, 
                    vib_play_pattern[vib_ptn_idx].gpio_control[i]));
            }
            return;
        }
    }

    for (i = 0; i < MAX_VIBRATOR; i++)
    {
        /* below is dummy function for led light control */
        uem_set_vib_level(i, 
            uem_get_vib_pattern_level(vib_play_pattern, 
            vib_play_pattern[vib_ptn_idx].gpio_control[i]));
    }

    if (vib_play_pattern[vib_ptn_idx].duration_time != 0)
    {
        uem_start_timer(VIB_EVENT_TIMER, uem_play_vib_pattern_callback, vib_play_pattern[vib_ptn_idx].duration_time);
    }
    else    /* end of pattern */
    {
        /* restart from base index 0 */
        vib_ptn_idx = 0;
        if (vib_ptn_type == PLAY_REPEAT)
        {
            uem_play_vib_pattern();
        }
        else
        {
            /* no case to run */
            vib_play_pattern = NULL;
        }
    }
}

static kal_uint8 uem_get_vib_pattern_level(const VIB_PATTERN_STRUCT *pattern, kal_uint8 level)
{
    if (pattern != vib_gpio_ptn4)
    {
        return level;
    }
    if (level == 0)
    {
        return 0;
    }
    return g_uem_cntx_p->rmi_data.gpio_status[GPIO_DEV_FTE_FEEDBACK_VIB];
}

/*****************************************************************************
*   Function 
*      uem_set_led_level
*   DESCRIPTION
*      set led level
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_set_led_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  led_id      [IN]        
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_set_led_level(kal_uint8 led_id, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __LTE_RAT__
    custom_uem_gpio_set_level(custom_get_led_label(led_id), level);
#endif
}

/*****************************************************************************
*   Function 
*      uem_set_lcd_level
*   DESCRIPTION
*      set lcd level
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_set_lcd_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_id      [IN]        
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_set_lcd_level(kal_uint8 lcd_id, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __LTE_RAT__
    custom_uem_gpio_set_level(custom_get_lcd_label(lcd_id), level);
#endif
}

/*****************************************************************************
*   Function 
*      uem_set_vib_level
*   DESCRIPTION
*      set lcd level
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_set_vib_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vib_id      [IN]        
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_set_vib_level(kal_uint8 vib_id, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __LTE_RAT__
    kal_trace(TRACE_FUNC, FUNC_UEM_SET_VIB_LEVEL, vib_id, level);
    custom_uem_gpio_set_level(custom_get_vib_label(vib_id), level);
    if (level != LED_LIGHT_LEVEL0)
    {
        uem_set_vib_state(KAL_TRUE);
    }
    else
    {
        uem_set_vib_state(KAL_FALSE);
    }
#endif
}

/*****************************************************************************
*   Function 
*      uem_stop_led_level
*   DESCRIPTION
*      set led level
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_stop_led_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  led_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_stop_led_level(kal_uint8 led_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __LTE_RAT__
    custom_uem_gpio_set_level(custom_get_led_label(led_id), 0);
#endif
}

/*****************************************************************************
*   Function 
*      uem_set_lcd_level
*   DESCRIPTION
*      set lcd level
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_stop_lcd_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_stop_lcd_level(kal_uint8 lcd_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __LTE_RAT__
    custom_uem_gpio_set_level(custom_get_lcd_label(lcd_id), 0);
#endif
}

/*****************************************************************************
*   Function 
*      uem_set_vib_level
*   DESCRIPTION
*      set lcd level
*   PARAMETERS
*
*   RETURNS
*      void
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  uem_stop_vib_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vib_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void uem_stop_vib_level(kal_uint8 vib_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __LTE_RAT__
    custom_uem_gpio_set_level(custom_get_vib_label(vib_id), 0);
    uem_set_vib_state(KAL_FALSE);
    vib_play_pattern = NULL;
#endif
}

void uem_set_vib_state(kal_uint8 on)
{
    g_uem_vib_state = on;
}

kal_uint8 uem_get_vib_state(void)
{
    return g_uem_vib_state;
}

kal_bool custom_cfg_gpio_is_vib_on(void)
{
    return (uem_get_vib_state() != 0);
}

//#if defined(__BK_LIGHT_20LEVEL_SUPPORT__) || defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)
#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)

#define UEM_BK_OFF_TOTAL_TIME   GPIO_BRIGHTNESS_DIMMING_TIME
#define UEM_BK_OFF_STEP_TIME	30

static kal_bool g_processing_bk_off;
static kal_uint16 g_bk_step_dur;
static kal_uint8 g_bk_start_level;
static kal_uint8 g_bk_cur_level;

static void uem_start_led_backlight_off(void);
static void uem_process_led_backlight_off(void);
static void uem_led_backlight_off_timer_hdlr(void *p);

void uem_set_led_backlight_off(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level)
{
    kal_trace(TRACE_FUNC, FUNC_UEM_SET_LED_BACKLIGHT_OFF);

    if (gpio_dev_level > custom_uem_get_bl_level_num())
    {
        EXT_ASSERT(0, gpio_dev_level, 0, 0);
        return;
    }

    if (g_processing_bk_off)
    {
        kal_trace(TRACE_FUNC, FUNC_UEM_PROCESSING);
        return;
    }

    g_processing_bk_off = KAL_TRUE;
    g_bk_start_level = gpio_dev_level;
    g_bk_step_dur = UEM_BK_OFF_STEP_TIME; //UEM_BK_OFF_TOTAL_TIME / gpio_dev_level;
    g_bk_cur_level = g_bk_start_level;

    kal_trace(TRACE_FUNC, FUNC_UEM_VIB_TIMER_DUR, g_bk_step_dur);
    
    uem_start_led_backlight_off();
}

void uem_stop_led_backlight_off(void)
{
    kal_trace(TRACE_FUNC, FUNC_UEM_STOP_LED_BACKLIGHT_OFF, g_processing_bk_off);
    if (g_processing_bk_off)
    {
        g_processing_bk_off = KAL_FALSE;
        uem_stop_timer(LCD_BK_OFF_TIMER);
    }
}

static void uem_start_led_backlight_off(void)
{
    kal_trace(TRACE_FUNC, FUNC_UEM_START_LED_BACKLIGHT_OFF);
    uem_process_led_backlight_off();
}

static void uem_process_led_backlight_off(void)
{
    kal_trace(TRACE_FUNC, FUNC_UEM_PROCESS_LED_BACKLIGHT_OFF, g_bk_cur_level);
    
    custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, g_bk_cur_level);

    if (g_bk_cur_level > LED_LIGHT_LEVEL1)
    {
        uem_start_timer(LCD_BK_OFF_TIMER, uem_led_backlight_off_timer_hdlr, g_bk_step_dur);
    }
    else
    {
        g_processing_bk_off = KAL_FALSE;
    }
}

static void uem_led_backlight_off_timer_hdlr(void *p)
{
    kal_trace(TRACE_FUNC, FUNC_UEM_LED_BACKLIGHT_OFF_TIMER_HDLR, g_processing_bk_off);
    
    if (!g_processing_bk_off)
    {
        return;
    }
    g_bk_cur_level --;
    uem_process_led_backlight_off();
}

#endif /* __BK_LIGHT_20LEVEL_SUPPORT__*/
