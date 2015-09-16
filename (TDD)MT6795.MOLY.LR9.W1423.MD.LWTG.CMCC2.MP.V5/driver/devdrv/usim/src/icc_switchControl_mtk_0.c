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
 *    switchControl_mtk_0.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the SIM driver in dual SIM controller (MT6238, MT6235) solution.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef DRV_SIM_OFF
#include 	"kal_public_api.h"
//#include 	"stack_common.h"
#include 	"stack_msgs.h"
#include 	"stack_ltlcom.h"       /* Task message communiction */
//RHR#include 	"syscomp_config.h"
//RHR#include 	"task_config.h"
//RHR#include 	"stacklib.h"
#include  	"drv_comm.h"
#include    "nvram_msgid.h"

 #ifdef __SIM_DRV_MULTI_DRV_ARCH__
#include 	"reg_base.h"
#include 	"intrCtrl.h"


#include    "sim_reg_adp.h"

#include    "sim_hw_mtk.h"
#include    "sim_al.h"

#include    "sim_sw_comm.h"
#include    "drvpdn.h"
#include    "drv_hisr.h"

#if defined(LPWR_SLIM)
#include "sleepdrv_interface.h"
#endif

#ifdef __MTK_TARGET__
#if  (defined(DRV_SIM_ALL_SOLUTION_BUILT) || (defined(DRV_MULTIPLE_SIM) && defined(DRV_2_SIM_CONTROLLER)))
#if !defined(DRV_SIM_MT6208_SERIES)
//#ifdef MT6318
//#include 	"pmic6318_sw.h"
//#endif   /*MT6318*/
//RHR#include    "init.h"

#if !defined(DRV_SIM_6290_SERIES)
#include	"usim_MT6302.h"
#endif
#ifndef __MAUI_BASIC__
//RHR#include 	"nvram_user_defs.h"
#include 	"nvram_struct.h"
#endif

#include		"sim_mtk.h"

//#include "pwic.h"

//#if defined(MT6223PMU)
//#include "pmu_sw.h"
//#endif

//#include "..\..\..\ps\sim\include\sim_trc.h"


#include "sim_trc.h"


#ifdef SIM_CACHED_SUPPORT
#include "cache_sw.h"
#endif
//#ifdef DUAL_MCU_SIM_V1
//#include "pmic6326_ccci_sw.h"
//#endif

/*RHR*/
#include "drv_features.h"
//#include "kal_non_specific_general_types.h"
#include "string.h"
#include "nvram_data_items.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "stdio.h"
//#include "pmic_features.h"
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



extern kal_uint32 SIM_GetCurrentTime(void);
#define	SIM_NULLBYTE_ISSUE
#ifdef	SIM_NULLBYTE_ISSUE
/*
	magic1 is an increasing counter, increases when 1) start new command, 2)get SIM timeout, 3)get T0 end
	for case 2 and 3, it means that one of the ends of SIM commands has appeared.
*/
//kal_uint32	simMagic1_0, simMagic1_1;
/*
	magic2 is used to compared with magic1 every time GPT expires. It is set to magic1 in the start of a new command,
	if they were compared equally in GPT timer, we know that we are still waiting for SIM controller's event.
*/
//kal_uint32	simMagic2_0, simMagic2_1;
//kal_uint8		sim_nullByteIssueGPT_0, sim_nullByteIssueNullCount_0, sim_nullByteIssueGPT_1, sim_nullByteIssueNullCount_1;
//extern kal_bool GPTI_StartItem(kal_uint8 module,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter);
//extern void GPTI_StopItem(kal_uint8 module);
//extern kal_uint8 GPTI_GetHandle(kal_uint8 *handle);
extern sim_env SIM_GetCurrentEnv(kal_uint32 simInterface);
extern void sim_get_card_status(kal_uint32 logicalNum, kal_bool *isRemoved);
#endif



extern void pmic6326_ccci_lock(kal_bool lock);


/*#if defined(MT6290)
//the unit of mt6290 is 16etu
#define SIM_DEFAULT_TOUT_VALUE      0x260
#define SIM_CMD_TOUT_VALUE          0x1400   //to be updated
#else*/
//#define SIM_DEFAULT_TOUT_VALUE      0x983
//#define SIM_CMD_TOUT_VALUE          0x1400
//#endif

#define FILE_SWITCHCONTROL0 1

extern kal_uint32	hwCbArray[];

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

extern void sim_addMsg(kal_uint32 tag, kal_uint32 event, kal_uint32 data1, kal_uint32 data2);

extern usim_dcb_struct usim_cb[];
//Sim_Card *SimCard = &SimCard_cb[0];
//kal_uint8 reset_index;
//kal_uint8 PTS_data[4];

extern kal_char sim_dbg_str[];
#if defined(__USIM_DRV__)
//kal_bool sim_ATR_fail;
#endif

//static kal_bool PTS_check = KAL_TRUE;

//extern kal_bool	sim_workingTaskWaiting; //this is used in Gemini projects, but sim_sw_comm.h used this, so we declared it

static kal_uint32   	SIM_ERROR_LINE[MAX_SIM_ERROR_LINE];
static kal_uint8 	  	SIM_ERROR_LINE_INDEX;
static kal_bool   	sim_error_tag;

#if defined(DRV_SIM_6290_SERIES)
#ifdef SIM_CACHED_SUPPORT
extern kal_uint32	sim_uncachedTxBuffer0[], sim_uncachedRxBuffer0[], sim_uncachedTxBuffer1[], sim_uncachedRxBuffer1[];
#define GET_NCACHEDTX_P(p, a) {if(0==a) p=(kal_uint8 *)sim_uncachedTxBuffer0; else p=(kal_uint8 *)sim_uncachedTxBuffer1;}
#define GET_NCACHEDRX_P(p, a) {if(0==a) p=(kal_uint8 *)sim_uncachedRxBuffer0; else p=(kal_uint8 *)sim_uncachedRxBuffer1;}
#endif
#else
#pragma arm section zidata = "NONCACHEDZI",  rwdata = "NONCACHEDRW"
#ifdef SIM_CACHED_SUPPORT
extern kal_uint32	sim_uncachedTxBuffer0[], sim_uncachedRxBuffer0[], sim_uncachedTxBuffer1[], sim_uncachedRxBuffer1[];
#define GET_NCACHEDTX_P(p, a) {if(0==a) p=(kal_uint8 *)sim_uncachedTxBuffer0; else p=(kal_uint8 *)sim_uncachedTxBuffer1;}
#define GET_NCACHEDRX_P(p, a) {if(0==a) p=(kal_uint8 *)sim_uncachedRxBuffer0; else p=(kal_uint8 *)sim_uncachedRxBuffer1;}
#endif
#pragma arm section zidata, rwdata
#endif

void sim_PDNDisable_MTK(sim_HW_cb *hw_cb);
void sim_PDNEnable_MTK(sim_HW_cb *hw_cb);

/*********************************************************************************************
*we move this macro from sim_sw_comm.h to here, since we need a distinguish from dual controllers or MT6302.
*In dual controllers solution, we need to enable interrupt according to simInterface, but in MT6302 solution, we only need to enable SIM's.
**********************************************************************************************/
static void sim_assert_update_nvram(void)
{
    
    #ifndef __MAUI_BASIC__
   ilm_struct internal_ilm;
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

	//ilm_ptr = allocate_ilm(MOD_SIM);
	internal_ilm.src_mod_id = MOD_SIM;
	internal_ilm.msg_id = MSG_ID_NVRAM_WRITE_REQ;
	internal_ilm.sap_id = DRIVER_PS_SAP;
	internal_ilm.local_para_ptr = (local_para_struct *)parm_stream;
	internal_ilm.peer_buff_ptr = (peer_buff_struct *)peer_buffer_ptr;
	internal_ilm.dest_mod_id = MOD_NVRAM;
	msg_send_ext_queue(&internal_ilm);
	#endif

}

static void sim_dump_error_line(void)
{
    if (sim_error_tag != KAL_FALSE)
   {
    //kal_sprintf(sim_dbg_str,"[SIM_DRV]:I=%d,L=%d,%d,%d,%d", SIM_ERROR_LINE_INDEX, SIM_ERROR_LINE[0], SIM_ERROR_LINE[1], SIM_ERROR_LINE[2], SIM_ERROR_LINE[3]);
    //dbg_print(sim_dbg_str);
      DRV_ICC_print(SIM_PRINT_DUMP_ERROR_LINE, SIM_ERROR_LINE_INDEX, SIM_ERROR_LINE[0], SIM_ERROR_LINE[1], SIM_ERROR_LINE[2], SIM_ERROR_LINE[3]);
    sim_error_tag = KAL_FALSE;
        sim_assert_update_nvram();
   }
}

void SIM_SetEvent_MTK(Sim_Card *SIMCARD, kal_uint8 result, sim_HW_cb *hw_cb);
static void sim_gpt_timeout_handler(void *parameter)
{
    sim_HW_cb *hw_cb;
    Sim_Card * SimCard;

    hw_cb = (sim_HW_cb *)parameter;
    SimCard = GET_SIM_CB(hw_cb->simInterface);
    DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC45, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);

    SIM_SetEvent_MTK(SimCard,SIM_GPT_TIMEOUT,hw_cb);
}

void SIM_WaitEvent_MTK(Sim_Card *SIMCARD,kal_uint32 flag, kal_bool unmaskSIMIntr, sim_HW_cb *hw_cb)
{
    kal_uint32 event_group;

    //extern void sim_dump_error_line(void);
    SIMCARD->event_state = KAL_TRUE;
    SIMCARD->EvtFlag = flag;
    if(KAL_TRUE == unmaskSIMIntr){
        IRQUnmask(hw_cb->mtk_lisrCode);
    }

    DRV_ICC_GPTI_StartItem(SIMCARD->gpt_handle,
          USIM_GPT_TIMEOUT_PERIOD,
          sim_gpt_timeout_handler,
          hw_cb);
          
    if (KAL_FALSE == kal_if_hisr() && KAL_FALSE == kal_query_systemInit()) {
        kal_retrieve_eg_events(SIMCARD->event,flag,KAL_OR_CONSUME,&event_group,KAL_SUSPEND);
    } else {
        kal_retrieve_eg_events(SIMCARD->event,flag,KAL_OR_CONSUME,&event_group,0);
    }
    
    sim_dump_error_line();
    if(SIMCARD->result != SIM_GPT_TIMEOUT)
        DRV_ICC_GPTI_StopItem(SIMCARD->gpt_handle);	
}

//redefine new MACRO since there is no sim_MT6302_addMsg API in MT6235, MT6238 and I don't want to change MT6302 again
void SIM_SetEvent_MTK(Sim_Card *SIMCARD, kal_uint8 result, sim_HW_cb *hw_cb)
{
   SIMCARD->result = result;
   SIMCARD->event_state = KAL_FALSE;
	DRV_ICC_GPTI_StopItem(SIMCARD->gpt_handle);
   if(0 == SIMCARD->EvtFlag)
        kal_set_eg_events(SIMCARD->event,SIM_EVT_CMD_END,KAL_OR);
   else
        kal_set_eg_events(SIMCARD->event,SIMCARD->EvtFlag,KAL_OR);
        
   SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_IRQEN_ALLOFF);
   sim_addMsg(0x12345678, SIMCARD->EvtFlag, __LINE__, drv_get_current_time());
}

//redefine new MACRO since there is no sim_MT6302_addMsg API in MT6235, MT6238 and I don't want to change MT6302 again
void SIM_Reject_MTK(sim_HW_cb *hw_cb)
{
	Sim_Card *SimCard;

	SIM_DisAllIntr();
	SimCard = GET_SIM_CB(hw_cb->simInterface);
	if (SIM_Reg((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK))&SIM_CTRL_SIMON)
	{
		sim_addMsg(SIM_DRIVER_DEACT_SIMD, hw_cb->simInterface, 2, 0);
		SimCard->State = SIM_PWROFF;
		SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK, SIM_IRQEN_SIMOFF);
		SIM_FIFO_Flush();
		SIM_Deactive();
#ifdef __FPGA__
#else
		while(!(DRV_Reg32(hw_cb->mtk_baseAddr + SIM_ATRSTA_MTK) & 0x0001));
		if(SIM_base == hw_cb->mtk_baseAddr)
		{
			DRV_ICC_PMU_switch(0, KAL_FALSE);
		} else {
			DRV_ICC_PMU_switch(1, KAL_FALSE);
		}
#endif
	}
	else
	{
		sim_PDNEnable_MTK(hw_cb);
      
		if(SimCard->reject_set_event)
			SIM_SetEvent_MTK(SimCard,SIM_NOREADY,hw_cb);
	}
}

static void sim_assert(kal_uint32 line)
{
	 sim_error_tag = KAL_TRUE;
    SIM_ERROR_LINE[SIM_ERROR_LINE_INDEX&(MAX_SIM_ERROR_LINE - 1)] = line;
    SIM_ERROR_LINE_INDEX++;
}



static void SIM_Initialize(kal_uint8 format, kal_uint8 power, sim_HW_cb *hw_cb);



//#if ( (!defined(MT6205)) && (!defined(MT6205B)) )
#if !defined(DRV_SIM_MT6205B_SERIES)
static void SIM_L1Reset(sim_HW_cb *hw_cb, kal_bool maskSIMIntr)
{
	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);
	SIM_DisAllIntr();

#ifdef SIM_ADDDMA
   #if defined(DRV_SIM_6290_SERIES)
	SIM_DMA_STOP(SimCard->dma_config.channel);
   #else
	if(SimCard->sim_dmaport != 0)
		DMA_Stop(SimCard->sim_dmaport);
   #endif
#endif // SIM_ADDDMA

	SIM_FIFO_Flush();
	// De-activate SIM card
	if (DRV_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK) & SIM_CTRL_SIMON)
	{
		sim_addMsg(SIM_DRIVER_DEACT_SIMD, hw_cb->simInterface, 1, 0);
		SimCard->State = SIM_WaitRejectDone;
		DRV_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK, (SIM_IRQEN_SIMOFF | SIM_IRQEN_NATR));
		// DRV_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_SIMON);
		SIM_Deactive();
#ifdef __FPGA__
#else
		while(!(DRV_Reg32(hw_cb->mtk_baseAddr + SIM_ATRSTA_MTK) & 0x0001));
		if(SIM_base == hw_cb->mtk_baseAddr) 
		{
			DRV_ICC_PMU_switch(0, KAL_FALSE);
		} else {
			DRV_ICC_PMU_switch(1, KAL_FALSE);
		}

        /* Need delay of at least 10ms before next activate operation */
        kal_sleep_task(10);

		if (SimCard->State == SIM_WaitRejectDone)
		{
			//dbg_print("%d:SIM_Initialize\n\r", __LINE__);
			SIM_Initialize(SimCard->Data_format,SimCard->Power, hw_cb);
		}

#endif
		// since we have do lots actions, if its context is task, there maybe chance that hisr occur before we wait event
		// to prevent this race condition, if maskSIMIntr is true, we have to disable SIM's interrupt
		if(KAL_TRUE == maskSIMIntr) {
			IRQMask(hw_cb->mtk_lisrCode);
		}
	}
	else
	{
		// since we have do lots actions, if its context is task, there maybe chance that hisr occur before we wait event
		// to prevent this race condition, if maskSIMIntr is true, we have to disable SIM's interrupt
		if(KAL_TRUE == maskSIMIntr) {
			IRQMask(hw_cb->mtk_lisrCode);
		}
		SIM_Initialize(SimCard->Data_format,SimCard->Power, hw_cb);
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC46, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);
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

	SIM_WaitEvent_MTK(SimCard,RST_READY, KAL_TRUE, hw_cb);
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC47, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);
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
	kal_uint16 Conf;
	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);

	//tmp = *(volatile kal_uint16 *)0x80140070;
	//if (tmp != 1)
	   //while(1);
	SimCard->Data_format = format;
	SimCard->Power = power;
#if defined(SIM_DEBUG_INFO)
	kal_sprintf(sim_dbg_str, "SIM_Initialize power: %d, format: %d, TS_HSK_ENABLE: %d\n\r", power, format, SimCard->TS_HSK_ENABLE);
	DRV_ICC_print_str(sim_dbg_str);
#endif
	//Setup the SIM control module, SIM_BRR, SIM_CONF
	//Set SIMCLK = 13M/4, and BAUD RATE = default value(F=372,D=1);
	DRV_WriteReg(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK,(SIM_BRR_CLK_Div4 | SIM_BRR_BAUD_Div372));

	if (format != SIM_direct)
	{
		Conf = SIM_CONF_InDirect;
	}
	else
	{
		Conf = SIM_CONF_Direct;
	}
#if 0
#if defined(__DRV_SIM_NEED_CUSTOM_CONTROL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif (!defined(__DRV_SIM_SIMIF_CONTROL_VSIM__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (2 == SIM_DRV_MTK_INTERFACE_NUM)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#else //configure through SIMIF setting
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef DRV_SIM_VSIM2_ISSUE_76_SERIES
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //DRV_SIM_VSIM2_ISSUE_76_SERIES
/* under construction !*/
#endif   //configure through SIMIF setting
#else
	if (power == SIM_30V)
	{
		Conf |= SIM_CONF_SIMSEL;
#ifdef __FPGA__
#else
		if(SIM_base == hw_cb->mtk_baseAddr)
		{
			DRV_ICC_PMU_setVolt(0, CLASS_B_30V);
		} else
		{
			DRV_ICC_PMU_setVolt(1, CLASS_B_30V);
		}
#endif
	}
#ifdef __FPGA__
#else
	else
	{
		if(SIM_base == hw_cb->mtk_baseAddr)
		{
			DRV_ICC_PMU_setVolt(0, CLASS_C_18V);
		} else
		{
			DRV_ICC_PMU_setVolt(1, CLASS_C_18V);
		}
	}
#endif
#endif

	if(SimCard->TS_HSK_ENABLE == KAL_TRUE)
		Conf |= (SIM_CONF_TXHSK | SIM_CONF_RXHSK);

	SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK, Conf);

	if(SimCard->TS_HSK_ENABLE == KAL_TRUE)
	{
		SIM_SetRXRetry(1);
		SIM_SetTXRetry(1);
	}
	else
	{
		SIM_SetRXRetry(0);
		SIM_SetTXRetry(0);
	}

	// Set the ATRTout as 9600etu
	SIM_SetTOUT(SimCard->TOUTValue,hw_cb);

	// reset interrupts, flush rx, tx fifo
	SIM_FIFO_Flush();

#if defined(DRV_SIM_6290_SERIES)
#else
	kal_sleep_task(1);
#endif

	//Set the txfifo and rxfifo tide mark
	SIM_SetRXTIDE(1, hw_cb);

	//Read Interrupt Status
	//SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
	//Interrupt Status of MT6290 is write clear instead
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_STS_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK));

	SimCard->State = SIM_WAIT_FOR_ATR;

	//Enable Interrupt
	SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK, (SIM_IRQEN_Normal & ~SIM_IRQEN_RXERR));
	SimCard->recDataErr = KAL_FALSE;

	//activate the SIM card, and activate the SIMCLK
#ifdef __FPGA__
#else
	if(SIM_base == hw_cb->mtk_baseAddr)
	{
		DRV_ICC_PMU_switch(0, KAL_TRUE);
	} else {
		DRV_ICC_PMU_switch(1, KAL_TRUE);
	}
#endif

	sim_addMsg(SIM_DRIVER_ACT_SIMD, hw_cb->simInterface, 1, power);
	SIM_Active();
	////dbg_print("SIM ACtive\r\n");
}

static kal_bool SIM_PTSProcess(kal_uint8 *TxBuffaddr, kal_uint8 Txlength, sim_HW_cb *hw_cb)	//Bool lalasun
{
	kal_uint8 index;
	kal_uint8 tmp;
	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);

#ifdef DRV_DEBUG
    dbg_print("SIM process PTS..\r\n");
#endif
	#if defined(__USIM_DRV__)
#ifdef SIM_ACTIVATE_BY_PTS_ERROR
	if((SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK) & SIM_CTRL_SIMON ) == 0)
	{
		SimCard->sim_ATR_fail = KAL_TRUE;
		SIM_Initialize(SimCard->Data_format,SimCard->Power,hw_cb);
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC49, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);
	}
#endif
	if(SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK))
		USIM_CLR_FIFO();
	SIM_SetTOUT(SimCard->TOUTValue,hw_cb);
	#endif
#if defined(SIM_DRV_IC_USB)
	if ((SimCard->isIcUsb == KAL_TRUE) && (hw_cb->simInterface == 0x0) &&
        (FACTORY_BOOT != kal_query_boot_mode()) && SimCard->forceISO == KAL_FALSE)
	{
	   Txlength = 4;
	   *(TxBuffaddr) = 0xFF;
	   *(TxBuffaddr+1) = 0x2F;
	   *(TxBuffaddr+2) = 0xC0;
	   *(TxBuffaddr+3) = 0x10;
	}
#endif
    /* fix plug out cause this flag set as true, but let next PPS response can't reveice data at Rxtide interrupt */
    SimCard->timeout = KAL_FALSE;
    
	for (index = 0; index < Txlength; index++)
	{
		SimCard->PTS_data[index]=0;
		tmp = *(TxBuffaddr+index);
		SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK,tmp);
	}

	SimCard->State = SIM_PROCESS_PTS;

	SIM_SetRXTIDE(Txlength, hw_cb);
	SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,SIM_IRQEN_Normal);
	// fix plug out cause this flag set as true, but let next PPS response can't reveice data at Rxtide interrupt
	SimCard->timeout = KAL_FALSE;
	SIM_WaitEvent_MTK(SimCard,PTS_END, KAL_FALSE, hw_cb);

	if ((SimCard->recDataErr == KAL_TRUE)
		|| (SimCard->result == SIM_INIPTSERR))
	{
#ifndef __MAUI_BASIC__
#if !defined(__L1_STANDALONE__)
#if defined(__SIM_DRV_TRACE__)
		drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__, SimCard->recDataErr, drv_get_current_time(), *TxBuffaddr, *(TxBuffaddr+1), *(TxBuffaddr+2), *(TxBuffaddr+3));
#endif /*__SIM_DRV_TRACE__*/
#endif
#endif
		SimCard->recDataErr = KAL_FALSE;
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC50, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);

		return KAL_FALSE;
	}

	for (index = 0; index < Txlength; index++)
	{
		if (SimCard->PTS_data[index] != *(TxBuffaddr+index))
		{
#ifndef __MAUI_BASIC__
#if !defined(__L1_STANDALONE__)
#if defined(__SIM_DRV_TRACE__)
			drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__, *TxBuffaddr, *(TxBuffaddr+1), *(TxBuffaddr+2), *(TxBuffaddr+3), SimCard->PTS_data[index], index);
#endif /*__SIM_DRV_TRACE__*/
#endif
#endif
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC51, SimCard->PTS_data[0], SimCard->PTS_data[1], SimCard->PTS_data[2], SimCard->PTS_data[3], 0);
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC51, *(TxBuffaddr+0), *(TxBuffaddr+1), *(TxBuffaddr+2), *(TxBuffaddr+3), 0);

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
	kal_uint16 tmp, tmp1, Fi = 372;
	kal_uint8 ptsdata[4];
	// TOUT is an uint32 value
	kal_uint32 WWT = 0;
	kal_uint8 Dvalue = 1;
	Sim_Card *SimCard;
	usim_dcb_struct *usim_dcb;
	kal_char *p;
	kal_uint32 i;

	// fix build warning
	// WWT = WWT;
	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	SimCard = GET_SIM_CB(hw_cb->simInterface);
#if defined(__USIM_DRV__)
	if(SimCard->sim_ATR_fail)
	{
		SIM_WaitEvent_MTK(SimCard,ATR_END, KAL_FALSE, hw_cb);
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC52, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);
		if (SimCard->recDataErr == KAL_TRUE)
		{
			SimCard->recDataErr = KAL_FALSE;
			return KAL_FALSE;
		}

		DRV_ICC_print_str("[SIM_DRV]Bad Card Recovery Success.");

        /* For DHL Limitation, Log length should <= 116bytes */
		p = sim_dbg_str;
		kal_sprintf(p,"[SIM_DRV]:SIM%d ATR= ", hw_cb->simInterface);
		p += strlen(p);
		for(i = 0; i < SimCard->recDataLen; i++)
		{
			kal_sprintf(p,"%02X",SimCard->recData[i]);
			p+= 2;
		}
		DRV_ICC_print_str(sim_dbg_str);
	}
	else
	{
		kal_mem_cpy(SimCard->recData, usim_dcb->ATR_data+1, usim_dcb->ATR_index-1);
	}
#else
	SIM_WaitEvent_MTK(SimCard,ATR_END, KAL_FALSE, hw_cb);

	if(SimCard->recDataErr == KAL_TRUE)
	{
		SimCard->recDataErr = KAL_FALSE;
		return KAL_FALSE;
	}
#endif // __USIM_DRV__

	index = 1;
	if(SimCard->recData[0] & 0x00f0)
	{
		if(SimCard->recData[0] & TAMask)
		{
			tmp = SimCard->recData[index]; // TA1
			index++;
			// dbg_print("TA1=%x\r\n",tmp);
			if ((tmp == 0x0011) || (tmp == 0x0001))  //default value of Fi, Di
			{
				// Don't process ATR data!!
				SimCard->State = SIM_PROCESSCMD;
				SIMCmdInit(); // if not defined NoT0CTRL, enable T0 controller
#ifdef NoT0CTRL
				SimCard->cmdState = SIMD_CmdIdle;
#endif
				// Use 372/1 as default TOUT
				Fi = 372;
				DRV_ICC_Calc_WWT(Fi,1,10,&WWT);
				SimCard->TOUTValue = WWT>>2;
				// SimCard->TOUTValue = SIM_CMD_TOUT_VALUE;
				SIM_SetTOUT(SimCard->TOUTValue,hw_cb);
				return KAL_TRUE;
			}
			else
			{
				// Set default Fi as 512
				Fi = 512;
				switch (tmp)
				{
					case 0x0094: // F = 512,D=8
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
							// Use 372/1 as default TOUT
							Fi = 372;
							DRV_ICC_Calc_WWT(Fi,1,10,&WWT);
							SimCard->TOUTValue = WWT>>2;

                     //SimCard->TOUTValue = SIM_CMD_TOUT_VALUE;
					 SIM_SetTOUT(SimCard->TOUTValue,hw_cb);
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
					   	SIM_SetTOUT(SimCard->TOUTValue,hw_cb);
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
						SIM_SetTOUT(SimCard->TOUTValue,hw_cb);
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
#if 0
#if defined(DRV_SIM_DMA_6218B)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   /*MT6218B*/
#endif
						SIM_SetData((SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), SIM_BRR_ETUMSK, SIM_BRR_BAUD_Div32);
						SimCard->TOUT_Factor = 16;
                     /* calc 512/16 TOUT value */
                        DRV_ICC_Calc_WWT(Fi,16,10,&WWT);

                        SimCard->TOUTValue = WWT>>2;
					   	//SimCard->TOUTValue = SimCard->TOUT_Factor*SIM_CMD_TOUT_VALUE;
					    SIM_SetTOUT(SimCard->TOUTValue,hw_cb);
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
    				    SIM_SetTOUT(SimCard->TOUTValue,hw_cb);
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
    					SIM_SetTOUT(SimCard->TOUTValue,hw_cb);
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
					SIM_SetTOUT(SimCard->TOUTValue,hw_cb);
    				break;
        		}
         }
      }  /*if (SimCard->recData[0] & TAMask)*/

#if defined(DRV_SIM_6290_SERIES)
      SimCard->Fi = Fi;
#endif

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
			if(tmp != 0xff && tmp != 0x00)
			{
				return KAL_FALSE;
			}
			index++;
		}

		if(SimCard->recData[0] & TDMask)
		{
			tmp = SimCard->recData[index]; // TD1
			index++;
			// dbg_print("TD1=%x\r\n",tmp);
			if (tmp & TCMask) // TC2 is obtain
			{
				if(tmp & TAMask)
				{
					tmp1 = SimCard->recData[index];
					// dbg_print("TA2=%x\r\n",tmp1);
					index++;
				}
				if(tmp & TBMask)
				{
					tmp1 = SimCard->recData[index];
					// dbg_print("TB2=%x\r\n",tmp1);
					index++;
				}
				if(tmp & TCMask) // TC2
				{
					tmp1 = SimCard->recData[index];
					// dbg_print("TC2=%x\r\n",tmp1);
					// TOUT is an uint32 value
					// TOUT = (960*Dvalue);
					// TOUT = (TOUT*tmp1)/4; // (/4)is hw-specific
					index++;
					// SimCard->TOUTValue = TOUT+8;
					// dbg_print("TOUT=%x\r\n",TOUT);
					SimCard->TC2Present = KAL_TRUE;
					// Calc 512/Dvalue TOUT value
					DRV_ICC_Calc_WWT(Fi,Dvalue,tmp1,&WWT);
					SimCard->TOUTValue = WWT>>2;
					// SimCard->TOUTValue = SIM_CMD_TOUT_VALUE;
					SIM_SetTOUT(SimCard->TOUTValue, hw_cb);
//#ifdef SIM_TOUT_REG_V2
//		if (TOUT < 0xffffff){
//#ifdef SIM_TOUT_REG_V3
//			SIM_WriteReg32((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), TOUT/4);
//#else
//			SIM_WriteReg32((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), TOUT);
//#endif
//		}
//		else
//			SIM_WriteReg32((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), 0xffffff);
//#else
//		if (TOUT < 0xffff)
//			SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), TOUT);
//		else
//			SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), 0xffff);
//#endif
				}
			}
		} // if (SimCard->recData[0] & TDMask)
	} // if (SimCard->recData[0] & 0x00f0)
	SimCard->State = SIM_PROCESSCMD;
	SIMCmdInit();
#ifdef NoT0CTRL
	SimCard->cmdState = SIMD_CmdIdle;
#endif //NoT0CTRL

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
#endif // SIM_ADDDMA
	SIM_SetEvent_MTK(SimCard,SIM_SUCCESS, hw_cb);

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
      SIM_SetTXTIDE(0, hw_cb);
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

			SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), (SIM_CONF_TXHSK | SIM_CONF_RXHSK |SIM_CONF_TOUTEN));

			/* *(volatile kal_uint16 *)SIM_CONF |= SIM_CONF_TOUTEN; */
			SIM_SetRXTIDE(12, hw_cb);
			SIM_SetRXRetry(7);
			SIM_SetTXRetry(7);
         SimCard->recDataLen = 0;

			SIM_SetEvent_MTK(SimCard,SIM_SUCCESS, hw_cb);
			SimCard->EvtFlag = ATR_END;
			SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,SIM_IRQEN_Normal);
		}
		else
		{
			SimCard->reset_index++;	//Change format!!, don't change power
			if (SimCard->reset_index>1)
			{
				SimCard->reset_index = 0;
				SIM_SetEvent_MTK(SimCard,SIM_CARDERR,hw_cb);
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
         		sim_addMsg(0x20080213, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK));

#ifdef SIM_REMOVE_ATR_ASSERT
			SIM_StartFaltalReport(hw_cb);
			SIM_SetEvent_MTK(SimCard, SIM_CMDRECERR,hw_cb);

#if !defined(__L1_STANDALONE__)
#if defined(__SIM_DRV_TRACE__)
			drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__, 0 , SimCard->State, SimCard->result, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), 0, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK));
#endif /*__SIM_DRV_TRACE__*/
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
               SIM_SetEvent_MTK(SimCard,SIM_SUCCESS,hw_cb);
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
		    kal_uint8 ch;

		    ch = (kal_uint8)SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK);

		    if (index < PPS_LEN) {
		        /* to avoid overflow other members of SimCard_cb */
			    SimCard->PTS_data[index] = ch;
			}
			    
			index++;

			if (SIM_FIFO_GetLev()==0)
			{
			    if (index > PPS_LEN) {
				    /* received too many data when processing PTS */
				    sim_addMsg(0x20140415, index, SimCard->recDataErr, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK));
				}
				
			    if (SimCard->recDataErr == KAL_FALSE) {
				    SIM_SetEvent_MTK(SimCard,SIM_SUCCESS,hw_cb);
				} else {
                    /* SetEvent should be called when handling TOUT */
				}

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
         SIM_SetEvent_MTK(SimCard,SIM_SUCCESS,hw_cb);
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


void SIM_HISR_Multiple(void)
{
	kal_uint16 sim_int;
	Sim_Card *SimCard;
	sim_HW_cb *hw_cb;

	/*logical SIM 1 not exactly work on physical SIM1 interface, we only know interrrupt comes from SIM1, have to find its logical */
	hw_cb = (sim_HW_cb *) (hwCbArray[sim_get_logical_from_SIMIF(0)]);

	SimCard = GET_SIM_CB(hw_cb->simInterface);
	sim_int = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
	SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK,sim_int);

	kal_sprintf(sim_dbg_str, "[DRV] SIM HISR int: %x\r\n", sim_int);
	DRV_ICC_print_str(sim_dbg_str);

#ifndef __MAUI_BASIC__
#ifdef __OLD_PDN_ARCH__
#if !defined(__L1_STANDALONE__)
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__, sim_int, drv_get_current_time(), SimCard->State, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK), SIM_Reg(DRVPDN_CON1));
#endif
#else
/*use PDN_STATUS(dev, s, t) to fullfill my dbg usage, add the code later*/
#endif
#endif

	sim_addMsg(SIM_INT_SIM, 0, sim_int, SimCard->State);

	if(SimCard->previous_state == SIM_WAIT_FOR_ATR || SimCard->previous_state == SIM_PROCESS_ATR)
	{
		SimCard->previous_state = SimCard->State;
		SimCard->atr_count++;
		if(SimCard->atr_count > 40)
		{
			SIM_DisAllIntr();
			SIM_Reject_MTK(hw_cb);
			SimCard->atr_count = 0;
			IRQClearInt(hw_cb->mtk_lisrCode);
#if !defined(__UNIFIED_ISR_LEVEL__)
			IRQUnmask(hw_cb->mtk_lisrCode);
#endif
			DRV_ICC_print_str("[SIM DRV]SIM1 card send too many ATR data\n\r");
			return;
		}
	} else
	{
		SimCard->previous_state = SimCard->State;
		SimCard->atr_count = 0;
	}

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
	      SIM_Reject_MTK(hw_cb);
	      SIM_ASSERT(0);
	      //SIM_SetEvent_MTK(SimCard,SIM_INIPTSERR,hw_cb);
	   }
	}

	if ( sim_int & SIM_STS_TX)
	{
	   //dbg_print("[DRV] SIM_STS_TX\r\n");
	   //SIM_DisIntr(SIM_IRQEN_TX);
#ifdef  SIM_ADDDMA
	   ////dbg_print("something error\r\n");
#else /*SIM_ADDDMA*/
      SIM_Txhandler(hw_cb);  /* Only used for no DMA */
#endif /*SIM_ADDDMA*/
	}

	if ( sim_int & SIM_STS_TOUT)
	{
	   DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC70, 0x8, SimCard->State, drv_get_current_time(), SimCard->cmdState, hw_cb->simInterface);
	   ////dbg_print("703SIM_STS_TOUT\r\n");
	   if(SimCard->State == SIM_WAIT_FOR_ATR)
	   {
	      DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC54, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);
	      SIM_SetEvent_MTK(SimCard,SIM_INIPTSERR,hw_cb);
	      SIM_ASSERT(0);
	   }

	   if(SimCard->State == SIM_PROCESS_ATR)
	   {
	      SIM_Rxhandler(sim_int, hw_cb);
	   }

	   if( SimCard->State == SIM_PROCESS_PTS)
	   {
	 DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC55, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);
         SIM_SetEvent_MTK(SimCard,SIM_INIPTSERR,hw_cb);
         SIM_ASSERT(0);
	   }

	   if (SimCard->State == SIM_PROCESSCMD)
	   {
	      if(SimCard->recDataErr == KAL_TRUE)
	      {
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC56, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC56, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_RETRY_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_TIDE_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK), 0xff);
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC56, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STATUS_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW2_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->recDataErr);		
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC56, SIM_Reg(SimCard->dma_config.ADDR_HDMA_HPRGA0Rx), SIM_Reg(SimCard->dma_config.ADDR_HDMA_HDCTRRx), SIM_Reg(SimCard->dma_config.ADDR_HDMA_HDC0Rx), 0, 0);
	         SIM_SetEvent_MTK(SimCard,SIM_CMDRECERR,hw_cb);
	         SIM_ASSERT(0);
	      }
	      else
	      {
	         switch(SimCard->cmdState)
	         {
	            case SIM_ProcessClk:
	               //dbg_print("[DRV] SIM_ProcessClk\r\n");
			SimCard->EvtFlag = CLK_PROC;
	               SIM_SetEvent_MTK(SimCard,SIM_CLKPROC,hw_cb);
	               break;

	            case SIM_StopClk:
	               //dbg_print("[DRV] SIM_StopClk\r\n");
	               SIM_Idle_MTK(SimCard->clkStopLevel, hw_cb);
#ifndef __DRV_SIM_REG_ON_PDN_V2__
	               /*controller's clock must now stopped, verify it*/
			if((SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK) & 0x2) != 0x2)
				ASSERT(0);
#endif
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
                           SIM_SetEvent_MTK(SimCard,SIM_SUCCESS,hw_cb);
                           Error = KAL_FALSE;
                        }
                        else
                        {
                           break;
                        }
	                  }
	                  if (Error)
	                  {
      	               SIM_SetEvent_MTK(SimCard,SIM_CMDTOUT,hw_cb);
      	               SIM_ASSERT(0);
	                  }
	               }
	               else
	               {
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC70, 0x9, 1, drv_get_current_time(), 0, hw_cb->simInterface);
   	               SIM_SetEvent_MTK(SimCard,SIM_CMDTOUT,hw_cb);
   	               SIM_ASSERT(0);
	               }
	               #else /*NoT0CTRL*/
	               #ifdef SIM_NULLBYTE_ISSUE
				SimCard->simMagic1 ++;
			#endif
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC70, 0x9, 0, drv_get_current_time(), 0, hw_cb->simInterface);
	               SIM_ASSERT(0);
	               SimCard->timeout = KAL_TRUE;
	               SIM_SetEvent_MTK(SimCard,SIM_CMDTOUT,hw_cb);
	               #endif   /*NoT0CTRL*/
	               break;
	         }/*endof switch*/
	      }
	   }/*if (SimCard->State == SIM_PROCESSCMD)*/

	   if (SimCard->State == SIM_SERIOUSERR)
	   {
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC57, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);
         SIM_SetEvent_MTK(SimCard,SIM_CMDTXERR,hw_cb);
         SIM_ASSERT(0);
	   }
	   SIM_DisAllIntr();
	}

   if ( sim_int & SIM_STS_OV)
   {
#if defined(SIM_DEBUG_INFO)
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC56, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_RETRY_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_TIDE_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK), 0xff);
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC56, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STATUS_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW2_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->recDataErr);		
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC56, SIM_Reg(SimCard->dma_config.ADDR_HDMA_HPRGA0Rx), SIM_Reg(SimCard->dma_config.ADDR_HDMA_HDCTRRx), SIM_Reg(SimCard->dma_config.ADDR_HDMA_HDC0Rx), 0, 0);
#endif
      //dbg_print("[DRV] SIM_STS_OV\r\n");
      SimCard->recDataErr = KAL_TRUE;
      if (SimCard->State == SIM_PROCESSCMD)
      {
			SIM_ASSERT(0);
	   }
   }

	if ( sim_int & SIM_STS_RXERR)
	{
	   //dbg_print("[DRV] SIM_STS_RXERR\r\n");
	   SimCard->recDataErr = KAL_TRUE;
	   SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,SIM_IRQEN_TOUT);
      if (SimCard->State == SIM_PROCESSCMD)
      {
			SIM_ASSERT(0);
	   }
	}

    if (sim_int & SIM_STS_RX)
	{
	   //dbg_print("[DRV] SIM_STS_RX\r\n");
	   if(SimCard->timeout != KAL_TRUE)
            SIM_Rxhandler(sim_int, hw_cb);
	}

   if ( (sim_int &  SIM_IRQEN_T0END)
       && (SimCard->State == SIM_PROCESSCMD))
	{
	#ifdef SIM_NULLBYTE_ISSUE
		SimCard->simMagic1 ++;
	#endif
	  //dbg_print("[DRV] SIM_IRQEN_T0END\r\n");
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
            SIM_Reject_MTK(hw_cb);
         }
	   }
	   else
	   {
	      SIM_Reject_MTK(hw_cb);
	   }
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC69, SimCard->SIM_ENV, SimCard->Power, SimCard->Data_format, 0, 0x1014);
   }

	if ( sim_int & SIM_STS_SIMOFF)
	{

#ifdef DUAL_MCU_SIM_V1
#if !defined(__L1_STANDALONE__)
#if defined(__SIM_DRV_TRACE__)
	   drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__, 0, 0, 0, 0, 0, drv_get_current_time());
#endif /*__SIM_DRV_TRACE__*/
#ifdef __FPGA__
#else
       DRV_ICC_PMU_switch(0, KAL_FALSE);
#endif
#endif
#endif /*DUAL_MCU_SIM_V1*/


	   //dbg_print("[DRV] SIM_STS_SIMOFF\r\n");
		SIM_DisAllIntr();

      if (SimCard->State == SIM_PWROFF)
      {
         sim_PDNEnable_MTK(hw_cb);
         if (SimCard->reject_set_event)
         {
            SIM_SetEvent_MTK(SimCard,SIM_NOREADY,hw_cb);
            //mask by mtk04122
            //SIM_ASSERT(0);
         }
      }
      else
      {
//#if ( (!defined(MT6205)) && (!defined(MT6205B)) )
#if !defined(DRV_SIM_MT6205B_SERIES)
         if (SimCard->State == SIM_WaitRejectDone)
         {
#ifdef __FPGA__
            SIM_Initialize(SimCard->Data_format,SimCard->Power, hw_cb);
#endif
	    DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC58, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);
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
#if !defined(__UNIFIED_ISR_LEVEL__)
	IRQUnmask(hw_cb->mtk_lisrCode);
#endif
}


void SIM_HISR2_Multiple(void)
{
	kal_uint16 	sim_int;
	Sim_Card *SimCard;
	sim_HW_cb *hw_cb;

	/*logical SIM 1 not exactly work on physical SIM1 interface, we only know interrrupt comes from SIM1, have to find its logical */
	hw_cb = (sim_HW_cb *)(hwCbArray[sim_get_logical_from_SIMIF(1)]);
	SimCard = GET_SIM_CB(hw_cb->simInterface);
	sim_int = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
    SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK,sim_int);
	kal_sprintf(sim_dbg_str, "[DRV] SIM2 HISR int: %x\r\n", sim_int);
	DRV_ICC_print_str(sim_dbg_str);

#ifndef __MAUI_BASIC__
#ifdef __OLD_PDN_ARCH__
#if !defined(__L1_STANDALONE__)
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__, sim_int , drv_get_current_time(), SimCard->State, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK),	SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK), SIM_Reg(DRVPDN_CON0));
#endif
#else
/*use PDN_STATUS(dev, s, t) to fullfill my dbg usage, add the code later*/
#endif
#endif


	sim_addMsg(SIM_INT_SIM, 1, sim_int, SimCard->State);
	////dbg_print("sim_int=%x\r\n",sim_int);

	if(SimCard->previous_state == SIM_WAIT_FOR_ATR || SimCard->previous_state == SIM_PROCESS_ATR)
	{
		SimCard->previous_state = SimCard->State;
		SimCard->atr_count++;
		if(SimCard->atr_count > 40)
		{
			SIM_DisAllIntr();
			SIM_Reject_MTK(hw_cb);
			SimCard->atr_count = 0;
			IRQClearInt(hw_cb->mtk_lisrCode);
#if !defined(__UNIFIED_ISR_LEVEL__)
			IRQUnmask(hw_cb->mtk_lisrCode);
#endif
			DRV_ICC_print_str("[SIM DRV]SIM2 card send too many ATR data\n\r");
			return;
		}
	} else
	{
		SimCard->previous_state = SimCard->State;
		SimCard->atr_count = 0;
	}

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
	      SIM_Reject_MTK(hw_cb);
	      SIM_ASSERT(0);
	      //SIM_SetEvent_MTK(SimCard,SIM_INIPTSERR,hw_cb);
	   }
	}

	if ( sim_int & SIM_STS_TX)
	{
	   ////dbg_print("SIM_STS_TX\r\n");
	   //SIM_DisIntr(SIM_IRQEN_TX);
#ifdef  SIM_ADDDMA
	   ////dbg_print("something error\r\n");
#else /*SIM_ADDDMA*/
      SIM_Txhandler(hw_cb);  /* Only used for no DMA */
#endif /*SIM_ADDDMA*/
	}

	if ( sim_int & SIM_STS_TOUT)
	{
	   DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC70, 0x8, SimCard->State, drv_get_current_time(), 0, hw_cb->simInterface);
	   //dbg_print("703SIM_STS_TOUT\r\n");
	   if(SimCard->State == SIM_WAIT_FOR_ATR)
	   {
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC54, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);
	      SIM_SetEvent_MTK(SimCard,SIM_INIPTSERR,hw_cb);
	      SIM_ASSERT(0);
	   }

	   if(SimCard->State == SIM_PROCESS_ATR)
	   {
	      SIM_Rxhandler(sim_int, hw_cb);
	   }

	   if( SimCard->State == SIM_PROCESS_PTS)
	   {
	 DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC55, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);
         SIM_SetEvent_MTK(SimCard,SIM_INIPTSERR,hw_cb);
         SIM_ASSERT(0);
	   }

	   if (SimCard->State == SIM_PROCESSCMD)
	   {
	      if(SimCard->recDataErr == KAL_TRUE)
	      {
		 DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC56, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC56, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_RETRY_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_TIDE_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK), 0xff);
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC56, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STATUS_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW2_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->recDataErr);		
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC56, SIM_Reg(SimCard->dma_config.ADDR_HDMA_HPRGA0Rx), SIM_Reg(SimCard->dma_config.ADDR_HDMA_HDCTRRx), SIM_Reg(SimCard->dma_config.ADDR_HDMA_HDC0Rx), 0, 0);
	         SIM_SetEvent_MTK(SimCard,SIM_CMDRECERR,hw_cb);
	         SIM_ASSERT(0);
	      }
	      else
	      {
	         switch(SimCard->cmdState)
	         {
	            case SIM_ProcessClk:
	               ////dbg_print("SIM_ProcessClk\r\n");
			SimCard->EvtFlag = CLK_PROC;
	               SIM_SetEvent_MTK(SimCard,SIM_CLKPROC,hw_cb);
	               break;

	            case SIM_StopClk:
	               ////dbg_print("SIM_StopClk\r\n");
	               SIM_Idle_MTK(SimCard->clkStopLevel, hw_cb);
#ifndef __DRV_SIM_REG_ON_PDN_V2__
	               /*controller's clock must now stopped, verify it*/
			if((SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK) & 0x2) != 0x2)
				ASSERT(0);
#endif
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
                           SIM_SetEvent_MTK(SimCard,SIM_SUCCESS,hw_cb);
                           Error = KAL_FALSE;
                        }
                        else
                        {
                           break;
                        }
	                  }
	                  if (Error)
	                  {
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC70, 0x9, 1, drv_get_current_time(), 0, hw_cb->simInterface);
      	               SIM_SetEvent_MTK(SimCard,SIM_CMDTOUT,hw_cb);
      	               SIM_ASSERT(0);
	                  }
	               }
	               else
	               {
   	               SIM_SetEvent_MTK(SimCard,SIM_CMDTOUT,hw_cb);
   	               SIM_ASSERT(0);
	               }
	               #else /*NoT0CTRL*/
	               #ifdef SIM_NULLBYTE_ISSUE
				SimCard->simMagic1 ++;
			#endif
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC70, 0x9, 0, drv_get_current_time(), 0, hw_cb->simInterface);
	               SIM_ASSERT(0);
	               SimCard->timeout = KAL_TRUE;
	               SIM_SetEvent_MTK(SimCard,SIM_CMDTOUT,hw_cb);
	               #endif   /*NoT0CTRL*/
	               break;
	         }/*endof switch*/
	      }
	   }/*if (SimCard->State == SIM_PROCESSCMD)*/

	   if (SimCard->State == SIM_SERIOUSERR)
	   {
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC57, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);
         SIM_SetEvent_MTK(SimCard,SIM_CMDTXERR,hw_cb);
         SIM_ASSERT(0);
	   }
	   SIM_DisAllIntr();
	}

	if (sim_int & SIM_STS_RX)
	{
	   //dbg_print("SIM_STS_RX\r\n");
	   if(SimCard->timeout != KAL_TRUE)
      SIM_Rxhandler(sim_int, hw_cb);
	}

   if ( sim_int & SIM_STS_OV)
   {
#if defined(SIM_DEBUG_INFO)
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC56, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_RETRY_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_TIDE_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK), 0xff);
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC56, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STATUS_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW2_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->recDataErr);		
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC56, SIM_Reg(SimCard->dma_config.ADDR_HDMA_HPRGA0Rx), SIM_Reg(SimCard->dma_config.ADDR_HDMA_HDCTRRx), SIM_Reg(SimCard->dma_config.ADDR_HDMA_HDC0Rx), 0, 0);
#endif
      //dbg_print("SIM_STS_OV\r\n");
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
            SIM_Reject_MTK(hw_cb);
         }
	   }
	   else
	   {
	      SIM_Reject_MTK(hw_cb);
	   }
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC69, SimCard->SIM_ENV, SimCard->Power, SimCard->Data_format, 0, 0x1014);
   }

	if ( sim_int & SIM_STS_SIMOFF)
	{
#ifdef DUAL_MCU_SIM_V1
#if !defined(__L1_STANDALONE__)
	   drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__, 0, 0, 0, 0, 0, drv_get_current_time());
