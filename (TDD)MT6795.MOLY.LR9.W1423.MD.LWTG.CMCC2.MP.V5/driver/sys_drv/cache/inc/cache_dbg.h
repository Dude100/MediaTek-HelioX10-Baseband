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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   cache_dbg.h
 *
 * Project:
 * --------
 *   Moly
 *
 * Description:
 * ------------
 *   This file implement cache debug APIs
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __CACHE_DBG_H__
#define __CACHE_DBG_H__

#include "kal_public_defs.h"
#include "kal_general_types.h"

typedef struct{
    kal_uint32 m_addr;
    kal_uint32 m_len;
    kal_uint32 m_lr;
}CACHE_LOG_T;

#define __CACHE_DEBUG_EN__

//for a small Internal SRAM case, config CACHE_DBG_LOG_MAX smaller
#if defined(MT6752) && defined(__MD2__)
	#define CACHE_DBG_LOG_MAX       6
#else
#define CACHE_DBG_LOG_MAX       8
#endif


#ifdef __MTK_TARGET__
#define SEC_INTSRAM_DATA_ZI     __attribute__ ((section("INTSRAM_ZI")))
#else
#define SEC_INTSRAM_DATA_ZI
#endif /* __MTK_TARGET__ */

#ifdef __CACHE_DEBUG_EN__

#define CACHE_INV_LOG           g_cache_inv_log
#define CACHE_INV_LOG_IDX       g_cache_inv_log_idx

#define CACHE_CLN_LOG           g_cache_cln_log
#define CACHE_CLN_LOG_IDX       g_cache_cln_log_idx

#define CACHE_CLN_INV_LOG       g_cache_cln_inv_log
#define CACHE_CLN_INV_LOG_IDX   g_cache_cln_inv_log_idx

#define CACHE_DBG_LOG_ENQUEUE(_log_buf, _idx, _addr, _len) \
do{ \
    kal_uint32 mask; \
    mask = SaveAndSetIRQMask(); \
    (_log_buf)[(_idx)].m_addr = (_addr); \
	(_log_buf)[(_idx)].m_len = (_len); \
    GET_RETURN_ADDRESS((_log_buf)[(_idx)].m_lr); \
	(_idx)++; \
    if((_idx)>=CACHE_DBG_LOG_MAX){ \
        (_idx) = 0; \
    }\
    RestoreIRQMask(mask); \
}while(0);

#else /*__CACHE_DEBUG_EN__*/

#define CACHE_INV_LOG             
#define CACHE_INV_LOG_IDX
#define CACHE_DBG_LOG_ENQUEUE(_log_buf, _idx, _addr, _len)

#endif /*__CACHE_DEBUG_EN__*/

#ifdef __CACHE_DEBUG_EN__
extern CACHE_LOG_T g_cache_inv_log[CACHE_DBG_LOG_MAX];
extern CACHE_LOG_T g_cache_cln_log[CACHE_DBG_LOG_MAX];
extern CACHE_LOG_T g_cache_cln_inv_log[CACHE_DBG_LOG_MAX];
extern kal_uint32 g_cache_inv_log_idx;
extern kal_uint32 g_cache_cln_log_idx;
extern kal_uint32 g_cache_cln_inv_log_idx;
#endif /*__CACHE_DEBUG_EN__*/

#endif /* __CACHE_DBG_H__ */
 
