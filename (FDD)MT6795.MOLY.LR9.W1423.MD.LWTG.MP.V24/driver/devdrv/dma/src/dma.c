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
 *    dma.c
 *
 * Project:
 * --------
 *   WR8_Software
 *
 * Description:
 * ------------
 *   This Module defines the DMA driver.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_public_api.h" 
#include "drv_hisr.h"
#include "config_hw.h"
#include "cache_sw.h"
#include "init.h"
#include "uart_internal.h"
#include "uart_sw.h"
#include "us_timer.h"
#include "dma_sw.h"

#if defined(MT6752) && defined(__SMART_PHONE_MODEM__)
//HIF driver will use AP HIF1 DMA that memory address should be viewed as AP side
#include "ccci.h"
#endif

#if defined(__DMA2_SUPPORT__)
static kal_uint32 Remap_addr = 0;
#endif
/**************************** debug info*********** **********************************/
#include "kal_internal_api.h" //for kal_fatal_error_handler
#if defined(__DMA_DEBUG_TRACE__) //add the compile option into individual project header file
#include "kal_trace.h"
#endif
DMA_EXTRA_LOG DMA_debug_info = {0};
/*===================================================================================*/

/**************************** declaration prototype **********************************/
typedef void (* VOID_FUNC)(void);
void DMA_ERROR_LISR(void);
#if !defined(__FUE__)
static void dma_Vfifo_static_RecHandler_CallBack(kal_uint32 master);
static void dma_Vfifo_static_RecTimeOutHandler_CallBack(kal_uint32 master);
#endif
void DMA_Quick_Config(kal_uint32 dma_no, kal_uint32 dst);

#if defined(__SSDVT_TEST__) 
extern void DMA_LISR_SSDVT(void) ;
#endif

/*===================================================================================*/

/******************************* import API*******************************************/
#if defined(__DMA_UART_VIRTUAL_FIFO__)
extern void UART_TrxHandler_VFIFO(UART_PORT port);
extern void UART_RecHandler_VFIFO(UART_PORT port);
#if defined(__DMA_V3__)
extern void UART_RecTimeOutHandler(UART_PORT port);
#endif //__DMA_V3__
#endif //__DMA_UART_VIRTUAL_FIFO__
#if defined(__DMA_BT_VIRTUAL_FIFO__)
extern void BTIF_DMA_TX_Threshold_Handler_VFIFO(void);
extern void BTIF_DMA_RX_Threshold_Handler_VFIFO(void);
#endif //__DMA_BT_VIRTUAL_FIFO__
extern UARTStruct UARTPort[MAX_UART_PORT_NUM];
extern kal_uint32 kal_get_current_task_priority(void);
/*===================================================================================*/

#if defined(__MULTI_CORE_SHARED_DMA__) //driver for Hosted Dongle/smartphone
/*****************global structure of __DMA_SUPPORT_CALLBACK_LISR__ ******************/
#if defined (__DMA_SUPPORT_CALLBACK_LISR__)
//data structure for __DMA_SUPPORT_CALLBACK_LISR__ feature
typedef struct
{
    kal_uint32 free_index;
	kal_bool hisr_activated;
    kal_uint32 pending_int_bit[2]; /*suppose total DMA channel # < 32*/
#if defined(__DMA_V3__)   
	/*UART channel of __DMA_V3__ has 2 int flag*/
    kal_uint32 pending_int1_bit[2]; /*suppose total DMA channel # < 32*/
#endif
} DMA_pending_info_struct;

//MD side
/*DMA_pending_info_struct Error checking*/
#if (defined (DMA_VFIFO_CH_E) && (DMA_VFIFO_CH_E >31)) || (DMA_MAX_CHANNEL > 31)
    #error "Need to extern DMA_pending_info_struct's pending_int_bit for channel account > 31"
#endif
static DMA_pending_info_struct g_DMA_pending_info = 
{
    0,
    KAL_FALSE, 
    {0,0}
#if defined(__DMA_V3__)   
    ,{0,0}
#endif
};
static kal_uint32 DMA_lisr_callback_ch_bit = 0; /*suppose total DMA channel # < 32*/

#if defined(__DMA2_SUPPORT__)

//AP side
/*DMA_pending_info_struct Error checking*/
#if ( DMA2_MAX_CHANNEL > 31)
    #error "Need to extern DMA2_pending_info_struct's pending_int_bit for channel account > 31"
#endif
static DMA_pending_info_struct g_DMA2_pending_info = 
{
    0,
    KAL_FALSE, 
    {0,0}
#if defined(__DMA_V3__)   
    ,{0,0}
#endif
};
static kal_uint32 DMA2_lisr_callback_ch_bit = 0; /*suppose total DMA channel # < 32*/
#endif //__DMA2_SUPPORT__

#endif //__DMA_SUPPORT_CALLBACK_LISR__
/*===================================================================================*/

/************************ global structure GDMA/PDMA/VFIFO DMA  **********************/
//PC: DMA driver owner should port chip by chip 
SSDVT_DMA_INT_RW_ATTR
#if defined(MT6280)
//array index start from 1 instead of 0
VOID_FUNC DMA_LISR_FUNC[DMA_ALL_CHANNEL+1] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR   
};
#if defined(__DMA2_SUPPORT__)
//array index start from 1 instead of 0
VOID_FUNC DMA2_LISR_FUNC[DMA2_ALL_CHANNEL+1] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR 
};
static kal_uint32 PHY_DMA2_MASTER[DMA2_MAX_CHANNEL] = {DMA_MSDC, DMA_HIF0, DMA_I2C, DMA_I2C2};
#endif //__DMA2_SUPPORT__
static kal_uint32 PHY_DMA_MASTER[DMA_MAX_CHANNEL] = {DMA_SIM, DMA_SIM2};
static kal_uint32 PHY_DMA_VFF[DMA_VFF_CH_NUM] = {VDMA_UART1TX_CH, VDMA_UART1RX_CH};

#elif defined(MT6752)
//array index start from 1 instead of 0
VOID_FUNC DMA_LISR_FUNC[DMA_ALL_CHANNEL+1] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR   
};
#if defined(__DMA2_SUPPORT__)
//array index start from 1 instead of 0
VOID_FUNC DMA2_LISR_FUNC[DMA2_ALL_CHANNEL+1] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR
};
static kal_uint32 PHY_DMA2_MASTER[DMA2_MAX_CHANNEL] = {DMA_HIF1};
#endif //__DMA2_SUPPORT__
static kal_uint32 PHY_DMA_MASTER[DMA_MAX_CHANNEL] = {DMA_SW, DMA_SW2, DMA_SIM, DMA_SIM2};
static kal_uint32 PHY_DMA_VFF[DMA_VFF_CH_NUM] = {VDMA_UART1TX_CH, VDMA_UART1RX_CH};

#elif defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571)
//array index start from 1 instead of 0
VOID_FUNC DMA_LISR_FUNC[DMA_ALL_CHANNEL+1] =
{
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR,
   DMA_ERROR_LISR   
};
//SCIF will use GDMA 
static kal_uint32 PHY_DMA_MASTER[DMA_MAX_CHANNEL] = {DMA_SW, DMA_SW2, DMA_SIM, DMA_SIM2};
static kal_uint32 PHY_DMA_VFF[DMA_VFF_CH_NUM] = {VDMA_UART1TX_CH, VDMA_UART1RX_CH};

#else
	#error "Need to port for new chip"
#endif

/* MD side*/
//only record GDMA+PDMA channel
SSDVT_DMA_INT_RW_ATTR kal_uint32 DMA_Channel_Status = 0xffffffff; //0: mean the dma channel is used, 1: mean the dma channel is un-used
SSDVT_DMA_INT_RW_ATTR DMA_Master DMA_Owner[DMA_ALL_CHANNEL+1] = {0}; ////array index start from 1 instead of 0
#if defined(__DMA_V3__)
static DMA_SAVE_PARAM DMA_Save_Param[DMA_ALL_CHANNEL+1] __SECTION__(INTSRAM_ZI) __ZI__ ;
#endif
//record all DMA channel
#if defined(__DMA_LOW_POWER__)
DMA_PWRCTRL DMA_PWR = {0};
#endif

/*AP side*/
#if defined(__DMA2_SUPPORT__)
//only record GDMA+PDMA channel
kal_uint32 DMA2_Channel_Status = 0xffffffff; //0: used, 1: un-used
DMA_Master DMA2_Owner[DMA2_ALL_CHANNEL+1] = {0};
#if defined(__DMA_V3__)
#if defined(MT6752) && defined(__MD2__)
static DMA_SAVE_PARAM DMA2_Save_Param[DMA2_ALL_CHANNEL+1] __ZI__ ;
#else
static DMA_SAVE_PARAM DMA2_Save_Param[DMA2_ALL_CHANNEL+1] __SECTION__(INTSRAM_ZI) __ZI__ ;
#endif //MT6752 && __MD2__
#endif //__DMA_V3__
//record all DMA channel
#if  defined(__DMA_LOW_POWER__)
DMA_PWRCTRL DMA2_PWR = {0};
#endif
#endif //__DMA2_SUPPORT__
/*===================================================================================*/

#if defined(__DMA2_SUPPORT__)
/* AP side */
/*************************************************************************************
* FUNCTION
*	DMA2_Stop
*
* DESCRIPTION
*  Stop the dedicated DMA channel
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
static void DMA2_Stop(kal_uint8 channel)
{    
#if defined(__DMA_V3__)
	kal_uint32 temp;
    /* E1 DMA bug: if stopping or flushing a disabled DMA channel, an unexpected interrupt will be triggered.
        Disable interrupt control bit before stop DMA*/
    if( !DMA2_CheckRunStat(channel) )
    {
        DMA2_ACKI(channel);
        return;
    }
    temp = DRV_Reg32(DMA2_INT_EN(channel));
    DRV_WriteReg32(DMA2_INT_EN(channel), 0);
    DMA2_Stop_Now(channel);
    DMA2_WaitUntilRdy(channel);   // => pending 1 transaction time
    DMA2_ACKI(channel);
    /* E1 DMA bug: restore intr. control bit */
    DRV_WriteReg32(DMA2_INT_EN(channel), temp);
#endif	// __DMA_V3_
}

/*************************************************************************************
* FUNCTION
*	DMA2_Run
*
* DESCRIPTION
*  Start the dedicated DMA channel
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
static void DMA2_Run(kal_uint8 channel)
{
#if defined(__DMA_V3__)
	/* E1 DMA bug */
	if( DMA2_CheckRunStat(channel) )
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = channel;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_Run: ret_addr=%x, channel=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	DMA2_Stop(channel);
	DMA2_Start(channel);
#endif // __DMA_V3_  
}

#if  defined(__DMA_LOW_POWER__)
/*************************************************************************************
* FUNCTION
*	DMA2_SleepEnable
*
* DESCRIPTION
*   un-register DMA service that DMA clock could be gated when none uses DMA service
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
static void DMA2_SleepEnable(kal_uint8 channel)
{
#if !defined(__FUE__)
	kal_uint32 savedMask;
	savedMask = SaveAndSetIRQMask();
	DMA2_PWR.sleepDisable &= ~(1 << channel);
	if (DMA2_PWR.sleepDisable == 0)
		DMA2_SLEEP_ENABLE();
	RestoreIRQMask(savedMask);
#endif /* __FUE__ */
}

/*************************************************************************************
* FUNCTION
*	DMA2_SleepDisable
*
* DESCRIPTION
*   register DMA service that DMA clock should be un-gated
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
static void DMA2_SleepDisable(kal_uint8 channel)
{
#if !defined(__FUE__)
	kal_uint32 savedMask;
	savedMask = SaveAndSetIRQMask();
	DMA2_SLEEP_DISABLE();
	DMA2_PWR.sleepDisable |= (1 << channel);
	RestoreIRQMask(savedMask);
#endif /* __FUE__ */
}
#endif //DMA_LOW_POWER__

/*************************************************************************************
* FUNCTION
*	DMA2_FullSize_GetChannel
*
* DESCRIPTION
*   look up the unique id to allocate GDMA channel
*
* CALLS
*
* PARAMETERS
*	unique DMA master id
*
* RETURNS
*	the corresponding Master id 
*
* GLOBALS AFFECTED
*************************************************************************************/
static kal_uint8 DMA2_FullSize_GetChannel(kal_uint8 DMA_CODE)
{
#if defined(__DMA_V3__)
	kal_uint8 handle=0xff;
	kal_uint32 savedMask;
	savedMask = SaveAndSetIRQMask();
	if ((DMA2_Channel_Status & (0x01<<DMA_CODE)) != 0)
	{
		handle = DMA_CODE;
		DMA2_Channel_Status &= ~(0x01<<DMA_CODE);
		DMA2_Owner[handle] = (DMA_Master)DMA_CODE;
	}	   
	RestoreIRQMask(savedMask);

	if(handle == 0xff)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = DMA_CODE;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_FullSize_GetChannel: ret_addr=%x, DMA_CODE=%x, DMA_Status=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA2_Channel_Status);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_GDMA_GET, (kal_uint32)RETURN_ADDRESS());
	}
	return (handle|0x80);
#endif //__DMA_V3__   
}

/*************************************************************************************
* FUNCTION
*	DMA2_FullSize_FreeChannel
*
* DESCRIPTION
*   look up the unique id to free GDMA channel
*
* CALLS
*
* PARAMETERS
*	unique DMA master id
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
static void DMA2_FullSize_FreeChannel(kal_uint8 handle)
{
#if defined(__DMA_V3__)
	kal_uint32 savedMask;
	if ((DMA2_Channel_Status & (0x01<<handle)) != 0)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = handle;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_FullSize_FreeChannel: ret_addr=%x, DMA_CODE=%x, DMA_Status=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA2_Channel_Status);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_GDMA_FREE, (kal_uint32)RETURN_ADDRESS());
	}	 
	savedMask = SaveAndSetIRQMask();
	DMA2_Channel_Status |= (0x01<<handle);
	DMA2_Stop(handle);
	DMA2_Owner[handle] = DMA_IDLE;
	RestoreIRQMask(savedMask);
#endif //__DMA_V3__   
}

/*************************************************************************************
* FUNCTION
*	DMA2_GetChannel
*
* DESCRIPTION
*   look up the unique id to allocate Perihal DMA channel
*
* CALLS
*
* PARAMETERS
*	unique DMA master id
*
* RETURNS
*	the corresponding Master id 
*
* GLOBALS AFFECTED
*************************************************************************************/
static kal_uint8 DMA2_GetChannel(kal_uint8 DMA_CODE)
{  
#if defined(__DMA_V3__)
	kal_uint8 handle=0xff;
	kal_uint32 savedMask;
	savedMask = SaveAndSetIRQMask();
	if ((DMA2_Channel_Status & (0x01<<DMA_CODE)) != 0)
	{
		handle = DMA_CODE;		 
		//register DMA channel by clearing the ocrresponding status bit 
        DMA2_Channel_Status &= ~(0x01<<DMA_CODE);
        DMA2_Owner[handle] = (DMA_Master)DMA_CODE;
	}   
	RestoreIRQMask(savedMask);  

	if(handle == 0xff)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = DMA_CODE;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_GetChannel: ret_addr=%x, DMA_CODE=%x, DMA_Status=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA2_Channel_Status);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_PDMA_GET, (kal_uint32)RETURN_ADDRESS());
	}
	return (handle|0x80);
#endif // __DMA_V3_   
}

