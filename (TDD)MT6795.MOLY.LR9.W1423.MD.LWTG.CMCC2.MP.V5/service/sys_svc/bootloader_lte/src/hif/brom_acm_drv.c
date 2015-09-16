/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   brom_acm_drv.c
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *	This is the USB3.0 ACM driver to handle ACM related EP0 command
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 ****************************************************************************/

#include "brom_acm_drv.h"
//#include "brom_efuse_drv.h"

usb_acm_priv_t usb_acm_priv;
/*used to record SET_INTERFACE info*/
kal_uint16 acm_if_setting[USBC_TOTAL_INTERFACE_NUM];
kal_uint16 dev_status;
kal_uint16 interface_status[USBC_TOTAL_INTERFACE_NUM];
kal_uint16 ex_patch_pid = 0;
kal_uint16 ex_patch_vid = 0;

/* MODE CDC_ACM Device Descriptors */
usbc_device_descriptor_t usbc_device_descriptor_cdc_acm =
{
    /* Device Descriptor */
    0x12,                           /* bLength              */
    USBC_DT_DEVICE,                 /* DEVICE               */
    0x0300,                         /* USB 3.0              */
#ifdef __CDC_ACM_REPORT_IAD__
    0xEF,                           /* CLASS                */
    0x02,                           /* Subclass             */
    0x01,                           /* Protocol             */
#else
    0x02,                           /* CLASS                */
    0x00,                           /* Subclass             */
    0x00,                           /* Protocol             */
#endif
    0x40,                           /* bMaxPktSize0         */
    USBC_DEF_VID,                   /* idVendor             */
    USBC_DEF_PID,                   /* idProduct            */
    USBC_DEF_BCDDEV,                /* bcdDevice            */
    USBC_DEF_STR_IDX_MANUFACTURER,  /* iManufacturer        */
    USBC_DEF_STR_IDX_PRODUCT,       /* iProduct             */
    0 ,    							/* iSerial Number       */
    0x01                            /* One configuration    */
};


/* MODE CDC_ACM Configuration Descriptors */
usbc_configuration_descriptor_cdc_acm_t usbc_configuration_descriptor_cdc_acm = {
{
    /* Configuration Descriptor */
    0x09,                       /* bLength              */
    0x02,                       /* CONFIGURATION        */
#ifdef __CDC_ACM_REPORT_IAD__
    0x005D,                     /* length               */
#else
    0x0055,                     /* length               */
#endif
    USBC_TOTAL_INTERFACE_NUM,   /* bNumInterfaces       */
    USBC_DEV_CONFIG_ACM_VAL,  	/* bConfigurationValue  */
    0x00,                       /* iConfiguration       */
    0x80,                       /* bmAttributes (required + self-powered) */
    0xFA                        /* power                */
},
#ifdef __CDC_ACM_REPORT_IAD__
{
    /* Interface Association Descriptor */
    0x08,                       /* bLength              */
    USBC_DT_IAD,                /* bDescriptorType      */
    USBC_INTERFACE_MTK_COM_0,   /* bFristInterface      */
    0x02,                       /* bInterfaceCount      */
    0x02,                       /* bFunctionClass       */
    0x02,                       /* bFunctionSubClass    */
    0x01,                       /* bFunctionProtocol    */
    0x00                        /* iFunction            */
},
#endif
{
    /* Comm Interface Descriptor */
    0x09,                       /* bLength              */
    USBC_DT_INTERFACE,          /* INTERFACE            */
    USBC_INTERFACE_MTK_COM_0,   /* bInterfaceNumber     */
    0x00,                       /* bAlternatSetting     */
    0x01,                       /* bNumberEnpoints      */
    0x02,                       /* bInterface Class     */
    0x02,                       /* SubClass             */
    0x01,                       /* Protocol             */
    0x00                        /* Index of String      */
},
{
    /* CS Header Descriptor */
    0x05,                       /* bLength;             */
    0x24,                       /* bDescriptorType;     */
    0x00,                       /* bDescriptorSubType;  */
    0x0110                      /* bcdCDC;              */
},
{
    /* CS Call Manage Descriptor */
    0x05,                       /* bLength              */
    0x24,                       /* bDescriptorType      */
    0x01,                       /* bDescriptorSubType   */
    0x03,                       /* bmCapabilities       */
    /*MT6280 has issue on MACOS for this field not match DATA interface number*/
    USBC_INTERFACE_MTK_COM_1    /* bDataInterface       */ 
},
{
    /* CS Abstract Control Manage Descriptor */
    0x04,                       /* bLength              */
    0x24,                       /* bDescriptorType      */
    0x02,                       /* bDescriptorSubType   */
    0x0F                        /* bmCapabilities       */
},
{
    /* CS Union Function Descriptor */
    0x05,                       /* bLength;             */
    0x24,                       /* bDescriptorType;     */
    0x06,                       /* bDescriptorSubType;  */
    USBC_INTERFACE_MTK_COM_0,   /* bMasterInterface;    */ //Comm Interface
    USBC_INTERFACE_MTK_COM_1    /* bSlaveInterface;     */ //Data Interface
},
{
    /* Comm EndpointDescriptor */
    0x07,                       /* bLength              */
    0x05,                       /* bDescriptorType      */
    0x80|USBC_ACM_COMM_IN_EP,	/* bEndpointAddress     */
    0x03,                       /* bmAttributes         */
    0x0040,                     /* wMaxPacketSize       */
    0x01                        /* bInterval            */
},
{
	/*Comm SuperSpeed Endpoint Companion Descriptor*/
	0x6,						/*bLength*/
	0x30,						/*bDescriptorType*/
	0x00,						/*bMaxBurst*/
	0x00,						/*bmAttributes*/
	0x0040,						/*bBytesPerInterval*/
},
{
    /* Data Interface Descriptor */
    0x09,                       /* bLength              */
    USBC_DT_INTERFACE,          /* INTERFACE            */
    USBC_INTERFACE_MTK_COM_1,   /* bInterfaceNumber     */
    0x00,                       /* bAlternatSetting     */
    0x02,                       /* bNumberEnpoints      */
    0x0A,                       /* bInterface Class     */
    0x00,                       /* SubClass             */
    0x00,                       /* Protocol             */
    0x00                        /* Index of String      */
},
{
    /* Data In Endpoint Descriptor */
    0x07,                       /* bLength              */
    0x05,                       /* bDescriptorType      */
    0x80|USBC_ACM_DATA_IN_EP,	/* bEndpointAddress     */
    0x02,                       /* bmAttributes         */
    0x0200,                     /* wMaxPacketSize       */
    0x00                        /* bInterval            */
},
{
	/*Data In SuperSpeed Endpoint Companion Descriptor*/
	0x6,						/*bLength*/
	0x30,						/*bDescriptorType*/
	0x1,						/*bMaxBurst*/
	0x00,						/*bmAttributes*/
	0x0000,						/*bBytesPerInterval*/
},
{
    /* Data Out EndpointDescriptor */
    0x07,                       /* bLength              */
    0x05,                       /* bDescriptorType      */
    USBC_ACM_DATA_OUT_EP,  		/* bEndpointAddress     */
    0x02,                       /* bmAttributes         */
    0x0200,                     /* wMaxPacketSize       */
    0x00                        /* bInterval            */
},
{
	/*Data Out SuperSpeed Endpoint Companion Descriptor*/
	0x6,						/*bLength*/
	0x30,						/*bDescriptorType*/
	0x1,						/*bMaxBurst*/
	0x00,						/*bmAttributes*/
	0x0000,						/*bBytesPerInterval*/
},
};

usbc_bos_descriptor_cdc_acm_t usbc_bos_descriptor_cdc_acm = {
{
	/*BOS standard descriptor*/
	0x05,						/*bLength*/
	0x0F,						/*bDescriptorType*/
	0x0016,						/*wTotalLength*/
	0x02						/*bNumDeviceCaps*/
},
{
	/*USB2.0 Extension Device Capability Descriptor*/
	0x07,						/*bLength*/
	0x10,						/*bDescriptorType*/
	0x02,						/*bDevCapabilityType*/
	/*Link Power Management : YES*/
	0x00000002					/*bmAttributes*/
},
{
	/*SuperSpeed Device Capability Descriptor*/
	0x0A,						/*bLength*/
	0x10,						/*bDescritorType*/
	0x03,						/*bDevCapabilityType*/
	0x00,						/*bmAttributes*/
	/*bit-map : support FS/HS/5Gbs*/
	0x000E,						/*wSpeedsSupport*/
	0x01,						/*bFunctionalitySupport*/
	0x0A,						/*bU1DevExitLat*/
	0x0020,						/*bU2DevExitLat*/
},
};


/* MODE CDC_ACM Device Qualifier Descriptors */
usbc_device_qualifier_descriptor_t usbc_device_qualifier_descriptor_cdc_acm =
{
    /* Device Qualifier Descriptor */
    0x0A,                       /* bLength              */
    USBC_DT_DEVICE_QUALIFIER,   /* Device Qualifier     */
    0x0200,                     /* USB Version          */
#ifdef __CDC_ACM_REPORT_IAD__
    0xEF,                       /* CLASS                */
    0x02,                       /* Subclass             */
    0x01,                       /* Protocol             */
#else
    0x02,                       /* CLASS                */
    0x00,                       /* Subclass             */
    0x00,                       /* Protocol             */
#endif
    0x40,                       /* Max Packet Length    */
    0x01,                       /* Number of other speed config */
    0x00                        /* Reserved             */
};

/* Default String Descriptor Language ID */
static kal_uint8 usbc_string_descriptor_language_default[] =
{
    /* String Descriptor */
    0x04,                       /* bLength              */
    0x03,                       /* bDescriptorType      */
    0x09,0x04
};

/* Default String Descriptor Manufacturer */
static kal_uint8 usbc_string_descriptor_manufacturer_default[] =
{
    /* String Descriptor */
    0x1c,                       /* bLength              */
    0x03,                       /* bDescriptorType      */
    'M',0x00,'e',0x00,'d',0x00,'i',0x00,
    'a',0x00,'T',0x00,'e',0x00,'k',0x00,
    ' ',0x00,'I',0x00,'n',0x00,'c',0x00,
    '.',0x00
};

/* Default String Descriptor Product */
static kal_uint8 usbc_string_descriptor_product_default[] =
{
    /* String Descriptor */
    0x1a,                       /* bLength              */
    0x03,                       /* bDescriptorType      */
    'L',0x00,'T',0x00,'E',0x00,' ',0x00,
    'U',0x00,'S',0x00,'B',0x00,' ',0x00,
    'C',0x00,'A',0x00,'R',0x00,'D',0x00,
};

/* Default String Descriptor SerialNum */
static kal_uint8 usbc_string_descriptor_serialnum_default[] =
{
    /* String Descriptor Serial Number */
    0x1a,                       /* bLength              */
    0x03,                       /* bDescriptorType      */
    '1',0x00,'1',0x00,'2',0x00,'2',0x00,
    '3',0x00,'3',0x00,'4',0x00,'4',0x00,
    '5',0x00,'5',0x00,'6',0x00,'6',0x00
};

usbc_string_descriptor_t *p_language_str_desc = (usbc_string_descriptor_t *)usbc_string_descriptor_language_default;
usbc_string_descriptor_t *p_manuf_str_desc = (usbc_string_descriptor_t *)usbc_string_descriptor_manufacturer_default;
usbc_string_descriptor_t *p_product_str_desc = (usbc_string_descriptor_t *)usbc_string_descriptor_product_default;
usbc_string_descriptor_t *p_sn_str_desc = (usbc_string_descriptor_t *)usbc_string_descriptor_serialnum_default;


void usbc_mode_speed_change_cdc_acm_usb11(void)
{
	usbc_device_descriptor_cdc_acm.bcdUSB = 0x210;
	usbc_device_descriptor_cdc_acm.bMaxPacketSize0 = 0x40;
    usbc_configuration_descriptor_cdc_acm.commin_endpoint_descriptor.wMaxPacketSize = USBC_USB11_MAX_PACKET_SIZE;
    usbc_configuration_descriptor_cdc_acm.datain_endpoint_descriptor.wMaxPacketSize = USBC_USB11_MAX_PACKET_SIZE;
    usbc_configuration_descriptor_cdc_acm.dataout_endpoint_descriptor.wMaxPacketSize = USBC_USB11_MAX_PACKET_SIZE;
	usbc_configuration_descriptor_cdc_acm.configuration_descriptor.bMaxPower = 400/USB20_POWER_DESC_UINT; //for USB2.0 the unit is 2mA
	usbc_configuration_descriptor_cdc_acm.configuration_descriptor.wTotalLength = 
	usbc_configuration_descriptor_cdc_acm.configuration_descriptor.bLength +
#ifdef __CDC_ACM_REPORT_IAD__
		usbc_configuration_descriptor_cdc_acm.interface_association_descriptor.bLength +
#endif
		usbc_configuration_descriptor_cdc_acm.control_interface_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.cs_header_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.cs_call_manage_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.cs_abstrac_control_manage_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.cs_union_function_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.commin_endpoint_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.data_interface_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.datain_endpoint_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.dataout_endpoint_descriptor.bLength;
}


void usbc_mode_speed_change_cdc_acm_usb20(void)
{
	usbc_device_descriptor_cdc_acm.bcdUSB = 0x210;
	usbc_device_descriptor_cdc_acm.bMaxPacketSize0 = 0x40;
    usbc_configuration_descriptor_cdc_acm.commin_endpoint_descriptor.wMaxPacketSize = USBC_USB11_MAX_PACKET_SIZE;
    usbc_configuration_descriptor_cdc_acm.datain_endpoint_descriptor.wMaxPacketSize = USBC_USB20_MAX_PACKET_SIZE;
    usbc_configuration_descriptor_cdc_acm.dataout_endpoint_descriptor.wMaxPacketSize = USBC_USB20_MAX_PACKET_SIZE;
	usbc_configuration_descriptor_cdc_acm.configuration_descriptor.bMaxPower = 400/USB20_POWER_DESC_UINT; //for USB2.0 the unit is 2mA
	usbc_configuration_descriptor_cdc_acm.configuration_descriptor.wTotalLength = 
	usbc_configuration_descriptor_cdc_acm.configuration_descriptor.bLength +
#ifdef __CDC_ACM_REPORT_IAD__
		usbc_configuration_descriptor_cdc_acm.interface_association_descriptor.bLength +
#endif
		usbc_configuration_descriptor_cdc_acm.control_interface_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.cs_header_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.cs_call_manage_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.cs_abstrac_control_manage_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.cs_union_function_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.commin_endpoint_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.data_interface_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.datain_endpoint_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.dataout_endpoint_descriptor.bLength;
}


void usbc_mode_speed_change_cdc_acm_usb30(void)
{

	usbc_device_descriptor_cdc_acm.bcdUSB = 0x300;
	usbc_device_descriptor_cdc_acm.bMaxPacketSize0 = 0x09; //for SuperSpeed 2^n
    usbc_configuration_descriptor_cdc_acm.commin_endpoint_descriptor.wMaxPacketSize = USBC_USB11_MAX_PACKET_SIZE;
    usbc_configuration_descriptor_cdc_acm.datain_endpoint_descriptor.wMaxPacketSize = USBC_USB30_MAX_PACKET_SIZE;
    usbc_configuration_descriptor_cdc_acm.dataout_endpoint_descriptor.wMaxPacketSize = USBC_USB30_MAX_PACKET_SIZE;
	usbc_configuration_descriptor_cdc_acm.configuration_descriptor.bMaxPower = 400/USB30_POWER_DESC_UINT; //for USB3.0 the unit is 8mA
	usbc_configuration_descriptor_cdc_acm.configuration_descriptor.wTotalLength = 
	usbc_configuration_descriptor_cdc_acm.configuration_descriptor.bLength +
#ifdef __CDC_ACM_REPORT_IAD__
		usbc_configuration_descriptor_cdc_acm.interface_association_descriptor.bLength +
#endif
		usbc_configuration_descriptor_cdc_acm.control_interface_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.cs_header_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.cs_call_manage_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.cs_abstrac_control_manage_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.cs_union_function_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.commin_endpoint_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.commin_ep_companion_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.data_interface_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.datain_endpoint_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.datain_ep_companion_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.dataout_endpoint_descriptor.bLength +
		usbc_configuration_descriptor_cdc_acm.dataout_ep_companion_descriptor.bLength;	
}

kal_uint32 usbc_cpy_config_desc_by_speed(hifusb_usb_speed_e speed, kal_uint8 *p_buf, kal_uint16 wLength, kal_bool is_other_speed)
{
	kal_uint32 cpy_len = 0, total_len = 0;

	switch (speed) {
		case HIFUSB_USB_SPEED_USB11:
			usbc_mode_speed_change_cdc_acm_usb11();			
			break;
		case HIFUSB_USB_SPEED_USB20:
			usbc_mode_speed_change_cdc_acm_usb20();
			break;
		case HIFUSB_USB_SPEED_USB30:
			usbc_mode_speed_change_cdc_acm_usb30();
			break;
		default:
			break;
	}

	total_len = HIFUSB_MIN(usbc_configuration_descriptor_cdc_acm.configuration_descriptor.wTotalLength, wLength);

	cpy_len = usbc_configuration_descriptor_cdc_acm.configuration_descriptor.bLength;
	if (is_other_speed) {
		usbc_configuration_descriptor_cdc_acm.configuration_descriptor.bDescriptorType = USBC_DT_OTHER_SPEED;
	} else {
		usbc_configuration_descriptor_cdc_acm.configuration_descriptor.bDescriptorType = USBC_DT_CONFIG;
	}
	memcpy(p_buf, (void*)(&usbc_configuration_descriptor_cdc_acm.configuration_descriptor), cpy_len);
	p_buf += cpy_len;
#ifdef __CDC_ACM_REPORT_IAD__
	cpy_len = usbc_configuration_descriptor_cdc_acm.interface_association_descriptor.bLength;
	memcpy(p_buf, (void*)(&usbc_configuration_descriptor_cdc_acm.interface_association_descriptor), cpy_len);
	p_buf += cpy_len;
#endif
	cpy_len = usbc_configuration_descriptor_cdc_acm.control_interface_descriptor.bLength;
	memcpy(p_buf, (void*)(&usbc_configuration_descriptor_cdc_acm.control_interface_descriptor), cpy_len);
	p_buf += cpy_len;
	cpy_len = usbc_configuration_descriptor_cdc_acm.cs_header_descriptor.bLength;
	memcpy(p_buf, (void*)(&usbc_configuration_descriptor_cdc_acm.cs_header_descriptor), cpy_len);
	p_buf += cpy_len;
	cpy_len = usbc_configuration_descriptor_cdc_acm.cs_call_manage_descriptor.bLength;
	memcpy(p_buf, (void*)(&usbc_configuration_descriptor_cdc_acm.cs_call_manage_descriptor), cpy_len);
	p_buf += cpy_len;
	cpy_len = usbc_configuration_descriptor_cdc_acm.cs_abstrac_control_manage_descriptor.bLength;
	memcpy(p_buf, (void*)(&usbc_configuration_descriptor_cdc_acm.cs_abstrac_control_manage_descriptor), cpy_len);
	p_buf += cpy_len;
	cpy_len = usbc_configuration_descriptor_cdc_acm.cs_union_function_descriptor.bLength;
	memcpy(p_buf, (void*)(&usbc_configuration_descriptor_cdc_acm.cs_union_function_descriptor), cpy_len);
	p_buf += cpy_len;
	cpy_len = usbc_configuration_descriptor_cdc_acm.commin_endpoint_descriptor.bLength;
	memcpy(p_buf, (void*)(&usbc_configuration_descriptor_cdc_acm.commin_endpoint_descriptor), cpy_len);
	p_buf += cpy_len;
	if (speed == HIFUSB_USB_SPEED_USB30) {
		cpy_len = usbc_configuration_descriptor_cdc_acm.commin_ep_companion_descriptor.bLength;
		memcpy(p_buf, (void*)(&usbc_configuration_descriptor_cdc_acm.commin_ep_companion_descriptor), cpy_len);
		p_buf += cpy_len;		
	}
	cpy_len = usbc_configuration_descriptor_cdc_acm.data_interface_descriptor.bLength;
	memcpy(p_buf, (void*)(&usbc_configuration_descriptor_cdc_acm.data_interface_descriptor), cpy_len);
	p_buf += cpy_len;
	cpy_len = usbc_configuration_descriptor_cdc_acm.datain_endpoint_descriptor.bLength;
	memcpy(p_buf, (void*)(&usbc_configuration_descriptor_cdc_acm.datain_endpoint_descriptor), cpy_len);
	p_buf += cpy_len;
	if (speed == HIFUSB_USB_SPEED_USB30) {
		cpy_len = usbc_configuration_descriptor_cdc_acm.datain_ep_companion_descriptor.bLength;
		memcpy(p_buf, (void*)(&usbc_configuration_descriptor_cdc_acm.datain_ep_companion_descriptor), cpy_len);
		p_buf += cpy_len;		
	}
	cpy_len = usbc_configuration_descriptor_cdc_acm.dataout_endpoint_descriptor.bLength;
	memcpy(p_buf, (void*)(&usbc_configuration_descriptor_cdc_acm.dataout_endpoint_descriptor), cpy_len);
	p_buf += cpy_len;
	if (speed == HIFUSB_USB_SPEED_USB30) {
		cpy_len = usbc_configuration_descriptor_cdc_acm.dataout_ep_companion_descriptor.bLength;
		memcpy(p_buf, (void*)(&usbc_configuration_descriptor_cdc_acm.dataout_ep_companion_descriptor), cpy_len);
		p_buf += cpy_len;		
	}

	return total_len;
}

hifusb_control_request_type_e usb_ep0_vendor_req_handle(hifusb_setup_packet_t *p_setup, void *p_buf, kal_uint32 *p_len)
{
	hifusb_control_request_type_e ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL;

	return ret;
}

void usb_acm_patch_pid_vid(kal_uint16 patch_pid, kal_uint16 patch_vid)
{
	ex_patch_pid = patch_pid;
	ex_patch_vid = patch_vid;
}

/*
 *	@brief	initial the ACM driver setting and variable
*/
void usb_acm_init(void)
{
	kal_uint32 pid_vid;

	/*initial ACM descriptor PID/VID*/

	//efuse_acquire_usb_pidvid(&pid_vid);

	if ((ex_patch_pid != 0) || (ex_patch_vid != 0)) { //patch by command script
		usbc_device_descriptor_cdc_acm.idVendor = ex_patch_vid;
		usbc_device_descriptor_cdc_acm.idProduct = ex_patch_pid;
	} else if (pid_vid !=0) { //patch by efuse
		usbc_device_descriptor_cdc_acm.idVendor = pid_vid & 0xFFFF; //efuse LSB 16bit is VID
		usbc_device_descriptor_cdc_acm.idProduct = ((pid_vid >> 16) & 0xFFFF); //efuse MSB 16bit is PID
	}

	/*initial line coding*/
}

hifusb_control_request_type_e usb_ep0_class_req_handle(hifusb_setup_packet_t *p_setup, void *p_buf, kal_uint32 *p_len)
{
	hifusb_control_request_type_e ret = HIFUSB_CONTROL_REQUEST_TYPE_STALL; //default return STALL
	kal_uint8 interface_idx = 0;
	
	interface_idx = 0xFF & p_setup->wIndex;
	if (((p_setup->bmRequestType & USBC_REQUEST_RECIP_MASK) == USBC_REQUEST_RECIP_INTERFACE) && 
															(interface_idx == USBC_INTERFACE_MTK_COM_0)) {
		switch (p_setup->bRequest) {
			case USB_ACM_SET_LINE_CODING:
				if ((p_setup->bmRequestType & USBC_REQUEST_DIR_IN) == 0) {
					ret = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;
					memcpy((void*)(&usb_acm_priv.line_coding), p_buf, HIFUSB_MIN(*p_len, sizeof(usb_acm_priv.line_coding)));
				}
				break;
			case USB_ACM_GET_LINE_CODING:
				if (p_setup->bmRequestType & USBC_REQUEST_DIR_IN) {
					ret = HIFUSB_CONTROL_REQUEST_TYPE_SEND;
					*p_len = HIFUSB_MIN(p_setup->wLength, sizeof(usb_acm_priv.line_coding));
					memcpy(p_buf, (void*)(&usb_acm_priv.line_coding), *p_len);
				}
				break;
			case USB_ACM_SET_CONTROL_LINE_STATE:
	        case USB_ACM_SEND_BREAK:
				// Do nothing as MAUI.
				if ((p_setup->bmRequestType & USBC_REQUEST_DIR_IN) == 0) {
					ret = HIFUSB_CONTROL_REQUEST_TYPE_RECEIVE;
				}				
				break;				
	        case USB_ACM_SEND_ENCAPSULATED_COMMAND:
	        case USB_ACM_GET_ENCAPSULATED_RESPONSE:
	        case USB_ACM_SET_COMM_FEATURE:
	        case USB_ACM_GET_COMM_FEATURE:
	        case USB_ACM_CLEAR_COMM_FEATURE:
			default : //return STALL
				break;
		}
	}

	return ret;
}

