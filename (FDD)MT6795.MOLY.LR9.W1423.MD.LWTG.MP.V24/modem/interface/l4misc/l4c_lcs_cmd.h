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
 *	l4c_lcs_cmd.h
 *
 * Project:
 * --------
 *   MT6268
 *
 * Description:
 * ------------
 *   This file is intends for ...
 *
 * Author:
 * -------
 * -------
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

#ifndef _L4C_LCS_CMD_H
#define _L4C_LCS_CMD_H

//#include "kal_non_specific_general_types.h"
//#include "l4c_aux_struct.h"
#include "kal_general_types.h"
#include "ps_public_struct.h"

extern kal_bool l4c_ss_mtlr_begin_res_req(kal_uint8 src_id,
                                          L4C_SS_LocationNotificationRes *response,
                                          kal_uint8 ss_id);

extern kal_bool l4c_ss_aerq_begin_res_req(kal_uint8 src_id,
                                          kal_uint8 cause,
                                          kal_uint8 ss_id);

extern kal_bool l4c_ss_aerp_begin_req(kal_uint8 src_id,
                                      L4C_SS_LCS_AreaEventReportArg *aerp,
                                      kal_uint8 ss_id,
                                      kal_uint8 is_initial,
                                      kal_uint8 rat_info);

extern kal_bool l4c_ss_aerp_end_req(kal_uint8 src_id,
                                    kal_uint8 cause,
                                    kal_uint8 ss_id);

extern kal_bool l4c_ss_aecl_begin_res_req(kal_uint8 src_id,
                                          kal_uint8 cause,
                                          kal_uint8 ss_id);

extern kal_bool l4c_ss_molr_begin_req(kal_uint8 src_id,
                                      L4C_SS_LCS_MOLRArg *molr,
                                      kal_uint8 ss_id,
                                      kal_uint8 is_initial,
                                      kal_uint8 rat_info);

extern kal_bool l4c_ss_molr_end_req(kal_uint8 src_id, 
                                    kal_uint8 cause,
                                    kal_uint8 ss_id);

extern void l4c_agps_cp_enable_disable_req(kal_uint8 src_id, kal_uint8 enable);

extern void l4c_agps_cp_key_update_req(kal_uint8 src_id, 
                                       kal_uint8 *sib15_current_deciphering_key, 
                                       kal_uint8 *sib15_next_deciphering_key, 
                                       kal_uint8 sib15_ciphering_key_flag);
                                       
extern void l4c_agps_cp_abort_req(kal_uint8 src_id,
                                  kal_uint8 is_abort_molr); //MAUI_02601131

extern void l4c_lbs_message_dispatch(ilm_struct *ilm_ptr); //lbs message

#endif /* _L4C_LCS_CMD_H */ 

