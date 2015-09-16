#ifndef _MLL1_GSM_H
#define _MLL1_GSM_H

#include "kal_public_defs.h" /*for LOCAL_PARA_HDR*/
#include "mll1_common.h"

/*****************************************************************************
*                                    DEFINITIONS
*****************************************************************************/
#ifdef __UMTS_RAT__
#ifdef __UMTS_FDD_MODE__
#define GSM_SESSION_IN_PERIOD  48 /* it is possible to have 2 gaps in 3 frames. 48/3*2= 3 , However, 8960 can have the set with 48 gap.*/
#endif /*__UMTS_FDD_MODE__*/

#ifdef __UMTS_TDD128_MODE__
#define GSM_SESSION_IN_PERIOD  312 /*DMO in two frames will give at most 13 spare slots (4+3+3+3), 480/20 *13 = 312*/
#endif /*__UMTS_TDD128_MODE__*/
#else /* LTE/GSM dual mode*/
#define GSM_SESSION_IN_PERIOD  6 /* LTE GP0 /GP1 = 6 gap*/
#endif /*__UMTS_RAT__*/


/* should sync. with mll1_const.h, and modify LL1_TGPS_GSM_PURPOSE_BITMAP_MAGIC_NUM in mll1_private.h */
#define MLL1_GAP_GSM_MEAS_BIT              (0x0002) /* bit  1*/
#define MLL1_GAP_GSM_BSIC_IDENTITY_BIT     (0x0004) /* bit  2*/
#define MLL1_GAP_GSM_BSIC_RECONFIRM_BIT    (0x0008) /* bit  3*/
#define MLL1_GAP_RESERVED_GSM_BSIC_BIT     (0x0040) /* bit  6*/
#define MLL1_GAP_DROP_TDS_FOR_GSM_BSIC_BIT (0x0040) /* bit  6*/
#define MLL1_GAP_GSM_FMO                   (0x0100) /* bit  8*/
#define MLL1_GAP_RESERVED_FOR_GSM_BSIC_BIT (0x0800) /* bit 11*/
#define MLL1_GAP_GSM_UNDEFINED_BIT         (0x1000) /* bit 12*/
#define MLL1_GAP_LTE_LEFT_TO_GSM_BIT       (0x2000) /* bit 13*/
#define GERAN_SCHEDULE_DELAY               0 /* used to postpone available gap start time */         
/*****************************************************************************
*                                    ENUMERATIONS
*****************************************************************************/
/*****************************************************************************
* ENUMERATION
*   gl1_ll1_rat_status_enum
*
* DESCRIPTIONS
*   Used to identify the status in GSM RAT.
* NOTE
*   any modification should sync. with ll1_rat_status_enum
*****************************************************************************/
typedef enum
{
  GL1_LL1_RAT_FLIGHT =0,
  GL1_LL1_RAT_STANDBY,
  GL1_LL1_RAT_ACTIVE,
  GL1_LL1_RAT_NUM
} gl1_ll1_rat_status_enum;

/*****************************************************************************
* ENUMERATION
*   gsm_tgmp_enum
*
* DESCRIPTIONS
*   tgmp for gsm .
* Note
*   any modification should sync. with umts_fdd_tgmp_enum
*   GSM_PURPOSE_BSIC_CNF_ONLY, only used for TDS
*****************************************************************************/
typedef enum
{
   GSM_PURPOSE_RSSI = 1,
   GSM_PURPOSE_BSIC_INIT,
   GSM_PURPOSE_BSIC_CNF,
   GSM_PURPOSE_BSIC_CNF_ONLY,
   GSM_PURPOSE_UNDEFINED
} gsm_tgmp_enum;

/*****************************************************************************
*                                    STRUCTURES
*****************************************************************************/
/*****************************************************************************
* STRUCT
*   gsm_time_struct
*
* DESCRIPTIONS
*   GSM system timing base
*
* PARAMETERS
*   fn      - GSM Frame Number (0~2715647), 1 FN = 10000 Ebits.
*   ebit    - GSM Ebit (0~9999)
*****************************************************************************/
typedef struct
{
  kal_int32        fn;
  kal_int32        ebit;
}geran_gsm_time_struct;

/*****************************************************************************
* STRUCT
*   ll1_gsm_standby_gap_struct
*
* DESCRIPTIONS
*   GSM standby gap pattern structure.
*
* PARAMETERS
*   start_time     - start time of the gap session
*   length         - length of the gap session (in ebit)
*   purpose        - Purpose for this gap session
*   purpose_bitmap - Purpose bitmap for this gap session
*****************************************************************************/
typedef struct
{
   geran_gsm_time_struct start_time;
   kal_int32             length;
   gsm_tgmp_enum         purpose;
   kal_int32             purpose_bitmap;
}ll1_gsm_standby_gap_struct;