/*************************************************************************************
* FUNCTION
*	DMA2_FreeChannel
*
* DESCRIPTION
*   look up the unique id to free Perihal DMA channel
*
* CALLS
*
* PARAMETERS
*	unique DMA master id
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
static void DMA2_FreeChannel(kal_uint8 handle)
{
	kal_uint32 savedMask;
	if ((DMA2_Channel_Status & (0x01<<handle)) != 0)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = handle;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_FreeChannel: ret_addr=%x, DMA_CODE=%x, DMA_status=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA2_Channel_Status);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_PDMA_FREE, (kal_uint32)RETURN_ADDRESS());
	} 
	savedMask = SaveAndSetIRQMask();
	DMA2_Channel_Status |= (0x01<<handle);
	DMA2_Stop(handle);
	DMA2_Owner[handle] = DMA_IDLE;
	RestoreIRQMask(savedMask);
}

/*************************************************************************************
* FUNCTION
*	DMA2_Config_Internal
*
* DESCRIPTION
*   Configure the setting of dedicated DMA channel
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel number, user configured DMA parameters
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
static void DMA2_Config_Internal(kal_uint8 dma_no, DMA_INPUT *dma_menu, kal_bool fullsize, kal_bool b2w, kal_uint8 limit, kal_bool start)
{
	kal_uint32 dma_con = 0;
	//locally keep the configure of WPTO & WPPT
	kal_uint32 *wpto=NULL, *wppt=NULL;
	
	//error check the invalid situation
	if (DMA2_CheckRunStat(dma_no) || DMA2_CheckITStat(dma_no))
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}

	if(DMA2_Owner[dma_no] == DMA_IDLE)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, DMA2_Owner=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA2_Owner[dma_no]);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	
#if defined (__DMA_V3__)
	if (fullsize)
	{
		//ASSERT(dma_menu->count <= 0xfffff);
		if((dma_menu->count) << (dma_menu->size) > 0xfffff)
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.count = dma_menu->count << dma_menu->size;
			DMA_debug_info.dma_no = dma_no;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, COUNT=%x, DMA_NO=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.count, DMA_debug_info.dma_no);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_GDMA_COUNT, (kal_uint32)RETURN_ADDRESS());
		}
	}
	else
	{	
		if((dma_menu->count) << (dma_menu->size) > 0xffff)
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.count = dma_menu->count << dma_menu->size;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, COUNT=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.count);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_PDMA_COUNT, (kal_uint32)RETURN_ADDRESS());
		}
	}
#endif //__DMA_V3__

	/* DMA bug: DMA will never stop when start DMA with zero length */
	if( start == KAL_TRUE )
	{
		if(dma_menu->count == 0)
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.count = dma_menu->count;
			DMA_debug_info.dma_no = dma_no;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, COUNT=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.count, DMA_debug_info.dma_no);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_ZERO_COUNT, (kal_uint32)RETURN_ADDRESS());
		}
	}
	DMA2_Stop(dma_no);

#if !defined(__MTK_L1CACHEABLE__)
	/* check if the memory address is in cached region for MMU(ARM9/ARM11) platforms */
	if(dma_menu->type == DMA_HWTX || dma_menu->type == DMA_HWRX)
	{
		if (INT_QueryIsCachedRAM(((DMA_HWMENU *)dma_menu->menu)->addr, 1)) 
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.access_addr = (kal_uint32)((DMA_HWMENU *)dma_menu->menu)->addr;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, access_addr=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_CACHE_ACCESS, (kal_uint32)RETURN_ADDRESS());
		}
	}
	else if (dma_menu->type == DMA_SWCOPY) 
	{
		if (INT_QueryIsCachedRAM(((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr, 1)) 
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.access_addr = (kal_uint32)((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, access_addr=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_CACHE_ACCESS, (kal_uint32)RETURN_ADDRESS());
		}
		if (INT_QueryIsCachedRAM(((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr, 1)) 
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.access_addr = (kal_uint32)((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, access_addr=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_CACHE_ACCESS, (kal_uint32)RETURN_ADDRESS());
		}
	}
	else if(dma_menu->type == DMA_FULLSIZE_TXRINGBUFF || dma_menu->type == DMA_FULLSIZE_RXRINGBUFF)
	{
		if (INT_QueryIsCachedRAM(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source, 1)) 
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.access_addr = (kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, access_addr=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_CACHE_ACCESS, (kal_uint32)RETURN_ADDRESS());
		}
		if (INT_QueryIsCachedRAM(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination, 1)) 
		{
			//EXT_ASSERT(0, ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination, 0, 0);
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.access_addr = (kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, access_addr=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_CACHE_ACCESS, (kal_uint32)RETURN_ADDRESS());
		}
		if (INT_QueryIsCachedRAM(*(kal_uint32*)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO), 1)) 
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.access_addr = *(kal_uint32*)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, access_addr=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_CACHE_ACCESS, (kal_uint32)RETURN_ADDRESS());
		}
	}
#endif // !__MTK_L1CACHEABLE__ 

    switch(dma_menu->type) {
	case  DMA_HWTX:
#if defined(__DMA_V3__)
		ASSERT( dma_no > DMA2_FULL_CH_NUM );
		dma_con |= DMA_CON_TXCONTRL;

	#if defined(__DMA_SIM_TX_RX_SUPPORT__)
		//AB: temp solution for SIM modification
		if((DMA_SIM != (dma_no | 0x80)) && (DMA_SIM2 != (dma_no | 0x80)))
		{
		#if defined(MT6752) && defined(__SMART_PHONE_MODEM__)
			DRV_WriteReg32(DMA2_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr | Remap_addr);
		#else
			DRV_WriteReg32(DMA2_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
		#endif
		}
		else
		{
		#if defined(MT6752) && defined(__SMART_PHONE_MODEM__)
			DRV_WriteReg32(((DMA2_PGMADDR(dma_no)) + 0), ((DMA_HWMENU *)dma_menu->menu)->addr | Remap_addr);
		#else	
			DRV_WriteReg32(((DMA2_PGMADDR(dma_no)) + 0), ((DMA_HWMENU *)dma_menu->menu)->addr);
		#endif
		}
	#else	//__DMA_SIM_TX_RX_SUPPORT__
		#if defined(MT6752) && defined(__SMART_PHONE_MODEM__)
			DRV_WriteReg32(DMA2_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr | Remap_addr);
		#else	
			DRV_WriteReg32(DMA2_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
		#endif
	#endif //__DMA_SIM_TX_RX_SUPPORT__
	  
		if (dma_menu->fixed_pattern)
		{
			dma_con |= DMA_CON_FIXED_PATTERN;
		}
#endif //__DMA_V3__
		break;

	case  DMA_HWRX:
#if defined( __DMA_V3__)
		//Peripheral DMA fixed pattern (when FIX_EN is turn on, DIR would be ignore, DMA will always treat this ransfer as TX
		if(dma_menu->fixed_pattern != 0)
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.fixed_pattern = (kal_bool)dma_menu->fixed_pattern;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, fixed_pattern=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.fixed_pattern);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_HWRX_FP, (kal_uint32)RETURN_ADDRESS());
		}
		
		if(dma_no <= DMA2_FULL_CH_NUM)
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_NO, (kal_uint32)RETURN_ADDRESS());
		}
		dma_con |= DMA_CON_RXCONTRL;
		
	#if defined(__DMA_SIM_TX_RX_SUPPORT__)
		//AB: temp solution for SIM modification		  				
		if((DMA_SIM != (dma_no | 0x80)) && (DMA_SIM2 != (dma_no | 0x80)))
		{
		#if defined(MT6752) && defined(__SMART_PHONE_MODEM__)
			DRV_WriteReg32(DMA2_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr | Remap_addr);
		#else
			DRV_WriteReg32(DMA2_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
		#endif
		}
		else
		{
		#if defined(MT6752) && defined(__SMART_PHONE_MODEM__)
			DRV_WriteReg32(((DMA2_PGMADDR(dma_no)) + 4), ((DMA_HWMENU *)dma_menu->menu)->addr | Remap_addr);
		#else
			DRV_WriteReg32(((DMA2_PGMADDR(dma_no)) + 4), ((DMA_HWMENU *)dma_menu->menu)->addr);
		#endif
		}
	#else	 /* __DMA_SIM_TX_RX_SUPPORT__ */ 
		#if defined(MT6752) && defined(__SMART_PHONE_MODEM__)
			DRV_WriteReg32(DMA2_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr | Remap_addr);
		#else
			DRV_WriteReg32(DMA2_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
	    #endif
	#endif  /* __DMA_SIM_TX_RX_SUPPORT__ */
		
#endif //__DMA_V3__
		break;

    case DMA_SWCOPY:
#if defined( __DMA_V3__)
		DRV_WriteReg32(DMA2_SRC(dma_no), ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr);
		DRV_WriteReg32(DMA2_DST(dma_no), ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr);

		if( ((DMA_SWCOPYMENU *)dma_menu->menu)->fixed_raddr)
		{
			/* Fixed read access, src address must be 8byte alignment, burst length always be single */
			if(( ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr & 0x7 ) != 0)
			{
				DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
				DMA_debug_info.dma_no = dma_no;
				DMA_debug_info.access_addr = (kal_uint32)((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr;
				#if defined(__DMA_DEBUG_TRACE__) 
				kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, SRC=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
				#endif
				kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_UNALIGNMENT, (kal_uint32)RETURN_ADDRESS());
			}
			dma_con |= ((((DMA_SWCOPYMENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
			dma_con |= DMA_CON_SFIX;
			if( ((DMA_SWCOPYMENU *)dma_menu->menu)->req_ack_connect)
			{
				DMA_SWCOPYMENU* menu = (DMA_SWCOPYMENU *)dma_menu->menu;
				DRV_WriteReg32(DMA2_CONNECT(dma_no), (menu->req_ack_connect|menu->req_ack_dir|menu->req_ack_ratio));
			}											  		  
		}

		if( ((DMA_SWCOPYMENU *)dma_menu->menu)->fixed_waddr)
		{
			/* Fixed write access, dst address must be 8byte alignment, burst length always be single */
			if( ( ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr & 0x7 ) != 0 )
			{
				DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
				DMA_debug_info.dma_no = dma_no;
				DMA_debug_info.access_addr = (kal_uint32)((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr;
				#if defined(__DMA_DEBUG_TRACE__) 
				kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, DST=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
				#endif
				kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_UNALIGNMENT, (kal_uint32)RETURN_ADDRESS());
			}
			dma_con |= ((((DMA_SWCOPYMENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
			dma_con |= DMA_CON_DFIX;
			if( ((DMA_SWCOPYMENU *)dma_menu->menu)->req_ack_connect)
			{
				DMA_SWCOPYMENU* menu = (DMA_SWCOPYMENU *)dma_menu->menu;
				DRV_WriteReg32(DMA2_CONNECT(dma_no), (menu->req_ack_connect|menu->req_ack_dir|menu->req_ack_ratio));
			}											  		  
		}

		if (dma_menu->fixed_pattern)
		{
			dma_con |= DMA_CON_FIXED_PATTERN;
		}	  
#endif //__DMA_V3__
		break;
   
    case DMA_FULLSIZE_TXRINGBUFF:
#if defined( __DMA_V3__)
		if( fullsize == KAL_FALSE || dma_no > DMA_FULL_CH_NUM )
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.fullsize = fullsize;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, fullsize=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.fullsize);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_NO, (kal_uint32)RETURN_ADDRESS());
		}
		
		/*E1 Bug: Len2 can not be zero */
		if( *(kal_uint32*)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT) == 0 )
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.count = *(kal_uint32*)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, COUNT=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.count);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_ZERO_COUNT, (kal_uint32)RETURN_ADDRESS());
		}
		
		//priority fixed pattern > destination wrap > write fixed address
		if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_raddr)
		{
			/* Fixed read access, src address must be 8byte alignment */
			if( ( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source & 0x7 ) != 0 )
			{
				DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
				DMA_debug_info.dma_no = dma_no;
				DMA_debug_info.access_addr = (kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source;
				#if defined(__DMA_DEBUG_TRACE__) 
				kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, SRC=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
				#endif
				kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_UNALIGNMENT, (kal_uint32)RETURN_ADDRESS());
			}
			dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
			dma_con |= DMA_CON_SFIX;
		}
		
		if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_waddr)
		{
			/* Fixed write access, dst address must be 8byte alignment */ 
			if( ( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination & 0x7 ) != 0 )
			{
				DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
				DMA_debug_info.dma_no = dma_no;
				DMA_debug_info.access_addr = (kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination;
				#if defined(__DMA_DEBUG_TRACE__) 
				kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, DST=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
				#endif
				kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_UNALIGNMENT, (kal_uint32)RETURN_ADDRESS());
			}
			dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
			dma_con |= DMA_CON_DFIX;
		}
		
		if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO && ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT )
		{
			dma_con |= DMA_CON_WPEN|DMA_CON_WPSD; //wrap in destination

			wpto = (kal_uint32 *)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
			wppt = (kal_uint32 *)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
			DRV_WriteReg32(DMA2_WPTO(dma_no), *wpto);
			DRV_WriteReg32(DMA2_WPPT(dma_no), *wppt);

			DRV_WriteReg32(DMA2_SRC(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source);
			DRV_WriteReg32(DMA2_DST(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination);
		}

		if (dma_menu->fixed_pattern)
		{
			dma_con |= DMA_CON_FIXED_PATTERN;
		}

#endif //__DMA_V3__
		break;

    case DMA_FULLSIZE_RXRINGBUFF:
#if defined(__DMA_V3__)
		if(fullsize != KAL_TRUE || dma_no > DMA_FULL_CH_NUM)
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.fullsize = fullsize;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, fullsize=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.fullsize);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_NO, (kal_uint32)RETURN_ADDRESS());
		}
		
		/*E1 Bug: Len2 can not be zero */
		if(*(kal_uint32*)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT) == 0 )
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.count = *(kal_uint32*)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, COUNT=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.count);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_ZERO_COUNT, (kal_uint32)RETURN_ADDRESS());
		}
		
		//priority fixed pattern > destination wrap > write fixed address
		if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_raddr)
		{
			/* Fixed write access, src address must be 8byte alignment */ 
			if(( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source & 0x7 ) != 0 )
			{
				DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
				DMA_debug_info.dma_no = dma_no;
				DMA_debug_info.access_addr = (kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source;
				#if defined(__DMA_DEBUG_TRACE__) 
				kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, SRC=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
				#endif
				kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_UNALIGNMENT, (kal_uint32)RETURN_ADDRESS());
			}
			dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
			dma_con |= DMA_CON_SFIX;
		}

		if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_waddr)
		{
			/* Fixed write access, dst address must be 8byte alignment */		
			if(( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination & 0x7 ) != 0)
			{
				DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
				DMA_debug_info.dma_no = dma_no;
				DMA_debug_info.access_addr = (kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination;
				#if defined(__DMA_DEBUG_TRACE__) 
				kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, DST=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
				#endif
				kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_UNALIGNMENT, (kal_uint32)RETURN_ADDRESS());
			}
			dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
			dma_con |= DMA_CON_DFIX;
		}
		
		if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO && ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT )
		{
			dma_con |= DMA_CON_WPEN & (~DMA_CON_WPSD); //wrap in source

			wpto = (kal_uint32 *)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
			wppt = (kal_uint32 *)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
			DRV_WriteReg32(DMA2_WPTO(dma_no), *wpto);
			DRV_WriteReg32(DMA2_WPPT(dma_no), *wppt);
		 
			DRV_WriteReg32(DMA2_SRC(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source);
			DRV_WriteReg32(DMA2_DST(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination);
		}
		
		if (dma_menu->fixed_pattern)
		{
			dma_con |= DMA_CON_FIXED_PATTERN;
		}
	 
	#endif //__DMA_V3__
		break;	 
	  
    default:
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		DMA_debug_info.type = dma_menu->type;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x, TYPE=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.type);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_TYPE, (kal_uint32)RETURN_ADDRESS());
		break;
    }

#if defined(__DMA_V3__)
	//configure burst mode
	if (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE && ( dma_con & ( DMA_CON_SFIX | DMA_CON_DFIX ) ) == 0 )  
	{
        if(((DMA_TMODE *)(dma_menu->menu))->cycle==0)
        {
			dma_con |= (DMA_CON_BURST_SINGLE<<DMA_CON_BURST_OFFSET);
        }
        else
        {
			//cycle could be from 1 to 8
			dma_con |= ((((DMA_TMODE *)(dma_menu->menu))->cycle-1)&0x07)<<DMA_CON_BURST_OFFSET;
        }
	}
    else /* Fixed access, burst size must be single */
    {
        dma_con |= (DMA_CON_BURST_SINGLE<<DMA_CON_BURST_OFFSET);
    }
	
	//register the callback function when using interrupt DMA mode
    if (dma_menu->callback != NULL)
    {
	#if defined (MT6752)
		/** astone: 20120215
        * This is an intermediatly solution for wrong shard channel INT rounting during many chips.
        **/
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_Config_Internal: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_INTERRUPT_MODE, (kal_uint32)RETURN_ADDRESS());
	#endif
		DRV_WriteReg32(DMA2_INT_EN(dma_no), 1);
		DMA2_LISR_FUNC[dma_no] = dma_menu->callback;
    }
    else
    {
		DRV_WriteReg32(DMA2_INT_EN(dma_no), 0);
    }

	//cache the setting for quicky configure APIs
	if(dma_menu->type!=DMA_FULLSIZE_TXRINGBUFF && dma_menu->type!=DMA_FULLSIZE_RXRINGBUFF)
	{
		DMA2_Save_Param[dma_no].len1 = ((kal_uint32)dma_menu->count)<<(dma_menu->size);
		DMA2_Save_Param[dma_no].len2 = 0;
		DMA2_Save_Param[dma_no].size = dma_menu->size;
	}
	else
	{  
		DMA2_Save_Param[dma_no].len1 = (kal_uint32)*wppt<<(dma_menu->size);
		DMA2_Save_Param[dma_no].len2 = ((kal_uint32)dma_menu->count-(kal_uint32)(*wppt))<<(dma_menu->size);
		DMA2_Save_Param[dma_no].size = dma_menu->size;
	}

    #if defined(__DMA_SIM_TX_RX_SUPPORT__)
    //AB: temp solution for sim modification
    if((DMA_SIM != (dma_no | 0x80)) && (DMA_SIM2 != (dma_no | 0x80)))
	{
			DRV_WriteReg32(DMA2_COUNT(dma_no),DMA2_Save_Param[dma_no].len1);
			DRV_WriteReg32(DMA2_WPPT(dma_no),DMA2_Save_Param[dma_no].len2);	
	}
	else
	{
	  	if(DMA_HWTX == dma_menu->type)
		{
			DRV_WriteReg32(DMA2_COUNT(dma_no),DMA2_Save_Param[dma_no].len1);
		}
		else
		{
			DRV_WriteReg32(((DMA2_COUNT(dma_no)) + 4),DMA2_Save_Param[dma_no].len1);
		}
	}
    #else /* __DMA_SIM_TX_RX_SUPPORT__ */
    DRV_WriteReg32(DMA2_COUNT(dma_no),DMA2_Save_Param[dma_no].len1);
    DRV_WriteReg32(DMA2_WPPT(dma_no),DMA2_Save_Param[dma_no].len2);
    #endif  /* __DMA_SIM_TX_RX_SUPPORT__ */

    if( limit != 0 )
    {
       dma_con |= (( limit << DMA_CON_SLOW_OFFSET )& DMA_CON_SLOW_MASK);
	   dma_con |= DMA_CON_SLOW_EN;
    }

    DRV_WriteReg32(DMA2_CON(dma_no),dma_con);  
#endif //__DMA_V3__

	/* configuration is done and start the DMA */
    if (start) 
    {
       DMA2_Start(dma_no);
    }
}

/*************************************************************************************
* FUNCTION
*	DMA2_Quick_Config_Bidir
*
* DESCRIPTION
*   Configure src & dst address & count of dedicated DMA channel
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel number, user configured DMA parameters
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
static void DMA2_Quick_Config_Bidir(  kal_uint32 dma_no, kal_uint32 dst, kal_uint32 src, kal_uint32 count, DMA_Type type )
{
	if (DMA2_CheckRunStat(dma_no) || DMA2_CheckITStat(dma_no)) 
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_Quick_Config_Bidir: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	
	if(DMA2_Owner[dma_no] == DMA_IDLE)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_Quick_Config_Bidir: ret_addr=%x, DMA_CODE=%x, DMA2_Owner=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA2_Owner[dma_no]);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}

	/* DMA bug: DMA will never stop when start DMA with zero length */
	if(count == 0)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		DMA_debug_info.count = count;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_Quick_Config_Bidir: ret_addr=%x, DMA_CODE=%x, COUNT=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA_debug_info.count);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_ZERO_COUNT, (kal_uint32)RETURN_ADDRESS());
	}
	DMA2_Stop(dma_no);
	DRV_WriteReg32(DMA2_DST(dma_no), dst);
	DRV_WriteReg32(DMA2_SRC(dma_no), src);   
#if defined(__DMA_V3__)
	DMA2_Save_Param[dma_no].len1 = count<<DMA2_Save_Param[dma_no].size;
	DRV_WriteReg32(DMA2_COUNT(dma_no),DMA2_Save_Param[dma_no].len1);
#endif //__DMA_V3__  
	DMA2_Start(dma_no); 
}

/*************************************************************************************
* FUNCTION
*	DMA2_Quick_Config
*
* DESCRIPTION
*   Configure dst address of dedicated DMA channel
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel number, user configured DMA parameters
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
static void DMA2_Quick_Config(kal_uint32 dma_no, kal_uint32 dst)
{
	if (DMA2_CheckRunStat(dma_no) || DMA2_CheckITStat(dma_no)) 
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_Quick_Config: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}

	if(DMA2_Owner[dma_no] == DMA_IDLE)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_Quick_Config: ret_addr=%x, DMA_CODE=%x, DMA2_Owner=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA2_Owner[dma_no]);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	DMA2_Stop(dma_no);
#if defined(__DMA_V3__)
	DRV_WriteReg32(DMA2_COUNT(dma_no),DMA2_Save_Param[dma_no].len1);   
#endif //__DMA_V3__
	DRV_WriteReg32(DMA2_DST(dma_no), dst);
	DMA2_Start(dma_no);
}

/*************************************************************************************
* FUNCTION
*	DMA2_SRC_Config
*
* DESCRIPTION
*   Configure src address of dedicated DMA channel
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel number, user configured DMA parameters
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
static void DMA2_SRC_Config(kal_uint32 dma_no, kal_uint32 src)
{
	if (DMA2_CheckRunStat(dma_no) || DMA2_CheckITStat(dma_no)) 
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_SRC_Config: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}

	if(DMA2_Owner[dma_no] == DMA_IDLE)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_SRC_Config: ret_addr=%x, DMA_CODE=%x, DMA2_Owner=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA2_Owner[dma_no]);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	
	if (INT_QueryIsCachedRAM(src, 1)) 
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		DMA_debug_info.access_addr = src;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_SRC_Config: ret_addr=%x, DMA_CODE=%x, access_addr=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_CACHE_ACCESS, (kal_uint32)RETURN_ADDRESS());
	}
	DMA2_Stop(dma_no);
	DRV_WriteReg32(DMA2_SRC(dma_no), src);
}

/*************************************************************************************
* FUNCTION
*	DMA2_DST_Config
*
* DESCRIPTION
*   Configure dst address of dedicated DMA channel
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel number, user configured DMA parameters
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
static void DMA2_DST_Config(kal_uint32 dma_no, kal_uint32 dst)
{
	if (DMA2_CheckRunStat(dma_no) || DMA2_CheckITStat(dma_no)) 
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_DST_Config: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}

	if(DMA2_Owner[dma_no] == DMA_IDLE)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_DST_Config: ret_addr=%x, DMA_CODE=%x, DMA2_Owner=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA2_Owner[dma_no]);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	
	if (INT_QueryIsCachedRAM(dst, 1)) 
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		DMA_debug_info.access_addr = dst;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_DST_Config: ret_addr=%x, DMA_CODE=%x, access_addr=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_CACHE_ACCESS, (kal_uint32)RETURN_ADDRESS());
	}
	DMA2_Stop(dma_no);
	DRV_WriteReg32(DMA2_DST(dma_no), dst);
}

/*************************************************************************************
* FUNCTION
*	DMA2_Transfer_Size_config
*
* DESCRIPTION
*   configure transfer size of dedicated GDMA channel
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel number, user configured GDMA parameters
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA2_Transfer_Size_Config( kal_uint8 dma_no, DMA_INPUT *dma_menu )
{
	kal_uint32 dma_con = 0;
	//error check the invalid situation
	if (DMA2_CheckRunStat(dma_no) || DMA2_CheckITStat(dma_no) || dma_no >DMA2_MAX_FULL_CHANNEL)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_Transfer_Size_Config: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}

	if(DMA2_Owner[dma_no] == DMA_IDLE)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_Transfer_Size_Config: ret_addr=%x, DMA_CODE=%x, DMA2_Owner=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA2_Owner[dma_no]);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	
	if((dma_menu->count) <<(dma_menu->size)  > 0xfffff)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.count = dma_menu->count <<dma_menu->size;
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 		
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_Transfer_Size_config: ret_addr=%x, COUNT=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.count, DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_GDMA_COUNT, (kal_uint32)RETURN_ADDRESS());
	}
	
	/* DMA bug: DMA will never stop when start DMA with zero length */

	if(dma_menu->count == 0)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.count = dma_menu->count;
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_Transfer_Size_config: ret_addr=%x, COUNT=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.count, DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_ZERO_COUNT, (kal_uint32)RETURN_ADDRESS());
	}
	
	DMA2_Stop(dma_no);
		
#if defined(__DMA_V3__)
	//configure burst mode
	if (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE )  
	{
		if(((DMA_TMODE *)(dma_menu->menu))->cycle==0)
		{
			dma_con |= (DMA_CON_BURST_SINGLE<<DMA_CON_BURST_OFFSET);
		}
		else
		{	
			//cycle could be from 1 to 8
			dma_con |= ((((DMA_TMODE *)(dma_menu->menu))->cycle-1)&0x07)<<DMA_CON_BURST_OFFSET;
		}
	}
	else/* Fixed access, burst size must be single */
	{
		dma_con |= (DMA_CON_BURST_SINGLE<<DMA_CON_BURST_OFFSET);
	}
#endif

	DRV_WriteReg32(DMA2_CON(dma_no),dma_con);   	
}

/*************************************************************************************
* FUNCTION
*	DMA2_Mode_Config
*
* DESCRIPTION
*   configure interrupt/polling mode of dedicated DMA channel
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel number, user configured DMA parameters
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA2_Mode_Config(kal_uint8 dma_no, DMA_INPUT *dma_menu)
{
	if (DMA2_CheckRunStat(dma_no) || DMA2_CheckITStat(dma_no)) 
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_Mode_Config: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	
	if(DMA2_Owner[dma_no] == DMA_IDLE)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_Mode_Config: ret_addr=%x, DMA_CODE=%x, DMA2_Owner=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA2_Owner[dma_no]);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	
	//register the callback function when using interrupt DMA mode
	if (dma_menu->callback != NULL)
	{
		DRV_WriteReg32(DMA2_INT_EN(dma_no), 1);
		DMA_LISR_FUNC[dma_no] = dma_menu->callback;
	}
	else
	{
		DRV_WriteReg32(DMA2_INT_EN(dma_no), 0);
	}
}

/*************************************************************************************
* FUNCTION
*	DMA2_Start_Config
*
* DESCRIPTION
*   Start dedicated DMA channel
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel number, user configured DMA parameters
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
static void DMA2_Start_Config( kal_uint8 dma_no )
{
	if (DMA2_CheckRunStat(dma_no) || DMA2_CheckITStat(dma_no)) 
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_Start_Config: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	
	DMA2_Start(dma_no);
}

#if defined (__DMA_SUPPORT_CALLBACK_LISR__)
/*************************************************************************************
* FUNCTION
*	DMA2_Register_RT_CallBack
*
* DESCRIPTION
*   register the dedicated DMA channel using the feature "__DMA_SUPPORT_CALLBACK_LISR__"
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel id
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
static void DMA2_Register_RT_CallBack ( kal_uint8 dma_no ) 
{
    kal_uint32 savedMask;
    savedMask = SaveAndSetIRQMask();
    DMA2_lisr_callback_ch_bit |= (1<<dma_no);
    RestoreIRQMask(savedMask);
}

/*************************************************************************************
* FUNCTION
*	DMA2_Unregister_RT_CallBack
*
* DESCRIPTION
*   un-register the dedicated DMA channel using the feature "__DMA_SUPPORT_CALLBACK_LISR__"
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel id
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
static void DMA2_Unregister_RT_CallBack ( kal_uint8 dma_no ) 
{
    kal_uint32 savedMask;
    savedMask = SaveAndSetIRQMask();
    DMA2_lisr_callback_ch_bit &= ~(1<<dma_no);
	RestoreIRQMask(savedMask);
}
#endif //__DMA_SUPPORT_CALLBACK_LISR__

/*************************************************************************************
* FUNCTION
*	DMA2_HISR
*
* DESCRIPTION
*   HISR for processing AP side GDMA/PDMA when using interrupt mode
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
*************************************************************************************/
static void DMA2_HISR(void)
{
	kal_uint8 index;
#if defined (__DMA_SUPPORT_CALLBACK_LISR__)
	kal_uint32 pend_info_idx;
    kal_uint32 savedMask;

	/*get the pending channel info and update the free_index*/
	savedMask = SaveAndSetIRQMask();
	pend_info_idx = g_DMA2_pending_info.free_index;
	g_DMA2_pending_info.hisr_activated = KAL_FALSE;
	g_DMA2_pending_info.free_index = (g_DMA2_pending_info.free_index + 1) % (sizeof(g_DMA2_pending_info.pending_int_bit)/sizeof(g_DMA2_pending_info.pending_int_bit[0]));
	/*reset the free one */
	g_DMA2_pending_info.pending_int_bit[g_DMA2_pending_info.free_index] = 0;
	RestoreIRQMask(savedMask);

#endif//#if defined (__DMA_SUPPORT_CALLBACK_LISR__)

    for(index = 0; index < DMA2_MAX_CHANNEL; index++)
	{
		kal_uint32 index_hw;
	    index_hw = ( PHY_DMA2_MASTER[index] & 0x7F);	   
#if defined (__DMA_SUPPORT_CALLBACK_LISR__)
        if ( g_DMA2_pending_info.pending_int_bit[pend_info_idx] & (1 << (index_hw)) )
        {
            DMA2_LISR_FUNC[index_hw]();
        }
#else //__DMA_SUPPORT_CALLBACK_LISR__
	
    #if defined(__DMA_V3__)
		if( DRV_Reg32(DMA2_GLBST_INT) & ( 1<<(index_hw-1) ) ) 
	    {
	       DMA2_Stop(index_hw);
	       DMA2_ACKI(index_hw);
           DMA2_LISR_FUNC[index_hw]();
	    }
	#endif //__DMA_V3__	  
#endif //__DMA_SUPPORT_CALLBACK_LISR__
	}

#if !defined(__DMA_SUPPORT_CALLBACK_LISR__)	  
	#if defined(DMA2_IRQ_CODE)
	IRQClearInt(DMA2_IRQ_CODE);
	IRQUnmask(DMA2_IRQ_CODE);
	#endif
#endif //!__DMA_SUPPORT_CALLBACK_LISR__			
}

/*************************************************************************************
* FUNCTION
*	DMA2_LISR
*
* DESCRIPTION
*   LISR for processing AP side GDMA/PDMA when using interrupt mode
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
*************************************************************************************/
static void DMA2_LISR(void)
{
#if defined(__DMA_SUPPORT_CALLBACK_LISR__)	  
    kal_uint32 index, intsta;
#endif //__DMA_SUPPORT_CALLBACK_LISR__	  

#if defined(DMA2_IRQ_CODE)
    IRQMask(DMA2_IRQ_CODE);
#endif

#if defined(__DMA_SUPPORT_CALLBACK_LISR__)	  
    /*get the finished DMA channel info and close channel-- start*/
    for(index = 0; index < DMA2_MAX_CHANNEL; index++)
    {
		kal_uint32 index_hw;
	    index_hw = ( PHY_DMA2_MASTER[index] & 0x7F);
	
    #if defined(__DMA_V3__)   
        /*because interrupt flag will be 1 after DMA finishs its job even the interrupt is disabled, we need to check inten too*/
        intsta = (DRV_Reg32(DMA2_INT_EN(index_hw))&1) != 0 ?  DRV_Reg32(DMA2_INTSTA(index_hw)) : 0 ;
    #endif
        if ( intsta & DMA_INTSTA_BIT)
        {
            /*certain channel should not income twice before it is handled in call-back*/
            EXT_ASSERT((g_DMA2_pending_info.pending_int_bit[g_DMA2_pending_info.free_index] & (1<<(index_hw))) == 0, 
                      g_DMA2_pending_info.pending_int_bit[g_DMA2_pending_info.free_index] , (index_hw), g_DMA2_pending_info.free_index);
            DMA2_ACKI(index_hw);
            if( DMA2_lisr_callback_ch_bit & (1<<(index_hw)) )
            {
               DMA2_LISR_FUNC[index_hw]();
            } 
            else
	        {
	           g_DMA2_pending_info.pending_int_bit[g_DMA2_pending_info.free_index] |= (1<<(index_hw));
	        }
        }
    }	

	if( g_DMA2_pending_info.hisr_activated == KAL_FALSE && (g_DMA2_pending_info.pending_int_bit[g_DMA2_pending_info.free_index]) )
	{
	#if !defined(__FUE__)
		(DRV_DMA2_HISR_ID);
		g_DMA2_pending_info.hisr_activated = KAL_TRUE;
	#else 
		DMA2_HISR();
	#endif
	}
	#if defined(DMA2_IRQ_CODE)
	IRQClearInt(DMA2_IRQ_CODE);
	IRQUnmask(DMA2_IRQ_CODE);
	#endif
#else   //__DMA_SUPPORT_CALLBACK_LISR__

	#if !defined(__FUE__)
	drv_active_hisr(DRV_DMA2_HISR_ID);
	#else 
	DMA2_HISR();
	#endif
#endif //__DMA_SUPPORT_CALLBACK_LISR__
}

/*************************************************************************************
* FUNCTION
*	DMA2_Ini
*
* DESCRIPTION
*   initialize AP DMA 
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
*************************************************************************************/
static void DMA2_Ini(void)	
{
	kal_uint8 index;
   
#if defined(MT6752) && defined(__SMART_PHONE_MODEM__)
	kal_int32 status = 0;
	//API: CCCI_EXTERN kal_int32 ccci_misc_info_feature_support(kal_uint32 op_id, kal_uint32 len, void *pReturn);
	status = ccci_misc_data_feature_support(CCMSG_ID_MISCINFO_HIF_DMA_REMAP, 4, &Remap_addr);
	if(status != CCCI_MISC_INFO_SUPPORT || status == CCCI_MISC_INFO_NOT_EXIST )
	{
	#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA2_Ini: AP/MD CCCI version doesn't support remapping\r\n");
	#endif
		ASSERT(0); // expected result
	}
#else
	Remap_addr = 0;
#endif
   
	for (index = 0; index <= DMA2_MAX_CHANNEL; index++) 
	{
		DMA2_Owner[index] = DMA_IDLE;
		DMA2_LISR_FUNC[index] = DMA_ERROR_LISR;
	}

	DMA2_POWER_ON();

#if defined(DMA2_IRQ_CODE)
	IRQ_Register_LISR(DMA2_IRQ_CODE, DMA2_LISR, "DMA2 handler");
	DRV_Register_HISR(DRV_DMA2_HISR_ID, DMA2_HISR);
	IRQSensitivity(DMA2_IRQ_CODE,LEVEL_SENSITIVE);
	IRQUnmask(DMA2_IRQ_CODE);    
#endif
}

#endif //__DMA2_SUPPORT__

/* MD side: API should be placed in TCM for DCM DVT */
/*************************************************************************************
* FUNCTION
*	DMA_Stop
*
* DESCRIPTION
*   Stop the dedicated DMA channel 
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
SSDVT_DMA_INT_CODE_ATTR void DMA_Stop(kal_uint8 channel)
{
	kal_uint32 temp;
   
#if defined(__DMA2_SUPPORT__)
	if( (channel & 0x80) == 0x80 )
	{
		DMA2_Stop((channel&0x7F));
		return;
	}
#endif //__DMA2_SUPPORT__

#if defined(__DMA_V3__)
	/* E1 DMA bug: if stopping or flushing a disabled DMA channel, an unexpected interrupt will be triggered. 
       Disable interrupt control bit before stop DMA*/
	if( !DMA_CheckRunStat(channel) )
	{
		DMA_ACKI(channel);
		return;   
	}
	temp = DRV_Reg32(DMA_INT_EN(channel));
	DRV_WriteReg32(DMA_INT_EN(channel), 0);    
	DMA_Stop_Now(channel);
	DMA_WaitUntilRdy(channel);   // => pending 1 transaction time
	DMA_ACKI(channel);        
	/* E1 DMA bug: restore intr. control bit */
	DRV_WriteReg32(DMA_INT_EN(channel), temp);   
#endif	// __DMA_V3_
}

/*************************************************************************************
* FUNCTION
*	DMA_Run
*
* DESCRIPTION
*   Start the dedicated DMA channel 
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA_Run(kal_uint8 channel)
{
#if defined(__DMA2_SUPPORT__)
	if( (channel & 0x80) == 0x80 )
	{
		DMA2_Run((channel&0x7F));
		return;
	}
#endif //__DMA2_SUPPORT__

#if defined(__DMA_V3__)
   /* E1 DMA bug */
	if( DMA_CheckRunStat(channel) )
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = channel;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Run: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	DMA_Stop(channel);
	DMA_Start(channel);
#endif // __DMA_V3_  
}

/*************************************************************************************
* FUNCTION
*	DMA_WaitforDone
*
* DESCRIPTION
*   Start the dedicated DMA channel 
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA_WaitforDone(kal_uint8 channel)
{
#if defined(__DMA2_SUPPORT__)
	if( (channel & 0x80) == 0x80 )
	{
		DMA2_WaitUntilRdy((channel&0x7F));
		return;
	}
#endif //__DMA2_SUPPORT__
	DMA_WaitUntilRdy(channel); 
	return ;
}

#if defined(__DMA_V3__)
/*************************************************************************************
* FUNCTION
*	DMA_CleanUp
*
* DESCRIPTION
*   flush the dedicated DMA channel 
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA_CleanUp(kal_uint8 channel)
{
	#if defined(__DMA2_SUPPORT__)
	if( (channel & 0x80) == 0x80 )
	{
		DMA2_Flush((channel&0x7F));
		return;
	} 
	#endif //__DMA2_SUPPORT__
	if( (channel & 0x80) == 0 )
	{
		DMA_Flush(channel);
	}
	DMA_WaitforDone(channel);
}
#endif //#if defined(__DMA_V3__)

#if defined(__DMA_LOW_POWER__)
/*************************************************************************************
* FUNCTION
*	DMA_SleepEnable
*
* DESCRIPTION
*   un-register DMA service that DMA clock could be gated when none uses DMA service 
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA_SleepEnable(kal_uint8 channel)
{
#if !defined(__FUE__)
	kal_uint32 savedMask; 
	if(channel == 0)	
		return;
	#if defined(__DMA2_SUPPORT__)
	if( (channel & 0x80) == 0x80 )
	{
		DMA2_SleepEnable((channel&0x7F));
		return;
	}
	#endif //__DMA2_SUPPORT__
	savedMask = SaveAndSetIRQMask();
    DMA_PWR.sleepDisable &= ~(1 << channel);
	if (DMA_PWR.sleepDisable == 0) 
	{
		DMA_SLEEP_ENABLE();
	}
	RestoreIRQMask(savedMask);
#endif /* __FUE__ */
}

/*************************************************************************************
* FUNCTION
*	DMA_SleepDisable
*
* DESCRIPTION
*   register DMA service that DMA clock should be un-gated
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA_SleepDisable(kal_uint8 channel)
{
#if !defined(__FUE__)
	kal_uint32 savedMask;   
	if(channel == 0)	
		return;
	#if defined(__DMA2_SUPPORT__)
	if( (channel & 0x80) == 0x80 )
	{
		DMA2_SleepDisable((channel&0x7F));
		return;
	}
	#endif //__DMA2_SUPPORT__
	savedMask = SaveAndSetIRQMask();
	if (DMA_PWR.sleepDisable == 0) 
	{
		DMA_SLEEP_DISABLE();
	}
	DMA_PWR.sleepDisable |= (1 << channel);
	RestoreIRQMask(savedMask);
#endif /* __FUE__ */
}
#endif //__DMA_LOW_POWER__

/*************************************************************************************
* FUNCTION
*	DMA_FullSize_GetChannel
*
* DESCRIPTION
*   look up the unique id to allocate GDMA channel
*
* CALLS
*
* PARAMETERS
*	unique DMA master id
*
* RETURNS
*	the corresponding Master id 
*
* GLOBALS AFFECTED
*************************************************************************************/
SSDVT_DMA_INT_CODE_ATTR kal_uint8 DMA_FullSize_GetChannel(DMA_Master DMA_CODE)
{
	kal_uint8 handle=0xff;
	kal_uint32 savedMask;

#if defined(__DMA2_SUPPORT__)
	if( (DMA_CODE & 0x80) == 0x80 )
		return DMA2_FullSize_GetChannel((DMA_CODE&0x7F));
#endif //__DMA2_SUPPORT__

#if defined(__DMA_V3__)

	savedMask = SaveAndSetIRQMask();

	if ((DMA_Channel_Status & (0x01<<DMA_CODE)) != 0)
	{
        handle = DMA_CODE;
        DMA_Channel_Status &= ~(0x01<<DMA_CODE);
        DMA_Owner[handle] = DMA_CODE;
	}

	RestoreIRQMask(savedMask);

	if(handle == 0xff || handle > DMA_MAX_FULL_CHANNEL)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = DMA_CODE;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_FullSize_GetChannel: ret_addr=%x, DMA_CODE=%x, DMA_Status=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA_Channel_Status);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_GDMA_GET, (kal_uint32)RETURN_ADDRESS());
	}
	return handle;
#endif //__DMA_V3__   
}

/*************************************************************************************
* FUNCTION
*	DMA_FullSize_FreeChannel
*
* DESCRIPTION
*   look up the unique id to free GDMA channel
*
* CALLS
*
* PARAMETERS
*	unique DMA master id
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
SSDVT_DMA_INT_CODE_ATTR void DMA_FullSize_FreeChannel(kal_uint8 handle)
{
	kal_uint32 savedMask;

#if defined(__DMA2_SUPPORT__)
	if( (handle & 0x80) == 0x80 )
	{
		DMA2_FullSize_FreeChannel((handle&0x7F));
		return;
	}
#endif //__DMA2_SUPPORT__
	
	if ((DMA_Channel_Status & (0x01<<handle)) != 0)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = handle;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_FullSize_FreeChannel: ret_addr=%x, DMA_CODE=%x, DMA_Status=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA_Channel_Status);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_GDMA_FREE, (kal_uint32)RETURN_ADDRESS());
	}	 
	savedMask = SaveAndSetIRQMask();
	DMA_Channel_Status |= (0x01<<handle);
	DMA_Stop(handle);
	DMA_Owner[handle] = DMA_IDLE;
	RestoreIRQMask(savedMask);
}

/*************************************************************************************
* FUNCTION
*	DMA_GetChannel
*
* DESCRIPTION
*   look up the unique id to allocate Perihal DMA channel
*
* CALLS
*
* PARAMETERS
*	unique DMA master id
*
* RETURNS
*	the corresponding Master id 
*
* GLOBALS AFFECTED
*************************************************************************************/
kal_uint8 DMA_GetChannel(DMA_Master DMA_CODE)
{
	kal_uint8 handle=0xff;
	kal_uint32 savedMask;

#if defined(__DMA2_SUPPORT__)
	if( (DMA_CODE & 0x80) == 0x80 )
		return DMA2_GetChannel((DMA_CODE&0x7F));
#endif //__DMA2_SUPPORT__

#if defined(__DMA_V3__)
	savedMask = SaveAndSetIRQMask();
	if ((DMA_Channel_Status & (0x01<<DMA_CODE)) != 0)
	{
        handle = DMA_CODE;
        DMA_Channel_Status &= ~(0x01<<DMA_CODE);
        DMA_Owner[handle] = DMA_CODE;
	}
	RestoreIRQMask(savedMask);

	if(handle == 0xff)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = DMA_CODE;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_GetChannel: ret_addr=%x, DMA_CODE=%x, DMA_Status=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA_Channel_Status);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_PDMA_GET, (kal_uint32)RETURN_ADDRESS());
	}
	return handle;
#endif // __DMA_V3_   
}

