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
 *    usblog_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *    This file implements USB logging hardware related functions
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
#include "drv_comm.h"
//#include "kal_non_specific_general_types.h"
//#include "kal_release.h"
#include "kal_public_api.h"
#include "reg_base.h"
#include "drvpdn.h"
#include "intrCtrl.h"
#include "drv_hisr.h"
#include "usb_drv.h"
#include "dsplog_hw.h"
#include "usblog_drv.h"
#include "init.h"
#ifdef __MODEM_3G_LOGGING__
#include "wlog3g.h"
#endif
//#include "usb_debug_tool.h"

#include "kal_public_api.h"
#include "kal_general_types.h"

#ifdef DRV_USB_LOGGING_V8
#include "mdci.h"
#endif


#ifdef __USB_LOGGING__


#define USBPDN_CLR(X) PDN_CLR(X)
#define USBPDN_SET(X) PDN_SET(X)


extern SW_SECVERSION INT_SW_SecVersion(void);

#ifdef __DSPIRDBG__
usb_log_hdlr_ptr	log_dsp_hdlr[2];
usb_mdci_hdlr_ptr	log_mdci_hdlr;

#if defined(DRV_USB_LOGGING_V5) || defined(DRV_USB_LOGGING_V6)
static void USB_LOGGING_DSP1_HISR(void);
static void USB_LOGGING_DSP1_LISR(void);
	#if !defined(DRV_USB_LOGGING_V5_SINGLE_DSP)
	static void USB_LOGGING_DSP2_HISR(void);
	static void USB_LOGGING_DSP2_LISR(void);
	#endif
#endif

#if defined(DRV_USB_LOGGING_MT50)
void IRQ_SetSWRegister(kal_uint8 code);
void IRQ_ResetSWRegister(kal_uint8 code);
#endif

#endif

#ifdef __MODEM_3G_LOGGING__
usb_log_hdlr_ptr	log_3g_hdlr;
#endif

/********************************************
*	Source
*********************************************/

#ifdef __DSPIRDBG__

#if defined(DRV_USB_LOGGING_V5) || defined(DRV_USB_LOGGING_V6)

#if defined(DRV_USB_LOGGING_MT50)
void USB_LOGGING_IRDBG_Trigger(void)
{
	if (SW_SEC_0 == INT_SW_SecVersion()) 
	{
		IRQ_SetSWRegister(IRQ_IRDEBUG1_CODE);
	}
}
#endif

void USB_LOGGING_Register_DSP_Hldr(usb_log_hdlr_ptr log_dsp1_hdlr, usb_log_hdlr_ptr log_dsp2_hdlr)
{
	if(log_dsp1_hdlr == NULL)
	{
	  ASSERT(0);
	}
	log_dsp_hdlr[0] = log_dsp1_hdlr;	
	#if !defined(DRV_USB_LOGGING_V5_SINGLE_DSP)
		if(log_dsp2_hdlr == NULL)
		{
		  ASSERT(0);
		}
		log_dsp_hdlr[1] = log_dsp2_hdlr;	
	#endif
}


static void USB_LOGGING_DSP1_HISR(void)
{
	if(log_dsp_hdlr[0] == NULL)
		ASSERT(0);
	log_dsp_hdlr[0]();
	
	IRQClearInt(IRQ_IRDEBUG1_CODE);
	IRQUnmask(IRQ_IRDEBUG1_CODE);
}

/* USB LOGGING DSP LISR */
static void USB_LOGGING_DSP1_LISR(void)
{
	IRQMask(IRQ_IRDEBUG1_CODE);
	drv_active_hisr(DRV_USB_LOGGING_DSP1_HISR_ID);
	#if defined(DRV_USB_LOGGING_MT50)
		if (SW_SEC_0 == INT_SW_SecVersion()) 
		{
			IRQ_ResetSWRegister(IRQ_IRDEBUG1_CODE);	
		}
	#endif	
}


/* USB LOGGING DSP LISR */
#if !defined(DRV_USB_LOGGING_V5_SINGLE_DSP)
static void USB_LOGGING_DSP2_HISR(void)
{
	if(log_dsp_hdlr[1] == NULL)
		ASSERT(0);
	log_dsp_hdlr[1]();
	IRQClearInt(IRQ_IRDEBUG2_CODE);
	IRQUnmask(IRQ_IRDEBUG2_CODE);
}

