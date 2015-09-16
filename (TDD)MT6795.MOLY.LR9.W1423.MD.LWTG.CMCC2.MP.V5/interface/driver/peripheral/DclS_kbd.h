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
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef DCL_DEFINITION_STRUCT

 #ifndef __DCLS_KBD_H_STRUCT__
#define __DCLS_KBD_H_STRUCT__

#ifdef __BUILD_DOM__
/*keypad driver control commands which is related with software layer*/
typedef enum
{
	KBD_CMD_SET_LONG_PRESS_TIME, /*Set the  long press key time*/
	KBD_CMD_SET_REPEAT_PRESS_TIME, /*Set the  repeat press key time*/
	KBD_CMD_SET_DETECTION_MODE, /*Set the  key detection mode*/
	KBD_CMD_GET_KEY_DATA, /*get the press key data*/
	KBD_CMD_PEEK_KEY_DATA,/*peek the press key data*/
	KBD_CMD_GET_DETECTION_MODE,/*get the current key detection mode*/
	KBD_CMD_CTRL_KEY_SUPPORT,/*query the key is support or not */
	KBD_CMD_CTRL_KEY_MULTIPLE,/*query the key is multiple key or not*/
	KBD_CMD_GET_KEY_EVENT_CNT,/*get the key event in the buffer*/
	KBD_CMD_PUT_KEY_DATA,/*put the key press data to the upper layer*/

}KBD_CMDS;

#else
#define KBD_CMDS    \
   KBD_CMD_SET_LONG_PRESS_TIME, \
   KBD_CMD_SET_REPEAT_PRESS_TIME, \
    KBD_CMD_SET_DETECTION_MODE, \
    KBD_CMD_GET_KEY_DATA, \
    KBD_CMD_PEEK_KEY_DATA,\
    KBD_CMD_GET_DETECTION_MODE,\
    KBD_CMD_CTRL_KEY_SUPPORT,\
    KBD_CMD_CTRL_KEY_MULTIPLE,\
    KBD_CMD_GET_KEY_EVENT_CNT,\
    KBD_CMD_PUT_KEY_DATA,\
    KBD_CMD_FIND_TWO_STEP,

#endif

/*keypad events to the upper layer*/
typedef enum {
      DCL_kbd_onekey_press=0,/*one key press event*/
      DCL_kbd_onekey_release,/*one key release event*/
#ifdef TWO_KEY_ENABLE
      DCL_kbd_twokey_press, /*two key press event, which has been phase out now */
      DCL_kbd_twokey_release,/*two key release event, which has been phase out now*/
#endif   /*TWO_KEY_ENABLE*/
      DCL_kbd_onekey_longpress,/*one long press key event*/
      DCL_kbd_onekey_repeated,/*one repeated press key event*/
      DCL_kbd_onekey_fullpress,/*two step key function: one key full press event*/
      DCL_kbd_twokey_detection_enable,/*enable two key detection mode*/
      DCL_kbd_threekey_detection_enable,/*enable three key detection mode*/
      DCL_kbd_multikey_detection_disable/*multiple key detection mode is disable, default is one key detection mode*/
} DCL_KBD_EVENT;

/*key detection mode*/
typedef enum {
   DCL_kbd_1_key_det_mode = 0, /*one key detection mode*/
   DCL_kbd_2_keys_det_mode,/*two key detection mode */
   DCL_kbd_3_keys_det_mode /*three key detection mode*/
}DCL_kbd_key_det_mode;

/*the control command data for command:KBD_CMD_SET_DETECTION_MODE and KBD_CMD_GET_DETECTION_MODE */
typedef struct
{
   DCL_BOOL     bFlag;/*the return flag to indicate whether switch mode successfully*/
   DCL_UINT8    Det_Mode;/*the detection mode value*/
} SKBD_CTRL_MODE_T;

/*the control command data for command:KBD_CMD_GET_KEY_EVENT_CNT*/
typedef struct
{
	DCL_UINT8 keycnt;/*the key event count in the buffer*/
}SKBD_CTRL_KEY_CNT_T;

