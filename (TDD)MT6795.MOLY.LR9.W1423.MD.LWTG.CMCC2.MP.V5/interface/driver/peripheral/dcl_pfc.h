/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *    dcl_pfc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for PFC.
 *
 * Author:
 * -------
 *
 *  Ansel Liao
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
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
#ifndef __DCL_PFC_H_STRUCT__
#define __DCL_PFC_H_STRUCT__

/*******************************************************************************
 * DCL_OPTIONS for PFC
 *******************************************************************************/
#define PFC_OPTIONS

/*******************************************************************************
 * DCL_CONFIGURE_T for PFC
 *******************************************************************************/
#define PFC_CONFIGS

/*******************************************************************************
 * DCL_EVENT for PFC
 *******************************************************************************/
#define PFC_EVENTS

/*******************************************************************************
 * PPP_PFC_CHANNEL enum for PFC
 *******************************************************************************/
typedef enum {
	PPP_PFC_CHANNEL_0 = 0,
	PPP_PFC_CHANNEL_1,
	PPP_PFC_CHANNEL_2,
} PPP_PFC_CHANNEL;

/*******************************************************************************
 * PPP_PFC_CHANNEL enum for PFC
 *******************************************************************************/
typedef enum {
	PFC_ENCODE = 0,
	PFC_DECODE,
} PFC_OPERATION_SEL_T; 

/*******************************************************************************
 * DCL_CTRL_CMD for PFC
 *******************************************************************************/
/* The PFC Command Values in DCL_CTRL_CMD_T Enum of dcl.h */
#ifdef __BUILD_DOM__
typedef enum {
	PFC_CMD_RESET,		/* To Reset PFC */
	PFC_CMD_SET_CONFIG,	/* to set config */
	PFC_CMD_ENCODE,		/* To Encode PPP Framer */
	PFC_CMD_DECODE,		/* To Decode PPP Framer */
	PFC_CMD_DEQUEUE, 	/* to de-Q encode/decode gpd list */
	PFC_CMD_RELOAD_RX	/* to reload GPD list */
} DCL_CTRL_CMD_T;
#else /* __BUILD_DOM__ */
#define PFC_CMDS \
	PFC_CMD_RESET, \
	PFC_CMD_SET_CONFIG, \
	PFC_CMD_ENCODE, \
	PFC_CMD_DECODE, \
	PFC_CMD_DEQUEUE, \
	PFC_CMD_RELOAD_RX,
#endif /* __BUILD_DOM__ */    

/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/
 
/* For PFC_CMD_RESET command. */
typedef struct 
{
	DCL_UINT32 en_de;	/* input: encode or decode */ 
	DCL_UINT32 channel;	/* input: channel id */ 
} PFC_CTRL_RESET_T;

/* For PFC_CMD_SET_CONFIG command. */
typedef struct 
{
	DCL_UINT32 en_de;	/* input: encode or decode */
	DCL_UINT32 channel;	/* input: channel id */ 
	DCL_BOOL f32;		/* input: fcs mode */
	DCL_BOOL acfc;		/* input: address and control field compression */
	DCL_BOOL pfc;		/* input: protocol field compression */
	DCL_UINT16 max_pkt_sz;	/* input: max packet size */
	DCL_UINT16 ptc;		/* input: pfc protocol */
	DCL_UINT32 pfc_accm[7];	/* input: accm 0 ~ 6 */
} PFC_CTRL_SET_CONFIG_T;

/* For PFC_CMD_ENCODE command. */
typedef struct
{
	DCL_UINT32 channel;	/* input: channel id */
	void *head;		/* input: head of TGPD list */
	void *tail;		/* input: tail of TGPD list */
} PFC_CTRL_ENCODE_T;

/* For PFC_CMD_DECODE command. */
typedef struct
{
	DCL_UINT32 channel;	/* input: channel id */
	void *head;		/* input: head of TGPD list */
	void *tail;		/* input: tail of TGPD list */
} PFC_CTRL_DECODE_T;

/* For PFC_CMD_DEQUEUE command. */
typedef struct
{
	DCL_UINT32 en_de;	/* input: encode or decode */
	DCL_UINT32 channel;	/* input: channel id */
	void **head;		/* output: head of RGPD list */
	void **tail;		/* output: tail of RGPD list */
	DCL_UINT32 *queue_len;	/* output: length of queue */
} PFC_CTRL_DEQUEUE_T;

/* For PFC_CMD_RELOAD_RX command. */
typedef struct
{
	DCL_UINT32 en_de;	/* input: encode or decode */
	DCL_UINT32 channel;	/* input: channel id */
	void *head;		/* input: head of RGPD list */
	void *tail;		/* input: tail of RGPD list */
	DCL_UINT32 queue_len;	/* input: length of RGPD list */
} PFC_CTRL_RELOAD_RX_T;

