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
//#include "kal_release.h"
#include "dcl.h"
#include "uart_internal.h"
#include "uart_sw.h"
#include "kal_general_types.h"
#include "drv_comm.h"

UartDriver_strcut* pUart_CMD_FUNC[MAX_UART_PORT_NUM];

extern UARTStruct UARTPort[];

static DCL_STATUS UART_Handler(DCL_DEV dev,DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);

Seriport_HANDLER_T  Uart_Drv_Handler = {DCL_UART_TYPE, UART_Handler};
extern UART_flowCtrlMode  UART_GetFlowCtrl(UART_PORT uart_port);

DCL_STATUS UART_Handler(DCL_DEV dev,DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	kal_bool return_flag = KAL_FALSE;
	DCL_STATUS return_status = STATUS_OK;
	if(dev >= MAX_UART_PORT_NUM)
      return STATUS_INVALID_DEVICE;
	switch (cmd)
		{
		case SIO_CMD_INIT:
				{
					UART_CTRL_INIT_T*    prCtrlInit;
					prCtrlInit = &(data->rUARTCtrlInit);
					UART_DriverInit(dev,prCtrlInit->u4Flag);
					//UART_DriverInit(dev);			
				}
			break;
			
		case SIO_CMD_OPEN:
				{
					UART_CTRL_OPEN_T* prCtrlOpen;
					prCtrlOpen = &(data->rUARTCtrlOPEN);
					return_flag = pUart_CMD_FUNC[dev]->Open(dev,(module_type)(prCtrlOpen->u4OwenrId) );
					if(return_flag == KAL_FALSE)
						return_status = STATUS_FAIL;
				}
			break;
			
		case SIO_CMD_CLOSE:
				{
					UART_CTRL_CLOSE_T* prCtrlClose;
					prCtrlClose = &(data->rUARTCtrlCLOSE);
					pUart_CMD_FUNC[dev]->Close(dev,(module_type)(prCtrlClose->u4OwenrId) );
				}
			break;
			
		case SIO_CMD_GET_BYTES:
				{
					UART_CTRL_GET_BYTES_T* prCtrlGetBytes;
					prCtrlGetBytes = &(data->rUARTCtrlGETBYTES);
				prCtrlGetBytes->u2RetSize=pUart_CMD_FUNC[dev]->GetBytes(dev, prCtrlGetBytes->puBuffaddr, prCtrlGetBytes->u2Length, prCtrlGetBytes->pustatus, (module_type)(prCtrlGetBytes->u4OwenrId) );
				}
			break;
			
		case SIO_CMD_PUT_BYTES:
				{
					UART_CTRL_PUT_BYTES_T* prCtrlPutBytes;
					prCtrlPutBytes = &(data->rUARTCtrlPUTBYTES);
				prCtrlPutBytes->u2RetSize=	pUart_CMD_FUNC[dev]->PutBytes(dev, prCtrlPutBytes->puBuffaddr, prCtrlPutBytes->u2Length,(module_type)(prCtrlPutBytes->u4OwenrId) );
				}
			break;
			
		case SIO_CMD_GET_RX_AVAIL:
				{
					UART_CTRL_RX_AVAIL_T* prCtrlRXAvail;
					prCtrlRXAvail = &(data->rUARTCtrlRXAVAIL);
					prCtrlRXAvail->u2RetSize =pUart_CMD_FUNC[dev]->GetRxAvail(dev);
				}
			break;
			
		case SIO_CMD_GET_TX_AVAIL:
				{
					UART_CTRL_TX_AVAIL_T* prCtrlTXAvail;
					prCtrlTXAvail = &(data->rUARTCtrlTXAVAIL);
					prCtrlTXAvail->u2RetSize = pUart_CMD_FUNC[dev]->GetTxAvail(dev);
				}
			break;
			
		case SIO_CMD_PUT_ISR_BYTES:
				{
					UART_CTRL_PUT_BYTES_T* prCtrlPutBytes;
					prCtrlPutBytes = &(data->rUARTCtrlPUTBYTES);
					prCtrlPutBytes->u2RetSize = pUart_CMD_FUNC[dev]->PutISRBytes(dev,prCtrlPutBytes->puBuffaddr,prCtrlPutBytes->u2Length,
																(module_type)(prCtrlPutBytes->u4OwenrId) );
				}
			break;

		case SIO_CMD_GET_ISR_TX_AVAIL:
				{
					UART_CTRL_TX_AVAIL_T* prCtrlTXAail;
					prCtrlTXAail = &(data->rUARTCtrlTXAVAIL);
					prCtrlTXAail->u2RetSize =pUart_CMD_FUNC[dev]->GetISRTxAvail(dev);	
				}
			break;
			
		case SIO_CMD_PURGE:
				{
					UART_CTRL_PURGE_T* prCtrlPurge;
					prCtrlPurge = &(data->rUARTCtrlPURGE);
					pUart_CMD_FUNC[dev]->Purge(dev,(UART_buffer)(prCtrlPurge->dir),(module_type)(prCtrlPurge->u4OwenrId) );
				}
			break;
			
		case SIO_CMD_SET_OWNER:
				{
					 UART_CTRL_OWNER_T* prCtrlOwner;
					 prCtrlOwner = &(data->rUARTCtrlOWNER);
					 pUart_CMD_FUNC[dev]->SetOwner(dev,(module_type)(prCtrlOwner->u4OwenrId));					 
				}
			break;
			
		case SIO_CMD_SET_FLOW_CTRL:
				{
					UART_CTRL_FLOW_CTRL_T* prCtrlFlowCtrl;
					prCtrlFlowCtrl = &(data->rUARTCtrlFLOWCTRL);
					pUart_CMD_FUNC[dev]->SetFlowCtrl(dev,(kal_bool)(prCtrlFlowCtrl->bXON),(module_type)(prCtrlFlowCtrl->u4OwenrId));
				}
			break;
			
		case SIO_CMD_CONFIG_ESCAPE:
				{
					UART_CTRL_CONFIG_ESP_T* prCtrlConfigEsp;
					prCtrlConfigEsp = &(data->rUARTCtrlCONFIGESP);
					pUart_CMD_FUNC[dev]->ConfigEscape(dev,prCtrlConfigEsp->uEscChar,prCtrlConfigEsp->u2ESCGuardtime,(module_type)(prCtrlConfigEsp->u4OwenrId) );					
				}
			break;
			
		case SIO_CMD_GET_ESCAPE_INFO:
				{
					UART_CTRL_CONFIG_ESP_T* prCtrlConfigEsp;
					prCtrlConfigEsp = &(data->rUARTCtrlCONFIGESP);
					prCtrlConfigEsp->u2ESCGuardtime = UARTPort[dev].ESCDet.GuardTime;
					prCtrlConfigEsp->uEscChar = UARTPort[dev].ESCDet.EscChar;
						
				}
			break;
			
		case SIO_CMD_SET_DCB_CONFIG:
				{
					UARTDCBStruct *prDCB;
					UART_CTRL_DCB_T* prCtrlDCB;
					prCtrlDCB = &(data->rUARTCtrlDCB);
					prDCB = (UARTDCBStruct*)(&(prCtrlDCB->rUARTConfig));
					pUart_CMD_FUNC[dev]->SetDCBConfig(dev,prDCB,(module_type)(prCtrlDCB->u4OwenrId) );
				}
			break;
			
		case SIO_CMD_CTRL_DCD:
				{
					 UART_CTRL_DCD_T* prCtrlDCD;
					 prCtrlDCD = &(data->rUARTCtrlDCD);
					 pUart_CMD_FUNC[dev]->CtrlDCD(dev,(IO_level)(prCtrlDCD->rIOLevelDCD),(module_type)(prCtrlDCD->u4OwenrId) );
				}
			break;
			
		case SIO_CMD_CTRL_BREAK:
				{
					UART_CTRL_BREAK_T* prCtrlBreak;
					prCtrlBreak = &(data->rUARTCtrlBREAK);
					pUart_CMD_FUNC[dev]->CtrlBreak(dev,(IO_level)(prCtrlBreak->rIOLevelBRK),(module_type)(prCtrlBreak->u4OwenrId) );
				}
			break;
			
		case SIO_CMD_CLR_RX_BUF:
				{
					UART_CTRL_CLR_BUFFER_T* prCtrlClrBuffer;
					prCtrlClrBuffer = &(data->rUARTCtrlCLRBUFFER);
					pUart_CMD_FUNC[dev]->ClrRxBuffer(dev,(module_type)(prCtrlClrBuffer->u4OwenrId) );
				}
			break;
			
		case SIO_CMD_CLR_TX_BUF:
				{
					UART_CTRL_CLR_BUFFER_T* prCtrlClrBuffer;
					prCtrlClrBuffer = &(data->rUARTCtrlCLRBUFFER);
					pUart_CMD_FUNC[dev]->ClrTxBuffer(dev,(module_type)(prCtrlClrBuffer->u4OwenrId) );
				}
			break;
			
		case SIO_CMD_SET_BAUDRATE:
				{
					UART_CTRL_BAUDRATE_T* prCtrlBaudrate;
					prCtrlBaudrate = &(data->rUARTCtrlBAUDRATE);
					pUart_CMD_FUNC[dev]->SetBaudRate(dev,prCtrlBaudrate->baudrate,(module_type)(prCtrlBaudrate->u4OwenrId) );
				}
			break;

		case SIO_CMD_SEND_ISR_DATA:
				{
					UART_CTRL_SEND_DATA_T* prCtrlSendData;
					prCtrlSendData = &(data->rUARTCtrlSENDDATA);
					prCtrlSendData->u2RetSize = pUart_CMD_FUNC[dev]->SendISRData(dev,prCtrlSendData->puBuffaddr,prCtrlSendData->u2Length,
										prCtrlSendData->umode,prCtrlSendData->uescape_char,(module_type)(prCtrlSendData->u4OwenrId) );
				}	
			break;
			
		case SIO_CMD_SEND_DATA:
				{
					UART_CTRL_SEND_DATA_T* prCtrlSendData;
					prCtrlSendData = &(data->rUARTCtrlSENDDATA);
					prCtrlSendData->u2RetSize = pUart_CMD_FUNC[dev]->SendData(dev,prCtrlSendData->puBuffaddr,prCtrlSendData->u2Length,
										prCtrlSendData->umode,prCtrlSendData->uescape_char,(module_type)(prCtrlSendData->u4OwenrId) );
				}
			break;
			
		case SIO_CMD_GET_OWNER_ID:
				{
					 UART_CTRL_OWNER_T* prCtrlOwner;
					 prCtrlOwner = &(data->rUARTCtrlOWNER);
					 
					 prCtrlOwner->u4OwenrId =  pUart_CMD_FUNC[dev]->GetOwnerID(dev);
				}
			break;
			
		case SIO_CMD_SET_AUTOBAUD_DIV:
				{
					 UART_CTRL_AUTO_BAUDDIV_T* prCtrlAutoBaudDiv;
					 prCtrlAutoBaudDiv = &(data->rUARTCtrlAUTOBAUDDIV);
					 pUart_CMD_FUNC[dev]->SetAutoBaud_Div(dev,(module_type)(prCtrlAutoBaudDiv->u4OwenrId) );
				}
			break;
			
		case SIO_CMD_REG_TX_CB:
				{
					UART_CTRL_REG_TX_CB_T* prCtrlTxCB;
					prCtrlTxCB = &(data->rUARTCtrlREGTXCB);
					pUart_CMD_FUNC[dev]->UART_Register_TX_cb(dev,(module_type)(prCtrlTxCB->u4OwenrId),(UART_TX_FUNC)prCtrlTxCB->func); 
				}
			break;
			
		case SIO_CMD_REG_RX_CB:
				{
					 UART_CTRL_REG_RX_CB_T * prCtrlRxCb;
					 prCtrlRxCb = &(data->rUARTCtrlREGRXCB);
					 pUart_CMD_FUNC[dev]->UART_Register_RX_cb(dev,(module_type)(prCtrlRxCb->u4OwenrId),(UART_RX_FUNC)prCtrlRxCb->func); 
				}
			break;


		case SIO_CMD_GET_UART_BYTE:
				{
					 UART_CTRL_GET_UART_BYTE_T* prCtrlGetUartByte;
					 prCtrlGetUartByte = &(data->rUARTCtrlGETUARTBYTE);
					 prCtrlGetUartByte->uByte = pUart_CMD_FUNC[dev]->GetUARTByte(dev); 
				}
			break;
			
		case SIO_CMD_GET_UART_BYTE_WITH_TIMEOUT:
				{
					 UART_CTRL_GET_UART_BYTE_WITH_TIMEOUT_T* prCtrlGetUartByte;
					 prCtrlGetUartByte = &(data->rUARTCtrlGETUARTBYTEWithTimeOut);
					 prCtrlGetUartByte->u1retByte = pUart_CMD_FUNC[dev]->GetUARTByte_WithTimeOut(dev, &(prCtrlGetUartByte->uByte), prCtrlGetUartByte->u4timeout_value); 
				}
			break;			
			
		case SIO_CMD_PUT_UART_BYTE:
				{
					UART_CTRL_PUT_UART_BYTE_T* prCtrlPutUartByte;
					prCtrlPutUartByte = &(data->rUARTCtrlPUTUARTBYTE);
					 pUart_CMD_FUNC[dev]->PutUARTByte(dev,prCtrlPutUartByte->uData); 
				}
			break;
			
		case SIO_CMD_PUT_UART_BYTES:
				{
					
					 UART_CTRL_PUT_UART_BYTES_T* prCtrlPutUartBytes;
					 prCtrlPutUartBytes = &(data->rUARTCtrlPUTUARTBYTES);
					 pUart_CMD_FUNC[dev]->PutUARTBytes(dev,prCtrlPutUartBytes->puBuffaddr,prCtrlPutUartBytes->u2Length); 
				}
			break;
			
		case SIO_CMD_READ_DCB_CONFIG:
				{
					UARTDCBStruct *prDCB;
					UART_CTRL_DCB_T* prCtrlDCB;
					prCtrlDCB = &(data->rUARTCtrlDCB);
					prDCB = (UARTDCBStruct*)(&(prCtrlDCB->rUARTConfig));
					pUart_CMD_FUNC[dev]->ReadDCBConfig(dev,prDCB); 
				}
			break;
			
		case SIO_CMD_CTRL_RI:
				{
					 UART_CTRL_RI_T* prCtrlRI;
					 prCtrlRI= &(data->rUARTCtrlRI);
					 pUart_CMD_FUNC[dev]->CtrlRI(dev,(IO_level)(prCtrlRI->rIOLevelSRI),(module_type)(prCtrlRI->u4OwenrId) ); 
				}
			break;
			
		case SIO_CMD_CTRL_DTR:
				{
					UART_CTRL_DTR_T* prCtrlDTR;
					prCtrlDTR = &(data->rUARTCtrlDTR);
					 pUart_CMD_FUNC[dev]->CtrlDTR(dev,(IO_level)(prCtrlDTR->rIOLevelDTR),(module_type)(prCtrlDTR->u4OwenrId) ); 
				}
			break;
			
		case SIO_CMD_READ_HW_STATUS:
				{
					IO_level* pSDSR;
					IO_level* pSCTS;
					 UART_CTRL_RHS_T* prCtrlRHS;
					 prCtrlRHS = &(data->rUARTCtrlRHS);
					 pSDSR = (IO_level*)(&(prCtrlRHS->rIOLevelDSR));
					 pSCTS = (IO_level*)(&(prCtrlRHS->rIOLevelCTS));
					 pUart_CMD_FUNC[dev]->ReadHWStatus(dev,pSDSR,pSCTS);  
				}
			break;
			
			case UART_CMD_SET_FIFO_TRIGGER:
					{
						 UART_CTRL_SFT_T* prCtrlSFT;
						 prCtrlSFT = &(data->rUARTCtrlSFT); 
						 UART_set_FIFO_trigger(dev,  prCtrlSFT->tx_level, prCtrlSFT->rx_level);
						 
					}
			break;
			
			case UART_CMD_POWER_ON:
					{
						UART_CTRL_POWERON_T* prCtrlPoweron;
						prCtrlPoweron = &(data->rUARTCtrlPoweron);
						//UART_TurnOnPower(dev, (kal_bool)(prCtrlPoweron->bFlag_Poweron) );
						UART_TurnOnPower(dev, KAL_TRUE );
					}

				break;
			case UART_CMD_CHECK_TX_BUF_EMPTY:
					{
						UART_CTRL_CHECK_TBE_T* prCtrlTBE;
						prCtrlTBE = &(data->rUARTCtrlCheckBUFEMP);
						prCtrlTBE->bFlag = UART_CheckTxBufferEmpty(dev);
					}
				break;
				
	 case UART_CMD_CHECK_TX_SEND_OUT:
	 		{
				UART_CTRL_CHECK_TSO_T* prCtrlTSO;
				prCtrlTSO = &(data->rUARTCtrlCheckTXSendOut);
				prCtrlTSO->bFlag = UART_CheckTxAllSentOut(dev);
			}
	 	break;
		
	case UART_CMD_GET_TX_BUF_SIZE:
			{
				UART_CTRL_GET_TBS_T* prCtrlGetTBS;
				prCtrlGetTBS = &(data->rUARTCtrlGetTxBufSize);
//dear yali help confirm if this type is right or not, i remove & for solve build error
				UART_GetTxBufferSize(dev, (kal_uint32 *)(prCtrlGetTBS->ptotal_size), (kal_uint32 *)(prCtrlGetTBS->preturn_size));
			}
		break;
		
	case UART_CMD_SLEEP_TX_ENABLE:
			{
				UART_CTRL_SLEEP_ON_TX_ENABLE_T* prCtrlSleepTx;
				prCtrlSleepTx = &(data->rUARTCtrlSleepOnTxEnable);
				UART_SleepOnTx_Enable(dev, (UART_SLEEP_ON_TX)(prCtrlSleepTx->bFlag) );
			}
		break;
		
	case UART_CMD_CTRL_SLEEP_MODE:
			{
				UART_CTRL_SLEEP_ENABLE_T* prCtrlSleepEnable;
				prCtrlSleepEnable = &(data->rUARTCtrlSleepEnable);
				UART_SetSleepEnable( (kal_bool)(prCtrlSleepEnable->bFlag) );
			}
		break;
		
		
	case UART_CMD_BOOTUP_INIT:
			{
				UART_Bootup_Init();
			}
		break;
		
	case UART_CMD_BOOT_PUTBYTES:
			{
				UART_CTRL_BOOT_PUTBYTES_T* prCtrlPutBytes;
				prCtrlPutBytes = &(data->rUARTCtrlBootPutBytes);
				UART_Boot_PutUARTBytes(dev,prCtrlPutBytes->puBuffaddr, prCtrlPutBytes->u2Length);
			}
		break;
		
	case UART_CMD_LOOPBACK:
			{
				UART_loopback(dev);
			}
		break;
		
	case UART_CMD_ASSERT_WAIT_SEND_OUT:
			{
				UART_AssertWaitPrevDataSentOut(dev);
			}
		break;
	case UART_CMD_CTRL_USE_VFIFO:
			{
			//	UART_CTRL_USE_VFIFO_T* prCtrlUseVfifo;
			//	prCtrlUseVfifo = &(data->rUARTCtrlUseVFifo);
		//		UART_UseVFIFO(dev,prCtrlUseVfifo->bUseVFifo);
			}
		break;
	case UART_CMD_CTRL_TX_DMA:
			{
				UART_CTRL_USE_VFIFO_T* prCtrlTxDMA;
				prCtrlTxDMA = &(data->rUARTCtrlUseVFifo);
				UART_VFIFO_TX_DMA_Enable(dev,(kal_bool)(prCtrlTxDMA->bUseVFifo));
			}
		break;
				
	case UART_CMD_GET_FLOW_CONTROL:
			{
				UART_CTRL_GET_FC_T* prCtrlFlowControl;
				prCtrlFlowControl = &(data->rUARTCtrlGetFC);
				prCtrlFlowControl->FlowCtrlMode =(UART_FLOW_CTRL_MODE_T) UART_GetFlowCtrl(dev);
			}
			break;
 	case UART_CMD_REG_DEF_CB:
			{
				UART_CTRL_REG_DEF_CB_T* prCtrlDef;
				prCtrlDef = &(data->rUARTCtrlRegDefCB);
				if(prCtrlDef->dir== UART_TX)
				    UART_dafault_tx_cb(dev);
				else if(prCtrlDef->dir== UART_RX)
					UART_dafault_rx_cb(dev);
				else if(prCtrlDef->dir== DSP_RX)
					UART_dsp_dafault_rx_cb(dev);
				else if(prCtrlDef->dir== DSP_TX)
					UART_dsp_dafault_tx_cb(dev);
			}
		break;
			
	case UART_CMD_BMT_PUT_BYTES:
			{
				#ifdef DRV_DEBUG
				UART_CTRL_PUT_BYTES_T* prCtrlBMTPutBytes;
				prCtrlBMTPutBytes = &(data->rUARTCtrlPUTBYTES);
			 	BMT_PutBytes(dev, prCtrlBMTPutBytes->puBuffaddr, prCtrlBMTPutBytes->u2Length);
			 	#endif
			}
		break;
	case UART_CMD_GET_MAX_BAUDRATE:
			{
				UART_CTRL_GET_MAXBAUDRATE_T* prCtrlGetMaxBaudrate;
				prCtrlGetMaxBaudrate = &(data->rUARTCtrlGetMaxBaudrate);
				prCtrlGetMaxBaudrate->max_baudrate = UART_Get_Maxbaudrate(dev);
			}
		break;
	#ifdef __DMA_UART_VIRTUAL_FIFO__
	case UART_CMD_RECHANDLER_VFIFO:
			{
				UART_RecHandler_VFIFO(dev);
			}
		break;
	case UART_CMD_TRXHANDLER_VFIFO:
			{
				UART_TrxHandler_VFIFO(dev);
			}
		break;	
	case UART_CMD_RECTIMEOUTHANDLE:
			{
				UART_RecTimeOutHandler(dev);
			}
		break;
	#endif
	/*added this cmd for TTY cmd compatiable */
	case UART_CMD_SWITCH_PORT:
	case TTY_CMD_GET_CHUNK_SIZE:
	case TTY_CMD_ASSIGN_RX_IOR:
	case TTY_CMD_NEED_TX_DONE_CB:
	case TTY_CMD_GET_DRV_STATE:
	case TTY_CMD_PUT_BYTES_IOR:
	case TTY_CMD_PUT_BYTES_IOR_LIGHT:
		// TTY commands for exception
	case TTY_CMD_EXCEPTION_RESET:
	case TTY_CMD_EXCEPTION_HIF_INIT:
	case TTY_CMD_EXCEPTION_CLEAR_CHANNEL:
	case TTY_CMD_EXCEPTION_TX_GPD:
	case TTY_CMD_EXCEPTION_TX_DONE_INFO:
	case TTY_CMD_EXCEPTION_HIF_STATE:
	case TTY_CMD_EXCEPTION_ASSIGN_RX_GPD:
	case TTY_CMD_EXCEPTION_GET_RX_GPD:
	case TTY_CMD_EXCEPTION_HIF_POLL:
		  break ;
			
			default:
				return STATUS_INVALID_CMD;
		}

	return return_status;
}



