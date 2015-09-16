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
 *   dhl_def.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   DHL function and struct definition
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 11 14 2014 hk.yang
 * removed!
 * [MP6] pls enhancement
 *
 * 10 31 2014 hk.yang
 * removed!
 * [MP6] dhl logging overwrite mode and passive logging on SD
 *
 * 09 29 2014 ken.liu
 * removed!
 * Add internal trace access level for MBJ L1.
 *
 * removed!
 * removed!
 * Split GPD list of control channel and data channel
 *
 * 06 16 2014 ken.liu
 * removed!
 * re-enable l1 boxster.
 *
 * 06 09 2014 ken.liu
 * removed!
 * re-enable l1 boxster.
 *
 * removed!
 * removed!
 * Back out changelist 588574
 *
 * 06 09 2014 ken.liu
 * removed!
 * add __SIP_RAM_SIZE__ for 8MB size config on EVB.
 *
 * removed!
 * removed!
 * .
 *
 * 06 06 2014 ken.liu
 * removed!
 * sync from K2 pre-bringup dev branch.
 *
 * removed!
 * removed!
 * .
 *
 * 04 08 2014 ken.liu
 * removed!
 * enable check for database integrity.
 *
 * removed!
 * removed!
 *  .
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *  .
 *
 * 03 07 2014 hk.yang
 * removed!
 * Add dhl trace stats
 *
 * removed!
 * removed!
 * Provide L2 trace timestamp API and change L2 trace type number
 *
 * removed!
 * removed!
 * .
 *
 * 01 14 2014 ken.liu
 * removed!
 * enable new sys trace and dhl header format
 *
 * 01 08 2014 ken.liu
 * removed!
 * update access level define names.
 *
 * 01 08 2014 ken.liu
 * removed!
 * add access level defines.
 *
 * 12 31 2013 ken.liu
 * removed!
 * enable dhl_internal_trace support.
 *
 * removed!
 * removed!
 *  .
 *
 * removed!
 * removed!
 *  .
 *
 * removed!
 * removed!
 *  .
 *
 * 11 15 2013 ken.liu
 * removed!
 * add filter on/off control for META tool.
 *
 * 11 08 2013 ken.liu
 * removed!
 * add default_type mem type for tool access.
 *
 * removed!
 * removed!
 *  .
 *
 * removed!
 * removed!
 *  .
 *
 * removed!
 * removed!
 *  .
 *
 * removed!
 * removed!
 *  .
 *
 * removed!
 * removed!
 *  .
 *
 * removed!
 * removed!
 *  .
 *
 * 08 15 2013 ken.liu
 * removed!
 * add read/write API for smart phone logging
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * 07 25 2013 ken.liu
 * removed!
 * check-in dhl mux filter support (disabled by default until next ELT release)
 *
 * 07 05 2013 ken.liu
 * removed!
 * 2/3g handover time support
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * .
 *
 * 06 05 2013 ken.liu
 * removed!
 * assign rx gpd after port is opened
 *
 * 06 03 2013 ken.liu
 * removed!
 * add DHL partial filter command.
 *
 * 06 03 2013 ken.liu
 * removed!
 * sync from MT6290E1_FirstCall.
 *
 * removed!
 * removed!
 * rework l2 copro logger
 *
 * removed!
 * removed!
 * L2 copro support
 *
 * 05 07 2013 ken.liu
 * removed!
 * reduce log ring buffer size to fit memory budget.
 *
 * 04 30 2013 ken.liu
 * removed!
 * sync dhl_peer_trace and dhl_EM_logger() from stanleyHY's CBr.
 *
 * 04 30 2013 ken.liu
 * removed!
 * sync from MT6290E1_FirstCall.
 *
 * removed!
 * removed!
 * Fix compile error
 *
 * removed!
 * removed!
 * SWTR merge
 *
 * 03 22 2013 ken.liu
 * removed!
 * 1. remove tst_dump_to_file_for_crash dummy wrapper
 * 2. sync FDI L1DMA
 * 3. enable per-byte processing for exception rx
 *
 * 03 20 2013 ken.liu
 * removed!
 * Back out changelist 107910
 *
 * 12 20 2012 ken.liu
 * removed!
 * enable uart channel with software flow control.
 *
 * 11 07 2012 ken.liu
 * removed!
 * dhl module check-in.
 ****************************************************************************/

#ifndef _DHL_DEF_H
#define _DHL_DEF_H

#include "dhl_trace.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "svc_sap.h"

#ifdef __EM_MODE__
  #ifndef _EM_STRUCT_H
    #include "em_struct.h"
  #endif  //#ifndef _EM_STRUCT_H
#endif  //#ifdef __EM_MODE__

#include "dcl.h"

#include "sysconf_statistics.h"

#if !defined (L1_SIM)
#include "nvram_interface.h"
//#include "nvram_data_items.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#endif

#include "tst.h"

#define DHL_NVRAM_ACCESS_EXCEPTION 1
#define DHL_NVRAM_ACCESS_STATISTIC 2
#define DHL_NVRAM_ACCESS_OTHERS 3

#define TST_MODULE_FILTER_LEN       ((END_OF_MOD_ID+8)/8)

#define TST_SAP_FILTER_LEN          (LAST_SAP_CODE+1)

#define TST_TRACE_FILTER_LEN        (2*(END_OF_MOD_ID+1))

#define TST_TOTAL_FILTER_LEN    (TST_MODULE_FILTER_LEN+ TST_SAP_FILTER_LEN+ TST_TRACE_FILTER_LEN)

#define DHL_TIMER_ID_SYNC 0


extern kal_eventgrpid   dhl_event_group;
#define DHL_EVENT_DATA_READY            (0x1)
#define DHL_EVENT_PORT_NOT_USING    (0x2)
#define DHL_EVENT_TX_IOR_READY         (0x4)
#define DHL_EVENT_TX_RESUME              (0x8)
#define DHL_EVENT_RESUME_READER     (0x10)
#define DHL_EVENT_TOOL_CONNECT       (0x20)
#define DHL_EVENT_READY_TO_WRITE    (0x40)

extern kal_eventgrpid dhl_rt_event_group;
#define DHL_RT_EVENT_L1DMA_BUFFER_READY (0x1)
#define DHL_RT_EVENT_L1_BUFFER_READY (0x2)
#define DHL_RT_EVENT_L2_BUFFER_READY (0x4)
#define DHL_RT_EVENT_ASM_BUFFER_READY (0x8)
#define DHL_RT_EVENT_IRDBG_BUFFER_READY (0x10)
#define DHL_RT_EVENT_TOOL_CONNECT (0x20)

#if !defined (__MTK_TARGET__)
  #define TST_RING_BUFFER_SIZE (1<<28)
#elif defined(FORCE_DHL_RING_BUFFER_SCALE)
  #if defined(GEN_FOR_PC)
    #define TST_RING_BUFFER_SIZE (FORCE_DHL_RING_BUFFER_SCALE << 10)
  #else
    #if FORCE_DHL_RING_BUFFER_SCALE < (512)
      #error "DHL logging buffer should be greater than or equal to 512KB"
    #elif FORCE_DHL_RING_BUFFER_SCALE > (128 * 1024)
      #error "DHL logging buffer should be less than or equal to 128MB"
    #else
      #define TST_RING_BUFFER_SIZE (FORCE_DHL_RING_BUFFER_SCALE << 10)
    #endif // FORCE_DHL_RING_BUFFER_SCALE size check
  #endif // GEN_FOR_PC
#else
#if defined (__LTE_RAT__)
  #if defined (__SIP_RAM_SIZE__) || defined (__DHL_SP_LOGGING_SUPPORT__)
    #define TST_RING_BUFFER_SIZE (1<<23)
  #else
    #define TST_RING_BUFFER_SIZE (1<<24)
  #endif
#elif defined (__UMTS_RAT__)
  #define TST_RING_BUFFER_SIZE (1<<19)
#else
  #define TST_RING_BUFFER_SIZE (1<<19)
#endif
#endif
#define DHL_FAST_BUFFER_SIZE (1<<15)

#define ASSERT_COMMAND_BUFFER_LENGTH (1024)

#ifdef IN_MEMORY_EXCEPTION_BUFFER
#define DHL_EXCEPTION_BUFFER_SIZE (TST_RING_BUFFER_SIZE * 2)
#endif

#define  INJECT_STRING_TO_MODULE_MAX_LENGTH  (128)
#define  INJECT_AT_COMMAND_MAX_LENGTH        (128)

#ifdef UNIT_TEST
#define DHL_RTOS_TIME_RESOLUTION_TICK (1)
#else
#define DHL_RTOS_TIME_RESOLUTION_TICK (1)
#endif

#ifdef __MTK_TARGET__
#define  MAX_TST_RECEIVE_BUFFER_LENGTH       256
#else
#define  MAX_TST_RECEIVE_BUFFER_LENGTH       (64*1024-1)
#endif  /* UNIT_TEST */

extern DCL_DEV   tst_L1Trc_port;
extern DCL_DEV   tst_PsTrc_port;
extern DCL_DEV   tst_rx_port;
extern UART_FLOW_CTRL_MODE_T tst_l1_flowCtrlMode;
extern UART_FLOW_CTRL_MODE_T tst_ps_flowCtrlMode;
extern UART_BAUDRATE_T tst_L1Trc_baudrate;
extern UART_BAUDRATE_T tst_PsTrc_baudrate;
extern kal_bool  tst_is_L1Trc_open;
extern kal_bool  tst_is_PsTrc_open;
extern kal_bool  tst_is_l1_writing_uart;/*protect UART Port from closing while writing*/
extern kal_bool  tst_is_ps_writing_uart;/*protect UART Port from closing while writing*/

/*for close/open UART port in run time*/
extern kal_bool tst_is_uart_open;
extern kal_bool tst_is_writing_uart;

#if defined (UNIT_TEST) || defined (__UE_SIMULATOR__)
#define LEGACY_TX
#endif

#if defined(__MD2__) && !defined(__HIF_CCCI_SUPPORT__)
#define LEGACY_TX
#define __ELT_SET_PORT_TO_UART__
#endif

extern kal_uint8  tst_ring_buffer[];
extern kal_uint32 tst_ptr_buffer_start;
extern kal_uint32 tst_ptr_buffer_end;
#ifndef LEGACY_TX
extern kal_uint32 tst_ptr_buffer_sent;
#endif

#ifdef IN_MEMORY_EXCEPTION_BUFFER
extern kal_uint8 dhl_exception_buffer[];
extern kal_uint32 dhl_exception_buffer_pos;
#endif

//the following is dummy tst enums/structs to bypass cgen database check
typedef enum {
    TST_NULL_COMMAND
} tst_command_type;

typedef kal_uint8 tst_null_command_struct;

typedef struct
{
   tst_command_type  command_type;
   kal_uint16        cmd_len;
} tst_command_header_struct;

typedef struct
{
    kal_uint32     dummy;
} tst_log_prim_header_struct;

typedef struct
{
    kal_uint32     dummy;
} tst_index_trace_header_struct;

typedef struct
{
    kal_uint32     dummy;
} tst_prompt_trace_header_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   index;
    kal_uint8   string[INJECT_STRING_TO_MODULE_MAX_LENGTH];
} tst_inject_string_struct;

typedef tst_inject_string_struct dhl_inject_string_struct;

#define TST_MSG_LOG_SAP_ENABLE 0x7

typedef stack_timer_struct timer_expiry_struct;


#define MAX_RAW_TRACE_SIZE (128)
#define MAX_TRACE_SIZE (128)
#define EX_MAX_TRACE_SIZE (128)

#define MAX_HEADER_LEN (8)

#if defined(DHL_V_0_5_1) || defined(DHL_V_0_7_1)
#define DHL_TYPE_CHECKSUM_FLAG      (0x10)
#define DHL_TYPE_USER_FLAG                (0x20)
#define DHL_TYPE_EXT_FLAG                  (0x08)
#define DHL_TYPE_MASK                         (0x07)
#else
#define DHL_FLAG_EXTRA                       (0x1)
#define DHL_FLAG_CHECKSUM              (0x20)
#endif

#define DHL_UNKNOWN_TYPE            (-1)

#define __TST_META_MODE_TRACE_ENABLE__ // for MOD_FT

typedef enum {
#if defined (DHL_V_0_5_1)
    V0_5_1_W1118
#elif defined(DHL_V_0_7_1)
    V0_7_1_W1232
#else
    V0_7_2_W1346
#endif  
} dhl_protocol_version;

//For ELT version checking
typedef enum {
  V2_1439_0
} elt_min_version;

typedef enum {
  NO_CHECKSUM,
  NO_HEADER_COMPRESSION,
} dhl_protocol_info;

typedef enum {  
    DHL_PRIMITIVE = 0,
    DHL_INDEX_TRACE = 1,
    DHL_RAW_BYTE_TRACE = 2,
    DHL_RAW_STRING_TRACE = 3,
    DHL_DISCARD_INFO = 4,
    DHL_TIME_INFO = 5,
    DHL_RLE_PRIMITIVE = 6,
    DHL_PRIMITIVE_ADT = 7,
    DHL_L1_TRACE = 8,
    DHL_META_CNF_PRIMITIVE = 9,
    DHL_L2_TRACE = 10,
} dhl_type;

#define DHL_TYPE_NUM 11

#if defined (DHL_V_0_5_1)
typedef struct {
    kal_uint16 type;    
    kal_uint16 len;
} dhl_header_struct;
#else
typedef struct {
    kal_uint8 flag;
    kal_uint8 type; 
    kal_uint16 len;
} dhl_header_struct;
#endif

typedef struct {
    kal_uint8 type;
    kal_uint8 len;
} dhl_compact_header_struct;

typedef struct {
    kal_uint8 type;
} dhl_ultra_compact_header_struct;

typedef struct {
    kal_uint32          msg_index;
    trace_class_enum    trace_class; 
    kal_uint8           access_level;
#if (defined(__GEMINI__) || defined(__SGLTE__))
    module_type module_id;
#endif      
} dhl_index_trace_header_struct;

typedef struct {    
    kal_uint16 key_len;
    kal_uint16 data_len;
} dhl_index_trace_ext_header_struct;

typedef struct {
    kal_uint32          msg_index;
    trace_class_enum    trace_class; 
#if (defined(__GEMINI__) || defined(__SGLTE__))
  module_type module_id;
#endif         
} dhl_raw_byte_trace_header_struct;

typedef struct {
    module_type         module_id;
    trace_class_enum    trace_class;    
} dhl_raw_string_trace_header_struct;

typedef struct {
    module_type src_mod_id;
    module_type dest_mod_id;
    sap_type    sap_id;
    msg_type    msg_id;
    kal_uint16  local_len;
    kal_uint16  peer_len;
    kal_uint32  local_addr;
    kal_uint32  peer_addr;
} dhl_primitive_header_struct;

typedef dhl_primitive_header_struct dhl_rle_primitive_header_struct;

typedef struct {
    module_type src_mod_id;
    module_type dest_mod_id;
    sap_type    sap_id;
    msg_type    msg_id;
    kal_uint16  local_len;
    kal_uint16  peer_len;
    kal_uint32  local_addr;
    kal_uint32  peer_addr;
    kal_uint8   local_access_type;
    kal_uint8   peer_access_type;
} dhl_ex_primitive_header_struct;

typedef struct {
    kal_uint32 src_mod_id;
    kal_uint32 dest_mod_id;
    kal_uint32 sap_id;
    kal_uint32 msg_id;
    kal_uint16 local_len;
    kal_uint16 peer_len;
} dhl_meta_cnf_primitive_header_struct;

typedef struct {
#if defined (DHL_V_0_5_1)
    kal_uint16 count;
#else
    kal_uint8 count;
#endif  
} dhl_discard_info_header_struct;

#define DISCARD_INFO_TYPE_UNKNOWN       (0x0)
#define DISCARD_INFO_TYPE_PS_TRACE        (0x1)
#define DISCARD_INFO_TYPE_PRIMITIVE        (0x2)
#define DISCARD_INFO_TYPE_TIMESTAMP      (0x3)
#define DISCARD_INFO_TYPE_L1_TRACE        (0x4)
#define DISCARD_INFO_TYPE_L1_BUFFER      (0x5)
#define DISCARD_INFO_TYPE_L2_TRACE        (0x6)
#define DISCARD_INFO_TYPE_L2_BUFFER      (0x7)

typedef enum {
    PS_TRACE = 1,
    PRIMITIVE = 2,
    TIMESTAMP = 3,
    L1_TRACE = 4,
    L1_BUFFER = 5,
    L2_TRACE = 6,
    L2_BUFFER = 7,
} dhl_discard_info_type;

typedef struct {
    kal_uint32 count;
} dhl_discard_info_type_ps_trace;

typedef struct {
    kal_uint32 count;
} dhl_discard_info_type_primitive;

typedef struct {
    kal_uint16 count;
} dhl_discard_info_type_timestamp;

typedef struct {
    kal_uint32 count;
} dhl_discard_info_type_l1_trace;

typedef struct {
    kal_uint16 count;
} dhl_discard_info_type_l1_buffer;

typedef struct {
    kal_uint8 count;
} dhl_discard_info_type_l2_trace;

typedef struct {
    kal_uint16 count;
} dhl_discard_info_type_l2_buffer;

typedef struct {
#if defined (DHL_V_0_5_1)
    kal_uint16 count;
#else
    kal_uint8 count;
#endif  
} dhl_time_info_header_struct;

#define TIME_INFO_TYPE_RTOS_TIMESTAMP    (0x1)
#define TIME_INFO_TYPE_3G_FRAME               (0x2)
#define TIME_INFO_TYPE_3G_SFN                    (0x3)

typedef enum {
    RTOS_TIME = 1,
} dhl_time_info_type;

typedef struct {
    kal_uint32 timestamp;
} dhl_time_info_type_rtos_time;

typedef struct {
    kal_uint16 count;
} dhl_l1_trace_header_struct;

#if defined(DHL_FRAME_LEN_WORD_ALIGN)
#define RUP(_v) ((_v + 3) / 4 * 4)
#else
#define RUP(_v) (_v)
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#define dhl_ex_trace_impl(_t, _u, _msg, _mod, _argv, _arg_info) \
    dhl_ex_internal_trace_impl(_t, _u, DHL_ACCESS_LEVEL_1_ALL_USER, _msg, _mod, _argv, _arg_info)
extern void dhl_ex_internal_trace_impl(trace_class_enum trc_class, kal_uint32 user_flag, kal_uint8 access_level, kal_uint32 msg_index, kal_uint32 module_id, const char *arg_type, va_list argument_info);

extern void dhl_ex_print_impl(trace_class_enum trc_class, kal_uint32 user_flag, module_type mod_id, const char *fmt, va_list argument_info);

