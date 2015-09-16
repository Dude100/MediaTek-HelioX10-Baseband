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
 *	l4c_rsat_msg_struct.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file is intends for RSAT message structures.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


#ifndef __L4C_RSAT_MSG_STRUCT_H__
#define __L4C_RSAT_MSG_STRUCT_H__

#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"

#if defined(__RSAT__)
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   is_sms_packed_required;
    kal_uint8   no_addr;
    kal_uint8   addr[MAX_CC_ADDR_BCD_LEN];
    kal_uint8   tpdu_length;
    kal_uint8   tpdu[175];
} mmi_sat_send_sms_stage1_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   input[MAX_DIGITS_USSD];
    kal_uint8   dcs;
    kal_uint8   length;
    kal_uint8   type_of_modification;
} mmi_sat_send_ss_stage1_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   input[MAX_DIGITS_USSD];
    kal_uint8   dcs;
    kal_uint8   length;
    kal_uint8   type_of_modification;
} mmi_sat_send_ussd_stage1_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   sat_call_type;
    kal_uint8   no_addr;
    kal_uint8   addr[MAX_CC_ADDR_BCD_LEN];
    kal_uint8   no_sub_addr;
    kal_uint8   sub_addr[MAX_CC_SUB_ADDR_BCD_LEN];
    kal_uint8   no_ccp;
    kal_uint8   ccp[MAX_SAT_SIZE_OF_CCP];
    kal_uint8   type_of_modification;
} mmi_sat_call_setup_stage1_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   dtmf_digit[MAX_CC_DTMF_BCD_LEN];
    kal_uint8   no_digit;
} mmi_sat_send_dtmf_stage1_req_struct;

#endif /* defined(__RSAT__) */
#endif
