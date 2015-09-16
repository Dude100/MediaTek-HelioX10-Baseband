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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   lapdm2rr_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
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
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _LAPDM2RR_STRUCT_H
#define _LAPDM2RR_STRUCT_H

/* add RHR */
#include "rmc_lapdm_interface.h"
#include "l3_inc_enums.h" /* MSBB by Rachel */
#include "kal_general_types.h"

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    channel_type_enum channel_type;
} lapdm_rr_unitdata_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    LAPDM_ESTB_MODE estb_mode;
    channel_type_enum channel_type;
} lapdm_rr_estb_conf_struct;

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    LAPDM_ESTB_MODE estb_mode;
    channel_type_enum channel_type;
} lapdm_rr_estb_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    channel_type_enum channel_type;
} lapdm_rr_sus_conf_struct;

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    LAPDM_ESTB_MODE estb_mode;
    channel_type_enum channel_type;
} lapdm_rr_resume_conf_struct;

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    LAPDM_ESTB_MODE estb_mode;
    channel_type_enum channel_type;
} lapdm_rr_recon_conf_struct;

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    channel_type_enum channel_type;
} lapdm_rr_data_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    kal_uint8 release_mode;
    LAPDM_ERROR_CAUSE error_cause;
    channel_type_enum channel_type;
} lapdm_rr_rel_conf_struct;

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    kal_uint8 release_mode;
    LAPDM_ERROR_CAUSE error_cause;
    channel_type_enum channel_type;
} lapdm_rr_rel_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    LAPDM_ERROR_CAUSE error_cause;
    channel_type_enum channel_type;
} lapdm_rr_error_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    kal_uint8 ch_mode;
    channel_type_enum ch_type;
    kal_uint8 tch_type;
} lapdm_ul_data_req_struct;

typedef struct {
    LOCAL_PARA_HDR
	 kal_bool  valid;
   lapdm_sapi_header sap_id;
   channel_type_enum ch_type;
	 kal_bool is_bad_frame;
	 kal_uint8 frame_type;
    kal_bool bit_cr;
    kal_bool bit_m;
    kal_bool bit_pf;
    kal_uint8 send_seq_num; /*ripple: used to store NS of down link data*/
    kal_uint8 recv_seq_num;
    kal_uint16 info_len;
} lapdm_downlink_ind_struct;

/* brwang, 06/04/08, [MAUI_00185915] { */    
typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sapi;
    kal_uint8 mui;
    kal_bool    is_successful;
#ifdef __AGPS_CONTROL_PLANE__
    lapdm_layer3_message_type_enum segment_type;
#endif /* __AGPS_CONTROL_PLANE__ */     
} lapdm_rr_data_conf_struct;
/* brwang, 06/04/08, [MAUI_00185915] } */    

#endif


