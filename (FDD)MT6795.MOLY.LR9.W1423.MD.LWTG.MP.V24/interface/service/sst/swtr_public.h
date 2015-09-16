#ifndef SWTR_PUBLIC_H
#define SWTR_PUBLIC_H

#if defined(__MALMO_ASM_SWTR__)
#include "MalmoDriver.h"
#endif

#if (defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__))
#define __MAUI_SOFTWARE_TRACER__
#endif

#define __MAUI_SWTR_V1__

#define GPT_TIMER_NUMBER_FOR_SWTR 2

#ifdef __MAUI_SOFTWARE_TRACER__

typedef struct _ST_return_struct
{
    kal_int32 start_time1;
    kal_int32 start_time2;
    kal_int32* buffer_start_addr;
    kal_int32* buffer_end_addr;
    kal_int32* buffer_current_index_addr;
    kal_int32 time_scale_for_one_sec;
    kal_int32 reserved[4];
    kal_bool buffer_wrap_around;
} ST_return_struct;

typedef struct _ST_input_struct
{
    kal_int32 trace_time_scale;
    kal_bool all_task;
    kal_bool trace_register;
    kal_bool trace_call_stack;
    kal_bool trace_data;
    kal_int32 task_filter[6];
    kal_int32 trace_stack_size;
    kal_int32* data_address[16];
    kal_int32 reserved[16];
} ST_input_struct;

#if defined(__MALMO_ASM_SWTR__)
typedef struct {
	MALMO_ASM_MONITORED_REGISTERS fields[MALLMO_ASM_MONITOR_FILTER_WIDTH];
	kal_uint32 cnt;						// the number of active fields
	kal_uint32 start_time1;		// value of L1I_GetTimeStamp() 
	kal_uint32 start_time2;		// value of drv_get_current_time
	kal_uint32 time_scale_for_one_sec;	
	kal_uint32 sampling_period;
} ST_MALMO_ASM_LoggingHeader;
#endif

extern kal_bool ST_init_and_running(ST_input_struct* input_command);
extern ST_return_struct* ST_stop(void);
#if defined(__MALMO_ASM_SWTR__)
ST_MALMO_ASM_LoggingHeader* ST_MALMO_ASM_RetrieveHeader(void);
#endif

#endif /* #ifdef __MAUI_SOFTWARE_TRACER__ */

#endif