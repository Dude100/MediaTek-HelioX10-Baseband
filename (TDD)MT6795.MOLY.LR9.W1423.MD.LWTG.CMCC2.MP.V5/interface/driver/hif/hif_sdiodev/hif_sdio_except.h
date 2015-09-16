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
 *   hif_sdio_except.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *	This is the SDIO exception handler driver API head file.
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
 * MT6290 exception handle of SDIO driver
 *
 * removed!
 * removed!
 * Change project name to MT6290
 *
 * removed!
 * removed!
 * update hifsdio_init_phase2 & API in except
 ****************************************************************************/

#ifndef __HIF_SDIO_EXCEPT__
#define __HIF_SDIO_EXCEPT__

#include "hif_sdio.h"


#define EXCEPT_SDIO_UL_QUE    0
#define EXCEPT_SDIO_DL_QUE    0


/*!
 *  @brief  simply delay us function ,
 *	@param delay_us , delay period in us
 *	@return
 */
void hifsdio_except_delay_us(kal_uint32 delay_us);

/*!
 *  @brief  See the sw interrupt occurs or not in polling mode
 *	@param sw_int_no , the interrupt number form 0~15
 *	@param timeout_ms , the period of polling time
 *
 *	@return KAL_TRUE :  interrupt happen in the period,
 *		KAL_FALSE : interrupt not happen in the period.
 */
kal_bool hifsdio_except_sw_int_poll(kal_uint8 sw_int_no, kal_uint32 timeout_ms);

/*!
 *  @brief  simply send a GPD,
 *	@param queue_no , the queue number form 0~n
 *	@param send_gpd , the GPD which want to send
 *	@param timeout_ms , the time interval which host should read this packet
 *                          If the user do not have timeout value, set it to 0.
 *      @return KAL_TRUE :  send gpd success,
 *		KAL_FALSE : send gpd fail and should not call this API again.
 */
kal_bool hifsdio_simple_send_gpd(kal_uint8 queue_no, qbm_gpd* send_gpd, kal_uint32 timeout_ms);

/*!
 *  @brief  simply receive a GPD,
 *      @param queue_no , the queue number form 0~n
 *      @param send_gpd , the GPD which want to receive
 *      @param timeout_ms , the time interval which host should read this packet
 *                          If the user do not have timeout value, set it to 0.
 *      @return KAL_TRUE :  receive gpd success,
 *              KAL_FALSE : receive gpd fail and should not call this API again.
 */
kal_bool hifsdio_simple_receive_gpd(kal_uint8 queue_no, qbm_gpd* recv_gpd, kal_uint32 timeout_ms);

#endif
