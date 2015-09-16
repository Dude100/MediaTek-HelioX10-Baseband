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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_gpt.h"
#include "drv_comm.h"
#include "reg_base.h"

#include "gpt_hw.h"
#include "intrCtrl.h"
#include "drvpdn.h"

#include "dcl.h"
#include "dcl_gpt_hw.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#if !defined(DRV_GPT_OFF)
//this is used when control PDN.
#define GPT_DRVPDN_FAST

extern GPTStruct GPTTimer;

//define hardware GPT No.
#define GPT1 		0x01
#define GPT2  	0x02
#define GPT3  	0x03
#define GPT4		0x04

#define DCL_HGPT_MAGIC_NUM  0x41000000
#define DCL_HGPT_IS_HANDLE_MAGIC(handle_) ((handle_)& DCL_HGPT_MAGIC_NUM)
#define DCL_HGPT_GET_DEV(handle_) ((handle_) & (~DCL_HGPT_MAGIC_NUM))

#define DCL_FGPT_MAGIC_NUM  0x42000000
#define DCL_FGPT_IS_HANDLE_MAGIC(handle_) ((handle_)& DCL_FGPT_MAGIC_NUM)
#define DCL_FGPT_GET_DEV(handle_) ((handle_) & (~DCL_FGPT_MAGIC_NUM))

static kal_bool fgGPT1Open = KAL_FALSE;
static kal_bool fgGPT2Open = KAL_FALSE;

//this count is used to record how many times gpt3 has been open.
#if !defined(GEMINI23C_EVB_BB)
 kal_uint32 GPT3_UseCount;
#endif

//this count is used to record loop times in gpt3_return_current_value.
kal_uint16 gpt_count=0;

static PFN_DCL_CALLBACK pfHGPT1Callback;
static PFN_DCL_CALLBACK pfHGPT2Callback;
static DCL_EVENT eHGPT1Event;
static DCL_EVENT eHGPT2Event;
static gpt_clock eClock[2] = {clk_invalid, clk_invalid};

static void HGPT_Defaul_Callback(DCL_EVENT event)
{
	ASSERT(0); 
	return;
}

static void HGPT1_Callback(void)
{
	pfHGPT1Callback(eHGPT1Event);
	return;
}

static void HGPT2_Callback(void)
{
	pfHGPT2Callback(eHGPT2Event);
	return;
}

//function declaration.
static void GPT_ResetTimer(kal_uint8 timerNum,kal_uint16 countValue,kal_bool autoReload);
static void GPT_clock(kal_uint8 timerNum ,gpt_clock clock);
static void GPT_PDN_enable(void);
static void GPT_PDN_disable(void);
static void GPT_Start(kal_uint8 timerNum);
static void GPT_Stop(kal_uint8 timerNum);
static kal_uint16 GPT_return_current_count(void);
//GPT4 support.
#if defined(DRV_GPT_GPT4)
static kal_uint32 GPT4_return_current_count(void);
static void GPT4_Lock(kal_bool en);
#endif
//static void GPTI_BusyWait(kal_uint16 len);//modified by dongming for build error about GPTI_BuisyWait follow non_static declaration

#if defined(DRV_GPT_STOP_2_STEP)
static void GPT_Stop_Step1(kal_uint8 timerNum);
static void GPT_Stop_Step2();
#endif

