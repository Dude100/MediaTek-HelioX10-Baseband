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
 *   ex_trc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains definitions for trace on target.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
  
#ifndef _EX_TRC_H
#define _EX_TRC_H

#ifndef GEN_FOR_PC
#include "kal_public_defs.h"
#endif /* GEN_FOR_PC */

#include "kal_trace.h"

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "ex_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_EX_LOG)

    /* TRACE_FUNC trace class */   

    /* exception type */
    TRC_MSG(EX_LOG_TYPE_UND, "Exception type: undefined instruction")
    TRC_MSG(EX_LOG_TYPE_SWI, "Exception type: SWI")
    TRC_MSG(EX_LOG_TYPE_PABT, "Exception type: prefetch abort")
    TRC_MSG(EX_LOG_TYPE_DABT, "Exception type: data abort")
    TRC_MSG(EX_LOG_TYPE_ASSERT, "Exception type: assert")
    TRC_MSG(EX_LOG_TYPE_FATALERR_TASK, "Exception type: fatal error(task)")
    TRC_MSG(EX_LOG_TYPE_FATALERR_BUFF, "Exception type: fatal error(buff)")
    TRC_MSG(EX_LOG_TYPE_INTERNAL_USE, "Exception type: internal use")

    /* software version */
    TRC_MSG(EX_LOG_SW_VER, "software version: %c%c%c%c%c%c%c%c%c%c%c%c")
    TRC_MSG(EX_LOG_SW_PROJECT, "software project: %s(%s)")
    TRC_MSG(EX_LOG_SW_BUILDTIME, "build time: %s")
    
    /* environment */
    TRC_MSG(EX_LOG_ENVINFO_FACTORY_BOOT, "boot mode: factory mode")
    TRC_MSG(EX_LOG_ENVINFO_NORMAL_BOOT, "boot mode: normal mode")
    TRC_MSG(EX_LOG_ENVINFO_USBMS_BOOT, "boot mode: USBMS mode")
    TRC_MSG(EX_LOG_ENVINFO_UNKNOWN_BOOT_MODE, "boot mode: unknown mode")
    TRC_MSG(EX_LOG_ENVINFO_RTC1, "rtc sec = %u, rtc min = %u, rtc hour = %u")
    TRC_MSG(EX_LOG_ENVINFO_RTC2, "rtc day = %u, rtc mon = %u, rtc wday = %u, rtc year = %u")
    TRC_MSG(EX_LOG_ENVINFO_TIMESTAMP, "exception timestamp: USCNT = %u, FrameNo = %u")
    TRC_MSG(EX_LOG_ENVINFO_EXECUTIONUNIT, "execution unit: %c%c%c%c%c%c%c%c")
    TRC_MSG(EX_LOG_ENVINFO_STATUS, "status: 0x%08X")
    TRC_MSG(EX_LOG_ENVINFO_ELM_STATUS, "ELM status: %s")
    TRC_MSG(EX_LOG_ENVINFO_STACIPOINTER, "stack pointer: 0x%08X")
    TRC_MSG(EX_LOG_ENVINFO_STACKDUMP_TITLE, "stack dump:")
    TRC_MSG(EX_LOG_ENVINFO_STACKDUMP, "    0x%08X")
    TRC_MSG(EX_LOG_ENVINFO_EXT_Q_PENDING_CNT, "number of messages in the external queue: %u")
    TRC_MSG(EX_LOG_ENVINFO_EXT_Q_PENDING_TITLE, "messages in the external queue:")
    TRC_MSG(EX_LOG_ENVINFO_EXT_Q_PENDING, "    %Mmsg_type")

    TRC_MSG(EX_LOG_ENVINFO_INTERRUPT_MASK, "interrupt mask: 0x%08X 0x%08X")
    TRC_MSG(EX_LOG_ENVINFO_PROCESSING_LISR, "processing_lisr: 0x%08X")
    TRC_MSG(EX_LOG_ENVINFO_LR, "lr: 0x%08X")

    /* diagnosis */
    TRC_MSG(EX_LOG_DIAGINFO_DIAGNOSIS_HEALTHY, "diagnosis: healthy")
    TRC_MSG(EX_LOG_DIAGINFO_DIAGNOSIS_INTSRAMCORRUPT, "diagnosis: internal SRAM corrupted")
    TRC_MSG(EX_LOG_DIAGINFO_DIAGNOSIS_SYSSTACKCORRUPT, "diagnosis: system stack corrupted")
    TRC_MSG(EX_LOG_DIAGINFO_DIAGNOSIS_TASKSTACKCORRUPT, "diagnosis: task stack corrupted")
    TRC_MSG(EX_LOG_DIAGINFO_DIAGNOSIS_HISRSTACKCORRUPT, "diagnosis: HISR stack corrupted")
    TRC_MSG(EX_LOG_DIAGINFO_DIAGNOSIS_VECTORTABLECORRUPT, "diagnosis: Vector 0x0--0x140 corrupted")

    TRC_MSG(EX_LOG_DIAGINFO_DIAGNOSIS_OWNER, "owner: %c%c%c%c%c%c%c%c")
    TRC_MSG(EX_LOG_DIAGINFO_DIAGNOSIS_TIMEING_CHECK, "timing check: %u %u %u %u %u %u")

    /* assert fail */
    TRC_MSG(EX_LOG_ASSERT_FILENAME, "filename: %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c")
    TRC_MSG(EX_LOG_ASSERT_LINE, "line: %u")
    TRC_MSG(EX_LOG_ASSERT_EXT1, "ext1: 0x%08X")
    TRC_MSG(EX_LOG_ASSERT_EXT2, "ext2: 0x%08X")
    TRC_MSG(EX_LOG_ASSERT_EXT3, "ext3: 0x%08X")
    TRC_MSG(EX_LOG_ASSERT_DUMP_TITLE, "dump:")
    TRC_MSG(EX_LOG_ASSERT_DUMP, "    0x%08X 0x%08X 0x%08X 0x%08X")

    /* fatal error */
    TRC_MSG(EX_LOG_FATALERR_MSG, "[%d] fatal error (%x): %Mkal_error_str - %c%c%c%c%c%c%c%c")
    TRC_MSG(EX_LOG_FATALERR_ERROR_CODE1, "fatal error code 1: 0x%08X")
    TRC_MSG(EX_LOG_FATALERR_ERROR_CODE2, "fatal error code 2: 0x%08X")

    /* control buffer */
    TRC_MSG(EX_LOG_CTRLBUF_SIZE, "ctrl buff size = %u")
    TRC_MSG(EX_LOG_CTRLBUF_NUM, "# of ctrl buff entries = %u")
    TRC_MSG(EX_LOG_CTRLBUF_TOP, "top occupier")
    TRC_MSG(EX_LOG_CTRLBUF_PREV, "previous buffer pointer")
    TRC_MSG(EX_LOG_CTRLBUF_COMMON_RTOS_HEADER1, "    RTOS header 1 = 0x%08X")
    TRC_MSG(EX_LOG_CTRLBUF_COMMON_RTOS_HEADER2, "    RTOS header 2 = 0x%08X")
    TRC_MSG(EX_LOG_CTRLBUF_COMMON_KAL_HEADER1, "    KAL header 1 = 0x%08X")
    TRC_MSG(EX_LOG_CTRLBUF_COMMON_KAL_HEADER2, "    KAL header 2 = 0x%08X")
    TRC_MSG(EX_LOG_CTRLBUF_COMMON_KAL_HEADER3, "    KAL header 3 = 0x%08X")
    TRC_MSG(EX_LOG_CTRLBUF_COMMON_BUFF_POOLID, "    buffer pool id = 0x%08X")
    TRC_MSG(EX_LOG_CTRLBUF_COMMON_KAL_FOOTER1, "    kal footer 1 = 0x%08X")
    TRC_MSG(EX_LOG_CTRLBUF_COMMON_KAL_FOOTER2, "    kal footer 2 = 0x%08X")
    TRC_MSG(EX_LOG_CTRLBUF_COMMON_FILENAME, "    source = %c%c%c%c%c%c%c%c%c%c%c%c")
    TRC_MSG(EX_LOG_CTRLBUF_COMMON_LR, "    Caller Address = 0x%08X")
    TRC_MSG(EX_LOG_CTRLBUF_COMMON_LINE, "    line = %u")
    TRC_MSG(EX_LOG_CTRLBUF_HISTORY_OWNER, "    owner = %c%c%c%c%c%c%c%c")
    TRC_MSG(EX_LOG_CTRLBUF_HISTORY_FILENAME, "    filename = %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c")
    TRC_MSG(EX_LOG_CTRLBUF_HISTORY_LINE, "    line = %u")
    TRC_MSG(EX_LOG_CTRLBUF_HISTORY_LR, "    Caller Address = 0x%08X")
    TRC_MSG(EX_LOG_CTRLBUF_HISTORY_COUNT, "    count = %u")
    TRC_MSG(EX_LOG_CTRLBUF_SECOND, "second occupier")
    TRC_MSG(EX_LOG_CTRLBUF_CURR, "current buffer pointer")
    TRC_MSG(EX_LOG_CTRLBUF_THIRD, "third occupier")
    TRC_MSG(EX_LOG_CTRLBUF_NEXT, "next buffer pointer")

    /* event scheduler buffer */
    TRC_MSG(EX_LOG_ESBUF_SIZE, "es buff size = %u")
    TRC_MSG(EX_LOG_ESBUF_NUM, "# of es buff entries = %u")
    TRC_MSG(EX_LOG_ESBUF_HISTORY_TIMERNAME, "    event scheduler name = %c%c%c%c%c%c%c%c")
    TRC_MSG(EX_LOG_ESBUF_HISTORY_MODULEID, "    dest module id = %Mmodule_type")
    TRC_MSG(EX_LOG_ESBUF_HISTORY_HANDLEFUNC, "    handler function address = 0x%08X")
    TRC_MSG(EX_LOG_ESBUF_HISTORY_COUNT, "    count = %u")
    TRC_MSG(EX_LOG_ESBUF_TOP, "top occupier")
    TRC_MSG(EX_LOG_ESBUF_SECOND, "second occupier")
    TRC_MSG(EX_LOG_ESBUF_THIRD, "third occupier")

    /* task info */
    TRC_MSG(EX_LOG_TASK_INFO_NAME, "TaskName = %c%c%c%c%c%c%c%c")
    TRC_MSG(EX_LOG_TASK_INFO_STACK_GP, "TaskStackGuardPattern = %c%c%c%c%c%c%c%c")
    TRC_MSG(EX_LOG_TASK_INFO_STATUS, "task current status = 0x%08X")
    TRC_MSG(EX_LOG_TASK_INFO_EXTQ, "task external queue")
    TRC_MSG(EX_LOG_TASK_INFO_Q_SRC_MOD_ID, "    src mod id = 0x%08X")
    TRC_MSG(EX_LOG_TASK_INFO_Q_QCOUNT, "    # of identical msg = 0x%08X")
    TRC_MSG(EX_LOG_TASK_INFO_Q_MSG_ID, "    msg id = 0x%08X")
    TRC_MSG(EX_LOG_TASK_INFO_Q_CUR_MSG_NO, "    # of pending msg = 0x%08X")
    TRC_MSG(EX_LOG_TASK_INFO_Q_CONFIG_ENTRY, "    # of queue entries = 0x%08X")
    TRC_MSG(EX_LOG_TASK_INFO_INTQ, "task internal queue")

    /* CPU registers */
    TRC_MSG(EX_LOG_CPU_REG_CPSR, "CPSR = 0x%08X")
    TRC_MSG(EX_LOG_CPU_REG_R0, "R0 = 0x%08X")
    TRC_MSG(EX_LOG_CPU_REG_R1, "R1 = 0x%08X")
    TRC_MSG(EX_LOG_CPU_REG_R2, "R2 = 0x%08X")
    TRC_MSG(EX_LOG_CPU_REG_R3, "R3 = 0x%08X")
    TRC_MSG(EX_LOG_CPU_REG_R4, "R4 = 0x%08X")
    TRC_MSG(EX_LOG_CPU_REG_R5, "R5 = 0x%08X")
    TRC_MSG(EX_LOG_CPU_REG_R6, "R6 = 0x%08X")
    TRC_MSG(EX_LOG_CPU_REG_R7, "R7 = 0x%08X")
    TRC_MSG(EX_LOG_CPU_REG_R8, "R8 = 0x%08X")
    TRC_MSG(EX_LOG_CPU_REG_R9, "R9 = 0x%08X")
    TRC_MSG(EX_LOG_CPU_REG_R10, "R10 = 0x%08X")
    TRC_MSG(EX_LOG_CPU_REG_R11, "R11 = 0x%08X")
    TRC_MSG(EX_LOG_CPU_REG_R12, "R12 = 0x%08X")
    TRC_MSG(EX_LOG_CPU_REG_R13, "R13(SP) = 0x%08X")
    TRC_MSG(EX_LOG_CPU_REG_R14, "R14(LR) = 0x%08X")
    TRC_MSG(EX_LOG_CPU_REG_R15, "R15(PC) = 0x%08X")

    /* BB registers */
    TRC_MSG(EX_LOG_REG_DUMP_MED, "BB register of multimedia:")
    TRC_MSG(EX_LOG_REG_DUMP_TITLE, "address        content")
    TRC_MSG(EX_LOG_REG_DUMP, "0x%08X     0x%08X 0x%08X 0x%08X 0x%08X")
    TRC_MSG(EX_LOG_REG_DUMP_PPP, "BB register of PPP:")
    TRC_MSG(EX_LOG_REG_DUMP_MSDC, "BB register of MSDC:")
    TRC_MSG(EX_LOG_REG_DUMP_SIM, "BB register of SIM:")
    TRC_MSG(EX_LOG_REG_DUMP_CHE, "BB register of CHE:")
    TRC_MSG(EX_LOG_REG_DUMP_PDN, "BB register of PDN:")
    TRC_MSG(EX_LOG_REG_DUMP_I2C, "BB register of I2C:")
    TRC_MSG(EX_LOG_REG_DUMP_LCD, "BB register of LCD:")

    /* special notification for L1 timing check assertion */
    TRC_MSG(EX_LOG_L1_TIMING_CHECK_ASSERT1, "L1 timing check fail.")
    TRC_MSG(EX_LOG_L1_TIMING_CHECK_ASSERT2, "Use the stack dump to find out who disables IRQ")

     /* Set Watchpoint, Breakpoint via ELT inject message function */
    TRC_MSG(MDDBG_HIT_BP,     "BreakPoint(0x%08X) is hit")
    TRC_MSG(MDDBG_HIT_WP_TBC, "WritePoint(Unknown) is hit at address 0x%08X")
    TRC_MSG(MDDBG_HIT_WP,     "WritePoint(0x%08X) is hit at address 0x%08X")
    TRC_MSG(MDDBG_HIT_Debug,     "[%d]0x%08X, 0x%08X, 0x%08X")

    /* dummy */
    TRC_MSG(EX_LOG_DUMMY, "")

END_TRACE_MAP(MOD_EX_LOG)

#endif    /* _EX_TRC_H */


