/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   ccci_debug.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI debug level configuration and macros
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * [CCCI] CCCI new debug mechanism
 *
 * removed!
 * removed!
 * Submit CCCI L2 trace
 *
 * 09 06 2013 ap.wang
 * removed!
 *
 * 04 12 2013 ap.wang
 * removed!
 * [CCCI] Add log for debug
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#ifndef _CCCI_DEBUG_H
#define _CCCI_DEBUG_H

#define HIF_DATA_TRACE_ENABLED          1

#if defined(__MTK_TARGET__)
    #define HIF_CONSOLE_TRACE_ENABLED   0 /* TODO: set it to 0 once DHL log is done on target. */
#else
    #define HIF_CONSOLE_TRACE_ENABLED   0 /* 0:disable log in MoDIS  1:enable log in MoDIS*/
#endif

#include "hif_trace.h"
#include "ccci_trace.h"
#include "ccci_if.h"
#include "TrcMod.h"

#define CCCI_DBG_TH	CCCI_TRACE
typedef enum _ccci_dbg_level {
	CCCI_TRACE = 0,
	CCCI_INFO,
	CCCI_WARN,
	CCCI_ERR,
	CCCI_OFF = 0xFF,
}ccci_dbg_level;

#define CCCI_DBG_MSK    (CCCI_MOD_HMU|CCCI_MOD_API|CCCI_MOD_HIF|CCCI_MOD_SDIO|CCCI_MOD_UT|CCCI_MOD_IT|CCCI_MOD_DEBUG)
#define CCCI_MOD_HMU    0x00000001
#define CCCI_MOD_API    0x00000002
#define CCCI_MOD_HIF    0x00000004
#define CCCI_MOD_SDIO   0x00000008
#define CCCI_MOD_UT     0x00000010
#define CCCI_MOD_IT     0x00000020
#define CCCI_MOD_DEBUG  0x00000040



#define __CCCI_DEBUG__

void ccci_dhl_print(kal_uint8 level, kal_uint32 mod, const char *fmt, ...);
void ccci_dump_data(void* p_data, kal_uint32 bytes);
void ccci_data_trace_dump(kal_uint32 ch,void* p_data, kal_uint32 bytes);

#ifdef __CCCI_DEBUG__
#define ccci_printf ccci_dhl_print
#else
#define ccci_printf(...)
#endif

#define __ccci_err_printf  hif_trace_error
#define __ccci_info_printf hif_trace_info

#define ccci_data_trace    hif_data_trace

#define ccci_trace(level, mod, ...)\
do{\
    if (level >= CCCI_DBG_TH) {\
        if (mod & CCCI_DBG_MSK) {\
            if (level == CCCI_ERR) {\
                __ccci_err_printf(__VA_ARGS__);\
            }else{\
                __ccci_info_printf(__VA_ARGS__);\
            }\
        }\
    }\
}while(0)       \


// CCCI seq trace
#define CCCI_DEBUG_MAX_SEQ_NUM 0x7FFF
#define CCCI_DEBUG_INCREASE_SEQ_NUM(seq) \
        do { \
            seq++; \
            if(seq > CCCI_DEBUG_MAX_SEQ_NUM) \
                seq = 0; \
        } while(0)
            
#define CCCI_DEBUG_ADD_SEQ_IN_CH(ch, seq) (ch = ch | ((seq & CCCI_DEBUG_MAX_SEQ_NUM) << 0x10)) // bit 16~31 is seq
#define CCCI_DEBUG_GET_SEQ_IN_CH(ch) ((ch >> 0x10) & CCCI_DEBUG_MAX_SEQ_NUM) // bit 16~31 is seq
#define CCCI_DEBUG_GET_ASSERT_BIT_IN_CH(ch) ((ch & 0x80000000) >> 0x1F) // bit 32 is assert bit
#define CCCI_DEBUG_ADD_ASSERT_BIT_IN_CH(ch, assert_bit) (ch = ch | ((assert_bit & 0x1) << 0x1F)) // bit 32 is assert bit
#define CCCI_DEBUG_CLR_SEQ_IN_CH(ch) (ch = ((ch << 0x10) >> 0x10) ) // bit 32~16 is seq
#define CCCI_DEBUG_STATUS_GUARD_PATTERN_START(index) ((0xCCDB << 0x10) | index)
#define CCCI_DEBUG_STATUS_GUARD_PATTERN_END(index)   ((0xDBCC << 0x10) | index)
#define CCCI_DEBUG_4BYTE_ALIGN(value) ((((value) + 3) >> 2) << 2) 
#define CCCI_DEBUG_RELOAD_GPD_COUNT 1

kal_bool ccci_debug_init();
kal_int32 ccci_debug_write_record(void *record_ptr);

typedef struct 
{
    kal_uint32 start_pattern;
    kal_uint32 number;
    kal_uint32 current_addr;
    kal_uint32 end_pattern;
}ccci_debug_record_hdr_t;

#endif /* _CCCI_DEBUG_H */
