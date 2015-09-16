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
 *   ft_fnc_lterf.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Factory testing function for LTE
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
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
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined(__LTE_RAT__)&&defined(__TSTM_ENABLE__)
/*************************************************************************
* Include Statements for KAL
 *************************************************************************/
#include "kal_public_defs.h"
#include "svc_sap.h"
#include "tst_msgid.h"
#include "ft_msgid.h"
/*************************************************************************
 * FT header
 *************************************************************************/
#include "ft_msg.h"
#include "ft_private.h"
#include "ft_fnc_lterf.h"
/**
 * @param metaMessage the input message from META tool for ERF test command processing
 */
void FT_Erf_Operation(ilm_struct* erfMessage)
{
    if(NULL != erfMessage->local_para_ptr)
    {
        hold_local_para(erfMessage->local_para_ptr);
    }
    if(NULL != erfMessage->peer_buff_ptr)
    {
        hold_peer_buff(erfMessage->peer_buff_ptr);
    }    
    FT_SEND_MSG(MOD_FT, MOD_ETSTM, DHL_ETSTM_SAP, MSG_ID_DHL_TO_ETSTM, erfMessage);
}
/**
 * Confirm message handler for MOD_ETSTM
 */
void FT_Erf_ConfirmHandler(ilm_struct* erfMessage)
{
    FT_ERF_TEST_CNF *ptrMsg;
    ptrMsg = (FT_ERF_TEST_CNF *)erfMessage->local_para_ptr;
    if(ptrMsg->type == ERF_TEST_CMD_CHECK_IF_FUNC_EXIST)
    {
        FT_UTILITY_COMMAND_CNF  cnf;
        kal_mem_set(&cnf, '\0', sizeof(cnf));
        cnf.status = (ptrMsg->param.CheckIfFuncExist.result==1)?FT_CNF_OK:FT_CNF_FAIL;
        cnf.result.CheckIfFuncExist.query_ft_msg_id = ptrMsg->header.ft_msg_id;
        cnf.result.CheckIfFuncExist.query_op_code = ptrMsg->param.CheckIfFuncExist.query_op_code;
        FT_UTIL_SendCnf(&cnf, NULL);
        return;
    }
    FT_SEND_MSG_TO_PC(erfMessage);
}
void FT_ErfCheckFunctionSupported(kal_uint32 query_op_code)
{
    ilm_struct ilm_ptr;
    FT_ERF_TEST_REQ *ptrMsg;	
    FT_ALLOC_OTHER_MSG( &ilm_ptr, sizeof(FT_ERF_TEST_REQ) );
    // local parameter    
    ptrMsg = (FT_ERF_TEST_REQ *)ilm_ptr.local_para_ptr;
    ptrMsg->header.ft_msg_id = FT_ERF_TEST_REQ_ID;  
    ptrMsg->type = ERF_TEST_CMD_CHECK_IF_FUNC_EXIST;
    ptrMsg->param.query_op_code = (ERfTestCmdType)query_op_code;
    FT_SEND_MSG(MOD_FT, MOD_ETSTM, DHL_ETSTM_SAP, MSG_ID_DHL_TO_ETSTM, &ilm_ptr);
}
#endif // #if defined(__LTE_RAT__)&&defined(__TSTM_ENABLE__)
