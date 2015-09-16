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
 *   el2_msgid.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 *   
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * Leave DRX for DCCH UL data (OA domain) on MP6.
 *
 * removed!
 * removed!
 * Merge codes related to L2 copro delay power off back to MOLY TRUNK in OA domain
 *
 * removed!
 * removed!
 * Add HOST_DATA_READY_IND
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
 * TA_INFO and NBR_CELL_INFO interfaces for LPP feature
 *
 * removed!
 * removed!
 * add el2 message for ERT task to ERT HISR.
 *
 * removed!
 * removed!
 * add IDC-related interface
 *
 * removed!
 * removed!
 * add MSG_ID_ERLCUL_EPDCP_SRB_DATA_CNF.
 ****************************************************************************/
#include "module_msg_range.h"

#ifndef _EL2_MSGID_H
#define _EL2_MSGID_H


MODULE_MSG_BEGIN( MSG_ID_EL2_CODE_BEGIN )	
	
	/*------------------- EL2_MSG_CODE_BEGIN---------------------*/

	//////////////////////////////////////////////
	// Destination: EPDCP                       //
	//////////////////////////////////////////////

	// ERRC --> EPDCP
	MSG_ID_ERRC_EPDCP_CONFIG_REQ = MSG_ID_EL2_CODE_BEGIN,
 	MSG_ID_ERRC_EPDCP_DCCH_DATA_REQ,
 	MSG_ID_ERRC_EPDCP_DCCH_DATA_RES,
	MSG_ID_ERRC_EPDCP_TEST_REQ,
	MSG_ID_ERRC_EPDCP_CNTINFO_REQ,

	// ERLC-UL --> EPDCP
	MSG_ID_ERLCUL_EPDCP_SRB_DATA_CNF,

	// EPDCP --> EPDCP
	MSG_ID_EPDCP_EPDCP_CTRL_PDU_IND,
	MSG_ID_EPDCP_EPDCP_DL_FLUSH_DONE_IND,
	
	// EMAC --> EPDCP	
	MSG_ID_EMAC_EPDCP_TDM_START_IND,
	MSG_ID_EMAC_EPDCP_TDM_END_IND,

	// EL1 --> EPDCP
	MSG_ID_EL1_EL2_PWR_DOWN_L2COPRO_IND,
	MSG_ID_EL1_EL2_WAKEUP_L2COPRO_IND,

	//////////////////////////////////////////////
	// Destination: ERLC-UL                     //
	//////////////////////////////////////////////

	// ERRC --> ERLC-UL
	MSG_ID_ERRC_ERLCUL_CONFIG_REQ,
	MSG_ID_ERRC_ERLCUL_SRB1_ACK_REQ,
	MSG_ID_ERRC_ERLCUL_END,

	// ETMR --> ERLC-UL
	MSG_ID_ETMR_ERLCUL_POLL_RETX_EXPRY,

	// EPDCP --> ERLC-UL
	MSG_ID_EPDCP_ERLCUL_DISCARD_REQ,

	// ERLCDL --> ERLC-UL
	MSG_ID_ERLCDL_ERLCUL_STATUS_PDU_RCV,

	// EMAC --> ERLC-UL
	MSG_ID_EMAC_ERLCUL_STATUS_IND,
	MSG_ID_EMAC_ERLCUL_ALL_HARQ_CLOSED_IND,
	MSG_ID_EMAC_ERLCUL_TDM_START_IND,
	MSG_ID_EMAC_ERLCUL_TDM_END_IND,


	//////////////////////////////////////////////
	// Destination: ERLC-DL                     //
	//////////////////////////////////////////////

	// ERRC --> ERLC-DL
	MSG_ID_ERRC_ERLCDL_CONFIG_REQ,

	// ETMR --> ERLC-DL
	MSG_ID_ETMR_ERLCDL_REORDER_EXPRY,

	// EPDCP --> ERLC-DL
	MSG_ID_EPDCP_ERLCDL_REASM_MODE_CHNG,
	MSG_ID_EPDCP_ERLCDL_NEXT_SRB1_REQ,

	// EMAC --> ERLC-DL
	MSG_ID_EMAC_ERLCDL_DATA_IND,


	//////////////////////////////////////////////
	// Destination: EMAC                        //
	//////////////////////////////////////////////

	MSG_ID_ERRC_EMAC_CONFIG_REQ,
	MSG_ID_ERRC_EMAC_CCCH_DATA_REQ,
	MSG_ID_ERRC_EMAC_TA_INFO_REQ,

    /// EPDCP --> EMAC
    MSG_ID_EPDCP_EMAC_LEAVE_DRX,
	
    /// ERLC --> EMAC
	MSG_ID_ERLCUL_EMAC_DATA_REQ,
	MSG_ID_ERLCUL_EMAC_FORCE_HARQ_CLOSE_REQ,
	MSG_ID_LTM_EMAC_LEAVE_DRX,

	// EMAC --> EMAC
	MSG_ID_EMAC_EMAC_RAR_INT,
	MSG_ID_EMAC_EMAC_EARLY_INT,

	// EMAC_UT --> EMAC
	MSG_ID_EMAC_UT_EMAC_TEST_CMD,

	// EL1 --> EMAC
	MSG_ID_EMAC_EL1_PHY_INFO_IND,
	MSG_ID_EMAC_EL1_RA_GAP_STOP_CNF,
	MSG_ID_EMAC_EL1_RA_GAP_RESUME_CNF,
	MSG_ID_EMAC_EL1_RNTI_UPDATE_CNF,
	MSG_ID_EMAC_EL1_DRX_CTRL_CNF,
	MSG_ID_EMAC_EL1_HOST_DATA_CNF,
	MSG_ID_EMAC_EL1_HOST_DATA_READY_IND,
	MSG_ID_EMAC_EL1_RA_RESTART_IND,
	MSG_ID_EMAC_EL1_IDC_TDM_IND,

	// EL1TX --> EMAC
	MSG_ID_EMAC_EL1TX_PDCCH_IND,
	MSG_ID_EMAC_EL1TX_RETX_INFO_IND,
	MSG_ID_EMAC_EL1TX_PHR_IND,
	MSG_ID_EMAC_EL1TX_SR_TX_ABORT_IND,

	// HISR --> EMAC
	MSG_ID_EMAC_DL_CTRL_DATA_IND,
	MSG_ID_EMAC_DL_CCCH_DATA_IND,

	//////////////////////////////////////////////
	// Destination: EL2                         //
	//////////////////////////////////////////////

    MSG_ID_ERLCUL_EL2_HWB_REL_END_IND,

	//////////////////////////////////////////////
	// Destination: LTM                         //
	//////////////////////////////////////////////

	// EPDCP --> LTM
	MSG_ID_LTM_EPDCP_UL_DATA_REDIR_IND,
	MSG_ID_LTM_EPDCP_DATA_IND,

	// EMAC --> LTM
	MSG_ID_LTM_EMAC_NEXT_DRX_IND,

	MSG_ID_LTM_EPDCP_DATA_REQ,
	/*------------------- EL2_MSG_CODE_END-----------------------*/

MODULE_MSG_END( MSG_ID_EL2_CODE_TAIL )

#endif /* _EL2_MSGID_H */
