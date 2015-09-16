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
 *    sim_driver_interface.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is used to extend the scope of functions in sim_driver_interfaces.c.
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#ifndef SIM_DRIVER_INTERFACES_H
#define SIM_DRIVER_INTERFACES_H

#include "sim_def.h"
/* Driver related*/
#include "drv_comm.h"
#include "dcl.h"
#include "dcl_sim.h"

extern DCL_STATUS sim_driver_reset_api(DCL_SIM_POWER ExpectVolt, DCL_SIM_POWER * ResultVolt_ptr, kal_bool warm, DCL_SIM_STATUS * RstResult_ptr, sim_context_struct *this_sim);
extern DCL_STATUS sim_driver_cmd_api(kal_uint8 *txData_ptr, kal_uint32 *txSize_ptr, kal_uint8 *rxData_ptr, kal_uint32 *rxSize_ptr, kal_uint16 *statusWord_ptr, sim_context_struct *this_sim);
extern DCL_STATUS sim_driver_get_card_info_api(DCL_SIM_INFO *info_ptr, sim_context_struct *this_sim);
extern DCL_STATUS sim_driver_set_clk_stop_mode_api(DCL_SIM_CLK_STOP mode, sim_context_struct *this_sim);
extern DCL_STATUS sim_driver_poweroff_api(sim_context_struct *this_sim);
extern DCL_STATUS sim_driver_get_speed_api(DCL_SIM_CARD_SPEED *speed_ptr, sim_context_struct *this_sim);
extern DCL_STATUS sim_driver_query_9000OnSelect_api(DCL_BOOL *got9000_ptr, sim_context_struct *this_sim);


#ifdef IC_MODULE_TEST 
extern DCL_STATUS sim_driver_set_slt_rlt_api(DCL_BOOL rlt, sim_context_struct *this_sim);
#endif

#if (!defined(__MTK_TARGET__) && defined(__SIM_UNIT_TEST__))
extern DCL_STATUS sim_driver_ut_reset_uicc_status_api(sim_context_struct *this_sim);
extern DCL_STATUS sim_driver_ut_reset_pin_cnr_api(kal_bool pin1_enabled, kal_bool pin2_enabled, sim_context_struct *this_sim);
extern DCL_STATUS sim_driver_ut_reset_chv_cnr_api(kal_bool pin1_enabled, sim_context_struct *this_sim);
#endif

#endif /* SIM_DRIVER_INTERFACES_H */ 
 
