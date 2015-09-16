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
 *   sim_public_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   SIM related message structure (outside PS)
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
#ifndef SIM_PUBLIC_STRUCT_H
#define SIM_PUBLIC_STRUCT_H

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "sim_public_enum.h"

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8  ef_imsi[9];
} sim_ready_ind_struct;

/* MAUI_01949579 mtk02374 20090903 for CTA GEMINI new bootup*/
typedef struct {
   LOCAL_PARA_HDR
   kal_uint8 src_id;
} sim_reset_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   kal_uint8 src_id;
   kal_bool is_sim_inserted;
} sim_reset_cnf_struct;

/*mtk01612:  [MAUI_02023545] BT_SIM_Profile for MAUI and DUMA*/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
} bt_sim_connect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 result;
    kal_uint8 current_transport_protocol_type;
    kal_uint8 supported_transport_protocol_type_capability;
    kal_uint16 atr_len;
    kal_uint8 atr[ATR_MAX_LEN];
    kal_uint8 src_id;    
} bt_sim_connect_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 transport_protocol_type;
    kal_uint8 src_id;    
} bt_sim_reset_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 result;
    kal_uint8 current_transport_protocol_type;
    kal_uint16 atr_len;
    kal_uint8 atr[ATR_MAX_LEN];
    kal_uint8 src_id;    
} bt_sim_reset_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 transport_protocol_type;
    kal_uint16 apdu_req_len;
    kal_uint8 apdu_req[APDU_REQ_MAX_LEN];
    kal_uint8 src_id;    
} bt_sim_apdu_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 result;
    kal_uint16 apdu_rsp_len;
    kal_uint8 apdu_rsp[APDU_RSP_MAX_LEN];
    kal_uint8 src_id;    
} bt_sim_apdu_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
} bt_sim_disconnect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 result;
    kal_uint8 src_id;
} bt_sim_disconnect_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
} bt_sim_power_off_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 result;
    kal_uint8 src_id;    
} bt_sim_power_off_cnf_struct;

typedef bt_sim_reset_req_struct bt_sim_power_on_req_struct;
typedef bt_sim_reset_cnf_struct bt_sim_power_on_cnf_struct;

//__SIM_JSR177_APDU__
typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8 src_id;
   kal_uint8 transport_protocol_type;
   kal_uint16 apdu_req_len;
   kal_uint8 apdu_req[261]; 
   kal_uint16 expected_rsp_len;
} sim_jsr177_apdu_req_struct;
 	
typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8 src_id;
   kal_uint16 result; 
   kal_uint16 apdu_rsp_len;
   kal_uint8 apdu_rsp[258];
} sim_jsr177_apdu_cnf_struct;

typedef struct 
{
   LOCAL_PARA_HDR
   kal_uint8 src_id;
} sim_jsr177_atr_req_struct;

typedef struct 
{
   LOCAL_PARA_HDR
   kal_uint8 src_id;
   kal_uint16 result;
   kal_uint8 current_transport_protocol_type;
   kal_uint16 atr_len;
   kal_uint8 atr[ATR_MAX_LEN];   
   kal_uint8 uicc_type; /* uicc_card_type_enum */
} sim_jsr177_atr_cnf_struct;

/* MAUI_02953154 */
typedef struct
{
   LOCAL_PARA_HDR
   kal_uint16 file_idx;
   kal_uint16 para; /* Low byte(P1) is record index. High byte(P2) indicate search mode but now it's RFU, only support search forward from index P1 */
   kal_uint8 access_id;
   kal_uint8 path[6];   
   kal_uint8 src_id;
   kal_uint8 pattern_len; /* pattern data size is MAX_SUPPORT_RECORD_SIZE at most */
   kal_uint8 data[MAX_SUPPORT_RECORD_SIZE+6];  /* max pattern data size + 6 bytes space for command header */
} sim_search_record_req_struct;
 	
typedef struct
{
   LOCAL_PARA_HDR
   kal_uint16 file_idx;   
   kal_uint16 para;        
   kal_uint8 access_id;  
   kal_uint8 src_id;
   kal_uint16 result; 
   kal_uint16 status_word;   
   kal_uint8 record_num;  /* number of pattern matched records. MAX_SUPPORT_RECORD_NUM at most */
   kal_uint8 record[258]; /* max APDU response data size 256 + 2 bytes preserved for SIM dirver */
} sim_search_record_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8   rand[16];
    kal_bool    is_auth_present;
    kal_uint8   auth[16];
    kal_uint8   src_id; /*[MAUI_02602650] mtk01612: AT+EAUTH authentication through AT cmd*/

    uicc_auth_mode_enum mode;
    kal_uint8   channel_id;
    kal_uint8   command_len;
    kal_uint8   command_data[256];
} sim_authenticate_req_struct, sim_app_authenticate_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    sim_cmd_result_enum result;
    kal_uint16 status_word;
    kal_uint8   kc[8];
    kal_uint8   sres[4];
    kal_uint8   ck[16];
    kal_uint8   ik[16];
    kal_uint8   res[16];
    kal_uint8   res_len;
    kal_uint8   auts[16];
    kal_uint8   auts_len;
    kal_uint8   auth_res[256]; /*[MAUI_02602650] mtk01612: AT+EAUTH authentication through AT cmd. This should be the same as USIM_MAX_AUTHENTICATE_RSP_LEN */
    kal_uint16  auth_res_len;  /*[MAUI_02602650] mtk01612: AT+EAUTH authentication through AT cmd.*/
    kal_uint8   src_id; /*[MAUI_02602650] mtk01612: AT+EAUTH authentication through AT cmd.*/  
} sim_authenticate_cnf_struct, sim_app_authenticate_cnf_struct;

typedef struct{
    kal_uint8 length;
    kal_uint8 atr[ATR_MAX_LEN];
}sim_atr_struct;

typedef struct{
    kal_bool is_sim_inserted;
    kal_bool is_df_gsm_existed;
    kal_bool is_df_cdma_existed;
}sim_cdma_struct;

typedef union {
    sim_atr_struct atr;
    sim_cdma_struct cdma;
} sim_query_info_field;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    sim_query_info_enum info_id;
} sim_query_info_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    sim_cmd_result_enum result;
    sim_query_info_enum info_id;
    sim_query_info_field info_data;
} sim_query_info_cnf_struct;

#ifdef __MINI_LOG_SUPPORT__
typedef struct
{
    sim_cmd_result_enum reset_result;
    kal_bool is_test_sim;	
    sim_card_status_enum sim_card_status;
    kal_uint8 sim_power_on_imsi[9];   
    kal_uint8 sim_sst[MAX_SST_LEN];
    kal_uint8 ust[USIM_SUPPORT_UST_LEN];	
}sim_mini_log_context_struct;

typedef struct
{
    sim_mini_log_context_struct sim_mini_log_context[SUPPORT_SIM_TOTAL];
    
    kal_uint32 dummy; /*[MAUI_03169422] mtk01612: add dummy to make sure 4-byte alignment, otherwise, TST would assert.*/
}mini_log_module_sim_struct;
#endif

#endif

