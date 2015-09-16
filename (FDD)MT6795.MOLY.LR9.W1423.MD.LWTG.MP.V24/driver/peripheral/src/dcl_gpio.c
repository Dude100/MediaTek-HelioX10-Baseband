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
 *    dcl_gpio.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the GPIO driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_gpio.h"
#include "drv_comm.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "gpio_sw.h"
#include "dcl.h"
#if defined(__AST_TL1_TDD__)
#include"gpio_md.h"
#include "ast_hif_hw.h"
#endif
//#define DCL_GPIO_INTERFACE //add here temp.
//#ifdef  DCL_GPIO_INTERFACE

#if !defined(DRV_GPIO_NOT_EXIST) && !defined(DRV_GPIO_OFF)

#define DCL_GPIO_MAGIC_NUM			0x80000000
#define DCL_GPO_MAGIC_NUM			0x40000000
#define DCL_GPIO_CLK_MAGIC_NUM	0x20000000

#define DCL_GPIO_IS_HANDLE_MAGIC(handle_)       ((handle_)& DCL_GPIO_MAGIC_NUM)
#define DCL_GPIO_GET_DEV(handle_) 	   	      ((handle_)& (~DCL_GPIO_MAGIC_NUM))

#define DCL_GPO_IS_HANDLE_MAGIC(handle_)        ((handle_) & DCL_GPO_MAGIC_NUM)
#define DCL_GPO_GET_DEV(handle_)                ((handle_) & (~DCL_GPO_MAGIC_NUM))

#define DCL_GPIO_CLK_IS_HANDLE_MAGIC(handle_)   ((handle_) & DCL_GPIO_CLK_MAGIC_NUM)
#define DCL_GPIO_CLK_GET_DEV(handle_)           ((handle_) & (~DCL_GPIO_MAGIC_NUM))

