/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   l4c_uagps_cp_struct.h
 *
 * Project:
 * --------
 *   AGPS
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log:$
 * 
 * removed!
 * removed!
 * 20120928_MOLY00004236_Adeline_Remove_stack_ltlcom.h_AGPS.xls.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * ULCS RHR
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 ****************************************************************************/

#ifndef _L4C_UAGPS_CP_STRUCT_H
#define _L4C_UAGPS_CP_STRUCT_H
#include "kal_public_api.h"
#include "kal_general_types.h"
/**************************************************************
 * L4C_UAGPS_CP_AGPS_ENABLE_DISABLE_REQ
 *
 * AGPS control plane switch on 的時候用 enable 通知 ULCS, switch off 的時候 disable 通知 ULCS
 ***************************************************************/ 
typedef struct
{
    LOCAL_PARA_HDR
    
    kal_bool enable; // KAL_TRUE for enable, KAL_FALSE for disable

} l4c_uagps_cp_agps_enable_disable_req_struct;

/**************************************************************
 * L4C_UAGPS_CP_AGPS_KEY_UPDATE_REQ
 *
 * 從 SS 拿到 deciphering key 之後, 將其傳給 ULCS
 ***************************************************************/ 
typedef struct
{
    LOCAL_PARA_HDR

    kal_uint8 sib15_current_deciphering_key[7]; // 56 bits deciphering key form SS Location 
    kal_uint8 sib15_next_deciphering_key[7]; // 56 bits deciphering key form SS Location 
    kal_uint8 sib15_ciphering_key_flag; // key flag form SS Location

} l4c_uagps_cp_agps_key_update_req_struct;

/**************************************************************
 * L4C_UAGPS_CP_AGPS_NEW_KEY_NEEDED_IND
 *
 * 從 SS 拿到 deciphering key 之後, 將其傳給 ULCS
 ***************************************************************/ 
typedef struct
{
    LOCAL_PARA_HDR

} l4c_uagps_cp_agps_new_key_needed_ind_struct;


/**************************************************************
 * L4C_UAGPS_CP_AGPS_LCOAL_ABORT_TRANSACTION_REQ
 *
 * Abort CP transaction when user dial E911 call
 ***************************************************************/ 
typedef struct
{
    LOCAL_PARA_HDR

} l4c_uagps_cp_agps_local_abort_transaction_req_struct;

/**************************************************************
 * L4C_UAGPS_CP_AGPS_TRANSACTION_START_STOP_IND
 *
 * Inform GPS manager about CP transaction start
 ***************************************************************/ 
typedef struct
{
    LOCAL_PARA_HDR

    kal_bool transaction_start;

} l4c_uagps_cp_agps_transaction_start_stop_ind_struct;

#endif /* _L4C_UAGPS_CP_STRUCT_H */
