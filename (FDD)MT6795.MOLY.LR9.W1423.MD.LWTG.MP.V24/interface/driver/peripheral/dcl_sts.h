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
 *   dcl_ts.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for TS.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_TS_H_STRUCT__
#define __DCL_TS_H_STRUCT__


/*******************************************************************************
 * DCL_OPTIONS for TS
 *******************************************************************************/
#define TS_OPTIONS 

// Earlier defined in dcl_ts.c. Moved here so that application files can use this define

/*******************************************************************************
 * DCL_CONFIGURE_T
 *******************************************************************************/

#define TS_CONFIGS    \
   //TS_CONFIG_T   rTSConfig;

/*******************************************************************************
 * DCL_EVENT for TS
 *******************************************************************************/
#define TS_EVENTS \
   DCL_EVENT_STS_PUSH_BUFF = 1, \
   DCL_EVENT_STS_UP,			\
   DCL_EVNET_STS_DOWN,			\
   DCL_EVENT_STS_MAX, 

/*******************************************************************************
 * DCL_CTRL_CMD for TS
 *******************************************************************************/
#define TS_CMDS    \
   STS_CMD_GET_EVENT, \
   STS_CMD_PEEK_EVENT, \
   STS_CMD_ENABLE, \
   STS_CMD_FLUSH, \
   STS_CMD_START_CALI, \
   STS_CMD_STOP_CALI, \
   STS_CMD_READ_CALI, \
   STS_CMD_SET_CALI, \
   STS_CMD_RESET, \
   STS_CMD_RESET_HANDWRITING, \
   STS_CMD_CONF_SAMPLE_PERIOD, \
   STS_CMD_CONF_MOVE_OFFSET, \
   STS_CMD_CONF_HANDWRITING, \
   STS_CMD_POWER_ON, \
   STS_CMD_CONF_TIMEOUT_PERIOD, \
   STS_CMD_CTRL_CUSTOM_PARAM,\
   STS_CMD_CTRL_CUSTOM_PARAM_RANGE,\
   STS_CMD_CTRL_MICRONMETER_TO_COORD,\
   STS_CMD_CTRL_COORD_TO_MICRONMETER,\
   STS_CMD_QUERY_TP_TYPE,\
   STS_CMD_SET_DEVICE,\
   STS_CMD_COMMAND,
  
/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/
/* For TS_CMD command. */


//STS_CMD_QUERY_TP_TYPE
typedef enum
{
    RTP_Type = 0,
    CTP_Type
    
}DCL_TP_TYPE_Enum;

typedef struct
{
    DCL_TP_TYPE_Enum TouchPanelType;
}DCL_TP_TYPE_T;


//STS_CMD_CTRL_CUSTOM_PARAM
typedef enum
{
    TP_PARAM_GET = 0,
    TP_PARAM_SET,
    TP_PARAM_RESET
}TP_CTRL_PARAM_TYPE;

typedef struct {
   kal_uint32 ts_debounce_time;
   kal_uint32 touch_panel_cali_check_offset;
   kal_uint32 min_pen_move_offset;
   kal_uint32 hand_writing_max_offset;
   kal_uint32 nonhand_writing_max_offset;
   kal_uint32 max_stroke_move_offset;
   kal_uint32 multiple_point_selection;
   kal_uint32 touch_pressure_threshold_high;
   kal_uint32 touch_pressure_threshold_low;
   kal_uint32 pressure_check_boundary;
   kal_uint32 pressure_shifting_boundary;
   kal_uint32 border_pass_criterion;
   kal_uint32 non_border_pass_criterion;
   kal_uint32 border_range;
   kal_uint32 jitter_circuit_interval;
   kal_uint32 Dump_Screen;
   kal_uint32 reserve_parameter1; //use for AUX_SPL_NUM
   kal_uint32 reserve_parameter2;
   kal_uint32 reserve_parameter3;
   kal_uint32  height; // get only
   kal_uint32  width;  // get only
} TouchPanel_EM_custom_data_struct; 

typedef struct
{
    TP_CTRL_PARAM_TYPE type;
    TouchPanel_EM_custom_data_struct* pEmData;
}DCL_CTRL_CUSTOM_PARAM_T;



typedef struct
{
 kal_int32 ts_debounce_time_min;                             
 kal_int32 ts_debounce_time_max;
kal_int32 touch_panel_cali_check_offset_min;         
kal_int32 touch_panel_cali_check_offset_max;
kal_int32 min_pen_move_offset_min;                       
kal_int32 min_pen_move_offset_max;
kal_int32 hand_writing_max_offset_min;                  
kal_int32 hand_writing_max_offset_max;
kal_int32 nonhand_writing_max_offset_min;            
kal_int32 nonhand_writing_max_offset_max;
kal_int32 max_stroke_move_offset_min;                  
kal_int32 max_stroke_move_offset_max;
kal_int32 multiple_point_selection_min;                    
kal_int32 multiple_point_selection_max;
kal_int32 touch_pressure_threshold_high_min;        
kal_int32 touch_pressure_threshold_high_max;
kal_int32 pressure_check_boundary_min;                
kal_int32 pressure_check_boundary_max;
kal_int32 pressure_shifting_boundary_min;              
kal_int32 pressure_shifting_boundary_max;
kal_int32 border_pass_criterion_min;                        
kal_int32 border_pass_criterion_max;
kal_int32 nonborder_pass_criterion_min;                  
kal_int32 nonborder_pass_criterion_max;
kal_int32 border_range_min;                                     
kal_int32 border_range_max;
kal_uint32 jitter_circuit_interval_min;
kal_uint32 jitter_circuit_interval_max;
kal_uint32 Dump_Screen_min;
kal_uint32 Dump_Screen_max;
kal_int32 reserve_parameter1_min;                           
kal_int32 reserve_parameter1_max;
kal_int32 reserve_parameter2_min;                           
kal_int32 reserve_parameter2_max;
kal_int32 reserve_parameter3_min;                           
kal_int32 reserve_parameter3_max;
}TP_PARAM_RANGE;

//STS_CMD_CTRL_CUSTOM_PARAM_RANGE
typedef struct
{
    TP_CTRL_PARAM_TYPE type;
    TP_PARAM_RANGE* pEmDataRange;
}DCL_CTRL_CUSTOM_PARAM_RANGE_T;

//   STS_CMD_CTRL_MICRONMETER_TO_PIXEL
typedef struct
{
    kal_uint32 x_micronmeter;
    kal_uint32 y_micronmeter;
    kal_uint32 x_coord;
    kal_uint32 y_coord;
}DCL_CTRL_MICRONMETER_COORD_T;



//STS_CMD_GET_EVENT

typedef enum {
      DCL_PEN_DOWN,    /*0*/  
      DCL_PEN_UP,      /*1*/
      DCL_PEN_MOVE,    /*2*/
      DCL_PEN_LONGTAP, /*3*/     
      DCL_PEN_REPEAT,  /*4*/ 
      DCL_PEN_ABORT,   /*5*/ 
      DCL_TP_UNKNOWN_EVENT,/*6*/
      DCL_STROKE_MOVE,     /*7*/
      DCL_STROKE_STATICAL, /*8*/
      DCL_STROKE_HOLD, /*9*/
      DCL_PEN_LONGTAP_HOLD, /*10*/
      DCL_PEN_REPEAT_HOLD,  /*11*/ 
      DCL_STROKE_DOWN=0xc0, /*0*/        /*1*/
      DCL_STROKE_LONGTAP=0x7e,   /*8*/
      DCL_STROKE_UP=0x7f/*127*/
} DCL_TP_Event_enum;

/*
typedef struct
{
   DCL_INT16     i2xAdc;
   DCL_INT16     i2yAdc;
   DCL_TP_Event_enum rEvent;
   DCL_UINT16    i2TimeStamp;		// unit: system tick
} STS_CTRL_GET_T;
*/

typedef struct
{
   // Touch_Panel_Event_enum
   DCL_UINT16 u2Event; 
   /*coordinate point, not diff*/
   DCL_UINT16 u2x;
   DCL_UINT16 u2y;
   DCL_UINT16 u2z; //resistance TP: presure,  capacitive TP: area
} DCL_TP_SINGLE_EVENT_T;

