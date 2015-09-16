/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dcl_uart.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for UART.
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
 * removed!
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __UART_INTERNAL_H__
#define __UART_INTERNAL_H__

#include "uart_sw.h"
#include "dcl.h"

#include "kal_general_types.h"
#include "drv_comm.h"
//#include "btif_sw.h"

typedef enum {
      UART_ON_VFIFO,
      UART_ON_DMA,
      UART_ON_MCU,
      UART_ON_UNKNOWN
} UART_WORKING_MODE;

#define  UART_STAT_EscDet        0x01
#define  UART_STAT_Break         0x02

#define  UART_RecNormal          0
#define  UART_Get3EscChar        1
#define  UART_StartCheckESC      2

//Size = 8bit, sinc en, dinc disable, hw management, 
//1 trans/dma cycle, UART1 master,Interrupt enable
#define DMA_CON_UART1TxNormal 0x8034
//Size = 8bit, sinc disable, dinc enable, hw management, 
//1 trans/dma cycle, UART1 master,Interrupt enable
#define DMA_CON_UART1RxNormal 0x8038
//Size = 8bit, sinc en, dinc disable, hw management, 
//1 trans/dma cycle, UART2 master,Interrupt enable
#define DMA_CON_UART2TxNormal 0x8054
//Size = 8bit, sinc disable, dinc enable, hw management, 
//1 trans/dma cycle, UART2 master,Interrupt enable
#define DMA_CON_UART2RxNormal 0x8058



/*TY adds these to expand flexibility 2004/10/15*/
typedef void (*UART_TX_FUNC)(UART_PORT port); 
typedef void (*UART_RX_FUNC)(UART_PORT port) ; 


typedef struct
{
      UART_PORT                      port_no;
      kal_bool                       initialized;
      kal_bool                       power_on;
      module_type                    ownerid;
      module_type                    UART_id;
      kal_bool                       breakDet;
      kal_bool                       EscFound;
      UARTDCBStruct                  DCB;
      UART_RingBufferStruct          RingBuffers;
      UART_ESCDetectStruct           ESCDet;
      BUFFER_INFO                    Tx_Buffer_ISR; /* receive buffer */
      BUFFER_INFO                    Rx_Buffer;  /* receive buffer */
      BUFFER_INFO                    Tx_Buffer;  /* transmit buffer */
      kal_hisrid                     hisr;
      IO_level                       DSR;
      /*detect Escape*/
      DCL_HANDLE                      handle;    /*GPT handle*/
#ifdef DCM_ENABLE
// UART_BAUD_AUTO conflict with rate fix, need to disable DCM
      kal_uint8                      DCMHandle; 
      kal_bool                       AutobaudDetection;
#endif
#if defined(DRV_UART_COMPENSATE_AT)
      UART_Compensate_enum           CompensateAT;
#endif
      kal_uint8                      EscCount;
      kal_uint8                      Rec_state; /**/
      UART_SLEEP_ON_TX               sleep_on_tx;
      kal_bool               		EnableTX;
      /*TY adds these to expand flexibility 2004/10/15*/
      UART_TX_FUNC                  tx_cb;
      UART_RX_FUNC                  rx_cb;
      //#ifdef __DMA_UART_VIRTUAL_FIFO__
		kal_uint8 							Rx_DMA_Ch;
		kal_uint8 							Tx_DMA_Ch;
      //#endif
      
#if defined(DRV_UART_VFIFO_V2)
#if defined(DRV_UART_VFIFO_V2_USE_GPT)
	DCL_HANDLE uart_flush_timer_handle;    /*GPT handle*/
	DCL_HANDLE uart_isr_flush_timer_handle;    /*GPT handle*/
#else
	kal_timerid   uart_flush_timer_id;
#endif //DRV_UART_VFIFO_V2_USE_GPT
#endif /* defined(DRV_UART_VFIFO_V1) */
	  
} UARTStruct;

// for uart dispatch table 
typedef enum
{
	UART_TYPE = 0,
	IRDA_TYPE,
	USB_TYPE,
	BLUETOOTH_TYPE,
	CMUX_TYPE
}UartType_enum;

