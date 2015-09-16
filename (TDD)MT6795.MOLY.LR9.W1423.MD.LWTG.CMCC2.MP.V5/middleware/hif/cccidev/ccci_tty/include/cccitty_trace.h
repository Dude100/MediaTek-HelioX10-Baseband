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
 *   cccitty_trace.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI TTY DHL messages
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
 * 	Add cccitty sequence support(Merging from MP5 CL:641385 to MP6)
 *
 * removed!
 * removed!
 * 	add cccitty sequence support and status update support
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#ifndef _CCCITTY_TRACH_H
#define _CCCITTY_TRACH_H


#if HIF_CONSOLE_TRACE_ENABLED != 1

#ifndef GEN_FOR_PC
 #include "kal_public_defs.h"
#endif /* GEN_FOR_PC */

#include "dhl_trace.h"
#include "dhl_def.h"

#if !defined(GEN_FOR_PC)
#if defined(__DHL_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "cccitty_trace_gen.h"
#endif /* TST Trace Defintion */
#endif

#endif /* HIF_CONSOLE_TRACE_ENABLED != 1 */

BEGIN_TRACE_MAP(MOD_CCCITTY)
   //4  <fatal_error_msg>, follow by ASSERT(0);
   TRC_MSG(CCCI_TTY_TR_CCCI_CH_INIT_FATAL_ERROR, "[CCCI_TTY] CCCI CH init fatal error. device id:(%d) err_code: (%d)")
   TRC_MSG(CCCI_TTY_TR_TTYC_INIT_FATAL_ERROR,    "[CCCI_TTY] TTY Core init fatal error. device id:(%d) err_code: (%d)")
   TRC_MSG(CCCI_TTY_TR_TTYC_RGPD_Q_TYPE_ERR, "[CCCI_TTY] TTYC_RGPD_Q for ccci_ch(%d)ttyport(%d) has length (%d) but with invalid GPDtype(%x)")   
   TRC_MSG(CCCI_TTY_TR_TTYC_NEW_RX_ERR,     "[CCCI_TTY] CCCI_TTY not support NEW_RX for ccci_ch(%d) ttyport(%d) GPDtype(%x)")   
   TRC_MSG(CCCI_TTY_TR_TTYC_RGPD_LEAK,      "[CCCI_TTY] dev_id (%d) CCCI_TTY cannot allocate the RPGD just freed, should be (%d) but have (%d)")   
   TRC_MSG(CCCI_TTY_TR_TTYC_RGPD_INIT_ERR,  "[CCCI_TTY] Fail to allocate RGPD for HIF reload at initialization, to_alloc(%d) num_alloc(%d)")   
   TRC_MSG(CCCI_TTY_TR_UL_INVALID_IOR,      "[CCCI_TTY] cccitty_ccci_ul_cb(): dev_id (%d), invalid IOR(%X), first_gpd(%X) last_gpd(%X) => Possible RGPD leakage, ASSERT")
   TRC_MSG(CCCI_TTY_TR_TTYC_ERR_RGPD_LEAK,  "[CCCI_TTY] dev_id (%d) CCCI_TTY UL error rgpd number error , err_gpd_q size (%d), number of error gpd (%d)")      
   //4  <error_msg>
   TRC_MSG(CCCI_TTY_ADD_DL_SEQ_FAIL,    "[CCCI_TTY] Add cccitty sequence number Failed(%d) ch_num(%d)!")
   TRC_MSG(CCCI_TTY_CHK_UL_SEQ_FAIL,    "[CCCI_TTY] Check cccitty sequence number Failed(%d) ch_num(%d)!")
   TRC_MSG(CCCI_TTY_TR_SM_INVALID_EVENT,    "[CCCI_TTY] dev_id (%d) current state(%d) receive a unexpected event(%d)!")
   TRC_MSG(CCCI_TTY_TR_SM_UNHANDLED_MSG,    "[CCCI_TTY] unhandled MSG (%x)!")
   TRC_MSG(CCCI_TTY_TR_HDR_UNKNOWN_CMD,     "[CCCI_TTY] unknown TTY Command (%x)!")
   TRC_MSG(CCCI_TTY_TR_DATA_DUMMY_CH_TRIG,  "[CCCI_TTY] cccitty ccci dummy ch receive data ch(%d)")
   TRC_MSG(CCCI_TTY_TR_OPEN_OWNER_IS_NOT_NULL, "[CCCI_TTY] SIO_CMD_OPEN requests to open an occupied port New owner(%d) Original owner(%d)")
   TRC_MSG(CCCI_TTY_TR_HIF_UL_Q_NUM_ERR,    "[CCCI_TTY] HIF_UL_Q gpd number error, actual number(%d) hif_ul_rgpd_cnt(%d)")
   TRC_MSG(CCCI_TTY_TR_TTYC_RGPD_Q_NUM_ERR, "[CCCI_TTY] TTYC_RGPD_Q gpd number error, actual q len(%d) ttyc_rgpd_cnt(%d)")   
   TRC_MSG(CCCI_TTY_TR_TTYC_RGPD_Q_NUM_ERR_ACT1, "[CCCI_TTY] TTYC_RGPD_Q gpd number error set ttyc_rgpd_cnt = actual q len(%d)")   
   TRC_MSG(CCCI_TTY_TR_TTYC_RGPD_Q_NUM_ERR_ACT2, "[CCCI_TTY] TTYC_RGPD_Q gpd number error set ttyc_rgpd_cnt = 0")   
   TRC_MSG(CCCI_TTY_TR_ASSIGN_RX_IOR_STATE_ERR, "[CCCI_TTY] TTY_CMD_ASSIGN_RX_IOR received at WRONG CCCI_TTY state, ccci_tty_state(%d) ")   
   TRC_MSG(CCCI_TTY_TR_UL_RELOAD_NULL_IOR,  "[CCCI_TTY] cccitty_ttyc_hdr_cmd_assign_rx_ior(): port (%d) receives NULL = * IOR => drop it")
   TRC_MSG(CCCI_TTY_TR_RLD_CCCI_WRITE_FAIL,     "[CCCI_TTY] cccitty_ttyc_hdr_cmd_assign_rx_ior ccci_write_gpd fail (%d)") 
   TRC_MSG(CCCI_TTY_TR_DEQ_CCCI_WRITE_FAIL,  "[CCCI_TTY] cccitty_ul_deq_hdr: dev_id (%d) ccci_write_gpd fail (%d), might have gpd leakage") 
   TRC_MSG(CCCI_TTY_TR_UL_CCCI_WRITE_FAIL,  "[CCCI_TTY] cccitty_ccci_ul_cb: dev_id (%d) ccci_write_gpd fail (%d), might have gpd leakage") 

   TRC_MSG(CCCI_TTY_TR_UL_INVALID_PKT,      "[CCCI_TTY] cccitty_ccci_ul_cb: dev_id (%d) receive invalid RGPD num(%d) totoal invalid RGPD (%d)") 
   TRC_MSG(CCCI_TTY_TR_UL_RELOAD_EMPTY_IOR, "[CCCI_TTY] cccitty_ttyc_hdr_cmd_assign_rx_ior(): port (%d) receives empty IOR => drop it")   
   TRC_MSG(CCCI_TTY_TR_UL_NULL_IOR,         "[CCCI_TTY] cccitty_ccci_ul_cb(): dev_id (%d) ccci_channel (%d) receives NULL = * IOR => drop it")
   TRC_MSG(CCCI_TTY_TR_UL_RPGD_ERR,         "[CCCI_TTY] UL GPD ERROR ,CCCI channel not match or len == 0, --> drop, need to relod RGPD cnt(%d), accumulating error count (%d)")
   TRC_MSG(CCCI_TTY_TR_UL_DISCARD_IN_DISCONNECTED, "[CCCI_TTY] cccitty_ccci_ul_cb(): dev_id (%d) DISCARD uplink GPD: %d in (%x) state!, need to relod RGPD cnt(%d)")
   TRC_MSG(CCCI_TTY_TR_UL_EMPTY_IOR,        "[CCCI_TTY] cccitty_ccci_ul_cb(): dev_id (%d) receives empty IOR => drop it")    
   TRC_MSG(CCCI_TTY_TR_UL_DEV_NOT_OPEN,     "[CCCI_TTY] cccitty_ccci_ul_cb: dev_id (%d) receive ul rgpds while device is not open, state (%d)") 
   
   TRC_MSG(CCCI_TTY_TR_DL_EMPTY_IOR,        "[CCCI_TTY] cccitty_ttyc_hdr_cmd_put_bytes_ior(): dev_id (%d) receives empty IOR => drop it")
   TRC_MSG(CCCI_TTY_TR_DL_TXDONE_NULL_IOR,  "[CCCI_TTY] cccitty_ccci_dl_cb(): dev_id (%d) ccci_channel (%d) receives NULL = * IOR => drop it")
   TRC_MSG(CCCI_TTY_TR_DL_DEV_NOPEN,        "[CCCI_TTY] cccitty_ttyc_hdr_cmd_put_bytes_ior(): dev_id (%d) receives IOR while device state(%d) is not open(%d) => drop it")

   TRC_MSG(CCCI_TTY_TR_UL_CCCICH_ERR,      "[CCCI_TTY] cccitty_get_ul_devid(): cannot find valid dev_id for ccci_ch (%d), return CCCI_TTY_DEV_CNT")
   TRC_MSG(CCCI_TTY_TR_DL_CCCICH_ERR,      "[CCCI_TTY] cccitty_get_dl_devid(): cannot find valid dev_id for ccci_ch (%d), return CCCI_TTY_DEV_CNT")

   
   //4 <warning>
   TRC_MSG(CCCI_TTY_TR_UL_RGPD_EMPTY,      "[CCCI_TTY] dev_id (%d) Received RGPD own by others from HIF, current RGPD hwo_rgpd_cnt (%d)")
   TRC_MSG(CCCI_TTY_TR_HDR_NONSUPPORT_CMD,  "[CCCI_TTY] non-supported TTY Command (%x)!")
   
   //4 <info_msg>
   TRC_MSG(CCCI_TTY_TR_SM_VALID_EVENT,      "[CCCI_TTY] dev_id (%d) current state(%d) -> event(%d) -> new state(%d)")

   //4 <trace_msg>
   TRC_MSG(CCCI_TTY_TR_HMU_INIT,            "[CCCI_TTY] cccitty_hmu_init dev_id (%d)")
   TRC_MSG(CCCI_TTY_TR_HMU_PREINIT,         "[CCCI_TTY] cccitty_hmu_pre_init dev_id (%d)")
   TRC_MSG(CCCI_TTY_TR_HMU_POSTINIT,        "[CCCI_TTY] cccitty_hmu_post_init dev_id (%d)")
   TRC_MSG(CCCI_TTY_TR_HMU_DEINIT,          "[CCCI_TTY] cccitty_hmu_deinit dev_id (%d)")
   TRC_MSG(CCCI_TTY_TR_HMU_PREDEINIT,       "[CCCI_TTY] cccitty_hmu_pre_deinit dev_id (%d)")
   TRC_MSG(CCCI_TTY_TR_HMU_POSTDEINIT,      "[CCCI_TTY] cccitty_hmu_post_deinit dev_id (%d)")
   TRC_MSG(CCCI_TTY_TR_HDR_RCV_CMD,         "[CCCI_TTY] hdr receive TTY command (%x)!")

   TRC_MSG(CCCI_TTY_TR_DL_CCCIH_TRACE,      "[CCCI_TTY] cccitty_ttyc_hdr_cmd_put_bytes_ior(): dev_id (%d) ccci_write_gpd with CCCI HEADER (%x # %x # %x # %x)")
   TRC_MSG(CCCI_TTY_TR_DL_TXDONE_CB,        "[CCCI_TTY] cccitty_ccci_dl_cb(): dev_id (%d) ccci_channel (%d) p_cccitty->dcl_txdone callback")
   TRC_MSG(CCCI_TTY_TR_DL_TXDONE_CB_DIS,    "[CCCI_TTY] cccitty_ccci_dl_cb(): dev_id (%d) ccci_channel (%d) tty_need_tx_done_cb == FALSE, drop IOR")

   /* dequeue from hif_ul_rgpd ul to TTYC and dequeue ttyc_rgpd_q to reload to HIF driver*/
   TRC_MSG(CCCI_TTY_TR_RGPD_DEQ,            "[CCCI_TTY] cccitty_ul_deq_hdr: DEQUEUE dev_id (%d) ttyc_rgpd_cnt (%d) hif_ul_rgpd_cnt (%d) dequeue_num (%d) ")
   /* TTYCore RGPD reload to ttyc_rgpd_q*/
   TRC_MSG(CCCI_TTY_TR_RGPD_RELOAD,         "[CCCI_TTY] dev_id (%d) Reload ttyc_rgpd_q RGPD (%d) current RGPD (%d) ")

   /* HIF RPGD reload to HIF driver*/
   TRC_MSG(CCCI_TTY_TR_HIF_RGPD_RELOAD1,    "[CCCI_TTY] dev_id (%d) Reload HIF RGPD Type 1 - 1st time Reload HIF RGPD cnt (%d) current RGPD hwo_rgpd_cnt (%d) ")
   TRC_MSG(CCCI_TTY_TR_HIF_RGPD_RELOAD2,    "[CCCI_TTY] dev_id (%d) Reload HIF RGPD Type 2 - After UL GPD to TTYCore Reload RGPD cnt (%d) current RGPD hwo_rgpd_cnt (%d) ")
   TRC_MSG(CCCI_TTY_TR_HIF_RGPD_RELOAD3,    "[CCCI_TTY] dev_id (%d) Reload HIF RGPD Type 3 - Flush return RGPD cnt (%d) to HIF,  current RGPD hwo_rgpd_cnt (%d) ")
   TRC_MSG(CCCI_TTY_TR_HIF_RGPD_RELOAD4,    "[CCCI_TTY] dev_id (%d) Reload HIF RGPD Type 4 - cccitty_ccci_ul_cb Reload ERROR RGPD cnt (%d) current RGPD hwo_rgpd_cnt (%d) ")
   TRC_MSG(CCCI_TTY_TR_HIF_RGPD_RELOAD5,    "[CCCI_TTY] dev_id (%d) Reload HIF RGPD Type 5 - cccitty_ccci_ul_cb Reload DEV not open cnt (%d) current RGPD hwo_rgpd_cnt (%d) ")   
   /* HIF RGPD enqueue to hif_ul_rgpd */
   TRC_MSG(CCCI_TTY_TR_UL_RCV_GPD,         "[CCCI_TTY] dev_id (%d) Received RGPD , cnt (%d), from HIF, current RGPD hwo_rgpd_cnt (%d)")
   TRC_MSG(CCCI_TTY_TR_UL_SEND_DEQ,        "[CCCI_TTY] dev_id (%d) sent MSG_ID_CCCI_TTY_UL_DEQUEUE_REQ")
   
   //4 <ut msg>

   //4 <misc_info_msg>
END_TRACE_MAP(MOD_CCCITTY)


#endif //#ifndef _CCCITTY_TRACH_H
