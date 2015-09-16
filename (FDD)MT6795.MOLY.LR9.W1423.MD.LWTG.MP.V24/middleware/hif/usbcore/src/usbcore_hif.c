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
 *   usbcore_hif.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   USB Core HIF interface and normal mode implementation.
 *   One can tell the type of HIF interface from function name prefix:
 *      (1) usbc_normal_hif_xxx(): implementation for normal mode HIF.
 *      (2) usbc_core_xxx(): shared between normal mode and exception mode HIF.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                 HISTORY
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "kal_public_api.h"
#include "syscomp_config.h"
#include "usbcore_common.h"
#include "hif_usb.h"
#include "usbcore_main.h"
#include "usbcore_ind_q.h"
#include "usbcore_hif.h"
#include "hifusb_qmu.h"
#include "hif_ior.h"
#include "qmu_bm_util.h"
#include "qmu_bm.h"
#include "hmu.h"
#include "hmu_conf_data.h"
#include "usbidle_if.h"
#include "usbcore_debug.h"
#include "hif_swla.h"
#ifdef __MULTI_BOOT__
#include "multiboot_config.h"
#endif /* __MULTI_BOOT__ */


#ifdef ATEST_SYS_USBCORE
#include "usbcore_ut.h"
#endif


/* 
 * Set up max capable speed by project makefile configuration, HIF_USB30_SUPPORT. 
 * See also usbcore.mak.
 */
#if __USBC_USB30_SUPPORT__
    #define USBC_MAX_SPEED HIFUSB_USB_SPEED_USB30
#else
    #define USBC_MAX_SPEED HIFUSB_USB_SPEED_USB20
#endif

extern kal_uint16 INT_BootMode(void);

#if __USBC_TARGET_HIF_DRIVER_SUPPORT__
#define __USBCORE_TARGET_DEBUG__
#endif

/*
 * HIF function pointers, actural mapping is defined in 
 * usbc_normal_hif_factory() and usbc_except_hif_factor() for 
 * normal mode and exception mode respectively.
 */
USBC_INDICATE_CONTROL_SETUP_PACKET  usbc_core_indicate_control_setup_packet = NULL;
USBC_INDICATE_CONTROL_COMPLETE      usbc_core_indicate_control_complete = NULL;
USBC_INDICATE_ALTERNATE_SETTING     usbc_core_indicate_alternate_setting = NULL;
USBC_INDICATE_STALL                 usbc_core_indicate_stall = NULL;
USBC_SET_CONTROL_REQUEST            usbc_core_set_control_request = NULL;
USBC_SET_PROPERTY                   usbc_core_set_property = NULL;
USBC_SET_USB_ADDRESS                usbc_core_set_usb_address = NULL;
USBC_SET_USB_CONFIGURATION          usbc_core_set_usb_configuration = NULL;
USBC_SET_STALL                      usbc_core_set_stall = NULL;
USBC_CLEAR_STALL                    usbc_core_clear_stall = NULL;
USBC_SET_USB_TESTMODE               usbc_core_set_usb_testmode = NULL;
USBC_SET_SS_DEV_INIT_U1_EN          usbc_core_set_ss_dev_init_u1_en = NULL;
USBC_SET_SS_DEV_INIT_U2_EN          usbc_core_set_ss_dev_init_u2_en = NULL;
USBC_SET_USBHIF_ADDRESS             usbc_core_set_usbhif_address = NULL;
USBC_SET_UFBHIF_CONFIGURATION       usbc_core_set_usbhif_configuration = NULL;
USBC_SET_USBHIF_CONNECT             usbc_core_set_usbhif_connect = NULL;
USBC_SET_USBHIF_DISCONNECT          usbc_core_set_usbhif_disconnect = NULL;
USBC_SET_USBHIFQ_GPD                usbc_core_set_usbhifq_gpd = NULL;

/*------------------------------------------------------------------------------
 * Private implementation for normal mode HIF.
 *----------------------------------------------------------------------------*/
static void usbc_normal_hif_notify_usb_event(hifusb_notify_evt_e event, void *data)
{
    usbc_core_t        *pUsbCore = usbc_core_get_instance();
    usbc_usb_state_e    state;
    usbc_ind_t          ind_to_enqueue;

    USBC_NON_EXCEPTION_MODE_CHECK();

    switch ( event )
    {
        case HIFUSB_NOTIFY_EVT_ATTACH:
        {
            state = USBC_USB_STATE_ATTACHING;
            usbc_trace_info(USBCORE_HIF_EVENT_ATTACH);
            break;
        }
        case HIFUSB_NOTIFY_EVT_DETACH:
        {
            state = USBC_USB_STATE_DETACHING;
            usbc_trace_info(USBCORE_HIF_EVENT_DETACH);
            break;
        }
        case HIFUSB_NOTIFY_EVT_SUSPEND:
        {
            state = USBC_USB_STATE_SUSPENDING;
            usbc_trace_info(USBCORE_HIF_EVENT_SUSPEND);
            break;
        }
        case HIFUSB_NOTIFY_EVT_RESUME:
        {
            state = USBC_USB_STATE_RESUME;
            usbc_trace_info(USBCORE_HIF_EVENT_RESUME);
            break;
        }
        case HIFUSB_NOTIFY_EVT_RESET:
        {
            usbc_usb_speed_e speed = *(usbc_usb_speed_e*)data;

            usbc_trace_info(USBCORE_HIF_EVENT_RESET);

            if ((speed != pUsbCore->speed) || (pUsbCore->is_mode_switch)) {
                usbc_trace_info(USBCORE_HIF_EVENT_SPEED_CHANGE, pUsbCore->speed, speed);

                /*
                 * Change USB link speed and related settings.
                 */
                usbc_core_speed_change(pUsbCore, speed);

                /*
                 * Enqueue USB speed change before USB reset event.
                 * Note that, we assume underlying HIF driver has already configured itself 
                 * for new USB link speed.
                 */
                ind_to_enqueue.type = USBC_IND_SPEED_CHANGE;
                ind_to_enqueue.ext = 0;
                ind_to_enqueue.data = (kal_uint8)speed;
                usbc_enqueue_ind(&ind_to_enqueue);
            }
            usbc_core_set_hif_configuration();

            state = USBC_USB_STATE_RESET;
            break;
        }
        default:
        {
            usbc_trace_error(USBCORE_HIF_EVENT_UNKNOWN);
            ASSERT(0);
            return;
        }
    }

    /*
     * Enqueue USB device state which will be handled in USB context later.
     */
    ind_to_enqueue.type = USBC_IND_DEV_EVENT;
    ind_to_enqueue.ext = 0;
    ind_to_enqueue.data = (kal_uint8)state;
    usbc_enqueue_ind(&ind_to_enqueue);

    /*
     * Wake up USBCORE task to process indications.
     */
    hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);
}

