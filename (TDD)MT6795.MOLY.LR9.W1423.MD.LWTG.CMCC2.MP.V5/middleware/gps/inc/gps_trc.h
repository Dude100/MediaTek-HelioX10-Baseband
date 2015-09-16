/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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

/*******************************************************************************
* Filename:
* ---------
*  gps_trc.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  GPS trace goes here
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*******************************************************************************/
#ifndef __GPS_TRC_H__
#define __GPS_TRC_H__
#if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)

#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_trace.h"

#define GPS_TRACE(args) kal_trace args

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "gps_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_GPS)

   /***************TRC MSG FOR GPS BEGIN ********************/
   /* --------------------------------------------------------------- */
   /* -----------------------   COMMON USE ID    -------------------- */
   /* --------------------------------------------------------------- */

    /* --------------------------------------------------------------- */
    /* ----------------------- MODULE NAME:GPS_UART------------------- */
    /* --------------------------------------------------------------- */
    //TRC_MSG(GPS_UART_TRC_DRV_READ_SIZE, "[GPS_UART]DRV read from driver size=%d")
    TRC_MSG(GPS_UART_TRC_BUFFER_WRITE_SIZE, "[GPS_UART]add to ring handle=%d size=%d")
    TRC_MSG(GPS_UART_TRC_DROP_ONE_SENTENCE, "[GPS_UART]NMEA buffer full drop one sentence[MOD_ID=%d]")
    TRC_MSG(GPS_UART_TRC_BUFFER_READ_SIZE, "[GPS_UART]read from ring mod=%d size=%d r_p=%d w_p=%d")
    TRC_MSG(GPS_UART_TRC_NEED_INDICATION, "[GPS_UART]Address %d need indication=%d")
    TRC_MSG(GPS_UART_TRC_OPEN_REQ_HDLR, "[GPS_UART]gps_uart_open_req_hdlr")
    TRC_MSG(GPS_UART_TRC_OPEN_REQ_HDLR_SET_EVENT, "[GPS_UART]gps_uart_open_req_hdlr done and set event")
    TRC_MSG(GPS_UART_TRC_OPEN_ERROR, "[GPS_UART]open uart error")
    TRC_MSG(GPS_UART_TRC_OPEN_ADD_TO_SLOT, "[GPS_UART] gps_uart_open_add_to_slot mode=%d mod_id=%d")
    TRC_MSG(GPS_UART_TRC_OPEN_ADD_TO_SLOT_FIND_MOD, "[GPS_UART] find a module open the port")
    TRC_MSG(GPS_UART_TRC_OPEN_ADD_TO_SLOT_FIND_SLOT, "[GPS_UART] find a empty slot to add request slot=%d")
    TRC_MSG(GPS_UART_TRC_OPEN_ADD_TO_SLOT_NO_SLOT, "[GPS_UART]Issue no slot to add request")
    TRC_MSG(GPS_UART_TRC_OPEN_FIND_PORT, "[GPS_UART]uart_open_req_hdlr find the port =%d")
    TRC_MSG(GPS_UART_TRC_OPEN_NEW_PORT, "[GPS_UART]uart_open_req_hdlr need open new port num=%d")
    TRC_MSG(GPS_UART_TRC_OPEN_PORT_STATE, "[GPS_UART]uart_open_req_hdlr port state port=%d")
    TRC_MSG(GPS_UART_TRC_OPEN_GPS_PORT, "[GPS_UART]uart_open_req_hdlr port=GPS port call GPS_init: [GPS_W]$PMTK997,1*29")
    TRC_MSG(GPS_UART_TRC_OPEN_REQUEST_PORT, "[GPS_UART]uart_open_req_hdlr open normal port=%d")
    TRC_MSG(GPS_UART_TRC_OPEN_PORT_FINAL_STATE, "[GPS_UART]uart_open_req_hdlr final state=%d")
    TRC_MSG(GPS_UART_TRC_OPEN_RAW_OK, "[GPS_UART]uart_open_req_hdlr open RAW mode OK")
    TRC_MSG(GPS_UART_TRC_OPEN_LCT_OK, "[GPS_UART]uart_open_req_hdlr open location mode OK")
    TRC_MSG(GPS_UART_TRC_OPEN_FIND_MOD_CMP, "[GPS_UART]add_to_slot mod_index=%d mod=%d request mod=%d")
    TRC_MSG(GPS_UART_TRC_OPEN_FIND_EMP_MOD, "[GPS_UART]add_to_slot find empty mod index=%d mod_id=%d")
    TRC_MSG(GPS_UART_TRC_MODE_ERROR, "[GPS_UART] last switch mode [%d], current gps mode [%d]!!")
    TRC_MSG(GPS_UART_TRC_MODE_STATUS, "[GPS_UART] last switch mode [%d], org gps mode [%d], curr gps mode [%d], prefer gps mode [%d], query gps mode [%d]")
    TRC_MSG(GPS_UART_TRC_POS_REPORT_BECOME_FIXED, "[GPS_UAR]Reported POS becomes FIXED")
    TRC_MSG(GPS_UART_TRC_MODE_READY, "[GPS_UART] gps_uart_is_mode_ready = %d")
    TRC_MSG(GPS_UART_TRC_GPS_START_FINISH, "[GPS_UART] GPS start finish = %d, another AGPS session ongoing [%d], pos_meas cnf fail sent [%d]")
    TRC_MSG(GPS_UART_TRC_NEXT_JOB, "[GPS_UART] next_job=%d started=%d")

    TRC_MSG(GPS_UART_TRC_CLOSE_HDLR, "[GPS_UART]uart_close_req_hdlr request close port=%d mode=%d")
    TRC_MSG(GPS_UART_TRC_CLOSE_FIND_RAW, "[GPS_UART]uart_close_req_hdlr find RAW&close it")
    TRC_MSG(GPS_UART_TRC_CLOSE_FIND_LCT, "[GPS_UART]uart_close_req_hdlr find LCT&close it")
    TRC_MSG(GPS_UART_TRC_CLOSE_GPS_POWER_DOWN, "[GPS_UART]uart_close_req_hdlr close internal gps port: [GPS_W]$PMTK997,0*28")
    TRC_MSG(GPS_UART_TRC_CLOSE_UART_PORT, "[GPS_UART]uart_close_req_hdlr close uart port num=%d")
    TRC_MSG(GPS_UART_TRC_CLOSE_EXIT, "[GPS_UART]uart_close_req_hdlr close function exit")
    TRC_MSG(GPS_UART_TRC_CLOSE_SWITCH_MOD_ID, "[GPS_UART]close_switch_req request_mod_id=%d ilm_mod=%d i=%d")
    TRC_MSG(GPS_UART_TRC_CLOSE_SWITCH_REQ_COUNT, "[GPS_UART]GPS CLOSE request_mod_id=%d request_count=%d i=%d")
    TRC_MSG(GPS_UART_TRC_CLOSE_SWITCH_ABORT_REQ_MOD, "[GPS_UART]GPS CLOSE abort for request_mod_id=%d cout=%d i =%d")
    TRC_MSG(GPS_UART_TRC_CLOSE_SWITCH_ABORT_MOD_ID, "GPS CLOSE abort for mod_id=%d i =%d")
    TRC_MSG(GPS_UART_TRC_CLOSE_PORT_ALREADY_CLOSED, "[GPS_UART]port %d already closed")
    TRC_MSG(GPS_UART_TRC_ALL_PORT_CLOSED, "[GPS_UART] All GPS ports are closed!!")

    //TRC_MSG(GPS_UART_TRC_INTERNAL_WRITE, "[GPS_UART]uart internal write data add=%d length=%d")
    TRC_MSG(GPS_UART_TRC_WRITE_HDLR, "[GPS_UART]uart_write_req_hdlr port:%d buffer=%d length=%d is_raw=%d cmd=%d")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_WARMSTART, "[GPS_UART]GPS command WARM START")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_HOTSTART, "[GPS_UART]GPS command HOT START")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_COLDSTART, "[GPS_UART]GPS command COLD START")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_VERSION, "[GPS_UART]GPS command get version")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_ENABLE_DEBUG_INFO, "[GPS_UART]GPS command enable debug info")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_SWITCH_MA, "[GPS_UART]GPS command Switch to MA mode")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_SWITCH_MB, "[GPS_UART]GPS command Switch to MB mode")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_SWITCH_NORMAL, "[GPS_UART]GPS command Switch to Normal mode")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_POS_QUERY, "[GPS_UART]GPS command Position query")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_MEAS_QUERY, "[GPS_UART]GPS command measurement query")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_CLEAR_NVRAM, "[GPS_UART]GPS command clear nvram")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_WRITTEN, "[GPS_W]Written:%d")
    //TRC_MSG(GPS_UART_TRC_GPS_CMD_NUMBER, "[GPS_UART]GPS command:%d")
    TRC_MSG(GPS_UART_TRC_GPS_CMD_UNPROCESSED_CMD, "[GPS_UART]GPS command Unprocessed:PMTK%d")
    TRC_MSG(GPS_UART_TRC_GPS_TASK_RESET, "[GPS Task] gps_task_reset()")
   /* --------------------------------------------------------------- */
   /* ----------------------- MODULE NAME:GPS_PARSER------------------- */
   /* --------------------------------------------------------------- */

    TRC_MSG(GPS_UART_TRC_ENABLE_SENTENCE, "[GPS_PARSER] enable sentence")
    TRC_MSG(GPS_UART_TRC_DISABLE_SENTENCE, "[GPS_PARSER] disable sentence")
    TRC_MSG(GPS_PARSER_TRC_GGA_FAILED, "[GPS_PARSER] $GPGGA field failed ")
    TRC_MSG(GPS_PARSER_TRC_GLL_FAILED, "[GPS_PARSER] $GPGLL field failed ")
    TRC_MSG(GPS_PARSER_TRC_GSA_FAILED, "[GPS_PARSER] $GPGSA field failed ")
    TRC_MSG(GPS_PARSER_TRC_GSV_FAILED, "[GPS_PARSER] $GPGSV field failed ")
    TRC_MSG(GPS_PARSER_TRC_RMC_FAILED, "[GPS_PARSER] $GPRMC field failed ")
    TRC_MSG(GPS_PARSER_TRC_VTG_FAILED, "[GPS_PARSER] $GPVTG field failed ")
    TRC_MSG(GPS_PARSER_TRC_P_RELEASE_FAILED, "[GPS_PARSER]PMTK Release field failed")
    TRC_MSG(GPS_PARSER_TRC_P_ACQ_FAILED, "[GPS_PARSER]PMTK ACQ field failed")
    TRC_MSG(GPS_PARSER_TRC_P_BITSYNC_FAILED, "[GPS_PARSER]PMTK bitsync field failed")
    TRC_MSG(GPS_PARSER_TRC_P_SIGNAL_FAILED, "[GPS_PARSER]PMTK signal field failed")
    TRC_MSG(GPS_PARSER_TRC_P_FIX_CONTRL_FAILED, "[GPS_PARSER]PMTK fix_control field failed")
    TRC_MSG(GPS_PARSER_TRC_PRO_SENTENCE, "[GPS_PARSER] gps_nmea_process_sentence")
    TRC_MSG(GPS_PARSER_TRC_PUSH_DATA, "[GPS_PARSER] push data buffer=%d length=%d")
    //TRC_MSG(GPS_PARSER_TRC_PARSER_STR, "[GPS_PARSER][state] start found")
    //TRC_MSG(GPS_PARSER_TRC_PARSER_CHK_SUM, "[GPS_PARSER][state] check sum flag found")
    TRC_MSG(GPS_PARSER_TRC_PARSER_NEED_END_CR, "[GPS_PARSER][state] need CR")
    //TRC_MSG(GPS_PARSER_TRC_PARSER_END_CR_OK, "[GPS_PARSER][state] END CR OK")
    TRC_MSG(GPS_PARSER_TRC_PARSER_CHK_SUM_OK, "[GPS_PARSER][state] Check sum OK")
    TRC_MSG(GPS_PARSER_TRC_CB_GGA, "[GPS_PARSER]sentenc pro GPGGA enable=%d")
    TRC_MSG(GPS_PARSER_TRC_CB_GLL, "[GPS_PARSER]sentenc pro GPGLL enable=%d")
    TRC_MSG(GPS_PARSER_TRC_CB_GSA, "[GPS_PARSER]sentenc pro GPGSA enable=%d")
    TRC_MSG(GPS_PARSER_TRC_CB_GSV, "[GPS_PARSER]sentenc pro GPGSV enable=%d is all rec=%d")
    TRC_MSG(GPS_PARSER_TRC_CB_RMC, "[GPS_PARSER]sentenc pro GPRMC enable=%d")
    TRC_MSG(GPS_PARSER_TRC_CB_VTG, "[GPS_PARSER]sentenc pro GPVTG enable=%d")
    TRC_MSG(GPS_PARSER_TRC_FIX_POSITION_OVER, "[GPS_PARSER]POSITION FIX OVER FIRST TIME")


   /* --------------------------------------------------------------- */
   /* ----------------------- MODULE NAME:GPS_LOGGING---------------- */
   /* --------------------------------------------------------------- */
    TRC_MSG(GPS_LOG_TRC_SENTENCE_TYPE, "[GPS_LOG]Sentence Catcher=%d Agent=%d")
    TRC_MSG(GPS_LOG_TRC_SEND_AGENT_STC, "[GPS_LOG]Send NMEA sentence to agent")
    TRC_MSG(GPS_LOG_TRC_CLOSE_FILE_HANDLE, "[GPS_LOG]close file handle=%d")
    TRC_MSG(GPS_LOG_TRC_AGENT_WRITE_REQ, "[GPS_LOG]Agent ask write data data_ptr=%d length=%d")
    TRC_MSG(GPS_LOG_TRC_SET_WORK_PORT, "[GPS_LOG]mdi_gps_set_work_port=%d")
    TRC_MSG(GPS_LOG_TRC_SET_AGENT_ENABLE, "[GPS_LOG]mdi_gps_set_agent_logging enable")
    TRC_MSG(GPS_LOG_TRC_SET_AGENT_DISABLE, "[GPS_LOG]mdi_gps_set_agent_logging disable")
    TRC_MSG(GPS_LOG_TRC_SET_CATCHER_ENABLE, "[GPS_LOG]mdi_gps_set_catcher_logging enable")
    TRC_MSG(GPS_LOG_TRC_SET_CATCHER_DISABLE, "[GPS_LOG]mdi_gps_set_catcher_logging disable")
    TRC_MSG(GPS_LOG_TRC_SET_DEBUG_ENABLE, "[GPS_LOG]mdi_gps_set_debug_info enable")
    TRC_MSG(GPS_LOG_TRC_SET_DEBUG_DISABLE, "[GPS_LOG]mdi_gps_set_debug_info enable")
    TRC_MSG(GPS_AGPS_TRC_P_RSP_FAILED, "[GPS]Parser P response error")

