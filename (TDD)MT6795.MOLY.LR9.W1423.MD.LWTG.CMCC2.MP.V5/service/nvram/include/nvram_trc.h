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
 *	nvram_trc.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is trace map definition.
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

#ifndef _NVRAM_TRC_H
#define _NVRAM_TRC_H


#include "kal_public_defs.h" //MSBB change #include "stack_config.h"

#include "kal_trace.h"
#include "nvram_gen_trc.h"


#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__) || defined(TST_TRACE_COMPAT)
    #include "nvram_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_NVRAM)

    /* TRACE_FUNC trace class */
    TRC_MSG(FUNC_NVRAM_STARTUP,        "NVRAM: startup handler")
    TRC_MSG(FUNC_NVRAM_STARTUP_CNF,    "NVRAM: confirm result: %02X")
    TRC_MSG(FUNC_NVRAM_READ,           "NVRAM: read handler")
    TRC_MSG(FUNC_NVRAM_READ_CNF,       "NVRAM: read result: %02X. Sniff: file_idx:%2X, para:%2X, %02X:%02X")
    TRC_MSG(FUNC_NVRAM_WRITE,          "NVRAM: write handler")
    TRC_MSG(FUNC_NVRAM_WRITE_CNF,      "NVRAM: write result: %02X")
    TRC_MSG(FUNC_NVRAM_WRITE_IMEI,     "NVRAM: write imei handler")
    TRC_MSG(FUNC_NVRAM_WRITE_IMEI_CNF, "NVRAM: write imei result: %02X")
    TRC_MSG(FUNC_NVRAM_RESET,        "NVRAM: reset handler")
    TRC_MSG(FUNC_NVRAM_RESET_CNF,    "NVRAM: reset result: %02X")
    TRC_MSG(FUNC_NVRAM_TST,          "NVRAM: tst handler")
    TRC_MSG(FUNC_NVRAM_READ_SM,      "NVRAM: read sm handler")
    TRC_MSG(FUNC_NVRAM_READ_SM_CNF,  "NVRAM: read sm result: %02X. Sniff: file_idx:%2X, para:%2X, %02X:%02X")
    TRC_MSG(FUNC_NVRAM_WRITE_SM,     "NVRAM: write sm handler")
    TRC_MSG(FUNC_NVRAM_WRITE_SM_CNF, "NVRAM: write sm result: %02X")

    /* TRACE_STATE trace class */
    TRC_MSG(STATE_NVRAM_NULL,      "NVRAM: State: NULL. Cannot initialized. Device fail?")
    TRC_MSG(STATE_NVRAM_NOT_READY, "NVRAM: State: Not ready. Initialized but not receive STARTUP yet")
    TRC_MSG(STATE_NVRAM_READY,     "NVRAM: State: Ready. Receive STARTUP and ready")

    /* TRACE_INFO trace class */
    TRC_MSG(INFO_NVRAM_DRV_INIT,        "NVRAM: DRV report: initialized")
    TRC_MSG(INFO_NVRAM_DRV_UNFORMATTED, "NVRAM: DRV report: DRV_UNFORMATTED")
    TRC_MSG(INFO_NVRAM_LOCK_STATUS,     "NVRAM: lock: %d")

    /* TRACE_WARNING trace class */
    TRC_MSG(WARNING_NVRAM_SYS_RECORD,   "NVRAM: %d is corrupted")
    TRC_MSG(WARNING_NVRAM_ALL_LDI_INIT, "NVRAM: Warning: all logical data items of category '%d' are to be reset; unformatted device or incompatible version?")

    /* TRACE_ERROR trace class */
    TRC_MSG(ERROR_NVRAM_CANNOT_STARTUP,   "NVRAM: Receive STARTUP but cannot startup. Device fail?")
    TRC_MSG(ERROR_NVRAM_STATE,            "NVRAM: State error")
    TRC_MSG(ERROR_NVRAM_TST_INVALID_COMM, "NVRAM: Invalid Command")

    TRC_MSG(FUNC_NVRAM_NOTIFY_EXCEPTION1, "NVRAM: Read exception error!")
    TRC_MSG(FUNC_NVRAM_NOTIFY_STATISTICS, "NVRAM: Notification!!! Statistics updated!")
    TRC_MSG(FUNC_NVRAM_NOTIFY_EXCEPTION2, "NVRAM: Notification!!! Pending exceptions [SN: %x] [Type: %x] [TaskName: %8s][SysTime: (%2d/%2d) %2d:%2d]")
    TRC_MSG(FUNC_NVRAM_WRITE_EXCEPTION1,  "nvram_write_exception(): ex_data == NULL")
    TRC_MSG(FUNC_NVRAM_WRITE_EXCEPTION2,  "nvram_write_exception(): Read Exception [%d] Error!")

    /* nvram io */
    TRC_MSG(IO_READ_DATA_ITEM_START,    "Read Start: LID=%d, rec_index=%d, rec_amount=%d, buffer_size=%d")
    TRC_MSG(IO_READ_DATA_ITEM_RESULT,   "Read Result: LID=%d, status=%d, line=%d")
    TRC_MSG(IO_READ_DATA_ITEM_SINGLE,   "Read Single Result: LID=%d, drv_status=%d, fat_status=%d, line=%d")
    TRC_MSG(IO_READ_DATA_ITEM_MULTIPLE, "Read Multiple Result: LID=%d, drv_status=%d, fat_status=%d, line=%d")

    TRC_MSG(IO_WRITE_DATA_ITEM_START,    "Write Start: LID=%d, index =%d, is_init=%d")
    TRC_MSG(IO_WRITE_DATA_ITEM_RESULT,   "Write Result: LID=%d, status=%d, line= %d, init=%d")
    TRC_MSG(IO_WRITE_DATA_ITEM_SINGLE,   "Write Single Result: LID=%d, drv_status=%d, fat_status=%d, line=%d")
    TRC_MSG(IO_WRITE_DATA_ITEM_MULTIPLE, "Write Multiple Result: LID=%d, drv_status=%d, fat_status=%d, line=%d")

    TRC_MSG(IO_RESET_DATA_ITEM, "Reset Data Item: LID=%d, line=%d")

    TRC_MSG(EX_IO_RECOVER_IMAGE_BY_LID, "Recover image via lid error, LID=%d, error =%d, line=%d")

    TRC_MSG(FUNC_NVRAM_GET_DEFAULT_VALUE, "NVRAM: Get default value LID=%d, result=%d, size=%d, des=%s")
    TRC_MSG(INFO_NVRAM_INIT_SDS_STATUS, "NVRAM: init status, sw_status=%d, storage_mode=%d")
    TRC_MSG(FUNC_NVRAM_SDS_READ_DATA_ITEM, "NVRAM: sds_read_data_item, LID=%d, result=%d")
    TRC_MSG(FUNC_NVRAM_SDS_FLUSH_IN, "NVRAM: sds_flush_in, result=%d")
    TRC_MSG(FUNC_NVRAM_SDS_FLUSH_OUT, "NVRAM: sds_flush_out")
    TRC_MSG(FUNC_NVRAM_SDS_THROW_EXCEPTION, "NVRAM: sds_throw_exception, error=%d line=%d")

    TRC_MSG(FUNC_NVRAM_AP_BIN_REGION_BACKUP, "NVRAM: nvram_ap_bin_region_backup")

    /* Nvram OTP */
    TRC_MSG(OTP_INIT,          "Init OTP")
    TRC_MSG(OTP_FAKE_WRITE,    "OTP Write Area: %x~%x")
    TRC_MSG(OTP_AREA_ALLOW,    "OTP Area Allowed: %x~%x")
    TRC_MSG(OTP_PROGRAM_TWICE, "OTP Area programmed twice: %x~%x")
    TRC_MSG(OTP_OVERSCOPE,     "OTP Area Overscope: 0x%X~0x%X")
    TRC_MSG(OTP_READ_RESULT,   "OTP_Read result = %d, range =%x : %x")
    TRC_MSG(OTP_WRITE_RESULT,  "OTP_Write result = %d")

    /* Pseudo merge */
    TRC_MSG(MERGE_WRITE_TEMP_RESULT,    "Write temp record Result: lid_moving_index=%d, lid_adding_index=%d, fat_status=%d, line=%d")
    TRC_MSG(MERGE_TRUNK_STATUS,         "FS_Open_Truncate status: %d")
    TRC_MSG(MERGE_OPEN_PKG_FILE_RESULT, "nvram_create_package_file: package_File = %d")

    /* handler test */
    TRC_MSG(TEST_RESET_OK,           "[NVRAM][Test]Exception record clear complete!")
    TRC_MSG(TEST_RESET_FAIL,         "[NVRAM][Test]Error to clear Exception record!")
    TRC_MSG(TEST_RESET_ALL_OK,       "[NVRAM][Test]All data item has been reset!")
    TRC_MSG(TEST_RESET_ALL_FAIL,     "[NVRAM][Test]Reset all data item failed!")
    TRC_MSG(TEST_RESET_INVALID_LID,  "[NVRAM][Test]Invalid LID!")
    TRC_MSG(TEST_RESET_CERTAIN_OK,   "[NVRAM][Test]Data item has been reset!")
    TRC_MSG(TEST_RESET_CERTAIN_FAIL, "[NVRAM][Test]Reset data item failed!")
    
    TRC_MSG(TEST_VALID_EXCEPTIONS,   "[NVRAM][Test]Total %d Exceptions Vaild!")
    TRC_MSG(TEST_INVALID_EXCEPTIONS, "[NVRAM][Test]Exception #%d is Invaild!")
    TRC_MSG(TEST_REC_NUM_OUT_RANGE,  "[NVRAM][Test]Get Exception record number out of range!")
    TRC_MSG(TEST_RESET_STAT_OK,      "[NVRAM][Test]Reset statistics succeded!")
    TRC_MSG(TEST_RESET_STAT_FAIL,    "[NVRAM][Test]Reset statistics failed!")
    TRC_MSG(TEST_RESET_ALLOC_FAIL,   "[NVRAM][Test]Could not allocat ctrl buffer! Show statistics info detail abort!")
    TRC_MSG(TEST_GET_STAT_FAIL,      "[NVRAM][Test]Get statistic information form nvram error!")

    TRC_MSG(TEST_SYSINFO_DETAIL1,              "[NVRAM][Test][Sysinfo]%2d: [%4d][%4d][%4d][%4d][%4d]")
    TRC_MSG(TEST_SYSINFO_DETAIL2,              "[NVRAM][Test][Sysinfo]%2d: [%7s %4d][%7s %4d][%7s %4d][%7s %4d][%7s %4d]")

    TRC_MSG(TEST_SYSINFO_STATUS,              "[NVRAM][Test][Sysinfo]status = %u")
    TRC_MSG(TEST_SYSINFO_MAX_SYSMEM,          "[NVRAM][Test][Sysinfo]Max SysMem used = %u")
    TRC_MSG(TEST_SYSINFO_MAX_SYSDBGMEM,       "[NVRAM][Test][Sysinfo]Max SysDbgMem used = %u")
    TRC_MSG(TEST_SYSINFO_MAX_TASK_STACK_USED, "[NVRAM][Test][Sysinfo]Max task stack used:")
    
    TRC_MSG(TEST_SYSINFO_MAX_HISR_STACK_USED, "[NVRAM][Test][Sysinfo]Max hisr stack used:")
    TRC_MSG(TEST_SYSINFO_MAX_TASK_EXTQ_ENQED, "[NVRAM][Test][Sysinfo]Max task extq enqued:")
    TRC_MSG(TEST_SYSINFO_CTRLBUFF_ALLOC,      "[NVRAM][Test][Sysinfo]Max ctrl buff num allocated:")
    TRC_MSG(TEST_SYSINFO_CTRLBUFF_LIST,       "[NVRAM][Test][Sysinfo](8/16/32/64/128) / (256/512/1024/2048/4096) / (8192/16384/32768/65536)")

    /* L1 def */
    TRC_MSG(L1_SEND_UNINIT_LID,     "[NVRAM][L1_DEF]Un-cali: LID = %d")
    TRC_MSG(L1_SEND_UNINIT_LID_PKG, "[NVRAM][L1_DEF]Un-cali: LID = %d, Description = package lid")

	/* nvram compress*/
	TRC_MSG(ABNORMAL_RETURN, "[NVRAM][UNZIP]Abnormal return at line:%d")
	TRC_MSG(UNZIP_SIZE, "[NVRAM][UNZIP]nvram_unzip_size()LID =%d")
	TRC_MSG(UNZIP_SIZE_RESULT, "[NVRAM][UNZIP]nvram_unzip_size()zip_size=%d, org_size=%d")
	TRC_MSG(UNZIP_RESULT, "[NVRAM][UNZIP]nvram_unzip_default_value() zip_size=%d, org_size=%d, ret =%d")

    TRC_MSG(FUNC_NVRAM_VERSION_CONFLICT_RESOLVE, "nvram_version_conflict_resolve step=%d")
    TRC_MSG(FUNC_NVRAM_SUPPLEMENTARY_CHECK, "nvram_supplementary_check, type=%d")
    TRC_MSG(FUNC_NVRAM_INIT_ALL, "nvram_init_all, category=%d")
    TRC_MSG(FUNC_NVRAM_INIT, "nvram_init, step=%d, para=%d")
    TRC_MSG(FUNC_NVRAM_DRV_FAT_THROW_EXCEPTION, "nvram_drv_fat_throw_exception, err=%d, line=%d")
    TRC_MSG(FUNC_NVRAM_RESET_DATA_ITEMS, "nvram_reset_data_items, category=%d, state=%d, app_id=%d, lid=%d, rec_index=%d")
    TRC_MSG(FUNC_NVRAM_CREATE_ALL_FOLDER, "nvram_create_all_folder, folder=%d")
    TRC_MSG(FUNC_NVRAM_DELETE_ALL_NVRAM_FILES, "nvram_delete_all_nvram_files, bootup_type=%d")
    TRC_MSG(INFO_NVRAM_DATA_ITEM,    "LID=%Mnvram_trc_lid_enum, size=%d")

END_TRACE_MAP(MOD_NVRAM)

#endif /* _NVRAM_TRC_H */


