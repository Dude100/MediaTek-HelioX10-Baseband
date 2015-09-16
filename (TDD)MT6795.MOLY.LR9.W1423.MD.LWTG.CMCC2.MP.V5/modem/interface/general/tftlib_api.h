/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   tftlib_api.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   TFT library API header file
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * TFTLIB check-in related interface
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * [TFTLIB] Check-in related changes
 *
 * removed!
 * removed!
 * Check-in TFTLIB part
 *
 * removed!
 * removed!
 * 	Check-in TFTLIB part
 *
 * removed!
 * removed!
 * check in TFTLIB related change
 *
 * removed!
 * removed!
 * add trace error/warning & work around
 *
 * removed!
 * removed!
 * TFTLIB modification for AT+CGTFT interpretation (support both difference set & full set)
 *
 * removed!
 * removed!
 * [Joe] TFTLIB part is check in done.
 ****************************************************************************/

#ifndef TFTLIB_API_H_
#define TFTLIB_API_H_


#include "tftlib_common_struct.h"
#include "tftlib_common_enum.h"
#include "l3_inc_enums.h"


/* TFT Library API for SM/ESM */

tft_validate_result_enum    tftlib_tft_decode(
#if defined (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
                                              kal_uint32            sim_indx,
#endif /* (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__) */
                                              kal_uint8             bearer_id,
                                              tft_info_struct       *tft_ptr,
                                              tft_pdu_struct        *tft_raw_ptr,
                                              bearer_type_enum      bearer_type,
                                              tft_proc_dir_enum     proc_dir, // 20131106_Joe: Added to support 2/3G 'MS/NW' 
                                              tft_bearer_act_enum   bearer_act,
                                              bcm_enum              bcm,
                                              rat_ind_enum          rat);

kal_bool                    tftlib_tft_encode(
#if defined (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
                                              kal_uint32        sim_indx,
#endif /* (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__) */
                                              tft_pdu_struct    *tft_raw_ptr, /*dst*/
                                              tft_info_struct   *tft_ptr);    /*src*/

kal_bool                    tftlib_tft_validate(
#if defined (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
                                                kal_uint32          sim_indx,
#endif /* (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__) */    
                                                kal_uint8           bearer_id,
                                                bearer_type_enum    bearer_type,
                                                bcm_enum            bcm, // 20131106_Joe: Added to support 2/3G 'MS/NW' 
                                                rat_ind_enum        rat);

kal_bool                    tftlib_tft_dir_extract(
#if defined (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
                                                   kal_uint32          sim_indx,
#endif /* (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__) */
                                                   tft_info_struct     *src_tft_ptr,
                                                   tft_info_struct     *dst_tft_ptr,
                                                   pf_direction_enum   pf_dir);

kal_bool                    tftlib_tft_own_enty_exst_chk(
#if defined (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
                                                         kal_uint32            sim_indx,
#endif /* (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__) */    
                                                         kal_uint8             bearer_id,
                                                         pf_own_entity_enum    pf_own_entity);

/* TFT Library API for TCM */

kal_bool                    tftlib_set_applied_tft(
#if defined (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
                                                   kal_uint32                   sim_indx,
#endif /* (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__) */   
                                                   kal_uint8                    cid,
                                                   tft_info_struct              *tft_ptr,
                                                   tft_proc_dir_enum            proc_dir, // 20131106_Joe: Added to support 2/3G 'MS/NW'
                                                   tft_bearer_act_enum          bearer_act,
                                                   pkt_filter_act_list_struct   *pf_act_list,
                                                   tft_deact_bearer_list_struct *deact_bearer_list,
                                                   rat_ind_enum                 rat); // TODO: OPTIMIZE stack size
                                                   
kal_bool                    tftlib_compose_tft_to_nw(
#if defined (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
                                                     kal_uint32             sim_indx,
#endif /* (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__) */      
                                                     kal_uint8              cid,
                                                     tft_info_struct        *tft_ptr,
                                                     tft_compose_type_enum  tft_compose_type,
                                                     bearer_type_enum       bearer_type,
                                                     tft_bearer_act_enum    bearer_act,
                                                     bcm_enum               bcm,
                                                     rat_ind_enum           rat);

void                        tftlib_del_tft(
#if defined (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
                                           kal_uint32           sim_indx,
#endif /* (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__) */    
                                           kal_uint8            cid,
                                           tft_ctxt_type_enum   tft_ctxt_type); // +CGTFT (undefine-mode)
                                           
kal_bool                    tftlib_chk_bearer_reusability(
#if defined (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
                                                          kal_uint32        sim_indx,
#endif /* (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__) */    
                                                          kal_uint8         cid,
                                                          bearer_type_enum  bearer_type,
                                                          rat_ind_enum      rat);


/* TFT Library API for L4C */

kal_bool                    tftlib_set_user_defined_tft(
#if defined (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
                                                        kal_uint32      sim_indx,
#endif /* (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__) */
                                                        kal_uint8       cid,
                                                        tft_info_struct *tft_ptr,
                                                        rat_ind_enum    rat); // +CGTFT (set-mode)
                                                        
kal_bool                    tftlib_get_user_defined_tft(
#if defined (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
                                                        kal_uint32      sim_indx,
#endif /* (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__) */    
                                                        kal_uint8       cid,
                                                        tft_info_struct *tft_ptr); // +CGTFT (read-mode)
                                                        
kal_bool                    tftlib_get_applied_tft(
#if defined (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
                                                   kal_uint32       sim_indx,
#endif /* (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__) */    

                                                   kal_uint8        cid,
                                                   tft_info_struct  *tft_ptr); // +CGTFTRDP
// TODO: OPTIMIZE stack size
                            
kal_bool                    tftlib_set_usr_delpf(
#if defined (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
                                                 kal_uint32     sim_indx,
#endif /* (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__) */    

                                                 kal_uint8      cid, 
                                                 kal_uint8      pf_id,
                                                 rat_ind_enum   rat); // +EGDELPF (set-mode)
                                                 
kal_int32                   tftlib_get_usr_delpf(
#if defined (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
                                                 kal_uint32 sim_indx,
#endif /* (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__) */        
                                                 kal_uint8  cid, 
                                                 kal_uint8  *pf_list); // +EGDELPF (read-mode)
                                                 
void                        tftlib_clear_usr_delpf(
#if defined (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
                                                   kal_uint32   sim_indx,
#endif /* (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__) */    
                                                   kal_uint8    cid); // +EGDELPF (undefine-mode)

kal_bool                    tftlib_set_usr_lnkpf(
#if defined (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
                                                 kal_uint32     sim_indx,
#endif /* (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__) */
                                                 kal_uint8      cid,
                                                 kal_uint8      lnkpf_id,
                                                 rat_ind_enum   rat); // +EGLNKPF (set-mode)
                                                 
kal_int32                   tftlib_get_usr_lnkpf(
#if defined (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
                                                 kal_uint32 sim_indx,
#endif /* (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__) */    
                                                 kal_uint8  cid,
                                                 kal_uint8  *lnkpf_list); // +EGLNKPF (read-mode)
                                                 
void                        tftlib_clear_usr_lnkpf(
#if defined (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__)
                                                   kal_uint32   sim_indx,
#endif /* (__SGLTE__) || (__GEMINI__) || (__SGLTE_DSDS__) */    
                                                   kal_uint8    cid); // +EGLNKPF (undefine-mode)

#endif /* TFTLIB_API_H_ */
