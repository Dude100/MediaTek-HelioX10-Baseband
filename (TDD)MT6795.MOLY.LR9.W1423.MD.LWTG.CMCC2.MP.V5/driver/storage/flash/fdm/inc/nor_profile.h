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
 *    NORProfile.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   The profiling tool for NOR Flash Disk
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
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/
#ifndef __NORPROFILE_H__
#define __NORPROFILE_H__

#include "flash_mtd_ut.h"

//----------------------------------------------------------
// Generic Profiling Utility
//----------------------------------------------------------
/* Time diff function, Depend on BB chip, 0x01000000 for 6238 */
#if defined(MT6250) || defined(MT6280)
#define NOR_PROFILE_TIME_DIFF(start,end)   ((start>end)?(end+(0xFFFFFFFF-start)+0x1):(end-start))
#else
#define NOR_PROFILE_TIME_DIFF(start,end)   ((start>end)?(end+0x01000000-start):(end-start))
#endif

#if defined(__BASIC_LOAD_FLASH_TEST__)

#include "kal_public_api.h" //MSBB change #include "kal_release.h"

// The full profiling procedure
void NOR_Profile(void);

// The compact profiling procedure used by MVG basic load test
void NOR_Profile_Basic(void);

// The profiling function with extended parameters
void NOR_Profile_Ext(
    kal_uint32 mtd_min_chunk,  // Minimum chuck size in MTD, 0: default 2B (non-SIB), 1024B (SIB)
    kal_uint32 fdm_min_chunk,  // Minimum chuck size in FDM, 0: default 16B (non-SIB), 256B (SIB)
    kal_uint32 fdm_max_chunk,  // Maximum chuck size in FDM, 0: default 32KB (non-SIB), 256KB (SIB)
    kal_uint32 fs_file_size,   // Test file size in C: drive: default 128KB (non-SIB), 256KB (SIB)
    kal_uint8 log_type         // Log type: NORLogDisable(0)/NORLogComplex(1)/NORLogCompact(2)
);

typedef enum  {
    NORLogDisable=0,
    NORLogComplex=1,
    NORLogCompact=2
} EnNORProfileLogType;

typedef enum {
    NORProfileIdle=0,
    NORProfileMTD=1,
    NORProfileFDM=2
} EnNORProfileProcType;

// NOR Profiling Status
extern kal_uint8 NORProfileProcess;

// MTD
extern kal_uint32 MTDrBusyTimeTotal, MTDrBusyCount;
extern kal_uint32 MTDwBusyTimeTotal, MTDwBusyCount;
extern kal_uint32 MTDrSTime, MTDrETime, MTDrBusyTime;
extern kal_uint32 MTDwSTime, MTDwETime, MTDwBusyTime;

// FDM
extern kal_uint32 FDMrTotalTime, FDMrCount;
extern kal_uint32 FDMwTotalTime, FDMwCount;
extern kal_uint32 FDMrSTime, FDMrETime, FDMrBusyTime;
extern kal_uint32 FDMwSTime, FDMwETime, FDMwBusyTime;

// FS (not exported)

/*
    There are three layers
    1. FileSystem: FS_Read() / FS_Write()
    2. FDM: NOR_ReadSectors() / NOR_WriteSectors()
    3. MTD memcpy() / ProgramData()
*/

//----------------------------------------------------------
// External Function Prototypes
//----------------------------------------------------------
extern kal_uint32 NORTEST_GetCurrentTime(void);          // nor_test.c

//----------------------------------------------------------
// Cache Control
//----------------------------------------------------------
// Enable FS Cache (MT6253E9 only)
// #define FS_CACHE_ENABLE

#define NOR_PROFILE_RESET(...)  { \
    MTDrBusyTimeTotal = MTDrBusyCount = 0; \
    MTDwBusyTimeTotal = MTDwBusyCount = 0; \
    FDMrTotalTime = FDMrCount = 0;  \
    FDMwTotalTime = FDMwCount = 0;  \
}


//----------------------------------------------------------
// 60Qbits Profiling Utility
//----------------------------------------------------------
extern kal_uint32 w60QStart, w60QEnd, w60QDuration;
extern kal_uint32 w60QLongest, w60QShortest;

#define NOR_PROFILE_60Q_START(...) {  \
    w60QStart=ust_get_current_time(); \
}

