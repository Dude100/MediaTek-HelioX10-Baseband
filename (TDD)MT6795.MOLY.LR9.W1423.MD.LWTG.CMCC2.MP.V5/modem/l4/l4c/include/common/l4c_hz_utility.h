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
 * l4c_hz_msg.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _L4C_HZ_UTILITY_H
#define _L4C_HZ_UTILITY_H

#ifdef __HOMEZONE_SUPPORT__

#include "kal_general_types.h"
#include "ps_public_struct.h"
#include "mcd_l3_inc_struct.h"

extern void l4c_hz_init_context(void);
extern kal_uint32 hz_atoi(kal_uint8 *asciiz);

extern kal_bool in_sim_cache(kal_uint8 hz_number, kal_uint8 lac[2], kal_uint16 cell_id);
extern void add_sim_cache(kal_uint8 hz_number, kal_uint8 lac[2], kal_uint16 cell_id);
extern void del_sim_cache(kal_uint8 hz_number, kal_uint8 lac[2], kal_uint16 cell_id);

extern kal_uint8 in_dynamic_cache(kal_uint8 lac[2], kal_uint16 cell_id);
extern void add_dynamic_cache(kal_uint8 hz_number, kal_uint8 lac[2], kal_uint16 cell_id);
extern void clear_dynamic_cache(void);

extern void l4c_hz_read_file_info_cnf_hdlr(l4c_result_struct result, kal_uint16 file_size, kal_uint8 num_of_rec);
extern void l4c_hz_read_sim_cnf_hdlr(l4c_result_struct result, kal_uint16 length, kal_uint8 *data);
extern void l4c_hz_write_sim_cnf_hdlr(kal_bool result, kal_uint16 cause);

extern void l4c_hz_ready(void);

extern kal_bool l4c_hz_is_on_home_plmn(plmn_id_struct plmn_id);

extern void l4c_hz_cell_reselection_alg(kal_uint8 lac[2], kal_uint16 cell_id);
extern void l4c_hz_cb_alg(kal_uint32 xc, kal_uint32 yc);

extern void l4c_hz_init(void);
extern void l4c_hz_init_finish(void);
extern void l4c_hz_update(void);

extern void start_cb_channel_timer(void);
extern void stop_cb_channel_timer(void);
extern void cb_channel_timer_timeout_hdlr(void);

extern void print_hz_para(int hz_number);

extern void print_hz_cache(int hz_number);

extern void l4c_hz_tag_lind(kal_bool action, kal_bool is_hz, kal_uint8 tag[12] ); //mtk02514_081216

#endif /* __HOMEZONE_SUPPORT__ */ 

#endif /* _L4C_HZ_UTILITY_H */

