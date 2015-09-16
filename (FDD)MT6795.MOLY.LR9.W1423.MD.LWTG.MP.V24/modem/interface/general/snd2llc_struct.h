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
 *  snd2llc_struct.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file describes the common structure of SNDCP and LLC.  
 *
 * Author:
 * -------
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

// Poying: 20101105. RHR.
//------------------------------ suggest Add ------------------------------    
#include "kal_general_types.h"
#include "kal_public_defs.h"    
#include "mcd_l3_inc_gprs_struct.h"
#include "flc2_config.h"

#ifndef _SND2LLC_STRUCT_H
#define _SND2LLC_STRUCT_H

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_uint8 local; /* LOCAL*/
    kal_uint32 tlli; /* TLLI*/
} ll_release_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_uint32 tlli; /* TLLI*/
    kal_uint16 req_n201u;  //erica 20070112
} ll_xid_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_uint32 tlli; /* TLLI*/
} ll_xid_res_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_uint32 tlli; /* TLLI*/
} ll_establish_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_uint32 tlli; /* TLLI*/
} ll_establish_res_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_uint8 radio_priority; /* RADIO PRIORITY*/
    kal_uint16 reference; /* SNDLLC REFERENCE TYPE*/
    flc2_pool_id_enum pspdu_ul_pool_id ;
    kal_uint32 tlli; /* TLLI*/
#ifdef __R99__
    kal_uint8 pfi;  /* PFI */
#endif    
    concise_qos_struct qos_param; /* QOS STRUCTURE*/
} ll_data_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
    kal_uint8 is_ack_mode;
} ll_sapi_act_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 sapi;
} ll_sapi_deact_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool is_all_flush;
    kal_bool are_two_pdp_same_qos;    
    kal_uint8 radio_priority; /* LLC shall decrement by onw when sent to RLC. */
    concise_qos_struct qos_param;    
    kal_bool is_need_cnf;
} llsnd_flush_req_struct;

typedef ll_release_req_struct llsnd_release_req_struct;
typedef ll_xid_req_struct llsnd_xid_req_struct;
typedef ll_xid_res_struct llsnd_xid_res_struct;
typedef ll_establish_req_struct llsnd_establish_req_struct;
typedef ll_establish_res_struct llsnd_establish_res_struct;
typedef ll_data_req_struct llsnd_data_req_struct;
typedef ll_sapi_act_req_struct llsnd_sapi_act_req_struct;
typedef ll_sapi_deact_req_struct llsnd_sapi_deact_req_struct;

#endif 


