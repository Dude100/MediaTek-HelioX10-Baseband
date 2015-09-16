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
 *	 bmt.c
 *
 * Project:
 * --------
 *	Maui_Software
 *
 * Description:
 * ------------
 *	This Module defines charging algorithm.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *				 HISTORY
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
 *	 Rev 1.31	May 16 2005 23:42:02	BM_Trunk
 * removed!
 * removed!
 * removed!
 *	 Rev 1.30	Jan 18 2005 00:14:16	BM
 * removed!
 * removed!
 *	 Rev 1.29	Jan 14 2005 20:56:34	mtk00502
 * removed!
 * removed!
 * removed!
 *	 Rev 1.28	Dec 03 2004 10:32:24	mtk00502
 * removed!
 * removed!
 * removed!
 *	 Rev 1.27	Oct 27 2004 11:48:46	mtk00502
 * removed!
 * removed!
 * removed!
 *	 Rev 1.26.2.1	Oct 27 2004 11:48:36	mtk00502
 * removed!
 * removed!
 * removed!
 *	 Rev 1.26.1.1	Oct 27 2004 11:48:22	mtk00502
 * removed!
 * removed!
 * removed!
 *	 Rev 1.26.1.0	Oct 19 2004 22:08:48	BM
 * removed!
 * removed!
 *	 Rev 1.26	Sep 22 2004 17:25:00	mtk00479
 * removed!
 * removed!
 * removed!
 *	 Rev 1.25	Jul 20 2004 21:50:24	mtk00502
 * removed!
 * removed!
 * removed!
 *	 Rev 1.24	May 13 2004 15:30:06	mtk00502
 * removed!
 * removed!
 * removed!
 *	 Rev 1.23	Mar 31 2004 11:26:58	mtk00502
 * removed!
 * removed!
 * removed!
 *	 Rev 1.22	Feb 23 2004 14:56:52	mtk00502
 * removed!
 * removed!
 * removed!
 *	 Rev 1.21	Feb 06 2004 17:32:10	mtk00502
 * removed!
 * removed!
 * removed!
 *	 Rev 1.20	Feb 01 2004 17:28:36	mtk00502
 * removed!
 * removed!
 * removed!
 *	 Rev 1.13.3.7	Dec 30 2003 09:57:54	mtk00479
 * removed!
 * removed!
 * removed!
 *	 Rev 1.13.3.6	Dec 07 2003 14:31:28	mtk00479
 * removed!
 * removed!
 * removed!
 *	 Rev 1.13.3.5	Dec 07 2003 14:23:46	mtk00479
 * removed!
 * removed!
 * removed!
 *	 Rev 1.13.3.4	Nov 26 2003 17:32:50	mtk00479
 * removed!
 * removed!
 * removed!
 * removed!
 *	 Rev 1.13.3.3	Nov 21 2003 11:40:36	mtk00479
 * removed!
 * removed!
 * removed!
 *	 Rev 1.13.3.2	Nov 17 2003 13:47:40	mtk00479
 * removed!
 * removed!
 *	 Rev 1.13.3.1	Nov 16 2003 18:01:18	mtk00479
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *	 Rev 1.13.3.0	Oct 08 2003 17:28:30	BM
 * removed!
 * removed!
 *	 Rev 1.13	Sep 29 2003 16:56:16	mtk00288
 * removed!
 * removed!
 * removed!
 *	 Rev 1.12	Sep 24 2003 17:50:06	mtk00479
 * removed!
 * removed!
 * removed!
 *	 Rev 1.11	Sep 17 2003 14:24:12	mtk00288
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include	"drv_comm.h"
#include "kal_public_defs.h" //MSBB change #include 	"stack_msgs.h"
#include	"drv_msgid.h"
#include	"bmt.h"
#include	"drvsignals.h"
#include	"bmt_trc.h"
// For RHR ADD Usage
#include "kal_public_defs.h" //MSBB change #include 	"stack_config.h"
#include 	"kal_trace.h"
#include    "bmt_sw.h"
#include    "kal_general_types.h"
#include    "kal_public_api.h"
#include    "dcl.h"
#include	"dcl_pmu_sw.h"

#define CHARGING_TIME_UNIT KAL_TICKS_1_SEC

#if defined(__DRV_BMT_DISABLE_STOP_TIMER__)
#define STOPTIMER_TIMEOUT_TICK	 0
#else
#define STOPTIMER_TIMEOUT_TICK	 (KAL_TICKS_1_MIN*30)
#endif

#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)
#define ESTIMATIVE_TIMEOUT_TICK	 (KAL_TICKS_1_MIN*70)
#endif //#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)

#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
extern void bmt_vchg_compare_and_set_current(kal_int32 cur_VCHG, kal_bool Hysteresis_Enable);
#endif

#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
kal_bool High_Vchg_Safety_Timer_Set = KAL_FALSE;
kal_bool First_Time_Charge_Enable = KAL_TRUE;
bmt_customized_high_vchg_struct *bmt_high_vchg_para;
kal_uint32 bmt_total_charge_time = 0;
kal_uint32 bmt_high_vchg_current = 0xFFFFFFF;
kal_int32 VCharge_Total = 0;
kal_int32 Pre_VCharge_AVG = 0;
kal_int32 Cur_VCharge_MAX = 0;
kal_bool bmt_safety_timer_config = KAL_FALSE;
#endif // End of #if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)

#if defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__)
DCL_HANDLE bmt_vbat_in_hisr_gpt_handle = 0xFF;
static kal_uint8  bmt_vbat_in_hisr_id;
kal_int32 g_battery_pre_voltage = 0;
extern volatile kal_uint8 bmt_event_sche_active;
#endif //defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__)

extern void bmt_set_stoptimer(kal_uint32 tick);
extern void bmt_charge_end(void);
extern void BMT_sendMes2UEM(BMT_CHR_STAT status);
extern void bmt_timer_config(kal_uint32 time);
extern kal_uint8  bmt_bmtid_adc_handle[BMT_ADC_MAX_CHANNEL_TOTAL];
extern stack_timer_struct		ChargeTimeout_timer;

#if defined(PMIC_6236_CV_TRIM_CALIBRATION)
extern pmu6236_chr_vbat_cv_enum mt6236_efuse_vbat_cv;
#endif // #if defined(PMIC_6236_CV_TRIM_CALIBRATION)

static kal_uint8 BATFULL_index = 0;
#if defined(DRV_BMT_PULSE_CHARGING)
static kal_bool batfull_msg_flag = KAL_FALSE;
static kal_uint8 BATNOTFULL_index = 0;
#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
kal_uint8 SW_Low_Current_Cnts=0;
kal_bool SW_Workaround_Flag = KAL_TRUE;
kal_bool Manual_Disable_Charge_Flag = KAL_FALSE;
kal_uint8 HW_Plug_Status = bmt_chr_uninit;
#endif // End of #if defined(DRV_BMT_HW_PRECC_WORKAROUND)
#endif // #if defined(DRV_BMT_PULSE_CHARGING)
static CHRTStruct  BATTime;
BMTStruct BMT;			 /*Main BMT struct*/
#if defined(CHR_WITH_NI_MH_BATTERY) 
static kal_uint32 VBATtmp;
#endif
/*lint -e552*/  
//althought not access in bmt.c, but they are accessed in bmt_main.c
extern kal_uint32 VBAT_OFF;
extern double ADCBAT_OFF;
/*lint +e552*/
kal_uint8 low_charger_count = 0;
kal_uint8 over_charger_count = 0;
kal_uint8 low_temper_count = 0;
kal_uint8 over_temper_count = 0;
kal_uint8 over_current_count=0;
kal_uint8 low_current_count = 0;

static void BMT_CHRPRE_ON(void);
static void BMT_CHRPRE_OFF(void);
static void BMT_CHRFAST_ON(void);
static void BMT_CHRFAST_OFF(void);
static void BMT_CHRTOPOFF_ON(void);
static void BMT_CHRTOPOFF_OFF(void);
static void BMT_CHRBATFULL_ON(void);
static void BMT_CHRBATFULL_OFF(void);
static void BMT_CHRHOLD(void);
#if defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)
static void BMT_CHRERRORCHECK(void);
#endif //#if defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)
static void BMT_MeasureStop(void);
#if defined(DRV_BMT_PULSE_CHARGING)
static void BMT_CHRPOSTFULL_ON(void);
static void BMT_CHRPOSTFULL_OFF(void);
static kal_bool BMT_CHRPRE_TO_CHRBATFULL_CHECK(void);
#endif //#if defined(DRV_BMT_PULSE_CHARGING)
#if defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__)
static void BMT_CHRPRE_FULLCHECK(void);
#endif // __DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__
static void BMT_CtrlCharge(kal_uint8 ON, kal_uint32 VBAT);
static kal_bool BMT_CHR_Is_Under_ExtremeTmp(BATPHYStruct *pBATPHYS);
static kal_bool BMT_CHR_Is_ExtremeTmp_Charge_Full(BATPHYStruct *pBATPHYS);
static kal_bool BMT_CHR_Is_ExtremeTmp_Charge_Recharge(BATPHYStruct *pBATPHYS);
void BMT_CHARSTOP(void);
kal_uint8 SaftyTimer_Flag = 0;

extern DCL_HANDLE bmt_PmuHandler;

#if defined(DRV_BMT_PULSE_CHARGING)
const CHR_FUNC	BMT_CHRFUNC[][2] = 
{
    {BMT_CHRPRE_OFF, BMT_CHRPRE_ON} //CHR_PRE
    ,{BMT_CHRFAST_OFF, BMT_CHRFAST_ON} //CHR_FAST
    ,{BMT_CHRTOPOFF_OFF, BMT_CHRTOPOFF_ON} //CHR_TOPOFF
    ,{BMT_CHRBATFULL_OFF, BMT_CHRBATFULL_ON} //CHR_BATFULL
    ,{BMT_MeasureStop,BMT_MeasureStop} //CHR_ERROR
    ,{BMT_CHRHOLD,BMT_CHRHOLD} //CHR_HOLD
    ,{BMT_CHRPOSTFULL_OFF, BMT_CHRPOSTFULL_ON} //CHR_POSTFULL
#ifdef __DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__
    ,{BMT_CHRPRE_FULLCHECK, BMT_CHRPRE_FULLCHECK} //CHR_PRE_FULL_CHECK
#endif
};
#else //#if defined(DRV_BMT_PULSE_CHARGING)
const CHR_FUNC	BMT_CHRFUNC[][2] = 
{
    {BMT_CHRPRE_OFF, BMT_CHRPRE_ON} //CHR_PRE
    ,{BMT_CHRFAST_OFF, BMT_CHRFAST_ON} //CHR_FAST
    ,{BMT_CHRTOPOFF_OFF, BMT_CHRTOPOFF_ON} //CHR_TOPOFF
    ,{BMT_CHRBATFULL_OFF, BMT_CHRBATFULL_ON} //CHR_BATFULL
    ,{BMT_MeasureStop,BMT_MeasureStop} //CHR_ERROR
    ,{BMT_CHRHOLD,BMT_CHRHOLD} //CHR_HOLD
#ifdef __DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__
    ,{BMT_MeasureStop,BMT_MeasureStop} //CHR_POSTFULL - actually non-pulse charging wnn't go here
    ,{BMT_CHRPRE_FULLCHECK, BMT_CHRPRE_FULLCHECK} //CHR_PRE_FULL_CHECK
#endif
};
#endif //#if defined(DRV_BMT_PULSE_CHARGING)

#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
void bmt_high_vchg_first_time_set(void)
{
	BATPHYStruct BATPHYS;
	if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
	{
        bmt_vchg_compare_and_set_current(BATPHYS.VCHARGER, KAL_TRUE);
        Pre_VCharge_AVG = BATPHYS.VCHARGER;
        drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_FIRST_TIME_VCHG_TRC, Pre_VCharge_AVG);
	}
} 

void bmt_high_vchg_set_safetytimer(kal_int32 Cur_VCHG)   
{
    kal_int32 i;

    if((bmt_safety_timer_config == KAL_FALSE) && (BMT.pmictrl_state == PMIC_CHARGEON))
    {
        drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_CURRENT_VCHG_TRC, Cur_VCHG);
        // Cur_VCHG > S/W OVP
        if(Cur_VCHG >= bmt_high_vchg_para->HIGH_VCHG_TABLE[VCHG_VOL_LEVEL - 1][0])
        {
            bmt_total_charge_time = 0;
            drv_trace0(TRACE_GROUP_9, BMT_HIGH_VCHG_TOO_HIGH_TRC);
        }
        else if(Cur_VCHG < bmt_high_vchg_para->HIGH_VCHG_TABLE[0][0])
        {
            drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_LOWEST_THRESHOLD_TRC, bmt_high_vchg_para->HIGH_VCHG_TABLE[0][0]);
            bmt_total_charge_time = bmt_high_vchg_para->HIGH_VCHG_TABLE[0][2];
        }
        else
        {
            for(i = (VCHG_VOL_LEVEL - 1); i > 0; i--)
            {

                drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_UPPER_THRESHOLD_TRC, bmt_high_vchg_para->HIGH_VCHG_TABLE[i][0]);
                drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_LOWER_THRESHOLD_TRC, bmt_high_vchg_para->HIGH_VCHG_TABLE[i-1][0]);
                if((Cur_VCHG < bmt_high_vchg_para->HIGH_VCHG_TABLE[i][0]) && (Cur_VCHG >= bmt_high_vchg_para->HIGH_VCHG_TABLE[i-1][0]))
                {
                    bmt_total_charge_time = bmt_high_vchg_para->HIGH_VCHG_TABLE[i][2];  
                    drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_TABLE_INDEX_TRC, i);
                    break;
                }
            }
        }
        drv_trace1(TRACE_GROUP_9, BMT_CURRENT_PMIC_STATE_TRC, BMT.pmictrl_state);
        if(bmt_IsUSBorCharger() != BMT_USB_IN)
        {
            drv_trace0(TRACE_GROUP_9, BMT_AC_IN_TRC);
        }
        else
        {
            drv_trace0(TRACE_GROUP_9, BMT_USB_IN_TRC);
			bmt_total_charge_time = BMT_TOTAL_CHARGE_TIME;
        }
        stack_start_timer(&ChargeTimeout_timer, 0, KAL_TICKS_1_MIN*bmt_total_charge_time);
         drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_START_TRC, bmt_total_charge_time);                      

        bmt_safety_timer_config = KAL_TRUE;
        SaftyTimer_Flag = BMT_SAFETY_TIMER_ON; 
    }
    
}

void bmt_vchg_compare_and_set_current(kal_int32 Cur_VCHG, kal_bool Hysteresis_Enable)
{
    static kal_uint8 pre_level = 0xFF;

    kal_uint8 i, cur_level = 0;
  
    drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_CURRENT_VCHG_TRC, Cur_VCHG);    
    // Cur_VCHG > S/W OVP
    if(Cur_VCHG >= bmt_high_vchg_para->HIGH_VCHG_TABLE[VCHG_VOL_LEVEL - 1][0])
    {
        bmt_high_vchg_current = bmt_high_vchg_para->HIGH_VCHG_TABLE[VCHG_VOL_LEVEL - 1][1]; // Use Last Charge Current
        drv_trace0(TRACE_GROUP_9, BMT_HIGH_VCHG_TOO_HIGH_TRC);
        if(Hysteresis_Enable == KAL_TRUE)
        {
            cur_level = VCHG_VOL_LEVEL;
        }
    }
    else if(Cur_VCHG < bmt_high_vchg_para->HIGH_VCHG_TABLE[0][0])
    {
        drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_LOWEST_THRESHOLD_TRC, bmt_high_vchg_para->HIGH_VCHG_TABLE[0][0]);
        bmt_high_vchg_current = bmt_high_vchg_para->HIGH_VCHG_TABLE[0][1];
        if(Hysteresis_Enable == KAL_TRUE)
        {        
            cur_level = 0;
        }
    }
    else
    {
        for(i = (VCHG_VOL_LEVEL - 1); i > 0; i--)
        {
            drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_UPPER_THRESHOLD_TRC, bmt_high_vchg_para->HIGH_VCHG_TABLE[i][0]);
            drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_LOWER_THRESHOLD_TRC, bmt_high_vchg_para->HIGH_VCHG_TABLE[i-1][0]);
            if((Cur_VCHG < bmt_high_vchg_para->HIGH_VCHG_TABLE[i][0]) && (Cur_VCHG >= bmt_high_vchg_para->HIGH_VCHG_TABLE[i-1][0]))
            {
                bmt_high_vchg_current = bmt_high_vchg_para->HIGH_VCHG_TABLE[i][1];  
                if(Hysteresis_Enable == KAL_TRUE)
                {
                    cur_level = i;
                }
                break;
            }
        }
    }
    
    if(Hysteresis_Enable == KAL_TRUE)
    {
        drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_PRE_CURRENT_LEVEL_TRC, pre_level);       
        drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_CUR_CURRENT_LEVEL_TRC, cur_level);        
        if(cur_level != pre_level && ((cur_level - pre_level) == 1 || (pre_level - cur_level) == 1 ) )
        {
            drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_HYSTERESIS_UPPER_BOUND_TRC, bmt_high_vchg_para->HIGH_VCHG_TABLE[pre_level][0] + BMT_HIGH_VCHG_THRESHOLD);              
            drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_HYSTERESIS_LOWER_BOUND_TRC, bmt_high_vchg_para->HIGH_VCHG_TABLE[cur_level][0] - BMT_HIGH_VCHG_THRESHOLD);                          
            
            // Hysteresis
            if((cur_level > pre_level) && (Cur_VCHG < bmt_high_vchg_para->HIGH_VCHG_TABLE[pre_level][0] + BMT_HIGH_VCHG_THRESHOLD))
            {
                bmt_high_vchg_current = bmt_high_vchg_para->HIGH_VCHG_TABLE[pre_level][1];
            }
            else if((cur_level < pre_level) && (Cur_VCHG > bmt_high_vchg_para->HIGH_VCHG_TABLE[cur_level][0] - BMT_HIGH_VCHG_THRESHOLD))
            {
                bmt_high_vchg_current = bmt_high_vchg_para->HIGH_VCHG_TABLE[pre_level][1];
            }
            else
            {
                pre_level = cur_level;
            }
                
        }
        else
        {
            pre_level = cur_level;
        }
    }
    drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_CHARGE_CURRENT_TRC, bmt_high_vchg_current);                              


#if defined(__CHINA_CHARGER_STANDARD__)
	if(chr_usb_detect.chr_usb_present == CHARGER_PRESENT_NON)
	{
	    if(bmt_high_vchg_current > PMU_CHARGE_CURRENT_450_00_MA)
	    {
	        bmt_high_vchg_current = PMU_CHARGE_CURRENT_450_00_MA;
	        drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_SET_USB_CHARGE_CURRENT_TRC, CHR_USB_CHARGE_CURRENT);	
	    }
	}
#endif //#if defined(__CHINA_CHARGER_STANDARD__)

	
}
#endif // End of #if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)

void bmt_set_vbat_cv_calibration(DCL_INT32 vbat)
{
	PMU_CTRL_CHR_SET_VBAT_CV_CALIBRATION val;

	val.vbat = vbat;
	DclPMU_Control(bmt_PmuHandler,CHR_SET_VBAT_CV_CALIBRATION,(DCL_CTRL_DATA_T *)&val);
}


/*
* FUNCTION
*	   bmt_frequently_check_on_state
*
* DESCRIPTION                                                           
*   	This function is called to check whether "on state" need to be check frequently
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   KAL_TRUE: need check in this state
*	   KAL_FALSE: not need
*
* GLOBALS AFFECTED
*     None
*/
kal_bool bmt_frequently_check_on_state(void)
{
    if(BMT.pmictrl_state == PMIC_CHARGEON)
    {
        if((BMT.bat_state == CHR_PRE)  || 
            (BMT.bat_state == CHR_FAST) || 
      	    ((BMT.call_state != talk_mode) && (BMT.bat_state == CHR_TOPOFF)) ||
      	    ((BMT.call_state != talk_mode) && (BMT.bat_state == CHR_POSTFULL)) ||
      	    ((BMT.call_state != talk_mode) && (BMT.bat_state == CHR_BATFULL)) )
        {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}

#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
/*
* FUNCTION
*	   bmt_frequently_check_off_state
*
* DESCRIPTION                                                           
*   	This function is called to check whether "off state" need to be check frequently
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   KAL_TRUE: need check in this state
*	   KAL_FALSE: not need
*
* GLOBALS AFFECTED
*     None
*/
kal_bool bmt_frequently_check_off_state(void)
{
    if(BMT.pmictrl_state == PMIC_CHARGEOFF)
    {
        if(BMT.bat_state == CHR_PRE)
        {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}
#endif // End of #if defined(DRV_BMT_HW_PRECC_WORKAROUND)

/*
* FUNCTION
*	   bmt_get_on_count
*
* DESCRIPTION                                                           
*   	This function is called to get the different count in each on state
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   kal_uint32: check count of current on state. 
*
* GLOBALS AFFECTED
*     None
*/
kal_uint32 bmt_get_on_count(void)
{
   kal_uint32 current_on_count = 0;
   switch(BMT.bat_state)
   {
      case 	CHR_PRE:
      	current_on_count = bmt_charging_para->PRE_TON*KAL_TICKS_1_SEC/45+1;
      	break;
      case 	CHR_FAST:
      	if(0 == BATTime.TON)
      		BATTime.TON = bmt_charging_para->TONOFFTABLE[0][CHRTON];
      	current_on_count = BATTime.TON*KAL_TICKS_1_SEC/45+1;
      	break;
      case 	CHR_TOPOFF:
      	current_on_count = bmt_charging_para->TOPOFF_TON*KAL_TICKS_1_SEC/45+1;
      	break;
#if defined(DRV_BMT_PULSE_CHARGING)
      case 	CHR_POSTFULL:
      	current_on_count = bmt_charging_para->BATPOSTFULL_TON_LI*KAL_TICKS_1_SEC/45+1;
		break;
#endif
      case 	CHR_BATFULL:
      	current_on_count = bmt_charging_para->BATFULL_TON_LI*KAL_TICKS_1_SEC/45+1;
      	break;
      default:
      	current_on_count = 1;
      	break;
   }
   drv_trace1(TRACE_GROUP_10, BMT_ERRORCHECK_ON_COUNT_TRC, current_on_count);   
   return current_on_count;
}

#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
/*
* FUNCTION
*	   bmt_get_off_count
*
* DESCRIPTION                                                           
*   	This function is called to get the different count in each off state
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   kal_uint32: check count of current off state. 
*
* GLOBALS AFFECTED
*     None
*/
kal_uint32 bmt_get_off_count(void)
{
   kal_uint32 current_off_count = 0;
   switch(BMT.bat_state)
   {
      case 	CHR_PRE:
      	current_off_count = bmt_charging_para->PRE_TOFF*KAL_TICKS_1_SEC/45+1;
      	break;
      default:
      	current_off_count = 1;
      	break;
   }
   drv_trace1(TRACE_GROUP_10, BMT_ERRORCHECK_OFF_COUNT_TRC, current_off_count);
   return current_off_count;
}
#endif // End of #if defined(DRV_BMT_HW_PRECC_WORKAROUND)

/*
* FUNCTION
*	   bmt_finish_check_on_state
*
* DESCRIPTION                                                           
*   	This function is called to check whether "on state check" already finish
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   KAL_TRUE: finish
*	   KAL_FALSE: not finish
*
* GLOBALS AFFECTED
*     None
*/
kal_bool bmt_finish_check_on_state(void)
{
#if defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)
   static kal_uint8  pre_bat_state = 0xFF;
   static kal_uint32 state_counter = 0; //the counter during this ON state
   static kal_uint32 bmt_on_count  = 0; //the count of this ON state. (how many "200 ms")

   if(BMT.bat_state != pre_bat_state) //change state
   {
      bmt_on_count = bmt_get_on_count();
      pre_bat_state = BMT.bat_state;
      state_counter = 0;
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)      
      VCharge_Total = 0;
      drv_trace0(TRACE_GROUP_9, BMT_HIGH_VCHG_MAX_RESET_TO_ZERO_TRC); 
#endif      	  
   }
   
   if(state_counter == bmt_on_count)
   {
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT) 
      Pre_VCharge_AVG = VCharge_Total / bmt_on_count;
      bmt_vchg_compare_and_set_current(VCharge_Total / bmt_on_count, KAL_TRUE);
      drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_AVERAGE_TRC, VCharge_Total / bmt_on_count); 
      VCharge_Total = 0;
      Cur_VCharge_MAX = 0;
      drv_trace0(TRACE_GROUP_9, BMT_HIGH_VCHG_MAX_RESET_TO_ZERO_TRC);       
#endif    
   
      state_counter = 0;
      return KAL_TRUE;
   }
   else
   {
      state_counter++;
      return KAL_FALSE;
   }
#else
   return KAL_TRUE;
#endif //#if defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)
}

#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
/*
* FUNCTION
*	   bmt_finish_check_on_state
*
* DESCRIPTION                                                           
*   	This function is called to check whether "on state check" already finish
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   KAL_TRUE: finish
*	   KAL_FALSE: not finish
*
* GLOBALS AFFECTED
*     None
*/
kal_bool bmt_finish_check_off_state(void)
{
#if defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)
   static kal_uint8  pre_bat_state = 0xFF;
   static kal_uint32 state_counter = 0; //the counter during this Off state
   static kal_uint32 bmt_off_count  = 0; //the count of this Off state. (how many "200 ms")

   if(BMT.bat_state != pre_bat_state) //change state
   {
      bmt_off_count = bmt_get_off_count();
      pre_bat_state = BMT.bat_state;
      state_counter = 0;
   }
   
   if(state_counter == bmt_off_count)
   {
      state_counter = 0;
      return KAL_TRUE;
   }
   else
   {
      state_counter++;
      return KAL_FALSE;
   }
#else
   return KAL_TRUE;
#endif //#if defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)
}
#endif // End of #if defined(DRV_BMT_HW_PRECC_WORKAROUND)

/*
* FUNCTION
*		bmt_measure_done
*
* DESCRIPTION																			  
*		This function is called when all parameters that charge algorithm needs
*  are all measured done.
*
* CALLS  
*
* PARAMETERS
*		None
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
/*total channel measure done*/
void bmt_measure_done(void)
{
#if defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)
    if(bmt_frequently_check_on_state())
    {
        if(bmt_finish_check_on_state()) 
        {
            BMT_CHRFUNC[BMT.bat_state][BMT.pmictrl_state]();
        }
        else //check the error condition on CC
        {
            drv_trace0(TRACE_GROUP_10, BMT_ERRORCHECK_AT_CHARGE_ON_TRC);         
            BMT_CHRERRORCHECK();
        }
    }
#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
    else if(bmt_frequently_check_off_state())
    {
        if(bmt_finish_check_off_state()) 
        {
            BMT_CHRFUNC[BMT.bat_state][BMT.pmictrl_state]();
        }
        else //check the error condition on CC
        {
            drv_trace0(TRACE_GROUP_10, BMT_ERRORCHECK_AT_CHARGE_OFF_TRC);   
            BMT_CHRERRORCHECK();
        }
    }
#endif // End of #if defined(DRV_BMT_HW_PRECC_WORKAROUND)
   else
#endif //#if defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)
	BMT_CHRFUNC[BMT.bat_state][BMT.pmictrl_state]();
}

/*
* FUNCTION
*		BMT_CallState
*
* DESCRIPTION																			  
*		This function is called by MMI to nodify talk/idle state to BMT task.
*
* CALLS  
*
* PARAMETERS
*		callState: 1, talk mode.
*					 0, idel mode.
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
void BMT_CallState(kal_uint8 callState)
{
	BMT.call_state = callState;	/*Talk time=1, otherwise = 0*/
	drv_trace1(TRACE_GROUP_10, BMT_CALL_STATE_TRC, callState);
}

/*
* FUNCTION
*		BMT_TONOFF
*
* DESCRIPTION																			  
*		This function is to obtain the TON/TOFF paramters in CHR_FAST mode.
*
* CALLS  
*
* PARAMETERS
*		PHY: measured physical parameters
*	  BATTime: the structure of TON/TOFF parameters
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
static void BMT_TONOFF(BATPHYStruct *PHY,CHRTStruct *pBATTime)////======
{
#ifndef __BMT_NO_ISENSE_RESISTOR__
	if(BMT.call_state == talk_mode)
	{
		if (PHY->ICHARGE > bmt_charging_para->FAST_ICHARGE_HIGHLEVEL)
		{
			pBATTime->TON=bmt_charging_para->TONOFFTABLE[3][CHRTON];
			pBATTime->TOFF=bmt_charging_para->TONOFFTABLE[3][CHRTOFF];
		}
		else
		{
			if (PHY->ICHARGE < bmt_charging_para->FAST_ICHARGE_LOWLEVEL)
			{
				pBATTime->TON=bmt_charging_para->TONOFFTABLE[5][CHRTON];
				pBATTime->TOFF=bmt_charging_para->TONOFFTABLE[5][CHRTOFF];
			}
			else
			{
				pBATTime->TON=bmt_charging_para->TONOFFTABLE[4][CHRTON];
				pBATTime->TOFF=bmt_charging_para->TONOFFTABLE[4][CHRTOFF];
			}
		}	
	}
	else
	{	 	
		if (PHY->ICHARGE > bmt_charging_para->FAST_ICHARGE_HIGHLEVEL)
		{
			pBATTime->TON=bmt_charging_para->TONOFFTABLE[0][CHRTON];
			pBATTime->TOFF=bmt_charging_para->TONOFFTABLE[0][CHRTOFF];
		}
		else
		{
			if (PHY->ICHARGE < bmt_charging_para->FAST_ICHARGE_LOWLEVEL)
			{
				pBATTime->TON=bmt_charging_para->TONOFFTABLE[2][CHRTON];
				pBATTime->TOFF=bmt_charging_para->TONOFFTABLE[2][CHRTOFF];
			}
			else
			{
				pBATTime->TON=bmt_charging_para->TONOFFTABLE[1][CHRTON];
				pBATTime->TOFF=bmt_charging_para->TONOFFTABLE[1][CHRTOFF];
			}
		}
	}	
#else // #ifndef __BMT_NO_ISENSE_RESISTOR__
	pBATTime->TON=bmt_charging_para->TONOFFTABLE[0][CHRTON];
	pBATTime->TOFF=bmt_charging_para->TONOFFTABLE[0][CHRTOFF];
#endif // #ifndef __BMT_NO_ISENSE_RESISTOR__
}


/*
* FUNCTION
*		BMT_CtrlUPMUCharge
*
* DESCRIPTION																			  
*		This function is called to control the SW of charge
*
* CALLS  
*
* PARAMETERS
*		ON: 1, charge on	  0, charge off
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
static void BMT_CtrlUPMUCharge(kal_bool ON)
{

	PMU_CTRL_CHR_SET_CSDAC_EN chr_csdac_en;
    PMU_CTRL_CHR_SET_CV_DETECTION_EN set_cv_detect_en;
    PMU_CTRL_CHR_SET_CV_DETECTION_VOLTAGE set_cv_detect_vol;
     
	if(ON == KAL_TRUE)
	{
   

        set_cv_detect_vol.voltage = PMU_VOLT_04_200000_V;// CHR_VBAT_CV_4_2000V
        DclPMU_Control(bmt_PmuHandler, CHR_SET_CV_DETECTION_VOLTAGE, (DCL_CTRL_DATA_T *)&set_cv_detect_vol);

    	set_cv_detect_en.enable = ON;
    	DclPMU_Control(bmt_PmuHandler, CHR_SET_CV_DETECTION_EN, (DCL_CTRL_DATA_T *)&set_cv_detect_en);
    	
	}


	DclPMU_Control(bmt_PmuHandler, CHR_SET_WDT_CLEAR, NULL);	

	chr_csdac_en.enable = ON;
	DclPMU_Control(bmt_PmuHandler, CHR_SET_CSDAC_EN, (DCL_CTRL_DATA_T *)&chr_csdac_en);


	BMT_Charge(ON);
}


/*
* FUNCTION
*		BMT_CtrlCharge
*
* DESCRIPTION																			  
*		This function is called to control the SW of charge
*
* CALLS  
*
* PARAMETERS
*		ON: 1, charge on	  0, charge off
*	  VBAT: the measured voltage of battery.
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
static void BMT_CtrlCharge(kal_uint8 ON, kal_uint32 VBAT)
{
#if defined(MT6236)

  	PMU_CTRL_CHR_SET_CHR_CURRENT set_chr_current;    
#endif

#if defined(__CHARGER_SOFT_START__)
	kal_uint32 curLevel = 0,i;
	PMU_CTRL_CHR_GET_CHR_CURRENT get_chr_current;
    PMU_CTRL_CHR_GET_CHR_CURRENT_LIST get_chr_current_list;

  	PMU_CTRL_CHR_SET_CHR_CURRENT set_chr_current;       
#endif //#if defined(__CHARGER_SOFT_START__)
	/*Prevent Charge Li Battery at CV mode*/
//	if ((((kal_bool)ON == KAL_TRUE) &&
//		(BMT.call_state == talk_mode) &&
//		(VBAT >= bmt_charging_para->V_PROTECT_HIGH_LI) &&
//		(BMT.BatType == LIBAT)) || (BMT.bat_state == CHR_ERROR)
//		)

    drv_trace1(TRACE_GROUP_1, BMT_CTRL_CHARGE_TRC, ON);

	// If bat_state is HOLD, we do NOT enable chr_en
	if ( (BMT.bat_state == CHR_HOLD) || (BMT.bat_state == CHR_ERROR) )
	{
#if defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)
		bmt_chr_force_enable(KAL_FALSE);
#endif ////#if defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)
		BMT.pmictrl_state = PMIC_CHARGEOFF;
		BMT_CtrlUPMUCharge(KAL_FALSE);
		return;
	}

#if defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)
	bmt_chr_force_enable((kal_bool)ON);
#endif ////#if defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)


	if ((kal_bool)ON == KAL_TRUE)
	{
		if (BMT.pmictrl_state == PMIC_CHARGEOFF)
		{      
			BMT.pmictrl_state = PMIC_CHARGEON;
			// Fast plug in/out may cause HW disable current level, but SW do not receive interrupt.
			// Under such scenario the current level will incorrect.
			// Enforce set correct current level every time charge ON.


#if defined(DRV_BMT_PULSE_CHARGING)
            if(BMT.bat_state != CHR_PRE)
            {
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
			if(bmt_IsUSBorCharger() != BMT_USB_IN)	
			{
				if(First_Time_Charge_Enable == KAL_TRUE)
				{
				    drv_trace0(TRACE_GROUP_9, BMT_HIGH_VCHG_FIRST_TIME_CHARGER_ON_TRC);	
				    bmt_high_vchg_first_time_set();
				    First_Time_Charge_Enable = KAL_FALSE;
            }

#if defined(__CHINA_CHARGER_STANDARD__)
				if(chr_usb_detect.chr_usb_present == CHARGER_PRESENT_NON)
				{
				    if(bmt_high_vchg_current > PMU_CHARGE_CURRENT_450_00_MA)
            {
				        bmt_high_vchg_current = PMU_CHARGE_CURRENT_450_00_MA;
				        drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_SET_USB_CHARGE_CURRENT_TRC, CHR_USB_CHARGE_CURRENT);	
				    }
				}
#endif //#if defined(__CHINA_CHARGER_STANDARD__)
    	        
				drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_CHARGE_CURRENT_TRC, bmt_high_vchg_current);	

				bmt_find_and_set_the_nearest_current(bmt_high_vchg_current);
				
				Cur_VCharge_MAX = 0;
				drv_trace0(TRACE_GROUP_9, BMT_HIGH_VCHG_MAX_RESET_TO_ZERO_TRC);	
                              
            }
            else
            {
			    drv_trace0(TRACE_GROUP_9, BMT_HIGH_VCHG_USB_IN_USE_CUSTOM_CHARGE_CURRENT_TRC);	
				bmt_set_chr_current();
			}
                              
#else // Else of #if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
			bmt_set_chr_current();
#endif // #if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)        
            }
		else
		{
#if defined(MT6236)		
			bmt_find_and_set_the_nearest_current(PMU_CHARGE_CURRENT_200_00_MA);
#else
			bmt_set_chr_current(); 
#endif // #if defined(MT6236)
		}
#endif //#if defined(DRV_BMT_PULSE_CHARGING)	


#if defined(DRV_BMT_PULSE_CV_CHARGING)
	bmt_set_chr_current();
#endif //#if defined(DRV_BMT_PULSE_CV_CHARGING)


#if defined(__CHARGER_SOFT_START__)

	        
	        DclPMU_Control(bmt_PmuHandler, CHR_GET_CHR_CURRENT, (DCL_CTRL_DATA_T *)&get_chr_current);
            DclPMU_Control(bmt_PmuHandler, CHR_GET_CHR_CURRENT_LIST, (DCL_CTRL_DATA_T *)&get_chr_current_list);
	        
			// curLevel = get_chr_current.current;
            while(1)
            {
                if(get_chr_current_list.pCurrentList[curLevel] == get_chr_current.current)
                    break;
                curLevel++;
            }
            drv_trace2(TRACE_GROUP_5, BMT_CHARGE_CURRENT_AND_LEVEL_TRC, get_chr_current.current, curLevel);	
            drv_trace1(TRACE_GROUP_5, BMT_TOTAL_CHARGE_CURRENT_LEVEL_TRC, get_chr_current_list.number);
            drv_trace1(TRACE_GROUP_5, BMT_MIN_CHARGE_CURRENT_TRC, get_chr_current_list.pCurrentList[0]);	                        
            drv_trace1(TRACE_GROUP_5, BMT_MAX_CHARGE_CURRENT_TRC, get_chr_current_list.pCurrentList[get_chr_current_list.number - 1]);
            set_chr_current.current = (PMU_CHR_CURRENT_ENUM)get_chr_current_list.pCurrentList[1];
            DclPMU_Control(bmt_PmuHandler, CHR_SET_CHR_CURRENT, (DCL_CTRL_DATA_T *)&set_chr_current);
            
#endif //#if defined(__CHARGER_SOFT_START__)
			BMT_CtrlUPMUCharge(KAL_TRUE);
#if defined(__CHARGER_SOFT_START__)
  	        
			for(i=2;i<=curLevel;i++)
			{
				kal_sleep_task(1); // delay 1 frames
                set_chr_current.current = (PMU_CHR_CURRENT_ENUM)get_chr_current_list.pCurrentList[i];
                DclPMU_Control(bmt_PmuHandler, CHR_SET_CHR_CURRENT, (DCL_CTRL_DATA_T *)&set_chr_current);
				drv_trace1(TRACE_GROUP_5, BMT_SOFT_START_CURRENT_LEVEL, i);	
                drv_trace1(TRACE_GROUP_5, BMT_CURRENT_CHARGE_CURRENT_TRC, get_chr_current_list.pCurrentList[i]);	
			}
                				            
#endif //#if defined(__CHARGER_SOFT_START__)
		}
		else
		{
      	 		drv_trace0(TRACE_GROUP_6, BMT_CHARGING_ALREADY_ON_TRC);
#if defined(DRV_BMT_PULSE_CV_CHARGING)
			BMT_CtrlUPMUCharge(KAL_TRUE);
#endif //#if defined(DRV_BMT_PULSE_CV_CHARGING)				
      		}
	}
	else
	{
		BMT.pmictrl_state = PMIC_CHARGEOFF;
		BMT_CtrlUPMUCharge(KAL_FALSE);
	}
}

/*
* FUNCTION
*		BMT_PhyCheck
*
* DESCRIPTION																			  
*		This function is to check whether the measured physical
*	  parameters is over the physical limitation.
*
* CALLS  
*
* PARAMETERS
*		Data: None
*	
* RETURNS
*		BATPHYS: measured physical parameters
*
* GLOBALS AFFECTED
*	  None
*/


#define VCHARGER_LOW_CHECK_COUNT			6		// VCHARGER low check count
#define VCHARGER_OVER_CHECK_COUNT		  6		// VCHARGER high check count
#define OVER_CURRENT_CHECK_COUNT			3		// Over current check count
#define LOW_CURRENT_CHECK_COUNT			 5		// Low current check count
#define OVER_BATTEMP_CHECK_COUNT			5		// Over battery temperature check count
#define LOW_BATTEMP_CHECK_COUNT			 5		// Low battery temperature check count

// Return KAL_TRUE: Phys status is GOOD
// Return KAL_FALSE: Phys status is BAD, should go to chr error state
static kal_bool BMT_PhyCheck_VCharger(BATPHYStruct *BATPHYS)
{
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
	if ( (BATPHYS->VCHARGER > bmt_high_vchg_para->HIGH_VCHG_TABLE[VCHG_VOL_LEVEL - 1][0]) )
#else
	if ( (BATPHYS->VCHARGER > bmt_charging_para->VCHARGER_HIGH) )
#endif // End of #if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)   
	{
		over_charger_count ++;
		drv_trace1(TRACE_GROUP_6, BMT_PHY_CHECK_OVER_CHARGER_COUNT_TRC, over_charger_count);	
	}
	else
	{
		over_charger_count = 0;
	}
	if ( (BATPHYS->VCHARGER < bmt_charging_para->VCHARGER_LOW) )
	{
		low_charger_count++;
	}
	else
	{			
		low_charger_count = 0;
	}
	if ( (low_charger_count > VCHARGER_LOW_CHECK_COUNT) || (over_charger_count > VCHARGER_OVER_CHECK_COUNT) )
	{
		low_charger_count = 0;
		return KAL_FALSE;
	}
	return KAL_TRUE;
}

#ifndef __BMT_NO_ISENSE_RESISTOR__
// Return KAL_TRUE: Phys status is GOOD
// Return KAL_FALSE: Phys status is BAD, should go to chr error state
static kal_bool BMT_PhyCheck_OverCurrent(BATPHYStruct *BATPHYS)
{
	if (BMT.pmictrl_state == PMIC_CHARGEOFF)
	{
		#if defined(__DRV_BMT_ISENSE_OFFSET_COMPENSATION__)
		if(BATPHYS->ICHARGE > bmt_charging_para->ICHARGE_OFF_HIGH || BATPHYS->ISense_Offset > (bmt_charging_para->ICHARGE_OFF_HIGH / 5))	// x0.2 Ohm resistor
		#else
		if(BATPHYS->ICHARGE > bmt_charging_para->ICHARGE_OFF_HIGH)
		#endif	
		{
			over_current_count++;
			drv_trace1(TRACE_GROUP_6, BMT_PHY_CHECK_OVER_CURRENT_COUNT_TRC, over_current_count);	
		}
		else
		{				
			over_current_count = 0;	
		}
	}
	else
	{
		if(BATPHYS->ICHARGE > bmt_charging_para->ICHARGE_ON_HIGH)
		{
			over_current_count++;
			drv_trace1(TRACE_GROUP_6, BMT_PHY_CHECK_OVER_CURRENT_COUNT_TRC, over_current_count);	
		}
		else
		{				
			over_current_count = 0;	  
		}	
	}
	if (over_current_count > OVER_CURRENT_CHECK_COUNT)
	{
		over_current_count = 0;
		return KAL_FALSE;
		
	}
	return KAL_TRUE;
}

// Return KAL_TRUE: Phys status is GOOD
// Return KAL_FALSE: Phys status is BAD, should go to chr error state
static kal_bool BMT_PhyCheck_LowCurrent(BATPHYStruct *BATPHYS)
{
	if (BMT.pmictrl_state != PMIC_CHARGEOFF)
	{
		if ( (BMT.bat_state == CHR_FAST)) //|| (BMT.bat_state == CHR_PRE) )
		{
#if !defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)
			if(BATPHYS->ICHARGE < bmt_charging_para->ICHARGE_ON_LOW)
			{
				low_current_count++;
				drv_trace1(TRACE_GROUP_6, BMT_PHY_CHECK_LOW_CURRENT_COUNT_TRC, low_current_count);	
			}
			else
			{				
				low_current_count = 0;
			}
			if (low_current_count > LOW_CURRENT_CHECK_COUNT)
			{
				low_current_count = 0;
				return KAL_FALSE;
			}
#endif //#if !defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)
		}//if ( (BMT.bat_state == CHR_FAST) ) //|| (BMT.bat_state == CHR_PRE) )
	}//if (BMT.pmictrl_state != PMIC_CHARGEOFF)
	return KAL_TRUE;
}
#endif // End of #ifndef __BMT_NO_ISENSE_RESISTOR__

// Return KAL_TRUE: Phys status is GOOD
// Return KAL_FALSE: Phys status is BAD, should go to chr error state
static kal_bool BMT_PhyCheck_VBat(BATPHYStruct *BATPHYS)
{
#if defined(CHR_WITH_LI_ION_BATTERY)    
	if((BATPHYS->VBAT > bmt_charging_para->MAX_VBAT_LI) && (BMT.BatType == LIBAT) )
	{
		return KAL_FALSE;
	}
#endif 
   
#if defined(CHR_WITH_NI_MH_BATTERY)
	if ((BATPHYS->VBAT > bmt_charging_para->MAX_VBAT_NI) && (BMT.BatType == NIBAT) )
	{
		return KAL_FALSE;
	}
#endif    
	return KAL_TRUE;
}

// Return KAL_TRUE: Phys status is GOOD
// Return KAL_FALSE: Phys status is BAD, should go to chr error state
static kal_bool BMT_PhyCheck_LowBatTemp(BATPHYStruct *BATPHYS)
{
	if (BATPHYS->BATTMP > bmt_charging_para->BATTMP_0C && BATPHYS->BATTMP < bmt_charging_para->BATTMP_MINUS_40C)  /*battery temperature < 0C*/
	{
		low_temper_count ++;
		drv_trace1(TRACE_GROUP_6, BMT_PHY_CHECK_LOW_TRMPER_COUNT_TRC, low_temper_count);	
	}
	else
	{
		low_temper_count = 0;
	}
	
	if (low_temper_count > LOW_BATTEMP_CHECK_COUNT)
	{
		return KAL_FALSE;
	}
	
	return KAL_TRUE;
}

// Return KAL_TRUE: Phys status is GOOD
// Return KAL_FALSE: Phys status is BAD, should go to chr error state
static kal_bool BMT_PhyCheck_HighBatTemp(BATPHYStruct *BATPHYS)
{
	/*y=69.65-47.4x*/
	if (BATPHYS->BATTMP < bmt_charging_para->BATTMP_45C)	/*battery temperature > 45C*/
	{
		over_temper_count++;
		drv_trace1(TRACE_GROUP_6, BMT_PHY_CHECK_OVER_TEMPER_COUNT_TRC, over_temper_count);	
	}
	else
	{
		over_temper_count = 0;
	}
	
	if (over_temper_count > OVER_BATTEMP_CHECK_COUNT)
	{
		over_temper_count = 0;
		return KAL_FALSE;
	}
	
	return KAL_TRUE;
}

// Return KAL_TRUE: Phys status is GOOD
// Return KAL_FALSE: Phys status is BAD, should go to chr error state
static kal_bool BMT_PhyCheck_BadBattContact(BATPHYStruct *BATPHYS)
{
	if (BATPHYS->BATTMP > bmt_charging_para->BATTMP_MINUS_40C)
	{
		return KAL_FALSE;
	}
	
	return KAL_TRUE;
	
}

// KAL_TRUE: Should enter charge HOLD state
// KAL_FALSE: Should NOT enter charge HOLD state
static kal_bool BMT_PhyCheck_EnterChargeHold(BATPHYStruct *BATPHYS)
{
	if ((BMT.call_state == talk_mode) &&
		(BATPHYS->VBAT >= bmt_charging_para->V_PROTECT_HIGH_LI) &&
		(BMT.BatType == LIBAT) )
	{
		if (BMT.pmictrl_state == PMIC_CHARGEOFF ||
			((BMT.pmictrl_state == PMIC_CHARGEON) &&
			((BMT.bat_state == CHR_TOPOFF) || (BMT.bat_state == CHR_BATFULL) || (BMT.bat_state == CHR_POSTFULL))))
		{
			return KAL_TRUE;
		}
	}
	
	return KAL_FALSE;
	
}

// KAL_TRUE:  Should turn off safety timer
// KAL_FALSE: Should turn on safety timer
static kal_bool BMT_PhyCheck_DisableSafetyTimer(void)
{
	//In talking mode, the power consumption may be large and cause long time to complete charging
	if (BMT.call_state == talk_mode)
	{
		return KAL_TRUE;
	}
	
	// When in hold state, the safety timer should be disabled
	// Because we do NOT perform charging
	if (BMT.bat_state == CHR_HOLD)
	{
		return KAL_TRUE;
	}
	
	return KAL_FALSE;
}

static void BMT_PhyCheck(BATPHYStruct *BATPHYS)
{
	if (bmt_charging_para->bmt_check_charger)
	{
		if (BMT_PhyCheck_VCharger(BATPHYS) == KAL_FALSE)
		{
			drv_trace0(TRACE_GROUP_10, BMT_INVALID_CHARGER_TRC);
			BMT_sendMes2UEM(BMT_INVALID_CHARGER);
			BMT.bat_state = CHR_ERROR;
			return;
		}
	}
	
#ifndef __BMT_NO_ISENSE_RESISTOR__
	if (BMT_PhyCheck_OverCurrent(BATPHYS) == KAL_FALSE)
	{
		drv_trace0(TRACE_GROUP_10, BMT_ICHARGE_OVER_TRC);
		BMT_sendMes2UEM(BMT_OVERCHARGECURRENT);
		BMT.bat_state = CHR_ERROR;
		return;
	}
	
	if (BMT_PhyCheck_LowCurrent(BATPHYS) == KAL_FALSE)
	{
		drv_trace0(TRACE_GROUP_10, BMT_ICHARGE_LOW_TRC);
		BMT_sendMes2UEM(BMT_LOWCHARGECURRENT);
		BMT.bat_state = CHR_ERROR;
		return;
	}
#endif // #ifndef __BMT_NO_ISENSE_RESISTOR__
	
	if (BMT_PhyCheck_VBat(BATPHYS) == KAL_FALSE)
	{
		drv_trace0(TRACE_GROUP_10, BMT_VBAT_OVER_TRC);
		BMT_sendMes2UEM(BMT_OVERVOLPROTECT);
		BMT.bat_state = CHR_ERROR;
		return;
	}
	
	if (bmt_charging_para->bmt_check_temp)
	{
		if (BMT_PhyCheck_HighBatTemp(BATPHYS) == KAL_FALSE)
		{
			drv_trace0(TRACE_GROUP_10, BMT_VTEMP_OVER_TRC);
			BMT_sendMes2UEM(BMT_OVERBATTEMP);
			BMT.bat_state = CHR_ERROR;
			return;
		}
		
		if (BMT_PhyCheck_LowBatTemp(BATPHYS) == KAL_FALSE)
		{
			drv_trace0(TRACE_GROUP_10, BMT_VTEMP_LOW_TRC);
			BMT_sendMes2UEM(BMT_LOWBATTEMP);
			BMT.bat_state = CHR_ERROR;
			return;
		}
		
		if (BMT_PhyCheck_BadBattContact(BATPHYS) == KAL_FALSE)
		{
			BMT_sendMes2UEM(BMT_BATTERY_BAD_CONTACT);
			BMT.bat_state = CHR_ERROR;
			return;
		}
	}		
	
	
	if (BMT_PhyCheck_DisableSafetyTimer())
	{
		// We should disable safety timer
		if (SaftyTimer_Flag == BMT_SAFETY_TIMER_ON)
		{	
			stack_stop_timer(&ChargeTimeout_timer);
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
            drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, bmt_total_charge_time);
#else
			drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, BMT_TOTAL_CHARGE_TIME);
#endif			
			SaftyTimer_Flag = BMT_SAFETY_TIMER_OFF; 
		}  
	}
	else
	{
		// We should enable safety timer
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
        if (SaftyTimer_Flag == BMT_SAFETY_TIMER_OFF && bmt_safety_timer_config == KAL_TRUE)
#else
		if (SaftyTimer_Flag == BMT_SAFETY_TIMER_OFF)
#endif         
		{	
#ifndef __BMT_CHARGE_GUARD_TIME__
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
            stack_start_timer(&ChargeTimeout_timer, 0, KAL_TICKS_1_MIN*bmt_total_charge_time);
            drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_START_TRC, bmt_total_charge_time);
#else
			stack_start_timer(&ChargeTimeout_timer, 0, KAL_TICKS_1_MIN*BMT_TOTAL_CHARGE_TIME);
			drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_START_TRC, BMT_TOTAL_CHARGE_TIME);
#endif
#endif
			drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_START_TRC, BMT_TOTAL_CHARGE_TIME);
			SaftyTimer_Flag = BMT_SAFETY_TIMER_ON; 
		}	
	}
	
	// Decide whether to enter HOLD state or NOT
	if (BMT_PhyCheck_EnterChargeHold(BATPHYS) == KAL_TRUE)
	{
		drv_trace0(TRACE_GROUP_10, BMT_CHR_HOLD_TRC);
		BMT.bat_state = CHR_HOLD;
		return;
	}
	
}

kal_bool BMT_Host_CHR_Is_Charge_Full(BATPHYStruct *pBATPHYS)
{
#ifndef __BMT_NO_ISENSE_RESISTOR__
	if (pBATPHYS->ICHARGE < bmt_charging_para->I_TOPOFF2FULL_THRES)
	{
		return KAL_TRUE;
	}
	else
	{
		return KAL_FALSE;
	}
#else	
	ASSERT(0); // When this function is called, we should have some operations to check charge full
	return KAL_FALSE;
#endif // #ifndef __BMT_NO_ISENSE_RESISTOR__
}

kal_bool BMT_CHR_Is_Charge_Full(BATPHYStruct *pBATPHYS)
{
	// Without external charger
#ifndef __GENERAL_EXTERNAL_CHARGER__
	return BMT_Host_CHR_Is_Charge_Full(pBATPHYS);
#endif // #ifndef __GENERAL_EXTERNAL_CHARGER__
	
	// With external charger
#if defined(__GENERAL_EXTERNAL_CHARGER__)
	if (BMT_CHR_FACTOR_CHECK_BY_CHARGER_DEV == default_get_chr_fac_check_support(BMT_CHR_FACTOR_CHARGE_FULL))
	{
		// Query external charger
		return ext_charger->get_charge_full(pBATPHYS->VBAT);
	}
	else
	{
		return BMT_Host_CHR_Is_Charge_Full(pBATPHYS);
	}
#endif // #if defined(__GENERAL_EXTERNAL_CHARGER__)
}

static kal_bool BMT_CHR_Is_Under_ExtremeTmp(BATPHYStruct *pBATPHYS)
{
	if (bmt_charging_para->bmt_check_temp == KAL_FALSE)
	{
		return KAL_FALSE;
	}
#if defined(__GENERAL_EXTERNAL_CHARGER__)
	// With external charger
	if (BMT_CHR_FACTOR_CHECK_BY_CHARGER_DEV == default_get_chr_fac_check_support(BMT_CHR_FACTOR_UNDER_EXTREMETMP))
	{
		kal_bool ret;
		
		// Query external charger
		ret = ext_charger->get_charge_under_extremetmp(pBATPHYS->BATTMP);
		if (KAL_TRUE == ret)
		{
			drv_trace0(TRACE_GROUP_10, BMT_CHR_UNDER_EXTREMETMP_TRC);
		}
		return ret;
	}
	else
	{
		return KAL_FALSE;
	}
#else // #if defined(__GENERAL_EXTERNAL_CHARGER__)
	// Without external charger
	return KAL_FALSE;
#endif // #if defined(__GENERAL_EXTERNAL_CHARGER__)
}

static kal_bool BMT_CHR_Is_ExtremeTmp_Charge_Full(BATPHYStruct *pBATPHYS)
{
	if (bmt_charging_para->bmt_check_temp == KAL_FALSE)
	{
		return KAL_FALSE;
	}
	
#if defined(__GENERAL_EXTERNAL_CHARGER__)
	// With external charger
	if (BMT_CHR_FACTOR_CHECK_BY_CHARGER_DEV == default_get_chr_fac_check_support(BMT_CHR_FACTOR_CHARGE_EXTREMETMP_FULL))
	{
		kal_bool ret;
		
		// Query external charger
		ret = ext_charger->get_charge_extremetmp_full(pBATPHYS->VBAT);
		if (KAL_TRUE == ret)
		{
			drv_trace0(TRACE_GROUP_10, BMT_CHR_EXTREMETMP_BATFULL_CHANGE_TRC);
#ifndef __DRV_BMT_CHARGING_COMPLETE_MSG__
			BMT_sendMes2UEM(BMT_CHARGE_COMPLETE);
#endif
			BMT.bat_state = CHR_BATFULL;
			bmt_stop_stoptimer();
			stack_stop_timer(&ChargeTimeout_timer);
#ifdef __BMT_CHARGE_GUARD_TIME__
			bmt_stop_guardtimer();
#endif // #ifdef __BMT_CHARGE_GUARD_TIME__
#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)
			bmt_stop_estimativetimer();
#endif //#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)
			BMT_CHARSTOP();
		}
		return ret;
	}
	else
	{
		return KAL_FALSE;
	}
#else // #if defined(__GENERAL_EXTERNAL_CHARGER__)
	// Without external charger
	return KAL_FALSE;
#endif // #if defined(__GENERAL_EXTERNAL_CHARGER__)
	
}

static kal_bool BMT_CHR_Is_ExtremeTmp_Charge_Recharge(BATPHYStruct *pBATPHYS)
{
	if (bmt_charging_para->bmt_check_temp == KAL_FALSE)
	{
		return KAL_FALSE;
	}
	
#if defined(__GENERAL_EXTERNAL_CHARGER__)
	// With external charger
	if (BMT_CHR_FACTOR_CHECK_BY_CHARGER_DEV == default_get_chr_fac_check_support(BMT_CHR_FACTOR_CHARGE_EXTREMETMP_RECHARGE))
	{
		kal_bool ret;
		
		// Query external charger
		ret = ext_charger->get_charge_extremetmp_recharge(pBATPHYS->VBAT);
		if (KAL_TRUE == ret)
		{
			drv_trace0(TRACE_GROUP_10, BMT_CHR_EXTREMETMP_CHARGE_RECHARGE_TRC);
		}
		return ret;
	}
	else
	{
		return KAL_FALSE;
	}
#else // #if defined(__GENERAL_EXTERNAL_CHARGER__)
	// Without external charger
	return KAL_FALSE;
#endif // #if defined(__GENERAL_EXTERNAL_CHARGER__)
	
}

/*
* FUNCTION
*		BMT_CHRPRE_ON
*
* DESCRIPTION																			  
*		This function is called when charger is on, and BMT charge module 
*	  is at CHR_PRE state.
*
* CALLS  
*
* PARAMETERS
*		None
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
static void BMT_CHRPRE_ON(void)
{
	BATPHYStruct BATPHYS;
	drv_trace0(TRACE_GROUP_10, BMT_CHRPRE_ON_STATE_TRC);
	if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
	{
		BMT_PhyCheck(&BATPHYS);
		BMT_CtrlCharge((kal_uint8)KAL_FALSE, BATPHYS.VBAT);	//Turn off Charge
	}
	bmt_timer_config(bmt_charging_para->PRE_TOFF*CHARGING_TIME_UNIT);
}

/*
* FUNCTION
*		BMT_CHRPRE_OFF
*
* DESCRIPTION																			  
*		This function is called when charger is off, and BMT charge module 
*	  is at CHR_PRE state.
*
* CALLS  
*
* PARAMETERS
*		None
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
static void BMT_CHRPRE_OFF(void)
{
	BATPHYStruct BATPHYS;
	#if defined(PMIC_PRESENT)
	
    #endif
	drv_trace0(TRACE_GROUP_10, BMT_CHRPRE_OFF_STATE_TRC);
	if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is off period
	{
		BMT_PhyCheck(&BATPHYS);
		if ((BMT.bat_state != CHR_ERROR) 
			&& (BMT_CHR_Is_Under_ExtremeTmp(&BATPHYS) == KAL_TRUE) 
			&& (BMT_CHR_Is_ExtremeTmp_Charge_Full(&BATPHYS) == KAL_TRUE))
		{
			return;
		}
		if( ((BATPHYS.VBAT) > bmt_charging_para->V_PRE2FAST_THRES) && (BMT.bat_state !=CHR_ERROR)&&(BMT.bat_state != CHR_HOLD))
		{
#if defined(DRV_BMT_PULSE_CHARGING)            
            if(BMT_CHRPRE_TO_CHRBATFULL_CHECK())
            {
				return;				
			}
#else
			BMT_CtrlCharge((kal_uint8)KAL_TRUE, BATPHYS.VBAT);
#endif // #if defined(DRV_BMT_PULSE_CHARGING)

			BMT.bat_state = CHR_FAST;
			if(bmt_Get_PowerOn_Type()== (kal_uint8)PRECHRPWRON)//PRECHRPWRON
			{
                                ilm_struct      bmt_ilm_local;
				ilm_struct *BMT_ilm=&bmt_ilm_local;				
				/*change power on type as charger power on*/						 
				bmt_Modify_PowerOn_Type((kal_uint8)CHRPWRON);
				#ifndef L4_NOT_PRESENT
				#if defined(PMIC_PRESENT)
            	
            	DclPW_Control(bmt_PmuHandler, PW_CMD_UPDATE_FLAGS, NULL);
            	               
		  
                #endif // #if defined(PMIC_PRESENT)
#endif // #ifndef L4_NOT_PRESENT
				DRV_BuildPrimitive(BMT_ilm, MOD_BMT, MOD_UEM, 
										MSG_ID_BMT_LEAVE_PRECHARGE_IND,NULL);
				msg_send(BMT_ilm);										
			}							
			drv_trace0(TRACE_GROUP_10, BMT_FAST_CHARGE_CHANGE_TRC);
		}
		else
		{
			BMT_CtrlCharge((kal_uint8)KAL_TRUE, BATPHYS.VBAT);	//Turn on Charge
		}
	}
	bmt_timer_config(bmt_charging_para->PRE_TON*CHARGING_TIME_UNIT);
}

/*
* FUNCTION
*		BMT_CHRFAST_ON
*
* DESCRIPTION																			  
*		This function is called when charger is on, and BMT charge module 
*	  is at CHR_FAST state.
*
* CALLS  
*
* PARAMETERS
*		None
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
static void BMT_CHRFAST_ON(void)
{
	BATPHYStruct BATPHYS;
	drv_trace0(TRACE_GROUP_10, BMT_FAST_ON_STATE_TRC);
	if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
	{
		BMT_PhyCheck(&BATPHYS);
		BMT_TONOFF(&BATPHYS,&BATTime);
		if(BMT.bat_state != CHR_ERROR)
		{
#if defined(CHR_WITH_NI_MH_BATTERY)            
			//Change state
			if (BMT.BatType == NIBAT)
			{
				if ( ((VBATtmp - BATPHYS.VBAT) > 100000) && (VBATtmp != 0) )
				{
					BMT.bat_state = CHR_BATFULL;
					bmt_stop_stoptimer();
					stack_stop_timer(&ChargeTimeout_timer);
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
					drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, bmt_total_charge_time);
#else
					drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, BMT_TOTAL_CHARGE_TIME);
#endif					/*30min*/
					bmt_set_stoptimer(STOPTIMER_TIMEOUT_TICK);
					VBATtmp = 0;
					BMT_CtrlCharge((kal_uint8)KAL_FALSE, BATPHYS.VBAT);
					BMT_sendMes2UEM(BMT_CHARGE_COMPLETE);
					drv_trace0(TRACE_GROUP_10, BMT_CHR_BATFULL_CHANGE_TRC);
					bmt_timer_config(BATTime.TOFF*CHARGING_TIME_UNIT);
					return;
				}

				if (BATPHYS.BATTMP < bmt_charging_para->V_TEMP_FAST2FULL_THRES_NI)
				{
					BMT.bat_state = CHR_BATFULL;
					bmt_stop_stoptimer();
					stack_stop_timer(&ChargeTimeout_timer);
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
					drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, bmt_total_charge_time);
#else
					drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, BMT_TOTAL_CHARGE_TIME);
#endif					/*30min*/
					bmt_set_stoptimer(STOPTIMER_TIMEOUT_TICK);
					BMT_CtrlCharge((kal_uint8)KAL_FALSE, BATPHYS.VBAT);
					BMT_sendMes2UEM(BMT_CHARGE_COMPLETE);
					bmt_timer_config(BATTime.TOFF*CHARGING_TIME_UNIT);
					drv_trace0(TRACE_GROUP_10, BMT_CHR_BATFULL_CHANGE_TRC);
					return;
				}
				VBATtmp = BATPHYS.VBAT;
			}
#endif // End of #if defined(CHR_WITH_NI_MH_BATTERY)
		}
		BMT_CtrlCharge((kal_uint8)KAL_FALSE, BATPHYS.VBAT);	//Turn off Charge
	}
	bmt_timer_config(BATTime.TOFF*CHARGING_TIME_UNIT);
}

/*
* FUNCTION
*		BMT_CHRFAST_OFF
*
* DESCRIPTION																			  
*		This function is called when charger is off, and BMT charge module 
*	  is at CHR_FAST state.
*
* CALLS  
*
* PARAMETERS
*		None
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
static void BMT_CHRFAST_OFF(void)
{
	BATPHYStruct BATPHYS;
	drv_trace0(TRACE_GROUP_10, BMT_FAST_OFF_STATE_TRC);
	if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
	{
		BMT_PhyCheck(&BATPHYS);
		if ((BMT.bat_state != CHR_ERROR) 
			&& (BMT_CHR_Is_Under_ExtremeTmp(&BATPHYS) == KAL_TRUE)
			&& (BMT_CHR_Is_ExtremeTmp_Charge_Full(&BATPHYS) == KAL_TRUE))
		{
			return;
		}
		if((BMT.bat_state != CHR_ERROR)&&(BMT.bat_state != CHR_HOLD))
		{
			if ((BMT.BatType == LIBAT) &&
				 (BATPHYS.VBAT > bmt_charging_para->V_FAST2TOPOFF_THRES)
				)
			{
				BMT.bat_state = CHR_TOPOFF;
				BMT_CtrlCharge((kal_uint8)KAL_TRUE, BATPHYS.VBAT);
				drv_trace0(TRACE_GROUP_10, BMT_CHR_TOPOFF_CHANGE_TRC);
				bmt_timer_config(BATTime.TON*CHARGING_TIME_UNIT);
#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__) 
				bmt_set_estimativetimer(ESTIMATIVE_TIMEOUT_TICK);
#endif //#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__) 
				return;
			}
#if defined(CHR_WITH_NI_MH_BATTERY)
			if ((BMT.BatType == NIBAT) &&
				 (BATPHYS.BATTMP < bmt_charging_para->V_TEMP_FAST2FULL_THRES_NI)
				)
			{
				BMT.bat_state = CHR_BATFULL;
				BMT_CtrlCharge((kal_uint8)KAL_FALSE, BATPHYS.VBAT);
				bmt_stop_stoptimer();
				stack_stop_timer(&ChargeTimeout_timer);
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
				drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, bmt_total_charge_time);
#else
				drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, BMT_TOTAL_CHARGE_TIME);
#endif          
				/*30min*/
				bmt_set_stoptimer(STOPTIMER_TIMEOUT_TICK);
				BMT_sendMes2UEM(BMT_CHARGE_COMPLETE);
				drv_trace0(TRACE_GROUP_10, BMT_CHR_BATFULL_CHANGE_TRC);
			}
#endif // End of #if defined(CHR_WITH_NI_MH_BATTERY)
			BMT_CtrlCharge((kal_uint8)KAL_TRUE, BATPHYS.VBAT);	//Turn on Charge
		}
	}
	bmt_timer_config(BATTime.TON*CHARGING_TIME_UNIT);
}

/*
* FUNCTION
*		BMT_CHRTOPOFF_ON
*
* DESCRIPTION																			  
*		This function is called when charger is on, and BMT charge module 
*	  is at CHR_TOPOFF state.
*
* CALLS  
*
* PARAMETERS
*		None
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
static void BMT_CHRTOPOFF_ON(void)	  //CV
{
	BATPHYStruct BATPHYS;
	drv_trace0(TRACE_GROUP_10, BMT_CHRTOPOFF_ON_STATE_TRC);
	if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
	{
		BMT_PhyCheck(&BATPHYS);
		if(BMT.bat_state != CHR_ERROR)
		{
#if defined(DRV_BMT_PULSE_CHARGING) || defined(__DRV_BMT_ALWAYS_PULSE_CHARGING__) 
			BMT_CtrlCharge((kal_uint8)KAL_FALSE, BATPHYS.VBAT);
			bmt_timer_config(bmt_charging_para->TOPOFF_TOFF*CHARGING_TIME_UNIT);
			return;
#else // #if defined(DRV_BMT_PULSE_CHARGING)

			/*for efuse error with CV voltage on MT6235*/
			bmt_set_vbat_cv_calibration(BATPHYS.VBAT);
			
#if defined (WISDOM35B_DEMO_BB)
			if (BATPHYS.VBAT > 4235000)  // if reach 4.235V then TOPOFF => FULL
#else
				if (BMT_CHR_Is_Charge_Full(&BATPHYS))
#endif
			{
				BATFULL_index++;
				if (BATFULL_index == 6)
				{
					BATFULL_index = 0;	
					BMT_CtrlCharge((kal_uint8)KAL_TRUE, BATPHYS.VBAT);
					BMT.bat_state = CHR_BATFULL;
					bmt_stop_stoptimer();
					stack_stop_timer(&ChargeTimeout_timer);
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
					drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, bmt_total_charge_time);
#else
						drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, BMT_TOTAL_CHARGE_TIME);
#endif          					/*30min*/
					bmt_set_stoptimer(STOPTIMER_TIMEOUT_TICK);
					BMT_sendMes2UEM(BMT_CHARGE_COMPLETE);
					drv_trace0(TRACE_GROUP_10, BMT_CHR_BATFULL_CHANGE_TRC);
				}
				else
				{
					BMT_CtrlCharge((kal_uint8)KAL_TRUE, BATPHYS.VBAT);
				}
			}
			else
			{
				BATFULL_index = 0;
				BMT_CtrlCharge((kal_uint8)KAL_TRUE, BATPHYS.VBAT);
			}
#endif //#if defined(DRV_BMT_PULSE_CHARGING)
		}//if (BMT.bat_state != CHR_ERROR)
	}//if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
	bmt_timer_config(bmt_charging_para->TOPOFF_TON*CHARGING_TIME_UNIT);
}

/*
* FUNCTION
*		BMT_CHRTOPOFF_OFF
*
* DESCRIPTION																			  
*		This function is called when charger is off, and BMT charge module 
*	  is at CHR_TOPOFF state.
*
* CALLS  
*
* PARAMETERS
*		None
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
static void BMT_CHRTOPOFF_OFF(void)
{
#if defined(DRV_BMT_PULSE_CHARGING)
	BATPHYStruct BATPHYS;
	drv_trace0(TRACE_GROUP_10, BMT_CHRTOPOFF_OFF_STATE_TRC);
	if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
	{
#if defined(__DRV_BMT_USE_ADC_DETECT_FULL__)
		if(bmt_get_chr_cv_det() || (BATPHYS.VBAT >= 4200000))
#else
		if(bmt_get_chr_cv_det())
#endif //#if defined(__DRV_BMT_USE_ADC_DETECT_FULL__)
		{
			BATFULL_index++;
		}
		else
		{
			BATNOTFULL_index++;
		}
		if(BATFULL_index == 6 )
		{
			// change state to post full
			BMT.bat_state = CHR_POSTFULL;
			drv_trace0(TRACE_GROUP_10, BMT_CHR_POSTFULL_CHANGE_TRC);
			/*30min*/
			bmt_set_stoptimer(KAL_TICKS_1_MIN*30);
			BMT_sendMes2UEM(BMT_CHARGE_COMPLETE);
			bmt_timer_config(bmt_charging_para->BATPOSTFULL_TWAIT_LI*KAL_TICKS_1_SEC); //wait 90 seconds, then check the vbat at BMT_CHRBATFULL_OFF
			BATFULL_index = BATNOTFULL_index = 0; //reset the index, recount the percentage again.
			return;
		}
		BMT_CtrlCharge((kal_uint8)KAL_TRUE, BATPHYS.VBAT);
	}
	bmt_timer_config(bmt_charging_para->TOPOFF_TON*CHARGING_TIME_UNIT);
#elif defined(__DRV_BMT_ALWAYS_PULSE_CHARGING__)
	BATPHYStruct BATPHYS;
	drv_trace0(TRACE_GROUP_10, BMT_CHRTOPOFF_OFF_STATE_TRC);
	if(BMT.BatType == LIBAT)
	{
		if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
		{
			BMT_PhyCheck(&BATPHYS);
			if ((BMT.bat_state != CHR_ERROR) 
				&& (BMT_CHR_Is_Under_ExtremeTmp(&BATPHYS) == KAL_TRUE)
				&& (BMT_CHR_Is_ExtremeTmp_Charge_Full(&BATPHYS) == KAL_TRUE))
			{
				BATFULL_index = 0;
				return;
			}
			if ((BMT.bat_state != CHR_ERROR)&&(BMT.bat_state != CHR_HOLD))
			{
//already start a estimative timer in fast state, 
//not check VBAT full condition here
#if !defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__) 
				if (BMT_CHR_Is_Charge_Full(&BATPHYS))
				{
					BATFULL_index++;
					if (BATFULL_index == 1) //for always pulse charging only need once
					{
						BATFULL_index = 0;
						BMT.bat_state = CHR_BATFULL;
						bmt_stop_stoptimer();
						stack_stop_timer(&ChargeTimeout_timer);
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
						drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, bmt_total_charge_time);
#else
						drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, BMT_TOTAL_CHARGE_TIME);
#endif    
						/*30min*/
						bmt_set_stoptimer(STOPTIMER_TIMEOUT_TICK);
						BMT_sendMes2UEM(BMT_CHARGE_COMPLETE);
						drv_trace0(TRACE_GROUP_10, BMT_CHR_BATFULL_CHANGE_TRC);
					}
				}
				else
				{
					BATFULL_index = 0;
				}
#endif //#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)
				BMT_CtrlCharge((kal_uint8)KAL_TRUE, BATPHYS.VBAT);
			}
			else
			{
				BMT_CtrlCharge((kal_uint8)KAL_FALSE, BATPHYS.VBAT);
			} // if(!error)
		} // if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
	} //if(BMT.BatType == LIBAT)
	bmt_timer_config(bmt_charging_para->TOPOFF_TON*CHARGING_TIME_UNIT);
#else
	drv_trace0(TRACE_GROUP_10, BMT_CHRTOPOFF_OFF_STATE_TRC);
#endif //#if defined(DRV_BMT_PULSE_CHARGING)
}


#if defined(DRV_BMT_PULSE_CHARGING)
/*
* FUNCTION
*		BMT_CHRPOSTFULL_ON
*
* DESCRIPTION																			  
*		This function is called when charger is on, and BMT charge module 
*	  is at CHR_POSTFULL state.
*
* CALLS  
*
* PARAMETERS
*		None
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
static void BMT_CHRPOSTFULL_ON(void)
{
	BATPHYStruct BATPHYS;
	
	drv_trace0(TRACE_GROUP_10, BMT_CHRBATPOSTFULL_ON_STATE_TRC);
	if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
	{
		BMT_CtrlCharge((kal_uint8)KAL_FALSE, BATPHYS.VBAT);
		BMT_PhyCheck(&BATPHYS);
	}//if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
	bmt_timer_config(bmt_charging_para->BATPOSTFULL_TOFF_LI*CHARGING_TIME_UNIT);
}

/*
* FUNCTION
*		BMT_CHRPOSTFULL_OFF
*
* DESCRIPTION																			  
*		This function is called when charger is off, and BMT charge module 
*	  is at CHR_POSTFULL state.
*
* CALLS  
*
* PARAMETERS
*		None
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
static void BMT_CHRPOSTFULL_OFF(void)
{
	BATPHYStruct BATPHYS;
	
	drv_trace0(TRACE_GROUP_10, BMT_CHRBATPOSTFULL_OFF_STATE_TRC);
	if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
	{
		if(BMT.bat_state != CHR_ERROR)
		{
#if defined(__DRV_BMT_USE_ADC_DETECT_FULL__)
			if(bmt_get_chr_cv_det() || (BATPHYS.VBAT >= 4200000))
#else
			if(bmt_get_chr_cv_det())
#endif //#if defined(__DRV_BMT_USE_ADC_DETECT_FULL__)
			{
				BATFULL_index++;
			}
			else
			{
				BATNOTFULL_index++;
			}
			if(BATFULL_index == 6)
			{
				// change state to bat full
				BMT.bat_state = CHR_BATFULL;
				bmt_stop_stoptimer();
				stack_stop_timer(&ChargeTimeout_timer);
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
				drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, bmt_total_charge_time);
#else
				drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, BMT_TOTAL_CHARGE_TIME);
#endif    				
				drv_trace0(TRACE_GROUP_10, BMT_CHR_BATFULL_CHANGE_TRC);
				BMT.highfull = 1;
				BATFULL_index = BATNOTFULL_index = 0;
				batfull_msg_flag = KAL_TRUE;
				bmt_timer_config(bmt_charging_para->BATPOSTFULL_TON_LI*CHARGING_TIME_UNIT);
				return;
			}
			BMT_CtrlCharge((kal_uint8)KAL_TRUE, BATPHYS.VBAT);
		}
	}
	bmt_timer_config(bmt_charging_para->BATPOSTFULL_TON_LI*CHARGING_TIME_UNIT);
}
#endif //#if defined(DRV_BMT_PULSE_CHARGING)

/*
* FUNCTION
*		BMT_CHRBATFULL_ON
*
* DESCRIPTION																			  
*		This function is called when charger is on, and BMT charge module 
*	  is at CHR_BATFULL state.
*
* CALLS  
*
* PARAMETERS
*		None
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
static void BMT_CHRBATFULL_ON(void)
{
	BATPHYStruct BATPHYS;
	drv_trace0(TRACE_GROUP_10, BMT_CHRBATFULL_ON_STATE_TRC);
	if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
	{
		BMT_PhyCheck(&BATPHYS);
		if(BMT.bat_state != CHR_ERROR)
		{
			if (BMT.BatType == LIBAT)
			{
#if defined(__DRV_BMT_ALWAYS_PULSE_CHARGING__) || defined(DRV_BMT_PULSE_CHARGING)
				BMT_CtrlCharge((kal_uint8)KAL_FALSE, BATPHYS.VBAT);
				bmt_timer_config(bmt_charging_para->BATFULL_TOFF_LI*CHARGING_TIME_UNIT);
#else
				if ((BATPHYS.VBAT) < bmt_charging_para->V_FULL2FAST_THRES)
				{
					BMT.bat_state = CHR_FAST;
					bmt_stop_stoptimer();
					drv_trace0(TRACE_GROUP_10, BMT_CHR_FAST_CHANGE_TRC);
				}
				BMT_CtrlCharge((kal_uint8)KAL_TRUE, BATPHYS.VBAT);
				bmt_timer_config(bmt_charging_para->BATFULL_TON_LI*CHARGING_TIME_UNIT);
#endif // #if defined(__DRV_BMT_ALWAYS_PULSE_CHARGING__) || defined(DRV_BMT_PULSE_CHARGING)
			}
			
#if defined(CHR_WITH_NI_MH_BATTERY)			
			if (BMT.BatType == NIBAT)
			{
				if ((BATPHYS.VBAT) < bmt_charging_para->V_FULL2FAST_THRES_NI)
				{
					BMT.bat_state = CHR_FAST;
					bmt_stop_stoptimer();
					drv_trace0(TRACE_GROUP_10, BMT_CHR_FAST_CHANGE_TRC);
				}
				BMT_CtrlCharge((kal_uint8)KAL_FALSE, BATPHYS.VBAT);
				bmt_timer_config(bmt_charging_para->BATFULL_TOFF_NI*CHARGING_TIME_UNIT);
			}
#endif // End of #if defined(CHR_WITH_NI_MH_BATTERY)
		}
		else
		{
			BMT_CtrlCharge((kal_uint8)KAL_FALSE, BATPHYS.VBAT);
			bmt_timer_config(1*CHARGING_TIME_UNIT);			
		}//if (BMT.bat_state != CHR_ERROR)
	}//if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
}

/*
* FUNCTION
*		BMT_CHRBATFULL_OFF
*
* DESCRIPTION																			  
*		This function is called when charger is off, and BMT charge module 
*	  is at CHR_BATFULL state.
*
* CALLS  
*
* PARAMETERS
*		None
*	
* RETURNS
*		None
*
*/
static void BMT_CHRBATFULL_OFF(void) 
{
	BATPHYStruct BATPHYS;
	drv_trace0(TRACE_GROUP_10, BMT_CHRBATFULL_OFF_STATE_TRC);
	
	if (BMT.highfull)
	{
		drv_trace0(TRACE_GROUP_10, BMT_HIGH_BAT_FULL_TRC);
		if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
		{
			BMT_PhyCheck(&BATPHYS);
			if((BMT.bat_state != CHR_ERROR)&&(BMT.bat_state != CHR_HOLD))
			{
				if (BMT.BatType == LIBAT)
				{
					if (BMT_CHR_Is_Under_ExtremeTmp(&BATPHYS) == KAL_TRUE)
					{
						if (BMT_CHR_Is_ExtremeTmp_Charge_Recharge(&BATPHYS) == KAL_TRUE)
						{
							BMT.bat_state = CHR_FAST;
							bmt_stop_stoptimer();
							drv_trace0(TRACE_GROUP_10, BMT_CHR_FAST_CHANGE_TRC);
							BMT.highfull = 0;
#ifndef __BMT_CHARGE_GUARD_TIME__
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
	    					bmt_safety_timer_config = KAL_FALSE;						
#else
							stack_start_timer(&ChargeTimeout_timer, 0, KAL_TICKS_1_MIN*BMT_TOTAL_CHARGE_TIME);
#endif
#endif
#if defined(DRV_BMT_PULSE_CHARGING)
							/* For pulse charging, if the charging complete message has been sent, 
							we have to restart guard time charger. */
							if (batfull_msg_flag == KAL_FALSE)
							{
#endif //#if defined(DRV_BMT_PULSE_CHARGING)
#ifdef __BMT_CHARGE_GUARD_TIME__
								bmt_set_guardtimer(KAL_TICKS_1_MIN*BMT_CHARGE_GUARD_TIME_PERIOD);
#endif // #ifdef __BMT_CHARGE_GUARD_TIME__
#if defined(DRV_BMT_PULSE_CHARGING)
							}//if (batfull_msg_flag == KAL_FALSE)
							batfull_msg_flag = KAL_FALSE;
#endif //#if defined(DRV_BMT_PULSE_CHARGING)
						}//if (BMT_CHR_Is_ExtremeTmp_Charge_Recharge(&BATPHYS) == KAL_TRUE)
					}//if (BMT_CHR_Is_Under_ExtremeTmp(&BATPHYS) == KAL_TRUE)
					else //if (BMT_CHR_Is_Under_ExtremeTmp(&BATPHYS) == KAL_TRUE)
					{
						if ((BATPHYS.VBAT) < bmt_charging_para->V_FULL2FAST_THRES)
						{
							BMT.bat_state = CHR_FAST;
							bmt_stop_stoptimer();
							drv_trace0(TRACE_GROUP_10, BMT_CHR_FAST_CHANGE_TRC);
							BMT.highfull = 0;
#ifdef __BMT_CHARGE_GUARD_TIME__
							bmt_set_guardtimer(KAL_TICKS_1_MIN*BMT_CHARGE_GUARD_TIME_PERIOD);
#else
							//if we have guard time, we don't need safty time
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
	    					bmt_safety_timer_config = KAL_FALSE;						
#else
							stack_start_timer(&ChargeTimeout_timer, 0, KAL_TICKS_1_MIN*BMT_TOTAL_CHARGE_TIME); 
#endif
#endif
#if defined(DRV_BMT_PULSE_CHARGING)
							batfull_msg_flag = KAL_FALSE;
#endif //#if defined(DRV_BMT_PULSE_CHARGING)
						}//if ((BATPHYS.VBAT) < bmt_charging_para->V_FULL2FAST_THRES)
					}//if (BMT_CHR_Is_Under_ExtremeTmp(&BATPHYS) == KAL_TRUE)
				}//if (BMT.BatType == LIBAT)
#if defined(CHR_WITH_NI_MH_BATTERY)
				if (BMT.BatType == NIBAT)
				{
					if (BMT_CHR_Is_Under_ExtremeTmp(&BATPHYS) == KAL_TRUE)
					{
						if (BMT_CHR_Is_ExtremeTmp_Charge_Recharge(&BATPHYS) == KAL_TRUE)
						{
							BMT.bat_state = CHR_FAST;
							bmt_stop_stoptimer();
							drv_trace0(TRACE_GROUP_10, BMT_CHR_FAST_CHANGE_TRC);
							BMT.highfull = 0;
#ifdef __BMT_CHARGE_GUARD_TIME__
							bmt_set_guardtimer(KAL_TICKS_1_MIN*BMT_CHARGE_GUARD_TIME_PERIOD);
#else
							//if we have guard time, we don't need safty time
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
	    					bmt_safety_timer_config = KAL_FALSE;						
#else
							stack_start_timer(&ChargeTimeout_timer, 0, KAL_TICKS_1_MIN*BMT_TOTAL_CHARGE_TIME);
#endif
#endif
						}
					}
					else
					{
						if ((BATPHYS.VBAT) < bmt_charging_para->V_FULL2FAST_THRES_NI)
						{
							BMT.bat_state = CHR_FAST;
							bmt_stop_stoptimer();
							drv_trace0(TRACE_GROUP_10, BMT_CHR_FAST_CHANGE_TRC);
							BMT.highfull = 0;
#ifdef __BMT_CHARGE_GUARD_TIME__
							bmt_set_guardtimer(KAL_TICKS_1_MIN*BMT_CHARGE_GUARD_TIME_PERIOD);
#endif
						}//if ((BATPHYS.VBAT) < bmt_charging_para->V_FULL2FAST_THRES_NI)
					}//if (BMT_CHR_Is_Under_ExtremeTmp(&BATPHYS) == KAL_TRUE)
				}//else if (BMT.BatType == NIBAT)
#endif // End of #if defined(CHR_WITH_NI_MH_BATTERY)
			} //if ((BMT.bat_state != CHR_ERROR)&&(BMT.bat_state != CHR_HOLD))
			BMT_CtrlCharge((kal_uint8)KAL_FALSE, BATPHYS.VBAT);
			bmt_timer_config(bmt_charging_para->BATFULL_TOFF*CHARGING_TIME_UNIT);
			return;
		}//if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
	}//if (BMT.highfull)
#if defined(__DRV_BMT_ALWAYS_PULSE_CHARGING__) 
	else if(BMT.BatType == LIBAT)
	{
		if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
		{
			BMT_PhyCheck(&BATPHYS);
			if ((BMT.bat_state != CHR_ERROR) 
				&& (BMT_CHR_Is_Under_ExtremeTmp(&BATPHYS) == KAL_TRUE)
				&& (BMT_CHR_Is_ExtremeTmp_Charge_Full(&BATPHYS) == KAL_TRUE))
			{
				return;
			}
			if ((BMT.bat_state != CHR_ERROR)&&(BMT.bat_state != CHR_HOLD))
			{
				BMT_CtrlCharge((kal_uint8)KAL_TRUE, BATPHYS.VBAT);
				bmt_timer_config(bmt_charging_para->BATFULL_TON_LI*CHARGING_TIME_UNIT);
			}
			else
			{
				BMT_CtrlCharge((kal_uint8)KAL_FALSE, BATPHYS.VBAT);
				bmt_timer_config(bmt_charging_para->BATFULL_TOFF_LI*CHARGING_TIME_UNIT);
			}
			return;
		}//if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
	}//else if(BMT.BatType == LIBAT)
#endif //#if defined(__DRV_BMT_ALWAYS_PULSE_CHARGING__)

#if defined(CHR_WITH_NI_MH_BATTERY)
	if (BMT.BatType == NIBAT)
	{
		if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
		{
			BMT_PhyCheck(&BATPHYS);
			if(BMT.bat_state != CHR_ERROR)
			{
				if ((BMT_CHR_Is_Under_ExtremeTmp(&BATPHYS) == KAL_TRUE) && (BMT_CHR_Is_ExtremeTmp_Charge_Full(&BATPHYS) == KAL_TRUE))
				{
					return;
				}
				if (BMT_CHR_Is_Under_ExtremeTmp(&BATPHYS) == KAL_TRUE)
				{
					if (BMT_CHR_Is_ExtremeTmp_Charge_Recharge(&BATPHYS) == KAL_TRUE)
					{
						//Guard timer should be alive and no need to stop it.
						BMT.bat_state = CHR_FAST;
						bmt_stop_stoptimer();
#ifndef __BMT_CHARGE_GUARD_TIME__
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
						bmt_safety_timer_config = KAL_FALSE;						
#else
						stack_start_timer(&ChargeTimeout_timer, 0, KAL_TICKS_1_MIN*BMT_TOTAL_CHARGE_TIME);
#endif
#endif
						drv_trace0(TRACE_GROUP_10, BMT_CHR_FAST_CHANGE_TRC);
					}
				}
				else
				{
					if ((BATPHYS.VBAT) < bmt_charging_para->V_FULL2FAST_THRES_NI)
					{
						BMT.bat_state = CHR_FAST;
						bmt_stop_stoptimer();
						drv_trace0(TRACE_GROUP_10, BMT_CHR_FAST_CHANGE_TRC);
					}
				}
			} //if (BMT.bat_state != CHR_ERROR)
		}//if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
		if(BMT.bat_state != CHR_ERROR)
		{
			BMT_CtrlCharge((kal_uint8)KAL_TRUE, BATPHYS.VBAT);
		}
		bmt_timer_config(bmt_charging_para->BATFULL_TON_NI*CHARGING_TIME_UNIT);
	}//if (BMT.BatType == NIBAT)
#endif // End of #if defined(CHR_WITH_NI_MH_BATTERY)
}

/*
* FUNCTION
*		BMT_CHARSTOP
*
* DESCRIPTION																			  
*		This function is called if charge is complete and run after 30 min
*
* CALLS  
*
* PARAMETERS
*		None
*	
* RETURNS
*		None
*
*/
void BMT_CHARSTOP(void)  /*30 min*/
{
	DCL_STATUS adc_status;
	drv_trace0(TRACE_GROUP_10, BMT_MEASURE_STOP_TRC);
	BMT_CtrlCharge((kal_uint8)KAL_FALSE, 4200000);	//Stop Charge!!
	BMT.highfull = 1;
#ifdef __BMT_CHARGE_GUARD_TIME__ 
	drv_trace1(TRACE_GROUP_10, BMT_CHARGE_GUARD_TIMER_EXPIRE_TRC, BMT_CHARGE_GUARD_TIME_PERIOD);
	/* Force into FULL state, so that we can monitor it to recharge again. */
	BMT.bat_state = CHR_BATFULL;
#endif // __BMT_CHARGE_GUARD_TIME__

    
	adc_status = DclSADC_Control(bmt_adc_handle, ADC_CMD_STOP_MEASURE, NULL);
	if(adc_status != STATUS_OK)
	{
		ASSERT(0);
	}

	bmt_timer_config(bmt_charging_para->BATFULL_TOFF*CHARGING_TIME_UNIT);
}

/*
* FUNCTION
*		BMT_CHRHOLD
*
* DESCRIPTION																			  
*		This function is called when BMT charge module 
*	  is at CHR_HOLD state.
*
* CALLS  
*
* PARAMETERS
*		None
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
static void BMT_CHRHOLD(void)
{
	BATPHYStruct BATPHYS;
	drv_trace0(TRACE_GROUP_10, BMT_CHRHOLD_STATE_TRC);
	if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
	{
		BMT_PhyCheck(&BATPHYS);
		if(((BATPHYS.VBAT) < bmt_charging_para->V_PROTECT_LOW_LI) || (BMT.call_state == 0))
		{
			BMT.bat_state = CHR_FAST;
			bmt_stop_stoptimer();
			drv_trace0(TRACE_GROUP_10, BMT_FAST_CHARGE_CHANGE_TRC);
		}
	}
	BMT_CtrlCharge((kal_uint8)KAL_FALSE, BATPHYS.VBAT);
	bmt_timer_config(bmt_charging_para->BATHOLD_OFF*CHARGING_TIME_UNIT);
}

/*
* FUNCTION
*	   BMT_CHRERRORCHECK
*
* DESCRIPTION                                                           
*   	This function is called when BMT charge module 
*     is at CHR_HOLD state.
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
#define VCHG_DIFF_THRESHOLD 300000 // 300mV
#if defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__) //only support if the platform can measurement current
static void BMT_CHRERRORCHECK(void)
{
   BATPHYStruct BATPHYS;
#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
   DCL_HANDLE bmt_dcl_handle;
   BMT_CTRL_SET_CHR_STATUS_T ChrStatus;
#endif
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
    static kal_uint32 pre_vchg_current = 0;
#if defined(__CHINA_CHARGER_STANDARD__)
    kal_uint32 cust_usb_charger_current;
#endif
#endif



   drv_trace0(TRACE_GROUP_10, BMT_ERROR_CHECK_TRC);
   if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is on
   {
#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
        if(SW_Workaround_Flag == KAL_TRUE) // VBAT < 3.4V
        {
            drv_trace0(TRACE_GROUP_10, BMT_SW_WORKAROUND_FLAG_TRUE_TRC);
            if(BATPHYS.VBAT > bmt_charging_para->V_PRE2FAST_THRES)
            {
                SW_Workaround_Flag = KAL_FALSE;
                drv_trace0(TRACE_GROUP_10, BMT_OUTSIDE_SW_WORKAROUND_RANGE_TRC);
                drv_trace0(TRACE_GROUP_10, BMT_SW_WORKAROUND_FLAG_FALSE_TRC);
                if(HW_Plug_Status == bmt_chr_out)
                {
                    drv_trace0(TRACE_GROUP_10, BMT_MISSING_HW_PLUG_OUT_TRC);
                    bmt_dcl_handle = DclBMT_Open(DCL_BMT, FLAGS_NONE);
                    ChrStatus.ChargerStat = DCL_BMT_CHR_OUT;
                    DclBMT_Control(bmt_dcl_handle, BMT_CMD_SET_CHR_STATUS, (DCL_CTRL_DATA_T *)&ChrStatus);
                    DclBMT_Close(bmt_dcl_handle);
                    return;
                }                
            }
            else
            {
                drv_trace0(TRACE_GROUP_10, BMT_INSIDE_SW_WORKAROUND_RANGE_TRC);
                SW_Workaround_Flag = KAL_TRUE;
				#if defined(__DRV_BMT_ISENSE_OFFSET_COMPENSATION__)
                if( BATPHYS.ICHARGE  < bmt_charging_para->ICHARGE_ON_LOW &&
				#else
                if( (BATPHYS.ICHARGE + bmt_charging_para->CurrOffset[BMT.call_state]) < bmt_charging_para->ICHARGE_ON_LOW &&
				#endif	
                (BATPHYS.VCHARGER < 2000000))
                {
                    SW_Workaround_Flag = KAL_FALSE;
                    drv_trace0(TRACE_GROUP_10, BMT_SW_WORKAROUND_FLAG_FALSE_TRC);    
                    drv_trace0(TRACE_GROUP_10, BMT_SW_PLUG_OUT_TRC);      
                    bmt_dcl_handle = DclBMT_Open(DCL_BMT, FLAGS_NONE);
                    ChrStatus.ChargerStat = DCL_BMT_CHR_OUT;
                    DclBMT_Control(bmt_dcl_handle, BMT_CMD_SET_CHR_STATUS, (DCL_CTRL_DATA_T *)&ChrStatus);
                    DclBMT_Close(bmt_dcl_handle);
                    return;
                }

		#if defined(__DRV_BMT_ISENSE_OFFSET_COMPENSATION__)
		if( (BMT.pmictrl_state == PMIC_CHARGEON)&&(BATPHYS.ICHARGE < bmt_charging_para->ICHARGE_ON_LOW))
		#else
		if( (BMT.pmictrl_state == PMIC_CHARGEON)&&((BATPHYS.ICHARGE + bmt_charging_para->CurrOffset[BMT.call_state]) < bmt_charging_para->ICHARGE_ON_LOW))
		#endif	
		{
			kal_uint8 threshold=7;

			if (threshold>bmt_get_on_count())
				threshold=bmt_get_on_count();
			
			SW_Low_Current_Cnts++;
			if (SW_Low_Current_Cnts>=threshold)
			{
			    SW_Workaround_Flag = KAL_FALSE;
			    drv_trace0(TRACE_GROUP_10, BMT_SW_WORKAROUND_FLAG_FALSE_TRC);    
			    drv_trace0(TRACE_GROUP_10, BMT_SW_PLUG_OUT_TRC);      
			    bmt_dcl_handle = DclBMT_Open(DCL_BMT, FLAGS_NONE);
			    ChrStatus.ChargerStat = DCL_BMT_CHR_OUT;
			    DclBMT_Control(bmt_dcl_handle, BMT_CMD_SET_CHR_STATUS, (DCL_CTRL_DATA_T *)&ChrStatus);
			    DclBMT_Close(bmt_dcl_handle);
			    return;
			}
		}
		else
		{		  
			SW_Low_Current_Cnts=0;
		}



                if(Manual_Disable_Charge_Flag == KAL_TRUE)
                {
                    drv_trace0(TRACE_GROUP_10, BMT_PLUG_OUT_FALSE_ALARM_TRC);   
                    Manual_Disable_Charge_Flag = KAL_FALSE;
                    if(BMT.pmictrl_state == PMIC_CHARGEON)
                    {
                        drv_trace0(TRACE_GROUP_10, BMT_ENABLE_CHARGE_AT_CHARGE_ON_TRC);   
                        BMT_Charge(KAL_TRUE); // Enable Charge for next time measure
                    }
                    bmt_timer_config(45); //45 frames ~= 200ms
                    return;
                }

				#if defined(__DRV_BMT_ISENSE_OFFSET_COMPENSATION__)
                if(BATPHYS.ICHARGE  < bmt_charging_para->ICHARGE_ON_LOW)
				#else
                if((BATPHYS.ICHARGE + bmt_charging_para->CurrOffset[BMT.call_state]) < bmt_charging_para->ICHARGE_ON_LOW)
				#endif	
                {
                    if(BMT.pmictrl_state == PMIC_CHARGEON)
                    {
                        drv_trace0(TRACE_GROUP_10, BMT_POSSIBLE_PLUG_OUT_TRC);
                        Manual_Disable_Charge_Flag = KAL_TRUE;
                        BMT_Charge(KAL_FALSE); // Disable Charge for next time measure
                        drv_trace0(TRACE_GROUP_10, BMT_DISABLE_CHARGE_AT_CHARGE_ON_TRC); 
                        bmt_timer_config(45); //45 frames ~= 200ms
                        return;
                    }
                    drv_trace0(TRACE_GROUP_10, BMT_LOW_CHARGE_CURRENT_AT_CHARGE_OFF_TRC); 
                }
            }
        }
        else if( (BATPHYS.VCHARGER > bmt_charging_para->VCHARGER_HIGH) ||
            ((BMT.pmictrl_state == PMIC_CHARGEON) &&
        #if defined(__DRV_BMT_ISENSE_OFFSET_COMPENSATION__)
            (BATPHYS.ICHARGE  < bmt_charging_para->ICHARGE_ON_LOW)))
		#else
            ((BATPHYS.ICHARGE + bmt_charging_para->CurrOffset[BMT.call_state]) < bmt_charging_para->ICHARGE_ON_LOW)))
        #endif    
#elif defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT) // Else of #if defined(DRV_BMT_HW_PRECC_WORKAROUND)
      VCharge_Total += BATPHYS.VCHARGER;
      drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_CUR_VCHG_MAX_TRC, Cur_VCharge_MAX);
      drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_VCHG_DIFF_TRC, BATPHYS.VCHARGER - Pre_VCharge_AVG);
      if(((BATPHYS.VCHARGER - Pre_VCharge_AVG) > VCHG_DIFF_THRESHOLD) && BATPHYS.VCHARGER > Cur_VCharge_MAX && 
        bmt_IsUSBorCharger() != BMT_USB_IN && BMT.bat_state != CHR_PRE)
      {                  
          pre_vchg_current = bmt_high_vchg_current;
          bmt_vchg_compare_and_set_current(BATPHYS.VCHARGER, KAL_FALSE);
#if defined(__CHINA_CHARGER_STANDARD__)

            if(chr_usb_detect.chr_usb_present == CHARGER_PRESENT_NON)
            {
                cust_usb_charger_current = PMU_CHARGE_CURRENT_450_00_MA;
                if(bmt_high_vchg_current > cust_usb_charger_current)
                {
                    bmt_high_vchg_current = cust_usb_charger_current;
                    drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_SET_USB_CHARGE_CURRENT_TRC, cust_usb_charger_current);
                }
            }
#endif // End of #if defined(__CHINA_CHARGER_STANDARD__)

          if(pre_vchg_current != bmt_high_vchg_current)
          {
		  bmt_find_and_set_the_nearest_current(bmt_high_vchg_current);          
          /*
		  PMU_CTRL_CHR_SET_CHR_CURRENT set_chr_current;
		  set_chr_current.current = bmt_high_vchg_current; 
                DclPMU_Control(bmt_PmuHandler, CHR_SET_CHR_CURRENT, (DCL_CTRL_DATA_T *)&set_chr_current);
          */
                BMT_CtrlUPMUCharge(KAL_FALSE);
                BMT_CtrlUPMUCharge(KAL_TRUE);
          }
          drv_trace1(TRACE_GROUP_9, BMT_VCHARGER_TRC, BATPHYS.VCHARGER);
          Cur_VCharge_MAX = BATPHYS.VCHARGER;
          drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_RUNTIME_APPLY_CHARGE_CURRENT_TRC, bmt_high_vchg_current);  
          drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_CUR_VCHG_MAX_TRC, Cur_VCharge_MAX);  
      }

      drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_TOTAL_VCHG_TRC, VCharge_Total);  
      bmt_high_vchg_set_safetytimer(BATPHYS.VCHARGER);  
	  if ( (BATPHYS.VCHARGER > bmt_high_vchg_para->HIGH_VCHG_TABLE[VCHG_VOL_LEVEL - 1][0]) ||
      	  ((BMT.pmictrl_state == PMIC_CHARGEON) && 
      #if defined(__DRV_BMT_ISENSE_OFFSET_COMPENSATION__)
      	   (BATPHYS.ICHARGE  < bmt_charging_para->ICHARGE_ON_LOW)) )	  	
	  #else
      	   ((BATPHYS.ICHARGE + bmt_charging_para->CurrOffset[BMT.call_state]) < bmt_charging_para->ICHARGE_ON_LOW)) )	  	
      #endif	   
#else // Else of #if defined(DRV_BMT_HW_PRECC_WORKAROUND)
        if( (BATPHYS.VCHARGER > bmt_charging_para->VCHARGER_HIGH) ||
            ((BMT.pmictrl_state == PMIC_CHARGEON) && 
      #if defined(__DRV_BMT_ISENSE_OFFSET_COMPENSATION__)
            (BATPHYS.ICHARGE  < bmt_charging_para->ICHARGE_ON_LOW)) )
	  #else
            ((BATPHYS.ICHARGE + bmt_charging_para->CurrOffset[BMT.call_state]) < bmt_charging_para->ICHARGE_ON_LOW)) )
      #endif      
#endif // End of #if defined(DRV_BMT_HW_PRECC_WORKAROUND) 
        {
            bmt_chr_force_enable(KAL_FALSE);
            BMT_CtrlCharge((kal_uint8)KAL_FALSE, BATPHYS.VBAT); //clear the SW global variable
            kal_sleep_task(20); //delay 20 frames for HW issue plug-out interrupt
            bmt_chr_force_enable(KAL_TRUE);
            BMT_CtrlCharge((kal_uint8)KAL_TRUE, BATPHYS.VBAT);
        }
    }
    bmt_timer_config(45); //45 frames ~= 200ms
}
#endif //#if defined(__DRV_BMT_ULTRA_LOW_COST_CHARGER__)

/*
* FUNCTION
*		BMT_MeasureStop
*
* DESCRIPTION																			  
*		This function is used to stop the charge measure, and restart normal measure.
*	  Besides, this function is called when BMT charge module 
*	  is at CHR_ERROR state.
*
* CALLS  
*
* PARAMETERS
*		None
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
void BMT_MeasureStop(void)
{
	drv_trace0(TRACE_GROUP_10, BMT_MEASURE_STOP_TRC);
#if defined(CHR_WITH_NI_MH_BATTERY) 
	VBATtmp = 0;
#endif
	BMT.pmictrl_state = PMIC_CHARGEOFF;
	bmt_charge_end();
}

/*
* FUNCTION
*	   BMT_VBatVoltageIsFull
*
* DESCRIPTION                                                           
*   	This function is used to check the Battery voltage full or not.
*
* CALLS  
*
* PARAMETERS
*	   voltage: for compare with full threshold
*	
* RETURNS
*	   KAL_FALSE: still not full
*	   KAL_TRUE:  already full
*
* GLOBALS AFFECTED
*     None
*/
kal_bool BMT_VBatVoltageIsFull(kal_uint32 voltage)
{	
	#if defined(__GENERAL_EXTERNAL_CHARGER__)
	return ext_charger->get_vbat_specific_full_voltage_state(voltage);
	#else
	return KAL_FALSE;
	#endif
}

#if defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__)
void BMT_CHRPRE_FULLCHECK(void)
{
   if (g_battery_pre_voltage != 0)  //It means that the voltage measurement tiggered in CHRDET_HISR is done.
   {
      kal_bool pre_full;

      VBAT_OFF = g_battery_pre_voltage;

      pre_full = BMT_VBatVoltageIsFull(g_battery_pre_voltage);
      if (KAL_TRUE == pre_full)
      {
		   BATFULL_index = 0;
		   BMT.bat_state = CHR_BATFULL;
		   bmt_stop_stoptimer();
		   stack_stop_timer(&ChargeTimeout_timer);
		   drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, BMT_TOTAL_CHARGE_TIME);
		   /*30min*/
		   bmt_set_stoptimer(STOPTIMER_TIMEOUT_TICK);
		   BMT_sendMes2UEM(BMT_CHARGE_COMPLETE);
		   drv_trace0(TRACE_GROUP_10, BMT_CHR_BATFULL_CHANGE_TRC);
		   BMT_CtrlCharge((kal_uint8)KAL_TRUE, g_battery_pre_voltage);
      }
      else
      {
         BMT.bat_state = CHR_PRE; //Begin charging from pre-charge state
      }
      g_battery_pre_voltage = 1; //change it to a none-zero small value because it only needs to check once after cable plug-in
   }
   bmt_timer_config(5);
}

void BMT_VbatInHISR_Init(void)
{
   DCL_HANDLE adc_handle;
   ADC_CTRL_CREATE_OBJECT_T adc_create;
   ADC_CTRL_GET_PHYSICAL_CHANNEL_T adc_ch;
   DCL_STATUS adc_status;

   adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
   if(adc_handle == DCL_HANDLE_INVALID)
   {
       ASSERT(0);   
   }
   adc_ch.u2AdcName = DCL_VBAT_ADC_CHANNEL;
   DclSADC_Control(adc_handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);

   bmt_vbat_in_hisr_gpt_handle = DclSGPT_Open(DCL_GPT_CB, 0);
   adc_create.u4Period = 10; // Measurement period (Uint is in Tick)
   adc_create.u1OwnerId = MOD_BMT; // Indicate the module to for ADC driver to notify the result
   adc_create.u1AdcChannel = adc_ch.u1AdcPhyCh; // To be measured physical ADC channel
   adc_create.u1EvaluateCount = 3; // Measurement count
   adc_create.fgSendPrimitive = KAL_FALSE; // Whether to send message to owner module or NOT
   adc_status = DclSADC_Control(adc_handle, ADC_CMD_CREATE_OBJECT, (DCL_CTRL_DATA_T *)&adc_create);
   if(adc_status != STATUS_OK)
   {
		ASSERT(0);   
   }
   bmt_vbat_in_hisr_id = adc_handle;
   DclSADC_Close(adc_handle);
}

static void check_vbat_full_at_fist(kal_int32 handle, kal_int32 volt_result, double adc_result)
{
	DCL_STATUS adc_status;
	adc_status = DclSADC_Control(bmt_vbat_in_hisr_id, ADC_CMD_STOP_MEASURE, NULL);
	if(adc_status != STATUS_OK)
	{
		ASSERT(0);
	}

	g_battery_pre_voltage = volt_result;
	VBAT_OFF = g_battery_pre_voltage;
}

static void bmt_bvat_in_hisr_adc_measurement_cb(void *parameter)
{
  DCL_STATUS adc_status;
  SGPT_CTRL_START_T start;  
  ADC_CTRL_REGISTER_COMPLETE_CB_T registerCB;

  if(KAL_TRUE == bmt_check_if_bat_on())
  {
  	if(bmt_event_sche_active == 1)
     {
        start.u2Tick=1;
        start.pfCallback=bmt_bvat_in_hisr_adc_measurement_cb;
        start.vPara=NULL;
         
        DclSGPT_Control(bmt_vbat_in_hisr_gpt_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
  		return;
  	}
     else
     {
		DclSGPT_Control(bmt_vbat_in_hisr_gpt_handle,SGPT_CMD_STOP,0);
  		DclSGPT_Close(&bmt_vbat_in_hisr_gpt_handle);
  		bmt_vbat_in_hisr_gpt_handle = 0xFF;
		registerCB.pfComplete_cb = (PFN_DCLSADC_COMPLETE_CALLBACK)check_vbat_full_at_fist;
		adc_status = DclSADC_Control(bmt_vbat_in_hisr_id, ADC_CMD_REGISTER_COMPLETE_CB, (DCL_CTRL_DATA_T *)&registerCB);
		if(adc_status != STATUS_OK)
		{
			ASSERT(0);  		
		}
		adc_status = DclSADC_Control(bmt_vbat_in_hisr_id, ADC_CMD_START_MEASURE, NULL);
		if(adc_status != STATUS_OK)
		{
			ASSERT(0);  		
		}
  	}
  }
}


/*
* FUNCTION
*	   BMT_VbatInHISR
*
* DESCRIPTION                                                           
*   	This function is used to save the Battery voltage in HISR
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
void BMT_VbatInHISR(void)
{
  DCL_STATUS adc_status;
  ADC_CTRL_REGISTER_COMPLETE_CB_T registerCB;	
  SGPT_CTRL_START_T start;

  if(KAL_TRUE == bmt_check_if_bat_on())
  {
    g_battery_pre_voltage = 0;
  	if (bmt_event_sche_active == 1)
     {
        if (0xFF == bmt_vbat_in_hisr_gpt_handle)
        {
			bmt_vbat_in_hisr_gpt_handle = DclSGPT_Open(DCL_GPT_CB, 0);
        }

	    start.u2Tick=1;
	    start.pfCallback=bmt_bvat_in_hisr_adc_measurement_cb;
	    start.vPara=NULL;

	    DclSGPT_Control(bmt_vbat_in_hisr_gpt_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);

  	}
    else
    {
  		// bmt task is NOT setting event scheduler, we can set directly
		registerCB.pfComplete_cb = (PFN_DCLSADC_COMPLETE_CALLBACK)check_vbat_full_at_fist;
		adc_status = DclSADC_Control(bmt_vbat_in_hisr_id, ADC_CMD_REGISTER_COMPLETE_CB, (DCL_CTRL_DATA_T *)&registerCB);
		if(adc_status != STATUS_OK)
		{
			ASSERT(0);  		
		}
		adc_status = DclSADC_Control(bmt_vbat_in_hisr_id, ADC_CMD_START_MEASURE, NULL);
		
		if(adc_status != STATUS_OK)
		{
			ASSERT(0);  		
		}
  	}
  }//if(KAL_TRUE == bmt_check_if_bat_on())
}

#endif //#if defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__)

#if defined(DRV_BMT_PULSE_CHARGING)
void BMT_CHRPRE_TO_CHRBATFULL(void)
{
#if defined(MT6236)  

    PMU_CTRL_CHR_SET_CV_DETECTION_VOLTAGE chr;
#endif

    BMT.bat_state = CHR_BATFULL;
    stack_stop_timer(&ChargeTimeout_timer);
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
	drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, bmt_total_charge_time);
#else
    drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, BMT_TOTAL_CHARGE_TIME);
#endif 
#if defined(MT6236)        

#if defined(PMIC_6236_CV_TRIM_CALIBRATION)

    chr.voltage = (PMU_VOLTAGE_ENUM)(PMU_VOLT_04_000000_V + mt6236_efuse_vbat_cv * 12500);
#else
    chr.voltage = PMU_VOLT_04_000000_V + CHR_VBAT_CV_4_2000V * 12500;
#endif
    DclPMU_Control(bmt_PmuHandler, CHR_SET_CV_DETECTION_VOLTAGE, (DCL_CTRL_DATA_T *)&chr);
          
#endif    
    drv_trace0(TRACE_GROUP_10, BMT_CHR_BATFULL_CHANGE_TRC);
    BMT.highfull = 1;
    batfull_msg_flag = KAL_TRUE;
    BMT_sendMes2UEM(BMT_CHARGE_COMPLETE);
    bmt_timer_config(bmt_charging_para->PRE_TON*CHARGING_TIME_UNIT);
}
/*
* FUNCTION
*		BMT_CHRPRE_TO_CHRBATFULL_CHECK
*
* DESCRIPTION																			  
*		This function is used to check if current battery voltage is larger than VBAT_CV
*	    Level - 2. We will transite to CHRBATFULL state.
*
* CALLS  
*
* PARAMETERS
*		None
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
kal_bool BMT_CHRPRE_TO_CHRBATFULL_CHECK(void)
{
#if defined(MT6236)
	DCL_HANDLE pmu_handle;
    PMU_CTRL_CHR_SET_CV_DETECTION_VOLTAGE chr;
#else    
    BATPHYStruct BATPHYS;
#endif
   
	if(bmt_get_chr_cv_det()) // For Custom check CV function
	{
        BMT_CHRPRE_TO_CHRBATFULL();
		return KAL_TRUE;				
	}
   
#if defined(MT6236)   
#if defined(PMIC_6236_CV_TRIM_CALIBRATION)   
    if(mt6236_efuse_vbat_cv >= 2)
    {
        
        chr.voltage = (PMU_VOLTAGE_ENUM)(PMU_VOLT_04_000000_V + (mt6236_efuse_vbat_cv - 2) * 12500);
        DclPMU_Control(bmt_PmuHandler, CHR_SET_CV_DETECTION_VOLTAGE, (DCL_CTRL_DATA_T *)&chr);
        
    }
#else // #if defined(PMIC_6236_CV_TRIM_CALIBRATION)
    
    chr.voltage = PMU_VOLT_04_000000_V + (CHR_VBAT_CV_4_1750V) * 12500;
    DclPMU_Control(bmt_PmuHandler, CHR_SET_CV_DETECTION_VOLTAGE, (DCL_CTRL_DATA_T *)&chr);
       
#endif // #if defined(PMIC_6236_CV_TRIM_CALIBRATION)

	if(bmt_get_chr_cv_det()) // For 4.175V CV Check
	{
        BMT_CHRPRE_TO_CHRBATFULL();
		return KAL_TRUE;				
	}
    else
	{
        
#if defined(PMIC_6236_CV_TRIM_CALIBRATION)
        chr.voltage = (PMU_VOLTAGE_ENUM)(PMU_VOLT_04_000000_V + mt6236_efuse_vbat_cv * 12500);
#else
        chr.voltage = PMU_VOLT_04_000000_V + CHR_VBAT_CV_4_2000V * 12500;
#endif
        DclPMU_Control(bmt_PmuHandler, CHR_SET_CV_DETECTION_VOLTAGE, (DCL_CTRL_DATA_T *)&chr);
                   
        return KAL_FALSE;
	}
#else // #if defined(MT6236)

	if (BMT_ObtainBMTPHYSTAT(&BATPHYS)) //The measure is off period
	{
		BMT_PhyCheck(&BATPHYS);
        if(BATPHYS.VBAT > 4175000)
        {
            BMT_CHRPRE_TO_CHRBATFULL();
		return KAL_TRUE;				
	}
        else
        {
    return KAL_FALSE;
}
	}
    else
    {
    return KAL_FALSE;
}
#endif // #if defined(MT6236)
}
#endif //#if defined(DRV_BMT_PULSE_CHARGING)
