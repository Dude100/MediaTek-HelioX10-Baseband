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
 *   ndis_ratdm_struct.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *     			HISTORY
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 ******************************************************************************/

#ifndef NDIS_RATDM_STRUCT_H
#define NDIS_RATDM_STRUCT_H
/******************************************************************************/

#include "kal_general_types.h"
#include "kal_public_defs.h"

#include "ps_public_enum.h"

/******************************************************************************/

//MSG_ID_NDIS_RATDM_DATA_ACTIVATE_IND,
typedef struct {
    LOCAL_PARA_HDR
//    UART_PORT uart_port_number;
    kal_uint8 context_id;
    kal_uint8 src_id;
    //#ifdef __IPV4V6__
    kal_uint8 /*pdp_addr_type_enum*/ pdp_type; // IPv4, IPv6, IPv4v6
    kal_uint8 channel_id; // UPS channel ID
    //#endif // ~ #ifdef __IPV4V6__
} ndis_ratdm_data_activate_ind_struct;

//MSG_ID_NDIS_RATDM_DATA_ACTIVATE_RSP,
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_bool result;
    kal_uint8 src_id;
} ndis_ratdm_data_activate_rsp_struct;

//MSG_ID_NDIS_RATDM_DATA_DEACTIVATE_IND,
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
} ndis_ratdm_data_deactivate_ind_struct;

//MSG_ID_NDIS_RATDM_DATA_DEACTIVATE_RSP,
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 context_id;
    kal_bool result;
} ndis_ratdm_data_deactivate_rsp_struct;
// --- __HSPA_DATA_PATH_OPT__

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8    pool_id;
//    UART_PORT    port;
} ndis_flc_data_resume_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8    pool_id;
//    UART_PORT    port;
} ndis_flc_data_suspend_ind_struct;

/******************************************************************************/
#endif /* NDIS_RATDM_STRUCT_H*/
