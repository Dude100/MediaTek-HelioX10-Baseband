/*******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   ppp_l4_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 ******************************************************************************/

/*******************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
*******************************************************************************/


#ifndef _PPP_L4_ENUMS_H
#define _PPP_L4_ENUMS_H

typedef enum
{
    NULL_L2P = 1,
    PPP,
    MANUFACTURER_PROTOCOL    
} mmi_ltwoh_protocol_enum;

typedef enum
{
    NORMAL_LINK_TERMINATION,
    ABNORMAL_LINK_TERMINATION
} mmi_link_free_enum;

typedef enum
{
   PPPE_MOBILE_DEACT,
   PPPE_NW_DEACT
} pppcsd_deact_cause_enum;

typedef enum
{
   PPPE_NONE,
   PPPE_LCP_FAIL,
   PPPE_AUTH_FAIL,
   PPPE_IPCP_FAIL,
   PPPE_ESC_DETECT,
   PPPE_PLUGOUT_DETECT,
   PPPE_PPP_GPRS_DIALUP_ALREADY_ACTIVATED,
   PPPE_PPP_NOT_ACTIVATED_BY_EXT_MODEM_YET,
   PPPE_PPP_ALREADY_ACTIVATED_BY_EXT_MODEM,
   PPPE_PPP_NOT_ACTIVATED_BY_WAP_OVER_CSD_YET,
   PPPE_PPP_ALREADY_ACTIVATED_BY_WAP_OVER_CSD,
   PPPE_PPP_WRONG_CSD_MOD_ID,
   PPPE_PPP_DETECT_AT_CMD_DURING_DIALUP, //[MONZA00008185]
   PPPE_PPP_DETECT_ESCAPE_DURING_DIALUP, //[MONZA00008185]
   PPPE_PPP_IN_GEMINI_DIALUP_ACTIVATED_BY_ANOTHER_L4C, // change feature 2008 03 26
   PPPE_PPP_DIALUP_ABORTED_BY_L4C_AT_CGACT_0,
   PPPE_PPP_DIALUP_WITH_UNSUPPORTED_PDP_TYPE, // __PPP_TYPE_PDP_DIALUP_SUPPORT__
   PPPE_PPP_PDP_CONTEXT_INCORRECT,
   PPPE_PPP_ERROR_CAUSE_ENUM_SIZE
} ppp_error_cause_enum;


enum
{
   PPPE_RESULT_SUCCESS,
   PPPE_RESULT_FAILED
};

typedef enum {
   FSM_INITIAL,
   FSM_STARTING,
   FSM_CLOSED,
   FSM_STOPPED,
   FSM_CLOSING,
   FSM_STOPPING,
   FSM_REQSENT,
   FSM_ACKRCVD,
   FSM_ACKSENT,
   FSM_OPENED,
   FSM_STATE_SIZE
} ppp_fsm_state_enum;

typedef enum {
    VENDOREXT = 0,
    CONF_REQ = 1,
    CONF_ACK = 2,
    CONF_NAK = 3,
    CONF_REJ = 4,
    TERM_REQ = 5,
    TERM_ACK = 6,
    CODE_REJ = 7,
    PROTO_REJ = 8,
    ECHO_REQ = 9,
    ECHO_RPLY = 10,
    DISCARD_REQ = 11,
    IDENTIFICATION = 12,
    TIMEREMAIN = 13,
    RESET_REQ = 14,
    RESET_ACK = 15,
    NULL_CODE = 0xFF
} ppp_fsm_code_enum;

/*
 * PPP Phase
 */
typedef enum
{
   PPP_INIT_STATE = 0,
   PPP_TYPE_PDP_DIALUP_INIT_STATE = PPP_INIT_STATE,
   PPP_LCP_STATE,
   PPP_AUTH_STATE,
   PPP_PDP_STATE,
   PPP_IPCP_STATE,
   PPP_IPV6CP_STATE,
   PPP_DATA_STATE,
   PPP_TERM_0_STATE,
   PPP_TERM_1_STATE,
   PPP_TERM_2_STATE,
   PPP_TERM_3_STATE,
   /*
     * When Used for GPRS dialup, the state PPP_TERM_3_STATE 
     * means PPP will send L4CPPP_DEACTIVATE_CNF to L4C after receiving TAF_EXT_PDP_DEACTIVATE_ACK_RSP, 
     * After 2 scenarios, PPP will enter this state: 
     *   (1) CBM L4C deactivate PPP in PPP_DATA_STATE, or 
     *   (2) AT+CGACT=0 L4C deactivate PPP in PPP_PDP_STATE,  PPP_IPCP_STATE, PPP_DATA_STATE, PPP_TERM_1_STATE, or PPP_TERM_2_STATE
     */
   PPP_TERM_4_STATE,
   /*
     * When Used for GPRS dialup, the state PPP_TERM_4_STATE 
     * means PPP will send L4CPPP_DEACTIVATE_CNF to L4C after receiving Term_Ack, 
     * After 1 scenarios, PPP will enter this state: 
     *   (1) AT+CGACT=0 L4C deactivate PPP in PPP_LCP_STATE,  PPP_AUTH_STATE, PPP_TERM_0_STATE
     */
   PPP_TYPE_PDP_DIALUP_PDP_ACTIVATING_STATE,   /* __PPP_TYPE_PDP_DIALUP_SUPPORT__ */
   PPP_TYPE_PDP_DIALUP_PDP_ACTIVATED_STATE,    /* __PPP_TYPE_PDP_DIALUP_SUPPORT__ */
   PPP_TYPE_PDP_DIALUP_LCP_NEGOTIATING_STATE,  /* __PPP_TYPE_PDP_DIALUP_SUPPORT__ */
   PPP_TYPE_PDP_DIALUP_AUTH_NEGOTIATING_STATE, /* __PPP_TYPE_PDP_DIALUP_SUPPORT__ */
   PPP_TYPE_PDP_DIALUP_NCP_NEGOTIATING_STATE,  /* __PPP_TYPE_PDP_DIALUP_SUPPORT__ */
   PPP_TYPE_PDP_DIALUP_DATA_STATE,             /* __PPP_TYPE_PDP_DIALUP_SUPPORT__ */
   PPP_TYPE_PDP_DIALUP_DEACTIVATING_STATE,     /* __PPP_TYPE_PDP_DIALUP_SUPPORT__ */   
   PPP_TYPE_PDP_LAST_STATE = PPP_TYPE_PDP_DIALUP_DEACTIVATING_STATE,
   PPP_STATE_SIZE
} ppp_state_enum;

/*
 * PPP FSM index  
 */
typedef enum
{
   LCP,
   AUTH,
   IPCP,    //IPV4 or IPV4V6 or IPV6
   IPV6CP,   //IPV4 + IPV6
   PPP_FSM_SIZE
} ppp_fsm_idx_enum;

typedef enum /* remember who activate CSD, WAP or EXT-MODEM*/ /*Not Used*/
{
   CSD_CONTEXT_OCCUPIED_BY_NONE,
   CSD_CONTEXT_OCCUPIED_BY_WAP_OVER_CSD,
   CSD_CONTEXT_OCCUPIED_BY_EXT_MODEM,
   CSD_CONTEXT_OCCUPIED_BY_WHO_ENUM_SIZE
} csd_context_occupied_by_which_app_enum;

typedef enum // For __PPP_TYPE_PDP_DIALUP_SUPPORT__
{
    PPP_PDP_NW_PPP_STATUS_NOT_RUNNING = 0,
    PPP_PDP_NW_PPP_STATUS_RUNNING,
    PPP_PDP_NW_PPP_STATUS_UE_HAS_SENT_TERM_REQ,
    PPP_PDP_NW_PPP_STATUS_UE_HAS_RCVD_TERM_REQ,
    PPP_PDP_NW_PPP_STATUS_ENUM_SIZE
}ppppdp_nw_ppp_status_enum;

typedef enum // For __PPP_TYPE_PDP_DIALUP_SUPPORT__
{
    PPP_PDP_NW_PDP_STATUS_NOT_ACTIVATED = 0,
    PPP_PDP_NW_PDP_STATUS_ACTIVATING,
    PPP_PDP_NW_PDP_STATUS_ACTIVATED,
    PPP_PDP_NW_PDP_STATUS_DISCONNECTING,
    PPP_PDP_NW_PDP_STATUS_ENUM_SIZE
}ppppdp_nw_pdp_status_enum;

typedef enum // For __PPP_TYPE_PDP_DIALUP_SUPPORT__
{
    PPP_PDP_PC_PPP_STATUS_NOT_RUNNING = 0,
    PPP_PDP_PC_PPP_STATUS_RUNNING,
    PPP_PDP_PC_PPP_STATUS_UE_HAS_SENT_TERM_REQ,
    PPP_PDP_PC_PPP_STATUS_UE_HAS_RCVD_TERM_REQ,
    PPP_PDP_PC_PPP_STATUS_ENUM_SIZE
}ppppdp_pc_ppp_status_enum;

typedef enum // For __PPP_TYPE_PDP_DIALUP_SUPPORT__
{
    PPP_PDP_FINAL_MSG_TO_L4_NONE = 0,
    PPP_PDP_FINAL_MSG_TO_L4_IS_ACTIVATE_CNF_FAIL, // 1
    PPP_PDP_FINAL_MSG_TO_L4_IS_DEACTIVATE_IND, // 2
    PPP_PDP_FINAL_MSG_TO_L4_IS_DEACTIVATE_CNF, // 3
    PPP_PDP_FINAL_MSG_TO_L4_ENUM_SIZE
}ppppdp_final_msg_to_l4_enum;

typedef enum
{
    PPPPDP_EVENT_SEE_IP_PACKET,
    PPPPDP_EVENT_RCV_L4CPPP_ACTIVATE_REQ,
    PPPPDP_EVENT_RCV_TAF_EXT_PDP_ACTIVATE_REJ_RSP,
    PPPPDP_EVENT_RCV_TAF_EXT_PDP_ACTIVATE_ACK_RSP,
    PPPPDP_EVENT_RCV_L4CPPP_PPPTYPEPDP_UART_TRANSFER_IND,
    PPPPDP_EVENT_RCV_L4C_DEACTIVATE_REQ,
    PPPPDP_EVENT_RCV_NW_PDP_DEACTIVATE_REQ,
    PPPPDP_EVENT_RCV_NW_PDP_DEACTIVATE_ACK_RSP, //
    PPPPDP_EVENT_RCV_PC_PPP_LCP_TERM_REQ,
    PPPPDP_EVENT_RCV_PC_PPP_LCP_TERM_ACK,
    PPPPDP_EVENT_RCV_NW_PPP_LCP_TERM_REQ,
    PPPPDP_EVENT_RCV_NW_PPP_LCP_TERM_ACK,
    PPPPDP_EVENT_RCV_AT_COMMAND,
    PPPPDP_EVENT_RCV_UART_PLUGOUT,
    PPPPDP_EVENT_RCV_ESCAPE,
    PPPPDP_EVENT_SEE_AUTH_FRAME,
    PPPPDP_EVENT_SEE_NCP_FRAME,
    PPPPDP_EVENT_SEE_NCP_IPV4CP_NW_TO_PC_CONF_ACK_FRAME,
    PPPPDP_EVENT_ALL_DISCONNECT_CONDITIONS_ARE_FULFILLED,
    PPPPDP_EVENT_ENUM_SIZE
} ppp_ppp_pdp_event_enum;

#endif