/*****************************************************************************
* STRUCT
*   ll1_gl1_expand_gap_pattern_struct
*
* DESCRIPTIONS
*   LL1 expands gap pattern for GL1
*
* PARAMETERS
*   session_num          - Indicate how many gap session 
*   session[]            - Standby gap session.
*   measure_tid          - Transition id for RANK tick./Valid when active RAT is in DRX mode./And bit 0 in tick_bitmap is "1"
*   hps_tid              - Transition id for HPS tick./Valid when active RAT is in DRX mode./And bit 1 in tick_bitmap is "1"
*   tick_bitmap          - Bit 0 : Rank search , Bit 1 : Priority search
*   t_identify_abort     - 0xFFFFFFFF means no requirement, Unit : ms, Valid when active rat is in connection mode
*                          abort the bsic identification if it has not successfully decoded it with the period
*   t_reconfirm_abort    - 0xFFFFFFFF means no requirement, Unit : ms, Valid when active rat is in connection mode,  abort the bsic re-comfirmation
*                          If fails to decode bsic after two successive attempts or if has not been able to reconfirm the bsic for a cell with the period 
*   gap_expand_period    - only valid when mode status in active rat is LL1_GL1_EUTRAN_CONNECT
*                        - value = 240/480 ms
*   n_freq_without_m_gsm - only valid when mode status in active rat is LL1_GL1_EUTRAN_CONNECT
*                        - equals to Nfreq,E-UTRA + Nfreq,UTRA.
*   dmo_lte_period       - the period in DMO for lte. GSM uses remained DMO with lte purpose for gsm usage when tds is active rat
*                        - Valid when : purpose_bitmap & MLL1_GAP_LTE_LEFT_TO_GSM_BIT != 0
*   dmo_lte_length       - the length in DMO for lte. GSM uses remained DMO with lte purpose for gsm usage when tds is active rat
*                        - Valid when : purpose_bitmap & MLL1_GAP_LTE_LEFT_TO_GSM_BIT != 0
*****************************************************************************/
typedef struct
{
   kal_uint16                 session_num;
   ll1_gsm_standby_gap_struct session[GSM_SESSION_IN_PERIOD];
   kal_uint8                  measure_tid;
   kal_uint8                  hps_tid;
   kal_uint8                  tick_bitmap;
   kal_uint32                 t_identify_abort;
   kal_uint32                 t_reconfirm_abort;
   kal_uint16                 gap_expand_period;
   kal_uint8                  n_freq_without_m_gsm;
   kal_uint16                 dmo_lte_period;
   kal_uint16                 dmo_lte_length;
}ll1_gl1_expand_gap_pattern_struct;

