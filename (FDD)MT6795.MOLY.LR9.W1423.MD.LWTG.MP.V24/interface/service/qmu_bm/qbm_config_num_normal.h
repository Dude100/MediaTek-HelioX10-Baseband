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
 *   qbm_config_num_normal.h
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
 ****************************************************************************/
#ifndef  QMU_BM_CONFIG_NUM_NORMAL_INC
#define  QMU_BM_CONFIG_NUM_NORMAL_INC

#if defined(__FPGA__)
#include "qbm_config_num_fpga.h"
#else
#ifdef __MD2__
/*
 * MD2 is 2G only modem. so defulat set number to 2G
 * Because we use SHRINK definition. The definition is in qbm_config_num.h
 * So the header file should only in qbm_config_num.h 
 * otherwise user should define their shink value.
 */
#define QBM_NUM_HIF_UL_TYPE_IN_HIF    QBM_NUM_HIF_UL_TYPE_IN_HIF_SHRINK
#define QBM_NUM_HIF_UL_TYPE_01_IN_HIF QBM_NUM_HIF_UL_TYPE_01_IN_HIF_SHRINK
#define QBM_NUM_HIF_UL_TYPE_02_IN_HIF QBM_NUM_HIF_UL_TYPE_02_IN_HIF_SHRINK
#define QBM_NUM_HIF_UL_TYPE_S_IN_HIF  QBM_NUM_HIF_UL_TYPE_S_IN_HIF_SHRINK
#else
#define QBM_NUM_HIF_UL_TYPE_IN_HIF    80
#define QBM_NUM_HIF_UL_TYPE_01_IN_HIF 80
#define QBM_NUM_HIF_UL_TYPE_02_IN_HIF 80
#define QBM_NUM_HIF_UL_TYPE_S_IN_HIF  80
#endif/*__MD2__*/

#define QBM_NUM_HIF_DL_IN_DRB_Q       100
#endif/*__FPGA__*/

#if defined(__UMTS_RAT__) || defined(__GSM_RAT__)

/* for FLC, we only allocate some buffer in the queue first, 
 * others are get by FLC from the traffic behavior.
 * More traffic will get more buffers in QBM
 */
#define QBM_NUM_HIF_UL_TYPE    QBM_NUM_HIF_UL_TYPE_IN_HIF
#define QBM_NUM_HIF_UL_TYPE_01 QBM_NUM_HIF_UL_TYPE_01_IN_HIF
#define QBM_NUM_HIF_UL_TYPE_02 QBM_NUM_HIF_UL_TYPE_02_IN_HIF
#else
/*
 * Single Mode buffer pool size can be more since they have no share capability
 */
#define QBM_NUM_HIF_UL_TYPE    620 /* Number of data path uplink GPD allocated. @ */
#define QBM_NUM_HIF_UL_TYPE_01 420 /* Number of data path uplink GPD allocated. @ */
#define QBM_NUM_HIF_UL_TYPE_02 240 /* Number of data path uplink GPD allocated. @ */
#endif/* defined(__UMTS_RAT__) || defined(__GSM_RAT__) */

/*
 * Note that the actual buffer pool size for HIF_UL_TYPE_S is defined in 
 * interface/service/flc2/flc2_tunable_para.h (FLC2_HIFSMALL_UL_POOL_SIZE).
 */
#ifdef __CCCICCMNI_SUPPORT__
/*
 * For CCMNI case, HIF_UL_TYPE_S is loaded on a specific CCMNI channel.
 * We allocate some buffer in the queue first and may get more from FLC.
 * This is to imitate HIF_UL_TYPE buffer behavior.
 */ 
#define QBM_NUM_HIF_UL_TYPE_S  QBM_NUM_HIF_UL_TYPE_S_IN_HIF
#else
/*
 * For non-CCMNI case, HIF_UL_TYPE_S will be used in LTM for replacement.
 * We just allocate the needed number from FLC in the beginning.
 *
 * The QBM_NUM_HIF_UL_TYPE_S is for UL TCP ACK.
 * In DL 150Mbps environment, there is (150000 * 8) / 1500 =~ 13 (pkt/ms).
 * If we need to send TCP ACK for each DL packet, and ERLC STATUS is sent every 60ms (in 8475), 
 * then we need at least 13 * 60 = 780 GPD in pool before they are released.
 */
#define QBM_NUM_HIF_UL_TYPE_S  800 /* Number of data path uplink GPD allocated. @ */
#endif /* ifdef __CCCICCMNI_SUPPORT__ */

#define QBM_NUM_HIF_DL 520

#endif   /* ----- #ifndef QMU_BM_CONFIG_NUM_NORMAL_INC  ----- */
