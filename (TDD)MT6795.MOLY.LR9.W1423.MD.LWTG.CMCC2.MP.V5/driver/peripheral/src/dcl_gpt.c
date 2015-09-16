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
 *    dcl_gpt.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the GPT driver.
 *
 * Author:
 * -------
 * -------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_gpt.h"
#include "drv_comm.h"
#include "gpt_hw.h"
#include "dcl_gpt_hw.h"
#include "dcl_gpt.h"
#include "dcl.h"
#include "drv_hisr.h"
#include "us_timer.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "drvpdn.h"
#include "l1_interface.h"
#include "drv_trc.h"

//#define DCL_GPT_INTERFACE
//#ifdef  DCL_GPT_INTERFACE

#if !defined(DRV_GPT_OFF)

//DCL_GPT_CB  this software gpt provide register callback function.
#define DCL_GPT_CB_MAGIC_NUM  							0x02000000
#define DCL_GPT_CB_IS_HANDLE_MAGIC(handl_)  ((handl_)& DCL_GPT_CB_MAGIC_NUM)
#define DCL_GPT_CB_GET_DEV(handle_) 				((handle_) & (~DCL_GPT_CB_MAGIC_NUM))

//DCL_GPT_CB2  this software gpt provide register callback function.
#define DCL_GPT_CB2_MAGIC_NUM  							0x10000000
#define DCL_GPT_CB2_IS_HANDLE_MAGIC(handl_)  ((handl_)& DCL_GPT_CB2_MAGIC_NUM)
#define DCL_GPT_CB2_GET_DEV(handle_) 				((handle_) & (~DCL_GPT_CB2_MAGIC_NUM))

//DCL_GPT_CB_MS  this software gpt provide register callback function.
#define DCL_GPT_CB_MS_MAGIC_NUM  					 0x20000000
#define DCL_GPT_CB_MS_IS_HANDLE_MAGIC(handl_)       ((handl_)& DCL_GPT_CB_MS_MAGIC_NUM)
#define DCL_GPT_CB_MS_GET_DEV(handle_) 				((handle_) & (~DCL_GPT_CB_MS_MAGIC_NUM))


//DCL_GPT_BW this software gpt provide busywait function.
#define DCL_GPT_BW_MAGIC_NUM  							0x04000000
#define DCL_GPT_BW_IS_HANDLE_MAGIC(handl_) 	((handl_)& DCL_GPT_BW_MAGIC_NUM)
#define DCL_GPT_BW_GET_DEV(handle_) 				((handle_) & (~DCL_GPT_BW_MAGIC_NUM))

//DCL_FGPT this software gpt provide return free run gpt value function.
#define DCL_FGPT_MAGIC_NUM    						 0x08000000
#define DCL_FGPT_IS_HANDLE_MAGIC(handl_) 	 ((handl_)& DCL_FGPT_MAGIC_NUM)
#define DCL_FGPT_GET_DEV(handle_) 				 ((handle_) & (~DCL_FGPT_MAGIC_NUM))

//this define may fadeout.
#define  GPTProcess(module)   \
{\
   if((GPTTimer.status & (1<<module))&&(GPTTimer.GPT_TICK == GPTTimer.GPTItems[module].tick))\
   {\
      GPTTimer.status &= ~(1<<module);\
      GPTTimer.GPTItems[module].gptimer_func(GPTTimer.GPTItems[module].parameter);\
   }\
}

static kal_bool is_gpt2_open = KAL_FALSE;


/*[start]******************SRAM or Cache select part1*****************/
#if 0
/* under construction !*/
#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
/* under construction !*/
/* under construction !*/
#else // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
/* under construction !*/
  #ifdef GPT_INTERNAL_SRAM
/* under construction !*/
  #endif
#endif // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
#endif
/*[end]******************SRAM or Cache select part1 end *****************/

//This global variable contain software gpt control information. -->debug sabre!!
#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported, put GPT data into cahched region
  __attribute__ ((section ("CACHEDZI")))
#else // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported, put GPT data into internal SRAM
  #ifdef GPT_INTERNAL_SRAM
  __attribute__ ((section ("INTSRAM_ZI")))
  #endif
#endif // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)

GPTStruct GPTTimer;
/*----------------------------*/
/* add for 1ms gpt */
#define GPT_MS_MAX_USER 5   /* we just support max 5 users */
volatile kal_uint16 gpt_ms_handle_status = 0;
volatile kal_uint16 gpt_ms_lisr_handle_status = 0;
volatile kal_uint16 gpt_ms_hisr_handle_status = 0;
volatile kal_uint16 gpt_ms_running_status = 0;
DCL_HANDLE gpt_ms_handle;
GPT_MS_Struct  GPT_MS_Timer[GPT_MS_MAX_USER];

/*----------------------------*/


//[Software bug  fix]This global variable is to complete buzywait control flow.  [Interrupt may send out before read GPT_STA]

#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported, put GPT data into cahched region
  __attribute__ ((section ("CACHEDZI")))
#else // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported, put GPT data into internal SRAM
  #ifdef GPT_INTERNAL_SRAM
  __attribute__ ((section ("INTSRAM_ZI")))
  #endif
#endif // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)

