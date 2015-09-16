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
 * UEM_AT_CMD.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for AT command test function.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Includes
*****************************************************************************/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "stdio.h"
#include "device.h"
#include "nvram_struct.h"
#include "custom_em.h"
#include "l4c_eq_msg.h"
#include "uem_context.h"
#include "uem_utility.h"
#include "uem_at_cmd.h"
#include "uem_trc.h"
#include "nvram_msgid.h"

/***************************************************************************** 
* Local Variables Declaration
*****************************************************************************/
static kal_int8 at_test_string[30];
#ifdef __AT_ESWM_SUPPORT__
static l4cuem_at_ef_port_mode_enum g_at_ef_port_mode;
static kal_bool g_at_ef_port_sd_logging;
static kal_uint8 g_at_ef_port_cdrom;
#endif

/***************************************************************************** 
****************************************************************************** 
* External Funcations 
******************************************************************************
******************************************************************************/

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


/*****************************************************************************
*   Function 
*      l4cuem_test_time_format
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_time_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_time_format(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        *buffer = (kal_uint8*) "+CSTF: (1,2)";
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


/*****************************************************************************
*   Function 
*      l4cuem_test_volume_level
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_volume_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_volume_level(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        kal_sprintf((kal_char*) at_test_string, "+CLVL: (0-%d)", MAX_VOL_LEVEL - 1);
        *buffer = (kal_uint8*) at_test_string;
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_test_ring_volume_level
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_ring_volume_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_ring_volume_level(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        kal_sprintf((kal_char*) at_test_string, "+CRSL: (1-%d)", MAX_VOL_LEVEL);
        *buffer = (kal_uint8*) at_test_string;
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

#ifdef __test_mode__
/*****************************************************************************
*   Function 
*      l4cuem_test_mute_mode
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_mute_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_mute_mode(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        *buffer = (kal_uint8*) "+CMUT: (0,1)";
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}
#endif /* __test_mode__ */ 

/*****************************************************************************
*   Function 
*      l4cuem_test_silent_mode
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_silent_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_silent_mode(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        *buffer = (kal_uint8*) "+CSIL: (0,1)";
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_test_vibrator_mode
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_vibrator_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_vibrator_mode(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        *buffer = (kal_uint8*) "+CVIB: (0,1)";
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
*   Function 
*      l4cuem_test_greeting_text
*   DESCRIPTION
*      
*   PARAMETERS
*      buffer
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  l4cuem_test_greeting_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_test_greeting_text(kal_uint8 const **buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        kal_sprintf((kal_char*) at_test_string, "+CSGT: (0,1),%d", 30);
        *buffer = (kal_uint8*) at_test_string;
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  l4cuem_at_query_is_charging
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_at_query_is_charging(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FLAG_IS_ON(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_USB_CHARGER) ||
        FLAG_IS_ON(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_CHARGER))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  l4cuem_at_query_is_clam_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_at_query_is_clam_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FLAG_IS_ON(g_uem_cntx_p->acc_latest_state, UEM_ACCESSORY_TYPE_CLAM))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

#ifdef __AT_ESWM_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  l4cuem_at_ef_port_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool l4cuem_at_ef_port_setting(l4cuem_at_ef_port_mode_enum mode, void *param)
{
    kal_bool ret = KAL_TRUE;

    kal_trace(TRACE_FUNC, FUNC_UEM_AT_EF_PORT_SETTING, mode, param, g_at_ef_port_mode);
    
    if (g_at_ef_port_mode != L4CUEM_EF_PORT_NULL)
    {
        return KAL_FALSE;
    }
    g_at_ef_port_mode = mode;
    
    switch(mode)
    {
        case L4CUEM_EF_PORT_COM_SWITCH:
        case L4CUEM_EF_PORT_MS:
            break;
            
        case L4CUEM_EF_PORT_SD_LOGGING:
        	  {
        	  	//g_at_ef_port_sd_logging = (kal_bool)param;
        	  	kal_uint32 mode = (kal_uint32)param;
              switch(mode)
              {
              	case 0:
              		g_at_ef_port_sd_logging = KAL_FALSE;
              		break;
              	case 1:
              		g_at_ef_port_sd_logging = KAL_TRUE;
              		break;
              	default:
              		g_at_ef_port_sd_logging = KAL_TRUE;
              		break;
              }
            }
            break;

        case L4CUEM_EF_PORT_CDROM_CONFIG:
            {
                //g_at_ef_port_cdrom = (kal_uint8)param;
                kal_uint32 mode = (kal_uint32)param;
                g_at_ef_port_cdrom = (kal_uint8)mode;
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
#endif
            }
            break;
            
        default:
            return KAL_FALSE;
    }

    uem_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ,
        NVRAM_EF_PORT_SETTING_LID,
        0, 0);
    
    return ret;
}

l4cuem_at_ef_port_mode_enum l4cuem_at_get_ef_port_setting_mode(void)
{
    return g_at_ef_port_mode;
}

void l4cuem_at_ef_port_setting_read_cnf_hdlr(void *data)
{
    //port_setting_struct *port = (port_setting_struct*)data;
    port_setting_struct new_port;

    kal_trace(TRACE_FUNC, FUNC_UEM_AT_EF_PORT_SETTING_READ_CNF_HDLR, g_at_ef_port_mode);
    
    kal_mem_cpy(&new_port, data, sizeof(port_setting_struct));
    
    switch(l4cuem_at_get_ef_port_setting_mode())
    {
        case L4CUEM_EF_PORT_COM_SWITCH:
            new_port.ps_port = uart_port_usb;
            new_port.tst_port_ps = uart_port_usb2;
            new_port.tst_port_l1 = uart_port_usb2;
            break;
            
        case L4CUEM_EF_PORT_MS:
            new_port.ps_port = uart_port_usb;
            new_port.tst_port_ps = uart_port2;
            new_port.tst_port_l1 = uart_port2;
            new_port.tst_baudrate_ps = 1500000;
            new_port.tst_baudrate_l1= 1500000;
            break;
            
        case L4CUEM_EF_PORT_SD_LOGGING:
            if (g_at_ef_port_sd_logging)
            {
                new_port.tst_output_mode = 1;
            }
            else
            {
                new_port.tst_output_mode = 0;
            }
            break;

        case L4CUEM_EF_PORT_CDROM_CONFIG:
            new_port.usb_cdrom_config = g_at_ef_port_cdrom;
            break;
            
        default:
            return;
    }

    uem_send_msg_to_nvram(MSG_ID_NVRAM_WRITE_REQ,
        NVRAM_EF_PORT_SETTING_LID,
        &new_port,
        sizeof(port_setting_struct));
}

void l4cuem_at_ef_port_setting_write_cnf_hdlr(void *data)
{
    nvram_write_cnf_struct *result = (nvram_write_cnf_struct*)data;

    kal_trace(TRACE_FUNC, FUNC_UEM_AT_EF_PORT_SETTING_WRITE_CNF_HDLR, result->result);
    
#ifdef __AT_ESWM_SUPPORT__
    l4cuem_at_ef_port_setting_result_rrsp(g_at_ef_port_mode, (result->result == NVRAM_ERRNO_SUCCESS)); //mtk02088_eswm
#endif
    switch(g_at_ef_port_mode)
    {
        case L4CUEM_EF_PORT_CDROM_CONFIG:
            custom_em_set_usb_cdrom_config(g_at_ef_port_cdrom);
            break;
            
        default:
            break;
    }
    
    g_at_ef_port_mode = L4CUEM_EF_PORT_NULL;
}

#endif /* __AT_ESWM_SUPPORT__*/
