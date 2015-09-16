#ifndef _MLL1_UMTS_FDD_H
#define _MLL1_UMTS_FDD_H

#include "kal_public_defs.h" /*for LOCAL_PARA_HDR*/
#include "mll1_common.h"
/*****************************************************************************
*                                    DEFINITIONS
*****************************************************************************/
#define UMTS_FDD_SESSION_IN_PERIOD     8 /* align gsm, LTE only need 6 for gp0/gp1 */

#define UMTS_FDD_MAX_DCH_GAP_PARAM_NUM 6 /*2 Pop temp modification for UL1's TGPS free buffer issue*/
#define UMTS_FDD_MAX_TGPS_NUM          6
#define UMTS_FDD_SCHEDULE_DELAY        0 /* used to postpone available gap start time */
/*****************************************************************************
*                                    ENUMERATIONS
*****************************************************************************/

/*****************************************************************************
* ENUMERATION
*   ul1_ll1_rat_status_enum
*
* DESCRIPTIONS
*   Used to identify the status in UMTS FDD RAT.
* NOTE
*   any modification should sync. with ll1_rat_status_enum
*****************************************************************************/
typedef enum
{
  UL1_LL1_RAT_FLIGHT =0,
  UL1_LL1_RAT_STANDBY,
  UL1_LL1_RAT_ACTIVE,
  UL1_LL1_RAT_NUM
} ul1_ll1_rat_status_enum;

/*****************************************************************************
* ENUMERATION
*   umts_fdd_tgps_status_enum
*
* DESCRIPTIONS
*   ACTIVE_GAP: the tgps is used in standby L1.
*   INACTIVE_GAP: the tgps is not used in standby L1.
*****************************************************************************/
typedef enum
{
   UL1_ACTIVATE_GAP=0, /* 0 */
   UL1_DEACTIVATE_GAP  /* 1 */
}umts_fdd_tgps_status_enum;

/*****************************************************************************
* ENUMERATION
*   umts_fdd_tgmp_enum
*
* DESCRIPTIONS
*   The enum type of TGPS purpose
* NOTE
*   any change should note x_tgmp_enum
*****************************************************************************/
typedef enum
{
   UL1_LL1_FDD_MEASURE,      /* Inter-frequency measurement */
   UL1_LL1_GSM_RSSI,         /* GSM RSSI measurement */
   UL1_LL1_GSM_BSIC_INIT,    /* GSM initial BSIC */
   UL1_LL1_GSM_BSIC_CNF,     /* GSM BSIC confirm */
   UL1_LL1_EUTRAN,           /* Inter-RAT LTE measurement*/  
   UL1_LL1_UMTS_TDD,         /* Inter-RAT UMTS_TDD measurement*/
   UL1_LL1_PURPOSE_UNDEFINED
} umts_fdd_tgmp_enum;

/*****************************************************************************
*                                    STRUCTURES
*****************************************************************************/

/*****************************************************************************
* STRUCT
*   umts_fdd_time_struct
*
* DESCRIPTIONS
*   UMTS FDD system timing base
*
* PARAMETERS
*   sfn      - UMTS FDD system frame number (0~4095), 1 sfn = 38400*8.
*   echip    - UMTS FDD Echip (0~307199)
*****************************************************************************/
typedef struct
{
  kal_int32        sfn;
  kal_int32        echip;
}umts_fdd_time_struct;

/*****************************************************************************
* STRUCT
*   ll1_umts_fdd_standby_gap_struct
*
* DESCRIPTIONS
*   UMTS FDD standby gap pattern structure.
*
* PARAMETERS
*   start_time - start time of the gap session
*   length     - length of the gap session (in echip)
*****************************************************************************/
typedef struct
{
   umts_fdd_time_struct start_time;
   kal_int32            length;
}ll1_umts_fdd_standby_gap_struct;

/*****************************************************************************
* STRUCT
*   ll1_ul1_expand_gap_pattern_struct
*
* DESCRIPTIONS
*   LL1 expands gap pattern for UL1
*
* PARAMETERS
*   session_num  - Indicate how many gap session 
*   session[]    - Standby gap session.
*   measure_tid  - Transition id for RANK tick./Valid when active RAT is in DRX mode./And bit 0 in tick_bitmap is "1"
*   hps_tid      - Transition id for HPS tick./Valid when active RAT is in DRX mode./And bit 1 in tick_bitmap is "1"
*   tick_bitmap  - Bit 0 : Rank search , Bit 1 : Priority search
*****************************************************************************/
typedef struct
{
   kal_uint8                       session_num;
   ll1_umts_fdd_standby_gap_struct session[UMTS_FDD_SESSION_IN_PERIOD];
   kal_uint8                       measure_tid;
   kal_uint8                       hps_tid;
   kal_uint8                       tick_bitmap;
}ll1_ul1_expand_gap_pattern_struct;