/*-----------------------------------------------------------------------*
* FUNCTION                                                            
*	GPT_LISR
*
* DESCRIPTION                                                           
*   	GPT interrupt handler
*
* CALLS  
*	It is called when GPT interrupt is coming
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/
extern void GPT_MS_Time_Out_Handler(kal_uint16 *ms_handle_sta);	/*defined in dcl_gpt.c*/
extern  kal_uint16 gpt_ms_lisr_handle_status;	/*defined in dcl_gpt.c*/
void GPT_LISR(void)
{
	kal_uint16 GPT_Status;
  	IRQMask(IRQ_GPT_CODE);
	GPT_Status = DRV_GPT_Reg(GPT_STS);
	
	if (GPT_Status & GPT_STS_1)
	{
		HGPT1_Callback();
	}
	if (GPT_Status & GPT_STS_2)
	{
		/*--------*/
		//add for 1ms GPT run in LISR context
		GPT_MS_Time_Out_Handler(&gpt_ms_lisr_handle_status);

		HGPT2_Callback(); /* always active hisr ,here may be some optimize */
	}
   IRQClearInt(IRQ_GPT_CODE);
   IRQUnmask(IRQ_GPT_CODE);
}
/*-----------------------------------------------------------------------*
* FUNCTION
*  DclHGPT_Initialize
*
* DESCRIPTION
*  This function is to initialize HW GPT module.
*
* PARAMETERS
*	None
*
* RETURNS
*	DCL_STATUS_OK
*
*------------------------------------------------------------------------*/
DCL_STATUS DclHGPT_Initialize(void)
{	 
	pfHGPT1Callback = HGPT_Defaul_Callback; 
	pfHGPT2Callback = HGPT_Defaul_Callback;
	IRQ_Register_LISR(IRQ_GPT_CODE, GPT_LISR,"GPT handler");
	IRQSensitivity(IRQ_GPT_CODE,LEVEL_SENSITIVE);
	IRQUnmask(IRQ_GPT_CODE);
	return STATUS_OK;
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclHGPT_Open
*
* DESCRIPTION
*  This function is to open a HW GPT module. Note that HW GPT only supports
* single open for each valid eDev and if DCL_GPT1 is chosen SGPT may be 
* influenced and work abnormally.
*
* PARAMETERS
*	eDev - only valid for GPT1 and GPT2
*	flags - no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*	DCL_HANDLE_INVALID - Open failed.
*  other value - a valid handle
*
*------------------------------------------------------------------------*/
DCL_HANDLE DclHGPT_Open(GPT_DEV eDev, DCL_FLAGS flags)
{
	kal_uint32 savedMask;

	switch(eDev)
	{
		case GPT1:
			savedMask = SaveAndSetIRQMask();
			if (KAL_TRUE == fgGPT1Open)
			{
				RestoreIRQMask(savedMask);
                                return (DCL_HGPT_MAGIC_NUM | GPT1);
			}
			fgGPT1Open = KAL_TRUE;
			RestoreIRQMask(savedMask);
			return (DCL_HGPT_MAGIC_NUM | GPT1);//use return instead of break;
		case GPT2:
			#if !defined(__IC_SLT__) // for slt load, always return a valid handle
			savedMask = SaveAndSetIRQMask();
			if (KAL_TRUE == fgGPT2Open)
			{
				RestoreIRQMask(savedMask);
				return DCL_HANDLE_INVALID;
			}

			fgGPT2Open = KAL_TRUE;
			RestoreIRQMask(savedMask);
			#endif
			return (DCL_HGPT_MAGIC_NUM | GPT2);//use return instead of break;
		default:
	      ASSERT(0);
	      return DCL_HANDLE_INVALID;
   }
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclHGPT_ReadData
*
* DESCRIPTION
*  This function is not supported for the HW GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/
DCL_STATUS DclHGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclHGPT_WriteData
*
* DESCRIPTION
*  This function is not supported for the HW GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/
DCL_STATUS DclHGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclHGPT_Configure
*
* DESCRIPTION
*  This function is not supported for the HW GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/
DCL_STATUS DclHGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclHGPT_RegisterCallback
*
* DESCRIPTION
*  This function is to set callback function for the HW GPT module.
*
* PARAMETERS
*	handle  - hanlde previous got from DclHGPT_Open().
*  event   - only support EVENT_HGPT_TIMEOUT event.
*  callback - the callback function when HW GPT is timeout.
*
* RETURNS
*	STATUS_OK - successfully register the callback function.
*  STATUS_INVALID_DCL_HANDLE - It's a invalid handle.
*  STATUS_NOT_OPENED - The module has not been opened.
*  STATUS_INVALID_EVENT - The event parameter is invalid.
*
*------------------------------------------------------------------------*/
DCL_STATUS DclHGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
   DCL_DEV  eDev;

   if (!DCL_HGPT_IS_HANDLE_MAGIC(handle))
   {
      ASSERT(0);
      return STATUS_INVALID_DCL_HANDLE;
   }
   if (!(event & EVENT_HGPT_TIMEOUT))
   {
      return STATUS_INVALID_EVENT;
   }
   eDev = DCL_HGPT_GET_DEV(handle);
   switch(eDev)
   {
   	case GPT1:
      	if (KAL_FALSE == fgGPT1Open)
	   	{
	         return STATUS_NOT_OPENED;
	   	}
      	pfHGPT1Callback = callback;
      	eHGPT1Event = event;
        IRQSensitivity(IRQ_GPT_CODE,LEVEL_SENSITIVE);
        IRQUnmask(IRQ_GPT_CODE);
      	return STATUS_OK;
   	case GPT2:
	      if (KAL_FALSE == fgGPT2Open)
	      {
	         return STATUS_NOT_OPENED;
	      }
	      pfHGPT2Callback = callback;
	      eHGPT2Event = event;
              IRQSensitivity(IRQ_GPT_CODE,LEVEL_SENSITIVE);
              IRQUnmask(IRQ_GPT_CODE);
	      return STATUS_OK;
   	default:
	      ASSERT(0);
	      return STATUS_INVALID_DCL_HANDLE;
   }
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclHGPT_Control
*
* DESCRIPTION
*  This function is to send command to control the HW GPT module.
*
* PARAMETERS
*	handle - a valid handle return by DclHGPT_Open()
*  cmd   - a control command for HW GPT module
*          1. HGPT_CMD_CLK: to set clock for a HW GPT timer
*          2. HGPT_CMD_RESET: to reset a HWGPT timer
*          3. HGPT_CMD_START: to start a HW GPT timer
*          4. HGPT_CMD_STOP: to stop a HWGPT timer
*  data - for 1. HGPT_CMD_CLK: pointer to a HGPT_CTRL_CLK_T structure
*             2. HGPT_CMD_RESET: pointer to a HGPT_CTRL_RESET_T structure
*             3. HGPT_CMD_START: a NULL pointer
*             4. HGPT_CMD_STOP: a NULL pointer
*
* RETURNS
*	STATUS_OK - command is executed successfully.
*	STATUS_FAIL - command is failed.
*  STATUS_INVALID_CMD - The command is invalid.
*  STATUS_INVALID_DCL_HANDLE - The handle is invalid.
*  STATUS_INVALID_CTRL_DATA - The ctrl data is not valid.
*
*------------------------------------------------------------------------*/
DCL_STATUS DclHGPT_Control(DCL_HANDLE handle, HGPT_CMD cmd, HGPT_CTRL *data)
{
   DCL_DEV  eDev;
   kal_uint8 u1TimerNum = 0;
   register kal_uint32 savedMask;
   if (!DCL_HGPT_IS_HANDLE_MAGIC(handle))
   {
      ASSERT(0);
      return STATUS_INVALID_DCL_HANDLE;
   }
   eDev = DCL_HGPT_GET_DEV(handle);
   switch(eDev)
   {
   	case GPT1:
	      if (KAL_FALSE == fgGPT1Open)
	      {
	         return STATUS_NOT_OPENED;//should we add assert ?
	      }
	      u1TimerNum = 1;
	      break;
		case GPT2:
	      if (KAL_FALSE == fgGPT2Open)
	      {
				return STATUS_NOT_OPENED;
	      }
	      u1TimerNum = 2;
	      break;
   	default:
	      ASSERT(0);
	      return STATUS_INVALID_DCL_HANDLE;
   }
   switch(cmd)
   {
   	case HGPT_CMD_CLK:
      {
         HGPT_CTRL_CLK_T   *prClock;
         prClock = &(data->rHGPTClk);
         switch(prClock->u4Clock)
         {
	         case CLK_16K:
	            eClock[u1TimerNum-1] = clk_16k;
	            break;
	         case CLK_8K:
	            eClock[u1TimerNum-1] = clk_8k;
	            break;
	         case CLK_4K:
	            eClock[u1TimerNum-1] = clk_4k;
	            break;
	         case CLK_2K:
	            eClock[u1TimerNum-1] = clk_2k;
	            break;
	         case CLK_1K:
	            eClock[u1TimerNum-1] = clk_1k;
	            break;
	         case CLK_500:
	            eClock[u1TimerNum-1] = clk_500;
	            break;
	         case CLK_250:
	            eClock[u1TimerNum-1]= clk_250;
	            break;
	         case CLK_125:
	            eClock[u1TimerNum-1]= clk_125;
	            break;
	         default:
	            ASSERT(0);
	            return STATUS_INVALID_CTRL_DATA;
			}
		 
			GPT_PDN_enable();
			GPT_clock(u1TimerNum, eClock[u1TimerNum-1]);
                        if(KAL_TRUE==GPT_IsStop())			
                            GPT_PDN_disable();
			break;
      }
   	case HGPT_CMD_RESET:
      {
         HGPT_CTRL_RESET_T   *prReset;
         prReset = &(data->rHGPTReset);
		 GPT_PDN_enable();
         GPT_ResetTimer(u1TimerNum, prReset->u2CountValue, prReset->fgAutoReload);
               if(KAL_TRUE==GPT_IsStop())		 
                   GPT_PDN_disable();
      }
      break;
   	case HGPT_CMD_START:
      	GPT_Start(u1TimerNum);
      	break;
   	case HGPT_CMD_STOP:
   	{
   	#if defined(__ENABLE_GPT_PROTECTION__)
      //savedMask = SaveAndSetIRQMask();
      savedMask = kal_take_thread_protect();
	if(u1TimerNum==1)
	{
      if ((GPTTimer.GPTSTOP) == KAL_TRUE)
         GPT_Stop(u1TimerNum);
	}
	else
	{
	   GPT_Stop(u1TimerNum);
	}
	 kal_give_thread_protect(savedMask);
     // RestoreIRQMask(savedMask); 
    #else
	if(u1TimerNum==1)
	{
            savedMask = SaveAndSetIRQMask();
            if ((GPTTimer.GPTSTOP) == KAL_TRUE)
            #if defined(DRV_GPT_STOP_2_STEP)
            {
               GPT_Stop_Step1(u1TimerNum);
               RestoreIRQMask(savedMask);
               savedMask = SaveAndSetIRQMask();
               if ((GPTTimer.GPTSTOP) == KAL_TRUE)
                   GPT_Stop_Step2();
             }
            #else
      	    GPT_Stop(u1TimerNum);
            #endif //#if defined(DRV_GPT_STOP_2_STEP)
            RestoreIRQMask(savedMask);
        }
        else
        {
            	savedMask = SaveAndSetIRQMask();
    	        #if defined(DRV_GPT_STOP_2_STEP)
                {
            	   GPT_Stop_Step1(u1TimerNum);
               	   RestoreIRQMask(savedMask);
               	   savedMask = SaveAndSetIRQMask();
                   GPT_Stop_Step2();
                }
            	#else
                GPT_Stop(u1TimerNum);
    	        #endif //#if defined(DRV_GPT_STOP_2_STEP)
                RestoreIRQMask(savedMask);				
        }
	  #endif
        }  
      	break;
   	default:
      	ASSERT(0);
      	return STATUS_INVALID_CMD;
   }
   return STATUS_OK;
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclHGPT_Close
*
* DESCRIPTION
*  This function is to close a HW GPT module by a handle previous opened. 
*
* PARAMETERS
*	handle  - hanlde previous got from DclHGPT_Open().
*
* RETURNS
*	STATUS_OK - successful.
*	DCL_HANDLE_INVALID - it's a invalid handle.
*
*------------------------------------------------------------------------*/
DCL_STATUS DclHGPT_Close(DCL_HANDLE handle)
{
	kal_uint32 savedMask;
	DCL_DEV  eDev;

   if (!DCL_HGPT_IS_HANDLE_MAGIC(handle))
   {
      ASSERT(0);
      return STATUS_INVALID_DCL_HANDLE;
   }
   eDev = DCL_HGPT_GET_DEV(handle);
   switch(eDev)
   {
   	case GPT1:
	      if (KAL_FALSE == fgGPT1Open)
	      {
				return STATUS_NOT_OPENED;
	      }
			savedMask = SaveAndSetIRQMask();
			fgGPT1Open = KAL_FALSE;
			RestoreIRQMask(savedMask);
			return STATUS_OK;
   	case GPT2:
	      if (KAL_FALSE == fgGPT2Open)
			{
	         return STATUS_NOT_OPENED;
			}
			savedMask = SaveAndSetIRQMask();
			fgGPT2Open = KAL_FALSE;
			RestoreIRQMask(savedMask);
	      return STATUS_OK;
   	default:
	      ASSERT(0);
	      return DCL_HANDLE_INVALID;
   }
}


/*-----------------------------------------------------------------------*
* FUNCTION
*  DclFHGPT_Initialize
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
DCL_STATUS DclFHGPT_Initialize(void)
{
	#if defined(DRV_GPT_GPT3)
	#if !defined(GEMINI23C_EVB_BB)
	GPT3_UseCount = 0;
	#endif
	DRV_GPT_WriteReg(GPT3_PRESCALER,GPT_PRESCALER_div32);  
	#endif
	return STATUS_OK;
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclFHGPT_Open
*
* DESCRIPTION
*  This function is to open a free run GPT module if it exists. Note 
* that it supports multiple opens and no need to close it.
*
* PARAMETERS
*	eDev - only valid for GPT3
*	flags - no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*	DCL_HANDLE_INVALID - Open failed. It means no free run GPT exists or 
*                       open a wrong device.
*  other value - a valid handle
*
*------------------------------------------------------------------------*/
DCL_HANDLE DclFHGPT_Open(DCL_DEV eDev, DCL_FLAGS flags)
{
	if(GPT3 != eDev && GPT4 != eDev )
   {
      ASSERT(0);
      return DCL_HANDLE_INVALID;
   }

	#if defined(DRV_GPT_GPT3) 
	if(GPT3 == eDev)
		return (DCL_FGPT_MAGIC_NUM | GPT3);
	#endif
	#if defined(DRV_GPT_GPT4)
	if (GPT4 == eDev)
		return (DCL_FGPT_MAGIC_NUM | GPT4);
	#endif
	{
		ASSERT(0);
		return DCL_HANDLE_INVALID;   		
	}
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclFHGPT_ReadData
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
DCL_STATUS DclFHGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclFHGPT_WriteData
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
DCL_STATUS DclFHGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclFHGPT_Configure
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
DCL_STATUS DclFHGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclFHGPT_RegisterCallback
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
DCL_STATUS DclFHGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclFHGPT_Control
*
* DESCRIPTION
*  This function is to send command to control the free run GPT module.
*
* PARAMETERS
*	handle - a valid handle return by DclFHGPT_Open()
*  cmd   - a control command for free ryb GPT module
*          FHGPT_CMD_RETURN_COUNT: to get the timer count
*  data - for FHGPT_CMD_RETURN_COUNT: pointer to a FGPT_CTRL_RETURN_COUNT_T type
*
* RETURNS
*	STATUS_OK - command is executed successfully.
*	STATUS_FAIL - command is failed. No free run GPT is supported.
*  STATUS_INVALID_CMD - The command is invalid.
*  STATUS_INVALID_DCL_HANDLE - The handle is invalid.
*
*------------------------------------------------------------------------*/
DCL_STATUS DclFHGPT_Control(DCL_HANDLE handle, HGPT_CMD cmd, HGPT_CTRL *data)
{
   DCL_DEV  eDev;
   if(!DCL_FGPT_IS_HANDLE_MAGIC(handle))
   {
		ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
   }
   
   eDev = DCL_FGPT_GET_DEV(handle);
   if(eDev != GPT3 && eDev != GPT4)
   {
		ASSERT(0);
		return DCL_HANDLE_INVALID;
   }
   switch(cmd)
   {
		case FHGPT_CMD_START:
			#if defined(DRV_GPT_GPT3)
			if (eDev==GPT3)
			{
      		GPT_Start(GPT3);
			}
			#endif
			
			#if defined(DRV_GPT_GPT4)
			if (eDev==GPT4)
			{
				GPT_Start(GPT4);
			}
			#endif
			//this judgment can be move to front and only do once.
			#if !defined(DRV_GPT_GPT3) && !defined(DRV_GPT_GPT4)
      	return STATUS_FAIL;
			#endif
      break;
		case FHGPT_CMD_STOP:
			#if defined(DRV_GPT_GPT3)
			if (eDev==GPT3)
			{
		      GPT_Stop(GPT3);
			}
			#endif
		
			#if defined(DRV_GPT_GPT4)
			if (eDev==GPT4)
			{
				GPT_Stop(GPT4);
			}
			#endif
		
			#if !defined(DRV_GPT_GPT3) && !defined(DRV_GPT_GPT4)
			return STATUS_FAIL;
			#endif
		break;
		case FHGPT_CMD_RETURN_COUNT:
			#if defined(DRV_GPT_GPT3)
			if (eDev==GPT3)
			{
		      data->u2RetCount = GPT_return_current_count();
			}
			#endif
		
			#if defined(DRV_GPT_GPT4)
			if (eDev==GPT4)
			{
				 data->u2RetCount_32bit = GPT4_return_current_count();
			}
			#endif
			#if !defined(DRV_GPT_GPT3) && !defined(DRV_GPT_GPT4)
		      return STATUS_FAIL;
			#endif
		break;
		case FHGPT_CMD_LOCK:
		#if defined(DRV_GPT_GPT4)  
		if(eDev==GPT4)
		{
			if(data->ulock ==0)
				GPT4_Lock(KAL_FALSE);
			else if(data->ulock ==1)
				GPT4_Lock(KAL_TRUE);
			else
				{
					ASSERT(0);
				}	  		
		}
		#endif 
		break;		
		default:
			ASSERT(0);
			return STATUS_INVALID_CMD;
	}
   return STATUS_OK;
}

/*-----------------------------------------------------------------------*
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
DCL_STATUS DclFHGPT_Close(DCL_HANDLE handle)
{
   return STATUS_UNSUPPORTED;
}
#else /*!defined(DRV_GPT_OFF)*/

DCL_STATUS DclHGPT_Initialize(void)
{
	return STATUS_FAIL;
}

DCL_HANDLE DclHGPT_Open(GPT_DEV eDev, DCL_FLAGS flags)
{
   return DCL_HANDLE_INVALID;
}

DCL_STATUS DclHGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_FAIL;
}

DCL_STATUS DclHGPT_Control(DCL_HANDLE handle, HGPT_CMD cmd, HGPT_CTRL *data)
{
	return STATUS_FAIL;
}

DCL_STATUS DclHGPT_Close(DCL_HANDLE handle)
{
	return STATUS_FAIL;
}

DCL_STATUS DclFHGPT_Initialize(void)
{
	return STATUS_FAIL;
}

DCL_HANDLE DclFHGPT_Open(DCL_DEV eDev, DCL_FLAGS flags)

{
   return DCL_HANDLE_INVALID;
}

DCL_STATUS DclFHGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFHGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFHGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFHGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_FAIL;
}

DCL_STATUS DclFHGPT_Control(DCL_HANDLE handle, HGPT_CMD cmd, HGPT_CTRL *data)

{
	return STATUS_FAIL;
}

DCL_STATUS DclFGPT_Close(DCL_HANDLE handle)
{
	return STATUS_FAIL;
}
#endif /*!defined(DRV_GPT_OFF)*/

/*-----------------------------------------------------------------------*                                                         
*
*   	This function is to setup GPT clock
*
*------------------------------------------------------------------------*/
static void GPT_clock(kal_uint8 timerNum ,gpt_clock clock)
{
	kal_uint16 *ptr_addr = (kal_uint16 *)GPT1_PRESCALER;	// Set ptr_addr a init value to avoid lint Warning 613
	if( timerNum == GPT1)
	{
		ptr_addr = (kal_uint16 *)GPT1_PRESCALER;
	}
	else if ( timerNum == GPT2)
	{
		ptr_addr = (kal_uint16 *)GPT2_PRESCALER;
	}
	else
	{
		ASSERT(0);
	}
	/*lint -e661*/
	switch(clock)
	{
		case clk_16k:
		   DRV_GPT_WriteReg(ptr_addr,GPT_PRESCALER_div2);
			break;
			
		case clk_8k:
		   DRV_GPT_WriteReg(ptr_addr,GPT_PRESCALER_div4);
			break;			
			
		case clk_4k:
		   DRV_GPT_WriteReg(ptr_addr,GPT_PRESCALER_div8);
			break;			
			
		case clk_2k:
		   DRV_GPT_WriteReg(ptr_addr,GPT_PRESCALER_div16);
			break;			
			
		case clk_1k:
		   DRV_GPT_WriteReg(ptr_addr,GPT_PRESCALER_div32);
			break;			
			
		case clk_500:
		   DRV_GPT_WriteReg(ptr_addr,GPT_PRESCALER_div64);
			break;			
			
		case clk_250:
		   DRV_GPT_WriteReg(ptr_addr,GPT_PRESCALER_div128);
			break;			
			
		case clk_125:
		   DRV_GPT_WriteReg(ptr_addr,GPT_PRESCALER_div256);
			break;
			
		default:
			break;
	}
	/*lint +e661*/
}

/*-----------------------------------------------------------------------*
* FUNCTION                                                            
*	GPT_ResetTimer
*
* DESCRIPTION                                                           
*  This function is to setup GPT parameters
*
* CALLS  
*	It is called to setup GPT parameters
*
* PARAMETERS
*	timerNum = 1(GPT1) or 2(GPT2)
*	countValue = GPT count
*	autoReload = KAL_TRUE,autoReload mode
*	KAL_FALSE, Single shot mode
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/
static void GPT_ResetTimer(kal_uint8 timerNum,kal_uint16 countValue,kal_bool autoReload)
{
	if (timerNum == GPT1)
	{
	   DRV_GPT_WriteReg(GPT1_LEN,countValue);
		if (autoReload == KAL_TRUE)
		{
			DRV_GPT_SetBits(GPT1_CTRL, GPT_CTRL_AUTOMODE);
		}
		else
		{
			DRV_GPT_ClearBits(GPT1_CTRL, GPT_CTRL_AUTOMODE);
		}
	}

	if (timerNum == GPT2)
	{
	   DRV_GPT_WriteReg(GPT2_LEN,countValue);
		if (autoReload == KAL_TRUE)
		{
			DRV_GPT_SetBits(GPT2_CTRL, GPT_CTRL_AUTOMODE);
		}
		else
		{
			DRV_GPT_ClearBits(GPT2_CTRL, GPT_CTRL_AUTOMODE);
		}		
	}
}

// Put the code into internal SRAM
#ifdef GPT_INTERNAL_SRAM
  #pragma arm section code = "INTERNCODE"
#endif
/*-----------------------------------------------------------------------*
*                                                          
*  This function is to enable GPT source clock.
*
*------------------------------------------------------------------------*/
static void GPT_PDN_enable()
{
	#if !defined(DRV_GPT_NO_PDN_BIT)
#if defined(__OLD_PDN_ARCH__)
#if defined(DRV_GPT_GPT_INTR_WAKEUP_SLEEP)
	// Clear GPT PDN bit directly
	#if defined(DRV_MISC_PDN_NO_SET_CLR)
#if defined(__OLD_PDN_DEFINE__)
		DRV_GPT_ClearBits(DRVPDN_CON1, DRVPDN_CON1_GPT);
		//DRV_GPT_Reg(DRVPDN_CON1) &= ~DRVPDN_CON1_GPT;
#elif defined(__CLKG_DEFINE__)
		#if defined(DRV_GPT_NO_GPT_CG_BIT)
		;
		#else // #if defined(DRV_GPT_NO_GPT_CG_BIT)
		ASSERT(0);
		#endif // #if defined(DRV_GPT_NO_GPT_CG_BIT)
#endif // #if defined(__OLD_PDN_DEFINE__)
	#else // #if defined(DRV_MISC_PDN_NO_SET_CLR)
#if defined(__OLD_PDN_DEFINE__)
		DRV_GPT_WriteReg(DRVPDN_CON1_CLR, DRVPDN_CON1_GPT);
#elif defined(__CLKG_DEFINE__)
		#if defined(DRV_GPT_NO_GPT_CG_BIT)
		;
		#else // #if defined(DRV_GPT_NO_GPT_CG_BIT)
		ASSERT(0);
		#endif // #if defined(DRV_GPT_NO_GPT_CG_BIT)
#endif // #if defined(__OLD_PDN_DEFINE__)
	#endif // #if defined(DRV_MISC_PDN_NO_SET_CLR)
#else // #if defined(DRV_GPT_GPT_INTR_WAKEUP_SLEEP)
	// We need to to hook sleep mode handler to disable MCU enter sleep mode
#if defined(__OLD_PDN_DEFINE__)
#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
	// Clear GPT PDN bit directly
	#if defined(DRV_MISC_PDN_NO_SET_CLR)
		DRV_GPT_ClearBits(DRVPDN_CON1, DRVPDN_CON1_GPT);
		//DRV_GPT_Reg(DRVPDN_CON1) &= ~DRVPDN_CON1_GPT;
	#else // #if defined(DRV_MISC_PDN_NO_SET_CLR)
		DRV_GPT_WriteReg(DRVPDN_CON1_CLR, DRVPDN_CON1_GPT);
	#endif // #if defined(DRV_MISC_PDN_NO_SET_CLR)
#else//#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
	#ifdef GPT_DRVPDN_FAST
		DRVPDN_DISABLE2(DRVPDN_CON1,DRVPDN_CON1_GPT,PDN_GPT);
	#else
		DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_GPT,PDN_GPT);
	#endif
#endif
#elif defined(__CLKG_DEFINE__)
	#if defined(DRV_GPT_NO_GPT_CG_BIT)
	#ifdef GPT_DRVPDN_FAST
//	   DRVPDN_DISABLE2(0,0,PDN_GPT);	// TTTTTT, Temp commented for MT6268A DVT load   
   #else // #ifdef GPT_DRVPDN_FAST
	   DRVPDN_Disable(0,0,PDN_GPT);
   #endif // #ifdef GPT_DRVPDN_FAST
	#else // #if defined(DRV_GPT_NO_GPT_CG_BIT)
		ASSERT(0);	// TODO
	#endif // 	#if defined(DRV_GPT_NO_GPT_CG_BIT)
#endif // #if defined(__OLD_PDN_DEFINE__)
#endif // #if defined(DRV_GPT_GPT_INTR_WAKEUP_SLEEP)
#else //#if defined(__OLD_PDN_ARCH__)
      PDN_CLR(PDN_GPT);
#endif //#if defined(__OLD_PDN_ARCH__)
#endif //#if !defined(DRV_GPT_NO_PDN_BIT)
}
/*-----------------------------------------------------------------------*
*                                                          
*  This function is to close GPT source clock.
*
*------------------------------------------------------------------------*/
static void GPT_PDN_disable()
{
	#if !defined(DRV_GPT_NO_PDN_BIT)
#if defined(__OLD_PDN_ARCH__)
#if defined(DRV_GPT_GPT_INTR_WAKEUP_SLEEP)
	// Set GPT PDN bit directly
	#if defined(DRV_MISC_PDN_NO_SET_CLR)
#if defined(__OLD_PDN_DEFINE__)
		DRV_GPT_SetBits(DRVPDN_CON1, DRVPDN_CON1_GPT);
		//DRV_GPT_Reg(DRVPDN_CON1) |= DRVPDN_CON1_GPT;
#elif defined(__CLKG_DEFINE__)
		#if defined(DRV_GPT_NO_GPT_CG_BIT)
		;
		#else // #if defined(DRV_GPT_NO_GPT_CG_BIT)
		ASSERT(0);
		#endif // #if defined(DRV_GPT_NO_GPT_CG_BIT)
#endif // #if defined(__OLD_PDN_DEFINE__)
	#else // #if defined(DRV_MISC_PDN_NO_SET_CLR)
#if defined(__OLD_PDN_DEFINE__)
		DRV_GPT_WriteReg(DRVPDN_CON1_SET, DRVPDN_CON1_GPT);
#elif defined(__CLKG_DEFINE__)
		#if defined(DRV_GPT_NO_GPT_CG_BIT)
		;
		#else // #if defined(DRV_GPT_NO_GPT_CG_BIT)
		ASSERT(0);
		#endif // #if defined(DRV_GPT_NO_GPT_CG_BIT)
#endif // #if defined(__OLD_PDN_DEFINE__)
	#endif // #if defined(DRV_MISC_PDN_NO_SET_CLR)
#else // #if defined(DRV_GPT_GPT_INTR_WAKEUP_SLEEP)
	// We need to to un-hook sleep mode handler to allow MCU enter sleep mode
#if defined(__OLD_PDN_DEFINE__)
#if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
	// Set GPT PDN bit directly
	#if defined(DRV_MISC_PDN_NO_SET_CLR)
		DRV_GPT_SetBits(DRVPDN_CON1, DRVPDN_CON1_GPT);
		//DRV_GPT_Reg(DRVPDN_CON1) |= DRVPDN_CON1_GPT;
	#else // #if defined(DRV_MISC_PDN_NO_SET_CLR)
		DRV_GPT_WriteReg(DRVPDN_CON1_SET, DRVPDN_CON1_GPT);
	#endif // #if defined(DRV_MISC_PDN_NO_SET_CLR)
#else // #if defined(DRV_GPT_DIRECT_SLEEP_MODE_HANDLE)
   #ifdef GPT_DRVPDN_FAST
	   DRVPDN_ENABLE2(DRVPDN_CON1,DRVPDN_CON1_GPT,PDN_GPT);	   
   #else
	   DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_GPT,PDN_GPT);	  
   #endif
#endif
#elif defined(__CLKG_DEFINE__)
	#if defined(DRV_GPT_NO_GPT_CG_BIT)
	#ifdef GPT_DRVPDN_FAST
//	   DRVPDN_ENABLE2(0,0,PDN_GPT);  // TTTTTTTT, Temp commented for MT6268A DVT load	   
	#else // #ifdef GPT_DRVPDN_FAST
	   DRVPDN_Enable(0,0,PDN_GPT);	  
	#endif // #ifdef GPT_DRVPDN_FAST
	#else // #if defined(DRV_GPT_NO_GPT_CG_BIT)
		ASSERT(0);
	#endif // 	#if defined(DRV_GPT_NO_GPT_CG_BIT)
#endif // #if defined(__OLD_PDN_DEFINE__)
#endif // #if defined(DRV_GPT_GPT_INTR_WAKEUP_SLEEP)
#else //#if defined(__OLD_PDN_ARCH__)
      PDN_SET(PDN_GPT);
#endif //#if defined(__OLD_PDN_ARCH__)
#endif //#if !defined(DRV_GPT_NO_PDN_BIT)
}
/*-----------------------------------------------------------------------*
*                                                          
*  This function is to start gpt hardware.
*
*------------------------------------------------------------------------*/
static void GPT_Start(kal_uint8 timerNum)
{
	GPT_PDN_enable();

	if (timerNum == GPT1)
	{
		DRV_GPT_SetBits(GPT1_CTRL, GPT_CTRL_Enable);
	}
	else if (timerNum == GPT2)
	{
		DRV_GPT_SetBits(GPT2_CTRL, GPT_CTRL_Enable);
	}
	#if defined(DRV_GPT_GPT3)
	else if (timerNum == GPT3)
	{
		#if !defined(GEMINI23C_EVB_BB)
		GPT3_UseCount++;
		#endif
		DRV_GPT_SetBits(GPT3_CTRL, GPT3_ENABLE);
	}
	#endif
	#if defined(DRV_GPT_GPT4)
	else if (timerNum == GPT4)
	{
		DRV_GPT_SetBits(GPT4_CTRL, GPT4_ENABLE);
	}
	#endif	
		
	//GPT_PDN_enable();
	IRQUnmask(IRQ_GPT_CODE);
}
/*-----------------------------------------------------------------------*
*
*	It is called to stop GPT timer
*
*------------------------------------------------------------------------*/
static void GPT_Stop(kal_uint8 timerNum)
{
	#if defined(DRV_GPT_STOP_2_STEP)
	GPT_Stop_Step1(timerNum);
	GPT_Stop_Step2();
	#else
	register kal_uint32 gpt_ctrl1;
	register kal_uint32 gpt_ctrl2;
	#if defined(DRV_GPT_GPT3)
	register kal_uint32 gpt_ctrl3;
	#endif   
	#if defined(DRV_GPT_GPT4)
	register kal_uint32 gpt_ctrl4;
	#endif 

	gpt_ctrl1 = DRV_GPT_Reg(GPT1_CTRL);
	gpt_ctrl2 = DRV_GPT_Reg(GPT2_CTRL);
   
	#if defined(DRV_GPT_GPT3)
	gpt_ctrl3 = DRV_GPT_Reg(GPT3_CTRL);
	#endif   
	
	#if defined(DRV_GPT_GPT4)
  	gpt_ctrl4= DRV_GPT_Reg(GPT4_CTRL);
	#endif

	if (timerNum == GPT1)
	{
		gpt_ctrl1 &= ~GPT_CTRL_Enable;
		DRV_GPT_WriteReg(GPT1_CTRL,gpt_ctrl1);
	}
	else if (timerNum == GPT2)
	{
		gpt_ctrl2 &= ~GPT_CTRL_Enable;
		DRV_GPT_WriteReg(GPT2_CTRL,gpt_ctrl2);
	}
	
	#if defined(DRV_GPT_GPT3)
	else if (timerNum == GPT3)
	{
		#if !defined(GEMINI23C_EVB_BB)
	   kal_uint32 savedMask;
		GPT3_UseCount--;
	   savedMask = SaveAndSetIRQMask();		
	   if(GPT3_UseCount == 0)
	   {
		#endif
		gpt_ctrl3 =(kal_uint16) ~GPT3_ENABLE;
		DRV_GPT_WriteReg(GPT3_CTRL,gpt_ctrl3);
		}
		 #if !defined(GEMINI23C_EVB_BB)
	   RestoreIRQMask(savedMask);
	}
		#endif
	#endif /* defined(DRV_GPT_GPT3) */
	#if defined(DRV_GPT_GPT4)
	else if (timerNum == GPT4)
	{
		gpt_ctrl4 =(kal_uint16) ~GPT4_ENABLE;
		DRV_GPT_WriteReg(GPT4_CTRL,gpt_ctrl4);
	}
	#endif 
	if ( (((gpt_ctrl1|gpt_ctrl2)&GPT_CTRL_Enable)==0)
	#if defined(DRV_GPT_GPT3)
	&& (!(gpt_ctrl3&GPT3_ENABLE))
	#endif /* defined(DRV_GPT_GPT3) */
	#if defined(DRV_GPT_GPT4)
	&& (!(gpt_ctrl4&GPT4_ENABLE))
	#endif /* defined(DRV_GPT_GPT4) */
 	)
   if(KAL_TRUE==GPT_IsStop())
   {
		DRV_GPT_Reg(GPT_STS);
		IRQMask(IRQ_GPT_CODE);
		IRQClearInt(IRQ_GPT_CODE);
		GPT_PDN_disable();
    }
#endif //#if defined(DRV_GPT_STOP_2_STEP)
}