#endif
  #ifdef __FPGA__
  #else
	   DRV_ICC_PMU_switch(1, KAL_FALSE);
  #endif
#endif /*DUAL_MCU_SIM_V1*/

	   ////dbg_print("SIM_STS_SIMOFF\r\n");
		SIM_DisAllIntr();

      if (SimCard->State == SIM_PWROFF)
      {
         sim_PDNEnable_MTK(hw_cb);
         if (SimCard->reject_set_event)
         {
            SIM_SetEvent_MTK(SimCard,SIM_NOREADY,hw_cb);
            SIM_ASSERT(0);
         }
      }
      else
      {
//#if ( (!defined(MT6205)) && (!defined(MT6205B)) )
#if !defined(DRV_SIM_MT6205B_SERIES)
         if (SimCard->State == SIM_WaitRejectDone)
         {
#ifdef __FPGA__
            SIM_Initialize(SimCard->Data_format,SimCard->Power, hw_cb);
#endif
	    DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC58, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);
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
#if !defined(__UNIFIED_ISR_LEVEL__)
	IRQUnmask(hw_cb->mtk_lisrCode);
#endif
}


void SIM_LISR_Multiple(kal_uint32 vector)
//void SIM_LISR_Multiple(void)
{
	sim_HW_cb *hw_cb;

	hw_cb = (sim_HW_cb *)(hwCbArray[sim_get_logical_from_SIMIF(0)]);
   IRQMask(hw_cb->mtk_lisrCode);
   drv_active_hisr(DRV_SIM_HISR_ID);
}

void SIM_LISR2_Multiple(kal_uint32 vector)
//void SIM_LISR2_Multiple(void)
{
	sim_HW_cb *hw_cb;

	hw_cb = (sim_HW_cb *)(hwCbArray[sim_get_logical_from_SIMIF(1)]);
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
void sim_PowerOff_MTK(sim_HW_cb *hw_cb)  //Validate
{
	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);

	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC65, 0, 0, drv_get_current_time(), 0, hw_cb->simInterface);

   SIM_DisAllIntr();
#if defined(SIM_DRV_IC_USB)
   if ((SimCard->isIcUsb == KAL_TRUE) && (hw_cb->simInterface == 0x0) &&
        (FACTORY_BOOT != kal_query_boot_mode()))
   {
        SIM_icusb_disableSession(hw_cb);
        sim_addMsg(0xE014, hw_cb->simInterface, 0, 0);     	
   }
#endif
   sim_PDNDisable_MTK(hw_cb);
   if(SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK) | SIM_CTRL_HALT)
   	SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);
   SimCard->reject_set_event = KAL_FALSE;
   SIM_Reject_MTK(hw_cb);

	/*turn off LDO*/
#ifndef __TBD__
#if !defined(__DRV_SIM_SIMIF_CONTROL_VSIM__)
   kal_sleep_task(50);
#ifdef __FPGA__
#else
   if(0 == sim_get_hwCtrl_from_logicalNum(hw_cb->simInterface)){
      DRV_ICC_PMU_switch(0, KAL_FALSE);
   }
   else{
      DRV_ICC_PMU_switch(1, KAL_FALSE);
   }
   kal_sleep_task(10);
#endif
#endif
#endif
#if defined(SIM_DRV_IC_USB)
	if((SimCard->isIcUsb == KAL_TRUE) && (hw_cb->simInterface == 0x0) && (FACTORY_BOOT != kal_query_boot_mode()))
	{
		//tell USB to reset MAC & PHY
		SIM_icusb_disconnectDone(hw_cb); 
		sim_addMsg(0xE015, hw_cb->simInterface, 0, 0);   
		SIM_icusb_deinit(hw_cb);
	}

#endif

   //DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM);
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
	kal_uint8 index;
  	Sim_Card *SimCard;
  	usim_dcb_struct	*usim_dcb;
   kal_bool  returnBool;

	usim_dcb = GET_USIM_CB(hw_cb->simInterface);
	SimCard = GET_SIM_CB(hw_cb->simInterface);

   kal_sleep_task(2);
   SIM_DisAllIntr();
   SimCard->sim_card_speed = sim_card_normal_speed;
   SimCard->reject_set_event = KAL_TRUE;
   sim_PDNDisable_MTK(hw_cb);


/*
	SIM_DEFAULT_TOUT_VALUE is 0x260 in ../inc/sim_drv_HW_def_MTK.h
	It has been divide by 16
*/
#if defined(DRV_SIM_6290_SERIES)
   SimCard->TOUTValue = SIM_DEFAULT_TOUT_VALUE << 2;
#else
   SimCard->TOUTValue = SIM_DEFAULT_TOUT_VALUE;
#endif

   SimCard->TOUT_Factor=1;
   SimCard->clkStop = KAL_FALSE;
	SimCard->Speed = Speed372;
	SimCard->State = SIM_WAIT_FOR_ATR;
	SimCard->Power = resetVolt;
	SimCard->initialPower = resetVolt;
	SimCard->power_class = UNKNOWN_POWER_CLASS;
	SimCard->TC2Present = KAL_FALSE;
	SimCard->timeout = KAL_FALSE;
//	SimCard->gpt_handle = usim_dcb->gpt_handle;
	SimCard->previous_state = 0;
	SimCard->atr_count = 0;
#if defined(SIM_DRV_IC_USB)
	SimCard->isIcUsb = usim_dcb->isIcUsb;
	SimCard->TB15 = usim_dcb->TB15;
	SimCard->isIcUsbRecPPS = usim_dcb->isIcUsbRecPPS;
	SimCard->uart_sim_ccci_handle = usim_dcb->uart_sim_ccci_handle;
#endif
#if defined(__SIM_HOT_SWAP_POLL_TIMER__) && defined(__SIM_HOT_SWAP_SUPPORT__)
	SimCard->poll_sim_2s = KAL_FALSE;
#endif
	#if defined(__USIM_DRV__)
	{
        //dbg_print("SIM does not reset againg.....\r\n");
		SimCard->Data_format = usim_dcb->dir;
		SimCard->result = SIM_SUCCESS;
		SimCard->sim_ATR_fail = KAL_FALSE;
        SimCard->power_class = usim_dcb->power_class;
        /*mtk04122: Reset failed due to TS_HSK_ENABLE is enabled,
                    we need to do activation for following process*/
        /*if(SimCard->TS_HSK_ENABLE == KAL_FALSE)
        {
            returnBool = SIM_ResetNoATR(SimCard->Power, hw_cb);
		    if(KAL_TRUE != returnBool){
			    DRV_ICC_print(SIM_PRINT_RESET_NOATR_FAIL, SimCard->Power,0, 0, 0, 0);
			    return SIM_CARD_ERROR;
		    }
            SIM_WaitEvent_MTK(SimCard,ATR_END, KAL_FALSE, hw_cb);
		}*/
	}
	#else
    //dbg_print("SIM reset againg.....\r\n");
	SimCard->Data_format = SIM_direct;
	reset_index = 0;
	SimCard->result = SIM_NOREADY;
	SIM_L1Reset();

	SIM_WaitEvent_MTK(SimCard,RST_READY, KAL_FALSE, hw_cb);

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
		SIM_WaitEvent_MTK(SimCard,RST_READY, KAL_FALSE, hw_cb);
	}

	#endif  /*__USIM_DRV__*/
	if (SimCard->result == SIM_SUCCESS)
	{
		index=0;
		while(1)
		{
			if (!SIM_ProcessATRData(hw_cb))
			{
				DRV_ICC_print_str("Bad card/Hw contact issue, cause PTS error. Enter recovery process\n\r");
				index++;
				//if (index == 3)
				if (index == 2)
				{
					SimCard->PTS_check = KAL_FALSE;
					DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC59, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);
				}
				//else if (index > 3)
				else if (index > 2 || KAL_TRUE == SimCard->keepAtrFatal)
				{
				   	SimCard->PTS_check = KAL_FALSE;
					DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC60, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);
					sim_PowerOff_MTK(hw_cb);
					return SIM_CARD_ERROR;
				}
#ifdef DRV_SIM_RETRY_18V_ONLY_USIM_ON_PTS_ERROR
				else if ((SimCard->Power == SIM_18V) && SimCard->power_class == CLASS_C_18V)
				{			  
					DRV_ICC_print_str("RETRY_18V_ONLY_USIM\n\r");
					SimCard->PTS_check = KAL_TRUE;
					SimCard->SIM_ENV = ME_18V_ONLY;
					DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC61, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);
					//index = 0;
				}
#endif                
#ifdef DRV_SIM_RETRY_3V_ON_PTS_ERROR
				/* For [MAUI_01321659] begin, retry 3V when we fail in 1.8V*/
				else if ((SimCard->Power == SIM_18V) && (SIM_GetCurrentEnv(hw_cb->simInterface) == ME_18V_30V))
				{
					DRV_ICC_print_str("RETRY_3V_ON_PTS_ERROR\n\r");
					SimCard->Power = SIM_30V;
					SimCard->PTS_check = KAL_TRUE;
					//index = 0;
				}/* For [MAUI_01321659] end */
#endif
				#if defined(__USIM_DRV__)
				SimCard->sim_ATR_fail = KAL_TRUE;
				#endif

				/*since we may power off the card and set SIM pdn, we have to disable PDN here, or we may trapped in wait event*/
				sim_PDNDisable_MTK(hw_cb);

#ifdef DRV_SIM_RETRY_VOLTAGE_ON_PPS_TIMEOUT
				if(index==2)
				{
			  		if(SimCard->SIM_ENV==ME_18V_30V)
			    		{
          					if (SimCard->Power == SIM_30V)
		        			{
							SimCard->Power = SIM_18V;
					  	}
						else
					 	{
							SimCard->Power = SIM_30V;
					  	}
					}
		   		}
#endif

				returnBool = SIM_ResetNoATR(SimCard->Power, hw_cb);
				if(KAL_TRUE != returnBool){
					DRV_ICC_print(SIM_PRINT_RESET_NOATR_FAIL, SimCard->Power, index, 0, 0, 0);
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
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC62, SimCard->EvtFlag, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SimCard->result, 0);
	   sim_PowerOff_MTK(hw_cb);
		return SIM_CARD_ERROR;
	}
}

kal_uint8 sim_Reset_MTK(kal_uint8 resetVolt, kal_uint8 *resultVolt,AtrStruct *Info, sim_HW_cb *hw_cb)	//Validate
{
	kal_uint8 result;
	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);

	SimCard->TS_HSK_ENABLE = KAL_TRUE;
	result = L1sim_Core_Reset(resetVolt,resultVolt,Info, hw_cb);
	if (result != SIM_NO_ERROR && KAL_FALSE == SimCard->keepAtrFatal)
  	{
		//dbg_print("[SIM]: SIM reset fail with TS_HSK_ENABLE");
		DRV_ICC_print(SIM_PRINT_RESET_FAIL_WITH_TS_HSK_ENABLE, 0, 0, 0, 0, 0);
		SimCard->TS_HSK_ENABLE = KAL_FALSE;
		result = L1sim_Core_Reset(resetVolt,resultVolt,Info, hw_cb);
	}
	if(result == SIM_NO_ERROR)
	{
		//kal_sprintf(sim_dbg_str,"[SIM]:SIM RESET OK, power:%d ,speed:%d",SimCard->Power,SimCard->Speed);
		//dbg_print(sim_dbg_str);
		DRV_ICC_print(SIM_PRINT_RESET_OK_POWER_SPEED, SimCard->Power, SimCard->Speed, 0, 0, 0);
	}
	else
	{
		//kal_sprintf(sim_dbg_str,"[SIM]:SIM RESET FAIL, result:%d", result);
		//dbg_print(sim_dbg_str);
		DRV_ICC_print(SIM_PRINT_RESET_FAIL_RESULT, result, 0, 0, 0, 0);
	}
	return result;
}



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
void L1sim_Configure_MTK(kal_uint8 clockMode, sim_HW_cb *hw_cb)	//Validate
{
	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);

	switch (clockMode)
	{
		case CLOCK_STOP_AT_HIGH:
		   // #if ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6218)) )
		   #if defined(DRV_SIM_CLKSTOP_6250B_SERIES)
		   SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_HALTEN);
		   #endif   /*MT6205,MT6205B,MT6218*/
			SimCard->clkStop = KAL_TRUE;
			SimCard->clkStopLevel = KAL_TRUE;
			break;

		case CLOCK_STOP_AT_LOW:
		   //#if ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6218)) )
		   #if defined(DRV_SIM_CLKSTOP_6250B_SERIES)
		   SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_HALTEN);
		   #endif   /*MT6205,MT6205B,MT6218*/
			SimCard->clkStop = KAL_TRUE;
			SimCard->clkStopLevel = KAL_FALSE;
			break;

		case CLOCK_STOP_NOT_ALLOW:
		   //#if ( (defined(MT6205)) || (defined(MT6205B)) || (defined(MT6218)) )
		   #if defined(DRV_SIM_CLKSTOP_6250B_SERIES)
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
#endif

