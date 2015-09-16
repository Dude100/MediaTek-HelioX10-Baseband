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
 *    e_compass_sensor.c
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
//MSBB remove #include "custom_config.h"
#include "gpio_sw.h"
#include "drv_comm.h"
#include "svc_sap.h"
#include "nvram_msgid.h"
#if defined (__E_COMPASS_SENSOR_SUPPORT__)
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "syscomp_config.h" /*MOD_EC_TASK*/
#include "stacklib.h"       /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"     /* Event scheduler */
#include "stack_timer.h"    /*Timer*/
//MSBB remove #include "app_buff_alloc.h" /*buffer*/
#include "task_config.h"    /* Task creation */
#include "e_compass_sensor.h"
#include "e_compass_sensor_custom.h"
#include "e_compass_sensor_buff.h"
#include "gpt_sw.h"

#include "nvram_struct.h"
#include "nvram_enums.h"
#include "nvram_data_items.h"
#include "nvram_editor_data_item.h"
#include "nvram.h"
#include "nvram_interface.h"

#include "drv_trc.h"

/*Variable Declaration*/
E_CompassSensorStruct e_compass_sensor_data;
E_CompassSensorBufferStruct e_compass_sensor_buff;
E_CompassSensor_customize_function_struct *e_compass_sensor_custom_fp;
E_CompassSensor_custom_data_struct *e_compass_sensor_custom_dp;

static kal_timerid  e_compass_power_on_timer_id = 0;
static kal_bool is_e_compass_enabled = KAL_FALSE;
static kal_bool nvram_cali_result = KAL_FALSE;
/* we use it to keep latest calibrated data */
static E_CompassSensorCalibratedDataStruct e_compass_calibrated_data;

/* middleware output should not exceed max value */
#define E_COMPASS_SENSOR_OUTPUT_MAX         360

/* local function declare */
static void e_compass_sensor_power_on_callback(void *timer_param);
static void e_compass_enable_driver(kal_bool enable);
static void e_compass_write_nvram(E_CompassSensorCalibratedDataStruct *calibrated_data);

/* GPT timer callback */
void e_compass_sample_cb(void *parameter)
{
    kal_set_eg_events(e_compass_sensor_data.event,1,KAL_OR);
}

/*E_Compass main function*/
/*
* FUNCTION                                                            
*   e_compass_start_cali
*
* DESCRIPTION                                                           
*       This function is to start calibration
*
* CALLS  
*
* PARAMETERS
*   None
*	
* RETURNS
*   None
*/
void e_compass_sensor_start_cali(void)
{
    drv_trace0(TRACE_GROUP_10, EC_CALIBRATION_START);
    e_compass_enable_driver(KAL_FALSE);
    e_compass_sensor_data.cali_state = E_COMPASS_SENSOR_START_CALI;
    e_compass_enable_driver(KAL_TRUE);
}

/*
* FUNCTION                                                            
*   e_compass_sensor_cancel_cali
*
* DESCRIPTION                                                           
*       This function is to cancel calibration
*
* CALLS  
*
* PARAMETERS
*   None
*	
* RETURNS
*   None
*/
void e_compass_sensor_cancel_cali(void)
{
    drv_trace0(TRACE_GROUP_10, EC_CALIBRATION_ABORT);
    e_compass_enable_driver(KAL_FALSE);
    /* end user cancel calibration */
    if (E_COMPASS_SENSOR_START_CALI == e_compass_sensor_data.cali_state)
    {
        /* calibration is on-going, we can cancel */
        e_compass_sensor_data.cali_state = E_COMPASS_SENSOR_CALI_ABORTED;
    }
    /* else we do nothing. Driver might have finished calibration */

    e_compass_enable_driver(KAL_TRUE);
} 

/*
* FUNCTION                                                            
*   e_compass_sensor_init
*
* DESCRIPTION                                                           
*       This function is to initialize e_compass sensor driver
*
* CALLS  
*
* PARAMETERS
*   None
*	
* RETURNS
*   None
*/
void e_compass_init(void)
{
    /*get customization functin data and function pointr*/
    e_compass_sensor_custom_fp = ec_GetFunc();
    e_compass_sensor_custom_fp->ec_custom_init();
    e_compass_sensor_custom_dp=e_compass_sensor_custom_fp->ec_get_data();

    /* init calibration state and GPT handle for sample and calibration */
    e_compass_sensor_data.cali_state = E_COMPASS_SENSOR_CALI_NONE;
    GPTI_GetHandle(&(e_compass_sensor_data.sample_handle));

    e_compass_flush_data_buffer();

    e_compass_power_on_timer_id = kal_create_timer("E_Compass_Power_On_Timer");
}
     
