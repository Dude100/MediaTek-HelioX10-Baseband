/******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
*******************************************************************************/

/******************************************************************************
 * Filename:
 * --------------------------------------------------------
 *   mrs_utility.h
 *
 * Project:
 * --------------------------------------------------------
 *   Multimode
 *
 * Description:
 * --------------------------------------------------------
 *   Declaration of funcitons of the utilities in MRS.
 *
 * Author:
 * --------------------------------------------------------
 * -------
 *
 * --------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * 	.
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
 * MRS support MMDC.
 *
 * removed!
 * removed!
 * [MT6290] CSFB Enhancement Implementation for Autonomous Fast Return - add new MRS API.
 *
 * removed!
 * removed!
 * [MT6290] CSFB Enhancement Implementation for Autonomous Fast Return - add SIM index.
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
 * .
 *
 * removed!
 * removed!
 * .
 *
 *****************************************************************************/

#ifndef _MRS_UTILITY_H
#define _MRS_UTILITY_H

#include "mrs_as_enums.h"
#include "mrs_as_struct.h"
#ifdef __ECSFB__
#include "nvram_editor_data_item.h"
#endif /* __ECSFB__*/

/* GLOBAL VARIABLE DECLARATIONS *********************************************/
#ifdef UNIT_TEST
extern kal_bool modis_IT_mode;
#endif

/*  Type Definitions */

/* PUBLIC FUNCTION PROTOTYPES ***********************************************/
extern void mrs_send_msg(kal_uint32 dest_mod_id, sap_type sap_id, msg_type msg_id, local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

#if defined(__CSG_SUPPORT__) || defined(__LTE_RAT__)
extern void NPSI_newAcsglFromUSIM(MRS_SIM_INDEX	sim_index, kal_uint8	acsglRecNum, kal_uint16	acsglSizePerRec
                             , kal_uint8*	acsglData, csg_white_list_update_cause update_cause);

extern void NPSI_newOcsglFromUSIM(MRS_SIM_INDEX	sim_index, kal_uint8	ocsglRecNum, kal_uint16	ocsgalSizePerRec
                             , kal_uint8*   ocsglData, csg_white_list_update_cause update_cause);

extern white_list_update_type NPSI_updateCsgWhiteList(MRS_SIM_INDEX        sim_index, 
                                               MRS_RAT_MODE_TYPE	rat, 
                                               csg_update_type_enum	csg_update_type, 
                                               mrs_plmn_id*	    plmn_id, 
                                               kal_uint32	        csg_id);

extern kal_uint8* NPSI_getEncodedAllowedCsgList(MRS_SIM_INDEX	sim_index, 
                                         kal_uint8*	    recNum, 
                                         kal_uint16 *	sizePerRec);

extern void NPSI_deleteCSGList(MRS_SIM_INDEX sim_index);

extern kal_uint8 NPSI_getValidCsgPlmn(MRS_SIM_INDEX    sim_index, 
                               mrs_plmn_id**	plmns);

extern csg_type_enum NPSI_checkCsgType(MRS_SIM_INDEX	sim_index, 
                                mrs_plmn_id	*plmn_id, 
                                kal_uint32	    csg_id);

kal_bool NPSI_isCsgListEmpty(MRS_SIM_INDEX sim_index);

kal_uint16 NPSI_checkCsgNumberPerPlmn(MRS_SIM_INDEX sim_index, mrs_plmn_id *plmn_id);

extern kal_bool mrs_write_next_csg_record_to_USIM(MRS_SIM_INDEX sim_index);

extern kal_bool mrs_write_csg_to_USIM(MRS_SIM_INDEX sim_index);

#endif /* #if defined(__CSG_SUPPORT__) || defined(__LTE_RAT__) */

extern kal_bool MRS_occupy_lla(MRS_SIM_INDEX	sim_index, 
                               MRS_RAT_MODE_TYPE	rat, 
                               MRS_OCCUPY_PROCEDURE procedure);

extern void MRS_release_lla(MRS_SIM_INDEX	    sim_index, 
                     MRS_RAT_MODE_TYPE	rat);

extern kal_bool MRS_test_occupy_lla(MRS_SIM_INDEX sim_index, 
                                    MRS_OCCUPY_PROCEDURE procedure);

extern MRS_RAT_MODE_TYPE MRS_get_lla_occupy_rat(MRS_SIM_INDEX sim_index);

extern MRS_SIM_INDEX mrs_get_current_sim_index(void);

extern void mrs_afr_reset_afr_list(MRS_SIM_INDEX sim_index);

extern void mrs_afr_insert_freq(MRS_SIM_INDEX sim_index, kal_uint32 earfcn);

extern void mrs_afr_get_afr_list(MRS_SIM_INDEX sim_index, mrs_afr_main_struct *afr_list_ptr);

void mrs_set_csfb_enhancement_status(MRS_SIM_INDEX sim_index, csfb_enhancement_enum enhancement_item, kal_bool activate);

void mrs_set_csfb_enhancement_status_in_test_mode(MRS_SIM_INDEX sim_index, csfb_enhancement_enum enhancement_item, kal_bool activate);

kal_bool mrs_get_csfb_enhancement_status(MRS_SIM_INDEX sim_index, csfb_enhancement_enum enhancement_item);

extern void mrs_afr_set_csfb_status(MRS_SIM_INDEX sim_index, kal_bool csfb_ongoing);

extern kal_bool mrs_afr_get_csfb_status(MRS_SIM_INDEX sim_index);

extern void mrs_set_background_search_status_in_test_mode(MRS_SIM_INDEX sim_index, background_search_enum background_search_type, kal_bool activate);

extern kal_bool mrs_get_background_search_status(MRS_SIM_INDEX sim_index, background_search_enum background_search_type);

#ifdef __ECSFB__
void mrs_ecsfb_add_2g_association(MRS_SIM_INDEX sim_index, kal_uint32 eas_cell_id, mrs_gas_cell_inf_struct *p_gas_cell_inf);

kal_uint8 mrs_ecsfb_get_2g_lai(MRS_SIM_INDEX sim_index, kal_uint32 eas_cell_id, mrs_gas_cell_inf_struct *p_gas_cell_inf);

kal_uint8 mrs_ecsfb_get_same_lai_2g(MRS_SIM_INDEX sim_index, mrs_lai_struct *lai, kal_uint32 valid_duration, mrs_gas_cell_struct *p_gas_cell);

void mrs_ecsfb_reset_association_info(MRS_SIM_INDEX sim_index);
#endif /* __ECSFB__*/
#endif /* _MRS_UTILITY_H */
