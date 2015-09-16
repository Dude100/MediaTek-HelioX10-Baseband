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
 * ll1_tl1.h
 *
 * Project:
 * --------
 *   TDD_Software
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _LL1_TL1_STRUCT_H
#define _LL1_TL1_STRUCT_H

/*****************************************************************************
*                                    DEFINITIONS
*****************************************************************************/ 
#define IMMEDIATELY  (-1)

#define TCH_REPEAT_CNT        (24) // 26 TDMA frame = 24 TDD subframe

#define SUBSFN_ROUND 8192 
#define ECHIP_ROUND    6400*8
#define QBIT_ROUND      5000
#define EBIT_ROUND (QBIT_ROUND*2)
#define FN_ROUND 2715648

#define TDD128_SUBSFN2ECHIP 6400*8
#define GSM_FN2QBIT         5000

#define MAX_DOFF_IN_SUBSFN          14

/* 1Sub-SFN=(13/12)FN =(6400*8)echip, 1FN=5000qbit */
/*
#define GSM_FN2SUBSFN                    (12.0/13.0)
#define GSM_FN2ECHIP                       (GSM_FN2SUBSFN * TDD128_SUBSFN2ECHIP)
#define GSM_QBIT2ECHIP                 (GSM_FN2ECHIP/GSM_FN2QBIT)
#define TDD128_SUBSFN2FN              (13.0/12.0)
#define TDD128_SUBSFN2QBIT           (TDD128_SUBSFN2FN*GSM_FN2QBIT)
#define TDD128_ECHIP2QBIT              (TDD128_SUBSFN2QBIT/TDD128_SUBSFN2ECHIP)
#define TDD128_ECHIP2EBIT              (TDD128_ECHIP2QBIT*2)
*/
/* 'double' for timing transformation calculation. */
#define GSM_FN2SUBSFN_NUMERATOR             (double)(12.0)
#define GSM_FN2SUBSFN_DENOMINATOR         (double)(13.0)
#define GSM_FN2SUBSFN_DOUBLE                    (double)(GSM_FN2SUBSFN_NUMERATOR/GSM_FN2SUBSFN_DENOMINATOR)

#define GSM_FN2ECHIP_NUMERATOR                (double)(GSM_FN2SUBSFN_NUMERATOR * TDD128_SUBSFN2ECHIP)
#define GSM_FN2ECHIP_DENOMINATOR            (double)(GSM_FN2SUBSFN_DENOMINATOR)
#define GSM_FN2ECHIP_DOUBLE                       (double)(GSM_FN2ECHIP_NUMERATOR/GSM_FN2ECHIP_DENOMINATOR)

#define GSM_QBIT2ECHIP_NUMERATOR             (double)(GSM_FN2ECHIP_NUMERATOR)
#define GSM_QBIT2ECHIP_DENOMINATOR         (double)(GSM_FN2ECHIP_DENOMINATOR*GSM_FN2QBIT)
#define GSM_QBIT2ECHIP_DOUBLE                    (double)(GSM_QBIT2ECHIP_NUMERATOR/GSM_QBIT2ECHIP_DENOMINATOR)

#define TDD128_SUBSFN2FN_NUMERATOR        (double)(13.0)
#define TDD128_SUBSFN2FN_DENOMINATOR    (double)(12.0)
#define TDD128_SUBSFN2FN_DOUBLE               (double)(TDD128_SUBSFN2FN_NUMERATOR/TDD128_SUBSFN2FN_DENOMINATOR)

#define TDD128_SUBSFN2QBIT_NUMERATOR     (double)(TDD128_SUBSFN2FN_NUMERATOR*GSM_FN2QBIT)
#define TDD128_SUBSFN2QBIT_DENOMINATOR (double)(TDD128_SUBSFN2FN_DENOMINATOR)
#define TDD128_SUBSFN2QBIT_DOUBLE            (double)(TDD128_SUBSFN2QBIT_NUMERATOR/TDD128_SUBSFN2QBIT_DENOMINATOR)

#define TDD128_ECHIP2QBIT_NUMERATOR        (double)(TDD128_SUBSFN2QBIT_NUMERATOR)
#define TDD128_ECHIP2QBIT_DENOMINATOR    (double)(TDD128_SUBSFN2QBIT_DENOMINATOR*TDD128_SUBSFN2ECHIP)
#define TDD128_ECHIP2QBIT_DOUBLE               (double)(TDD128_ECHIP2QBIT_NUMERATOR/TDD128_ECHIP2QBIT_DENOMINATOR)

#define TDD128_ECHIP2EBIT_NUMERATOR         (double)(TDD128_SUBSFN2QBIT_NUMERATOR*2)
#define TDD128_ECHIP2EBIT_DENOMINATOR     (double)(TDD128_SUBSFN2QBIT_DENOMINATOR*TDD128_SUBSFN2ECHIP) 
#define TDD128_ECHIP2EBIT_DOUBLE                (double)(TDD128_ECHIP2EBIT_NUMERATOR/TDD128_ECHIP2EBIT_DENOMINATOR)

#define SLOT2CHIP                  (864)
#define DwPTS2CHIP               (96)
#define GP2CHIP                     (96)
#define UpPTS2CHIP               (160) 
#define FROM_UpPTS_ECHIP   (SLOT2CHIP+DwPTS2CHIP+GP2CHIP)*8

#define GAPS_IN_SESSION    3
#define EXPAND_NUM             (96)// for 480ms
#define EXPAND_NUM_PLUS_FOUR (100)// for 480ms + subframe boundary(for FB should be four)

#define FB_SEARCH_SUBFRAME 12

/* GAP control for HSPA/DCHFACH/PCH state:
 * STOP_ALL_GAP - disable, ASSIGN_GAP - enable. 
 */
#define STOP_ALL_GAP           (0)
#define ASSIGN_GAP             (1)

/* Indicate that whether timing sync is needed before
 * sending the GAP configuration to 2G L1 in HSPA/DCH/FACH state.
 */
#define LL1_WAIT_SYNC_HSPA    (0x03) 
#define LL1_WAIT_SYNC_DCH    (0x02)
#define LL1_WAIT_SYNC_FACH  (0x01)

#define LL1_FACH_MODE (1)
#define LL1_DCH_MODE  (2)
#define LL1_HSPA_MODE  (3)

/*****************************************************************************
*                                    ENUMERATIONS
*****************************************************************************/

/*****************************************************************************
* ENUMERATION
*   ll1_service_type_enum
*
* DESCRIPTIONS
*   Identify the gap purpose that TL1 requests when 2G is active.
*   (If LL1_CELL_SEARCH is chosen, 2G L1 still schedules DRX
*   gaps for TL1 to search cells after 3G cell measurement is done during the 5s period.)
*****************************************************************************/
typedef enum
{
  LL1_CELL_MEAS_ONLY,
  LL1_CELL_SEARCH
}ll1_service_type_enum;

/*****************************************************************************
* ENUMERATION
*   tl1a_gsm_service_type_enum
*
* DESCRIPTIONS
*   Identify the gap purpose that L1 requests when 3G is active.
*   (If TL1A_GSM_PM_ONLY is chosen, 3G L1 could not schedules DRX
*   gaps for L1 after 2G power measurement is done during the Tmeas. period.)
*****************************************************************************/
typedef enum
{
  TL1A_GSM_PM_ONLY,
  TL1A_GSM_ALL
}tl1a_gsm_service_type_enum;

