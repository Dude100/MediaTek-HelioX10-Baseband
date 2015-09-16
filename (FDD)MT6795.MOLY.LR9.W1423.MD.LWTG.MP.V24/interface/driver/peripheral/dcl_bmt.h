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
 *   dcl_bmt.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for BMT.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_BMT_H_STRUCT__
#define __DCL_BMT_H_STRUCT__

/*******************************************************************************
 * DCL_OPTIONS for BMT
 *******************************************************************************/
#define BMT_OPTIONS

/*******************************************************************************
 * DCL_CONFIGURE_T for BMT
 *******************************************************************************/
#define BMT_CONFIGS

/*******************************************************************************
 * DCL_EVENT for BMT
 *******************************************************************************/
#define BMT_EVENTS

/*******************************************************************************
 * DCL_CTRL_CMD for BMT
 *******************************************************************************/
#ifdef __BUILD_DOM__
/* The BMT Command Values in DCL_CTRL_CMD_T Enum of dcl.h */
typedef enum {
    BMT_CMD_CALLSTATE, /* To Set BMT Call State */
    BMT_CMD_CHARGE, /* To Enable/Disable Charge */
    BMT_CMD_GET_CUSTOMIZED_PARA, /* To Get Customized Parameters */
    BMT_CMD_SET_EXT_CHARGER, /* To Set External Charger */
    BMT_CMD_INITIALIZE, /* To Initialize BMT Module */
    BMT_CMD_IS_BAT_ON, /* To Check If Battery Exist or Not */
    BMT_CMD_SENDMES2UEM, /* To Send Message to UEM via BMT */
    BMT_CMD_SET_CHR_STATUS, /* To Set Charger Status */
    BMT_CMD_VBATINHISR, /* To Save The Battery Voltage in HISR */
    BMT_CMD_WDT_INIT, /
} DCL_CTRL_CMD_T;
#else /* __BUILD_DOM__ */
#define BMT_CMDS \
    BMT_CMD_CALLSTATE, \
    BMT_CMD_CHARGE, \
    BMT_CMD_GET_CUSTOMIZED_PARA, \
    BMT_CMD_SET_EXT_CHARGER, \
    BMT_CMD_INITIALIZE, \
    BMT_CMD_IS_BAT_ON, \
    BMT_CMD_SENDMES2UEM, \
    BMT_CMD_SET_CHR_STATUS, \
    BMT_CMD_VBATINHISR, \
    BMT_CMD_WDT_INIT,
#endif /* __BUILD_DOM__ */

/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/

/* For BMT_CMD_CALLSTATE command. */
typedef struct
{
    DCL_UINT8 call_state; /* Input : Phone State */
}BMT_CTRL_CALLSTATE_T;

/* For BMT_CMD_CHARGE command. */
typedef struct
{
    DCL_BOOLEAN bEnable; /* Input : Enable/Disable Charge */
}BMT_CTRL_CHARGE_T;

/* Enum for Get Commands of Charge Parameter. */
typedef enum
{
    DCL_GET_BATTERY_TYPE, /* Get Bettery Type */
	DCL_GET_CHECK_BATTERY, /* Get Check Battery Configuration */
	DCL_GET_CHECK_CHARGER_VOLTAGE, /* Get Check Charger Voltage Configuration */
	DCL_GET_CHECK_BATT_TEMP, /* Get Check Battery Temperature Configuration */ 
	DCL_GET_MAX_VBAT_LI /* Get Max Voltage of Li Battery */
}DCL_GET_CUSTOM_CHR_PARA;

/* For BMT_CMD_GET_CUSTOMIZED_PARA command. */
typedef struct
{
    DCL_UINT32 u4ChargingParameter; /* Output : Result of Charge Parameter */
    DCL_GET_CUSTOM_CHR_PARA eGetParaCmd; /* Input : Get Command of Charge Parameter */
}BMT_CTRL_GET_CUSTOMIZED_PARA_T;

/* Enum for Commands of External Charger. */
typedef enum
{
    DCL_BMT_EXT_CHR_DRV_INIT = 0, /* Called at Driver Init Phase */
    DCL_BMT_EXT_CHR_ENABLE_INTR, /* Called at PMIC Adpt Layer Init Phase */
    DCL_BMT_EXT_CHR_CHARGE_ENABLE, /* Control Charge Enable/Disable */
    DCL_BMT_EXT_CHR_SET_CHARGE_CURRENT, /* Set Charge Current */
    DCL_BMT_EXT_CHR_GET_CHR_FAC_MEASURE_SUPPORT, /* Whether the External Charger Can Measure the Passed-in Charging Factor */
    DCL_BMT_EXT_CHR_GET_CHR_FAC_CHECK_SUPPORT, /* Whether the External Charger Can Check the Passed-in Charging Factor */
    DCL_BMT_EXT_CHR_CHECK_CHR_STATUS, /* Charger Device Can Calculate the Charger Status Through the Passed-in Information */
    DCL_BMT_EXT_CHR_GET_CHR_STATUS, /* Return calculated charger status */
    DCL_BMT_EXT_CHR_GET_VBAT, /* Get VBAT */
    DCL_BMT_EXT_CHR_GET_ISENSE, /* Get ISENSE */
    DCL_BMT_EXT_CHR_GET_VCHARGER, /* Get VCHARGER */
    DCL_BMT_EXT_CHR_GET_BAT_TEMP, /* Get Battery Temperature */
    DCL_BMT_EXT_CHR_GET_CHARGE_FULL, /* Return If Charge Full */
    DCL_BMT_EXT_CHR_GET_CHARGE_UNDER_EXTREMETMP, /* Return If It's Under Extreme Temperature */
    DCL_BMT_EXT_CHR_GET_CHARGE_EXTREMETMP_FULL, /* Return If Charge Full When Under Extreme Temperature */
    DCL_BMT_EXT_CHR_GET_CHARGE_EXTREMETMP_RECHARGE, /* Return If Charge Should Recharge When Under Extreme Temperature */
    DCL_BMT_EXT_CHR_GET_CHARGE_HOLD, /* Return If It's Need to Hold Charging */
    DCL_BMT_EXT_CHR_GET_CHR_BATT_STATE_TRANSIT_SUPPORT, /* Whether the External Charger Can Handle the Specific Charging Battery State */
    DCL_BMT_EXT_CHR_CHR_BATT_STATE_TRANSIT, /* Perform Charging Battery State Transit */
    DCL_BMT_EXT_CHR_GET_CURR_CHR_BATT_STATE, /* Get Current Charging Battery State */
    DCL_BMT_EXT_CHR_GET_SPECIFIC_CHR_CURRENT, /* Get Custom Charge Current According to Specific Charger */   
    DCL_BMT_EXT_CHR_GET_VBAT_SPECIFIC_FULL_VOLTAGE_STATE /* Whether the VBAT is Higher Than Specific Full Check Vaule or Not */
}DCL_BMT_EXT_CHR_CMD;

/* For BMT_CMD_SET_EXT_CHARGER command. */
typedef struct
{
    DCL_BMT_EXT_CHR_CMD eExtChargerCtrl; /* Input : Command of External Charger */
}BMT_CTRL_SET_EXT_CHARGER_T;

/* For BMT_CMD_IS_BAT_ON command. */
typedef struct
{
    DCL_BOOLEAN fgBatIsOn; /* Output : Battery Exist or Not */
}BMT_CTRL_IS_BAT_ON_T;

