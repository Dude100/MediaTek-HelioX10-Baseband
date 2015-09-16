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
 *   kal_adm.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This header file defines data structure for KAL application dynamic memory
 *   management.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _KAL_ADM_H
#define _KAL_ADM_H

#include "kal_general_types.h"

/*******************************************************************************
 * Constant definitions
 *******************************************************************************/

/* internal use constants */
#define ADM_ID       0x20101027
#define ADM_INUSE    0
#define ADM_FREE     1
#define ADM_SHIFT    1
#define ADM_NOTSHIFT 0
#define ADM_MB_LOG_STAMP  0x03F3F3F3
#define ADM_MB_FOOT_STAMP 0x04F4F4F4
#define ADM_MAX_PRINT_LEN 128

/* other public ADM constant defined in kal_public_defs.h */

#define KAL_ADM_GOODFIT_FUZZ        8

#define KAL_ADM_TRAVERSE_ALLMB       0x1
#define KAL_ADM_TRAVERSE_NO_CONCHECK 0x2
#define KAL_ADM_MB_INUSE            (0x01)
#define KAL_ADM_MB_FREE             (0x02)
#define KAL_ADM_MB_FIRST            (0x10)
#define KAL_ADM_MB_LAST             (0x20)
#define KAL_ADM_MB_INTERNAL         (0x80)

/*******************************************************************************
 * Data structure definitions
 *******************************************************************************/

/* ADM Control Block */
typedef struct
{
	kal_uint32 adm_id;    /* ID, ADM_ID */
	kal_uint16 bl_num;    /* number of block lists */
	kal_uint16 owner;     /* owner of ADM */
    kal_uint32 left_size; /* total left (free) size in this ADM pool */
	kal_uint16 flags;     /* KAL_ADM_*_FLAG */
	kal_uint8  extheader_size; /* a user-defined extensible header, in word */
	kal_uint8  life0;     /* life cycle */
} ADM_CB;


typedef struct ADM_MB_MINI_HEAD_STRUCT
{
	struct ADM_MB_HEAD_STRUCT *prev;     /* previous MB */
	struct ADM_MB_HEAD_STRUCT *next;     /* next MB */
} ADM_MB_MINI_HEAD;


typedef struct ADM_MB_HEAD_STRUCT
{
	struct ADM_MB_HEAD_STRUCT *prev;     /* previous MB */
	struct ADM_MB_HEAD_STRUCT *next;     /* next MB */
	struct ADM_MB_HEAD_STRUCT *bl_prev;  /* prev pointer in Block List */
	struct ADM_MB_HEAD_STRUCT *bl_next;  /* next pointer in Block List */
} ADM_MB_HEAD;


typedef struct ADM_MB_HEADGUARD_STRUCT
{
    kal_uint32 stamp;    /* store a fixed pattern to check corruption */
} ADM_MB_HEADGUARD;


typedef struct ADM_MB_FOOTGUARD_STRUCT
{
	kal_uint32 stamp;   /* store a fixed pattern to check corruption */
} ADM_MB_FOOTGUARD;


typedef struct ADM_MB_OLDLOGGING_EXTHEADER
{
    kal_char *filename;
	kal_uint32 line;
} ADM_MB_OLDLOGGING_EXTHEADER;

/* ADM Block List */
typedef struct
{
	kal_uint32 size;
	kal_uint32 reserved;                 /* this pointer is used in first BL to store last MB */
	struct ADM_MB_HEAD_STRUCT *bl_prev;  /* prev pointer in Block List */
	struct ADM_MB_HEAD_STRUCT *bl_next;  /* next pointer in Block List */
	/*
	 * NoteXXX: bl_prev and bl_next must be the last 2 elements
	 * since ADM_MB_HEAD's bl_prev may point to one ADM_BL.
	 * (i may cast a ADM_BL to ADM_MB_HEAD to reference bl_prev and bl_next.)
	 */
} ADM_BL;

/*******************************************************************************
 * Macros definitions
 *******************************************************************************/

/*
 * NoteXXX: the least-significant-bit of adm_mb_head->prev is used to store the memory
 * block's state. 1 for INUSE; 0 for FREE.
 * Need to use these special macros for accessing adm_mb_head->prev.
 */
#define ADM_MB_PREV(adm_mb_head) \
		((ADM_MB_HEAD *)((kal_uint32)(adm_mb_head)->prev & ~0x01))

#define ADM_MB_SET_PREV(oldval, newval) \
		((ADM_MB_HEAD *)((kal_uint32)(newval) | ((kal_uint32)(oldval) & 0x01)))

