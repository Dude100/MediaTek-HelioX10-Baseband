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
 * custom_sim_driver.C
 *
 * Project:
 * --------
 *   Gemini
 *
 * Description:
 * ------------
 *   this file is custom implementation of SIM driver
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
#include "reg_base.h"
#include "intrCtrl.h"
#include "multi_icc_custom.h"
#include "kal_public_api.h"

#ifdef __SIM_HOT_SWAP_SUPPORT__
#include "eint.h"
#endif
#ifdef DRV_SIM_ALL_SOLUTION_BUILT

extern void sim_init_hwCb(void);
extern void DRV_ICC_interface_init(SIM_ICC_APPLICATION application);
extern kal_bool sim_physicalSlotChanged;

/*following is the template for dual SIM platform, I test it on TF68*/
/****************************************************
	customer and HW SA please fill from here
*****************************************************/

#define iccSlotNum 2
kal_char sim_dbg_custom_str[200];

#ifdef __SIM_HOT_SWAP_SUPPORT__
SIM_ICC_HOT_PLUG iccHotPlugTable[iccSlotNum];
#endif

const SIM_ICC_HW_SW_MAPPING iccMappingTable[iccSlotNum] =
{
/*
logical number, application usage from user's view, do it connect to MT6302, owned by which SIM controller, MT6302 chip #, interface # of this MT6302
*/
		{0, SIM_ICC_APPLICATION_PHONE1, MTK_SIMIF0, KAL_FALSE, 0, 1},
		{1, SIM_ICC_APPLICATION_PHONE2, MTK_SIMIF1, KAL_FALSE, 0, 1},
};

/****************************************************
	end of custom table
*****************************************************/

/****************************************************
	only SW guys familiar with multiple SIM driver can modify following
*****************************************************/

void sim_init_all_cb(void)
{
	kal_uint32 loopIndex;
	sim_init_hwCb();

	for(loopIndex = 0; iccSlotNum > loopIndex; loopIndex++){
		DRV_ICC_interface_init(iccMappingTable[loopIndex].application);
	}
}

kal_uint32 sim_get_logicalNum_from_app(SIM_ICC_APPLICATION application)
{
	kal_uint32 loopIndex, loopMax = iccSlotNum;

	for(loopIndex = 0; loopIndex < loopMax; loopIndex++){
		if(application == iccMappingTable[loopIndex].application){
			if(iccSlotNum <= iccMappingTable[loopIndex].logicalNum)
				ASSERT(0);
			return iccMappingTable[loopIndex].logicalNum;
		}
	}

	return 0xffffffff;
}

kal_uint32 sim_get_MT6302_from_logicalNum(kal_uint32 logicalNum)
{
	kal_uint32 loopIndex, loopMax = iccSlotNum;

	if(iccSlotNum <= logicalNum)
				ASSERT(0);

	for(loopIndex = 0; loopIndex < loopMax; loopIndex++){
		if(logicalNum == iccMappingTable[loopIndex].logicalNum){
			if(SIM_SWITCH_6302 == (kal_bool)iccMappingTable[loopIndex].needMT6302)
				return (iccMappingTable[loopIndex].MT6302ChipNum << 8) | (iccMappingTable[loopIndex].MT6302PortNum);
			else if(SIM_SWITCH_6306 == (kal_bool)iccMappingTable[loopIndex].needMT6302)
				return (iccMappingTable[loopIndex].MT6302ChipNum << 8) | (iccMappingTable[loopIndex].MT6302PortNum) | (SIM_SWITCH_6306 <<16);
			else if(SIM_SWITCH_6314 == (kal_bool)iccMappingTable[loopIndex].needMT6302)
				return (iccMappingTable[loopIndex].MT6302ChipNum << 8) | (iccMappingTable[loopIndex].MT6302PortNum) | (SIM_SWITCH_6314 <<16);
			else
				return SIM_ICC_MT6302_NONE;
		}
	}

	/*there is no this logical number*/
	ASSERT(0);
	return 0;
}

kal_uint32 sim_get_hwCtrl_from_logicalNum(kal_uint32 logicalNum)
{
	kal_uint32 loopIndex, loopMax = iccSlotNum;

	if(iccSlotNum <= logicalNum)
				ASSERT(0);

	for(loopIndex = 0; loopIndex < loopMax; loopIndex++){
		if(logicalNum == iccMappingTable[loopIndex].logicalNum){
			return iccMappingTable[loopIndex].hwCtrl;
		}
	}

	/*there is no this logical number*/
	ASSERT(0);
	return 0;
}

