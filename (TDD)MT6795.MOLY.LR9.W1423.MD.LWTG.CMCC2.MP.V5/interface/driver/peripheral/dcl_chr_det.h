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
 *    dcl_chr_det.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines functions of charger detection
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifdef DCL_DEFINITION_STRUCT

#ifndef __DCL_CHR_DET_H_STRUCT__
#define __DCL_CHR_DET_H_STRUCT__


/*******************************************************************************
 * DCL_OPTIONS for PMU
 *******************************************************************************/
#define CHR_DET_OPTIONS

 /*******************************************************************************
 * DCL_CONFIGURE_T for PMU
 *******************************************************************************/

#define CHR_DET_CONFIGS

/*******************************************************************************
 * DCL_EVENT for PMU
 *******************************************************************************/
#define CHR_DET_EVENTS

/* Enum of Charger type */
typedef enum
{
   PW_AC_CHR=0,			/* AC CHARGER */
   PW_USB_CHR,			/* USB CHARGER */
   PW_AC_NON_STD_CHR, /* NON-STANDARD AC CHARGER */
   PW_USB_CHARGING_HOST_CHR,  /* USB CHARGING HOST */
   PW_NO_CHR    // Indicate NO charger
}CHR_DET_TYPE_ENUM;

/* For CHR_DET_CMD_QUERY_CHR_TYPE command. */
typedef struct
{
	CHR_DET_TYPE_ENUM	Chr_det_type;	/* Output : Value of Charger type */
}CHR_DET_CTRL_QUERY_IS_CHR_IN_BY_PW;

/* For RTC_CMD_CONFIG_AL_TC command. */
typedef struct
{
	CHR_DET_TYPE_ENUM	Chr_det_type;	/* Output : Value of Charger type */
}CHR_DET_CTRL_QUERY_CHR_TYPE;

typedef struct
{
	void (*usb_det_hisr)(void); 
}CHR_DET_CTRL_REGISTER_USB_HISR;

/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/
#ifdef __BUILD_DOM__
/* The CHR_DET Command Parameter Data Structure for Each Command in DCL_CTRL_DATA_T Enum of dcl.h */
typedef struct
{
    CHR_DET_CTRL_QUERY_IS_CHR_IN_BY_PW	rChrDetQueryIsChrInByPW; /* Data Structure for CHR_DET_CMD_QUERY_IS_CHR_IN_BY_PW */
    CHR_DET_CTRL_QUERY_CHR_TYPE	rChrDetQueryChrType; 		/* Data Structure for CHR_DET_CMD_QUERY_CHR_TYPE */
	CHR_DET_CTRL_REGISTER_USB_HISR rChrDetUSBHISR;  /* Data Structure for CHR_DET_CTRL_REGISTER_USB_HISR */
} DCL_CTRL_CHR_DET_DATA;
#else /* __BUILD_DOM__ */
#define CHR_DET_CTRLS \
	CHR_DET_CTRL_QUERY_IS_CHR_IN_BY_PW	rChrDetQueryIsChrInByPW; \
	CHR_DET_CTRL_QUERY_CHR_TYPE	rChrDetQueryChrType;  \
	CHR_DET_CTRL_REGISTER_USB_HISR rChrDetUSBHISR;
#endif /* __BUILD_DOM__ */


/*******************************************************************************
 * DCL_CTRL_CMD for PMU
 *******************************************************************************/
#ifdef __BUILD_DOM__
/* The CHR DET Command Values in DCL_CTRL_CMD_T Enum of dcl.h */
typedef enum 
{
    CHR_DET_CMD_QUERY_IS_CHR_IN_BY_PW,
    CHR_DET_CMD_QUERY_CHR_TYPE,
    CHR_DET_CMD_REGISTER_CHR_USB,
    CHR_DET_CMD_UNMASK_EINT,
    CHR_DET_CMD_REGISTER_CHR_USB_EINT,
    CHR_DET_CMD_REGISTER_USB_HISR,
} DCL_CTRL_CHR_DET_CMD;
#else /* __BUILD_DOM__ */
#define CHR_DET_CMDS \
	CHR_DET_CMD_QUERY_IS_CHR_IN_BY_PW=0, \
	CHR_DET_CMD_QUERY_CHR_TYPE, \
	CHR_DET_CMD_REGISTER_CHR_USB, \
	CHR_DET_CMD_UNMASK_EINT, \
	CHR_DET_CMD_REGISTER_CHR_USB_EINT,\
	CHR_DET_CMD_REGISTER_USB_HISR,
#endif /* __BUILD_DOM__ */


// CHR_USB_EINT control owner list
// Only the tasks listed can control CHR_USB_EINT Unmask
typedef enum
{
	CHR_DET_EINT_OWNER_USB = 0x01,	// Bit00
	CHR_DET_EINT_OWNER_BMT = 0x02,	// Bit01
	USB_DET_EINT_OWNER_FORCE_UNMASK = 0x80	// Bit7 // It means we should skip bit match and directly unmask EINT
}CHR_DET_EINT_OWNER;


