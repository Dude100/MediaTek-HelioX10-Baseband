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
 *    usb_custom.c
 *
 * Project:
 * --------
 *   Maui_Software
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "eint.h"
#include "usb_custom.h"
//MSBB remove #include "kal_non_specific_general_types.h"
#include "drv_features.h"
#include "dcl.h"
#include "usb_custom_def.h"
#include "usb_memory_def.h"



/************************************************************
	external variables
*************************************************************/
#if defined(__USB_ENABLE__)&&defined(__USB_MASS_STORAGE_ENABLE__)
	#include "usb_msdisk.h"
	#include "fat_fs.h"
	
	extern USB_DiskDriver_STRUCT USB_NOR_drv;
	extern USB_DiskDriver_STRUCT USB_SIMPLUS_drv;
	#ifdef NAND_SUPPORT
	extern USB_DiskDriver_STRUCT USB_NAND_drv;
	#endif	/*NAND_SUPPORT*/
	#ifdef __USB_MASS_STORAGE_CDROM_ENABLE__
	extern	USB_DiskDriver_STRUCT USB_CDROM_drv;
	#endif /*__USB_MASS_STORAGE_CDROM_ENABLE__*/
	#ifdef __MSDC_DUAL_CARD_SWITCH__
	extern USB_DiskDriver_STRUCT USB_tCard_2_drv;
	#endif /*__MSDC_DUAL_CARD_SWITCH__*/
	#if defined(__SIM_PLUS__)
	extern kal_bool g_usb_ms_simplus_exist;
	#endif /*__SIM_PLUS__*/
#endif   /*#if defined(__USB_ENABLE__)&&defined(__USB_MASS_STORAGE_ENABLE__)*/




#ifdef __CUST_NEW__
#if (defined(__USB_ENABLE__) && defined(PMIC_6305_USB_FUNCTION))
extern const char gpio_usb_enable_pin;
#endif
#if defined(__USB_ENABLE__) && defined(DRV_PHY_CHARGER_DETECT_BY_EXTERNAL_R)
extern const char gpio_usb_chr_det_switch_pin;
#endif
#endif /* __CUST_NEW__ */



#ifdef __USB_ENABLE__
#if defined(__MTK_TARGET__)
__attribute__((zero_init, section ("NONCACHEDZI"),aligned(16)))
#endif
kal_uint8 USB_BUFFER[USB_MAX_MEMORY_SIZE]; // USB total buffer 
#endif



/************************************************************
	device descriptor parameters
*************************************************************/

static const kal_uint16 USB_MANUFACTURER_STRING[] = 
{
	0x031a,
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
	'c'
};

static const kal_uint16 USB_PRODUCT_STRING[] = 
{
	0x0310,
	'P',
	'r',
	'o',
	'd',
	'u',
	'c',
	't'
};


static const USB_DEVICE_PARAM usb_device_param = 
{
	LEVEL_HIGH,			/* cable plugin level */
	0x0e8d,				/* vendor id */	
	USB_MANUFACTURER_STRING,
	sizeof(USB_MANUFACTURER_STRING)/sizeof(kal_uint16),
	USB_PRODUCT_STRING,
	sizeof(USB_PRODUCT_STRING)/sizeof(kal_uint16)
};

 /************************************************************
	mass storage parameters
*************************************************************/

 /*USB mass storage customize*/

/* Inquire data explanation
   The length byte(Byte 4) should be always not changed, the mass storage spec define it
   Byte 8 to 15 is Vendor Information
   Byte 16 to 31 is Product Identification
   Byte 32 to 35 is Product Revision Level */   
#ifdef __MTK_TARGET__
__attribute__ ((section ("NONCACHEDRW"), aligned(4))) 
#endif /* __MTK_TARGET__ */
kal_uint8 INQUIRE_DATA[] =
{
	0x00,
	0x80,
	0x00,
	0x01,
	0x1f, /*length*/
	0x00,
	0x00,
	0x00,
	'M',   
	'E',
	'D',
	'I',
	'A',
	'T',
	'E',
	'K',
	' ',
	'F',
	'L',
	'A',
	'S',
	'H',
	' ',
	'D',
	'I',
	'S',
	'K',
	' ',
	' ',
	' ',
	' ',
	' ',
	'6',
	'2',
	'2',
	'5'
};

static const kal_uint16  USB_MS_INTERFACE_STRING[] = 
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


