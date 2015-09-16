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
 *    usblog_drv.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *    This file intends for USB logging hardware related function definitions
 *
 * Author:
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef USB_LOGGING_DRV_H
#define USB_LOGGING_DRV_H

//#include "kal_non_specific_general_types.h"




#if defined(DRV_USB_LOGGING_V5) || defined(DRV_USB_LOGGING_V6) || defined(DRV_USB_LOGGING_V8)
#if !defined(DRV_USB_LOGGING_V5_SINGLE_DSP)
#define  USBACM_LOGGING_DSP_SOURCE_NUM   		2
#else
#define  USBACM_LOGGING_DSP_SOURCE_NUM   		1
#endif
#define  USBACM_LOGGING_3G_SOURCE_NUM   			3  //v6 dose not support 3G logging.
#ifdef __MODEM_3G_LOGGING__
#define  USBACM_LOGGING_TOTAL_SOURCE_NUM   		(USBACM_LOGGING_3G_SOURCE_NUM + USBACM_LOGGING_DSP_SOURCE_NUM)
#else
#define  USBACM_LOGGING_TOTAL_SOURCE_NUM   		(USBACM_LOGGING_DSP_SOURCE_NUM)
#endif

#endif  //logging source number


//#ifdef __MODEM_3G_LOGGING__
#if defined(DRV_USB_LOGGING_V5)||defined(DRV_USB_LOGGING_V8)
/* 3G MODEM part */
#define USB_LOGGING_3G_BUFFER1_NUM		4
#define USB_LOGGING_3G_BUFFER2_NUM		4
#define USB_LOGGING_3G_BUFFER3_NUM		5
#define USB_LOGGING_3G_BUFFER4_NUM		2
#define USB_LOGGING_3G_BUFFER1_SIZE		(1024*4)
#define USB_LOGGING_3G_BUFFER2_SIZE		(1024*4)
#define USB_LOGGING_3G_BUFFER3_SIZE		(1024*4)
#define USB_LOGGING_3G_BUFFER4_SIZE		(1024*16)
#endif

//#endif /* __MODEM_3G_LOGGING__ */


/* HISR handler function type */
typedef void (*usb_log_hdlr_ptr)(void);
typedef void (*usb_mdci_hdlr_ptr)(kal_uint32 addr, kal_uint32 len, kal_uint32 index);

#if defined(DRV_USB_LOGGING_V5)
extern void USB_LOGGING_DSP_Clear_Buff(kal_uint8 channel, kal_uint8 index);
extern kal_uint16 USB_LOGGING_Get_DSP_Status(kal_uint8 channel);
extern void USB_LOGGING_DSP_Init(kal_uint8 channel, kal_uint8* addr);
extern void USB_LOGGING_Register_DSP_Hldr(usb_log_hdlr_ptr log_dsp1_hdlr, usb_log_hdlr_ptr log_dsp2_hdlr);
extern void USB_LOGGING_DSP_Start(void);
extern void USB_LOGGING_DSP_Stop(void);
extern void USB_LOGGING_DSP_Drv_Create_ISR(void);
extern void USB_LOGGING_DSP_Drv_Activate_ISR(void);
#elif defined(DRV_USB_LOGGING_V8)
	extern kal_uint8 USB_LOGGING_Get_Buff_Num(kal_uint8 buf_index);
	extern kal_uint32 USB_LOGGING_Get_Buff_Size(kal_uint8 buf_index);
	extern void USB_LOGGING_Clear_Buff(kal_uint8 buf_index, kal_uint8 index);
	extern kal_uint16 USB_LOGGING_Get_DSP1_Status(void);
	extern kal_uint16 USB_LOGGING_Get_DSP2_Status(void);
	extern void USB_LOGGING_DSP_Init(kal_uint8 channel, kal_uint8* addr);
	extern void USB_LOGGING_Register_DSP_Hldr(usb_mdci_hdlr_ptr mdci_hdlr);
	extern void USB_LOGGING_DSP_Start(void);
	extern void USB_LOGGING_DSP_Stop(void);
	extern void USB_LOGGING_DSP_Drv_Create_ISR(void);
	extern void USB_LOGGING_DSP_Drv_Activate_ISR(void);
	extern void USB_LOGGING_Register_3G_Hldr(usb_log_hdlr_ptr log_3g_hdlr);
	extern void USB_LOGGING_3G_HISR(void);

#endif

#endif  /* USB_LOGGING_DRV_H */

