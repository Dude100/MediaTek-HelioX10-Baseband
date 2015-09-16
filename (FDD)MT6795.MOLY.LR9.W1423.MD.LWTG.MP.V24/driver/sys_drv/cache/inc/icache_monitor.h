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
 *   bus_monitor.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file for BUS monitor control.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * Please note that this file will be remove in custom release!!
 * Use it for debugging only.
 *
 * Example to use bus monitor:
 *
 * #include "ahb_monitor.h"
 *
 * int foo()
 * {
 *     CM_LOG_T log;
 *
 *     // Start logging.
 *     CM_BEGIN_LOG();
 *
 *     // SW to be measured
 *
 *     // Stop logging
 *     CM_END_LOG();
 *
 *     // retrieve log
 *     CM_GET_LOG(&log);
 *
 *     // clear log
 *     CM_CLR_LOG();
 *
 *     // print log
 *     printf("hit0_cntl = %d\n", log.hit0_cntl);
 * }
 */

#if !defined(__CACHE_MONITOR_H__)
#define __CACHE_MONITOR_H__

//MSBB remove #include "kal_non_specific_general_types.h"

/*******************************************************************************
 * Define Chip-dependet settings.
 *******************************************************************************/

#if defined(MT6253T) || defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
#define __CACHE_MONITOR_SUPPORT__
#define CACHE_MON_base 0x85000000
#endif  /* MT6253T || MT6253 || MT6251 */


/*******************************************************************************
 * Define HW register.
 *******************************************************************************/

#define CACHE_MON_CON (volatile kal_uint16 *)(CACHE_MON_base + 0x0000)
#define CACHE_MON_HCNT0L (volatile kal_uint32 *)(CACHE_MON_base + 0x0008)
#define CACHE_MON_HCNT0U (volatile kal_uint32 *)(CACHE_MON_base + 0x000C)
#define CACHE_MON_CCNT0L (volatile kal_uint32 *)(CACHE_MON_base + 0x0010)
#define CACHE_MON_CCNT0U (volatile kal_uint32 *)(CACHE_MON_base + 0x0014)
#define CACHE_MON_HCNT1L (volatile kal_uint32 *)(CACHE_MON_base + 0x0018)
#define CACHE_MON_HCNT1U (volatile kal_uint32 *)(CACHE_MON_base + 0x001C)
#define CACHE_MON_CCNT1L (volatile kal_uint32 *)(CACHE_MON_base + 0x0020)
#define CACHE_MON_CCNT1U (volatile kal_uint32 *)(CACHE_MON_base + 0x0024)


/*******************************************************************************
 * Define constants.
 *******************************************************************************/

enum { 
    CACHE_MON_EN = 0x000C
};


/*******************************************************************************
 * Define data structures.
 *******************************************************************************/

typedef struct CM_LOG_STRUCT
{
    kal_uint32 hit0_cntl;          /* hit counter 0, lower part. */
    kal_uint32 hit0_cntu;         /* hit counter 0, upper part. */
    kal_uint32 access0_cntl;    /* access counter 0, lower part. */
    kal_uint32 access0_cntu;   /* access counter 0, upper part. */
    kal_uint32 hit1_cntl;          /* hit counter 1, lower part. */
    kal_uint32 hit1_cntu;         /* hit counter 1, upper part. */
    kal_uint32 access1_cntl;    /* access counter 1, lower part. */
    kal_uint32 access1_cntu;   /* access counter 1, upper part. */
} CM_LOG_T;


/*******************************************************************************
 * Define macros.
 *******************************************************************************/

#if defined(__CACHE_MONITOR_SUPPORT__)

#define CM_BEGIN_LOG()  \
        do {    \
            *CACHE_MON_HCNT0L = 0;  \
            *CACHE_MON_HCNT0U = 0; \
            *CACHE_MON_CCNT0L = 0; \
            *CACHE_MON_CCNT0U = 0; \
            *CACHE_MON_HCNT1L = 0;  \
            *CACHE_MON_HCNT1U = 0; \
            *CACHE_MON_CCNT1L = 0; \
            *CACHE_MON_CCNT1U = 0; \
            *CACHE_MON_CON |= CACHE_MON_EN;   \
        } while (0)

#define CM_END_LOG()    \
        do {    \
            *CACHE_MON_CON &= (~CACHE_MON_EN);   \
        } while (0)

#define CM_GET_LOG(l) \
        do {    \
            (l)->hit0_cntl = *CACHE_MON_HCNT0L;  \
            (l)->hit0_cntu = *CACHE_MON_HCNT0U; \
            (l)->access0_cntl = *CACHE_MON_CCNT0L; \
            (l)->access0_cntu = *CACHE_MON_CCNT0U; \
            (l)->hit1_cntl = *CACHE_MON_HCNT1L;  \
            (l)->hit1_cntu = *CACHE_MON_HCNT1U; \
            (l)->access1_cntl = *CACHE_MON_CCNT1L; \
            (l)->access1_cntu = *CACHE_MON_CCNT1U; \
        } while (0)

#define CM_START_LOG()  \
        do {    \
            *CACHE_MON_CON |= CACHE_MON_EN;   \
        } while (0)	

#define CM_CLEAR_LOG() \
        do {    \
            *CACHE_MON_HCNT0L = 0;  \
            *CACHE_MON_HCNT0U = 0; \
            *CACHE_MON_CCNT0L = 0; \
            *CACHE_MON_CCNT0U = 0; \
            *CACHE_MON_HCNT1L = 0;  \
            *CACHE_MON_HCNT1U = 0; \
            *CACHE_MON_CCNT1L = 0; \
            *CACHE_MON_CCNT1U = 0; \
        } while (0)

#else   /* __CACHE_MONITOR_SUPPORT__ */

#define CM_BEGIN_LOG()
#define CM_END_LOG()
#define CM_GET_LOG(l)
#define CM_START_LOG()  
#define CM_CLEAR_LOG()


#endif  /* __CACHE_MONITOR_SUPPORT__ */

#endif  /* !__CACHE_MONITOR_SUPPORT__ */