/*****************************************************************************
* ENUMERATION
*   ll1_umts_state_enum
*
* DESCRIPTIONS
*   The enum type of UMTS state
*****************************************************************************/
typedef enum
{
   UMTS_STATE_STANDBY,
   UMTS_STATE_FLIGHT,
   UMTS_STATE_NULL,
   UMTS_STATE_PCH,
   UMTS_STATE_FACH,
   UMTS_STATE_DCH,
   UMTS_STATE_HSPA
} ll1_umts_state_enum;

/*****************************************************************************
* ENUMERATION
*   tl1a_gsm_state_enum
*
* DESCRIPTIONS
*   When the surrounding mode of GSM RAT is changed, 2G L1 would inform LL1 
*   the change and LL1 would send MPHD_GSM_SC_MODE_IND to TL1. 
* 
*   GSM_DM_NONE  - l1a_surround_enter_null_mode
*                  l1a_surround_enter_standby_mode                   
*                  (This value is used in the initialize stage only. In other 
*                   cases, if 2G L1 passes GSM_DM_NONE to LL1, LL1 would store it
*                   locally without informing TL1, or TL1 may have assertions.)
*   GSM_DM_IDLE  - l1a_surround_enter_idle_mode
*                  l1a_surround_enter_scan_mode
*                  l1a_surround_enter_access_mode
*                  l1a_surround_set_ba_list
*                  l1a_surround_enter_ccch_packet_idle_mode
*                  l1a_surround_enter_pccch_packet_idle_mode
*                  l1a_surround_enter_packet_access_mode
*   GSM_DM_SDCCH - l1a_surround_enter_resume_dch (L1SCModeDediSDCCh)
*                  l1a_surround_enter_dedicated_mode (L1SCModeDediSDCCh)
*   GSM_DM_DCH   - l1a_surround_enter_resume_dch (L1SCModeDediTCh)
*                  l1a_surround_enter_dedicated_mode (L1SCModeDediTCh)
*   GSM_DM_PKTTX - l1a_surround_enter_packet_transfer_mode
*                  l1a_surround_change_mode_two_phase
*****************************************************************************/
typedef enum
{
   GSM_DM_NONE, 
   GSM_DM_IDLE,
   GSM_DM_SDCCH,
   GSM_DM_DCH,
   GSM_DM_PKTTX,
   GSM_DM_FLIGHT_MODE	
}tl1a_gsm_state_enum;

/*****************************************************************************
* ENUMERATION
*   gap_table_enum
*
* DESCRIPTIONS
*   Gap type in the subframe 
*   
*   INIT_STATE          -- Initial state 
*   GAP                 -- NW not allocate any resource
*   FMO                 -- FACH Measurement Occasion
*   FB_SEARCH           -- This subframe is used for FB search
*   FB_SEARCH_UL        -- Only DCH UL subframe and for FB search
*   FB_SEARCH_DL        -- Only DCH DL subframe and for FB search
*   ISCP_MEAS           -- TL1 used for ISCP measurement
*   FACH                -- FACH channel
*   DCH_DL_UL           -- DCH UL + DL channel 
*   DCH_DL              -- DCH DL channel
*   DCH_UL              -- DCH UL channel
*   MEAS_FOR_2G         -- Reserved for 2G measment in HSPA
*   FB_IN_GAP           -- GAP for FB search
*   FB_IN_FMO           -- FMO for FB search
*   FB_IN_DROP          -- DROP subframe in 3G for FB search
*   RESERVED            -- Reserved subframe after FB search window for aligning max gap pattern
*   RESERVED_DL         -- RESERVED subframe in DCH_DL
*   RESERVED_UL         -- RESERVED subframe in DCH_UL
*   GAP_RESERVED        -- RESERVED subframe in GAP 
*   FMO_RESERVED        -- RESERVED subframe in FMO 
*   MEAS_RESERVED       -- RESERVED subframe in MEAS_FOR_2G
*****************************************************************************/
typedef enum
{
   INIT_STATE,/*LL1 internal use*/ 
   GAP,
   FMO,// = GAP   
   FB_SEARCH,
   FB_SEARCH_UL,
   FB_SEARCH_DL,
   ISCP_MEAS,
   FACH,
   DCH_DL_UL,/*8*/
   DCH_DL,
   DCH_UL,
   MEAS_FOR_2G,
   FB_IN_GAP,
   FB_IN_FMO,// = FB_IN_GAP
   FB_IN_DROP,/*14*/
   RESERVED,
   RESERVED_DL,
   RESERVED_UL,   
   GAP_RESERVED,
   FMO_RESERVED,//= GAP_RESERVED
   MEAS_RESERVED,
   GAP_RULE_ENUM_NUM
}gap_table_enum;
/*****************************************************************************
*                                    STRUCTURES
*****************************************************************************/

/*****************************************************************************
* STRUCT
*   umts_time_struct
*
* DESCRIPTIONS
*   UMTS timing base, LL1 internal use.
*
* PARAMETERS
*   sub_sfn     - UMTS SUB_SFN (0~8191), 1 SUB_SFN = 6400 chips.
*   echip          - UMTS chip (0~51199), 1 chip = 8 echips
*****************************************************************************/
typedef struct
{
  kal_int32 sub_sfn;
  kal_int32 echip;        
} umts_time_struct;

/*****************************************************************************
* STRUCT
*   gsm_time_struct
*
* DESCRIPTIONS
*   GSM timing base, LL1 internal use.
*
* PARAMETERS
*   qbit    - GSM Qbit (0~4999)
*   fn      - GSM Frame Number (0~2715647), 1 FN = 5000 Qbits.
*****************************************************************************/
typedef struct
{
  kal_int32        fn;
  kal_int32        qbit;
}gsm_time_struct;

/*****************************************************************************
* STRUCT
*   drx_idle_pattern_struct
*
* DESCRIPTIONS
*   This structure represents the gap pattern in the drx. cycle.
*
* PARAMETERS
*  start_sub_sfn       -Starting sub-SFN of gap, 0~ 8191 subframes
*  start_echip            -Starting chip of gap, 0~ 51199 echips
*  width_sub_frame  - GAP width in sub frame level, 0~ 8191 subframes
*  width_echip     - GAP width in chip level, 0~ 51199 echips
*****************************************************************************/
typedef struct
{
   kal_int32   start_sub_sfn;  
   kal_int32   start_echip;
   kal_int32   width_sub_frame;
   kal_int32   width_echip;
}drx_idle_pattern_struct;

/*****************************************************************************
* STRUCT
*   umts_pch_gap_pattern_struct
*
* DESCRIPTIONS
*   This structure represents the IDLE/PCH gap pattern parameters passed from TL1.
*
* PARAMETERS
*   gap_control          - 0: STOP_ALL_GAP, 1: ASSIGN_GAP.
*   gap                      - the gap pattern in the drx. cycle.
*   pm_tick                - KAL_TRUE :  The first DRX in the Tmeas period,
*                              - KAL_FALSE : The others in the Tmeas period
*   pm_tid                 - Transaction id for the Tmeas period
*   drx_len                - DRX cycle length (25.123 Table 4.1A) in ms.
*   Tmeas_drx_num   - TmeasureGSM (number of DRX cycles)
*****************************************************************************/
typedef struct
{
  kal_uint8                 gap_control;
  drx_idle_pattern_struct   gap;
  kal_bool                  pm_tick;
  kal_uint8                 pm_tid;
  kal_uint16                drx_len;
  kal_uint8                 Tmeas_drx_num;
} umts_pch_gap_pattern_struct;


