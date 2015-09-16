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
 *    drvsignals.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for driver primitives.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _DRVSIGNALS_H
#define _DRVSIGNALS_H

#include "bmt.h"
#include "usb_comm.h"
#include "kal_public_api.h" //#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"
#include "kal_general_types.h"
#include "dcl.h"


/*RTC driver*/
#define RTC_TC_IND			0
#define RTC_AL_IND			1
typedef struct {
	LOCAL_PARA_HDR
	kal_uint8 		rtc_ind;
} RTC_Primitive;

typedef struct {
	LOCAL_PARA_HDR
    DCL_RTC_DATA_T      previous_rtc;
    DCL_RTC_DATA_T      new_rtc;        
} RTC_Time_Change_IND_Struct;

/*Kbd driver*/
#define Kbd_KeyPress			0
#define Kbd_KeyRelease		1
typedef struct {
	LOCAL_PARA_HDR
	kal_uint8 		kp_status;
	kal_uint8 		key;
} Kbd_Primitive;

/*Communicated with MMI, charging status*/
typedef enum 
{
   BMT_CHARGER_IN = 0,
   BMT_CHARGER_OUT,
   BMT_OVERVOLPROTECT,
   BMT_OVERBATTEMP,
   BMT_LOWBATTEMP,
   BMT_OVERCHARGECURRENT,
   BMT_CHARGE_COMPLETE,
   BMT_INVALID_BAT,
   BMT_INVALID_CHARGER,
   BMT_CHARGE_TIMEOUT,
   BMT_LOWCHARGECURRENT,
   BMT_CHARGE_BAD_CONTACT,
   BMT_BATTERY_BAD_CONTACT,
   BMT_USB_CHARGER_IN,
   BMT_USB_CHARGER_OUT,
   BMT_USB_NO_CHARGING_IN,
   BMT_USB_NO_CHARGING_OUT,
   BMT_BATT_IN,
   BMT_BATT_OUT
}BMT_CHR_STAT;

typedef struct {
	LOCAL_PARA_HDR
	BMT_CHR_STAT 		status;
} drvuem_pmic_ind_struct;

/*ADC scheduler*/
typedef struct {
	LOCAL_PARA_HDR
	double         adc_value;
	kal_int32 		adc_handle;
	kal_int32 		volt;
	kal_uint8 		adc_sche_id;
} bmt_adc_measure_done_conf_struct;

typedef struct {
	LOCAL_PARA_HDR
	kal_int32 adc_handle;
	kal_uint8 adc_sche_id;
} bmt_adc_add_item_req_struct;

typedef struct {
	LOCAL_PARA_HDR
	kal_int32 adc_handle;
	kal_uint8 adc_sche_id;
} bmt_adc_remove_item_req_struct;

typedef struct {
	LOCAL_PARA_HDR
	kal_int32   adc_handle;
	kal_uint32  period;
	kal_uint8   evaluate_count;
	kal_uint8   adc_sche_id;
} bmt_adc_modify_parameters_req_struct;

/*AUX task*/
typedef enum 
{
   AUX_ID_PLUGOUT=0,
   AUX_ID_TVOUT,
   AUX_ID_EARPHONE,
   AUX_ID_KEY_PRESS,
   AUX_ID_KEY_RELEASE,
   AUX_ID_UART,
   AUX_ID_CLAM_OPEN,
   AUX_ID_CLAM_CLOSE,
   AUX_ID_TVOUT_OUT,
   AUX_ID_TVOUT_INIT1,
   AUX_ID_DETECTION_DONE,
   AUX_ID_PLUGIN,
   AUX_ID_TRANSMITTER_HOLD_ON,
   AUX_ID_TRANSMITTER_PUT_DOWN,
   AUX_MAX_ID
}AUX_ID;
typedef struct {
	LOCAL_PARA_HDR
	AUX_ID   aux_id;
} aux_id_struct;

/*Engineering mode*/
typedef struct {
   LOCAL_PARA_HDR
   kal_int32 		vbat;	/*Battery Voltage(micro-voltage)*/
   kal_int32     bat_temp;	/*Battery Temperature(¢J)*/
   kal_int32 		vaux;		/*AUX Voltage(micro-voltage)*/
   kal_int32 		charge_current;	/*Charge current(micro-A)*/
   kal_int32 		vcharger;	/*Charger Voltage(micro-voltage)*/
} adc_all_channel_struct;

/*USB driver*/
typedef struct {
	LOCAL_PARA_HDR
   void                 *pData; /* Pointer to data buffer */
   kal_int32             nBuffLen; /* Length of data buffer */
	kal_int32             nBytesRecv; /* Number of bytes received */
} usb_ms_rec_done_conf_struct;

/*L4->USB*/
typedef struct {
   LOCAL_PARA_HDR
   USB_DEVICE_TYPE         mode;
   kal_uint32        *parameter;
} drvuem_usbcfg_req_struct;

/*USB->USB*/
typedef struct {
   LOCAL_PARA_HDR
   USB_DEVICE_TYPE         mode;
   kal_uint32        *parameter;
   kal_uint32 device_code;
   kal_uint32 subclass_code;
   kal_uint32 protocol_code;
   kal_uint32 product_code;
} drvusb_usbcfg_req_struct;

/*USB->L4*/
typedef struct {
   LOCAL_PARA_HDR
   USB_DEVICE_TYPE         mode;
   kal_uint32        reserved;
   kal_bool          result;
} drvuem_usbcfg_cnf_struct;

/*USB->L4*/
typedef enum 
{
   DETECT_ACTION_UNKNOWN=0,
   DETECT_ACTION_PLUGIN,
   DETECT_ACTION_PLUGOUT,
   DETECT_ACTION_USB_SUSPEND,
   DETECT_ACTION_MAX_ID
}USB_DETECT_ACTION_ID;

typedef struct {
   LOCAL_PARA_HDR
   USB_DETECT_ACTION_ID         action;  /*1: Plugin, 0:PlugOut*/
}drvuem_usbdetect_ind_struct;

// add for usb charging
typedef enum{
	BMT_USB_100,
	BMT_USB_500
}bmt_usb_ind_enum;

typedef struct{
	LOCAL_PARA_HDR
	PMU_CHR_CURRENT_ENUM  usb_ind;
}bmt_usb_ind_struct;

typedef struct{
	LOCAL_PARA_HDR
	PW_CTRL_POWER_ON_REASON power_on;
	kal_uint32 	poweron_time_left;
}drvuem_power_on_ind_struct;



typedef struct {
   LOCAL_PARA_HDR
   kal_uint8 usb_ip_port;
   kal_uint8 feature_index;
//  USB_HCD_STATUS result;
   kal_uint8 result;
   kal_uint32 param;
}usb_host_usbattach_ind_struct;



typedef struct {
   LOCAL_PARA_HDR
   kal_bool confirm;
}rndis_usb_config_cnf_struct;



/* ----------------------------------MTP------------------------------------*/

/*
 * Macro
 */
#define MTP_PARAM_MAX   5
#define MTP_EVENT_MAX   3

/*
 * Enum
 */

typedef enum {
   USB_MTP_RESULT_OK = 0,
   USB_MTP_RESULT_CONTINUE,
   USB_MTP_RESULT_ABORTED,
   USB_MTP_RESULT_DEVICE_BUSY,
   USB_MTP_RESULT_NOT_ENABLE,
   USB_MTP_RESULT_ALREADY_ENABLE,
   USB_MTP_RESULT_UNKNOWN_ERROR
}usb_mtp_result_enum;


typedef enum {
   USB_MTP_EVENT_NORMAL = 0,
   USB_MTP_EVENT_ABORT
}usb_mtp_event_enum;


/*
 * Struct
 */

typedef struct {
   LOCAL_PARA_HDR
   kal_int32  result_code; /* <  0: FS error
                                         >= 0: usb_mtp_result_enum */
}usb_mtp_enable_rsp_struct, usb_mtp_disable_rsp_struct;


typedef struct {
   LOCAL_PARA_HDR
   kal_uint16 op_code;                     /* operation */
   kal_uint32 op_params[MTP_PARAM_MAX];    /* operation */
               
//   kal_uint16 op_serial_no;                /* start from 0 */

   /* Data phase */
   kal_uint32 data_total_size;             /* size of total data, 0 means no Data phase */
   kal_uint8  *data_pool_ptr;              /* data pool */
   kal_uint32 data_pool_size;              /* size of data pool */
   kal_uint32 data_size;                   /* size of real data, signle direction */
}usb_mtp_operation_req_struct;


typedef struct {
   LOCAL_PARA_HDR
    
   kal_int32  result_code; /* <  0: FS error
                               >= 0: usb_mtp_result_enum */                
   kal_uint16 rsp_code;
   kal_uint32 rsp_params[MTP_PARAM_MAX];

   kal_uint16 op_code;
//   kal_uint16 op_serial_no;                /* start from 0 */

   /* Data phase */
   kal_uint32 data_total_size;             /* size of total data, 0 means no Data phase */
   kal_uint8  *data_pool_ptr;              /* data pool */
   kal_uint32 data_pool_size;              /* size of data pool */
   kal_uint32 data_size;                   /* size of real data */
}usb_mtp_operation_rsp_struct;


typedef struct {
   LOCAL_PARA_HDR
   kal_uint16 event;       // see usb_mtp_event_enum
   kal_uint16 event_code;
   kal_uint32 params[MTP_EVENT_MAX];
}usb_mtp_event_ind_struct;


#endif

