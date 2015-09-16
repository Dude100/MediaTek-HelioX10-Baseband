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
 *   ccmni_trace.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI CCMNI DHL debug messages
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 05 14 2014 ap.wang
 * removed!
 * CCMNI Fast Ack Patch and linkdown fast reload
 *
 * removed!
 * removed!
 * 	[CCMNI ACK Fast Path]
 *
 * 08 27 2013 ap.wang
 * removed!
 * CCMNI L2 trace
 *
 * 08 15 2013 ap.wang
 * removed!
 * [CCMNI] Move CCCI header to BD extension
 *
 * 02 05 2013 ap.wang
 * removed!
 *
 * 01 22 2013 ap.wang
 * removed!
 * .
 *
 * removed!
 * removed!
 * sync latest version of new features
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#ifndef _CCMNI_TRACH_H
#define _CCMNI_TRACH_H


#if HIF_CONSOLE_TRACE_ENABLED != 1

#ifndef GEN_FOR_PC
 #include "kal_public_defs.h"
#endif /* GEN_FOR_PC */

#include "dhl_trace.h"
#include "dhl_def.h"

#if !defined(GEN_FOR_PC)
#if defined(__DHL_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "ccmni_trace_gen.h"
#endif /* TST Trace Defintion */
#endif

#endif /* HIF_CONSOLE_TRACE_ENABLED != 1 */

BEGIN_TRACE_MAP(MOD_CCMNI)
    //4  <fatal_error_msg>, follow by ASSERT(0);
    TRC_MSG(CCMNI_TR_SESSION_INIT_FATAL_ERROR, "[CCMNI] session init fatal error. device id:(%d) err_code: (%d)")
    TRC_MSG(CCMNI_TR_UL_INVALID_IOR,      "[CCMNI] ccmni_ccci_ul_cb(): CCCI_CH (%d) invalid IOR(%X), first_gpd(%X) last_gpd(%X) => Possible RGPD leakage, ASSERT")

    //4  <error_msg>
    TRC_MSG(CCMNI_TR_SM_UNHANDLED_MSG,    "[CCMNI] unhandled MSG (%x)!")
    TRC_MSG(CCMNI_TR_UL_INVALID_CCCI_CH,  "[CCMNI] CCCI_CH (%d) UL gets invalid ccci channel id (%d)!")
    TRC_MSG(CCMNI_TR_DATA_DUMMY_CH_TRIG,  "[CCMNI] ccmni ccci dummy ch receive data ch(%d)")
    TRC_MSG(CCMNI_TR_UL_RGPD_SUBMITTED_FAIL, "[CCMNI] ccci_write_gpd with RGPD error. device id:(%d) ch(%d) err_code: (%d) {IOR, head, tail}={%x,%x,%x}")
    TRC_MSG(CCMNI_TR_UL_FREE_INVALID_GPD, "[CCMNI] ccmni_ccci_ul_cb(): CCCI_CH (%d) free invalid GPD: %X, prev: %X, next: %X, first_gpd:%X, last_gpd:%X")
    TRC_MSG(CCMNI_TR_UL_DISCARD_IN_DISCONNECTED, "[CCMNI] ccmni_ccci_ul_cb(): CCCI_CH (%d) DISCARD uplink GPD: %d in disconnected state!")
    TRC_MSG(CCMNI_TR_UL_NULL_IOR,        "[CCMNI] ccmni_ccci_ul_cb(): CCCI_CH (%d) receives NULL = *ior => drop it")
    TRC_MSG(CCMNI_TR_UL_ALLOC_GPD,        "[CCMNI] dev_id (%d) UL RGPD to allocate: %d, allocated: %d, in HIF: %d")
    TRC_MSG(CCMNI_TR_UL_RGPD_SUBMITTED,   "[CCMNI] ccci_write_gpd with RGPD success. device id:(%d) ch(%d) err_code: (%d) {IOR, head, tail}={%x,%x,%x}")

    //4 <info_msg>
    TRC_MSG(CCMNI_TR_HMU_INIT,            "[CCMNI] ccmni_hmu_init dev_id (%d)")
    TRC_MSG(CCMNI_TR_HMU_PREINIT,         "[CCMNI] ccmni_hmu_pre_init dev_id (%d)")
    TRC_MSG(CCMNI_TR_HMU_POSTINIT,        "[CCMNI] ccmni_hmu_post_init dev_id (%d)")
    TRC_MSG(CCMNI_TR_HMU_DEINIT,          "[CCMNI] ccmni_hmu_deinit dev_id (%d)")
    TRC_MSG(CCMNI_TR_HMU_PREDEINIT,       "[CCMNI] ccmni_hmu_pre_deinit dev_id (%d)")
    TRC_MSG(CCMNI_TR_HMU_POSTDEINIT,      "[CCMNI] ccmni_hmu_post_deinit dev_id (%d)")
    TRC_MSG(CCMNI_TR_SM_VALID_EVENT,      "[CCMNI] dev_id (%d) current state(%d) -> event(%d) -> new state(%d)")
    TRC_MSG(CCMNI_TR_SM_INVALID_EVENT,    "[CCMNI] dev_id (%d) current state(%d) receive a unexpected event(%d)!")
    TRC_MSG(CCMNI_TR_RGPD_RELOAD_BY_INIT, "[CCMNI] ccmni_reload_ul_gpds() called by ccmni_session_init dev_id (%d)")
    TRC_MSG(CCMNI_TR_UL_RCV_GPD,          "[CCMNI] CCCI_CH (%d) Receive UL RGPD: %d, in HIF: %d")
    TRC_MSG(CCMNI_TR_UL_EMPTY_IOR,        "[CCMNI] ccmni_ccci_ul_cb(): CCCI_CH (%d) receives empty IOR => drop it")

    //4 <trace_msg>
    TRC_MSG(CCMNI_TR_DL_CCCIH_TRACE,      "[CCMNI] ccmni_ipc_dl(): dev_id (%d) ccci_write_gpd cnt(%d) with CCCI HEADER (%x # %x # %x # %x)")
    TRC_MSG(CCMNI_DUMP_GPD_PTR,           "[CCMNI_DUMP] GPD=0x%x BD=0x%x BD=0x%x DATA=0x%x")
    TRC_MSG(CCMNI_DUMP_DATA_4HEX,         "[CCMNI_DUMP] %08x %08x %08x %08x")
    TRC_MSG(CCMNI_INDEX_ERROR,            "[CCMNI] SEQNO not match dev(%d) in(%x) expect(%x)")
    
    //4 <ut msg>
    TRC_MSG(CCMNI_UT_TR_HMU_INIT,         "[CCMNI_UT] ccmni_hmu_init dev_id (%d)")
    TRC_MSG(CCMNI_UT_TR_HMU_DEINIT,       "[CCMNI_UT] ccmni_hmu_deinit dev_id (%d)")
    TRC_MSG(CCMNI_UT_TR_LINK_UP_REQ,      "[CCMNI_UT] LINK UP dev_id (%d)")
    TRC_MSG(CCMNI_UT_TR_LINK_DOWN_REQ,    "[CCMNI_UT] LINK DOWN dev_id (%d)")   
    TRC_MSG(CCMNI_UT_FUNC_TRACE,          "[CCMNI_UT] ----%5d Function Begin----\n")   
    TRC_MSG(CCMNI_UT_FUNC_PASS_TRACE,     "[CCMNI_UT] ^^^^%5d Function PASS ^^^^\n")   
    TRC_MSG(CCMNI_UT_FUNC_STEP_TRACE,     "[CCMNI_UT] %5d test step %d \n")
    TRC_MSG(CCMNI_UT_ERR,                 "[CCMNI_UT][ERROR] %d \n")
    TRC_MSG(CCMNI_PROFILING_RELOAD_TRACE, "[CCMNI_PROFILING] Reload GPD = %d \n")
    TRC_MSG(CCMNI_PROFILING_RGPD_TRACE,   "[CCMNI_PROFILING] Receive GPD = %d \n")
    TRC_MSG(CCMNI_PROFILING_CYCLE_TRACE,  "[CCMNI_PROFILING] Cycle count = %d \n")
    TRC_MSG(CCMNI_UT_PURE_LB_MODE_TRACE,  "[CCMNI_UT] CCMNI_IT_PURE_LB channel=%d, numgpd =%d \n")
    

    //4 <misc_info_msg>
    TRC_MSG(CCMNI_TR_LINKUP_REQ_MSG,      "[CCMNI] Dev (%x) Linkup!")
    TRC_MSG(CCMNI_TR_LINKDOWN_REQ_MSG,    "[CCMNI] Dev (%x) Linkdown!")   

    //4 <it msg> ==================================================
    TRC_MSG(CCMNI_TR_IT_LB,               "[CCMNI][IT] ===>ccmni_ul2dl_loopback Dev (%x)")
    TRC_MSG(CCMNI_TR_IT_PING,             "[CCMNI][IT] ===>ccmni_it_ping Dev (%x)")   
    TRC_MSG(CCMNI_TR_IT_UDP,              "[CCMNI][IT] ===>ccmni_it_udp Dev (%x)")   
    TRC_MSG(CCMNI_TR_IT_RGPD_CNT,         "[CCMNI][IT] Dev (%x) Rx RGPD cnt (%d) BPS RGPD cnt (%d)")
    TRC_MSG(CCMNI_TR_IT_ICMP_SEQ,         "[CCMNI][IT] Dev (%x) ICMP echo seq. (%d)")
    TRC_MSG(CCMNI_TR_IT_UDP_SEQ,          "[CCMNI][IT] Dev (%x) UDP seq. (%d)")

    TRC_MSG(CCMNI_TR_PG_BW_ERR,           "[CCMNI_PG][IT] Request BW error (%d) treated as 150Mbps")
    TRC_MSG(CCMNI_TR_PG_LEN_ERR,          "[CCMNI_PG][IT] Request payload length error (%d) treated as 1500 Bytes")
    TRC_MSG(CCMNI_TR_PG_HD_ERR,           "[CCMNI_PG][IT] fatal error: **drop request** p_iph or p_udph is NULL")
    TRC_MSG(CCMNI_TR_PG_NO_BPS,           "[CCMNI_PG][IT] NO_BPS_GPD, skip Tx this time, consecutive skip number (%d)")
    TRC_MSG(CCMNI_TR_PG_NO_TGPD,          "[CCMNI_PG][IT] NO_TGPD, skip Tx this time, consecutive skip number (%d)")
    TRC_MSG(CCMNI_TR_PG_NOT_ENOUG_TGPD,   "[CCMNI_PG][IT] Cannot allocate enough TGPD (%d)/(%d)")
    TRC_MSG(CCMNI_TR_PG_NOT_ENOUG_BW,     "[CCMNI_PG][IT] Target BW too small ntgpd = (%d) set as (%d)")

    TRC_MSG(CCMNI_TR_IT_AT_DEV_ERR,       "[CCMNI][IT] Dev number = %d, AT command devid = %d")
    TRC_MSG(CCMNI_TR_IT_AT_MODE_ERR,      "[CCMNI][IT] MAX mode = %d, AT command mode = %d")
    TRC_MSG(CCMNI_TR_IT_AT_OP_ERR,        "[CCMNI][IT] Dev (%x) AT command op = %d")
    TRC_MSG(CCMNI_TR_IT_AT_OP_SET,        "[CCMNI][IT] Dev (%x) Set IT Mode = %d")
    TRC_MSG(CCMNI_TR_IT_AT_OP_READ,       "[CCMNI][IT] Dev (%x) Read IT Mode = %d")
    TRC_MSG(CCMNI_TR_IT_AT_INFO,          "[CCMNI][IT] ccmni_it_mode_switch devid = %d Mode = %d OP =%d")
    TRC_MSG(CCMNI_TR_IT_FUNC_TRACE,       "[CCMNI][IT] ----%5d Function Begin----\n")   
    TRC_MSG(CCMNI_TR_IT_FUNC_PASS_TRACE,  "[CCMNI][IT] ^^^^%5d Function PASS ^^^^\n")
    TRC_MSG(CCMNI_TR_IT_PING_TRACE,       "[CCMNI][IT] ----ccmni_it_ip4_ping Function Begin----\n")   
    TRC_MSG(CCMNI_TR_IT_PING_PASS_TRACE,  "[CCMNI][IT] ^^^^ccmni_it_ip4_ping Function PASS ^^^^\n")
    TRC_MSG(CCMNI_TR_IT_MS_TRACE,         "[CCMNI][IT] ----ccmni_process_mode_switch Function Begin----\n") 
    TRC_MSG(CCMNI_TR_IT_MS_PASS_TRACE,    "[CCMNI][IT] ^^^^ccmni_process_mode_switch Function PASS ^^^^\n")
    TRC_MSG(CCMNI_TR_IT_RL_TRACE,         "[CCMNI][IT] ----ccmni_it_reload_rgpds Function Begin----\n") 
    TRC_MSG(CCMNI_TR_IT_RL_PASS_TRACE,    "[CCMNI][IT] ^^^^ccmni_it_reload_rgpds Function PASS ^^^^\n")
END_TRACE_MAP(MOD_CCMNI)


#endif //#ifndef _CCMNI_TRACH_H