typedef struct
{
	CHR_DET_TYPE_ENUM (*pw_is_charger_usb_det)(void);
	void (*pw_is_charger_usb_det_eint)(void);
	void (*usb_det_hisr)(void); 
}CHR_USB_DET_MGR_T;



#endif // #ifndef __DCL_PMU_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT


#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_CHR_DET_H_PROTOTYPE__
#define __DCL_CHR_DET_H_PROTOTYPE__




/*************************************************************************
* FUNCTION
*  Dcl_Chr_Det_Initialize
*
* DESCRIPTION
*  This function is to initialize Chr_Det module
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS Dcl_Chr_Det_Initialize(void);
/*************************************************************************
* FUNCTION
*  Dcl_Chr_Det_Open
*
* DESCRIPTION
*  This function is to open the Chr_Det module and return a handle
*
* PARAMETERS
*  dev: only valid for DCL_CHR_USB_DET
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed.
*  other value: a valid handle
*
*************************************************************************/
extern DCL_HANDLE Dcl_Chr_Det_Open(DCL_DEV dev, DCL_FLAGS flags);
/*************************************************************************
* FUNCTION
*  Dcl_Chr_Det_ReadData
*
* DESCRIPTION
*  This function is not supported for the Chr_Det module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS Dcl_Chr_Det_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  Dcl_Chr_Det_WriteData
*
* DESCRIPTION
*  This function is not supported for the Chr_Det module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS Dcl_Chr_Det_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  Dcl_Chr_Det_Configure
*
* DESCRIPTION
*  This function is to close the Chr_Det module.
*
* PARAMETERS
*	N/A
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS Dcl_Chr_Det_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION
*  Dcl_Chr_Det_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the Chr_Det module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS Dcl_Chr_Det_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);
/*************************************************************************
* FUNCTION
*	Dcl_Chr_Det_Control
*
* DESCRIPTION
*   	This function is to send command to control the Chr_Det module.
*	All command 
*
* CALLS  
*	It is called to send command to control the Chr_Det module.
*
* PARAMETERS
*  handle: [IN] The handle value returned from Dcl_Chr_Det_Open()
*  cmd: [IN] A control command for Chr_Det module
*          1. PW_CMD_POWERON: call RTC module to latch power and init time if necessary
*          2. PW_CMD_POWEROFF: call RTC module to unlatch power
*          3. PW_CMD_SET_POWERON_REASON: set power on reason
*          4. PW_CMD_GET_POWERON_REASON: get power on reason
*          5. PW_CMD_SET_SWITCH_TO_IDLE: set flag which force phone to enter idle mode
*          6. PW_CMD_CLEAR_SWITCH_TO_IDLE: clear flag which force phone to enter idle mode
*          7. PW_CMD_POWER_INIT: check power on factors to decide power on reason and save in RTC register
*	     8. PW_CMD_UPDATE_FLAGS: update power on reason to rtc register
*	     9. PW_CMD_NFB_POWERON: call RTC module to latch power and init time if necessary (only for NAND FLASH BOOTING)
*          10. PW_CMD_IS_USB_BOOT: query is power on reason USB plug in
*
*  data: The data of the control command
*          1. PW_CMD_POWERON: A null pointer
*          2. PW_CMD_POWEROFF: A null pointer
*          3. PW_CMD_SET_POWERON_REASON: pointer to a PW_CTRL_SET_POWERON_REASON structure
*          4. PW_CMD_GET_POWERON_REASON: pointer to a PW_CTRL_GET_POWERON_REASON structure
*          5. PW_CMD_SET_SWITCH_TO_IDLE: A null pointer
*          6. PW_CMD_CLEAR_SWITCH_TO_IDLE: A null pointer
*          7. PW_CMD_POWER_INIT: A null pointer
*	     8. PW_CMD_UPDATE_FLAGS: A null pointer
*	     9. PW_CMD_NFB_POWERON: A null pointer
*          10. PW_CMD_IS_USB_BOOT: pointer to a PW_CTRL_IS_USB_BOOT
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*     STATUS_UNSUPPORTED: It's a unsupported command.
*
* GLOBALS AFFECTED
*   external_global
*************************************************************************/
extern DCL_STATUS Dcl_Chr_Det_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION
*  Dcl_Chr_Det_Close
*
* DESCRIPTION
*  This function is to close the Chr_Det module.
*
* PARAMETERS
*  handle: the returned handle value of Dcl_Chr_Det_Open
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS Dcl_Chr_Det_Close(DCL_HANDLE handle);


#endif // #ifndef __DCL_CHR_DET_H_PROTOTYPE__
#endif //#ifdef DCL_DEFINITION_PROTOTYPE


































