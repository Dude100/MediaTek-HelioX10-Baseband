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
*  A. Patent Notice:
*  The software delivered hereunder, including any and all updates and upgrades, 
*  might be subject to patent rights of standard-setting organizations, patent pools 
*  or their respective patent owners, that will be necessarily infringed by the use 
*  and distribution of the products incorporating all or part of this software.  
*  According to the licensing terms of these patent holders, it is your sole 
*  obligation to obtain the necessary patent licenses from these patent holders 
*  before you can use or distribute the products incorporating all or part of this 
*  software. MediaTek shall not be liable for your failure to obtain or maintain such 
*  licenses.
*  
*    As a courtesy to our customers, the following are some of the software that might 
*    contain such patent licenses, but MediaTek does not warrant the accuracy or
*    completeness of the information below.  
*    (1) MPEG4/AAC/AACPLUS/AACVPLUSV2: essential patents license must be obtained
*        from Via Licensing: <www.vialicensing.com>
*    (2) WAP/MMS security RC5 algorithm belongs to RSA Data Security: 
*        <www.rsasecurity.com> 
*    Notice: Please contact RSA to get this license before shipping the products to 
*    USA which include RC5 security algorithm.
*  
*  B. In addition, customers must contact the respective licensors to obtain 
*  necessary software licenses before it can use or distribute the licensed 
*  products. 
*  
*    As a courtesy to our customers, the following are some of the software licensers 
*    and the notice or disclaimer required by their licenses, but MediaTek does not 
*    warrant the accuracy or completeness of the information below.  
*    (1) Microsoft Windows Media (WMA software): 
*        Microsoft: <www.microsoft.com> 
*        Approved OEM Manufacturers: <wmlicense.smdisp.net/oem_approved/>
*        Sample Windows Media Licensing Agreements: 
*        <www.microsoft.com/windows/windowsmedia/licensing/agreements.aspx>
*    Notice in header or documentation: "This product is protected by certain 
*    intellectual property rights of Microsoft and cannot be used or further 
*    distributed without a license from Microsoft."
*    
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   usbimage_mtp_state.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements the MEDIA TRANSFER PROTOCOL (MTP) definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef USB_IMAGE_MTP_STATE_H
#define USB_IMAGE_MTP_STATE_H

//#include "kal_non_specific_general_types.h"
#include "usbimage_drv.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"


/***********************************************
	PTP/MTP specific command definitions
************************************************/
/* Operation Codes */
#define MTP_GET_DEVICE_INFO				0x1001
#define MTP_OPEN_SESSION					0x1002
#define MTP_CLOSE_SESSION					0x1003
#define MTP_GET_STORAGE_IDS				0x1004
#define MTP_GET_STORAGE_INFO				0x1005
#define MTP_GET_NUM_OBJECTS				0x1006
#define MTP_GET_OBJECT_HANDLES			0x1007
#define MTP_GET_OBJECT_INFO				0x1008
#define MTP_GET_OBJECT						0x1009
#define MTP_DELETE_OBJECT					0x100B
#define MTP_SEND_OBJECT_INFO				0x100C
#define MTP_SEND_OBJECT					0x100D

#define MTP_FORMAT_STORE					0x100F
#define MTP_RESET_DEVICE					0x1010
#define MTP_SET_OBJECT_PROTECTION			0x1012

#define MTP_GET_DEVICE_PROP_DESC			0x1014
#define MTP_GET_DEVICE_PROP_VALUE		0x1015
#define MTP_SET_DEVICE_PROP_VALUE			0x1016

#define MTP_RESET_DEVICE_PROP_VALUE		0x1017

#define MTP_GET_PARTIAL_OBJECT			0x101B

/* MTP only */
#define MTP_GET_OBJECT_PROPS_SUPPORTED		0x9801
#define MTP_GET_OBJECT_PROP_DESC				0x9802
#define MTP_GET_OBJECT_PROP_VALUE			0x9803
#define MTP_SET_OBJECT_PROP_VALUE				0x9804

#define MTP_GET_OBJECT_PROP_LIST				0x9805
#define MTP_SET_OBJECT_PROP_LIST				0x9806
#define MTP_GET_INTER_DEPENDENT_PROP_DESC	0x9807
#define MTP_SEND_OBJECT_PROP_LIST				0x9808


#define MTP_GET_OBJECT_REFERENCES				0x9810
#define MTP_SET_OBJECT_REFERENCES				0x9811
#define MTP_SKIP								0x9820


/* DRM only */
#define MTP_GET_SECURE_TIME_CHALLENGE		0x9101
#define MTP_SET_SECURE_TIME_RESPONSE			0x9102
#define MTP_SET_LICENSE_RESPONSE				0x9103
#define MTP_GET_SYNC_LIST						0x9104
#define MTP_SEND_METER_CHALLENGE_QUERY		0x9105
#define MTP_GET_METER_CHALLENGE				0x9106
#define MTP_SET_METER_RESPONSE				0x9107
#define MTP_CLEAN_DATA_STORE					0x9108
#define MTP_GET_LICENSE_STATE					0x9109
#define MTP_DRM_CMD_1							0x910A
#define MTP_DRM_CMD_2							0x910B
#define MTP_DRM_CMD_3							0x9001
#define MTP_DRM_CMD_4							0x9002




/* Response Codes */
#define MTP_OK								0x2001
#define MTP_GENERAL_ERROR					0x2002
#define MTP_SESSION_NOT_OPEN				0x2003
#define MTP_OPERATION_NOT_SUPPORTED		0x2005	
#define MTP_PARAMETER_NOT_SUPPORTED		0x2006
#define MTP_NO_THUMBNAIL_PRESENT			0x2010
#define MTP_STORE_NOT_AVAILABLE			0x2013
#define MTP_DEVICE_BUSY					0x2019
#define MTP_SESSION_ALREADY_OPEN			0x201E
#define MTP_TRANSACTION_CANCELLED		0x201F




/* Event Codes */
#define MTP_CANCEL_TRANSACTION			0x4001
#define MTP_OBJECT_ADDED					0x4002
#define MTP_OBJECT_REMOVED				0x4003
#define MTP_STORE_ADDED					0x4004
#define MTP_STORE_REMOVED					0x4005
#define MTP_DEVICE_PROP_CHAGNED			0x4006
#define MTP_OBJECT_INFO_CHAGNED			0x4007
#define MTP_REQUEST_OBJECT_TRANSFER		0x4009
#define MTP_DEVICE_RESET					0x400B
#define MTP_STORAGE_INFO_CHANGED			0x400C


/* Object Format Codes */
#define MTP_UNDEFINED						0x3000
#define MTP_ASSOCIATION					0x3001
#define MTP_SCRIPT							0x3002
#define MTP_DPOF							0x3006
#define MTP_MP3								0x3009
#define MTP_ASF								0x300C
#define MTP_DEFINED							0x3800
#define MTP_EXIF_JPEG						0x3801
#define MTP_TIFF_EP							0x3802
#define MTP_BMP								0x3804
#define MTP_CIFF							0x3805
#define MTP_GIF								0x3807
#define MTP_JFIF								0x3808
#define MTP_PNG								0x380B
#define MTP_TIFF							0x380D
#define MTP_TIFF_IT							0x380E
#define MTP_WMA							0xB901
#define MTP_WMV							0xB981
#define MTP_ABSTRACT_AUDIO_ALBUM			0xBA03
#define MTP_ABSTRACT_AUDIOVIDEO_PLAYLIST	0xBA05

/* Device Properties Codes */
#define MTP_BATTERY_LEVEL					0x5001
#define MTP_DATE_TIME						0x5011
#define MTP_SYNCHRONIZATION_PARTNER		0xD401
#define MTP_DEVICE_FRIENDLY_NAME			0xD402
#define MTP_VOLUME							0xD403
#define MTP_DEVICELCON						0xD405
#define MTP_SESSION_INITIATOR_VERSION_INFO	0xD406
#define MTP_PLAYBACK_RATE					0xD410
#define MTP_PLAYBACK_OBJECT				0xD411
#define MTP_PLAYBACK_CONTAINER_INDEX		0xD412

/* DRM only */
#define MTP_SECURE_TIME					0xD101
#define MTP_DEVICE_CERIFICATE				0xD102



/* VenderExtensionID */
#define MTP_VENDER_EXTENSION_ID_093		0x00000006
#define MTP_VENDER_EXTENSION_ID_10		0xFFFFFFFF

/* Functional Mode Values*/
#define MTP_STANDARD_MODE					0x0000
#define MTP_SLEEP_STATE					0x0001

/*  ObjectInfo ProtectionStatus Values*/
#define MTP_NO_PROTECTION					0x0000
#define MTP_READ_ONLY						0x0001

/*  Storage Types */
#define MTP_FIXED_ROM						0x0001
#define MTP_REMOVABLE_ROM					0x0002
#define MTP_FIXED_RAM						0x0003
#define MTP_REMOVABLE_RAM					0x0004

/* File System Type Values */
#define MTP_GENERIC_FLAT					0x0001
#define MTP_GENERIC_HIERARCHICAL			0x0002
#define MTP_DCF								0x0003

