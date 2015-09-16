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
 *    usb_memory_def.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *    This file intends for usb memory usage calculation.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef USB_MEMORY_H
#define USB_MEMORY_H


#include "usb_custom_def.h"


//===================== Single Feature Set ===================//
#ifdef  __USB_MASS_STORAGE_ENABLE__
#define USB_MS_FUNCTION_SIZE 	 (USBMS_MAX_BUFFERSIZE)
#else
#define USB_MS_FUNCTION_SIZE 	 0
#endif

#ifdef __MTP_ENABLE__
#define USB_MTP_FUNCTION_SIZE 	 (USB_IMAGE_MTP_MAX_BUFFERSIZE)
#else
#define USB_MTP_FUNCTION_SIZE 	 0
#endif

#ifdef __USB_COM_PORT_ENABLE__
#define USB_COM_FUNCTION_SIZE 	 ((USB_ACM_RX_BUFFER_NUM*USB_ACM_RX_BUFFER_SIZE)+USB_RX_RING_BUFFER_1_SIZE+USB_TX_RING_BUFFER_1_SIZE+USB_TXISR_RING_BUFFER_SIZE)
#else
#define USB_COM_FUNCTION_SIZE 	 0
#endif

#ifdef WEBCAM_SUPPORT
#define USB_WEBCAM_FUNCTION_SIZE 	 (USBVIDEO_MAX_PAYLOAD_LENGTH)
#else
#define USB_WEBCAM_FUNCTION_SIZE 	 0
#endif

#ifdef __USB_TETHERING__
#define USB_ISD_FUNCTION_SIZE 	 (USB_ISD_EP0_BUFFER_LENGTH)
#else
#define USB_ISD_FUNCTION_SIZE 	 0
#endif



//================== Calculation =====================//

#if USB_MS_FUNCTION_SIZE > USB_MTP_FUNCTION_SIZE
	#define USB_MAX_STEMP1 	USB_MS_FUNCTION_SIZE
#else
	#define USB_MAX_STEMP1 	USB_MTP_FUNCTION_SIZE
#endif

#if USB_COM_FUNCTION_SIZE > USB_WEBCAM_FUNCTION_SIZE
	#define USB_MAX_STEMP2 	USB_COM_FUNCTION_SIZE
#else
	#define USB_MAX_STEMP2 USB_WEBCAM_FUNCTION_SIZE
#endif


#if USB_MAX_STEMP1 > USB_MAX_STEMP2
	#define USB_MAX_STEMP3 	USB_MAX_STEMP1
#else
	#define USB_MAX_STEMP3 	USB_MAX_STEMP2
#endif


#if USB_MAX_STEMP3 > USB_ISD_FUNCTION_SIZE
	#define USB_MAX_STEMP4 	USB_MAX_STEMP3
#else
	#define USB_MAX_STEMP4 	USB_ISD_FUNCTION_SIZE
#endif


// single function max size
#define USB_MAX_SINGLE_TEMP  USB_MAX_STEMP4


#ifndef __USB_COMPOSITE_DEVICE_SUPPORT__
#define USB_MAX_MEMORY_SIZE		(USB_MAX_SINGLE_TEMP + USB_DESCRIPTOR_SIZE)
#endif


//===================== Composite Feature Set ==============================//
#ifdef __USB_COMPOSITE_DEVICE_SUPPORT__


#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
#define USB_2COM_FUNCTION_SIZE 	 (USB_COM_FUNCTION_SIZE+USB_RX_RING_BUFFER_2_SIZE+USB_TX_RING_BUFFER_2_SIZE)
#ifdef __USB_MODEM_CARD_SUPPORT__  
#define USB_5COM_FUNCTION_SIZE 	 (USB_COM_FUNCTION_SIZE+USB_RX_RING_BUFFER_2_SIZE+USB_TX_RING_BUFFER_2_SIZE+USB_RX_RING_BUFFER_3_SIZE+USB_TX_RING_BUFFER_3_SIZE+USB_RX_RING_BUFFER_4_SIZE+USB_TX_RING_BUFFER_4_SIZE+USB_RX_RING_BUFFER_5_SIZE+USB_TX_RING_BUFFER_5_SIZE)
#endif
#else
#define USB_2COM_FUNCTION_SIZE 	 0
#endif


