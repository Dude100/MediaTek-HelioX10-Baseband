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
 *   ccifcore_if.h
 *
 * Project:
 * --------
 *   MOLY 
 *
 * Description:
 * ------------
 *   CCIF core normal mode APIs header file
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef _CCIFCORE_IF_H
#define _CCIFCORE_IF_H

#include "qmu_bm.h"
#include "hif_ior.h"
#include "hif_common.h"
#include "ccifcore_except_if.h"
#include "ccci_if.h"

#include "reg_base.h"

#define CCIFC_ULQ_NUM 	(8)
#define CCIFC_DLQ_NUM 	(8)

#ifdef __HIF_WCCIF_SUPPORT__ 
#if defined(__REG_base_MT6589_H__)
#define CCIFC_BOOTUP_TRACE_ADDR (MDCCIF_base + 0x0100 + 256 - 8)
#else
#define CCIFC_BOOTUP_TRACE_ADDR (MD_CCIF0_BASE + 0x0100 + 512 - 8)
#endif
#endif

typedef enum{
        CCIFC_RXQ_Q0 = 0,   
        CCIFC_RXQ_Q1 = 1,   
        CCIFC_RXQ_Q2 = 2,          
        CCIFC_RXQ_Q3 = 3,   
        CCIFC_RXQ_Q4 = 4,   
        CCIFC_RXQ_Q5 = 5,   
        CCIFC_RXQ_Q6 = 6,   
        CCIFC_RXQ_Q7 = 7,  
        CCIFC_RXQ_NUM = CCIFC_ULQ_NUM,
        CCIFC_RXQ_INVALID = 0xff
} CCIFC_RXQ_TYPE ;

/*!
 *  @brief DOWNLINK queue index CCIFC_TXQ_TYPE
 */
typedef enum{
        /*TX_PORT0_Q_MIN = 0 ,*/
        CCIFC_TXQ_Q0 = 0 ,       
        CCIFC_TXQ_Q1 = 1 ,   
        CCIFC_TXQ_Q2 = 2 ,   
        CCIFC_TXQ_Q3 = 3 ,   
        CCIFC_TXQ_Q4 = 4 ,   
        CCIFC_TXQ_Q5 = 5 ,   
        CCIFC_TXQ_Q6 = 6 ,   
        CCIFC_TXQ_Q7 = 7 ,   
        CCIFC_TXQ_NUM = CCIFC_DLQ_NUM,
        CCIFC_TXQ_INVALID = 0xff
        /*TX_PORT0_Q_MAX = CCIFC_ULQ_NUM*/
} CCIFC_TXQ_TYPE ;


#define CCIFQ_TYPE_TX HIFQ_TYPE_TX
#define CCIFQ_TYPE_RX HIFQ_TYPE_RX
#define CCIFQ_TYPE_TX_NO_FLUSH	HIFQ_TYPE_TX_NO_FLUSH

void ccifc_hif_init(void);
void ccifc_init_phase2(void);

/*!
 *  @brief API for CCCI channel attaching ccif queue
 */
kal_bool ccifc_q_attach(kal_uint8 queue_type, kal_uint8 queue_no, CCCI_CHANNEL_T channel, HIF_CCCI_GPD_CALLBACK funp);
/*!
 *  @brief API for CCCI channel detaching ccif queue
 */
kal_bool ccifc_q_detach(kal_uint8 queue_type, kal_uint8 queue_no, CCCI_CHANNEL_T channel);
/*!
 *  @brief API for CCCI channel to submit io request
 */
kal_bool ccifc_submit_ior(kal_uint8 queue_type , kal_uint8 queue_no, void* ior);
 /*!
 *  @brief API for CCCI setup shared data address
 */
kal_bool ccifc_setup_shared_data(kal_uint8 *addr, kal_uint32 size);
/*!
 *  @brief API for CCCI channel to submit one gpd in polling mode
 */
kal_bool ccifc_polling_submit_one_gpd(kal_uint8 queue_no, qbm_gpd *pgpd, kal_bool istx);
#endif //#ifndef _CCIFCORE_IF_H

