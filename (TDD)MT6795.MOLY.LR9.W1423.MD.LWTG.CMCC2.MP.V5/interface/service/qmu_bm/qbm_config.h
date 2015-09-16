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
 *   qbm_config.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *  QBM configure files.
 *  NOTE:
 *  For cache flush more efficiency.
 *  Put all non-cache flush buffers on the front.
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
 * 1. QBM change data length of HIF_UL_TYPE_S from 64 to 128 for hooking this gpd type on CCMNI2. (wrapped by __CCCICCMNI_SUPPORT__)
 * 	2. Map QBM_FLC_UL_POOL_ID_HIF_UL_02 to new FLC pool FLC2_POOL_ID_HIF_UL_02, which makes HIF_UL_TYPE and HIF_UL_TYPE_02 not sharing FLC pool.
 * 	3. Do not toggle EMPTY TCP ACK in TFT_PF (wrapped by __CCCICCMNI_SUPPORT__)
 * 	4. UPCM check priority by GPD type, instead of EMPTY TCP ACK bit toggled by TFT_PF (wrapped by __CCCICCMNI_SUPPORT__)
 * 	5. Do not config queue for HIF_UL_TYPE_01
 *
 * removed!
 * removed!
 * Add a new QBM type: QBM_TYPE_HIF_UL_TYPE_S for UL TCP ACK for better buffer usage efficiency.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * prepare HIF_UL_TYPE, HIF_UL_TYPE_01, HIF_UL_TYPE_02.
 *
 * removed!
 * removed!
 * remoe MSD type from config init.
 * MSD owner will use init_q by themself.
 * Change MSD data len from 2048 to 1024..
 *
 * removed!
 * removed!
 * modify compile flag for ttycore internal buffer
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
 *       Filename:  qbm_config.h
 *
 *    Description:  configure qbm pool.
 *
 *        Created:  2011/11/21 ?W?? 09:33:31
 *        Author:  mtk01641 (moja)
 * =====================================================================================
 */

#include "qbm_features.h"
#include "qbm_config_num.h"

/*************************BM Pool CFG Begin****************/
/*BM Buffer type*/
bmcfg_type(QBM_TYPE_TGPD) 
/*The buffer number*/
bmcfg_num(QBM_COMMON_NUM_TGPD) 
/*The size of one buffer*/
bmcfg_one_size(QBM_SIZE_TGPD) 
/*Config do cache invalid for the data part when do de-q-rx*/
bmcfg_cache_invalid(KAL_FALSE) 
/*Config do cache flush the data part when do en-q-tx*/
/*  Put all non-cache flush buffers on the front.*/
bmcfg_cache_flush(KAL_FALSE) 
/*************************BM Pool CFG END******************/

/*************************BM Pool CFG Begin****************/
/*BM Buffer type*/
bmcfg_type(QBM_TYPE_TBD) 
/*The buffer number*/
bmcfg_num(QBM_COMMON_NUM_TBD) 
/*The size of one buffer*/
bmcfg_one_size(QBM_SIZE_TBD) 
/*Config do cache invalid for the data part when do de-q-rx*/
bmcfg_cache_invalid(KAL_FALSE) 
/*Config do cache flush the data part when do en-q-tx*/
bmcfg_cache_flush(KAL_FALSE) 
/*************************BM Pool CFG END******************/

/*************************BM Pool CFG Begin****************/
/*BM Buffer type*/
bmcfg_type(QBM_TYPE_TGPD_BPS) 
/*The buffer number*/
bmcfg_num(QBM_COMMON_NUM_TGPD_BPS) 
/*The size of one buffer*/
bmcfg_one_size(QBM_SIZE_TGPD_BPS) 
/*Config do cache invalid for the data part when do de-q-rx*/
bmcfg_cache_invalid(KAL_FALSE) 
/*Config do cache flush the data part when do en-q-tx*/
bmcfg_cache_flush(KAL_FALSE) 
/*************************BM Pool CFG END******************/

/*************************BM Pool CFG Begin****************/
/* use postfix _flc for FLC usage case. it's behavior is the same on no FLC case. */
/*BM Buffer type*/
bmcfg_type_flc(QBM_TYPE_HIF_UL_TYPE) 
/*The buffer number*/
bmcfg_num_flc(QBM_NUM_HIF_UL_TYPE) 
/*The size of one buffer*/
bmcfg_one_size_flc(QBM_SIZE_HIF_UL_TYPE) 
/*Config do cache invalid for the data part when do de-q-rx*/
bmcfg_cache_invalid_flc(KAL_FALSE) 
/*Config do cache flush the data part when do en-q-tx*/
bmcfg_cache_flush_flc(KAL_FALSE) 
/*************************BM Pool CFG END******************/

/*
 * [20140414 Clark]
 * Do not initialize queue for QBM_TYPE_HIF_UL_TYPE_01 since HIF agrees that
 * no allocation will be made for it. (But the enum is still kept for them.)
 */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*************************BM Pool CFG Begin****************/
/* use postfix _flc for FLC usage case. it's behavior is the same on no FLC case. */
/*BM Buffer type*/
bmcfg_type_flc(QBM_TYPE_HIF_UL_TYPE_02) 
/*The buffer number*/
bmcfg_num_flc(QBM_NUM_HIF_UL_TYPE_02) 
/*The size of one buffer*/
bmcfg_one_size_flc(QBM_SIZE_HIF_UL_TYPE_02) 
/*Config do cache invalid for the data part when do de-q-rx*/
bmcfg_cache_invalid_flc(KAL_FALSE) 
/*Config do cache flush the data part when do en-q-tx*/
bmcfg_cache_flush_flc(KAL_FALSE) 
/*************************BM Pool CFG END******************/

/*************************BM Pool CFG Begin****************/
/* use postfix _flc for FLC usage case. it's behavior is the same on no FLC case. */
/*BM Buffer type*/
bmcfg_type_flc(QBM_TYPE_HIF_UL_TYPE_S) 
/*The buffer number*/
bmcfg_num_flc(QBM_NUM_HIF_UL_TYPE_S) 
/*The size of one buffer*/
bmcfg_one_size_flc(QBM_SIZE_HIF_UL_TYPE_S) 
/*Config do cache invalid for the data part when do de-q-rx*/
bmcfg_cache_invalid_flc(KAL_FALSE) 
/*Config do cache flush the data part when do en-q-tx*/
bmcfg_cache_flush_flc(KAL_FALSE) 
/*************************BM Pool CFG END******************/

/*************************BM Pool CFG Begin****************/
/*BM Buffer type*/
bmcfg_type(QBM_TYPE_HIF_DL) 
/*The buffer number*/
bmcfg_num(QBM_NUM_HIF_DL) 
/*The size of one buffer*/
bmcfg_one_size(QBM_SIZE_HIF_DL) 
/*Config do cache invalid for the data part when do de-q-rx*/
bmcfg_cache_invalid(KAL_FALSE) 
/*Config do cache flush the data part when do en-q-tx*/
bmcfg_cache_flush(KAL_FALSE) 
/*************************BM Pool CFG END******************/

/*************************BM Pool CFG Begin****************/
/*BM Buffer type*/
bmcfg_type(QBM_TYPE_NET_DL) 
/*The buffer number*/
bmcfg_num(QBM_NUM_NET_DL) 
/*The size of one buffer*/
bmcfg_one_size(QBM_SIZE_NET_DL) 
/*Config do cache invalid for the data part when do de-q-rx*/
bmcfg_cache_invalid(KAL_FALSE) 
/*Config do cache flush the data part when do en-q-tx*/
bmcfg_cache_flush(KAL_FALSE) 
/*************************BM Pool CFG END******************/

/*************************BM Pool CFG Begin****************/
/*BM Buffer type*/
bmcfg_type_flc(QBM_TYPE_NET_UL) 
/*The buffer number*/
bmcfg_num_flc(QBM_NUM_NET_UL) 
/*The size of one buffer*/
bmcfg_one_size_flc(QBM_SIZE_NET_UL) 
/*Config do cache invalid for the data part when do de-q-rx*/
bmcfg_cache_invalid_flc(KAL_FALSE) 
/*Config do cache flush the data part when do en-q-tx*/
bmcfg_cache_flush_flc(KAL_FALSE) 
/*************************BM Pool CFG END******************/

/*************************BM Pool CFG Begin****************/
/*BM Buffer type*/
bmcfg_type_flc(QBM_TYPE_NET_UL_SHRD) 
/*The buffer number*/
bmcfg_num_flc(QBM_NUM_NET_UL_SHRD) 
/*The size of one buffer*/
bmcfg_one_size_flc(QBM_SIZE_NET_UL_SHRD) 
/*Config do cache invalid for the data part when do de-q-rx*/
bmcfg_cache_invalid_flc(KAL_FALSE) 
/*Config do cache flush the data part when do en-q-tx*/
bmcfg_cache_flush_flc(KAL_FALSE) 
/*************************BM Pool CFG END******************/

/*************************BM Pool CFG Begin****************/
/*BM Buffer type*/
bmcfg_type(QBM_TYPE_ACM) 
/*The buffer number*/
bmcfg_num(QBM_NUM_ACM)
/*The size of one buffer*/
bmcfg_one_size(QBM_SIZE_ACM)
/*Config do cache invalid for the data part when do de-q-rx*/
bmcfg_cache_invalid(KAL_FALSE) 
/*Config do cache flush the data part when do en-q-tx*/
bmcfg_cache_flush(KAL_FALSE) 
/*************************BM Pool CFG END******************/


#if defined(__QBM_FLC_UT_USE_BD_TST__)
/*************************BM Pool CFG Begin****************/
/* 20120724 ian: QBM_TYPE_CCCI_COMM*/
/*BM Buffer type*/
bmcfg_type(QBM_TYPE_GPD_BD_TST) 
/*The buffer number*/
bmcfg_num(QBM_NUM_HIF_UL_TYPE + 1) //need plus 1. or HIF_UL only can allocate QBM_NUM_HIF_UL_TYPE  - 1
/*The size of one buffer*/
bmcfg_one_size(QBM_SIZE_GPD_BD_TST) 
/*Config do cache invalid for the data part when do de-q-rx*/
bmcfg_cache_invalid(KAL_FALSE) 
/*Config do cache flush the data part when do en-q-tx*/
bmcfg_cache_flush(KAL_FALSE) 
/*************************BM Pool CFG END******************/
#endif

/*-----------------------------------------------------------------------
 |    Start from Cache Operation (need cache_invalid, and cache_flush)
 ------------------------------------------------------------------------*/

#if __HIF_CCCI_SUPPORT__
/*************************BM Pool CFG Begin****************/
/* 20120724 ian: QBM_TYPE_CCCI_COMM*/
/* QBM_NUM_CCCI_COMM includes TTY internal used gpd */
/*BM Buffer type*/
bmcfg_type(QBM_TYPE_CCCI_COMM) 
/*The buffer number*/
bmcfg_num(QBM_NUM_CCCI_COMM) 
/*The size of one buffer*/
bmcfg_one_size(QBM_SIZE_CCCI_COMM) 
/*Config do cache invalid for the data part when do de-q-rx*/
bmcfg_cache_invalid(KAL_TRUE) 
/*Config do cache flush the data part when do en-q-tx*/
bmcfg_cache_flush(KAL_TRUE) 
/*************************BM Pool CFG END******************/
#endif
/*************************BM Pool CFG Begin****************/
/*BM Buffer type*/
bmcfg_type(QBM_TYPE_TTY_INT) 
/*The buffer number*/
bmcfg_num(QBM_NUM_TTY_INT) 
/*The size of one buffer*/
bmcfg_one_size(QBM_SIZE_TTY_INT) 
/*Config do cache invalid for the data part when do de-q-rx*/
bmcfg_cache_invalid(KAL_TRUE) 
/*Config do cache flush the data part when do en-q-tx*/
bmcfg_cache_flush(KAL_TRUE) 
/*************************BM Pool CFG END******************/


/*************************BM Pool CFG Begin****************/
/*BM Buffer type*/
bmcfg_type(QBM_TYPE_TTY_TYPE1) 
/*The buffer number*/
bmcfg_num(QBM_NUM_TTY_TYPE1) 
/*The size of one buffer*/
bmcfg_one_size(QBM_SIZE_TTY_TYPE1) 
/*Config do cache invalid for the data part when do de-q-rx*/
bmcfg_cache_invalid(KAL_TRUE) 
/*Config do cache flush the data part when do en-q-tx*/
bmcfg_cache_flush(KAL_TRUE) 
/*************************BM Pool CFG END******************/

/*************************BM Pool CFG Begin****************/
/*BM Buffer type*/
bmcfg_type(QBM_TYPE_TTY_TYPE2) 
/*The buffer number*/
bmcfg_num(QBM_NUM_TTY_TYPE2)
/*The size of one buffer*/
bmcfg_one_size(QBM_SIZE_TTY_TYPE2)
/*Config do cache invalid for the data part when do de-q-rx*/
bmcfg_cache_invalid(KAL_TRUE) 
/*Config do cache flush the data part when do en-q-tx*/
bmcfg_cache_flush(KAL_TRUE) 
/*************************BM Pool CFG END******************/

/*************************BM Pool CFG Begin****************/
/*BM Buffer type*/
bmcfg_type(QBM_TYPE_IMS_DL) 
/*The buffer number*/
bmcfg_num(QBM_NUM_IMS_DL)
/*The size of one buffer*/
bmcfg_one_size(QBM_SIZE_IMS_DL)
/*Config do cache invalid for the data part when do de-q-rx*/
bmcfg_cache_invalid(KAL_TRUE) 
/*Config do cache flush the data part when do en-q-tx*/
bmcfg_cache_flush(KAL_TRUE) 
/*************************BM Pool CFG END******************/