/*****************************************************************************
* STRUCT
*   subframe_allocation_struct
*
* DESCRIPTIONS
*   Sub-Frame allocation structure of TDD
*
* PARAMETERS
*   repetition_period            -subframe allocation repetition period, Resolution  : sub-frame, 0 ~ 8191
*   repetition_length            -subframe allocation repetition length, Resolution  : sub-frame, 0 ~ 8191
*   offset                            -subframe allocation offset, Resolution  : sub-frame, 0 ~ 8191
*   activation_time_sub_sfn  -subframe allocation activation time, Resolution  : sub-frame, 0 ~ 8191
*****************************************************************************/
typedef struct
{
   kal_uint16 repetition_period;
   kal_uint16 repetition_length;
   kal_uint16 offset;
   kal_uint16 activation_time_sub_sfn;
} subframe_allocation_struct;

/*****************************************************************************
* STRUCT
*   umts_fach_gap_pattern_struct
*
* DESCRIPTIONS
*  This structure represents the FACH gap pattern parameters passed from TL1
*
* PARAMETERS
*   wait_timing_sync      - Indicate that whether the patterns need to be applied after
*                                     the inter-RAT timing sync procedure is done.
*   gap_control              - 0: STOP_ALL_GAP, 1: ASSIGN_GAP.
*   fach                         - sub-frame allocation of fach pattern
*   slot_bitmap              - bitmap of slot used by 3G in one sub-frame;
*                                    Bit 0~bit 6 --> TS0~TS6
*                                    Bit 7 --> DwPTS
*                                    Bit 8 --> GP
*                                    Bit 9 --> UpPTS
*                                    1 : means the slot is reserved for 3G
*                                    0 : means the slot is not reserved for 3G
*   is_fmo_valid             -True : sub-frame allocation of fmo is valid
*                                    False : sub-frame allocation of fmo is invalid
*   fmo                         - sub-frame allocation of fmo pattern
*   is_iscp_valid             - True : sub-frame allocation of iscp is valid
*                                     False : sub-frame allocation of iscp is invalid
*   iscp                          - sub-frame allocation of iscp pattern
*   is_fb_valid                - True : sub-frame allocation of fb is valid
*                                     False : sub-frame allocation of fb is invalid
*   fb                             - sub-frame allocation of fb search pattern         
*****************************************************************************/
typedef struct
{
  kal_uint8                          wait_timing_sync;
  kal_uint8                          gap_control;
  subframe_allocation_struct         fach;
  kal_uint16                         slot_bitmap;  
  kal_bool                           is_fmo_valid;
  subframe_allocation_struct         fmo;
  kal_bool                           is_iscp_valid;
  subframe_allocation_struct         iscp;
  kal_bool                           is_fb_valid;
  subframe_allocation_struct         fb;
} umts_fach_gap_pattern_struct;

/*****************************************************************************
* STRUCT
*   umts_dch_gap_pattern_struct
*
* DESCRIPTIONS
*  This structure represents the DCH gap pattern parameters passed from TL1
*
* PARAMETERS
*   wait_timing_sync      - Indicate that whether the patterns need to be applied after
*                                     the inter-RAT timing sync procedure is done.
*   gap_control              - 0: STOP_ALL_GAP, 1: ASSIGN_GAP.
*   is_dl_valid                - True : sub-frame allocation of dch_dl is valid
*                                     False : sub-frame allocation of dch_dl is invalid
*   dch_dl                          - sub-frame allocation of dch_dl pattern
*   dl_slot_bitmap              - bitmap of slot used by 3G in one sub-frame for dl;
*                                    Bit 0~bit 6 --> TS0~TS6
*                                    Bit 7 --> DwPTS
*                                    Bit 8 --> GP
*                                    Bit 9 --> UpPTS
*                                    1 : means the slot is reserved for 3G
*                                    0 : means the slot is not reserved for 3G
*   is_ul_valid                - True : sub-frame allocation of dch_ul is valid
*                                     False : sub-frame allocation of dch_ul is invalid
*   dch_ul                          - sub-frame allocation of dch_ul pattern
*   ul_slot_bitmap              - bitmap of slot used by 3G in one sub-frame for ul;
*                                    Bit 0~bit 6 --> TS0~TS6
*                                    Bit 7 --> DwPTS
*                                    Bit 8 --> GP
*                                    Bit 9 --> UpPTS
*                                    1 : means the slot is reserved for 3G
*                                    0 : means the slot is not reserved for 3G
*   is_iscp_valid             - True : sub-frame allocation of iscp is valid
*                                     False : sub-frame allocation of iscp is invalid
*   iscp                          - sub-frame allocation of iscp pattern
*   is_fb_valid                - True : sub-frame allocation of fb is valid
*                                     False : sub-frame allocation of fb is invalid
*   fb                             - sub-frame allocation of fb search pattern
*   last_tx_slot                - The last tx slot UE used before the second switch point in one subframe.
*   doff                           - to align cfn in sub_frame (0~14);
*****************************************************************************/
typedef struct
{
  kal_uint8                          wait_timing_sync;
  kal_uint8                          gap_control;  
  kal_bool                           is_dl_valid;  
  subframe_allocation_struct         dch_dl;
  kal_uint16                         dl_slot_bitmap;    
  kal_bool                           is_ul_valid;  
  subframe_allocation_struct         dch_ul;
  kal_uint16                         ul_slot_bitmap;  
  kal_bool                           is_iscp_valid;
  subframe_allocation_struct         iscp;
  kal_bool                           is_fb_valid;
  subframe_allocation_struct         fb;
  kal_uint8                          last_tx_slot;
  kal_uint8                           doff;
} umts_dch_gap_pattern_struct;


/*****************************************************************************
* STRUCT
*   dpa_idle_pattern_struct
*
* DESCRIPTIONS
*   The start slot in the first drop sub-frame & end slot in the last drop sub-frame in DPA  for TDD
*
* PARAMETERS
*   start_slot         -start slot in the first  drop sub-frame
*   end_slot          - end slot in the last drop sub-frame                    
*****************************************************************************/
typedef struct
{
  kal_uint8 start_slot;
  kal_uint8 end_slot;
}dpa_idle_pattern_struct;

