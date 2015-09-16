/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *   br_time_stamp.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Time stamp measurement utility functions
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __BR_TIME_STAMP_H__
#define __BR_TIME_STAMP_H__

#include "br_sw_types.h"
#include "br_time_stamp_cb.h"

#if defined(__BOOTROM__)
    #include "br_time_stamp_id.h"
#elif defined(__UBL__)
    #include "bl_time_stamp_id.h"
#elif defined(__FUE__)
    #include "fue_time_stamp_id.h"
#else
    // MAUI 
    #include "maui_time_stamp_id.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

//==============================================================================
// TimeStamp Measurement APIs
//==============================================================================
#define TS_MAGIC1   0x454D4954  // "TIME"
#define TS_MAGIC2   0x504D5453  // "STMP"

typedef enum {
     TS_TIME_TICK = 0
    ,TS_TIME_US
    ,TS_TIME_MS
} TS_TIME_UNIT;

typedef struct {
    TSID            m_id;
    U16             m_duration;
    U32             m_info1;
    U32             m_info2;
    U32             m_info3;
    U32             m_begin_tick;
    U32             m_end_tick;
} TS_Unit;

typedef struct {
    TS_TIME_UNIT    m_unit;
    TS_Unit         m_record[TSID_NUM];
} TS_RecordTable;

#if defined(__TIME_STAMP__)

    // function prototype 
    extern void TS_Init(bool bResetRecords);
    extern void TS_ConvertTimeUnit(void);
    extern void TS_Record(TSID id, TS_TIME_ANCHOR anchor);
    extern void TS_UpdateInfo(TSID id, U32 data1, U32 data2, U32 data3);
    #if defined(__RTLSIM__)
        extern void TS_Record_RTLSIM(const char *id_str, TSID id, TS_TIME_ANCHOR anchor);
        extern void TS_UpdateInfo_RTLSIM(const char *id_str, TSID id, U32 data1, U32 data2, U32 data3);
    #elif defined(__UBL__)
        extern void TS_Record_BLWrapper(TSID id, TS_TIME_ANCHOR anchor);
        extern void TS_UpdateInfo_BLWrapper(TSID id, U32 data1, U32 data2, U32 data3);
    #endif

    // macro re-define 
    #if defined(__RTLSIM__)
        #define TS_RECORD_FUNC                  TS_Record_RTLSIM
        #define TS_INFO_FUNC                    TS_UpdateInfo_RTLSIM
        #define TS_BEGIN(id)                    TS_Record_RTLSIM(QUOTE(id##[BEGIN]), id, TS_BEGIN)
        #define TS_END(id)                      TS_Record_RTLSIM(QUOTE(id##[END]), id, TS_END)
        #define TS_INFO(id,d1,d2,d3)            TS_UpdateInfo_RTLSIM(QUOTE(id##[INFO]), id, d1, d2, d3)
    #elif defined(__UBL__)
        #define TS_RECORD_FUNC                  TS_Record_BLWrapper
        #define TS_INFO_FUNC                    TS_UpdateInfo_BLWrapper
        #define TS_BEGIN(id)                    TS_Record_BLWrapper(id, TS_BEGIN)
        #define TS_END(id)                      TS_Record_BLWrapper(id, TS_END)
        #define TS_INFO(id,d1,d2,d3)            TS_UpdateInfo_BLWrapper(id, d1, d2, d3)
    #else
        #define TS_RECORD_FUNC                  TS_Record
        #define TS_INFO_FUNC                    TS_UpdateInfo
        #define TS_BEGIN(id)                    TS_Record(id, TS_BEGIN)
        #define TS_END(id)                      TS_Record(id, TS_END)
        #define TS_INFO(id,d1,d2,d3)            TS_UpdateInfo(id, d1, d2, d3)
    #endif

#else

    #define TS_Init(b)
    #define TS_ConvertTimeUnit()
    #define TS_RECORD_FUNC                  NULL
    #define TS_INFO_FUNC                    NULL
    #define TS_BEGIN(id)
    #define TS_END(id)
    #define TS_INFO(id,d1,d2,d3)

#endif

//==============================================================================
// TimeStamp Utility APIs
//==============================================================================

#if defined(__TIME_STAMP__)

    #if defined(__TIME_STAMP_UTIL__)
        extern void TS_GetContext(U32 *p_addr, U32 *p_size);
        extern void TS_SetTimeUnit(TS_TIME_UNIT  unit);
        extern const TS_RecordTable * TS_GetRecordTable(void);
    #endif

#else

    #define TS_GetContext(a,s)
    #define TS_SetTimeUnit(u)
    #define TS_GetRecordTable()             NULL

#endif

#ifdef __cplusplus
}
#endif

#endif

