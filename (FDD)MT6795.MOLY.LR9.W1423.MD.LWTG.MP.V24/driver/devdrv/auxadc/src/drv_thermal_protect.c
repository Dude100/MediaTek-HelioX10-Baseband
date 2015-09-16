#include "kal_general_types.h"
#include "kal_public_api.h"
#include "dcl.h"
#include "kal_trace.h"
#include "drv_thermal_protect.h"
#include "drv_emi.h"
#include "drv_features.h"

#if !defined(DRV_ADC_OFF)
#define DRV_THERMAL_PROTECT
#endif

/****** To Enable Phase 1 Mechanism **********/
#define THERMAL_PROTECT_RESET_MD

/****** To Enable Phase 2 Mechanism **********/
#define THERMAL_PROTECT_AIRPLANE_MODE

#if defined(DRV_THERMAL_PROTECT) && defined(__MTK_TARGET__)

#if defined(THERMAL_PROTECT_AIRPLANE_MODE)
#include "md_sap.h"         // mcu/interface/sap
#include "l4_msgid.h"       // mcu/interface/sap/md/
#include "rmmi_struct.h"    // mcu/interface/modem/general
#endif

// For phase2, don't start detection before AP side setting threshold
#define NO_THRESHOLD_SETTING        ((kal_int16)0xA22A) // magic number => will not monitor the sensor
#define DEFAULT_THERMAL_THLD        (NO_THRESHOLD_SETTING)  // !!!Important

/* MS to TICK convertion */
#define MSEC_PER_TIMER_TICK         (10)
#define MSEC_TO_TIMER_TICKS(ms)     ((ms)/(MSEC_PER_TIMER_TICK))    

/* 3--30C, 4-Reserved, 5--85C, 6--95C, 7--105C */
#define MAX_DRAM_REFRESH_RATE       (7)
#define DRAM_REFRESH_RATE_THLD      (7)

/* To avoid continuously reset due to temperature cannot cool down immediately */
#define INIT_DETECT_INTERVAL        (600)   /* max 65,535 ticks */

/* For debug purpose */
//#define DEBUG_PERIOD_SAMPLE
#define SAMPLE_INTERVAL_SECOND      (10)

typedef struct {
    kal_uint32 detect_timer1;
    kal_uint32 detect_timer2;
    kal_uint32 polling_interval;
    
#if defined(DEBUG_PERIOD_SAMPLE)
    kal_uint32 sample_timer;
    kal_uint32 sample_interval;
    kal_uint32 reset_limit;
#endif
    kal_int16 threshold[thermal_sensor_num];
    kal_int16 warn_temp[thermal_sensor_num];
} thermal_prot_cb;

static thermal_prot_cb g_thermal_prot_cb = {0, 0, 0};


/**********************************************************************
 *           Imported APIs implemented in other Files
 ***********************************************************************/
extern void dbg_print(char *fmt, ...);
extern kal_int32 vsnprintf( kal_char *str, kal_uint32 size, const kal_char *fmt,
                              va_list ap );


/**********************************************************************
 *          Internal APIs called in this File
 ***********************************************************************/
static kal_int32 thermal_prot_print(trace_class_enum level, const char *fmt, ...)
{
	static kal_char dbg_buff[256];
	kal_int32 ret;
	va_list args;
	
	va_start(args, fmt);
	ret = vsnprintf(dbg_buff, 256, fmt, args);
	va_end(args);

	dbg_print(dbg_buff);
	dhl_print(level, DHL_USER_FLAG_NONE, MOD_SYSTEM, dbg_buff);

	return ret;
}

#if defined(THERMAL_PROTECT_RESET_MD) || defined(THERMAL_PROTECT_AIRPLANE_MODE) || defined(DEBUG_PERIOD_SAMPLE)
static kal_bool thermal_prot_start_timer(kal_uint32 handle,kal_uint32 msecs, void (*timer_callback)(void *),void *parameter)
{
	SGPT_CTRL_START_T ctrlVariable;
	DCL_STATUS status;
	
	ctrlVariable.u2Tick = (kal_uint16)MSEC_TO_TIMER_TICKS(msecs);
	ctrlVariable.pfCallback = timer_callback;
	ctrlVariable.vPara = parameter;
	status = DclSGPT_Control(handle, SGPT_CMD_START, (DCL_CTRL_DATA_T *)&ctrlVariable);

	return (status==STATUS_OK)?KAL_TRUE : KAL_FALSE;
}

static kal_bool thermal_prot_stop_timer(kal_uint32 handle)
{
    DCL_STATUS status;

    status = DclSGPT_Control(handle, SGPT_CMD_STOP, 0);

    return (status==STATUS_OK)?KAL_TRUE : KAL_FALSE;
}

