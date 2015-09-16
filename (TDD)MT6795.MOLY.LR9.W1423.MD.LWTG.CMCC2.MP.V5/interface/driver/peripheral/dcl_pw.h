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
 *    dcl_pw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for phone on/off control and power on reason
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_PW_H_STRUCT__
#define __DCL_PW_H_STRUCT__


/*******************************************************************************
 * DCL_OPTIONS for PMU
 *******************************************************************************/
#define PW_OPTIONS

 /*******************************************************************************
 * DCL_CONFIGURE_T for PMU
 *******************************************************************************/

#define PW_CONFIGS

/*******************************************************************************
 * DCL_EVENT for PMU
 *******************************************************************************/
#define PW_EVENTS


/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/

typedef enum{
	PWRKEYPWRON = 0, /* power on reason is powerkey */
	CHRPWRON	= 1,      /* power on reason is charger in */
	RTCPWRON = 2,	    /* power on reason is rtc alarm */
	CHRPWROFF = 3,     /* reserved */
	WDTRESET = 4, 	   /* reserved */
	ABNRESET = 5,       /* power on reason is abnormal reboot */
	USBPWRON = 6,     /* power on reason is usb cable in */
	USBPWRON_WDT = 7, /* power on reason is usb cable in and abnormal reboot*/
	PRECHRPWRON = 8,   /* power on reason is precharger power on*/
	UNKNOWN_PWRON = 0xF9	/* power on reason is unknown*/
}PW_CTRL_POWER_ON_REASON;

typedef enum{
 	PWR_FACTOR_POWER_KEY = 0,
	PWR_FACTOR_CHARGER_IN,
 	PWR_FACTOR_USB_IN,
 	PWR_FACTOR_RTC_EXPIRE,
 	PWR_FACTOR_WDT_RESET,
 	PWR_FACTOR_NORMAL_RESET_FLG,
 	PWR_FACTOR_CHRPWRON_FLG,
 	PWR_FACTOR_USBMS_PWRON_FLG,
 	PWR_FACTOR_RTCPWRON_FLG,
 	PWR_FACTOR_PRECHRPWRON_FLG,
 	PWR_FACTOR_SWITCH2IDLE_FLG,
 	PWR_FACTOR_SWITCH2CHR_FLG,
 	PWR_FACTOR_SWITCH2USB_FLG,
 	PWR_FACTOR_MAX
}pwr_factor_enum;

typedef enum{
    PWR_FACTOR_BL_POWER_KEY = 0x1,
    PWR_FACTOR_BL_CABLE_IN = 0x2,
    PWR_FACTOR_BL_RTC_EXPIRE = 0x4,
    PWR_FACTOR_BL_NORMAL_RESET_FLG = 0x8,
    PWR_FACTOR_BL_CHRPWRON_FLG = 0x10,
    PWR_FACTOR_BL_USBMS_PWRON_FLG = 0x20,
    PWR_FACTOR_BL_RTCPWRON_FLG = 0x40,
    PWR_FACTOR_BL_FACTORY_FLG = 0x80,
    PWR_FACTOR_BL_MAX
}pw_factor_bl_enum;

typedef struct
{
	DCL_BOOL	val; /* Output : TRUE: indicate usb plug in; FALSE: indicate not usb plug in  */
} PW_CTRL_IS_USB_BOOT;

typedef struct
{
	PW_CTRL_POWER_ON_REASON	powerOnReason; /* Input : power on reason  */
} PW_CTRL_SET_POWERON_REASON;
   
typedef struct
{
	PW_CTRL_POWER_ON_REASON	powerOnReason; /* Output : power on reason  */
} PW_CTRL_GET_POWERON_REASON;

/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/
#ifdef __BUILD_DOM__
/* The PW Command Parameter Data Structure for Each Command in DCL_CTRL_DATA_T Enum of dcl.h */
typedef struct
{
	PW_CTRL_SET_POWERON_REASON		rPWSetPowerOnReason; /* Data Structure for PW_CMD_SET_POWERON_REASON */
	PW_CTRL_GET_POWERON_REASON		rPWGetPowerOnReason; /* Data Structure for PW_CMD_GET_POWERON_REASON */
	PW_CTRL_IS_USB_BOOT				rPWIsUsbBoot; /* Data Structure for PW_CMD_IS_USB_BOOT */
}DCL_CTRL_PW_DATA;
#else /* __BUILD_DOM__ */
#define PW_CTRLS \
	PW_CTRL_SET_POWERON_REASON		rPWSetPowerOnReason; \
	PW_CTRL_GET_POWERON_REASON		rPWGetPowerOnReason; \
	PW_CTRL_IS_USB_BOOT				rPWIsUsbBoot;
#endif /* __BUILD_DOM__ */	


/*******************************************************************************
 * DCL_CTRL_CMD for PMU
 *******************************************************************************/
#ifdef __BUILD_DOM__
/* The PW Command Values in DCL_CTRL_CMD_T Enum of dcl.h */
typedef enum {
	PW_CMD_POWERON, /* call RTC module to latch power and init time if necessary */
	PW_CMD_POWEROFF, /* call RTC module to unlatch power */
	PW_CMD_SET_POWERON_REASON, /* set power on reason */
	PW_CMD_GET_POWERON_REASON, /* get power on reason */
	PW_CMD_SET_SWITCH_TO_IDLE, /* set flag which force phone to enter idle mode */
	PW_CMD_CLEAR_SWITCH_TO_IDLE, /* clear flag which force phone to enter idle mode */
	PW_CMD_POWER_INIT, /* For check power on factors to decide power on reason and save in RTC register */
	PW_CMD_UPDATE_FLAGS, /* update power on reason to rtc register */
	PW_CMD_NFB_POWERON, /* call RTC module to latch power and init time if necessary (only for NAND FLASH BOOTING) */
	PW_CMD_IS_USB_BOOT, /* query is power on reason USB plug in  */
} DCL_CTRL_PW_CMD;
#else /* __BUILD_DOM__ */
#define PW_CMDS \
	PW_CMD_POWERON, \
	PW_CMD_POWEROFF, \
	PW_CMD_SET_POWERON_REASON, \
	PW_CMD_GET_POWERON_REASON, \
	PW_CMD_SET_SWITCH_TO_IDLE, \
	PW_CMD_CLEAR_SWITCH_TO_IDLE, \
	PW_CMD_POWER_INIT, \
	PW_CMD_UPDATE_FLAGS, \
	PW_CMD_NFB_POWERON, \
	PW_CMD_IS_USB_BOOT,
#endif /* __BUILD_DOM__ */		

#ifndef __DRV_DEBUG_PWIC_REG_READ_WRITE__
#define PW_DRV_ClearBits16(addr, data)       DRV_ClearBits(addr,data)
#define PW_DRV_SetBits16(addr, data)         DRV_SetBits(addr,data)
#define PW_DRV_WriteReg16(addr, data)        DRV_WriteReg(addr, data)
#define PW_DRV_WriteReg32(addr, data)        DRV_WriteReg32(addr, data)
#define PW_DRV_ReadReg16(addr)               DRV_Reg(addr)
#define PW_DRV_ReadReg32(addr)               DRV_Reg32(addr)
#else // #ifndef __DRV_DEBUG_PWIC_REG_READ_WRITE__
#define PW_DRV_ClearBits16(addr,data)        DRV_DBG_ClearBits(addr,data)
#define PW_DRV_SetBits16(addr)               DRV_DBG_SetBits(addr)
#define PW_DRV_WriteReg16(addr, data)        DRV_DBG_WriteReg(addr, data)
#define PW_DRV_WriteReg32(addr, data)        DRV_DBG_WriteReg32(addr, data)
#define PW_DRV_ReadReg16(addr)               DRV_DBG_Reg(addr)
#define PW_DRV_ReadReg32(addr)               DRV_DBG_Reg32(addr)
#endif // #ifndef __DRV_DEBUG_PWIC_REG_READ_WRITE__


#endif // #ifndef __DCL_PMU_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT


#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_PW_H_PROTOTYPE__
#define __DCL_PW_H_PROTOTYPE__



/*************************************************************************
* FUNCTION
*  DclPW_Initialize
*
* DESCRIPTION
*  This function is to initialize PW module
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclPW_Initialize(void);
/*************************************************************************
* FUNCTION
*  DclPW_Open
*
* DESCRIPTION
*  This function is to open the PW module and return a handle
*
* PARAMETERS
*  dev: only valid for DCL_PW
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed.
*  other value: a valid handle
*
*************************************************************************/
extern DCL_HANDLE DclPW_Open(DCL_DEV dev, DCL_FLAGS flags);
/*************************************************************************
* FUNCTION
*  DclPW_ReadData
*
* DESCRIPTION
*  This function is not supported for the PW module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclPW_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclPW_WriteData
*
* DESCRIPTION
*  This function is not supported for the PW module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclPW_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION
*  DclPW_Configure
*
* DESCRIPTION
*  This function is not supported for the PW module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclPW_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION
*  DclPW_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the PW module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclPW_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);
/*************************************************************************
* FUNCTION
*	DclPW_Control
*
* DESCRIPTION
*   	This function is to send command to control the PW module.
*	All command 
*
* CALLS  
*	It is called to send command to control the PW module.
*
* PARAMETERS
*  handle: [IN] The handle value returned from DclPW_Open()
*  cmd: [IN] A control command for PW module
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
extern DCL_STATUS DclPW_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION
*  DclPW_Close
*
* DESCRIPTION
*  This function is to close the PW module.
*
* PARAMETERS
*  handle: the returned handle value of DclPW_Open
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclPW_Close(DCL_HANDLE handle);


#endif // #ifndef __DCL_PW_H_PROTOTYPE__

#endif //#ifdef DCL_DEFINITION_PROTOTYPE



