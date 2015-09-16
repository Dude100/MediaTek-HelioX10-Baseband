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
 *	smsal_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains enumeration definitions for SMSAL module.
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


#ifndef _SMSAL_ENUMS_H
#define _SMSAL_ENUMS_H

#define smsal_error_cause_enum   ps_cause_enum


/* This enum provides all the checks related to peer header parameters */
typedef enum
{
#if 0 /* kevin */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

    /* Check for telematics support */
    SMSAL_TELEMATICS_CHECK = 0x20,
    
    /* Check for TYPE0 short messages */
    SMSAL_MSG_TYPE0_CHECK  = 0x3F,
    
    /* Check for optional paramter
     * of TPDU header PID, DCS, UDL */
    SMSAL_PARAM_CHECK      = 0x03,
    SMSAL_DCS_PRESENT      = 0x02,
    SMSAL_PID_PRESENT      = 0x01,
    
    /* Check for report messages 
     * coming for SMS COMMAND */
    SMSAL_COMMAND_CHECK    = 0xFF,
    
    /* Check for length of TPDU */
    SMSAL_TPDU_LEN_CHECK   = 175

}smsal_msg_check_enum;


/*
 * Message box entry state enum
 */
typedef enum
{
   SMSAL_MB_ENTRY_INVALID = 0x00,
   SMSAL_MB_ENTRY_FREE    = 0x01,  /* already read from storage, 
                                 * corresponding record is not used */
   
   SMSAL_MB_ENTRY_VALID   = 0x02,

   SMSAL_MB_ENTRY_PENDING = 0x04,  /* pending for writing,
                                 * deleting (not by del flag), storing 
                                 * new message */

   SMSAL_MB_ENTRY_DEL_FLAG_PENDING = 0x08, /* pending for deleting 
                                         * (by del flag) */
                                
   SMSAL_MB_ENTRY_REPLACE_PENDING = 0x10  /* pending for replacing messages */
} smsal_mb_entry_state_enum;

typedef enum
{
   SMSAL_MB_TYPE_REPLY_PATH    = 0x01,
   SMSAL_MB_TYPE_REPLACE_MSG   = 0x02,
   SMSAL_MB_TYPE_RCM           = 0x04
                              
} smsal_mb_msg_type_enum;



typedef enum
{
   READ_FROM_SIM,
   GET_FILE_INFO_FROM_SIM,
   READ_FROM_NVRAM,

   /* Linear Fix */
   GET_REC_NUM,
   GET_REC_SIZE,
   GET_REC,
   GET_EXT_REC
} smsal_read_file_type_enum;

typedef enum 
{   
   SMSAL_READ_CURRENT_FILE,
   SMSAL_READ_NEXT_FILE,
   SMSAL_PAUSE_READ

} smsal_read_file_proc_enum;


typedef enum 
{   
   RESET_MWIS_LID         = 0x01,
   RESET_MAILBOX_ADDR_LID = 0x02,
   RESET_CB_CH_INFOR      = 0x04,
   RESET_COMMON_PARAM     = 0x08,
   RESET_SMSAL_SMSP_LID   = 0x10
} smsal_reset_file_enum;

typedef enum 
{   
   /* During Power On */   
   SMSAL_START_REQ = 0,    /* when SIM/NVRAM are ready */

   /* From L4C module */
   SMSAL_READ,
   SMSAL_READ_RAW_DATA,
   SMSAL_WRITE,
   SMSAL_WRITE_RAW_DATA,
   SMSAL_DELETE,
   SMSAL_SAVE_PARAM,
   SMSAL_COPY,
   SMSAL_SET_STATUS,

   SMSAL_SEND_DELIVER_REPORT,

   /* MO SMS */
   SMSAL_SEND_MO_SMS,
   SMSAL_SEND_FROM_STORAGE,
   
   /* MO Mem. avail. */
   SMSAL_SEND_MEM_AVIL,

   /* SAT */   
   SMSAL_SAT_SEND,
   SMSAL_SAT_MO_SMS_CTRL,
   SMSAL_SIM_DOWNLOAD,
   SMSAL_SMU_DEPERSONALIZATION,

#ifdef __CB__
   /* For CB */
   SMSAL_CB_READ,
   SMSAL_CB_WRITE,
#endif

   /* From SMS module */
   SMSAL_DELIVER,
   SMSAL_STATUS_REPORT,
   
   /* Used for init and SIM refresh */
   SMSAL_INIT_PROC,
   SMSAL_SIM_REFRESH,
   SMSAL_FILES_REFRESH,

   SMSAL_RESET_FILE,

   /* __IMS_SUPPORT__ */
   SMSAL_SEND_IMS_MO_SMS,
   SMSAL_SEND_IMS_MEM_AVIL,

} smsal_act_code_enum;

typedef enum
{     
   /* Used for Read request */   
   SMSAL_READ_INDEX,
   SMSAL_READ_NEXT,

   /* Used for Write request */
   SMSAL_WRITE_SINGLE,

   /* Used for Delete request */
   SMSAL_DELETE_INDEX,
   SMSAL_DELETE_FLAG,

   /* Used for Send request */
   /* Used for Send From Storage request */
   SMSAL_SEND_SINGLE,
   SMSAL_READ_RP_MSG,

   SMSAL_GET_MSG_REF,
   SMSAL_FDN_CHECK,
   SMSAL_FDN_CHECK_PENDING,

   /* Used for Send From Storage request */
   SMSAL_READ_MSG_FR_STORAGE,

   /* Used for Save Parameter request */
   SMSAL_SAVE_COMMON_PARAM,
   SMSAL_SAVE_PROFILE_PARAM,
   SMSAL_SAVE_MAILBOX_ADDR,
   SMSAL_SAVE_EXT_MAILBOX_ADDR,
   SMSAL_SAVE_MBI_PARAM,   

   /* Used for SMS-Deliver */
   SMSAL_MT_MSG,
   SMSAL_REPLACE_PENDING_MSG,
   SMSAL_REPLACE_READ_MSG,
   SMSAL_REPLACE_WRITE_MSG,

   /* Used for SAT MO SMS CTRL */
   SMSAL_SAT_SEND_MSG, //AT

   /* __IMS_SUPPORT__ */
   SMSAL_SAT_IMS_SEND_MSG,
   SMSAL_IMS_MT_MSG,

   SMSAL_SAT_SEND_FROM_STORAGE, //AT
   SMSAL_SAT_SEND_FROM_SAT,
   
   /* Used for READ FILE (boot up) */
   SMSAL_READ_SMS_FILE,

   /* Used for TST inject command */
   SMSAL_TST_WRITE,   
   /* Used for TST inject sms sample in ME */
   SMSAL_TST_SMS_SAMPLE_WRITE,
   /* Used for TST inject sms sample in ME (single segment) */
   SMSAL_TST_SMS_SINGLE_WRITE,
   /* Used for TST inject ems5 sample in ME (8 segments) */
   SMSAL_TST_SMS_EMS5_WRITE
} smsal_sub_act_code_enum;

typedef enum
{
   DELIVER_NORMAL_MT_MSG,
   DELIVER_TYPE_0,
   DELIVER_REPLACE,
   DELIVER_RETURN_CALL_MSG,    /* Return Call Messag */
   DELIVER_ME_DE_PERSONAL,
   DELIVER_SIM_DATA_DOWNLOAD,
   DELIVER_ME_DATA_DOWNLOAD,
   DELIVER_ANSI_136_RDATA,
   DELIVER_CPHS_VMW_IND       /* Voice Mail Waiting Ind (followed by CPHS) */
} smsal_deliver_type_enum;

typedef enum
{
   SMSAL_SMSS_MR = 0,         /* Last-Used TP-MR */
   SMSAL_SMSS_MEM_EXD_FLAG    /* SMS "Memory Cap. Exceeded" Not. Flag */
} smsal_smss_offset_enum;

typedef enum
{
   SMSAL_CSMS = 0,
   SMSAL_CPMS,
   SMSAL_CMGF,
   //SMSAL_CSDH,
   SMSAL_CNMI,   
   SMSAL_CMMS,
   SMSAL_CNMA,
   SMSAL_CSCB,
   NUM_OF_FIXED_AT_TEST_STRING
} smsal_at_cmd_test_enum;
   
typedef enum
{
   STORAGE_USED,
   STORAGE_TOTAL
} smsal_storage_info_enum;

typedef enum
{
   SMSAL_BASE_TIMER = 0,
   SMSAL_CNMA_TIMER      
#if defined(__CB__) 
   ,SMSAL_CB_TIMER
#endif
} smsal_timer_enum;

typedef enum
{
   SMSAL_MSG_WAIT_CPHS  = 0x01 ,
   SMSAL_MSG_WAIT_DCS   = 0x02 ,
   SMSAL_MSG_WAIT_UDH       = 0x04 ,
   SMSAL_MSG_WAIT_UDH_EVM   = 0x08
} smsal_type_of_msg_waiting_enum;


#ifdef __CB__
typedef enum
{
   SMSAL_ACT_CB_MI_SIM      = 0x01,
   SMSAL_ACT_CB_MIR         = 0x02,
   SMSAL_ACT_CB_DCS         = 0x04,
   SMSAL_ACT_CB_CH_INFO     = 0x08,
   SMSAL_ACT_CB_ALL_LANG    = 0x10
}smsal_cb_sub_act_enum;

typedef enum
{
   SMSAL_CB_IN_SEQ,
   SMSAL_CB_OUT_SEQ_KEEP,
   SMSAL_CB_OUT_SEQ_DROP
} smsal_cb_in_seq_enum;

#endif

typedef enum {
   SMSAL__DELIVER, 
   SMSAL__DELIVER_REPORT, 
   SMSAL__STATUS_REPORT, 
   SMSAL__COMMAND, 
   SMSAL__SUBMIT, 
   SMSAL__SUBMIT_REPORT 
}smsal_peer_msg_name_enum;

#endif /* end of smsal_enums.h */