static void USB_LOGGING_DSP2_LISR(void)
{
	IRQMask(IRQ_IRDEBUG2_CODE);
	drv_active_hisr(DRV_USB_LOGGING_DSP2_HISR_ID);
}
#endif

void USB_LOGGING_DSP_Drv_Create_ISR(void)
{
	IRQ_Register_LISR(IRQ_IRDEBUG1_CODE, USB_LOGGING_DSP1_LISR, "USB_LOGGING_DSP1");
	DRV_Register_HISR(DRV_USB_LOGGING_DSP1_HISR_ID, USB_LOGGING_DSP1_HISR);
	#if !defined(DRV_USB_LOGGING_V5_SINGLE_DSP)
		IRQ_Register_LISR(IRQ_IRDEBUG2_CODE, USB_LOGGING_DSP2_LISR, "USB_LOGGING_DSP2");
		DRV_Register_HISR(DRV_USB_LOGGING_DSP2_HISR_ID, USB_LOGGING_DSP2_HISR);
	#endif
}


/* activate USB LOGGING DSP interrput */
void USB_LOGGING_DSP_Drv_Activate_ISR(void)
{
	IRQSensitivity(IRQ_IRDEBUG1_CODE, LEVEL_SENSITIVE);
	IRQUnmask(IRQ_IRDEBUG1_CODE);
	#if !defined(DRV_USB_LOGGING_V5_SINGLE_DSP)	
		IRQSensitivity(IRQ_IRDEBUG2_CODE, LEVEL_SENSITIVE);
		IRQUnmask(IRQ_IRDEBUG2_CODE);
	#endif	
}

#elif defined(DRV_USB_LOGGING_V8)

void USB_LOGGING_Register_DSP_Hldr(usb_mdci_hdlr_ptr mdci_hdlr)
{
	if(mdci_hdlr == NULL)
		ASSERT(0);
	log_mdci_hdlr = mdci_hdlr;
}

static void mdci_dsplogging_d2m_cb(MDCI_BUFF_T *bufp)
{
	if((bufp->reserved>1)||(log_mdci_hdlr == NULL))
		EXT_ASSERT(0, (kal_uint32)bufp->reserved, (kal_uint32)log_mdci_hdlr, 0);

	log_mdci_hdlr(((MDCI_STREAM_T *)(bufp))->addr, ((MDCI_STREAM_T *)(bufp))->len, bufp->reserved);

}

void USB_LOGGING_DSP_Drv_Create_ISR(void)
{
	/*MDCI init*/
	mdci_init(MDCI_USBLOG_CHANNEL_D2M, mdci_dsplogging_d2m_cb);
}


/* activate USB LOGGING DSP interrput */
void USB_LOGGING_DSP_Drv_Activate_ISR(void)
{
}
#endif //defined(DRV_USB_LOGGING_V5) || defined(DRV_USB_LOGGING_V6)
#endif //__DSPIRDBG__

#ifdef __MODEM_3G_LOGGING__
void USB_LOGGING_Register_3G_Hldr(usb_log_hdlr_ptr log3g_hdlr)
{
	if(log3g_hdlr == NULL)
		ASSERT(0);

	log_3g_hdlr = log3g_hdlr;
}


void USB_LOGGING_3G_HISR(void)
{
	kal_uint32   buf_index;
	kal_uint8     total_full_index = 0;


	for(buf_index = USBACM_LOGGING_DSP_SOURCE_NUM; buf_index < USBACM_LOGGING_TOTAL_SOURCE_NUM; buf_index++)
	{
		total_full_index |= USB_LOGGING_Get_3G_Status((buf_index-USBACM_LOGGING_DSP_SOURCE_NUM));
	}

	if(total_full_index != 0)
	{
		if(log_3g_hdlr == NULL)
			ASSERT(0);

		log_3g_hdlr();
	}

	IRQClearInt(IRQ_LOG3G_CODE);
	IRQUnmask(IRQ_LOG3G_CODE);
}
#endif /* __MODEM_3G_LOGGING__ */
#endif /*__USB_LOGGING__ */
