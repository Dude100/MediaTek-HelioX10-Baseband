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
 *   qmu_bm.h
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
 * 	//MOLY_CBr/tj.chang/MOLY_Profile.w1352p1/mcu/...
 *  	
 * 	to //MOLY/TRUNK/MOLY/mcu/...
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * add QMU_BM EM stats.
 *
 * removed!
 * removed!
 * Back out changelist 156018
 * patch for QMU_BM/UPCM/RATADP/TFT_PF trace
 *
 * removed!
 * removed!
 * add tft_pf/qmu_bm/upcm/ratadp trace
 *
 * removed!
 * removed!
 * separate flc related function from  qmu_bm.h to qmu_bm_flc.h
 *
 * removed!
 * removed!
 * add comment for qbmt_alloc_q_no_tail() can use qbmt_common_en_q_rx.
 *
 * removed!
 * removed!
 * add QBM_TYPE_MSD
 *
 * removed!
 * removed!
 * multi-mode data path support.
 ****************************************************************************/
/*QMU BM export header file*/
#ifndef QMU_BM_H
#define QMU_BM_H

#include "qbm_features.h"
#include "qmu_bm_enum.h"

/*************************************************************************
 * Note!!
 * qmu_bm APIs only can be used on thread contex.
 * Because of it uses mutex to protect state.
 * So user can't use it on ISR/HISR context.
 *
 * Sample Code:
 * Init qmu_bm first. (Note: it only need to be inited once)
 *
   qbm_init();
 * 
 * Now just init queue.
 * Before init queue, we need to allocate a memory 
 * The memory is from outside, BM just manager it.
 * We need to init a config file fist.
 * And then know the pool size and allocate enough memory.
 *
 
    // static memory for buffer pool.
    kal_uint8 g_pool[QBM_QUEUE_GET_MEM_SIZE(QBM_SIZE_HIF_DL, 100)];

	bm_queue_config conf;

	qbm_init_q_config(&conf);
    size = qbm_queue_get_mem_size(QBM_TYPE_HIF_DL, 100);
	conf.buff_num = 100;
    conf.p_mem_pool_str = g_pool;
    conf.p_mem_pool_end = g_pool + size;
	qbm_init_queue(
			QBM_TYPE_HIF_DL,
			&conf
			);
    
 * or managed by QMU_BM.
 * add the buffer config in qbm_config.h
 
 *  
 *  Now we can use this type buffer now.
 *
    ptr = QBM_ALLOC_ONE(QBM_TYPE_HIF_DL);
    QBM_FREE_ONE(ptr);

    qbmt_alloc_q(QBM_TYPE_HIF_DL, 50, &hif->p_head, &hif->p_tail);
    qbmt_reload_q(QBM_TYPE_HIF_DL, 50, &hif->p_head, &hif->p_tail);
 *
 *************************************************************************/
#include "kal_public_api.h"
#include "qmu_bm_in.h"
#include "qmu_bm_size.h"

/*************************************************************************
 * Type Definitions
 *************************************************************************/
/** 
 * @brief common structure for GPD/BD header
 */
typedef struct _qbm_gpd qbm_gpd;
struct _qbm_gpd
{
    kal_uint8   flags;
    kal_uint8   chksum;
    kal_uint16  reserved1;
    /*
     * It only can be used on 32 bits CPU, this pointer implies kal_uint32 
     * Declared as pointer is used for ICE debug easily.
     */
    qbm_gpd    *p_next;
    void       *p_data_tbd;
    kal_uint16  data_len;
    kal_uint8   ext_len;
    kal_uint8   reserved2;
};

#define QBM_HEAD_SIZE   QBM_CACHE_SIZE
/*
 * Buffer header format.
 * Reserve 12 bytes first.
 *
 * If use want to access bm_header member,
 * Please use GET_BM_HDR_PTR(_p)->xxx.
 */
typedef struct
{
	kal_uint16 mcode_used;
	kal_uint8  type;
	kal_uint8  flc_pool_id;
	kal_uint32 rsv1;
	kal_uint32 rsv2;
}_bm_header_in;

/* 
 * Put SW control field first.
 * So we can detect if User use too much memory by mcode.
 */
typedef struct
{
    kal_uint8     sw_ctrl_field[QBM_HEAD_SIZE - sizeof(_bm_header_in)];
    _bm_header_in header;
}bm_header;

