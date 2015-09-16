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
 *   as_access_sem_funcs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * Merge LTE GEMINI to MOLY
 *
 * removed!
 * removed!
 * Fix a syntax error because the original assigner who forgot to merge this.
 *
 * removed!
 * removed!
 * Part 2 - Other common files for Multimode
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
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * 
 ******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _AS_ACCESS_SEM_FUNCS_H_
#define _AS_ACCESS_SEM_FUNCS_H_

#ifdef __GEMINI__

/* Nancy 20101005: Suggest Add for RHR */
#include "rsvas_enum.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_general_types.h"

#ifndef _RSVAS_ENUM_H
#error "`rsvas_enum.h' must be included before `as_access_sem_funcs.h'"
#endif 

#include "as_access_sem_context.h"

/* These two functions only located at RR1 */
extern void as_create_access_sem(void);

extern kal_bool as_occupy_access_sem(as_access_sem_owner_enum owner);

extern void as_release_access_sem(void);

extern kal_bool as_transfer_access_sem_owner(as_access_sem_owner_enum owner);

extern as_access_sem_owner_enum as_query_access_sem_owner(void);

#ifndef __MTK_TARGET__
extern void as_service_sem_reset(void);
extern void as_service_occupy( const rsvas_service_type_enum service_type);
extern void as_service_release(const rsvas_service_type_enum service_type);
extern void as_set_sem_owner(const rsvas_id_enum new_sem_owner);

#ifdef __GEMINI_PREEMPT_PEER_SERVICE__
extern void as_set_sem_service_domain(const rsvas_service_type_enum new_service_domain);
#endif /*__GEMINI_PREEMPT_PEER_SERVICE__*/

extern void as_set_idle_service_owner(const rsvas_id_enum new_idle_service_owner);
extern rsvas_service_type_enum as_service_sem_domain_query(void);

#endif /* __MTK_TARGET__ */
extern kal_bool as_service_sem_occupy(const module_type mod_src, const rsvas_id_enum id, const rsvas_service_type_enum service_type);

extern void as_service_sem_release(const module_type mod_src, const rsvas_id_enum id, const rsvas_service_type_enum service_type);

extern kal_bool as_service_sem_transfer(const module_type mod_src, const rsvas_id_enum new_id, const rsvas_service_type_enum reserve_domain_service_after_transfer);

extern rsvas_id_enum as_service_sem_query(void);

rsvas_id_enum as_idle_service_owner_query(void);

extern kal_bool is_as_service_this_sim_occupy(const rsvas_sim_enum sim_index);

#ifdef __UMTS_RAT__
#if !defined(__MTK_TARGET__) && !defined(__UE_SIMULATOR__)
#ifdef __GEMINI_PREEMPT_PEER_SERVICE__
extern void as_set_sem_service_domain(const rsvas_service_type_enum new_service_domain);
#endif
#endif
#ifdef __GEMINI_PREEMPT_PEER_SERVICE__
extern kal_bool is_as_service_occupy_this_domain(const rsvas_service_type_enum service_type);
#endif
#endif


#ifdef __ETWS_SUPPORT__
#if !defined(__MTK_TARGET__) && !defined(__UE_SIMULATOR__)
extern void as_set_etws_owner(const rsvas_id_enum new_etws_owner);
#endif
#endif

#if defined(__ETWS_SUPPORT__)||defined(__LTE_RAT__)
extern kal_bool as_update_etws_channel_priority(const module_type mod_src, const rsvas_id_enum id, const kal_bool is_protect_req);

extern rsvas_id_enum as_etws_owner_query(void);
#endif /* __ETWS_SUPPORT__ || __LTE_RAT__*/


#endif /* __GEMINI__ */

#endif /* _AS_ACCESS_SEM_FUNCS_H_ */

