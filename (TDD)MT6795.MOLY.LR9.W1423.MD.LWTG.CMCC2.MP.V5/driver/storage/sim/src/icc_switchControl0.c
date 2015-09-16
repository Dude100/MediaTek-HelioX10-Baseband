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
 *    switchControl0.c (originally named simd_MT6302.c)
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the SIM driver in MT6302 switch solution.
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef DRV_SIM_OFF
#include 	"kal_public_api.h"
//#include 	"stack_common.h"
#include "kal_public_defs.h" //MSBB change #include 	"stack_msgs.h"
#include 	"syscomp_config.h"
#include 	"task_config.h"
#include 	"stacklib.h"
#include  	"drv_comm.h"
#include "md_drv_sap.h"
#include "nvram_msgid.h"
#ifdef __SIM_DRV_MULTI_DRV_ARCH__
#include 	"reg_base.h"
#include 	"intrCtrl.h"
#include    "sim_reg_adp.h"

#include    "sim_hw_mtk.h"
#include    "sim_al.h"
#include 	  "dma_sw.h"
#include    "sim_sw_comm.h"
#include    "drvpdn.h"
#if defined (LPWR_SLIM)
#include    "l1sm_public.h"
#endif
#include    "drv_hisr.h"

#ifdef __MTK_TARGET__
#if  (defined(DRV_SIM_ALL_SOLUTION_BUILT) || (defined(DRV_MULTIPLE_SIM) && !defined(DRV_2_SIM_CONTROLLER)))
#if !defined(DRV_SIM_MT6208_SERIES)
//fdef MT6318
//nclude 	"pmic6318_sw.h"
//ndif   /*MT6318*/
#include    "init.h"

#ifdef SIM_ADDDMA
#include    "dma_hw.h"
#include    "dma_sw.h"
#endif   /*SIM_ADDDMA*/
#include	"usim_MT6302.h"

#ifndef __MAUI_BASIC__
//RHR#include 	"nvram_user_defs.h"
#include 	"nvram_struct.h"
#endif

#if defined(MT6223PMU)
#include "pmu_sw.h"
#endif

#include "sim_MT6302.h"
#include "sim_ctrl_al.h"
#include "sim_drv_trc.h"

#ifdef SIM_CACHED_SUPPORT
#include "cache_sw.h"
#endif

/*RHR*/
#include "drv_features.h"
//#include "kal_non_specific_general_types.h"
#include "string.h"
#include "nvram_data_items.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "stdio.h"
//nclude "pmic_features.h"
#include "kal_trace.h"
#include "kal_debug.h"
/*RHR*/


#ifdef __CLKG_DEFINE__
#if (defined(DRVPDN_CON1) || defined(DRVPDN_CON0))
#error "__CLKG_DEFINE__ & DRVPDN_CON1 are all defined"
#else /*(defined(DRVPDN_CON1) || defined(DRVPDN_CON0))*/

#ifdef SIM_PDN_REG_VERSION_3
#define DRVPDN_CON1		CG_CON0
#else /*SIM_PDN_REG_VERSION_3*/
#define DRVPDN_CON1		CG_CON1
#endif /*SIM_PDN_REG_VERSION_3*/

#ifdef SIM_PDN_REG_VERSION_3
/*MT6516 E2 has SIM2 PDN bit on MD side, we have to access CG_CON0 directly*/
#define DRVPDN_CON0		CG_CON0
#else /*SIM_PDN_REG_VERSION_3*/
#define DRVPDN_CON0		CG_CON0
#endif /*SIM_PDN_REG_VERSION_3*/

#endif /*(defined(DRVPDN_CON1) || defined(DRVPDN_CON0))*/

#if (defined(DRVPDN_CON1_SIM) || defined(DRVPDN_CON0_SIM2))
#error "__CLKG_DEFINE__ & DRVPDN_CON1_SIM are all defined"
#else /*(defined(DRVPDN_CON1_SIM) || defined(DRVPDN_CON0_SIM2))*/


#ifdef SIM_PDN_REG_VERSION_3
#define DRVPDN_CON1_SIM	CG_CON0_SIM
#else /*SIM_PDN_REG_VERSION_3*/
#define DRVPDN_CON1_SIM	CG_CON1_SIM
#endif /*SIM_PDN_REG_VERSION_3*/

#ifdef SIM_PDN_REG_VERSION_3
/*MT6516 E2 has SIM2 PDN bit on MD side, we have to access this bit*/
#define DRVPDN_CON0_SIM2	CG_CON0_SIM2
#else /*SIM_PDN_REG_VERSION_3*/
#define DRVPDN_CON0_SIM2	CG_CON0_SIM2
#endif /*SIM_PDN_REG_VERSION_3*/


#endif /*(defined(DRVPDN_CON1_SIM) || defined(DRVPDN_CON0_SIM2))*/
#endif /*__CLKG_DEFINE__*/


#define	SIM_NULLBYTE_ISSUE
#ifdef	SIM_NULLBYTE_ISSUE
/*
	magic1 is an increasing counter, increases when 1) start new command, 2)get SIM timeout, 3)get T0 end
	for case 2 and 3, it means that one of the ends of SIM commands has appeared.
*/
//kal_uint32	simMagic1;
/*
	magic2 is used to compared with magic1 every time GPT expires. It is set to magic1 in the start of a new command,
	if they were compared equally in GPT timer, we know that we are still waiting for SIM controller's event.
*/
//kal_uint32	SimCard->simMagic2;
//kal_uint32	GPTServingInterface;
//kal_uint8		SimCard->sim_nullByteIssueGPT, SimCard->sim_nullByteIssueNullCount;
//extern kal_bool GPTI_StartItem(kal_uint8 module,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter);
//extern void GPTI_StopItem(kal_uint8 module);
//extern kal_uint8 GPTI_GetHandle(kal_uint8 *handle);
#endif
extern sim_MT6302_status sim_MT6302_passRST(sim_HW_cb *hw_cb);
extern kal_int32 invalidate_wt_cache(kal_uint32 addr, kal_uint32 len);
extern void pmic6326_ccci_lock(kal_bool lock);


#define SIM_DEFAULT_TOUT_VALUE      0x983
#define SIM_CMD_TOUT_VALUE          0x1400

#define FILE_SWITCHCONTROL0 1
//kal_uint32 TOUTValue = SIM_DEFAULT_TOUT_VALUE;
//static kal_uint8  TOUT_Factor=1;
/*Maybe changed when the unit of the HW TOUT counter is changed!!*/
#ifndef DRV_SIM_HIGH_SPEED
static const kal_uint8  ClkStopTimeTable[3][2]={  {0,5},
                                           {3,11},
                                           {6,19}
                                    };
#else
static const kal_uint8  ClkStopTimeTable[5][2]={  {0,5},
                                           {3,11},
                                           {6,19},
                                           {12,40},
                                           {24,78}                                           
                                    };
#endif


//I set the number of element to a fixed value, since this code is for analog-switch solution, I have no power to support more than 2 interface
//static Sim_Card SimCard_cb[DRV_SIM_MAX_LOGICAL_INTERFACE];


extern usim_dcb_struct usim_cb[];
extern kal_bool	sim_physicalSlotChanged;
//Sim_Card *SimCard = &SimCard_cb[0];
//kal_uint8 reset_index;
//kal_uint8 PTS_data[4];

extern kal_char sim_dbg_str[];
#if defined(__USIM_DRV__)
//kal_bool sim_ATR_fail;
#endif

//static kal_bool PTS_check = KAL_TRUE;
//extern kal_uint8						sim_MT6302_regValue[];
//extern kal_bool						sim_workingTaskWaiting;


static kal_uint32   	SIM_ERROR_LINE[MAX_SIM_ERROR_LINE];
static kal_uint8 	  	SIM_ERROR_LINE_INDEX;
static kal_bool   	sim_error_tag;

#if defined(__ARMCC_VERSION)
#pragma arm section zidata = "NONCACHEDZI",  rwdata = "NONCACHEDRW"
#endif

#ifdef SIM_CACHED_SUPPORT
/*declare 2 pairs of uncache buffer for 2 SIM interfaces*/
extern kal_uint32	sim_uncachedTxBuffer0[], sim_uncachedRxBuffer0[], sim_uncachedTxBuffer1[], sim_uncachedRxBuffer1[];
#define GET_NCACHEDTX_P(p, a) {if(0==a) p=(kal_uint8 *)sim_uncachedTxBuffer0; else p=(kal_uint8 *)sim_uncachedTxBuffer1;}
#define GET_NCACHEDRX_P(p, a) {if(0==a) p=(kal_uint8 *)sim_uncachedRxBuffer0; else p=(kal_uint8 *)sim_uncachedRxBuffer1;}
extern kal_uint8 uncachedDmaBuffer0[], uncachedDmaBuffer1[];//the instance is declared in icc_sim_common_mtk.c
#define GET_NCACHED_USIM_DMA_BUF_P(p, a) {if(0==a) p=(kal_uint8 *)uncachedDmaBuffer0; else p=(kal_uint8 *)uncachedDmaBuffer1;}
#define GET_NCACHED_USIM_DMA_BUF_INT(p, a) {if(0==a) p=(kal_uint32)uncachedDmaBuffer0; else p=(kal_uint32)uncachedDmaBuffer1;}
#endif

#if defined(__ARMCC_VERSION)
#pragma arm section zidata, rwdata
#endif

void sim_PDNDisable_MT6302(sim_HW_cb *hw_cb);
void sim_PDNEnable_MT6302(sim_HW_cb *hw_cb);
extern int sprintf(char *, const char *, ...);
extern void sim_MT6302_addMsg(kal_uint32 tag, kal_uint32 event, kal_uint32 data1, kal_uint32 data2);
extern void sim_MT6302_VCCCtrl(sim_HW_cb *hw_cb, kal_uint32 on);
extern void sim_MT6302_VCCLvlCtrl(sim_HW_cb *hw_cb, kal_uint32 level);
extern kal_bool sim_MT6302_QueryNeedManualControl(sim_HW_cb *hw_cb);
extern void sim_MT6302_manualDeactive(sim_HW_cb *hw_cb);
extern sim_MT6302_status sim_MT6302_blockCLK(sim_HW_cb *hw_cb);
extern void sim_MT6302_setCardState(sim_HW_cb *hw_cb, sim_MT6302_cardState cardState);
extern kal_bool sim_MT6302_allCLKStopped(sim_HW_cb *hw_cb);
extern void sim_MT6302_SPIWrite(sim_MT6302_switchInfo *switch_CB,kal_uint8 data);
extern void sim_MT6302_clkStopTimer(sim_HW_cb *hw_cb);
extern sim_env SIM_GetCurrentEnv(void);
extern void sim_MT6302_LISRStateChange(sim_HW_cb *hw_cb, sim_MT6302_LISRState lisrState);
extern kal_uint32 SIM_GetCurrentTime(void);
extern void SIM_SetRXTIDE(kal_uint16 RXTIDE, sim_HW_cb *hw_cb);
extern void SIM_SetTXTIDE(kal_uint16 TXTIDE, sim_HW_cb *hw_cb);
extern kal_uint32 SIM_GetDurationTick(kal_uint32 previous_time, kal_uint32 current_time);

static void SIM_Initialize(kal_uint8 format, kal_uint8 power, sim_HW_cb *hw_cb);

static void sim_assert(kal_uint32 line)
{
	 sim_error_tag = KAL_TRUE;
    SIM_ERROR_LINE[SIM_ERROR_LINE_INDEX&(MAX_SIM_ERROR_LINE - 1)] = line;
    SIM_ERROR_LINE_INDEX++;
}
static void sim_assert_update_nvram(void)
{
	#ifndef __MAUI_BASIC__
   peer_buff_struct *peer_buffer_ptr;
   sim_nvram_param_struct* data_stream;
   nvram_write_req_struct* parm_stream;
   kal_uint16 data_len;
   
   parm_stream = (nvram_write_req_struct *)construct_local_para(sizeof(nvram_write_req_struct), TD_CTRL);
   peer_buffer_ptr = construct_peer_buff(sizeof(SIM_ERROR_LINE), 0, 0, TD_CTRL);
   
   data_stream = (sim_nvram_param_struct *)get_peer_buff_pdu(peer_buffer_ptr, &data_len);
   
   memcpy(data_stream, SIM_ERROR_LINE, sizeof(SIM_ERROR_LINE));
   
   //data_stream->ptr = SIM_ERROR_LINE;
   //data_stream->size = sizeof(SIM_ERROR_LINE);
   
   ((nvram_write_req_struct*) parm_stream)->file_idx =  NVRAM_EF_SIM_ASSERT_LID;
   ((nvram_write_req_struct*) parm_stream)->para = 1;

	msg_send6(MOD_SIM, MOD_NVRAM, DRIVER_PS_SAP, MSG_ID_NVRAM_WRITE_REQ, (local_para_struct *)parm_stream, (peer_buff_struct *)peer_buffer_ptr);
	#endif

}

static void sim_dump_error_line(void)
{
	if (sim_error_tag != KAL_FALSE)
   {
   	//kal_sprintf(sim_dbg_str,"[SIM dump]:Index=%d,SIM_ERROR_LINE=%d,%d,%d,%d", SIM_ERROR_LINE_INDEX, SIM_ERROR_LINE[0], SIM_ERROR_LINE[1], SIM_ERROR_LINE[2], SIM_ERROR_LINE[3]);
   	//kal_print(sim_dbg_str);
    DRV_ICC_print(SIM_PRINT_DUMP_ERROR_LINE, SIM_ERROR_LINE_INDEX, SIM_ERROR_LINE[0], SIM_ERROR_LINE[1], SIM_ERROR_LINE[2], SIM_ERROR_LINE[3]);
   	sim_error_tag = KAL_FALSE;
		sim_assert_update_nvram();
   }
}

void SIM_WaitEvent_MT6302(Sim_Card *SIMCARD,kal_uint32 flag, kal_bool unmaskSIMIntr, sim_HW_cb *hw_cb)
{
   kal_uint32 event_group;
   kal_status returnValue;
	sim_MT6302_switchInfo *switch_CB;
#if defined(__ARMCC_VERSION)
	kal_uint32 retAddr;
#else
	void	*retAddr;
#endif
   extern void sim_dump_error_line(void);

	DRV_GET_RET_ADDR(retAddr);
   sim_addMsg(0x12345679, flag, SIMCARD->result, (kal_uint32)retAddr);   
	switch_CB = sim_MT6302_get_MT6302switchCB(hw_cb);
   SIMCARD->event_state = KAL_TRUE;
   SIMCARD->EvtFlag = flag;
   switch_CB->sim_workingTaskWaiting = KAL_TRUE;
   if(KAL_TRUE == unmaskSIMIntr)
   	IRQUnmask(hw_cb->mtk_lisrCode);
	returnValue= kal_retrieve_eg_events(SIMCARD->event,flag,KAL_OR_CONSUME,&event_group,KAL_SUSPEND);
   returnValue = returnValue; //fix assigned but not used warning
	switch_CB->sim_workingTaskWaiting = KAL_FALSE;
	sim_dump_error_line();
}

void SIM_SetEvent_MT6302(Sim_Card *SIMCARD, kal_uint8 result, sim_HW_cb *hw_cb)
{
#if defined(__ARMCC_VERSION)
	kal_uint32 retAddr;
#else
	void	*retAddr;
#endif

	DRV_GET_RET_ADDR(retAddr);
   sim_addMsg(0x12345678, SIMCARD->EvtFlag, drv_get_current_time(), (kal_uint32)retAddr);

   SIMCARD->result = result;
   SIMCARD->event_state = KAL_FALSE;
   if(0 == SIMCARD->EvtFlag)
   	kal_set_eg_events(SIMCARD->event,SIM_EVT_CMD_END,KAL_OR);
   else
   kal_set_eg_events(SIMCARD->event,SIMCARD->EvtFlag,KAL_OR);
   SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_IRQEN_ALLOFF);
}

void SIM_Reject_MT6302(sim_HW_cb *hw_cb)
{
#if defined(__ARMCC_VERSION)
	kal_uint32 retAddr;
#else
	void	*retAddr;
#endif
	Sim_Card *SimCard;

	DRV_GET_RET_ADDR(retAddr);
	SimCard = GET_SIM_CB(hw_cb->simInterface);
   sim_addMsg(0x1234567A, SimCard->EvtFlag, drv_get_current_time(), (kal_uint32)retAddr);

   SIM_DisAllIntr();
   if (SIM_Reg((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK))&SIM_CTRL_SIMON)
   {
      sim_MT6302_addMsg(SIM_MT6302_DRIVER_DEACT, hw_cb->simInterface, 2, 0);
      SimCard->State = SIM_PWROFF;
      SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_IRQEN_SIMOFF);
      SIM_FIFO_Flush();
      if(KAL_FALSE == sim_MT6302_QueryNeedManualControl(hw_cb)){
      	SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_SIMON);
      	sim_MT6302_VCCCtrl(hw_cb, 0);
		}
   	else{
   		sim_MT6302_manualDeactive(hw_cb);
   	}
	}
	else
	{
      sim_PDNEnable_MT6302(hw_cb);
      if(SimCard->reject_set_event)
         SIM_SetEvent_MT6302(SimCard,SIM_NOREADY, hw_cb);
	}
}

//#if ( (!defined(MT6205)) && (!defined(MT6205B)) )
#if !defined(DRV_SIM_MT6205B_SERIES)
  // kal_uint8                        sim_dmaport[2];
#ifdef SIM_ADDDMA
   static DMA_INPUT                 sim_input;
   //#ifdef MT6218B
   #if defined(DRV_SIM_DMA_6218B)
      #pragma arm section rwdata = "INTERNRW", zidata = "INTERNZI"
      static kal_uint8          baud_data[640];
      #pragma arm section rwdata , zidata
      static DMA_FULLSIZE_HWMENU    sim_menu;
      extern void dma_ch1_stop(void);
      extern void dma_ch1_init(kal_uint32 dstaddr, kal_uint16 len, kal_uint8 limiter);
      extern void dma_ch1_start(kal_uint32 srcaddr);
   #else /*!MT6218B*/
      static DMA_HWMENU             sim_menu;
   #endif   /*MT6218B*/
