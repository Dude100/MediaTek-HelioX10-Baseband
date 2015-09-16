/*!
 *  @file usbcore_resource.c
 *  @author HaoRen Kao
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
 *  This file provides usb resource management function
 */

#include <stdlib.h>
#include "usbcore_main.h"

void
usbc_resource_reset(void)
{
    usbc_core_t* usbc_inst = usbc_core_get_instance();
    kal_uint8 idx;

    for (idx = 0; idx < MAX_USBCORE_CONFIG_NUM; idx++)
    {
         usbc_inst->resource_interface_number[idx] = 0;
         usbc_inst->resource_iad_number[idx] = 0;
         usbc_inst->resource_ep_tx_number[idx] = 0;
         usbc_inst->resource_ep_rx_number[idx] = 0;
    }
    usbc_inst->resource_string_number = 0;
}

usbc_interface_info_t*
usbc_get_interface_number(kal_uint8 config_num, kal_uint8 *if_num_p)
{
    usbc_core_t* usbc_inst = usbc_core_get_instance();

    ASSERT(config_num < MAX_USBCORE_CONFIG_NUM);
    ASSERT(usbc_inst->resource_interface_number[config_num] < MAX_USBCORE_INTERFACE_NUM);

    usbc_inst->resource_interface_number[config_num]++;
    if (if_num_p) {
        *if_num_p = usbc_inst->resource_interface_number[config_num] - 1;
    }
    return (&usbc_inst->if_info[config_num][usbc_inst->resource_interface_number[config_num] - 1]);
}

kal_uint8
usbc_get_string_number(void *string)
{
    usbc_core_t* usbc_inst = usbc_core_get_instance();
    usbc_string_descriptor_t* string_dscr;

    ASSERT(string);
    ASSERT(usbc_inst->resource_string_number < MAX_USBCORE_STRING_DESCRIPTOR_NUM);

	string_dscr = (usbc_string_descriptor_t*)string;

    usbc_inst->resource_string_number++;
    usbc_inst->string_descriptor[usbc_inst->resource_string_number - 1] = string_dscr;
    return (usbc_inst->resource_string_number - 1);
}

usbc_interface_association_descriptor_t*
usbc_get_iad_number(kal_uint8 config_num, kal_uint8 *iad_num_p)
{
    usbc_core_t* usbc_inst = usbc_core_get_instance();

    ASSERT(config_num < MAX_USBCORE_CONFIG_NUM);
    ASSERT(usbc_inst->resource_iad_number[config_num] < MAX_USBCORE_IAD_NUM);

    usbc_inst->resource_iad_number[config_num]++;
    if (iad_num_p) {
        *iad_num_p = usbc_inst->resource_iad_number[config_num] - 1;
    }
    return (&usbc_inst->iad_descriptor[config_num][usbc_inst->resource_iad_number[config_num] - 1]);
}

usbc_endpoint_info_t*
usbc_get_endpoint_tx_number(kal_uint8 config_num, kal_uint8 *tx_ep_num_p)
{
    usbc_core_t* usbc_inst = usbc_core_get_instance();

    ASSERT(config_num < MAX_USBCORE_CONFIG_NUM);
    ASSERT(usbc_inst->resource_ep_tx_number[config_num] < MAX_USBCORE_QUEUE_NUM);

    usbc_inst->resource_ep_tx_number[config_num]++;
    if (tx_ep_num_p) {
        *tx_ep_num_p = usbc_inst->resource_ep_tx_number[config_num];
    }
    return (&usbc_inst->ep_tx_info[config_num][usbc_inst->resource_ep_tx_number[config_num] - 1]);
}

usbc_endpoint_info_t*
usbc_get_endpoint_rx_number(kal_uint8 config_num, kal_uint8 *rx_ep_num_p)
{
    usbc_core_t* usbc_inst = usbc_core_get_instance();

    ASSERT(config_num < MAX_USBCORE_CONFIG_NUM);
    ASSERT(usbc_inst->resource_ep_rx_number[config_num] < MAX_USBCORE_QUEUE_NUM);

    usbc_inst->resource_ep_rx_number[config_num]++;
    if (rx_ep_num_p) {
        *rx_ep_num_p = usbc_inst->resource_ep_rx_number[config_num];
    }
    return (&usbc_inst->ep_rx_info[config_num][usbc_inst->resource_ep_rx_number[config_num] - 1]);
}


