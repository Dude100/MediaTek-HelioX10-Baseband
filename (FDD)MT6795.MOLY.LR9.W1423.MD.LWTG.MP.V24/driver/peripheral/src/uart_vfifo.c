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
 *    uart_vfifo.c      
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the functions for virtual FIFO
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include    "drv_features.h"
#include "sync_data.h"
//#include    "kal_release.h"
//#include    "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include    "stack_msgs.h"
//#include "stack_ltlcom.h" //MSBB change #include    "app_ltlcom.h"       /* Task message communiction */
//#include    "stack_buff_pool.h"
//#include    "app_buff_alloc.h"
#include    "drv_comm.h"
#include    "reg_base.h"
#include    "uart_hw.h"
//#include    "bmd.h"
//#include    "intrCtrl.h"
//#include    "drvpdn.h"
//#include    "stack_ltlcom.h"       /*msg_send_ext_queue.....definitions*/
#include "kal_public_defs.h" //MSBB change #include    "stack_config.h"        /*MOD_UART1_HISR,MOD_UART2_HISR*/
#include    "uart_sw.h"
#include "uart_internal.h"
#include    "dma_hw.h"
#include    "dma_sw.h"
#include    "uart_hw.h"
#include    "gpt_sw.h"
//#include    "init.h"
#include    "drv_trc.h"
#ifdef __ROMSA_SUPPORT__
#ifndef __ROMSA_EXPORT_UART_H__
#include "romsa_export_uart.h"
#endif
#include    "gpt_hw.h"
#endif
//#include "kal_non_specific_general_types.h"
//#include "kal_common_defs.h"
#include "l1_interface.h"
#include "us_timer.h"

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "dcl.h"
//#include "kal_internal_api.h"

#ifdef __DMA_UART_VIRTUAL_FIFO__
#if !defined(DRV_UART_OFF)

/*variable*/
extern const kal_uint32 UART_BaseAddr[MAX_UART_PORT_NUM];
extern UARTStruct UARTPort[MAX_UART_PORT_NUM];
extern const UART_rings_struct *UART_rings;
extern kal_uint8 uart_escape_state;
extern kal_bool send_Rxilm[MAX_UART_PORT_NUM];
extern kal_bool send_Txilm[MAX_UART_PORT_NUM];
/*function*/ 
extern void UART_sendilm(UART_PORT port, msg_type msgid);
extern void UART_Calback(void *parameter);

extern UartDriver_strcut* pUart_CMD_FUNC[];

kal_uint32 GET_RX_DMA_WRPTR( UART_PORT port);
kal_uint32 GET_RX_DMA_RDPTR( UART_PORT port);

#if defined(DRV_UART_VFIFO_V3)


void DMA_PUSH32(kal_uint8 channel, kal_uint32 data )
{
	kal_uint16 LeftRingRoom, VFIFOSize ;
	kal_uint8 i = 0;
	kal_uint32* pBuffer = NULL;
	kal_uint16 WritePointer = 0;
	kal_uint8* pdata = (kal_uint8*)&data;

	//ch = channel;
     WritePointer = DRV_Reg(DMA_VFF_WPT(channel));
	VFIFOSize = DRV_Reg(DMA_VFF_SIZE(channel));
	
	LeftRingRoom = VFIFOSize-WritePointer;
	
	
	pBuffer = (kal_uint32*)(WritePointer + DRV_Reg32(DMA_SRC(channel)));
		
	if(LeftRingRoom > 5)
	{
		*pBuffer = data;
	    Data_Sync_Barrier();	
		DRV_WriteReg(DMA_VFF_WPT(channel),(WritePointer+4));
	}
	else
	{
		for(i =0; i < 4; i++)
			{
			DMA_PUSH(channel, *pdata);
			}
	}
}


void DMA_PUSH_Multi_VFIFO(UART_PORT port,kal_uint8 *pData, kal_uint32 size, kal_uint32 multi)
{

	kal_uint8 ch;
	kal_uint32 LeftRoom, VFIFO_Size, Write_Pointer ;

	ch = UARTPort[port].Tx_DMA_Ch;
	VFIFO_Size = DRV_Reg(DMA_VFF_SIZE(ch));
	Write_Pointer = DRV_Reg(DMA_VFF_WPT(ch));

	if(0 == size)
		return;

	LeftRoom = VFIFO_Size - Write_Pointer;

	if(LeftRoom == 0)
		return;
	
	if(LeftRoom > size)
		{
		//memcpy((volatile kal_uint8 *)(DRV_Reg(DMA_VFF_WPT(ch))+DRV_Reg32(DMA_SRC(ch))), (kal_uint8 *)pData, size);
		//for build warning
	                memcpy((kal_uint8 *)(DRV_Reg(DMA_VFF_WPT(ch))+DRV_Reg32(DMA_SRC(ch))), (kal_uint8 *)pData, size);
			Data_Sync_Barrier();	
			DRV_WriteReg32(DMA_VFF_WPT(ch), DRV_Reg32(DMA_VFF_WPT(ch))+size);
		}

	if(LeftRoom < size)
		{
			memcpy((kal_uint8 *)(DRV_Reg(DMA_VFF_WPT(ch))+DRV_Reg32(DMA_SRC(ch))), (kal_uint8 *)pData, LeftRoom);
		        Data_Sync_Barrier();	
			DRV_WriteReg32(DMA_VFF_WPT(ch), (~DRV_Reg32(DMA_VFF_WPT(ch)))&0x10000);	
			memcpy((kal_uint8 *)(DRV_Reg(DMA_VFF_WPT(ch))+DRV_Reg32(DMA_SRC(ch))), (kal_uint8 *)(pData +LeftRoom), (size-LeftRoom));
		        Data_Sync_Barrier();	
			DRV_WriteReg32(DMA_VFF_WPT(ch), DRV_Reg32(DMA_VFF_WPT(ch))+(size-LeftRoom));
			
			
		}
	
	 if(LeftRoom == size)
		{
		
			memcpy((kal_uint8 *)(DRV_Reg(DMA_VFF_WPT(ch))+DRV_Reg32(DMA_SRC(ch))), (kal_uint8 *)pData, LeftRoom);
			Data_Sync_Barrier();	
			DRV_WriteReg32(DMA_VFF_WPT(ch), (~DRV_Reg32(DMA_VFF_WPT(ch)))&0x10000);	
		}

}


#endif


#if defined(DRV_UART_VFIFO_V2)
#if defined(DRV_UART_VFIFO_V2_USE_GPT)
#else
kal_timerid   uart_isr_flush_timer_id;
UART_PORT uart_isr_port;
kal_hisrid uart_isr_hisr_id = KAL_NILHISR_ID;
#endif //defined(DRV_UART_VFIFO_V2_USE_GPT)

#define UART_DMA_FLUSH_WAIT_LOOP 500000

void DMA_PUSH_Multi_VFIFO(UART_PORT port,kal_uint8 *pData, kal_uint32 size, kal_uint32 multi)
{
	kal_uint32 *p32tmp;
	kal_uint32 i;
	kal_uint32 header, tail;
	kal_uint32 _times;	
//	kal_uint16 LSR;
	kal_uint8 *pTemp;
	kal_uint8 ch;

  	ch = UARTPort[port].Tx_DMA_Ch;
	
	multi = multi<=4?4:8;

	header = size>=multi?multi-((int)pData%multi):size; // align 8 
	header = header==multi?0:header;
	tail = size>=multi?(size-header)%multi:0;
	_times = (size-header-tail)/multi;
	
	for (i=0;i<header;i++)
	{
		//DMA_PUSH(ch,*(pData+i));
	while(DRV_UART_Reg(DMA_W_INT_BUF_SIZE(ch))>=64);
	*(volatile kal_uint8*)DMA_VPORT(ch) = (kal_uint8)*(pData+i);

		
	}
	for(i=0;i<_times;i++)
	{
		p32tmp = (kal_uint32 *)(pData+header);

			//	if(multi == 4)
					DMA_PUSH32(ch, *(p32tmp+i) );
			//	else
			//		DMA_PUSH64(*(p32tmp+2*i), *(p32tmp+2*i+1), ch);

	}
	for (i=0;i<tail;i++)
	{
		pTemp = pData+header+multi*_times;
		DMA_PUSH(ch,*(pTemp+i));
	}	

}


