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
 *    usb_comm.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for usb common definitions.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef USB_COMM_H
#define USB_COMM_H


#include "kal_general_types.h"

/* Define usb device type */
typedef enum 
{
	USB_UNKOWN=0,
	USB_CDC_ACM,
	USB_MASS_STORAGE,
	USB_VIDEO,
	USB_COMPOSITE_VIDEO_COM,	
	USB_STOP_MS,
	USB_CDC_ACM_LOGGING,
	USB_IMAGE,
	USB_IMAGE_MTP,
	USB_STOP_MTP,
	USB_COMPOSITE_MULTI_COM,
	USB_RNDIS,		
	USB_COMPOSITE_RNDIS_COM,
	USB_MASS_STORAGE_CDROM_ONLY,
	USB_CANNOT_CONFIG,
	USB_DATA_CONNECTION,
	USB_DATA_CONNECTION_COM,
	USB_COMPOSITE_DEVICES,
	USB_MAX_DEVICE_TYPE
} USB_DEVICE_TYPE;

typedef enum 
{
	USB_COMP_UNKOWN=0,
	USB_COMP_CDC_ACM,
	USB_COMP_CDC_ACM2,
	USB_COMP_CDC_ACM3,
	USB_COMP_MBIM,
	USB_COMP_SI_CDC_ACM,	 //Single Interface CDCACM
	USB_COMP_SI_CDC_ACM2,	 //Single Interface CDCACM
	USB_COMP_REDUCED_CDC_ACM2, //Reduced CDCACM (without INTR pipe)
	USB_COMP_REDUCED_CDC_ACM3, //Reduced CDCACM (without INTR pipe)
	USB_COMP_REDUCED_CDC_ACM4, //Reduced CDCACM (without INTR pipe)
	USB_COMP_REDUCED_CDC_ACM5, //Reduced CDCACM (without INTR pipe)
	USB_COMP_MASS_STORAGE,
	USB_COMP_MAX_DEVICE_TYPE
} USB_COMPOSITE_DEVICE_TYPE;

extern kal_bool USB_GetCableStatus(void);


#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
	#ifdef __USB_MODEM_CARD_SUPPORT__
	#define MAX_USB_PORT_NUM						5
	#else
	#define MAX_USB_PORT_NUM						2
	#endif
#else
#define MAX_USB_PORT_NUM						1
#endif


#endif  /* USB_COMM_H */                   

