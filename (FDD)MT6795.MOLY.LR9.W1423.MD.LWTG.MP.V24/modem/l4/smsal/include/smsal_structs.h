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
 *	smsal_structs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for defining data structures used in SMSAL context.
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

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


#ifndef _SMSAL_STRUCTS_H
#define _SMSAL_STRUCTS_H

#include "smsal_l4c_enum.h"
#include "l3_inc_enums.h"
#include "l4c2smsal_struct.h"
#include "smsal_peer_struct.h"
#include "mnsms_struct.h"
#include "nvram_editor_data_item.h"
#include "mcd_l4_common.h"
//#include "smslib_def.h"
#include "smsal_defs.h"
#include "smsal_l4c_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "ps_public_struct.h"
#include "ps_public_enum.h"

#ifdef __SMS_STORAGE_BY_MMI__
#ifdef __SMS_ME_STORAGE__
#undef __SMS_ME_STORAGE__
#endif
#endif


#define SMSAL_MAX_FILE 22

typedef struct _nvram_smsal_common_param_struct smsal_nvm_common_param_struct;

struct _read_file_aux_info_struct;

typedef struct _read_file_aux_info_struct smsal_read_file_aux_info_struct;

typedef kal_uint8 (*READ_FILE_FUNC)(kal_uint8, /* id */
                                   smsal_read_file_aux_info_struct *,
                                   peer_buff_struct  *, 
                                   local_para_struct *);

typedef void (*READ_FILE_FINISH_FUNC)(kal_uint8, /* id */
                                      kal_bool  /* result */);

typedef void (*READ_FILE_ERROR_FUNC)(kal_uint8      result,
                                     kal_uint32     error_cause,
                                     kal_uint8      src_id);

typedef struct
{  
   kal_bool        is_used; 
   smsal_file_enum file_id;
   kal_uint8       read_type;
   READ_FILE_FUNC  succ_fn_ptr;   
   READ_FILE_FUNC  fail_fn_ptr;   
} file_list_struct;

struct _read_file_aux_info_struct
{
   kal_uint32            file_type_bitmap;  /* 0: sim, 1: nvram
                                             * bit0: 1st read file
                                             * bit1: 2nd read file, so on 
                                             */
                                             
   kal_bool              occur_error;       /* whether occur error during
                                             * reading files */
   kal_uint8             current_read_idx;  /* index of current read file */
   kal_uint16            record_no;         /* current record no */
#if defined (__CPHS__) || defined (__REL4__)
   kal_uint16            ext_record_no;     /* current ext record no */
#endif
   kal_uint16            number;            /* store number of records */
   kal_uint16            nvram_rec_amount;  /* nvram multiple recoder reading */
   kal_uint16            nvram_rec_decoded; /* number of record already prcessed */
   kal_bool              send_init_cnf;     /* for SIM refresh during SMSAL initialization */

   kal_uint8             msg_box_seq_num;   /* used during startup */

   file_list_struct      file[SMSAL_MAX_FILE];
   READ_FILE_FINISH_FUNC finish_fn_ptr;     
};

//#if defined(__SMS_STORAGE_BY_MMI__)
// should be the same between "smslib_mwis_struct" and "smsal_mwis_struct"
//typedef struct smslib_mwis_struct smsal_mwis_struct;
//#else
/* Message Waiting Indication Status */
typedef struct
{
   //kal_uint8 waiting_ind;
   kal_uint8 waiting_num[NUM_OF_MSG_WAITING_TYPE];
} smsal_mwis_struct;
//#endif


/* defined in l4c2smsal_struct.h
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
}smsal_evmi_msg_struct;
*/

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

    smsal_evmi_msg_struct *vm_msg[32];

}smsal_evmi_struct;


typedef struct 
{
   kal_uint8         type_of_info;
   kal_bool          need_store;
   kal_bool          is_msg_wait;
   kal_bool          is_show_num[NUM_OF_MSG_WAITING_TYPE];
   kal_bool          is_clear[NUM_OF_MSG_WAITING_TYPE];
   kal_bool          ind_flag[NUM_OF_MSG_WAITING_TYPE];
   smsal_mwis_struct mwis;    
   kal_uint8         msp;
   kal_uint8         line_no;

#ifdef __SMS_R6_ENHANCED_VOICE_MAIL__
   smsal_evmi_struct evmi;  // should free this after processing
#endif
} smsal_msg_waiting_struct;