/* Enum for BMT to UEM Messages. */
typedef enum 
{
    DCL_BMT_CHARGER_IN = 0, /* Charger In */
    DCL_BMT_CHARGER_OUT, /* Charger Out */
    DCL_BMT_OVERVOLPROTECT, /* Battery Over Voltage Protect */
    DCL_BMT_OVERBATTEMP, /* Battery Over Temperature */
    DCL_BMT_LOWBATTEMP, /* Battery Low Temperature */
    DCL_BMT_OVERCHARGECURRENT, /* Over Charger Current */
    DCL_BMT_CHARGE_COMPLETE, /* Charge Complete */
    DCL_BMT_INVALID_BAT, /* Invalid Battery */
    DCL_BMT_INVALID_CHARGER, /* Invalid Charger */
    DCL_BMT_CHARGE_TIMEOUT, /* Charge Time Out */
    DCL_BMT_LOWCHARGECURRENT, /* Low Charger Current */
    DCL_BMT_CHARGE_BAD_CONTACT, /* Charger Bat Contact */
    DCL_BMT_BATTERY_BAD_CONTACT, /* Battery Bad Contact */
    DCL_BMT_USB_CHARGER_IN, /* USB Charger In */
    DCL_BMT_USB_CHARGER_OUT, /* USB Charger Out */
    DCL_BMT_USB_NO_CHARGING_IN, /* USB No Charger In */
    DCL_BMT_USB_NO_CHARGING_OUT, /* USB No Charger Out */
    DCL_BMT_BATT_IN, /* Battery In */
    DCL_BMT_BATT_OUT /* Battery Out */
}DCL_BMT_CHR_MSG;

/* For BMT_CMD_SENDMES2UEM command. */
typedef struct
{
    DCL_BMT_CHR_MSG ChargerMsg; /* Input : BMT to UEM Message */
}BMT_CTRL_SENDMES2UEM_T;

/* Enum for Charger Status. */
typedef enum {
	DCL_BMT_CHR_IN = 0, /* Charger In */
	DCL_BMT_CHR_OUT, /* Charger Out */
	DCL_BMT_CHR_UNINIT = 0xff /* Charger Uninitialized */
}DCL_BMT_CHR_STAT;

/* For BMT_CMD_SET_CHR_STATUS command. */
typedef struct
{
    DCL_BMT_CHR_STAT ChargerStat; /* Input : Charger State */
}BMT_CTRL_SET_CHR_STATUS_T;

/* For BMT_CMD_VBATINHISR command. */
// BMT_CMD_VBATINHISR does NOT need parameters

#ifdef __BUILD_DOM__
/* The BMT Command Parameter Data Structure for Each Command in DCL_CTRL_DATA_T Enum of dcl.h */
typedef struct
{
    BMT_CTRL_CALLSTATE_T rCallState; /* Data Structure for BMT_CMD_CALLSTATE */
    BMT_CTRL_CHARGE_T rChargeControl; /* Data Structure for BMT_CMD_CHARGE */
    BMT_CTRL_GET_CUSTOMIZED_PARA_T rGetCustomizedPara; /* Data Structure for BMT_CMD_GET_CUSTOMIZED_PARA */
    BMT_CTRL_SET_EXT_CHARGER_T rSetExtChr; /* Data Structure for BMT_CMD_SET_EXT_CHARGER */
    BMT_CTRL_IS_BAT_ON_T rIsBatOn; /* Data Structure for BMT_CMD_IS_BAT_ON */
    BMT_CTRL_SENDMES2UEM_T rSendMes2Uem; /* Data Structure for BMT_CMD_SENDMES2UEM */
    BMT_CTRL_SET_CHR_STATUS_T rSetChrStatus; /* Data Structure for BMT_CMD_SET_CHR_STATUS */
}DCL_CTRL_DATA_T;
#else /* __BUILD_DOM__ */
#define BMT_CTRLS \
    BMT_CTRL_CALLSTATE_T rCallState; \
    BMT_CTRL_CHARGE_T rChargeControl; \
    BMT_CTRL_GET_CUSTOMIZED_PARA_T rGetCustomizedPara; \
    BMT_CTRL_SET_EXT_CHARGER_T rSetExtChr; \
    BMT_CTRL_IS_BAT_ON_T rIsBatOn; \
    BMT_CTRL_SENDMES2UEM_T rSendMes2Uem; \
    BMT_CTRL_SET_CHR_STATUS_T rSetChrStatus;
#endif /* __BUILD_DOM__ */

#endif // #ifndef __DCL_BMT_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT   


#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_BMT_H_PROTOTYPE__
#define __DCL_BMT_H_PROTOTYPE__

