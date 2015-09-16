/*******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   rmmi_sio.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Serial Port Input/Output of RMMI
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *     HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *==============================================================================
 ******************************************************************************/
 
#ifndef RMMI_SIO_H
#define RMMI_SIO_H
/******************************************************************************/

//#include "uart_sw.h"
#include "drv_comm.h"
#include "dcl.h"

/******************************************************************************/

#if !defined(__MTK_TARGET__ ) && defined(__RMMI_UT__)

#else
	#ifndef __HAL_SIO_DEV__

	#else

	#endif
#endif

/******************************************************************************/

extern kal_bool RMMI_UART_is_usb_cdc_acm(UART_PORT port); /* MAUI_02738549: 2011/03/02, avoid dialup on 1T1R USB COM */
extern kal_bool RMMI_UART_is_usb_active(UART_PORT port);

extern void RMMI_UART_Close(UART_PORT port, module_type ownerid);
extern void RMMI_UART_ClrRxBuffer(UART_PORT port, module_type ownerid);
extern void RMMI_UART_ClrTxBuffer(UART_PORT port, module_type ownerid);
extern void RMMI_UART_ConfigEscape(UART_PORT port, kal_uint8 EscChar, kal_uint16 ESCGuardtime, module_type ownerid);
//extern void RMMI_UART_CtrlBreak(UART_PORT port, IO_level SBREAK, module_type ownerid);
extern void RMMI_UART_CtrlDCD(UART_PORT port, IO_level SDCD, module_type ownerid);
extern void RMMI_UART_CtrlDTR(UART_PORT port, IO_level SDTR, module_type ownerid);
extern void RMMI_UART_CtrlRI(UART_PORT port, IO_level SRI, module_type ownerid);
extern kal_uint16 RMMI_UART_GetBytes(UART_PORT port, kal_uint8 * Buffaddr, kal_uint16 Length, kal_uint8 * status, module_type ownerid);
//extern kal_uint16 RMMI_UART_GetBytesAvail(UART_PORT port);
extern module_type RMMI_UART_GetOwnerID(UART_PORT port);
//extern kal_uint16 RMMI_UART_GetTxRoomLeft(UART_PORT port);
extern kal_bool RMMI_UART_Open(UART_PORT port,module_type ownerid);
//extern void RMMI_UART_Purge(UART_PORT port, UART_buffer dir, module_type ownerid);
extern kal_uint16 RMMI_UART_PutBytes(UART_PORT port, kal_uint8 * Buffaddr, kal_uint16 Length, module_type ownerid);
extern void RMMI_UART_ReadDCBConfig(UART_PORT port, UART_CONFIG_T * DCB, module_type ownerid);
extern void RMMI_UART_SetAutoBaud_Div(UART_PORT port, module_type ownerid);
//extern void RMMI_UART_SetBaudRate(UART_PORT port, UART_baudrate baudrate, module_type ownerid);
extern void RMMI_UART_SetDCBConfig(UART_PORT port, UART_CONFIG_T * UART_Config, module_type ownerid);
//extern void RMMI_UART_SetFlowCtrl(UART_PORT port, kal_bool XON, module_type ownerid);
extern UART_FLOW_CTRL_MODE_T RMMI_UART_GetFlowCtrl(UART_PORT uart_port);
extern void RMMI_UART_SetOwner(UART_PORT port, module_type ownerid);
extern void RMMI_UART_SleepOnTx_Enable(UART_PORT port, UART_SLEEP_ON_TX enable_flag);
extern void RMMI_UART_OpenWithPort(UART_PORT APP_port, UART_PORT new_uart_port);

/******************************************************************************/
#endif /* RMMI_SIO_H */

