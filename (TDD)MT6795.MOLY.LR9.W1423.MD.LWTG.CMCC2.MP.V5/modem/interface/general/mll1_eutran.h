#ifndef _MLL1_EUTRAN_H
#define _MLL1_EUTRAN_H

#include "kal_public_defs.h" /*for LOCAL_PARA_HDR*/
#include "mll1_common.h"
/*****************************************************************************
*                                    DEFINITIONS
*****************************************************************************/
#define EUTRAN_SESSION_IN_PERIOD     48 /*align TDS DMO based on 10ms, 480ms/10ms = 48*/

#define EUTRAN_SCHEDULE_DELAY        0 /* used to postpone available gap start time */

/*****************************************************************************
*                                    ENUMERATIONS
*****************************************************************************/

/*****************************************************************************
* ENUMERATION
*   el1_ll1_rat_status_enum
*
* DESCRIPTIONS
*   Used to identify the status in EUTRAN RAT.
* NOTE
*   any modification should sync. with ll1_rat_status_enum
*****************************************************************************/
typedef enum
{
  EL1_LL1_RAT_FLIGHT =0,
  EL1_LL1_RAT_STANDBY,
  EL1_LL1_RAT_ACTIVE,
  EL1_LL1_RAT_NUM
} el1_ll1_rat_status_enum;

/*****************************************************************************
*                                    STRUCTURES
*****************************************************************************/

/*****************************************************************************
* STRUCT
*   eutran_time_struct
*
* DESCRIPTIONS
*   EUTRAN system timing base
*
* PARAMETERS
*   sfn         - EUTRAN system frame number (0~0XFFFFFFF). -1 = IMMEDIATELY
*   sub_frame   - EUTRAN sub-frame number (0~9)
*   sample      - EUTRAN half samples (0~61439)
*****************************************************************************/
typedef struct
{
  kal_uint32 sfn;
  kal_uint8  sub_frame;
  kal_uint16 sample;
}eutran_time_struct;

/*****************************************************************************
* STRUCT
*   ll1_eutran_standby_gap_struct
*
* DESCRIPTIONS
*   EUTRAN standby gap pattern structure.
*
* PARAMETERS
*   start_time - start time of the gap session
*   length     - length of the gap session (in sample)
*****************************************************************************/
typedef struct
{
   eutran_time_struct start_time;
   kal_int64          length;
}ll1_eutran_standby_gap_struct;

/*****************************************************************************
* STRUCT
*   ll1_el1_expand_gap_pattern_struct
*
* DESCRIPTIONS
*   LL1 expands gap pattern for EL1
*
* PARAMETERS
*   session_num  - Indicate how many gap session 
*   session[]    - Standby gap session.
*   measure_tid  - Transition id for RANK tick./Valid when active RAT is in DRX mode./And bit 0 in tick_bitmap is "1"
*   hps_tid      - Transition id for HPS tick./Valid when active RAT is in DRX mode./And bit 1 in tick_bitmap is "1"
*   tick_bitmap  - Bit 0 : Rank search , Bit 1 : Priority search
*   gap_seq      - Valid only in SDCCH mode. 2* (9 frames / 102 frames) for one frequency. 1: the first gap pattern ; 2: the last gap pattern 
*****************************************************************************/
typedef struct
{
   kal_uint8                     session_num;
   ll1_eutran_standby_gap_struct session[EUTRAN_SESSION_IN_PERIOD];
   kal_uint8                     measure_tid;
   kal_uint8                     hps_tid;
   kal_uint8                     tick_bitmap;
   kal_uint8                     gap_seq;
}ll1_el1_expand_gap_pattern_struct;

/*****************************************************************************
* STRUCT
*   ll1_eutran_gap_config_struct
*
* DESCRIPTIONS
*   EUTRAN gap configuration when EUTRAN is active RAT.
*
* PARAMETERS
*   start_time - Valid time of gap pattern in active RAT
*   use_num    - Continuous gap number could be used in active RAT(Basic unit = 480ms)
*   skip_num   - Skip number in active RAT. (Basic unit = 480ms)
*****************************************************************************/
typedef struct
{
   eutran_time_struct start_time;
   kal_uint8          use_num;
   kal_uint8          skip_num;
}ll1_eutran_gap_config_struct;

/*****************************************************************************
* STRUCT
*   eutran_drx_gap_struct
*
* DESCRIPTIONS
*   EUTRAN drx gap structure.
*
* PARAMETERS
*   start_time  - start time of the gap session
*   length      - length of the gap session (in sub_frame)
*   is_drx_tick   - KAL_TRUE : First tick in this DRX period
*                   KAL_FALSE: Not the first free interval in this DRX period
*****************************************************************************/
typedef struct
{
   eutran_time_struct start_time;
   kal_int32          length;
   kal_bool           is_drx_tick;
}eutran_drx_gap_struct;

/*****************************************************************************
* STRUCT
*   eutran_connect_gap_struct
*
* DESCRIPTIONS
*   EUTRAN gap structure in connection mode without DRX .
*
* PARAMETERS
*   start_time - start time of the gap session
*   period     - ID 0 = 40 ms ; ID 1 = 80 ms; 
*   length     - length of the gap session = 6 (ms)
*****************************************************************************/
typedef struct
{
   eutran_time_struct start_time;
   kal_uint8          period;
   kal_uint8          length;
}eutran_connect_gap_struct;

/*****************************************************************************
* STRUCT
*   el1_ll1_sync_cnf_struct
*
* DESCRIPTIONS
*   EL1 uses this primitive to confirm LL1 that current EUTRAN timing 
*   and micro second counter value.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   current_time  - sync. time in eutran_time_struct 
*   eutran_ustime - sync. time in USC  
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   eutran_time_struct current_time;
   kal_uint32         eutran_ustime;
}el1_ll1_sync_cnf_struct;

/*****************************************************************************
* STRUCT
*   el1_ll1_rat_status_ind_struct
*
* DESCRIPTIONS
*   This message is sent from EL1 to LL1 for informing current GL1 RAT status. 
*   This message should be sent when EL1 RAT status changed.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   rat_status - RAT status in EL1 
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   el1_ll1_rat_status_enum rat_status;
}el1_ll1_rat_status_ind_struct;

/*****************************************************************************
* STRUCT
*   el1_ll1_mode_status_ind_struct
*
* DESCRIPTIONS
*   This message is sent from EL1 to LL1 for informing that GL1 mode status when GL1 is active RAT. 
*   This message should be sent when EL1 mode status changed.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   eutran_mode_status - current mode in EL1 when EUTRAN is active RAT
*   is_cell_changed    - KAL_TRUE : Cell changed
*                        KAL_FALSE : When only status or drx_cycle_length changed.
*   drx_cycle_length   - valid when eutran_mode_status = EL1_LL1_IDLE_MODE
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   ll1_active_rat_mode_status_enum eutran_mode_status;
   kal_bool                        is_cell_changed;
   kal_uint16                      drx_cycle_length;
}el1_ll1_mode_status_ind_struct;

/*****************************************************************************
* STRUCT
*   ll1_el1_mode_status_update_ind_struct
*
* DESCRIPTIONS
*   This message is sent to EL1 for informing that mode status of active RAT when EL1 is standby RAT. 
*   This message should be updated for EL1 in standby when any mode status changed in active RAT. 
*   Also when EL1 enters into standby RAT from FLIGHT, LL1 will update current mode state in active RAT to EL1.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   active_rat_mode_status - current mode status in active RAT
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   ll1_active_rat_mode_status_enum active_rat_mode_status;
}ll1_el1_mode_status_update_ind_struct;

/*****************************************************************************
* STRUCT
*   el1_ll1_active_measure_status_ind_struct
*
* DESCRIPTIONS
*   EL1 informs LL1 that how many higher priority inter-frequencies in EL1 when high priority search is turned on
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   freq_num      - The number of higher priority inter-freq. in EL1.(0~3)
*                   When HPS off, the freq_num is equal to zero.
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8     freq_num;
}el1_ll1_active_measure_status_ind_struct;

/*****************************************************************************
* STRUCT
*   el1_ll1_measure_req_struct
*
* DESCRIPTIONS
*   This message is sent from EL1 to inform LL1 that how many EUTRAN frequencies are required to be 
*   measured and the measurement purposes both in EUTRAN Active and Standby. The message is not 
*   applicable for EL1 to request gaps for inter-frequency measurement in idle mode.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   meas_purpose_bitmap - bit 0 for measurement, bit 1 for cell search, bit 2 for BCCH
*   tid                 - tid for lastest meas_req on (should only change when off)
*   tick_bitmap         - bit 0 for ranking search, bit 1 for priority search 
*   freq_num            - high priority freqencies when HPS ON, measurement frequencies when HPS OFF
*   t_hps               - basic period of high priority search (25s,60s,70s)
*   is_period_reset_bmp - bit 0 for rank period, 1 means to reset
*                       - bit 1 for prio period, 0 means not to reset
*                       - when freq. num is same as before, ll1 will check this flag to reset period or not
*                       - KAL_TRUE : reset hps period, KAL_FALSE : doesnt reset hps period.
*   current_time        - current in EL1
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8           meas_purpose_bitmap;
   kal_uint8           tid;
   kal_uint8           tick_bitmap;
   kal_uint8           freq_num;
   kal_uint16          t_hps;
   kal_int32           is_period_reset_bmp;
   eutran_time_struct  current_time; 
}el1_ll1_measure_req_struct;

/*****************************************************************************
* STRUCT
*   el1_ll1_standby_measure_done_ind_struct
*
* DESCRIPTIONS
*   For low power optimization, EL1 informs LL1 which measurement purpose is 
*   measured done in its period. If all measurement purposes are measured done, 
*   LL1 will not tick EL1 anymore in shortest measurement period.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   tid           - For LL1 to know this tid is mapped to which gap pattern period sent before
*   tick_bitmap   - bit 0 for ranking search, bit 1 for priority search. Only one bit will be set in one message
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8      tid;
   kal_uint8      tick_bitmap;
}el1_ll1_standby_measure_done_ind_struct;

/*****************************************************************************
* STRUCT
*   ll1_el1_gap_service_req_struct
*
* DESCRIPTIONS
*   LL1 uses this primitive to enable (disable) active RAT gap service to get (release) 
*   the free radio frequency period in EUTRAN.When LL1 disables active RAT gap service, 
*   it means that EUTRAN could use all RF time already.
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
}ll1_el1_gap_service_req_struct;


/*****************************************************************************
* STRUCT
*   el1_ll1_gap_stop_cnf_struct
*
* DESCRIPTIONS
*   EL1 uses this primitive to confirm LL1_EL1_GAP_STOP_REQ when there is no gap usage in EUTRAN..
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   current_time  - current time in EL1
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   eutran_time_struct current_time;
}el1_ll1_gap_stop_cnf_struct;


/*****************************************************************************
* STRUCT
*   el1_ll1_auto_gap_req_struct
*
* DESCRIPTIONS
*   EL1 sends this message to request LL1 that EL1 wants to use the auto gap  from  (sfn, sub_frame, half_sample). 
*   EL1 could use this auto gap after getting the successful confirm
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   auto_time  - Start time of auto gap in EL1
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   eutran_time_struct auto_time;
}el1_ll1_auto_gap_req_struct;

/*****************************************************************************
* STRUCT
*   ll1_el1_auto_gap_cnf_struct
*
* DESCRIPTIONS
*   LL1 sends this message to confirm EL1 auto gap request. 
*   After receiving this message, EL1 could use required auto gap.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   success       - KAL_TRUE : EL1 could use auto gap to search
*                   KAL_FALSE: EL1 could not use auto gap to search. 
*                              And GL1 should not request auto gap until AUTO_GAP_AVAILABLE_IND
*   valid_period  - The length of  autonomous gap allowed by active RAT 
*                   The value is valid when success = KAL_TRUE
*                   Unit : sample
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_bool  success;
   kal_int64 valid_period;
}ll1_el1_auto_gap_cnf_struct;

/*****************************************************************************
* STRUCT
*   ll1_el1_auto_gap_ind_struct
*
* DESCRIPTIONS
*   LL1 sends this message to inform EL1 stopping using RF in this auto gap from (sfn, sub_frame, half_sample).
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   auto_time  - Start time of auto gap
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   eutran_time_struct auto_time;
}ll1_el1_auto_gap_ind_struct;

/*****************************************************************************
* STRUCT
*   el1_ll1_auto_gap_res_struct
*
* DESCRIPTIONS
*   EL1 sends this message to response LL1 that EL1 will/won't use RF from 
*   the start timing of auto gap which is informed by LL1_EL1_auto_GAP_IND.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   success       - KAL_TRUE : EL1 will not use RF from the starting time of LL1_EL1_AUTO_GAP_IND
*                   KAL_FALSE: EL1 may use RF after starting time of LL1_EL1_AUTO_GAP_IND. 
*   valid_period  - The length of  autonomous gap allowed in EL1 
*                   The value is valid when EL1 is active rat and success = KAL_TRUE
*                   Unit : sample 
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_bool  success;
   kal_int64 valid_period;
}el1_ll1_auto_gap_res_struct;

/*****************************************************************************
* STRUCT
*   ll1_el1_gap_notify_ind_struct
*
* DESCRIPTIONS
*   LL1 sends this message to inform EL1 that the starting time and length of gap pattern.
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
   ll1_el1_expand_gap_pattern_struct standby_gap;
   ll1_eutran_gap_config_struct      active_gap;
   kal_uint8                         tid;        /* Tid for lastest meas_req on, LL1 will expand gap notify ind with this tid*/
}ll1_el1_gap_notify_ind_struct;