static const USB_MS_PARAM usb_ms_param = 
{
	0x0002,			/* Mass storage Product ID */
	INQUIRE_DATA,
	sizeof(INQUIRE_DATA)/sizeof(kal_uint8),
	USB_MS_INTERFACE_STRING,
	sizeof(USB_MS_INTERFACE_STRING)/sizeof(kal_uint16)
};

/************************************************************
	CDC ACM parameters
*************************************************************/

static const kal_uint16 USB_ACM_COMM_INTERFACE_STRING[] = 
{
	0x031A,
	'C',
	'O',
	'M',
	'(',
	'c',   
	'o',
	'm',
	'm',
	'_',
	'i',
	'f',
	')'
};

static const kal_uint16  USB_ACM_DATA_INTERFACE_STRING[] = 
{
	0x031A,
	'C',
	'O',
	'M',
	'(',
	'd',
	'a',
	't',
	'a',
	'_',
	'i',
	'f',
	')'
};

#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)

static const kal_uint16 USB_ACM_COMM_INTERFACE_STRING_2[] =
{
	0x031A,
	'C',
	'O',
	'M',
	'(',
	'c',
	'o',
	'm',
	'm',
	'_',
	'i',
	'f',
	')'
};


static const kal_uint16  USB_ACM_DATA_INTERFACE_STRING_2[] =
{
	0x031A,
	'C',
	'O',
	'M',
	'(',
	'd',
	'a',
	't',
	'a',
	'_',
	'i',
	'f',
	')'
};

#if defined (__USB_MODEM_CARD_SUPPORT__)
static const kal_uint16 USB_ACM_COMM_INTERFACE_STRING_3[] =
{
	0x031A,
	'C',
	'O',
	'M',
	'(',
	'c',
	'o',
	'm',
	'm',
	'_',
	'i',
	'f',
	')'
};


static const kal_uint16  USB_ACM_DATA_INTERFACE_STRING_3[] =
{
	0x031A,
	'C',
	'O',
	'M',
	'(',
	'd',
	'a',
	't',
	'a',
	'_',
	'i',
	'f',
	')'
};

static const kal_uint16 USB_ACM_COMM_INTERFACE_STRING_4[] =
{
	0x031A,
	'C',
	'O',
	'M',
	'(',
	'c',
	'o',
	'm',
	'm',
	'_',
	'i',
	'f',
	')'
};


static const kal_uint16  USB_ACM_DATA_INTERFACE_STRING_4[] =
{
	0x031A,
	'C',
	'O',
	'M',
	'(',
	'd',
	'a',
	't',
	'a',
	'_',
	'i',
	'f',
	')'
};

static const kal_uint16 USB_ACM_COMM_INTERFACE_STRING_5[] =
{
	0x031A,
	'C',
	'O',
	'M',
	'(',
	'c',
	'o',
	'm',
	'm',
	'_',
	'i',
	'f',
	')'
};


static const kal_uint16  USB_ACM_DATA_INTERFACE_STRING_5[] =
{
	0x031A,
	'C',
	'O',
	'M',
	'(',
	'd',
	'a',
	't',
	'a',
	'_',
	'i',
	'f',
	')'
};
#endif

#endif  /* defined(__USB_MULTIPLE_COMPORT_SUPPORT__) */



static const USB_ACM_PARAM usb_acm_param =
{
#if !defined (__USB_MODEM_CARD_SUPPORT__)
	0x0003,				/* CDC ACM Product ID */
#else
	0x00A0,				/* CDC ACM Product ID */
#endif
	USB_ACM_COMM_INTERFACE_STRING,
	sizeof(USB_ACM_COMM_INTERFACE_STRING)/sizeof(kal_uint16),
	USB_ACM_DATA_INTERFACE_STRING,
	sizeof(USB_ACM_DATA_INTERFACE_STRING)/sizeof(kal_uint16),
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
#if !defined (__USB_MODEM_CARD_SUPPORT__)
	0x0023,				/* dual CDC ACM Product ID */
#else
	0x00A1,				/* dual CDC ACM Product ID */
#endif
	USB_ACM_COMM_INTERFACE_STRING_2,
	sizeof(USB_ACM_COMM_INTERFACE_STRING_2)/sizeof(kal_uint16),
	USB_ACM_DATA_INTERFACE_STRING_2,
	sizeof(USB_ACM_DATA_INTERFACE_STRING_2)/sizeof(kal_uint16),
#if defined (__USB_MODEM_CARD_SUPPORT__)
	0x00A2,				/* dual CDC ACM Product ID */
	USB_ACM_COMM_INTERFACE_STRING_3,
	sizeof(USB_ACM_COMM_INTERFACE_STRING_3)/sizeof(kal_uint16),
	USB_ACM_DATA_INTERFACE_STRING_3,
	sizeof(USB_ACM_DATA_INTERFACE_STRING_3)/sizeof(kal_uint16),
#endif
#endif
#if defined(__USB_TETHERING__)
	0x000A, // ISD Product ID 
	0x0013, // ISD + COM Product ID
#endif
#if defined(__USB_DATA_CONNECTION__)
	0x0043, //Data Connection Single port
	0x0033, //Data Connection Dual port
#endif
#if defined(__USB_MODEM_CARD_SUPPORT__)
	0x00A4,	//desc_5vcom_product;
	0x00A5,	//desc_mbim_4vcom_product;
#endif
};



