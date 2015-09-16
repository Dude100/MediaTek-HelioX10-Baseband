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
 *   rr2lapdm_struct.h
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

#ifndef _RR2LAPDM_STRUCT_H
#define _RR2LAPDM_STRUCT_H

/* add RHR */
#if 0
/* under construction !*/
#endif
#include "rmc_lapdm_interface.h"
#include "l3_inc_enums.h" /* MSBB by Rachel */
#include "kal_general_types.h"

typedef struct
{
    kal_bool is_dtx_updated;
    kal_uint8 is_dtx_tch_h;
    kal_uint8 is_dtx_tch_f;
}
rr_dtx_update_struct;

typedef struct
{
    kal_bool is_maxrlc_updated;
    kal_uint16 max_rlcvalue; 
}
rr_maxrlc_update_struct;

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    kal_uint8 l2header;
    channel_type_enum channel_type;
} rr_lapdm_unitdata_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    LAPDM_ESTB_MODE estb_mode;
    channel_type_enum channel_type;
    rr_maxrlc_update_struct maxrlc_update;
} rr_lapdm_estb_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    channel_type_enum channel_type;
    kal_uint8 half_to_full;
} rr_lapdm_sus_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    channel_type_enum channel_type;
} rr_lapdm_resume_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    channel_type_enum channel_type;
} rr_lapdm_recon_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    kal_uint8 priority;
    channel_type_enum channel_type;
/* brwang, 06/04/08, [MAUI_00185915] { */
    kal_uint8 mui;
/* brwang, 06/04/08, [MAUI_00185915] } */    
} rr_lapdm_data_req_struct;

#ifdef __AGPS_CONTROL_PLANE__
typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    kal_uint8 priority;
    channel_type_enum channel_type;
    lapdm_layer3_message_type_enum segment_type;
    kal_uint8 mui;
} rr_lapdm_app_data_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool need_clear;
} rr_lapdm_clear_app_queue_req_struct;
#endif /* __AGPS_CONTROL_PLANE__ */

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    kal_uint8 release_mode;
    channel_type_enum channel_type;
} rr_lapdm_rel_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    channel_type_enum channel_type;
} rr_lapdm_mdl_rel_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    rr_dtx_update_struct dtx_update;
    rr_maxrlc_update_struct maxrlc_update;
} rr_lapdm_cell_option_update_req_struct;


typedef struct {
    LOCAL_PARA_HDR
    lapdm_sapi_header sap_id;
    channel_type_enum channel_type;
    rr_maxrlc_update_struct maxrlc_update;    
} rr_lapdm_inter_rat_est_req_struct;

#endif