#endif   /*SIM_ADDDMA*/
#endif   /*MT6218,MT6218B*/


//#if ( (!defined(MT6205)) && (!defined(MT6205B)) )
#if !defined(DRV_SIM_MT6205B_SERIES)
static void SIM_L1Reset(sim_HW_cb *hw_cb, kal_bool maskSIMIntr)
{
	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);
   SIM_DisAllIntr();

#ifdef SIM_ADDDMA
   if (SimCard->sim_dmaport != 0)
      DMA_Stop(SimCard->sim_dmaport);
#endif   /*SIM_ADDDMA*/

   SIM_FIFO_Flush();
   //De-activate SIM card
   if (SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK)&SIM_CTRL_SIMON)
   {
   	sim_MT6302_addMsg(SIM_MT6302_DRIVER_DEACT, hw_cb->simInterface, 1, 0);
      SimCard->State = SIM_WaitRejectDone;
      SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,(SIM_IRQEN_SIMOFF|SIM_IRQEN_NATR));
      SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_SIMON);
      /*since we have do lots actions, if its context is task, there maybe chance that hisr occur before we wait event*/
      /*to prevent this race condition, if maskSIMIntr is true, we have to disable SIM's interrupt*/
      if(KAL_TRUE == maskSIMIntr)
      	  IRQMask(hw_cb->mtk_lisrCode);
      sim_MT6302_VCCCtrl(hw_cb, 0);
   }
   else
   {
      /*since we have do lots actions, if its context is task, there maybe chance that hisr occur before we wait event*/
      /*to prevent this race condition, if maskSIMIntr is true, we have to disable SIM's interrupt*/
      if(KAL_TRUE == maskSIMIntr)
      	  IRQMask(hw_cb->mtk_lisrCode);
      SIM_Initialize(SimCard->Data_format,SimCard->Power, hw_cb);
   }
}
#endif   /*! MT6205,MT6205B*/




#ifdef NoT0CTRL
kal_uint8 SIM_CheckSW(kal_uint16 ACK)
{
   if ((ACK & 0x00f0) == 0x0060)
			return KAL_TRUE;
	if ((ACK & 0x00f0) == 0x0090)
		return KAL_TRUE;

   return KAL_FALSE;
}
#endif   /*NoT0CTRL*/

static kal_bool SIM_ResetNoATR(kal_uint8 pow, sim_HW_cb *hw_cb)	//For normal case reset
{
	//Only enable SIM interrupt

	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);

	SimCard->State = SIM_WAIT_FOR_ATR;
	SimCard->reset_index = 0;
	SimCard->Power = pow;

	kal_set_eg_events(SimCard->event, 0, KAL_AND);

	//Deactivate the SIM card
	SIM_L1Reset(hw_cb, KAL_TRUE);

	SIM_WaitEvent_MT6302(SimCard,RST_READY, KAL_TRUE, hw_cb);
#if !defined(__L1_STANDALONE__)
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
		0 , SimCard->State , SimCard->result, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK),
		0, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK));
#endif
	if (SimCard->result == SIM_SUCCESS)
	{
	   return KAL_TRUE;
	}
	else
	{
	   return KAL_FALSE;
	}
}

static void SIM_Initialize(kal_uint8 format, kal_uint8 power, sim_HW_cb *hw_cb)
{
	kal_uint16 tmp;
	kal_uint16 Conf;
	Sim_Card *SimCard;
	const kal_uint8 *tmpPtr = ClkStopTimeTable[0];
	tmpPtr = tmpPtr;
	sim_input = sim_input;
	sim_menu = sim_menu;
	SimCard = GET_SIM_CB(hw_cb->simInterface);

	//tmp = *(volatile kal_uint16 *)0x80140070;
	//if (tmp != 1)
	   //while(1);
	SimCard->Data_format = format;
	SimCard->Power = power;
	//Setup the SIM control module, SIM_BRR, SIM_CONF
	//Set SIMCLK = 13M/4, and BAUD RATE = default value(F=372,D=1);
	SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK,(SIM_BRR_CLK_Div4 | SIM_BRR_BAUD_Div372));

	if (format != SIM_direct)
	{
	   Conf = SIM_CONF_InDirect;
	}
	else
	{
	   Conf = SIM_CONF_Direct;
	}

	/*fix the voltage to MT6302, currently is always 3V*/
#if (!defined(__DRV_SIM_SIMIF_CONTROL_VSIM__))

	/*use PMU API*/
	if(SIM_base == hw_cb->mtk_baseAddr){
		DRV_ICC_PMU_setVolt(0, CLASS_B_30V);
	}
#if (2 == SIM_DRV_MTK_INTERFACE_NUM)
	else if(SIM2_base == hw_cb->mtk_baseAddr){
		DRV_ICC_PMU_setVolt(1, CLASS_B_30V);
	}
#endif

#else //configure through SIMIF setting

	/*in Gemini project, we need 3V to communicate with outer switch*/
	Conf |= SIM_CONF_SIMSEL;

#endif //configure through SIMIF setting

	/*control the real voltage to card*/
	if (power == SIM_30V)
	{
		sim_MT6302_VCCLvlCtrl(hw_cb, 1);
	}
	else{
		/*in Gemini project, we need 3V to communicate with outer switch*/
		sim_MT6302_VCCLvlCtrl(hw_cb, 0);
	}



	if (SimCard->TS_HSK_ENABLE == KAL_TRUE)
	   Conf |= (SIM_CONF_TXHSK | SIM_CONF_RXHSK);

   SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK, Conf);

   if (SimCard->TS_HSK_ENABLE == KAL_TRUE)
   {
      SIM_SetRXRetry(hw_cb, 1);
	   SIM_SetTXRetry(hw_cb, 1);
   }
   else
   {
      SIM_SetRXRetry(hw_cb, 0);
	   SIM_SetTXRetry(hw_cb, 0);
   }

	//Set the ATRTout as 9600etu
	SIM_SetTOUT(SimCard->TOUTValue, hw_cb);

   // reset interrupts, flush rx, tx fifo
	SIM_FIFO_Flush();
	// delay 100 clock cycles (30us) [MAUI_03431888]/[MAUI_03433590]
	while(SIM_Reg(SIM0_BASE_ADDR_MTK+SIM_CLR_STA)==1);
		
	{
		kal_uint32 t1;
		t1 = drv_get_current_time();
		while((drv_get_current_time()-t1) < 1);
	}
	

	//Set the txfifo and rxfifo tide mark
	SIM_SetRXTIDE(1, hw_cb);

	//Read Interrupt Status
	tmp = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
	tmp = tmp; //fix assigned but not used warning

	SimCard->State = SIM_WAIT_FOR_ATR;

	//Enable Interrupt
	SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK, (SIM_IRQEN_Normal & ~SIM_IRQEN_RXERR));
   SimCard->recDataErr = KAL_FALSE;
	//activate the SIM card, and activate the SIMCLK

	sim_MT6302_VCCCtrl(hw_cb, 1);
	sim_MT6302_addMsg(SIM_MT6302_DRIVER_ACT, hw_cb->simInterface, 1, power);
	SIM_Active();
	////dbg_print("SIM ACtive\r\n");
}

extern kal_uint32 MT6302_initDelayTime;

static kal_bool SIM_PTSProcess(kal_uint8 *TxBuffaddr, kal_uint8 Txlength, sim_HW_cb *hw_cb)	//Bool lalasun
{
	kal_uint8    index;
	kal_uint8    tmp;
  	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);


	#if defined(__USIM_DRV__)
#ifdef SIM_ACTIVATE_BY_PTS_ERROR
	if((SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK) & SIM_CTRL_SIMON ) == 0)
	{
		SimCard->sim_ATR_fail = KAL_TRUE;
		SIM_Initialize(SimCard->Data_format,SimCard->Power,hw_cb);
	}
#endif
	if(SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK))
	{
		USIM_CLR_FIFO();
		// delay 100 clock cycles (30us) [MAUI_03431888]/[MAUI_03433590]
		while(SIM_Reg(SIM0_BASE_ADDR_MTK+SIM_CLR_STA)==1);
			
		{
			kal_uint32 t1;
			t1 = drv_get_current_time();
			while((drv_get_current_time()-t1) < 1);
		}		
		
	}
	SIM_SetTOUT(SimCard->TOUTValue, hw_cb);
	#endif

#if !defined(__L1_STANDALONE__)
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
		0 , SimCard->TOUTValue, SimCard->State, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK),
		0, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK));
#endif
	for (index = 0; index < Txlength; index++)
	{
	   	SimCard->PTS_data[index]=0;
		tmp = *(TxBuffaddr+index);
		SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK,tmp);
	}

	SimCard->State = SIM_PROCESS_PTS;

	SIM_SetRXTIDE(Txlength, hw_cb);
	SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,SIM_IRQEN_Normal);

	SIM_WaitEvent_MT6302(SimCard,PTS_END, KAL_FALSE, hw_cb);
#if !defined(__L1_STANDALONE__)
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
			SimCard->recDataErr , drv_get_current_time(), MT6302_initDelayTime, 0, 0, 0);
#endif

	if ((SimCard->recDataErr == KAL_TRUE)
	   || (SimCard->result == SIM_INIPTSERR))
   {
#if !defined(__L1_STANDALONE__)
   	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
			SimCard->recDataErr , drv_get_current_time(),
			*TxBuffaddr, *(TxBuffaddr+1), *(TxBuffaddr+2), *(TxBuffaddr+3)
	);
#endif	
      SimCard->recDataErr = KAL_FALSE;
      return KAL_FALSE;
   }

	for (index = 0; index < Txlength; index++)
	{
		if (SimCard->PTS_data[index]!=*(TxBuffaddr+index))
		{
#if !defined(__L1_STANDALONE__)
			drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
				*TxBuffaddr, *(TxBuffaddr+1), *(TxBuffaddr+2), *(TxBuffaddr+3),
				SimCard->PTS_data[index], index
			);
#endif			
			return KAL_FALSE;
		}
	}
	// Some high speed SIM card after clock rate change have to wait a while to
	// to receive the first command.
	if(SimCard->PTS_data[1] != 0x00)
		kal_sleep_task(10);

	return KAL_TRUE;
}

static kal_bool SIM_ProcessATRData(sim_HW_cb *hw_cb)
{
   kal_uint8 index;
	kal_uint16 tmp,tmp1, Fi = 372;
	kal_uint8 ptsdata[4];
	/*TOUT is an uint32 value*/
	kal_uint32 WWT = 0;
	kal_uint8 Dvalue = 1;
  	Sim_Card *SimCard;
  	usim_dcb_struct	*usim_dcb;
  	/* fix build warning */
   WWT = WWT;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	SimCard = GET_SIM_CB(hw_cb->simInterface);
	#if defined(__USIM_DRV__)
	if(SimCard->sim_ATR_fail)
	{
	   SIM_WaitEvent_MT6302(SimCard,ATR_END, KAL_FALSE, hw_cb);

	   if (SimCard->recDataErr == KAL_TRUE)
	   {
	      SimCard->recDataErr = KAL_FALSE;
	      return KAL_FALSE;
	   }
	}
	else
	{
		kal_mem_cpy(SimCard->recData, usim_dcb->ATR_data+1, usim_dcb->ATR_index-1);
	}
	#else
	SIM_WaitEvent_MT6302(SimCard,ATR_END, KAL_FALSE, hw_cb);

	if (SimCard->recDataErr == KAL_TRUE)
	{
		SimCard->recDataErr = KAL_FALSE;
		return KAL_FALSE;
	}
	#endif

   index = 1;
   if (SimCard->recData[0] & 0x00f0)
   {
      if (SimCard->recData[0] & TAMask)
      {
         tmp = SimCard->recData[index]; //TA1
         index++;
         ////dbg_print("TA1=%x\r\n",tmp);
         if ((tmp == 0x0011)||(tmp == 0x0001))
         {
            //Don't process ATR data!!
            SimCard->State = SIM_PROCESSCMD;
            SIMCmdInit();
            #ifdef NoT0CTRL
	         SimCard->cmdState = SIMD_CmdIdle;
	         #endif
				/* Use 372/1 as default TOUT */
				Fi = 372;
				DRV_ICC_Calc_WWT(Fi,1,10,&WWT);
				SimCard->TOUTValue = WWT>>2;
				//SimCard->TOUTValue = SIM_CMD_TOUT_VALUE;
            	SIM_SetTOUT(SimCard->TOUTValue, hw_cb);
	         return KAL_TRUE;
         }
         else
         {
            /* Set default Fi as 512 */
				Fi = 512;
            switch (tmp)
            {
               case 0x0094:		//F = 512,D=8
                  SimCard->sim_card_speed = sim_card_enhance_speed_64;

                  if (!SimCard->PTS_check)
                  {
                     Dvalue = 1;
                     ptsdata[0]=0xff;
					   	ptsdata[1]=0x00;
					   	ptsdata[2]=0xff;
					   	if (!SIM_PTSProcess(ptsdata, 3, hw_cb))
					   	{
					   	   return KAL_FALSE;
					   	}
                     /* Use 372/1 as default TOUT */
                     Fi = 372;
                     DRV_ICC_Calc_WWT(Fi,1,10,&WWT);
                     SimCard->TOUTValue = WWT>>2;
                     //SimCard->TOUTValue = SIM_CMD_TOUT_VALUE;
							SIM_SetTOUT(SimCard->TOUTValue, hw_cb);
				      }
                  else
                  {
//#ifdef MT6218B
#if defined(DRV_SIM_DMA_6218B)
                     kal_uint32 savedMask;
#endif   /*MT6218B*/
					   	Dvalue = 8;
					   	ptsdata[0]=0xff;
					   	ptsdata[1]=0x10;
					   	ptsdata[2]=0x94;
					   	ptsdata[3]=0x7b;
					   	SimCard->Speed = Speed64;

					   	if (!SIM_PTSProcess(ptsdata,4, hw_cb))
					   	{
					   	   return KAL_FALSE;
					   	}

					   	SIM_SetData((SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), SIM_BRR_ETUMSK, SIM_BRR_BAUD_Div64);
					   	SimCard->TOUT_Factor = 8;  //hw-specific
                     /* calc 512/8 TOUT value */
                     DRV_ICC_Calc_WWT(Fi,8,10,&WWT);
                     SimCard->TOUTValue = WWT>>2;
					   	//SimCard->TOUTValue = SimCard->TOUT_Factor*SIM_CMD_TOUT_VALUE;
					   	SIM_SetTOUT(SimCard->TOUTValue, hw_cb);
                  }
        				break;

        			case 0x0095:		//F=512,D=16
        				SimCard->sim_card_speed = sim_card_enhance_speed_32;
					if (!SimCard->PTS_check)
					{
        				 	Dvalue = 1;
	        			   	ptsdata[0]=0xff;
					     ptsdata[1]=0x00;
					     ptsdata[2]=0xff;
					     if (!SIM_PTSProcess(ptsdata,3, hw_cb))
						{
							return KAL_FALSE;
						}
                     /* Use 372/1 as default TOUT */
                     Fi = 372;
                     DRV_ICC_Calc_WWT(Fi,1,10,&WWT);
                     SimCard->TOUTValue = WWT>>2;
                     //SimCard->TOUTValue = SIM_CMD_TOUT_VALUE;
						SIM_SetTOUT(SimCard->TOUTValue, hw_cb);
					}
                  		else
                  		{
//#ifdef MT6218B
#if defined(DRV_SIM_DMA_6218B)
                     kal_uint32 savedMask;
#endif   /*MT6218B*/
        				   Dvalue = 16;
        				   ptsdata[0]=0xff;
					      ptsdata[1]=0x10;
					      ptsdata[2]=0x95;
					      ptsdata[3]=0x7a;
					      SimCard->Speed = Speed32;

					      if (!SIM_PTSProcess(ptsdata,4, hw_cb))
						   {
						      return KAL_FALSE;
						   }
//#ifdef MT6218B
#if defined(DRV_SIM_DMA_6218B)
                     if (INT_ecoVersion() < GN)
                     {
					   	   savedMask = SaveAndSetIRQMask();
					   	   dma_ch1_stop();
					   	   RestoreIRQMask(savedMask);
					      }
#endif   /*MT6218B*/
					   	SIM_SetData((SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), SIM_BRR_ETUMSK, SIM_BRR_BAUD_Div32);
						 	SimCard->TOUT_Factor = 16;
                     /* calc 512/16 TOUT value */
                     DRV_ICC_Calc_WWT(Fi,16,10,&WWT);
                     SimCard->TOUTValue = WWT>>2;
					   	//SimCard->TOUTValue = SimCard->TOUT_Factor*SIM_CMD_TOUT_VALUE;
					      	SIM_SetTOUT(SimCard->TOUTValue, hw_cb);
                  }
        				break;
#ifdef DRV_SIM_HIGH_SPEED
		case 0x0096:		//F=512,D=32
        		SimCard->sim_card_speed = sim_card_enhance_speed_16;

                	if (!SimCard->PTS_check)
            		{
        			Dvalue = 1;
	        		ptsdata[0]=0xff;
				ptsdata[1]=0x00;
				ptsdata[2]=0xff;
				if (!SIM_PTSProcess(ptsdata,3, hw_cb))
				{
					return KAL_FALSE;
				}
                     /* Use 372/1 as default TOUT */
                     Fi = 372;
                     DRV_ICC_Calc_WWT(Fi,1,10,&WWT);
                     SimCard->TOUTValue = WWT>>2;
							//SimCard->TOUTValue = SIM_CMD_TOUT_VALUE;
				SIM_SetTOUT(SimCard->TOUTValue, hw_cb);
			}
                  	else
                  	{
        			Dvalue = 32;
        			ptsdata[0]=0xff;
				ptsdata[1]=0x10;
				ptsdata[2]=0x96;
				ptsdata[3]=0x79;
				SimCard->Speed = Speed16;

				if (!SIM_PTSProcess(ptsdata,4, hw_cb))
				{
					return KAL_FALSE;
				}
					SIM_SetData((SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), SIM_BRR_ETUMSK, SIM_BRR_BAUD_Div16);
					SimCard->TOUT_Factor = 32;
                     /* calc 512/32 TOUT value */
                     DRV_ICC_Calc_WWT(Fi,32,10,&WWT);
                     SimCard->TOUTValue = WWT>>2;
					   	//SimCard->TOUTValue = SimCard->TOUT_Factor*SIM_CMD_TOUT_VALUE;
							SIM_SetTOUT(SimCard->TOUTValue, hw_cb);
               	}
			        	break;
					case 0x0097:		//F=512,D=64
				   	SimCard->sim_card_speed = sim_card_enhance_speed_8;
					
						if (!SimCard->PTS_check)
						{
							Dvalue = 1;
							ptsdata[0]=0xff;
							ptsdata[1]=0x00;
							ptsdata[2]=0xff;
							if (!SIM_PTSProcess(ptsdata,3, hw_cb))
							{
								return KAL_FALSE;
							}
                     /* Use 372/1 as default TOUT */
                     Fi = 372;
                     DRV_ICC_Calc_WWT(Fi,1,10,&WWT);
                     SimCard->TOUTValue = WWT>>2;
                     //SimCard->TOUTValue = SIM_CMD_TOUT_VALUE;
							SIM_SetTOUT(SimCard->TOUTValue, hw_cb);
						}
						else
						{
							Dvalue = 64;
							ptsdata[0]=0xff;
							ptsdata[1]=0x10;
							ptsdata[2]=0x97;
							ptsdata[3]=0x78;
							SimCard->Speed = Speed8;
					
							if (!SIM_PTSProcess(ptsdata,4, hw_cb))
							{
								return KAL_FALSE;
							}
							SIM_SetData((SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), SIM_BRR_ETUMSK, SIM_BRR_BAUD_Div8);
							SimCard->TOUT_Factor = 64;
                     /* calc 512/64 TOUT value */
                     DRV_ICC_Calc_WWT(Fi,64,10,&WWT);
                     SimCard->TOUTValue = WWT>>2;
					   	//SimCard->TOUTValue = SimCard->TOUT_Factor*SIM_CMD_TOUT_VALUE;
					SIM_SetTOUT(SimCard->TOUTValue, hw_cb);
                  	}
        		break;
#endif

	        		default:		//F=372,D=1
	        			Dvalue = 1;
	        			ptsdata[0]=0xff;
					   ptsdata[1]=0x00;
					   ptsdata[2]=0xff;
					   if (!SIM_PTSProcess(ptsdata,3, hw_cb))
						{
						   return KAL_FALSE;
						}
						/* Use 372/1 as default TOUT */
						Fi = 372;
						DRV_ICC_Calc_WWT(Fi,1,10,&WWT);
						SimCard->TOUTValue = WWT>>2;
						//SimCard->TOUTValue = SIM_CMD_TOUT_VALUE;
						SIM_SetTOUT(SimCard->TOUTValue, hw_cb);
        				break;
        		}
         }
      }  /*if (SimCard->recData[0] & TAMask)*/

      if (SimCard->recData[0] & TBMask)
      {
         tmp = SimCard->recData[index];
         ////dbg_print("TB1=%x\r\n",tmp);
         index++;
      }
      if (SimCard->recData[0] & TCMask)
      {
         tmp = SimCard->recData[index];
         ////dbg_print("TC1=%x\r\n",tmp);
         if (tmp != 0xff && tmp != 0x00)
        	{
            return KAL_FALSE;
         }
        	index++;
      }

      if (SimCard->recData[0] & TDMask)
      {
         tmp = SimCard->recData[index];	///TD1
         index++;
         ////dbg_print("TD1=%x\r\n",tmp);
         if (tmp & TCMask)	//TC2 is obtain
        	{
            if (tmp & TAMask)
            {
               tmp1 = SimCard->recData[index];
               ////dbg_print("TA2=%x\r\n",tmp1);
               index++;
            }
				if (tmp & TBMask)
        		{
        			tmp1 = SimCard->recData[index];
        			////dbg_print("TB2=%x\r\n",tmp1);
        			index++;
        		}
        		if (tmp & TCMask)	//TC2
        		{
        		   tmp1 = SimCard->recData[index];
               ////dbg_print("TC2=%x\r\n",tmp1);
               /*TOUT is an uint32 value*/
//               TOUT = (960*Dvalue);
//               TOUT = (TOUT*tmp1)/4;   /*(/4)is hw-specific*/
               index++;
//               SimCard->TOUTValue = TOUT+8;
               //////dbg_print("TOUT=%x\r\n",TOUT);
               
					/* Calc 512/Dvalue TOUT value*/
					DRV_ICC_Calc_WWT(Fi,Dvalue,tmp1,&WWT);
					SimCard->TOUTValue = WWT>>2;
					//SimCard->TOUTValue = SIM_CMD_TOUT_VALUE;
					SIM_SetTOUT(SimCard->TOUTValue, hw_cb);

//					if (TOUT < 0xffff)
//						SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), TOUT);
//					else
//						SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), 0xffff);
        	}
         }
      }  /*if (SimCard->recData[0] & TDMask)*/
   }/*if (SimCard->recData[0] & 0x00f0)*/
	SimCard->State = SIM_PROCESSCMD;
	SIMCmdInit();
	#ifdef NoT0CTRL
	SimCard->cmdState = SIMD_CmdIdle;
	#endif   /*NoT0CTRL*/
	return KAL_TRUE;
}

static void SIM_Cmdhandler(sim_HW_cb *hw_cb)
{
  	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);

#ifndef SIM_ADDDMA
   while(SIM_FIFO_GetLev())
   {
      *(SimCard->rxbuffer+SimCard->recDataLen) = (kal_uint8)SIM_Reg((SIM0_BASE_ADDR_MTK + SIM_DATA_MTK));
      SimCard->recDataLen++;
   }
#endif /*SIM_ADDDMA*/
   SIM_SetEvent_MT6302(SimCard,SIM_SUCCESS, hw_cb);
   return;
}

#ifndef SIM_ADDDMA
void SIM_Txhandler(sim_HW_cb *hw_cb)
{
#ifdef NoT0CTRL
   kal_uint8 index;
   kal_uint16 reslen;
   reslen = SimCard->txsize - SimCard->txindex;
   if(reslen <= 15)
   {
      for(index=0;index<reslen;index++)
      {
         SIM_WriteReg(SIM_DATA,*(SimCard->txbuffer+SimCard->txindex));
         SimCard->txindex++;
      }
      SIM_SetRXTIDE(2);
      SimCard->cmdState = SIM_WaitProcByte;
      SIM_WriteReg(SIM_IRQEN,SIM_IRQEN_CMDNormal);
   }
   else
   {
      for(index=0;index<15;index++)
      {
         SIM_WriteReg(SIM_DATA,*(SimCard->txbuffer+SimCard->txindex));
         SimCard->txindex++;
      }
      SIM_SetTXTIDE(0);
      SIM_WriteReg(SIM_IRQEN,(SIM_IRQEN_CMDNormal|SIM_IRQEN_TX));
   }
   return;
#else   /*NoT0CTRL*/
   kal_uint8 index;
   kal_uint16 reslen;
     	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);


   reslen = SimCard->txsize - SimCard->txindex;
   if(reslen <= 15)
   {
      for(index=0;index<reslen;index++)
      {
         SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK,*(SimCard->txbuffer+SimCard->txindex));
         SimCard->txindex++;
      }
      SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,SIM_IRQEN_CMDNormal);
   }
   else
   {
      for(index=0;index<15;index++)
      {
         SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK,*(SimCard->txbuffer+SimCard->txindex));
         SimCard->txindex++;
      }
      SIM_SetTXTIDE(0);
      SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,(SIM_IRQEN_CMDNormal|SIM_IRQEN_TX));
   }
#endif   /*NoT0CTRL*/
}
#endif   /*SIM_ADDDMA*/

static void SIM_Rxhandler(kal_uint16 sim_int, sim_HW_cb *hw_cb)
{
   kal_uint16 TS;
   kal_uint8  index;
     	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);

   if (SimCard->State == SIM_WAIT_FOR_ATR)
	{
		TS = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK);

		if ((TS == 0x003f) || (TS == 0x003b))
		{
			SimCard->State = SIM_PROCESS_ATR;

			//SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) |=
			//         (SIM_CONF_TXHSK | SIM_CONF_RXHSK |SIM_CONF_TOUTEN);
			SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), (SIM_CONF_TXHSK | SIM_CONF_RXHSK |SIM_CONF_TOUTEN));

			/* *(volatile kal_uint16 *)SIM_CONF |= SIM_CONF_TOUTEN; */
			SIM_SetRXTIDE(12, hw_cb);
			SIM_SetRXRetry(hw_cb, 7);
			SIM_SetTXRetry(hw_cb, 7);
         SimCard->recDataLen = 0;

			SIM_SetEvent_MT6302(SimCard,SIM_SUCCESS, hw_cb);
			SimCard->EvtFlag = ATR_END;
			SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,SIM_IRQEN_Normal);
		}
		else
		{
			SimCard->reset_index++;	//Change format!!, don't change power
			if (SimCard->reset_index>1)
			{
				SimCard->reset_index = 0;
				SIM_SetEvent_MT6302(SimCard,SIM_CARDERR, hw_cb);
				SIM_ASSERT(0);
				/* fix build warning */
	         sim_assert(0);
			}
			else
			{
				if (SimCard->Data_format == SIM_indirect)
				{
					SimCard->Data_format = SIM_direct;
					SIM_L1Reset(hw_cb, KAL_FALSE);
				}
				else
				{
					SimCard->Data_format = SIM_indirect;
					SIM_L1Reset(hw_cb, KAL_FALSE);
				}
			}
		}
		return;
	}

	if (SimCard->State == SIM_PROCESS_ATR)
	{
	   while(1)
      {
         if (SIM_FIFO_GetLev())
         {
         	if(40 <= SimCard->recDataLen){
         		sim_MT6302_addMsg(0x20080213, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK));
#ifdef SIM_REMOVE_ATR_ASSERT
			SIM_StartFaltalReport(hw_cb);
			SIM_SetEvent_MT6302(SimCard, SIM_CMDRECERR, hw_cb);
#if !defined(__L1_STANDALONE__)
			drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
				0 , SimCard->State, SimCard->result, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK),
				0, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK));
#endif
			return;
#else
         		ASSERT(0);
#endif
         	}
            SimCard->recData[SimCard->recDataLen] = (kal_uint8)SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK);
            SimCard->recDataLen++;
         }
         else
         {
            if (sim_int & SIM_STS_TOUT)
            {
               SIM_SetEvent_MT6302(SimCard,SIM_SUCCESS, hw_cb);
            }
            break;
		   }
      }
      return;
	}

	if (SimCard->State == SIM_PROCESS_PTS)
	{
		index = 0;
		while(KAL_TRUE)
		{
			SimCard->PTS_data[index] = (kal_uint8)SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK);
			index++;

			if (SIM_FIFO_GetLev()==0)
			{
				SIM_SetEvent_MT6302(SimCard,SIM_SUCCESS, hw_cb);
				break;
			}
		}
		SIM_DisAllIntr();
		return;
	}

	if (SimCard->State == SIM_PROCESSCMD)
	{
#ifdef SIM_ADDDMA
	   ////dbg_print("something error\r\n");
#else /*SIM_ADDDMA*/
#ifdef NoT0CTRL
{
   kal_uint16 ACK;
   while(SIM_FIFO_GetLev())
   {
      if (SimCard->cmdState == SIM_WaitProcByte)
      {
         ACK = SIM_Reg(SIM_DATA);
         if ((ACK == SimCard->INS) || (ACK == (SimCard->INS+1)))    //ACK
         {
            if (SimCard->txsize != 5)
            {
               /*Trx command*/
               SIM_WriteReg(SIM_DATA,*(SimCard->txbuffer+SimCard->txindex));
               SimCard->txindex++;
               SIM_SetTXTIDE(0);
               SIM_WriteReg(SIM_IRQEN,(SIM_IRQEN_CMDNormal | SIM_IRQEN_TX));
               SimCard->cmdState = SIM_AckDataState;
               return;
            }
            else
            {
               SIM_SetTXTIDE(0xffff);
               SIM_WriteReg(SIM_IRQEN,SIM_IRQEN_CMDNormal);
               SimCard->cmdState = SIM_AckDataState;
               continue;
            }
         }

         if ((ACK == (~SimCard->INS & 0x00ff)) || (ACK == (~(SimCard->INS+1)& 0x00ff)))    ///NACK
         {
            if (SimCard->txsize != 5)
            {
               SIM_WriteReg(SIM_DATA,*(SimCard->txbuffer+SimCard->txindex));
               SimCard->txindex++;
               SIM_SetRXTIDE(1);
               SimCard->cmdState = SIM_WaitProcByte;
               /*Trx command*/
               SIM_WriteReg(SIM_IRQEN,SIM_IRQEN_CMDNormal);
               return;
            }
            else
            {
               SIM_SetTXTIDE(0xffff);
               SimCard->cmdState = SIM_NAckDataState;
               SIM_WriteReg(SIM_IRQEN,SIM_IRQEN_CMDNormal);
            }
            continue;
         }

         if (ACK == 0x60)    //ACK
         {
            continue;
         }
         if (SIM_CheckSW(ACK))    //ACK
         {
            SimCard->SW1 = (kal_uint8)ACK;
            SIM_SetRXTIDE(1);
            SimCard->recDataLen++;
            SimCard->cmdState = SIM_WaitSWByte;
            continue;
         }
      }

      if (SimCard->cmdState == SIM_WaitSWByte)
      {
         SimCard->SW2 = (kal_uint8)SIM_Reg(SIM_DATA);
         /*SimCard->recDataLen++;*/
         SimCard->recDataLen--;
         SIM_SetEvent_MT6302(SimCard,SIM_SUCCESS, hw_cb);
         return;
      }

      if (SimCard->cmdState == SIM_AckDataState)
      {
         *(SimCard->rxbuffer+SimCard->recDataLen) = (kal_uint8)SIM_Reg(SIM_DATA);
         SimCard->recDataLen++;
         if (SimCard->recsize == SimCard->recDataLen)
         {
            SimCard->cmdState = SIM_WaitProcByte;
         }
         continue;
      }

      if (SimCard->cmdState == SIM_NAckDataState)
      {
         *(SimCard->rxbuffer+SimCard->recDataLen) = (kal_uint8)SIM_Reg(SIM_DATA);
         SimCard->recDataLen++;
         SimCard->cmdState = SIM_WaitProcByte;
         continue;
      }
   }  /*while(SIM_FIFO_GetLev())*/
   if (SimCard->txsize == 5)
   {
      if ((SimCard->recsize+2 - SimCard->recDataLen) > 15)
      {
         SIM_SetRXTIDE(CMD_RECBUFSIZE-8);
      }
      else
      {
         SIM_SetRXTIDE(SimCard->recsize+2 - SimCard->recDataLen);
      }

      SIM_WriteReg(SIM_IRQEN,SIM_IRQEN_CMDNormal);
   }
}
#else /*NoT0CTRL*/
	   while(SIM_FIFO_GetLev())
      {
         *(SimCard->rxbuffer+SimCard->recDataLen) = (kal_uint8)SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK);
         SimCard->recDataLen++;
      }
#endif /*NoT0CTRL*/
#endif /*SIM_ADDDMA*/
		return;
	}
}

static kal_bool recordHISR;

static void SIM_HISR_MT6302_Common(sim_HW_cb *hw_cb, kal_uint32 sim_int)
{
	Sim_Card *SimCard;
	Sim_Card *PeerSimCard, *SimCardNow;
	sim_HW_cb *peerHWCb;

	SimCard = GET_SIM_CB(hw_cb->simInterface);

	if ( sim_int & SIM_STS_TXERR)
	{
	   ////dbg_print("SIM_STS_TXERR\r\n");
	   if (SimCard->State == SIM_PROCESSCMD)
	   {
	      SimCard->State = SIM_SERIOUSERR;
	      SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK, SIM_IRQEN_TOUT);
	      SIM_ASSERT(0);
	   }
	   else
	   {
	      SIM_Reject_MT6302(hw_cb);
	      SIM_ASSERT(0);
	      //SIM_SetEvent_MT6302(SimCard,SIM_INIPTSERR, hw_cb);
	   }
	}

	if ( sim_int & SIM_STS_TX)
	{
	   ////dbg_print("SIM_STS_TX\r\n");
	   //SIM_DisIntr(SIM_IRQEN_TX);
#ifdef  SIM_ADDDMA
	   ////dbg_print("something error\r\n");
#else /*SIM_ADDDMA*/
      SIM_Txhandler();  /* Only used for no DMA */
#endif /*SIM_ADDDMA*/
	}

	if ( sim_int & SIM_STS_TOUT)
	{
	   ////dbg_print("703SIM_STS_TOUT\r\n");
	   if(SimCard->State == SIM_WAIT_FOR_ATR)
	   {
	      SIM_SetEvent_MT6302(SimCard,SIM_INIPTSERR, hw_cb);
	      SIM_ASSERT(0);
	   }

	   if(SimCard->State == SIM_PROCESS_ATR)
	   {
	      SIM_Rxhandler(sim_int, hw_cb);
	   }

	   if( SimCard->State == SIM_PROCESS_PTS)
	   {
         SIM_SetEvent_MT6302(SimCard,SIM_INIPTSERR, hw_cb);
         SIM_ASSERT(0);
	   }

	   if (SimCard->State == SIM_PROCESSCMD)
	   {
	      if(SimCard->recDataErr == KAL_TRUE)
	      {
	         SIM_SetEvent_MT6302(SimCard,SIM_CMDRECERR, hw_cb);
	         SIM_ASSERT(0);
	      }
	      else
	      {
	         switch(SimCard->cmdState)
	         {
	            case SIM_ProcessClk:
	               ////dbg_print("SIM_ProcessClk\r\n");
	               SIM_SetEvent_MT6302(SimCard,SIM_CLKPROC, hw_cb);
	               break;

	            case SIM_StopClk:
	            	/*in Gemini project, we can't use HISR to stop clk*/
				ASSERT(0);
	               break;

	            default: /*normal command case*/
	               #ifdef NoT0CTRL
	               if (SimCard->cmdState == SIM_WaitProcByte)
	               {
   	               kal_uint8 ACK;
	                  kal_uint8 Error;
	                  Error = KAL_TRUE;
	                  while(SIM_FIFO_GetLev())
	                  {
      	               ACK = (kal_uint8)SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK);
	                     if (ACK == 0x60)    //NULL
                        {
                           continue;
                        }
                        if (SIM_CheckSW(ACK))    //ACK
                        {
                           SimCard->SW1 = ACK;
                           SimCard->SW2 = (kal_uint8)SIM_Reg(SIM_DATA);
                           SIM_SetEvent_MT6302(SimCard,SIM_SUCCESS, hw_cb);
                           Error = KAL_FALSE;
                        }
                        else
                        {
                           break;
                        }
	                  }
	                  if (Error)
	                  {
      	               SIM_SetEvent_MT6302(SimCard,SIM_CMDTOUT, hw_cb);
      	               SIM_ASSERT(0);
	                  }
	               }
	               else
	               {
   	               SIM_SetEvent_MT6302(SimCard,SIM_CMDTOUT, hw_cb);
   	               SIM_ASSERT(0);
	               }
	               #else /*NoT0CTRL*/
	               #ifdef SIM_NULLBYTE_ISSUE
			SimCard->simMagic1 ++;
			#endif

	               SIM_ASSERT(0);
	               SimCard->timeout = KAL_TRUE;
	               SIM_SetEvent_MT6302(SimCard,SIM_CMDTOUT, hw_cb);
	               #endif   /*NoT0CTRL*/
	               break;
	         }/*endof switch*/
	      }
	   }/*if (SimCard->State == SIM_PROCESSCMD)*/

	   if (SimCard->State == SIM_SERIOUSERR)
	   {
         SIM_SetEvent_MT6302(SimCard,SIM_CMDTXERR, hw_cb);
         SIM_ASSERT(0);
	   }
	   SIM_DisAllIntr();
	}

	if (sim_int & SIM_STS_RX)
	{
	   ////dbg_print("SIM_STS_RX\r\n");
	   if(SimCard->timeout != KAL_TRUE)
      SIM_Rxhandler(sim_int, hw_cb);
	}

   if ( sim_int & SIM_STS_OV)
   {
      ////dbg_print("SIM_STS_OV\r\n");
      SimCard->recDataErr = KAL_TRUE;
      if (SimCard->State == SIM_PROCESSCMD)
      {
			SIM_ASSERT(0);
	   }
   }

	if ( sim_int & SIM_STS_RXERR)
	{
	   ////dbg_print("SIM_STS_RXERR\r\n");
	   SimCard->recDataErr = KAL_TRUE;
	   SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,SIM_IRQEN_TOUT);
      if (SimCard->State == SIM_PROCESSCMD)
      {
			SIM_ASSERT(0);
	   }
	}

   if ( (sim_int &  SIM_IRQEN_T0END)
       && (SimCard->State == SIM_PROCESSCMD))
	{
	#ifdef SIM_NULLBYTE_ISSUE
		SimCard->simMagic1 ++;
	#endif

	   ////dbg_print("SIM_IRQEN_T0END\r\n");
      SIM_Cmdhandler(hw_cb);
      SIM_DisAllIntr();
	}

	if ( sim_int & SIM_STS_NATR)
	{
	   ////dbg_print("SIM_STS_NATR\r\n");
	   SIM_DisAllIntr();
	   if (SimCard->SIM_ENV == ME_18V_30V)
	   {
	      if (SimCard->Power == SimCard->initialPower)
         {
            if (SimCard->Power != SIM_30V)
            {
               SimCard->Power = SIM_30V;
            }
            else
            {
               SimCard->Power = SIM_18V;
            }
            SIM_L1Reset(hw_cb, KAL_FALSE);
         }
         else
         {
            SIM_Reject_MT6302(hw_cb);
         }
	   }
	   else
	   {
	      SIM_Reject_MT6302(hw_cb);
	   }
   }

	if ( sim_int & SIM_STS_SIMOFF)
	{
		peerHWCb = hw_cb->MT6302PeerInterfaceCb;
		SimCardNow = GET_SIM_CB(hw_cb->simInterface);
		PeerSimCard = GET_SIM_CB(peerHWCb->simInterface);
		
		sim_MT6302_addMsg(SIM_MT6302_TEST_7, PeerSimCard->clkStop, SimCardNow->clkStop, peerHWCb->simInterface);

	   ////dbg_print("SIM_STS_SIMOFF\r\n");
		SIM_DisAllIntr();
      if (SimCard->State == SIM_PWROFF)
      {
         sim_PDNEnable_MT6302(hw_cb);
         if (SimCard->reject_set_event)
         {
            SIM_SetEvent_MT6302(SimCard,SIM_NOREADY, hw_cb);
            SIM_ASSERT(0);
         }
      }
      else
      {
//#if ( (!defined(MT6205)) && (!defined(MT6205B)) )
#if !defined(DRV_SIM_MT6205B_SERIES)
         if (SimCard->State == SIM_WaitRejectDone)
         {
            SIM_Initialize(SimCard->Data_format,SimCard->Power, hw_cb);
         }
         else
         {
            SIM_ASSERT(0);
         }
#else /*! (MT6205,MT6205B)*/
         SIM_Initialize(SimCard->Data_format,SimCard->Power, hw_cb);
#endif   /*MT6205,MT6205B*/
      }
	}
	IRQClearInt(hw_cb->mtk_lisrCode);
	IRQUnmask(hw_cb->mtk_lisrCode);

}
void SIM_HISR_MT6302(void)
{
	kal_uint16 	sim_int;
	Sim_Card *SimCard;
	sim_HW_cb *hw_cb;

	hw_cb = sim_get_hwCb(sim_get_logical_from_SIMIF(0));
	SimCard = GET_SIM_CB(hw_cb->simInterface);
	sim_int = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);

#ifdef __OLD_PDN_ARCH__
#if !defined(__L1_STANDALONE__)
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
		sim_int , drv_get_current_time(), SimCard->State, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK),
		SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK), SIM_Reg(DRVPDN_CON1));
#endif
#else
#if !defined(__L1_STANDALONE__)
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
		sim_int , drv_get_current_time(), SimCard->State, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK),
		SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK), 0);
#endif
#endif

	if(recordHISR)
		sim_MT6302_addMsg(SIM_MT6302_CLKSTART_HISR, 0, 0, 0);
	////dbg_print("sim_int=%x\r\n",sim_int);
	SIM_HISR_MT6302_Common(hw_cb, sim_int);
}


void SIM_HISR2_MT6302(void)
{
	kal_uint16 	sim_int;
	Sim_Card *SimCard;
	sim_HW_cb *hw_cb;

	hw_cb = sim_get_hwCb(sim_get_logical_from_SIMIF(1));
	SimCard = GET_SIM_CB(hw_cb->simInterface);
	sim_int = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);

#ifdef __OLD_PDN_ARCH__
#if !defined(__L1_STANDALONE__)
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
		sim_int , drv_get_current_time(), SimCard->State, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK),
		SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK), SIM_Reg(DRVPDN_CON1));
#endif
#else
#if !defined(__L1_STANDALONE__)
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
		sim_int , drv_get_current_time(), SimCard->State, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK),
		SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK), 0);
#endif
#endif

	if(recordHISR)
		sim_MT6302_addMsg(SIM_MT6302_CLKSTART_HISR, 0, 0, 0);
	////dbg_print("sim_int=%x\r\n",sim_int);
	SIM_HISR_MT6302_Common(hw_cb, sim_int);	
}

void SIM_LISR_MT6302(void)
{
   sim_HW_cb *hw_cb;

   hw_cb = sim_get_hwCb(sim_get_logical_from_SIMIF(0));
   IRQMask(hw_cb->mtk_lisrCode);
   drv_active_hisr(DRV_SIM_HISR_ID);
}

void SIM_LISR2_MT6302(void)
{
   sim_HW_cb *hw_cb;

   hw_cb = sim_get_hwCb(sim_get_logical_from_SIMIF(1));
   IRQMask(hw_cb->mtk_lisrCode);
   drv_active_hisr(DRV_SIM2_HISR_ID);
}

#if 1
//==========================SIM adaption=============================
/*
* FUNCTION
*  L1sim_PowerOff
*
* DESCRIPTION
*     The function requests the driver to deactivate SIM
*
* CALLS
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void sim_PowerOff_MT6302(sim_HW_cb *hw_cb)  //Validate
{
	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);

   SIM_DisAllIntr();
   sim_PDNDisable_MT6302(hw_cb);
   if(SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK) | SIM_CTRL_HALT){
   	SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);
   }
   SimCard->reject_set_event = KAL_FALSE;
   SIM_Reject_MT6302(hw_cb);
}

/*
* FUNCTION
*	L1sim_Reset
*
* DESCRIPTION
*   	The function L1sim_Reset is used to reset SIM by specific voltage
*
* CALLS
*
* PARAMETERS
*	resetVolt: Request the driver to reset SIM at voltage resetVolt
*	resultVolt: The pointer to the voltage after the driver reset SIM.
*	(RESET_3V,RESET_5V)
*	Info: The pointer to buffer of ATR data returned from SIM
*
* RETURNS
*	SIM_NO_ERROR	No SIM error
*	SIM_NO_INSERT	No SIM inserted
*	SIM_CARD_ERROR	SIM fatal error
*
* GLOBALS AFFECTED
*   external_global
*/
static kal_uint8 L1sim_Core_Reset(kal_uint8 resetVolt, kal_uint8 *resultVolt,AtrStruct *Info, sim_HW_cb *hw_cb)	//Validate
{
	kal_uint8 index = 0;
  	Sim_Card *SimCard;
  	usim_dcb_struct	*usim_dcb;
	kal_bool  returnBool;
	index = index;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	SimCard = GET_SIM_CB(hw_cb->simInterface);

   SIM_DisAllIntr();
   kal_sleep_task(2);
   SimCard->sim_card_speed = sim_card_normal_speed;
   SimCard->reject_set_event = KAL_TRUE;
   sim_PDNDisable_MT6302(hw_cb);
   SimCard->TOUTValue = SIM_DEFAULT_TOUT_VALUE;
   SimCard->TOUT_Factor=1;
   SimCard->clkStop = KAL_FALSE;
	SimCard->Speed = Speed372;
	SimCard->State = SIM_WAIT_FOR_ATR;
	SimCard->Power = resetVolt;
	SimCard->initialPower = resetVolt;
	SimCard->power_class = UNKNOWN_POWER_CLASS;

	#if defined(__USIM_DRV__)
	{
		SimCard->Data_format = usim_dcb->dir;
		SimCard->result = SIM_SUCCESS;
		SimCard->sim_ATR_fail = KAL_FALSE;
		SimCard->power_class = usim_dcb->power_class;
	}
	#else
	SimCard->Data_format = SIM_direct;
	reset_index = 0;
	SimCard->result = SIM_NOREADY;
	SIM_L1Reset();

	SIM_WaitEvent_MT6302(SimCard,RST_READY, KAL_FALSE, hw_cb);

	if (SimCard->result == SIM_NOREADY)
	{
	   //L1sim_PowerOff();
	   return SIM_NO_INSERT;
	}

	if (SimCard->result == SIM_CARDERR)
	{
		if (SimCard->Power == SIM_30V)
		{
			SimCard->Power = SIM_18V;
			SIM_L1Reset();
		}
		else
		{
			SimCard->Power = SIM_30V;
			SIM_L1Reset();
		}
		SIM_WaitEvent_MT6302(SimCard,RST_READY, KAL_FALSE, hw_cb);
	}

	#endif
#if !defined(__L1_STANDALONE__)
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
		0 , index, SimCard->result, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK),
		0, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK));
#endif
	if (SimCard->result == SIM_SUCCESS)
	{
		index=0;
		while(1)
		{
			if (!SIM_ProcessATRData(hw_cb))
			{
#if !defined(__L1_STANDALONE__)
				drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
					0 , index, SimCard->State, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK),
					0, SimCard->PTS_check);
#endif
				index++;
				//if (index == 3)
				if (index == 2)
				{
				   SimCard->PTS_check = KAL_FALSE;
				}
				//else if (index > 3)
				else if (index > 2 || KAL_TRUE == SimCard->keepAtrFatal)
				{
				   	SimCard->PTS_check = KAL_FALSE;

					sim_PowerOff_MT6302(hw_cb);
#if !defined(__L1_STANDALONE__)
					drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
						SimCard->keepAtrFatal , index, SimCard->State, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK),
						0, SimCard->PTS_check);
#endif
					return SIM_CARD_ERROR;
				}
#ifdef DRV_SIM_RETRY_18V_ONLY_USIM_ON_PTS_ERROR
				else if ((SimCard->Power == SIM_18V) && SimCard->power_class == CLASS_C_18V)
				{
					SimCard->PTS_check = KAL_TRUE;
					SimCard->SIM_ENV = ME_18V_ONLY;
					//index = 0;
				}
#endif
#ifdef DRV_SIM_RETRY_3V_ON_PTS_ERROR				
				/* For [MAUI_01321659] begin, retry 3V when we fail in 1.8V*/
				else if ((SimCard->Power == SIM_18V) && (SIM_GetCurrentEnv() == ME_18V_30V))
				{
					SimCard->Power = SIM_30V;
					SimCard->PTS_check = KAL_TRUE;
					//index = 0;
				}/* For [MAUI_01321659] end */
#endif
				#if defined(__USIM_DRV__)
				SimCard->sim_ATR_fail = KAL_TRUE;
				#endif

				/*since we may power off the card and set SIM pdn, we have to disable PDN here, or we may trapped in wait event*/
				sim_PDNDisable_MT6302(hw_cb);


				returnBool = SIM_ResetNoATR(SimCard->Power, hw_cb);
				if(KAL_TRUE != returnBool){
					//kal_print("[SIM]:resetNoATR failed, hahahaahahahahahhahaahhahahahahhahaahhhhhhhhhhhhhhhhhhxxxxxxxxxxx");
					DRV_ICC_print(SIM_PRINT_RESET_NOATR_FAIL, 0, 0, 0, 0, 0);
					return SIM_CARD_ERROR;
				}
			}
			else
			{
			   if (resultVolt != NULL)
			   {
			      *resultVolt = SimCard->Power;
			   }
			   if (Info != NULL)
			   {
	            for (index = 0;index < SimCard->recDataLen;index++)
	            {
   		         Info->info[index] = SimCard->recData[index];
	            }
	         }
				return SIM_NO_ERROR;
			}
		}
	}
	else
	{
	   sim_PowerOff_MT6302(hw_cb);
		return SIM_CARD_ERROR;
	}
}

kal_uint8 sim_Reset_MT6302(kal_uint8 resetVolt, kal_uint8 *resultVolt,AtrStruct *Info, sim_HW_cb *hw_cb)	//Validate
{
	kal_uint8 result;
	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);

	SimCard->TS_HSK_ENABLE = KAL_TRUE;
	result = L1sim_Core_Reset(resetVolt,resultVolt,Info, hw_cb);
	if (result != SIM_NO_ERROR && KAL_FALSE == SimCard->keepAtrFatal)
  	{
		//kal_print("[SIM]: SIM reset fail with TS_HSK_ENABLE");
		DRV_ICC_print(SIM_PRINT_RESET_FAIL_WITH_TS_HSK_ENABLE, 0, 0, 0, 0, 0);
		SimCard->TS_HSK_ENABLE = KAL_FALSE;
		result = L1sim_Core_Reset(resetVolt,resultVolt,Info, hw_cb);
	}
	if(result == SIM_NO_ERROR)
	{
		sim_MT6302_setCardState(hw_cb, sim_MT6302_stateClkRunning);
		//kal_sprintf(sim_dbg_str,"[SIM]:SIM RESET OK, power:%d ,speed:%d",SimCard->Power,SimCard->Speed);
		//kal_print(sim_dbg_str);
		DRV_ICC_print(SIM_PRINT_RESET_OK_POWER_SPEED,SimCard->Power, SimCard->Speed, 0, 0, 0);
	}
	else
	{
		sim_MT6302_setCardState(hw_cb, sim_MT6302_stateDeactiavate);
		//kal_sprintf(sim_dbg_str,"[SIM]:SIM RESET FAIL, result:%d", result);
		//kal_print(sim_dbg_str);
		DRV_ICC_print(SIM_PRINT_RESET_FAIL_RESULT, result, 0, 0, 0, 0);
	}
	return result;
}

#if 0 //if following functions didn't be called, remove it
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_SIM_BAUD_6218B_SERIES)
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
#endif   /*MT6218,MT6218B*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(DRV_SIM_BAUD_6218B_SERIES)
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
#endif   /*MT6218,MT6218B*/
/* under construction !*/
#endif

/*
* FUNCTION
*	L1sim_Configure
*
* DESCRIPTION
*   	The function indicates clock mode when idle.
*
* CALLS
*
* PARAMETERS
*	clockMode: The clockMode defines the clock mode when idle.
*		CLOCK_STOP_AT_HIGH,CLOCK_STOP_AT_LOW,CLOCK_STOP_NOT_ALLOW
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void L1sim_Configure_MT6302(kal_uint8 clockMode, sim_HW_cb *hw_cb)	//Validate
{
	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);

	switch (clockMode)
	{
		case CLOCK_STOP_AT_HIGH:
		   // #if ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6218)) )
		   #if defined(DRV_SIM_CLKSTOP_6250B_SERIES)
		   //SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) |= SIM_CONF_HALTEN;
		   SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_HALTEN);
		   #endif   /*MT6205,MT6205B,MT6218*/
			SimCard->clkStop = KAL_TRUE;
			SimCard->clkStopLevel = KAL_TRUE;
			break;

		case CLOCK_STOP_AT_LOW:
		   //#if ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6218)) )
		   #if defined(DRV_SIM_CLKSTOP_6250B_SERIES)
		   //SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) |= SIM_CONF_HALTEN;
		   SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_HALTEN);
		   #endif   /*MT6205,MT6205B,MT6218*/
			SimCard->clkStop = KAL_TRUE;
			SimCard->clkStopLevel = KAL_FALSE;
			break;

		case CLOCK_STOP_NOT_ALLOW:
		   //#if ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6218)) )
		   #if defined(DRV_SIM_CLKSTOP_6250B_SERIES)
		   //SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) &= ~SIM_CONF_HALTEN;
		   SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_HALTEN);
		   #endif   /*MT6205,MT6205B,MT6218*/
			SimCard->clkStop = KAL_FALSE;
			break;

		default:
			break;
	}
}

