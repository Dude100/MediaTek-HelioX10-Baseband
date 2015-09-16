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
 *   flc2_ent_functions.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the function declarations used for gprs flow
 *   control implementation.
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
 *
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
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _FLC2_ENT_FUNCTIONS_H
#define _FLC2_ENT_FUNCTIONS_H

#include "kal_general_types.h"
#include "kal_public_defs.h"

#include "flc2_config.h"

/*************************************************************************
 * Constants
 *************************************************************************/
#define FLC2_MEM_SIZE_ALIGN_32(_SIZE_)  ((((_SIZE_) + 31) / 32) * 32)
#define FLC2_MEM_SIZE_ALIGN_4(_SIZE_)   ((((_SIZE_) + 3) / 4) * 4)
#define FLC2_MEM_SIZE_FOUR_ALIGN        FLC2_MEM_SIZE_ALIGN_4

#define FLC2_PERCENT_BASE               100

#define FLC2_MEM_CHUNK_HEADER_LEN_FOR_DCACHE            (32)
#define FLC2_MEM_CHUNK_HEADER_TAIL_LEN_FOR_DCACHE       \
    (FLC2_MEM_CHUNK_HEADER_LEN_FOR_DCACHE + 4) //4 for HEADER+TAIL GUARD PATTERN

#define FLC2_ENT_SIZE_UPPER_THRES_ALREADY_REPORTED      0x01
#define FLC2_ENT_SIZE_UPPER_THRES_TO_BE_REPORTED        0x00
#define FLC2_ENT_PKT_NO_UPPER_THRES_ALREADY_REPORTED    0x10
#define FLC2_ENT_PKT_NO_UPPER_THRES_TO_BE_REPORTED      0x00

#define FLC2_ENT_MARK_SIZE_U_THRES_REPORTED(_pool_id_)  \
    FLC2_POOL_INFO(_pool_id_, thres_reported) |= \
        FLC2_ENT_SIZE_UPPER_THRES_ALREADY_REPORTED;
#define FLC2_ENT_MARK_PKT_NO_U_THRES_REPORTED(_pool_id_) \
    FLC2_POOL_INFO(_pool_id_, thres_reported) |= \
        FLC2_ENT_PKT_NO_UPPER_THRES_ALREADY_REPORTED;

#define FLC2_ENT_MARK_SIZE_U_THRES_NOT_REPORTED(_pool_id_) \
    FLC2_POOL_INFO(_pool_id_, thres_reported) &= 0xF0;
#define FLC2_ENT_MARK_PKT_NO_U_THRES_NOT_REPORTED(_pool_id_) \
    FLC2_POOL_INFO(_pool_id_, thres_reported) &= 0x0F;

#define FLC2_ENT_IS_SIZE_U_THRES_REPORTED(_pool_id_)    \
    (((FLC2_POOL_INFO(_pool_id_, thres_reported) & 0x0F) == \
      FLC2_ENT_SIZE_UPPER_THRES_ALREADY_REPORTED) ? (KAL_TRUE):(KAL_FALSE))
#define FLC2_ENT_IS_PKT_NO_U_THRES_REPORTED(_pool_id_)  \
    (((FLC2_POOL_INFO(_pool_id_, thres_reported) & 0xF0) == \
      FLC2_ENT_PKT_NO_UPPER_THRES_ALREADY_REPORTED) ? (KAL_TRUE):(KAL_FALSE))

typedef struct{
   kal_uint16    pdu_len;
   kal_uint16    ref_count;        // extend to 16 bit
   kal_uint16    free_header_space;
   kal_uint16    free_tail_space;
} flc2_peer_buff_struct;

#ifdef __3G_NEW_DATA_PLANE_ARCH__
#define FLC2_GPD_BD_TYPE_DATA           0
#define FLC2_GPD_BD_TYPE_SIGNAL         1

#define FLC2_GPD_NULL_ADDRESS           ((void *)0xffffffff)
#define FLC2_BD_NULL_ADDRESS            ((void *)0xffffffff)

