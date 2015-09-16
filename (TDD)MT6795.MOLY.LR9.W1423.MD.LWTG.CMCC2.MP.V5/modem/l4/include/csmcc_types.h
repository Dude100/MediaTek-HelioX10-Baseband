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
 *	csmcc_types.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for type definition used in CSM(CC) module.
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
 * removed!
 *
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


#ifndef _CSMCC_TYPES_H
#define _CSMCC_TYPES_H

//#include "event_shed.h"       
//#include "stack_timer.h"      
//#include "kal_non_specific_general_types.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
//#include "event_shed.h"
//#include "stack_timer.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "csmcc_defs.h"
#include "csmcc_common_enums.h"
#include "csmcc_enums.h"
#include "csmcc_bc_types.h"
#include "mncc_struct.h"
//#include "ps2sat_struct.h"
#include "mcd_l4_common.h"
#include "l4c2csm_cc_struct.h"
//#include "ps_public_struct.h"
#include "ps_public_enum.h"     

typedef kal_uint16 csmcc_ret_t;

typedef enum
{
   CSMCC_CALL_FREE,
   CSMCC_CALL_BLK,
   CSMCC_CALL_UNUSED
} csmcc_call_alloc_enum;

typedef enum
{
   CSMCC_AUTO_DTMF,
   CSMCC_MANUAL_DTMF,
   CSMCC_VTS_DTMF,
   CSMCC_INVALID_DTMF_MODE = 255
} csmcc_dtmf_mode_enum;

typedef enum
{
   CSMCC_CALL_IDLE            = 0x0000, /*0*/
   CSMCC_CALL_INIT            = 0x0001, /*1*/
   CSMCC_CALL_ALERT           = 0x0002, /*2*/
   CSMCC_CALL_ACCEPT          = 0x0004, /*4*/
   CSMCC_CALL_ACTIVE          = 0x0008, /*8*/
   CSMCC_MS_CALL_DISC         = 0x0010, /*16*/
   CSMCC_NW_CALL_DISC         = 0x0020, /*32*/
   CSMCC_NW_CALL_DISC_ON_HOLD = 0x0040, /*64*/
   CSMCC_CALL_MODIFY          = 0x0080, /*128*/
   CSMCC_CALL_HOLD_REQ        = 0x0100, /*256*/
   CSMCC_CALL_HOLD            = 0x0200, /*512*/
   CSMCC_CALL_RETRIEVE_REQ    = 0x0400, /*1024*/
   CSMCC_CALL_PRESENT_IND     = 0x0800  /*2048*/
} csmcc_call_state_enum;

#define CSMCC_ALL_DISC_STATES (CSMCC_MS_CALL_DISC|   \
                               CSMCC_NW_CALL_DISC|   \
                               CSMCC_NW_CALL_DISC_ON_HOLD)   \
                               
#ifdef __CCBS_SUPPORT__
typedef enum
{
   CSMCC_CCBS_NONE,
   CSMCC_CCBS_POSSIBLE,
   CSMCC_CCBS_ACTIVATED,
   CSMCC_CCBS_INVOKED
} csmcc_ccbs_status_enum;
#endif /*__CCBS_SUPPORT__*/

typedef enum
{
   CSMCC_MPTY_IDLE,
   CSMCC_MPTY_REQ,
   CSMCC_MPTY_ACTIVE,
   CSMCC_SPLIT_REQ
} csmcc_mpty_state_enum;

typedef struct csmcc_dtmf_struct
{
   kal_uint8          *digit;
   kal_uint8          cur_digit_index;
   kal_uint8          count;  
} csmcc_dtmf_struct;

typedef struct csmcc_inv_info_struct
{
   kal_uint32          inv_id;
   kal_uint8          opcode;
   kal_bool           used;
} csmcc_inv_info_struct;

typedef struct csmcc_cug_info_struct
{
   kal_uint16 cug_index;
   kal_uint8 cug_suppress;
} csmcc_cug_info_struct;

