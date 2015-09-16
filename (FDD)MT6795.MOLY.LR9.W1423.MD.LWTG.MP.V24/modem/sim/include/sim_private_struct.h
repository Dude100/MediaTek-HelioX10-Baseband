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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   sim_private_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Structure provided by SIM task and inside-SIM task uses only
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
#ifndef SIM_PRIVATE_STRUCT_H
#define SIM_PRIVATE_STRUCT_H

#include "kal_public_defs.h"

#if (defined(__SIM_MMDS_CLIENT__)||defined(__SGLTE__))
/* Task Message Communication */
#include "lcd_ip_cqueue.h"
#include "sysservice_msgid.h"

/* Timer Management  */
//#include "stack_timer.h"
//#include "event_shed.h"

/* Task Management */
#include "task_config.h" 
#endif

#include "sat_def.h"
#include "sim_ps_enum.h"
#include "ps_public_struct.h"
#include "ps_public_enum.h"
#include "sim_private_enum.h"
#include "sim_public_enum.h"
#include "sim_public_struct.h"

/* Driver related*/
#include "drv_comm.h"
#include "dcl.h"

#ifndef __MTK_TARGET__
#include "usim_dummy_driver.h"
#endif

typedef struct
{
    kal_uint8 timer_data[8];            /* Time Out Value */
    eventid event_id;   /* Event Id returned by 
                           EventSchedular when an 
                           event is set */
    kal_uint32 ref_ticks;               /* the ticks while the timer is set */
    kal_uint8 timer_id;                 /* Timer ID */
    kal_uint8 current_module;
    sim_timer_status_enum timer_status; /* Timer Status */
} sim_timer_info_struct;

typedef struct
{
    /* [MAUI_02903761] mtk01612 : modify event scheduler due to system service optimization */
    event_scheduler *sim_event_scheduler_ptr1;
    /* [MAUI_02620145] mtk01616_100910 : remove sim_base_timer2,sim_event_scheduler_ptr2,sim_timer_ilm */
} sim_timer_context_struct;

typedef struct
{
    sim_file_index_enum sim_current_file_idx;
    sim_file_index_enum sim_current_df_idx;
    kal_uint16 sim_current_df_file_id; //__CSIM       
    kal_uint8 uicc_current_path[6];
    kal_uint8 file_descriptor;
    kal_uint8 file_type;
    kal_uint16 file_size;
    kal_uint8 rec_num;
    kal_uint8 rec_size;

    uicc_card_type_enum uicc_type;
    kal_uint8 aid_len;
    kal_uint8 aid[16];	
    sim_chv_info_struct chv_status; 
    kal_uint8 verified_pin1[8];
} uicc_channel_ctx_struct;

typedef struct
{
    kal_uint16 len;
    kal_uint8 buf[258]; /* MAUI_02953154: preserve 2 bytes for possible T=1 scenario. driver need extra 2 bytes for status word */
}sim_buff_struct;

#if defined( __GEMINI__) || defined(__SGLTE__)
typedef struct 
{
    kal_uint8 is_other_RR_dedicated;
    kal_uint8 mmi_allow_other_sat_fetch; /* mtk01488: CR# 1079892 */  
#ifdef __SIM_SYNC_POLL_TIMER__	/*mtk01612: [MAUI_03020152] sync polling timer*/
	sim_sync_poll_timer_state_enum sim_sync_poll_timer_state;
	kal_uint32 sim_sync_poll_timer_period;
	kal_bool is_sync_ind_not_send;
#endif	
}gemini_context_struct;
#endif

typedef struct
{
    /* mtk01488: keep the location info before setup event list */
////    kal_uint8 is_first_location_info_updated;
    /* mtk01616_110504 MAUI_02870129 check if we already done location_info event download ever */
    kal_uint8 had_location_info_event_download;
    kal_uint32 evdl_timer_tick;
}ens_context_struct;

#ifdef __SAT_ADDITIONAL_LOCK__
typedef struct
{
    kal_uint8 is_mutual_auth_passed;
}additional_lock_context_struct;	
#endif 

#ifdef __DRV_SIM_CLK_DUTY_NOT_ENOUGH__
typedef struct
{
    kal_uint8 is_last_cmd_FETCH;
    kal_uint8 additional_STATUS_counter;
    kal_uint8 need_recovery_as_18v;      /* MAUI_02825474 mtk02374 20100924 add a flag to check whether to recovery as 1.8v */
}drv_clk_cycle_context_struct;	
#endif

#ifdef __USIM_SUPPORT__
typedef struct
{
    kal_uint8 ust[USIM_SUPPORT_UST_LEN];
    kal_uint8 est[USIM_SUPPORT_EST_LEN];
}usim_context_struct;	
#endif

#ifdef __ISIM_SUPPORT__
typedef struct
{
    kal_bool is_isim_exist;
    usim_logic_channel_enum channel;
}isim_context_struct;
#endif

#ifdef __SAT__
typedef struct
{
    kal_uint8 command_number;
    kal_uint8 refresh_status;
    kal_uint8 type_of_refresh;
} sat_refresh_cmd_data_struct;

typedef struct
{
    /*mtk01488: MAUI_00799533*/
    kal_uint8 is_location_updated_by_rac;
    kal_bool proactive_cmd_ind;                                                      
    kal_uint16 pending_proactive_cmd_len;	
    kal_uint8 drop_tr;  /*mtk02374 20090717 used to drop tr if there is proactive command before recovery*/
    kal_uint8 time_zone;
//    kal_uint8 timing_advance;
    kal_uint8 sat_cmd_detail[5];
    sat_refresh_cmd_data_struct refresh_info;
    kal_uint16 file_changed_module_table;/* MAUI_02943738 extend file change bitmask table from u8 to u16 */
    kal_uint8 mm_status;
    kal_uint8 rat_status;               /* mtk01488 */
    kal_uint8 location_info[9]; /* mtk01616_110505 MAUI_02931370 Enlarge from 7 to 9. to support Extended Cell ID in location information */
#ifdef __SGLTE__
    kal_uint8 ext_mm_status;            // for SGLTE case, we need both CS/PS information
    kal_uint8 ext_rat_status;           // for SGLTE case, we need both CS/PS information
    kal_uint8 ext_location_info[9];     // for SGLTE case, we need both CS/PS information
#endif
    sat_call_status_enum call_status;
    sat_pdp_status_enum pdp_status;
    kal_uint8 sim_cmd_apdu[261];
    //[MAUI_02371550] 20100311 mtk02374 extend envelope_data to 79 to avoid memory corruption
    kal_uint8 envelope_data[79];        /* For SATC3 Event DL */
    kal_uint8 envelope_length;
    kal_uint8 is_in_sat_session;        /* For EVDL call connected origin by STK */
    kal_uint8 retry_env_timer_expiry;   /* For SATC3 Timer Management */ 
    /* Call Control by SIM */
    sat_call_ctrl_by_sim_state_enum call_ctrl_state;
    kal_uint8 *call_ctrl_by_sim_rsp_ptr;    /* Keep the envelope response for TR usage */
    kal_uint16 call_ctrl_by_sim_rsp_len;
    kal_uint8 get_input_ucs2_max;
    kal_uint8 get_input_nonucs2_max;
    kal_uint8 nw_search_mode;   /*MAUI_1687912 mtk02374*/
    sat_terminal_res_enum error_res;    
    sim_cmd_result_enum terminal_profile_result; /* MAUI_03032781 */
#ifdef __SETUP_CALL_WITH_SS_STR__	
    /*
      *  [MAUI_01744519] mtk02374 20090520
      *  Implementation of SETUP CALL with SS strubg
      */
    kal_bool setup_call_with_ss_string;
#endif  /*__SETUP_CALL_WITH_SS_STR__*/
	
#ifdef __SATCE__
    kal_uint8 channel_id;
#endif 	
    /*MAUI_01956092 mtk02374 20090914 used to check whether 1st proc_cmd length is 910B*/
    kal_bool imei_lock_needed;

/* mtk01616_110320 MAUI_02899488 */
#ifdef __SAT_DISABLE_ICON_SUPPORT__  
    kal_bool icon_present;
#endif

    rsat_config_enum is_wait_for_rsp;
#ifdef __SATCE__
    kal_uint32 sim_pun_buff[150];
#endif
#ifdef __SGLTE__
    kal_bool provide_ps_info;
#endif
    sat_procomm_struct  *proactive_cmd;
    kal_uint8 is_refresh_successful;
}sat_context_struct;
#endif /* __SAT__ */


#ifdef __BT_SIM_PROFILE__
typedef struct
{
    kal_uint8 sim_access_profile_is_connected;
}bt_sap_context_struct;	
#endif 

#ifdef __GSMCDMA_DUALSIM__
typedef struct
{
    kal_uint8 is_gsmcdma_dualsim_disconnected;
    kal_uint8 allowed_get_sim_info;
}gsmcdma_context_struct;
#endif /* __GSMCDMA_DUALSIM__ */ 

#ifdef __CDMASIM_DETECTION__
typedef struct
{
    kal_bool check_cdma_done;
    sim_cdma_struct cdma;
}sim_cdma_info_struct;
#endif

#ifdef __SIM_HOT_SWAP_SUPPORT__
typedef struct
{
    kal_uint8 sim_plug_out_signal;
    kal_uint8 sim_plug_out_count;
    kal_uint8 sim_plug_in_count;
}sim_hot_swap_context_struct;
#endif /* __SIM_HOT_SWAP_SUPPORT__ */

#ifdef __SIM_RECOVERY_ENHANCEMENT__
typedef struct
{
    kal_bool is_sim_recovery_enh_on; 
    kal_uint8 fast_recovery_count;
    kal_bool is_reset_finished;
    kal_bool is_initialize_success;
    kal_bool is_sim_lost;
    kal_uint16 full_recovery_count;
    eventid recovery_timer_event;
}sim_recovery_context_struct;
#endif /* __SIM_RECOVERY_ENHANCEMENT__ */

typedef struct
{
    kal_bool support_additional_interface;
    kal_uint8 additional_interface;
    kal_bool support_extended_logical_channel;
    kal_bool support_power_supply;
    kal_uint8 power_supply_data[3];
}sim_terminal_capability_struct;


/* SIM Module Context Struct */
typedef struct 
{
/***********************************************************************/
/* Below context are placed in the front of SIM context                */
/* to increase immediate offset access , to reduce ROM size            */
/* Please KEEP the position for the following frequent used variables  */
/***********************************************************************/
	
    /* MAUI_01949579 mtk02374 20090903 for CTA GEMINI new bootup*/
    sim_cmd_result_enum reset_result;
    kal_uint8 event_list[3]; //__SATCM__
    /* mtk01488: sim recovery counter */
    kal_uint8 sim_recovery_counter;
    /* mtk01488: CR#093514 */
    kal_bool is_restarted_from_puk;
    kal_bool sat_ready_to_start;
    /* mtk01488: This records if MS is in dedicated, as timer expiry will send STATUS within 30s in dedicated mode */
    kal_bool is_dedicated;
    /* This file stores the information about the current EF selected */
    kal_uint8 sim_reset_volt;
    kal_bool is_dcs1800_card;
    kal_bool is_test_sim;
    kal_bool is_imsi_remain;//Kinki: [MAUI_01302464]
    kal_bool is_poweron_finished; /*mtk01612: [MAUI_02052346]*/
    /* Benson 20040430 Prevent sim abnormal reset during power on procedure */
    kal_bool sim_reseting_abnormal;
    kal_uint8 phase;
    kal_bool cipher_ind;                                                                            
    kal_uint8 mnc_length;                                                                         
    kal_bool is_start_cnf_sent; /* mtk01612: [MAUI_01790222], [MAUI_01792021]*/  
    sim_card_status_enum sim_card_status;
    sim_dn_enum dn_type;                    /* used for no SIM initialization */                
    kal_uint8 sim_sst[MAX_SST_LEN];
    kal_uint8 start_req_access_id; /* MAUI_02996856 to record access id of start_req*/
    kal_uint8 iccid[10];

#if defined( __GEMINI__) || defined(__SGLTE__)
    gemini_context_struct gemini;
#endif

    /* Current file path */
    uicc_channel_ctx_struct uicc_ch_info[USIM_LOGIC_CH_SIZE];

#ifdef __USIM_SUPPORT__
    usim_context_struct usim;
#endif

#ifdef __ISIM_SUPPORT__
    isim_context_struct isim;
#endif

    kal_uint16 current_module;

    kal_uint8 simInterface;     /* for driver and other tasks: SIM1:0, SIM2:1 */

    DCL_HANDLE sim_hd; /*Task descriptor handler provided by sim driver: A number which can uniquely identify driver API user*/

#ifdef __SIM_HOT_SWAP_SUPPORT__
    sim_hot_swap_context_struct hot_swap; /* mtk80420: add for SIM hot swap */
#endif /* __SIM_HOT_SWAP_SUPPORT__ */

/***********************************************************************/
/* Above context are placed in the front of SIM context                */
/* to increase immediate offset access , to reduce ROM size            */
/* Please try to KEEP the position for these frequent used variables   */
/***********************************************************************/

    kal_uint32 sim_timer_period;	
    kal_uint8 sim_power_on_imsi[9];	//Kinki: [MAUI_01302464]

    sim_timer_context_struct sim_timer_context;
    sim_timer_info_struct timer_pool[9];

#ifdef __SIM_RECOVERY_ENHANCEMENT__
    sim_recovery_context_struct recovery;
#endif

#ifdef __SIM_UNIT_TEST__
    kal_uint8 sim_test_num;
    kal_bool disable_sim_recovery;
#ifdef __DUAL_SIM_HOT_SWAP_CO_DECK_SUPPORT__
    kal_bool is_deck_plug_out; // reset flag if deck is plug in; only used on SIM Context 1
    kal_bool is_sim_plug_out; // reset flag if SIM is inserted
#endif
#endif

    ens_context_struct ens;

#ifdef __SAT_ADDITIONAL_LOCK__
    additional_lock_context_struct additional_lock; 
#endif
#ifdef __DRV_SIM_CLK_DUTY_NOT_ENOUGH__
    drv_clk_cycle_context_struct drv_clk_cycle; 
#endif
#if defined(__SIM_ACCESS__)	|| defined(EXTERNAL_MMI) || defined(__SIM_UNIT_TEST__)
    kal_uint16 unit_test_num;        /* Benson add for unit test control */ 
#endif
#ifdef __BT_SIM_PROFILE__
    bt_sap_context_struct bt_sap;
#endif 
#ifdef __GSMCDMA_DUALSIM__
    gsmcdma_context_struct gsmcdma_dual;
#endif

#ifdef __CDMASIM_DETECTION__
    sim_cdma_info_struct cdma_info;
#endif

#ifdef __VSIM__
    kal_bool is_vsim_on;
#endif

#ifdef __SIM_UT__
    kal_uint8 switch_mode;
#endif

#ifdef __ECALL_SUPPORT__ 
    /* This is for test simulation. If ecall_test_mode is set to value other than default value SIM_ECALL_TEST_DISABLE.
       SIM task return the set value as the ecall mode in sim_ecall_mode_query() */
    sim_ecall_mode_enum ecall_test_mode; 
#endif

#ifdef __SAT__
    sat_context_struct sat;
#endif
    sim_buff_struct rx_tmp_buff;

    DCL_CONFIGURE_T sim_driver_config;
    kal_bool is_sim_hd_valid;

    sim_terminal_capability_struct terminal_capability;
    
#if defined(__SIM_MMDS_CLIENT__)
    kal_uint8 mmdc_src;
    int_q_type *sim_queue;
#endif

#if defined(__SGLTE__)
    int_q_type *sim_queue; 
    sim_mmdc_mode_enum mmdc_mode; //sim query l4c and set this flag when powwer on.
#endif

    kal_bool is_sim_poweroff; //SIM card in poweroff state or not

#ifdef __SIM_HOT_SWAP_POLL_TIMER__
    kal_bool sim_hot_swap_timer_start;
    kal_uint32 sim_temp_timer_period;
#endif
} sim_context_struct;