#ifdef __FLC_REALLOCATE__
#define FLC2_REALLOCATE_GUARD_LEN       4
#define FLC2_REALLOCATE_GUARD_PATTERN   (0xfaaaaaaf)
#define FLC2_POINT_TO_HEAD_LEN          4

// 32 bytes alignment
typedef struct flc2_reallocate_header_tag_
{
    peer_buff_struct peer;                               // 8
    kal_uint16 left_len;                                 // 2
    kal_uint16 pool_id;                                  // 2
    kal_uint16 reserved[4];                              // 8
    struct flc2_reallocate_header_tag_  *pth_nc;         // 4
    kal_uint32 guard_pattern;                            // 4
    struct flc2_reallocate_header_tag_  *pth_c;          // 4
}flc2_reallocate_header;

#define FLC2_GET_REALLOCATE_BUFFER_SIZE(_hdr_, _pdu_, _tail_) \
    FLC2_MEM_SIZE_ALIGN_32(sizeof(peer_buff_struct) + (_hdr_) + (_pdu_) + \
        (_tail_) + FLC2_REALLOCATE_GUARD_LEN + FLC2_POINT_TO_HEAD_LEN)

#define FLC2_GET_REALLOCATE_PTH(peer_buff, size) \
    (*((kal_uint32 *)(((kal_uint8 *)peer_buff) + (size) - sizeof(void *))))

#define FLC2_GET_REALLOCATE_GUARD(peer_buff, size) \
    (*((kal_uint32 *)(((kal_uint8 *)peer_buff) + (size) - sizeof(void *) - \
        FLC2_REALLOCATE_GUARD_LEN)))

#define FLC2_GET_REALLOCATE_BUFFER_PTH(peer_buff) \
    FLC2_GET_REALLOCATE_PTH(peer_buff, \
        FLC2_GET_REALLOCATE_BUFFER_SIZE(peer_buff->free_header_space, \
            peer_buff->pdu_len,peer_buff->free_tail_space))
#endif
#endif

#ifdef __3G_NEW_DATA_PLANE_ARCH__
#define flc2_my_peer_buff_struct flc2_peer_buff_struct
#else
#define flc2_my_peer_buff_struct peer_buff_struct
#endif

typedef void* (*flc2_alloc_func_ptr)(flc2_pool_id_enum, flc2_mb_index_enum,
    kal_uint32, kal_uint32 *);

#ifndef __USE_LEGACY_23G_DATAPATH__
// Used by IPCORE and above layer to fill their protocol header
#define FLC2_GPD_HEADER_BUFFER_SIZE         128

#define FLC2_GET_GPD_HEADER_BD_BUF_HDR_ADDR(gpd) \
    ((kal_uint8 *)(gpd->gpd_header_bd.nas.data_buffer_ptr) - \
     FLC2_GPD_HEADER_BUFFER_SIZE)
#else
#define FLC2_GPD_HEADER_BUFFER_SIZE         60

#define FLC2_GET_GPD_HEADER_BD_BUF_HDR_ADDR(gpd) \
    ((kal_uint8 *)(gpd->gpd_header_bd.nas.data_buffer_ptr))
#endif

/*************************************************************************
 * FLC2 API prototype
 *************************************************************************/
#define FLC_GET_PEER_BUFF(_pool_id_, _pdu_len_, _header_size_, _tail_size_, \
    _data_type_, _sapi_type_, _dir_, _context_id_, is_pool_created) \
    flc2_get_peer_buff(_pool_id_, _pdu_len_, _header_size_, _tail_size_)

#define FLC_FREE_PEER_BUFF(_pool_id_, _buff_ptr_ , _data_type_, _sapi_type_, \
    _dir_, _context_id_) \
    flc2_free_peer_buff(_pool_id_, _buff_ptr_)

#if defined(__UMTS_TDD128_MODE__) && !defined(__3G_NEW_DATA_PLANE_ARCH__) && \
    !defined(__LOW_COST_SUPPORT_COMMON__)
