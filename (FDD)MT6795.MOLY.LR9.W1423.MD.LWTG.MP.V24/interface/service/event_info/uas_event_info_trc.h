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
 *  event_trc.h
 *
 * Project:
 * --------
 *
 *
 * Description:
 * ------------
 *   This is trace map definition.
 *
 * Author:
 * -------
 *
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

[Code Collaborator Link]:
http://mtksap20:8080/go?page=ReviewDisplay&reviewid=29808

[Code Collaborator Link] (CSCE/ADR):
http://mtksap20:8080/go?page=ReviewDisplay&reviewid=29930

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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


#ifndef _UAS_EVENT_INFO_TRC_H
#define _UAS_EVENT_INFO_TRC_H


#ifndef GEN_FOR_PC
#include "kal_public_defs.h" //MSBB change    #include "stack_config.h"
#endif /* GEN_FOR_PC */

#include "kal_trace.h"

//#include "event_info_utility.h"

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "uas_event_info_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP_WITH_RANGE(MOD_EVENT_INFO, 701, 1200)
/***************************************************************************
  *     Part I : Protocol Action
  *
  * Notes: Use TRACE_GROUP_1 ~ 5 to display Protocol Action Events
  *                   TRACE_GROUP_1  ==> Protocol_level_1
  *                   TRACE_GROUP_2  ==> Protocol_level_2
  *                   TRACE_GROUP_3  ==> Protocol_level_3
  *                   TRACE_GROUP_4  ==> Reserved
  *                   TRACE_GROUP_5  ==> Reserved
  ***************************************************************************/
/***************************** Beging of Protocol Action  **************************/
#if defined(__GEMINI__) || defined(__SGLTE__)
   /*Level 1 put here*/
   TRC_MSG(EVENT_INFO_GROUP1_IRCR_TO_UTRAN, "%Msim_interface_enum, Cell reselection to UTRAN")
   TRC_MSG(EVENT_INFO_GROUP1_SRNS_relocation, "%Msim_interface_enum, SRNS relocation")
   TRC_MSG(EVENT_INFO_GROUP1_UMTS_HHO_revert, "%Msim_interface_enum, UMTS HHO revert")
   TRC_MSG(EVENT_INFO_GROUP1_CELL_RESEL_FROM_UTRAN, "%Msim_interface_enum, Cell Reselection From UTRAN")
   TRC_MSG(EVENT_INFO_GROUP1_INTER_FREQ_CELL_RESEL, "%Msim_interface_enum, UMTS Inter-Frequency Cell Reselection")
   TRC_MSG(EVENT_INFO_GROUP1_CELL_RESEL_FAILURE, "%Msim_interface_enum, UMTS Cell Reselection Failure")
   TRC_MSG(EVENT_INFO_GROUP1_PDCP_RFC2507, "%Msim_interface_enum, RFC2507 is supported by NW")

   /*Level 2 put here*/
   TRC_MSG(EVENT_INFO_GROUP2_UMTS_HHO, "%Msim_interface_enum, UMTS HHO")
#ifdef __UMTS_TDD128_MODE__
   TRC_MSG(EVENT_INFO_GROUP2_UMTS_BHO, "%Msim_interface_enum, UMTS BHO")
#endif
   TRC_MSG(EVENT_INFO_GROUP2_SLCE_PS_RATE, "%Msim_interface_enum, [PS_RATE] RAB_ID=%d, RB_ID=%u, ul_trch_id=%u, dl_trch_id=%u, ul_rate=%u, dl_rate=%u")
   TRC_MSG(EVENT_INFO_GROUP2_INTRA_FREQ_CELL_RESEL, "%Msim_interface_enum, UMTS Intra-Frequency Cell Reselection")

   /*Level 3 put here*/
#else
   /*Level 1 put here*/
   TRC_MSG(EVENT_INFO_GROUP1_IRCR_TO_UTRAN, "Cell reselection to UTRAN")
   TRC_MSG(EVENT_INFO_GROUP1_SRNS_relocation,"SRNS relocation")
   TRC_MSG(EVENT_INFO_GROUP1_UMTS_HHO_revert,"UMTS HHO revert")
   TRC_MSG(EVENT_INFO_GROUP1_CELL_RESEL_FROM_UTRAN, "Cell Reselection From UTRAN")
   TRC_MSG(EVENT_INFO_GROUP1_INTER_FREQ_CELL_RESEL,"UMTS Inter-Frequency Cell Reselection")
   TRC_MSG(EVENT_INFO_GROUP1_CELL_RESEL_FAILURE,"UMTS Cell Reselection Failure")
   TRC_MSG(EVENT_INFO_GROUP1_PDCP_RFC2507, "RFC2507 is supported by NW")
   
   /*Level 2 put here*/
   TRC_MSG(EVENT_INFO_GROUP2_UMTS_HHO,"UMTS HHO")