#ifdef WEBCAM_SUPPORT

/************************************************************
	VIDEO parameters
*************************************************************/

static const kal_uint16 USB_VIDEO_VC_INTERFACE_STRING[] = 
{
	0x031A,
	'V',
	'I',
	'D',
	'E',
	'O',
	'(',
	'V',
	'C',
	'_',
	'i',
	'f',
	')'
};

static const kal_uint16 USB_VIDEO_CT_INTERFACE_STRING[] = 
{
	0x031A,
	'V',
	'I',
	'D',
	'E',
	'O',
	'(',
	'C',
	'T',
	'_',
	'i',
	'f',
	')'
};

static const kal_uint16 USB_VIDEO_OUTPUT_INTERFACE_STRING[] = 
{
	0x0322,
	'V',
	'I',
	'D',
	'E',
	'O',
	'(',
	'o',
	'u',
	't',
	'p',
	'u',
	't',
	'_',
	'i',
	'f',
	')'
};

static const kal_uint16 USB_VIDEO_PU_INTERFACE_STRING[] = 
{
	0x031A,
	'V',
	'I',
	'D',
	'E',
	'O',
	'(',
	'P',
	'U',
	'_',
	'i',
	'f',
	')'
};

static const kal_uint16 USB_VIDEO_VS_INTERFACE_STRING[] = 
{
	0x031A,
	'V',
	'I',
	'D',
	'E',
	'O',
	'(',
	'V',
	'S',
	'_',
	'i',
	'f',
	')'
};

static const USB_VIDEO_PARAM usb_video_param = 
{
	0x0004,			/* video Product ID */
#ifdef __COMPOSITE_WEBCAM__		
	0x0014,        // PID  (for composite : Webcam+COM)	
#endif	
	USB_VIDEO_VC_INTERFACE_STRING,
	sizeof(USB_VIDEO_VC_INTERFACE_STRING)/sizeof(kal_uint16),
	USB_VIDEO_CT_INTERFACE_STRING,
	sizeof(USB_VIDEO_CT_INTERFACE_STRING)/sizeof(kal_uint16),
	USB_VIDEO_OUTPUT_INTERFACE_STRING,
	sizeof(USB_VIDEO_OUTPUT_INTERFACE_STRING)/sizeof(kal_uint16),
	USB_VIDEO_PU_INTERFACE_STRING,
	sizeof(USB_VIDEO_PU_INTERFACE_STRING)/sizeof(kal_uint16),
	USB_VIDEO_VS_INTERFACE_STRING,
	sizeof(USB_VIDEO_VS_INTERFACE_STRING)/sizeof(kal_uint16)
};
#endif /* WEBCAM_SUPPORT */

#ifdef PICTBRIDGE_SUPPORT
/************************************************************
	PTP IMAGE parameters
*************************************************************/
static const kal_uint16 USB_PTP_IMAGE_INTERFACE_STRING[] = 
{
	0x030C,
	'I',
	'M',
	'A',
	'G',
	'E'
};


/* Must have NULL termination */
static const kal_uint16 USB_PTP_IMAGE_MANUFACTURER_STRING[] = 
{
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
	'.',
	'\0'
};


/* Must have NULL termination */
static const kal_uint16 USB_PTP_IMAGE_MODEL_STRING[] = 
{
	'M',
	'T',
	'K',
	' ',
	'I',
	'M',
	'A',
	'G',
	'E',
	' ',
	'\0'
};


/* Must have NULL termination */
static const kal_uint16 USB_PTP_IMAGE_DEVICE_VERSION_STRING[] = 
{
	'1',
	'.',
	'0',
	'0',
	'\0'
};


/* Must have NULL termination */
static const kal_uint16 USB_PTP_IMAGE_SERIAL_NUMBER_STRING[] = 
{
	'5',
	'6',
	'7',
	'0',
	'7',
	'6',
	'6',
	'\0'
};


static const USB_IMAGE_PARAM usb_image_param =
{
	0x0005,			/* USB PTP image Product ID */
	USB_PTP_IMAGE_INTERFACE_STRING,
	sizeof(USB_PTP_IMAGE_INTERFACE_STRING)/sizeof(kal_uint16),
	USB_PTP_IMAGE_MANUFACTURER_STRING,
	sizeof(USB_PTP_IMAGE_MANUFACTURER_STRING)/sizeof(kal_uint16),
	USB_PTP_IMAGE_MODEL_STRING,
	sizeof(USB_PTP_IMAGE_MODEL_STRING)/sizeof(kal_uint16),
	USB_PTP_IMAGE_DEVICE_VERSION_STRING,
	sizeof(USB_PTP_IMAGE_DEVICE_VERSION_STRING)/sizeof(kal_uint16),
	USB_PTP_IMAGE_SERIAL_NUMBER_STRING,
	sizeof(USB_PTP_IMAGE_SERIAL_NUMBER_STRING)/sizeof(kal_uint16)
};

#endif /* PICTBRIDGE_SUPPORT */


#ifdef  __MTP_ENABLE__
/************************************************************
	MTP IMAGE parameters
*************************************************************/
static const kal_uint16 USB_MTP_IMAGE_INTERFACE_STRING[] = 
{
	0x0314,
	'I',
	'M',
	'A',
	'G',
	'E',
	' ',
	'M',
	'T',
	'P'
};

/* Must have NULL termination */
static const kal_uint16 USB_MTP_IMAGE_MANUFACTURER_STRING[] = 
{
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
	'.',
	' ',
	'M',
	'T',
	'P',	
	'\0'
};

/* Must have NULL termination */
static const kal_uint16 USB_MTP_IMAGE_MODEL_STRING[] = 
{
	'M',
	'T',
	'K',
	' ',
	'I',
	'M',
	'A',
	'G',
	'E',
	' ',
	'M',
	'T',
	'P',
	' ',
	'\0'
};


/* Must have NULL termination */
static const kal_uint16 USB_MTP_IMAGE_DEVICE_VERSION_STRING[] = 
{
	'2',
	'.',
	'0',
	'0',
	'\0'
};


/* USB flash disk, must have NULL termination */
static const kal_uint16 USB_MTP_IMAGE_STORAGE_DESCRIPTION_STRING_1[] = 
{
	'P',
	'h',
	'o',
	'n',
	'e',
	'\0'
};


/* USB card disk, must have NULL termination */
static const kal_uint16 USB_MTP_IMAGE_STORAGE_DESCRIPTION_STRING_2[] = 
{
	'C',
	'a',
	'r',
	'd',
	'\0'
};


/* Must have NULL termination */
static const kal_uint16 USB_MTP_IMAGE_DEVICE_FRIENDLY_NAME_DEFAULT_VALUE_STRING[] = 
{
	'M',
	'T',
	'K',
	' ',
	'P',
	'h',
	'o',
	'n',
	'e',
	'\0'
};


/* Must have NULL termination */
static const kal_uint16 USB_MTP_IMAGE_DEVICE_FRIENDLY_NAME_CURRENT_VALUE_STRING[] = 
{
	'M',
	'T',
	'K',
	' ',
	'P',
	'h',
	'o',
	'n',
	'e',
	'\0'
};


/* Must have NULL termination */
static const kal_uint16 USB_MTP_SYNCHRONIZATION_PARTNER_DEFAULT_VALUE_STRING[] = 
{
	'W', 
	'i', 
	'n', 
	'd', 
	'o', 
	'w', 
	's',
	' ',
	'M',
	'e',
	'd',
	'i',
	'a',
	' ',
	'P',
	'l',
	'a',
	'y',
	'e',
	'r',
	' ',
	'1',
	'1',
	'\0'
};


/* Must have NULL termination */
static const kal_uint16 USB_MTP_SYNCHRONIZATION_PARTNER_CURRENT_VALUE_STRING[] = 
{
	'W', 
	'i', 
	'n', 
	'd', 
	'o', 
	'w', 
	's',
	' ',
	'M',
	'e',
	'd',
	'i',
	'a',
	' ',
	'P',
	'l',
	'a',
	'y',
	'e',
	'r',
	' ',
	'1',
	'1',
	'\0'
};


static const USB_MTP_IMAGE_PARAM usb_mtp_image_param =
{
	0x0050,			/* USB MTP image Product ID */
	USB_MTP_IMAGE_INTERFACE_STRING,
	sizeof(USB_MTP_IMAGE_INTERFACE_STRING)/sizeof(kal_uint16),
	USB_MTP_IMAGE_MANUFACTURER_STRING,
	sizeof(USB_MTP_IMAGE_MANUFACTURER_STRING)/sizeof(kal_uint16),
	USB_MTP_IMAGE_MODEL_STRING,
	sizeof(USB_MTP_IMAGE_MODEL_STRING)/sizeof(kal_uint16),
	USB_MTP_IMAGE_DEVICE_VERSION_STRING,
	sizeof(USB_MTP_IMAGE_DEVICE_VERSION_STRING)/sizeof(kal_uint16),
	USB_MTP_IMAGE_STORAGE_DESCRIPTION_STRING_1,
	sizeof(USB_MTP_IMAGE_STORAGE_DESCRIPTION_STRING_1)/sizeof(kal_uint16),
	USB_MTP_IMAGE_STORAGE_DESCRIPTION_STRING_2,
	sizeof(USB_MTP_IMAGE_STORAGE_DESCRIPTION_STRING_2)/sizeof(kal_uint16),
	USB_MTP_IMAGE_DEVICE_FRIENDLY_NAME_DEFAULT_VALUE_STRING,
	sizeof(USB_MTP_IMAGE_DEVICE_FRIENDLY_NAME_DEFAULT_VALUE_STRING)/sizeof(kal_uint16),
	USB_MTP_IMAGE_DEVICE_FRIENDLY_NAME_CURRENT_VALUE_STRING,
	sizeof(USB_MTP_IMAGE_DEVICE_FRIENDLY_NAME_CURRENT_VALUE_STRING)/sizeof(kal_uint16),
	USB_MTP_SYNCHRONIZATION_PARTNER_DEFAULT_VALUE_STRING,
	sizeof(USB_MTP_SYNCHRONIZATION_PARTNER_DEFAULT_VALUE_STRING)/sizeof(kal_uint16),
	USB_MTP_SYNCHRONIZATION_PARTNER_CURRENT_VALUE_STRING,
	sizeof(USB_MTP_SYNCHRONIZATION_PARTNER_CURRENT_VALUE_STRING)/sizeof(kal_uint16)
};

#endif /* __MTP_ENABLE__ */



#if defined(__OTG_ENABLE__)||defined(__IC_USB_ENABLE__)

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
#else


#if defined(__OTG_ENABLE__)

/* Should put the default driver in the last line */
kal_uint8 USB_EXT_CLASS_DRV_WEIGHT_TBL[] =
{
	1,		/* MS drv */
#ifdef __USB_HOST_COM_PORT_SUPPORT__
	1,		/* CDC ACM drv */
#endif
	0		/* Default */
};

#endif

#endif

#if defined(__IC_USB_ENABLE__)

/* Should put the default driver in the last line */
kal_uint8 USB_INT_CLASS_DRV_WEIGHT_TBL[] =
{
	1,		/* MS drv */
	1,		/* ICCD drv */
	1,		/* EEM drv */
	0		/* Default */
};

#endif


/*
1. If "current_follow_spec" is TRUE means only current value <= g_otg_support_max_power will be checked,
    if it is FALSE. then we will first choose the configuration with max weight number, and then choose a current the which is the most nearnest to the g_otg_support_max_power

2. If all class driver are with the same weight, we will choose the configuration which matches the most class drivers
 */


static const USB_HOST_MATCH_PARAM usb_host_match_rule_param =
{
#if defined(__OTG_ENABLE__)
	USB_EXT_CLASS_DRV_WEIGHT_TBL,
	sizeof(USB_EXT_CLASS_DRV_WEIGHT_TBL)/sizeof(kal_uint8),
#endif
#if defined(__IC_USB_ENABLE__)
	USB_INT_CLASS_DRV_WEIGHT_TBL,
	sizeof(USB_INT_CLASS_DRV_WEIGHT_TBL)/sizeof(kal_uint8),
#endif
	KAL_FALSE
};

static const USB_HOST_COMMON_PARAM usb_host_common_param =
{
	KAL_TRUE, 	 //support_HNP;
	KAL_TRUE,    //support SRP;
	KAL_TRUE, 	 //support_Remote_Wakeup;
	KAL_TRUE, 	 //support_Double_FIFO;	
	16	 //HS ep0 interval;  max value is 16, 16 stands for 4 seconds,FS value is (HS-3)
};


#endif /* #if defined(__OTG_ENABLE__)||defined(__IC_USB_ENABLE__) */
/************************************************************
	customization functinos
*************************************************************/

/* get general USB device parameter function*/
const USB_DEVICE_PARAM *USB_GetDeviceParam(void)
{
	return (&usb_device_param);
}

/* get mass storage USB device parameter function*/
const USB_MS_PARAM *USB_GetMsParam(void)
{
	return (&usb_ms_param);
}

/* get CDC ACM USB device parameter function*/
const USB_ACM_PARAM *USB_GetAcmParam(void)
{
	return (&usb_acm_param);
}

#ifdef WEBCAM_SUPPORT
/* get VIDEO USB device parameter function*/
const USB_VIDEO_PARAM *USB_GetVideoParam(void)
{
	return (&usb_video_param);
}
#endif /* WEBCAM_SUPPORT */

#ifdef PICTBRIDGE_SUPPORT
/* get IMAGE USB device parameter function*/
const USB_IMAGE_PARAM *USB_GetImageParam(void)
{
	return (&usb_image_param);
}
#endif /* PICTBRIDGE_SUPPORT */


#ifdef __MTP_ENABLE__
/* get IMAGE USB device parameter function*/
const USB_MTP_IMAGE_PARAM *USB_MTP_GetImageParam(void)
{
	return (&usb_mtp_image_param);
}
#endif /* __MTP_ENABLE__ */

#if defined(__OTG_ENABLE__)||defined(__IC_USB_ENABLE__)

const USB_HOST_MATCH_PARAM *USB_Host_GetMatchParam(void)
{
	return (&usb_host_match_rule_param);
}

const USB_HOST_COMMON_PARAM *USB_Host_GetCommonParam(void)
{
	return (&usb_host_common_param);
}

#endif


/* get USB custom parameter function*/
static const USB_CUSTOM_FUNC USB_CustomFunc = 
{
	USB_GetDeviceParam,
	USB_GetMsParam,
	USB_GetAcmParam,
#ifdef WEBCAM_SUPPORT	
	USB_GetVideoParam,
#endif
#ifdef PICTBRIDGE_SUPPORT
	USB_GetImageParam,
#endif
#ifdef __MTP_ENABLE__
	USB_MTP_GetImageParam,
#endif
#if defined(__OTG_ENABLE__)||defined(__IC_USB_ENABLE__)
	USB_Host_GetMatchParam,
	USB_Host_GetCommonParam
#endif
};

const USB_CUSTOM_FUNC* USB_GetCustomFunc(void)
{
	return(&USB_CustomFunc);
}

/* power control function, enable == KAL_TRUE turn on the power*/
void USB_PowerControl(kal_bool enable)
{
#ifdef __USB_ENABLE__
	DCL_HANDLE handle;
	PMU_CTRL_LDO_BUCK_SET_EN val;
	
	if(enable == KAL_FALSE)
		return;	
		
	val.enable=enable;
	val.mod=VUSB;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
#endif   /*__USB_ENABLE__*/
}


#ifdef __OTG_ENABLE__
const kal_uint16 g_otg_support_max_power = 100; /*mA*/
const kal_bool OTG_IDPIN_CABLE_PLUGIN_LEVEL = LEVEL_LOW;

kal_uint16 USBD_Get_Max_Power(void)
{
	return 	g_otg_support_max_power;
}
#endif

//#if defined(__OTG_ENABLE__)
	// When OTG is enabled, we must set this to FALSE, or we may impact OTG functionality while charging
//const kal_bool usb_default_charge = KAL_FALSE;
//#else // #if defined(__OTG_ENABLE__)
//const kal_bool usb_default_charge = KAL_TRUE;
//#endif // #if defined(__OTG_ENABLE__)


kal_bool USB_Default_Charging(void)
{
// const kal_bool usb_default_charge
#if defined(__OTG_ENABLE__)	                          
	return KAL_FALSE; // When OTG is enabled, we must set this to FALSE, or we may impact OTG functionality while charging
#endif		
		
#if defined(__USB_COMPLIANCE_CHARGE__)
	return KAL_FALSE; // follow USB spec : only after set Configuration, USB can drag 500mA current
#endif

	return KAL_TRUE; // no matter what, USB cable in will drag 500mA current
}

/************************************************************
	customization functinos
*************************************************************/
void USB_Connect_R_To_DM_Control(kal_bool enable)
{
	/*******************************************************
	* This function only used in 6219/6227/6225/6228/6229/6235.
	* 
	* If you want to use it, please define 
	* DRV_PHY_CHARGER_DETECT_BY_EXTERNAL_R in project makefile
	********************************************************/
	
#ifdef DRV_PHY_CHARGER_DETECT_BY_EXTERNAL_R
#ifdef __CUST_NEW__
	if(enable == KAL_TRUE)
		GPIO_WriteIO(1, gpio_usb_chr_det_switch_pin);
	else
		GPIO_WriteIO(0, gpio_usb_chr_det_switch_pin);
#endif /* __CUST_NEW__ */
#endif /* DRV_PHY_CHARGER_DETECT_BY_EXTERNAL_R */

}


void custom_usb_ms_init(void)
{
#ifndef __UBL__
#if defined(__USB_ENABLE__)&&defined(__USB_MASS_STORAGE_ENABLE__)
	#if ((defined(__MSDC_MS__))||(defined(__MSDC_MSPRO__))||(defined(__MSDC_SD_MMC__)) )
		#ifdef __SIM_PLUS__
	if(g_usb_ms_simplus_exist == KAL_TRUE)
	{
		USB_Ms_Register_DiskDriver(&USB_SIMPLUS_drv);
	}
		#endif
	USB_Ms_Register_DiskDriver(&USB_MSDC_drv);
	#ifdef __MSDC_DUAL_CARD_SWITCH__
	USB_Ms_Register_DiskDriver(&USB_tCard_2_drv);
	#endif
	#endif

	#ifdef __USB_RAMDISK__
	USB_Ms_Register_DiskDriver(&USB_RAM_drv);
	#endif

	#if (!defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_))
	if(FS_GetDevPartitions(FS_DEVICE_TYPE_NOR) >= 2)
	{
		USB_Ms_Register_DiskDriver(&USB_NOR_drv);
	}
	#endif

	//#if defined(NAND_SUPPORT)&&(!defined(__USB_MODEM_CARD_SUPPORT__))
	#if defined(NAND_SUPPORT)
	if(FS_GetDevPartitions(FS_DEVICE_TYPE_NAND) >= 2)
	{
		USB_Ms_Register_DiskDriver(&USB_NAND_drv);
	}
	else if (FS_GetDevPartitions(FS_DEVICE_TYPE_NAND) == 1)
	{
		#if (!defined(__FS_SYSDRV_ON_NAND__))
		USB_Ms_Register_DiskDriver(&USB_NAND_drv);
		#endif
	}
	#endif
	
	#if (!defined(__FS_SYSDRV_ON_NAND__) && !defined( _NAND_FLASH_BOOTING_)&&!defined(__EMMC_BOOTING__))||defined(NAND_SUPPORT)
		#if defined(__USB_MASS_STORAGE_CDROM_ENABLE__)
			USB_Ms_Set_Current_Driver(LOGIC_DRIVE_CDROM);
			USB_Ms_Register_DiskDriver(&USB_CDROM_drv);
			USB_Ms_Set_Current_Driver(LOGIC_DRIVE_MS); //always swith current drive to MS
			#if !(defined(__USB_MODEM_CARD_SUPPORT__)||defined(__USB_DATA_CONNECTION__))
			//modem_card and data_connect do not support CD-ROM in LOGIC_DRIVE_MS
			USB_Ms_Register_DiskDriver(&USB_CDROM_drv);
			#endif
		#endif
	#endif
#endif   /*__USB_ENABLE__*/
#endif	/*__UBL__*/
}