/*****************************************************************************
* STRUCT
*   el1_ll1_gap_pattern_ind_struct
*
* DESCRIPTIONS
*   EL1 sends this message to inform LL1 that the free RF period in EL1 as gap pattern. 
* PARAMETERS
*   LOCAL_PARA_HDR  
*   el1_current_time  - EL1 current time
*   drx_gap           - No matter the length is bigger than zero or not, EL1 should send  
*                       this message and sets is_drx_tick = KAL_TRUE in one DRX period once.
*   connect_gap       - GP0 or GP1
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   eutran_time_struct            el1_current_time;
   eutran_drx_gap_struct         drx_gap;
   eutran_connect_gap_struct     connect_gap;
}el1_ll1_gap_pattern_ind_struct;

/*****************************************************************************
* STRUCT
*   ll1_el1_sync_req_struct
*   el1_ll1_gap_stop_req_struct
*   ll1_el1_gap_stop_cnf_struct
*   ll1_el1_gap_stop_req_struct
*   el1_ll1_gap_stop_cnf_struct
*   el1_ll1_gap_suspend_req_struct
*   ll1_el1_gap_suspend_cnf_struct
*   ll1_el1_gap_suspend_req_struct
*   el1_ll1_gap_suspend_cnf_struct
*   el1_ll1_gap_resume_ind_struct
*   ll1_el1_gap_resume_ind_struct
*   el1_ll1_auto_gap_stop_req_struct
*   ll1_el1_auto_gap_stop_ind_struct
*   el1_ll1_auto_gap_stop_res_struct
*   ll1_el1_auto_gap_stop_cnf_struct
*   el1_ll1_auto_gap_end_ind_struct
*   ll1_el1_auto_gap_end_ind_struct
*   el1_ll1_auto_gap_available_ind_struct
*   ll1_el1_auto_gap_available_ind_struct
*
* DESCRIPTIONS
*   ll1_el1_sync_req_struct
*     LL1 will use this primitive to get EL1 current UMTS timing and micro 
*     second counter value in both EL1 in active and standby mode.
*
*   el1_ll1_gap_stop_req_struct
*     EL1 uses this primitive to inform LL1 to stop all gap usage in standby 
*     RAT when GERAN GSM wants to change configuration or other purposes.
*
*   ll1_el1_gap_stop_cnf_struct
*     LL1 uses this primitive to confirm EL1 that LL1 has already stopped 
*     all gap usages in standby RAT and EL1 could use all RF time.
*
*   ll1_el1_gap_stop_req_struct
*     LL1 uses this primitive to stop gap usage in EUTRAN when EUTRAN is standby RAT.
*  
*   el1_ll1_gap_stop_cnf_struct
*     EL1 uses this primitive to confirm LL1_EL1_GAP_STOP_REQ when there is no gap usage in EUTRAN.
*
*   el1_ll1_gap_suspend_req_struct
*     EL1 uses this primitive to temporal suspend gap usage in standby RAT for higher priority
*     task and doesn't need to give new gap configuration in connection mode when resumed.
*
*   ll1_el1_gap_suspend_cnf_struct
*     LL1 sends this confirm message to EL1 after all standby RAT gap usage are suspended.
*
*   ll1_el1_gap_suspend_req_struct
*     LL1 sends this message to EL1 to request that EL1 suspends RF usage immediately.
*
*   el1_ll1_gap_suspend_cnf_struct
*     EL1 sends this message to confirm LL1 that EL1 will not use gap from 
*     now to receiving resume indicator
*
*   el1_ll1_gap_resume_ind_struct
*     EL1 sends this message to inform LL1 that EL1 has already finished 
*     higher priority task, and standby RAT could use gap normally.
*
*   ll1_el1_gap_resume_ind_struct
*     LL1 sends this message to EL1 to resume EL1's gap usage. 
*     After receiving this message, EL1 could  use gap pattern normally.
*
*   el1_ll1_auto_gap_stop_req_struct
*     EL1 sends this message to request LL1 that EL1 wants to 
*     retrieve auto gap for higher priority task.
*
*   ll1_el1_auto_gap_stop_ind_struct
*     LL1 sends this message to inform EL1 of stopping using RF 
*     during auto gap period.
*
*   el1_ll1_auto_gap_stop_res_struct
*     EL1 sends this message to response LL1 that EL1 stops 
*     auto gap usage.
*
*   ll1_el1_auto_gap_stop_cnf_struct
*     LL1 sends this message to confirm that EL1 could use RF now.
*
*   el1_ll1_auto_gap_end_ind_struct
*     EL1 sends this message to inform LL1 that auto gap usage is finished.
* 
*   ll1_el1_auto_gap_end_ind_struct
*     LL1 sends this message to inform EL1 that auto gap usage is finished.
*
*   el1_ll1_auto_gap_available_ind_struct
*     EL1 sends this message to inform LL1 that auto gap is available now. Standby RAT 
*     could request auto gap now. Standby RAT could request auto gap now
*
*   ll1_el1_auto_gap_available_ind_struct
*     LL1 sends this message to inform EL1 that auto gap 
*     is available now. EL1 could request auto gap now.
*
*   el1_ll1_auto_gap_unavailable_ind_struct
*     EL1 sends this message to inform LL1 that auto gap is unavailable now. 
*     Standby RAT could not request auto gap now.
*
*   ll1_el1_auto_gap_unavailable_ind_struct
*     LL1 sends this message to inform EL1 that auto gap is unavailable now. 
*     EL1 could not request auto gap now.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
}ll1_el1_sync_req_struct,
 el1_ll1_gap_stop_req_struct,
 ll1_el1_gap_stop_cnf_struct,
 ll1_el1_gap_stop_req_struct,
 el1_ll1_gap_suspend_req_struct,
 ll1_el1_gap_suspend_cnf_struct,
 ll1_el1_gap_suspend_req_struct,
 el1_ll1_gap_suspend_cnf_struct,
 el1_ll1_gap_resume_ind_struct,
 ll1_el1_gap_resume_ind_struct,
 el1_ll1_auto_gap_stop_req_struct,
 ll1_el1_auto_gap_stop_ind_struct,
 el1_ll1_auto_gap_stop_res_struct,
 ll1_el1_auto_gap_stop_cnf_struct,
 el1_ll1_auto_gap_end_ind_struct,
 ll1_el1_auto_gap_end_ind_struct,
 el1_ll1_auto_gap_available_ind_struct,
 ll1_el1_auto_gap_available_ind_struct,
 el1_ll1_auto_gap_unavailable_ind_struct,
 ll1_el1_auto_gap_unavailable_ind_struct;

/*****************************************************************************
* STRUCT
*   mll1_el1_info_database_struct
*
* DESCRIPTIONS
*   EL1 information structure.
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
   kal_bool                            is_meas_done_useful; /* eutran uses meas_done or not by checking meas_purpose_bmp*/
   kal_uint8                           meas_purpose_bitmap; /* record the measure purpose bitmap*/
   eutran_time_struct                  current_time;        /* eutran current time when request gap service*/
   /* Paging period in active RAT */
   kal_int32                           drx_cycle;           /* 80,160,350,640,1280,2560,5120 Unit : ms*/
   /* Store gap information*/
   el1_ll1_gap_pattern_ind_struct      gap_pattern;         /* store gap pattern ilm*/   
   /* auto gap para*/
   eutran_time_struct                  auto_time;           /* auto gap time*/ 
   /* Mode status*/
   ll1_active_rat_mode_status_enum     mode_status;         /* mode status*/   
   /* Gap request from standby rat should do sync in connection*/
   kal_bool                            valid_timing;        /* KAL_TRUE  : sync not finish after request*/
                                                            /* KAL_FALSE : sync done*/
   kal_uint8                           meas_req_tid;        /* Tid for lastest meas_req on, LL1 will expand gap notify ind with this tid*/                                                            
}mll1_el1_info_database_struct;
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
/* under construction !*/
#endif /*__POP_FSM__*/
/*****************************************************************************
*                                GLOBAL FUNCTIONS
*****************************************************************************/

