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
 *    usb_custom_def.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file declares usb customization definitions
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



/* USB VID */
#define MTK_USB_VID						(0x0e8d)


/*********************************************/
/*        Device Common                      */
/*********************************************/
#define USB_DESCRIPTOR_SIZE 		512

/*********************************************/
/*             CDC ACM Buffer Size           */
/*********************************************/
#if defined(__HSUPA_SUPPORT__)|| defined(__HSDPA_SUPPORT__)
	#define	USB_TX_RING_BUFFER_1_SIZE			(16*2048)
	#define	USB_TX_RING_BUFFER_2_SIZE			(16*2048)
	#define	USB_TX_RING_BUFFER_3_SIZE			(16*2048)
	#define	USB_TX_RING_BUFFER_4_SIZE			(16*2048)
	#define	USB_TX_RING_BUFFER_5_SIZE			(16*2048)
	#define	USB_TXISR_RING_BUFFER_SIZE		(4*3072)
#elif defined(__EGPRS_MODE__)
	#define	USB_TX_RING_BUFFER_1_SIZE			(4*2048)
	#define	USB_TX_RING_BUFFER_2_SIZE			(4*2048)
	#define	USB_TX_RING_BUFFER_3_SIZE			(4*2048)
	#define	USB_TX_RING_BUFFER_4_SIZE			(4*2048)
	#define	USB_TX_RING_BUFFER_5_SIZE			(4*2048)
	#define	USB_TXISR_RING_BUFFER_SIZE		(3072)
#else
	#define	USB_TX_RING_BUFFER_1_SIZE			(2048)
	#define	USB_TX_RING_BUFFER_2_SIZE			(2048)
	#define	USB_TX_RING_BUFFER_3_SIZE			(2048)
	#define	USB_TX_RING_BUFFER_4_SIZE			(2048)
	#define	USB_TX_RING_BUFFER_5_SIZE			(2048)
	#define	USB_TXISR_RING_BUFFER_SIZE		(3072)
#endif

#define	USB_RX_RING_BUFFER_1_SIZE				(2048)
#define	USB_RX_RING_BUFFER_2_SIZE				(2048)
#define	USB_RX_RING_BUFFER_3_SIZE				(2048)
#define	USB_RX_RING_BUFFER_4_SIZE				(2048)
#define	USB_RX_RING_BUFFER_5_SIZE				(2048)

#ifdef  __USB_HIGH_SPEED_COM_PORT_ENABLE__
// high speed interface RX buffer
#define USB_ACM_RX_BUFFER_NUM  					8   
#define USB_ACM_RX_BUFFER_SIZE 					3072
#else
#define USB_ACM_RX_BUFFER_NUM  					0   
#define USB_ACM_RX_BUFFER_SIZE 					0
#endif

/*********************************************/
/*        Mass Storage Buffer Size           */
/*********************************************/
#if defined(__LOW_COST_SUPPORT_ULC__)
#define USBMS_MAX_BUFFERSIZE     		(4*1024)
#elif (defined(__LOW_COST_SUPPORT_COMMON__)&&(!defined(__USB_HS_ENABLE__)))
#define USBMS_MAX_BUFFERSIZE     		(8*1024)
#else
#define USBMS_MAX_BUFFERSIZE     		(128*1024)
#endif

/*********************************************/
/*        MTP Buffer Size           */
/*********************************************/
#define USB_IMAGE_MTP_MAX_BUFFERSIZE     				USBMS_MAX_BUFFERSIZE 

/*********************************************/
/*        Webcam                             */
/*********************************************/
#ifdef  __WEBCAM_SUPPORT_ISO_PIPE__
#define USBVIDEO_MAX_PAYLOAD_LENGTH				512
#else
#define USBVIDEO_MAX_PAYLOAD_LENGTH				1024
#endif

/*********************************************/
/*        Tethering EP0 Buffer                             */
/*********************************************/
#define USB_ISD_EP0_BUFFER_LENGTH				64

/*********************************************/
/*        Host Common                      */
/*********************************************/
#define USBD_MAX_CFG_NUM			8
#define USBD_MAX_IF_PER_CFG		4

/*********************************************/
/*        Host Class Drivers                      */
/*********************************************/
#define USB_HOST_MAX_MS_NUM				1
#define USB_HOST_MS_SUPPORT_LUN  		8
#define USB_HOST_MS_MAX_DATA_LENGTH 	(32*1024)
#define USB_HOST_MS_ERROR_COUNT  		3
#define USB_HOST_MS_SLEEP_TIME  		0x00FF


#ifdef __IC_USB_ICCD_SUPPORT__
#define USB_MAX_ICCD_NUM			1
#define USB_HOST_ICCD_BUSY_COUNT  	10
#define USB_HOST_ICCD_SLEEP_TIME  	0x00FF
#endif


#ifdef __IC_USB_EEM_SUPPORT__
#define USB_MAX_EEM_NUM				1
#define EEM_TX_BUFFER_NUM			10
#define EEM_RX_BUFFER_NUM			10
#endif

