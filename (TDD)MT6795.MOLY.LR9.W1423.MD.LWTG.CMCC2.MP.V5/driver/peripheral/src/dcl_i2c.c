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
 *    dcl_i2c.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the I2C driver.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_features.h"
#include "drv_comm.h"

#include "dcl.h"

#include "kal_general_types.h"
#include "dcl_i2c_owner.h"
#include "i2c.h"
#include "kal_public_api.h"

#if (!defined(DRV_I2C_OFF) && defined(DCL_I2C_INTERFACE)) //&& !defined(__MODEM_COMPONENT__ ) && !defined(__MODEM_PRODUCT__))

// Global variable for DCL I2C API usage
#define DCL_I2C_DEV_MAGIC_NUM		(0x50000000)
#define MAX_DCL_I2C_HANDLE			DCL_I2C_NUM_OF_OWNER

extern i2c_handle_struct i2c_handle[DCL_I2C_NUM_OF_OWNER];
extern i2c_status_struct dcl_i2c_status;
extern kal_bool dcl_i2c_DMA_check_tx_buffer_cacheability(kal_uint32 addr, kal_uint32 datalen);
extern kal_bool dcl_i2c_DMA_check_rx_buffer_cacheability(kal_uint32 addr, kal_uint32 datalen);
extern kal_bool dcl_i2c_DMA_rx_done_cacheability(kal_uint32 addr, kal_uint32 datalen);

DCL_STATUS _ConvertDclReturnStatus(I2C_TRANSACTION_RESULT result)
{
    if (result == I2C_TRANSACTION_COMPLETE)
    {
        return STATUS_OK;
    }
    else
    {
        if (result == I2C_TRANSACTION_IS_BUSY)
            return STATUS_DEVICE_IS_BUSY;
        else if (result == I2C_TRANSACTION_ACKERR)
            return STATUS_ACKERR;
        else if (result == I2C_TRANSACTION_HS_NACKERR)
            return STATUS_HS_NACKERR;
        else
            return STATUS_FAIL;
    }

    //return STATUS_OK;
}


/*************************************************************************
* FUNCTION
*  DclSI2C_Initialize
*
* DESCRIPTION
*  This function is to initialize S/W I2C module
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS DclSI2C_Initialize(void)
{
	//*/ DclSI2C_Initialize() should be called only once, when system init /*//
	dcl_i2c_init();

	return STATUS_OK;
}

/*************************************************************************
* FUNCTION
*  DclSI2C_Open
*
* DESCRIPTION
*  This function is to open the I2C module and return a handle
*
* PARAMETERS
*  dev: only valid for DCL_I2C
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed
*  Other value: A valid handle
*
*************************************************************************/

DCL_HANDLE DclSI2C_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	kal_uint32 i2c_owner = flags & 0xFF;  //*/ DCL_I2C_OWNER should be transfered through the low 8bit of flags /*//
	
	if (i2c_handle[i2c_owner].i2c_config.Fast_Mode_Speed)  //*/ when system init or called DclSI2C_Close(), config->Fast_Mode_Speed == 0 /*// 
	{
		return DCL_HANDLE_OCCUPIED;		//*/ This Handle has been opened /*//
	}
			
	//*/ Tricky! when != 0, indicate that the owner has owned a handle, to avoid one owner call DclSI2C_Open() more than once. /*//
	i2c_handle[i2c_owner].i2c_config.Fast_Mode_Speed = 1;
		
	return (DCL_I2C_DEV_MAGIC_NUM | i2c_owner);
}

