#ifndef DCL_HTS_H_
#define DCL_HTS_H_

#include "dcl.h"

#define DCL_HTS_MAGIC_NUM  0x40000000

typedef DCL_UINT32 HTS_DEV;
typedef enum
{
	TOUCH_PANEL_R=1
}HTS_DEV_T;

typedef DCL_UINT32 HTS_EVENT;
typedef enum
{
   DCL_EVENT_HTS_PEN_DOWN=1, 
   DCL_EVENT_HTS_PEN_UP,
   DCL_EVENT_HTS_MAX
}HTS_EVENT_T;

//touch panel driver command of  hardware layer.
typedef DCL_UINT32 HTS_CMD;

typedef enum
{
	HTS_CMD_GET_TP_ADC,
	HTS_CMD_TS_READ_ADC,
	HTS_CMD_GET_TP_LEVEL,
	HTS_CMD_GET_TP_LEVEL_PRESSURE,
	HTS_CMD_TP_UPDATENOTIFY,
	HTS_CMD_GET_TP_PRESSURE,
	HTS_CMD_TP_PRESSURE_VALUE,
	HTS_CMD_SET_CONFIG,
	HTS_CMD_GET_TP_POINT,
	HTS_CMD_GET_TP_POINT_NUM,
	HTS_CMD_GET_TP_TYPE,
	HTS_CMD_SET_CALI_VALUE,
	HTS_CMD_GET_CALI_VALUE,
	HTS_CMD_SET_DEBOUNCE_TIME,
	HTS_CMD_GET_DEBOUNCE_TIME,
	HTS_CMD_SET_SPL_NUM,
	HTS_CMD_GET_SPL_NUM
}HTS_CMD_T;

//HTS_CMD_SET_DEBOUNCE_TIME
typedef struct
{
    DCL_UINT32 u4DebounceTime;
}HTS_CTRL_DT_T;


//HTS_CMD_TP_SET_PARAMETERS
typedef struct
{
   DCL_UINT32            u4SampleResolution;
   DCL_UINT32            u4ModeSelection;
} HTS_CTRL_CONFIG_T;
typedef enum {
	//Not use the same values as ts_hw.h
	//Otherwise it easy to cause bug if change ts_hw.h, but forget to change these
   DCL_TS_CMD_DIFFERENTIAL,
   DCL_TS_CMD_SINGLE_END,
   DCL_TS_CMD_MODE_8BIT,
   DCL_TS_CMD_MODE_10BIT,
   DCL_TS_CMD_MODE_12BIT
} HTS_PARAMETER_T;

//HTS_CMD_TP_LEVEL,
typedef struct
{
   DCL_BOOL  fgIsUP;
   DCL_UINT32 pressure_value;
} HTS_CTRL_TL_T;


//HTS_CMD_TP_READ_ADC
typedef struct
{
   DCL_INT16 *pi2x;
   DCL_INT16 *pi2y;
} HTS_CTRL_TPRA_T;

//HTS_CMD_TS_READ_ADC
typedef enum {
   TS_COORD_HTS_ADDR_Y, 
   TS_COORD_HTS_ADDR_Z1,
   TS_COORD_HTS_ADDR_Z2,
   TS_COORD_HTS_ADDR_X
} TS_COORD_ENUM;
typedef struct
{
   DCL_INT16 i2AdcValue;
   TS_COORD_ENUM uCoord;
} HTS_CTRL_TSRA_T;

//HTS_CMD_TP_PRESSURE
typedef struct
{
   DCL_BOOL  fgIsPressed;
} HTS_CTRL_TPP_T;

//HTS_CMD_TP_PRESSURE_VALUE
typedef struct
{
   DCL_INT32  fgPressureValue;
} HTS_CTRL_TPPV_T;
//HTS_CMD_READ_ADC
typedef struct
{
   DCL_INT16 *pi2x;
   DCL_INT16 *pi2y;
} HTS_CTRL_RA_T;

//HTS_CMD_ADC_TO_COORDINATE
typedef struct
{
   DCL_BOOL fgValid;
   DCL_INT16 *pi2x;
   DCL_INT16 *pi2y;
} HTS_CTRL_ATC_T;

//HTS_CMD_GET_SPL_NUM
typedef struct
{
    DCL_UINT32 u4SPLNum;
}HTS_CTRL_SN_T;

typedef union 
{
	HTS_CTRL_TL_T	   rTSCtrlTL; 
	HTS_CTRL_TPRA_T    rTSCtrlTPRA; 
	HTS_CTRL_TSRA_T    rTSCtrlTSRA; 
	HTS_CTRL_TPP_T	   rTSCtrlTPP; 
	HTS_CTRL_TPPV_T    rTSCtrlTPPV; 
	HTS_CTRL_RA_T	   rTSCtrlRA; 
	HTS_CTRL_ATC_T	   rTSCtrlATC;
	HTS_CTRL_CONFIG_T  rTSCtrlConfig;
	HTS_CTRL_DT_T      rTSCtrlDebouncetime;
	HTS_CTRL_SN_T      rTSCtrlSPLNum;
}HTS_CTRL_DATA_T;


/*************************************************************************
* FUNCTION                                                            
*	DclHTS_Close
*
* DESCRIPTION                                                           
*   This function is to close the HW TS module.
*
* CALLS  
*	It is called to close HW TS module
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
extern DCL_STATUS DclHTS_Close(DCL_HANDLE handle);
/*************************************************************************
* FUNCTION                                                            
*	DclHTS_Configure
*
* DESCRIPTION                                                           
*   This function is to configure the HW TS module.
*
* CALLS  
*	It is called to configure of the HW TS module.
*
* PARAMETERS
*	handle - a valid handle return by DclHTS_Open()
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
//extern DCL_STATUS DclHTS_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
/*************************************************************************
* FUNCTION                                                            
*	DclHTS_Control
*
* DESCRIPTION                                                           
*   	This function is to send command to control the TS module.
*
* CALLS  
*	It is called to send command to control the TS module.
*
* PARAMETERS
*	handle - a valid handle return by DclHTS_Open()
*   cmd   - a control command for TS module
*           1. HTS_CMD_TP_LEVEL           :to detect whether TP is touched or NOT
*           2. HTS_CMD_TP_UPDATE_NOTIFY   :to set a event to TP task to indicate we are at UP state
*           3. HTS_CMD_TP_READ_ADC        :to read x and y adc value from AUXADC HW. (with touch_panel_filter_thresold which avoid detect error)
*           4. HTS_CMD_TP_PRESSURE        :to check is touch panel pressed.
*           5. HTS_CMD_TS_DRV_INIT        :to initial HW driver and switch on work around funciton
*           6. HTS_CMD_READ_ADC           :to read adc from touch panel module. (with Landscape support, compile option: __PORTRAIT_LCM_SIMULATE_LANDSCAPE_LCM__)
*           7. HTS_CMD_TS_READ_ADC        :to read x or y adc value from AUXADC HW.
*
*   data - a union of DCL_CTRL_DATA_T
*            rTSCtrlTL;    //HTS_CTRL_TL_T
*            rTSCtrlTPRA;  //HTS_CTRL_TPRA_T
*            rTSCtrlTPP;   //HTS_CTRL_TPP_T
*            rTSCtrlRA;    //HTS_CTRL_RA_T
*            rTSCtrlTSRA   //HTS_CMD_TS_READ_ADC
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
extern DCL_STATUS DclHTS_Control(DCL_HANDLE handle, HTS_CMD cmd, HTS_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION                                                            
*	DclHTS_Initialize
*
* DESCRIPTION                                                           
*   This function is to initialize HW TS module
*
* CALLS  
*	It is called to initialize HW TS module
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
extern DCL_STATUS DclHTS_Initialize(void);
/*************************************************************************
* FUNCTION                                                            
*	DclHTS_Open
*
* DESCRIPTION                                                           
*   	This function is to open the TS HW module and return a handle
*
* CALLS  
*	It is called to open HW TS module
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
extern DCL_HANDLE DclHTS_Open(HTS_DEV dev, DCL_FLAGS flags);
/*************************************************************************
* FUNCTION                                                            
*	DclHTS_ReadData
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
extern DCL_STATUS DclHTS_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);
/*************************************************************************
* FUNCTION                                                            
*	DclHTS_RegisterCallback
*
* DESCRIPTION                                                           
*   	This function is to register HW TS call back funciton.
*
* CALLS  
*	It is called to register HW TS call back funciton.
*
* PARAMETERS
*	event - a valid event indicate register which event's call back funciton
*            1. DCL_EVENT_HTS_PEN_DOWN,
*            2. DCL_EVENT_HTS_PEN_UP 
*   callback - a call back funciton
*	
* RETURNS
*	STATUS_OK: register is executed successfully.
*	STATUS_FAIL: register is failed.
*   STATUS_INVALID_CMD: It's a invalid command.
*
* GLOBALS AFFECTED
*   external_global
*************************************************************************/
extern DCL_STATUS DclHTS_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);






#endif