/*mtk01602: Replace 3 stack timer(DTMF, AoC, RLC) by event scheduler*/
typedef struct csmcc_timer_struct
{
	kal_uint8 	call_id;
	eventid	  	event_id;
	kal_uint32	timer_duration; 
} csmcc_timer_struct;

typedef struct csmcc_call_context_struct
{
   kal_uint8                   call_id;
   kal_uint8                   src_id;
   kal_uint8                   ti;
   csmcc_call_state_enum       call_state;
   csmcc_call_mode_enum        call_mode;
   kal_uint8                   cur_call_type;
   csmcc_call_orig_enum        call_orig;
   csmcc_call_type_enum        bc[2];
   csmcc_dtmf_mode_enum        dtmf_mode;
   kal_bool                    wait_stop_dtmf;   
   csmcc_dtmf_struct           dtmf;
   kal_bool                    cw_flag;                   
   kal_bool                    cug_info;
   kal_uint8                   clir_info;
   csmcc_inv_info_struct       inv_info; 
   csmcc_mpty_state_enum       mpty_state;
   /* store previous state, when send or receive DISC */
   csmcc_call_state_enum       pre_call_state; 
#ifdef __AOC_SUPPORT__
   kal_uint32                  ccm_per_call;
   kal_uint32			 aoc_cdur;  
#endif 
   /* save rlc_timer_status, this timer is started for REL_COMP_REQ will not immediately sent until timer expired. */
   csmcc_timer_struct          rlc_timer;
   kal_uint8				   csmcc_rlc_status;
   /* the following variable is for:
      1. sending connect indication after data activation in case of MO data or fax call 
      2. sending incoming call indication after sending alerting request in case of 
         early assignment */
   local_para_struct                *local_para_ptr;
#ifdef __EMLPP_SUPPORT__
   csmcc_call_priority_enum    call_priority;
#endif 
#ifdef __CCBS_SUPPORT__   
   csmcc_ccbs_status_enum      ccbs_status;
   kal_uint8                   ccbs_index;
#endif /*__CCBS_SUPPORT__*/
#ifdef __SAT__
   kal_uint8   sat_call_type;
   kal_uint8   type_of_modification; //mtk01602: Store tom for SAT modified call to avoid L4C retry but send call ctrl again
#endif

   /*mtk01602: R4 new feature, Emergency Call Category*/
#ifdef __REL4__
   kal_uint8                service_category;
#endif
   kal_bool                    number_present;
   l4_addr_bcd_struct          number;
#ifdef __SUBADDR_SUPPORT__
   kal_bool                    sub_addr_present;
   l4ccsm_cc_sub_addr_struct   sub_addr;
#endif

#if defined(__TC09__)
   kal_bool ctrl_by_sim_with_mod;                /* call control by SIM with modified number */
   l4_addr_bcd_struct ctrl_by_sim_tmp_number;
#endif

} csmcc_call_context_struct;

typedef struct csmcc_v120_param_struct
{
   csmcc_v120_rah_enum          v120_rah;
   csmcc_v120_mfm_enum          v120_mfm;
   csmcc_v120_mode_enum         v120_mode;
   csmcc_v120_llineg_enum       v120_llineg;
   csmcc_v120_assign_enum       v120_assign;
   csmcc_v120_negtype_enum      v120_negtype;
} csmcc_v120_param_struct;

typedef struct csmcc_rlp_param_struct
{
   kal_uint8           rlp_iws;
   kal_uint8           rlp_mws;
   kal_uint8           rlp_T1;
   kal_uint8            rlp_N2;
   kal_uint8            rlp_ver;
   kal_uint8            rlp_T4;
} csmcc_rlp_param_struct;

typedef struct csmcc_data_compression_param_struct
{
   csmcc_data_compression_dir_enum         dir;
   csmcc_data_compression_nego_enum        negotiation;
   kal_uint16                              max_dict;
   kal_uint8                               max_string;
} csmcc_data_compression_param_struct;

typedef struct csmcc_data_bc_param_struct
{
   csmcc_sync_enum             sync;
   csmcc_bearer_ce_enum        ce;
   csmcc_itc_enum              itc;
   csmcc_other_itc_enum        other_itc;
   csmcc_user_rate_enum        ur;
   csmcc_fnur_enum             fnur;
   csmcc_rate_adaptation_enum                ra;
   csmcc_other_rate_adaptation_enum          other_ra;
   csmcc_modem_type_enum                     mt;
   csmcc_other_modem_type_enum               other_mt;
   csmcc_v120_param_struct                   v120_param;
   csmcc_rlp_param_struct                    rlp_param;
   csmcc_data_compression_param_struct       data_compression_param;
   csmcc_nsb_enum              nsb;
   csmcc_ndb_enum              ndb;
   csmcc_parity_enum           parity;
   
} csmcc_data_bc_param_struct;

typedef struct csmcc_bearer_service_type_struct
{
   csmcc_bearer_speed_enum      bearer_speed;
   csmcc_bearer_name_enum       bearer_name;
   csmcc_bearer_ce_enum         bearer_ce;
} csmcc_bearer_service_type_struct;

#if (defined(__TCPIP_OVER_CSD__) && defined(__SATCE__))
typedef struct csmcc_sat_profile_struct
{
   l4_addr_bcd_struct addr;
#ifdef __SUBADDR_SUPPORT__
   l4ccsm_cc_sub_addr_struct  subaddr;
#endif
   sat_csd_bearer_para_struct sat_cbst;
   kal_uint8 csd_module; //mtk01602, 070618: L4C need csd_module information
   kal_uint8 user_id[CSD_USER_ID_LEN];
   kal_uint8 user_pwd[CSD_USER_PWD_LEN];
   kal_uint8 local_addr[SAT_LOCAL_ADDR_LEN]; 
} csmcc_sat_profile_struct;
#endif

typedef struct csmcc_cf_param_struct
{
   csmcc_cf_format_enum          cf_format;
   csmcc_cf_parity_enum          cf_parity;
} csmcc_cf_param_struct;


typedef struct csmcc_cug_param_struct
{
   csmcc_cug_temporary_mode_enum    cug_temporary_mode;
   kal_uint8                        cug_index;
   csmcc_cug_suppress_enum          cug_suppress;
} csmcc_cug_param_struct;

typedef struct csmcc_at_param_struct
{
   csmcc_addr_type_enum          addr_type;
   csmcc_call_mode_enum          call_mode;
   csmcc_bearer_service_type_struct     bearer_service_type;
   csmcc_sns_mode_enum           sns_mode;
   csmcc_data_compression_param_struct  data_compression_param;
   csmcc_cf_param_struct                cf_param;
   csmcc_v120_param_struct              v120_param;
   csmcc_rlp_param_struct               rlp_param;
   csmcc_aoc_mode_enum                  aoc_mode;
   csmcc_cug_param_struct               cug_param;
   csmcc_fclass_mode_enum               fclass_mode;
} csmcc_at_param_struct;

typedef struct csmcc_nego_bc_struct
{
   kal_bool  bc1_present;
   csmcc_bc_struct  bc1;
   kal_bool  bc2_present;
   csmcc_bc_struct  bc2;
   kal_bool  repeat_present;
   mncc_repeat_ind_struct   bc_repeat_ind;
} csmcc_nego_bc_struct;

/*[MAUI_00740014] Supported Codec List
   Supported UMTS codec should also be considered after Rel 4 onward. */

