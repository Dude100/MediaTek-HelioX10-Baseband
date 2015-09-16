/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   kal_afm.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This header file defines data structure for KAL application fixed-size
 *   memory management.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef _KAL_AFM_H
#define _KAL_AFM_H

#include "kal_general_types.h"

/*******************************************************************************
 * define
 *******************************************************************************/

/**
   * enable internal debug functionality.
   */
//#define AFM_DEBUG

/*******************************************************************************
 * Constant definitions
 *******************************************************************************/

#define AFM_CB_ID         0x20100105
#define AFM_HEAD_STAMP    0x03F3F3F3
#define AFM_FOOT_STAMP    0x04F4F4F4
#define AFM_MAX_PRINT_LEN 128
#define AFM_INUSE         0
#define AFM_FREE          1
#define AFM_STS_BIT       1

#if 0 /* for GLOBAL INC,move to kal_public_defs.h */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
//#define AFM_SUBPOOL_END_PATTERN 0xFFFFFFFF

/*******************************************************************************
 * Data structure definitions
 *******************************************************************************/

typedef struct AFM_CB_STRUCT
{
    kal_uint32 id;
    kal_uint32 size;
    kal_uint16 subpool_nr;		
    kal_uint16 option;
    kal_uint16 owner; /*owner of afm,concurrent check*/
    kal_uint8 log_en;
    kal_uint8 reserved;
} AFM_CB_T;

typedef struct AFM_POOL_CB_STRUCT
{
    kal_uint32 buff_size;
    kal_uint16 buff_nr;
    kal_uint16 left_buff_nr;		
    struct AFM_MB_HEAD_STRUCT *free_head;
    struct AFM_MB_HEADGUD_STRUCT *static_head;
    struct AFM_POOL_CUSLOG_STRUCT *pool_cuslog;
} AFM_POOL_CB_T;

typedef struct AFM_POOL_CUSLOG_STRUCT
{
    kal_uint16 alloc_cnt;
    kal_uint16 min_left_buf_nr;
} AFM_POOL_CUSLOG_T;

typedef struct AFM_MB_HEAD_STRUCT
{
    struct AFM_MB_HEAD_STRUCT *next_free;
    AFM_POOL_CB_T *pool;		
} AFM_MB_HEAD_T;

typedef struct AFM_MB_HEADGUD_STRUCT
{
    struct AFM_MB_HEADGUD_STRUCT *static_next;
    kal_char *filename;
    kal_uint32 line;
    kal_uint32 stamp;    /* store a fixed pattern to check corruption */
} AFM_MB_HEADGUD_T;


typedef struct AFM_MB_FOOTGUD_STRUCT
{
	kal_uint32 stamp;   /* store a fixed pattern to check corruption */
} AFM_MB_FOOTGUD_T;


/*******************************************************************************
 * Macros definitions
 *******************************************************************************/

#define AFM_GET_INDEXED_SUBPOOL(afm_id, idx) (AFM_POOL_CB_T *)((kal_uint8*)(afm_id) + sizeof(AFM_CB_T) + (sizeof(AFM_POOL_CB_T) * (idx)))

#define AFM_GET_INDEXED_SUBPOOL_LOG(afm_id, idx) (AFM_POOL_CUSLOG_T *)((kal_uint8*)(afm_id) + sizeof(AFM_CB_T) + (sizeof(AFM_POOL_CB_T) * (((AFM_CB_T*)afm_id)->subpool_nr)) + (sizeof(AFM_POOL_CUSLOG_T) * (idx)))

#define AFM_GET_HEADGUD(afm_mb) (AFM_MB_HEADGUD_T *)((kal_uint8*)(afm_mb) + sizeof(AFM_MB_HEAD_T))

#define AFM_GET_FOOTGUD(afm_mb) (AFM_MB_FOOTGUD_T *)((kal_uint8*)(afm_mb) + sizeof(AFM_MB_HEAD_T) + sizeof(AFM_MB_HEADGUD_T) + ((AFM_MB_HEAD_T*)(afm_mb))->pool->buff_size)

#define AFM_SET_HEADGUD(afm_head, input_filename, input_line, gudptn) \
    { \
        ((AFM_MB_HEADGUD_T*)(afm_head))->filename = input_filename; \
        ((AFM_MB_HEADGUD_T*)(afm_head))->line = input_line; \
        ((AFM_MB_HEADGUD_T*)(afm_head))->stamp = gudptn; \
    }

#define AFM_SET_FOOTGUD(afm_foot, gudptn) \
    { \
        ((AFM_MB_FOOTGUD_T*)(afm_foot))->stamp = gudptn; \
    }

#define AFM_GET_FIRST_FREEHEAD(afm_id, subpool_sz, subpool_nr, buf_no, first_freehead) \
    { \
        kal_int32 idx, sz = 0; \
        for(idx = 0; idx < (buf_no); idx++) { \
            sz += ((subpool_sz[idx]+sizeof(AFM_MB_HEAD_T)) * subpool_nr[idx]); \
        } \
        first_freehead = (AFM_MB_HEAD_T *)((kal_uint8*)(afm_id) + sizeof(AFM_CB_T) + (sizeof(AFM_POOL_CB_T) * (afm_id->subpool_nr)) + sz); \
   }

#define AFM_GET_FIRST_FREEHEAD_GUDPTN(afm_id, subpool_sz, subpool_nr, buf_no, first_freehead) \
    { \
        kal_int32 idx, sz = 0; \
        for(idx = 0; idx < (buf_no); idx++) { \
            sz += ((subpool_sz[idx]+sizeof(AFM_MB_HEAD_T)+sizeof(AFM_MB_HEADGUD_T)+sizeof(AFM_MB_FOOTGUD_T)) * subpool_nr[idx]); \
        } \
        first_freehead = (AFM_MB_HEAD_T *)((kal_uint8*)(afm_id) + sizeof(AFM_CB_T) + (sizeof(AFM_POOL_CB_T) * (afm_id->subpool_nr)) + sz); \
   }

#define AFM_GET_FIRST_FREEHEAD_LOG(afm_id, subpool_sz, subpool_nr, buf_no, first_freehead) \
    { \
        kal_int32 idx, sz = 0; \
        for(idx = 0; idx < (buf_no); idx++) { \
            sz += ((subpool_sz[idx]+sizeof(AFM_MB_HEAD_T)) * subpool_nr[idx]); \
        } \
        first_freehead = (AFM_MB_HEAD_T *)((kal_uint8*)(afm_id) + sizeof(AFM_CB_T) + (sizeof(AFM_POOL_CB_T) * (afm_id->subpool_nr)) + (sizeof(AFM_POOL_CUSLOG_T) * (afm_id->subpool_nr)) + sz); \
   }

#define AFM_GET_FIRST_FREEHEAD_GUDPTN_LOG(afm_id, subpool_sz, subpool_nr, buf_no, first_freehead) \
    { \
        kal_int32 idx, sz = 0; \
        for(idx = 0; idx < (buf_no); idx++) { \
            sz += ((subpool_sz[idx]+sizeof(AFM_MB_HEAD_T)+sizeof(AFM_MB_HEADGUD_T)+sizeof(AFM_MB_FOOTGUD_T)) * subpool_nr[idx]); \
        } \
        first_freehead = (AFM_MB_HEAD_T *)((kal_uint8*)(afm_id) + sizeof(AFM_CB_T) + (sizeof(AFM_POOL_CB_T) * (afm_id->subpool_nr)) + (sizeof(AFM_POOL_CUSLOG_T) * (afm_id->subpool_nr)) + sz); \
   }

#define AFM_GET_AFMPOOL_END(afm_id, subpool_sz, subpool_nr, total_buf_no, end_addr) \
   { \
	   kal_int32 idx, sz = 0; \
	   for(idx = 0; idx < (total_buf_no); idx++) { \
	       sz += ((subpool_sz[idx]+sizeof(AFM_MB_HEAD_T)) * subpool_nr[idx]); \
	   } \
	   end_addr = (kal_uint32)((kal_uint8*)(afm_id) + sizeof(AFM_CB_T) + (sizeof(AFM_POOL_CB_T) * (afm_id->subpool_nr)) + sz); \
   }

#define AFM_GET_AFMPOOL_END_GUDPTN(afm_id, subpool_sz, subpool_nr, total_buf_no, end_addr) \
   { \
	   kal_int32 idx, sz = 0; \
	   for(idx = 0; idx < (total_buf_no); idx++) { \
	       sz += ((subpool_sz[idx]+sizeof(AFM_MB_HEAD_T)+sizeof(AFM_MB_HEADGUD_T)+sizeof(AFM_MB_FOOTGUD_T)) * subpool_nr[idx]); \
	   } \
	   end_addr = (kal_uint32)((kal_uint8*)(afm_id) + sizeof(AFM_CB_T) + (sizeof(AFM_POOL_CB_T) * (afm_id->subpool_nr)) + sz); \
   }

#define AFM_GET_AFMPOOL_END_LOG(afm_id, subpool_sz, subpool_nr, total_buf_no, end_addr) \
   { \
	   kal_int32 idx, sz = 0; \
	   for(idx = 0; idx < (total_buf_no); idx++) { \
	       sz += ((subpool_sz[idx]+sizeof(AFM_MB_HEAD_T)) * subpool_nr[idx]); \
	   } \
	   end_addr = (kal_uint32)((kal_uint8*)(afm_id) + sizeof(AFM_CB_T) + (sizeof(AFM_POOL_CB_T) * (afm_id->subpool_nr)) + (sizeof(AFM_POOL_CUSLOG_T) * (afm_id->subpool_nr)) + sz); \
   }

#define AFM_GET_AFMPOOL_END_GUDPTN_LOG(afm_id, subpool_sz, subpool_nr, total_buf_no, end_addr) \
   { \
	   kal_int32 idx, sz = 0; \
	   for(idx = 0; idx < (total_buf_no); idx++) { \
	       sz += ((subpool_sz[idx]+sizeof(AFM_MB_HEAD_T)+sizeof(AFM_MB_HEADGUD_T)+sizeof(AFM_MB_FOOTGUD_T)) * subpool_nr[idx]); \
	   } \
	   end_addr = (kal_uint32)((kal_uint8*)(afm_id) + sizeof(AFM_CB_T) + (sizeof(AFM_POOL_CB_T) * (afm_id->subpool_nr)) + (sizeof(AFM_POOL_CUSLOG_T) * (afm_id->subpool_nr)) + sz); \
   }

#define AFM_MB_HEADGUD_SET_INUSE(afm_mb_headgud) \
		(afm_mb_headgud)->static_next = (AFM_MB_HEADGUD_T *)((kal_uint32)(afm_mb_headgud)->static_next | AFM_STS_BIT)

#define AFM_MB_HEADGUD_SET_FREE(afm_mb_headgud) \
		(afm_mb_headgud)->static_next = (AFM_MB_HEADGUD_T *)((kal_uint32)(afm_mb_headgud)->static_next & ~AFM_STS_BIT)

#define AFM_MB_HEADGUD_STATE(afm_mb_headgud) \
		(((kal_uint32)(afm_mb_headgud)->static_next & AFM_STS_BIT)? AFM_INUSE: AFM_FREE)

#define AFM_MB_HEADGUD_NEXT(afm_mb_headgud) \
		(AFM_MB_HEADGUD_T *)((kal_uint32)(afm_mb_headgud)->static_next & ~AFM_STS_BIT)

#define AFM_MB_HEADGUD_SET_NEXT(oldval, newval) \
		(AFM_MB_HEADGUD_T *)((kal_uint32)(newval) | ((kal_uint32)(oldval) & AFM_STS_BIT))


#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__DYNAMIC_SWITCH_CACHEABILITY__))
#define AFM_ROUNDUP_2_CACHE_LINE(value) (value) = ((((value) + (CPU_CACHE_LINE_SIZE-1)) >> CPU_CACHE_LINE_BIT_OFFSET) << CPU_CACHE_LINE_BIT_OFFSET)

#define AFM_ROUNDDOWN_2_CACHE_LINE(value) (value) = (((value) >> CPU_CACHE_LINE_BIT_OFFSET) << CPU_CACHE_LINE_BIT_OFFSET)

#define AFM_GET_CACHE_LINE_ALIGN_PAD(value) (((((value) + (CPU_CACHE_LINE_SIZE-1)) >> CPU_CACHE_LINE_BIT_OFFSET) << CPU_CACHE_LINE_BIT_OFFSET)-value)
#endif /* __MTK_TARGET__ && (__ARM9_MMU__ || __DYNAMIC_SWITCH_CACHEABILITY__) */

#define AFM_ROUNDUP_2_4B(value) (value) = ((((value) + (4-1)) >> 2) << 2)

/********* define macro to caculate require size, internal part ***************/
#define __ALIGN4(sz) (((sz) + 3) & ~3)
#define __ALIGNCACHE(sz) (((sz) + CPU_CACHE_LINE_SIZE-1) & ~(CPU_CACHE_LINE_SIZE-1))

#define _KAL_AFM_MB_OVERHEAD(option) (sizeof(AFM_MB_HEAD_T) + (option & AFM_OPT_DBG ? sizeof(AFM_MB_HEADGUD_T) + sizeof(AFM_MB_FOOTGUD_T) : 0))
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__DYNAMIC_SWITCH_CACHEABILITY__))
#define _KAL_AFM_POOLSIZE_BASE(pcount, option) \
    (sizeof(AFM_CB_T) + sizeof(AFM_POOL_CB_T) * pcount \
        + (((option) & AFM_OPT_CUSLOG) ? sizeof(AFM_POOL_CUSLOG_T) * (pcount) : 0) + 4 \
        + (((option) & AFM_OPT_ALIGN_ALLOC) ? CPU_CACHE_LINE_SIZE : 0))
#define _KAL_AFM_POOLSIZE_PARTITION(option, sz, nr) \
    (option & AFM_OPT_ALIGN_ALLOC ? \
        (nr) * (__ALIGNCACHE(sz) + __ALIGNCACHE(_KAL_AFM_MB_OVERHEAD(option))) \
        : (nr) * (__ALIGN4(sz) + _KAL_AFM_MB_OVERHEAD(option))) 
#else
#define _KAL_AFM_POOLSIZE_BASE(pcount, option) \
    sizeof(AFM_CB_T) + sizeof(AFM_POOL_CB_T) * (pcount) \
        + ((option & AFM_OPT_CUSLOG) ? sizeof(AFM_POOL_CUSLOG_T) * pcount : 0) + 4 
#define _KAL_AFM_POOLSIZE_PARTITION(option, sz, nr) \
    (nr) * (__ALIGN4(sz) + _KAL_AFM_MB_OVERHEAD(option))
#endif

/*******************************   PUBLIC API  ********************************/
#define KAL_AFM_POOL_OVERHEAD(option, subpool_count) (_KAL_AFM_POOLSIZE_BASE((subpool_count), (option)))
#define KAL_AFM_SUBPOOL_OVERHEAD(option, sz, nr) (_KAL_AFM_POOLSIZE_PARTITION((option), (sz), (nr)))

#endif   /* _KAL_AFM_H */
