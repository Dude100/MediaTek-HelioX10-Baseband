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
 *   cccidev_qbm.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines the common qmu_bm macros or inline functions for CCCI devices
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
 * [CCCI] CCCI new debug mechanism
 *
 * removed!
 * removed!
 * [CCCI RPC] Fix ccci rpc coding defect in ccci_rpc_receive_cb
 *
 * 09 06 2013 ap.wang
 * removed!
 *
 * removed!
 * removed!
 * [MOLY][CCCI] CCCIDEV_GET_QBM_DATALEN return GPD length even when there's BD
 *
 * 03 14 2013 ap.wang
 * removed!
 * [CCCIDEV] Add GPD cache flush after set checksum
 *
 * removed!
 * removed!
 * remove internal _reset_ccci_common
 *
 * removed!
 * removed!
 * Rename project name as MT6290
 *
 * removed!
 * removed!
 * sync latest version of new features
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#ifndef _CCCIDEV_QBM_H
#define _CCCIDEV_QBM_H
#include "kal_public_api.h"
#include "qmu_bm.h"
#include "qmu_bm_util.h"
#include "ccci_if.h"          /* ccci_io_request_t */

/*!
 * @function        [INLINE] CCCICOMM_SET_QBM_DATALEN
 * @brief           Set data length for QBM_TYPE_CCCI_COMM by QBM_DES_SET_DATALEN
 *
 * @param gpd       [IN] pointer to the GPD
 *
 * @return          void
 */
static __inline void CCCICOMM_SET_QBM_DATALEN(void* gpd, kal_uint32 data_len)
{
    void* bd = NULL;

    EXT_ASSERT(NULL != gpd, (kal_uint32)gpd, data_len, 0);
    /*QBM_TYPE_CCCI_COMM specific function*/
    EXT_ASSERT(QBM_TYPE_CCCI_COMM == QBM_GET_TYPE(gpd), (kal_uint32)QBM_GET_TYPE(gpd), (kal_uint32)gpd, data_len);
    /*Must have BD*/
    EXT_ASSERT(0 != QBM_DES_GET_BDP(gpd), (kal_uint32)QBM_DES_GET_BDP(gpd), (kal_uint32)gpd, data_len);

    bd = QBM_DES_GET_DATAPTR(gpd);
    EXT_ASSERT(NULL!=bd, (kal_uint32)gpd, (kal_uint32)bd, data_len);
    QBM_DES_SET_DATALEN(bd, data_len);
    qbm_cal_set_checksum((kal_uint8 *)bd);
    
    QBM_DES_SET_DATALEN(gpd, data_len);
    qbm_cal_set_checksum((kal_uint8 *)gpd);
}

/*!
 * @function        [INLINE] CCCIDEV_GET_QBM_DATALEN
 * @brief           Obtain the data length of first BD in GPD list. 
 *                  Possible application is used during inserting layer headers ex. CCCI headers.
 *
 * @param gpd       [IN] pointer to the GPD
 *
 * @return          Return gpd->1st_bd->data_len / gpd->data_len
 */
static __inline kal_uint32 CCCIDEV_GET_QBM_DATALEN(void* gpd)
{
    kal_uint32 data_len = 0;

    EXT_ASSERT(NULL!=gpd, (kal_uint32) gpd,0 ,0);
	/* user should put length in gpd.len 
	   gpd.len = bd.ext_len + bd.len */
	data_len = QBM_DES_GET_DATALEN(gpd);
    return data_len;
}

/*!
 * @function        [INLINE] CCCIDEV_GET_QBM_DATAPTR
 * @brief           Obtain the pointer of data. 
 *
 * @param gpd       [IN] pointer to the GPD
 *
 * @return          Return gpd->1st_bd->p_data_tbd / gpd->p_data_tbd
 */
