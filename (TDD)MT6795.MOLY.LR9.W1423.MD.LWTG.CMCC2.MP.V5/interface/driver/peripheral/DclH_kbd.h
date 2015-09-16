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
 *   dcl_kbd.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for KBD.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef DCL_DEFINITION_STRUCT

#ifndef __DCLH_KBD_H_STRUCT__
#define __DCLH_KBD_H_STRUCT__


#define DCL_HKBD_MAGIC_NUM  0x40000000


#ifdef __BUILD_DOM__
/*keypad hw event */
typedef enum
{
	DCL_EVENT_HKBD_STATUS_CHANGE = 0x01, /*keypad hw status change  for the normal keypad hw matrix*/
	DCL_EVENT_HKBD_EX_STATUS_CHANGE = 0X02,/*keypad extension direction key status change ex: jogball*/
	DCL_EVENT_HKBD_MAX = 0XFF,/*the max keypad hw event id*/

}KBDH_EVENTS;
#else
#define KBDH_EVENTS    \
   DCL_EVENT_HKBD_STATUS_CHANGE = 0x01, \
   DCL_EVENT_HKBD_EX_STATUS_CHANGE = 0X02,\
   DCL_EVENT_HKBD_MAX = 0XFF,\

#endif


#ifdef __BUILD_DOM__
/*keypad hw control commands*/
typedef enum
{
	HKBD_CMD_GET_KEY_NUMBER, /*the command to get the total key number*/
	HKBD_CMD_GET_KEY_STA_MAP,/*get the keypad hw status register table*/
	HKBD_CMD_GET_KEY_STATUS, /*Query the key is pressed or released status*/
	HKBD_CMD_GET_POWER_KEY_STATUS,/*Query the power key status*/

}KBDH_CMDS;
#else
#define KBDH_CMDS    \
   HKBD_CMD_GET_KEY_NUMBER, \
   HKBD_CMD_GET_KEY_STA_MAP,\
   HKBD_CMD_GET_KEY_STATUS,\
   HKBD_CMD_GET_POWER_KEY_STATUS,
#endif


#ifdef __BUILD_DOM__
/*define the data structure type for every command*/
typedef union
{
	HKBD_CTRL_KNUM_T             		rKBDCtrlKNUM; /*keypad number structure*/
	HKBD_CTRL_STA_MAP_T       			rKBDCtrlStaMap; /*keypad stauts register structure*/
	HKBD_CTRL_KEY_STA_T            		rKBDCtrlKeySta; /*key status structure*/
	HKBD_CTRL_POWKEY_T                 	rKBDCtrlPowerKeySta;/*power key status structure*/
}KBDH_CTRLS;

#else
#define KBDH_CTRLS \
   HKBD_CTRL_KNUM_T             		rKBDCtrlKNUM; \
   HKBD_CTRL_STA_MAP_T       			rKBDCtrlStaMap;\
   HKBD_CTRL_KEY_STA_T            		rKBDCtrlKeySta;\
   HKBD_CTRL_POWKEY_T                 	rKBDCtrlPowerKeySta;
#endif


//HKBD_CMD_GET_KEY_NUMBER
/*the control command data for command:HKBD_CMD_GET_KEY_NUMBER*/
typedef struct
{
   DCL_UINT16   u2KeyNum;/*key number*/
} HKBD_CTRL_KNUM_T;

//HKBD_CMD_GET_KEY_STA_MAP
/*the control command data for command:HKBD_CMD_GET_KEY_STA_MAP*/
typedef struct
{
   DCL_UINT32 kbdmap_reg;/*the lowest 32bit register value, every bit indicates one key status*/
   DCL_UINT32 kbdmap_reg1;/*the middle 32bit register value, every bit indicates one key status*/
   DCL_UINT32 kbdmap_reg2;/*the highest 32bit register value, every bit indicates one key status*/
} HKBD_CTRL_STA_MAP_T;

/*the control command data for command:HKBD_CMD_GET_KEY_STATUS*/
typedef struct
{
	DCL_BOOL sta;/*key stauts:KAL_TURE indicates the key is pressed, KAL_FALSE indicates the key is released*/
	DCL_UINT8 key;/*key index number, which is defined in the kbd_table.h */
}HKBD_CTRL_KEY_STA_T;

/*the control command data for command:HKBD_CMD_GET_POWER_KEY_STATUS*/
typedef struct
{
   DCL_BOOL     fgPKP;/*KAL_TURE indicates the key is pressed, KAL_FALSE indicates the key is released*/
} HKBD_CTRL_POWKEY_T;

#endif
#endif