/*****************************************************************************
* STRUCT
*   umts_hspa_gap_pattern_struct
*
* DESCRIPTIONS
*  This structure represents the HSPA gap pattern parameters passed from TL1
*
* PARAMETERS
*   wait_timing_sync      - Indicate that whether the patterns need to be applied after
*                                     the inter-RAT timing sync procedure is done.
*   gap_control              - 0: STOP_ALL_GAP, 1: ASSIGN_GAP.
*   is_meas_for_2g_valid- True : sub-frame allocation of meas_for_2g is valid
*                                     False : sub-frame allocation of meas_for_2g is invalid 
*   meas_for_2g            - sub-frame allocation of meas_for_2g pattern
*   slot_bitmap              - bitmap of slot used by 3G in one sub-frame;
*                                    Bit 0~bit 6 --> TS0~TS6
*                                    Bit 7 --> DwPTS
*                                    Bit 8 --> GP
*                                    Bit 9 --> UpPTS
*                                    1 : means the slot is reserved for 3G
*                                    0 : means the slot is not reserved for 3G
*   is_fb_valid                - True : sub-frame allocation of fb is valid
*                                     False : sub-frame allocation of fb is invalid
*   fb                             - sub-frame allocation of fb search pattern
*   dpa                           - The start slot in the first  drop sub-frame & end slot in the last drop sub-frame in DPA 
*   last_tx_slot                - The last tx slot UE used before the second switch point in one subframe
*****************************************************************************/
typedef struct
{
  kal_uint8                       wait_timing_sync;
  kal_uint8                       gap_control;  
  kal_bool                        is_meas_for_2g_valid;
  subframe_allocation_struct      meas_for_2g;
  kal_uint16                      slot_bitmap;  
  kal_bool                        is_fb_valid;
  subframe_allocation_struct      fb;
  dpa_idle_pattern_struct         dpa;
  kal_uint8                       last_tx_slot;
} umts_hspa_gap_pattern_struct;

/*****************************************************************************
* STRUCT
*   gap_pattern_struct
*
* DESCRIPTIONS
*   This structure represents the gap pattern from GSM
*
* PARAMETERS
*   start_sub_frame   - Start sub frame of gap
*   start_echip            - Start echip of gap
*   echip_width           - GAP width in echip level 
*****************************************************************************/
typedef struct
{
  kal_int32 	start_sub_frame;
  kal_int32 	start_echip;
  kal_int32 	echip_width;
}gap_pattern_struct;
/*****************************************************************************
* STRUCT
*   gsm_gap_param_struct
*
* DESCRIPTIONS
*    In GSM active, GSM L1 use this structure to set the GSM gap to UMTS
*
* PARAMETERS
*   gap_control         - 0: STOP_ALL_GAP, It means that GSM gap in TL1 is not valid, 
*                                                            so 3G should immediately stop all GAP patterns.
*                                1: ASSIGN_GAP. 
*   num_gap            - indicated the num of gap in the gap[];
*   gap[8]                - In current design, the maximum number of gap is eight in GSM dedicated mode.  
*   is_five_sec_tick   - Is the first DRX in the five second period 
*   tid                      - Transaction id for the five second period
*****************************************************************************/
typedef struct
{
  kal_uint8               gap_control;
  kal_uint8               num_gap;
  gap_pattern_struct      gap[8];
  kal_bool                is_five_sec_tick;
  kal_uint8               tid;
} gsm_gap_param_struct;

typedef struct _gsm_time_struct
{
   kal_int32 frame; /* @field Frame number */
   kal_int32 ebits; /* @field Eighth bits */
} gsm_time;
/*****************************************************************************
* STRUCT
*   gap_struct
*
* DESCRIPTIONS
*    UMTS gap struct 
*
* PARAMETERS
*    start_time           -- gap's start time
*    len                  -- gap's length
*    is_before_tx         -- indicate if the gap is before 3G UL slot (for leave more gap margin in l1c/l1d)
*****************************************************************************/
typedef struct _gap_struct
{
   gsm_time            start_time;
   kal_int32       len;   /* in unit of ebit */
   kal_bool            is_before_tx;
} gap_struct;
/*****************************************************************************
* STRUCT
*   gap_session_struct
*
* DESCRIPTIONS
*    UMTS gap session 
*
* PARAMETERS
*    gap_num              -- number of gap patterns in the gap session
*    gap[]                -- gap struct
*    is_fb_search         -- indicate if the gap session is used for fb search 
*****************************************************************************/
typedef struct _gap_session_struct
{
   kal_uint8      gap_num;
   gap_struct gap[GAPS_IN_SESSION];
   kal_bool       is_fb_search;
}gap_session_struct;
/*****************************************************************************
* STRUCT
*   expand_umts_gap_pattern_struct
*
* DESCRIPTIONS
*    UMTS gap pattern parameters expanded to be set to 2G L1.
*
* PARAMETERS
*    session_num          -- number of gap sessions in the expansion period
*    session              -- gap_session_struct
*    mode                 -- indicate 3G current mode
*****************************************************************************/
typedef struct
{
   kal_uint8 session_num;
   gap_session_struct* session;
   kal_uint8 mode;
} expand_umts_gap_pattern_struct;
/*****************************************************************************
* STRUCT
*   ll1_inter_rat_timing_sync_struct
*
* DESCRIPTIONS
*   The inter-RAT timing sync informtaion maintained by LL1.
*
* PARAMETERS
*   umts_time_valid - Indicate wheter the UMTS timing sync report is got from TL1.
*   gsm_time_valid  - Indicate wheter the GSM timing sync report is got from 2G L1.
*   umts_sync_time  - The UMTS sync time reported by 3G L1. (SUBSFN, eChip)
*   gsm_sync_time   - The GSM sync time reported by 2G L1. (FN, Qbit)
*****************************************************************************/
typedef struct
{
   kal_bool         umts_time_valid;
   kal_bool         gsm_time_valid;
	umts_time_struct umts_sync_time;
   gsm_time_struct  gsm_sync_time; 
} ll1_inter_rat_timing_sync_struct;


/*****************************************************************************
* STRUCT
*   mphd_umts_mode_ind_struct
*
* DESCRIPTIONS
*   This structure is for the primitive MPHD_UMTS_MODE_IND. When the 
*   mode of UMTS RAT is changed, TL1 would inform LL1
*   the change and LL1 would send MPHD_UMTS_MODE_IND to 2G L1.
*   
* PARAMETERS
*   ref_count
*   msg_len
*   umts_mode - 
*****************************************************************************/
typedef struct
{
  kal_uint8                      ref_count;
  kal_uint16                     msg_len;
  ll1_umts_state_enum            umts_mode;
} mphd_umts_mode_ind_struct;


/*****************************************************************************
* STRUCT
*   mphd_gsm_pm_done_ind_struct
*
* DESCRIPTIONS
* Send the PM done information to Tl1 to stop expand gap to GSM for saving power
*   
* PARAMETERS
*   ref_count
*   msg_len
*   tid - 
*****************************************************************************/
typedef struct
{
  kal_uint8                            ref_count;
  kal_uint16                           msg_len;
  kal_uint8                            tid;
} mphd_gsm_pm_done_ind_struct;

