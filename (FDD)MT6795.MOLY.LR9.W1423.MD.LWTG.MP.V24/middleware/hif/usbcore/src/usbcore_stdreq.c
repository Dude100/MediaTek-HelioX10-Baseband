/*!
 *  @file usbcore_usbstd.c
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
 *  This file provides usb standard request handler function
 */

#include "kal_public_api.h"
#include "syscomp_config.h"
#include "usbcore_common.h"
#include "usbcore_usbstd.h"
#include "usbcore_main.h"
#include "usbcore_hif.h"
#include "hmu.h"
#include "hmu_conf_data.h"
#include "usbcore_ind_q.h"
#include "usbcore_debug.h"

#ifdef ATEST_SYS_USBCORE
#include "usbcore_ut.h"
#endif

#define _USB30_DEVICE_REMOTE_WK_SUPPORT_ 1

static kal_uint8 usbc_bos_s[USBC_MAX_BOS_SIZE] = {
    /*BOS standard descriptor*/
    0x05,                        /*bLength*/
    0x0F,                        /*bDescriptorType*/
    0x16, 0x00, //0x0016,        /*wTotalLength*/
    0x02,                        /*bNumDeviceCaps*/

    /*USB2.0 Extension Device Capability Descriptor*/
    0x07,                        /*bLength*/
    0x10,                        /*bDescriptorType*/
    0x02,                        /*bDevCapabilityType*/
    /*Link Power Management : YES*/
    0x02, 0x00, 0x00, 0x00, //0x00000002 /*bmAttributes*/

    /*SuperSpeed Device Capability Descriptor*/
    0x0A,                        /*bLength*/
    0x10,                        /*bDescritorType*/
    0x03,                        /*bDevCapabilityType*/
    0x00,                        /*bmAttributes*/
    /*bit-map : support FS/HS/5Gbs*/
    0x0E, 0x00, //0x000E,        /*wSpeedsSupport*/ /* 3: 5Gbps, 2: high 1: full, 0: low */
    0x01,                        /*bFunctionalitySupport*/ /* lowest speed supported */
    0x0A,                        /*bU1DevExitLat*/ /* Less than 0x0a us */
    0x20, 0x00 //0x0020,         /*bU2DevExitLat*/ /* Less than 0x20 us */
};

/*
 *  Define Microsoft OS string descriptor
 */
#define USBC_MS_OS_STRING_INDEX             0xEE
#define USBC_MAX_OS_STRING_LENGTH           18
static const kal_uint16 usbc_os_string[] = {'M', 'S', 'F', 'T', '1', '0', '0'};
static usbc_os_string_descriptor_t usbc_os_string_desc;
static kal_uint8 pOtherSpeedDescript[256];

static void usbc_core_handle_set_address()
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint16 wValue = pUsbCore->setup_packet.wValue;

    usbc_core_printf("=========>usbcore_handle_set_address\r\n");
    usbc_trace_info(USBCORE_SET_ADDRESS, (wValue & 0x7f));

    usbc_core_set_usb_address(wValue & 0x7f);
    usbc_core_set_control_request(NULL, 0, USBC_CONTROL_REQUEST_TYPE_RECEIVE);
}


static void usbc_core_handle_get_status()
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    usbc_control_request_type_e type = USBC_CONTROL_REQUEST_TYPE_STALL;
    kal_uint8 bRecip = pUsbCore->setup_packet.bmRequestType & USBC_REQUEST_RECIP_MASK;
    //kal_uint16 wIndex = pUsbCore->setup_packet.wIndex;
    kal_uint8* pBuffer = pUsbCore->control_request_buffer;
    kal_uint32 length = 0;

    usbc_core_printf("=========>usbcore_handle_get_status\r\n");
    usbc_trace_info(USBCORE_GET_STATUS, bRecip);

    if ( bRecip == USBC_REQUEST_RECIP_DEVICE )
    {
        kal_uint8 i;

        /* D0: Self Powered, D1: Remote Wakeup */
        pBuffer[0] = 0;     //Bus Power
        pBuffer[1] = 0;     //No Remote Wakeup
        length = 2;
        type = USBC_CONTROL_REQUEST_TYPE_SEND;

        // report remote wakeup status in USB 1.1 and USB 2.0 (0 in USB 3.0)
        if( pUsbCore->speed != USBC_USB_SPEED_USB30 )
        {
            for( i=0; i<pUsbCore->total_class_devices; i++)
            {
                if ( NULL != pUsbCore->class_device[i].query_func_wk_status &&
                     pUsbCore->class_device[i].query_func_wk_status(i) & 0x0002 )
                {
                    pBuffer[0] |= ((kal_uint8)0x01 << 1);
                    break;
                }
            }
        }
		else
		{
            // USB 3.0 U1 enable status (0 in USB 2.0)
            if ( pUsbCore->is_device_u1_enable )
            {
                pBuffer[0] |= ((kal_uint8)0x01 << 2);
            }

            // USB 3.0 U2 enable status ( 0 in USB 3.0)
            if( pUsbCore->is_device_u2_enable )
            {
                pBuffer[0] |= ((kal_uint8)0x01 << 3);
            }

            // USB 3.0 LTM enable status ( 0 in USB 3.0)
            if( pUsbCore->is_device_ltm_enable )
            {
                pBuffer[0] |= ((kal_uint8)0x01 << 4);
            }
		}

    } else
    if ( bRecip == USBC_REQUEST_RECIP_INTERFACE )
    {
        kal_uint8 nInterface = (kal_uint8)pUsbCore->setup_packet.wIndex;
        kal_uint8 class_device_id = pUsbCore->class_interface[nInterface].class_device_id;

        /* return two bytes of 0x00, 0x00.
           Both bytes are reserved for future use
         */
        pBuffer[0] = 0;
        pBuffer[1] = 0;
        length = 2;
        type = USBC_CONTROL_REQUEST_TYPE_SEND;

        if ( pUsbCore->speed == USBC_USB_SPEED_USB30 &&
             usbc_core_is_1st_interface(nInterface)  && 
             NULL !=  pUsbCore->class_device[class_device_id].query_func_wk_status )
        {
            /* if the requested interface is the first one of a function,
               report the function remote wakeup capability and state
             */
            pBuffer[0] = pUsbCore->class_device[class_device_id].query_func_wk_status(class_device_id) & ((kal_uint8)0xFF);
        }

    } else
    if ( bRecip == USBC_REQUEST_RECIP_ENDPOINT )
    {
        /* D0: HALT, D1: Reserve */
        kal_uint8 nEnd = pUsbCore->setup_packet.wIndex & USBC_EP_ADDR_NUM_MASK; /* TODO: It's error-prone to use en_no instead of endpoint address. */
        usbc_core_queue_t* pQueue = NULL;
        kal_uint8 i = 0;

        if ( (pUsbCore->setup_packet.wIndex & USBC_EP_ADDR_DIR_IN) )
        {
            for ( i=0; i<MAX_USBCORE_QUEUE_NUM; i++ )
            {
                if ( (pUsbCore->tx_queue[i].ep_no == nEnd) &&
                     (pUsbCore->tx_queue[i].state > USBC_CORE_QUEUE_STATE_INITIATED) )
                {
                    pQueue = &pUsbCore->tx_queue[i];
                    break;
                }
            }
        } else {
            for ( i=0; i<MAX_USBCORE_QUEUE_NUM; i++ )
            {
                if ( (pUsbCore->rx_queue[i].ep_no == nEnd) &&
                     (pUsbCore->rx_queue[i].state > USBC_CORE_QUEUE_STATE_INITIATED) )
                {
                    pQueue = &pUsbCore->rx_queue[i];
                    break;
                }
            }
        }

        /* D0: HALT, D1: Reserve */
        if ( pQueue == NULL )
        {
            length = 0;
            type = USBC_CONTROL_REQUEST_TYPE_STALL;

            if( nEnd == 0)
            {
                pBuffer[0] = 0;
                pBuffer[1] = 0;
                length = 2;
                type = USBC_CONTROL_REQUEST_TYPE_SEND;
            }

        } else {
            switch (pQueue->state)
            {
                case USBC_CORE_QUEUE_STATE_ACTIVE:
                {
                    pBuffer[0] = 0;
                    pBuffer[1] = 0;
                    length = 2;
                    type = USBC_CONTROL_REQUEST_TYPE_SEND;
                    break;
                }
                case USBC_CORE_QUEUE_STATE_STALL:
                {
                    pBuffer[0] = 1;
                    pBuffer[1] = 0;
                    length = 2;
                    type = USBC_CONTROL_REQUEST_TYPE_SEND;
                    break;
                }
                default:
                {
                    ASSERT(0);
                    length = 0;
                    type = USBC_CONTROL_REQUEST_TYPE_STALL;
                    break;
                }
            }
        }
    } else {
        ASSERT(0);
        type = USBC_CONTROL_REQUEST_TYPE_STALL;
    }

    usbc_core_set_control_request(pBuffer, length, type);

}


