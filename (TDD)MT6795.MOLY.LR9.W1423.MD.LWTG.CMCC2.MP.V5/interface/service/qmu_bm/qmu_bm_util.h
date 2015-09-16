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
 *   qmu_bm_util.h
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
 * notify upper layer about buffer shrink normal.
 *
 * removed!
 * removed!
 * add DMA TYPE Query.
 *
 * removed!
 * removed!
 * Merging
 *  	
 * 	//MOLY_CBr/tj.chang/MOLY_Profile.w1352p1/mcu/...
 *  	
 * 	to //MOLY/TRUNK/MOLY/mcu/...
 *
 * removed!
 * removed!
 * add comment for qbm_reset_pd API.
 * For some user mis-understand it will help to calculate checksum.
 * It won't.
 *
 * removed!
 * removed!
 * add qbm_reset_pd function for user to reset their buffer format by QBM Type.
 ****************************************************************************/
/*
 * =====================================================================================
 *
 *       Filename:  qmu_bm_util.h
 *
 *    Description:  Some customize API. 
 *                  Used for testing, or easy manager HW Queue.
 *
 *           Note:  The all API are not protected, so for every potential lock problem.
 *                  User should protect it by himself.
 *                  e.g. 
 *                  1) for HIF En-Q, it may be called by many threads.
 *                     So when HIF use qbmt_common_en_q, it need lock.
 *                  2) for PDCP Cipher en-q, it may only be called on PDCP context.
 *                     So PDCP don't need to protect it.
 *
 *        Created:  2011/6/15 �U�� 03:35:28
 *        Author:  mtk01641 (moja)
 * =====================================================================================
 */
#ifndef  QMU_BM_UTIL_INC
#define  QMU_BM_UTIL_INC

#include "qmu_bm.h"

/* 
 * Because kal cache related api have alignment restriction.
 * Not convenient. So just export this API for user who is not sure the alignement.
 */
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
#define QBM_CACHE_GET_ALIGN(_o, _sz, _alo, _alsz) \
{                                                 \
    _alo   = (kal_uint32)(_o);                    \
    _alsz  = (_sz);                               \
    if(_alo&CPU_CACHE_LINE_SIZE_MASK) {           \
        _alo = (kal_uint32)(_o)&~CPU_CACHE_LINE_SIZE_MASK;    \
        _alsz += (kal_uint32)(_o)&CPU_CACHE_LINE_SIZE_MASK;   \
    }                                             \
    _alsz = _alsz + CPU_CACHE_LINE_SIZE - 1;      \
    _alsz = _alsz & ~CPU_CACHE_LINE_SIZE_MASK;    \
}

/**
 * @brief QBM_CACHE_FLUSH_ALIGN 
 * If we already know the address and size are align, 
 * we can use this macro to save MIPs
 *
 * @param _o
 * @param _sz
 *
 * @return 
 */
#define QBM_CACHE_FLUSH_ALIGN(_o, _sz) \
{                                      \
    clean_dcache((kal_uint32)(_o), (kal_uint32)(_sz));             \
}

#define QBM_CACHE_INVALID_ALIGN(_o, _sz) \
{                                        \
    invalidate_dcache((kal_uint32)(_o), (kal_uint32)(_sz));          \
}

#define QBM_CACHE_FLUSH(_o, _sz)                 \
{                                                \
    kal_uint32 _addr;                            \
    kal_uint32 _isz;                             \
    QBM_CACHE_GET_ALIGN((_o), _sz, _addr, _isz);   \
    clean_dcache(                                \
            _addr,                               \
            _isz                                 \
            );                                   \
}

#define QBM_CACHE_INVALID(_o, _sz)               \
{                                                \
    kal_uint32 _addr;                            \
    kal_uint32 _isz;                             \
    QBM_CACHE_GET_ALIGN((_o), _sz, _addr, _isz);   \
    invalidate_dcache(                           \
            _addr,                               \
            _isz                                 \
            );                                   \
}
#else
#define QBM_CACHE_FLUSH_ALIGN(_o, _sz)
#define QBM_CACHE_INVALID_ALIGN(_o, _sz)
#define QBM_CACHE_FLUSH(_o, _sz)
#define QBM_CACHE_INVALID(_o, _sz)
#endif

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qmu_util_set_flush_region
 *  Description:  Set the flush region. It's used for en_q function.
 *                en_q function only flush data part 
 *                when the memory is in the flush region
 *
 *   Note: It is used internally.
 *         Please don't call it unless testing purpose.
 *
 *  s_mem: region start address
 *  e_mem: region end   address
 * =====================================================================================
 */
void qmu_util_set_flush_region(kal_uint32 s_mem, kal_uint32 e_mem);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbm_cal_set_checksum_by_len
 *  Description:  Calculate checksum for check_len bytes 
 *                and set it in descriptor checksum field.
 *                The formula is to use byte to store all bytes sum 
 *                and use 0xFF - all bytes sum.
 *        Note:   The check_len must be divided by 4
 * @param data calculate checksum start address
 * @param len  length of protected data.
 * =====================================================================================
 */
#ifdef __ENABLE_QMU_CHECKSUM__
void       qbm_cal_set_checksum_by_len(const kal_uint8 *data, const kal_uint32 check_len);
kal_uint32 qbm_cal_checksum_by_len(const kal_uint8 *data, const kal_uint32 check_len);
#else
#define qbm_cal_set_checksum_by_len(_d, _l)
#define qbm_cal_checksum_by_len(_d, _l) 0
#endif

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbm_cal_set_checksum_wth_hwo_by_len
 *  Description:  Just like qbm_cal_set_checksum_by_len, but it will treat HWO bit as 1.
 *                The HWO bit may not be 1 in the memory.
 * =====================================================================================
 */
#ifdef __ENABLE_QMU_CHECKSUM__
void       qbm_cal_set_checksum_wth_hwo_by_len(const kal_uint8 *data, const kal_uint32 check_len);
kal_uint32 qbm_cal_checksum_wth_hwo_by_len(const kal_uint8 *data, const kal_uint32 check_len);
#else
#define qbm_cal_set_checksum_wth_hwo_by_len(_d, _l)
#define qbm_cal_checksum_wth_hwo_by_len(_d, _l) 0
#endif

/** 
 * @brief qbm_cal_set_checksum_wth_hwo
 * Fix 12 bytes.
 * Just like calculate checksum. But it will treat the HWO bit to 1.
 * Because we may set HWO bit later and resume HW.
 * In this case we can't use the first byte to calculate checksum.
 */
#ifdef __ENABLE_QMU_CHECKSUM__
void       qbm_cal_set_checksum_wth_hwo(const kal_uint8 * const data);
kal_uint32 qbm_cal_checksum_wth_hwo(const kal_uint8 * const data);
#else
#define qbm_cal_set_checksum_wth_hwo(_d)
#define qbm_cal_checksum_wth_hwo(_d) 0
#endif

/**
 * @brief qbmt_cache_flush_q 
 * Flush PD/BD and data part(if the data part is configured to be flushed)
 *
 * @param p_head
 * @param p_tail
 * @param hwo     0: don't fill hwo bit.
 *                1: fill hwo bit to 1 and recalculate checksum.
 */
void qbmt_cache_flush_q(void *p_head, void *p_tail, kal_uint32 hwo);

/* 
 * EnQ by reuse the tail descriptor.
 * It will do memory copy, and hold the p_new_tail for tail(HWO = 0).
 * Note: User should make sure all TGPD extension part are enough.
 * This API will scan all TGPD/TBD list, and do cache flush.
 *
 * Param:
 * p_new_head, p_new_tail: the new list want to be enqueued.
 *
 * pp_orig_head, pp_orig_tail: original list queue on HW QMU.
 *
 * The original source tail will be updated after en-queue.
 * 
 * hwo: 0 - don't do anything on the new list.
 *          Assume the HWO of this queue from p_new_head to p_new_tail all "1" and checksum is right
 *      1 - set hwo on the new list (from p_new_head to p_new_tail).
 *      Because in some case, we may de-q data from one HW and en-q data to another HW.
 *      e.g. 
 *      HIF->PPP Copro
 *      TFT Copro -> Cipher Engine.
 *      
 *      In this case, the HWO need to to reset to 1.
 *      If we always set HWO to 1 by the user, it waste time.
 *      (user need to traverse all list and en_q also traverse all list)
 *      So we can reduce MIPs by set the HWO and checksum on en_Q process.
 */
void
qbmt_common_en_q(
		void *p_new_head, 
		void *p_new_tail, 
		void **pp_orig_head, 
		void **pp_orig_tail,
		kal_uint32 hwo
		);

/* 
 * Like qbmt_common_en_q, but this api only link descriptor.
 * Don't do travse the whole PD list to flush thing.
 * Save MIPs when en_q a larger PD and the PD is non-cacheable or don't need to do flush.
 */
void
qbmt_common_en_q_no_flush(
		void *p_new_head, 
		void *p_new_tail, 
		void **pp_orig_head, 
		void **pp_orig_tail
		);

/* 
 * EnQ with a bypass bit TGPD.
 * This API will scan all TGPD/TBD list, and do cache flush.
 * The TGPD is allocated in this API.
 * If no TGPD memory, it will return QBM_ERROR_MEM_NOT_ENOUGH
 *
 * This API assume the original tail is a bypass bit TGPD.
 * So it just easily link the new list at the tail.
 * The source tail will be updated to the bypass TGPD.
 */
kal_int32
qbmt_common_en_q_wth_bypass(
		void *p_new_head, 
		void *p_new_tail, 
		void **pp_orig_head, 
		void **pp_orig_tail,
		kal_uint32 hwo
		);
/*
 * Like qbmt_common_en_q_wth_bypass, but don't do cache flush for whole PD list
 */
kal_int32
qbmt_common_en_q_wth_bypass_no_flush(
		void *p_new_head, 
		void *p_new_tail, 
		void **pp_orig_head, 
		void **pp_orig_tail
		);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbmt_common_en_q_rx
 *  Description:  En-q new list for Receiver side.
 *                It is like reload_q, but the new list is from outside, 
 *                this API just help to link new list to the original list.
 *                This API won't help to do cache flush, 
 *                because the new list is supposed from BM and it is done cache flush when
 *                call alloc_q_no_tail.
 *
 *                This API will link new head to the orig_tail,
 *                change new tail HWO to 0. (will help do cache flush)
 *                and then change orig_tail'HWO to 1. (will help do cache flush)
 *                Update *pp_orig_tail to the new tail.
 *
 *                Used scenario:
 *                Driver don't allocate buffer, it is get buffer from upper APP.
 * =====================================================================================
 */
void
qbmt_common_en_q_rx(
		void *p_new_head, 
		void *p_new_tail, 
		void **pp_orig_head, 
		void **pp_orig_tail
		);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbmt_de_q_n
 *  Description:  DeQ RGPD from QMU. This API will check the HWO bit.
 *                If HWO bit is 0, the buffer will be de-q from the QMU.
 *                The RGPD/RBD descriptor will be cache invalided.
 *
 *	   	   Note: The whole buffer list in the QMU should have the same attribute.
 *	   	         All data part are need to be invalidate or not.
 *
 *    pp_src_head, pp_src_tail 
 *       Original queue on QMU (May be used to receive data from host)
 *       After de-q, the *pp_src_head will be updated to the next of the last buffer.
 *    
 *    n: Max de-q number.
 *    
 *    pp_new_head, pp_new_tail
 *       The de-queued buffer list will be stored here.
 *
 *    Return: The number of de-queued RGPD.
 *          
 * =====================================================================================
 */
kal_uint32
qbmt_de_q_n(
		void **pp_src_head, 
		void **pp_src_tail, 
		kal_uint32 max_n,
		void **pp_new_head,
		void **pp_new_tail
		);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbmt_de_q
 *  Description:  Just like qbmt_de_q_n, but the number is not restricted.
 *                It will de-q until HWO = 1 or tail is reached (not include tail).
 * =====================================================================================
 */
kal_uint32
qbmt_de_q(
		void **pp_src_head, 
		void **pp_src_tail, 
		void **pp_new_head, 
		void **pp_new_tail
		);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbmt_de_q_hif_ul_type
 *  Description:  Quick de-q RGPD from HIF_UL Type3 queue.
 *                It also invalid first 192 - 32 bytes of data part.
 *                Others just like qbmt_de_q_n
 * =====================================================================================
 */
kal_uint32
qbmt_de_q_hif_ul_type(
		void **pp_src_head, 
		void **pp_src_tail, 
		void **pp_new_head, 
		void **pp_new_tail
		);

kal_uint32
qbmt_de_q_hif_ul_type_n(
		void **pp_src_head, 
		void **pp_src_tail, 
		kal_uint32 max_n,
		void **pp_new_head,
		void **pp_new_tail
		);

#define qbmt_de_q_hif_ul   qbmt_de_q_hif_ul_type
#define qbmt_de_q_hif_ul_n qbmt_de_q_hif_ul_type_n

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbmt_de_q_tx_n
 *  Description:  DeQ TGPD from QMU. This API will check the HWO bit.
 *                If HWO bit is 0, the buffer will be de-q from the QMU.
 *                It only invalid TGPD.
 *
 *    pp_src_head, pp_src_tail 
 *       Original TGPD queue on QMU (May be used to transmit data to host)
 *       After de-q, the *pp_src_head will be updated to the next of the last buffer(*pp_new_tail).
 *    
 *    n: Max de-q number.
 *    
 *    pp_new_head, pp_new_tail
 *       The de-queued buffer list will be stored here.
 *
 *    Return: The number of de-queued TGPD.
 *          
 * =====================================================================================
 */
kal_uint32
qbmt_de_q_tx_n(
		void **pp_src_head, 
		void **pp_src_tail, 
		kal_uint32 max_n,
		void **pp_new_head,
		void **pp_new_tail
		);
kal_uint32
qbmt_de_q_tx(
		void **pp_src_head, 
		void **pp_src_tail, 
		void **pp_new_head,
		void **pp_new_tail
		);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbm_set_extended_param
 *  Description:  Set extended parameter value.
 *                Used for some queue operation.
 *                1. dynamic allow length for USB dynamic chunk size.
 *
 *                User should know the queue operation when set it.
 * =====================================================================================
 */
void
qbm_set_extended_param(kal_uint32 type, kal_int32 value);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbm_set_non_free
 *  Description:  Set the PD as non-free type.
 *                Used when user want to use their own buffer, (non-allocated from BM)
 *                It should cooperate with qbm_set_used and qbm_get_used APIs.
 *                Use set used to declare teh p_pd is used.
 *                Use get_used to check if the PD is released by the BM.
 *                User should reserve QBM_HEAD_SIZE before the p_pd.
 * =====================================================================================
 */
void
qbm_set_non_free(void *p_pd);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbm_init_queue_non_free
 *  Description:  Just like qbm_init_q,
 *                But it will init the all buffer as non-free type.
 *                The descriptors will be returned on pp_head and pp_tail.
 *
 *                Just help to split non-free type memory pool for easy usage.
 *                User also need to specify p_conf for the memory pool and buffer number.
 *
 *       Return:  qbm_error_code
 *       Note:    before use it, you should init p_conf first.
 *                This API won't affect qbm inner status. 
 * =====================================================================================
 */
kal_int32 
qbm_init_queue_non_free(qbm_type type, bm_queue_config *p_conf, void **pp_head, void **pp_tail);

/**
 * @brief qbm_init_queue_non_free_on_exception 
 * It's pure function, just split memory by QBM_TYPE_TGPD format.
 * If code section is protected, this API should always works.
 * May be used on exception handler.
 *
 * The descriptors will be returned on pp_head and pp_tail.
 *
 * @param p_conf 
 * @param pp_head
 * @param pp_tail
 *
 * @return qbm_error_code
 */
kal_int32 
qbm_init_queue_non_free_tgpd(bm_queue_config *p_conf, void **pp_head, void **pp_tail);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbm_get_used
 *  Description:  Non-Free type API.
 *                Check the used bit in BM Header.
 *                Used to check if the PD is released by BM.
 * =====================================================================================
 */
kal_uint32
qbm_get_used(void *p_pd);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbm_set_used
 *  Description:  Non-Free type API.
 *                Set the PD as used.
 *                Set it before en-q it to QMU.
 * =====================================================================================
 */
void
qbm_set_used(void *p_pd);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbm_reset_pd
 *  Description:  Used to reset PD format by the specified type. 
 *                It just reset the format to the format by document. 
 *                The checksum will usually be 0.
 * =====================================================================================
 */
void
qbm_reset_pd(qbm_type type, void *p_pd);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbm_env_is_dma_only_noncacheable
 *  Description:  Used to check current environment DMA only support non-cacheable address
 *                KAL_TRUE: DMA only can access non-cacheable memory address.
 *                KAL_FALSE: Normal case, DMA can access cache and noncache address.
 *  Need qbm_init: No
 * =====================================================================================
 */
kal_bool
qbm_env_is_dma_only_noncacheable(void);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbm_reg_cbk_notify_pool_status
 *  Description:  Used to register callback functino for QBM Pool size status notification.
 *  Need qbm_init: Yes
 * =====================================================================================
 */
typedef void (*qbm_pool_status_func_ptr)(qbm_pool_status status);
void qbm_reg_cbk_notify_pool_status(qbm_pool_status_func_ptr fptr);

/* 
 * Simple GPD list management.
 * Used for data queue.
 * We can use the same operation (Don't check null) by reserved head memory space.
 */
typedef struct 
{
    qbm_gpd head;
    qbm_gpd *p_tail;
}qbm_gpd_list;

/*
 * Clear the data list.
 * Just reset p_tail to head
 */
#define qbm_gpd_list_clr(_p) \
    (_p)->p_tail = &((_p)->head)

/*
 * Check if the data list is empty.
 */
#define qbm_gpd_list_is_empty(_p) \
    ((_p)->p_tail == &((_p)->head))

/*
 * Get first PD node
 */
#define qbm_gpd_list_get_head(_p) \
    QBM_DES_GET_NEXT(&(_p)->head)

/*
 * Get last PD node
 */
#define qbm_gpd_list_get_tail(_p) \
    (_p)->p_tail

/*
 * Add GPD to the list
 */
#define qbm_gpd_list_add(_p, _pd)        \
{                                        \
    QBM_DES_SET_NEXT((_p)->p_tail, _pd); \
    (_p)->p_tail = (qbm_gpd*)_pd;        \
}

/*
 * Add GPD list to the list
 * _pd_h, the new list head
 * _pd_t, the new list tail
 */
#define qbm_gpd_list_add_list(_p, _pd_h, _pd_t) \
{                                               \
    QBM_DES_SET_NEXT((_p)->p_tail, _pd_h);      \
    (_p)->p_tail = (qbm_gpd*)_pd_t;             \
}

/**
 * @brief qbm_gpd_list_dest 
 * Drop the PD on the list and reset the list to empty.
 *
 * @param _p
 *
 * @return 
 */
#define qbm_gpd_list_drop(_p)              \
{                                          \
    if (!qbm_gpd_list_is_empty(_p)) {      \
        qbmt_dest_q(                       \
                qbm_gpd_list_get_head(_p), \
                qbm_gpd_list_get_tail(_p)  \
                );                         \
        qbm_gpd_list_clr(_p);              \
    }                                      \
}


#endif   /* ----- #ifndef QMU_BM_UTIL_INC  ----- */