void uart_dma_flush(void *timer_param)
{
	kal_uint8 i;
	kal_uint8 ch;
#if defined(DRV_UART_VFIFO_V2_USE_GPT)	
	kal_uint32  *pTimerHandle=(kal_uint32 *)timer_param;
    SGPT_CTRL_START_T start;

#else
	kal_timerid *pTimerid=(kal_timerid *)timer_param;
#endif		
	kal_uint32 flush_tick;

#if defined(DRV_UART_VFIFO_V2_USE_GPT)	

	for (i=0;i<MAX_UART_PORT_NUM;i++)
	{
		if (UARTPort[i].uart_flush_timer_handle==*pTimerHandle)
		{
			break;
		}
		else if(UARTPort[i].uart_isr_flush_timer_handle==*pTimerHandle)
		{
			break;
		}
	}	
#else	
	for (i=0;i<MAX_UART_PORT_NUM;i++)
	{
		if (UARTPort[i].uart_flush_timer_id==*pTimerid)
		{
			break;
		}
        }

	if (i==MAX_UART_PORT_NUM && *pTimerid==uart_isr_flush_timer_id)
	{
		i=uart_isr_port;
	}
#endif	

	ASSERT(i < MAX_UART_PORT_NUM);
	ch=UARTPort[i].Tx_DMA_Ch;
	
	if (DRV_UART_Reg(DMA_W_INT_BUF_SIZE(ch))!=0)
	{
		if (DRV_UART_Reg(DMA_FLUSH(ch))==0)
		{
			DMA_Flush(ch);
		}
		else
		{
#if defined(DRV_UART_VFIFO_V2_USE_GPT)			
			flush_tick=DRV_UART_Reg(DMA_VFF_VALID_SIZE(ch))*10/UARTPort[i].DCB.baud/100;

	//		GPTI_StopItem(*pTimerHandle);
	DclSGPT_Control(*pTimerHandle,SGPT_CMD_STOP,0);

/*
			GPTI_StartItem(*pTimerHandle,
                     flush_tick,
                     uart_dma_flush,
                     (void*)pTimerHandle);
                     */
            start.u2Tick=flush_tick;
			start.pfCallback=uart_dma_flush;
			start.vPara=(void*)pTimerHandle;
			DclSGPT_Control(*pTimerHandle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
#else	
			flush_tick=DRV_UART_Reg(DMA_VFF_VALID_SIZE(ch))*10*650/3/UARTPort[i].DCB.baud;
			kal_set_timer(*pTimerid, (kal_timer_func_ptr)uart_dma_flush, (void*)pTimerid, flush_tick,	0);
#endif	
		}
	}

}

void uart_isr_dma_flush(void)
{
	kal_uint32 uart_flush_timer_tick;

	if (kal_get_time_remaining(uart_isr_flush_timer_id)==0)
	{
		uart_flush_timer_tick=DRV_UART_Reg(DMA_VFF_VALID_SIZE(UARTPort[uart_isr_port].Tx_DMA_Ch))*10*650/3/UARTPort[uart_isr_port].DCB.baud;
		kal_cancel_timer(uart_isr_flush_timer_id);
		kal_set_timer(uart_isr_flush_timer_id, (kal_timer_func_ptr)uart_dma_flush, (void*)&uart_isr_flush_timer_id, uart_flush_timer_tick,0);
	}

}

void VFIFO_DMA_Flush(UART_PORT port,kal_bool is_ISR)
{
	kal_uint32 uart_flush_timer_tick;
	kal_uint8 ch;
#if defined(DRV_UART_VFIFO_V2_USE_GPT)	
	DCL_HANDLE *pTimerHandle;
    SGPT_CTRL_START_T start;

#else
	kal_timerid *pTimerid;
#endif	
	ch=UARTPort[port].Tx_DMA_Ch;

	if (DRV_UART_Reg(DMA_W_INT_BUF_SIZE(ch))!=0)
	{
		

		if(DRV_UART_Reg(DMA_FLUSH(ch))==0)
		{
			DMA_Flush(ch);
		}
		else 
		{
#if defined(DRV_UART_VFIFO_V2_USE_GPT)

			if (is_ISR==KAL_FALSE)
				pTimerHandle=&UARTPort[port].uart_flush_timer_handle;
			else
				pTimerHandle=&UARTPort[port].uart_isr_flush_timer_handle;


			uart_flush_timer_tick=DRV_UART_Reg(DMA_VFF_VALID_SIZE(ch))*10/UARTPort[port].DCB.baud/100;

		//	GPTI_StopItem(*pTimerHandle);
			DclSGPT_Control(*pTimerHandle,SGPT_CMD_STOP,0);
		/*
			GPTI_StartItem(*pTimerHandle,
                     uart_flush_timer_tick,
                     uart_dma_flush,
                     (void*)pTimerHandle);*/
                     
		    
			start.u2Tick=uart_flush_timer_tick;
			start.pfCallback=uart_dma_flush;
			start.vPara=(void*)pTimerHandle;
			DclSGPT_Control(*pTimerHandle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);

	
#else

			if (is_ISR==KAL_FALSE)
			{
				pTimerid=&UARTPort[port].uart_flush_timer_id;
				if (kal_get_time_remaining(*pTimerid)==0)
			{
					uart_flush_timer_tick=DRV_UART_Reg(DMA_VFF_VALID_SIZE(ch))*10*650/3/UARTPort[port].DCB.baud;
					kal_cancel_timer(*pTimerid);
					kal_set_timer(*pTimerid, (kal_timer_func_ptr)uart_dma_flush, (void*)pTimerid, uart_flush_timer_tick,0);
			}

			}
			else
			{
					uart_isr_port=port;
					kal_activate_hisr(uart_isr_hisr_id);
			}

#endif //defined(DRV_UART_VFIFO_V2_USEGPT)

		}
	}
}
#endif /* defined(DRV_UART_VFIFO_V2) */





/*UART API*/
// toy recommend: do not handle any rx data in UART_RecTimeOutHandler(), otherwise single vfifo will fail
kal_uint16 U_GetTxISRRoomLeft_VFIFO(UART_PORT port)
{ 
   kal_uint16 real_count; 

	real_count=DMA_GetVFIFO_Roomleft(UARTPort[port].Tx_DMA_Ch);

   /*temp solution: to cover L1 trace bug*/
   if(real_count<=16)
   	real_count=0;
   else
     real_count-=16;
     
   return real_count;
}
// toy recommend: do not handle any rx data in UART_RecTimeOutHandler(), otherwise single vfifo will fail
kal_uint16 U_GetTxRoomLeft_VFIFO(UART_PORT port)
{
   kal_uint16 real_count;
   kal_uint32  savedMask;

   savedMask = SaveAndSetIRQMask();
	real_count=DMA_GetVFIFO_Roomleft(UARTPort[port].Tx_DMA_Ch);
	RestoreIRQMask(savedMask);
 
   return real_count;
}
kal_uint16 U_GetBytesAvail_VFIFO(UART_PORT port)
{	
   kal_uint16 real_count;

   real_count=DMA_GetVFIFO_Avail(UARTPort[port].Rx_DMA_Ch);
   return real_count;
}
// toy recommend: do not handle any tx data in UART_RecTimeOutHandler(), otherwise single vfifo will fail
kal_uint8 U_GetUARTByte_VFIFO(UART_PORT port)
{

  kal_uint8 data;
  kal_uint8 ch;
  kal_uint16  real_count=0;

  ch = UARTPort[port].Rx_DMA_Ch;
  while(1)
  {
     real_count=DMA_GetVFIFO_Avail(ch);
     if (real_count!=0)
     {
        data = DMA_POP(ch);
	//Shengkai
        if (uart_support_autoescape()==KAL_FALSE || (kal_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw && UARTPort[port].ownerid==MOD_DHL_READER) )
        {
           if(UARTPort[port].DCB.flowControl==fc_sw)
           {     
              if(uart_escape_state==0)
              {
                 if(data==0x77)            
                    uart_escape_state=0x77;
                 else            
                    return data;
              }
              else if (uart_escape_state==0x77)
              {
                 uart_escape_state=0x0; 
                 switch(data)
                 {
                    case 0x01:
                       return UARTPort[port].DCB.xonChar;
                    //   break;
                    case 0x02:
                       return UARTPort[port].DCB.xoffChar;
                    //   break;               
                    case 0x03:
                       return 0x77;                  
                     //  break;      
                    default:                     
                       break;      
                 }                                            
              }                           
           }
           else
              return data;            
         } 
         else
         {
	   return data;
         }      
     }
  }        
}

kal_uint8 U_GetUARTByteWithTimeOut_VFIFO(UART_PORT port, kal_uint8* ret_ch, kal_uint32 timeout_value)
{

  kal_uint8 data;
  kal_uint8 ch;
  kal_uint16  real_count=0;
  kal_uint8 res_byte = 0;  

  ch = UARTPort[port].Rx_DMA_Ch;
  while(timeout_value != 0)
  {
     real_count=DMA_GetVFIFO_Avail(ch);
     if (real_count!=0)
     {
        data = DMA_POP(ch);	
        res_byte = 1;
        if (uart_support_autoescape()==KAL_FALSE || (kal_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw && UARTPort[port].ownerid==MOD_DHL_READER) )
        {
           if(UARTPort[port].DCB.flowControl==fc_sw)
           {     
              if(uart_escape_state==0)
              {
                 if(data==0x77)            
                    uart_escape_state=0x77;
                 else            
                 {
                   *ret_ch = data; 
                   break;
                 }
              }
              else if (uart_escape_state==0x77)
              {
                 uart_escape_state=0x0; 
               
                 if (data == 0x01)
                 {
                   *ret_ch = UARTPort[port].DCB.xonChar;
                   break;
                 }
                 else if (data == 0x02)
                 {
                   *ret_ch = UARTPort[port].DCB.xoffChar;
                   break;
                 }
                 else if (data == 0x03)
                 {
                   *ret_ch = 0x77;
                   break;
                 }                                              
              }                           
           }
           else
           {
              *ret_ch = data; 
              break;           
           }
         } 
         else
         {
	         *ret_ch = data; 
           break; 
         }          
     }
     
     --timeout_value;
  } 
  
  return  res_byte;      
}
// toy recommend: do not handle any rx data in UART_RecTimeOutHandler(), otherwise single vfifo will fail
void U_PutUARTByte_VFIFO(UART_PORT port, kal_uint8 data)
{

  kal_uint8 ch;
#if defined(DRV_UART_VFIFO_V2)  
  kal_uint32 start_ticks=0;
#endif /* defined(DRV_UART_VFIFO_V2) */

  ch = UARTPort[port].Tx_DMA_Ch;
  while(1)
  {
    if (!IS_VFIFO_FULL(ch)) // fifo not full
    {
      DMA_PUSH(ch,data);
      break;
    }
  }

#if defined(DRV_UART_VFIFO_V2)
	while (DRV_UART_Reg(DMA_FLUSH(ch))!=0)
	{
            start_ticks++;//busy loop to wait DMA send out all data.
            if(start_ticks > UART_DMA_FLUSH_WAIT_LOOP)
               break;
         }
  DMA_Flush(ch);
  
#elif defined(DRV_UART_VFIFO_V3)
DMA_Flush(ch);
DMA_Flush(ch);

#else

#endif /* defined(DRV_UART_VFIFO_V2) */

}
// toy recommend: do not handle any rx data in UART_RecTimeOutHandler(), otherwise single vfifo will fail
void PutUARTData_VFIFO(UART_PORT port, kal_uint8 escape_char, kal_uint8 data)
{
   if(port >= MAX_UART_PORT_NUM)
      return;

   if( (kal_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw && UARTPort[port].ownerid==MOD_DHL_READER)||
       (uart_support_autoescape()==KAL_FALSE))     
   {
		if (data == UARTPort[port].DCB.xonChar)
   	{
   			pUart_CMD_FUNC[port]->PutUARTByte(port, escape_char);
         pUart_CMD_FUNC[port]->PutUARTByte(port, 0x01);            
   	}
   	else if (data == UARTPort[port].DCB.xoffChar)
   	{
   		pUart_CMD_FUNC[port]->PutUARTByte(port, escape_char);
      pUart_CMD_FUNC[port]->PutUARTByte(port, 0x02);            
   	}
   	else if (data == escape_char)
   	{
       pUart_CMD_FUNC[port]->PutUARTByte(port, escape_char);
       pUart_CMD_FUNC[port]->PutUARTByte(port, 0x03);            
   	}
   	else
   	{
   		pUart_CMD_FUNC[port]->PutUARTByte(port, data);
   	}         
   }
   else
   {
   	pUart_CMD_FUNC[port]->PutUARTByte(port, data);
   }        
}

// toy recommend: do not handle any tx data in UART_RecTimeOutHandler(), otherwise single vfifo will fail
kal_uint16 U_GetBytes_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid)
{
   kal_uint16  real_count,index;
   kal_uint8 ch;
   kal_uint16   data_count=0;


   ch = UARTPort[port].Rx_DMA_Ch;
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);

   if (status != NULL)
      *status = 0;

   // get available bytes in rx ring buffer
	real_count = DMA_GetVFIFO_Avail(ch);
   
