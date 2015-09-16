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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if !defined(__US_TIMER_H__)
#define __US_TIMER_H__

#if defined(MT6268) || defined(MT6270A) || defined(MT6276) || defined(MT6573) || defined(MT6575) || defined(TK6280) || defined(MT6577) || defined(MT6280) || defined (MT6752)
#define __HW_US_TIMER_SUPPORT__
#endif

#include "reg_base.h"
//For L1 simulation
#include "l1_interface.h"
#include "drv_comm.h"

#if !defined(HW_READ)
#if defined(L1_SIM) 
#include "tool.h" 
#else 
#define  HW_WRITE(ptr,data)         (*(ptr) = (data)) 
#define  HW_READ(ptr)               (*(ptr)) 
#endif
#endif //#if !defined(HW_READ)


/*******************************************************************************
 * Define registers.
 *******************************************************************************/
#if defined(MT6268)
#define __ALIGN_2G_CLOCK__
#define USCNT_CON          (volatile kal_uint16 *)(CONFIG_base+0x5000)
#define F32K_FM            (volatile kal_uint32 *)(CONFIG_base+0x5004)
#define USCNTI_VAL         (volatile kal_uint32 *)(CONFIG_base+0x5008)
#define USCNTF_VAL         (volatile kal_uint32 *)(CONFIG_base+0x500C)
#define USCNT_FREQ         3250000	//usc freq. = 3.25MHz
#define USCNT_TO_FRAME(us) ((us)/15000)		// 
											//				120 ms
											//	1 frame = ----------- = 4615.xxx us
											//				26 frame
											// 
											//	usc freq =  3.25MHz 
											//
											//				 3.25M * 120ms
											//	=> 1 frame = ----------- = 15000 usc ticks (no error)
											//					26frame
#define FRAME_TO_USCNT(fr) ((fr)*15000)
#define USCNT_TO_QBIT(us)  ((us)/3)       	/*Error rate: 0, allowd max log duration: 89s (due to 27bit) */
											// qbit := quadrant bit = 1/4 bit
                                            // GSM bitrate: 32500bit/26frame := 32500bit/120ms
											//			   120ms
											// 	1qbit = -------------= 0.923 us
											//			  32500bit/s * 4
											//
											// 	      = 3.25Mhz * 120ms/(32500*4) = 3 usc ticks (no error)

#define USCNT_WRAP         0x0FFFFFFF
#define USCNT_START_CODE   0x6269
#define USCNT_STOP_CODE    0x6268
#elif defined(MT6270A) || defined(MT6276) || defined(MT6573) || defined(MT6575) || defined(TK6280) || defined(MT6577) || defined (MT6280) || defined(MT6752)
#define USCNT_CON          (volatile kal_uint32 *)(TOPSM_base+0x0080)
#define F32K_FM            (volatile kal_uint32 *)(TOPSM_base+0x0084)
#define USCNTI_VAL         (volatile kal_uint32 *)(TOPSM_base+0x0088)
#define USCNT_FREQ         1000000	//1MHz

// Frame duration may change to be 5 ms
#if KAL_MICROSECS_PER_TICK==4615  /* (12/13)*5000us */
    #define USCNT_TO_FRAME(sus) (((sus)*58161)>>28) /* Error rate: 0.0000266% */
#elif KAL_MICROSECS_PER_TICK==5000
    #define USCNT_TO_FRAME(sus) (((sus)*53687)>>28) /* Error rate: 0.0001700% */
#else  /* KAL_MICROSECS_PER_TICK== */
    #error "Un-Support Frame Period"
#endif /* KAL_MICROSECS_PER_TICK== */

///AST: maybe overflow in (sus > 73846) 
//#define USCNT_TO_FRAME(sus) (((sus)*58161)>>28) 	/* Error rate: 0.0000266% */	
													//			2^28
													//	usc	=   ------- = 4615.xx us
													//			58161
													
#define USCNT_TO_QBIT(us)  (((us)*1109)>>10)  		/*Error rate: 1 qbit error per 3000 qbits, allowd max log duration: 4s */
													//			2^10
													//	usc	=	------- = 0.923 us
													//			1109
#define USCNT_WRAP         0xFFFFFFFF

#if defined(MT6270A) || defined(MT6276) || defined(TK6280)
#define USCNT_START_CODE   0x62760001
#define USCNT_STOP_CODE    0x62760000
#elif defined(MT6573)
#define USCNT_START_CODE   0x65730001
#define USCNT_STOP_CODE    0x65730000
#elif defined(MT6575) || defined(MT6577)
#define USCNT_START_CODE   0x65750001
#define USCNT_STOP_CODE    0x65750000
#else //afterward, (0x1153<<16) is the default key, instead of chip-specified key.
#define USCNT_START_CODE   ((0x1153<<16) | 0x01)
#define USCNT_STOP_CODE    (0x1153<<16)
#endif

#endif

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
extern kal_uint32 USC_Get_TimeStamp_CNT( void);
//AB: software workaround for us counter hw issue during waking up
#if defined(MT6268_S00)
extern unsigned int USC_Get_Int(void);
#define ust_get_current_time() USC_Get_Int()
#else
#define ust_get_current_time() HW_READ(USCNTI_VAL)
#endif

//rcc: output qbits
#define ust_get_duration(prev, cur)  USCNT_TO_QBIT((((cur) >= (prev))? (((cur) - (prev))): ((USCNT_WRAP - (prev) + (cur)))))
#define ust_us_duration(start, end)   (((end) >= (start))? (((end) - (start))): ((USCNT_WRAP - (start) + (end) + 1)))

#else   /* __HW_US_TIMER_SUPPORT__ */

/*
 * There is no HW support.
 * Use TDMA TQCNT to approximate it.
 */
#define ust_get_current_time() HW_READ(US_TD_Timer)

//rcc: output qbits
#define ust_get_duration(prev, cur) (((cur) >= (prev))? ((cur) - (prev)): ((HW_READ(US_TD_Wrape)) - (prev) + (cur)))

#endif  /* __HW_US_TIMER_SUPPORT__ */

/**
 * ust_busy_wait - a busy loop wait for a period
 * @us: microseconds to wait
 *
 * This macro contains a busy loop to wait a period of specified microsends.
 * There is a maximal iteration count in the busy loop to prevent from infinite loop. 
 * (EX: timer is not working.)
 */
#define ust_busy_wait(us)   \
        do {    \
            kal_uint32 t1, t2, zerocount = 0xffff;\
            if ((us) == 0) {    \
                break;  \
            }   \
            t1 = ust_get_current_time();    \
            do {    \
                t2 = ust_get_current_time();    \
                if (t1 == t2) { zerocount--; }  \
                else if (ust_get_duration(t1, t2) >= (us)) { break; } \
	       	else { continue; }   \
            } while (zerocount);    \
        } while (0)


#endif  /* !__US_TIMER_H__ */

