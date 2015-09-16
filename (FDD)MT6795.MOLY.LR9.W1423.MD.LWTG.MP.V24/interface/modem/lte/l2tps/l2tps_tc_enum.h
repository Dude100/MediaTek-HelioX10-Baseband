#ifndef L2TPS_TC_ENUM_H
#define L2TPS_TC_ENUM_H

#define L2TPS_TC_TABLE_START()   enum{
#define L2TPS_TC_REG1(_t)             _t,
#define L2TPS_TC_REG2(_t,_func)       _t,
#define L2TPS_TC_TABLE_END()     L2TPS_TC_NUM};

#include "l2tps_tc_list.cfg"

#undef L2TPS_TC_TABLE_START
#undef L2TPS_TC_REG1 
#undef L2TPS_TC_REG2
#undef L2TPS_TC_TABLE_END

#endif