#if defined(DRV_UART_COMPENSATE_AT)
   if( (UARTPort[port].CompensateAT == Compensate_AT) || (UARTPort[port].CompensateAT == Compensate_at))
   {
      data_count += 2;
      *(Buffaddr)   = (UARTPort[port].CompensateAT == Compensate_AT) ? 0x41 : 0x61; // A or a
      *(Buffaddr+1) = (UARTPort[port].CompensateAT == Compensate_AT) ? 0x54 : 0x74; // T or t
      UARTPort[port].CompensateAT = Compensate_None;
   }
   else if(UARTPort[port].CompensateAT == Compensate_Wait) // it should never happen.
   { // if autobaud fail, restart autobaud detection again.
    //  UART_SetBaudRate(port, UART_BAUD_AUTO, UARTPort[port].ownerid);
 //   U_SetBaudRate(port, UART_BAUD_AUTO, UARTPort[port].ownerid);
 	pUart_CMD_FUNC[port]->SetBaudRate(port, UART_BAUD_AUTO, UARTPort[port].ownerid);
 	send_Rxilm[port] = KAL_TRUE;          
  EnableRxIntr(UART_BaseAddr[port]);
      return 0;
   }
#endif
   if (status != NULL)
   {
      if (UARTPort[port].EscFound)
      {
         *status |= UART_STAT_EscDet;
         UARTPort[port].EscFound = KAL_FALSE;
      }
      if (UARTPort[port].breakDet)
      {
         *status |= UART_STAT_Break;
         UARTPort[port].breakDet = KAL_FALSE;
      }
   }
   do
   {      
      real_count = DMA_GetVFIFO_Avail(ch);      
      if( (kal_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw && UARTPort[port].ownerid==MOD_DHL_READER)||
          (uart_support_autoescape()==KAL_FALSE&& UARTPort[port].DCB.flowControl==fc_sw ))
      {  
         for (index = 0; (index < real_count)&& (data_count<Length) ; index++)
         {                
            *(Buffaddr+data_count) = DMA_POP(ch); 
            /*The following are for software flow control*/
            if(uart_escape_state==0)
            {
               if(*(Buffaddr+data_count)==0x77)
               {
                  uart_escape_state=0x77;               
               }   
               else   
               {
                  data_count++;
               }   
            }  
            else if (uart_escape_state==0x77)
            {
               switch(*(Buffaddr+data_count))
               {
                  case 0x01:
                     *(Buffaddr+data_count)=UARTPort[port].DCB.xonChar;
                     data_count++;
                     break;
                  case 0x02:                  
                     *(Buffaddr+data_count)=UARTPort[port].DCB.xoffChar; 
                     data_count++;                 
                     break;               
                  case 0x03:                  
                     *(Buffaddr+data_count)=0x77;
                     data_count++;
                     break;      
                  default:                  
                     break;      
               }                         
               uart_escape_state=0x0;        
            }                          
         }   
      }
      else/*HW flow control*/
      {
         for (index = 0; (index < real_count)&& (data_count<Length) ; index++)
         {            
            *(Buffaddr+data_count) = DMA_POP(ch); 
            data_count++;
         }   
      }         
      /*satisfy uart owner request, so break*/
      if (data_count == Length) break;            
      /* disable interrupt*/      
      DMA_DisableINT(ch);      
      //race condition, 3M baudrate only need 12us to trigger timeout interrupt
      //it may cause interrupt between get avail and set flag.
      DisableRxIntr(UART_BaseAddr[port]);
      real_count = DMA_GetVFIFO_Avail(ch);
       /*there is no data in ringbuffer, so break*/       
      if (real_count==0)
      {
         send_Rxilm[port] = KAL_TRUE;          
         EnableRxIntr(UART_BaseAddr[port]);

         DMA_EnableINT(ch);
         /* enable interrupt*/
         break;
      }      
      EnableRxIntr(UART_BaseAddr[port]);
      DMA_EnableINT(ch);
      /* enable interrupt*/
   }while(KAL_TRUE);      
     
   DMA_EnableINT(ch);
   return data_count;	   
}


// toy recommend: do not handle any rx data in UART_RecTimeOutHandler(), otherwise single vfifo will fail
kal_uint16 U_PutBytes_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
	kal_uint8 ch;
	kal_uint8 data;

#ifndef DRV_DEBUG
   kal_uint16  real_count,index;
   kal_uint32  savedMask;


  ch = UARTPort[port].Tx_DMA_Ch;
	EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid,  (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);

	 if((kal_query_boot_mode()== FACTORY_BOOT))
 	{
	kal_uint8 escape_char=0x77;
    kal_uint8 mode=0x1;

   real_count=U_SendData_VFIFO(port, Buffaddr,  Length, mode,escape_char,  ownerid);

	return real_count;
 	}
   if((UARTPort[port].EnableTX == KAL_FALSE) || (UARTPort[port].power_on == KAL_FALSE))
   {
   	return Length;
   }
#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
   if (UARTPort[port].sleep_on_tx == uart_sleep_on_tx_forbid)
   { 
	   UART_PDN_Disable(port);	   
   }
#endif//#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn   
   real_count = DMA_GetVFIFO_Roomleft(ch);
	UART_DBG(__LINE__,0,0,real_count);
	
/*#ifdef VFIFO_DBG
{
	kal_char s[50];
	sprintf(s,"uart_putbytes,len %d,left %d",Length,real_count);
	kal_print(s);
}
#endif*/
   if(UARTPort[port].ownerid != MOD_DHL_READER)// if catcher log via UART,Tx will be too many data
   	drv_trace2(TRACE_GROUP_4,UART_TX_VFIFO_U_PutBytes_VFIFO,Length,real_count);

   if (real_count >= Length)
   {
      real_count = Length;
   }
   else
   {
      send_Txilm[port] = KAL_TRUE;
      DMA_EnableINT(ch);
   }
   if(ownerid==MOD_DHL_READER)
   {
      for (index = 0; index < real_count; index++)
      {
        data = *(Buffaddr+index);
      	savedMask = SaveAndSetIRQMask();   
      	if(!IS_VFIFO_FULL(ch))
      	{
      		DMA_PUSH(ch,data);
      	}	
      	else
      	{
      	   real_count=index;
      	   send_Txilm[port] = KAL_TRUE;
      	   DMA_EnableINT(ch);      	   
      	   RestoreIRQMask(savedMask);	
      	   break;
      	 }   
          RestoreIRQMask(savedMask);	
      }
   }   
   else/*not TST */
   {

#if defined(DRV_UART_VFIFO_V2)     
	DMA_PUSH_Multi_VFIFO(port,Buffaddr,real_count,4);
	VFIFO_DMA_Flush(port,KAL_FALSE);
#elif defined(DRV_UART_VFIFO_V3)
DMA_PUSH_Multi_VFIFO(port,Buffaddr,real_count,4);

DMA_Flush(ch);
DMA_Flush(ch);


#else
      for (index = 0; index < real_count; index++)
      {
      	DMA_PUSH(ch,*(Buffaddr+index));
      }      
#endif /* defined(DRV_UART_VFIFO_V2) */
   }      
   /*invoke THRE interrupt*/
   //EnableTxIntr(UART_BaseAddr[port]);
   return real_count;
#else /*DRV_DEBUG*/
   return Length;
#endif /*DRV_DEBUG*/
}
// toy recommend: do not handle any rx data in UART_RecTimeOutHandler(), otherwise single vfifo will fail
kal_uint16 U_PutISRBytes_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid)
{
	kal_uint8 ch;
#ifndef DRV_DEBUG
   kal_uint16  real_count;
#if (!defined(DRV_UART_VFIFO_V2)) && (!defined(DRV_UART_VFIFO_V3))
 kal_uint16 index;
 #endif

 if(port >= MAX_UART_PORT_NUM)
  EXT_ASSERT (0,(kal_uint32) ownerid, (kal_uint32)port, 0);

  ch = UARTPort[port].Tx_DMA_Ch;
	EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);
	
   if((UARTPort[port].EnableTX == KAL_FALSE) || (UARTPort[port].power_on == KAL_FALSE))
   {
   	return Length;
   }
