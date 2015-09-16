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
 *   dcl_i2c.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for I2C.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_I2C_H_STRUCT__
#define __DCL_I2C_H_STRUCT__

/*******************************************************************************
 * DCL_OPTIONS for I2C, not in use now.
 *******************************************************************************/
#define I2C_OPTIONS

#include "dcl_i2c_owner.h"

 /* I2C Transaction Mode*/
typedef enum
{
   DCL_I2C_TRANSACTION_FAST_MODE, /* Fast Mode: < 400kbps */
   DCL_I2C_TRANSACTION_HIGH_SPEED_MODE /* Hign Speed Mode: > 400kbps */
}DCL_I2C_TRANSACTION_MODE;

/* Transaction Type, for batch transaction use*/
typedef enum
{
	DCL_I2C_TRANSACTION_WRITE, /* Single write */
	DCL_I2C_TRANSACTION_READ, /* Single read */
	DCL_I2C_TRANSACTION_CONT_WRITE, /* Continue write */
	DCL_I2C_TRANSACTION_CONT_READ, /* Continue read */
	DCL_I2C_TRANSACTION_WRITE_AND_READ /* Write and read. Note: This command can not be used, when using DMA to transfer but driver can only support DCL_I2C_DMA_SINGLE_CHANNEL. */
}DCL_I2C_TRANSACTION_TYPE;

/* Transaction result, for batch transaction query */
typedef enum
{
   DCL_I2C_BATCH_TRANSACTION_SUCCESS, /* The prior batch transaction is successfully transmitted */
   DCL_I2C_BATCH_TRANSACTION_FAIL, /* Something wrong was happened during the prior batch transaction */
   DCL_I2C_BATCH_TRANSACTION_IS_BUSY /* I2C bus is occupied now */
}DCL_I2C_BATCH_TRANSACTION_RESULT;

/* DMA property that driver support, for user query */
typedef enum
{
   DCL_I2C_DMA_NOT_SUPPORT, /* Driver do not support DMA */
   DCL_I2C_DMA_DUAL_CHANNEL, /* Driver support dual channel DMA mode */
   DCL_I2C_DMA_SINGLE_CHANNEL /* Driver support single channel DMA mode, not support WRITE_AND_READ when DMA is enabled */
}DCL_I2C_DMA_PROPERTY;

/* DCL I2C configure structure */
typedef struct
{
   DCL_I2C_OWNER eOwner; /* The owner of I2C, defined in DCL_I2C_OWNER */
   DCL_BOOL fgGetHandleWait; /* KAL_TRUE: wait until I2C is idle; KAL_FALSE: do not wait */
   DCL_UINT8 u1SlaveAddress; /* Slave address */
   DCL_UINT8 u1DelayLen; /* Wait delay between consecutive transfers (the unit is half pulse width) */
   DCL_I2C_TRANSACTION_MODE eTransactionMode; /* Fast mode or high speed mode */
   DCL_UINT32 u4FastModeSpeed; /* The transfer speed under fast mode. But even under high speed mode, you should alse configure this parameter */
   DCL_UINT32 u4HSModeSpeed; /* The transfer speed under high speed mode */
   DCL_BOOL fgEnableDMA; /* KAL_TRUE: use DMA to transfer data; KAL_FALSE: do not use DMA. Note: Make sure driver support DMA mode before you use it. */
} I2C_CONFIG_T;

/* DCL_CONFIGURE_T for I2C. */
#define I2C_CONFIGS \
   I2C_CONFIG_T rI2CCofig;

/* DCL_EVENT for I2C, not in use now. */
#define I2C_EVENTS

#ifdef __BUILD_DOM__
/* DCL_CTRL_CMD for I2C */
typedef enum
{
   I2C_CMD_GET_TRANSACTION_MODE, /* Get transaction mode */
   I2C_CMD_SET_TRANSACTION_SPEED, /* Set transaction speed */
   I2C_CMD_SINGLE_WRITE, /* Single write of blocking mode */
   I2C_CMD_SINGLE_READ, /* Single read of blocking mode */
   I2C_CMD_CONT_WRITE, /* Continue write of blocking mode */
   I2C_CMD_CONT_READ, /* Continue read of blocking mode */
   I2C_CMD_WRITE_AND_READ, /* Write and read of blocking mode */
   I2C_CMD_BATCH_TRANSACTION, /* Batch transaction which support non-blocking mode */
   I2C_CMD_GET_BATCH_TRANSACTION_RESULT, /* Query the prior batch transaction result */
   I2C_CMD_GET_DMA_PROPERTY, /* Get the DMA property which driver support */
   I2C_CMD_ENABLE_DMA, /* Use DMA to transfer data. Note: Before you do this, please make sure that driver support DMA mode */
   I2C_CMD_SET_SLAVE_ADDRESS /* Set the slave address of sensor */
}DCL_CTRL_CMD_T;
#else 
#define I2C_CMDS \
   I2C_CMD_GET_TRANSACTION_MODE, \
   I2C_CMD_SET_TRANSACTION_SPEED, \
   I2C_CMD_SINGLE_WRITE, \
   I2C_CMD_SINGLE_READ, \
   I2C_CMD_CONT_WRITE, \
   I2C_CMD_CONT_READ, \
   I2C_CMD_WRITE_AND_READ, \
   I2C_CMD_BATCH_TRANSACTION, \
   I2C_CMD_GET_BATCH_TRANSACTION_RESULT, \
   I2C_CMD_GET_DMA_PROPERTY, \
   I2C_CMD_ENABLE_DMA, \
   I2C_CMD_SET_SLAVE_ADDRESS, 
#endif /* __BUILD_DOM__ */

/* For I2C_CMD_GET_TRANSACTION_MODE command. */
typedef struct
{
   DCL_I2C_TRANSACTION_MODE eTransactionMode; /* Transaction mode */
}I2C_CTRL_GET_TRANSACTION_MODE_T;
/* For I2C_CMD_SET_TRANSACTION_SPEED command. */
typedef struct
{
   DCL_I2C_TRANSACTION_MODE eTransactionMode; /* Transaction mode */
   DCL_UINT32 u4FastModeSpeed; /* Fast mode speed */
   DCL_UINT32 u4HSModeSpeed; /* High speed mode speed */
}I2C_CTRL_SET_TRANSACTION_SPEED_T;
/* For I2C_CMD_SINGLE_WRITE, I2C_CMD_SINGLE_READ command. */
typedef struct
{
   DCL_UINT8 *pu1Data; /* Pointer to the buffer of data */
   DCL_UINT32 u4DataLen; /* Data length */
}I2C_CTRL_SINGLE_WRITE_T, I2C_CTRL_SINGLE_READ_T;
/* For I2C_CMD_CONT_WRITE, I2C_CMD_CONT_READ command. */
typedef struct
{
   DCL_UINT8 *pu1Data; /* Pointer to the buffer of data */
   DCL_UINT32 u4DataLen; /* Data length of each transfer */
   DCL_UINT32 u4TransferNum; /* Transfer number */
}I2C_CTRL_CONT_WRITE_T, I2C_CTRL_CONT_READ_T;
/* For I2C_CMD_WRITE_AND_READ command. */
typedef struct
{
   DCL_UINT8 *pu1InData; /* Pointer to the read data */
   DCL_UINT32 u4InDataLen; /* Read data length */
   DCL_UINT8 *pu1OutData; /* Pointer to the write data */
   DCL_UINT32 u4OutDataLen; /* Write data length */
}I2C_CTRL_WRITE_AND_READE_T;
/* For I2C_CTRL_BATCH_DATA_T structure. */
typedef union
{
	I2C_CTRL_SINGLE_WRITE_T rSingleWrite; /* Single write */
  I2C_CTRL_SINGLE_READ_T rSingleRead; /* Single read */
  I2C_CTRL_CONT_WRITE_T rContWrite; /* Continue write */
  I2C_CTRL_CONT_READ_T rContRead; /* Continue read */
  I2C_CTRL_WRITE_AND_READE_T rWriteAndRead; /* Write and read. Note: this command can not be used, when using DMA to transfer but driver can only support DCL_I2C_DMA_SINGLE_CHANNEL. */
}I2C_CTRL_TRANSACTION_DATA_T;
/* For I2C_CTRL_BATCH_TRANSACTION_T structure. */
typedef struct
{
   DCL_I2C_TRANSACTION_TYPE eTransactionType; /* Transaction type */
   I2C_CTRL_TRANSACTION_DATA_T rTansactionData; /* Batch transaction data of corresponding transaction type */
}I2C_CTRL_BATCH_DATA_T;
/* For I2C_CMD_BATCH_TRANSACTION command. */
typedef struct
{
   DCL_UINT32 u4BatchNum; /* Number of batches of this batch transaction */
   I2C_CTRL_BATCH_DATA_T *prBatchData; /* Pointer to the buffer where stored the batches data*/
}I2C_CTRL_BATCH_TRANSACTION_T;
/* For I2C_CMD_GET_BATCH_TRANSACTION_RESULT command. */
typedef struct
{
   DCL_I2C_BATCH_TRANSACTION_RESULT eBatchTransactionResult; /* Batch transaction result */
   DCL_UINT32 u4BatchNum;  /* The number of Batches have been transferred successfully */
}I2C_CTRL_GET_BATCH_TRANSACTION_RESULT_T;
/* For I2C_CMD_GET_DMA_PROPERTY command. */
typedef struct
{
   DCL_I2C_DMA_PROPERTY eDMAProperty; /* DMA property */
}I2C_CTRL_GET_DMA_PROPERTY_T;
/* For I2C_CMD_ENABLE_DMA command. */
typedef struct
{
   DCL_BOOL fgEnableDMA; /* KAL_TRUE: use DMA to transfer data; KAL_FALSE: do not use DMA. Note: Make sure driver support DMA mode before you use it. */
}I2C_CTRL_ENABLE_DMA_T;
/* For I2C_CMD_SET_SLAVE_ADDRESS command. */
typedef struct
{
   DCL_UINT8 u1SlaveAddress; /* Slave address */
}I2C_CTRL_SET_SLAVE_ADDRESS_T;

