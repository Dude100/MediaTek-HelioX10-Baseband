/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 * ps2ratdm_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct between Application and RATDM for PS service
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _PS_RATDM_STRUCT_H
#define _PS_RATDM_STRUCT_H

#ifndef __L1_STANDALONE__

#include "kal_general_types.h"
//#include "uas_data_common.h"
#include "kal_public_defs.h"
    
typedef enum{
    PS_STATISTICS_RESET_ALL, 			// reset all data (eset context 1, 2, 3¡K tx data amount to zero, eset context 1, 2, 3¡K rx data amount to zero)
    PS_STATISTICS_RESET_ALL_TX, 		// reset context 1, 2, 3¡K tx data amount to zero
    PS_STATISTICS_RESET_ALL_RX, 		// reset context 1, 2, 3¡K rx data amount to zero
    PS_STATISTICS_CHECK_ARRAY_TO_RESET 	//(check detail_reset_command[] array content to determine reset which content)
}ext_call_history_reset_operation_enum;

typedef enum{
    RATDM_SHAQ_SOCKET_EMPTY_VALUE = 0xFE,
    RATDM_SHAQ_SOCKET_INVALID_VALUE = 0xFF
}ratdm_shaq_socket_value_enum;

typedef struct {
    LOCAL_PARA_HDR

#ifndef __LTE_RAT__
    kal_uint8 context_id;
#endif
    kal_uint8 pool_id;

    /* for RATDM usage */
    kal_uint8 nsapi;
    kal_uint16 npdu_num;
} ps_data_ind_struct;


typedef struct {
    LOCAL_PARA_HDR

#ifndef __LTE_RAT__
    kal_uint8 context_id;
#endif
    kal_uint8 pool_id;

    /* for RATDM usage */
    kal_uint8 nsapi;
    kal_uint16 npdu_num;
} ps_data_req_struct;

typedef struct ratdm_ps_data_ind_struct_tag
{
    PEER_BUFF_HDR

    kal_uint8 pool_id;
#ifndef __LTE_RAT__
    kal_uint8 context_id;
#endif
    kal_uint8 nsapi;    
    kal_uint16 npdu_num;
#ifdef __3G_NEW_DATA_PLANE_ARCH__
    void *gpd_ptr; //umts_dl_gpd *gpd_ptr; need to include "uas_data_common.h"
    void *last_gpd_ptr; //umts_dl_gpd *last_gpd_ptr; need to include "uas_data_common.h"
    peer_buff_struct *pTemp;
#endif    
}ratdm_ps_data_ind_struct;

#ifdef __3G_NEW_DATA_PLANE_ARCH__
// for MSC ~ it is necessary to be defined
typedef ratdm_ps_data_ind_struct peer_buff_ps_dscr_data_struct;
#endif

#endif // ~ #ifndef __L1_STANDALONE__

#endif 