/*****************************************************************************
* STRUCT
*   ll1_fach_gap_DB_struct
*
* DESCRIPTIONS
*   The FACH GAP parameters recorded by LL1
*   current_state;                                                                                      
*     -     0: LL1_GAP_DEACTIVATE                                                                             
*     -     1: LL1_GAP_ACTIVATE                                                                               
*   gap_control;                                                                                        
*     -	0: STOP_ALL_GAP,                                                                                      
*     -	1: ASSIGN_GAP.                                                                                        
*   is_first_fach; used to check fach is started or not.                                                
*   fach; sub-frame allocation of fach.                                                                 
*   slot_bitmap - bitmap of slot used by 3G in one sub-frame;                    
*     Bit 0~bit 6 --> TS0~TS6             
*     Bit 7 --> DwPTS                                                                                         
*     Bit 8 --> GP                                                                                            
*     Bit 9 --> UpPTS                                                                                         
*     1 : means the slot is reserved for 3G                                                                   
*     0 : means the slot is not reserved for 3G                                                               
*   sub_frame_gap_num;number of idle interval in one subframe.                                          
*   start_echip[GAPS_IN_SESSION]; echips of start point for each idle interval                          
*   echip_length[GAPS_IN_SESSION]; length of idle interval for each idle interval.                      
*   align_gap; 0,1,2 (max idle interval num)                                                            
*   is_fmo_valid;                                                                                       
*	-True : sub-frame allocation of fmo is valid                                                            
*     -False : sub-frame allocation of fmo is invalid                                                         
*   is_first_fmo; used to check fmo is started or not.                                                  
*   fmo; sub-frame allocation of fmo.                                                                   
*   is_iscp_valid;                                                                                      
*     - True : sub-frame allocation of iscp is valid   
*     -False : sub-frame allocation of iscp is invalid  
*   is_first_iscp; used to check iscp is started or not                                                 
*   iscp; sub-frame allocation of iscp                                                                  
*   is_fb_valid;                                                                                        
*     - True : sub-frame allocation of fb is valid                                                            
*     - False : sub-frame allocation of fb is invalid                                                         
*   is_first_fb; used to check fb is started or not                                                     
*   fb; sub-frame allocation of fb                  
* PARAMETERS
*****************************************************************************/
typedef struct
{
  kal_uint8                          current_state;
  kal_uint8                          gap_control;
  kal_bool                           is_first_fach;
  subframe_allocation_struct         fach;
  kal_uint16                         slot_bitmap;  
  kal_uint8                          sub_frame_gap_num;
  kal_uint16                         start_echip[GAPS_IN_SESSION];                           
  kal_uint16                         echip_length[GAPS_IN_SESSION];
  kal_uint8                          align_gap; // 0,1,2
  kal_bool                           is_fmo_valid;
  kal_bool                           is_first_fmo;
  subframe_allocation_struct         fmo;
  kal_bool                           is_iscp_valid;
  kal_bool                           is_first_iscp;
  subframe_allocation_struct         iscp;
  kal_bool                           is_fb_valid;
  kal_bool                           is_first_fb;
  subframe_allocation_struct         fb;
} ll1_fach_gap_DB_struct;
/*****************************************************************************
* STRUCT
*   ll1_dch_gap_DB_struct
*
* DESCRIPTIONS
*   The DCH GAP parameters recorded by LL1
*
* PARAMETERS
*****************************************************************************/
typedef struct
{
  kal_uint8   current_state;
  kal_uint8                          gap_control;
  kal_bool                           is_first_dch_dl;
  kal_bool                           is_dl_valid;  
  subframe_allocation_struct         dch_dl;
  kal_uint16                         dl_slot_bitmap;
  kal_bool                           is_first_dch_ul;  
  kal_bool                           is_ul_valid;  
  subframe_allocation_struct         dch_ul;
  kal_uint16                         ul_slot_bitmap;  
  kal_uint16                         slot_bitmap;/*total slot_bitmap*/ 	
  kal_uint8                          sub_frame_gap_num;
  kal_uint16                         start_echip[GAPS_IN_SESSION];                           
  kal_uint16                         echip_length[GAPS_IN_SESSION];
  kal_uint8                          ul_sub_frame_gap_num;
  kal_uint16                         ul_start_echip[GAPS_IN_SESSION];                           
  kal_uint16                         ul_echip_length[GAPS_IN_SESSION];
  kal_uint8                          dl_sub_frame_gap_num;
  kal_uint16                         dl_start_echip[GAPS_IN_SESSION];                           
  kal_uint16                         dl_echip_length[GAPS_IN_SESSION];  
  kal_uint8                          align_gap; // 0,1,2
  kal_uint8                          ul_align_gap; // 0,1,2
  kal_uint8                          dl_align_gap; // 0,1,2
  kal_bool                           is_iscp_valid;
  kal_bool                           is_first_iscp;
  subframe_allocation_struct         iscp;
  kal_bool                           is_fb_valid;
  kal_bool                           is_first_fb;
  subframe_allocation_struct         fb;
  kal_uint16                         last_tx_position;
  kal_uint8                          doff;
} ll1_dch_gap_DB_struct;
/*****************************************************************************
* STRUCT
*   ll1_hspa_gap_DB_struct
*
* DESCRIPTIONS
*   The DCH GAP parameters recorded by LL1
*
* PARAMETERS
*****************************************************************************/
typedef struct
{
  kal_uint8                          current_state;
  kal_uint8                          gap_control;
  kal_bool                           is_first_meas;
  kal_bool                           is_meas_for_2g_valid;  
  subframe_allocation_struct         meas_for_2g;
  kal_uint16                         slot_bitmap;  
  kal_uint8                          sub_frame_gap_num;
  kal_uint16                         start_echip[GAPS_IN_SESSION];                           
  kal_uint16                         echip_length[GAPS_IN_SESSION];  
  kal_uint8                          align_gap; // 0,1,2  
  kal_bool                           is_fb_valid;
  kal_bool                           is_first_fb;
  subframe_allocation_struct         fb;
  dpa_idle_pattern_struct            dpa;
  kal_uint16                         last_tx_position;
} ll1_hspa_gap_DB_struct;
/*****************************************************************************
*                                 GLOBAL VARIABLES
*****************************************************************************/

/* Used to identify if the gap stop report from 2G L1 results from
 * the UMTS_GAP_STOP_REQ requested by 3G L1 before. */
extern kal_bool ll1_gap_stop_req;

/* Used to store the temporary timing sync information during sync procedure. */
extern kal_uint8 ll1_wait_timing_sync;

/* The next expand period starting time */
extern umts_time_struct ll1_next_gap_st;

/* The next expand period end time */
extern umts_time_struct ll1_next_gap_end_time;

/* The expand time period in chips */
extern kal_int32 ll1_expand_time_length_chip;

/* The l1 gsm state */
extern tl1a_gsm_state_enum ll1_tl1_gsm_state;

/* The expand gap table */
extern gap_table_enum ll1_gap_table[EXPAND_NUM_PLUS_FOUR];
/*****************************************************************************
*                                GLOBAL FUNCTIONS
*****************************************************************************/

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   ll1_main
*
* DESCRIPTION
*   For TL1 to trasfer the primitive sent by 2G L1 to LL1 since LL1 is not a task.
*
* PARAMETERS
*   current_ilm - primitive passed to LL1.
*
* RETURN
*   None
*****************************************************************************/
extern void ll1_main(void *ptr_ilm);

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   ll1_start_gsm_gap_service
*
* DESCRIPTION
*   For TL1 to trigger the 2G L1 to start the gap service machine.
*
* PARAMETERS
*   gap_service_type - The gap purpose TL1 requests.
*
* RETURN
*   None
*****************************************************************************/
extern void ll1_start_gsm_gap_service(ll1_service_type_enum gap_service_type);

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   ll1_stop_gsm_gap_service
*
* DESCRIPTION
*   For TL1 to trigger the 2G L1 to stop the gap service machine.
*
* PARAMETERS
*   None
*
* RETURN
*   None
*****************************************************************************/
extern void ll1_stop_gsm_gap_service(void);

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   tl1_start_umts_gap_service
*
* DESCRIPTION
*   When 3G is active, 2G L1 asks for the UMTS gap service.
*
* PARAMETERS
*   gap_service_type - The gap purpose L1 requests.
*
* RETURN
*   None
*****************************************************************************/
extern void tl1_start_umts_gap_service(tl1a_gsm_service_type_enum gap_service_type);