/*************************************************************************************
* FUNCTION
*	DMA_FreeChannel
*
* DESCRIPTION
*   look up the unique id to free Perihal DMA channel
*
* CALLS
*
* PARAMETERS
*	unique DMA master id
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA_FreeChannel(kal_uint8 handle)
{
	kal_uint32 savedMask;
#if defined(__DMA2_SUPPORT__)
	if( (handle & 0x80) == 0x80 )
	{
		DMA2_FreeChannel((handle&0x7F));
		return;
	}
#endif //__DMA2_SUPPORT__
   
	if ((DMA_Channel_Status & (0x01<<handle)) != 0)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = handle;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_FreeChannel: ret_addr=%x, DMA_CODE=%x, DMA_status=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA_Channel_Status);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_PDMA_FREE, (kal_uint32)RETURN_ADDRESS());
	} 
	savedMask = SaveAndSetIRQMask();
	DMA_Channel_Status |= (0x01<<handle);
	DMA_Stop(handle);
	DMA_Owner[handle] = DMA_IDLE;
	RestoreIRQMask(savedMask);
}

/*************************************************************************************
* FUNCTION
*	DMA_Config_Internal
*
* DESCRIPTION
*   Configure the setting of dedicated DMA channel
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel number, user configured DMA parameters
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
SSDVT_DMA_INT_CODE_ATTR void DMA_Config_Internal(kal_uint8 dma_no, DMA_INPUT *dma_menu, kal_bool fullsize, kal_bool b2w, kal_uint8 limit, kal_bool start)
{
	kal_uint32 dma_con = 0;
	//locally keep the configure of WPTO & WPPT
	kal_uint32 *wpto=NULL, *wppt=NULL;

#if defined(__DMA2_SUPPORT__)
	if( (dma_no & 0x80) == 0x80 )
	{
	//error check for incorrcet low power feature usage
	#if  defined(__DMA_LOW_POWER__)
		if(DMA2_PWR.sleepDisable==0)
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, DMA2_PWR=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no,DMA2_PWR.sleepDisable);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
		}	
	#endif	
		DMA2_Config_Internal((dma_no&0x7F), dma_menu, fullsize, b2w, limit, start);
		return;
	}
#endif //__DMA2_SUPPORT__
   
    //error check for incorrcet low power feature usage
	#if  defined(__DMA_LOW_POWER__)
	if(DMA_PWR.sleepDisable==0)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, DMA_PWR=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no,DMA_PWR.sleepDisable);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	#endif
	
	//error check the invalid situation
	if (DMA_CheckRunStat(dma_no) || DMA_CheckITStat(dma_no))
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}

	if(DMA_Owner[dma_no] == DMA_IDLE)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, DMA_Owner=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA_Owner[dma_no]);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	
#if defined (__DMA_V3__)
	if (fullsize)
	{
		//ASSERT(dma_menu->count <= 0xfffff);
		if((dma_menu->count)<<(dma_menu->size) > 0xfffff)
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.count = dma_menu->count << dma_menu->size;
			DMA_debug_info.dma_no = dma_no;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, COUNT=%x, DMA_NO=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.count, DMA_debug_info.dma_no);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_GDMA_COUNT, (kal_uint32)RETURN_ADDRESS());
		}
	}
	else
	{
		if((dma_menu->count)<<(dma_menu->size)  > 0xffff)
		{ 
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.count = dma_menu->count << dma_menu->size;
			DMA_debug_info.dma_no = dma_no;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, COUNT=%x, DMA_NO=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.count, DMA_debug_info.dma_no);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_PDMA_COUNT, (kal_uint32)RETURN_ADDRESS());
		}
	}
#endif //__DMA_V3__
	/* DMA bug: DMA will never stop when start DMA with zero length */
	if( start == KAL_TRUE && dma_no < DMA_VFIFO_PHY_CH_S)
	{
		if(dma_menu->count == 0)
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.count = dma_menu->count;
			DMA_debug_info.dma_no = dma_no;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, COUNT=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.count, DMA_debug_info.dma_no);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_ZERO_COUNT, (kal_uint32)RETURN_ADDRESS());
		}
	}
	DMA_Stop(dma_no);

	#if !defined(__MTK_L1CACHEABLE__)
	/* check if the memory address is in cached region for MMU(ARM9/ARM11) platforms */
	if(dma_menu->type == DMA_HWTX || dma_menu->type == DMA_HWRX)
	{
		if (INT_QueryIsCachedRAM(((DMA_HWMENU *)dma_menu->menu)->addr, 1)) 
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.access_addr = (kal_uint32)((DMA_HWMENU *)dma_menu->menu)->addr;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, access_addr=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_CACHE_ACCESS, (kal_uint32)RETURN_ADDRESS());
		}
	}
	else if (dma_menu->type == DMA_SWCOPY) 
	{
		if (INT_QueryIsCachedRAM(((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr, 1)) 
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.access_addr = (kal_uint32)((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, access_addr=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_CACHE_ACCESS, (kal_uint32)RETURN_ADDRESS());
		}
		if (INT_QueryIsCachedRAM(((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr, 1)) 
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.access_addr = (kal_uint32)((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, access_addr=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_CACHE_ACCESS, (kal_uint32)RETURN_ADDRESS());
		}
	}
	else if(dma_menu->type == DMA_FULLSIZE_TXRINGBUFF || dma_menu->type == DMA_FULLSIZE_RXRINGBUFF)
	{
		if (INT_QueryIsCachedRAM(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source, 1)) 
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.access_addr = (kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, access_addr=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_CACHE_ACCESS, (kal_uint32)RETURN_ADDRESS());
		}
		if (INT_QueryIsCachedRAM(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination, 1)) 
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.access_addr = (kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, access_addr=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_CACHE_ACCESS, (kal_uint32)RETURN_ADDRESS());
		}
		if (INT_QueryIsCachedRAM(*(kal_uint32*)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO), 1)) 
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.access_addr = *(kal_uint32*)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, access_addr=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_CACHE_ACCESS, (kal_uint32)RETURN_ADDRESS());
		}
	}
	#endif /* !__MTK_L1CACHEABLE__ */

	switch(dma_menu->type) {
	case  DMA_HWTX:
#if defined( __DMA_V3__)
		ASSERT( dma_no > DMA_FULL_CH_NUM );
		dma_con |= DMA_CON_TXCONTRL;

	#if defined(__DMA_SIM_TX_RX_SUPPORT__)
        //AB: temp solution for SIM modification
	    if(DMA_SIM != dma_no && DMA_SIM2 != dma_no)
		{
            DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
        }
        else
		{
            DRV_WriteReg32(((DMA_PGMADDR(dma_no)) + 0), ((DMA_HWMENU *)dma_menu->menu)->addr);
        }
	#else  /* __DMA_SIM_TX_RX_SUPPORT__ */
        DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
	#endif /* __DMA_SIM_TX_RX_SUPPORT__ */
	  
		if (dma_menu->fixed_pattern)
		{
			dma_con |= DMA_CON_FIXED_PATTERN;
		}
#endif //__DMA_V3__
		break;

	case  DMA_HWRX:
#if defined( __DMA_V3__)
		//Peripheral DMA fixed pattern (when FIX_EN is turn on, DIR would be ignore, DMA will always treat this ransfer as TX
		if(dma_menu->fixed_pattern != 0)
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.fixed_pattern = (kal_bool)dma_menu->fixed_pattern;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, fixed_pattern=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.fixed_pattern);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_HWRX_FP, (kal_uint32)RETURN_ADDRESS());
		}

		if(dma_no <= DMA_FULL_CH_NUM)
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_NO, (kal_uint32)RETURN_ADDRESS());
		}
		dma_con |= DMA_CON_RXCONTRL;
		
	#if defined(__DMA_SIM_TX_RX_SUPPORT__)
        //AB: temp solution for SIM modification		 
	    if(DMA_SIM != dma_no && DMA_SIM2 != dma_no)
		{
			DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
        }
        else
		{
            DRV_WriteReg32(((DMA_PGMADDR(dma_no)) + 4), ((DMA_HWMENU *)dma_menu->menu)->addr);
        }
	#else 	// __DMA_SIM_TX_RX_SUPPORT__
        DRV_WriteReg32(DMA_PGMADDR(dma_no), ((DMA_HWMENU *)dma_menu->menu)->addr);
	#endif  // __DMA_SIM_TX_RX_SUPPORT__
  
#endif //__DMA_V3__
		break;

	case DMA_SWCOPY:   	
#if defined( __DMA_V3__)
		DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr);
		DRV_WriteReg32(DMA_DST(dma_no), ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr);

		if( ((DMA_SWCOPYMENU *)dma_menu->menu)->fixed_raddr)
		{
			/* Fixed read access, src address must be 8byte alignment */
			if(( ((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr & 0x7 ) != 0)
			{
				DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
				DMA_debug_info.dma_no = dma_no;
				DMA_debug_info.access_addr = (kal_uint32)((DMA_SWCOPYMENU *)dma_menu->menu)->srcaddr;
				#if defined(__DMA_DEBUG_TRACE__) 
				kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, SRC=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
				#endif
				kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_UNALIGNMENT, (kal_uint32)RETURN_ADDRESS());
			}
			dma_con |= ((((DMA_SWCOPYMENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
			dma_con |= DMA_CON_SFIX;
			if( ((DMA_SWCOPYMENU *)dma_menu->menu)->req_ack_connect)
			{
				DMA_SWCOPYMENU* menu = (DMA_SWCOPYMENU *)dma_menu->menu;
				DRV_WriteReg32(DMA_CONNECT(dma_no), (menu->req_ack_connect|menu->req_ack_dir|menu->req_ack_ratio));
			}											  
		}

		if( ((DMA_SWCOPYMENU *)dma_menu->menu)->fixed_waddr)
		{
			/* Fixed write access, dst address must be 8byte alignment */
			if( ( ((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr & 0x7 ) != 0 )
			{
				DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
				DMA_debug_info.dma_no = dma_no;
				DMA_debug_info.access_addr = (kal_uint32)((DMA_SWCOPYMENU *)dma_menu->menu)->dstaddr;
				#if defined(__DMA_DEBUG_TRACE__) 
				kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, DST=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
				#endif
				kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_UNALIGNMENT, (kal_uint32)RETURN_ADDRESS());
			}
			dma_con |= ((((DMA_SWCOPYMENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
			dma_con |= DMA_CON_DFIX;
			if( ((DMA_SWCOPYMENU *)dma_menu->menu)->req_ack_connect)
			{
				DMA_SWCOPYMENU* menu = (DMA_SWCOPYMENU *)dma_menu->menu;
				DRV_WriteReg32(DMA_CONNECT(dma_no), (menu->req_ack_connect|menu->req_ack_dir|menu->req_ack_ratio));
			}											  
		}

		if (dma_menu->fixed_pattern)
		{
			dma_con |= DMA_CON_FIXED_PATTERN;
		}	  
#endif //__DMA_V3__
		break;

	case DMA_FULLSIZE_TXRINGBUFF:
#if defined( __DMA_V3__)
		if( fullsize != KAL_TRUE || dma_no > DMA_FULL_CH_NUM )
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.fullsize = fullsize;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, fullsize=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.fullsize);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_NO, (kal_uint32)RETURN_ADDRESS());
		}
		
		/*E1 Bug: Len2 can not be zero */
		if( *(kal_uint32*)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT) == 0 )
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.count = *(kal_uint32*)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, COUNT=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.count);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_ZERO_COUNT, (kal_uint32)RETURN_ADDRESS());
		}
		
		//priority fixed pattern > destination wrap > write fixed address
		if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_raddr)
		{
			/* Fixed read access, src address must be 8byte alignment */
			if( ( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source & 0x7 ) != 0 )
			{
				DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
				DMA_debug_info.dma_no = dma_no;
				DMA_debug_info.access_addr = (kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source;
				#if defined(__DMA_DEBUG_TRACE__) 
				kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, SRC=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
				#endif
				kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_UNALIGNMENT, (kal_uint32)RETURN_ADDRESS());
			}
			dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
			dma_con |= DMA_CON_SFIX;
		}
		
		if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_waddr)
		{
			/* Fixed write access, dst address must be 8byte alignment */  
			if( ( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination & 0x7 ) != 0 )
			{
				DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
				DMA_debug_info.dma_no = dma_no;
				DMA_debug_info.access_addr = (kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination;
				#if defined(__DMA_DEBUG_TRACE__) 
				kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, DST=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
				#endif
				kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_UNALIGNMENT, (kal_uint32)RETURN_ADDRESS());
			}
			dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
			dma_con |= DMA_CON_DFIX;
		}
		
		if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO && ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT )
		{
			dma_con |= DMA_CON_WPEN|DMA_CON_WPSD; //wrap in destination

			wpto = (kal_uint32 *)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
			wppt = (kal_uint32 *)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
			DRV_WriteReg32(DMA_WPTO(dma_no), *wpto);
			DRV_WriteReg32(DMA_WPPT(dma_no), *wppt);

			DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source);
			DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination);
		}		

		if (dma_menu->fixed_pattern)
		{
			dma_con |= DMA_CON_FIXED_PATTERN;
		}
		
#endif //__DMA_V3__
		break;

	case DMA_FULLSIZE_RXRINGBUFF:

#if defined(__DMA_V3__)
		if( fullsize != KAL_TRUE || dma_no > DMA_FULL_CH_NUM )
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.fullsize = fullsize;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, fullsize=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.fullsize);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_NO, (kal_uint32)RETURN_ADDRESS());
		}
		
		/*E1 Bug: Len2 can not be zero */
		if(*(kal_uint32*)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT) == 0 )
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			DMA_debug_info.count = *(kal_uint32*)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, COUNT=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.count);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_ZERO_COUNT, (kal_uint32)RETURN_ADDRESS());
		}
		
		//priority fixed pattern > destination wrap > write fixed address
		if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_raddr)
		{
			/* Fixed write access, src address must be 8byte alignment */  
			if( ( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source & 0x7 ) != 0 )
			{
				DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
				DMA_debug_info.dma_no = dma_no;
				DMA_debug_info.access_addr = (kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source;
				#if defined(__DMA_DEBUG_TRACE__) 
				kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, SRC=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
				#endif
				kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_UNALIGNMENT, (kal_uint32)RETURN_ADDRESS());
			}	
			dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->rsize)&DMA_CON_SIZE_MASK)<<DMA_CON_RSIZE_OFFSET;
			dma_con |= DMA_CON_SFIX;
		}

		if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->fixed_waddr)
		{
			/* Fixed write access, dst address must be 8byte alignment */    
			if( ( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination & 0x7 ) != 0 )
			{
				DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
				DMA_debug_info.dma_no = dma_no;
				DMA_debug_info.access_addr = (kal_uint32)((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination;
				#if defined(__DMA_DEBUG_TRACE__) 
				kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, DST=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
				#endif
				kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_UNALIGNMENT, (kal_uint32)RETURN_ADDRESS());
			}
			dma_con |= ((((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->wsize)&DMA_CON_SIZE_MASK)<<DMA_CON_WSIZE_OFFSET;
			dma_con |= DMA_CON_DFIX;
		}
		
		if( ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO && ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT )
		{
			dma_con |= DMA_CON_WPEN & (~DMA_CON_WPSD); //wrap in source

			wpto = (kal_uint32 *)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPTO);
			wppt = (kal_uint32 *)(((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->WPPT);
			DRV_WriteReg32(DMA_WPTO(dma_no), *wpto);
			DRV_WriteReg32(DMA_WPPT(dma_no), *wppt);
		 
			DRV_WriteReg32(DMA_SRC(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->source);
			DRV_WriteReg32(DMA_DST(dma_no), ((DMA_FULLSIZE_HWRINGBUFF_MENU *)dma_menu->menu)->destination);
		}
		
		if (dma_menu->fixed_pattern)
		{
			dma_con |= DMA_CON_FIXED_PATTERN;
		}
		
#endif //__DMA_V3__
		break;	 
	  
	default:
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		DMA_debug_info.type = dma_menu->type;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, TYPE=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.type);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_TYPE, (kal_uint32)RETURN_ADDRESS());
		break;
	}

#if defined(__DMA_V3__)
	//configure burst mode
	if (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE && ( dma_con & ( DMA_CON_SFIX | DMA_CON_DFIX ) ) == 0 )  
	{
		if(((DMA_TMODE *)(dma_menu->menu))->cycle==0)
		{
			dma_con |= (DMA_CON_BURST_SINGLE<<DMA_CON_BURST_OFFSET);
		}
		else
		{	
			//cycle could be from 1 to 8
			dma_con |= ((((DMA_TMODE *)(dma_menu->menu))->cycle-1)&0x07)<<DMA_CON_BURST_OFFSET;
		}
	}
	else/* Fixed access, burst size must be single */
	{
		dma_con |= (DMA_CON_BURST_SINGLE<<DMA_CON_BURST_OFFSET);
	}

	//register the callback function when using interrupt DMA mode
	if (dma_menu->callback != NULL)
	{
		DRV_WriteReg32(DMA_INT_EN(dma_no), 1);
		DMA_LISR_FUNC[dma_no] = dma_menu->callback;
	}
	else
	{
		DRV_WriteReg32(DMA_INT_EN(dma_no), 0);
	}

	//cache the setting for quicky configure APIs
	if(dma_menu->type!=DMA_FULLSIZE_TXRINGBUFF && dma_menu->type!=DMA_FULLSIZE_RXRINGBUFF)
	{
		DMA_Save_Param[dma_no].len1 = ((kal_uint32)dma_menu->count)<<(dma_menu->size);
		DMA_Save_Param[dma_no].len2 = 0;
		DMA_Save_Param[dma_no].size = dma_menu->size;
	}
	else
	{  
		DMA_Save_Param[dma_no].len1 = (kal_uint32)*wppt<<(dma_menu->size);
		DMA_Save_Param[dma_no].len2 = ((kal_uint32)dma_menu->count-(kal_uint32)(*wppt))<<(dma_menu->size);
		DMA_Save_Param[dma_no].size = dma_menu->size;
	}
   
#if defined(__DMA_SIM_TX_RX_SUPPORT__)
	//AB: temp solution for sim modification
	if(DMA_SIM != dma_no && DMA_SIM2 != dma_no)
	{
       DRV_WriteReg32(DMA_COUNT(dma_no),DMA_Save_Param[dma_no].len1);
       DRV_WriteReg32(DMA_WPPT(dma_no),DMA_Save_Param[dma_no].len2);   
	}else{
		if(DMA_HWTX == dma_menu->type)
		{
			DRV_WriteReg32(DMA_COUNT(dma_no),DMA_Save_Param[dma_no].len1);
		}else{
			DRV_WriteReg32(((DMA_COUNT(dma_no)) + 4),DMA_Save_Param[dma_no].len1);
		}
	}
#else /* __DMA_SIM_TX_RX_SUPPORT__ */
	DRV_WriteReg32(DMA_COUNT(dma_no),DMA_Save_Param[dma_no].len1);
	DRV_WriteReg32(DMA_WPPT(dma_no),DMA_Save_Param[dma_no].len2);
#endif  /* __DMA_SIM_TX_RX_SUPPORT__ */

	if( limit != 0 )
	{
		dma_con |= (( limit << DMA_CON_SLOW_OFFSET )& DMA_CON_SLOW_MASK);
		dma_con |= DMA_CON_SLOW_EN;
	}

	DRV_WriteReg32(DMA_CON(dma_no),dma_con);   
#endif //__DMA_V3__

	APB_DUMMY_READ();
	
	/* configuration is done and start the DMA */
	if (start) 
	{
		DMA_Start(dma_no);
	}
}

/*************************************************************************************
* FUNCTION
*	DMA_Quick_Config_Bidir
*
* DESCRIPTION
*   Configure src & dst address & count of dedicated DMA channel
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel number, user configured DMA parameters
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA_Quick_Config_Bidir(  kal_uint32 dma_no, kal_uint32 dst, kal_uint32 src, kal_uint32 count, DMA_Type type )
{
#if defined(__DMA2_SUPPORT__)
	if( (dma_no & 0x80) == 0x80 )
	{
	//error check for incorrcet low power feature usage
	#if  defined(__DMA_LOW_POWER__)
		if(DMA2_PWR.sleepDisable==0)
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, DMA2_PWR=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no,DMA2_PWR.sleepDisable);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
		}	
	#endif	
		DMA2_Quick_Config_Bidir((dma_no&0x7F), dst, src,count,type);
		return;
	}
#endif //__DMA2_SUPPORT__

	//error check for incorrcet low power feature usage
	#if  defined(__DMA_LOW_POWER__)
	if(DMA_PWR.sleepDisable==0)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, DMA_PWR=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no,DMA_PWR.sleepDisable);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	#endif
	
	if (DMA_CheckRunStat(dma_no) || DMA_CheckITStat(dma_no)) 
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Quick_Config_Bidir: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}

	if(DMA_Owner[dma_no] == DMA_IDLE)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Quick_Config_Bidir: ret_addr=%x, DMA_CODE=%x, DMA_Owner=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA_Owner[dma_no]);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}

	/* DMA bug: DMA will never stop when start DMA with zero length */
	if( count == 0 )
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		DMA_debug_info.count = count;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Quick_Config_Bidir: ret_addr=%x, DMA_CODE=%x, COUNT=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA_debug_info.count);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_ZERO_COUNT, (kal_uint32)RETURN_ADDRESS());
	}
	DMA_Stop(dma_no);
	DRV_WriteReg32(DMA_DST(dma_no), dst);
	DRV_WriteReg32(DMA_SRC(dma_no), src);   
#if defined(__DMA_V3__)
	DMA_Save_Param[dma_no].len1 = count<<DMA_Save_Param[dma_no].size;
	DRV_WriteReg32(DMA_COUNT(dma_no),DMA_Save_Param[dma_no].len1);
#endif //__DMA_V3__
	APB_DUMMY_READ();
	DMA_Start(dma_no);
}

/*************************************************************************************
* FUNCTION
*	DMA_Quick_Config
*
* DESCRIPTION
*   Configure dst address of dedicated DMA channel
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel number, user configured DMA parameters
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA_Quick_Config(kal_uint32 dma_no, kal_uint32 dst)
{
#if defined(__DMA2_SUPPORT__)
	if( (dma_no & 0x80) == 0x80 )
	{
	//error check for incorrcet low power feature usage
	#if  defined(__DMA_LOW_POWER__)
		if(DMA2_PWR.sleepDisable==0)
		{
			DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
			DMA_debug_info.dma_no = dma_no;
			#if defined(__DMA_DEBUG_TRACE__) 
			kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, DMA2_PWR=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no,DMA2_PWR.sleepDisable);	
			#endif
			kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
		}	
	#endif	
		DMA2_Quick_Config((dma_no&0x7F),dst);
		return;
	}
#endif //__DMA2_SUPPORT__

	//error check for incorrcet low power feature usage
	#if  defined(__DMA_LOW_POWER__)
	if(DMA_PWR.sleepDisable==0)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Config_Internal: ret_addr=%x, DMA_CODE=%x, DMA_PWR=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no,DMA_PWR.sleepDisable);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	#endif
	
	if (DMA_CheckRunStat(dma_no) || DMA_CheckITStat(dma_no)) 
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Quick_Config: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}

	if(DMA_Owner[dma_no] == DMA_IDLE)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Quick_Config: ret_addr=%x, DMA_CODE=%x, DMA_Owner=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA_Owner[dma_no]);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	DMA_Stop(dma_no);
#if defined(__DMA_V3__)
	DRV_WriteReg32(DMA_COUNT(dma_no),DMA_Save_Param[dma_no].len1);   
#endif //__DMA_V3__
	DRV_WriteReg32(DMA_DST(dma_no), dst);
	APB_DUMMY_READ();
	DMA_Start(dma_no);
}

/*************************************************************************************
* FUNCTION
*	DMA_SRC_Config
*
* DESCRIPTION
*   Configure src address of dedicated DMA channel
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel number, user configured DMA parameters
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA_SRC_Config(kal_uint32 dma_no, kal_uint32 src)
{
#if defined(__DMA2_SUPPORT__)
	if( (dma_no & 0x80) == 0x80 )
	{
		DMA2_SRC_Config((dma_no&0x7F),src);
		return;
	}
#endif //__DMA2_SUPPORT__

	if (DMA_CheckRunStat(dma_no) || DMA_CheckITStat(dma_no)) 
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_SRC_Config: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}

	if(DMA_Owner[dma_no] == DMA_IDLE)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_SRC_Config: ret_addr=%x, DMA_CODE=%x, DMA_Owner=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA_Owner[dma_no]);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	
	if (INT_QueryIsCachedRAM(src, 1)) 
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		DMA_debug_info.access_addr = src;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_SRC_Config: ret_addr=%x, DMA_CODE=%x, access_addr=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_CACHE_ACCESS, (kal_uint32)RETURN_ADDRESS());
	}
	DMA_Stop(dma_no);
	DRV_WriteReg32(DMA_SRC(dma_no), src);
}

/*************************************************************************************
* FUNCTION
*	DMA_DST_Config
*
* DESCRIPTION
*   Configure dst address of dedicated DMA channel
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel number, user configured DMA parameters
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA_DST_Config(kal_uint32 dma_no, kal_uint32 dst)
{
#if defined(__DMA2_SUPPORT__)
	if( (dma_no & 0x80) == 0x80 )
	{
		DMA2_DST_Config((dma_no&0x7F),dst);
		return;
	}
#endif //__DMA2_SUPPORT__
	if (DMA_CheckRunStat(dma_no) || DMA_CheckITStat(dma_no)) 
	{
		//ASSERT(0);
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_DST_Config: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}

	if(DMA_Owner[dma_no] == DMA_IDLE)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_DST_Config: ret_addr=%x, DMA_CODE=%x, DMA_Owner=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA_Owner[dma_no]);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	
	if (INT_QueryIsCachedRAM(dst, 1)) 
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		DMA_debug_info.access_addr = dst;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_DST_Config: ret_addr=%x, DMA_CODE=%x, access_addr=%x\r\n",DMA_debug_info.ret_addr, DMA_debug_info.dma_no, DMA_debug_info.access_addr);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_CACHE_ACCESS, (kal_uint32)RETURN_ADDRESS());
	}
	DMA_Stop(dma_no);
	DRV_WriteReg32(DMA_DST(dma_no), dst);
}

/*************************************************************************************
* FUNCTION
*	DMA_Transfer_Size_config
*
* DESCRIPTION
*   configure transfer size of dedicated DMA channel
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel number, user configured DMA parameters
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA_Transfer_Size_Config( kal_uint8 dma_no, DMA_INPUT *dma_menu )
{
	kal_uint32 dma_con = 0;
#if defined(__DMA2_SUPPORT__)
	if( (dma_no & 0x80) == 0x80 )
	{
		DMA2_Transfer_Size_Config((dma_no&0x7F), dma_menu);
		return;
	}
#endif //__DMA2_SUPPORT__

	//error check the invalid situation
	if (DMA_CheckRunStat(dma_no) || DMA_CheckITStat(dma_no) || dma_no >DMA_MAX_FULL_CHANNEL)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Transfer_Size_config: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}

	if(DMA_Owner[dma_no] == DMA_IDLE)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Transfer_Size_config: ret_addr=%x, DMA_CODE=%x, DMA_Owner=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA_Owner[dma_no]);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	
	if((dma_menu->count) << (dma_menu->size) > 0xfffff)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.count = dma_menu->count << dma_menu->size;
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Transfer_Size_config: ret_addr=%x, COUNT=%x, DMA_NO=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.count, DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_GDMA_COUNT, (kal_uint32)RETURN_ADDRESS());
	}
	
	/* DMA bug: DMA will never stop when start DMA with zero length */

	if(dma_menu->count == 0)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.count = dma_menu->count;
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Transfer_Size_config: ret_addr=%x, COUNT=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.count, DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_ZERO_COUNT, (kal_uint32)RETURN_ADDRESS());
	}

	DMA_Stop(dma_no);
		
#if defined(__DMA_V3__)
	//configure burst mode
	if (((DMA_TMODE *)(dma_menu->menu))->burst_mode==KAL_TRUE )  
	{
		if(((DMA_TMODE *)(dma_menu->menu))->cycle==0)
		{
			dma_con |= (DMA_CON_BURST_SINGLE<<DMA_CON_BURST_OFFSET);
		}
		else
		{	
			//cycle could be from 1 to 8
			dma_con |= ((((DMA_TMODE *)(dma_menu->menu))->cycle-1)&0x07)<<DMA_CON_BURST_OFFSET;
		}
	}
	else/* Fixed access, burst size must be single */
	{
		dma_con |= (DMA_CON_BURST_SINGLE<<DMA_CON_BURST_OFFSET);
	}
#endif
	DRV_WriteReg32(DMA_CON(dma_no),dma_con);   	
}

/*************************************************************************************
* FUNCTION
*	DMA_Mode_config
*
* DESCRIPTION
*   configure interrupt/polling mode of dedicated DMA channel
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel number, user configured DMA parameters
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA_Mode_Config(kal_uint8 dma_no, DMA_INPUT *dma_menu)
{
#if defined(__DMA2_SUPPORT__)
	if( (dma_no & 0x80) == 0x80 )
	{
		DMA2_Mode_Config((dma_no&0x7F), dma_menu);
		return;
	}
#endif //__DMA2_SUPPORT__

	if (DMA_CheckRunStat(dma_no) || DMA_CheckITStat(dma_no)) 
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Mode_config: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	
	if(DMA_Owner[dma_no] == DMA_IDLE)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Mode_config: ret_addr=%x, DMA_CODE=%x, DMA_Owner=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA_Owner[dma_no]);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	
	//register the callback function when using interrupt DMA mode
	if (dma_menu->callback != NULL)
	{
		DRV_WriteReg32(DMA_INT_EN(dma_no), 1);
		DMA_LISR_FUNC[dma_no] = dma_menu->callback;
	}
	else
	{
		DRV_WriteReg32(DMA_INT_EN(dma_no), 0);
	}
}

/*************************************************************************************
* FUNCTION
*	DMA_START_config
*
* DESCRIPTION
*   Start dedicated DMA channel
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel number, user configured DMA parameters
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA_Start_Config( kal_uint8 dma_no )
{
#if defined(__DMA2_SUPPORT__)
	if( (dma_no & 0x80) == 0x80 )
	{
		DMA2_Start_Config((dma_no&0x7F));
		return;
	}
#endif //__DMA2_SUPPORT__

	if (DMA_CheckRunStat(dma_no) || DMA_CheckITStat(dma_no)) 
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_START_config: ret_addr=%x, DMA_CODE=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	
	if(DMA_Owner[dma_no] == DMA_IDLE)
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = dma_no;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_START_config: ret_addr=%x, DMA_CODE=%x, DMA_Owner=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA_Owner[dma_no]);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_STATUS, (kal_uint32)RETURN_ADDRESS());
	}
	
	DMA_Start(dma_no);
}

/*************************************************************************************
* FUNCTION
*	DMA_ERROR_LISR
*
* DESCRIPTION
*   Default LISR callback
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
*************************************************************************************/
void DMA_ERROR_LISR(void)
{
	while(1);//ext_assert
}

#if defined (__DMA_SUPPORT_CALLBACK_LISR__)
/*************************************************************************************
* FUNCTION
*	DMA_Register_RT_CallBack
*
* DESCRIPTION
*   register the dedicated DMA channel using the feature "__DMA_SUPPORT_CALLBACK_LISR__"
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel id
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA_Register_RT_CallBack ( kal_uint8 dma_no ) 
{
#if defined(__DMA2_SUPPORT__)
	if( (dma_no & 0x80) == 0x80 )
	{
		DMA2_Register_RT_CallBack((dma_no&0x7F));
		return;
	}
#endif //__DMA2_SUPPORT__

#if defined(DMA_IRQ_CODE)
    IRQMask(DMA_IRQ_CODE);
#endif
    DMA_lisr_callback_ch_bit |= (1<<dma_no);
#if defined(DMA_IRQ_CODE)
    IRQUnmask(DMA_IRQ_CODE);
#endif
}

/*************************************************************************************
* FUNCTION
*	DMA_Unregister_RT_CallBack
*
* DESCRIPTION
*   un-register the dedicated DMA channel using the feature "__DMA_SUPPORT_CALLBACK_LISR__"
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel id
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA_Unregister_RT_CallBack ( kal_uint8 dma_no ) 
{
#if defined(__DMA2_SUPPORT__)
	if( (dma_no & 0x80) == 0x80 )
	{
		DMA2_Unregister_RT_CallBack((dma_no&0x7F));
		return;
	}
#endif //__DMA2_SUPPORT__

#if defined(DMA_IRQ_CODE)
    IRQMask(DMA_IRQ_CODE);
#endif
    DMA_lisr_callback_ch_bit &= ~(1<<dma_no);
#if defined(DMA_IRQ_CODE)
    IRQUnmask(DMA_IRQ_CODE);
#endif
}
#endif //__DMA_SUPPORT_CALLBACK_LISR__

/*************************************************************************************
* FUNCTION
*	DMA_HISR
*
* DESCRIPTION
*   HISR for processing AP side GDMA/PDMA when using interrupt mode
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
*************************************************************************************/
void DMA_HISR(void)
{
	kal_uint8 index;
#if defined (__DMA_SUPPORT_CALLBACK_LISR__)
	kal_uint32 pend_info_idx;
	kal_uint32 savedMask;
#endif //#if defined (__DMA_SUPPORT_CALLBACK_LISR__)
   
#if defined (__DMA_SUPPORT_CALLBACK_LISR__)
	/*get the pending channel info and update the free_index*/
	savedMask = SaveAndSetIRQMask();
	pend_info_idx = g_DMA_pending_info.free_index;
	g_DMA_pending_info.hisr_activated = KAL_FALSE;
	g_DMA_pending_info.free_index = (g_DMA_pending_info.free_index + 1) % (sizeof(g_DMA_pending_info.pending_int_bit)/sizeof(g_DMA_pending_info.pending_int_bit[0]));
	/*reset the free one */
	g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index] = 0;
    #if defined(__DMA_V3__)   
	g_DMA_pending_info.pending_int1_bit[g_DMA_pending_info.free_index] = 0;
    #endif
	RestoreIRQMask(savedMask);
#endif

	for(index = 0; index < DMA_MAX_CHANNEL; index++)
	{
		kal_uint32 index_hw;
		index_hw = PHY_DMA_MASTER[index];
#if defined (__DMA_SUPPORT_CALLBACK_LISR__)
        if ( g_DMA_pending_info.pending_int_bit[pend_info_idx] & (1 << (index_hw)) )
        {
            DMA_LISR_FUNC[index_hw]();
        }		
#else //__DMA_SUPPORT_CALLBACK_LISR__
	
    #if defined(__DMA_V3__)
		if( DRV_Reg32(DMA_GLBST_INT) &  1<<(index_hw-1) ) 
		{
			DMA_Stop(index_hw);
			DMA_ACKI(index_hw);
			DMA_LISR_FUNC[index_hw]();
		}
	#endif //__DMA_V3__
#endif //__DMA_SUPPORT_CALLBACK_LISR__
	}

#if !defined(__FUE__) &&( defined(__DMA_UART_VIRTUAL_FIFO__) || defined(__DMA_BT_VIRTUAL_FIFO__) )
	// handle virtual fifo interrupt
	for(index=DMA_VFIFO_CH_S; index<=DMA_VFIFO_CH_E; index++)
	{
        kal_uint32 VFF_ACK =0;
        kal_uint32 index_hw;
    	index_hw = PHY_DMA_VFF[index]; 
        /*VFF Over threshold handler*/
        if ( 
		#if defined (__DMA_SUPPORT_CALLBACK_LISR__)
        g_DMA_pending_info.pending_int_bit[pend_info_idx] & (1<<index_hw) 
		#else   
        DRV_Reg32(DMA_INTSTA(index_hw) ) & DMA_INTSTA_BIT
		#endif
        )
        {
			dma_Vfifo_static_RecHandler_CallBack(
            #if defined(__DMA_V3__)   
               index_hw
            #endif //__DMA_V3__
               );			 
		    VFF_ACK = 1;
        }
    #if defined(__DMA_V3__)   
		/* VFF flush handler */
        if ( 
		#if defined (__DMA_SUPPORT_CALLBACK_LISR__)
            g_DMA_pending_info.pending_int1_bit[pend_info_idx] & (1<<index_hw) 
		#else  
			DRV_Reg32(DMA_INTSTA(index_hw) )& DMA_INTSTA_BIT1
		#endif
		)
        {
            dma_Vfifo_static_RecTimeOutHandler_CallBack(index_hw);
		    VFF_ACK = 1;
        }
    #endif //__DMA_V3__		 

    #if !defined(__DMA_SUPPORT_CALLBACK_LISR__)	  
        if( VFF_ACK == 1 )
        {
           DMA_ACKI(index_hw); 
        }	
    #endif //!__DMA_SUPPORT_CALLBACK_LISR__	

	}
#endif //!__FUE__ && ( __DMA_UART_VIRTUAL_FIFO__ || __DMA_BT_VIRTUAL_FIFO__)

#if !defined(__DMA_SUPPORT_CALLBACK_LISR__)	  
	#if defined(DMA_IRQ_CODE)
	IRQClearInt(DMA_IRQ_CODE);
	IRQUnmask(DMA_IRQ_CODE);
	#endif	
#endif //!__DMA_SUPPORT_CALLBACK_LISR__		
	
}

/*************************************************************************************
* FUNCTION
*	DMA_LISR
*
* DESCRIPTION
*   LISR for processing AP side GDMA/PDMA when using interrupt mode
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
*************************************************************************************/
void DMA_LISR(void)
{
#if defined(__DMA_SUPPORT_CALLBACK_LISR__)	  
	kal_uint32 index, intsta;
#endif //__DMA_SUPPORT_CALLBACK_LISR__	  

#if defined(DMA_IRQ_CODE)
	IRQMask(DMA_IRQ_CODE);
#endif

#if defined(__DMA_SUPPORT_CALLBACK_LISR__)	  
   /*get the finished DMA channel info and close channel-- start*/
	for ( index = 0; index < DMA_MAX_CHANNEL; index++ )
	{
		kal_uint32 index_hw;
		index_hw = PHY_DMA_MASTER[index];
	
    #if defined(__DMA_V3__)   
		/*because interrupt flag will be 1 after DMA finishs its job even the interrupt is disabled, we need to check inten too*/
		intsta = (DRV_Reg32(DMA_INT_EN(index_hw))&1) != 0 ?  DRV_Reg32(DMA_INTSTA(index_hw)) : 0 ;
    #endif
		if ( intsta & DMA_INTSTA_BIT)
		{
			/*certain channel should not income twice before it is handled in call-back*/
			EXT_ASSERT((g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index] & (1<<(index_hw))) == 0, 
                      g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index] , (index_hw), g_DMA_pending_info.free_index);
			DMA_ACKI(index_hw);
			if( DMA_lisr_callback_ch_bit & (1<<(index_hw)) )
			{
				DMA_LISR_FUNC[index_hw]();
			}
			else
			{
				g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index] |= (1<<(index_hw));
			}
		}
	}

	#if !defined(__FUE__)   
	for(index=DMA_VFIFO_CH_S; index<=DMA_VFIFO_CH_E; index++)
	{
        kal_uint32 index_hw;	
    	index_hw = PHY_DMA_VFF[index]; 
   
		#if defined(__DMA_V3__)   
		/*because interrupt flag will be 1 after DMA finishs its job even the interrupt is disabled, we need to check inten too*/
		intsta = (DRV_Reg32(DMA_INT_EN(index_hw))&3) != 0 ?  DRV_Reg32(DMA_INTSTA(index_hw)) : 0 ;
		#endif
		if ( intsta & DMA_INTSTA_BIT)
		{
			/*certain channel should not income twice before it is handled in call-back*/
			EXT_ASSERT((g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index] & (1<<index_hw)) == 0, 
                      g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index] , index_hw, g_DMA_pending_info.free_index);
			/*because VFIFO interrput never stop before buffered data is handled even ack it. So we have to disable it.*/
			DMA_DisableINT(index_hw);			   
			DMA_ACKI(index_hw);
			if(  DMA_lisr_callback_ch_bit & (1<<index_hw) )
			{
				dma_Vfifo_static_RecHandler_CallBack(
			#if defined(__DMA_V3__)   
                   index_hw
            #endif
                );               
			}
			else
			{           
				g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index] |= (1<<index_hw);
			}
		}
		#if defined(__DMA_V3__)   
		if( intsta & DMA_INTSTA_BIT1 )
		{
			/*certain channel should not income twice before it is handled in call-back*/
			EXT_ASSERT((g_DMA_pending_info.pending_int1_bit[g_DMA_pending_info.free_index] & (1<<index_hw)) == 0, 
                      g_DMA_pending_info.pending_int1_bit[g_DMA_pending_info.free_index] , index_hw, g_DMA_pending_info.free_index);
			/*because VFIFO interrput never stop before buffered data is handled even ack it. So we have to disable it.*/
			DMA_DisableINT(index_hw);			   
			DMA_ACKI(index_hw);
			if(  DMA_lisr_callback_ch_bit & (1<<index_hw) )
			{
				dma_Vfifo_static_RecTimeOutHandler_CallBack(index_hw);
			}
			else
			{           
				g_DMA_pending_info.pending_int1_bit[g_DMA_pending_info.free_index] |= (1<<index_hw);
			}
		}
		#endif
	}
	#endif //!__FUE__

	if( 
		g_DMA_pending_info.hisr_activated == KAL_FALSE && (
		g_DMA_pending_info.pending_int_bit[g_DMA_pending_info.free_index]
	#if defined(__DMA_V3__)  
		|| g_DMA_pending_info.pending_int1_bit[g_DMA_pending_info.free_index] 
	#endif
		)
    )
	{	
	#if !defined(__FUE__)   
		drv_active_hisr(DRV_DMA_HISR_ID);
		g_DMA_pending_info.hisr_activated = KAL_TRUE;
	#else
		DMA_HISR();
	#endif	   
	}
	#if defined(DMA_IRQ_CODE) 
	IRQClearInt(DMA_IRQ_CODE);
	IRQUnmask(DMA_IRQ_CODE);
	#endif
#else   //__DMA_SUPPORT_CALLBACK_LISR__

#if !defined(__FUE__)
	#if defined(__SSDVT_TEST__) 
	//PC: due to DMA processing flow will ack DMA before execute callback ==> DMA interrupt flag will be cleared
	//however, the DMA status information is needed for DMA_LISR_SSDVT ==> DMA_LISR_SSDVT will read DMA interrupt flag register
	//hence, we create special flow for DVT test
    DMA_LISR_SSDVT();
    IRQClearInt(DMA_IRQ_CODE);
    IRQUnmask(DMA_IRQ_CODE);
	#else
    drv_active_hisr(DRV_DMA_HISR_ID);
	#endif
#else 
	DMA_HISR();
#endif

#endif //__DMA_SUPPORT_CALLBACK_LISR__
}


/*************************************************************************************
* FUNCTION
*	DMA_VFF_Tx_Flush_Config
*
* DESCRIPTION
*   Config VFF Tx flush
*
* CALLS
*
* PARAMETERS
*	dedicated DMA channel number, user configured DMA parameters
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA_VFF_Tx_Flush_Config(kal_uint32 dma_no, kal_bool hwflush_en)
{
#ifdef DMA_SUPPORT_TX_FLUSH_HW_GUARANTEE
	if(dma_no < DMA_VFIFO_PHY_CH_S)
		return;
	
	if(hwflush_en)
		DRV_WriteReg32(DMA_VFF_FLUSH_CTRL(dma_no),1);//flush process is guaranteed by HW
	else
		DRV_WriteReg32(DMA_VFF_FLUSH_CTRL(dma_no),0);//Default value, flush process is guaranteed by SW
#endif
}

/*************************************************************************************
* FUNCTION
*	DMA_Ini
*
* DESCRIPTION
*   initialize AP DMA 
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
*************************************************************************************/
void DMA_Ini(void)
{
	kal_uint8 index;

	for (index = 1; index <= DMA_ALL_CHANNEL; index++)
	{
		DMA_Owner[index] = DMA_IDLE;
		DMA_LISR_FUNC[index] = DMA_ERROR_LISR;
	}
	DMA_POWER_ON();

#if defined(DMA_IRQ_CODE)
	IRQ_Register_LISR(DMA_IRQ_CODE, DMA_LISR, "DMA handler");
	DRV_Register_HISR(DRV_DMA_HISR_ID, DMA_HISR);
	IRQSensitivity(DMA_IRQ_CODE,LEVEL_SENSITIVE);
	IRQUnmask(DMA_IRQ_CODE);
#endif
   
#if defined(__DMA2_SUPPORT__)
	DMA2_Ini();
#endif   
}

/*************************************************************************************
* FUNCTION
*	 DMA_memcpy
*
* DESCRIPTION
*   do SW memory copy by GDMA for BTMT 
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
*************************************************************************************/
kal_bool DMA_memcpy(const void *src, const void *dst, kal_uint32 length)
{

#if ( DMA_MAX_FULL_CHANNEL > 0 )
	kal_uint8 handle=0xff;
	DMA_INPUT input = {0};
	#if defined(__DMA_API_V2__)
	DMA_SWCOPYMENU menu = {{0}, 0};
	#else
	DMA_SWCOPYMENU menu = {0};
	#endif

	#if !defined(__MTK_L1CACHEABLE__)
	if (INT_QueryIsCachedRAM(src, length) || INT_QueryIsCachedRAM(dst, length)) 
	{
		EXT_ASSERT(0, (kal_uint32)src, (kal_uint32)dst, length);
	}
	#endif /* !__MTK_L1CACHEABLE__ */

	handle = DMA_FullSize_GetChannel(DMA_SW);
	ASSERT(handle!=0xff);
	

	if (handle != 0xff)
	{
		menu.srcaddr = (kal_uint32)src;
		menu.dstaddr = (kal_uint32)dst;
		input.type = DMA_SWCOPY;
		input.menu = &menu;
		input.callback = NULL;

	#if defined(__DMA_V3__)
		if(length > DMA_COUNT_MAX)
			return KAL_FALSE;

		input.size = DMA_BYTE;
		input.count = length;
		menu.TMOD.burst_mode = KAL_TRUE;
		menu.TMOD.cycle = 8;
	#endif //__DMA_V3__
		DMA_FullSize_Config(handle,&input,KAL_TRUE);
		DMA_WaitforDone(handle);
		DMA_FullSize_FreeChannel(handle);
	#if defined(__WRITE_THROUGH_CACHEABLE__) && ! defined(__FUE__)
		invalidate_wt_cache((kal_uint32)dst, length);
	#endif /*__WRITE_THROUGH_CACHEABLE__ */
		return KAL_TRUE;
	}
	else
	{
		return KAL_FALSE;
	}
#else //DMA_MAX_FULL_CHANNEL > 0
	return KAL_FALSE;
#endif //DMA_MAX_FULL_CHANNEL > 0   
}

/*************************************************************************************
* FUNCTION
*	DMA_Valid_Addr_Chk
*
* DESCRIPTION
*   legacy API 
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
*************************************************************************************/
kal_bool DMA_Valid_Addr_Chk(const void *src, kal_uint32 length)
{
	return KAL_TRUE;
}

#if !defined(__FUE__)

static kal_uint8 dma_slowdown_handle;

/*************************************************************************************
* FUNCTION
*	dma_slowdown_get_handle
*
* DESCRIPTION
*   get slow down handler 
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	already allocated slow down handler number
*
* GLOBALS AFFECTED
*************************************************************************************/
kal_uint8 dma_slowdown_get_handle(void)
{
    ASSERT(dma_slowdown_handle<32);
    return dma_slowdown_handle++;
}

/*************************************************************************************
* FUNCTION
*	dma_slowdown
*
* DESCRIPTION
*   legacy API 
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
*************************************************************************************/
void dma_slowdown(kal_uint8 handle)
{
#if defined(__DMA_V3__)

    /* EMI bandwidth limiter is applied, To slow down DMA is not required. */
	
#endif //__DMA_V3__   
}

/*************************************************************************************
* FUNCTION
*	dma_recover
*
* DESCRIPTION
*   legacy API 
*
* CALLS
*
* PARAMETERS
*	slow down handler id
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void dma_recover(kal_uint8 handle)
{

#if defined(__DMA_V3__)

    /* EMI bandwidth limiter is applied, To slow down DMA is not required. */

#endif //__DMA_V3__   
}

/*************************************************************************************
* FUNCTION
*	dma_recover_all
*
* DESCRIPTION
*   legacy API 
*
* CALLS
*
* PARAMETERS
*	slow down handler id
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
void dma_recover_all()
{
#if defined( __DMA_V3__)
   
   /* EMI bandwidth limiter is applied, To slow down DMA is not required. */
   
#endif //__DMA_V3__

}

/*************************************************************************************
* FUNCTION
*	dma_Vfifo_static_RecHandler_CallBack
*
* DESCRIPTION
*   To call Vfifo static RecHandler CallBack 
*
* CALLS
*
* PARAMETERS
*	master id
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
static void dma_Vfifo_static_RecHandler_CallBack(kal_uint32 master)
{
#if !defined(__FUE__)
    switch( (master) )
    {
	#if defined(__DMA_UART_VIRTUAL_FIFO__)			    
		case DMA_CON_MASTER_UART1RX:
			UART_RecHandler_VFIFO(uart_port1);
			break;
		case DMA_CON_MASTER_UART1TX:
			UART_TrxHandler_VFIFO(uart_port1);
			break;
		#if defined(DMA_CON_MASTER_UART2RX)
		case DMA_CON_MASTER_UART2RX:
			UART_RecHandler_VFIFO(uart_port2);
			break;
		#endif /*DMA_CON_MASTER_UART2RX */
		#if defined(DMA_CON_MASTER_UART2TX)
		case DMA_CON_MASTER_UART2TX:
			UART_TrxHandler_VFIFO(uart_port2);
			break;
		#endif /*DMA_CON_MASTER_UART2TX */
		#if defined(DMA_CON_MASTER_UART3RX)
		case DMA_CON_MASTER_UART3RX:
			UART_RecHandler_VFIFO(uart_port3);
			break;
		#endif /*DMA_CON_MASTER_UART3RX */
		#if defined(DMA_CON_MASTER_UART3TX)
		case DMA_CON_MASTER_UART3TX:
			UART_TrxHandler_VFIFO(uart_port3);
			break;
		#endif /*DMA_CON_MASTER_UART3TX */		
		#if defined(DMA_CON_MASTER_UART4RX)
		case DMA_CON_MASTER_UART4RX:
			UART_RecHandler_VFIFO(DMA_REMP_UART_PORT4);
			break;			
		#endif /* DMA_CON_MASTER_UART4RX */
		#if defined(DMA_CON_MASTER_UART4TX)
		case DMA_CON_MASTER_UART4TX:
			UART_TrxHandler_VFIFO(DMA_REMP_UART_PORT4);
			break;
		#endif /* DMA_CON_MASTER_UART4TX */

	#endif //__DMA_UART_VIRTUAL_FIFO__					
	#if defined(__DMA_BT_VIRTUAL_FIFO__)
		case DMA_CON_MASTER_BTIFTX:
			BTIF_DMA_TX_Threshold_Handler_VFIFO(); //Flush and threadhold handler
			break;
		case DMA_CON_MASTER_BTIFRX:
			BTIF_DMA_RX_Threshold_Handler_VFIFO();
			break;
	#endif //__DMA_BT_VIRTUAL_FIFO__					
    }
#endif //!__FUE__
}

/*************************************************************************************
* FUNCTION
*	dma_Vfifo_static_RecTimeOutHandler_CallBack
*
* DESCRIPTION
*   To call Vfifo static RecTimeOutHandler CallBack 
*
* CALLS
*
* PARAMETERS
*	master id
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*************************************************************************************/
static void dma_Vfifo_static_RecTimeOutHandler_CallBack(kal_uint32 master)
{
#if defined (__DMA_V3__) && !defined(__FUE__) 
    switch( (master) )
    {
	#if defined(__DMA_UART_VIRTUAL_FIFO__)			    			    
		case DMA_CON_MASTER_UART1RX:
			UART_RecTimeOutHandler(uart_port1);
			break;
		#if defined(DMA_CON_MASTER_UART2RX)
		case DMA_CON_MASTER_UART2RX:
			UART_RecTimeOutHandler(uart_port2);
			break;
		#endif
		#if defined(DMA_CON_MASTER_UART3RX)
		case DMA_CON_MASTER_UART3RX:
			UART_RecTimeOutHandler(uart_port3);
			break;
		#endif
	#endif	//__DMA_UART_VIRTUAL_FIFO__		
	#if defined(__DMA_BT_VIRTUAL_FIFO__)
		case DMA_CON_MASTER_BTIFTX:
			BTIF_DMA_TX_Threshold_Handler_VFIFO(); //Flush and threadhold handler
			break;
		case DMA_CON_MASTER_BTIFRX:
			BTIF_DMA_RX_Threshold_Handler_VFIFO();
			break;					
	#endif	//__DMA_UART_VIRTUAL_FIFO__												
    }
#endif //__DMA_V3__ && !__FUE__
}

#endif // !__FUE__ 

#if defined(__DMA_UART_VIRTUAL_FIFO__) && !defined(__FUE__)
/*************************************************************************************
* FUNCTION
*	DMA_Vfifo_init
*
* DESCRIPTION
*   enable interrupt mode for all DMA virtual FIFO 
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
*************************************************************************************/
void DMA_Vfifo_init(void)
{
	#if defined(__DMA_V3__)
    kal_uint32 index;
    for( index = 0; index < MAX_UART_PORT_NUM; index++)
    {
        if( UART_VFIFO_support[index] )
        {
		    DRV_WriteReg32(DMA_INT_EN(UARTPort[index].Tx_DMA_Ch), DMA_INTSTA_BIT);
            DRV_WriteReg32(DMA_INT_EN(UARTPort[index].Rx_DMA_Ch), DMA_INTSTA_BIT|DMA_INTSTA_BIT1);
        }	
    }
	#endif //__DMA_V3__
}

/*************************************************************************************
* FUNCTION
*	DMA_Vfifo_SetChan
*
* DESCRIPTION
*   enable interrupt mode for dedicated DMA virtual FIFO 
*
* CALLS
*
* PARAMETERS
*	Uart port id
*
* RETURNS
*	configure status (success/fail)
*
* GLOBALS AFFECTED
*************************************************************************************/
int DMA_Vfifo_SetChan(UART_PORT port)
{
	if(UART_VFIFO_support[port] != KAL_TRUE)
		return KAL_FALSE;

	if(port == uart_port1)
	{
#if defined(__DMA_V3__)
		DRV_WriteReg32(DMA_INT_EN(UARTPort[port].Rx_DMA_Ch), DMA_INTSTA_BIT|DMA_INTSTA_BIT1);
		DRV_WriteReg32(DMA_INT_EN(UARTPort[port].Tx_DMA_Ch), DMA_INTSTA_BIT);       
#endif //__DMA_V3__	   
	}
	else if(port == uart_port2)
	{
#if defined(__DMA_V3__)
	DRV_WriteReg32(DMA_INT_EN(UARTPort[port].Rx_DMA_Ch), DMA_INTSTA_BIT|DMA_INTSTA_BIT1);
	DRV_WriteReg32(DMA_INT_EN(UARTPort[port].Tx_DMA_Ch), DMA_INTSTA_BIT);       
#endif 	//__DMA_V3__	   
	}
#if defined(__UART3_SUPPORT__)
	else if(port == uart_port3)
	{
#if defined(__DMA_V3__)
		DRV_WriteReg32(DMA_INT_EN(UARTPort[port].Rx_DMA_Ch), DMA_INTSTA_BIT|DMA_INTSTA_BIT1);
		DRV_WriteReg32(DMA_INT_EN(UARTPort[port].Tx_DMA_Ch), DMA_INTSTA_BIT);       
#endif 	//__DMA_V3__	   
	}
#endif /* __UART3_SUPPORT__ */					   
	return KAL_TRUE;
}

/*************************************************************************************
* FUNCTION
*	DMA_Vfifo_SetAdrs
*
* DESCRIPTION
*   set address of dedicated DMA virtual FIFO 
*
* CALLS
*
* PARAMETERS
*	address, VFF buffer size, uart id, tx/rx direction
*
* RETURNS
*	configure status (success/fail)
*
* GLOBALS AFFECTED
*************************************************************************************/
void DMA_Vfifo_SetAdrs(kal_uint32 adrs, kal_uint32 len, DMA_VFIFO_UART ch, kal_bool IsTx )
{
#if defined(__DMA_V3__)
	if( ( adrs & 0x7 ) != 0 )
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = ch;
		DMA_debug_info.access_addr = adrs;
		DMA_debug_info.IsTx = IsTx;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Vfifo_SetAdrs: ret_addr=%x, DMA_CODE=%x, access_addr=%x, IsTx=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA_debug_info.access_addr, DMA_debug_info.IsTx);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_UNALIGNMENT, (kal_uint32)RETURN_ADDRESS());
	}
	
	if( ( len & 0xFFFF0007 ) != 0 )
	{
		DMA_debug_info.ret_addr = (kal_uint32)RETURN_ADDRESS();
		DMA_debug_info.dma_no = ch;
		DMA_debug_info.access_addr = len;
		DMA_debug_info.IsTx = IsTx;
		#if defined(__DMA_DEBUG_TRACE__) 
		kal_prompt_trace(MOD_DRV_HISR,"DMA_Vfifo_SetAdrs: ret_addr=%x, DMA_CODE=%x, access_len=%x, IsTx=%x\r\n",DMA_debug_info.ret_addr,DMA_debug_info.dma_no, DMA_debug_info.access_addr, DMA_debug_info.IsTx);	
		#endif
		kal_fatal_error_handler(KAL_ERROR_INVALID_DMA_UNALIGNMENT, (kal_uint32)RETURN_ADDRESS());
	}
#endif
	DRV_WriteReg32(DMA_PGMADDR(ch), adrs);
	DRV_WriteReg32(DMA_FFSIZE(ch), len);
#if defined(__DMA_V3__)	  
	DRV_Reg(DMA_VFF_THRE(ch)) = (IsTx)?DMA_TX_TRIGGER_LEVEL(len):DMA_RX_TRIGGER_LEVEL(len); // set trigger level for DMA interrupt     
	if( IsTx == KAL_FALSE )
	{
		DRV_WriteReg32(DMA_ALTLEN(ch), DMA_VIFOF_ALERT_LENGTH); //maximum of alert threshold will effect the flow control	  
	}
#endif//__DMA_V3__	  
}

/*************************************************************************************
* FUNCTION
*	DMA_Vfifo_Flush
*
* DESCRIPTION
*   Flushing DMA virtual FIFO
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
*************************************************************************************/
void DMA_Vfifo_Flush(DMA_VFIFO_UART ch)
{
#if defined(__DMA_V3__)	 
	kal_uint32 temp;
	/* E1 DMA bug: if stopping or flushing a disabled DMA channel, an unexpected interrupt will be triggered. 
       Disable interrupt control bit before stop DMA*/
	if( !DMA_CheckRunStat(ch) )
		return;   
	temp = DRV_Reg32(DMA_INT_EN(ch));
	DRV_WriteReg32(DMA_INT_EN(ch), 0);  
	DMA_Flush(ch);
	DMA_WaitUntilRdy(ch);
	DMA_ACKI(ch);        
	/* E1 DMA bug: restore intr. control bit */
	DRV_WriteReg32(DMA_INT_EN(ch), temp);      
#endif //__DMA_V3__
	DMA_Start(ch);
}

#endif  // __DMA_UART_VIRTUAL_FIFO__ && !__FUE__ 

/****************************** whether be EOL or not **************************************************/ 
#if defined(__RTL_SIMULATION_FOR_60QBIT__)

#include "ebm_if.h"
#include "che_hw.h"

static EBM_LOG_T dma_slowdown_ibus_log, dma_slowdown_dbus_log;
static EBM_LOG_T dma_recover_ibus_log, dma_recover_dbus_log;
extern void	cp15_clean_dcache(void);
extern void cp15_invalidate_icache(void);

#if !defined(__DMA_V3__)
static kal_uint32 dma_slowdown_mask;
#endif //#if !defined(__DMA_V3__)

/*************************************************************************************
* FUNCTION
*	test_dma_slowdown
*
* DESCRIPTION
*   DMA slowdown test code
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
*************************************************************************************/
void test_dma_slowdown( void )
{
    kal_uint32 _savedMask;
    kal_uint8 handle = 0;

    dma_slowdown_mask = 0;
    EBM_INIT();

    /* invalidate and clean ICACHE && DCACHE */
    cp15_clean_dcache();
    cp15_invalidate_icache();

    EBM_START();

    _savedMask = SaveAndSetIRQMask();

    if (dma_slowdown_mask == 0)
    {
        che_slowdown();
        /*
         * Original lcd_dma_slow_down(void) internally uses 0x3F as command
         * latency. Here we pass "4" to new lcd_dma_slow_down(level) such that
         * the command latency is longer than before.
         */
        {
            kal_uint8 index;
#if defined(__DMA_V3__)
            for(index = 1; index <= DMA_MAX_CHANNEL; index++)
            {
                DRV_WriteReg32(DMA_LIMITER(index), (DRV_Reg32(DMA_LIMITER(index))&(~DMA_CON_SLOW_MASK)) | (0xc8<<DMA_CON_SLOW_OFFSET));
            }
#endif //__DMA_V3__		 
        }
    }
    dma_slowdown_mask |= (1 << handle);
    RestoreIRQMask(_savedMask);
    EBM_PAUSE();
    EBM_GET_MCU_IBUS_LOG(&dma_slowdown_ibus_log);
    EBM_GET_MCU_DBUS_LOG(&dma_slowdown_dbus_log);
    EBM_STOP();
}

/*************************************************************************************
* FUNCTION
*	test_dma_recover
*
* DESCRIPTION
*   DMA recover 60 qbit test code.
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
*************************************************************************************/
void test_dma_recover( void )
{
    kal_uint32 _savedMask;
    kal_uint8 handle = 0;

    /*Initialize lcd variable to force enter worst path*/
    dma_slowdown_mask = 0;

    EBM_INIT();

    /* invalidate and clean ICACHE && DCACHE */
    cp15_clean_dcache();
    cp15_invalidate_icache();

    EBM_START();

    _savedMask = SaveAndSetIRQMask();

    dma_slowdown_mask &= ~(1 << handle);

    if (dma_slowdown_mask == 0)
    {
        che_recover();
        {
            kal_uint8 index;
            kal_uint8 limiter;
            limiter = dma_gbl_class_to_grade[dma_gbl_class_g];
            for(index = 1; index <= DMA_MAX_CHANNEL; index++)
            {
#if defined(__DMA_V3__)
                DRV_WriteReg32(DMA_LIMITER(index), (DRV_Reg32(DMA_LIMITER(index))&(~DMA_CON_SLOW_MASK)) | (limiter<<DMA_CON_SLOW_OFFSET));
#endif //__DMA_V3__
            }
        }
    }
    RestoreIRQMask(_savedMask);
    EBM_PAUSE();
    EBM_GET_MCU_IBUS_LOG(&dma_recover_ibus_log);
    EBM_GET_MCU_DBUS_LOG(&dma_recover_dbus_log);
    EBM_STOP();
}
#endif //__RTL_SIMULATION_FOR_60QBIT__
/*=====================================================================================================*/ 
#endif //__MULTI_CORE_SHARED_DMA__


