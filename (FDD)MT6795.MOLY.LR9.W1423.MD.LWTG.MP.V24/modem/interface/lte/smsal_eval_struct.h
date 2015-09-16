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
 *   smsal_eval_struct.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   message and common structure definition between SMSAL and EVAL module
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
 * 	.
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * MOLY_CBr to MOLY.
 *
 * removed!
 * removed!
 * [EVAL] Add EVAL related interfaces and common strust
 ****************************************************************************/


#ifndef  SMSAL_EVAL_STRUCT_INC
#define  SMSAL_EVAL_STRUCT_INC

#include "l3_inc_enums.h"


/***** message structure definition *****/
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool                    is_cbs_required;

} smsal_eval_cbch_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                  cbmi[CB_MAX_MSG_CBMI_NUM];
    kal_uint16                  cbmid[CB_MAX_MSG_CBMID_NUM];
    kal_uint16                  cbmir[CB_MAX_MSG_CBMIR_NUM];
    kal_uint16                  dcs[CB_MAX_LANG_NUM];
    kal_bool                    is_all_language_on;

} smsal_eval_cb_update_req_struct;


typedef struct
{
    LOCAL_PARA_HDR

} smsal_eval_cb_reconfig_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8                   geography_type;

} smsal_eval_cb_gs_change_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16                  message_id;
    kal_uint16                  serial_number;
    kal_uint8                   data_coding_scheme;

} smsal_eval_cb_data_ind_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint16 message_id;          
    kal_uint16 serial_number;        
} smsal_eval_cb_msg_removal_req_struct;


#endif   /* ----- #ifndef SMSAL_EVAL_STRUCT_INC ----- */