typedef struct
{
    kal_uint8 fd;
    kal_uint8 data_coding;
    kal_uint16 rec_len;
    kal_uint8 num_rec;
} usim_file_descriptor_struct;

typedef struct
{
    kal_uint16 file_id;
} usim_file_identifier_struct;

typedef struct
{
    kal_uint8 length;
    kal_uint8 df_name[16];
} usim_df_name_struct;

typedef struct
{
    kal_uint32 available_mem_bytes; /* limit to 4 bytes */
    kal_uint8 do_flag;              /* data object exist flags */
    kal_uint8 char_byte;            /* usim uicc characteristics */
    kal_uint8 supp_volt_class;      /* application power consumption */
    kal_uint8 app_pwr_consump;      /* application power consumption */
    kal_uint8 pwr_ref_freq;         /* application power consumption */
    kal_uint8 app_min_freq;         /* minimum application clock frequency */
    kal_uint8 supported_sys_cmds;     /* supported system commands*/
} usim_proprietary_information_struct;

typedef struct
{
    kal_uint8 life_cycle_status;
} usim_life_cycle_status_integer_struct;

typedef struct
{
    kal_uint8 do_flag;
} usim_security_attributes_struct;

typedef struct
{
    kal_uint32 pin_flag;
    kal_uint32 enabled_pin_flag;
} usim_pin_status_temp_do_struct;

typedef struct
{
    kal_uint32 tot_file_size;
} usim_total_file_size_struct;

typedef struct
{
    kal_uint16 file_size;
} usim_file_size_struct;

typedef struct
{
    sfi_usage_enum sfi_usage;
    kal_uint8 sfi_prop;
} usim_short_file_identifier_struct;

#ifdef __SGLTE__
typedef struct {    
    sim_file_index_enum file_idx;
    kal_uint8 channel_id;
    kal_uint8 path[6];
} sim_intsim_access_file_info_req_struct;

typedef struct {    
    sim_file_index_enum file_idx;
    kal_uint16 para;
    kal_uint16 req_len;
    kal_uint8 channel_id;
    kal_uint8 path[6];
} sim_intsim_access_read_req_struct;

typedef struct {
    sim_file_index_enum file_idx;
    kal_uint16 para;
    kal_uint16 req_len;
    kal_uint8 channel_id;
    kal_uint8 path[6];
    kal_uint8 data[260];
} sim_intsim_access_update_req_struct;

typedef struct {
    kal_uint8   rand[16];
    kal_bool    is_auth_present;
    kal_uint8   auth[16];
    //kal_uint8   src_id;
    kal_uint16 length;
    kal_uint8 path[6];
} sim_intsim_access_auth_req_struct;

typedef struct {
    sim_file_index_enum file_idx;
    kal_uint8 data[127];
    kal_uint8 data_len;
    kal_uint8 access_id;
    kal_uint8 channel_id;
    kal_uint8 path[6];
} sim_intsim_access_increase_req_struct;

typedef struct {
    sim_file_index_enum file_idx;
    kal_uint8 path[6];
} sim_intsim_access_invalidate_req_struct;

typedef struct {    
    sim_file_index_enum file_idx;
    kal_uint8 path[6];
} sim_intsim_access_rehabilitate_req_struct;

typedef struct sim_intsim_access_req_struct{
    LOCAL_PARA_HDR
    //kal_uint8 src_id; 
    sim_intsim_access_op_enum op;
    union
    {
        sim_intsim_access_file_info_req_struct file_info_req;
        sim_intsim_access_read_req_struct read_req;
        sim_intsim_access_update_req_struct update_req;
        sim_intsim_access_auth_req_struct auth_req;
        sim_intsim_access_increase_req_struct increase_req;       
        sim_intsim_access_invalidate_req_struct invalidate_req;
        sim_intsim_access_rehabilitate_req_struct rehabilitate_req;
    }req_field;
} sim_intsim_access_req_struct;

typedef struct {
    LOCAL_PARA_HDR  
    kal_uint8 src_id; 
    sim_cmd_result_enum result;
    kal_uint16 status;
    kal_uint16 rsp_len;
    kal_uint8 rsp_data[256];
} sim_intsim_access_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR  
    sim_error_cause_enum error_cause;    
} sim_intsim_notify_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    sim_cmd_result_enum result;
    kal_uint16 status_word;
    sim_security_operation_enum op;
    sim_chv_type_enum which_chv;
    kal_uint8 access_id;
    sim_chv_info_struct chv_info;
    kal_uint8 verified_pin1[8];        
} sim_intsim_security_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 access_id;
    sim_cmd_result_enum result;
    sim_dn_enum dn_type;
    kal_bool switch_on;         
} sim_intsim_dial_mode_change_ind_struct;
#endif /* __SGLTE__ */
/******************* MMDS DC END ****************/
extern sim_context_struct sim_context_g[SUPPORT_SIM_TOTAL];

extern const rsat_config_enum rsat_conf[RSAT_SIZE];

#ifdef __SAT_ADDITIONAL_LOCK__
extern kal_uint8 sim_profile[MAX_SIM_PROFILE_LEN + SAT_ADDITIONAL_TER_PROFILE];
#else /* __SAT_ADDITIONAL_LOCK__ */ 
extern kal_uint8 sim_profile[MAX_SIM_PROFILE_LEN];
#endif /* __SAT_ADDITIONAL_LOCK__ */ 

extern const kal_uint8 terminal_support_table[8];

#ifndef __MTK_TARGET__
#ifdef __USIM_SUPPORT__
extern const sim_file_index_enum usim_adf_sfi_table[USIM_TOTAL_SFI];
extern const sim_file_index_enum gsm_access_sfi_table[GSM_ACCESS_TOTAL_SFI];
#endif
#endif

/* SAT */
typedef struct
{
    kal_uint8 tag;
    kal_uint8 length;
    union{
        void *value_ptr;
        kal_uint8 value_data[4];
    } value;
} sat_tlv_struct;


#endif