static kal_bool usbc_normal_hif_indicate_control_setup_packet(kal_uint8 intf_idx, usbc_setup_packet_t *packet)
{
    usbc_core_t    *pUsbCore = usbc_core_get_instance();
    usbc_ind_t      ind_to_enqueue;

    pUsbCore->setup_indicated = KAL_TRUE; /* Indicate to USBCLASS */

    ind_to_enqueue.type = USBC_IND_CTRL_SETUP;
    ind_to_enqueue.ext = 0;
    ind_to_enqueue.data = intf_idx;
    usbc_enqueue_ind(&ind_to_enqueue);

    /*
     * Wake up USBCORE task to process indications.
     */
    hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);
    return KAL_FALSE;
}

static void usbc_normal_hif_indicate_control_complete(kal_uint8 intf_idx)
{
    usbc_core_t    *pUsbCore = usbc_core_get_instance();
    usbc_ind_t      ind_to_enqueue;

    ASSERT(pUsbCore->setup_indicated); /* Only setup packet indicated case shall enqueue a control complet indication. */

    ind_to_enqueue.type = USBC_IND_CTRL_CMPLT;
    ind_to_enqueue.ext = 0;
    ind_to_enqueue.data = intf_idx;
    usbc_enqueue_ind(&ind_to_enqueue);

    /*
     * Wake up USBCORE task to process indications.
     */
    hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);
}

static void usbc_normal_hif_indicate_alternate_setting(kal_uint8 intf_idx, kal_uint8 alternate_setting)
{
    usbc_ind_t      ind_to_enqueue;

    ind_to_enqueue.type = USBC_IND_ALT_SETTING;
    ind_to_enqueue.ext = intf_idx;
    ind_to_enqueue.data = alternate_setting;
    usbc_enqueue_ind(&ind_to_enqueue);

    /*
     * Wake up USBCORE task to process indications.
     */
    hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);
}

static void usbc_normal_hif_indicate_stall(kal_bool is_tx, kal_uint8 queue_idx, kal_bool stall)
{
    usbc_ind_t      ind_to_enqueue;

    ind_to_enqueue.type = USBC_IND_PIPE_STALL;
    ind_to_enqueue.ext = ((KAL_TRUE == stall) ? 1 : 0);
    ind_to_enqueue.data = ((KAL_TRUE == is_tx) ? 0x80 : 0x00) | (queue_idx & 0x7f);
    usbc_enqueue_ind(&ind_to_enqueue);

    /*
     * Wake up USBCORE task to process indications.
     */
    hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);
}

static kal_bool usbc_normal_hif_notify_control_setup_packet(hifusb_setup_packet_t *p_setup)
{
    usbc_core_t     *pUsbCore = usbc_core_get_instance();

    USBC_NON_EXCEPTION_MODE_CHECK();

    return usbc_core_dispatch_control_setup_packet(pUsbCore, p_setup);
}

static void usbc_normal_hif_notify_control_complete(void)
{
    usbc_core_t     *pUsbCore = usbc_core_get_instance();

    USBC_NON_EXCEPTION_MODE_CHECK();

    usbc_core_notify_control_complete(pUsbCore);
}

static kal_bool usbc_normal_hif_set_usb_address(kal_uint8 address)
{
    usbc_core_t    *pUsbCore = usbc_core_get_instance();
    kal_bool        result = KAL_TRUE;

    USBC_NON_EXCEPTION_MODE_CHECK();

    pUsbCore->usb_address = address;
    usbc_core_set_usbhif_address(pUsbCore->usb_address);

    return result;
}

static kal_bool usbc_normal_hif_set_usb_configuration(kal_uint8 configuration)
{
    #define CFG_TO_INDEX(config)   (config-1)

    usbc_core_t        *pUsbCore = usbc_core_get_instance();
    kal_bool            result = KAL_TRUE;
    kal_uint32          idx_class;
    kal_uint32          idx_if;
    kal_uint32          idx_ep;
    usbc_class_set_config_func_t class_set_config_func;
    usb_class_type_e    type;
    usb_cfg_param_t     cfg_param;

    USBC_NON_EXCEPTION_MODE_CHECK();

    usbc_trace_info(USBCORE_HIF_SET_CONFIG, configuration);

    /* Check if configuration is changed */
    if (pUsbCore->usb_configuration == configuration) {
        usbc_trace_info(USBCORE_HIF_SET_CONFIG_UNCHANGED);
        return result;
    }
	pUsbCore->usb_configuration = configuration;

    /* Reinit usb classes of old configuration */
    usbc_trace_info(USBCORE_HIF_SET_CONFIG_REINIT_START);
    usbc_reinit_class();
    usbc_trace_info(USBCORE_HIF_SET_CONFIG_REINIT_END);

    if (configuration == 0)
    {  /* Clear all class device / interface / tx_queue / rx_queue number */
       pUsbCore->total_class_devices = 0;
       pUsbCore->total_class_interfaces = 0;
       pUsbCore->total_tx_queues = 0;
       pUsbCore->total_rx_queues = 0;
    } else
    {
        /* Fill class_device / interface / tx_queue / rx_queue */
        pUsbCore->total_class_devices = pUsbCore->dev_param->mode_param[pUsbCore->mode].cfg_param[CFG_TO_INDEX(configuration)].class_num;
        for (idx_class = 0; idx_class < pUsbCore->total_class_devices; idx_class ++)
        {
            type = pUsbCore->dev_param->mode_param[pUsbCore->mode].cfg_param[CFG_TO_INDEX(configuration)].class_type[idx_class];
            pUsbCore->class_device[idx_class].state = USBC_CORE_CLASS_DEVICE_STATE_INITIATED;
            pUsbCore->class_device[idx_class].class_type = type;
            pUsbCore->class_device[idx_class].total_pipes = 0;
        }
    
        pUsbCore->total_class_interfaces = pUsbCore->resource_interface_number[CFG_TO_INDEX(configuration)];
        for (idx_if = 0; idx_if < pUsbCore->total_class_interfaces; idx_if ++)
        {
            kal_mem_cpy(&pUsbCore->class_interface[idx_if],
                           &pUsbCore->if_info[CFG_TO_INDEX(configuration)][idx_if].class_interface,
                           sizeof(usbc_core_class_interface_t));
            pUsbCore->class_interface[idx_if].state = USBC_CORE_CLASS_INTERFACE_STATE_INITIATED;
        }
    
        pUsbCore->total_tx_queues = pUsbCore->resource_ep_tx_number[CFG_TO_INDEX(configuration)];
        for (idx_ep = 0; idx_ep < pUsbCore->total_tx_queues; idx_ep ++)
        {
            kal_mem_cpy(&pUsbCore->tx_queue[idx_ep],
                           &pUsbCore->ep_tx_info[CFG_TO_INDEX(configuration)][idx_ep].queue_info,
                           sizeof(usbc_core_queue_t));
            pUsbCore->tx_queue[idx_ep].state = USBC_CORE_QUEUE_STATE_INITIATED;
            pUsbCore->class_device[pUsbCore->tx_queue[idx_ep].class_device_id].total_pipes ++;
        }
    
        pUsbCore->total_rx_queues = pUsbCore->resource_ep_rx_number[CFG_TO_INDEX(configuration)];
        for (idx_ep = 0; idx_ep < pUsbCore->total_rx_queues; idx_ep ++)
        {
            kal_mem_cpy(&pUsbCore->rx_queue[idx_ep],
                           &pUsbCore->ep_rx_info[CFG_TO_INDEX(configuration)][idx_ep].queue_info,
                           sizeof(usbc_core_queue_t));
            pUsbCore->rx_queue[idx_ep].state = USBC_CORE_QUEUE_STATE_INITIATED;
            pUsbCore->class_device[pUsbCore->rx_queue[idx_ep].class_device_id].total_pipes ++;
        }
        
         
        /* Call Set config callback function to all usb class modules */
    	for (idx_class = 0; idx_class < pUsbCore->total_class_devices; idx_class ++)
        {
            cfg_param = pUsbCore->dev_param->mode_param[pUsbCore->mode].cfg_param[CFG_TO_INDEX(configuration)];
            type = cfg_param.class_type[idx_class];
            class_set_config_func = usbc_get_class_set_config_func(type);
            if (class_set_config_func) {
                usbc_trace_info(USBCORE_HIF_SET_CONFIG_USBCLASS, type);
                class_set_config_func(idx_class,
                                   CFG_TO_INDEX(configuration),
                                   cfg_param.class_ctxt[idx_class]);
            } else {
                ASSERT(0);
            }
        }
    }

    /* According to Ming's comment in 2013/4/24, we can still set old property to hif if usb_configuration is changed to 0 */
	usbc_core_set_hif_configuration();
   
    usbc_trace_info(USBCORE_HIF_SET_CONFIG_HIF, pUsbCore->usb_configuration);
    usbc_core_set_usbhif_configuration(pUsbCore->usb_configuration);

    if (pUsbCore->usb_configuration > 0) {
        /* notify class driver that HOST enable this device */
        usbc_trace_info(USBCORE_HIF_SET_CONFIG_CONF_STATE);
        usbc_core_notify_state_attached();
    } else {
        /* notify class driver that HOST disable this device */
        usbc_trace_info(USBCORE_HIF_SET_CONFIG_ADDR_STATE);
        usbc_core_notify_state_attaching(); /* According to usb spec, configuration 0 means device enter addressed state */
    }

    return result;
}

static void usbc_normal_hif_set_stall(kal_bool is_tx, kal_uint8 nEnd)
{
    USBC_NON_EXCEPTION_MODE_CHECK();

    hifusb_set_stall(is_tx, nEnd);
}

static void usbc_normal_hif_clear_stall(kal_bool is_tx, kal_uint8 nEnd)
{
    USBC_NON_EXCEPTION_MODE_CHECK();

    hifusb_clear_stall(is_tx, nEnd);
}

static void usbc_normal_hif_set_control_request(kal_uint8 *buffer, kal_uint32 length, usbc_control_request_type_e type)
{
    usbc_core_t                    *pUsbCore = usbc_core_get_instance();
    hifusb_control_request_type_e   hif_type = HIFUSB_CONTROL_REQUEST_TYPE_SEND;

    USBC_NON_EXCEPTION_MODE_CHECK();

    switch ( type ) {
        case USBC_CONTROL_REQUEST_TYPE_SEND:
            hif_type = HIFUSB_CONTROL_REQUEST_TYPE_SEND;
            break;
        case USBC_CONTROL_REQUEST_TYPE_RECEIVE:
            hif_type = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;
            break;
        case USBC_CONTROL_REQUEST_TYPE_STALL:
            hif_type = HIFUSB_CONTROL_REQUEST_TYPE_STALL;
            break;
        default:
            ASSERT(0);
            break;
    }

    if (pUsbCore->setup_indicated) {
        hifusb_set_control_request_in_task(buffer, length, hif_type);
    } else {
        hifusb_set_control_request_in_hisr(buffer, length, hif_type);
    }
}


/*------------------------------------------------------------------------------
 * USB Core HIF interface shared between normal mode and exception mode.
 *----------------------------------------------------------------------------*/
#ifdef __USBCORE_DEBUG__
void usbc_core_dump_gpd_list(void* first_gpd, void* last_gpd)
{
    void* curr_gpd = NULL;

    curr_gpd = first_gpd;
    do {
        void* curr_bd = NULL;

        if ( curr_gpd == NULL ) break;

        usbc_core_printf("[USBCORE] gpd[%x].CHKSUM   : %x \r\n", curr_gpd, QBM_DES_GET_CHKSUM(curr_gpd));
        usbc_core_printf("[USBCORE] gpd[%x].IOC      : %d \r\n", curr_gpd, QBM_DES_GET_IOC(curr_gpd)?1:0);
        usbc_core_printf("[USBCORE] gpd[%x].BDP      : %d \r\n", curr_gpd, QBM_DES_GET_BDP(curr_gpd)?1:0);
        usbc_core_printf("[USBCORE] gpd[%x].HWO      : %d \r\n", curr_gpd, QBM_DES_GET_HWO(curr_gpd)?1:0);
        usbc_core_printf("[USBCORE] gpd[%x].BPS      : %d \r\n", curr_gpd, QBM_DES_GET_BPS(curr_gpd)?1:0);
        usbc_core_printf("[USBCORE] gpd[%x].NEXT     : %x \r\n", curr_gpd, QBM_DES_GET_NEXT(curr_gpd));
        usbc_core_printf("[USBCORE] gpd[%x].DATAPTR  : %x \r\n", curr_gpd, QBM_DES_GET_DATAPTR(curr_gpd));
        usbc_core_printf("[USBCORE] gpd[%x].DATALEN  : %d \r\n", curr_gpd, QBM_DES_GET_DATALEN(curr_gpd));
        usbc_core_printf("[USBCORE] gpd[%x].ALLOWLEN : %d \r\n", curr_gpd, QBM_DES_GET_ALLOW_LEN(curr_gpd));
        usbc_core_printf("[USBCORE] gpd[%x].EXTLEN   : %d \r\n", curr_gpd, QBM_DES_GET_EXTLEN(curr_gpd));
        curr_bd = QBM_DES_GET_DATAPTR(curr_gpd);
        do {
            if ( !QBM_DES_GET_BDP(curr_gpd) )
            {
                break;
            }

            usbc_core_printf("[USBCORE]    bd[%x].CHKSUM   : %x \r\n", curr_bd, QBM_DES_GET_CHKSUM(curr_bd));
            usbc_core_printf("[USBCORE]    bd[%x].EOL      : %d \r\n", curr_bd, QBM_DES_GET_EOL(curr_bd));
            usbc_core_printf("[USBCORE]    bd[%x].NEXT     : %x \r\n", curr_bd, QBM_DES_GET_NEXT(curr_bd));
            usbc_core_printf("[USBCORE]    bd[%x].DATAPTR  : %x \r\n", curr_bd, QBM_DES_GET_DATAPTR(curr_bd));
            usbc_core_printf("[USBCORE]    bd[%x].DATALEN  : %d \r\n", curr_bd, QBM_DES_GET_DATALEN(curr_bd));
            usbc_core_printf("[USBCORE]    bd[%x].ALLOWLEN : %d \r\n", curr_bd, QBM_DES_GET_ALLOW_LEN(curr_bd));
            usbc_core_printf("[USBCORE]    bd[%x].EXTLEN   : %d \r\n", curr_bd, QBM_DES_GET_EXTLEN(curr_bd));

            if ( QBM_DES_GET_EOL(curr_bd) ) break;

            curr_bd =  QBM_DES_GET_NEXT(curr_bd);

        } while (curr_bd != NULL);

        if ( curr_gpd == last_gpd ) break;

        curr_gpd = QBM_DES_GET_NEXT(curr_gpd);

    } while (1);
}
#endif

static void usbc_core_getGpdLength(void* first_gpd, void* last_gpd, kal_uint32* gpd_len, kal_uint32* bd_len)
{
    void* curr_gpd = first_gpd;
    void* curr_bd = NULL;
    *gpd_len = *bd_len = 0;

    while(curr_gpd)
    {
        // Update length of GPD
        *gpd_len += QBM_DES_GET_DATALEN(curr_gpd) + QBM_DES_GET_EXTLEN(curr_gpd);

        if (QBM_DES_GET_BDP(curr_gpd))
        {
            curr_bd = QBM_DES_GET_DATAPTR(curr_gpd);

            while(curr_bd)
            {
                // Update length of BD
                *bd_len += QBM_DES_GET_DATALEN(curr_bd) + QBM_DES_GET_EXTLEN(curr_bd);

                if ( QBM_DES_GET_EOL(curr_bd) ) break;
                curr_bd = QBM_DES_GET_NEXT(curr_bd);
            }
        }

        if(curr_gpd == last_gpd) break;
        curr_gpd = QBM_DES_GET_NEXT(curr_gpd);
    }

    return;
}

kal_bool usbc_core_set_hif_configuration(void)
{
    static hifusb_property_t   property;
    usbc_core_t        *pUsbCore = usbc_core_get_instance();
    kal_bool            result = KAL_FALSE;
    kal_uint8           i = 0;

    kal_mem_set(&property, 0, sizeof(hifusb_property_t));
    property.speed      = USBC_MAX_SPEED; /* set desired speed as max capable speed */
    property.qmu_config = 0;
    property.txq_num    = pUsbCore->total_tx_queues;
    property.rxq_num    = pUsbCore->total_rx_queues;
    for ( i=0; i<property.txq_num; i++) {
        property.tx_que[i].ep_no            = pUsbCore->tx_queue[i].ep_no;
        property.tx_que[i].que_no           = HIFUSB_EPNO_2_QNO(pUsbCore->tx_queue[i].ep_no);
        property.tx_que[i].config           = pUsbCore->tx_queue[i].config;
        property.tx_que[i].type             = pUsbCore->tx_queue[i].xfer_type;
        property.tx_que[i].max_packet_size  = pUsbCore->tx_queue[i].max_packet_size;
        property.tx_que[i].double_fifo      = pUsbCore->tx_queue[i].double_fifo;
    }
    for ( i=0; i<property.rxq_num; i++) {
        property.rx_que[i].ep_no            = pUsbCore->rx_queue[i].ep_no;
        property.rx_que[i].que_no           = HIFUSB_EPNO_2_QNO(pUsbCore->rx_queue[i].ep_no);
        property.rx_que[i].config           = pUsbCore->rx_queue[i].config;
        property.rx_que[i].type             = pUsbCore->rx_queue[i].xfer_type;
        property.rx_que[i].max_packet_size  = pUsbCore->rx_queue[i].max_packet_size;
        property.rx_que[i].double_fifo      = pUsbCore->rx_queue[i].double_fifo;
    }

    property.notify_usb_evt                 = usbc_normal_hif_notify_usb_event;
    property.notify_control_setup_packet    = usbc_normal_hif_notify_control_setup_packet;
    property.notify_control_complete        = usbc_normal_hif_notify_control_complete;

    result = usbc_core_set_property(&property);
    ASSERT(result);

    return result;
}

kal_bool usbc_core_dispatch_control_setup_packet(usbc_core_t *pUsbCore, hifusb_setup_packet_t *p_setup)
{
    kal_bool    handled = KAL_TRUE;

    pUsbCore->setup_packet.bmRequestType    = p_setup->bmRequestType;
    pUsbCore->setup_packet.bRequest         = p_setup->bRequest;
    pUsbCore->setup_packet.wValue           = USBC_EF16P((kal_uint8*)&p_setup->wValue);
    pUsbCore->setup_packet.wIndex           = USBC_EF16P((kal_uint8*)&p_setup->wIndex);
    pUsbCore->setup_packet.wLength          = USBC_EF16P((kal_uint8*)&p_setup->wLength);

    pUsbCore->setup_indicated = KAL_FALSE; /* Default is handled in USBCORE. */

    usbc_trace_info(USBCORE_DISPATCH_REQUEST, pUsbCore->setup_packet.bmRequestType);

    if ((pUsbCore->setup_packet.bmRequestType & USBC_REQUEST_TYPE_MASK) == USBC_REQUEST_TYPE_STANDARD) {
        //usbc_core_printf("=========>usbcore_handle_standard_request\r\n");
        handled = usbc_core_handle_standard_request();
    } else if ((pUsbCore->setup_packet.bmRequestType & USBC_REQUEST_TYPE_MASK) == USBC_REQUEST_TYPE_CLASS) {
        if ((pUsbCore->setup_packet.bmRequestType & USBC_REQUEST_RECIP_MASK) == USBC_REQUEST_RECIP_INTERFACE) {
            kal_uint8 bInterface = pUsbCore->setup_packet.wIndex & 0xff;
            kal_uint8 i;

            usbc_core_printf("=========>usbcore_handle_class_request\r\n");

            /* notify class driver by interface if exist */
            for ( i=0; i<pUsbCore->total_class_interfaces; i++) {
                if ( (pUsbCore->class_interface[i].interface_no == bInterface) &&
                     (pUsbCore->class_interface[i].state == USBC_CORE_CLASS_INTERFACE_STATE_ACTIVE) &&
                     (pUsbCore->class_interface[i].notify_control_setup_packet != NULL)) {
                    break;
                }
            }

            if ( i == pUsbCore->total_class_interfaces ) {
                /* incorrect reqeuset */
                usbc_core_set_control_request(NULL, 0, HIFUSB_CONTROL_REQUEST_TYPE_STALL);
            } else {
                handled = usbc_core_indicate_control_setup_packet(i, &pUsbCore->setup_packet);
            }
        } else {
            /* incorrect reqeuset */
            usbc_core_set_control_request(NULL, 0, HIFUSB_CONTROL_REQUEST_TYPE_STALL);
        }
    } else if ((p_setup->bmRequestType & USBC_REQUEST_TYPE_MASK) == USBC_REQUEST_TYPE_VENDOR) {
        usbc_core_printf("=========>usbcore_handle_vendor_request\r\n");
        usbc_core_handle_vendor_request();
    } else {
        /* unknown reqeuset */
        usbc_core_set_control_request(NULL, 0, HIFUSB_CONTROL_REQUEST_TYPE_STALL);
    }

    return handled;
}

void usbc_core_notify_control_complete(usbc_core_t *pUsbCore)
{
    if (((pUsbCore->setup_packet.bmRequestType & USBC_REQUEST_TYPE_MASK) == USBC_REQUEST_TYPE_CLASS) ||
        ((pUsbCore->setup_packet.bmRequestType & USBC_REQUEST_TYPE_MASK) == USBC_REQUEST_TYPE_VENDOR)) {
        if ((pUsbCore->setup_packet.bmRequestType & USBC_REQUEST_RECIP_MASK) == USBC_REQUEST_RECIP_INTERFACE) {
            kal_uint8 bInterface = pUsbCore->setup_packet.wIndex & 0xff;
            kal_uint8 i;

            /* notify class driver by interface if exist */
            for ( i=0; i<pUsbCore->total_class_interfaces; i++) {
                if ( (pUsbCore->class_interface[i].interface_no == bInterface) &&
                     (pUsbCore->class_interface[i].state == USBC_CORE_CLASS_INTERFACE_STATE_ACTIVE) &&
                     (pUsbCore->class_interface[i].notify_control_complete != NULL) ) {
                    break;
                }
            }

            if ( i < pUsbCore->total_class_interfaces ) {
                usbc_core_indicate_control_complete(i);
            }
        }
    }
}

void usbc_core_speed_change(usbc_core_t *pUsbCore, usbc_usb_speed_e speed)
{
    pUsbCore->speed = speed;

    usbc_core_descriptors_speed_change(pUsbCore, speed);
}

/*------------------------------------------------------------------------------
 * USB Core internal implementation for HIF normal mode.
 *----------------------------------------------------------------------------*/
kal_bool usbc_normal_hif_init(void)
{
    kal_bool        result = KAL_FALSE;
    USBC_NON_EXCEPTION_MODE_CHECK();

    result = hifusb_init(USBC_MAX_SPEED);
    ASSERT(result);
    return result;
}

kal_bool usbc_normal_hif_shutdown(void)
{
    kal_bool        result = KAL_FALSE;

    USBC_NON_EXCEPTION_MODE_CHECK();

    hifusb_shutdown();

    return result;
}

kal_bool usbc_normal_hif_connect(void)
{
    kal_bool        result = KAL_FALSE;

    USBC_NON_EXCEPTION_MODE_CHECK();

    usbc_core_set_usbhif_connect();

    return result;
}

kal_bool usbc_normal_hif_disconnect(void)
{
    kal_bool        result = KAL_FALSE;

    USBC_NON_EXCEPTION_MODE_CHECK();

    usbc_core_set_usbhif_disconnect();

    return result;
}

kal_bool usbc_normal_hif_remote_wakeup(void)
{
    kal_bool        result = KAL_FALSE;
    USBC_NON_EXCEPTION_MODE_CHECK();

#if __USBC_TARGET_HIF_DRIVER_SUPPORT__ || ATEST_SYS_USBCORE
    result = hifusb_remote_wakeup();
    ASSERT(result);
#endif

    return result;
}

kal_bool usbc_normal_hif_ss_wk_notify(kal_uint8 nInterface)
{
    kal_bool        result = KAL_FALSE;
    USBC_NON_EXCEPTION_MODE_CHECK();

#if __USBC_TARGET_HIF_DRIVER_SUPPORT__ || ATEST_SYS_USBCORE
    usbc_trace_info(USBCORE_REMOTE_WK_HIF_NOTIFY, nInterface);
    result = hifusb_ss_func_wk_notify(nInterface);
    ASSERT(result);
#endif

    return result;
}

