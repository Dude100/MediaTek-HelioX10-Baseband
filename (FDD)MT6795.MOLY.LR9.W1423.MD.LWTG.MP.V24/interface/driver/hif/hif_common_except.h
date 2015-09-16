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
 *   hif_common_except.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *	This is the HIF data path exception handler driver head file for both USB2.0/USB3.0.
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
 * .modify project name as MT6290 and change all comment or log for new model name
 *
 * removed!
 * removed!
 * .separate USB/SDIO/CLDMA from hif_common.c for multi-hif request
 * -- USB (ming.hsieh)
 * -- SDIO (Wei-De/mick.lin)
 * -- CLDMA (TH.Cheng)
 * .resolve SDIO BPS TX/RX test case fail issue
 ****************************************************************************/

#ifndef __HIF_COMMON_EXCEPT_H__
#define __HIF_COMMON_EXCEPT_H__

#include "hif_common.h"

/*!
 *	@brief	initial the exception HIF driver, only support empty enqueue flow in exception
*/
kal_bool hif_except_initial(void);
/*!
 *  @brief  ask hif driver to flush all GPD buffer from QMU
 *			this API only used to stop exception mode to go back normal mode
 *  @param  q_type        	the queue type
 *  @param  queue_no        QMU queue no
 *  @param  flush type    	the flush type wished
 *  @param  pp_head        	the head pointer of flush list
 *  @param  pp_tail        	the tail pointer of flush list
 *  @return	return total flushed gpd number
 */
kal_uint32 hif_except_flush_gpd(hif_queue_type_e q_type, kal_uint8 queue_no, hif_flush_type_e flush_type , void **pp_head, void **pp_tail);
/*!
 *	@brief	stop the queue and flush USB pipe fifo for following debug log
 *			HIF layer don't care remain GPD and upper layer could parsing their resource
 *			to handle remain data re-send flow (DHL would re-send remain data after using this API)
 *	@param	q_type , define the queue tx/rx direction
 *	@param	q_num , define the channel which using the queue number
*/
void hif_except_clear_q(hif_queue_type_e q_type, kal_uint8 q_num);
/*!
 *  @brief  ask hif driver to set GPD buffer into QMU
 *			don't handle critical section protection becuase in the single thread exception handler
 *  @param  q_type        	the queue type
 *  @param  queue_no        QMU queue no
 *  @param  first_gpd       first GPD of a single GPD or GPD list
 *  @param  last_gpd        last GPD of a single GPD or GPD list
 *	@return KAL_TRUE : set gpd success, 
 			KAL_FALSE : set gpd fail and upper module should re-submit or free the queue list
 */
kal_bool hif_except_set_gpd(hif_queue_type_e q_type, kal_uint8 queue_no, qbm_gpd* first_gpd, qbm_gpd* last_gpd);
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
kal_uint32 hif_except_poll_queue(hif_deq_info_t deq_info, void **pp_first_gpd, void **pp_last_gpd);

/*!
 *	@brief	hif driver would count the timeout for TX queue not progressing
 *			upper driver should check this the status when they found channel abnormal
 *	@param	q_num, the tx queue number to check status
 *	@return	Return the hif driver counter of txq stall time in millisecond (ms)
*/
kal_uint32 hif_except_get_txq_timeout(kal_uint8 q_num);

#endif
