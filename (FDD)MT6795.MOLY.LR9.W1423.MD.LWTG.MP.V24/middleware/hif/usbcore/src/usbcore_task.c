/*!
 *  @file usbcore_task.c
 *  @author Roger Huang <chaomin.haung@mediatek.com>
 *  @version 1.0
 *  @section LICENSE
 *
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
 *  @section DESCRIPTION
 *  This file provides main functions of usbcore
 */

#include "kal_public_api.h"
#include "syscomp_config.h"
#include "usbcore_common.h"
#include "usbcore_hif.h"
#include "usbcore_usbstd.h"
#include "usbcore_main.h"
#include "hmu.h"
#include "hmu_conf_data.h"
#include "sysservice_msgid.h"
#include "nvram_interface.h"
#include "nvram_data_items.h"
#include "usbcore_debug.h"
#ifdef __ESL_COSIM_HIF__
#include "usbcore_cosim.h"
#endif

/*
 * Current operation mode.
 */
static usbc_op_mode_e   usbc_op_mode_s = USBC_OP_MODE_UNKNOWN;

/*
 * USBCORE settings read from HMU.
 */
static usbc_hmu_info_t  usbc_hmu_info_s;

/*
 * Pointer to current USBCORE global context.
 */
static usbc_core_t     *usbc_inst_s = NULL;

/*
 * USBCORE global context for exception mode.
 */
static usbc_core_t      usbc_except_inst_s;

/*
 * USBCORE global context for normal mode.
 */
static usbc_core_t      usbc_normal_inst_s;


usbc_op_mode_e usbc_get_op_mode(void)
{
    return usbc_op_mode_s;
}


void usbc_set_op_mode(usbc_op_mode_e op_mode)
{
    if (USBC_OP_MODE_EXCEPTION == op_mode) {
        usbc_inst_s = &usbc_except_inst_s;
    } else {
        usbc_inst_s = &usbc_normal_inst_s;
    }
    usbc_op_mode_s = op_mode;
}


usbc_core_t* usbc_core_get_instance()
{
    USBC_CORE_INSTANCE_CHECK(usbc_inst_s);
    return usbc_inst_s;
}


usbc_hmu_info_t *usbc_core_get_hmu_info(void)
{
    return &usbc_hmu_info_s; 
}


void usbc_core_clear_register()
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8 i = 0;

    /* Clear USB Core Register information */
    for ( i=0; i<MAX_USBCORE_QUEUE_NUM; i++ )
    {
        pUsbCore->tx_queue[i].state = USBC_CORE_QUEUE_STATE_DISABLE;
        pUsbCore->rx_queue[i].state = USBC_CORE_QUEUE_STATE_DISABLE;
    }
    for ( i=0; i<MAX_USBCORE_INTERFACE_NUM; i++ )
    {
        pUsbCore->class_interface[i].state = USBC_CORE_CLASS_INTERFACE_STATE_DISABLE;
    }
    for ( i=0; i<MAX_USBCORE_DEVICE_NUM; i++ )
    {
        pUsbCore->class_device[i].state = USBC_CORE_CLASS_DEVICE_STATE_NOTEXIST;
    }

    pUsbCore->total_class_devices = 0;
    pUsbCore->total_class_interfaces = 0;
    pUsbCore->total_tx_queues = 0;
    pUsbCore->total_rx_queues = 0;
}

void usbc_core_clear_status()
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8 i;

    /* Clear USBCORE task to wait for both indication events and tick events */
    usbc_trace_info(USBCORE_SUSPEND_START_POLL);
    pUsbCore->hmu_indication = HIF_DRV_EG_HIF_TICK_EVENT | HIF_DRV_EG_USBC_IND_EVENT;

    /* Clear USB device status */
    pUsbCore->usb_configuration = 0;
    pUsbCore->is_device_u1_enable = KAL_FALSE;
    pUsbCore->is_device_u2_enable = KAL_FALSE;
    pUsbCore->is_device_ltm_enable = KAL_FALSE;

    /* Clear USB class status */
    for( i=0; i<MAX_USBCORE_DEVICE_NUM; i++ )
    {
        pUsbCore->class_device[i].is_func_suspend = KAL_FALSE;
        pUsbCore->func_notify_list[i] = KAL_FALSE;
    }
}

kal_bool usbc_core_is_1st_interface(kal_uint8 idx)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8 i = 0;

    for(i = 0; i <  pUsbCore->total_class_devices; i++)
    {
        if( pUsbCore->class_device[i].device_instance.interface_no[0] == idx )
        {
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}

kal_uint8 usbc_class_device_get_1st_interface(kal_uint8 class_device_id)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();

    return pUsbCore->class_device[class_device_id].device_instance.interface_no[0];
}

