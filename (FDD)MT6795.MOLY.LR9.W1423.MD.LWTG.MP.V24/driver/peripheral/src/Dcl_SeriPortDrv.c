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
//#include "uart_sw.h"


#include "kal_public_api.h"
#include "kal_general_types.h"
    
#define UART_DEV_CNT  (uart_max_port - uart_port1) //subtract uart1, in case uart1 != 0 in future.

#define SIO_DEV_TYPE_CNT ( DCL_UART_DEV_TYPE_MAX-DCL_UART_TYPE)

static SIO_TYPE_T SIO_DEV_Drv_Index[UART_DEV_CNT];
static SeriPort_HANLDER_CB SIO_Dev_Driver[SIO_DEV_TYPE_CNT];


#define DCL_UART_MAGIC_NUM  0x40000000
#define DCL_UART_IS_HANDLE_MAGIC(handl_) ((handl_)& DCL_UART_MAGIC_NUM)
#define DCL_UART_GET_DEV(handle_) ((handle_) & (~DCL_UART_MAGIC_NUM))



 
extern Seriport_HANDLER_T Uart_Drv_Handler;

//add in k2 md2 6589, wr8 uart register API name is different from moly
DCL_STATUS DclSerialPort_RegisterCallback(DCL_HANDLE handle, Seriport_HANDLER_T* uart_handler_cb)
{
    DCL_STATUS  status;

	status=DclSerialPort_DrvRegisterCb(handle,uart_handler_cb);

	return status;
}
/*

DCL_STATUS DclSerialPort_Initialize(void)
{
	return STATUS_OK;
}

DCL_HANDLE DclSerialPort_Open(DCL_DEV dev, DCL_FLAGS flags)
{

	if(dev>uart_max_port)//if((dev<uart_port1) ||(dev>uart_max_port))    remove for build warning,beasese this  enum can't < 0
		return STATUS_INVALID_DEVICE;

	if(uart_port_null == dev)
		return STATUS_INVALID_DEVICE;
		
	 return (DCL_UART_MAGIC_NUM | dev);
}

DCL_STATUS DclSerialPort_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_OK;
}

DCL_STATUS DclSerialPort_RegisterCallback(DCL_HANDLE handle, Seriport_HANDLER_T* uart_handler_cb)
{
	DCL_DEV Device = uart_max_port;
	DCL_UINT8 TypeIndex;
	
 	if(handle == STATUS_INVALID_DEVICE)
 		return STATUS_FAIL;
 			
	if (!DCL_UART_IS_HANDLE_MAGIC(handle))
	  {
		 ASSERT(0);
		 return STATUS_INVALID_DCL_HANDLE;
	  }
	
	Device = DCL_UART_GET_DEV(handle);
	if(Device > UART_DEV_CNT)//if((Device<0)||(Device > UART_DEV_CNT))  remove for build warning,beasese this  enum can't < 0
		return  STATUS_FAIL; 
	
	SIO_DEV_Drv_Index[Device] = uart_handler_cb->DevType; 
	TypeIndex = uart_handler_cb->DevType;
	
	SIO_Dev_Driver[TypeIndex]= uart_handler_cb->SeriportHandlerCb;
	 
	return STATUS_OK;
}


DCL_STATUS DclSerialPort_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{ 
	DCL_DEV Device ;
	SIO_TYPE_T type;
	if(handle == STATUS_INVALID_DEVICE)
 		return STATUS_FAIL;
 			
	 if (!DCL_UART_IS_HANDLE_MAGIC(handle))
   {
      ASSERT(0);
      return STATUS_INVALID_DCL_HANDLE;
   }
 					
 Device = DCL_UART_GET_DEV(handle);
  if(Device > UART_DEV_CNT)// if((Device<0)||(Device > UART_DEV_CNT)) remove for build warning,beasese this  enum can't < 0
		return  STATUS_FAIL; 
 
 type = SIO_DEV_Drv_Index[Device];
 
// if the uart driver not init, here will issue assert
 if(type == DCL_UART_TYPE)
 	{
 	if(SIO_Dev_Driver[type] != Uart_Drv_Handler.SeriportHandlerCb)//maybe bootup trace
 	     EXT_ASSERT(0, (kal_uint32)type, (kal_uint32)Device,  (kal_uint32)handle);//please check weather called UART_Boot_Trace_Release(0),when bootup init
 			}
  return  SIO_Dev_Driver[type](Device, cmd, data);
	
}

DCL_STATUS DclSerialPort_Close(DCL_HANDLE handle)
{
	return STATUS_OK;
}

*/




