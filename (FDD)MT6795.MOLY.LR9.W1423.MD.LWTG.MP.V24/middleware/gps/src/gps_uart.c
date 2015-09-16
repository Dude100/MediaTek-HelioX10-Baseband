/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *  gps_uart.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GPS task
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __GPS_SUPPORT__
/* basic system service headers */
#include "dcl.h"            /* uart APIs*/
#include "gps_main.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_general_types.h"   
#include "kal_trace.h"   
#include "gps_sm.h"   

extern kal_uint8 gps_uart_port;
#ifdef __MNL_SUPPORT__
extern kal_uint8 mnl_port;
#endif
extern gps_context_struct *gps_context_p;
#ifdef __MNL_SUPPORT__
extern kal_uint16 mtk_mnl_uart_read(kal_uint8 *buffer, kal_uint16 length);  // Porting layer implementation
extern kal_int32 mtk_gps_nmea_input(const kal_int8 *buffer, kal_uint32 length);  // Library function
#endif
/*****************************************************************************
 * FUNCTION
 *  GPS_UART_Read
 * DESCRIPTION
 *  Read data from GPS UART port
 * PARAMETERS
 *  ilm_ptr     [IN]     message data
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 GPS_UART_Read(kal_uint8 port, kal_uint8 *buffer, kal_uint16 length)
{
#if defined(__SMART_PHONE_MODEM__)


    kal_uint16 readLen = 0;
    kal_uint8 status;
    DCL_HANDLE handle;
  	UART_CTRL_GET_BYTES_T data;
    
       
    data.u4OwenrId = MOD_GPS;
	  data.u2Length = length;
	  data.puBuffaddr = buffer;
    data.pustatus = &status;
	  handle = DclSerialPort_Open(port, 0);
	  DclSerialPort_Control(handle, SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*)&data);
	  readLen = data.u2RetSize;	

    return readLen;
    
#else
    
#ifdef __MNL_SUPPORT__
    kal_uint8 status;
    status = mtk_mnl_uart_read(buffer, length);
    return status;
#else

    kal_uint16 readLen = 0;
    kal_uint8 status;
    DCL_HANDLE handle;
	UART_CTRL_GET_BYTES_T data;
    
    if (gps_context_p->gps_state != GPS_POWEROFF_STATE)
    {
        gps_uart_rx_sleep_handler();
        if (MOD_GPS == UART_GetOwnerID(port))
        {
#ifdef __GPS_SW_DBG__
            kal_mem_set(buffer, 0x0, length);                
#endif    
            data.u4OwenrId = MOD_GPS;
	        data.u2Length = length;
	        data.puBuffaddr = buffer;
            data.pustatus = &status;
	        handle = DclSerialPort_Open(port, 0);
	        DclSerialPort_Control(handle, SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*)&data);
	        readLen = data.u2RetSize;	
#ifdef __GPS_SW_DBG__
            kal_print_string_trace(MOD_GPS, TRACE_FUNC, "[UART RX] %s", buffer);
#endif    
        }
    }
    return readLen;

#endif

#endif /* __SMART_PHONE_MODEM__ */
}


/*****************************************************************************
 * FUNCTION
 *  GPS_UART_Write
 * DESCRIPTION
 *  GPS task main
 * PARAMETERS
 *  task_entry_ptr      [IN]        task struct pointer 
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 GPS_UART_Write(kal_uint8 port, kal_uint8 *buffer, kal_uint16 length)
{    
#if defined(__SMART_PHONE_MODEM__)

    kal_uint16 writeLen = 0;
    
    DCL_HANDLE handle;
	  UART_CTRL_PUT_BYTES_T data;
	    
    gps_uart_tx_sleep_handler();
       
    data.u4OwenrId = MOD_GPS;
	  data.u2Length = length;
	  data.puBuffaddr = buffer;
	  handle = DclSerialPort_Open(port, 0);
	  DclSerialPort_Control(handle,SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data);
	  writeLen =  data.u2RetSize;
        
    return writeLen;
    
#else
    
#ifdef __MNL_SUPPORT__
    mtk_gps_nmea_input((kal_int8 *)buffer, length);
    return length; // should be no problem, just return the length
#else
    kal_uint16 writeLen = 0;
    if(gps_context_p->gps_state != GPS_POWEROFF_STATE)
    {
        DCL_HANDLE handle;
	    UART_CTRL_PUT_BYTES_T data;
	    
        gps_uart_tx_sleep_handler();
        
        data.u4OwenrId = MOD_GPS;
	    data.u2Length = length;
	    data.puBuffaddr = buffer;
	    handle = DclSerialPort_Open(port, 0);
	    DclSerialPort_Control(handle,SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data);
	    writeLen =  data.u2RetSize;
        
#ifdef __GPS_SW_DBG__
        kal_print_string_trace(MOD_GPS, TRACE_FUNC, "[UART TX] %s", buffer);
#endif  
    }   
    return writeLen;

#endif

#endif /* __SMART_PHONE_MODEM__ */
}

/*****************************************************************************
 * FUNCTION
 *  GPS_SetUART
 * DESCRIPTION
 *  Set the baudrate of UART 
 * PARAMETERS
 *  task_entry_ptr      [IN]        task struct pointer 
 * RETURNS
 *  void
 *****************************************************************************/
void GPS_SetUART(kal_uint32 baudrate, kal_uint32 flow_control_type)
{
    DCL_HANDLE handle;
    UART_CTRL_DCB_T data;
#if defined(__SMART_PHONE_MODEM__)
    data.u4OwenrId = MOD_GPS;	
#else   
 

#ifdef __MNL_SUPPORT__
    data.u4OwenrId = MOD_MNL;	
#else
    data.u4OwenrId = MOD_GPS;	
#endif

#endif /* __SMART_PHONE_MODEM__ */
   	
	data.rUARTConfig.u4Baud = baudrate;
	data.rUARTConfig.u1DataBits = LEN_8;
	data.rUARTConfig.u1StopBits = SB_1;
	data.rUARTConfig.u1Parity = PA_NONE;
	data.rUARTConfig.u1FlowControl = flow_control_type;
	data.rUARTConfig.ucXonChar = 0x11;
	data.rUARTConfig.ucXoffChar = 0x13;
	data.rUARTConfig.fgDSRCheck = (DCL_BOOLEAN)KAL_FALSE;
	
    handle = DclSerialPort_Open(gps_uart_port, 0);
	DclSerialPort_Control(handle, SIO_CMD_SET_DCB_CONFIG, (DCL_CTRL_DATA_T*)&data);
}
/*****************************************************************************
 * FUNCTION
 *  GPS_Get_UART_Port
 * DESCRIPTION
 *  Get the UART port
 * PARAMETERS
 *  task_entry_ptr      [IN]        task struct pointer 
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 GPS_Get_UART_Port(void)
{
#if defined(__SMART_PHONE_MODEM__)

    return gps_uart_port;
    
#else

#ifdef __MNL_SUPPORT__
    return mnl_port;
#else
    return gps_uart_port;
#endif

#endif /* __SMART_PHONE_MODEM__ */
}

#endif /* __GPS_SUPPORT__ */