#define GET_BM_HDR_PTR(_p) (&(((bm_header*)((kal_uint8*)(_p) - QBM_HEAD_SIZE))->header))

/* 
 * Get buffer type of the descriptor.
 * @param _p PD/BD start address.
 * @return buffer type (qbm_type)
 */
#define QBM_GET_TYPE(_p) \
	(GET_BM_HDR_PTR(_p)->type)

#define QBM_SET_TYPE(_p, _t) \
	(GET_BM_HDR_PTR(_p)->type = _t )

/* 
 * Different type will have different format.
 * The formats are pre-defined.
 * For different buffer formats. 
 * See the document
 * http://teams.mediatek.inc/sites/LTE/Software%20Engineering/presentation/20110810_QMU_Intro_Moja/QMU_BM_buffer_format_1.01.pptx
 *
 * Add new buffer type working flow.
 * QBM_TYPE_XXX is moved to qmu_bm_enum.h
 * 1) define a QBM_TYPE_XXX (Should follow the attribute)
 * 2) define QBM_SIZE_XXX in qmu_bm_size.h
 * 3) add the QBM_SZIE_XXX to the right position in _g_qbm_size_ary in qmu_bm_queue.c
 * 4) add unit test case in t_get_size in qmu_bm_queue.c if needed check content in t_chk_content
 *    -> for RX queue, can test it in t_rx_data_size in qmu_bm.c 
 *       (if the queue type is normal, just fill the type in _g_tst_rx_data_type)
 * 5) add reset buffer function and init buffer function in qbm_queue.c
      -> fill the table _g_queue_inif_conf_tbl[]
 * 6) If needed add the entry size in _get_per_entry_size. (for some special case)
 * 7) If the type is pseudo type, remember to modify 
 *        qbm_get_buff_remain_num(qbm_type type)
 *        _qbm_alloc_q() or qbm_alloc_one() by demand
 * 8) Finished, now you can use this type after call qbm_init_queue(QBM_TYPE_XXX, queue_conf)
 *
 * UT case:
 * add check format in t_chk_content in qmu_bm_queue.c
 */
#define QBM_TYPE_IS_ONLY_DESCRIPTOR(_t) (QBM_TYPE_TGPD    <= (_t) && (_t) < QBM_TYPE_ESRB_UL)
#define QBM_TYPE_IS_GPD_DATA(_t)        (QBM_TYPE_ESRB_UL <= (_t) && (_t) < QBM_TYPE_HIF_DL)
#define QBM_TYPE_IS_GPD_BD_DATA(_t)     (QBM_TYPE_HIF_DL  <= (_t) && (_t) < QBM_TYPE_NON_FREE)
#define QBM_TYPE_IS_PSEUDO(_t)          (QBM_TYPE_NON_FREE <= (_t))

/* 
 * anchor type for HIF_UL 
 * We also has qbmt_de_q_hif_ul anchor function.
 */
#define QBM_TYPE_HIF_UL QBM_TYPE_HIF_UL_TYPE


typedef struct
{
    /* used to check if the config is inited or not */
    kal_uint32 mcode;

    /* Total buffer number */
    kal_uint32 buff_num;

    /* 
     * The data part need to be invalidate when de-Q from QMU 
     * It may be used on command queue.
     * For user plane data (TCP/IP packet, user should set this flag to KAL_FALSE)
     * Becuase we don't need to see the whole packet content.
     *
     * Note: the flag is only used when using the de-q api provided by qbm.
     * (e.g. qbmt_de_q )
     * User also can do invalidate thing by himself.
     */
    kal_bool   b_cache_invalid;

    /* 
     * The buffer need to be flused before en-Q 
     * It may be used on event buffer.
     * For user plane data (TCP/IP packet, user should set this flag to KAL_FALSE)
     * Becuase we don't need to flush the whole packet content.
     *
     * Note: the flag is only used when using the en-q api provided by qbm.
     * (e.g. qbmt_common_en_q)
     * User also can do flush thing by himself.
     */
    kal_bool   b_cache_flush;

	/*  
	 *  Memory pool start/end address.
	 */
	kal_uint8* p_mem_pool_str;
	kal_uint8* p_mem_pool_end;
} bm_queue_config;

/*************************************************************************
 * Exported Macros
 *************************************************************************/
#define DES_FLAG_BIT_HWO  0x01
#define DES_FLAG_BIT_EOL  0x01
#define DES_FLAG_BIT_BDP  0x02
#define DES_FLAG_BIT_BPS  0x04
#define DES_FLAG_BIT_IOC  0x80