typedef struct _uartdriver
{
	
	kal_bool (*Open)(UART_PORT port, module_type ownerid);
	void (*Close)(UART_PORT port, module_type ownerid);
	kal_uint16 (*GetBytes)(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid);
	kal_uint16 (*PutBytes)(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid);
	kal_uint16 (*GetRxAvail)(UART_PORT port);
	kal_uint16 (*GetTxAvail)(UART_PORT port);
	kal_uint16 (*PutISRBytes)(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid);
	kal_uint16 (*GetISRTxAvail)(UART_PORT port);
	void (*Purge)(UART_PORT port, UART_buffer dir, module_type ownerid);	
	//void (*SetOwner)(UART_PORT port, kal_uint8 ownerid);
	void (*SetOwner)(UART_PORT port, module_type ownerid);
	void (*SetFlowCtrl)(UART_PORT port, kal_bool XON, module_type ownerid);
	void (*ConfigEscape)(UART_PORT port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type ownerid);
	void (*SetDCBConfig)(UART_PORT port, UARTDCBStruct *UART_Config, module_type ownerid);
	void (*CtrlDCD)(UART_PORT port, IO_level SDCD, module_type ownerid);
	void (*CtrlBreak)(UART_PORT port, IO_level SBREAK, module_type ownerid);
	void (*ClrRxBuffer)(UART_PORT port, module_type ownerid);
	void (*ClrTxBuffer)(UART_PORT port, module_type ownerid);	
	void (*SetBaudRate)(UART_PORT port, UART_baudrate baudrate, module_type ownerid);	
	kal_uint16 (*SendISRData)(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode, kal_uint8 escape_char, module_type ownerid);
	kal_uint16 (*SendData)(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid);
	module_type (*GetOwnerID)(UART_PORT port);	
	void (*SetAutoBaud_Div)(UART_PORT port, module_type ownerid);			
	/*TY adds these to expand flexibility 2004/10/15*/
	void (*UART_Register_TX_cb)(UART_PORT port, module_type ownerid, UART_TX_FUNC func);
	void (*UART_Register_RX_cb)(UART_PORT port, module_type ownerid, UART_RX_FUNC func);	
	/*TY adds these to let virtual COM port can retrive exception log 2005/3/8*/
	kal_uint8 (*GetUARTByte)(UART_PORT port);	
	void (*PutUARTByte)(UART_PORT port, kal_uint8 data);	
	void (*PutUARTBytes)(UART_PORT port, kal_uint8 *data, kal_uint16 len);		
	/*for virtual com port to return DCB configuration*/
	void (*ReadDCBConfig)(UART_PORT port, UARTDCBStruct *UART_Config);	
	void (*CtrlRI)(UART_PORT port, IO_level SRI, module_type ownerid);	
	void (*CtrlDTR)(UART_PORT port, IO_level SDTR, module_type ownerid);	
	void (*ReadHWStatus)(UART_PORT port, IO_level *SDSR, IO_level *SCTS);	
	kal_uint8 (*GetUARTByte_WithTimeOut)(UART_PORT port, kal_uint8* ch, kal_uint32 timeout_value);	
}UartDriver_strcut;

/*Function Declaration*/
extern UartDriver_strcut UartDriver;	

#if defined(__DMA_UART_VFIFO_SINGLE_TUNNEL__)
extern kal_bool UART_SINGLE_VFIFO_support[MAX_UART_TUNNEL_NUM] ; //toy add for single tunnel vfifo
extern kal_bool UART_IsVfifoSetting(UART_PORT port, UART_TxRx_VFIFO_support vs);
#ifdef __DMA_UART_VIRTUAL_FIFO__	
extern UartDriver_strcut UartDriver_VFIFO;
extern UartDriver_strcut UartDriver_VFIFO_RX;
extern UartDriver_strcut UartDriver_VFIFO_TX;
#endif
#else
extern kal_bool UART_VFIFO_support[MAX_UART_PORT_NUM];
#ifdef __DMA_UART_VIRTUAL_FIFO__	
extern UartDriver_strcut UartDriver_VFIFO;
#endif
#endif