#if defined(__AGPS_SUPPORT__)
   /* --------------------------------------------------------------- */
   /* ----------------------- MODULE NAME:GPS_AGPS___---------------- */
   /* --------------------------------------------------------------- */
    TRC_MSG(GPS_AGPS_TRC_CMD_TIMEOUT, "[AGPS]CMD timeout cmd=%d")
    TRC_MSG(GPS_AGPS_TRC_CMD_IN_PROCESSING, "[AGPS]processing CMD is in processing=%d")
    TRC_MSG(GPS_AGPS_TRC_CMD_START_WRITE_EXP_TIMER, "[AGPS]start CMD time exp timer")
    TRC_MSG(GPS_AGPS_TRC_NAVIGATION_WRITE, "[AGPS]navigation write index=%d sate_num=%d")
    TRC_MSG(GPS_AGPS_TRC_REF_TIME_TOW_ASSIST_WRITE, "[AGPS]ref time tow assist write index=%d sate_num=%d")
    TRC_MSG(GPS_AGPS_TRC_ALMANAC_WRITE, "[AGPS]almanac write index=%d sate_num=%d")
    TRC_MSG(GPS_AGPS_TRC_ACQUISITION_WRITE, "[AGPS]acquisition write index=%d sate_num=%d")
    TRC_MSG(GPS_AGPS_TRC_REF_LOCATION_WRITE, "[AGPS]ref_location write")
    TRC_MSG(GPS_AGPS_TRC_IONOSPHERE_WRITE, "[AGPS]ionosphere write")
    TRC_MSG(GPS_AGPS_TRC_REF_TIME_WRITE, "[AGPS]ref_time write")
    TRC_MSG(GPS_AGPS_TRC_UTC_WRITE, "[AGPS]UTC write")
    TRC_MSG(GPS_AGPS_TRC_RTI_WRITE, "[AGPS]real time integrity write")
    TRC_MSG(GPS_AGPS_TRC_DGPS_CORRECTION_WRITE, "[AGPS]dgps correction write")
    TRC_MSG(GPS_AGPS_TRC_AGPS_PARSER, "[AGPS]AGPS PARSER cmd=%d")
    TRC_MSG(GPS_AGPS_TRC_CALC_CHECK_SUM_ERROR, "[AGPS]Check Sum Error: Sum = %d")
    TRC_MSG(GPS_AGPS_TRC_ASSIST_DATA_STATE, "[AGPS]assist_valid_bitmap = %d")
    TRC_MSG(GPS_AGPS_TRC_RES_NOT_FOUND_CMD, "[AGPS]RESPONSE parser not found CMD")
    TRC_MSG(GPS_AGPS_TRC_RES_CMD_RESULT, "[AGPS]response CMD:%d result:%d")
    TRC_MSG(GPS_AGPS_TRC_NAV_SEND_ERROR, "[AGPS]send navigation error")
    TRC_MSG(GPS_AGPS_TRC_NAV_INDEX_EQU_N_SAT, "[AGPS]navigation_index = N_sat")
    TRC_MSG(GPS_AGPS_TRC_IND_REQ_FALSE, "[AGPS]assist_indication_req = KAL_FALSE")
    TRC_MSG(GPS_AGPS_TRC_MEAS_PARSER_FAILED, "[AGPS]Parser measurement data error")
    TRC_MSG(GPS_AGPS_TRC_ASSIST_DATA_FAILED, "[AGPS]Parser assist data bitmap error")
    TRC_MSG(GPS_AGPS_TRC_POS_PARSER_FAILED, "[AGPS]Parser gps_agps_pos_parser error")
