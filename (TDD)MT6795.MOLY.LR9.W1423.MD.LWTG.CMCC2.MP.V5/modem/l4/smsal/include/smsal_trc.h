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
 *	smsal_trc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is trace map definition.
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

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


#ifndef _SMSAL_TRC_H
#define _SMSAL_TRC_H

//------------------------------ suggest Add ------------------------------
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_trace.h"

#ifndef __MTK_TARGET__
#define SMSALDBG_(x)
#else
#define SMSALDBG_(x)
#endif


#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "smsal_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_SMSAL)

   /*=========================== 
    * TRACE_PEER trace class 
    *===========================*/   
   TRC_MSG(SMSAL_NW_TO_MS_PEER_MSG, "[NW->MS]: %Msmsal_peer_msg_name_enum ")
   TRC_MSG(SMSAL_MS_TO_NW_PEER_MSG, "[MS->NW]: %Msmsal_peer_msg_name_enum ")

   /*=========================== 
    * TRACE_FUNC trace class 
    *===========================*/   
   TRC_MSG(FUNC_SMSAL_INIT, "SMSAL: init()")
   TRC_MSG(FUNC_SMSAL_INIT_REQ, "SMSAL: startup handler")
   TRC_MSG(FUNC_SMSAL_INIT_CNF, "SMSAL: startup confirm result: %d")
   TRC_MSG(FUNC_SMSAL_INIT_ME_ONLY_CNF, "SMSAL: startup confirm (me only) result: %d")
   TRC_MSG(FUNC_SMSAL_READ, "SMSAL: read handler")
   TRC_MSG(FUNC_SMSAL_READ_CNF, "SMSAL: read result: %d, cause: %2x")
   TRC_MSG(FUNC_SMSAL_READ_RAW_DATA, "SMSAL: read raw data handler")
   TRC_MSG(FUNC_SMSAL_READ_RAW_DATA_CNF, "SMSAL: read raw data result: %d, cause: %2x")
   TRC_MSG(FUNC_SMSAL_WRITE, "SMSAL: write handler")
   TRC_MSG(FUNC_SMSAL_WRITE_CNF, "SMSAL: write result: %d, cause: %2x")   
   TRC_MSG(FUNC_SMSAL_WRITE_RAW_DATA, "SMSAL: write raw data handler")
   TRC_MSG(FUNC_SMSAL_WRITE_RAW_DATA_CNF, "SMSAL: write raw data result: %d, cause: %2x")
   TRC_MSG(FUNC_SMSAL_DELETE, "SMSAL: delete handler")
   TRC_MSG(FUNC_SMSAL_DELETE_CNF, "SMSAL: delete result: %d, cause: %2x")   
   TRC_MSG(FUNC_SMSAL_SEND, "SMSAL: send handler")
   TRC_MSG(FUNC_SMSAL_SEND_CNF, "SMSAL: send result: %d cause: %2x")  
   TRC_MSG(FUNC_SMSAL_SEND_FROM_STORAGE, "SMSAL: send from storage handler")
   TRC_MSG(FUNC_SMSAL_SEND_FROM_STORAGE_CNF, "SMSAL: send from storage result: %d, cause: %2x")  
   TRC_MSG(FUNC_SMSAL_SET_PARAM, "SMSAL: set parameter handler")
   TRC_MSG(FUNC_SMSAL_SET_PARAM_CNF, "SMSAL: set parameter result: %d, cause: %2x")  
   TRC_MSG(FUNC_SMSAL_MEM_FULL, "SMSAL: storage capacity full :%Msmsal_mem_full_enum")
   TRC_MSG(FUNC_SMSAL_MEM_EXCEED, "SMSAL: MEM EXCEED : %Msmsal_mem_exceed_enum")
   TRC_MSG(FUNC_SMSAL_MEM_AVAILABLE, "SMSAL: storage capacity available")
   TRC_MSG(FUNC_SMSAL_MSG_WAITING, "SMSAL: message waiting")   
   TRC_MSG(FUNC_SMSAL_MSG_WAITING_EXT, "SMSAL: message waiting extension (msp:%d, line:%d)")
   TRC_MSG(FUNC_SMSAL_EVM_IND, "SMSAL: Enhanced Voice Mail")
   TRC_MSG(FUNC_UPDATE_MSGBOX_REPORT, "SMSAL: enter smsal_update_msgbox_for_report")   
   TRC_MSG(FUNC_SMSAL_MSGBOX_POST, "SMSAL: enter smsal_msgbox_post: index=%d")
   TRC_MSG(FUNC_SMSAL_MT_FIX_7BIT_EMPTY_CONTENT, "SMSAL: enter smsal_mt_fix_7bit_empty_content")
   TRC_MSG(FUNC_SMSAL_INIT_FIX_7BIT_EMPTY_CONTENT, "SMSAL: enter smsal_init_fix_7bit_empty_content")
   TRC_MSG(FUNC_SMSAL_IMS_SEND, "SMSAL: smsal_ims_send_handler()")
   TRC_MSG(FUNC_SMSAL_IMS_SEND_CNF, "SMSAL IMS: send result: %d cause: %2x")

   /* 
    * smsal_transport_proc.c 
    */
   TRC_MSG(FUNC_SMSAL_MSG_REPLACE_HDLR, "SMSAL: enter smsal_msg_replace_hdlr, pid=%d")   
   TRC_MSG(FUNC_SMSAL_REPLACE_MSG_CNF, "SMSAL: enter smsal_replace_msg_cnf")
   TRC_MSG(FUNC_SMSAL_REPLACE_MSG_REJ, "SMSAL: enter smsal_replace_msg_rej")
   TRC_MSG(FUNC_SMSAL_MT_MSG_HDLR, "SMSAL: enter smsal_mt_msg_hdlr")
   TRC_MSG(FUNC_SMSAL_DELIVER_NACK_POST, "SMSAL: enter smsal_deliver_nack_post: smi=%d failure_cause=%d")
   TRC_MSG(FUNC_SMSAL_DELIVER_ACK_POST,  "SMSAL: enter smsal_deliver_ack_post: smi=%d")
   TRC_MSG(FUNC_SMSAL_NEW_MSG_IND, "SMSAL: enter smsal_new_msg_ind: smi=%d")
   TRC_MSG(FUNC_SMSAL_MSG_SUBMIT_POST, "SMSAL: enter smsal_msg_submit_post")
   TRC_MSG(FUNC_SMSAL_SEND_MSG_TEXT_MODE, "SMSAL: enter smsal_send_msg_text_mode")
   TRC_MSG(FUNC_SMSAL_SEND_CMD_TEXT_MODE, "SMSAL: enter smsal_send_cmd_text_mode")
   TRC_MSG(FUNC_SMSAL_SEND_PDU_MODE, "SMSAL: enter smsal_send_pdu_mode")
   TRC_MSG(FUNC_SMSAL_SEND_CONC, "SMSAL: enter smsal_send_conc")
   TRC_MSG(FUNC_SMSAL_IS_AVL_FOR_NEW_MSG, "SMSAL: enter smsal_is_avl_for_new_msg")
   TRC_MSG(FUNC_SMSAL_STORE_NEW_MSG, "SMSAL: enter smsal_store_new_msg")
   TRC_MSG(FUNC_CPHS_VM_IND, "SMSAL: cphs voicemail indication")
   TRC_MSG(FUNC_SMSAL_IMS_SEND_DELIVER_CNF, "SMSAL: enter smsal_ims_send_deliver_cnf")
   TRC_MSG(FUNC_SMSAL_IMS_SEND_STATUS_CNF, "SMSAL: enter smsal_ims_send_status_report_cnf")

   /* sim toolkit related sms */
   TRC_MSG(FUNC_SMSAL_SIM_DATA_DL_HDLR, "SMSAL: enter smsal_sim_data_dl_hdlr: smi=%d")
   TRC_MSG(FUNC_SMSAL_SAT_MO_SMS_CTRL_CNF, "SMSAL: enter smsal_sat_mo_sms_ctrl_cnf")
   TRC_MSG(FUNC_SMSAL_SAT_SEND_MSG_CNF, "SMSAL: enter smsal_sat_send_msg_cnf")
   TRC_MSG(FUNC_SMSAL_SAT_MO_MSG_CTRL, "SMSAL: enter smsal_sat_mo_msg_ctrl")
   TRC_MSG(FUNC_SMSAL_SAT_SEND_CMD, "SMSAL: enter smsal_sat_send_cmd")
   TRC_MSG(FUNC_SMSAL_SAT_SEND_MSG, "SMSAL: enter smsal_sat_send_msg")

   /* 
    * smsal_sms.c 
    */
   TRC_MSG(FUNC_SMSAL_DELIVER_HDLR, "SMSAL: receive mt message")
   TRC_MSG(FUNC_SMSAL_SUBMIT_ACK_HDLR, "SMSAL: receive submit report ack")
   TRC_MSG(FUNC_SMSAL_SUBMIT_NACK_HDLR, "SMSAL: receive submit report nack")
   TRC_MSG(FUNC_SMSAL_STATUS_REPORT_HDLR, "SMSAL: receive status report: mr=%d")
   TRC_MSG(FUNC_SMSAL_SMMA_CNF, "SMSAL: receive memory notification cnf: result=%d")
   
   /*
    * smsal_storage.c
    */   
   TRC_MSG(FUNC_SMSAL_RESET_SHORT_MSG, "SMSAL: enter smsal_reset_short_msg, storage_type=%Msmsal_storage_enum, record_no=%d")
   TRC_MSG(FUNC_SMSAL_READ_SHORT_MSG,  "SMSAL: enter smsal_read_short_msg, storage_type=%Msmsal_storage_enum, record_no=%d")
   TRC_MSG(FUNC_SMSAL_WRITE_SHORT_MSG, "SMSAL: enter smsal_write_short_msg, storage_type=%Msmsal_storage_enum, record_no=%d")


   /* sim toolkit related sms */
   TRC_MSG(FUNC_SMSAL_SAT_FILE_CHANGE_HDLR, "SMSAL: enter smsal_sat_file_change_hdlr")
   TRC_MSG(FUNC_SMSAL_SAT_FILE_CHANGE_RES, "SMSAL: enter smsal_sat_file_change_res, result=%d")


   /* cell broadcast */
   TRC_MSG(FUNC_SMSAL_CBCH_REQ_HANDLER, "CB(SMSAL): enter smsal_cbch_req_handler")
   TRC_MSG(FUNC_SMSAL_CB_SEND_RATCM_CBCH_REQ, "CB(SMSAL): enter smsal_cb_send_ratcm_cbch_req")
   TRC_MSG(FUNC_SMSAL_CB_SEND_EVAL_CBCH_REQ, "CB(SMSAL): enter smsal_cb_send_eval_cbch_req")
   TRC_MSG(FUNC_SMSAL_CB_UPDATE_REQ_HANDLE, "CB(SMSAL): enter smsal_cb_update_req_handler")
   TRC_MSG(FUNC_SMSAL_CB_FLUSH_OLDEST, "CB(SMSAL): enter smsal_cb_flush_oldest")
   TRC_MSG(FUNC_SMSAL_RATCM_CB_GS_CHANGE_IND_HANDLER, "CB(SMSAL): enter smsal_ratcm_cb_gs_change_ind_handler")
   TRC_MSG(FUNC_SMSAL_EVAL_CB_GS_CHANGE_IND_HANDLER, "CB(SMSAL): enter smsal_eval_cb_gs_change_ind_handler")   
   TRC_MSG(FUNC_SMSAL_RATCM_CB_DATA_IND_HANDLER, "CB(SMSAL): enter smsal_ratcm_cb_data_ind_handler")   
   TRC_MSG(FUNC_SMSAL_CB_SERVICE_BY_PLMN_HANDLER, "CB(SMSAL): enter smsal_cb_service_by_plmn_handler")
   TRC_MSG(FUNC_SMSAL_EVAL_CB_DATA_IND_HANDLER, "CB(SMSAL): enter smsal_eval_cb_data_ind_handler")   
   TRC_MSG(INFO_UPDATE_CB_MID,  "CB(SMSAL): update cb mid")
   TRC_MSG(INFO_UPDATE_CB_MIR,  "CB(SMSAL): update cb mir")
   TRC_MSG(INFO_UPDATE_CB_DCS,  "CB(SMSAL): update cb dcs")
   TRC_MSG(INFO_UPDATE_CB_MASK, "CB(SMSAL): update cb mask")
   TRC_MSG(INFO_UPDATE_CB_ALL_LANG, "CB(SMSAL): update cb all language")
   TRC_MSG(FUNC_SMSAL_CB_RESET, "CB(SMSAL): enter smsal_cb_reset")
   TRC_MSG(INFO_CB_PAGE_INFO, "CB(SMSAL): recv a page: [%Mrat_enum] sn=%d mi=%d dcs=%d cur_page=%d total_page=%d")
   TRC_MSG(INFO_CB_RESERVED_PAGE_INFO, "CB(SMSAL): recv a reserved_dcs cb page")
   TRC_MSG(INFO_CB_SERVICE_PLMN_NUM, "CB(SMSAL): PLMN num in customer file=%d")
   TRC_MSG(ERROR_RECV_WRONG_CB_PAGE, "CB(SMSAL): [%Mrat_enum] recv a wrong cb page (len=%d) ")
   TRC_MSG(ERROR_RECV_UNSUPPORTED_CB_PAGE, "CB(SMSAL): recv an unsupported cb page")
   TRC_MSG(ERROR_WHEN_WRITE_CB_PARA, "CB(SMSAL): cb_write_rej: sub_act_code=%d cause=%d")
   TRC_MSG(ERROR_UNSUPPORTED_CB_TO_NMI, "CB(SMSAL): unsupported cb page to dst[%Msmsal_nmi_dest_enum]")

   /*=========================== 
    * TRACE_INFO trace class 
    *===========================*/ 
   TRC_MSG(WRITE_CONC_MSG_INFO, "SMSAL: write concatenated messaeg, %d segs, len of last seg:%d")
   TRC_MSG(STORE_MT_MSG_SUCC_INFO, "SMSAL: store a mt msg, index=%d, storage=%d")
   TRC_MSG(INFO_SMSAL_FOUND_MSG_REQ_STATUS_REP, "SMSAL: found a msg which requested status report previously mr=%d addr_len=%d addr_type=%2x addr_bcd=%2x %2x %2x %2x %2x %2x %2x %2x %2x %2x")
   TRC_MSG(INFO_SMSAL_UPDATE_STATUS_FOR_RCV_STATUS_REP, "SMSAL: update status for receiving status report")
   TRC_MSG(INFO_SMSAL_MSGBOX_POST, "SMSAL: smsal_msgbox_post ok: mr=%d")
   TRC_MSG(INFO_RECV_CLASS0_MSG, "SMSAL: recv class0 message")
   TRC_MSG(INFO_RECV_CLASS1_MSG, "SMSAL: recv class1 message")
   TRC_MSG(INFO_RECV_CLASS2_MSG, "SMSAL: recv class2 message")
   TRC_MSG(INFO_RECV_CLASS3_MSG, "SMSAL: recv class3 message")
   TRC_MSG(INFO_RECV_CLASS1_BUT_NVRAM_NOT_READ, "SMSAL: recvv class1 message but nvram not read yet")   
   TRC_MSG(MT_SMS_DISPATCH, "SMSAL: MT SMS dispatch. [store=%d],[LMI=%d],[RMI=%d][dest=%d][rmi_index=%d]")   
   TRC_MSG(MT_7BIT_EMPTY_CONTENT, "SMSAL: FIX MT SMS 7bit code, have no content: [DCS=%d]")
   TRC_MSG(INIT_7BIT_EMPTY_CONTENT, "SMSAL: FIX INIT SMS 7bit code, have no content: [DCS=%d]")  
   /* sim toolkit related sms */
   TRC_MSG(INFO_SAT_MO_SMS_ALLOW_WITH_MODIFY, "SMSAL: sat mo sms ctrl, allow with modification of addr, size_of_addr1=%d, size_of_addr2=%d")
   TRC_MSG(INFO_SAT_MO_SMS_ALLOW_WITHOUT_MODIFY, "SMSAL: sat mo sms ctrl, allow without modification of addr")
   TRC_MSG(INFO_SMSAL_SAT_MO_MSG_CTRL_NOT_SUPPORT, "SMSAL: sat mo sms ctrl not support")

   /* cell broadcast */
   TRC_MSG(INFO_SEND_SMSAL_AS_CBCH_REQ, "CB(SMSAL): send SMSAL_AS_CBCH_REQ to as")
   TRC_MSG(INFO_SEND_SMSAL_AS_CBCH_REQ_INTER_RAT, "CB(SMSAL): NOT send SMSAL_AS_CBCH_REQ to as due to interRAT") 
   TRC_MSG(INFO_SEND_SMSAL_AS_CB_UPDATE_REQ, "CB(SMSAL): send SMSAL_AS_CB_UPDATE_REQ to as")
   TRC_MSG(INFO_SEND_SMSAL_AS_CB_UPDATE_REQ_INTER_RAT, "CB(SMSAL): NOT send SMSAL_AS_CB_UPDATE_REQ to as due to interRAT")   
   TRC_MSG(INFO_SEND_L4CSMSAL_CB_MSG_IND, "CB(SMSAL): send L4CSMSAL_CB_MSG_IND to l4c")
   TRC_MSG(INFO_SEND_SAT_CB_DL_REQ, "CB(SMSAL): send SAT_CB_DL_REQ to sim")
   TRC_MSG(INFO_SEND_SMSAL_CB_MSG_IND_TO_SELF, "CB(SMSAL): send CB_DATA_IND to SMSAL: [%d/%d]")
   
   /* context info. */
   TRC_MSG(MSG_BOX_TOTAL_NUM, "MB: total MB = %d ")   
   TRC_MSG(MSG_BOX_INFO_1, "MB(%d):[state=%d][status=%d][rec=%d][type=%d] ")   
   TRC_MSG(MSG_BOX_INFO_2, "MB(%d):[%Msmsal_storage_enum][%Msmsal_mti_enum]")   
   
   TRC_MSG(INFO_STORAGE_SM, "SM:[total=%d][used=%d][inbox=%d][outbox=%d]")   
   TRC_MSG(INFO_STORAGE_ME, "ME:[total=%d][used=%d][inbox=%d][outbox=%d]")   

   TRC_MSG(INFO_MSGBOX_NUM_INFO, "SMSAL: simchg=%d, insim=%d, inme=%d, otsim=%d, otme=%d, unread=%d, all_sim=%d, all_me=%d")

   TRC_MSG(INFO_EVM_STATUS_INFO, "SMSAL: EVM - status data")
   TRC_MSG(INFO_EVM_MSG_INFO, "SMSAL: EVM id=0x%x(%d), len=%d, day=%d, p=%d")
   TRC_MSG(INFO_EVM_MSG_EXT_INFO, "SMSAL: EVM - extension data")


    /* TST info. */
    TRC_MSG(INFO_TST_WRITE_SMS2SIM,"SMSAL: tst write sms to sim info: set %03d byte as %02x")
    
   /* Other usage system info. */

   /*=========================== 
    * TRACE_WARNING trace class 
    *===========================*/   
   TRC_MSG(EF_SMS_NOT_SUPPORT, "SMSAL: EFsms not support")
   TRC_MSG(EF_SMSS_NOT_SUPPORT, "SMSAL: EFsmss not support")
   TRC_MSG(EF_SMSP_NOT_SUPPORT, "SMSAL: EFsmsp not support")
   TRC_MSG(MSG_PTR_IS_NULL, "SMSAL: Msg_ptr is NULL in smsal_cnma_timeout()")
   TRC_MSG(TIMER_IS_NOT_USED, "SMSAL: the CNMI timer entry is not used")
   TRC_MSG(GSM_DEFAULT_7_BIT_NOT_EQUAL_TO_ANSCII, "SMSAL: GSM default 7-bit != anscii")

   TRC_MSG(SMSALCB_RESET_OLD_BLK, "CB(SMSAL):flush old session.(blk_id=%d, blk->sn=%d, new sn=%d, cause=%Mcb_geography_enum)")
   TRC_MSG(SMSAL_DISCARD_UNREG_APP_PORT, "SMSAL: discard MT-SMS with port number=%d")
   TRC_MSG(SMSAL_CUT_PDU_LEN, "SMSAL: PDU length is modied, old pdu_len = %d, new pdu_len = %d")

   /*=========================== 
    * TRACE_ERROR trace class 
    *===========================*/ 
   TRC_MSG(WRONG_SMSAL_MSG, "SMSAL: wrong message %d")
   TRC_MSG(SMSAL_REJECT_MSG_BEFORE_INIT, "SMSAL: reject msg comes before normal initiation")
    
   TRC_MSG(NO_FREE_PENDING_ACT_STRUCT, "SMSAL: no free pending action structure")
   TRC_MSG(GET_NVRAM_INFO, "SMSAL: get_nvram_info error: result=%d rec_num=%d rec_size=%d")
   TRC_MSG(READ_SIM_ERROR,"SMSAL: read sim error: access_id=%d, file_id=%02x, length=%d, para=%02x")
   TRC_MSG(WRITE_SIM_ERROR,"SMSAL: write sim error: access_id=%d, file_id=%02x, length=%d, para=%02x")
   TRC_MSG(READ_SIM_FILEINFO_ERROR,"SMSAL: read sim file info error: access_id=%d, file_id=%02x, info_type=%d")
   TRC_MSG(STORAGE_NOT_AVAILABLE, "SMSAL: storage not available, storage_type = %d, requested num = %d, tot_sim = %d, used_sim = %d, tot_me = %d, used_me = %d")
   TRC_MSG(NO_SPACE_FOR_MT_SMS, "SMSAL: no space for mt sms, cause=%d")
   TRC_MSG(SMSAL_WRONG_MSG_IN_SIM_ENTRY_FUNC, "SMSAL: recv wrong msg in sim_entry_func: msgid=%d")
   TRC_MSG(SMSAL_WRONG_MSG_IN_NVM_ENTRY_FUNC, "SMSAL: recv wrong msg in nvm_entry_func: msgid=%d")
   TRC_MSG(WRITE_SIM_ERROR_FOR_STORE_C2_MSG,  "SMSAL: write sim error for storing class message")
   TRC_MSG(SMSAL_EFSMS_CORRUPT, "SMSAL: read a record in EFsms which may be corrupted: storage=%d record_no=%d")
   
   TRC_MSG(GET_NVRAM_SIZE_ERROR, "SMSAL: get_nvram_size error: pdu_size=%d")
   TRC_MSG(SMSAL_MSGBOX_DEL_EMPTY_ERROR, "SMSAL: delete an inVALID message: storage=%Msmsal_storage_enum record_no=%d")
   
   TRC_MSG(SMSAL_DECODE_SMS_PDU_ERROR, "SMSAL: decode sms pdu error")
   TRC_MSG(SMSAL_DECODE_UDH_ERROR, "SMSAL: UDH is invalid [%Msmsal_mti_enum] val: %x")

   /* sim toolkit related sms */
   TRC_MSG(SMSAL_SAT_MO_SMS_ERROR, "SMSAL: sat mo sms ctrl error, not allow or sim error")


   TRC_MSG(SMSAL_START_TIMER_FUNC, "SMSAL: start timer: timer_id=%d invoke_id=%d timeout=%d")
   TRC_MSG(SMSAL_STOP_TIMER_FUNC, "SMSAL: stop timer: timer_id=%d invoke_id=%d")
   TRC_MSG(SMSAL_CNMA_EXE, "SMSAL: cnmi_id=%d mode=%d")


END_TRACE_MAP(MOD_SMSAL)

#endif /* _SMSAL_TRC_H */


