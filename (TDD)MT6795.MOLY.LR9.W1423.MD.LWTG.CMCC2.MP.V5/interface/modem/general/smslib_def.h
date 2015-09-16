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
 * smslib_def.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains definition
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _SMSLIB_DEF_H
#define _SMSLIB_DEF_H

#if defined(__SMS_STORAGE_BY_MMI__)


#include "smslib_enum.h"
#include "mcd_l4_common.h"
#include "kal_general_types.h"
#include "ps_public_struct.h"

#define SMSLIB_MTI_BITS                 (0x03)
#define SMSLIB_MAX_CC_ADDR_LEN          (41)    // = MAX_CC_ADDR_LEN
#define SMSLIB_ADDR_LEN                 (11)
#define SMSLIB_ONE_MSG_OCTET            (140)
#define SMSLIB_ONE_REPORT_MSG_OCTET     (143)
#define SMSLIB_MAX_MSG_LEN              (160)
#define SMSLIB_MAX_REPORT_MSG_LEN       (163)
#define SMSLIB_INVALID_PORT_NUM         (-1)
#define SMSLIB_TP_ADDR2_L4_ADDR_LEN(x)  (((x+1)/2)+1)
#define SMSLIB_CUSTOM_WILD_CHAR '?'

/*------------------------------
 * Length of SIM EF
 *------------------------------*/
#define SMSLIB_SMS_STATUS_LEN     (2)   /* length of a EFsmss */
#define SMSLIB_SMS_LEN            (176) /* length of a SIM EFsms record */
#define SMSLIB_SMS_ME_LEN         (184) /* length of a ME EFsms record +7 byte SCT +1 pad */
#define SMSLIB_SMSP_LEN           (28)  /* length of a EFsmsp record */
#ifdef __CPHS__
#define SMSLIB_MWF_LEN            (1)
#endif
#define SMSLIB_EXT_LEN            (13)  /* length of a SIM EFext1/6 record */
#define SMSLIB_MAILBOX_NUM_LEN    (14)

#ifdef __REL6__
    #ifdef __SMS_R6_ENHANCED_VOICE_MAIL__
#define SMSLIB_MAX_MW_SOURCE      (4)
    #else
#define SMSLIB_MAX_MW_SOURCE      (3)
    #endif
#else
#define SMSLIB_MAX_MW_SOURCE      (3)
#endif

/*--------------------------------------------
 * Length of SMS peer message header (part)
 *--------------------------------------------*/
/* fo(1), pid(1), dcs(1), scts(7), udl(1), oa_len(1), oa_type(1) */
#define SMSLIB_PART_OF_DELIVER_HEADER_LEN     (13)

/* fo(1), mr(1), pid(1), dcs(1), udl(1), da_len(1), da_type(1) */
#define SMSLIB_PART_OF_SUBMIT_HEADER_LEN      (7)

/* fo(1), mr(1), ra_len(1), ra_type(1), scts(7), dt(7) */
#define SMSLIB_PART_OF_REPORT_HEADER_LEN      (19)  //ToCheck


/*------------------------------------
 * Information Element Identifier
 *------------------------------------*/
#define SMSLIB_CONC8_MSG_IEI         (0x00)
#define SMSLIB_CONC16_MSG_IEI        (0x08)
#define SMSLIB_SPECIAL_MSG_IND_IEI   (0x01)
#define SMSLIB_ENHANCED_VM_INFO_IEI  (0x23)


#if defined (__CPHS__) /* NEW */
/*-------------------------------------
 * For CPHS Voice Mail Indication
 *-------------------------------------*/
#define SMSLIB_CPHS_VM_ADDR_TYPE  (0xd0)
#define SMSLIB_CPHS_VM_SET_BITS   (0x01)
#define SMSLIB_CPHS_VM_IND_BITS   (0x0e)
#define SMSLIB_CPHS_VM_LINE_BITS  (0x80)
#endif

/* SIM SMSP */
#define SMSLIB_SMSP_DA_BITS    (0xfe)
#define SMSLIB_SMSP_SCA_BITS   (0xfd)
#define SMSLIB_SMSP_PID_BITS   (0xfb)
#define SMSLIB_SMSP_DCS_BITS   (0xf7)
#define SMSLIB_SMSP_VP_BITS    (0xef)

/* EMS */
#define SMSLIB_EMS_TEXT_FORMAT_IEI   (0x0a)   /* Text Formating */
#define SMSLIB_EMS_PREDEF_SND_IEI    (0x0b)   /* Predefined Sound */
#define SMSLIB_EMS_USER_DEF_SND_IEI  (0x0c)   /* User Defined Sound */
#define SMSLIB_EMS_PREDEF_ANM_IEI    (0x0d)   /* Predefined Animation */
#define SMSLIB_EMS_LARGE_ANM_IEI     (0x0e)   /* Large Animation */
#define SMSLIB_EMS_SMALL_ANM_IEI     (0x0f)   /* Small Animation */
#define SMSLIB_EMS_LARGE_PIC_IEI     (0x10)   /* Large Picture */
#define SMSLIB_EMS_SMALL_PIC_IEI     (0x11)   /* Small Picture */
#define SMSLIB_EMS_VAR_PIC_IEI       (0x12)   /* Variable Picture */

/* MISC */
#define SMSLIB_APP_PORT8_IEI         (0x04)   /* application port - 8 bit */
#define SMSLIB_APP_PORT16_IEI        (0x05)   /* application port - 16 bit */
#define SMSLIB_NL_SINGLE_IEI         (0x24)   /* National Language single shift */
#define SMSLIB_NL_LOCKING_IEI        (0x25)   /* National Language looking shift */


/*------------------------------
 * Status byte in SMS
 * RFU shall be set to zero !!
 * 12/27/2002 Kevin
 *------------------------------*/
#define SMSLIB_UNUSED_MSG              (0x00)

/* MT: Receive from network */
#define SMSLIB_UNREAD_MSG              (0x03)
#define SMSLIB_READ_MSG                (0x01)

/* MO: Sent to network */
#define SMSLIB_UNSENT_MSG              (0x07)
#define SMSLIB_SENT_NO_SRR             (0x05)
#define SMSLIB_SENT_SRR_NOT_RECV       (0x0d)
#define SMSLIB_SENT_SRR_RECV_NOT_STO   (0x15)
#define SMSLIB_SENT_SRR_RECV_STO       (0x1d)

#define SMSLIB_DRAFT_MSG               (0x27)

#ifdef __SMS_MSP_UP_TO_4__
#define SMSLIB_MAX_MSP_NUM     4  //(max support msp)
#ifdef __REL6__
#define SMSLIB_MAX_MBDN_NUM    10 // 20 is too much, reduce to 10
#else
#define SMSLIB_MAX_MBDN_NUM    10 // 16 is too much, reduce to 10
#endif
#else //__SMS_MSP_UP_TO_4__
#define SMSLIB_MAX_MSP_NUM     2 //(max support msp)
#ifdef __REL6__
#define SMSLIB_MAX_MBDN_NUM    10 //(5 * SMSAL_MAX_MSP_NUM, max support mbdn)
#else
#define SMSLIB_MAX_MBDN_NUM    8 //(4 * SMSAL_MAX_MSP_NUM, max support mbdn)
#endif
#endif //__SMS_MSP_UP_TO_4__


typedef struct
{
    kal_uint8   reply_flag;             /* whether reply is sought*/
    kal_uint8   udh_p;                  /* indicates presence of
                                           user data header*/
    kal_uint8   status_rep_flag;        /* whether status reports
                                           are sought*/
    kal_uint8   fill_bits;              /* to be ignored*/
    kal_uint8   mms;                    /* more message to send*/
    kal_uint8   msg_type;               /* sms deliver*/
    kal_uint8   no_orig_addr;
    kal_uint8   orig_addr_size;         /* the max size of *orig_addr in octet*/
    kal_uint8   *orig_addr;             /* assumed to be
                                           byte-packed*/
    kal_uint8   pid;                    /* to be bit-wise decoded*/
    kal_uint8   dcs;                    /* to be bit-wise decoded*/
    kal_uint8   scts[7];
    kal_uint8   user_data_len;
    kal_uint8   no_user_data;           /* 7-bit to octet */
    kal_uint8   user_data_size;         /* the max size of *user_data in octet*/
    kal_uint8   *user_data;             /* can have user data header also*/
} smslib_deliver_peer_struct;

typedef struct
{
    kal_uint8   reply_flag;             /* whether reply is sought*/
    kal_uint8   udh_p;                  /* indicates presence of
                                           user data header*/
    kal_uint8   status_rep_flag;        /* whether status reports
                                           are sought*/
    kal_uint8   vp_flag;                /* indicates presence of
                                           validity period*/
    kal_uint8   rej_dup_flag;
    kal_uint8   msg_type;               /* sms submit*/
    kal_uint8   msg_ref;                /* to be read from SIM*/
    kal_uint8   no_dest_addr;
    kal_uint8   dest_addr_size;         /* the max size of *dest_addr in octet*/
    kal_uint8   *dest_addr;             /* assumed to be
                                           byte-packed*/
    kal_uint8   pid;                    /* to be bit-wise encoded*/
    kal_uint8   dcs;                    /* to be bit-wise encoded*/
    kal_uint8   no_validity_period;
    kal_uint8   validity_period_size;
    kal_uint8   *validity_period;       /* to be
                                           bit/byte-wise
                                           encoded, cannot
                                           be even represnted
                                           using CHOICE*/
    kal_uint8   user_data_len;
    kal_uint8   no_user_data;           /* 7-bit to octet */
    kal_uint8   user_data_size;         /* the max size of *user_data in octet*/
    kal_uint8   *user_data;             /* can have user data header also*/
} smslib_submit_peer_struct;

typedef struct
{
    kal_uint8   fill_bits1;             /* to be ignored*/
    kal_uint8   udh_p;                  /* indicates presence of
                                           user data header*/
    kal_uint8   status_rep_type;        /* sms command or sms
                                           submit*/
    kal_uint8   fill_bits2;             /* to be ignored*/
    kal_uint8   mms;
    kal_uint8   msg_type;               /* sms status report*/
    kal_uint8   msg_ref;
    kal_uint8   no_rcpnt_addr;
    kal_uint8   rcpnt_addr_size;        /* the max size of *rcpnt_addr in octet*/
    kal_uint8   *rcpnt_addr;
    kal_uint8   scts[7];
    kal_uint8   dis_time[7];
    kal_uint8   status;                 /* actual status of submit*/
    kal_uint8   params_p;               /* depicts presence of
                                           optional parameters*/
    kal_uint8   pid;                    /* to be bit-wise decoded*/
    kal_uint8   dcs;                    /* to be bit-wise decoded*/
    kal_uint8   user_data_len;
    kal_uint8   no_user_data;           /* 7-bit to octet */
    kal_uint8   user_data_size;         /* the max size of *user_data in octet*/
    kal_uint8   *user_data;             /* can have user data header also*/
} smslib_status_report_peer_struct;

typedef struct 
{
    kal_uint8 addr_length;
    kal_uint8 addr_bcd[11];
} smslib_addr_struct;   //TP Addr Type

/* defined in l4c_aux_struct.h
              mcd_l4_common.h

typedef struct
{
    kal_uint8 addr_length;
    kal_uint8 addr_bcd[41];
} l4_addr_bcd_struct;   //RP Addr Type

typedef struct
{
    kal_uint8 type;
    kal_uint8 length;
    kal_uint8 number[SMSLIB_MAX_CC_ADDR_LEN];
} l4c_number_struct;    //MMI Addr Type

typedef struct
{
	kal_uint8 name_length;
	kal_uint8 name_dcs;
	kal_uint8 name[32];
} l4_name_struct;

typedef struct
{
    kal_uint8 length;
    kal_uint8 charset;
    kal_uint8 *data;
} istring_type; */

typedef struct
{
    kal_uint8 waiting_num[SMSLIB_NUM_OF_MSG_WAITING_TYPE];
} smslib_mwis_struct; // = smsal_mwis_struct (!!!important!!!)

#ifdef __REL6__
#ifdef __SMS_R6_ENHANCED_VOICE_MAIL__
// Enhanced Voice Mail Information
typedef struct
{
    kal_uint16  id;

    kal_uint8   msg_len_insec;
    kal_uint8   msg_retention_day;  // max 31

    kal_uint8   priority;

    kal_uint8   msg_ext_flg;

    l4_addr_bcd_struct   calling_line_addr;

    kal_uint8   msg_ext_len;
    kal_uint8   *msg_ext_data;
}smslib_evmi_msg_struct; // = smsal_evmi_msg_struct (!!!important!!!)

// Enhanced Voice Mail Information
// l4csmsal_enhanced_voice_mail_ind_struct should be the same as smsal_evmi_struct
typedef struct
{
    kal_uint8   evm_pdu_type;
    kal_uint8   multi_sub_profile;
    kal_uint8   is_store;
    kal_uint8   vm_almost_full;
    kal_uint8   vm_full;
    kal_uint8   vm_status_ext_flg;

    l4_addr_bcd_struct   vm_access_addr;
    kal_uint8   number_of_vm_unread;  // should be stored in (U)SIM
    kal_uint8   number_of_vm_notify;  // max 15
    kal_uint8   number_of_vm_delete;  // max 31

    kal_uint8   l4_status;        // 0:init, 1: sent to MMI, 2:free

    kal_uint8   vm_status_ext_len;
    kal_uint8   *vm_status_ext_data;

    smslib_evmi_msg_struct *vm_msg[32];

}smslib_evmi_struct;  // = smsal_evmi_struct (!!!important!!!)
#endif
#endif

typedef struct
{
    kal_uint8         type_of_info;
    kal_bool          need_store;
    kal_bool          is_msg_wait;
    kal_bool          is_show_num[SMSLIB_NUM_OF_MSG_WAITING_TYPE];
    kal_bool          is_clear[SMSLIB_NUM_OF_MSG_WAITING_TYPE];
    kal_bool          ind_flag[SMSLIB_NUM_OF_MSG_WAITING_TYPE];
    smslib_mwis_struct mwis;
    kal_uint8         msp;
    kal_uint8         line_no;

#ifdef __REL6__    
#ifdef __SMS_R6_ENHANCED_VOICE_MAIL__
    smslib_evmi_struct evmi;  // should free this after processing
#endif
#endif
} smslib_msg_waiting_struct; // = smsal_msg_waiting_struct (!!!important!!!)

typedef struct
{
    kal_int32 dest_port; /* -1: invalid port */
    kal_int32 src_port;
} smslib_port_struct; // = smsal_port_struct

typedef struct
{
    kal_uint16 ref;      /* concat. message reference*/
    kal_uint8 total_seg; /* total segments*/
    kal_uint8 seg;       /* indicate which segment*/
} smslib_concat_struct; // = smsal_concat_struct (!!!important!!!)

typedef struct
{
    union
    {
        smslib_deliver_peer_struct        deliver_tpdu;
        smslib_submit_peer_struct         submit_tpdu;
        smslib_status_report_peer_struct  report_tpdu;
    } data;

    smslib_mti_enum             mti;

    //
    kal_uint8                   fo;     /* first octet */
    kal_uint8                   offset; /* offset to message content */
                                        /* init address of User Data Header */
    kal_uint8                   msg_len;/* length of user data */
                                        /* User Data Header + User Data */
    kal_uint8                   udhl;   /* for calculating offset to unpack */
                                        /* udhl + udh */

    smslib_concat_struct        concat_info;

    /* for decoding DCS */
    smslib_msg_class_enum       msg_class;
    smslib_alphabet_enum        alphabet_type;
    kal_bool                    is_compress;


    smslib_msg_waiting_struct   msg_wait;

    /* User Data Header */
    smslib_port_struct          port;

} smslib_tpdu_decode_struct;

typedef struct
{
    smslib_sim_status_enum      status;
    l4_addr_bcd_struct          sca;
    smslib_tpdu_decode_struct   tpdu;
    kal_uint8                   pdu_len;   /* length of PDU */
    kal_uint8                   tpdu_len;  /* length of TPDU */
    l4c_number_struct           forMMI_SCAAddr;
    l4c_number_struct           forMMI_TPAddr;
    kal_uint16                  forMMI_UserData_length;  /*unit: octet*/
    kal_uint8                   forMMI_UserData[170];
} smslib_general_struct;

typedef struct
{
    /* alpha id size of EFmailbox_numr */
    kal_uint8           alpha_size;             //Input value for decode & encode
    
    l4_name_struct      name;
    l4c_number_struct   addr;
    kal_uint8           capability_id;
    kal_uint8           extension_id;
}smslib_ef_mailbox_num_struct;

typedef struct
{
    kal_uint8           mbi_id[SMSLIB_NUM_OF_MSG_WAITING_TYPE];
}smslib_ef_mbi_struct; 

typedef struct
{
    kal_uint8           waiting_num[SMSLIB_NUM_OF_MSG_WAITING_TYPE];
} smslib_ef_mwis_struct;

typedef struct
{
    smslib_mwis_struct  cphs_mwis[SMSLIB_MAX_LINES]; 
}smslib_ef_vm_struct;

typedef struct
{
    /* maximum number of supported, SMS parameter profiles in SIM */
    //kal_uint8	        max_profile_num;        //Input value for decode

    /* size of alpha-identifier in EFsmsp */
    kal_uint8           alpha_size;             //Input value for decode
                                                //Input value for encode
    /* store alpha-identifier */
    l4_name_struct      profile_name;           //Input&Output value for decode
                                                //Input&Output value for encode
    /* Parameter Indicator */
    kal_uint8	        para_ind;               //Output value for decode
                                                //Input value for encode
    /*	Validity period */
    kal_uint8	        vp;                     //Output value for decode
                                                //Input value for encode
    /*	Protocol identifier */
    kal_uint8	        pid;                    //Output value for decode
                                                //Input value for encode
    /*	Data coding scheme */
    kal_uint8	        dcs;                    //Output value for decode
                                                //Input value for encode
    /* Service Centre Address */
    l4c_number_struct   sca;                    //Output value for decode
                                                //Input value for encode
    /* Destination Address */
    l4c_number_struct   da;                     //Output value for decode
                                                //Input value for encode
}smslib_ef_smsp_struct;

#endif // __SMS_STORAGE_BY_MMI__

#endif
