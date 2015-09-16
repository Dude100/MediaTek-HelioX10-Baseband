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
 *   dcl_irda.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for IrDA.
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

#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_IRDA_H_STRUCT__
#define __DCL_IRDA_H_STRUCT__
/*******************************************************************************
 * DCL_OPTIONS for IRDA
 *******************************************************************************/
#define IRDA_OPTIONS

/*******************************************************************************
 * DCL_CONFIGURE_T
 *******************************************************************************/
typedef struct
{
   DCL_BOOL     fgModulation1p63;
   DCL_BOOL     fgBOFType0xff;
   DCL_UINT8    uMirDoubleStaNum;
#define DCL_MIR_DOUBLE_STA_DEFAULT  0x7f
#define DCL_MIR_DOUBLE_STA_MAX  0x7f
} IRDA_CONFIG_T;

#define IRDA_CONFIGS \
   IRDA_CONFIG_T rIRDACofig;


/*******************************************************************************
 * DCL_EVENT for IRDA
 *******************************************************************************/
#define IRDA_EVENTS

/*******************************************************************************
 * DCL_CTRL_CMD for IRDA
 *******************************************************************************/
#define IRDA_CMDS

/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/
#define IRDA_CTRLS

#endif // #ifndef __DCL_IRDA_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT   

#if defined(DCL_DEFINITION_PROTOTYPE)
#ifndef __DCL_IRDA_H_PROTOTYPE__
#define __DCL_IRDA_H_PROTOTYPE__
// MoDIS parser skip start
/*************************************************************************
* FUNCTION
*  DclIRDA_Initialize
*
* DESCRIPTION
*  This function is to initialize IRDA module. 
*
* PARAMETERS
*	DCL_STATUS_OK
*  STATUS_UNSUPPORTED - IrDA is not supported or enabled.
*
* RETURNS
*  none
*
*************************************************************************/
extern DCL_STATUS DclIRDA_Initialize(void);

/*************************************************************************
* FUNCTION
*  DclIRDA_Open
*
* DESCRIPTION
*  This function is to open the IRDA module and get a handle. Note that 
* multiple opens are not allowed.
*
* PARAMETERS
*	eDev - only valid for DCL_IRDA
*	flags - no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*	DCL_HANDLE_INVALID - Open failed.
*  STATUS_UNSUPPORTED - IrDA is not supported or enabled.
*  other value - a valid handle
*
*************************************************************************/
extern DCL_HANDLE DclIRDA_Open(DCL_DEV eDev, DCL_FLAGS flags);

/*************************************************************************
* FUNCTION
*  DclIRDA_ReadData
*
* DESCRIPTION
*  This function is not supported for the IRDA module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclIRDA_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);

/*************************************************************************
* FUNCTION
*  DclIRDA_WriteData
*
* DESCRIPTION
*  This function is not supported for the IRDA module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclIRDA_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);

/*************************************************************************
* FUNCTION
*  DclIRDA_Configure
*
* DESCRIPTION
*  This function is to configure for the IRDA module.
*
* PARAMETERS
*	handle - a valid handle return by DclIRDA_Open()
*  configure - a ponter to IRDAT_CONFIG_T structure which is a member of union 
*              DCL_CONFIGURE_T.
*
* RETURNS
*	STATUS_OK - successfully set the configuratuib.
*  STATUS_INVALID_HANDLE - It's a invalid handle.
*  STATUS_UNSUPPORTED - IrDA is not supported or enabled.
*
*************************************************************************/
extern DCL_STATUS DclIRDA_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);

/*************************************************************************
* FUNCTION
*  DclIRDA_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the IRDA module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclIRDA_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);

/*************************************************************************
* FUNCTION
*  DclIRDA_Control
*
* DESCRIPTION
*  This function is not supported for the IRDA module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclIRDA_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);

/*************************************************************************
* FUNCTION
*  DclIRDA_Close
*
* DESCRIPTION
*  This function is to close the IRDA module.
*
* PARAMETERS
*	handle  - hanlde previous got from DclIRDA_Open()
*
* RETURNS
*	DCL_STATUS_OK - successfully close the IRDA module.
*  STATUS_NOT_OPENED - IrDA hasn't been opened yet.
*  STATUS_INVALID_HANDLE - It's a invalid handle.
*  STATUS_UNSUPPORTED - IrDA is not supported or enabled.
*
*************************************************************************/
extern DCL_STATUS DclIRDA_Close(DCL_HANDLE handle);

// MoDIS parser skip end

#endif // #ifndef __DCL_IRDA_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE


