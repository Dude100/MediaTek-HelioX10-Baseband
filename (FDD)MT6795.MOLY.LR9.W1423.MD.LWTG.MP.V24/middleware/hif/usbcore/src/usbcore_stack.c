/*!
 *  @file usbcore_stack.c
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
 *  This file provides interactive functions of usbcore and HMU
 */

#include "kal_public_api.h"
#include "syscomp_config.h"
#include "usbcore_common.h"
#include "usbcore_main.h"
#include "usbcore_hif.h"
#include "usbc_custom.h"
#include "usbcore_debug.h"
#ifdef __MULTI_BOOT__
#include "multiboot_config.h"
#endif /* __MULTI_BOOT__ */


extern kal_uint8 custom_em_get_usb_cdrom_config(void);
extern kal_uint16 INT_BootMode(void);

/*------------------------------------------------------------------------------
 * USB stack initialization.
 *----------------------------------------------------------------------------*/
/*
 * USB stack configuration.
 */

/*
 * Bitmap of check-in nodes.
 */
static kal_uint32 usbc_stack_nodes_s = 0;

/*
 * Node registration information.
 *    0 ~ (USB_FUNC_NUM-1) : USB function node
 *    USB_FUNC_NUM         : USB Core node
 */
#define USBC_NODE_COUNT       USB_CLASS_NUM+1
static usbc_node_reg_entry_t *usbc_stack_nodes_reg_table_s[USBC_NODE_COUNT];

/*
 * USB stack helper routines.
 */
#define _NODE_TO_BIT(_node) \
    ( (kal_uint32)1 << (kal_uint32)(_node) )

#define _GET_NODE_VALUE() \
    usbc_stack_nodes_s

#define _SET_NODE_VALUE(_val) \
    usbc_stack_nodes_s = (_val)

#define _GET_NODE_REG_TABLE(_node) \
    usbc_stack_nodes_reg_table_s[(_node)]

#define _SET_NODE_REG_TABLE(_node, _reg_table) \
    usbc_stack_nodes_reg_table_s[(_node)] = (_reg_table)

#define _CHECKIN_NODE(_node, _reg_table) \
    (usbc_stack_nodes_s) |= _NODE_TO_BIT(_node); \
    _SET_NODE_REG_TABLE(_node, _reg_table)

#define _ALL_NODES_CHECKIN() \
    ( (usbc_stack_nodes_s) == (_NODE_TO_BIT(USBC_NODE_COUNT) - 1) )


#define INDEX_TO_CFG(index)   (index+1)

/*
 * USB language string
 */
static const kal_uint16 usb_language_string[] = 
{
    0x0304,
    0x0409
};

/*
 * Default device descriptor
 */
static usbc_device_descriptor_t usbc_default_device_descriptor =
{
    /* Device Descriptor */
    0x12,                           /* bLength              */
    USBC_DT_DEVICE,                 /* DEVICE               */
    0x0200,                         /* bcdUSB: USB 2.0      */
    0xEF,                           /* CLASS                */
    0x02,                           /* Subclass             */
    0x01,                           /* Protocol             */
    0x40,                           /* bMaxPktSize0         */
    0x0E8D,                         /* idVendor             */
    0x1234,                         /* idProduct            */
    0x0001,                         /* bcdDevice            */
    0x00,                           /* iManufacturer        */
    0x00,                           /* iProduct             */
    0x00,                           /* iSerial Number       */
    0x01                            /* One configuration    */
};

/*
 * Default configuration descriptor
 */
static usbc_configuration_descriptor_t usbc_default_configuration_descriptor =
{
    0x09,                       /* bLength              */
    0x02,                       /* CONFIGURATION        */
    0x0000,                     /* length               */
    0x00,                       /* bNumInterfaces       */
    0x00,                       /* bConfigurationValue  */
    0x00,                       /* iConfiguration       */
    0x80,                       /* bmAttributes (required + self-powered) */
    0xFA                        /* power                */
};

void usbc_stack_reset()
{
    usbc_stack_nodes_s = 0;
    kal_mem_set(usbc_stack_nodes_reg_table_s, 0, sizeof(usbc_stack_nodes_reg_table_s));
}

static usbc_class_init_func_t _get_class_init_func(usb_class_type_e type)
{
    usbc_node_reg_entry_t  *curr_entry;

    curr_entry = _GET_NODE_REG_TABLE(type);

    if (curr_entry && curr_entry->init_func) {
        return (usbc_class_init_func_t)(curr_entry->init_func);
    } else {
        return NULL;
    }
}

static usbc_class_reinit_func_t _get_class_reinit_func(usb_class_type_e type)
{
    usbc_node_reg_entry_t  *curr_entry;

    curr_entry = _GET_NODE_REG_TABLE(type);

    if (curr_entry && curr_entry->reinit_func) {
        return (usbc_class_reinit_func_t)(curr_entry->reinit_func);
    } else {
        return NULL;
    }
}

usbc_class_set_config_func_t usbc_get_class_set_config_func(usb_class_type_e type)
{
    usbc_node_reg_entry_t  *curr_entry;

    curr_entry = _GET_NODE_REG_TABLE(type);

    if (curr_entry && curr_entry->set_config_func) {
        return (usbc_class_set_config_func_t)(curr_entry->set_config_func);
    } else {
        return NULL;
    }
}

static usbc_class_query_func_wk_capability_func_t usbc_get_class_query_func_wk_capability_func(usb_class_type_e type)
{
    usbc_node_reg_entry_t  *curr_entry;

    curr_entry = _GET_NODE_REG_TABLE(type);

    if (curr_entry && curr_entry->query_func_wk_capability)
    {
        return (usbc_class_query_func_wk_capability_func_t)(curr_entry->query_func_wk_capability);
    }
    else
    {
        return NULL;
    }
}
 
static void _usbc_construct_config_descriptor(usbc_core_t *usbc_p)
{
    kal_uint32    idx_cfg, idx_if, idx_ep, idx_iad, idx_class;
    kal_uint32    config_index;
    usb_cfg_param_t *cfg_param;
    kal_uint8     *conf;
    usbc_configuration_descriptor_t  *config_desc_p;
    usbc_class_query_func_wk_capability_func_t class_query;

    // check for valid USB mode
    if (usbc_p->mode >= USB_MODE_NUM)
    {
        ASSERT(0);
        return;
    }

    // assign bMaxPower for USB 3.0 configurations
    usbc_p->u3ConfMaxPower = (U3_CONF_BMAXPOWER / USBC_USB30_POWER_DESC_UINT);

    // construct configuration descriptors
    for (idx_cfg = 0; idx_cfg < usbc_p->dev_param->mode_param[usbc_p->mode].cfg_num; idx_cfg ++)
    {
        config_index = 0;
        conf = usbc_p->descriptors.configuration[idx_cfg];

        /* configuration descriptor */
        kal_mem_cpy(conf + config_index,
                       &usbc_default_configuration_descriptor,
                       USBC_CONFIGURATION_DESC_SIZE);
        config_index += USBC_CONFIGURATION_DESC_SIZE;

        /* interface/iad/endpoint descriptors */
        for (idx_if = 0; idx_if < usbc_p->resource_interface_number[idx_cfg]; idx_if ++)
        {
            /* IAD */
            for (idx_iad = 0; idx_iad < usbc_p->resource_iad_number[idx_cfg]; idx_iad ++) {
                if (idx_if == usbc_p->iad_descriptor[idx_cfg][idx_iad].bFirstInterface) {
                    break;
                }
            }
            if (idx_iad != usbc_p->resource_iad_number[idx_cfg])
            {  /* This interface is the first interface of the IAD */
                kal_mem_cpy(conf + config_index,
                               &usbc_p->iad_descriptor[idx_cfg][idx_iad],
                               sizeof(usbc_interface_association_descriptor_t));
                config_index += sizeof(usbc_interface_association_descriptor_t);
            }

            /* Interface */
            kal_mem_cpy(conf + config_index,
                           &usbc_p->if_info[idx_cfg][idx_if].ifdscr.stdif,
                           usbc_p->if_info[idx_cfg][idx_if].ifdscr_size);
            config_index += usbc_p->if_info[idx_cfg][idx_if].ifdscr_size;

            /* Endpoints */
            for (idx_ep = 0; idx_ep < usbc_p->if_info[idx_cfg][idx_if].ifdscr.stdif.bNumEndpoints; idx_ep ++)
            {
                kal_mem_cpy(conf + config_index,
                               &usbc_p->if_info[idx_cfg][idx_if].ep_info[idx_ep]->epdscr.stdep,
                               usbc_p->if_info[idx_cfg][idx_if].ep_info[idx_ep]->epdscr_size);
                config_index += usbc_p->if_info[idx_cfg][idx_if].ep_info[idx_ep]->epdscr_size;
            }

            /* alternate setting */
            if (usbc_p->if_info[idx_cfg][idx_if].altn_surpport)
            {
                kal_mem_cpy(conf + config_index,
                               &usbc_p->if_info[idx_cfg][idx_if].altn_if_info.ifdscr.stdif,
                               usbc_p->if_info[idx_cfg][idx_if].altn_if_info.ifdscr_size);
                config_index += usbc_p->if_info[idx_cfg][idx_if].altn_if_info.ifdscr_size;
                for (idx_ep = 0; idx_ep < usbc_p->if_info[idx_cfg][idx_if].altn_if_info.ifdscr.stdif.bNumEndpoints; idx_ep ++)
                {
                    kal_mem_cpy(conf + config_index,
                                   &usbc_p->if_info[idx_cfg][idx_if].altn_if_info.ep_info[idx_ep]->epdscr.stdep,
                                   usbc_p->if_info[idx_cfg][idx_if].altn_if_info.ep_info[idx_ep]->epdscr_size);
                    config_index += usbc_p->if_info[idx_cfg][idx_if].altn_if_info.ep_info[idx_ep]->epdscr_size;
                }
            }
        }

        ASSERT(config_index <= USBC_MAX_CONF_SIZE);

        /* Fill in some members of configuration descriptor */
        config_desc_p = (usbc_configuration_descriptor_t*)conf;
        config_desc_p->wTotalLength = config_index;
        config_desc_p->bNumInterfaces = usbc_p->resource_interface_number[idx_cfg];
        config_desc_p->bConfigurationValue = INDEX_TO_CFG(idx_cfg); // configuration value must start with 1

        // update remote wakeup attribute in configuration descriptor by qeuring each class in this config
        cfg_param = &usbc_p->dev_param->mode_param[usbc_p->mode].cfg_param[idx_cfg];
        for (idx_class = 0; idx_class < cfg_param->class_num; idx_class++)
        {
            class_query = usbc_get_class_query_func_wk_capability_func(cfg_param->class_type[idx_class]);
            if ( class_query &&
                 (class_query() & 0x0001) ) 
            {
                config_desc_p->bmAttributes |= 0x20;
                break;
            } 
        }
    }
    
}

/*
   usbcore:        usbc_stack_checkin(USB_CLASS_NUM, NULL);
   usbclass:   ex. usbc_stack_checkin(USB_CLASS_ACM1, XXX);
 */
void usbc_stack_checkin(usb_class_type_e class_type, usbc_node_reg_entry_t *reg_table)
{
    usbc_class_init_func_t  class_init;
    kal_uint32              idx_cfg, idx_class;
    kal_uint32              cfg_num;
    usb_cfg_param_t        *cfg_param;
    usbc_device_descriptor_t *dev_desc;
    usbc_device_qualifier_descriptor_t *dev_qual_desc;
    usbc_configuration_descriptor_t  *config_desc_p;
    usbc_core_t            *usbc_inst;

    _CHECKIN_NODE(class_type, reg_table);

    if (_ALL_NODES_CHECKIN())
    {
        usbc_trace_info(USBCORE_ALL_NODE_CHECKIN);

        usbc_inst = usbc_core_get_instance();

        /* 1. hif init */
        usbc_normal_hif_init();

        // Check for META mode
        #if defined(__MTK_TARGET__) && defined(__MULTI_BOOT__) && !defined(__ESL_COSIM_HIF__)
        if( INT_BootMode() == MTK_FACTORY_MODE )
        {
            usbc_inst->is_mode_meta = KAL_TRUE;
            usbc_inst->is_mode_meta_reused = usbc_normal_hif_is_meta_reused();
        }
        else
        #endif
        {
            usbc_inst->is_mode_meta = usbc_inst->is_mode_meta_reused = KAL_FALSE;
        }

        /* 2. Reset usbcore resources/structures */
        usbc_resource_reset();
        usbc_core_clear_register();
        usbc_core_clear_status();

        /*
           3. If Morphing is enabled, use WIN8 mode configuration
              If it is resulted from mode switch, use usbc_inst->mode
        */
        usbc_inst->dev_param = (usb_dev_param_t*)usb_get_custom_func()->get_device_param_func();

        if( !usbc_inst->is_mode_meta )
        {
        #if defined (BTT_STANDALONE_MODE)
            usbc_inst->mode = USB_MODE_BTT_STANDALONE;
        #elif defined(__ESL_COSIM_HIF__)
            usbc_inst->mode = USB_MODE_ESL;
        #else
            if (!usbc_inst->is_mode_switch) 
            {
                usbc_inst->morphing_enable = (custom_em_get_usb_cdrom_config() & 0x02)? KAL_TRUE:KAL_FALSE; // check for morphing enable

                if ( usbc_inst->morphing_enable ) 
                {
                    usbc_inst->mode = usbc_inst->dev_param->usb_mode[USB_OS_WIN8];
                } 
                else 
                {
                    if( (custom_em_get_usb_cdrom_config() & 0x01) == 0 )
                    {
                        usbc_inst->mode = USB_MODE_MSD_ONLY;
                    }
                    else 
                    {
                        usbc_inst->mode = USB_MODE_MT6290_DATACARD;
                    }
                }

            }
        #endif
        }
        else
        {
            // set USB enumeration to USB_MODE_META if it is in meta mode
            usbc_inst->mode = USB_MODE_META;
        }

        cfg_num = usbc_inst->dev_param->mode_param[usbc_inst->mode].cfg_num;

        /* 4. Set device_descriptor */
        dev_desc = (usbc_device_descriptor_t *)usbc_inst->descriptors.device;
        kal_mem_cpy(dev_desc, &usbc_default_device_descriptor, USBC_DEVICE_DESC_SIZE);
        dev_desc->bDeviceClass = usbc_inst->dev_param->mode_param[usbc_inst->mode].device_class;
        dev_desc->bDeviceSubClass = usbc_inst->dev_param->mode_param[usbc_inst->mode].device_sub_class;
        dev_desc->bDeviceProtocol = usbc_inst->dev_param->mode_param[usbc_inst->mode].device_protocol;
        dev_desc->idVendor = usbc_inst->dev_param->vendor_id;
        dev_desc->idProduct = usbc_inst->dev_param->mode_param[usbc_inst->mode].product_id;
        dev_desc->bcdDevice = usbc_inst->dev_param->bcd_device;
        dev_desc->bNumConfigurations = usbc_inst->dev_param->mode_param[usbc_inst->mode].cfg_num;

        dev_qual_desc = &usbc_inst->device_qualifier_descriptor;
        dev_qual_desc->bLength = 0x0A;
        dev_qual_desc->bDescriptorType = USBC_DT_DEVICE_QUALIFIER;
        dev_qual_desc->bcdUSB = dev_desc->bcdUSB;
        dev_qual_desc->bDeviceClass = dev_desc->bDeviceClass;
        dev_qual_desc->bDeviceSubClass = dev_desc->bDeviceSubClass;
        dev_qual_desc->bDeviceProtocol = dev_desc->bDeviceProtocol;
        dev_qual_desc->bMaxPacketSize0 = dev_desc->bMaxPacketSize0;
        dev_qual_desc->bNumConfigurations = dev_desc->bNumConfigurations;

        /* 5. Store device string - language/manufacturere/product/serialnum */
        usbc_get_string_number((void*)usb_language_string);
        dev_desc->iManufacturer = usbc_get_string_number((void*)usbc_inst->dev_param->manufacture_string);
        dev_desc->iProduct = usbc_get_string_number((void*)usbc_inst->dev_param->product_string);
        // Update serial number by reading the IMEI from NVRAM
#ifdef __PRODUCTION_RELEASE__
        dev_desc->iSerialNumber = usbc_core_set_serial_number()? usbc_get_string_number((void*)usbc_inst->dev_param->serial_number):0x00;
#else
/* under construction !*/
#endif

        /* 6. Call init function of each usb class for all configurations */      
        for (idx_cfg = 0; idx_cfg < cfg_num; idx_cfg++)
        {
            cfg_param = &usbc_inst->dev_param->mode_param[usbc_inst->mode].cfg_param[idx_cfg];
            for (idx_class = 0; idx_class < cfg_param->class_num; idx_class++)
            {
                class_init = _get_class_init_func(cfg_param->class_type[idx_class]);
                if (class_init) {
                    usbc_trace_info(USBCORE_ALL_NODE_CHECKIN_INIT_CLASS_START, cfg_param->class_type[idx_class]);
                    class_init( idx_class,
                                usbc_inst->mode,
                                idx_cfg,
                                cfg_param->class_ctxt[idx_class],
                                cfg_param->bulk_double_fifo_bitmap[idx_class]);
                    usbc_trace_info(USBCORE_ALL_NODE_CHECKIN_INIT_CLASS_END, cfg_param->class_type[idx_class]);
                } else {
                    EXT_ASSERT(KAL_FALSE, 1, 0, 0);
                }
            }
        }


        if( !usbc_inst->is_mode_meta_reused )
        {
            /* 7. Construct configuration descriptor */
            _usbc_construct_config_descriptor(usbc_inst);

            /* 8. Update descriptors for META (non-reuse COM) */
            if(usbc_inst->is_mode_meta)
            {
                dev_desc->idProduct = 0x7101;
            }

            /* 9. Set configuration and connect to hif */
            usbc_normal_hif_disconnect();
            usbc_core_set_hif_configuration();
            usbc_normal_hif_connect();
        }
        else
        {
            /* 7. Construct configuration descriptor */
            usbc_inst->resource_iad_number[0] = 0;          // Discard IAD if it is in META mode
            _usbc_construct_config_descriptor(usbc_inst);   // construct configuration descriptor

            /* 8. Update descriptors for META */
            dev_desc->iSerialNumber = 0x00;     // no serial number in BootROM/pre-loader's COM
            config_desc_p = (usbc_configuration_descriptor_t*)usbc_inst->descriptors.configuration[0];   // only one configuration in META mode
            config_desc_p->bmAttributes &= 0xdf;   // the remote wakeup is not capable in BootROM/Pre-loader COM
            config_desc_p->bMaxPower = 0xc8;       // the max power of BootROM/Preloader COM's confiuration is 400mA
            usbc_inst->u3ConfMaxPower = (U3_CONF_BMAXPOWER_META / USBC_USB30_POWER_DESC_UINT); // the max power is 400mA in USB 3.0

            /* 9. Set configuration and connect to hif */
            usbc_meta_hif_factory();            // set function pointers of USB driver to META state
            usbc_core_set_hif_configuration();
        }

    }
}

void usbc_mode_switch(usb_mode_e mode)
{
    kal_uint32   idx;
    usbc_core_t* usbc_inst = usbc_core_get_instance();
    usbc_class_reinit_func_t  class_reinit;

    /* 1. set disconnect */
    hifusb_set_disconnect();

    /* 2. Set switch mode */
    usbc_inst->is_mode_switch = KAL_TRUE;
    usbc_inst->mode = mode;

    /* 3. Send re-init callback to all usb class */
    _SET_NODE_VALUE(0);
    usbc_stack_checkin(USB_CLASS_NUM, NULL);
    for (idx = 0; idx < USB_CLASS_NUM; idx++) {
        class_reinit = _get_class_reinit_func(idx);
        _SET_NODE_REG_TABLE(idx, NULL);
        if (class_reinit) {
            usbc_trace_info(USBCORE_ALL_NODE_CHECKIN_REINIT_CLASS_START, idx);
            class_reinit(KAL_TRUE);
            usbc_trace_info(USBCORE_ALL_NODE_CHECKIN_REINIT_CLASS_END, idx);
        } else {
            EXT_ASSERT(KAL_FALSE, 2, 0, 0);
        }
    }
}

void usbc_reinit_class(void)
{
    kal_uint32   idx;
    usbc_class_reinit_func_t  class_reinit;

    for (idx = 0; idx < USB_CLASS_NUM; idx++) {
        class_reinit = _get_class_reinit_func(idx);
        if (class_reinit) {
            usbc_trace_info(USBCORE_ALL_NODE_CHECKIN_REINIT_CLASS_START, idx);
            class_reinit(KAL_FALSE);
            usbc_trace_info(USBCORE_ALL_NODE_CHECKIN_REINIT_CLASS_END, idx);
        } else {
            EXT_ASSERT(KAL_FALSE, 2, 0, 0);
        }
    }
}