#ifdef SIM_NULLBYTE_ISSUE
/*in MT6302 solution, there is only one task to access card in the same time, so we don't need the interface parameter*/
void sim_nullByteIssueGptTimeoutMT6302(void *parameter)
{
	Sim_Card *SimCard;
	sim_HW_cb *hw_cb;
	sim_MT6302_switchInfo *switch_CB;


	hw_cb = (sim_HW_cb *)parameter;
	switch_CB = sim_MT6302_get_MT6302switchCB(hw_cb);

	if(switch_CB->nullByteGPTServingInterface != switch_CB->sim_waitHisrCb_MT6302->simInterface)
		ASSERT(0);

	if(switch_CB->sim_waitHisrCb_MT6302 != hw_cb)
		ASSERT(0);

	if(switch_CB->nullByteGPTServingInterface != hw_cb->simInterface)
		ASSERT(0);

	SimCard = GET_SIM_CB(hw_cb->simInterface);
#ifdef __SIM_HOT_SWAP_SUPPORT__
	sim_get_card_status(hw_cb->simInterface, &hw_cb->IsCardRemove);
   /* [MAUI_03009364]If card is removed, we don't need to wait null bytes */
   if (hw_cb->IsCardRemove == KAL_TRUE)
   {
		SimCard->sim_nullByteIssueNullCount = 0;
		DRV_ICC_GPTI_StopItem(SimCard->sim_nullByteIssueGPT);
		/*must change magic after we confirm GPT won't trigger, since this code run in task context, we can run this code means GPT won't trigger*/
		SimCard->simMagic1 ++;
		SimCard->simMagic2 = SimCard->simMagic1;
		switch_CB->nullByteGPTServingInterface = hw_cb->simInterface;
		return;
   }
#endif
	if(SimCard->simMagic1 != SimCard->simMagic2){ /*cmd finished before GPT timeout*/
	}
	else{/*the GPT timer is used to find out these cases, it means we still haven't complete the CMD for so long duration*/

		/*it means the last byte received is null byte, we wait for 5 consecutive null byte noticed before ending the CMD*/
		if(0x60 == SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK)){
			SimCard->sim_nullByteIssueNullCount ++;
			if(15 < SimCard->sim_nullByteIssueNullCount){
				/*we have receive 5 null byte*/
				SIM_DisAllIntr();
				//dbg_print("[SIM] : null timeout\n\r");	
#ifdef ATEST_DRV_ENABLE	
				dbg_print("[SIM] : null timeout\n\r");
#else	
				dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_SIM_DRV, "[SIM] : null timeout\n\r");
#endif	

				//DRV_ICC_print(SIM_PRINT_NULL_TIME_OUT, hw_cb->simInterface, 0, 0, 0, 0);

				 SimCard->timeout = KAL_TRUE;
				SIM_SetEvent_MT6302(SimCard,SIM_NULLTIMEOUT, hw_cb);
			}
			else{
				//dbg_print("[SIM] : null byte\n\r");
#ifdef ATEST_DRV_ENABLE	
				dbg_print("[SIM] : null byte\n\r");
#else	
				dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_SIM_DRV, "[SIM] : null byte\n\r");
#endif

				//DRV_ICC_print(SIM_PRINT_NULL_BYTE, hw_cb->simInterface, SIM_Reg32(SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), 0, 0, 0);
				/*polling status every 3 sec*/
				DRV_ICC_GPTI_StartItem(SimCard->sim_nullByteIssueGPT, 300, sim_nullByteIssueGptTimeoutMT6302, parameter);
			}
		}
		else {/*received is not null*/
			SimCard->sim_nullByteIssueNullCount = 0;
			//dbg_print("[SIM] : non-null byte\n\r");
#ifdef ATEST_DRV_ENABLE	
			dbg_print("[SIM] : non-null byte\n\r");
#else	
			dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_SIM_DRV, "[SIM] : non-null byte\n\r");
#endif

			//DRV_ICC_print(SIM_PRINT_NON_NULL_BYTE, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK), SIM_Reg32(SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), 0, 0);
			DRV_ICC_GPTI_StartItem(SimCard->sim_nullByteIssueGPT, 300, sim_nullByteIssueGptTimeoutMT6302, parameter);
		}

	}
}
#endif



/*
* FUNCTION
*	SIM_CMD
*
* DESCRIPTION
*   	The function is used to transmit coded command and
*	its following data to the driver.
*
* CALLS
*
* PARAMETERS
*	txData: Pointer to the transmitted command and data.
*	txSize:	The size of the transmitted command and data from AL to driver.
*	expSize: The size of expected data from SIM
*	result: Pointer to received data
* 	rcvSize: Pointer to the size of data received
*	parityError: 1 (parity error) or 0(no parity error)
*
* RETURNS
*	status(high byte:sw1 low byte: sw2)
*
* GLOBALS AFFECTED
*   external_global
*/

//#define GEMINI_ORIGINAL_CLKSTART
//#define GEMINI_CLKSTART2
#define GEMINI_CLKSTART3
#define GEMINI_NEW_DELAY



static kal_uint16 SIM_CMD(kal_uint8  *txData,kal_uint16  txSize,kal_uint8  *result,kal_uint16  *rcvSize, kal_uint8 *Error, sim_HW_cb *hw_cb)
//kal_uint16 L1sim_Cmd(kal_uint8  *txData,kal_uint16  txSize,kal_uint8  expSize, kal_uint8  *result,kal_uint8  *rcvSize, kal_uint8 *Error)
{
   kal_uint16 SW = 0;
   kal_uint8 index = 0;
   kal_uint16 INS;
   kal_uint16 temp;
   kal_uint16 expSize = *rcvSize;
#ifdef   SIM_ADDDMA
	kal_bool	txDelay = KAL_FALSE;
   kal_uint32 txaddr;
   kal_uint32 rxaddr;
#endif/*SIM_ADDDMA*/
	Sim_Card *SimCard;
	kal_uint32 clkStartTime1;
	kal_uint16 temp_reg;
	kal_uint32 savedMask = 0;
	sim_MT6302_switchInfo	*switch_CB;
	sim_MT6302_cardInfo	*card_cb;
	Sim_Card *PeerSimCard, *SimCardNow;
	sim_HW_cb *peerHWCb;

	card_cb = sim_MT6302_get_MT6302CardCB(hw_cb);
	switch_CB = sim_MT6302_get_MT6302switchCB(hw_cb);
	SimCard = GET_SIM_CB(hw_cb->simInterface);
	peerHWCb = hw_cb->MT6302PeerInterfaceCb;
	SimCardNow = GET_SIM_CB(hw_cb->simInterface);
	PeerSimCard = GET_SIM_CB(peerHWCb->simInterface);

	sim_MT6302_addMsg(SIM_MT6302_TEST_6, PeerSimCard->clkStop, SimCardNow->clkStop, peerHWCb->simInterface);

	if(result == NULL && *rcvSize != 0)
	{
		*Error = KAL_TRUE;
	  	return 0;
	}
	if (SimCard->State != SIM_PROCESSCMD)
	{
	   *Error = KAL_TRUE;
	   return 0;
	}

   #ifdef NoT0CTRL
   if ((SimCard->cmdState != SIMD_CmdIdle)&&(SimCard->cmdState != SIM_StopClk))
   {
      *Error = KAL_TRUE;
      return 0;
   }
   #endif   /*NoT0CTRL*/

   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
  #endif
#if defined(SIM_DEBUG_INFO)
  DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC15, *result,*(result+1),*(result+2),*(result+3),*(result+4));
  DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC15, txSize,*rcvSize,index,SW,SimCard->timeout);
#endif

#if defined(GEMINI_ORIGINAL_CLKSTART)
   /*for clock stop mode*/
   SIM_DisAllIntr();

   if (SimCard->clkStop == KAL_TRUE)
   {
      SIM_ActiveClk_MT6302();
   }
   else
   {
      sim_PDNDisable_MT6302(hw_cb);
   }
   //delayIndex = 400000;
/*
   recordHISR = KAL_TRUE;
   sim_MT6302_addMsg(SIM_MT6302_CLKSTART_START, 0, 0, 0);
   delayIndex = 60000;
   while(delayIndex > 0)
   	delayIndex--;
   recordHISR = KAL_FALSE;
   sim_MT6302_addMsg(SIM_MT6302_CLKSTART_END, 0, 0, 0);
*/
   sim_MT6302_setCardState(hw_cb, sim_MT6302_stateClkRunning);
   SIM_DisAllIntr();

   if( (SimCard->Speed != Speed372) &&
       ((SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK)) & SIM_CTRL_HALT)
     )
   {
      //SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) &= ~SIM_CONF_TOUTEN;
      SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);
      SIM_SetTOUT(ClkStopTimeTable[SimCard->Speed][0]* SimCard->TOUT_Factor, hw_cb);
      //SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) |= SIM_CONF_TOUTEN;
      SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);
      SimCard->cmdState = SIM_ProcessClk;
      SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,SIM_IRQEN_TOUT);
      SIM_WaitEvent_MT6302(SimCard,CLK_PROC, KAL_FALSE, hw_cb);
   }
#ifndef DRV_SIM_HIGH_SPEED
	else if(SimCard->is_err && SimCard->Speed == Speed32) // to solve ROSSINI SIM issue
#else
	else if(SimCard->is_err && (SimCard->Speed == Speed32 || SimCard->Speed == Speed16 || SimCard->Speed == Speed8)) // to solve ROSSINI SIM issue
#endif
	{
		kal_uint32 t1;

		t1 = SIM_GetCurrentTime();
		while((SIM_GetCurrentTime()-t1) < 5); // delay 500 clock cycles (152us)

	}
#elif defined (GEMINI_CLKSTART2)
	/*for clock stop mode*/
   SIM_DisAllIntr();


   if (SimCard->clkStop == KAL_TRUE)
   {
      SIM_ActiveClk_MT6302();
   }
   else
   {
      sim_PDNDisable_MT6302(hw_cb);
   }

   if(switch_CB->sim_MT6302_needCLKStartTimeout)
   {
   	sim_MT6302_addMsg(SIM_MT6302_CLKSTART_NEW_TRUE, 0, 0, 0);
   	switch_CB->sim_MT6302_needCLKStartTimeout = KAL_FALSE;
   //delayIndex = 400000;
/*
   recordHISR = KAL_TRUE;
   sim_MT6302_addMsg(SIM_MT6302_CLKSTART_START, 0, 0, 0);
   delayIndex = 60000;
   while(delayIndex > 0)
   	delayIndex--;
   recordHISR = KAL_FALSE;
*/
   sim_MT6302_addMsg(SIM_MT6302_CLKSTART_END, 0, 0, 0);

   sim_MT6302_setCardState(hw_cb, sim_MT6302_stateClkRunning);
   SIM_DisAllIntr();
   }
   else{
   	sim_MT6302_addMsg(SIM_MT6302_CLKSTART_NEW_FALSE, 0, 0, 0);
   	sim_MT6302_setCardState(hw_cb, sim_MT6302_stateClkRunning);
   	SIM_DisAllIntr();
   }
   if(sim_MT6302_CLKPass != card_cb->pins.CLK)
   	ASSERT(0);

   if( (SimCard->Speed != Speed372) &&
       ((SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK)) & SIM_CTRL_HALT)
     )
   {
      //SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) &= ~SIM_CONF_TOUTEN;
      SIM_SetTOUT(ClkStopTimeTable[SimCard->Speed][0]* SimCard->TOUT_Factor, hw_cb);
      //SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) |= SIM_CONF_TOUTEN;
      SimCard->cmdState = SIM_ProcessClk;
      SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,SIM_IRQEN_TOUT);
      SIM_WaitEvent_MT6302(SimCard,CLK_PROC, KAL_FALSE, hw_cb);
   }
	else if(SimCard->is_err && SimCard->Speed == Speed32) // to solve ROSSINI SIM issue
	{
		kal_uint32 t1;

		t1 = SIM_GetCurrentTime();
		while((SIM_GetCurrentTime()-t1) < 5); // delay 500 clock cycles (152us)

	}
#elif defined (GEMINI_CLKSTART3)
	/*for clock stop mode*/
   SIM_DisAllIntr();

   if(0x3 == SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK))
   	ASSERT(0);
#ifdef __OLD_PDN_ARCH__
   if((SIM_Reg(hw_cb->mtk_pdnAddr)) & (hw_cb->mtk_pdnBit))
   	ASSERT(0);
#endif


   if (SimCard->clkStop == KAL_TRUE)
   {
      	if(switch_CB->sim_MT6302_needCLKStartTimeout)
       {
       	switch_CB->sim_MT6302_needCLKStartTimeout = KAL_FALSE;
       	clkStartTime1 = drv_get_current_time();
       	sim_MT6302_addMsg(0x20080216, clkStartTime1, 0, 0);
		if(SimCard->Speed != Speed372){
			temp_reg = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK);
			temp_reg &= ~SIM_CONF_TOUTEN;
			SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), temp_reg);
#ifndef DRV_SIM_HIGH_SPEED
			if(3 <= SimCard->Speed ||
			   0 == SimCard->TOUT_Factor
			)
				ASSERT(0);
#else
			if(5 <= SimCard->Speed ||
			   0 == SimCard->TOUT_Factor
			)
				ASSERT(0);
#endif
			while(12 > (drv_get_current_time() - clkStartTime1));

			sim_MT6302_addMsg(0x20080216, drv_get_current_time(), 0, 0);
			/*
	      		SIM_SetTOUT(ClkStopTimeTable[SimCard->Speed][0]* SimCard->TOUT_Factor, hw_cb);
      			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) |= SIM_CONF_TOUTEN;
      			SimCard->cmdState = SIM_ProcessClk;
	      		SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,SIM_IRQEN_TOUT);
     			SIM_WaitEvent_MT6302(SimCard,CLK_PROC, KAL_FALSE, hw_cb);
     			*/
		}
	}
      else{
      	}
   }

	sim_MT6302_addMsg(SIM_MT6302_CLKSTART_END, 0, 0, 0);
	sim_MT6302_setCardState(hw_cb, sim_MT6302_stateClkRunning);
	if(sim_MT6302_CLKPass != card_cb->pins.CLK)
   		ASSERT(0);

	SIM_DisAllIntr();

	if(SimCard->is_err && SimCard->Speed == Speed32) // to solve ROSSINI SIM issue
	{
		kal_uint32 t1;

		t1 = SIM_GetCurrentTime();
		while((SIM_GetCurrentTime()-t1) < 5); // delay 500 clock cycles (152us)

	}

#else
	/*for clock stop mode*/
	SIM_DisAllIntr();

	if (SimCard->clkStop == KAL_TRUE)/*support clk stop*/
	{
		sim_PDNDisable_MT6302(hw_cb);
		/*if clock is now stopped, or interface encounter an clk-start event*/
		if((SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK) & SIM_CTRL_HALT) ||switch_CB->sim_MT6302_needCLKStartTimeout)
		{
			switch_CB->sim_MT6302_needCLKStartTimeout = KAL_FALSE;
			SIM_ActiveClk_MT6302();

#ifdef GEMINI_NEW_DELAY
{
			kal_uint32 delayIndex;

			recordHISR = KAL_TRUE;
			sim_MT6302_addMsg(SIM_MT6302_CLKSTART_START, 0, 0, 0);
			delayIndex = 60000;
			while(delayIndex > 0){
				delayIndex--;
			}

			recordHISR = KAL_FALSE;
			sim_MT6302_addMsg(SIM_MT6302_CLKSTART_END, 0, 0, 0);
			//
}
#else
			//SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) &= ~SIM_CONF_TOUTEN;
			SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);
			SIM_SetTOUT(ClkStopTimeTable[SimCard->Speed][0]* SimCard->TOUT_Factor, hw_cb);
			//SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) |= SIM_CONF_TOUTEN;
			SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);
			SimCard->cmdState = SIM_ProcessClk;
			SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,SIM_IRQEN_TOUT);
			SIM_WaitEvent_MT6302(SimCard,CLK_PROC, KAL_FALSE, hw_cb);
#endif
		}
		else{/*clk is currently running, not stopped*/
			sim_PDNDisable_MT6302(hw_cb);
			SIM_DisAllIntr();
		}
	}
	else/*not support clk stop*/
	{
		sim_PDNDisable_MT6302(hw_cb);
	}


	sim_MT6302_setCardState(hw_cb, sim_MT6302_stateClkRunning);
	SIM_DisAllIntr();

	if(SimCard->is_err && SimCard->Speed == Speed32) // to solve ROSSINI SIM issue
	{
		kal_uint32 t1;

		t1 = SIM_GetCurrentTime();
		while((SIM_GetCurrentTime()-t1) < 5); // delay 500 clock cycles (152us)

	}
#endif

	/*check pdn bit and clk*/
#ifdef __OLD_PDN_ARCH__
	if((SIM_Reg(hw_cb->mtk_pdnAddr)) & (hw_cb->mtk_pdnBit))
		ASSERT(0);
#endif
	if(0x1 != SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK))
		ASSERT(0);


	if(KAL_FALSE == switch_CB->sim_MT6302_taskAccessing)
		ASSERT(0);
	/*check pin state*/
	if(((0x1<<hw_cb->MT6302PortNo) == (switch_CB->sim_MT6302_regValue[0] & (0x5 <<hw_cb->MT6302PortNo))) && (sim_MT6302_cardTypeAL == card_cb->type))
		ASSERT(0);
	if((0x1<<hw_cb->MT6302PortNo) != (switch_CB->sim_MT6302_regValue[1] & (0x5 <<hw_cb->MT6302PortNo)))
		ASSERT(0);
	if((0x1<<hw_cb->MT6302PortNo) != (switch_CB->sim_MT6302_regValue[2] & (0x5 <<hw_cb->MT6302PortNo)))
		ASSERT(0);
	if((0x4<<hw_cb->MT6302PortNo) != (switch_CB->sim_MT6302_regValue[3] & (0x4 <<hw_cb->MT6302PortNo)))
		ASSERT(0);
	if(0x43 == (switch_CB->sim_MT6302_regValue[2]))
		ASSERT(0);

	sim_MT6302_SPIWrite(switch_CB, switch_CB->sim_MT6302_regValue[1]);
	sim_MT6302_SPIWrite(switch_CB, switch_CB->sim_MT6302_regValue[2]);


	if(0 != SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK)){
		/*we print index, */
#if !defined(__L1_STANDALONE__)
   		drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK) , SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK),
			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK),
			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK)
		);
#endif
	}


   //SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) &= ~SIM_CONF_TOUTEN;
   SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN)

   kal_set_eg_events(SimCard->event,0,KAL_AND);  //2: NU_AND

   SIM_SetTOUT(SimCard->TOUTValue, hw_cb);
   SIM_FIFO_Flush();
	// delay 100 clock cycles (30us) [MAUI_03431888]/[MAUI_03433590]
	while(SIM_Reg(SIM0_BASE_ADDR_MTK+SIM_CLR_STA)==1);
	
	{
		kal_uint32 t1;
		t1 = drv_get_current_time();
		while((drv_get_current_time()-t1) < 1);
	}   
	
   *Error = KAL_FALSE;
   SimCard->recDataErr = KAL_FALSE;

#ifdef SIM_ADDDMA
   txaddr = (kal_uint32)txData;
   rxaddr = (kal_uint32)result;
#else /*SIM_ADDDMA*/
   SimCard->txbuffer = txData;
   SimCard->txsize = txSize;
   SimCard->rxbuffer = result;
   SimCard->recDataLen = 0;
#ifdef NoT0CTRL
   SimCard->recsize = expSize;
   SimCard->txindex = 0;
   SimCard->INS = *(txData+1);
#endif   /*NoT0CTRL*/
#endif/*SIM_ADDDMA*/

#ifndef NoT0CTRL
   INS = (kal_uint16)*(txData+1);
   SIM_SetIMP3(*(txData+4));
   SimCard->cmdState = SIM_WaitCmdEnd;
#endif   /*NoT0CTRL*/

#ifdef SIM_ADDDMA
   for(index=0;index<5;index++)
   {
      SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK,*(txData+index));
   }
   //DRVPDN_Disable(DRVPDN_CON0,DRVPDN_CON0_DMA,PDN_DMA);

   DMA_Stop(SimCard->sim_dmaport);
   SIM_SetRXTIDE(1, hw_cb);
   if (expSize == 0)
   {
//      #if defined(SIM_DEBUG_INFO)
//		kal_print("SIM TX");
//	  #endif

      SIM_SetTXTIDE(0, hw_cb);
      //#if ( defined(MT6205) || defined(MT6205B) )

      SimCard->sim_menu.addr = (kal_uint32)(txaddr+5);  /*1*/
      SimCard->sim_input.type = DMA_HWTX; /*2*/
      SimCard->sim_input.count = txSize-5;       /*3*/
	if(SimCard->sim_input.count > SIM_TX_DELAY_LEN && SimCard->Speed > Speed372)
		txDelay = KAL_TRUE;
     SimCard->sim_input.callback = NULL;   /*4*/
         /*DMA_Config(sim_dmaport, &sim_input, KAL_TRUE);     */


     INS |= SIM_INS_INSD;
   }
   else
   {
//      #if defined(SIM_DEBUG_INFO)
//	  kal_print("SIM RX");
//	  #endif

      SIM_SetTXTIDE(0xffff, hw_cb);

      //#if ( defined(MT6205) || defined(MT6205B) )
         SimCard->sim_menu.addr = (kal_uint32)(rxaddr);  /*1*/
         SimCard->sim_input.type = DMA_HWRX; /*2*/
         SimCard->sim_input.count = expSize;       /*3*/
         SimCard->sim_input.callback = NULL;   /*4*/
         /*DMA_Config(sim_dmaport, &sim_input, KAL_TRUE);  */
   }
   temp = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
   temp = temp; //fix assigned but not used warning

   SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK, SIM_IRQEN_CMDDMANormal);
#else /*SIM_ADDDMA*/
#ifdef NoT0CTRL
   for(index=0;index<5;index++)
   {
      SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK,*(txData+index));
   }
   SimCard->txindex = 5;
   SimCard->cmdState = SIM_WaitProcByte;

   if (expSize == 0) //Transmit
   {
      if (txSize == 5)
      {
         SIM_SetRXTIDE(2, hw_cb);
      }
      else
      {
         SIM_SetRXTIDE(1, hw_cb);
      }
   }
   else
   {
      if ((expSize+3) > 15)
      {
         SIM_SetRXTIDE(CMD_RECBUFSIZE-8, hw_cb);
      }
      else
      {
         SIM_SetRXTIDE(expSize+3, hw_cb);
      }
   }
   temp = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
   SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK, SIM_IRQEN_CMDNormal);
#else /*NoT0CTRL*/
   if(txSize <= 15)
   {
      for(index=0;index<txSize;index++)
      {
         SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK,*(txData+index));
      }
      SimCard->txindex = txSize;
      temp = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
      SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,SIM_IRQEN_CMDNormal);
   }
   else
   {
      for(index=0;index<15;index++)
      {
         SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK,*(txData+index));
      }
      SimCard->txindex = 15;
      SIM_SetTXTIDE(0, hw_cb);
      temp = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
      SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK, (SIM_IRQEN_CMDNormal|SIM_IRQEN_TX));
   }

   if (expSize > 0)
   {
      if (expSize > 15)
      {
         SIM_SetRXTIDE(CMD_RECBUFSIZE, hw_cb);
      }
      else
      {
         SIM_SetRXTIDE(expSize, hw_cb);
      }
      /* maybe changed for 64k rate */
   }
   else
   {
      INS |= SIM_INS_INSD;
   }
#endif /*NoT0CTRL*/
#endif/*SIM_ADDDMA*/

#ifdef SIM_ADDDMA
   //#if ( defined(MT6205) || defined(MT6205B) )
	/*DMA add this assertion, so we should avoid this*/
	if(0 != SimCard->sim_input.count)
      		DMA_Config(SimCard->sim_dmaport, &SimCard->sim_input, KAL_FALSE);
#endif   /*SIM_ADDDMA*/

	{
		extern void DMA_Run(kal_uint8 channel);




#ifndef    NoT0CTRL
#ifdef	SIM_NULLBYTE_ISSUE
		SimCard->sim_nullByteIssueNullCount = 0;
		DRV_ICC_GPTI_StopItem(SimCard->sim_nullByteIssueGPT);
		/*must change magic after we confirm GPT won't trigger, since this code run in task context, we can run this code means GPT won't trigger*/
		SimCard->simMagic1 ++;
		SimCard->simMagic2 = SimCard->simMagic1;
		switch_CB->nullByteGPTServingInterface = hw_cb->simInterface;
		DRV_ICC_GPTI_StartItem(SimCard->sim_nullByteIssueGPT, 300, sim_nullByteIssueGptTimeoutMT6302, hw_cb);
#endif
#endif   /*NoT0CTRL*/


#ifdef __OLD_PDN_ARCH__		
#if !defined(__L1_STANDALONE__)
		drv_trace8(TRACE_GROUP_4, SIM_GEMINI_CMD1, SIM_Reg(DRVPDN_CON1), hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK),
			INS, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK),
			0, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK)
			);
#endif
#else
#if !defined(__L1_STANDALONE__)
		drv_trace8(TRACE_GROUP_4, SIM_GEMINI_CMD1, 0, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK),
			INS, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK),
			0, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK)
			);
#endif
#endif
#if !defined(__L1_STANDALONE__)
		drv_trace8(TRACE_GROUP_4, SIM_GEMINI_CMD2, switch_CB->sim_MT6302_regValue[0], switch_CB->sim_MT6302_regValue[1], switch_CB->sim_MT6302_regValue[2], switch_CB->sim_MT6302_regValue[3],
					drv_get_current_time(), SimCard->sim_input.count,
			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK)
			);

		drv_trace8(TRACE_GROUP_4, SIM_GEMINI_CMD3, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IMP3_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x70),
			SIM_Reg(SIM0_BASE_ADDR_MTK + 0x74),
			*txData, *(txData + 1), *(txData + 2), *(txData + 3), *(txData + 4)
				);
#endif
		/*in case */
		SimCard->EvtFlag = 0x0;

		if(txDelay == KAL_FALSE)
			savedMask = SaveAndSetIRQMask();
#ifndef    NoT0CTRL
		SIM_SetCmdINS(INS);
#endif   /*NoT0CTRL*/

#ifdef SIM_ADDDMA
	/* add delay(1ms) between ACK and first transmit data for enhance speed card */
	//#if ( defined(MT6205) || defined(MT6205B) )
	//#elif defined(MT6218B)
	if(txDelay == KAL_TRUE)
	{
		volatile kal_uint32 t1,t2;
		kal_uint32 loop = SIM_TX_DELAY_LOOP*10;

		while(loop--)
		{
			if(SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STATUS_MTK)&(SIM_STATUS_ACK|SIM_STATUS_NACK))
				break;
		}
		t1 = SIM_GetCurrentTime();
		do{
		t2 = SIM_GetCurrentTime();
		}while(drv_get_duration_tick(t1,t2) < 32);
	}

	//#if ( defined(MT6205) || defined(MT6205B) )
	sim_MT6302_addMsg(0x34567801, SIM_Reg32(0x80030018+ (SimCard->sim_dmaport * 0x100)), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), drv_get_current_time());
	sim_MT6302_addMsg(SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_TIDE_MTK), SIM_Reg32(DMA_START(SimCard->sim_dmaport )), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STATUS_MTK));
	/*DMA add this assertion, so we should avoid this*/
	if(0 != SimCard->sim_input.count)
		DMA_Run(SimCard->sim_dmaport);
#endif   /*SIM_ADDDMA*/

		if(txDelay == KAL_FALSE)
			RestoreIRQMask(savedMask);
		if(0 < expSize){
			kal_uint32 time1, time2;

			sim_MT6302_addMsg(0x98765432, SIM_Reg32(DMA_RLCT(SimCard->sim_dmaport )), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STATUS_MTK));
			time1 = drv_get_current_time();
			do{
				time2 = SIM_GetCurrentTime();
			}while(drv_get_duration_tick(time1,time2) < 2);
			/*poll DMA_RLCT for 32us*/
			sim_MT6302_addMsg(SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IMP3_MTK), SIM_Reg32(DMA_RLCT(SimCard->sim_dmaport )), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STATUS_MTK));
		}
	}
   sim_MT6302_addMsg(0x2468024, txDelay, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), drv_get_current_time());
   //SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) |= SIM_CONF_TOUTEN;
   SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);
   SIM_WaitEvent_MT6302(SimCard,SIM_EVT_CMD_END, KAL_FALSE, hw_cb);

#ifdef	SIM_NULLBYTE_ISSUE
		DRV_ICC_GPTI_StopItem(SimCard->sim_nullByteIssueGPT);
#endif


#ifdef SIM_ADDDMA
   //#if ( defined(MT6205) || defined(MT6205B) )
	/*DMA add this assertion, so we should avoid this*/
	if(0 != SimCard->sim_input.count)
		DMA_Stop(SimCard->sim_dmaport);
#endif   /*SIM_ADDDMA*/

#ifdef NoT0CTRL
   SimCard->initialPower = SimCard->cmdState;
   SimCard->cmdState = SIMD_CmdIdle;
#endif   /*NoT0CTRL*/

#ifdef __OLD_PDN_ARCH__
	/*check PDN, baud rate, clk_stop here*/
   if(SIM_Reg(hw_cb->mtk_pdnAddr) & hw_cb->mtk_pdnBit)
   	ASSERT(0);
#endif
   if(0x3 == SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK))
   	ASSERT(0);
   if(((card_cb->baud << 2)|0x1) != SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK))
   	ASSERT(0);

	sim_MT6302_addMsg(SIM_MT6302_TEST_5, PeerSimCard->clkStop, SimCardNow->clkStop, peerHWCb->simInterface);

   if (SimCard->result == SIM_SUCCESS && SimCard->recDataErr == KAL_FALSE)
   {
    #ifdef  SIM_ADDDMA
    if(expSize != 0)
       *rcvSize = expSize - SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IMP3_MTK);
   //DRVPDN_Enable(DRVPDN_CON0,DRVPDN_CON0_DMA,PDN_DMA);
    #else /*SIM_ADDDMA*/
   *rcvSize = SimCard->recDataLen;
    #endif /*SIM_ADDDMA*/

//   #if defined(SIM_DEBUG_INFO)
//   kal_print("SIM_SUCCESS");
//   #endif

      #ifdef NoT0CTRL
      SW = (SimCard->SW2 | (SimCard->SW1 << 8));
      #else /*NoT0CTRL*/
      SIM_ObtainSW(SW);
      #endif   /*NoT0CTRL*/

#if defined(SIM_DEBUG_INFO)
	   DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC16, SimCard->sim_menu.addr, SimCard->sim_input.type, SimCard->sim_input.count,SW,*rcvSize);
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC16, txSize,*Error,*result,*(result+1),*(result+2));		
#endif

      //dbg_print("SW=%x\r\n",SW);
      /*for clock stop mode*/
      if(SimCard->clkStop == KAL_TRUE)
      {
      	/*in Gemini project, we don't use SIM controller's timeout as clk-stop timer*/
         //SIM_DisAllIntr(simInterface);
         //SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) &= ~SIM_CONF_TOUTEN;
         //SIM_SetTOUT(ClkStopTimeTable[SimCard->Speed][1]* SimCard->TOUT_Factor, hw_cb);
         //SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK) |= SIM_CONF_TOUTEN;
         //SimCard->cmdState = SIM_StopClk;
         //SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,SIM_IRQEN_TOUT);
         sim_MT6302_clkStopTimer(hw_cb);
      }
      return SW;
   }
   else
   {
   	//kal_sprintf(sim_dbg_str,"[SIM]:SIM_CMD fail status=%d", SimCard->result);
   	   //dbg_print(sim_dbg_str);
   	   DRV_ICC_print(SIM_PRINT_SIM_CMD_FAIL_STATUS, SimCard->result, SW, txSize, *rcvSize, expSize);
	   DRV_ICC_print(SIM_PRINT_SIM_CMD_FAIL_STATUS, SimCard->sim_menu.addr, SimCard->sim_input.type, SimCard->sim_input.count,*result,*(result+1));
	   DRV_ICC_print(SIM_PRINT_SIM_CMD_FAIL_STATUS, *(result+2),*(result+3),*(result+4),*(result+5),*(result+6));

#ifdef __OLD_PDN_ARCH__
   	/*we print DMA lefting, SIM controller power, SW1, SW2, 0x70, 0x74*/
#if !defined(__L1_STANDALONE__)
   	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
			SIM_Reg(DMA_base + 0x24 + (0x100 * SimCard->sim_dmaport)), SIM_Reg(DRVPDN_CON1), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW2_MTK),
			SIM_Reg(SIM0_BASE_ADDR_MTK + 0x70), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x74)
		);
#endif		
#else
#endif
   	if(0 != expSize){
#if !defined(__L1_STANDALONE__)
   		/*we print P3, rx buffer addr, ((EV_GCB *)SimCard->event)->ev_current_events, data count, rx 1st, 2nd byte*/
   		drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IMP3_MTK), (kal_uint32)result,
#ifndef __MEUT__
			0,
#else
			0,
#endif
			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK),
			*result, *(result+1)
		);
#endif
   	}
      //SimCard->recDataErr = KAL_FALSE;
		SimCard->is_err = KAL_TRUE;
      *Error = KAL_TRUE;
      return 0;
   }
}



/*
* FUNCTION
*	L1sim_Cmd
*
* DESCRIPTION
*   	The function is used to implement re-try command mechanism.
*
* CALLS
*
* PARAMETERS
*	txData: Pointer to the transmitted command and data.
*	txSize:	The size of the transmitted command and data from AL to driver.
*	expSize: The size of expected data from SIM
*	result: Pointer to received data
* 	rcvSize: Pointer to the size of data received
*	parityError: 1 (parity error) or 0(no parity error)
*
* RETURNS
*	status(high byte:sw1 low byte: sw2)
*
* GLOBALS AFFECTED
*   external_global
*/
static kal_uint16 L1sim_Cmd(kal_uint8  *txData,kal_uint16  txSize,kal_uint8  *result,kal_uint16  *rcvSize, kal_uint8 *Error, sim_HW_cb *hw_cb)
{
   kal_uint8 index;
   kal_uint16 SW;
	Sim_Card *SimCard;
	usim_dcb_struct *usim_dcb;
#ifdef SIM_CACHED_SUPPORT
	kal_uint8	*pNoncachedTx, *pNoncachedRx;
#endif

	SimCard = GET_SIM_CB(hw_cb->simInterface);

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);


   #if defined(SIM_DEBUG_INFO)
   kal_sprintf(sim_dbg_str,"L1sim_Cmd(1) txSize=%d, rcvSize=%d", txSize, *rcvSize);    
#ifdef ATEST_DRV_ENABLE	
		dbg_print(sim_dbg_str);
#else	
		dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_SIM_DRV, sim_dbg_str);