static kal_uint32 thermal_prot_create_timer()
{
    return DclSGPT_Open(DCL_GPT_CB, 0);
}
#endif


#if defined(THERMAL_PROTECT_AIRPLANE_MODE) || defined(DEBUG_PERIOD_SAMPLE)
static kal_int32 thermal_prot_get_auxadc_tmp(kal_uint16 adc_name, kal_int16 *p_temp)
{
    DCL_HANDLE adc_handle;
    ADC_CTRL_GET_PHYSICAL_CHANNEL_T getChannel;
    ADC_CTRL_GET_TEMP_T getTemp;
    DCL_STATUS sts;

    if (p_temp == NULL)
        return -1;

    adc_handle = DclHADC_Open(DCL_ADC, FLAGS_NONE);
    if (adc_handle == DCL_HANDLE_INVALID) {
        return -1;
    }

    getChannel.u2AdcName = adc_name;
    sts = DclHADC_Control(adc_handle, ADC_CMD_GET_PHYSICAL_CHANNEL, (DCL_CTRL_DATA_T *)&getChannel);
    if (sts != STATUS_OK) {
        return -1;
    }

    getTemp.u2Channel = getChannel.u1AdcPhyCh;
    sts = DclHADC_Control(adc_handle, ADC_CMD_GET_TEMP, (DCL_CTRL_DATA_T *)&getTemp);
    if (sts != STATUS_OK) {
        return -1;
    }

    DclHADC_Close(adc_handle);

    *p_temp = getTemp.i2Temp;

    if (getTemp.i2Temp > 300 || getTemp.i2Temp < -100) {
        /* it can happen when AUXADC or Themister is not configured correctly (not mounted) */
        return -1;
    }

    return 0;
}
#endif

#if defined(THERMAL_PROTECT_AIRPLANE_MODE)
/***************************************************************************
In this protect mode (Phase2),

MD will monitor thermal info every 1 second,
If overrun detected, inform AP with AT command to let AP set airplane mode

Currently, three sensors will be monitored:
1. DRAM Refresh Rate
2. 6290M NTC (AUXADC0)
3. PA NTC    (AUXADC1)

AP Side can set the threshold for each sensor.
*****************************************************************************/
static void thermal_prot_detect_timer2_callback(void *parameter);
kal_bool thermal_prot_set_threshold(thermal_sensor_type sensor_type, kal_int16 threshold)
{
    if (sensor_type >= thermal_sensor_num) {
        thermal_prot_print(TRACE_WARNING, "[Thermal Protection] invalid sensor type %d [%s]\r\n", sensor_type, __FUNCTION__);
        return KAL_FALSE;
    }

    thermal_prot_print(TRACE_INFO, "[Thermal Protection] sensor_type:%d threshold:%d [%s]\r\n", sensor_type, threshold, __FUNCTION__);

    g_thermal_prot_cb.threshold[sensor_type] = threshold;
    g_thermal_prot_cb.warn_temp[sensor_type] = threshold*90/100;

    /* stop detect timer first */
    thermal_prot_stop_timer(g_thermal_prot_cb.detect_timer2);

    /* then call timer callback directly, this will check sensors immediately and restart timer if needed */
    thermal_prot_detect_timer2_callback(NULL);

    return KAL_TRUE;
}

static void thermal_prot_phase2_action(thermal_sensor_type sensor, kal_int16 temp)
{
    atci_thermal_event_report_ind_struct *local_ptr = NULL;

    local_ptr = (atci_thermal_event_report_ind_struct *)
                construct_local_para(sizeof(atci_thermal_event_report_ind_struct),  TD_RESET);

    local_ptr->type = (kal_uint8)sensor;
    local_ptr->value = temp;

    thermal_prot_print(TRACE_WARNING, "[Thermal Protection] %s %d %d\r\n", __FUNCTION__, sensor, temp);
    msg_send6((module_type)MOD_SYSTEM, (module_type)MOD_ATCI, ATCI_SAP, 
              (msg_type)MSG_ID_ATCI_THERMAL_EVENT_REPORT_IND, 
              (local_para_struct *)local_ptr, 
              (peer_buff_struct*)NULL);
}

