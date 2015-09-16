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

/*******************************************************************************
 * Filename:
 * ---------
 *   ltecsr_struct.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *	define the message struct parameters
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *     HISTORY
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _LTECSR_STRUCT_H
#define _LTECSR_STRUCT_H

#include "kal_general_types.h"
#include "kal_public_defs.h"

#pragma warning( push )
#pragma warning( disable : 4200 )

#include "codec_def.h"

#pragma warning( pop )

typedef enum e_func_class {
	FC_RTP          = (1<<0),
	FC_XMIT         = (1<<1),
	FC_VOICE        = (1<<2),
	FC_VIDEO        = (1<<3),
	FC_DTMF         = (1<<4),
	FC_CODEC        = (1<<5),
} func_class_e;

typedef enum e_xmit_mode {
	XMIT_MODE_NONE=0,
	XMIT_MODE_SENDONLY,
	XMIT_MODE_RECVONLY,
	XMIT_MODE_SENDRECV,
	XMIT_MODE_INACTIVE,
	XMIT_MODE_ACTIVE,
} xmit_mode_e;

enum VoLTE_Event_RTP_DIRECTION_e {
    VoLTE_Event_RTP_DIRECTION_INACTIVE = 0,     ///< RTP session suspends. Inactive also is default value.
    VoLTE_Event_RTP_DIRECTION_SENDONLY,         ///< Send only
    VoLTE_Event_RTP_DIRECTION_RECVONLY,         ///< Receive only
    VoLTE_Event_RTP_DIRECTION_SENDRECV,         ///< Send and Receive
    /*add here*/    
    VoLTE_Event_RTP_DIRECTION_Max,
};

enum VoLTE_Event_IP_Version_e {
    VoLTE_Event_IPv4 = 0, 
    VoLTE_Event_IPv6,
    /*add here*/    
    VoLTE_Event_IPv_Max,
};

#define VOLTE_IPADDR_LENGTH                 16
#define VOLTE_IPV4_LENGTH                   4
#define VOLTE_IPV6_LENGTH                   16
#define VOLTE_MAX_SDP_FMTP_SUB_VALUE_LENGTH 16
#define VOLTE_MAX_SDP_EGBYTE_LENGTH         8
typedef struct volte_event_media_config {
    kal_uint8                                   local_address[VOLTE_IPADDR_LENGTH];
    
    //  RTP and RTCP session for audio and video
    kal_uint32                                  audio_b_as;               // RTP bandwidth
    kal_uint32                                  audio_b_rs;               // RTCP sender bandwidth
    kal_uint32                                  audio_b_rr;               // RTCP receiver bandwidth    
    kal_uint16                                  audio_remote_rtp_port;
    kal_uint16                                  audio_remote_rtcp_port;    
    kal_uint16                                  audio_local_rtcp_port;     ///< rtcp port number. we may configure it not rtp_port+1
    kal_uint16                                  audio_local_rtp_port;      ///< rtp port number for media attribute in SDP message    
    kal_uint8                                   audio_remote_rtp_address[VOLTE_IPADDR_LENGTH];
    kal_uint8                                   audio_remote_rtcp_address[VOLTE_IPADDR_LENGTH];

    kal_uint32                                  video_b_as;               // RTP bandwidth
    kal_uint32                                  video_b_rs;               // RTCP sender bandwidth
    kal_uint32                                  video_b_rr;               // RTCP receiver bandwidth    
    kal_uint16                                  video_remote_rtp_port;
    kal_uint16                                  video_remote_rtcp_port;    
    kal_uint16                                  video_local_rtcp_port;     ///< rtcp port number. we may configure it not rtp_port+1
    kal_uint16                                  video_local_rtp_port;      ///< rtp port number for media attribute in SDP message    
    kal_uint8                                   video_remote_rtp_address[VOLTE_IPADDR_LENGTH];
    kal_uint8                                   video_remote_rtcp_address[VOLTE_IPADDR_LENGTH];
    
    kal_uint8                                   remote_addr_type;           ///< VoLTE_Event_IP_Version_e, apply to RTP audio & video session, RTCP audio & video session
    kal_uint8                                   audio_rtp_direction;        ///< VoLTE_Event_RTP_DIRECTION_e
    kal_uint8                                   video_rtp_direction;        ///< VoLTE_Event_RTP_DIRECTION_e
    // required by video codec
    kal_uint8                                   video_payload_type;
    
    kal_uint32                                  rtcp_interval;              ///< IMCB will get value from NVRAM. Used by data plane.
    kal_uint32                                  dscp;                       ///< IMCB will get value from NVRAM. Used by data plane.

    // required by voice codec driver
    kal_uint8                                   audio_codec;                ///< voip_codec_enum in codec_def.h
    kal_uint8                                   audio_payload_type;         ///< payload type
    kal_uint8                                   audio_clock_rate;           ///< dynamic rate, clock rate, see VoLTE_Event_Clock_Rate_e    
    kal_uint8                                   is_dtmf;                    ///< is dtmf tone useing telephony event   
          
    kal_uint8                                   tele_evt_payload_type;  ///< telephony event payload type
    kal_uint8                                   tele_evt_clock_rate;    ///< telephony event rate
    kal_uint8                                   g723_bitrate;           ///< VoLTE_Event_G7231_BitRate_e
    kal_uint8                                   is_g723_annexAYES;      ///< G.723.1 annexA Yes:1, No:0

    kal_uint8                                   is_g729_annexBYES;      ///< G.729 annexB Yes:1, No:0
    kal_uint8                                   ilbc_mode;              ///< VoLTE_Event_iLBC_Rate_e
    // required by RFC 6679 ECN
    kal_uint8                                   ecn_capable_rtp_method; ///< VoLTE_Event_ECN_RTP_METHOD_e
    kal_uint8                                   ecn_capable_ect;        //0, 1

    kal_uint32                                  ptime;         ///< ptime of the codec
    kal_uint32                                  max_ptime;    ///< max ptime is the buffer size for data plane. may not the same to ptime
    // required by AMR and AMR WB codec
    kal_int8                                    mode_set[VOLTE_MAX_SDP_FMTP_SUB_VALUE_LENGTH];

    kal_uint8                                   is_octet_align;     ///< 0:default, bandwidth-efficient, 1: octet_align
    kal_uint8                                   mode_change_period; ///< the period should be N. but currently only 1(default) or 2.
    kal_uint8                                   mode_change_cap;    ///< 1(default) or 2(recommended to support)
    kal_uint8                                   mode_change_neighbor;///< 0(default) or 1
   
    kal_uint8                                   crc;                ///< 0 or 1
    kal_uint8                                   robust;             ///< 0 or 1
    kal_uint8                                   interleaving;       ///< the maximum number of frame-blocks. 0: not present
    kal_uint8                                   channel;            ///< the number of audio channel. must be 1 currently
    kal_uint16                                  max_red;            // the maximum duration in ms
// required by RTCP FB
    kal_uint16                                  rtcp_rsize;
    kal_uint32                                  rtcpfb_type;        ///< bitmap, VoLTE_Event_RTCP_FB_Type_e
	kal_int8                                    id[VOLTE_MAX_SDP_EGBYTE_LENGTH];
	kal_int8                                    trr_int[VOLTE_MAX_SDP_EGBYTE_LENGTH];
	kal_int8                                    id_app_string[VOLTE_MAX_SDP_FMTP_SUB_VALUE_LENGTH]; 
	kal_int8                                    ack_app_string[VOLTE_MAX_SDP_FMTP_SUB_VALUE_LENGTH]; 
	kal_int8                                    nack_app_string[VOLTE_MAX_SDP_FMTP_SUB_VALUE_LENGTH]; 
	kal_int8                                    tmmbr_string[VOLTE_MAX_SDP_FMTP_SUB_VALUE_LENGTH];
	kal_int8                                    vbcm_string[VOLTE_MAX_SDP_FMTP_SUB_VALUE_LENGTH];		
} VoLTE_Event_Media_config_t;

//#define __UA_SDP_MEDIA_PARAM__
#undef __UA_SDP_MEDIA_PARAM__

#ifndef __UA_SDP_MEDIA_PARAM__
typedef struct s_media_param {
	VoLTE_Event_Media_config_t o;
} media_param_t;
#else

/* tyepdef for the ua sdp media data structure */
#endif

typedef struct s_xxx2ltecsr_param {

	/* call id */
	kal_int32 cid;

	/* session id */
	kal_int32 voice_sid;
	kal_int32 video_sid;

	/* ebi for voice and video */
	kal_int32 voice_ebi;
	kal_int32 video_ebi;

	/* op code */
	kal_uint32 func_class;

	/* all parameters */
	media_param_t params;

} xxx2ltecsr_param_t ;

typedef enum e_dtmf_mode {
	DTMF_IN_BAND=0,
	DTMF_OUT_BAND=1,
	DTMF_INOUT_BAND=2,
} dtmf_mode_e;

typedef enum e_dtmf_duration {
	DTMF_PLAY_INFINITE=-1,
	DTMF_STOP=0,
	DTMF_PLAY_ONESHOT=40, 
	/* others value: for unit(ms) */
} dtmf_duration_e;

typedef struct s_xxx2ltecsr_dtmf_param {
	kal_int32 cid;
//	kal_int32 sid;
	kal_uint8 digit;
//	kal_int8 mode;
	kal_int8 duration;
} xxx2ltecsr_dtmf_param_t;

typedef enum e_dtmf_event_state {
	DTMF_KEY_RELEASE =0,
	DTMF_KEY_PUSH_STR=1,
	DTMF_KEY_PUSH_ING=2,
	DTMF_KEY_PUSH_RE1=3,
	DTMF_KEY_PUSH_RE2=4,
	DTMF_KEY_PUSH_RE3=5,
} dtmf_event_state_e;

#define DTMF_MAX_LENGTH 32

typedef struct s_dtmf_event_report {
	dtmf_event_state_e  state;/* used */
	kal_int16 rt_period; /*used for event request duration is not -1 or 0*/
	kal_int16 dtmf_period; /*used for event request duration is not -1 or 0*/
	kal_uint8  queue[DTMF_MAX_LENGTH]; /* queue DTMF request for duration is not -1 or 0 */
	kal_uint8  q_idx; /* queue idx */
	kal_uint32 ts; 
	kal_uint16 duration;
	kal_uint8  code; /* event code */
	kal_uint8 m;   /* marker bit */
	kal_uint8 e;   /* end bit */
} dtmf_event_report_t;

/**
 * IMC External
 */
/* from IMC to LTECSR */
typedef struct s_ltecsr_media_new {
	LOCAL_PARA_HDR
    kal_uint32  tv_sec;         // IMCB use gettimeofday to get the time from 1970 (sec)
	xxx2ltecsr_param_t param;
} ltecsr_media_new_struct;

typedef struct s_ltecsr_media_del {
	LOCAL_PARA_HDR
	xxx2ltecsr_param_t param;
} ltecsr_media_del_struct;

typedef struct s_ltecsr_media_update {
	LOCAL_PARA_HDR
	xxx2ltecsr_param_t param;
} ltecsr_media_update_struct;

typedef struct s_ltecsr_dtmf_req {
	LOCAL_PARA_HDR
	xxx2ltecsr_dtmf_param_t param;
} ltecsr_dtmf_req_struct;

typedef struct s_ltecsr_media_active {
	LOCAL_PARA_HDR
	kal_int32 cid;
} ltecsr_media_active_struct;

/* from LTECSR to IMC */
typedef struct s_ltecsr_media_no_dlpkt_struct {
	LOCAL_PARA_HDR
	kal_int32 cid;
} ltecsr_media_no_dlpkt_struct;


/**
 * L1SP External
 */
typedef struct s_ltecsr_voice_ul_data_notify {
	LOCAL_PARA_HDR
} ltecsr_voice_ul_data_notify_struct;

/**
 * LTECSR Internal
 */
typedef struct s_ltecsr_media_init {
	LOCAL_PARA_HDR
	xxx2ltecsr_param_t param;
} ltecsr_media_init_struct;

typedef struct s_ltecsr_media_start {
	LOCAL_PARA_HDR
	kal_int32 cid;
	kal_int32 sid;
} ltecsr_media_start_struct;

typedef struct s_ltecsr_media_stop {
	LOCAL_PARA_HDR
	kal_int32 cid;
	kal_int32 sid;
} ltecsr_media_stop_struct;

typedef struct s_ltecsr_media_xmit_mode_set {
	LOCAL_PARA_HDR
	kal_int32 cid;
	kal_int32 sid;
	kal_int8 xmit_mode; /* xmit_mode_e */
} ltecsr_media_xmit_mode_set_struct;

typedef struct s_ltecsr_dtmf_play {
	LOCAL_PARA_HDR
	xxx2ltecsr_dtmf_param_t param;
} ltecsr_dtmf_play_struct;

typedef struct s_ltecsr_dtmf_stop {
	LOCAL_PARA_HDR
	kal_int32 cid;
} ltecsr_dtmf_stop_struct;

typedef struct s_ltecsr_media_pt_set {
	LOCAL_PARA_HDR
	kal_int32 cid;
	kal_int32 codec;
	kal_int32 pt;
} ltecsr_media_pt_set_struct;

typedef struct s_ltecsr_rtcp_send_interval_set {
	LOCAL_PARA_HDR
	kal_int32 cid;
	kal_int32 sid;
	kal_int32 rtcp_send_interval;
} ltecsr_rtcp_send_interval_set_struct;

#endif

