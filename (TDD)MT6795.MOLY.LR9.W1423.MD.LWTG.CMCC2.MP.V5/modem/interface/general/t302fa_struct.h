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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2003
 *
 ****************************************************************************/

/*****************************************************************************
 * Filename:
 * ---------
 *	t302fa_struct.h
 *
 * Project:
 * --------
 *   Fax Over GSM
 *
 * Description:
 * ------------
 *   This file contains the data structures for messages between FA and T30
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/




#ifndef T302FA_STRUCT_H
#define T302FA_STRUCT_H

#include "kal_general_types.h"

/* DATA REQ local param struct */
typedef struct
{
   kal_uint8  ref_count;
   kal_uint16 msg_len;
	kal_bool   is_final;
	kal_uint8  length;
   kal_uint8  is_next_followed;
}t30_fa_data_req_struct;




//Robert
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_uint8	access_rate;
	kal_uint8	is_FR ;
}t30_fa_activate_req_struct;

/* FA Command request local param struct */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_bool   is_final;
	kal_uint8  length;
}t30_fa_cmd_req_struct;


typedef struct
{
   kal_uint8  ref_count;
   kal_uint16 msg_len;
	kal_uint8  fax_rate;
	kal_uint8  data_type;
}t30_fa_tx_data_req_struct;

typedef struct
{
   kal_uint8  ref_count;
   kal_uint16 msg_len;
	kal_uint8  fax_rate;
	kal_uint8  data_type;
}t30_fa_rx_data_req_struct;




/***************************************************************************
											T32 <- FA										  *
***************************************************************************/

/* FA Command indication local param struct */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_bool   is_final;
	kal_uint8  length;
}fa_t30_cmd_ind_struct;

/* FA Data indication local param struct */
typedef struct
{
   kal_uint8  ref_count;
   kal_uint16 msg_len;
	kal_uint8  length;
	kal_bool   is_final;
}fa_t30_data_ind_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_uint8  gsm_rate;
	kal_uint8 is_FR;
	kal_uint16 byte_cnt;
}fa_t30_rate_change_struct;


/* FA Activate Confirm message local param structure */
typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_bool	is_successful;
	kal_uint8	gsm_rate;
	kal_uint8	is_FR;
	kal_uint16	byte_cnt;
}fa_t30_activate_cnf_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_bool	is_successful;
}fa_t30_tx_data_cnf_struct;

typedef struct
{
   kal_uint8 ref_count;
   kal_uint16 msg_len;
	kal_bool	is_successful;
}fa_t30_rx_data_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 allowed_frame_num;
} fa_t30_get_data_ind_struct;



#endif /* T302FA_STRUCT_H */


