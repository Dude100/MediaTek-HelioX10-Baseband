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

/*******************************************************************************
 * Filename:
 * ---------
 *   ipc_utils.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   IPCore internal utilities.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                 HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *==============================================================================
 *******************************************************************************/

#include "kal_public_api.h"
#include "intrCtrl.h"
#include "mw_sap.h"
#include "ipcore_upcm_struct.h"

#include "qmu_bm.h"
#include "qmu_bm_size.h"
#include "qmu_bm_util.h"
#include "qmu_bm_flc.h"

#include "ipc_defs.h"
#include "ipc_debug.h"
#include "ipc_utils.h"

/*------------------------------------------------------------------------------
 * Global variables.
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 * Helper macro.
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 * Private function.
 *----------------------------------------------------------------------------*/
kal_bool 
ipc_do_gpd_copy(
    kal_uint8              *dst_buffer,
    kal_uint32              dst_max_len,
    kal_uint32             *dst_len_copied,
    qbm_gpd                *src_head_gpd,
    qbm_gpd                *src_tail_gpd)
 {
     qbm_gpd    *curr_gpd;
     qbm_gpd    *curr_bd;
     kal_bool    end_of_gpd_list;
     kal_bool    end_of_bd_list;

    if (NULL == dst_buffer || 0 == dst_max_len || NULL == dst_len_copied || 
        NULL == src_head_gpd || NULL == src_tail_gpd) {
        return KAL_FALSE;
    }

    *dst_len_copied = 0;

    end_of_gpd_list = KAL_FALSE;
    for (   curr_gpd = src_head_gpd;
            curr_gpd && !end_of_gpd_list;
            curr_gpd = (qbm_gpd *)QBM_DES_GET_NEXT(curr_gpd)) {

        end_of_gpd_list = (curr_gpd == src_tail_gpd);
        if (QBM_DES_GET_BDP(curr_gpd)) {

            end_of_bd_list = KAL_FALSE;
            for (   curr_bd = (qbm_gpd *)QBM_DES_GET_DATAPTR(curr_gpd);
                    curr_bd && !end_of_bd_list;
                    curr_bd = (qbm_gpd *)QBM_DES_GET_NEXT(curr_bd)) {

                end_of_bd_list = QBM_DES_GET_EOL(curr_bd);
                if (QBM_DES_GET_DATALEN(curr_bd) > 0) {
                    if (*dst_len_copied + QBM_DES_GET_DATALEN(curr_bd) <= dst_max_len) {
                        /* Invalid source BD */                        
                        QBM_CACHE_INVALID(QBM_DES_GET_DATAPTR(curr_bd), QBM_DES_GET_DATALEN(curr_bd));

                        kal_mem_cpy(
                        dst_buffer + *dst_len_copied,
                        QBM_DES_GET_DATAPTR(curr_bd),
                        QBM_DES_GET_DATALEN(curr_bd));
                        *dst_len_copied += QBM_DES_GET_DATALEN(curr_bd);
                    } else {
                        return KAL_FALSE;
                    }
                }
            }
        } else {
            if (QBM_DES_GET_DATALEN(curr_gpd) > 0) {
                if (*dst_len_copied + QBM_DES_GET_DATALEN(curr_gpd) <= dst_max_len) {
                    /* Invalid source GPD */
                    QBM_CACHE_INVALID(QBM_DES_GET_DATAPTR(curr_gpd), QBM_DES_GET_DATALEN(curr_gpd));

                    kal_mem_cpy(
                    dst_buffer + *dst_len_copied,
                    QBM_DES_GET_DATAPTR(curr_gpd),
                    QBM_DES_GET_DATALEN(curr_gpd));
                    *dst_len_copied += QBM_DES_GET_DATALEN(curr_gpd);
                } else {
                    return KAL_FALSE;
                }
            }
        }
    }

    /* Flush destination cache */
    QBM_CACHE_FLUSH(dst_buffer, *dst_len_copied);

    return KAL_TRUE;
    }

 void ipc_set_gpd_datalen(void* gpd, kal_uint32 datalen, void **payload_ptr)
 {
     kal_uint8* data_ptr = NULL;
 
     IPC_ASSERT(gpd && payload_ptr);
 
     if (QBM_DES_GET_BDP(gpd)) {
         void* bd;
 
         /* set bd data ptr */
         bd = QBM_DES_GET_DATAPTR(gpd);
 
         data_ptr = (kal_uint8*)QBM_DES_GET_DATAPTR(bd);
 
         /* set bd data len */
         QBM_DES_SET_DATALEN(bd, datalen);
 
         /* set bd checksum */
         qbm_cal_set_checksum(bd);
     } else
     {
         data_ptr = (kal_uint8*)QBM_DES_GET_DATAPTR(gpd);
     }
 
     /* set gpd data len */
     QBM_DES_SET_DATALEN(gpd, datalen);
 
     /* set gpd checksum */
     qbm_cal_set_checksum(gpd);
 
     *payload_ptr = (void*)(data_ptr);
 }

