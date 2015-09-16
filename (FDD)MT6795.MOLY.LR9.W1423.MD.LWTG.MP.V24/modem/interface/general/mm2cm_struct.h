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
 *	mm2cm_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for structure definition between MM and Cm layers.
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


#ifndef _MM2CM_STRUCT_H
#define _MM2CM_STRUCT_H

#include "kal_general_types.h"
#include "mcd_l3_inc_struct.h"
#include "l3_inc_enums.h"
#include "kal_public_defs.h"

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 ti;
} mmcm_est_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 ti;
} mmcm_est_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 ti;
} mmcm_data_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    ps_cause_enum cause;
} mmcm_rel_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    ps_cause_enum cause;
    kal_bool remain_ecc; /* 1: emergency call is kept */
} mmcc_rel_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_successful;
} mmcc_srvcc_ho_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 ti;
} mmcm_est_intr_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 ti;
    ps_cause_enum cause;
} mmcm_est_rej_struct;

typedef struct {
    LOCAL_PARA_HDR
    sync_ind_cause_enum cause;
    channel_type_enum channel_type;
    channel_mode_enum channel_mode;
} mmcm_sync_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    rat_enum rat;      /* RATCM_RAT_ENUM */
} mmcm_rat_ind_struct;

typedef struct {
    // When 4G23 irat_type==IR_TYPE_SEARCH, SM need to queue ESM transferred context until receiving MSG_ID_GMMSM_RAT_IND. 
    // SM only need to process this message when __LTE_RAT__ is on because this message is only used when 4G23 IR_TYPE_SEARCH interRAT
    // in 2G single mode project or 23G dual mode project, SM will drop this message
    LOCAL_PARA_HDR
    rat_enum rat;      /* RATCM_RAT_ENUM */
    kal_bool is_suitable_cell;
} gmmsm_rat_ind_struct;


typedef struct {
    LOCAL_PARA_HDR
    plmn_id_struct plmn_id; 
} mmcm_plmn_info_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
} mmcm_dummy_local_para_struct;

typedef mmcm_est_ind_struct mmcc_est_ind_struct;
typedef mmcm_est_cnf_struct mmcc_est_cnf_struct;
typedef mmcm_data_ind_struct mmcc_data_ind_struct;
typedef mmcm_est_intr_struct mmcc_est_intr_struct;
typedef mmcm_est_rej_struct mmcc_est_rej_struct;
typedef mmcm_sync_ind_struct mmcc_sync_ind_struct;

typedef mmcm_rat_ind_struct mmcc_rat_ind_struct;

typedef mmcm_plmn_info_ind_struct mmcc_plmn_info_ind_struct;

typedef mmcm_est_ind_struct mmss_est_ind_struct;
typedef mmcm_est_cnf_struct mmss_est_cnf_struct;
typedef mmcm_data_ind_struct mmss_data_ind_struct;
typedef mmcm_rel_ind_struct mmss_rel_ind_struct;
typedef mmcm_est_intr_struct mmss_est_intr_struct;
typedef mmcm_est_rej_struct mmss_est_rej_struct;
typedef mmcm_rat_ind_struct mmss_rat_ind_struct;


typedef mmcm_est_ind_struct mmsms_est_ind_struct;
typedef mmcm_est_cnf_struct mmsms_est_cnf_struct;
typedef mmcm_data_ind_struct mmsms_data_ind_struct;
typedef mmcm_rel_ind_struct mmsms_rel_ind_struct;
typedef mmcm_est_intr_struct mmsms_est_intr_struct;
typedef mmcm_est_rej_struct mmsms_est_rej_struct;
#endif 


