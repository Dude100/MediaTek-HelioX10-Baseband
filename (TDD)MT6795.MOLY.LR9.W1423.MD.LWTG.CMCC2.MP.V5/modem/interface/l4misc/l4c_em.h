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
 *   l4c_em.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Engineer mode header file.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
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
 *
 * removed!
 * removed!
 * removed!
 *
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

#ifndef _L4C_EM_H
#define _L4C_EM_H

#include "em_struct.h"
//#include "kal_non_specific_general_types.h"
//#include "app_ltlcom.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"

#include "kal_general_types.h"
#include "ps_public_struct.h"

extern em_source_enum g_em_cmd_src;

/* L4C call-back functions for MMI */
void l4a_em_update_req (kal_uint8 src_id,kal_uint8 *info_request);
void l4c_em_update_req(em_source_enum em_src,  kal_uint8 *info_request);
void l4c_vt_em_get_config_req(kal_uint8 src_id);
void l4c_vt_em_set_config_req(kal_uint8 src_id, vt_em_config_struct *em_config);
void l4c_em_cell_resel_suspend_req(kal_uint8 src_id, kal_uint8 status);
void l4c_em_cell_resel_resume_req(kal_uint8 src_id);
void l4c_em_get_cell_lock_req(kal_uint8 src_id);
void l4c_em_set_cell_lock_req(
        kal_uint8 src_id,
        kal_bool turn_on_or_off,
        kal_bool band_indicator,
        kal_uint16 lock_arfcn);
extern void l4c_em_common_set_cell_lock_req(kal_uint8 src_id, kal_uint32 enabled_bitmap, kal_bool band_indicator, kal_uint16 *lock_arfcn, kal_uint32 mode);
extern void l4c_em_ext_get_cell_lock_req(kal_uint8 src_id);
extern void l4c_em_ext_set_cell_lock_req(kal_uint8 src_id, kal_uint32 enabled_bitmap, kal_bool band_indicator, kal_uint16 *lock_arfcn);
void l4c_em_feature_command_req(kal_uint8 src_id, kal_uint8 em_feature, kal_uint8 em_feature_state);

/* EM main message handler */
void l4c_em_handler(ilm_struct *ilm_ptr);
kal_bool l4c_em_nw_event_notify_req(kal_uint8 src_id, kal_bool is_on, kal_uint8 num_of_mod, module_type *mod_list);
#if defined(__NONE_USED_L4MMI_MESSAGE__)
void l4c_em_set_cell_id_lock_req(kal_uint8 src_id, kal_uint8 num_of_nc_lai, rr_em_lai_info_struct *nc_lai);
#endif

void l4c_em_quick_test_report_res_req(kal_bool result, kal_uint8 test_count, kal_uint8 *test_list);

extern kal_bool l4c_l1_max_tx_pwr_red_req(kal_uint8 src_id,
                                            kal_uint8 op,
                                            kal_bool gsm_tbl_valid,
                                            kal_uint8 ***gsm_tx_pwr_reduction_tbl,
                                            kal_bool umts_tbl_valid,
                                            kal_uint8 **umts_tx_pwr_reduction_tbl,
                                            kal_bool lte_tbl_valid,
                                            kal_uint8 lte_band,
                                            kal_uint8 *lte_tx_pwr_reduction_param);

extern kal_bool l4c_get_thermal_info_req(kal_uint8 src_id);
extern void l4c_get_thermal_info_cnf_hdlr(msg_type msg_id, local_para_struct *local_para_ptr);

extern kal_bool l4c_eq_set_rx_path_req(kal_uint8 src_id,
                                       kal_uint8 cmd_type,
                                       kal_uint8 rx_path,
                                       kal_bool nvram_write);

extern kal_bool l4c_force_tx_ant_req(kal_uint8 src_id,
                                 kal_uint8 cmd_type,
                                 kal_uint8 rat,
                                 kal_uint8 ant_idx);
extern void l4c_force_tx_ant_cnf_hdlr(msg_type msg_id, local_para_struct *local_para_ptr);

#endif /* _L4C_EM_H */ 