#define QBM_GET_GPD_PTR(_p) ((qbm_gpd*)(_p))

#define QBM_DES_SET_HWO(_p) \
          (QBM_GET_GPD_PTR(_p)->flags |= DES_FLAG_BIT_HWO)

#define QBM_DES_CLR_HWO(_p) \
          (QBM_GET_GPD_PTR(_p)->flags &= ~DES_FLAG_BIT_HWO)

#define QBM_DES_GET_HWO(_p) \
          (QBM_GET_GPD_PTR(_p)->flags & DES_FLAG_BIT_HWO)

#define QBM_DES_SET_BDP(_p)             \
          (QBM_GET_GPD_PTR(_p)->flags |= DES_FLAG_BIT_BDP)

#define QBM_DES_CLR_BDP(_p)             \
          (QBM_GET_GPD_PTR(_p)->flags &= ~DES_FLAG_BIT_BDP)

#define QBM_DES_GET_BDP(_p) \
          (QBM_GET_GPD_PTR(_p)->flags & DES_FLAG_BIT_BDP)

#define QBM_DES_SET_BPS(_p) \
          (QBM_GET_GPD_PTR(_p)->flags |= DES_FLAG_BIT_BPS)

#define QBM_DES_CLR_BPS(_p) \
          (QBM_GET_GPD_PTR(_p)->flags &= ~DES_FLAG_BIT_BPS)

#define QBM_DES_GET_BPS(_p) \
          (QBM_GET_GPD_PTR(_p)->flags & DES_FLAG_BIT_BPS)

#define QBM_DES_SET_IOC(_p) \
          (QBM_GET_GPD_PTR(_p)->flags |= DES_FLAG_BIT_IOC)

#define QBM_DES_CLR_IOC(_p) \
          (QBM_GET_GPD_PTR(_p)->flags &= ~DES_FLAG_BIT_IOC)

#define QBM_DES_GET_IOC(_p) \
          (QBM_GET_GPD_PTR(_p)->flags & DES_FLAG_BIT_IOC)

#define QBM_DES_SET_EOL(_p) \
          (QBM_GET_GPD_PTR(_p)->flags |= DES_FLAG_BIT_EOL)

#define QBM_DES_CLR_EOL(_p) \
          (QBM_GET_GPD_PTR(_p)->flags &= ~DES_FLAG_BIT_EOL)

#define QBM_DES_GET_EOL(_p) \
          (QBM_GET_GPD_PTR(_p)->flags & DES_FLAG_BIT_EOL)

#ifdef __ENABLE_QMU_CHECKSUM__
#define QBM_DES_SET_CHKSUM(_p, _chk) \
          (QBM_GET_GPD_PTR(_p)->chksum = (_chk))
#else
#define QBM_DES_SET_CHKSUM(_p, _chk)
#endif

#define QBM_DES_GET_CHKSUM(_p) \
          QBM_GET_GPD_PTR(_p)->chksum

#define QBM_DES_SET_ALLOW_LEN(_p, _len) \
          (QBM_GET_GPD_PTR(_p)->reserved1 = (kal_uint16)(_len))

#define QBM_DES_GET_ALLOW_LEN(_p) \
          (QBM_GET_GPD_PTR(_p)->reserved1)

#define QBM_DES_SET_NEXT(_p, _nxt)           \
          QBM_GET_GPD_PTR(_p)->p_next = (qbm_gpd*)(_nxt)

#define QBM_DES_GET_NEXT(_p) \
          (QBM_GET_GPD_PTR(_p)->p_next)

#define QBM_DES_SET_DATAPTR(_p, _dp)     \
          (QBM_GET_GPD_PTR(_p)->p_data_tbd = (kal_uint8*)(_dp))

#define QBM_DES_GET_DATAPTR(_p) \
          (QBM_GET_GPD_PTR(_p)->p_data_tbd)

#define QBM_DES_GET_DATALEN(_p) \
          QBM_GET_GPD_PTR(_p)->data_len

#define QBM_DES_SET_DATALEN(_p, _l) \
          QBM_GET_GPD_PTR(_p)->data_len = (kal_uint16)(_l)

#define QBM_DES_GET_EXTLEN(_p) \
          QBM_GET_GPD_PTR(_p)->ext_len

