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
 *    e_compass_sensor.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module is for e_compass sensor driver.
 *
 * Author:
 * Peter Zhang
 *
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef E_COMPASS_SENSOR_H
#define E_COMPASS_SENSOR_H

#define E_COMPASS_SENSOR_BUFFER_SIZE 0x08 /* Must be a power of 2. */

typedef enum {
    E_COMPASS_SENSOR_BUFF_EMPTY,
    E_COMPASS_SENSOR_BUFF_DATA_EXIST,
    E_COMPASS_SENSOR_BUFF_FULL
} E_Compass_Sensor_BuffState_enum;

/* we use this enum to save calibration state */
typedef enum {
    E_COMPASS_SENSOR_CALI_NONE,
    E_COMPASS_SENSOR_START_CALI,
    E_COMPASS_SENSOR_CALI_FINISHED,
    E_COMPASS_SENSOR_CALI_ABORTED
} E_Compass_Sensor_Cali_enum;

/* we use this enum to save calibration result */
typedef enum {
    E_COMPASS_SENSOR_CALI_SUCCESS,
    E_COMPASS_SENSOR_CALI_FAILED
} E_Compass_Sensor_Cali_Result_enum;

#if defined (E_COMPASS_MAGNETIC_DETECT)
/* we use this enum to save magnetic state */
typedef enum {
    E_COMPASS_SENSOR_MAGNETIC_NORMAL,
    E_COMPASS_SENSOR_MAGNETIC_ABNORMAL
} E_Compass_Sensor_Magnetic_State_enum;
#endif /* E_COMPASS_MAGNETIC_DETECT */

typedef struct
{
    kal_uint16  angle;
} E_CompassSensorDataStruct;

typedef struct
{
    kal_int16   usr_moffset_x;
    kal_int16   usr_moffset_y;
    kal_int16   usr_moffset_z;
    kal_bool    cali_result;

    kal_int32   x_axis_sensitivity;		/*x axis data sensitivity*/
    kal_int32   y_axis_sensitivity;		/*y axis data sensitivity*/
    kal_int16   x_max; 			/*sample point maximum of x coordinate*/
    kal_int16   x_min; 			/*sample point minimum of x coordinate*/
    kal_int16   y_max; 			/*sample point maximum of y coordinate*/
    kal_int16   y_min; 			/*sample point minimum of y coordinate*/

    kal_int32       ext_para1;
    kal_int32       ext_para2;
    kal_int32       ext_para3;
    kal_int16       ext_para4;
    kal_int16       ext_para5;
    kal_int16       ext_para6;
    kal_int16       ext_para7;
    kal_int16       ext_para8;
    kal_int16       ext_para9;
} E_CompassSensorCalibratedDataStruct;

typedef void (*EC_DATA_FUNC)(void *parameter,E_Compass_Sensor_BuffState_enum state);
typedef void (*EC_CALI_FUNC)(void *parameter,E_Compass_Sensor_Cali_Result_enum result);
#if defined (E_COMPASS_MAGNETIC_DETECT)
typedef void (*EC_MAG_FUNC)(void *parameter,E_Compass_Sensor_Magnetic_State_enum state);
#endif /* E_COMPASS_MAGNETIC_DETECT */

typedef struct
{
    EC_DATA_FUNC        data_cb_func;
    EC_CALI_FUNC        cali_cb_func;
#if defined (E_COMPASS_MAGNETIC_DETECT)
    EC_MAG_FUNC         mag_cb_func;
#endif /* E_COMPASS_MAGNETIC_DETECT */
    void                *data_para;
    void                *cali_para;
#if defined (E_COMPASS_MAGNETIC_DETECT)
    void                *mag_para;
#endif /* E_COMPASS_MAGNETIC_DETECT */
    kal_eventgrpid      event;                      /* event id */
    E_Compass_Sensor_Cali_enum  cali_state;         /* calibration state */
    kal_uint8           sample_handle;              /* GPT timer handle for sample */
}E_CompassSensorStruct;

typedef struct
{
    E_CompassSensorDataStruct   e_compass_sensor_data[E_COMPASS_SENSOR_BUFFER_SIZE];
    kal_uint16                  e_compass_sensor_rindex;
    kal_uint16                  e_compass_sensor_windex;
}E_CompassSensorBufferStruct;

/* customization part */
typedef struct
{
    kal_uint8   calibration_sample_dura;        /* GPT timer duration for calibration sample, *10ms */
    kal_uint8   normal_sample_dura;             /* GPT timer duration for normal sample, *10ms */
    kal_uint8   poweron_delay;                  /* SW timer for sensor power on delay, *4.615ms */
} E_CompassSensor_custom_data_struct;

typedef struct
{
    E_CompassSensor_custom_data_struct * (*ec_get_data)(void);      /* return configuration data */
    void (*ec_read_adc)(kal_int16 *x,kal_int16 *y,kal_int16 *z);    /* read raw data from e_compass sensor */
#if defined (__E_COMPASS_MIDDLEWARE_DEBUG__)
    void (*ec_middleware_dump)(kal_int16 *x,kal_int16 *y,kal_int16 *z); /* middleware parameter dump */
#endif  /* __E_COMPASS_MIDDLEWARE_DEBUG__ */
    kal_bool (*ec_convert)(kal_int16 x, kal_int16 y, kal_int16 z,E_CompassSensorDataStruct *e_compass_data);    /* convert raw data to angle */
    E_Compass_Sensor_Cali_enum (*ec_calibrate)(kal_int16 x, kal_int16 y, kal_int16 z);  /* e_compass calibration */
    void (*ec_calibrate_cancel)(void);  /* e_compass calibration cancel */
    void (*ec_middleware_init)(void);   /* sensor middleware init */
    void (*ec_turn_on)(kal_uint8 stage);    /* turn on sensor */
    void (*ec_turn_off)(void);          /* turn off sensor */
#if defined (E_COMPASS_MAGNETIC_DETECT)
    void (*ec_get_magnetic_data)(E_Compass_Sensor_Magnetic_State_enum *e_compass_mag_data);             /* driver want to get magnetic field data */
#endif /* E_COMPASS_MAGNETIC_DETECT */
    void (*ec_get_calibrated_data)(E_CompassSensorCalibratedDataStruct *e_compass_calibrated_data);     /* driver want to get calibrated data */
    void (*ec_init_calibrated_data)(E_CompassSensorCalibratedDataStruct *e_compass_calibrated_data);    /* driver want to init middleware calibration data */
    void (*ec_custom_init)(void);
    void (*ec_take_measurement)(void);   /* command of fetching raw data */
}E_CompassSensor_customize_function_struct;

/* For MMI */
extern void e_compass_sensor_power_on(void);
extern void e_compass_sensor_power_off(void);
extern void e_compass_enable(kal_bool enable);
extern void e_compass_sensor_start_cali(void);
extern void e_compass_sensor_cancel_cali(void);
/* extern kal_bool e_compass_sensor_power(kal_bool enable); */
/* extern void e_compass_sensor_flush_buff(void); */
extern void e_compass_sensor_data_cb_registration(EC_DATA_FUNC cb_fun,void *para);
extern void e_compass_sensor_cali_cb_registration(EC_CALI_FUNC cb_fun,void *para);
#if defined (E_COMPASS_MAGNETIC_DETECT)
extern void e_compass_sensor_mag_cb_registration(EC_MAG_FUNC cb_fun,void *para);
#endif /* E_COMPASS_MAGNETIC_DETECT */
extern kal_bool e_compass_sensor_get_data(E_CompassSensorDataStruct *e_compass_data);
extern kal_bool e_compass_get_calibration_result(void);
extern void e_compass_sensor_manual_init(void);

/* For driver */
extern void e_compass_init(void);
extern void e_compass_main_hdr(void);
extern void e_compass_nvram_init(void);

#if defined (E_COMPASS_DRV_DEBUG)
#define E_COMPASS_DEBUG_OUTPUT(_string,_var1,_var2,_var3,_var4) \
{ \
    char sTemp[100]; \
    sprintf(sTemp,(_string),(_var1),(_var2),(_var3),(_var4)); \
    kal_print(sTemp); \
}
#else
#define E_COMPASS_DEBUG_OUTPUT(_string,_var1,_var2,_var3,_var4)
#endif

#endif
