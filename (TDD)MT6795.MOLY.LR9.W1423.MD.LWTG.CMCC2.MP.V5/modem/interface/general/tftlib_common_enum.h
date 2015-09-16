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
 *   tftlib_common_enum.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   TFT library common enum & define constants
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
 * [ESM/TFTLIB] Modification fot "TFT validate" and "PS init deactivation"
 *
 * removed!
 * removed!
 * [TFTLIB] Modify compile options for GEMINI (tweak)
 *
 * removed!
 * removed!
 * [TFTLIB] Modify compile options for GEMINI
 *
 * removed!
 * removed!
 * TFTLIB check-in related interface
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * [TFTLIB] Check-in related changes
 *
 * removed!
 * removed!
 * [TFTLIB] Check-in related changes
 *
 * removed!
 * removed!
 * Check-in TFTLIB part
 *
 * removed!
 * removed!
 * 	Check-in TFTLIB part
 *
 * removed!
 * removed!
 * check in TFTLIB related change
 *
 * removed!
 * removed!
 * [TFTLIB] checkin missing header file
 *
 * removed!
 * removed!
 * drop corrupted fragment v6 packet.
 *
 * removed!
 * removed!
 * add trace error/warning & work around
 *
 * removed!
 * removed!
 * TFTLIB modification for AT+CGTFT interpretation (support both difference set & full set)
 *
 * removed!
 * removed!
 * TFTLIB part check-in
 *
 * removed!
 * removed!
 * [TFTLIB] revise trace
 *
 * removed!
 * removed!
 * [MT6290][TFTLIB] update TFT parameter list with new structure
 *
 * removed!
 * removed!
 * Rename MT7208 to MT6290 in CR title.
 *
 * removed!
 * removed!
 * TFTLIB merge from PreIT to MOLY trunk
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * [Joe] TFTLIB part is check in done.
 ****************************************************************************/


#ifndef TFTLIB_COMMON_ENUM_H_
#define TFTLIB_COMMON_ENUM_H_



/* Common define constant */

#define MAX_PACKET_FILTER_NUM                  16   // This number is defined in 3GPP, TS 24.008, 10.5.6.12
#define MAX_PACKET_FILTER_NUM_IN_TRANSACTION   15   // This number is defined in 3GPP, TS 24.008, 10.5.6.12
#define MAX_PACKET_FILTER_NUM_SUPPORT_BY_NW    16   // TODO: Modify this to global variable, which can be run-time adjusted
#define MIN_PACKET_FILTER_ID                    0
#define MAX_PACKET_FILTER_ID                   15

#define MAX_PACKET_FILTER_PRECED_NUM          256
#define MIN_PACKET_FILTER_PRECED_IDX            0
#define MAX_PACKET_FILTER_PRECED_IDX          255

#define MAX_REMOTE_ADDR_AND_MASK_LEN           32
#define MAX_TFT_LEN                           255
#define PACKET_FILTER_ID_LEN                    1

#define TFTLIB_MIN_BEARER_ID                    5
#define TFTLIB_MAX_BEARER_ID                   15
#define TFTLIB_MAX_BEARER_ID_TOTAL_NUM         16
#define TFTLIB_MAX_BEARER_CTXT_NUM             11

#define TFTLIB_SIM_DONT_CARE                    0xFF
#if defined(__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
#define TFTLIB_SIM1                             0
#define TFTLIB_SIM2                             1
#if (GEMINI_PLUS >= 3) || defined(__SGLTE_DSDS__)
#define TFTLIB_SIM3                             2
#endif /* GEMINI_PLUS >= 3 || __SGLTE_DSDS__ */
#if (GEMINI_PLUS >= 4)
#define TFTLIB_SIM4                             3
#endif /* GEMINI_PLUS >= 4 */
#endif /* (__SGLTE__) || (__GEMINI__) */


/* Packet filter component length (octet) define */

#define IPV4_REMOTE_ADDR_AND_MASK_LEN                   8
#define IPV6_REMOTE_ADDR_AND_MASK_LEN                  32
#define PROTOCOL_ID_NEXT_HEADER_LEN                     1
#define SINGLE_LOCAL_PORT_LEN                           2
#define LOCAL_PORT_RANGE_LEN                            4
#define SINGLE_REMOTE_PORT_LEN                          2              
#define REMOTE_PORT_RANGE_LEN                           4
#define SECURITY_PARAMETER_ID_LEN                       4
#define TYPE_OF_SERVICE_TRAFFIC_CLASS_AND_MASK_LEN      2
#define FLOW_LABEL_LEN                                  3


/* Parameter list define */

#define MAX_AUTHTOKEN_FLOWID_NUM                4       // temp max num (TS 24.008 10.5.162 does not restrict its max number...)
#define MAX_PARAMETER_LIST_NUM                 16
#define MAX_PARAMETER_LIST_SIZE               255
#define MAX_AUTHORIZATION_TOKEN_LEN            16       // temp max length (it could be very long...)
#define MAX_FLOW_IDENTIFIER_NUM                 4       // temp max num (TS 24.008 10.5.162 does not restrict its max number...)
#define FLOW_IDENTIFIER_LEN                     4


/* Temp define constant */

#define MAX_PF_COMP_TYPE_NUM                   15
#define MAX_PACKET_FILTER_CONTENT_LEN          47
#define MAX_TFT_PDU_ENCODE_LEN                 1500


/* define constants for BITMAP */

#define BMP_NONE               0x00000000
#define BMP_V4_ADDR            0x00000001
#define BMP_V6_ADDR            0x00000002
#define BMP_PROTOCOL           0x00000004
#define BMP_LOCAL_PORT_SINGLE  0x00000008
#define BMP_LOCAL_PORT_RANGE   0x00000010
#define BMP_REMOTE_PORT_SINGLE 0x00000020
#define BMP_REMOTE_PORT_RANGE  0x00000040
#define BMP_SPI                0x00000080
#define BMP_TOS                0x00000100
#define BMP_FLOW_LABEL         0x00000200
#define BMP_EMPTY_TCP_ACK      0x80000000
#define BMP_IP_FRAGMENT        0x40000000
#define BMP_CORRUPTED          0x20000000



/* enum declaration */

typedef enum {
    TFT_CTXT_TYPE_USER_DEFINED = 0,
    TFT_CTXT_TYPE_APPLIED,
    TFT_CTXT_TYPE_ALL
} tft_ctxt_type_enum;


typedef enum {
    TFT_PROC_DIR_NONE = 0,  // 0x00
    TFT_PROC_DIR_MO,        // 0x01
    TFT_PROC_DIR_MT,        // 0x02
} tft_proc_dir_enum;


typedef enum {
    TFT_BEARER_NO_ACTION = 0,  // 0x00
    TFT_BEARER_ACTIVATION,     // 0x01
    TFT_BEARER_MODIFICATION,   // 0x02
    TFT_BEARER_DEACTIVATION    // 0x03
} tft_bearer_act_enum;


typedef enum {
    TFT_CHECK_PASS = 1,                        // (0x01) Validate pass
    TFT_CHECK_FAILED_SEMANTIC_ERROR_IN_TFT,    // (0x02) Validate error, SM/ESM should reject the procedure with cause "Semantic errors in TFT operations (#41)"
    TFT_CHECK_FAILED_SYNTACTICAL_ERROR_IN_TFT, // (0x03) Validate error, SM/ESM should reject the procedure with cause "Syntactical errors in TFT operations (#42)"
    TFT_CHECK_FAILED_SEMANTIC_ERROR_IN_PF,     // (0x04) Validate error, SM/ESM should reject the procedure with cause "Semantic errors in packet filters (#44)"
    TFT_CHECK_FAILED_SYNTACTICAL_ERROR_IN_PF,  // (0x05) Validate error, SM/ESM should reject the procedure with cause "Syntactical errors in packet filters (#45)"
    TFT_CHECK_FAILED_BCM_VIOLATION             // (0x06) Validate error, SM should reject the procedure with cause "Bearer Control Mode violation (#48)"
} tft_validate_result_enum;


typedef enum
{
    PF_ACT_NONE         = 0,
    PF_ACT_ADD          = 1,
    PF_ACT_MOD          = 2,
    PF_ACT_DEL          = 3,
    PF_ACT_DEL_ALL      = 4,
    PF_ACT_DEL_BEARER   = 5
}pkt_filter_act_enum;


typedef enum
{
    PF_DIRECTION_PRE_REL7_TFT = 0x00,
    PF_DIRECTION_DL_ONLY      = 0x01,
    PF_DIRECTION_UL_ONLY      = 0x02,
    PF_DIRECTION_BIDIRECTION  = 0x03,
}pf_direction_enum;


typedef enum
{
    PF_OWN_ENTITY_NONE = 0,
    PF_OWN_ENTITY_UE,
    PF_OWN_ENTITY_NW
}pf_own_entity_enum;


typedef enum {
    TFT_OPCODE_SPARE = 0,       // (0x00) Spare
    TFT_OPCODE_CREATE_NEW_TFT,  // (0x01) Create new TFT
    TFT_OPCODE_DELETE_TFT,      // (0x02) Delete existing TFT
    TFT_OPCODE_ADD_PF,          // (0x03) Add packet filters to existing TFT
    TFT_OPCODE_REPLACE_PF,      // (0x04) Replace packet filters in existing TFT
    TFT_OPCODE_DELETE_PF,       // (0x05) Delete packet filters from existing TFT
    TFT_OPCODE_NOTFT_OP,        // (0x06) No TFT operation
    TFT_OPCODE_RESERVED         // (0x07) Reserved
} tft_operation_enum;


typedef enum {
    PF_COMP_ID_IPV4_REMOTE_ADDR                 = 0x10,
    PF_COMP_ID_IPV6_REMOTE_ADDR                 = 0x20,
    PF_COMP_ID_PROTOCOL_ID_NEXT_HEADER          = 0x30,
    PF_COMP_ID_SINGLE_LOCAL_PORT                = 0x40,
    PF_COMP_ID_LOCAL_PORT_RANGE                 = 0x41,
    PF_COMP_ID_SINGLE_REMOTE_PORT               = 0x50,
    PF_COMP_ID_REMOTE_PORT_RANGE                = 0x51,
    PF_COMP_ID_SECURITY_PARAMETER_ID            = 0x60,
    PF_COMP_ID_TYPE_OF_SERVICE_TRAFFIC_CLASS    = 0x70,
    PF_COMP_ID_FLOW_LABEL                       = 0x80

} pf_comp_id_enum;


typedef enum {
    TFT_PARA_LIST_ID_UNDEFINED    = 0x00,   // (0x00) Undefined (not defined in spec 24.008)
    TFT_PARA_LIST_ID_AUTH_TOKEN   = 0x01,   // (0x01) Authorization token
    TFT_PARA_LIST_ID_FLOW_ID      = 0x02,   // (0x02) Flow identifier 
    TFT_PARA_LIST_ID_PF_ID        = 0x03    // (0x03) Packet filter identifier
} tft_para_list_id_enum;

typedef enum {
    BEARER_TYPE_UNKNOWN = 0,
    BEARER_TYPE_PRIMARY_PDP,        // (2G/3G) PRIMARY PDP CONTEXT
    BEARER_TYPE_SECONDARY_PDP,      // (2G/3G) SECONDARY PDP CONTEXT
    BEARER_TYPE_DEFAULT_BEARER,     // (LTE)   DEFAULT EPS BEARER
    BEARER_TYPE_DEDICATED_BEARER    // (LTE)   DEDICATED EPS BEARER
} bearer_type_enum;


typedef enum {
    RAT_IND_2G3G = 1,   // 0x01
    RAT_IND_LTE         // 0x02
} rat_ind_enum;


typedef enum {
    TFT_COMPOSE_TYPE_NONE = 0,      // Reserved value
    TFT_COMPOSE_TYPE_MOD_TFT,       // Only TFT is requested to be modified
    TFT_COMPOSE_TYPE_MOD_QOS,       // Only QoS is requested to be modified
    TFT_COMPOSE_TYPE_MOD_TFT_QOS,   // Both TFT and QoS are requested to be modified
    TFT_COMPOSE_TYPE_UNDEFINE_TFT,  // TFT is requested to be undefined (deleted)
    TFT_COMPOSE_TYPE_DEL_EPSB       // [LTE only] Dedicated EPS bearer is requested to be deactivated
} tft_compose_type_enum;






/* DHL trace use */

typedef enum {
    TFTLIB_TFT_DECODE = 0,
    TFTLIB_TFT_ENCODE,
    TFTLIB_TFT_DIR_EXTRACT,
    TFTLIB_SET_APPLIED_TFT,
    TFTLIB_COMPOSE_TFT_TO_NW,
    TFTLIB_DEL_TFT,
    TFTLIB_GET_USER_DEFINED_TFT,
    TFTLIB_GET_APPLIED_TFT,
    TFTLIB_SET_USER_DEFINED_TFT,
    TFTLIB_SET_USR_DELPF,
    TFTLIB_GET_USR_DELPF,
    TFTLIB_CLEAR_USR_DELPF,
    TFTLIB_SET_USR_LNKPF,
    TFTLIB_GET_USR_LNKPF,
    TFTLIB_CLEAR_USR_LNKPF,
    UPDATE_TFT,
    TFT_DECODE,
    TFT_ENCODE,
    PF_CONTENT_DECODE,
    TFT_COMPOSE,
    PF_FIELD_CHECK,
    PF_COMP_CHECK,
    TFT_EMPTY_COLLISION_CHECK,
    PF_PRECEDENCE_COLLISION_CHECK,
    COMPOSE_PF_ACT_LIST,
    COMPOSE_BEARER_DEACT_LIST,
    BCM_RESTRICT_CHK
} tftlib_trc_func_name_enum;


typedef enum {
    TFT_PTR = 0,
    TFT_RAW_PTR,
    PF_ACT_LIST,
    DEACT_BEARER_LIST,
    COMPOSED_TFT_PTR
} tftlib_trc_func_arg_name_enum;


typedef enum {
    SOURCE_TFT = 0,
    SOURCE_TFT_RAW,
    DECODED_TFT,
    ENCODED_TFT_RAW,
    COMPOSED_TFT,
    EXTRACTED_TFT,
    CURRENT_USER_DEFINED_TFT,
    UPDATED_USER_DEFINED_TFT,
    CURRENT_APPLIED_TFT,
    UPDATED_APPLIED_TFT,
    USER_REQUEST_CGTFT
} tftlib_trc_tft_type_enum;

typedef enum {
    TFTLIB_TRC_PARA_TYPE_NONE = 0,
    TFTLIB_TRC_PARA_TYPE_FUNC_ARG_IN,
    TFTLIB_TRC_PARA_TYPE_FUNC_ARG_OUT,
    TFTLIB_TRC_PARA_TYPE_INTERNAL_FUNC_ARG_OUT,
    TFTLIB_TRC_PARA_TYPE_TFT_CONTEXT
} tftlib_trc_para_type_enum;

#endif /* TFTLIB_COMMON_ENUM_H_ */
