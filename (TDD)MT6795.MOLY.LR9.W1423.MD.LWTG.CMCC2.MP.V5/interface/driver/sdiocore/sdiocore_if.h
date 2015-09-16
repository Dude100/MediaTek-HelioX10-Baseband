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
 *   sdiocore_if.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   SDIO core normal mode APIs header file
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
 * 	CCCI_FS compact read and profile trace (sdio)
 *
 * removed!
 * removed!
 * 	CCCI_FS compact read and profile trace
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * [MT6290 SDIOC Rename]
 *
 * removed!
 * removed!
 * [MT6290 Rename] SDIOCore
 *
 * removed!
 * removed!
 * [SDIOC] multi-hif modification
 * 1. HMU
 * 2. HIF SDIO APIs
 *
 * removed!
 * removed!
 * [CCCITTY]  1. fix warnings 2.enable sdiocore sim when CCCITTY UT
 *
 * removed!
 * removed!
 * sync latest version of new features
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#ifndef _SDIOCORE_IF_H
#define _SDIOCORE_IF_H

#include "qmu_bm.h"
#include "hif_ior.h"
#include "hif_common.h"
#include "hifsdio_qmu.h"
#include "hif_sdio.h"
#include "ccci_if.h"
#include "sdiocore_except_if.h"
#include "hifsdio_qmu_except.h"

#if defined(SYS_TEST_EMSC_ENABLE) || defined(ATEST_SYS_SDIOC)
#define __SDIOCORE_UT__
#endif

#if defined(ATEST_SYS_CCCI) || defined(ATEST_SYS_SDIOC) || defined(ATEST_SYS_CCCI_TTY)
#define __SDIOCORE_HIF_SIM__
#endif

#define SDIOQ_TYPE_TX HIFQ_TYPE_TX
#define SDIOQ_TYPE_TX_NO_FLUSH HIFQ_TYPE_TX_NO_FLUSH
#define SDIOQ_TYPE_RX HIFQ_TYPE_RX

//NOTE!!! you have to update SDIOC_TxQ_TYPE/SDIOC_RxQ_TYPE
#define SDIOC_ULQ_NUM 5 //HIFSDIO_MAX_ULQ_NUM
#define SDIOC_DLQ_NUM 4 //HIFSDIO_MAX_DLQ_NUM

/*!
 *  @brief UPLINK queue index SDIOC_RXQ_TYPE
 */
typedef enum{
	SDIOC_RXQ_Q0 = 0,   //realtime
	SDIOC_RXQ_Q1 = 1,   //normal
	SDIOC_RXQ_Q2 = 2,   //normal
	SDIOC_RXQ_Q3 = 3,   //normal
	SDIOC_RXQ_Q4 = 4,   //normal
	SDIOC_RXQ_NUM = SDIOC_ULQ_NUM,
	SDIOC_RXQ_INVALID = 0xff
} SDIOC_RXQ_TYPE ;

/*!
 *  @brief DOWNLINK queue index SDIOC_TXQ_TYPE
 */
typedef enum{
	/*TX_PORT0_Q_MIN = 0 ,*/
	SDIOC_TXQ_Q0 = 0 ,	 //realtime
	SDIOC_TXQ_Q1 = 1 ,   //normal
	SDIOC_TXQ_Q2 = 2 ,   //normal
	SDIOC_TXQ_Q3 = 3 ,   //normal
	SDIOC_TXQ_NUM = SDIOC_DLQ_NUM,
	SDIOC_TXQ_INVALID = 0xff
	/*TX_PORT0_Q_MAX = SDIOC_ULQ_NUM*/
} SDIOC_TXQ_TYPE ;

/*!
 *  @brief API for CCCI channel attaching sdio queue
 */
kal_bool sdioc_q_attach(kal_uint8 queue_type, kal_uint8 queue_no, CCCI_CHANNEL_T channel, HIF_CCCI_GPD_CALLBACK funp);
/*!
 *  @brief API for CCCI channel detaching sdio queue
 */
kal_bool sdioc_q_detach(kal_uint8 queue_type, kal_uint8 queue_no, CCCI_CHANNEL_T channel);
/*!
 *  @brief API for CCCI channel to submit io request
 */
kal_bool sdioc_submit_ior(kal_uint8 queue_type , kal_uint8 queue_no, void* ior);
/*!
 *  @brief API for CCCI channel to submit single gpd during polling mode
 */
kal_bool sdioc_polling_submit_one_gpd(kal_uint8 queue_no, qbm_gpd *pgpd, kal_bool istx);
/*!
 *  @brief API for registering the reload rgpd callback function, used in MT6575 CCMNI IT
 */
kal_bool sdioc_reg_reload_rgpd_cb(CCCI_RGPD_RELOAD_CALLBACK reload_rgpd_funcp);
/*!
 *  @brief API for registering the traffic generating callback function, used in MT6575 CCMNI IT
 */
kal_bool sdioc_reg_pkt_gen_cb(CCCI_DL_PKTGEN_CALLBACK dl_pktgen_funcp);

#if defined(__SDIOCORE_HIF_SIM__)
void hifsdioq_ut_set_lb(kal_bool sdio_lb_ut, kal_bool ccci_lb_ut);
#endif

/*!
 *  @brief API for initializing sdiocore
 */
kal_int32 sdioc_init(void);
kal_int32 sdioc_init_phase2(void);
void sdioc_normal_init(void);
void hifsdioq_ut_set_lb(kal_bool sdio_lb_ut, kal_bool ccci_lb_ut);

kal_uint32 sdioc_get_time();
kal_uint32 sdioc_get_dur(kal_uint32 start, kal_uint32 end);

#endif //#ifndef _SDIOCORE_IF_H