void sim_nullByteIssueGptTimeout_0(void *parameter)
{
	Sim_Card *SimCard;
	sim_HW_cb *hw_cb;

	hw_cb = (sim_HW_cb *)parameter;
	SimCard = GET_SIM_CB(hw_cb->simInterface);

	/* [ALPS00600930]we should stop wait event gpt timer;otherwise it will cause null byte process fail */
	DRV_ICC_GPTI_StopItem(SimCard->gpt_handle);
#ifdef __SIM_HOT_SWAP_SUPPORT__
	sim_get_card_status(hw_cb->simInterface, &hw_cb->IsCardRemove);

	/* [MAUI_03009364]If card is removed, we don't need to wait null bytes */
	if(hw_cb->IsCardRemove == KAL_TRUE)
	{
		SimCard->sim_nullByteIssueNullCount = 0;
		SimCard->sim_nullByteIssuenonNullCount = 0;
		DRV_ICC_GPTI_StopItem(SimCard->sim_nullByteIssueGPT);
		/*must change magic after we confirm GPT won't trigger, since this code run in task context, we can run this code means GPT won't trigger*/
		SimCard->simMagic1 ++;
		SimCard->simMagic2 = SimCard->simMagic1;
		return;
	}
#endif
	if(SimCard->simMagic1 != SimCard->simMagic2){ /*cmd finished before GPT timeout*/
		kal_sprintf(sim_dbg_str, "sim_nullByteIssueGptTimeout_0:cmd finished before GPT timeout");
    		DRV_ICC_print_str(sim_dbg_str);
	}
	else{/*the GPT timer is used to find out these cases, it means we still haven't complete the CMD for so long duration*/

		/*it means the last byte received is null byte, we wait for 5 consecutive null byte noticed before ending the CMD*/
		if(0x60 == SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK)){
			SimCard->sim_nullByteIssueNullCount ++;
			if(15 < SimCard->sim_nullByteIssueNullCount){
				/*we have receive 5 null byte*/
				SIM_DisAllIntr();
    			kal_sprintf(sim_dbg_str, "[SIM:%d] : null timeout %d\n\r", __LINE__, SimCard->sim_nullByteIssueNullCount);
    			DRV_ICC_print_str(sim_dbg_str);
				//DRV_ICC_print(SIM_PRINT_NULL_TIME_OUT, hw_cb->simInterface, 0, 0, 0, 0);
				SimCard->timeout = KAL_TRUE;
				SIM_SetEvent_MTK(SimCard,SIM_NULLTIMEOUT,hw_cb);
			}
			else{
	    		kal_sprintf(sim_dbg_str, "[SIM:%d] : null timeout %d\n\r", __LINE__, SimCard->sim_nullByteIssueNullCount);
	    		DRV_ICC_print_str(sim_dbg_str);
				// DRV_ICC_print(SIM_PRINT_NULL_BYTE, hw_cb->simInterface, SIM_Reg32(SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), 0, 0, 0);
#if 0 //defined(SIM_HOT_SWAP_V2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

				/*polling status every 3 sec*/
				DRV_ICC_GPTI_StartItem(SimCard->sim_nullByteIssueGPT, 300, sim_nullByteIssueGptTimeout_0, parameter);
			}
		}
		else {/*received is not null*/
			SimCard->sim_nullByteIssueNullCount = 0;
			SimCard->sim_nullByteIssuenonNullCount ++;
			if(15 < SimCard->sim_nullByteIssuenonNullCount){
				/*we have receive 84 non null byte*/
				SIM_DisAllIntr();
	    		kal_sprintf(sim_dbg_str, "[SIM:%d] : non-null timeout %d\n\r", __LINE__, SimCard->sim_nullByteIssuenonNullCount);
	    		DRV_ICC_print_str(sim_dbg_str);
				 SimCard->timeout = KAL_TRUE;
                 SIM_SetEvent_MTK(SimCard,SIM_NULLTIMEOUT,hw_cb);
             } else {
    			kal_sprintf(sim_dbg_str, "[SIM:%d] : non-null timeout %d\n\r", __LINE__, SimCard->sim_nullByteIssuenonNullCount);
    			DRV_ICC_print_str(sim_dbg_str);
    			// DRV_ICC_print(SIM_PRINT_NON_NULL_BYTE, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK), SIM_Reg32(SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), 0, 0);
#if 0 //defined(SIM_HOT_SWAP_V2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC66, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK), SimCard->TOUTValue, drv_get_current_time(), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x34), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90));
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC66, SIM_Reg(SIM0_BASE_ADDR_MTK + 0x10), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x24), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x70), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x74), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x64));
			DRV_ICC_GPTI_StartItem(SimCard->sim_nullByteIssueGPT, 300, sim_nullByteIssueGptTimeout_0, parameter);
            }
		}
	}
}

void sim_nullByteIssueGptTimeout_1(void *parameter)
{
	Sim_Card *SimCard;
	sim_HW_cb *hw_cb;

	hw_cb = (sim_HW_cb *)parameter;
	SimCard = GET_SIM_CB(hw_cb->simInterface);

	/* [ALPS00600930]we should stop wait event gpt timer;otherwise it will cause null byte process fail */
	DRV_ICC_GPTI_StopItem(SimCard->gpt_handle);
#ifdef __SIM_HOT_SWAP_SUPPORT__
	sim_get_card_status(hw_cb->simInterface, &hw_cb->IsCardRemove);

	/* [MAUI_03009364]If card is removed, we don't need to wait null bytes */
	if(hw_cb->IsCardRemove == KAL_TRUE)
	{
		SimCard->sim_nullByteIssueNullCount = 0;
		SimCard->sim_nullByteIssuenonNullCount = 0;
		DRV_ICC_GPTI_StopItem(SimCard->sim_nullByteIssueGPT);
		/*must change magic after we confirm GPT won't trigger, since this code run in task context, we can run this code means GPT won't trigger*/
		SimCard->simMagic1 ++;
		SimCard->simMagic2 = SimCard->simMagic1;
		return;
	}
#endif

	if(SimCard->simMagic1 != SimCard->simMagic2){ /*cmd finished before GPT timeout*/
		kal_sprintf(sim_dbg_str, "sim_nullByteIssueGptTimeout_1:cmd finished before GPT timeout");
    		DRV_ICC_print_str(sim_dbg_str);
	}
	else{/*the GPT timer is used to find out these cases, it means we still haven't complete the CMD for so long duration*/

		/*it means the last byte received is null byte, we wait for 5 consecutive null byte noticed before ending the CMD*/
		if(0x60 == SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK)){
			SimCard->sim_nullByteIssueNullCount ++;
			if(15 < SimCard->sim_nullByteIssueNullCount){
				/*we have receive 5 null byte*/
				SIM_DisAllIntr();
				kal_sprintf(sim_dbg_str, "[SIM:%d] : null timeout %d\n\r", __LINE__, SimCard->sim_nullByteIssueNullCount);
    			DRV_ICC_print_str(sim_dbg_str);
				// DRV_ICC_print(SIM_PRINT_NULL_TIME_OUT, hw_cb->simInterface, 0, 0, 0, 0);
				SimCard->timeout = KAL_TRUE;
				SIM_SetEvent_MTK(SimCard,SIM_NULLTIMEOUT,hw_cb);
			}
			else{
				kal_sprintf(sim_dbg_str, "[SIM:%d] : null timeout %d\n\r", __LINE__, SimCard->sim_nullByteIssueNullCount);
				DRV_ICC_print_str(sim_dbg_str);
				// DRV_ICC_print(SIM_PRINT_NULL_BYTE, hw_cb->simInterface, SIM_Reg32(SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), 0, 0, 0);
#if 0 //defined(SIM_HOT_SWAP_V2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

				/*polling status every 3 sec*/
				DRV_ICC_GPTI_StartItem(SimCard->sim_nullByteIssueGPT, 300, sim_nullByteIssueGptTimeout_1, parameter);
			}
		}
		else {/*received is not null*/
			SimCard->sim_nullByteIssueNullCount = 0;
			SimCard->sim_nullByteIssuenonNullCount ++;
			if(15 < SimCard->sim_nullByteIssuenonNullCount){
				/*we have receive 84 non null byte*/
				SIM_DisAllIntr();
				kal_sprintf(sim_dbg_str, "[SIM:%d] : non-null timeout %d\n\r", __LINE__, SimCard->sim_nullByteIssuenonNullCount);
				DRV_ICC_print_str(sim_dbg_str);
				 SimCard->timeout = KAL_TRUE;
                 SIM_SetEvent_MTK(SimCard,SIM_NULLTIMEOUT,hw_cb);
             } else {
				kal_sprintf(sim_dbg_str, "[SIM:%d] : non-null timeout %d\n\r", __LINE__, SimCard->sim_nullByteIssuenonNullCount);
				DRV_ICC_print_str(sim_dbg_str);
    			// DRV_ICC_print(SIM_PRINT_NON_NULL_BYTE, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK), SIM_Reg32(SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), 0, 0);
#if 0 //defined(SIM_HOT_SWAP_V2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC66, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK), SimCard->TOUTValue, drv_get_current_time(), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x34), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90));
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC66, SIM_Reg(SIM0_BASE_ADDR_MTK + 0x10), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x24), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x70), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x74), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x64));
			DRV_ICC_GPTI_StartItem(SimCard->sim_nullByteIssueGPT, 300, sim_nullByteIssueGptTimeout_1, parameter);
		    }
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




static kal_uint16 SIM_CMD(kal_uint8  *txData,kal_uint16  txSize,kal_uint8  *result,kal_uint16  *rcvSize, kal_uint8 *Error, sim_HW_cb *hw_cb)
//kal_uint16 L1sim_Cmd(kal_uint8  *txData,kal_uint16  txSize,kal_uint8  expSize, kal_uint8  *result,kal_uint8  *rcvSize, kal_uint8 *Error)
{
   kal_uint16 SW;
   kal_uint8 index;
   kal_uint16 INS;
   kal_uint16 expSize = *rcvSize;
#ifdef   SIM_ADDDMA
	kal_bool	txDelay = KAL_FALSE;
   kal_uint32 txaddr;
   kal_uint32 rxaddr;
#endif/*SIM_ADDDMA*/
	Sim_Card *SimCard;
#if !defined(DRV_SIM_6290_SERIES)
	kal_uint32 clkStartTime1;
#endif

	kal_uint32 savedMask;
	kal_uint32 hwCtrl;
    kal_uint8 tmpsts;


	SimCard = GET_SIM_CB(hw_cb->simInterface);


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

   #if 1
	kal_sprintf(sim_dbg_str, "[MOD_SIM_DRV] CMD header: %x %x %x %x %x\n\r", *txData, *(txData+1), *(txData+2), *(txData+3), *(txData+4));
	DRV_ICC_print_str(sim_dbg_str);
  #endif
#if defined(SIM_DEBUG_INFO)
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC15, *txData,*(txData+1),*(txData+2),*(txData+3),*(txData+4));
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC15, *result,*(result+1),*(result+2),*(result+3),*(result+4));
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC15, txSize,*rcvSize,index,drv_get_current_time(),SimCard->timeout);
#endif

   /*for clock stop mode*/
   SIM_DisAllIntr();
#if defined(SIM_DRV_IC_USB)
	if ((SimCard->isIcUsb == KAL_TRUE) && (hw_cb->simInterface == 0x0) &&
        (FACTORY_BOOT != kal_query_boot_mode()) && SimCard->forceISO == KAL_FALSE)
    {		
#if defined(SIM_DRV_IC_USB_DBG_2)
        DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC15, *txData,*(txData+1),*(txData+2),*(txData+3),*(txData+4));
        DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC15, *(txData+5),*(txData+6),*(txData+7),*(txData+8),*(txData+9));		
        DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC15, txSize,*rcvSize,index,drv_get_current_time(),0xaaaa);
#endif
        kal_set_eg_events(SimCard->event,0,KAL_AND);  //2: NU_AND
        *Error = KAL_FALSE;
        SimCard->recDataErr = KAL_FALSE;

        SimCard->sim_icusb_T0cmd.txData = txData;
        SimCard->sim_icusb_T0cmd.txSize = txSize;
        SimCard->sim_icusb_T0cmd.result = result;
        SimCard->sim_icusb_T0cmd.rcvSize = rcvSize;
        SW = SIM_icusb_cmd(hw_cb);
        if (SW == (kal_uint16)SIM_ICUSB_CCCI_TIMEOUT)
        {
            sim_addMsg(0xE023, hw_cb->simInterface, 0, 0);  
            SW = 0x0000;
        }
#if defined(SIM_DRV_IC_USB_DBG)
        DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC83, SimCard->icusb_state, SW, hw_cb->simInterface, SimCard->TB15, SimCard->isIcUsbRecPPS);
#endif
#if defined(SIM_DRV_IC_USB_DBG_2)
        DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC15, txSize,*rcvSize,index,drv_get_current_time(),0xaaab);
#endif
        return SW;
    }
#endif	

   /**mtk04122: we don't need to active the clock in advance,
      **                because we don't have pnd in mt6290 for now....
      **                (maybe apply in future)
     **/
   #if 1
   if (SimCard->clkStop == KAL_TRUE)
   {
      SIM_ActiveClk_MTK(hw_cb);
   }
   else
   {
      sim_PDNDisable_MTK(hw_cb);
   }
   #endif


   SIM_DisAllIntr();

#if !defined(DRV_SIM_6290_SERIES)
    clkStartTime1 = drv_get_current_time();
#endif
  #if defined(DRV_SIM_6290_SERIES)
    if (SimCard->clkStop == KAL_TRUE)
    {
        if((SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK)) & SIM_CTRL_HALT)
        {
            //dbg_print("[DRV] CLK stopped..\r\n");
            SIM_ClearBits(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK, SIM_CONF_TOUTEN);
            if(SimCard->Speed == Speed372)
            {
                SIM_SetTOUT( 2+5 ,hw_cb);   //longer than spec
            }
            else
            {
                //SIM_SetTOUT((ClkStopTimeTable[SimCard->Speed][0]*SimCard->TOUT_Factor)>>4,hw_cb);   //SimCard->TOUT_Factor == Di
                SIM_SetTOUT( ((744/(SimCard->Fi/SimCard->TOUT_Factor)) >> 2)+5,hw_cb);
            }
            //dbg_print("[DRV] REG_TOUT = %d\r\n", SIM_Reg32(SIM0_BASE_ADDR_MTK+SIM_TOUT_MTK));
            SIM_SetBits(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK, SIM_CONF_TOUTEN);
            SimCard->cmdState = SIM_ProcessClk;
            SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,SIM_IRQEN_TOUT);
            SIM_ActiveClk_MTK(hw_cb);
            SIM_WaitEvent_MTK(SimCard,CLK_PROC, KAL_FALSE, hw_cb);
        }
        else
        {
            //dbg_print("[DRV] CLK has not stopped yet...\r\n");
        }
    }

  #else
   if( (SimCard->Speed != Speed372) &&
       ((SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK)) & SIM_CTRL_HALT)
     )

   {

      SIM_ClearBits(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK, SIM_CONF_TOUTEN);
#ifndef DRV_SIM_HIGH_SPEED
			if(3 <= SimCard->Speed)
				ASSERT(0);
#else
			if(5 <= SimCard->Speed)
				ASSERT(0);
#endif

      SIM_SetTOUT(ClkStopTimeTable[SimCard->Speed][0]*SimCard->TOUT_Factor,hw_cb);
      SIM_SetBits(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK, SIM_CONF_TOUTEN);
      SimCard->cmdState = SIM_ProcessClk;
      SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,SIM_IRQEN_TOUT);
	DRV_ICC_print_str("before waiting clk proc\n\r");
      SIM_WaitEvent_MTK(SimCard,CLK_PROC, KAL_FALSE, hw_cb);
   }

#ifndef DRV_SIM_HIGH_SPEED
	else if(SimCard->is_err && SimCard->Speed == Speed32) // to solve ROSSINI SIM issue
#else
	else if(SimCard->is_err && (SimCard->Speed == Speed32 || SimCard->Speed == Speed16 || SimCard->Speed == Speed8)) // to solve ROSSINI SIM issue
#endif
	{
#ifndef __TBD__
		kal_uint32 t1;

		t1 = SIM_GetCurrentTime();
		while((SIM_GetCurrentTime()-t1) < 5); // delay 500 clock cycles (152us)
#endif
	}
    #endif //defined(DRV_SIM_6290_SERIES)



#if !defined(DRV_SIM_6290_SERIES)
#ifdef __OLD_PDN_ARCH__
   /*check PDN, baud rate, clk_stop here*/
   if(DRV_Reg(hw_cb->mtk_pdnAddr)&hw_cb->mtk_pdnBit)
   	ASSERT(0);
#endif
#endif /*DRV_SIM_6290_SERIES*/

   if(0x3 == SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK))
		ASSERT(0);



#ifndef __MAUI_BASIC__
	if(0 != SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK)){
		/*we print index, */
#if !defined(__L1_STANDALONE__)
 #if defined(__SIM_DRV_TRACE__)
   		drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK) , SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK),
			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK),
			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK)
		);
 #endif /*__SIM_DRV_TRACE__*/
#endif
	}
#endif


   SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);

   kal_set_eg_events(SimCard->event,0,KAL_AND);  //2: NU_AND

   SIM_SetTOUT(SimCard->TOUTValue,hw_cb);
   SIM_FIFO_Flush();
   ////dbg_print("[DRV] TOUTValue = %d\r\n",SimCard->TOUTValue);
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
   SIM_SetCOMDLEN(*(txData+4));
   SimCard->cmdState = SIM_WaitCmdEnd;
#endif   /*NoT0CTRL*/

#ifdef SIM_ADDDMA

#if defined (__SIM_DVT__)
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94),
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94)
	);
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94),
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94)
	);
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94),
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), 0, 0
	);
	
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90),
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90)
	);
#endif

       savedMask = SaveAndSetIRQMask();
       for(index=0;index<5;index++)
       {
          SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK,*(txData+index));
       }
       sim_addMsg(SIM_CMD_TX_LOG, *(txData + 1), *(txData + 4), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK));
       RestoreIRQMask(savedMask);

#if defined (__SIM_DVT__)
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94),
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94)
	);
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94),
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94)
	);
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94),
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94), 0, 0
	);
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90),
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90)
	);
#endif

       
       //DRVPDN_Disable(DRVPDN_CON0,DRVPDN_CON0_DMA,PDN_DMA);
#if defined(DRV_SIM_6290_SERIES)
    SIM_DMA_STOP(SimCard->dma_config.channel);
#else
    DMA_Stop(SimCard->sim_dmaport);
#endif

       SIM_SetRXTIDE(1, hw_cb); //set rxtide 0

       if (expSize == 0)
       {
#if defined(SIM_DEBUG_INFO)
		DRV_ICC_print_str("SIM TX\n\r");
#endif

          SIM_SetTXTIDE(0, hw_cb);
          //#if ( defined(MT6205) || defined(MT6205B) )

   #if defined(DRV_SIM_6290_SERIES)
        SIM_WriteReg32(SimCard->dma_config.ADDR_HDMA_HPRGA0Rx, (kal_uint32)(txaddr+5));
        SIM_WriteReg32(SimCard->dma_config.ADDR_HDMA_HDCTRRx, ( HDCTRR_RX_SEL0(0)|
                                                              HDCTRR_BST_SIZE(HDCTRR_BST_SIZE_16) |
                                                              HDCTRR_DEV_BUS_WIDTH(HDCTRR_BUS_WIDTH_8) |
                                                              HDCTRR_MEM_BUS_WIDTH(HDCTRR_BUS_WIDTH_32)));
        SIM_WriteReg32(SimCard->dma_config.ADDR_HDMA_HDC0Rx, HDCR_XFER_SIZE0(txSize-5) | HDCR_START0);

    #else
          SimCard->sim_menu.addr = (kal_uint32)(txaddr+5);  /*1*/
          SimCard->sim_input.type = DMA_HWTX; /*2*/
          SimCard->sim_input.count = txSize-5;       /*3*/
    	if(SimCard->sim_input.count > SIM_TX_DELAY_LEN && SimCard->Speed > Speed372)
    		txDelay = KAL_TRUE;
         SimCard->sim_input.callback = NULL;   /*4*/
             /*DMA_Config(sim_dmaport, &sim_input, KAL_TRUE);     */

    #endif /*DRV_SIM_6290_SERIES*/
         INS |= SIM_INS_INSD;

       }
       else
       {
#if defined(SIM_DEBUG_INFO)
		DRV_ICC_print_str("SIM RX\n\r");
#endif

          SIM_SetTXTIDE(0xffff, hw_cb);

          #if defined(DRV_SIM_6290_SERIES)
            SIM_WriteReg32(SimCard->dma_config.ADDR_HDMA_HPRGA0Rx, (kal_uint32)(rxaddr));
            SIM_WriteReg32(SimCard->dma_config.ADDR_HDMA_HDCTRRx, ( HDCTRR_RX_SEL0(1)|
                                                              HDCTRR_BST_SIZE(HDCTRR_BST_SIZE_16) |
                                                              HDCTRR_DEV_BUS_WIDTH(HDCTRR_BUS_WIDTH_8) |
                                                              HDCTRR_MEM_BUS_WIDTH(HDCTRR_BUS_WIDTH_32)));
            SIM_WriteReg32(SimCard->dma_config.ADDR_HDMA_HDC0Rx, HDCR_XFER_SIZE0(expSize) | HDCR_START0);

          #else
          //#if ( defined(MT6205) || defined(MT6205B) )
             SimCard->sim_menu.addr = (kal_uint32)(rxaddr);  /*1*/
             SimCard->sim_input.type = DMA_HWRX; /*2*/
             SimCard->sim_input.count = expSize;       /*3*/
             SimCard->sim_input.callback = NULL;   /*4*/
             /*DMA_Config(sim_dmaport, &sim_input, KAL_TRUE);  */
          #endif /*DRV_SIM_6290_SERIES*/
       }

     #if defined(DRV_SIM_6290_SERIES)
        tmpsts = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
        SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK, tmpsts);
     #else
       /*make sure it has been 750 us passed*/
       while(25 > drv_get_duration_tick(clkStartTime1, drv_get_current_time()));
       SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
     #endif /*DRV_SIM_6290_SERIES*/
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
   //SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
   tmpsts = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
   SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK, tmpsts); 
   SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK, SIM_IRQEN_CMDNormal);
#else /*NoT0CTRL*/

   if(txSize <= 15)
   {
      for(index=0;index<txSize;index++)
      {
         SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_DATA_MTK,*(txData+index));
      }
      SimCard->txindex = txSize;

      tmpsts = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
      SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK, tmpsts);
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

      tmpsts = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
      SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK, tmpsts);
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
    #if defined(DRV_SIM_6290_SERIES)
        /*start DMA*/
        //mtk04122:we start the DMA after we finish the DMA configuration
        //SIM_SetBits(SimCard->dma_config.ADDR_HDMA_HDC0Rx, HDCR_START0);
    #else
       //#if ( defined(MT6205) || defined(MT6205B) )
       	/*DMA add this assertion, so we should avoid this*/
       	if(0 != SimCard->sim_input.count)
          		DMA_Config(SimCard->sim_dmaport, &SimCard->sim_input, KAL_FALSE);
    #endif /*DRV_SIM_6290_SERIES*/

#if defined(SIM_DEBUG_INFO)
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC40, SIM_Reg(SIM0_BASE_ADDR_MTK + 0x00), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x4), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x8),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x10),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x20));
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC40, SIM_Reg(SIM0_BASE_ADDR_MTK + 0x24),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x34),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x60),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x68),SimCard->recDataErr);		
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC40, SIM_Reg(SIM0_BASE_ADDR_MTK + 0x6c),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x70),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x74),SIM_Reg32(SIM0_BASE_ADDR_MTK + 0x90),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94));
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC40, SIM_Reg32(DMA_base + 0x0 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x4 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x8 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x10 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x18 + (0x80 * SimCard->sim_dmaport)));
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC40, SIM_Reg32(DMA_base + 0x1c + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x20 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x24 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x28 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x38 + (0x80 * SimCard->sim_dmaport)));
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC40, SIM_Reg32(DMA_base + 0x50 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x8),SIM_Reg32(0x80000450),drv_get_current_time(),0);	
#endif


#endif   /*SIM_ADDDMA*/

	{
	#if !defined(DRV_SIM_6290_SERIES)
		extern void DMA_Run(kal_uint8 channel);
        #endif

#ifndef    NoT0CTRL
#ifdef	SIM_NULLBYTE_ISSUE
        hwCtrl = sim_get_hwCtrl_from_logicalNum(hw_cb->simInterface);
		if(MTK_SIMIF0 == hwCtrl){
			SimCard->sim_nullByteIssueNullCount = 0;
			SimCard->sim_nullByteIssuenonNullCount = 0;
			DRV_ICC_GPTI_StopItem(SimCard->sim_nullByteIssueGPT);
			/*must change magic after we confirm GPT won't trigger, since this code run in task context, we can run this code means GPT won't trigger*/
			SimCard->simMagic1 ++;
			SimCard->simMagic2 = SimCard->simMagic1;
			DRV_ICC_GPTI_StartItem(SimCard->sim_nullByteIssueGPT, 300, sim_nullByteIssueGptTimeout_0, hw_cb);
		}
		else if(MTK_SIMIF1 == hwCtrl){
			SimCard->sim_nullByteIssueNullCount = 0;
			SimCard->sim_nullByteIssuenonNullCount = 0;
			DRV_ICC_GPTI_StopItem(SimCard->sim_nullByteIssueGPT);
			/*must change magic after we confirm GPT won't trigger, since this code run in task context, we can run this code means GPT won't trigger*/
			SimCard->simMagic1 ++;
			SimCard->simMagic2 = SimCard->simMagic1;
			DRV_ICC_GPTI_StartItem(SimCard->sim_nullByteIssueGPT, 300, sim_nullByteIssueGptTimeout_1, hw_cb);
		}
		else
			ASSERT(0);

#endif
#endif   /*NoT0CTRL*/

#ifndef __MAUI_BASIC__
#ifdef __OLD_PDN_ARCH__
#if !defined(__L1_STANDALONE__)
		drv_trace8(TRACE_GROUP_4, SIM_GEMINI_CMD1, SIM_Reg(DRVPDN_CON1), hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK),
			INS, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK),
			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK)
			);
#endif
#else //__OLD_PDN_ARCH__
/*use PDN_STATUS(dev, s, t) to fullfill my dbg usage, add the code later*/
#if !defined(__L1_STANDALONE__)
#if defined(__SIM_DRV_TRACE__)
		drv_trace8(TRACE_GROUP_4, SIM_GEMINI_CMD1, 0, hw_cb->simInterface, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_BRR_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK),
			INS, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK),
			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK)
			);
#endif /*__SIM_DRV_TRACE__*/
#endif
#endif
#if !defined(__L1_STANDALONE__)
 #if defined(__SIM_DRV_TRACE__)
		drv_trace8(TRACE_GROUP_4, SIM_GEMINI_CMD2, SimCard->sim_menu.addr,SimCard->sim_input.type,SimCard->sim_input.count,0, 
					drv_get_current_time(), SimCard->sim_input.count,
			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK)
			);
		drv_trace8(TRACE_GROUP_4, SIM_GEMINI_CMD3, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IMP3_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x70),
			SIM_Reg(SIM0_BASE_ADDR_MTK + 0x74),
			*txData, *(txData + 1), *(txData + 2), *(txData + 3), *(txData + 4)
				);
#endif /*__SIM_DRV_TRACE__*/
#endif
#endif   //__MAUI_BASIC__

		/*in case */
		SimCard->EvtFlag = 0x0;

		if(SimCard->simMagic2 != SimCard->simMagic1)
			ASSERT(0);
		if(txDelay == KAL_FALSE)
			savedMask = SaveAndSetIRQMask();
#ifndef    NoT0CTRL
{
#ifndef __DRV_LOW_SPEED_EMI_PLATFORM__
	/*we should not use the same variable to store the return value twice*/
		kal_uint32 savedMask2;

		savedMask2 = SaveAndSetIRQMask();
		sim_addMsg(SIM_CMD_INS_LOG, hw_cb->simInterface, INS, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK));
#endif
		SIM_SetCmdCTRL(INS);
		SIM_CMDSTART();
#ifndef __DRV_LOW_SPEED_EMI_PLATFORM__
		   RestoreIRQMask(savedMask2);
#endif
}
#endif   /*NoT0CTRL*/

#if defined (__SIM_DVT__)	
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90),
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90)
	);
#endif /* End of #if defined (__SIM_DVT__) */


#ifdef SIM_ADDDMA
    #if !defined(DRV_SIM_6290_SERIES)
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
    		sim_addMsg(SIM_CMD_TXDELAY, hw_cb->simInterface, SimCard->sim_input.count, txSize);
    #ifndef __TBD__
    		t1 = SIM_GetCurrentTime();
    		do{
    		t2 = SIM_GetCurrentTime();
    		}while(SIM_GetDurationTick(t1,t2) < 32);
    #endif
    	}
#if 0
#ifndef __DRV_LOW_SPEED_EMI_PLATFORM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
	/*DMA add this assertion, so we should avoid this*/
	if(0 != SimCard->sim_input.count)
		DMA_Run(SimCard->sim_dmaport);
  #endif /*DRV_SIM_6290_SERIES*/
#endif   /*SIM_ADDDMA*/

		if(txDelay == KAL_FALSE)
			RestoreIRQMask(savedMask);

	}
#ifdef SIM_ADDDMA
   sim_addMsg(0x2468024, hw_cb->simInterface, txDelay, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK));
#endif   /*SIM_ADDDMA*/
   SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);

#if 0 //def SIM_HOT_SWAP_V2
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#if defined (__SIM_DVT__)	
	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90),
		SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x90)
	);
#endif /* End of #if defined (__SIM_DVT__) */
#if defined(SIM_DEBUG_INFO)
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC42, SIM_Reg(SIM0_BASE_ADDR_MTK + 0x00), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x4), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x8),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x10),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x20));
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC42, SIM_Reg(SIM0_BASE_ADDR_MTK + 0x24),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x34),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x60),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x68),SimCard->recDataErr);		
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC42, SIM_Reg(SIM0_BASE_ADDR_MTK + 0x6c),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x70),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x74),SIM_Reg32(SIM0_BASE_ADDR_MTK + 0x90),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94));
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC42, SIM_Reg32(DMA_base + 0x0 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x4 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x8 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x10 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x18 + (0x80 * SimCard->sim_dmaport)));
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC42, SIM_Reg32(DMA_base + 0x1c + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x20 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x24 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x28 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x38 + (0x80 * SimCard->sim_dmaport)));
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC42, SIM_Reg32(DMA_base + 0x50 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x8),SIM_Reg32(0x80000450),drv_get_current_time(),0);
#endif
   SIM_WaitEvent_MTK(SimCard,SIM_EVT_CMD_END, KAL_FALSE, hw_cb);
//sim_dump_fifo(hw_cb);
#if defined(SIM_DEBUG_INFO)
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC43, SIM_Reg(SIM0_BASE_ADDR_MTK + 0x00), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x4), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x8),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x10),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x20));
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC43, SIM_Reg(SIM0_BASE_ADDR_MTK + 0x24),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x34),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x60),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x68),SimCard->recDataErr);		
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC43, SIM_Reg(SIM0_BASE_ADDR_MTK + 0x6c),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x70),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x74),SIM_Reg32(SIM0_BASE_ADDR_MTK + 0x90),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94));
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC43, SIM_Reg32(DMA_base + 0x0 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x4 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x8 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x10 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x18 + (0x80 * SimCard->sim_dmaport)));
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC43, SIM_Reg32(DMA_base + 0x1c + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x20 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x24 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x28 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x38 + (0x80 * SimCard->sim_dmaport)));
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC43, SIM_Reg32(DMA_base + 0x50 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x8),SIM_Reg32(0x80000450),drv_get_current_time(),0);
#endif
#ifdef	SIM_NULLBYTE_ISSUE
	DRV_ICC_GPTI_StopItem(SimCard->sim_nullByteIssueGPT);
#endif


#ifdef SIM_ADDDMA
    #if defined(DRV_SIM_6290_SERIES)
        SIM_DMA_STOP(SimCard->dma_config.channel);
    #else
       //#if ( defined(MT6205) || defined(MT6205B) )
       /*DMA add this assertion, so we should avoid this*/
       if(0 != SimCard->sim_input.count){
     #ifdef DRV_SIM_DMA_V2
     	 /*in DMA_V2, we should use flush to end RX DMA*/
    	if(0 != expSize) //rx
    	 	DMA_Flush(SimCard->sim_dmaport);
    	else //tx
    		DMA_Stop(SimCard->sim_dmaport);
     #else
       	DMA_Stop(SimCard->sim_dmaport);
     #endif
       }
    #endif /*DRV_SIM_6290_SERIES*/
#endif   /*SIM_ADDDMA*/

#ifdef NoT0CTRL
   SimCard->initialPower = SimCard->cmdState;
   SimCard->cmdState = SIMD_CmdIdle;
#endif   /*NoT0CTRL*/

#if !defined(DRV_SIM_6290_SERIES)
#ifdef __OLD_PDN_ARCH__
	/*check PDN, baud rate, clk_stop here*/
   if(DRV_Reg(hw_cb->mtk_pdnAddr)&hw_cb->mtk_pdnBit)
   	ASSERT(0);
#endif
#endif /*DRV_SIM_6290_SERIES*/
   if(0x3 == SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK))
   	ASSERT(0);

   if (SimCard->result == SIM_SUCCESS && SimCard->recDataErr == KAL_FALSE)
   {
    #ifdef  SIM_ADDDMA
        #if defined(DRV_SIM_6290_SERIES)
        if(expSize != 0)
        {
            kal_uint16 leftlen = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_LEFTLEN_MTK);
    	    if (leftlen > expSize) {
                *rcvSize = expSize;
                kal_sprintf(sim_dbg_str, "SIM Error : in SIM_CMD Leftlen(%d) > expSize(%d)!!!\r\n", leftlen, expSize);
                tst_sys_trace(sim_dbg_str);
    	    } else {
                *rcvSize = expSize - leftlen;
            }
        }
        #else
            if(expSize != 0)
               *rcvSize = expSize - SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IMP3_MTK);
            //DRVPDN_Enable(DRVPDN_CON0,DRVPDN_CON0_DMA,PDN_DMA);
        #endif
    #else /*SIM_ADDDMA*/
   *rcvSize = SimCard->recDataLen;
    #endif /*SIM_ADDDMA*/

#if defined(SIM_DEBUG_INFO)
	DRV_ICC_print_str("SIM_SUCCESS\n\r");
#endif

      #ifdef NoT0CTRL
      SW = (SimCard->SW2 | (SimCard->SW1 << 8));
      #else /*NoT0CTRL*/
      SIM_ObtainSW(SW);
      #endif   /*NoT0CTRL*/

#if defined(SIM_DEBUG_INFO)
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC16, SimCard->sim_menu.addr, SimCard->sim_input.type, SimCard->sim_input.count,SW,*rcvSize);
	DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC16, txSize,*Error,*result,*(result+1),drv_get_current_time());
#endif


      // dbg_print("SW=%x\r\n",SW);
      // for clock stop mode
      if(SimCard->clkStop == KAL_TRUE)
      {
         kal_uint32 t1;
        //dbg_print("[DRV] CLK Stopping...\r\n");
         SIM_DisAllIntr();
         SIM_ClearBits(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK, SIM_CONF_TOUTEN);
      #if defined(DRV_SIM_6290_SERIES)
         SIM_SetTOUT( ((1860/(SimCard->Fi/SimCard->TOUT_Factor)) >> 2)+10 ,hw_cb);
      #else
         SIM_SetTOUT(ClkStopTimeTable[SimCard->Speed][1]* SimCard->TOUT_Factor,hw_cb);
      #endif
         SIM_SetBits(SIM0_BASE_ADDR_MTK + SIM_CONF_MTK, SIM_CONF_TOUTEN);
         SimCard->cmdState = SIM_StopClk;
         SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK,SIM_IRQEN_TOUT);

         t1 = SIM_GetCurrentTime();
		 while((SIM_GetCurrentTime()-t1) < 20); // delay 600 clock cycles (600us)
      }
      else
      {
            kal_uint32 t1;

            t1 = SIM_GetCurrentTime();
            while((SIM_GetCurrentTime()-t1) < 25); // delay 750 clock cycles (750us) 			
      }
      return SW;
   }
   else
   {
#ifdef NoT0CTRL
	         SW = (SimCard->SW2 | (SimCard->SW1 << 8));
#else /*NoT0CTRL*/
		       SIM_ObtainSW(SW);
#endif   /*NoT0CTRL*/
	//kal_sprintf(sim_dbg_str,"[SIM]:SIM_CMD fail status=%d", SimCard->result);
	//dbg_print(sim_dbg_str);
	DRV_ICC_print(SIM_PRINT_SIM_CMD_FAIL_STATUS, SimCard->result, SW, drv_get_current_time(), *rcvSize, hw_cb->simInterface);
	//DRV_ICC_print(SIM_PRINT_SIM_CMD_FAIL_STATUS, SimCard->sim_menu.addr, SimCard->sim_input.type, SimCard->sim_input.count,*result,*(result+1));
	DRV_ICC_print(SIM_PRINT_SIM_CMD_FAIL_STATUS, *(result+2),*(result+3),*(result+4),expSize,txSize);
	DRV_ICC_print(SIM_PRINT_SIM_CMD_FAIL_STATUS, SIM_Reg(SIM0_BASE_ADDR_MTK + 0x00), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x4), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x8),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x10),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x20));
	DRV_ICC_print(SIM_PRINT_SIM_CMD_FAIL_STATUS, SIM_Reg(SIM0_BASE_ADDR_MTK + 0x24),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x34),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x60),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x68),SimCard->recDataErr);
	DRV_ICC_print(SIM_PRINT_SIM_CMD_FAIL_STATUS, SIM_Reg(SIM0_BASE_ADDR_MTK + 0x6c),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x70),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x74),SIM_Reg32(SIM0_BASE_ADDR_MTK + 0x90),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x94));
	//DRV_ICC_print(SIM_PRINT_SIM_CMD_FAIL_STATUS, SIM_Reg32(DMA_base + 0x0 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x4 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x8 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x10 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x18 + (0x80 * SimCard->sim_dmaport)));
	//DRV_ICC_print(SIM_PRINT_SIM_CMD_FAIL_STATUS, SIM_Reg32(DMA_base + 0x1c + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x20 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x24 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x28 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x38 + (0x80 * SimCard->sim_dmaport)));
	//DRV_ICC_print(SIM_PRINT_SIM_CMD_FAIL_STATUS, SIM_Reg32(DMA_base + 0x50 + (0x80 * SimCard->sim_dmaport)),SIM_Reg32(DMA_base + 0x8),SIM_Reg32(0x80000450),drv_get_current_time(),SIM_Reg(SIM0_BASE_ADDR_MTK + 0x64));
#ifndef __MAUI_BASIC__
   	/*we print DMA lefting, SIM controller power, SW1, SW2, 0x70, 0x74*/
#ifdef __OLD_PDN_ARCH__
#if !defined(__L1_STANDALONE__)
   	drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
			SIM_Reg(DMA_base + 0x24 + (0x100 * SimCard->sim_dmaport)), SIM_Reg(DRVPDN_CON1), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW2_MTK),
			SIM_Reg(SIM0_BASE_ADDR_MTK + 0x70), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x74)
		);
#endif
#else
#endif
   	if(0 != expSize){
   		/*we print P3, rx buffer addr, ((EV_GCB *)SimCard->event)->ev_current_events, data count, rx 1st, 2nd byte*/
#if !defined(__L1_STANDALONE__)
 #if defined(__SIM_DRV_TRACE__)
   		drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IMP3_MTK), (kal_uint32)result, 0, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK),
			*result, *(result+1)
		);
 #endif /*__SIM_DRV_TRACE__*/
#endif
   	}
#endif /*__MAUI_BASIC__*/


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
#ifdef SIM_CACHED_SUPPORT
	kal_uint8	*pNoncachedTx, *pNoncachedRx;
#endif

	SimCard = GET_SIM_CB(hw_cb->simInterface);

#if defined(SIM_DEBUG_INFO)
	kal_sprintf(sim_dbg_str, "L1sim_Cmd(1) txSize=%d, rcvSize=%d\n\r", txSize, *rcvSize);
	DRV_ICC_print_str(sim_dbg_str);
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

	if ((INT_QueryIsCachedRAM(txData, txSize)) || (INT_QueryIsCachedRAM(result, 512)))
        {

		 GET_NCACHEDTX_P(pNoncachedTx, sim_get_hwCtrl_from_logicalNum(hw_cb->simInterface));
		 GET_NCACHEDRX_P(pNoncachedRx, sim_get_hwCtrl_from_logicalNum(hw_cb->simInterface));
		kal_mem_cpy(pNoncachedTx, txData, txSize);
		if(INT_QueryIsCachedRAM(result, 512)){
            //dbg_print("[DRV] CACHED TX and RX\r\n");
			SW = SIM_CMD((kal_uint8 *)pNoncachedTx,txSize,(kal_uint8 *)pNoncachedRx,rcvSize,Error, hw_cb);
			if(0 != *rcvSize){
                #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __DRV_SIM_DMA_TX2RX__
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
#ifndef __MAUI_BASIC__
#if !defined(__L1_STANDALONE__)
 #if defined(__SIM_DRV_TRACE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #endif /*__SIM_DRV_TRACE__*/
#endif
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
                #endif
				kal_mem_cpy(result, pNoncachedRx, *rcvSize);
			}
		}
		else{
			SW = SIM_CMD((kal_uint8 *)pNoncachedTx,txSize, result, rcvSize,Error, hw_cb);
		}
	}
	else
#endif // SIM_CACHED_SUPPORT
   	{
      		SW = SIM_CMD(txData,txSize,result,rcvSize,Error, hw_cb);
   	}

    if(0x9000 == SW && 0xA4 == txData[1]){
    	//dbg_print("[SIM]:0x9000 on select");
	DRV_ICC_print(SIM_PRINT_9000_ON_SELECT, 0, 0, 0, 0, 0);
    	SimCard->get9000WhenSelect = KAL_TRUE;
    }

#if defined(SIM_DEBUG_INFO)
	kal_sprintf(sim_dbg_str, "L1sim_Cmd(2) txSize=%d, rcvSize=%d, fifo: %d\n\r", txSize, *rcvSize, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK));
	DRV_ICC_print_str(sim_dbg_str);
#endif

#ifdef __SIM_HOT_SWAP_SUPPORT__
#ifdef SIM_HOT_SWAP_V2
	sim_get_card_status(hw_cb->simInterface, &hw_cb->IsCardRemove);

	/* [MAUI_03009364]If card is removed, we don't need to wait status words */
	if(hw_cb->IsCardRemove && *Error == KAL_TRUE)
	{
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC70, 0x3, SW, drv_get_current_time(), *rcvSize, hw_cb->simInterface);
		/* SimCard->timeout's life cycle should be only in this L1sim_Cmd, reset to false before we leave */
		SimCard->timeout = KAL_FALSE;
		return SW;
	}
#endif
#endif

		if(SimCard->timeout && SimCard->app_proto == USIM_PROTOCOL)
		{
		   DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC18, txSize,*rcvSize,drv_get_current_time(),SW,hw_cb->simInterface);
		   /*SimCard->timeout's life cycle should be only in this L1sim_Cmd, reset to false before we leave*/
		   SimCard->timeout = KAL_FALSE;

#ifdef DUAL_MCU_SIM_V1
			pmic6326_ccci_lock(KAL_TRUE);
			/*AP will wake up in at most 100ms*/
			kal_sleep_task(25);
#endif
			sim_PowerOff_MTK(hw_cb);

			/*to deactivation SIMIF takes time, we must make sure it deactivated done*/
			kal_sleep_task(20);

#ifdef DUAL_MCU_SIM_V1
#if defined(__SIM_DRV_TRACE__)
			drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__, hw_cb->simInterface, 0, 0, 0, 0, drv_get_current_time());
#endif
			pmic6326_ccci_lock(KAL_FALSE);
#endif
			return SW;
		}
#ifdef __SIM_HOT_SWAP_SUPPORT__		
		sim_get_card_status(hw_cb->simInterface, &hw_cb->IsCardRemove);
		/* [MAUI_03009364]If card is removed, we don't need to wait status words */
		if(hw_cb->IsCardRemove && *Error == KAL_TRUE)
		{
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC70, 0x5, SW, drv_get_current_time(), *rcvSize, hw_cb->simInterface);
			/*SimCard->timeout's life cycle should be only in this L1sim_Cmd, reset to false before we leave*/
			SimCard->timeout = KAL_FALSE;
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
		//kal_sprintf(sim_dbg_str,"[SIM]:SIM_CMD fail result=%d, status=%x\n\r", SimCard->result, SW);
		//dbg_print(sim_dbg_str);
		DRV_ICC_print(SIM_PRINT_CMD_FAIL_RESULT_STATUS, SimCard->result, SW, drv_get_current_time(), 0, 0);
		//kal_sprintf(sim_dbg_str,"[SIM]: recDataErr=%d, timeout=%d, cmdState=%d, event_state=%d, EvtFlag=%d, clkStop=%d, app_proto=%d\n\r",
		//	SimCard->recDataErr, SimCard->timeout, SimCard->cmdState, SimCard->event_state,
		//	SimCard->EvtFlag, SimCard->clkStop, SimCard->app_proto);
		//dbg_print(sim_dbg_str);
		DRV_ICC_print(SIM_PRINT_RECEIVE_ERR_1, SimCard->recDataErr, SimCard->timeout, SimCard->cmdState, SimCard->event_state, SimCard->EvtFlag);
		DRV_ICC_print(SIM_PRINT_RECEIVE_ERR_2, SimCard->clkStop, SimCard->app_proto, 0, 0, 0);

#ifndef __MAUI_BASIC__
#ifdef __OLD_PDN_ARCH__
 #if defined(__SIM_DRV_TRACE__)
		/*we print DMA lefting, SIM controller power, SW1, SW2, 0x70, 0x74*/
   		drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
			SIM_Reg(DMA_base + 0x24 + (0x100 * SimCard->sim_dmaport)), SIM_Reg(DRVPDN_CON1), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK), SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW2_MTK),
			SIM_Reg(SIM0_BASE_ADDR_MTK + 0x70), SIM_Reg(SIM0_BASE_ADDR_MTK + 0x74)
		);
 #endif /*__SIM_DRV_TRACE__*/
#else
#endif
   		if(0 != result){
   			/*we print P3, rx buffer addr, ((EV_GCB *)SimCard->event)->ev_current_events, data count, rx 1st, 2nd byte*/
#if !defined(__L1_STANDALONE__)
 #if defined(__SIM_DRV_TRACE__)
   			drv_trace8(TRACE_GROUP_4, SIM_GEMINI_GEN1, FILE_SWITCHCONTROL0, __LINE__,
			SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_IMP3_MTK), (kal_uint32)result, 0, SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK),
			*result, *(result+1)
			);
 #endif /*__SIM_DRV_TRACE__*/
#endif
   		}