#define QBM_DES_SET_EXTLEN(_p, _l) \
          QBM_GET_GPD_PTR(_p)->ext_len = (_l)

#define QBM_DES_GET_EXT(_p) \
          ((kal_uint8*)(_p) + sizeof(qbm_gpd)) 

/* 
 * SW control field are stored in front of the BM header.
 * We reserve CACHE size for total QBM_HEAD.
 * If the CACHE SIZE is 32 bytes, the SW control field is 32 - sizeof(bm_header)
 * Currently the sw control field space is 20 bytes.
 * 
 * The field is cast by the user to fill their proprietary structure.
 */
#define QBM_DES_GET_SW_CTRL_FIELD(_p) ((kal_uint8*)(_p) - QBM_HEAD_SIZE)
/*************************************************************************
 * Exported Function Prototypes
 *************************************************************************/
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbm_init
 *  Description:  Init QMU BM. 
 *  Note: 
 *  After init QMU BM, *  user also need to init it's needed queue befroe use the queue.
 * =====================================================================================
 */
kal_bool qbm_init(void);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbm_queue_get_mem_size
 *  Description:  Get total needed size of the queue.
 *                User should use this API to get the needed size.
 *                And allocate enough memory to init the queue.
 * =====================================================================================
 */
kal_uint32 qbm_queue_get_mem_size(qbm_type type, kal_uint32 buff_num);

/*
 * Constant get needed memory size.
 * So user can use it on the static memory. (e.g. kal_uint8 HIF_DL_MEM[QBM_QUEUE_GET_MEM_SIZE()]; )
 * The _sz is defined in qmu_bm_size.h.
 * User should have knowledge of the size for its queue.
 * 
 * QBM_CACHE_SIZE is added for first buffer cache aligned.
 * Because all size is cache aligned, so only care about first buffer.
 *
 * Now we have the following size can be used.
 *
 * QBM_SIZE_TGPD 
 * QBM_SIZE_TBD 
 * QBM_SIZE_TGPD_BYPSS     
 * QBM_SIZE_HIF_DL      
 * ... others can be found in qmu_bm_size.h
 */
#define QBM_QUEUE_GET_MEM_SIZE(_sz, _buf_num) ((_sz)*((_buf_num) + 1) + QBM_CACHE_SIZE)

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbm_init_q_config
 *  Description:  init the queue config structure to default value.
 *                User can overwrite its config after init the config.
 * =====================================================================================
 */
void qbm_init_q_config(bm_queue_config *p_conf);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbm_init_queue
 *  Description:  Before use the queue, user should init the queue first.
 *                The buffer number is bound by the real memory pool size and configure buffer_num.
 *                => The buffer number may be restricted 
 *                    by p_conf->p_mem_pool_str and p_conf->p_mem_pool_end
 *                 or by p_conf->buff_num.
 *       Return:  qbm_error_code
 *       Note:    before use it, you should init p_conf first.
 * =====================================================================================
 */
kal_int32 qbm_init_queue(qbm_type type, bm_queue_config *p_conf);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbm_get_buff_remain_num
 *  Description:  Get how many remain buffers in the specified buffer type.
 * =====================================================================================
 */
kal_uint32 qbm_get_buff_remain_num(qbm_type type);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbm_cal_set_checksum
 *  Description:  Calculate checksum and set it.
 *                For easy and quick, the checksum length is fix to 12 bytes.
 *                If you need to test other length, 
 *                use qbm_cal_set_checksum_by_len in qbm_util.h
 * =====================================================================================
 */
#ifdef __ENABLE_QMU_CHECKSUM__
void       qbm_cal_set_checksum(const kal_uint8 * const data);
kal_uint32 qbm_cal_checksum(const kal_uint8 * const data);
#else
#define qbm_cal_set_checksum(_d)
#define qbm_cal_checksum(_d) 0
#endif

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  QBM_ALLOC_ONE
 *  Description:  allocate one buffer. 
 *                It's a wrap API. user should use it to allocate buffer.
 *
 *         TODO: debug feature. (may store filename, lineno)
 *               #define QBM_ALLOC_ONE(type) qbm_alloc_one2(type, __FILE__, __LINE__)
 *
 *        Return: void *, buffer pointer address.
 *                NULL if no buffer returned.
 * =====================================================================================
 */
