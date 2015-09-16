/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 * Filename:
 * ------------
 *   ims_common_def.h
 *
 * Project:
 * ------------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file defines structures and enums commonly used by IMC, IMSP, and xDM.
 *
 * Author:
 * -----------
 * -------
 *
 *===========================================================
 * $Log$
 *
 * removed!
 * removed!
 * 	IMS MO call timeout trigger call retry on CS domain - VDM TRK part
 *
 * removed!
 * removed!
 * 	link to ALPS01634796
 *
 * removed!
 * removed!
 * MMIVT2MP6
 *
 * removed!
 * removed!
 * Integration change for 504 cause
 *
 * removed!
 * removed!
 * 504 cause
 *
 * removed!
 * removed!
 * SRVCC cause mapping to error report
 *
 * removed!
 * removed!
 * Add SRVCC cause
 *
 * removed!
 * removed!
 * check-in SRVCC R10 feature for IMC and /modem_interface/ims
 *
 * removed!
 * removed!
 * Fix build error.
 *
 * removed!
 * removed!
 * change IMS reg state enum
 *
 * removed!
 * removed!
 * AT+CDU=0 feature in
 *
 * removed!
 * removed!
 * Add IMC handle for ads ctrl to VDM
 *
 * removed!
 * removed!
 * Add ads_ctrl message to VDM for Test Mode
 *
 * removed!
 * removed!
 * SS phase2 conferce call check-in
 * for IMCB pre-checkin (if failed the Basic IT, it will be rollback)
 *
 * removed!
 * IMSP.
 *
 * removed!
 * removed!
 * IMS enable/disable feature-in for IMC related part
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * pre-checkin ims_dereg_cause_enum
 *
 * removed!
 * removed!
 * IMC merge code v1, sync to Ben's CBR CL: 258323
 *****************************************************************************/

#ifndef _IMS_COMMON_DEF_H_
#define _IMS_COMMON_DEF_H_

#include "kal_general_types.h"
#include "kal_public_defs.h"

// To use some enums such as ue_mode_enum, voice_domain_preference_enum, ...
#include "l3_inc_enums.h"
#include "ps_public_enum.h"

/******************************************************************************
 *                              Constant
 *****************************************************************************/

#define MAX_CC_ATD_NUM_LEN          81
#define MAX_CC_CDU_URI_LEN          MAX_CC_ATD_NUM_LEN
#define MAX_CC_ECPI_NUM_LEN         MAX_CC_ATD_NUM_LEN
#define MAX_CC_EAIC_NUM_LEN         MAX_CC_ATD_NUM_LEN

#define IMS_MAX_CALL_NUM            7
#define IMS_P_ASSERT_URI_LEN        512

#define MAX_SS_NOTIFY_DATA_LEN      512

#define IMC_SMS_SUCCESS (1)
#define IMC_SMS_FAIL    (0)
/******************************************************************************
 *                               Enum
 *****************************************************************************/

typedef enum
{
    IMS_RAT_TYPE_2G = 0,
    IMS_RAT_TYPE_3G_FDD,
    IMS_RAT_TYPE_3G_TDD,
    IMS_RAT_TYPE_4G_FDD,
    IMS_RAT_TYPE_4G_TDD
} ims_rat_type_enum;

typedef enum
{
    IMS_RCODE_OK,
    IMS_RCODE_CONNECT,
    IMS_RCODE_RING,
    IMS_RCODE_NO_CARRIER,        //3
    IMS_RCODE_ERROR,             //4
    IMS_RCODE_BUSY = 7,

    /* Below are MTK proprietary result codes */
    IMS_RCODE_CONNECT_PS = 100,

    /* Below are result codes added for IMS */

} ims_result_code_enum;

