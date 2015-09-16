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
 *	csmcc_crss_proc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for call related SS procedure used in CSM(CC) module.
 *
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

#ifndef _CSMCC_CRSS_PROC_H
#define _CSMCC_CRSS_PROC_H

#include "csmcc_types.h"
//#include "kal_non_specific_general_types.h"
#include "kal_general_types.h"

extern csmcc_ret_t 
csmcc_accept_other_call(kal_uint8 accept_type,
                        kal_uint8 accept_call_id);
                                         
extern csmcc_ret_t 
csmcc_hold_active_call(kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_retrieve_held_call(kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_alternate_two_call(kal_uint8 active_call_id,
                         kal_uint8 held_call_id);
                                          
extern csmcc_ret_t 
csmcc_rel_held_or_udub(kal_bool need_to_check_udub, kal_uint8 src_id);

#ifdef __CALL_REJECT__
extern csmcc_ret_t 
csmcc_rel_call_reject( kal_uint8 src_id);
#endif 


extern csmcc_ret_t 
csmcc_rel_active_and_accept(kal_bool need_accept, kal_uint8 *accept_req, kal_uint8 *accept_call_id);

extern csmcc_ret_t 
csmcc_rel_specific_active_call(kal_uint8 call_id);

extern csmcc_ret_t 
csmcc_rel_specific_call(kal_uint8 call_id);

#if defined(__VIDEO_CALL_SUPPORT__)  
extern csmcc_ret_t 
csmcc_reject_vt_by_specific_cause(kal_uint8 call_id);
#endif

extern csmcc_ret_t 
csmcc_hold_active_and_accept(kal_uint8 *accept_req, kal_uint8 *accept_call_id, kal_bool need_accept);

extern csmcc_ret_t 
csmcc_hold_active_except_specific_call(kal_uint8 call_id, kal_uint8 *accept_req, kal_uint8 *accept_call_id);

extern csmcc_ret_t 
csmcc_add_held_call(void);

extern csmcc_ret_t 
csmcc_explicit_call_transfer(void);

#ifdef __CCBS_SUPPORT__
extern csmcc_ret_t 
csmcc_activate_ccbs_call(kal_uint8 *call_id);
#endif /*__CCBS_SUPPORT__*/

extern csmcc_ret_t
csmcc_rel_all_except_waiting_call(void);

extern csmcc_ret_t csmcc_rel_all(kal_bool need_rel_sat_idle_call);

#endif /* _CSMCC_CRSS_PROC_H */