/*  StorageInfo AccessCapability Values */
#define MTP_READ_WRITE						0x0000
#define MTP_READ_ONLY_WITHOUT_DELETION	0x0001
#define MTP_READ_ONLY_WITH_DELETION		0x0002

/* Association Types */
#define MTP_GENERIC_FOLDER					0x0001
#define MTP_ALBUM							0x0002
#define MTP_TIME_SEQUENCE					0x0003
#define MTP_HORIZONTAL_PANORAMIC			0x0004
#define MTP_VERTICAL_PANORAMIC			0x0005
#define MTP_2D_PANORAMIC					0x0006
#define MTP_ANCILLARY						0x0007

/***********************************************
	Implement definition
************************************************/
#define MTP_MAX_OPERATION_CODE_SIZE				21
//#define MTP_MAX_OPERATION_CODE_SIZE				35

#define MTP_MAX_EVENT_CODE_SIZE					4

//#define MTP_MAX_DEVICE_PROPERTIES_SUPPORTED_SIZE	7
#define MTP_MAX_DEVICE_PROPERTIES_SUPPORTED_SIZE	2

//#define MTP_MAX_PLAYBACK_FORMAT_CODE_SIZE			7
#define MTP_MAX_PLAYBACK_FORMAT_CODE_SIZE			2


/***********************************************
	Implement enum and structure 
************************************************/
typedef struct
{
	kal_uint16	StandardVersion;
	kal_uint16	VenderExtensionID[2];
	kal_uint16	VenderExtensionVersion;
	kal_uint8		VendorExtensionDescNum;
	kal_uint8		VendorExtensionDescString[29][2];
	kal_uint8 	FunctionalMode[2];
	kal_uint8	       OperationsSupportedSize[4];
	kal_uint8		OperationsSupported[MTP_MAX_OPERATION_CODE_SIZE][2];
	kal_uint8		EventsSupportedSize[4];
	kal_uint8		EventsSupported[MTP_MAX_EVENT_CODE_SIZE][2];
	kal_uint8		DevicePropertiesSupportedSize[4];
	kal_uint8		DevicePropertiesSupported[MTP_MAX_DEVICE_PROPERTIES_SUPPORTED_SIZE][2];
	kal_uint8		CaptureFormatsSize[4];				/* empty array*/
	kal_uint8		PlaybackFormatsSize[4];
	kal_uint8		PlaybackFormats[MTP_MAX_PLAYBACK_FORMAT_CODE_SIZE][2];
//	kal_uint8		padding;
}MTP_DeviceInfo_Struct;


typedef struct
{
	kal_uint16	DevicePropertyCode;
	kal_uint16	DataType;
	kal_uint8		GetSet;
}MTP_DeviceProperty_Struct;



typedef struct
{
	kal_uint16	StorageType;
	kal_uint16	FilesystemType;
	kal_uint16	AccessCapability;
	kal_uint16	MaxCapacity[4];
	kal_uint16	FreeSpaceInBytes[4];
	kal_uint16	FreeSpaceInImages[2];
}MTP_StorageInfo_Struct;


typedef struct
{
	kal_uint32	StorageID;
	kal_uint16	ObjectFormat;
	kal_uint16	ProtectionStatus;
	kal_uint32	ObjectCompressedSize;
	kal_uint16	ThumbFormat;
	kal_uint16	ThumbCompressedSize[2];
	kal_uint16	ThumbPixWidth[2];
	kal_uint16	ThumbPixHeight[2];
	kal_uint16	ImagePixWidth[2];
	kal_uint16	ImagePixHeight[2];
	kal_uint16	ImageBitDepth[2];
	kal_uint16	ParentObject[2];
	kal_uint16	AssociationType;
	kal_uint32	AssociationDesc;
	kal_uint32	SequenceNumber;
}MTP_ObjectInfo_Struct;


typedef struct
{
	/* PTP dataset structure */
	MTP_DeviceInfo_Struct			image_deviceinfo;
	kal_bool						is_wait_host_respone;
}USB_IMAGE_MTP_Struct;


/***********************************************
	function and global variable
************************************************/
extern USB_IMAGE_MTP_Struct g_MTPImage;
extern USB_IMAGE_CONTAINER_HEADER g_USB_Image_Data_Header;

extern kal_bool USB_MTP_Is_RX_Cmd(kal_uint16 cmd_code);

extern void USB_MTP_Parse_MTP_Meg(ilm_struct *p_recv_ilm);
extern void USB_MTP_Parse_MTP_Event_Meg(ilm_struct *p_recv_ilm);
extern void USB_MTP_Parse_USB_Meg(ilm_struct *p_recv_ilm);


#endif /* USB_IMAGE_MTP_STATE_H */