volatile kal_bool BusyWaitFlag;

//[hardware bug fix] GPT3 register synchronism problem.[register may changing while APB bus fetching value]
#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported, put GPT data into cahched region
  __attribute__ ((section ("CACHEDZI")))
#else // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported, put GPT data into internal SRAM
  #ifdef GPT_INTERNAL_SRAM
  __attribute__ ((section ("INTSRAM_ZI")))
  #endif
#endif // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)

int testcount=0;

//[System fixing] GPT should disable sleep mode for L1 layer restrict~!
#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported, put GPT data into cahched region
  __attribute__ ((section ("CACHEDZI")))
#else // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported, put GPT data into internal SRAM
  #ifdef GPT_INTERNAL_SRAM
  __attribute__ ((section ("INTSRAM_ZI")))
  #endif
#endif // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)

static kal_uint8 gpt_sm_handle;
#endif // #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
#endif //#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)

#if 0
/* under construction !*/
#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
/* under construction !*/
#else // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  #ifdef GPT_INTERNAL_SRAM
/* under construction !*/
  #endif
#endif // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
#endif
/*[end]*******************SRAM or Cache select part end*****************/

void GPTI_HISR(void);
void GPT_MS_HISR(void);

static kal_bool GPTI_StartItem(kal_uint8 module,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter);
static kal_bool GPT_MS_StartItem(kal_uint8 module,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter);
static kal_bool GPT_MS_StopItem(kal_uint8 module);
static void GPTI_StopItem(kal_uint8 module);
static void GPTI_BusyWait(kal_uint16 len);

extern void SleepDrv_SleepDisable(kal_uint8 handle);
extern void SleepDrv_SleepEnable(kal_uint8 handle);
//extern void SleepDrv_UnIRQSleepEnable( kal_uint8 handle );
//extern void SleepDrv_UnIRQSleepDisable( kal_uint8 handle );

extern kal_uint8 SleepDrv_GetHandle(void);
static void gpt_sw_delay(void);

/*[start]***********************************debug informaiton *****************************/
#if defined(__MTK_INTERNAL__) && !defined(LOW_COST_SUPPORT) && !defined(__MAUI_BASIC__) && defined(__DRV_DBG_MEMORY_TRACE_SUPPORT__)

#define MAX_GPT_HISR_DBG_INFO_SIZE 128
typedef struct
{
	kal_uint16      tag;
   kal_uint32      time;
   kal_uint32      time2;
} GPT_HISR_DBG_DATA;
typedef struct{
   GPT_HISR_DBG_DATA   	dbg_data[MAX_GPT_HISR_DBG_INFO_SIZE];
   kal_uint16     		dbg_data_idx;
}
GPT_HISR_DBG_STRUCT;

GPT_HISR_DBG_STRUCT	GPT_HISR_DBG_INFO_DATA;
#define GPT_DBG(a,b) GPT_hisr_dbg_trace(a,b);
void GPT_hisr_dbg_trace(kal_uint32 index, kal_uint32 time)
{
    kal_uint32 savedMask;
    kal_uint32      time2;
    savedMask = SaveAndSetIRQMask();
    GPT_HISR_DBG_INFO_DATA.dbg_data[GPT_HISR_DBG_INFO_DATA.dbg_data_idx&(MAX_GPT_HISR_DBG_INFO_SIZE  - 1)].tag = (kal_uint16)index;
    GPT_HISR_DBG_INFO_DATA.dbg_data[GPT_HISR_DBG_INFO_DATA.dbg_data_idx&(MAX_GPT_HISR_DBG_INFO_SIZE  - 1)].time = time;

    time2 = drv_get_current_time();
    GPT_HISR_DBG_INFO_DATA.dbg_data[GPT_HISR_DBG_INFO_DATA.dbg_data_idx&(MAX_GPT_HISR_DBG_INFO_SIZE  - 1)].time2 = time2;

    GPT_HISR_DBG_INFO_DATA.dbg_data_idx++;
    RestoreIRQMask(savedMask);
    /*
    kal_prompt_trace(MOD_DRVKBD, "index=%d, time=%d, time2=%d", index, time, time2);
	*/
}
#else
#define GPT_DBG(a,b) ;
#endif
/*[end]***********************************debug informaiton end *****************************/

/*-----------------------------------------------------------------------*
*																		    
*						GPT1 LISR function,								    
*				pass to gpt_hw layer as a function pointer 						    
*																		    
*------------------------------------------------------------------------*/
void GPTI_Callback(DCL_EVENT timeout)
{
	 drv_active_hisr(DRV_GPT_HISR_ID);
}

