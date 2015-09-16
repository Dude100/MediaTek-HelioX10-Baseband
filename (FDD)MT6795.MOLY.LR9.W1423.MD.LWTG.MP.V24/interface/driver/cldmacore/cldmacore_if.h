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
 *   cldmacore_if.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   CLDMA core normal mode APIs header file
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 01 06 2014 box.wu
 * removed!
 * CLDMA non-cacheable for E1 & adjust init sequence to hs2.
 *
 * 12 24 2013 box.wu
 * removed!
 * for SP to read NVRAM via CCCI FS first.
 *
 * 12 10 2013 box.wu
 * removed!
 * [ECCCI] exception done
 *
 * removed!
 * removed!
 * .
 * 11 26 2013 box.wu
 * removed!
 * add exception, tty, ICUSB.
 *
 * removed!
 * removed!
 * 	.
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
 * [CCCI/CLDMA INT] 1. work around cldmacore initialization flow
 * 2. create CCCI DUMMY HIF interface for CCIF channels
 ****************************************************************************/
#ifndef _CLDMACORE_IF_H
#define _CLDMACORE_IF_H

#include "qmu_bm.h"
#include "hif_ior.h"
#include "hif_common.h"
#include "hif_cldma.h"
#include "ccci_if.h"
#include "cldmacore_except_if.h"

#define CLDMAQ_TYPE_TX HIFQ_TYPE_TX
#define CLDMAQ_TYPE_RX HIFQ_TYPE_RX
#define CLDMAQ_TYPE_TX_NO_FLUSH HIFQ_TYPE_TX_NO_FLUSH

#define CLDMAQ_DATA_CH_NUM 3


//NOTE!!! you have to update CLDMAC_TxQ_TYPE/CLDMAC_RxQ_TYPE
#define CLDMAC_ULQ_NUM HIFCLDMA_MAX_ULQ_NUM
#define CLDMAC_DLQ_NUM HIFCLDMA_MAX_DLQ_NUM

void cldmac_hifcldma_init(void);
void cldmac_init_phase2(void);
/*!
 *  @brief UPLINK queue index CLDMAC_RXQ_TYPE
 */
typedef enum{
	CLDMAC_RXQ_Q0 = 0,   //lte0
	CLDMAC_RXQ_Q1 = 1,   //lte1
	CLDMAC_RXQ_Q2 = 2,   //lte2
	CLDMAC_RXQ_Q3 = 3,   //COM
	CLDMAC_RXQ_Q4 = 4,   //normal
	CLDMAC_RXQ_Q5 = 5,   //normal
	CLDMAC_RXQ_Q6 = 6,   //normal
	CLDMAC_RXQ_Q7 = 7,   //normal
	CLDMAC_RXQ_NUM = CLDMAC_ULQ_NUM,
	CLDMAC_RXQ_INVALID = 0xff
} CLDMAC_RXQ_TYPE ;

/*!
 *  @brief DOWNLINK queue index CLDMAC_TXQ_TYPE
 */
typedef enum{
	/*TX_PORT0_Q_MIN = 0 ,*/
	CLDMAC_TXQ_Q0 = 0 ,	  //lte0
	CLDMAC_TXQ_Q1 = 1 ,   //lte1
	CLDMAC_TXQ_Q2 = 2 ,   //lte2
	CLDMAC_TXQ_Q3 = 3 ,   //Com
	CLDMAC_TXQ_Q4 = 4 ,   //normal
	CLDMAC_TXQ_Q5 = 5 ,   //normal
	CLDMAC_TXQ_Q6 = 6 ,   //normal
	CLDMAC_TXQ_Q7 = 7 ,   //normal
	CLDMAC_TXQ_NUM = CLDMAC_DLQ_NUM,
	CLDMAC_TXQ_INVALID = 0xff
	/*TX_PORT0_Q_MAX = CLDMAC_ULQ_NUM*/
} CLDMAC_TXQ_TYPE ;

/*!
 *  @brief API for CCCI channel attaching cldma queue
 */
kal_bool cldmac_q_attach(kal_uint8 queue_type, kal_uint8 queue_no, CCCI_CHANNEL_T channel, HIF_CCCI_GPD_CALLBACK funp);
/*!
 *  @brief API for CCCI channel detaching cldma queue
 */
kal_bool cldmac_q_detach(kal_uint8 queue_type, kal_uint8 queue_no, CCCI_CHANNEL_T channel);
/*!
 *  @brief API for CCCI channel to submit io request
 */
kal_bool cldmac_submit_ior(kal_uint8 queue_type , kal_uint8 queue_no, void* ior);
/*!
 *  @brief API for CCCI channel to submit single gpd during polling mode
 */
kal_bool cldmac_polling_submit_one_gpd(kal_uint8 queue_no, qbm_gpd *pgpd, kal_bool istx);
/*!
 *  @brief API for CCCI channel to submit io request with extra config, info
 */
//kal_bool cldmac_submit_ior_ext(kal_uint8 queue_type , kal_uint8 queue_no, void* ior, ccci_io_ext_info_t* pinfo);
#endif //#ifndef _CLDMACORE_IF_H