#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
   if (UARTPort[port].sleep_on_tx == uart_sleep_on_tx_forbid)	   
   {  
	   UART_PDN_Disable(port);	   
   }
#endif//#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
   real_count = DMA_GetVFIFO_Roomleft(ch);
/*#ifdef VFIFO_DBG
{
	kal_char s[50];
	sprintf(s,"uart_putbytes,len %d,left %d",Length,real_count);
	kal_print(s);
}
#else //#ifndef DRV_DEBUG
   if(port >= MAX_UART_PORT_NUM)
      return 0;
  ch = UARTPort[port].Tx_DMA_Ch;
#endif //#ifndef DRV_DEBUG
*/
if(UARTPort[port].ownerid != MOD_DHL_READER)// if catcher log via UART,Tx will be too many data
	drv_trace2(TRACE_GROUP_4,UART_TX_VFIFO_U_PutISRBytes_VFIFO,Length,real_count);

   if (real_count >= Length)
   {
      real_count = Length;
   }
   else
   {
      send_Txilm[port] = KAL_TRUE;
      DMA_EnableINT(ch);
   }
   

#if defined(DRV_UART_VFIFO_V2)     
	DMA_PUSH_Multi_VFIFO(port,Buffaddr,real_count,4);
	VFIFO_DMA_Flush(port,KAL_TRUE);
#elif defined(DRV_UART_VFIFO_V3)
DMA_PUSH_Multi_VFIFO(port,Buffaddr,real_count,4);
DMA_Flush(ch);
DMA_Flush(ch);

#else
   for (index = 0; index < real_count; index++)
   {   	
   	DMA_PUSH(ch,*(Buffaddr+index));   		
   }
#endif /* defined(DRV_UART_VFIFO_V2) */


   /*invoke THRE interrupt*/
   //EnableTxIntr(UART_BaseAddr[port]);
   return real_count;
#else /*DRV_DEBUG*/
   return Length;
#endif /*DRV_DEBUG*/
}
// toy recommend: do not handle any rx data in UART_RecTimeOutHandler(), otherwise single vfifo will fail
kal_uint16 U_SendData_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid)
{
#ifndef DRV_DEBUG
    kal_uint16   real_count,index;
    kal_uint8   data;
    kal_uint8 ch;
    kal_uint32  savedMask;

   ch = UARTPort[port].Tx_DMA_Ch;
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid,  (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);
   
   if((UARTPort[port].EnableTX == KAL_FALSE) || (UARTPort[port].power_on == KAL_FALSE))
   {
   	return Length;
   }      
   
   if( (kal_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw && UARTPort[port].ownerid==MOD_DHL_READER)||
    (uart_support_autoescape()==KAL_FALSE) )
   {
      if(mode == 0)
	  	ASSERT(0);//real_count = U_PutBytes_VFIFO(port, Buffaddr, Length, ownerid);
        //  real_count = UART_PutBytes(port, Buffaddr, Length, ownerid);
      else
      {
#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
        if (UARTPort[port].sleep_on_tx == uart_sleep_on_tx_forbid) 
        {    
           UART_PDN_Disable(port);           
        }
#endif//#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
	   real_count = DMA_GetVFIFO_Roomleft(ch);
     /* #ifdef VFIFO_DBG
      {
      	char s[50];
      	sprintf(s,"uart_SendData,len %d,left %d",Length,real_count);
      	kal_print(s);
      }
      #endif*/
	 if(UARTPort[port].ownerid != MOD_DHL_READER)// if catcher log via UART,Tx will be too many data 
      drv_trace2(TRACE_GROUP_4,UART_TX_VFIFO_U_SendData_VFIFO,Length,real_count);
      
	   if (real_count > Length)
	   {
	      real_count = Length;
	   }
	   else
	   {
	      send_Txilm[port] = KAL_TRUE;
	      DMA_EnableINT(ch);
	   }
      
         for (index = 0; index < real_count; index++)
         {
	   	   data = *(Buffaddr+index);
	   	
	   	if (data == UARTPort[port].DCB.xonChar)
	   	{   
	   	   savedMask = SaveAndSetIRQMask(); 		     					
      		if(DMA_GetVFIFO_Roomleft(ch)>=2)
	   		{
	   		     DMA_PUSH(ch,escape_char);
	   		     DMA_PUSH(ch,0x01);
	   		}    
      		else
      		{
      			RestoreIRQMask(savedMask);	
      	   	break;
      		}   
         	RestoreIRQMask(savedMask);				
	   		 
	   	}
 	   	else if (data == UARTPort[port].DCB.xoffChar)
	   	{
	   	    savedMask = SaveAndSetIRQMask(); 	
      		if(DMA_GetVFIFO_Roomleft(ch)>=2)
	   		{
	   		     DMA_PUSH(ch,escape_char);
	   		     DMA_PUSH(ch,0x02);
	   		}     
	   		else
      		{
      			RestoreIRQMask(savedMask);	
      	   	break;
      		}  
         	RestoreIRQMask(savedMask);				
      					
	   	}
        		else if (data == escape_char)
	   	{
	   	   savedMask = SaveAndSetIRQMask(); 		     					
	   		if(DMA_GetVFIFO_Roomleft(ch)>=2)
	   		{
	   		     DMA_PUSH(ch,escape_char);
	   		     DMA_PUSH(ch,0x03);
	   		}     
	   		else
      		{
      			RestoreIRQMask(savedMask);				
      	   	break;
      		}  			     
	   		      	RestoreIRQMask(savedMask);				
      
	   	}
	   	 else
	   	 {
	   	   savedMask = SaveAndSetIRQMask(); 		     							 	
			if(DMA_GetVFIFO_Roomleft(ch)>=1)
	   		{
	   	   	DMA_PUSH(ch,data);
	   	   }	
	   		else
      		{
      			RestoreIRQMask(savedMask);	
      	   	break;
      		} 	
      		RestoreIRQMask(savedMask);				
      
	   	 }
	   	
         }
         real_count = index;
      
	   }   
	}
	else
	{
     //real_count = UART_PutBytes(port, Buffaddr, Length, ownerid);
     	ASSERT(0);//real_count = U_PutBytes_VFIFO(port, Buffaddr, Length, ownerid);
   }   

#if defined(DRV_UART_VFIFO_V2)     
	VFIFO_DMA_Flush(port,KAL_FALSE);
#elif defined(DRV_UART_VFIFO_V3)
DMA_Flush(ch);
DMA_Flush(ch);

#endif //defined(DRV_UART_VFIFO_V2)  
	
   /*invoke THRE interrupt*/
   //EnableTxIntr(UART_BaseAddr[port]);
   return real_count;
#else//#ifndef DRV_DEBUG
    return Length;
#endif//#ifndef DRV_DEBUG
}
// toy recommend: do not handle any rx data in UART_RecTimeOutHandler(), otherwise single vfifo will fail
kal_uint16 U_SendISRData_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid)
{
#ifndef DRV_DEBUG
    kal_uint16   real_count,index;
    kal_uint8   data;
    kal_uint8 ch;

   ch = UARTPort[port].Tx_DMA_Ch;
   EXT_ASSERT( (UARTPort[port].ownerid == ownerid), (kal_uint32) ownerid, (kal_uint32)port, (kal_uint32)UARTPort[port].ownerid);
   
   if((UARTPort[port].EnableTX == KAL_FALSE) || (UARTPort[port].power_on == KAL_FALSE))
   {
   	return Length;
   }
            
       if( (kal_query_boot_mode()== FACTORY_BOOT && UARTPort[port].DCB.flowControl==fc_sw && UARTPort[port].ownerid==MOD_DHL_READER)||
       (uart_support_autoescape()==KAL_FALSE) )  
       {
          if(mode == 0)
		real_count = U_PutISRBytes_VFIFO(port, Buffaddr, Length, ownerid);
             // real_count = UART_PutISRBytes(port, Buffaddr, Length, ownerid);
          else
          {
#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
            if (UARTPort[port].sleep_on_tx == uart_sleep_on_tx_forbid)
            { 
               UART_PDN_Disable(port);               
            }
#endif//#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
   	      real_count = DMA_GetVFIFO_Roomleft(ch);
           /* #ifdef VFIFO_DBG
            {
            	char s[50];
            	sprintf(s,"uart_SendData,len %d,left %d",Length,real_count);
            	kal_print(s);
            }
            #endif*/
		 if(UARTPort[port].ownerid != MOD_DHL_READER)// if catcher log via UART,Tx will be too many data	
   			drv_trace2(TRACE_GROUP_4,UART_TX_VFIFO_U_SendISRData_VFIFO,Length,real_count);
   
   	   if (real_count > Length)
   	   {
   	      real_count = Length;
   	   }
   	   else
   	   {
   	      send_Txilm[port] = KAL_TRUE;
   	      DMA_EnableINT(ch);
   	   }
         
         for (index = 0; index < real_count; index++)
         {
   	   	data = *(Buffaddr+index);
   	   	if (data == UARTPort[port].DCB.xonChar)
   	   	{   
   	   		DMA_PUSH(ch,escape_char);
   	   		DMA_PUSH(ch,0x01); 
   	   	}
    	   	else if (data == UARTPort[port].DCB.xoffChar)
   	   	{
   	   	   DMA_PUSH(ch,escape_char);
   	   		DMA_PUSH(ch,0x02);
         
   	   	}
            else if (data == escape_char)
   	   	{
   	   		DMA_PUSH(ch,escape_char);
   	   		DMA_PUSH(ch,0x03);
   	   	}
   	   	else
   	   	{
   	   	   DMA_PUSH(ch,data);		     	   	   
            }
         }   
      }    		    
  	}
  	else
  	{
     // real_count = UART_PutISRBytes(port, Buffaddr, Length, ownerid);
     real_count = U_PutISRBytes_VFIFO(port, Buffaddr, Length, ownerid);
   }    

#if defined(DRV_UART_VFIFO_V2)     
	VFIFO_DMA_Flush(port,KAL_TRUE);
#elif defined(DRV_UART_VFIFO_V3) 
DMA_Flush(ch);
DMA_Flush(ch);
#endif //defined(DRV_UART_VFIFO_V2)  
	
   /*invoke THRE interrupt*/
   //EnableTxIntr(UART_BaseAddr[port]);   
   return real_count;
#else //#ifndef DRV_DEBUG
    return Length;
#endif//#ifndef DRV_DEBUG
}