#if defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__) || defined(__L1_GPS_REF_TIME_SUPPORT__)
    TRC_MSG(GPS_AGPS_TRC_FTIME_PARSER_FAILED, "[AGPS]Parser ftime data error")
#endif
    TRC_MSG(GPS_AGPS_TRC_POS_TIMER_START, "[AGPS]Start Pos time index=%d")
    TRC_MSG(GPS_AGPS_TRC_MEAS_TIMER_START, "[AGPS]Start Meas time index=%d")
    TRC_MSG(GPS_AGPS_TRC_POS_TIMER_STOP, "[AGPS]Stop Pos time index=%d")
    TRC_MSG(GPS_AGPS_TRC_MEAS_TIMER_STOP, "[AGPS]Stop Meas time index=%d")
    TRC_MSG(GPS_AGPS_TRC_SET_POS_GPS_TASK1, "[AGPS]Set pos to GPS task latitude=%d sign=%d")
    TRC_MSG(GPS_AGPS_TRC_SET_POS_GPS_TASK2, "[AGPS]Set pos to GPS task longtitude=%d")
    TRC_MSG(GPS_AGPS_TRC_SET_POS_GPS_TASK3, "[AGPS]Set pos to GPS task altitude=%d sign=%d")
    TRC_MSG(GPS_AGPS_TRC_SET_POS_GPS_TASK4, "[AGPS]Set pos to GPS task unc_major=%d/%d unc_minor=%d/%d")
    TRC_MSG(GPS_AGPS_TRC_SET_POS_GPS_TASK5, "[AGPS]Set pos to GPS task unc_bear=%d unc_vert=%d/%d")
    TRC_MSG(GPS_AGPS_TRC_SET_POS_GPS_TASK6, "[AGPS]Set pos to GPS task confidence=%d h_speed=%d")
    TRC_MSG(GPS_AGPS_TRC_SET_POS_GPS_TASK7, "[AGPS]Set pos to GPS task bearing=%d ticks=%d")
    TRC_MSG(GPS_AGPS_TRC_POS_TO_GAD_UNC_MAJOR, "[AGPS][lcsp_pos_to_gad] unc_major[%d/%d]")
    TRC_MSG(GPS_AGPS_TRC_POS_TO_GAD_UNC_MINOR, "[AGPS][lcsp_pos_to_gad] unc_minor[%d/%d]")
    TRC_MSG(GPS_AGPS_TRC_POS_TO_GAD_UNC_VERT, "[AGPS][lcsp_pos_to_gad] unc_altitude[%d/%d]")
    TRC_MSG(GPS_AGPS_TRC_QOP_CHECK_DELAY, "[AGPS]QOP check qop_delay=%d delay_valid=%d his->ticks=%d sys_ticks=%d")
    TRC_MSG(GPS_AGPS_TRC_MAJ_MIN_UNC_DISMATCH, "[AGPS]QOP should be cur_maj=%d =< req_maj=%d cur_min=%d =< req_min=%d")
    TRC_MSG(GPS_AGPS_TRC_ALTITUDE_DISMATCH, "[AGPS] QOP altitude should be: curr_alt_unc[%d] < req_alt_unc[%d], line[%d]")
    TRC_MSG(GPS_AGPS_TRC_MEAS_QOP_ACCURACY, "[AGPS]meas_qop[j]=%d qop.accurcy=%d")        
    TRC_MSG(GPS_AGPS_TRC_MEAS_INDEX_MEET_QOP, "[AGPS]index:%d meas data meet qop")
    TRC_MSG(GPS_AGPS_TRC_MEAS_INDEX_TIMEOUT, "[AGPS]Meas timeout:index=%d")
    TRC_MSG(GPS_AGPS_TRC_POS_INDEX_TIMEOUT, "[AGPS]Pos timeout:index=%d")
    TRC_MSG(GPS_AGPS_TRC_WAIT_FOR_REF_TIME_ASSIST_BITMAP, "[AGPS] wait for ref_time assist data bitmap=%d")
    TRC_MSG(GPS_AGPS_TRC_CURRENT_ASSIST_BITMAP, "[AGPS] gps_loc_error_send_rsp(): current assist bitmap=%d")
    TRC_MSG(GPS_AGPS_TRC_TIME_INDEP_ASSIST_DATA_CHECK, "[AGPS] allow to process time independent assist data, current valid assist bitmap=%d")
    TRC_MSG(GPS_AGPS_TRC_POS_VALID, "[AGPS] pos [%d] is valid")
    TRC_MSG(GPS_AGPS_TRC_MEAS_VALID, "[AGPS] meas [%d] is valid")
    TRC_MSG(GPS_AGPS_TRC_CHECK_MEAS_QOP, "[AGPS] check assist=%d, bitmap=%d, pass=%d, acquisition_valid=%d")
    TRC_MSG(GPS_AGPS_TRC_LOC_ERROR_PARSER, "[AGPS] gps_agps_loc_error_parser(), enter")
    TRC_MSG(GPS_AGPS_TRC_RET_FALSE, "[AGPS][loc_error_parser] ret FALSE")
    TRC_MSG(GPS_AGPS_TRC_POS_REPORT_DELAY, "[AGPS] POS report delayed, curr_cnt[%d], target_cnt[%d]")
