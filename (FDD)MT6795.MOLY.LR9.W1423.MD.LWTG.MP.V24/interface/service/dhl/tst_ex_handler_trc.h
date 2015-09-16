/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   tst_ex_handler_trc.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file defines the index trace of TST exception handler
 *   This file is included by SST\include\SST_trc.h
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 *  .
 *
 * 11 07 2012 ken.liu
 * removed!
 * dhl module check-in.
 ****************************************************************************/

TRC_MSG(TST_EX_MSG_DUMP_UART_RING_BUFFER_START, "[EXC][COMMON] Dump UART ring buffer data start (port:%MDCL_DEV_T)!")
TRC_MSG(TST_EX_MSG_DUMP_UART_RING_BUFFER_END, "[EXC][COMMON] Dump UART ring buffer data end (port:%MDCL_DEV_T)!")
TRC_MSG(TST_EX_MSG_DISABLE_LGA_BUF_UNDER_SS_START, "[EXC][COMMON] Disable Lga buffer start!")
TRC_MSG(TST_EX_MSG_DISABLE_LGA_BUF_UNDER_SS_END, "[EXC][COMMON] Disable Lga buffer end!")
TRC_MSG(TST_EX_MSG_CLEAN_UART_UNDER_SS_START, "[EXC][COMMON] Clean up UART channel start (port:%MDCL_DEV_T)!")
TRC_MSG(TST_EX_MSG_CLEAN_UART_UNDER_SS_END, "[EXC][COMMON] Clean up UART channel end (port:%MDCL_DEV_T)!")
TRC_MSG(TST_EX_MSG_DUMP_PS_BUF_START, "[EXC][COMMON] Dump PS Buf start!")
TRC_MSG(TST_EX_MSG_DUMP_PS_BUF_END, "[EXC][COMMON] Dump PS Buf end!")
TRC_MSG(TST_EX_MSG_DISABLE_LGA_BUF_START, "[EXC][ELT] Disable Lga buffer start!")
TRC_MSG(TST_EX_MSG_DISABLE_LGA_BUF_END, "[EXC][ELT] Disable Lga buffer end!")
TRC_MSG(TST_EX_MSG_REOPEN_PORT_START, "[EXC][ELT] Reopen logging ports start!")
TRC_MSG(TST_EX_MSG_REOPEN_PORT_END, "[EXC][ELT] Reopen logging ports end!")
TRC_MSG(TST_EX_MSG_OPEN_PORT_START, "[EXC][ELT] open logging ports start! (Port:%MDCL_DEV_T)")
TRC_MSG(TST_EX_MSG_OPEN_PORT_END, "[EXC][ELT] open logging ports end! (Port:%MDCL_DEV_T)")
TRC_MSG(TST_EX_MSG_CLEAN_UART_START, "[EXC][ELT] Clean up UART channel start! (Port:%MDCL_DEV_T)")
TRC_MSG(TST_EX_MSG_CLEAN_UART_END, "[EXC][ELT] Clean up UART channel end! (Port:%MDCL_DEV_T)")
TRC_MSG(TST_EX_MSG_CLOSE_PORT_START, "[EXC][ELT] close logging ports start! (Port:%MDCL_DEV_T)")
TRC_MSG(TST_EX_MSG_CLOSE_PORT_END, "[EXC][ELT] close logging ports end! (Port:%MDCL_DEV_T)")
TRC_MSG(TST_EX_MSG_CHANGE_L1_PORT, "[EXC][ELT] Change L1 logging port from %MDCL_DEV_T to %MDCL_DEV_T !")
TRC_MSG(TST_EX_MSG_NESTED_EX_DETECTED, "[EXC][ELT] Detect nested exception! (times:%d)")
TRC_MSG(TST_EX_MSG_DUMP_SST_LOG_START, "[EXC][ELT] Redump exception log start!")
TRC_MSG(TST_EX_MSG_DUMP_SST_LOG_END, "[EXC][ELT] Redump exception log end!")
TRC_MSG(TST_EX_MSG_DRV_EX_HANDLER_START, "[EXC][ELT] Drv ex handler start!")
TRC_MSG(TST_EX_MSG_DRV_EX_HANDLER_END, "[EXC][ELT] Drv ex handler end!")
TRC_MSG(TST_EX_MSG_DUMP_LGA_BUF_START, "[EXC][ELT] Dump Lga buffer start!")
TRC_MSG(TST_EX_MSG_DUMP_LGA_BUF_END, "[EXC][ELT] Dump Lga buffer end!")
TRC_MSG(TST_EX_MSG_REDUMP_PS_BUF_START, "[EXC][ELT] Redump PS buffer start!")
TRC_MSG(TST_EX_MSG_REDUMP_PS_BUF_END, "[EXC][ELT] Redump PS buffer end!")
TRC_MSG(TST_EX_MSG_REDUMP_L1_BUF_START, "[EXC][ELT] Redump L1 buffer start!")
TRC_MSG(TST_EX_MSG_REDUMP_L1_BUF_END, "[EXC][ELT] Redump L1 buffer end!")
TRC_MSG(TST_EX_MSG_GET_ELT_CMD, "[EXC][ELT] Get one PC exception command:%Mdhl_command_type !")
TRC_MSG(TST_EX_MSG_GET_ELT_CMD_CHECKSUM_ERROR, "[EXC][ELT] Get one PC exception command:%Mdhl_command_type, but the checksum is incorrect! Expected checksum: %x, Got checksum: %x")
