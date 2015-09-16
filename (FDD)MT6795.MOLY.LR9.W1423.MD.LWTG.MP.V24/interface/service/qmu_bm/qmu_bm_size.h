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
 *   qmu_bm_size.h
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
 * 1. QBM change data length of HIF_UL_TYPE_S from 64 to 128 for hooking this gpd type on CCMNI2. (wrapped by __CCCICCMNI_SUPPORT__)
 * 	2. Map QBM_FLC_UL_POOL_ID_HIF_UL_02 to new FLC pool FLC2_POOL_ID_HIF_UL_02, which makes HIF_UL_TYPE and HIF_UL_TYPE_02 not sharing FLC pool.
 * 	3. Do not toggle EMPTY TCP ACK in TFT_PF (wrapped by __CCCICCMNI_SUPPORT__)
 * 	4. UPCM check priority by GPD type, instead of EMPTY TCP ACK bit toggled by TFT_PF (wrapped by __CCCICCMNI_SUPPORT__)
 * 	5. Do not config queue for HIF_UL_TYPE_01
 *
 * removed!
 * removed!
 * Add new QBM type: QBM_TYPE_ESRB_UL_S for smaller UL SRB data (allowed data length<=256 byte)
 *
 * removed!
 * removed!
 * 1. QBM_NET_UL_DATA_LEN is set back to QBM_HIF_UL_TYPE_DATA_LEN.
 * 	2. Set data length in set_buffer_func_t for QBM_TYPE_HIF_UL_TYPE_S as QBM_HIF_UL_TYPE_S_DATA_LEN.
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
 * add DHL_GPD_BD type.
 *
 * removed!
 * removed!
 * remoe MSD type from config init.
 * MSD owner will use init_q by themself.
 * Change MSD data len from 2048 to 1024..
 *
 * removed!
 * removed!
 * add QBM_TYPE_MSD
 *
 * removed!
 * removed!
 * increase NET_UL data part length as the same as HIF_UL_TYPE.
 ****************************************************************************/
/*
 * =====================================================================================
 *
 *       Filename:  qmu_bm_size.h
 *
 *    Description:  Each buffer type size. Defined as constant.
 *                  For user can put it into array.
 *                  Because in kal model, it don't prefer dynamic allocation.
 *
 *        Created:  2011/8/11 �U�� 03:06:39
 *        Author:  mtk01641 (moja)
 * =====================================================================================
 */
#ifndef  QMU_BM_SIZE_INC
#define  QMU_BM_SIZE_INC

/* 
 * Because kal cache related api have alignment restriction.
 * Not convenient. So just export this API for user who is not sure the alignement.
 */
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
#include "cache_sw.h"
#define QBM_CACHE_ALIGN          CPU_CACHE_LINE_BIT_OFFSET
#define QBM_CACHE_SIZE           CPU_CACHE_LINE_SIZE
#define QBM_CACHE_LINE_SIZE_MASK CPU_CACHE_LINE_SIZE_MASK
#else
#define QBM_CACHE_ALIGN 5
#define QBM_CACHE_SIZE  32
#define QBM_CACHE_LINE_SIZE_MASK ((1 << QBM_CACHE_ALIGN) - 1)
#endif

/* always invalid first 192 btyes from the BD1. */
#define HIF_UL_INVALID_LEN (192)
#define HIF_UL_TYPE_INVALID_LEN (HIF_UL_INVALID_LEN)

/* calculate nearest cache aligned size. */
#define QBM_SIZE_CACHE_ALIGN(_sz) (((_sz) + (QBM_CACHE_SIZE - 1)) & ~QBM_CACHE_LINE_SIZE_MASK)

#define QBM_HEAD_SIZE   QBM_CACHE_SIZE

#define TGPD_SZ        16
#define COMMON_EXT_LEN (QBM_CACHE_SIZE - TGPD_SZ)
#define EMBEDDED_BD_SZ (2*QBM_CACHE_SIZE)

/* 
 * Reserve RX_EXT_LEN space before data 
 * So we can put the decompressed header on this space.
 * Note: the extension is after the embedded BD.
 */
#define QBM_HIF_DL_EXT_LEN   (128)
#define QBM_HIF_DL_DATA_LEN  (2048 - QBM_HIF_DL_EXT_LEN)
/* 20120724 ian: QBM_TYPE_CCCI_COMM*/
#define QBM_CCCI_COMM_EXT_LEN  (128)
#define QBM_CCCI_COMM_DATA_LEN (4096)
#define QBM_IMS_DL_DATA_LEN    (4096)

#define QBM_ESRB_UL_DATA_LEN       (8192)
#define QBM_ESRB_UL_S_DATA_LEN     (256)
#define QBM_ESRB_DL_DATA_LEN       (8192)
#define QBM_TTY_XXX_DATA_LEN       (1024)
#define QBM_GPD_BD_TST_DATA_LEN    (2048)
#define QBM_GPD_BD_TST_EXT_LEN     (256)
#define QBM_PDCP_CTRL_DATA_LEN     (258)
#define QBM_ROHC_CTRL_DATA_LEN     (256)
#define QBM_ACM_DATA_LEN           (64)
#define QBM_HIF_UL_TYPE_DATA_LEN   (1536 + QBM_CACHE_SIZE)
#ifdef __CCCICCMNI_SUPPORT__
#define QBM_HIF_UL_TYPE_S_DATA_LEN (128)
#else
#define QBM_HIF_UL_TYPE_S_DATA_LEN (64)
#endif /* ifdef __CCCICCMNI_SUPPORT__ */
#define QBM_NET_UL_DATA_LEN        (QBM_HIF_UL_TYPE_DATA_LEN)
#define QBM_NET_UL_SHRD_DATA_LEN   (QBM_HIF_UL_TYPE_DATA_LEN)
#define QBM_MSD_DATA_LEN           (1024)

#define QBM_SIZE_PD          (QBM_HEAD_SIZE + TGPD_SZ)

/*---------- Each foramt size constant ----------*/
#define _QBM_SIZE_TGPD          (QBM_SIZE_PD + COMMON_EXT_LEN)
#define _QBM_SIZE_TBD           _QBM_SIZE_TGPD
#define _QBM_SIZE_TGPD_BPS      _QBM_SIZE_TGPD
#define _QBM_SIZE_DHL_GPD_BD    (_QBM_SIZE_TGPD + _QBM_SIZE_TBD)
#define _QBM_SIZE_HIF_DL        (_QBM_SIZE_TGPD + EMBEDDED_BD_SZ - COMMON_EXT_LEN + QBM_HIF_DL_EXT_LEN + QBM_HIF_DL_DATA_LEN)
#define _QBM_SIZE_IMS_DL        (_QBM_SIZE_TGPD + EMBEDDED_BD_SZ + QBM_IMS_DL_DATA_LEN)
#define _QBM_SIZE_ESRB_UL       (_QBM_SIZE_TGPD + QBM_ESRB_UL_DATA_LEN)
#define _QBM_SIZE_ESRB_UL_S     (_QBM_SIZE_TGPD + QBM_ESRB_UL_S_DATA_LEN)
#define _QBM_SIZE_ESRB_DL       (_QBM_SIZE_TGPD + QBM_ESRB_DL_DATA_LEN)
#define _QBM_SIZE_TTY_TYPE1     (_QBM_SIZE_TGPD + QBM_TTY_XXX_DATA_LEN)
#define _QBM_SIZE_TTY_TYPE2     _QBM_SIZE_TTY_TYPE1
#define _QBM_SIZE_TTY_INT       _QBM_SIZE_TTY_TYPE1
#define _QBM_SIZE_GPD_BD_TST    (QBM_SIZE_PD + QBM_GPD_BD_TST_EXT_LEN + QBM_GPD_BD_TST_DATA_LEN)
#define _QBM_SIZE_PDCP_CTRL     (_QBM_SIZE_TGPD + QBM_PDCP_CTRL_DATA_LEN)
#define _QBM_SIZE_ROHC_CTRL     (_QBM_SIZE_TGPD + QBM_ROHC_CTRL_DATA_LEN)
#define _QBM_SIZE_ACM           (_QBM_SIZE_TGPD + QBM_ACM_DATA_LEN)
#define _QBM_SIZE_NET_UL        (_QBM_SIZE_TGPD + EMBEDDED_BD_SZ + QBM_NET_UL_DATA_LEN)
#define _QBM_SIZE_NET_UL_SHRD   (_QBM_SIZE_TGPD + EMBEDDED_BD_SZ + QBM_NET_UL_SHRD_DATA_LEN)
#define _QBM_SIZE_HIF_UL_TYPE   (_QBM_SIZE_TGPD + EMBEDDED_BD_SZ + QBM_HIF_UL_TYPE_DATA_LEN)
#define _QBM_SIZE_HIF_UL_TYPE_S (_QBM_SIZE_TGPD + EMBEDDED_BD_SZ + QBM_HIF_UL_TYPE_S_DATA_LEN)
/* 20120724 ian: QBM_TYPE_CCCI_COMM*/
#define _QBM_SIZE_CCCI_COMM   (_QBM_SIZE_TGPD + EMBEDDED_BD_SZ - COMMON_EXT_LEN + QBM_CCCI_COMM_EXT_LEN + QBM_CCCI_COMM_DATA_LEN)
#define _QBM_SIZE_MSD         (_QBM_SIZE_TGPD + QBM_MSD_DATA_LEN)
/*
 * For the QBM_HEADER and Descriptor start address is cache aligned,
 * We need to make sure all entry is cache aligned
 * 
 * Note:
 * Don't use the size as the total size of your memory pool.
 * Please use QBM_QUEUE_GET_MEM_SIZE(_sz, _buf_num) defined in qmu_bm.h to get total memory size.
 * e.g. 
 * QBM_QUEUE_GET_MEM_SIZE(QBM_SIZE_TGPD, 12);
 */
#define QBM_SIZE_TGPD           QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_TGPD)
#define QBM_SIZE_TBD            QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_TBD)
#define QBM_SIZE_TGPD_BPS       QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_TGPD_BPS)
#define QBM_SIZE_DHL_GPD_BD     QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_DHL_GPD_BD)
#define QBM_SIZE_HIF_DL         QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_HIF_DL)
#define QBM_SIZE_NET_DL         QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_HIF_DL)
#define QBM_SIZE_IMS_DL         QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_IMS_DL)
#define QBM_SIZE_NET_UL         QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_NET_UL)
#define QBM_SIZE_NET_UL_SHRD    QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_NET_UL_SHRD)
#define QBM_SIZE_HIF_UL_TYPE    QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_HIF_UL_TYPE)
#define QBM_SIZE_HIF_UL_TYPE_01 QBM_SIZE_HIF_UL_TYPE
#define QBM_SIZE_HIF_UL_TYPE_02 QBM_SIZE_HIF_UL_TYPE
#define QBM_SIZE_HIF_UL_TYPE_S  QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_HIF_UL_TYPE_S)
#define QBM_SIZE_ESRB_UL        QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_ESRB_UL)
#define QBM_SIZE_ESRB_UL_S      QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_ESRB_UL_S)
#define QBM_SIZE_ESRB_DL        QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_ESRB_DL)
#define QBM_SIZE_TTY_TYPE1      QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_TTY_TYPE1)
#define QBM_SIZE_TTY_TYPE2      QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_TTY_TYPE2)
#define QBM_SIZE_TTY_INT        QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_TTY_INT)
#define QBM_SIZE_GPD_BD_TST     QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_GPD_BD_TST)
#define QBM_SIZE_PDCP_CTRL      QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_PDCP_CTRL)
#define QBM_SIZE_ROHC_CTRL      QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_ROHC_CTRL)
#define QBM_SIZE_ACM            QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_ACM)
/* 20120724 ian: QBM_TYPE_CCCI_COMM*/
#define QBM_SIZE_CCCI_COMM      QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_CCCI_COMM)
#define QBM_SIZE_MSD            QBM_SIZE_CACHE_ALIGN(_QBM_SIZE_MSD)
/*---------- Each foramt size constant ----------*/

#endif   /* ----- #ifndef QMU_BM_SIZE_INC  ----- */