/*MAUI_02601973 remove rel 4 compile option */
typedef struct csmcc_mscap_struct
{
   kal_uint8   speech_version;   
   kal_uint8   acc;   
   kal_uint16  data_cap;
   kal_uint8   speech_version_byte2;   /*second byte for GSM supported speech codec*/
   kal_uint8   umts_supported_speech;  /*first byte for UMTS supported speech codec*/
   kal_uint8   umts_supported_speech_byte2; /*second byte for UMTS supported speech codec*/
   kal_uint8   disable_call; /*MAUI_02907137 block CS call for DATA CARD*/
} csmcc_mscap_struct;   


typedef struct csmcc_evshed_struct
{
	event_scheduler	*evshed_ptr;
	
} csmcc_evshed_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

 /*cosine: 20080512, [SMS BOOTSTRAP]*/
typedef struct
{
    kal_uint16 rec_num;     /* total record numbers */
    kal_uint16 rec_size;    /* one record size */
    kal_uint16 batch_num;   /* batch record numbers */
    kal_uint16 current_rec; /* current record number */
} csmcc_nvram_struct;

#ifdef __CPHS__
typedef struct csmcc_als_struct
{
   kal_uint8   line_id;
} csmcc_als_struct;
#endif


typedef struct csmcc_context_struct
{
   csmcc_req_enum                   cur_req;
   kal_uint8                        req_call_id;
   csmcc_crss_req_enum              crss_req;
   kal_bool                         sat_file_change_req; /* ALPS00439699 */
   kal_bool                         starup_sim_read_req;
   kal_bool                          is_tch;     /*mtk00924 add 041210 for ECPI*/
   kal_bool                          is_ibt;      /*mtk00924 add 041210 for ECPI*/
   kal_uint8			             rat;
   kal_uint8                         rat_mode;   /* MAUI_00740014 : add for rel4 new IE, SCL*/
#ifdef __REL6__
   /*[MAUI_01712442]CC R6 change request*/ 
   kal_bool                          umts_only_service;
#endif
   kal_uint8   csmcc_sim_interface;
   csmcc_mscap_struct               mscap;
   csmcc_evshed_struct		    csmcc_timer; 
   csmcc_timer_struct		    csmcc_timer_pool[CSMCC_GTIMER_NUM];
   csmcc_data_bc_param_struct       data_bc_param;
   csmcc_at_param_struct            at_param;
   csmcc_nego_bc_struct             nego_bc;
   kal_uint8                        default_call_priority;
   kal_uint8                        auto_answer_priority_level;   
   //csmcc_timer_struct             csmcc_timer;   /* used by auto dtmf pause */
   //csmcc_timer_struct             csmcc_timer_2;   /* used by AoC update SIM ACM */   
   kal_uint32			    rlc_duration;
   kal_bool                         call_reest;
   csmcc_attach_status_enum         attach_status;   
   csmcc_channel_info_enum          channel_info;
   kal_uint8                        channel_mode;
   kal_uint8                        channel_type;
   kal_uint8                        req_src_id;
   /*Cosine: 20080503*/
   csmcc_req_enum                   prev_req;
   kal_uint8                        prev_req_src_id;
   kal_uint8                        prev_req_call_id;
   /*csmcc_req_enum*/kal_uint8                   aux_req;
   kal_uint8                        startup_req;/*only used in startup sim phase*/
   kal_uint8                        aux_req_call_id;
   kal_bool                         is_aux_req_processed;
   csmcc_req_enum                   cur_non_l4c_req;
   kal_uint8                        cur_non_l4c_req_call_id;
   /*mtk01602, 070718: MMI needs opcode in CHLD_RSP, otherwise when there's multiple CHLD_REQ,
    MMI may confused with CHLD_RSP.*/
   kal_uint32                       pause_duration;
   kal_uint32                       inv_id_count;
   kal_bool                          is_sat_dtmf;
   kal_uint8                         dtmf_src_id;
   /*Michael: add for SAT retry, to store ccp from L4C or SIM until send SAT_CALL_SETUP_CNF*/
   kal_uint8                        ccp_temp[15];
   kal_uint8                         size_of_ccp_temp;
   kal_uint8                         ctm_status;
   kal_uint8			     activate_data_call_id;
   kal_uint8 			     iwf;
   csmcc_bearer_ce_enum   activate_data_call_ce; /* MAUI_01789039 */
   kal_uint8  csmcc_emergency_call_id;
#ifdef __AOC_SUPPORT__
   kal_uint32                       acm;
   kal_uint32                       pre_acm;
   kal_uint32                       acmmax;
   kal_uint32                       acmmax_update_temp;
   kal_uint32                       last_ccm;
   kal_bool                         acm_valid;
   kal_bool                         update_acm_flag;
   kal_bool                         cdur_present;
   kal_uint32                       cdur;
   kal_bool                         updated_cdur_present;
   kal_uint32                       updated_cdur;  
   kal_uint32 acm_before_write_sim;//MAUI_02866587 , because ACM might be increased during increasing SIM(before CNF), therefore.save before increase SIM
#endif 
#ifdef __CNAP_SUPPORT__
   /* [Cosine 070327] CNAP */
   l4ccsm_cc_name_ind_struct  	cnap_info;
#endif
#ifdef __CPHS__
   kal_uint8                              temp_als_id;
   csmcc_als_struct                   als;
#endif

#ifdef __CSD_FAX__
   kal_uint8     fax_dir; /*CSD_FAX_DIRECTION_ENUM*/
#endif
   kal_bool  rscd_P;
#if (defined(__TCPIP_OVER_CSD__) && defined(__SATCE__))
   csmcc_sat_profile_struct sat_prof;
#endif
   csmcc_csd_prof_rate_enum prof_type; //add profile type for CSD prof, SAT prof, and SIM provisioing prof.
   kal_uint8                              seq_num; //MAUI_01964704
#if defined(__ECALL_SUPPORT__)
   kal_uint8  csmcc_ecall_id;
   ecall_type_enum ecall_type;
#endif
   kal_bool dup_sim_file_change_req;//ALPS00437346, true when there is unfinished sim file change
//ALPS00596537, store the newest call id for build MPTY call.
   kal_uint8 csmcc_last_call_id;
#ifdef __UMTS_TDD128_MODE__ /*For TDD projects "3G通话占网比"analysis*/
   kal_uint16 connected_call_count; /*only active call can be counted in*/
#endif
} csmcc_context_struct;

