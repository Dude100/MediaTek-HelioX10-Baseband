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
 *   hifusb_qmu.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *	This is the HIF data path driver API head file for both USB2.0/USB3.0
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/



#ifndef __HIFUSB_QMU_H__
#define __HIFUSB_QMU_H__

#include "qmu_bm.h"
//#include "kal_internal_api.h"
#include "hif_common.h"


/*!
 *  @brief  ask hif driver to set GPD buffer into QMU
 *  @param  q_type        	the queue type
 *  @param  queue_no        QMU queue no
 *  @param  first_gpd       first GPD of a single GPD or GPD list
 *  @param  last_gpd        last GPD of a single GPD or GPD list
 *	@return KAL_TRUE : set gpd success, 
 			KAL_FALSE : set gpd fail and upper module should re-submit or free the queue list
 */
kal_bool hifusbq_set_gpd(hif_queue_type_e q_type, kal_uint8 queue_no, qbm_gpd* first_gpd, qbm_gpd* last_gpd);


/*!
 *  @brief  ask hif driver to flush all GPD buffer from QMU
 *  @param  q_type        	the queue type
 *  @param  queue_no        QMU queue no
 *  @param  flush type    	the flush type wished
 *  @param  pp_head        	the head pointer of flush list
 *  @param  pp_tail        	the tail pointer of flush list
 *  @return	return total flushed gpd number
 */
kal_uint32 hifusbq_flush_gpd(hif_queue_type_e q_type, kal_uint8 queue_no, hif_flush_type_e flush_type , void **pp_head, void **pp_tail);


/*!
 *  @brief  poll specified QMU queue to see if any GPD complete
 *			deq_type == HIFQ_FREEQ, (use qbmt_free_q_hwo())
 *				would free the used queue after this function and return the deq number
 *			deq_type == HIF_DEQ, 	
 *				would just deq and return the deq list and the deq number
 *				use use qbmt_de_q() if generic buffer type
 *				use deqmt_deq_hif_ul_type1() if QBM_TYPE_HIF_UL_TYPE1				
 *				use deqmt_deq_hif_ul_type2() if QBM_TYPE_HIF_UL_TYPE2
 *  @param  deq_info        the que number , que type and deq type
 *  @param  first_gpd       first GPD of a single GPD or GPD list
 *  @param  last_gpd        last GPD of a single GPD or GPD list
 *	@return	return the deq number
 */
kal_uint32 hifusbq_poll_queue(hif_deq_info_t deq_info, void **first_gpd, void **last_gpd);

/*!
 *  @brief  initial hif_common.c private structure and variable
 *	@return	return KAL_TRUE if success , KAL_FALSE if failure
 */
kal_bool hifusbq_common_qmu_init(void);

/*!
 *  @brief  get currently que list
 *	@param	is_tx, KAL_TRUE for txq , KAL_FALSE for rxq
 *	@param q_no , the queue number form 0~n
 *	@param pp_head , return the currently queue head
 *	@param pp_tail , return the currently queue tail
 */
void hifusbq_get_que_list(kal_bool is_tx , kal_uint8 q_no, void **pp_head, void **pp_tail);

/*!
 *  @brief  configure specific queue operation option with bit-map config
 *	@param	is_tx, KAL_TRUE for txq , KAL_FALSE for rxq
 *	@param q_no , the queue number form 0~n
 *	@param que_cfg , the bit-map configuration , ex. HIF_QCFG_BM_TX_EMPTY_ENQ
 *	@return KAL_TRUE if success, KAL_FALSE if configure not valid
 */
kal_bool hifusbq_set_que_cfg(kal_bool is_tx , kal_uint8 q_no, kal_uint16 que_cfg);

/*!
 *  @brief  upper layer use this light weight api to query if new ul packet valid
 *	@return	return bit-mask of valid ul packet exist queue number
 */
kal_uint32 hifusbq_check_ul_newpkt(void);

/*!
 *  @brief  upper layer use this light weight api to query if new dl packet valid
 *	@return	return bit-mask of valid dl packet exist queue number
 */
kal_uint32 hifusbq_check_dl_newpkt(void);

/*!
 *  @brief  ask hif driver to buffer gpd when USB related pwr or clock off (SUSPEND)
 *  @param  q_type        	the queue type
 *  @param  queue_no        QMU queue no
 *  @param  first_gpd       first GPD of a single GPD or GPD list
 *  @param  last_gpd        last GPD of a single GPD or GPD list
 *	@return KAL_TRUE : set gpd success, 
 			KAL_FALSE : set gpd fail and upper module should re-submit or free the queue list
 */
kal_bool hifusbq_pwrsave_buffer_gpd(hif_queue_type_e q_type, kal_uint8 queue_no, qbm_gpd* first_gpd, qbm_gpd* last_gpd);

/*!
 *  @brief  ask hif driver to configure gpd which bufferred when USB related pwr or clock off (SUSPEND) after resumed
 *  @param  q_type        	the queue type
 *  @param  queue_no        QMU queue no
 *	@return KAL_TRUE : set gpd success, 
 			KAL_FALSE : set gpd fail and upper module should re-submit or free the queue list
 */
kal_bool hifusbq_pwrsave_restore_gpd(hif_queue_type_e q_type, kal_uint8 queue_no);


/*!
 *  @brief  ask hif driver to flush all GPD bufferred when USB related pwr or clock off (SUSPEND)
 *  @param  q_type        	the queue type
 *  @param  queue_no        QMU queue no
 *  @param  flush type    	the flush type wished
 *  @param  pp_head        	the head pointer of flush list
 *  @param  pp_tail        	the tail pointer of flush list
 *  @return	return total flushed gpd number
 */
kal_uint32 hifusbq_pwrsave_flush_gpd(hif_queue_type_e q_type, kal_uint8 queue_no, hif_flush_type_e flush_type , void **pp_head, void **pp_tail);


#endif
