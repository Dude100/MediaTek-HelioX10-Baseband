#ifndef _MLL1_UMTS_TDD_H
#define _MLL1_UMTS_TDD_H

#include "kal_public_defs.h" /*for LOCAL_PARA_HDR*/
#include "mll1_common.h"
/*****************************************************************************
*                                    DEFINITIONS
*****************************************************************************/
#define MO_PURPOSE_NUM             12 /* Undefined */
#define UMTS_TDD_SESSION_IN_PERIOD 8  /* align gsm, LTE only need 6 for gp0/gp1 */
#define UMTS_TDD_SCHEDULE_DELAY    0 /* used to postpone available gap start time */
/*****************************************************************************
*                                    ENUMERATIONS
*****************************************************************************/
/*****************************************************************************
* ENUMERATION
*    tl1_ll1_rat_status_enum
* DESCRIPTIONS
*    Used to identify the status in UMTS TDD RAT.
* NOTE
*    any modification should sync. with ll1_rat_status_enum
*****************************************************************************/
typedef enum
{
  TL1_LL1_RAT_FLIGHT =0,
  TL1_LL1_RAT_STANDBY,
  TL1_LL1_RAT_ACTIVE,
  TL1_LL1_RAT_NUM
} tl1_ll1_rat_status_enum;

/*****************************************************************************
*                                    STRUCTURES
*****************************************************************************/
/*****************************************************************************
* STRUCT
*   umts_tdd_time_struct
*
* DESCRIPTIONS
*   UMTS TDD system timing base
*
* PARAMETERS
*   sub_sfn   - UMTS TDD sub-system frame number (0~8191), 1 sub_sfn = 6400*8.
*   echips    - UMTS TDD Echip (0~51199)
*****************************************************************************/
typedef struct
{
  kal_int32        sub_sfn;
  kal_int32        echips;
}umts_tdd_time_struct;

/*****************************************************************************
* STRUCT
*   umts_tdd_mo_allocation_struct
*
* DESCRIPTIONS
*   UMTS TDD measurement occasion allocation structure in subframe.
*
* PARAMETERS
*   period      - Measurement occasion period
*   length      - The measurement occasion length starting from the Offset
*   offset      - The measurement occasion position in the measurement period.
*   slot_bmp    - Bit 0 is for timeslot 0/DwPTS/GP (LL1 will not expand UpPTS for TA of slot 1).
*                 Bit 1 is for timeslot 1/UpPTS.
*                 Bit 2 is for timeslot 2 ¡K Bit 6 is for timeslot 6.
*                 The value 1 of a bit means the corresponding timeslot is used for measurement.
*                 Bit 0 is the first/right most bit of the bit string.
*   purpose_bmp - Measurement Purpose. 
*                 Bit 0 is for E-UTRA measurement.
*                 Bit 1 is for Inter-frequency measurement.
*                 Bit 2 is for BSIC re-confirmation.
*                 Bit 3 is for Initial BSIC identification.
*                 Bit 4 is for GSM carrier RSSI measurement.
*                 Bit 5 is for Drop frame for EL1-Meas.  
*                 Bit 6 is for Reserved for FB/SB search
*                 Bit 7 is for ISCP.
*                 Bit 8 is for FMO.
*                 Bit 9 is for DL.
*                 Bit 10 is for UL.
*                 The value 1 of a bit means that the measurement occasion pattern sequence is applicable for the corresponding type of measurement.
*                 Bit 0 is the first/rightmost bit of the bit string.
*                 Only one bit will be set to 1, the others are set to zero.
*****************************************************************************/
typedef struct
{
   kal_uint16 period;
   kal_uint16 length;
   kal_uint16 offset;
   kal_uint8  slot_bmp;
   kal_uint32 purpose_bmp;
}umts_tdd_mo_allocation_struct;

/*****************************************************************************
* STRUCT
*   umts_tdd_idle_gap_struct
*
* DESCRIPTIONS
*   Idle gap structure of UMTS TDD.
*
* PARAMETERS
*   start_time  - start time of the gap
*   length      - length of the gap session (in echip)
*   is_drx_tick - KAL_TRUE : First tick in this DRX period
*                 KAL_FALSE: Not the first free interval in this DRX period
*****************************************************************************/
typedef struct
{
   umts_tdd_time_struct start_time;
   kal_int32            length;
   kal_bool             is_drx_tick;
}umts_tdd_idle_gap_struct;

/*****************************************************************************
* STRUCT
*   umts_tdd_connected_gap_struct
*
* DESCRIPTIONS
*   UMTS TDD gap structure in CELL_FACH/CELL_DCH.
*
* PARAMETERS
*   mo_num             - The number of mo pattern
*   measure_occasion[] - One measure_occasion[] stands for one measurement occasion. 
*                        purpose_bmp in umts_tdd_mo_allocation_struct may set more than one bit to 1 due to DMO configuration.
*                        MO_PURPOSE_NUM = total number of measurement purposes = 12.
*   last_tx_slot       - The last TX slot UE used before the second switch point in one sub-frame.
*   doff               - to align CFN in sub-frame,
*                        only used when umts_tdd_mo_allocation_struct.purpose_bmp
*                        Bit 9 or 10 is set to 1.
*                        Bit 9 is for DL.
*                        Bit 10 is for UL.
*****************************************************************************/
typedef struct
{
   kal_uint16                    mo_num;
   umts_tdd_mo_allocation_struct measure_occasion[MO_PURPOSE_NUM];
   kal_uint8                     last_tx_slot;
   kal_uint8                     doff;
}umts_tdd_connected_gap_struct;

/*****************************************************************************
* STRUCT
*   ll1_umts_tdd_standby_gap_struct
*
* DESCRIPTIONS
*   UMTS TDD standby gap pattern structure.
*
* PARAMETERS
*   start_time - start time of the gap session
*   length     - length of the gap session (in echip)
*****************************************************************************/
typedef struct
{
   umts_tdd_time_struct start_time;
   kal_int32            length;
}ll1_umts_tdd_standby_gap_struct;

/*****************************************************************************
* STRUCT
*   ll1_tl1_expand_gap_pattern_struct
*
* DESCRIPTIONS
*   LL1 expands gap pattern for TL1
*
* PARAMETERS
*   session_num  - Indicate how many gap session 
*   session[]    - Standby gap session.
*   measure_tid  - Transition id for RANK tick./Valid when active RAT is in DRX mode./And bit 0 in tick_bitmap is "1"
*   hps_tid      - Transition id for HPS tick./Valid when active RAT is in DRX mode./And bit 1 in tick_bitmap is "1"
*   tick_bitmap  - Bit 0 : Rank search , Bit 1 : Priority search when active rat in idle mode, 
*                  Bit 0 : is_first gap in Nfreq*expansion_period when active rat in connect mode.
*****************************************************************************/
typedef struct
{
   kal_uint8                       session_num;
   ll1_umts_tdd_standby_gap_struct session[UMTS_TDD_SESSION_IN_PERIOD];
   kal_uint8                       measure_tid;
   kal_uint8                       hps_tid;
   kal_uint8                       tick_bitmap;
}ll1_tl1_expand_gap_pattern_struct;