#ifdef L1A_SIM_WO_TL1
typedef struct
{
  kal_uint8                  ref_count;
  kal_uint16                 msg_len;
  tl1a_gsm_service_type_enum gap_service_type;
} tl1_receive_start_umts_gap_service_ind_struct;
#endif /*L1A_SIM_WO_TL1*/

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   tl1_stop_umts_gap_service
*
* DESCRIPTION
*   When 3G is active and 2G L1 need no gap service anymore, it would request
*   3G L1 to stop the UMTS gap service.
*
* PARAMETERS
*   None
*
* RETURN
*   None
*****************************************************************************/
extern void tl1_stop_umts_gap_service(void);

#ifdef L1A_SIM_WO_TL1
typedef struct
{
  kal_uint8          ref_count;
  kal_uint16         msg_len;
} tl1_receive_stop_umts_gap_service_ind_struct;
#endif /*L1A_SIM_WO_TL1*/

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   ll1_l1a_set_gap_func_idle
*
* DESCRIPTION
*   In UMTS IDLE/PCH state, the TL1 calls this to set the UMTS gap parameters 
*   to LL1 for GSM measurement .
*
* PARAMETERS
*   tl1_gap_pattern - pch gap pattern
*
* RETURN
*   None
*****************************************************************************/
extern void ll1_l1a_set_gap_func_idle(umts_pch_gap_pattern_struct* tl1_gap_pattern);

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   ll1_l1a_set_gap_func_fach
*
* DESCRIPTION
*   In UMTS FACH mode, the TL1 calls this to set the UMTS gap to LL1 for GSM 
*   measurement.
*
* PARAMETERS
*   tl1_gap_pattern - fach gap pattern
*
* RETURN
*   None
*****************************************************************************/
extern void ll1_l1a_set_gap_func_fach(umts_fach_gap_pattern_struct* tl1_gap_pattern);

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   ll1_l1a_set_gap_func_dch
*
* DESCRIPTION
*   In UMTS DCH mode, the TL1 calls this to set the UMTS gap to LL1 for GSM 
*   measurement. 
*
* PARAMETERS
*   tl1_gap_config - dch gap config
*
* RETURN
*   None
*****************************************************************************/
extern void ll1_l1a_set_gap_func_dch(umts_dch_gap_pattern_struct* tl1_gap_config);

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   ll1_l1a_set_gap_func_hspa
*
* DESCRIPTION
*   In UMTS HSPA mode, the TL1 calls this to set the UMTS gap to LL1 for GSM 
*   measurement. 
*
* PARAMETERS
*   tl1_gap_config - hspa gap config
*
* RETURN
*   None
*****************************************************************************/
extern void ll1_l1a_set_gap_func_hspa(umts_hspa_gap_pattern_struct* tl1_gap_config);

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   tl1_set_gap_func
*
* DESCRIPTION
*   When 2G is active and 2G L1 calls this function to set the GSM gap to 
*   UMTS L1.
*
* PARAMETERS
*   None
*
* RETURN
*   None
*****************************************************************************/
extern void tl1_set_gap_func(gsm_gap_param_struct *ptr);

#ifdef L1A_SIM_WO_TL1
typedef struct
{
  kal_uint8            ref_count;
  kal_uint16           msg_len;
  gsm_gap_param_struct gsm_gap_param;
} tl1_receive_set_gap_func_ind_struct;
#endif /*L1A_SIM_WO_TL1*/

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   ll1_l1a_stop_gap_confirm
*
* DESCRIPTION
*   In GSM active, the L1A asks UMTS L1 to stop the GAP usage, the TL1 calls
*   this to confirm the request.
*
* PARAMETERS
*   success - Should always be KAL_TRUE. Otherwise, it would cause 2G L1A assert.
*
* RETURN
*   None
*****************************************************************************/
extern void ll1_l1a_stop_gap_confirm(kal_bool success);

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   tl1_stop_gap_confirm
*
* DESCRIPTION
*   When 3G is active, the LL1 calls this to confirm the stop request that 3G
*   asked before once it gets the confirmation from 2G L1 and ascertains that 
*   2G L1 has stopped the UMTS gap usage.
*   
* PARAMETERS
*   None
*
* RETURN
*   None
*****************************************************************************/
extern void tl1_stop_gap_confirm(void);

#ifdef L1A_SIM_WO_TL1
typedef struct
{
  kal_uint8          ref_count;
  kal_uint16         msg_len;
} tl1_receive_stop_gap_cnf_struct;
#endif /*L1A_SIM_WO_TL1*/

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   tl1_dual_mode_gsm_sync_start_func
*
* DESCRIPTION
*   When 2G is active, 2G L1 calls this to request the timing sync procedure.
*   And this would trigger TL1 to send the CPHY_IRAT_SYNC_REQ to UMTS L1C(FDD).
*
* PARAMETERS
*   None
*
* RETURN
*   None
*****************************************************************************/
extern void tl1_dual_mode_gsm_sync_start_func(void);

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   ll1_dual_mode_umts_sync_start_func
*
* DESCRIPTION
*   When 3G is active, TL1 use this function to ask 2G L1 to generate the 
*   inter-RAT timing synchronization signal.
*
* PARAMETERS
*   None
*
* RETURN
*   None
*****************************************************************************/
extern void ll1_dual_mode_umts_sync_start_func(void);

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   ll1_dual_mode_sync_ready_func
*
* DESCRIPTION
*   When 2G is active and requests the timing sync procedure, 3G L1 would call
*   this function to notify that it is ready to perform the timing sync. And so,
*   2G L1 would starting to generate the timing sync hardware signal.
*
* PARAMETERS
*   None
*
* RETURN
*   None
*****************************************************************************/
extern void ll1_dual_mode_sync_ready_func(void);

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   ll1_dual_mode_sync_rpt_func
*
* DESCRIPTION
*   Once the inter-RAT timing sync procedure is started, when getting the 
*   timing sync report from TL1, the LL1 would check if 2G timing sync report 
*   is received or not. If timing sync reports are got from both RATs, the 
*   LL1 would start calculating the time difference.
*
* PARAMETERS
*   None
*
* RETURN
*   None
*****************************************************************************/
extern void ll1_dual_mode_sync_rpt_func(kal_bool success,kal_uint16 sub_sfn, kal_uint32 echip);

/*****************************************************************************
* FUNCTION
*  tl1_dual_mode_sync_update_func
*
* DESCRIPTION
*   At the end of the inter-RAT timing sync procedure, this function is called
*   to update the GSM sync time to TL1.
*
* PARAMETERS
*   success - timing sync is successful or not
* RETURNS
*   None
*****************************************************************************/
extern void tl1_dual_mode_sync_update_func(kal_bool success);

#ifdef L1A_SIM_WO_TL1
typedef struct
{
  kal_uint8          ref_count;
  kal_uint16         msg_len;
  kal_bool           success;
} tl1_receive_irat_umts_sync_update_ind_struct;
#endif /*L1A_SIM_WO_TL1*/
/*****************************************************************************
* FUNCTION
*   ll1_inform_umts_mode
*
* DESCRIPTION
*   Used to inform LL1 the change of the UMTS mode. 
*   And LL1 would send MPHD_UMTS_MODE_IND to 2G L1.
*
* PARAMETERS
*   new_state - 
*
* RETURN
*   None
*****************************************************************************/
extern void ll1_inform_umts_mode ( ll1_umts_state_enum new_state );

