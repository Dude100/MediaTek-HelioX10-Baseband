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

/*******************************************************************************
 * Filename:
 * ---------
 *   rtc_trc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is trace map definition for RTC driver
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef _RTC_TRC_H
#define _RTC_TRC_H


#ifndef GEN_FOR_PC

   #ifndef _STACK_CONFIG_H
   #error "stack_config.h should be included before tst_config.h"
   #endif

#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */


#ifndef _KAL_TRACE_H
   #error "kal_trace.h should be included before tst_trace.h"
#endif

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "rtc_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_RTC_HISR)

   TRC_MSG(RTC_REPEAT_CALI_ADJUST_COUNT,"RTC adjust %d count for repeat calibration register")
   TRC_MSG(RTC_REPEAT_CALI_VALUE,"RTC repeat calibration register value: %x")
   TRC_MSG(RTC_REPEAT_CALI_VALUE_EXCEED_MAX,"RTC repeat calibration value %d exceed max")
   TRC_MSG(RTC_REPEAT_CALI_VALUE_EXCEED_MIN,"RTC repeat calibration value %d exceed min")
   TRC_MSG(RTC_REPEAT_CALI_PERFORM_CALI,"RTC repeat calibration perform for %d counts")
   
   TRC_MSG(RTC_ONESHOT_CALI_PERFORM_COUNT,"RTC one shot calibration for %d counts, remains %d counts")
   TRC_MSG(RTC_ONESHOT_CALI_VALUE,"RTC oneshot calibration register value: %x")
   TRC_MSG(RTC_ONESHOT_CALI_FINISH,"RTC oneshot calibration finish")
   
   TRC_MSG(RTC_HW_CALI_START_MEASURE_INACCURATE,"RTC HW cali, start to measure rtc inaccurate: (%d:%d:%d)")
   TRC_MSG(RTC_HW_CALI_INIT_MEASURE_ACCURATE_L1_TICK,"RTC HW cali, init L1 tick: %d")
   TRC_MSG(RTC_HW_CALI_FINISH_MEASURE_INACCURATE,"RTC HW cali, finish measuring rtc inaccurate: (%d:%d:%d)")
   TRC_MSG(RTC_HW_CALI_FINISH_MEASURE_ACCURATE_L1_TICK,"RTC HW cali, finish L1 tick: %d, inaccurate ticks: %d")
   TRC_MSG(RTC_HW_CALI_NO_NEED_TO_CALI,"RTC HW cali, no need to perform calibration, no diff count: %d")
   TRC_MSG(RTC_HW_CALI_IN_PROGRESS,"RTC HW cali, in progress: (%d:%d:%d)")
   TRC_MSG(RTC_HW_CALI_INIT_REPEAT_CALI_COUNT,"RTC HW cali, init repeat cali count: %d")
   
   TRC_MSG(RTC_SW_CALI_START_POWEROFF_CALI,"RTC SW cali, start to do power off cali")
   TRC_MSG(RTC_SW_CALI_START_POWEROFF_CALI_TIME,"RTC SW cali, current time before power off cali: (%d:%d:%d)")
   TRC_MSG(RTC_SW_CALI_FINISH_POWEROFF_CALI_TIME,"RTC SW cali, current time after power off cali: (%d:%d:%d)")
   TRC_MSG(RTC_SW_CALI_FINISH_2ND_POWEROFF_CALI,"RTC SW cali, wait %d ticks to perform 2nd power off cali")
   TRC_MSG(RTC_SW_CALI_AFTER_2ND_POWEROFF_CALI,"RTC SW cali, current time after 2nd power off cali: (%d:%d:%d)")
   TRC_MSG(RTC_SW_CALI_START_POWERON_CALI_TIME,"RTC SW cali, start power on cali: (%d:%d:%d), init tick: %d")
   TRC_MSG(RTC_SW_CALI_POWERON_CALI_START_INACCURACY_MEASURE,"RTC SW cali, start accuracy measure")
   TRC_MSG(RTC_SW_CALI_POWERON_CALI_FINISH_INACCURACY_MEASURE,"RTC SW cali, accuracy for one hour: %d ticks")
   TRC_MSG(RTC_SW_CALI_POWERON_CALI_START,"RTC SW cali, start power on cali: (%d:%d:%d), init tick: %d")
   TRC_MSG(RTC_SW_CALI_WRITE_NVRAM,"RTC SW cali, write to NVRAM")
   TRC_MSG(RTC_SW_CALI_KAL_EXPIRE_EARLY,"RTC SW cali, KAL_timer expired early, expected: %d (tick), now: %d")
   TRC_MSG(RTC_SW_CALI_TIMOUE_NOT_IN_SEC_BOUNDARY,"RTC SW cali, timeout not in second boundary: %d (tick)")
   TRC_MSG(RTC_SW_CALI_TIMOUE_OUT,"RTC SW cali timeout (%d:%d:%d), current frame tick: %d")
   TRC_MSG(RTC_SW_CALI_UPDATE_TIME,"RTC SW cali, update time (%d:%d:%d), current frame tick: %d")
   TRC_MSG(RTC_SW_CALI_POWEROFF_CALI_INIT1,"RTC SW cali, NVRAM time valid: %d")
   TRC_MSG(RTC_SW_CALI_POWEROFF_CALI_INIT2,"RTC SW cali, NVRAM time: %d-%d-%d (%d:%d:%d)")
   TRC_MSG(RTC_SW_CALI_POWEROFF_CALI_INIT3,"RTC SW cali, NVRAM tick diff valud: %d")
   TRC_MSG(RTC_SW_CALI_POWEROFF_CALI_INIT4,"RTC SW cali, NVRAM ticks_diff_per_hour: %d")
   TRC_MSG(RTC_SW_CALI_CURR_POWER_TIME,"RTC SW cali, curr power on time: %d-%d-%d (%d:%d:%d)")
   TRC_MSG(RTC_SW_CALI_RTC_TIME_IN_MINUTE_BOUNDARY,"RTC SW cali, rtc time in minute boundary: %d, delay 6 sec")
   TRC_MSG(RTC_SW_CALI_RTC_TIME_IN_ALARM_BOUNDARY,"RTC SW cali, rtc time in alarm boundary: %d, delay 6 sec")
   TRC_MSG(RTC_SW_CALI_INACCURATE_TICK_DURING_POWEROFF,"RTC cali, inaccurate ticks during power off: %d")
   TRC_MSG(RTC_SW_CALI_ALARM_POWERON_AND_NEED_BACKWARD_TIME,"RTC cali, alarm power on, but we need to backward time")
   TRC_MSG(RTC_SW_CALI_ALARM_POWERON_AND_POWEROFF,"RTC cali, alarm power on but we backward time so power off")
   
   
   
   TRC_MSG(RTC_TC_INTR_FOR_USER,"RTC TC intr for user")
   TRC_MSG(RTC_AL_INTR,"RTC AL intr")
   
   TRC_MSG(RTC_FORWARD_TIME_1,"RTC forward time: (%d:%d:%d) forward %d hour, %d min, %d sec")
   TRC_MSG(RTC_FORWARD_TIME_2,"RTC forward time done: (%d:%d:%d)")
   TRC_MSG(RTC_BACKWARD_TIME_1,"RTC backward time: (%d:%d:%d) backward %d hour, %d min, %d sec")
   TRC_MSG(RTC_BACKWARD_TIME_2,"RTC backward time done: (%d:%d:%d)")
   
   
   

	
END_TRACE_MAP(MOD_RTC_HISR)

#endif /* _RTC_TRC_H */