/*****************************************************************************
* STRUCT
*   tl1_ll1_sync_cnf_struct
*
* DESCRIPTIONS
*   TL1 uses this primitive to confirm LL1 that current UMTS TDD timing 
*   and micro second counter value.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   current_time      - sync. time in umts_tdd_time_struct 
*   umts_tdd_ustime   - sync. time in USC  
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   umts_tdd_time_struct current_time;
   kal_uint32           umts_tdd_ustime;
}tl1_ll1_sync_cnf_struct;

/*****************************************************************************
* STRUCT
*   tl1_ll1_rat_status_ind_struct
*
* DESCRIPTIONS
*   This message is sent from TL1 to LL1 for informing current TL1 RAT status. 
*   This message should be sent when TL1 RAT status changed.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   rat_status - RAT status in TL1 
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   tl1_ll1_rat_status_enum rat_status;
}tl1_ll1_rat_status_ind_struct;

/*****************************************************************************
* STRUCT
*   tl1_ll1_mode_status_ind_struct
*
* DESCRIPTIONS
*   This message is sent from TL1 to LL1 for informing that TL1 mode status when TL1 is active RAT. 
*   This message should be sent when TL1 mode status changed.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   tdd_mode_status  - current mode in TL1 when UMTS TDD is active RAT
*   drx_cycle_length - valid when gsm_mode_status = TL1_LL1_PCH_MODE
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   ll1_active_rat_mode_status_enum tdd_mode_status;
   kal_uint16                      drx_cycle_length;
}tl1_ll1_mode_status_ind_struct;

/*****************************************************************************
* STRUCT
*   ll1_tl1_mode_status_update_ind_struct
*
* DESCRIPTIONS
*   This message is sent to TL1 for informing that mode status of active RAT when TL1 is standby RAT. 
*   This message should be updated for TL1 in standby when any mode status changed in active RAT. 
*   Also when TL1 enters into standby RAT from FLIGHT, LL1 will update current mode state in active RAT to TL1.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   active_rat_mode_status - current mode status in active RAT
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   ll1_active_rat_mode_status_enum active_rat_mode_status;
}ll1_tl1_mode_status_update_ind_struct;

/*****************************************************************************
* STRUCT
*   tl1_ll1_active_measure_status_ind_struct
*
* DESCRIPTIONS
*   TL1 informs LL1 that how many higher priority inter-frequencies in TL1 when high priority search is turned on
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   freq_num      - The number of higher priority inter-freq. in TL1.(0~3)
*                   When HPS off, the freq_num is equal to zero.
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8     freq_num;
}tl1_ll1_active_measure_status_ind_struct;


/*****************************************************************************
* STRUCT
*   tl1_ll1_measure_req_struct
*
* DESCRIPTIONS
*   This message is sent from TL1 to inform LL1 that how many UMTS TDD frequencies are required to be measured and the measurement purposes in UMTS TDD Standby.
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
*   current_time        - current in TL1
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
   umts_tdd_time_struct  current_time; 
}tl1_ll1_measure_req_struct;

/*****************************************************************************
* STRUCT
*   tl1_ll1_standby_measure_done_ind_struct
*
* DESCRIPTIONS
*   For low power optimization, TL1 informs LL1 which measurement purpose is 
*   measured done in its period. If all measurement purposes are measured done, 
*   LL1 will not tick TL1 anymore in shortest measurement period.
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
}tl1_ll1_standby_measure_done_ind_struct;

/*****************************************************************************
* STRUCT
*   ll1_tl1_gap_service_req_struct
*
* DESCRIPTIONS
*   LL1 uses this primitive to enable (disable) active RAT gap service to get (release) 
*   the free radio frequency period in UMTS TDD.When LL1 disables active RAT gap service, 
*   it means that UMTS TDD could use all RF time already.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   enable           - KAL_TRUE  : request gap service
*                      KAL_FALSE : stop gap service
*   service_type_bmp - Bit 0 for FB/SB search in GSM
*                      Bit 1 for LTE meas.
*                      The  value 1 of a bit means that TL1 should provide suitable gap pattern  for the corresponding type of measurement.
*                      Bit 0 is the first/rightmost bit of the bit string.
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_bool      enable;
   kal_uint8     service_type_bmp;
}ll1_tl1_gap_service_req_struct;


/*****************************************************************************
* STRUCT
*   tl1_ll1_gap_stop_cnf_struct
*
* DESCRIPTIONS
*   TL1 uses this primitive to confirm LL1_TL1_GAP_STOP_REQ when there is no gap usage in UMTS_TDD..
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   current_time  - current time in TL1
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   umts_tdd_time_struct current_time;
}tl1_ll1_gap_stop_cnf_struct;

/*****************************************************************************
* STRUCT
*   tl1_ll1_auto_gap_req_struct
*
* DESCRIPTIONS
*   TL1 sends this message to request LL1 that TL1 wants to use the auto gap  from  (sub_sfn, echips). 
*   TL1 could use this auto gap after getting the successful confirm
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   auto_time  - Start time of auto gap in TL1
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   umts_tdd_time_struct auto_time;
}tl1_ll1_auto_gap_req_struct;

/*****************************************************************************
* STRUCT
*   ll1_tl1_auto_gap_cnf_struct
*
* DESCRIPTIONS
*   LL1 sends this message to confirm TL1 auto gap request. 
*   After receiving this message, TL1 could use required auto gap.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   success       - KAL_TRUE : TL1 could use auto gap to search
*                   KAL_FALSE: TL1 could not use auto gap to search. 
*                              And TL1 should not request auto gap until AUTO_GAP_AVAILABLE_IND
*   valid_period  - The length of  autonomous gap allowed by active RAT 
*                   The value is valid when success = KAL_TRUE
*                   Unit : echip 
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_bool  success;
   kal_int32 valid_period;
}ll1_tl1_auto_gap_cnf_struct;

/*****************************************************************************
* STRUCT
*   ll1_tl1_auto_gap_ind_struct
*
* DESCRIPTIONS
*   LL1 sends this message to inform TL1 stopping using RF in this auto gap from   (sub_sfn, echips).
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   auto_time  - Start time of auto gap
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   umts_tdd_time_struct auto_time;
}ll1_tl1_auto_gap_ind_struct;

/*****************************************************************************
* STRUCT
*   tl1_ll1_auto_gap_res_struct
*
* DESCRIPTIONS
*   TL1 sends this message to response LL1 that TL1 will/won't use RF from 
*   the start timing of auto gap which is informed by LL1_TL1_AUTO_GAP_IND.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   success       - KAL_TRUE : TL1 will not use RF from the starting time of LL1_TL1_AUTONOMOIS_GAP_IND
*                   KAL_FALSE: TL1 may use RF after starting time of LL1_TL1_AUTONOMOIS_GAP_IND. 
*   valid_period  - The length of  autonomous gap allowed in TL1 
*                   The value is valid when TL1 is active rat and success = KAL_TRUE
*                   Unit : echip
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_bool  success;
   kal_int32 valid_period;
}tl1_ll1_auto_gap_res_struct;

/*****************************************************************************
* STRUCT
*   ll1_tl1_gap_notify_ind_struct
*
* DESCRIPTIONS
*   LL1 sends this message to inform TL1 that the starting time and length of gap pattern when TL1 is standby RAT.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   standby_gap   - standby gap pattern
*   tid           - tid for lastest meas_req on
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   ll1_tl1_expand_gap_pattern_struct standby_gap;
   kal_uint8                         tid;        /* Tid for lastest meas_req on, LL1 will expand gap notify ind with this tid*/   
}ll1_tl1_gap_notify_ind_struct;

/*****************************************************************************
* STRUCT
*   tl1_ll1_gap_pattern_ind_struct
*
* DESCRIPTIONS
*   TL1 sends this message to inform LL1 that the free RF period in TL1 as gap pattern. 
* PARAMETERS
*   LOCAL_PARA_HDR  
*   tl1_current_time - TL1 current time
*   idle_gap         - No matter the length is bigger than zero or not, 
*                      TL1 should send this message and sets is_drx_tick = KAL_TRUE in one DRX period once.
*   dch_gap          - Gap pattern provided by TL1 in CELL_FACH/CELL_DCH
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   umts_tdd_time_struct           tl1_current_time;
   umts_tdd_idle_gap_struct       idle_gap;
   umts_tdd_connected_gap_struct  connect_gap;
}tl1_ll1_gap_pattern_ind_struct;

/*****************************************************************************
* STRUCT
*   ll1_tl1_sync_req_struct
*   tl1_ll1_gap_stop_req_struct
*   ll1_tl1_gap_stop_cnf_struct
*   ll1_tl1_gap_stop_req_struct
*   tl1_ll1_gap_suspend_req_struct
*   ll1_tl1_gap_suspend_cnf_struct
*   ll1_tl1_gap_suspend_req_struct
*   tl1_ll1_gap_suspend_cnf_struct
*   tl1_ll1_gap_resume_ind_struct
*   ll1_tl1_gap_resume_ind_struct
*   tl1_ll1_auto_gap_stop_req_struct
*   ll1_tl1_auto_gap_stop_ind_struct
*   tl1_ll1_auto_gap_stop_res_struct
*   ll1_tl1_auto_gap_stop_cnf_struct
*   tl1_ll1_auto_gap_end_ind_struct
*   ll1_tl1_auto_gap_end_ind_struct
*   tl1_ll1_auto_gap_available_ind_struct
*   ll1_tl1_auto_gap_available_ind_struct
*
* DESCRIPTIONS
*   ll1_tl1_sync_req_struct
*     LL1 will use this primitive to get TL1 current UMTS timing and micro 
*     second counter value in both TL1 in active and standby mode.
*
*   tl1_ll1_gap_stop_req_struct
*     TL1 uses this primitive to inform LL1 to stop all gap usage in standby 
*     RAT when GERAN GSM wants to change configuration or other purposes.
*
*   ll1_tl1_gap_stop_cnf_struct
*     LL1 uses this primitive to confirm TL1 that LL1 has already stopped 
*     all gap usages in standby RAT and TL1 could use all RF time.
*
*   ll1_tl1_gap_stop_req_struct
*     LL1 uses this primitive to stop gap usage in UMTS TDD when UMTS TDD is standby RAT.
*
*   tl1_ll1_gap_suspend_req_struct
*     TL1 uses this primitive to temporal suspend gap usage in standby RAT for higher priority
*     task and doesn't need to give new gap configuration in connection mode when resumed.
*
*   ll1_tl1_gap_suspend_cnf_struct
*     LL1 sends this confirm message to TL1 after all standby RAT gap usage are suspended.
*
*   ll1_tl1_gap_suspend_req_struct
*     LL1 sends this message to TL1 to request that TL1 suspends RF usage immediately.
*
*   tl1_ll1_gap_suspend_cnf_struct
*     TL1 sends this message to confirm LL1 that TL1 will not use gap from 
*     now to receiving resume indicator
*
*   tl1_ll1_gap_resume_ind_struct
*     TL1 sends this message to inform LL1 that TL1 has already finished 
*     higher priority task, and standby RAT could use gap normally.
*
*   ll1_tl1_gap_resume_ind_struct
*     LL1 sends this message to TL1 to resume TL1's gap usage. 
*     After receiving this message, TL1 could  use gap pattern normally.
*
*   tl1_ll1_auto_gap_stop_req_struct
*     TL1 sends this message to request LL1 that TL1 wants to 
*     retrieve autonomous gap for higher priority task.
*
*   ll1_tl1_auto_gap_stop_ind_struct
*     LL1 sends this message to inform TL1 of stopping using RF 
*     during autonomous gap period.
*
*   tl1_ll1_auto_gap_stop_res_struct
*     TL1 sends this message to response LL1 that TL1 stops 
*     autonomous gap usage.
*
*   ll1_tl1_auto_gap_stop_cnf_struct
*     LL1 sends this message to confirm that TL1 could use RF now.
*
*   tl1_ll1_auto_gap_end_ind_struct
*     TL1 sends this message to inform LL1 that autonomous gap usage is finished.
* 
*   ll1_tl1_auto_gap_end_ind_struct
*     LL1 sends this message to inform TL1 that autonomous gap usage is finished.
*
*   tl1_ll1_auto_gap_available_ind_struct
*     TL1 sends this message to inform LL1 that autonomous gap is available now. Standby RAT 
*     could request autonomous gap now. Standby RAT could request autonomous gap now
*
*   ll1_tl1_auto_gap_available_ind_struct
*     LL1 sends this message to inform TL1 that autonomous gap 
*     is available now. TL1 could request autonomous gap now.
*
*   tl1_ll1_auto_gap_unavailable_ind_struct
*     TL1 sends this message to inform LL1 that auto gap is unavailable now. 
*     Standby RAT could not request auto gap now.
*
*   ll1_tl1_auto_gap_unavailable_ind_struct
*     LL1 sends this message to inform TL1 that auto gap is unavailable now. 
*     TL1 could not request auto gap now.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
}ll1_tl1_sync_req_struct,
 tl1_ll1_gap_stop_req_struct,
 ll1_tl1_gap_stop_cnf_struct,
 ll1_tl1_gap_stop_req_struct,
 tl1_ll1_gap_suspend_req_struct,
 ll1_tl1_gap_suspend_cnf_struct,
 ll1_tl1_gap_suspend_req_struct,
 tl1_ll1_gap_suspend_cnf_struct,
 tl1_ll1_gap_resume_ind_struct,
 ll1_tl1_gap_resume_ind_struct,
 tl1_ll1_auto_gap_stop_req_struct,
 ll1_tl1_auto_gap_stop_ind_struct,
 tl1_ll1_auto_gap_stop_res_struct,
 ll1_tl1_auto_gap_stop_cnf_struct,
 tl1_ll1_auto_gap_end_ind_struct,
 ll1_tl1_auto_gap_end_ind_struct,
 tl1_ll1_auto_gap_available_ind_struct,
 ll1_tl1_auto_gap_available_ind_struct,
 tl1_ll1_auto_gap_unavailable_ind_struct,
 ll1_tl1_auto_gap_unavailable_ind_struct;
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
* STRUCT
*   mll1_tl1_info_database_struct
*
* DESCRIPTIONS
*   TL1 information structure.
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
   kal_bool                            is_meas_done_useful; /* umts tdd uses meas_done or not by checking meas_purpose_bmp*/
   kal_uint8                           meas_purpose_bitmap; /* record the measure purpose bitmap*/
   umts_tdd_time_struct                current_time;        /* umts tdd current time when request gap service*/
   /* Paging period in active RAT */
   kal_int32                           drx_cycle;           /* 80,160,320,640,1280,2560,5120 Unit : ms*/
   /* auto gap para*/
   umts_tdd_time_struct                auto_time;           /* auto gap time*/ 
   /* Mode status*/
   ll1_active_rat_mode_status_enum     mode_status;         /* mode status*/   
   /* GAP pattern*/
   tl1_ll1_gap_pattern_ind_struct      gap_pattern;         /* Gap pattern */
   /* Gap request from standby rat should do sync in connection*/
   kal_bool                            valid_timing;        /* KAL_TRUE  : with valid timing*/
                                                            /* KAL_FALSE : with invalid timing*/
   kal_uint16                          dmo_lte_len;         /* length of dmo for lte*/
   kal_uint16                          dmo_lte_period;      /* period of dmo for lte*/
   kal_uint8                           meas_req_tid;        /* Tid for lastest meas_req on, LL1 will expand gap notify ind with this tid*/
}mll1_tl1_info_database_struct;

/*****************************************************************************
*                                GLOBAL FUNCTIONS
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*   mll1_tick_tl1_gap_expansion
* DESCRIPTION
*   tick tl1 to expand gap when sync done
*
* PARAMETERS
*   none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tick_tl1_gap_expansion(void);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_auto_gap_available_ind
* DESCRIPTION
*   ll1 sends auto gap available ind to UMTS TDD now
*
* PARAMETERS
*   kal_bool available
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tl1_auto_gap_available_ind(kal_bool available);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_auto_gap_cnf
* DESCRIPTION
*   ll1 sends auto gap cnf to UMTS_TDD now
*
* PARAMETERS
*   success - success or not
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tl1_auto_gap_cnf(kal_bool success,kal_int32 valid_period);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_auto_gap_end_ind
* DESCRIPTION
*   ll1 sends auto gap end ind to UMTS TDD now
*
* PARAMETERS
*   none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tl1_auto_gap_end_ind(void);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_auto_gap_ind
* DESCRIPTION
*   ll1 sends auto gap end ind to UMTS TDD now
*
* PARAMETERS
*   tdd_time - auto time
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tl1_auto_gap_ind(umts_tdd_time_struct tdd_time);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_auto_gap_stop_cnf
* DESCRIPTION
*   ll1 sends auto gap stop cnf to UMTS_TDD now
*
* PARAMETERS
*   None
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tl1_auto_gap_stop_cnf(void);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_auto_gap_stop_ind
* DESCRIPTION
*   ll1 sends auto gap stop ind to UMTS_TDD now
*
* PARAMETERS
*   None
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tl1_auto_gap_stop_ind(void);

/*****************************************************************************
* FUNCTION
*  mll1_tl1_auto_time_minus
* DESCRIPTION
*  Add more rf margin for any standby rat which will enter sleep during autonomous serch procedure
*  Assume margin is smaller than one sub_sfn
* PARAMETERS
*   umts_tdd_time_struct*
*   kal_int32              - more RF margin (recovery from sleep).
* RETURNS
*  void
*****************************************************************************/
void mll1_tl1_auto_time_minus(umts_tdd_time_struct* time, kal_int32 echip);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_expand_gap_pattern_ind
* DESCRIPTION
*   ll1 sends auto gap available ind to UMTS TDD now
*
* PARAMETERS
*   standby_gap - gap pattern for umts tdd
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tl1_expand_gap_pattern_ind(ll1_tl1_expand_gap_pattern_struct* standby_gap);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_gap_resume_ind
* DESCRIPTION
*   LL1 sends this message to TL1 to resume TL1's gap usage. 
*   After receiving this message, TL1 could  use gap pattern normally.
*
* PARAMETERS
*   none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tl1_gap_resume_ind(void);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_gap_service_req
* DESCRIPTION
*   ll1 sends gap service req to UMTS_TDD now
*
* PARAMETERS
*   enable   - KAL_TRUE  : turn on gap service 
*            - KAL_FALSE : turn off gap service
*   service_type_bmp - Bit 0 for FB/SB search in GSM
*                      Bit 1 for LTE meas.
*                      The  value 1 of a bit means that TL1 should provide suitable gap pattern  for the corresponding type of measurement.
*                      Bit 0 is the first/rightmost bit of the bit string.
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tl1_gap_service_req(kal_bool enable, kal_uint8 service_type_bmp);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_gap_stop_cnf
* DESCRIPTION
*   LL1 uses this primitive to confirm TL1 that LL1 has already stopped 
*   all gap usages in standby RAT and TL1 could use all RF time.
*
* PARAMETERS
*   NONE
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tl1_gap_stop_cnf(void);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_gap_stop_req
* DESCRIPTION
*   LL1 uses this primitive to stop gap usage in UMTS TDD when UMTS TDD is standby RAT.
*
* PARAMETERS
*   NONE
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tl1_gap_stop_req(void);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_gap_suspend_cnf
* DESCRIPTION
*   LL1 sends this confirm message to TL1 after gap usage in standby RAT is suspended.
*   TL1 could use RF only after getting this message.
*
* PARAMETERS
*   NONE
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tl1_gap_suspend_cnf(void);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_gap_suspend_req
* DESCRIPTION
*   LL1 uses this primitive to suspend gap usage in UMTS TDD when UMTS TDD is standby RAT.
*
* PARAMETERS
*   NONE
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tl1_gap_suspend_req(void);