typedef struct
{
   /* smsal_mb_entry_state_enum */
   kal_uint8                       state;
                                    /* state of the entry */

   /* smsal_storage_enum */
   kal_uint8                        storage_type;                                    
                                    /* storage type of the entry */

   /* smsal_mti_enum */
   kal_uint8                        mti;
                                    /* message type identifier */

   kal_uint8                        status;        
                                    /* status of the message */

   kal_uint16                       record_no;     
                                    /* indicate record number in storage */

   kal_uint16                       mb_type_ind;     
                                    /* bitmap for specific type SM, ie. PID with replace type,  */
                                    /* FO with reply path.                                      */

} smsal_mb_entry_struct;

typedef struct
{     
   kal_uint16   inbox_sim_num;
   kal_uint16   outbox_sim_num;
   
#ifndef __SMS_STORAGE_BY_MMI__
#ifdef __SMS_ME_STORAGE__   
   kal_uint16   inbox_me_num;
   kal_uint16   outbox_me_num;
#endif
#else
   kal_uint16   inbox_me_num;
   kal_uint16   outbox_me_num;
#endif

   kal_uint16   sim_msg_num;        /* maximum number of supported messages in SIM */
   kal_uint16   used_sim_msg_num;
   
#ifndef __SMS_STORAGE_BY_MMI__
#ifdef __SMS_ME_STORAGE__
   kal_uint16   me_msg_num;      /* maximum number of supported messages in ME */
   kal_uint16   used_me_msg_num;
#endif
#else
   kal_uint16   me_msg_num;         /* maximum number of supported messages in ME */
   kal_uint16  used_me_msg_num;
#endif
   
   //kal_uint8   is_sim_full;    /* only used for AT-Command ... currently no used */
   kal_uint8   is_me_full;     /* only used for AT-Command (pretended full) */
   
} smsal_storage_num_struct;


typedef struct
{      
   l4_name_struct       profile_name;
                        /* store alpha-identifier */

   kal_uint8	         para_ind;                              
                        /* Parameter Indicator */

   kal_uint8	         vp;                                    
                        /*	Validity period */

   kal_uint8	         pid;                                   
                        /*	Protocol identifier */

   kal_uint8	         dcs;                                   
                        /*	Data coding scheme */

   sms_addr_struct      sca;  
                        /* Service Centre Address */

   sms_addr_struct      da;  
                        /* Destination Address */

} smsal_profile_element_struct;

/* KEEP this struct even SAT is not supported */
typedef struct 
{
   sms_addr_struct        sc_addr;
   sms_addr_struct        dest_addr;   
} smsal_sat_addr_struct;


typedef struct
{
   kal_int32 dest_port; /* -1: invalid port */
   kal_int32 src_port;
} smsal_port_struct;

#if defined(__SMS_STORAGE_BY_MMI__)

#if defined(__SMSAL_MODI_PEER_REST_C)
    //NA
#elif defined(__SMSAL_UTILS_C)
    //NA
#else
    #if defined(__SMSAL_XXX_C)
    typedef smslib_tpdu_decode_struct smsal_tpdu_decode_struct;
    #endif
#endif

#else
typedef struct
{
   union 
   {
      smsal_deliver_peer_struct  deliver_tpdu;
      smsal_submit_peer_struct   submit_tpdu;
      smsal_status_report_peer_struct  report_tpdu;
   } data;

   smsal_concat_struct        concat_info;
                
   smsal_mti_enum             mti;      
   kal_uint8                  fo;     /* first octet */
   kal_uint8                  offset; /* offset to message content */
   kal_uint8                  msg_len;/* length of user data */   
  
   kal_uint8                  udhl;   /* for calculating offset to unpack */

   /* for decoding DCS */   
   smsal_msg_class_enum       msg_class;    
   smsal_alphabet_enum        alphabet_type;
   kal_bool                   is_compress;
   smsal_msg_waiting_struct   msg_wait;

   smsal_port_struct          port;

} smsal_tpdu_decode_struct;
#endif

#if defined(__SMS_STORAGE_BY_MMI__)

#if defined(__SMSAL_MODI_PEER_REST_C)
    //NA
#elif defined(__SMSAL_UTILS_C)
    //NA
#else
    #if defined(__SMSAL_XXX_C)
    typedef smslib_general_struct smsal_pdu_decode_struct;
    #endif
#endif

#define _SMSAL_UTILS_C

#else
typedef struct
{
   sms_addr_struct          sca;
   smsal_tpdu_decode_struct tpdu; 
   kal_uint8                pdu_len;   /* length of PDU */
   kal_uint8                tpdu_len;  /* length of TPDU */
} smsal_pdu_decode_struct;
#endif

typedef struct
{     
   kal_uint8                  bitmap; /* refer to smsal_reset_file_enum */ 

} smsal_reset_file_aux_info_struct;

typedef struct
{   
   kal_uint16                   index;                                  
   kal_uint8                    storage_type;
} smsal_write_aux_info_struct;

typedef struct
{
   kal_uint8              src_id;
   kal_uint8              msg_ref;
} smsal_pending_send_struct;

#if defined(__SMS_STORAGE_BY_MMI__)
#else
typedef struct
{   
   kal_uint8                   smi;
   kal_uint8                   replace_count;
   kal_uint8                   pid_type;       /* Replace type or Return Call Message */
   kal_bool                    is_msg_writing;
   kal_uint16                  index;                                      
   smsal_pdu_decode_struct     *pdu_decode;   
   kal_uint8                   search_status;  // bit0: SIM, bit1: NVRAM
                                               // 1:search done, 0: not yet
#ifdef __SMS_ME_STORAGE__
   kal_uint8                   storage_type;
#endif
} smsal_mt_msg_aux_info_struct;
#endif

typedef struct
{   
   kal_uint16             index;                                      
   kal_uint8              msg_ref;
   kal_uint8              status;
   sms_addr_struct        rcpnt_addr;

} smsal_status_report_aux_info_struct;


typedef struct
{  
   kal_uint32   set_ind; /* 0: not present 1:present 
                           bit0: common param in NVRAM (NVRAM_EF_SMSAL_COMMON_PARAM_LID)
                           bit1: mailbox num in NVRAM (NVRAM_EF_SMSAL_MAILBOX_ADDR_LID) or 
                                                SIM (FILE_MAILBOX_NUM_IDX if CPHS) 
                           bit2: profile in SIM (FILE_SMSP_IDX)
                           bit3: MBI in SIM (FILE_MBI_IDX)
                           bit4: ext mailbox num */
   smsal_nvm_common_param_struct *common;   
   smsal_profile_element_struct  *profile;
} smsal_set_param_aux_info_struct;

#ifdef __CB__ /* added by Kevin */
typedef struct
{  
   kal_uint8                     ori_para_ind; /* original para_ind */
   kal_uint8                     para_ind; /* smsal_cb_para_enum */

   kal_uint16                    cbmi[CB_MAX_MSG_CBMI_NUM];
   kal_uint16                    cbmir[SMSAL_CB_MAX_ENTRY*2];   
   kal_uint16                    dcs[SMSAL_CB_MAX_ENTRY];

   kal_uint8                     cbmir_mask[SMSAL_CB_MAX_ENTRY];
   kal_uint8                     cbmi_mask[CB_MAX_MSG_CBMI_NUM];
   kal_uint8                     dcs_mask[SMSAL_CB_MAX_ENTRY];

   kal_uint8                     cbmi_num;
   kal_uint8                     cbmir_num;   
   kal_uint8                     dcs_num;

   kal_uint8                     is_all_lang_on;
} smsal_set_cb_aux_info_struct;
#endif

typedef struct
{     
   kal_uint8              src_id;
   kal_uint8              msg_ref;

   kal_uint8            scts[7];
   kal_uint8            sat_res_type;
   
   kal_bool               is_da_modified;
                           /* to identify the DA in sat_addr is modified */
                           /* by RP message or SAT.                      */

   kal_uint8              req_type; /* send message or command */
   smsal_sat_addr_struct  sat_addr;   
   smsal_concat_struct    concat_info;   

   peer_buff_struct       *peer_to_send;

} smsal_send_sms_aux_info_struct;

#if defined (__SAT__)
typedef struct
{  
   kal_uint8              smi; 
   kal_uint8              dcs;      
   kal_uint8              pid;
} smsal_sim_dl_aux_info_struct;
#endif

typedef struct
{  
   kal_uint8              smi; 
   kal_uint8              dcs;      
   kal_uint8              pid;
} smsal_sms_depersonalization_aux_info_struct;

typedef struct 
{
   kal_uint8            in_use;           /* KAL_TRUE:  used
                                             KAL_FALSE: free to use */
   kal_uint8            act_code;         /* Main action code */
   kal_uint8            sub_act_code;     /* Sub action code */

   // [MAUI_01422850] Abort Sending, delay free pending_act until storage confirmation
   kal_uint8            action_status;    /* bit0: 0 normal, 1 abort sending
                                             bit1: 0 normal, 1 has sent request to SMS
                                             bit7: 1 normal, 0 not processed, pending
                                                   for concurrent request from L4C or MT-SMS */

   local_para_struct    *local_para_ptr;  /* To hold the pointer 
                                             of request struct */

   peer_buff_struct     *peer_buff_ptr;   /* To hold the pointer of
                                             peer message */

   void                 *aux_info;        /* auxiliary information which 
                                             store the necessary data */
} smsal_pending_act_struct;

typedef struct
{
   kal_uint8            src_id;
   kal_uint8            seq_num;
   void                 *aux_info;        /* auxiliary information which 
                                             store the necessary data */
} smsal_send_abort_struct;


typedef struct
{
   kal_uint8	status_report;			
   kal_uint8	reply_path;			
   kal_uint8   vp_format;
   kal_uint8	bearer_service;			

   kal_uint8	sms_fdn_off;			
      
   kal_uint8	fo;               /*	First octet , includes 
                                  * reply path, status report request, 
                                  * validity period format, etc. */
   kal_uint8 selected_msp;
} smsal_common_parameter_struct;

typedef struct
{
   kal_uint8	max_profile_num; 	/* maximum number of supported 
                                  * SMS parameter profiles in SIM */

   kal_uint8   alpha_size;       /* size of alpha-identifier in EFsmsp */

   smsal_profile_element_struct profile[SMSAL_MAX_PROFILE_NUM];

} smsal_profile_parameter_struct;

typedef struct
{   
   /*smsal_service_mode_enum*/
   kal_uint8                     service_mode;
   smsal_service_mode_struct	   service_info;
   smsal_mt_msg_route_struct	   nmi_para;          
                                 /*	New Message Indication Parameters */
                                 
   /*smsal_storage_enum*/
   kal_uint8                     prefer_mem1;
   kal_uint8                     prefer_mem2;
   kal_uint8                     prefer_mem3;
   
   /*smsal_msg_format_enum*/
   kal_uint8              	      message_format;    /* 0: PDU mode 1:TEXT mode */
   
#if defined(__SMS_STORAGE_BY_MMI__)
   kal_uint8                     force_msg_mode;
   // 0: PDU mode, 1:TEXT mode, else:OFF
   // to distinguish
   // +cmgs send by AT, form AT          <= text mode/pdu mode
   // +cmss sned by AT, from MMI storage <= pdu always
#endif
   
   //kal_uint8	                  sdh;	            /* Show Detailed Header		
   //                                                   0: not show 1: show */
   kal_uint8	                  mms;              /*	mode of More Message to Send		
                                                      refer to 127.005 3.5.6 */

   /* RMI activate profile ID, refer to smsal_profile_parameter_struct  */
   kal_uint8                     act_pfile_id;

   kal_uint8                     set_read_status;

   /* running profile, ie: running setting for RMI */
   smsal_profile_element_struct  profile;

} smsal_rmi_parameter_struct;

typedef struct
{
#if defined(__REL4__)
   smsal_mwis_struct          r4mwis[SMSAL_MAX_MSP_NUM]; /* msg waiting status for r4 */
#endif
    /* msg waiting status, if support rel4, line1 will be the same as sel msp in r4mwis */
   smsal_mwis_struct          mwis[SMSAL_MAX_LINES];

   smsal_mailbox_addr_struct  addr[SMSAL_MAX_MAILBOX_NUM]; /* mailbox address */

#if defined (__CPHS__) || defined (__REL4__)
   kal_uint8                  rec_bitmap[SMSAL_MAX_EXT_NUM/8]; /* length is not final value, for ext1 */
   kal_uint8                  ext_rec_num;    /* record number of EFext1/6*/
#endif

   kal_uint8                  alpha_size;     /* alpha id size of EFmailbox_numr */

#ifdef __CPHS__
   kal_uint8                  mwf_file_size;  /* file size of EFmwf */
#endif

   kal_uint8                  rec_num;        /* record number of EFmailbox_numr or EFmbdn*/

#ifdef __REL4__
   smsal_mbi_struct           mbi[SMSAL_MAX_MSP_NUM];
   kal_uint8                  mbi_rec_num;        /* record number of EFmbi */
   kal_uint8                  mbi_rec_length;        /* record length of EFmbi */
   kal_uint8                  mwis_rec_num;       /* record number of EFmwis */
   kal_uint8                  mwis_rec_length;       /* record length of EFmwis */
#endif

} smsal_mailbox_info_struct;

typedef struct
{     
   smsal_rmi_parameter_struct       rmi;
   smsal_common_parameter_struct    common;
   smsal_profile_parameter_struct   profile;
   smsal_mailbox_info_struct        mailbox;               
} smsal_parameter_struct;

typedef struct
{
   kal_bool    is_used;
   kal_bool    sent_report;
   kal_uint8   smi;
} smsal_pending_cnmi_struct;

typedef struct
{
   kal_bool    pending_smma;
} smsal_pending_smma_struct;


#ifdef __CB__

/* for CB queueing */
typedef struct
{
   kal_uint8  total_pages; /* 0xff: not used */
   kal_uint8  page;
   kal_uint8  recv_pages;
   kal_uint8  dcs;
   kal_uint8  alphabet;
   kal_uint16 cbmi;   
   kal_uint16 sn;   
   kal_uint16 pages_map; /* bit map for received pate */
   kal_uint32 last_time; /* unit: system ticks */
   kal_uint8  page_offset[15]; /* offset of each page */
   l4csmsal_cb_msg_text_ind_struct *msg_ind ;    /* for start pointer of data */
} smsal_cb_ctrl_block_struct;


#if defined(__3G_CB_SERVICE_BY_PLMN__)

typedef enum
{
  SMSAL_CB_3G_SERVICE_NULL = 0, 
  SMSAL_CB_3G_SERVICE_ON,      
  SMSAL_CB_3G_SERVICE_OFF       
} smsal_cb_3g_service_type_enum;

#endif


typedef struct
{
   kal_uint8                             cbch_req;
   kal_uint8                             hz_act;

   kal_uint16                            cbmi_default[SMSAL_DEFAULT_CBMI_ENTRY];
   kal_uint16                            cbmi[CB_MAX_MSG_CBMI_NUM];
   kal_uint16                            cbmir[SMSAL_CB_MAX_ENTRY*2];
   kal_uint16                            dcs[SMSAL_CB_MAX_ENTRY];
   kal_uint16                            cbmid[SMSAL_CB_MAX_ENTRY];

   kal_uint8                             cbmi_mask[CB_MAX_MSG_CBMI_NUM];
   kal_uint8                             cbmir_mask[SMSAL_CB_MAX_ENTRY];/* added by Kevin */
   kal_uint8                             dcs_mask[SMSAL_CB_MAX_ENTRY];

   kal_uint8                             cbmi_num;
   kal_uint8                             cbmir_num;
   kal_uint8                             dcs_num;
   kal_uint8                             dcs_num_sim;
   kal_uint8                             cbmid_num;

   kal_bool                              is_elp_used; /* true: if EFelp is used */
   kal_bool                              is_li_used;  /* true: if USIM EFli is used */

   kal_bool                              all_lang_on; /* true: all cb languages turn on */  
#ifdef __LTE_RAT__
   kal_bool                              is_itRAT;    /* true: if in interRAT period, CB setting should be reset*/
                                                      /* only distinguish  2/3G <-> 4G*/
#endif
   
   /* for CB queueing */
   smsal_cb_ctrl_block_struct            ctrl_blk_pool[SMSAL_CB_MAX_SESSION];

#ifdef __SAT__
#ifdef __REL6__
   local_para_struct                     *local_para_ptr;
   peer_buff_struct                      *peer_buff_ptr;
#endif
#endif

    l4c_cb_set_type_enum                 set_type;
    kal_bool                             is_cbmir_in_nvram;
    kal_uint8                            cb_msg_num;

#if defined(__3G_CB_SERVICE_BY_PLMN__)
    smsal_cb_3g_service_type_enum           cb_service;
#endif
} smsal_cb_struct;
#endif

typedef struct
{
   kal_int32 port[SMSAL_MAX_REG_PORT_NUM];    /* invalid: SMSAL_INVALID_PORT_NUM */
   kal_uint16 mod_id[SMSAL_MAX_REG_PORT_NUM];
} smsal_reg_port_struct;

#if defined(__SMS_ME_STORAGE__) 
typedef struct
{
   smsal_concat_struct concat_info; /* total_seg = 1 : free slot */	
   kal_uint16          hash;
   kal_uint8           storage_type;
} smsal_concat_msg_save_struct;
#endif

#endif /* _SMSAL_STRUCTS_H */

