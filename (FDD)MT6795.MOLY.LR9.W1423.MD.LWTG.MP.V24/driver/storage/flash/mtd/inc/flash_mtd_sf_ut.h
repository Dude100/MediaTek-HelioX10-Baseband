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
 *    flash_mtd_sf_ut.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Serial Flash device unit test
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/
#ifndef __FLASH_MTD_SF_UT_H__
#define __FLASH_MTD_SF_UT_H__

#include "flash_opt.h"

#ifdef __SF_DVT__
#include "flash_mtd_sf_dvt.h"
#else
#include "us_timer.h"
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#endif

// Test Options and Enable method
// 1. Module Test / Burin Test
//    Pre-defined compile option in make: IC_MODULE_TEST and IC_BURNIN_TEST.
// 2. Memory SLT
//    Add __SERIAL_FLASH_MEMORY_SLT__ to custom options in project make file
//    ex: CUSTOM_OPTION += __SERIAL_FLASH_MEMORY_SLT__
// 3. MVG Device Functional Test
//    Change flash_mtd.c FDM_UT_ITEM

#if (!defined(__UBL__))
#if ( (defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__)) || defined(IC_MODULE_TEST) || defined(IC_BURNIN_TEST) || defined(__SF_DVT__))
    #ifdef __SERIAL_FLASH__
        #define SF_DEBUG
    #endif
#endif
#endif //!defined(__UBL__)

// Test Setup
//-----------------------------------------------------------------------------
// [Test Cases]
//    SFUT_TEST_ERASE_PROGRAM_WITHOUT_SUSPEND
//      - Erase / Program without suspends
//    SFUT_TEST_ERASE_PROGRAM_WITH_SUSPEND
//      - Erase / Program with suspends
//    SFUT_TEST_MACRO_READ
//      - Macro Mode read test, regarding to the CS high time.
//    SFUT_TEST_WRAP_READ
//      - Wrap read functional test
//    SFUT_TEST_PROG_DISTURBANCE
//      - Program disturbance test
//      - Suspends only in program operation, after program, verifies all data within the same block.
//    SFUT_TEST_Erase_DISTURBANCE
//      - Erase disturbance test
//      - Suspends only in erase operation, after erase, verifies all data within the same block-group (256KB).
//
// [Configruations]
//    SFUT_DISTURBANCE_CHECK_IN_LISR
//      - Enable distrubance checking in SW intrrupt LISR
//      - For debug purpose only, target for the suspend-read fail.
//      - This will significantly slowing down the test speed.
//    SFUT_DISTURBANCE_LOOP_LIMIT
//      - Loop limit in erase/program disturnce test (N x 256KB)
//    SFUT_ERASE_SUSPEND_FREQUENCY
//      - SW interrupt (suspend) frequency while erasing, in terms of qbits per interrupt.
//      - Note: For some vendors, intense erase-suspend will cause erase time over expectation.
//          *** If the test hanged in the erase suspend test, try to set the frqeuncy to 4096.
//    SFUT_PROG_SUSPEND_FREQUENCY
//      - SW interrupt (suspend) frequency while programming, in terms of qbits per interrupt.
//      - Note: For some vendors, intense program-suspend will cause program time over expectation.
//          *** If the test hanged in the program suspend test, try to set the frqeuncy to 1024.
//    SFUT_CSHT_MIN, SFUT_CSHT_MAX, SFUT_CSHT_STEP
//      - The range and step of the CS high time
//      - The three parameters are used in Macro mode read test (SFUT_TEST_MACRO_READ)
//    SFUT_WRAP_LEN
//      - Warp read length
//    SFUT_WRAP_TEST_COUNT
//      - Number of random wrap read test counts
//-----------------------------------------------------------------------------

// Memory SLT test
//---------------------------------
#if defined(__SERIAL_FLASH_MEMORY_SLT__)
    // Test Cases
    #define SFUT_TEST_ERASE_PROGRAM_WITHOUT_SUSPEND
    #define SFUT_TEST_ERASE_PROGRAM_WITH_SUSPEND
    #define SFUT_TEST_MACRO_READ
    #define SFUT_TEST_WRAP_READ
    #define SFUT_TEST_ERASE_DISTURBANCE
    #define SFUT_TEST_PROG_DISTURBANCE
    //-----------------------------
    // Disturbance Test Parameters
//  #define SFUT_DISTURBANCE_CHECK_IN_LISR
    #define SFUT_DISTURBANCE_LOOP_LIMIT 16
    #define SFUT_DISTURBANCE_TIME_LIMIT 1
    // Suspend Frequency
    #define SFUT_ERASE_SUSPEND_FREQUENCY 4096
    #define SFUT_PROG_SUSPEND_FREQUENCY  1
    // Macro Mode Read Test: Chip Select High Time
    #define SFUT_CSHT_MIN  100
    #define SFUT_CSHT_MAX  500
    #define SFUT_CSHT_STEP 10
    // Macro Mode Read Test: Test Patterns
    #define SFUT_MAC_READ_COMPACT
    // #define SFUT_MAC_READ_DEBUG
    // Wrap Read Test
    #define SFUT_WRAP_LEN 32
    #define SFUT_WRAP_TEST_COUNT 4096
    // Enable Debug Log
    #define SFUT_DEBUG_LOG
    // Suspend Test
    #define SFUT_SUSPEND_TEST_ITERATION 4

// Burin test / Module test
//---------------------------------
#elif defined(IC_MODULE_TEST) || defined(IC_BURNIN_TEST)
    // Test Cases
    #define SFUT_TEST_MACRO_READ
    #define SFUT_TEST_WRAP_READ
    //-----------------------------
    // Disturbance Test Parameters
    #define SFUT_DISTURBANCE_LOOP_LIMIT 1
    #define SFUT_DISTURBANCE_TIME_LIMIT 1
    // Suspend Frequency
    #define SFUT_ERASE_SUSPEND_FREQUENCY 4096
    #define SFUT_PROG_SUSPEND_FREQUENCY  128
    // Macro Mode Read Test: Chip Select High Time
    #define SFUT_CSHT_MIN  120
    #define SFUT_CSHT_MAX  360
    #define SFUT_CSHT_STEP 10
    // Macro Mode Read Test: Test Patterns
    #define SFUT_MAC_READ_COMPACT
    // Wrap Read Test
    #define SFUT_WRAP_LEN 32
    #define SFUT_WRAP_TEST_COUNT 1024
    // Suspend Test
    #define SFUT_SUSPEND_TEST_ITERATION 4

// Serial Flash Device Validation Test
//---------------------------------
#elif defined(__SF_DVT__)
    // Test Cases
    #define SFUT_TEST_ERASE_PROGRAM_WITHOUT_SUSPEND
    #define SFUT_TEST_ERASE_PROGRAM_WITH_SUSPEND
    #define SFUT_TEST_MACRO_READ
    #define SFUT_TEST_WRAP_READ
    #define SFUT_TEST_ERASE_DISTURBANCE
    #define SFUT_TEST_PROG_DISTURBANCE
    //-----------------------------
    // Suspend Frequency
    #define SFUT_ERASE_SUSPEND_FREQUENCY 4096
    #define SFUT_PROG_SUSPEND_FREQUENCY  128
    // Macro Mode Read Test: Chip Select High Time
    #define SFUT_CSHT_MIN  100
    #define SFUT_CSHT_MAX  500
    #define SFUT_CSHT_STEP 10
    // Macro Mode Read Test: Test Patterns
    #define SFUT_MAC_READ_COMPACT
    // Wrap Read Test Parameters
    #define SFUT_WRAP_LEN 32
    #define SFUT_WRAP_TEST_COUNT 4096
    // Disturbance Test Parameters
    //  #define SFUT_DISTURBANCE_CHECK_IN_LISR
    #define SFUT_DISTURBANCE_LOOP_LIMIT 2048
    #define SFUT_DISTURBANCE_TIME_LIMIT 4
    // Enable Debug Log
    #define SFUT_DEBUG_LOG
    // Suspend Test
    #define SFUT_SUSPEND_TEST_ITERATION 4

// Basic Load Functional Test
//---------------------------------
#else
    // Test Cases
    #define SFUT_TEST_ERASE_PROGRAM_WITHOUT_SUSPEND
    #define SFUT_TEST_ERASE_PROGRAM_WITH_SUSPEND // mt6255 fpga
    #define SFUT_TEST_MACRO_READ // mt6255 fpga
    #define SFUT_TEST_WRAP_READ // mt6255 fpga
    #define SFUT_TEST_ERASE_DISTURBANCE // mt6255 fpga
    #define SFUT_TEST_PROG_DISTURBANCE // mt6255 fpga
    //-----------------------------
    // Suspend Frequency
    #define SFUT_ERASE_SUSPEND_FREQUENCY 4096
    #define SFUT_PROG_SUSPEND_FREQUENCY  128
    // Macro Mode Read Test: Chip Select High Time
    #define SFUT_CSHT_MIN  100
    #define SFUT_CSHT_MAX  500
    #define SFUT_CSHT_STEP 10
    // Macro Mode Read Test: Test Patterns
    #define SFUT_MAC_READ_COMPACT
    // Wrap Read Test Parameters
    #define SFUT_WRAP_LEN 32
    #define SFUT_WRAP_TEST_COUNT 4096
    // Disturbance Test Parameters
    //  #define SFUT_DISTURBANCE_CHECK_IN_LISR
    #define SFUT_DISTURBANCE_LOOP_LIMIT 0xFFFFFFFF
    #define SFUT_DISTURBANCE_TIME_LIMIT 4
    // Enable Debug Log
    #define SFUT_DEBUG_LOG
    #define SFUT_SHOW_TEST_COVERAGE
    // Suspend Test
    #define SFUT_SUSPEND_TEST_ITERATION 4
#endif
//-----------------------------------------------------------------------------

// Exported Serial Flash Unit Test APIs
kal_bool SFUT_DeviceTest(void);
void SFUT_LISR(void);
void SFUT_LISRInsert(void);
void SFUT_IntServe(void);
void SFUT_IntTrigger(void);
void SFUT_CorruptNOR(void);

// SW Interrupt Frequency Control
extern kal_uint32 SFUT_IntTimeCurr;
extern kal_uint32 SFUT_IntTimePrev;
extern kal_uint32 SFUT_IntTimeDiff;
extern kal_uint32 SFUT_IntFreq;
extern kal_uint32 SFUT_IntBusySuspend;
extern kal_uint32 SFUT_IntSuspendBase;

// Memory SLT GPIO outputs
#if !(defined(IC_MODULE_TEST) || defined(IC_BURNIN_TEST)) && !(defined(__SF_DVT__))
#define SFUT_GPIO_LED_OUTPUT
#endif

#define SFUT_READY_WRAP_FUNCTION_LED_GPIO     (47)    // Combinational read test
#define SFUT_READY_BASIC_FUNCTION_LED_GPIO    (49)    // Program / Erase without suspend
#define SFUT_READY_SUSPEND_FUNCTION_LED_GPIO  (51)    // Program / Erase with suspend + disturbance check

// SFUT concurrency test (only for Memory SLT)
// #define SFUT_MSDC_TRACE_ENABLE
#define SFUT_MSDC_CONCURRENCY_TEST

// Erase suspend disable
typedef enum {
    SFUT_DISABLE_ERASE_SUSPEND=0x1,
    SFUT_DISABLE_PROG_SUSPEND=0x2
} Enum_SFUT_DISABLE_SUSPEND;

extern kal_uint32 sfut_suspend_enable;

// Interrupt (Suspend) Insertion Macro
#if defined(SF_DEBUG)
// TODO: Add randomizer here
#define SFUT_IntTest(triggerfunc)   do {  \
    if (0!=SFUT_IntFreq) { \
        SFUT_IntTimeCurr=ust_get_current_time();  \
        if (ust_get_duration(SFUT_IntTimePrev, SFUT_IntTimeCurr) > (SFUT_IntFreq)) {  \
            SFUT_IntTimePrev=SFUT_IntTimeCurr; triggerfunc(); \
        } \
    } \
    if (0<SFUT_IntBusySuspend) { \
        SFUT_IntTimeCurr=ust_get_current_time(); \
        ust_busy_wait(SFUT_IntBusySuspend-1); \
        triggerfunc(); \
    } \
 } while(0)
#else
#define SFUT_IntTest(...)
#endif

#endif // __FLASH_MTD_SF_UT_H__