typedef enum
{
    IMS_ERR_PHONE_FAILURE = 0,
    IMS_ERR_OPERATION_NOT_ALLOWED_ERR = 3,
    IMS_ERR_OPERATION_NOT_SUPPORTED = 4,
    IMS_ERR_PH_SIM_PIN_REQUIRED = 5,
    IMS_ERR_PH_FSIM_PIN_REQUIRED = 6, 
    IMS_ERR_PH_FSIM_PUK_REQUIRED = 7,
    IMS_ERR_SIM_NOT_INSERTED = 10,
    IMS_ERR_SIM_PIN_REQUIRED = 11,
    IMS_ERR_SIM_PUK_REQUIRED = 12,
    IMS_ERR_SIM_FAILURE = 13,
    IMS_ERR_SIM_BUSY = 14,
    IMS_ERR_SIM_WRONG = 15,
    IMS_ERR_INCORRECT_PASSWD = 16,
    IMS_ERR_SIM_PIN2_REQUIRED = 17,
    IMS_ERR_SIM_PUK2_REQUIRED = 18,
    IMS_ERR_MEM_FULL = 20,
    IMS_ERR_INVALID_INDEX = 21,
    IMS_ERR_NO_FOUND = 22,
    IMS_ERR_TEXT_ERRSTRING_TOO_LONG_ERR = 24,
    IMS_ERR_INVALID_CHARACTERS_IN_TEXT_ERRSTRING_ERR = 25,
    IMS_ERR_DIAL_ERRSTRING_TOO_LONG_ERR = 26, 
    IMS_ERR_INVALID_CHARACTERS_IN_DIAL_ERRSTRING_ERR = 27,
    IMS_ERR_NO_NW_SERVICE = 30,
    IMS_ERR_NETWORK_TIMEOUT = 31,
    IMS_ERR_NETWORK_NOT_ALLOWED = 32,
    IMS_ERR_NW_PERSON_PIN_REQUIRED = 40,
    IMS_ERR_NW_PERSON_PUK_REQUIRED = 41,
    IMS_ERR_NW_SUB_PERSON_PIN_REQUIRED = 42,
    IMS_ERR_NW_SUB_PERSON_PUK_REQUIRED = 43,
    IMS_ERR_SP_PERSON_PIN_REQUIRED = 44,
    IMS_ERR_SP_PERSON_PUK_REQUIRED = 45,
    IMS_ERR_CORP_PERSON_PIN_REQUIRED = 46,
    IMS_ERR_CORP_PERSON_PUK_REQUIRED = 47,
    IMS_ERR_UNKNOWN = 100,
    IMS_ERR_ILLEGAL_MS = 103,
    IMS_ERR_ILLEGAL_ME = 106,
    IMS_ERR_GPRS_NOT_ALLOWED = 107,
    IMS_ERR_PLMN_NOT_ALLOWED = 111,
    IMS_ERR_LA_NOT_ALLOWED = 112,
    IMS_ERR_ROAMING_AREA_NOT_ALLOWED = 113,
    IMS_ERR_SERV_OPTION_NOT_SUPPORTED = 132,
    IMS_ERR_REQ_SERV_OPTION_NOT_SUBSCRIBED = 133,
    IMS_ERR_SERV_OPTION_TEMP_OUT_OF_ORDER = 134,
    IMS_ERR_GPRS_UNSPECIFIED_ERROR = 148,
    IMS_ERR_PDP_AUTH_FAIL = 149,
    IMS_ERR_INVALID_MOBILE_CLASS = 150,
    IMS_ERR_LINK_NS_SP_PERSON_PIN_REQUIRED = 151,
    IMS_ERR_LINK_NS_SP_PERSON_PUK_REQUIRED = 152,
    IMS_ERR_LINK_SIM_C_PERSON_PIN_REQUIRED = 153,
    IMS_ERR_LINK_SIM_C_PERSON_PUK_REQUIRED = 154,

    /* Below are MTK proprietary error codes */
    IMS_ERR_COMMAND_CONFLICT = 302,
    IMS_NO_ERR = 600,
    IMS_ERR_UNRECOGNIZED_CMD = 601,
    IMS_ERR_RETURN_ERROR = 602,
    IMS_ERR_SYNTEX_ERROR = 603,
    IMS_ERR_UNSPECIFIED = 604,
    IMS_ERR_DATA_TRANSFER_ALREADY = 605,
    IMS_ERR_ACTION_ALREADY = 606,
    IMS_ERR_NOT_AT_CMD = 607,
    IMS_ERR_MULTI_CMD_TOO_LONG = 608,
    IMS_ERR_ABORT_COPS = 609,
    IMS_ERR_NO_CALL_DISC = 610,
    IMS_ERR_BT_SAP_UNDEFINED = 611,
    IMS_ERR_BT_SAP_NOT_ACCESSIBLE = 612,
    IMS_ERR_BT_SAP_CARD_REMOVED = 613,
    IMS_ERR_AT_NOT_ALLOWED_BY_CUSTOMER = 614

} ims_err_id_enum;

typedef enum
{
    IMS_ECPI_DISC_CAUSE_XXX = 0
} ims_ecpi_disc_cause_enum;

typedef enum 
{
    IMS_CALL_TYPE_NATIONAL        = 129,
    IMS_CALL_TYPE_INTERNATIONAL	= 145,
} ims_call_type_enum;

typedef enum 
{
    IMS_CALL_DIR_MO_CALL = 0,
    IMS_CALL_DIR_MT_CALL = 1,
} ims_call_dir_enum;

typedef enum
{
    IMS_CALL_STATE_ACTIVE       = 0,
    IMS_CALL_STATE_HELD         = 1,
    IMS_CALL_STATE_MO_DIALING   = 2,
    IMS_CALL_STATE_MO_ALERTING  = 3,
    IMS_CALL_STATE_MT_INCOMING  = 4,
    IMS_CALL_STATE_MT_WAITING   = 5,
} ims_call_state_enum;

typedef enum 
{
    IMS_CALL_MODE_CS_DOMAIN_BEGIN     = 0,
    IMS_CALL_MODE_CS_VOICE_CALL       = IMS_CALL_MODE_CS_DOMAIN_BEGIN,
    IMS_CALL_MODE_CS_DATA_CALL,       
    IMS_CALL_MODE_CS_FAX_CALL,        
    IMS_CALL_MODE_CS_VFD_VOICE,     /* voice followed by data, voice mode */
    IMS_CALL_MODE_CS_AVD_VOICE,     /* alternating voice/data, voice mode */
    IMS_CALL_MODE_CS_AVF_VOICE,     /* alternating voice/fax, voice mode */
    IMS_CALL_MODE_CS_VFD_DATA,      /* voice followed by data, data mode */
    IMS_CALL_MODE_CS_AVD_DATA,      /* alternating voice/data, data mode */
    IMS_CALL_MODE_CS_AVF_FAX,       /* alternating voice/fax, fax mode */
    IMS_CALL_MODE_CS_UNKNOWN_MODE,    
    IMS_CALL_MODE_CS_VIDEO_CALL,		

    IMS_CALL_MODE_IMS_DOMAIN_BEGIN    = 20,
    IMS_CALL_MODE_IMS_VOICE_CALL      = IMS_CALL_MODE_IMS_DOMAIN_BEGIN,	
    IMS_CALL_MODE_IMS_VIDEO_CALL,		
    IMS_CALL_MODE_IMS_VOICE_CONF,
    IMS_CALL_MODE_IMS_DOMAIN_END      = 39
} ims_call_mode_enum;

typedef enum
{
    IMS_CALL_CATEGORY_NORMAL = 0,
    IMS_CALL_CATEGORY_EMERGENCY
} ims_call_category_enum;

typedef enum
{
    IMS_CC_RESULT_SUCCESS = 0,
    IMS_CC_RESULT_FAILURE,
    IMS_CC_RESULT_INVALID
} ims_cc_result_enum;

typedef enum
{
    // Source: UA
    IMS_CC_CAUSE_NORMAL = 0,        /* receive BYE request, MO hangup, or User reject to receive the all. mapping to CS NORMAL_CLEARING = 16. */
    IMS_CC_CAUSE_ABNORMAL,          /* memory allocation failed, or no resource for call session in the very first begin!!! VDM can require CS to make call, mapping to CS RESOURCE_UNAVAILABLE = 47*/
    IMS_CC_CAUSE_NONUMBER,          /* no dialing number for MO call. mapping to CS Unassigned/Unobtainable number, VDM can require CS to make call. UNOBTAINABLE_NUMBER = 1*/
    IMS_CC_CAUSE_UNREGISTERED,      /* account is not registered, VDM can require CS to make call, mapping to CS NORMAL_UNSPECIFIED = 31*/
    IMS_CC_CAUSE_DISCONNECT,        /* register state go to disconnect state, mapping to CS BEARER_NOT_AVAIL = 58, play congestion tone*/
    IMS_CC_CAUSE_BECANCEL,          /* we cancel the call, which is receive MO_HANGUP_REQ from AP side. Mapping to CS_NORMAL_CLEANING = 16*/
    IMS_CC_CAUSE_BEREJECT,          /* receive 4xx,5xx,6xx from the peer side to  cancel request, mapping to CS USER_BUSY = 17, play busy tone*/
    IMS_CC_CAUSE_BEREJECT_380,      /* receive 380 alternative service, mapping to CS SERVICE_NOT_AVAILABLE = 63. VDM can require CS to make call */
    IMS_CC_CAUSE_BEREJECT_380_EMERGENCY_TO_CS, /* receive 380 alternative service, mapping to CS SERVICE_NOT_AVAILABLE = 63. VDM can require CS to make call */
    IMS_CC_CAUSE_BEREJECT_380_EMERGENCY_REREG, /* receive 380 alternative service with reason, mapping to CS SERVICE_NOT_AVAILABLE = 63. VDM can require CS to make call */
    IMS_CC_CAUSE_BEREJECT_480,      /* receive 480, mapping to CS TEMPORARY_FAILURE = 41, play congestion tone*/
    IMS_CC_CAUSE_BEREJECT_503,      /* receive 503 Service Unavailable, retry-after time period is reported. In this time period, UE cannot use VoLTE to make call. mapping to CS SERVICE_NOT_AVAILABLE = 63.*/
    IMS_CC_CAUSE_TX_TIMEOUT,        /* receive internal error from SIPTX, or AP side do not send confirmation for this MT call until we timeout, we abort the MT call presentation. mapping to CS SERVICE_NOT_AVAILABLE = 63.*/
    IMS_CC_CAUSE_NO_PRIVACY,        /* network cannot support privacy service when user requires critical level. mapping to CS BEARER_NOT_AVAIL = 58, play congestion tone */
    IMS_CC_CAUSE_PRECONDFAIL,       /* receive 580 precondition failure, mapping to CS BEARER_NOT_AVAIL = 58, play congestion tone*/
    IMS_CC_CAUSE_SECONDCALL,        /* receive second call request, VDM can have its policy, mapping to CS NORMAL_UNSPECIFIED = 31*/
    IMS_CC_CAUSE_NOMEDIACONTENT,    /* peer side do not provide SDP for media content or receive 488, mapping to CS QOS_NOT_AVAIL = 49, play congestion tone*/
    IMS_CC_CAUSE_INVALIDMSG,        /*SIP message is not valid, so that the related SS command cannot be executed. This happens in SS function. mapping to CS FACILITY_REJECTED = 29. no tone.*/
    IMS_CC_CAUSE_INVALIDCMD,        /*The command cannot be executed since no related call session is existed. This happens in SS function. cannot mapping to CS, AP side require to send 0. no tone.*/
    IMS_CC_CAUSE_INVALIDIDX,        /* cannot find the acct_id or call_id in the Request command, we send Confirmation with failure result and this cause. mapping to CS NORMAL_UNSPECIFIED = 31 */
    IMS_CC_CAUSE_SRVCC,             /* Add for SRVCC, mapping to CS NORMAL_UNSPECIFIED = 31 */
    IMS_CC_CAUSE_FACILITY_REJECTED, /* receive 504 with XML body for Registration Restoration. Mapping to CS FACILILITY_REJECTED = 29 */
    IMS_CC_CAUSE_DEDICATED_BEARER_TIMEOUT,  /* for MO call, send INVITE but no response and timeout, send indication to VDM and VDM can use CS (TMO, CMCC requirement) */
    IMS_CC_CAUSE_UA_MAX,

    // Source: IMC
    IMS_CC_CAUSE_UNAVAILABLE_OF_CALLS,  /* unavailable of IMS Voice Service */
    
    IMS_CC_CAUSE_MAX
} ims_cc_cause_enum;

typedef enum
{
    IMS_CC_EAIC_ALLOWED = 0,
    IMS_CC_EAIC_NOT_ALLOWED
} ims_cc_eaic_result_enum;

typedef enum
{
    IMS_CALL_RELATED_SS_TYPE_REL_HELD_OR_UDUB,                  // AT+CHLD=0
    IMS_CALL_RELATED_SS_TYPE_REL_ACTIVE_AND_ACCEPT,             // AT+CHLD=1
    IMS_CALL_RELATED_SS_TYPE_REL_SPECIFIC_CALL,                 // AT+CHLD=1x
    IMS_CALL_RELATED_SS_TYPE_HOLD_ACTIVE_AND_ACCEPT,            // AT+CHLD=2
    IMS_CALL_RELATED_SS_TYPE_HOLD_ACTIVE_EXCEPT_SPECIFIC_CALL,  // AT+CHLD=2x
    IMS_CALL_RELATED_SS_TYPE_ADD_HELD_CALL,                     // AT+CHLD=3
    IMS_CALL_RELATED_SS_TYPE_EXPLICIT_CALL_TRANSFER,            // AT+CHLD=4
    IMS_CALL_RELATED_SS_TYPE_ACTIVATE_CCBS_CALL,                // AT+CHLD=5
    IMS_CALL_RELATED_SS_TYPE_REL_ALL,                           // AT+CHLD=6
    IMS_CALL_RELATED_SS_TYPE_REL_CALL_REJECT,                   // AT+CHLD=8
    IMS_CALL_RELATED_SS_TYPE_VT_FALL_TO_VOICE,                  // AT+CHLD=9x
    IMS_CALL_RELATED_SS_TYPE_INVALID
} ims_call_related_ss_type_enum;


typedef enum 
{
    /* Ref: TS27.007 +CIREPH. 
     * NOTE 1: vSRVCC is a Rel-11 feature
     * NOTE 2: Value 3, general non specific failure, might be used 
     *         e.g. in the case of handover cancellation as specified in 3GPP 
     *         TS 24.301 [83] subclause 6.6.2.
     */
    SRVCC_STATUS_HO_STARTED = 0,        // 0: SRVCC handover has started in the CS domain
    SRVCC_STATUS_HO_SUCCESSFUL,         // 1: SRVCC handover successful
    SRVCC_STATUS_HO_FAILED,             // 2: SRVCC or vSRVCC handover cancelled ("Handover Failure" sent)
    SRVCC_STATUS_HO_CANCELLED,          // 3: SRVCC or vSRVCC handover, general non specific failure
    SRVCC_STATUS_HO_VSRVCC_STARTED,     // 4: vSRVCC handover has started in the CS domain
    SRVCC_STATUS_HO_VSRVCC_SUCCESSFUL,  // 5: vSRVCC handover successful
    SRVCC_STATUS_HO_MAX
} srvcc_status_enum;

/* the enum value is generated from ims_cc_cause_enum */
typedef enum 
{
    IMS_EXT_ERROR_REPORT_NORMAL_CLEARING                = 16,
    IMS_EXT_ERROR_REPORT_RESOURCE_UNAVAILABLE           = 47,
    IMS_EXT_ERROR_REPORT_UNOBTAINABLE_NUMBER            = 1,
    IMS_EXT_ERROR_REPORT_NORMAL_UNSPECIFIED             = 31,
    IMS_EXT_ERROR_REPORT_BEARER_NOT_AVAIL               = 58,
    IMS_EXT_ERROR_REPORT_USER_BUSY                      = 17,
    IMS_EXT_ERROR_REPORT_SERVICE_NOT_AVAILABLE          = 63,
    IMS_EXT_ERROR_REPORT_FDN_RESTRICTION                = 2600, // refer to ps_cause_enum
    IMS_EXT_ERROR_REPORT_TEMPORTARY_FAILURE             = 41,
    IMS_EXT_ERROR_REPORT_QOS_NOT_AVAIL                  = 49,
    IMC_EXT_ERROR_REPORT_INVALID_CMD                    = 0,
    IMS_EXT_ERROR_REPORT_FACILITY_REJECTED              = 29,
    IMS_EXT_ERROR_REPORT_CALL_REJECTED                  = 21,
    IMS_EXT_ERROR_REPORT_DEDICATED_BEARER_TIMEOUT       = 1000, // may reselect CS domain
} ims_ext_error_report_enum;

typedef ims_ext_error_report_enum ims_disc_cause_enum;

typedef enum 
{
    IMS_REG_STATE_UNREGISTERED = 0,
    IMS_REG_STATE_REGISTERED
} ims_reg_state_enum;

typedef enum 
{
    IMS_REG_TYPE_NORMAL = 0,
    IMS_REG_TYPE_EMERGENCY
} ims_reg_type_enum;


// For extended DTMF operation commands from IMSP to VDM
typedef enum 
{
    IMS_DTMF_ACTION_START = 0,
    IMS_DTMF_ACTION_STOP
} ims_dtmf_action_enum;

typedef enum
{
    IMCSMS_MS_NW_RP_DATA =0,
    IMCSMS_NW_MS_RP_DATA,
    IMCSMS_MS_NW_RP_ACK,
    IMCSMS_NW_MS_RP_ACK,
    IMCSMS_MS_NW_RP_ERROR,
    IMCSMS_NW_MS_RP_ERROR,
    IMCSMS_MS_NW_RP_SMMA
}imcsms_rp_msg_type_enum;


typedef enum 
{
    IMS_SERVICE_NORMAL_SERVICE = 0, /* NAS registration success */
    IMS_SERVICE_LIMITED_SERVICE,
    IMS_SERVICE_NO_SERVICE   /* plmn loss/idle oos happen */
} ims_service_enum;


typedef enum 
{
    CELL_NORMAL_SERVICE = 0,
    CELL_LIMITED_SERVICE
} cell_service_enum;

typedef enum
{
    IMS_SUB_EVENT_UNKNOWN = 0,
    IMS_SUB_EVENT_CONF = 1,
    IMS_SUB_EVENT_MAX,
}ims_ss_sub_event_enum;

typedef enum
{
    IMS_DEREG_CAUSE_UNSPECIFIED = 0,
    IMS_DEREG_CAUSE_PWR_OFF = 1,
    IMS_DEREG_CAUSE_RF_OFF = 2,
    IMS_DEREG_CAUSE_MAX
}ims_dereg_cause_enum;

typedef enum
{
    VOICE_ADS_CTRL_AUTO = 0,        //  VDM apply domain selection
    VOICE_ADS_CTRL_IMS_ALWAYS       //  VDM select IMS domain as long as IMS Registered
} voice_ads_ctrl_enum;

typedef enum
{
    IMS_URI_TYPE_SIP = 0x01,
    IMS_URI_TYPE_TEL = 0x02,
    IMS_URI_TYPE_URN = 0x04
}ims_uri_type_enum;

/**
 *  MM means generic mobility management
 *  not for 2G MM module
 */
typedef enum
{
    MM_IMS_VOICE_TERMINATION_DISABLED = 1,
    MM_IMS_VOICE_TERMINATION_ENABLED
} mm_ims_voice_termination;

typedef enum
{
    IMS_SRVCC_CALL_MODE_VOICE = 0,
    IMS_SRVCC_CALL_MODE_VIDEO,
    IMS_SRVCC_CALL_MODE_EMERGENCY,
    IMS_SRVCC_CALL_MODE_VOICE_CONFERENCE,
    IMS_SRVCC_CALL_MODE_MAX
}ims_srvcc_call_mode_enum;

typedef enum 
{
    IMS_SRVCC_CALL_DIRECTION_MO = 0,
    IMS_SRVCC_CALL_DIRECTION_MT,
    IMS_SRVCC_CALL_DIRECTION_MAX,
}ims_srvcc_call_direction_enum;

typedef enum 
{
    IMS_SRVCC_CALL_STATE_EARLY = 0,
    IMS_SRVCC_CALL_STATE_EARLY_WITH_MEDIA,
    IMS_SRVCC_CALL_STATE_ACTIVE,
    IMS_SRVCC_CALL_STATE_ON_HOLD,
    IMS_SRVCC_CALL_STATE_MAX
}ims_srvcc_call_state_enum;

typedef enum
{
    IMS_SRVCC_CALL_ECC_CTGY_UNSPECIFIED = 0,
    IMS_SRVCC_CALL_ECC_CTGY_POLICE      = 0x1,
    IMS_SRVCC_CALL_ECC_CTGY_AMBULANCE   = 0x2,
    IMS_SRVCC_CALL_ECC_CTGY_FIRE        = 0x4,
    IMS_SRVCC_CALL_ECC_CTGY_MARINE      = 0x8,     
    IMS_SRVCC_CALL_ECC_CTGY_MOUNTAIN    = 0x10,
    IMS_SRVCC_CALL_ECC_CTGY_GAS         = 0x20,
    IMS_SRVCC_CALL_ECC_CTGY_ANIMAL      = 0x40,
    IMS_SRVCC_CALL_ECC_CTGY_PHYSICIAN   = 0x80,
    IMS_SRVCC_CALL_ECC_CTGY_POISON      = 0x100,
    IMS_SRVCC_CALL_ECC_CTGY_MAX         = 0xFFFF
}ims_srvcc_call_ecc_category_enum;

typedef enum
{
    IMS_REG_SRV_NONE     = 0x00,
    IMS_REG_SRV_VOICE    = 0x01,
    IMS_REG_SRV_SMS      = 0x02,
    IMS_REG_SRV_BOTH     = IMS_REG_SRV_VOICE | IMS_REG_SRV_SMS
}ims_reg_service_enum;

/******************************************************************************
 *                                Struct
 *****************************************************************************/
typedef struct 
{
    /* +ECPI:<call_id>,<msg_type>,<is_ibt>,<is_tch>,<dir>,
     *       <call_mode>,[<number>,<type>],[<disc_cause>],[<pau>]
     */
    kal_bool                is_ibt;
    kal_bool                is_tch;
    ims_call_dir_enum       call_dir;    
    ims_call_mode_enum      call_mode;
    kal_bool                is_number_call_type_present;
    kal_uint8               number[MAX_CC_ECPI_NUM_LEN];
    ims_call_type_enum      call_type;
    kal_bool                is_disc_cause_present;
    ims_disc_cause_enum     disc_cause;
} ims_ecpi_info_struct;

// <pau> field of +ECPI
typedef struct
{
    kal_uint8 p_asserted_uri[IMS_P_ASSERT_URI_LEN]; 
} pau_info_struct;

typedef struct
{
    kal_uint8                           call_id;      /* call_id_ims = call_id_ap */
    ims_srvcc_call_mode_enum            call_mode;
    ims_srvcc_call_direction_enum       call_direction;
    ims_srvcc_call_state_enum           call_state;
    ims_srvcc_call_ecc_category_enum    call_ecc_category;
    kal_uint8                           num_of_conf_parts;
} ims_srvcc_call_ctxt_struct;

typedef struct {
    kal_uint8               number[MAX_CC_ECPI_NUM_LEN];
    ims_call_type_enum      call_type;
    ims_call_mode_enum      call_mode;
} ims_cc_eaic_info_struct;

/* +CLCC:<idx>,<dir>,<stat>,<mode>,<mpty>,[<number>,<type>]... */
typedef struct {
    kal_uint8               call_id;
    ims_call_dir_enum       dir;
    ims_call_state_enum     call_state;     
    ims_call_mode_enum      call_mode;           
    kal_bool                mpty;  // FALSE: is NOT conference call, TRUE: is conference call
    ims_call_type_enum      call_type;
    kal_uint8               number[MAX_CC_ATD_NUM_LEN];
} ims_call_list_struct;

#endif /* _IMS_COMMON_DEF_H_ */