kal_bool usbc_core_set_serial_number(void)
{
    kal_bool result = KAL_FALSE;

#if USB_UNIQUE_SERIAL_NUM_ENABLE

    #define VAL_TO_STRING(uInt4Val) (((uInt4Val) < 0x0a)? ((uInt4Val) + 0x30):((uInt4Val) - 0x0a + 0x61))
    #define NO_IMEI_SERIAL_NUM  0xffffffffffffffff

    kal_uint16* pSerialNumber = usbc_core_get_instance()->dev_param->serial_number;
    kal_uint8 *pBuffer = NULL;
    kal_uint16 record, size, sVal;
    kal_uint8 i = 0;

    /* check for valid ID for NVRAM */
    if( NVRAM_ERRNO_SUCCESS != nvram_get_info(UNI_ID, &record, &size) )
    {
        ASSERT(0);
        return result;
    }

    pBuffer = (kal_uint8*)get_ctrl_buffer(size);

    /* store IMEI to pBuffer, and store the length of IMEI to size */
    if ( nvram_external_read_data(UNI_ID, 1, pBuffer, (kal_uint32)size) )
    {
        if(NO_IMEI_SERIAL_NUM != *((kal_uint64*)pBuffer))   // update serial number if IEMI has been set
        {
            /* 
            * Assume the maximum length of IEMI is 0x0F, and we also define the length of serial number as 0x0F.
            * Then the length of parsed IMEI must be smaller or equal to the length of serial number
            */
            size = (size <= (0x0f >> 1))? size:(0x0f >> 1);
            while( i < size )
            {
                sVal = pBuffer[i] & 0x0f;                       // the lower part of pBuffer[i] is the odd part of the serail number
                pSerialNumber[(i<<1)+1] = VAL_TO_STRING(sVal);
                sVal = (pBuffer[i] & 0xf0) >> 4;                // the higher part of pBuffer[i] is the even part of the serail number
                pSerialNumber[(i<<1)+2] = VAL_TO_STRING(sVal);
                i++;
            }
            sVal = pBuffer[i] & 0x0f;                           // pBuffer[15] is the last field of the serail number
            pSerialNumber[0x0f] = VAL_TO_STRING(sVal);

            free_ctrl_buffer(pBuffer);
            result =  KAL_TRUE;
        }
    }
    else
    {
        free_ctrl_buffer(pBuffer);
        ASSERT(0);
    }
#endif

    return result;
}

kal_uint8 usbc_core_get_function_remote_wk_list(void)
{
    kal_uint8 i, total_class_device, result;
    usbc_core_t* pUsbCore = usbc_core_get_instance();

    result = 0;
    total_class_device = pUsbCore->total_class_devices;

    for(i=0; i<total_class_device; i++)
    {
        if ( pUsbCore->class_device[i].query_func_wk_status &&
             pUsbCore->class_device[i].query_func_wk_status(i) == 0x03 )
        {
            result |= (0x01 << i);
        } 
    }

    return result;
}

kal_uint8 usbc_core_get_function_suspend_list(void)
{
    kal_uint8 i, total_class_device, result;
    usbc_core_t* pUsbCore = usbc_core_get_instance();

    result = 0;
    total_class_device = pUsbCore->total_class_devices;

    for(i=0; i<total_class_device; i++)
    {
        if ( pUsbCore->class_device[i].is_func_suspend &&
             pUsbCore->class_device[i].is_func_suspend == KAL_TRUE )
        {
            result |= (0x01 << i);
        }
    }

    return result;
}

