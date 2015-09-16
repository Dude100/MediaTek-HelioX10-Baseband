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
 *    sim_mtk.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is the header file for MTK dual SIM controllers.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*RHR*/
#include "drv_features.h"
#include "sim_sw_comm.h"
#include "sim_hw_mtk.h"
#include "sim_reg_adp.h"
#include "intrCtrl.h"
/*RHR*/

#ifndef __SIM_DRV_MULTI_DRV_ARCH__
#ifdef DRV_2_SIM_CONTROLLER
typedef enum{
	SIM_DRIVER_ACT			= 0x00000001,
	SIM_DRIVER_DEACT			= 0x00000002,
	SIM_PDNDIS					= 0x00000003,
	SIM_PDNEN					= 0x00000004,
	SIM_INT_SIM				= 0x00000005,
	SIM_INT_USIM				= 0x00000006,
	SIM_DRIVER_ACT_SIMD		= 0x00000007,
	SIM_DRIVER_DEACT_SIMD	= 0x00000008,
	SIM_CMD_TX_LOG			= 0x00010001,
	SIM_CMD_INS_LOG			= 0x00010002,
	SIM_CMD_TXDELAY			= 0x00010003,
	SIM_INIT_USIM				= 0x00020001,
	SIM_DEACTIVATE_1			= 0x00030001,
	SIM_DEACTIVATE_2			= 0x00030002,
	SIM_ACTION_RESET			= 0x000F0001,
	SIM_ACTION_POWOFF		= 0x000F0002,
	SIM_ACTION_COMMAND		= 0x000F0003,
	SIM_ACTION_EOC			= 0x000F0004
}sim_msgTag;

typedef struct{
	sim_msgTag					tag;
	kal_uint32					event;
	kal_uint32					data1;
	kal_uint32					data2;
	kal_uint32					time;
}sim_msg;

//redefine new MACRO since there is no sim_MT6302_addMsg API in MT6235, MT6238 and I don't want to change MT6302 again
#define SIM_Reject_MTK(simInterface) \
{\
   SIM_DisAllIntr(simInterface);\
   if (SIM_Reg((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK))&SIM_CTRL_SIMON)\
   {\
   sim_addMsg(SIM_DRIVER_DEACT_SIMD, simInterface, 2, 0);\
      SimCard->State = SIM_PWROFF;\
      SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK, SIM_IRQEN_SIMOFF);\
      SIM_FIFO_Flush();\
      SIM_ClearBits(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK, SIM_CTRL_SIMON);\
	}\
	else\
	{\
      sim_PDNEnable(simInterface);\
      if(SimCard->reject_set_event)\
         SIM_SetEvent_MTK(SimCard,SIM_NOREADY);\
	}\
}
#ifdef NO_SLIM_DEF
/*********************************************************************************************
*we move this macro from sim_sw_comm.h to here, since we need a distinguish from dual controllers or MT6302.
*In dual controllers solution, we need to enable interrupt according to simInterface, but in MT6302 solution, we only need to enable SIM's.
**********************************************************************************************/
#define SIM_WaitEvent_MTK(_SIMCARD,_flag, _unmaskSIMIntr) \
{\
   kal_uint32 _event_group;\
   extern void sim_dump_error_line(void);\
   _SIMCARD->event_state = KAL_TRUE;\
   _SIMCARD->EvtFlag = _flag;\
   sim_workingTaskWaiting = KAL_TRUE;\
   if(KAL_TRUE == _unmaskSIMIntr){\
   	if(0 == simInterface)\
   		IRQUnmask(IRQ_SIM_CODE);\
   	else\
   		IRQUnmask(IRQ_SIM2_CODE);\
   	}\
	kal_retrieve_eg_events(_SIMCARD->event,_flag,KAL_OR_CONSUME,&_event_group,KAL_SUSPEND);\
	sim_workingTaskWaiting = KAL_FALSE;\
	sim_dump_error_line();\
}

//redefine new MACRO since there is no sim_MT6302_addMsg API in MT6235, MT6238 and I don't want to change MT6302 again
#define SIM_SetEvent_MTK(_SIMCARD,_result)   \
{\
   _SIMCARD->result = _result;\
   _SIMCARD->event_state = KAL_FALSE;\
   if(0 == _SIMCARD->EvtFlag)\
   	kal_set_eg_events(_SIMCARD->event,CMD_END,KAL_OR);\
   else\
   kal_set_eg_events(_SIMCARD->event,_SIMCARD->EvtFlag,KAL_OR);\
   SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_IRQEN_ALLOFF);\
   sim_addMsg(0x12345678, _SIMCARD->EvtFlag, __LINE__, drv_get_current_time());\
}
#endif /*#ifdef NO_SLIM_DEF*/
#endif /*DRV_2_SIM_CONTROLLER*/
#endif /*__SIM_DRV_MULTI_DRV_ARCH__*/