/*****************************************************************************
* FUNCTION
*  mll1_el1_auto_gap_available_ind
* DESCRIPTION
*  ll1 sends auto gap available ind to EUTRAN now
*
* PARAMETERS
*  kal_bool available
* RETURNS
*  none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_auto_gap_available_ind(kal_bool available);

/*****************************************************************************
* FUNCTION
*   mll1_el1_auto_gap_cnf
* DESCRIPTION
*   ll1 sends auto gap cnf to EUTRAN now
*
* PARAMETERS
*   success - success or not
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_auto_gap_cnf(kal_bool success, kal_int64 valid_period);

/*****************************************************************************
* FUNCTION
*   mll1_el1_auto_gap_end_ind
* DESCRIPTION
*   ll1 sends auto gap end ind to EUTRAN now
*
* PARAMETERS
*   none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_auto_gap_end_ind(void);

/*****************************************************************************
* FUNCTION
*   mll1_el1_auto_gap_ind
* DESCRIPTION
*   ll1 sends auto gap ind to EUTRAN now
*
* PARAMETERS
*   eutran_time - auto time
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_auto_gap_ind(eutran_time_struct eutran_time);

/*****************************************************************************
* FUNCTION
*   mll1_el1_auto_gap_stop_cnf
* DESCRIPTION
*   ll1 sends auto gap stop cnf to EUTRAN now
*
* PARAMETERS
*   None
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_auto_gap_stop_cnf(void);

/*****************************************************************************
* FUNCTION
*   mll1_el1_auto_gap_stop_ind
* DESCRIPTION
*   ll1 sends auto gap stop ind to EUTRAN now
*
* PARAMETERS
*   None
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_auto_gap_stop_ind(void);

/*****************************************************************************
* FUNCTION
*  mll1_el1_auto_time_minus
* DESCRIPTION
*  Add more rf margin for any standby rat which will enter sleep during autonomous serch procedure
*  Assume margin is smaller than one sfn
* PARAMETERS
*   eutran_time_struct*
*   kal_int64              - more RF margin (recovery from sleep).
* RETURNS
*  void
*****************************************************************************/
void mll1_el1_auto_time_minus(eutran_time_struct* time, kal_int64 sample);

/*****************************************************************************
* FUNCTION
*   mll1_el1_expand_active_gap_pattern_ind
* DESCRIPTION
*   ll1 sends active gap pattern ind to EUTRAN now
*
* PARAMETERS
*   start_time - the first gap start time
*   use_num    - how many 480ms period el1 could use
*   skip_num   - how many 480ms period el1 should skip after use use_cnt 480ms period.
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_expand_active_gap_pattern_ind(eutran_time_struct* start_time,kal_uint8 use_num,kal_uint8 skip_num);

/*****************************************************************************
* FUNCTION
*   mll1_el1_expand_gap_pattern_ind
* DESCRIPTION
*   ll1 sends auto gap available ind to EUTRAN now
*
* PARAMETERS
*   none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_expand_gap_pattern_ind(ll1_el1_expand_gap_pattern_struct* standby_gap);

/*****************************************************************************
* FUNCTION
*   mll1_el1_gap_resume_ind
* DESCRIPTION
*   LL1 sends this message to EL1 to resume EL1 gap usage. 
*   After receiving this message, EL1 could use gap pattern normally.
*
* PARAMETERS
*   none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_gap_resume_ind(void);

/*****************************************************************************
* FUNCTION
*   mll1_el1_gap_service_request
* DESCRIPTION
*   ll1 sends gap service req to EUTRAN now
*
* PARAMETERS
*   enable   - KAL_TRUE  : turn on gap service 
*            - KAL_FALSE : turn off gap service
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_gap_service_req(kal_bool enable);

/*****************************************************************************
* FUNCTION
*   mll1_el1_gap_stop_cnf
* DESCRIPTION
*   LL1 uses this primitive to confirm EL1 that LL1 has already stopped 
*   all gap usages in standby RAT and EL1 could use all RF time.
*
* PARAMETERS
*   NONE
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_gap_stop_cnf(void);

/*****************************************************************************
* FUNCTION
*   mll1_el1_gap_stop_req
* DESCRIPTION
*   LL1 uses this primitive to stop gap usage in EUTRAN when EUTRAN is standby RAT.
*
* PARAMETERS
*   NONE
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_gap_stop_req(void);

/*****************************************************************************
* FUNCTION
*   mll1_el1_gap_suspend_cnf
* DESCRIPTION
*   LL1 sends this confirm message to EL1 after gap usage in standby RAT is suspended.
*   EL1 could use RF only after getting this message.
*
* PARAMETERS
*   NONE
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_gap_suspend_cnf(void);

/*****************************************************************************
* FUNCTION
*   mll1_el1_gap_suspend_req
* DESCRIPTION
*   LL1 uses this primitive to suspend gap usage in EUTRAN when EUTRAN is standby RAT.
*
* PARAMETERS
*   NONE
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_gap_suspend_req(void);

/*****************************************************************************
* FUNCTION
*  mll1_el1_get_auto_time
* DESCRIPTION
*   return auto time from EL1
*
* PARAMETERS
*   None
* RETURNS
*  eutran_time_struct auto_time
*****************************************************************************/
eutran_time_struct mll1_el1_get_auto_time(void);

/*****************************************************************************
* FUNCTION
*   mll1_el1_get_current_time
* DESCRIPTION
*   ll1 gets current time + ahead margin to expand gap
*
* PARAMETERS
*   eutran_time - start time of expansion period
*   kal_bool is_ahead_time
*         TRUE : advance eutran_time with the predefined ahead_time
*         FALSE: don't advance eutran_time with the predefined ahead_time
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
extern void mll1_el1_get_current_time(eutran_time_struct* eutran_time, kal_bool is_ahead_time);

/*****************************************************************************
* FUNCTION
*  mll1_el1_get_el1_rf_margin
* DESCRIPTION
*  EL1 gets RF margin in current state
*
* PARAMETERS
*  head      - header_margin
*  tail         - tail_margin
* RETURNS
*  none
*****************************************************************************/
void mll1_el1_get_el1_rf_margin(kal_int32* head,kal_int32* tail);
#ifdef __GSM_RAT__
/*****************************************************************************
* FUNCTION
*  mll1_el1_get_gl1_rf_margin
* DESCRIPTION
*  EL1 gets GL1 RF margin in current state
*
* PARAMETERS
*  head      - header_margin
*  tail         - tail_margin
* RETURNS
*  none
*****************************************************************************/
void mll1_el1_get_gl1_rf_margin(kal_int32* head,kal_int32* tail);
#endif /*__GSM_RAT__*/
/*****************************************************************************
* FUNCTION
*   mll1_el1_get_timing_status
* DESCRIPTION
*
* PARAMETERS
* RETURNS
*   kal_bool  - valid_timing  KAL_TRUE  : means still sync. cant be expanded
*                             KAL_FALSE : means sync. done
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool mll1_el1_get_timing_status(void);

/*****************************************************************************
* FUNCTION
*  mll1_el1_get_mode_status
* DESCRIPTION
*   return mode status from EL1
*
* PARAMETERS
*   None
* RETURNS
*  ll1_active_rat_mode_status_enum mode_status
*****************************************************************************/
ll1_active_rat_mode_status_enum mll1_el1_get_mode_status(void);

/*****************************************************************************
* FUNCTION
*  mll1_el1_get_t_abort
* DESCRIPTION
*   Tidentify,gsm / Treconfirm,gsm uint: ms
*
* PARAMETERS
*   carriers_other_than_gsm - Number of carriers other than GSM
*   
* RETURNS
*  kal_uint32 t_abort;
*****************************************************************************/
kal_uint32 mll1_el1_get_t_abort(kal_uint8 carriers_other_than_gsm, kal_bool is_identify);

/*****************************************************************************
* FUNCTION
*  mll1_el1_get_tick_count
* DESCRIPTION
*   EL1 tick number
*
* PARAMETERS
*   is_prio_search - KAL_FALSE : ll1_main wants to get meas. tick
*                    KAL_TRUE  : ll1_main wants to get prio. tick
*   t_hps          - 60 (uint : second)
*   
* RETURNS
*  kal_uint32 count;
*****************************************************************************/
kal_uint32 mll1_el1_get_tick_count(kal_bool is_prio_search, kal_uint16 t_hps);

#ifdef __UMTS_RAT__
#ifdef __UMTS_TDD128_MODE__
/*****************************************************************************
* FUNCTION
*  mll1_el1_get_tl1_rf_margin
* DESCRIPTION
*  EL1 gets TL1 RF margin in current state
*
* PARAMETERS
*  head      - header_margin
*  tail      - tail_margin
* RETURNS
*  none
*****************************************************************************/
void mll1_el1_get_tl1_rf_margin(kal_int32* head,kal_int32* tail);
#endif /*__UMTS_TDD128_MODE__*/
#ifdef __UMTS_FDD_MODE__
/*****************************************************************************
* FUNCTION
*  mll1_el1_get_ul1_rf_margin
* DESCRIPTION
*  EL1 gets UL1 RF margin in current state
*
* PARAMETERS
*  head      - header_margin
*  tail      - tail_margin
* RETURNS
*  none
*****************************************************************************/
void mll1_el1_get_ul1_rf_margin(kal_int32* head,kal_int32* tail);
#endif /*__UMTS_FDD_MODE__*/
#endif /*__UMTS_RAT__*/
/*****************************************************************************
* FUNCTION
*   mll1_el1_handle_gap_margin_in_connect
* DESCRIPTION
*   EL1 handle gap margin in connection mode
*
* PARAMETERS
*   *st       - gap starting time
*   *length   - gap length in sample
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_handle_gap_margin_in_connect(eutran_time_struct* st, kal_int32* length);

/*****************************************************************************
* FUNCTION
*   mll1_el1_is_before_dest_time
* DESCRIPTION
*   check if gap start time is before dest time,
*
* PARAMETERS
*   src      - gap start time
*   dest     - expand start time
*   smp_offset - the offset of (dest_sample - src_sample), only valid when returned value is KAL_TRUE. Default: INVALID
* RETURNS
*   kal_bool - KAL_TRUE  : means that src is before dest time
*              KAL_FALSE : means that dest is before src time
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool mll1_el1_is_before_dest_time(eutran_time_struct* src,eutran_time_struct* dest,kal_uint64* smp_offset);

/*****************************************************************************
* FUNCTION
*  mll1_el1_is_in_connect_gp1
* DESCRIPTION
*   use to check if el1 is in connect gp1 configuration
*
* PARAMETERS
*   
* RETURNS
*  kal_bool - KAL_TRUE  : with GP1 configuration
*             KAL_FALSE : without GP1 configuration
*****************************************************************************/
kal_bool mll1_el1_is_in_connect_gp1(void);

/*****************************************************************************
* FUNCTION
*  mll1_el1_is_lower_pwr_on
* DESCRIPTION
*   Check if el1 is low pwr on
*
* PARAMETERS
*   
* RETURNS
*  kal_bool - KAL_FALSE : measurement is not finished and need gap in this period 
*             KAL_TRUE  : measurement is finished and doesnt need gap in this period
*****************************************************************************/
kal_bool mll1_el1_is_lower_pwr_on(void);

/*****************************************************************************
* FUNCTION
*   mll1_el1_mode_status_update_ind
* DESCRIPTION
*   This message is sent to EL1 for informing that mode status of active RAT when EL1 is standby RAT. 
*   This message should be updated for EL1 in standby when any mode status changed in active RAT.
*
* PARAMETERS
*   status - mode status in active RAT 
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_mode_status_update_ind(ll1_active_rat_mode_status_enum status);

/*****************************************************************************
* FUNCTION
*   mll1_el1_set_timing_status
* DESCRIPTION
*
* PARAMETERS
*   flag     - set valid_timing = flag
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_set_timing_status(kal_bool flag);

/*****************************************************************************
* FUNCTION
*   mll1_el1_sync_time_req
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
void mll1_el1_sync_time_req(void);

/*****************************************************************************
* FUNCTION
*  mll1_el1_time_add
* DESCRIPTION
*  This function is used to add samples to time
*
* PARAMETERS
*   time          - basic time
*   samples    - samples
* RETURNS
*  none
*****************************************************************************/
void mll1_el1_time_add( eutran_time_struct* time, kal_int32 samples);

/*****************************************************************************
* FUNCTION
*   mll1_el1_update_current_time
* DESCRIPTION
*   ll1 updates current after timing sync done
*
* PARAMETERS
*   eutran_time - current time
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_update_current_time(eutran_time_struct* eutran_time);

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   mll1_eutran_handler()
*
* DESCRIPTION
*   Function to handle the primitive from EL1.
*
* PARAMETERS
*   current_ilm - primitive from EL1.
*
* RETURN
*   None
*****************************************************************************/
void mll1_eutran_handler(void *ptr_ilm);

/*****************************************************************************
* FUNCTION
*   mll1_tick_el1_gap_expansion
* DESCRIPTION
*   tick el1 to expand gap when sync done
*
* PARAMETERS
*   none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tick_el1_gap_expansion(void);

/*****************************************************************************
* FUNCTION
*   mll1_el1_info_init
* DESCRIPTION
*   Initialize el1 internal global variable
*
* PARAMETERS
*   none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_el1_info_init(void);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_gap_pattern_timing_checking
* DESCRIPTION
*   check if the pending gap is out of date or not
*
* PARAMETERS
*   eutran_time   - el1 timing correspond to some standby rat's timing indicated in measure request
* RETURNS
*   TRUE   - the pending gap has not been out of date
*   FALSE   - the pending gap has been out of date
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool mll1_el1_gap_pattern_timing_checking(eutran_time_struct eutran_time);

#endif /*_MLL1_EUTRAN_H*/
