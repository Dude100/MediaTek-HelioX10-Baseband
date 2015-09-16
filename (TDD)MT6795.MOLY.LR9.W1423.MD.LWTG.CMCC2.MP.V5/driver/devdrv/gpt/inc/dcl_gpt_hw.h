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
 *   dcl_gpt.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for GPT.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * DCL_CTRL_CMD
 *******************************************************************************/
#ifndef DCL_GPT_HW_H_
#define DCL_GPT_HW_H_
#include "kal_general_types.h"
#include "drv_comm.h"
#include "dcl.h"

typedef DCL_UINT16 GPT_DEV;
typedef enum
{
	GPT1 = 1,
	GPT2 = 2,
	GPT3 = 3,
	GPT4 = 4
} GPT_DEV_T;

typedef enum 
{
	clk_16k,
	clk_8k,
	clk_4k,
	clk_2k,
	clk_1k,
	clk_500,
	clk_250,
	clk_125,
	clk_invalid=0xFF
}gpt_clock;

typedef DCL_UINT32  HGPT_CMD;
typedef enum
{

   HGPT_CMD_CLK, 
   HGPT_CMD_RESET, 
   HGPT_CMD_START, 
   HGPT_CMD_STOP, 
   HGPT_CMD_BUSYWAIT,
//   HGPT_CMD_GPT_STATUS,
   FHGPT_CMD_START, 
   FHGPT_CMD_STOP, 
   FHGPT_CMD_RETURN_COUNT,
   FHGPT_CMD_LOCK
} HGPT_CMD_T;

/* For HGPT_CMD_CLK command. */
typedef enum 
{
	CLK_16K,
	CLK_8K,
	CLK_4K,
	CLK_2K,
	CLK_1K,
	CLK_500,
	CLK_250,
	CLK_125
} HGPT_CLK_T;

typedef struct
{
   DCL_UINT32   u4Clock; // for HGPT_CLK_T enum
} HGPT_CTRL_CLK_T;

/* For HGPT_CMD_RESET command. */
typedef struct
{
   DCL_UINT16   u2CountValue;
   DCL_BOOL     fgAutoReload;
} HGPT_CTRL_RESET_T;

/* For HGPT_CMD_RESET command. */
//typedef DCL_UINT16 FGPT_CTRL_RETURN_COUNT_T;
typedef DCL_UINT32 FGPT_CTRL_RETURN_COUNT_T_32bit;
typedef DCL_UINT16 BUSY_WAIT_COUNT_T;
typedef DCL_BOOL	 FGPT_CTRL_LOCK_T;
//typedef DCL_UINT8  GPT_STATUS_T;
typedef  union
{
   HGPT_CTRL_CLK_T                rHGPTClk; 
   HGPT_CTRL_RESET_T              rHGPTReset; 
   FGPT_CTRL_RETURN_COUNT_T       u2RetCount;
   FGPT_CTRL_RETURN_COUNT_T_32bit u2RetCount_32bit;
   BUSY_WAIT_COUNT_T			 			  uBusyWaitCount;
   FGPT_CTRL_LOCK_T							  ulock;
//   GPT_STATUS_T					 gpt_status;
} HGPT_CTRL;

void GPTI_BusyWait(kal_uint16 len);
/* DCL for HW GPT */
/*************************************************************************
* FUNCTION
*  DclHGPT_Initialize
*
* DESCRIPTION
*  This function is to initialize HW GPT module.
*
* PARAMETERS
*	None
*
* RETURNS
*	DCL_STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclHGPT_Initialize(void);

/*************************************************************************
* FUNCTION
*  DclHGPT_Open
*
* DESCRIPTION
*  This function is to open a HW GPT module. Note that HW GPT only supports
* single open for each valid eDev and if DCL_GPT1 is chosen SGPT may be 
* influenced and work abnormally.
*
* PARAMETERS
*	eDev - only valid for DCL_GPT1 and DCL_GPT2
*	flags - no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*	DCL_HANDLE_INVALID - Open failed.
*  other value - a valid handle
*
*************************************************************************/
extern DCL_HANDLE DclHGPT_Open(DCL_DEV dev, DCL_FLAGS flags);

