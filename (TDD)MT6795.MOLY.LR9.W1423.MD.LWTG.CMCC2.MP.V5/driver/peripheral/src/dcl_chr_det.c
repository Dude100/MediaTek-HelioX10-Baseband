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
 *    dcl_chr_det.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines ADC scheduler.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "reg_base.h"
#include "drv_comm.h"
#include "init.h"
#include "dcl.h"
#include "usb_drv.h"
#include "eint.h"
#include "bmt.h"
#include "dcl_pmu_sw.h"
#include "gpio_sw.h"
#include "bmt_trc.h"

kal_uint8 gCHRDET_EINT_NO = 0xFF;

#if defined(__USB_ENABLE__)
kal_uint8 gUSB_EINT_NO;
#endif // #if defined(__USB_ENABLE__)

CHR_DET_TYPE_ENUM pw_chr_type;


#if defined(PMIC_CHR_USB_DETECT_THROUGH_USB)
DCL_HANDLE chrDet_UsbHandler;
#endif

DCL_HANDLE chrDet_PmuHandler;

#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
CHR_USB_DET_MGR_T chr_usb_det_mgr;
chr_usb_detect_struct chr_usb_detect;
#endif //#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__

#if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
static kal_uint8 g_usb_eint_no;
#endif


#if defined(PMIC_6326_REG_API)
void dcl_pmic6326_HISR(void);
extern void dcl_pmic6326_ChrDet_Registration(chr_callback_type type, void (*Callback)(void));
#endif //#if defined(PMIC_6326_REG_API)


#if !defined(PMIC_CHR_DETECT_NONE)

extern BMTStruct BMT;          /*Main BMT struct*/
extern void bmt_set_chr_status(Charger_Status status);


#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
extern void CHRDET_HISR(void);
#endif //#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__


#if defined(__DRV_EXT_CHARGER_DETECTION__)
bmt_ext_charger_det *ext_charger_det;
#endif // #if defined(__DRV_EXT_CHARGER_DETECTION__)

#ifdef __USB_UART_MULTIPLEXED_WITH_EXT_SWITCH__
extern const char gpio_usb_uart_switch_pin;
#endif


void chrdet_level_config(kal_uint8 state)
{
	#if defined(__DRV_EXT_CHARGER_DETECTION__)
	return ;  // For external charger detection mechanism, we leave the setting in det driver
	#endif // #if defined(__DRV_EXT_CHARGER_DETECTION__)

	if (state != DETECTCHRIN)
	{
		/*lint -e64*/
#if defined(PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_HIGH)		
		EINT_Set_Polarity(gCHRDET_EINT_NO,LEVEL_LOW);
#else
		EINT_Set_Polarity(gCHRDET_EINT_NO,LEVEL_HIGH);
#endif //#if defined(PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_HIGH)	
		/*lint +e64*/
	}
	else
	{
		/*lint -e64*/
#if defined(PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_HIGH)		
		EINT_Set_Polarity(gCHRDET_EINT_NO,LEVEL_HIGH);
#else
		EINT_Set_Polarity(gCHRDET_EINT_NO,LEVEL_LOW);
#endif //#if defined(PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_HIGH)	
		/*lint +e64*/
	}
	#if defined(PMIC_6326_REG_API)
	ASSERT(0);	// For MT6326, we should ASSERT
	#endif // #if defined(PMIC_6326_REG_API)
}

/*
* FUNCTION
*	   CHRDET_HISR
*
* DESCRIPTION
*   	This function is the interrupt handler for EINT1
*
* CALLS
*
* PARAMETERS
*	   None
*
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void CHRDET_HISR(void)
{
	#ifndef __DRV_NO_USB_CHARGER__
	extern void bmt_charger_action(kal_bool in);
	#endif /*__DRV_NO_USB_CHARGER__*/
	kal_uint32 state;
	#if defined(PMIC_6326_REG_API)
	static kal_bool chr_status = KAL_FALSE;
	#endif // #if defined(PMIC_6326_REG_API)

#if defined(PMIC_6326_REG_API)

	{
		PMU_CTRL_CHR_GET_CHR_DET_STATUS chrStatus;
		DclPMU_Control(chrDet_PmuHandler, CHR_GET_CHR_DET_STATUS, (DCL_CTRL_DATA_T *)&chrStatus);
		DclPMU_Close(chrDet_PmuHandler);
	

		if (chr_status == chrStatus.enable){
			#if ( (!defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)) && defined(PMIC_6326_REG_API) )
			#if (!defined(__DRV_EXT_CHARGER_DETECTION__))
			EINT_UnMask(gCHRDET_EINT_NO);
			#endif // #if (!defined(__DRV_EXT_CHARGER_DETECTION__))
			#endif // #if ( (!defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)) && defined(PMIC_6326_REG_API) )
			return;
		}
	}
	
	chr_status =(kal_bool)(!((kal_uint8)chr_status));
	if (chr_status == KAL_TRUE){
		state = DETECTCHRIN;
	}else{
		state = DETECTCHROUT;
	}
	// Should PMIC6326 update the flag?
	BMT.EINT2STATE = !state;

#else // #if defined(PMIC_6326_REG_API)

	BMT.EINT2STATE = !BMT.EINT2STATE;
	#if (!defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__) )
	#if (!defined(__DRV_EXT_CHARGER_DETECTION__))
	chrdet_level_config(BMT.EINT2STATE);
	#endif // #if (!defined(__DRV_EXT_CHARGER_DETECTION__))
	#endif // #if ( (!defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)) && ( defined(PMIC_6305_REG_API) || defined(PMIC_6223_REG_API)|| defined(PMIC_6238_REG_API) || defined(PMIC_6253_REG_API) || defined(PMIC_6236_REG_API) || defined(PMIC_6251_REG_API)) )
	state = !BMT.EINT2STATE;

#endif // #if defined(PMIC_6326_REG_API)


	if (state == DETECTCHRIN)
	{
		//DclPMU_Control(chrDet_PmuHandler, CHR_SET_CV_DETECTION_VOLTAGE_CALIBRATION, NULL);	
		#ifdef BMT_DEBUG
		dbg_printWithTime("CHARGER_PLUGIN\r\n");
		#endif // #ifdef BMT_DEBUG
		#if defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__)
		BMT_VbatInHISR(); //save current vbat, otherwise turn on LCD backlight may cause VBAT decrease.
		#endif //#if defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__)
		bmt_set_chr_status(bmt_chr_in);
		#ifndef __DRV_NO_USB_CHARGER__
		bmt_charger_action(KAL_TRUE);
		#endif // #ifndef __DRV_NO_USB_CHARGER__
	}
	else
	{
		#ifdef BMT_DEBUG
		dbg_printWithTime("CHARGER_PLUGOUT\r\n");
		#endif // #ifdef BMT_DEBUG
		bmt_set_chr_status(bmt_chr_out);
		#ifndef __DRV_NO_USB_CHARGER__
		bmt_charger_action(KAL_FALSE);
		#endif // #ifndef __DRV_NO_USB_CHARGER__
	}

	#if ( (!defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__))  )
	#if (!defined(__DRV_EXT_CHARGER_DETECTION__))
	EINT_UnMask(gCHRDET_EINT_NO);
	#endif // #if (!defined(__DRV_EXT_CHARGER_DETECTION__))
	#endif // #if ( (!defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__))  )

}







#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
kal_uint8 chr_usb_eint_mask = 0;
kal_uint8 chr_usb_eint_owner_mask = 0;
kal_bool CHR_USB_EINT_UnMask(CHR_DET_EINT_OWNER Owner)
{
	kal_uint32 savedMask;
	kal_uint32 eint;


	#if (!defined(DRV_MISC_CHR_USB_EINT_CENTRAL_UNMASK))
	// If CENTRAL control is NOT enabled, we filter out USB owner control
	// ==> Just ignore USB request, the EINT unmask control is controlled by PMIC only
	if (Owner == CHR_DET_EINT_OWNER_USB){
		return KAL_FALSE;
	}else{
		EINT_UnMask(chr_usb_detect.chr_usb_eint);
		return KAL_TRUE;
	}
	#endif // #if defined(DRV_MISC_CHR_USB_EINT_CENTRAL_UNMASK)

	eint = (kal_uint32)chr_usb_detect.chr_usb_eint;

	// Force to unmask EINT
	// For some cases, our driver may trigger the EINT (Ex: OTG)
	// In this situation, we do NOT need central control
	// Because it is a false alarm trigger
	if (Owner == USB_DET_EINT_OWNER_FORCE_UNMASK){
		savedMask = SaveAndSetIRQMask();
		chr_usb_eint_mask = 0;
		EINT_UnMask((kal_uint8)eint);
		RestoreIRQMask(savedMask);
		return KAL_TRUE;
	}

	savedMask = SaveAndSetIRQMask();
	chr_usb_eint_mask |= (kal_uint8)Owner;


	if (chr_usb_eint_mask == chr_usb_eint_owner_mask){
		EINT_UnMask((kal_uint8)eint);
		// Reset the flag
		chr_usb_eint_mask = 0;
	}
	RestoreIRQMask(savedMask);
	return (chr_usb_eint_mask==0?KAL_TRUE:KAL_FALSE);
}

// This function is to set OWNER mask
// When one ot the owners wants to un-mask EINT, we compare the value with owner_mask
// When the value matchs owner_mask, then we un-mask EINT
void CHR_USB_EINT_Owner_SetMask(CHR_DET_EINT_OWNER Owner){
	#if !defined(__USB_ENABLE__)
	return;
	#endif // #if !defined(__USB_ENABLE__)
	#if (!defined(DRV_MISC_CHR_USB_EINT_CENTRAL_UNMASK))
	// Not allow for USB to set
	if (Owner == CHR_DET_EINT_OWNER_USB){
		return;
	}
	#endif // #if (!defined(DRV_MISC_CHR_USB_EINT_CENTRAL_UNMASK))
	chr_usb_eint_owner_mask |= Owner;
}
// Clear owner_mask, this should be called when cable is plugged-in every time
void CHR_USB_EINT_Owner_ClrMask(void){
	chr_usb_eint_owner_mask = 0;
}

static void CHR_USB_PLUG_OUT(void)
{
	//kal_prompt_trace(MOD_BMT,"CHR_USB OUT");
	kal_brief_trace( TRACE_STATE,BMT_CABLE_OUT_TRC);
	if (chr_usb_detect.chr_usb_present == USB_PRESENT)
	{
		CHRDET_HISR();
		#if defined(__USB_ENABLE__)
		chr_usb_det_mgr.usb_det_hisr();
		#endif // #if defined(__USB_ENABLE__)
	}
	else if (chr_usb_detect.chr_usb_present == CHARGER_PRESENT || chr_usb_detect.chr_usb_present == CHARGER_PRESENT_NON)
	{
		CHRDET_HISR();
	}	
	else
	{
		ASSERT(0);
	}

	chr_usb_detect.chr_usb_present = NO_PRESENT;
	pw_chr_type = PW_NO_CHR;

	CHR_USB_EINT_UnMask(CHR_DET_EINT_OWNER_BMT); // EINT_UnMask(chr_usb_detect.chr_usb_eint);
}

void CHR_USB_Det_EINT_Return(CHR_DET_TYPE_ENUM state)
{

	if ( state == PW_USB_CHR || state == PW_USB_CHARGING_HOST_CHR)
	{
		
		//	kal_prompt_trace(MOD_BMT,"USB IN");
		if(state == PW_USB_CHR)
		{
			kal_brief_trace( TRACE_STATE,BMT_USB_IN_TRC);
		}	
		else
		{
			kal_brief_trace( TRACE_STATE,BMT_USB_CHARGING_HOST_IN_TRC);
		}
		chr_usb_detect.chr_usb_present = USB_PRESENT;
		// Set central control owner bit
		CHR_USB_EINT_Owner_SetMask(CHR_DET_EINT_OWNER_BMT);
		CHR_USB_EINT_Owner_SetMask(CHR_DET_EINT_OWNER_USB);

		CHRDET_HISR();
		#if defined(__USB_ENABLE__)
		chr_usb_det_mgr.usb_det_hisr();
		#endif // #if defined(__USB_ENABLE__)
	}
	else if (state == PW_AC_CHR || state==PW_AC_NON_STD_CHR)
	{
		if(state == PW_AC_CHR)
		{
			//kal_prompt_trace(MOD_BMT,"AC IN");
			kal_brief_trace( TRACE_STATE,BMT_AC_IN_TRC);
			chr_usb_detect.chr_usb_present = CHARGER_PRESENT;
		}
		else	// non standard charger
		{
			//kal_prompt_trace(MOD_BMT,"Non AC IN");
			kal_brief_trace( TRACE_STATE,BMT_NON_AC_IN_TRC);
			chr_usb_detect.chr_usb_present = CHARGER_PRESENT_NON;
		}
		CHR_USB_EINT_Owner_SetMask(CHR_DET_EINT_OWNER_BMT);
		CHRDET_HISR();
		
		#if ( defined(__USB_AND_UART_WITH_ONE_GPIO__) || defined(__USB_AND_UART_WITH_ONE_PORT__) )
		/* We must call this function in chr_usb_det_mgr.usb_det_hisr() in the case that USB and UART with one GPIO */
		//USB_UART_Share(KAL_TRUE);
			{
			
				DCL_HANDLE  usb_dcl_handle;
				DCL_BOOL dcl_data;			
				usb_dcl_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);
				dcl_data = DCL_TRUE;
				DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_USB_UART_SHARE, (DCL_CTRL_DATA_T  *)&dcl_data);
				DclUSB_DRV_Close(usb_dcl_handle);			
			}
		#endif // #if ( defined(__USB_AND_UART_WITH_ONE_GPIO__) || defined(__USB_AND_UART_WITH_ONE_PORT__) )
		//#endif // #if defined(__CHINA_CHARGER_STANDARD__)
	}
	

	CHR_USB_EINT_UnMask(CHR_DET_EINT_OWNER_BMT); // EINT_UnMask(chr_usb_detect.chr_usb_eint);

}


/*************************************************************************
* FUNCTION
*	CHRDET_USB_HISR
*
* DESCRIPTION
*	1. HISR of charger and usb external interrupt
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void CHR_USB_EINT_HISR(void)
{
#ifdef __OTG_ENABLE__
	static kal_bool g_usb_host_turn_on_vbus = KAL_FALSE;
#endif // #ifdef __OTG_ENABLE__

//#if defined(PMIC_6305_REG_API) || defined(PMIC_6318_REG_API) || defined(PMIC_6238_REG_API) || defined(PMIC_6326_REG_API) || defined(PMIC_6253_REG_API) || defined(PMIC_6236_REG_API) || defined(PMIC_6276_REG_API) || defined(PMIC_6255_REG_API)

	#if defined(PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_HIGH)
	EINT_Set_Polarity(chr_usb_detect.chr_usb_eint, (kal_bool)(chr_usb_detect.chr_usb_state));
	#endif // #if defined(PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_HIGH)

	#if defined(PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_LOW)
	EINT_Set_Polarity(chr_usb_detect.chr_usb_eint, (kal_bool)(!chr_usb_detect.chr_usb_state));
	#endif // #if defined(PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_LOW)

	#if defined(PMIC_6326_REG_API)
	//if (pmic_chrdet_status() == chr_usb_detect.chr_usb_state){
	//	ASSERT(0);	// There is problem!!!! Because whenever the program goes here, we should get invert state
	//					// In => Out => In => Out
	//}
	{
		PMU_CTRL_CHR_GET_CHR_DET_STATUS chrStatus;
		DclPMU_Control(chrDet_PmuHandler, CHR_GET_CHR_DET_STATUS, (DCL_CTRL_DATA_T *)&chrStatus);
	
		if (chrStatus.enable== chr_usb_detect.chr_usb_state)
		{
			// When the detected status is same as the current state, do nothing!
			//kal_prompt_trace(MOD_BMT,"CHRDet status is same as chr_usb_state");
			EINT_UnMask(chr_usb_detect.chr_usb_eint); // unmask eint here, otherwise it never comes interrupt again.
			//CHR_USB_EINT_Owner_SetMask(CHR_DET_EINT_OWNER_BMT); // Set owner mask flag of BMT
			//CHR_USB_EINT_UnMask(CHR_DET_EINT_OWNER_BMT); // EINT_UnMask(chr_usb_detect.chr_usb_eint);
			return;
		}
	}
	#endif // #if defined(PMIC_6326_REG_API)

	

	chr_usb_detect.chr_usb_state = (kal_bool)(!((kal_uint8)chr_usb_detect.chr_usb_state));
	if (chr_usb_detect.chr_usb_state)
	{
		//kal_prompt_trace(MOD_BMT,"CHR_USB IN");
		kal_brief_trace( TRACE_STATE,BMT_CABLE_IN_TRC);

		#ifdef __USB_UART_MULTIPLEXED_WITH_EXT_SWITCH__
		GPIO_WriteIO(1, gpio_usb_uart_switch_pin);	//switch to usb mode
		#endif

		#ifdef __OTG_ENABLE__
		{
			DCL_HANDLE  otg_dcl_handle;
			DCL_BOOL dcl_data;
			kal_bool b_is_host_on_vbus;
			otg_dcl_handle = DclOTG_DRV_Open(DCL_USB, FLAGS_NONE);
			DclOTG_DRV_Control(otg_dcl_handle, OTG_DRV_CMD_IS_HOST_TURN_ON_VBUS, (DCL_CTRL_DATA_T  *)&dcl_data);
			b_is_host_on_vbus = (kal_bool)dcl_data;
			DclOTG_DRV_Close(otg_dcl_handle);
			
			if (b_is_host_on_vbus== KAL_TRUE)
		{
			g_usb_host_turn_on_vbus = KAL_TRUE;
			// Force to unmask EINT for OTG case
			CHR_USB_EINT_UnMask(USB_DET_EINT_OWNER_FORCE_UNMASK); // EINT_UnMask(chr_usb_detect.chr_usb_eint);
			return;
		}
		}
		#endif // #ifdef __OTG_ENABLE__

		// Clear EINT owner bit mask
		CHR_USB_EINT_Owner_ClrMask();

		ASSERT(chr_usb_det_mgr.pw_is_charger_usb_det_eint != NULL);
		chr_usb_det_mgr.pw_is_charger_usb_det_eint();


	}
	else
	{

		#ifdef __USB_UART_MULTIPLEXED_WITH_EXT_SWITCH__
		GPIO_WriteIO(0, gpio_usb_uart_switch_pin);	//switch to uart mode
		#endif

		#ifdef __OTG_ENABLE__
		if (g_usb_host_turn_on_vbus == KAL_TRUE)
		{
			g_usb_host_turn_on_vbus = KAL_FALSE;
			// Force to unmask EINT for OTG case
			CHR_USB_EINT_UnMask(USB_DET_EINT_OWNER_FORCE_UNMASK); // EINT_UnMask(chr_usb_detect.chr_usb_eint);
			return;
		}
		#endif // #ifdef __OTG_ENABLE__

			CHR_USB_PLUG_OUT();
	}


}

#if defined(PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11)
extern void USB_Charger_Detect_Init(void);
extern void USB_Check_Standard_Charger(void);
extern kal_bool USB_Check_DP_Value_Is_High(void);
extern kal_bool USB_Check_DM_Value_Is_High(void);
extern  void USB_Charger_Detect_Release(void);

extern charger_usb_present_enum pw_charger_usb_det_PMU_BC11(void);
extern DCL_STATUS pmu_set_chr(PMU_FLAGS_LIST_ENUM flagname,DCL_UINT32 val);
extern DCL_UINT16 pmu_get_chr(PMU_FLAGS_LIST_ENUM flagname);

DCL_HANDLE pmu_bc11_usb_charger_detect_handle = 0x7F;
kal_uint8 BC11_Status;
#define BC11_STEP_A                                     0
#define BC11_STEP_A_RESULT_GROUP_B      1
#define BC11_STEP_A_RESULT_GROUP_C      2
void pmu_bc11_delay_us(kal_uint32 us)
{
	kal_uint32 tmp;
	kal_uint32 tick_count;
	tick_count = us>>5;  // The unit is 32us
	//tick_count = us/32;  // The unit is 32us
	tmp = drv_get_current_time();
	while (drv_get_duration_tick(tmp, drv_get_current_time()) < tick_count)
	{
		;
	}
}

DCL_BOOL pmu_bc11_is_USB_DP_state_high()
{
	DCL_BOOL ret = KAL_FALSE;
	#if defined(__DRV_BC11_USE_USB_LINE_STATUS_API__)
	ret = USB_Check_DP_Value_Is_High();
	#else // __DRV_BC11_USE_USB_LINE_STATUS_API__
	//chr_bc11_comp_vth(CHR, COMP_VTH_01_200000);
	pmu_set_chr(BC11_VREF_VTH,COMP_VTH_01_200000);

	//chr_bc11_comp_en_ctrl(CHR, COMP_EN_ON_DP);
	pmu_set_chr(BC11_CMP_EN,COMP_EN_ON_DP);

	pmu_bc11_delay_us(200);
	
	//ret = chr_bc11_get_cmp_out(CHR);
	ret =pmu_get_chr(BC11_CMP_OUT);
	
	//chr_bc11_comp_en_ctrl(CHR, COMP_DISABLE);
	pmu_set_chr(BC11_CMP_EN,COMP_DISABLE);
	#endif // #if defined(__DRV_BC11_USE_USB_LINE_STATUS_API__)

	return ret;

}

DCL_BOOL pmu_bc11_is_USB_DM_state_high()
{
	DCL_BOOL ret = KAL_FALSE;
	#if defined(__DRV_BC11_USE_USB_LINE_STATUS_API__)
	ret = USB_Check_DM_Value_Is_High();
	#else // __DRV_BC11_USE_USB_LINE_STATUS_API__
	//chr_bc11_comp_vth(CHR, COMP_VTH_01_200000);
	pmu_set_chr(BC11_VREF_VTH,COMP_VTH_01_200000);
	
	//chr_bc11_comp_en_ctrl(CHR, COMP_EN_ON_DM);
	pmu_set_chr(BC11_CMP_EN,COMP_EN_ON_DM);
	
	pmu_bc11_delay_us(200);
	//ret = chr_bc11_get_cmp_out(CHR);
	ret =pmu_get_chr(BC11_CMP_OUT);
	
	//chr_bc11_comp_en_ctrl(CHR, COMP_DISABLE);
	pmu_set_chr(BC11_CMP_EN,COMP_DISABLE);
	#endif // #if defined(__DRV_BC11_USE_USB_LINE_STATUS_API__)

	return ret;
}
void pmu_bc11_detect_init(void)
{
	#if defined(__DRV_UPMU_BC11_V1__)
	//chr_bc11_bias_enable(CHR, KAL_TRUE);
	pmu_set_chr(BC11_BIAS_EN,KAL_TRUE);
	
	//chr_bc11_vsrc_en_ctrl(CHR, VSRC_DISABLE);
	pmu_set_chr(BC11_VSRC_EN,VSRC_DISABLE);
	
	//chr_bc11_comp_vth(CHR, COMP_VTH_00_325000);
	pmu_set_chr(BC11_VREF_VTH,COMP_VTH_00_325000);
	
	//chr_bc11_comp_en_ctrl(CHR, COMP_DISABLE);
	pmu_set_chr(BC11_CMP_EN,COMP_DISABLE);
	
	//chr_bc11_ipu_en_ctrl(CHR, IPU_DISABLE);
	pmu_set_chr(BC11_IPU_EN,IPU_DISABLE);
	
	//chr_bc11_ipd_en_ctrl(CHR, IPD_DISABLE);
	pmu_set_chr(BC11_IPD_EN,IPD_DISABLE);
	
	USB_Charger_Detect_Init();
	#endif // #if defined(__DRV_UPMU_BC11_V1__)
}

// Partition GroupB (Standard charger or Charging host) or GroupC(Standard host or Non-standard charger)
void pmu_bc11_stepA(void)
{
	#if defined(__DRV_UPMU_BC11_V1__)
	//chr_bc11_vsrc_en_ctrl(CHR, VSRC_EN_ON_DP);
	pmu_set_chr(BC11_VSRC_EN,VSRC_EN_ON_DP);
	//chr_bc11_ipd_en_ctrl(CHR, IPD_EN_ON_DM);
	pmu_set_chr(BC11_IPD_EN,IPD_EN_ON_DM);
	//chr_bc11_comp_vth(CHR, COMP_VTH_00_325000);
	pmu_set_chr(BC11_VREF_VTH,COMP_VTH_00_325000);
	//chr_bc11_comp_en_ctrl(CHR, COMP_EN_ON_DM);
	pmu_set_chr(BC11_CMP_EN,COMP_EN_ON_DM);
	#endif // #if defined(__DRV_UPMU_BC11_V1__)
}

kal_uint32 pmu_bc11_get_stepA_result(void)
{
	kal_uint32 result = BC11_STEP_A_RESULT_GROUP_B;
	DCL_BOOL cmp_out = KAL_TRUE;
	#if defined(__DRV_UPMU_BC11_V1__)
	//cmp_out = chr_bc11_get_cmp_out(CHR);
	cmp_out =pmu_get_chr(BC11_CMP_OUT);
	//chr_bc11_vsrc_en_ctrl(CHR, VSRC_DISABLE);
	pmu_set_chr(BC11_VSRC_EN,VSRC_DISABLE);
	//chr_bc11_ipd_en_ctrl(CHR, IPD_DISABLE);
	pmu_set_chr(BC11_IPD_EN,IPD_DISABLE);
	//chr_bc11_comp_en_ctrl(CHR, COMP_DISABLE);
	pmu_set_chr(BC11_CMP_EN,COMP_DISABLE);
	if (cmp_out)
	{
		result = BC11_STEP_A_RESULT_GROUP_B;
	}
	else
	{
		result = BC11_STEP_A_RESULT_GROUP_C;
	}
	#endif // #if defined(__DRV_UPMU_BC11_V1__)

	return result;
}

// Identify Standard charger or Charging host
//#define DEBUG_STEP_B

#if defined(DEBUG_STEP_B)
kal_bool use_bc11_ipu = KAL_FALSE;
#endif // #if defined(DEBUG_STEP_B)
void pmu_bc11_stepB(void)
{

	#if defined(DEBUG_STEP_B)
	if (use_bc11_ipu)
	{
		//chr_bc11_ipu_en_ctrl(CHR, IPU_EN_ON_DP);
		pmu_set_chr(BC11_IPU_EN,IPU_EN_ON_DP);
	}
	else
	{
		USB_Check_Standard_Charger();
	}
	#endif // #if defined(DEBUG_STEP_B)


	#if !defined(DEBUG_STEP_B)

	#if defined(__DRV_UPMU_BC11_V1__)
	#if defined(__DRV_BC11_USE_USB_100_K_RESISTOR_4_GROUP_B__)
	USB_Check_Standard_Charger();
	#else // #if defined(__DRV_BC11_USE_USB_100_K_RESISTOR_4_GROUP_B__)
	//chr_bc11_ipu_en_ctrl(CHR, IPU_EN_ON_DP);
	pmu_set_chr(BC11_IPU_EN,IPU_EN_ON_DP);
	#endif // #if defined(__DRV_BC11_USE_USB_100_K_RESISTOR_4_GROUP_B__)
	#endif // #if defined(__DRV_UPMU_BC11_V1__)

	#endif // #if !defined(DEBUG_STEP_B)
}

CHR_DET_TYPE_ENUM pmu_bc11_get_stepB_result(void)
{
	CHR_DET_TYPE_ENUM chr_type = PW_AC_CHR;
	#if defined(__DRV_UPMU_BC11_V1__)
	if (pmu_bc11_is_USB_DM_state_high())
	{
		chr_type = PW_AC_CHR;
	}
	else
	{
		chr_type = PW_USB_CHARGING_HOST_CHR;
	}

	#endif // #if defined(__DRV_UPMU_BC11_V1__)

	//chr_bc11_ipu_en_ctrl(CHR, IPU_DISABLE);
	pmu_set_chr(BC11_IPU_EN,IPU_DISABLE);
	return chr_type;
}

// Identify Standard host or Non-standard charger
void pmu_bc11_stepC(void)
{
	#if defined(__DRV_UPMU_BC11_V1__)
	//chr_bc11_ipu_en_ctrl(CHR, IPU_EN_ON_DM);
	pmu_set_chr(BC11_IPU_EN,IPU_EN_ON_DM);
	#endif // #if defined(__DRV_UPMU_BC11_V1__)
}

CHR_DET_TYPE_ENUM pmu_bc11_get_stepC_result(void)
{
	CHR_DET_TYPE_ENUM chr_type = PW_USB_CHR;
	#if defined(__DRV_UPMU_BC11_V1__)
	if (pmu_bc11_is_USB_DM_state_high())
	{
		chr_type = PW_AC_NON_STD_CHR;
	}
	else
	{
		chr_type = PW_USB_CHR;
	}
	#endif // #if defined(__DRV_UPMU_BC11_V1__)

	return chr_type;
}

void pmu_bc11_detect_deinit(void)
{
	#if defined(__DRV_UPMU_BC11_V1__)
	//chr_bc11_vsrc_en_ctrl(CHR, VSRC_DISABLE);
	pmu_set_chr(BC11_VSRC_EN,VSRC_DISABLE);
	
	//chr_bc11_comp_vth(CHR, COMP_VTH_00_325000);
	pmu_set_chr(BC11_VREF_VTH,COMP_VTH_00_325000);
	
	//chr_bc11_comp_en_ctrl(CHR, COMP_DISABLE);
	pmu_set_chr(BC11_CMP_EN,COMP_DISABLE);
	
	//chr_bc11_ipu_en_ctrl(CHR, IPU_DISABLE);
	pmu_set_chr(BC11_IPU_EN,IPU_DISABLE);
	//chr_bc11_ipd_en_ctrl(CHR, IPD_DISABLE);
	pmu_set_chr(BC11_IPD_EN,IPD_DISABLE);
	
	//chr_bc11_bias_enable(CHR, KAL_FALSE);
	pmu_set_chr(BC11_BIAS_EN,KAL_FALSE);
	
	USB_Charger_Detect_Release();
	#endif // #if defined(__DRV_UPMU_BC11_V1__)
}

void pmu_bc11_check_charger_or_usb_step4(void *parameter)
{

	if (BC11_Status == BC11_STEP_A_RESULT_GROUP_B)
	{
		// Step B
		pw_chr_type = pmu_bc11_get_stepB_result();
	}
	else if (BC11_Status == BC11_STEP_A_RESULT_GROUP_C)
	{
		// Step C
		pw_chr_type = pmu_bc11_get_stepC_result();
	}
	else
	{
		ASSERT(0);
	}

	pmu_bc11_detect_deinit();


	// Stop GPT			
	DclSGPT_Control(pmu_bc11_usb_charger_detect_handle,SGPT_CMD_STOP,0);			
	DclSGPT_Close(&pmu_bc11_usb_charger_detect_handle);


	// handle race condition by this function .
	CHR_USB_Det_EINT_Return(pw_chr_type);

}

void pmu_bc11_check_charger_or_usb_step3(void *parameter)
{


	if (BC11_Status == BC11_STEP_A_RESULT_GROUP_B)
	{
		// Step B
		pmu_bc11_stepB();
	}
	else if (BC11_Status == BC11_STEP_A_RESULT_GROUP_C)
	{
		// Step C
		pmu_bc11_stepC();
	}
	else
	{
		ASSERT(0);
	}


	{   	  
		SGPT_CTRL_START_T start;	  
		start.u2Tick=2;	  
		start.pfCallback=pmu_bc11_check_charger_or_usb_step4;	  
		start.vPara=NULL;	  
		DclSGPT_Control(pmu_bc11_usb_charger_detect_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);		
	}

}
		

void pmu_bc11_check_charger_or_usb_step2(void *parameter)
{
	// Check to go Step B or Step C
	BC11_Status = pmu_bc11_get_stepA_result();


	{   	  
		SGPT_CTRL_START_T start;	  
		start.u2Tick=7;	  
		start.pfCallback=pmu_bc11_check_charger_or_usb_step3;	  
		start.vPara=NULL;	  
		DclSGPT_Control(pmu_bc11_usb_charger_detect_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);		
	}

}


void pmu_bc11_check_charger_or_usb_step1(void *parameter)
{
 
	// Init BC11 component
	BC11_Status=BC11_STEP_A;
	pmu_bc11_detect_init();
	// Step A (Partition Group B (Standard charger or charging host) and Group C(Standard host or Non-standard charger)
	pmu_bc11_stepA();


	{   	  
		SGPT_CTRL_START_T start;	  
		start.u2Tick=7;	  
		start.pfCallback=pmu_bc11_check_charger_or_usb_step2;	  
		start.vPara=NULL;	  
		DclSGPT_Control(pmu_bc11_usb_charger_detect_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);		
	}


}

#define bc11_stepDelay  80000 // unit:us 80000=80ms

CHR_DET_TYPE_ENUM DclPW_charger_usb_det_PMU_BC11(void)
{
	//kal_uint32 tmp;
	kal_uint32 stepA_result;
	// Init BC11 component
	pmu_bc11_detect_init();
	// Step A (Partition Group B (Standard charger or charging host) and Group C(Standard host or Non-standard charger)
	pmu_bc11_stepA();

	// Wait 200 us
	pmu_bc11_delay_us(bc11_stepDelay);
	// Check to go Step B or Step C
	stepA_result = pmu_bc11_get_stepA_result();

	if (stepA_result == BC11_STEP_A_RESULT_GROUP_B)
	{
		// Step B
		pmu_bc11_stepB();
		// Wait 200 us ==> 6.25 * 32us
		pmu_bc11_delay_us(bc11_stepDelay);
		pw_chr_type = pmu_bc11_get_stepB_result();
	}
	else if (stepA_result == BC11_STEP_A_RESULT_GROUP_C)
	{
		// Step C
		pmu_bc11_stepC();
		// Wait 200 us ==> 6.25 * 32us
		pmu_bc11_delay_us(bc11_stepDelay);
		pw_chr_type = pmu_bc11_get_stepC_result();
	}
	else
	{
		ASSERT(0);
	}

	pmu_bc11_detect_deinit();

	return pw_chr_type;

}

void DclPW_charger_usb_det_eint_PMU_BC11(void)
{

#if defined(__USB_ENABLE__)
       if (INT_IsBootForUSBAT()==KAL_TRUE)
       {
		pw_chr_type = PW_USB_CHR;  
		CHR_USB_Det_EINT_Return(PW_USB_CHR);
		return;
       }
#endif //#if defined(__USB_ENABLE__)

	if (pmu_bc11_usb_charger_detect_handle == 0x7F)
	{
		pmu_bc11_usb_charger_detect_handle=DclSGPT_Open(DCL_GPT_CB,0);
	}


	{   	  
		SGPT_CTRL_START_T start;	  
		start.u2Tick=1;	  
		start.pfCallback=pmu_bc11_check_charger_or_usb_step1;	  
		start.vPara=NULL;	  
		DclSGPT_Control(pmu_bc11_usb_charger_detect_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);		
	}

}



#endif // #if defined(PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11)



#if defined(PMIC_CHR_USB_DETECT_THROUGH_USB)
#define USB_IP_V3_DETECT_ITEM_USB_CHARGER		0
#define USB_IP_V3_DETECT_ITEM_CHARGER			1
DCL_HANDLE usb_charger_detect_handle=0x7F;



static void USB_IP_V3_check_charger_or_usb(void *parameter)
{

	CHR_DET_TYPE_ENUM state = PW_NO_CHR;

	if (parameter == USB_IP_V3_DETECT_ITEM_USB_CHARGER)
	{
		// Detect USB/Charger
		if (USB_Detect_Is_Charger_In())
			{
			// Standard/Non-standard charger detection init setting
			USB_Check_Standard_Charger();
			// After init setting, we need debounce time
			// Perform Standard/Non-standard charger detection after 10ms
			{
		   	  SGPT_CTRL_START_T start;
			  start.u2Tick=1;
			  start.pfCallback=USB_IP_V3_check_charger_or_usb;
			  start.vPara=(void *)USB_IP_V3_DETECT_ITEM_CHARGER;
			  DclSGPT_Control(usb_charger_detect_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);	
			}
			
			return;
		}
		else
		{
			// USB
			state = PW_USB_CHR;

			// Finish detection
			USB_Charger_Detect_Release();

			// Stop GPT
			DclSGPT_Control(usb_charger_detect_handle,SGPT_CMD_STOP,0);
			DclSGPT_Close(&usb_charger_detect_handle);	
		}
	}
	else //if ((kal_uint32)parameter == USB_IP_V3_DETECT_ITEM_CHARGER)
	{
		// Detect standard/non-standard charger
		if (USB_Detect_Is_Standard_Charger_In())
		{
			// Standard charger
			state = PW_AC_CHR;
		}
		else
		{
			// Non-standard charger
			state = PW_AC_NON_STD_CHR;
		}
		// Finish detection
		USB_Charger_Detect_Release();

		// Stop GPT
		DclSGPT_Control(usb_charger_detect_handle,SGPT_CMD_STOP,0);
		DclSGPT_Close(&usb_charger_detect_handle);	
	}

	pw_chr_type = state;
	CHR_USB_Det_EINT_Return(state);

}



CHR_DET_TYPE_ENUM DclPW_charger_usb_det_USB(void)
{                 
#if defined(__USB_ENABLE__)
	kal_uint32 i;
	CHR_DET_TYPE_ENUM state = PW_NO_CHR;

	// Call this function to init USB H/W
	DclUSB_DRV_Control(chrDet_UsbHandler, USB_DRV_CMD_INITIALIZE_DRV_PHASE_1, NULL);
	//USB_Initialize_Drv_Phase1();

	// Detect init setting
	USB_Charger_Detect_Init();
	// Init setting debounce
	for (i=0;i<1000000;i++){
		;
	}
	// Check USB or Charger
	if (USB_Detect_Is_Charger_In()){
		// Charger
		// Init setting to detect Standard/Non-standard charger
		USB_Check_Standard_Charger();
		// Init setting debounce
		for (i=0;i<10000;i++){
			;
		}
		if (USB_Detect_Is_Standard_Charger_In()){
			// Standard charger
			state = PW_AC_CHR;
		}else{
			// Non-standard charger
			state = PW_AC_NON_STD_CHR;
		}
	}
	else
	{
		// USB
		state = PW_USB_CHR;
	}
	USB_Charger_Detect_Release();

	return state;

#else // #if defined(__USB_ENABLE__)
	return PW_NO_CHR;
#endif // #if defined(__USB_ENABLE__)
}

void DclPW_charger_usb_det_eint_USB(void)
{
#if defined(__USB_ENABLE__)

       if (INT_IsBootForUSBAT()==KAL_TRUE)
       {
		pw_chr_type = PW_USB_CHR;  
		CHR_USB_Det_EINT_Return(PW_USB_CHR);
		return;
       }

	if (usb_charger_detect_handle == 0x7F)
	{
		usb_charger_detect_handle=DclSGPT_Open(DCL_GPT_CB,0);
	}

	// Init setting for detecting
	USB_Charger_Detect_Init();

	// After init setting, we need debounce time
	// Perform USB/Charger detection after 10ms
	{
   	  SGPT_CTRL_START_T start;
	  start.u2Tick=1;
	  start.pfCallback=USB_IP_V3_check_charger_or_usb;
	  start.vPara=USB_IP_V3_DETECT_ITEM_USB_CHARGER;
	  DclSGPT_Control(usb_charger_detect_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);	
	}
	
#else
	ASSERT(0); // Assert here, need to check whether the configuration is correct or NOT
#endif // #if defined(__USB_ENABLE__)
}
#endif // #if defined(PMIC_CHR_USB_DETECT_THROUGH_USB)

#if defined(PMIC_CHR_USB_DETECT_THROUGH_ADC)
charger_usb_present_enum pw_charger_usb_det_ADC(void)
{
	kal_uint16 adc=0;
	kal_int32 volt;
	charger_usb_present_enum state;
	kal_uint8 adc_channel;
	extern charger_usb_present_enum bmt_check_ac_usb(kal_int32 vol);

	adc_channel = chr_usb_detect.chr_usb_adc;

	// use adc to distinguish between charger & usb
	USB_Phy_Enable(USB_PHY_OWNER_BMT);//USB_PowerControl(KAL_TRUE);
	// Add delay, We found there may be unstable effect when turn on USB power; need de-bounce time
	{
		volatile kal_uint32 debounce;
		for (debounce=0;debounce<10000;debounce++){
			;
		}
	}


	//DRV_Reg(DRVPDN_CON2_CLR) = DRVPDN_CON2_AUXADC;
	AUXADC_PDN_CLR();

	if (adc_channel<ADC_MAX_CHANNEL)
	{
		adc = ADC_GetData(adc_channel);
	}

	//DRV_Reg(DRVPDN_CON2_SET) = DRVPDN_CON2_AUXADC;
	AUXADC_PDN_SET();
	/*lint -e661*/
	//volt = (kal_int32)((adc_adc2vol(adc_channel, (double)adc)/100)*bmt_charing_para->adc_volt_factor[adc_channel]);
	volt = (kal_int32)adc_adc2vol(adc_channel, (double)adc);
	/*lint +e661*/
	USB_Phy_Disable(USB_PHY_OWNER_BMT);//USB_PowerControl(KAL_FALSE);
	state = bmt_check_ac_usb(volt);
	//if (volt < chr_usb_detect.chr_usb_volt)

	return state;
}

void pw_charger_usb_det_eint_ADC(void)
{
	USB_Phy_Enable(USB_PHY_OWNER_BMT);//USB_PowerControl(KAL_TRUE);
	if (bmt_event_sche_active == 1){
		if (usb_charger_eint_reg_handle == 0xFF){
			GPTI_GetHandle(&usb_charger_eint_reg_handle);
		}
		GPTI_StartItem(usb_charger_eint_reg_handle,
		                 1,
		                 usb_charger_eint_reg_adc_measurement_cb,
		                 NULL);
	}else{
		// bmt task is NOT setting event scheduler, we can set directly
		//adc_sche_set_timer_page_align(KAL_FALSE);
		adc_sche_add_item(chr_usb_detect.chr_usb_adc_logical_id,check_charger_or_usb,adc_sche_measure);
	}
}
#endif // #if defined(PMIC_CHR_USB_DETECT_THROUGH_ADC)


#endif //#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
//called by drv_init_phase1
void Dcl_Chr_Det_reg_charger_usb_eint(void)
{

#if !defined (__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
#if defined(PMIC_FIXED_CHR_EINT)
   gCHRDET_EINT_NO = PMIC_CHR_EINT_PIN;
#else
   gCHRDET_EINT_NO = custom_eint_get_channel(chrdet_eint_chann);
#endif

   #if defined(__USB_ENABLE__)
   gUSB_EINT_NO = custom_eint_get_channel(usb_eint_chann);
   #endif
#endif

#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
#if defined(PMIC_FIXED_CHR_EINT)
   chr_usb_detect.chr_usb_eint = PMIC_CHR_EINT_PIN;
#else
   chr_usb_detect.chr_usb_eint = custom_eint_get_channel(chr_usb_eint_chann);
#endif
#if defined(PMIC_CHR_USB_DETECT_THROUGH_ADC)
{
   DCL_HANDLE adc_handle;
   ADC_CTRL_GET_PHYSICAL_CHANNEL_T adc_ch;

   adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
   adc_ch.u2AdcName = DCL_CHR_USB_ADC_CHANNEL;
   DclSADC_Control(adc_handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);
   chr_usb_detect.chr_usb_adc = adc_ch.u1AdcPhyCh;
   chr_usb_detect.chr_usb_volt = bmt_get_chr_usb_detect_volt();
}
#endif   
#endif
}

// called by DclPW
CHR_DET_TYPE_ENUM Dcl_Chr_Det_is_charger_usb_present(void)
{
	PMU_CTRL_CHR_GET_CHR_DET_STATUS val;
	CHR_DET_TYPE_ENUM state = PW_NO_CHR;
	DclPMU_Control(chrDet_PmuHandler, CHR_GET_CHR_DET_STATUS, (DCL_CTRL_DATA_T *)&val);

	if (val.enable==DCL_TRUE)
	{
		#if defined (__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
			if (chr_usb_det_mgr.pw_is_charger_usb_det != NULL)
			{
				state = chr_usb_det_mgr.pw_is_charger_usb_det();
			}
		#else
				state = PW_AC_CHR;
		#endif

	}

	return state;
}




void Dcl_chr_det_reg_chr_usb(void)
{

#if defined(__MAUI_BASIC__) || defined(PMIC_CHR_DETECT_NONE)
	// In Basic load, we do NOT perform cable detection, just return
	return;

#elif defined(__DRV_EXT_CHARGER_DETECTION__)

	#ifndef IC_MODULE_TEST // When module test, we don't want to perform cable detection (For saving module time)
	#if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
	#if defined(__USB_ENABLE__)
	ext_charger_det->reg_usb_hisr(chr_usb_det_mgr.usb_det_hisr);
	#endif // #if defined(__USB_ENABLE__)
	#endif // #if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
	ext_charger_det->reg_chr_hisr(CHRDET_HISR);
	ext_charger_det->set_chr_deb_time(40);
	ext_charger_det->enable_intr();
	#endif // #ifndef IC_MODULE_TEST // When module test, we don't want to perform cable detection (For saving module time)

	return; // Return immediately here to avoid running to original PMU setting, which may make confusion

#elif defined(PMIC_PMU_SERIES)

	#if !defined (__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
	// Register gCHRDET_EINT_NO with CHRDET_HISR directly
	EINT_SW_Debounce_Modify(gCHRDET_EINT_NO, 40); // Set de-bounce time
	#if defined(PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_HIGH)
	EINT_Registration(gCHRDET_EINT_NO, KAL_TRUE, LEVEL_HIGH, CHRDET_HISR, KAL_FALSE);
	#endif //defined(PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_HIGH)
	#if defined(PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_LOW)
	EINT_Registration(gCHRDET_EINT_NO, KAL_TRUE, LEVEL_LOW, CHRDET_HISR, KAL_FALSE);
	#endif //defined(PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_LOW)
	#endif // #if !defined (__CHARGER_USB_DETECT_WIHT_ONE_EINT__)

	#if defined (__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
	#ifndef IC_MODULE_TEST // When module test, we don't want to perform cable detection (For saving module time)
	EINT_SW_Debounce_Modify(chr_usb_detect.chr_usb_eint, 40); // Set de-bounce time
	#if defined(PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_HIGH)
	EINT_Registration(chr_usb_detect.chr_usb_eint, KAL_TRUE, LEVEL_HIGH, CHR_USB_EINT_HISR, KAL_FALSE);
	#endif //defined(PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_HIGH)
	#if defined(PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_LOW)
	EINT_Registration(chr_usb_detect.chr_usb_eint, KAL_TRUE, LEVEL_LOW, CHR_USB_EINT_HISR, KAL_FALSE);
	#endif //defined(PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_LOW)
		#endif // #ifndef IC_MODULE_TEST
	#endif // #if defined (__CHARGER_USB_DETECT_WIHT_ONE_EINT__)

	{
	#ifndef IC_MODULE_TEST // When module test, we don't want to perform cable detection (For saving module time)
		PMU_CTRL_CHR_GET_CHR_DET_STATUS chrStatus;
		DclPMU_Control(chrDet_PmuHandler, CHR_GET_CHR_DET_STATUS, (DCL_CTRL_DATA_T *)&chrStatus);
		
		if (chrStatus.enable==DCL_TRUE)
		{
	#if !defined (__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
			CHRDET_HISR();
	#else
            chr_usb_detect.chr_usb_state = KAL_FALSE;
			CHR_USB_EINT_HISR();
	#endif //#if !defined (__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
		}
	#endif	
	}
	


#elif defined(PMIC_PMIC_SERIES)
	/*PMIC uses charger's interrupt*/
	#if defined(PMIC_6326_REG_API)
	#if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
	// TTTTTTTTT
	dcl_pmic6326_ChrDet_Registration(AC_CHR, CHRDET_HISR);
	EINT_SW_Debounce_Modify(gCHRDET_EINT_NO, 40);
	/*lint -e64*/
	EINT_Registration(gCHRDET_EINT_NO,KAL_TRUE,LEVEL_HIGH,dcl_pmic6326_HISR, KAL_FALSE);
	/*lint +e64*/
	#endif // #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)

	#if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
	dcl_pmic6326_ChrDet_Registration(AC_CHR_CALLBACK, CHR_USB_EINT_HISR);
	// PMIC6326 can only detect chr in, can NOT distinguish Charger or USB
	//if (pmic_is_chr_det(AC_CHR)){
	// TTTTTTTTTTTTTTTTTTTTTTTTT
	chr_usb_detect.chr_usb_state = KAL_FALSE;
	// If we nsert USB cable and serviced the intr, then re-boot device
	// PMIC6326 won't assert intr because the cable status is NOT changed
	// Then we need to check the cable status at boot time
	// If cable is inserted, we manually call HISR to handle
	if (dcl_pmic6326_chrdet_status()){
		//PMIC_CHRDET.pmic_ac_det();
		dcl_pmic6326_HISR();
	}

	EINT_SW_Debounce_Modify(chr_usb_detect.chr_usb_eint, 40);
	//EINT_SW_Debounce_Modify(chr_usb_detect.chr_usb_eint, gDebounceTime);
	/*lint -e64*/
	EINT_Registration(chr_usb_detect.chr_usb_eint,KAL_TRUE,LEVEL_HIGH,dcl_pmic6326_HISR, KAL_FALSE);
			/*lint +e64*/
	#endif // #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
	#endif //defined(PMIC_6326_REG_API)

#endif //#if defined(__MAUI_BASIC__) || defined(PMIC_CHR_DETECT_NONE)


}


void DclPW_reg_usb(kal_bool ACT_Polarity, void (reg_hisr)(void))
{
#if defined(__MAUI_BASIC__) || defined(PMIC_CHR_DETECT_NONE)
	return;

#elif defined(__DRV_EXT_CHARGER_DETECTION__)
	if (ext_charger_det->support_usb_det() == KAL_TRUE)
	{
		ext_charger_det->reg_usb_hisr(reg_hisr);
	}
	else
	{
		#if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
		EINT_Registration(g_usb_eint_no, KAL_TRUE, ACT_Polarity, reg_hisr, KAL_TRUE);
		#endif // #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
	}
	return;

#elif defined(PMIC_PMIC_SERIES)

	#if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
	dcl_pmic6326_ChrDet_Registration(USB_CHR_CALLBACK, reg_hisr);
	#else // #if defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
	EINT_Registration(g_usb_eint_no, KAL_TRUE, ACT_Polarity, reg_hisr, KAL_TRUE);
	#endif // #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)

#endif // #if defined(__MAUI_BASIC__) || defined(PMIC_CHR_DETECT_NONE)
}

#endif //#if !defined(PMIC_CHR_DETECT_NONE)

/*************************************************************************
* FUNCTION
*  DclPMU_Initialize
*
* DESCRIPTION
*  This function is to initialize PMU module
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS Dcl_Chr_Det_Initialize(void)
{
#if !defined(PMIC_CHR_DETECT_NONE)

	#if defined(PMIC_CHR_USB_DETECT_THROUGH_USB)
	if (chrDet_UsbHandler==DCL_HANDLE_NONE);
		chrDet_UsbHandler=DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);
	#endif	
	
	if (chrDet_PmuHandler==DCL_HANDLE_NONE)
		chrDet_PmuHandler=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	
#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
	chr_usb_det_mgr.pw_is_charger_usb_det = NULL;
	chr_usb_det_mgr.pw_is_charger_usb_det_eint = NULL;

	#if defined(PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11)
		chr_usb_det_mgr.pw_is_charger_usb_det = DclPW_charger_usb_det_PMU_BC11;
		chr_usb_det_mgr.pw_is_charger_usb_det_eint = DclPW_charger_usb_det_eint_PMU_BC11;
	#elif defined(PMIC_CHR_USB_DETECT_THROUGH_USB) // #if defined(PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11)
		chr_usb_det_mgr.pw_is_charger_usb_det = DclPW_charger_usb_det_USB;
		chr_usb_det_mgr.pw_is_charger_usb_det_eint = DclPW_charger_usb_det_eint_USB;
	#elif defined(PMIC_CHR_USB_DETECT_THROUGH_ADC) // #if defined(PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11)
		chr_usb_det_mgr.pw_is_charger_usb_det = DclPW_charger_usb_det_ADC;
		chr_usb_det_mgr.pw_is_charger_usb_det_eint = DclPW_charger_usb_det_eint_ADC;
	#else // #if defined(PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11)
		// TTTT
	#endif // #if defined(PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11)
#endif //#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
#endif //#if !defined(PMIC_CHR_DETECT_NONE)

    return STATUS_OK;
}
/*************************************************************************
* FUNCTION
*  DclPMU_Open
*
* DESCRIPTION
*  This function is to open the PMU38 module and return a handle
*
* PARAMETERS
*  dev: only valid for DCL_PMU
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed.
*  other value: a valid handle
*
*************************************************************************/
DCL_HANDLE Dcl_Chr_Det_Open(DCL_DEV dev, DCL_FLAGS flags)
{
    return STATUS_OK;
}
/*************************************************************************
* FUNCTION
*  DclPMU_ReadData
*
* DESCRIPTION
*  This function is not supported for the PMU module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS Dcl_Chr_Det_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
    return STATUS_OK;
}
/*************************************************************************
* FUNCTION
*  DclPMU_WriteData
*
* DESCRIPTION
*  This function is not supported for the PMU module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS Dcl_Chr_Det_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
    return STATUS_OK;
}
/*************************************************************************
* FUNCTION
*  DclPMU_Configure
*
* DESCRIPTION
*  This function is not supported for the PMU module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS Dcl_Chr_Det_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
    return STATUS_OK;
}
/*************************************************************************
* FUNCTION
*  DclPMU_RegisterCallback
*
* DESCRIPTION
*  This function is to set callback function for the PMU module.
*
* PARAMETERS
*  handle: the returned handle value of DclPMU_Open
*  event: Supported events:
*         EVENT_WDT_TIMEOUT: Watch dog time out interrupt
*  callback: the callback function for registered events
*
* RETURNS
*  STATUS_OK: Successfully register the callback function.
*  STATUS_INVALID_HANDLE: It's a invalid handle.
*  STATUS_NOT_OPENED: The module has not been opened.
*  STATUS_INVALID_EVENT: The event parameter is invalid.
*
*************************************************************************/
DCL_STATUS Dcl_Chr_Det_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
    return STATUS_OK;
}
/*************************************************************************
* FUNCTION
*  DclPMU_Control
*
* DESCRIPTION
*  This function is to send command to control the PMU module.
*
* PARAMETERS
*  handle: The handle value returned from DclPMU_Open
*  cmd: a control command for PMU module
*          1. WDT_CMD_ENABLE: to enable/disable WDT
*          2. WDT_CMD_SET_EXT_POL: to set ploarity of external pin when WDT expired
*  data: The data of the control command
*          1. WDT_CMD_ENABLE: pointer to a WDT_CTRL_ENABLE_T structure
*          2. WDT_CMD_SET_EXT_POL: pointer to a WDT_CTRL_SET_EXT_POL_T structure
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
DCL_STATUS Dcl_Chr_Det_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{


	switch(cmd)
	{
#if !defined(PMIC_CHR_DETECT_NONE)
		case CHR_DET_CMD_QUERY_IS_CHR_IN_BY_PW:
		{
//#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
			CHR_DET_CTRL_QUERY_IS_CHR_IN_BY_PW *pCtrlType=&(data->rChrDetQueryIsChrInByPW);
			pCtrlType->Chr_det_type=Dcl_Chr_Det_is_charger_usb_present();
//#endif //#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
		}	
		break;	
		case CHR_DET_CMD_QUERY_CHR_TYPE:
		{
			CHR_DET_CTRL_QUERY_CHR_TYPE *pCtrlType=&(data->rChrDetQueryChrType);
			pCtrlType->Chr_det_type=pw_chr_type;
	
		}	
		break;			
		case CHR_DET_CMD_REGISTER_CHR_USB:
		{
			Dcl_chr_det_reg_chr_usb();
		}
		break;
		//CHR_USB_EINT_UnMask
		//Dcl_Chr_Det_Control(NULL,CHR_DET_CMD_UNMASK_EINT,NULL);
		case CHR_DET_CMD_UNMASK_EINT:
		{
#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
			CHR_USB_EINT_UnMask(CHR_DET_EINT_OWNER_USB);
#endif //#ifdef __CHARGER_USB_DETECT_WIHT_ONE_EINT__
		}
		break;		
		case CHR_DET_CMD_REGISTER_CHR_USB_EINT:
		{
			Dcl_Chr_Det_reg_charger_usb_eint();
		}
		break;
		case CHR_DET_CMD_REGISTER_USB_HISR:
		{
#if defined(__USB_ENABLE__)
			CHR_DET_CTRL_REGISTER_USB_HISR  *prRegisterCompleteCB;

			prRegisterCompleteCB = &(data->rChrDetUSBHISR);
			chr_usb_det_mgr.usb_det_hisr = prRegisterCompleteCB->usb_det_hisr;
		
#endif
		}
		break;
#endif //#if !defined(PMIC_CHR_DETECT_NONE)
	      default:
	       return STATUS_UNSUPPORTED;
	}

	return STATUS_OK;
}
/*************************************************************************
* FUNCTION
*  DclPMU_Close
*
* DESCRIPTION
*  This function is to close the PMU module.
*
* PARAMETERS
*  handle: the returned handle value of DclPMU_Open
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS Dcl_Chr_Det_Close(DCL_HANDLE handle)
{
    return STATUS_OK;
}





























