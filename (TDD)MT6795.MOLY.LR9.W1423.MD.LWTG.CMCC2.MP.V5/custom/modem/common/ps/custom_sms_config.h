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
 * custom_sms_config.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for header file of sms customization functions. 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef _CUSTOM_SMS_CONFIG_H
#define _CUSTOM_SMS_CONFIG_H

#include "kal_general_types.h"

/* implement in custom/ps/<project>/customer_sms_discard_patent.c */
extern kal_uint8 *smsal_get_discard_patent_str(kal_uint16 *);

/* implement in custom/ps/<project>/customer_sms_msg_box_num.c */
extern kal_uint16 cm_sms_max_msg_num (void);
extern void *cm_sms_get_message_box(kal_uint8);

/* implement in custom/ps/<project>/customer_sms_prefer_order.c */
extern kal_uint8 smsal_sms_prefer_order (void);

/* implement in custom/ps/<project>/customer_sms_tl_retry.c */
extern kal_uint8 sms_tl_max_retry_count(void);
extern kal_uint8 sms_tl_retry_timer (void);

/* implement in custom/common/custom_sms_config.c */
extern kal_uint8 sms_cnmi_para_mode(void);
extern kal_uint8 sms_cnmi_para_mt(void);
extern kal_uint8 sms_cnmi_para_bm(void);
extern kal_uint8 sms_cnmi_para_ds(void);
extern kal_uint16 sms_check_sim_service_table(void);
extern kal_uint8 custom_sms_is_disabled(void);
extern kal_uint8 sms_message_format(void);

/* implement in custom/modem/common/ps/customer_sms_force_read_smsp.c */
extern kal_uint8 smsal_force_read_smsp_for_sat_file_change (void);

/* implement in custom/modem/common/ps/customer_cb_service_by_plmn.c */
extern kal_uint8 smsal_cb_get_service_plmn_num (void);
extern void smsal_cb_get_service_plmn(kal_uint8 i, kal_uint8 * plmn);

extern kal_bool custom_sms_store_class0_mwd(void);
#endif
