/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * mmi2voip_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the structure used for communicating between MMI and VoIP.
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
 *============================================================================
 ****************************************************************************/
#ifndef _MMI2VOIP_STRUCT_H
#define _MMI2VOIP_STRUCT_H

#define VOIP_DEBUG_CALL_LIST
//#define VOIP_3PCC_SUPPORT                   /* 3pcc call flows support */
//#define VOIP_EARLY_MEDIA_SUPPORT            /* early media support */
//#define VOIP_SIP_CAPACITY_SUPPORT

/***************************************************************************** 
* Define
*****************************************************************************/
#define SIP_CONFORMANCE_TEST

#define VOIP_MAX_NUM_CODEC	    (15) /* Maximum number of codec */
//#define VOIP_MAX_NUM_SESSION	(2)  /* Maximum number of RTP session within a dialog */
#define VOIP_MAX_SOCK_ADDR_LEN  (16) /* Length of IP address */
#define VOIP_MAX_DERIEVED_ADDR  (2)  /* Maximum number of derived address */
#define VOIP_MAX_IP_SEG_LEN     (4)  /* Maximum number of IP segement */

/* result */
#define VOIP_OK	                     (0)	/* Succsess */
#define VOIP_ERROR	                 (1)	/* Failure happens in VoIP task */
#define VOIP_SIP_ERROR	             (2)	/* Failure happens in SIP task */
#define VOIP_FS_ERROR	             (3)	/* File system related error */
#define VOIP_NAT_ERROR	             (4)	/* NAT related error */

/* cause */
#define VOIP_NO_ERROR	             (0) /*no error */
#define VOIP_UNSPECIFIED_ERROR	    (-1) /*Unspecified error */
#define VOIP_NOT_REGISTERED	        (-2) /* UA has not registered yet */
#define VOIP_ALREADY_REGISTERED     (-3) /*UA has already registered */
#define VOIP_INVALID_PARAM          (-4) /* Invalid parameter */
#define VOIP_CREATE_UAC_ERROR       (-5) /*Create UAC failed */
#define VOIP_GET_ADDR_FAILED        (-6) /* Get derived address failed during MO/MT call */
#define VOIP_CALL_ABORT_LOCALLY     (-7) /* Force to abort call */
#define VOIP_RECV_BYE               (-8) /* Receive BYE request from remote side */
#define VOIP_INCORRECT_CALL_STATE   (-9) /* Call state is not possible to achieve requested operation */
#define VOIP_BEARER_DISCONNECTED    (-10) /* Network is down */
#define VOIP_ABORT_FAILED           (-11) /*Abort failed */
#define VOIP_CALL_NOT_EXIST         (-12) /* Call does not exist */
#define VOIP_INVALID_URI            (-13) /* Invalid URI */
#define VOIP_SWAP_FAILED            (-14) /* Whole swap failed */
#define VOIP_SWAP_PARTIAL_FAILED    (-15) /* Hold successfully, retrieve failed */
#define VOIP_TRANSFER_FAILED        (-16) /* Transfer failed, keep the same state */
#define VOIP_MERGE_FAILED           (-17) /* Call merge failed */
#define VOIP_MERGE_PARTIAL_FAILED   (-18) /* Call merge partial failed */
#define VOIP_NAT_FAILED             (-19) /* Get NAT information from sever failed. */
#define VOIP_TEMPORARY_BUSY         (-20) /* No empty slot in call list to servce request. */
#define VOIP_UNSUPPORTED_NAT_TYPE   (-21) /* The NAT type is not supported. */
#define VOIP_NETWORK_ERROR          (-22) /* Network Error */
#define VOIP_BUSY                   (-23) /* VoIP task is executoing another action now */
#define VOIP_INVALID_CALL_REQ       (-24) /* Invalid call request */
#define VOIP_PARTIAL_FAILED         (-25) /* Partial failed */
#define VOIP_REREGISTER_FAILED      (-26) /* Re-register failed. */
#define VOIP_SDP_MISMATCHED         (-27) /* Incorrect SDP session in the response */
#define VOIP_DNS_ERROR              (-28) /* Failure happens in SIP task */
#define VOIP_NO_RESOURCE            (-29) /* no resource or memory to execute */ /* new for Julia */
#define VOIP_SIP_FS_ERROR           (-30) /* FS error *//* new for Julia */ 
#define VOIP_DHCP_ERROR             (-31) /* DHCP get IP error */ /* for MMI to retry login */


/* sync with SIP error */
#define VOIP_SIP_300_MULTIPLE_CHOICES         (300)
#define VOIP_SIP_301_MOVED_PERMANENTLY        (301)
#define VOIP_SIP_302_MOVED_TEMPORARILY        (302)
#define VOIP_SIP_305_USE_PROXY                (305)
#define VOIP_SIP_400_BAD_REQUEST              (400)
#define VOIP_SIP_401_UNAUTHORIZED             (401)
#define VOIP_SIP_403_FORBIDDEN                (403)
#define VOIP_SIP_404_NOT_FOUND                (404)
#define VOIP_SIP_405_METHOD_NOT_ALLOW         (405)
#define VOIP_SIP_406_NOT_ACCEPTABLE           (406)
#define VOIP_SIP_407_PROXY_AUTH_REQUIRED      (407)
#define VOIP_SIP_408_REQUEST_TIMEOUT          (408)
#define VOIP_SIP_412_CONDITIONAL_REQ_FAIL     (412) /* Conditional Request Failed */
#define VOIP_SIP_422_INTERVAL_TOO_BRIEF       (422) /* Session-Expires too brief */
#define VOIP_SIP_423_INTERVAL_TOO_BRIEF       (423) /* Expires too brief */
#define VOIP_SIP_478_UNRESOLVEABLE_DEST       (478) /* unresolveable destination */
#define VOIP_SIP_480_TEMP_UNAVAILABLE         (480)
#define VOIP_SIP_481_CALL_TRANS_NOT_EXIST     (481)
#define VOIP_SIP_484_ADDRESS_INCOMPLETE       (484)
#define VOIP_SIP_486_BUSY_HERE                (486)
#define VOIP_SIP_488_NOT_ACCEPTABLE_HERE      (488)
#define VOIP_SIP_487_REQ_TERMINATED           (487)
#define VOIP_SIP_491_REQUEST_PENDING          (491)
#define VOIP_SIP_499_UNRESOLVEABLE_DEST       (499) /* unresolveable destination */
#define VOIP_SIP_500_SERVER_INT_ERROR         (500)
#define VOIP_SIP_503_SERVICE_UNAVAILABLE      (503)
#define VOIP_SIP_600_BUSY_EVERYWHERE          (600)			
#define VOIP_SIP_603_DECLINE                  (603)
#define VOIP_SIP_606_NOT_ACCEPTABLE           (606)			

/* Type of OUTBOUND server */
#define VOIP_OUTBOUND_NEVER         (0)
#define VOIP_OUTBOUND_AUTO          (1)
#define VOIP_OUTBOUND_ALWAYS        (2)

/* Type of NAT */
#define VOIP_NAT_TYPE_NONE          (0)
#define VOIP_NAT_TYPE_STATIC_IP     (1)
#define VOIP_NAT_TYPE_STUN          (2)

/* Type of DTMF */
#define VOIP_DTMF_IN_BAND           (0)
#define VOIP_DTMF_OUT_OF_BAND       (1)
#define VOIP_DTMF_TYPE_NONE         (2)

/* File Length */
#define VOIP_FILE_LEN               (32)
#define VOIP_CALL_FILE_PATH         "Z:\\@voip"
#define VOIP_CALL_FILE_NAME         "call"
#define VOIP_CONF_STATE_FILE_NAME   "conf"

#define VOIP_MAX_NUM_DIALOG	    (2)  /* Maximum number of dialogs within a call */

/* Conference Server Related */
#define VOIP_CONF_STATE_USER_COUNT  (10) /* Maximum number of conference server state */

#ifdef SIP_CONFORMANCE_TEST

#define VOIP_SIP_OPTION_LEN     (1500)
#endif

