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
 *   el1_msgid.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   LTE Layer 1 and Protocol Stack related message identity definition
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
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * IDC msg : pin type lte con, and lte con timer
 *
 * removed!
 * removed!
 * add sap.
 *
 * removed!
 * removed!
 * specific measurement el1 sap
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Add a 1s guard timer for cphy_cfg_req/cnf.
 *
 * 11 13 2013 ty.shen
 * removed!
 * .
 *
 * removed!
 * removed!
 * add csi_srs_admission_2nd_ntf for EMAC
 *
 * removed!
 * removed!
 * 	(Revise IPC messages).
 *
 * removed!
 * removed!
 * Add new SW message ID
 *
 * 10 29 2013 ms.lin
 * removed!
 *  .
 *
 * removed!
 * removed!
 * .
 *
 * 10 11 2013 ms.lin
 * removed!
 *  .
 *
 * removed!
 * removed!
 * HOST_DATA_REQ is rcv by CH
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * (add new msgid).
 *
 * removed!
 * removed!
 * add timer expiry msg for sch.
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * <saved by Perforce>
 * Re-arrange the MSG ID for sleep mode related messages.
 *
 * 03 04 2013 ms.lin
 * removed!
 * .
 *
 * 01 28 2013 ms.lin
 * removed!
 * .
 *
 * 11 08 2012 ms.lin
 * removed!
 * .
 ****************************************************************************/
#include "module_msg_range.h"

#ifndef _EL1_MSGID_H
#define _EL1_MSGID_H


MODULE_MSG_BEGIN( MSG_ID_EL1_CODE_BEGIN )

/****************************************************************************
 *                          Destination: CH
 ****************************************************************************/
MSG_ID_ERRC_EL1_CPHY_CFG_REQ                = MSG_ID_EL1_CODE_BEGIN,
MSG_ID_EL1_CH_MSG_START                     = MSG_ID_ERRC_EL1_CPHY_CFG_REQ,
MSG_ID_ERRC_EL1_RL_MONITOR_REQ,
MSG_ID_ERRC_EL1_SPECIFIC_CELL_SEARCH_REQ,
MSG_ID_ERRC_EL1_PCH_RCV_NTF,
MSG_ID_ERRC_EL1_ABORT_HO_NTF,
MSG_ID_EMAC_EL1_RA_GAP_STOP_REQ,
MSG_ID_EMAC_EL1_RA_GAP_RESUME_REQ,
MSG_ID_EMAC_EL1_RNTI_UPDATE_REQ,
MSG_ID_EMAC_EL1_DRX_CTRL_REQ,
MSG_ID_EMAC_EL1_DRX_SLEEP_NTF,
MSG_ID_EMAC_EL1_DRX_CYCLE_NTF,
MSG_ID_EMAC_EL1_HOST_DATA_REQ,
MSG_ID_ETMR_EL1_RS_EXTEND_END,
MSG_ID_ETMR_EL1_CH_TIMER_EXPIRY,
MSG_ID_ETMR_EL1_CPHY_CFG_TMR_EXPIRY,
MSG_ID_GAS_EL1_ENABLE_B39_REQ,
MSG_ID_GAS_EL1_DISABLE_B39_REQ,
/* Internal message */
MSG_ID_EL1_IRT_CH_PARAM_CHG_CNF,
MSG_ID_EL1_IRT_CH_GAP_SUSP_CNF,
MSG_ID_EL1_IRT_CH_BCCH_CNF,
MSG_ID_EL1_IRT_CH_AUTO_GAP_STOP_REQ,
MSG_ID_EL1_IRT_CH_AUTO_GAP_AVAIL_IND,
MSG_ID_EL1_PHS_CH_CTRL_CNF,
MSG_ID_EL1_PHS_CH_CONFLICT_IND,
MSG_ID_EL1_PHS_CH_REL_ALL_IND,
MSG_ID_EL1_DRV_CH_CTRL_CNF,
MSG_ID_EL1_DRV_CH_DL_SYNC_RPT,
MSG_ID_EL1_DRV_CH_MIB_RPT,
MSG_ID_EL1_DRV_CH_DL_BC_ASSIGN_RLT,
MSG_ID_EL1_DRV_CH_CELL_DETECT_RPT,
MSG_ID_EL1_DRV_CH_STATIC_MEAS_RPT,
MSG_ID_EL1_DRV_CH_CELL_TBL_GET_RPT,
MSG_ID_EL1_MEAS_CH_MEAS_MODE_CHNG_REQ,
MSG_ID_EL1_MEAS_CH_MEAS_MODE_SWITCH_CNF,

MSG_ID_ERRC_EL1_RX_POLL_DATA_IND,
/****************************************************************************
 *                          Destination: PHS
 ****************************************************************************/
/* Internal message */
MSG_ID_ERRC_EL1_CHANNEL_PROTECT_START_REQ,
MSG_ID_EL1_PHS_MSG_START                = MSG_ID_ERRC_EL1_CHANNEL_PROTECT_START_REQ,
MSG_ID_ERRC_EL1_CHANNEL_PROTECT_STOP_REQ,
MSG_ID_AP_MD_LTE_AUTO_GAP_REQ,
MSG_ID_EMAC_EL1_LAST_PDCCH_MONITOR_NTF,
/* Internal message */
MSG_ID_EL1_IRT_PHS_RAT_CHG_REQ,
MSG_ID_EL1_CH_PHS_CTRL_REQ,
MSG_ID_EL1_CH_PHS_DRX_CTRL_REQ,
MSG_ID_EL1_CH_PHS_DRX_CYCLE_IND,
MSG_ID_EL1_CH_PHS_DRX_SLEEP_IND,
MSG_ID_EL1_CSR_PHS_CTRL_REQ,
MSG_ID_EL1_MEAS_PHS_CTRL_REQ,
MSG_ID_EL1_MEAS_PHS_PRS_CTRL_REQ,
MSG_ID_EL1_PHS_PHS_ABORT_IND,
MSG_ID_EL1_PHS_PHS_CTRL_RSP,
MSG_ID_EL1_DRV_PHS_CTRL_CNF,
MSG_ID_EL1_DRV_PHS_DSP_CTRL_RSP,
MSG_ID_EL1_DRV_PHS_RAT_CHNG_RPT,
MSG_ID_EL1_IRT_PHS_MEAS_GAP_REQ,
MSG_ID_EL1_IRT_PHS_GAP_CANCEL_CNF,
MSG_ID_EL1_IRT_PHS_GAP_CTRL_REQ,
MSG_ID_EL1_IRT_PHS_GAP_CANCEL_REQ,
MSG_ID_EL1_IRT_PHS_GAP_RESUME_IND,
MSG_ID_EL1_IRT_PHS_AUTO_GAP_IND,
MSG_ID_EL1_IRT_PHS_AUTO_GAP_END_IND,
MSG_ID_EL1_IRT_PHS_GAP_SUSPEND_CNF,
MSG_ID_EL1_MEAS_PHS_IRT_CTRL_REQ,
MSG_ID_EL1_TX_PHS_TAS_IND,

/****************************************************************************
 *                          Destination: IRT
 ****************************************************************************/
MSG_ID_ERRC_EL1_SET_RAT_REQ,
MSG_ID_EL1_IRT_MSG_START                = MSG_ID_ERRC_EL1_SET_RAT_REQ,
MSG_ID_ERRC_EL1_AUTO_GAP_ON_REQ,
MSG_ID_ERRC_EL1_AUTO_GAP_OFF_REQ,
MSG_ID_ERRC_EL1_LOCK_SLEEP_NTF,
/* Internal message */
MSG_ID_EL1_CSR_IRT_GAP_REQ,
MSG_ID_EL1_PHS_IRT_RAT_CHG_CNF,
MSG_ID_EL1_CH_IRT_PARAM_CHG_REQ,
MSG_ID_EL1_CH_IRT_RECONFIG_DONE_IND,
MSG_ID_EL1_CH_IRT_GAP_SUSP_REQ,
MSG_ID_EL1_CH_IRT_GAP_RESUME_IND,
MSG_ID_EL1_CH_IRT_BCCH_REQ,
MSG_ID_EL1_CH_IRT_AUTO_GAP_STOP_CNF,
MSG_ID_EL1_MEAS_IRT_MEASURE_REQ,
MSG_ID_EL1_MEAS_IRT_MEASURE_DONE_IND,
MSG_ID_EL1_MEAS_IRT_GAP_SUSP_REQ,
MSG_ID_EL1_MEAS_IRT_GAP_RESUME_IND,
MSG_ID_EL1_PHS_IRT_DRX_TICK_IND,
MSG_ID_EL1_PHS_IRT_GAP_PERIOD_IND,
MSG_ID_EL1_PHS_IRT_GAP_CANCEL_REQ,
MSG_ID_EL1_PHS_IRT_GAP_CTRL_CNF,
MSG_ID_EL1_PHS_IRT_GAP_CANCEL_CNF,
MSG_ID_EL1_PHS_IRT_AUTO_GAP_RES,
MSG_ID_EL1_PHS_IRT_GAP_SUSPEND_REQ,
MSG_ID_EL1_PHS_IRT_GAP_RESUME_IND,

/* LL1 -> EL1 */

/****************************************************************************
 *                          Destination: MEAS
 ****************************************************************************/
MSG_ID_ERRC_EL1_RADIO_MEASURE_REQ,
MSG_ID_EL1_MEAS_MSG_START               = MSG_ID_ERRC_EL1_RADIO_MEASURE_REQ,
MSG_ID_ERRC_EL1_SPECIFIC_MEASURE_REQ,
MSG_ID_ERRC_EL1_HPS_QUALIFY_CELL_NTF,
MSG_ID_ERRC_EL1_OOS_TRIG_SEARCH_NTF,
MSG_ID_ETMR_EL1_SRV_TMR_EXPIRY,
MSG_ID_ETMR_EL1_LIFE_TMR_EXPIRY,
MSG_ID_LPP_EL1_OTDOA_MEAS_REQ,
MSG_ID_LPP_EL1_OTDOA_ASSIST_DATA_REQ,
MSG_ID_LPP_EL1_OTDOA_MEAS_ABORT_REQ,
MSG_ID_LPP_EL1_OTDOA_RESET_UE_STORED_POS_INFO,

/* Internal message */
MSG_ID_EL1_IRT_MEAS_GAP_CFG_IND,
MSG_ID_EL1_IRT_MEAS_MEAS_GAP_REQ,
MSG_ID_EL1_IRT_MEAS_BASE_TIME_IND,
MSG_ID_EL1_IRT_MEAS_MODE_CHNG_NTF,
MSG_ID_EL1_IRT_MEAS_GAP_SUSP_CNF,
MSG_ID_EL1_PHS_MEAS_SCHDL_IND,
MSG_ID_EL1_PHS_MEAS_CTRL_CNF,
MSG_ID_EL1_PHS_MEAS_CONFLICT_IND,
MSG_ID_EL1_PHS_MEAS_PRS_CTRL_CNF,
MSG_ID_EL1_CH_MEAS_RL_PROBLEM_NTF,
MSG_ID_EL1_CH_MEAS_RL_RECOVER_NTF,
MSG_ID_EL1_DRV_MEAS_STATIC_MEAS_RPT,
MSG_ID_EL1_DRV_MEAS_PRESCH_RPT,
MSG_ID_EL1_DRV_MEAS_CELL_SEARCH_RPT,
MSG_ID_EL1_DRV_MEAS_PRS_MEAS_RPT,
MSG_ID_EL1_DRV_MEAS_CTRL_CNF,
MSG_ID_EL1_DRV_MEAS_CELL_TBL_GET_RPT,//To be removed
MSG_ID_EL1_DRV_MEAS_SRV_INFO_GET_RPT,
MSG_ID_EL1_DRV_MEAS_PCTI_CTRL_CNF,
MSG_ID_EL1_CH_MEAS_MEAS_MODE_SWITCH_REQ,
MSG_ID_EL1_CH_MEAS_MEAS_MODE_CHNG_CNF,

/****************************************************************************
 *                          Destination: CSR
 ****************************************************************************/
MSG_ID_ERRC_EL1_CARRIER_SEARCH_REQ,
MSG_ID_EL1_CSR_MSG_START                = MSG_ID_ERRC_EL1_CARRIER_SEARCH_REQ,
MSG_ID_ERRC_EL1_RSSI_SNIFFER_REQ,
/* Internal message */
MSG_ID_EL1_PHS_CSR_CTRL_CNF,
MSG_ID_EL1_PHS_CSR_CONFLICT_IND,
MSG_ID_EL1_DRV_CSR_CTRL_CNF,
MSG_ID_EL1_DRV_CSR_CSR_RPT,
MSG_ID_EL1_DRV_CSR_PWR_SCN_RPT,

/****************************************************************************
 *                          Destination: SM
 ****************************************************************************/
MSG_ID_EL1_DRV_SM_FWS_TIME_ERR_RPT,
MSG_ID_EL1_SM_MSG_START                 = MSG_ID_EL1_DRV_SM_FWS_TIME_ERR_RPT,
MSG_ID_EL1_DRV_SM_RECAL_NTF,
MSG_ID_EL1_DRV_SM_SLP_TIME_RPT,
MSG_ID_EL1_EL2_WAKEUP_L2COPRO_RES,
MSG_ID_EL1_MSG_END,                     //END of EL1 Messages

/****************************************************************************
 *                          Destination: TX
 ****************************************************************************/
MSG_ID_EL1_IRT_TX_AUTO_GAP_IND,
MSG_ID_EL1_TX_MSG_START                 = MSG_ID_EL1_IRT_TX_AUTO_GAP_IND,
MSG_ID_EL1_CH_TX_INFO_IND,
MSG_ID_EL1_CH_TX_GAP_INFO_IND,
MSG_ID_EL1_CH_TX_CRNTI_UPDATE_IND,
MSG_ID_EL1_CH_TX_SCH_CLOSE_IND,
MSG_ID_EL1_MEAS_TX_PATHLOSS_IND,
MSG_ID_EL1_PHS_TX_SUSPEND_IND,
MSG_ID_EL1_DRV_TX_DL_UL_INFO,
MSG_ID_EL1_IDC_TX_MAX_PWR_IND,
MSG_ID_EL1_TX_TX_CFG_IND,

/****************************************************************************
 *                          EMAC -> EL1-TX
 ****************************************************************************/
MSG_ID_EMAC_EL1TX_TX_REQ,
MSG_ID_EMAC_EL1TX_2ND_TX_REQ,
MSG_ID_EMAC_EL1TX_CR_RESULT_NTF,
MSG_ID_EMAC_EL1TX_SPS_REL_REQ,
MSG_ID_EMAC_EL1TX_PRACH_INFO_NTF,
MSG_ID_EMAC_EL1TX_RAR_MATCH_NTF,
MSG_ID_EMAC_EL1TX_TX_TIMING_ADJ_REQ,
MSG_ID_EMAC_EL1TX_TA_TIMER_EXPRY_NTF,
MSG_ID_EMAC_EL1TX_DL_HARQ_BUF_REL_REQ,
MSG_ID_EMAC_EL1TX_DL_SPS_RX_REQ,
MSG_ID_EMAC_EL1TX_CSI_SRS_ADMISSION_2ND_NTF,

/****************************************************************************
 *                          Destination: EL1_IT
 ****************************************************************************/
MSG_ID_ETMR_XL1_GAP_TMR,

/****************************************************************************
 *                          Destination: IDC
 ****************************************************************************/
MSG_ID_EL1_IDC_MSG_START,
MSG_ID_ETMR_EL1_TDM_TMR_EXPIRY,
MSG_ID_ETMR_EL1_LTE_CON_STATUS_TMR_EXPIRY,
MSG_ID_EL1_IDC_MSG_END,

/****************************************************************************
 *                         Tool <-> EL1-DRV
 ****************************************************************************/
MSG_ID_EL1_DRV_DSP_LOG_FILTER,
MSG_ID_EL1_DRV_DSP_LOG_FILTER_CNF,

/****************************************************************************/

MODULE_MSG_END( MSG_ID_EL1_CODE_TAIL )

#endif /* _EL1_MSGID_H */
