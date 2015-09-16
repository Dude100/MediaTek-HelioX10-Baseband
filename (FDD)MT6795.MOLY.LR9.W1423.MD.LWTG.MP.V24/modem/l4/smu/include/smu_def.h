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
 *    smu_def.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file defines the data structure, enum and constant for SMU.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                 HISTORY
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
#ifndef _SMU_DEF_H
#define _SMU_DEF_H

#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "ps2sim_struct.h"
#include "sim_common_enums.h"
#include "smu_common_enums.h"
#include "kal_general_types.h"
#include "kal_public_api.h"   
#include "ps_public_struct.h" 
#include "ps_public_enum.h"   
#include "global_def.h"
#include "sim_ps_enum.h"
#include "sim_public_enum.h"

typedef enum
{
   SMU_RES_OK,
   SMU_RES_FALSE
}l4c2smu_res_enum;

/*
typedef struct
{
   kal_uint8                reg_ps_key[NUM_OF_BYTE_KEY];
   kal_uint8                security_indication;
   kal_uint8                auto_lock_item;
   kal_uint8                np_code[NUM_OF_BYTE_NP*NUM_NP];
   kal_uint8                np_key[NUM_OF_BYTE_KEY];
   kal_uint8                nsp_code[NUM_OF_BYTE_NSP*NUM_NSP];
   kal_uint8                nsp_key[NUM_OF_BYTE_KEY];
   kal_uint8                gid1[NUM_GID];
   kal_uint8                gid2[NUM_GID];
   kal_uint8                sp_key[NUM_OF_BYTE_KEY];
   kal_uint8                cp_key[NUM_OF_BYTE_KEY];
   kal_uint8                imsi_code[NUM_OF_BYTE_IMSI];
   kal_uint8                imsi_key[NUM_OF_BYTE_KEY];
   kal_uint8                phone_key[NUM_OF_BYTE_KEY];
   kal_uint8                last_imsi[NUM_OF_BYTE_IMSI];
}smu_security_info_struct;
*/

/* Benson 20040506 add for MCD PACK UNPACK */
#define SMU_PACK(PACK_FUNC, BITS_FUNC, STRUCTID, MSG_PTR, PEER_BUFF, HDR_SIZE, TLR_SIZE) \
  smu_mcd_pack(STRUCTID, \
                (kal_uint8*)MSG_PTR, \
                PEER_BUFF, \
                HDR_SIZE, \
                TLR_SIZE);

#define SMU_UNPACK(UNPACK_FUNC, STRUCTID, STRUCT, MSG_PTR, PEER_BUFF) { \
   MSG_PTR = (STRUCT*)l4_pun_dest_buff; \
   smu_mcd_unpack(STRUCTID, PEER_BUFF); }

/* mtk01488: SATCE SCWS multiple channel */
#define MAX_SUPPORT_SATE_CHANNEL  3

#define SMU_MODULE(x,y)     (module_type)((x) + (y))

#define SMU_SELECT_SIM(x)    (sim_interface_enum)((x) - MOD_SMU)

#define NVRAM_EF_SML_TMO_LID (NVRAM_EF_SIM_LOCK_LID)

typedef struct
{
   kal_uint16 num;
   kal_uint8  *plmn_ptr;
}smu_plmn_sel_struct;

typedef struct
{
    kal_uint8 currency_code[3];
    kal_uint8 price_unit[2];
} smu_puct_struct;

typedef struct
{
    kal_uint16 file_list[8];
    kal_bool read_result[8];
} smu_file_change_info_struct;

typedef struct
{
    kal_uint8 is_valid_gid1;
    kal_uint8 gid1[NUM_GID1];
    kal_uint8 is_valid_gid2;
    kal_uint8 gid2[NUM_GID2];
    kal_uint16 num_cnl;
    kal_uint8 cnl[NUM_CNL];
    kal_uint8 is_valid_dck;
    kal_uint8 dck[16];
} smu_sim_security_info_struct;

typedef struct {
    kal_uint8 op_text[40];
    kal_uint8 key[32];
    kal_uint8 imei[16];
}smu_sms_depersonalization_req_struct;

