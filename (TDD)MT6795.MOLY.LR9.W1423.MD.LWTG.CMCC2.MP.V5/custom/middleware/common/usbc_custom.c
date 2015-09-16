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
 *    usbc_custom.c
 *
 * Project:
 * --------
 *    MOLY
 *
 * Description:
 * ------------
 *   This file implements usb customer support
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef  __HIF_USB_SUPPORT__

#include "usbc_custom.h"
#include "dcl.h"
#include "usbc_custom_def.h"
#include "usbc_custom_mode.h"

static kal_uint16 usb_manufacturer_string[] = 
{
	0x031c,  /* bDescriptorType:0x03, bLength:0x1c */
	'M',
	'e',
	'd',
	'i',
	'a',
	'T',
	'e',
	'k',
	' ',
	'I',
	'n',
	'c',
	'.'
};

static kal_uint16 usb_product_string[] = 
{
	0x031a,
	'L',
	'T',
	'E',
	' ',
	'U',
	'S',
	'B',
	' ',
	'C',
	'A',
	'R',
	'D'
};

static kal_uint16 usb_serial_num[] = 
{
#ifdef __PRODUCTION_RELEASE__
	0x0320,
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
	'0',
    '0',
    '0',
    '0'
#else
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
#endif
};

static const usb_dev_param_t usb_dev_param =
{
    0x0e8d,     /* idVendor */
    0x0001,     /* bcdDevice */
    
    usb_manufacturer_string,
    sizeof(usb_manufacturer_string)/sizeof(kal_uint16),
    usb_product_string,
    sizeof(usb_product_string)/sizeof(kal_uint16),
    usb_serial_num,
    sizeof(usb_serial_num)/sizeof(kal_uint16),
    
    2, // morphing sub id

    /* Mode Parameter: each mode is defined in a file of usbc_custom_mode folder */
    /* And the proper name of each USB mode is also defined in usbc_custom_def.h */
    /* ========================================================== */
    {
        /* USB_MODE_BTT_STANDALONE */
        _USBMODE_APP_COM_ONLY,
        /* USB_MODE_ACM_ONLY */
        _USBMODE_DBG_COM_ONLY,
        /* USB_MODE_META */
        _USBMODE_BOOTROM_COM,
        /* USB_MODE_1R2C */
        _USBMODE_LEGACY_1R2C,
        /* USB_MODE_MSD*/
        _USBMODE_CDROM,
        /* USB_MODE_MT6290_DATACARD */
        _USBMODE_DATACARD_MBIM,
        /* USB_MODE_MORPHING */
        _USBMODE_MORPHING,
        /* USB_MODE_MT6290_ECM*/
        _USBMODE_DATACARD_ECM,
        /* USB_MODE_ESL */
        _USBMODE_ESL,
    },

    {   
    #ifdef BTT_STANDALONE_MODE
        USB_MODE_BTT_STANDALONE, //USB_OS_WIN8
        USB_MODE_BTT_STANDALONE, //USB_OS_WIN
        USB_MODE_BTT_STANDALONE, //USB_OS_LINUX
        USB_MODE_BTT_STANDALONE, //USB_OS_MAC
        USB_MODE_BTT_STANDALONE  //USB_OS_OTHERS
    #else   // #ifdef BTT_STANDALONE_MODE
        USB_MODE_MORPHING,        //USB_OS_WIN8
        USB_MODE_MT6290_DATACARD, //USB_OS_WIN
        USB_MODE_MT6290_ECM,      //USB_OS_LINUX
        USB_MODE_MT6290_ECM,      //USB_OS_MAC
        USB_MODE_MT6290_DATACARD  //USB_OS_OTHERS
    #endif // #ifdef BTT_STANDALONE_MODE
    }
};

//
// ACM1 String Descriptor
//
static kal_uint16 acm1_string_descr_interface[] = 
{
	0x031A,  /* bDescriptorType:0x03, bLength:0x1A */
	'U', 'S', 'B', ' ',
	'C', 'O', 'M', ' ',
	'P', 'o', 'r', 't',
};
static const usb_class_acm1_param_t usb_class_acm1_param_c =
{
    acm1_string_descr_interface,                                        // interface_string;
    sizeof(acm1_string_descr_interface)/sizeof(kal_uint16),             // interface_string_size;
};

//
// ACM2 String Descriptor
//
static kal_uint16 acm2_string_descr_comm_interface[] = 
{
	0x0340,  /* bDescriptorType:0x03, bLength:0x40 */
	'U', 'S', 'B', ' ',
    'C', 'O', 'M', ' ',
	'C', 'o', 'm', 'm', 'u', 'n', 'i', 'c', 'a', 't', 'i', 'o', 'n', ' ',
	'I', 'n', 't', 'e', 'r', 'f', 'a', 'c', 'e',
};
static kal_uint16 acm2_string_descr_data_interface[] = 
{
	0x032E,  /* bDescriptorType:0x03, bLength:0x2E */
	'U', 'S', 'B', ' ',
    'C', 'O', 'M', ' ',
	'D', 'a', 't', 'a', ' ',
	'I', 'n', 't', 'e', 'r', 'f', 'a', 'c', 'e',
};
static kal_uint16 acm2_string_descr_iad[] = 
{
    0x031A,  /* bDescriptorType:0x03, bLength:0x1A */
    'U', 'S', 'B', ' ',
    'C', 'O', 'M', ' ',
    'P', 'o', 'r', 't',
};
static const usb_class_acm2_param_t usb_class_acm2_param_c =
{
    acm2_string_descr_comm_interface,                                   // comm_interface_string;
    sizeof(acm2_string_descr_comm_interface)/sizeof(kal_uint16),        // comm_interface_string_size;
    acm2_string_descr_data_interface,                                   // data_interface_string;
    sizeof(acm2_string_descr_data_interface)/sizeof(kal_uint16),        // data_interface_string_size;
    acm2_string_descr_iad,                                              // iad_string;
    sizeof(acm2_string_descr_iad)/sizeof(kal_uint16),                   // iad_string_size;
};

//
// ACM3 String Descriptor
//
static kal_uint16 acm3_string_descr_interface[] = 
{
    0x031A,  /* bDescriptorType:0x03, bLength:0x1A */
    'U', 'S', 'B', ' ',
    'C', 'O', 'M', ' ',
    'P', 'o', 'r', 't',
};
static const usb_class_acm3_param_t usb_class_acm3_param_c =
{
    acm3_string_descr_interface,                                        // interface_string;
    sizeof(acm3_string_descr_interface)/sizeof(kal_uint16),             // interface_string_size;
};

//
// RNDIS String Descriptor
//
static kal_uint16 rndis_string_descr_comm_interface[] = 
{
    0x033C,  /* bDescriptorType:0x03, bLength:0x3C */
    'R', 'N', 'D', 'I', 'S', ' ',
    'C', 'o', 'm', 'm', 'u', 'n', 'i', 'c', 'a', 't', 'i', 'o', 'n', ' ',
    'I', 'n', 't', 'e', 'r', 'f', 'a', 'c', 'e',
};
static kal_uint16 rndis_string_descr_data_interface[] = 
{
	0x032A,  /* bDescriptorType:0x03, bLength:0x2A */
	'R', 'N', 'D', 'I', 'S', ' ',
	'D', 'a', 't', 'a', ' ',
	'I', 'n', 't', 'e', 'r', 'f', 'a', 'c', 'e',
};
static kal_uint16 rndis_string_descr_iad[] = 
{
    0x0326,  /* bDescriptorType:0x03, bLength:0x26 */
    'R', 'E', 'M', 'O', 'T', 'E', ' ',
    'N', 'D', 'I', 'S', ' ',
    'D', 'e', 'v', 'i', 'c', 'e',
};
static const usb_class_rndis_param_t usb_class_rndis_param_c =
{
    rndis_string_descr_comm_interface,                                  // comm_interface_string;
    sizeof(rndis_string_descr_comm_interface)/sizeof(kal_uint16),       // comm_interface_string_size;
    rndis_string_descr_data_interface,                                  // data_interface_string;
    sizeof(rndis_string_descr_data_interface)/sizeof(kal_uint16),       // data_interface_string_size;
    rndis_string_descr_iad,                                             // iad_string;
    sizeof(rndis_string_descr_iad)/sizeof(kal_uint16),                  // iad_string_size;
};