#ifdef __BUILD_DOM__
/* DCL_CTRL_DATA_T for I2C: Define the Control data structure for each command */ 
typedef union
{
   I2C_CTRL_GET_TRANSACTION_MODE_T rGetTransactionMode; /* Get transaction mode */
   I2C_CTRL_SET_TRANSACTION_SPEED_T rSetTransactionSpeed; /* Set transaction speed */
   I2C_CTRL_SINGLE_WRITE_T rSingleWrite; /* Single write of blocking mode */
   I2C_CTRL_SINGLE_READ_T rSingleRead; /* Single read of blocking mode */
   I2C_CTRL_CONT_WRITE_T rContWrite; /* Continue write of blocking mode */
   I2C_CTRL_CONT_READ_T rContRead; /* Continue read of blocking mode */
   I2C_CTRL_WRITE_AND_READE_T rWriteAndRead; /* Write and read of blocking mode */
   I2C_CTRL_BATCH_TRANSACTION_T rBatchTransaction; /* Batch transaction which support non-blocking mode */
   I2C_CTRL_GET_BATCH_TRANSACTION_RESULT_T rGetBatchTransactionResult; /* Query the prior batch transaction result */
   I2C_CTRL_GET_DMA_PROPERTY_T rGetDMAProperty; /* Get the DMA property which driver support */
   I2C_CTRL_ENABLE_DMA_T rEnableDMA; /* Use DMA to transfer data. Note: Before you do this, please make sure that driver support DMA mode */
   I2C_CTRL_SET_SLAVE_ADDRESS_T rSetSlaveAddress; /* Set slave address of sensor */
}DCL_CTRL_DATA_T;
#else
#define I2C_CTRLS \
   I2C_CTRL_GET_TRANSACTION_MODE_T rGetTransactionMode; \
   I2C_CTRL_SET_TRANSACTION_SPEED_T rSetTransactionSpeed; \
   I2C_CTRL_SINGLE_WRITE_T rSingleWrite; \
   I2C_CTRL_SINGLE_READ_T rSingleRead; \
   I2C_CTRL_CONT_WRITE_T rContWrite; \
   I2C_CTRL_CONT_READ_T rContRead; \
   I2C_CTRL_WRITE_AND_READE_T rWriteAndRead; \
   I2C_CTRL_BATCH_TRANSACTION_T rBatchTransaction; \
   I2C_CTRL_GET_BATCH_TRANSACTION_RESULT_T rGetBatchTransactionResult; \
   I2C_CTRL_GET_DMA_PROPERTY_T rGetDMAProperty; \
   I2C_CTRL_ENABLE_DMA_T rEnableDMA; \
   I2C_CTRL_SET_SLAVE_ADDRESS_T rSetSlaveAddress;
#endif /* __BUILD_DOM__ */

#endif // #ifndef __DCL_I2C_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT  

#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_I2C_H_PROTOTYPE__
#define __DCL_I2C_H_PROTOTYPE__

/*************************************************************************
* FUNCTION
*  DclSI2C_Initialize
*
* DESCRIPTION
*  This function is to initialize S/W I2C module, should be called only once when driver init.
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclSI2C_Initialize(void);
/*************************************************************************
* FUNCTION
*  DclSI2C_Open
*
* DESCRIPTION
*  This function is to open the I2C module and return a handle
*
* PARAMETERS
*  dev: I2C device ID. Only valid for DCL_I2C.
*  flags: User of I2C. Should be one of the enum DCL_I2C_OWNER.
*
* RETURNS
*  DCL_HANDLE_INVALID: Incorrect device ID.
*  DCL_HANDLE_OCCUPIED: This user has opened a handle, which is in use.
*  Other value: A valid handle
*
* EXAMPLE
*  <code>
*  DCL_HANDLE i2c_handle = NULL;
*  if (NULL == i2c_handle)
*  {
*      i2c_handle = DclSI2C_Open(DCL_I2C, DCL_I2C_OWNER_CAMERA);
*  }
*  </code>
*
*************************************************************************/
extern DCL_HANDLE DclSI2C_Open(DCL_DEV dev, DCL_FLAGS flags);
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
extern DCL_STATUS DclSI2C_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
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
extern DCL_STATUS DclSI2C_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
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
*  STATUS_DEVICE_NOT_SUPPORT_DMA: User wants to use DMA transfer, but driver do not support.
*
* EXAMPLE
*  <code>
*  I2C_CONFIG_T cfg;
*  cfg.eOwner = DCL_I2C_OWNER_CAMERA;
*  cfg.fgGetHandleWait = KAL_TRUE;
*  cfg.u1SlaveAddress = SLAVE_ADDRESS_ID;
*  cfg.u1DelayLen = 0;
*  cfg.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE;
*  cfg.u4FastModeSpeed = 300;
*  cfg.u4HSModeSpeed = 0;
*  cfg.fgEnableDMA = KAL_FALSE;
*  if (STATUS_OK != DclSI2C_Configure(i2c_handle, (DCL_CONFIGURE_T *)&cfg))
*  {
*      ASSERT(0);
*  }
*  </code>
*
*************************************************************************/
extern DCL_STATUS DclSI2C_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION
*  DclSI2C_RegisterCallback
*
* DESCRIPTION
*  This function is to set callback function for the I2C module, which is not supported for the I2C module now.
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
extern DCL_STATUS DclSI2C_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);
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
*          8. I2C_CMD_BATCH_TRANSACTION: to perform a non-blocking batch transaction
*          9. I2C_CMD_GET_BATCH_TRANSACTION_RESULT: to get batch transaction result
*          10. I2C_CMD_GET_DMA_PROPERTY: to get DMA property
*          11. I2C_CMD_ENABLE_DMA: to enable/disable DMA
*  data: The data of the control command
*          1. I2C_CMD_GET_TRANSACTION_MODE: pointer to a I2C_CTRL_GET_TRANSACTION_MODE_T structure
*          2. I2C_CMD_SET_TRANSACTION_SPEED: pointer to a I2C_CTRL_SET_TRANSACTION_SPEED_T structure
*          3. I2C_CMD_SINGLE_WRITE: pointer to a I2C_CTRL_SINGLE_WRITE_T structure
*          4. I2C_CMD_SINGLE_READ: pointer to a I2C_CTRL_SINGLE_READ_T structure
*          5. I2C_CMD_CONT_WRITE: pointer to a I2C_CTRL_CONT_WRITE_T structure
*          6. I2C_CMD_CONT_READ: pointer to a I2C_CTRL_CONT_READ_T structure
*          7. I2C_CMD_WRITE_AND_READ: pointer to a I2C_CTRL_WRITE_AND_READE_T structure
*          8. I2C_CMD_BATCH_TRANSACTION: pointer to a I2C_CTRL_BATCH_TRANSACTION_T structure
*          9. I2C_CMD_GET_BATCH_TRANSACTION_RESULT: pointer to a I2C_CTRL_GET_BATCH_TRANSACTION_RESULT_T structure
*          10. I2C_CMD_GET_DMA_PROPERTY: pointer to a I2C_CTRL_GET_DMA_PROPERTY_T structure
*          11. I2C_CMD_ENABLE_DMA: pointer to a I2C_CTRL_ENABLE_DMA_T structure
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*  STATUS_INVALID_DCL_HANDLE: It's a invalid handle.
*  STATUS_NOT_OPENED: The module has not been opened.
*  STATUS_DEVICE_IS_BUSY: I2C bus is occupied by others, but this user choose not to wait. Only valid for blocking transaction mode.
*  STATUS_ACKERR: ACK error occured. Only valid for blocking transaction mode.
*  STATUS_HS_NACKERR: Master code nack error occured. Only valid for blocking transaction mode.
*
* EXAMPLE
*  <code>
*  kal_uint8 out_buff[3];
*  out_buff[0] = REG_ADDR >> 8;
*  out_buff[1] = REG_ADDR;
*  out_buff[1] = WRT_DATA;
*  DCL_STATUS_T rt;
*  DCL_CTRL_CMD cmd = I2C_CMD_SINGLE_WRITE;
*  I2C_CTRL_SINGLE_WRITE_T write_data;
*  write_data.pu1Data = out_buff;
*  write_data.u4DataLen = 3;
*  rt = DclSI2C_Control(i2c_handle, cmd, (DCL_CTRL_DATA_T *)&write_data);
*  if (STATUS_OK != rt)
*  {
*      ASSERT(0);
*  }
*  </code>
*  
*************************************************************************/
extern DCL_STATUS DclSI2C_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
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
* EXAMPLE
*  <code>
*  if (i2c_handle)
*  {
*      DclSI2C_Close(i2c_handle);
*      i2c_handle = NULL;
*  }
*  </code>
*  
*************************************************************************/
extern DCL_STATUS DclSI2C_Close(DCL_HANDLE handle);


#endif // #ifndef __DCL_I2C_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE



