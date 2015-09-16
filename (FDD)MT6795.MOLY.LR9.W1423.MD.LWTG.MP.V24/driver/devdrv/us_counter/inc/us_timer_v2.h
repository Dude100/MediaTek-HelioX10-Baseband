/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   us_timer.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file for providing timer of microsecond precision.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if !defined(__US_TIMER_H__)
#define __US_TIMER_H__

#if defined(MT9999) /* All Chips in MOLY support US Timer*/
#else
#define __HW_US_TIMER_SUPPORT__
#endif

#include "reg_base.h"
#include "cpu.h"
#include "drv_comm.h"

//For L1 simulation
#include "l1_interface.h"

/*******************************************************************************
 * Define registers.
 *******************************************************************************/
#if defined(MT6290)||defined(MT6595)||defined(MT6752)

#if KAL_MICROSECS_PER_TICK==4615  /* (12/13)*5000us */
    #define USCNT_TO_FRAME(sus) (((sus)*58161)>>28) /* Error rate: 0.0000266% */
#elif KAL_MICROSECS_PER_TICK==5000
    #define USCNT_TO_FRAME(sus) (((sus)*53687)>>28) /* Error rate: 0.0001700% */
#else  /* KAL_MICROSECS_PER_TICK== */
    #error "Un-Support Frame Period"
#endif /* KAL_MICROSECS_PER_TICK== */

#define USCNT_TO_QBIT(us)  (((us)*1109)>>10)  /*Error rate: 1 qbit error per 3000 qbits, allowd max log duration: 4s */
#define USCNT_WRAP         0xFFFFFFFF

#ifdef ESIM_BUILD_CONFIG
    #define USCNT_START_CODE   0x62900001
    #define USCNT_STOP_CODE    0x62900000

    #define USCNT_CON          (volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0x0080)
    #define F32K_FM            (volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0x84)
    #define USCNTI_VAL         (volatile kal_uint32 *)(BASE_MADDR_MDTOPSM+0x0088)
#else /* ESIM_BUILD_CONFIG */
    #define USCNT_CON          (volatile kal_uint32 *)(BASE_ADDR_MDTOPSM+0x0080)
    #define F32K_FM            (volatile kal_uint32 *)(BASE_ADDR_MDTOPSM+0x84)
    #define USCNTI_VAL         (volatile kal_uint32 *)(BASE_ADDR_MDTOPSM+0x0088)
#endif /* ESIM_BUILD_CONFIG */

#define USCNT_FREQ         1000000

#endif /* MTxxxx chip defined */

#define US_TD_Timer        (volatile kal_uint16 *)(TDMA_base + 0x00)
#define US_TD_Wrape        (volatile kal_uint16 *)(TDMA_base + 0x04)


/*******************************************************************************
 * Define macros.
 *******************************************************************************/
#if defined(__HW_US_TIMER_SUPPORT__)
    extern void USC_Start( void );
    extern void USC_Stop( void );
    extern void USC_Cal_32KFM( kal_uint32 Cal_32K, kal_uint32 Cal_26M);
    extern kal_uint32 USC_Get_TimeStamp( void );
//    extern kal_uint32 USC_Get_TimeStamp_CNT( void);
    #if defined(__UE_SIMULATOR__) || defined(ESIM_BUILD_CONFIG)
        #define ust_get_current_time()        HW_READ(USCNTI_VAL)
        #define ust_get_current_time_source() HW_READ(USCNTI_VAL)
    #else
        #if defined(MT6290)
            extern volatile kal_uint32 ostd_patch_us_timer_period;
            #if defined(__FAST_FRC__)
                #define ust_get_current_time()   (DRV_Reg32(BASE_ADDR_ALC+0xF4) + ostd_patch_us_timer_period)
            #else
                #define ust_get_current_time()   (DRV_Reg32(BASE_ADDR_MDTOPSM+0x88) + ostd_patch_us_timer_period)
            #endif
        #else /* MT6290 */
            #if defined(__FAST_FRC__)
                #define ust_get_current_time()   DRV_Reg32(BASE_ADDR_ALC+0xF4)
            #else
                #define ust_get_current_time()   DRV_Reg32(BASE_ADDR_MDTOPSM+0x88)
            #endif
        #endif /* MT6290 */
        #define ust_get_current_time_source()   DRV_Reg32(BASE_ADDR_MDTOPSM+0x88)
    #endif

    /* Get duration, unit = Qbit */
    #define ust_get_duration(prev, cur)  USCNT_TO_QBIT((((cur) >= (prev))? (((cur) - (prev))): ((USCNT_WRAP - (prev) + (cur) + 1))))

    /* Get duration, unit = us */
    #define ust_us_duration(start, end)   (((end) >= (start))? (((end) - (start))): ((USCNT_WRAP - (start) + (end) + 1)))

#else   /* __HW_US_TIMER_SUPPORT__ */
#error "MOLY chips always support the HW US Timer"

#endif  /* __HW_US_TIMER_SUPPORT__ */

/**
 * ust_busy_wait - a busy loop wait for a period
 * @us: qbit to wait
 *
 * This macro contains a busy loop to wait a period of specified microsends.
 * There is a maximal iteration count in the busy loop to prevent from infinite loop. 
 * (EX: timer is not working.)
 * ==> Update the design, if the ust does not work, CPU blocking at this macro.
 *     Because it's hard to find the delay loop issue when FRC is stop.
 */
#define ust_busy_wait(qbit)                                   \
do {                                                          \
    kal_uint32 t1, t2, zerocount = 0xFFFFF;                   \
    if ((us) == 0) {break;}                                   \
    t1 = ust_get_current_time();                              \
    do {                                                      \
        t2 = ust_get_current_time();                          \
        if (t1 == t2) { zerocount--; }                        \
        else if (ust_get_duration(t1, t2) >= (us)) { break; } \
    } while (zerocount);                                      \
    if(0==zerocount)                                          \
    {                                                         \
        kal_uint32 FRC_IS_NOT_INIT = 0;                       \
        ASSERT(FRC_IS_NOT_INIT);                              \
    }                                                         \
} while (0)

#define ust_us_busyloop(us)                                   \
do {                                                          \
    kal_uint32 t1, t2, zerocount = 0xFFFFF;                   \
    if ((us) == 0) {break;}                                   \
    t1 = ust_get_current_time();                              \
    do {                                                      \
        t2 = ust_get_current_time();                          \
        if (t1 == t2) { zerocount--; }                        \
        else if (ust_us_duration(t1, t2) >= (us)) { break; } \
    } while (zerocount);                                      \
    if(0==zerocount)                                          \
    {                                                         \
        kal_uint32 FRC_IS_NOT_INIT = 0;                       \
        ASSERT(FRC_IS_NOT_INIT);                              \
    }                                                         \
} while (0)


#endif  /* !__US_TIMER_H__ */