#endif	

	#endif

   if (SimCard->State != SIM_PROCESSCMD)
   {
      *Error = KAL_TRUE;
      return 0;
   }
   SimCard->get9000WhenSelect = KAL_FALSE;

   // while encounter physical errors, deactivate the SIM immediately
   for(index=0;index<3;index++)
   {
   	SimCard->timeout = KAL_FALSE;

#ifdef SIM_CACHED_SUPPORT
	if (INT_QueryIsCachedRAM(txData, txSize) || INT_QueryIsCachedRAM(result, 512)){
		GET_NCACHEDTX_P(pNoncachedTx, sim_get_hwCtrl_from_logicalNum(hw_cb->simInterface));
		GET_NCACHEDRX_P(pNoncachedRx, sim_get_hwCtrl_from_logicalNum(hw_cb->simInterface));
		kal_mem_cpy(pNoncachedTx, txData, txSize);
		if(INT_QueryIsCachedRAM(result, 512)){
			SW = SIM_CMD((kal_uint8 *)pNoncachedTx,txSize,(kal_uint8 *)pNoncachedRx,rcvSize,Error, hw_cb);
			if(0 != *rcvSize){
				if(512 < *rcvSize){
				DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC17, *rcvSize, txSize, SW,0,0);
				DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC17, *pNoncachedRx,*(pNoncachedRx+1),*(pNoncachedRx+2),*(pNoncachedRx+3),*(pNoncachedRx+4));		
					/*add for noise resistence*/
					if(
						*(pNoncachedRx+9) == SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IMP3_MTK) && //10th byte equals to IMP3
						10 == (SIM_Reg(DMA_COUNT(SimCard->sim_dmaport)) - SIM_Reg(DMA_RLCT(SimCard->sim_dmaport))) && //DMA transferred 10 bytes
						*(pNoncachedRx) == *txData && //1st byte of EMI equals to 1st byte of tx
						*(pNoncachedRx+1) == *(txData+1) && //2nd byte of EMI equals to 2nd byte of tx
						*(pNoncachedRx+2) == *(txData+2) && //3rd byte of EMI equals to 3rrd byte of tx
						*(pNoncachedRx+3) == *(txData+3) && //4tth byte of EMI equals to 4th byte of tx
						*(pNoncachedRx+4) == *(txData+4)  //5th byte of EMI equals to 5th byte of tx
					){
						*rcvSize = 0;
						*Error = 1;
						SW = 0x0000;
						return SW;
					}
					else if(
						10 > *(txData+4) && //The original DMA setting only receive fewer than 10 bytes.
						*(pNoncachedRx) == *txData && //1st byte of EMI equals to 1st byte of tx
						*(pNoncachedRx+1) == *(txData+1) && //2nd byte of EMI equals to 2nd byte of tx
						*(pNoncachedRx+2) == *(txData+2) && //3rd byte of EMI equals to 3rrd byte of tx
						*(pNoncachedRx+3) == *(txData+3) && //4tth byte of EMI equals to 4th byte of tx
						*(pNoncachedRx+4) == *(txData+4)  //5th byte of EMI equals to 5th byte of tx
					){
						*rcvSize = 0;
						*Error = 1;
						SW = 0x0000;
						return SW;
					}
				else if(
					SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IMP3_MTK) > *(txData+4) && //the IMP3 is uopdated to a value larger than P3.
					*(pNoncachedRx) == *txData && //1st byte of EMI equals to 1st byte of tx
					*(pNoncachedRx+1) == *(txData+1) && //2nd byte of EMI equals to 2nd byte of tx
					*(pNoncachedRx+2) == *(txData+2) && //3rd byte of EMI equals to 3rrd byte of tx
					*(pNoncachedRx+3) == *(txData+3) && //4tth byte of EMI equals to 4th byte of tx
					*(pNoncachedRx+4) == *(txData+4)  //5th byte of EMI equals to 5th byte of tx
				){
					*rcvSize = 0;
					*Error = 1;
					SW = 0x0000;
					return SW;
				}
				else if(
					SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IMP3_MTK) > *(txData+4) && //the IMP3 is uopdated to a value larger than P3. and *(pNoncachedRx+4) == *(txData+4) is different
					*(pNoncachedRx) == *txData && //1st byte of EMI equals to 1st byte of tx
					*(pNoncachedRx+1) == *(txData+1) && //2nd byte of EMI equals to 2nd byte of tx
					*(pNoncachedRx+2) == *(txData+2) && //3rd byte of EMI equals to 3rrd byte of tx
					*(pNoncachedRx+3) == *(txData+3) //4tth byte of EMI equals to 4th byte of tx
				){
					*rcvSize = 0;
					*Error = 1;
					SW = 0x0000;
					return SW;
				}

				sim_addMsg(0x11111001, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IMP3_MTK), SIM_Reg(DMA_COUNT(SimCard->sim_dmaport)), SIM_Reg(DMA_RLCT(SimCard->sim_dmaport)));
				sim_addMsg(0x12030201, *txData, *(txData+1), *(txData+2));
				sim_addMsg(0x12030202, *(txData+3), *(txData+4), *(pNoncachedRx));
				sim_addMsg(0x12030203, *(pNoncachedRx+1), *(pNoncachedRx+2), *(pNoncachedRx+3));
				sim_addMsg(0x12030204, *(pNoncachedRx+4), 0, 0);


#if !defined(__L1_STANDALONE__)
					drv_trace8(TRACE_GROUP_5, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__, SW, *rcvSize,
						SIM_Reg(DMA_RLCT(SimCard->sim_dmaport)), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IMP3_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK));
#endif						
					/*2nd to 9-th*/
#if !defined(__L1_STANDALONE__)
					drv_trace8(TRACE_GROUP_5, SIM_GEMINI_GEN1, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK),
						SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK));
#endif
					/*10-th to 16-th*/
#if !defined(__L1_STANDALONE__)
					drv_trace8(TRACE_GROUP_5, SIM_GEMINI_GEN1, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK),
						SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK));
#endif						
					ASSERT(0);
				}
				if(0 == result)
					ASSERT(0);
				kal_mem_cpy(result, pNoncachedRx, *rcvSize);
			}
		}
		else{
			SW = SIM_CMD((kal_uint8 *)pNoncachedTx,txSize, result, rcvSize,Error, hw_cb);
		}
	}
	else
#endif
	{
      SW = SIM_CMD(txData,txSize,result,rcvSize,Error, hw_cb);
	}

    if(0x9000 == SW && 0xA4 == txData[1]){
    	//dbg_print("[SIM]:0x9000 on select");
	DRV_ICC_print(SIM_PRINT_9000_ON_SELECT, 0, 0, 0, 0, 0);
    	SimCard->get9000WhenSelect = KAL_TRUE;
    }

      #if defined(SIM_DEBUG_INFO)
      kal_sprintf(sim_dbg_str,"L1sim_Cmd(2) txSize=%d, rcvSize=%d, fifo: %d", txSize, *rcvSize, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK));
#ifdef ATEST_DRV_ENABLE	
			dbg_print(sim_dbg_str);
#else	
			dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_SIM_DRV, sim_dbg_str);
#endif	

      #endif

		if(SimCard->timeout && SimCard->app_proto == USIM_PROTOCOL)
		{
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC18, txSize,*rcvSize,index,SW,SimCard->timeout);
		   /*SimCard->timeout's life cycle should be only in this L1sim_Cmd, reset to false before we leave*/
		   SimCard->timeout = KAL_FALSE;

		   	/*USIM FTA requires to deactivate the card after timeout in 100ms*/
			if(KAL_FALSE == sim_MT6302_QueryNeedManualControl(hw_cb)){
				sim_MT6302_passRST(hw_cb);
			}
			sim_PowerOff_MT6302(hw_cb);
			/*set card not present to prevent next SIM command rush in*/
			usim_dcb->present = KAL_FALSE;
			sim_MT6302_setCardState(hw_cb, sim_MT6302_stateDeactiavate);
			return SW;
		}
#ifdef __SIM_HOT_SWAP_SUPPORT__
		 sim_get_card_status(hw_cb->simInterface, &hw_cb->IsCardRemove);
		/* [MAUI_03009364]If card is removed, we don't need to wait status words */
		if(hw_cb->IsCardRemove && *Error == KAL_TRUE)
		{
		   /*SimCard->timeout's life cycle should be only in this L1sim_Cmd, reset to false before we leave*/
		   SimCard->timeout = KAL_FALSE;
			/*set card not present to prevent next SIM command rush in*/
			usim_dcb->present = KAL_FALSE;
			return SW;
		}
#endif
      if (*Error == 0)
         break;
   }

   if ( ((SW&0xf000) != 0x6000) && ((SW&0xf000) != 0x9000) )
   {
      *Error = KAL_TRUE;
   }

   if(*Error)
   {
		//kal_sprintf(sim_dbg_str,"[SIM]:SIM_CMD fail result=%d, status=%x", SimCard->result, SW);
		//dbg_print(sim_dbg_str);
		DRV_ICC_print(SIM_PRINT_CMD_FAIL_RESULT_STATUS, SimCard->result, SW, 0, 0, 0);
		//kal_sprintf(sim_dbg_str,"[SIM]: recDataErr=%d, timeout=%d, cmdState=%d, event_state=%d, EvtFlag=%d, clkStop=%d, app_proto=%d",
		//	SimCard->recDataErr, SimCard->timeout, SimCard->cmdState, SimCard->event_state,
		//	SimCard->EvtFlag, SimCard->clkStop, SimCard->app_proto);
		//dbg_print(sim_dbg_str);
		DRV_ICC_print(SIM_PRINT_RECEIVE_ERR_1, SimCard->recDataErr, SimCard->timeout, SimCard->cmdState, SimCard->event_state, SimCard->EvtFlag);
		DRV_ICC_print(SIM_PRINT_RECEIVE_ERR_2, SimCard->clkStop, SimCard->app_proto, 0, 0, 0);

#ifdef __OLD_PDN_ARCH__
		/*we print DMA lefting, SIM controller power, SW1, SW2, 0x70, 0x74*/
#if !defined(__L1_STANDALONE__)
   		drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
			SIM_Reg(DMA_base + 0x24 + (0x100 * SimCard->sim_dmaport)), SIM_Reg(DRVPDN_CON1), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW2_MTK),
			SIM_Reg(SIM0_BASE_ADDR_MTK + 0x70), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x74)
		);
#endif		
#else
#endif
   		if(0 != result){
   			/*we print P3, rx buffer addr, ((EV_GCB *)SimCard->event)->ev_current_events, data count, rx 1st, 2nd byte*/
#if !defined(__L1_STANDALONE__)
   			drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IMP3_MTK), (kal_uint32)result,
#ifndef __MEUT__
			0,
#else
			0,
#endif
			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK),
			*result, *(result+1)
			);
#endif			
   		}
	}

#ifdef SIM_CACHED_SUPPORT_WRITE_THROUGH_SERIES
	invalidate_wt_cache((kal_uint32)result, *rcvSize);
#endif

   /*SimCard->timeout's life cycle should be only in this L1sim_Cmd, reset to false before we leave*/
   SimCard->timeout = KAL_FALSE;
   return SW;
}

/*
* FUNCTION
*	L1sim_Init
*
* DESCRIPTION
*   	The function L1sim_Init initialize the SIM driver.
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void L1sim_Init_MT6302(sim_HW_cb *hw_cb)		//Validate
{
	kal_uint16 tmp;
	Sim_Card *SimCard, *peer_SimCard;
	sim_HW_cb *peerHWCb;
	sim_MT6302_switchInfo *switch_cb;
	switch_cb = sim_MT6302_get_MT6302switchCB(hw_cb);
	peerHWCb = hw_cb->MT6302PeerInterfaceCb;
	SimCard = GET_SIM_CB(hw_cb->simInterface);
	peer_SimCard = GET_SIM_CB(peerHWCb->simInterface);

	SimCard->SIM_ENV = SIM_GetCurrentEnv();
	if (SimCard->SIM_ENV == ME_30V_ONLY)
	{
	   SimCard->Power = SIM_30V;
	}
	else
	{
	   SimCard->Power = SIM_18V;
	}

	SimCard->Data_format = SIM_direct;
	SimCard->State = SIM_WAIT_FOR_ATR;
	SimCard->clkStop = KAL_FALSE;
	SimCard->Speed = Speed372;

   #ifdef SIM_ADDDMA
/* try to remove the restriction that SIM1 must reset before SIM2, comment this part's code
	if(KAL_FALSE == sim_physicalSlotChanged){
   		if(0 != hw_cb->simInterface && NULL != SimCard_cb[peerHWCb->simInterface].sim_dmaport)
			SimCard->sim_dmaport = SimCard_cb[0].sim_dmaport;
      		else if(0 != simInterface);//this case is legal since there maybe no SIM1 and we didn't do SIM1's L1sim_init
			//ASSERT(0);
	}
	else{
	 	if(1 != simInterface && NULL != SimCard_cb[1].sim_dmaport)
			SimCard->sim_dmaport = SimCard_cb[1].sim_dmaport;
      		else if(1 != simInterface);//this case is legal since there maybe no SIM1 and we didn't do SIM1's L1sim_init
			//ASSERT(0);
	}
*/
	if((kal_uint32)NULL != peer_SimCard->sim_dmaport)
		SimCard->sim_dmaport = peer_SimCard->sim_dmaport;

	if(DMA_SIM != hw_cb->mtk_dmaMaster 
#if (2 == SIM_DRV_MTK_INTERFACE_NUM)
		&& DMA_SIM2 != hw_cb->mtk_dmaMaster
#endif
	)
		ASSERT(0);

      if (SimCard->sim_dmaport == 0)
         SimCard->sim_dmaport = DMA_GetChannel((DMA_Master)hw_cb->mtk_dmaMaster);

      SimCard->sim_menu.TMOD.burst_mode = KAL_FALSE;
      SimCard->sim_menu.master = (DMA_Master)hw_cb->mtk_dmaMaster;
      SimCard->sim_menu.addr = (kal_uint32)NULL;  /*1*/

      SimCard->sim_input.type = DMA_HWTX; /*2*/
      SimCard->sim_input.size = DMA_BYTE;
      SimCard->sim_input.menu = &SimCard->sim_menu;
      SimCard->sim_input.count = 0;       /*3*/
      SimCard->sim_input.callback = NULL;   /*4*/
   #endif   /*SIM_ADDDMA*/

	/*following members are originally RW global variable, need additional initialize here*/
	SimCard->TOUTValue = SIM_DEFAULT_TOUT_VALUE;
   	SimCard->TOUT_Factor = 1;
   	SimCard->PTS_check = KAL_TRUE;

	tmp = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
	tmp = tmp; //fix assigned but not used warning
/*
	if(KAL_FALSE == sim_physicalSlotChanged){
		if(0 != simInterface && NULL != SimCard_cb[0].event)
			SimCard->event = SimCard_cb[0].event;
		else if(0 != simInterface);//this case is legal since there maybe no SIM1 and we didn't do SIM1's L1sim_init
			//ASSERT(0);
	}
	else{
		if(1 != simInterface && NULL != SimCard_cb[1].event)
			SimCard->event = SimCard_cb[1].event;
		else if(1 != simInterface);//this case is legal since there maybe no SIM1 and we didn't do SIM1's L1sim_init
			//ASSERT(0);
	}
*/
	if(NULL != peer_SimCard->event)
		SimCard->event = peer_SimCard->event;

	if (SimCard->event == NULL)
	   SimCard->event = kal_create_event_group("SIMEVT");

	if(SIM_base == hw_cb->mtk_baseAddr){
		if(hw_cb != sim_get_hwCb(sim_get_logical_from_SIMIF(0)))
			ASSERT(0);
		if(IRQ_SIM_CODE != hw_cb->mtk_lisrCode)
			ASSERT(0);
		DRV_Register_HISR(DRV_SIM_HISR_ID, SIM_HISR_MT6302);
	}
#if (2 == SIM_DRV_MTK_INTERFACE_NUM)
	else if(SIM2_base == hw_cb->mtk_baseAddr){
		if(hw_cb != sim_get_hwCb(sim_get_logical_from_SIMIF(1)))
			ASSERT(0);
		if(IRQ_SIM2_CODE != hw_cb->mtk_lisrCode)
			ASSERT(0);
		DRV_Register_HISR(DRV_SIM2_HISR_ID, SIM_HISR2_MT6302);
	}
#endif
	else{
			ASSERT(0);
	}


	/*IRQ related setting check */
	if(IRQ_SIM_CODE != hw_cb->mtk_lisrCode 
#if (2 == SIM_DRV_MTK_INTERFACE_NUM)
	&& IRQ_SIM2_CODE != hw_cb->mtk_lisrCode
#endif
	)
		ASSERT(0);

	if(SIM_base == hw_cb->mtk_baseAddr){
		IRQ_Register_LISR(hw_cb->mtk_lisrCode, SIM_LISR_MT6302,"SIM handler");
	}
#if (2 == SIM_DRV_MTK_INTERFACE_NUM)
	else if(SIM2_base == hw_cb->mtk_baseAddr){
		IRQ_Register_LISR(hw_cb->mtk_lisrCode, SIM_LISR2_MT6302,"SIM2 handler");
	}
#endif

	switch_cb->sim_waitHisrCb_MT6302 = hw_cb;

	sim_MT6302_LISRStateChange(hw_cb, sim_MT6302_LISRSim);

#ifdef	SIM_NULLBYTE_ISSUE
	if((kal_uint32)NULL != peer_SimCard->sim_nullByteIssueGPT)
		SimCard->sim_nullByteIssueGPT = peer_SimCard->sim_nullByteIssueGPT;
	if(SimCard->sim_nullByteIssueGPT == (kal_uint32)NULL)
			DRV_ICC_GPTI_GetHandle(&SimCard->sim_nullByteIssueGPT);