/*****************************************************************************
* Dialog status
*****************************************************************************/
#define VOIP_SDP_STATUS_NONE            0x00000000
#define VOIP_SDP_STATUS_IS_DTMF         0x00000001
#define VOIP_SDP_STATUS_PT_CHANGE       0x00000002
#define VOIP_SDP_STATUS_INVITE_SDP      0x00000004
#define VOIP_SDP_STATUS_SDP_NO_MEDIA    0x00000008
#define VOIP_SDP_STATUS_EXCHANGED       0x00000010
#define VOIP_SDP_STATUS_EARLY_MEDIA     0x00000020

/*****************************************************************************
* Typedef 
*****************************************************************************/
/* This structure is used for the profile setting */
typedef struct
{
    kal_uint16  sip_port;                               /* Sip server port number */
    kal_uint16  local_port;                             /* Local port (default 0: auto assign) */
    kal_uint16  outbound_port;                          /* Port of outbound server */
    kal_uint16  registrar_port;                         /* Port of registrar server */
    kal_uint16  stun_port;                              /* Port of STUN server */
    kal_uint16  rtp_start_port;                         /* Start of RTP port */
    kal_uint16  rtp_end_port;                           /* End of RTP port */
    kal_char    disp_name[VOIP_DISP_NAME_LEN*3];        /* Display name of the user */
    kal_char    sip_server[VOIP_URI_LEN];               /* Sip server address */
    kal_char    sip_username[VOIP_USERNAME_LEN];        /* Username of SIP */
    kal_char    sip_password[VOIP_PASSWORD_LEN];        /* Password of SIP */
    kal_char    *domain_name;                           /* pointer to the domain part of username filed*/
    kal_bool    is_IP_domain;                           /* if the domain is in IP form */
    kal_uint8   outbound_type;                          /* Enable or disable outbound server */
    kal_bool    enable_registrar;                       /* Enable or disable registrar server */    
    kal_char    outbound_server[VOIP_URI_LEN];          /* Address of outbound server */
    kal_char    outbound_username[VOIP_USERNAME_LEN];   /* Username of outbound server */
    kal_char    outbound_password[VOIP_PASSWORD_LEN];   /* Password of outbound server */
    kal_char    registrar_server[VOIP_URI_LEN];         /* Address of registrar server */
    kal_char    registrar_username[VOIP_USERNAME_LEN];  /* Username of registrar server */
    kal_char    registrar_password[VOIP_PASSWORD_LEN];  /* Password of registrar server */
    kal_char    auth_username[VOIP_USERNAME_LEN];       /* Authorization username */
    kal_uint8   nat_type;                               /* Type of NAT*/
    kal_uint8   fire_wall[4];                           /* IP address of firewall */
    kal_char    stun_server[VOIP_URI_LEN];              /* Address of STUN server */
    kal_char    voice_mail[VOIP_URI_LEN];               /* Voice mail serfer */
    kal_bool    nat_refresh;                            /* Auto or manual refresh NAT */
    kal_uint8   nat_refresh_time;                       /* NAT manual refresh interval */
    kal_uint32  data_account;                           /* Index of data account */
}voip_profile_struct;

/* This structure is used for SIP capability */
#ifdef VOIP_SIP_CAPACITY_SUPPORT
typedef struct
{
    kal_bool                        enable;
    voip_sip_cap_boolean_type_enum  audio;
    voip_sip_cap_boolean_type_enum  application;
    voip_sip_cap_boolean_type_enum  data;
    voip_sip_cap_boolean_type_enum  control;
    voip_sip_cap_boolean_type_enum  video;
    voip_sip_cap_boolean_type_enum  text;
    voip_sip_cap_boolean_type_enum  automata;
    voip_sip_cap_class_type_enum    class;
    voip_sip_cap_duplex_type_enum   duplex;
    voip_sip_cap_mobility_type_enum mobility;
    kal_char                        description[64];
    kal_bool                        events;
    kal_uint8                       priority;
    kal_bool                        methods;
    kal_bool                        extensions;
    kal_bool                        schemes;
    voip_sip_cap_actor_type_enum    actor;
    voip_sip_cap_boolean_type_enum  isfocus;
}voip_sip_cap_struct;
#endif

#ifdef VOIP_SIP_CAPACITY_SUPPORT
typedef struct _voip_caller_pref_struct
{
    voip_sip_cap_struct             caller_pref;
    voip_caller_pref_type_enum      pref_type;
} voip_caller_pref_struct;
#endif
/* This structure is used for the option of a call */
typedef struct 
{
    voip_codec_enum         codec_order[VOIP_MAX_NUM_CODEC];        /* Array index of codec */
    kal_bool                auto_decline;                           /* Auto decline anonymouse */
    kal_bool                do_not_disturb;                         /* Auto reject all calls */
    kal_bool                hide_user_id;                           /* Hide user id or not */
    kal_bool                auto_answer;                            /* Auto answer mode in MMI */
    kal_uint8               dtmf;                                   /* In band or out-of-band DTMF */
    kal_bool                comfortable_noise;                      /* enable confortable noise or not */
    kal_bool    srtp;                                   /* enable srtp usage or not */
#ifdef VOIP_SIP_CAPACITY_SUPPORT
    voip_sip_cap_struct     sip_cap;                                /* SIP Capability */
    voip_caller_pref_struct caller_pref[VOIP_MAX_CALLER_PREFERENCE];/* Caller Preference */
#endif
    kal_bool                early_media;                            /* if send early media */
}voip_setting_struct;


/* This structure defines a structure to carry all kinds of call id. */
typedef struct
{
    kal_uint32  call_id;    /* Call ID */
    kal_uint32  dialog_id;  /* Dialog ID */
}voip_call_id_struct;


/* This structure is used for the address of a call. */
typedef struct
{
    kal_char   disp_name[VOIP_DISP_NAME_LEN*3]; /*Display name of the user, could be null */
    kal_char    uri[VOIP_URI_LEN];             /* Eg, "sip: a@b.c" */
}voip_addr_struct;

/* This structure is used for ringing indication */
typedef struct
{
    voip_addr_struct *refer_by;
    voip_call_id_struct *replaced_call;
}voip_ring_data_struct;

typedef struct
{
    kal_uint32 newmsgs;
    kal_uint32 oldmsgs;
    kal_bool is_urgent_present;
    kal_uint32 new_urgentmsgs;
    kal_uint32 old_urgentmsgs;
}voip_msg_struct;

/* socket address strcuture */
typedef struct 
{
   kal_int16	addr_len;
   kal_uint8	addr[VOIP_MAX_SOCK_ADDR_LEN];
   kal_uint16	port; 
} voip_sockaddr_struct;

/* NAT address information */
typedef struct
{
    voip_sockaddr_struct local_addr;
    voip_sockaddr_struct derived_addr;
}voip_nat_addr_struct;

/* SDP crypto */
typedef struct
{
    kal_uint8 crypto_idx;
    srtp_crypto_struct crypto;
} voip_crypto_struct;

/* SDP sessoin */
typedef struct
{
    kal_uint64      remote_sdp_version;                 /* remote SDP version */
    kal_uint16      payload_type[VOIP_MAX_NUM_CODEC];   /* payload type */
    kal_uint16      local_payload_type[VOIP_MAX_NUM_CODEC]; /* local payload type */
    kal_uint16      dtmf_payload_type;                  /* payload type of DTMF */
    kal_uint16      num_codec;                          /* number of codec supported in this section  */
    kal_uint16      remote_rtp_port;                    /* remote RTP port number */
    kal_uint16      remote_rtcp_port;                   /* remote RTCP port number */
    kal_uint16      local_rtp_port;                     /* local RTP port number */
    kal_uint16      local_rtcp_port;                    /* local RTCP port number */
    kal_uint16      ptime;
    kal_uint16      maxptime;
    kal_uint16      modeset[VOIP_MAX_NUM_CODEC];        /* modeset of codec */
    voip_codec_enum codec[VOIP_MAX_NUM_CODEC];          /* suppored codec list */
    kal_uint8       local_addr[VOIP_MAX_IP_SEG_LEN];    /* local address */
    kal_uint8       remote_addr[VOIP_MAX_IP_SEG_LEN];   /* remote address */
    kal_uint32      sdp_status;                         /* status info about sdp session */
    voip_rtp_direction_enum direction;                  /* media direction, 
                                                           sendonly, recvonly, sendrecv, inactive */
    voip_annex_enum g7231_annexa;                       /* annexa for G7231 */
    voip_annex_enum g729_annexb;                        /* annexb for G729 */
    voip_crypto_struct      *crypto_info;                       /* crypto information */
}voip_sdp_struct; /* voip_session_struct; */

/* This structure defines a dialog between two peers */
typedef struct
 {
    kal_uint32              dialog_id;                          /* unique id of the dialog */
    kal_int16               dialog_idx;                         /* unique index of call dialog */
    voip_addr_struct        user_addr;                          /* remote side address */
    voip_sdp_struct         sdp_info;                           /* Information of each media stream */
#ifdef VOIP_EARLY_MEDIA_SUPPORT
    voip_sdp_struct         early_sdp_info;                     /* information of early media stream */
#endif
    voip_nat_addr_struct    stun_addr[VOIP_MAX_DERIEVED_ADDR];  /* stun address */
    voip_dlg_state_enum     dialog_state;                       /* dialog state */
    kal_bool                in_use;                             /* dialog is in used */
    kal_uint8               rel_prov_rsp;                       /* if 100rel is required in MT invite */
}voip_dialog_struct;

typedef struct
{
    kal_uint32              version;        /* version of the conference state */
    kal_bool                is_conference;  /* if the call is a conference server call */
    voip_subs_state_enum    subs_state;     /* if the call state is subscribed */
}voip_call_conf_info_struct;

typedef struct
{
    kal_uint32                  call_id;                      /* Call id */
    voip_dialog_struct          dialog[VOIP_MAX_NUM_DIALOG];  /* Dialog */
    voip_call_conf_info_struct  conf_info;                    /* information of conference server */
    voip_call_state_enum        call_state;                   /* Call state */
    kal_uint8                   num_dialogs;                  /* Number of dialog in this call */
    kal_bool                    is_bk_call;                   /* If the call is a background call */
}voip_call_struct;

typedef struct
{    
    voip_codec_enum         codec[VOIP_MAX_NUM_CODEC];          /* suppored codec list */
    voip_dlg_state_enum     dialog_state;                       /* dialog state */
    kal_bool                in_use;                             /* dialog is in used */
    kal_uint16              payload_type[VOIP_MAX_NUM_CODEC];   /* payload type */
    kal_uint16              dtmf_payload_type;                  /* payload type of DTMF */
    kal_uint16              num_codec;                          /* number of codec supported in this section  */
    kal_uint16              remote_rtp_port;                    /* remote RTP port number */
    kal_uint16              remote_rtcp_port;                   /* remote RTCP port number */
    kal_uint16              local_rtp_port;                     /* local RTP port number */
    kal_uint16              local_rtcp_port;                    /* local RTCP port number */
    kal_uint8               local_addr[VOIP_MAX_IP_SEG_LEN];    /* local address */
    kal_uint8               remote_addr[VOIP_MAX_IP_SEG_LEN];   /* remote address */
    kal_bool                is_dtmf;                            /* is DTMF supported */
    kal_bool                is_sdp_exchanged;                   /* is SDP exchange finished */
    voip_rtp_direction_enum direction;                          /* media direction, */
    voip_annex_enum         g7231_annexa;                       /* G7231 annexa */
    voip_annex_enum         g729_annexb;                        /* G729 annexb */
    voip_crypto_struct      *crypto_info;                            /* crypto info */
}voip_dialog_info_struct;

typedef struct
{
    kal_uint32              call_id;
    voip_dialog_info_struct dialog[VOIP_MAX_NUM_DIALOG];    /* dialog */
    voip_call_state_enum    call_state;                     /* Call state */
    kal_uint8               num_dialogs;                    /* Number of dialog in this call */
    kal_bool                is_bk_call;                     /* If the call is a background call */
    kal_bool                is_conference;                  /* If the call is a conference server call */
}voip_call_info_struct;

typedef struct
{
    voip_msg_struct msg[VOIP_MWI_TOTAL];            /* message indication list */  
    kal_bool        msg_present[VOIP_MWI_TOTAL];    /* if the message is present */
    kal_bool        is_account_present;             /* if message account is present */
    kal_char        msg_account[VOIP_URI_LEN];      /* Eg, "sip: a@b.c" */    
}voip_mwi_info_struct;


typedef struct
{
    kal_char                    disp_name[VOIP_DISP_NAME_LEN*3];    /*Display name of the user, could be null */
    kal_char                    uri[VOIP_URI_LEN];                  /* Eg, "sip: a@b.c" */
    voip_conf_user_status_enum  state;
}voip_conf_user_struct;


/*****************************************************************************
* Message struct 
*****************************************************************************/
#define VOIP_MSG_STRUCT
/* Registration */
typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;  
    voip_profile_struct profile; /* Profile settings */
    voip_setting_struct setting; /* Setting of the call */
}mmi_voip_register_req_struct;

/* Setting */
typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;  
    voip_setting_struct setting; /*Setting of the call */
}mmi_voip_setting_req_struct;

typedef struct
{
    kal_uint8  ref_count;
    kal_uint16 msg_len;  
    kal_uint8  result; /* result */
    kal_int32  cause;  /* cause of the result */
}mmi_voip_result_struct;

typedef mmi_voip_result_struct mmi_voip_register_rsp_struct;
typedef mmi_voip_result_struct mmi_voip_deregister_rsp_struct;
typedef mmi_voip_result_struct mmi_voip_deregister_ind_struct;
typedef mmi_voip_result_struct mmi_voip_setting_rsp_struct;

/* call related indications */
typedef struct
{
    kal_uint8        ref_count;
    kal_uint16       msg_len;  
    kal_uint32       call_id;                      /* call id of the ringing call */
    kal_uint32       dialog_id;                    /* dialog id of the ringing call */
    voip_addr_struct refer_by;                     /* Address of the refer-by field */
    kal_wchar        call_list[VOIP_FILE_LEN];     /* Name of call list file */
    kal_bool         is_refer_by;                  /* If the call is refered by other users */
#ifdef VOIP_DEBUG_CALL_LIST
    voip_call_info_struct call_info[6];
#endif
}mmi_voip_call_ring_ind_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;  
    kal_uint32       call_id;                      /* call id of the ringing call */
    kal_uint32       dialog_id;                    /* dialog id of the ringing call */
    kal_uint32       replace_call_id;              /* call id of the replaced call */
    kal_uint32       replace_dialog_id;            /* dialog id of the ringing call */
}mmi_voip_call_replace_ind_struct;

typedef struct
{
    kal_uint8        ref_count;
    kal_uint16       msg_len;
    kal_uint8        result;                       /* Accept the call or not */
    kal_uint32       call_id;                      /* call id of the ringing call */
    kal_uint32       dialog_id;                    /* dialog id of the ringing call */
    kal_uint32       replace_call_id;              /* call id of the replaced call */
    kal_uint32       replace_dialog_id;            /* dialog id of the ringing call */
}mmi_voip_call_replace_cnf_struct;

typedef struct
{
    kal_uint8        ref_count;
    kal_uint16       msg_len;
    kal_uint32       replace_call_id;              /* call id of the replaced call */
    kal_uint32       replace_dialog_id;            /* dialog id of the replaced call */
    voip_call_struct call;                          /* affected call */
}mmi_voip_call_replace_complete_ind_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;  
    kal_uint32  call_id;                            /* Call ID */
    kal_uint32  dialog_id;                          /* Dialog ID */
    kal_int32   cause;                              /* cause of the result */
    kal_uint8   result;                             /* result */
    kal_wchar   call_list[VOIP_FILE_LEN];           /* length of cal list file */
    kal_uint16  status_code;                        /* status code of call end */
#ifdef VOIP_DEBUG_CALL_LIST
    voip_call_info_struct call_info[6];
#endif
}mmi_voip_call_end_ind_struct;

typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;  
    kal_uint32          call_id;                      /* Call ID */
    kal_uint32          dialog_id;                    /* Dialog ID */
    kal_char            tansfer_target[VOIP_URI_LEN]; /* Address of the transfer target. Used when the remote site asks to transfer the call */
    voip_state_ind_enum change_cause;                 /* Main state of  changes */
    voip_call_struct    call;                         /* affect call */
#if 0
/* under construction !*/
#ifdef VOIP_DEBUG_CALL_LIST
/* under construction !*/
#endif
#endif
}mmi_voip_call_state_ind_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;  
    kal_uint32              call_id;                  /* Call ID */
    kal_uint32              dialog_id;                /* Dialog ID */
    voip_call_progress_enum status;                   /* Status of the call (ringing, forward, and etc..) */
    kal_wchar               call_list[VOIP_FILE_LEN]; /* length of cal list file */
#ifdef VOIP_DEBUG_CALL_LIST
    voip_call_info_struct call_info[6];
#endif
}mmi_voip_progressing_ind_struct;

/* call action request */
typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;  
    kal_char            target_call[VOIP_URI_LEN];    /* Eg, "sip: a@b.c"  Call to be dialed */
    voip_call_id_struct active_call;                  /* Call to be activated. Call Transfer also uses this as the transferee */
    voip_call_id_struct hold_call;                    /* Call to be held */
    voip_call_id_struct rel_call;                     /* Call to be released or rejected */
    voip_call_act_enum  op_code;                      /* Operation code  */
    kal_int8            abort_call_id;
#ifdef VOIP_SIP_CAPACITY_SUPPORT
    voip_caller_pref_struct caller_pref[VOIP_MAX_CALLER_PREFERENCE];
#endif
}mmi_voip_call_act_req_struct;

typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;  
    voip_call_act_enum  op_code;                      /* Operation code */
    kal_uint8           result;                       /* result */
    kal_int32           cause;                        /* cause of the result */
    kal_wchar           call_list[VOIP_FILE_LEN];     /* length of cal list file */
#ifdef VOIP_DEBUG_CALL_LIST
    voip_call_info_struct call_info[6];
#endif
}mmi_voip_call_act_rsp_struct;

/* MWI, this primitive is used to notify the status of waiting message. */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;  
    kal_bool                is_msg_waiting;
    voip_mwi_info_struct    mwi_info;
}mmi_voip_waiting_msg_ind_struct;

/* conference state indication structure */
typedef struct
{
    kal_uint8                   ref_count;
    kal_uint16                  msg_len;
    kal_uint32                  call_id;                    /* call ID */
    kal_uint32                  dlg_id;                     /* dialog ID */
    kal_uint32                  count;                      /* number of entity in this indication */
    kal_wchar                   file_path[VOIP_FILE_LEN];   /* file path+name for entity list */
    voip_conf_state_enum        conf_state;                 /* state of conference indication */
}mmi_voip_conference_state_ind_struct;

#ifdef SIP_CONFORMANCE_TEST
/* MWI, this primitive is used to notify the status of waiting message. */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;  
    kal_char    uri[VOIP_URI_LEN]; /* Address of remote server */
}mmi_voip_option_req_struct;

/* MWI, this primitive is used to notify the status of waiting message. */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;  
    kal_uint8   result;                       /* result */
    kal_int32   cause;                        /* cause of the result */
    kal_char    data[VOIP_SIP_OPTION_LEN];
}mmi_voip_option_rsp_struct;
#endif /* SIP_CONFORMANCE_TEST */

/* Transferee, this primitive is used to notify an refer is received */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_bool    result;
}mmi_voip_transferee_cnf_struct;

typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;  
    kal_uint8           result;                       /* result */
    kal_int32           cause;                        /* cause of the result */
    kal_uint32          call_id;                      /* Call ID */
    kal_uint32          dialog_id;                    /* Dialog ID */
}mmi_voip_act_bk_rej_rsp_struct;

#endif /* _MMI2VOIP_STRUCT_H */