/*-----------------------------------------------------------------------*
*							GPT2 LISR function.							   
*																		   
*		the exist of this funciton is to round over busywait control flow.				    
*
*------------------------------------------------------------------------*/
void GPT2_Callback(DCL_EVENT timeout)
{
	//BusyWaitFlag=KAL_TRUE;
	drv_active_hisr(DRV_GPT_MS_HISR_ID);
} 

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_Initialize
*
* DESCRIPTION
*  This function is to initialize SW GPT module. 
*
* PARAMETERS
*	DCL_STATUS_OK
*
* RETURNS
*  none
*
*------------------------------------------------------------------------*/
DCL_STATUS DclSGPT_Initialize(void)
{
	//DCL_HANDLE gpt2;
	HGPT_CTRL clock;
	HGPT_CTRL set_gpt;

	#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
	#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
	gpt_sm_handle = SleepDrv_GetHandle();
	#endif // #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
	#endif //#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
	//PDN_CLR(PDN_GPT);

	clock.rHGPTClk.u4Clock=CLK_1K;
	set_gpt.rHGPTReset.u2CountValue=9;
	set_gpt.rHGPTReset.fgAutoReload=KAL_TRUE;

	//register HISR.
	if (GPTTimer.hisr == NULL)
	{
		GPTTimer.hisr= (void*)0x1234;
		DRV_Register_HISR(DRV_GPT_HISR_ID, GPTI_HISR);
	}  

	//open GPT1 and set control register.
	DclHGPT_Initialize();
	GPTTimer.Hgpt_handle=DclHGPT_Open(GPT1,0);
	DclHGPT_Control(GPTTimer.Hgpt_handle,HGPT_CMD_CLK,&clock);
	DclHGPT_Control(GPTTimer.Hgpt_handle,HGPT_CMD_RESET,&set_gpt);
	DclHGPT_RegisterCallback(GPTTimer.Hgpt_handle,EVENT_HGPT_TIMEOUT,GPTI_Callback);
	DclHGPT_Close(GPTTimer.Hgpt_handle);

	//global variable initialization.
	GPTTimer.GPT_TICK = 0;
	GPTTimer.MAX_GPTIMER_ITEMS = 0;
	GPTTimer.GPTSTOP = KAL_TRUE;
	GPTTimer.status =0;
	{
		kal_uint32 i;
		for (i=0;i<32;i++)
		{
			GPTTimer.GPTUsed[i] = 0;
		}
	}

	//gpt2 initialization.
	clock.rHGPTClk.u4Clock=CLK_1K;
	gpt_ms_handle=DclHGPT_Open(GPT2,0);	
	DclHGPT_Control(gpt_ms_handle,HGPT_CMD_CLK,&clock);
	
	set_gpt.rHGPTReset.u2CountValue=0;
	set_gpt.rHGPTReset.fgAutoReload=KAL_TRUE;
	DclHGPT_Control(gpt_ms_handle,HGPT_CMD_RESET,&set_gpt);
	
	DclHGPT_RegisterCallback(gpt_ms_handle,EVENT_HGPT_TIMEOUT,GPT2_Callback);
	//DclHGPT_Close(gpt_ms_handle);
	DRV_Register_HISR(DRV_GPT_MS_HISR_ID, GPT_MS_HISR);
	//*((volatile kal_uint32 *)(0x80000454)) |= 0x00000080;//pdn
	//PDN_SET(PDN_GPT);

	return STATUS_OK;
}

/*-----------------------------------------------------------------------
* FUNCTION
*  DclSGPT_Open
*
* DESCRIPTION
*  This function is to open the SW GPT module and get a handle. Note that 
* multiple opens are allowed.
*
* PARAMETERS
*	eDev - only valid for DCL_GPT1
*	flags - no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*	DCL_HANDLE_INVALID - Open failed.
*  other value - a valid handle
*
*------------------------------------------------------------------------*/
DCL_HANDLE DclSGPT_Open(DCL_DEV eDev, DCL_FLAGS flags)
{
   kal_uint8 handle;
   kal_uint32 savedMask;
   kal_uint32 i;
   if (DCL_GPT_CB==eDev)
   {
		savedMask = SaveAndSetIRQMask();
      for (i=0;i<32;i++)
	  	{
			if (GPTTimer.GPTUsed[i] == 0)
			{
				GPTTimer.GPTUsed[i] = 1;
				handle =i;
				GPTTimer.MAX_GPTIMER_ITEMS ++;
				RestoreIRQMask(savedMask);
				return DCL_GPT_CB_MAGIC_NUM|handle;
			}
		}
		RestoreIRQMask(savedMask);
		// The case that we do NOT return in the loop:
		// Indicate there is NO GPT handle!!!!!
		ASSERT(0);
		// return invalid handle
		return DCL_HANDLE_INVALID;
	}
   else if(DCL_GPT_CB2 == eDev)
   	{
		return DCL_HANDLE_INVALID;//for 1ms gpt, we will use gpt2, so,we not support this dev
	}
/*-----------------------------------------------------------------------*/
/* add for 1ms gpt */
	else if(DCL_GPT_CB_MS == eDev || DCL_GPT_CRITICAL_CB_MS == eDev)
	{
		savedMask = SaveAndSetIRQMask();
		for (i=0;i<GPT_MS_MAX_USER;i++)
		{
			if ((gpt_ms_handle_status & (0x1 << i))== 0)
                 {
				gpt_ms_handle_status |= (0x1 << i);
				if(DCL_GPT_CB_MS == eDev){
					gpt_ms_hisr_handle_status |= (0x1 << i);}
				else if(DCL_GPT_CRITICAL_CB_MS == eDev){
					gpt_ms_lisr_handle_status |= (0x1 << i);}
				handle =i;
				RestoreIRQMask(savedMask);
				return DCL_GPT_CB_MS_MAGIC_NUM|handle;
                  }
		}
		RestoreIRQMask(savedMask);
		ASSERT(0);
		// return invalid handle
			return DCL_HANDLE_INVALID;
   	}
/*-----------------------------------------------------------------------*/
   else if(DCL_GPT_BusyWait==eDev)
   {
		return DCL_GPT_BW_MAGIC_NUM |eDev;
   }
   else
   {
		//invaild GPT DCL_DEV type.
		ASSERT(0);
		return DCL_HANDLE_INVALID;
   }
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_ReadData
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_WriteData
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_Configure
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
   return STATUS_UNSUPPORTED;
}