kal_uint32 sim_get_MT6302PeerInterface(kal_uint8 chipNum, kal_uint32 portNum)
{
	kal_uint32 loopIndex, loopMax = iccSlotNum;

	for(loopIndex = 0; loopIndex < loopMax; loopIndex++){
		if(chipNum == iccMappingTable[loopIndex].MT6302ChipNum && portNum == iccMappingTable[loopIndex].MT6302PortNum){
			if(iccSlotNum <= iccMappingTable[loopIndex].logicalNum)
				ASSERT(0);
			return iccMappingTable[loopIndex].logicalNum;
		}
	}

	/*there is no this logical number*/
	return SIM_ICC_MT6302_NONE;
}

#if defined(__MTK_TARGET__)
kal_uint32 sim_get_ToalInterfaceCount()
{
	return iccSlotNum;
}
#endif

kal_uint32 get_CAS_icc_logicalNum()
{
	kal_uint32 loopIndex, loopMax = iccSlotNum;

	for(loopIndex = 0; loopIndex < loopMax; loopIndex++){
		if(SIM_ICC_APPLICATION_CMMB_SMD == iccMappingTable[loopIndex].application){
			if(iccSlotNum <= iccMappingTable[loopIndex].logicalNum)
				ASSERT(0);
			return iccMappingTable[loopIndex].logicalNum;
		}
	}

	/*there is no this logical number*/
	ASSERT(0);
	return 0;
}

kal_uint32 sim_custom_task_2_driver(kal_uint32 taskInterface)
{
	return taskInterface;
}

#ifdef __SIM_HOT_SWAP_SUPPORT__
void sim_reg_hot_plug_cb(SIM_ICC_APPLICATION application, 
                      SIM_HOT_PLUG_CALLBACK hotPlugInCb, 
                      SIM_HOT_PLUG_CALLBACK hotPlugOutCb)
{
	kal_uint32 loopIndex;

	for(loopIndex = 0; loopIndex < iccSlotNum; loopIndex++){
		if(application == iccMappingTable[loopIndex].application){
		   iccHotPlugTable[loopIndex].application = application;
		   iccHotPlugTable[loopIndex].plugInCb = hotPlugInCb;
		   iccHotPlugTable[loopIndex].plugOutcb = hotPlugOutCb;
		   break;
		}
	}
}

void sim_get_card_status(kal_uint32 logicalNum, kal_bool *isRemoved)
{
	kal_uint32 loopIndex;

	for(loopIndex = 0; loopIndex < iccSlotNum; loopIndex++){
		if(logicalNum == iccHotPlugTable[loopIndex].logicalNum){
		   *isRemoved = iccHotPlugTable[loopIndex].removed;
		   break;
		}
	}
}
void sim_hot_plug_eint_cb_rm_h_common(kal_uint32 idx, SIM_ICC_APPLICATION app)
{
   if (iccHotPlugTable[idx].polarity == LEVEL_HIGH)
   {
      /* Remove card: polarity LEVEL_HIGH. When interrupt occurs, we should change it to LEVEL_LOW
         otherwise we will alwasy receive interrupt */
      iccHotPlugTable[idx].removed = KAL_TRUE;
      if (iccHotPlugTable[idx].plugOutcb != NULL)
      {
#if defined(__SIM_HOT_SWAP_POLL_TIMER__)
         SIM_PlugEvent_Poll_Timer_Cb(app);
#else
         iccHotPlugTable[idx].plugOutcb(app);
#ifdef SIM_HOT_SWAP_V2
         SIM_PlugEvent_Cb(app);
#endif
#endif
      }
#if defined (__DUAL_SIM_HOT_SWAP_CO_DECK_SUPPORT__)
		iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].removed = KAL_TRUE;
		if (iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].plugOutcb != NULL)
		{
#if defined(__SIM_HOT_SWAP_POLL_TIMER__)
			SIM_PlugEvent_Poll_Timer_Cb(SIM_ICC_APPLICATION_PHONE2);
#else
			iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].plugOutcb(SIM_ICC_APPLICATION_PHONE2);
#ifdef SIM_HOT_SWAP_V2
			SIM_PlugEvent_Cb(SIM_ICC_APPLICATION_PHONE2);
#endif
#endif
		}
#endif	
	   iccHotPlugTable[idx].polarity = LEVEL_LOW;
#if defined (__DUAL_SIM_HOT_SWAP_CO_DECK_SUPPORT__)
		iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].polarity = LEVEL_LOW;
#endif
		kal_sprintf(sim_dbg_custom_str,"[SIM_CUS_DRV:%d]Remove SIM : %x, %x, %x, %x, %x, %x, %x\n\r", __LINE__,
		idx,
		app, 
		iccHotPlugTable[idx].polarity, 
		iccHotPlugTable[idx].removed, 
		iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].polarity, 
		iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].removed,
		drv_get_current_time());
#if defined (ATEST_DRV_ENABLE)
		dbg_print(sim_dbg_custom_str);
#else
		tst_sys_trace(sim_dbg_custom_str);
#endif
		kal_sprintf(sim_dbg_custom_str, "[SIM_DRV]Card removed eint Pol %x, sourcepin %x,GPIO Mode %x,data %x %x IES %x\n\r",REG32(0x80021180),REG32(0x80021000),REG32(0xA0005790),REG32(0xA0005570),REG32(0xA0005580),REG32(0xA0005910));
#if defined (ATEST_DRV_ENABLE)
		dbg_print(sim_dbg_custom_str);
#else
		tst_sys_trace(sim_dbg_custom_str);
#endif
   }
   else
   {
      /* Insert card: polarity LEVEL_LOW. When interrupt occurs, we should change it to LEVEL_HIGH
         otherwise we will alwasy receive interrupt */
      iccHotPlugTable[idx].removed = KAL_FALSE;
      if (iccHotPlugTable[idx].plugInCb!= NULL)
      {
         iccHotPlugTable[idx].plugInCb(app);
      }
#if defined (__DUAL_SIM_HOT_SWAP_CO_DECK_SUPPORT__)
		iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].removed = KAL_FALSE;
		if (iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].plugInCb!= NULL)
		{
			iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].plugInCb(SIM_ICC_APPLICATION_PHONE2);
		}
#endif 
	   iccHotPlugTable[idx].polarity = LEVEL_HIGH;	   
#if defined (__DUAL_SIM_HOT_SWAP_CO_DECK_SUPPORT__)
		iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].polarity = LEVEL_HIGH;
#endif
		kal_sprintf(sim_dbg_custom_str,"[SIM_CUS_DRV:%d]Insert SIM : %x, %x, %x, %x, %x, %x, %x\n\r", __LINE__,
		idx,
		app, 
		iccHotPlugTable[idx].polarity, 
		iccHotPlugTable[idx].removed, 
		iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].polarity, 
		iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].removed,
		drv_get_current_time());
#if defined (ATEST_DRV_ENABLE)
		dbg_print(sim_dbg_custom_str);
#else
		tst_sys_trace(sim_dbg_custom_str);
#endif
		kal_sprintf(sim_dbg_custom_str, "[SIM_DRV]Card inserted eint Pol %x, sourcepin %x,GPIO Mode %x,data %x %x IES %x\n\r",REG32(0x80021180),REG32(0x80021000),REG32(0xA0005790),REG32(0xA0005570),REG32(0xA0005580),REG32(0xA0005910));
#if defined (ATEST_DRV_ENABLE)
		dbg_print(sim_dbg_custom_str);
#else
		tst_sys_trace(sim_dbg_custom_str);
#endif
   }  
}

void sim_hot_plug_eint_cb_rm_l_common(kal_uint32 idx, SIM_ICC_APPLICATION app)
{
   if (iccHotPlugTable[idx].polarity == LEVEL_LOW)
   {
      /* Remove card: polarity LEVEL_LOW. When interrupt occurs, we should change it to LEVEL_HIGH
         otherwise we will alwasy receive interrupt */
      iccHotPlugTable[idx].removed = KAL_TRUE;
      if (iccHotPlugTable[idx].plugOutcb != NULL)
      {
#if defined(__SIM_HOT_SWAP_POLL_TIMER__)
         SIM_PlugEvent_Poll_Timer_Cb(app);
#else
         iccHotPlugTable[idx].plugOutcb(app);
#ifdef SIM_HOT_SWAP_V2
         SIM_PlugEvent_Cb(app);
#endif
#endif
      }
#if defined (__DUAL_SIM_HOT_SWAP_CO_DECK_SUPPORT__)
		iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].removed = KAL_TRUE;
		if (iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].plugOutcb != NULL)
		{
#if defined(__SIM_HOT_SWAP_POLL_TIMER__)
                        SIM_PlugEvent_Poll_Timer_Cb(SIM_ICC_APPLICATION_PHONE2);
#else
			iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].plugOutcb(SIM_ICC_APPLICATION_PHONE2);