#define NOR_PROFILE_60Q_END(...) {  \
    w60QEnd=ust_get_current_time(); \
    w60QDuration=ust_get_duration(w60QStart,w60QEnd); \
    w60QLongest=(w60QLongest<w60QDuration)?w60QDuration:w60QLongest;    \
    w60QShortest=(w60QShortest>w60QDuration)?w60QDuration:w60QShortest; \
}


//----------------------------------------------------------
// MTD Layer Profiling Utility
//----------------------------------------------------------
#define NOR_PROFILE_MTD_WRITE_Start(...)  {   \
    MTDwSTime = NORTEST_GetCurrentTime(); \
}

#define NOR_PROFILE_MTD_WRITE_End(...)  {   \
    MTDwETime = NORTEST_GetCurrentTime(); \
    MTDwBusyTime = NOR_PROFILE_TIME_DIFF(MTDwSTime, MTDwETime); \
    MTDwBusyTimeTotal += MTDwBusyTime;  \
}

#define NOR_PROFILE_MTD_WRITE_Count(...) { \
    MTDwBusyCount++; \
}

#define NOR_PROFILE_MTD_READ_Start(...)  {   \
    MTDrSTime = NORTEST_GetCurrentTime(); \
}

#define NOR_PROFILE_MTD_READ_End(...)  {   \
    MTDrETime = NORTEST_GetCurrentTime(); \
    MTDrBusyTime = NOR_PROFILE_TIME_DIFF(MTDrSTime,MTDrETime); \
    MTDrBusyTimeTotal += MTDrBusyTime;  \
}

#define NOR_PROFILE_MTD_READ_Count(...) { \
    MTDrBusyCount++; \
}

//----------------------------------------------------------
// FDM Layer Profiling Utility
//----------------------------------------------------------
#define NOR_PROFILE_FDM_WRITE_Start(...)  {   \
    FDMwSTime = NORTEST_GetCurrentTime(); \
}

#define NOR_PROFILE_FDM_WRITE_End(...)  {   \
    FDMwETime = NORTEST_GetCurrentTime(); \
    FDMwBusyTime = NOR_PROFILE_TIME_DIFF(FDMwSTime, FDMwETime); \
    FDMwTotalTime += FDMwBusyTime;  \
}

#define NOR_PROFILE_FDM_WRITE_Count(...) { \
    FDMwCount++; \
}

#define NOR_PROFILE_FDM_READ_Start(...)  {   \
    FDMrSTime = NORTEST_GetCurrentTime(); \
}

#define NOR_PROFILE_FDM_READ_End(...)  {   \
    FDMrETime = NORTEST_GetCurrentTime(); \
    FDMrBusyTime = NOR_PROFILE_TIME_DIFF(FDMrSTime, FDMrETime); \
    FDMrTotalTime += FDMrBusyTime;  \
}

#define NOR_PROFILE_FDM_READ_Count(...) { \
    FDMrCount++; \
}

#else //  __BASIC_LOAD_FLASH_TEST__

#define NOR_PROFILE_MTD_WRITE_Start(...)
#define NOR_PROFILE_MTD_WRITE_End(...)
#define NOR_PROFILE_MTD_WRITE_Count(...)
#define NOR_PROFILE_FDM_WRITE_Start(...)
#define NOR_PROFILE_FDM_WRITE_End(...)
#define NOR_PROFILE_FDM_WRITE_Count(...)

#define NOR_PROFILE_MTD_READ_Start(...)
#define NOR_PROFILE_MTD_READ_End(...)
#define NOR_PROFILE_MTD_READ_Count(...)
#define NOR_PROFILE_FDM_READ_Start(...)
#define NOR_PROFILE_FDM_READ_End(...)
#define NOR_PROFILE_FDM_READ_Count(...)

#define NOR_PROFILE_60Q_START(...)
#define NOR_PROFILE_60Q_END(...)

#define NOR_Profile(...)
#define NOR_Profile_Basic(...)

#endif // __BASIC_LOAD_FLASH_TEST__

// #define NOR_SIM_DOWNGRADE
#ifdef NOR_SIM_DOWNGRADE
#define NOR_SIM_PROG_DELAY(ustime)  { \
    DelayAWhile_UST(ustime); \
}
#else
#define NOR_SIM_PROG_DELAY(...)
#endif // NOR_SIM_DOWNGRADE

#endif //__NORPROFILE_H__
