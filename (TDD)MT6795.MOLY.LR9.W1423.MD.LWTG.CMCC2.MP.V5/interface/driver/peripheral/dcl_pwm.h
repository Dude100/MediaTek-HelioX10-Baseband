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
 *   dcl_PWM.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for PWM.
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
#ifndef __DCL_PWM_H_STRUCT__
#define __DCL_PWM_H_STRUCT__
//#include "kal_non_specific_general_types.h"  //it is empty ,we don't delete it in order to avoid  vilating  HAL rule 1

#include "kal_general_types.h"
#define  PWM_OUTPUT_LOW   0
#define  PWM_OUTPUT_HIGH  1
//******************************************
#define  PWM_MAX_FREQ     50000
#define  PWM_MAX_DUTY     100
#define  PWM_MIN_FREQ     50
#define  PWM_MIN_DUTY     1
//******************************************
typedef struct
{
   DCL_UINT8  pitch;  /*note vlaue*/
   DCL_UINT8  volume; /*note volume*/
   DCL_UINT16 on_duration;  /* in ms */
   DCL_UINT16 off_duration;  /* in ms */
}BuzNoteStruct;

typedef struct
{
   DCL_UINT8 volume;
   DCL_UINT8 stop;
   DCL_UINT32 handle;  /*GPT handle*/
   BuzNoteStruct NotesData;
   kal_bool (*GetNotesCallbac)(BuzNoteStruct *Buz);
   void (*EndofAlterPlay)(void);
}ALterNoteStruct;

/* PWM wrok mode enumerate*/
typedef enum
{
   PWM_FIFO_MODE=0,
   PWM_MEMO_MODE,
   PWM_OLD_MODE,
   PWM_RANDOM_MODE,
   PWM_MODE_COUNT
}pwm_mode_e;

/*PWM FIFO mode data structure.[more detail in spec]*/
typedef struct 
{
   kal_uint32 data0;
   kal_uint32 data1;
   kal_uint16 repeat_count; /* 0 means endless repeat */
   kal_uint8  stop_bitpos; /* 0~63*/
   kal_uint16 high_dur; /* must>0. When set to N, the duration is N+1 clocks. */
   kal_uint16 low_dur; /* must>0. When set to N, the duration is N+1 clocks. */
   kal_uint16 guard_dur; /* must>0. When set to N, the duration is N+1 clocks. */
   kal_uint8  idle_output; /* PWM_OUTPUT_LOW or PWM_OUTPUT_HIGH */
   kal_uint8  guard_output; /* PWM_OUTPUT_LOW or PWM_OUTPUT_HIGH */
   void       (*pwm_callback)(kal_uint32 pwm_num);
}pwm_fifo_para_s;

/*PWM memory mode data structure.[more detail in spec] */
typedef struct 
{
   kal_uint32 *buf_addr;
   kal_uint16 buf_size;
   kal_uint16 repeat_count; /* 0 means endless repeat */
   kal_uint8  stop_bitpos; /* 0~31 in the last 32bits*/
   kal_uint16 high_dur; /* must>0. When set to N, the duration is N+1 clocks. */
   kal_uint16 low_dur; /* must>0. When set to N, the duration is N+1 clocks. */
   kal_uint16 guard_dur; /* must>0. When set to N, the duration is N+1 clocks. */
   kal_uint8  idle_output; /* PWM_OUTPUT_LOW or PWM_OUTPUT_HIGH */
   kal_uint8  guard_output; /* PWM_OUTPUT_LOW or PWM_OUTPUT_HIGH */
   void       (*pwm_callback)(kal_uint32 pwm_num);
}pwm_memo_para_s;

/*PWM old mode data structure.[more detail in spec]*/
typedef struct 
{
   kal_uint16 data_width;
   kal_uint16 threshold;
   kal_uint16 repeat_count; /* 0 means endless repeat */
   kal_uint16 guard_dur; /* must>0. When set to N, the duration is N+1 clocks. */
   kal_uint8  idle_output; /* PWM_OUTPUT_LOW or PWM_OUTPUT_HIGH */
   kal_uint8  guard_output; /* PWM_OUTPUT_LOW or PWM_OUTPUT_HIGH */
   void       (*pwm_callback)(kal_uint32 pwm_num);
}pwm_old_para_s;

/*PWM random mode data structure.[more detail in spec]*/
typedef struct 
{
   kal_uint32 *buf0_addr;
   kal_uint32 *buf1_addr;
   kal_uint16 buf0_size; /* must>0 */
   kal_uint16 buf1_size; /* must>0 */
   kal_uint16 high_dur; /* must>0. When set to N, the duration is N+1 clocks. */
   kal_uint16 low_dur; /* must>0. When set to N, the duration is N+1 clocks. */
   kal_uint8  idle_output; /* PWM_OUTPUT_LOW or PWM_OUTPUT_HIGH */
   void       (*pwm_invalid_cb)(kal_uint32 pwm_num, kal_uint8 buf_num);
   void       (*pwm_underflow_cb)(kal_uint32 pwm_num);
}pwm_random_para_s;

typedef struct
{
   DCL_UINT32 clksrc; //the Clock source of the PWM module.
   DCL_UINT32 clkdiv; //The Clock Divisor value.
}PWM_CONFIG_T;

#define PWM_CONFIGS    \
   PWM_CONFIG_T   rPWMConfig; 

#ifdef __BUILD_DOM__
/*
* The ALERTER Command values in DCL_CTRL_CMD_T Enum of dcl.h 
* DCL_CTRL_DATA_T Define the Control data structure for each module's command 
*/
typedef enum
{
   PWM_CMD_SEQ_OPEN, //This command is to open the PWM channel under the Sequential mode.
   PWM_CMD_SEQ_START, //This command is to enable PWM output under the Sequential mode.
   PWM_CMD_SEQ_STOP,  //This command is to stop PWM output under the Sequential mode.
   PWM_CMD_SEQ_CLOSE, //This command is to Close the PWM channel under the Sequential mode.
   PWM_CONFIG_FREQ_STEPS, //The command is to set the output frequency and the steps.it is used by the Camera AF lens driver. 
   PWM_CMD_SET_DUTY, //The function is to set the output duty value, it should not larger than the Steps in the above function.it is used by the Camera AF lens driver.
   PWM_CMD_OPEN, //This command is to Open PWM channel.This command should be called before any other configuration function.
   PWM_CMD_CLOSE, //The function is to close the PWM channel.it should be called after stop the PWM channel.
   PWM_CMD_START, //This command is to Start the PWM channel output.It is called after all the configuration finished
   PWM_CMD_STOP, //This command is to stop the PWM channel output.
   PWM_CMD_CONFIG, //This command is to configure the PWM channel working mode and setting the accoring mode parameter.
   PWM_CMD_CONFIG_OLD,  //This command is to configure the PWM1 output frequency and duty cycle.the function is to generate the simpliest periodical output signal.
   PWM_CMD_SET_BUF_VALID, //Set buffer status to be valid and update the buffer data.the function is called when receiving the finish interrupt under the random mode.it is responsible to call the function to update the buffer of the user.
   PWM_CMD_SET_DELAY, //This command is to set the delay time during the adjacent channels under the Sequential mode.
   //PWM_CMD_TEST_SEL,  should remove.
   PWM_CMD_GET_CURRENT_LEVEL, //This command is to get current PWM1 output level.
   PWM_CMD_GET_CURRENT_DUTY, //This command is to get current PWM1 output duty cycle.
   PWM_CMD_GET_CURRENT_FREQ, //This command is to get current PWM1 output duty cycle.
   ALERTER_CMD_CONFIGURE, //configure ALerter freq and duty.
   ALERTER_CMD_START, 	  //Start ALERTER module.
   ALERTER_CMD_STOP, 		  //Stop ALERTER module.
   ALERTER_CMD_PWROPEN, 
   ALERTER_CMD_OUTPUT, 
   ALERTER_CMD_PLAYNOTES, 
   ALERTER_CMD_STOPNOTES, 
   ALERTER_CMD_SETBUZVOLUME, 
   ALERTER_CMD_GETLEVEL,
}DCL_CTRL_CMD_T;
#else
#define PWM_CMDS    \
   PWM_CMD_SEQ_OPEN, \
   PWM_CMD_SEQ_START, \
   PWM_CMD_SEQ_STOP, \
   PWM_CMD_SEQ_CLOSE, \
   PWM_CONFIG_FREQ_STEPS, \
   PWM_CMD_START, \
   PWM_CMD_STOP, \
   PWM_CMD_GET_CURRENT_LEVEL, \
   PWM_CMD_GET_CURRENT_DUTY, \
   PWM_CMD_GET_CURRENT_FREQ, \
   PWM_CMD_CONFIG, \
   PWM_CMD_CONFIG_OLD, \
   PWM_CMD_SET_BUF_VALID, \
   PWM_CMD_SET_DELAY, \
   PWM_CMD_SET_DUTY, \
   PWM_CMD_TEST_SEL, \
   PWM_CMD_OPEN, \
   PWM_CMD_CLOSE,
   
#define ALERTER_CMDS \
   ALERTER_CMD_CONFIGURE, \
   ALERTER_CMD_START, \
   ALERTER_CMD_STOP, \
   ALERTER_CMD_PWROPEN, \
   ALERTER_CMD_OUTPUT, \
   ALERTER_CMD_PLAYNOTES, \
   ALERTER_CMD_STOPNOTES, \
   ALERTER_CMD_SETBUZVOLUME, \
   ALERTER_CMD_GETLEVEL,
   
#endif

/* For PWM_CMD_SEQ_START command parameter. */ 
typedef struct
{
   DCL_UINT8 uEnCount; //the PWM Channel Group of the Sequential mode
}PWM_CTRL_SS_T;

/* For PWM_CMD_CLK_INIT command parameter. */ 
typedef struct
{
   DCL_UINT32 u4ClkSel; //the Clock source of the PWM module.
   DCL_UINT32 u4ClkDiv; // The Clock Divisor value.
}PWM_CTRL_CI_T;

/* For PWM_CMD_SET_BUF_VALID command parameter. */ 
typedef struct
{
   DCL_UINT32 *pu4BufAddr; //the buffer address of the update data.
   DCL_UINT16  u2BufSize;  //the buffer size.
   DCL_BOOL   fgIsBuf0;    //the flag indicates whether buffer 0 is to be update
}PWM_CTRL_SBV_T;

/* For PWM_CMD_SET_DELAY command parameter. */ 
typedef struct
{
   DCL_UINT32 u4ClkSel; // the clock unit of the delay_cnt
   DCL_UINT16 u2DelayCnt; //the delay clock count of the two channels.
}PWM_CTRL_SD_T;

/* For PWM_CMD_TEST_SEL command parameter. */ 
typedef struct
{
   DCL_BOOLEAN bTestSel; 
}PWM_CTRL_TS_T;

/* For PWM_CMD_CONFIG command parameter. */ 
typedef struct
{
   DCL_UINT32 mode; //Set the work mode of the PWM channel.
   void *para; // The mode parameter.
}PWM_CTRL_CONFIG_T;

/* For PWM_CMD_CONFIG_OLD command parameter. */ 
typedef struct
{
   kal_uint32 freq; // the PWM channel output frequency.
   kal_uint8 duty;  // the duty cycle of the high level under the periodical output.
}PWM_CMD_CONFIG_OLD_T;

/*For
* PWM_CMD_GET_CURRENT_LEVEL, 
* PWM_CMD_GET_CURRENT_DUTY, 
* PWM_CMD_GET_CURRENT_FREQ, 
* command parameter
*/
typedef struct
{
   DCL_UINT8 	pwm_level;//return value of the command , the current level value
   DCL_UINT8 	pwm_duty; //return value of the command ,the current setting duty cycle value
   DCL_UINT32  pwm_freq;//return value of the command ,the current setting frequency value
}PWM_DATA_T;

/*For PWM_CMD_SET_DUTY command parameter.*/
typedef struct
{
   DCL_UINT16 duty; //the output duty value (0~steps).
}PWM_DUTY_T;

/*For PWM_CONFIG_FREQ_STEPS command parameter.*/
typedef struct
{
   kal_uint32 freq;  //the output frequency.
   kal_uint16 steps; //the lens driver steps.
}PWM_CONFIG_FREQ_STEPS_T;

//#if !defined(DRV_ALERTER_NOT_EXIST)
typedef struct
{
   DCL_UINT32 freq;
   DCL_UINT8  duty;
}ALERTER_CONFIGURE_T;

typedef struct
{
   DCL_BOOL poweron;
}ALERTER_PWROPEN_T;

typedef struct
{
   kal_bool (*GetNotecallbac)(BuzNoteStruct *Buz);
   void (*endofAlter)(void);
}ALERTER_PLAYNOTE_T;

typedef struct
{
   DCL_UINT8 volumn;
}ALERTER_SETVOLUMN_T;

typedef struct
{
   DCL_UINT8   mode;
   DCL_UINT8   clock;
}ALERTER_CONFIG_T;

typedef struct
{
   kal_uint8 output;
}ALERTER_OUTPUT_T;

typedef struct
{
   kal_uint8 level;
}ALERTER_LEVEL_T;

#define ALERTER_CTRLS		\
   ALERTER_CONFIGURE_T     ralertConfigure; \
   ALERTER_PWROPEN_T	      ralertPwrOpen; \
   ALERTER_PLAYNOTE_T      ralertPlayNote; \
   ALERTER_SETVOLUMN_T     ralertSetVolumn; \
   ALERTER_CONFIG_T        ralertConfig;	 \
   ALERTER_OUTPUT_T        ralertOutput;	\
   ALERTER_LEVEL_T         ralertlevel;


#define PWM_CTRLS \
   PWM_CTRL_SS_T           rPWMCtrlSS; \
   PWM_CTRL_CI_T           rPWMCtrlCI; \
   PWM_CTRL_SBV_T          rPWMCtrlSBV; \
   PWM_CTRL_SD_T           rPWMCtrlSD; \
   PWM_CTRL_TS_T           rPWMCtrlTS; \
   PWM_DUTY_T              rPWMCtrlDuty; \
   PWM_DATA_T              rPWMSaveData; \
   PWM_CTRL_CONFIG_T       rPWMConfig; \
   PWM_CONFIG_FREQ_STEPS_T rPWMFreqConfig; \
   PWM_CMD_CONFIG_OLD_T    rPWMConfigOld; 

#endif // #ifndef __DCL_PWM_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT   


#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_PWM_H_PROTOTYPE__
#define __DCL_PWM_H_PROTOTYPE__

/*************************************************************************
* FUNCTION                                                            
*	DclPWM_Close
*
* DESCRIPTION                                                           
*   	This function is to close the software layer of PWM module.
*
* CALLS  
*	It is called to close PWM(1~6) module
*
* PARAMETERS
*	None
*	
* RETURNS
*   DCL_STATUS_OK
*   STATUS_INVALID_ARGUMENT: invalid arguments
*
* GLOBALS AFFECTED
*   external_global
*************************************************************************/
extern DCL_STATUS DclPWM_Close(DCL_HANDLE handle);
/*************************************************************************
* FUNCTION                                                            
*	DclPWM_Configure
*
* DESCRIPTION                                                           
*   	This function is to configure the PWM module. Include clock sources and div vaules.
*
* CALLS  
*	It is called to configure of the PWM module.
*
* PARAMETERS
*   handle:  - a valid handle return by DclPWM_Configure()
*	
* RETURNS
*	STATUS_OK: command is executed successfully.
*	STATUS_FAIL: command is failed.
*
* GLOBALS AFFECTED
*   external_global
*************************************************************************/
extern DCL_STATUS DclPWM_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION                                                            
*	DclPWM_Control
*
* DESCRIPTION                                                           
*   	This function is to send command to control the PWM module.
*	All command 
*
* CALLS  
*	It is called to send command to control the PWM module.
*
* PARAMETERS
*   handle:  - a valid handle return by DclPWM_Open()
*   cmd:   - a control command for PWM module
*          1. PWM_CMD_START: to start a PWM timer
*          2. PWM_CMD_STOP: to stop a PWM timer
*          3. PWM_CMD_CONFIG: to config a pwm timer.
*          4. PWM_CMD_CONFIG_OLD
*          5. PWM_CMD_GET_CURRENT_LEVEL:
*          6. PWM_CMD_GET_CURRENT_DUTY:
*          7. PWM_CMD_GET_CURRENT_FREQ:
*	     8. PWM_CMD_OPEN
*	     9. PWM_CMD_CLOSE
*          10. PWM_CMD_SEQ_OPEN: 
*          11. PWM_CMD_SEQ_START:
*          12. PWM_CMD_SEQ_STOP:
*	     13. PWM_CMD_SEQ_CLOSE
*	     14. PWM_CMD_SET_BUF_VALID
*	     15. PWM_CMD_SET_DELAY
*	     16. PWM_CMD_TEST_SEL
*   data - for 1. PWM_CMD_START: poiter to a PWM_CTRL_START_T structure
*             2. PWM_CMD_STOP: a NULL pointer
*	 #if !defined(DRV_ALERTER_NOT_EXIST)
 #define ALERTER_CMDS
 ALERTER_CMD_CONFIGURE, \
 ALERTER_CMD_START,   \
 ALERTER_CMD_STOP,	  \
 ALERTER_CMD_PWROPEN, \
 ALERTER_CMD_OUTPUT,  \
 ALERTER_CMD_PLAYNOTES,   \
 ALERTER_CMD_STOPNOTES,   \
 ALERTER_CMD_SETBUZVOLUME,
 #endif 
* RETURNS
*	STATUS_OK: command is executed successfully.
*	STATUS_FAIL: command is failed.
*   STATUS_INVALID_CMD: It's a invalid command.
*
* GLOBALS AFFECTED
*   external_global
*************************************************************************/
extern DCL_STATUS DclPWM_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION                                                            
*	DclPWM_Initialize
*
* DESCRIPTION                                                           
*   	This function is to initialize PWM module, It's should be called during drv_init stage.
*	
*	For PWM, this function do nothing.
*
*	For RWG, this function create some global variable and LISR, HISR.
*	
* CALLS  
*	It is called to initialize PWM module
*
* PARAMETERS
*	None
*	
* RETURNS
*	DCL_STATUS_OK
*
* GLOBALS AFFECTED
*   external_global
*************************************************************************/
extern DCL_STATUS DclPWM_Initialize(void);
/*************************************************************************
* FUNCTION                                                            
*	DclPWM_Open
*
* DESCRIPTION                                                           
*   	This function is to open the software layer PWM module and return a software handle.
*     This function don't open the PWM hardware power or generate out wave. 
*	This is only for software layer to avoid multi open by different module.
*
*	If you want to power on or start PWM hardware , you should send a command by use of DclPWM_Control.
* CALLS  
*	It is called to open PWM module
*
* PARAMETERS
*	dev 	 - 	valid for DCL_PWM1 ~ DCL_PWM6
*	flags -	module name that call this fuction. 
*
* RETURNS
*   DCL_HANDLE_OCCUPIED: - Open failed.
*   STATUS_INVALID_ARGUMENT:  - invalid arguments
*   other value:  - a valid handle
*
* GLOBALS AFFECTED
*   external_global
*************************************************************************/
extern DCL_HANDLE DclPWM_Open(DCL_DEV dev, DCL_FLAGS flags);
/*************************************************************************
* FUNCTION
*  DclPWM_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the PWM module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
extern DCL_STATUS DclPWM_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);

#endif // #ifndef __DCL_PWM_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE


