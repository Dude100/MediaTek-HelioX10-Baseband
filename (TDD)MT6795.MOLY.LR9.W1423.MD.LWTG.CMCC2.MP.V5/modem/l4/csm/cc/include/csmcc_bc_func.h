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
 *	csmcc_bc_func.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for bearer capability compatibility checking
 *   and negotiation functions declaration used in CSM(CC) module.
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

#ifndef _CSMCC_BC_FUNC_H
#define _CSMCC_BC_FUNC_H

#include "csmcc_bc_types.h"
//#include "kal_non_specific_general_types.h"
#include "csmcc_types.h"
#include "csmcc_common_enums.h"
#include "mncc_struct.h"
#include "kal_general_types.h"

typedef kal_uint8 (*func_app_bc_ptr)(csmcc_bc_struct * , kal_uint8 *);
typedef kal_uint8 (*func_peer_bc_ptr)(kal_uint8 *, csmcc_bc_struct *);
typedef kal_uint8 (*func_app_llc_ptr)(csmcc_llc_struct * ,kal_uint8 *);
typedef kal_uint8 (*func_peer_llc_ptr)(kal_uint8 * , csmcc_llc_struct *);

extern csmcc_ret_t 
csmcc_fill_bc(kal_uint8 call_id, 
	      kal_uint8 src_id, 
	      csmcc_call_type_enum call_type, 
	      csmcc_csd_prof_rate_enum profile_type);

extern void
csmcc_fill_llc(csmcc_llc_struct *llc_ptr,
               csmcc_bc_struct *app_bc_ptr);
                     
extern kal_bool 
csmcc_is_mo_call_compat(mncc_call_proc_ind_struct* call_proc_ind_ptr);
                                           
extern kal_bool 
csmcc_is_mt_call_compat(kal_uint8 call_id,
                        mncc_setup_ind_struct *setup_ind_ptr);
                                 
extern kal_bool 
csmcc_is_ccbs_call_compat(kal_uint8 call_id,
                          mncc_ccbs_est_ind_struct *ccbs_est_ind_ptr);

extern kal_bool 
csmcc_is_bc_compat(csmcc_bc_struct *bc1,
                   csmcc_bc_struct *bc2);

extern void
csmcc_form_peer_bc(mncc_bc_struct *peer_bc_ptr,
                   csmcc_bc_struct *app_bc_ptr);

extern void
csmcc_form_peer_llc(mncc_llc_struct *peer_bc_ptr,
                    csmcc_llc_struct *app_llc_ptr);

extern void
csmcc_form_peer_hlc(mncc_hlc_struct *peer_bc_ptr,
                    csmcc_hlc_struct *app_hlc_ptr);

extern void
csmcc_form_app_bc(csmcc_bc_struct *app_bc_ptr,
                  mncc_bc_struct *peer_bc_ptr);

extern void
csmcc_form_app_llc(csmcc_llc_struct *app_llc_ptr,
                mncc_llc_struct *peer_llc_ptr);

extern void
csmcc_form_app_hlc(csmcc_hlc_struct *app_hlc_ptr,
                mncc_hlc_struct *peer_hlc_ptr);

#ifdef __SAT__

extern kal_bool
csmcc_is_sat_call_compat(kal_uint8 call_id, 
                         kal_uint8 *ccp1_ptr,
                         kal_uint8 size_of_ccp1,
                         kal_uint8 *ccp2_ptr,
                         kal_uint8 size_of_ccp2,
                         kal_bool  is_bc_repeat_ind_avail,
                         kal_uint8 bc_repeat_ind);

extern void
csmcc_form_peer_ccp(mncc_bc_struct *peer_bc_ptr,
                    kal_uint8 *ccp_ptr,
                    kal_uint8 size_of_ccp);

extern void
csmcc_form_app_ccp(csmcc_bc_struct *app_bc_ptr,
                   kal_uint8* ccp_ptr,
                   kal_uint8 size_of_ccp);

#endif /* __SAT__ */

#ifdef __REL4__
extern void 
csmcc_form_peer_supported_codec(mncc_supported_codec_struct *peer_scl_ptr);

#endif /* (__REL4__)*/


#ifdef __REL5__
extern csmcc_call_type_enum 
csmcc_deduce_bc_from_peer_backup(csmcc_bc_struct *bc_ptr); 
#endif

#ifdef __VIDEO_CALL_SUPPORT__
extern void 
csmcc_fill_video_call_llc(csmcc_llc_struct *llc_ptr,csmcc_bc_struct *app_bc_ptr);                     

extern void 
csmcc_fill_video_bc_param(csmcc_data_bc_param_struct *data_bc_param_ptr);

extern void 
csmcc_fill_video_bc_ie(csmcc_bc_struct *bc);
#endif

#endif /* _CSMCC_BC_FUNC_H */

