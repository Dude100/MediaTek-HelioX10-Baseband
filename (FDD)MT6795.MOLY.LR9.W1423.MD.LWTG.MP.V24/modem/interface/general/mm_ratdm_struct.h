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
 *   mm_ratdm_struct.h
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

#ifndef MM_RATDM_STRUCT_H
#define MM_RATDM_STRUCT_H

#include "kal_general_types.h"
#include "l3_inc_enums.h"
#include "mmcm_enums.h"

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 no_of_valid_entries;
    kal_uint8 nsapi_list[11];
    kal_uint8 sequence_list[11];
} mm_ratdm_sequence_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 no_of_valid_entries;
    kal_uint8 nsapi_list[11];
    kal_uint8 sequence_list[11];
} mm_ratdm_sequence_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;    
    traffic_class_enum traffic_class; /* tTrafficClass */
#ifdef __REL7__
    kal_uint16 ul_data_status; /* 24.008 CR1053 R7: Indicate which preserved PDP contexts have uplink data pending. */
#endif
} mm_ratdm_reestablish_rab_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    gmmcm_result_enum result; /* gmmcm_result_enum */
} mm_ratdm_reestablish_rab_rsp_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    gmmcm_result_enum result; /* gmmcm_result_enum */
} mm_ratdm_send_user_data_rsp_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
} mm_ratdm_reestablish_rab_ready_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
} mm_ratdm_rab_release_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    traffic_class_enum traffic_class; /* tTrafficClass */
    kal_uint16 ul_data_status;
    gmmcm_service_proc_cause_enum cause; /* gmmcm_service_proc_cause_enum */
} mm_ratdm_service_proc_ind_struct;

#endif /* MM_RATDM_STRUCT_H */