static void usbc_core_handle_set_feature()
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    usbc_control_request_type_e type = USBC_CONTROL_REQUEST_TYPE_STALL;
    kal_uint8 bRecip = pUsbCore->setup_packet.bmRequestType & USBC_REQUEST_RECIP_MASK;
    kal_uint16 wIndex = pUsbCore->setup_packet.wIndex;
    kal_uint16 wValue = pUsbCore->setup_packet.wValue;
    kal_bool is_tx = KAL_TRUE;

    usbc_core_printf("=========>usbcore_handle_set_feature\r\n");
    usbc_trace_info(USBCORE_SET_FEATURE, bRecip, wIndex, wValue);

    if ( bRecip == USBC_REQUEST_RECIP_DEVICE )
    {
        usbc_ind_t          ind_to_enqueue;
        usbc_func_state_e   state;
        kal_uint8 i;

        if ( pUsbCore->speed == USBC_USB_SPEED_USB30 )
        {
            if ( pUsbCore->state <= USBC_USB_STATE_ATTACHING )
            {
                type = USBC_CONTROL_REQUEST_TYPE_STALL;
            } else 
            if ( wValue == USBC_FEATURE_U1_ENABLE )
            {
                pUsbCore->is_device_u1_enable = KAL_TRUE;
                usbc_core_set_ss_dev_init_u1_en(KAL_TRUE);
                type = USBC_CONTROL_REQUEST_TYPE_RECEIVE;
            } else
            if ( wValue == USBC_FEATURE_U2_ENABLE )
            {
                pUsbCore->is_device_u2_enable = KAL_TRUE;
                usbc_core_set_ss_dev_init_u2_en(KAL_TRUE);
                type = USBC_CONTROL_REQUEST_TYPE_RECEIVE;
            } else
            if ( wValue == USBC_FEATURE_LTM_ENABLE )
            {
                pUsbCore->is_device_ltm_enable = KAL_TRUE;
                // TODO: set LTM enabled if support
                type = USBC_CONTROL_REQUEST_TYPE_RECEIVE;
            }
#if _USB30_DEVICE_REMOTE_WK_SUPPORT_
            else if ( wValue == USBC_FEATURE_DEVICE_REMOTE_WAKEUP )
            {
                // enable function remote wakeup for capable functions in enabling device remote wakeup
                state = USBC_FUNC_WK_ENABLE;
                for( i=0; i<pUsbCore->total_class_devices; i++)
                {
                    if ( NULL != pUsbCore->class_device[i].query_func_wk_status &&
                         pUsbCore->class_device[i].query_func_wk_status(i) & ((kal_uint8)0x01) )
                    {
                        ind_to_enqueue.type = USBC_IND_FUNC_EVENT;
                        ind_to_enqueue.ext = i;
                        ind_to_enqueue.data = (kal_uint8)state;
                        usbc_enqueue_ind(&ind_to_enqueue);
                    }
                }
                hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);

                type = USBC_CONTROL_REQUEST_TYPE_RECEIVE;
            } 
#endif
            else
            {
                 type = USBC_CONTROL_REQUEST_TYPE_STALL;
            }
        }
        else
        {
            if ( wValue == USBC_FEATURE_DEVICE_REMOTE_WAKEUP )
            {
                // enable function remote wakeup for capable functions in enabling device remote wakeup
                state = USBC_FUNC_WK_ENABLE;
                for( i=0; i<pUsbCore->total_class_devices; i++)
                {
                    if ( NULL != pUsbCore->class_device[i].query_func_wk_status &&
                         pUsbCore->class_device[i].query_func_wk_status(i) & ((kal_uint8)0x01) )
                    {
                        ind_to_enqueue.type = USBC_IND_FUNC_EVENT;
                        ind_to_enqueue.ext = i;
                        ind_to_enqueue.data = (kal_uint8)state;
                        usbc_enqueue_ind(&ind_to_enqueue);
                    }
                }
                hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);

                type = USBC_CONTROL_REQUEST_TYPE_RECEIVE;
            } else
            if ( wValue == USBC_FEATURE_TEST_MODE )
            {
                usbc_core_set_usb_testmode((hifusb_test_mode_e)(wIndex >> 8));
                type = USBC_CONTROL_REQUEST_TYPE_RECEIVE;
            }
            else
            {
                 type = USBC_CONTROL_REQUEST_TYPE_STALL;
            }
        }

    } else
    if ( bRecip == USBC_REQUEST_RECIP_INTERFACE )
    {
        kal_uint8 nInterface = (kal_uint8)wIndex & 0xFF;
        kal_uint8 suspendOpt = wIndex >> 8;
        usbc_ind_t          ind_to_enqueue;
        kal_uint8 class_device_id = pUsbCore->class_interface[nInterface].class_device_id;
        usbc_func_state_e    state;

        //specifies no interface features
        type = USBC_CONTROL_REQUEST_TYPE_RECEIVE;

        if( pUsbCore->speed == USBC_USB_SPEED_USB30 )
        {
            if ( pUsbCore->state > USBC_USB_STATE_ATTACHING &&
                 wValue == USBC_FEATURE_FUNCTION_SUSPEND && 
                 usbc_core_is_1st_interface(nInterface) )
            {
                if ( suspendOpt & 0x02 )
                {
                    state = (suspendOpt & 0x01)? USBC_FUNC_WK_ENABLE_STATE_SUSPENDING:USBC_FUNC_WK_ENABLE_STATE_RESUME;
                }
                else
                {
                    state = (suspendOpt & 0x01)? USBC_FUNC_WK_DISABLE_STATE_SUSPENDING:USBC_FUNC_WK_DISABLE_STATE_RESUME;
                }
                ind_to_enqueue.type = USBC_IND_FUNC_EVENT;
                ind_to_enqueue.ext = class_device_id;
                ind_to_enqueue.data = (kal_uint8)state;
                usbc_enqueue_ind(&ind_to_enqueue);

                // Wake up USBCORE task to process indications.
                hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);

                if(USBC_IS_IN_EXCEPTION_MODE())
                {
                    usbc_core_set_control_request(NULL, 0, USBC_CONTROL_REQUEST_TYPE_RECEIVE);
                }
            }
            else
            {
                ind_to_enqueue.type = USBC_IND_FUNC_EVENT;
                ind_to_enqueue.ext = class_device_id;
                ind_to_enqueue.data = (kal_uint8)USBC_FUNC_SET_FEATURE_ERROR;
                usbc_enqueue_ind(&ind_to_enqueue);

                // Wake up USBCORE task to process indications.
                hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);

                if(USBC_IS_IN_EXCEPTION_MODE())
                {
                    usbc_core_set_control_request(NULL, 0, USBC_CONTROL_REQUEST_TYPE_STALL);
                }
            }
            // Return USB 3.0 SetFeature of interfaces here, because the state is reported after finishing indications.
            return;
        }

    } else
    if ( bRecip == USBC_REQUEST_RECIP_ENDPOINT )
    {
        kal_uint8 nEnd = pUsbCore->setup_packet.wIndex & USBC_EP_ADDR_NUM_MASK; /* TODO: It's error-prone to use en_no instead of endpoint address. */
        usbc_core_queue_t* pQueue = NULL;
        kal_uint8 i = 0;

        if ( (pUsbCore->setup_packet.wIndex & USBC_EP_ADDR_DIR_IN) )
        {
            is_tx = KAL_TRUE;
            for ( i=0; i<MAX_USBCORE_QUEUE_NUM; i++ )
            {
                if ( (pUsbCore->tx_queue[i].ep_no == nEnd) &&
                     (pUsbCore->tx_queue[i].state > USBC_CORE_QUEUE_STATE_INITIATED) )
                {
                    pQueue = &pUsbCore->tx_queue[i];
                    break;
                }
            }
        } else {
            is_tx = KAL_FALSE;
            for ( i=0; i<MAX_USBCORE_QUEUE_NUM; i++ )
            {
                if ( (pUsbCore->rx_queue[i].ep_no == nEnd) &&
                     (pUsbCore->rx_queue[i].state > USBC_CORE_QUEUE_STATE_INITIATED) )
                {
                    pQueue = &pUsbCore->rx_queue[i];
                    break;
                }
            }
        }

        if ( pQueue == NULL )
        {
            type = USBC_CONTROL_REQUEST_TYPE_STALL;
        } else {
            pQueue->state = USBC_CORE_QUEUE_STATE_STALL;
            /* notify hif driver that this endpoint is set stall */
            usbc_core_set_stall(is_tx, nEnd);
            /* notify class driver that this queue is set stall */
            if ( pQueue->notify_stall != NULL )
            {
                usbc_core_indicate_stall(is_tx, i, KAL_TRUE);
            }
            type = USBC_CONTROL_REQUEST_TYPE_RECEIVE;
        }
    } else {
        type = USBC_CONTROL_REQUEST_TYPE_STALL;
    }

    usbc_core_set_control_request(NULL, 0, type);
}