extern const kal_uint32 GPIO_CLK_SEL[13];
static kal_uint8 get_mode(kal_uint8 mode);
static kal_uint8 get_clknum(kal_uint8 number);
/*-----------------------------------------------------------------------*
* FUNCTION
*  DclGPIO_Initialize
*
* DESCRIPTION
*  This function is to initialize GPIO module. Note that all the GPIO pin
* will be set to a predefined state.
*
* PARAMETERS
*	DCL_STATUS_OK
*
* RETURNS
*  none
*
*-----------------------------------------------------------------------*/
DCL_STATUS DclGPIO_Initialize(void)
{
   extern void GPIO_init(void);

   GPIO_init();
   return STATUS_OK;
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclGPIO_Open
* DESCRIPTION
*  This function is to open the GPIO module and get a handle. Note that multiple opens are allowed.
*
* PARAMETERS
*	eDev: - only valid for DCL_GPIO,DCL_GPO,DCL_GPIO_CLK.
*	flags: - no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURN VALUES
*	DCL_HANDLE_INVALID: - Open failed.
* other value: - a valid handle
*
*-----------------------------------------------------------------------*/

DCL_HANDLE DclGPIO_Open(DCL_DEV eDev, DCL_FLAGS flags)
{
   if(flags>0xFF)
   {
      ASSERT(0);
      return DCL_HANDLE_INVALID;
   }
   if(eDev==DCL_GPIO)
   {
      return (DCL_GPIO_MAGIC_NUM | flags);
   }
   else if(eDev==DCL_GPO)
   {
      return (DCL_GPO_MAGIC_NUM | flags);
   }
   else if(eDev==DCL_GPIO_CLK)
   {
	   return (DCL_GPIO_CLK_MAGIC_NUM | flags);
   }
   else
   {
      EXT_ASSERT(0,eDev,flags,0);
      return DCL_HANDLE_INVALID;
   }	
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclGPIO_ReadData
*
* DESCRIPTION
*  This function is not supported for the GPIO module now.
*
* PARAMETERS
*	N/A
*
* RETURN VALUES
*	STATUS_UNSUPPORTED: 
*
*-----------------------------------------------------------------------*/
DCL_STATUS DclGPIO_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclGPIO_WriteData
*
* DESCRIPTION
*  This function is not supported for the GPIO module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*-----------------------------------------------------------------------*/
DCL_STATUS DclGPIO_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclGPIO_Configure
*
* DESCRIPTION
*  This function is not supported for the GPIO module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*-----------------------------------------------------------------------*/
DCL_STATUS DclGPIO_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclGPIO_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the GPIO module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*-----------------------------------------------------------------------*/
DCL_STATUS DclGPIO_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclGPIO_Control
*
* DESCRIPTION
*  This function is to send command to control the GPIO module.
*
* PARAMETERS
*	handle - a valid handle return by DclGPIO_Open()
*  cmd   - a control command for GPIO module
*          1. GPIO_CMD_READ: to read the input value from the GPIO port contain in handle.
*          2. GPIO_CMD_WRITE_LOW: to write low to the output of GPIO port contain in handle.
*          3. GPIO_CMD_WRITE_HIGH: to write high to the output of  GPIO port contain in handle.
*          4. GPIO_CMD_SET_MODE_0: to set the mode of the GPIO port contain in handle as mode 0.
*          5. GPIO_CMD_SET_MODE_1: to set the mode of the GPIO port contain in handle as mode 1.
*          6. GPIO_CMD_SET_MODE_2: to set the mode of the GPIO port contain in handle as mode 2.
*          7. GPIO_CMD_SET_MODE_3: to set the mode of the GPIO port contain in handle as mode 3.
*          8. GPIO_CMD_SET_DIR_OUT: to set the direction of the GPIO port as output.
*          9. GPIO_CMD_SET_DIR_IN: to set the direction of the GPIO port as input.
*         10. GPIO_CMD_RETURN_MODE: to get the mode of the GPIO port
*         11. GPIO_CMD_RETURN_DIR: to get the direction of the GPIO port
*         12. GPIO_CMD_RETURN_OUT: to return the output value of the GPIO port
*         13. GPIO_CMD_ENABLE_PULL: to enable the pull resister for a GPIO port
*         14. GPIO_CMD_DISABLE_PULL: to disenable the pull resister for a GPIO port
*         15. GPIO_CMD_SET_PULL_HIGH: to select the pull up for a GPIO port
*         16. GPIO_CMD_SET_PULL_LOW: to select the pull down for a GPIO port
*         17. GPIO_CMD_SET_DINV: to set the inversion of a GPIO port
*         18. GPIO_CMD_SET_DEBUG: to enable or disable debug mode
*         19. GPIO_CMD_SET_CLK_OUT: to set the clock frequency for a clock output
*
*         20. GPO_CMD_RETURN_MODE: to get the mode of the GPO port
*         21. GPO_CMD_RETURN_OUT: to return the output value of the GPO port
*         22. GPO_CMD_WRITE_HIGH: to write high to the output of  GPO port contain in handle.
*         23. GPO_CMD_WRITE_LOW: to write low to the output of GPO port contain in handle.
*         24. GPO_CMD_MODE_SET_0: to set the mode of the GPIO port contain in handle as mode 0.
*         25. GPO_CMD_MODE_SET_1: to set the mode of the GPI1 port contain in handle as mode 1.
*         26. GPO_CMD_MODE_SET_2: to set the mode of the GPI2 port contain in handle as mode 2.
*         27. GPO_CMD_MODE_SET_3: to set the mode of the GPI3 port contain in handle as mode 3.

*         28. GPIO_CMD_SET_DIR_OUT_NO_IRQ_MASK_T: to set the direction of the GPIO port as output without IRQ protect.
*         29. GPIO_CMD_SET_DIR_IN_NO_IRQ_MASK_T:  to set the direction of the GPIO port as input without IRQ protect
*         30. GPIO_CMD_WRITE_HIGH_NO_IRQ_MASK_T:  to write high to the output of  GPIO port contain in handle without IRQ protect.
*         31. GPIO_CMD_WRITE_LOW_NO_IRQ_MASK_T:	  to write low to the output of GPIO port contain in handle without IRQ protect.
*         32. GPIO_CMD_READ_NO_IRQ_MASK_T:		  to read the input value from the GPIO port contain in handle without IRQ protect..

*         33. GPIO_CMD_WRITE_FOR_SPI_T: 
*  data - for 1. GPIO_CMD_READ: 
*          1. GPIO_CMD_READ: pointer to a GPIO_CTRLS structure
*          2. GPIO_CMD_WRITE_LOW:		NULL.
*          3. GPIO_CMD_WRITE_HIGH:		NULL.
*          4. GPIO_CMD_SET_MODE_0:		NULL.
*          5. GPIO_CMD_SET_MODE_1:		NULL.
*          6. GPIO_CMD_SET_MODE_2:		NULL.
*          7. GPIO_CMD_SET_MODE_3:		NULL.
*          8. GPIO_CMD_SET_DIR_OUT:		NULL.
*          9. GPIO_CMD_SET_DIR_IN:		NULL.
*         10. GPIO_CMD_RETURN_MODE: pointer to a GPIO_CTRL_RETURN_MODE_T structure
*         11. GPIO_CMD_RETURN_DIR:  pointer to a GPIO_CTRL_SET_DIR_T structure
*         12. GPIO_CMD_RETURN_OUT:  pointer to a GPIO_CTRL_RETURN_OUT_T structure
*         13. GPIO_CMD_ENABLE_PULL:		NULL.
*         14. GPIO_CMD_DISABLE_PULL:	NULL.
*         15. GPIO_CMD_SET_PULL_HIGH:	NULL.	
*         16. GPIO_CMD_SET_PULL_LOW:	NULL.
*         17. GPIO_CMD_SET_DINV:  pointer to a GPIO_CTRL_SET_DINV_T structure
*         18. GPIO_CMD_SET_DEBUG: pointer to a GPIO_CTRL_SET_DEBUG_T structure
*         19. GPIO_CMD_SET_CLK_OUT: pointer to a GPIO_CTRL_SET_CLK_OUT_T structure
*
*         20. GPO_CMD_RETURN_MODE: pointer to a GPO_CTRL_RETURN_MODE_T structure
*         21. GPO_CMD_RETURN_OUT:  pointer to a GPO_CTRL_RETURN_OUT_T structure
*         22. GPO_CMD_WRITE_HIGH: NULL.
*         23. GPO_CMD_WRITE_LOW:  NULL.
*         24. GPO_CMD_MODE_SET_0: NULL..
*         25. GPO_CMD_MODE_SET_1: NULL..
*         26. GPO_CMD_MODE_SET_2: NULL.
*         27. GPO_CMD_MODE_SET_3: NULL.

*         28. GPIO_CMD_SET_DIR_OUT_NO_IRQ_MASK_T: NULL.
*         29. GPIO_CMD_SET_DIR_IN_NO_IRQ_MASK_T:  NULL.
*         30. GPIO_CMD_WRITE_HIGH_NO_IRQ_MASK_T:  NULL.
*         31. GPIO_CMD_WRITE_LOW_NO_IRQ_MASK_T:	  NULL.
*         32. GPIO_CMD_READ_NO_IRQ_MASK_T:		  pointer to a GPIO_CTRLS structure

*         33. GPIO_CMD_WRITE_FOR_SPI_T: pointer to
* RETURNS
*	STATUS_OK - command is executed successfully.
*	STATUS_FAIL - command is failed.
*  STATUS_INVALID_CMD - The command is invalid.
*  STATUS_INVALID_HANDLE - The handle is invalid.
*  STATUS_INVALID_CTRL_DATA - The ctrl data is not valid.
*-----------------------------------------------------------------------*/
DCL_STATUS DclGPIO_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
   kal_char port; 
   port= 0x000000FF & handle;

   if(DCL_GPIO_IS_HANDLE_MAGIC(handle))
   {
	   switch(cmd)
	   {
         case GPIO_CMD_READ:
         {
            GPIO_CTRL_READ_T   *prRead;
            prRead = &(data->rRead);
            prRead->u1IOData = GPIO_ReadIO(port);
            break;
         }
         case GPIO_CMD_WRITE_LOW:
         {
		         GPIO_WriteIO(GPIO_IO_LOW, port);
            break;
         }
         case GPIO_CMD_WRITE_HIGH:
         {
            GPIO_WriteIO(GPIO_IO_HIGH, port);
            break;
         } 
         case GPIO_CMD_SET_MODE_0:
         {
            GPIO_ModeSetup(port, GPIO_MODE_0);
            break;
         }
         case GPIO_CMD_SET_MODE_1:
         {
            GPIO_ModeSetup(port, GPIO_MODE_1);
            break;
         }
         case GPIO_CMD_SET_MODE_2:
         {
            GPIO_ModeSetup(port, GPIO_MODE_2);
            break;		   	  	
         }
         case GPIO_CMD_SET_MODE_3:
         {
            GPIO_ModeSetup(port, GPIO_MODE_3);
            break;			   	  	
         }
         case GPIO_CMD_SET_MODE_4: //mode4-7 only for chip support more than 3bit mode control.
         {
            GPIO_ModeSetup(port, GPIO_MODE_4);
            break;
         }
         case GPIO_CMD_SET_MODE_5:
         {
            GPIO_ModeSetup(port, GPIO_MODE_5);
            break;
         }
         case GPIO_CMD_SET_MODE_6:
         {
            GPIO_ModeSetup(port, GPIO_MODE_6);
            break;	
         }
         case GPIO_CMD_SET_MODE_7:
         {
            GPIO_ModeSetup(port, GPIO_MODE_7);
            break;	
         } 
        case GPIO_CMD_SET_MODE_8:
         {
            GPIO_ModeSetup(port, GPIO_MODE_8);
            break;	
         } 	 	  
         case GPIO_CMD_SET_DIR_OUT:
         {
            GPIO_InitIO(GPIO_DIR_OUT,port);
            break;
         }
         case GPIO_CMD_SET_DIR_IN:
         {
            GPIO_InitIO(GPIO_DIR_IN,port);
            break;		   			
         }
         case GPIO_CMD_RETURN_MODE:
         {
            GPIO_CTRL_RETURN_MODE_T   *prReturnMode;
            prReturnMode = &(data->rReturnMode);
            prReturnMode->u1RetMode = GPIO_ReturnMode(port);
            break;
         }
         case GPIO_CMD_RETURN_DIR:
         {
            GPIO_CTRL_RETURN_DIR_T   *prReturnDir;
            prReturnDir = &(data->rReturnDir);
            prReturnDir->u1RetDirData =GPIO_ReturnDir(port);
            break;
         }
         case GPIO_CMD_RETURN_OUT:
         {
            GPIO_CTRL_RETURN_OUT_T   *prReturnOut;
            prReturnOut = &(data->rReturnOut);
            prReturnOut->u1RetOutData = GPIO_ReturnDout(port);
            break;
         }
         case GPIO_CMD_ENABLE_PULL:
         {
            GPIO_PullenSetup(port, (kal_bool)GPIO_PULL_ENABLE);
            break;
         }
         case GPIO_CMD_DISABLE_PULL:
         {
            GPIO_PullenSetup(port, (kal_bool)GPIO_PULL_DISABLE);
            break;
         }
         case GPIO_CMD_SET_PULL_HIGH:
         {
            GPIO_PullSelSetup(port,(kal_bool) GPIO_PULL_HIGH);
            break;
         }
         case GPIO_CMD_SET_PULL_LOW:
         {
            GPIO_PullSelSetup(port, (kal_bool)GPIO_PULL_LOW);
            break;
         }   
         case GPIO_CMD_SET_DINV:
         {
            GPIO_CTRL_SET_DINV_T   *prSetDinv;
            prSetDinv = &(data->rSetDinv);
            GPIO_DinvSetup(port,(kal_bool)( prSetDinv->fgSetDinv));
            break;
         }
         case GPIO_CMD_SET_DEBUG:
         {
            GPIO_CTRL_SET_DEBUG_T   *prSetDebug;
            prSetDebug = &(data->rSetDebug);
            GPIO_SetDebugMode((kal_bool)(prSetDebug->fgSetDebug));
            break;
         }
         #ifdef __CUST_NEW__
         case GPIO_CMD_SET_DIR_OUT_NO_IRQ_MASK: 
         {
            GPIO_InitIO_FAST(GPIO_DIR_OUT,port);
            break;
         }
         case GPIO_CMD_SET_DIR_IN_NO_IRQ_MASK:
         {
            GPIO_InitIO_FAST(GPIO_DIR_IN,port);
            break;
         }
         case GPIO_CMD_WRITE_HIGH_NO_IRQ_MASK:
         {
            GPIO_WriteIO_FAST(GPIO_IO_HIGH,port);
            break;
         }
         case GPIO_CMD_WRITE_LOW_NO_IRQ_MASK:
         {
            GPIO_WriteIO_FAST(GPIO_IO_LOW,port);
            break;
         }
		  case GPIO_CMD_READ_NO_IRQ_MASK:
         {
            GPIO_CTRL_READ_T   *prRead;
            prRead = &(data->rRead);
            prRead->u1IOData = GPIO_ReadIO_FAST(port);
            break;
         }
         #endif
         case GPIO_CMD_WRITE_FOR_SPI:
         {
            GPIO_CTRL_WRITE_FOR_SPI_T *prWrite;
            prWrite = &(data->rWriteSpi);
            GPIO_WriteIO_FAST2(prWrite->data,prWrite->no,prWrite->remainder_shift);
            break;
         }		
         default:
            EXT_ASSERT(0,handle,cmd,0);
            return STATUS_INVALID_CMD;
      }
   }
   else if(DCL_GPO_IS_HANDLE_MAGIC(handle))
   {
      switch(cmd)
      {
         case GPO_CMD_MODE_SET_0:
         {
            GPO_ModeSetup(port,GPO_MODE_0);
            break;
         }
         case GPO_CMD_MODE_SET_1:
         {
            GPO_ModeSetup(port,GPO_MODE_1);
            break;
         }
         case GPO_CMD_MODE_SET_2:
         {
            GPO_ModeSetup(port,GPO_MODE_2);
            break;
         }
         case GPO_CMD_MODE_SET_3:
         {
            GPO_ModeSetup(port,GPO_MODE_3);
            break;
         }
         case GPO_CMD_WRITE_LOW :
         {
            GPO_WriteIO(port,GPO_IO_LOW);
            break;
         }
         case GPO_CMD_WRITE_HIGH:
         {
            GPO_WriteIO(port,GPO_IO_HIGH);
            break;
         }
         case GPO_CMD_RETURN_OUT:
         {
            GPO_CTRL_RETURN_OUT_T   *prReturnOut;
            prReturnOut = &(data->oReturnOut);
            prReturnOut->u1RetOutData = GPO_ReturnDout(port);
            break;
         }
         case GPO_CMD_RETURN_MODE:
         {
            GPO_CTRL_RETURN_MODE_T   *prReturnMode;
            prReturnMode = &(data->oReturnMode);
            prReturnMode->u1RetMode = GPO_ReturnMode(port);
            break;
         }
         default:
            EXT_ASSERT(0,handle,cmd,0);
            return STATUS_INVALID_CMD;
      }
   }
   else if (DCL_GPIO_CLK_IS_HANDLE_MAGIC(handle))
   {
      switch(cmd)
      {
         case GPIO_CMD_SET_CLK_OUT:
         {
            kal_uint8 mode=0;
            kal_uint8 clknum=0;
            GPIO_CTRL_SET_CLK_OUT_T   *prSetClkOut;
            prSetClkOut = &(data->rSetClkOut);
            mode = get_mode(prSetClkOut->u2Mode);
            clknum=get_clknum(prSetClkOut->u2ClkNum);
            GPIO_SetClkOut(clknum,(gpio_clk_mode)mode);
            break;
         }
         case GPIO_CMD_SET_CLK_DIV:
         {
            kal_uint8 clknum=0;
            GPIO_CTRL_SET_CLK_DIV_T *prSetClkDiv;
            prSetClkDiv= &(data->rSetClkDiv);
            clknum=get_clknum(prSetClkDiv->u2ClkNum);
            GPIO_SetClkDiv(clknum,prSetClkDiv->u2Div);
            break;
         }
         default:
            EXT_ASSERT(0,handle,cmd,0);
            return STATUS_INVALID_CMD;
      }
   }
   else
   {
      EXT_ASSERT(0,handle,cmd,0);
      return STATUS_INVALID_DCL_HANDLE;
   }  
   return STATUS_OK;
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  DclGPIO_Close
*
* DESCRIPTION
*  This function is not supported for the GPIO module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*-----------------------------------------------------------------------*/
DCL_STATUS DclGPIO_Close(DCL_HANDLE handle)
{
   return STATUS_OK;
}

static kal_uint8 get_mode(kal_uint8 mode)
{
   if(mode <GPIO_MAGIC_NUM)
      return mode;
   else if(mode == mode_f32k_ck)
   {
      #if defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6253E) || defined(DRV_GPIO_REG_AS_6253E_1)
      mode = 0x04;
      #elif defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235)
      mode = 0x06;
      #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6270A)
      mode = 0x40; 
      #elif defined(DRV_GPIO_REG_AS_6236)
      mode = 0x40; //32KHz
    	#elif defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6256)
      mode = 0x0C;
      #elif defined(DRV_GPIO_REG_AS_6276)
         #if defined(MT6276_S01)
         mode = 0xE;
         #else 
         mode = 0x2;
         #endif
      #elif defined(DRV_GPIO_REG_AS_6251)
      mode = 0x03;
      #endif
      return mode;
   }
   else
   {
      ASSERT(0);
   }		
   return mode;
}

static kal_uint8 get_clknum(kal_uint8 number)
{
	#if defined(MT6276_S01)
	//  kal_uint8 clock_number=0;
	// clock_number=GPIO_CLK_SEL[number-1]+1;
	return (kal_uint8)(GPIO_CLK_SEL[number-1]+1);
	#else
	return 	number;
	#endif	
}

#else /*!defined(DRV_GPIO_OFF)*/

//#if defined(DRV_GPIO_SP_ON)
  #if defined(DRV_GPIO_SP_ON) && (defined(__AST_TL1_TDD__) || defined(__UMTS_FDD_MODE__))
/*************for  smartphone MD user************************/
#define DCL_GPIO_MAGIC_NUM			0x80000000
#define DCL_GPO_MAGIC_NUM			0x40000000
#define DCL_GPIO_CLK_MAGIC_NUM	0x20000000
#define DCL_GPIO_MD_MAGIC_NUMBER  0X00001000
#define DCL_GPIO_IS_HANDLE_MAGIC(handle_)       ((handle_)& DCL_GPIO_MAGIC_NUM)
#define DCL_GPIO_GET_DEV(handle_) 	   	      ((handle_)& (~DCL_GPIO_MAGIC_NUM))

#define DCL_GPO_IS_HANDLE_MAGIC(handle_)        ((handle_) & DCL_GPO_MAGIC_NUM)
#define DCL_GPO_GET_DEV(handle_)                ((handle_) & (~DCL_GPO_MAGIC_NUM))

#define DCL_GPIO_CLK_IS_HANDLE_MAGIC(handle_)   ((handle_) & DCL_GPIO_CLK_MAGIC_NUM)
#define DCL_GPIO_CLK_GET_DEV(handle_)           ((handle_) & (~DCL_GPIO_MAGIC_NUM))


extern const kal_uint32 GPIO_CLK_SEL[13];
//static kal_uint8 get_mode(kal_uint8 mode);
static kal_uint8 get_clknum(kal_uint8 number);
kal_uint8  MD_QUERY_GPIO[30]={0};
/*
static kal_uint8 get_mode(kal_uint8 mode)
{
   if(mode <GPIO_MAGIC_NUM)
	  return mode;
   else if(mode == mode_f32k_ck)
   {
   #if defined(DRV_GPIO_REG_AS_6223) || defined(DRV_GPIO_REG_AS_6253T) || defined(DRV_GPIO_REG_AS_6253E) || defined(DRV_GPIO_REG_AS_6253E_1)
	  mode = 0x04;
   #elif defined(DRV_GPIO_REG_AS_6238) || defined(DRV_GPIO_REG_AS_6235)
	  mode = 0x06;
   #elif defined(DRV_GPIO_REG_AS_6268A) || defined(DRV_GPIO_REG_AS_6268) || defined(DRV_GPIO_REG_AS_6270A)
	  mode = 0x40; 
   #elif defined(DRV_GPIO_REG_AS_6236)
	  mode = 0x40; //32KHz
	 #elif defined(DRV_GPIO_REG_AS_6255) || defined(DRV_GPIO_REG_AS_6256)
	  mode = 0x0C;
   #elif defined(DRV_GPIO_REG_AS_6276)
	  #if defined(MT6276_S01)
		 mode = 0xE;
	  #else 
		 mode = 0x2;
	  #endif
   #elif defined(DRV_GPIO_REG_AS_6251)
	  mode = 0x03;
   #endif
	  return mode;
   }
   else
   {
	  ASSERT(0);
   }		
   return mode;
}
*/
static kal_uint8 get_clknum(kal_uint8 number)
{
 #if defined(MT6276_S01)
	//	kal_uint8 clock_number=0;
	// clock_number=GPIO_CLK_SEL[number-1]+1;
	return (kal_uint8)(GPIO_CLK_SEL[number-1]+1);
 #else
	return	number;
 #endif  
}


DCL_STATUS DclGPIO_Initialize(void)
{
   return STATUS_FAIL;
}

DCL_HANDLE DclGPIO_Open(DCL_DEV eDev, DCL_FLAGS flags)
{
	DCL_FLAGS flags1;
#ifdef __ANDROID_MODEM__
	   if(flags>0xff && flags< GPIO_AST_HIF_CS)
		  return DCL_HANDLE_INVALID;
#endif
	if(flags<0xff)
		
		{
    #if (!defined(GPIO_AST_DEBUG_ON) && defined(__ANDROID_MODEM__))
    kal_uint32 i;
    for(i=0;i<sizeof(MD_QUERY_GPIO)/sizeof(*MD_QUERY_GPIO);i++)
    {
      if(MD_QUERY_GPIO[i]==flags)
        break;
    }
    if(i==sizeof(MD_QUERY_GPIO)/sizeof(*MD_QUERY_GPIO))  
        ASSERT(0);
    #endif
			
			   if(eDev==DCL_GPIO)
	   {
		  return (DCL_GPIO_MAGIC_NUM | flags);
	   }
	   else if(eDev==DCL_GPO)
	   {
		  return (DCL_GPO_MAGIC_NUM | flags);
	   }
	   else if(eDev==DCL_GPIO_CLK)
	   {
		   return (DCL_GPIO_CLK_MAGIC_NUM | flags);
	   }
	   else
	   {
		  EXT_ASSERT(0,eDev,flags,0);
		  return DCL_HANDLE_INVALID;
	   }	
	   }
#ifdef __ANDROID_MODEM__	
	   else
		{
	   flags&=~DCL_GPIO_MD_MAGIC_NUMBER;  //get gpio enum
	   
		flags1=MD_get_gpio_pin_number(flags);  //fet  AP gpio pin numser
	   
   MD_QUERY_GPIO[flags]=flags1;
	   
	   if(eDev==DCL_GPIO)
	   {
		  return (DCL_GPIO_MAGIC_NUM | flags1);
	   }
	   else if(eDev==DCL_GPO)
{
		  return (DCL_GPO_MAGIC_NUM | flags1);
	   }
	   else if(eDev==DCL_GPIO_CLK)
	   {
		   return (DCL_GPIO_CLK_MAGIC_NUM | flags1);
	   }
	   else
	   {
		  EXT_ASSERT(0,eDev,flags,0);
   return DCL_HANDLE_INVALID;
}
	  }
#endif

}

DCL_STATUS DclGPIO_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

DCL_STATUS DclGPIO_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

DCL_STATUS DclGPIO_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
   return STATUS_UNSUPPORTED;
}

DCL_STATUS DclGPIO_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
   return STATUS_FAIL;
}

DCL_STATUS DclGPIO_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	   kal_char port; 
	   port= 0x000000FF & handle;

	   if(DCL_HANDLE_INVALID==handle)
   return STATUS_FAIL;
	
	   if(DCL_GPIO_IS_HANDLE_MAGIC(handle))
	   {
		   switch(cmd)
		   {
			 case GPIO_CMD_READ:
			 {
				GPIO_CTRL_READ_T   *prRead;
				prRead = &(data->rRead);
				prRead->u1IOData = GPIO_ReadIO(port);
				break;
			 }
			 case GPIO_CMD_WRITE_LOW:
			 {
				GPIO_MD_WriteIO(GPIO_IO_LOW, port);
				break;
			 }
			 case GPIO_CMD_WRITE_HIGH:
			 {
				GPIO_MD_WriteIO(GPIO_IO_HIGH, port);
				break;
			 } 
			 case GPIO_CMD_SET_MODE_0:
			 {
				GPIO_MD_ModeSetup(port, GPIO_MODE_0);
				break;
			 }
			 case GPIO_CMD_SET_MODE_1:
			 {
				GPIO_MD_ModeSetup(port, GPIO_MODE_1);
				break;
			 }
			 case GPIO_CMD_SET_MODE_2:
			 {
				GPIO_MD_ModeSetup(port, GPIO_MODE_2);
				break;				
			 }
			 case GPIO_CMD_SET_MODE_3:
			 {
				GPIO_MD_ModeSetup(port, GPIO_MODE_3);
				break;					
			 }
			 case GPIO_CMD_SET_MODE_4: //mode4-7 only for chip support more than 3bit mode control.
			 {
				GPIO_MD_ModeSetup(port, GPIO_MODE_4);
				break;
			 }
			 case GPIO_CMD_SET_MODE_5:
			 {
				GPIO_MD_ModeSetup(port, GPIO_MODE_5);
				break;
			 }
			 case GPIO_CMD_SET_MODE_6:
			 {
				GPIO_MD_ModeSetup(port, GPIO_MODE_6);
				break;	
			 }
			 case GPIO_CMD_SET_MODE_7:
			 {
				GPIO_MD_ModeSetup(port, GPIO_MODE_7);
				break;	
			 } 
			case GPIO_CMD_SET_MODE_8:
			 {
				GPIO_MD_ModeSetup(port, GPIO_MODE_8);
				break;	
			 }		  
			 case GPIO_CMD_SET_DIR_OUT:
			 {
				GPIO_MD_InitIO(GPIO_DIR_OUT,port);
				break;
			 }
			 case GPIO_CMD_SET_DIR_IN:
			 {
				GPIO_MD_InitIO(GPIO_DIR_IN,port);
				break;					
			 }
			 case GPIO_CMD_ENABLE_PULL:
			 {
				GPIO_MD_PullenSetup(port, (kal_bool)GPIO_PULL_ENABLE);
				break;
			 }
			 case GPIO_CMD_DISABLE_PULL:
			 {
				GPIO_MD_PullenSetup(port, (kal_bool)GPIO_PULL_DISABLE);
				break;
			 }
			 case GPIO_CMD_SET_PULL_HIGH:
			 {
				GPIO_PullSelSetup(port,(kal_bool) GPIO_PULL_HIGH);
				break;
			 }
			 case GPIO_CMD_SET_PULL_LOW:
			 {
				GPIO_MD_PullSelSetup(port, (kal_bool)GPIO_PULL_LOW);
				break;
			 }	 
			 case GPIO_CMD_SET_DINV:
			 {
				GPIO_CTRL_SET_DINV_T   *prSetDinv;
				prSetDinv = &(data->rSetDinv);
				GPIO_MD_DinvSetup(port,(kal_bool)( prSetDinv->fgSetDinv));
				break;
			 }

			 case GPIO_CMD_GET_AP_PIN:
			 {
			 	GPIO_CTRL_RETURN_AP_T  *prGetApData;
				prGetApData=&(data->rReturnAp);
				prGetApData->u1RetApData=port;
				break;
			 }
				
         #ifdef __CUST_NEW__
			 case GPIO_CMD_SET_DIR_OUT_NO_IRQ_MASK: 
			 {
				GPIO_InitIO_FAST(GPIO_DIR_OUT,port);
				break;
			 }
			 case GPIO_CMD_SET_DIR_IN_NO_IRQ_MASK:
			 {
				GPIO_InitIO_FAST(GPIO_DIR_IN,port);
				break;
			 }
			 case GPIO_CMD_WRITE_HIGH_NO_IRQ_MASK:
			 {
				GPIO_WriteIO_FAST(GPIO_IO_HIGH,port);
				break;
			 }
			 case GPIO_CMD_WRITE_LOW_NO_IRQ_MASK:
			 {
				GPIO_WriteIO_FAST(GPIO_IO_LOW,port);
				break;
			 }
			  case GPIO_CMD_READ_NO_IRQ_MASK:
			 {
				GPIO_CTRL_READ_T   *prRead;
				prRead = &(data->rRead);
				prRead->u1IOData = GPIO_ReadIO_FAST(port);
				break;
			 }
         #endif
			 case GPIO_CMD_WRITE_FOR_SPI:
			 {
				GPIO_CTRL_WRITE_FOR_SPI_T *prWrite;
				prWrite = &(data->rWriteSpi);
				GPIO_WriteIO_FAST2(prWrite->data,prWrite->no,prWrite->remainder_shift);
				break;
			 }		
			 default:
				EXT_ASSERT(0,handle,cmd,0);
				return STATUS_INVALID_CMD;
		  }
	   }
	   else if(DCL_GPO_IS_HANDLE_MAGIC(handle))
	   {
		  switch(cmd)
		  {
			 case GPO_CMD_MODE_SET_0:
			 {
				GPO_ModeSetup(port,GPO_MODE_0);
				break;
			 }
			 case GPO_CMD_MODE_SET_1:
			 {
				GPO_ModeSetup(port,GPO_MODE_1);
				break;
			 }
			 case GPO_CMD_MODE_SET_2:
			 {
				GPO_ModeSetup(port,GPO_MODE_2);
				break;
			 }
			 case GPO_CMD_MODE_SET_3:
			 {
				GPO_ModeSetup(port,GPO_MODE_3);
				break;
			 }
			 case GPO_CMD_WRITE_LOW :
			 {
				GPO_WriteIO(port,GPO_IO_LOW);
				break;
			 }
			 case GPO_CMD_WRITE_HIGH:
			 {
				GPO_WriteIO(port,GPO_IO_HIGH);
				break;
			 }
			 case GPO_CMD_RETURN_OUT:
			 {
				GPO_CTRL_RETURN_OUT_T	*prReturnOut;
				prReturnOut = &(data->oReturnOut);
				prReturnOut->u1RetOutData = GPO_ReturnDout(port);
				break;
			 }
			 case GPO_CMD_RETURN_MODE:
			 {
				GPO_CTRL_RETURN_MODE_T	 *prReturnMode;
				prReturnMode = &(data->oReturnMode);
				prReturnMode->u1RetMode = GPO_ReturnMode(port);
				break;
			 }
			 default:
				EXT_ASSERT(0,handle,cmd,0);
				return STATUS_INVALID_CMD;
		  }
	   }
	   else if (DCL_GPIO_CLK_IS_HANDLE_MAGIC(handle))
	   {
		  switch(cmd)
		  {

			 case GPIO_CMD_SET_CLK_DIV:
			 {
				kal_uint8 clknum=0;
				GPIO_CTRL_SET_CLK_DIV_T *prSetClkDiv;
				prSetClkDiv= &(data->rSetClkDiv);
				clknum=get_clknum(prSetClkDiv->u2ClkNum);
				GPIO_SetClkDiv(clknum,prSetClkDiv->u2Div);
				break;
			 }
			 default:
				EXT_ASSERT(0,handle,cmd,0);
				return STATUS_INVALID_CMD;
		  }
	   }
	   else
	   {
		  EXT_ASSERT(0,handle,cmd,0);
		  return STATUS_INVALID_DCL_HANDLE;
	   }  
	   return STATUS_OK;
}

DCL_STATUS DclGPIO_Close(DCL_HANDLE handle)
{
  	   if(DCL_HANDLE_INVALID==handle)
   return STATUS_FAIL;
	   else
	   	 return STATUS_OK;
}

 #else
   DCL_STATUS DclGPIO_Initialize(void)    //for FDD use
{
   return STATUS_FAIL;
}

DCL_HANDLE DclGPIO_Open(DCL_DEV dev, DCL_FLAGS flags)
{
   return DCL_HANDLE_INVALID;
}

DCL_STATUS DclGPIO_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

DCL_STATUS DclGPIO_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

DCL_STATUS DclGPIO_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
   return STATUS_UNSUPPORTED;
}

DCL_STATUS DclGPIO_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
   return STATUS_FAIL;
}

DCL_STATUS DclGPIO_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
   return STATUS_FAIL;
}

DCL_STATUS DclGPIO_Close(DCL_HANDLE handle)
{
   return STATUS_FAIL;
}
  #endif
 // #endif //#if defined(DRV_GPIO_SP_ON)
 
#endif /*!defined(DRV_GPIO_OFF)*/