#ifdef __COMPOSITE_WEBCAM__
#define USB_WEBCAM_COM_FUNCTION_SIZE 	 (USBVIDEO_MAX_PAYLOAD_LENGTH+USB_COM_FUNCTION_SIZE)
#else
#define USB_WEBCAM_COM_FUNCTION_SIZE 	 0
#endif

#if defined(__USB_TETHERING__)&&defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
#define USB_ISD_COM_FUNCTION_SIZE 	 (USB_ISD_EP0_BUFFER_LENGTH + USB_COM_FUNCTION_SIZE)
#else
#define USB_ISD_COM_FUNCTION_SIZE 	 0
#endif

#ifdef __COMPOSITE_MS__  // MS+COM temp name
#define USB_MS_COM_FUNCTION_SIZE 	 (USBMS_MAX_BUFFERSIZE + USB_COM_FUNCTION_SIZE)
#else
#define USB_MS_COM_FUNCTION_SIZE	 0
#endif

#ifdef __USB_MODEM_CARD_SUPPORT__ //MS+2COM
#define USB_MS_2COM_FUNCTION_SIZE	 (USBMS_MAX_BUFFERSIZE + USB_2COM_FUNCTION_SIZE)
#else
#define USB_MS_2COM_FUNCTION_SIZE	 0
#endif

#ifdef __USB_MODEM_CARD_SUPPORT__  //MT6280 temp name
#define USB_MS_5COM_FUNCTION_SIZE	 (USBMS_MAX_BUFFERSIZE + USB_5COM_FUNCTION_SIZE)
#else
#define USB_MS_5COM_FUNCTION_SIZE	 0
#endif


#ifdef __USB_MODEM_CARD_SUPPORT__ // 3 COM
#define USB_3COM_FUNCTION_SIZE 	 (USB_2COM_FUNCTION_SIZE + USB_RX_RING_BUFFER_3_SIZE+USB_TX_RING_BUFFER_3_SIZE)
#else
#define USB_3COM_FUNCTION_SIZE 	 0
#endif


//================== Calculation =====================//

#if USB_2COM_FUNCTION_SIZE > USB_3COM_FUNCTION_SIZE
	#define USB_MAX_MTEMP1 	USB_2COM_FUNCTION_SIZE
#else
	#define USB_MAX_MTEMP1 	USB_3COM_FUNCTION_SIZE
#endif

#if USB_WEBCAM_COM_FUNCTION_SIZE > USB_ISD_COM_FUNCTION_SIZE
	#define USB_MAX_MTEMP2 	USB_WEBCAM_COM_FUNCTION_SIZE
#else
	#define USB_MAX_MTEMP2 	USB_ISD_COM_FUNCTION_SIZE
#endif


#if USB_MS_COM_FUNCTION_SIZE > USB_MS_2COM_FUNCTION_SIZE
	#define USB_MAX_MTEMP3 	USB_MS_COM_FUNCTION_SIZE
#else
	#define USB_MAX_MTEMP3 	USB_MS_2COM_FUNCTION_SIZE
#endif


#if USB_MAX_MTEMP1 > USB_MAX_MTEMP2
	#define USB_MAX_MTEMP4 	USB_MAX_MTEMP1
#else
	#define USB_MAX_MTEMP4 	USB_MAX_MTEMP2
#endif


#if USB_MAX_MTEMP4 > USB_MAX_MTEMP3
	#define USB_MAX_MTEMP5 	USB_MAX_MTEMP4
#else
	#define USB_MAX_MTEMP5 	USB_MAX_MTEMP3
#endif


#if USB_MAX_MTEMP5 > USB_MS_5COM_FUNCTION_SIZE
	#define USB_MAX_MTEMP6 	USB_MAX_MTEMP5
#else
	#define USB_MAX_MTEMP6 	USB_MS_5COM_FUNCTION_SIZE
#endif


// composite device max size
#define USB_MAX_MULTI_TEMP  USB_MAX_MTEMP6


// compare single function and multi function max size
#if USB_MAX_MULTI_TEMP > USB_MAX_SINGLE_TEMP
	#define USB_MAX_MEMORY_SIZE		(USB_MAX_MULTI_TEMP+ (USB_DESCRIPTOR_SIZE * 5))
#else	
	#define USB_MAX_MEMORY_SIZE		(USB_MAX_SINGLE_TEMP+ USB_DESCRIPTOR_SIZE)
#endif


#endif  //__USB_COMPOSITE_DEVICE_SUPPORT__




#endif //USB_MEMORY_H