#ifdef __AGPS_CONTROL_PLANE__
    TRC_MSG(GPS_AGPS_TRC_AREA_REQ, "[GPS]CP Area event %d,rad=%d al=%d lat=%d lng=%d s_al=%d s_lat=%d")
    TRC_MSG(GPS_AGPS_TRC_POS_FIX_LAT_LONG,"[GPS]rmc lat=%d lng=%d req lat=%d lng=%d id=%d")
#endif
    TRC_MSG(GPS_AGPS_TRC_SELF_DEFINED_CMD_PARSER_FAILED, "[AGPS] Parser self define cmd %d error")
    TRC_MSG(GPS_AGPS_TRC_AP_TRIGGER_RESET, "[AGPS] AP side trigger AGPS reset!")
    TRC_MSG(GPS_AGPS_TRC_CP_AUTO_RESET_OPTION, "[AGPS] CP auto reset option: %d")
    TRC_MSG(GPS_AGPS_TRC_CP_AUTO_RESET_TRIGGERED, "[AGPS] CP auto reset is triggered because finished with %Mgps_error_code_enum!")
    TRC_MSG(GPS_AGPS_TRC_UPDATE_POS_QOP_RECORD, "[AGPS] [Update Pos QOP] qop_delay=%ds, qop_hor_acc=%dm, qop_ver_acc=%dm")
    TRC_MSG(GPS_AGPS_TRC_UPDATE_MEAS_QOP_RECORD, "[AGPS] [Update Meas QOP] qop_delay=%ds, qop_acc=%dm")
    TRC_MSG(GPS_AGPS_TRC_ANOTHER_AGPS_SESSION_ONGOING, "[AGPS] [Dual Modem] Receive (PMTK997, 6): another AGPS session is ongoing!! pos_meas cnf fail sent [%d]")
    TRC_MSG(GPS_AGPS_TRC_UART_REOPEN, "[AGPS] [Dual Modem] uart_reopen!!another AGPS session ongoing [%d], loc error sent [%d]")
    TRC_MSG(GPS_AGPS_REMAINING_TICK_NUM, "[AGPS] Remaining tick number is %d")
