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
 *   SST_dmdsp_ex.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines the structure and prototype for handling Dual MAC
 *   DSP exceptions
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SST_DMDSP_EX_H__
#define __SST_DMDSP_EX_H__


#if defined(__DSP_FCORE4__)

#include "kal_general_types.h"

/****************************************************************************
 *
 *  Defines the message ids for MDCI communication
 *
 ****************************************************************************/

/** The message ids between MCU and DSP for exception handling */
typedef enum
{
    ECMSG_ID_DSP_TRIGGER_ASSERT   = 0x00000001,   /* D2M, DSP triggers MCU assert */
    ECMSG_ID_MCU_TRIGGER_ASSERT   = 0x00000002,   /* M2D, MCU triggers DSP assert */
    ECMSG_ID_MEM_REGION_INFO      = 0x00000003,   /* M2D, Query DSP memory region info */
    ECMSG_ID_EXCEPTION_LOG        = 0x00000004,   /* D2M, Provide the DSP exception log */
} except_channel_msg_t;


/****************************************************************************
 *
 *  Define the constants
 *
 ****************************************************************************/

/** The maximum number call stack length */
#define DMDSP_EX_CALL_STACK_LEN         10

/** The maximum SW version length */
#define DMDSP_EX_SW_VERSION_LEN         32

/** The maximum number of IRQ mask */
#define DMDSP_EX_MAX_IRQ_MASK           8

/** The maximum length of the name */
#define DMDSP_EX_MAX_NAME_LEN           8

/** The maximum length of the file */
#define DMDSP_EX_MAX_FILE_LEN           32

/** The maximum dump data of assertion fail */
#define DMDSP_EX_MAX_DUMP_DATA          200

/** The maximum analysis entry */
#define DMDSP_EX_MAX_ANALYSIS_ENTRY     10

/** The Dual MAC DSP exception log version */
#define DMDSP_EX_LOG_VERSION            1

/** The trace buffer count */
#define DMDSP_DUMP_TRACE_BUFFER_COUNT   32

/** The Dual MAC DSP maximum exception log number */
#define DMDSP_EX_LOG_MAX_ENTRY          2

/** The Dual MAC DSP close reason */
typedef enum
{
   DMDSP_CLOSE_REASON_NORMAL = 0,
   DMDSP_CLOSE_REASON_ASSERT,
   DMDSP_CLOSE_REASON_EXC,
   DMDSP_CLOSE_REASON_FATAL
} dmdsp_close_reason_t;


/****************************************************************************
 *
 *  Defines the data structure
 *
 ****************************************************************************/

/*************************************************************************
 * Define date types for common exception information
 *************************************************************************/

/** The exception log header */
typedef struct {
    kal_uint32              exlog_ver;
    kal_uint32              close_reason;
    kal_char                sw_version[DMDSP_EX_SW_VERSION_LEN];
} dmdsp_exlog_header_t;


/** The environment info in exception log */
typedef struct {
    kal_char                exec_uint[DMDSP_EX_MAX_NAME_LEN];
    kal_uint32              call_stack[DMDSP_EX_CALL_STACK_LEN];
    kal_uint32              irq_mask[DMDSP_EX_MAX_IRQ_MASK];
    kal_uint32              imask;
    kal_uint32              last_int_src;
    kal_uint32              stack_frame_ptr;
} dmdsp_exlog_env_info_t;


/** The diagnostic info in exception log */
typedef struct {
    kal_uint32              system_status;
    kal_uint32              owner_type;
    kal_uint32              health_status;
    kal_char                owner_name[DMDSP_EX_MAX_FILE_LEN];
    kal_uint32              data_watchpoint;
} dmdsp_exlog_diag_info_t;


/*************************************************************************
 * Define date types for fatal exception
 *************************************************************************/

/** The trace buffer record to be dumped in Dual MAC DSP */
typedef struct
{
    kal_uint32                  count;
    kal_uint32                  trace_entry[DMDSP_DUMP_TRACE_BUFFER_COUNT];
} dmdsp_dump_trace_buffer_t;

/** The fatal exception information in exception log */
typedef struct {
    kal_uint32                  exception_code;
    kal_uint32                  icplb_fault_addr;
    kal_uint32                  dcplb_fault_addr;
    dmdsp_dump_trace_buffer_t   trace_buffer;
} dmdsp_exlog_exception_info_t;


/*************************************************************************
 * Define date types for assertion fail
 *************************************************************************/
 
/** The assertion fail information in exception log */
typedef struct {
    kal_char                     file_name[DMDSP_EX_MAX_FILE_LEN];
    kal_uint32                   line_number;
    kal_uint32                   params[3];
    kal_uint8                    dump_data[DMDSP_EX_MAX_DUMP_DATA];
} dmdsp_exlog_assert_info_t;


/*************************************************************************
 * Define date types for fatal error
 *************************************************************************/

/** The fatal error information in exception log */
typedef struct {
    kal_uint32                   error_code;
    kal_uint32                   parameter;
    kal_uint32                   analysis[DMDSP_EX_MAX_ANALYSIS_ENTRY];
} dmdsp_exlog_fatal_error_info_t;


/*************************************************************************
 * Define the exception log data structure
 *************************************************************************/

/** The DAK exception log */
typedef struct {

    dmdsp_exlog_header_t          header;
    dmdsp_exlog_env_info_t        env_info;
    dmdsp_exlog_diag_info_t       diag_info;

    /* Union of the error data information */
    union { 
        dmdsp_exlog_exception_info_t      exception_info;
        dmdsp_exlog_assert_info_t         assert_info;
        dmdsp_exlog_fatal_error_info_t    fatal_err_info;
    } error;

    /* Extra data */
    kal_uint8                     ext_data[1];
} dmdsp_ex_log_t;


/****************************************************************************
 *
 *  Defines the function prototype
 *
 ****************************************************************************/

extern void dmdsp_ex_init(void);
extern void dmdsp_ex_notify_dsp(void);
extern kal_bool dmdsp_ex_is_from_dsp(void);
extern dmdsp_ex_log_t *dmdsp_ex_get_excep_log(kal_uint32 *len_ptr);



#endif /* defined(__DSP_FCORE4__) */


#endif  /* __SST_DMDSP_EX_H__ */