void usbc_normal_hif_poll_queue()
{
    usbc_core_t    *pUsbCore = usbc_core_get_instance();
    qbm_gpd        *first_gpd;
    qbm_gpd        *last_gpd;
    kal_uint32      num;
    hif_deq_info_t  deq_info;
    usbc_io_request_t   *request;
    kal_int8        i = 0;

    HIF_SWLA_START("UDP");

    for ( i=0; i<pUsbCore->total_tx_queues; i++ ) {
        if ( pUsbCore->tx_queue[i].state > USBC_CORE_QUEUE_STATE_INITIATED ) {
            first_gpd  = NULL;
            last_gpd   = NULL;
            num = 0;

            kal_mem_set(&deq_info, 0, sizeof(hif_deq_info_t));

            deq_info.q_type = HIFQ_TYPE_TX;
            deq_info.que_no = HIFUSB_EPNO_2_QNO(pUsbCore->tx_queue[i].ep_no);
            if ( pUsbCore->tx_queue[i].notify_complete == NULL ) {
                deq_info.deq_type = HIFQ_FREEQ;
            } else {
                deq_info.deq_type = HIFQ_DEQ;
            }

            // check Tx bitmap of the endpoint
            if (((hifusbq_check_dl_newpkt() >> i) & 0x01) == 0){
                continue;
            }

            num = hifusbq_poll_queue(deq_info, (void**)&first_gpd, (void**)&last_gpd);

            if ( num == 0 ) {
                continue;
            }

#ifdef __USBCORE_DEBUG__
            usbc_core_printf("[USBCORE] poll tx[%d] return %d first gpd %x last gpd %x\r\n", i, num, first_gpd, last_gpd);
            //usbc_core_dump_gpd_list(first_gpd, last_gpd);
#endif
            usbc_data_trace(USBCORE_POLL_QUEUE_TX, i, num, first_gpd, last_gpd);
#ifdef __USBCORE_TARGET_DEBUG__            
            kal_uint32 gpd_len, bd_len;
            usbc_core_getGpdLength(first_gpd, last_gpd, &gpd_len, &bd_len);
#endif
            if ( pUsbCore->tx_queue[i].notify_complete != NULL ) {
                if ( first_gpd == NULL ) {
                    /* just indicate a notification */
                    pUsbCore->tx_queue[i].notify_complete(pUsbCore->tx_queue[i].class_device_id, NULL);
                } else {
                    USBC_CLASS_REMOTE_WK_LOCK(pUsbCore->usbc_class_func_access_mutex);
                    pUsbCore->is_func_be_accessed[pUsbCore->tx_queue[i].class_device_id] = KAL_TRUE;
                    USBC_CLASS_REMOTE_WK_UNLOCK(pUsbCore->usbc_class_func_access_mutex);

                    request = (usbc_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(first_gpd);
                    request->next_request = NULL;
                    request->first_gpd = first_gpd;
                    request->last_gpd = last_gpd;
                    pUsbCore->tx_queue[i].notify_complete(pUsbCore->tx_queue[i].class_device_id, request);
                }
            }

#ifdef __USBCORE_TARGET_DEBUG__
            usbc_data_trace(USBCORE_POLL_QUEUE_LEN_TX, i, gpd_len, bd_len);
#endif
        }
    }

    HIF_SWLA_STOP("UDP");


    HIF_SWLA_START("UUP");

    for ( i=0; i<pUsbCore->total_rx_queues; i++ ) {
        if ( pUsbCore->rx_queue[i].state > USBC_CORE_QUEUE_STATE_INITIATED ) {
            first_gpd  = NULL;
            last_gpd   = NULL;
            num = 0;
            kal_mem_set(&deq_info, 0, sizeof( deq_info));

            deq_info.q_type = HIFQ_TYPE_RX;
            deq_info.que_no = HIFUSB_EPNO_2_QNO(pUsbCore->rx_queue[i].ep_no);
            deq_info.deq_type = HIFQ_DEQ;

            // check Rx bitmap of the endpoint
            if (((hifusbq_check_ul_newpkt() >> i) & 0x01) == 0){
                continue;
            }

            num = hifusbq_poll_queue(deq_info, (void**)&first_gpd, (void**)&last_gpd);

            if ( num == 0 ) {
                continue;
            }

#ifdef __USBCORE_DEBUG__
            usbc_core_printf("[USBCORE] poll rx[%d] return %d first gpd %x last gpd %x\r\n", i, num, first_gpd, last_gpd);
            //usbc_core_dump_gpd_list(first_gpd, last_gpd);
#endif
            usbc_data_trace(USBCORE_POLL_QUEUE_RX, i, num, first_gpd, last_gpd);
#ifdef __USBCORE_TARGET_DEBUG__
            kal_uint32 gpd_len, bd_len;
            usbc_core_getGpdLength(first_gpd, last_gpd, &gpd_len, &bd_len);
#endif

            if ( pUsbCore->rx_queue[i].notify_complete != NULL ) {
                if ( first_gpd == NULL ) {
                    /* has return number, but no return GPD */
                    ASSERT(0);
                } else {
                    USBC_CLASS_REMOTE_WK_LOCK(pUsbCore->usbc_class_func_access_mutex);
                    pUsbCore->is_func_be_accessed[pUsbCore->rx_queue[i].class_device_id] = KAL_TRUE;
                    USBC_CLASS_REMOTE_WK_UNLOCK(pUsbCore->usbc_class_func_access_mutex);

                    request = (usbc_io_request_t*)QBM_DES_GET_SW_CTRL_FIELD(first_gpd);
                    request->next_request = NULL;
                    request->first_gpd = first_gpd;
                    request->last_gpd = last_gpd;
                    pUsbCore->rx_queue[i].notify_complete(pUsbCore->rx_queue[i].class_device_id, request);
                }
            } else {
                ASSERT(0);
            }

#ifdef __USBCORE_TARGET_DEBUG__
        usbc_data_trace(USBCORE_POLL_QUEUE_LEN_RX, i, gpd_len, bd_len);
#endif

        }
    }

    HIF_SWLA_STOP("UUP");
}

static kal_bool usbc_core_isConfigValid(kal_uint8 iConfig)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8* pDevConf = pUsbCore->descriptors.device;

    if(iConfig <= pDevConf[17])
    {
        return KAL_TRUE;
    }
    else
    {
        usbc_trace_warn(USBCORE_CONF_INVALID, iConfig);
        return KAL_FALSE;
    }
}