/*the control command data for command:KBD_CMD_GET_KEY_DATA*/
typedef struct
{
   DCL_KBD_EVENT   Keyevent;/*the key event*/
#ifdef TWO_KEY_ENABLE
   DCL_UINT8   Keydata[2];/*the key data*/
#else /*!TWO_KEY_ENABLE*/
   DCL_UINT8   Keydata[1];/*the key data*/
#endif   /*TWO_KEY_ENABLE*/
#if defined(__TC01__)
   DCL_UINT32  keytimestamp;/*the key time stamp*/
#endif

} SKBD_CTRL_KEYDATA_T;

/*the control command data for command:KBD_CMD_PEEK_KEY_DATA*/
typedef struct
{
 SKBD_CTRL_KEYDATA_T* keydata;/*the key data */
 DCL_BOOL specify_read; /*specify whether to read the data in the position of read_pointerl; KAL_TURE:specify to peek the data
 							in the position:read_pointer;KAL_FALSE: return the current read pointer data to the upper layer*/
 DCL_UINT32 read_pointer;/*the read position in the buffer, the max value is buff_size;*/
 DCL_UINT32* current_read_pointer;/*return the data in the structure position*/

}SKBD_CTRL_PEEKDATA_T;


/*the control command data for command:KBD_CMD_CTRL_KEY_MULTIPLE*/
typedef struct
{
   DCL_BOOL     fgIMK;/*the return value to indicate whether the ukey is a multiple key*/
   DCL_UINT8    uKey; /*the input parameter to indicate the key index*/
} SKBD_CTRL_MULTIKEY_T;


/*the control command data for command:KBD_CMD_CTRL_KEY_SUPPORT*/
typedef struct
{
   DCL_UINT8    uKey;/*the input parameter to indicate the key index*/
   DCL_BOOL fgIKBS;/*the return flag to indicate whether the ukey *is supported*/
} SKBD_CTRL_KEYSUPPORT_T;

/*the control command data for command:KBD_CMD_SET_LONG_PRESS_TIME and KBD_CMD_SET_REPEAT_PRESS_TIME*/
typedef struct
{
   DCL_UINT32   u4Tick;/*the time unit is ms.*/
} SKBD_CTRL_TIME_T;

/*the control command data for command:KBD_CMD_PUT_KEY_DATA */
typedef struct
{
	DCL_UINT8 keydata;/*the key index number*/
}SKBD_CTRL_PUTKEY_T;

typedef struct
{
  DCL_UINT32 *number;
  DCL_UINT8 *two_step;
}SKBD_CTRL_FIND_TWO_STEP_T;


#ifdef __BUILD_DOM__
/*define the data structure type for every command*/*/
typedef union
{
	SKBD_CTRL_TIME_T		   	rKBDCtrTime; /*the long press and repeat press time */
	SKBD_CTRL_KEYSUPPORT_T   	rKBDCtrlKeySupport; /*the key support structure*/
	SKBD_CTRL_MULTIKEY_T		rKBDCtrlMultiple;  /*the multiply key structure*/
	SKBD_CTRL_PEEKDATA_T		rKBDCtrPeekData;  /*peek key data command control data structure*/
	SKBD_CTRL_KEYDATA_T			rKBDCtrGetData; /*get key data command control data structure*/
	SKBD_CTRL_MODE_T			rKBDCtrMode;  /*detection command control data structure*/
	SKBD_CTRL_KEY_CNT_T		   	rKBDCtrkeyCnt;/*get key event count command control data structure*/
	SKBD_CTRL_PUTKEY_T		   	rKBDCtrPutKey;/*put key data command control data structure*/
	SKBD_CTRL_FIND_TWO_STEP_T	rKBDCtrlFindTwoStepKey;

}KBDS_CTRLS;

#else
#define KBDS_CTRLS \
   SKBD_CTRL_TIME_T  			rKBDCtrTime; \
   SKBD_CTRL_KEYSUPPORT_T  	rKBDCtrlKeySupport; \
   SKBD_CTRL_MULTIKEY_T  		 rKBDCtrlMultiple; \
   SKBD_CTRL_PEEKDATA_T                   rKBDCtrPeekData; \
   SKBD_CTRL_KEYDATA_T                      rKBDCtrGetData; \
   SKBD_CTRL_MODE_T  			rKBDCtrMode;\
   SKBD_CTRL_KEY_CNT_T			rKBDCtrkeyCnt;\
   SKBD_CTRL_PUTKEY_T			rKBDCtrPutKey;\
      SKBD_CTRL_FIND_TWO_STEP_T   rKBDCtrlFindTwoStepKey;
#endif

#endif
#endif

#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_SKBD_H_PROTOTYPE__
#define __DCL_SKBD_H_PROTOTYPE__

/*************************************************************************
* FUNCTION
*  DclSKBD_Initialize
*
* DESCRIPTION
*  This function is to initialize keypad hardware module, It is called during the driver initialization.
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclSKBD_Initialize(void);
/*************************************************************************
* FUNCTION
* DclSKBD_Open
*
* DESCRIPTION
*  This function is to open the keypad hw module and return a handle.
*
* PARAMETERS
*  dev: keypad device ID. it should be DCL_KBD.
*  flags: User of keypad driver. It should be the user module id, if the user does not module id, it can be set 0.
*
* RETURNS
*  DCL_HANDLE_INVALID: Incorrect device ID.
*  Other value: A valid handle
*
* EXAMPLE
*  <code>
*  DCL_HANDLE kbd_handle;
*  kbd_handle = DclSKBD_Open(DCL_KBD, MOD_DRVKBD);
*  </code>
*
*************************************************************************/
extern DCL_HANDLE DclSKBD_Open(DCL_DEV dev, DCL_FLAGS flags);

/*************************************************************************
* FUNCTION
*  DclSKBD_Close
*
* DESCRIPTION
* This function is to close the keypad driver.
*
* PARAMETERS
*  handle: the user handler of the keypad, which is returned by the DclSKBD_Close function.
*
* RETURNS
*  STATUS_OK: return successfully.
*
*************************************************************************/
extern DCL_STATUS DclSKBD_Close(DCL_HANDLE handle);
/*************************************************************************
* FUNCTION
*  DclSKBD_Control
*
* DESCRIPTION
* This function is to control the keypad driver, the user can call the interface to get the keypad driver services through the different commands.
* the control services is responsible for the software related services, the keypad hardware related services can be accessed through the DCLH** interface.  
* PARAMETERS
*  handle: the user handler of the keypad, which is returned by the DclSKBD_Open function.
*  cmd: the keypad driver control commands, the values can be get from the enum KBD_CMDS.
*  data: the data which is corresponed to the commands, the data type can beone of  the enum KBDS_CTRLS.
*
* RETURNS
*  DCL_HANDLE_INVALID: Incorrect device ID.
*STATUS_BUFFER_EMPTY:indicate the buffer is empty, when the command KBD_CMD_GET_KEY_DATA or KBD_CMD_PEEK_KEY_DATA is used.
*  STATUS_OK: return successfully.
*
* EXAMPLE
*  <code>
* DCL_CTRL_DATA_T sta;
* DCL_HANDLE handle1;
* handle1 = DclSKBD_Open(DCL_KBD, MOD_MMI);
* DclSKBD_Control(handle1,KBD_CMD_GET_KEY_EVENT_CNT , (DCL_CTRL_DATA_T*)&sta);
*return sta.rKBDCtrkeyCnt.keycnt;
*  </code>
*
*************************************************************************/
extern DCL_STATUS DclSKBD_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);

/*************************************************************************
* FUNCTION
*  DclSKBD_RegisterCallback
*
* DESCRIPTION
* This function is to register the hardware event callback function.
*
* PARAMETERS
*  handle: the user handler of the keypad, which is returned by the DclHKBD_Open function.
*  event:  Reserved.
*  callback: the callback function pointer.           
*
* RETURNS
*  DCL_HANDLE_INVALID: Incorrect device ID.
*  STATUS_INVALID_EVENT: the event parameter is not valid for the keypad.
*  STATUS_OK: return successfully.
*
*************************************************************************/
extern DCL_STATUS DclSKBD_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event,PFN_DCL_CALLBACK callback);
#endif
#endif

