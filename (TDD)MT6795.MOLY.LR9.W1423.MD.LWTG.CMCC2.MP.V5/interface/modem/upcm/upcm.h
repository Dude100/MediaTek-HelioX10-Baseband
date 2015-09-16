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
 *   upcm.h
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
 * Implementation of upcm_get_pending_ul_data_status() based on timestamp difference (3sec)
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Back out changelist 156018
 * patch for QMU_BM/UPCM/RATADP/TFT_PF trace
 *
 * removed!
 * removed!
 * add tft_pf/qmu_bm/upcm/ratadp trace
 *
 * removed!
 * removed!
 * add upcm_rcv_ul_by_ebi and add EBI for DL Deliver for IMS requirement.
 ****************************************************************************/
/*
 * =====================================================================================
 *
 *       Filename:  upcm.h
 *
 *    Description:  UPCM (User plane connection manager exported header file)
 *
 *        Created: 2012/3/19 �W�� 11:20:22
 *
 *        Author:  mtk01641 (moja)
 * =====================================================================================
 */
#ifndef  UPCM_INC
#define  UPCM_INC

#include "kal_public_api.h"
#include "qmu_bm.h"
#include "upcm_enum.h"

/*
 * lte tick source notify callback prototype.
 * is_lte_tick: KAL_TRUE - has LTE tick.
 *              KAL_FLAE - may no LTE tick.
 */
typedef void (*upcm_nofify_lte_tick_f)(kal_bool is_lte_tick);
typedef void (*upcm_dlvr_dl_sdu_f)(kal_uint32 pdn_id, qbm_gpd* p_head, qbm_gpd* p_tail);

/**
 * @brief upcm_init Init UPCM module.
 *
 * @return TRUE  
 */
kal_bool upcm_init(void);

/**
 * @brief upcm_reset 
 * Reset UPCM module.
 *
 * @return TRUE  
 *
 * @return 
 */
kal_bool upcm_reset(void);

/**
 * @brief upcm_on_ilm 
 * Receive ILM message
 *
 * @param ilm
 */
void upcm_on_ilm(ilm_struct *p_ilm);


/**
 * @brief upcm_rcv_ul_sdu 
 * Receive UL SDUs. UL SDU are GPD list.
 *
 * @param ip_type the UL SDU IP type. may help UPCM go quick path if the IP type is known.
 * @param pdn_id PDN Connection ID
 * @param p_head SDU list head. (GPD based)
 * @param p_tail SDU list tail. (GPD based)
 */
void upcm_rcv_ul_sdu(ip_type_e ip_type, kal_uint32 pdn_id, qbm_gpd* p_head, qbm_gpd* p_tail);

/**
 * @brief upcm_rcv_ul_sdu_by_ebi 
 * Receive UL SDUs on specified EBI. The Function will bypass TFT Process.
 * But for inter-rat case, the data will enter suspend queue, so TFT Process will be applied.
 * It can't be called on test loopback mode.
 *
 * @param ebi
 * @param p_head
 * @param p_tail
 */
void upcm_rcv_ul_sdu_by_ebi(kal_uint32 ebi, qbm_gpd* p_head, qbm_gpd* p_tail);

/**
 * @brief upcm_reg_cbk_notify_lte_tick
 * Register callback function.
 * For get if there is a LTE tick source.
 *
 * @param pf_notify callback function.
 */
void upcm_reg_cbk_notify_lte_tick(upcm_nofify_lte_tick_f pf_notify);

/**
 * @brief upcm_reg_cbk_dlvr_dl_sdu 
 * Register callback for deliver DL SDUs.
 *
 * @param pf_dlvr_sdu
 */
void upcm_reg_cbk_dlvr_dl_sdu(upcm_dlvr_dl_sdu_f pf_dlvr_sdu);


typedef struct
{
    /* tx/rx bytes */
    kal_uint64 tx_bytes;
    kal_uint64 rx_bytes;
} single_epsb_txrx_info_struct;

typedef struct
{
    single_epsb_txrx_info_struct txrx_info[MAX_EPSB_NUM];
} upcm_query_epsb_statistics_struct;

/**
 * @brief upcm_query_epsb_txrx_statistics 
 * Query UPCM tx/rx statistics.
 * If the connection is deactivated, it will give the last value of previous activate.
 *
 * @param query_result
 */
void upcm_query_epsb_txrx_statistics(upcm_query_epsb_statistics_struct *query_result);

/**
 * @brief upcm_get_pending_ul_data_status 
 * Predict pending UL data of each NSAPI/EBI by checking if there is UL data
 * within past UPCM_UL_DATA_INTERVAL_TO_TRIGGER_SR.
 * 
 * @return 16-bit bitmap for each NSAPI/EBI.
 *  If it predicts this NSAPI/EBI has UL data, the corresponding bit is set to 1.
 *  Otherwise, the corresponding bit is set to 0.
 *  For example, if there is pending UL data for NSAPI/EBI 5~15, 
 *  then the return value will be 0xFFE0.
 */
kal_uint16 upcm_get_pending_ul_data_status(void);

#endif   /* ----- #ifndef UPCM_INC  ----- */

