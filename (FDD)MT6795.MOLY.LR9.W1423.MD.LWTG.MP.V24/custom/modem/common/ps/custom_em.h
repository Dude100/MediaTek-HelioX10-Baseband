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
 *   custom_em.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the custom engineer mode declarations
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef CUSTOM_EM_H
#define CUSTOM_EM_H

#include "kal_general_types.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "ps_em_enum.h"
/* for HAL, some device definition move to device.h*/
#include "device.h"


typedef enum
{
    CUSTOM_EM_PWM_LEVEL_1 = 0x0,
    CUSTOM_EM_PWM_LEVEL_2,
    CUSTOM_EM_PWM_LEVEL_3,
    CUSTOM_EM_PWM_LEVEL_4,
    CUSTOM_EM_PWM_LEVEL_5,
    CUSTOM_EM_PWM_LEVEL_MAX
} CUSTOM_EM_PWM_LEVEL;

typedef enum
{
    CUSTOM_EM_PWM_TYPE_1 = 0x0,
    CUSTOM_EM_PWM_TYPE_2,
    CUSTOM_EM_PWM_TYPE_3,
    CUSTOM_EM_PWM_TYPE_MAX
} CUSTOM_EM_PWM_TYPE;

typedef enum
{
    CUSTOM_EM_UART_PORT1 = 0,
    CUSTOM_EM_UART_PORT2,
    CUSTOM_EM_UART_PORT3,
    CUSTOM_EM_UART_MAX_PORT
} CUSTOM_EM_PORT_TYPE;

extern kal_bool custom_em_pwm_get_level_value(
                    CUSTOM_EM_PWM_TYPE type,
                    CUSTOM_EM_PWM_LEVEL level,
                    kal_uint16 *freq,
                    kal_uint8 *duty_cycle);
extern kal_bool custom_em_pwm_set_level_value(
                    CUSTOM_EM_PWM_TYPE type,
                    CUSTOM_EM_PWM_LEVEL level,
                    kal_uint16 freq,
                    kal_uint8 duty_cycle);
extern void custom_em_pwm_get_value(kal_uint16 *freq, kal_uint8 *duty_cycle);
extern void custom_em_pwm_set_value(kal_uint16 *freq, kal_uint8 *duty_cycle);
extern void custom_em_pwm_start(CUSTOM_EM_PWM_TYPE type, kal_uint32 freq, kal_uint32 duty);
extern void custom_em_pwm_stop(CUSTOM_EM_PWM_TYPE type);
extern kal_uint8 custom_em_pwm_get_hw_current_level(CUSTOM_EM_PWM_TYPE type);
extern void custom_em_pwm_set_level(CUSTOM_EM_PWM_TYPE type, kal_uint8 level);

extern void custom_em_gpio_start(kal_uint8 port);
extern void custom_em_gpio_stop(kal_uint8 port);
extern void custom_em_gpo_writeio(kal_int8 data, kal_int8 port);
extern void custom_em_nvram_config_com_port(void);
/* For USB CDROM config*/
extern kal_uint8 custom_em_get_usb_cdrom_config(void);
extern void custom_em_set_usb_cdrom_config(kal_uint8 cdrom_config);

#ifdef __SP_RIL_SUPPORT__
extern void custom_em_thermal_red_ccci_hisr_callback(kal_uint32 value);
#endif
extern sim_interface_enum custom_em_get_imei_rec_by_sim(kal_uint8 op, sim_interface_enum slot);

#endif /* CUSTOM_EM_H */