#endif

	IRQSensitivity(hw_cb->mtk_lisrCode,LEVEL_SENSITIVE);
	IRQUnmask(hw_cb->mtk_lisrCode);
}
#endif
//================================ Layer type SIM driver start ==================================
/*************************************************************************
* FUNCTION
*  L1sim_Cmd_Layer
*
* DESCRIPTION
*	Layer type sim driver (transport layer) which maps C-APDU into C-TPDU for T=0
*
* PARAMETERS
*	txData:	address of the tx buffer including the command header and optional tx data
*	txSize:	size of data to be transfer including command buffer(5 bytes):(Lc+5) and
				will be updated by real transfered data count.
*	rxData:	address of the rx buffer
*	rxSize:	expect received data size not including the sw1 and sw2 and will be updataed
				by the real received data coung
*
* RETURNS
*  kal_uint16: status bytes of (sw1<<8|sw2), and 0 to indicate a physical error detected
					by the driver such as timeout.
*
* GLOBALS AFFECTED
*
*************************************************************************/
sim_status L1sim_Cmd_Layer_MT6302(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize, sim_HW_cb *hw_cb, kal_bool *isSW6263)
{
	kal_bool warn, case4, sim_card;
	kal_uint8 sw1, sw2, error, gp, rs, *tx;
   kal_uint8 sim_get_resp_sim[] = {0xa0, 0xc0, 0x00, 0x00, 0x00 }; // 0xa0: SIM, 0x00: USIM
	sim_status status, status_w = 0;
	kal_uint32 rx_len,rx_buf_len;
	// sim_protocol_app_enum p = SimCard->app_proto;
	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);
	/* [MAUI_03035883]clear status word 0x62xx 0x63xx flag */
   *isSW6263 = KAL_FALSE;

	/////dbg_print("L1sim_Cmd_Layer\r\n");
	if(rxData != NULL && *rxSize ==0)
	   rx_buf_len = 256;
	else
	   rx_buf_len = *rxSize;
	if(SimCard->cmd_case == usim_case_4)
	{
		case4 = KAL_TRUE;
		*txSize -= 1;
		*rxSize = 0;
	}
	else
		case4 = KAL_FALSE;
	tx = txData;
	status = L1sim_Cmd(tx, (kal_uint16)*txSize, rxData, (kal_uint16*)rxSize, &error, hw_cb);
	rx_len = *rxSize;
	rxData += *rxSize;
	rs = SW1_RESEND_USIM;
	//if(SIM_PROTOCOL == p)
	if(txData[0] == 0xA0)  // some usim will compatiable with SIM after received 0xa0....
	{
		gp = SW1_GET_RESP_SIM;
		sim_get_resp_sim[0] = GET_RESP_CLA_SIM;
		sim_card = KAL_TRUE;
	}
	else
	{	// USIM_PROTOCOL (0x61 and 0x6c are only for case2 and case4
		gp = SW1_GET_RESP_USIM;
		/*
			2009/3/28, from Nagra SMD, we should uses previouse CLA byte as the CLA of get response payload
			Snce CLA in usim is a run time variable depends on the channl opened in card, only protocol layer knows what is correct CLA.
		*/
		/*
			2011/2/11, CLA need to have a revise :
			for version before R7, bit5 to bit8 of CLA is defined by spec; bit1 to bit 4 is from SIM task.
			for version after R7, bit7 to bit8 of CLA is defined by spec; bit1 to bit 6 is from SIM task.
		*/
		sim_get_resp_sim[0] = DRV_ICC_makeCLA(GET_RESP_CLA_USIM, tx[0]);
		sim_card = KAL_FALSE;
	}
	warn = KAL_FALSE;
	for(;;)
	{
		if(error == KAL_TRUE){
			status = SIM_SW_STATUS_FAIL;
			//*rxSize = rx_len; //*rxSize was used in every L1sim_Cmd, not a overall result, need to update it in the last
			return status;
		}
		sw1 = status>>8;
		sw2 = status&0xff;
#if defined(SIM_DEBUG_INFO)
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC3, sim_card,warn,case4,status_w,status);
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC3, sim_get_resp_sim[0],error,*rxSize,rx_buf_len,rx_len);		
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC3, rs,gp,sw1,sw2,status);
#endif
		if((sw1 == gp) ||
		   (sim_card && (sw1 == SW1_SIM_WARN1))) //add 9exx judegement
		{	// get response  0x61
#if defined(SIM_DEBUG_INFO)
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC4, sim_card,warn,case4,status_w,status);
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC4, sim_get_resp_sim[0],error,*rxSize,rx_buf_len,rx_len);		
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC4, rs,gp,sw1,sw2,status);

         kal_sprintf(sim_dbg_str,"get response  %x \r\n", sw1);
#ifdef ATEST_DRV_ENABLE	
         dbg_print(sim_dbg_str);
#else	
         dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_SIM_DRV, sim_dbg_str);
#endif	

#endif
			if(rxData == NULL)
			{
#if defined(SIM_DEBUG_INFO)
#ifdef ATEST_DRV_ENABLE	
            dbg_print("!!! ERR  NULL rx buffer \r\n");
#else	
            dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_SIM_DRV, "!!! ERR  NULL rx buffer \r\n");
#endif	

#endif
				return status;
			}
			//add 9exx judegement
			if (sw1 == SW1_SIM_WARN1)
			{
#if defined(SIM_DEBUG_INFO	)
				kal_sprintf(sim_dbg_str,"warning status %x %x\r\n", sw1, sw2);
#ifdef ATEST_DRV_ENABLE	
            dbg_print(sim_dbg_str);
#else	
            dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_SIM_DRV, sim_dbg_str);
#endif	

#endif
				*isSW6263 = KAL_TRUE; //set 0x9exx flag
				warn = KAL_TRUE;
				status_w = status;
#if defined(SIM_DEBUG_INFO)
				DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC5, sim_card,warn,case4,status_w,status);
				DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC5, sim_get_resp_sim[0],error,*rxSize,rx_buf_len,rx_len);		
				DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC5, rs,gp,sw1,sw2,status);
#endif				
			}
			tx = sim_get_resp_sim;
			if(0 != sw2){
				if( sw2 > (rx_buf_len - rx_len))
					sw2 = (rx_buf_len - rx_len);
				*rxSize = sw2;
				tx[LEN_INDEX] = sw2;
			}
			else{
				if(256 > (rx_buf_len - rx_len)){
					*rxSize = (rx_buf_len - rx_len);
					tx[LEN_INDEX] = (rx_buf_len - rx_len);
				}
				else{
					*rxSize = 256;
					tx[LEN_INDEX] = 0;
				}
			}
			if(0 == *rxSize)/*we have to take care one condition that SIM task gave not enough space for next action*/
				return status;

			status = L1sim_Cmd(tx, LEN_OF_CMD, rxData, (kal_uint16*)rxSize, &error, hw_cb);
			if(error == KAL_TRUE){
				status = SIM_SW_STATUS_FAIL;
				//*rxSize = rx_len; //*rxSize was used in every L1sim_Cmd, not a overall result, need to update it in the last
				return status;
			}
			if(sim_card)
				break;
			else
			{
				rx_len += *rxSize;
				ASSERT(rx_len <= rx_buf_len);
				rxData += *rxSize;

			}
#if defined(SIM_DEBUG_INFO)
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC6, sim_card,warn,case4,status_w,status);
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC6, sim_get_resp_sim[0],error,*rxSize,rx_buf_len,rx_len);		
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC6, rs,gp,sw1,sw2,status);
#endif				
		}
		else if(sim_card && sw1 == SW1_GET_RESP_USIM) /*this is a work around for that, a SIM card replies USIM procedure byte*/
		{	// get response  0x61
#if defined(SIM_DEBUG_INFO)
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC7, sim_card,warn,case4,status_w,status);
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC7, sim_get_resp_sim[0],error,*rxSize,rx_buf_len,rx_len);		
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC7, rs,gp,sw1,sw2,status);
#endif	

			//dbg_print("0x6100 from SIM card");
			DRV_ICC_print(SIM_PRINT_6100_FROM_CARD, 0, 0, 0, 0, 0);

			if(rxData == NULL)
			{
#if defined(SIM_DEBUG_INFO)
#ifdef ATEST_DRV_ENABLE	
            dbg_print("!!! ERR  NULL rx buffer \r\n");
#else	
            dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_SIM_DRV, "!!! ERR  NULL rx buffer \r\n");
#endif	

#endif
				return status;
			}
			tx = sim_get_resp_sim;
			if(0 != sw2){
				if( sw2 > (rx_buf_len - rx_len))
					sw2 = (rx_buf_len - rx_len);
				*rxSize = sw2;
				tx[LEN_INDEX] = sw2;
			}
			else{
				if(256 > (rx_buf_len - rx_len)){
					*rxSize = (rx_buf_len - rx_len);
					tx[LEN_INDEX] = (rx_buf_len - rx_len);
				}
				else{
					*rxSize = 256;
					tx[LEN_INDEX] = 0;
				}
			}
			if(0 == *rxSize)/*we have to take care one condition that SIM task gave not enough space for next action*/
				return status;

			status = L1sim_Cmd(tx, LEN_OF_CMD, rxData, (kal_uint16*)rxSize, &error, hw_cb);
			if(error == KAL_TRUE){
				status = SIM_SW_STATUS_FAIL;
				//*rxSize = rx_len; //*rxSize was used in every L1sim_Cmd, not a overall result, need to update it in the last
				return status;
			}
			if(sim_card)
				break;
			else
			{
				rx_len += *rxSize;
				ASSERT(rx_len <= rx_buf_len);
				rxData += *rxSize;

			}
#if defined(SIM_DEBUG_INFO)
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC8, sim_card,warn,case4,status_w,status);
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC8, sim_get_resp_sim[0],error,*rxSize,rx_buf_len,rx_len);		
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC8, rs,gp,sw1,sw2,status);
#endif				
		}
		else if(!sim_card && sw1 == rs)
		{	// resend the previous cmd 0x6c
#if defined(SIM_DEBUG_INFO)
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC9, sim_card,warn,case4,status_w,status);
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC9, sim_get_resp_sim[0],error,*rxSize,rx_buf_len,rx_len);		
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC9, rs,gp,sw1,sw2,status);

			kal_sprintf(sim_dbg_str,"resend  command %x \r\n", sw1);
#ifdef ATEST_DRV_ENABLE	
         dbg_print(sim_dbg_str);
#else	
         dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_SIM_DRV, sim_dbg_str);
#endif	


#endif
			if(rxData == NULL)
			{
#if defined(SIM_DEBUG_INFO)
#ifdef ATEST_DRV_ENABLE	
            dbg_print("!!! ERR  NULL rx buffer \r\n");
#else	
            dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_SIM_DRV, "!!! ERR  NULL rx buffer \r\n");
#endif	

#endif
				return status;
			}
			/*there is one card that keep asking host to do get response.
			  but in this case we did not prepare enough buffer, so we should check buffer size here.
			*/
			if(sim_get_resp_sim == tx && (rx_buf_len - rx_len) < sw2){
				break;
			}

			/*we should check the valid buffer size here*/
			if((NULL != rxData) && ((rx_buf_len - rx_len) < sw2)){
				break;
			}

			tx[LEN_INDEX] = sw2;
			*rxSize = sw2;
			status = L1sim_Cmd(tx, LEN_OF_CMD, rxData, (kal_uint16*)rxSize, &error, hw_cb);
			/*
			   In FTA test, SIM may reply 0x62, 0x6c then we get status word 0x9000 while resend.
			   Since we have resend many CMD and got correct status word, if we return old warning status word,
			   we will make SIM task take wrong action. Here is we got success SW, we set warn as FALSE
			*/
			if(0x9000 == status && KAL_TRUE == warn)
				warn = KAL_FALSE;

         /* [ALPS00315325]we should add rxSize to rx_len to record total received length */
			if(error == KAL_TRUE){
				status = SIM_SW_STATUS_FAIL;
				return status;
			}
			else
			{
				rx_len += *rxSize;
				ASSERT(rx_len <= rx_buf_len);				
				rxData += *rxSize;
			}
#if defined(SIM_DEBUG_INFO)
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC10, sim_card,warn,case4,status_w,status);
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC10, sim_get_resp_sim[0],error,*rxSize,rx_buf_len,rx_len);		
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC10, rs,gp,sw1,sw2,status);
#endif				
		}
		else if(!sim_card && case4 &&
			(sw1 == SW1_WARN1 || sw1== SW1_WARN2|| (status != SIM_SW_STATUS_OK && sw1 != 0x91 && ((sw1&0xf0) == 0x90))))
		{	
			/* 
				08/07/30, it is 102 221 didn't consider the case that recursive get response condition.
				It is impossible for driver to tell whether it is 3.a or 3.b when we encounter 0x91 status word after receiving 0x61.
				But 0x91 will always be handled in SIM task layer, we do a little modification that won't classify 0x91 status word to 3.b,
				if card do goes to wrong state, this status word will be catched and handled by SIM task.
			*/
#if defined(SIM_DEBUG_INFO)
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC11, sim_card,warn,case4,status_w,status);
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC11, sim_get_resp_sim[0],error,*rxSize,rx_buf_len,rx_len);		
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC11, rs,gp,sw1,sw2,status);
#endif	

		   // warning status
#if defined(SIM_DEBUG_INFO)
			kal_sprintf(sim_dbg_str,"warning status %x %x\r\n", sw1, sw2);
#ifdef ATEST_DRV_ENABLE	
   dbg_print(sim_dbg_str);
#else	
   dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_SIM_DRV, sim_dbg_str);
#endif	 
#endif
			/* [MAUI_03035883]set status word 0x62xx 0x63xx flag */
			*isSW6263 = KAL_TRUE; //set 0x62xx 0x63xx flag
			warn = KAL_TRUE;
			status_w = status;
			tx = sim_get_resp_sim;
			tx[LEN_INDEX] = 0;
			*rxSize = 0;
			status = L1sim_Cmd(tx, LEN_OF_CMD, rxData, (kal_uint16*)rxSize, &error, hw_cb);

			if(error == KAL_TRUE){
				status = SIM_SW_STATUS_FAIL;
				//*rxSize = rx_len; //*rxSize was used in every L1sim_Cmd, not a overall result, need to update it in the last
				return status;
			}
			else
			{
				rx_len += *rxSize;
				ASSERT(rx_len <= rx_buf_len);
				rxData += *rxSize;
			}
#if defined(SIM_DEBUG_INFO)
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC12, sim_card,warn,case4,status_w,status);
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC12, sim_get_resp_sim[0],error,*rxSize,rx_buf_len,rx_len);		
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC12, rs,gp,sw1,sw2,status);
#endif			
		}
		else
		{	// command complete
#if defined(SIM_DEBUG_INFO)
			kal_sprintf(sim_dbg_str,"command complete %x \r\n", status);
#ifdef ATEST_DRV_ENABLE	
         dbg_print(sim_dbg_str);
#else	
         dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_SIM_DRV, sim_dbg_str);
#endif	
#endif
			ASSERT(rx_len <= rx_buf_len);
			*rxSize = rx_len; //*rxSize was used in every L1sim_Cmd, not a overall result, need to update it in the last
#if defined(SIM_DEBUG_INFO)
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC13, sim_card,warn,case4,status_w,status);
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC13, sim_get_resp_sim[0],error,*rxSize,rx_buf_len,rx_len);		
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC13, rs,gp,sw1,sw2,status);
#endif
			if(warn == KAL_TRUE){
				return status_w;
			}
			return status;
		}
	}
#if defined(SIM_DEBUG_INFO)
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC14, sim_card,warn,case4,status_w,status);
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC14, sim_get_resp_sim[0],error,*rxSize,rx_buf_len,rx_len);		
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC14, rs,gp,sw1,sw2,status);
#endif
	//*rxSize = rx_len; //*rxSize was used in every L1sim_Cmd, not a overall result, need to update it in the last
	return status;
}
//================================ Layer type SIM driver end ==================================
//================================For engineer mode start =======================
#ifndef DRV_SIM_ALL_SOLUTION_BUILT
void SIM1_LDO_enable(kal_bool enable)
{
#ifdef PMIC_6238_REG_API
   if (enable == KAL_TRUE)
   {
      SIM_WriteReg(DRVPDN_CON1_CLR, DRVPDN_CON1_SIM);
   }
   else
   {
      SIM_WriteReg(DRVPDN_CON1_SET, DRVPDN_CON1_SIM);
   }
   //pmu_set_vsim_force(enable);
   ASSERT(0);
#endif /* PMIC_6238_REG_API */
}

void SIM2_LDO_enable(kal_bool enable)
{
#ifdef PMIC_6238_REG_API
   if (enable == KAL_TRUE)
   {
      SIM_WriteReg(DRVPDN_CON0_CLR, DRVPDN_CON0_SIM2);
   }
   else
   {
      SIM_WriteReg(DRVPDN_CON0_SET, DRVPDN_CON0_SIM2);
   }
   //pmu_set_vsim2_en_force(enable);
   ASSERT(0);
#endif /* PMIC_6238_REG_API */
}
#endif
//================================For engineer mode end==========================
//================================SIM test code==================================
#ifdef DEVDRV_TEST
#undef DEVDRV_TEST
#endif
#ifdef DEVDRV_TEST
kal_uint8 Volt;
kal_uint8 resVolt;
AtrStruct ATRInfo;

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
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
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
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
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
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
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
	#if 1
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
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
/* under construction !*/
	#if defined(DRV_SIM_CLKSTOP_6250B_SERIES)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif   /*MT6205,MT6205B,MT6218*/
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
	#if 1
/* under construction !*/
/* under construction !*/
	#endif
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

void Sim_test(void)
{
	kal_uint8 result;
	result = sim_Reset_MT6302(SIM_30V,&resVolt,&ATRInfo);
	if (result == SIM_NO_ERROR)
	{
		//dbg_print("SIM has no Error!\r\n");
	}
	if (result == SIM_CARD_ERROR)
	{
		//dbg_print("SIM CARD has something error!\r\n");
		return;
	}

	if (result == SIM_NO_INSERT)
	{
		//dbg_print("SIM CARD no insert!\r\n");
		return;
	}
	//dbg_print("the resVolt=%x\r\n",resVolt);
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
	#endif

		#if 1
		if (vcc_check())
		{
			//dbg_print("VCC check is ok\r\n");
		//	break;
		}
		else
		{
			//dbg_print("VCC check is Failed\r\n");
		}
		#endif
		//return;
		CheckPinCMD();
		//////dbg_print("=========================================\r\n");
		#if 1
		//////dbg_print("Will be close the sim!!\r\n");
		//delay1s(50);
		closeSIMcmd();
		//SIM_Reject();
		//dbg_print("SIM is closed!!\r\n");
		#endif
}
#endif /* DEVDRV_TEST */

#endif
#endif //DRV_MULTIPLE_SIM
#endif //__MTK_TARGET__
#endif /*__SIM_DRV_MULTI_DRV_ARCH__*/

#endif //DRV_SIM_OFF