/*****************************************************************************
* STRUCT
*   ll1_umts_fdd_gap_config_struct
*
* DESCRIPTIONS
*   UMTS FDD gap configuration when UMTS FDD is active RAT.
*
* PARAMETERS
*   start_time - Valid time of gap pattern in active RAT
*   use_num    - Continuous gap number could be used in active RAT(Each FMO cycle = 10*M_REP*NTTI as a unit)
*   skip_num   - Skip number in active RAT (Each FMO cycle = 10*M_REP*NTTI as a unit)
*****************************************************************************/
typedef struct
{
   umts_fdd_time_struct start_time;
   kal_uint8            use_num;
   kal_uint8            skip_num;
}ll1_umts_fdd_gap_config_struct;

/*****************************************************************************
* STRUCT
*   umts_fdd_idle_gap_struct
*
* DESCRIPTIONS
*   UMTS FDD idle gap structure.
*
* PARAMETERS
*   start_time  - start time of the gap session
*   length      - length of the gap session (in echip)
*   is_drx_tick - KAL_TRUE : First tick in this DRX period
*                 KAL_FALSE: Not the first free interval in this DRX period
*****************************************************************************/
typedef struct
{
   umts_fdd_time_struct start_time;
   kal_int32            length;
   kal_bool             is_drx_tick;
}umts_fdd_idle_gap_struct;

/*****************************************************************************
* STRUCT
*   umts_fdd_fach_gap_struct
*
* DESCRIPTIONS
*   UMTS FDD FACH gap structure.(FMO)
*
* PARAMETERS
*   active_time_sfm  - The first SFN for starting FMO.
*   fmo_offset       - The FMO offset from the beginning of each FMO cycle in UMTS FDD frames.
*   fmo_duration     - The FMO duration for measurements within each FMO cycle in UMTS FDD frames
*   period_length    - Equal to 10*M_REP*NTTI
*****************************************************************************/
typedef struct
{
   kal_uint32 active_time_sfn;
   kal_uint32 fmo_offset;
   kal_uint32 fmo_duration;
   kal_uint32 period_length;
}umts_fdd_fach_gap_struct;

/*****************************************************************************
* STRUCT
*   umts_fdd_dch_gap_info_struct
*
* DESCRIPTIONS
*   UMTS FDD gap information structure. (TGPSi configuration)  
*
* PARAMETERS
*   refer to spec. 36.331
*****************************************************************************/
typedef struct
{
   kal_uint8                 tgpsi;
   umts_fdd_tgps_status_enum status;
   kal_int16                 tgsfn;
   umts_fdd_tgmp_enum        purpose;
   kal_uint16                original_tgprc;
   kal_uint16                remain_tgprc;
   kal_uint8                 tgsn;
   kal_uint8                 tgl1;
   kal_uint8                 tgl2;
   kal_uint16                tgd;
   kal_uint8                 tgpl1;
   kal_uint8                 tgpl2;
   kal_uint16                t_reconfirm_dch;
   kal_uint16                t_identify_dch;
}umts_fdd_dch_gap_info_struct;

/*****************************************************************************
* STRUCT
*   umts_fdd_dch_gap_param_struct
*
* DESCRIPTIONS
*   UMTS FDD DCH gap info structure. (gap_info_lenthg TGPSi in one TGPS configuration )
*
* PARAMETERS
*   gap_info_length   - The DCH gap pattern sequence number
*   reconfig_time_sfn - valid time of this configuration
*   dch_gap_info[]    - 
*****************************************************************************/
typedef struct
{
   kal_uint8 gap_info_length;
   kal_int16 reconfig_time_sfn;
   umts_fdd_dch_gap_info_struct dch_gap_info[UMTS_FDD_MAX_TGPS_NUM];
}umts_fdd_dch_gap_param_struct;

/*****************************************************************************
* STRUCT
*   umts_fdd_dch_gap_struct
*
* DESCRIPTIONS
*   UMTS FDD DCH gap structure. ( many TGPS configurations)
*
* PARAMETERS
*   gap_param_num            - Indicate that whether the patterns need to be applied
*   umts_fdd_dch_gap_param[] - DCH gap configurations
*****************************************************************************/
typedef struct
{
   kal_uint8 gap_param_num;
   umts_fdd_dch_gap_param_struct umts_fdd_dch_gap_param[UMTS_FDD_MAX_DCH_GAP_PARAM_NUM];
}umts_fdd_dch_gap_struct;

