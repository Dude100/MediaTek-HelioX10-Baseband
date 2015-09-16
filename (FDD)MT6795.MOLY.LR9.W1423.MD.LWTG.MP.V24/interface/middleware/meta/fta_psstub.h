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
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   fta_api.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   FTA API stuff
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

#ifndef FTA_PSSTUB_H
#define FTA_PSSTUB_H

#ifndef WIN32

#if defined(TL1_TESTCASE) || ((defined(IC_MODULE_TEST) || defined(__IC_SLT__)) && defined(__TDDSYS_SLT_FACTORY_BOOT__))
#include "fta_ll1stub.h"
enum
{
	MSG_ID_UMACSTUB_SET_TFCI = MSG_ID_LL1STUB_STOP_SYNC_REQ + 1,
#ifdef __HSUPA_SUPPORT__		
	MSG_ID_UMACSTUB_SET_EDCH_CTRL_PARA,
#endif	
	MSG_ID_L1TEST_CMD,		
	MSG_ID_L1TEST_CMD_RESP,
    MSG_ID_FTA_GEMINI_SET_REQ,
    MSG_ID_FTA_GEMINI_REPORT,	
};


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint16 uwCmdType;
    kal_uint16 uwPadding0;
}L1MCU_L1TEST_CMD;
#endif

#ifdef __cplusplus
extern "C" {
#endif
void FTA_mac_hs_get_pdu_buffer(kal_uint8** buffer_ptr, kal_uint16 size);
void FTA_mac_get_pdu_buffer(kal_uint8** buffer_ptr, kal_uint16 size);
//#ifndef __UMAC_DCH_LISR__
//void FTA_UMAC_UL_DCH_Tick_End(kal_bool tx_suspend,tx_enable_type_E tx_enable,uldch_data_ind_T * uldch_data_ind);


//void FTA_UMAC_UL_DCH_Tick(uldch_data_req_T * uldch_data_req);
//#else
uldch_data_ind_T * FTA_UMAC_UL_DCH_Tick_Low_Lisr(uldch_data_req_T * uldch_data_req);
//#endif
#ifdef __HSUPA_SUPPORT__

etfc_eval_info_ind_T* FTA_umac_e_dch_tick_1(etfc_eval_info_req_T *etfc_eval_input);

edch_data_ind_T* FTA_umac_e_dch_tick_2(edch_data_req_T *edch_data_input);

void FTA_umac_e_dch_tick_3(kal_uint8 harq_id, tdd128_modulation_E modulation);

#endif
void FTA_ul_dpch_power(kal_uint8 cfn, kal_uint8* tfc_status);
void FTA_ul_inform_MAC(void);
#ifdef __cplusplus
}
#endif

#endif


#endif 
