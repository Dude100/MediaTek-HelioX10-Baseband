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
 ****************************************************************************/
#ifndef __UART_INTERNAL_H__
#define __UART_INTERNAL_H__

#include "uart_sw.h"
#include "dcl.h"

#include "kal_general_types.h"
#include "drv_comm.h"

#include "qmu_bm.h"
#include "qmu_bm_size.h"
#include "qmu_bm_util.h"

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

#define UART1_HDMA_TX_CHANNEL		4
#define UART1_HDMA_RX_CHANNEL		6
#define UART2_HDMA_TX_CHANNEL		5
#define UART2_HDMA_RX_CHANNEL		7
#define UART3_HDMA_TX_CHANNEL		4
#define UART3_HDMA_RX_CHANNEL		6

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
      kal_uint8                      EscCount;
      kal_uint8                      Rec_state; /**/
      UART_SLEEP_ON_TX               sleep_on_tx;
      kal_bool               		EnableTX;
      /*TY adds these to expand flexibility 2004/10/15*/
      UART_TX_FUNC                  tx_cb;
      UART_RX_FUNC                  rx_cb;
      //#ifdef __DMA_UART_VIRTUAL_FIFO__
	kal_uint8 			Rx_DMA_Ch;
	kal_uint8 			Tx_DMA_Ch;
      //#endif
      
#if defined(DRV_UART_VFIFO_V2)
#if defined(DRV_UART_VFIFO_V2_USE_GPT)
	DCL_HANDLE uart_flush_timer_handle;    /*GPT handle*/
	DCL_HANDLE uart_isr_flush_timer_handle;    /*GPT handle*/
#else
	kal_timerid   uart_flush_timer_id;
#endif //DRV_UART_VFIFO_V2_USE_GPT
#endif /* defined(DRV_UART_VFIFO_V1) */


	// added by ansel for new TTY API
	kal_bool		need_tx_done_cb;
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


extern kal_bool UART_VFIFO_support[MAX_UART_PORT_NUM];
#ifdef __DMA_UART_VIRTUAL_FIFO__	
extern UartDriver_strcut UartDriver_VFIFO;
#endif

extern UartDriver_strcut* pUart_CMD_FUNC[];


#ifdef DCM_ENABLE
extern void UART_SetRateFix(UART_PORT  port);
#endif

extern void UART1_PDN_ENABLE(void);
extern void UART1_PDN_DISABLE(void);
extern void UART2_PDN_ENABLE(void);
extern void UART2_PDN_DISABLE(void);

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

extern void UART_DriverInit(UART_PORT port);
extern void UART_set_FIFO_trigger(UART_PORT port, kal_uint16 tx_level, kal_uint16 rx_level);

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
extern void UART_SetSleepEnable(UART_PORT port, kal_bool enable);
extern void UART_SwitchPort(UART_PORT *APP_port, UART_PORT new_uart_port);
extern void UART_dafault_tx_cb(UART_PORT port);
extern void UART_dafault_rx_cb(UART_PORT port);
extern void UART_TurnOnPower(UART_PORT port, kal_bool enable);
extern kal_bool UART_CheckTxBufferEmpty(UART_PORT port);
extern kal_bool UART_CheckTxAllSentOut(UART_PORT port);
extern void UART_GetTxBufferSize(UART_PORT port, kal_uint32 *total_size, kal_uint32 *rest_size);
extern void UART1_HISR(void);
extern void UART2_HISR(void);
extern void UART3_HISR(void);
extern void UART1_LISR(kal_uint32 vector);
extern void UART2_LISR(kal_uint32 vector);
extern void UART3_LISR(kal_uint32 vector);
extern void uart_hdma_isr(void);
extern void uart_hdma_hisr(void);
extern kal_bool uart_support_autoescape(void);
void UART_VFIFO_TX_DMA_Enable(UART_PORT port,kal_bool enable);
void UART_dsp_dafault_rx_cb(UART_PORT port);
void UART_dsp_dafault_tx_cb(UART_PORT port);
kal_uint16 BMT_PutBytes(UART_PORT port, kal_uint8 *Buffaddr, kal_uint16 Length);
kal_uint32 UART_Get_Maxbaudrate(UART_PORT port);

kal_uint32 UART_PutBytesIor(UART_PORT port, void *putIor);
kal_uint32 UART_PutBytesIor_LIGHT(UART_PORT port, void *putIor);
kal_uint32 UART_GetBytesIor(UART_PORT port, void *ior);
void UART_SetNeedTxDoneCb(UART_PORT port, kal_bool needTxDoneCb, module_type ownerid);

kal_uint32 U_GetFlowCtrl(UART_PORT port, module_type ownerid);
kal_uint32 uart_cal_tgpd_buf_length(void *head, void *tail);
void uart_en_q_de_q_with_mutex(UART_PORT port, kal_bool tx_or_rx, kal_bool en_q_or_de_q, void *p_ior_head, void *p_ior_tail);
DCL_STATUS uart_en_q_de_q_for_ecpt(UART_PORT port, kal_bool tx_or_rx, kal_uint8 en_q_or_de_q, void **p_ior_head, void **p_ior_tail, kal_uint32 *num);
void uart_cal_chksum_and_flush_gpd_list(void *gpd_head, void *gpd_tail);
void uart_clear_hwo_of_gpd_list(void *gpd_head, void *gpd_tail);

DCL_STATUS uart_ecpt_init_hif(UART_PORT port);
DCL_STATUS uart_ecpt_clear_ch(UART_PORT port);
DCL_STATUS uart_ecpt_tx_gpd(UART_PORT port, void *p_first_gpd, void *p_last_gpd);
DCL_STATUS uart_ecpt_tx_done_info(UART_PORT port, void **p_first_gpd, void **p_last_gpd, kal_uint32 *gpd_num);
DCL_STATUS uart_ecpt_assign_rx_gpd(UART_PORT port, void *p_first_gpd, void *p_last_gpd);
DCL_STATUS uart_ecpt_get_rx_gpd(UART_PORT port, void **p_first_gpd, void **p_last_gpd, kal_uint32 *gpd_num);

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



#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_UART_REG_DBG__)
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

#if defined(MT6290)
// following defined added by ansel
/* MDMISC register */
#define MDMISC_BASE				BASE_ADDR_MDPERIMISC
#define APMISC_BASE				BASE_ADDR_APMISC
#define MDMISC_MDGDMACTL			(MDMISC_BASE + 0x10)
#define APMISC_APGDMACTL			(APMISC_BASE + 0x58)
#endif


#define GDMA_BASE_ADDR				BASE_ADDR_MDGDMA
#define APGDMA_BASE_ADDR			BASE_ADDR_APGDMA

#define UART_HDMA_INTR_ID			MD_IRQID_MDGDMA2

#define HDMA_BURST_SIZE_DEFAULT			(HDMA_BURST_SIZE_16B)
#define HDMA_DEV_BUS_WIDTH_DEFAULT		(HDMA_DEV_BUS_WIDTH_1B)
#define HDMA_MEM_BUS_WIDTH_DEFAULT		(HDMA_MEM_BUS_WIDTH_4B)
#define HDMA_MODE_DEFAULT			(HDMA_BASIC_MODE)
#define HDMA_CKSUM_EN_DEFAULT			(HDMA_CKSUM_ON)
#define HDMA_CKSUM_MODE_DEFAULT			(HDMA_CKSUM_16B)

/* HDMA registers */
#define GDMA_HDCSR(_n)				(GDMA_BASE_ADDR + 0x100 + (_n/2 * 0x4))
#define GDMA_HDSR                               (GDMA_BASE_ADDR + 0x120)
#define GDMA_HDCPR                              (GDMA_BASE_ADDR + 0x124)
#define GDMA_HDCTRR(_n)				(GDMA_BASE_ADDR + 0x140 + (_n * 0x20))
#define GDMA_HDC0R(_n)				(GDMA_BASE_ADDR + 0x144 + (_n * 0x20))
#define GDMA_HDC1R(_n)				(GDMA_BASE_ADDR + 0x148 + (_n * 0x20))
#define GDMA_HPRGA0R(_n)			(GDMA_BASE_ADDR + 0x14C + (_n * 0x20))
#define GDMA_HPRGA1R(_n)			(GDMA_BASE_ADDR + 0x150 + (_n * 0x20))
#define GDMA_HCCR(_n)				(GDMA_BASE_ADDR + 0x154 + (_n * 0x20))
#define GDMA_HDCPRN(_n)				(GDMA_BASE_ADDR + 0x158 + (_n * 0x20))
#define GDMA_GISAR_UART				(GDMA_BASE_ADDR + 0x60C)                                        //GDMA_GISAR3
#define GDMA_GIMRK_UART				(GDMA_BASE_ADDR + 0x62C)                                        //GDMA_GIMRK3