/*************************************************************************
* FUNCTION
*  DclHGPT_ReadData
*
* DESCRIPTION
*  This function is not supported for the HW GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclHGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);

/*************************************************************************
* FUNCTION
*  DclHGPT_WriteData
*
* DESCRIPTION
*  This function is not supported for the HW GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclHGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);

/*************************************************************************
* FUNCTION
*  DclHGPT_Configure
*
* DESCRIPTION
*  This function is not supported for the HW GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclHGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);

/*************************************************************************
* FUNCTION
*  DclHGPT_RegisterCallback
*
* DESCRIPTION
*  This function is to set callback function for the HW GPT module.
*
* PARAMETERS
*	handle  - hanlde previous got from DclHGPT_Open().
*  event   - only support EVENT_HGPT_TIMEOUT event.
*  callback - the callback function when HW GPT is timeout.
*
* RETURNS
*	STATUS_OK - successfully register the callback function.
*  STATUS_INVALID_HANDLE - It's a invalid handle.
*  STATUS_NOT_OPENED - The module has not been opened.
*  STATUS_INVALID_EVENT - The event parameter is invalid.
*
*************************************************************************/
extern DCL_STATUS DclHGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);

/*************************************************************************
* FUNCTION
*  DclHGPT_Control
*
* DESCRIPTION
*  This function is to send command to control the HW GPT module.
*
* PARAMETERS
*	handle - a valid handle return by DclHGPT_Open()
*  cmd   - a control command for HW GPT module
*          1. HGPT_CMD_CLK: to set clock for a HW GPT timer
*          2. HGPT_CMD_RESET: to reset a HWGPT timer
*          3. HGPT_CMD_START: to start a HW GPT timer
*          4. HGPT_CMD_STOP: to stop a HWGPT timer
*  data - for 1. HGPT_CMD_CLK: pointer to a HGPT_CTRL_CLK_T structure
*             2. HGPT_CMD_RESET: pointer to a HGPT_CTRL_RESET_T structure
*             3. HGPT_CMD_START: a NULL pointer
*             4. HGPT_CMD_STOP: a NULL pointer
*
* RETURNS
*	STATUS_OK - command is executed successfully.
*	STATUS_FAIL - command is failed.
*  STATUS_INVALID_CMD - The command is invalid.
*  STATUS_INVALID_HANDLE - The handle is invalid.
*  STATUS_INVALID_CTRL_DATA - The ctrl data is not valid.
*
*************************************************************************/
extern DCL_STATUS DclHGPT_Control(DCL_HANDLE handle, HGPT_CMD cmd, HGPT_CTRL *data);

/*************************************************************************
* FUNCTION
*  DclHGPT_Close
*
* DESCRIPTION
*  This function is to close a HW GPT module by a handle previous opened. 
*
* PARAMETERS
*	handle  - hanlde previous got from DclHGPT_Open().
*
* RETURNS
*	STATUS_OK - successful.
*	DCL_HANDLE_INVALID - it's a invalid handle.
*
*************************************************************************/
extern DCL_STATUS DclHGPT_Close(DCL_HANDLE handle);

/* DCL for Free Run HW GPT */
/*************************************************************************
* FUNCTION
*  DclFHGPT_Initialize
*
* DESCRIPTION
*  This function is to initialize the free run GPT module.
*
* PARAMETERS
*	None
*
* RETURNS
*	DCL_STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclFHGPT_Initialize(void);

/*************************************************************************
* FUNCTION
*  DclFHGPT_Open
*
* DESCRIPTION
*  This function is to open a free run GPT module if it exists. Note 
* that it supports multiple opens and no need to close it.
*
* PARAMETERS
*	eDev - only valid for DCL_GPT3
*	flags - no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*	DCL_HANDLE_INVALID - Open failed. It means no free run GPT exists or 
*                       open a wrong device.
*  other value - a valid handle
*
*************************************************************************/
extern DCL_HANDLE DclFHGPT_Open(DCL_DEV dev, DCL_FLAGS flags);

