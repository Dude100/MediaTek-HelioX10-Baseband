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
 *   ltm.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *   
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * adjust interface usage.
 ****************************************************************************/
/*
 * =====================================================================================
 *
 *       Filename:  ltm.h
 *
 *    Description:  LTM (LTE traffic manager exported header file)
 *
 *        Created:  2011/10/28 ¤U¤È 07:03:55
 *        Author:  mtk01641 (moja)
 * =====================================================================================
 */
#ifndef  LTM_INC
#define  LTM_INC

#include "kal_public_api.h"
#include "ratcommon.h"

/*
 * lte tick source notify callback prototype.
 * is_lte_tick: KAL_TRUE - has LTE tick.
 *              KAL_FLAE - may no LTE tick.
 */
typedef void (*ltm_multi_notify_lte_tick_f)(kal_bool is_lte_tick);

/**
 * @brief ltm_multiinit
 * Init LTM module.
 *
 * @return TRUE  
 */
kal_bool ltm_multi_init(void);

/**
 * @brief ltm_multiinit
 * Reset LTM module.
 *
 * @return TRUE  
 */
kal_bool ltm_multi_reset(void);

/**
 * @brief ltm_multion_ilm 
 * Receive ILM message
 *
 * @param ilm
 */
void ltm_multi_on_ilm(ilm_struct *p_ilm);

/**
 * @brief ltm_multircv_ul_sdu 
 * Receive UL SDUs. UL SDU are GPD list.
 *
 * @param ebi    EPSB ID
 * @param p_head SDU list head. (GPD based)
 * @param p_tail SDU list tail. (GPD based)
 */
void ltm_multi_rcv_ul_sdu(kal_uint32 ebi, ratcmn_ul_sdu_t *p_sdus);

/**
 * @brief ltm_multireg_cbk_notify_lte_tick
 * Register callback function.
 * For get if there is a LTE tick source.
 *
 * @param pf_notify callback function.
 */
void ltm_multi_reg_cbk_notify_lte_tick(ltm_multi_notify_lte_tick_f pf_notify);

/**
 * @brief ltm_multireg_cbk_dlvr_dl_sdu 
 * Register callback for deliver DL SDUs.
 *
 * @param pf_dlvr_sdu
 */
void ltm_multi_reg_cbk_dlvr_dl_sdu(ratcmn_dlvr_dl_sdu_f pf_dlvr_sdu);

/**
 * @brief ltm_multi_reg_cbk_hook_ul 
 * Register callback for LTE UL traffic.
 *
 * @param pf_hook
 */
void ltm_multi_reg_cbk_hook_ul(ratcmn_hook_ul_f pf_hook);

/**
 * @brief ltm_multi_reg_cbk_rollback_ul_sdu
 * Register callback for LTE UL traffic rollback.
 *
 * @param pf_hook
 */
void ltm_multi_reg_cbk_rollback_ul_sdu(ratcmn_rollback_sdu_f pf_rollback);
#endif   /* ----- #ifndef LTM_INC  ----- */

