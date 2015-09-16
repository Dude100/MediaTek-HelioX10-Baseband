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
 *   uart_handler.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   Handler for UART
 *
 * Author:
 * -------
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * Set UART related GPIO setting when uart is used.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * add uart3 driver support
 *
 * removed!
 * removed!
 * update uart driver to sperate uartcore and DRV_DEBUG
 *
 * removed!
 * removed!
 * uart driver update for TTY_CMD_EXCEPTION_HIF_POL
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * update UART exception driver for following the HMU standard mode.
 *
 * removed!
 * removed!
 * rename: 7208 -> 6290
 *
 * removed!
 * removed!
 * Integration change.
 *
 * removed!
 * removed!
 * Add UART/HDMA driver
 ****************************************************************************/
#include "dcl.h"
#include "uart_internal.h"
#include "uart_sw.h"
#include "kal_general_types.h"
#include "drv_comm.h"
#include "kal_public_api.h"

#if defined(__HMU_ENABLE__)
#include "hmu.h"
#include "hmu_conf_data.h"
#endif

#define UART_CHUNK_SIZE	512

UartDriver_strcut* pUart_CMD_FUNC[MAX_UART_PORT_NUM];

extern UARTStruct UARTPort[];
kal_uint32 uart_open_event = 0;

static DCL_STATUS UART_Handler(DCL_DEV dev,DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);

Seriport_HANDLER_T  Uart_Drv_Handler = {DCL_UART_TYPE, UART_Handler};
//extern UART_flowCtrlMode  UART_GetFlowCtrl(UART_PORT uart_port);