/*****************************************************************************
* STRUCT
*   ul1_ll1_sync_cnf_struct
*
* DESCRIPTIONS
*   UL1 uses this primitive to confirm LL1 that current UMTS FDD timing 
*   and micro second counter value.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   current_time      - sync. time in umts_fdd_time_struct 
*   umts_fdd_ustime   - sync. time in USC  
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   umts_fdd_time_struct current_time;
   kal_uint32           umts_fdd_ustime;
}ul1_ll1_sync_cnf_struct;

/*****************************************************************************
* STRUCT
*   ul1_ll1_rat_status_ind_struct
*
* DESCRIPTIONS
*   This message is sent from UL1 to LL1 for informing current UL1 RAT status. 
*   This message should be sent when UL1 RAT status changed.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   rat_status - RAT status in UL1 
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   ul1_ll1_rat_status_enum rat_status;
}ul1_ll1_rat_status_ind_struct;

/*****************************************************************************
* STRUCT
*   ul1_ll1_mode_status_ind_struct
*
* DESCRIPTIONS
*   This message is sent from UL1 to LL1 for informing that UL1 mode status when UL1 is active RAT. 
*   This message should be sent when UL1 mode status changed.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   fdd_mode_status  - current mode in UL1 when UMTS FDD is active RAT
*   drx_cycle_length - valid when gsm_mode_status = UL1_LL1_IDLE_MODE ||   LL1_FDD_EFACH_DRX_MODE
*   burst_length     - valid when gsm_mode_status = LL1_FDD_EFACH_DRX_MODE, and should be smaller than drx_cycle_length
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   ll1_active_rat_mode_status_enum fdd_mode_status;
   kal_uint16                      drx_cycle_length;
   kal_uint16                      burst_length;
}ul1_ll1_mode_status_ind_struct;

/*****************************************************************************
* STRUCT
*   ll1_ul1_mode_status_update_ind_struct
*
* DESCRIPTIONS
*   This message is sent to UL1 for informing that mode status of active RAT when UL1 is standby RAT. 
*   This message should be updated for UL1 in standby when any mode status changed in active RAT. 
*   Also when UL1 enters into standby RAT from FLIGHT, LL1 will update current mode state in active RAT to UL1.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   active_rat_mode_status - current mode status in active RAT
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   ll1_active_rat_mode_status_enum active_rat_mode_status;
}ll1_ul1_mode_status_update_ind_struct;

/*****************************************************************************
* STRUCT
*   ul1_ll1_active_measure_status_ind_struct
*
* DESCRIPTIONS
*   UL1 informs LL1 that how many higher priority inter-frequencies in UL1 when high priority search is turned on
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   freq_num      - The number of higher priority inter-freq. in UL1.(0~3)
*                   When HPS off, the freq_num is equal to zero.
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8     freq_num;
}ul1_ll1_active_measure_status_ind_struct;

/*****************************************************************************
* STRUCT
*   ul1_ll1_measure_req_struct
*
* DESCRIPTIONS
*   This message is sent from UL1 to inform LL1 that how many UMTS FDD frequencies are required to be 
*   measured and the measurement purposes both in UMTS FDD Active and Standby. The message is not 
*   applicable for UL1 to request gaps for inter-frequency measurement in idle mode.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   meas_purpose_bitmap - bit 0 for measurement, bit 1 for cell search
*   tid                 - tid for lastest meas_req on (should only change when off)
*   tick_bitmap         - bit 0 for ranking search, bit 1 for priority search 
*   freq_num            - high priority freqencies when HPS ON, measurement frequencies when HPS OFF
*   t_hps               - basic period of high priority search (25s,60s,70s)
*   is_period_reset_bmp - bit 0 for rank period, 1 means to reset
*                       - bit 1 for prio period, 0 means not to reset
*                       - when freq. num is same as before, ll1 will check this flag to reset period or not
*                       - bit 2 for Tmeas prohibit n_laer, 0 means not to apply n_layer
*                       - when freq. num is same as before, ll1 will check this flag to apply n_layer or not
*   current_time        - current in UL1
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8             meas_purpose_bitmap;
   kal_uint8             tid;   
   kal_uint8             tick_bitmap;
   kal_uint8             freq_num;
   kal_uint16            t_hps;
   kal_int32             is_period_reset_bmp;
   umts_fdd_time_struct  current_time; 
}ul1_ll1_measure_req_struct;

/*****************************************************************************
* STRUCT
*   ul1_ll1_standby_measure_done_ind_struct
*
* DESCRIPTIONS
*   For low power optimization, UL1 informs LL1 which measurement purpose is 
*   measured done in its period. If all measurement purposes are measured done, 
*   LL1 will not tick UL1 anymore in shortest measurement period.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   tid           - For LL1 to know this tid is mapped to which gap pattern period sent before
*   tick_bitmap   - bit 0 for ranking search, bit 1 for priority search. Only one bit will be set in one message.
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8      tid;
   kal_uint8      tick_bitmap;
}ul1_ll1_standby_measure_done_ind_struct;

/*****************************************************************************
* STRUCT
*   ll1_ul1_gap_service_req_struct
*
* DESCRIPTIONS
*   LL1 uses this primitive to enable (disable) active RAT gap service to get (release) 
*   the free radio frequency period in UMTS FDD.When LL1 disables active RAT gap service, 
*   it means that UMTS FDD could use all RF time already.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   enable        - KAL_TRUE  : request gap service
*                   KAL_FALSE : stop gap service
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_bool      enable;
}ll1_ul1_gap_service_req_struct;

/*****************************************************************************
* STRUCT
*   ul1_ll1_gap_stop_cnf_struct
*
* DESCRIPTIONS
*   UL1 uses this primitive to confirm LL1_UL1_GAP_STOP_REQ when there is no gap usage in UMTS_FDD..
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   current_time  - current time in UL1
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   umts_fdd_time_struct current_time;
}ul1_ll1_gap_stop_cnf_struct;

/*****************************************************************************
* STRUCT
*   ul1_ll1_auto_gap_req_struct
*
* DESCRIPTIONS
*   UL1 sends this message to request LL1 that UL1 wants to use the auto gap  from  (sfn, echip). 
*   UL1 could use this auto gap after getting the successful confirm
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   auto_time  - Start time of auto gap in UL1
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   umts_fdd_time_struct auto_time;
}ul1_ll1_auto_gap_req_struct;

/*****************************************************************************
* STRUCT
*   ll1_ul1_auto_gap_cnf_struct
*
* DESCRIPTIONS
*   LL1 sends this message to confirm UL1 auto gap request. 
*   After receiving this message, UL1 could use required auto gap.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   success       - KAL_TRUE : UL1 could use auto gap to search
*                   KAL_FALSE: UL1 could not use auto gap to search. 
*                              And UL1 should not request auto gap until AUTO_GAP_AVAILABLE_IND
*   valid_period  - The length of  autonomous gap allowed by active RAT 
*                   The value is valid when success = KAL_TRUE
*                   Unit : echip 
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_bool  success;
   kal_int32 valid_period;
}ll1_ul1_auto_gap_cnf_struct;

/*****************************************************************************
* STRUCT
*   ll1_ul1_auto_gap_ind_struct
*
* DESCRIPTIONS
*   LL1 sends this message to inform UL1 stopping using RF in this auto gap from   (sfn, echip).
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   auto_time  - Start time of auto gap
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   umts_fdd_time_struct auto_time;
}ll1_ul1_auto_gap_ind_struct;

/*****************************************************************************
* STRUCT
*   ul1_ll1_auto_gap_res_struct
*
* DESCRIPTIONS
*   UL1 sends this message to response LL1 that UL1 will/won't use RF from 
*   the start timing of auto gap which is informed by LL1_UL1_AUTO_GAP_IND.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   success       - KAL_TRUE : UL1 will not use RF from the starting time of LL1_UL1_AUTONOMOIS_GAP_IND
*                   KAL_FALSE: UL1 may use RF after starting time of LL1_UL1_AUTONOMOIS_GAP_IND. 
*   valid_period  - The length of  autonomous gap allowed in UL1 
*                   The value is valid when UL1 is active rat and success = KAL_TRUE
*                   Unit : echip
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_bool  success;
   kal_int32 valid_period;
}ul1_ll1_auto_gap_res_struct;

/*****************************************************************************
* STRUCT
*   ll1_ul1_gap_notify_ind_struct
*
* DESCRIPTIONS
*   LL1 sends this message to inform UL1 that the starting time and length of gap pattern when UL1 is standby RAT.
*   LL1 sends this message to inform UL1 the gap pattern configuration when UL1 is active RAT.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   standby_gap   - standby gap pattern
*   active_gap    - active gap pattern configuration
*   tid           - tid for lastest meas_req on
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   ll1_ul1_expand_gap_pattern_struct standby_gap;
   ll1_umts_fdd_gap_config_struct    active_gap;
   kal_uint8                         tid;        /* Tid for lastest meas_req on, LL1 will expand gap notify ind with this tid*/
}ll1_ul1_gap_notify_ind_struct;

/*****************************************************************************
* STRUCT
*   ul1_ll1_gap_pattern_ind_struct
*
* DESCRIPTIONS
*   UL1 sends this message to inform LL1 that the free RF period in UL1 as gap pattern. 
* PARAMETERS
*   LOCAL_PARA_HDR  
*   ul1_current_time - Ul1 current time
*   idle_gap         - No matter the length is bigger than zero or not, 
*                      UL1 should send this message and sets is_drx_tick = KAL_TRUE in one DRX period once.
*   fach_gap         - fach gap pattern
*   dch_gap          - tgps gap pattern
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   umts_fdd_time_struct     ul1_current_time;
   umts_fdd_idle_gap_struct idle_gap;
   umts_fdd_fach_gap_struct fach_gap;
   umts_fdd_dch_gap_struct  dch_gap;
}ul1_ll1_gap_pattern_ind_struct;

/*****************************************************************************
* STRUCT
*   ll1_ul1_sync_req_struct
*   ul1_ll1_gap_stop_req_struct
*   ll1_ul1_gap_stop_cnf_struct
*   ll1_ul1_gap_stop_req_struct
*   ul1_ll1_gap_suspend_req_struct
*   ll1_ul1_gap_suspend_cnf_struct
*   ll1_ul1_gap_suspend_req_struct
*   ul1_ll1_gap_suspend_cnf_struct
*   ul1_ll1_gap_resume_ind_struct
*   ll1_ul1_gap_resume_ind_struct
*   ul1_ll1_auto_gap_stop_req_struct
*   ll1_ul1_auto_gap_stop_ind_struct
*   ul1_ll1_auto_gap_stop_res_struct
*   ll1_ul1_auto_gap_stop_cnf_struct
*   ul1_ll1_auto_gap_end_ind_struct
*   ll1_ul1_auto_gap_end_ind_struct
*   ul1_ll1_auto_gap_available_ind_struct
*   ll1_ul1_auto_gap_available_ind_struct
*
* DESCRIPTIONS
*   ll1_ul1_sync_req_struct
*     LL1 will use this primitive to get UL1 current UMTS timing and micro 
*     second counter value in both UL1 in active and standby mode.
*
*   ul1_ll1_gap_stop_req_struct
*     UL1 uses this primitive to inform LL1 to stop all gap usage in standby 
*     RAT when GERAN GSM wants to change configuration or other purposes.
*
*   ll1_ul1_gap_stop_cnf_struct
*     LL1 uses this primitive to confirm UL1 that LL1 has already stopped 
*     all gap usages in standby RAT and UL1 could use all RF time.
*
*   ll1_ul1_gap_stop_req_struct
*     LL1 uses this primitive to stop gap usage in UMTS FDD when UMTS FDD is standby RAT.
*
*   ul1_ll1_gap_suspend_req_struct
*     UL1 uses this primitive to temporal suspend gap usage in standby RAT for higher priority
*     task and doesn't need to give new gap configuration in connection mode when resumed.
*
*   ll1_ul1_gap_suspend_cnf_struct
*     LL1 sends this confirm message to UL1 after all standby RAT gap usage are suspended.
*
*   ll1_ul1_gap_suspend_req_struct
*     LL1 sends this message to UL1 to request that UL1 suspends RF usage immediately.
*
*   ul1_ll1_gap_suspend_cnf_struct
*     UL1 sends this message to confirm LL1 that UL1 will not use gap from 
*     now to receiving resume indicator
*
*   ul1_ll1_gap_resume_ind_struct
*     UL1 sends this message to inform LL1 that UL1 has already finished 
*     higher priority task, and standby RAT could use gap normally.
*
*   ll1_ul1_gap_resume_ind_struct
*     LL1 sends this message to UL1 to resume UL1's gap usage. 
*     After receiving this message, UL1 could  use gap pattern normally.
*
*   ul1_ll1_auto_gap_stop_req_struct
*     UL1 sends this message to request LL1 that UL1 wants to 
*     retrieve auto gap for higher priority task.
*
*   ll1_ul1_auto_gap_stop_ind_struct
*     LL1 sends this message to inform UL1 of stopping using RF 
*     during auto gap period.
*
*   ul1_ll1_auto_gap_stop_res_struct
*     UL1 sends this message to response LL1 that UL1 stops 
*     auto gap usage.
*
*   ll1_ul1_auto_gap_stop_cnf_struct
*     LL1 sends this message to confirm that UL1 could use RF now.
*
*   ul1_ll1_auto_gap_end_ind_struct
*     UL1 sends this message to inform LL1 that auto gap usage is finished.
* 
*   ll1_ul1_auto_gap_end_ind_struct
*     LL1 sends this message to inform UL1 that auto gap usage is finished.
*
*   ul1_ll1_auto_gap_available_ind_struct
*     UL1 sends this message to inform LL1 that auto gap is available now. Standby RAT 
*     could request auto gap now. Standby RAT could request auto gap now
*
*   ll1_ul1_auto_gap_available_ind_struct
*     LL1 sends this message to inform UL1 that auto gap 
*     is available now. UL1 could request auto gap now.
*
*   ul1_ll1_auto_gap_unavailable_ind_struct
*     UL1 sends this message to inform LL1 that auto gap is unavailable now. 
*     Standby RAT could not request auto gap now.
*
*   ll1_ul1_auto_gap_unavailable_ind_struct
*     LL1 sends this message to inform UL1 that auto gap is unavailable now. 
*     UL1 could not request auto gap now.
*

* PARAMETERS
*   LOCAL_PARA_HDR  
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
}ll1_ul1_sync_req_struct,
 ul1_ll1_gap_stop_req_struct,
 ll1_ul1_gap_stop_cnf_struct,
 ll1_ul1_gap_stop_req_struct,
 ul1_ll1_gap_suspend_req_struct,
 ll1_ul1_gap_suspend_cnf_struct,
 ll1_ul1_gap_suspend_req_struct,
 ul1_ll1_gap_suspend_cnf_struct,
 ul1_ll1_gap_resume_ind_struct,
 ll1_ul1_gap_resume_ind_struct,
 ul1_ll1_auto_gap_stop_req_struct,
 ll1_ul1_auto_gap_stop_ind_struct,
 ul1_ll1_auto_gap_stop_res_struct,
 ll1_ul1_auto_gap_stop_cnf_struct,
 ul1_ll1_auto_gap_end_ind_struct,
 ll1_ul1_auto_gap_end_ind_struct,
 ul1_ll1_auto_gap_available_ind_struct,
 ll1_ul1_auto_gap_available_ind_struct,
 ul1_ll1_auto_gap_unavailable_ind_struct,
 ll1_ul1_auto_gap_unavailable_ind_struct;

/*****************************************************************************
* STRUCT
*   mll1_ul1_info_database_struct
*
* DESCRIPTIONS
*   UL1 information structure.
*
* PARAMETERS
*
*****************************************************************************/
typedef struct
{  /* measure req*/
   kal_uint8                           tick_bmp;            /* use to record tick bitmap*/
   kal_uint8                           rank_tick_tid;       /* tid for rank tick*/
   kal_uint8                           prio_tick_tid;       /* tid for prio tick*/
   kal_uint8                           meas_done_bmp;       /* measurement done ind bitmap*/
   kal_bool                            is_meas_done_useful; /* umts fdd uses meas_done or not by checking meas_purpose_bmp*/
   kal_uint8                           meas_purpose_bitmap; /* record the measure purpose bitmap*/
   umts_fdd_time_struct                current_time;        /* umts fdd current time when request gap service*/
   umts_fdd_time_struct                current_time_from_ul1; /* Record the UL1 current time carried in the gap pattern ind */
   /* Paging period in active RAT */
   kal_int32                           drx_cycle;           /* 80,160,320,640,1280,2560,5120 Unit : ms*/
   /* Burst length for eFACH DRX*/
   kal_int32                           burst_length;        /* 10,20,40,80,160 Unit : ms*/
   /* auto gap para*/
   umts_fdd_time_struct                auto_time;           /* auto gap time*/ 
   /* Mode status*/
   ll1_active_rat_mode_status_enum     mode_status;         /* mode status*/   
   /* GAP pattern*/
   ul1_ll1_gap_pattern_ind_struct      gap_pattern;         /* Gap pattern */
   /* Gap request from standby rat should do sync in connection*/
   kal_bool                            valid_timing;        /* KAL_TRUE  : with valid timing */
                                                            /* KAL_FALSE : with invalid timing */
   kal_uint8                           meas_req_tid;        /* Tid for lastest meas_req on, LL1 will expand gap notify ind with this tid*/
}mll1_ul1_info_database_struct;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__POP_FSM__*/