#endif
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
void L1sim_Init_MTK(sim_HW_cb *hw_cb)		//Validate
{
	Sim_Card *SimCard;
	kal_uint32 hwCtrl;


	SimCard = GET_SIM_CB(hw_cb->simInterface);
	SimCard->SIM_ENV = SIM_GetCurrentEnv(hw_cb->simInterface);
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
      #if defined(DRV_SIM_6290_SERIES)
          SimCard->dma_config.BURST_SIZE = HDCTRR_BST_SIZE_16;
          SimCard->dma_config.DEV_BUS_WIDTH = HDCTRR_BUS_WIDTH_8;
          SimCard->dma_config.MEM_BUS_WIDTH = HDCTRR_BUS_WIDTH_32;
          SimCard->dma_config.channel = hw_cb->simInterface;
          SimCard->dma_config.ADDR_HDMA_HPRGA0Rx = (hw_cb->simInterface == 0)? REG_HDMA_HPRGA0R0 : REG_HDMA_HPRGA0R1;
          SimCard->dma_config.ADDR_HDMA_HPRGA1Rx = (hw_cb->simInterface == 0)? REG_HDMA_HPRGA1R0 : REG_HDMA_HPRGA1R1;
          SimCard->dma_config.ADDR_HDMA_HDCTRRx = (hw_cb->simInterface == 0)? REG_HDMA_HDCTRR0 : REG_HDMA_HDCTRR1;
          SimCard->dma_config.ADDR_HDMA_HDC0Rx = (hw_cb->simInterface == 0)? REG_HDMA_HDC0R0 : REG_HDMA_HDC0R1;
          SimCard->dma_config.ADDR_HDMA_HDC1Rx = (hw_cb->simInterface == 0)? REG_HDMA_HDC1R0 : REG_HDMA_HDC1R1;

      #else
          if(SimCard->sim_dmaport == 0)
             SimCard->sim_dmaport = DMA_GetChannel((DMA_Master)hw_cb->mtk_dmaMaster);
          SimCard->sim_menu.master = (DMA_Master)hw_cb->mtk_dmaMaster;


          SimCard->sim_menu.TMOD.burst_mode = KAL_FALSE;
          SimCard->sim_menu.addr = NULL;  /*1*/
          SimCard->sim_input.type = DMA_HWTX; /*2*/
          SimCard->sim_input.size = DMA_BYTE;
          SimCard->sim_input.menu = &SimCard->sim_menu;
          SimCard->sim_input.count = 0;       /*3*/
          SimCard->sim_input.callback = NULL;   /*4*/
      #endif
   #endif   /*SIM_ADDDMA*/

	/*following members are originally RW global variable, need additional initialize here*/
   //dbg_print("SIM_DEFAULT_TOUT_VALUE = %x\r\n",SIM_DEFAULT_TOUT_VALUE);

#if defined(DRV_SIM_6290_SERIES)
   SimCard->TOUTValue = SIM_DEFAULT_TOUT_VALUE << 2;
#else
   SimCard->TOUTValue = SIM_DEFAULT_TOUT_VALUE;
#endif

   	SimCard->TOUT_Factor = 1;
   	SimCard->PTS_check = KAL_TRUE;
   #if defined(DRV_SIM_6290_SERIES)
    SimCard->Fi = 372;
   #endif
	//DRV_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);
	DRV_WriteReg((SIM0_BASE_ADDR_MTK + SIM_STS_MTK),DRV_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK));

	if (SimCard->event == NULL){
        hwCtrl = sim_get_hwCtrl_from_logicalNum(hw_cb->simInterface);
		if(MTK_SIMIF0 == hwCtrl){
	   	SimCard->event = kal_create_event_group("SIMEVT");
		}
		else if(MTK_SIMIF1 == hwCtrl){
	   	SimCard->event = kal_create_event_group("SIMEVT2");
		}
	   else
	   	ASSERT(0);
	}

	/*hisr and lisr should be different in both interfaces*/
	if(SIM_base == hw_cb->mtk_baseAddr){
		DRV_Register_HISR(DRV_SIM_HISR_ID, SIM_HISR_Multiple);
		IRQ_Register_LISR(hw_cb->mtk_lisrCode, SIM_LISR_Multiple,"SIM handler");

#ifdef	SIM_NULLBYTE_ISSUE
		if(NULL ==(void*)SimCard->sim_nullByteIssueGPT)
			DRV_ICC_GPTI_GetHandle(&SimCard->sim_nullByteIssueGPT);
#if 0
#ifdef SIM_HOT_SWAP_V2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
#endif
        if(SimCard->gpt_handle == (kal_uint32)NULL)
			DRV_ICC_GPTI_GetHandle(&SimCard->gpt_handle);
		IRQSensitivity(hw_cb->mtk_lisrCode,LEVEL_SENSITIVE);
		IRQUnmask(hw_cb->mtk_lisrCode);
	}
#if (2 == SIM_DRV_MTK_INTERFACE_NUM)
	else if(SIM2_base == hw_cb->mtk_baseAddr){
		DRV_Register_HISR(DRV_SIM2_HISR_ID, SIM_HISR2_Multiple);
		IRQ_Register_LISR(hw_cb->mtk_lisrCode, SIM_LISR2_Multiple,"SIM2 handler");

#ifdef	SIM_NULLBYTE_ISSUE
		if(NULL == (void*)SimCard->sim_nullByteIssueGPT)
			DRV_ICC_GPTI_GetHandle(&SimCard->sim_nullByteIssueGPT);
#if 0
#ifdef SIM_HOT_SWAP_V2
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
#endif
        if(SimCard->gpt_handle == (kal_uint32)NULL)
			DRV_ICC_GPTI_GetHandle(&SimCard->gpt_handle);
		IRQSensitivity(hw_cb->mtk_lisrCode,LEVEL_SENSITIVE);
		IRQUnmask(hw_cb->mtk_lisrCode);

	}
#endif
	else
		ASSERT(0);
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
sim_status L1sim_Cmd_Layer_MTK(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize, sim_HW_cb *hw_cb, kal_bool *isSW6263)
{
	kal_bool warn, case4, sim_card, isSw6310 = KAL_FALSE;
	kal_uint8 sw1, sw2, error, gp, rs, *tx;
   kal_uint8 sim_get_resp_sim[] = {0xa0, 0xc0, 0x00, 0x00, 0x00 }; // 0xa0: SIM, 0x00: USIM
	sim_status status, status_w = 0;
	kal_uint32 rx_len,rx_buf_len;
	// sim_protocol_app_enum p = SimCard->app_proto;
	Sim_Card *SimCard;

	SimCard = GET_SIM_CB(hw_cb->simInterface);
	/* [MAUI_03035883]clear status word 0x62xx 0x63xx flag */
   *isSW6263 = KAL_FALSE;

	//dbg_print("L1sim_Cmd_Layer_MTK\r\n");
	if(rxData != NULL && *rxSize ==0)
	   rx_buf_len = 256;
	else
	   rx_buf_len = *rxSize;
	if(SimCard->cmd_case == usim_case_4)
	{
		case4 = KAL_TRUE;
		*txSize -= 1;   //the last byte is expected length of rxdata and shall not be sent
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
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC3, 0x00000009, drv_get_current_time(), case4, status_w, status);
			//sim_dump_fifo(hw_cb);
			status = SIM_SW_STATUS_FAIL;
			return status;
		}
		sw1 = status>>8;
		sw2 = status&0xff;
#if defined(SIM_DEBUG_INFO)
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC3, sim_card,warn,case4,status_w,status);
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC3, sim_get_resp_sim[0],error,*rxSize,rx_buf_len,rx_len);
		DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC3, rs,gp,sw1,sw2,status);
#endif
		if(sw1 == gp)
		{	// get response  0x61
#if defined(SIM_DEBUG_INFO)
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC4, sim_card,warn,case4,status_w,status);
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC4, sim_get_resp_sim[0],error,*rxSize,rx_buf_len,rx_len);
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC4, rs,gp,sw1,sw2,status);

			kal_sprintf(sim_dbg_str, "get response  %x\r\n", sw1);
			DRV_ICC_print_str(sim_dbg_str);
#endif
			if(rxData == NULL)
			{
#if defined(SIM_DEBUG_INFO)
				DRV_ICC_print_str("!!! ERR  NULL rx buffer\r\n");
#endif
				return status;
			}
			//add 9exx judegement
			if (sw1 == SW1_SIM_WARN1)
			{
#if defined(SIM_DEBUG_INFO)
				kal_sprintf(sim_dbg_str, "warning status %x %x\r\n", sw1, sw2);
				DRV_ICC_print_str(sim_dbg_str);
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
			{
			    *rxSize = rx_len; //*rxSize was used in every L1sim_Cmd, not a overall result, need to update it in the last
			    return status;
			}

			status = L1sim_Cmd(tx, LEN_OF_CMD, rxData, (kal_uint16*)rxSize, &error, hw_cb);
			if(error == KAL_TRUE){
				DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC3, 0x00000007,drv_get_current_time(),case4,status_w,status);
				status = SIM_SW_STATUS_FAIL;
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

			//dbg_print("0x6100 from SIM card");
			DRV_ICC_print(SIM_PRINT_6100_FROM_CARD, 0, 0, 0, 0, 0);
#endif

			if(rxData == NULL)
			{
#if defined(SIM_DEBUG_INFO)
				dbg_print("!!! ERR  NULL rx buffer \r\n");
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
			{
			    *rxSize = rx_len; //*rxSize was used in every L1sim_Cmd, not a overall result, need to update it in the last
			    return status;
			}

			status = L1sim_Cmd(tx, LEN_OF_CMD, rxData, (kal_uint16*)rxSize, &error, hw_cb);
			if(error == KAL_TRUE){
				status = SIM_SW_STATUS_FAIL;
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

			kal_sprintf(sim_dbg_str, "resend  command %x\r\n", sw1);
			DRV_ICC_print_str(sim_dbg_str);
#endif
			if(rxData == NULL)
			{
#if defined(SIM_DEBUG_INFO)
				DRV_ICC_print_str("!!! ERR  NULL rx buffer\r\n");
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
				DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC3, 0x00000010,drv_get_current_time(),case4,status_w,status);
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
		/*else if( !sim_card &&
                  case4 &&
			     (sw1 == SW1_WARN1 || sw1== SW1_WARN2 ||
			         ((status != SIM_SW_STATUS_OK )&& ((sw1&0xf0) == 0x90))
			      )
			    )*/
	    //mtk04122: modify condition for preventing recognizing normal ending status byte(0x92XX and 0x91XX) as error status
		else if(!sim_card && case4 &&
			     (sw1 == SW1_WARN1 || sw1== SW1_WARN2 || ((status != SIM_SW_STATUS_OK )&& ((sw1&0xf0) == 0x90) && (sw1!=0x91) && (sw1!=0x92))))
		{	// warning status
#if defined(SIM_DEBUG_INFO)
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC11, sim_card,warn,case4,status_w,status);
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC11, sim_get_resp_sim[0],error,*rxSize,rx_buf_len,rx_len);		
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC11, rs,gp,sw1,sw2,status);
			kal_sprintf(sim_dbg_str, "warning status %x %x\r\n", sw1, sw2);
			DRV_ICC_print_str(sim_dbg_str);
#endif
			// [MAUI_03035883]set status word 0x62xx 0x63xx flag
			*isSW6263 = KAL_TRUE; //set 0x62xx 0x63xx flag
#if defined (DTAG_WALLET_V1)
			if(sw1 == SW1_WARN2 && sw2 == 0x10)
			{
				isSw6310 = KAL_TRUE;
				// [ALPS00459948]Review DTAG requirement for multipart APDUs
				// If we enconter status 0x6310, it is specific for DTAG wallet development
				// we just return status to sim task and let ril drive to send get response
				kal_sprintf(sim_dbg_str,"sw1:%x, isSW6263:%d, warn:%d, isSW6310:%d, status:%x", sw1, *isSW6263, warn, isSw6310, status);
				DRV_ICC_print_str(sim_dbg_str);
				// *rxSize = rx_len; // *rxSize was used in every L1sim_Cmd, not a overall result, need to update it in the last
				// return status;
			}
#endif
#if defined(SIM_BY_PASS_6310)
			if(sw1 == SW1_WARN2 && sw2 == 0x10 && *rxSize != 0)
			{
				*rxSize = rx_len; // *rxSize was used in every L1sim_Cmd, not a overall result, need to update it in the last
				kal_sprintf(sim_dbg_str,"1.CLA:%x, INS:%x, isSW6263:%d, warn:%d, rx_len:%d, *rxSize:%x", *txData, *(txData + 1), *isSW6263, warn, rx_len, *rxSize);
				DRV_ICC_print_str(sim_dbg_str);
				return 0x6310;
			} else
			{
				kal_sprintf(sim_dbg_str,"[ERR]CLA:%x, INS:%x, isSW6263:%d, warn:%d, rx_len:%d, *rxSize:%x", *txData, *(txData + 1), sw1, sw2, rx_len, *rxSize);
				DRV_ICC_print_str(sim_dbg_str);
			}
#endif
			warn = KAL_TRUE;
			status_w = status;
			tx = sim_get_resp_sim;
			if(sw1 == SW1_WARN2 && sw2 == 0x10)
			{
				status_w = 0x6310;	
			}
#if defined(SIM_DEBUG_INFO)
			kal_sprintf(sim_dbg_str,"DBG sw1:%x, isSW6263:%d, warn:%d, isSW6310:%d, status:%x", sw1, *isSW6263, warn, isSw6310, status_w);
			DRV_ICC_print_str(sim_dbg_str);
#endif
			tx[LEN_INDEX] = 0;
			if(sw1 == SW1_WARN2 && sw2 == 0x10)
			{	
				*rxSize = 256;
			} else
			{
				*rxSize = 0;
			}
			status = L1sim_Cmd(tx, LEN_OF_CMD, rxData, (kal_uint16*)rxSize, &error, hw_cb);
			if(error == KAL_TRUE){
				DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC3, 0x00000011,drv_get_current_time(),case4,status_w,status);
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
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC12, sim_card,warn,case4,status_w,status);
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC12, sim_get_resp_sim[0],error,*rxSize,rx_buf_len,rx_len);
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC12, rs,gp,sw1,sw2,status);
#endif
		}
		else
		{	// command complete
#if defined(SIM_DEBUG_INFO)
			kal_sprintf(sim_dbg_str, "command complete %x\r\n", status);
			DRV_ICC_print_str(sim_dbg_str);
#endif
			ASSERT(rx_len <= rx_buf_len);

			*rxSize = rx_len; //*rxSize was used in every L1sim_Cmd, not a overall result, need to update it in the last
#if defined(SIM_DEBUG_INFO)
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC13, sim_card,warn,case4,status_w,status);
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC13, sim_get_resp_sim[0],error,*rxSize,rx_buf_len,rx_len);
			DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC13, rs,gp,sw1,sw2,status);
#endif
			if(warn == KAL_TRUE || isSw6310 == KAL_TRUE)
			{
				kal_sprintf(sim_dbg_str,"DBG2 sw1:%x, sw2:%x, isSW6263:%d, warn:%d, isSW6310:%d, status:%x", sw1, sw2, *isSW6263, warn, isSw6310, status_w);
				DRV_ICC_print_str(sim_dbg_str);
				DRV_ICC_print(SIM_PRINT_L1SIM_CMD_TRC3, 0x00000012, drv_get_current_time(), case4, status_w, status);
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

	return status;
}
//================================ Layer type SIM driver end ==================================
//================================For engineer mode start =======================
#ifndef DRV_SIM_ALL_SOLUTION_BUILT
void SIM1_LDO_enable(kal_bool enable)
{
#ifdef PMIC_6238_REG_API
#ifdef __OLD_PDN_ARCH__
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
#else
   if (enable == KAL_TRUE)
   {
#if defined(LPWR_SLIM)
      PDN_CLR(PDN_SIM); //power up dev
	  SleepDrv_SleepDisable(hw_cb->smHandler); //lock sleep mode
#else
      DRVPDN_Disable(PDN_SIM);
#endif

   }
   else
   {
#if defined(LPWR_SLIM)
	   PDN_SET(PDN_SIM); //power down dev
	   SleepDrv_SleepEnable(hw_cb->smHandler);  //unlock sleep mode      
#else
      DRVPDN_Enable(PDN_SIM);;
#endif
   }
#endif
#endif /* PMIC_6238_REG_API */
}

void SIM2_LDO_enable(kal_bool enable)
{
#ifdef PMIC_6238_REG_API
#ifdef __OLD_PDN_ARCH__
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
#else
   if (enable == KAL_TRUE)
   {
#if defined(LPWR_SLIM)
      PDN_CLR(PDN_SIM2); //power up dev
	  SleepDrv_SleepDisable(hw_cb->smHandler); //lock sleep mode
#else
      DRVPDN_Disable(PDN_SIM2);
#endif
   }
   else
   {
#if defined(LPWR_SLIM)
	   PDN_SET(PDN_SIM2); //power down dev
	   SleepDrv_SleepEnable(hw_cb->smHandler);  //unlock sleep mode    
#else
      DRVPDN_Enable(PDN_SIM2);;
#endif
   }
#endif
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
	result = sim_Reset_MTK(SIM_30V,&resVolt,&ATRInfo);
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
		//SIM_Reject_MTK();
		//dbg_print("SIM is closed!!\r\n");
		#endif
}
#endif /* DEVDRV_TEST */

#endif
#endif //DRV_MULTIPLE_SIM
#endif //__MTK_TARGET__
#endif /*__SIM_DRV_MULTI_DRV_ARCH__*/

#endif //DRV_SIM_OFF