#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_HKBD_H_PROTOTYPE__
#define __DCL_HKBD_H_PROTOTYPE__


/*************************************************************************
*<GROUP CallBackFunctions>
* FUNCTION
*  KBDH_EVENT_FUNC
*
* DESCRIPTION
*  This function is the callback function for the hw status change.
*
* PARAMETERS
*  event: the keypad hw event, it can be the enum value KBDH_EVENTS.
*  param: the optional parameter.
*
* RETURNS
*  NONE
*
*************************************************************************/
typedef void (*KBDH_EVENT_FUNC)(DCL_EVENT event, void* param) ; 

/*************************************************************************
* FUNCTION
*  DclHKBD_Initialize
*
* DESCRIPTION
*  This function is to initialize keypad hardware module, It is called during the driver initialization and the user is not needed to call it.
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclHKBD_Initialize(void);

/*************************************************************************
* FUNCTION
* DclHKBD_Open
*
* DESCRIPTION
* This function is to open the keypad hw module and return a handle.
*
* PARAMETERS
*  dev:keypad device ID. it should be DCL_KBD.
*  flags:User of keypad driver. It should be the user module id, if the user does not module id, it can be set 0.
*
* RETURNS
*  DCL_HANDLE_INVALID: Incorrect device ID.
*  Other value: A valid handle
*
* EXAMPLE
*  <code>
*  DCL_HANDLE kbd_handle;
*  kbd_handle = DclHKBD_Open(DCL_KBD, MOD_DRVKBD);
*  </code>
*************************************************************************/
extern DCL_HANDLE DclHKBD_Open(DCL_DEV dev, DCL_FLAGS flags);

/*************************************************************************
* FUNCTION
*  DclHKBD_Control
*
* DESCRIPTION
* This function is to control the keypad driver, the user can call the interface to get the keypad driver services through the different commands.
*
* PARAMETERS
*  handle: the user handler of the keypad, which is returned by the DclHKBD_Open function.
*  cmd: the keypad driver control commands, the values can be get from the enum KBDH_CMDS.
*  data: the data which is corresponed to the commands, the data type can beone of  the enum KBDH_CTRLS.
*
* RETURNS
*  DCL_HANDLE_INVALID: Incorrect device ID.
*  STATUS_OK: return successfully.
*
* EXAMPLE
*  <code>
*  DCL_HANDLE kbdhandle;
*  DCL_CTRL_DATA_T reg;
*  kbdhandle = DclHKBD_Open(DCL_KBD, MOD_DRVKBD);
*  DclHKBD_Control(kbdhandle, HKBD_CMD_GET_KEY_STA_MAP, (DCL_CTRL_DATA_T*)&reg);	 
*  pkeypad_status->kbdmap_reg = reg.rKBDCtrlStaMap.kbdmap_reg;
*  pkeypad_status->kbdmap_reg1= reg.rKBDCtrlStaMap.kbdmap_reg1;
*  pkeypad_status->kbdmap_reg2= reg.rKBDCtrlStaMap.kbdmap_reg2;
*  </code>
*
*************************************************************************/
extern DCL_STATUS DclHKBD_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);


/*************************************************************************
* FUNCTION
*  DclHKBD_Close
*
* DESCRIPTION
* This function is to close the keypad driver.
*
* PARAMETERS
*  handle: the user handler of the keypad, which is returned by the DclHKBD_Open function.
*
* RETURNS
*  STATUS_OK: return successfully.
*
*************************************************************************/
extern DCL_STATUS DclHKBD_Close(DCL_HANDLE handle);

/*************************************************************************
* FUNCTION
*  DclHKBD_RegisterCallback
*
* DESCRIPTION
* This function is to register the hardware event callback function.
*
* PARAMETERS
*  handle: the user handler of the keypad, which is returned by the DclHKBD_Open function.
*  event: the keypad hardware event.It can be one of the value in the enum KBDH_EVENTS.
*  callback: the callback function pointer.           
*
* RETURNS
*  DCL_HANDLE_INVALID: Incorrect device ID.
*  STATUS_INVALID_EVENT: the event parameter is not valid for the keypad.
*  STATUS_OK: return successfully.
*
* EXAMPLE
*  <code>
* DCL_HANDLE handle ;
* handle = DclHKBD_Open(DCL_KBD, 0);
* DclHKBD_RegisterCallback(handle, DCL_EVENT_HKBD_STATUS_CHANGE, &Kbd_hw_event_Callback);
*  </code>
*
*************************************************************************/
extern DCL_STATUS DclHKBD_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, KBDH_EVENT_FUNC callback);

#endif
#endif

