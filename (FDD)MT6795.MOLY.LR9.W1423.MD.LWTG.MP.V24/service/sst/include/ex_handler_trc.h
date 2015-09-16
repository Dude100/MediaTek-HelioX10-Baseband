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
 *   ex_handler_trc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines exception debugging trace.
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

    TRC_MSG(SST_EXC_WATCHDOG_RESET_ENTER, "[EXC][COMMON] Enter Watchdog reset")
    TRC_MSG(SST_EXC_WATCHDOG_RESET_EXIT, "[EXC][COMMON] Exit Watchdog reset")

    TRC_MSG(SST_EXC_WATCHDOG_DISABLE_ENTER, "[EXC][COMMON] Enter Watchdog disable")
    TRC_MSG(SST_EXC_WATCHDOG_DISABLE_EXIT, "[EXC][COMMON] Exit Watchdog disable")

    TRC_MSG(SST_EXC_OPEN_LOGGING_PORT_ENTER, "[EXC][COMMON] Enter tst_assert_open_logging_port_for_exception()")
    TRC_MSG(SST_EXC_OPEN_LOGGING_PORT_EXIT, "[EXC][COMMON] Exit tst_assert_open_logging_port_for_exception()")

    TRC_MSG(SST_EXC_FLUSH_LOGGING_PORT_ENTER, "[EXC][COMMON] Enter dhl_flush_logging_port_for_exception()")
    TRC_MSG(SST_EXC_FLUSH_LOGGING_PORT_EXIT, "[EXC][COMMON] Exit dhl_flush_logging_port_for_exception()")

    TRC_MSG(SST_EXC_UST_GET_TIME_ENTER, "[EXC][COMMON] Enter ust_get_current_time()")
    TRC_MSG(SST_EXC_UST_GET_TIME_EXIT, "[EXC][COMMON] Exit ust_get_current_time()")

    TRC_MSG(SST_EXC_USC_GET_TIME_ENTER, "[EXC][COMMON] Enter USC_Get_TimeStamp()")
    TRC_MSG(SST_EXC_USC_GET_TIME_EXIT, "[EXC][COMMON] Exit USC_Get_TimeStamp()")
  
    TRC_MSG(SST_EXC_NOTIFY_DSP_ENTER, "[EXC][COMMON] Enter dmdsp_ex_notify_dsp()")
    TRC_MSG(SST_EXC_NOTIFY_DSP_EXIT, "[EXC][COMMON] Exit dmdsp_ex_notify_dsp()")

    TRC_MSG(SST_EXC_CCCI_HANDSHAKING_ENTER, "[EXC][COMMON] Enter ccci_exception_handshake()")
    TRC_MSG(SST_EXC_CCCI_HANDSHAKING_EXIT, "[EXC][COMMON] Exit ccci_exception_handshake()")

    TRC_MSG(SST_EXC_TOPSM_ENABLE_FRC_ENTER, "[EXC][COMMON] Enter MD_TOPSM_EnableFRC()")
    TRC_MSG(SST_EXC_TOPSM_ENABLE_FRC_EXIT, "[EXC][COMMON] Exit MD_TOPSM_EnableFRC()")

    TRC_MSG(SST_EXC_RESET_HARDWARE_ENTER, "[EXC][COMMON] Enter ex_reset_hw()")
    TRC_MSG(SST_EXC_RESET_HARDWARE_EXIT, "[EXC][COMMON] Exit ex_reset_hw()")

    TRC_MSG(SST_EXC_INIT_EXCEPTION_RECORD_ENTER, "[EXC][COMMON] Enter ex_init_log()")
    TRC_MSG(SST_EXC_INIT_EXCEPTION_RECORD_EXIT, "[EXC][COMMON] Exit ex_init_log()")

    TRC_MSG(SST_EXC_VFP_REGISTER_DUMP_ENTER, "[EXC][COMMON] Enter vfp_register_dump()")
    TRC_MSG(SST_EXC_VFP_REGISTER_DUMP_EXIT, "[EXC][COMMON] Exit vfp_register_dump()")	

    TRC_MSG(SST_EXC_CLEAR_PENDING_LOG_ENTER, "[EXC][COMMON] Enter tst_dump_as_fatal_error()")
    TRC_MSG(SST_EXC_CLEAR_PENDING_LOG_EXIT, "[EXC][COMMON] Exit tst_dump_as_fatal_error()")	

    TRC_MSG(SST_EXC_OUTPUT_EXC_MSG_ENTER, "[EXC][COMMON] Enter ex_output_exc_msg()")
    TRC_MSG(SST_EXC_OUTPUT_EXC_MSG_EXIT, "[EXC][COMMON] Exit ex_output_exc_msg()")

    TRC_MSG(SST_EXC_INVOKE_SST_ENGINE_ENTER, "[EXC][COMMON] Enter INT_InvokeSSTEngine()")
    TRC_MSG(SST_EXC_INVOKE_SST_ENGINE_EXIT, "[EXC][COMMON] Exit INT_InvokeSSTEngine()")
    
    TRC_MSG(SST_EXC_EMM_WRITE_EX_RECORD_ENTER, "[EXC][COMMON] Enter EMM_Write_ExceptRecord()")
    TRC_MSG(SST_EXC_EMM_WRITE_EX_RECORD_EXIT, "[EXC][COMMON] Exit EMM_Write_ExceptRecord()")
    
    TRC_MSG(SST_EXC_SWLA_PRINT_LOWRAM_ENTER, "[EXC][COMMON] Enter SLA_Print_low_RAM_SWLA()")
    TRC_MSG(SST_EXC_SWLA_PRINT_LOWRAM_EXIT, "[EXC][COMMON] Exit SLA_Print_low_RAM_SWLA()")

    TRC_MSG(SST_EXC_OUTPUT_EXCEPTION_RECORD_ENTER, "[EXC][COMMON] Enter ex_output_log()")
    TRC_MSG(SST_EXC_OUTPUT_EXCEPTION_RECORD_EXIT, "[EXC][COMMON] Exit ex_output_log()")

    TRC_MSG(SST_EXC_PASS_CCCI_EXCINFO_ENTER, "[EXC][COMMON] Enter ccci_exception_info_passed()")
    TRC_MSG(SST_EXC_PASS_CCCI_EXCINFO_EXIT, "[EXC][COMMON] Exit ccci_exception_info_passed()")

    TRC_MSG(SST_EXC_FLC_DEBUG_INFO_ENTER, "[EXC][COMMON] Enter flc2_debug_assert_callback()")
    TRC_MSG(SST_EXC_FLC_DEBUG_INFO_EXIT, "[EXC][COMMON] Exit flc2_debug_assert_callback()")

    TRC_MSG(SST_EXC_INIT_FDD_TABLE_ENTER, "[EXC][COMMON] Enter Initialize_FDD_tables()")
    TRC_MSG(SST_EXC_INIT_FDD_TABLE_EXIT, "[EXC][COMMON] Exit Initialize_FDD_tables()")

    TRC_MSG(SST_EXC_SAVE_EXCEPTION_RECORD_ENTER, "[EXC][COMMON] Enter ex_save_log()")
    TRC_MSG(SST_EXC_SAVE_EXCEPTION_RECORD_EXIT, "[EXC][COMMON] Exit ex_save_log()")

    TRC_MSG(SST_EXC_FS_UNLOCK_ALL_ENTER, "[EXC][COMMON] Enter FS_UnlockAll()")
    TRC_MSG(SST_EXC_FS_UNLOCK_ALL_EXIT, "[EXC][COMMON] Exit FS_UnlockAll()")

    TRC_MSG(SST_EXC_FS_SHUTDOWN_ENTER, "[EXC][COMMON] Enter FS_ShutDown()")
    TRC_MSG(SST_EXC_FS_SHUTDOWN_EXIT, "[EXC][COMMON] Exit FS_ShutDown()")

    TRC_MSG(SST_EXC_NVRAM_WRITE_EXC_ENTER, "[EXC][COMMON] Enter nvram_write_exception()")
    TRC_MSG(SST_EXC_NVRAM_WRITE_EXC_EXIT, "[EXC][COMMON] Exit nvram_write_exception()")

    TRC_MSG(SST_EXC_TST_DUMP2FILE_ENTER, "[EXC][COMMON] Enter tst_dump_to_file_for_crash()")
    TRC_MSG(SST_EXC_TST_DUMP2FILE_EXIT, "[EXC][COMMON] Exit tst_dump_to_file_for_crash()")

    TRC_MSG(SST_EXC_DUMP_USB_DEBUG_DATA_ENTER, "[EXC][COMMON] Enter USB_DSPIRDBG_Flush_Data()")
    TRC_MSG(SST_EXC_DUMP_USB_DEBUG_DATA_EXIT, "[EXC][COMMON] Exit USB_DSPIRDBG_Flush_Data()")
    
    TRC_MSG(SST_EXC_RESET_EXCSP_ENTER, "[EXC][COMMON] Enter INT_ExceptionResetExcSP()")
    TRC_MSG(SST_EXC_RESET_EXCSP_EXIT, "[EXC][COMMON] Exit INT_ExceptionResetExcSP()")
    
    TRC_MSG(SST_EXC_MINILOG_DUMP_ENTER, "[EXC][COMMON] Enter tst_mini_log_dump()")
    TRC_MSG(SST_EXC_MINILOG_DUMP_EXIT, "[EXC][COMMON] Exit tst_mini_log_dump()")
    
    TRC_MSG(SST_EXC_CLEAN_RES_PROT_ENTER, "[EXC][COMMON] Enter ex_clean_res_prot()")
    TRC_MSG(SST_EXC_CLEAN_RES_PROT_EXIT, "[EXC][COMMON] Exit ex_clean_res_prot()")
    
    TRC_MSG(SST_EXC_UNGUARD_STACKSPACE_ENTER, "[EXC][COMMON] Enter kal_unguard_stack_space()")
    TRC_MSG(SST_EXC_UNGUARD_STACKSPACE_EXIT, "[EXC][COMMON] Exit kal_unguard_stack_space()")
    
    TRC_MSG(SST_EXC_INIT_DUMP_ENTER, "[EXC][COMMON] Enter ex_init_dump()")
    TRC_MSG(SST_EXC_INIT_DUMP_EXIT, "[EXC][COMMON] Exit ex_init_dump()")

    TRC_MSG(SST_EXC_CORESONIC_DSP_DUMP_DEBUGINFO_ENTER, "[EXC][COMMON] Enter coresonic: dspfnc_dump_dsp_debug_information()")
    TRC_MSG(SST_EXC_CORESONIC_DSP_DUMP_DEBUGINFO_EXIT, "[EXC][COMMON] Exit coresonic: dspfnc_dump_dsp_debug_information()")

    TRC_MSG(SST_EXC_SYSMEM_TO_BE_DUMPED, "[EXC][COMMON] sys_mem_xxx.bin to be dumped [%d]: (0x%x, 0x%x)")

    TRC_MSG(SST_EXC_HANDOVER2TST, "[EXC][COMMON] Handover to TST exception handler")
	
    TRC_MSG(SST_EXC_READY2REBOOT, "[EXC][COMMON] Ready to silent reboot")
	
	TRC_MSG(SST_EXC_CORESONIC_DSP_WAKEUP_SUCCEEDED, "[EXC][COMMON] Wake up LTE DSP succeeded")
	TRC_MSG(SST_EXC_CORESONIC_DSP_WAKEUP_FAILED, "[EXC][COMMON] Wake up LTE DSP failed")
	
    TRC_MSG(SST_EXC_BBREG_DUMP_COUNT, "[EXC][COMMON] BB register dump count: %d")
    TRC_MSG(SST_EXC_BBREG_DUMP_OWNER, "[EXC][COMMON] BB register dump onwer: %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c")
    TRC_MSG(SST_EXC_BBREG_DUMP_CALLBACK_FUNC_ENTER, "[EXC][COMMON] Enter BB register dump callback, address: 0x%x")
    TRC_MSG(SST_EXC_BBREG_DUMP_CALLBACK_FUNC_EXIT, "[EXC][COMMON] Exit BB register dump callback, address: 0x%x")
    TRC_MSG(SST_EXC_BBREG_DUMP_SKIP, "[EXC][COMMON] Skip this dump")    
    TRC_MSG(SST_EXC_BBREG_DUMP_TO_BE_DUMPED, "[EXC][COMMON] bb_mem_xxx.bin to be dumped [%d]: (0x%x, 0x%x, %d)")
	