static kal_int32 thermal_prot_phase2_handle()
{
    kal_int16 temp;
    kal_int16 threshold;
    kal_int32 ret;
    static kal_int32 count = 0;
    kal_int32 next_interval = 0;

    count++;

    /* Monitor DRAM Refresh Rate */
    threshold = g_thermal_prot_cb.threshold[thermal_sensor_dram];
    if (threshold != NO_THRESHOLD_SETTING) {
        temp = emi_get_dram_temp();
        if (temp >= threshold) {
            thermal_prot_print(TRACE_WARNING, "[Thermal Protection] DRAM SENOR Exceeds Threshold (%d)\r\n", threshold);
            thermal_prot_phase2_action(thermal_sensor_dram, temp);
            return 0;
        }
        if (temp >= g_thermal_prot_cb.warn_temp[thermal_sensor_dram]) {
            /* print log if exceeds 90% */
            if ((count%2) == 0)
                thermal_prot_print(TRACE_INFO, "[Thermal Protection] DRAM SENOR Temp %d\r\n", temp);
        }
        next_interval = 1000;
    }

    /* Monitor MD NTC Temperature */
    threshold = g_thermal_prot_cb.threshold[thermal_sensor_md_ntc];
    if (threshold != NO_THRESHOLD_SETTING) {
        ret = thermal_prot_get_auxadc_tmp(DCL_MDTMP_ADC_CHANNEL, &temp);
        if (ret == 0 && temp >= threshold) {
            thermal_prot_print(TRACE_WARNING, "[Thermal Protection] MD_NTC SENOR Exceeds Threshold (%d)\r\n", threshold);
            thermal_prot_phase2_action(thermal_sensor_md_ntc, temp);
            return 0;
        }
        if (ret == 0 && temp >= g_thermal_prot_cb.warn_temp[thermal_sensor_md_ntc]) {
            /* print log if exceeds 90% */
            if ((count%2) == 0)
                thermal_prot_print(TRACE_INFO, "[Thermal Protection] MD_NTC SENOR Temp %d\r\n", temp);
        }
        next_interval = 1000;
    }

    /* Monitor PMIC/B7_PA NTC Temperature */
    threshold = g_thermal_prot_cb.threshold[thermal_sensor_pa_ntc];
    if (threshold != NO_THRESHOLD_SETTING) {
        ret = thermal_prot_get_auxadc_tmp(DCL_PMICTMP_ADC_CHANNEL, &temp);
        if (ret == 0 && temp >= threshold) {
            thermal_prot_print(TRACE_WARNING, "[Thermal Protection] PA_NTC SENOR Exceeds Threshold (%d)\r\n", threshold);
            thermal_prot_phase2_action(thermal_sensor_pa_ntc, temp);
            return 0;
        }
        if (ret == 0 && temp >= g_thermal_prot_cb.warn_temp[thermal_sensor_pa_ntc]) {
            /* print log if exceeds 90% */
            if ((count%2) == 0)
                thermal_prot_print(TRACE_INFO, "[Thermal Protection] PA_NTC SENOR Temp %d\r\n", temp);
        }
        next_interval = 1000;
    }

    return next_interval;
}

static void thermal_prot_detect_timer2_callback(void *parameter)
{
    kal_int32 next_interval = 0;
    
    next_interval = thermal_prot_phase2_handle();

    if (next_interval != 0) {
        /* not overrun, restart timer to do next polling */
        thermal_prot_start_timer(g_thermal_prot_cb.detect_timer2, next_interval, thermal_prot_detect_timer2_callback, NULL);
    } 
}
#endif

#ifdef THERMAL_PROTECT_RESET_MD
/***************************************************************************
In this protect mode (Phase1),

MD will monitor DRAM Refresh Rate periodically,
If overrun detected, inform AP to RESET MD
Threshold setting: 3b'111

*****************************************************************************/
static void thermal_prot_phase1_action()
{
    DCL_HANDLE wdt_handle;

    wdt_handle = DclWDT_Open(DCL_WDT, 0);
    DclWDT_Control(wdt_handle, WDT_CMD_ABN_RESET, 0);
    DclWDT_Close(wdt_handle);
}