typedef struct
{
   DCL_UINT16   uModel; // Single/Dual/Triple/Four/Five/All gesture 
   DCL_UINT16   uPadding; //currently use for check the structure format correctness, 0xAA
   DCL_UINT32  u2Time_stamp;
   DCL_TP_SINGLE_EVENT_T rPoints[5];
} STS_CTRL_GET_T;

//STS_CMD_ENABLE
typedef struct
{
   DCL_BOOL fgEnable;
} STS_CTRL_EN_T;

typedef struct  
{       
	kal_uint8 	ref_count;
	kal_uint16 	msg_len;			/* LOCAL_PARA_HDR */	
	kal_bool 	result;
}tp_cali_done_struct; 

//STS_CMD_START_CALI
typedef struct
{   
   DCL_INT16 i2x;  /*x coordinate*/
   DCL_INT16 i2y;  /*y coordinate*/ 
} TS_COORD_T;
typedef struct
{
   TS_COORD_T *rpPoint;
   DCL_UINT16 u2Num;
} STS_CTRL_SC_T;

//STS_CMD_READ_CALI
typedef struct
{  
   /*x*/ 
   double x_slope;
   double x_offset; 
   /*y*/   
   double y_slope;
   double y_offset; 
} TS_CALI_T; 
typedef struct
{
   TS_CALI_T rCali;
} STS_CTRL_RC_T;

//STS_CMD_SET_CALI
typedef struct
{
   TS_CALI_T rCali;
} STS_CTRL_SETC_T;

//STS_CMD_RESET
typedef struct
{
   DCL_BOOL fgSkipUnreleaseEnable;
} STS_CTRL_RESET_T;

//STS_CMD_CONF_SAMPLE_PERIOD
typedef struct
{
   DCL_UINT32 u4Low;
   DCL_UINT32 u4High;
} STS_CTRL_CSP_T;

//STS_CMD_CONF_MOVE_OFFSET
typedef struct
{
   DCL_UINT16 u2Pen_offset;
   DCL_UINT16 u2Stroke_offset;
   DCL_UINT16 u2Longtap_pen_offset;
   DCL_UINT16 u2Longtap_stroke_offset;
} STS_CTRL_CMO_T;

//STS_CMD_CONF_HANDWRITING
typedef struct
{  
   TS_COORD_T rMin;
   TS_COORD_T rMax;
} TS_HandArea_T;
typedef struct
{
   TS_HandArea_T *rArea;
   DCL_UINT16 u2n;
   TS_HandArea_T *rExtArea;
} STS_CTRL_CHW_T;

//STS_CMD_CONF_TIMEOUT_PERIOD
typedef struct
{
   DCL_UINT32 u4Longtap;
   DCL_UINT32 u4Repeat;
   DCL_UINT32 u4Handwriting_longtap;
} STS_CTRL_CTP_T;

//STS_CMD_POWER_ON
typedef struct
{
   DCL_BOOL fgPowerOn;
} STS_CTRL_POWER_ON_T;

//STS_CMD_SET_DEVICE
typedef enum 
{
   DCL_CTP_ACTIVE_MODE,
   DCL_CTP_IDLE_MODE,
   DCL_CTP_SLEEP_MODE,
   DCL_CTP_GESTURE_DETECTION_MODE,
   DCL_CTP_MULTIPLE_POINT_MODE,
   DCL_CTP_FIRMWARE_UPDATE,
   DCL_CTP_FM_ENABLE,
   DCL_CTP_FM_DISABLE
}DCL_CTP_DEVICE_MODE_enum;

typedef struct
{
   DCL_CTP_DEVICE_MODE_enum mode;
} STS_CTRL_SET_DEVICE_T;

