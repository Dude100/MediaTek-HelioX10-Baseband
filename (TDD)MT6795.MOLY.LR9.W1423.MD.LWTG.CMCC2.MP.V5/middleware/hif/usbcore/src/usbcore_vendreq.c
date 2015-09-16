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


#define MIN(_a, _b) (((_a) <= (_b)) ? (_a) : (_b))

/*
 *  Define Microsoft OS feature descriptor
 */
#define USBC_FEATURE_EXT_COMPAT_ID          0x0004
#define USBC_MAX_OS_FEATURE_DESC_LENGTH     40
static usbc_ext_compat_id_os_feature_descriptor_t usbc_os_descriptor =
{
    USBC_MAX_OS_FEATURE_DESC_LENGTH,                     /* dwLength */
    0x0100,                                              /* bcdVersion */
    USBC_FEATURE_EXT_COMPAT_ID,                          /* wIndex */
    0x01,                                                /* bCount */
    {0,0,0,0,0,0,0},                                     /* bPads_1 */
    0x00,                                                /* bFirstInterfaceNumber */
    0x01,                                                /* bInterfaceCount */
    {0x41, 0x4C, 0x54, 0x52, 0x43, 0x46, 0x47, 0x00},    /* compatibleID (ALTRCFG) */
    {0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},    /* subcompatibleID (default:2) */
    {0,0,0,0,0,0}                                        /* bPads_2 */
};

static void usbc_core_handle_get_ms_descriptor()
{
    usbc_core_t* pUsbCore = usbc_core_get_instance();
    kal_uint8 bRecip = pUsbCore->setup_packet.bmRequestType & USBC_REQUEST_RECIP_MASK;
    kal_uint16 wValue = pUsbCore->setup_packet.wValue;
    kal_uint16 wIndex = pUsbCore->setup_packet.wIndex;
    kal_uint16 wLength = pUsbCore->setup_packet.wLength;
    kal_uint8* pBuffer = NULL;
    kal_uint32 length = 0;

	if ( bRecip == USBC_REQUEST_RECIP_DEVICE && 
         pUsbCore->morphing_enable   )
	{
	    if (wValue == 0x00 && wIndex == USBC_FEATURE_EXT_COMPAT_ID)
	    {
	        /* Morphing device must not report the compatible and subcompatible ID after a configuration is selected */
	        if (pUsbCore->state == USBC_USB_STATE_ATTACHED) {
	            usbc_core_set_control_request(NULL, 0, HIFUSB_CONTROL_REQUEST_TYPE_STALL);
	            return;
	        }
	        pUsbCore->morph_active = KAL_TRUE;
            if (pUsbCore->dev_param->morphing_sub_id >= 2 && pUsbCore->dev_param->morphing_sub_id <= 4)
            {   /*
                 *  0x32 -> '2',   0x33 -> '3',   0x34 -> '4'
                 */
                usbc_os_descriptor.subcompatibleID[0] = 0x30 + pUsbCore->dev_param->morphing_sub_id;
            }

            length = MIN(USBC_MAX_OS_FEATURE_DESC_LENGTH, wLength);
            pBuffer = (kal_uint8*)&usbc_os_descriptor;   
	        usbc_core_set_control_request(pBuffer, length, USBC_CONTROL_REQUEST_TYPE_SEND);
	    }
	} else
	{
	    usbc_core_set_control_request(NULL, 0, HIFUSB_CONTROL_REQUEST_TYPE_STALL);
	}
}

void usbc_core_handle_vendor_request()
{
    static struct _usbc_request_entry {
        kal_uint32          request;
        void                (*request_handler)();
    } request_entry_table[] = {
        {USBC_REQ_GET_MS_DESCRIPTOR,    usbc_core_handle_get_ms_descriptor},
    };

    kal_uint32      request_entry_table_num = sizeof(request_entry_table)/sizeof(struct _usbc_request_entry);
    usbc_core_t    *pUsbCore = usbc_core_get_instance();
    kal_uint32      idx;
    kal_uint8       bInterface;

    for (idx = 0; idx < request_entry_table_num; idx++) {
        if (pUsbCore->setup_packet.bRequest == request_entry_table[idx].request) break;
    }

    if (idx < request_entry_table_num)
    {
        request_entry_table[idx].request_handler();
    } else
    {   /* If request handler can't be found, search all interface and notify class driver if existed */
        if ((pUsbCore->setup_packet.bmRequestType & USBC_REQUEST_RECIP_MASK) == USBC_REQUEST_RECIP_INTERFACE)
        {
            kal_uint8 i;
            bInterface = pUsbCore->setup_packet.wIndex & 0xff;
            
            /* notify class driver by interface if exist */
            for ( i=0 ; i< pUsbCore->total_class_interfaces; i++ ) {
                if ( (pUsbCore->class_interface[i].interface_no == bInterface) &&
                    (pUsbCore->class_interface[i].state == USBC_CORE_CLASS_INTERFACE_STATE_ACTIVE) &&
                    (pUsbCore->class_interface[i].notify_control_setup_packet != NULL)) {
                    break;
                }
            }
            
            if ( i == pUsbCore->total_class_interfaces ) {
                /* incorrect request */
                usbc_core_set_control_request(NULL, 0, HIFUSB_CONTROL_REQUEST_TYPE_STALL);
            } else {
                usbc_core_indicate_control_setup_packet(i, &pUsbCore->setup_packet);
            }
        } else
        {   // not support
            usbc_core_set_control_request(NULL, 0, HIFUSB_CONTROL_REQUEST_TYPE_STALL);
        }
    }
}