static void usbc_core_handle_clear_feature()
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    usbc_control_request_type_e type = USBC_CONTROL_REQUEST_TYPE_STALL;
    kal_uint8 bRecip = pUsbCore->setup_packet.bmRequestType & USBC_REQUEST_RECIP_MASK;
    kal_uint16 wIndex = pUsbCore->setup_packet.wIndex;
    kal_uint16 wValue = pUsbCore->setup_packet.wValue;
    kal_bool is_tx = KAL_TRUE;

    usbc_core_printf("=========>usbcore_handle_clear_feature\r\n");
    usbc_trace_info(USBCORE_CLEAR_FEATURE, bRecip, wIndex, wValue);

    if ( bRecip == USBC_REQUEST_RECIP_DEVICE )
    {
        if ( pUsbCore->speed == USBC_USB_SPEED_USB30 )
        {
            type = USBC_CONTROL_REQUEST_TYPE_RECEIVE;

            if ( wValue == USBC_FEATURE_U1_ENABLE )
            {
                pUsbCore->is_device_u1_enable = KAL_FALSE;
                usbc_core_set_ss_dev_init_u1_en(KAL_FALSE);
            } else
            if ( wValue == USBC_FEATURE_U2_ENABLE )
            {
                pUsbCore->is_device_u2_enable = KAL_FALSE;
                usbc_core_set_ss_dev_init_u2_en(KAL_FALSE);
            } else
            if ( wValue == USBC_FEATURE_LTM_ENABLE )
            {
                pUsbCore->is_device_ltm_enable = KAL_FALSE;
                //TODO: clear LTM capability if support
            }
#if _USB30_DEVICE_REMOTE_WK_SUPPORT_
            else if ( wValue == USBC_FEATURE_DEVICE_REMOTE_WAKEUP )
            {
                kal_uint8           i;
                usbc_func_state_e   state;
                usbc_ind_t          ind_to_enqueue;

                // disable function remote wakeup for capable functions while disabling device remote wakeup
                state = USBC_FUNC_WK_DISABLE;
                for( i=0; i<pUsbCore->total_class_devices; i++ )
                {
                    if ( NULL != pUsbCore->class_device[i].query_func_wk_status &&
                         pUsbCore->class_device[i].query_func_wk_status(i) & ((kal_uint8)0x01) )
                    {
                        ind_to_enqueue.type = USBC_IND_FUNC_EVENT;
                        ind_to_enqueue.ext = i;
                        ind_to_enqueue.data = (kal_uint8)state;
                        usbc_enqueue_ind(&ind_to_enqueue);
                    }
                }
                hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);
                type = USBC_CONTROL_REQUEST_TYPE_RECEIVE;
            }
#endif
            else {
                type = USBC_CONTROL_REQUEST_TYPE_STALL;
            }
        }
        else
        {
            if ( wValue == USBC_FEATURE_DEVICE_REMOTE_WAKEUP )
            {
                kal_uint8           i;
                usbc_func_state_e   state;
                usbc_ind_t          ind_to_enqueue;

                // disable function remote wakeup for capable functions while disabling device remote wakeup
                state = USBC_FUNC_WK_DISABLE;
                for( i=0; i<pUsbCore->total_class_devices; i++ )
                {
                    if ( NULL != pUsbCore->class_device[i].query_func_wk_status &&
                         pUsbCore->class_device[i].query_func_wk_status(i) & ((kal_uint8)0x01) )
                    {
                        ind_to_enqueue.type = USBC_IND_FUNC_EVENT;
                        ind_to_enqueue.ext = i;
                        ind_to_enqueue.data = (kal_uint8)state;
                        usbc_enqueue_ind(&ind_to_enqueue);
                    }
                }
                hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);
                type = USBC_CONTROL_REQUEST_TYPE_RECEIVE;
            }
            else {
                type = USBC_CONTROL_REQUEST_TYPE_STALL;
            }
        }

    } else
    if ( bRecip == USBC_REQUEST_RECIP_INTERFACE )
    {
        kal_uint8 nInterface = (kal_uint8)pUsbCore->setup_packet.wIndex;
        usbc_ind_t          ind_to_enqueue;
        kal_uint8 class_device_id = pUsbCore->class_interface[nInterface].class_device_id;
        usbc_func_state_e    state;

        //specifies no interface features
        type = USBC_CONTROL_REQUEST_TYPE_RECEIVE;

        if( pUsbCore->speed == USBC_USB_SPEED_USB30 )
        {
            if ( wValue == USBC_FEATURE_FUNCTION_SUSPEND && usbc_core_is_1st_interface(nInterface) )
            {
                state = USBC_FUNC_WK_DISABLE_STATE_RESUME;
                ind_to_enqueue.type = USBC_IND_FUNC_EVENT;
                ind_to_enqueue.ext = class_device_id;
                ind_to_enqueue.data = (kal_uint8)state;
                usbc_enqueue_ind(&ind_to_enqueue);

                // Wake up USBCORE task to process indications.
                hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);
                
                if(USBC_IS_IN_EXCEPTION_MODE())
                {
                    usbc_core_set_control_request(NULL, 0, USBC_CONTROL_REQUEST_TYPE_RECEIVE);
                }
            }
            else
            {
                ind_to_enqueue.type = USBC_IND_FUNC_EVENT;
                ind_to_enqueue.ext = class_device_id;
                ind_to_enqueue.data = (kal_uint8)USBC_FUNC_SET_FEATURE_ERROR;
                usbc_enqueue_ind(&ind_to_enqueue);

                // Wake up USBCORE task to process indications.
                hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);
                
                if(USBC_IS_IN_EXCEPTION_MODE())
                {
                    usbc_core_set_control_request(NULL, 0, USBC_CONTROL_REQUEST_TYPE_STALL);
                }
            }
            // Return USB 3.0 SetFeature of interfaces here, because the state is reported after finishing indications.
            return;
        }

    } else
    if ( bRecip == USBC_REQUEST_RECIP_ENDPOINT )
    {
        kal_uint8 nEnd = pUsbCore->setup_packet.wIndex & USBC_EP_ADDR_NUM_MASK; /* TODO: It's error-prone to use en_no instead of endpoint address. */
        usbc_core_queue_t* pQueue = NULL;
        kal_uint8 i = 0;

        if ( (pUsbCore->setup_packet.wIndex & USBC_EP_ADDR_DIR_IN) )
        {
            is_tx = KAL_TRUE;
            for ( i=0; i<MAX_USBCORE_QUEUE_NUM; i++ )
            {
                if ( (pUsbCore->tx_queue[i].ep_no == nEnd) &&
                     (pUsbCore->tx_queue[i].state > USBC_CORE_QUEUE_STATE_INITIATED) )
                {
                    pQueue = &pUsbCore->tx_queue[i];
                    break;
                }
            }
        } else {
            is_tx = KAL_FALSE;
            for ( i=0; i<MAX_USBCORE_QUEUE_NUM; i++ )
            {
                if ( (pUsbCore->rx_queue[i].ep_no == nEnd) &&
                     (pUsbCore->rx_queue[i].state > USBC_CORE_QUEUE_STATE_INITIATED) )
                {
                    pQueue = &pUsbCore->rx_queue[i];
                    break;
                }
            }
        }

        if ( pQueue == NULL )
        {
            type = USBC_CONTROL_REQUEST_TYPE_STALL;
        } else {
            pQueue->state = USBC_CORE_QUEUE_STATE_ACTIVE;
            /* notify hif driver that this endpoint is clear stall */
            usbc_core_clear_stall(is_tx, nEnd);
            /* notify class driver that this queue is clear stall */
            if ( pQueue->notify_stall != NULL )
            {
                usbc_core_indicate_stall(is_tx, i, KAL_FALSE);
            }
            type = USBC_CONTROL_REQUEST_TYPE_RECEIVE;
        }
    } else {
        type = USBC_CONTROL_REQUEST_TYPE_STALL;
    }

    usbc_core_set_control_request(NULL, 0, type);
}