/*************************************************************************
* FUNCTION
*  DclBMT_Initialize
*
* DESCRIPTION
*  This function is to initialize BMT module
*
* PARAMETERS
*  None
*
* RETURNS
*  Return the status of DclBMT_Initialize
*
* RETURN VALUES
*  STATUS_OK: Initialize Finished
*
*************************************************************************/
extern DCL_STATUS DclBMT_Initialize(void);
/*************************************************************************
* FUNCTION
*  DclBMT_Open
*
* DESCRIPTION
*  This function is to open the BMT module and return a handle
*
* PARAMETERS
*  dev: [IN] Only valid for DCL_BMT
*  flags: [IN] No sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  Return DCL_HANDLE of BMT
*
* RETURN VALUES
*  DCL_HANDLE_INVALID : Open failed
*  Other value : A valid handle
*
*************************************************************************/
extern DCL_HANDLE DclBMT_Open(DCL_DEV dev, DCL_FLAGS flags);
/*************************************************************************
* FUNCTION
*  DclBMT_ReadData
*
* DESCRIPTION
*  This function is not supported for the BMT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclBMT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclBMT_WriteData
*
* DESCRIPTION
*  This function is not supported for the BMT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclBMT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclBMT_Configure
*
* DESCRIPTION
*  This function is not supported for the BMT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclBMT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION
*  DclBMT_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the BMT module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclBMT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);
/*************************************************************************
* FUNCTION
*  DclBMT_Control
*
* DESCRIPTION
*  This function is to send command to control the BMT module.
*
* PARAMETERS
*  handle: [IN] The handle value returned from DclBMT_Open
*  cmd: [IN] A control command for BMT module
*           1. BMT_CMD_CALLSTATE: to nodify talk/idle state to BMT task
*           2. BMT_CMD_CHARGE: to enable/disble charge
*           3. BMT_CMD_GET_CUSTOMIZED_PARA: to get customized charge parameters
*           4. BMT_CMD_SET_EXT_CHARGER: to control the external charger
*           5. BMT_CMD_INITIALIZE: to initialize BMT Module
*           6. BMT_CMD_IS_BAT_ON: to check is battery exist or not
*       	7. BMT_CMD_SENDMES2UEM: to send message from BMT to UEM
*           8. BMT_CMD_SET_CHR_STATUS: to set charger status
*           9. BMT_CMD_VBATINHISR: to save the Battery voltage in HISR
*
*  data: [IN] The data of the control command
*           1. BMT_CMD_CALLSTATE: pointer to a BMT_CTRL_CALLSTATE_T structure
*           2. BMT_CMD_CHARGE: pointer to a BMT_CTRL_CHARGE_T structure
*           3. BMT_CMD_GET_CUSTOMIZED_PARA: pointer to a BMT_CTRL_GET_CUSTOMIZED_PARA_T structure
*           4. BMT_CMD_SET_EXT_CHARGER: pointer to a BMT_CTRL_SET_EXT_CHARGER_T structure
*           5. BMT_CMD_INITIALIZE: A null pointer
*           6. BMT_CMD_IS_BAT_ON: pointer to a BMT_CTRL_IS_BAT_ON_T structure
*           7. BMT_CMD_SENDMES2UEM: pointer to a BMT_CTRL_SENDMES2UEM_T structure
*           8. BMT_CMD_SET_CHR_STATUS: pointer to a BMT_CTRL_SET_CHR_STATUS_T structure
*           9. BMT_CMD_VBATINHISR: A null pointer
*
* RETURNS
*  Return the status of DclBMT_Control
*
* RETURN VALUES
*  STATUS_OK: Command is executed successfully.
*  STATUS_FAIL: Command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
extern DCL_STATUS DclBMT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION
*  DclBMT_Close
*
* DESCRIPTION
*  This function is to close the BMT module.
*
* PARAMETERS
*  handle: [IN] The returned handle value of DclBMT_Open
*
* RETURNS
*  Return the status of DclBMT_Close
*
* RETURN VALUES
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclBMT_Close(DCL_HANDLE handle);


#endif // #ifndef __DCL_BMT_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE

