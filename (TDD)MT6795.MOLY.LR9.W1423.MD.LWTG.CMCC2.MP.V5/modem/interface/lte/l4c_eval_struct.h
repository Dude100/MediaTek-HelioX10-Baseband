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
 *   l4c_eval_struct.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   message and common structure definition between L4C and EVAL module
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
 * Merging
 *  	
 * 	//MOLY_CBr/danny.kuo/MOLY_LR9W1414B.MP4.W14.16.p1/mcu/modem/interface/lte/l4c_eval_struct.h
 *  	
 * 	to //MOLY/TRUNK/MOLY/mcu/modem/interface/lte/l4c_eval_struct.h
 *
 * removed!
 * removed!
 * not use compile options for VoLTE Gemini interface structures definition
 *
 * removed!
 * removed!
 * Check in VoLTE+Gemini related interfaces for VDM, IMSP, L4C, EVAL, and ERRC
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * VoLTE to MOLY
 *
 * removed!
 * removed!
 * B39 capability change indication.
 *
 * removed!
 * removed!
 * integrate EAS_TO_PEER_INFO_IND.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * - modify L4C_EVAL_PS_SWITCH_CONTEXT_IND/REQ interface
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
 * Send POWER_LEVEL_IND every 2.5s in connected mode
 *
 * removed!
 * removed!
 * Implementation of EVAL_ERRC_CELL_POWER_LEVEL_IND
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * Temp solution.
 *
 * removed!
 * removed!
 * MM IT merge back to MOLY.
 *
 * removed!
 * removed!
 * common file: EVAL part.
 *
 * removed!
 * removed!
 * revert interface
 *
 * removed!
 * removed!
 * RATCHG Interface - duplex mode update
 *
 * 01 22 2013 roy.lin
 * removed!
 * Multimode interface re-architecture.
 *
 * 11 07 2012 roy.lin
 * removed!
 * Add ESM related interface(msgid, struct, enum).
 ****************************************************************************/


#ifndef  L4C_EVAL_STRUCT_INC
#define  L4C_EVAL_STRUCT_INC

#include "l3_inc_local.h"
#include "irat_common_struct.h"
#include "nbr_public_struct.h"
#include "as2l4c_struct.h"
#include "l3_inc_enums.h"

#ifdef __VOLTE_SUPPORT__
#include "ims_common_def.h"
#endif /* __VOLTE_SUPPORT__ */

#define EAS_POWER_LEVEL_IND_INVALID_RSRP      (1)
#define EAS_POWER_LEVEL_IND_INVALID_RSRQ      (1)

#define EAS_POWER_LEVEL_IND_PERIOD_IN_MS_IDLE (5000)  /* The period that EAS shuold send POWER_LEVEL_IND again 
                                                         even if rsrp and rsrq do not change */                                                       
#define EAS_POWER_LEVEL_IND_PERIOD_IN_MS_CONN (2500)  /* The period that EAS shuold send POWER_LEVEL_IND again 
                                                         even if rsrp and rsrq do not change */
#define EAS_POWER_LEVEL_IND_RSRP_DIFF_QDBM    (8*4)   /* If the diff between the previously reported rsrp and the latest rsrp
                                                         exceeds this threshold, EAS should send POWER_LEVEL_IND to update power level */

#define EAS_POWER_LEVEL_IND_RSRQ_DIFF_QDBM    (3*4)   /* If the diff between the previously reported rsrq and the latest rsrq
                                                          exceeds this threshold, EAS should send POWER_LEVEL_IND to update power level */

/***** message structure definition *****/
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                    is_etws_needed;
    kal_bool                    is_etws_testing_on;

} l4c_eval_etws_setting_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                  warning_type;
    kal_uint16                  message_id;
    kal_uint16                  serial_number;

} l4c_eval_etws_information_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_int16                  rsrp_in_qdbm;
    kal_int16                  rsrq_in_qdbm;

#ifdef __SGLTE__ 
    target_module_enum         target_module;
    kal_uint32                 serv_EARFCN;
#endif /* __SGLTE__  */        

} l4c_eval_cell_power_level_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                        is_rest_command_present;
    rest_command_struct             rest_command;
    kal_bool                        is_monitor_mode_command_present;
    monitor_mode_command_struct     monitor_mode_command;
} l4c_eval_adjust_meas_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   result;
} l4c_eval_adjust_meas_cnf_struct;

/** 
  * According to Multimode interRAT message processing rules, 
  * the receiving module, said... the MOD_A, need to process this message in the following way  
  * - (1) Relay this interRAT message to next module, said... the MOD_B, first
  * - (2) then MOD_A can start to do processing of this message
  * because when a RD designs a new MM iRAT feature, he/she will assume others process these messages in this way
  * this rules make sures the interRAT message flow is as expected
  */
typedef struct 
{
    LOCAL_PARA_HDR
    irat_type_enum              irat_type;
    rat_type_enum               source_rat;
    rat_type_enum               target_rat;
    emm2mm_irat_info_struct     emm_info;
    esm2sm_irat_info_struct     esm_info;
    void                        *as_info_ptr;

} l4c_eval_rat_change_ind_struct;

/** 
  * According to Multimode interRAT message processing rules, 
  * the receiving module, said... the MOD_A, need to process this message in the following way  
  * - (1) Relay this interRAT message to next module, said... the MOD_B, first
  * - (2) then MOD_A can start to do processing of this message
  * because when a RD designs a new MM iRAT feature, he/she will assume others process these messages in this way
  * this rules make sures the interRAT message flow is as expected
  */
typedef struct
{
    LOCAL_PARA_HDR
    irat_type_enum              irat_type;
    rat_type_enum               source_rat;
    rat_type_enum               target_rat;
    irat_result_enum            irat_result;
    void                        *as_info_ptr;

} l4c_eval_rat_change_rsp_struct;

/** 
  * According to Multimode interRAT message processing rules, 
  * the receiving module, said... the MOD_A, need to process this message in the following way  
  * - (1) Relay this interRAT message to next module, said... the MOD_B, first
  * - (2) then MOD_A can start to do processing of this message
  * because when a RD designs a new MM iRAT feature, he/she will assume others process these messages in this way
  * this rules make sures the interRAT message flow is as expected
  */
typedef struct
{
    LOCAL_PARA_HDR
    irat_type_enum              irat_type;
    rat_type_enum               source_rat;
    rat_type_enum               target_rat;
    mm2emm_irat_info_struct     mm_info;
    sm2esm_irat_info_struct     sm_info;
    void                        *as_info_ptr;

} l4c_eval_rat_change_req_struct;

/** 
  * According to Multimode interRAT message processing rules, 
  * the receiving module, said... the MOD_A, need to process this message in the following way  
  * - (1) Relay this interRAT message to next module, said... the MOD_B, first
  * - (2) then MOD_A can start to do processing of this message
  * because when a RD designs a new MM iRAT feature, he/she will assume others process these messages in this way
  * this rules make sures the interRAT message flow is as expected
  */
typedef struct
{
    LOCAL_PARA_HDR
    irat_type_enum              irat_type;
    rat_type_enum               source_rat;
    rat_type_enum               target_rat;
    irat_result_enum            irat_result;
    void                        *as_info_ptr;
} l4c_eval_rat_change_cnf_struct;

typedef l4c_nbr_cell_info_reg_cnf_struct    l4c_eval_nbr_cell_info_start_cnf_struct;
typedef l4c_nbr_cell_info_ind_struct        l4c_eval_nbr_cell_info_ind_struct;

typedef struct 
{
    LOCAL_PARA_HDR    
    kal_uint8                       num_earfcn;
    rat_enum                        rat;
    interrat_lte_cell_info_struct   lte_cell_info[MAX_NUMBER_OF_EARFCN];
} l4c_eval_lte_neighbor_cell_info_req_struct;

#ifdef __SGLTE__ 
typedef struct
{
    LOCAL_PARA_HDR
    rat_enum                        source_rat;
    rat_enum                        target_rat;
    emm_mm_context_info_struct      mm_info;
    sm2esm_irat_info_struct         sm_info;
} l4c_eval_ps_switch_context_transfer_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    rat_enum                        source_rat;
    rat_enum                        target_rat;
    emm_mm_context_info_struct      emm_info;
    esm2sm_irat_info_struct         esm_info;
} l4c_eval_ps_switch_context_transfer_ind_struct;

typedef l4cas_to_peer_info_ind_struct       l4c_eval_to_peer_info_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool is_band_39_supported;
}l4c_eval_capability_change_ind_struct;
#endif /* __SGLTE__  */

#ifdef __VOLTE_SUPPORT__
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   barring_factor_voice;/*0~16*/
    kal_uint8                   barring_factor_video;/*0~16*/
    kal_uint8                   barring_time_voice;  /*0~8*/
    kal_uint8                   barring_time_video;  /*0~8*/    
} l4c_eval_get_ssac_param_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    srvcc_status_enum       status;
} l4c_eval_srvcc_status_update_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    vdm_voice_status_enum   vdm_voice_status;
} l4c_eval_vdm_voice_status_req_struct;

#endif /* __VOLTE_SUPPORT__ */

#endif   /* ----- #ifndef L4C_EVAL_STRUCT_INC ----- */

