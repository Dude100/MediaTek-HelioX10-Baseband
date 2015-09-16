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
 *   qbm_config_num.h
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
 * 1. Add QBM_TYPE_NET_UL_SHRD, which is mapped to FLC NET_UL_SHARED pool
 * 2. Allow QBM_TYPE_NET_UL_SHRD in RAL
 *
 * removed!
 * removed!
 * Merging
 *  	
 * 	//MOLY/BRANCHES_LR9/LR9.W1421.MD.LWTG.MP/mcu/...
 *  	
 * 	to //MOLY/BRANCHES_LR9/LR9.W1423.MD.LWTG.MP/mcu/...
 *
 * removed!
 * removed!
 * Merging
 *  	
 * 	//MOLY/TRUNK/MOLY/mcu/...
 *  	
 * 	to //MOLY/BRANCHES_LR9/LR9.W1421.MD.LWTG.MP/mcu/...
 *
 * removed!
 * removed!
 * separate platform dependent (mostly HIF related) config to different header files.
 *
 * removed!
 * removed!
 * 1. QBM change data length of HIF_UL_TYPE_S from 64 to 128 for hooking this gpd type on CCMNI2. (wrapped by __CCCICCMNI_SUPPORT__)
 * 	2. Map QBM_FLC_UL_POOL_ID_HIF_UL_02 to new FLC pool FLC2_POOL_ID_HIF_UL_02, which makes HIF_UL_TYPE and HIF_UL_TYPE_02 not sharing FLC pool.
 * 	3. Do not toggle EMPTY TCP ACK in TFT_PF (wrapped by __CCCICCMNI_SUPPORT__)
 * 	4. UPCM check priority by GPD type, instead of EMPTY TCP ACK bit toggled by TFT_PF (wrapped by __CCCICCMNI_SUPPORT__)
 * 	5. Do not config queue for HIF_UL_TYPE_01
 *
 * removed!
 * removed!
 * increase BPS number from 800 to 1400.
 * About need 44K memory
 *
 * removed!
 * removed!
 * Increase the number of buffer allocated initially from FLC for HIF_UL_TYPE_S.
 *
 * removed!
 * removed!
 * Add a new QBM type: QBM_TYPE_HIF_UL_TYPE_S for UL TCP ACK for better buffer usage efficiency.
 *
 * removed!
 * removed!
 * 520 is not enough, increase it to 600. but also decrease HIF_UL_TYPE1 number.
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
 * increase single mode UL buffer number
 *
 * removed!
 * removed!
 * tuen qbm number for ESL.
 *
 * removed!
 * removed!
 * prepare HIF_UL_TYPE, HIF_UL_TYPE_01, HIF_UL_TYPE_02.
 *
 * removed!
 * removed!
 * increase the number of DL GPDs for TC 7.2.3.7 (at least AM_Window_size + 2)
 *
 * removed!
 * removed!
 * remoe MSD type from config init.
 * MSD owner will use init_q by themself.
 * Change MSD data len from 2048 to 1024..
 *
 * removed!
 * removed!
 * increase HIFUL,DL buffers in ASIC.
 * UL 5->80
 * DL 10->100
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * add QBM_TYPE_MSD
 *
 * removed!
 * removed!
 * multi-mode data path support.
 *
 * removed!
 * removed!
 * [CDCACM] Add SIO_CMD_DCD command handling
 *
 * removed!
 * removed!
 * 
 * MOLY Migration from TATAKA
 ****************************************************************************/
/*
 * =====================================================================================
 *
 *       Filename:  qbm_config_num.h
 *
 *    Description:  Buffer number centeral control
 *    User can put total number and init queue number definition here.
 *
 *        Created:  2012/1/13 W 11:32:34
 *        Author:  mtk01641 (moja)
 * =====================================================================================
 */
#ifndef  QMU_BM_CONFIG_NUM_INC
#define  QMU_BM_CONFIG_NUM_INC

#define QBM_COMMON_NUM_TGPD     600
#define QBM_COMMON_NUM_TBD      600
 /*
  * worst case, one TCP Ack per frame.
  * We need 800 for Ack pool, and 5xx for UL Type
  * and remain for others. e.g. HIF DL Enqueue
  */
#define QBM_COMMON_NUM_TGPD_BPS 1400

#define QBM_NUM_HIF_DL_IN_MBMS_Q        0

#define QBM_NUM_TTY_INT                 200
/* 20120724 ian: QBM_TYPE_CCCI_COMM*/
/* Including TTY internal used buffers  */
#if __HIF_CCCI_SUPPORT__
#define QBM_NUM_CCCI_COMM               200+QBM_NUM_TTY_INT
#endif

#define QBM_NUM_NET_DL      20  /* Number of downlink GPD for internal network protocols. */
#define QBM_NUM_NET_UL      20  /* Number of uplink GPD for internal network protocols.   */
#define QBM_NUM_NET_UL_SHRD 200 /* Number of uplink GPD for IPCore(VoLTE, etc).           */

#define QBM_NUM_TTY_TYPE1 100
#define QBM_NUM_TTY_TYPE2 100

#define QBM_NUM_ACM       16  /* Number of ACM GPD                                      */

#define QBM_NUM_IMS_DL    16

/*
 * For 2G Buffer shrink case
 */
#define QBM_NUM_HIF_UL_TYPE_IN_HIF_SHRINK    6
#define QBM_NUM_HIF_UL_TYPE_01_IN_HIF_SHRINK 6
#define QBM_NUM_HIF_UL_TYPE_02_IN_HIF_SHRINK 6
#define QBM_NUM_HIF_UL_TYPE_S_IN_HIF_SHRINK  6

/* 
 * some platform dependent number is put here.
 * most are HIF related.
 */
#if defined(__ESL_COSIM_LTE__)
#include "qbm_config_num_cosim.h"
#else
#include "qbm_config_num_normal.h"
#endif/*__ESL_COSIM_LTE__*/

#endif   /* ----- #ifndef QMU_BM_CONFIG_NUM_INC  ----- */
