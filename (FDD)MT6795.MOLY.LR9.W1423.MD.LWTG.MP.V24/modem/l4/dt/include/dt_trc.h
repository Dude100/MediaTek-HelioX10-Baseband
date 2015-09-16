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
 *	dt_trc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is trace map definition for DT.
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
 *****************************************************************************/


#ifndef _DT_TRC_H
#define _DT_TRC_H

#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_trace.h"

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "dt_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_DT)

   /* TRACE_FUNC trace class */
   TRC_MSG(FUNC_DT_FAST_STRING_PRINT_ENTRY, "DT: dt_fast_string_print()")
   TRC_MSG(FUNC_DT_UART_RTW_IND_HDLR_ENTRY, "DT: dt_uart_ready_to_write_ind_hdlr()")
   TRC_MSG(FUNC_DT_UART_RTR_IND_HDLR_ENTRY, "DT: dt_uart_ready_to_read_ind_hdlr()")
   TRC_MSG(FUNC_DT_UART_SEND_DATA_ENTRY, "DT: dt_uart_send_data()")
   TRC_MSG(FUNC_DT_UART_READ_DATA_ENTRY, "DT: dt_uart_read_data()")
   TRC_MSG(FUNC_DT_READ_FROM_UART_ENTRY, "DT: dt_read_from_uart()")
   TRC_MSG(FUNC_DT_WRITE_TO_UART_ENTRY, "DT: dt_write_to_uart()")
   TRC_MSG(FUNC_DT_PROCESS_ONE_CMD_ENTRY, "DT: dt_process_one_cmd()")
   TRC_MSG(FUNC_DT_EQ_FS_FILELIST_REQ_ENTRY, "DT: dt_eq_fs_filelist_req()")
   TRC_MSG(FUNC_DT_EQ_FS_EFSL_LIST_ENTRY, "DT: dt_eq_fs_efsl_list()")
   TRC_MSG(FUNC_DT_EQ_FS_EFSL_NEXT_ENTRY, "DT: dt_eq_fs_efsl_next()")
   TRC_MSG(FUNC_DT_GET_DOWNLOAD_FULLPATH_ENTRY, "DT: dt_get_downloadFullpath()") 
   TRC_MSG(FUNC_DT_EQ_GENERAL_FS_ACCESS_REQ_ENTRY, "DT: dt_eq_general_fs_access_req()")
   TRC_MSG(FUNC_DT_INT_TO_ASCII_CONVERTER_ENTRY, "DT: dt_int_to_ascii_converter()")
   TRC_MSG(FUNC_DT_LINT_TO_ASCII_CONVERTER_ENTRY,"DT: dt_lint_to_ascii_converter()")
   TRC_MSG(FUNC_DT_FS_READ_ENTRY, "DT: dt_eq_fs_read_req()")
   TRC_MSG(FUNC_DT_EQ_READ_RRSP_ENTRY, "DT: dt_eq_fs_read_rrsp()")
   TRC_MSG(FUNC_DT_UART_WRITE_DATA_ENTRY, "DT: dt_uart_write_data()")
   TRC_MSG(FUNC_DT_RESULT_CODE_FMTTR_ENTRY, "DT: dt_result_code_fmttr()")  
   TRC_MSG(FUNC_DT_CMD_PROCESSOR_ENTRY, "DT: dt_cmd_processor()")
   TRC_MSG(FUNC_DT_EFSR_HDLR_ENTRY, "DT: dt_efsr_hdlr()")
   TRC_MSG(FUNC_DT_EFSW_HDLR_ENTRY, "DT: dt_efsw_hdlr()")   
   TRC_MSG(FUNC_DT_INT_VALIDATOR_EXT_ENTRY, "DT: dt_int_validator_ext()")
   TRC_MSG(FUNC_DT_INT_VALIDATOR_ENTRY, "DT: dt_int_validator()")
   TRC_MSG(FUNC_DT_STRING_VALIDATOR_EXT_ENTRY, "DT: dt_string_validator_ext()")   
   TRC_MSG(FUNC_DT_STRING_VALIDATOR_ENTRY, "DT: dt_string_validator()")
   TRC_MSG(FUNC_DT_CHECK_HEX_VALUE_ENTRY, "DT: dt_check_hex_value()")
   TRC_MSG(FUNC_DT_TOUPPER_ENTRY, "DT: dt_toUpper()")   
   TRC_MSG(FUNC_DT_FIND_CMD_MODE_ENTRY, "DT: dt_find_cmd_mode()")   
   TRC_MSG(FUNC_DT_COPYMOVE_CHK_MSG_QUE_ENTRY, "DT: dt_copymove_check_msg_queue()")
   TRC_MSG(FUNC_DT_FS_MOVECOPY_HDLR_ENTRY, "DT: dt_fs_copymove_hdlr()")
   TRC_MSG(FUNC_DT_EFSRN_HDLR_ENTRY, "DT: dt_efsrn_hdlr()")
   TRC_MSG(FUNC_DT_EFSCP_HDLR_ENTRY, "DT: dt_efscp_hdlr()") 
   TRC_MSG(FUNC_DT_EQ_FS_FOLDER_ACTION_REQ_ENTRY, "DT: dt_eq_fs_folder_action_req()")  
   TRC_MSG(FUNC_DT_EFSL_HDLR_ENTRY, "DT: dt_efsl_hdlr()")
   TRC_MSG(FUNC_DT_EQ_FS_AV_DISK_SIZE_REQ_ENTRY, "DT: dt_eq_fs_av_disk_size_req()")
   TRC_MSG(FUNC_DT_ESUO_HDLR_ENTRY, "DT: dt_esuo_hdlr()")

   /*Group 1 : to print AT download information  */
   TRC_MSG(DT_CLOSE_FILE_FAIL, "DT: +EFSW=1 fail: dunno which file to close!")
   TRC_MSG(DT_FS_ACCESS, "DT: FS action = %Mdt_fs_opcode_enum, ret_val = %d")
   TRC_MSG(DT_FS_COUNT, "DT: FS_Count ret_val = %d")
   TRC_MSG(DT_FS_COPYMOVE_RATE,"DT: Completed = %d, Total = %d") 
   TRC_MSG(DT_FS_ACCESS_FAIL, "file system error_code = %d")
   
   /*TRACE_INFO*/
   TRC_MSG(INFO_DT_RESUME_DOWNLOAD,"DT: resume download")	
   TRC_MSG(INFO_DT_RESUME_FILELIST,"DT: resume filelist")	
   TRC_MSG(INFO_DT_CLEAR_FILELIST_TIMER, "DT: clear filelist timer!, event_id=%d")   
   TRC_MSG(INFO_DT_CLEAR_DOWNLOAD_TIMER, "DT: clear download timer!, event_id=%d")
   TRC_MSG(INFO_DT_INPUT, "DT: read uart, que.len=%d, space=%d, read=%d, uart_empty=%d")   
   TRC_MSG(INFO_DT_CURRENT_STATE, "DT: current state =%Mdt_transfer_state_enum")   
   TRC_MSG(INFO_DT_FILE_PATH_LEN, "DT: file_path_len = %u")   
   TRC_MSG(INFO_DT_CLOSE_FD,"Close DT fd[%d]") 
   TRC_MSG(INFO_DT_FILELIST_END, "Filelist end") 
   TRC_MSG(INFO_DT_NULL_DOWNLOAD_PATH, "Download path is NULL")   
   TRC_MSG(INFO_DT_FILELIST_NOT_FOUND, "dt_eq_fs_filelist_req: no file found in the folder") 
   TRC_MSG(INFO_DT_SET_MOD_ID,"Set DT src mod id=%d")
   TRC_MSG(INFO_DT_FIND_CLOSE, "DT: FindClose!")
   TRC_MSG(INFO_DT_FIND_FIRST, "DT: FindFirst")
   TRC_MSG(INFO_DT_CLEAR_PREVIOUS_PATH, "DT: clear previous path")
   TRC_MSG(INFO_DT_SEND_BT_SPP_UART_PLUGOUT_CNF, "DT: send bt spp uart plugout cnf") 
   TRC_MSG(INFO_DT_PLUGOUT_RSV_IN_CALLBACK, "DT: receive plugout message in copy/move callback function")
   TRC_MSG(INFO_DT_FS_COPYMOVE_CALLBACK_PGS, "DT: dt_fs_copymove_callback() and Action is %d")   
   TRC_MSG(INFO_DT_AT_CMD_STRING, "command: %c%c%c%c%c%c%c%c%c%c%c%c") 
   TRC_MSG(INFO_DT_RESULT_CODE_FMTTR, "result code: %Mdt_rsp_type_enum")
   TRC_MSG(INFO_DT_RESULT_CODE_ERROR, "result code: %Mdt_rsp_type_enum, cause: %u")
   
   /*TRACE_ERROR*/
   TRC_MSG(ERROR_DT_INVALID_MSG, "DT: invalid message!!")      
   TRC_MSG(ERROR_DT_INVALID_CMD, "DT: invalid command!!")        
   TRC_MSG(ERROR_DT_UNSPECTED_MSG_RECEIVED_IN_CALLBACK, "DT: unspected message received in callback func")
   TRC_MSG(ERROR_DT_PORT_OR_UART_PORT_OWNER, "DT: DT_PTR->port = %d, DT_UART_GetOwnerID(port) = %d") //mtk02088_dt
     
   /*TRACE_WARNING*/
   TRC_MSG(WARNING_DT_NOT_DOWNLOAD_STATE, "DT: +EFSR is invalid when state = %d")
   TRC_MSG(WARNING_DT_USER_ABORT_WHEN_UART_FULL, "DT: user abort download during UART full")	
   TRC_MSG(WARNING_DT_DOWNLOAD_COMPLETE_WHEN_UART_FULL, "DT: download completed during UART full")	
   TRC_MSG(WARNING_DT_UART_FULL, "DT: set uart_stop_send_flag!")
   TRC_MSG(WARNING_DT_CLR_TX_BUFFER, "DT: ClrTxBuffer")
   TRC_MSG(WARNING_DT_UART_INPUT_QUEUE_FULL, "DT: uart_input_queue Full!")
   TRC_MSG(WARNING_DT_WRITE_FILE_FAIL, "DT:Write FILE Fail!")
   TRC_MSG(WARNING_DT_CALL_UART_SWITCHPORT, "DT: call UART_SwitchPort!")
   TRC_MSG(WARNING_DT_ACTION_ABORT, "DT: action abort")
   TRC_MSG(WARNING_DT_COPYMOVE_FAIL, "DT: File action %d failed, and FS_Move returns ret_v = %d")
   TRC_MSG(WARNING_DT_RENAME_PATH_CLEARED, "DT: DT_PTR->data_rename_path[%d] is cleared!")
   TRC_MSG(WARNING_DT_FS_ABORT_ERROR, "DT: FS_Abort() return error code %d")
   
END_TRACE_MAP(MOD_DT)
#endif