/*****************************************************************************
*                                GLOBAL FUNCTIONS
*****************************************************************************/

/*****************************************************************************
* FUNCTION
*   mll1_tick_ul1_gap_expansion
* DESCRIPTION
*   tick ul1 to expand gap when sync done
*
* PARAMETERS
*   none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tick_ul1_gap_expansion(void);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_auto_gap_available_ind
* DESCRIPTION
*   ll1 sends auto gap available ind to UMTS FDD now
*
* PARAMETERS
*   kal_bool available
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_auto_gap_available_ind(kal_bool available);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_auto_gap_cnf
* DESCRIPTION
*   ll1 sends auto gap cnf to UMTS_FDD now
*
* PARAMETERS
*   success - success or not
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_auto_gap_cnf(kal_bool success,kal_int32 valid_period);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_auto_gap_end_ind
* DESCRIPTION
*   ll1 sends auto gap end ind to UMTS FDD now
*
* PARAMETERS
*   none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_auto_gap_end_ind(void);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_auto_gap_ind
* DESCRIPTION
*   ll1 sends auto gap end ind to UMTS FDD now
*
* PARAMETERS
*   fdd_time - auto time
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_auto_gap_ind(umts_fdd_time_struct fdd_time);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_auto_gap_stop_cnf
* DESCRIPTION
*   ll1 sends auto gap stop cnf to UMTS_FDD now
*
* PARAMETERS
*   None
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_auto_gap_stop_cnf(void);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_auto_gap_stop_ind
* DESCRIPTION
*   ll1 sends auto gap stop ind to UMTS_FDD now
*
* PARAMETERS
*   None
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_auto_gap_stop_ind(void);

/*****************************************************************************
* FUNCTION
*  mll1_ul1_auto_time_minus
* DESCRIPTION
*  Add more rf margin for any standby rat which will enter sleep during autonomous serch procedure
*  Assume margin is smaller than one sfn
* PARAMETERS
*   umts_fdd_time_struct*
*   kal_int32              - more RF margin (recovery from sleep).
* RETURNS
*  void
*****************************************************************************/
void mll1_ul1_auto_time_minus(umts_fdd_time_struct* time, kal_int32 echip);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_expand_active_gap_pattern_ind
* DESCRIPTION
*   ll1 sends active gap pattern ind to UMTS_FDD now
*
* PARAMETERS
*   start_time - Valid time of gap pattern in active RAT
*   use_num    - Continuous gap number could be used in active RAT(Each FMO cycle = 10*M_REP*NTTI as a unit)
*   skip_num   - Skip number in active RAT (Each FMO cycle = 10*M_REP*NTTI as a unit)
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_expand_active_gap_pattern_ind(umts_fdd_time_struct* start_time,kal_uint8 use_num,kal_uint8 skip_num);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_expand_gap_pattern_ind
* DESCRIPTION
*   ll1 sends auto gap available ind to UMTS FDD now
*
* PARAMETERS
*   standby_gap - gap pattern for umts fdd
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_expand_gap_pattern_ind(ll1_ul1_expand_gap_pattern_struct* standby_gap);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_gap_resume_ind
* DESCRIPTION
*   LL1 sends this message to UL1 to resume UL1's gap usage. 
*   After receiving this message, UL1 could  use gap pattern normally.
*
* PARAMETERS
*   none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_gap_resume_ind(void);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_gap_service_req
* DESCRIPTION
*   ll1 sends gap service req to UMTS_FDD now
*
* PARAMETERS
*   enable   - KAL_TRUE  : turn on gap service 
*            - KAL_FALSE : turn off gap service
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_gap_service_req(kal_bool enable);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_gap_stop_cnf
* DESCRIPTION
*   LL1 uses this primitive to confirm UL1 that LL1 has already stopped 
*   all gap usages in standby RAT and UL1 could use all RF time.
*
* PARAMETERS
*   NONE
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_gap_stop_cnf(void);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_gap_stop_req
* DESCRIPTION
*   LL1 uses this primitive to stop gap usage in UMTS FDD when UMTS FDD is standby RAT.
*
* PARAMETERS
*   NONE
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_gap_stop_req(void);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_gap_suspend_cnf
* DESCRIPTION
*   LL1 sends this confirm message to UL1 after gap usage in standby RAT is suspended.
*   UL1 could use RF only after getting this message.
*
* PARAMETERS
*   NONE
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_gap_suspend_cnf(void);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_gap_suspend_req
* DESCRIPTION
*   LL1 uses this primitive to suspend gap usage in UMTS FDD when UMTS FDD is standby RAT.
*
* PARAMETERS
*   NONE
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_gap_suspend_req(void);

/*****************************************************************************
* FUNCTION
*  mll1_ul1_get_auto_time
* DESCRIPTION
*   return auto time from UL1
*
* PARAMETERS
*   None
* RETURNS
*  umts_fdd_time_struct auto_time
*****************************************************************************/
umts_fdd_time_struct mll1_ul1_get_auto_time(void);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_get_current_time
* DESCRIPTION
*   ll1 gets current time + ahead margin to expand gap
*
* PARAMETERS
*   umts_fdd_time - start time of expansion period
*   kal_bool is_ahead_time
*         TRUE : advance eutran_time with the predefined ahead_time
*         FALSE: don't advance eutran_time with the predefined ahead_time
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_get_current_time(umts_fdd_time_struct* fdd_time, kal_bool is_ahead_time);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_get_efach_drx_tick_count
* DESCRIPTION
*   ll1 gets rank tick base when umts fdd in efach drx mode
*
* PARAMETERS
*   none
* RETURNS
*   kal_uint32 count
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_uint32 mll1_ul1_get_efach_drx_tick_count(void);

#ifdef __LTE_RAT__
/*****************************************************************************
* FUNCTION
*  mll1_ul1_get_el1_rf_margin
* DESCRIPTION
*  UL1 gets EL1 RF margin in current state
*
* PARAMETERS
*  head      - header_margin
*  tail      - tail_margin
* RETURNS
*  none
*****************************************************************************/
void mll1_ul1_get_el1_rf_margin(kal_int32* head,kal_int32* tail);
#endif /*__LTE_RAT__*/

#ifdef __GSM_RAT__
/*****************************************************************************
* FUNCTION
*  mll1_ul1_get_gl1_rf_margin
* DESCRIPTION
*  UL1 gets GL1 RF margin in current state
*
* PARAMETERS
*  head      - header_margin
*  tail      - tail_margin
* RETURNS
*  none
*****************************************************************************/
void mll1_ul1_get_gl1_rf_margin(kal_int32* head,kal_int32* tail);
#endif /*__GSM_RAT__*/

/*****************************************************************************
* FUNCTION
*  mll1_ul1_get_mode_status
* DESCRIPTION
*   return mode status from UL1
*
* PARAMETERS
*   None
* RETURNS
*  ll1_active_rat_mode_status_enum mode_status
*****************************************************************************/
ll1_active_rat_mode_status_enum mll1_ul1_get_mode_status(void);

/*****************************************************************************
* FUNCTION
*  mll1_ul1_get_t_abort
* DESCRIPTION
*   Tidentify,gsm / Treconfirm,gsm uint: ms
*
* PARAMETERS
*   tti    - in ms
*   t_meas - in ms
*   
* RETURNS
*  kal_uint32 t_abort;
*****************************************************************************/
kal_uint32 mll1_ul1_get_t_abort(kal_uint32 tti, kal_uint32 t_meas, kal_bool is_identify);


/*****************************************************************************
* FUNCTION
*  mll1_ul1_get_t_abort_for_efach_drx
* DESCRIPTION
*   Tidentify,gsm / Treconfirm,gsm uint: ms
*
* PARAMETERS
*  kal_bool is_identify
*   
* RETURNS
*  kal_uint32 t_abort;
*****************************************************************************/
kal_uint32 mll1_ul1_get_t_abort_for_efach_drx(kal_bool is_identify);

/*****************************************************************************
* FUNCTION
*  mll1_ul1_get_tick_count
* DESCRIPTION
*   UL1 tick number
*
* PARAMETERS
*   is_prio_search - KAL_FALSE : ll1_main wants to get meas. tick
*                    KAL_TRUE  : ll1_main wants to get prio. tick
*   t_hps          - 60 (uint : second)
*   
* RETURNS
*  kal_uint32 count;
*****************************************************************************/
kal_uint32 mll1_ul1_get_tick_count(kal_bool is_prio_search, kal_uint16 t_hps);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_get_timing_status
* DESCRIPTION
*
* PARAMETERS
* RETURNS
*   kal_bool  - valid_timing KAL_TRUE  : with valid timing 
*                            KAL_FALSE : with invalid timing 
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool mll1_ul1_get_timing_status(void);

/*****************************************************************************
* FUNCTION
*  mll1_ul1_get_ul1_rf_margin
* DESCRIPTION
*  UL1 gets RF margin in current state
*
* PARAMETERS
*  head      - header_margin
*  tail         - tail_margin
* RETURNS
*  none
*****************************************************************************/
void mll1_ul1_get_ul1_rf_margin(kal_int32* head,kal_int32* tail);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_is_before_dest_time
* DESCRIPTION
*   check if gap start time is before dest time,
*
* PARAMETERS
*   src      - gap start time sfn
*   dest     - expand start time sfn
* RETURNS
*   kal_bool - KAL_TRUE  : means that src is before dest time
*                        : the src_time is before the dest_time. Return false if they are equal.
*              KAL_FALSE : means that dest is before src time
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool mll1_ul1_is_before_dest_time(kal_int32 src,kal_int32 dest);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_offset_to_fmo_act_time
* DESCRIPTION
*   calculate the timing offset between FMO activation time and expand start time.
*
* PARAMETERS
*   src      - gap start time sfn
*   dest     - expand start time sfn
* RETURNS
*   kal_int32 -  (-1) : FMO activation time fall in the duration of 480ms expand period.
*                     other positive value:  the offset between MO activation time and expand start time.
*
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_int32 mll1_ul1_offset_to_fmo_act_time(kal_int32 src, umts_fdd_time_struct* dest);

/*****************************************************************************
* FUNCTION
*  mll1_ul1_is_lower_pwr_on
* DESCRIPTION
*   Check if ul1 is low pwr on
*
* PARAMETERS
*   
* RETURNS
*  kal_bool - KAL_FALSE : measurement is not finished and need gap in this period 
*             KAL_TRUE  : measurement is finished and doesnt need gap in this period
*****************************************************************************/
kal_bool mll1_ul1_is_lower_pwr_on(void);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_mode_status_update_ind
* DESCRIPTION
*   This message is sent to UL1 for informing that mode status of active RAT when UL1 is standby RAT. 
*   This message should be updated for UL1 in standby when any mode status changed in active RAT.
*
* PARAMETERS
*   status - mode status in active RAT 
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_mode_status_update_ind(ll1_active_rat_mode_status_enum status);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_set_timing_status
* DESCRIPTION
*
* PARAMETERS
*   flag     - set valid_timing = flag
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_set_timing_status(kal_bool flag);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_sync_time_req
* DESCRIPTION
*   When timing synchronization procedure is triggered, mll1 will decide which rat should do 
*   timing synchronization based on the result of g_ll1_flight_rat|| g_ll1_standby_rat || g_ll1_active_rat.
*
* PARAMETERS
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_sync_time_req(void);

/*****************************************************************************
* FUNCTION
*  mll1_ul1_time_add
* DESCRIPTION
*  This function is used to add echips to time
*
* PARAMETERS
*   time       - basic time
*   echips     - echips
* RETURNS
*  none
*****************************************************************************/
void mll1_ul1_time_add( umts_fdd_time_struct* time, kal_int32 echips);


/*****************************************************************************
* FUNCTION
*   mll1_ul1_update_current_time
* DESCRIPTION
*   ll1 updates current time after timing sync. done
*
* PARAMETERS
*   umts_fdd_time - current time
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_ul1_update_current_time(umts_fdd_time_struct* fdd_time);

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   mll1_umts_fdd_handler()
*
* DESCRIPTION
*   Function to handle the primitive from UL1.
*
* PARAMETERS
*   current_ilm - primitive from UL1.
*
* RETURN
*   None
*****************************************************************************/
void mll1_umts_fdd_handler(void *ptr_ilm);

/*****************************************************************************
* FUNCTION
*  mll1_ul1_info_init
* DESCRIPTION
*  Initialize ul1 internal global variable
*
* PARAMETERS
*  none
* RETURNS
*  none
*****************************************************************************/
void mll1_fdd_info_init(void);

/*****************************************************************************
* FUNCTION
*   mll1_ul1_gap_pattern_timing_checking
* DESCRIPTION
*   check if the pending gap is out of date or not
*
* PARAMETERS
*   umts_fdd_time   - ul1 timing correspond to some standby rat's timing indicated in measure request
* RETURNS
*   TRUE   - the pending gap has not been out of date
*   FALSE   - the pending gap has been out of date
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool mll1_ul1_gap_pattern_timing_checking(umts_fdd_time_struct umts_fdd_time);

#endif /*_MLL1_UMTS_FDD_H*/