extern UartDriver_strcut* pUart_CMD_FUNC[];


#ifdef DCM_ENABLE
extern void UART_SetRateFix(UART_PORT  port);
#endif
#if defined(DRV_UART_COMPENSATE_AT)
extern void UART_CompensateAT(UART_PORT  port);
extern void UART_CheckAT_Callback(void *parameter);
#endif //#if defined(DRV_UART_COMPENSATE_AT)

extern void UART1_PDN_ENABLE(void);
extern void UART1_PDN_DISABLE(void);
extern void UART2_PDN_ENABLE(void);
extern void UART2_PDN_DISABLE(void);
#ifdef __UART3_SUPPORT__
extern void UART3_PDN_ENABLE(void);
extern void UART3_PDN_DISABLE(void);
#endif //#ifdef __UART3_SUPPORT__

/*ISR handler for VFIFO*/
extern void UART_RecTimeOutHandler(UART_PORT port);
extern void UART_TrxHandler_VFIFO(UART_PORT port);
extern void UART_RecHandler_VFIFO(UART_PORT port);
extern void UART_THRE_hdr_VFIFO(UART_PORT port);
/*API for VFIFO*/
extern void U_configure_DMA_VFIFO(void);
extern kal_uint16 U_GetTxISRRoomLeft_VFIFO(UART_PORT port);
extern kal_uint16 U_GetTxRoomLeft_VFIFO(UART_PORT port);
extern kal_uint16 U_GetBytesAvail_VFIFO(UART_PORT port);
extern kal_uint8 U_GetUARTByte_VFIFO(UART_PORT port);
extern void U_PutUARTByte_VFIFO(UART_PORT port, kal_uint8 data);
extern void PutUARTData_VFIFO(UART_PORT port, kal_uint8 escape_char, kal_uint8 data);
extern kal_uint16 U_GetBytes_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid);
extern kal_uint16 U_PutBytes_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid);
extern kal_uint16 U_PutISRBytes_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid);
extern kal_uint16 U_SendData_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid);
extern kal_uint16 U_SendISRData_VFIFO(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid);
extern kal_bool UART_UseVFIFO(UART_PORT port, kal_bool use_vfifo);

extern void UART_DriverInit(UART_PORT port,kal_uint32 flag);
extern void UART_Boot_Trace_Release(kal_bool flag);//for bootup trace

extern void UART_set_FIFO_trigger(UART_PORT port, kal_uint16 tx_level, kal_uint16 rx_level);

#ifdef __UART3_SUPPORT__
   extern void UART3_HISR(void);
   extern void UART3_LISR(void);
#endif   /*MT6218*/
// for Uart Dispatch
//extern void UART_Register(UART_PORT port, UartType_enum type, UartDriver_strcut* drv);

/* Note: for ROM code start */
#ifdef __ROMSA_SUPPORT__
/*for mcu rom*/
extern kal_uint16 U_GetTxISRRoomLeft(UART_PORT port);
extern kal_uint16 U_PutISRBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid);
extern kal_uint16 U_ROM_GetTxISRRoomLeft(UART_PORT port);
extern UARTStruct *U_ROM_GetUARTPort(UART_PORT port);
extern kal_uint8 *U_ROM_GetUART_TXilm(UART_PORT port);
extern void U_ROM_InformUARTOwner(UART_PORT port);
extern void U_ROM_PushDataToBuf(UART_PORT port, kal_uint8 *data, kal_uint32 real_count);
extern void U_ROM_EnableTxIntr(UART_PORT port);
//extern void DRVPDN_Disable(kal_uint32 addr,kal_uint16 code,kal_uint8 handle);
#endif
/* Note: for ROM code end */

// Used under ASSERT condition
// This has effect only when the port does NOT support VFIFO and used as Catcher port
extern void UART_AssertWaitPrevDataSentOut(UART_PORT port);


extern kal_bool UART1DMA_Ini(kal_bool Tx);
extern kal_bool UART2DMA_Ini(kal_bool Tx);
extern kal_uint8 GetUARTByte(UART_PORT port);
extern void PutUARTByte(UART_PORT port, kal_uint8 data);
extern void UART_SetBaudRate(UART_PORT port, UART_baudrate baud_rate, module_type ownerid);
extern void UART_SetDCBConfig(UART_PORT port, UARTDCBStruct *UART_Config, module_type ownerid);
extern void UART_ReadDCBConfig (UART_PORT port, UARTDCBStruct *DCB);
extern void UART_loopback(UART_PORT port);
extern void UART_HWInit(UART_PORT port);
extern kal_bool UART_Open(UART_PORT port, module_type ownerid);
extern void UART_Close(UART_PORT port, module_type ownerid);
//extern void UART_SetOwner (UART_PORT port, kal_uint8 ownerid);
extern void UART_SetOwner (UART_PORT port, module_type ownerid);
extern void UART_ConfigEscape (UART_PORT port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type ownerid);
extern void UART_CtrlDTR (UART_PORT port, IO_level SDTR, module_type ownerid);
extern void UART_ReadHWStatus(UART_PORT port, IO_level *SDSR, IO_level *SCTS);
extern void UART_CtrlBreak(UART_PORT port, IO_level SBREAK, module_type ownerid);
extern void UART_Purge(UART_PORT port, UART_buffer dir, module_type ownerid);
extern void UART_Register_RX_cb(UART_PORT port, module_type ownerid, UART_RX_FUNC func);
extern void UART_Register_TX_cb(UART_PORT port, module_type ownerid, UART_TX_FUNC func);
extern void UART_PDN_Disable(UART_PORT port);
extern void UART_PDN_Enable(UART_PORT port);


//API for single tunnel VFIFO
extern kal_uint16 U_GetBytesAvail(UART_PORT port);
extern kal_uint16 U_GetBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid);
extern kal_uint8  U_GetUARTByte(UART_PORT port);
extern kal_uint16 U_PutBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid );
extern kal_uint16 U_GetTxRoomLeft(UART_PORT port);
extern kal_uint16 U_SendISRData(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode, kal_uint8 escape_char, module_type ownerid);
extern kal_uint16 U_SendData(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid);
extern void       U_PutUARTByte(UART_PORT port, kal_uint8 data);

extern void UART_Boot_PutUARTBytes(UART_PORT port, kal_uint8 *data,kal_uint16 len);
extern void UART_Bootup_Init(void);
extern kal_uint16 UART_GetBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, kal_uint8 *status, module_type ownerid);
extern kal_uint16 UART_PutBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid);
extern kal_uint16 UART_PutISRBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length, module_type ownerid);
extern kal_uint16 UART_SendISRData(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode, kal_uint8 escape_char, module_type ownerid);
extern kal_uint16 UART_SendData(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length,kal_uint8 mode,kal_uint8 escape_char, module_type ownerid );
extern void UART_SetFlowCtrl(UART_PORT port, kal_bool XON, module_type ownerid);
extern void UART_CtrlDCD(UART_PORT port, IO_level SDCD, module_type ownerid);
extern void UART_CtrlRI (UART_PORT port, IO_level SRI, module_type ownerid);
extern kal_uint16 UART_GetBytesAvail(UART_PORT port);
extern void UART_SleepOnTx_Enable(UART_PORT port, UART_SLEEP_ON_TX enable_flag);
extern void UART_SetSleepEnable(kal_bool enable);
extern void UART_SwitchPort(UART_PORT *APP_port, UART_PORT new_uart_port);
extern void UART_dafault_tx_cb(UART_PORT port);
extern void UART_dafault_rx_cb(UART_PORT port);
extern void UART_TurnOnPower(UART_PORT port, kal_bool enable);
extern kal_bool UART_CheckTxBufferEmpty(UART_PORT port);
extern kal_bool UART_CheckTxAllSentOut(UART_PORT port);
extern void UART_GetTxBufferSize(UART_PORT port, kal_uint32 *total_size, kal_uint32 *rest_size);
extern void UART1_HISR(void);
extern void UART2_HISR(void);
extern void UART1_LISR(void);
extern void UART2_LISR(void);
extern kal_bool uart_support_autoescape(void);
extern void UART_VFIFO_TX_DMA_Enable(UART_PORT port,kal_bool enable);
extern void UART_dsp_dafault_rx_cb(UART_PORT port);
extern void UART_dsp_dafault_tx_cb(UART_PORT port);
extern kal_uint32 UART_Get_Maxbaudrate(UART_PORT port);