typedef struct {
    kal_uint8 imei[16];
    kal_uint8 status[4]; //ENUM
}smu_sms_depersonalization_cnf_struct;

typedef struct 
{
    kal_uint8 key_length;
    kal_uint8 key_bcd[4];
} smu_key_bcd_struct;

typedef enum 
{
    SML_NOT_PERSONALISED=0x30, 
    SML_PERM_NOT_PERSONALISED,
    SML_PERSONALISED,
    SML_IMEI_MISMATCH,
    SML_RFU
} smu_sml_ota_enum;

typedef enum
{
    SMU_NO_TIMER_STATUS = 0,
    SMU_TIMER_RUNNING,
    SMU_TIMER_NOT_RUNNING,
    SMU_TIMER_STOPPED,
    SMU_TIMER_TIMED_OUT
} smu_timer_status_enum;

typedef struct
{
    kal_uint8 timer_id;                 /* Timer ID */
    kal_uint8 timer_data[8];            /* Time Out Value */
    smu_timer_status_enum timer_status; /* Timer Status */
    eventid event_id;                   /* Event Id returned by EventSchedular when an event is set */
    kal_uint32 ref_ticks;               /* the ticks while the timer is set */
} smu_timer_info_struct;

typedef struct 
{
   event_scheduler  *smu_event_scheduler_ptr1;
   ilm_struct       smu_timer_ilm;
} smu_timer_context_struct;

typedef struct
{
   kal_uint32 account_id;
   kal_int8 socket_id;
} smu_socket_context_struct;

typedef struct
{
   kal_uint8    cmd_detail[5];
   kal_uint8    bearer;     // '01' for CSD '02' for GPRS
   kal_uint8    channel_id;
   kal_int8     soc_fd;
   kal_uint8    channel_status[2];
   kal_uint8    channel_data_len;    // Data requested by SIM
   kal_bool     is_cmd_modified;
   kal_uint8    no_local_addr;   
   kal_uint8    no_username;
   kal_uint8    dcs_of_username;
   kal_uint8    no_passwd;
   kal_uint8    dcs_of_passwd;
   kal_uint8    protocol_type;
   kal_uint8    no_dest_addr;   
   kal_uint8    no_apn;
   kal_uint8    size_of_address;
   kal_uint8    addr[MAX_SIM_ADDR_BCD_LEN];
   kal_uint8    size_of_subaddr;
   kal_uint8    subaddr[MAX_SIM_ADDR_BCD_LEN];
   kal_bool     is_auto_reconnetion;
   kal_bool     is_immediate_link;
   kal_bool     is_retry_allowed;

   /* used to make sure we will only try to establish the connection once */
   kal_bool     is_ondemand_link_established;  
   
   kal_uint16   buffer_size;
   kal_uint16   avail_buf_size;      // tx buffer
   kal_uint16   satce_buf_hd;        // tx buffer
   kal_uint16   port_num;
   kal_uint16   avail_buf_size_rx;   //  rx buffer
   kal_uint16   satce_buf_hd_rx;     //  rx buffer

   kal_uint8    *satce_buffer;       // tx buffer
   kal_uint8    *satce_buffer_rx;    //  rx buffer
   kal_uint8    *local_addr;
   kal_uint8    *username;
   kal_uint8    *passwd;
   kal_uint8    *dest_addr;
   kal_uint8    *apn;

   kal_uint32   duration1;
   kal_uint32   duration2;
   
   /* GPRS only */
   sat_gprs_bearer_para_struct    gprs_bearer_para;

   /* CSD only */
   sat_csd_bearer_para_struct     csd_bearer_para;

   smu_socket_context_struct      socket_context;
   smu_timer_context_struct       smu_timer_context;
   smu_timer_info_struct          timer_pool[1];

    /**********************************************************************
    *   For reduce ROM/RAM size, 
    *   Above context order has been organized for data alignment and structure padding,
    *   Do not change the order arbitrarily.
    ***********************************************************************/
} sate_channel_context_struct;

