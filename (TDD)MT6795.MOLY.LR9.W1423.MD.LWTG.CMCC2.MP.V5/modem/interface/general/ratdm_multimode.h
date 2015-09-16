/******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * --------------------------------------------------------
 *   ratdm_multimode.h
 *
 * Project:
 * --------------------------------------------------------
 *
 *
 * Description:
 * --------------------------------------------------------
 *
 *
 * Author:
 * --------------------------------------------------------
 * -------
 *
 * --------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 * 
 * removed!
 * removed!
 * .
 * 
 * removed!
 * removed!
 * .
 *
 *
 *
 ******************************************************************************/

#ifndef _RATDM_MULTIMODE_H
#define _RATDM_MULTIMODE_H

#ifndef __USE_LEGACY_23G_DATAPATH__

#include "ratdm_shaq_application_api.h"
#include "kal_general_types.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h", "stack_msgs.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h"       	/* Task message communiction */
#include "l3_inc_local.h"

#ifdef __GEMINI__
#include "sim_common_enums.h"
#endif

#include "mmi_l3_enums.h"
#include "kal_public_api.h"
#include "ps_ratdm_struct.h"
#include "global_def.h"

/* Buffer Management */
#include "flc2_ent_functions.h"

#include "l3_inc_enums.h"
#include "mcd_l3_inc_struct.h"

#ifdef __DIALUP_GPRS_COUNTER_SUPPORT__
#include "l4c_ratdm_struct.h"
#endif

#ifdef __UMTS_RAT__
#include "uas_common_enums.h"
#endif // ~ #ifdef __UMTS_RAT__

void ratdm_multimode_ps_dscr_data_ind_hdlr(ilm_struct *ilm_ptr);
extern void (*ratdm_multimode_hook_ul_dest_cb)(void);
extern void (*ratdm_multimode_ug_ready_ind_cb)(kal_uint8 nsapi);
extern void (*ratdm_multimode_forward_from_ug_data_cb)(kal_uint8 nsapi, ratdm_ps_data_req_struct * pPeer, flc2_pool_id_enum pool_id, SHAQ_ENQUEUE_WHICH_QUEUE enqueue_decision);

kal_uint8 ratdm_multimode_assign_pcid(kal_uint8 nsapi);
kal_uint8 ratdm_multimode_remove_pcid(kal_uint8 nsapi);
void ratdm_multimode_ug_data_req_hdlr(kal_uint8 nsapi, ratdm_ps_data_req_struct * pPeer, flc2_pool_id_enum pool_id, SHAQ_ENQUEUE_WHICH_QUEUE enqueue_decision);
kal_bool ratdm_multimode_init(void);
void ratdm_multimode_on_ilm(ilm_struct *ilm);
kal_bool ratdm_multimode_reset(void);
void ratdm_sm_update_max_traffic_class_req(ilm_struct *ilm_ptr);
void ratdm_multimode_forward_npdu_queue_by_nsapi(kal_uint8 nsapi);
void ratdm_multimode_check_forward_npdu_queue_end(void);
void ratdm_ps_switch_to_lte(void);

#define NSAPI_NULL     (0xff)   // For roll-back end indication
#endif //__USE_LEGACY_23G_DATAPATH__

#endif /* _RATDM_MULTIMODE_H */
