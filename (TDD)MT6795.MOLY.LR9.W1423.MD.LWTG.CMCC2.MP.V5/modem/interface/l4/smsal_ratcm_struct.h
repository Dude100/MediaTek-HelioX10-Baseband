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
 *   smsal_ratcm_struct.h
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

#ifndef SMSAL_RATCM_STRUCT_H
#define SMSAL_RATCM_STRUCT_H

#include "ps_public_enum.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"

typedef struct {
    LOCAL_PARA_HDR   
    kal_bool is_cbs_required;
} smsal_ratcm_cbch_req_struct;

typedef struct {
    LOCAL_PARA_HDR   
    kal_uint16 cbmi[CB_MAX_MSG_CBMI_NUM];
    kal_uint16 cbmid[CB_MAX_MSG_CBMID_NUM];
    kal_uint16 cbmir[CB_MAX_MSG_CBMIR_NUM];
    kal_uint16 dcs[CB_MAX_LANG_NUM];
    kal_bool is_all_language_on;
    l4c_cb_set_type_enum set_type;
} smsal_ratcm_cb_update_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 rat; 
    kal_uint16 msgid;
    kal_uint16 serial_num;
    kal_uint8 dcs;
    kal_bool is_mids;
    kal_uint8 page_no;
    kal_uint8 total_pages;
    kal_uint8 page_data[CB_MAX_DATA_NUM_PER_PAGE];

#ifdef __GSM_RAT__
    kal_uint8 valid_blk_num; /* for last bit */
#endif
} smsal_ratcm_cb_data_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 geography_type;
} smsal_ratcm_cb_gs_change_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint16 mid;
    kal_uint16 sn;
} smsal_ratcm_cb_msg_removal_req_struct;

#endif /* SMSAL_RATCM_STRUCT_H */