static void usbc_core_update_dt_other_speed(kal_uint8 *pDescript, kal_uint8 idx_config)
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8* pConfig = (kal_uint8*)pUsbCore->descriptors.configuration[idx_config];
    kal_uint16 totalLength = pConfig[2] + (pConfig[3] << 8);
    kal_uint8 *ptr = NULL;
    kal_uint16 i = 0;
    kal_uint8 currLength, type;

    // copy the configuration descriptor as the default other speeed descriptor
    kal_mem_cpy(pDescript, pConfig, totalLength);
    
    // set the descriptor type as other speed configuration;
    pDescript[1] = USBC_DT_OTHER_SPEED;

    // update the maximum packet size of each bulk endpoint descriptor
    ptr = pDescript;
    while(i < totalLength)
    {
        currLength = ptr[0];
        type = ptr[1];

        if( USBC_DT_ENDPOINT == type &&
            USBC_BULK_TRANSFER == (ptr[3] & 0x03))
        {
            if (USBC_USB_SPEED_USB20 == pUsbCore->speed)
            {
                ptr[4] = USBC_USB11_MAX_PACKET_SIZE & 0x00FF;
                ptr[5] = (USBC_USB11_MAX_PACKET_SIZE >> 8) & 0x07;
            }
            else if(USBC_USB_SPEED_USB11 == pUsbCore->speed)
            {
                ptr[4] = USBC_USB20_MAX_PACKET_SIZE & 0x00FF;
                ptr[5] = (USBC_USB20_MAX_PACKET_SIZE >> 8) & 0x07;
            }
        }

        ptr += currLength;
        i += currLength;
    }

    return;
}