/*end of local parameter struct */
#define EnableRxIntr(_baseaddr)   \
{\
      kal_uint32 _savedMask;\
      kal_uint16 _IER;\
      _savedMask = SaveAndSetIRQMask();\
      _IER = DRV_Reg(UART_IER(_baseaddr));\
      _IER |= (UART_IER_ERBFI | UART_IER_ELSI);\
      DRV_WriteReg(UART_IER(_baseaddr),_IER);\
      RestoreIRQMask(_savedMask);\
}

#define DisableRxIntr(_baseaddr)   \
{\
   kal_uint16 _IER;\
   kal_uint32 _savedMask;\
   _savedMask = SaveAndSetIRQMask();\
   _IER = DRV_Reg(UART_IER(_baseaddr));\
   _IER &= ~(UART_IER_ERBFI|UART_IER_ELSI);\
   DRV_WriteReg(UART_IER(_baseaddr),_IER);\
   RestoreIRQMask(_savedMask);\
}


#define EnableTxIntr(_baseaddr)   \
{\
   kal_uint16 _IER;\
   kal_uint32 _savedMask;\
   _savedMask = SaveAndSetIRQMask();\
   _IER = DRV_Reg(UART_IER(_baseaddr));\
   _IER |= UART_IER_ETBEI;\
   DRV_WriteReg(UART_IER(_baseaddr),_IER);\
   RestoreIRQMask(_savedMask);\
}

#define DisableTxIntr(_baseaddr)   \
{\
   kal_uint16 _IER;\
   kal_uint32 _savedMask;\
   _savedMask = SaveAndSetIRQMask();\
   _IER = DRV_Reg(UART_IER(_baseaddr));\
   _IER &= ~UART_IER_ETBEI;\
   DRV_WriteReg(UART_IER(_baseaddr),_IER);\
   RestoreIRQMask(_savedMask);\
}

#define UART_SetDMAIntr(_baseaddr) \
{\
   kal_uint16 _IER;\
   kal_uint32 _savedMask;\
   _savedMask = SaveAndSetIRQMask();\
   _IER = DRV_Reg(UART_IER(_baseaddr));\
   _IER &= ~(UART_IER_ETBEI);\
   DRV_WriteReg(UART_IER(_baseaddr),_IER);\
   RestoreIRQMask(_savedMask);\
}

#define DisableRLSIntr(_baseaddr)   \
{\
   kal_uint16 _IER;\
   kal_uint32 _savedMask;\
   _savedMask = SaveAndSetIRQMask();\
   _IER = DRV_Reg(UART_IER(_baseaddr));\
   _IER &= ~(UART_IER_ELSI);\
   DRV_WriteReg(UART_IER(_baseaddr),_IER);\
   RestoreIRQMask(_savedMask);\
}


extern UART_WORKING_MODE UART_GetTxWorkingMode(UART_PORT port);

#if defined(__MTK_INTERNAL__) && !defined(LOW_COST_SUPPORT) && !defined(__MAUI_BASIC__) && defined(__DRV_DBG_MEMORY_TRACE_SUPPORT__)
#define DRV_UART_MEMORY_TRACE
typedef struct{
   kal_uint16      tag;
   kal_uint32      time;
   kal_uint32      data1;
   kal_uint32      data2;
}UART_DRV_DBG_DATA;
#define MAX_UART_DRV_DBG_INFO_SIZE 512
typedef struct{
   UART_DRV_DBG_DATA   dbg_data[MAX_UART_DRV_DBG_INFO_SIZE];
   kal_uint16          dbg_data_idx;
}UART_DRV_DBG_STRUCT;
extern void uart_drv_dbg_trace(kal_uint16 index, kal_uint32 time, kal_uint32 data1, kal_uint32 data2);
#define UART_DBG(a,b,c,d) uart_drv_dbg_trace(a,b,c,d);
#include "us_timer.h"
extern kal_uint32 L1I_GetTimeStamp(void);
#define UART_GetTimeStamp L1I_GetTimeStamp
#else //#if defined(__MTK_INTERNAL__) && !defined(LOW_COST_SUPPORT)
#define UART_DBG(a,b,c,d) ;
#endif //#if defined(__MTK_INTERNAL__) && !defined(LOW_COST_SUPPORT)


#if defined(__SSDVT_TEST__)     /*  add for SSDVT , make sure that UART init Value is satisfied for DVT's need  */
#define DRV_UART_WriteReg(addr,data)
#define DRV_UART_Reg(addr)                        DRV_Reg(addr)                      
#define DRV_UART_WriteReg32(addr,data)
#define DRV_UART_Reg32(addr)                      DRV_Reg32(addr)                    
#define DRV_UART_WriteReg8(addr,data)
#define DRV_UART_Reg8(addr)                       DRV_Reg8(addr)                     
#define DRV_UART_ClearBits(addr,data)
#define DRV_UART_SetBits(addr,data)
#define DRV_UART_SetData(addr, bitmask, value)
#define DRV_UART_ClearBits32(addr,data)
#define DRV_UART_SetBits32(addr,data)
#define DRV_UART_SetData32(addr, bitmask, value)
#define DRV_UART_ClearBits8(addr,data)
#define DRV_UART_SetBits8(addr,data)
#define DRV_UART_SetData8(addr, bitmask, value)
#elif defined(__DRV_COMM_REG_DBG__) && defined(__DRV_UART_REG_DBG__)  /*normal case */
#define DRV_UART_WriteReg(addr,data)              DRV_DBG_WriteReg(addr,data)
#define DRV_UART_Reg(addr)                        DRV_DBG_Reg(addr)                      
#define DRV_UART_WriteReg32(addr,data)            DRV_DBG_WriteReg32(addr,data)          
#define DRV_UART_Reg32(addr)                      DRV_DBG_Reg32(addr)                    
#define DRV_UART_WriteReg8(addr,data)             DRV_DBG_WriteReg8(addr,data)           
#define DRV_UART_Reg8(addr)                       DRV_DBG_Reg8(addr)                     
#define DRV_UART_ClearBits(addr,data)             DRV_DBG_ClearBits(addr,data)           
#define DRV_UART_SetBits(addr,data)               DRV_DBG_SetBits(addr,data)             
#define DRV_UART_SetData(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)  
#define DRV_UART_ClearBits32(addr,data)           DRV_DBG_ClearBits32(addr,data)         
#define DRV_UART_SetBits32(addr,data)             DRV_DBG_SetBits32(addr,data)           
#define DRV_UART_SetData32(addr, bitmask, value)  DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_UART_ClearBits8(addr,data)            DRV_DBG_ClearBits8(addr,data)          
#define DRV_UART_SetBits8(addr,data)              DRV_DBG_SetBits8(addr,data)            
#define DRV_UART_SetData8(addr, bitmask, value)   DRV_DBG_SetData8(addr, bitmask, value) 
#else
#define DRV_UART_WriteReg(addr,data)              DRV_WriteReg(addr,data)
#define DRV_UART_Reg(addr)                        DRV_Reg(addr)                      
#define DRV_UART_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)          
#define DRV_UART_Reg32(addr)                      DRV_Reg32(addr)                    
#define DRV_UART_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)           
#define DRV_UART_Reg8(addr)                       DRV_Reg8(addr)                     
#define DRV_UART_ClearBits(addr,data)             DRV_ClearBits(addr,data)           
#define DRV_UART_SetBits(addr,data)               DRV_SetBits(addr,data)             
#define DRV_UART_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)  
#define DRV_UART_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)         
#define DRV_UART_SetBits32(addr,data)             DRV_SetBits32(addr,data)           
#define DRV_UART_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
#define DRV_UART_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)          
#define DRV_UART_SetBits8(addr,data)              DRV_SetBits8(addr,data)            
#define DRV_UART_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value) 
#endif //#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_UART_REG_DBG__)


#endif

