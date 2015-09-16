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
 *
 * Filename:
 * ---------
 *	llc_flowctrl.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains declarations of functions and enumerations for LLC-specific flow control.
 *
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/

#ifndef _LLC_FLOWCTRL_H
#define _LLC_FLOWCTRL_H

/*****************
Include Statements
******************/
//#include "kal_non_specific_general_types.h"
#include "flc2_config.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"

/************************
Macros Without Parameters 
*************************/

/*****************
Enums Without Tags 
******************/

/***************
Type Definitions 
****************/

typedef enum {
    LLC_GPRS_ACK_DATA,
    LLC_GPRS_UNACK_DATA,
    LLC_GPRS_SUPERVISORY_DATA
} llc_flc2_data_type_enum;

typedef enum {
    LLC_GPRS_UL,
    LLC_GPRS_DL,
    LLC_GPRS_UL_DL //Jeff: Need to discuss
} llc_flc2_dir_enum;

typedef enum {
    LLC_GPRS_FLC_RNR_TRIGGER,
    LLC_GPRS_FLC_RR_TRIGGER
} llc_flc2_stack_trigger_enum;

typedef struct {
   LOCAL_PARA_HDR
   kal_uint8 sapi;
   kal_uint32 blocked_mem_size;
} llc_flc2_rr_rnr_xid_struct;


typedef llc_flc2_rr_rnr_xid_struct llsnd_rnr_stop_struct;
typedef llc_flc2_rr_rnr_xid_struct rlc_llc_rnr_trigger_struct;

/********
Constants 
*********/

/*********************
Macros With Parameters 
**********************/

/***************************
Exported Function Prototypes 
****************************/

flc2_pool_id_enum llc_get_flc2_pool_id_enum_val (kal_uint8 sapi,
                                                 llc_flc2_data_type_enum data_type,
                                                 llc_flc2_dir_enum dir);

flc2_pool_id_enum llc_get_flc2_pool_id_enum_from_nsapi (kal_uint8 nsapi);

void llc_flc2_rnr_rr_ind(flc2_pool_id_enum pool_id, llc_flc2_stack_trigger_enum action_req);

/* Roebrt :move to FLC2 */
/*
extern void flc2_cipher_callback(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id);
*/

extern void llc_flc2_pspdu_ack_dl_pool_low_threshold_hit(flc2_pool_id_enum pool_id);

extern void llc_flc2_pspdu_ack_dl_pool_high_threshold_hit(flc2_pool_id_enum pool_id);

flc2_pool_id_enum llc_get_flc2_pool_id_enum_val_by_nsapi (kal_uint8 nsapi, llc_flc2_dir_enum dir);

#endif /* _LLC_FLOWCTRL_H */