/*
* FUNCTION                                                            
*   e_compass_sensor_flush_buff
*
* DESCRIPTION                                                           
*       This function is to flush data buffer
*
* CALLS  
*
* PARAMETERS
*   None
*	
* RETURNS
*   None
*/
/* void e_compass_sensor_flush_buff(void)
{
    e_compass_flush_data_buffer();   
} */

/*
* FUNCTION                                                            
*   e_compass_sensor_data_cb_registration
*
* DESCRIPTION                                                           
*       This function is to register callback function for new data
*
* CALLS  
*
* PARAMETERS
*   cb_fun:callback function 
*   para: parameter of callback function
*
* RETURNS
*   None
*/
void e_compass_sensor_data_cb_registration(EC_DATA_FUNC cb_fun,void *para)
{
    e_compass_sensor_data.data_cb_func = cb_fun;
    e_compass_sensor_data.data_para = para;
}   

/*
* FUNCTION                                                            
*   e_compass_sensor_cali_cb_registration
*
* DESCRIPTION                                                           
*       This function is to register callback function for calibration
*
* CALLS  
*
* PARAMETERS
*   cb_fun:callback function 
*   para: parameter of callback function
*
* RETURNS
*   None
*/
void e_compass_sensor_cali_cb_registration(EC_CALI_FUNC cb_fun,void *para)
{
    e_compass_sensor_data.cali_cb_func = cb_fun;
    e_compass_sensor_data.cali_para = para;
}   

#if defined (E_COMPASS_MAGNETIC_DETECT)
/*
* FUNCTION                                                            
*   e_compass_sensor_mag_cb_registration
*
* DESCRIPTION                                                           
*       This function is to register callback function for magnetic detection
*
* CALLS  
*
* PARAMETERS
*   cb_fun:callback function 
*   para: parameter of callback function
*
* RETURNS
*   None
*/
void e_compass_sensor_mag_cb_registration(EC_MAG_FUNC cb_fun,void *para)
{
    e_compass_sensor_data.mag_cb_func = cb_fun;
    e_compass_sensor_data.mag_para = para;
}   
#endif /* E_COMPASS_MAGNETIC_DETECT */

/*
* FUNCTION                                                            
*   e_compass_sensor_get_data
*
* DESCRIPTION                                                           
*       This function is to get converted data
*
* CALLS  
*
* PARAMETERS
*   e_compass_data: data pointer
*	
* RETURNS
*   result
*/
kal_bool e_compass_sensor_get_data(E_CompassSensorDataStruct *e_compass_data)
{
    kal_bool result;
    kal_uint16 avail_data_size;

    /* disable sample firstly */
    e_compass_enable_driver(KAL_FALSE);

    ec_get_buf_avail(avail_data_size);
    if (0 != avail_data_size)
    {
        e_compass_pop_data_from_buffer(*e_compass_data);
        result = KAL_TRUE;
    }
    else
    {
        result = KAL_FALSE;
    }

    /* enable sample again */
    e_compass_enable_driver(KAL_TRUE);

    return result;
}

/*
* FUNCTION                                                            
*   e_compass_get_calibration_result
*
* DESCRIPTION                                                           
*       This function is to get previous calibration result
*
* CALLS  
*
* PARAMETERS
*   None
*	
* RETURNS
*   previous calibration result
*/
kal_bool e_compass_get_calibration_result(void)
{
    return nvram_cali_result;
}

