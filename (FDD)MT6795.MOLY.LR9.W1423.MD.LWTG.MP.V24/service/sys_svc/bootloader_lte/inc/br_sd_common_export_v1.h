/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   br_sd_common_export_v1.h
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *   BOOTROM common shared functions version 1 (EXPORTED APIs)
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __BR_SD_SD_COMMON_V1_H__
#define __BR_SD_SD_COMMON_V1_H__

#include "br_sw_types.h"

#ifdef __cplusplus
extern "C" {
#endif

//==============================================================================
// external struct declaration 
//==============================================================================

// N/A

//==============================================================================
// Shared reentrant common function prototype
//==============================================================================

// To be reentrant, a computer program or routine:
// 
// Must hold no static (or global) non-constant data.
// Must not return the address to static (or global) non-constant data.
// Must work only on the data provided to it by the caller.
// Must not rely on locks to singleton resources.
// Must not modify its own code. (unless executing in its own unique thread storage)
// Must not call non-reentrant computer programs or routines.
//
// Therefore, a reentrant function must not be a patched function, nor a function 
// that invokes patched functions

// UART 
typedef void (*SD_R_UART_INIT_V1)                   (U32 uart_clock, U32 uart_badurate);
typedef void (*SD_R_UART_CHECK_SEND_COMPLETE_V1)    (void);

// GPT4
typedef void (*SD_R_GPT4_START_V1)                  (bool bLock);
typedef void (*SD_R_GPT4_STOP_V1)                   (void);
typedef U32  (*SD_R_GPT4_GET_CURRENT_TICK_V1)       (void);
typedef bool (*SD_R_GPT4_TIMEOUT_TICK_V1)           (U32 start_tick, U32 timeout_tick);
typedef U32  (*SD_R_GPT4_TICK2TIME_US_V1)           (U32 tick);
typedef U32  (*SD_R_GPT4_TIME2TICK_US_V1)           (U32 timeout_us);
typedef U32  (*SD_R_GPT4_TICK2TIME_MS_V1)           (U32 tick);
typedef U32  (*SD_R_GPT4_TIME2TICK_MS_V1)           (U32 timeout_ms);
typedef void (*SD_R_GPT4_BUSY_WAIT_US_V1)           (U32 timeout_us);
typedef void (*SD_R_GPT4_BUSY_WAIT_MS_V1)           (U32 timeout_ms);

//==============================================================================
// Shared reentrant common function table
//==============================================================================

typedef struct SD_R_Common_FuncTable_v1 {
    // UART
    SD_R_UART_INIT_V1                   m_r_uart_init;
    SD_R_UART_CHECK_SEND_COMPLETE_V1    m_r_uart_check_send_complete;
    // GPT4
    SD_R_GPT4_START_V1                  m_r_gpt4_start;
    SD_R_GPT4_STOP_V1                   m_r_gpt4_stop;
    SD_R_GPT4_GET_CURRENT_TICK_V1       m_r_gpt4_get_current_tick;
    SD_R_GPT4_TIMEOUT_TICK_V1           m_r_gpt4_timeout_tick;
    SD_R_GPT4_TICK2TIME_US_V1           m_r_gpt4_tick2time_us;
    SD_R_GPT4_TIME2TICK_US_V1           m_r_gpt4_time2tick_us;
    SD_R_GPT4_TICK2TIME_MS_V1           m_r_gpt4_tick2time_ms;
    SD_R_GPT4_TIME2TICK_MS_V1           m_r_gpt4_time2tick_ms;
    SD_R_GPT4_BUSY_WAIT_US_V1           m_r_gpt4_busy_wait_us;
    SD_R_GPT4_BUSY_WAIT_MS_V1           m_r_gpt4_busy_wait_ms;
} SD_R_Common_FuncTable_v1;

//==============================================================================
// Shared non-reentrant common function prototype
//==============================================================================

// PLL
typedef U32  (*SD_PLL_CONTROL_V1)               (bool bEnable);
typedef bool (*SD_PLL_IS_ENABLED_V1)            (void);
typedef U32  (*SD_PLL_QUERY_CLOCK_UART_V1)      (void);

// Virtual I/O 
typedef U8   (*SD_IO_QUERY_INTERFACE_V1)        (void);
typedef U8   (*SD_IO_GET_BYTE_V1)               (void);
typedef void (*SD_IO_PUT_BYTE_EX_V1)            (U8 data, bool bFlushTx);
typedef U16  (*SD_IO_GET_DATA16_V1)             (void);
typedef void (*SD_IO_PUT_DATA16_EX_V1)          (U16 data16, bool bFlushTx);
typedef U32  (*SD_IO_GET_DATA32_V1)             (void);
typedef void (*SD_IO_PUT_DATA32_EX_V1)          (U32 data32, bool bFlushTx);
typedef void (*SD_IO_GET_DATA_BLOCK8_V1)        (U32 buf_addr, U32 data_len, U32 attr);
typedef void (*SD_IO_PUT_DATA_BLOCK8_V1)        (U32 buf_addr, U32 data_len, U32 attr);

//==============================================================================
// Shared non-reentrant common function table
//==============================================================================

typedef struct SD_NR_Common_FuncTable_v1 {
    // PLL
    SD_PLL_CONTROL_V1                   m_pll_control;
    SD_PLL_IS_ENABLED_V1                m_pll_is_enabled;
    SD_PLL_QUERY_CLOCK_UART_V1          m_pll_query_clock_uart;
    // Virtual I/O 
    SD_IO_QUERY_INTERFACE_V1            m_io_query_interface;
    SD_IO_GET_BYTE_V1                   m_io_get_byte;
    SD_IO_PUT_BYTE_EX_V1                m_io_put_byte_ex;
    SD_IO_GET_DATA16_V1                 m_io_get_data16;
    SD_IO_PUT_DATA16_EX_V1              m_io_put_data16_ex;
    SD_IO_GET_DATA32_V1                 m_io_get_data32;
    SD_IO_PUT_DATA32_EX_V1              m_io_put_data32_ex;
    SD_IO_GET_DATA_BLOCK8_V1            m_io_get_data_block8;
    SD_IO_PUT_DATA_BLOCK8_V1            m_io_put_data_block8;
} SD_NR_Common_FuncTable_v1;

//==============================================================================
// Shared common function prototype
//==============================================================================

typedef struct SD_Common_FuncTable_v1 {
    const SD_R_Common_FuncTable_v1  * const m_p_tbl_r;
    const SD_NR_Common_FuncTable_v1 * const m_p_tbl_nr;
} SD_Common_FuncTable_v1;

#ifdef __cplusplus
}
#endif

#endif