/*****************************************************************************
* STRUCT
*   gl1_ll1_sync_cnf_struct
*
* DESCRIPTIONS
*   GL1 uses this primitive to confirm LL1 that current GERAN GSM timing 
*   and micro second counter value.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   current_time - sync. time in geran_gsm_time_struct 
*   gsm_ustime   - sync. time in USC  
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   geran_gsm_time_struct current_time;
   kal_uint32            gsm_ustime;
}gl1_ll1_sync_cnf_struct;

/*****************************************************************************
* STRUCT
*   gl1_ll1_rat_status_ind_struct
*
* DESCRIPTIONS
*   This message is sent from GL1 to LL1 for informing current GL1 RAT status. 
*   This message should be sent when GL1 RAT status changed.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   rat_status - RAT status in GL1 
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   gl1_ll1_rat_status_enum rat_status;
}gl1_ll1_rat_status_ind_struct;

/*****************************************************************************
* STRUCT
*   gl1_ll1_mode_status_ind_struct
*
* DESCRIPTIONS
*   This message is sent from GL1 to LL1 for informing that GL1 mode status when GL1 is active RAT. 
*   This message should be sent when GL1 mode status changed.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   gsm_mode_status - current mode in GL1 when GSM is active RAT
*   paging_period   - valid when gsm_mode_status = GL1_LL1_IDLE_MODE
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   ll1_active_rat_mode_status_enum gsm_mode_status;
   kal_uint8                       paging_period;
}gl1_ll1_mode_status_ind_struct;

/*****************************************************************************
* STRUCT
*   ll1_gl1_mode_status_update_ind_struct
*
* DESCRIPTIONS
*   This message is sent to GL1 for informing that mode status of active RAT when GL1 is standby RAT. 
*   This message should be updated for GL1 in standby when any mode status changed in active RAT. 
*   Also when GL1 enters into standby RAT from FLIGHT, LL1 will update current mode state in active RAT to GL1.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   active_rat_mode_status - current mode status in active RAT
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   ll1_active_rat_mode_status_enum active_rat_mode_status;
}ll1_gl1_mode_status_update_ind_struct;

/*****************************************************************************
* STRUCT
*   gl1_ll1_measure_req_struct
*
* DESCRIPTIONS
*   This message is sent from GL1 to inform LL1 that how many GERAN GSM frequencies 
*   are required to be measured and the measurement purposes in GERAN GSM Standby. 
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   meas_purpose_bitmap - bit 0 for measurement, bit 1 for cell search
*   tid                 - tid for lastest meas_req on (should only change when off)
*   tick_bitmap         - bit 0 for ranking search, bit 1 for priority search 
*   carrier_num         - high priority freqencies when HPS ON, measurement frequencies when HPS OFF
*   t_hps               - basic period of high priority search (60s)
*   is_period_reset_bmp - bit 0 for rank period, 1 means to reset
*                       - bit 1 for prio period, 0 means not to reset
*                       - when freq. num is same as before, ll1 will check this flag to reset period or not
*                       - KAL_TRUE : reset hps period, KAL_FALSE : doesnt reset hps period.
*   current_time        - current in GL1
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8             meas_purpose_bitmap;
   kal_uint8             tid;
   kal_uint8             tick_bitmap;
   kal_uint8             carrier_num;
   kal_uint16            t_hps;
   kal_int32             is_period_reset_bmp;
   geran_gsm_time_struct current_time; 
}gl1_ll1_measure_req_struct;

/*****************************************************************************
* STRUCT
*   gl1_ll1_standby_measure_done_ind_struct
*
* DESCRIPTIONS
*   For low power optimization, GL1 informs LL1 which measurement purpose is 
*   measured done in its period. If all measurement purposes are measured done, 
*   LL1 will not tick GL1 anymore in shortest measurement period.
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
}gl1_ll1_standby_measure_done_ind_struct;

/*****************************************************************************
* STRUCT
*   ll1_gl1_gap_service_req_struct
*
* DESCRIPTIONS
*   LL1 uses this primitive to enable (disable) active RAT gap service to get (release) 
*   the free radio frequency period in GERAN GSM.When LL1 disables active RAT gap service, 
*   it means that GERAN GSM could use all RF time already.
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
}ll1_gl1_gap_service_req_struct;

/*****************************************************************************
* STRUCT
*   ll1_gl1_gap_stop_req_struct
*
* DESCRIPTIONS
*   LL1 uses this primitive to stop gap usage in GERAN GSM when GERAN GSM is standby RAT.
*   Stop all purposes in gsm, confirmed with SY Yeh/Albert Lee SE2/CS3
* PARAMETERS
*   LOCAL_PARA_HDR  
*   
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
}ll1_gl1_gap_stop_req_struct;

/*****************************************************************************
* STRUCT
*   gl1_ll1_gap_stop_cnf_struct
*
* DESCRIPTIONS
*   GL1 uses this primitive to confirm LL1_GL1_GAP_STOP_REQ when there is no gap usage in GERAN GSM..
*   Stop all purposes in gsm, confirmed with SY Yeh/Albert Lee SE2/CS3
* PARAMETERS
*   LOCAL_PARA_HDR  
*   current_time  - current time in GL1
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   geran_gsm_time_struct current_time;
}gl1_ll1_gap_stop_cnf_struct;

/*****************************************************************************
* STRUCT
*   gl1_ll1_auto_gap_req_struct
*
* DESCRIPTIONS
*   GL1 sends this message to request LL1 that GL1 wants to use the auto gap  from  (fn, ebits). 
*   GL1 could use this auto gap after getting the successful confirm
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   auto_time  - Start time of auto gap in GL1
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   geran_gsm_time_struct auto_time;
}gl1_ll1_auto_gap_req_struct;

/*****************************************************************************
* STRUCT
*   ll1_gl1_auto_gap_cnf_struct
*
* DESCRIPTIONS
*   LL1 sends this message to confirm GL1 auto gap request. 
*   After receiving this message, GL1 could use required auto gap.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   success       - KAL_TRUE : GL1 could use auto gap to search
*                   KAL_FALSE: GL1 could not use auto gap to search. 
*                              And GL1 should not request auto gap until AUTO_GAP_AVAILABLE_IND
*   valid_period  - The length of autonomous gap allowed by active RAT.
*                   The value is valid when success = KAL_TRUE, 
*                   Unit : ebit
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_bool  success;
   kal_int32 valid_period;
}ll1_gl1_auto_gap_cnf_struct;

/*****************************************************************************
* STRUCT
*   ll1_gl1_auto_gap_ind_struct
*
* DESCRIPTIONS
*   LL1 sends this message to inform GL1 stopping using RF in this auto gap from   (fn, ebits).
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   auto_time  - Start time of auto gap
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   geran_gsm_time_struct auto_time;
}ll1_gl1_auto_gap_ind_struct;

/*****************************************************************************
* STRUCT
*   gl1_ll1_auto_gap_res_struct
*
* DESCRIPTIONS
*   GL1 sends this message to response LL1 that GL1 will/won't use RF from 
*   the start timing of auto gap which is informed by LL1_GL1_auto_GAP_IND.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   success       - KAL_TRUE : GL1 will not use RF from the starting time of LL1_GL1_AUTO_GAP_IND
*                   KAL_FALSE: GL1 may use RF after starting time of LL1_GL1_AUTO_GAP_IND. 
*   valid_period  - The length of  autonomous gap allowed in GL1
*                   The value is valid when GL1 is active rat and success = KAL_TRUE
*                   Unit : ebit 
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_bool  success;
   kal_int32 valid_period;
}gl1_ll1_auto_gap_res_struct;

/*****************************************************************************
* STRUCT
*   ll1_gl1_gap_notify_ind_struct
*
* DESCRIPTIONS
*   LL1 sends this message to inform GL1 that the starting time and length of gap pattern.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   standby_gap   - standby gap pattern
*   tid           - tid for lastest meas_req on
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   ll1_gl1_expand_gap_pattern_struct standby_gap;
   kal_uint8                         tid;        /* Tid for lastest meas_req on, LL1 will expand gap notify ind with this tid*/
}ll1_gl1_gap_notify_ind_struct;

