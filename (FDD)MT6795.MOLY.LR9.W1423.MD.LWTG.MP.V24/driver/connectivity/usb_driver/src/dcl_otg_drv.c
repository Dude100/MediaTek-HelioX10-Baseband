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
 *   dcl_otg_drv.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 * This file defines the DCL common definitions for USB OTG driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#if defined(__OTG_ENABLE__) && !defined(DRV_USB_OFF)


#include "drv_comm.h"
#include "reg_base.h"
#include "drvpdn.h"
#include "intrCtrl.h"
#include "drv_hisr.h"
#include "gpio_hw.h"
#include "gpio_sw.h"
//#include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */
#include "isrentry.h"
#include "eint.h"
#include "usb_hw.h"
#include "otg_drv.h"
#include "otg_drv_pri.h"
#include "usb_hcd.h"
#include "usb_hcd_pri.h"
#include "usb_drv.h"
#include "usb_drv_pri.h"
//#include "usb_custom.h"
#include "otg_if.h"
#include "usb_debug_tool.h"
#include "usb_trc.h"
#include "dcl.h"
#include "usb_adap.h"
//#include "kal_non_specific_general_types.h"
//#include "kal_release.h"
#include "kal_trace.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "drv_msgid.h"


//#if (defined(MT6326))
//#include "pmic6326_sw.h"
//#include "i2c_dual_sw.h"
//#endif


static OTG_Drv_Info g_OtgInfo;
static kal_bool g_otg_idpin_state;
extern kal_bool OTG_IDPIN_CABLE_PLUGIN_LEVEL;
extern kal_uint8 INT_Exception_Enter;/* Exception flag*/

static void OTG_Set_Plug_Type(OTG_PLUG_TYPE type);
static kal_bool OTG_Is_B_Session_Valid(void);

static void OTG_Timeout_Hdlr(void *parameter);
static void OTG_Start_Timer(OTG_TIMER_TYPE type, kal_uint32 ticks);
static void OTG_Stop_Timer(void);
static OTG_TIMER_TYPE OTG_Get_TimerType(void);

static kal_bool OTG_Is_TimerOut(OTG_TIMER_TYPE type);
static kal_bool OTG_Is_TimerActive(void);
static void OTG_Process_A_Idle(void);
static void OTG_Process_A_Wait_BCon(void);
static void OTG_Process_A_Host(void);
static void OTG_Process_A_Suspend(void);
static void OTG_Process_A_Peripheral(void);
static void OTG_Process_A_Wait_VFall(void);
static void OTG_Process_B_Idle(void);
static void OTG_Process_B_Session_Valid(void);
static void OTG_Process_B_SRP_Init(void);
static void OTG_Process_B_Peripheral(void);
static void OTG_Process_B_Wait_ACon(void);
static void OTG_Process_B_Host(void);
static void OTG_State_Machine(void);

static void OTGDMA_HISR(void);
static void OTGDMAQ_HISR(void);
static void OTGDMA_LISR(void);
static void OTG_LISR(void);

static void OTG_ID_EINT_HISR(void);



/************************************************************
	A plug detection functions
*************************************************************/

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_USB_PHY_U65_IP)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static void OTG_ID_EINT_HISR(void)
{
	ilm_struct *maplug_ilm;
	kal_uint8 otg_idpin_eint = custom_eint_get_channel(otg_idpin_eint_chann);

	if(g_otg_idpin_state != OTG_IDPIN_CABLE_PLUGIN_LEVEL)
	{
		USB_Dbg_Trace(USB_HOST_A_CABLE_PLUG_OUT, (kal_uint32)g_OtgInfo.otg_state, 0);

#if (defined(DRV_USB_PHY_COST_DOWN))
		USB_DRV_SetBits8(USB_PHYIR3_2, USB_PHYIR3_2_IDDIG);
		USB_DRV_SetBits8(USB_PHYCR4_0,USB_PHYCR4_0_FORCE_IDDIG);
#endif

		/* USB IRQ is masked so there is no expected interrupt */
	#if defined(DRV_USB_IP_V3)
		if(g_OtgInfo.otg_state == OTG_STATE_A_HOST)
		{
			if(USB_HCD_Get_UnMask_Irq(0) == KAL_FALSE)
			{
				USB_Dbg_Trace(USB_A_CABLE_OUT_BUT_NO_DISCONN, 1, 1);
				USB_HCD_Disconn_Hdlr(0);
			}
			else
			{
				USB_Dbg_Trace(USB_A_CABLE_OUT_BUT_NO_DISCONN, USB_DRV_Reg8(USB_LINE_STATE), USB_DRV_Reg8(USB_OPSTATE));
			}
		}
		else if(g_OtgInfo.otg_state == OTG_STATE_A_PERIPHERAL)
		{
			if(USB_HW_Get_UnMask_Irq() == KAL_FALSE)
			{
				USB_Dbg_Trace(USB_A_CABLE_OUT_BUT_NO_DISCONN, 2, 0);
				g_OtgInfo.otg_state = OTG_STATE_A_WAIT_BCON;
			}
			else
			{
				USB_Dbg_Trace(USB_A_CABLE_OUT_BUT_NO_DISCONN, USB_DRV_Reg8(USB_LINE_STATE), USB_DRV_Reg8(USB_OPSTATE));
			}
		}
	#endif

		OTG_Set_Plug_Type(OTG_PLUG_B);

		DRV_BuildPrimitive(maplug_ilm,
						stack_get_active_module_id(),
						MOD_USB,
						MSG_ID_USB_A_PLUGOUT_IND,
						NULL);

		msg_send_ext_queue(maplug_ilm);
	}
	else
	{
		USB_Dbg_Trace(USB_HOST_A_CABLE_PLUG_IN, 0, 0);

	/* Open AHB clock, then we can set USB IP's registers */	
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
	USB_DRV_WriteReg(DRVPDN_CON0_CLR, DRVPDN_CON0_USB);
#elif defined(__CLKG_DEFINE__)
	USB_DRV_WriteReg(CG_CLR0, CG_CON0_USB);
#endif
#else
	DRVPDN_Disable(PDN_USB);
#endif

		OTG_Set_Plug_Type(OTG_PLUG_A);

#if (defined(DRV_USB_PHY_COST_DOWN))
		USB_DRV_ClearBits8(USB_PHYIR3_2, USB_PHYIR3_2_IDDIG);
		USB_DRV_SetBits8(USB_PHYCR4_0, USB_PHYCR4_0_FORCE_IDDIG);
#endif

		DRV_BuildPrimitive(maplug_ilm,
						stack_get_active_module_id(),
						MOD_USB,
						MSG_ID_USB_A_PLUGIN_IND,
						NULL);
		msg_send_ext_queue(maplug_ilm);
	}

	g_otg_idpin_state = (g_otg_idpin_state == KAL_FALSE)?(KAL_TRUE):(KAL_FALSE);
	EINT_Set_Polarity(otg_idpin_eint, g_otg_idpin_state);

#if 0 // (defined(MT6326))
/* under construction !*/
/* under construction !*/
#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
/* under construction !*/
#elif defined(__CLKG_DEFINE__)
/* under construction !*/
#endif
#else
/* under construction !*/
#endif
/* under construction !*/
#endif


	EINT_UnMask(otg_idpin_eint);
}


static void OTG_Set_Plug_Type(OTG_PLUG_TYPE type)
{
	g_OtgInfo.plug_type = type;
}



void OTG_Set_Status(OTG_STATUS_TYPE type, kal_bool set)
{
	kal_bool	b_process_state_machine = KAL_FALSE;
	kal_uint32 savedMask;


	USB_Dbg_Trace(USB_OTG_SET_STATUS, (kal_uint32)type, (kal_uint32)set);

	switch(type)
	{
	case OTG_STATUS_A_BUS_REQUEST:
		g_OtgInfo.a_bus_req = set;
		break;
	case OTG_STATUS_A_DETECT_B_CONN:
		g_OtgInfo.a_detect_b_conn = set;
		break;
	case OTG_STATUS_A_DETECT_B_SUSPEND:
		g_OtgInfo.a_detect_b_suspend = set;
		break;
	case OTG_STATUS_A_DETECT_B_RESUME:
		g_OtgInfo.a_detect_b_resume = set;
		break;
	case OTG_STATUS_A_DETECT_B_DATA_PLS:
		g_OtgInfo.a_detect_b_data_pls = set;
		break;
	case OTG_STATUS_A_SUSPEND_REQUEST:
		g_OtgInfo.a_suspend_req = set;
		break;
	case OTG_STATUS_A_RESUME_REQUEST:
		g_OtgInfo.a_resume_req = set;
		break;
	case OTG_STATUS_A_SET_B_HNP_ENABLE:
		g_OtgInfo.a_set_b_hnp_enable = set;
		break;
	case OTG_STATUS_B_SESSION_VALID:
		g_OtgInfo.b_session_valid = set;
		break;
	case OTG_STATUS_B_SUSPEND_REQUEST:
		g_OtgInfo.b_suspend_req = set;
		break;
	case OTG_STATUS_B_DETECT_A_CONN:
		g_OtgInfo.b_detect_a_conn = set;
		break;
	case OTG_STATUS_B_DETECT_A_SUSPEND:
		g_OtgInfo.b_detect_a_suspend = set;
		break;
	case OTG_STATUS_B_DETECT_A_RESUME:
		g_OtgInfo.b_detect_a_resume = set;
		break;
	case OTG_STATUS_B_DETECT_A_RESET:
		g_OtgInfo.b_detect_a_reset = set;
		break;
	case OTG_STATUS_B_SRP_REQUEST:
		g_OtgInfo.b_srp_request = set;
		break;
	case OTG_STATUS_B_HNP_ENABLE:
		g_OtgInfo.b_hnp_enable = set;
		break;
	default:
		ASSERT(0);
		break;
	}

	/* Process OTG state machine*/
	savedMask = SaveAndSetIRQMask();
	if(g_OtgInfo.b_processing == KAL_FALSE)
	{
		g_OtgInfo.b_processing = KAL_TRUE;
		b_process_state_machine = KAL_TRUE;
	}
	RestoreIRQMask(savedMask);

	if(b_process_state_machine == KAL_TRUE)
	{
		OTG_State_Machine();
		g_OtgInfo.b_processing = KAL_FALSE;
	}

	if((g_OtgInfo.suspend_and_conn_intr == KAL_TRUE)&&(g_OtgInfo.otg_state == OTG_STATE_B_WAIT_ACON))
	{
		g_OtgInfo.suspend_and_conn_intr = KAL_FALSE;
		USB_HCD_Conn_Hdlr(0);
	}
}


OTG_PLUG_TYPE OTG_Get_Plug_Type(void)
{
	return g_OtgInfo.plug_type;
}


OTG_STATE OTG_Get_State(void)
{
	return g_OtgInfo.otg_state;
}


kal_uint8 OTG_Get_Intr_Status(void)
{
	return g_OtgInfo.otg_intr_status;
}


void OTG_Set_Conn_Intr_With_Suspend(void)
{
	g_OtgInfo.suspend_and_conn_intr = KAL_TRUE;
}


void OTG_Set_Disconn_Status(void)
{
	g_OtgInfo.disconn_and_conn_intr = KAL_TRUE;
}


kal_bool OTG_Is_B_Process_SRP(void)
{
	return g_OtgInfo.b_srp_request;
}





static kal_bool OTG_Is_B_Session_Valid(void)
{
	kal_bool ret = KAL_FALSE;
	kal_uint8	 usbdevice = (USB_DRV_Reg8(USB_DEVCTL)&USB_DEVCTL_VBUS);


	if((usbdevice == USB_DEVCTL_ABOVE_VBUS_VALID)||(usbdevice == USB_DEVCTL_ABOVE_A_VALID))
		ret = KAL_TRUE;

	return ret;
}


/************************************************************
	Timer  functions
*************************************************************/

/* GPT timeout handler */
static void OTG_Timeout_Hdlr(void *parameter)
{
	DclSGPT_Control((DCL_HANDLE)(g_OtgInfo.gpt_handle), SGPT_CMD_STOP, 0);
//	GPTI_StopItem(g_OtgInfo.gpt_handle);

	g_OtgInfo.timer_out = KAL_TRUE;

	USB_Dbg_Trace(USB_OTG_TIMEOUT_HDLR, (kal_uint32)g_OtgInfo.timer_type, USB_DRV_Reg8(USB_POWER));

	if(OTG_Is_TimerOut(OTG_TIMER_B_CHECK_A_RESUME) == KAL_TRUE)
	{
		if((USB_DRV_Reg8(USB_LINE_STATE)&0xC0) == 0x80)
		{
			/* K resume! */
			/* Stop the timer, let state machine see as resume */
			OTG_Stop_Timer();

			/* K resume! */
			g_OtgInfo.b_detect_a_resume = KAL_TRUE;
		}
	}

	/* Process OTG state machine*/
	if(g_OtgInfo.b_processing == KAL_FALSE)
	{
//		g_OtgInfo.b_processing = KAL_TRUE;
		OTG_State_Machine();
//		g_OtgInfo.b_processing = KAL_FALSE;
	}
}