typedef struct csmcc_ctab_struct
{
   csmcc_call_alloc_enum            call_pool[CSMCC_MAX_CALL_NUM+1];
   csmcc_call_context_struct        call_tab[CSMCC_MAX_CALL_NUM];
} csmcc_ctab_struct;   
   
extern csmcc_ctab_struct csmcc_ctab_g;
extern csmcc_ctab_struct *csmcc_ctab_ptr_g;

#if defined(__GEMINI__) || defined(__SGLTE__)
extern module_type csmcc_ctab_mod_id;
#endif /*__GEMINI__*/

extern csmcc_context_struct *csmcc_ptr_g;
extern csmcc_context_struct csmcc_context_g[CSMCC_SIM_TOTAL];
extern kal_uint32 csmcc_call_capability; 

#if defined(__GEMINI__) || defined(__SGLTE__)
#define CSMCC_PTR   (csmcc_ptr_l)
#else
#define CSMCC_PTR   (csmcc_context_g)
#endif

/*every ILM from L4C, which relates one call
  shall be having the following header */
  
typedef struct l4ccsm_cc_local_para_hdr_struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 call_id;
} l4ccsm_cc_local_para_hdr_struct;

typedef l4_addr_bcd_struct mncc_called_num_struct;
typedef l4ccsm_cc_peer_addr_struct   mncc_calling_num_struct;
typedef l4ccsm_cc_sub_addr_struct mncc_sub_addr_struct;
typedef void (*csmcc_timer_hdlr_t)(kal_uint32 data);

#endif /* _CSMCC_TYPES_H */