static kal_int32 thermal_prot_phase1_handle()
{
    static kal_uint32 last_high_rate = 0xFFFFFFFF;
    static kal_int32  check_cnt = 0;
    kal_uint32 dram_ref_rate = 0;
    kal_uint32 dram_ref_thld = 0;
    kal_uint32 next_interval = 100;

    dram_ref_rate = emi_get_dram_refresh_rate();
    if (dram_ref_rate > MAX_DRAM_REFRESH_RATE) {
        thermal_prot_print(TRACE_WARNING, "[Thermal Protection] dram refresh rate is %d, exceeds max(%d)\r\n", dram_ref_rate, MAX_DRAM_REFRESH_RATE);
        return 0;
    }
    
    dram_ref_thld = DRAM_REFRESH_RATE_THLD;

    if (last_high_rate == 0xFFFFFFFF) {
        thermal_prot_print(TRACE_INFO, "[Thermal Protection] dram refresh rate is %d\r\n", dram_ref_rate);
        last_high_rate = dram_ref_rate;
    } else {
        if (dram_ref_rate > last_high_rate) {
            /* log immdiately if temperature become higher, have little influence to log amount */
            thermal_prot_print(TRACE_WARNING, "[Thermal Protection] dram refresh rate change %d ==> %d\r\n", last_high_rate, dram_ref_rate);
            last_high_rate = dram_ref_rate;
            check_cnt = 0;
        } else if (dram_ref_rate < last_high_rate) {
            /* check for 10 seconds, to reduce log amount */
            check_cnt ++;
            if (check_cnt > 100) {
                thermal_prot_print(TRACE_WARNING, "[Thermal Protection] dram refresh rate change %d ==> %d\r\n", last_high_rate, dram_ref_rate);
                last_high_rate = dram_ref_rate;
            }
        } else {
            /* don't log if no change */
            ;
        }
    }
    
    /* check if overrun */
    if (dram_ref_rate >= dram_ref_thld) 
    {
        thermal_prot_print(TRACE_ERROR, "[Thermal Protection] dram refresh rate reach threshold %d !!!!!!\r\n", dram_ref_thld);
        thermal_prot_phase1_action();
        return 0;
    }

    /* set next timer interval */
    if (dram_ref_rate < 5) {
        /* < 90C */
        next_interval = 1000;
    } else if (dram_ref_rate < 6) {
        /* < 100C */
        static kal_uint32 cnt2_for_log = 0;

        cnt2_for_log ++;
        if ((cnt2_for_log%10)==0)
            thermal_prot_print(TRACE_WARNING, "[Thermal Protection] dram refresh rate is %d \r\n", dram_ref_rate);
            
        next_interval = 500;
    } else if (dram_ref_rate < 7) {
        /* < 105C */
        static kal_uint32 cnt1_for_log = 0;

        cnt1_for_log ++;
        if ((cnt1_for_log%10)==0)
            thermal_prot_print(TRACE_WARNING, "[Thermal Protection] dram refresh rate is %d \r\n", dram_ref_rate);
            
        next_interval = 200;
    } else {
        /* never reach here */
        next_interval = 200;
    }

    return next_interval;
}

static void thermal_prot_detect_timer1_callback(void *parameter)
{
    kal_int32 next_interval = 0;
    
    next_interval = thermal_prot_phase1_handle();

    if (next_interval != 0) {
        /* not overrun, restart timer to do next polling */
        thermal_prot_start_timer(g_thermal_prot_cb.detect_timer1, next_interval, thermal_prot_detect_timer1_callback, NULL);
    } 
}
#endif


#if defined(DEBUG_PERIOD_SAMPLE)
static void thermal_prot_sample_temp_info()
{
    kal_uint32 dram_ref_rate = 0;
    kal_int16  adc0_temp = -123;
	kal_int16  adc1_temp = -123;
    kal_uint16 adc0_name = DCL_MDTMP_ADC_CHANNEL;
	kal_uint16 adc1_name = DCL_PMICTMP_ADC_CHANNEL;
    static kal_uint32 times = 0;
#if !defined(THERMAL_PROTECT_AIRPLANE_MODE)
    dram_ref_rate = emi_get_dram_refresh_rate();
#else
    dram_ref_rate = emi_get_dram_temp();
#endif
    thermal_prot_get_auxadc_tmp(adc0_name, &adc0_temp);
	thermal_prot_get_auxadc_tmp(adc1_name, &adc1_temp);

    times++;

    thermal_prot_print(TRACE_INFO, "[Thermal Protection] SAMPLE_DATA: \t%d \t%d \t%d \t%d\r\n",times, dram_ref_rate, adc0_temp, adc1_temp);
}

static void thermal_prot_sample_timer_callback(void *parameter)
{
    static kal_int32 count = 0;

    if ((count%SAMPLE_INTERVAL_SECOND) == 0) {
        thermal_prot_sample_temp_info();
    }

    count ++;

    thermal_prot_start_timer(g_thermal_prot_cb.sample_timer, g_thermal_prot_cb.sample_interval, thermal_prot_sample_timer_callback, NULL);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}
#endif

static void thermal_prot_init_threshold()
{
#if defined(THERMAL_PROTECT_AIRPLANE_MODE)
    int idx;

    for (idx = 0; idx < thermal_sensor_num; idx++) {
        // Init default threshold
        g_thermal_prot_cb.threshold[idx] = DEFAULT_THERMAL_THLD;
        g_thermal_prot_cb.warn_temp[idx] = DEFAULT_THERMAL_THLD*90/100;
    }
#endif
}

/**********************************************************************
 *          Global APIs called from other Files
 ***********************************************************************/
kal_bool thermal_prot_stop()
{
    kal_bool ret = KAL_FALSE;

#if defined(THERMAL_PROTECT_RESET_MD)
    if (g_thermal_prot_cb.detect_timer1 != 0) {
        thermal_prot_print(TRACE_INFO, "[Thermal Protection] %s \r\n", __FUNCTION__);
        ret = thermal_prot_stop_timer(g_thermal_prot_cb.detect_timer1);
    }
#endif
    
#if defined(THERMAL_PROTECT_AIRPLANE_MODE)
    if (g_thermal_prot_cb.detect_timer2 != 0) {
        thermal_prot_print(TRACE_INFO, "[Thermal Protection] %s \r\n", __FUNCTION__);
        ret = thermal_prot_stop_timer(g_thermal_prot_cb.detect_timer2);
    }
#endif

#if defined(DEBUG_PERIOD_SAMPLE)
    if (g_thermal_prot_cb.sample_timer != 0) {
        ret = thermal_prot_stop_timer(g_thermal_prot_cb.sample_timer);
    }
#endif

    return ret;
}

kal_bool thermal_prot_run()
{
    kal_bool ret = KAL_FALSE;

#if defined(THERMAL_PROTECT_RESET_MD)
    thermal_prot_print(TRACE_INFO, "[Thermal Protection] dram refresh rate is %d\r\n", emi_get_dram_refresh_rate());
    if (g_thermal_prot_cb.detect_timer1 != 0) {
        thermal_prot_print(TRACE_INFO, "[Thermal Protection] %s \r\n", __FUNCTION__);
        ret = thermal_prot_start_timer(g_thermal_prot_cb.detect_timer1, g_thermal_prot_cb.polling_interval, thermal_prot_detect_timer1_callback, NULL);
    }
#endif

#if defined(THERMAL_PROTECT_AIRPLANE_MODE)
    thermal_prot_print(TRACE_INFO, "[Thermal Protection] dram sensor temp is %d\r\n", emi_get_dram_temp());
    if (g_thermal_prot_cb.detect_timer2 != 0) {
        thermal_prot_print(TRACE_INFO, "[Thermal Protection] %s \r\n", __FUNCTION__);
        ret = thermal_prot_start_timer(g_thermal_prot_cb.detect_timer2, g_thermal_prot_cb.polling_interval, thermal_prot_detect_timer2_callback, NULL);
    }
#endif

#if defined(DEBUG_PERIOD_SAMPLE)
    if (g_thermal_prot_cb.sample_timer != 0) {
        ret = thermal_prot_start_timer(g_thermal_prot_cb.sample_timer, g_thermal_prot_cb.sample_interval, thermal_prot_sample_timer_callback, NULL);
    }
#endif

    return ret;
}

void thermal_prot_init()
{
    static kal_bool init_done = KAL_FALSE;
    
    if (init_done == KAL_TRUE)
        return;
        
    thermal_prot_print(TRACE_INFO, "[Thermal Protection] %s \r\n", __FUNCTION__);
    
    thermal_prot_init_threshold();

#if defined(THERMAL_PROTECT_RESET_MD)
    g_thermal_prot_cb.detect_timer1 = thermal_prot_create_timer();
#endif

#if defined(THERMAL_PROTECT_AIRPLANE_MODE)
    g_thermal_prot_cb.detect_timer2 = thermal_prot_create_timer();
#endif
    
    if (INIT_DETECT_INTERVAL < MSEC_PER_TIMER_TICK || INIT_DETECT_INTERVAL > 655360)
        g_thermal_prot_cb.polling_interval = MSEC_PER_TIMER_TICK*10;
    else
        g_thermal_prot_cb.polling_interval = INIT_DETECT_INTERVAL;

#if defined(DEBUG_PERIOD_SAMPLE)
    g_thermal_prot_cb.sample_timer = thermal_prot_create_timer();
    g_thermal_prot_cb.sample_interval = 1000;
    g_thermal_prot_cb.reset_limit = 60;
#endif

    init_done = KAL_TRUE;

    /* just run after init */
    thermal_prot_run();
}

#else
kal_bool thermal_prot_set_threshold(thermal_sensor_type sensor_type, kal_int16 threshold) {return KAL_TRUE;}
kal_bool thermal_prot_stop() {return KAL_TRUE;}
kal_bool thermal_prot_run() {return KAL_TRUE;}
void thermal_prot_init() {;}
#endif