typedef struct
{
   module_type                  smu_current_mod;
   kal_bool                     is_puct_valid;
   kal_bool                     is_simcard_replaced;   
   kal_bool                     is_puk_unlock;
   kal_bool                     is_exception_reset;
   kal_bool                     is_phone_lock_verified;
   kal_bool                     is_mmi_security_ind_recv;
   kal_bool                     is_mmrr_ready_ind_recv;
   kal_bool                     is_mmrr_ready_ind_sent;
   kal_bool                     is_personalization_done;
   kal_uint8                    puct_src;   
   kal_uint8                    simaccess_src;
   kal_uint8                    smu_startup_src;
   kal_uint8                    security_status;
   sim_dn_enum                  dn_type;   
   smu_sim_status_enum          sim_status;             //Kinki add for MAUI_00632199   
   smu_sim_inserted_enum        is_sim_card_inserted;   //Kinki add for MAUI_00276095,MAUI_00276091   
   smu_cipher_ind_enum          cipher_ind;
   smu_pending_password_id_enum pending_password_id;
   smu_pending_password_id_enum pending_password_id_ext[USIM_LOGIC_CH_SIZE];  // for multiple app, todo: replace "pending_password_id"
   sim_chv_status_struct        chv_status;
   sim_chv_status_struct        chv_status_ext[USIM_LOGIC_CH_SIZE];           // for multiple app, todo: replace "chv_status"
   
#ifdef __SIM_ME_LOCK__
   kal_bool                     is_sml_refresh;
   kal_bool                     is_autolock_enable;
   kal_bool                     is_autolock_success;   
   kal_bool                     is_masterkey_unlocked;   
   kal_uint8                    autolock_remain_count;
   kal_uint8                    cphs_lock_count;
   kal_uint8                    is_valid_dck;
   kal_uint8                    n_dck[4];
   kal_uint8                    ns_dck[4];
   kal_uint8                    sp_dck[4];
   kal_uint8                    cp_dck[4];
   void                         *l4csmu_set_sml_cnf_ptr;

   // TMO SML
   void                         *l4csmu_update_slb_cnf_ptr;
   void                         *l4csmu_reset_slb_cnf_ptr;
   event_scheduler              *sml_event_scheduler_ptr;
   eventid                      sml_event_id;
   kal_bool                     is_sml_timer_started;
#endif

   smu_puct_struct              *temp_puct_ptr;
   smu_file_change_info_struct  *file_change_info_ptr;
   sim_chv_info_struct          chv_info;
   sim_chv_info_struct          chv_info_ext[USIM_LOGIC_CH_SIZE];   // for multiple app, to do: replace "chv_info"
   smu_plmn_sel_struct          plmn_sel_info;
   smu_plmn_sel_struct          uplmn_wact_info;
   smu_plmn_sel_struct          oplmn_wact_info;
   smu_plmn_sel_struct          hplmn_wact_info;
   smu_puct_struct              puct_data;
   kal_uint8                    temp_pin_code[8];       //Kinki add for pin verification in exceptional power-on
   kal_uint8                    imsi[NUM_OF_BYTE_IMSI];
   
#ifdef __SIM_ME_LOCK__
   smu_sim_security_info_struct sim_security_info;
#endif 

    /**********************************************************************
    *   For reduce ROM/RAM size, 
    *   Above context order has been organized for data alignment and structure padding,
    *   Do not change the order arbitrarily.
    ***********************************************************************/
    
#if defined(__SATCE__) && !defined(__RSAT__)
   sate_channel_context_struct  sate_channel[MAX_SUPPORT_SATE_CHANNEL+1];
   kal_uint8                    sate_channel_usage_table[MAX_SUPPORT_SATE_CHANNEL+1];
   kal_uint8                    sate_channel_socket_table[MAX_SUPPORT_SATE_CHANNEL+1];
   kal_uint8                    sate_channel_child_socket_table[MAX_SUPPORT_SATE_CHANNEL+1];
   kal_uint8                    sate_current_channel;
   kal_uint8                    sate_app_id;
   kal_bool                     is_sate_child_socket_closed;
   kal_bool                     is_drop_data[MAX_SUPPORT_SATE_CHANNEL+1];
   kal_bool                     is_server_mode_multi_channel_existed;    /* mtk01488: default is false */
#endif
}smu_context_struct;

extern smu_context_struct smu_context_g[MAX_SIM_NUM];
extern smu_context_struct * this_smu;

#endif  