/* The tick unit is ms */
static void OTG_Start_Timer(OTG_TIMER_TYPE type, kal_uint32 ticks)
{
	SGPT_CTRL_START_T start;
		
	if(g_OtgInfo.timer_on==KAL_TRUE)
		EXT_ASSERT(0, (kal_uint32)g_OtgInfo.timer_on, (kal_uint32)g_OtgInfo.timer_type, (kal_uint32)g_OtgInfo.timer_out);

	g_OtgInfo.timer_type = type;
	g_OtgInfo.timer_on = KAL_TRUE;
	g_OtgInfo.timer_out = KAL_FALSE;

	/* IP V3 only have GPT timer */
	if (ticks < 10)
		ticks = 10;

    start.u2Tick = ticks/10;					
    start.pfCallback = OTG_Timeout_Hdlr;			
    start.vPara = &g_OtgInfo;							
    DclSGPT_Control((DCL_HANDLE)(g_OtgInfo.gpt_handle), SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);	

}


/* stop the timer */
static void OTG_Stop_Timer(void)
{
	DclSGPT_Control((DCL_HANDLE)(g_OtgInfo.gpt_handle), SGPT_CMD_STOP, 0);
//	GPTI_StopItem(g_OtgInfo.gpt_handle);

	g_OtgInfo.timer_on = KAL_FALSE;
	g_OtgInfo.timer_out = KAL_FALSE;
	g_OtgInfo.timer_type = OTG_TIMER_NONE;
}


/* return KAL_TRUE if "type" timer is timeout */
static kal_bool OTG_Is_TimerOut(OTG_TIMER_TYPE type)
{
	kal_bool ret = KAL_FALSE;


	if((g_OtgInfo.timer_out == KAL_TRUE)&&(g_OtgInfo.timer_type == type))
		ret = KAL_TRUE;

	return ret;
}


/* return if any timer is active*/
static kal_bool OTG_Is_TimerActive(void)
{
	kal_bool	ret = KAL_FALSE;

	if((g_OtgInfo.timer_on == KAL_TRUE) || (g_OtgInfo.timer_out == KAL_TRUE))
		ret = KAL_TRUE;

	return ret;
}


/* Return active timer type */
static OTG_TIMER_TYPE OTG_Get_TimerType(void)
{
	return g_OtgInfo.timer_type;
}


/************************************************************
	state machine functions
*************************************************************/

/* Go from Vbus error */
static void OTG_Process_A_Vbus_Fail(void)
{
	g_OtgInfo.otg_state = OTG_STATE_A_WAIT_VFALL;

	/* Turn off VBUS "auto" */
	USB_HCD_VBusEnable(0, KAL_FALSE);

	if(g_OtgInfo.host_up == KAL_TRUE)
	{
		g_OtgInfo.host_up = KAL_FALSE;
		g_OtgInfo.a_host_stop_hdlr();
		g_OtgInfo.host_down_hdlr();
	}

	if(g_OtgInfo.device_up == KAL_TRUE)
	{
		g_OtgInfo.device_up = KAL_FALSE;
		g_OtgInfo.device_down_hdlr();
	}

	if(g_OtgInfo.a_process_hnp == KAL_TRUE)
	{
//		ASSERT(0);
		g_OtgInfo.a_process_hnp = KAL_FALSE;
		/* OTG_A_HNP_Fail_Hdlr(void) */
		/* OTG_Display_Message(OTG_DISPLAY_MSG_HNP_STOP); */
		g_OtgInfo.a_hnp_fail_hdlr();
	}
	else
	{
		/* device draws too much current */
		/* void OTG_A_VRise_Fail_Hdlr(void) */
		/* OTG_Display_Message(OTG_DISPLAY_MSG_UN_SUPPORT); */
		g_OtgInfo.a_vrise_fail_hdlr();
	}

	OTG_Start_Timer(OTG_TIMER_A_CHECK_VFALL, TA_CHECK_VFALL);
	OTG_Process_A_Wait_VFall();
}


static void OTG_Process_A_Idle(void)
{
	if(OTG_Get_Plug_Type() == OTG_PLUG_B)
	{
		//  A cable plug out, A device return to A_ldle, then gp to B_idle
		//  from OTG_Process_A_Wait_VFall
		g_OtgInfo.otg_state = OTG_STATE_B_IDLE;
		OTG_Process_B_Idle();
		return;
	}

	/* A detect SRP */
	if(g_OtgInfo.a_detect_b_data_pls == KAL_TRUE)
	{
		g_OtgInfo.a_detect_b_data_pls = KAL_FALSE;
#ifdef OTG_A_NOT_INSERTION_BASE		
		g_OtgInfo.a_bus_req = KAL_TRUE;
#endif
	}
#ifdef OTG_A_NOT_INSERTION_BASE
/*
	else if(OTG_Is_TimerOut(OTG_TIMER_A_ATTATCH_DEBOUNCE) == KAL_TRUE)
	{
		OTG_Stop_Timer();

		if(g_OtgInfo.host_up == KAL_FALSE)
		{
			g_OtgInfo.host_up = KAL_TRUE;
			g_OtgInfo.host_up_hdlr();
		}
	}
	else if(g_OtgInfo.a_detect_b_resume == KAL_TRUE)
	{
		// compliance test
		// deassert resume
		g_OtgInfo.a_detect_b_resume = KAL_FALSE;

		ASSERT(0);
//		USB_DRV_SetBits8(USB_POWER, USB_POWER_RESUME);
//		OTG_Start_Timer(OTG_TIMER_A_RESUME, TA_RESUME);
	}
*/

	USB_DRV_WriteReg8(USB_INTRUSBE, USB_INTRUSBE_SESSREQ);
#endif

	if(g_OtgInfo.a_bus_req == KAL_TRUE)
	{
		/* In case go here and SRP timer is still on*/
		OTG_Stop_Timer();

		/* If device is up, pull it down */
		if(g_OtgInfo.device_up == KAL_TRUE)
		{
			/* For 1. B in 2. A in 3.  B out case */
			g_OtgInfo.device_up = KAL_FALSE;
			g_OtgInfo.device_down_hdlr();
		}

		/* Software reset */
#if defined(DRV_USB_IP_V3)
			USB_DRV_WriteReg(USB_SWRST, USB_SWRST_DISUSBRESET);
#elif defined(DRV_USB_IP_V4)
			USB_DRV_SetBits(USB_BUSPERF3, USB_BUSPERF3_DISUSBRESET);
#endif


		/* Enable system interrupts, but disable all ep interrupts */
		USB_EnSysIntr();

		USB_Dbg_Trace(USB_OTG_STATE_FROM_A_IDLE_TO_A_WAIT_BCON, 0, 0);
		/* Turn on VBUS, and wait B connect or VBUS error */
		g_OtgInfo.otg_state = OTG_STATE_A_WAIT_BCON;

#ifdef __OTG_A_PERIODIC_VBUS_CYCLE__
		OTG_Start_Timer(OTG_TIMER_A_VBUS_PERIOD_VON, TA_VBUS_PERIOD_VON);
#endif

	#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
		g_OtgInfo.b_is_vbus_power_on = KAL_TRUE;
	#endif
		USB_HCD_VBusEnable(0, KAL_TRUE);

		if(g_OtgInfo.host_up == KAL_FALSE)
		{
			g_OtgInfo.host_up = KAL_TRUE;
			g_OtgInfo.host_up_hdlr();
		}
	}
#ifdef OTG_A_NOT_INSERTION_BASE
/*
	else
	{
		// for compliance test
		// start timer to debounce attatch
		if(g_OtgInfo.host_up == KAL_FALSE)
		{
			OTG_Start_Timer(OTG_TIMER_A_ATTATCH_DEBOUNCE, TA_ATTATCH_DEBOUNCE);
		}
	}
*/
#endif
}


static void OTG_Process_A_Wait_BCon(void)
{
	if (g_OtgInfo.a_detect_b_conn == KAL_TRUE)
	{
#ifdef __OTG_A_PERIODIC_VBUS_CYCLE__
		OTG_Stop_Timer();
#endif
		USB_Dbg_Trace(USB_OTG_STATE_FROM_A_WAIT_BCON_TO_A_HOST, 0, 0);
		g_OtgInfo.otg_state = OTG_STATE_A_HOST;
	}
	else if(OTG_Get_TimerType() == OTG_TIMER_A_RESUME)
	{
//		ASSERT(0);
		OTG_Stop_Timer();
		USB_DRV_ClearBits8(USB_POWER, USB_POWER_RESUME);
	}
#ifdef __OTG_A_PERIODIC_VBUS_CYCLE__
	else if(OTG_Is_TimerOut(OTG_TIMER_A_VBUS_PERIOD_VON) == KAL_TRUE)
	{
		OTG_Stop_Timer();
		USB_Dbg_Trace(USB_OTG_STATE_A_WAIT_BCON_TURN_OFF_VBUS, 0, 0);

		g_OtgInfo.otg_state = OTG_STATE_A_WAIT_VFALL;

		/* Turn off VBUS */
		USB_HCD_VBusEnable(0, KAL_FALSE);

		if(g_OtgInfo.host_up == KAL_TRUE)
		{
			g_OtgInfo.host_up = KAL_FALSE;
			g_OtgInfo.a_host_stop_hdlr();
			g_OtgInfo.host_down_hdlr();
		}

		OTG_Start_Timer(OTG_TIMER_A_VBUS_PERIOD_VFALL, TA_VBUS_PERIOD_VFALL);
	}
#endif
#ifdef OTG_A_NOT_INSERTION_BASE
/*
	else if(OTG_Is_TimerOut(OTG_TIMER_A_WAIT_BCON) == KAL_TRUE)
	{
		OTG_Stop_Timer();
		g_OtgInfo.a_bus_req=KAL_FALSE;
		g_OtgInfo.otg_state = OTG_STATE_A_WAIT_VFALL;
		USB_DRV_SetBits8(USB_POWER, USB_POWER_SUSPENDMODE);
		// Turn off VBUS
		USB_DRV_ClearBits8(OTG_CTRL, OTG_CTL_VBUS_ON);

		g_OtgInfo.a_no_response_hdlr();

		OTG_Start_Timer(OTG_TIMER_A_CHECK_VFALL, TA_CHECK_VFALL);
		OTG_Process_A_Wait_VFall();
	}

	if(g_OtgInfo.otg_state == OTG_STATE_A_WAIT_BCON)
	{
		if(OTG_Is_TimerActive() == KAL_TRUE)
		{
			if(OTG_Get_TimerType() != OTG_TIMER_NONE)
			{
				OTG_Stop_Timer();
				OTG_Start_Timer(OTG_TIMER_A_WAIT_BCON, TA_WAIT_BCON);
			}
			else
			{
				ASSERT(0);
			}
		}
		else
		{
//			OTG_Stop_Timer();
			OTG_Start_Timer(OTG_TIMER_A_WAIT_BCON, TA_WAIT_BCON);
		}
	}
*/
#endif
}


static void OTG_Process_A_Host(void)
{
#ifdef OTG_A_NOT_INSERTION_BASE
/*
	if(OTG_Get_TimerType() == OTG_TIMER_A_WAIT_BCON)
	{
		OTG_Stop_Timer();
	}
*/
#endif

	/*
	** If mini B plug is removed RESET (DETACH) interrupt will
	** happen on A-Device.The DETACH will processed by the host
	** ISR  and set a_detect_b_conn to  FALSE
	*/
	if((g_OtgInfo.a_detect_b_conn == KAL_FALSE)&&(g_OtgInfo.a_detect_b_resume ==KAL_FALSE))
	{
		USB_Dbg_Trace(USB_OTG_STATE_FROM_A_HOST_TO_A_WAIT_BCON, 0, 0);
		g_OtgInfo.otg_state = OTG_STATE_A_WAIT_BCON;

		g_OtgInfo.a_host_stop_hdlr();

		/* When A device detect conn and disconn intr at the same time, always turn off Vbus and then turn on Vbus */
		if(g_OtgInfo.disconn_and_conn_intr == KAL_TRUE)
		{
			g_OtgInfo.disconn_and_conn_intr = KAL_FALSE;

			USB_Dbg_Trace(USB_OTG_STATE_A_WAIT_BCON_TURN_OFF_VBUS, 0, 0);

			g_OtgInfo.otg_state = OTG_STATE_A_WAIT_VFALL;

			/* Turn off VBUS*/
			USB_HCD_VBusEnable(0, KAL_FALSE);

			if(g_OtgInfo.host_up == KAL_TRUE)
			{
				g_OtgInfo.host_up = KAL_FALSE;
				g_OtgInfo.host_down_hdlr();
			}

			OTG_Start_Timer(OTG_TIMER_A_VBUS_PERIOD_VFALL, TA_VBUS_PERIOD_VFALL);
		}
#ifdef __OTG_A_PERIODIC_VBUS_CYCLE__
		else if(g_OtgInfo.a_bus_req == KAL_TRUE)
		{
			/* When A cable out, wait a moment and then turn off Vbus */
			OTG_Start_Timer(OTG_TIMER_A_VBUS_PERIOD_VON, TA_VBUS_PERIOD_VON);
		}
#endif

#ifdef OTG_A_NOT_INSERTION_BASE
		USB_Dbg_Trace(USB_OTG_STATE_A_WAIT_BCON_TURN_OFF_VBUS, 0, 0);

		g_OtgInfo.otg_state = OTG_STATE_A_WAIT_VFALL;

		/* Turn off VBUS */
		USB_HCD_VBusEnable(0, KAL_FALSE);

		if(g_OtgInfo.host_up == KAL_TRUE)
		{
			g_OtgInfo.host_up = KAL_FALSE;
			g_OtgInfo.host_down_hdlr();
		}
#endif
	}
	/************   Starting HNP **************************************
	** When the A-device is in the a_host state and has set the dual-role
	** B-device's HNP enable bit (b_hnp_enable = TRUE ie, a_suspend_req
	** = TRUE) the A-device shall place the connection to the B-device into
	** Suspend when it is finished using the bus.  We can go to the
	** suspend state also if user want to power down.
	*/
	else if((g_OtgInfo.a_set_b_hnp_enable == KAL_TRUE)&&(g_OtgInfo.a_detect_b_resume ==KAL_FALSE))
	{
		USB_Dbg_Trace(USB_OTG_STATE_FROM_A_HOST_TO_A_SUSPEND, 0, 0);
		g_OtgInfo.otg_state = OTG_STATE_A_SUSPEND;
		USB_DRV_SetBits8(USB_POWER, (USB_POWER_SUSPENDMODE|USB_POWER_SOFTCONN));

		/*  When A idle, B can decide to enter HNP process more than 200ms */
//		OTG_Start_Timer(OTG_TIMER_A_IDLE_BDIS, TA_AIDL_BDIS);

		g_OtgInfo.a_process_hnp = KAL_TRUE;
      	}
	/* A request to suspend the bus */
      	else if(g_OtgInfo.a_suspend_req == KAL_TRUE)
      	{
		USB_Dbg_Trace(USB_OTG_STATE_FROM_A_HOST_TO_A_SUSPEND, 0, 0);
		g_OtgInfo.otg_state = OTG_STATE_A_SUSPEND;
		USB_DRV_SetBits8(USB_POWER, USB_POWER_SUSPENDMODE);
		g_OtgInfo.a_suspend_req = KAL_FALSE;
      	}
	/* This may be because B device is not supported by this A device */
      	else if(g_OtgInfo.a_bus_req == KAL_FALSE)
      	{
		g_OtgInfo.otg_state = OTG_STATE_A_WAIT_VFALL;

		USB_DRV_SetBits8(USB_POWER, USB_POWER_SUSPENDMODE);

		/* Turn off VBUS*/
		USB_HCD_VBusEnable(0, KAL_FALSE);

		USB_DRV_ClearBits8(USB_INTRUSBE, USB_INTRUSBE_SESSREQ);

		if(g_OtgInfo.host_up == KAL_TRUE)
		{
			g_OtgInfo.host_up = KAL_FALSE;
			g_OtgInfo.a_host_stop_hdlr();
			g_OtgInfo.host_down_hdlr();
		}

		if(g_OtgInfo.device_up == KAL_TRUE)
		{
			g_OtgInfo.device_up = KAL_FALSE;
			g_OtgInfo.device_down_hdlr();
		}

		OTG_Start_Timer(OTG_TIMER_A_CHECK_VFALL, TA_CHECK_VFALL);
		OTG_Process_A_Wait_VFall();
      	}
	else if(OTG_Is_TimerOut(OTG_TIMER_A_RESUME) == KAL_TRUE)
	{
		/* host resume 20ms timeout */
		OTG_Stop_Timer();
		USB_DRV_ClearBits8(USB_POWER, USB_POWER_RESUME);
	}
}


static void OTG_Process_A_Suspend(void)
{
	/* HNP failed */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	/* a_detect_b_conn = FALSE if a disconn interrupt happens and it will set by
	** the application; a_set_b_hnp_en is false as default and set to
	** if the request is not stalled
	*/
	if((g_OtgInfo.a_detect_b_conn == KAL_FALSE)&&(g_OtgInfo.a_set_b_hnp_enable == KAL_FALSE))
	{
		USB_Dbg_Trace(USB_OTG_STATE_FROM_A_SUSPEND_TO_A_WAIT_BCON, 0, 0);
		g_OtgInfo.otg_state = OTG_STATE_A_WAIT_BCON;
	}
	/*
	** If the B-device disconnects after the bus has been suspended,
	** then this is an indication that the B-device is attempting
	** to become Host. When the A-device detects the disconnect
	** from the B-device, it shall turn on its D+ pull-up resistor
	** within 3 ms (TA_BDIS_ACON max) to acknowledge
	** the request from the B-device.
	*/
	else if((g_OtgInfo.a_detect_b_conn == KAL_FALSE)&&(g_OtgInfo.a_set_b_hnp_enable==KAL_TRUE))
	{
		/* Must execute within 3ms */
		/* stop OTG_TIMER_A_IDLE_BDIS timer */
//		OTG_Stop_Timer();

		/* start up device */
		if((g_OtgInfo.host_up == KAL_FALSE)||(g_OtgInfo.device_up == KAL_TRUE))
			EXT_ASSERT(0, (kal_uint32)g_OtgInfo.host_up, (kal_uint32)g_OtgInfo.device_up, 0);

		g_OtgInfo.host_up = KAL_FALSE;
		g_OtgInfo.host_down_hdlr();
		g_OtgInfo.device_up = KAL_TRUE;
		g_OtgInfo.device_up_hdlr();

		USB_Dbg_Trace(USB_OTG_STATE_FROM_A_SUSPEND_TO_A_PERIPHERAL, 0, 0);
		g_OtgInfo.otg_state = OTG_STATE_A_PERIPHERAL;
		g_OtgInfo.a_set_b_hnp_enable = KAL_FALSE;
		g_OtgInfo.a_process_hnp = KAL_FALSE;
		g_OtgInfo.a_hnp_stop_hdlr();
	}
	else if (g_OtgInfo.a_resume_req == KAL_TRUE)
	{
		/* stop OTG_TIMER_A_IDLE_BDIS timer */
//		OTG_Stop_Timer();

		if(g_OtgInfo.a_process_hnp == KAL_TRUE)
		{
			g_OtgInfo.a_process_hnp = KAL_FALSE;
			g_OtgInfo.a_hnp_fail_hdlr();
		}

		USB_Dbg_Trace(USB_OTG_STATE_FROM_A_SUSPEND_TO_A_HOST, 0, 0);
		g_OtgInfo.otg_state = OTG_STATE_A_HOST;

		USB_DRV_SetBits8(USB_POWER, USB_POWER_RESUME);
		g_OtgInfo.a_resume_req = KAL_FALSE;
		OTG_Start_Timer(OTG_TIMER_A_RESUME, TA_RESUME);
	}
	/* OPT remote wakeup */
	else if(g_OtgInfo.a_detect_b_resume == KAL_TRUE)
	{
		/* A-host detect B-device send remote wakeup resume */

		/* stop OTG_TIMER_A_IDLE_BDIS timer */
//		OTG_Stop_Timer();

		g_OtgInfo.a_detect_b_resume = KAL_FALSE;

		if(g_OtgInfo.a_process_hnp == KAL_TRUE)
		{
			g_OtgInfo.a_process_hnp = KAL_FALSE;
			g_OtgInfo.a_hnp_fail_hdlr();
		}

		USB_Dbg_Trace(USB_OTG_STATE_FROM_A_SUSPEND_TO_A_HOST, 0, 0);
		g_OtgInfo.otg_state = OTG_STATE_A_HOST;
		g_OtgInfo.a_set_b_hnp_enable = KAL_FALSE;
		USB_DRV_ClearBits8(USB_POWER, USB_POWER_SOFTCONN);
		/* IP resume automatically, wait 20ms to clear resume bit */
		OTG_Start_Timer(OTG_TIMER_A_RESUME, TA_RESUME);
	}
}


static void OTG_Process_A_Peripheral(void)
{
	/* In the current design, do not allow host init again*/
	/*
	** A-device detects lack of bus activity for more than 3 ms
	** (TA_BIDL_ADIS min) and turns off its D+ pull-up. Alternatively,
	** if the A-device has no further need to communicate with the
	** B-device, the A-device may turn off VBUS and end the session.
	** SUSPEND will be processed by the  device ISR a_detect_b_suspend
	** variable will be set by the application
	** The following will be done when this happens:
	**
	**   - disconnect its pull up
	**   - allow time for the data line to discharge
	**   - check if the B-device has connected its pull up
	*/
	if((g_OtgInfo.a_detect_b_suspend == KAL_TRUE)&&(OTG_Is_TimerActive() == KAL_FALSE))
	{
		g_OtgInfo.a_detect_b_suspend = KAL_FALSE;

		/* start up host */
		if((g_OtgInfo.device_up == KAL_FALSE)||(g_OtgInfo.host_up == KAL_TRUE))
			EXT_ASSERT(0, (kal_uint32)g_OtgInfo.device_up, (kal_uint32)g_OtgInfo.host_up, 0);

		g_OtgInfo.device_up = KAL_FALSE;
		g_OtgInfo.device_down_hdlr();
		g_OtgInfo.host_up = KAL_TRUE;
		g_OtgInfo.host_up_hdlr();

		/* Clear softconn bit */
		USB_DRV_ClearBits8(USB_POWER, USB_POWER_SOFTCONN);

		USB_Dbg_Trace(USB_OTG_STATE_FROM_A_PERIPHERAL_TO_A_WAIT_BCON, 0, 0);
		g_OtgInfo.otg_state = OTG_STATE_A_WAIT_BCON;
	}

// official should be this , but not suitable for OPT test
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


static void OTG_Process_A_Wait_VFall(void)
{
	if((OTG_Is_B_Session_Valid() == KAL_FALSE)
		||(OTG_Get_Plug_Type() == OTG_PLUG_B))
	{
		USB_Dbg_Trace(USB_OTG_STATE_FROM_A_WAIT_VFAIL_TO_A_IDLE, 0, 0);
		g_OtgInfo.otg_state = OTG_STATE_A_IDLE;

	#ifdef __OTG_A_PERIODIC_VBUS_CYCLE__
		if(OTG_Get_TimerType() == OTG_TIMER_A_VBUS_PERIOD_VFALL)
			g_OtgInfo.a_bus_req = KAL_TRUE;
		else
			g_OtgInfo.a_bus_req = KAL_FALSE;
	#else
		g_OtgInfo.a_bus_req = KAL_FALSE;
	#endif
		OTG_Stop_Timer();

		/* In current design, conditions that may go here are
		    1. B device draws too much current
		    2. A device dose not recognize B device and B device dose not take HNP
		    3. B device return from HNP host
		*/

		/* Only set g_OtgInfo.b_is_vbus_power_on = KAL_FALSE when A cable is plugged out */
	#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
		if(OTG_Get_Plug_Type() == OTG_PLUG_B)
			g_OtgInfo.b_is_vbus_power_on = KAL_FALSE;
	#endif

		OTG_Process_A_Idle();
		return;
	}
#ifdef OTG_A_NOT_INSERTION_BASE
/*
	else if(g_OtgInfo.a_detect_b_resume == KAL_TRUE)
	{
		// compliance test
		// deassert resume
		g_OtgInfo.a_detect_b_resume = KAL_FALSE;

		ASSERT(0);
//		USB_DRV_SetBits8(USB_POWER, USB_POWER_RESUME);
//		OTG_Start_Timer(OTG_TIMER_A_RESUME, TA_RESUME);
	}
*/
#endif

	if(OTG_Is_TimerOut(OTG_TIMER_A_CHECK_VFALL) == KAL_TRUE)
	{
		OTG_Stop_Timer();
		OTG_Start_Timer(OTG_TIMER_A_CHECK_VFALL, TA_CHECK_VFALL);
	}
}


static void OTG_Process_B_Idle(void)
{
	/* Cable plugged out */
	/* If host or device is up, pull it down*/
	if(g_OtgInfo.host_up == KAL_TRUE)
	{
		g_OtgInfo.host_up = KAL_FALSE;
		g_OtgInfo.host_down_hdlr();
	}

	if(g_OtgInfo.device_up == KAL_TRUE)
	{
		g_OtgInfo.device_up = KAL_FALSE;
		g_OtgInfo.device_down_hdlr();
	}

	/*
	** When a B-device detects that the voltage on VBUS is greater
	** than the B-Device Session Valid threshold (VSESS_VLD),
	** then the B-device shall consider a session to be in progress.
	** After the VBUS voltage crosses this threshold, the B-device
	** shall assert either the D+ or D- data-line within 100 ms.
	*/
	if(g_OtgInfo.b_session_valid == KAL_TRUE)
	{
		/* SRP succeed */
		OTG_Process_B_Session_Valid();
	}
	else if(g_OtgInfo.b_srp_request == KAL_TRUE)
	{
		/*  ********* Starting  SRP *****************************************
		** When the B-device detects that VBUS has gone below its Session End
		** threshold and detects that both D+ and D- have been low (SE0) for
		** at least 2 ms (TB_SE0_SRP min), then any previous session on the
		** A-device is over and a new session may start. The B-device may
		** initiate the SRP any time the initial conditions of Section 5.3.2
		** are met.
		*/
		/* Wait 2ms is used only to make sure that host detect disconnect */

		/* Start the fail timer, OPT will wait 5s to vrise Vbus */
		OTG_Start_Timer(OTG_TIMER_B_SRP_FAIL, TB_SRP_FAIL);
		USB_DRV_SetBits8(USB_DEVCTL, USB_DEVCTL_SESSION);
//		kal_sleep_task(9);
		kal_sleep_task(22);
		USB_DRV_ClearBits8(USB_POWER, USB_POWER_SOFTCONN);

		g_OtgInfo.otg_state = OTG_STATE_B_SRP_INIT;
	}
}


static void OTG_Process_B_Session_Valid(void)
{
	/* Init device */
	if(g_OtgInfo.device_up == KAL_TRUE)
		EXT_ASSERT(0, (kal_uint32)g_OtgInfo.device_up, 0, 0);

	g_OtgInfo.device_up = KAL_TRUE;

	g_OtgInfo.otg_state = OTG_STATE_B_PERIPHERAL;
        // because device up handler will enable interrupt, change state first
		
	g_OtgInfo.device_up_hdlr();

	g_OtgInfo.b_srp_request = KAL_FALSE;

	USB_Dbg_Trace(USB_OTG_STATE_FROM_B_IDLE_TO_B_PERIPHERAL, 0, 0);
//	g_OtgInfo.otg_state = OTG_STATE_B_PERIPHERAL;
}


static void OTG_Process_B_SRP_Init(void)
{
	/*
	** When a B-device detects that the voltage on VBUS is greater than the
	** B-Device Session Valid threshold (VSESS_VLD), then the B-device
	** shall consider a session to be in progress. After the VBUS voltage
	** crosses this threshold, the B-device shall assert either the D+ or
	** D- data-line within 100 ms(TB_SVLD_BCON max).
	*/
	if(g_OtgInfo.b_session_valid == KAL_TRUE)
	{
		/* This section is executed in USB EINT context */
		/* SRP OK */
		OTG_Stop_Timer();
		/* OTG_B_SRP_Stop_Hdlr(void) */
		/* OTG_Display_Message(OTG_DISPLAY_MSG_STOP_CONNECTING); */
		g_OtgInfo.b_srp_stop_hdlr();
		OTG_Process_B_Session_Valid();
	}
	else if (OTG_Is_TimerOut(OTG_TIMER_B_SRP_FAIL) == KAL_TRUE)
	{
		/*
		** The error call back have the following requirement:
		** After initiating SRP, the B-device is required to wait at least
		** 5 seconds (TB_TB_SRP_FAIL min) for the A-device to respond,
		** before informing the user that the communication attempt
		** has failed.
		**
		*/

		/* SRP fail */
		OTG_Stop_Timer();

		g_OtgInfo.b_srp_request = KAL_FALSE;
		g_OtgInfo.otg_state = OTG_STATE_B_IDLE;

		/* OTG_B_SRP_Fail_Hdlr(void) */
		/* OTG_Display_Message(OTG_DISPLAY_MSG_NO_RESPONSE); */
		g_OtgInfo.b_srp_fail_hdlr();

		OTG_Process_B_Idle();
	}
}


static void OTG_Process_B_Peripheral(void)
{
	/* b_detect_a_suspend will be processed by the DEVICE ISR */
	/*
	** B-device detects that bus is idle for more than 4 ms
	** (TB_AIDL_BDIS min) and begins HNP by turning off pull-up on D+.
	** This allows the bus to discharge to the SE0 state.
	** The following will be done when this happens:
	**
	**   disconnect its pull up
	**   allow time for the data line to discharge
	**   check if the A-device has connected its pull up
	*/
	if((g_OtgInfo.b_hnp_enable == KAL_TRUE)&&(g_OtgInfo.b_detect_a_suspend == KAL_TRUE))
	{
//		OTG_Stop_Timer();
//		USB_DRV_WriteReg8(USB_INTRUSBE, 0xFF);

		g_OtgInfo.b_detect_a_suspend = KAL_FALSE;

		/* Start up host */
		if((g_OtgInfo.device_up == KAL_FALSE) ||(g_OtgInfo.host_up == KAL_TRUE))
			EXT_ASSERT(0, (kal_uint32)g_OtgInfo.device_up, (kal_uint32)g_OtgInfo.host_up, 0);

		/* To prevent a case that A-device suspend but it does not do HNP correctly, so B-device must go back to peripheral */
		/* In this case, we do not want to UEM see cable in/out event */
		g_OtgInfo.device_up = KAL_FALSE;
		/* Do not execute device_down_hdlr yet */
//		g_OtgInfo.device_down_hdlr();
		g_OtgInfo.b_device_down_pending = KAL_TRUE;
		USB_Dbg_Trace(USB_OTG_B_DEVICE_PENDING_DOWN_HDLR, 0, 1);

		g_OtgInfo.host_up = KAL_TRUE;
		g_OtgInfo.host_up_hdlr();

		USB_Dbg_Trace(USB_OTG_STATE_FROM_B_PERIPHERAL_TO_B_WAIT_ACON, 0, 0);
		g_OtgInfo.otg_state = OTG_STATE_B_WAIT_ACON;

		if(g_OtgInfo.suspend_and_conn_intr == KAL_FALSE)
		{
			// Start timer to check if A resume
			OTG_Start_Timer(OTG_TIMER_B_CHECK_A_RESUME, TB_CHECK_A_RESUME);
		}
	}
}


static void OTG_Process_B_Wait_ACon(void)
{
	/*
	** After waiting long enough to insure that the D+ line
	** cannot be high due to the residual effect of the B-device
	** pull-up,(see Section 5.1.9), the B-device sees that the
	** D+ line is high and D- low, (i.e. J state). This indicates
	** that the A-device has recognized the HNP request from the
	** B-device. At this point, the B-device becomes Host and
	** asserts bus reset to start using the bus. The B-device
	** must assert the bus reset (SE0) within 1 ms (TB_ACON_BSE0 max)
	** of the time that the A-device turns on its
	** pull-up.
	*/
	/* After A connect interrupt, B host must reset within 1ms */
	/* Conn will be processed by the USB_HCD_HISR */
	if(g_OtgInfo.b_detect_a_conn == KAL_TRUE)
	{
		OTG_Stop_Timer();

		/* Execute device_down_hdlr when B device become host */
		if(g_OtgInfo.b_device_down_pending == KAL_TRUE)
		{
			g_OtgInfo.b_device_down_pending = KAL_FALSE;
			g_OtgInfo.device_down_hdlr();
			USB_Dbg_Trace(USB_OTG_B_DEVICE_PENDING_DOWN_HDLR, 0, 2);
		}

		g_OtgInfo.b_suspend_req = KAL_FALSE;
		g_OtgInfo.b_hnp_enable = KAL_FALSE;
//		USB_DRV_ClearBits8(USB_DEVCTL, USB_DEVCTL_HOSTREQ);
		USB_DRV_ClearBits8(USB_POWER, USB_POWER_SOFTCONN);

		USB_Dbg_Trace(USB_OTG_STATE_FROM_B_WAIT_ACON_TO_B_HOST, 0, 0);
		g_OtgInfo.otg_state = OTG_STATE_B_HOST;
	}
	/*
	** While waiting in the b_wait_acon state, the B-device
	** may detect a K state on the bus. This indicates that the
	** A-device is signaling a resume condition and is retaining
	** control of the bus. In this case, the B-device will return
	** to the b_peripheral state.
	*/
	/*
	** If the B-device at any time detects more than 3.125 ms of SE0
	** (TB_ASE0_BRST min), then this is an indication that the
	** A-device is remaining Host and is resetting the bus. In this
	** case the B-device shall return to the b_peripheral state
	** and start to process the bus reset before TB_ASE0_BRST max.
	*/
	/*
	** b_detect_a_resume will be set by the host ISR when K state is
	** detected  if (b_detect_a_resume || b_ase0_brst_tmr)
	*/
	else if (OTG_Is_TimerOut(OTG_TIMER_B_CHECK_A_RESUME) == KAL_TRUE)
	{
		/* Stop the timer */
		OTG_Stop_Timer();

		// Start timer to wait A to connect
		OTG_Start_Timer(OTG_TIMER_B_ASE0_BRST, TB_ASE0_BRST);
      	}
	else if ((g_OtgInfo.b_detect_a_resume == KAL_TRUE)||(g_OtgInfo.b_detect_a_reset == KAL_TRUE)||(OTG_Is_TimerOut(OTG_TIMER_B_ASE0_BRST) == KAL_TRUE))
	{
		/* A suspend and then resume */
		g_OtgInfo.b_detect_a_resume = KAL_FALSE;
		/* A suspend and then reset */
		g_OtgInfo.b_detect_a_reset = KAL_FALSE;
		g_OtgInfo.b_hnp_enable = KAL_FALSE;

		/* HNP fail,  this is caused by A-device does not pull up D+ */
		/***********************************************************
		OPT test 5.8 and 5.9 require that we must display a message
		when a HNP fails. This event should allow the application
		to know  that HNP failed with Host.
		***********************************************************/
		if(OTG_Is_TimerOut(OTG_TIMER_B_ASE0_BRST) == KAL_TRUE)
		{
			/* time out */
			/* OTG_B_HNP_Fail_Hdlr(void) */
			/* OTG_Display_Message(OTG_DISPLAY_MSG_NO_RESPONSE); */
			g_OtgInfo.b_hnp_fail_hdlr();
	#ifndef __OTG_SRP_HNP_APP_FIXED__
			/* If cable quality is very bad, we try to use full speed */
			USB_DRV_ClearBits8(USB_POWER, USB_POWER_HSENAB);
	#endif
		}

		/* Stop the timer */
		OTG_Stop_Timer();

		/* Start up device */
		if((g_OtgInfo.host_up == KAL_FALSE)||(g_OtgInfo.device_up == KAL_TRUE))
			EXT_ASSERT(0, (kal_uint32)g_OtgInfo.host_up, (kal_uint32)g_OtgInfo.device_up, 0);

		g_OtgInfo.host_up = KAL_FALSE;
		g_OtgInfo.host_down_hdlr();

		g_OtgInfo.device_up = KAL_TRUE;

		if(g_OtgInfo.b_device_down_pending == KAL_TRUE)
		{
			g_OtgInfo.b_device_down_pending = KAL_FALSE;
			USB_Dbg_Trace(USB_OTG_B_DEVICE_PENDING_DOWN_HDLR, 0, 3);
		}
		else
		{
			g_OtgInfo.device_up_hdlr();
		}

		/* Clear this bit make DP re-connect */
		USB_DRV_ClearBits8(USB_DEVCTL, USB_DEVCTL_HOSTREQ);

		USB_Dbg_Trace(USB_OTG_STATE_FROM_B_WAIT_ACON_TO_B_PERIPHERAL, 0, 0);
		g_OtgInfo.otg_state = OTG_STATE_B_PERIPHERAL;
	}
}


static void OTG_Process_B_Host(void)
{
	/* HNP phase 2, B transfer from host to peripheral, or A peripheral want to disconnect */
	if((g_OtgInfo.b_suspend_req == KAL_TRUE)||(g_OtgInfo.b_detect_a_conn == KAL_FALSE))
	{
		/* Start up device */
		if((g_OtgInfo.host_up == KAL_FALSE)||(g_OtgInfo.device_up == KAL_TRUE))
			EXT_ASSERT(0, (kal_uint32)g_OtgInfo.host_up, (kal_uint32)g_OtgInfo.device_up, 0);

		g_OtgInfo.host_up = KAL_FALSE;
		g_OtgInfo.host_down_hdlr();

		/* Set suspend */
		if(g_OtgInfo.b_suspend_req == KAL_TRUE)
		{
			USB_DRV_SetBits8(USB_POWER, USB_POWER_SUSPENDMODE);
		}

		g_OtgInfo.device_up = KAL_TRUE;
		g_OtgInfo.device_up_hdlr();

		USB_Dbg_Trace(USB_OTG_STATE_FROM_B_HOST_TO_B_PERIPHERAL, USB_DRV_Reg8(USB_POWER), 3);
		g_OtgInfo.otg_state = OTG_STATE_B_PERIPHERAL;
	}
}





static void OTG_State_Machine(void)
{
	static kal_bool	b_processing = KAL_FALSE;


	if(b_processing == KAL_TRUE)
		ASSERT(0);

	b_processing = KAL_TRUE;

	switch(g_OtgInfo.otg_state)
	{
	case OTG_STATE_START:
		USB_Dbg_Trace(USB_OTG_STATE_START, 0, 0);
		if(OTG_Get_Plug_Type() == OTG_PLUG_B)
		{
			g_OtgInfo.otg_state = OTG_STATE_B_IDLE;
			OTG_Process_B_Idle();
 		}
 		else
		{
			/* ID is false when A device is identified */
	#ifdef OTG_A_NOT_INSERTION_BASE
			/* for SRP compliance test */
			/* When mini a plug in, turn on VBUS only after SPR */
			g_OtgInfo.a_bus_req = KAL_FALSE;
	#else
			g_OtgInfo.a_bus_req = KAL_TRUE;
	#endif
			g_OtgInfo.otg_state = OTG_STATE_A_IDLE;
			OTG_Process_A_Idle();
		}
		break;
	case OTG_STATE_A_IDLE:
		USB_Dbg_Trace(USB_OTG_STATE_A_IDLE, 0, 0);
		OTG_Process_A_Idle();
		break;
	case OTG_STATE_A_WAIT_BCON:
		USB_Dbg_Trace(USB_OTG_STATE_A_WAIT_BCON, (kal_uint32)g_OtgInfo.a_detect_b_conn, 0);
		OTG_Process_A_Wait_BCon();
		break;
	case OTG_STATE_A_HOST:
		USB_Dbg_Trace(USB_OTG_STATE_A_HOST, 0, 0);
		OTG_Process_A_Host();
		break;
	case OTG_STATE_A_SUSPEND:
		USB_Dbg_Trace(USB_OTG_STATE_A_SUSPEND, 0, 0);
		OTG_Process_A_Suspend();
		break;
	case OTG_STATE_A_PERIPHERAL:
		USB_Dbg_Trace(USB_OTG_STATE_A_PERIPHERALE, (kal_uint32)g_OtgInfo.a_detect_b_suspend, 0);
		OTG_Process_A_Peripheral();
		break;
	case OTG_STATE_A_WAIT_VFALL:
		USB_Dbg_Trace(USB_OTG_STATE_A_WAIT_VFALL, 0, 0);
		OTG_Process_A_Wait_VFall();
		break;
	case OTG_STATE_B_IDLE:
		USB_Dbg_Trace(USB_OTG_STATE_B_IDLE, 0, 0);
		OTG_Process_B_Idle();
		break;
	case OTG_STATE_B_SRP_INIT:
		USB_Dbg_Trace(USB_OTG_STATE_B_SRP_INIT, 0, 0);
		OTG_Process_B_SRP_Init();
		break;
	case OTG_STATE_B_PERIPHERAL:
		USB_Dbg_Trace(USB_OTG_STATE_B_PERIPHERAL, (kal_uint32)g_OtgInfo.b_hnp_enable, (kal_uint32)g_OtgInfo.b_detect_a_suspend);
		OTG_Process_B_Peripheral();
		break;
	case OTG_STATE_B_WAIT_ACON:
		USB_Dbg_Trace(USB_OTG_STATE_B_WAIT_ACON, (kal_uint32)g_OtgInfo.b_detect_a_conn, 0);
		OTG_Process_B_Wait_ACon();
		break;
	case OTG_STATE_B_HOST:
		USB_Dbg_Trace(USB_OTG_STATE_B_HOST, (kal_uint32)g_OtgInfo.b_suspend_req, (kal_uint32)g_OtgInfo.b_detect_a_conn);
		OTG_Process_B_Host();
		break;
	default:
		ASSERT(0);
		break;
	}

	b_processing = KAL_FALSE;
}




/************************************************************
	HISR/LISR   interrupt handler
*************************************************************/
void OTG_Set_Intr()
{
	volatile kal_uint8	IntrUSB;
	
	IntrUSB = USB_DRV_Reg8(USB_INTRUSB);
	g_OtgInfo.otg_intr_status = IntrUSB;
}




static void OTGDMA_HISR(void)
{
	kal_uint8  	DMAIntr;
	kal_uint32  	index;


#if defined(DRV_USB_IP_V3)
	DMAIntr = USB_DRV_Reg8(USB_DMAINTR);
#elif defined(DRV_USB_IP_V4)
	DMAIntr = USB_DRV_Reg8(USB_DMA_INTR_STATUS);
#endif


	while(DMAIntr != 0)
	{
		for(index = 0; index < MAX_DMA_NUM; index++)
		{
			if((DMAIntr&(1<<index)) != 0)
			{
#if defined(DRV_USB_IP_V3)
				// write 0 clear first, then do call back function, order is very important !!!
				USB_DRV_WriteReg8(USB_DMAINTR, ~(0x01<<index));
#elif defined(DRV_USB_IP_V4)
			// write 1 clear first, then do call back function, order is very important !!!
				USB_DRV_WriteReg8(USB_DMA_INTR_STATUS, (0x01<<index));
#endif
				if ((USB_HCD_DMA_Get_Run_Status(0, index+1) == KAL_TRUE)||(g_UsbDrvInfo.dma_running[index] == KAL_TRUE))
				{	
					// cannot be host & device at the same time
					if ((USB_HCD_DMA_Get_Run_Status(0, index+1) == KAL_TRUE)&&(g_UsbDrvInfo.dma_running[index] == KAL_TRUE))
						ASSERT(0);
					
					/* DMA channel index+1 have interrupt */
					if(USB_DRV_Reg32(USB_DMA_REALCNT(index+1)) != 0)
					{
						if(USB_HCD_DMA_Get_Run_Status(0, index+1) == KAL_TRUE)
						{
							USB_HCD_DMA_Callback(0, index+1);
						}
						else if(g_UsbDrvInfo.dma_running[index] == KAL_TRUE)
						{
							USB_DMA_Callback(index+1);
						}
					}
					else
					{
						if(USB_Check_DMA_Time_Out(index+1) == KAL_TRUE)
						{
							if(USB_HCD_DMA_Get_Run_Status(0, index+1) == KAL_TRUE)
							{
								USB_HCD_DMA_Callback(0, index+1);
							}
							else if(g_UsbDrvInfo.dma_running[index] == KAL_TRUE)
							{
								USB_DMA_Callback(index+1);
							}
						}
						else
						{						
							drv_trace4(TRACE_FUNC, (kal_uint32)USB_OTG_DMA_STATUS, USB_DRV_Reg32(USB_DMA_REALCNT(index+1)),USB_DRV_Reg32(USB_DMACNT(index+1)), USB_HCD_DMA_Get_Run_Status(0, index+1), g_UsbDrvInfo.dma_running[index]);
//							ASSERT(0);
						}
						// DMA timer time out
						
	/*
						if(index == 0)
						{
							// set address
							USB_DMA_Callback(index+1);
						}
						else
						{
							USB_DRV_SetBits(USB_DMACNTL(index+1), USB_DMACNTL_DMAEN);
						}
	*/
					}
				}
			}
		}

		/* Read register again to see if any interrupt is generated again */
		/* if ping pong buffer serve done, then we do call back function here */
#if defined(DRV_USB_IP_V3)
		DMAIntr = USB_DRV_Reg8(USB_DMAINTR);
#elif defined(DRV_USB_IP_V4)
		DMAIntr = USB_DRV_Reg8(USB_DMA_INTR_STATUS);
#endif
		
	}

#if defined(DRV_USB_IP_V3)
	IRQClearInt(IRQ_USBDMA_CODE);
	IRQUnmask(IRQ_USBDMA_CODE);
#endif	
}





#if defined(DRV_USB_IP_V4)

static void OTGDMAQ_HISR(void)
{
	volatile kal_uint32  	DMAQIntr;
	static kal_uint32  	temp;
	kal_uint32  	index;
	kal_uint8  	ep_num;

	DMAQIntr = DRV_Reg32(USB_DMAQ_QISAR);

	while(DMAQIntr != 0)
	{
		DRV_WriteReg32(USB_DMAQ_QISAR, DMAQIntr); //write 1 clear

		for (index = 0; index < DMAQ_MAX_NUMBERS; index++)
		{	
			ep_num = index + 1; // DMAQ 0 mapping to EP 1 , DMAQ 1 mapping to EP 2
			
			if (DMAQIntr & USB_DMAQ_QISAR_TXQ_EMPYT_INT) // can check DMAQ Activate bit
			{	
				DRV_WriteReg32(USB_DMAQ_TQEMIR,DRV_Reg32(USB_DMAQ_TQEMIR));
			}
			
			if (DMAQIntr & USB_DMAQ_QISAR_RXQ_EMPTY_INT)	 // can check DMAQ Activate bit
			{		
				DRV_WriteReg32(USB_DMAQ_RQEMIR,DRV_Reg32(USB_DMAQ_RQEMIR));
			}
			
			if (DMAQIntr & USB_DMAQ_QISAR_RXQ_ERR_INT)
			{	
				if (DRV_Reg32(USB_DMAQ_RQEIR) & (USB_DMAQ_QIMCR0 << index))			
				{
					ASSERT(0);			// Error handler
					DRV_WriteReg32(USB_DMAQ_RQEIR, DRV_Reg32(USB_DMAQ_RQEIR)); //write 1 clear
				}						
			}
			
			if (DMAQIntr & USB_DMAQ_QISAR_TXQ_ERR_INT)	
			{
				if (DRV_Reg32(USB_DMAQ_TQEIR)& (USB_DMAQ_QIMCR0 << index))				
				{
					ASSERT(0);  // Error handler
					DRV_WriteReg32(USB_DMAQ_TQEIR, DRV_Reg32(USB_DMAQ_TQEIR)); //write 1 clear
				}		
			}
			
			if (DMAQIntr & USB_DMAQ_QISAR_RXEP_ERR_INT)	
			{
				if (DRV_Reg32(USB_DMAQ_REPEIR) & (USB_DMAQ_QIMCR0 << index))
				{
					ASSERT(0);					// Error handler				
					DRV_WriteReg32(USB_DMAQ_REPEIR, DRV_Reg32(USB_DMAQ_REPEIR)); //write 1 clear
				}								
			}
			
			if (DMAQIntr & USB_DMAQ_QISAR_TXEP_ERR_INT)	
			{
				if (DRV_Reg32(USB_DMAQ_TEPEIR) & (USB_DMAQ_QIMCR0 << index))
				{
					ASSERT(0);		// Error handler							
					DRV_WriteReg32(USB_DMAQ_TEPEIR, DRV_Reg32(USB_DMAQ_TEPEIR)); //write 1 clear
				}				
			}

			
			if (DMAQIntr & USB_DMAQ_QISAR_RX_DONE(index)) // IOC trigger interrupt
			{	// this GPD transfer done, HW is still reading next GPD
			
				if(USB_HCD_DMA_Get_Run_Status(0, index+1) == KAL_TRUE)
				{
					USB_HCD_DMAQ_Callback(0,index,USB_EP_RX_DIR);
				}
				else if(g_UsbDrvInfo.dma_running[index] == KAL_TRUE)
				{
					USB_DMA_Callback(index+1);
				}
			}
			
			if (DMAQIntr & USB_DMAQ_QISAR_TX_DONE(index))
			{
				if(USB_HCD_DMA_Get_Run_Status(0, index+1) == KAL_TRUE)
				{
					USB_HCD_DMAQ_Callback(0,index,USB_EP_TX_DIR);
}
				else if(g_UsbDrvInfo.dma_running[index] == KAL_TRUE)
				{
					USB_DMA_Callback(index+1);
				}
			}			
		}
		
		/* Read register again to see if any interrupt is generated again */
			/* if pong pong buffer serve done, then we do call back function here */
			DMAQIntr = DRV_Reg32(USB_DMAQ_QISAR);
			DRV_WriteReg32(USB_DMAQ_QISAR, DMAQIntr); //write 1 clear
	}	

}
#endif	


static void OTGDMA_LISR(void)
{
	kal_uint8  DMAIntr;

#if defined(DRV_USB_IP_V3)

	IRQMask(IRQ_USBDMA_CODE);
	drv_active_hisr(DRV_USBDMA_HISR_ID);
	DMAIntr = USB_DRV_Reg8(USB_DMAINTR);
	USB_Dbg_Trace(USB_DMA_LISR, DMAIntr, 0);
	ASSERT(DMAIntr != 0);
#endif
}

void OTG_HISR(void)
{
	kal_bool	b_dev_unmask_irq = KAL_TRUE;
	volatile kal_uint8	IntrUSB;
#ifdef __MEUT__		
	kal_bool b_otg_hisr_is_handled = KAL_FALSE;
#endif


	IntrUSB = USB_DRV_Reg8(USB_INTRUSB);
	g_OtgInfo.otg_intr_status = IntrUSB;
	USB_Dbg_Trace(USB_OTG_HISR, IntrUSB, USB_DRV_Reg8(USB_POWER));

#ifdef __MEUT__	
	if ((IntrUSB == 0)&&(g_OtgInfo.host_up == KAL_FALSE)&&(g_OtgInfo.device_up == KAL_FALSE))
	{
		if ((USB_DRV_Reg(USB_INTRTX)== 0)&&(USB_DRV_Reg(USB_INTRRX)== 0))
			b_otg_hisr_is_handled = KAL_TRUE;	
	}	

	if(IntrUSB != 0)
	{
		b_otg_hisr_is_handled = KAL_TRUE;
	}
#endif

	if((IntrUSB&USB_INTRUSB_RESET) != 0)
	{
		if(OTG_Get_State() == OTG_STATE_B_WAIT_ACON)
		{
			USB_Dbg_Trace(USB_OTG_RESET, 0, 0);
			OTG_Set_Status(OTG_STATUS_B_DETECT_A_RESET, KAL_TRUE);
		}
	}

	if((IntrUSB&USB_INTRUSB_RESUME) != 0)
	{
		if((g_OtgInfo.device_up == KAL_FALSE)&&(g_OtgInfo.otg_state == OTG_STATE_B_WAIT_ACON))
		{
			USB_Dbg_Trace(USB_OTG_RESUME, 0, 0);
			OTG_Set_Status(OTG_STATUS_B_DETECT_A_RESUME, KAL_TRUE);
		}
	}

	/* SRP detection, Only A-device */
	if((IntrUSB&USB_INTRUSB_SESSREQ) != 0)
	{
		USB_Dbg_Trace(USB_OTG_SESSREQ, USB_DRV_Reg8(USB_OPSTATE), USB_DRV_Reg8(USB_DEVCTL));
		drv_trace4(TRACE_FUNC, (kal_uint32)USB_OTG_SESSION_REQUEST, IntrUSB, USB_DRV_Reg8(USB_POWER), USB_DRV_Reg8(USB_LINE_STATE), USB_DRV_Reg8(USB_OPSTATE));

		if((OTG_Get_Plug_Type() == OTG_PLUG_A)&&(g_OtgInfo.otg_state != OTG_STATE_A_WAIT_VFALL))
		{ //receive un-expected interrupt after Vbus error
			OTG_Set_Status(OTG_STATUS_A_DETECT_B_DATA_PLS, KAL_TRUE);
		}
		else
		{
			if(USB_DRV_Reg8(USB_OPSTATE) != 0x00)
				ASSERT(0);
			//receive babble interrupt will force HW jump to idle state (0x00)--> cannot receive session interrupt.
		}
	}

	/* VBUS error, A device only */
	if((IntrUSB&USB_INTRUSB_VBUSERROR) != 0)
	{
		if(OTG_Get_Plug_Type() == OTG_PLUG_A)
		{
			drv_trace0(TRACE_FUNC, (kal_uint32)USB_OTG_VBUS_FALL_DOWN);
		
			/* IP detect every 543ms, Vbus is still lower than 4.4V it will issue this intr and auto turn off Vbus */
			OTG_Process_A_Vbus_Fail();
		}
		else
		{
			ASSERT(0);
		}
	}

	if((IntrUSB&USB_INTRUSB_CONN) != 0)
	{

	}

	if(g_OtgInfo.host_up == KAL_TRUE)
	{
		/* set TRUE in A_WAIT_BCON */
		/* set TRUE in B_WAIT_ACON */
		/* set FALSE in OTG_STATE_A_PERIPHERAL */
		/* set FALSE in OTG_STATE_B_PERIPHERAL */
		/* set FALSE in B_IDLE */
		/* set FALSE in OTG_STATE_A_WAIT_VFALL */
		/* Host mode */
		USB_HCD_HISR();
		b_dev_unmask_irq = USB_HCD_Get_UnMask_Irq(0);
		
#ifdef __MEUT__			
		b_otg_hisr_is_handled = KAL_TRUE;
#endif

	#ifdef __OTG_SRP_HNP_APP_FIXED__
		/* Mask USB IRQ to prevent host reset too fast, even USB device does not become MS yet */
		/* From A suspend to A peripheral */
		if(g_OtgInfo.device_up == KAL_TRUE)
		{
			b_dev_unmask_irq = USB_HW_Get_UnMask_Irq();
		}
	#endif
	}
	else if(g_OtgInfo.device_up == KAL_TRUE)
	{
		/* set TRUE in OTG_STATE_A_PERIPHERAL */
		/* set TRUE in OTG_STATE_B_PERIPHERAL */
		/* set FALSE in OTG_STATE_A_WAIT_VFALL */
		/* set FALSE in OTG_STATE_A_WAIT_VRISE & A_IDLE */
		/* set FALSE in OTG_STATE_A_WAIT_BCON */
		/* set FALSE in OTG_STATE_B_WAIT_ACON */
		/* set FALSE in OTG_STATE_B_IDLE */
		/* Device mode */
		USB_HISR();
		b_dev_unmask_irq = USB_HW_Get_UnMask_Irq();
		
#ifdef __MEUT__			
		b_otg_hisr_is_handled = KAL_TRUE;
#endif		
	}

	if((IntrUSB&USB_INTRUSB_DISCON) != 0)
	{

	}

	if((IntrUSB&USB_INTRUSB_SUSPEND) != 0)
	{

	}

	//debug used
	if((IntrUSB&USB_INTRUSB_SOF) != 0)
	{
//		USB_Dbg_Trace(USB_OTG_SOF, USB_DRV_Reg8(USB_LINE_STATE), USB_DRV_Reg8(USB_OPSTATE));
//		USB_Dbg_Trace(USB_OTG_SOF, USB_DRV_Reg8(USB_DEVCTL), USB_DRV_Reg8(USB_PHYIR2_0));
	}

#ifdef __MEUT__			
	if((b_otg_hisr_is_handled == KAL_FALSE) && (INT_Exception_Enter ==0))
		EXT_ASSERT(0, USB_DRV_Reg(USB_INTRTX), USB_DRV_Reg(USB_INTRRX), 0);
#endif

#if defined(DRV_USB_IP_V4)
		OTGDMA_HISR();

		OTGDMAQ_HISR();
#endif

	/* Clear interrupt and unmask interrupt */
   	IRQClearInt(IRQ_USB_CODE);
   	g_OtgInfo.is_ProOTGHISR = KAL_FALSE;

	if((g_OtgInfo.b_unmask_irq == KAL_TRUE)&&(b_dev_unmask_irq == KAL_TRUE))
	{
		IRQUnmask(IRQ_USB_CODE);
	}
	else
	{
		USB_Dbg_Trace(USB_OTG_MASK_HISR, (kal_uint32)g_OtgInfo.b_unmask_irq, (kal_uint32)b_dev_unmask_irq);
	}
}


static void OTG_LISR(void)
{
	IRQMask(IRQ_USB_CODE);
	g_OtgInfo.is_ProOTGHISR = KAL_TRUE;
	drv_active_hisr(DRV_USB_HISR_ID);
}


/* Global variables */
#define DCL_OTG_DRV_HANDLE  	0x00004000
#define DCL_OTG_DRV_CHECK_HANDLE_IS_VALID(handle) ((handle)&DCL_OTG_DRV_HANDLE)


/* static variables */
static kal_bool g_OTG_Drv_Init = KAL_FALSE;
static kal_bool g_OTG_Drv_Open = KAL_FALSE;



/*************************************************************************
* FUNCTION
*  DclOTG_DRV_Initialize
*
* DESCRIPTION
*  This function is to initialize OTG module
*  It should be called before user register USB EINT handler and only called once
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK : command is executed successfully.
*  STATUS_INVALID_OPERATION : already initialized.
*
*************************************************************************/
DCL_STATUS DclOTG_DRV_Initialize(void)
{
	if(g_OTG_Drv_Init == KAL_TRUE)
	{
		/* Already initialized */
		return STATUS_INVALID_OPERATION;
	}
	else
	{
		g_OTG_Drv_Init = KAL_TRUE;
//		USB_Initialize_Drv_Phase1();
		return STATUS_OK;
	}
}


/*************************************************************************
* FUNCTION
*  DclOTG_DRV_Open
*
* DESCRIPTION
*  This function is to open the OTG module and return a valid handle
*
* PARAMETERS
*  dev: only valid for DCL_USB
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed
*  DCL_HANDLE_OCCUPIED: Already opened
*  Other value: A valid handle
*
*************************************************************************/
DCL_HANDLE DclOTG_DRV_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	if(dev != DCL_USB)
	{
		ASSERT(0);
		return (DCL_HANDLE)DCL_HANDLE_INVALID;
	}
	else
	{
		g_OTG_Drv_Open = KAL_TRUE;
		return (DCL_HANDLE)DCL_OTG_DRV_HANDLE;
	}
}

/*************************************************************************
* FUNCTION
*  DclOTG_DRV_Close
*
* DESCRIPTION
*  This function is to close the OTG module.
*
* PARAMETERS
*  handle: the returned handle value of DclOTG_DRV_Open
*
* RETURNS
*  STATUS_INVALID_OPERATION: OTG module does not open yet, but user want to close
*  STATUS_INVALID_DCL_HANDLE: Use invalid handle to close
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS DclOTG_DRV_Close(DCL_HANDLE handle)
{
	/* Check open or not and handle validity */
	
	if(DCL_OTG_DRV_CHECK_HANDLE_IS_VALID(handle) == 0)
	{
		ASSERT(0);

//		if(g_OTG_Drv_Open == KAL_FALSE)
//			return STATUS_INVALID_OPERATION;
//		else
//			return STATUS_INVALID_DCL_HANDLE;
	}

//	g_OTG_Drv_Open = KAL_FALSE;

	return STATUS_OK;
}


/*************************************************************************
* FUNCTION
*  DclOTG_DRV_ReadData
*
* DESCRIPTION
*  This function is not supported for the OTG module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclOTG_DRV_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	/* Check open or not and handle validity */
/*	
	if((g_OTG_Drv_Open == KAL_FALSE)||(DCL_OTG_DRV_CHECK_HANDLE_IS_VALID(handle) == 0))
	{
		ASSERT(0);

		if(g_OTG_Drv_Open == KAL_FALSE)
			return STATUS_INVALID_OPERATION;
		else
			return STATUS_INVALID_DCL_HANDLE;
	}
*/
	return STATUS_UNSUPPORTED;
}



/*************************************************************************
* FUNCTION
*  DclOTG_DRV_WriteData
*
* DESCRIPTION
*  This function is not supported for the OTG module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclOTG_DRV_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	/* Check open or not and handle validity */
/*	
	if((g_OTG_Drv_Open == KAL_FALSE)||(DCL_OTG_DRV_CHECK_HANDLE_IS_VALID(handle) == 0))
	{
		ASSERT(0);

		if(g_OTG_Drv_Open == KAL_FALSE)
			return STATUS_INVALID_OPERATION;
		else
			return STATUS_INVALID_DCL_HANDLE;
	}
*/
	return STATUS_UNSUPPORTED;
}



/*************************************************************************
* FUNCTION
*  DclOTG_DRV_Configure
*
* DESCRIPTION
*  This function is not supported for the OTG module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclOTG_DRV_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	/* Check open or not and handle validity */
/*	
	if((g_OTG_Drv_Open == KAL_FALSE)||(DCL_OTG_DRV_CHECK_HANDLE_IS_VALID(handle) == 0))
	{
		ASSERT(0);

		if(g_OTG_Drv_Open == KAL_FALSE)
			return STATUS_INVALID_OPERATION;
		else
			return STATUS_INVALID_DCL_HANDLE;
	}
*/
	return STATUS_UNSUPPORTED;
}



/*************************************************************************
* FUNCTION
*  DclOTG_DRV_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the OTG module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclOTG_DRV_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	/* Check open or not and handle validity */
/*	
	if((g_OTG_Drv_Open == KAL_FALSE)||(DCL_OTG_DRV_CHECK_HANDLE_IS_VALID(handle) == 0))
	{
		ASSERT(0);

		if(g_OTG_Drv_Open == KAL_FALSE)
			return STATUS_INVALID_OPERATION;
		else
			return STATUS_INVALID_DCL_HANDLE;
	}
*/
	return STATUS_UNSUPPORTED;
}



/*******************************************************************************
	Control functions for OTG_DRV
 *******************************************************************************/
static DCL_STATUS DCL_USB_CTRL_API_OTG_Init_Drv_Info(DCL_CTRL_DATA_T *data)
{
	g_OtgInfo.otg_state = OTG_STATE_START;

	g_OtgInfo.host_up_hdlr = NULL;
	g_OtgInfo.host_down_hdlr = NULL;
	g_OtgInfo.device_up_hdlr = NULL;
	g_OtgInfo.device_down_hdlr = NULL;
	g_OtgInfo.a_host_stop_hdlr = NULL;
	g_OtgInfo.b_hnp_fail_hdlr = NULL;
	g_OtgInfo.a_vrise_fail_hdlr = NULL;
	g_OtgInfo.b_srp_fail_hdlr = NULL;
	g_OtgInfo.b_srp_stop_hdlr = NULL;

	g_OtgInfo.a_bus_req = KAL_TRUE;
	g_OtgInfo.a_detect_b_conn = KAL_FALSE;
	g_OtgInfo.a_detect_b_suspend = KAL_FALSE;
	g_OtgInfo.a_detect_b_resume = KAL_FALSE;
	g_OtgInfo.a_suspend_req = KAL_FALSE;
	g_OtgInfo.a_resume_req = KAL_FALSE;
	g_OtgInfo.a_set_b_hnp_enable = KAL_FALSE;

	g_OtgInfo.b_suspend_req = KAL_FALSE;
	g_OtgInfo.b_detect_a_conn = KAL_FALSE;
	g_OtgInfo.b_detect_a_suspend = KAL_FALSE;
	g_OtgInfo.b_detect_a_resume = KAL_FALSE;
	g_OtgInfo.b_srp_request = KAL_FALSE;
	g_OtgInfo.b_hnp_enable = KAL_FALSE;


	g_OtgInfo.suspend_and_conn_intr = KAL_FALSE;
	g_OtgInfo.disconn_num = 0;

	g_OtgInfo.timer_on = KAL_FALSE;
	g_OtgInfo.timer_out = KAL_FALSE;
	g_OtgInfo.timer_type = OTG_TIMER_NONE;

	g_OtgInfo.device_up = KAL_FALSE;
	g_OtgInfo.host_up = KAL_FALSE;

	g_OtgInfo.b_processing = KAL_FALSE;

	g_OtgInfo.b_unmask_irq = KAL_TRUE;
	g_OtgInfo.is_ProOTGHISR = KAL_FALSE;

	if ((g_OtgInfo.gpt_handle == 0)||(g_OtgInfo.gpt_handle == 0x7F))
		g_OtgInfo.gpt_handle = DclSGPT_Open(DCL_GPT_CB, 0);
//		GPTI_GetHandle(&g_OtgInfo.gpt_handle);

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_Release_Drv_Info(DCL_CTRL_DATA_T *data)
{
	DCL_HANDLE handle;
	g_OtgInfo.otg_state = OTG_STATE_START;

	g_OtgInfo.host_up_hdlr = NULL;
	g_OtgInfo.host_down_hdlr = NULL;
	g_OtgInfo.device_up_hdlr = NULL;
	g_OtgInfo.device_down_hdlr = NULL;
	g_OtgInfo.a_host_stop_hdlr = NULL;
	g_OtgInfo.b_hnp_fail_hdlr = NULL;
	g_OtgInfo.a_vrise_fail_hdlr = NULL;
	g_OtgInfo.b_srp_fail_hdlr = NULL;
	g_OtgInfo.b_srp_stop_hdlr = NULL;

	g_OtgInfo.a_bus_req = KAL_TRUE;
	g_OtgInfo.a_detect_b_conn = KAL_FALSE;
	g_OtgInfo.a_detect_b_suspend = KAL_FALSE;
	g_OtgInfo.a_detect_b_resume = KAL_FALSE;
	g_OtgInfo.a_suspend_req = KAL_FALSE;
	g_OtgInfo.a_resume_req = KAL_FALSE;
	g_OtgInfo.a_set_b_hnp_enable = KAL_FALSE;

	g_OtgInfo.b_suspend_req = KAL_FALSE;
	g_OtgInfo.b_detect_a_conn = KAL_FALSE;
	g_OtgInfo.b_detect_a_suspend = KAL_FALSE;
	g_OtgInfo.b_detect_a_resume = KAL_FALSE;
	g_OtgInfo.b_srp_request = KAL_FALSE;
	g_OtgInfo.b_hnp_enable = KAL_FALSE;

	g_OtgInfo.timer_on = KAL_FALSE;
	g_OtgInfo.timer_out = KAL_FALSE;
	g_OtgInfo.timer_type = OTG_TIMER_NONE;

	g_OtgInfo.device_up = KAL_FALSE;
	g_OtgInfo.host_up = KAL_FALSE;

	g_OtgInfo.b_processing = KAL_FALSE;

	g_OtgInfo.b_unmask_irq = KAL_TRUE;
	g_OtgInfo.is_ProOTGHISR = KAL_FALSE;

	if((g_OtgInfo.gpt_handle != 0)&&(g_OtgInfo.gpt_handle != 0x7F))
	{	
		 	handle = (DCL_HANDLE)g_OtgInfo.gpt_handle;
			g_OtgInfo.gpt_handle = DclSGPT_Close(&handle);
	}
//		GPTI_ReleaseHandle(&g_OtgInfo.gpt_handle);

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_Register_Drv_Info(DCL_CTRL_DATA_T *data)
{
	OTG_DRV_CTRL_REGISTER_DRV_INFO_T *prregister_drv_info;
	OTG_DRV_HDLR_TYPE type;
	otg_intr_handler_ptr hdlr;


	prregister_drv_info = &data->rOTG_Drv_Info;
	type = (OTG_DRV_HDLR_TYPE)prregister_drv_info->type;
	hdlr = (otg_intr_handler_ptr)prregister_drv_info->hdlr;

	switch(type)
	{
	case OTG_DRV_HDLR_HOST_UP:
		g_OtgInfo.host_up_hdlr = hdlr;
		break;
	case OTG_DRV_HDLR_HOST_DOWN:
		g_OtgInfo.host_down_hdlr = hdlr;
		break;
	case OTG_DRV_HDLR_DEVICE_UP:
		g_OtgInfo.device_up_hdlr = hdlr;
		break;
	case OTG_DRV_HDLR_DEVICE_DOWN:
		g_OtgInfo.device_down_hdlr = hdlr;
		break;
	case OTG_DRV_HDLR_A_VRISE_FAIL:
		g_OtgInfo.a_vrise_fail_hdlr = hdlr;
		break;
	case OTG_DRV_HDLR_A_HNP_FAIL:
		g_OtgInfo.a_hnp_fail_hdlr = hdlr;
		break;
	case OTG_DRV_HDLR_A_HNP_STOP:
		g_OtgInfo.a_hnp_stop_hdlr = hdlr;
		break;
	case OTG_DRV_HDLR_A_NO_RESPONSE:
		g_OtgInfo.a_no_response_hdlr = hdlr;
		break;
	case OTG_DRV_HDLR_B_HNP_FAIL:
		g_OtgInfo.b_hnp_fail_hdlr = hdlr;
		break;
	case OTG_DRV_HDLR_B_SRP_FAIL:
		g_OtgInfo.b_srp_fail_hdlr = hdlr;
		break;
	case OTG_DRV_HDLR_B_SRP_STOP:
		g_OtgInfo.b_srp_stop_hdlr = hdlr;
		break;
	case OTG_DRV_HDLR_B_SRP_EXCEPTION_STOP:
		g_OtgInfo.b_srp_exception_stop_hdlr = hdlr;
		break;
	case OTG_DRV_HDLR_A_HOST_STOP:
		g_OtgInfo.a_host_stop_hdlr = hdlr;
		break;
	default:
		ASSERT(0);
		break;
	}


	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_Drv_Create_ISR(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_IP_V3)

	IRQ_Register_LISR(IRQ_USB_CODE, OTG_LISR, "OTG");
	DRV_Register_HISR(DRV_USB_HISR_ID, OTG_HISR);
#endif	
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_Drv_Activate_ISR(DCL_CTRL_DATA_T *data)
{
	g_OtgInfo.b_unmask_irq = KAL_TRUE;
#if defined(DRV_USB_IP_V3)
	IRQSensitivity(IRQ_USB_CODE,LEVEL_SENSITIVE);
	IRQUnmask(IRQ_USB_CODE);
#endif	
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTGDMA_Drv_Create_ISR(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_IP_V3)
	IRQ_Register_LISR(IRQ_USBDMA_CODE, OTGDMA_LISR, "OTGDMA");
	DRV_Register_HISR(DRV_USBDMA_HISR_ID, OTGDMA_HISR);
#endif
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTGDMA_Drv_Activate_ISR(DCL_CTRL_DATA_T *data)
{
#if defined(DRV_USB_IP_V3)

	IRQSensitivity(IRQ_USBDMA_CODE, LEVEL_SENSITIVE);
	IRQUnmask(IRQ_USBDMA_CODE);
#endif
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_Init_Drv(DCL_CTRL_DATA_T *data)
{
	kal_bool b_process_state_machine = KAL_FALSE;
	kal_uint32 savedMask;

	/* Software reset */
#if defined(DRV_USB_IP_V3)
	USB_DRV_WriteReg(USB_SWRST, (USB_SWRST_DISUSBRESET|USB_SWRST_SWRST));
#elif defined(DRV_USB_IP_V4)
	USB_DRV_SetBits(USB_BUSPERF3, (USB_BUSPERF3_DISUSBRESET|USB_BUSPERF3_SWRST));
#endif
//	USB_DRV_WriteReg8(USB_RSTINFO, 0xA6);
	USB_DRV_WriteReg8(USB_RSTINFO, 0xA0);

	/* Set USB_POWER_ISOUPDATE will make ISO pipe with DMA abnormally */
//	USB_DRV_SetBits8(USB_POWER, (USB_POWER_ISOUPDATE|USB_POWER_ENABLESUSPENDM));
	USB_DRV_SetBits8(USB_POWER, (USB_POWER_ENABLESUSPENDM));

#ifdef __USB_HS_ENABLE__
	USB_DRV_SetBits8(USB_POWER, USB_POWER_HSENAB);
#else
	USB_DRV_ClearBits8(USB_POWER, USB_POWER_HSENAB);
#endif

	/* SRP Vbus pulsing duration */
	USB_DRV_WriteReg8(USB_VPLEN, 0x02);

#if (defined(DRV_USB_PHY_COST_DOWN))
	USB_DRV_WriteReg8(USB_PHYIR4_3, USB_PHYIR4_3_DEGLICH);
#elif (defined(DRV_USB_PHY_U65_IP))

#elif (defined(DRV_USB_PHY_U40_IP))

#else    //Old PHY version
	/* Change phy register setting */
	USB_DRV_WriteReg8(USB_PHYCR3_3, 0x67);
	USB_DRV_WriteReg8(USB_PHYCR2_0, 0x00);
#endif

	savedMask = SaveAndSetIRQMask();
	if(g_OtgInfo.b_processing == KAL_FALSE)
	{
		g_OtgInfo.b_processing = KAL_TRUE;
		b_process_state_machine = KAL_TRUE;
	}
	RestoreIRQMask(savedMask);

	if(b_process_state_machine == KAL_TRUE)
	{
		OTG_State_Machine();
		g_OtgInfo.b_processing = KAL_FALSE;
	}

	return STATUS_OK;
}

static DCL_STATUS DCL_USB_CTRL_API_OTG_Set_Plug_Type(DCL_CTRL_DATA_T *data)
{
	OTG_DRV_CTRL_GET_PLUG_TYPE_T *prget_plug_type;

	prget_plug_type = &data->rOTG_Plug_Type;
	OTG_Set_Plug_Type(prget_plug_type->type);
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_Get_Plug_Type(DCL_CTRL_DATA_T *data)
{
	OTG_DRV_CTRL_GET_PLUG_TYPE_T *prget_plug_type;


	prget_plug_type = &data->rOTG_Plug_Type;
	prget_plug_type->type = (DCL_OTG_PLUG_TYPE)g_OtgInfo.plug_type;
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_A_Suspend_Req(DCL_CTRL_DATA_T *data)
{
	if(g_OtgInfo.otg_state != OTG_STATE_A_HOST)
		return STATUS_FAIL;

	/* suspend only effect when A_HOST state */
	OTG_Set_Status(OTG_STATUS_A_SUSPEND_REQUEST, KAL_TRUE);
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_A_Resume_Req(DCL_CTRL_DATA_T *data)
{
	if(g_OtgInfo.otg_state != OTG_STATE_A_SUSPEND)
		return STATUS_FAIL;

	OTG_Set_Status(OTG_STATUS_A_RESUME_REQUEST, KAL_TRUE);
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_A_Stop_Host(DCL_CTRL_DATA_T *data)
{
	if(g_OtgInfo.otg_state != OTG_STATE_A_HOST)
		return STATUS_FAIL;

	OTG_Set_Status(OTG_STATUS_A_BUS_REQUEST, KAL_FALSE);
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_A_Start_HNP(DCL_CTRL_DATA_T *data)
{
	if(g_OtgInfo.otg_state != OTG_STATE_A_HOST)
		return STATUS_FAIL;

	OTG_Set_Status(OTG_STATUS_A_SET_B_HNP_ENABLE, KAL_TRUE);
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_B_EnDis_HNP(DCL_CTRL_DATA_T *data)
{
	DCL_BOOL *dcl_data_ptr = (DCL_BOOL*)data;
	kal_bool set = (kal_bool)(*dcl_data_ptr);


	if(g_OtgInfo.otg_state != OTG_STATE_B_PERIPHERAL)
		return STATUS_FAIL;


	if(set == KAL_TRUE)
	{
		USB_DRV_SetBits8(USB_DEVCTL, USB_DEVCTL_HOSTREQ);
	}
	else
	{
		USB_DRV_ClearBits8(USB_DEVCTL, USB_DEVCTL_HOSTREQ);
	}

	OTG_Set_Status(OTG_STATUS_B_HNP_ENABLE, set);

	return STATUS_OK;
}



static DCL_STATUS DCL_USB_CTRL_API_OTG_B_Start_SRP(DCL_CTRL_DATA_T *data)
{
	if(g_OtgInfo.otg_state != OTG_STATE_B_IDLE)
		return STATUS_FAIL;

	OTG_Set_Status(OTG_STATUS_B_SRP_REQUEST, KAL_TRUE);
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_B_Stop_Host(DCL_CTRL_DATA_T *data)
{
	if(g_OtgInfo.otg_state != OTG_STATE_B_HOST)
		return STATUS_FAIL;

	OTG_Set_Status(OTG_STATUS_B_SUSPEND_REQUEST, KAL_TRUE);
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_B_Set_Session_Valid(DCL_CTRL_DATA_T *data)
{
	DCL_BOOL *dcl_data_ptr = (DCL_BOOL*)data;
	kal_bool set = (kal_bool)(*dcl_data_ptr);


	OTG_Set_Status(OTG_STATUS_B_SESSION_VALID, set);
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_Get_State(DCL_CTRL_DATA_T *data)
{
	OTG_DRV_CTRL_GET_STATE_T *prget_state;


	prget_state = &data->rOTG_Get_State;
	prget_state->state = (DCL_OTG_STATE)OTG_Get_State();
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_Enable_Device(DCL_CTRL_DATA_T *data)
{
	USB_DRV_SetBits8(USB_POWER, USB_POWER_SOFTCONN);
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_Incr_Disconn_Count(DCL_CTRL_DATA_T *data)
{
	g_OtgInfo.disconn_num++;

	/* If cable quality is very bad, we try to use full speed */
	if(g_OtgInfo.disconn_num == 8)
	{
		USB_DRV_ClearBits8(USB_POWER, USB_POWER_HSENAB);
	}

	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_Process_Exceptions(DCL_CTRL_DATA_T *data)
{
	USB_Dbg_Trace(USB_HOST_EXCEPTIONS, (kal_uint32)g_OtgInfo.otg_state, 0);

	if(kal_if_hisr() == KAL_TRUE)
		EXT_ASSERT(0, 0, 0, 0);

	/* Check exception for A device */
	if((g_OtgInfo.otg_state < OTG_STATE_B_IDLE))
	{
		/*
		** Exceptions are as follows.
		** 1. Transition to B_IDLE when id = TRUE.
		** 2. Transition to A_WAIT_VFALL when V_BUS is voltage is fallen below
		** 3. 4 VDC is not able to set the V_BUS voltage.
		*/

		/* For A device, only A cable plug out will go here */
		if(OTG_Get_Plug_Type() == OTG_PLUG_B)
		{
			/* 1. A plug out, EINT will set as OTG_PLUG_B  */
			/* stop any active timers*/
			OTG_Stop_Timer();

			/* state is in A_idle because b-device is un-supported and it does not support OTG, A device turn off Vbus */
			if(g_OtgInfo.otg_state == OTG_STATE_A_IDLE)
			{
				/* Only set g_OtgInfo.b_is_vbus_power_on = KAL_FALSE when A cable is plugged out */
			#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
				g_OtgInfo.b_is_vbus_power_on = KAL_FALSE;
			#endif

				g_OtgInfo.otg_state = OTG_STATE_B_IDLE;

				if(g_OtgInfo.b_srp_request == KAL_TRUE)
				{
					/* A device should not g_OtgInfo.b_srp_request == KAL_TRUE */
					ASSERT(0);
					/* OTG_B_SRP_Stop_Hdlr(void) */
					/* OTG_Display_Message(OTG_DISPLAY_MSG_STOP_CONNECTING); */
//					g_OtgInfo.b_srp_stop_hdlr();
//					g_OtgInfo.b_srp_request = KAL_FALSE;
				}

				OTG_Process_B_Idle();
			}
			else if((g_OtgInfo.otg_state == OTG_STATE_A_WAIT_BCON)||(g_OtgInfo.otg_state == OTG_STATE_A_WAIT_VFALL)||(g_OtgInfo.otg_state == OTG_STATE_A_HOST))
			{
				/* 1. A_HOST receive disconn -> A_WAIT_BCON
				     2. A_PERIPHERAL receive suspend -> A_WAIT_BCON */
				OTG_Stop_Timer();

				if(g_OtgInfo.a_process_hnp == KAL_TRUE)
				{
					g_OtgInfo.a_hnp_stop_hdlr();
					g_OtgInfo.a_process_hnp = KAL_FALSE;
				}

				g_OtgInfo.otg_state = OTG_STATE_A_WAIT_VFALL;

				/* Turn off VBUS */
				USB_HCD_VBusEnable(0, KAL_FALSE);

				if(g_OtgInfo.host_up == KAL_TRUE)
				{
					g_OtgInfo.host_up = KAL_FALSE;
					g_OtgInfo.a_host_stop_hdlr();
					g_OtgInfo.host_down_hdlr();
				}

				if(g_OtgInfo.device_up == KAL_TRUE)
				{
					g_OtgInfo.device_up = KAL_FALSE;
					g_OtgInfo.device_down_hdlr();
				}

				OTG_Start_Timer(OTG_TIMER_A_CHECK_VFALL, TA_CHECK_VFALL);
				OTG_Process_A_Wait_VFall();
			}
			else
			{
				ASSERT(0);
			}
		}
	}
	else
	{
		/*
		** Process B- device exceptions
		*/
		/* mini B plug out, or B device do SRP but mini A plug in */
		if(((g_OtgInfo.b_session_valid == KAL_TRUE)||(g_OtgInfo.otg_state == OTG_STATE_B_SRP_INIT))&&(OTG_Get_Plug_Type() == OTG_PLUG_B))
			ASSERT(0);

		if(g_OtgInfo.b_srp_request == KAL_TRUE)
		{
			/* In case go here and SRP timer is still on */
			OTG_Stop_Timer();

			/* OTG_B_SRP_Exception_Stop_Hdlr(void) */
			/* OTG_Display_Message(OTG_DISPLAY_MSG_STOP_CONNECTING); */
			g_OtgInfo.b_srp_exception_stop_hdlr();
			g_OtgInfo.b_srp_request = KAL_FALSE;
		}

		if(OTG_Get_TimerType() ==  OTG_TIMER_B_ASE0_BRST)
			OTG_Stop_Timer();

		if(g_OtgInfo.b_device_down_pending == KAL_TRUE)
		{
			if(g_OtgInfo.device_up == KAL_TRUE)
				ASSERT(0);

			g_OtgInfo.b_device_down_pending = KAL_FALSE;
			g_OtgInfo.device_down_hdlr();
			USB_Dbg_Trace(USB_OTG_B_DEVICE_PENDING_DOWN_HDLR, 0, 4);
		}

		if(OTG_Get_Plug_Type() == OTG_PLUG_B)
		{
			/* B plug out */
			/* Must go to there to release type */
			g_OtgInfo.otg_state = OTG_STATE_B_IDLE;

			/* Reset B-device HNP enabled state */
			g_OtgInfo.b_hnp_enable = KAL_FALSE;
			USB_DRV_ClearBits8(USB_DEVCTL, USB_DEVCTL_HOSTREQ);

			OTG_Process_B_Idle();
		}
		else
		{
			/* A plug in */
			g_OtgInfo.otg_state = OTG_STATE_A_IDLE;
			g_OtgInfo.a_bus_req = KAL_TRUE;
			OTG_Process_A_Idle();
		}

/*
		if((OTG_Get_Plug_Type() == OTG_PLUG_A)||
			((g_OtgInfo.b_session_valid == KAL_FALSE)&&(g_OtgInfo.otg_state != OTG_STATE_B_SRP_INIT)))
		{
			if(g_OtgInfo.b_srp_request == KAL_TRUE)
			{
				g_OtgInfo.b_srp_stop_hdlr();
				g_OtgInfo.b_srp_request = KAL_FALSE;
			}

			if(OTG_Get_Plug_Type() == OTG_PLUG_B)
			{
				g_OtgInfo.otg_state = OTG_STATE_B_IDLE;
				OTG_Process_B_Idle();
			}
			else
{
				g_OtgInfo.otg_state = OTG_STATE_A_IDLE;
				g_OtgInfo.a_bus_req = KAL_TRUE;
				OTG_Process_A_Idle();
			}
		}
*/
	}
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_Init_A_Plug_Detect(DCL_CTRL_DATA_T *data)
{
	kal_uint8 otg_idpin_eint = custom_eint_get_channel(otg_idpin_eint_chann);

	/* Set plug type as B before we register EINT */
	OTG_Set_Plug_Type(OTG_PLUG_B);

#if defined(__OLD_PDN_ARCH__)
#if defined(__OLD_PDN_DEFINE__)
	USB_DRV_WriteReg(DRVPDN_CON0_CLR, DRVPDN_CON0_USB);
#elif defined(__CLKG_DEFINE__)
	USB_DRV_WriteReg(CG_CLR0, CG_CON0_USB);
#endif
#else
	DRVPDN_Disable(PDN_USB);
#endif


#if defined(DRV_USB_PHY_U65_IP)
	USB_DRV_SetBits8(USB_U2PHYDTM1_0, USB_U2PHYDTM1_0_RG_IDPULLUP);
	USB_DRV_SetBits8(USB_U2PHYDTM1_1, USB_U2PHYDTM1_1_FORCE_IDPULLUP);
	kal_sleep_task(50);
#endif


	EINT_SW_Debounce_Modify(otg_idpin_eint, 50);
	EINT_Mask(otg_idpin_eint);
	
	g_otg_idpin_state = OTG_IDPIN_CABLE_PLUGIN_LEVEL;
	EINT_Registration(otg_idpin_eint, KAL_TRUE, OTG_IDPIN_CABLE_PLUGIN_LEVEL, OTG_ID_EINT_HISR, KAL_FALSE);	
	return STATUS_OK;
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_Host_Set_VBUS_high(DCL_CTRL_DATA_T *data)
{
#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
	DCL_BOOL *dcl_data_ptr = (DCL_BOOL*)data;
	kal_bool b_set = (kal_bool)(*dcl_data_ptr);


	g_OtgInfo.b_is_vbus_power_on = b_set;
	return STATUS_OK;
#else
	return STATUS_FAIL;
#endif
}


static DCL_STATUS DCL_USB_CTRL_API_OTG_Is_Host_Turn_On_VBUS(DCL_CTRL_DATA_T *data)
{
#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
	DCL_BOOL *usb_data;


	usb_data = (DCL_BOOL *)data;
	*usb_data = (DCL_BOOL)g_OtgInfo.b_is_vbus_power_on;
	return STATUS_OK;
#else
	return STATUS_FAIL;
#endif
}

static DCL_STATUS DCL_USB_CTRL_API_Is_OTG_A_Cable_In(DCL_CTRL_DATA_T *data)
{
	OTG_DRV_CTRL_GET_Reg_T *usb_data;
	
	usb_data = &data->rOTG_Get_State2;
	usb_data->return_value = DCL_FALSE;

#if (defined(DRV_USB_PHY_COST_DOWN)) 
//	if ((USB_DRV_Reg8(USB_PHYIR3_1)& USB_PHYIR3_1_IDDIG)== 0x00)
//		usb_data->return_value = DCL_TRUE;
#elif (defined(DRV_USB_PHY_U65_IP))   // otg cable in : ox22 , without cable: 0x2A
	if ((USB_DRV_Reg8(USB_U2PHYDMON0_3)& USB_U2PHYDMON0_3_IDDIG_MAC)== 0x00)
		usb_data->return_value = DCL_TRUE;
#elif (defined(DRV_USB_PHY_U40_IP)) 

#else
// old project doesn't support OTG
#endif
	

	return STATUS_OK;
}

static DCL_STATUS DCL_USB_CTRL_API_SRP_Init(DCL_CTRL_DATA_T *data)
{
	ilm_struct 	*usb_ilm;

	DRV_BuildPrimitive(usb_ilm,
				stack_get_active_module_id(),
				MOD_USB,
				MSG_ID_SRP_INIT,
				NULL);
	msg_send_ext_queue(usb_ilm); 	
	
	return STATUS_OK;
}


DCL_USB_CTRL_API DCL_OTG_DRV_API_T[] =
{
	DCL_USB_CTRL_API_OTG_Init_Drv_Info,
	DCL_USB_CTRL_API_OTG_Release_Drv_Info,
	DCL_USB_CTRL_API_OTG_Register_Drv_Info,
	DCL_USB_CTRL_API_OTG_Drv_Create_ISR,
	DCL_USB_CTRL_API_OTG_Drv_Activate_ISR,
	DCL_USB_CTRL_API_OTGDMA_Drv_Create_ISR,
	DCL_USB_CTRL_API_OTGDMA_Drv_Activate_ISR,
	DCL_USB_CTRL_API_OTG_Init_Drv,
	DCL_USB_CTRL_API_OTG_Get_Plug_Type,
	DCL_USB_CTRL_API_OTG_A_Suspend_Req,
	DCL_USB_CTRL_API_OTG_A_Resume_Req,
	DCL_USB_CTRL_API_OTG_A_Stop_Host,
	DCL_USB_CTRL_API_OTG_A_Start_HNP,
	DCL_USB_CTRL_API_OTG_B_EnDis_HNP,
	DCL_USB_CTRL_API_OTG_B_Start_SRP,
	DCL_USB_CTRL_API_OTG_B_Stop_Host,
	DCL_USB_CTRL_API_OTG_B_Set_Session_Valid,
	DCL_USB_CTRL_API_OTG_Get_State,
	DCL_USB_CTRL_API_OTG_Enable_Device,
	DCL_USB_CTRL_API_OTG_Incr_Disconn_Count,
	DCL_USB_CTRL_API_OTG_Process_Exceptions,
	DCL_USB_CTRL_API_OTG_Init_A_Plug_Detect,
	DCL_USB_CTRL_API_OTG_Host_Set_VBUS_high,
	DCL_USB_CTRL_API_OTG_Is_Host_Turn_On_VBUS,
	DCL_USB_CTRL_API_Is_OTG_A_Cable_In,
	DCL_USB_CTRL_API_SRP_Init,
	DCL_USB_CTRL_API_OTG_Set_Plug_Type		
};


#ifdef __OTG_SRP_HNP_APP_FIXED__
void OTG_Set_Vbus_ON(void)
{
	OTG_Set_Status(OTG_STATUS_A_DETECT_B_DATA_PLS, KAL_TRUE);
}
#endif

/*************************************************************************
* FUNCTION
*  DclOTG_DRV_Control
*
* DESCRIPTION
*  This function is to send command to control the OTG module.
*
* PARAMETERS
*  handle: A valid handle return by DclOTG_DRV_Open()
*  cmd: A control command for OTG module
// Should be added
*
*  data: The data of the control command
// Should be added
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
DCL_STATUS DclOTG_DRV_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	/* Check open or not and handle validity */
	if((g_OTG_Drv_Open == KAL_FALSE)||(DCL_OTG_DRV_CHECK_HANDLE_IS_VALID(handle) == 0))
	{
		ASSERT(0);

		if(g_OTG_Drv_Open == KAL_FALSE)
			return STATUS_INVALID_OPERATION;
		else
			return STATUS_INVALID_DCL_HANDLE;
	}

	return DCL_OTG_DRV_API_T[cmd](data);
}


#endif /* #if defined(__OTG_ENABLE__) && !defined(DRV_USB_OFF) */