#endif

   /* --------------------------------------------------------------- */
   /* ----------------------- MODULE NAME:GPS_SLEEP_MODE--------------*/
   /* --------------------------------------------------------------- */
    TRC_MSG(GPS_TIMER_TRC_TIMEOUT_ID, "[GPS_TIMER] gps timer expiry id=%d")
    TRC_MSG(GPS_TIMER_TRC_START_TIMER_ID, "[GPS_TIMER] start gps timer id=%d")
    TRC_MSG(GPS_TIMER_TRC_STOP_TIMER_ID, "[GPS_TIMER] stop timer id=%d")
    TRC_MSG(GPS_TIMER_TRC_ALREADY_STOP_TIMER_ID, "[GPS_TIMER] timer already stop id=%d")
    TRC_MSG(GPS_TIMER_TRC_IGNORE_TIMEOUT_ID, "[GPS_TIMER] ignore expiry timer id=%d")
    TRC_MSG(GPS_SLEEP_TRC_ENABLE_SLEEP, "[GPS_SLEEP] enable gsm sleep mode, current_time=%d")
    TRC_MSG(GPS_SLEEP_TRC_DISABLE_SLEEP, "[GPS_SLEEP] disable gsm sleep mode, current_time=%d")
    TRC_MSG(GPS_SLEEP_TRC_START_TIMER, "[GPS_SLEEP] start timer, current_time=%d, timeout=%d, timer=%d")
    TRC_MSG(GPS_SLEEP_TRC_STOP_TIMER, "[GPS_SLEEP] stop timer, current_time=%d, timer=%d")
    TRC_MSG(GPS_SLEEP_TRC_UART_DATA, "[GPS_SLEEP] we can't sleep because UART still has some data!!")
    TRC_MSG(GPS_SLEEP_TRC_SEND_ACK, "[GPS_SLEEP] send ACK to GPS module!!")

   /* --------------------------------------------------------------- */
   /* ----------------------- MODULE NAME:GPS_CALIBRATION_RTC-------- */
   /* --------------------------------------------------------------- */
    TRC_MSG(GPS_RTC_TRC_UTC_INVALID_TIME, "[GPS_RTC] UTC time is invalid")
    TRC_MSG(GPS_RTC_TRC_FIRST_POWERON, "[GPS_RTC] The phone is first power on")
    TRC_MSG(GPS_RTC_TRC_CALIBRATE_RTC, "[GPS_RTC] Utilize GPS UTC time to calibrate GSM RTC time")
    TRC_MSG(GPS_RTC_TRC_ADJUST_RTC_DIFF, "[GPS_RTC] GSM's RTC time is changed!!! We need to adjust the difference")
    TRC_MSG(GPS_RTC_TRC_GSM_CURRENT_TIME, "[GPS_RTC] gsm current time, year=%d, mon=%d, day=%d, hour=%d, min=%d, sec=%d")
    TRC_MSG(GPS_RTC_TRC_GSM_CURRENT_GPS_TIME, "[GPS_RTC] gsm current gps time, wn=%d, tow=%d")
    TRC_MSG(GPS_RTC_TRC_GPS_CURRENT_TIME, "[GPS_RTC] gps current time, year=%d, mon=%d, day=%d, hour=%d, min=%d, sec=%d")
    TRC_MSG(GPS_RTC_TRC_GPS_CURRENT_GPS_TIME, "[GPS_RTC] gps current gps time, wn=%d, tow=%d")
    TRC_MSG(GPS_RTC_TRC_DIFF_CURRENT_GPS_TIME, "[GPS_RTC] diff current gps time, wn=%d, tow=%d")
    /* ----------------------- MODULE NAME:add-------- */
    TRC_MSG(GPS_UTC_TRC_AGE_TOW_RANGE, "[GPS_RTC] age_tow > 1 week || age_tow < 0 ")
    TRC_MSG(GPS_UTC_TRC_CALIBRATE_CLOCK_DRIFT_FAIL, "[GPS_RTC] Calibrate Clock Drift Fail")
    TRC_MSG(GPS_UTC_TRC_GPS_CLOCK_DRIFT, "[GPS_RTC] diff current gps time, wn=%d, tow=%d")
    TRC_MSG(GPS_RTC_TRC_PREVIOUS_RTC, "[GPS_RTC] previous RTC:year=%d, mon=%d, day=%d, hour=%d, min=%d, sec=%d")
    TRC_MSG(GPS_RTC_TRC_NEW_RTC, "[GPS_RTC] new RTC:year=%d, mon=%d, day=%d, hour=%d, min=%d, sec=%d")
    TRC_MSG(GPS_TRC_MNL_HW_CHECK_SIZE, "[GPS_INIT] MNL HW Check Size = %d !")
    TRC_MSG(GPS_TRC_MNL_HW_CHECK_DATA, "[GPS_INIT] MNL HW Check Data = 0x%x !")
    TRC_MSG(GPS_TRC_MNL_HW_CHECK_OK, "[GPS_INIT] MNL HW Check OK !")
    TRC_MSG(GPS_TRC_MNL_HW_CHECK_FAIL, "[GPS_INIT] MNL HW Check Fail...Try Again !!!")
    TRC_MSG(GPS_TRC_MNL_HW_CHECK_32K_CLOCK, "[GPS_INIT] MNL HW Check,modelpo,%d,numlpo,%d,TEST")
    TRC_MSG(GPS_TRC_MNL_INIT_GPS_STATUS, "[GPS_INIT] gps_state:(%d),if 1:init MNL; 0:not to init MNL.")
    TRC_MSG(GPS_TRC_MNL_INIT, "[GPS_INIT] MNL Init")
    TRC_MSG(GPS_TRC_READ_GPS_DSP_BIN_SECCUSS, "[GPS_INIT] success to read gps_dsp.bin!")
    TRC_MSG(GPS_TRC_READ_GPS_DSP_BIN_FAIL, "[GPS_INIT] Fail to read gps_dsp.bin!")
    TRC_MSG(GPS_TRC_MNL_INIT_OK, "[GPS_INIT] MNL Init OK !!!")
    TRC_MSG(GPS_TRC_MNL_INIT_FAIL, "[GPS_INIT] MNL Init Fail !!!")
    TRC_MSG(GPS_TRC_MNL_SHUTDOWN_GPS_STATUS, "[GPS_CLOSE] GPS_Status:(%d).0:do MNL shutdown; 1: not do GPS MNL Shutdown()!!!")
    TRC_MSG(GPS_PARSER_P_CMD_714_FAILED, "[AGPS]Parser PMTK714 message error")
    
    TRC_MSG(GPS_TRC_MNL_SHUTDOWN, "MNL Shutdown")
    TRC_MSG(GPS_TRC_GPS_STOP_TIMER, "MNL Shutdown")
    TRC_MSG(GPS_INJECT_CMD_TRC_UART_BAUDRATE_SETTING_INVALID, "[warning]The inject string is out of range[1~4]!!!")
    TRC_MSG(GPS_INJECT_CMD_TRC_GPS_OPEN_NOTIFY, "The GPS hasn't Power ON.Turn ON GPS first!!!")
    TRC_MSG(GPS_INJECT_CMD_TRC_GPS_POWER_ON_OFF_OPEN_GPS, "[GPS_INJECT] power on GPS ")
    TRC_MSG(GPS_INJECT_CMD_TRC_GPS_POWER_ON_OFF_CLOSE_GPS, "[GPS_INJECT]power off GPS ")
    TRC_MSG(GPS_INJECT_CMD_TRC_GPS_POWER_ON_OFF_COUNT, "[GPS_INJECT]power on off count:%d")
    TRC_MSG(GPS_TRC_GPS_ENTER_POWER_SAVEING_MODE, "[APSM] Enter Power Saving Mode")
    TRC_MSG(GPS_TRC_GPS_ENTER_NORMAL_FIX_MODE, "[APSM] Enter Normal Fix Mode")
    TRC_MSG(GPS_TRC_GPS_NORMAL_FIX_COUNT, "[APSM] gps_ps_normal_fix_count = %d")
    TRC_MSG(GPS_TRC_GPS_NO_FIX_COUNT, "[APSM] no fix = %d")
    TRC_MSG(GPS_TRC_GPS_SPEED_LOW_NORMAL_FIX_COUNT, "[APSM] speed <  10 and normal = %d")
    TRC_MSG(GPS_TRC_GPS_SPEED_HIGHNORMAL_FIX_COUNT, "[APSM] speed >= 10 and normal = %d")
    
    TRC_MSG(GPS_TRC_IS_GSM_GPS_REF_TIME_NEEDED, "time sync - is_gsm_gps_ref_time_wanted=%d")
    TRC_MSG(GPS_TRC_IS_UTRAN_GPS_REF_TIME_NEEDED, "time sync - is_utran_gps_ref_time_wanted=%d")
    TRC_MSG(GPS_UART_TRC_ASSERT_NMEA, "ASSERT_NMEA:%s")
    
    
   /***************TRC MSG FOR GPS END ********************/
END_TRACE_MAP(MOD_GPS)
#endif /* __GPS_SUPPORT__*/
#endif /* __GPS_TRC_H__ */