/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
   return STATUS_UNSUPPORTED;
}


/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_Control
*
* DESCRIPTION
*  This function is to send command to control the SW GPT module.
*
* PARAMETERS
*	handle - a valid handle return by DclSGPT_Open()
*  cmd   - a control command for GPT module
*          1. SGPT_CMD_START: to start a GPT timer
*          2. SGPT_CMD_STOP: to stop a GPT timer
*  data - for 1. SGPT_CMD_START: pointer to a SGPT_CTRL_START_T structure
*             2. SGPT_CMD_STOP: a NULL pointer
*
* RETURNS
*	STATUS_OK - command is executed successfully.
*	STATUS_FAIL - command is failed.
*  STATUS_INVALID_CMD - It's a invalid command.
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	
	DCL_UINT8 gpt_handle=0;
	//DCL_UINT32 gpt2_handle = 0;
	gpt_handle=DCL_GPT_CB_GET_DEV(handle) & 0xFF;
	
	if(DCL_GPT_CB_IS_HANDLE_MAGIC(handle))
	{
		switch(cmd)
		{
			case SGPT_CMD_START:
			{
				kal_bool ret_b;
	      	SGPT_CTRL_START_T  *prStart;
	
	     		prStart = &(data->rSGPTStart);
				//test if callback function is null.
				if(NULL==prStart->pfCallback)
					ASSERT(0);
	     		ret_b = GPTI_StartItem(gpt_handle, prStart->u2Tick, prStart->pfCallback, prStart->vPara);
	     		if(ret_b == KAL_TRUE)
	         	return STATUS_OK;
	      	else
	         	return STATUS_FAIL;
				}
				//break; we can return in any case.
			case SGPT_CMD_STOP:
	      	GPTI_StopItem(gpt_handle);
	      	return STATUS_OK;
			default:
				ASSERT(0);
      		return STATUS_INVALID_CMD;
	   }
	}

	else if(DCL_GPT_CB2_IS_HANDLE_MAGIC(handle))
	{
		return STATUS_FAIL;  /* from 1ms gpt, we not support SGPT2_CMDxx */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
	}
	else if(DCL_GPT_CB_MS_IS_HANDLE_MAGIC(handle))
	{
		 switch(cmd)
		 {
			 case SGPT_CMD_START:
			 {
				kal_bool ret_b;
			 	SGPT_CTRL_START_T	*prStart;
		
				prStart = &(data->rSGPTStart);
				ASSERT(NULL!=prStart->pfCallback);
				 ret_b = GPT_MS_StartItem(gpt_handle, prStart->u2Tick, prStart->pfCallback, prStart->vPara);
				 if(ret_b == KAL_TRUE)
				 	return STATUS_OK;
			 	 else
				 	return STATUS_FAIL;
			}
				 //break; we can return in any case.
			 case SGPT_CMD_STOP:
			 GPT_MS_StopItem(gpt_handle);
			 return STATUS_OK;
			 default:
				 ASSERT(0);
			 return STATUS_INVALID_CMD;
		}
	}
	else if(DCL_GPT_BW_IS_HANDLE_MAGIC(handle))
	{
		switch(cmd)
		{
			case SGPT_CMD_BUSYWAIT:
			{
				GPTI_BusyWait(data->uBusyWaitcount);
			}
			break;
			default:
				ASSERT(0);
      		return STATUS_INVALID_CMD;			
		}
		return STATUS_OK;
	}
	else
	{
		//if assert happen here, that means DCL_HANDLE pass in is wrong!
		ASSERT(0);
		return DCL_HANDLE_INVALID;
	}
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_Close
*
* DESCRIPTION
*  This function is to close the SW GPT module.
*
* PARAMETERS
*	handle  - hanlde previous got from DclSGPT_Open()
*
* RETURNS
*	DCL_STATUS_OK - successfully close the SW GPT module.
*	DCL_STATUS_fail - fails to close the SW GPT module.
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_Close(DCL_HANDLE *handle)
{
	DCL_UINT8 gpt_handle;
	kal_uint32 savedMask;
	gpt_handle=DCL_GPT_CB_GET_DEV(*handle) & 0xFF;	
	
	if(DCL_GPT_CB_IS_HANDLE_MAGIC(*handle))
	{

		if(GPTTimer.GPTSTOP!=KAL_TRUE)
			GPTI_StopItem(gpt_handle);
		// Make sure the GPT handle is activated
		ASSERT(GPTTimer.GPTUsed[gpt_handle]);		
		savedMask = SaveAndSetIRQMask();
		GPTTimer.GPTUsed[gpt_handle] = 0;
		GPTTimer.MAX_GPTIMER_ITEMS --;	
		RestoreIRQMask(savedMask);
		*handle=0x7F;
		return STATUS_OK;
	}
	else if(DCL_GPT_CB2_IS_HANDLE_MAGIC(*handle))
	{
		//is_gpt2_open = KAL_FALSE;
		return STATUS_OK;
	}
	if(DCL_GPT_CB_MS_IS_HANDLE_MAGIC(*handle))
	{

		if(0 != (gpt_ms_running_status & (0x1 << gpt_handle))){
			GPT_MS_StopItem(gpt_handle);}
		// Make sure the GPT handle is activated
		ASSERT(gpt_ms_handle_status & (0x1 << gpt_handle));		
		savedMask = SaveAndSetIRQMask();
		gpt_ms_handle_status &= ~(0x1 << gpt_handle);
		gpt_ms_hisr_handle_status &= ~(0x1 << gpt_handle);
		gpt_ms_lisr_handle_status &= ~(0x1 << gpt_handle);
		RestoreIRQMask(savedMask);
		*handle=0x7F;
		return STATUS_OK;
	}
	else if(DCL_GPT_BW_IS_HANDLE_MAGIC(*handle))
	{
		return STATUS_OK;
	}
	else
	{
		ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclFGPT_Initialize
*
* DESCRIPTION
*  This function is to initialize the free run GPT module.
*
* PARAMETERS
*	None
*
* RETURNS
*	DCL_STATUS_OK
*
*------------------------------------------------------------------------*/

DCL_STATUS DclFGPT_Initialize(void)
{
	DclFHGPT_Initialize();
	return STATUS_OK;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclFGPT_Open
*
* DESCRIPTION
*  This function is to open a free run GPT module if it exists. Note 
* that it supports multiple opens and no need to close it.
*
* PARAMETERS
*	eDev - only valid for DCL_GPT3
*	flags - no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*	DCL_HANDLE_INVALID - Open failed. It means no free run GPT exists or 
*                       open a wrong device.
*  other value - a valid handle
*
*------------------------------------------------------------------------*/

DCL_HANDLE DclFGPT_Open(DCL_DEV eDev, DCL_FLAGS flags)
{
	#if defined(DRV_GPT_GPT3)
	if(DCL_GPT_FreeRUN3==eDev)
		return DCL_FGPT_MAGIC_NUM|eDev;
	#endif
	#if defined(DRV_GPT_GPT4)
	if(DCL_GPT_FreeRUN4==eDev)
		return DCL_FGPT_MAGIC_NUM|eDev;
   #endif
	{
		ASSERT(0);
   	return DCL_HANDLE_INVALID;
	}
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclFGPT_ReadData
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclFGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclFGPT_WriteData
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclFGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclFGPT_Configure
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclFGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclFGPT_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclFGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclFGPT_Control
*
* DESCRIPTION
*  This function is to send command to control the free run GPT module.
*
* PARAMETERS
*	handle - a valid handle return by DclFGPT_Open()
*  cmd   - a control command for free ryb GPT module
*          FGPT_CMD_RETURN_COUNT: to get the timer count
*  data - for FGPT_CMD_RETURN_COUNT: pointer to a FGPT_CTRL_RETURN_COUNT_T type
*
* RETURNS
*	STATUS_OK - command is executed successfully.
*	STATUS_FAIL - command is failed. No free run GPT is supported.
*  STATUS_INVALID_CMD - The command is invalid.
*  STATUS_INVALID_HANDLE - The handle is invalid.
*
*------------------------------------------------------------------------*/

DCL_STATUS DclFGPT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
   DCL_DEV  eDev;
   DCL_HANDLE gpt_handle;

   if (!DCL_FGPT_IS_HANDLE_MAGIC(handle))
   {
      ASSERT(0);
      return STATUS_INVALID_DCL_HANDLE;
   }
   eDev = DCL_FGPT_GET_DEV(handle);
   #if defined(DRV_GPT_GPT3)
   if(DCL_GPT_FreeRUN3==eDev)
   	{
   		switch(cmd)
   		{
   			case FGPT_CMD_START:
				{
					gpt_handle=DclFHGPT_Open(GPT3,0);
					DclFHGPT_Control(gpt_handle,FHGPT_CMD_START,0);
					DclFHGPT_Close(gpt_handle);
				}
				break;
   			case FGPT_CMD_STOP:
				{
					gpt_handle=DclFHGPT_Open(GPT3,0);
					DclFHGPT_Control(gpt_handle,FHGPT_CMD_STOP,0);
					DclFHGPT_Close(gpt_handle);
				}
				break;
				case FGPT_CMD_RETURN_COUNT:
				{
					HGPT_CTRL value;
					gpt_handle=DclFHGPT_Open(GPT3,0);
					DclFHGPT_Control(gpt_handle,FHGPT_CMD_RETURN_COUNT,&value);
					data->u2RetCount=value.u2RetCount;
					DclFHGPT_Close(gpt_handle);					
				}
				break;
			  default:
	      	  ASSERT(0);
	      	  return STATUS_INVALID_CMD;
			} 
			return STATUS_OK;
	  }
	#endif
	#if defined(DRV_GPT_GPT4)
  	if(DCL_GPT_FreeRUN4==eDev)
  	{
   		switch(cmd)
   		{
   			case FGPT_CMD_START:
				{
					gpt_handle=DclFHGPT_Open(GPT4,0);
					DclFHGPT_Control(gpt_handle,FHGPT_CMD_START,0);
					DclFHGPT_Close(gpt_handle);
				}
				break;
   			case FGPT_CMD_STOP:
				{
					gpt_handle=DclFHGPT_Open(GPT4,0);
					DclFHGPT_Control(gpt_handle,FHGPT_CMD_STOP,0);
					DclFHGPT_Close(gpt_handle);
				}
				break;
   			case FGPT_CMD_RETURN_COUNT:
				{
					HGPT_CTRL value;
					gpt_handle=DclFHGPT_Open(GPT4,0);
					DclFHGPT_Control(gpt_handle,FHGPT_CMD_RETURN_COUNT,&value);
					data->u2RetCount=value.u2RetCount;
					DclFHGPT_Close(gpt_handle);					
				}
				break;
				default:
      			ASSERT(0);
					return STATUS_INVALID_CMD;  		
  	  }
  	  return STATUS_OK;
    }
	#endif
	ASSERT(0);
	return DCL_HANDLE_INVALID;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclFGPT_Close
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclFGPT_Close(DCL_HANDLE handle)
{
   return STATUS_UNSUPPORTED;
}
#if 0
#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
/* under construction !*/
#else // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
/* under construction !*/
#ifdef GPT_INTERNAL_SRAM
/* under construction !*/
#endif
#endif // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
#endif
/*-----------------------------------------------------------------------

* FUNCTION                                                            
*	GPTI_StartItem
*
* DESCRIPTION                                                           
*   	GPT start a item.
*
* CALLS  
*
* PARAMETERS
*	moudle = UART_Module, SIM_Module, GPT_Module
*	tick = the delay(the unit is 10ms)
*  gptimer_func = the callback function when the tick is reached.
*  parameter = the parameter inputed into gptimer_func
*
* RETURNS
*	KAL_TRUE, start item successfully
*  KAL_FALSE, start item fail
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/
#if defined(__ENABLE_GPT_PROTECTION__)

#error "this macro should not be defined "
      #else
	 
static void gpt_sw_delay(void)
   {
	ust_busy_wait(95);//delay three 32K ticks for HW limitation. we should avoid two case: 1, start after start. 2,start after stop.
}
void gpt_ms_sw_delay(kal_uint32 ticks)
{
	ust_busy_wait(ticks);
}


#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported the code is put into cached region
#else // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // Put the code into internal SRAM
#ifdef GPT_INTERNAL_SRAM
__attribute__ ((section ("INTSRAM_ROCODE")))
#endif
#endif // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)

static kal_bool GPTI_StartItem(kal_uint8 module,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter)
{
   kal_uint32 savedMask;  
   // Clear magic number
   //module &= ~(GPT_HANDLE_MAGIC_NUM);
   if (GPTTimer.status & (1<<module))
   {
      return KAL_FALSE;
   }
   
   GPTTimer.GPTItems[module].tick = GPTTimer.GPT_TICK+tick;
   GPTTimer.GPTItems[module].gptimer_func = gptimer_func;
   GPTTimer.GPTItems[module].parameter = parameter;
   //kal_prompt_trace(MOD_DRVKBD, "--GPT start Item-- module:%d,tick:%d,callback:%x", module, tick,gptimer_func);
   savedMask = SaveAndSetIRQMask();
   GPTTimer.status |= (1<<module);
   
   //module_test_print("GPTI_StartItem module %x,%x\r\n",module, GPTTimer.GPTItems[module].tick);
   if(KAL_TRUE==GPTTimer.GPTSTOP)
   	{
   		GPTTimer.GPTSTOP=KAL_FALSE;
   		//Is there any race condition.....
   		if ((GPTTimer.GPTSTOP) == KAL_FALSE)
			{
   				RestoreIRQMask(savedMask);
			        gpt_sw_delay();//delay 3 32K ticks for hw limitation
	   	  	       	savedMask = SaveAndSetIRQMask();
                                     GPTTimer.Hgpt_handle=DclHGPT_Open(GPT1,0);			
				DclHGPT_Control(GPTTimer.Hgpt_handle,HGPT_CMD_START,0);
			}
   	}
    RestoreIRQMask(savedMask);
 
//toy separate GPT and SleepDrv function 
	#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
	#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
	   savedMask = SaveAndSetIRQMask();
	   if (KAL_FALSE== (GPTTimer.GPTSTOP))
			SleepDrv_SleepDisable(gpt_sm_handle);
	   RestoreIRQMask(savedMask);
	#endif
	#endif	
   return KAL_TRUE;
}

/*-----------------------------------------------------------------------

* FUNCTION                                                            
*	GPTI_StopItem
*
* DESCRIPTION                                                           
*   	GPT stop a item.
*
* CALLS  
*
* PARAMETERS
*	moudle = UART_Module, SIM_Module, GPT_Module
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/

#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // If cache is supported the code is put into cached region
#else // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
  // Put the code into internal SRAM
#ifdef GPT_INTERNAL_SRAM
__attribute__ ((section ("INTSRAM_ROCODE")))
#endif
#endif // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)

static void GPTI_StopItem(kal_uint8 module)
{
   register kal_uint32 savedMask;
   // Clear magic number
   //module &= ~(GPT_HANDLE_MAGIC_NUM);
   savedMask = SaveAndSetIRQMask();
   GPTTimer.status &= ~(1<<module);
   if(0==GPTTimer.status)
   {
	GPTTimer.GPTSTOP=KAL_TRUE;
    	GPTTimer.GPT_TICK=0;
	//GPTTimer.Hgpt_handle=0;
	RestoreIRQMask(savedMask);
	savedMask = SaveAndSetIRQMask();
	//as open is there any race condition.
	if((GPTTimer.GPTSTOP) == KAL_TRUE)
	{
		RestoreIRQMask(savedMask);
		DclHGPT_Control(GPTTimer.Hgpt_handle,HGPT_CMD_STOP,0);
		gpt_sw_delay();//delay 3 32K ticks for hw limitation
		savedMask = SaveAndSetIRQMask();
		DclHGPT_Close(GPTTimer.Hgpt_handle);
		//GPTTimer.Hgpt_handle=0;
  	}
   }
   RestoreIRQMask(savedMask);
	//toy separate GPT and SleepDrv function 
	#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
   #if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
   savedMask = SaveAndSetIRQMask();
   if (KAL_TRUE == GPTTimer.GPTSTOP)
   {
		//if(KAL_TRUE==GPT_IsStop())// for 1ms gpt,dongming remove if, because we should ensure only gpt1 can lock/unlock sleep
			SleepDrv_SleepEnable(gpt_sm_handle);
   }
   RestoreIRQMask(savedMask);
	#endif
	#endif
}
#if 0
#if defined(DRV_MISC_CACHE_REGION_SUPPORT)
/* under construction !*/
#else // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
/* under construction !*/
#ifdef GPT_INTERNAL_SRAM
/* under construction !*/
#endif
#endif // #if defined(DRV_MISC_CACHE_REGION_SUPPORT)
#endif
/*-----------------------------------------------------------------------

* FUNCTION                                                            
*	GPTI_HISR
*
* DESCRIPTION                                                           
*   	GPTI HISR
*
* CALLS
*
* PARAMETERS
*	void
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/

void GPTI_HISR(void)
{
   kal_uint8 index;
   kal_uint32 time1, time2;
   kal_uint32 savedMask;
   //this can be delete ?!!@
   //#if !defined(DRV_MISC_TDMA_NO_TIME)
   //kal_uint32 process_tick = 0;
   //kal_uint32 u4DurationMS = 0;
   //#endif
   
   // Bit matched method to check if a GPT items is activated
   // Search whole GPT items
   for (index = 0;index < MAX_GPT_ITEMS;index++)
   {
      #if defined(DRV_MISC_TDMA_NO_TIME)
      GPTProcess(index);//extract macro for assert process which occupy too long.
      #else
      savedMask = SaveAndSetIRQMask();
      if((GPTTimer.status & (1<<index))&&(GPTTimer.GPT_TICK == GPTTimer.GPTItems[index].tick))
      {
         //process_tick = drv_get_current_time();
			time1=drv_get_current_time();
			GPTTimer.status &= ~(1<<index);
			RestoreIRQMask(savedMask);
         GPTTimer.GPTItems[index].gptimer_func(GPTTimer.GPTItems[index].parameter);
			time2=drv_get_current_time();
			GPT_DBG(index,time2-time1);
			//u4DurationMS = drv_get_duration_ms(process_tick);
			//ASSERT(u4DurationMS < 30); // 30 ms //user may break trace32, this assert need to cover by l1_assert_bypass
      }
      else
      {
			RestoreIRQMask(savedMask);
      }
		#endif
   }
   
	GPTTimer.GPT_TICK++;
   
   if(GPTTimer.status == 0)
   {
		// UT Test road test.
		//	module_test_print(" HISR: GPTTimer.Hgpt_handle status is : %x \r\n",GPTTimer.Hgpt_handle);
                GPTTimer.GPT_TICK=0;
		GPTTimer.GPTSTOP=KAL_TRUE;
      
		DclHGPT_Control(GPTTimer.Hgpt_handle,HGPT_CMD_STOP,0);
		DclHGPT_Close(GPTTimer.Hgpt_handle);
		gpt_sw_delay();//delay 3 32K ticks for hw limitation
		//DclHGPT_Close(GPTTimer.Hgpt_handle);

		//GPTTimer.Hgpt_handle=0;
		#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
		#if defined(MTK_SLEEP_ENABLE) && !defined(__FUE__)
		//if(KAL_TRUE==GPT_IsStop())// for 1ms gpt,dongming remove if, because we should ensure only gpt1 can lock/unlock sleep
			SleepDrv_SleepEnable(gpt_sm_handle);
		#endif
		#endif
   }
}


#endif

/* --------------------------------------------- */
/* add for 1ms gpt */

/* --------------------------------------------- */

static kal_bool GPT_MS_StartItem(kal_uint8 module,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter)
{
   kal_uint32 savedMask;  
   savedMask = SaveAndSetIRQMask();
   if (0 != (gpt_ms_running_status & (0x1<<module))) //already running
   {
   		RestoreIRQMask(savedMask);
		return KAL_FALSE;
   }
   gpt_ms_running_status |= (0x1<<module);
   RestoreIRQMask(savedMask);

   //kal_brief_trace(TRACE_GROUP_10,GPT_MS_START,module,tick,gptimer_func);

   GPT_MS_Timer[module].timeout_tick= tick;
   GPT_MS_Timer[module].gpt_ms_callback = gptimer_func;
   GPT_MS_Timer[module].cb_parameter = parameter;
   if((DRV_GPT_Reg(GPT2_CTRL) & GPT_CTRL_Enable) == 0) // means gpt is stop
   {
	    gpt_ms_sw_delay(90);
		savedMask = SaveAndSetIRQMask();
		if((DRV_GPT_Reg(GPT2_CTRL) & GPT_CTRL_Enable) == 0) // we juge one more because racecondition may happen after busy wait
		{
			DclHGPT_Control(gpt_ms_handle,HGPT_CMD_START,0);
		}
		RestoreIRQMask(savedMask);
   }
 
   return KAL_TRUE;
}

static kal_bool GPT_MS_StopItem(kal_uint8 module)
{
   kal_uint32 savedMask;  
   savedMask = SaveAndSetIRQMask();
   if (0 == (gpt_ms_running_status & (1<<module))) //already running
   {
	   RestoreIRQMask(savedMask);
		return KAL_TRUE;
   }
   gpt_ms_running_status &=  (~(1<<module));
   RestoreIRQMask(savedMask);
   //kal_brief_trace(TRACE_GROUP_10,GPT_MS_STOP,module);
   //GPT_MS_Timer[module].timeout_tick= 0;
   //GPT_MS_Timer[module].gpt_ms_callback = gptimer_func;
   //GPT_MS_Timer[module].cb_parameter = parameter;
   savedMask = SaveAndSetIRQMask();
	if((gpt_ms_running_status == 0) && ((DRV_GPT_Reg(GPT2_CTRL) & GPT_CTRL_Enable) != 0) ) // means gpt is stop
	{
		DclHGPT_Control(gpt_ms_handle,HGPT_CMD_STOP,0);
		RestoreIRQMask(savedMask);
		gpt_ms_sw_delay(90);
	}
	else
	{
		RestoreIRQMask(savedMask);
	}
   	return KAL_TRUE;
}

void GPT_MS_Time_Out_Handler(kal_uint16 *ms_handle_sta)
{
   kal_uint16 index;
   kal_uint32 savedMask;
   kal_uint16 bit_mask = 0x1;
   if(0 != gpt_ms_running_status)
	{
	   for (index = 0;index < GPT_MS_MAX_USER;index++)
	   {
	      savedMask = SaveAndSetIRQMask();
			if ((0 != (gpt_ms_running_status & (bit_mask<<index))) && (0 != ((*ms_handle_sta) & (bit_mask<<index))))
			{
		  GPT_MS_Timer[index].timeout_tick--;
				if((GPT_MS_Timer[index].timeout_tick == 0))
	      {
				gpt_ms_running_status &= (~(bit_mask<<index));
				RestoreIRQMask(savedMask);
				//kal_brief_trace(TRACE_GROUP_10,GPT_MS_TIMEOUT,index,GPT_MS_Timer[index].gpt_ms_callback);
	         	GPT_MS_Timer[index].gpt_ms_callback(GPT_MS_Timer[index].cb_parameter);
	      }
	      else
	      {
				RestoreIRQMask(savedMask);
	      }
	   }
			else
			{
				RestoreIRQMask(savedMask);
			}
		}
	}
	}
void GPT_MS_HISR(void)
{
	kal_uint32 savedMask;
	// Search whole GPT items
	GPT_MS_Time_Out_Handler(&gpt_ms_hisr_handle_status);
	savedMask = SaveAndSetIRQMask();
	if((gpt_ms_running_status == 0) && ((DRV_GPT_Reg(GPT2_CTRL) & GPT_CTRL_Enable) != 0) )
	{
		DclHGPT_Control(gpt_ms_handle,HGPT_CMD_STOP,0);
		RestoreIRQMask(savedMask);
		gpt_ms_sw_delay(90);
	}
	else
	{
		RestoreIRQMask(savedMask);
	}
}
/* --------------------------------------------- */
/* --------------------------------------------- */

static void GPTI_BusyWait(kal_uint16 len)
{
	
	gpt_ms_sw_delay(len * 1000);
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
	#endif
}
#else

DCL_STATUS DclSGPT_Initialize(void)
{
	return STATUS_UNSUPPORTED;
}

DCL_HANDLE DclSGPT_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_Close(DCL_HANDLE *handle)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_Initialize(void)
{
	return STATUS_UNSUPPORTED;
}

DCL_HANDLE DclFGPT_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_Close(DCL_HANDLE handle)
{
	return STATUS_UNSUPPORTED;
}
#endif
//#endif 

