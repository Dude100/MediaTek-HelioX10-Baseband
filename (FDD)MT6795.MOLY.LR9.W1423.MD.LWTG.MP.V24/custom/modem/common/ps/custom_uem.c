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
 *   custom_uem_config.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "kal_general_types.h"
#include "kal_trace.h"
#include "uem_trc.h"
#include "custom_uem.h"
#include "device.h"
#include "dcl.h"

/* RMI default vaules*/
#define CUSTOM_UEM_RMI_LANG_ID_DEFAULT_0   'e'
#define CUSTOM_UEM_RMI_LANG_ID_DEFAULT_1   'n'
#define CUSTOM_UEM_RMI_DATE_MODE_DEFAULT   1

static const kal_uint8* g_custom_uem_equip_id[] = 
{
    (kal_uint8*)"MTK1",
#ifdef __DM_MO_SUPPORT__
    (kal_uint8*)"MTK3",
#else
    (kal_uint8*)"MTK2",
#endif
    (kal_uint8*)"MTK3",
    (kal_uint8*)"MTK4",
    (kal_uint8*)"MTK5",
    (kal_uint8*)"MTK6",
    (kal_uint8*)"MTK7",
};



void custom_uem_set_rmi_lang_id(kal_uint8 *lang_id)
{
    if (*((kal_uint16*)lang_id) == 0)
    {
        lang_id[0] = CUSTOM_UEM_RMI_LANG_ID_DEFAULT_0;
        lang_id[1] = CUSTOM_UEM_RMI_LANG_ID_DEFAULT_1;
    }
}

kal_uint8* custom_uem_get_equip_id(kal_uint8 equip_id)
{
    return (kal_uint8*)g_custom_uem_equip_id[equip_id];
}

//#pragma arm section code = "PRIMARY_ROCODE", rodata = "PRIMARY_RODATA"

#ifdef __VIBRATION_SPEAKER_SUPPORT__

static custom_uem_spkvib_func g_custom_uem_spkvib_func;
#endif

extern kal_bool custom_cfg_gpio_set_level(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level );

kal_bool custom_uem_gpio_set_level(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level)
{
#ifndef __MTK_TARGET__
    return custom_cfg_gpio_set_level_modis(gpio_dev_type, gpio_dev_level);
#else
#if !defined(L4_NOT_PRESENT)
//    kal_trace(TRACE_FUNC, FUNC_UEM_CUST_SET_LEVEL, gpio_dev_type, gpio_dev_level);
#endif
 
#ifdef __VIBRATION_SPEAKER_SUPPORT__
    if (gpio_dev_type == GPIO_DEV_VIBRATOR && g_custom_uem_spkvib_func)
    {
        g_custom_uem_spkvib_func((gpio_dev_level != 0));
        return KAL_TRUE;
    }
#endif
    return custom_cfg_gpio_set_level(gpio_dev_type, gpio_dev_level);
#endif
}

#ifdef __VIBRATION_SPEAKER_SUPPORT__

void custom_uem_set_spkvib_func(custom_uem_spkvib_func func)
{
    g_custom_uem_spkvib_func = func;
}
#endif

//#pragma arm section code, rodata


//extern kal_uint32 custom_bl_level_support_query(void);
//extern kal_uint32 custom_use_pwm_channel_query(kal_uint8 gpio_dev_type);

kal_uint32 custom_uem_get_bl_level_num(void)
{
    kal_uint32 ret = 0;

//    ret = custom_bl_level_support_query();
    return ret;
}

kal_uint32 custom_uem_get_pwm_bl_mode(kal_uint8 gpio_dev_type)
{
    kal_uint32 ret = 0;
    
  //  ret = custom_use_pwm_channel_query(gpio_dev_type);
    return ret;
}