#define APGDMA_HDCSR(_n)			(APGDMA_BASE_ADDR + 0x100 + (_n/2 * 0x4))
#define APGDMA_HDSR				(APGDMA_BASE_ADDR + 0x120)
#define APGDMA_HDCPR				(APGDMA_BASE_ADDR + 0x124)
#define APGDMA_HDCTRR(_n)			(APGDMA_BASE_ADDR + 0x140 + (_n * 0x20))
#define APGDMA_HDC0R(_n)			(APGDMA_BASE_ADDR + 0x144 + (_n * 0x20))
#define APGDMA_HDC1R(_n)			(APGDMA_BASE_ADDR + 0x148 + (_n * 0x20))
#define APGDMA_HPRGA0R(_n)			(APGDMA_BASE_ADDR + 0x14C + (_n * 0x20))
#define APGDMA_HPRGA1R(_n)			(APGDMA_BASE_ADDR + 0x150 + (_n * 0x20))
#define APGDMA_HCCR(_n)				(APGDMA_BASE_ADDR + 0x154 + (_n * 0x20))
#define APGDMA_HDCPRN(_n)			(APGDMA_BASE_ADDR + 0x158 + (_n * 0x20))
#define APGDMA_GISAR_UART			(APGDMA_BASE_ADDR + 0x60C)                                        //GDMA_GISAR3
#define APGDMA_GIMRK_UART			(APGDMA_BASE_ADDR + 0x62C)                                        //GDMA_GIMRK3

#define HDMA_START_BIT				(0x1)
#define HDMA_STOP_BIT				(0x4)
#define HDMA_RESUME_BIT				(0x2)

#define HDMA_STAT				(0x1)
#define HDMA_CONFIG_MASK			(0x3FFFF)
#define HDMA_MODE_MASK(_n)			(0xFFFF << (16 *(_n %2)))

#define HDMA_INTR_CHL_MASK(_n)			(1 << (_n -4))

typedef enum{
	HDMA_BURST_SIZE_4B = 2,
	HDMA_BURST_SIZE_8B = 3,
	HDMA_BURST_SIZE_16B = 4,
	HDMA_BURST_SIZE_MAX,
}drv_uart_hdma_burst_size_t;

typedef enum{
	HDMA_DEV_BUS_WIDTH_1B = 0,
	HDMA_DEV_BUS_WIDTH_MAX,	
}drv_uart_hdma_dev_bus_width;

typedef enum{
	HDMA_MEM_BUS_WIDTH_1B = 0,
	HDMA_MEM_BUS_WIDTH_2B = 1,
	HDMA_MEM_BUS_WIDTH_4B = 2,
	HDMA_MEM_BUS_WIDTH_MAX,	
}drv_uart_hdma_mem_bus_width;

typedef enum{
	HDMA_LIST_MODE = 0,
	HDMA_BASIC_MODE = 1,
	HDMA_DESCRIPTOR_MODE = 2,	
}drv_uart_hdma_mode;

typedef enum{
	HDMA_CKSUM_OFF	= 0,
	HDMA_CKSUM_ON	= 1,
}drv_uart_hdma_cksum_en;

typedef enum{
	HDMA_CKSUM_12B = 0,
	HDMA_CKSUM_16B = 1,
}drv_uart_hdma_cksum_mode;

typedef enum{
	UART_EN_Q = 0,
	UART_DE_Q = 1,
	UART_EN_Q_LIGHT = 2,
	UART_DE_Q_ALL = 3,
} drv_uart_en_q_or_de_q;

typedef struct{
	drv_uart_hdma_burst_size_t			bst_size;
	drv_uart_hdma_dev_bus_width 			dev_bus_width;
	drv_uart_hdma_mem_bus_width 			mem_bus_width;
	drv_uart_hdma_mode				mode;
	drv_uart_hdma_cksum_en				cksum_en;
	drv_uart_hdma_cksum_mode			cksum_mode;
}drv_uart_hdma_config_t;

#define HDMA_CONFIG_INIT(_bst, _devbus, _membus, _mode, _cksum_en,_cksum) \
	{ _bst, _devbus, _membus, _mode, _cksum_en, _cksum}

typedef enum{
	GDMA_MODE_HDMA = 0,
	GDMA_MODE_VDMA = 1,
}drv_uart_gdma_mode;


/* HDMA commands */
#define HDMA_CONFIG(_n, _bst, _devbus, _membus) \
	DRV_WriteReg32_NPW(GDMA_HDCTRR(_n), (DRV_Reg32(GDMA_HDCTRR(_n)) & ~HDMA_CONFIG_MASK) | (_bst << 13) |( _devbus << 6) |(_membus << 4))
#define HDMA_MODE_CONFIG(_n, _cksum_en,_mode, _cksum) \
	DRV_WriteReg32_NPW(GDMA_HDCSR(_n), (DRV_Reg32(GDMA_HDCSR(_n)) & ~(HDMA_MODE_MASK(_n))) |(_cksum_en << (15 + (16 *(_n %2))))| (_mode << (9 + (16 *(_n %2)))) |(_cksum << (8 + (16 *(_n %2)))))
#define APHDMA_CONFIG(_n, _bst, _devbus, _membus) \
	DRV_WriteReg32_NPW(APGDMA_HDCTRR(_n), (DRV_Reg32(APGDMA_HDCTRR(_n)) & ~HDMA_CONFIG_MASK) | (_bst << 13) |( _devbus << 6) |(_membus << 4))
#define APHDMA_MODE_CONFIG(_n, _cksum_en,_mode, _cksum) \
	DRV_WriteReg32_NPW(APGDMA_HDCSR(_n), (DRV_Reg32(APGDMA_HDCSR(_n)) & ~(HDMA_MODE_MASK(_n))) |(_cksum_en << (15 + (16 *(_n %2))))| (_mode << (9 + (16 *(_n %2)))) |(_cksum << (8 + (16 *(_n %2)))))


#define HDMA_BUF0_XFER_SIZE_CONFIG(_n, _xfer) \
	DRV_WriteReg32_NPW(GDMA_HDC0R(_n), (_xfer << 16))
#define HDMA_BUF0_PROG_ADDR_CONFIG(_n, _addr) \
	DRV_WriteReg32_NPW(GDMA_HPRGA0R(_n), _addr)
#define HDMA_BUF0_START(_n) \
	DRV_WriteReg32(GDMA_HDC0R(_n), DRV_Reg32(GDMA_HDC0R(_n)) | HDMA_START_BIT)
#define HDMA_BUF0_RESUME(_n) \
	DRV_WriteReg32(GDMA_HDC0R(_n), DRV_Reg32(GDMA_HDC0R(_n)) | HDMA_RESUME_BIT)
#define HDMA_BUF0_STOP(_n) \
	DRV_WriteReg32(GDMA_HDCTRR(_n), DRV_Reg32(GDMA_HDCTRR(_n)) | HDMA_STOP_BIT)
#define HDMA_BUF0_IS_ACTIVE(_n) \
	(DRV_Reg32(GDMA_HDSR) & (HDMA_STAT << (_n)))
#define HDMA_CHANNEL_CUR_BUF(_n) \
	( (DRV_Reg32(GDMA_HDCPR) >> (_n)) & 0x1 )
#define HDMA_INT_CLEAR_ALL() \
	(DRV_WriteReg32(GDMA_GISAR_UART, 0xFFFFFFFF))

#define APHDMA_BUF0_XFER_SIZE_CONFIG(_n, _xfer) \
	DRV_WriteReg32_NPW(APGDMA_HDC0R(_n), (_xfer << 16))
#define APHDMA_BUF0_PROG_ADDR_CONFIG(_n, _addr) \
	DRV_WriteReg32_NPW(APGDMA_HPRGA0R(_n), _addr)
#define APHDMA_BUF0_START(_n) \
	DRV_WriteReg32(APGDMA_HDC0R(_n), DRV_Reg32(APGDMA_HDC0R(_n)) | HDMA_START_BIT)
#define APHDMA_BUF0_RESUME(_n) \
	DRV_WriteReg32(APGDMA_HDC0R(_n), DRV_Reg32(APGDMA_HDC0R(_n)) | HDMA_RESUME_BIT)
#define APHDMA_BUF0_STOP(_n) \
	DRV_WriteReg32(APGDMA_HDCTRR(_n), DRV_Reg32(APGDMA_HDCTRR(_n)) | HDMA_STOP_BIT)
#define APHDMA_BUF0_IS_ACTIVE(_n) \
	(DRV_Reg32(APGDMA_HDSR) & (HDMA_STAT << (_n)))
#define APHDMA_CHANNEL_CUR_BUF(_n) \
	( (DRV_Reg32(APGDMA_HDCPR) >> (_n)) & 0x1 )