/*****************************************************************************
* FUNCTION
*  mll1_tl1_get_auto_time
* DESCRIPTION
*   return auto time from TL1
*
* PARAMETERS
*   None
* RETURNS
*  umts_tdd_time_struct auto_time
*****************************************************************************/
umts_tdd_time_struct mll1_tl1_get_auto_time(void);


/*****************************************************************************
* FUNCTION
*   mll1_tl1_get_current_time
* DESCRIPTION
*   ll1 gets current time + ahead margin to expand gap
*
* PARAMETERS
*   umts_tdd_time - start time of expansion period
*   kal_bool is_ahead_time
*         TRUE : advance eutran_time with the predefined ahead_time
*         FALSE: don't advance eutran_time with the predefined ahead_time
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tl1_get_current_time(umts_tdd_time_struct* tdd_time, kal_bool is_ahead_time);

/*****************************************************************************
* FUNCTION
*  mll1_tl1_get_dmo_para
* DESCRIPTION
*   return length , period of dmo for lte from TL1
*
* PARAMETERS
*   *length
*   *period
* RETURNS
*  none
*****************************************************************************/
void mll1_tl1_get_dmo_para(kal_uint16* length,kal_uint16* period);

#ifdef __LTE_RAT__
/*****************************************************************************
* FUNCTION
*  mll1_tl1_get_el1_rf_margin
* DESCRIPTION
*  TL1 gets EL1 RF margin in current state
*
* PARAMETERS
*  head      - header_margin
*  tail      - tail_margin
* RETURNS
*  none
*****************************************************************************/
void mll1_tl1_get_el1_rf_margin(kal_int32* head,kal_int32* tail);
#endif /*__LTE_RAT__*/