/*************************************************************************
* FUNCTION
*  DclFHGPT_ReadData
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclFHGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);

/*************************************************************************
* FUNCTION
*  DclFHGPT_WriteData
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclFHGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);

/*************************************************************************
* FUNCTION
*  DclFHGPT_Configure
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclFHGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);

/*************************************************************************
* FUNCTION
*  DclFHGPT_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclFHGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);

/*************************************************************************
* FUNCTION
*  DclFHGPT_Control
*
* DESCRIPTION
*  This function is to send command to control the free run GPT module.
*
* PARAMETERS
*	handle - a valid handle return by DclFHGPT_Open()
*  cmd   - a control command for free ryb GPT module
*          FGPT_CMD_RETURN_COUNT: to get the timer count
*  data - for FGPT_CMD_RETURN_COUNT: pointer to a FGPT_CTRL_RETURN_COUNT_T type
*
* RETURNS
*	STATUS_OK - command is executed successfully.
*	STATUS_FAIL - command is failed. No free run GPT is supported.
*  STATUS_INVALID_CMD - The command is invalid.
*  STATUS_INVALID_HANDLE - The handle is invalid.
*
*************************************************************************/
extern DCL_STATUS DclFHGPT_Control(DCL_HANDLE handle, HGPT_CMD cmd, HGPT_CTRL *data);

/*************************************************************************
* FUNCTION
*  DclFHGPT_Close
*
* DESCRIPTION
*  This function is not supported for the free run GPT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclFHGPT_Close(DCL_HANDLE handle);

kal_bool GPT_IsStop(void);


#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_GPT_REG_DBG__)
#define DRV_GPT_WriteReg(addr,data)              DRV_DBG_WriteReg(addr,data)
#define DRV_GPT_Reg(addr)                        DRV_DBG_Reg(addr)                      
#define DRV_GPT_WriteReg32(addr,data)            DRV_DBG_WriteReg32(addr,data)          
#define DRV_GPT_Reg32(addr)                      DRV_DBG_Reg32(addr)                    
#define DRV_GPT_WriteReg8(addr,data)             DRV_DBG_WriteReg8(addr,data)           
#define DRV_GPT_Reg8(addr)                       DRV_DBG_Reg8(addr)                     
#define DRV_GPT_ClearBits(addr,data)             DRV_DBG_ClearBits(addr,data)           
#define DRV_GPT_SetBits(addr,data)               DRV_DBG_SetBits(addr,data)             
#define DRV_GPT_SetData(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)  
#define DRV_GPT_ClearBits32(addr,data)           DRV_DBG_ClearBits32(addr,data)         
#define DRV_GPT_SetBits32(addr,data)             DRV_DBG_SetBits32(addr,data)           
#define DRV_GPT_SetData32(addr, bitmask, value)  DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_GPT_ClearBits8(addr,data)            DRV_DBG_ClearBits8(addr,data)          
#define DRV_GPT_SetBits8(addr,data)              DRV_DBG_SetBits8(addr,data)            
#define DRV_GPT_SetData8(addr, bitmask, value)   DRV_DBG_SetData8(addr, bitmask, value) 
#else
#define DRV_GPT_WriteReg(addr,data)              DRV_WriteReg(addr,data)
#define DRV_GPT_Reg(addr)                        DRV_Reg(addr)                      
#define DRV_GPT_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)          
#define DRV_GPT_Reg32(addr)                      DRV_Reg32(addr)                    
#define DRV_GPT_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)           
#define DRV_GPT_Reg8(addr)                       DRV_Reg8(addr)                     
#define DRV_GPT_ClearBits(addr,data)             DRV_ClearBits(addr,data)           
#define DRV_GPT_SetBits(addr,data)               DRV_SetBits(addr,data)             
#define DRV_GPT_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)  
#define DRV_GPT_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)         
#define DRV_GPT_SetBits32(addr,data)             DRV_SetBits32(addr,data)           
#define DRV_GPT_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
#define DRV_GPT_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)          
#define DRV_GPT_SetBits8(addr,data)              DRV_SetBits8(addr,data)            
#define DRV_GPT_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value) 
#endif //#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_GPT_REG_DBG__)


#endif