void usbc_normal_hif_process_indications(void)
{
    usbc_core_t    *pUsbCore = usbc_core_get_instance();
    usbc_core_class_interface_t *intf;
    usbc_ind_t      ind_dequeued;
    kal_uint8 class_device_id;

    USBC_CLASS_DEVICE_CONTEXT_CHECK();

    while (usbc_dequeue_ind(&ind_dequeued)) {
        switch (ind_dequeued.type) {
        case USBC_IND_CTRL_SETUP:
            ASSERT(pUsbCore->setup_indicated);
            intf = &pUsbCore->class_interface[ind_dequeued.data];

            if (USBC_CORE_CLASS_INTERFACE_STATE_ACTIVE == intf->state && 
                NULL != intf->notify_control_setup_packet) {

                intf->notify_control_setup_packet(intf->class_device_id, &pUsbCore->setup_packet);
            } else {
                usbc_core_set_control_request(NULL, 0, HIFUSB_CONTROL_REQUEST_TYPE_STALL);
            }
            break;

        case USBC_IND_CTRL_CMPLT:
            intf = &pUsbCore->class_interface[ind_dequeued.data];

            if (USBC_CORE_CLASS_INTERFACE_STATE_ACTIVE == intf->state && 
                NULL != intf->notify_control_complete) {

                intf->notify_control_complete(intf->class_device_id);
            }
            break;

        case USBC_IND_DEV_EVENT:
            switch ((usbc_usb_state_e)ind_dequeued.data) {
            case USBC_USB_STATE_ATTACHING:
                usbc_core_notify_state_attaching();
                break;
            case USBC_USB_STATE_ATTACHED:
                usbc_core_notify_state_attached();
                break;
            case USBC_USB_STATE_DETACHING:
                usbc_core_notify_state_detaching();
                break;
            case USBC_USB_STATE_SUSPENDING:
                usbc_core_notify_state_suspending();
                break;
            case USBC_USB_STATE_RESUME:
                usbc_core_notify_state_resume();
                break;
            case USBC_USB_STATE_RESET:
                usbc_core_notify_state_reset();
                pUsbCore->usb_configuration = 0;
                break;
            default:
                ASSERT(KAL_FALSE);
                break;
            }
            break;

        case USBC_IND_SPEED_CHANGE:
            usbc_core_notify_speed_change((usbc_usb_speed_e)ind_dequeued.data);
            break;

        case USBC_IND_ALT_SETTING:
            usbc_core_notify_alternate_setting(ind_dequeued.ext, ind_dequeued.data);
            break; 

        case USBC_IND_PIPE_STALL:
            usbc_core_notify_stall(
                    ((ind_dequeued.data & 0x80) ? KAL_TRUE : KAL_FALSE), /* is_tx */
                    (ind_dequeued.data & 0x7f), /* queue_idx */
                    ((1 == ind_dequeued.ext) ? KAL_TRUE : KAL_FALSE)); /* stall */
            break;
        case USBC_IND_MODE_SWITCH:
            if (ind_dequeued.data < USB_MODE_NUM) {
                usbc_mode_switch(ind_dequeued.data);
            } else {
                ASSERT(KAL_FALSE);
            }
            break;

        case USBC_IND_FUNC_EVENT:
            class_device_id = ind_dequeued.ext;
            switch((usbc_func_state_e)ind_dequeued.data)
            {
                case USBC_FUNC_WK_ENABLE:
                     usbc_core_notify_func_wk_ability(class_device_id, KAL_TRUE);
                    break;
                case USBC_FUNC_WK_DISABLE:
                    usbc_core_notify_func_wk_ability(class_device_id, KAL_FALSE);
                    break;
                case USBC_FUNC_STATE_SUSPENDING:
                    usbc_core_notify_function_state_suspending(class_device_id);
                    break;
                case USBC_FUNC_STATE_RESUME:
                    usbc_core_notify_function_state_resume(class_device_id);
                    break;
                case USBC_FUNC_WK_ENABLE_STATE_SUSPENDING:
                    usbc_core_notify_func_wk_ability(class_device_id, KAL_TRUE);
                    usbc_core_notify_function_state_suspending(class_device_id);
                    usbc_core_set_control_request(NULL, 0, USBC_CONTROL_REQUEST_TYPE_RECEIVE);
                    break;
                case USBC_FUNC_WK_ENABLE_STATE_RESUME:
                    usbc_core_notify_function_state_resume(class_device_id);
                    usbc_core_notify_func_wk_ability(class_device_id, KAL_TRUE);
                    usbc_core_set_control_request(NULL, 0, USBC_CONTROL_REQUEST_TYPE_RECEIVE);
                    break;
                case USBC_FUNC_WK_DISABLE_STATE_SUSPENDING:
                    usbc_core_notify_func_wk_ability(class_device_id, KAL_FALSE);
                    usbc_core_notify_function_state_suspending(class_device_id);
                    usbc_core_set_control_request(NULL, 0, USBC_CONTROL_REQUEST_TYPE_RECEIVE);
                    break;
                case USBC_FUNC_WK_DISABLE_STATE_RESUME:
                    usbc_core_notify_function_state_resume(class_device_id);
                    usbc_core_notify_func_wk_ability(class_device_id, KAL_FALSE);
                    usbc_core_set_control_request(NULL, 0, USBC_CONTROL_REQUEST_TYPE_RECEIVE);
                    break;
                case USBC_FUNC_SET_FEATURE_ERROR:
                    usbc_core_set_control_request(NULL, 0, USBC_CONTROL_REQUEST_TYPE_STALL);
                    break;
                default:
                    ASSERT(KAL_FALSE);
                    break;
            }
            break;
        case USBC_IND_SET_CONFIG:
            if(usbc_core_isConfigValid(ind_dequeued.data))
            {
                usbc_core_set_usb_configuration(ind_dequeued.data);
                usbc_core_set_control_request(NULL, 0, USBC_CONTROL_REQUEST_TYPE_RECEIVE);
            }
            else
            {
                usbc_core_set_control_request(NULL, 0, USBC_CONTROL_REQUEST_TYPE_STALL);
            }
            break;

        default:
            ASSERT(KAL_FALSE);
            break;
        }
    }
}


kal_bool usbc_normal_hif_hw_usbq_set_gpd(hif_queue_type_e q_type, kal_uint8 queue_no, qbm_gpd* first_gpd, qbm_gpd* last_gpd)
{
    kal_bool        result = KAL_FALSE;
    USBC_NON_EXCEPTION_MODE_CHECK();

    usbc_data_trace(USBCORE_CLASS_SUBMIT_IO_REQUEST_HWQ, ((q_type << 8) | (queue_no & 0xFF)), first_gpd, last_gpd);
    result = hifusbq_set_gpd(q_type, queue_no, first_gpd, last_gpd);

    return result;
}

kal_bool usbc_normal_hif_sw_usbq_set_gpd(hif_queue_type_e q_type, kal_uint8 queue_no, qbm_gpd* first_gpd, qbm_gpd* last_gpd)
{
    kal_bool        result = KAL_FALSE;
    USBC_NON_EXCEPTION_MODE_CHECK();

    usbc_data_trace(USBCORE_CLASS_SUBMIT_IO_REQUEST_SWQ, ((q_type << 8) | (queue_no & 0xFF)), first_gpd, last_gpd);
    result = hifusbq_pwrsave_buffer_gpd(q_type, queue_no, first_gpd, last_gpd);

    return result;
}

void usbc_normal_hif_factory(void)
{
    USBC_NON_EXCEPTION_MODE_CHECK();

    usbc_core_indicate_control_setup_packet = usbc_normal_hif_indicate_control_setup_packet;
    usbc_core_indicate_control_complete = usbc_normal_hif_indicate_control_complete;
    usbc_core_indicate_alternate_setting = usbc_normal_hif_indicate_alternate_setting;
    usbc_core_indicate_stall = usbc_normal_hif_indicate_stall;
    usbc_core_set_control_request = usbc_normal_hif_set_control_request;
    usbc_core_set_property = hifusb_set_property;
    usbc_core_set_usb_address = usbc_normal_hif_set_usb_address;
    usbc_core_set_usb_configuration = usbc_normal_hif_set_usb_configuration;
    usbc_core_set_stall = usbc_normal_hif_set_stall;
    usbc_core_clear_stall = usbc_normal_hif_clear_stall;
    usbc_core_set_usb_testmode = hifusb_set_usb_testmode;
#if __USBC_TARGET_HIF_DRIVER_SUPPORT__
    usbc_core_set_ss_dev_init_u1_en = hifusb_ss_dev_init_u1_en;
    usbc_core_set_ss_dev_init_u2_en = hifusb_ss_dev_init_u2_en;
#endif
    usbc_core_set_usbhif_address = hifusb_set_usb_address;
    usbc_core_set_usbhif_configuration = hifusb_set_usb_configuration;
    usbc_core_set_usbhif_connect = hifusb_set_connect;
    usbc_core_set_usbhif_disconnect = hifusb_set_disconnect;
    usbc_core_set_usbhifq_gpd = usbc_normal_hif_hw_usbq_set_gpd;
}

void usbc_meta_hif_factory(void)
{
    USBC_NON_EXCEPTION_MODE_CHECK();

    usbc_core_set_property = hifusb_set_property_emulate;
    usbc_core_set_usbhif_address = hifusb_set_usb_address_emulate;
    usbc_core_set_usbhif_configuration = hifusb_set_usb_configuration_emulate;
}

void usbc_suspended_hif_factory(void)
{
    USBC_NON_EXCEPTION_MODE_CHECK();

    // Update function pointer for buffering GPDs in DRAM
    usbc_core_set_usbhifq_gpd = usbc_normal_hif_sw_usbq_set_gpd;
}


#ifdef ATEST_SYS_USBCORE
void usbc_fake_hif_factory(void)
{
    usbc_core_set_control_request = usbc_ut_fake_set_control_request;
}
#endif

void usbc_normal_hif_meta_attach(void)
{
    usbc_core_t        *pUsbCore = usbc_core_get_instance();
    hifusb_boot_info_t usb_boot_info;

    /* get USB HW info */
    hifusb_get_boot_info(&usb_boot_info);

    /* emulate driver connection */
    usbc_core_notify_state_attaching();

    /* emulate HIFUSB_NOTIFY_EVT_RESET */
    hifusb_reset_isr_emulate();
    usbc_core_speed_change(pUsbCore, (usbc_usb_speed_e)usb_boot_info.usb_speed);    // emulate speed change notify
    usbc_core_notify_speed_change((usbc_usb_speed_e)usb_boot_info.usb_speed);
    usbc_core_set_hif_configuration();      // emulate reset notify
    usbc_core_notify_state_reset();

    /* emulate SetAddress */
    usbc_core_set_usb_address(usb_boot_info.usb_addr & 0x7f);     // set USB address

    /* emulate SetConfig */
    usbc_core_set_usb_configuration(1);   //set USB configuration, assume there is only one configuration in META mode

    /* restore function pointers of USB driver to normal state*/
    usbc_normal_hif_factory();
}

kal_bool usbc_normal_hif_is_meta_reused(void)
{
    hifusb_boot_info_t usb_boot_info;

    /* get USB HW info */
    hifusb_get_boot_info(&usb_boot_info);

#if defined(__MTK_TARGET__) && defined(__MULTI_BOOT__)
    return ((INT_BootMode() == MTK_FACTORY_MODE) && (usb_boot_info.boot_type == HIFUSB_BOOT_SUSPEND))? KAL_TRUE:KAL_FALSE;
#else
    return KAL_FALSE;
#endif
}

kal_bool usbc_normal_hif_restore_gpd_pwrsave()
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8 queue_no;
    kal_bool result;


    USBC_NON_EXCEPTION_MODE_CHECK();
        
    // Restore Tx GPDs
    for(queue_no = 0; queue_no < pUsbCore->total_tx_queues; queue_no++)
    {
        usbc_data_trace(USBCORE_RESTORE_TX_GPD_SWQ2HWQ, (HIFQ_TYPE_TX << 8) | (queue_no & 0xFF) );
        result = hifusbq_pwrsave_restore_gpd(HIFQ_TYPE_TX, queue_no);
        ASSERT(result);
    }

    // Restore Rx GPDs
    for(queue_no = 0; queue_no < pUsbCore->total_rx_queues; queue_no++)
    {
        usbc_data_trace(USBCORE_RESTORE_RX_GPD_SWQ2HWQ, (HIFQ_TYPE_RX << 8) | (queue_no & 0xFF) );
        result = hifusbq_pwrsave_restore_gpd(HIFQ_TYPE_RX, queue_no);
        ASSERT(result);
    }
    
    return KAL_TRUE;
}