#define flc2_get_peer_buff(_pool_id_, _pdu_len_, _header_size_, _tail_size_) \
        flc2_ent_get_peer_buff(_pool_id_, _pdu_len_, _header_size_, _tail_size_, \
            __FILE__, __LINE__)

#define flc2_free_peer_buff(_pool_id_, _buff_ptr_) \
        flc2_ent_free_peer_buff(_pool_id_, _buff_ptr_, __FILE__, __LINE__)

#define flc2_init_pool(_pool_id_) \
        flc2_ent_init_pool(_pool_id_, __FILE__, __LINE__)

#define flc2_deinit_pool(_pool_id_) \
        flc2_ent_deinit_pool(_pool_id_, __FILE__, __LINE__)

#define flc2_grow_pool_with_shrink_mode(_pool_id_, _req_size_, _total_size_, \
    _shrink_mode_) \
        flc2_ent_grow_pool(_pool_id_, _req_size_, _total_size_, _shrink_mode_, \
            __FILE__, __LINE__)

#define flc2_grow_pool(_pool_id_, _req_size_, _total_size_) \
        flc2_ent_grow_pool(_pool_id_, _req_size_, _total_size_, \
            FLC2_SHRINK_AUTO, __FILE__, __LINE__)

#define flc2_shrink_pool( _pool_id_) \
        flc2_ent_shrink_pool( _pool_id_, __FILE__, __LINE__)

#define flc2_check_peer_buff(_pool_id_, _buff_ptr_) \
        flc2_ent_check_peer_buff(_pool_id_, _buff_ptr_, __FILE__, __LINE__)

#define flc2_config_user_info(_pool_id_, _user_info_ptr_)  \
        flc2_ent_config_user_info(_pool_id_, _user_info_ptr_, __FILE__, __LINE__)

#define flc2_reset_user_info(_pool_id_) \
        flc2_ent_reset_user_info(_pool_id_, __FILE__, __LINE__)  

#define flc2_get_user_info(_pool_id_) \
        flc2_ent_get_user_info(_pool_id_, __FILE__, __LINE__)  

#else
#define flc2_get_peer_buff(_pool_id_, _pdu_len_, _header_size_, _tail_size_) \
        flc2_ent_get_peer_buff(_pool_id_, _pdu_len_, _header_size_, _tail_size_)

#define flc2_free_peer_buff(_pool_id_, _buff_ptr_) \
        flc2_ent_free_peer_buff(_pool_id_, _buff_ptr_)

#define flc2_init_pool(_pool_id_) flc2_ent_init_pool(_pool_id_)
#define flc2_deinit_pool(_pool_id_) flc2_ent_deinit_pool(_pool_id_)

#define flc2_grow_pool_with_shrink_mode( _pool_id_, _req_size_, _total_size_, \
    _shrink_mode_) \
        flc2_ent_grow_pool( _pool_id_, _req_size_, _total_size_, _shrink_mode_)

#define flc2_grow_pool( _pool_id_, _req_size_, _total_size_) \
        flc2_ent_grow_pool( _pool_id_, _req_size_, _total_size_, \
            FLC2_SHRINK_AUTO)

#define flc2_shrink_pool( _pool_id_) \
        flc2_ent_shrink_pool( _pool_id_)

#define flc2_check_peer_buff(_pool_id_, _buff_ptr_) \
        flc2_ent_check_peer_buff(_pool_id_, _buff_ptr_)

#define flc2_config_user_info(_pool_id_, _user_info_ptr_)  \
        flc2_ent_config_user_info(_pool_id_, _user_info_ptr_)  

#define flc2_reset_user_info(_pool_id_)  \
        flc2_ent_reset_user_info(_pool_id_)  

#define flc2_get_user_info(_pool_id_)  \
        flc2_ent_get_user_info(_pool_id_)
#endif

#define flc2_query_pool(_pool_id_, _total_size_, _available_half_blocks_, \
    _available_full_blocks_) \
        flc2_ent_query_pool(_pool_id_, _total_size_, _available_half_blocks_, \
            _available_full_blocks_)

#ifdef __3G_NEW_DATA_PLANE_ARCH__
#define flc2_get_peer_buff_nc(_pool_id_, _pdu_len_, _header_size_, _tail_size_) \
        flc2_ent_get_peer_buff_nc(_pool_id_, _pdu_len_, _header_size_, _tail_size_)

#define flc2_free_peer_buff_count(_pool_id_, _buff_ptr_, _count_) \
        flc2_ent_free_peer_buff_count(_pool_id_, _buff_ptr_, _count_)

#define flc2_free_peer_buff_without_pool_id(_buff_ptr_) \
        flc2_ent_free_peer_buff_without_pool_id(_buff_ptr_)

#define flc2_get_gpd(_num_, _option_, _actual_num_) \
        flc2_gpd_get(_num_, _option_, _actual_num_, FLC2_GPD_BD_TYPE_DATA)

#define flc2_get_gpd_signal(_num_, _option_, _actual_num_) \
        flc2_gpd_get(_num_, _option_, _actual_num_, FLC2_GPD_BD_TYPE_SIGNAL)

#define flc2_free_gpd_only(_ptr_) \
        flc2_gpd_free(_ptr_)

#define flc2_get_bd(_num_, _option_, _actual_num_) \
        flc2_bd_get(_num_, _option_, _actual_num_, FLC2_GPD_BD_TYPE_DATA)

#define flc2_get_bd_signal(_num_, _option_, _actual_num_) \
        flc2_bd_get(_num_, _option_, _actual_num_, FLC2_GPD_BD_TYPE_SIGNAL)

#define flc2_free_gpd_traversal_with_bd_traversal(_ptr_) \
        flc2_gpd_free_traversal_with_bd_traversal(_ptr_)

#define flc2_free_bd_only(_ptr_) \
        flc2_bd_free(_ptr_)

#define flc2_free_bd(_ptr_) \
        flc2_bd_free_with_data_buff(_ptr_)

#define flc2_free_bd_traversal(_ptr_) \
        flc2_bd_free_traversal(_ptr_)

#ifdef __FLC_REALLOCATE__
#define flc2_get_peer_buff_reallocatable(_pool_id_, _hdr_len_, _pdu_len_, \
    _tail_len_, _total_len_) \
        flc2_ent_get_peer_buff_reallocatable(_pool_id_, _hdr_len_, _pdu_len_, \
            _tail_len_, _total_len_)        

#define flc2_reallocate_peer_buff(_ptr_, _hdr_len_, _pdu_len_, _tail_len_) \
        flc2_ent_reallocate_peer_buff((peer_buff_struct *)_ptr_, _hdr_len_, \
            _pdu_len_, _tail_len_)

#define flc2_free_peer_buff_reallocatable(_pool_id_, _ptr_) \
        flc2_ent_free_peer_buff_reallocatable(_pool_id_, _ptr_)

#define flc2_hold_peer_buff_reallocatable(_pool_id_, _ptr_, _count_) \
        flc2_ent_hold_peer_buff_reallocatable(_pool_id_, _ptr_, _count_)
#endif

#define flc2_set_reference_count(_ptr_, _count_) \
        flc2_ent_set_reference_count(_ptr_, _count_)

#define flc2_hold_peer_buff(_ptr_, _count_) \
        flc2_ent_hold_peer_buff(_ptr_, _count_)

/******************************************************************************/
extern void* flc2_gpd_get(kal_uint16 num, kal_uint32 option,
    kal_uint16 *actual_num, kal_uint8 type);

extern void flc2_gpd_free(void * ptr);

extern void flc2_gpd_free_traversal_with_bd_traversal(void *ptr);

extern void* flc2_bd_get(kal_uint16 num, kal_uint32 option,
    kal_uint16 *actual_num, kal_uint8 type);

extern void flc2_bd_free(void * ptr);

extern void flc2_bd_free_with_data_buff(void * ptr);

extern void flc2_bd_free_traversal(void * ptr);