//because two reason:  ----to add GET_RX_DMA_WRPTR() and GET_RX_DMA_RDPTR() the two function!
// 1:because VFIFO_V1'sWrite point is absolute address,VFIFO_V2 & VFIFO_V3 is relative address
// 2:when VFIFO_V2 & VFIFO_V3,the 16 bit is RX_VFF_WPT_WRA,this bit will be set to 1,when write point wrap.
kal_uint32 GET_RX_DMA_WRPTR(UART_PORT port)
{
	kal_uint32 wp;	
	wp = DMA_WRPTR(UARTPort[port].Rx_DMA_Ch);   
	#if defined(DRV_UART_VFIFO_V2) || defined(DRV_UART_VFIFO_V3)
	 //,because VFIFO_V1'sWrite point is absolute address,VFIFO_V2 & VFIFO_V3 is relative address
	 wp = DRV_UART_Reg(wp);//because the 16 bit is RX_VFF_WPT_WRA,this bit will be set to 1,when write point wrap.
	wp+=(kal_uint32) UART_rings->ring[UARTPort[port].port_no].rx_adrs;
	#else
	 wp = DRV_UART_Reg32(wp);
	#endif
	return wp;
}
kal_uint32 GET_RX_DMA_RDPTR( UART_PORT port)
{
	kal_uint32 rp;
    rp = DMA_RDPTR(UARTPort[port].Rx_DMA_Ch);
	#if defined(DRV_UART_VFIFO_V2) || defined(DRV_UART_VFIFO_V3)
	 //because VFIFO_V1'sWrite point is absolute address,VFIFO_V2 & VFIFO_V3 is relative address
	rp = DRV_UART_Reg(rp);//because the 16 bit is RX_VFF_WPT_WRA,this bit will be set to 1,when write point wrap.
	rp+=(kal_uint32) UART_rings->ring[UARTPort[port].port_no].rx_adrs;
	#else
	rp = DRV_UART_Reg32(rp);
	#endif
	return rp;
}


/************************ISR level**************************************************/
kal_uint32 last_w;
kal_uint32 last_r;
// toy recommend: do not handle any tx data in UART_RecTimeOutHandler(), otherwise single vfifo will fail
void UART_RecTimeOutHandler(UART_PORT port)
{
   UARTStruct *UARTData=&UARTPort[port];
   kal_uint32 UART_BASE;
   kal_uint16 avail;
   kal_uint8 ch;
   SGPT_CTRL_START_T start;
   volatile kal_uint8 tmp=0;
   //kal_bool btmp; //avoid Warning 534: Ignoring return value of function 'GPTI_StartItem"

#if defined(__MTK_INTERNAL__) && !defined(LOW_COST_SUPPORT)


   if(UARTData->port_no >= MAX_UART_PORT_NUM)
      return;
      
   UART_BASE = UART_BaseAddr[UARTData->port_no];
   if(UARTData->port_no == uart_port3)
      UART_DBG(__LINE__, UART_GetTimeStamp(), ust_get_current_time(), 0);
#else
   if(UARTData->port_no >= MAX_UART_PORT_NUM)
      return;
   UART_BASE = UART_BaseAddr[UARTData->port_no];
#endif //#if defined(__MTK_INTERNAL__) && !defined(LOW_COST_SUPPORT)

#ifdef VFIFO_DBG
	gUART_RecTimeOutHandler++;
#endif
#ifdef DCM_ENABLE
   if(UARTData->AutobaudDetection)
   {
      UART_SetRateFix(UARTData->port_no); // if under autobaud detection, set ratefix back and set correct baudrate.
   }
#endif

   // clear the timeout interrupt
   tmp |=0;
 	tmp = DRV_UART_Reg(UART_RXDMA(UART_BASE));

   //check if no incomming data ----for future don't remove it.
   //if(!(DRV_UART_Reg(UART_RXDMA(UART_BASE))&UART_RXDMA_TIMEOUT))
   	//return;

   // inform the upper layer to check virtual fifo remains data
   ch = UARTData->Rx_DMA_Ch;
   avail = DMA_GetVFIFO_Avail(ch);

   drv_trace2(TRACE_GROUP_3,UART_RX_VFIFO_TIMEOUT_INT,port,avail);
   if(avail == 0)
   	return;
   /*TY adds these to expand flexibility 2004/10/15*/
   UARTPort[UARTData->port_no].rx_cb(UARTData->port_no);
   
	DMA_DisableINT(ch);

   if (UARTData->ESCDet.GuardTime != 0)   
   {
   	  //toy mark this, already initial UARTData at function beginning.
      //UARTStruct *UARTData=(UARTStruct *)parameter;
      
      switch(UARTData->Rec_state)
      {
         case UART_Get3EscChar:                        
            UARTData->Rec_state = UART_RecNormal;            
            UARTData->EscCount = 0;
            
            break;
         case UART_RecNormal:
            UARTData->Rec_state = UART_RecNormal;     
            UARTData->EscCount = 0;
            
            break;      
         case UART_StartCheckESC:                                          
            if(avail>3)
            {
               UARTData->Rec_state = UART_RecNormal;            
               UARTData->EscCount = 0;
            }
            else
            {
               kal_uint16 i;
               kal_uint8 data;
               last_w=GET_RX_DMA_WRPTR(port);
               for(i=1;i<(avail+1);i++)
               {                                     
                  last_w--;
                  if( (last_w) <(kal_uint32) UART_rings->ring[UARTData->port_no].rx_adrs )
                     last_w=(kal_uint32)UART_rings->ring[UARTData->port_no].rx_adrs+
                             UART_rings->ring[UARTData->port_no].rx_len-1;                  
                  data=DRV_UART_Reg8((last_w));                                               
                  if(data==UARTData->ESCDet.EscChar)
                  {
                     UARTData->EscCount++;
                     if(UARTData->EscCount == 3)
                     {
                        UARTData->Rec_state = UART_Get3EscChar;
                     }                     
                     else if(UARTData->EscCount > 3)
                     {
                        UARTData->Rec_state = UART_RecNormal;
                        UARTData->EscCount = 0;
                     }                     
                  }   
                  else
                  {
                        
                     UARTData->Rec_state = UART_RecNormal; 
                     UARTData->EscCount = 0;
                  }                                                       
               }                   

            }     
            break;
            default:
            break;
      }           

	  /*
      GPTI_StartItem(UARTData->handle,
                        (UARTData->ESCDet.GuardTime/10),
                        UART_Calback,
                        &UARTPort[UARTData->port_no]);     */
 
	start.u2Tick=UARTData->ESCDet.GuardTime/10;
	start.pfCallback=UART_Calback;
	start.vPara=&UARTPort[UARTData->port_no];
	DclSGPT_Control(UARTData->handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);                  
      
   }  
               

}


// called by DMA ISR while tx fifo is under the threshold

// toy recommend: do not handle any rx data in UART_TrxHandler_VFIFO(), otherwise single vfifo will fail
void UART_TrxHandler_VFIFO(UART_PORT port)
{
   UARTStruct *UARTData=&UARTPort[port];
   kal_int16 room;
   kal_uint8 ch;

   if(UARTData->port_no >= MAX_UART_PORT_NUM)
      return;

#ifdef VFIFO_DBG
	gUART_TrxHandler_VFIFO++;
#endif
	ch = UARTData->Tx_DMA_Ch;
   room = DMA_GetVFIFO_Roomleft(ch);
   if(room == 0)
   	return;
	/* inform the upper layer to send data to vfifo*/
	/*TY adds these to expand flexibility 2004/10/15*/
   UARTPort[UARTData->port_no].tx_cb(UARTData->port_no);
	
   DMA_DisableINT(ch);

}

// called by DMA ISR while rx vfifo is over the threshold
// toy recommend: do not handle any tx data in UART_RecHandler_VFIFO(), otherwise single vfifo will fail
void UART_RecHandler_VFIFO(UART_PORT port)
{
   UARTStruct *UARTData=&UARTPort[port];
   kal_uint16 avail;
   kal_uint8 ch;


   if(UARTData->port_no >= MAX_UART_PORT_NUM)
      return;

#ifdef VFIFO_DBG
	gUART_RecHandler_VFIFO++;
#endif

#ifdef DCM_ENABLE
   if(UARTData->AutobaudDetection)
   {
      UART_SetRateFix(UARTData->port_no); // if under autobaud detection, set ratefix back and set correct baudrate.
   }
#endif
	ch = UARTData->Rx_DMA_Ch;

   avail = DMA_GetVFIFO_Avail(ch);
   drv_trace2(TRACE_GROUP_3,UART_RX_VFIFO_INT,port,avail);  
   if(avail == 0)
   	return;
	// inform the upper layer to get data from vfifo
	/*TY adds these to expand flexibility 2004/10/15*/

   UARTPort[UARTData->port_no].rx_cb(UARTData->port_no);
   
	DMA_DisableINT(ch);
}

// toy recommend: do not handle any rx data in UART_THRE_hdr_VFIFO(), otherwise single vfifo will fail
void UART_THRE_hdr_VFIFO(UART_PORT port)
{
   kal_uint16 avail;
   kal_uint32 UART_BASE;
   if(port >= MAX_UART_PORT_NUM)
      return;
   UART_BASE = UART_BaseAddr[port];
   /*check if there is data in ring buffer*/	
   avail=DMA_GetVFIFO_Avail(UARTPort[port].Tx_DMA_Ch); 	
   if(avail==0)
   {
#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
      UART_PDN_Enable(port);                 
#endif//#if !defined(DRV_MISC_TDMA_PDN0) // For MT6516 MD side do not have pdn
      DisableTxIntr(UART_BASE);
   }
}   

#if !defined(__MEUT__) && !defined(__MEIT__)

void U_configure_DMA_VFIFO(void)
{

#if defined(DRV_UART_VFIFO_V2)
      kal_uint8 i;
#endif 

   #if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
   const kal_uint8 VFIFO_BASE = 11;

   kal_uint8 i;
   kal_uint8 occupyMap = 0;  // uart1 rx --> bit 0; uart3 tx --> bit 5...etc
   kal_uint8 nonVFIFO1 = UART_rings->not_support_VFIFO_TUNNEL1;
   kal_uint8 nonVFIFO2 = UART_rings->not_support_VFIFO_TUNNEL2;
   kal_uint8 tunnel;
   kal_uint8 port;

   for(i=0;i<MAX_UART_TUNNEL_NUM;i++)//initial UART_SINGLE_VFIFO_support[]
      UART_SINGLE_VFIFO_support[i] = KAL_TRUE;
   UART_SINGLE_VFIFO_support[nonVFIFO1] = KAL_FALSE;
   UART_SINGLE_VFIFO_support[nonVFIFO2] = KAL_FALSE;

   
   for(i=0; i<MAX_UART_PORT_NUM; i++)	// assign rx vfifo channel first, for rx has its specific channels.
   {
      tunnel = uart1_rx_tunnel + i*2; // tunnel = uart1_rx_tunnel, uart2_rx_tunnel, uart3_rx_tunnel
      port = uart_port1 + i;               // port = uart1_port, uart2_port, uart3_port

      if( tunnel != nonVFIFO1 && tunnel != nonVFIFO2) // rx tunnel support VFIFO, fill it the specific channel.
      {
   	   UARTPort[port].Rx_DMA_Ch = VFIFO_BASE + i;
   	   occupyMap =  occupyMap | (1 << i);     // record which channel already occupy
      }
   }

   for(i=0; i<MAX_UART_PORT_NUM; i++)	// assign tx vfifo channel according occupy map.
   {
      tunnel = uart1_tx_tunnel + i*2; // tunnel = uart1_tx_tunnel, uart2_tx_tunnel, uart3_tx_tunnel
      port = uart_port1 + i;               // port = uart1_port, uart2_port, uart3_port
      
      if(UART_SINGLE_VFIFO_support[tunnel])
      {
         if(0 == (occupyMap & 0x1)){
            UARTPort[port].Tx_DMA_Ch = VFIFO_BASE ;
            occupyMap |= 0x1;
         }else if(0 == (occupyMap & 0x2)){
            UARTPort[port].Tx_DMA_Ch = VFIFO_BASE + 1;
            occupyMap |= 0x2;
         }else if(0 == (occupyMap & 0x4)){
            UARTPort[port].Tx_DMA_Ch = VFIFO_BASE + 2;
            occupyMap |= 0x4;
         }else if(0 == (occupyMap & 0x8)){
            UARTPort[port].Tx_DMA_Ch = VFIFO_BASE + 3;
            occupyMap |= 0x8;
         }else{
            ASSERT(0); //use more than 4 channels
         }
      }// end of if(UART_SINGLE_VFIFO_support[tunnel])
   }// end of for(i=0; i<3; i++)	// assign tx vfifo channel according occupy map.
   #else //#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)      
   #if defined(DRV_UART_DMA_VFIFO_CONFIG2)
   if(UART_rings->not_support_VFIFO==uart_port1)
   {
      UARTPort[uart_port2].Rx_DMA_Ch=12;
      UARTPort[uart_port2].Tx_DMA_Ch=11;
      #ifdef __UART3_SUPPORT__
      UARTPort[uart_port3].Rx_DMA_Ch=13;
      UARTPort[uart_port3].Tx_DMA_Ch=14;
      #endif
      UART_VFIFO_support[uart_port1]=KAL_FALSE;
   }
   else if(UART_rings->not_support_VFIFO==uart_port2)
   {
      UARTPort[uart_port1].Rx_DMA_Ch=11;
      UARTPort[uart_port1].Tx_DMA_Ch=12;
      #ifdef __UART3_SUPPORT__
      UARTPort[uart_port3].Rx_DMA_Ch=13;
      UARTPort[uart_port3].Tx_DMA_Ch=14;
      #endif
      UART_VFIFO_support[uart_port2]=KAL_FALSE;
   }
   else if(UART_rings->not_support_VFIFO==uart_port3)
   {
      UARTPort[uart_port1].Rx_DMA_Ch=11;
      UARTPort[uart_port1].Tx_DMA_Ch=13;
      UARTPort[uart_port2].Rx_DMA_Ch=12;
      UARTPort[uart_port2].Tx_DMA_Ch=14;
      #ifdef __UART3_SUPPORT__
      UART_VFIFO_support[uart_port3]=KAL_FALSE;
      #endif
   }   
   else
   {
      UART_VFIFO_support[uart_port2]=KAL_FALSE;
      UARTPort[uart_port1].Rx_DMA_Ch=11;
      UARTPort[uart_port1].Tx_DMA_Ch=12;
      #ifdef __UART3_SUPPORT__
      UARTPort[uart_port3].Rx_DMA_Ch=13;
      UARTPort[uart_port3].Tx_DMA_Ch=14;
      #endif
   }    
   #elif defined(DRV_UART_DMA_VFIFO_CONFIG3) //MT6253T
      UARTPort[uart_port1].Rx_DMA_Ch=12;
      UARTPort[uart_port1].Tx_DMA_Ch=15;
      UARTPort[uart_port2].Rx_DMA_Ch=13;
      UARTPort[uart_port2].Tx_DMA_Ch=16;
      #ifdef __UART3_SUPPORT__
      UARTPort[uart_port3].Rx_DMA_Ch=14;
      UARTPort[uart_port3].Tx_DMA_Ch=17;
      #endif
   #elif defined(DRV_UART_DMA_VFIFO_CONFIG4) //MT6268
      UARTPort[uart_port1].Rx_DMA_Ch=11;
      UARTPort[uart_port1].Tx_DMA_Ch=14;
      UARTPort[uart_port2].Rx_DMA_Ch=12;
      UARTPort[uart_port2].Tx_DMA_Ch=15;
      #ifdef __UART3_SUPPORT__
      UARTPort[uart_port3].Rx_DMA_Ch=13;
      UARTPort[uart_port3].Tx_DMA_Ch=16;
      #endif
   #elif defined(DRV_UART_DMA_VFIFO_CONFIG5) //MT6236
      UARTPort[uart_port1].Rx_DMA_Ch=11;
      UARTPort[uart_port1].Tx_DMA_Ch=15;
      UARTPort[uart_port2].Rx_DMA_Ch=12;
      UARTPort[uart_port2].Tx_DMA_Ch=16;
      #ifdef __UART3_SUPPORT__
      UARTPort[uart_port3].Rx_DMA_Ch=13;
      UARTPort[uart_port3].Tx_DMA_Ch=17;
      #endif
   #elif defined(DRV_UART_DMA_VFIFO_CONFIG6) //MT6276
      UARTPort[uart_port1].Rx_DMA_Ch=13;
      UARTPort[uart_port1].Tx_DMA_Ch=12;
      UARTPort[uart_port2].Rx_DMA_Ch=15;
      UARTPort[uart_port2].Tx_DMA_Ch=14;
      #ifdef __UART3_SUPPORT__
      UARTPort[uart_port3].Rx_DMA_Ch=17;
      UARTPort[uart_port3].Tx_DMA_Ch=16;
      #endif
  #elif defined(DRV_UART_DMA_VFIFO_CONFIG9)
      UARTPort[uart_port1].Rx_DMA_Ch=16;
      UARTPort[uart_port1].Tx_DMA_Ch=15;
      UARTPort[uart_port2].Rx_DMA_Ch=18;
      UARTPort[uart_port2].Tx_DMA_Ch=17;
      #ifdef __UART3_SUPPORT__
      UARTPort[uart_port3].Rx_DMA_Ch=20;
      UARTPort[uart_port3].Tx_DMA_Ch=19;
      #endif
    #elif defined(DRV_UART_DMA_VFIFO_CONFIG11) //MT6280
      UARTPort[uart_port1].Rx_DMA_Ch=6;
      UARTPort[uart_port1].Tx_DMA_Ch=5;	  
#elif defined(DRV_UART_DMA_VFIFO_CONFIG12)
      UARTPort[uart_port1].Rx_DMA_Ch=8;
      UARTPort[uart_port1].Tx_DMA_Ch=11;
      UARTPort[uart_port2].Rx_DMA_Ch=9;
      UARTPort[uart_port2].Tx_DMA_Ch=12;
      #ifdef __UART3_SUPPORT__
      UARTPort[uart_port3].Rx_DMA_Ch=10;
      UARTPort[uart_port3].Tx_DMA_Ch=13;
      #endif
   #elif defined(DRV_UART_DMA_VFIFO_CONFIG7) //MT6251
      UARTPort[uart_port1].Rx_DMA_Ch=13;
      UARTPort[uart_port1].Tx_DMA_Ch=15;
      UARTPort[uart_port2].Rx_DMA_Ch=14;
      UARTPort[uart_port2].Tx_DMA_Ch=16;   
   #elif defined(DRV_UART_DMA_VFIFO_CONFIG10) //MT6575
 	  	UARTPort[uart_port1].Rx_DMA_Ch=4;
      UARTPort[uart_port1].Tx_DMA_Ch=3;
      UARTPort[uart_port2].Rx_DMA_Ch=6;
      UARTPort[uart_port2].Tx_DMA_Ch=5; 
 #elif defined(DRV_UART_DMA_VFIFO_CONFIG8) //MT6253EL
      UARTPort[uart_port1].Rx_DMA_Ch=10;
      UARTPort[uart_port1].Tx_DMA_Ch=13;
      UARTPort[uart_port2].Rx_DMA_Ch=11;
      UARTPort[uart_port2].Tx_DMA_Ch=14;
      #ifdef __UART3_SUPPORT__
      UARTPort[uart_port3].Rx_DMA_Ch=12;
      UARTPort[uart_port3].Tx_DMA_Ch=15;
      #endif         	  
   #endif //#if defined(DRV_UART_DMA_VFIFO_CONFIG2)
   #endif //#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
   
#if defined(DRV_UART_VFIFO_V2)
#if defined(DRV_UART_VFIFO_V2_USE_GPT)

	for (i=0;i<MAX_UART_PORT_NUM;i++)
	{
		//GPTI_GetHandle(&UARTPort[i].uart_flush_timer_handle);
		//GPTI_GetHandle(&UARTPort[i].uart_isr_flush_timer_handle);
		UARTPort[i].uart_flush_timer_handle = DclSGPT_Open(DCL_GPT_CB, 0);
		UARTPort[i].uart_isr_flush_timer_handle = DclSGPT_Open(DCL_GPT_CB, 0);
	}

#else

	for (i=0;i<MAX_UART_PORT_NUM;i++)
	{
		UARTPort[i].uart_flush_timer_id=kal_create_timer("UART_Flush_Timer");
	}
	uart_isr_flush_timer_id=kal_create_timer("UART_Flush_Timer");
	uart_isr_hisr_id = kal_create_hisr("UART_ISR_FLUSH_HISR", 1, 512, uart_isr_dma_flush, NULL);

#endif //defined(DRV_UART_VFIFO_V2_USEGPT)
#endif /* defined(DRV_UART_VFIFO_V2) */

}   

#endif //#if !defined(__MEUT__) && !defined(__MEIT__)


#if defined(__MEUT__) || defined(__MEIT__)

#if defined(__UART3_SUPPORT__)
#define UART_VFIFO_3_PORTS
#elif defined(DRV_MD_1_UART)//for MT6280
	#define UART_VFIFO_1_PORTS
#endif //defined(__UART3_SUPPORT__)

#if defined(UART_VFIFO_3_PORTS)
#define UART_VFIFO_PORT_CNT   3
#define UART_VFIFO_CH_CNT   (UART_VFIFO_PORT_CNT*2)

#if defined(DRV_UART_DMA_VFIFO_CONFIG6)
static const kal_uint8  vfifo_ch_num[UART_VFIFO_CH_CNT] = {13, 15, 17, 16, 14, 12};
#endif

#if defined(DRV_UART_DMA_VFIFO_CONFIG3)
static const kal_uint8  vfifo_ch_num[UART_VFIFO_CH_CNT] = {12, 13, 14, 15, 16, 17};
#elif defined(DRV_UART_DMA_VFIFO_CONFIG8) //MT6253EL
static const kal_uint8  vfifo_ch_num[UART_VFIFO_CH_CNT] = {10, 11, 12, 13, 14, 15};
#elif defined(DRV_UART_DMA_VFIFO_CONFIG9)
static const kal_uint8  vfifo_ch_num[UART_VFIFO_CH_CNT] = {16, 18, 20,19,17,15};
#elif defined(DRV_UART_DMA_VFIFO_CONFIG11) //MT6280   MD maybe use AP uart1&uart2
  static const kal_uint8  vfifo_ch_num[UART_VFIFO_CH_CNT] = {6,0,0,0,0,5};
#elif defined(DRV_UART_DMA_VFIFO_CONFIG12)
	   static const kal_uint8 vfifo_ch_num[UART_VFIFO_CH_CNT] = {8,9,10,13,12,11};//{9, 11, 13, 12, 10, 8};

#endif
kal_bool vfifo_used[UART_VFIFO_CH_CNT] = {KAL_FALSE, KAL_FALSE, KAL_FALSE, KAL_FALSE, KAL_FALSE, KAL_FALSE};

#elif defined(UART_VFIFO_1_PORTS)//defined(UART_VFIFO_3_PORTS)
//for MT6280
#define UART_VFIFO_PORT_CNT   1
#define UART_VFIFO_CH_CNT   (UART_VFIFO_PORT_CNT*2)

#if defined(DRV_UART_DMA_VFIFO_CONFIG11) //MT6280
  static const kal_uint8  vfifo_ch_num[UART_VFIFO_CH_CNT] = {6,5};
kal_bool vfifo_used[UART_VFIFO_CH_CNT] = {KAL_FALSE, KAL_FALSE};
#endif

#else //defined(UART_VFIFO_3_PORTS)

#define UART_VFIFO_PORT_CNT   2
#define UART_VFIFO_CH_CNT   (UART_VFIFO_PORT_CNT*2)
kal_bool vfifo_used[UART_VFIFO_CH_CNT] = {KAL_FALSE, KAL_FALSE, KAL_FALSE, KAL_FALSE};

   #if defined(DRV_UART_DMA_VFIFO_CONFIG2)
   static const kal_uint8  vfifo_ch_num[UART_VFIFO_CH_CNT] = {11, 12, 13, 14};
#elif defined(DRV_UART_DMA_VFIFO_CONFIG3)
     static const kal_uint8  vfifo_ch_num[UART_VFIFO_CH_CNT] = {12, 13, 15, 16};
   #elif defined(DRV_UART_DMA_VFIFO_CONFIG5)
   static const kal_uint8  vfifo_ch_num[UART_VFIFO_CH_CNT] = {11, 12, 15, 16};
#elif defined(DRV_UART_DMA_VFIFO_CONFIG6)
   static const kal_uint8  vfifo_ch_num[UART_VFIFO_CH_CNT] = {13, 15, 14, 12};
   #elif defined(DRV_UART_DMA_VFIFO_CONFIG7)
   static const kal_uint8  vfifo_ch_num[UART_VFIFO_CH_CNT] = {13, 14, 15, 16};  
#elif defined(DRV_UART_DMA_VFIFO_CONFIG8) //MT6253EL
   static const kal_uint8  vfifo_ch_num[UART_VFIFO_CH_CNT] = {10, 11, 13, 14}; 
#elif defined(DRV_UART_DMA_VFIFO_CONFIG10)
	static const kal_uint8 vfifo_ch_num[UART_VFIFO_CH_CNT] = {3, 4, 5, 6};
#elif defined(DRV_UART_DMA_VFIFO_CONFIG11) //MT6280  MD maybe use AP uart1  
  static const kal_uint8  vfifo_ch_num[UART_VFIFO_CH_CNT] = {6,0,0,5};
   #endif
//   kal_bool vfifo_used[UART_VFIFO_CH_CNT] = {KAL_FALSE, KAL_FALSE, KAL_FALSE, KAL_FALSE};

#endif//defined(UART_VFIFO_3_PORTS)

static kal_uint8 uart_vfifo_used_cnt = 0;


kal_bool UART_UseVFIFO(UART_PORT port, kal_bool use_vfifo)
{
   ASSERT(port < MAX_UART_PORT_NUM);
   if (port >= MAX_UART_PORT_NUM)
      return KAL_FALSE;
   if (UARTPort[port].initialized &&
   	(UARTPort[port].ownerid != (module_type)((kal_uint16)MOD_UART1_HISR + (kal_uint8)port)))
      return KAL_FALSE;
   if (KAL_TRUE == use_vfifo)
   {
      if (KAL_FALSE == UART_VFIFO_support[port])
      {
         kal_int16  index;
         if (uart_vfifo_used_cnt < UART_VFIFO_PORT_CNT)
         {
            ASSERT(vfifo_used[port] == KAL_FALSE);
            UARTPort[port].Rx_DMA_Ch=vfifo_ch_num[port];
            vfifo_used[port] = KAL_TRUE;

				//liming for VFIFO test
			index = UART_VFIFO_CH_CNT-1-port;
			UARTPort[port].Tx_DMA_Ch = vfifo_ch_num[index];
           vfifo_used[index] = KAL_TRUE;
			
			//liming remove ,for VFIFO test 
         /*  for (index = UART_VFIFO_CH_CNT-1; index >= 0; index--)
            {
               if (index != port)
               {
                  if (KAL_FALSE == vfifo_used[index])
                  {
                     UARTPort[port].Tx_DMA_Ch = vfifo_ch_num[index];
                     vfifo_used[index] = KAL_TRUE;
                     break;
                  }
               }
            }
            ASSERT(index >= 0);*/
            
			   DMA_Vfifo_SetAdrs((kal_uint32)UART_rings->ring[port].rx_adrs, UART_rings->ring[port].rx_len, (DMA_VFIFO_UART)UARTPort[port].Rx_DMA_Ch, KAL_FALSE);
		      DMA_Vfifo_SetAdrs((kal_uint32)UART_rings->ring[port].tx_adrs, UART_rings->ring[port].tx_len, (DMA_VFIFO_UART)UARTPort[port].Tx_DMA_Ch, KAL_TRUE);

			//DMA_Vfifo_SetChan(port);//liming remove!!!   should enable DMA interrupt when U_Putbytes_VFIFO().Becase enable interrupt now,there will be issue a interrupt right away. UDVT test  load maybe fail!!! 
            UART_VFIFO_support[port]=KAL_TRUE;
            uart_vfifo_used_cnt++;
         }
         else
         {
            return KAL_FALSE;
         }
      }
   }
   else 
   {
      if (KAL_TRUE == UART_VFIFO_support[port])
      {
         kal_int16  index;

         UARTPort[port].Rx_DMA_Ch=0xff;
         vfifo_used[port] = KAL_FALSE;

			//liming for VFIFO test
			index = UART_VFIFO_CH_CNT-1-port;
            vfifo_used[index] = KAL_FALSE;

		   
		 /*
         for (index = UART_VFIFO_CH_CNT-1; index >= 0; index--)
         {
            if (index != port)
            {
               if (KAL_TRUE == vfifo_used[index])
               {
                  if (UARTPort[port].Tx_DMA_Ch == vfifo_ch_num[index])
                  {
                     vfifo_used[index] = KAL_FALSE;
                     break;
                  }
               }
            }
         }
         ASSERT(index >= 0);*/
         
         UARTPort[port].Tx_DMA_Ch=0xff;
         UART_VFIFO_support[port]=KAL_FALSE;
         ASSERT(uart_vfifo_used_cnt > 0);
         uart_vfifo_used_cnt--;
      }
   }
   return KAL_TRUE;
}
#else
kal_bool UART_UseVFIFO(UART_PORT port, kal_bool use_vfifo)
{
	return KAL_TRUE;
}
#endif //defined(__MEUT__) || defined(__MEIT__)

#else //#if !defined(DRV_UART_OFF)
void PutUARTData_VFIFO(UART_PORT port, kal_uint8 escape_char, kal_uint8 data){}
void U_configure_DMA_VFIFO(void){}
kal_uint16 U_GetBytes_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid){}
kal_uint16 U_GetBytesAvail_VFIFO(UART_PORT port){}
kal_uint16 U_GetTxISRRoomLeft_VFIFO(UART_PORT port){}
kal_uint16 U_GetTxRoomLeft_VFIFO(UART_PORT port){}
kal_uint8 U_GetUARTByte_VFIFO(UART_PORT port){}
kal_uint8 U_GetUARTByteWithTimeOut_VFIFO(UART_PORT port, kal_uint8* ch, kal_uint32 timeout_value){return 0;}
kal_uint16 U_PutBytes_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid){}
kal_uint16 U_PutISRBytes_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid){}
void U_PutUARTByte_VFIFO(UART_PORT port, kal_uint8 data){}
kal_uint16 U_SendData_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid){}
kal_uint16 U_SendISRData_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid){}
void UART_RecHandler_VFIFO(UART_PORT port){}
void UART_RecTimeOutHandler(UART_PORT port){}
void UART_THRE_hdr_VFIFO(UART_PORT port){}
void UART_TrxHandler_VFIFO(UART_PORT port){}
kal_bool UART_UseVFIFO(UART_PORT port, kal_bool use_vfifo){}
#endif //#if !defined(DRV_UART_OFF)


#if 1
extern kal_bool U_Open(UART_PORT port, module_type owner);
extern void U_Close(UART_PORT port, module_type ownerid);
extern void U_Purge(UART_PORT port, UART_buffer dir, module_type ownerid);
//extern void U_SetOwner (UART_PORT port, kal_uint8 owner);
extern void U_SetOwner (UART_PORT port, module_type owner);
extern void U_SetFlowCtrl(UART_PORT port, kal_bool XON, module_type ownerid);
extern void U_CtrlDCD(UART_PORT port, IO_level SDCD, module_type ownerid);
extern void U_ConfigEscape (UART_PORT port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type ownerid);
extern void U_SetDCBConfig(UART_PORT port, UARTDCBStruct *UART_Config, module_type ownerid);
extern void U_CtrlBreak(UART_PORT port, IO_level SBREAK, module_type ownerid);
extern void U_ClrRxBuffer(UART_PORT port, module_type ownerid);
extern void U_ClrTxBuffer(UART_PORT port, module_type ownerid);
extern void U_SetBaudRate(UART_PORT port, UART_baudrate baudrate, module_type ownerid);
extern module_type U_GetOwnerID(UART_PORT port);
extern void U_SetAutoBaud_Div(UART_PORT port, module_type ownerid);
extern void U_Register_TX_cb(UART_PORT port, module_type owner, UART_TX_FUNC func);
extern void U_Register_RX_cb(UART_PORT port, module_type owner, UART_RX_FUNC func);
extern void U_PutUARTBytes(UART_PORT port, kal_uint8 *data,kal_uint16 len);
extern void U_ReadDCBConfig (UART_PORT port, UARTDCBStruct *DCB);
extern void U_CtrlRI (UART_PORT port, IO_level SRI, module_type ownerid);   /*NULL for DCE*/
extern void U_CtrlDTR (UART_PORT port, IO_level SDTR, module_type ownerid);
extern void U_ReadHWStatus(UART_PORT port, IO_level *SDSR, IO_level *SCTS);
// uart dispatch funtion table

extern kal_uint16 U_GetBytesAvail(UART_PORT port);
extern kal_uint16 U_GetBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid);
extern kal_uint8  U_GetUARTByte(UART_PORT port);

extern kal_uint16 U_PutBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid );
extern kal_uint16 U_GetTxRoomLeft(UART_PORT port);
extern kal_uint16 U_SendISRData(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode, kal_uint8 escape_char, module_type ownerid);
extern kal_uint16 U_SendData(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid);
extern kal_uint16 U_PutISRBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid);
//extern void       U_PutUARTByte(UART_PORT port, kal_uint8 data);

extern kal_uint16 U_GetTxISRRoomLeft(UART_PORT port);

UartDriver_strcut UartDriver_VFIFO=
{
        U_Open,
        U_Close,
        U_GetBytes_VFIFO,
        U_PutBytes_VFIFO,
        U_GetBytesAvail_VFIFO,
        U_GetTxRoomLeft_VFIFO,
        U_PutISRBytes_VFIFO,
        U_GetTxISRRoomLeft_VFIFO, 
        U_Purge,
        U_SetOwner,
        U_SetFlowCtrl,
        U_ConfigEscape,
        U_SetDCBConfig,
        U_CtrlDCD,
        U_CtrlBreak, 
        U_ClrRxBuffer,
        U_ClrTxBuffer,
        U_SetBaudRate,
        U_SendISRData_VFIFO,
        U_SendData_VFIFO,
        U_GetOwnerID,
        U_SetAutoBaud_Div,
        /*TY adds these to expand flexibility 2004/10/15*/
        U_Register_TX_cb,        
        U_Register_RX_cb,
        /*TY adds these to let virtual COM port can retrive exception log 2005/3/8*/
        U_GetUARTByte_VFIFO,
        U_PutUARTByte_VFIFO,
        U_PutUARTBytes,
        /*for virtual com port to return DCB configuration*/
        U_ReadDCBConfig,
        U_CtrlRI,
        U_CtrlDTR,
        U_ReadHWStatus,
        U_GetUARTByteWithTimeOut_VFIFO,   
};

UartDriver_strcut UartDriver_VFIFO_TX=
{
        U_Open,                                                                          
        U_Close,                                                                         
        U_GetBytes,                                                                      
        U_PutBytes_VFIFO,                                                                
        U_GetBytesAvail,                                                                 
        U_GetTxRoomLeft_VFIFO,                                                           
        U_PutISRBytes_VFIFO,                                                             
        U_GetTxISRRoomLeft_VFIFO,                                                        
        U_Purge,                                                                         
        U_SetOwner,                                                                      
        U_SetFlowCtrl,                                                                   
        U_ConfigEscape,                                                                  
        U_SetDCBConfig,                                                                  
        U_CtrlDCD,                                                                       
        U_CtrlBreak,                                                                     
        U_ClrRxBuffer,                                                                   
        U_ClrTxBuffer,                                                                   
        U_SetBaudRate,                                                                   
        U_SendISRData_VFIFO,                                                             
        U_SendData_VFIFO,                                                                
        U_GetOwnerID,                                                                    
        U_SetAutoBaud_Div,                                                               
        /*TY adds these to expand flexibility 2004/10/15*/                               
        U_Register_TX_cb,                                                                
        U_Register_RX_cb,                                                                
        /*TY adds these to let virtual COM port can retrive exception log 2005/3/8*/     
        U_GetUARTByte,                                                                   
        U_PutUARTByte_VFIFO,                                                             
        U_PutUARTBytes,                                                                  
        /*for virtual com port to return DCB configuration*/                             
        U_ReadDCBConfig,                                                                 
        U_CtrlRI,                                                                        
        U_CtrlDTR,                                                                       
        U_ReadHWStatus                                                                   
};

UartDriver_strcut UartDriver_VFIFO_RX=
{
        U_Open,
        U_Close,
        U_GetBytes_VFIFO,
        U_PutBytes,
        U_GetBytesAvail_VFIFO,
        U_GetTxRoomLeft,
        U_PutISRBytes,
        U_GetTxISRRoomLeft,
        U_Purge,
        U_SetOwner,
        U_SetFlowCtrl,
        U_ConfigEscape,
        U_SetDCBConfig,
        U_CtrlDCD,
        U_CtrlBreak, 
        U_ClrRxBuffer,
        U_ClrTxBuffer,
        U_SetBaudRate,
        U_SendISRData,
        U_SendData,
        U_GetOwnerID,
        U_SetAutoBaud_Div,
        /*TY adds these to expand flexibility 2004/10/15*/
        U_Register_TX_cb,        
        U_Register_RX_cb,
        /*TY adds these to let virtual COM port can retrive exception log 2005/3/8*/
        U_GetUARTByte_VFIFO,
        U_PutUARTByte,
        U_PutUARTBytes,
        /*for virtual com port to return DCB configuration*/
        U_ReadDCBConfig,
        U_CtrlRI,
        U_CtrlDTR,
        U_ReadHWStatus         
};

#endif
#endif //__DMA_UART_VIRTUAL_FIFO__