/* primitive */
extern void dhl_log_primitive(ilm_struct *ilm);
extern void dhl_log_primitive_without_filter_check(ilm_struct *ilm);
extern void dhl_FT_log_primitive(ilm_struct *ilm);
//extern void dhl_convert_ilm_header(ilm_struct *ilm, dhl_primitive_header_struct *hdr);
#define dhl_convert_ilm_header(_ilm, _hdr) \
{ \
    (_hdr)->local_len = 0; \
    (_hdr)->peer_len = 0; \
    \
    if (!msg_is_inline((_ilm))) { \
    if ((_ilm)->local_para_ptr != NULL) { \
        if (MSG_ID_TIMER_EXPIRY == (_ilm)->msg_id) \
            (_hdr)->local_len = sizeof(timer_expiry_struct); \
        else \
            (_hdr)->local_len = (_ilm)->local_para_ptr->msg_len; \
    } \
    \
    if ((_ilm)->peer_buff_ptr != NULL) { \
        (_hdr)->peer_len = sizeof(peer_buff_struct) + \
                        (_ilm)->peer_buff_ptr->pdu_len + \
                        (_ilm)->peer_buff_ptr->free_header_space + \
                        (_ilm)->peer_buff_ptr->free_tail_space; \
    } \
    \
    } \
    (_hdr)->src_mod_id = (_ilm)->src_mod_id; \
    (_hdr)->dest_mod_id = (_ilm)->dest_mod_id; \
    (_hdr)->sap_id = (_ilm)->sap_id; \
    (_hdr)->msg_id = (_ilm)->msg_id; \
    (_hdr)->local_addr = (kal_uint32)(_ilm)->local_para_ptr; \
    (_hdr)->peer_addr = (kal_uint32)(_ilm)->peer_buff_ptr; \
}


typedef struct {
    kal_uint8 access_type;
    kal_int32 len;
    kal_uint8 *data;
} buf_des;

extern void dhl_log_primitive_impl(kal_uint32 user_flag, dhl_primitive_header_struct *hdr, buf_des *des, kal_int32 count, kal_bool compressed);
extern void dhl_print_primitive(kal_uint32 user_flag, dhl_primitive_header_struct *hdr);
extern void dhl_print_primitive_impl(
        kal_uint32 user_flag,
        dhl_primitive_header_struct *hdr,
        kal_uint8 *local_data,
        kal_int32 local_len,
        kal_uint8 *peer_data,
        kal_int32 peer_len);
extern void dhl_ex_print_primitive(kal_uint32 user_flag, dhl_ex_primitive_header_struct *hdr);

/* layer-1 trace group */
typedef enum {
    UMTS_3G_GEMINI_TIME = 0,
    UMTS_3G_TIME,
    UMTS_2G_GEMINI_TIME,
    UMTS_2G_TIME,
    UMTS_2G_HANDOVER_TIME,
    UMTS_3G_HANDOVER_TIME,
    LTE_4G_TIME = 6,
    LTE_4G_TIME_2 = 7,
    LTE_4G_L2_TIME = 8,
} dhl_l1_time_trace_type;

typedef enum {
    L1_TRACE_LOST_COUNT,
    L1_BUFFER_LOST_COUNT,
    L2_TRACE_LOST_COUNT,
    L2_BUFFER_LOST_COUNT,
} dhl_l1_lost_count_type;

extern kal_bool dhl_log_l1_trace_group(kal_uint32 user_flag, kal_uint16 count, kal_uint8 *buf, kal_uint32 len);
extern kal_bool dhl_log_l2_trace_group(kal_uint32 user_flag, kal_uint16 count, kal_uint8 *buf, kal_uint32 len);
extern kal_bool dhl_log_l1_lost_count(dhl_l1_lost_count_type type, kal_uint8 count);

extern void dhl_ex_log_l1_trace_group(kal_uint32 user_flag, kal_uint16 count, kal_uint8 *buf, kal_uint32 buf_len);
extern void dhl_ex_log_l2_trace_group(kal_uint32 user_flag, kal_uint16 count, kal_uint8 *buf, kal_uint32 buf_len);
extern void dhl_ex_log_l1_lost_count(dhl_l1_lost_count_type type, kal_uint8 count);

#include "adt.h"

/* ADT logging */
extern void dhl_log_primitive_with_adt(ilm_struct *ilm_ptr, translator_adt_enc_callback_t translator_cb, kal_bool filter);

/* ADT inject for UT */
typedef void (*translator_adt_dec_callback_t)(const ilm_struct *ilm_adt_ptr, ilm_struct **ilm_ptr);
kal_bool register_translator_adt_decoder(msg_type msg_id, translator_adt_dec_callback_t cb);
translator_adt_dec_callback_t get_adt_decoder(msg_type msg_id);
kal_bool register_translator_adt_encoder(msg_type msg_id, translator_adt_enc_callback_t translator_cb);
translator_adt_enc_callback_t get_adt_encoder(msg_type msg_id);
        
/* control */
extern void dhl_sync();
extern void dhl_time();

#ifdef UNIT_TEST
void dhl_write_file(kal_bool outgoing, kal_uint8 *data, kal_int32 len);
#endif

#define SYNC_PATTERN_SIZE (4)

typedef enum {
    DHL_CMD_NULL = 0,   
    DHL_CMD_META_REQ_PRIMITIVE = 1,
    DHL_CMD_CHECK_DATABASE_SIGNATURE = 2,

    /* Do NOT change the order of the above command(s) */

    DHL_CMD_SET_PRIM_MOD_FILTER,
    DHL_CMD_SET_PRIM_SAP_FILTER,
    DHL_CMD_SET_TRAP_FILTER,
    DHL_CMD_SET_PS_TRC_FILTER,  
    DHL_CMD_SET_L1_TRC_FILTER,
    DHL_CMD_READ_GLOBAL_VARIABLE,
    DHL_CMD_WRITE_GLOBAL_VARIABLE,
    DHL_CMD_REBOOT_TARGET,
    DHL_CMD_INJECT_ILM,
    DHL_CMD_REDIRECT,   
    DHL_CMD_FT_MODE_CONFIG,
    DHL_CMD_NVRAM,
    DHL_CMD_READ_STACK_STATISTICS,
    DHL_CMD_FILE_TRANSFER,  
    DHL_CMD_FILE_SAVE,
    DHL_CMD_READ_MEMORY_ADDR,
    DHL_CMD_QUERY_MEMORY_RANGE,
    DHL_CMD_WRITE_MEMORY,
    DHL_CMD_QUERY_CTRL_BUF_MONITOR_DATA,
    DHL_CMD_QUERY_FLC_BUF_MONITOR_DATA,
    DHL_CMD_FORCE_ASSERT,
    DHL_CMD_INJECT_ILM_ADT,
    DHL_CMD_MSG_BKPT,
    DHL_CMD_INJECT_STRING_TO_MODULE,
    DHL_CMD_INJECT_AT_CMD,
    DHL_CMD_SIM_FILE_INFO_REQ,
    DHL_CMD_SIM_READ_REQ,
    DHL_CMD_SIM_WRITE_REQ,
    DHL_CMD_SWLA_START,
    DHL_CMD_SWLA_STOP,
    DHL_CMD_SWLA_QUERY_HEADER,
    DHL_CMD_SWLA_EMI_MONITOR_MASTER_SELECT,
    DHL_CMD_VIRTUAL_CHANNEL,
    DHL_CMD_EM_MODE_CONFIG,
    DHL_CMD_SET_TRAP_MSG,
    DHL_CMD_UBDB,
    DHL_CMD_REBOOT_FOR_MMI_AUTO_TEST,
    DHL_CMD_SET_PARTIAL_PRIM_MOD_FILTER,
    DHL_CMD_SET_PARTIAL_PRIM_SAP_FILTER,
    DHL_CMD_SET_PARTIAL_PS_TRC_FILTER,  
    DHL_CMD_SET_PARTIAL_L1_TRC_FILTER,
        DHL_CMD_SET_2G_DSP_FILTER,
  DHL_CMD_ELT_CONNECT,
  DHL_CMD_ELT_DISCONNECT,
  DHL_CMD_LOOP_BACK,
    DHL_CMD_CUSTOM_READ_MEMORY,
    DHL_CMD_CUSTOM_WRITE_MEMORY,    
} dhl_command_type;

typedef dhl_header_struct dhl_cmd_header_struct;

typedef struct {
    dhl_cmd_header_struct hdr;
    kal_uint32 cksum;
    kal_uint8 extra_len;
    kal_uint8 *extra;
    kal_uint16 recv_len;
    kal_uint8 *value;
} dhl_cmd_frame_buffer_struct;

typedef kal_uint8 dhl_cmd_null_struct;

typedef struct {
    kal_uint8   mod_filter[TST_MODULE_FILTER_LEN];
} dhl_cmd_set_prim_mod_filter_struct;

typedef struct {
    kal_uint8   sap_filter[TST_SAP_FILTER_LEN];
} dhl_cmd_set_prim_sap_filter_struct;

typedef struct {
    kal_uint16  sap_id;
    kal_uint8   is_trap;
} dhl_cmd_set_trap_filter_struct;

typedef struct {
    kal_uint16  sap_filter[END_OF_MOD_ID+1];
} dhl_cmd_set_ps_trc_filter_struct;

typedef dhl_cmd_set_ps_trc_filter_struct dhl_test_struct;

typedef kal_uint8 dhl_cmd_set_l1_trc_filter_struct;

typedef struct {
    kal_uint32  gv_name_len;
    kal_char    data[1];
} dhl_cmd_read_global_variable_struct;

typedef kal_uint8 dhl_ind_read_variable_return_struct;

typedef struct {
    kal_uint16      size1;
    kal_uint16      size2;
} dhl_cmd_write_global_variable_struct;

typedef kal_uint8 dhl_cmd_reboot_target_struct;

typedef kal_uint8 dhl_cmd_reboot_for_mmi_auto_test_struct;

typedef struct {
    kal_uint16      no_peer_buff_ptr;
    kal_uint16      peer_buff_ptr_size;
    kal_uint8       *peer_buff_ptr;
    kal_uint8       ref_count;
    kal_uint8       header_len;
    kal_uint8       tail_len;
    kal_uint8       unused1;
} asn_peer_buff_struct;

typedef struct {
    kal_uint8       ref_count;
    kal_uint16      no_local_params_ptr;
    kal_uint16      local_params_ptr_size;
    kal_uint8       *local_params_ptr;
} asn_local_para_struct;

typedef struct {
    module_type     src_mod_id;
    module_type     dest_mod_id;
    sap_type        sap_id;
    msg_type        msg_id;
    asn_local_para_struct   local_params;
    asn_peer_buff_struct    peer_buff;
} ilmessage;

typedef kal_uint8 dhl_cmd_inject_ilm_struct;

typedef struct {
    kal_uint32 src_mod_id;
    kal_uint32 dest_mod_id;
    kal_uint32 sap_id;
    kal_uint32 msg_id;
    kal_uint16 local_len;
    kal_uint16 peer_len;
} dhl_cmd_meta_req_primitive_struct;

typedef struct {
    kal_uint8   virtual_channel_id;
    kal_uint8   pData[1];
} dhl_cmd_redirect_struct;

typedef struct {
    kal_uint8   enable;
} dhl_cmd_ft_mode_config_struct;

typedef enum {
    NVRAM_READ,
    NVRAM_RESET,
    NVRAM_WRITE,
    NVRAM_RESET_FLAG
 // reset stack stats status in NVRAM_EF_SYS_STATISTICS_LID
} nvram_actions; 

typedef struct {
    LOCAL_PARA_HDR
    nvram_actions act;
    kal_uint32  file_id;
} dhl_cmd_nvram_struct;

typedef struct {
    LOCAL_PARA_HDR
} dhl_cmd_read_stack_statistics_struct;

typedef stack_statistics_struct dhl_ind_stack_statistics_struct;

#ifdef L1_SIM
typedef kal_uint8 dhl_ind_nvram_read_cnf_struct;
typedef kal_uint8 dhl_ind_nvram_reset_cnf_struct;
#else
typedef nvram_read_cnf_struct dhl_ind_nvram_read_cnf_struct;
typedef nvram_reset_cnf_struct dhl_ind_nvram_reset_cnf_struct;
#endif

typedef struct {
    kal_uint32 HISR_pair_num;
    kal_char HISR_Name[KAL_MAX_NUM_HISRS * STACK_STATS_HISR_MAX_NAME];
} dhl_HISR_name_struct;

typedef struct {
    stack_statistics_struct statistic;
    dhl_HISR_name_struct hisr_name_struct;
} dhl_nvram_statistics_struct;

typedef dhl_nvram_statistics_struct tst_stack_statistics_struct;

typedef struct {
    kal_uint32  token;
    kal_uint32  start_address; //if 0xFFFFFFFF => to delete the file
    kal_uint32  buf_length;
    kal_uint8   buf[1]; // full path
} dhl_cmd_file_transfer_struct;

typedef struct {
    kal_uint32  time_stamp;
    kal_uint32  token;
    kal_uint32  start_address;//0xFFFFFFFF , to delete the file
    kal_uint32  path_length;
    kal_uint32  data_length; //0: end-of-file or file deleted    
} dhl_ind_file_transfer_report_struct;

typedef enum {
  DHL_FS_DELETE_FILE = -1,
  DHL_FS_ALWAYS_CREATE,
  DHL_FS_APPEND_END,
  DHL_FS_SEEK_AND_APPEND
} dhl_file_save_action_t;

typedef struct {
    kal_uint32 token;
    dhl_file_save_action_t action;  //0: create, 1: append to the end, 2. open and append the seek pos, 0xFFFFFFFF: delete
    kal_int32 seek_pos;  
    kal_uint32 data_len;  //the total length of data[1] array
    kal_uint32 content_offset;  //the offset of file content start in the data[1] array
    kal_uint8 data[1];  //file path name and file content segment
} dhl_cmd_file_save_struct;

typedef struct {  
  kal_uint32 token;
  kal_uint32 action;  //0: create, 1: append to the end, 2. open and append the seek pos, 0xFFFFFFFF: delete
  kal_uint32 fill_data_len;  
} dhl_ind_file_save_report_struct;

typedef enum {
  DHL_READ_MEMORY_ACCESS_TYPE_NOT_SPECIFIED = 0,
  DHL_READ_MEMORY_ACCESS_TYPE_BYTE = 1,
  DHL_READ_MEMORY_ACCESS_TYPE_HALF_WORD = 2,
  DHL_READ_MEMORY_ACCESS_TYPE_WORD = 4
} dhl_read_memory_access_type;

typedef struct {
    kal_uint8   token;  
    kal_uint8   reserved;
    kal_uint16  chunk_size;
    void        *address;
    kal_uint32  length;
    kal_uint32  mem_type;  
    dhl_read_memory_access_type  access_type;
} dhl_cmd_read_memory_addr_struct;

typedef struct {
    kal_uint8   token;
    kal_uint8   encoded; //0 for not encoded, 1 for encoded with RLE
    const void  *address;
    kal_uint32  length;
    kal_uint32 mem_type;    
    dhl_read_memory_access_type access_type;
} dhl_ind_read_memory_report_struct;

// redefine structure for ELT decode MSG_ID_DHL_AUTO_MEMORY_DUMP_IN_ILM.
typedef dhl_ind_read_memory_report_struct dhl_auto_memory_dump_in_ilm_struct;

typedef kal_uint8 dhl_cmd_query_memory_range_struct;

typedef struct {
    kal_uint32 mem_type_num;
    kal_uint8 token;
    kal_bool last;
} dhl_ind_query_memory_range_struct;

typedef struct {
    void        *address;
    kal_uint32  length;
    kal_uint8   data[1];
} dhl_cmd_write_memory_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint32  token;  
} dhl_cmd_query_ctrl_buf_monitor_data_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint32  token;  
} dhl_cmd_query_flc_buf_monitor_data_struct;

typedef struct {
    kal_uint32  token;
    kal_uint32  ack_type; //0: ctrl buffer, 1: flc buffer    
} dhl_ind_query_buf_monitor_report_struct;

typedef enum {
    MSG_BKPT_SET = 0,
    MSG_BKPT_CLR,   
    MSG_BKPT_RESUME,
    MSG_BKPT_CLR_ALL,
    MSG_BKPT_CONFIG_MODE,
} dhl_msg_bkpt_action;

typedef enum {
    MSG_BKPT_CONFIG_SENDER_HOLD = 0,
    MSG_BKPT_CONFIG_RECEIVER_HOLD,
    MSG_BKPT_CONFIG_SENDER_BREAK,
    MSG_BKPT_CONFIG_RECEIVER_BREAK,
    MSG_BKPT_CONFIG_BUFFER,
    MSG_BKPT_CONFIG_SINGLE,
} dhl_msg_bkpt_config;

typedef struct _dhl_cmd_msg_bkpt {
    dhl_msg_bkpt_config config;
    module_type     src_mod_id;
    module_type     dest_mod_id;    
    msg_type        msg_id;
    struct _dhl_cmd_msg_bkpt *next;
} dhl_cmd_msg_bkpt;

typedef struct {
    LOCAL_PARA_HDR
    dhl_msg_bkpt_action action;
    dhl_msg_bkpt_config config;
    module_type     src_mod_id;
    module_type     dest_mod_id;    
    msg_type        msg_id;
} dhl_cmd_msg_bkpt_struct;

typedef enum {
    MSG_BREAK_SENDER_HOLD = 0,
    MSG_BREAK_RECEIVER_HOLD,
    MSG_BREAK_SENDER_BREAK,
    MSG_BREAK_RECEIVER_BREAK,
    MSG_BREAK_SINGLE_STEP,
} dhl_msg_break_type;

typedef struct {
    LOCAL_PARA_HDR
    dhl_msg_break_type type;
    module_type src_mod_id;
    module_type dest_mod_id;
    msg_type msg_id;    
} dhl_dbg_msg_break_struct;

typedef dhl_dbg_msg_break_struct dhldbg_msg_break_struct;

typedef struct {
    LOCAL_PARA_HDR
    module_type dest_mod;
    kal_uint8 index;
    kal_uint8 string[INJECT_STRING_TO_MODULE_MAX_LENGTH];
} dhl_cmd_inject_string_to_module_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 atcmd[INJECT_AT_COMMAND_MAX_LENGTH];
} dhl_cmd_inject_at_cmd_struct;

typedef struct {
    kal_uint32 sim_num;
    kal_uint16 file_idx;
    kal_uint8 file_path[6];
} dhl_cmd_sim_file_info_req_struct;

typedef struct {
    kal_uint32 sim_num;
    kal_uint16 file_idx;
    kal_uint16 para;
    kal_uint16 length;
    kal_uint8 file_path[6];
} dhl_cmd_sim_read_req_struct;

typedef struct {
    kal_uint32 sim_num;
    kal_uint16 file_idx;
    kal_uint16 para;
    kal_uint8 data[260];
    kal_uint16 length;
    kal_uint8 file_path[6];
} dhl_cmd_sim_write_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint32 token;
    kal_bool enable;
} dhl_cmd_swla_start_struct;

typedef dhl_cmd_swla_start_struct dhl_cmd_swla_stop_struct;

typedef struct {
    kal_uint32 token;
    dhl_command_type ack_cmd_type;
    kal_uint32 return_code;
    kal_uint32 is_cmd_msg;
    msg_type ack_cmd_msg_id;
} dhl_ind_general_query_cmd_ack_struct;

typedef kal_uint8 dhl_cmd_swla_query_header_struct;

typedef struct {
    kal_uint32 main_desc_len;
    kal_uint32 addon_desc_len;
    kal_uint32 init_blk_len;
} dhl_ind_swla_query_header_report_struct;

#define DHL_SWLA_EMI_MONITOR_MASTER_NUM (3)
typedef struct {
    LOCAL_PARA_HDR
    kal_uint16 master_select[DHL_SWLA_EMI_MONITOR_MASTER_NUM];
} dhl_cmd_swla_emi_monitor_master_select_cmd_struct;

typedef struct {
    kal_uint8 channel_id;
    kal_uint8 pData[1];
} dhl_cmd_virtual_channel_struct;

typedef struct {
    kal_uint8 channel_id;
} dhl_ind_virtual_channel_struct;

typedef struct {
#ifdef __EM_MODE__
    em_info_status_enum  info_request[NUM_OF_EM_INFO];
    kal_uint32 sim_selection;   //Accompanied with one option in Catcher_Version_Info_Enum (CATCHER_EM_MULTIPLE_SIM_ENABLE)
#else   //#ifdef __EM_MODE__
    //The reason we keep the old declaration here is that we don't want to change the order of tst_command_type
    //MLT uses the flake database
    kal_uint8 enable;
#endif  //#ifdef __EM_MODE__
} dhl_cmd_em_mode_config_struct;

typedef struct {
    kal_uint16 nCount;
    kal_uint16 MsgIDs[1];
} dhl_cmd_set_trap_msg_struct;

typedef struct {
    kal_uint8 token;
    kal_uint8 command; //0: db_reset, 1:db_write, 2:db_read, 3:db_delete
                       //4: db_snap, 5:db_exist
    kal_uint16 length;
    kal_uint8 sim_num;
    kal_uint8 buf[1];
} dhl_cmd_ubdb_struct;

typedef struct {
    kal_uint8 token;
    kal_uint8 command;
    kal_uint16 length;
} dhl_ind_ubdb_struct;

//MSG_ID_TST_R8_DL_PKT_SINGLE_GPD_IND
typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint32 trace_id;
   sap_type raw_data_sap;
   kal_uint16 offset;
} tst_r8_dl_pkt_single_gpd_ind_struct;

typedef struct {
  LOCAL_PARA_HDR
  kal_uint8 token;
  //ST_input_struct
  kal_int32 trace_time_scale;
  kal_bool all_task; 
  kal_bool trace_register;
  kal_bool trace_call_stack;
  kal_bool trace_data; 
  kal_int32 task_filter[6];
  kal_int32 trace_stack_size;
  kal_int32* data_address[16];
  kal_int32 reserved[16];
} dhl_cmd_st_start_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 token;
} dhl_cmd_st_stop_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 token;
} dhl_cmd_st_query_header_struct;

typedef struct
{   
    kal_uint8 token;
  kal_uint32  time_stamp;
  //ST_return_struct
  kal_int32 start_time1;
  kal_int32 start_time2;
  kal_int32* buffer_start_addr;
  kal_int32* buffer_end_addr;
  kal_int32* buffer_current_index_addr;
  kal_int32 time_scale_for_one_sec;
  kal_int32 reserved[4];
  kal_bool buffer_wrap_around;
} dhl_cmd_st_stop_report_struct;

typedef struct {
  void  *m_Addr;
  kal_uint16  m_Value;
} dhl_2g_dsp_filter_setting;

typedef struct
{   
  kal_uint32  count;
  dhl_2g_dsp_filter_setting* filter;
} dhl_cmd_set_2g_dsp_filter_struct;

typedef enum {
  TST_GPD_LOG_GPD_TYPE=0,
  TST_GPD_LOG_BD_TYPE,
  TST_GPD_LOG_RAW_TYPE,
  TST_GPD_LOG_LAST_TYPE,
} tst_gpd_log_type_t;

typedef enum {
    DHL_DRV_DETACH,
    DHL_DRV_ATTACH,
    DHL_DRV_INIT,
} dhl_drv_state;

typedef struct {
    LOCAL_PARA_HDR
    DCL_HANDLE handle;
    dhl_drv_state state;
} dhl_driver_state_change_struct;

typedef struct {
    LOCAL_PARA_HDR
    DCL_HANDLE handle;
    tty_io_request_t *ior;
} dhl_tty_rx_done_struct;

typedef struct
{
   LOCAL_PARA_HDR
}
tst_l2copro_filter_retrieval_struct;

typedef struct
{
   LOCAL_PARA_HDR
}
tst_l2copro_filter_save_struct;

typedef struct {
    kal_uint32 count;
} dhl_cmd_set_partial_prim_mod_filter_struct;

typedef struct {
    kal_uint32 count;
} dhl_cmd_set_partial_prim_sap_filter_struct;

typedef struct {
    kal_uint32 count;
} dhl_cmd_set_partial_ps_trc_filter_struct;

typedef struct {
    kal_uint32 count;
} dhl_cmd_set_partial_l1_trc_filter_struct;

typedef enum {
    DHL_MUX_ID_MCU_CODE_BEGIN = 0, DHL_MUX_ID_MCU_CODE_TAIL = 2,
    DHL_MUX_ID_DSP_CODE_BEGIN = 3, DHL_MUX_ID_DSP_CODE_TAIL = 127,
    DHL_MUX_ID_HW_CODE_BEGIN = 128, DHL_MUX_ID_HW_CODE_TAIL = 255,
    DHL_MUX_ID_END = 256,
} dhl_mux_id_range;

#define DHL_MUX_FILTER_LEN 32

typedef enum {
    DHL_MUX_ID_MCU = 0,
    DHL_MUX_ID_MCU_ASM = 1,
    DHL_MUX_ID_DSP_FMC_1 = DHL_MUX_ID_DSP_CODE_BEGIN,
    DHL_MUX_ID_DSP_FMC_2,
    DHL_MUX_ID_DSP_FNC_1,
    DHL_MUX_ID_DSP_FNC_2,
    DHL_MUX_ID_DSP_BC_1,
    DHL_MUX_ID_DSP_BC_2,
    DHL_MUX_ID_DSP_MC_1,
    DHL_MUX_ID_DSP_MC_2,
    DHL_MUX_ID_DSP_MMC_1,
    DHL_MUX_ID_DSP_MMC_2,
    DHL_MUX_ID_DSP_MSC_1,
    DHL_MUX_ID_DSP_MSC_2,
    DHL_MUX_ID_DSP_MD32_1,
    DHL_MUX_ID_DSP_MD32_2,  
    DHL_MUX_ID_DSP_CODE_END = DHL_MUX_ID_DSP_MD32_2,
    DHL_MUX_ID_HW_IRDBG = DHL_MUX_ID_HW_CODE_BEGIN, 
    DHL_MUX_ID_NO_MUX = 255
} dhl_mux_id;

#define DHL_MUXID_NUM 17

typedef struct {
    kal_uint32 bytes_sent;
    kal_uint32 last_update;
} dhl_trace_stats;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 select[DHL_MUX_FILTER_LEN];
    kal_uint8 value[DHL_MUX_FILTER_LEN];
} dhl_cmd_set_dhl_mux_filter_struct;

typedef enum
{
  DHL_PORT_NULL,
  DHL_PORT_UART,
  DHL_PORT_USB,
  DHL_PORT_SP,
  DHL_PORT_OTHER
} DHL_PORT_SETTING;

//Generic memory dump definitions
#if defined(GEN_FOR_PC)
  #define Define_TST_Mem_Dump_Type_Start() typedef enum {
  #define Define_TST_Mem_Dump_Type_Item(type, string, length) string##__size__##length,
  #define Define_TST_Mem_Dump_Type_End()   tst_mem_type_string_end} tst_mem_type_string_enum;
#else
  #define Define_TST_Mem_Dump_Type_Start() typedef enum {
  #define Define_TST_Mem_Dump_Type_Item(type, string, length) type,
  #define Define_TST_Mem_Dump_Type_End()   tst_mem_type_end} tst_mem_type_enum;
#endif 

typedef enum {
  INIT_CMDS_RESEND_EXCEPTION_INFO = 0,
  INIT_CMDS_MEMORY_DUMP_SWITCH,
  INIT_CMDS_QUERY_SWLA_HEADER,
  INIT_CMDS_QUERY_TARGET_VERSION,
  INIT_CMDS_ECHO_SIM_MAPPING,
  INIT_CMDS_QUERY_LOAD_VERSION,
  INIT_CMDS_QUERY_CALIBRATION,
  INIT_CMDS_QUERY_SWLA_INFO,
  INIT_CMDS_QUERY_SWTR_HEADER,
  INIT_CMDS_MAX = 31,
} dhl_init_cmd_set_enum_type;

typedef enum {
  DISCONNECT_CMDS_MEMORY_DUMP_SWITCH = 0,
  DISCONNECT_CMDS_MAX = 31,
} dhl_disconnect_cmd_set_enum_type;

typedef struct {
  kal_uint32 init_cmds;
} dhl_cmd_elt_connect_struct;

typedef struct {
  kal_uint32 disconnect_cmds;
} dhl_cmd_elt_disconnect_struct;

typedef struct {
  kal_uint32 token;
  kal_uint32 data_len;
  kal_uint8  data[1];
} dhl_cmd_loop_back_struct;

typedef struct {
  kal_uint32 token;
} dhl_cmd_loop_back_response_struct;

#define DATABASE_SIGNATURE_MAGIC (0x24541605)
#define DATABASE_SIGNATURE_MAX_LENGTH (64)
typedef struct {
    kal_uint32 magic;
    kal_uint32 length;
    kal_uint8 data[DATABASE_SIGNATURE_MAX_LENGTH];
} dhl_cmd_check_database_signature_struct;

typedef enum {
    QUERY_FAIL,
    QUERY_CONTINUE,
    QUERY_END
} query_mem_range_result;

typedef enum 
{
  MEM_SYS, 
  MEM_DSP,
  MEM_SLA,
  MEM_CSDSP, 
#if defined(__AST_TL1_TDD__)
  MEM_AST,
#endif  
  MEM_BB,
  MEM_TYPE_END,
} DHL_MEM_TYPE;

Define_TST_Mem_Dump_Type_Start()
Define_TST_Mem_Dump_Type_Item(default_type, default, 0xFFFFFFFF)
Define_TST_Mem_Dump_Type_Item(tst_system_mem_type, sys_mem, 0xFFFFFFFF)
Define_TST_Mem_Dump_Type_Item(tst_dsp_mem_type, dsp_mem, 0xFFFFFFFF)
Define_TST_Mem_Dump_Type_Item(tst_bb_mem_type, bb_reg, 0xFFFFFFFF)
Define_TST_Mem_Dump_Type_Item(tst_swla_mem_type, swla, 0xFFFFFFFF)
Define_TST_Mem_Dump_Type_Item(dhl_coresonic_mem_type, coresonic_mem, 0xFFFFFFFF)
#if defined(__AST_TL1_TDD__) && !defined(UNIT_TEST)
  Define_TST_Mem_Dump_Type_Item(tst_ast_mem_type, ast_mem, 0x400)
#endif  
Define_TST_Mem_Dump_Type_End()

typedef struct {
    kal_uint8   token;  
    kal_uint8   reserved;
    kal_uint16  chunk_size;
    void        *address;
    kal_uint32  length;
    DHL_CUSTOM_MEM_TYPE     custom_mem_type;  
    kal_uint32  custom_option;
} dhl_cmd_custom_read_memory_struct;

typedef struct {
    kal_uint8   token;
    void  *address;
    kal_uint32  length;
    DHL_CUSTOM_MEM_TYPE     custom_mem_type;    
    kal_uint32  custom_option;    
} dhl_ind_custom_read_memory_report_struct;

typedef struct {
    void        *address;
    kal_uint32  length;
    DHL_CUSTOM_MEM_TYPE     custom_mem_type;  
    kal_uint32  custom_option;
} dhl_cmd_custom_write_memory_struct;

#endif