#ifdef SIM_HOT_SWAP_V2
			SIM_PlugEvent_Cb(SIM_ICC_APPLICATION_PHONE2);
#endif
#endif
		}
#endif
	   iccHotPlugTable[idx].polarity = LEVEL_HIGH;
#if defined (__DUAL_SIM_HOT_SWAP_CO_DECK_SUPPORT__)
		iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].polarity = LEVEL_HIGH;
#endif	   
		kal_sprintf(sim_dbg_custom_str,"[SIM_CUS_DRV:%d]Remove SIM : %x, %x, %x, %x, %x, %x, %x", __LINE__,
		idx,
		app, 
		iccHotPlugTable[idx].polarity, 
		iccHotPlugTable[idx].removed, 
		iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].polarity, 
		iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].removed,
		drv_get_current_time());
#if defined (ATEST_DRV_ENABLE)
		dbg_print(sim_dbg_custom_str);
#else
		tst_sys_trace(sim_dbg_custom_str);
#endif
		kal_sprintf(sim_dbg_custom_str, "[SIM_DRV]Card removed eint Pol %x, sourcepin %x,GPIO Mode %x,data %x %x IES %x\n\r",REG32(0x80021180),REG32(0x80021000),REG32(0xA0005790),REG32(0xA0005570),REG32(0xA0005580),REG32(0xA0005910));
#if defined (ATEST_DRV_ENABLE)
		dbg_print(sim_dbg_custom_str);
#else
		tst_sys_trace(sim_dbg_custom_str);
#endif
   }
   else
   {
      /* Insert card: polarity LEVEL_HIGH. When interrupt occurs, we should change it to LEVEL_LOW
         otherwise we will alwasy receive interrupt */
      iccHotPlugTable[idx].removed = KAL_FALSE;
      if (iccHotPlugTable[idx].plugInCb != NULL)
      {
         iccHotPlugTable[idx].plugInCb(app);
      }
#if defined (__DUAL_SIM_HOT_SWAP_CO_DECK_SUPPORT__)
		iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].removed = KAL_FALSE;
		if (iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].plugInCb!= NULL)
		{
			iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].plugInCb(SIM_ICC_APPLICATION_PHONE2);
		}
#endif
	   iccHotPlugTable[idx].polarity = LEVEL_LOW;	   
#if defined (__DUAL_SIM_HOT_SWAP_CO_DECK_SUPPORT__)
		iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].polarity = LEVEL_LOW;
#endif	   
		kal_sprintf(sim_dbg_custom_str,"[SIM_CUS_DRV:%d]Insert SIM : %x, %x, %x, %x, %x, %x, %x\n\r", __LINE__,
		idx,
		app, 
		iccHotPlugTable[idx].polarity, 
		iccHotPlugTable[idx].removed, 
		iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].polarity, 
		iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].removed,
		drv_get_current_time());
#if defined (ATEST_DRV_ENABLE)
		dbg_print(sim_dbg_custom_str);
#else
		tst_sys_trace(sim_dbg_custom_str);
#endif
		kal_sprintf(sim_dbg_custom_str, "[SIM_DRV]Card inserted eint Pol %x, sourcepin %x,GPIO Mode %x,data %x %x IES %x\n\r",REG32(0x80021180),REG32(0x80021000),REG32(0xA0005790),REG32(0xA0005570),REG32(0xA0005580),REG32(0xA0005910));
#if defined (ATEST_DRV_ENABLE)
		dbg_print(sim_dbg_custom_str);
#else
		tst_sys_trace(sim_dbg_custom_str);
#endif
	}   
}

/*
* FUNCTION
*	sim1_hot_plug_eint_cb_rm_h
*
* DESCRIPTION
*   	The function is call when REMOVE EINT interrupt is triggered at HIGH state, INSERT EINT interrupt is triggered.
*     at LOW state.
*
* CALLS
*
* PARAMETERS
*	void
*
* RETURNS
*	NULL
*
* GLOBALS AFFECTED
*   external_global
*/
void sim1_hot_plug_eint_cb_rm_h(void)
{   
	kal_uint32 loopIndex;

	for(loopIndex = 0; loopIndex < iccSlotNum; loopIndex++)
	{
		if(SIM_ICC_APPLICATION_PHONE1 == iccHotPlugTable[loopIndex].application)
		{
			break;
		}
	}
	
	if(sim_physicalSlotChanged == KAL_TRUE)
	{
		sim_hot_plug_eint_cb_rm_h_common(loopIndex, 1-SIM_ICC_APPLICATION_PHONE1);   
	} else
	{
		sim_hot_plug_eint_cb_rm_h_common(loopIndex, SIM_ICC_APPLICATION_PHONE1);   
	}

	EINT_Set_Polarity(iccHotPlugTable[loopIndex].eintNo, iccHotPlugTable[loopIndex].polarity);
}

/*
* FUNCTION
*	sim1_hot_plug_eint_cb_rm_l
*
* DESCRIPTION
*   	The function is call when INSERT EINT interrupt is triggered at LOW state, REMOVE EINT interrupt is triggered.
*     at HIGH state.
*
* CALLS
*
* PARAMETERS
*	void
*
* RETURNS
*	NULL
*
* GLOBALS AFFECTED
*   external_global
*/
void sim1_hot_plug_eint_cb_rm_l(void)
{
	kal_uint32 loopIndex;

	for(loopIndex = 0; loopIndex < iccSlotNum; loopIndex++)
	{
		if(SIM_ICC_APPLICATION_PHONE1 == iccHotPlugTable[loopIndex].application)
		{
			break;
		}
	}
	
	if(sim_physicalSlotChanged == KAL_TRUE)
	{
		sim_hot_plug_eint_cb_rm_l_common(loopIndex, 1-SIM_ICC_APPLICATION_PHONE1);   
	} else
	{
		sim_hot_plug_eint_cb_rm_l_common(loopIndex, SIM_ICC_APPLICATION_PHONE1);   
	}

	EINT_Set_Polarity(iccHotPlugTable[loopIndex].eintNo, iccHotPlugTable[loopIndex].polarity);
}

/*
* FUNCTION
*	sim2_hot_plug_eint_cb_rm_h
*
* DESCRIPTION
*   	The function is call when REMOVE EINT interrupt is triggered at HIGH state, INSERT EINT interrupt is triggered.
*     at LOW state.
*
* CALLS
*
* PARAMETERS
*	void
*
* RETURNS
*	NULL
*
* GLOBALS AFFECTED
*   external_global
*/
void sim2_hot_plug_eint_cb_rm_h(void)
{
	kal_uint32 loopIndex;

	for(loopIndex = 0; loopIndex < iccSlotNum; loopIndex++)
	{
		if(SIM_ICC_APPLICATION_PHONE2 == iccHotPlugTable[loopIndex].application)
		{
			break;
		}
	}

	if(sim_physicalSlotChanged == KAL_TRUE)
	{
		sim_hot_plug_eint_cb_rm_h_common(loopIndex, 1 - SIM_ICC_APPLICATION_PHONE2);   
	} else
	{
		sim_hot_plug_eint_cb_rm_h_common(loopIndex, SIM_ICC_APPLICATION_PHONE2);   
	}

	EINT_Set_Polarity(iccHotPlugTable[loopIndex].eintNo, iccHotPlugTable[loopIndex].polarity);
}

/*
* FUNCTION
*	sim2_hot_plug_eint_cb_rm_l
*
* DESCRIPTION
*   	The function is call when INSERT EINT interrupt is triggered at LOW state, REMOVE EINT interrupt is triggered.
*     at HIGH state.
*
* CALLS
*
* PARAMETERS
*	void
*
* RETURNS
*	NULL
*
* GLOBALS AFFECTED
*   external_global
*/
void sim2_hot_plug_eint_cb_rm_l(void)
{
	kal_uint32 loopIndex;

	for(loopIndex = 0; loopIndex < iccSlotNum; loopIndex++)
	{
		if(SIM_ICC_APPLICATION_PHONE2 == iccHotPlugTable[loopIndex].application)
		{
			break;
		}
	}

	if(sim_physicalSlotChanged == KAL_TRUE)
	{
		sim_hot_plug_eint_cb_rm_l_common(loopIndex, 1-SIM_ICC_APPLICATION_PHONE2);   
	} else
	{
		sim_hot_plug_eint_cb_rm_l_common(loopIndex, SIM_ICC_APPLICATION_PHONE2);   
	}
    
	EINT_Set_Polarity(iccHotPlugTable[loopIndex].eintNo, iccHotPlugTable[loopIndex].polarity);
}

void sim_reg_hot_plug_eint(SIM_ICC_APPLICATION application, 
                           kal_uint32 eintNo, 
                           kal_uint32 debounceTime, 
                           kal_uint32 polarity, 
                           kal_uint32 sensitivity, 
                           kal_uint32 socketType)
{
	kal_uint32 loopIndex;

	for(loopIndex = 0; loopIndex < iccSlotNum; loopIndex++)
	{
		if(application == iccMappingTable[loopIndex].application){
			if (iccHotPlugTable[loopIndex].registed == KAL_TRUE)
			{
				kal_sprintf(sim_dbg_custom_str, "[SIM_DRV]sim_registed\n\r");
#if defined (ATEST_DRV_ENABLE)
				dbg_print(sim_dbg_custom_str);
#else
				tst_sys_trace(sim_dbg_custom_str);
#endif
				return;
			} else
			{
				iccHotPlugTable[loopIndex].logicalNum = iccMappingTable[loopIndex].logicalNum;
				iccHotPlugTable[loopIndex].application = iccMappingTable[loopIndex].application;
				iccHotPlugTable[loopIndex].eintNo = eintNo;
				iccHotPlugTable[loopIndex].debounceTime = debounceTime;
				iccHotPlugTable[loopIndex].polarity = (kal_bool)polarity;
				iccHotPlugTable[loopIndex].sensitivity = sensitivity;
				iccHotPlugTable[loopIndex].socketType = socketType;		   		   
				iccHotPlugTable[loopIndex].registed = KAL_TRUE;
#if defined (__DUAL_SIM_HOT_SWAP_CO_DECK_SUPPORT__)
				iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].logicalNum = iccMappingTable[SIM_ICC_APPLICATION_PHONE2].logicalNum;
				iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].application = SIM_ICC_APPLICATION_PHONE2;
				iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].eintNo = eintNo;
				iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].debounceTime = debounceTime;
				iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].polarity = (kal_bool)polarity;
				iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].sensitivity = sensitivity;
				iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].socketType = socketType;
				iccHotPlugTable[SIM_ICC_APPLICATION_PHONE2].registed = KAL_TRUE;
#endif
				break;
			}
		}
	}

	// need to set SW debounce & sensitivity before registration
	EINT_SW_Debounce_Modify(eintNo, debounceTime);// 32768Hz, ]wdebounce time
	EINT_Set_Sensitivity(eintNo, sensitivity);
	// When polarity equals to KAL_TRUE, we expect REMOVE interrupt will be triggered at HIGH state;
	// When polarity equals to KAL_FALSE, we expect REMOVE interrupt will be triggered at LOW state.
	if (application == SIM_ICC_APPLICATION_PHONE1)
	{
		if ((kal_bool)polarity == KAL_TRUE)
		{
			EINT_Registration(eintNo, KAL_TRUE, (kal_bool)polarity, sim1_hot_plug_eint_cb_rm_h, KAL_TRUE);
		}
		else
		{
			EINT_Registration(eintNo, KAL_TRUE, (kal_bool)polarity, sim1_hot_plug_eint_cb_rm_l, KAL_TRUE);
		}
	}
	else
	{
		if ((kal_bool)polarity == KAL_TRUE)
			EINT_Registration(eintNo, KAL_TRUE, (kal_bool)polarity, sim2_hot_plug_eint_cb_rm_h, KAL_TRUE);
		else
			EINT_Registration(eintNo, KAL_TRUE, (kal_bool)polarity, sim2_hot_plug_eint_cb_rm_l, KAL_TRUE);
	}

}
#endif
#endif
