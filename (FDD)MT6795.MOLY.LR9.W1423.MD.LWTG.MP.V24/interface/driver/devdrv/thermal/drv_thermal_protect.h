#ifndef __DRV_THERMAL_PROTECT_H__
#define __DRV_THERMAL_PROTECT_H__

#include "kal_general_types.h"

typedef enum {
    thermal_sensor_dram,    /* dram refresh rate */
    thermal_sensor_md_ntc,  /* auxadc0 */
    thermal_sensor_pa_ntc,  /* auxadc1 */
    thermal_sensor_num,
} thermal_sensor_type;

extern void thermal_prot_init();
extern kal_bool thermal_prot_run();
extern kal_bool thermal_prot_stop();
extern kal_bool thermal_prot_set_threshold(thermal_sensor_type sensor_type, kal_int16 threshold);

#endif