//
// ECM String Descriptor
//
static kal_uint16 ecm_string_descr_comm_interface[] = 
{
    0x033A,  /* bDescriptorType:0x03, bLength:0x3A */
    'E', 'C', 'M', ' ',
    'C', 'o', 'm', 'm', 'u', 'n', 'i', 'c', 'a', 't', 'i', 'o', 'n', ' ',
    'I', 'n', 't', 'e', 'r', 'f', 'a', 'c', 'e',
};
static kal_uint16 ecm_string_descr_null_data_interface[] = 
{
	0x0330,  /* bDescriptorType:0x03, bLength:0x30 */
	'E', 'C', 'M', ' ',
	'N', 'U', 'L', 'L', ' ',
	'D', 'a', 't', 'a', ' ',
	'I', 'n', 't', 'e', 'r', 'f', 'a', 'c', 'e',
};

static kal_uint16 ecm_string_descr_data_interface[] = 
{
	0x0326,  /* bDescriptorType:0x03, bLength:0x26 */
	'E', 'C', 'M', ' ',
	'D', 'a', 't', 'a', ' ',
	'I', 'n', 't', 'e', 'r', 'f', 'a', 'c', 'e',
};
static kal_uint16 ecm_string_descr_iad[] = 
{
    0x0328,  /* bDescriptorType:0x03, bLength:0x28 */
    'U', 'S', 'B', ' ',
    'E', 't', 'h', 'e', 'r', 'n', 'e', 't', ' ',
    'D', 'e', 'v', 'i', 'c', 'e',
};
static kal_uint16 ecm_string_descr_mac_addr[3][13] = 
{
    {0x031A,  /* bDescriptorType:0x03, bLength:0x1A */
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
    
    {0x031A,  /* bDescriptorType:0x03, bLength:0x1A */
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
    
    {0x031A,  /* bDescriptorType:0x03, bLength:0x1A */
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000}, 
};
static const usb_class_ecm_param_t usb_class_ecm_param_c =
{
    ecm_string_descr_comm_interface,                                  // comm_interface_string;
    sizeof(ecm_string_descr_comm_interface)/sizeof(kal_uint16),       // comm_interface_string_size;
    ecm_string_descr_null_data_interface,                              // null_data_interface_string;       -- Disable data interface
    sizeof(ecm_string_descr_null_data_interface)/sizeof(kal_uint16),   // null_data_interface_string_size; 
    ecm_string_descr_data_interface,                                  // data_interface_string;     -- Enable data interface
    sizeof(ecm_string_descr_data_interface)/sizeof(kal_uint16),       // data_interface_string_size;
    ecm_string_descr_iad,                                             // iad_string;
    sizeof(ecm_string_descr_iad)/sizeof(kal_uint16),                  // iad_string_size;
    // mac_addr_string;
    ecm_string_descr_mac_addr[0],
    ecm_string_descr_mac_addr[1],
    ecm_string_descr_mac_addr[2],
    // mac_addr_string_size;  
    sizeof(ecm_string_descr_mac_addr[0])/sizeof(kal_uint16), 
    sizeof(ecm_string_descr_mac_addr[1])/sizeof(kal_uint16),  
    sizeof(ecm_string_descr_mac_addr[2])/sizeof(kal_uint16),
};


//
// MBIM String Descriptor
//
static kal_uint16 mbim_string_descr_comm_interface[] = 
{
    0x033A,  /* bDescriptorType:0x03, bLength:0x3A */
    'M', 'B', 'I', 'M', ' ',
    'C', 'o', 'm', 'm', 'u', 'n', 'i', 'c', 'a', 't', 'i', 'o', 'n', ' ',
    'I', 'n', 't', 'e', 'r', 'f', 'a', 'c', 'e',
};
static kal_uint16 mbim_string_descr_null_data_interface[] = 
{
	0x0332,  /* bDescriptorType:0x03, bLength:0x32 */
	'M', 'B', 'I', 'M', ' ',
	'N', 'U', 'L', 'L', ' ',
	'D', 'a', 't', 'a', ' ',
	'I', 'n', 't', 'e', 'r', 'f', 'a', 'c', 'e',
};
static kal_uint16 mbim_string_descr_data_interface[] = 
{
	0x0328,  /* bDescriptorType:0x03, bLength:0x28 */
	'M', 'B', 'I', 'M', ' ',
	'D', 'a', 't', 'a', ' ',
	'I', 'n', 't', 'e', 'r', 'f', 'a', 'c', 'e',
};
static kal_uint16 mbim_string_descr_iad[] = 
{
    0x0330,  /* bDescriptorType:0x03, bLength:0x30 */
    'M', 'o', 'b', 'i', 'l', 'e', ' ',
    'B', 'r', 'o', 'a', 'd', 'b', 'a', 'n', 'd', ' ',
    'D', 'e', 'v', 'i', 'c', 'e',
};
static const usb_class_mbim_param_t usb_class_mbim_param_c =
{
    mbim_string_descr_comm_interface,                                   // comm_interface_string;
    sizeof(mbim_string_descr_comm_interface)/sizeof(kal_uint16),        // comm_interface_string_size;
    mbim_string_descr_null_data_interface,                              // null_data_interface_string;       -- Disable data interface
    sizeof(mbim_string_descr_null_data_interface)/sizeof(kal_uint16),   // null_data_interface_string_size;
    mbim_string_descr_data_interface,                                   // data_interface_string;       -- Enable data interface
    sizeof(mbim_string_descr_data_interface)/sizeof(kal_uint16),        // data_interface_string_size;
    mbim_string_descr_iad,                                              // iad_string;
    sizeof(mbim_string_descr_iad)/sizeof(kal_uint16),                   // iad_string_size;
};

#if defined(__USB_MSD_SUPPORT__)
//customization disk eport  for MSD only mode
static MS_DISK_CONFIG_TYPE DISK_CONFIG_CDROM[]= {
#if defined(__MTK_TARGET__)
	USBMS_DISK_CDROM   //Export CDROM
#else
	USBMS_DISK_RAMDISK	
#endif
};


//customization disk eport  for ACM only mode
static MS_DISK_CONFIG_TYPE DISK_CONFIG_ACM[]= {
#if defined(__MTK_TARGET__)
	#if defined(__MSDC_SD_MMC__)
		USBMS_DISK_MSDC1,
	#endif
		USBMS_DISK_NAND		
#else	
	USBMS_DISK_RAMDISK
#endif
};

//customization disk eport  for 1R2C mode
static MS_DISK_CONFIG_TYPE DISK_CONFIG_1R2C[]= {
#if defined(__MTK_TARGET__)
	#if defined(__MSDC_SD_MMC__)
		USBMS_DISK_MSDC1,
	#endif
		USBMS_DISK_NAND	
#else	
	USBMS_DISK_RAMDISK
#endif
};

//customization disk eport  for 6290 data card mode
static MS_DISK_CONFIG_TYPE DISK_CONFIG_MT6290_DATACARD[]= {
#if defined(__MTK_TARGET__)
	#if defined(__MSDC_SD_MMC__)
		USBMS_DISK_MSDC1,
	#endif
		USBMS_DISK_NAND
#else
	USBMS_DISK_RAMDISK	
#endif
};

//customization disk eport for 6290 ECM mode
static MS_DISK_CONFIG_TYPE DISK_CONFIG_MT6290_ECM[]= {
#if defined(__MTK_TARGET__)
	#if defined(__MSDC_SD_MMC__)
		USBMS_DISK_MSDC1,
	#endif
		USBMS_DISK_NAND
#else
	USBMS_DISK_RAMDISK	
#endif
};

//customization disk for morphing configuration 1
static MS_DISK_CONFIG_TYPE DISK_CONFIG_MORPHING_CFG1[]= {
#if defined(__MTK_TARGET__)
	USBMS_DISK_CDROM
#else
	USBMS_DISK_RAMDISK		
#endif
};

//customization disk for morphing configuration 2
static MS_DISK_CONFIG_TYPE DISK_CONFIG_MORPHING_CFG2[]= {
#if defined(__MTK_TARGET__)
	#if defined(__MSDC_SD_MMC__)
		USBMS_DISK_MSDC1,
	#endif
		USBMS_DISK_NAND
#else
	USBMS_DISK_RAMDISK
#endif
};


/*
* max string size is 32 Byte...
*/
static kal_uint16 ms_inf_string[] = 
{
	0x031c,
	'M',
	'a',
	's',
	's',
	' ',
	'S',
	't',
	'o',
	'r',
	'a',
	'g',
	'e',
	' '
};

static ms_inquriy_data_t ms_inquriy_data = 
{
	"MEDIATEK",
	" FLASH DISK",
	"7208"
};

static usb_class_ms_param_t ms_cus_param =
{
	sizeof(ms_inf_string)/sizeof(kal_char), /*inf string size*/
	sizeof(ms_inquriy_data_t),	
	0,
	0,
	ms_inf_string,
	&ms_inquriy_data,
	NULL
};

const usb_class_ms_param_t *usb_get_ms_param(usb_mode_e mode,kal_uint32 config_num)
{
	// usbcore trans config num to index
	// and call back usbclass using not config num but config index...
	// trans index to config value now...
	kal_uint32 config_value = config_num + 1; 

	switch(mode)
	{
		case USB_MODE_MSD_ONLY:
			 ms_cus_param.disk_num = sizeof(DISK_CONFIG_CDROM)/sizeof(MS_DISK_CONFIG_TYPE);
			 ms_cus_param.disk_config = DISK_CONFIG_CDROM;
			 break;
		
		case USB_MODE_ACM_ONLY:
			 ms_cus_param.disk_num = sizeof(DISK_CONFIG_ACM)/sizeof(MS_DISK_CONFIG_TYPE);
			 ms_cus_param.disk_config = DISK_CONFIG_ACM;
			 break;
		
		case USB_MODE_1R2C:
			 ms_cus_param.disk_num = sizeof(DISK_CONFIG_1R2C)/sizeof(MS_DISK_CONFIG_TYPE);
			 ms_cus_param.disk_config = DISK_CONFIG_1R2C;
			 break;

		case USB_MODE_MT6290_DATACARD:
			 ms_cus_param.disk_num = sizeof(DISK_CONFIG_MT6290_DATACARD)/sizeof(MS_DISK_CONFIG_TYPE);
			 ms_cus_param.disk_config = DISK_CONFIG_MT6290_DATACARD;
			 break;
             
        case USB_MODE_MT6290_ECM:
             ms_cus_param.disk_num = sizeof(DISK_CONFIG_MT6290_ECM)/sizeof(MS_DISK_CONFIG_TYPE);
             ms_cus_param.disk_config = DISK_CONFIG_MT6290_ECM;
             break;

		case USB_MODE_MORPHING:
			switch(config_value)
				{
					case USB_MODE_MORPHING_CFG1:
						ms_cus_param.disk_num = sizeof(DISK_CONFIG_MORPHING_CFG1)/sizeof(MS_DISK_CONFIG_TYPE);
			 			ms_cus_param.disk_config = DISK_CONFIG_MORPHING_CFG1;
						break;

					case USB_MODE_MORPHING_CFG2:
						ms_cus_param.disk_num = sizeof(DISK_CONFIG_MORPHING_CFG2)/sizeof(MS_DISK_CONFIG_TYPE);
			 			ms_cus_param.disk_config = DISK_CONFIG_MORPHING_CFG2;
						break;

					default:
						ms_cus_param.disk_num = sizeof(DISK_CONFIG_MORPHING_CFG1)/sizeof(MS_DISK_CONFIG_TYPE);
			 			ms_cus_param.disk_config = DISK_CONFIG_MORPHING_CFG1;
						break;
				}
			break;
		
		default: 
			ms_cus_param.disk_num = sizeof(DISK_CONFIG_CDROM)/sizeof(MS_DISK_CONFIG_TYPE);
			ms_cus_param.disk_config = DISK_CONFIG_CDROM;
			break;
	}
    return &ms_cus_param;
}
#endif

/*
 * Public Function
 */
const usb_dev_param_t *usb_get_device_param(void)
{
    return (&usb_dev_param);
}

const usb_class_acm1_param_t *usb_get_acm1_param(void)
{
    return &usb_class_acm1_param_c;
}

const usb_class_acm2_param_t *usb_get_acm2_param(void)
{
    return &usb_class_acm2_param_c;
}

const usb_class_acm3_param_t *usb_get_acm3_param(void)
{
    return &usb_class_acm3_param_c;
}

const usb_class_mbim_param_t *usb_get_mbim_param(void)
{
    return &usb_class_mbim_param_c;
}

const usb_class_rndis_param_t *usb_get_rndis_param(void)
{
    return &usb_class_rndis_param_c;
}

const usb_class_ecm_param_t *usb_get_ecm_param(void)
{
    return &usb_class_ecm_param_c;
}

/* get USB custom parameter function*/
static const usb_custom_func_t usb_custom_func = 
{
	usb_get_device_param,

#if defined(__USB_MSD_SUPPORT__)
	usb_get_ms_param,
#endif

	usb_get_acm1_param,
	usb_get_acm2_param,
	usb_get_acm3_param,
	usb_get_mbim_param,
	usb_get_rndis_param,
	usb_get_ecm_param
};

const usb_custom_func_t *usb_get_custom_func(void)
{
	return(&usb_custom_func);
}

#endif /* __HIF_USB_SUPPORT__ */