/*
* FUNCTION                                                            
*   e_compass_nvram_init
*
* DESCRIPTION                                                           
*       This function is to read calibrated data from NvRAM
*
* CALLS  
*
* PARAMETERS
*   None
*	
* RETURNS
*   None
*/
void e_compass_nvram_init(void)
{
    static kal_bool is_e_compass_nvram_init = KAL_FALSE;
    nvram_ef_ecompass_calibration ec_nvram;

    if (KAL_FALSE == is_e_compass_nvram_init)
    {
        /* read data from NvRAM */
        nvram_external_read_data(NVRAM_EF_ECOMPASS_DATA_LID, 1, (kal_uint8 *)&ec_nvram, sizeof(nvram_ef_ecompass_calibration));
        /* E_COMPASS_DEBUG_OUTPUT("Read from NvRAM usr_moffset_x = %d, usr_moffset_y = %d, usr_moffset_z = %d, misc = %d", ec_nvram.usr_moffset_x, ec_nvram.usr_moffset_y, ec_nvram.usr_moffset_z, 0); */
        drv_trace4(TRACE_GROUP_10, EC_NVRAM_READBACK, ec_nvram.usr_moffset_x, ec_nvram.usr_moffset_y, ec_nvram.usr_moffset_z, ec_nvram.cali_result);

        e_compass_calibrated_data.usr_moffset_x = ec_nvram.usr_moffset_x;
        e_compass_calibrated_data.usr_moffset_y = ec_nvram.usr_moffset_y;
        e_compass_calibrated_data.usr_moffset_z = ec_nvram.usr_moffset_z;
        e_compass_calibrated_data.cali_result   = ec_nvram.cali_result;

        e_compass_calibrated_data.x_axis_sensitivity = ec_nvram.x_axis_sensitivity;
        e_compass_calibrated_data.y_axis_sensitivity = ec_nvram.y_axis_sensitivity;
        e_compass_calibrated_data.x_max              = ec_nvram.x_max;
        e_compass_calibrated_data.y_max              = ec_nvram.y_max;
        e_compass_calibrated_data.x_min              = ec_nvram.x_min;
        e_compass_calibrated_data.y_min              = ec_nvram.y_min;

        nvram_cali_result                       = ec_nvram.cali_result;

        /* we just read NvRAM once */
        is_e_compass_nvram_init = KAL_TRUE;
    }
}

/*************************************************************************
* FUNCTION
*   e_compass_sensor_power_on
*
* DESCRIPTION
*   This function is to turn on sensor
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void e_compass_sensor_power_on(void)
{
    static kal_bool is_middleware_init = KAL_FALSE;

    drv_trace0(TRACE_GROUP_10, EC_CALIBRATION_POWERON);

    if (KAL_FALSE == is_middleware_init)
    {
        /* we just need to initialize middleware once */
        e_compass_sensor_custom_fp->ec_init_calibrated_data(&e_compass_calibrated_data);
        is_middleware_init = KAL_TRUE;
    }

    e_compass_sensor_custom_fp->ec_turn_on(1);
    /* we start timer, after timer expired, it will invoke e_compass_sensor_power_on_callback
       because sensor need some time to be ready after power on */
    kal_set_timer(e_compass_power_on_timer_id,(kal_timer_func_ptr)e_compass_sensor_power_on_callback,NULL,
                  e_compass_sensor_custom_dp->poweron_delay,0);
}

/*for e_compass sensor power on */
static void e_compass_sensor_power_on_callback(void *timer_param)
{
    e_compass_sensor_custom_fp->ec_turn_on(2);

    /* enable E_Compass here after sensor and NvRAM are ready */
    e_compass_enable(KAL_TRUE);
}

/*************************************************************************
* FUNCTION
*   e_compass_sensor_power_off
*
* DESCRIPTION
*   This function is to turn off sensor
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void e_compass_sensor_power_off(void)
{
    drv_trace0(TRACE_GROUP_10, EC_CALIBRATION_POWEROFF);
    e_compass_enable(KAL_FALSE);
    e_compass_sensor_custom_fp->ec_turn_off();
}

/*************************************************************************
* FUNCTION
*   e_compass_enable
*
* DESCRIPTION
*   This function is to enable/disbale e_compass module.
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void e_compass_enable(kal_bool enable)
{
    /* save flag, normally driver will not modify this flag. */
    is_e_compass_enabled = enable;

    e_compass_enable_driver(enable);
}

static void e_compass_enable_driver(kal_bool enable)
{
    if (KAL_TRUE == enable)
    {
        e_compass_sensor_custom_fp->ec_take_measurement();

        /* we have different GPT timer for different state */
        if (E_COMPASS_SENSOR_START_CALI != e_compass_sensor_data.cali_state)
            GPTI_StartItem(e_compass_sensor_data.sample_handle,e_compass_sensor_custom_dp->normal_sample_dura,e_compass_sample_cb,NULL);
        else
            GPTI_StartItem(e_compass_sensor_data.sample_handle,e_compass_sensor_custom_dp->calibration_sample_dura,e_compass_sample_cb,NULL);
    }
    else
    {
        GPTI_StopItem(e_compass_sensor_data.sample_handle);
    }
}