/* The PFC Command Parameter Data Structure for Each Command in DCL_CTRL_DATA_T Enum of dcl.h */
#ifdef __BUILD_DOM__
typedef union 
{
	PFC_CTRL_RESET_T r_pfc_ctrl_reset;		/* Data Structure for PFC_CMD_RESET */
	PFC_CTRL_SET_CONFIG_T r_pfc_ctrl_set_config;	/* Data Structure for PFC_CMD_SET_CONFIG */
	PFC_CTRL_ENCODE_T r_pfc_ctrl_encode;		/* Data Structure for PFC_CMD_ENCODE */
	PFC_CTRL_DECODE_T r_pfc_ctrl_decode;		/* Data Structure for PFC_CMD_DECODE */
	PFC_CTRL_DEQUEUE_T r_pfc_ctrl_dequeue;		/* Data Structure for PFC_CMD_DEQUEUE */
	PFC_CTRL_RELOAD_RX_T r_pfc_ctrl_reload_rx;	/* Data Structure for PFC_CMD_RELOAD_RX */
} DCL_CTRL_DATA_T;
#else /* __BUILD_DOM__ */
#define PFC_CTRLS \
	PFC_CTRL_RESET_T r_pfc_ctrl_reset; \
	PFC_CTRL_SET_CONFIG_T r_pfc_ctrl_set_config; \
	PFC_CTRL_ENCODE_T r_pfc_ctrl_encode; \
	PFC_CTRL_DECODE_T r_pfc_ctrl_decode; \
	PFC_CTRL_DEQUEUE_T r_pfc_ctrl_dequeue; \
	PFC_CTRL_RELOAD_RX_T r_pfc_ctrl_reload_rx;
#endif /* __BUILD_DOM__ */

#endif // #ifndef __DCL_PFC_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT   

#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_PFC_H_PROTOTYPE__
#define __DCL_PFC_H_PROTOTYPE__


/*************************************************************************
* FUNCTION
*  DclPFC_Initialize
*
* DESCRIPTION
*  This function is to initialize PFC module
*
* PARAMETERS
*  None
*
* RETURNS
*  Return the status of DclPFC_Initialize
*
* RETURN VALUES
*  STATUS_OK: Initialize Finished
*
*************************************************************************/
extern DCL_STATUS DclPFC_Initialize(void);
/*************************************************************************
* FUNCTION
*  DclPFC_Open
*
* DESCRIPTION
*  This function is to open the PFC module and return a handle
*
* PARAMETERS
*  dev: [IN] Only valid for DCL_PFC
*  flags: [IN] No sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  Return DCL_HANDLE of PFC
*
* RETURN VALUES
*  DCL_HANDLE_INVALID : Open failed
*  Other value : A valid handle
*
*************************************************************************/
extern DCL_HANDLE DclPFC_Open(DCL_DEV dev, DCL_FLAGS flags);
/*************************************************************************
* FUNCTION
*  DclPFC_ReadData
*
* DESCRIPTION
*  This function is not supported for the PFC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclPFC_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclPFC_WriteData
*
* DESCRIPTION
*  This function is not supported for the PFC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclPFC_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclPFC_Configure
*
* DESCRIPTION
*  This function is not supported for the PFC module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclPFC_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION
*  DclPFC_RegisterCallback
*
* DESCRIPTION
*  This function is to set callback function for the PFC module.
*
* PARAMETERS
*  handle: the returned handle value of DclPFC_Open
*  event: Supported events:
*  callback: the callback function for registered events
*
* RETURNS
*  STATUS_OK: Successfully register the callback function.
*  STATUS_INVALID_DCL_HANDLE: It's a invalid handle.
*  STATUS_NOT_OPENED: The module has not been opened.
*  STATUS_INVALID_EVENT: The event parameter is invalid.
*
*************************************************************************/
extern DCL_STATUS DclPFC_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);
/*************************************************************************
* FUNCTION
*  DclPFC_Control
*
* DESCRIPTION
*  This function is to send command to control the PFC module.
*
* PARAMETERS
*  handle: [IN] The handle value returned from DclPFC_Open
*  cmd: [IN] A control command for PFC module
*          1. PFC_CMD_RESET: to reset PFC Module
*          2. PFC_CMD_ENCODE: to Encode
*          3. PFC_CMD_DECODE: to Decode
*
*  data: [IN] The data of the control command
*          1. PFC_CMD_RESET: pointer to a PFC_CTRL_RESET_T structure
*          2. PFC_CMD_ENCODE: pointer to a PFC_CTRL_ENCODE_T structure
*          3. PFC_CMD_DECODE: pointer to a PFC_CTRL_DECODE_T structure
*
* RETURNS
*  Return the status of DclPFC_Control
*
* RETURN VALUES
*  STATUS_OK: Command is executed successfully.
*  STATUS_FAIL: Command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
extern DCL_STATUS DclPFC_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION
*  DclPFC_Close
*
* DESCRIPTION
*  This function is to close the PFC module.
*
* PARAMETERS
*  handle: [IN] The returned handle value of DclPFC_Open
*
* RETURNS
*  Return the status of DclPFC_Close
*
* RETURN VALUES
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclPFC_Close(DCL_HANDLE handle);

// MoDIS parser skip end

#endif // #ifndef __DCL_PFC_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE
