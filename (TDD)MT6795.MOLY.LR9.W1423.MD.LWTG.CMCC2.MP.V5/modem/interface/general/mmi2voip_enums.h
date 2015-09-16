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
 *  mmi2voip_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the Enum for interface between MMI and VoIP task.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _MMI2VOIP_ENUMS_H
#define _MMI2VOIP_ENUMS_H

/* call act enum */
typedef enum
{
    VOIP_CALL_ACT_IDLE = 0,                     /* 0   No action */
    VOIP_CALL_ACT_DIAL_CALL,                    /* 1   Make a call */
    VOIP_CALL_ACT_RETRIEVE_CALL,                /* 2   retrieve a specific held call */
    VOIP_CALL_ACT_HOLD_CALL,                    /* 3   Hold an active call */
    VOIP_CALL_ACT_ACCEPT_CALL,                  /* 4   Accept call */
    VOIP_CALL_ACT_REL_CALL,                     /* 5   Release a specific call, whether it is a waiting, active, or help call */
    VOIP_CALL_ACT_REL_ALL_CALLS,                /* 6   Release all calls */
    VOIP_CALL_ACT_REL_ALL_HOLD,                 /* 7   Release all held calls */
    VOIP_CALL_ACT_REL_ALL_EXCEPT_WAITING,       /* 8   Release all calls except waiting call */
    VOIP_CALL_ACT_REL_ACTIVE_AND_ACCEPT,        /* 9   Release active call and accept waiting call */
    VOIP_CALL_ACT_FORCE_REL_CALL,               /* 10  Force to release an call that is already  released but response not comes back yet */
    VOIP_CALL_ACT_SWAP_CALL,                    /* 11  Hold active call and activate a specific held call */
    VOIP_CALL_ACT_SPLIT_CALL,                   /* 12  Split a multiparty call into two calls */
    VOIP_CALL_ACT_MERGE_CALL,                   /* 13  Add a held call into an active call */
    VOIP_CALL_ACT_BLIND_TRANSFER,               /* 14  Blind transfer a call */
    VOIP_CALL_ACT_UNATTENDED_TRANSFER,          /* 15  Unattended transfer a call */
    VOIP_CALL_ACT_CONSULT_TRNASFER,             /* 16  Consultive transfer a call  (Not supported yet) */
    VOIP_CALL_ACT_ATTENDED_TRNASFER,            /* 17  Attended transfer a call    (Not supported yet) */
    VOIP_CALL_ACT_REL_ALL_AND_DIAL_EMERGENCY,   /* 18  Force release all call and dial emergency call */
    VOIP_CALL_ACT_HOLD_AND_DIAL,                /* 19  Hold active and dial */
    VOIP_CALL_ACT_HOLD_AND_ACCEPT,              /* 20  Hold active and accept */
    VOIP_CALL_ACT_TRANSFEREE,                   /* 21  Transfer call to another location (transfee case).  Triggered by remove site. */
    VOIP_CALL_ACT_BK_REL_MT_CALL,               /* 22  Release call in the background */
    VOIP_CALL_ACT_BK_REL_ALL_CALL,              /* 23  Release all calls in the background */
    VOIP_CALL_ACT_ADD_PARTICIPANT,              /* 24  Add participant into a conference call */
    VOIP_CALL_ACT_REMOVE_PARTICIPANT,           /* 25  Remove participant from a conference call */
    VOIP_CALL_ACT_CONF_REFRESH,                 /* 26  Subscribe state of a call   (Not supported yet) */
    VOIP_CALL_ACT_ACCEPT_REPLACED_CALL,         /* 27  Accept new call with replaces */
    VOIP_CALL_ACT_TOTAL                         /* 28  Total number of call action */
}voip_call_act_enum;

/* call main state. */
typedef enum
{
    VOIP_CALL_STATE_TERMINATED = 0,     /* 0 Call is terminated  */
    VOIP_CALL_STATE_CONFIRMED,          /* 1 Call is connected. The call might be active or hold */
    VOIP_CALL_STATE_GET_MO_ADDR,        /* 2 Getting NAT address for MO call For MO call */
    VOIP_CALL_STATE_INVITE_PENDING,     /* 3 Waiting for the response of INVITE request */
    VOIP_CALL_STATE_RECV_1XX,           /* 4 Receive 1XX resposne for INVITE */
    VOIP_CALL_STATE_RECV_2XX_REINVITE,  /* 5*/
    VOIP_CALL_STATE_RINGING,            /* 6 Incoming call, waiting user to accept (for MT call) */
    VOIP_CALL_STATE_GET_MT_ADDR,        /* 7 Getting NAT address (for MT call)  */
    VOIP_CALL_STATE_ACCEPTING,          /* 8 Waiting for the ACK of ACCEPT request (for MT call) */
    VOIP_CALL_STATE_HOLDING,            /* 9 Holding dialog inner a single call  (Call HOLD) */
    VOIP_CALL_STATE_UNHOLDING,          /* 10 Retrieving dialog inner a single call (Call HOLD) */
    VOIP_CALL_STATE_HOLDING_1D,         /* 11 Holding the first dialog of a call and waiting for the response (Call HOLD)*/
    VOIP_CALL_STATE_HOLDING_2D,         /* 12 Holding the second dialog of a call and waiting for the response (Call HOLD) */
    VOIP_CALL_STATE_REL_HOLD_FAILED,    /* 13 Releasing the failed dialog during the HOLD process (Call HOLD) */
    VOIP_CALL_STATE_UNHOLDING_1D,       /* 14 Retrieving the first dialog of a call and waiting for the response  (Call UNHOLD) */
    VOIP_CALL_STATE_UNHOLDING_2D,       /* 15 Retrieving the second dialog of a call and waiting for the response  (Call UNHOLD)  */
    VOIP_CALL_STATE_REL_UNHOLD_FAILED,  /* 16 Releasing the failed dialog during the UNHOLD process (Call UNHOLD) */
    VOIP_CALL_STATE_TERMINATING,        /* 17 Releasing call */
    VOIP_CALL_STATE_WAIT_TRANSFER,      /* 18 Waiting for the response of previous sent REFER CALL Transfer */
    VOIP_CALL_STATE_TRANSFERING,        /* 19 Trasfering a call and waiting for the result. */
    VOIP_CALL_STATE_ABORT_MO_NAT_ADDR,  /* 20 Aborting the getting derived address process */
    VOIP_CALL_STATE_ABORT_MT_NAT_ADDR,  /* 21 Aborting the getting derived address process */
    VOIP_CALL_STATE_WAIT_CANCEL,        /* 22 Received the request to abort the MO, is waiting the 1xx indication to proceed the canceling procedure  */
    VOIP_CALL_STATE_CANCELING,          /* 23 Canceling a MO call, and waiting for the response */
    VOIP_CALL_STATE_WAIT_TERMINATE,     /* 24 Waiting for the reposne of accpetance to proceed the terminating process */
    VOIP_CALL_STATE_TERMINATING_2D,     /* 25 Terminating a mulit-party call, and waiting for the response */   
    VOIP_CALL_STATE_TERMINATING_1D,     /* 26 Terminating a mulit-party call, and already received the first response */
    VOIP_CALL_STATE_ADD_PARTICIPANT,    /* 27 Adding participant and waiting for the response */
    VOIP_CALL_STATE_REMOVE_PARTICIPENT, /* 28 Removing participant and waiting for the response */
    VOIP_CALL_STATE_SUBSCRIBING,        /* 29 Subscribing the call state */
//    VOIP_CALL_STATE_UNSUBSCRIBING,      /* 30 Unsubscribing the call state before release a call */
    VOIP_CALL_STATE_TOTAL
}voip_call_state_enum;

/* dialog state */
typedef enum
{
    VOIP_DLG_STATE_TERMINATED = 0,  /* dialog is terminated */
    VOIP_DLG_STATE_ACTIVE,          /* 1 Active call */
    VOIP_DLG_STATE_HOLD,            /* 2 Held call */
    VOIP_DLG_STATE_WAITING,         /* 3 Waiting call */
    VOIP_DLG_STATE_HOLDING,         /* 4 The dialog is holding and waiting for the response */
    VOIP_DLG_STATE_UNHOLDING,       /* 5 The dialog is unholding and waiting for the response */
    VOIP_DLG_STATE_TERMINATING,     /* 6 Terminating a dialog */
    VOIP_DLG_STATE_WAIT_NAT,        /* 7 Wait NAT response to proceed MO/MT call */
    VOIP_DLG_STATE_MO,              /* 8 During MO procedure */  
    VOIP_DLG_STATE_MT,              /* 9 During MT procedure */
    VOIP_DLG_STATE_WAIT_ACK,        /* 10 Waiting for remote ACK */
    VOIP_DLG_STATE_WAIT_PRACK,      /* 11 Waiting for PRACK */
    VOIP_DLG_STATE_WAIT_PRACK_RESP, /* 12 Waiting for 200 of PRACK */
    VOIP_DLG_STATE_TRANSFERING,     /* 12 During transfering procedure */
    VOIP_DLG_STATE_TRANSFEREE,      /* 13 During background transfering procedure */
    VOIP_DLG_STATE_TOTAL
}voip_dlg_state_enum;


typedef enum
{
    VOIP_RTP_DIRECTION_SENDRECV = 0,    /* Send and Receive */
    VOIP_RTP_DIRECTION_SENDONLY,        /* Send only */
    VOIP_RTP_DIRECTION_RECVONLY,        /* Receive only */
    VOIP_RTP_DIRECTION_INACTIVE,         /* RTP session suspends */
    VOIP_RTP_DIRECTION_DEFAULT,
    VOIP_RTP_DIRECTION_TOTAL
}voip_rtp_direction_enum;


/* PROGRESSING_IND */
typedef enum
{
    VOIP_CALL_PROG_TRYING = 0,      /* specific for sending call_id to mmi */
    VOIP_CALL_PROG_RINGING,         /* Receive 180 (ringing indication) */
    VOIP_CALL_PROG_FORWARDED,       /* Receove 181 (call forwarded) */
    VOIP_CALL_PROG_SDP_EXCHANGED,   /* Receive 1xx with SDP */
    VOIP_CALL_PROG_TOTAL
}voip_call_progress_enum;

/* Type of call state in CALL_STATE_IND. */
typedef enum
{
    VOIP_STATE_IND_SDP_CHANGE = 0,
    VOIP_STATE_IND_TRANSFERING,
    VOIP_STATE_IND_TRANSFERED,
    VOIP_STATE_IND_TRANSFER_FAILED,
    VOIP_STATE_IND_TOTAL
}voip_state_ind_enum;

typedef enum
{
   VOIP_MWI_VOICE=0, /* Voice Message */
   VOIP_MWI_FAX,     /* Fax Message */
   VOIP_MWI_PAGER,   /* Pager Message */
   VOIP_MWI_MM,      /* Multimedia Message */
   VOIP_MWI_TEXT,    /* Text Message */
   VOIP_MWI_NONE,    /* Unrecognized Message */
   VOIP_MWI_TOTAL
} voip_mwi_type_enum;


typedef enum
{
    VOIP_CONF_STATE_FULL = 0,   /* full information of conference */
    VOIP_CONF_STATE_PARTIAL,    /* particial information, contains only changed part */
    VOIP_CONF_STATE_DELETED,    /* conference is deleted (call end) */
    VOIP_CONF_STATE_END
}voip_conf_state_enum;

typedef enum
{
    VOIP_CONF_USER_STATUS_CONNECTED = 0,    /* User connected */
    VOIP_CONF_USER_STATUS_DISCONNECTED,     /* User disconnected */
    VOIP_CONF_USER_STATUS_END
}voip_conf_user_status_enum;

typedef enum
{
    VOIP_SUBS_STATE_NONE = 0,
    VOIP_SUBS_STATE_SUCCESS,
    VOIP_SUBS_STATE_BK_SUBSCRIBING,
    VOIP_SUBS_STATE_END
}voip_subs_state_enum;

typedef enum
{
    VOIP_ANNEX_NONE = 0,
    VOIP_ANNEX_NO,
    VOIP_ANNEX_YES,
    VOIP_ANNEX_END
}voip_annex_enum;

typedef enum
{
    VOIP_SIP_CAP_AUDIO = 0,                         /* 0 sip.audio */
    VOIP_SIP_CAP_APPLICATION,                       /* 1 sip.application */
    VOIP_SIP_CAP_DATA,                              /* 2 sip.data */
    VOIP_SIP_CAP_CONTROL,                           /* 3 sip.control */
    VOIP_SIP_CAP_VIDEO,                             /* 4 sip.video */
    VOIP_SIP_CAP_TEXT,                              /* 5 sip.text */
    VOIP_SIP_CAP_AUTOMATA,                          /* 6 sip.automata */
    VOIP_SIP_CAP_CLASS,                             /* 7 sip.class */
    VOIP_SIP_CAP_DUPLEX,                            /* 8 sip.duplex */
    VOIP_SIP_CAP_MOBILITY,                          /* 9 sip.mobility */
    VOIP_SIP_CAP_DESCRIPTION,                       /* 10 sip.description */
    VOIP_SIP_CAP_EVENTS,                            /* 11 sip.events */
    VOIP_SIP_CAP_PRIORITY,                          /* 12 sip.priority */
    VOIP_SIP_CAP_METHODS,                           /* 13 sip.methods */
    VOIP_SIP_CAP_EXTENSIONS,                        /* 14 sip.extensions */
    VOIP_SIP_CAP_SCHEMES,                           /* 15 sip.schemes */
    VOIP_SIP_CAP_ACTOR,                             /* 16 sip.actor */
    VOIP_SIP_CAP_ISFOCUS,                           /* 17 sip.isfocus */
    VOIP_SIP_CAP_BASE_TAGS = VOIP_SIP_CAP_ISFOCUS,
/* new defined tags starting from here */
    VOIP_SIP_CAP_TOTAL
} voip_sip_capability_enum;

#define VOIP_SIP_CAP_NON_SPECIFIED 0
typedef enum
{
    VOIP_SIP_CAP_BOOLEAN_TRUE = 1,
    VOIP_SIP_CAP_BOOLEAN_FALSE
} voip_sip_cap_boolean_type_enum;

typedef enum
{
    VOIP_SIP_CAP_CLASS_BUSINESS = 1,
    VOIP_SIP_CAP_CLASS_PERSONAL,
    VOIP_SIP_CAP_CLASS_SYSTEM = VOIP_SIP_CAP_CLASS_PERSONAL
} voip_sip_cap_class_type_enum;

typedef enum
{
    VOIP_SIP_CAP_DUPLEX_FULL = 1,
    VOIP_SIP_CAP_DUPLEX_SYSTEM = VOIP_SIP_CAP_DUPLEX_FULL,
    VOIP_SIP_CAP_DUPLEX_HALF,
    VOIP_SIP_CAP_DUPLEX_RECVONLY,
    VOIP_SIP_CAP_DUPLEX_SENDONLY
} voip_sip_cap_duplex_type_enum;

typedef enum
{
    VOIP_SIP_CAP_MOBILITY_FIXED = 1,
    VOIP_SIP_CAP_MOBILITY_MOBILE,
    VOIP_SIP_CAP_MOBILITY_SYSTEM = VOIP_SIP_CAP_MOBILITY_MOBILE
} voip_sip_cap_mobility_type_enum;

typedef enum
{
    VOIP_SIP_CAP_ACTOR_PRINCIPAL = 1,
    VOIP_SIP_CAP_ACTOR_SYSTEM = VOIP_SIP_CAP_ACTOR_PRINCIPAL,
    VOIP_SIP_CAP_ACTOR_ATTENDANT,
    VOIP_SIP_CAP_ACTOR_MSG_TAKER,
    VOIP_SIP_CAP_ACTOR_INFORMATION
} voip_sip_cap_actor_type_enum;

typedef enum
{
    VOIP_CALLER_PREF_NON_SPECIFIED = 0,
    VOIP_CALLER_PREF_ACCEPT_EXPLICIT,
    VOIP_CALLER_PREF_ACCEPT_REQUIRE,
    VOIP_CALLER_PREF_ACCEPT_NONE,
    VOIP_CALLER_PREF_REJECT_EXPLICIT,
    VOIP_CALLER_PREF_REJECT_REQUIRE,
    VOIP_CALLER_PREF_REJECT_NONE
} voip_caller_pref_type_enum;

#endif /* _MMI2VOIP_ENUMS_H */