/*************************************************************************
* FUNCTION
*  DclSI2C_ReadData
*
* DESCRIPTION
*  This function is not supported for the I2C module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclSI2C_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options){
	return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclSI2C_WriteData
*
* DESCRIPTION
*  This function is not supported for the I2C module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclSI2C_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options){
	return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclSI2C_Configure
*
* DESCRIPTION
*  This function is to configure the I2C module.
*
* PARAMETERS
*  handle: the returned handle value of DclSI2C_Open
*  configure: a structure which include the I2C configuration.  
*
* RETURNS
*  STATUS_OK: Successfully configure I2C module.
*  STATUS_INVALID_DCL_HANDLE: It's a invalid handle.
*  STATUS_NOT_OPENED: The module has not been opened.
*  STATUS_INVALID_CONFIGURATION: The configuration is invalid.
*
*************************************************************************/
DCL_STATUS DclSI2C_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure){

	// Check magic number
	if ((handle & DCL_I2C_DEV_MAGIC_NUM) != DCL_I2C_DEV_MAGIC_NUM)
	{
		//ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}

	{
		I2C_CONFIG_T* prI2CConfig = (I2C_CONFIG_T*) configure;
		DCL_I2C_OWNER i2c_owner = prI2CConfig->eOwner;
		
		//*/ check if the handle is opened /*//
		if (i2c_handle[i2c_owner].i2c_config.Fast_Mode_Speed == 0)
		{
			return STATUS_NOT_OPENED;
		}
		// Check owner
		if (i2c_owner >= (kal_uint8)DCL_I2C_NUM_OF_OWNER )
		{
			return STATUS_INVALID_CONFIGURATION;
		}

		i2c_handle[i2c_owner].i2c_config.get_handle_wait = (kal_bool)prI2CConfig->fgGetHandleWait;

 		i2c_handle[i2c_owner].i2c_config.slave_address = prI2CConfig->u1SlaveAddress;
 		i2c_handle[i2c_owner].i2c_config.delay_len = prI2CConfig->u1DelayLen;
 		
 		//*/ sccb_xxx will be replaced by i2c_xxx /*//
		i2c_handle[i2c_owner].i2c_config.transaction_mode = (I2C_TRANSACTION_MODE)prI2CConfig->eTransactionMode;
		
		i2c_handle[i2c_owner].i2c_config.Fast_Mode_Speed = prI2CConfig->u4FastModeSpeed;
		i2c_handle[i2c_owner].i2c_config.HS_Mode_Speed = prI2CConfig->u4HSModeSpeed;
		
		#if (defined(DRV_I2C_DMA_ENABLED))
		i2c_handle[i2c_owner].i2c_config.is_DMA_enabled = (kal_bool)(prI2CConfig->fgEnableDMA);
		#else
		if (prI2CConfig->fgEnableDMA)
		{
			//ASSERT(0);
			return STATUS_DEVICE_NOT_SUPPORT_DMA; //*/ user config fgEnableDMA == TRUE, but we do not support /*//
		}
		#endif // #if (defined(DRV_I2C_DMA_ENABLED))
          
        dcl_i2c_set_transaction_speed(i2c_owner,i2c_handle[i2c_owner].i2c_config.transaction_mode,&(i2c_handle[i2c_owner].i2c_config.Fast_Mode_Speed),&(i2c_handle[i2c_owner].i2c_config.HS_Mode_Speed));          

        prI2CConfig->u4FastModeSpeed = i2c_handle[i2c_owner].i2c_config.Fast_Mode_Speed;
        prI2CConfig->u4HSModeSpeed = i2c_handle[i2c_owner].i2c_config.HS_Mode_Speed;
	}

	return STATUS_OK;
}

/*************************************************************************
* FUNCTION
*  DclSI2C_RegisterCallback
*
* DESCRIPTION
*  This function is to set callback function for the I2C module.
*
* PARAMETERS
*  handle: the returned handle value of DclSI2C_Open
*  event: Supported events:
*  callback: the callback function for registered events
*
* RETURNS
*  STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclSI2C_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback){
	return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclSI2C_Control
*
* DESCRIPTION
*  This function is to send command to control the I2C module.
*
* PARAMETERS
*  handle: The handle value returned from DclSI2C_Open
*  cmd: A control command for I2C module
*          1. I2C_CMD_GET_TRANSACTION_MODE: to get transaction mode
*          2. I2C_CMD_SET_TRANSACTION_SPEED: to set transaction speed
*          3. I2C_CMD_SINGLE_WRITE: to perform a single WRITE
*          4. I2C_CMD_SINGLE_READ: to perform a single READ
*          5. I2C_CMD_CONT_WRITE: to perform a continuous WRITE
*          6. I2C_CMD_CONT_READ: to  perform a continuous READ
*          7. I2C_CMD_WRITE_AND_READ: to perform a specific sequence "WRITE then READ"
*          8. I2C_CMD_ENABLE_DMA: to enable/disable DMA
*  data: The data of the control command
*          1. I2C_CMD_GET_TRANSACTION_MODE: pointer to a I2C_CTRL_GET_TRANSACTION_MODE_T structure
*          2. I2C_CMD_SET_TRANSACTION_SPEED: pointer to a I2C_CTRL_SET_TRANSACTION_SPEED_T structure
*          3. I2C_CMD_SINGLE_WRITE: pointer to a I2C_CTRL_SINGLE_WRITE_T structure
*          4. I2C_CMD_SINGLE_READ: pointer to a I2C_CTRL_SINGLE_READ_T structure
*          5. I2C_CMD_CONT_WRITE: pointer to a I2C_CTRL_CONT_WRITE_T structure
*          6. I2C_CMD_CONT_READ: pointer to a I2C_CTRL_CONT_READ_T structure
*          7. I2C_CMD_WRITE_AND_READ: pointer to a I2C_CTRL_WRITE_AND_READE_T structure
*          8. I2C_CMD_ENABLE_DMA: pointer to a I2C_CTRL_ENABLE_DMA_T structure
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
DCL_STATUS DclSI2C_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_I2C_OWNER i2c_owner;
  #if defined(DRV_I2C_BATCH_TRANSACTION_SUPPORT)
  I2C_TRANSACTION_RESULT result;
  #endif
  
  // At present, this is not allowed to be used in LISR
	if (kal_if_lisr())
	{
    return STATUS_FAIL;
	}
	
	// Check magic number
	if ((handle & DCL_I2C_DEV_MAGIC_NUM) != DCL_I2C_DEV_MAGIC_NUM)
	{
		return STATUS_INVALID_DCL_HANDLE;
	}
			
	//*/ check if the handle is opened /*//
	if ((i2c_handle[(kal_uint8)(handle & 0xFF)].i2c_config.Fast_Mode_Speed) == 0)
	{
		return STATUS_NOT_OPENED;
	}
	
	i2c_owner = (DCL_I2C_OWNER)(handle & 0xFF);
	switch (cmd)
	{
		case I2C_CMD_GET_TRANSACTION_MODE:
		{
			I2C_CTRL_GET_TRANSACTION_MODE_T *prGetTransactionMode;
			prGetTransactionMode = &(data->rGetTransactionMode);
			
			prGetTransactionMode->eTransactionMode = (DCL_I2C_TRANSACTION_MODE)i2c_handle[i2c_owner].i2c_config.transaction_mode;
			return STATUS_OK;
		}
		//break;
		case I2C_CMD_SET_TRANSACTION_SPEED:
		{
			I2C_CTRL_SET_TRANSACTION_SPEED_T *prSetTransactionSpeed;
			prSetTransactionSpeed = &(data->rSetTransactionSpeed);

            i2c_handle[i2c_owner].i2c_config.Fast_Mode_Speed = prSetTransactionSpeed->u4FastModeSpeed;
            i2c_handle[i2c_owner].i2c_config.HS_Mode_Speed = prSetTransactionSpeed->u4HSModeSpeed;
            
            dcl_i2c_set_transaction_speed(i2c_owner,i2c_handle[i2c_owner].i2c_config.transaction_mode,&(i2c_handle[i2c_owner].i2c_config.Fast_Mode_Speed),&(i2c_handle[i2c_owner].i2c_config.HS_Mode_Speed));          
            
            prSetTransactionSpeed->u4FastModeSpeed = i2c_handle[i2c_owner].i2c_config.Fast_Mode_Speed;
            prSetTransactionSpeed->u4HSModeSpeed = i2c_handle[i2c_owner].i2c_config.HS_Mode_Speed;

			return STATUS_OK;
		}
		//break;
		case I2C_CMD_SINGLE_WRITE:
        case I2C_CMD_SINGLE_READ:
        case I2C_CMD_CONT_WRITE:
        case I2C_CMD_CONT_READ:
        case I2C_CMD_WRITE_AND_READ:
		{
            kal_uint32 savedMask;
            
            savedMask=dcl_i2c_wait_transaction_complete_and_lock(i2c_owner);
            if (dcl_i2c_status.owner!=i2c_owner)
            {
                return STATUS_DEVICE_IS_BUSY;
            }

            if(cmd == I2C_CMD_SINGLE_WRITE)
            {
                I2C_CTRL_SINGLE_WRITE_T *prSingleWrite = &(data->rSingleWrite);
                dcl_i2c_hw_cfg (i2c_owner, I2C_TRANSACTION_WRITE, prSingleWrite->pu1Data, prSingleWrite->u4DataLen, NULL, 0, 1); 
                dcl_i2c_wait_transaction_complete(savedMask);
            }
            else if(cmd == I2C_CMD_SINGLE_READ)
            {
                I2C_CTRL_SINGLE_READ_T *prSingleRead = &(data->rSingleRead);
                dcl_i2c_hw_cfg (i2c_owner, I2C_TRANSACTION_READ, NULL, 0, prSingleRead->pu1Data, prSingleRead->u4DataLen, 1);
                dcl_i2c_wait_transaction_complete(savedMask);

                #if(defined (DRV_I2C_DMA_ENABLED))
                if (i2c_handle[i2c_owner].i2c_config.is_DMA_enabled)
                {
                    dcl_i2c_DMA_rx_done_cacheability((kal_uint32)prSingleRead->pu1Data, prSingleRead->u4DataLen);
                }
                #endif // #if(defined (DRV_I2C_DMA_ENABLED))
            }
            else if(cmd == I2C_CMD_CONT_WRITE)
            {
                I2C_CTRL_CONT_WRITE_T *prContWrite = &(data->rContWrite);
                dcl_i2c_hw_cfg (i2c_owner, I2C_TRANSACTION_CONT_WRITE, prContWrite->pu1Data, prContWrite->u4DataLen, NULL, 0, prContWrite->u4TransferNum);
                dcl_i2c_wait_transaction_complete(savedMask);
            }
            else if(cmd == I2C_CMD_CONT_READ)
            {
                I2C_CTRL_CONT_READ_T *prContRead = &(data->rContRead);
                dcl_i2c_hw_cfg (i2c_owner, I2C_TRANSACTION_CONT_READ, NULL, 0, prContRead->pu1Data, prContRead->u4DataLen, prContRead->u4TransferNum);
                dcl_i2c_wait_transaction_complete(savedMask);
            
                #if(defined (DRV_I2C_DMA_ENABLED))
                if (i2c_handle[i2c_owner].i2c_config.is_DMA_enabled)
                {
                    dcl_i2c_DMA_rx_done_cacheability((kal_uint32)prContRead->pu1Data, (prContRead->u4DataLen)*(prContRead->u4TransferNum));
                }
                #endif // #if(defined (DRV_I2C_DMA_ENABLED))
            }
            else if(cmd == I2C_CMD_WRITE_AND_READ)
            {
                I2C_CTRL_WRITE_AND_READE_T *prWriteAndRead  = &(data->rWriteAndRead);
                dcl_i2c_hw_cfg (i2c_owner, I2C_TRANSACTION_WRITE_AND_READ, prWriteAndRead->pu1OutData, prWriteAndRead->u4OutDataLen, prWriteAndRead->pu1InData, prWriteAndRead->u4InDataLen, 2);  
                dcl_i2c_wait_transaction_complete(savedMask);
            
                #if(defined (DRV_I2C_DMA_ENABLED))
                if (i2c_handle[i2c_owner].i2c_config.is_DMA_enabled)
                {
                    dcl_i2c_DMA_rx_done_cacheability((kal_uint32)prWriteAndRead->pu1InData, prWriteAndRead->u4InDataLen);
                }
                #endif // #if(defined (DRV_I2C_DMA_ENABLED))
            }
            
            return _ConvertDclReturnStatus(i2c_handle[i2c_owner].transaction_result);
		}
		//break;

#if defined(DRV_I2C_BATCH_TRANSACTION_SUPPORT)
		case I2C_CMD_BATCH_TRANSACTION:
		{
			I2C_CTRL_BATCH_TRANSACTION_T *prBatchTransaction;
			prBatchTransaction = &(data->rBatchTransaction);
			
			result = dcl_i2c_batch_transaction(i2c_owner, (i2c_batch_data_struct*)prBatchTransaction->prBatchData, prBatchTransaction->u4BatchNum);
      return _ConvertDclReturnStatus(result);
		}
		//break;
		case I2C_CMD_GET_BATCH_TRANSACTION_RESULT:
		{
			I2C_CTRL_GET_BATCH_TRANSACTION_RESULT_T *prGetBatchTransactionResult;
			prGetBatchTransactionResult = &(data->rGetBatchTransactionResult);
			
			result = dcl_i2c_get_batch_transaction_result(i2c_owner, (kal_uint32* )&(prGetBatchTransactionResult->u4BatchNum));
			if (result == I2C_TRANSACTION_SUCCESS)
			{
				prGetBatchTransactionResult->eBatchTransactionResult = DCL_I2C_BATCH_TRANSACTION_SUCCESS;
			}
			else
			{
				if (result == I2C_TRANSACTION_IS_BUSY)
					prGetBatchTransactionResult->eBatchTransactionResult = DCL_I2C_BATCH_TRANSACTION_IS_BUSY;
				else if (result == I2C_TRANSACTION_FAIL)
					prGetBatchTransactionResult->eBatchTransactionResult = DCL_I2C_BATCH_TRANSACTION_FAIL;
			}
			
            return STATUS_OK;
		}
		//break;
#endif

#if (defined(DRV_I2C_DMA_ENABLED))
		case I2C_CMD_GET_DMA_PROPERTY:
		{
			I2C_CTRL_GET_DMA_PROPERTY_T *prGetDMAProperty;
			prGetDMAProperty = &(data->rGetDMAProperty);
			
            #if (!defined(DRV_I2C_DMA_ENABLED))			
			prGetDMAProperty->eDMAProperty = DCL_I2C_DMA_NOT_SUPPORT;
#elif defined (DRV_I2C_DMA_NOT_SUPPORT_READ_AFTER_WRITE)
			prGetDMAProperty->eDMAProperty = DCL_I2C_DMA_SINGLE_CHANNEL;
#else
			prGetDMAProperty->eDMAProperty = DCL_I2C_DMA_DUAL_CHANNEL;
#endif //#if (!defined(DRV_I2C_DMA_ENABLED))							
			
			return STATUS_OK;
		}
		//break;
		case I2C_CMD_ENABLE_DMA:
		{
			I2C_CTRL_ENABLE_DMA_T *prEnableDMA;
			prEnableDMA = &(data->rEnableDMA);
				
            #if (!defined(DRV_I2C_DMA_ENABLED))
			    return STATUS_DEVICE_NOT_SUPPORT_DMA;
            #else
                i2c_handle[i2c_owner].i2c_config.is_DMA_enabled=(kal_bool)(prEnableDMA->fgEnableDMA);
                return STATUS_OK;
            #endif // #if (!defined(DRV_I2C_DMA_ENABLED))
		}
	//	break;
#endif
		case I2C_CMD_SET_SLAVE_ADDRESS:
		{
			I2C_CTRL_SET_SLAVE_ADDRESS_T *prSetSlaveAddress;
			prSetSlaveAddress = &(data->rSetSlaveAddress);

            i2c_handle[i2c_owner].i2c_config.slave_address=prSetSlaveAddress->u1SlaveAddress;
			return STATUS_OK;
		}
	//	break;
		default:
			return STATUS_INVALID_CMD;
	//	break;
	}
	return STATUS_FAIL;
}

/*************************************************************************
* FUNCTION
*  DclSI2C_Close
*
* DESCRIPTION
*  This function is to close the I2C module.
*
* PARAMETERS
*  handle: the returned handle value of DclSI2C_Open
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS DclSI2C_Close(DCL_HANDLE handle)
{
	i2c_config_struct* config = &i2c_handle[(kal_uint8)(handle & 0xFF)].i2c_config;

	// Check magic number
	if ((handle & DCL_I2C_DEV_MAGIC_NUM) != DCL_I2C_DEV_MAGIC_NUM)
	{
		return STATUS_INVALID_DCL_HANDLE;
	}

		
	//*/ check if the handle is opened, if i2c handle is opened, the related Fast_Mode_Speed not equal to zero /*//
	if (config->Fast_Mode_Speed == 0)
	{
		return STATUS_NOT_OPENED;
	}

	config->Fast_Mode_Speed = 0;

	return STATUS_OK;
}

#else //#if (!defined(DRV_I2C_OFF) && defined(DCL_I2C_INTERFACE))

#if (!defined(DRV_I2C_OFF) && !defined(DCL_I2C_INTERFACE))
//#error "DRV_I2C_25_SERIES not defined. You should define DRV_I2C_OFF to turn off I2C."
#endif //#if (!defined(DRV_I2C_OFF) && !defined(DCL_I2C_INTERFACE))
DCL_STATUS DclSI2C_Initialize(void)
{
    return STATUS_FAIL;
}

DCL_HANDLE DclSI2C_Open(DCL_DEV dev, DCL_FLAGS flags)
{
    return 0;
}
DCL_STATUS DclSI2C_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSI2C_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSI2C_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
    return STATUS_FAIL;
}

DCL_STATUS DclSI2C_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSI2C_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    return STATUS_FAIL;
}
DCL_STATUS DclSI2C_Close(DCL_HANDLE handle)
{
    return STATUS_FAIL;
}
#endif