static void usbc_core_task_main(task_entry_struct* task_entry_ptr)
{
    ilm_struct current_ilm;
	kal_uint32 rt_event;
    kal_uint16 timer_index;
    usbc_core_t* pUsbCore = usbc_core_get_instance();

    kal_set_active_module_id(MOD_USBCORE);
    kal_mem_set(&current_ilm, 0, sizeof(ilm_struct));

    usbc_trace_info(USBCORE_TASK_MAIN);

    if( pUsbCore->is_mode_meta_reused )
    {
        usbc_normal_hif_meta_attach();
    }

    while (1)
    {
        //usbc_core_printf("=========>usbcore_task_main\r\n");

        /* msg_receive_extq will block, therefore we poll if any message
           exist first */
        while ( msg_get_extq_messages() > 0 )
        {
            if ( msg_receive_extq(&current_ilm) != KAL_TRUE )
            {
                break;
            }

            switch (current_ilm.msg_id)
            {
                case MSG_ID_TIMER_EXPIRY:
                    timer_index = evshed_get_index(&current_ilm);
                    switch (timer_index)
                    {
                        case USBC_WK_NOTIFY_INDEX:
                            evshed_timer_handler(pUsbCore->usbc_es_wk_notify_g);
                            break;

                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }

            destroy_ilm(&current_ilm);
        }

        /* Wait someone notify HMU to wake up HIF. */
        rt_event = hmu_hifeg_wait(pUsbCore->hmu_indication);
        if ((HIF_DRV_EG_HIF_TICK_EVENT & rt_event) && 
            (pUsbCore->state != USBC_USB_STATE_SUSPENDED))
        {
            /* poll HIF queue data */
            usbc_normal_hif_poll_queue();
        } 
        if ((HIF_DRV_EG_USBC_IND_EVENT & rt_event))
        {
            /* Handle indications */
            usbc_normal_hif_process_indications();
        } 
    }
}


static kal_bool usbc_core_task_init(void)
{
    usbc_core_t* pUsbCore;
    kal_char usbc_class_mutex_name[50];
    usbc_core_printf("=========>usbcore_task_init\r\n");
    usbc_trace_info(USBCORE_TASK_INIT);

#ifdef IPCORE_NOT_PRESENT
    hmu_boot_init();
#endif
    
    usbc_set_op_mode(USBC_OP_MODE_NORMAL);
    kal_mem_set(usbc_core_get_instance(), 0, sizeof(usbc_core_t));

    usbc_core_clear_register();
    usbc_core_clear_status();

    pUsbCore = usbc_core_get_instance();

    // create enhance mutex
    sprintf(usbc_class_mutex_name, "USBC_CLASS_REMOTE_WK_MUTEX");
    pUsbCore->usbc_class_remote_wk_mutex = kal_create_enh_mutex(usbc_class_mutex_name);
    sprintf(usbc_class_mutex_name, "USBC_CLASS_RENOTIFY_MUTEX");
    pUsbCore->usbc_class_renotify_mutex = kal_create_enh_mutex(usbc_class_mutex_name);
    sprintf(usbc_class_mutex_name, "USBC_CLASS_FUNC_ACCESS_MUTEX");
    pUsbCore->usbc_class_func_access_mutex = kal_create_enh_mutex(usbc_class_mutex_name);
    if ( NULL == pUsbCore->usbc_class_remote_wk_mutex ||
         NULL == pUsbCore->usbc_class_renotify_mutex ||
         NULL == pUsbCore->usbc_class_func_access_mutex )
    {
        ASSERT(0);
    }

    // initial an evnet scheduler
    pUsbCore->usbc_es_wk_notify_g = evshed_create(
                        "USBC_WK_NOTIFY", /* timer_name: event scheduler name */
                        MOD_USBCORE, /* dest_mod_id: system sends timeout message to this module when event scheduler timeout happens */
                        0, /* fuzz */
                        255); /* max_delay_ticks */
    if (pUsbCore->usbc_es_wk_notify_g) {
        evshed_set_index(pUsbCore->usbc_es_wk_notify_g, USBC_WK_NOTIFY_INDEX);
    } else {
        ASSERT(0);
    }

    usbc_normal_hif_factory();

    usbc_stack_checkin(USB_CLASS_NUM, NULL);
    return KAL_TRUE;
}


static kal_bool usbc_core_task_reset(void)
{
    usbc_core_printf("=========>usbcore_task_reset\r\n");
    usbc_trace_info(USBCORE_TASK_RESET);

    /* Do task's reset here.
     * Notice that: shouldn't execute modules reset handler since
     * stack_task_reset() will do. */
    return KAL_TRUE;
}

extern void usbc_stack_reset(); /* Simply reset USB stack before task init, so, no need to be public. */

kal_bool usbc_core_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct usbc_core_handler_info =
    {
#ifndef __ESL_COSIM_HIF__    
        usbc_core_task_main,        /* task entry function */
        usbc_core_task_init,        /* task initialization function */
#else
        usbc_cosim_core_task_main,  /* task entry function for ESL COSIM */
        usbc_cosim_core_task_init,  /* task initialization function for ESL_COSIM */
#endif
        usbc_core_task_reset        /* task reset handler */
    };

    usbc_core_printf("=========>usbcore_create\r\n");
    usbc_trace_info(USBCORE_TASK_CREATE);

    *handle = (comptask_handler_struct *)&usbc_core_handler_info;

    usbc_stack_reset();
    return KAL_TRUE;
}

