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


#ifndef _GAS_EVENT_INFO_TRC_H
#define _GAS_EVENT_INFO_TRC_H


#ifndef GEN_FOR_PC
#include "kal_public_defs.h" //MSBB change    #include "stack_config.h"
#endif /* GEN_FOR_PC */

#include "kal_trace.h"

//#include "event_info_utility.h"

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "gas_event_info_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP_WITH_RANGE(MOD_EVENT_INFO, 101, 600)
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
   TRC_MSG(EVENT_INFO_GROUP1_PS_MTBF, "%Msim_interface_enum, MTBF is supported by NW")
   TRC_MSG(EVENT_INFO_GROUP1_PS_HANDOVER, "%Msim_interface_enum, PS Handover is supported by NW")
   TRC_MSG(EVENT_INFO_GROUP1_PS_RTTI_SUPPORT, "%Msim_interface_enum, 2G R7 RTTI is supported by NW")   
   TRC_MSG(EVENT_INFO_GROUP1_PS_RTTI_ASSIGN, "%Msim_interface_enum, 2G R7 RTTI is triggered by NW")   
   TRC_MSG(EVENT_INFO_GROUP1_PS_FANR_SUPPORT, "%Msim_interface_enum, 2G R7 FANR is triggered by NW")
   TRC_MSG(EVENT_INFO_GROUP1_PS_DLDC_SUPPORT, "%Msim_interface_enum, 2G R7 DLDC is triggered by NW")
   TRC_MSG(EVENT_INFO_GROUP1_PS_RLC_NON_PERSISTENT_MODE_SUPPORT, "%Msim_interface_enum, 2G R7 RLC NON PERSISTENT MODE is triggered by NW")
   TRC_MSG(EVENT_INFO_GROUP1_PS_EGPRS2_SUPPORT, "%Msim_interface_enum, 2G R7 EGPRS2 is triggered by NW")
   TRC_MSG(EVENT_INFO_GROUP1_PS_FLEXIBLE_TN_SUPPORT, "%Msim_interface_enum, 2G R7 Flexible Timeslot is triggered by NW")
   
   /*Level 2 put here*/
   TRC_MSG(EVENT_INFO_GROUP2_CELL_RESELECT, "%Msim_interface_enum, Cell reselection [%d ->%d], Type[%d]")
   TRC_MSG(EVENT_INFO_GROUP2_MEASURE_3G_ALLOW, "%Msim_interface_enum, 3G measurement allow in 2G dedicate")
   TRC_MSG(EVENT_INFO_GROUP2_CELL_SEL_TRIG_BY_RESEL_FAIL, "Cell selection triggered by cell reselection failure")
   TRC_MSG(EVENT_INFO_GROUP2_CELL_SEL_TRIG_BY_REDIRECTION, "Cell selection triggered by IR blind search")

   /*Level 3 put here*/
   TRC_MSG(EVENT_INFO_GROUP3_HANDOVER_ATTEMPT, "%Msim_interface_enum, Handover Attempt [%d ->%d], Type[%d]")
#else
   /*Level 1 put here*/
   TRC_MSG(EVENT_INFO_GROUP1_PS_MTBF, "MTBF is supported by NW")
   TRC_MSG(EVENT_INFO_GROUP1_PS_HANDOVER, "PS Handover is supported by NW")
   TRC_MSG(EVENT_INFO_GROUP1_PS_RTTI_SUPPORT, "2G R7 RTTI is supported by NW")   
   TRC_MSG(EVENT_INFO_GROUP1_PS_RTTI_ASSIGN, "2G R7 RTTI is triggered by NW")   
   TRC_MSG(EVENT_INFO_GROUP1_PS_FANR_SUPPORT, "2G R7 FANR is triggered by NW")
   TRC_MSG(EVENT_INFO_GROUP1_PS_DLDC_SUPPORT, "2G R7 DLDC is triggered by NW")
   TRC_MSG(EVENT_INFO_GROUP1_PS_RLC_NON_PERSISTENT_MODE_SUPPORT, "2G R7 RLC NON PERSISTENT MODE is triggered by NW")
   TRC_MSG(EVENT_INFO_GROUP1_PS_EGPRS2_SUPPORT, "2G R7 EGPRS2 is triggered by NW")
   TRC_MSG(EVENT_INFO_GROUP1_PS_FLEXIBLE_TN_SUPPORT, "2G R7 Flexible Timeslot is triggered by NW")

/*Level 2 put here*/
   TRC_MSG(EVENT_INFO_GROUP2_CELL_RESELECT, "Cell reselection [%d ->%d], Type[%d]")
   TRC_MSG(EVENT_INFO_GROUP2_MEASURE_3G_ALLOW, "3G measurement allow in 2G dedicate")
   TRC_MSG(EVENT_INFO_GROUP2_CELL_SEL_TRIG_BY_RESEL_FAIL, "Cell selection triggered by cell reselection failure")
   TRC_MSG(EVENT_INFO_GROUP2_CELL_SEL_TRIG_BY_REDIRECTION, "Cell selection triggered by IR blind search")
   
   /*Level 3 put here*/
   TRC_MSG(EVENT_INFO_GROUP3_HANDOVER_ATTEMPT, "Handover Attempt [%d ->%d], Type[%d]")
#endif


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
   TRC_MSG(EVENT_INFO_TRACE_WARNING_RLF, "%Msim_interface_enum, Dropped Call")
   TRC_MSG(EVENT_INFO_TRACE_WARNING_HO_FAILURE, "%Msim_interface_enum, Handover to %d failure, cause[%d]")
   TRC_MSG(EVENT_INFO_TRACE_WARNING_EGPRS_OUT_OF_MEMORY, "%Msim_interface_enum, [EGPRS Out of Memory]")
   TRC_MSG(EVENT_INFO_TRACE_WARNING_T3168_TIMEOUT, "%Msim_interface_enum, [T3168 Timeout]")
#else
   TRC_MSG(EVENT_INFO_TRACE_WARNING_RLF, "Dropped Call")
   TRC_MSG(EVENT_INFO_TRACE_WARNING_HO_FAILURE, "Handover to %d failure, cause[%d]")
   TRC_MSG(EVENT_INFO_TRACE_WARNING_EGPRS_OUT_OF_MEMORY, "[EGPRS Out of Memory]")
   TRC_MSG(EVENT_INFO_TRACE_WARNING_T3168_TIMEOUT, "[T3168 Timeout]")
#endif

/***************************** End of Abnormal Event  ****************************/

/***************************************************************************
  *     Part IV : New Feature or Rare Configuration
  *
  * Notes: Use TRACE_FUNC to print New Feature or Rare Configuration Events
  ***************************************************************************/
/***************************** Beging of New Feature or Rare Configuration  ************/

#if defined(__GEMINI__) || defined(__SGLTE__)
   TRC_MSG(EVENT_INFO_TRACE_FUNC_Repeated_ACCH_FOUND , "%Msim_interface_enum, Repeated ACCH found")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_G2U_IR_NACC, "%Msim_interface_enum, [RR]PCCN sending for IR NACC, please infroma GAS owner!!")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_IR_RESEL_CRITERIA3_NOT_SATISFIED, "%Msim_interface_enum, [RR]IR resel criteria 3 not satisfied, please inform GAS owner!!")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_FDD_REP_THR_2, "%Msim_interface_enum, [GAS][R5][MEAS] FDD_REPORTING_THRESHOLD_2 is present")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_IR2G3_REDIRECTION , "%Msim_interface_enum, IR2G3 Redirection found")   

   TRC_MSG(EVENT_INFO_TRACE_FUNC_MAX_OUTPUT_CONTROL , "%Msim_interface_enum, Enhanced control of max output found")   
   TRC_MSG(EVENT_INFO_TRACE_FUNC_SI2N, "%Msim_interface_enum, [GAS][R6][SI] System Inofrmation Type 2N (SI2N) received!!")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_PSCS, "%Msim_interface_enum, [GAS][R6][PSS/PPS] Packet Serving Cell SI (PSCS) received!!")
   
   TRC_MSG(EVENT_INFO_TRACE_FUNC_UTRAN_PRIORITY_RESELECTION, "%Msim_interface_enum, [GAS][R8][UTRAN] Priority cell reselection is used!!")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_EUTRAN_PRIORITY_RESELECTION, "%Msim_interface_enum, [GAS][R8][EUTRAN] Priority cell reselection is used!!")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_UTRAN_CSG, "%Msim_interface_enum, [GAS][R8][UTRAN] Configuration of CSG cells found!!")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_EUTRAN_CSG, "%Msim_interface_enum, [GAS][R8][EUTRAN] Configuration of CSG cells found!!")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_EUTRAN_MEAS_CONTROL, "%Msim_interface_enum, [GAS][R8][EUTRAN] Configuration of meas control parameter found!!")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_FAST_ACQUISITION, "%Msim_interface_enum, [GAS][R8][SI] Fast acquisition is used!!")
 
   TRC_MSG(EVENT_INFO_TRACE_FUNC_UTRAN_CSG_REPORTING, "%Msim_interface_enum, [GAS][R8][UTRAN] Configuration of CSG cells reporting found!!")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_EUTRAN_CSG_REPORTING, "%Msim_interface_enum, [GAS][R8][EUTRAN] Configuration of CSG cells reporting found!!")   
   TRC_MSG(EVENT_INFO_TRACE_FUNC_IR2G4_REDIRECTION , "%Msim_interface_enum, IR2G4 Redirection found")   
   
#else
   TRC_MSG(EVENT_INFO_TRACE_FUNC_Repeated_ACCH_FOUND , "Repeated ACCH found")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_G2U_IR_NACC, "[RR]PCCN sending for IR NACC, please infroma GAS owner!!")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_IR_RESEL_CRITERIA3_NOT_SATISFIED, "[RR]IR resel criteria 3 not satisfied, please inform GAS owner!!")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_FDD_REP_THR_2, "[GAS][R5][MEAS] FDD_REPORTING_THRESHOLD_2 is present")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_IR2G3_REDIRECTION , "IR2G3 Redirection found")   

   TRC_MSG(EVENT_INFO_TRACE_FUNC_MAX_OUTPUT_CONTROL , "Enhanced control of max output found")   
   TRC_MSG(EVENT_INFO_TRACE_FUNC_SI2N, "[GAS][R6][SI] System Inofrmation Type 2N (SI2N) received!!")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_PSCS, "[GAS][R6][PSS/PPS] Packet Serving Cell SI (PSCS) received!!")

   TRC_MSG(EVENT_INFO_TRACE_FUNC_UTRAN_PRIORITY_RESELECTION, "[GAS][R8][UTRAN] Priority cell reselection is used!!")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_EUTRAN_PRIORITY_RESELECTION, "[GAS][R8][EUTRAN] Priority cell reselection is used!!")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_UTRAN_CSG, "[GAS][R8][UTRAN] Configuration of CSG cells found!!")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_EUTRAN_CSG, "[GAS][R8][EUTRAN] Configuration of CSG cells found!!")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_EUTRAN_MEAS_CONTROL, "%Msim_interface_enum, [GAS][R8][EUTRAN] Configuration of meas control parameter found!!")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_FAST_ACQUISITION, "[GAS][R8][SI] Fast acquisition is used!!")

   TRC_MSG(EVENT_INFO_TRACE_FUNC_UTRAN_CSG_REPORTING, "%Msim_interface_enum, [GAS][R8][UTRAN] Configuration of CSG cells reporting found!!")
   TRC_MSG(EVENT_INFO_TRACE_FUNC_EUTRAN_CSG_REPORTING, "%Msim_interface_enum, [GAS][R8][EUTRAN] Configuration of CSG cells reporting found!!")   
   TRC_MSG(EVENT_INFO_TRACE_FUNC_IR2G4_REDIRECTION , "%Msim_interface_enum, IR2G4 Redirection found")   
#endif

/***************************** End of New Feature or Rare Configuration  **************/

/**********************************************************************************************/
/* Part IV : L1 EVENT INFO                                                                    */
/*                                                                                            */
/* Notes   : Use record rare FT event                                                         */
/**********************************************************************************************/
/***************************** Beging of L1 EVENT INFO  ***************************************/


/***************************** End of L1 EVENT INFO  ******************************************/

END_TRACE_MAP_WITH_RANGE(MOD_EVENT_INFO, 101, 600)
#endif

