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
 *    rtc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the RTC driver.
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_public_api.h"
#include	"drv_features.h"
#include "kal_public_defs.h" //MSBB change #include 	"stack_msgs.h"
#include 	"drv_comm.h"
#include    "drvsignals.h"
#include    "init.h"
#include "md_drv_sap.h"
#include "svc_sap.h"
#include "l4_msgid.h"
#include "nvram_msgid.h"
#include "sysservice_msgid.h"

#ifndef DRV_RTC_NOT_EXIST

#include 	"kal_trace.h"
#include 	"intrctrl.h"

#include 	"reg_base.h"
#include 	"rtc_hw.h"
#include 	"rtc_sw_new.h"
#if !defined(DRV_RTC_OFF) //Empty function need rtc structure.
#include 	"intrCtrl.h"
#include "kal_public_defs.h" //MSBB change #include	"stack_config.h"		/* for module_type, MOD_DRV_HISR, MOD_GPS, MOD_UEM */
#include    "drv_hisr.h"
#ifdef __MULTI_BOOT__
#include 	"multiboot_config.h"
#endif /* __MULTI_BOOT__ */
#include    "drv_trc.h"
#include    "dcl.h"

/* #define  RTC_Test */
/* #define RTC_CAL_DEBUG */
/* #define RTC_CAL_DEBUG2 */
#if !defined(IC_BURNIN_TEST) && !defined(IC_MODULE_TEST) && !defined(__MAUI_BASIC__) && !defined(__FUE__) && !defined(__UBL__) && !defined(DRV_RTC_NO_REG_COMM)
#ifdef DRV_RTC_HW_CALI
#define RTC_HW_CALIBRATION
#else
#define RTC_SW_CALIBRATION
#endif
#endif

t_rtc RTCTimer; // For save latest rtc got correct time.

kal_uint16	originalPDN1; //For DCL test.

/*
#if defined(DRV_RTC_LOCK_PROTECT)
// unlock protection and lock it again.
#define DRV_RTC_WriteReg(a,b)   \
        DRV_RTC_WriteReg(RTC_PROT, RTC_PROTECT1); \
        DRV_RTC_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR); \
        while(DRV_RTC_Reg(RTC_BBPU) & 0x40); \
        DRV_RTC_WriteReg(RTC_PROT, RTC_PROTECT2); \
        DRV_RTC_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR); \
        while(DRV_RTC_Reg(RTC_BBPU) & 0x40); \
        DRV_RTC_WriteReg(a,b);   \
        DRV_RTC_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR); \
        while(DRV_RTC_Reg(RTC_BBPU) & 0x40); \
        DRV_RTC_WriteReg(RTC_PROT, 0x0); \
        DRV_RTC_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR); \
        while(DRV_RTC_Reg(RTC_BBPU) & 0x40);
#else
#define DRV_RTC_WriteReg(a,b)   DRV_RTC_WriteReg(a,b)
#endif
*/

#if defined(__MEUT__) || defined(__MEIT__)
	#define RTC_RESTORE_REGISTER_VALUES_FOR_DVT
#endif 
#ifdef RTC_RESTORE_REGISTER_VALUES_FOR_DVT
	kal_uint16 u2dvt_info1_reg_value;
	kal_uint16 u2dvt_rtc_seconds_value;
	kal_uint16 u2dvt_rtc_minutes_value;
	kal_uint16 u2dvt_rtc_hours_value;
	kal_uint16 u2dvt_rtc_bbpu_reg_value;
#endif
// Define to enable sleep workaround debug message
#if defined(DRV_RTC_SLEEP_LOCKED_UP_WA)
#if defined(MTK_SLEEP_ENABLE)
// If the chip has sleep mode locked up issue, and sleep mechanism is enabled, 
// We need to perform enable workaround to avoid locked up in sleep mode while loop
#define SLEEP_WORKAROUND_IN_RTC
// Define to enable debug message of SLEEP_WORKAROUND_IN_RTC
// #define RTC_SLEEP_WA_DEBUG
#endif // #if defined(MTK_SLEEP_ENABLE)
#endif // #if defined(DRV_RTC_SLEEP_LOCKED_UP_WA)

static kal_bool First_PowerOn = KAL_FALSE; /* use a static variable to recode is this first power on */
#if !defined(__FUE__) && !defined(__UBL__)
rtc_callbac RTC_CALLBAC;
rtc_module  RTCConfig;

#define MODULE_REGISTER_ILM_MAX_NUM     1
RTC_REG_MODULE_ILM_INFO_T rtc_reg_mod_ilm_info[MODULE_REGISTER_ILM_MAX_NUM];

/* for rtc calibration */
#if defined(RTC_HW_CALIBRATION) || defined(RTC_SW_CALIBRATION)

#if defined(__USB_ENABLE__) && !defined(__NVRAM_IN_USB_MS__)
extern kal_bool INT_USBBoot(void);
#endif /* __USB_ENABLE__ */

extern kal_uint32 L1I_GetTimeStamp(void);

/* for rtc calibration */
void rtc_cali_init(void *timer_param);

/* Calibration State */
typedef enum
{
   CAL_STATE_NONE = 0,
   CAL_STATE_INIT,
   CAL_STATE_INIT2,
   CAL_STATE_START,
   CAL_STATE_RESET
} rtc_cali_state;

static kal_uint8 cali_state = (kal_uint8)CAL_STATE_NONE;
static kal_uint8 rtc_tc_int_var = TC_EN_None;
static kal_uint16 tc_min_expire_cnt = 0;

#if defined(RTC_HW_CALIBRATION)
#define RTC_CALI_PERIOD_MINS		(6) // unit: minutes
#define RTC_CALI_PERIOD_SECS   		(RTC_CALI_PERIOD_MINS*60) // unit: minutes
#define RTC_CALI_REPEAT_DUR_SECS    (8) // spec: 8 seconds to do one repeate calibration    
#define RTC_CALI_REPEAT_TOTAL_CNT   (RTC_CALI_PERIOD_SECS>>3)
#define RTC_CALI_TICK_VALUE 		(13000 * RTC_CALI_PERIOD_MINS)
#define RTC_STANDARD_FREQ  			(32768)
#define RTC_STANDARD_FREQ_8SECS  	(RTC_STANDARD_FREQ * 8)

#define RTC_CALI_REPEAT_MAX   		(63)
#define RTC_CALI_REPEAT_MIN   		(-64)
#define RTC_CALI_ONE_TIME_MAX   	(2045)
#define RTC_CALI_ONE_TIME_MIN   	(-2048)

static kal_uint32 rtc_current_frame_tick;
static kal_uint32 rtc_current_freq_8secs;
static kal_bool one_time_cali = KAL_FALSE;
static kal_int32 inaccurate_total_cnt = 0;
static kal_int32 no_diff_cnt = 0;

#elif defined(RTC_SW_CALIBRATION)
extern BMTStruct BMT; /* Main BMT struct */
/* extern NVRAM API */
// extern kal_bool nvram_external_read_data(kal_uint8 LID,kal_uint8 rec_index, kal_uint8* buffer, kal_uint16 buffer_size);
kal_timerid rtc_timer_id = 0;
void rtc_system_timer_cb(void *timer_param); 
void rtc_get_next_time(void);
void rtc_forward_time(t_rtc *rtc_time, kal_uint16 hours, kal_uint16 mins, kal_uint16 secs);
void rtc_backward_time(t_rtc *rtc_time, kal_uint16 hours, kal_uint16 mins, kal_uint16 secs);
void rtc_write_to_nvram(void);

#if defined(SLEEP_WORKAROUND_IN_RTC)
// The tick to trigger rtc_sleep_wa_timer_cb to disable sleep mode
// We may delayed waked up at 59:04, set kal timer to wake up after 52 sec
// We may keep in sleep-disabled mode at least for 4 sec per hour
#define RTC_SLEEP_WA_DISABLE_SLEEP_TICK		11266 // ~ 52 sec, (13000/60) * 52 
kal_timerid rtc_sleep_wa_timer_id = 0;
void rtc_sleep_wa_timer_cb(void *timer_param);
void rtc_sleep_wa_enable_sleep_mode(void);
void rtc_sleep_wa_disable_sleep_mode(void);
kal_uint8 rtc_sleep_wa_handle;
volatile kal_bool rtc_sleep_wa_disable_sleep_performed = KAL_FALSE; // Init value: disable sleep NOT performed
// static t_rtc rtc_sleep_wa_ref;
#endif // #ifdef SLEEP_WORKAROUND_IN_RTC

#define rtc_cali_hr_period 			(1) /*hour*/ 
#define rtc_cali_min_period 		(2) /*minute*/ 
#define rtc_cali_tick_value 		(13000 * 60 * rtc_cali_hr_period + 13000 * rtc_cali_min_period)
#define rtc_cali_tick_safe_margin   13000 /* ticks */
#define rtc_tick_update_interval 	(217) /* 1300 / 6 = 216 and 2/3 */
#define rtc_sec_update_interval 	(1)

static const kal_uint8 days_in_month[13] = 
{
   0,  /* Null */ 
   31, /* Jan */
   28, /* Feb */
   31, /* Mar */
   30, /* Apr */
   31, /* May */
   30, /* Jun */
   31, /* Jul */
   31, /* Aug */
   30, /* Sep */
   31, /* Oct */
   30, /* Nov */
   31  /* Dec */
};

static rtc_nvram_data rtc_nvram_s;
static t_rtc next_current_time;
static kal_uint32 next_frame_tick, tick_left=0;
static kal_uint16 one_third_tick_count = 0; /* 217 - 216and2/3 = 1/3. The counts for the 1/3. */

static kal_uint8 rtc_al_int_var = AL_EN_None;
static kal_int32 pwroff_inacc_ticks = 0;
static kal_uint32 frame_tick1;
static kal_uint32 frame_tick2;
static kal_int32 frame_tick_1hr_diff;
#endif /* RTC_SW_CALIBRATION */
#endif /* defined(RTC_HW_CALIBRATION) || defined(RTC_SW_CALIBRATION) */
//extern void dbg_print(char *fmt,...);

#ifdef RTC_Test
void RTC_delay(void)
{
	kal_uint16 i;
	for(i = 0; i < 2000; i++);
}
#endif

void RTC_setBBPU(kal_uint16 data)
{
	data &= 0x00ff;
	data |= 0x4300;
	#if defined(DRV_RTC_WRITE_ENABLE)
	data |= RTC_BBPU_WRITE_EN;
	#endif // #if defined(DRV_RTC_WRITE_ENABLE)
	DRV_RTC_WriteReg(RTC_BBPU,data);
}
#endif /* !defined(__FUE__) && !defined(__UBL__) */

#if defined(DRV_RTC_HW_CALI)
/*
* FUNCTION                                                            
*	RTC_write_trigger
*
* DESCRIPTION                                                           
*   	This function is to enable the transfers from core to RTC.
*
* CALLS  
*	It is called to trigger RTC register writing.
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_write_trigger(void)
{
#if defined(DRV_RTC_NOT_EMPTY_TRIGGER)
	DRV_RTC_WriteReg(RTC_PROT, RTC_PROTECT2);
#endif // #if defined(DRV_RTC_NOT_EMPTY_TRIGGER)
	DRV_RTC_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR);
}

/*
* FUNCTION                                                            
*	RTC_write_trigger
*
* DESCRIPTION                                                           
*   	This function is to enable the transfers from core to RTC and wait till it's done.
*
* CALLS  
*	It is called to trigger RTC register writing.
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_write_trigger_wait(void)
{
	kal_uint32 count = 0;
   
#if defined(DRV_RTC_NOT_EMPTY_TRIGGER)
	DRV_RTC_WriteReg(RTC_PROT, RTC_PROTECT2);
#endif //#if defined(DRV_RTC_NOT_EMPTY_TRIGGER)
	DRV_RTC_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR);
	//while(count < 10000)
#if defined(DRV_RTC_SHORTER_CBUSY_POLLING)
   	while(count < 0x6EEEEE)
#else
	while(count < 0xffffffff)
#endif
	{
		if ((RTC_BBPU_CBUSY & DRV_RTC_Reg(RTC_BBPU)) == 0)
		{
			break;
		}
		count++;
	}
}

/*
* FUNCTION                                                            
*	RTC_reload
*
* DESCRIPTION                                                           
*     Reload the values from RTC domain to Core domain
*
* CALLS  
*	This function can be treated as a debugging function.
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_reload(void)
{
	kal_uint16 reg;
	
	reg = DRV_RTC_Reg(RTC_BBPU);
	reg |= (RTC_BBPU_RELOAD|RTC_BBPU_KEY);
	#if defined(DRV_RTC_WRITE_ENABLE)
	reg |= RTC_BBPU_WRITE_EN;
	#endif // #if defined(DRV_RTC_WRITE_ENABLE)
	DRV_RTC_WriteReg(RTC_BBPU, reg);
}
#endif //#if defined(DRV_RTC_HW_CALI)

#if !defined(__FUE__) && !defined(__UBL__)
/*
* FUNCTION                                                            
*	isPWROnByRTC
*
* DESCRIPTION                                                           
*   	This function is to check whether "power on" is due to RTC.
*
* CALLS  
*	It is called to check whether "power on" is due to RTC.
*
* PARAMETERS
*	None
*	
* RETURNS
*	KAL_TRUE: "Power on" is due to RTC.
*	KAL_FALSE: "Power on" is not due to RTC.
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool isPWROnByRTC(void)
{
#if defined(DRV_RTC_PWRON_BBPU_POLARITY) || defined(FPGA)
	kal_uint16 BBPU;
	kal_uint16 POLAR;
	kal_uint16 PWRSW;
	BBPU = DRV_RTC_Reg(RTC_BBPU);
	POLAR = BBPU & RTC_BBPU_PWR_POLARITY;
	POLAR >>= 1;
	PWRSW = BBPU & RTC_BBPU_PWR_SW;
	PWRSW >>= 4;
	
	if (POLAR == PWRSW)
	{
		return KAL_TRUE;
	}
	else
	{
		return KAL_FALSE;
	}
#endif /* DRV_RTC_PWRON_BBPU_POLARITY, FPGA */

#if defined(DRV_RTC_PWRON_BBPU_SW)
	if (DRV_RTC_Reg(RTC_BBPU) & RTC_BBPU_PWR_SW)
		return KAL_TRUE;
	else
		return KAL_FALSE;
#endif /* DRV_RTC_PWRON_BBPU_SW */
}
//=================================================================
/*
* FUNCTION                                                            
*	RTC_IRQOneShotEnable
*
* DESCRIPTION                                                           
*   	This function is to setup that RTC interrupt is at oneshot mode
*	or at automatic reset mode. 
*
* CALLS  
*	It is called to setup that RTC interrupt is at oneshot mode
*	or at automatic reset mode. 
*
* PARAMETERS
*	oneShotEN:
*     ONE_SHOT_DIS, automatic reset mode
*     ONE_SHOT_EN, one shot mode
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_IRQOneShotEnable(kal_uint8 oneShotEN)
{
	if (oneShotEN == ONE_SHOT_DIS)
	{
		DRV_RTC_ClearBits(RTC_IRQ_EN, RTC_IRQ_EN_ONESHOT);
		//DRV_RTC_Reg(RTC_IRQ_EN) &= ~RTC_IRQ_EN_ONESHOT;
	}
	else
	{
		DRV_RTC_SetBits(RTC_IRQ_EN, RTC_IRQ_EN_ONESHOT);
		//DRV_RTC_Reg(RTC_IRQ_EN) |= RTC_IRQ_EN_ONESHOT;
	}
#if defined(DRV_RTC_HW_CALI)
   	RTC_write_trigger_wait();
#endif
}
//=================================================================
/*
* FUNCTION                                                            
*	RTC_Config_
*
* DESCRIPTION                                                           
*   	Configure the RTC interrupt 
*
* CALLS  
*	This function is called to enable RTC interrupt
*
* PARAMETERS
*	AL_EN:
*		AL_EN_None: Alarm interrupt is disable.
*		AL_EN_bySEC: Alarm interrupt is issued by second.
*		AL_EN_byMIN: Alarm interrupt is issued by minute.
*	TC_EN:
*		TC_EN_None: TC interrupt is disable
*		TC_EN_bySEC: TC interrupt is issued by second.
*		TC_EN_byMIN: TC interrupt is issued by minute.
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_Config_(kal_uint8 AL_EN,kal_uint8 TC_EN)
{
	kal_uint16 tmp;
	kal_uint16 BBPU;
	kal_uint32 savedMask;

	#if defined(DRV_RTC_HW_CALI)
	RTC_wait_busy();
	#endif   
	
	#if defined(DRV_RTC_W_FLAG)
	while (DRV_RTC_Reg(RTC_IRQ_EN) & 0x8000){;};
	#endif // #if defined(DRV_RTC_W_FLAG)

	savedMask = SaveAndSetIRQMask();   
	
	
	tmp = DRV_RTC_Reg(RTC_IRQ_EN);
	tmp &= ~RTC_IRQ_EN_ONESHOT;
	BBPU = DRV_RTC_Reg(RTC_BBPU);

#if defined(RTC_HW_CALIBRATION)
   	/* Save user's configuration for Alarm and Time Clock settings. */
   	if (TC_EN != TC_EN_NoChange)
		rtc_tc_int_var = TC_EN;
   	if (cali_state == (kal_uint8)CAL_STATE_INIT)
   	{
      	/* In the calibration INIT state, we need "minute" interrupt. */
      	if ((TC_EN != TC_EN_ChkS) && (TC_EN != TC_EN_ChkM))
        	TC_EN = TC_EN_NoChange;
   	}
   	else if (cali_state == (kal_uint8)CAL_STATE_START)
   	{
		if (one_time_cali == KAL_TRUE)
		{
			/* We need "seconds" interrupt. */
			if (TC_EN != TC_EN_ChkS)
		    	TC_EN = TC_EN_NoChange;
		}
		else
		{
			/* We need "minute" interrupt. */
			if ((TC_EN != TC_EN_ChkS) && (TC_EN != TC_EN_ChkM))
				TC_EN = TC_EN_NoChange;
		}
	}
#elif defined(RTC_SW_CALIBRATION)
   	/* Save user's configuration for Alarm and Time Clock settings. */
	if (AL_EN != AL_EN_NoChange)
		rtc_al_int_var = AL_EN;
	if (TC_EN != TC_EN_NoChange)
		rtc_tc_int_var = TC_EN;
	if (cali_state == (kal_uint8)CAL_STATE_INIT)
	{
		/* In the calibration INIT state, we need "second" interrupt. */
		if (TC_EN != TC_EN_ChkS)
		 	TC_EN = TC_EN_NoChange;
	}
	else if (cali_state == (kal_uint8)CAL_STATE_START)
	{
		/* In the calibration START state, we need "minute" interrupt. */
		if ((TC_EN != TC_EN_ChkS) && (TC_EN != TC_EN_ChkM))
		 	TC_EN = TC_EN_NoChange;
	}
#endif /* RTC_SW_CALIBRATION */
	switch(AL_EN)
	{
		case AL_EN_None:
			tmp &= ~RTC_IRQ_EN_AL; /* RTC_ALIRQEnable(KAL_FALSE); */
			BBPU &= ~(RTC_BBPU_ALARM_SW); /* 0227 TY adds */
			break;
		
		case AL_EN_ChkS:
			tmp |= RTC_IRQ_EN_AL;
			DRV_RTC_WriteReg(RTC_AL_MASK, (~RTC_AL_MASK_SEC));
			BBPU |= (RTC_BBPU_ALARM_SW); /* 0227 TY adds */
			break;
		
		case AL_EN_ChkMS:
			tmp |= RTC_IRQ_EN_AL;
			DRV_RTC_WriteReg(RTC_AL_MASK, (~RTC_AL_MASK_MIN));
			BBPU |=(RTC_BBPU_ALARM_SW); /* 0227 TY adds */
			break;
      
		case AL_EN_ChkHMS:
			tmp |= RTC_IRQ_EN_AL;
			DRV_RTC_WriteReg(RTC_AL_MASK, (~RTC_AL_MASK_HOU));
			BBPU |= (RTC_BBPU_ALARM_SW); /* 0227 TY adds */
			break;
	   
	   	case AL_EN_ChkDHMS:
			tmp |= RTC_IRQ_EN_AL;
			DRV_RTC_WriteReg(RTC_AL_MASK,(~RTC_AL_MASK_DOM));
			BBPU |=(RTC_BBPU_ALARM_SW); /* 0227 TY adds */
			break;
		
		case AL_EN_ChkWHMS:
			tmp |= RTC_IRQ_EN_AL;
			DRV_RTC_WriteReg(RTC_AL_MASK, (~RTC_AL_MASK_DOW));
			BBPU |= (RTC_BBPU_ALARM_SW); /* 0227 TY adds */
			break;
			
	   	case AL_EN_ChkMDHMS:
			tmp |= RTC_IRQ_EN_AL;
			DRV_RTC_WriteReg(RTC_AL_MASK, (~RTC_AL_MASK_MTH));
			BBPU |= (RTC_BBPU_ALARM_SW); /* 0227 TY adds */
			break;
			
	   	case AL_EN_ChkYMDHMS:
			tmp |= RTC_IRQ_EN_AL;
			DRV_RTC_WriteReg(RTC_AL_MASK, (~RTC_AL_MASK_YEA));
			BBPU |= (RTC_BBPU_ALARM_SW); /* 0227 TY adds */
			break;
			
	   	case AL_EN_NoChange:
	     	break;

		default:
			break;
	}

	switch(TC_EN)
	{
		case TC_EN_None:
			tmp &= ~RTC_IRQ_EN_TC;
			break;
		
		case TC_EN_ChkS:
			tmp |= RTC_IRQ_EN_TC;
			DRV_RTC_WriteReg(RTC_CII_EN, RTC_CII_EN_SEC);
			break;
		
		case TC_EN_ChkM:
			tmp |= RTC_IRQ_EN_TC;
			DRV_RTC_WriteReg(RTC_CII_EN, RTC_CII_EN_MIN);
			break;
			
	   	case TC_EN_ChkH:
			tmp |= RTC_IRQ_EN_TC;
			DRV_RTC_WriteReg(RTC_CII_EN, RTC_CII_EN_HOU);
			break;
		
		case TC_EN_ChkD:
			tmp |= RTC_IRQ_EN_TC;
			DRV_RTC_WriteReg(RTC_CII_EN, RTC_CII_EN_DOM);
			break;
		
		case TC_EN_ChkW:
			tmp |= RTC_IRQ_EN_TC;
			DRV_RTC_WriteReg(RTC_CII_EN, RTC_CII_EN_DOW);
			break;
			
		case TC_EN_ChkMon:
			tmp |= RTC_IRQ_EN_TC;
			DRV_RTC_WriteReg(RTC_CII_EN, RTC_CII_EN_MTH);
			break;
			
		case TC_EN_ChkY:
			tmp |= RTC_IRQ_EN_TC;
			DRV_RTC_WriteReg(RTC_CII_EN, RTC_CII_EN_YEA);
			break;
    
		case TC_EN_NoChange:
		 	break;
         
		default:
			break;
	}
	DRV_RTC_WriteReg(RTC_IRQ_EN, tmp);
	
	#if defined(DRV_RTC_WRITE_ENABLE)
	BBPU |= RTC_BBPU_WRITE_EN;
	#endif // #if defined(DRV_RTC_WRITE_ENABLE)
	
	DRV_RTC_WriteReg(RTC_BBPU, (BBPU | RTC_BBPU_KEY)); /* 0227 TY adds */
#if defined(DRV_RTC_HW_CALI)
   	DRV_RTC_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR);
   	// RTC_write_trigger();
#endif /* DRV_RTC_HW_CALI */
	RestoreIRQMask(savedMask);
	
#if defined(DRV_RTC_HW_CALI)
	RTC_wait_busy();
#endif /* DRV_RTC_HW_CALI */
	
}
#endif /* !defined(__FUE__) && !defined(__UBL__) */


extern kal_bool kal_query_systemInit(void);
// Return KAL_TRUE: OS is running, we can send ilm at this moment
// Return KAL_FALSE: OS is NOT running, we are called at boot time phase
kal_bool IsOSRunning(void){
	// kal_query_systemInit() return KAL_TRUE: System is at init phase
	// kal_query_systemInit() return KAL_FALSE: System is NOT at init phase
#ifdef __UBL__
  	return 0;
#else
	return (kal_bool)(!kal_query_systemInit());
#endif

}


/*
* FUNCTION                                                            
*	RTC_SaveTC_Time
*
* DESCRIPTION                                                           
*   	Setup the time
*
* CALLS  
*	This function is called to setup the time
*
* PARAMETERS
*	rtctime: the time.
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_SaveTC_Time(t_rtc *rtctime)
{
#if !defined(__FUE__) && !defined(__UBL__)
	kal_uint32 savedMask = 0;
#endif /* !defined(__FUE__) && !defined(__UBL__) */
#if !defined(DRV_RTC_HW_CALI)
	kal_uint32 loop = 0;
#endif /* DRV_RTC_HW_CALI */

	#if defined(DRV_RTC_HW_CALI) && !defined(__FUE__) && !defined(__UBL__)
	RTC_wait_busy();
	#endif
	
#if !defined(__FUE__) && !defined(__UBL__)
   	savedMask = SaveAndSetIRQMask();   
#endif /* !defined(__FUE__) && !defined(__UBL__) */

	/* update time */
	DRV_RTC_WriteReg(RTC_TC_SEC, rtctime->rtc_sec);
	DRV_RTC_WriteReg(RTC_TC_MIN, rtctime->rtc_min);
	DRV_RTC_WriteReg(RTC_TC_HOU, rtctime->rtc_hour);
	DRV_RTC_WriteReg(RTC_TC_DOM, rtctime->rtc_day);
	DRV_RTC_WriteReg(RTC_TC_DOW, rtctime->rtc_wday);
	DRV_RTC_WriteReg(RTC_TC_MTH, rtctime->rtc_mon);
	DRV_RTC_WriteReg(RTC_TC_YEA, rtctime->rtc_year);
	
#if !defined(__FUE__) && !defined(__UBL__)
	RestoreIRQMask(savedMask);
#endif /* !defined(__FUE__) && !defined(__UBL__) */
	
#if defined(DRV_RTC_HW_CALI)
   	RTC_write_trigger_wait();
#else /* DRV_RTC_HW_CALI */
	// for(loop = 0; loop < 1000; loop++){};
	// Use while loop with fields check instead of for loop
	// We compare each field until all the fields are what we set to RTC module
   	loop = 0;
   	while(1){
		if ( 
			(DRV_RTC_Reg(RTC_TC_SEC) == rtctime->rtc_sec) &&
			(DRV_RTC_Reg(RTC_TC_MIN) == rtctime->rtc_min) &&
			(DRV_RTC_Reg(RTC_TC_HOU) == rtctime->rtc_hour) &&
			(DRV_RTC_Reg(RTC_TC_DOM) == rtctime->rtc_day) &&
			(DRV_RTC_Reg(RTC_TC_MTH) == rtctime->rtc_mon) &&
			(DRV_RTC_Reg(RTC_TC_YEA) == rtctime->rtc_year) ){
			break;
      	}
		loop ++;
		if (loop >= 10000){
		 	// Warning: RTC may NOT complet the update
		 	break;
      	}
	}
	
#if !defined(LOW_COST_SUPPORT)
#if !defined(__FUE__) && !defined(__UBL__)
	drv_trace8(TRACE_GROUP_9, RTC_INIT_TC_TIME, rtctime->rtc_year, rtctime->rtc_mon,
		rtctime->rtc_day, rtctime->rtc_hour, rtctime->rtc_min, rtctime->rtc_sec, 0, 0);
#endif
#endif
#endif /* DRV_RTC_HW_CALI */
}

/*
* FUNCTION                                                            
*	RTC_InitTC_Time
*
* DESCRIPTION                                                           
*   	Setup the current time
*
* CALLS  
*	This function is called to setup the current time
*
* PARAMETERS
*	rtctime: the current time.
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_InitTC_Time(t_rtc *rtctime) // validate
{
#if !defined(__FUE__) && !defined(__UBL__)
     kal_bool   module_reg_ilm_flag = KAL_FALSE;
     kal_uint16 index;
	ilm_struct *RTC_ilm;
	RTC_Time_Change_IND_Struct *rtc_ind = NULL;
#endif //#if !defined(__FUE__) && !defined(__UBL__)

#if ( defined(__GPS_SUPPORT__) || defined(RTC_HW_CALIBRATION) )
#if !defined(LOW_COST_SUPPORT)
#if !defined(__FUE__) && !defined(__UBL__)
	if( RTC_is_Time_Valid(rtctime) == KAL_FALSE)
	{   
    	drv_trace8(TRACE_GROUP_9, RTC_IS_NOT_CONFIG_INVALID_TIME, rtctime->rtc_year, rtctime->rtc_mon,
        	rtctime->rtc_day, rtctime->rtc_hour, rtctime->rtc_min, rtctime->rtc_sec, 0, 0);
      	return;
   	}
#endif
#endif	
#endif // #if ( defined(__GPS_SUPPORT__) || defined(RTC_HW_CALIBRATION) )


	#if defined(DRV_RTC_HW_CALI) && !defined(__FUE__) && !defined(__UBL__)
	RTC_wait_busy();
	#endif   
   
#if defined(RTC_SW_CALIBRATION)
	if(rtc_timer_id!=0)
	{
		cali_state = (kal_uint8)CAL_STATE_RESET;
		kal_cancel_timer(rtc_timer_id);
	}	
#endif /* RTC_SW_CALIBRATION */
	
#if !defined(__FUE__) && !defined(__UBL__) // Indicate other tasks(ex:GPS) that the time is modified by upper layer

    if (IsOSRunning()) {
        index = 0;
        while( index < MODULE_REGISTER_ILM_MAX_NUM )
        {
            if (rtc_reg_mod_ilm_info[index].dest_mod_id != MOD_NIL)
            {
                module_reg_ilm_flag = KAL_TRUE;
                break;
            }
            index++;
        }

        if (module_reg_ilm_flag == KAL_TRUE)
        {
    		rtc_ind = (RTC_Time_Change_IND_Struct*)
    					construct_local_para(sizeof(RTC_Time_Change_IND_Struct), TD_CTRL);

    		// Save current time to message        
    		rtc_ind->previous_rtc.rtc_sec = DRV_RTC_Reg(RTC_TC_SEC);
    		rtc_ind->previous_rtc.rtc_min = DRV_RTC_Reg(RTC_TC_MIN);
    		rtc_ind->previous_rtc.rtc_hour = DRV_RTC_Reg(RTC_TC_HOU);
    		rtc_ind->previous_rtc.rtc_day = DRV_RTC_Reg(RTC_TC_DOM);
    		rtc_ind->previous_rtc.rtc_mon = DRV_RTC_Reg(RTC_TC_MTH);
    		rtc_ind->previous_rtc.rtc_year = DRV_RTC_Reg(RTC_TC_YEA);


        }
    }    
    
#endif //#if !defined(__FUE__) && !defined(__UBL__)

   	RTC_SaveTC_Time(rtctime);

#if !defined(__FUE__) && !defined(__UBL__) // Indicate other tasks(ex:GPS) that the time is modified by upper layer

    if (IsOSRunning()) {
        if (module_reg_ilm_flag == KAL_TRUE)
        {
            // Save new RTC time to message
            module_type module_id;

            rtc_ind->new_rtc.rtc_sec = DRV_RTC_Reg(RTC_TC_SEC);
            rtc_ind->new_rtc.rtc_min = DRV_RTC_Reg(RTC_TC_MIN);
            rtc_ind->new_rtc.rtc_hour = DRV_RTC_Reg(RTC_TC_HOU);
            rtc_ind->new_rtc.rtc_day = DRV_RTC_Reg(RTC_TC_DOM);
            rtc_ind->new_rtc.rtc_mon = DRV_RTC_Reg(RTC_TC_MTH);
            rtc_ind->new_rtc.rtc_year = DRV_RTC_Reg(RTC_TC_YEA);

            if(KAL_TRUE == kal_if_hisr())
            {
                module_id = MOD_DRV_HISR;
            }
            else
            {
                module_id = stack_get_active_module_id();
            }

            index = 0;
            while( index < MODULE_REGISTER_ILM_MAX_NUM )
            {
                if (rtc_reg_mod_ilm_info[index].dest_mod_id != MOD_NIL)
                {
            #if 0                 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #else // use new KAL message passing API
                    msg_send5(module_id, rtc_reg_mod_ilm_info[index].dest_mod_id, 
                            rtc_reg_mod_ilm_info[index].sap_id, rtc_reg_mod_ilm_info[index].msg_id, (local_para_struct*)rtc_ind); 
            #endif
                }
                index++;
            }
            
        }                    
    }
 
#endif //#if !defined(__FUE__) && !defined(__UBL__)

#if defined(RTC_HW_CALIBRATION)
	// For H/W calibration case, we only enable calibration process when OS is running case
	// Or the calibration process may modify RTC register values to unexpected value during boot time
	if (IsOSRunning()){
		cali_state = (kal_uint8)CAL_STATE_NONE;
		rtc_cali_init(0);
	}
#elif defined(RTC_SW_CALIBRATION)
	/* reset calibration, start after rtc initialization */
	if(rtc_timer_id!=0)
	{
		next_current_time = *rtctime;
		rtc_cali_init((void *)rtc_timer_id);
		
		/* save current time to nvram */
		rtc_nvram_s.time_valid = KAL_TRUE;
		rtc_nvram_s.rtc_time = next_current_time;
		rtc_write_to_nvram();
	}	
#endif /* RTC_SW_CALIBRATION */
	
	#ifdef RTC_Test
	RTC_delay();
	#endif
}

#if !defined(__FUE__) && !defined(__UBL__)

/*
* FUNCTION                                                            
*	RTC_Set_Module_ILM_Info
*
* DESCRIPTION                                                           
*   	RTC save the ILM information form other modules.
*
* CALLS  
*	This function is called to save ILM by other modules.
*
* PARAMETERS
*	Module_ilm_info: Other module ILM information.
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool RTC_Set_Module_ILM_Info(RTC_REG_MODULE_ILM_INFO_T *Module_ilm_info)
{
    kal_uint16 index = 0;

    /* After system init is ok, module could register ILM to RTC. 
       If system init isn't ok, we have to assert for module register ILM.
    */
    if (IsOSRunning() == KAL_FALSE)
    {
        ASSERT(0);
    }
    
    while( index < MODULE_REGISTER_ILM_MAX_NUM )
    {
        if (rtc_reg_mod_ilm_info[index].dest_mod_id == MOD_NIL)
        {
            rtc_reg_mod_ilm_info[index].dest_mod_id = Module_ilm_info->dest_mod_id;
            rtc_reg_mod_ilm_info[index].msg_id = Module_ilm_info->msg_id;
            rtc_reg_mod_ilm_info[index].sap_id = Module_ilm_info->sap_id;
            return KAL_TRUE;
        }
        index++;
    }
    
    return KAL_FALSE;
}

#endif

#if defined(RTC_SW_CALIBRATION)
/*
* FUNCTION                                                            
*	RTC_Cali_Time
*
* DESCRIPTION                                                           
*   	update the current time
*
* CALLS  
*	This function is to update the current time
*
* PARAMETERS
*	rtctime: the current time.
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_Cali_Time(t_rtc *rtctime)		//validate
{   
#if ( defined(__GPS_SUPPORT__) || defined(RTC_HW_CALIBRATION) )
#if !defined(LOW_COST_SUPPORT)
#if !defined(__FUE__) && !defined(__UBL__)
	if( RTC_is_Time_Valid(rtctime) == KAL_FALSE)
	{   
		drv_trace8(TRACE_GROUP_9, RTC_IS_NOT_CONFIG_INVALID_TIME, rtctime->rtc_year, rtctime->rtc_mon,
			rtctime->rtc_day, rtctime->rtc_hour, rtctime->rtc_min, rtctime->rtc_sec, 0, 0);
		return;
	}
#endif
#endif	
#endif // #if ( defined(__GPS_SUPPORT__) || defined(RTC_HW_CALIBRATION) )

	/* update time */
	DRV_RTC_WriteReg(RTC_TC_SEC, rtctime->rtc_sec);
	DRV_RTC_WriteReg(RTC_TC_MIN, rtctime->rtc_min);
	DRV_RTC_WriteReg(RTC_TC_HOU, rtctime->rtc_hour);
	DRV_RTC_WriteReg(RTC_TC_DOM, rtctime->rtc_day);
	DRV_RTC_WriteReg(RTC_TC_MTH, rtctime->rtc_mon);
	DRV_RTC_WriteReg(RTC_TC_YEA, rtctime->rtc_year);	
#if !defined(LOW_COST_SUPPORT)
#if !defined(__FUE__) && !defined(__UBL__)
	drv_trace8(TRACE_GROUP_9, RTC_CALI_TIME, rtctime->rtc_year, rtctime->rtc_mon,
    	rtctime->rtc_day, rtctime->rtc_hour, rtctime->rtc_min, rtctime->rtc_sec, 0, 0);
#endif
#endif
}

/*
* FUNCTION                                                            
*	RTC_Check_Alarm
*
* DESCRIPTION                                                           
*   	check if alarm expires after calibrating time
*
* CALLS  
*	This function is to check if alarm expires after calibrating time
*
* PARAMETERS
*	rtctime: the current time.
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_Check_Alarm(t_rtc rtctime) // validate
{   
	kal_uint8 irq = 0;
	t_rtc alarm_time, current_time;
	kal_uint32 alarm_sec = 0, current_sec = 0, new_time = 0;

   	irq = DRV_RTC_Reg(RTC_IRQ_EN);
    /* configure alarm or not */
	if(irq & RTC_IRQ_EN_AL)
	{
		RTC_GetALTime(&alarm_time);
		RTC_GetTime_(&current_time);
		if(alarm_time.rtc_hour == 0)
			alarm_sec = (kal_uint32)(24 * 3600 + alarm_time.rtc_min * 60 + alarm_time.rtc_sec);
		else
		 	alarm_sec = (kal_uint32)(alarm_time.rtc_hour * 3600 + alarm_time.rtc_min * 60 + alarm_time.rtc_sec);
		if(current_time.rtc_hour == 0)
			current_sec = (kal_uint32)(24 * 3600 + current_time.rtc_min * 60 + current_time.rtc_sec);
		else
		 	current_sec = (kal_uint32)(current_time.rtc_hour * 3600 + current_time.rtc_min * 60 + current_time.rtc_sec);   
		
		/* exceed alarm or not */         
		if(current_sec < alarm_sec)            
		{
			if(rtctime.rtc_hour == 0)
		    	new_time=(kal_uint32)(24 * 3600 + rtctime.rtc_min * 60 + rtctime.rtc_sec);
		 	else
		    	new_time=(kal_uint32)(rtctime.rtc_hour * 3600 + rtctime.rtc_min * 60 + rtctime.rtc_sec);   
		 	/* change alarm or not */   
			if(new_time >= alarm_sec)               
			{
				RTC_SetAlarm(&rtctime);
			}   
		}   
	}	   
}
#endif /* RTC_SW_CALIBRATION */

/*
* FUNCTION                                                            
*	RTC_GetTime_
*
* DESCRIPTION                                                           
*   	Obtain the current time
*
* CALLS  
*	This function is called to obtain the current time
*
* PARAMETERS
*	rtctime: the current time.
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_GetTime_(t_rtc *rtctime) // validate
{
#if !defined(__FUE__) && !defined(__UBL__)
	kal_uint32 savedMask;
#endif /* !defined(__FUE__) && !defined(__UBL__) */
	t_rtc rtc_InitTime;
   
	RTC_GetTimeOnly(rtctime);

// check the RTC validation, 
#if ( defined(__GPS_SUPPORT__) || defined(RTC_HW_CALIBRATION) )
	if( RTC_is_Time_Valid(rtctime) == KAL_FALSE)
	{   
		if( IsOSRunning() && (RTC_isFisrtOn() == KAL_FALSE))
		{
#if defined(__MTK_INTERNAL__)            
			rtc_InitTime.rtc_sec  = 1;
			rtc_InitTime.rtc_min  = rtc_InitTime.rtc_sec; // try avoid warning #177-D: variable was declared but never referenced
			rtc_InitTime.rtc_hour = 1;
			rtc_InitTime.rtc_day  = 1;
			rtc_InitTime.rtc_wday = 1;
			rtc_InitTime.rtc_mon  = 1;
			rtc_InitTime.rtc_year = 1;
			RTC_SaveTC_Time(&rtc_InitTime); // Avoid ASSERT again when TST call rtc get time.
			ASSERT(0);
#endif            
			rtctime->rtc_sec  = RTCTimer.rtc_sec;
			rtctime->rtc_min  = RTCTimer.rtc_min;
			rtctime->rtc_hour = RTCTimer.rtc_hour;
			rtctime->rtc_day  = RTCTimer.rtc_day;
			rtctime->rtc_wday = RTCTimer.rtc_wday;
			rtctime->rtc_mon  = RTCTimer.rtc_mon;
			rtctime->rtc_year = RTCTimer.rtc_year;
			RTC_InitTC_Time(rtctime);
		}
	}

#if !defined(__FUE__) && !defined(__UBL__)
    savedMask = SaveAndSetIRQMask();   
#endif //#if !defined(__FUE__) && !defined(__UBL__)
	// Save latest correct rtc time, 
	// Once rtc HW timer has any error, restore the latest value
	RTCTimer.rtc_sec  = rtctime->rtc_sec;  
	RTCTimer.rtc_min  = rtctime->rtc_min;
	RTCTimer.rtc_hour = rtctime->rtc_hour;
	RTCTimer.rtc_day  = rtctime->rtc_day;
	RTCTimer.rtc_wday = rtctime->rtc_wday;
	RTCTimer.rtc_mon  = rtctime->rtc_mon;
	RTCTimer.rtc_year = rtctime->rtc_year;
#if !defined(__FUE__) && !defined(__UBL__)
    RestoreIRQMask(savedMask);
#endif // #if !defined(__FUE__) && !defined(__UBL__)

#endif // #if ( defined(__GPS_SUPPORT__) || defined(RTC_HW_CALIBRATION) )
}

/*
* FUNCTION                                                            
*	RTC_GetTimeOnly
*
* DESCRIPTION                                                           
*   	Obtain the current time
*
* CALLS  
*	This function is called to obtain the current time
*
* PARAMETERS
*	rtctime: the current time.
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_GetTimeOnly(t_rtc *rtctime) // validate
{
#if !defined(__FUE__) && !defined(__UBL__)
	kal_uint32 savedMask;

	#if defined(DRV_RTC_HW_CALI)
	RTC_wait_busy();
	#endif   

   	savedMask = SaveAndSetIRQMask();   
#endif /* !defined(__FUE__) && !defined(__UBL__) */
	rtctime->rtc_sec = DRV_RTC_Reg(RTC_TC_SEC);
	rtctime->rtc_min = DRV_RTC_Reg(RTC_TC_MIN);
	rtctime->rtc_hour = DRV_RTC_Reg(RTC_TC_HOU);
	rtctime->rtc_day = DRV_RTC_Reg(RTC_TC_DOM);
	rtctime->rtc_mon = DRV_RTC_Reg(RTC_TC_MTH);
	rtctime->rtc_wday = DRV_RTC_Reg(RTC_TC_DOW);
	rtctime->rtc_year = DRV_RTC_Reg(RTC_TC_YEA);
#if !defined(__FUE__) && !defined(__UBL__)
	RestoreIRQMask(savedMask);
	#ifdef RTC_Test
	RTC_delay();
	#endif
#endif /* !defined(__FUE__) && !defined(__UBL__) */
}

/*
* FUNCTION                                                            
*	RTC_SetAlarm
*
* DESCRIPTION                                                           
*   	Setup the alarm time
*
* CALLS  
*	This function is called to setup the alarm time
*
* PARAMETERS
*	rtctime: the expected alarm time.
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_SetAlarm(t_rtc *rtctime )		//validate 
{
	kal_uint32 loop;
#if !defined(__FUE__) && !defined(__UBL__)
	// kal_uint32 savedMask=0;
	// savedMask = SaveAndSetIRQMask();
#endif /* !defined(__FUE__) && !defined(__UBL__) */
	
	#if defined(DRV_RTC_HW_CALI) && !defined(__FUE__) && !defined(__UBL__)
	RTC_wait_busy();
	#endif

	/* Add for loop to ensure that RTC alarm time has been written in. */
	for (loop = 0; loop < 1000000; loop++)
	{
		DRV_RTC_WriteReg(RTC_AL_SEC,rtctime->rtc_sec);
		DRV_RTC_WriteReg(RTC_AL_MIN,rtctime->rtc_min);
		DRV_RTC_WriteReg(RTC_AL_HOU,rtctime->rtc_hour);
		DRV_RTC_WriteReg(RTC_AL_DOM,rtctime->rtc_day);
		DRV_RTC_WriteReg(RTC_AL_MTH,rtctime->rtc_mon);
		DRV_RTC_WriteReg(RTC_AL_YEA,rtctime->rtc_year);
		#if defined(DRV_RTC_HW_CALI)
		RTC_write_trigger_wait();
		#endif /*DRV_RTC_HW_CALI*/
		if ((DRV_RTC_Reg(RTC_AL_SEC) == rtctime->rtc_sec) && (DRV_RTC_Reg(RTC_AL_MIN) == rtctime->rtc_min)
		 && (DRV_RTC_Reg(RTC_AL_HOU) == rtctime->rtc_hour) && (DRV_RTC_Reg(RTC_AL_DOM) == rtctime->rtc_day)
		 && (DRV_RTC_Reg(RTC_AL_MTH) == rtctime->rtc_mon) && (DRV_RTC_Reg(RTC_AL_YEA) == rtctime->rtc_year))
			break;
	}
#if !defined(__FUE__) && !defined(__UBL__)
    // RestoreIRQMask(savedMask);
	#ifdef RTC_Test
	RTC_delay();
	#endif
#endif /* !defined(__FUE__) && !defined(__UBL__) */
#if !defined(LOW_COST_SUPPORT)
#if !defined(__FUE__) && !defined(__UBL__)
	drv_trace8(TRACE_GROUP_9, RTC_SET_ALARM, rtctime->rtc_year, rtctime->rtc_mon,
			rtctime->rtc_day, rtctime->rtc_hour, rtctime->rtc_min, rtctime->rtc_sec, 0, 0);
#endif
#endif
}

/*
* FUNCTION                                                            
*	RTC_GetALTime
*
* DESCRIPTION                                                           
*   	Obtain the alarm time
*
* CALLS  
*	This function is called to obtain the alarm time setting
*
* PARAMETERS
*	rtctime: the alarm time.
*	
* RETURNS
*	return the status of AL enable bit of RTC_IRQ_EN
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool RTC_GetALTime(t_rtc *rtctime) // Validate
{
	kal_uint16 IRQ_En;    
	
	#if defined(DRV_RTC_HW_CALI) && !defined(__FUE__) && !defined(__UBL__)
	RTC_wait_busy();
	#endif   
	
#if defined(DRV_RTC_W_FLAG)
	while (DRV_RTC_Reg(RTC_IRQ_EN) & 0x8000){;};
#endif // #if defined(DRV_RTC_W_FLAG)

	IRQ_En = DRV_RTC_Reg(RTC_IRQ_EN);	
	
	rtctime->rtc_sec = DRV_RTC_Reg(RTC_AL_SEC);
	rtctime->rtc_min = DRV_RTC_Reg(RTC_AL_MIN);
	rtctime->rtc_hour = DRV_RTC_Reg(RTC_AL_HOU);
	rtctime->rtc_day = DRV_RTC_Reg(RTC_AL_DOM);
	rtctime->rtc_mon = DRV_RTC_Reg(RTC_AL_MTH);
	rtctime->rtc_wday = DRV_RTC_Reg(RTC_AL_DOW);
	rtctime->rtc_year = DRV_RTC_Reg(RTC_AL_YEA);
	#ifdef RTC_Test
	RTC_delay();
	#endif

#if !defined(LOW_COST_SUPPORT)
#if !defined(__FUE__) && !defined(__UBL__)
  	drv_trace8(TRACE_GROUP_8, RTC_GET_AL_TIME, rtctime->rtc_year, rtctime->rtc_mon,
            rtctime->rtc_day, rtctime->rtc_hour, rtctime->rtc_min, rtctime->rtc_sec, 0, 0);
#endif
#endif	

    return (kal_bool)(IRQ_En & RTC_IRQ_EN_AL);    
}

#if !defined(__FUE__) && !defined(__UBL__)
//=================================================================
/*
* FUNCTION                                                            
*	RTC_HISR
*
* DESCRIPTION                                                           
*   	RTC interrupt handler
*
* CALLS  
*	This function is called when RTC intr. is coming
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_HISR(void)
{
	kal_uint16 status;

#if defined(DRV_RTC_PWRON_BBPU_POLARITY)
	kal_uint16 BBPU;
	kal_uint16 POLAR;
	kal_uint16 PWRSW;
	
	BBPU = DRV_RTC_Reg(RTC_BBPU);
	POLAR = BBPU & RTC_BBPU_PWR_POLARITY;
	POLAR >>= 1;
	PWRSW = BBPU & RTC_BBPU_PWR_SW;
	#if defined(DRV_RTC_BBPU_AS_6205)
	PWRSW >>= 2;
	#else /* !MT6205 */
	PWRSW >>= 4;
	#endif /* MT6205 */

	if (POLAR != PWRSW)
	{
		#ifndef __L1_STANDALONE__
		IRQMask(IRQ_RTC_CODE);
		ASSERT(0);
		return;
		#endif /*__L1_STANDALONE__*/
	}
#endif /* DRV_RTC_PWRON_BBPU_POLARITY */ 

#if 0 /* remove this part because rtc initialization is before latch power */
#if defined(DRV_RTC_PWRON_BBPU_SW)
/* under construction !*/
/* under construction !*/
		#ifndef __L1_STANDALONE__
/* under construction !*/
/* under construction !*/
		#endif /* __L1_STANDALONE__ */
/* under construction !*/
#endif /* DRV_RTC_PWRON_BBPU_SW */
#endif 
   
	status = DRV_RTC_Reg(RTC_IRQ_STATUS);
	if (status & RTC_IRQ_STATUS_AL_STAT)
	{
		RTC_CALLBAC.rtc_alfunc();	
     	#if defined(RTC_AS_MT6218)
		// set AUTO_PDN bit of RTC_BBPU again which is cleared by RTC 
		{
			kal_uint16 reg;
			
			reg = DRV_RTC_Reg(RTC_BBPU);
			reg |= (RTC_BBPU_KEY|RTC_BBPU_AUTOPDN); 
			DRV_RTC_WriteReg(RTC_BBPU, reg );
			#if defined(DRV_RTC_HW_CALI)
			RTC_write_trigger();
			#endif /*DRV_RTC_HW_CALI*/
		}		
		#endif		
	}
	if (status & RTC_IRQ_STATUS_TC_STAT)
	{
		RTC_CALLBAC.rtc_tcfunc();
		#if defined(DRV_RTC_HW_CALI)
		RTC_write_trigger();
		#endif /* DRV_RTC_HW_CALI */		
	}
	
#if defined(DRV_RTC_LOW_POWER_DETECT)
	if (status & RTC_IRQ_STATUS_LP_STAT)
	{
		// it should not happen
		ASSERT(0);
	}
#endif // defined(DRV_RTC_LOW_POWER_DETECT)
	
	IRQClearInt(IRQ_RTC_CODE);
	IRQUnmask(IRQ_RTC_CODE);
}

void RTC_LISR(void)
{
	IRQMask(IRQ_RTC_CODE);
	// kal_activate_hisr(RTCConfig.hisr);
	drv_active_hisr(DRV_RTC_HISR_ID);
}
#endif /* !defined(__FUE__) && !defined(__UBL__) */

/*
* FUNCTION                                                            
*	RTC_isFisrtOn
*
* DESCRIPTION                                                           
*   	Check whether RTC is first on
*
* CALLS  
*	This function is called to check whether RTC is first on
*
* PARAMETERS
*	None
*	
* RETURNS
*	KAL_TRUE: RTC is first on
*	KAL_FALSE: RTC is not first on
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool RTC_isFisrtOn(void)        //validate
{
    kal_uint16 key1 = DRV_RTC_Reg(RTC_POWERKEY1);
    kal_uint16 key2 = DRV_RTC_Reg(RTC_POWERKEY2);
#if defined(DRV_RTC_LOW_POWER_DETECT)
    kal_uint16 LPD = DRV_RTC_Reg(RTC_GPIO) & RTC_GPIO_LPSTA_RAW;
#endif //#if defined(DRV_RTC_LOW_POWER_DETECT)

#if defined(DRV_RTC_INTERNAL_32K_SWITCH_FAIL_DETECT)
    kal_uint16 EMBCK_switch_fail_fg = DRV_RTC_Reg(RTC_GPIO) & RTC_GPIO_EMBCK_SWITCH_FAIL;

    DCL_HANDLE f32k_handler;
    F32K_CLK_CTRL_F32K_IS_XOSC32_T IsXOSC32K;
    
    f32k_handler = DclF32K_Open(DCL_F32K_CLK, FLAGS_NONE);
    DclF32K_Control(f32k_handler, F32K_CLK_CMD_QUERY_IS_XOSC32K, (DCL_CTRL_DATA_T *)&IsXOSC32K);
    DclF32K_Close(f32k_handler);
                  
    if (IsXOSC32K.f32k_is_xosc32)
    {
        EMBCK_switch_fail_fg = 0;
    }
#endif //#if defined(DRV_RTC_INTERNAL_32K_SWITCH_FAIL_DETECT)
	
#if defined(DRV_RTC_REG_COMM)
    // save the original RTC_PDN1 value, otherwise pwic may modify it. (for DVT test)
    originalPDN1 = DRV_RTC_Reg(RTC_INFO1);
#endif
#ifdef RTC_RESTORE_REGISTER_VALUES_FOR_DVT
    u2dvt_info1_reg_value = DRV_RTC_Reg(RTC_INFO1);
    u2dvt_rtc_seconds_value = DRV_RTC_Reg(RTC_TC_SEC);
    u2dvt_rtc_minutes_value = DRV_RTC_Reg(RTC_TC_MIN);
    u2dvt_rtc_hours_value = DRV_RTC_Reg(RTC_TC_HOU);
    u2dvt_rtc_bbpu_reg_value = DRV_RTC_Reg(RTC_BBPU);
#endif
    
    if ((key1 == RTC_POWERKEY1_KEY) && (key2 == RTC_POWERKEY2_KEY)
#if defined(DRV_RTC_LOW_POWER_DETECT)
        &&(LPD == 0)
#endif //#if defined(DRV_RTC_LOW_POWER_DETECT)
#if defined(DRV_RTC_INTERNAL_32K_SWITCH_FAIL_DETECT)
        &&(EMBCK_switch_fail_fg == 0)
#endif //#if defined(DRV_RTC_INTERNAL_32K_SWITCH_FAIL_DETECT)
    )
    {
        /* TY adds this 2004/10/21 to record this is first power on */
        // First_PowerOn = KAL_FALSE;
        return KAL_FALSE;
    }
    else
    {
        /* TY adds this 2004/10/21 to record if this is first power on */
#if !defined(__FUE__) && !defined(__UBL__)
        First_PowerOn = KAL_TRUE;
#endif //#if !defined(__FUE__) && !defined(__UBL__)
        return KAL_TRUE;
    }
}

#if !defined(__FUE__) && !defined(__UBL__)
/*
* FUNCTION                                                            
*	RTC_is_MS_FirstPowerOn_
*
* DESCRIPTION                                                           
*   	Check whether RTC is first power on
*
* CALLS  
*	This function is called by MMI. MMI wants to knows this status
*  whenever he wants but the function "RTC_isFisrtOn" is only valid
*  before calling DRV_POWERON function
*
* PARAMETERS
*	None
*	
* RETURNS
*	KAL_TRUE: RTC is first on
*	KAL_FALSE: RTC is not first on
*
* GLOBALS AFFECTED
*   external_global
*/
/* TY adds this 2004/10/21 to record if this is first power on */	   
kal_bool RTC_is_MS_FirstPowerOn_(void) // validate
{
	if (First_PowerOn ==KAL_FALSE)
	{	   
		return KAL_FALSE;
	}
	else
	{	   
		return KAL_TRUE;
	}
}

void RTC_set_First_PowerOn(kal_bool isFirstPowerOn)
{
	First_PowerOn = isFirstPowerOn;
}
#endif /* !defined(__FUE__) && !defined(__UBL__) */

/*
* FUNCTION                                                            
*	RTC_setXOSC_
*
* DESCRIPTION                                                           
*   	Setup RTC XOSC register, 
*     We have to set XOSC earlier in drv_init_phase1(), that's the purpose of this API
*
* CALLS  
*	This function is called in every booting sequence
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_setXOSC_(void)
{
    kal_uint16 reg_val = 0xf;

	//#if defined(DRV_RTC_XOSC_DEF_10) // for MT6253 XOSC need to set before set power key.
	kal_uint16 key1 = DRV_RTC_Reg(RTC_POWERKEY1);
	kal_uint16 key2 = DRV_RTC_Reg(RTC_POWERKEY2);
	//#endif

	#if defined(DRV_RTC_HW_CALI) && !defined(__FUE__) && !defined(__UBL__)
	RTC_wait_busy();
	#endif   

    // Unlock RTC Protect
    RTC_unlockPROT();

	#if defined(DRV_RTC_XOSC_DEF_10) // for MT6253 XOSC need to set before set power key.
	if ((key1 != RTC_POWERKEY1_KEY) || (key2 != RTC_POWERKEY2_KEY))
	{
		reg_val = 0x10;
	}
	// After PWRKEY is configured to correct setting, set RTC XOSCCALI register
	// This register is to control XOU swing
	// some chips need to set XOSC after set power key.
	// when PWRKEY is NOT matched, the write operation of XOCCALI register will be failed
	// we still do below operations in RTC_setPWRKey(), in case write failed.
	#elif defined(DRV_RTC_XOSC_DEF_7)
	reg_val = 0x7;		
	#elif defined(DRV_RTC_XOSC_DEF_8)
	reg_val = 0x8;
	#elif defined(DRV_RTC_XOSC_DEF_0)
	reg_val = 0x0;
	#elif defined(DRV_RTC_XOSC_DEF_B)
	reg_val = 0xB;
	#elif defined(DRV_RTC_XOSC_DEF_C)
	reg_val = 0xC;
	#elif defined(DRV_RTC_XOSC_DEF_D)
	reg_val = 0xD;
    #elif defined(DRV_RTC_XOSC_DEF_F)
    reg_val = 0xF;
    #elif defined(DRV_RTC_XOSC_DEF_10F)
    reg_val = 0x10F;
	#else // #if defined(DRV_RTC_XOSC_DEF_8)
	reg_val = 0x1f;
	#endif // #if defined(DRV_RTC_XOSC_DEF_10)

    #if defined(DRV_RTC_INTERNAL_32K_AS_6255)
    { 

        DCL_HANDLE f32k_handler;
        F32K_CLK_CTRL_F32K_IS_XOSC32_T IsXOSC32K;

        f32k_handler = DclF32K_Open(DCL_F32K_CLK, FLAGS_NONE);        
        DclF32K_Control(f32k_handler, F32K_CLK_CMD_QUERY_IS_XOSC32K, (DCL_CTRL_DATA_T *)&IsXOSC32K);
               
        if (IsXOSC32K.f32k_is_xosc32)
        {
            reg_val |= RTC_OSC32_EOSC_CHOP_EN; //set EOSC_CHOP_EN=1
        }
        else
        {
            reg_val = DRV_RTC_Reg(RTC_XOSCCAL);
            if ((key1 == RTC_POWERKEY1_KEY) && (key2 == RTC_POWERKEY2_KEY))
            {                
                F32K_CLK_CTRL_EOSC32_CALI_VAL_T EOSC32Cali;                
                DclF32K_Control(f32k_handler, F32K_CLK_CMD_EOSC32_TRIMMING, (DCL_CTRL_DATA_T *)&EOSC32Cali);
		       /*
                * RTC_OSC32_AMP_EN: valid bit in MT6255
                *                   reserved bit in MT6250
                */
                #if defined(DRV_F32K_EOSC32_AS_6255)
                reg_val = (RTC_OSC32_EOSC_CHOP_EN | RTC_OSC32_AMP_EN | RTC_OSC32_XOSC32_ENB | EOSC32Cali.eosc32_cali_val);
                #elif defined(DRV_F32K_EOSC32_AS_6250)
                reg_val = (RTC_OSC32_EOSC_CHOP_EN | RTC_OSC32_XOSC32_ENB | EOSC32Cali.eosc32_cali_val);
                #endif
            }
        }

        DclF32K_Close(f32k_handler);        
    }
    #endif //#if defined(DRV_RTC_INTERNAL_32K_AS_6255)

	#if defined(DRV_RTC_XOSC_UPDATE)
	DRV_RTC_WriteReg(RTC_XOSCCAL, 0x1a57);
	while(DRV_RTC_Reg(RTC_BBPU) & 0x40);
	DRV_RTC_WriteReg(RTC_XOSCCAL, 0x2b68);
	while(DRV_RTC_Reg(RTC_BBPU) & 0x40);	
	#endif /* defined(DRV_RTC_XOSC_UPDATE) */

    DRV_RTC_WriteReg(RTC_XOSCCAL, reg_val);
          
	#if defined(DRV_RTC_XOSC_UPDATE)
	while(DRV_RTC_Reg(RTC_BBPU) & 0x40);
	#endif /* defined(DRV_RTC_XOSC_UPDATE) */
	
	#if defined(DRV_RTC_HW_CALI)
	RTC_write_trigger_wait();
	#endif // #if defined(DRV_RTC_HW_CALI)
	
	#if defined(DRV_RTC_XOSC_UPDATE)
	#if defined(DRV_RTC_HW_CALI)
	RTC_reload();
	#endif /* defined(DRV_RTC_HW_CALI) */
	#endif /* defined(DRV_RTC_XOSC_UPDATE) */	
}


/*
* FUNCTION                                                            
*	RTC_setPWRKey
*
* DESCRIPTION                                                           
*   	Setup RTC power key
*
* CALLS  
*	This function is called when RTC is first on
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_setPWRKey(void) // Validate
{
    kal_uint16 reg_val = 0xf;
     
	#if defined(DRV_RTC_HW_CALI) && !defined(__FUE__) && !defined(__UBL__)
	RTC_wait_busy();
	#endif   
	
	DRV_RTC_WriteReg(RTC_POWERKEY1, RTC_POWERKEY1_KEY);
	DRV_RTC_WriteReg(RTC_POWERKEY2, RTC_POWERKEY2_KEY);
	
	#if defined(DRV_RTC_HW_CALI)
	RTC_write_trigger_wait();
	#endif // #if defined(DRV_RTC_HW_CALI)
	
	// After PWRKEY is configured to correct setting, set RTC XOSCCALI register
	// This register is to control XOU swing
	// but when PWRKEY is NOT matched, the write operation of XOCCALI register will be failed
    #if defined(DRV_RTC_XOSC_DEF_8)
        reg_val = 0x8;
    #elif defined(DRV_RTC_XOSC_DEF_7)
        reg_val = 0x7;		
    #elif defined(DRV_RTC_XOSC_DEF_B)
        reg_val = 0xB;
    #elif defined(DRV_RTC_XOSC_DEF_C)
        reg_val = 0xC;
    #elif defined(DRV_RTC_XOSC_DEF_D)
        reg_val = 0xD;
    #elif defined(DRV_RTC_XOSC_DEF_0)
        reg_val = 0x0;
    #elif defined(DRV_RTC_XOSC_DEF_F)
        reg_val = 0xF;    
    #elif defined(DRV_RTC_XOSC_DEF_10)
        reg_val = 0x10;
    #elif defined(DRV_RTC_XOSC_DEF_10F)
        reg_val = 0x10F;
    #else // #if defined(DRV_RTC_XOSC_DEF_8)
        reg_val = 0x1f;
    #endif // #if defined(DRV_RTC_XOSC_DEF_8)

    #if defined(DRV_RTC_INTERNAL_32K_AS_6255)
    { 

        DCL_HANDLE f32k_handler;
        F32K_CLK_CTRL_F32K_IS_XOSC32_T IsXOSC32K;

        f32k_handler = DclF32K_Open(DCL_F32K_CLK, FLAGS_NONE);
        DclF32K_Control(f32k_handler, F32K_CLK_CMD_QUERY_IS_XOSC32K, (DCL_CTRL_DATA_T *)&IsXOSC32K);

        if (IsXOSC32K.f32k_is_xosc32)    
        {
            reg_val |= RTC_OSC32_EOSC_CHOP_EN; //set EOSC_CHOP_EN=1
        }
        else
        {
            reg_val = DRV_RTC_Reg(RTC_XOSCCAL);           
        }
        
        DclF32K_Close(f32k_handler);        
    }
    #endif //#if defined(DRV_RTC_INTERNAL_32K_AS_6255)

	#if defined(DRV_RTC_XOSC_UPDATE)
	DRV_RTC_WriteReg(RTC_XOSCCAL, 0x1a57);
	while(DRV_RTC_Reg(RTC_BBPU) & 0x40);
	DRV_RTC_WriteReg(RTC_XOSCCAL, 0x2b68);
	while(DRV_RTC_Reg(RTC_BBPU) & 0x40);	
	#endif /* defined(DRV_RTC_XOSC_UPDATE) */

    DRV_RTC_WriteReg(RTC_XOSCCAL, reg_val);
    
	#if defined(DRV_RTC_XOSC_UPDATE)
	while(DRV_RTC_Reg(RTC_BBPU) & 0x40);
	#endif /* defined(DRV_RTC_XOSC_UPDATE) */
   
	#if defined(DRV_RTC_HW_CALI)
	RTC_write_trigger_wait();
	#endif // #if defined(DRV_RTC_HW_CALI)
	
	#if defined(DRV_RTC_XOSC_UPDATE)
	#if defined(DRV_RTC_HW_CALI)
	RTC_reload();
	#endif /* defined(DRV_RTC_HW_CALI) */
	#endif /* defined(DRV_RTC_XOSC_UPDATE) */	
}

/*
* FUNCTION                                                            
*	RTC_unlockPROT
*
* DESCRIPTION                                                           
*   Unlock RTC PROT
*
* CALLS  
*   This function is called in every booting sequence before first setting RTC register.
*   Ex: RTC_OSC32CON, RTC_PDN2 
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_unlockPROT(void)
{
	#if defined(DRV_RTC_PROTECT1)
	DRV_RTC_WriteReg(RTC_PROT, RTC_PROTECT1);
	DRV_RTC_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR);
	while(DRV_RTC_Reg(RTC_BBPU) & 0x40);
	#endif // #if defined(DRV_RTC_PROTECT1)
	
	#if defined(DRV_RTC_PROTECT2)
	DRV_RTC_WriteReg(RTC_PROT, RTC_PROTECT2);
	DRV_RTC_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR);
	while(DRV_RTC_Reg(RTC_BBPU) & 0x40);
	#endif // #if defined(DRV_RTC_PROTECT2)
}


#if !defined(__FUE__) && !defined(__UBL__)

#if defined(RTC_HW_CALIBRATION)
/*
* FUNCTION                                                            
*	rtc_get_cali_offset
*
* DESCRIPTION                                                           
*   	To get the repeat calibration count value from register
*
* CALLS  
*	This function is called when doing RTC HW calibration
*
* PARAMETERS
*	None
*	
* RETURNS
*	the calibration count:  -0x40~0x3f (-64~63)
*
* GLOBALS AFFECTED
*   external_global
*/
kal_int8 rtc_get_cali_offset(void)
{
   kal_uint16 data;
   kal_int8 ret_val = 0;

   data = DRV_RTC_Reg(RTC_CALI);
   if (data & 0x0040)
   {
		ret_val = (kal_int8)((~(data) + 1) & 0x007f);
		ret_val = -ret_val;
   }
   else
   {
      	ret_val = (kal_int8)data;
   }
   return ret_val;
}

/*
* FUNCTION                                                            
*	rtc_do_repeat_cali
*
* DESCRIPTION                                                           
*   	To set the repeat calibration count value to register
*
* CALLS  
*	This function is called when doing RTC HW calibration
*
* PARAMETERS
*	None
*	
* RETURNS
*	the calibration count:  -0x40~0x3f (-64~63)
*
* GLOBALS AFFECTED
*   external_global
*/
void rtc_do_repeat_cali(kal_int32 inaccurate_cnt)
{
	kal_int32 cali_cnt;
	kal_uint8 value;

	cali_cnt = inaccurate_cnt / RTC_CALI_REPEAT_TOTAL_CNT;
	/* divided by total count from last repeat calibration to this time. No that we don't do repeat
	  calibration when there's no inaccurate count. */
	cali_cnt = cali_cnt / (1 + no_diff_cnt);
	#ifdef RTC_CAL_DEBUG
	kal_prompt_trace(MOD_RTC_HISR, "Adjust %d count for repeat calibration register\r\n", cali_cnt);
	#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
   	drv_trace1(TRACE_GROUP_10, RTC_REPEAT_CALI_ADJUST_COUNT, cali_cnt);
#endif // #if !defined(LOW_COST_SUPPORT)
   	cali_cnt += rtc_get_cali_offset();
   	#ifdef RTC_CAL_DEBUG
   	kal_prompt_trace(MOD_RTC_HISR, "Now the value for repeat calibration is %d\r\n", cali_cnt);
   	#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
   	drv_trace1(TRACE_GROUP_10, RTC_REPEAT_CALI_VALUE, cali_cnt);
#endif // #if !defined(LOW_COST_SUPPORT)

	if (cali_cnt > RTC_CALI_REPEAT_MAX)
	{
		#ifdef RTC_CAL_DEBUG
		kal_prompt_trace(MOD_RTC_HISR, "Warning!! value %d exceeds repeat calibration MAX value!\r\n", cali_cnt);
		#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
      	drv_trace1(TRACE_GROUP_10, RTC_REPEAT_CALI_VALUE_EXCEED_MAX, cali_cnt);
#endif // #if !defined(LOW_COST_SUPPORT)
      	cali_cnt = RTC_CALI_REPEAT_MAX;
   	}
	else if (cali_cnt < RTC_CALI_REPEAT_MIN)
	{
		#ifdef RTC_CAL_DEBUG
		kal_prompt_trace(MOD_RTC_HISR, "Warning!! value %d exceeds repeat calibration MIN value!\r\n", cali_cnt);
		#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
      	drv_trace1(TRACE_GROUP_10, RTC_REPEAT_CALI_VALUE_EXCEED_MIN, cali_cnt);
#endif // #if !defined(LOW_COST_SUPPORT)
      	cali_cnt = RTC_CALI_REPEAT_MIN;
	}
	if (cali_cnt < 0)
	{
		value = ((kal_uint8)(~(-cali_cnt) + 1)) & 0x7f;
	}
	else
	{
	  	value = (kal_uint8)cali_cnt;
	}
	DRV_RTC_WriteReg(RTC_CALI, value);
}

/*
* FUNCTION                                                            
*	rtc_do_one_time_cali
*
* DESCRIPTION                                                           
*   To do the one shot calibration
*
* CALLS  
*	This function is called when doing RTC HW calibration
*
* PARAMETERS
*	None
*	
* RETURNS
*	KAL_TRUE: need to do more one shot calibraiton
*  KAL_FASLE: No need to do more one shot calibration
*
* GLOBALS AFFECTED
*   external_global
*/
kal_bool rtc_do_one_time_cali(void)
{
	kal_uint16 value;
	
	if (inaccurate_total_cnt > RTC_CALI_ONE_TIME_MAX)
	{
		/* Exceed max value. So calibration with RTC_CALI_ONE_TIME_MAX */
		inaccurate_total_cnt -= RTC_CALI_ONE_TIME_MAX;
		value = RTC_CALI_ONE_TIME_MAX;
		#ifdef RTC_CAL_DEBUG
		kal_prompt_trace(MOD_RTC_HISR, "Do one shot calibration for %d counts, remains: %d counts\r\n", RTC_CALI_ONE_TIME_MAX, inaccurate_total_cnt);
		#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
      	drv_trace2(TRACE_GROUP_10, RTC_ONESHOT_CALI_PERFORM_COUNT, RTC_CALI_ONE_TIME_MAX, inaccurate_total_cnt);
#endif // #if !defined(LOW_COST_SUPPORT)
  	}
	else if (inaccurate_total_cnt < RTC_CALI_ONE_TIME_MIN)
	{
		/* Less than the min value. So calibration with RTC_CALI_ONE_TIME_MIN */
		inaccurate_total_cnt -= RTC_CALI_ONE_TIME_MIN;
		/* 2's complement. */
		value = (~(-RTC_CALI_ONE_TIME_MIN) + 1) & 0x0fff;
		#ifdef RTC_CAL_DEBUG
		kal_prompt_trace(MOD_RTC_HISR, "Do one shot calibration for %d counts, remains: %d counts\r\n", RTC_CALI_ONE_TIME_MIN, inaccurate_total_cnt);
		#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
      	drv_trace2(TRACE_GROUP_10, RTC_ONESHOT_CALI_PERFORM_COUNT, RTC_CALI_ONE_TIME_MAX, inaccurate_total_cnt);
#endif // #if !defined(LOW_COST_SUPPORT)
   	}
   	else
   	{
		#ifdef RTC_CAL_DEBUG
		kal_prompt_trace(MOD_RTC_HISR, "Do one shot calibration for %d counts, remains: 0 counts\r\n", inaccurate_total_cnt);
		#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
      	drv_trace2(TRACE_GROUP_10, RTC_ONESHOT_CALI_PERFORM_COUNT, inaccurate_total_cnt, 0);
#endif // #if !defined(LOW_COST_SUPPORT)
		/* calibration with inaccurate_total_cnt */
		if (inaccurate_total_cnt < 0)
		{
			/* 2's complement. */
		 	value = ((kal_uint16)(~(-inaccurate_total_cnt) + 1)) & 0x0fff;
		}
		else
		{
			value = (kal_uint16)inaccurate_total_cnt;
		}
      	inaccurate_total_cnt = 0;
   	}
	#ifdef RTC_CAL_DEBUG
	kal_prompt_trace(MOD_RTC_HISR, "Write to one shot calib. value: %x\r\n", value);
	#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
   	drv_trace1(TRACE_GROUP_10, RTC_ONESHOT_CALI_VALUE, value);
#endif // #if !defined(LOW_COST_SUPPORT)
  	DRV_RTC_WriteReg(RTC_DIFF, value);
	if (inaccurate_total_cnt == 0)
	{
		#ifdef RTC_CAL_DEBUG
		kal_prompt_trace(MOD_RTC_HISR, "Finish one shot calibration!!\r\n");
		#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
      	drv_trace0(TRACE_GROUP_10, RTC_ONESHOT_CALI_FINISH);
#endif // #if !defined(LOW_COST_SUPPORT)
      	return KAL_FALSE;
   	}
   	else
      	return KAL_TRUE;
}
#endif /* RTC_HW_CALIBRATION */

/*
* FUNCTION                                                            
*	RTC_TCintr
*
* DESCRIPTION                                                           
*   	RTC Time tick interrupt handler
*
* CALLS  
*	This function is called to handle TC interrupt
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_TCintr(void)
{
#ifndef L4_NOT_PRESENT
	ilm_struct *RTC_ilm;
	RTC_Primitive *RTC_Prim;
	// kal_bool msg_b; //for avoid Lint Warning 534: Ignoring return value of function 'msg_send_ext_queue"
#if defined(RTC_HW_CALIBRATION)
	kal_uint32 frame_tick;
	t_rtc current_time;
	kal_uint32 diff_frame_tick;

	if (cali_state != (kal_uint8)CAL_STATE_NONE)
	{
		kal_bool need_trigger;
		kal_int32 inaccurate_frame_tick = 0;
		
		need_trigger = KAL_FALSE;
		RTC_GetTime_(&current_time);
		if (current_time.rtc_sec == 0)
		{
			if (cali_state == (kal_uint8)CAL_STATE_INIT)
			{
				/* Get the L1 frame tick for reference. */
				rtc_current_frame_tick = L1I_GetTimeStamp();
				cali_state = (kal_uint8)CAL_STATE_START;
				#ifdef RTC_CAL_DEBUG
				kal_prompt_trace(MOD_RTC_HISR, "Start to measure RTC inaccurate. current time - (%d:%d:%d)",
									current_time.rtc_hour, current_time.rtc_min, current_time.rtc_sec);
				kal_prompt_trace(MOD_RTC_HISR, "ini L1 ticks=%d\r\n", rtc_current_frame_tick);
				#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
            	drv_trace4(TRACE_GROUP_10, RTC_HW_CALI_START_MEASURE_INACCURATE, current_time.rtc_hour, current_time.rtc_min, current_time.rtc_sec, 0);
            	drv_trace1(TRACE_GROUP_10, RTC_HW_CALI_INIT_MEASURE_ACCURATE_L1_TICK, rtc_current_frame_tick);
#endif // #if !defined(LOW_COST_SUPPORT)
         	}
			else if (cali_state == (kal_uint8)CAL_STATE_START)
			{
				tc_min_expire_cnt++;
				if (RTC_CALI_PERIOD_MINS <= tc_min_expire_cnt)
				{
					tc_min_expire_cnt = 0;
					/* Get the L1 frame tick for computation. */
					frame_tick = L1I_GetTimeStamp();
					if(frame_tick >= rtc_current_frame_tick)
						diff_frame_tick = (frame_tick - rtc_current_frame_tick);
					else
					{
						diff_frame_tick=(0xffffffff - rtc_current_frame_tick + frame_tick + 1);
					}
					/* Compute the difference between expected frame tick count and real frame tick count. */
					inaccurate_frame_tick = (kal_int32)(diff_frame_tick - RTC_CALI_TICK_VALUE);
					#ifdef RTC_CAL_DEBUG
					kal_prompt_trace(MOD_RTC_HISR, "Finish to measure RTC inaccurate for %d mins. current time - (%d:%d:%d)",
				  	RTC_CALI_PERIOD_MINS, current_time.rtc_hour, current_time.rtc_min, current_time.rtc_sec);
					kal_prompt_trace(MOD_RTC_HISR, "L1 ticks=%d, inaccurate ticks=%d\r\n", frame_tick, inaccurate_frame_tick);
					#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
               		drv_trace4(TRACE_GROUP_10, RTC_HW_CALI_FINISH_MEASURE_INACCURATE, current_time.rtc_hour, current_time.rtc_min, current_time.rtc_sec, 0);
               		drv_trace2(TRACE_GROUP_10, RTC_HW_CALI_FINISH_MEASURE_ACCURATE_L1_TICK, frame_tick, inaccurate_frame_tick);
#endif // #if !defined(LOW_COST_SUPPORT)

					/* The next expected frame tick count. */
					rtc_current_frame_tick += RTC_CALI_TICK_VALUE;
					if (inaccurate_frame_tick == 0)
					{
						no_diff_cnt++;
						#ifdef RTC_CAL_DEBUG
						kal_prompt_trace(MOD_RTC_HISR, "No difference and no need do calibration!!  no_diff_cnt=%d \r\n", no_diff_cnt);
						#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
                  		drv_trace1(TRACE_GROUP_10, RTC_HW_CALI_NO_NEED_TO_CALI, no_diff_cnt);
#endif // #if !defined(LOW_COST_SUPPORT)
              		}
               		else
               		{
						if (inaccurate_frame_tick < 0)
						{
							/* Note that there are 650 / 3 frames ticks per second. */
							inaccurate_total_cnt = (kal_int32)(-inaccurate_frame_tick) * rtc_current_freq_8secs * 3 / 8 / 650;
							inaccurate_total_cnt = -inaccurate_total_cnt;
						}
						else
						{
							inaccurate_total_cnt = (kal_int32)inaccurate_frame_tick * rtc_current_freq_8secs * 3 / 8 / 650;
						}
						#ifdef RTC_CAL_DEBUG
						kal_prompt_trace(MOD_RTC_HISR, "Do repeat calibration for %d counts\r\n", inaccurate_total_cnt);
						#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
                  		drv_trace1(TRACE_GROUP_10, RTC_REPEAT_CALI_PERFORM_CALI, inaccurate_total_cnt);
#endif // #if !defined(LOW_COST_SUPPORT)
						rtc_do_repeat_cali(inaccurate_total_cnt);
						one_time_cali = KAL_TRUE;
						/* Enable TC seconds interrupt */
						if (rtc_tc_int_var != TC_EN_ChkS)
						DRV_RTC_WriteReg(RTC_CII_EN,RTC_CII_EN_SEC);
						need_trigger = KAL_TRUE;
						no_diff_cnt = 0;
               		}
				}
				else
				{
					#ifdef RTC_CAL_DEBUG
					kal_prompt_trace(MOD_RTC_HISR, "In progress for HW RTC calibration. current time - (%d:%d:%d)",
				  		current_time.rtc_hour, current_time.rtc_min, current_time.rtc_sec);
					#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
               		drv_trace4(TRACE_GROUP_10, RTC_HW_CALI_IN_PROGRESS, current_time.rtc_hour, current_time.rtc_min, current_time.rtc_sec, 0);
#endif // #if !defined(LOW_COST_SUPPORT)               
            	}
         	}
		} /* (current_time.rtc_sec == 0) */
		if (one_time_cali == KAL_TRUE)
		{
			kal_bool ret_value;
			
			ret_value = rtc_do_one_time_cali();
			need_trigger = KAL_TRUE;
		 	if (ret_value == KAL_FALSE)
		 	{
				/* No need to do one shot calibration. Change back to minute interrupt if needed. */
				if (rtc_tc_int_var != TC_EN_ChkS)
				{
					DRV_RTC_WriteReg(RTC_CII_EN, RTC_CII_EN_MIN);
				}
		    	one_time_cali = KAL_FALSE;
		 	}
		}
		if (need_trigger == KAL_TRUE)
		{
		 	RTC_write_trigger();
		}
#elif defined(RTC_SW_CALIBRATION)
	t_rtc current_time;
 	kal_uint32 frame_tick;
#if defined(SLEEP_WORKAROUND_IN_RTC)
	kal_uint32 rtc_sleep_wa_delay_tick;
	static t_rtc previous_time;
#endif // #if defined(SLEEP_WORKAROUND_IN_RTC)

	if (cali_state != (kal_uint8)CAL_STATE_NONE)
	{
  		RTC_GetTime_(&current_time);
  		if (cali_state == (kal_uint8)CAL_STATE_INIT)
  		{
   			kal_uint16 reg_comm2;
   			// kal_uint16 tmp;

			// tmp = DRV_RTC_Reg(RTC_IRQ_EN);
			// tmp &= ~RTC_IRQ_EN_ONESHOT;
			// tmp |= RTC_IRQ_EN_TC;
			// DRV_RTC_WriteReg(RTC_IRQ_EN, tmp);

			#ifdef RTC_CAL_DEBUG2
			kal_prompt_trace(MOD_RTC_HISR, "Start to do poweroff calibration");
			#endif /* RTC_CAL_DEBUG */
     
#if !defined(LOW_COST_SUPPORT)
     		drv_trace0(TRACE_GROUP_10, RTC_SW_CALI_START_POWEROFF_CALI);
#endif // #if !defined(LOW_COST_SUPPORT)
     		/* Change to calibration start state. */
     		cali_state = (kal_uint8)CAL_STATE_START;
			if (pwroff_inacc_ticks != 0)
			{
				kal_uint16 hours, mins, secs;
				kal_bool neg = KAL_FALSE;
			
				tc_min_expire_cnt = 0;
				/* Check the time has to be forward or backward. */
				if (pwroff_inacc_ticks < 0)
				{
					neg = KAL_TRUE;
					pwroff_inacc_ticks = -pwroff_inacc_ticks;
				}
				/* Calculate the time shift for hour(60 * 13000), minute(13000) and second(650 / 3). */
				hours = pwroff_inacc_ticks / (13000 * 60);
				pwroff_inacc_ticks = pwroff_inacc_ticks % (13000 * 60);
				mins = pwroff_inacc_ticks / 13000;
				pwroff_inacc_ticks = pwroff_inacc_ticks % 13000;
				secs = pwroff_inacc_ticks * 3 / 650;
				#ifdef RTC_CAL_DEBUG2
				kal_prompt_trace(MOD_RTC_HISR, "current time before poweroff calibration - (%d:%d:%d)",
									current_time.rtc_hour, current_time.rtc_min, current_time.rtc_sec);
				#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
        		drv_trace4(TRACE_GROUP_10, RTC_SW_CALI_START_POWEROFF_CALI_TIME, current_time.rtc_hour, current_time.rtc_min, current_time.rtc_sec, 0);
#endif // #if !defined(LOW_COST_SUPPORT)
        
				/* Calculate the ticks to reach the nearest second boundary. */
				if (neg == KAL_TRUE)
				{
				   	pwroff_inacc_ticks = pwroff_inacc_ticks - (secs * 650 / 3);
				   	rtc_backward_time(&current_time, hours, mins, secs);
				}
				else
				{
				   	secs++;
				   	pwroff_inacc_ticks = (secs * 650 / 3) - pwroff_inacc_ticks;
				   	rtc_forward_time(&current_time, hours, mins, secs);
				}
				/* Set the correct time here. */
				RTC_Cali_Time(&current_time);
				#ifdef RTC_CAL_DEBUG2
				kal_prompt_trace(MOD_RTC_HISR, "current time after poweroff calibration - (%d:%d:%d)",
				   					current_time.rtc_hour, current_time.rtc_min, current_time.rtc_sec);
				#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
        		drv_trace4(TRACE_GROUP_10, RTC_SW_CALI_FINISH_POWEROFF_CALI_TIME, current_time.rtc_hour, current_time.rtc_min, current_time.rtc_sec, 0);
#endif // #if !defined(LOW_COST_SUPPORT)
				if (pwroff_inacc_ticks != 0)
				{
					#ifdef RTC_CAL_DEBUG2
					kal_prompt_trace(MOD_RTC_HISR, "wait %d ticks to do second poweroff calibration",
				  						pwroff_inacc_ticks);
					#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
           			drv_trace1(TRACE_GROUP_10, RTC_SW_CALI_FINISH_2ND_POWEROFF_CALI, pwroff_inacc_ticks);
#endif // #if !defined(LOW_COST_SUPPORT)
           			/* Still some ticks hasn't been calibrated. So change to init2 state */
           			cali_state = (kal_uint8)CAL_STATE_INIT2;
           			/* Save the correct time in: next_current_time */
           			next_current_time = current_time;
           			/* We'll write the correct time again when the exact correspoding time(second) comes by using KAL timer. */
           			kal_set_timer(rtc_timer_id, (kal_timer_func_ptr)rtc_cali_init, NULL, pwroff_inacc_ticks, 0);
        		}
     		} // if (pwroff_inacc_ticks != 0)
     		/* validate rtc nvram data */
   			reg_comm2 = DRV_RTC_Reg(DRV_COMM_REG2);
     		reg_comm2 |= DRV_COMM_REG2_RTC_NVRAM;
     		DRV_RTC_WriteReg(DRV_COMM_REG2,reg_comm2);    

			/* Send msg to write current time to nvram */
			rtc_nvram_s.time_valid = KAL_TRUE;
			rtc_nvram_s.rtc_time = current_time;
			rtc_write_to_nvram();
			
			/* Turn on the TC minute interrupt if necessary. */
			if (rtc_tc_int_var != TC_EN_ChkS)
				DRV_RTC_WriteReg(RTC_CII_EN,RTC_CII_EN_MIN);
			if (pwroff_inacc_ticks == 0)
			{
				tick_left = 0;
				one_third_tick_count = 0;
			
				/* We may start calibration here. */
				next_current_time = current_time;
				kal_set_timer(rtc_timer_id, (kal_timer_func_ptr)rtc_system_timer_cb, NULL, rtc_cali_tick_value + rtc_cali_tick_safe_margin, 0);
				#if (!defined(__L1_STANDALONE__)) 
				frame_tick = L1I_GetTimeStamp();
				#endif
				#ifdef RTC_CAL_DEBUG
				kal_prompt_trace(MOD_RTC_HISR, "Start poweron calibration");
				kal_prompt_trace(MOD_RTC_HISR, "(%d:%d:%d): ", next_current_time.rtc_hour, next_current_time.rtc_min, next_current_time.rtc_sec);
				kal_prompt_trace(MOD_RTC_HISR, "ini tick=%d\r\n", frame_tick);                                                   
				#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
        		drv_trace4(TRACE_GROUP_10, RTC_SW_CALI_START_POWERON_CALI_TIME, next_current_time.rtc_hour,
        					next_current_time.rtc_min, next_current_time.rtc_sec, frame_tick);
#endif // #if !defined(LOW_COST_SUPPORT)
        		next_frame_tick = frame_tick + rtc_cali_tick_value;         
        		rtc_get_next_time();    
     		}
  		} // if (cali_state == (kal_uint8)CAL_STATE_INIT)
		else if (cali_state == (kal_uint8)CAL_STATE_START)
		{
			#if defined(SLEEP_WORKAROUND_IN_RTC)
			// When WA enabled, RTC ISR may be delayed, we can NOT guarantee trc_sec == 0 always
			// Our goal is to count tc_min_expire_cnt every minute
			if (current_time.rtc_min != /*lint -e(727)*/previous_time.rtc_min)
			#else
			// If WA not enabled, we just only need to confirm sec == 0
			/* rtc_sec is zero. Meaning it's TC minute expired. */
			if (current_time.rtc_sec == 0)
			#endif // #if defined(SLEEP_WORKAROUND_IN_RTC)
			{
				if (tc_min_expire_cnt == 0)
				{
					/* Save the frame stick as a refence. */
					frame_tick1 = L1I_GetTimeStamp();
					#ifdef RTC_CAL_DEBUG2
					kal_prompt_trace(MOD_RTC_HISR, "Inaccuracy measurement start");
					#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
           			drv_trace0(TRACE_GROUP_10, RTC_SW_CALI_POWERON_CALI_START_INACCURACY_MEASURE);
#endif // #if !defined(LOW_COST_SUPPORT)
           
        		}
				#if defined(SLEEP_WORKAROUND_IN_RTC)
				else if (tc_min_expire_cnt == 59)
				{
					// Calculate how many ticks we should wait to disable sleep mode
					// We plan to wakeup at 58 sec
					rtc_sleep_wa_delay_tick = 58 - (kal_uint32)current_time.rtc_sec;
					rtc_sleep_wa_delay_tick = (kal_uint32) ((rtc_sleep_wa_delay_tick * 1000) / 4.615);
					// Set kal timer in order to disable sleep mode for RTC calibration
					kal_set_timer(rtc_sleep_wa_timer_id, (kal_timer_func_ptr)rtc_sleep_wa_timer_cb, NULL, rtc_sleep_wa_delay_tick, 0);
					#ifdef RTC_SLEEP_WA_DEBUG
					kal_prompt_trace(MOD_RTC_HISR, "SleepWA: (%d:%d), Start disable sleep timer with tick: %d", 
										current_time.rtc_min, current_time.rtc_sec, rtc_sleep_wa_delay_tick);
					#endif /* RTC_SLEEP_WA_DEBUG */
				}
				#endif // #if defined(SLEEP_WORKAROUND_IN_RTC)
        		else if (tc_min_expire_cnt == 60)
        		{
					#if defined(SLEEP_WORKAROUND_IN_RTC)
					// We only calculate 1hr diff when disable_sleep is performed
					// This means there is no problem between kal timer and our rtc TC intr
					if (rtc_sleep_wa_disable_sleep_performed)
					{
					#endif // #if defined(SLEEP_WORKAROUND_IN_RTC)
					
						/* Get the frame stick after 60 minutes passed. */
						frame_tick2 = L1I_GetTimeStamp();
						/* Calculate the frame tick number for 1 hr of RTC time. */
						if(frame_tick2 >= frame_tick1) 
							frame_tick_1hr_diff = (kal_int32)(frame_tick2 - frame_tick1 - 13000 * 60);
						else
							frame_tick_1hr_diff = (kal_int32)(0xffffffff + frame_tick2 - frame_tick1 + 1 - 13000 * 60);
						
						#ifdef RTC_CAL_DEBUG2
						kal_prompt_trace(MOD_RTC_HISR, "Inaccuracy measurement done for one hour: %d ticks", frame_tick_1hr_diff);
						#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
           				drv_trace1(TRACE_GROUP_10, RTC_SW_CALI_POWERON_CALI_FINISH_INACCURACY_MEASURE, frame_tick_1hr_diff);
#endif // #if !defined(LOW_COST_SUPPORT)
           
						/* save frame_tick_1hr_diff(inaccuracy) to nvram here */
						// rtc_nvram_s.ticks_diff_valid = KAL_TRUE;
						// rtc_nvram_s.ticks_diff_per_hour = frame_tick_1hr_diff;
						// rtc_write_to_nvram();
               
					#if defined(SLEEP_WORKAROUND_IN_RTC)
						#ifdef RTC_SLEEP_WA_DEBUG
						kal_prompt_trace(MOD_RTC_HISR, "SleepWA: (%d:%d), Calculate power off calibration info", 
											current_time.rtc_min, current_time.rtc_sec);
						#endif /* RTC_SLEEP_WA_DEBUG */
					} // if (rtc_sleep_wa_disable_sleep_performed)
					else
					{
						#ifdef RTC_SLEEP_WA_DEBUG
						kal_prompt_trace(MOD_RTC_HISR, "SleepWA: (%d:%d), Warning!!, disable sleep mode NOT performed", 
								current_time.rtc_min, current_time.rtc_sec);
						#endif /* RTC_SLEEP_WA_DEBUG */
					}
					#endif // #if defined(SLEEP_WORKAROUND_IN_RTC)
           
					#if defined(SLEEP_WORKAROUND_IN_RTC)
					rtc_sleep_wa_disable_sleep_performed = KAL_FALSE;
					// After RTC calibration processing is done, re-enabel sleep mode
					// We always enable sleep mode in this stage
					rtc_sleep_wa_enable_sleep_mode();
					#ifdef RTC_SLEEP_WA_DEBUG
					kal_prompt_trace(MOD_RTC_HISR, "SleepWA: (%d:%d), Enable sleep mode", 
							current_time.rtc_min, current_time.rtc_sec);
					#endif /* RTC_SLEEP_WA_DEBUG */
					#endif // #if defined(SLEEP_WORKAROUND_IN_RTC)
        		}
        		#if defined(SLEEP_WORKAROUND_IN_RTC)
	            // Only sec, min, hour info is enough for us
	            previous_time.rtc_sec = current_time.rtc_sec;
	            previous_time.rtc_min = current_time.rtc_min;
	            previous_time.rtc_hour = current_time.rtc_hour;
	            #endif // #if defined(SLEEP_WORKAROUND_IN_RTC)
	            tc_min_expire_cnt++;
     		} // if (current_time.rtc_sec == 0)
  		}
#endif /* RTC_SW_CALIBRATION */
#if defined(RTC_HW_CALIBRATION) || defined(RTC_SW_CALIBRATION)
		/* Check user's configuration for Time Clock interrupt. */
		switch(rtc_tc_int_var)
		{
			case TC_EN_None:
				return;
				//avoid Warning:  #111-D: statement is unreachable
				//break;
		
			case TC_EN_ChkS:
				break;
			
			case TC_EN_ChkM:
				#if defined(SLEEP_WORKAROUND_IN_RTC)
				// If WA enabled, we won't check sec, because it would be delayed
				;
				#else
				// Original design: sec must be 0 if it is user TC setting
				if (current_time.rtc_sec != 0)
					return;
				#endif // #if defined(SLEEP_WORKAROUND_IN_RTC)
				break;
		
			case TC_EN_ChkH:
				#if defined(SLEEP_WORKAROUND_IN_RTC)
				// If WA enabled, we won't check sec, because it would be delayed
				if ((current_time.rtc_min != 0))
					return;
				#else
				// Original design: sec must be 0 if it is user TC setting
				if ((current_time.rtc_sec != 0) || (current_time.rtc_min != 0))
					return;
				#endif // #if defined(SLEEP_WORKAROUND_IN_RTC)
				break;
		
			case TC_EN_ChkD:
			case TC_EN_ChkW:
				#if defined(SLEEP_WORKAROUND_IN_RTC)
				// If WA enabled, we won't check sec, because it would be delayed
				if ((current_time.rtc_min != 0) || (current_time.rtc_hour != 0))
					return;
				#else
					// Original design: sec must be 0 if it is user TC setting
				if ((current_time.rtc_sec != 0) || (current_time.rtc_min != 0) ||(current_time.rtc_hour != 0))
					return;
				#endif // #if defined(SLEEP_WORKAROUND_IN_RTC)
				break;
			case TC_EN_ChkMon:
				#if defined(SLEEP_WORKAROUND_IN_RTC)
				// If WA enabled, we won't check sec, because it would be delayed
				if ((current_time.rtc_min != 0) ||(current_time.rtc_hour != 0) 
					||(current_time.rtc_day != 1))
					return;
				#else
				// Original design: sec must be 0 if it is user TC setting
				if ((current_time.rtc_sec != 0) || (current_time.rtc_min != 0) || (current_time.rtc_hour != 0) 
					||(current_time.rtc_day != 1))
					return;
				#endif // #if defined(SLEEP_WORKAROUND_IN_RTC)
				break;
		
			case TC_EN_ChkY:
				#if defined(SLEEP_WORKAROUND_IN_RTC)
				// If WA enabled, we won't check sec, because it would be delayed
				if ((current_time.rtc_min != 0) ||(current_time.rtc_hour != 0) 
				||(current_time.rtc_day != 1) || (current_time.rtc_mon != 1))
				return;
				#else
				// Original design: sec must be 0 if it is user TC setting
				if ((current_time.rtc_sec != 0) || (current_time.rtc_min != 0) ||(current_time.rtc_hour != 0) 
				||(current_time.rtc_day != 1) || (current_time.rtc_mon != 1))
				return;
				#endif // #if defined(SLEEP_WORKAROUND_IN_RTC)
				break;
			
			case TC_EN_NoChange:
				break;
			
			default:
				break;
		}
	} /* (cali_state != CAL_STATE_NONE) */
   	#ifdef RTC_CAL_DEBUG
   	// frame_tick=L1I_GetTimeStamp();
  	kal_prompt_trace(MOD_RTC_HISR, "TC interrupt for user\r\n");
   	#endif /* RTC_CAL_DEBUG */
   	drv_trace0(TRACE_GROUP_10, RTC_TC_INTR_FOR_USER);     
#endif /* defined(RTC_HW_CALIBRATION) || defined(RTC_SW_CALIBRATION) */

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
#else // use new KAL message passing API
	RTC_Prim = (RTC_Primitive *)
				   construct_local_para(sizeof(RTC_Primitive), TD_CTRL);
	RTC_Prim->rtc_ind = RTC_TC_IND;

    msg_send5(MOD_DRV_HISR, MOD_UEM, 
              DRIVER_PS_SAP, MSG_ID_DRVUEM_RTC_PERIOD_IND, (local_para_struct*)RTC_Prim);     
#endif
    
#endif   /*L4_NOT_PRESENT*/   
}

void RTC_ALintr(void)
{
	kal_uint16 BBPU;
#ifndef L4_NOT_PRESENT
	//kal_bool btmp;
#endif /* L4_NOT_PRESENT */ 

#ifndef L4_NOT_PRESENT
	ilm_struct *RTC_ilm;
	RTC_Primitive *RTC_Prim;
#endif   /*L4_NOT_PRESENT*/ 
   	BBPU = DRV_RTC_Reg(RTC_BBPU);
   	BBPU &= ~(RTC_BBPU_ALARM_SW); /* 0227 TY adds */
	#if defined(DRV_RTC_WRITE_ENABLE)
	BBPU |= RTC_BBPU_WRITE_EN;
	#endif // #if defined(DRV_RTC_WRITE_ENABLE)
	DRV_RTC_WriteReg(RTC_BBPU,(BBPU|RTC_BBPU_KEY)); /* 0227 TY adds */
#if defined(DRV_RTC_HW_CALI)
   	RTC_write_trigger();
#endif /* DRV_RTC_HW_CALI */
   	drv_trace0(TRACE_GROUP_10, RTC_AL_INTR);
   
#ifndef L4_NOT_PRESENT

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
  #else // use new KAL message passing API
    RTC_Prim = (RTC_Primitive *)
                 construct_local_para(sizeof(RTC_Primitive), TD_CTRL);
    RTC_Prim->rtc_ind = RTC_AL_IND;

    msg_send5(MOD_DRV_HISR, MOD_UEM, 
            DRIVER_PS_SAP, MSG_ID_DRVUEM_RTC_PERIOD_IND, (local_para_struct*)RTC_Prim); 
  #endif
   
#endif /* L4_NOT_PRESENT */    
}

#if defined(RTC_SW_CALIBRATION)
/*
* FUNCTION                                                            
*	rtc_write_to_nvram
*
* DESCRIPTION                                                           
*   	Save RTC SW calibration data to nvram
*
* CALLS  
*	This function is called internally for RTC SW calibration
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*  None
*/
void rtc_write_to_nvram(void)
{
	ilm_struct *rtc_ilm_ptr = 0;
	void *parm_stream = 0;
	void *data_stream = 0;
	kal_uint16 pdu_len;
   // kal_bool msg_b; //for avoid Lint Warning 534: Ignoring return value of function 'msg_send_ext_queue"

   
#if !defined(LOW_COST_SUPPORT)
	drv_trace0(TRACE_GROUP_10, RTC_SW_CALI_WRITE_NVRAM);
#endif // #if !defined(LOW_COST_SUPPORT)

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
#else // use new KAL message passing API

    parm_stream = construct_local_para(sizeof(nvram_write_req_struct), TD_CTRL);
    data_stream = construct_peer_buff(sizeof(rtc_nvram_data), 0, 0, TD_CTRL);

    ((nvram_write_req_struct *) parm_stream)->file_idx =  (nvram_lid_enum)NVRAM_EF_RTC_DATA_LID;
    ((nvram_write_req_struct *) parm_stream)->para = 1;

 	pdu_len = sizeof(rtc_nvram_data);
	/* lint -e(534) */kal_mem_cpy(get_peer_buff_pdu(data_stream, &pdu_len), (void *)&rtc_nvram_s, sizeof(rtc_nvram_data));  

    msg_send6(MOD_RTC_HISR, MOD_NVRAM, 
            PS_NVRAM_SAP, MSG_ID_NVRAM_WRITE_REQ, (local_para_struct*)parm_stream, (peer_buff_struct*) data_stream);     
    
#endif

#if !defined(LOW_COST_SUPPORT)
#if !defined(__FUE__) && !defined(__UBL__)
  drv_trace8(TRACE_GROUP_9, RTC_WRITE_TO_NVRAM, rtc_nvram_s.rtc_time.rtc_year, rtc_nvram_s.rtc_time.rtc_mon,
      rtc_nvram_s.rtc_time.rtc_day, rtc_nvram_s.rtc_time.rtc_hour, rtc_nvram_s.rtc_time.rtc_min, 
      rtc_nvram_s.rtc_time.rtc_sec, 0, 0);
#endif
#endif
}

/*
* FUNCTION                                                            
*	rtc_compare_time
*
* DESCRIPTION                                                           
*  Compare the rtc time.
*
* CALLS  
*	This function is called internally for RTC SW calibration
*
* PARAMETERS
*	rtc_time1
*	rtc_time2
*
* RETURNS
*	KAL_TRUE if rtc_time1 > rtc_time2. Else, return KAL_FALSE
*
* GLOBALS AFFECTED
*  None
*/
kal_bool rtc_compare_time(t_rtc *rtc_time1, t_rtc *rtc_time2)
{
	if (rtc_time1->rtc_year < rtc_time2->rtc_year)
	  	return KAL_FALSE;
	else if (rtc_time1->rtc_year == rtc_time2->rtc_year)
	{
	  	if (rtc_time1->rtc_mon < rtc_time2->rtc_mon)
	     	return KAL_FALSE;
	  	else if (rtc_time1->rtc_mon == rtc_time2->rtc_mon)
	  	{
	     	if (rtc_time1->rtc_day < rtc_time2->rtc_day)
	        	return KAL_FALSE;
	     	else if (rtc_time1->rtc_day == rtc_time2->rtc_day)
	     	{
	        	if (rtc_time1->rtc_hour < rtc_time2->rtc_hour)
	           	return KAL_FALSE;
	        	else if (rtc_time1->rtc_hour == rtc_time2->rtc_hour)
	        	{
	           		if (rtc_time1->rtc_min < rtc_time2->rtc_min)
	              		return KAL_FALSE;
	           		else if (rtc_time1->rtc_min == rtc_time2->rtc_min)
	           		{
	              		if (rtc_time1->rtc_sec <= rtc_time2->rtc_sec)
	                 		return KAL_FALSE;
	           		}
	        	}
	     	}
	  	}
	}
   	return KAL_TRUE;
}

/*
* FUNCTION                                                            
*	rtc_get_diff_time
*
* DESCRIPTION                                                           
*  Get the time different between 2 RTC time into hours and minute. Note that if the year difference is
*  more than 1 then we'll see it as invalid.
*
* CALLS  
*	This function is called internally for RTC SW calibration
*
* PARAMETERS
*	curr_time: INPUT for current RTC time
*	prev_time: INPUT for previous RTC time
*  ret_hours: OUTPUT for hours of time difference between current time and previous time
*  ret_mins: OUTPUT for minutes of time difference between current time and previous time
*
* RETURNS
*	KAL_TRUE: If the time difference is valid
*  KAL_FALSE: If the time difference is invalid such as curr_time is older, or the time difference is 
*             too large.
*
* GLOBALS AFFECTED
*  None
*/
kal_bool rtc_get_diff_time(t_rtc *curr_time, t_rtc *prev_time, kal_uint16 *ret_hours, kal_uint16 *ret_mins)
{
	kal_int16 secs;
	kal_int16 mins;
	kal_int32 hours;
	kal_int16 days;
	
	/* Invalid if the current time is older. */
	if (KAL_FALSE == rtc_compare_time(curr_time, prev_time))
		return KAL_FALSE;
	
	/* Invalid if the year difference is more than 1. */
	if (curr_time->rtc_year>(prev_time->rtc_year + 1))
		return KAL_FALSE;
	
	days = 0;
	secs = 0;
	mins = 0;
	hours = 0;
   	if (curr_time->rtc_sec < prev_time->rtc_sec)
   	{
		secs = 60;
		mins = -1;
   	}
   	secs += (curr_time->rtc_sec - prev_time->rtc_sec);
   	if (curr_time->rtc_min < (prev_time->rtc_min - mins))
   	{
      	mins += 60;
      	hours = -1;
   	}
   	mins += (curr_time->rtc_min - prev_time->rtc_min);
   	if (secs >= 30)
      	mins++;
   	if (curr_time->rtc_hour < (prev_time->rtc_hour - hours))
   	{
		hours += 24;
		days = -1;
   	}
   	hours += (curr_time->rtc_hour - prev_time->rtc_hour);
   	if ((curr_time->rtc_year == prev_time->rtc_year) && (curr_time->rtc_mon == prev_time->rtc_mon))
	{
		days += (curr_time->rtc_day - prev_time->rtc_day);
	}
	else
	{
		kal_uint8   month;
		kal_uint8   month_end;
		
		days += (days_in_month[prev_time->rtc_mon] - prev_time->rtc_day);
		month_end = (curr_time->rtc_year == prev_time->rtc_year) ? curr_time->rtc_mon : 13; 
		for (month = (prev_time->rtc_mon + 1); month < month_end; month++)
		{
			days += days_in_month[month];
		}
		if ((0==(prev_time->rtc_year % 4)) && (prev_time->rtc_mon <= 2))
		{
			if (curr_time->rtc_year != prev_time->rtc_year)
				days++;
			else if (curr_time->rtc_mon > 2)
				days++;
		}
		month_end = (curr_time->rtc_year == prev_time->rtc_year) ? 0 : curr_time->rtc_mon; 
		for (month = 1; month < month_end; month++)
		{
			days += days_in_month[month];
		}
		days += curr_time->rtc_day;
		if ((curr_time->rtc_year != prev_time->rtc_year) && (0 == (curr_time->rtc_year % 4)) && (curr_time->rtc_mon > 2))
			days++;
	}
	hours += (days * 24);
	*ret_mins = (kal_uint16)mins;
	*ret_hours = (kal_uint16)hours;
	return KAL_TRUE;
}

/*
* FUNCTION                                                            
*	rtc_forward_time
*
* DESCRIPTION                                                           
*  Increase the RTC time by hours, minutes and seconds.
*
* CALLS  
*	This function is called internally for RTC SW calibration
*
* PARAMETERS
*	rtc_time: current RTC time
*	hours: hours to increase time
*  mins: minutes to increase time
*  secs: seconds to increase time
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*  None
*/
void rtc_forward_time(t_rtc *rtc_time, kal_uint16 hours, kal_uint16 mins, kal_uint16 secs)
{
	ASSERT(hours < 168); //24*7, we do not handle forward more than 7 days.
	
	secs += rtc_time->rtc_sec;
	mins += rtc_time->rtc_min;
	hours += rtc_time->rtc_hour;
#if !defined(LOW_COST_SUPPORT)
   	// TIMER_HISR stack only 512 bytes, remove trace
   	// drv_trace8(TRACE_GROUP_10, RTC_FORWARD_TIME_1, rtc_time->rtc_hour, rtc_time->rtc_min, rtc_time->rtc_sec, hours, mins, secs, 0, 0);
#endif // #if !defined(LOW_COST_SUPPORT)
   
	if (secs > 59)
	{
		/* min */
		mins += secs / 60;
		secs %= 60;
	}
	rtc_time->rtc_sec = secs;
	if (mins > 59)
	{
		/* hour */
		hours += mins / 60;
		mins %= 60;
	}
	rtc_time->rtc_min = mins;
	if (hours > 23)
	{
		kal_uint16 days;
		kal_uint8 max_day;
	
		/* day of week */
		days = hours / 24;
		hours %= 24;
		rtc_time->rtc_wday += days;
		if(rtc_time->rtc_wday > 7)
			rtc_time->rtc_wday -= 7;
		/* day of month */            
		rtc_time->rtc_day += days;
		max_day = days_in_month[rtc_time->rtc_mon];
		if(rtc_time->rtc_mon == 2)
		{
			kal_uint32 remender;
			remender = rtc_time->rtc_year % 4;
			if(remender == 0)
				max_day++;
		}    
		if(rtc_time->rtc_day > max_day)
		{
			rtc_time->rtc_day-=max_day;
	
			/* month of year */
			rtc_time->rtc_mon++;
			if(rtc_time->rtc_mon > 12)
			{
				rtc_time->rtc_mon = 1;
				rtc_time->rtc_year++;
			}                                      
		}   
	}
	rtc_time->rtc_hour = hours;
   
#if !defined(LOW_COST_SUPPORT)
   	// TIMER_HISR stack only 512 bytes, remove trace
   	// drv_trace4(TRACE_GROUP_10, RTC_FORWARD_TIME_2, rtc_time->rtc_hour, rtc_time->rtc_min, rtc_time->rtc_sec, 0);
#endif // #if !defined(LOW_COST_SUPPORT)
}

/*
* FUNCTION                                                            
*	rtc_backward_time
*
* DESCRIPTION                                                           
*  Decrease the RTC time by hours, minutes and seconds.
*
* CALLS  
*	This function is called internally for RTC SW calibration
*
* PARAMETERS
*	rtc_time: current RTC time
*	hours: hours to decrease time
*  mins: minutes to decrease time
*  secs: seconds to decrease time
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*  None
*/
void rtc_backward_time(t_rtc *rtc_time, kal_uint16 hours, kal_uint16 mins, kal_uint16 secs)
{
	kal_uint8 day;

#if !defined(LOW_COST_SUPPORT)
#if !defined(__FUE__) && !defined(__UBL__)
	drv_trace8(TRACE_GROUP_10, RTC_BACKWARD_TIME_1, rtc_time->rtc_hour, rtc_time->rtc_min, rtc_time->rtc_sec, hours, mins, secs, 0, 0);
#endif
#endif // #if !defined(LOW_COST_SUPPORT)
	day = 0;
	if (secs > rtc_time->rtc_sec)
	{
		rtc_time->rtc_sec += 60;
		mins++;
	}
	rtc_time->rtc_sec -= secs;
	if (mins > rtc_time->rtc_min)
	{
		rtc_time->rtc_min += 60;
		hours++;
	}
	rtc_time->rtc_min -= mins;   
	if (hours > rtc_time->rtc_hour)
	{
		rtc_time->rtc_hour += 24;
		day = 1;
	}
	rtc_time->rtc_hour -= hours;   
	if(day == 1)
	{
		rtc_time->rtc_wday--;
		if (rtc_time->rtc_wday == 0)
			rtc_time->rtc_wday = 7;
		rtc_time->rtc_day--;
		if (rtc_time->rtc_day == 0)
		{
			rtc_time->rtc_mon--;
			if (rtc_time->rtc_mon == 0)
			{
				rtc_time->rtc_mon = 12;
				rtc_time->rtc_year--;
			}
			rtc_time->rtc_day = days_in_month[rtc_time->rtc_mon];
			if(rtc_time->rtc_mon==2)
			{
				kal_uint32 remender;
				remender = rtc_time->rtc_year % 4;
				if(remender==0)
					rtc_time->rtc_day++;
			}    
		}
	}   
#if !defined(LOW_COST_SUPPORT)
	drv_trace4(TRACE_GROUP_10, RTC_BACKWARD_TIME_2, rtc_time->rtc_hour, rtc_time->rtc_min, rtc_time->rtc_sec, 0);
#endif // #if !defined(LOW_COST_SUPPORT)
}

/*
* FUNCTION                                                            
*	rtc_update_time
*
* DESCRIPTION                                                           
*     update time according to time stamp
*
* CALLS  
*	This function is to update time according to time stamp
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void rtc_update_time(void)
{
	kal_uint32 current_frame_tick, diff_frame_tick;
	kal_uint32 sec;
	kal_uint32 tick_left_temp;
	kal_uint16 one_third_tick_count_temp;
	// kal_uint32 max_day = 0;  
	#ifdef RTC_CAL_DEBUG
	t_rtc rtctime;
	#endif /* RTC_CAL_DEBUG */
	
	#if (!defined(__L1_STANDALONE__)) 
	current_frame_tick = L1I_GetTimeStamp();
	#endif
	/* Calculate the different ticks between the current time and expected time for calibration timeout. */
	if(current_frame_tick >= next_frame_tick) 
		diff_frame_tick = (current_frame_tick - next_frame_tick) + tick_left;   
	else
	{
		diff_frame_tick=(0xffffffff + current_frame_tick - next_frame_tick + 1) + tick_left;   
		#ifdef RTC_CAL_DEBUG
		kal_prompt_trace(MOD_RTC_HISR, "KAL time out early, expected:%d (ticks), now:%d \r\n", next_frame_tick, current_frame_tick);
		#endif /* RTC_CAL_DEBUG */
      
#if !defined(LOW_COST_SUPPORT)
		drv_trace2(TRACE_GROUP_10, RTC_SW_CALI_KAL_EXPIRE_EARLY, next_frame_tick, current_frame_tick);
#endif // #if !defined(LOW_COST_SUPPORT)
	}
	/* Convert the ticks to minutes. */
	sec = (diff_frame_tick / rtc_tick_update_interval);
	sec = sec * rtc_sec_update_interval;
	
	/* the 1/3 tick for each second. (217 - 216 & 2/3) */
	one_third_tick_count_temp = one_third_tick_count + sec;
	tick_left_temp = (diff_frame_tick % rtc_tick_update_interval) + one_third_tick_count_temp / 3;
	/* record the left 1/3 tick count. */
	one_third_tick_count_temp %= 3;
	
	/* The below calculation is neccessary because the tick_left_temp may be larger than
	rtc_tick_update_interval again. */
	while (tick_left_temp >= rtc_tick_update_interval)
	{
		sec += (tick_left_temp / rtc_tick_update_interval);
		one_third_tick_count_temp += (tick_left_temp / rtc_tick_update_interval);
		tick_left_temp = ((tick_left_temp % rtc_tick_update_interval) + one_third_tick_count_temp / 3);
		one_third_tick_count_temp %= 3;
	}

   	/* 15 ticks is about 69 ms. */
   	if (tick_left_temp > 15)
   	{
		/* If the inaccuracy for second boundary is more than 15 ticks, set kal timer to reach the boundary and wait. */
		kal_set_timer(rtc_timer_id, (kal_timer_func_ptr)rtc_system_timer_cb, NULL, (rtc_tick_update_interval - tick_left_temp + 1),0);
		#ifdef RTC_CAL_DEBUG2
		kal_prompt_trace(MOD_RTC_HISR, "calibration time out not in the second boundary:%d (ticks) \r\n", tick_left_temp);
		#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
      	drv_trace1(TRACE_GROUP_10, RTC_SW_CALI_TIMOUE_NOT_IN_SEC_BOUNDARY, tick_left_temp);
#endif // #if !defined(LOW_COST_SUPPORT)
      	return;
   	}
	/* At this moment, it's around the second boundary. So we do the calibration here now. */
	tick_left = tick_left_temp;
	one_third_tick_count = one_third_tick_count_temp;
	tc_min_expire_cnt = 0;
	/* Plus some ticks to the timer period to guarantee it will expire longer than expected. */
	kal_set_timer(rtc_timer_id, (kal_timer_func_ptr)rtc_system_timer_cb, NULL, rtc_cali_tick_value + rtc_cali_tick_safe_margin, 0);
	/* update time */
	/* sec */
	rtc_forward_time(&next_current_time, 0, 0, sec);
	
	RTC_Cali_Time(&next_current_time);
	
	/* Save current time and frame_tick_1hr_diff to nvram. */
	rtc_nvram_s.time_valid = KAL_TRUE;
	rtc_nvram_s.rtc_time = next_current_time;
	rtc_nvram_s.ticks_diff_valid = KAL_TRUE;
	rtc_nvram_s.ticks_diff_per_hour = frame_tick_1hr_diff;
	rtc_write_to_nvram();
	
	#ifdef RTC_CAL_DEBUG
	RTC_GetTime_(&rtctime);
	kal_prompt_trace(MOD_RTC_HISR, "calibration time out(%d:%d:%d):%d \r\n"
		,rtctime.rtc_hour,rtctime.rtc_min,rtctime.rtc_sec, current_frame_tick);
	kal_prompt_trace(MOD_RTC_HISR, "(update %d:%d:%d,):%d \r\n"
		,next_current_time.rtc_hour, next_current_time.rtc_min, next_current_time.rtc_sec, current_frame_tick);
	#endif /* RTC_CAL_DEBUG */
	
	#ifdef RTC_CAL_DEBUG
	#if !defined(LOW_COST_SUPPORT)
	drv_trace4(TRACE_GROUP_10, RTC_SW_CALI_TIMOUE_OUT, rtctime.rtc_hour, rtctime.rtc_min, rtctime.rtc_sec, current_frame_tick);
	#endif // #if !defined(LOW_COST_SUPPORT)
	#endif /* RTC_CAL_DEBUG */
	#if !defined(LOW_COST_SUPPORT)
	drv_trace4(TRACE_GROUP_10, RTC_SW_CALI_UPDATE_TIME, next_current_time.rtc_hour, next_current_time.rtc_min, next_current_time.rtc_sec, current_frame_tick);
	#endif // #if !defined(LOW_COST_SUPPORT)
	/* Calculate the next calibration timeout in frame tick and time. */
	next_frame_tick = rtc_cali_tick_value + current_frame_tick;
	rtc_get_next_time();      
}

/*
* FUNCTION                                                            
*	rtc_get_next_time
*
* DESCRIPTION                                                           
*     calculate next time out time
*
* CALLS  
*	This function is to calculate nexe time out time
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void rtc_get_next_time(void)
{
	/*next time*/
	rtc_forward_time(&next_current_time, rtc_cali_hr_period, rtc_cali_min_period, 0);
}   


/*
* FUNCTION                                                            
*	rtc_poweroff_cali_init
*
* DESCRIPTION                                                           
*  Calculate the last poweroff period of the handset and the RTC inaccuracy between this period.
*
* CALLS  
*	This function is called internally in handset power on sequence.
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void rtc_poweroff_cali_init(void)
{
	kal_uint16 reg_comm2;
    PW_CTRL_GET_POWERON_REASON GetPWReason;
    DCL_HANDLE pmu_handle;
    pmu_handle = DclPW_Open(DCL_PW, FLAGS_NONE);
    
	// kal_bool   btmp;
	
	pwroff_inacc_ticks = 0;
	/* lint -e(534) */nvram_external_read_data((kal_uint16)NVRAM_EF_RTC_DATA_LID, 1, (kal_uint8 *)&rtc_nvram_s, sizeof(rtc_nvram_data));
	#ifdef RTC_CAL_DEBUG2
	kal_prompt_trace(MOD_RTC_HISR, "Get nvram data");
	kal_prompt_trace(MOD_RTC_HISR, "time valid?: %d", rtc_nvram_s.time_valid);
	kal_prompt_trace(MOD_RTC_HISR, "%d-%d-%d (%d:%d:%d): ", rtc_nvram_s.rtc_time.rtc_year, rtc_nvram_s.rtc_time.rtc_mon,
		rtc_nvram_s.rtc_time.rtc_day, rtc_nvram_s.rtc_time.rtc_hour, rtc_nvram_s.rtc_time.rtc_min, rtc_nvram_s.rtc_time.rtc_sec);
	kal_prompt_trace(MOD_RTC_HISR, "tick diff valide?: %d", rtc_nvram_s.ticks_diff_valid);                                                   
	kal_prompt_trace(MOD_RTC_HISR, "ticks_diff_per_hour=%d", rtc_nvram_s.ticks_diff_per_hour);                                                   
   	#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
#if !defined(__FUE__) && !defined(__UBL__)
   	drv_trace1(TRACE_GROUP_10, RTC_SW_CALI_POWEROFF_CALI_INIT1, rtc_nvram_s.time_valid);
   	drv_trace8(TRACE_GROUP_10, RTC_SW_CALI_POWEROFF_CALI_INIT2, rtc_nvram_s.rtc_time.rtc_year, rtc_nvram_s.rtc_time.rtc_mon,
		rtc_nvram_s.rtc_time.rtc_day, rtc_nvram_s.rtc_time.rtc_hour, rtc_nvram_s.rtc_time.rtc_min, rtc_nvram_s.rtc_time.rtc_sec, 0, 0);
   	drv_trace1(TRACE_GROUP_10, RTC_SW_CALI_POWEROFF_CALI_INIT3, rtc_nvram_s.ticks_diff_valid);
   	drv_trace1(TRACE_GROUP_10, RTC_SW_CALI_POWEROFF_CALI_INIT3, rtc_nvram_s.ticks_diff_per_hour);
#endif
#endif // #if !defined(LOW_COST_SUPPORT)
   
   	/* RTC_isFirstOn() may be called before in DRV_POWERON(). */
	if ((First_PowerOn == KAL_TRUE) || (KAL_FALSE == RTC_isFisrtOn()))
   	{
		reg_comm2 = DRV_RTC_Reg(DRV_COMM_REG2);

		/* DRV_COMM_REG2_RTC_NVRAM is to determine if the content of RTC nvram is valid or not. */
		if ((reg_comm2 & DRV_COMM_REG2_RTC_NVRAM) && (rtc_nvram_s.time_valid == KAL_TRUE) && (rtc_nvram_s.ticks_diff_valid == KAL_TRUE))
		{
			kal_uint16 hours, mins, secs;
			t_rtc time;
			kal_bool valid;

			/* Get the RTC current time. */
			RTC_GetTime_(&time);
			#ifdef RTC_CAL_DEBUG2
			kal_prompt_trace(MOD_RTC_HISR, "The current power on time: %d-%d-%d (%d:%d:%d): ", time.rtc_year, time.rtc_mon,
				time.rtc_day, time.rtc_hour, time.rtc_min, time.rtc_sec);
			#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
#if !defined(__FUE__) && !defined(__UBL__)
         	drv_trace8(TRACE_GROUP_10, RTC_SW_CALI_CURR_POWER_TIME, time.rtc_year, time.rtc_mon,
            	time.rtc_day, time.rtc_hour, time.rtc_min, time.rtc_sec, 0, 0);
#endif
#endif // #if !defined(LOW_COST_SUPPORT)
                  
         	/* calculate the power off period in hours and minutes. */
         	valid = rtc_get_diff_time(&time, &(rtc_nvram_s.rtc_time), &hours, &mins);
         	#ifdef RTC_CAL_DEBUG2
         	kal_prompt_trace(MOD_RTC_HISR, "poweroff period - valid: %d, hours: %d, minutes: %d", valid, hours, mins);
         	#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
         	drv_trace4(TRACE_GROUP_10, RTC_SW_CALI_POWEROFF_PERIOD_VALID, valid, hours, mins, 0);
#endif // #if !defined(LOW_COST_SUPPORT)
         	/* Check if these values are reasonable. */
         	if ((valid == KAL_TRUE) && (hours < 7200) 
            	&& (rtc_nvram_s.ticks_diff_per_hour > -1300) && (rtc_nvram_s.ticks_diff_per_hour < 1300))
         	{
            	/* calculate the inaccurate difference. */
            	pwroff_inacc_ticks = hours * rtc_nvram_s.ticks_diff_per_hour + mins * rtc_nvram_s.ticks_diff_per_hour / 60;

            	#ifdef RTC_CAL_DEBUG2
            	kal_prompt_trace(MOD_RTC_HISR, "inaccurate ticks during poweroff: %d", pwroff_inacc_ticks);
            	#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
            	drv_trace1(TRACE_GROUP_10, RTC_SW_CALI_INACCURATE_TICK_DURING_POWEROFF, pwroff_inacc_ticks);
#endif // #if !defined(LOW_COST_SUPPORT)
                DclPW_Control(pmu_handle, PW_CMD_GET_POWERON_REASON, (DCL_CTRL_DATA_T *)&GetPWReason);
                DclPW_Close(pmu_handle);

            	/* Check if it's alarm power on and the time has to be backward. */
            	if ((GetPWReason.powerOnReason == (kal_uint8)RTCPWRON) && (pwroff_inacc_ticks < 0))
            	{
               		t_rtc alarm_time;
					DCL_HANDLE pw_handle;
					pw_handle = DclPW_Open(DCL_PW, FLAGS_NONE);

#if !defined(LOW_COST_SUPPORT)
               		drv_trace0(TRACE_GROUP_10, RTC_SW_CALI_ALARM_POWERON_AND_NEED_BACKWARD_TIME);
#endif // #if !defined(LOW_COST_SUPPORT)

					pwroff_inacc_ticks = -pwroff_inacc_ticks;
					hours = pwroff_inacc_ticks / (13000 * 60);
					pwroff_inacc_ticks = pwroff_inacc_ticks % (13000 * 60);
					mins = pwroff_inacc_ticks / 13000;
					pwroff_inacc_ticks = pwroff_inacc_ticks % 13000;
					secs = pwroff_inacc_ticks * 3 / 650;
					
					RTC_GetALTime(&alarm_time);

					/* calculate the correct time */
					rtc_backward_time(&time, hours, mins, secs);
					/* Check if the correct time is before the alarm time. */
					if (KAL_TRUE == rtc_compare_time(&alarm_time, &time))
					{
						#ifdef RTC_CAL_DEBUG2
						kal_prompt_trace(MOD_RTC_HISR, "Alarm power on, and power off the phone");
						#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
                  		drv_trace0(TRACE_GROUP_10, RTC_SW_CALI_ALARM_POWERON_AND_POWEROFF);
#endif // #if !defined(LOW_COST_SUPPORT)
                  
						RTC_Cali_Time(&time);
						/* invalidate DRV_COMM_REG2_RTC_NVRAM because time has been calibrated. */
						reg_comm2 &= ~(DRV_COMM_REG2_RTC_NVRAM);
						DRV_RTC_WriteReg(DRV_COMM_REG2,reg_comm2);
						#if defined(DRV_RTC_HW_CALI)
						RTC_write_trigger();
						#endif /*DRV_RTC_HW_CALI*/
						/* Power off the phone and wait for alarm power on again.*/
						DclPW_Control(pw_handle,PW_CMD_POWEROFF,NULL);
						DclPW_Close(pw_handle);
               		}
            	}
         	} /* if ((valid == */
      	} /* if((reg & DRV_COMM_REG2_RTC_NVRAM */
   	} /* if((KAL_FALSE == RTC_isFisrtOn() */
}

/*
* FUNCTION                                                            
*	rtc_system_timer_cb
*
* DESCRIPTION                                                           
*     system timer callback function
*
* CALLS  
*	This function is called when calibration timer time out
*
* PARAMETERS
*	timer_param
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void rtc_system_timer_cb(void *timer_param)
{
//	kal_uint32 savedMask;
   	kal_uint8  rtc_sec;

#if defined(SLEEP_WORKAROUND_IN_RTC)
#if (!defined(__L1_STANDALONE__)) 
	kal_uint32 current_frame_tick;
#endif
#endif // #if defined(SLEEP_WORKAROUND_IN_RTC)

   	rtc_sec = DRV_RTC_Reg(RTC_TC_SEC);
	if ((rtc_tc_int_var != TC_EN_None) && (rtc_tc_int_var != TC_EN_ChkS))
	{
		/* avoid the situation when rtc_sec is around zero for minute interrupt. */
		if (rtc_sec < 3 || rtc_sec > 57)
		{
			#ifdef RTC_CAL_DEBUG
			kal_prompt_trace(MOD_RTC_HISR, "rtc time is in minute boundary :(%d): calibration delays 6 secs. ", rtc_sec);
			#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
         	drv_trace1(TRACE_GROUP_10, RTC_SW_CALI_RTC_TIME_IN_MINUTE_BOUNDARY, rtc_sec);
#endif // #if !defined(LOW_COST_SUPPORT)
			
			/* To skip the miniute boundary, delay about 6 secs to do the calibration. */
			kal_set_timer(rtc_timer_id, (kal_timer_func_ptr)rtc_system_timer_cb, NULL, 1300 , 0);
			return;
      	}
   	}
#if defined(SLEEP_WORKAROUND_IN_RTC)
	// Added by GuoXin begin
	// New check case: If KAL timer expired early than the time we expected, 
	// we set KAL timer to 6 sec later
	#if (!defined(__L1_STANDALONE__)) 
	current_frame_tick = L1I_GetTimeStamp();
	/* Calculate the different ticks between the current time and expected time for calibration timeout. */
	if(current_frame_tick < next_frame_tick){
		#ifdef RTC_CAL_DEBUG
		kal_prompt_trace(MOD_RTC_HISR, "(1)KAL time out early, expected:%d (ticks), now:%d \r\n", next_frame_tick, current_frame_tick);
		#endif /* RTC_CAL_DEBUG */
		kal_set_timer(rtc_timer_id, (kal_timer_func_ptr)rtc_system_timer_cb, NULL, 1300 ,0);
		return;
	}
	#endif // #if (!defined(__L1_STANDALONE__)) 
	// Added by GuoXin end
#endif // #if defined(SLEEP_WORKAROUND_IN_RTC)
	if (rtc_al_int_var != AL_EN_None)
   	{
		kal_uint8  al_rtc_sec;
		kal_uint8  sec_diff;

		al_rtc_sec = DRV_RTC_Reg(RTC_AL_SEC);
		sec_diff = (rtc_sec >= al_rtc_sec) ? (rtc_sec - al_rtc_sec) : (al_rtc_sec - rtc_sec);
		/* avoid the situation when al_rtc_sec is around rtc_sec for alarm interrupt. */
		if (sec_diff < 3 || sec_diff > 57)
		{
			#ifdef RTC_CAL_DEBUG
			kal_prompt_trace(MOD_RTC_HISR, "rtc time is in alarm boundary :(%d): calibration delays 6 secs. ", rtc_sec);
			#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
        	drv_trace1(TRACE_GROUP_10, RTC_SW_CALI_RTC_TIME_IN_ALARM_BOUNDARY, rtc_sec);
#endif // #if !defined(LOW_COST_SUPPORT)
		
		/* To skip the alarm boundary, delay about 6 secs to do the calibration. */
			kal_set_timer(rtc_timer_id, (kal_timer_func_ptr)rtc_system_timer_cb, NULL, 1300 , 0);
			return;
      	}
   	}
//	savedMask = SaveAndSetIRQMask();
 	rtc_update_time();      
//  RestoreIRQMask(savedMask);   
}  
#endif /* RTC_SW_CALIBRATION */

#if defined(RTC_HW_CALIBRATION) || defined(RTC_SW_CALIBRATION)
/*
* FUNCTION                                                            
*	rtc_cali_init
*
* DESCRIPTION                                                           
*     Initialize rtc calibration
*
* CALLS  
*	This function is called at power on or user configures time.
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void rtc_cali_init(void *timer_param)
{   
#if defined(RTC_SW_CALIBRATION)
	kal_uint32 frame_tick = 0;
#endif /* RTC_SW_CALIBRATION */

	if (cali_state == (kal_uint8)CAL_STATE_NONE)
	{
#ifdef RTC_HW_CALIBRATION
		/* Change calibration state to init and enable RTC minute interrupt.
		   And wait 'till the RTC minute expired to start calibration. */
		cali_state = (kal_uint8)CAL_STATE_INIT;
		if (rtc_tc_int_var != TC_EN_ChkM)
#elif defined(RTC_SW_CALIBRATION)
		/* Change calibration state to init and enable RTC second interrupt.
		   And wait 'till the RTC second expired to start calibration. */
	    cali_state = (kal_uint8)CAL_STATE_INIT;
    	if (rtc_tc_int_var != TC_EN_ChkS)
#endif
    	{
			kal_uint16 tmp;
			
			tmp = DRV_RTC_Reg(RTC_IRQ_EN);
			tmp &= ~RTC_IRQ_EN_ONESHOT;
			tmp |= RTC_IRQ_EN_TC;
	   	   	DRV_RTC_WriteReg(RTC_IRQ_EN,tmp);
#ifdef RTC_HW_CALIBRATION
			DRV_RTC_WriteReg(RTC_CII_EN,RTC_CII_EN_MIN);
	        RTC_write_trigger_wait();
    	}
		tc_min_expire_cnt = 0;
		no_diff_cnt = 0;
		rtc_current_freq_8secs = RTC_STANDARD_FREQ_8SECS + rtc_get_cali_offset();
		#ifdef RTC_CAL_DEBUG
		kal_prompt_trace(MOD_RTC_HISR, "Initial: repeat calibration count is %d \r\n", (rtc_current_freq_8secs - RTC_STANDARD_FREQ_8SECS));
		#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
      	drv_trace1(TRACE_GROUP_10, RTC_HW_CALI_INIT_REPEAT_CALI_COUNT, (rtc_current_freq_8secs - RTC_STANDARD_FREQ_8SECS));
#endif // #if !defined(LOW_COST_SUPPORT)
	}
#elif defined(RTC_SW_CALIBRATION)
			DRV_RTC_WriteReg(RTC_CII_EN,RTC_CII_EN_SEC);
      	}
   	}
   	else if ((cali_state == (kal_uint8)CAL_STATE_INIT2) || (cali_state == (kal_uint8)CAL_STATE_RESET))
   	{
		/* next_current_time has already been set before in RTC_InitTC_Time() or RTC_TCintr(). */
		if (cali_state == (kal_uint8)CAL_STATE_INIT2)
      	{
			/* Set the adjusted correct time (power off calibration) in this moment. */
			RTC_Cali_Time(&next_current_time);
			#ifdef RTC_CAL_DEBUG2
			kal_prompt_trace(MOD_RTC_HISR, "current time after 2nd poweroff calibration - (%d:%d:%d)",
			next_current_time.rtc_hour, next_current_time.rtc_min, next_current_time.rtc_sec);
			#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
         	drv_trace4(TRACE_GROUP_10, RTC_SW_CALI_AFTER_2ND_POWEROFF_CALI, next_current_time.rtc_hour, next_current_time.rtc_min, next_current_time.rtc_sec, 0);
#endif // #if !defined(LOW_COST_SUPPORT)
        }
		/* Start power on calibration by KAL timer. */
		kal_set_timer(rtc_timer_id, (kal_timer_func_ptr)rtc_system_timer_cb, NULL, rtc_cali_tick_value + rtc_cali_tick_safe_margin, 0);
		#if (!defined(__L1_STANDALONE__)) 
		frame_tick = L1I_GetTimeStamp();
		#endif
		#ifdef RTC_CAL_DEBUG
		kal_prompt_trace(MOD_RTC_HISR, "Start poweron calibration");
		kal_prompt_trace(MOD_RTC_HISR, "(%d:%d:%d): ", next_current_time.rtc_hour, next_current_time.rtc_min, next_current_time.rtc_sec);
		kal_prompt_trace(MOD_RTC_HISR, "ini tick=%d\r\n", frame_tick);                                                   
		#endif /* RTC_CAL_DEBUG */
#if !defined(LOW_COST_SUPPORT)
      	drv_trace4(TRACE_GROUP_10, RTC_SW_CALI_POWERON_CALI_START, next_current_time.rtc_hour, next_current_time.rtc_min, next_current_time.rtc_sec, frame_tick);
#endif // #if !defined(LOW_COST_SUPPORT)
      
		tick_left = 0;
		one_third_tick_count = 0;
		tc_min_expire_cnt = 0;
		next_frame_tick = frame_tick + rtc_cali_tick_value;         
		rtc_get_next_time();
		/* Change to "start" state. */
		cali_state = (kal_uint8)CAL_STATE_START;
   	}
#endif /* RTC_SW_CALIBRATION */
}   

/*
* FUNCTION                                                            
*	rtc_sleep_wa_timer_cb
*
* DESCRIPTION                                                           
*  The sleep mode workaround timer callback handler
*
* CALLS  
*	This function is called when we are going to perform RTC S/W calibration hourly
*   When 59 min reaches, we enable kal timer with this function as callback function
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
#if defined(SLEEP_WORKAROUND_IN_RTC)
void rtc_sleep_wa_timer_cb(void *timer_param){
	kal_uint32 rtc_sleep_wa_delay_tick;
	t_rtc current_time;
	
	// Get reference time of 59th min
	RTC_GetTime_(&current_time);

	// Protection check, in case kal timer expires after we finished calibration process:
	// to avoid the following case:
	// calbration process -> enable sleep mode -> kal timer trigger to disable sleep mode
	if ( (tc_min_expire_cnt == 60) ){
		
		// Check if we expire early, if expire early ==> Re-start kal disable sleep timer
		// We only do this when tc_min_expire_cnt == 60, or means we expire too late
		if (current_time.rtc_sec < 58){
			// Calculate how many ticks we should wait to disable sleep mode
			// We plan to wakeup at 58 sec
			rtc_sleep_wa_delay_tick = 58 - (kal_uint32)current_time.rtc_sec;
			rtc_sleep_wa_delay_tick = (kal_uint32) ((rtc_sleep_wa_delay_tick * 1000 * 60) / 13);
			// Set kal timer in order to disable sleep mode for RTC calibration
			kal_set_timer(rtc_sleep_wa_timer_id, (kal_timer_func_ptr)rtc_sleep_wa_timer_cb, NULL, rtc_sleep_wa_delay_tick,0);
			#ifdef RTC_SLEEP_WA_DEBUG
			kal_prompt_trace(MOD_RTC_HISR, "SleepWA: (%d:%d), Re-start disable sleep timer with tick: %d", 
					current_time.rtc_min, current_time.rtc_sec, rtc_sleep_wa_delay_tick);
			#endif /* RTC_SLEEP_WA_DEBUG */
			return;
		}		
		
		// Disable sleep mode, because we are going to perform RTC calibration in few seconds
		rtc_sleep_wa_disable_sleep_mode();
		rtc_sleep_wa_disable_sleep_performed = KAL_TRUE;
		#ifdef RTC_SLEEP_WA_DEBUG
		kal_prompt_trace(MOD_RTC_HISR, "SleepWA: (%d:%d), Disable sleep mode", 
					current_time.rtc_min, current_time.rtc_sec);
		#endif /* RTC_SLEEP_WA_DEBUG */
	}else{
		#ifdef RTC_SLEEP_WA_DEBUG
		kal_prompt_trace(MOD_RTC_HISR, "SleepWA: (%d:%d), Warning!!, disable sleep timer expired too late", 
					current_time.rtc_min, current_time.rtc_sec);
		#endif /* RTC_SLEEP_WA_DEBUG */
	}	
}

void rtc_sleep_wa_enable_sleep_mode(){
	L1SM_SleepEnable(rtc_sleep_wa_handle);
}
void rtc_sleep_wa_disable_sleep_mode(){
	L1SM_SleepDisable(rtc_sleep_wa_handle);
}
#endif // #ifdef SLEEP_WORKAROUND_IN_RTC

#endif /* defined(RTC_HW_CALIBRATION) || defined(RTC_SW_CALIBRATION) */

/*
* FUNCTION                                                            
*	RTC_start_cali
*
* DESCRIPTION                                                           
*  The entry function of RTC calibration.
*
* CALLS  
*	This function is called in bmt_task_init()(in bmt_create.c) because at this moment of the 
*  function, the file system is ready for accessing nvram data.
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_start_cali(void)
{
#if defined(RTC_SW_CALIBRATION) || defined(RTC_HW_CALIBRATION)
	#if defined(__USB_ENABLE__) && !defined(__NVRAM_IN_USB_MS__)
	/* In this compile option case, when it's USB mode powered on we can't do RTC calibration
		because L1 time stamp won't be updated (L1I_GetTimeStamp()). */
	PW_CTRL_IS_USB_BOOT IsUsbBoot;
	DCL_HANDLE pw_handle;
	pw_handle=DclPW_Open(DCL_PW, FLAGS_NONE);
	DclPW_Control(pw_handle, PW_CMD_IS_USB_BOOT,(DCL_CTRL_DATA_T *)&IsUsbBoot);
	DclPW_Close(pw_handle);

	if (KAL_FALSE == IsUsbBoot.val )
	{
   	#endif
		#if (!defined(__L1_STANDALONE__)) 	
		#if defined(RTC_HW_CALIBRATION)
		rtc_cali_init(0);
		#elif defined(RTC_SW_CALIBRATION)
		rtc_timer_id=kal_create_timer("RTCcal_Timer");
		rtc_poweroff_cali_init();
		kal_set_timer(rtc_timer_id, (kal_timer_func_ptr)rtc_cali_init, NULL, 1,	0);
		#endif
		#endif /* (!defined(__L1_STANDALONE__)) */
		#if defined(SLEEP_WORKAROUND_IN_RTC)
		rtc_sleep_wa_timer_id = kal_create_timer("RTC_sleep_wa_Timer");
		rtc_sleep_wa_handle = L1SM_GetHandle();
		#endif // #if defined(SLEEP_WORKAROUND_IN_RTC)
	#if defined(__USB_ENABLE__) && !defined(__NVRAM_IN_USB_MS__)
	}
	#endif
#endif /* defined(RTC_SW_CALIBRATION) || defined(RTC_HW_CALIBRATION) */
}

/*
* FUNCTION                                                            
*	RTC_init_
*
* DESCRIPTION                                                           
*     RTC initialization function
*
* CALLS  
*	This function is initialize RTC software
*
* PARAMETERS
*	RTC_TCCallback: time update callback function
*	RTC_ALCallback: alarm callback function
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_init_(void (*RTC_TCCallback)(void), void (*RTC_ALCallback)(void)) // Validate
{
	/* status = DRV_RTC_Reg(RTC_IRQ_STATUS); */
	RTC_CALLBAC.rtc_tcfunc = RTC_TCCallback;
	RTC_CALLBAC.rtc_alfunc = RTC_ALCallback;
	/* *(volatile kal_uint16 *)RTC_IRQ_EN = RTC_IRQ_EN_ONESHOT; */
	/* DRV_RTC_WriteReg(RTC_IRQ_EN,RTC_IRQ_EN_ALLOFF); */

	if (RTCConfig.hisr == NULL)
	{
	   	//RTCConfig.hisr = kal_create_hisr("RTC_HISR", 2, 512, RTC_HISR,NULL);
	   	RTCConfig.hisr = (void *)0x1234;
	   	DRV_Register_HISR(DRV_RTC_HISR_ID, RTC_HISR);
	}   
   	/*RTC IRQ configuration*/
   	#ifdef __MULTI_BOOT__
	if (INT_BootMode() == MTK_NORMAL_MODE)
	{
    	IRQ_Register_LISR(IRQ_RTC_CODE, RTC_LISR, "RTC handler");
		IRQSensitivity(IRQ_RTC_CODE, LEVEL_SENSITIVE);
		#if !defined(IC_MODULE_TEST) // Disable RTC interrupt in module test
      	IRQUnmask(IRQ_RTC_CODE);
      	#endif
   	}
   	#else /*__MULTI_BOOT__*/
   	IRQ_Register_LISR(IRQ_RTC_CODE, RTC_LISR, "RTC handler");
   	IRQSensitivity(IRQ_RTC_CODE, LEVEL_SENSITIVE);
	#if !defined(IC_MODULE_TEST) // Disable RTC interrupt in module test
    IRQUnmask(IRQ_RTC_CODE);
    #endif
   	#endif   /*__MULTI_BOOT__*/
	/*config RTC driving current*/
	/*
	#if defined(DRV_RTC_XOSC_DEF_8)
	DRV_RTC_WriteReg(RTC_XOSCCAL,0x8);
	#endif
	*/

    /* init rtc_reg_mod_ilm_info array */
#if !defined(__FUE__) && !defined(__UBL__) 
    {
        kal_uint16 index;
        index = 0;
        while (index < MODULE_REGISTER_ILM_MAX_NUM)
        {
            rtc_reg_mod_ilm_info[index].dest_mod_id = MOD_NIL;
            rtc_reg_mod_ilm_info[index].sap_id = INVALID_SAP;
            rtc_reg_mod_ilm_info[index].msg_id = MSG_ID_INVALID_TYPE;
            index++;
        }
    }    
#endif
    
}

#if defined(DRV_RTC_HW_CALI)
/*
* FUNCTION                                                            
*	RTC_clrpky
*
* DESCRIPTION                                                           
*     Clear powerkey1 and powerkey2 at the same time.
*
* CALLS  
*	When want to clear powerkey value.
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_clrpky(void)
{
	kal_uint16 reg;
	
	reg = DRV_RTC_Reg(RTC_BBPU);
	reg |= (RTC_BBPU_CLRPKY | RTC_BBPU_KEY);
	#if defined(DRV_RTC_WRITE_ENABLE)
	reg |= RTC_BBPU_WRITE_EN;
	#endif // #if defined(DRV_RTC_WRITE_ENABLE)
	DRV_RTC_WriteReg(RTC_BBPU, reg);
}
#endif /* DRV_RTC_HW_CALI */
#endif /* !defined(__FUE__) && !defined(__UBL__) */

#if defined(DRV_RTC_HW_CALI)
#if defined(DRV_RTC_DBING)
/*
* FUNCTION                                                            
*	RTC_wait_debounce
*
* DESCRIPTION                                                           
*     To wait until RTC is not in debouncing
*
* CALLS  
*	This function is called in RTC initialization
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_wait_debounce(void)
{
	kal_uint32 count = 0;
#if defined(DRV_RTC_SHORTER_CBUSY_POLLING)
    while(count < 0x6EEEEE)
#else
	while(count < 0xffffffff)
#endif
	{
		if ((RTC_BBPU_DBING & DRV_RTC_Reg(RTC_BBPU)) == 0)
			break;
		count++;
	}
	#ifdef RTC_CAL_DEBUG
	kal_prompt_trace(MOD_RTC_HISR, "RTC wait debounce count = %x\r\n", count);
	#endif /* RTC_CAL_DEBUG */
}
#endif //#if defined(DRV_RTC_DBING)

#if defined(DRV_RTC_SHORTER_CBUSY_POLLING)
/*
* FUNCTION                                                            
*	RTC_wait_busy_shorter
*
* DESCRIPTION                                                           
*     To wait until the read/write channels between RTC / Core is not busy
*
* CALLS  
*	This function is called after RTC register is written and triggered
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_wait_busy_shorter(void)
{
	kal_uint32 count = 0;
	//6EEEEE = 1 second
	while(count < 0x6EEEEE)
	{
	  	if ((RTC_BBPU_CBUSY & DRV_RTC_Reg(RTC_BBPU)) == 0)
	     	break;
	  	count++;
	}
	#ifdef RTC_CAL_DEBUG
	kal_prompt_trace(MOD_RTC_HISR, "RTC wait busy count = %x\r\n", count);
	#endif /* RTC_CAL_DEBUG */
}
#endif//#if defined(DRV_RTC_SHORTER_CBUSY_POLLING)

/*
* FUNCTION                                                            
*	RTC_wait_busy
*
* DESCRIPTION                                                           
*     To wait until the read/write channels between RTC / Core is not busy
*
* CALLS  
*	This function is called after RTC register is written and triggered
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_wait_busy(void)
{
	kal_uint32 count = 0;
#if defined(DRV_RTC_SHORTER_CBUSY_POLLING)
    while(count < 0x6EEEEE)
#else
	while(count < 0xffffffff)
#endif
	{
		if ((RTC_BBPU_CBUSY & DRV_RTC_Reg(RTC_BBPU)) == 0)
			break;
		count++;
	}
	#ifdef RTC_CAL_DEBUG
	kal_prompt_trace(MOD_RTC_HISR, "RTC wait busy count = %x\r\n",count);
	#endif /* RTC_CAL_DEBUG */
}

/*
* FUNCTION                                                            
*	RTC_HW_Init_
*
* DESCRIPTION                                                           
*     RTC hardware initialization function
*
* CALLS  
*	This function is initialize RTC HW
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_HW_Init_(void)
{
#if defined(DRV_RTC_DBING)
	// Wait H/W mechanism to issue reload command automatically at power on phase begin
	RTC_wait_debounce();
#endif // #if defined(DRV_RTC_DBING)

#if defined(DRV_RTC_SHORTER_CBUSY_POLLING)
   	RTC_wait_busy_shorter();
#else
	RTC_wait_busy();
#endif // #if defined(DRV_RTC_SHORTER_CBUSY_POLLING)
  	// Wait H/W mechanism to issue reload command automatically at power on phase end
	// We are afraid H/W mechanism failed ...
  	RTC_reload();
  	RTC_write_trigger_wait();
  	// We are afraid H/W mechanism failed ...
}
#else
void RTC_HW_Init_(void){} // For FOTA build on not defined (DRV_RTC_HW_CALI) platform
#endif /* DRV_RTC_HW_CALI */

/*
* FUNCTION                                                            
*	RTC_is_Time_Valid
*
* DESCRIPTION                                                           
*  Check if time are valid. 
*  If these time values are not correct, return false.
*
* CALLS  
*	This function is to check if time are valid.
*
* PARAMETERS
* valid or not
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/

kal_bool RTC_is_Time_Valid(t_rtc *time)
{
    if((time->rtc_sec > 59) || 
      	(time->rtc_min > 59) || 
      	(time->rtc_hour > 23) || 
      	(time->rtc_day > 31) || (time->rtc_day == 0) ||
      	(time->rtc_mon > 12) || (time->rtc_mon == 0) ||
      	(time->rtc_year > 127))
   	{   
#if (!defined(LOW_COST_SUPPORT) && !defined(__FUE__) && !defined(__UBL__) )
     	drv_trace8(TRACE_GROUP_9, RTC_TIME_NOT_VALID, time->rtc_year, time->rtc_mon,
            time->rtc_day, time->rtc_hour, time->rtc_min, time->rtc_sec, 0, 0);
#endif
      	return KAL_FALSE;
   	}
#if (!defined(LOW_COST_SUPPORT) && !defined(__FUE__) && !defined(__UBL__))
    drv_trace8(TRACE_GROUP_9, RTC_TIME_VALID, time->rtc_year, time->rtc_mon,
		time->rtc_day, time->rtc_hour, time->rtc_min, time->rtc_sec, 0, 0);
#endif   
   	return KAL_TRUE;
}

/*
* FUNCTION                                                            
*	RTC_is_config_valid
*
* DESCRIPTION                                                           
*  Check if RTC time and Alarm are valid. If these
*  settings are not correct, we treat it as first power on and
*  reconfigure RTC.
*
* CALLS  
*	This function is to check if RTC time and Alarm are valid.
*
* PARAMETERS
* valid or not
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/

kal_bool RTC_is_config_valid(void)
{
	t_rtc time, alarm;
	
	RTC_GetTimeOnly(&time);
	RTC_GetALTime(&alarm);
	
	if( (RTC_is_Time_Valid(&time) == KAL_FALSE) || (RTC_is_Time_Valid(&alarm) == KAL_FALSE))
	{   
#if !defined(LOW_COST_SUPPORT)
#if !defined(__FUE__) && !defined(__UBL__)
		drv_trace8(TRACE_GROUP_9, RTC_NOT_CONFIG_VALID_TIME, time.rtc_year, time.rtc_mon,
			time.rtc_day, time.rtc_hour, time.rtc_min, time.rtc_sec, 0, 0);
		drv_trace8(TRACE_GROUP_9, RTC_NOT_CONFIG_VALID_ALARM, alarm.rtc_year, alarm.rtc_mon,
		    alarm.rtc_day, alarm.rtc_hour, alarm.rtc_min, alarm.rtc_sec, 0, 0);
#endif
#endif
		alarm.rtc_sec=0;
		alarm.rtc_min=0;
		alarm.rtc_hour=0;
		alarm.rtc_day=1;
		alarm.rtc_wday=1;
		alarm.rtc_mon=1;
		RTC_SetAlarm(&alarm);
		return KAL_FALSE;      
	}
#if !defined(LOW_COST_SUPPORT)
#if !defined(__FUE__) && !defined(__UBL__)
		drv_trace8(TRACE_GROUP_9, RTC_IS_CONFIG_VALID_TIME, time.rtc_year, time.rtc_mon,
				time.rtc_day, time.rtc_hour, time.rtc_min, time.rtc_sec, 0, 0);
		drv_trace8(TRACE_GROUP_9, RTC_IS_CONFIG_VALID_ALARM, alarm.rtc_year, alarm.rtc_mon,
		        alarm.rtc_day, alarm.rtc_hour, alarm.rtc_min, alarm.rtc_sec, 0, 0);
#endif
#endif
   	return KAL_TRUE;
}   

/*
* FUNCTION                                                            
*	RTC_read_xosc_reg
*
* DESCRIPTION                                                           
*  Read RTC XOSC register value
*
* CALLS  
*	This function is for enginner mode.
*
* PARAMETERS
*  None
*	
* RETURNS
*	RTC XOSC register value
*
* GLOBALS AFFECTED
*   external_global
*/
kal_uint8 RTC_read_xosc_reg(void)
{
	kal_uint16   value;
	
	value = DRV_RTC_Reg(RTC_XOSCCAL);
	return ((kal_uint8)value);
}

/*
* FUNCTION                                                            
*	RTC_write_xosc_reg
*
* DESCRIPTION                                                           
*  Set RTC XOSC register value.
*
* CALLS  
*	This function is for enginner mode.
*
* PARAMETERS
*  RTC XOSC register value to set.
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_write_xosc_reg(kal_uint16 reg_value)
{

#if defined(DRV_RTC_XOSC_UPDATE)
	DRV_RTC_WriteReg(RTC_XOSCCAL, 0x1a57);
	while(DRV_RTC_Reg(RTC_BBPU) & 0x40);
	DRV_RTC_WriteReg(RTC_XOSCCAL, 0x2b68);
	while(DRV_RTC_Reg(RTC_BBPU) & 0x40);	
#endif /* defined(DRV_RTC_XOSC_UPDATE) */

   	DRV_RTC_WriteReg(RTC_XOSCCAL, ((kal_uint16)reg_value));

#if defined(DRV_RTC_XOSC_UPDATE)
	while(DRV_RTC_Reg(RTC_BBPU) & 0x40);
#endif /* defined(DRV_RTC_XOSC_UPDATE) */

#if defined(DRV_RTC_HW_CALI)
   	RTC_write_trigger_wait();
#endif
}

/*
* FUNCTION                                                            
*	RTC_original_pnd1
*
* DESCRIPTION                                                           
*  Read RTC original pdn1 value
*
* CALLS  
*	This function is for DVT test
*
* PARAMETERS
*  None
*	
* RETURNS
*	RTC saved pdn1 register value.
*
* GLOBALS AFFECTED
*   external_global
*/
#if defined(DRV_RTC_REG_COMM)
kal_uint16 RTC_original_pnd1(void)
{
   	return originalPDN1;
}

kal_uint16 RTC_Read_PDN(RTC_PDN_INDEX PDNIndex)
{
	kal_uint16 REG_COMM = 0;

	switch(PDNIndex)
	{
		case rtc_pdn1:
			REG_COMM = DRV_RTC_Reg(DRV_COMM_REG1);
#if !defined(DRV_RTC_PDN_EXTEND)		
			REG_COMM &= RTC_PDN1_MASK;
#endif /*!defined(DRV_RTC_PDN_EXTEND)*/
			break;
		case rtc_pdn2:
			REG_COMM = DRV_RTC_Reg(DRV_COMM_REG2);
			break;

		default:
		ASSERT(0);
			break;
	}
	return REG_COMM;
}



void RTC_Set_PDN_bits(RTC_PDN_INDEX PDNIndex, kal_uint16 flag)
{
#ifndef DRV_RTC_HW_CALI
    kal_uint32 count;
#endif // #if defined(DRV_RTC_HW_CALI)
    kal_uint32 loop;
    kal_uint32 reg_addr = 0;
    kal_uint16 REG_COMM;

    switch(PDNIndex)
    {
        case rtc_pdn1:
#if !defined(DRV_RTC_PDN_EXTEND)  	
            if ((flag & ~(RTC_PDN1_MASK)) != 0)
                ASSERT(0);
#endif /*!defined(DRV_RTC_PDN_EXTEND)*/
            
            reg_addr = DRV_COMM_REG1;           
            break;
            
        case rtc_pdn2:
            reg_addr = DRV_COMM_REG2;
            break;

        default:
            ASSERT(0);
            break;
    }

    REG_COMM = DRV_RTC_Reg(reg_addr);
    REG_COMM |= flag;
    for (loop = 0; loop < 1000000; loop++)
    {
        DRV_RTC_WriteReg(reg_addr, REG_COMM);

        #if defined(DRV_RTC_HW_CALI)
        // RTC_write_trigger();
        RTC_write_trigger_wait();
        #else
        for(count = 0; count < 1000; count++){};
        #endif /* DRV_RTC_HW_CALI */

        if (DRV_RTC_Reg(reg_addr) == REG_COMM) 
            break; 
    } 
    
}

void RTC_Clear_PDN_bits(RTC_PDN_INDEX PDNIndex, kal_uint16 flag)
{
#ifndef DRV_RTC_HW_CALI
    kal_uint32 count;
#endif // #if defined(DRV_RTC_HW_CALI)
    kal_uint32 loop;
    kal_uint32 reg_addr = 0;
    kal_uint16 REG_COMM;

    switch(PDNIndex)
    {
        case rtc_pdn1:
#if !defined(DRV_RTC_PDN_EXTEND)	  	
            if ((flag & ~(RTC_PDN1_MASK)) != 0)
                ASSERT(0);
#endif /*!defined(DRV_RTC_PDN_EXTEND)*/		

            reg_addr = DRV_COMM_REG1;
            break;
        
        case rtc_pdn2:
            reg_addr = DRV_COMM_REG2;
            break;

        default:
            ASSERT(0);
            break;
    }

    REG_COMM = DRV_RTC_Reg(reg_addr);
    REG_COMM &= ~(flag);
    for (loop = 0; loop < 1000000; loop++)
    {             
        DRV_RTC_WriteReg(reg_addr, REG_COMM);

        #if defined(DRV_RTC_HW_CALI)
        // RTC_write_trigger();
        RTC_write_trigger_wait();
        #else
        for(count = 0; count < 1000; count++){};
        #endif /* DRV_RTC_HW_CALI */

        if (DRV_RTC_Reg(reg_addr) == REG_COMM)
            break;
    }
    
}

void RTC_Write_PDN_bits(RTC_PDN_INDEX PDNIndex, kal_uint16 flag)
{
#ifndef DRV_RTC_HW_CALI
    kal_uint32 count;
#endif // #if defined(DRV_RTC_HW_CALI)
    kal_uint32 loop;
    kal_uint32 reg_addr = 0;

#if !defined(DRV_RTC_PDN_EXTEND)	
    kal_uint16 REG_COMM = 0;
#endif /*!defined(DRV_RTC_PDN_EXTEND)*/	

    switch(PDNIndex)
    {
        case rtc_pdn1:
#if !defined(DRV_RTC_PDN_EXTEND)		  	
            if ((flag & ~(RTC_PDN1_MASK)) != 0)
                ASSERT(0);
            REG_COMM = DRV_RTC_Reg(DRV_COMM_REG1);
            flag |= REG_COMM & ~(RTC_PDN1_MASK);
#endif /*!defined(DRV_RTC_PDN_EXTEND)*/			

            reg_addr = DRV_COMM_REG1;
            break;

        case rtc_pdn2:
            reg_addr = DRV_COMM_REG2;
            break;
            
        default:
            ASSERT(0);
            break;
    }

    for (loop = 0; loop < 1000000; loop++)
    { 
        DRV_RTC_WriteReg(reg_addr, flag);

        #if defined(DRV_RTC_HW_CALI)
        // RTC_write_trigger();
        RTC_write_trigger_wait();
        #else
        for(count = 0; count < 1000; count++){};
        #endif /*DRV_RTC_HW_CALI*/

        if (DRV_RTC_Reg(reg_addr) == flag)
            break;
    }   
    
}

// For Flash Tool Power Off
kal_bool RTC_FT_PowerOff(void)
{
#if !defined(MT6208)    
    kal_uint16 REG_COMM = 0;

#if defined(DRV_RTC_DBING)
    RTC_wait_debounce();
#endif // #if defined(DRV_RTC_DBING)

    REG_COMM = DRV_RTC_Reg(DRV_COMM_REG1);

    // release power to shutdown target
    // if RTC_PDN1 bit7 is 1 by Flash Tool download, RTC_POWERKEY1 have to reset
    if(REG_COMM & DRV_COMM_REG1_META_RESET_RTC) {
        // Reset RTC_PDN1 bit7 to zero
        DRV_RTC_WriteReg(DRV_COMM_REG1, (kal_uint16)(REG_COMM & (~DRV_COMM_REG1_META_RESET_RTC)));
#if defined(DRV_RTC_HW_CALI)
        // Write trigger wait
        RTC_write_trigger_wait();
#endif
        // Set RTC_POWERKEY1 to any value other than 0xA357 to release power
        // RTC date-time value is reset to default value
        DRV_RTC_WriteReg(RTC_POWERKEY1, 0x1234);
#if defined(DRV_RTC_HW_CALI)
    	// Write trigger wait
    	RTC_write_trigger_wait();
#endif

		return KAL_TRUE;
    }
    else {
        // pull down RTC_BBPU register BBPU bit to release power
        // RTC date-time value is preserved
        REG_COMM = DRV_RTC_Reg(RTC_BBPU);
        DRV_RTC_WriteReg(RTC_BBPU, (kal_uint16)((REG_COMM & 0x0009) | 0x4300));
#if defined(DRV_RTC_HW_CALI)
    	// Write trigger wait
    	RTC_write_trigger_wait();
#endif
		return KAL_FALSE;
    }
    // for 35, 38, 39~later series chip!,
    //drv_comm.h -> drv_features.h -> drv_features_option.h

#endif // #if !defined(MT6208)
}
#endif //#if defined(DRV_RTC_REG_COMM)

#if defined(DRV_RTC_REG_SPAR)
kal_uint16 RTC_Read_SPAR(RTC_SPAR_INDEX SPARIndex)
{
	kal_uint16 REG_COMM = 0;

	switch(SPARIndex)
	{
		case rtc_spar0:
			REG_COMM = DRV_RTC_Reg(RTC_SPAR0);
			break;
		case rtc_spar1:
			REG_COMM = DRV_RTC_Reg(RTC_SPAR1);
			break;

		default:
		ASSERT(0);
			break;
	}
	return REG_COMM;
}

void RTC_Write_SPAR(RTC_SPAR_INDEX SPARIndex, kal_uint16 flag)
{
#ifndef DRV_RTC_HW_CALI
	kal_uint32 loop;
#endif // #if defined(DRV_RTC_HW_CALI)

	switch(SPARIndex)
	{
		case rtc_spar0:
			DRV_RTC_WriteReg(RTC_SPAR0, flag);
 			break;
		case rtc_spar1:
			DRV_RTC_WriteReg(RTC_SPAR1, flag);
 			break;
		default:
 			ASSERT(0);
 			break;
	}

#if defined(DRV_RTC_HW_CALI)
	// RTC_write_trigger();
	RTC_write_trigger_wait();
#else
	for(loop = 0; loop < 1000; loop++){};
#endif /*DRV_RTC_HW_CALI*/
}
#endif // End of #if defined(DRV_RTC_REG_SPAR)
/*
* FUNCTION                                                            
*	RTC_IRQ_Enable
*
* DESCRIPTION                                                           
*   	This function is to enable RTC IRQ
*
* CALLS  
*
* PARAMETERS
*	en: KAL_TRUE, enable RTC IRQ
*	    FASLE, disable RTC IRQ
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void RTC_IRQ_Enable(kal_bool en)
{
	if (en == KAL_TRUE)
	{
		IRQUnmask(IRQ_RTC_CODE);
	}
	else
	{
		IRQMask(IRQ_RTC_CODE);
	}
}

void RTC_PWIC_PowerOff_RTC_INIT(void)
{
	kal_uint16 BBPU;

   	#if defined(DRV_RTC_NO_REG_COMM) || defined(FPGA)
   	// MT6205 //MT6208
	BBPU = DRV_RTC_Reg(RTC_BBPU);
	BBPU |= (RTC_BBPU_KEY | RTC_BBPU_PWR_POLARITY | RTC_BBPU_PDN_XOSC32K);
	BBPU &= ~RTC_BBPU_PWR_SW;     //RTC_setPWRSW(KAL_TRUE);
	DRV_RTC_WriteReg(RTC_BBPU,BBPU);
  	#endif // #if defined(DRV_RTC_NO_REG_COMM) || defined(FPGA)
   
   	#if defined(DRV_RTC_REG_COMM)
      
	BBPU = DRV_RTC_Reg(RTC_BBPU); /* 0227 TY modifies */
	#if defined(DRV_RTC_WRITE_ENABLE)
	BBPU |= (RTC_BBPU_AUTOPDN|RTC_BBPU_KEY);      
	BBPU &= ~RTC_BBPU_WRITE_EN; /* close RTC interface */
	#else // #if defined(DRV_RTC_WRITE_ENABLE)
	
	#if defined(DRV_RTC_PWRON_BBPU_POLARITY)
	BBPU |= (RTC_BBPU_PWR_POLARITY | RTC_BBPU_AUTOPDN | RTC_BBPU_KEY);     
	#else
	BBPU |= (RTC_BBPU_AUTOPDN | RTC_BBPU_KEY);  		
	#endif // #if defined(DRV_RTC_PWRON_BBPU_POLARITY)      
	
	#endif // #if defined(DRV_RTC_WRITE_ENABLE)
	BBPU &= ~RTC_BBPU_PWR_SW; 
	DRV_RTC_WriteReg(RTC_BBPU,BBPU);      
	#if defined(DRV_RTC_HW_CALI)
	// RTC_write_trigger();
	RTC_write_trigger_wait();
	#if defined(DRV_RTC_DBING)
	RTC_wait_debounce();
	#endif
	#endif // #if defined(DRV_RTC_HW_CALI)
#endif // #if defined(DRV_RTC_REG_COMM)
}

void RTC_PWIC_PowerOn_RTC_INIT(void)
{
   	// Latch BB power (BBPU)
	kal_uint32 BBPU;
   	kal_uint32 count;	 


#if defined(DRV_RTC_NO_LATCH_PWR_POLL) || defined(FPGA)
	BBPU = DRV_RTC_Reg(RTC_BBPU);
	BBPU |= (RTC_BBPU_KEY | RTC_BBPU_PWR_POLARITY | RTC_BBPU_PDN_XOSC32K
	        | RTC_BBPU_PWR_SW | RTC_BBPU_ALARM_SW);
   	DRV_RTC_WriteReg(RTC_BBPU, BBPU);
#endif // #if defined(DRV_RTC_NO_LATCH_PWR_POLL) || defined(FPGA)
#if defined(DRV_RTC_LATCH_PWR_POLL)
   	// DRV_WriteReg(RTC_BBPU,RTC_BBPU_POWERON);
   	BBPU = DRV_RTC_Reg(RTC_BBPU); /* 0227 TY modifies */
   	BBPU |= RTC_BBPU_POWERON;
	  
	#if defined(DRV_RTC_WRITE_ENABLE)
	BBPU |= RTC_BBPU_WRITE_EN;
	#endif // #if defined(DRV_RTC_WRITE_ENABLE)
   
	DRV_RTC_WriteReg(RTC_BBPU,BBPU);   
	#if defined(DRV_RTC_HW_CALI)
	// RTC_write_trigger();
	RTC_write_trigger_wait();
	#endif // #if defined(DRV_RTC_HW_CALI)

	for(count = 1000; count > 0; count--)
	{
		kal_uint32 delay_tick;
	
		if(( DRV_RTC_Reg(RTC_BBPU)&RTC_BBPU_PWR_SW) != 0)
	 		break;
		for (delay_tick = 10000; delay_tick > 0; delay_tick--)
		{
		}
		DRV_RTC_WriteReg(RTC_BBPU,BBPU);      
		#if defined(DRV_RTC_HW_CALI)
		// RTC_write_trigger();
		RTC_write_trigger_wait();
		#endif // #if defined(DRV_RTC_HW_CALI)
	}  
         
	BBPU = DRV_RTC_Reg(RTC_INFO1);
	BBPU &= ~0x0e; 
	BBPU |= (0x00 << 1); /* 2ms debounce time */
	DRV_RTC_WriteReg(RTC_INFO1,BBPU);
#endif /* DRV_RTC_LATCH_PWR_POLL */
	
	DRV_RTC_WriteReg(RTC_AL_DOW,DRV_RTC_Reg(RTC_TC_DOW));
	#if defined(DRV_RTC_HW_CALI)
	// RTC_write_trigger();
	RTC_write_trigger_wait();
	#endif /* DRV_RTC_HW_CALI */
}

void RTC_PWIC_First_PowerOn_INIT_RTCTime(t_rtc *rtctime)	
{
	kal_uint32 BBPU;
	kal_uint32 count;	   
    #if defined(DRV_RTC_INTERNAL_32K_AS_6255)
    DCL_HANDLE f32k_handler;
    F32K_CLK_CTRL_F32K_IS_XOSC32_T IsXOSC32K;
    F32K_CLK_CTRL_EOSC32_CALI_VAL_T EOSC32Cali; 
    kal_uint16 reg_val;
    #endif //#if defined(DRV_RTC_INTERNAL_32K_AS_6255)    

	#if defined(DRV_RTC_HW_CALI)
	DRV_RTC_WriteReg(RTC_CALI, 0);  // move from PW_PowerInit()
	RTC_write_trigger_wait();
	#endif //#if defined(DRV_RTC_HW_CALI)

	RTC_InitTC_Time(rtctime);
	#if !defined(DRV_RTC_HW_CALI)
	#if defined(DRV_RTC_TC_BUSY_CHECK)
	while(1)
	{
		if((DRV_RTC_Reg(RTC_TC_YEA) & RTC_TIME_BUSY) == 0)
			break;            
	}
    #endif // #if defined(DRV_RTC_TC_BUSY_CHECK)
    #endif // #if !defined(DRV_RTC_HW_CALI)
	DRV_RTC_Reg(RTC_IRQ_STATUS);
	DRV_RTC_WriteReg(RTC_TC_DOW, 1);
	DRV_RTC_WriteReg(RTC_IRQ_EN, RTC_IRQ_EN_ALLOFF);
	/* clear alarm mask */
	DRV_RTC_WriteReg(RTC_AL_MASK, 0);
	#if defined(DRV_RTC_HW_CALI)
	RTC_write_trigger_wait();
	#endif // #if defined(DRV_RTC_HW_CALI)
	/* clearn BBPU alarm power on bit */
	BBPU = DRV_RTC_Reg(RTC_BBPU);
   	BBPU &= 0xfe;
   	BBPU |= RTC_BBPU_KEY;
      
	#if defined(DRV_RTC_WRITE_ENABLE)
	BBPU |= RTC_BBPU_WRITE_EN;
	#endif // #if defined(DRV_RTC_WRITE_ENABLE)
      
	DRV_RTC_WriteReg(RTC_BBPU,BBPU);		
    #if defined(DRV_RTC_HW_CALI)
    RTC_write_trigger_wait();
    #endif
    
	RTC_setPWRKey();	   	   
    #if defined(DRV_RTC_HW_CALI)
	RTC_write_trigger_wait();
    #elif defined(DRV_RTC_POWERKEY_BUSY_CHECK) // #if defined(DRV_RTC_HW_CALI)
	
	while(1)
	{
		if((DRV_RTC_Reg(RTC_W_FLAG)&RTC_POWERKEY_BUSY) == 0)
			break;	         
	}  
    #endif // #if defined(DRV_RTC_HW_CALI)

	#if defined(DRV_RTC_GPIO)
    #if defined(DRV_RTC_INTERNAL_32K_AS_6255)
    count = 0;       
    reg_val = DRV_RTC_Reg(RTC_GPIO);     
    reg_val &= (RTC_GPIO_LPEN|RTC_GPIO_LPRST); //clear all, except LPEN, LPRST
   /*
    * RTC_GPIO_F32KOB:  valid bit in MT6255E1
    *                   reserved bit in MT6255E1 later, MT6250
    */        
    #if defined(DRV_RTC_INTERNAL_32K_SWITCH_FAIL_DETECT)
        reg_val |= RTC_GPIO_F32KOB;
    #endif

        while(count < 0xffff)
        {         
            DRV_RTC_WriteReg(RTC_GPIO, reg_val); // init to RTC_GPIO
            RTC_write_trigger();
    #if defined(DRV_RTC_INTERNAL_32K_SWITCH_FAIL_DETECT)            
            if (  ((DRV_RTC_Reg(RTC_GPIO)&(RTC_GPIO_EMBCK_SWITCH_FAIL|RTC_GPIO_VBAT_LPSTA_RAW)) == 0)
                &&((DRV_RTC_Reg(RTC_GPIO)&RTC_GPIO_F32KOB) == RTC_GPIO_F32KOB) )
    #else
            if ((DRV_RTC_Reg(RTC_GPIO)&(RTC_GPIO_VBAT_LPSTA_RAW)) == 0)
    #endif
                break;
            count++;            
        }        

    #else
	//DRV_RTC_WriteReg(RTC_GPIO, 0x0420); // init to RTC_GPIO
	DRV_RTC_WriteReg(RTC_GPIO, (RTC_GPIO_GPEN | RTC_GPIO_F32KOB));

    	#if defined(DRV_RTC_HW_CALI)
	RTC_write_trigger_wait();
        #endif
	#endif // #if defined(DRV_RTC_INTERNAL_32K_AS_6255)
	#endif // #if defined(DRV_RTC_GPIO)
	  	   	  	
	#if defined(DRV_RTC_LOW_POWER_DETECT)
	RTC_Clear_LPSTA_RAW();
	#endif // #if defined(DRV_RTC_LOW_POWER_DETECT)     

    #if defined(DRV_RTC_INTERNAL_32K_AS_6255)    
    f32k_handler = DclF32K_Open(DCL_F32K_CLK, FLAGS_NONE);
    DclF32K_Control(f32k_handler, F32K_CLK_CMD_QUERY_IS_XOSC32K, (DCL_CTRL_DATA_T *)&IsXOSC32K);
    
    if (!(IsXOSC32K.f32k_is_xosc32))    
    {
        DclF32K_Control(f32k_handler, F32K_CLK_CMD_EOSC32_TRIMMING, (DCL_CTRL_DATA_T *)&EOSC32Cali);
       /*
        * RTC_OSC32_AMP_EN: valid bit in MT6255
        *                   reserved bit in MT6250
        */        
        #if defined(DRV_F32K_EOSC32_AS_6255)
        reg_val = (RTC_OSC32_EOSC_CHOP_EN | RTC_OSC32_AMP_EN | RTC_OSC32_XOSC32_ENB | EOSC32Cali.eosc32_cali_val);
        #elif defined(DRV_F32K_EOSC32_AS_6250)
        reg_val = (RTC_OSC32_EOSC_CHOP_EN | RTC_OSC32_XOSC32_ENB | EOSC32Cali.eosc32_cali_val);
        #endif       
        RTC_write_xosc_reg(reg_val);
    }    
    DclF32K_Close(f32k_handler);   
    #endif //#if defined(DRV_RTC_INTERNAL_32K_AS_6255)

#ifdef _SIMULATION

	/*
	* When running co-sim,
	* the RTC registers are not stable soon after we set their value.
	* Thus we have to delay for a while before first access.
	*/
	for (count = 0; count < 2000; count++) {
	}

#endif // #ifdef _SIMULATION

#if defined(DRV_RTC_INIT_POLL)
	/* HW bug fix: to cover 128ms de_bounce time */	     
	
	// PWIC Clear Plan(RTC)
	// Repeatedly readback and write
	// Make sure RTC settings are all OK
   
	for(count = 0; count < 10000000; count++)
	{   	
		t_rtc current_time;
		kal_uint32 delay = 0;
		RTC_GetTime_(&current_time);
		if((rtctime->rtc_hour == current_time.rtc_hour) && (rtctime->rtc_day == current_time.rtc_day) && 
			(rtctime->rtc_wday == current_time.rtc_wday) && (rtctime->rtc_mon==current_time.rtc_mon) &&
			((DRV_RTC_Reg(RTC_IRQ_EN) & 0x7FFF) == RTC_IRQ_EN_ALLOFF) && (DRV_RTC_Reg(RTC_POWERKEY1) == RTC_POWERKEY1_KEY) && 
			(DRV_RTC_Reg(RTC_POWERKEY2) == RTC_POWERKEY2_KEY) && ((DRV_RTC_Reg(RTC_AL_MASK) & 0x7FFF) == 0) && 
			((DRV_RTC_Reg(RTC_BBPU) & 0x1) == 0))
	 		break;   	  
		RTC_InitTC_Time(rtctime);         	
		DRV_RTC_WriteReg(RTC_AL_MASK,0);
		DRV_RTC_WriteReg(RTC_IRQ_EN,RTC_IRQ_EN_ALLOFF);
	
		#if defined(DRV_RTC_HW_CALI)
		RTC_write_trigger_wait();
		#endif /*DRV_RTC_HW_CALI*/
	
		/* clearn BBPU alarm power on bit */
		BBPU = DRV_RTC_Reg(RTC_BBPU);
		BBPU &= 0xfe;
		BBPU |= RTC_BBPU_KEY;
	
		#if defined(DRV_RTC_WRITE_ENABLE)
		BBPU |= RTC_BBPU_WRITE_EN;
		#endif // #if defined(DRV_RTC_WRITE_ENABLE)
		
		DRV_RTC_WriteReg(RTC_BBPU,BBPU);
		for(delay = 0; delay < 500; delay++);
		RTC_setPWRKey();	
		#if defined(DRV_RTC_HW_CALI)
		
		//RTC_write_trigger();
		RTC_write_trigger_wait();
	
	#endif // #if defined(DRV_RTC_HW_CALI)
	}
#endif // #if defined(DRV_RTC_INIT_POLL)
}

void RTC_PWIC_Mask_AL(void)
{
	kal_uint32 loop = 0, wait = 0;
	kal_uint16 mask = 0;	
	
	mask = DRV_RTC_Reg(RTC_AL_MASK);
	if((mask & 1) == 1) /* make sure user doesn't configure Alarm */
	{
		for(loop = 0; loop < 10000; loop++)
		{
			/* Diable all alarm mask */
			DRV_RTC_WriteReg(RTC_AL_MASK, 0);
			#if defined(DRV_RTC_HW_CALI)
			DRV_RTC_WriteReg(RTC_WRTGR, RTC_WRTGR_WRTGR);
			#endif /* DRV_RTC_HW_CALI */
			for(wait = 0; wait < 10000; wait++){};                
			mask = DRV_RTC_Reg(RTC_AL_MASK);
			if(mask	== 0)
				break;
		}
	}
}

kal_bool RTC_PWIC_Check_PowerOn(void)
{
#if defined(DRV_RTC_PWRON_BBPU_POLARITY)
	kal_uint16 BBPU;
	kal_uint16 POLAR;
	kal_uint16 PWRSW;
#endif /* DRV_RTC_PWRON_BBPU_POLARITY */

#if defined(DRV_RTC_PWRON_BBPU_POLARITY)
	// get Polarity and BBPU bit
	BBPU = DRV_RTC_Reg(RTC_BBPU);
	POLAR = BBPU & RTC_BBPU_PWR_POLARITY;
	POLAR >>= 1;
	PWRSW = BBPU & RTC_BBPU_PWR_SW;
	#if defined(DRV_RTC_BBPU_AS_6205) || defined(DRV_RTC_BBPU_AS_6218)
	PWRSW >>= 2;
	#elif defined(DRV_RTC_BBPU_AS_6208) // #if defined(DRV_RTC_BBPU_AS_6205) || defined(DRV_RTC_BBPU_AS_6218)
  	PWRSW >>= 4;
	#endif // #if defined(DRV_RTC_BBPU_AS_6205) || defined(DRV_RTC_BBPU_AS_6218)
#endif // #if defined(DRV_RTC_PWRON_BBPU_POLARITY)

	// BBPU bit is set
	#if defined(DRV_RTC_PWRON_BBPU_POLARITY)
	if (POLAR == PWRSW)
	#elif defined(DRV_RTC_PWRON_BBPU_SW) // #if defined(DRV_RTC_PWRON_BBPU_POLARITY)
	if (DRV_RTC_Reg(RTC_BBPU) & RTC_BBPU_PWR_SW)
	#elif ( (defined(FPGA)) ) // #if defined(DRV_RTC_PWRON_BBPU_POLARITY)
	if (0)
	#endif // #if defined(DRV_RTC_PWRON_BBPU_POLARITY)
	{
		return KAL_TRUE;
	}

    return KAL_FALSE;

}

kal_bool RTC_Bootloader_PowerOn_(void)
{
	kal_bool isFirstOn = KAL_FALSE;
#ifndef DRV_RTC_NOT_EXIST
   	// need to set XOSC earlier
   	RTC_setXOSC_();

#ifdef DRV_RTC_HW_CALI
   	RTC_HW_Init_();
#endif

    isFirstOn = RTC_isFisrtOn();

	if (isFirstOn == KAL_TRUE)
	{
		RTC_setPWRKey();
	}

	RTC_PWIC_PowerOn_RTC_INIT();

#endif /* DRV_RTC_NOT_EXIST */

	return isFirstOn;
}

#if defined(DRV_RTC_LOW_POWER_DETECT)
void RTC_Clear_LPSTA_RAW(void)
{
	kal_uint16 reg_value;	
	reg_value = DRV_RTC_Reg(RTC_GPIO);

	reg_value |= RTC_GPIO_LPEN;
	reg_value &= ~(RTC_GPIO_LPRST);
	DRV_RTC_WriteReg(RTC_GPIO, ((kal_uint16)reg_value));
#if defined(DRV_RTC_HW_CALI)
	RTC_write_trigger_wait();
#endif
	while(DRV_RTC_Reg(RTC_BBPU) & 0x40);

	reg_value |= RTC_GPIO_LPRST;
	DRV_RTC_WriteReg(RTC_GPIO, ((kal_uint16)reg_value));
#if defined(DRV_RTC_HW_CALI)
	RTC_write_trigger_wait();
#endif	
	while(DRV_RTC_Reg(RTC_BBPU) & 0x40);

	reg_value |= RTC_GPIO_LPEN;
	reg_value &= ~(RTC_GPIO_LPRST);
	DRV_RTC_WriteReg(RTC_GPIO, ((kal_uint16)reg_value));
#if defined(DRV_RTC_HW_CALI)
	RTC_write_trigger_wait();
#endif	
	while(DRV_RTC_Reg(RTC_BBPU) & 0x40);

/*
	IRQMask(IRQ_RTC_CODE);
	reg_value = DRV_RTC_Reg(RTC_IRQ_EN);
	reg_value |= RTC_IRQ_STATUS_LP_STAT;	
	DRV_RTC_WriteReg(RTC_IRQ_EN, reg_value);
#if defined(DRV_RTC_HW_CALI)
	RTC_write_trigger_wait();
#endif	
	IRQClearInt(IRQ_RTC_CODE);
	IRQUnmask(IRQ_RTC_CODE);
*/
	reg_value = DRV_RTC_Reg(RTC_IRQ_STATUS);
}

#endif // #if defined(DRV_RTC_LOW_POWER_DETECT)

#if defined(DRV_RTC_GPIO)

void RTC_Set_GPIO_Output_Mode(kal_bool value, kal_bool is_SlewRateOn)
{
	kal_uint16 reg_value;
	reg_value = DRV_RTC_Reg(RTC_GPIO);

	if (value == KAL_FALSE)
	{
	   	reg_value |= (RTC_GPIO_GOE | RTC_GPIO_F32KOB);
	   	reg_value &= ~(RTC_GPIO_GPO | RTC_GPIO_CDBO);		
	}
	else
	{
	   	reg_value |= (RTC_GPIO_GOE | RTC_GPIO_F32KOB | RTC_GPIO_GPO);
	   	reg_value &= ~(RTC_GPIO_CDBO);	
	}

	reg_value &= ~(RTC_GPIO_GPEN);

	if (is_SlewRateOn == KAL_TRUE)
	{
		reg_value |= (RTC_GPIO_GSR);
	}
	else
	{
		reg_value &= ~(RTC_GPIO_GSR);
	}

	DRV_RTC_WriteReg(RTC_GPIO, reg_value);
#if defined(DRV_RTC_HW_CALI)
	RTC_write_trigger_wait();
#endif	
}

kal_bool RTC_Get_GPIO_Input(void)
{
	kal_uint16 reg_value;
	reg_value = DRV_RTC_Reg(RTC_GPIO);

	if (reg_value && RTC_GPIO_GPI)
	{
		return KAL_TRUE;

	}
	return KAL_FALSE;

}

void RTC_Set_GPIO_Input_Mode(RTC_GPIO_PULL_TYPE_enum PullType, RTC_GPIO_DRIVING_STRENGTH_enum PullDs, kal_bool is_SmithTrigger)
{
	kal_uint16 reg_value;
	reg_value = DRV_RTC_Reg(RTC_GPIO);

	reg_value &= ~(RTC_GPIO_GOE);	

	switch(PullType)
	{
		case RTC_GPIO_NO_PULL:
			reg_value &= ~(RTC_GPIO_GPEN);
			break;		
		case RTC_GPIO_PULL_DOWN:
			reg_value |= (RTC_GPIO_GPEN);
			reg_value &= ~(RTC_GPIO_GPU);		
			break;	
		case RTC_GPIO_PULL_UP:
			reg_value |= (RTC_GPIO_GPEN | RTC_GPIO_GPU);
			break;					   
		default:
			break;		

	}

	switch(PullDs)
	{
		case RTC_GPIO_DS_4mA:
		   	reg_value &= ~(RTC_GPIO_GE4 | RTC_GPIO_GE8);
		   	break;		
		case RTC_GPIO_DS_8mA:
		   reg_value |= (RTC_GPIO_GE4);
		   reg_value &= ~(RTC_GPIO_GE8);		
		   break;	
		case RTC_GPIO_DS_12mA:
		   reg_value |= (RTC_GPIO_GE4);
		   reg_value &= ~(RTC_GPIO_GE8);	
		   break;		
		case RTC_GPIO_DS_16mA:
		   reg_value |= (RTC_GPIO_GE4 | RTC_GPIO_GE8);
		   break;					   
		default:
		   break;		
	}

	if (is_SmithTrigger == KAL_TRUE)
		reg_value |= (RTC_GPIO_GSMT);

	DRV_RTC_WriteReg(RTC_GPIO, reg_value);
#if defined(DRV_RTC_HW_CALI)
	RTC_write_trigger_wait();
#endif	
}

void RTC_Set_GPIO_Mode(RTC_GPIO_MODE_enum Mode)
{
	kal_uint16 reg_value;
	
	reg_value = DRV_RTC_Reg(RTC_GPIO);
	
	switch(Mode)
	{
		case RTC_GPIO_DISABLE:
			reg_value |= (RTC_GPIO_GPEN | RTC_GPIO_F32KOB);
			reg_value &= ~(RTC_GPIO_GPU | RTC_GPIO_GOE);		   
		   	break;
		case RTC_GPIO_EXPORT_32K:
		   	reg_value &= ~(RTC_GPIO_F32KOB);		
		   	break;	
		case RTC_GPIO_EXPORT_COREDETB:
		   	reg_value |= (RTC_GPIO_GOE | RTC_GPIO_F32KOB | RTC_GPIO_CDBO);
		   	break;					   
		default:
		   break;
	}

	reg_value &= ~(RTC_GPIO_GPEN);

	DRV_RTC_WriteReg(RTC_GPIO, reg_value);
#if defined(DRV_RTC_HW_CALI)
	RTC_write_trigger_wait();
#endif	

}

#endif //defined(DRV_RTC_GPIO)

#else // #if !defined(DRV_RTC_OFF)
kal_bool IsOSRunning(void){}
kal_bool isPWROnByRTC(void){}
void RTC_ALintr(void){}
void rtc_backward_time(t_rtc *rtc_time, kal_uint16 hours, kal_uint16 mins, kal_uint16 secs){}
void rtc_cali_init(void *timer_param){}
void RTC_Cali_Time(t_rtc *rtctime){}
void RTC_Check_Alarm(t_rtc rtctime){}
void RTC_clrpky(void){}
kal_bool rtc_compare_time(t_rtc *rtc_time1, t_rtc *rtc_time2){}
void RTC_Config_(kal_uint8 AL_EN, kal_uint8 TC_EN){}
void RTC_delay(void){}
kal_bool rtc_do_one_time_cali(void){}
void rtc_do_repeat_cali(kal_int32 inaccurate_cnt){}
void rtc_forward_time(t_rtc *rtc_time, kal_uint16 hours, kal_uint16 mins, kal_uint16 secs){}
kal_int8 rtc_get_cali_offset(void){}
kal_bool rtc_get_diff_time(t_rtc *curr_time, t_rtc *prev_time, kal_uint16 *ret_hours, kal_uint16 *ret_mins){}
void rtc_get_next_time(void){}
void RTC_GetALTime(t_rtc *rtctime ){}
void RTC_GetTime_(t_rtc *rtctime ){}
void RTC_HW_Init_(void){}
void RTC_init_(void (*RTC_TCCallback)(void),void (*RTC_ALCallback)(void)){}
void RTC_InitTC_Time(t_rtc *rtctime){}
kal_bool RTC_Set_Module_ILM_Info(RTC_REG_MODULE_ILM_INFO_T *Module_ilm_info){}
void RTC_IRQOneShotEnable(kal_uint8 oneShotEN){}
kal_bool RTC_is_config_valid(void){}
kal_bool RTC_is_MS_FirstPowerOn_(void){}
kal_bool RTC_isFisrtOn(void){}
kal_uint16 RTC_original_pnd1(void){}
void rtc_poweroff_cali_init(void){}
kal_uint8 RTC_read_xosc_reg(void){}
void RTC_reload(void){}
void RTC_SetAlarm(t_rtc *rtctime ){}
void RTC_setBBPU(kal_uint16 data){}
void RTC_setPWRKey(void){}
void RTC_setXOSC_(void){}
void RTC_unlockPROT(void){}
void rtc_sleep_wa_disable_sleep_mode(){}
void rtc_sleep_wa_enable_sleep_mode(){}
void rtc_sleep_wa_timer_cb(void *timer_param){}
void RTC_start_cali(void){}
void RTC_TCintr(void){}
void rtc_system_timer_cb(void *timer_param){}
void rtc_update_time(void){}
void RTC_wait_busy(void){}
void RTC_wait_debounce(void){}
void rtc_write_to_nvram(void){}
void RTC_write_trigger(void){}
void RTC_write_trigger_wait(void){}
void RTC_write_xosc_reg(kal_uint16 reg_value){}
kal_uint16 RTC_Read_PDN(RTC_PDN_INDEX PDNIndex){}
void RTC_Set_PDN_bits(RTC_PDN_INDEX PDNIndex, kal_uint16 flag){}
void RTC_Clear_PDN_bits(RTC_PDN_INDEX PDNIndex, kal_uint16 flag){}
void RTC_Write_PDN_bits(RTC_PDN_INDEX PDNIndex, kal_uint16 flag){}
kal_bool RTC_FT_PowerOff(void){}
#if defined(DRV_RTC_LOW_POWER_DETECT)
void RTC_Clear_LPSTA_RAW(void){}
#endif // defined(DRV_RTC_LOW_POWER_DETECT)

#if defined(DRV_RTC_GPIO)
void RTC_Set_GPIO_Output_Mode(kal_bool value, kal_bool is_SlewRateOn){}
kal_bool RTC_Get_GPIO_Input(void){return KAL_TRUE;}
void RTC_Set_GPIO_Input_Mode(RTC_GPIO_PULL_TYPE_enum PullType, RTC_GPIO_DRIVING_STRENGTH_enum PullDs, kal_bool is_SmithTrigger){}
void RTC_Set_GPIO_Mode(RTC_GPIO_MODE_enum Mode){}
#endif //defined(DRV_RTC_GPIO)

#endif // #if !defined(DRV_RTC_OFF)
#endif /* DRV_RTC_NOT_EXIST */
