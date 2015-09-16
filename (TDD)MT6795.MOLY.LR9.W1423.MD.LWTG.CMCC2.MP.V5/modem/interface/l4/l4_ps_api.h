/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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

 /***************************************************************************
 * Filename:
 * ---------
 *   l4_ps_api.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   API provided by L4 task and inside-PS task uses only
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
 *==============================================================================
 *******************************************************************************/
#ifndef L4_PS_API_H
#define L4_PS_API_H

#include "ps_em_enum.h"
#include "ps_public_enum.h"
#ifdef __DIALUP_GPRS_COUNTER_SUPPORT__
#include "l4c_ratdm_struct.h"
#endif
#ifdef __SGLTE__
#include "psdm2l4c_enum.h"
#endif

extern kal_bool is_ps_conf_test_xta_mode_internal(void);
extern kal_bool is_ps_conf_test_xta_mode(void);
extern ps_conf_test_mode_enum query_ps_conf_test_mode_internal(void);
extern ps_conf_test_mode_enum query_ps_conf_test_mode(void);
extern kal_uint32 query_ps_conf_test_profile_setting(void);

extern ps_conf_test_mode_enum test_mode_consider_sim(kal_uint8 simInterface);

#ifdef __DIALUP_GPRS_COUNTER_SUPPORT__
extern void ratdm_l4c_query_pdp_statistics_table( single_pdp_call_history_info_struct *query_result );
#endif

#ifdef __SGLTE__
extern kal_bool is_mmdc_mode(kal_uint8 simIndex);
extern mmdc_mode_enum current_mmdc_mode(kal_uint8 simIndex);

extern psdm_psd_enum psdm_query_current_ps_domain(void);

extern kal_bool psdm_is_ps_switch_ongoing(void);

extern psdm_psd_enum psdm_query_target_ps_domain(void);

#endif

#ifdef __SGLTE_DSDS__
/***************************************************************************************************************
 * FUNCTION
 *     sglte_dsds_4G_switch_nvram_para()
 * DESCRIPTION
 *     In SGLTE_DSDS load:
 *         Determine which NVRAM LID record shall be accessed.
 * PARAMETERS
 *     sim_interface: the protocol stack's sim_interface, which calls the function.
 * RETURNS
 *     if (not 4G switched)
 *         if (sim_interface == 0)        return 1;
 *         else if (sim_interface == 1)   return 3;
 *         else if (sim_interface == 2)   return 2;
 *         else                           return 0xFFFF;    //other protocol, should not occur
 *     else                                                 //4G switched
 *         if (sim_interface == 0)        return 4;
 *         else if (sim_interface == 1)   return 2;
 *         else if (sim_interface == 2)   return 3;
 *         else                           return 0xFFFF;    //other protocol, should not occur
 **************************************************************************************************************/
extern kal_uint16 sglte_dsds_4G_switch_nvram_para(kal_uint8 sim_interface);
#endif

#ifdef __SGLTE_DSDS__
/**************************************************************************************************************
 * FUNCTION
 *     sglte_dsds_4G_switch_double_write_nvram_para()
 * DESCRIPTION
 *     In SGLTE_DSDS load:
 *         (1)Whether the protocol need double write nvram record.
 *         (2)If needed, which nvram record should be written.
 * PARAMETERS
 *     sim_interface: the protocol stack's sim_interface, which calls the function.
 * RETURNS
 *     if (sim_interface == 2)            //protocol3
 *         if (not 4G switched)
 *             return 4;
 *         else                           //4G switched
 *             return 1;
 *     else                               //other protocol
 *         return 0xFFFF;                 //the protocol need not double write nvram record.
 **************************************************************************************************************/
extern kal_uint16 sglte_dsds_4G_switch_double_write_nvram_para(kal_uint8 sim_interface);
#endif

#if defined(__DUAL_SIM_PROJECT_SUPPORT_SGLTE_WORLD_PHONE_NVRAM__) && defined(__GEMINI__) && !defined(__SGLTE_DSDS__)
/**************************************************************************************************************
 * FUNCTION
 *     gemini_double_write_nvram_para()
 * DESCRIPTION
 *     In GEMINI load:
 *         (1)Whether the protocol need double write nvram record.
 *         (2)If needed, which nvram record should be written.
 * PARAMETERS
 *     sim_interface: the protocol stack's sim_interface, which calls the function.
 * RETURNS
 *     if (not 4G switched)
 *         if (sim_interface == 0)        return 3;
 *         else if (sim_interface == 1)   return 4;
 *         else                           return 0xFFFF;    //other protocol, should not occur
 *     else                                                 //4G switched
 *         if (sim_interface == 0)        return 4;
 *         else if (sim_interface == 1)   return 3;
 *         else                           return 0xFFFF;    //other protocol, should not occur
 **************************************************************************************************************/
extern kal_uint16 gemini_double_write_nvram_para(kal_uint8 sim_interface);
#endif

extern kal_bool is_RRM_test(void);

extern void l4c_resend_afr_req();

#endif