#if defined(DRV_GPT_STOP_2_STEP)
void GPT_Stop_Step1(kal_uint8 timerNum)
{
	register kal_uint32 gpt_ctrl1;
	register kal_uint32 gpt_ctrl2;
	#if defined(DRV_GPT_GPT3)
	register kal_uint32 gpt_ctrl3;
	#endif   
	#if defined(DRV_GPT_GPT4)
	register kal_uint32 gpt_ctrl4;
	#endif  
  
	gpt_ctrl1 = DRV_GPT_Reg(GPT1_CTRL);
	gpt_ctrl2 = DRV_GPT_Reg(GPT2_CTRL);
	#if defined(DRV_GPT_GPT3)
	gpt_ctrl3 = DRV_GPT_Reg(GPT3_CTRL);
	#endif   
	#if defined(DRV_GPT_GPT4)
	gpt_ctrl4 = DRV_GPT_Reg(GPT4_CTRL);
	#endif  

   if (timerNum == 1)
   {
      gpt_ctrl1 &= ~GPT_CTRL_Enable;
      DRV_GPT_WriteReg(GPT1_CTRL,gpt_ctrl1);
   }
   else if (timerNum == 2)
   {
      gpt_ctrl2 &= ~GPT_CTRL_Enable;
      DRV_GPT_WriteReg(GPT2_CTRL,gpt_ctrl2);
   }
	#if defined(DRV_GPT_GPT3)
   else if (timerNum == 3)
   {
		#if !defined(GEMINI23C_EVB_BB)
		GPT3_UseCount--;
		if(GPT3_UseCount == 0)
		{
			#endif
			gpt_ctrl3 =(kal_uint16) ~GPT3_ENABLE;
			DRV_GPT_WriteReg(GPT3_CTRL,gpt_ctrl3);
			#if !defined(GEMINI23C_EVB_BB)
		}
		#endif
   }
	#endif //#if defined(DRV_GPT_GPT3)
	#if defined(DRV_GPT_GPT4)
	else if (timerNum == 4)
	{
		gpt_ctrl4 =(kal_uint16) ~GPT4_ENABLE;
		DRV_GPT_WriteReg(GPT4_CTRL,gpt_ctrl4);
	}
	#endif //#if defined(DRV_GPT_GPT4)

	if ( (((gpt_ctrl1|gpt_ctrl2)&GPT_CTRL_Enable)==0)
	#if defined(DRV_GPT_GPT3)
	&& (!(gpt_ctrl3&GPT3_ENABLE))
	#endif /* defined(DRV_GPT_GPT3) */
	#if defined(DRV_GPT_GPT4)
	&& (!(gpt_ctrl4&GPT4_ENABLE))
	#endif /* defined(DRV_GPT_GPT4) */
	)
 	{
		register kal_uint32 GPT_Status;
		GPT_Status = DRV_GPT_Reg(GPT_STS);
		IRQMask(IRQ_GPT_CODE);
		IRQClearInt(IRQ_GPT_CODE);
	}
}