//STS_CMD_COMMAND
typedef enum 
{
   DCL_CTP_COMMAND_GET_VERSION,
   DCL_CTP_COMMAND_GET_CONFIG,
   DCL_CTP_COMMAND_LOAD_INT_CONFIG,
   DCL_CTP_COMMAND_LOAD_EXT_CONFIG,
   DCL_CTP_COMMAND_GET_DIFF_DATA,
   DCL_CTP_COMMAND_GET_FW_BUFFER,
   DCL_CTP_COMMAND_DO_FW_UPDATE
}DCL_CTP_CTRL_COMMAND_enum;

typedef struct
{
   DCL_UINT32 u4Command;
   void *pVoid1;
   void *pVoid2;
} STS_CTRL_COMMAND_T;

#define TS_CTRLS \
   STS_CTRL_GET_T     rTSCtrlGE; \
   STS_CTRL_EN_T      rTSCtrlEN; \
   STS_CTRL_SC_T      rTSCtrlSC; \
   STS_CTRL_RC_T      rTSCtrlRC; \
   STS_CTRL_SETC_T    rTSCtrlSETC; \
   STS_CTRL_RESET_T   rTSCtrlRESET; \
   STS_CTRL_CSP_T     rTSCtrlCSP; \
   STS_CTRL_CMO_T     rTSCtrlCMO; \
   STS_CTRL_CHW_T     rTSCtrlCHW; \
   STS_CTRL_POWER_ON_T rTSCtrlPO; \
   STS_CTRL_CTP_T     rTSCtrlCTP; \
   DCL_CTRL_CUSTOM_PARAM_T rTSCtrlCustomParam;\
   DCL_CTRL_CUSTOM_PARAM_RANGE_T rTSCtrlCustomParamRang;\
   DCL_CTRL_MICRONMETER_COORD_T rTSCtrlMicronMeter_Pixel;\
   DCL_TP_TYPE_T                            rTSCtrlTouchPanelType;\
   STS_CTRL_SET_DEVICE_T rTSCtrlSD;\
   STS_CTRL_COMMAND_T rTSCtrlCmd;


#endif // #ifndef __DCL_TS_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT   


#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_TS_H_PROTOTYPE__
#define __DCL_TS_H_PROTOTYPE__


/*************************************************************************
* FUNCTION                                                            
*	DclSTS_Configure
*
* DESCRIPTION                                                           
*   This function is to configure the SW TS module.
*
* CALLS  
*	It is called to configure of the SW TS module.
*
* PARAMETERS
*	handle - a valid handle return by DclSTS_Open()
*   configure - a structure which include the TS configuration.  
*	
* RETURNS
*	STATUS_OK: command is executed successfully.
*	STATUS_FAIL: not open yet.
*   STATUS_INVALID_ARGUMENT: not a valid handle.
*
* GLOBALS AFFECTED
*   external_global
*************************************************************************/
extern DCL_STATUS DclSTS_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION                                                            
*	DclSTS_Control
*
* DESCRIPTION                                                           
*   	This function is to send command to control the SW TS module.
*
* CALLS  
*	It is called to send command to control the SW TS module.
*
* PARAMETERS
*	handle - a valid handle return by DclSTS_Open()
*   cmd   - a control command for TS module
*           1. STS_CMD_ENABLE             :enable/disable touch panel
*           2. STS_CMD_FLUSH              :to flush all data in ring buffer.
*           3. STS_CMD_START_CALI         :to do coordinate calibration. 
*           4. STS_CMD_STOP_CALI          :to stop coordinate calibration.
*           5. STS_CMD_READ_CALI          :to read coordinate calibration.
*           6. STS_CMD_SET_CALI           :to set coordinate calibration.
*           7. STS_CMD_RESET              :to reset touch panel driver. 
*           8. STS_CMD_RESET_HANDWRITING  :to reset handwriting area as normal.
*           9. STS_CMD_CONF_SAMPLE_PERIOD :to configure sample period in handwriting and non-handwriting area.
*          10. STS_CMD_CONF_MOVE_OFFSET   :to configure pen move offset and stroke move offset.
*          11. STS_CMD_CONF_HANDWRITING   :to configure handwriting area.
*          12. STS_CMD_CONF_TIMEOUT_PERIOD:to configure period of long tap and repeat event.
*          13. STS_CMD_GET_EVENT          :to read event from ring buffer
*          13. STS_CMD_PEEK_EVENT         :to peek event from ring buffer

*   data - a union of DCL_CTRL_DATA_T
*            rTSCtrlEN;     //STS_CMD_ENABLE
*            rTSCtrlSC;     //STS_CMD_START_CALI
*            rTSCtrlRC;     //STS_CMD_READ_CALI
*            rTSCtrlSETC;   //STS_CMD_SET_CALI
*            rTSCtrlRESET;  //STS_CMD_RESET
*            rTSCtrlCSP;    //STS_CMD_CONF_SAMPLE_PERIOD
*            rTSCtrlCMO;    //STS_CMD_CONF_MOVE_OFFSET
*            rTSCtrlCHW;    //STS_CMD_CONF_HANDWRITING
*            rTSCtrlCTP;    //STS_CMD_CONF_TIMEOUT_PERIOD
*            rTSCtrlGE;     //STS_CMD_GET_EVENT
*            rTSCtrlGE;     //STS_CMD_PEEK_EVENT
*
* RETURNS
*	STATUS_OK: command is executed successfully.
*	STATUS_FAIL: command is failed.
*   STATUS_INVALID_CMD: It's a invalid command.
*   STATUS_INVALID_ARGUMENT: not a valid handle.
*
* GLOBALS AFFECTED
*   external_global
*************************************************************************/
extern DCL_STATUS DclSTS_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION                                                            
*	DclSTS_Initialize
*
* DESCRIPTION                                                           
*   This function is to initialize SW TS module
*
* CALLS  
*	It is called to initialize SW TS module
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
extern DCL_STATUS DclSTS_Initialize(void);
/*************************************************************************
* FUNCTION                                                            
*	DclSTS_Open
*
* DESCRIPTION                                                           
*   	This function is to open the TS SW module and return a handle
*
* CALLS  
*	It is called to open SW TS module
*
* PARAMETERS
*	dev - valid for DCL_TS
*	flags - no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*	DCL_HANDLE_INVALID - Open failed.
*   Other value - a valid handle
*
* GLOBALS AFFECTED
*   external_global
*************************************************************************/
extern DCL_HANDLE DclSTS_Open(DCL_DEV dev, DCL_FLAGS flags);
/*************************************************************************
* FUNCTION                                                            
*	DclSTS_ReadData
*
* DESCRIPTION
*   This function unsupported.
*
* CALLS  
*	It is unsupported.
*
* PARAMETERS
*	handle
*   buff  
*   buf_len 
*   options  
*	
* RETURNS
*	STATUS_UNSUPPORTED: command unsupported
*
* GLOBALS AFFECTED
*   external_global
*************************************************************************/
extern DCL_STATUS DclSTS_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION                                                            
*	DclSTS_RegisterCallback
*
* DESCRIPTION                                                           
*   	This function is to register SW TS call back funciton.
*       Execute call back function when we push ts data into ts ring buffer.
*
* CALLS  
*	It is called to register SW TS call back funciton.
*
* PARAMETERS
*	event - a valid event indicate register which event's call back funciton
*           1. DCL_EVENT_STS_PUSH_BUFF
*
*   callback - a call back funciton
*	
* RETURNS
*	STATUS_OK: command is executed successfully.
*	STATUS_FAIL: command is failed.
*   STATUS_INVALID_CMD: It's a invalid command.
*
* GLOBALS AFFECTED
*   external_global
*************************************************************************/
extern DCL_STATUS DclSTS_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);
/*************************************************************************
* FUNCTION                                                            
*	DclSTS_Close
*
* DESCRIPTION                                                           
*   This function is to close the SW TS module.
*
* CALLS  
*	It is called to close SW TS module
*
* PARAMETERS
*	None
*	
* RETURNS
*	DCL_STATUS_OK
*   STATUS_INVALID_ARGUMENT: invalid arguments
*
* GLOBALS AFFECTED
*   external_global
*************************************************************************/
extern DCL_STATUS DclSTS_Close(DCL_HANDLE handle);


#endif // #ifndef __DCL_TS_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE
