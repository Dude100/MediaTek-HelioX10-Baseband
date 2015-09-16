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
 *   ccci_trace.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI DHL trace messages
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
 * [CCCI] CCCI new debug mechanism
 *
 * removed!
 * removed!
 * [CCCI] Add & Maintain UT code
 *
 * removed!
 * removed!
 * Submit CCCI L2 trace
 *
 * 09 12 2013 ap.wang
 * removed!
 * 	Add CCCI Log
 *
 * 04 12 2013 ap.wang
 * removed!
 * [CCCI] Add log for debug
 *
 * removed!
 * removed!
 * [CCCI] CCCI/CLDMA INT
 *
 * removed!
 * removed!
 * MT6290 Rename CCCI Services
 *
 * 01 28 2013 ap.wang
 * removed!
 * [CCCI] CCCI_IMS channel rename
 *
 * removed!
 * removed!
 * sync latest version of new features
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#ifndef _CCCI_TRACH_H
#define _CCCI_TRACH_H


#if HIF_CONSOLE_TRACE_ENABLED != 1

#ifndef GEN_FOR_PC
 #include "kal_public_defs.h"
#endif /* GEN_FOR_PC */

#include "dhl_trace.h"
#include "dhl_def.h"

#if !defined(GEN_FOR_PC)
#if defined(__DHL_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "ccci_trace_gen.h"
#endif /* TST Trace Defintion */
#endif

#endif /* HIF_CONSOLE_TRACE_ENABLED != 1 */

BEGIN_TRACE_MAP(MOD_CCCI)
   //4  <fatal_error_msg>, follow by ASSERT(0);
    TRC_MSG(CCCI_TR_ULBUFF_RST_MD, "[CCCI_ERR] ccci_ulbuff_cb <AP>[CCCI_FORCE_RESET_MODEM_CHANNEL] ..\r\n")
    TRC_MSG(CCCI_TR_ULIOR_RST_MD, "[CCCI_ERR] ccci_ulior_cb <AP>[CCCI_FORCE_RESET_MODEM_CHANNEL] ..\r\n")
    TRC_MSG(CCCI_TR_DLIOR_RST_MD, "[CCCI_ERR]ccci_dlior_agg_cb log_chann=%d >= CCCI_MAX_CHANNEL=%d ...\r\n")
    TRC_MSG(CCCI_TR_ULCB_FUNP_ERR, "[CCCI_ERR] ccci_ulbuff_cb ccci_ctrl_pool[%d].funp == NULL\r\n")
    TRC_MSG(CCCI_TR_ULIORCB_FUNP_ERR, "[CCCI_ERR] <Rx data to an inactive GPD mode channel> ccci_ulior_cb[%d] iorcb_funp == NULL\r\n")
    TRC_MSG(CCCI_TR_ULIORCB_IORFUNP_ERR, "[CCCI_ERR] <Rx data to an inactive GPD mode channel> ccci_ulior_cb[%d] iorcb_funp == NULL\r\n")
    TRC_MSG(CCCI_TR_ULIORNETCB_IORFUNP_ERR, "[CCCI_ERR] <Rx data to an inactive GPD mode channel> ccci_ulior_net_cb[%d] iorcb_funp == NULL\r\n")    
    TRC_MSG(CCCI_TR_DLIOR_FUNP_ERR, "[CCCI_ERR] ccci_dlior_agg_cb[%d] iorcb_funp == NULL -1\r\n")
    TRC_MSG(CCCI_TR_DLIOR_IORFUNP_ERR, "[CCCI_ERR] ccci_dlior_agg_cb[%d] iorcb_funp == NULL -2\r\n")
    
   //4  <error_msg>
    TRC_MSG(CCCI_TR_DEINIT_STATE_ERR, "[CCCI_ERR] ccci_ctrl_pool[%d].state = %d should remain CCCI_IDLE(=0)\r\n")
    TRC_MSG(CCCI_TR_DEINIT_ATTCNT_ERR, "[CCCI_ERR] ccci channel [%d] detach fail due to hwq_detach fail (%d#%d#%d)\r\n")
    TRC_MSG(CCCI_TR_ULCB_BUFF_ERR, "[CCCI_ERR] ccci_ulbuff_cb pbuff == NULL \r\n")
    TRC_MSG(CCCI_TR_ULCB_CH_ERR, "[CCCI_ERR] ccci_ulbuff_cb log_chann=%d >= CCCI_MAX_CHANNEL=%d ...\r\n")
    TRC_MSG(CCCI_TR_ULIORCB_IOR_ERR, "[CCCI_ERR] ccci_ulior_cb io_request == NULL \r\n")
    TRC_MSG(CCCI_TR_ULIORCB_FGPD_ERR, "[CCCI_ERR] ccci_ulior_cb io_request->first_gpd == NULL \r\n")
    TRC_MSG(CCCI_TR_ULIORCB_TGPD_ERR, "[CCCI_ERR] ccci_ulior_cb io_request->last_gpd == NULL \r\n")
    TRC_MSG(CCCI_TR_ULIORCB_CH_ERR, "[CCCI_ERR] ccci_ulior_cb logic_channel=%d >= CCCI_MAX_CHANNEL=%d ...\r\n")
    TRC_MSG(CCCI_TR_ULIORCB_Q_ERR, "[CCCI_ERR] ccci_ulior_cb receives gpd with wrong hwqid queue_no=%d != ccci_ctrl_pool.hwq_id=%d ...\r\n")
    TRC_MSG(CCCI_TR_ULIORCB_CH_INAC, "[CCCI_ERR] <Rx data to an inactive Legacy mode channel> ccci_ulior_cb[%d] cb_funp == NULL\r\n")
    TRC_MSG(CCCI_TR_ULIORCB_TYPE_ERR, "[CCCI_ERR] ccci_ulior_cb ccci_ctrl_pool[%d].owner == %d\r\n")
    
    TRC_MSG(CCCI_TR_ULIORNET_IOR_ERR, "[CCCI_ERR] ccci_ulior_net_cb io_request == NULL \r\n")
    TRC_MSG(CCCI_TR_ULIORNET_HGPD_ERR, "[CCCI_ERR] ccci_ulior_net_cb io_request->first_gpd == NULL \r\n")
    TRC_MSG(CCCI_TR_ULIORNET_TGPD_ERR, "[CCCI_ERR] ccci_ulior_net_cb io_request->last_gpd == NULL \r\n")

    TRC_MSG(CCCI_TR_DLIOR_IOR_ERR, "[CCCI_ERR] ccci_dlior_agg_cb io_request == NULL \r\n")
    TRC_MSG(CCCI_TR_DLIOR_HGPD_ERR, "[CCCI_ERR] ccci_dlior_agg_cb io_request->first_gpd == NULL \r\n")
    TRC_MSG(CCCI_TR_DLIOR_TGPD_ERR, "[CCCI_ERR] ccci_dlior_agg_cb io_request->last_gpd == NULL \r\n")
    
    TRC_MSG(CCCI_TR_HSHK1_ERR, "The initial message error MB = (%x, %x, %x, %x) .. \r\n")
    TRC_MSG(CCCI_TR_BOOTACK_ERR, "The initial channel %d and value %d\n")
    TRC_MSG(CCCI_TR_SYSPERI_CB_ERR, "[CCCI_ERR] ====>ccci_system_channel_periodic_callback ccci_write return %x \r\n")
    TRC_MSG(CCCI_TR_SET_POLA, "[CCCI_ERR] =========>EINT_Set_Polarity \r\n")
    TRC_MSG(CCCI_TR_SET_EINT, "[CCCI_ERR] ====>CCMSG_ID_MD_EINT_ON_OFF ccci_write return %x \r\n")

    TRC_MSG(CCCI_TR_HSHK1_WNG, "[CCCI_ERR] ====>CCCI_SDIO_HANDSHAKE1 ccci_write return %x \n")
    TRC_MSG(CCCI_TR_HSHK2_DRV_VERERR, "[CCCI_ERR] CCMSG_ID_DRV_VERSION_ERR %X \n")
    TRC_MSG(CCCI_TR_HSHK2_WNG, "[CCCI_ERR] ====>CCCI_SDIO_HANDSHAKE2 ccci_write return %X \n")
    TRC_MSG(CCCI_TR_ILM_MSG_ERR, "[CCCI_ERR] Received wrong msg id in ILM msg: %d \n")

//==========ccci_init================
    TRC_MSG(CCCI_TR_INITB_ERR, "[CCCI_ERR] ccci_init[%d].ccci_uldl_iorcb_funp != NULL Buffer mode user should NOT request CCCI_TYPE_TX callback!! funp will be treated as NULL\r\n")
    TRC_MSG(CCCI_TR_INITB_ERR_CH_NO, "[CCCI_ERR] ccci_init channel=%d MOD_ID=%d Channel number error \n")
    TRC_MSG(CCCI_TR_INITB_ERR_FUNP, "[CCCI_ERR] ccci_init channel=%d MOD_ID=%d Function point is NULL \n")
    TRC_MSG(CCCI_TR_INITB_ERR_MODE, "[CCCI_ERR] ccci_init channel=%d MOD_ID=%d Channel Mode error \n")
    TRC_MSG(CCCI_TR_INITB_ERR_TYPE, "[CCCI_ERR] ccci_init channel=%d MOD_ID=%d Hardware Type(%d) error \n")
    TRC_MSG(CCCI_TR_INITB_ERR_INUSE, "[CCCI_ERR] ccci_init channel=%d MOD_ID=%d Channel is inuse \n")

//==========ccci_write================
    TRC_MSG(CCCI_TR_WRB_CH, "[CCCI_ERR] ccci_write ch(%d) MOD(%d) channel>=CCCI_MAX_CHANNEL ret CCCI_INALID_PARAM \n")
    TRC_MSG(CCCI_TR_WRB_BN, "[CCCI_ERR] ccci_write ch(%d) MOD(%d) buff == NULL ret CCCI_INALID_PARAM \n")
    TRC_MSG(CCCI_TR_WRB_OWNDIS, "[CCCI_ERR] ccci_write ch(%d) MOD(%d) ch.owner == CCCI_CH_DISABLE ret CCCI_INALID_PARAM \n")
    TRC_MSG(CCCI_TR_WRB_OWNGPD, "[CCCI_ERR] ccci_write ch(%d) MOD(%d) onwer(%d) not buffer user\n")
    TRC_MSG(CCCI_TR_WRB_MBXLEN, "[CCCI_ERR] ccci_write ch(%d) MOD(%d) mbx len (%d) error\n")
    TRC_MSG(CCCI_TR_WRITE_NO_TGPD_ERR, "[CCCI_ERR] ccci_write ch(%d) ran out of TGPD \r\n")
    TRC_MSG(CCCI_TR_WRITE_LEN_ERR, "[CCCI_ERR] ccci_write ch(%d) buffer len (%d) >  GPD allow_len (%d)\r\n")
    TRC_MSG(CCCI_TR_WRITE_IORCB_NULL_ERR, "[CCCI_ERR] ccci_write ch(%d) ccci_ctrl_pool[channel].ioreq_funp == NULL\r\n")

//==========ccci_write_gpd================
    TRC_MSG(CCCI_TR_WR_CH, "[CCCI_ERR] ccci_write_gpd ch(%d) MOD(%d) channel>=CCCI_MAX_CHANNEL ret CCCI_INALID_PARAM \n")
    TRC_MSG(CCCI_TR_WR_FGPDN, "[CCCI_ERR] ccci_write_gpd ch(%d) MOD(%d) ior->first_gpd == NULL ret CCCI_INALID_PARAM \n")
    TRC_MSG(CCCI_TR_WR_LGPDN, "[CCCI_ERR] ccci_write_gpd ch(%d) MOD(%d) ior->last_gpd == NULL ret CCCI_INALID_PARAM \n")
    TRC_MSG(CCCI_TR_WR_OWNDIS, "[CCCI_ERR] ccci_write_gpd ch(%d) MOD(%d) ch.owner == CCCI_CH_DISABLE ret CCCI_INALID_PARAM \n")
    TRC_MSG(CCCI_TR_WR_OWNBUFF, "[CCCI_ERR] ccci_write_gpd ch(%d) MOD(%d) ch.owner != CCCI_CH_USER_GPD ret CCCI_INALID_PARAM \n")
    TRC_MSG(CCCI_TR_WR_HIFREQ_NG, "[CCCI_ERR] ccci_write_gpd ch(%d) MOD(%d) ioreq_funp ret(%d)\n")

//==========ccci_gpd_init================
    TRC_MSG(CCCI_TR_INIT_ERR_CH_NO, "[CCCI_ERR] ccci_gpd_init channel=%d MOD_ID=%d Channel number error \n")
    TRC_MSG(CCCI_TR_INIT_ERR_FUNP, "[CCCI_ERR] ccci_init channel=%d MOD_ID=%d ior_funp function point is NULL \n")
    TRC_MSG(CCCI_TR_INIT_ERR_USR, "[CCCI_ERR] ccci_init channel=%d MOD_ID=%d usermode(%d) != CCCI_CH_USER_GPD \n")
    TRC_MSG(CCCI_TR_INIT_ERR_TYPE, "[CCCI_ERR] ccci_init channel=%d MOD_ID=%d Hardware Type(%d) error \n")
    TRC_MSG(CCCI_TR_INIT_ERR_INUSE, "[CCCI_ERR] ccci_init channel=%d MOD_ID=%d Channel is inuse \n")
    TRC_MSG(CCCI_TR_INIT_ERR_HIFA, "[CCCI_ERR] ccci_init channel=%d MOD_ID=%d gpdhwq_attach fail(%d \n")

   //4 <info_msg>
    TRC_MSG(CCCI_INIT_TRACE, "[CCCI_TRACE] ccci_init channel=%d MOD_ID=%d \n")
    TRC_MSG(CCCI_TR_RECEIVE_ILM, "[CCCI_TRACE] CCCI Receive ILM msg: %d \n")
   //4 <trace_msg>
    TRC_MSG(CCCI_TR_WRITE_NO_FLUSH, "[CCCI_TRACE] ccci_write (CCCI_TYPE_TX_NO_FLUSH) \r\n")
    TRC_MSG(CCCI_TR_ULIOR_CB_DBG, "[CCCI] ccci_ulior_cb local_queue_channel=%d, queue count= %d...\r\n")
    TRC_MSG(CCCI_TR_DLIOR_AGG_CB_DBG, "[CCCI] ccci_dlior_cb local_queue_channel=%d, queue count= %d...\r\n")
    
    TRC_MSG(CCCI_TR_SDIOCS_SIOR, "[CCCI_ERR] =========>dummy sdioc_submit_ior\r\n")
    TRC_MSG(CCCI_TR_SDIOCS_QATT, "[CCCI_ERR] =========>dummy sdioc_q_attach\r\n")
    TRC_MSG(CCCI_TR_SDIOCS_QDEATT, "[CCCI_ERR] =========>dummy sdioc_q_detach\r\n")
    TRC_MSG(CCCI_TR_SDIOCS_POLLING, "[CCCI_ERR] =========>dummy sdioc_polling_submit_one_gpd\r\n")

    TRC_MSG(CCCI_TR_CCIFCS_SIOR, "[CCCI_ERR] =========>dummy ccifc_submit_ior\r\n")
    TRC_MSG(CCCI_TR_CCIFCS_SBUFF, "[CCCI_ERR] =========>dummy ccifc_submit_buff\r\n")
    TRC_MSG(CCCI_TR_CCIFCS_GPDATT, "[CCCI_ERR] =========>dummy ccifc_q_gpd_attach\r\n")
    TRC_MSG(CCCI_TR_CCIFCS_BUFFATT, "[CCCI_ERR] =========>dummy ccifc_q_buff_attach\r\n")
    TRC_MSG(CCCI_TR_CCIFCS_QDEATT, "[CCCI_ERR] =========>dummy ccifc_q_detach\r\n")

    TRC_MSG(CCCI_TR_CAIFCS_SIOR, "[CCCI_ERR] =========>dummy caifc_submit_ior\r\n")
    TRC_MSG(CCCI_TR_CAIFCS_GPDATT, "[CCCI_ERR] =========>dummy caifc_q_gpd_attach return KAL_TRUE\r\n")
    TRC_MSG(CCCI_TR_CAIFCS_BUFFATT, "[CCCI_ERR] =========>dummy caifc_q_buff_attach return KAL_TRUE\r\n")
    TRC_MSG(CCCI_TR_CAIFCS_QDEATT, "[CCCI_ERR] =========>dummy caifc_q_detach return KAL_TRUE\r\n")
    TRC_MSG(CCCI_TR_CAIFCS_SBUFF, "[CCCI_ERR] =========>dummy caifc_submit_buff\r\n")

    TRC_MSG(CCCI_TR_CLDMACS_SIOR, "[CCCI_ERR] =========>dummy cldmac_submit_ior\r\n")
    TRC_MSG(CCCI_TR_CLDMACS_QATT, "[CCCI_ERR] =========>dummy cldmac_q_attach\r\n")
    TRC_MSG(CCCI_TR_CLDMACS_QDEATT, "[CCCI_ERR] =========>dummy cldmac_q_detach\r\n")    

    TRC_MSG(CCCI_TR_DUMMY_SIOR, "[CCCI_ERR] =========>!!! DROP_PKT !!! dummy_submit_ior\r\n")
    TRC_MSG(CCCI_TR_DUMMY_QATT, "[CCCI_ERR] =========> dummy_q_attach\r\n")
    TRC_MSG(CCCI_TR_DUMMY_QDEATT, "[CCCI_ERR] =========> dummy_q_detach\r\n")
    TRC_MSG(CCCI_TR_DUMMY_POLLING_IO, "[CCCI_ERR] =========> dummy_q_polling_io\r\n") 
    
    TRC_MSG(CCCI_ISNT_INIT, "[CCCI_ERR] =========>ccci_inst_init\r\n")    
    
    TRC_MSG(CCCI_TR_HSHK1_IN, "===> lte_ccci_init_handshake_phase1\n")
    TRC_MSG(CCCI_TR_HSHK1_WAIT_ACK, "wait for AP ACK")
    TRC_MSG(CCCI_TR_HSHK1_AP_ACK, "\n===>AP ACK RCVED %d !!\n")
    
    TRC_MSG(CCCI_TR_HSHK2_IN, "\n===> lte_ccci_init_handshake_phase2\n")
    TRC_MSG(CCCI_TR_HSHK2_DRV_VER, "[CCCI_HS] CCMSG_ID_DRV_VERSION %X \n")
    TRC_MSG(CCCI_DUMP_DATA_4HEX, "[CCCI_DUMP] %X %X %X %X \n")
   //4 <ut msg>
    TRC_MSG(CCCI_UT_SERIAL_ERR, "[CCCI_ERR][CCCI_UT] %d 1st packet is not 0 **** %x#%x#%x#%x#%x \n")
    TRC_MSG(CCCI_UT_OUT_OF_ORDER_ERR, "[CCCI_ERR][CCCI_UT] %d out-of-order **** %x#%x#%x#%x#%x \n")
    TRC_MSG(CCCI_UT_MAGICID_ERR, "[CCCI_ERR][CCCI_UT] %d MAGIC ID error **** %x#%x#%x#%x#%x \n")
    TRC_MSG(CCCI_UT_FUNC_TRA, "[CCCI_UT] ====>BEGIN %d \n")
    TRC_MSG(CCCI_UT_FUNC_STEP_TRA, "[CCCI_UT] %d test step %x \n")
    TRC_MSG(CCCI_UT_FUNC_PASS_TRA, "[CCCI_UT] %d PASS \n")
    TRC_MSG(CCCI_UT_ERR,"[CCCI_UT][ERROR] %d \n")
    TRC_MSG(CCCI_UT_FUNC_STEP_PASS_TRA, "[CCCI_UT] %d test step %d PASS, LB_COUNT %d##%d \n")
    TRC_MSG(CCCI_UT_FUNC_INIT_STEP_DEINIT_TRA, "[CCCI_UT] %d %d, start deinit from %d \n")
    TRC_MSG(CCCI_UT_CCCI_WRITE_ERR, "[CCCI_UT] step %d: loop %d curr_txch return %d LB_COUNT %d##%d retry %d \n")
    TRC_MSG(CCCI_UT_CALLBACK_TRA, "[CCCI_UT] %d **** %x#%x#%x#%x \n")
   //4 <misc_info_msg>

   //4 <it msg> ==================================================
   
   //4 <CCCI Debug>
   TRC_MSG(CCCI_TR_DEBUG_GETSTATUS_START, "[CCCI DEBUG] Get status start \n")
   TRC_MSG(CCCI_TR_DEBUG_GETSTATUS_DONE, "[CCCI DEBUG] Get status done \n")
   TRC_MSG(CCCI_TR_DEBUG_GETSTATUS_WRITE_FAIL, "[CCCI DEBUG ERR] Get status write gpd fail \n")
   TRC_MSG(CCCI_TR_DEBUG_TX_CB, "[CCCI DEBUG] Tx CB:%d \n")
   TRC_MSG(CCCI_TR_DEBUG_RX_CB_START, "[CCCI DEBUG] Rx CB start:%d \n")
   TRC_MSG(CCCI_TR_DEBUG_RX_CB_DONE, "[CCCI DEBUG] Rx CB done:%d \n")
   TRC_MSG(CCCI_TR_DEBUG_RELOAD_GPD_ERR, "[CCCI DEBUG ERR] Can't reload gpd:%d \n")
END_TRACE_MAP(MOD_CCCI)


#endif //#ifndef _CCCI_TRACH_H