/*****************************************************************************
* FUNCTION
*  ll1_get_gsm_sc_mode
* DESCRIPTION
*   For TL1 to query the surrounding cell mode of GSM L1
* PARAMETERS
*  a  IN
* RETURNS
*  none
* GLOBALS AFFECTED
*  none
*****************************************************************************/
extern kal_uint32 ll1_get_gsm_sc_mode( void );

/*****************************************************************************
* FUNCTION
*  tl1_dm_set_gsm_mode
* DESCRIPTION
*   The function is for L1 to inform TL1 that GSM SC current mode
* PARAMETERS
*  a  IN
* RETURNS
*  none
* GLOBALS AFFECTED
*  none
*****************************************************************************/
extern void tl1_dm_set_gsm_mode(tl1a_gsm_state_enum gsm_state);

#ifdef L1A_SIM_WO_TL1
typedef struct
{
  kal_uint8           ref_count;
  kal_uint16          msg_len;
  tl1a_gsm_state_enum gsm_state;
} tl1_receive_dm_set_gsm_mode_ind_struct;
#endif /*L1A_SIM_WO_TL1*/

/*****************************************************************************
* FUNCTION
*  tl1_receive_gsm_gap_available_ind
* DESCRIPTION
*   The function is to inform UMTS that GSM is active. And GSM gaps are available.
* PARAMETERS
*  a  IN service type
* RETURNS
*  none
* GLOBALS AFFECTED
*  none
*****************************************************************************/
extern void tl1_receive_gsm_gap_available_ind(void);

/*****************************************************************************
* FUNCTION
*  tl1_receive_gsm_gap_unavailable_ind
* DESCRIPTION
*   The function is to inform UMTS that GSM is inactive. And GSM gaps are unavailable.
* PARAMETERS
*  a  IN service type
* RETURNS
*  none
* GLOBALS AFFECTED
*  none
*****************************************************************************/
extern void tl1_receive_gsm_gap_unavailable_ind(void);

#ifdef L1A_SIM_WO_TL1
typedef struct
{
  kal_uint8          ref_count;
  kal_uint16         msg_len;
} tl1_receive_gsm_gap_unavailable_ind_struct;
#endif /*L1A_SIM_WO_TL1*/
/*****************************************************************************
* FUNCTION
*  ll1_send_umts_gap_available_ind
* DESCRIPTION
*   The function is to inform GSM that UMTS is active. And UMTS gaps are available.
* PARAMETERS
*  a  IN service type
* RETURNS
*  none
* GLOBALS AFFECTED
*  none
*****************************************************************************/
extern void ll1_send_umts_gap_available_ind(void);

#ifdef L1A_SIM_WO_TL1
typedef struct
{
  kal_uint8          ref_count;
  kal_uint16         msg_len;
} tl1_receive_gsm_gap_available_ind_struct;
#endif /*L1A_SIM_WO_TL1*/
/*****************************************************************************
* FUNCTION
*  ll1_send_umts_gap_unavailable_ind
* DESCRIPTION
*   The function is to inform GSM that UMTS is inactive. And UMTS gaps are unavailable.
* PARAMETERS
*  a  IN service type
* RETURNS
*  none
* GLOBALS AFFECTED
*  none
*****************************************************************************/
extern void ll1_send_umts_gap_unavailable_ind(void);

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   ll1_l1a_set_fach_gap_lock
*
* DESCRIPTION
*   In UMTS_STATE_FACH mode, the TL1 calls this to lock/unlock FACH gap.
*   This information is passed to 2G L1 transparantly by sending primitives.
*
* PARAMETERS
*   lock      - lock=true: 	To lock FACH gap 
*               lock=false: To unlock FACH gap
*
* RETURN
*   None
*****************************************************************************/
extern void ll1_l1a_set_fach_gap_lock(kal_bool lock);

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   tl1_fach_gap_lock_cnf
*
* DESCRIPTION
*   In UMTS FACH mode, after TL1 lock FACH gap.
*   GSM will report "ReportFMOStop" when GSM stopping using RF, 
*   then TL1 calls this function to confirm lock FACH gap in 2G to inform UMTS that TL1 could use the RF
*
* PARAMETERS
*   lock      - lock=true: 	To lock FACH gap 
*               lock=false: To unlock FACH gap
*
* RETURN
*   None
*****************************************************************************/
extern void tl1_fach_gap_lock_cnf(void);

#ifdef L1A_SIM_WO_TL1
typedef struct
{
  kal_uint8          ref_count;
  kal_uint16         msg_len;
} tl1_receive_fach_gap_lock_cnf_struct;
#endif /*L1A_SIM_WO_TL1*/

/*****************************************************************************
* FUNCTION
*  ll1_umts_cell_meas_done_ind
* DESCRIPTION
*   For DM low power optimize in 2G active,
*   TL1A can notify L1C to stop sending ReportGAPPattern during this 5s period 
* PARAMETERS
*  kal_uint8 tid:
*  For L1C to know this umts_cell_meas_done_ind is mapped to which ReportGAPPattern sent before
* RETURNS
*  none
* GLOBALS AFFECTED
*  none
*****************************************************************************/
extern void ll1_umts_cell_meas_done_ind( kal_uint8 tid );

/*****************************************************************************
* CALL FUNCTION PROTOTYPE
*   tl1_receive_gsm_pm_done_ind
*
* DESCRIPTION
*   When 3G is active and 2G L1 finishes the PM, it would inform 
*   3G L1 to stop the UMTS gap service in this Tmeas period.
*
* PARAMETERS
*   pm_tid: id of the Tmeas period
*
* RETURN
*   None
*****************************************************************************/
extern void tl1_receive_gsm_pm_done_ind( kal_uint8 pm_tid );

#ifdef L1A_SIM_WO_TL1
typedef struct
{
  kal_uint8          ref_count;
  kal_uint16         msg_len;
  kal_uint8          pm_tid;
} tl1_receive_gsm_pm_done_ind_struct;
#endif /*L1A_SIM_WO_TL1*/

/*****************************************************************************
* FUNCTION
*   ll1_init_main
*
* DESCRIPTION
*   Init the LL1 module. Including the timing sync, gap service .
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*****************************************************************************/
extern void ll1_init_main(void);

/*****************************************************************************
* FUNCTION
*   ll1_reset
*
* DESCRIPTION
*   Reset the LL1 module. (The timing sync parameters would not be reset.)
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*****************************************************************************/
extern void ll1_reset(void);

/*****************************************************************************
* FUNCTION
*  time_transfer_3G_to_2G
*
* DESCRIPTION
*   Transform UMTS time (SUBSFN:Chip) to GSM time (FN:Qbit).
*
* PARAMETERS
*   OUT     gsm_time  - The gsm time tranformed from the umts time.
*   IN      umts_time - The umts time to be transformed.
*
* RETURNS
*    None
*****************************************************************************/
extern gsm_time_struct time_transfer_3G_to_2G(umts_time_struct umts_time);

/*****************************************************************************
* FUNCTION
*  time_transfer_2G_to_3G
*
* DESCRIPTION
*   Transform GSM time (FN:Qbit) to UMTS time (SUBSFN:Chip).
*
* PARAMETERS
*   OUT     umts_time  - The umts time tranformed from the gsm time.
*   IN      gsm_time   - The gsm time to be transformed.
*
* RETURNS
*    None
*****************************************************************************/
extern umts_time_struct time_transfer_2G_to_3G(gsm_time_struct gsm_time);

/*****************************************************************************
* FUNCTION
*  ll1_expand_dpa_pattern
*
* DESCRIPTION
*   When 2G L1 asks 3G to provide UMTS gap service in DPA, this function 
*   would be called by 2G L1 to get gaps expanded by LL1. And whenever the 
*   480 ms expand tick timer started at 2G L1 expires, this function would 
*   also be periodically called. LL1 would expand gaps for a 480 ms period 
*   each time this function is called if the gap active time is reached.
*
* PARAMETERS
*   None
*
* RETURNS
*    None
*****************************************************************************/
extern void ll1_expand_hspa_pattern(void);

/*****************************************************************************
* FUNCTION
*  ll1_expand_dch_pattern
*
* DESCRIPTION
*   When 2G L1 asks 3G to provide UMTS gap service in DCH, this function 
*   would be called by 2G L1 to get gaps expanded by LL1. And whenever the 
*   480 ms expand tick timer started at 2G L1 expires, this function would 
*   also be periodically called. LL1 would expand gaps for a 480 ms period 
*   each time this function is called if the gap active time is reached.
*
* PARAMETERS
*   None
*
* RETURNS
*    None
*****************************************************************************/
extern void ll1_expand_dch_pattern(void);

/*****************************************************************************
* FUNCTION
*  ll1_expand_fach_pattern
*
* DESCRIPTION
*   When 2G L1 asks 3G to provide UMTS gap service in FACH, this function 
*   would be called by 2G L1 to get gaps expanded by LL1. And whenever the 
*   480 ms expand tick timer started at 2G L1 expires, this function would 
*   also be periodically called. LL1 would expand gaps for a 480 ms period 
*   each time this function is called if the gap active time is reached.
*
* PARAMETERS
*   None
*
* RETURNS
*    None
*****************************************************************************/
extern void ll1_expand_fach_pattern(void);

/*****************************************************************************
* FUNCTION
*  ll1_start_set_gap_func_dch
* 
* DESCRIPTION
*   In UMTS active, the function is used for setting the gap patterns in DCH 
*   mode after inter-RAT timing sync procedure is finished if the gaps provided
*   by TL1 is requested to be applied after the inter-RAT timing sync.
* 
* PARAMETERS
*   None
* 
* RETURNS
*   None
*****************************************************************************/
extern void ll1_start_set_gap_func_dch(void);

/*****************************************************************************
* FUNCTION
*  ll1_start_set_gap_func_fach
* 
* DESCRIPTION
*   In UMTS active, the function is used for setting the gap patterns in FACH 
*   mode after inter-RAT timing sync procedure is finished if the gaps provided
*   by TL1 is requested to be applied after the inter-RAT timing sync.
* 
* PARAMETERS
*   None
* 
* RETURNS
*   None
*****************************************************************************/
extern void ll1_start_set_gap_func_fach(void);

/*****************************************************************************
* FUNCTION
*  ll1_start_set_gap_func_hspa
* 
* DESCRIPTION
*   In UMTS active, the function is used for setting the gap patterns in HSPA 
*   mode after inter-RAT timing sync procedure is finished if the gaps provided
*   by TL1 is requested to be applied after the inter-RAT timing sync.
* 
* PARAMETERS
*   None
* 
* RETURNS
*   None
*****************************************************************************/
extern void ll1_start_set_gap_func_hspa(void);

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
#endif
/*****************************************************************************
* FUNCTION
*  slot_bitmap_to_sub_frame_gap_num
* DESCRIPTION
*   return the number of gap in one subframe
*
* PARAMETERS
*  none
* RETURNS
*  kal_uint8 num_len
* GLOBALS AFFECTED
*  none
*****************************************************************************/
extern kal_uint8 slot_bitmap_to_sub_frame_gap_num( kal_uint16 slot_bitmap ,kal_uint16* start_chip,kal_uint16* echip_length,kal_uint8* align_gap);
/*****************************************************************************
* FUNCTION
*  before_dest_time
* 
* DESCRIPTION
*   This function is used to compare the src_time with dest_time. Note that 
*   the src_time can only be the activation time time or stop time of the gap
*   patterns here and the dest_time should be the start or end point of the 
*   expand period. Thus, the src_time here can only be ahead of dest_time by 
*   48 UMTS frames and can never be later than the dest_time for (256+48) UMTS
*   frames.
* 
* PARAMETERS
*   None
* 
* RETURNS
*   TRUE : The src_time is before the dest_time which means the src_time is
*          within the next 480 ms expand period.
*   FALSE: Else.
*****************************************************************************/
extern kal_bool before_dest_time(kal_int32 src_time, kal_int32 dest_time);

extern kal_bool is_before_dest_time(kal_int32 src,kal_int32 dest);

extern void gap_expand_func(kal_int32 start_sub_sfn, kal_int32 start_echip, gap_session_struct * gap_session, kal_uint32 echip_length, kal_bool before_tx);

extern gap_session_struct* next_gap_session(kal_bool is_for_fb,kal_uint8 sub_sfn_num, kal_uint8* sub_frame_index, gap_session_struct* temp_gap_session, expand_umts_gap_pattern_struct* expand_umts_gap_pattern);

extern void ll1_allocate_all_gap_table(gap_table_enum type);

extern kal_bool is_before_tx_slot(kal_uint16 start_position,kal_uint16 last_tx_position);

extern gap_session_struct* ll1_expand_pattern_by_pattern(kal_uint8* sub_frame_index, gap_session_struct* temp_gap_session, expand_umts_gap_pattern_struct* expand_umts_gap_pattern);

/*****************************************************************************
* FUNCTION
*   init_for_timing_sync
*
* DESCRIPTION
*   Init the timing sync parameters. Used only when the system is start-up.
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*****************************************************************************/
extern void init_for_timing_sync(void);

/*****************************************************************************
* FUNCTION
*   init_for_gap_expand_fach
*
* DESCRIPTION
*   Init the FACH gap database.
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*****************************************************************************/
extern void init_for_gap_expand_fach(void);

/*****************************************************************************
* FUNCTION
*   init_for_gap_expand_dch
*
* DESCRIPTION
*   Init the DCH gap database.
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*****************************************************************************/
extern void init_for_gap_expand_dch(void);

/*****************************************************************************
* FUNCTION
*   init_for_gap_expand_hspa
*
* DESCRIPTION
*   Init the HSPA gap database.
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*****************************************************************************/
extern void init_for_gap_expand_hspa(void);

/*****************************************************************************
* FUNCTION
*  ll1_check_full_reserved_in_dch
* DESCRIPTION
*  when all slots are allocated for DCH but still need 2G measurement, use this function to check 
*  
* PARAMETERS
* RETURNS
*   kal_bool 
* GLOBALS AFFECTED
*  none
*****************************************************************************/
extern kal_bool ll1_check_full_reserved_in_dch(void);
#endif