#define QBM_ALLOC_ONE(type) qbm_alloc_one(type)

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  QBM_ALLOC_ONE_CHK
 *  Description:  Just like qbm_alloc_one, but this API will check if the queue is empty.
 *                If empy, this API will call assertion.
 *                Used when user always can allocate buffer scenario.
 *                Reduce code size. (check NULL in the center)
 *        Return: void *, buffer pointer address.
 * =====================================================================================
 */
#define QBM_ALLOC_ONE_CHK(type) qbm_alloc_one_chk(type)

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  QBM_FREE_ONE
 *  Description:  Only free one buffer.
 *       Return:  qbm_error_code
 * =====================================================================================
 */
#define QBM_FREE_ONE(ptr) qbm_free_one(ptr)


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  QBM_FREE_PD_BD
 *  Description:  Free PD and all BD list.
 *                This API will check BDP in the PD,
 *                If BDP is 1, it will release all BD list linked with the PD.
 *
 *       Return:  qbm_error_code
 * =====================================================================================
 */
#define QBM_FREE_PD_BD(p_pd) qbm_free_pd_bd(p_pd)
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbmt_dest_q
 *  Description:  Destroy the whole queue from p_head to p_tail.
 *                It also release the TBD link.
 *      p_tail:   If set to NULL, it means destroy from p_head to a NULL pointer.
 *      Return:   The freed GPD number.
 * =====================================================================================
 */
kal_uint32
qbmt_dest_q(void *p_head, void *p_tail);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbmt_free_q_hwo
 *  Description:  Release buffer from head to tail until HWO = 1 (not include tail).
 *                This API will check the HWO bit before release the GPD.
 *                It also release the TBD link.
 *                After release, the *pp_head will be updated to the first HWO = 1 GPD.
 *      Return:   The freed GPD number.
 * =====================================================================================
 */
kal_uint32
qbmt_free_q_hwo(void **pp_head, void **pp_tail);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbmt_alloc_q
 *  Description:  Allocate a descriptor list in one time.
 *                It will return the list to the pp_head and pp_tail.
 *                The last descriptor HWO will be set to 0 for tail.
 *
 *                Use scenario:
 *                  when user want to init a new queue for HW. 
 *                  This API should only be called in the first time.
 *                  After that, user should use qbmt_reload_q to reload buffer.
 *               
 *               Note:
 *                 This API is suitable for GPD/BD with data buffer type.
 *                 For pure GPD/BD case, use QBM_ALLOC_ONE otherwise 
 *                 user should know the buffer looking when use this API.
 *
 *        type:     qbm_type
 *        buff_num: buffer number
 *        pp_head:  return allocated list header.
 *        pp_tail:  return allocated list tail.
 *
 *       Return:  Number of buffers allocated.
 * =====================================================================================
 */
kal_uint32
qbmt_alloc_q(
        kal_uint32 type,
        kal_uint32 buff_num,
        void **pp_head, 
        void **pp_tail
        );

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbmt_alloc_q_no_tail
 *  Description:  Just like qbmt_alloc_q, but the tail HWO is still 1.
 *                =>All descriptor's HWO is 1.
 *
 *                Use scenario:
 *                  when user want to allocate a new queue to receive data and do reload_q by other module.
 *                    can use qbmt_common_en_q_rx
 *                  when user want to allocate a new TGPD with data list to send data.
 *
 *        type:     qbm_type
 *        buff_num: buffer number
 *        pp_head:  return allocated list header.
 *        pp_tail:  return allocated list tail.
 *
 *       Return:  Number of buffers allocated.
 * =====================================================================================
 */
kal_uint32
qbmt_alloc_q_no_tail(
        kal_uint32 type,
        kal_uint32 buff_num,
        void **pp_head, 
        void **pp_tail
        );

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qbmt_reload_q
 *  Description:  Allocate a descriptor list in one time.
 *                This API also link the new list to the original queue.
 *                The pp_tail will be updated to the new list tail.
 *                The original tail HWO will be set to 1.
 *                The last descriptor HWO will be set to 0 for tail.
 *        type:     qbm_type
 *        buff_num: buffer number
 *        pp_head:  Original queue header.
 *        pp_tail:  Original queue tail.
 *       Return:  Number of buffers allocated.
 * =====================================================================================
 */
kal_uint32
qbmt_reload_q(
        kal_uint32 type,
        kal_uint32 buff_num,
        void **pp_head, 
        void **pp_tail
        );

#endif /* QMU_BM_H */