#define ADM_MB_SET_INUSE(adm_mb_head) \
		(adm_mb_head)->prev = (ADM_MB_HEAD *)((kal_uint32)(adm_mb_head)->prev | 0x01)

#define ADM_MB_SET_FREE(adm_mb_head) \
		(adm_mb_head)->prev = (ADM_MB_HEAD *)((kal_uint32)(adm_mb_head)->prev & ~0x01)

#define ADM_MB_STATE(adm_mb_head) \
		(((kal_uint32)(adm_mb_head)->prev & 0x01)? ADM_INUSE: ADM_FREE)

#define ADM_MB_NEXT(adm_mb_head) \
		((ADM_MB_HEAD *)((kal_uint32)(adm_mb_head)->next & ~0x01))

#define ADM_MB_SET_NEXT(oldval, newval) \
		((ADM_MB_HEAD *)((kal_uint32)(newval) | ((kal_uint32)(oldval) & 0x01)))

#define ADM_MB_SET_ADDR_SHIFT(adm_mb_head) \
		(adm_mb_head)->next = (ADM_MB_HEAD *)((kal_uint32)(adm_mb_head)->next | 0x01)

#define ADM_MB_CLEAR_ADDR_SHIFT(adm_mb_head) \
		(adm_mb_head)->next = (ADM_MB_HEAD *)((kal_uint32)(adm_mb_head)->next & ~0x01)

#define ADM_MB_IS_ADDR_SHIFT(adm_mb_head) \
        (((kal_uint32)(adm_mb_head)->next & 0x01)? ADM_SHIFT: ADM_NOTSHIFT)

#define ADM_MB_SIZE(adm_mb_head) \
	      ((kal_uint32)(ADM_MB_NEXT(adm_mb_head)) - (kal_uint32)(adm_mb_head))

#define ADM_GET_HEADGUARD_POINTER(adm_mb_head) \
        ((ADM_MB_HEADGUARD *)((kal_uint8 *)(adm_mb_head) + sizeof(ADM_MB_MINI_HEAD)))

#define ADM_GET_FOOTGUARD_POINTER(adm_mb_head) \
        ((ADM_MB_FOOTGUARD *)ADM_MB_NEXT(adm_mb_head) - 1)

#define ADM_GET_HEADGUARD_STAMP(adm_cb) \
        ((kal_uint32)(adm_cb) ^ ADM_MB_LOG_STAMP)

#define ADM_GET_LIFE(adm_cb) ((adm_cb->life0 << 8) | (adm_cb->life0 << 16))
#define ADM_GET_FOOTGUARD_STAMP(adm_cb) \
        (ADM_GET_LIFE((adm_cb)) ^ ADM_MB_FOOT_STAMP)

#define ADM_ROUND_2_4BYTE(value) ((((value) + 3) >> 2) << 2)

#define ADM_IS_4B_ALIGNED(value) (((value)&0x00000003)==0? 1: 0)


#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__)	|| defined(__MTK_L1CACHEABLE__) || defined(__DYNAMIC_SWITCH_CACHEABILITY__))

#define ADM_ROUNDUP_2_CACHE_LINE(value) (value) = ((((value) + (CPU_CACHE_LINE_SIZE-1)) >> CPU_CACHE_LINE_BIT_OFFSET) << CPU_CACHE_LINE_BIT_OFFSET)

#define ADM_ROUNDDOWN_2_CACHE_LINE(value) (value) = (((value) >> CPU_CACHE_LINE_BIT_OFFSET) << CPU_CACHE_LINE_BIT_OFFSET)

#define ADM_GET_CACHE_LINE_ALIGN_PAD(value) (((((value) + (CPU_CACHE_LINE_SIZE-1)) >> CPU_CACHE_LINE_BIT_OFFSET) << CPU_CACHE_LINE_BIT_OFFSET)-value)

#endif /* __MTK_TARGET__ && (__ARM9_MMU__ || __ARM7_L1DCACHEABLE__ || __DYNAMIC_SWITCH_CACHEABILITY__ ) */

void *kal_adm_get_buffer(KAL_ADM_ID adm_id, ADM_MB_HEAD *adm_mb_head, kal_uint32 *buffer_length);

typedef kal_bool (*kal_adm_mb_visitor)(KAL_ADM_ID adm_id, kal_uint32 flags, ADM_MB_HEAD *mb, void *user_data);
void kal_adm_traverse(KAL_ADM_ID adm_id, kal_uint32 options, kal_adm_mb_visitor callback, void *user_data);

#endif   /* !_KAL_ADM_H */

