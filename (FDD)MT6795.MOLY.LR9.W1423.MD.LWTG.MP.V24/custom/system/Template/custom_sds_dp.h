/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   custom_sds_dp.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Declaration of SDS data process callback function.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CUSTOM_SDS_DP_H__
#define __CUSTOM_SDS_DP_H__

#include "kal_general_types.h" 
#include "custom_sds_type.h"

#ifdef __cplusplus
extern "C" {
#endif

//==============================================================================
// SDS data process attribute
//==============================================================================
#define SDS_DP_READ                             0x00000000 // bit0 => 0:READ
#define SDS_DP_WRITE                            0x00000001 // bit0 => 1:WRITE 

//==============================================================================
// SDS data process callback prototype 
//==============================================================================

// returned code rules of all the data process callback functions 
// 0 == code : SUCCESS
// 0 <  code : SUCCESS with status 
// 0 >  code : ERROR with status 

typedef void        (*SDS_DP_GET_INIT_INFO)     (kal_uint32 actual_src_len, kal_uint32 *p_occupied_src_len);
typedef kal_int32   (*SDS_DP_INIT)              (kal_uint32 attr, const void *p_arg, kal_uint32 *p_block_size);
typedef void        (*SDS_DP_DEINIT)            (kal_uint32 attr);
typedef kal_int32   (*SDS_DP_RD_POST_PROCESS)   (kal_uint8 *p_dst, kal_uint32 actual_dst_len, kal_uint32 dst_offset, const kal_uint8 *p_src, kal_uint32 len);
typedef kal_int32   (*SDS_DP_WR_PRE_PROCESS)    (const kal_uint8 *p_src, kal_uint32 actual_src_len, kal_uint32 src_offset, kal_uint8 *p_dst, kal_uint32 len);

typedef struct SDS_DP_Callback {
    SDS_DP_GET_INIT_INFO        m_get_init_info;
    SDS_DP_INIT                 m_init;
    SDS_DP_DEINIT               m_deinit;
    SDS_DP_RD_POST_PROCESS      m_rd_post_process;
    SDS_DP_WR_PRE_PROCESS       m_wr_pre_process;
} SDS_DP_Callback;

//==============================================================================
// SDS data process exported APIs
//==============================================================================

extern const SDS_DP_Callback * SDS_DP_GetCallback(SDS_DP_TYPE  type);

#ifdef __cplusplus
}
#endif

#endif

