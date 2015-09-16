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
 *   ratcm_llc_struct.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 ******************************************************************************/

#ifndef _RATCM_LLC_STRUCT_H
#define _RATCM_LLC_STRUCT_H

#include "mcd_l3_inc_gprs_struct.h"
#include "as2nas_struct.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "l3llc_enums.h"
#include "irat_common_enums.h"

typedef struct {
    LOCAL_PARA_HDR
    kal_uint32 old_tlli;
    kal_uint32 new_tlli;
    tlli_update_type_enum tlli_update_type; /* tlli_update_type_enum */
    kal_uint8 cipher_algo; /* 0=no ciphering, 1=GEA1, 2=GEA2, 3=GEA3*/
    kal_uint8 is_gprs_cipher_key_info_present; /* if GPRS cipher key present */
    kal_uint8 gprs_cipher_key_info[KC_LEN]; /* GPRS cipher key (Kc) */    
    kal_uint8 is_gprs_cipher_key128_info_present; /* if GPRS cipher key128 present */
    kal_uint8 gprs_cipher_key128_info[KC128_LEN]; /* GPRS cipher key128 (Kc) */
} ratcm_llc_assign_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint32 tlli; /* xyz*/
} ratcm_llc_resume_req_struct; /* Should be same as mm_ratcm_llc_resume_req_struct */

typedef struct {
    LOCAL_PARA_HDR
    kal_uint32 tlli; /* xyz*/
} ratcm_llc_suspend_req_struct; /* Should be same as mm_ratcm_llc_suspend_req_struct */

typedef struct {
    LOCAL_PARA_HDR
    kal_uint32 tlli;
    kal_uint8 cause;
} ratcm_llc_status_ind_struct; /* Should be same as mm_ratcm_llc_status_ind_struct */

#ifdef __PS_HO__
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 cipher_algo;    
} ratcm_llc_psho_ind_struct; /* Should be same as mm_ratcm_llc_psho_ind_struct */
#endif

typedef struct {
    LOCAL_PARA_HDR
    kal_uint32 tlli; /* xyz*/
    kal_uint8 cause; /* res_req_cause */
    kal_uint8 cell_update_type; /* R99 feature: llgmm_cell_update_type_enum */
} ratcm_llc_trigger_req_struct; /* Should be same as mm_ratcm_llc_trigger_req_struct */

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_uint8 radio_priority;
    kal_uint8 cipher_ind;
    kal_uint8 msg_type;
    kal_uint8 nsapi;
    kal_uint32 tlli;
    kal_uint8 pfi; /* R99 feature */
    concise_qos_struct qos_param;
    peer_msg_id_struct peer_msg_id;    
} ratcm_llc_unitdata_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_bool cipher_ind;
    kal_uint32 tlli;
} ratcm_llc_unitdata_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 tx_status;  /* MAUI_02388489 */
    peer_msg_id_struct peer_msg;
} ratcm_llc_as_nas_data_cnf_struct;

typedef ratcm_llc_assign_req_struct llc_gmm_assign_req_struct; 
typedef ratcm_llc_trigger_req_struct llc_gmm_trigger_req_struct;
typedef ratcm_llc_suspend_req_struct llc_gmm_suspend_req_struct;
typedef ratcm_llc_resume_req_struct llc_gmm_resume_req_struct;
typedef ratcm_llc_status_ind_struct llc_gmm_status_ind_struct; 
#ifdef __PS_HO__
typedef ratcm_llc_psho_ind_struct llc_gmm_psho_ind_struct; 
#endif

#endif /* RATCM_LLC_STRUCT_H */