extern void* flc2_ent_get_peer_buff_nc(flc2_pool_id_enum pool_id,
    kal_uint16 pdu_len, kal_uint16 header_size, kal_uint16 tail_size);

extern void flc2_ent_free_peer_buff_count(flc2_pool_id_enum pool_id,
    peer_buff_struct *buff_ptr, kal_uint16 count);

extern void flc2_ent_free_peer_buff_without_pool_id(peer_buff_struct *buff);

#ifdef __FLC_REALLOCATE__
extern void *flc2_ent_get_peer_buff_reallocatable(flc2_pool_id_enum pool_id,
    kal_uint16 hdr_len, kal_uint16 pdu_len, kal_uint16 tail_len,
    kal_uint16 total_len);

extern void *flc2_ent_reallocate_peer_buff(peer_buff_struct *prev_ptr,
    kal_uint16 hdr_len, kal_uint16 pdu_len, kal_uint16 tail_len);

extern void flc2_ent_free_peer_buff_reallocatable(flc2_pool_id_enum pool_id,
    void *ptr);

extern void flc2_ent_hold_peer_buff_reallocatable(flc2_pool_id_enum pool_id,
    void *ptr, kal_uint16 count);
#endif

extern void flc2_ent_set_reference_count(void *ptr, kal_uint16 count);

extern void flc2_ent_hold_peer_buff(void *ptr, kal_uint16 count);
#endif

#if defined(__UMTS_TDD128_MODE__) && !defined(__3G_NEW_DATA_PLANE_ARCH__)
#define flc2_ppp_set_realloc_pdu_num(num) {}
#else
#define flc2_ppp_set_realloc_pdu_num(num) flc2_ent_ppp_set_realloc_pdu_num(num)
extern kal_int32 flc2_ent_ppp_set_realloc_pdu_num(kal_uint16 num);
#endif

#if defined(__UMTS_TDD128_MODE__) && !defined(__3G_NEW_DATA_PLANE_ARCH__) && \
    !defined(__LOW_COST_SUPPORT_COMMON__)
extern kal_bool flc2_ent_init_pool(flc2_pool_id_enum pool_id,
    kal_char *filename, kal_uint32 line);
extern kal_bool flc2_ent_deinit_pool(flc2_pool_id_enum pool_id,
    kal_char *filename, kal_uint32 line);

extern kal_bool flc2_ent_grow_pool(flc2_pool_id_enum pool_id,
    kal_uint32 req_size, kal_uint32 *total_size,
    flc2_shrink_mode_enum shrink_mode, kal_char *filename, kal_uint32 line);

extern kal_bool flc2_ent_shrink_pool(flc2_pool_id_enum pool_id,
    kal_char *filename, kal_uint32 line);

extern void* flc2_ent_get_peer_buff(flc2_pool_id_enum pool_id,
    kal_uint16 pdu_len, kal_uint16 header_size, kal_uint16 tail_size, 
    kal_char *filename, kal_uint32 line);

extern void flc2_ent_free_peer_buff(flc2_pool_id_enum pool_id,
    peer_buff_struct* buff_ptr, kal_char *filename, kal_uint32 line);

extern kal_bool flc2_ent_config_user_info(flc2_pool_id_enum pool_id,
    void *user_info_ptr, kal_char *filename, kal_uint32 line);

extern void* flc2_ent_reset_user_info(flc2_pool_id_enum pool_id,
    kal_char *filename, kal_uint32 line);

extern void* flc2_ent_get_user_info(flc2_pool_id_enum pool_id,
    kal_char *filename, kal_uint32 line);

extern kal_bool flc2_ent_check_peer_buff(flc2_pool_id_enum pool_id,
    peer_buff_struct *buff_ptr, kal_char *filename, kal_uint32 line);
#else
extern kal_bool flc2_ent_init_pool(flc2_pool_id_enum pool_id);
extern kal_bool flc2_ent_deinit_pool(flc2_pool_id_enum pool_id);

extern kal_bool flc2_ent_grow_pool(flc2_pool_id_enum pool_id,
    kal_uint32 req_size, kal_uint32 *total_size,
    flc2_shrink_mode_enum shrink_mode);

extern kal_bool flc2_ent_shrink_pool(flc2_pool_id_enum pool_id);


extern void* flc2_ent_get_peer_buff(flc2_pool_id_enum pool_id,
    kal_uint16 pdu_len, kal_uint16 header_size, kal_uint16 tail_size);

extern void flc2_ent_free_peer_buff(flc2_pool_id_enum pool_id,
    peer_buff_struct* buff_ptr);

extern kal_bool flc2_ent_config_user_info(flc2_pool_id_enum pool_id,
    void *user_info_ptr);

extern void* flc2_ent_reset_user_info(flc2_pool_id_enum pool_id);

extern void* flc2_ent_get_user_info(flc2_pool_id_enum pool_id);

extern kal_bool flc2_ent_check_peer_buff(flc2_pool_id_enum pool_id,
    peer_buff_struct *buff_ptr);
#endif

#ifndef __USE_LEGACY_23G_DATAPATH__
#ifndef __MTK_TARGET__
extern void* flc2_get_lte_dl_data(void *data, kal_uint16 length);
#endif

extern void* flc2_get_peer_buff_without_mutex(flc2_pool_id_enum pool_id,
    kal_uint16 pdu_len, kal_uint16 header_size, kal_uint16 tail_size);

extern void flc2_set_peer_buff_head(void *buff_ptr, void *data_ptr,
    kal_uint16 pdu_len);

extern void flc2_leave_23g(void);

extern void flc2_reg_cbk_notify_pool_status(flc2_pool_status_func_ptr fptr);
#endif

extern void flc2_send_ilm(module_type dest_mod_id, msg_type msg_id,
    sap_type sap_id, local_para_struct *local_para_ptr,
    peer_buff_struct *peer_buff_ptr);

extern void flc2_ent_init_peer_buff(void *buff_ptr, kal_uint16 pdu_len,
    kal_uint16 header_size, kal_uint16 tail_size);

extern kal_uint32 flc2_ent_query_pool(flc2_pool_id_enum pool_id,
    kal_uint32 *total_size, kal_uint32 *available_half_blocks,
    kal_uint32 *available_full_blocks);

extern kal_bool flc2_get_spdu_info(kal_uint8 dir, kal_uint32 *pdu_block_size,
    kal_uint32 *pdu_total_size);

#ifdef FLC2_RECONFIG_ON
extern kal_bool flc2_ent_reconfig_pool_profile(flc2_pool_id_enum pool_id,
    flc2_profile_index_enum profile_index);

extern void flc2_ent_reconfig_profile_params(flc2_pool_id_enum pool_id,
    kal_uint32 size, kal_uint8 size_upper_thre, kal_uint8 size_lower_thre,
    kal_uint8 pkt_no_upper_thre, kal_uint8 pkt_no_lower_thre,
    kal_uint16 max_grow_size, kal_uint16 grow_step_size);

extern kal_bool flc2_ent_reconfig_single_pool(flc2_pool_id_enum pool_id,
    flc2_profile_index_enum profile_index);
#endif

#ifdef __FLC2_AFM_MEMORY_FINE_TUNE__
extern kal_int32 flc2_afm_custom_performance_info_get(flc2_pool_id_enum pool_id,
    kal_uint32 *option, kal_uint32 *buff_size, kal_uint32 *buff_nr,
    kal_uint32 *alloc_cnt, kal_uint32 *min_left_buf_nr);
extern kal_int32 flc2_afm_set_cuslogging(flc2_pool_id_enum pool_id,
    kal_uint32 cus_log_opt);
extern kal_int32 flc2_afm_get_left_subpool_num(flc2_pool_id_enum pool_id,
    kal_uint32 size);
extern kal_int32 flc2_afm_actual_size(void * ptr);
#endif

#endif /* _FLC2_ENT_FUNCTIONS_H */