/*************************************************************************
* FUNCTION
*   e_compass_sensor_manual_init
*
* DESCRIPTION
*   This function is to configure sensor middleware manually, end user must keep handset horizontal.
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void e_compass_sensor_manual_init(void)
{
    drv_trace0(TRACE_GROUP_10, EC_MIDDLEWARE_MANUAL_INIT);
    e_compass_enable_driver(KAL_FALSE);
    /* sensor middleware init */
    e_compass_sensor_custom_fp->ec_middleware_init();
    e_compass_enable_driver(KAL_TRUE);
}

static void e_compass_write_nvram(E_CompassSensorCalibratedDataStruct *calibrated_data)
{
    ilm_struct *ec_ilm_ptr = 0;
    void *parm_stream = 0;
    void *data_stream = 0;
    kal_uint16 pdu_len;
    nvram_ef_ecompass_calibration ec_nvram;
    module_type module_id;

    module_id = MOD_EC_TASK;

    /* for now we just save three fields */
    ec_nvram.usr_moffset_x = calibrated_data->usr_moffset_x;
    ec_nvram.usr_moffset_y = calibrated_data->usr_moffset_y;
    ec_nvram.usr_moffset_z = calibrated_data->usr_moffset_z;
    ec_nvram.cali_result   = calibrated_data->cali_result;

    ec_nvram.x_axis_sensitivity = calibrated_data->x_axis_sensitivity;
    ec_nvram.y_axis_sensitivity = calibrated_data->y_axis_sensitivity;
    ec_nvram.x_max              = calibrated_data->x_max;
    ec_nvram.y_max              = calibrated_data->y_max;
    ec_nvram.x_min              = calibrated_data->x_min;
    ec_nvram.y_min              = calibrated_data->y_min;

    /* E_COMPASS_DEBUG_OUTPUT("Calibrated result usr_moffset_x = %d, usr_moffset_y = %d, usr_moffset_z = %d, misc = %d", ec_nvram.usr_moffset_x, ec_nvram.usr_moffset_y, ec_nvram.usr_moffset_z, 0); */
    drv_trace4(TRACE_GROUP_10, EC_NVRAM_SAVE, ec_nvram.usr_moffset_x, ec_nvram.usr_moffset_y, ec_nvram.usr_moffset_z, ec_nvram.cali_result);

    ec_ilm_ptr = allocate_ilm(module_id);
    ec_ilm_ptr->msg_id = MSG_ID_NVRAM_WRITE_REQ;

    parm_stream = construct_local_para(sizeof(nvram_write_req_struct), TD_CTRL);
    data_stream = construct_peer_buff(sizeof(nvram_ef_ecompass_calibration), 0, 0, TD_CTRL);

    ((nvram_write_req_struct*) parm_stream)->file_idx = NVRAM_EF_ECOMPASS_DATA_LID;
    ((nvram_write_req_struct*) parm_stream)->para = 1;

    pdu_len = sizeof(nvram_ef_ecompass_calibration);
    kal_mem_cpy(get_pdu_ptr(data_stream, &pdu_len), (void*)&ec_nvram, sizeof(nvram_ef_ecompass_calibration));

    ec_ilm_ptr->local_para_ptr = (local_para_struct*) parm_stream;
    ec_ilm_ptr->peer_buff_ptr = (peer_buff_struct*) data_stream;

    ec_ilm_ptr->src_mod_id  = module_id;
    ec_ilm_ptr->dest_mod_id = MOD_NVRAM;
    ec_ilm_ptr->sap_id = PS_NVRAM_SAP;
    msg_send_ext_queue(ec_ilm_ptr);
}

/*************************************************************************
* FUNCTION
*   e_compass_main_hdr
*
* DESCRIPTION
*   This function is to handle event.
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void e_compass_main_hdr(void)
{
    kal_int16 x,y,z;
    kal_uint16 room;
    E_Compass_Sensor_Cali_enum cali_result;
    E_CompassSensorDataStruct angle;
#if defined (E_COMPASS_MAGNETIC_DETECT)
    E_Compass_Sensor_Magnetic_State_enum mag_state;
#endif /* E_COMPASS_MAGNETIC_DETECT */

    /* disable example, maybe it is not necessary, GPT is one-shot, anyway it is harmless */
    e_compass_enable_driver(KAL_FALSE);

    /* read raw data */
    e_compass_sensor_custom_fp->ec_read_adc(&x,&y,&z);
    /* E_COMPASS_DEBUG_OUTPUT("Raw data X = %d, Y = %d, Z = %d, misc = %d", x, y, z, 0); */
    drv_trace4(TRACE_GROUP_10, EC_RAW_DATA, x, y, z, 0);

    switch (e_compass_sensor_data.cali_state)
    {
    case E_COMPASS_SENSOR_CALI_NONE:
        /* normal case, we will convert raw data to angle */
#if defined (__E_COMPASS_MIDDLEWARE_DEBUG__)
        {
            kal_int16 mag_x_dump;
            kal_int16 mag_y_dump;
            kal_int16 mag_z_dump;
            e_compass_sensor_custom_fp->ec_middleware_dump(&mag_x_dump,&mag_y_dump,&mag_z_dump);
            drv_trace4(TRACE_GROUP_10, EC_MIDDLEWARE_DUMP, mag_x_dump, mag_y_dump, mag_z_dump, 0);
        }
#endif  /* __E_COMPASS_MIDDLEWARE_DEBUG__ */

        e_compass_sensor_custom_fp->ec_convert(x,y,z,&angle);
        if (E_COMPASS_SENSOR_OUTPUT_MAX >= angle.angle)
        {
            e_compass_sensor_custom_fp->ec_get_calibrated_data(&e_compass_calibrated_data);
            if (KAL_TRUE == e_compass_calibrated_data.cali_result)
            {
                /* save calibrated data into NvRAM */
                e_compass_write_nvram(&e_compass_calibrated_data);
            }

            drv_trace1(TRACE_GROUP_10, EC_ATTITUDE_ANGLE, angle.angle);

#if defined (E_COMPASS_MAGNETIC_DETECT)
            /* we detect magnetic field here */
            e_compass_sensor_custom_fp->ec_get_magnetic_data(&mag_state);
            e_compass_sensor_data.mag_cb_func(e_compass_sensor_data.mag_para,mag_state);
            drv_trace1(TRACE_GROUP_10, EC_MAGNETIC_STATE, mag_state);
#endif /* E_COMPASS_MAGNETIC_DETECT */

            ec_get_buf_roomleft(room);
            if (0 != room)
            {
                e_compass_push_data_to_buffer(angle,room);
            }
            else
            {
                /* there is no room, if SW goes to here, that means something abnormal, MMI has not handled nofication for a long time
                   we do nothing here */
            }
        }
        break;

    case E_COMPASS_SENSOR_START_CALI:
        /* end user has started calibration */
        cali_result = e_compass_sensor_custom_fp->ec_calibrate(x,y,z);
        if (E_COMPASS_SENSOR_CALI_FINISHED == cali_result)
        {
            e_compass_sensor_custom_fp->ec_get_calibrated_data(&e_compass_calibrated_data);
            if (KAL_TRUE == e_compass_calibrated_data.cali_result)
            {
                /* save calibrated data into NvRAM */
                e_compass_write_nvram(&e_compass_calibrated_data);

                /* calibration finished, we need to inform end user */
                e_compass_sensor_data.cali_cb_func(e_compass_sensor_data.cali_para,E_COMPASS_SENSOR_CALI_SUCCESS);
            }
            else
            {
                /* calibration finished, we need to inform end user */
                e_compass_sensor_data.cali_cb_func(e_compass_sensor_data.cali_para,E_COMPASS_SENSOR_CALI_FAILED);
            }
            drv_trace1(TRACE_GROUP_10, EC_CALIBRATION_RESULT, e_compass_calibrated_data.cali_result);
            /* reset calibration state */
            e_compass_sensor_data.cali_state = E_COMPASS_SENSOR_CALI_NONE;
        }
        break;

    case E_COMPASS_SENSOR_CALI_ABORTED:
        /* E_COMPASS_DEBUG_OUTPUT("Calibration aborted: %d %d %d %d", 0, 0, 0, 0); */
        /* end user cancel calibration, we need to do something */
        e_compass_sensor_custom_fp->ec_calibrate_cancel();

        /* reset calibration state */
        e_compass_sensor_data.cali_state = E_COMPASS_SENSOR_CALI_NONE;
        break;

    case E_COMPASS_SENSOR_CALI_FINISHED:
    default:
        /* we should not go to here, assert will happen */
        ASSERT(0);
    }

    /* enable sample again, for the safe reason, if MMI has disabled it, however driver task still runs to here, we should double check */
    if (KAL_TRUE == is_e_compass_enabled)
        e_compass_enable_driver(KAL_TRUE);
}

#endif