static __inline void* CCCIDEV_GET_QBM_DATAPTR(void* gpd)
{
    void* bd = NULL;
    void* data_ptr = NULL;
    
    EXT_ASSERT(NULL!=gpd, (kal_uint32) gpd, 0, 0);
    if(0 != QBM_DES_GET_BDP(gpd)){
        //4 <case 1> GPD->BD->BUFF
        bd = QBM_DES_GET_DATAPTR(gpd);
        EXT_ASSERT(NULL!=bd, (kal_uint32) bd, (kal_uint32) gpd, 0);
        data_ptr = QBM_DES_GET_DATAPTR(bd);
    }else{
        //4 <case 2> GPD->BUFF        
        data_ptr = QBM_DES_GET_DATAPTR(gpd);
    }

    EXT_ASSERT(NULL!=data_ptr, (kal_uint32) data_ptr, (kal_uint32) bd, (kal_uint32) gpd);
    return data_ptr;
}

/*!
 * @function        [INLINE] CCCIDEV_GET_GPD_LIST_SIZE
 * @brief           Traverse the GPD chain to obtain the number of GPDs in GPD chain. 
 *
 * @param head      [IN] pointer to the head of the GPD chain
 * @param tail      [IN] pointer to the tail of the GPD chain
 *
 * @return          Number of the GPDs in GPD chain. 
 */
static __inline kal_uint32 CCCIDEV_GET_GPD_LIST_SIZE(qbm_gpd *head, qbm_gpd *tail)
{
    kal_uint32          cnt = 0;

    if (tail) {
        while (head) {
            cnt++;
            if (head != tail) {
                head = QBM_DES_GET_NEXT(head);
            } else {
                break;
            }
        }
    }

    return cnt;
}

/*!
 * @function        [INLINE] CCCIDEV_GET_NONBPS_GPD_LIST_SIZE
 * @brief           Traverse the GPD chain to obtain the number of NON-bypass GPDs in GPD chain. 
 *
 * @param head      [IN] pointer to the head of the GPD chain
 * @param tail      [IN] pointer to the tail of the GPD chain
 *
 * @return          Number of the non-bypass GPDs in GPD chain. 
 */
static __inline kal_uint32 CCCIDEV_GET_NONBPS_GPD_LIST_SIZE(qbm_gpd *head, qbm_gpd *tail)
{
    kal_uint32          cnt = 0;

    if (tail) {
        while (head) {
            cnt += (0 == QBM_DES_GET_BPS(head));
            if (head != tail) {
                head = QBM_DES_GET_NEXT(head);
            } else {
                break;
            }
        }
    }

    return cnt;
}

/*!
 * @function        [INLINE] CCCIDEV_PUSH_QBM_DATAHEAD
 * @brief           Push the Tx GPD/BD data pointer. i.e. increase the header room
 *                  1. move the GPD->1st_BD->data / GPD->data pointer back "offset"
 *                  2. increase the BD length
 *                  3. DO NOT flush the Tx BD header -> QMU enqueue should do it
 *                     Please refer to the mail 20120606 from YiLun
 *                     >  Folder:  0WCP\0. important announce\programming related
 *                     >  [Note] CACHE op convention : upper user no need to take TX GPD/BD cache flush(clean)
 *                  4. set gpd data length
 *                  5. DO NOT flush the Tx GPD header -> QMU enqueue should do it
 *                  reference : ETHC_CORE_PUSH_QBM_DATAHEAD
 *
 * @param gpd       [IN] pointer to the GPD need modification
 * @param offset    [IN] move the data_ptr by offset
 *
 * @return          void
 */
static __inline void CCCIDEV_PUSH_QBM_DATAHEAD(void* gpd, kal_uint32 offset)
{
    void* bd = NULL;
    kal_uint8* data_ptr = NULL;
    kal_uint32 data_len = 0;

    if(0 != QBM_DES_GET_BDP(gpd)){
        //4 <case 1> GPD->BD->BUFF
        /* set bd data ptr */
        bd = QBM_DES_GET_DATAPTR(gpd);
        data_ptr =  (kal_uint8*)QBM_DES_GET_DATAPTR(bd);
        QBM_DES_SET_DATAPTR(bd, data_ptr-offset);
        /* set bd data len */
        data_len = QBM_DES_GET_DATALEN(bd);
        QBM_DES_SET_DATALEN(bd, data_len+offset);
        /* set bd checksum */
        qbm_cal_set_checksum(bd);

        /* set gpd data len */
        data_len = QBM_DES_GET_DATALEN(gpd);
        QBM_DES_SET_DATALEN(gpd, data_len+offset);
        /* set gpd checksum */
        //qbm_cal_set_checksum(gpd);
    }else{
        //4 <case 2> GPD->BUFF  
        /* set gpd data ptr */
        data_ptr =  (kal_uint8*)QBM_DES_GET_DATAPTR(gpd);
        QBM_DES_SET_DATAPTR(gpd, data_ptr-offset);
        /* set gpd data len */
        data_len = QBM_DES_GET_DATALEN(gpd);
        QBM_DES_SET_DATALEN(gpd, data_len+offset);
        /* set gpd checksum */
        //qbm_cal_set_checksum(gpd);
    }
}

/*!
 * @function        [INLINE] CCCIDEV_PULL_QBM_DATAHEAD
 * @brief           Pull the Tx GPD/BD data pointer. i.e. decrease the header room
 *
 *                  <Used in non-network GPD->BD->BUFF >
 *
 * @param gpd       [IN] pointer to the GPD need modification
 * @param offset    [IN] move the data_ptr by offset
 *
 * @return          void
 */
static __inline void CCCIDEV_PULL_QBM_DATAHEAD(void* gpd, kal_uint32 offset)
{
    void* bd = NULL;
    kal_uint8* data_ptr = NULL;
    kal_uint32 data_len = 0;

    if(0 != QBM_DES_GET_BDP(gpd)){
        //4 <case 1> GPD->BD->BUFF
        /* set bd data ptr */
        bd = QBM_DES_GET_DATAPTR(gpd);
        data_ptr =  (kal_uint8*)QBM_DES_GET_DATAPTR(bd);
        QBM_DES_SET_DATAPTR(bd, data_ptr+offset);
        /* set bd data len */
        data_len = QBM_DES_GET_DATALEN(bd);
        QBM_DES_SET_DATALEN(bd, data_len-offset);
        /* set bd checksum */
        qbm_cal_set_checksum(bd);
        QBM_CACHE_FLUSH(bd, sizeof(qbm_gpd));

        /* set gpd data len */
        data_len = QBM_DES_GET_DATALEN(gpd);
        QBM_DES_SET_DATALEN(gpd, data_len-offset);
        /* set gpd checksum */
        qbm_cal_set_checksum(gpd);
        QBM_CACHE_FLUSH(gpd, sizeof(qbm_gpd));
    }else{
        //4 <case 2> GPD->BUFF  
        /* set gpd data ptr */
        data_ptr =  (kal_uint8*)QBM_DES_GET_DATAPTR(gpd);
        QBM_DES_SET_DATAPTR(gpd, data_ptr+offset);
        /* set gpd data len */
        data_len = QBM_DES_GET_DATALEN(gpd);
        QBM_DES_SET_DATALEN(gpd, data_len-offset);
        /* set bd checksum */
        qbm_cal_set_checksum(gpd);
        QBM_CACHE_FLUSH(gpd, sizeof(qbm_gpd));
    }
}

/*!
 * @function        [INLINE] CCCIDEV_QBM_ENQ
 * @brief           Enqueue p_new_head/p_new_tail to pp_orig_head/pp_orig_tail
 *
 * @param p_new_head    [IN] head of new gpd chain
 * @param p_new_tail    [IN] tail of new gpd chain
 * @param pp_orig_head  [IN/OUT] head of original gpd chain
 * @param pp_orig_tail  [IN/OUT] tail of original gpd chain
 *
 * @return          void
 */
static __inline void CCCIDEV_QBM_ENQ(void *p_new_head, void *p_new_tail, void **pp_orig_head, void **pp_orig_tail)
{
    kal_uint8 *p_ori_tail;
    p_ori_tail = *pp_orig_tail;

    if(*pp_orig_head == NULL){
        *pp_orig_tail = p_new_tail;
        *pp_orig_head = p_new_head;
    }else{
        /* link new queue */
        QBM_DES_SET_NEXT(p_ori_tail, p_new_head);
        // change tail to new tail
        *pp_orig_tail = p_new_tail;
    }
    QBM_DES_SET_NEXT(*pp_orig_tail, NULL);
}

/*!
 * @function        [INLINE] CCCIDEV_QBM_DEQ
 * @brief           dequeue n GPD from pp_src_head/pp_src_tail to p_new_head/p_new_tail
 *                  a accelerate version of qbmt_de_q_n
 *
 * @param pp_src_head   [IN/OUT] head of src gpd chain
 * @param pp_src_tail   [IN/OUT] tail of src gpd chain
 * @param n             [IN] dequeue count
 * @param pp_new_head   [OUT] head of dest gpd chain
 * @param pp_new_tail   [OUT] tail of dest gpd chain
 *
 * @return          void
 */
static __inline kal_uint32 CCCIDEV_QBM_DEQ(
		void **pp_src_head, 
		void **pp_src_tail, 
		kal_uint32 n,
		void **pp_new_head,
		void **pp_new_tail
		)
{
    kal_uint32 deq_num = 0;

    if(0 == n){
        *pp_new_head = NULL;
        *pp_new_tail = NULL;
        return 0;
    }

    if(NULL == *pp_src_head){
        EXT_ASSERT(NULL == *pp_src_tail, (kal_uint32)*pp_src_head, (kal_uint32) *pp_src_tail, 0);
        *pp_new_head = NULL;
        *pp_new_tail = NULL;
        return 0;
    }

    *pp_new_head = *pp_src_head;


    //for(deq_num = 0; deq_num < n; deq_num++){
    do{ 
        *pp_new_tail = *pp_src_head;
        deq_num++;
        *pp_src_head = QBM_DES_GET_NEXT(*pp_src_head);
    }while((deq_num < n) && (NULL != *pp_src_head));

    if(NULL == *pp_src_head){
        *pp_src_tail = NULL;
    }
    
    return deq_num;
}

/*!
 * @function        [INLINE] CCCIDEV_FIX_IOR_NULL_LAST
 * @brief           if the last gpd of ior is == NULL, traverse the GPD chain to fill the last_gpd info
 *
 * @param ior       [IN] input ior
 *
 * @return          void
 */
static __inline void CCCIDEV_FIX_IOR_NULL_LAST(ccci_io_request_t* ior)
{
    qbm_gpd             *last_gpd = ior->last_gpd; 
    qbm_gpd             *first_gpd = ior->first_gpd;
    qbm_gpd             *current_gpd;
    
    /*  fix the last_gpd == NULL case */
    if (last_gpd == NULL)
    {
        current_gpd = first_gpd;
        while ( current_gpd->p_next != NULL )
        {
            current_gpd = current_gpd->p_next;
        }
        ior->last_gpd = current_gpd;
    }
}


/*!
 * @function        [INLINE] CCCIDEV_RM_CCCI_HEADERS 
 * @brief           Tool function to remove the CCCI header in GPD->BD->BUFF / GPD->BUFF
 *
 * @param channel   [IN] channel number for this CCCI header
 * @param gpd       [IN] pointer to the gpd
 *
 * @return          KAL_TRUE: success, KAL_FALSE: channel number not matched
 */
static __inline kal_bool CCCIDEV_RM_CCCI_HEADERS(CCCI_CHANNEL_T channel, qbm_gpd *gpd)
{
    CCCI_BUFF_T         *pdata;

    //4 <1> check gpd->bd->buff->channel = channel
    pdata = CCCIDEV_GET_QBM_DATAPTR(gpd);
    EXT_ASSERT(pdata, (kal_uint32)pdata, (kal_uint32)gpd, (kal_uint32)channel);

    /* treat channel not match and size = 0 as invalid GPD*/
    if(GET_CCCI_CHANNEL(pdata->channel) != channel || pdata->data[1] == sizeof(CCCI_BUFF_T)){
        //hif_trace_error(CCCIDEV_TR_UL_CCCI_CH_ERR, pdata->channel, channel);
        return KAL_FALSE;
    }else{
        //4 <2> move data pointer to raw data
        CCCIDEV_PULL_QBM_DATAHEAD(gpd, sizeof(CCCI_BUFF_T));
    }

    return KAL_TRUE;
}

/*!
 * @function        [INLINE] ccci_dest_ior
 * @brief           Traverse ior chain to free the linked ior/GPD/BD/Buff 
 *
 * @param ior       [IN] pointer to the ior chain
 *
 * @return          void
 */
static __inline void ccci_dest_ior(ccci_io_request_t *ior){
    ccci_io_request_t    *next_ior;
    qbm_gpd*            current_gpd;

    EXT_ASSERT(ior, (kal_uint32)ior, 0, 0);
    for (; ior; ior = next_ior) {
        next_ior = ior->next_request;
        EXT_ASSERT(ior->first_gpd, (kal_uint32)ior->first_gpd, (kal_uint32)ior,  (kal_uint32)next_ior);

        /*  fix the last_gpd == NULL case */
        if (ior->last_gpd == NULL)
        {
            current_gpd = ior->first_gpd;
            while ( current_gpd->p_next != NULL )
            {
                current_gpd = current_gpd->p_next;
            }
            ior->last_gpd = current_gpd;
        }
        
        EXT_ASSERT(ior->first_gpd && ior->last_gpd, (kal_uint32)ior->first_gpd, (kal_uint32)ior->last_gpd, (kal_uint32)ior);
        qbmt_dest_q(ior->first_gpd, ior->last_gpd);
    }
}

/* Get address by a offset of the PD */
#define CCCIDEV_QBM_DES_GET_ADDR_BY_OFFSET(_p, _ofst)  \
          (void*)((kal_uint8*)(_p) + (_ofst))

/*  Used for buffer and descriptor are in continus memory address */
#define CCCIDEV_QBM_DES_SET_DATA_BY_OFFSET(_p, _ofst)  \
          (QBM_GET_GPD_PTR(_p)->p_data_tbd = CCCIDEV_QBM_DES_GET_ADDR_BY_OFFSET(_p, _ofst))

#define CCCI_COMM_BD_OFST    (64) /* p_data_tbd = 64 */
#define CCCI_COMM_GET_BD(_p) CCCIDEV_QBM_DES_GET_ADDR_BY_OFFSET(_p, CCCI_COMM_BD_OFST)

/* this code will set datalen and extlen to 0 */
/* Because in descriptor, they are in the 12 bytes */
#define CCCI_COMM_RESET_DATALEN_EXTLEN(_p) *(kal_uint32*)((kal_uint8*)(_p) + 12) = 0

/*!
 * @function        [INLINE] CCCIDEV_RST_CCCI_COMM_GPD_LIST
 * @brief           Reset the GPD list to the default value, type has to be QBM_TYPE_CCCI_COMM
 *
 * @param first_gpd [IN] pointer to the first GPD in the GPD chain
 * @param last_gpd  [IN] pointer to the last GPD in the GPD chain
 *
 * @return          void
 */
static __inline kal_uint32 CCCIDEV_RST_CCCI_COMM_GPD_LIST(qbm_gpd* first_gpd, qbm_gpd* last_gpd)
{
    qbm_gpd*            current_gpd = NULL;
    qbm_gpd*            next_gpd = NULL;
    kal_uint32          num_gpd = 0;
    
    EXT_ASSERT(first_gpd && last_gpd, (kal_uint32)first_gpd, (kal_uint32)last_gpd, 0);
    current_gpd = first_gpd;

    do {
        next_gpd = QBM_DES_GET_NEXT(current_gpd);
        qbm_reset_pd(QBM_TYPE_CCCI_COMM, (void*)current_gpd);
        qbm_cal_set_checksum((kal_uint8 *)current_gpd);
        QBM_CACHE_FLUSH(current_gpd, sizeof(qbm_gpd));
        num_gpd ++;
        if ( current_gpd == last_gpd )
        {
            break;
        }        
        current_gpd = next_gpd;
    } while ( current_gpd != NULL );

    return num_gpd;
}
#endif //#ifndef _CCCIDEV_QBM_H
