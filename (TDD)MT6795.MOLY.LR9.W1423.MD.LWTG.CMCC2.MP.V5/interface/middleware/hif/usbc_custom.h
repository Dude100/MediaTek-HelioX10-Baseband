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
 *    usbc_custom.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *    This file intends for usb customization parameter definition
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _USBC_CUSTOM_H_
#define _USBC_CUSTOM_H_

#include "usbc_custom_def.h"
#include "kal_general_types.h"

/*     
       Sample Diagram to illustrate the combination of USB Dev Param

       USB Dev Param
             |
             |-- USB Mode 1 (MSD)
             |      |
             |      |-- USB Cfg1
             |             |
             |             |-- USB class 1 (MS)
             |
             |-- USB Mode 2
             |     ...
             |
             |-- USB Mode 3
             |      |
             |      |-- USB Cfg 1
             |      |      |
             |      |      |-- USB class 1 (MS)
             |      |      |         
             |      |      |-- USB class 2 (ACM2)
             |      |      |
             |      |      |-- USB class 3 (RNDIS)
             |      |
             |      |-- USB Cfg 2
             |      |
             |      |-- USB Cfg 3
             |
             |-- USB Mode 4
             |
             |-- USB Mode 5
             ...
                     
 */

#define USB_MAX_CLASS_NUM          8
#define USB_MAX_CFG_NUM            8


typedef enum {
    USB_OS_WIN8 = 0,
    USB_OS_WIN,  // non-win8 windows
    USB_OS_LINUX,
    USB_OS_MAC,
    USB_OS_OTHERS,

    USB_OS_NUM
} usb_os_type_e;

typedef enum {
#if defined(__USB_MSD_SUPPORT__)
    USB_CLASS_MS = 0,
#endif
#ifdef __USB_ACM_SUPPORT__
  #if defined(__USB_MSD_SUPPORT__)
    USB_CLASS_ACM1,  /* 1T1R, 1 interface */
  #else
  	USB_CLASS_ACM1 = 0,  /* 1T1R, 1 interface */
  #endif
    USB_CLASS_ACM2,  /* 2T1R, 2 interface, IAD */
    USB_CLASS_ACM3,  /* 2T1R, 1 interface */
#endif
#ifdef __USB_MBIM_SUPPORT__
    USB_CLASS_MBIM,
#endif
#ifdef __USB_RNDIS_SUPPORT__
    USB_CLASS_RNDIS,
#endif
#ifdef __USB_ECM_SUPPORT__
    USB_CLASS_ECM,
#endif
    USB_CLASS_NUM
} usb_class_type_e;

// definition for double FIFO enabling of bulk endpoint 
#define DATA_IN_DOUBLE_FIFO_ON   0x01
#define DATA_OUT_DOUBLE_FIFO_ON  0x02

#define USB_MODE_MORPHING_CFG1	1
#define USB_MODE_MORPHING_CFG2	2

typedef struct {
    kal_uint32             class_num;
    usb_class_type_e       class_type[USB_MAX_CLASS_NUM];
    /* device mapping for each function. ex. ACM->port, RNDIS/MBIM->network interface id */
    void                   *class_ctxt[USB_MAX_CLASS_NUM];

    /* The 8-bit bitmap is used to describe the enabling for double FIFO.
     * Each bit for each endpoint: bit[0-15] for OUT endpoint, bit[16-31] for IN enepoint
     */
    kal_uint32              bulk_double_fifo_bitmap[USB_MAX_CLASS_NUM]; 
} usb_cfg_param_t;

typedef struct {
    kal_uint16             product_id;         /* idProduct */
    kal_uint8              device_class;       /* bDeviceClass */
    kal_uint8              device_sub_class;   /* bDeviceSubClass */
    kal_uint8              device_protocol;    /* bDeviceProtocol */
    kal_uint8              cfg_num;
    usb_cfg_param_t        cfg_param[USB_MAX_CFG_NUM];
} usb_mode_param_t;

/* custom parameter for usb device */
typedef struct {
    kal_uint16             vendor_id;          /* idVendor */
    kal_uint16             bcd_device;         /* bcdDevice */
    kal_uint16             *manufacture_string;
    kal_uint8              manufacture_string_size;
    kal_uint16             *product_string;
    kal_uint8              product_string_size;
    kal_uint16             *serial_number;
    kal_uint8              serial_number_size;
    kal_uint8              morphing_sub_id;
    usb_mode_param_t       mode_param[USB_MODE_NUM];
    /* USB Mode which each USB OS corresponds to */
    usb_mode_e             usb_mode[USB_OS_NUM];
} usb_dev_param_t;




/* custom parameter for each class type */
typedef struct
{
    kal_uint16             *interface_string;
    kal_uint8              interface_string_size;
} usb_class_acm1_param_t;

typedef struct
{
    kal_uint16             *comm_interface_string;
    kal_uint8              comm_interface_string_size;
    kal_uint16             *data_interface_string;
    kal_uint8              data_interface_string_size;
    kal_uint16             *iad_string;
    kal_uint8              iad_string_size;
} usb_class_acm2_param_t;

typedef struct
{
    kal_uint16             *interface_string;
    kal_uint8              interface_string_size;
} usb_class_acm3_param_t;

typedef struct
{
    kal_uint16             *comm_interface_string;
    kal_uint8              comm_interface_string_size;
    kal_uint16             *null_data_interface_string;
    kal_uint8              null_data_interface_string_size;
    kal_uint16             *data_interface_string;
    kal_uint8              data_interface_string_size;
    kal_uint16             *iad_string;
    kal_uint8              iad_string_size;
} usb_class_mbim_param_t;

typedef struct
{
    kal_uint16             *comm_interface_string;
    kal_uint8              comm_interface_string_size;
    kal_uint16             *data_interface_string;
    kal_uint8              data_interface_string_size;
    kal_uint16             *iad_string;
    kal_uint8              iad_string_size;
} usb_class_rndis_param_t;

typedef struct
{
    kal_uint16             *comm_interface_string;
    kal_uint8              comm_interface_string_size;
    kal_uint16             *null_data_interface_string;
    kal_uint8              null_data_interface_string_size;    
    kal_uint16             *data_interface_string;
    kal_uint8              data_interface_string_size;
    kal_uint16             *iad_string;
    kal_uint8              iad_string_size;
    kal_uint16             *mac_addr_string[3];// max is 3
    kal_uint8              mac_addr_string_size[3];// max is 3
} usb_class_ecm_param_t;

#if defined(__USB_MSD_SUPPORT__)
typedef struct 
{
	kal_char vendor[MS_INQURIY_VENDOR_MAX_SIZE];
	kal_char product[MS_INQURIY_PRODUCT_MAX_SIZE];
	kal_char revision[MS_INQURIY_REVISION_MAX_SIZE];
}ms_inquriy_data_t;


typedef struct 
{
	kal_uint8 inf_str_size;
	kal_uint8 inquiry_str_size;
	kal_uint8 disk_num;
	kal_uint8 reserved;
	kal_uint16 *inf_str_descr;
	ms_inquriy_data_t *inquiry_data;
	MS_DISK_CONFIG_TYPE *disk_config;	
}usb_class_ms_param_t;
#endif

/* get parameter function pointer */
typedef const usb_dev_param_t*           (*usb_get_device_param_f)(void);

#if defined(__USB_MSD_SUPPORT__)
typedef const usb_class_ms_param_t*      (*usb_get_ms_param_f)(usb_mode_e mode, kal_uint32 config_num);
#endif

typedef const usb_class_acm1_param_t*    (*usb_get_acm1_param_f)(void);
typedef const usb_class_acm2_param_t*    (*usb_get_acm2_param_f)(void);
typedef const usb_class_acm3_param_t*    (*usb_get_acm3_param_f)(void);
typedef const usb_class_mbim_param_t*    (*usb_get_mbim_param_f)(void);
typedef const usb_class_rndis_param_t*   (*usb_get_rndis_param_f)(void);
typedef const usb_class_ecm_param_t*     (*usb_get_ecm_param_f)(void);

/* get parameter functions*/
typedef struct 
{
    usb_get_device_param_f       get_device_param_func;
	
#if defined(__USB_MSD_SUPPORT__)
    usb_get_ms_param_f           get_ms_param_func;
#endif

    usb_get_acm1_param_f         get_acm1_param_func;
    usb_get_acm2_param_f         get_acm2_param_func;
    usb_get_acm3_param_f         get_acm3_param_func;
    usb_get_mbim_param_f         get_mbim_param_func;
    usb_get_rndis_param_f        get_rndis_param_func;
    usb_get_ecm_param_f          get_ecm_param_func;
} usb_custom_func_t;


extern const usb_custom_func_t* usb_get_custom_func(void);


#endif /* _USBC_CUSTOM_H_ */