void GPT_Stop_Step2()
{
	if( (((DRV_GPT_Reg(GPT1_CTRL)|DRV_GPT_Reg(GPT2_CTRL))&GPT_CTRL_Enable)==0)
	#if defined(DRV_GPT_GPT3)
	&& (!(DRV_GPT_Reg(GPT3_CTRL)&GPT3_ENABLE))
	#endif /* defined(DRV_GPT_GPT3) */
	#if defined(DRV_GPT_GPT4)
	&& (!(DRV_GPT_Reg(GPT4_CTRL)&GPT4_ENABLE))
	#endif /* defined(DRV_GPT_GPT4) */
   ) 
      {
			GPT_PDN_disable();
   	}
}
#endif //#if defined(DRV_GPT_STOP_2_STEP)

// Put the code into internal SRAM
#ifdef GPT_INTERNAL_SRAM
#pragma arm section code
#endif


#if defined(DRV_GPT_GPT3) 
//add while loop to fix a hardware bug.
static kal_uint16 GPT_return_current_count(void)
{
   kal_uint16 current_count;
   gpt_count=0;
   do
   {	
      gpt_count++;
		current_count=DRV_GPT_Reg(GPT3_LEN);
   }
   while((current_count!=DRV_GPT_Reg(GPT3_LEN)) && (gpt_count<100));
   return current_count;      
}   
#endif

#if defined(DRV_GPT_GPT4)
static kal_uint32  GPT4_return_current_count(void)
{
   kal_uint32  current_count;
   current_count=DRV_GPT_Reg(GPT4_LEN);
   return current_count;      
}  
static void GPT4_Lock(kal_bool en)
{
	if(en==KAL_TRUE)
	{
		DRV_GPT_SetBits(GPT4_CTRL, GPT4_LOCKED);
	}	
	else
	{
		DRV_GPT_ClearBits(GPT4_CTRL,GPT4_LOCKED);
	}
}
#endif
//this function return the status of GPT1 and GPT2, which influence sleep mode.
//re-check with wy to remove GPT3 GPT4 
 kal_bool GPT_IsStop(void)
{
	#if defined(DRV_GPT_GPT3)
	if ( (((DRV_GPT_Reg(GPT1_CTRL)|DRV_GPT_Reg(GPT2_CTRL))&GPT_CTRL_Enable)==0)&& (!(DRV_GPT_Reg(GPT3_CTRL)&GPT3_ENABLE)))
	#else
	if ( ((DRV_GPT_Reg(GPT1_CTRL)|DRV_GPT_Reg(GPT2_CTRL))&GPT_CTRL_Enable)==0  )
	#endif	
	{
		return KAL_TRUE;
	}
	else
		return KAL_FALSE;
}