static void usbc_core_handle_get_descriptor()
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    usbc_control_request_type_e type = USBC_CONTROL_REQUEST_TYPE_STALL;
    kal_uint8 bRecip = pUsbCore->setup_packet.bmRequestType & USBC_REQUEST_RECIP_MASK;
    //kal_uint16 wIndex = pUsbCore->setup_packet.wIndex;
    kal_uint16 wValue = pUsbCore->setup_packet.wValue;
    kal_uint16 wLength = pUsbCore->setup_packet.wLength;
    kal_uint8* pBuffer = NULL;
    kal_uint32 length = 0;

    usbc_trace_info(USBCORE_GET_DESCRIPTOR, bRecip, (wValue >> 8));

    if ( bRecip == USBC_REQUEST_RECIP_DEVICE )
    {
        kal_uint8 bDscrType = wValue >> 8;

        switch ( bDscrType )
        {
            case USBC_DT_DEVICE:
            {
                usbc_core_printf("=========>usbcore_handle_get_descriptor: Device\r\n");
                /* Device Descriptor Type */
                if ( USBC_GET_DESC_LENGTH(pUsbCore->descriptors.device) > wLength )
                {
                    length = wLength;
                } else {
                    length = USBC_GET_DESC_LENGTH(pUsbCore->descriptors.device);
                }
                pBuffer = pUsbCore->descriptors.device;
                type = USBC_CONTROL_REQUEST_TYPE_SEND;
                break;
            }
            case USBC_DT_CONFIG:
            {
                kal_uint8 config_idx = wValue & 0xff; /* configuration index */

                usbc_core_printf("=========>usbcore_handle_get_descriptor: Configuration\r\n");
                /* Configuration Descriptor Type */
                if ( USBC_GET_CONF_TOTAL_LENGTH(pUsbCore->descriptors.configuration[config_idx]) > wLength )
                {
                    length = wLength;
                } else {
                    length = USBC_GET_CONF_TOTAL_LENGTH(pUsbCore->descriptors.configuration[config_idx]);
                }
                pBuffer = pUsbCore->descriptors.configuration[config_idx];
                type = USBC_CONTROL_REQUEST_TYPE_SEND;
                break;
            }
            case USBC_DT_DEVICE_QUALIFIER:
            {
                usbc_core_printf("=========>usbcore_handle_get_descriptor: Qualifier\r\n");

                if ( USBC_USB_SPEED_USB30 == pUsbCore->speed ) {
                    type = USBC_CONTROL_REQUEST_TYPE_STALL;
                    break;
                }

                /* Device Qualifier Type */
                if ( pUsbCore->device_qualifier_descriptor.bLength > wLength )
                {
                    length = wLength;
                } else {
                    length = pUsbCore->device_qualifier_descriptor.bLength;
                }
                pBuffer = (kal_uint8*)&pUsbCore->device_qualifier_descriptor;
                type = USBC_CONTROL_REQUEST_TYPE_SEND;
                break;
            }
            case USBC_DT_STRING:
            {
                kal_uint8 bStrIdx = wValue & 0xff; /* String Type */

                usbc_core_printf("=========>usbcore_handle_get_descriptor: String\r\n");

                if (bStrIdx == USBC_MS_OS_STRING_INDEX)
                {   /* MOD string descriptor */
                    if ( !pUsbCore->morphing_enable || pUsbCore->state == USBC_USB_STATE_ATTACHED ) 
                    {
                        pBuffer = NULL;
                        length = 0;
                        type = USBC_CONTROL_REQUEST_TYPE_STALL;
                        break;
                    }
                    usbc_os_string_desc.bLength = USBC_MAX_OS_STRING_LENGTH;
                    usbc_os_string_desc.bDescriptorType = USBC_DT_STRING;
                    kal_mem_cpy(usbc_os_string_desc.qwSignature, (kal_uint8*)usbc_os_string, 14);
                    usbc_os_string_desc.bMS_VendorCode = USBC_REQ_GET_MS_DESCRIPTOR;
                    usbc_os_string_desc.bPad = 0x00;

					if (USBC_MAX_OS_STRING_LENGTH > wLength) {
						length = wLength;
					} else {
						length = USBC_MAX_OS_STRING_LENGTH;
					}
					pBuffer = (kal_uint8*)&usbc_os_string_desc;
					type = USBC_CONTROL_REQUEST_TYPE_SEND;
                } else
                {
                    if (bStrIdx < pUsbCore->resource_string_number && pUsbCore->string_descriptor[bStrIdx] != NULL)
                    {
                        if (pUsbCore->string_descriptor[bStrIdx]->bLength > wLength) {
                            length = wLength;
                        } else {
                            length = pUsbCore->string_descriptor[bStrIdx]->bLength;
                        }
                        pBuffer = (kal_uint8*)pUsbCore->string_descriptor[bStrIdx];
                        type = USBC_CONTROL_REQUEST_TYPE_SEND;
                    } else
                    {
                        pBuffer = NULL;
                        length = 0;
                        type = USBC_CONTROL_REQUEST_TYPE_STALL;
                    }
                }
                break;
            }
            case USBC_DT_BOS:
            {
                usbc_core_printf("=========>usbcore_handle_get_descriptor: BOS\r\n");

                /*if ( USBC_USB_SPEED_USB30 != pUsbCore->speed ) {
                    type = USBC_CONTROL_REQUEST_TYPE_STALL;
                    break;
                }*/

                /* Binary Device Object Store (BOS) Type */
                pBuffer = usbc_bos_s;
                if ( USBC_GET_BOS_TOTAL_LENGTH(pBuffer) > wLength ) {
                    length = wLength;
                } else {
                    length = USBC_GET_BOS_TOTAL_LENGTH(pBuffer);
                }
                type = USBC_CONTROL_REQUEST_TYPE_SEND;
                break;
            }
            case USBC_DT_OTHER_SPEED:
            {
                kal_uint8 config_idx = wValue & 0xff; /* configuration index */

                usbc_core_printf("=========>usbcore_handle_get_descriptor: Other_Speed_Configuration\r\n");
                /* Configuration Descriptor Type */

                if ( USBC_USB_SPEED_USB30 == pUsbCore->speed ) {
                    type = USBC_CONTROL_REQUEST_TYPE_STALL;
                    break;
                }

                if ( USBC_GET_CONF_TOTAL_LENGTH(pUsbCore->descriptors.configuration[config_idx]) > wLength )
                {
                    length = wLength;
                } 
                else 
                {
                    length = USBC_GET_CONF_TOTAL_LENGTH(pUsbCore->descriptors.configuration[config_idx]);
                }

                // struct other speed configuration
                usbc_core_update_dt_other_speed(pOtherSpeedDescript, config_idx);

                pBuffer = pOtherSpeedDescript;
                type = USBC_CONTROL_REQUEST_TYPE_SEND;
                break;
            }
            default:
            {
                pBuffer = NULL;
                length = 0;
                type = USBC_CONTROL_REQUEST_TYPE_STALL;
                break;
            }
        }
    } else {
        pBuffer = NULL;
        length = 0;
        type = USBC_CONTROL_REQUEST_TYPE_STALL;
    }

    usbc_core_set_control_request(pBuffer, length, type);
}


static void usbc_core_handle_set_configuration()
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint16 wValue = pUsbCore->setup_packet.wValue;
    usbc_ind_t ind_to_enqueue;

    usbc_core_printf("=========>usbcore_handle_set_configuration\r\n");
    usbc_trace_info(USBCORE_SET_CONFIG, wValue & 0xff);

    if (USBC_IS_IN_EXCEPTION_MODE()) {
        usbc_core_set_usb_configuration(wValue & 0xff);
        usbc_core_set_control_request(NULL, 0, USBC_CONTROL_REQUEST_TYPE_RECEIVE);
    } else {
        ind_to_enqueue.type = USBC_IND_SET_CONFIG;
        ind_to_enqueue.ext = 0;
        ind_to_enqueue.data = (kal_uint8)(wValue & 0xff);
        usbc_enqueue_ind(&ind_to_enqueue);	
        hmu_hifeg_set(HIF_DRV_EG_USBC_IND_EVENT);
    }
}


static void usbc_core_handle_get_configuration()
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8* pBuffer = pUsbCore->control_request_buffer;
    kal_uint32 length = 0;

    usbc_core_printf("=========>usbcore_handle_get_configuration\r\n");
    usbc_trace_info(USBCORE_GET_CONFIG, pUsbCore->usb_configuration);

    pBuffer[0] = pUsbCore->usb_configuration;
    length = 1;

    usbc_core_set_control_request(pBuffer, length, USBC_CONTROL_REQUEST_TYPE_SEND);
}


static void usbc_core_handle_set_interface()
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    usbc_control_request_type_e type = USBC_CONTROL_REQUEST_TYPE_STALL;
    kal_uint8 bInterface = pUsbCore->setup_packet.wIndex & 0xff;
    kal_uint16 wValue = pUsbCore->setup_packet.wValue;
    kal_uint8 i;

    usbc_core_printf("=========>usbcore_handle_set_interface\r\n");
    usbc_trace_info(USBCORE_SET_INFX, bInterface, wValue);

    do {
        for ( i=0; i<pUsbCore->total_class_interfaces; i++ )
        {
            if ( (pUsbCore->class_interface[i].interface_no == bInterface) &&
                 (pUsbCore->class_interface[i].state == USBC_CORE_CLASS_INTERFACE_STATE_ACTIVE) )
            {
                break;
            }
        }

        if ( i == pUsbCore->total_class_interfaces )
        {
            type = USBC_CONTROL_REQUEST_TYPE_STALL;
            break;
        }

        pUsbCore->class_interface[i].alternate_setting = wValue & 0xff;
        
        if ( pUsbCore->class_interface[i].notify_alternate_setting != NULL ) 
        {
            //type = USBC_CONTROL_REQUEST_TYPE_RECEIVE;
            usbc_core_indicate_alternate_setting(i, pUsbCore->class_interface[i].alternate_setting);
            return;
        }
        else
        {
            type = USBC_CONTROL_REQUEST_TYPE_STALL;
        }
    } while (0);

    usbc_core_set_control_request(NULL, 0, type);

}


static void usbc_core_handle_get_interface()
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    usbc_control_request_type_e type = USBC_CONTROL_REQUEST_TYPE_STALL;
    kal_uint8 bInterface = pUsbCore->setup_packet.wIndex & 0xff;
    //kal_uint16 wValue = pUsbCore->setup_packet.wValue;
    kal_uint8* pBuffer = pUsbCore->control_request_buffer;
    kal_uint32 length = 0;
    kal_uint8 i;

    usbc_core_printf("=========>usbcore_handle_get_interface\r\n");
    usbc_trace_info(USBCORE_GET_INFX, bInterface);

    do {
        for ( i=0; i<pUsbCore->total_class_interfaces; i++ )
        {
            if ( (pUsbCore->class_interface[i].interface_no == bInterface) &&
                 (pUsbCore->class_interface[i].state == USBC_CORE_CLASS_INTERFACE_STATE_ACTIVE) )
            {
                break;
            }
        }

        if ( i == pUsbCore->total_class_interfaces )
        {
            type = USBC_CONTROL_REQUEST_TYPE_STALL;
            length = 0;
            break;
        }

        pBuffer[0] = pUsbCore->class_interface[i].alternate_setting;
        length = 1;
        type = USBC_CONTROL_REQUEST_TYPE_SEND;

    } while (0);

    usbc_core_set_control_request(pBuffer, length, type);
}

static void usbc_core_handle_set_sel()
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8* pBuffer = pUsbCore->control_request_buffer;
    kal_uint32 length = 6;

    usbc_core_printf("=========>usbcore_handle_set_sel\r\n");
    // TODO: set exit latency value if support, do nothing currently
    usbc_core_set_control_request(pBuffer, length, USBC_CONTROL_REQUEST_TYPE_RECEIVE);
}

static void usbc_core_handle_set_isochro_delay()
{
    usbc_core_printf("=========>usbcore_handle_isochro_delay\r\n");
    // TODO: set isochronous delay value if support, do nothing currently
    usbc_core_set_control_request(NULL, 0, USBC_CONTROL_REQUEST_TYPE_RECEIVE);
}

static void usbc_core_device_descriptor_speed_change(usbc_device_descriptor_t *desc, usbc_usb_speed_e speed)
{
    switch (speed) {
        case USBC_USB_SPEED_USB30:
            desc->bcdUSB = 0x0300;
            desc->bMaxPacketSize0 = USBC_USB30_EP0_PACKET_SIZE;
            break;
    
        default:
#ifdef __MTK_TARGET__
	    desc->bcdUSB = 0x0210;
#else
	    desc->bcdUSB = 0x0200;
#endif
            desc->bMaxPacketSize0 = 64;
            break;
    }
}

static void usbc_core_compile_ep_companion(kal_uint8 *dst_desc, kal_uint8 transfer_type)
{
    USBC_SET_DESC_LENGTH(dst_desc, USBC_ENDPOINT_COMPANION_DESC_SIZE);
    USBC_SET_DESC_TYPE(dst_desc, USBC_DT_ENDPOINT_COMPANION);
    USBC_SET_EPC_ATTRIBUTES(dst_desc, 0);

    if (USBC_BULK_TRANSFER == transfer_type) {
        USBC_SET_EPC_MAX_BURST(dst_desc, 1);
        USBC_SET_EPC_BYTES_PER_INTERVAL(dst_desc, 0);
    } else {
        USBC_SET_EPC_MAX_BURST(dst_desc, 0);
        USBC_SET_EPC_BYTES_PER_INTERVAL(dst_desc, 0x40);
    }
}

static void usbc_core_configuration_speed_change(usbc_core_t *pUsbCore, usbc_usb_speed_e speed)
{
    kal_uint32 total_len;
    kal_uint32 bytes_read;
    kal_uint32 bytes_written;
    kal_uint8 *desc_read;
    kal_uint8 *desc_to_write;
    kal_uint32 desc_len;
    kal_uint32 idx_cfg;
    kal_uint32 idx_ep;
    kal_uint8  conf[USBC_MAX_CONF_SIZE];

    for (idx_cfg = 0; idx_cfg < pUsbCore->dev_param->mode_param[pUsbCore->mode].cfg_num; idx_cfg++)
    {
        kal_mem_cpy(conf, pUsbCore->descriptors.configuration[idx_cfg], USBC_MAX_CONF_SIZE);
        bytes_read = 0;
        bytes_written = 0;
        total_len = USBC_GET_CONF_TOTAL_LENGTH(conf);

        while (bytes_read < total_len)
        {
            desc_read = conf + bytes_read;
            desc_to_write = pUsbCore->descriptors.configuration[idx_cfg] + bytes_written;
            desc_len = USBC_GET_DESC_LENGTH(desc_read);

            kal_mem_cpy(desc_to_write, desc_read, desc_len);
            bytes_written += desc_len;

            switch (USBC_GET_DESC_TYPE(desc_read))
            {
                case USBC_DT_ENDPOINT:
                {
                    if (USBC_BULK_TRANSFER == USBC_GET_EP_TRANSFER_TYPE(desc_to_write))
                    {
                        switch (speed) {
                            case USBC_USB_SPEED_USB11:
                            {
                                USBC_SET_EP_MAX_PACKET_SIZE(desc_to_write, USBC_USB11_MAX_PACKET_SIZE);
                                break;
                            }
                            case USBC_USB_SPEED_USB20:
                            {
                                USBC_SET_EP_MAX_PACKET_SIZE(desc_to_write, USBC_USB20_MAX_PACKET_SIZE);
                                break;
                            }
                            case USBC_USB_SPEED_USB30:
                            {
                                USBC_SET_EP_MAX_PACKET_SIZE(desc_to_write, USBC_USB30_MAX_PACKET_SIZE);
                                break;
                            }
                            default:
                            {
                                ASSERT(0);
                                break;
                            }
                        }
                    }
                    if (speed == USBC_USB_SPEED_USB30) {
                        if (bytes_written + USBC_ENDPOINT_COMPANION_DESC_SIZE <= USBC_MAX_CONF_SIZE) {
                            usbc_core_compile_ep_companion(desc_to_write + desc_len, USBC_GET_EP_TRANSFER_TYPE(desc_to_write));
                            bytes_written += USBC_ENDPOINT_COMPANION_DESC_SIZE;
                        } else {
                            ASSERT(0);
                        }
                    }
                    break;
                }
                   
                default:
                   break;
            }
            bytes_read += desc_len;
        }

        /*
         * Patch configuration descriptor.
         */
        ASSERT(bytes_written <= USBC_MAX_CONF_SIZE);
        if (speed == USBC_USB_SPEED_USB30) {
            USBC_SET_CONF_MAX_POWER(pUsbCore->descriptors.configuration[idx_cfg], pUsbCore->u3ConfMaxPower);
        }
        USBC_SET_CONF_TOTAL_LENGTH(pUsbCore->descriptors.configuration[idx_cfg], bytes_written);

        /*
         * Modify max packet size in tx/rx endpoint queue info
         */
        for (idx_ep = 0; idx_ep < pUsbCore->resource_ep_tx_number[idx_cfg]; idx_ep ++)
        {
            if (pUsbCore->ep_tx_info[idx_cfg][idx_ep].queue_info.xfer_type == HIFUSB_EP_XFER_TYPE_BULK)
            {
                switch (speed) {
                    case USBC_USB_SPEED_USB11:
                    {
                        pUsbCore->ep_tx_info[idx_cfg][idx_ep].queue_info.max_packet_size = USBC_USB11_MAX_PACKET_SIZE;
                        break;
                    }
                    case USBC_USB_SPEED_USB20:
                    {
                        pUsbCore->ep_tx_info[idx_cfg][idx_ep].queue_info.max_packet_size = USBC_USB20_MAX_PACKET_SIZE;
                        break;
                    }
                    case USBC_USB_SPEED_USB30:
                    {
                        pUsbCore->ep_tx_info[idx_cfg][idx_ep].queue_info.max_packet_size = USBC_USB30_MAX_PACKET_SIZE;
                        break;
                    }
                    default:
                    {
                        ASSERT(0);
                        break;
                    }
                }
            }
        }
        for (idx_ep = 0; idx_ep < pUsbCore->resource_ep_rx_number[idx_cfg]; idx_ep ++)
        {
            if (pUsbCore->ep_rx_info[idx_cfg][idx_ep].queue_info.xfer_type == HIFUSB_EP_XFER_TYPE_BULK)
            {
                switch (speed) {
                    case USBC_USB_SPEED_USB11:
                    {
                        pUsbCore->ep_rx_info[idx_cfg][idx_ep].queue_info.max_packet_size = USBC_USB11_MAX_PACKET_SIZE;
                        break;
                    }
                    case USBC_USB_SPEED_USB20:
                    {
                        pUsbCore->ep_rx_info[idx_cfg][idx_ep].queue_info.max_packet_size = USBC_USB20_MAX_PACKET_SIZE;
                        break;
                    }
                    case USBC_USB_SPEED_USB30:
                    {
                        pUsbCore->ep_rx_info[idx_cfg][idx_ep].queue_info.max_packet_size = USBC_USB30_MAX_PACKET_SIZE;
                        break;
                    }
                    default:
                    {
                        ASSERT(0);
                        break;
                    }
                }
            }
        }
    }
}

kal_bool usbc_core_handle_standard_request()
{
    static struct _usbc_request_entry {
        kal_uint32          request;
        void                (*request_handler)();
    } request_entry_table[] = {
        {USBC_REQ_SET_ADDRESS,              usbc_core_handle_set_address},
        {USBC_REQ_GET_STATUS,               usbc_core_handle_get_status},
        {USBC_REQ_SET_FEATURE,              usbc_core_handle_set_feature},
        {USBC_REQ_CLEAR_FEATURE,            usbc_core_handle_clear_feature},
        {USBC_REQ_GET_DESCRIPTOR,           usbc_core_handle_get_descriptor},
        {USBC_REQ_SET_CONFIGURATION,        usbc_core_handle_set_configuration},
        {USBC_REQ_GET_CONFIGURATION,        usbc_core_handle_get_configuration},
        {USBC_REQ_SET_INTERFACE,            usbc_core_handle_set_interface},
        {USBC_REQ_GET_INTERFACE,            usbc_core_handle_get_interface},
        {USBC_REQ_SET_SEL,                  usbc_core_handle_set_sel},
        {USBC_REQ_SET_ISOCHRONOUS_DELAY,    usbc_core_handle_set_isochro_delay},
    };

    kal_uint32      request_entry_table_num = sizeof(request_entry_table)/sizeof(struct _usbc_request_entry);
    usbc_core_t    *pUsbCore = usbc_core_get_instance();
    kal_uint32      idx = 0;
    kal_bool        handled = KAL_TRUE;

    for (idx = 0; idx < request_entry_table_num; idx++) {
        if (pUsbCore->setup_packet.bRequest == request_entry_table[idx].request) break;
    }

    if (idx < request_entry_table_num) {
        request_entry_table[idx].request_handler();
        /* Because set_config procedure needs to execute reinit usb class handler which can't be run in HISR,
           therefore we pend this request and move to USBCore Task */
        if (request_entry_table[idx].request == USBC_REQ_SET_CONFIGURATION) {
            if (!USBC_IS_IN_EXCEPTION_MODE()) {
                pUsbCore->setup_indicated = KAL_TRUE; // set control request in task
                handled = KAL_FALSE;
            }
        }
        else if ( ((request_entry_table[idx].request == USBC_REQ_SET_FEATURE) || (request_entry_table[idx].request == USBC_REQ_CLEAR_FEATURE)) &&
                  (pUsbCore->speed == USBC_USB_SPEED_USB30))
        {
            kal_uint8 bRecip = pUsbCore->setup_packet.bmRequestType & USBC_REQUEST_RECIP_MASK;

            if  ( bRecip == USBC_REQUEST_RECIP_INTERFACE &&
                  !USBC_IS_IN_EXCEPTION_MODE() )
            {
                pUsbCore->setup_indicated = KAL_TRUE; // set control request in task
                handled = KAL_FALSE;
            }
        }
        else if (request_entry_table[idx].request == USBC_REQ_SET_INTERFACE)
        {
            usbc_core_t* pUsbCore = usbc_core_get_instance();
            kal_uint8 bInterface = pUsbCore->setup_packet.wIndex & 0xff;
            kal_uint8 i;

            for ( i=0; i<pUsbCore->total_class_interfaces; i++ )
            {
                if ( (pUsbCore->class_interface[i].interface_no == bInterface) &&
                     (pUsbCore->class_interface[i].state == USBC_CORE_CLASS_INTERFACE_STATE_ACTIVE) )
                {
                    if ( pUsbCore->class_interface[i].notify_alternate_setting != NULL )
                    {
                        pUsbCore->setup_indicated = KAL_TRUE; // set control request in task
                        handled = KAL_FALSE;
                    }
                    break;
                }
            }
        }
    } else {
        usbc_core_set_control_request(NULL, 0, HIFUSB_CONTROL_REQUEST_TYPE_STALL);
    }

    return handled;
}


void usbc_core_descriptors_speed_change(usbc_core_t *pUsbCore, usbc_usb_speed_e speed)
{
    usbc_core_device_descriptor_speed_change(
            (usbc_device_descriptor_t *)pUsbCore->descriptors.device, 
            speed);

    usbc_core_configuration_speed_change(pUsbCore, speed);
}