#define APHDMA_INT_CLEAR_ALL() \
	(DRV_WriteReg32(APGDMA_GISAR_UART, 0xFFFFFFFF))

/* HDMA Interrupt Related Macros*/
#define IS_HDMA_DONE_INTR(_val, _chl) \
	( _val &  HDMA_INTR_CHL_MASK(_chl))
#define IS_HDMA_QE_INTR(_val, _chl) \
	( _val &  (HDMA_INTR_CHL_MASK(_chl) << 8))
#define IS_HDMA_LENERR_INTR(_val, _chl) \
	( _val &  (HDMA_INTR_CHL_MASK(_chl) << 16))
#define IS_HDMA_BD_CSERR_INTR(_val, _chl) \
	( _val &  (HDMA_INTR_CHL_MASK(_chl) << 24))
#define IS_HDMA_GPD_CSERR_INTR(_val, _chl) \
	( _val &  (HDMA_INTR_CHL_MASK(_chl) << 28))
#define HDMA_INTR_MASK_ALL() \
	(DRV_WriteReg32(GDMA_GIMRK_UART, 0xFFFFFFFF))
#define HDMA_INTR_UNMASK_ALL() \
	(DRV_WriteReg32(GDMA_GIMRK_UART, 0x0))
#define HDMA_DONE_INTR_MASK(_chl) \
	DRV_WriteReg32(GDMA_GIMRK_UART, DRV_Reg32(GDMA_GIMRK_UART) | HDMA_INTR_CHL_MASK(_chl))
#define HDMA_DONE_INTR_UNMASK(_chl) \
	DRV_WriteReg32(GDMA_GIMRK_UART, DRV_Reg32(GDMA_GIMRK_UART) & ~(HDMA_INTR_CHL_MASK(_chl)))
#define HDMA_QE_INTR_MASK(_chl) \
	DRV_WriteReg32(GDMA_GIMRK_UART, DRV_Reg32(GDMA_GIMRK_UART) | (HDMA_INTR_CHL_MASK(_chl) << 8))
#define HDMA_QE_INTR_UNMASK(_chl) \
	DRV_WriteReg32(GDMA_GIMRK_UART, DRV_Reg32(GDMA_GIMRK_UART) & ~((HDMA_INTR_CHL_MASK(_chl)) << 8))
#define HDMA_LENERR_INTR_MASK(_chl) \
	DRV_WriteReg32(GDMA_GIMRK_UART, DRV_Reg32(GDMA_GIMRK_UART) | (HDMA_INTR_CHL_MASK(_chl) << 16))
#define HDMA_LENERR_INTR_UNMASK(_chl) \
	DRV_WriteReg32(GDMA_GIMRK_UART, DRV_Reg32(GDMA_GIMRK_UART) & ~((HDMA_INTR_CHL_MASK(_chl)) << 16))
#define HDMA_BD_CSERR_INTR_MASK(_chl) \
	DRV_WriteReg32(GDMA_GIMRK_UART, DRV_Reg32(GDMA_GIMRK_UART) | (HDMA_INTR_CHL_MASK(_chl) << 24))
#define HDMA_BD_CSERR_INTR_UNMASK(_chl) \
	DRV_WriteReg32(GDMA_GIMRK_UART, DRV_Reg32(GDMA_GIMRK_UART) & ~((HDMA_INTR_CHL_MASK(_chl)) << 24))
#define HDMA_GPD_CSERR_INTR_MASK(_chl) \
	DRV_WriteReg32(GDMA_GIMRK_UART, DRV_Reg32(GDMA_GIMRK_UART) | (HDMA_INTR_CHL_MASK(_chl) << 28))
#define HDMA_GPD_CSERR_INTR_UNMASK(_chl) \
	DRV_WriteReg32(GDMA_GIMRK_UART, DRV_Reg32(GDMA_GIMRK_UART) & ~((HDMA_INTR_CHL_MASK(_chl)) << 28))

// UART exception mode
#define UART_ECPT_QBM_BPS_NUM	15
#define UART_ECPT_QBM_BPS_BUF_SZ	QBM_QUEUE_GET_MEM_SIZE(QBM_SIZE_TGPD_BPS, UART_ECPT_QBM_BPS_NUM)

typedef struct _uart_bps_gpd{
	void		*bps_ptr[UART_ECPT_QBM_BPS_NUM];
	kal_uint32	bps_cur_idx;
	kal_uint32	remain_bps_gpd;
} uart_bps_gpd_t;

#endif