#ifdef __GSM_RAT__
/*****************************************************************************
* FUNCTION
*  mll1_tl1_get_gl1_rf_margin
* DESCRIPTION
*  TL1 gets GL1 RF margin in current state
*
* PARAMETERS
*  head      - header_margin
*  tail      - tail_margin
*  st_slot   - gap start slot in DCH
*  len       - gap len in DCH
* RETURNS
*  none
*****************************************************************************/
void mll1_tl1_get_gl1_rf_margin(kal_int32* head,kal_int32* tail, kal_int32 st_slot, kal_int32 len);
#endif /*__GSM_RAT__*/

/*****************************************************************************
* FUNCTION
*  mll1_tl1_get_mode_status
* DESCRIPTION
*   return mode status from TL1
*
* PARAMETERS
*   None
* RETURNS
*  ll1_active_rat_mode_status_enum mode_status
*****************************************************************************/
ll1_active_rat_mode_status_enum mll1_tl1_get_mode_status(void);

/*****************************************************************************
* FUNCTION
*  mll1_tl1_get_tick_count
* DESCRIPTION
*   TL1 tick number
*
* PARAMETERS
*   is_prio_search - KAL_FALSE : ll1_main wants to get meas. tick
*                    KAL_TRUE  : ll1_main wants to get prio. tick
*   t_hps          - 60 (uint : second)
*   
* RETURNS
*  kal_uint32 count;
*****************************************************************************/
kal_uint32 mll1_tl1_get_tick_count(kal_bool is_prio_search, kal_uint16 t_hps);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_get_timing_status
* DESCRIPTION
*
* PARAMETERS
* RETURNS
*   kal_bool  - valid_timing KAL_TRUE  : with valid timing
*                            KAL_FALSE : with invalid timing
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool mll1_tl1_get_timing_status(void);

/*****************************************************************************
* FUNCTION
*  mll1_tl1_get_tl1_rf_margin
* DESCRIPTION
*  TL1 gets RF margin in current state
*
* PARAMETERS
*  head      - header_margin
*  tail      - tail_margin
* RETURNS
*  none
*****************************************************************************/
void mll1_tl1_get_tl1_rf_margin(kal_int32* head,kal_int32* tail);

/*****************************************************************************
* FUNCTION
*  mll1_tl1_is_lower_pwr_on
* DESCRIPTION
*   Check if tl1 is low pwr on
*
* PARAMETERS
*   
* RETURNS
*  kal_bool - KAL_FALSE : measurement is not finished and need gap in this period 
*             KAL_TRUE  : measurement is finished and doesnt need gap in this period
*****************************************************************************/
kal_bool mll1_tl1_is_lower_pwr_on(void);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_mode_status_update_ind
* DESCRIPTION
*   This message is sent to TL1 for informing that mode status of active RAT when TL1 is standby RAT. 
*   This message should be updated for TL1 in standby when any mode status changed in active RAT.
*
* PARAMETERS
*   status - mode status in active RAT 
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tl1_mode_status_update_ind(ll1_active_rat_mode_status_enum status);


/*****************************************************************************
* FUNCTION
*   mll1_tl1_set_purpose_for_expansion_period
* DESCRIPTION
*
* PARAMETERS
*   kal_uint32** m - two dimension array of gap purposes
*   kal_int32 st_subsfn - starting time of expansion period
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tl1_set_purpose_for_expansion_period(kal_uint32** m, kal_int32 st_subsfn);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_set_timing_status
* DESCRIPTION
*
* PARAMETERS
*   flag     - set valid_timing = flag
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tl1_set_timing_status(kal_bool flag);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_sync_time_req
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
void mll1_tl1_sync_time_req(void);

/*****************************************************************************
* FUNCTION
*  mll1_tl1_time_add
* DESCRIPTION
*  This function is used to add echips to time
*
* PARAMETERS
*   time       - basic time
*   echips     - echips
* RETURNS
*  none
*****************************************************************************/
void mll1_tl1_time_add( umts_tdd_time_struct* time, kal_int32 echips);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_update_current_time
* DESCRIPTION
*   ll1 updates current time after timing sync. done
*
* PARAMETERS
*   umts_tdd_time - current time
* RETURNS
*   none 
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tl1_update_current_time(umts_tdd_time_struct* tdd_time);

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   mll1_umts_tdd_handler()
*
* DESCRIPTION
*   Function to handle the primitive from TL1.
*
* PARAMETERS
*   current_ilm - primitive from TL1.
*
* RETURN
*   None
*****************************************************************************/
void mll1_umts_tdd_handler(void *ptr_ilm);

/*****************************************************************************
* FUNCTION
*  mll1_tl1_info_init
* DESCRIPTION
*  Initialize tl1 internal global variable
*
* PARAMETERS
*  none
* RETURNS
*  none
*****************************************************************************/
void mll1_tdd_info_init(void);

/*****************************************************************************
* FUNCTION
*   mll1_tl1_gap_pattern_timing_checking
* DESCRIPTION
*   check if the pending gap is out of date or not
*
* PARAMETERS
*   umts_tdd_time   - tl1 timing correspond to some standby rat's timing indicated in measure request
* RETURNS
*   TRUE   - the pending gap has not been out of date
*   FALSE   - the pending gap has been out of date
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool mll1_tl1_gap_pattern_timing_checking(umts_tdd_time_struct umts_tdd_time);

#endif /*_MLL1_UMTS_TDD_H*/
