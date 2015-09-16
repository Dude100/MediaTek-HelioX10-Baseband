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
 * MalmoDriver.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements Malmo drivers
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __DHL_MALMO_SUPPORT__

#include "kal_general_types.h"
#include "MalmoDriver.h"
#if defined(MT6595) || defined(MT6752)
#include "drvpdn.h"
#endif

////////////////////////////Start of MALMO Test case//////////////////////////
kal_uint32 g_malmo_asm_packet_header ;

//For ASM
kal_uint32 MALMO_ASM_MonitorFilter[MALLMO_ASM_MONITOR_FILTER_WIDTH];

int apmcu_data_synchronization_barrier()
{
  //Shengkai: dummy functions for compilation
  return 0;  
}

void AdoePollSwCanSetTxPktRdy()
{
	while(1)
	{
		unsigned int tmp = *(volatile unsigned int*) (ADOE_DBG_STATES);
		tmp &= 0x000F0000;	
		if( tmp == 0x00050000 || tmp == 0x00060000 )
			break;
	}
}
		

//Important global var for ADOE, for manual mode usage
unsigned int g_AdoeBufferSizeChn0, g_AdoeBufferSizeChn1, g_AdoeBufferSizeChn2;
int g_AdoeBufferBaseAddrChn0, g_AdoeBufferBaseAddrChn1, g_AdoeBufferBaseAddrChn2;
int g_AdoeChannelEnabledStatus;

/////////////////////////////////////////////////////////////////
//Note! You need to finish all packets before resetting ALC
void AlcFinishAllPacket()
{
	unsigned char flush_valid, flush_type;
	unsigned int flush_csm;
	unsigned int dbg_state;
	unsigned int flush_left_length;
	unsigned int i;
	
	ALC_GET_SW_MANUAL_FLUSH_VALID(flush_valid);
	while(flush_valid)
	{
		ALC_GET_SW_MANUAL_FLUSH_CSM(flush_csm);
		ALC_GET_DBG_STATES(dbg_state);
		
		if( (dbg_state&0xF) != 0x0 ) //If we can not Finish it, use manual flush
		{
			ALC_SEND_CSM(flush_csm);
			ALC_GET_CURRENT_LEFT_LENGTH_AND_TYPE(flush_left_length, flush_type);
			for( i = 0 ; i < flush_left_length; ++i )
			{
				ALC_SEND_DATA(0);
			}		
		}
		else
		{
			ALC_SEND_FINISH(flush_csm); //Send Finish only
		}	
		
		flush_valid = flush_type ; //prevent compile error...
		ALC_GET_SW_MANUAL_FLUSH_VALID(flush_valid);
	}	
}


//Internal use only!
//Do not call this function PLEASE, call AlcInit instead!
void AlcReset()
{
	ADOE_SET_CH0_DISABLED;
	ADOE_SET_CH1_DISABLED;
	ADOE_SET_CH2_DISABLED;
	  
	AlcFinishAllPacket();
	while(1)
	{
		unsigned int dbg_info;
		ALC_GET_DBG_STATES(dbg_info);
		dbg_info &= 0x0000000F;
		if(dbg_info == 0x00000000)
			break;
	}
		
	ALC_RESET;
}

//Enable MAMLO HW (Clock Gating and Bus Way Enable)
void MalmoHwEnable()
{
#ifndef __TST_ON_AOS_PC__
    #if defined(MT6595) || defined(MT6752)
    // do nothing
    #else
	//Disable clock gating of MALMO system
	//MT6290 ASIC To Do *(volatile unsigned int *)MALMO_CLOCK_GATING_CONTROL |= MALMO_CLOCK_GATING_ENABLE_CODE;	
	
	//Enable ALC Bus Way Enable
	*(volatile unsigned int *)MALMO_ALC_BUS_WAY_ENABLE_CONTROL |= MALMO_ALC_BUS_WAY_ENABLE_CODE;
	//*(volatile unsigned int *)MALMO_ALC_BUS_WAY_ENABLE_CONTROL &= ~MALMO_ALC_BUS_WAY_ENABLE_CODE;
	#endif
		
#endif  //#ifndef __TST_ON_AOS_PC__
}


//Call this function to init/re-init ALC
//Please note that the basic acceptable buffer size is 1KB, and the base is in KB
char AlcInit( unsigned int *alc_l1_buffer,        //Must-be 32-bit alignment
			   unsigned int *alc_ps_buffer,       //Must-be 32-bit alignment
			   unsigned int alc_l1_buffer_length, //length in word
			   unsigned int alc_ps_buffer_length) //length in word
{
#if defined(MT6595) || defined(MT6752)
    PDN_CLR(PDN_ALC);
#endif

	AlcReset();
	
	ALC_POWER_UP;
	ALC_ENABLE;
	ALC_APDI_ENABLE;

#ifdef __BB_MT6280_0__
	// ***Chip Dependent***
	//Disable failure BMGR checking mechanism
	//MUST BE SET on MT6280 E1 E1!	
	ALC_SET_EXTRA_WAIT_WORKAROUND_DISABLE;
#endif

	//Configure ALC buffer
	ALC_SET_LOGGING_BUF0_BSAD((unsigned int)alc_l1_buffer);
	ALC_SET_LOGGING_BUF1_BSAD((unsigned int)alc_ps_buffer);
	//Note taht buffer size is in KB, the unit of input parameters is word
	ALC_SET_LOGGING_BUF0_SIZE(alc_l1_buffer_length>>8);
	ALC_SET_LOGGING_BUF1_SIZE(alc_ps_buffer_length>>8);
	
	//Configure ALC PDI Pattern
	*((volatile unsigned int*) (ALC_PDI_PATTERN0_BUF0) ) = ALC_PDI_PATTERN0_L1;	
	*((volatile unsigned int*) (ALC_PDI_PATTERN0_BUF1) ) = ALC_PDI_PATTERN0_PS;	
	*((volatile unsigned int*) (ALC_PDI_PATTERN1_BUF0) ) = ALC_PDI_PATTERN1_L1;	
	*((volatile unsigned int*) (ALC_PDI_PATTERN1_BUF1) ) = ALC_PDI_PATTERN1_PS;	
	
	apmcu_data_synchronization_barrier();	
	
	return 0;	
}

//Check LIT is full or not
int AlcCheckLitFull()
{
	unsigned int error_code;
	ALC_GET_MISC_ERR(error_code);
	if( (error_code & 0x20) == 0x20 ) //LIT is full!
	{
		error_code |= 0x20 ; //Clear LIT full signal
		return 1;
	}
	return 0;
}

//Flush all packets by SW manually
int AlcSwManualFlush(unsigned int flush_value)
{
	unsigned char flush_valid, flush_type;
	unsigned int flush_csm;
	unsigned int flush_left_length;
	unsigned int i;
	
	ALC_GET_SW_MANUAL_FLUSH_VALID(flush_valid);
	while(flush_valid)
	{
		ALC_GET_SW_MANUAL_FLUSH_CSM(flush_csm);
		ALC_SEND_CSM(flush_csm);
		
		ALC_GET_CURRENT_LEFT_LENGTH_AND_TYPE(flush_left_length, flush_type);
		for( i = 0 ; i < flush_left_length; ++i )
		{
			ALC_SEND_DATA(flush_value);
		}
		
		flush_valid = flush_type ; //prevent compile error...
		ALC_GET_SW_MANUAL_FLUSH_VALID(flush_valid);
	}
	
	return 0;
}


//Returns true when there's any error!
int AlcCheckMiscErr()
{
	unsigned int misc_err;

	//Check error status
	ALC_GET_MISC_ERR(misc_err);
	
	if( (misc_err & 0xFF) != 0x0 )
	{
		if( misc_err == 0x20 ) //Don't take LIT_FULL_ERR into account 
			return 0;
		if( misc_err == 0x10 ) //This is only warning, the burst write is incremental
			return 0;
	}	
	
	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////ADOE Function //////////////////////////////////////////

//Note: Do NOT call this function alone to reset ADOE if you're working with ALC!
void AdoeInit()
{	
#if defined(MT6595) || defined(MT6752)
    PDN_CLR(PDN_ADOE);
#endif

	ADOE_SET_CH0_DISABLED;
	ADOE_SET_CH1_DISABLED;
	ADOE_SET_CH2_DISABLED;
	
	ADOE_POLL_BUSY;
	ADOE_RESET;
	ADOE_ENABLE;
	
	apmcu_data_synchronization_barrier();	
}

//Reset ALC and ADOE
void AlcAndAdoeReset()
{
#define ADOE_USB_STATE_IDLE (0x00010000)

	ADOE_SET_CH0_DISABLED;
	ADOE_SET_CH1_DISABLED;
	ADOE_SET_CH2_DISABLED;
	
	/*  
	AlcFinishAllPacket();
	while(1)
	{
		unsigned int dbg_info;
		ALC_GET_DBG_STATES(dbg_info);
		dbg_info &= 0x0000000F;
		if(dbg_info == 0x00000000)
			break;
	}
  */
  
	//Wait ADOE to be IDLE
	ADOE_POLL_TO_BE_IDLE;
	
	ALC_RESET;
	
	ADOE_POLL_BUSY;
	ADOE_RESET;
					
	ADOE_SET_ENABLE_IGNORE_NEXTBUFRDY;
	ADOE_SET_DISABLE_IGNORE_NEXTBUFRDY;
			
	apmcu_data_synchronization_barrier();	
}

//ADOE mode:
//Config ADOE USB-Auto Mode
char AdoeConfigUsbMode(
		unsigned int usb_ep_num, 
		unsigned int usb_mps, 
		unsigned int usb_base_addr, 
		unsigned int usb_txpktrdy_base_addr)
{
#define USB_EP_BULK_MAXP_HS	512  	/* maximum packet size for high-speed bulk endpoints */
#define USB_EP_BULK_MAXP_FS	64  		/* maximum packet size for full-speed bulk endpoints */

	ADOE_SET_USB_EP_NUM(usb_ep_num);

	if(usb_mps == USB_EP_BULK_MAXP_HS)	
		ADOE_SET_USB_MPS(4);
	else
		ADOE_SET_USB_MPS(1);
	
	ADOE_SET_USB_FIFO_BASEADDR(usb_base_addr);
	ADOE_SET_USB_SETTX_ADDR(usb_txpktrdy_base_addr);
	
	return 0;
	
}

//Config ADOE UART-Auto Mode
//  single_channel is 0, 1, 2
//Note there's only UART to output on MT6280
char AdoeConfigUartMode(int single_channel_to_output)
{
	ADOE_SET_TO_AUTO_UART_MODE;

	//UART channel 0
	if(single_channel_to_output == MALMO_LOGGING_CHANNEL_ASM)
		ADOE_SET_UART0_TO_CHN0;
	else if(single_channel_to_output == MALMO_LOGGING_CHANNEL_ALC_L1)
		ADOE_SET_UART0_TO_CHN1;
	else if(single_channel_to_output == MALMO_LOGGING_CHANNEL_ALC_PS)		
		ADOE_SET_UART0_TO_CHN2;
		
  return 0; 
}

//Note! 
//You MUST set the buffer alert threshold before enabling buffer_alt_int! 
//Or it will enter INT first.
char AdoeConfigManualMode(char int_enable_val)
{
	*(volatile unsigned int*) (ADOE_BUFFER_ALT_INT_EN) |= int_enable_val;
	ADOE_INT_ENABLE; //Do not enable INT handling now
	ADOE_SET_TO_MANUAL_MODE;
	
	return 0;
}

char AdoeConfigManualModeNoInterrupt()
{
	ADOE_SET_TO_MANUAL_MODE;
	
	return 0;
}

//Call this after all settings are done!
//single_channel is 0, 1, 2
void AdoeConfigChannel(
	 char single_channel, 
	 int base_addr, 
	 unsigned int buffer_size //Note that in ADOE, it base is in "word"
	)
{
	switch( single_channel )
	{
		case MALMO_LOGGING_CHANNEL_ASM:
			ADOE_SET_LOGGING_BUFFER_BASEADDR_CHN0(base_addr);
			ADOE_SET_LOGGING_BUFFER_SIZE_CHN0(buffer_size); //Note that in ADOE, it base is in "word"
			g_AdoeBufferBaseAddrChn0 = base_addr; //for Manual mode 
			g_AdoeBufferSizeChn0 = buffer_size; //for Manual mode 
			break;
		case MALMO_LOGGING_CHANNEL_ALC_L1:
			ADOE_SET_LOGGING_BUFFER_BASEADDR_CHN1(base_addr);
			ADOE_SET_LOGGING_BUFFER_SIZE_CHN1(buffer_size); //Note that in ADOE, it base is in "word"
			g_AdoeBufferBaseAddrChn1 = base_addr; //for Manual mode 
			g_AdoeBufferSizeChn1 = buffer_size; //for Manual mode 
			break;
		case MALMO_LOGGING_CHANNEL_ALC_PS:
			ADOE_SET_LOGGING_BUFFER_BASEADDR_CHN2(base_addr);
			ADOE_SET_LOGGING_BUFFER_SIZE_CHN2(buffer_size); //Note that in ADOE, it base is in "word"
			g_AdoeBufferBaseAddrChn2 = base_addr; //for Manual mode 
			g_AdoeBufferSizeChn2 = buffer_size; //for Manual mode 
			break;			
	}
	
}

void AdoeEnableChannel(int channel_num)
{
	if(channel_num == MALMO_LOGGING_CHANNEL_ASM)
		ADOE_SET_CH0_ENABLED;
	if(channel_num == MALMO_LOGGING_CHANNEL_ALC_L1)
		ADOE_SET_CH1_ENABLED;
	if(channel_num == MALMO_LOGGING_CHANNEL_ALC_PS)
		ADOE_SET_CH2_ENABLED;
}

void AdoeDisableChannel(int channel_num)
{
	if(channel_num == MALMO_LOGGING_CHANNEL_ASM)
		ADOE_SET_CH0_DISABLED;
	if(channel_num == MALMO_LOGGING_CHANNEL_ALC_L1)
		ADOE_SET_CH1_DISABLED;
	if(channel_num == MALMO_LOGGING_CHANNEL_ALC_PS)
		ADOE_SET_CH2_DISABLED;
}

//Pause&Resume
void AdoePauseAllChannels()
{	
	ADOE_GET_CHN_ENABLED_STATUS(g_AdoeChannelEnabledStatus);
	ADOE_SET_ALL_CHN_DISABLED;
	ADOE_POLL_BUSY;
}

void AdoeResumeAllChannels()
{
	ADOE_SET_CHN_ENABLED(g_AdoeChannelEnabledStatus);
}

//Setup ADOE BWL
void AdoeSetupBwl(
	int bwl_timewindow, 
	int bwl_chn0,
	int bwl_chn1,
	int bwl_chn2 )
{
	ADOE_SET_OUTPUT_BWL_TIMEWINDOW(bwl_timewindow);
	ADOE_SET_OUTPUT_BWL_THRESHOLD_CHN0(bwl_chn0);
	ADOE_SET_OUTPUT_BWL_THRESHOLD_CHN1(bwl_chn1);
	ADOE_SET_OUTPUT_BWL_THRESHOLD_CHN2(bwl_chn2);	
}

//Manual mode
void AdoeSetManualModeAltThreshold(	
	int alt_th_chn0,
	int alt_th_chn1,
	int alt_th_chn2 )
{
	ADOE_SET_BUFFER_ALT_THRESHOLD_CHN0(alt_th_chn0);
	ADOE_SET_BUFFER_ALT_THRESHOLD_CHN1(alt_th_chn1);
	ADOE_SET_BUFFER_ALT_THRESHOLD_CHN2(alt_th_chn2);
}

void AdoeGetPtrChn0( unsigned int *rd_ptr, unsigned int *wr_ptr )
{	
	*rd_ptr = *(volatile unsigned int *)ADOE_RD_PTR_CHN0;
	*wr_ptr = *(volatile unsigned int *)ADOE_WR_PTR_CHN0;	
}

void AdoeGetPtrChn1( unsigned int *rd_ptr, unsigned int *wr_ptr )
{	
	*rd_ptr = *(volatile unsigned int *)ADOE_RD_PTR_CHN1;
	*wr_ptr = *(volatile unsigned int *)ADOE_WR_PTR_CHN1;	
}

void AdoeGetPtrChn2( unsigned int *rd_ptr, unsigned int *wr_ptr )
{	
	*rd_ptr = *(volatile unsigned int *)ADOE_RD_PTR_CHN2;
	*wr_ptr = *(volatile unsigned int *)ADOE_WR_PTR_CHN2;	
}

void AdoeUpdateRdPtrChn0( unsigned int rd_ptr )
{	
	ADOE_SET_RD_PTR_CHN0(rd_ptr);
}

void AdoeUpdateRdPtrChn1( unsigned int rd_ptr )
{	
	ADOE_SET_RD_PTR_CHN1(rd_ptr);
}

void AdoeUpdateRdPtrChn2( unsigned int rd_ptr )
{	
	ADOE_SET_RD_PTR_CHN2(rd_ptr);
}


void AdoePollAllChannelBufferAreEmpty(int b_timeout, unsigned int timeout_val)
{
	unsigned int rptr, wptr;
	//Poll Channel 0
	while(1)
	{ //According to the experiment, on MT6280E1, it takes 1 sec to decrese 83M timeout_val
		ADOE_GET_RD_PTR_CHN0(rptr);
		ADOE_GET_WR_PTR_CHN0(wptr);
		if( rptr == wptr )
			break;
	  if (b_timeout)
	  {
	    if (timeout_val == 0)  
	      break;
	    else
	      --timeout_val;
	  }
	}
	//Poll Channel 1
	while(1)
	{
		ADOE_GET_RD_PTR_CHN1(rptr);
		ADOE_GET_WR_PTR_CHN1(wptr);
		if( rptr == wptr )
			break;
	  
	  if (b_timeout)
	  {
	    if (timeout_val == 0)  
	      break;
	    else
	      --timeout_val;
	  }
	}
	//Poll Channel 2
	while(1)
	{
		ADOE_GET_RD_PTR_CHN2(rptr);
		ADOE_GET_WR_PTR_CHN2(wptr);
		if( rptr == wptr )
			break;
	  if (b_timeout)
	  {
	    if (timeout_val == 0)  
	      break;
	    else
	      --timeout_val;
	  }
	}
}
//ALC and ADOE needs special resetting procedure!
//You NEED to disable all channels first befoer re-init all loggers (ALC and ASM)
//void ResetAlcAndAdoe()
//{
//	// 1. Disable all ADOE channels
//	ADOE_SET_CH0_DISABLED;
//	ADOE_SET_CH1_DISABLED;
//	ADOE_SET_CH2_DISABLED;
//
//	// 2. Reset ALC
//	AlcInit(g_ALC_L1_BUFFER, g_ALC_PS_BUFFER, ALC_L1_BUFFER_LENGTH, ALC_PS_BUFFER_LENGTH);	
//
//	// 3. Reset ADOE
//	AdoeInit();
//}

//For DVT Only
void ClearAllRwPtr()
{
	//Disable INT first, or you'll receive the INT when you're clearing the W/R PTR
	ADOE_BUFFER_ALT_INT_DISABLE;
	
	ADOE_SET_RD_PTR_CHN0(0);
	ADOE_SET_RD_PTR_CHN1(0);
	ADOE_SET_RD_PTR_CHN2(0);	
	ADOE_SET_WR_PTR_CHN0(0);
	ADOE_SET_WR_PTR_CHN1(0);
	ADOE_SET_WR_PTR_CHN2(0);	
}


///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////ASM Function ///////////////////////////////////////////

kal_uint32 g_asm_bus_monitor_range_0_start, g_asm_bus_monitor_range_1_start, g_asm_bus_monitor_range_2_start, g_asm_bus_monitor_range_3_start;
kal_uint32 g_asm_bus_monitor_range_0_end, g_asm_bus_monitor_range_1_end, g_asm_bus_monitor_range_2_end, g_asm_bus_monitor_range_3_end;

void AsmSetBusMonitorRange();

void AsmInitMonitoringMode(
	kal_uint32 asm_mode, 
	kal_uint32 asm_timer_mode,
	kal_uint32 *asm_buffer,
	kal_uint32 asm_buffer_length,
	kal_uint32 filter_mask,
	kal_uint32 asm_swtracer_sampling_rate)
{
#if defined(MT6595) || defined(MT6752)
    PDN_CLR(PDN_ABM);
#endif

	//Reset
	ASM_INPUT_DISABLE;
	//ASM_SET_SRAM_FLUSH_TRIGGER;
	ASM_RESET;

	//Set logging buffer
	ASM_SET_LOG_BUF_BASEADDR((kal_uint32)asm_buffer);
	ASM_SET_LOG_BUF_SIZE(asm_buffer_length>>8);  //in KB
	
	//Set packet header
	ASM_SET_PDI_HEADER(ASM_PDI_HEADER);
	ASM_SET_SYNC_HEADER(ASM_SYNC_HEADER);

	//Set mode
	if( asm_mode == __ASM_BUS_MONITOR_MODE__ )
	{
		ASM_SET_MODE_TO_BUS_MONITOR_MODE;
		AsmSetBusMonitorRangeFromGlobalVar();
	}
	else if( asm_mode == __ASM_HW_SWLA_MODE__ )
	{
		ASM_SET_MODE_TO_HW_SWLA_MODE;
		ASM_SET_HW_SWLA_ADN_SW_TRACER_HEADER(ASM_HW_SWLA_HEADER);		
	}
	else if( asm_mode == __ASM_HW_SW_TRACER_MODE__ )
	{
		MALMO_ASM_SetMonitorFilter(filter_mask);
		ASM_SET_MODE_TO_HW_SW_TRACER_MODE;
		ASM_SET_HW_SWLA_ADN_SW_TRACER_HEADER(ASM_HW_SW_TRACER_HEADER);
		ASM_SET_HW_SW_TRACER_SAMPLING_RATE(asm_swtracer_sampling_rate);
	}
	else
	{
		//Should assert here!
	}

	if( asm_timer_mode == __ASM_TIMER_INPUT_FRC__ )
	{
		ASM_SET_TIMER_SELECTION_FRC;
		ASM_SET_BUS_MONITOR_HEADER(ASM_BUS_MONITOR_FRC_HEADER);		
		ASM_MONITOR_TIMER_ENABLE;
	}
	else if( asm_timer_mode == __ASM_TIMER_INPUT_3G__ )
	{
		ASM_SET_TIMER_SELECTION_3G_TIMER;
		ASM_SET_BUS_MONITOR_HEADER(ASM_BUS_MONITOR_3G_HEADER);		
		ASM_MONITOR_TIMER_ENABLE;		
	}
	else
	{
		//Should assert here!
	}

	//ASM SRAM Config
	//ASM_SET_SRAM_FLUSH_TIMEOUT(ASM_SRAM_FLUSH_TIMEOUT);
	ASM_SET_SRAM_MAX_BUF_SIZE(ASM_SRAM_SIZE_WORD);
	ASM_PDI_ENABLE;
	ASM_INPUT_ENABLE;
	
}

void AsmSetBusMonitorRange(
	kal_uint32 range0_start, kal_uint32 range0_end,
	kal_uint32 range1_start, kal_uint32 range1_end,
	kal_uint32 range2_start, kal_uint32 range2_end,
	kal_uint32 range3_start, kal_uint32 range3_end)

{
	ASM_SET_BUS_MONITOR_RAGE_0_START(range0_start);
	ASM_SET_BUS_MONITOR_RAGE_0_END(range0_end);	
	ASM_SET_BUS_MONITOR_RAGE_1_START(range1_start);
	ASM_SET_BUS_MONITOR_RAGE_1_END(range1_end);	
	ASM_SET_BUS_MONITOR_RAGE_2_START(range1_end);
	ASM_SET_BUS_MONITOR_RAGE_2_END(range2_end);	
	ASM_SET_BUS_MONITOR_RAGE_3_START(range3_start);
	ASM_SET_BUS_MONITOR_RAGE_3_END(range3_end);	
}

void AsmSetBusMonitorRangeToGlobalVar(
	kal_uint32 range0_start, kal_uint32 range0_end,
	kal_uint32 range1_start, kal_uint32 range1_end,
	kal_uint32 range2_start, kal_uint32 range2_end,
	kal_uint32 range3_start, kal_uint32 range3_end)
{
	g_asm_bus_monitor_range_0_start = range0_start;
	g_asm_bus_monitor_range_0_end = range0_end;	
	g_asm_bus_monitor_range_1_start = range1_start;
	g_asm_bus_monitor_range_1_end = range1_end;	
	g_asm_bus_monitor_range_2_start = range2_start;
	g_asm_bus_monitor_range_2_end = range2_end;	
	g_asm_bus_monitor_range_3_start = range3_start;
	g_asm_bus_monitor_range_3_end = range3_end;
}


void AsmSetBusMonitorRangeFromGlobalVar()
{
	ASM_SET_BUS_MONITOR_RAGE_0_START(g_asm_bus_monitor_range_0_start);
	ASM_SET_BUS_MONITOR_RAGE_0_END(g_asm_bus_monitor_range_0_end);	
	ASM_SET_BUS_MONITOR_RAGE_1_START(g_asm_bus_monitor_range_1_start);
	ASM_SET_BUS_MONITOR_RAGE_1_END(g_asm_bus_monitor_range_1_end);	
	ASM_SET_BUS_MONITOR_RAGE_2_START(g_asm_bus_monitor_range_2_start);
	ASM_SET_BUS_MONITOR_RAGE_2_END(g_asm_bus_monitor_range_2_end);	
	ASM_SET_BUS_MONITOR_RAGE_3_START(g_asm_bus_monitor_range_3_start);
	ASM_SET_BUS_MONITOR_RAGE_3_END(g_asm_bus_monitor_range_3_end);		
}

/////////////////////////////////////End///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////






/////////////////////////////////////////////////////////////////////////////////
//Example!!!
/////////////////////////////////////////////////////////////////////////////////
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
#ifdef __BB_MT6280_0__
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
#endif

//For SS team
/////////////MALMO_ASM_InitSwlaMode////////
//buffer_baseaddr:
//  MUST-BE 32 bit alignment!!!

//buffer_len:
//  The base is in "KB (256 word) "!
//  Note that the minimum size is 256 (1KB)
//  Ex. 1KB -> 256
//      2KB -> 512

//timestamp_type: 
//  #define __ASM_TIMER_INPUT_FRC__     (0)
//  #define __ASM_TIMER_INPUT_3G__      (1)
kal_uint32 MALMO_ASM_InitSwlaMode( kal_uint32* buffer_baseaddr, kal_uint32 buffer_len, kal_uint32 timestamp_type )
{
#define ASM_SW_TRACER_SAMPLING_RATE_DUMMY (0)
#define ASM_SW_TRACER_FILTER_DUMMY (0)

//MT6280 ASM bug! The size of ASM buffer can only have one-1
#define ASM_MAX_BUF_BIT_LEN (24)
	kal_uint32 i;
	if( buffer_len == 0 )
		while(1); //should not happen
		
	for( i = 0 ; i < ASM_MAX_BUF_BIT_LEN; ++i )
	{
		if( buffer_len==0 )
			break;
		buffer_len = (buffer_len >> 1);
	}
	buffer_len = (1 << (i-1));
	
#if defined(MT6595) || defined(MT6752)
    PDN_CLR(PDN_ABM);
#endif

	ADOE_SET_CH0_DISABLED;
	
	AdoeConfigChannel(ADOE_ASM_CHN, (kal_uint32)buffer_baseaddr, buffer_len); 
	AdoeEnableChannel(ADOE_ASM_CHN);

	AsmInitMonitoringMode( __ASM_HW_SWLA_MODE__, timestamp_type, buffer_baseaddr, buffer_len, ASM_SW_TRACER_FILTER_DUMMY, ASM_SW_TRACER_SAMPLING_RATE_DUMMY );
	return MALMO_ASM_ERR_CODE_NO_ERROR;
}

/////////////MALMO_ASM_InitSwTracerMode////////
//buffer_baseaddr:
//  MUST-BE 32 bit alignment!!!

//buffer_len:
//  The base is in "KB (256 word) "!
//  Note that the minimum size is 256 (1KB)
//  Ex. 1KB -> 256
//      2KB -> 512

//timestamp_type: 
//  #define __ASM_TIMER_INPUT_FRC__     (0)
//  #define __ASM_TIMER_INPUT_3G__      (1)

//The parameters are almost the same as MALMO_ASM_InitSwlaMode 
// However you need to assign the sampling rate for SW-Tracer
kal_uint32 MALMO_ASM_InitSwTracerMode( 
	kal_uint32* buffer_baseaddr, 
	kal_uint32 buffer_len, 
	kal_uint32 timestamp_type,
	kal_uint32 filter_mask,
	kal_uint32 asm_swtracer_sampling_rate
	)
{
//MT6280 ASM bug! The size of ASM buffer can only have one-1
#define ASM_MAX_BUF_BIT_LEN (24)
	kal_uint32 i;
	if( buffer_len == 0 )
		while(1); //should not happen
			
	for( i = 0 ; i < ASM_MAX_BUF_BIT_LEN; ++i )
	{
		if( buffer_len==0 )
			break;
		buffer_len = (buffer_len >> 1);
	}
	buffer_len = (1 << (i-1));	

#if defined(MT6595) || defined(MT6752)
    PDN_CLR(PDN_ABM);
#endif

	ADOE_SET_CH0_DISABLED;
	
	AdoeConfigChannel(ADOE_ASM_CHN, (kal_uint32)buffer_baseaddr, buffer_len); 
	AdoeEnableChannel(ADOE_ASM_CHN);

	AsmInitMonitoringMode( __ASM_HW_SW_TRACER_MODE__, timestamp_type, buffer_baseaddr, buffer_len, filter_mask, asm_swtracer_sampling_rate );	
	return MALMO_ASM_ERR_CODE_NO_ERROR;
}

kal_uint32 MALMO_ASM_StopSwTracerMode( void )
{
	ADOE_SET_CH0_DISABLED;
	ASM_SET_MODE_TO_HW_SWLA_MODE; //Set to SWLA mode to disable SW-Tracer Mode

	return MALMO_ASM_ERR_CODE_NO_ERROR;
}

kal_uint32 MALMO_ASM_SetMonitorFilter( kal_uint32 bitMask )
{
	ASM_POLL_BUSY;
	ASM_SET_HW_MONITOR_FILTER(bitMask);	
	return MALMO_ASM_ERR_CODE_NO_ERROR;
}

kal_uint32 MALMO_ASM_FillExtraData( kal_uint32 *buf, kal_uint32 size )
{
	kal_uint32 i;
	volatile kal_uint32 *extra_addon_info_base_addr = (kal_uint32 *)ASM_PROFILE_ADDON_INFO0;

	if( size > MALMO_ASM_EXTRA_INFO_NUM )
		return MALMO_ASM_ERR_CODE_ERROR;
	
	for( i = 0 ; i < size ; ++i )
	{
		*extra_addon_info_base_addr = buf[i];
		extra_addon_info_base_addr++;
	}
	return MALMO_ASM_ERR_CODE_NO_ERROR;
}

kal_uint32 MALMO_ASM_Send( void )
{
    ASM_POLL_BUSY;

	ASM_SET_HW_SWLA_ADN_SW_TRACER_HEADER(ASM_HW_SWLA_HEADER);
	g_malmo_asm_packet_header = ASM_HW_SWLA_HEADER;

	ASM_SET_HW_SWLA_TRIGGER;
	return MALMO_ASM_ERR_CODE_NO_ERROR;	
}

kal_uint32 MALMO_ASM_ContinueSend( void )
{
    ASM_POLL_BUSY;

	g_malmo_asm_packet_header += 0x00010000;  //Increase packet num by one (frame num)
	ASM_SET_HW_SWLA_ADN_SW_TRACER_HEADER( g_malmo_asm_packet_header );
	
	ASM_SET_HW_SWLA_TRIGGER;
	return MALMO_ASM_ERR_CODE_NO_ERROR;
}

//For ASM-SWLA Performance Optimization
kal_uint32 MALMO_ASM_SendOnlyOnePacket( void )
{
	ASM_SET_HW_SWLA_TRIGGER;
	return MALMO_ASM_ERR_CODE_NO_ERROR;	
}

kal_uint32* MALMO_ASM_GetMonitorFilterInfo( void )
{
#if defined(MT6280_S00)
	MALMO_ASM_MonitorFilter[0] = MALMO_ASM_MCU_PC;
	MALMO_ASM_MonitorFilter[1] = MALMO_ASM_CONTEXT_ID;
	MALMO_ASM_MonitorFilter[2] = MALMO_ASM_PMC0;
	MALMO_ASM_MonitorFilter[3] = MALMO_ASM_PMC1;
	MALMO_ASM_MonitorFilter[4] = MALMO_ASM_PMC2;
	MALMO_ASM_MonitorFilter[5] = MALMO_ASM_CYCLE_CNT;
	MALMO_ASM_MonitorFilter[6] = MALMO_ASM_EMI_BCNT;
	MALMO_ASM_MonitorFilter[7] = MALMO_ASM_EMI_BACT;
	MALMO_ASM_MonitorFilter[8] = MALMO_ASM_EMI_BSCT;
	MALMO_ASM_MonitorFilter[9] = MALMO_ASM_EMI_BSCT2;
	MALMO_ASM_MonitorFilter[10] = MALMO_ASM_EMI_BSCT3;
	MALMO_ASM_MonitorFilter[11] = MALMO_ASM_TIMESTAMP;
	MALMO_ASM_MonitorFilter[12] = MALMO_ASM_EXTRA0;
	MALMO_ASM_MonitorFilter[13] = MALMO_ASM_EXTRA1;
	MALMO_ASM_MonitorFilter[14] = MALMO_ASM_EXTRA2;	
	MALMO_ASM_MonitorFilter[15] = MALMO_ASM_EXTRA3;		
#else
	MALMO_ASM_MonitorFilter[0] = MALMO_ASM_MCU_PC;
	MALMO_ASM_MonitorFilter[1] = MALMO_ASM_CONTEXT_ID;
	MALMO_ASM_MonitorFilter[2] = MALMO_ASM_PMC0;
	MALMO_ASM_MonitorFilter[3] = MALMO_ASM_PMC1;
	MALMO_ASM_MonitorFilter[4] = MALMO_ASM_PMC2;
	MALMO_ASM_MonitorFilter[5] = MALMO_ASM_CYCLE_CNT;
	MALMO_ASM_MonitorFilter[6] = MALMO_ASM_EMI_BCNT;
	MALMO_ASM_MonitorFilter[7] = MALMO_ASM_EMI_BACT;
	MALMO_ASM_MonitorFilter[8] = MALMO_ASM_EMI_BSCT;
	MALMO_ASM_MonitorFilter[9] = MALMO_ASM_EMI_BSCT2;
	MALMO_ASM_MonitorFilter[10] = MALMO_ASM_EMI_BSCT3;
	MALMO_ASM_MonitorFilter[11] = MALMO_ASM_TIMESTAMP;
	MALMO_ASM_MonitorFilter[12] = MALMO_ASM_EXTRA0;
	MALMO_ASM_MonitorFilter[13] = MALMO_ASM_EXTRA1;
	MALMO_ASM_MonitorFilter[14] = MALMO_ASM_EXTRA2; 
	MALMO_ASM_MonitorFilter[15] = MALMO_ASM_EXTRA3;
	MALMO_ASM_MonitorFilter[16] = MALMO_ASM_EXTRA4;
	MALMO_ASM_MonitorFilter[17] = MALMO_ASM_EXTRA5;
	MALMO_ASM_MonitorFilter[18] = MALMO_ASM_EXTRA6; 
	MALMO_ASM_MonitorFilter[19] = MALMO_ASM_EXTRA7;
	MALMO_ASM_MonitorFilter[20] = MALMO_ASM_EXTRA8;
	MALMO_ASM_MonitorFilter[21] = MALMO_ASM_EXTRA9;
	MALMO_ASM_MonitorFilter[22] = MALMO_ASM_EXTRA10; 
	MALMO_ASM_MonitorFilter[23] = MALMO_ASM_EXTRA11;
#endif

	return MALMO_ASM_MonitorFilter;
}

/////////////MALMO_ASM_InitBusMonitorMode////////
//buffer_baseaddr:
//  MUST-BE 32 bit alignment!!!

//buffer_len:
//  The base is in "KB (256 word) "!
//  Note that the minimum size is 256 (1KB)
//  Ex. 1KB -> 256
//      2KB -> 512

//timestamp_type: 
//  #define __ASM_TIMER_INPUT_FRC__     (0)
//  #define __ASM_TIMER_INPUT_3G__      (1)

//Monitor Range: from range0 ~ range3
kal_uint32 MALMO_ASM_InitBusMonitorMode( 
	kal_uint32* buffer_baseaddr, 
	kal_uint32 buffer_len, 
	kal_uint32 timestamp_type, 
	kal_uint32 range0_start, kal_uint32 range0_end,
	kal_uint32 range1_start, kal_uint32 range1_end,
	kal_uint32 range2_start, kal_uint32 range2_end,
	kal_uint32 range3_start, kal_uint32 range3_end )
{
#define ASM_SW_TRACER_SAMPLING_RATE_DUMMY (0)
#define ASM_SW_TRACER_FILTER_DUMMY (0)

//MT6280 ASM bug! The size of ASM buffer can only have one-1
#define ASM_MAX_BUF_BIT_LEN (24)
	kal_uint32 i;
	if( buffer_len == 0 )
		while(1); //should not happen
		
	for( i = 0 ; i < ASM_MAX_BUF_BIT_LEN; ++i )
	{
		if( buffer_len==0 )
			break;
		buffer_len = (buffer_len >> 1);
	}
	buffer_len = (1 << (i-1));	

	AsmSetBusMonitorRangeToGlobalVar(range0_start, range0_end, range1_start, range1_end, range2_start, range2_end, range3_start, range3_end);

	MALMO_ASM_StopBusMonitorMode();

	ADOE_SET_CH0_DISABLED;
	
	AdoeConfigChannel(ADOE_ASM_CHN, (kal_uint32)buffer_baseaddr, buffer_len); 
	AdoeEnableChannel(ADOE_ASM_CHN);

	AsmInitMonitoringMode( __ASM_BUS_MONITOR_MODE__, timestamp_type, buffer_baseaddr, buffer_len, ASM_SW_TRACER_FILTER_DUMMY, ASM_SW_TRACER_SAMPLING_RATE_DUMMY );
	
	return MALMO_ASM_ERR_CODE_NO_ERROR;
}


kal_uint32 MALMO_ASM_StopBusMonitorMode( void )
{
	ADOE_SET_CH0_DISABLED;
	
	ASM_SET_MODE_TO_HW_SWLA_MODE; //Set to SWLA mode to disable SW-Tracer Mode

	return MALMO_ASM_ERR_CODE_NO_ERROR;
}

kal_uint32 MALMO_ASM_GetBufferSize(kal_uint32 buffer_len)
{
  //MT6280 ASM bug! The size of ASM buffer can only have one-1
  #define ASM_MAX_BUF_BIT_LEN (24)
	kal_uint32 i;
  
	if( buffer_len == 0 )
		while(1); //should not happen
			
	for( i = 0 ; i < ASM_MAX_BUF_BIT_LEN; ++i )
	{
		if(buffer_len == 0)
		{
			break;
		}
		buffer_len = (buffer_len >> 1);
	}
  
	buffer_len = (1 << (i-1));	

  return buffer_len;
}

#endif  //__DHL_MALMO_SUPPORT__