DCL_STATUS UART_Handler(DCL_DEV dev,DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	kal_bool return_flag = KAL_FALSE;
	DCL_STATUS return_status = STATUS_OK;
	if(dev >= MAX_UART_PORT_NUM)
		return STATUS_INVALID_DEVICE;
	
	switch (cmd)
	{
		// Class Driver must implement
		case SIO_CMD_INIT:
		{
			UART_DriverInit(dev);			
		}
			break;
			
		case SIO_CMD_OPEN:
		{
			UART_CTRL_OPEN_T* prCtrlOpen;
#if defined(__UARTCORE_SUPPORT__) && !defined(UARTCORE_NOT_PRESENT) && !defined(__UARTCORE_TASK_DISABLE__)&&!defined(DRV_DEBUG)
			if(dev < uart_port3){   //SUART1 not support DMA mode
				uart_open_event ++;
				hmu_hifeg_set(HIF_DRV_EG_UART_IND_EVENT);
			}
#endif

#if defined(MT6752) && defined(__MD1__)
            #define AP_GPIO_BASE       (0xA0005000)
            #define AP_IOCFG_R_BASE    (0xA0002800)
            if (dev == uart_port1) {
                kal_uint32 temp;
                DRV_WriteReg32(AP_GPIO_BASE+0x428, 0xFF);
                DRV_WriteReg32(AP_GPIO_BASE+0x424, 0x66);      /* Set MD_UR/TXD Pin Mode */

                temp = DRV_Reg32(AP_IOCFG_R_BASE+0x090);
                temp &= ~(0x3);
                temp |= 0x1;
                DRV_WriteReg32(AP_IOCFG_R_BASE+0x090, temp);   /* Set MD_URXD PullEn */

                temp = DRV_Reg32(AP_IOCFG_R_BASE+0x0c0);
                temp &= ~(0x3);
                temp |= 0x1;
                DRV_WriteReg32(AP_IOCFG_R_BASE+0x0c0, temp);   /* Set MD_URXD PullSel */
            } else if (dev == uart_port2) {
                kal_uint32 temp;
                DRV_WriteReg32(AP_GPIO_BASE+0x428, 0xFF00);
                DRV_WriteReg32(AP_GPIO_BASE+0x424, 0x6600);    /* Set LTE_UR/TXD Pin Mode */

                temp = DRV_Reg32(AP_IOCFG_R_BASE+0x090);
                temp &= ~(0xC);
                temp |= 0x4;
                DRV_WriteReg32(AP_IOCFG_R_BASE+0x090, temp);   /* Set LTE_URXD PullEn */

                temp = DRV_Reg32(AP_IOCFG_R_BASE+0x0c0);
                temp &= ~(0xC);
                temp |= 0x4;
                DRV_WriteReg32(AP_IOCFG_R_BASE+0x0c0, temp);   /* Set LTE_URXD PullSel */
            }
#endif

			prCtrlOpen = &(data->rUARTCtrlOPEN);
			return_flag = pUart_CMD_FUNC[dev]->Open(dev,(module_type)(prCtrlOpen->u4OwenrId));
			if(return_flag == KAL_FALSE){
				UART_DriverInit(dev);
				return_status = STATUS_FAIL;
			}
		}
			break;
			
		case SIO_CMD_CLOSE:
		{
			UART_CTRL_CLOSE_T* prCtrlClose;
			prCtrlClose = &(data->rUARTCtrlCLOSE);
			pUart_CMD_FUNC[dev]->Close(dev,(module_type)(prCtrlClose->u4OwenrId));
#if defined(__UARTCORE_SUPPORT__) && !defined(UARTCORE_NOT_PRESENT) && !defined(__UARTCORE_TASK_DISABLE__)&&!defined(DRV_DEBUG)
			if(dev < uart_port3){  //SUART1 not support DMA mode
				if(uart_open_event>0){
					uart_open_event--;
				}
			}
#endif	
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
			pUart_CMD_FUNC[dev]->SetOwner(dev, (module_type) (prCtrlOwner->u4OwenrId));
		}
			break;

		case SIO_CMD_CLR_RX_BUF:
		{
			UART_CTRL_CLR_BUFFER_T* prCtrlClrBuffer;
			prCtrlClrBuffer = &(data->rUARTCtrlCLRBUFFER);
			pUart_CMD_FUNC[dev]->ClrRxBuffer(dev, (module_type) (prCtrlClrBuffer->u4OwenrId));
		}
			break;

		case SIO_CMD_CLR_TX_BUF:
		{
			UART_CTRL_CLR_BUFFER_T* prCtrlClrBuffer;
			prCtrlClrBuffer = &(data->rUARTCtrlCLRBUFFER);
			pUart_CMD_FUNC[dev]->ClrTxBuffer(dev, (module_type) (prCtrlClrBuffer->u4OwenrId));
		}
			break;

		case SIO_CMD_GET_OWNER_ID:
		{
			UART_CTRL_OWNER_T* prCtrlOwner;
			prCtrlOwner = &(data->rUARTCtrlOWNER);
			prCtrlOwner->u4OwenrId = pUart_CMD_FUNC[dev]->GetOwnerID(dev);
		}
			break;

		// Other SIO configuration related commands
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
			pUart_CMD_FUNC[dev]->ConfigEscape(dev, prCtrlConfigEsp->uEscChar, prCtrlConfigEsp->u2ESCGuardtime, (module_type) (prCtrlConfigEsp->u4OwenrId));
		}
			break;

		case SIO_CMD_SET_DCB_CONFIG:		
		{
			UARTDCBStruct *prDCB;
			UART_CTRL_DCB_T* prCtrlDCB;
			prCtrlDCB = &(data->rUARTCtrlDCB);
			prDCB = (UARTDCBStruct*)(&(prCtrlDCB->rUARTConfig));
			pUart_CMD_FUNC[dev]->SetDCBConfig(dev,prDCB,(module_type)(prCtrlDCB->u4OwenrId));
		}
			break;

		case SIO_CMD_CTRL_DCD:		// Not used in MT6290 UART
			ASSERT(0);
			break;

		case SIO_CMD_CTRL_BREAK:
		{
			UART_CTRL_BREAK_T* prCtrlBreak;
			prCtrlBreak = &(data->rUARTCtrlBREAK);
			pUart_CMD_FUNC[dev]->CtrlBreak(dev, (IO_level) (prCtrlBreak->rIOLevelBRK), (module_type) (prCtrlBreak->u4OwenrId));
		}
			break;

		case SIO_CMD_SET_BAUDRATE:
		{
			UART_CTRL_BAUDRATE_T* prCtrlBaudrate;
			prCtrlBaudrate = &(data->rUARTCtrlBAUDRATE);
			pUart_CMD_FUNC[dev]->SetBaudRate(dev, prCtrlBaudrate->baudrate, (module_type)(prCtrlBaudrate->u4OwenrId));
		}
			break;

		case SIO_CMD_SET_AUTOBAUD_DIV:	// LTE TBC
			ASSERT(0);
			break;

		case SIO_CMD_READ_DCB_CONFIG:	
		{
			UARTDCBStruct *prDCB;
			UART_CTRL_DCB_T* prCtrlDCB;
			prCtrlDCB = &(data->rUARTCtrlDCB);
			prDCB = (UARTDCBStruct*) &(prCtrlDCB->rUARTConfig);
			pUart_CMD_FUNC[dev]->ReadDCBConfig(dev, prDCB); 
		}
			break;

		case SIO_CMD_CTRL_RI:		// Not used in MT6290 UART
			ASSERT(0);
			break;

		case SIO_CMD_GET_ESCAPE_INFO:		
		{
			UART_CTRL_CONFIG_ESP_T* prCtrlConfigEsp;
			prCtrlConfigEsp = &(data->rUARTCtrlCONFIGESP);
			prCtrlConfigEsp->u2ESCGuardtime = UARTPort[dev].ESCDet.GuardTime;
			prCtrlConfigEsp->uEscChar = UARTPort[dev].ESCDet.EscChar;
		}
			break;

		case SIO_CMD_CTRL_DTR:		// Not used in MT6290 UART
		case SIO_CMD_READ_HW_STATUS:	// Not used in MT6290 UART (assert temporary)

		// Not used commands in driver level (TTY would handle/wrap these commands from conventional upper layer module)
		case SIO_CMD_GET_BYTES:
		case SIO_CMD_PUT_BYTES:
		case SIO_CMD_GET_RX_AVAIL:
		case SIO_CMD_GET_TX_AVAIL:
		case SIO_CMD_PUT_ISR_BYTES:
		case SIO_CMD_GET_ISR_TX_AVAIL:
		case SIO_CMD_SEND_ISR_DATA:
		case SIO_CMD_SEND_DATA:
		case SIO_CMD_REG_TX_CB:
		case SIO_CMD_REG_RX_CB:
		case SIO_CMD_PUT_UART_BYTE:
		case SIO_CMD_GET_UART_BYTE:
		case SIO_CMD_PUT_UART_BYTES:
			ASSERT(0);
			break;

		// ???
		case SIO_CMD_GET_UART_BYTE_WITH_TIMEOUT:
			// temporary
			ASSERT(0);
		{
			 UART_CTRL_GET_UART_BYTE_WITH_TIMEOUT_T* prCtrlGetUartByte;
			 prCtrlGetUartByte = &(data->rUARTCtrlGETUARTBYTEWithTimeOut);
			 prCtrlGetUartByte->u1retByte = pUart_CMD_FUNC[dev]->GetUARTByte_WithTimeOut(dev, &(prCtrlGetUartByte->uByte), prCtrlGetUartByte->u4timeout_value); 
		}
			break;

		// Only UART driver need to take care
		case UART_CMD_SET_FIFO_TRIGGER:
		{
			 UART_CTRL_SFT_T* prCtrlSFT;
			 prCtrlSFT = &(data->rUARTCtrlSFT); 
			 UART_set_FIFO_trigger(dev, prCtrlSFT->tx_level, prCtrlSFT->rx_level);
		}
			break;
		
		case UART_CMD_POWER_ON:
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
			ASSERT(0);
		{
			UART_CTRL_GET_TBS_T* prCtrlGetTBS;
			prCtrlGetTBS = &(data->rUARTCtrlGetTxBufSize);
			UART_GetTxBufferSize(dev, (kal_uint32 *)(prCtrlGetTBS->ptotal_size), (kal_uint32 *)(prCtrlGetTBS->preturn_size));
		}
			break;
		
		case UART_CMD_SLEEP_TX_ENABLE:
			return STATUS_UNSUPPORTED;
		
		case UART_CMD_CTRL_SLEEP_MODE:
		{
			UART_CTRL_SLEEP_ENABLE_T* prCtrlSleepEnable;
			prCtrlSleepEnable = &(data->rUARTCtrlSleepEnable);
			UART_SetSleepEnable(dev, (kal_bool) prCtrlSleepEnable->bFlag);
		}
			break;
		case UART_CMD_SWITCH_PORT:
			return STATUS_UNSUPPORTED;
		
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
			return STATUS_UNSUPPORTED;
			ASSERT(0);
		{
//			UART_CTRL_USE_VFIFO_T* prCtrlUseVfifo;
//			prCtrlUseVfifo = &(data->rUARTCtrlUseVFifo);
//			UART_UseVFIFO(dev,prCtrlUseVfifo->bUseVFifo);
		}
			break;

		case UART_CMD_GET_FLOW_CONTROL:
		{
			UART_CTRL_GET_FC_T* prCtrlFlowControl;
			prCtrlFlowControl = &(data->rUARTCtrlGetFC);
			prCtrlFlowControl->FlowCtrlMode = (UART_FLOW_CTRL_MODE_T) U_GetFlowCtrl(dev, prCtrlFlowControl->u4OwenrId);
		}
			break;
			
	 	case UART_CMD_REG_DEF_CB:
			ASSERT(0);
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

		case UART_CMD_RECHANDLER_VFIFO:
		case UART_CMD_TRXHANDLER_VFIFO:
		case UART_CMD_RECTIMEOUTHANDLE:
		case UART_CMD_CTRL_TX_DMA:
			ASSERT(0);
		{
			UART_CTRL_USE_VFIFO_T* prCtrlTxDMA;
			prCtrlTxDMA = &(data->rUARTCtrlUseVFifo);
			UART_VFIFO_TX_DMA_Enable(dev,(kal_bool)(prCtrlTxDMA->bUseVFifo));
		}
			break;

		// TTY commands
		case TTY_CMD_GET_CHUNK_SIZE:
		{
			UART_CTRL_GET_CHUNK_SIZE_T *prCtrlGetChunkSize;
			prCtrlGetChunkSize = &(data->rUARTCtrlGETCHUNKSIZE);
			prCtrlGetChunkSize->chunkSize = UART_CHUNK_SIZE;
		}
			break;

		case TTY_CMD_ASSIGN_RX_IOR:
		{
			UART_CTRL_ASSIGN_RX_IOR_T *prCtrlAssignRxIor;
			prCtrlAssignRxIor = &(data->rUARTCtrlAssignRxIor);
			UART_GetBytesIor(dev, prCtrlAssignRxIor->ior);
		}
			break;

		case TTY_CMD_NEED_TX_DONE_CB:
		{
			UART_CTRL_NEED_TX_DONE_CB_T *prNeedTxDoneCb;
			prNeedTxDoneCb = &(data->rUARTCtrlNeedTxDoneCb);
			UART_SetNeedTxDoneCb(dev, prNeedTxDoneCb->needTxDoneCb, prNeedTxDoneCb->u4OwnerId);
		}
			break;

		case TTY_CMD_GET_DRV_STATE:
		{
			UART_CTRL_GET_DRV_STATE_T *prGetDrvState;
			prGetDrvState = &(data->rUARTCtrlGetDrvState);
			prGetDrvState->drv_state = DRV_ST_ATTACHED;
		}
			break;

		case TTY_CMD_PUT_BYTES_IOR:
		{
			UART_CTRL_PUT_BYTES_IOR_T *prCtrlPutBytesIor;
			prCtrlPutBytesIor = &(data->rUARTCtrlPUTBYTESIOR);
			UART_PutBytesIor(dev, prCtrlPutBytesIor->putIor);
		}
			break;

		case TTY_CMD_PUT_BYTES_IOR_LIGHT:
		{
			UART_CTRL_PUT_BYTES_IOR_T *prCtrlPutBytesIor;
			prCtrlPutBytesIor = &(data->rUARTCtrlPUTBYTESIOR);
			UART_PutBytesIor_LIGHT(dev, prCtrlPutBytesIor->putIor);
		}
			break;

		// TTY commands for exception
		case TTY_CMD_EXCEPTION_RESET:
			break;	

		case TTY_CMD_EXCEPTION_HIF_INIT:
		{
			return_status = uart_ecpt_init_hif(dev);
		}
			break;

		case TTY_CMD_EXCEPTION_CLEAR_CHANNEL:
		{
			return_status = uart_ecpt_clear_ch(dev);
		}
			break;

		case TTY_CMD_EXCEPTION_TX_GPD:
		{
			TTY_CTRL_EXCP_TX_GPD_T* prCtrlExptTxGpd;
			prCtrlExptTxGpd = &(data->rTTYCtrlExcpTxGPD);
			return_status = uart_ecpt_tx_gpd(dev, prCtrlExptTxGpd->first_gpd, prCtrlExptTxGpd->last_gpd);
		}
			break;

		case TTY_CMD_EXCEPTION_TX_DONE_INFO:
		{
			TTY_CTRL_EXCP_TX_DONE_INFO_T* prCtrlExptTxDoneInfo; 
			prCtrlExptTxDoneInfo = &(data->rTTYCtrlExcpTxDoneInfo);
			return_status = uart_ecpt_tx_done_info(dev, &(prCtrlExptTxDoneInfo->first_gpd), &(prCtrlExptTxDoneInfo->last_gpd), (kal_uint32 *) &(prCtrlExptTxDoneInfo->num));
		}
			break;

		case TTY_CMD_EXCEPTION_HIF_STATE:
		{   
			TTY_CTRL_EXCP_HIF_STATE_T* prCtrlExptHifState;
			prCtrlExptHifState = &(data->rTTYCtrlExcpHifState);
			prCtrlExptHifState->hif_state = 0; //HIF_STATE_NORMAL

		}
			break;

		case TTY_CMD_EXCEPTION_ASSIGN_RX_GPD:
		{
			TTY_CTRL_EXCP_ASSIGN_RX_GPD_T* prCtrlExptAssignRxGpd;
			prCtrlExptAssignRxGpd = &(data->rTTYCtrlExcpAssignRxGPD);
			return_status = uart_ecpt_assign_rx_gpd(dev, prCtrlExptAssignRxGpd->first_gpd, prCtrlExptAssignRxGpd->last_gpd);
		}
			break;

		case TTY_CMD_EXCEPTION_GET_RX_GPD:
		{
			TTY_CTRL_EXCP_GET_RX_GPD_T* prCtrlExptGetRxGpd;
			prCtrlExptGetRxGpd = &(data->rTTYCtrlExcpGetRxGPD);
			return_status = uart_ecpt_get_rx_gpd(dev, &(prCtrlExptGetRxGpd->first_gpd), &(prCtrlExptGetRxGpd->last_gpd), (kal_uint32 *) &(prCtrlExptGetRxGpd->num));
		}
			break;

		case TTY_CMD_EXCEPTION_HIF_POLL:
        {
            TTY_CTRL_EXCP_HIF_POLL_T* pCtrlHifPoll;
            pCtrlHifPoll = &(data->rTTYCtrlExcpHifPoll);
            pCtrlHifPoll->reset_event = DCL_FALSE;
        }
			break;

		default:
			return STATUS_INVALID_CMD;
	}

	return return_status;
}
