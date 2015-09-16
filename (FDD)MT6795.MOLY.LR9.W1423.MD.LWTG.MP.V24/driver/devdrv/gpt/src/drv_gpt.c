/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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

/*******************************************************************************
 * Filename:
 * ---------
 *   drv_gpt.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   Low level GPT driver
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * Add Debug GPT APIs
 *
 * removed!
 * removed!
 * remove compiling warning
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * MT6290E1_FristCall Branch sync back to MOLY Trunk
 *
 * removed!
 * removed!
 * LISR 2 HISR support, driver part
 *
 * removed!
 * removed!
 * MOLY LISR2HISR, Driver part
 ****************************************************************************/

#include "drv_features_gpt.h"
#include "drv_comm.h"

#include "drv_gpt.h"
#include "intrCtrl.h"

#include "dcl.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "sync_data.h"
#if !defined(DRV_GPT_OFF)

/*****************************************************************************
 *						 SYMBOL Definition                                   *
 *****************************************************************************/


/*****************************************************************************
 *						 Global/External Variable                            *
 *****************************************************************************/
#if !defined(__UNIFIED_ISR_LEVEL__)
static PFN_DCL_CALLBACK pfHGPTCallback[DRV_GPT_TOTAL_COUNTER];
static DCL_EVENT        eHGPTEvent[DRV_GPT_TOTAL_COUNTER];
#endif /* !__UNIFIED_ISR_LEVEL__ */


/*****************************************************************************
 *						 function declaration                                *
 *****************************************************************************/
//function declaration.



/*****************************************************************************
 *						 LISR/HISR/Callback Functions                        *
 *****************************************************************************/
#if !defined(__UNIFIED_ISR_LEVEL__)
static void drv_default_callback(DCL_EVENT event)
{
	kal_uint32 ASSERT_IN_GPT_DEFAULT_CALLBACK = 0;
	ASSERT(ASSERT_IN_GPT_DEFAULT_CALLBACK); 
	return;
}
#endif

/*****************************************************************************
 *						 Basic Driver Implementation						 *
 *****************************************************************************/

/*-----------------------------------------------------------------------*
* FUNCTION                                                            
*	drv_gpt_lisr
*
* DESCRIPTION                                                           
*   	GPT interrupt handler (LISR)
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
#if !defined(__UNIFIED_ISR_LEVEL__)
void drv_gpt_lisr(kal_uint32 v)
{
	ASSERT(MDGPT_INTR_ID(DRV_GPT_BASE_COUNTER_NUM) <= v && v <= MDGPT_INTR_ID(DRV_GPT_TOTAL_COUNTER));
	pfHGPTCallback[MDGPT_INTR_ID2TIMER(v)-1](eHGPTEvent[MDGPT_INTR_ID2TIMER(v)-1]);
}
#endif/* !defined(__UNIFIED_ISR_LEVEL__) */

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_gpt_reset
*
* DESCRIPTION
*  This function is to reset the hardware GPT module.
*
* PARAMETERS
*	None
*
* RETURNS
*	DCL_STATUS_OK
*
*------------------------------------------------------------------------*/
void drv_gpt_reset(void)
{
	kal_uint32 i;
	for(i = DRV_GPT_BASE_COUNTER_NUM; i <= DRV_GPT_TOTAL_COUNTER; i++)
	{
		DRV_WriteReg32(MDGPT_CTRL_REG(i), 0);
		DRV_WriteReg32(MDGPT_CNT_REG(i), 0xFFFFF);
		DRV_WriteReg32(MDGPT_PSR_REG(i), 0);
        IRQSensitivity(MDGPT_INTR_ID(i), EDGE_SENSITIVE);
		IRQClearInt(MDGPT_INTR_ID(i));
		
#if !defined(__UNIFIED_ISR_LEVEL__)
		pfHGPTCallback[i-1] = drv_default_callback;
		if( i != DRV_GPT_SYSTEM_TIMER )
		{
			IRQ_Register_LISR(MDGPT_INTR_ID(i), drv_gpt_lisr, "GPT handler");
		}
#endif /* !defined(__UNIFIED_ISR_LEVEL__) */
		//IRQUnmask(MDGPT_INTR_ID(i));
	}
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_gpt_set_timer
*
* DESCRIPTION
*  This function is to configure the gpt timer.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
*------------------------------------------------------------------------*/
void drv_gpt_set_timer(kal_uint32 num, kal_uint32 time, kal_uint32 mode)
{
	ASSERT( (DRV_GPT_BASE_COUNTER_NUM <= num) && (num <= DRV_GPT_TOTAL_COUNTER) && (time <= 0xFFFFFUL) );
	DRV_WriteReg32(MDGPT_CNT_REG(num), time);

	mode &= MDGPT_CTRL_MODE_REPEAT | MDGPT_CTRL_MODE_ONESHOT;

	DRV_WriteReg32_NPW(MDGPT_CTRL_REG(num), mode);	//1<<1 enable timer
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_gpt_get_data
*
* DESCRIPTION
*  This function is to get the current data value.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
*------------------------------------------------------------------------*/
kal_uint32 drv_gpt_get_data(kal_uint32 num)
{
	ASSERT( (DRV_GPT_BASE_COUNTER_NUM <= num) && (num <= DRV_GPT_TOTAL_COUNTER));
	return DRV_Reg32(MDGPT_DATA_REG(num));
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_gpt_start_timer
*
* DESCRIPTION
*  This function is to start the gpt timer.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
*------------------------------------------------------------------------*/
void drv_gpt_start_timer(kal_uint32 num)
{
	unsigned int timer_status;

	ASSERT( (num >= DRV_GPT_BASE_COUNTER_NUM) && (DRV_GPT_TOTAL_COUNTER >= num) );

	timer_status = DRV_Reg32(MDGPT_CTRL_REG(num));

	if( timer_status & MDGPT_CTRL_MODE_ENABLE ){
		//ASSERT(0);
		return;
	}

	DRV_WriteReg32_NPW(MDGPT_CTRL_REG(num), timer_status | MDGPT_CTRL_MODE_ENABLE);
	Data_Sync_Barrier();
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_gpt_stop_timer
*
* DESCRIPTION
*  This function is to start the gpt timer.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
*------------------------------------------------------------------------*/
void drv_gpt_stop_timer(kal_uint32 num)
{
	unsigned int timer_status;

	ASSERT( (num >= DRV_GPT_BASE_COUNTER_NUM) && (DRV_GPT_TOTAL_COUNTER >= num) );

	timer_status = DRV_Reg32(MDGPT_CTRL_REG(num));

	DRV_WriteReg32_NPW(MDGPT_CTRL_REG(num), timer_status & (~MDGPT_CTRL_MODE_ENABLE));
	Data_Sync_Barrier();
}

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
#endif

#else /*!defined(DRV_GPT_OFF)*/

#endif /*!defined(DRV_GPT_OFF)*/

void startSystemTimer(void){
	IRQUnmask(MDGPT_INTR_ID(DRV_GPT_SYSTEM_TIMER));
	drv_gpt_start_timer(DRV_GPT_SYSTEM_TIMER);
}