/*****************************************************************************
* STRUCT
*   gl1_ll1_gap_pattern_ind_struct
*
* DESCRIPTIONS
*   GL1 sends this message to inform LL1 that the free RF period in GL1 as gap pattern. 
*   No matter the length is bigger than zero or not, GL1 should send this message 
*   and sets is_drx_tick = KAL_TRUE in one DRX period once.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*   repeat_count  - (1) : GSM in NULL/IDLE /SDCCH mode  (8) : GSM in TCH/PKT mode.
*   start_time    - starting time of the first gap 
*   length        - gap length
*   is_drx_tick   - KAL_TRUE : First tick in this DRX period
*                   KAL_FALSE: Not the first free interval in this DRX period
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8             repeat_count;
   geran_gsm_time_struct start_time;
   kal_int32             length;
   kal_bool              is_drx_tick;
}gl1_ll1_gap_pattern_ind_struct;

/*****************************************************************************
* STRUCT
*   ll1_gl1_sync_req_struct
*   gl1_ll1_active_measure_status_ind_struct
*   gl1_ll1_gap_stop_req_struct
*   ll1_gl1_gap_stop_cnf_struct
*   gl1_ll1_gap_suspend_req_struct
*   ll1_gl1_gap_suspend_cnf_struct
*   ll1_gl1_gap_suspend_req_struct
*   gl1_ll1_gap_suspend_cnf_struct
*   gl1_ll1_gap_resume_ind_struct
*   ll1_gl1_gap_resume_ind_struct
*   gl1_ll1_auto_gap_stop_req_struct
*   ll1_gl1_auto_gap_stop_ind_struct
*   gl1_ll1_auto_gap_stop_res_struct
*   ll1_gl1_auto_gap_stop_cnf_struct
*   gl1_ll1_auto_gap_end_ind_struct
*   ll1_gl1_auto_gap_end_ind_struct
*   gl1_ll1_auto_gap_available_ind_struct
*   ll1_gl1_auto_gap_available_ind_struct
*
* DESCRIPTIONS
*   ll1_gl1_sync_req_struct
*     LL1 will use this primitive to get GL1 current UMTS timing and micro 
*     second counter value in both GL1 in active and standby mode.
*
*   gl1_ll1_active_measure_status_ind_struct (Useless Now)
*     GL1 informs LL1 that how many configured inter-RAT frequencies in GL1 
*     when priority search is turned on.
*
*   gl1_ll1_gap_stop_req_struct
*     GL1 uses this primitive to inform LL1 to stop all gap usage in standby 
*     RAT when GERAN GSM wants to change configuration or other purposes.
*
*   ll1_gl1_gap_stop_cnf_struct
*     LL1 uses this primitive to confirm GL1 that LL1 has already stopped 
*     all gap usages in standby RAT and GL1 could use all RF time.
*
*   gl1_ll1_gap_suspend_req_struct
*     GL1 uses this primitive to temporal suspend gap usage in standby RAT for higher priority
*     task and doesn't need to give new gap configuration in connection mode when resumed.
*
*   ll1_gl1_gap_suspend_cnf_struct
*     LL1 sends this confirm message to GL1 after all standby RAT gap usage are suspended.
*
*   ll1_gl1_gap_suspend_req_struct
*     LL1 sends this message to GL1 to request that GL1 suspends RF usage immediately.
*
*   gl1_ll1_gap_suspend_cnf_struct
*     GL1 sends this message to confirm LL1 that GL1 will not use gap from 
*     now to receiving resume indicator
*
*   gl1_ll1_gap_resume_ind_struct
*     GL1 sends this message to inform LL1 that GL1 has already finished 
*     higher priority task, and standby RAT could use gap normally.
*
*   ll1_gl1_gap_resume_ind_struct
*     LL1 sends this message to GL1 to resume GL1's gap usage. 
*     After receiving this message, GL1 could  use gap pattern normally.
*
*   gl1_ll1_auto_gap_stop_req_struct
*     GL1 sends this message to request LL1 that GL1 wants to 
*     retrieve auto gap for higher priority task.
*
*   ll1_gl1_auto_gap_stop_ind_struct
*     LL1 sends this message to inform GL1 of stopping using RF 
*     during auto gap period.
*
*   gl1_ll1_auto_gap_stop_res_struct
*     GL1 sends this message to response LL1 that GL1 stops 
*     auto gap usage.
*
*   ll1_gl1_auto_gap_stop_cnf_struct
*     LL1 sends this message to confirm that GL1 could use RF now.
*
*   gl1_ll1_auto_gap_end_ind_struct
*     GL1 sends this message to inform LL1 that auto gap usage is finished.
* 
*   ll1_gl1_auto_gap_end_ind_struct
*     LL1 sends this message to inform GL1 that auto gap usage is finished.
*
*   gl1_ll1_auto_gap_available_ind_struct
*     GL1 sends this message to inform LL1 that auto gap is available now. Standby RAT 
*     could request auto gap now. Standby RAT could request auto gap now
*
*   ll1_gl1_auto_gap_available_ind_struct
*     LL1 sends this message to inform GL1 that auto gap 
*     is available now. GL1 could request auto gap now.
*
*   gl1_ll1_auto_gap_unavailable_ind_struct
*     GL1 sends this message to inform LL1 that auto gap is unavailable now. 
*     Standby RAT could not request auto gap now.
*
*   ll1_gl1_auto_gap_unavailable_ind_struct
*     LL1 sends this message to inform GL1 that auto gap is unavailable now. 
*     GL1 could not request auto gap now.
*
* PARAMETERS
*   LOCAL_PARA_HDR  
*****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
}ll1_gl1_sync_req_struct,
 gl1_ll1_active_measure_status_ind_struct,
 gl1_ll1_gap_stop_req_struct,
 ll1_gl1_gap_stop_cnf_struct,
 gl1_ll1_gap_suspend_req_struct,
 ll1_gl1_gap_suspend_cnf_struct,
 ll1_gl1_gap_suspend_req_struct,
 gl1_ll1_gap_suspend_cnf_struct,
 gl1_ll1_gap_resume_ind_struct,
 ll1_gl1_gap_resume_ind_struct,
 gl1_ll1_auto_gap_stop_req_struct,
 ll1_gl1_auto_gap_stop_ind_struct,
 gl1_ll1_auto_gap_stop_res_struct,
 ll1_gl1_auto_gap_stop_cnf_struct,
 gl1_ll1_auto_gap_end_ind_struct,
 ll1_gl1_auto_gap_end_ind_struct,
 gl1_ll1_auto_gap_available_ind_struct,
 ll1_gl1_auto_gap_available_ind_struct,
 gl1_ll1_auto_gap_unavailable_ind_struct,
 ll1_gl1_auto_gap_unavailable_ind_struct;

/*****************************************************************************
* STRUCT
*   mll1_gl1_info_database_struct
*
* DESCRIPTIONS
*   GL1 information structure.
*
* PARAMETERS
*
*****************************************************************************/
typedef struct
{  /* Measure req*/
   kal_uint8                           tick_bmp;            /* use to record tick bitmap*/
   kal_uint8                           rank_tick_tid;       /* tid for rank tick*/
   kal_uint8                           prio_tick_tid;       /* tid for prio tick*/
   kal_uint8                           meas_done_bmp;       /* measurement done ind bitmap*/
   kal_bool                            is_meas_done_useful; /* gsm uses meas_done or not by checking meas_purpose_bmp*/
   kal_uint8                           meas_purpose_bitmap; /* record the measure purpose bitmap*/
   geran_gsm_time_struct               current_time;        /* gsm current time when request gap service*/
   /* Paging period in active RAT */
   kal_uint8                           paging_period;       /* Range : 2~9 Unit : 51 frames*/
   /* Used for Mgsm in LET GP1 */
   kal_uint8                           carrier;             /* in LTE GP1 Mgsm = (ceil(carrier/20))*/
   /* Store gap information*/
   gl1_ll1_gap_pattern_ind_struct      gap_pattern;         /* store gap pattern ilm*/
   /* auto gap para*/
   geran_gsm_time_struct               auto_time;           /* auto gap time*/ 
   /* Mode status*/
   ll1_active_rat_mode_status_enum     mode_status;         /* mode status*/
   /* Gap request from standby rat should do sync in connection*/
   kal_bool                            valid_timing;        /* KAL_TRUE  : with valid timing*/
                                                            /* KAL_FALSE : with invalid timing */
   kal_uint8                           meas_req_tid;        /* Tid for lastest meas_req on, LL1 will expand gap notify ind with this tid*/                                                            
}mll1_gl1_info_database_struct;

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
*   mll1_gl1_auto_gap_available_ind
* DESCRIPTION
*   ll1 sends auto gap available ind to GERAN now
*
* PARAMETERS
*   kal_bool available
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_gl1_auto_gap_available_ind(kal_bool available);

/*****************************************************************************
* FUNCTION
*   mll1_gl1_auto_gap_cnf
* DESCRIPTION
*   ll1 sends auto gap cnf to GERAN now
*
* PARAMETERS
*   success      - success or not
*   valid_period - autonomous gap length which is allowed by active rat
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_gl1_auto_gap_cnf(kal_bool success,kal_int32 valid_period);

/*****************************************************************************
* FUNCTION
*   mll1_gl1_auto_gap_end_ind
* DESCRIPTION
*   ll1 sends auto gap end ind to GERAN now
*
* PARAMETERS
*   none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_gl1_auto_gap_end_ind(void);

/*****************************************************************************
* FUNCTION
*   mll1_gl1_auto_gap_ind
* DESCRIPTION
*   ll1 sends auto gap ind to GERAN now
*
* PARAMETERS
*   gsm_time - auto time
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_gl1_auto_gap_ind(geran_gsm_time_struct gsm_time);

/*****************************************************************************
* FUNCTION
*   mll1_gl1_auto_gap_stop_cnf
* DESCRIPTION
*   ll1 sends auto gap stop cnf to GERAN now
*
* PARAMETERS
*   None
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_gl1_auto_gap_stop_cnf(void);

/*****************************************************************************
* FUNCTION
*   mll1_gl1_auto_gap_stop_ind
* DESCRIPTION
*   ll1 sends auto gap stop ind to GERAN now
*
* PARAMETERS
*   None
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_gl1_auto_gap_stop_ind(void);

/*****************************************************************************
* FUNCTION
*  mll1_gl1_auto_time_minus
* DESCRIPTION
*  add more rf margin for any standby rat which will enter sleep during autonomous serch procedure
*
* PARAMETERS
*   geran_gsm_time_struct*
*   kal_int32              - more RF margin (recovery from sleep).
* RETURNS
*  void
*****************************************************************************/
void mll1_gl1_auto_time_minus(geran_gsm_time_struct* time, kal_int32 ebits);

/*****************************************************************************
* FUNCTION
*   mll1_gl1_expand_gap_pattern_ind
* DESCRIPTION
*   ll1 sends gap pattern ind to GERAN now
*
* PARAMETERS
*   standby_gap - gap pattern for geran
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_gl1_expand_gap_pattern_ind(ll1_gl1_expand_gap_pattern_struct* standby_gap);

/*****************************************************************************
* FUNCTION
*   mll1_gl1_gap_resume_ind
* DESCRIPTION
*  LL1 sends this message to GL1 to resume GL1's gap usage. 
*  After receiving this message, GL1 could  use gap pattern normally.
*
* PARAMETERS
*   none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_gl1_gap_resume_ind(void);

/*****************************************************************************
* FUNCTION
*   mll1_gl1_gap_service_request
* DESCRIPTION
*   ll1 sends gap service req to GERAN now
*
* PARAMETERS
*   enable   - KAL_TRUE  : turn on gap service 
*            - KAL_FALSE : turn off gap service
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_gl1_gap_service_req(kal_bool enable);

/*****************************************************************************
* FUNCTION
*   mll1_gl1_gap_stop_cnf
* DESCRIPTION
*   LL1 uses this primitive to confirm GL1 that LL1 has already stopped 
*   all gap usages in standby RAT and GL1 could use all RF time.
*
* PARAMETERS
*   NONE
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_gl1_gap_stop_cnf(void);

/*****************************************************************************
* FUNCTION
*   mll1_gl1_gap_stop_req
* DESCRIPTION
*   LL1 uses this primitive to stop gap usage in GERAN GSM when GERAN GSM is standby RAT.
*   Stop all purposes in gsm, confirmed with SY Yeh/Albert Lee SE2/CS3
* PARAMETERS
*   None
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_gl1_gap_stop_req(void);
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
#endif /* currently GL1 will not use suspend procedure*/
/*****************************************************************************
* FUNCTION
*   mll1_gl1_gap_suspend_req
* DESCRIPTION
*   LL1 uses this primitive to suspend gap usage in GERAN GSM when GERAN GSM is standby RAT.
*
* PARAMETERS
*   None
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_gl1_gap_suspend_req(void);

/*****************************************************************************
* FUNCTION
*   mll1_gl1_get_current_time
* DESCRIPTION
*   ll1 gets current time
*
* PARAMETERS
*   geran_time - gl1 current time
*
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_gl1_get_current_time(geran_gsm_time_struct* geran_time);

/*****************************************************************************
* FUNCTION
*  mll1_gl1_get_auto_time
* DESCRIPTION
*   return auto time from GL1
*
* PARAMETERS
*   None
* RETURNS
*  geran_gsm_time_struct auto_time
*****************************************************************************/
geran_gsm_time_struct mll1_gl1_get_auto_time(void);

#ifdef __LTE_RAT__
/*****************************************************************************
* FUNCTION
*  mll1_gl1_get_el1_rf_margin
* DESCRIPTION
*  GL1 gets EL1 RF margin in current state
*  margin should be small, so use kal_int32
* PARAMETERS
*  head      - header_margin
*  tail      - tail_margin
* RETURNS
*  none
*****************************************************************************/
void mll1_gl1_get_el1_rf_margin(kal_int32* head,kal_int32* tail);
#endif /*__LTE_RAT__*/

/*****************************************************************************
* FUNCTION
*  mll1_gl1_get_gl1_rf_margin
* DESCRIPTION
*  GL1 gets GL1 RF margin in current state
*
* PARAMETERS
*  head      - header_margin
*  tail      - tail_margin
* RETURNS
*  none
*****************************************************************************/
void mll1_gl1_get_gl1_rf_margin(kal_int32* head,kal_int32* tail);

/*****************************************************************************
* FUNCTION
*   mll1_gl1_get_timing_status
* DESCRIPTION
*
* PARAMETERS
* RETURNS
*   kal_bool  - valid_timing  KAL_TRUE  : with valid timing
*                             KAL_FALSE : with invalid timing
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool mll1_gl1_get_timing_status(void);


/*****************************************************************************
* FUNCTION
*  mll1_gl1_get_m_gsm
* DESCRIPTION
*   return M_GSM in GL1
*
* PARAMETERS
*   None
* RETURNS
*  kal_uint8 m_gsm
*****************************************************************************/
kal_uint8 mll1_gl1_get_m_gsm(void);

/*****************************************************************************
* FUNCTION
*  mll1_gl1_get_mode_status
* DESCRIPTION
*   return mode status from GL1
*
* PARAMETERS
*   None
* RETURNS
*  ll1_active_rat_mode_status_enum mode_status
*****************************************************************************/
ll1_active_rat_mode_status_enum mll1_gl1_get_mode_status(void);

/*****************************************************************************
* FUNCTION
*  mll1_gl1_get_tick_count
* DESCRIPTION
*   GL1 tick number
*
* PARAMETERS
*   is_prio_search - KAL_TRUE  : ll1_main wants to get prio. tick
*                    KAL_FALSE : ll1_main wants to get rank tick
*   hps            - 25 or 70 (uint : second)
*   
* RETURNS
*  kal_uint32 count;
*****************************************************************************/
kal_uint32 mll1_gl1_get_tick_count(kal_bool is_prio_search, kal_uint16 hps);

#ifdef __UMTS_RAT__
#ifdef __UMTS_FDD_MODE__
/*****************************************************************************
* FUNCTION
*  mll1_gl1_get_ul1_rf_margin
* DESCRIPTION
*  GL1 gets UL1 RF margin in current state
*
* PARAMETERS
*  head      - header_margin
*  tail      - tail_margin
* RETURNS
*  none
*****************************************************************************/
void mll1_gl1_get_ul1_rf_margin(kal_int32* head,kal_int32* tail);
#endif /*__UMTS_FDD_MODE__*/

#ifdef __UMTS_TDD128_MODE__
/*****************************************************************************
* FUNCTION
*  mll1_gl1_get_tl1_rf_margin
* DESCRIPTION
*  GL1 gets TL1 RF margin in current state
*
* PARAMETERS
*  head      - header_margin
*  tail      - tail_margin
* RETURNS
*  none
*****************************************************************************/
void mll1_gl1_get_tl1_rf_margin(kal_int32* head,kal_int32* tail);

/*****************************************************************************
* FUNCTION
*  mll1_gl1_is_fb_sb_search_on
* DESCRIPTION
*   Check if gl1 turns on fb/sb search
*
* PARAMETERS
*   
* RETURNS
*  kal_bool - KAL_FALSE : turns off fb/sb search
*             KAL_TRUE  : turns on fb/sb search
*****************************************************************************/
kal_bool mll1_gl1_is_fb_sb_search_on(void);

#endif /*__UMTS_TDD128_MODE__*/
#endif /*__UMTS_RAT__*/
/*****************************************************************************
* FUNCTION
*  mll1_gl1_is_lower_pwr_on
* DESCRIPTION
*   Check if gl1 is low pwr on
*
* PARAMETERS
*   
* RETURNS
*  kal_bool - KAL_FALSE : measurement is not finished and need gap in this period 
*             KAL_TRUE  : measurement is finished and doesnt need gap in this period
*****************************************************************************/
kal_bool mll1_gl1_is_lower_pwr_on(void);

/*****************************************************************************
* FUNCTION
*   mll1_gl1_mode_status_update_ind
* DESCRIPTION
*   This message is sent to GL1 for informing that mode status of active RAT when GL1 is standby RAT. 
*   This message should be updated for GL1 in standby when any mode status changed in active RAT.
*
* PARAMETERS
*   status - mode status in active RAT 
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_gl1_mode_status_update_ind(ll1_active_rat_mode_status_enum status);

/*****************************************************************************
* FUNCTION
*   mll1_gl1_set_timing_status
* DESCRIPTION
*
* PARAMETERS
*   flag     - set valid_timing = flag
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_gl1_set_timing_status(kal_bool flag);


/*****************************************************************************
* FUNCTION
*   mll1_gl1_sync_time_req
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
void mll1_gl1_sync_time_req(void);

/*****************************************************************************
* FUNCTION
*  mll1_gl1_time_add
* DESCRIPTION
*  This function is used to add ebits to time , for rf margin, should smaller than kal_int32
*
* PARAMETERS
*   time          - basic time
*   ebits         - add ebits
* RETURNS
*  none
*****************************************************************************/
void mll1_gl1_time_add( geran_gsm_time_struct* time, kal_int32 ebits );

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   mll1_gsm_handler()
*
* DESCRIPTION
*   Function to handle the primitive from GL1.
*
* PARAMETERS
*   current_ilm - primitive from GL1.
*
* RETURN
*   None
*****************************************************************************/
void mll1_gsm_handler(void *ptr_ilm);

/*****************************************************************************
* FUNCTION
*   mll1_tick_gl1_gap_expansion
* DESCRIPTION
*   tick gl1 to expand gap when sync done
*
* PARAMETERS
*   none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_tick_gl1_gap_expansion(void);

/*****************************************************************************
* FUNCTION
*   mll1_gl1_info_init
* DESCRIPTION
*   Initialize gl1 internal global variable
*
* PARAMETERS
*   none
* RETURNS
*   none
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mll1_gl1_info_init(void);

/*****************************************************************************
* FUNCTION
*   mll1_gl1_gap_pattern_timing_checking
* DESCRIPTION
*   check if the pending gap is out of date or not
*
* PARAMETERS
*   gsm_time   - gl1 timing correspond to some standby rat's timing indicated in measure request
* RETURNS
*   TRUE   - the pending gap has not been out of date
*   FALSE   - the pending gap has been out of date
* GLOBALS AFFECTED
*   none
*****************************************************************************/
kal_bool mll1_gl1_gap_pattern_timing_checking(geran_gsm_time_struct gsm_time);

#endif /*_MLL1_GSM_H*/