#ifdef __UMTS_TDD128_MODE__
   TRC_MSG(EVENT_INFO_GROUP2_UMTS_BHO,"UMTS BHO")
#endif
   TRC_MSG(EVENT_INFO_GROUP2_SLCE_PS_RATE,"[PS_RATE] RAB_ID=%d, RB_ID=%u, ul_trch_id=%u, dl_trch_id=%u, ul_rate=%u, dl_rate=%u")
   TRC_MSG(EVENT_INFO_GROUP2_INTRA_FREQ_CELL_RESEL,"UMTS Intra-Frequency Cell Reselection")

   /*Level 3 put here*/
#endif //__GEMINI__ || __SGLTE__


/***************************** End of Protocol Action  ****************************/

/***************************************************************************
  *     Part II : User Action
  *
  * Notes: Use TRACE_GROUP_6 ~ 10 to display User Action Events
  *                   TRACE_GROUP_6  ==> User_Action_level_1
  *                   TRACE_GROUP_7  ==> User_Action_level_2
  *                   TRACE_GROUP_8  ==> User_Action_level_3
  *                   TRACE_GROUP_9  ==> Reserved
  *                   TRACE_GROUP_10 ==> Reserved
  ***************************************************************************/
/***************************** Beging of User Action  *****************************/


/***************************** End of User Action  *******************************/

/***************************************************************************
  *     Part III : Abnormal Event
  *
  * Notes: Use TRACE_WARNING to display Abnormal Events
  ***************************************************************************/
/***************************** Beging of Abnormal Event  **************************/

#if defined(__GEMINI__) || defined(__SGLTE__)
   TRC_MSG(EVENT_INFO_TRACE_WARNING_RRCE_ABORT, "%Msim_interface_enum, RRCE ABORT CONFIGURATION")
   TRC_MSG(EVENT_INFO_TRACE_WARNING_TGPS_OVERLAP_XD, "%Msim_interface_enum, TGPS OVERLAP with [%d]")
   TRC_MSG(EVENT_INFO_TRACE_WARNING_OOS_during_SRNS_relocation, "%Msim_interface_enum, OOS during SRNS relocation")
   TRC_MSG(EVENT_INFO_TRACE_WARNING_RLC_unrecoverable_during_SRNS_relocation, "%Msim_interface_enum, RLC unrecoverable during SRNS relocation")
   TRC_MSG(EVENT_INFO_TRACE_WARNING_cell_reselection_during_SRNS_relocation, "%Msim_interface_enum, cell reselection during SRNS relocation")
   TRC_MSG(EVENT_INFO_TRACE_WARNING_Inter_freq_SIB_collection_during_SRNS_relocation, "%Msim_interface_enum, Inter freq SIB collection during SRNS relocation")
   TRC_MSG(EVENT_INFO_TRACE_WARNING_Integrity_Failed, "%Msim_interface_enum, Integrity failed")
#else
   TRC_MSG(EVENT_INFO_TRACE_WARNING_RRCE_ABORT,"RRCE ABORT CONFIGURATION")
   TRC_MSG(EVENT_INFO_TRACE_WARNING_TGPS_OVERLAP_XD,"TGPS OVERLAP with [%d]")
   TRC_MSG(EVENT_INFO_TRACE_WARNING_OOS_during_SRNS_relocation,"OOS during SRNS relocation")
   TRC_MSG(EVENT_INFO_TRACE_WARNING_RLC_unrecoverable_during_SRNS_relocation,"RLC unrecoverable during SRNS relocation")
   TRC_MSG(EVENT_INFO_TRACE_WARNING_cell_reselection_during_SRNS_relocation,"cell reselection during SRNS relocation")
   TRC_MSG(EVENT_INFO_TRACE_WARNING_Inter_freq_SIB_collection_during_SRNS_relocation,"Inter freq SIB collection during SRNS relocation")
   TRC_MSG(EVENT_INFO_TRACE_WARNING_Integrity_Failed,"Integrity failed")
#endif //__GEMINI__ || __SGLTE__

/***************************** End of Abnormal Event  ****************************/

/***************************************************************************
  *     Part IV : New Feature or Rare Configuration
  *
  * Notes: Use TRACE_FUNC to print New Feature or Rare Configuration Events
  ***************************************************************************/
/***************************** Beging of New Feature or Rare Configuration  ************/

#if defined(__GEMINI__) || defined(__SGLTE__)
   TRC_MSG(EVENT_INFO_TRACE_FUNC_TFCC_received , "%Msim_interface_enum, Transport Fortmat Combination Control")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_FAST_DORMANCY, "%Msim_interface_enum, Fast Dormancy is configured in cell(%d/%d), T323 = %MRRC_T_323.") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_START_BCH_TO_COLLECT_SIB, "%Msim_interface_enum, Start BCH to collect SIB on cell(%d/%d).")
#ifdef __UMTS_R5__
   TRC_MSG(EVENT_INFO_TRACE_FUNC_MAC_D_HFN_INITIAL_VALUE_IS_RECEIVED, "%Msim_interface_enum, MAC-d HFN initial value is received")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_ONE_SIDED_RLC_REESTABLISH_IS_CONFIGURED, "%Msim_interface_enum, One sided RLC re-establishment is configured for RB %d")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_PRECONFIGURED_CONNECTION_ESTABLISHMENT, "%Msim_interface_enum, Preconfigured Connection Establishment")   
   TRC_MSG(EVENT_INFO_TRACE_FUNC_RECEIVE_TM_TFCC, "%Msim_interface_enum, TM TFCC is received")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_LOSSLESS_DL_RLC_SIZE_CHANGE, "%Msim_interface_enum, RB ID %d has lossless DL RLC PDU size change from %d to %d.")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_LOSSY_DL_RLC_SIZE_CHANGE, "%Msim_interface_enum, RB ID %d has lossy DL RLC PDU size change from %d to %d.")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_3G2_IRNACC, "%Msim_interface_enum, 3G2 IR NACC") 
#endif

   TRC_MSG(EVENT_INFO_TRACE_FUNC_GROUP_URNTI, "%Msim_interface_enum, Group URNTI")

#ifdef __UMTS_R6__
   TRC_MSG(EVENT_INFO_TRACE_FUNC_DL_COMM_INFO_FDPCH, "%Msim_interface_enum, F-DPCH is configured")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_HS_DPCCH_ACK_NACK_WITH_PREAMBLE_POSTAMBLE, "%Msim_interface_enum, HS-DPCCH ACK/NACK Enhancement with preamble/postamble")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_POST_VERIFICATION_PERIOD_IS_USED, "%Msim_interface_enum, Post verification period is used")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_TMHHO_WITHOUT_SYNC_A, "%Msim_interface_enum, TMHHO without sync A")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_DELAY_RESTRICTION_FLAG_IS_CONFIGURED, "%Msim_interface_enum, Delay restriction flag is configured.")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_3G2_PS_HO, "%Msim_interface_enum, 3G2 IR PS HO")  
   TRC_MSG(EVENT_INFO_TRACE_FUNC_DSAC_IS_CONFIGURED, "%Msim_interface_enum, DSAC is configured.")  
   TRC_MSG(EVENT_INFO_TRACE_FUNC_NETWORK_SHARING_IS_CONFIGURED, "%Msim_interface_enum, Network Sharing is configured.")
#endif
#ifdef __UMTS_R7__
   TRC_MSG(EVENT_INFO_TRACE_FUNC_DEFERRED_SIB11_12_18_19_READING, "%Msim_interface_enum, Deferred SIB11/12/18/19 Reading is configured in cell(%d/%d)") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_PLMN_SELECTION_PING_PONG_CONTROL, "%Msim_interface_enum, PLMN Selection Ping-Pong Control is configured in cell(%d/%d), q_QualMin_Offset = %d, q_RxlevMin_Offset = %d")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_ENHANCED_CELL_FACH_STATE, "%Msim_interface_enum, Enhanced Cell FACH State is configured in cell(%d/%d)") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_ENHANCED_CELL_PCH_STATE, "%Msim_interface_enum, Enhanced Cell PCH State is configured in cell(%d/%d)") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_TWODRX_IS_CONFIGURED, "%Msim_interface_enum, TOW DRX in Cell_PCH/URA_PCH is configured [%d->%d]") 
#endif
#ifdef __UMTS_R8__
   TRC_MSG(EVENT_INFO_TRACE_FUNC_ABSOLUTE_PRIORITY_BASED_CELL_RESELECTION, "%Msim_interface_enum, Absolute Priority Based Cell Re-selection is configured in cell(%d/%d): FDD=%Mkal_bool, TDD=%Mkal_bool, GSM=%Mkal_bool, E-UTRA=%Mkal_bool") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_HOME_NODE_B_NAME, "%Msim_interface_enum, Home Node-B Name is configured in cell(%d/%d)") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_CSG_ID, "%Msim_interface_enum, CSG ID is configured in SIB3 of cell(%d/%d)") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_CSG_IND, "%Msim_interface_enum, CSG Indicator is configured in MIB of cell(%d/%d)") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_PPACR, "%Msim_interface_enum, Paging Permission with Access Control is configured in cell(%d/%d)")    
   TRC_MSG(EVENT_INFO_TRACE_FUNC_HS_DSCH_DRX_IN_CELL_FACH, "%Msim_interface_enum, HS-DSCH DRX in CELL_FACH is configured in cell(%d/%d)")    
   TRC_MSG(EVENT_INFO_TRACE_FUNC_COMMON_E_DCH, "%Msim_interface_enum, Common E-DCH is configured in cell(%d/%d)") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_MULTIPLE_PLMN_IN_SIB18, "%Msim_interface_enum, Multiple PLMN in SIB18 is configured in cell(%d/%d)")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_PPACR_IS_CONFIGURED, "%Msim_interface_enum, PPACR is configured.") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_APBCR_3G3_INTER_FREQ_RESELECTION, "%Msim_interface_enum, [APBCR] 3G3 inter freq cell reselection in %MRRC_DB_RRC_StateType")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_APBCR_3G2_INTER_RAT_RESELECTION, "%Msim_interface_enum, [APBCR] 3G2 inter rat cell reselection in %MRRC_DB_RRC_StateType")
#endif
#ifdef __LTE_RAT__
   TRC_MSG(EVENT_INFO_TRACE_FUNC_APBCR_3G4_INTER_RAT_RESELECTION, "%Msim_interface_enum, [APBCR] 3G4 inter rat cell reselection in %MRRC_DB_RRC_StateType")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_3G4_CSG_AUTO_RESELECTION, "%Msim_interface_enum, [CSG] 3G4 CSG AUTO cell reselection in %MRRC_DB_RRC_StateType")
#endif
#else
   TRC_MSG(EVENT_INFO_TRACE_FUNC_TFCC_received , "Transport Fortmat Combination Control")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_FAST_DORMANCY, "Fast Dormancy is configured in cell(%d/%d), T323 = %MRRC_T_323.")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_START_BCH_TO_COLLECT_SIB, "Start BCH to collect SIB on cell(%d/%d).")
#ifdef __UMTS_R5__
   TRC_MSG(EVENT_INFO_TRACE_FUNC_MAC_D_HFN_INITIAL_VALUE_IS_RECEIVED, "MAC-d HFN initial value is received")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_ONE_SIDED_RLC_REESTABLISH_IS_CONFIGURED, "One sided RLC re-establishment is configured for RB %d")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_PRECONFIGURED_CONNECTION_ESTABLISHMENT,"Preconfigured Connection Establishment")   
   TRC_MSG(EVENT_INFO_TRACE_FUNC_RECEIVE_TM_TFCC, "TM TFCC is received")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_LOSSLESS_DL_RLC_SIZE_CHANGE, "RB ID %d has lossless DL RLC PDU size change from %d to %d.")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_LOSSY_DL_RLC_SIZE_CHANGE, "RB ID %d has lossy DL RLC PDU size change from %d to %d.")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_3G2_IRNACC, "3G2 IR NACC") 
#endif

   TRC_MSG(EVENT_INFO_TRACE_FUNC_GROUP_URNTI,"Group URNTI")

#ifdef __UMTS_R6__
   TRC_MSG(EVENT_INFO_TRACE_FUNC_DL_COMM_INFO_FDPCH, "F-DPCH is configured")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_HS_DPCCH_ACK_NACK_WITH_PREAMBLE_POSTAMBLE, "HS-DPCCH ACK/NACK Enhancement with preamble/postamble")   
   TRC_MSG(EVENT_INFO_TRACE_FUNC_POST_VERIFICATION_PERIOD_IS_USED, "Post verification period is used")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_TMHHO_WITHOUT_SYNC_A, "TMHHO without sync A")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_DELAY_RESTRICTION_FLAG_IS_CONFIGURED, "Delay restriction flag is configured.")   
   TRC_MSG(EVENT_INFO_TRACE_FUNC_3G2_PS_HO, "3G2 IR PS HO")  
   TRC_MSG(EVENT_INFO_TRACE_FUNC_DSAC_IS_CONFIGURED, "DSAC is configured.") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_NETWORK_SHARING_IS_CONFIGURED, "Network Sharing is configured.")
#endif
#ifdef __UMTS_R7__
   TRC_MSG(EVENT_INFO_TRACE_FUNC_DEFERRED_SIB11_12_18_19_READING, "Deferred SIB11/12/18/19 Reading is configured in cell(%d/%d)") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_PLMN_SELECTION_PING_PONG_CONTROL, "PLMN Selection Ping-Pong Control is configured in cell(%d/%d), q_QualMin_Offset = %d, q_RxlevMin_Offset = %d")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_ENHANCED_CELL_FACH_STATE, "Enhanced Cell FACH State is configured in cell(%d/%d)") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_ENHANCED_CELL_PCH_STATE, "Enhanced Cell PCH State is configured in cell(%d/%d)") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_TWODRX_IS_CONFIGURED, "TOW DRX in Cell_PCH/URA_PCH is configured [%d->%d]") 
#endif
#ifdef __UMTS_R8__
   TRC_MSG(EVENT_INFO_TRACE_FUNC_ABSOLUTE_PRIORITY_BASED_CELL_RESELECTION, "Absolute Priority Based Cell Re-selection is configured in cell(%d/%d): FDD=%Mkal_bool, TDD=%Mkal_bool, GSM=%Mkal_bool, E-UTRA=%Mkal_bool") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_HOME_NODE_B_NAME, "Home Node-B Name is configured in cell(%d/%d)") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_CSG_ID, "CSG ID is configured in SIB3 of cell(%d/%d)") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_CSG_IND, "CSG Indicator is configured in MIB of cell(%d/%d)") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_PPACR, "Paging Permission with Access Control is configured in cell(%d/%d)")    
   TRC_MSG(EVENT_INFO_TRACE_FUNC_HS_DSCH_DRX_IN_CELL_FACH, "HS-DSCH DRX in CELL_FACH is configured in cell(%d/%d)")    
   TRC_MSG(EVENT_INFO_TRACE_FUNC_COMMON_E_DCH, "Common E-DCH is configured in cell(%d/%d)") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_MULTIPLE_PLMN_IN_SIB18, "Multiple PLMN in SIB18 is configured in cell(%d/%d)")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_PPACR_IS_CONFIGURED, "PPACR is configured.") 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_APBCR_3G3_INTER_FREQ_RESELECTION, "[APBCR] 3G3 inter freq cell reselection in %MRRC_DB_RRC_StateType")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_APBCR_3G2_INTER_RAT_RESELECTION, "[APBCR] 3G2 inter rat cell reselection in %MRRC_DB_RRC_StateType")
#endif
#ifdef __LTE_RAT__
   TRC_MSG(EVENT_INFO_TRACE_FUNC_APBCR_3G4_INTER_RAT_RESELECTION, "%Msim_interface_enum, [APBCR] 3G4 inter rat cell reselection in %MRRC_DB_RRC_StateType")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_3G4_CSG_AUTO_RESELECTION, "%Msim_interface_enum, [CSG] 3G4 CSG AUTO cell reselection in %MRRC_DB_RRC_StateType")
#endif
#endif //__GEMINI__ || __SGLTE__

/***************************** End of New Feature or Rare Configuration  **************/

/**********************************************************************************************/
/* Part IV : L1 EVENT INFO                                                                    */
/*                                                                                            */
/* Notes   : Use record rare FT event                                                         */
/**********************************************************************************************/
/***************************** Beging of L1 EVENT INFO  ***************************************/


/***************************** End of L1 EVENT INFO  ******************************************/

END_TRACE_MAP_WITH_RANGE(MOD_EVENT_INFO, 701, 1200)
#endif

