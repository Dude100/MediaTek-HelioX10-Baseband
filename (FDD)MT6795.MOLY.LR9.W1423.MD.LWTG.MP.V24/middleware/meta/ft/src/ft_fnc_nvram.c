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
 *   ft_fnc_nvram.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   FT NVRAM operations
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/*************************************************************************
 * FT header
 *************************************************************************/
#include "ft_msg.h"
#include "ft_private.h"
#include "ft_fnc_nvram.h"
#include "ft_fnc_l1rf.h"
#include "ft_fnc_wcdma.h"
#include "ft_fnc_misc.h"
#include "svc_sap.h"
#include "nvram_msgid.h"
#include "ft_msgid.h"
/**************************************************************************
 * NVRAM header
 *************************************************************************/
#include "nvram_defs.h"
#include "nvram_enums.h"
#include "nvram_interface.h"
#include "nvram_data_items.h"
#include "nvram_struct.h"
#ifdef __NVRAM_SECRET_DATA__
#include "rc4.h"
#endif // #ifdef __NVRAM_SECRET_DATA__
/*******************************************************************************
 * FUNCTION
 *   FT_WriteTo_NVRAM()
 *
 * DESCRIPTION
 *   Handle the write request of NVRAM
 *
 * CALLS
 *   None
 *
 * PARAMETERS
 *
 *
 * RETURNS
 *   None
 *
 * GLOBALS AFFECTED
 *   None
 *******************************************************************************/
#ifdef __NVRAM_SECRET_DATA__
kal_uint16  g_u2_ft_nvram_pdu_length = 0;
kal_uint8   *p_g_u1_ft_nvram_pdu_ptr = NULL;
peer_buff_struct *p_g_pbs_ft_nvram = NULL;
#endif // #ifdef __NVRAM_SECRET_DATA__
void FT_WriteTo_NVRAM(ft_nvram_write_req_struct_T* req, peer_buff_struct* peer_buff, ilm_struct* ptrMsg)
{
    ilm_struct  ilm_ptr;
    nvram_write_req_struct *nvram_ptr_loc_para;
    kal_uint16             pdu_length;
    kal_uint8              *pdu_ptr = get_peer_buff_pdu( peer_buff, &pdu_length );
#ifdef __NVRAM_SECRET_DATA__
    kal_bool  bPassCheck = KAL_FALSE;
    kal_int32 err_code = 0xFE;
    kal_uint8 key[256]; // at most 256 bytes
    kal_int32 real_key_len;
    real_key_len = custom_nvram_get_database_key(key, sizeof(key));
    if(req->msg_num == 2 && real_key_len >0) // we must wait until we collect all
    {
        if(req->msg_idx == 0) // allocate a peer buffer to store it.
        {
            if(p_g_pbs_ft_nvram != NULL) // free previous buffer
            {
                free_peer_buff(p_g_pbs_ft_nvram);
                p_g_pbs_ft_nvram = NULL;
            }
            // allocate a new peer buffer
            if( NULL != (p_g_pbs_ft_nvram=construct_peer_buff(pdu_length, 0, 0, TD_CTRL)) )
            {
                p_g_u1_ft_nvram_pdu_ptr = get_peer_buff_pdu( p_g_pbs_ft_nvram, &g_u2_ft_nvram_pdu_length );
                kal_mem_cpy(p_g_u1_ft_nvram_pdu_ptr, pdu_ptr , pdu_length);
                p_g_pbs_ft_nvram->pdu_len = pdu_length;
            }
            return; // wait for next message
        }
        else // the second message with encrpted data
        {
            kal_int32 i;
            RC4_CNXT cnxt;
            kal_uint8 *output_data = (kal_uint8*) get_ctrl_buffer(g_u2_ft_nvram_pdu_length);  // since at most 2k bytes
            if(p_g_u1_ft_nvram_pdu_ptr!=NULL)
            {
                // get the key
                //real_key_len =  custom_nvram_get_database_key(key, sizeof(key));
                if(real_key_len >0) // get the key
                {
                    // deciphered the input data
                    che_rc4_set_key((RC4_CNXT *)&cnxt, (kal_uint32)real_key_len, (kal_uint8 *)key);
                    che_rc4((RC4_CNXT *)&cnxt, p_g_u1_ft_nvram_pdu_ptr , g_u2_ft_nvram_pdu_length, key, real_key_len, CHE_MODE_NULL, output_data);
                    for(i=0; i<g_u2_ft_nvram_pdu_length; i++)
                    {
                        if(output_data[i] != pdu_ptr[i])
                        {
                            err_code = 0xFD;
                            break;
                        }
                    }
                    if(i == g_u2_ft_nvram_pdu_length)
                    {
                        bPassCheck = true;
                    }
                }
            }
            else
            {
                err_code = 0xFC;
            }
            free_ctrl_buffer(output_data);
        }
    }
    else
    {
        if(real_key_len == 0 || g_b_ft_nvram_proc_locally == true) // sec not ON
            bPassCheck = true;
    }
    if(!bPassCheck)
    {
        // invoke:
        nvram_write_cnf_struct  cnf_result;
        cnf_result.file_idx = req->file_idx;
        cnf_result.para = req->para;
        cnf_result.result = err_code;
        // allocate a peer buffer to stored the output data for debug
        FT_WriteTo_NVRAM_CNF(&cnf_result);
        return;
    }
    if(real_key_len >0 &&
            req->msg_num == 2 &&
            p_g_pbs_ft_nvram != NULL) // re-assign the pdu_ptr, and free the buffer
    {
        kal_mem_cpy(pdu_ptr, p_g_u1_ft_nvram_pdu_ptr,pdu_length);
        free_peer_buff(p_g_pbs_ft_nvram);
        p_g_pbs_ft_nvram = NULL;
    }
#endif // #ifdef __NVRAM_SECRET_DATA__
    FT_ALLOC_OTHER_MSG(&ilm_ptr ,sizeof(nvram_write_req_struct));
    nvram_ptr_loc_para=(nvram_write_req_struct *)(ilm_ptr.local_para_ptr);
    nvram_ptr_loc_para->file_idx=req->file_idx;/* LID */
    nvram_ptr_loc_para->para=req->para;
    nvram_ptr_loc_para->access_id=0 ; // change it!
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
    {
        // stop RF
        L1TST_Stop();
    }
#endif // #ifdef _LOW_COST_SINGLE_BANK_FLASH_
    // keep a runtime buffer of the written value for updating L1 runtime
    // FIX: ACCESS OUT-OF BOUND
    if(pdu_length > sizeof(ft_rf_data_pt))
    {
        kal_mem_cpy(&ft_rf_data_pt, pdu_ptr, sizeof(ft_rf_data_pt));
    }
    else
    {
        kal_mem_cpy(&ft_rf_data_pt, pdu_ptr, pdu_length);
    }
    ilm_ptr.peer_buff_ptr = peer_buff;
    /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
    FT_SEND_MSG(MOD_FT, MOD_NVRAM, PS_NVRAM_SAP, MSG_ID_NVRAM_WRITE_REQ, &ilm_ptr);
    if(ptrMsg != NULL)
       ptrMsg->peer_buff_ptr=NULL;/* make sure the NVRAM will release the mem*/
}
/*******************************************************************************
 * FUNCTION
 *   FT_ReadFrom_NVRAM()
 *
 * DESCRIPTION
 *   Handle the read request of FT to NVRAM
 *
 * CALLS
 *   None
 *
 * PARAMETERS
 *
 *
 * RETURNS
 *   None
 *
 * GLOBALS AFFECTED
 *   None
 *******************************************************************************/
void FT_ReadFrom_NVRAM(ft_nvram_read_req_struct_T* req)
{
    ilm_struct  ilm_ptr;
    nvram_read_req_struct *ptrMsg;
#ifdef __NVRAM_SECRET_DATA__
    kal_uint8 key[256]; // at most 256 bytes
    kal_int32 real_key_len;
    kal_uint8 input_data[4];
    kal_uint8 output_data[4];
    kal_uint8 i;
    RC4_CNXT cnxt;
    kal_uint32 err_code = 0xFE;
    kal_bool bPassCheck = KAL_FALSE;
    real_key_len =  custom_nvram_get_database_key(key, sizeof(key));
    kal_mem_set(output_data, 0x0, sizeof(output_data));
    // make sure if the authenticaion pass
    if(req->ciphered_data_valid && real_key_len > 0 ) // the load need to be checked, and user send ciphered data
    {
        kal_mem_cpy(input_data, &(req->file_idx), 2);
        kal_mem_cpy(input_data+2, &(req->para), 2);
        // deciphered the input data
        che_rc4_set_key((RC4_CNXT *)&cnxt, (kal_uint32)real_key_len, (kal_uint8 *)key);
        che_rc4((RC4_CNXT *)&cnxt, input_data , 4, key, real_key_len, CHE_MODE_NULL, output_data);
        for(i=0; i<4; i++)
        {
            if(output_data[i] != req->ciphered_data[i])
            {
                err_code = 0xFD;
                break;
            }
        }
        if(i == 4)
            bPassCheck = KAL_TRUE;
    }
    else // ciphered data invalid
    {
        if(real_key_len == 0 || g_b_ft_nvram_proc_locally == true) // no need to checked
            bPassCheck = KAL_TRUE;
        else // need check, but user doesn't send data
            err_code = 0xFB;
    }
    if(!bPassCheck)
    {
        // invoke:
        kal_uint16    pdu_length_new = 0;
        kal_uint8   *pdu_ptr_new;
        peer_buff_struct *peer_buff_new;
        nvram_read_cnf_struct  cnf_result;
        cnf_result.file_idx = req->file_idx;
        cnf_result.para = req->para;
        cnf_result.result = err_code;
        // allocate a peer buffer to stored the output data for debug

        if( NULL != (peer_buff_new=construct_peer_buff(4, 0, 0, TD_CTRL)) )
        {
            pdu_ptr_new = get_peer_buff_pdu( peer_buff_new, &pdu_length_new );
            kal_mem_cpy(pdu_ptr_new, output_data , 4);
            peer_buff_new->pdu_len = 4;
        }
        FT_ReadFrom_NVRAM_CNF(&cnf_result, peer_buff_new);
        return;
    }
#endif // #ifdef __NVRAM_SECRET_DATA__
    FT_ALLOC_OTHER_MSG(&ilm_ptr, sizeof(nvram_read_req_struct));
    /* if ptrMsg != NULL*/
    ptrMsg = (nvram_read_req_struct *)ilm_ptr.local_para_ptr;
    ptrMsg->file_idx=req->file_idx;
    ptrMsg->access_id=0;
    ptrMsg->para=req->para;
    /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
    FT_SEND_MSG(MOD_FT, MOD_NVRAM, PS_NVRAM_SAP, MSG_ID_NVRAM_READ_REQ, &ilm_ptr);// wait READ_CNF
}
/*******************************************************************************
 * FUNCTION
 *   FT_ReadFrom_NVRAM_CNF
 *
 * DESCRIPTION
 *   Handle the confirmation of reading
 *
 * CALLS
 *
 *
 * PARAMETERS
 *   local_para_struct * local_para_ptr, //( force to nvram_read_cnf_struct* cnf )
 *   peer_buff_struct * peer_buff_ptr
 *
 *
 * RETURNS
 *   None
 *
 * GLOBALS AFFECTED
 *   None
 *******************************************************************************/
void FT_ReadFrom_NVRAM_CNF(nvram_read_cnf_struct*  cnf_result,
        peer_buff_struct*       peer_buff )
{
    ilm_struct    ilm_ptr;
    ft_nvram_read_cnf_struct_T *ft_cnf;

    if(!g_b_ft_nvram_proc_locally ||  cnf_result->file_idx != NVRAM_EF_CAL_DATA_CHECK_LID)
    {
        FT_ALLOC_MSG(&ilm_ptr, sizeof(ft_nvram_read_cnf_struct_T));
        ft_cnf = (ft_nvram_read_cnf_struct_T *)ilm_ptr.local_para_ptr;
        ft_cnf->header.ft_msg_id = FT_NVRAM_READ_CNF_ID;
        ft_cnf->file_idx=cnf_result->file_idx;
        ft_cnf->para=cnf_result->para;
#if defined(__MOD_NVRAM__)
        if( nvram_test_lock() && (NVRAM_EF_SML_LID==cnf_result->file_idx) ) {
            ft_cnf->status = 0xFF;
            ilm_ptr.peer_buff_ptr = NULL;
            free_peer_buff(peer_buff);
        }
        else
        {
            ft_cnf->status = cnf_result->result;
            ilm_ptr.peer_buff_ptr=peer_buff;
        }
#endif // #if defined(__MOD_NVRAM__)
        FT_SEND_MSG_TO_PC(&ilm_ptr);
    }
    else
    {
#if !defined(NVRAM_NOT_PRESENT)
        ft_misc_cal_data_read_from_nvram_cnf(cnf_result,peer_buff);
        free_peer_buff(peer_buff);
#endif // #if !defined(NVRAM_NOT_PRESENT)
    }

}
/*******************************************************************************
 * FUNCTION
 *   FT_WriteTo_NVRAM_CNF
 *
 * DESCRIPTION
 *   Handle the confirmation of writting
 *
 * CALLS
 *
 *
 * PARAMETERS
 *
 * RETURNS
 *   None
 *
 * GLOBALS AFFECTED
 *   None
 *******************************************************************************/
void FT_WriteTo_NVRAM_CNF(nvram_write_cnf_struct* cnf_result)
{
    ilm_struct  ilm_ptr;
    ft_nvram_write_cnf_struct_T *ptrMsg ;
    kal_uint8       ok;

    if (cnf_result->result ==0)
        ok = FT_CNF_OK;
    else
        ok = FT_CNF_FAIL;

    if(ok==FT_CNF_OK)
    {
        switch(cnf_result->file_idx)
        {
            default:
                /**V \brief 2G update runtime value after wrote nvram */
#if !defined(__LTE_SM__)
                L1TST_UpdateCalibrationData( cnf_result->file_idx );
#endif // #if !defined(__LTE_SM__)                
#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)                
                /**V \brief 3G WCDMA update runtime value after wrote nvram */
                FT_UL1TST_UpdateRuntimeReq( cnf_result->file_idx );              
#endif // #if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)                           
                break;
        }
    }
    if(!g_b_ft_nvram_proc_locally || cnf_result->file_idx != NVRAM_EF_CAL_DATA_CHECK_LID)
    {
        FT_ALLOC_MSG(&ilm_ptr, sizeof(ft_nvram_write_cnf_struct_T));
        /* if ptrMsg != NULL*/
        ptrMsg = (ft_nvram_write_cnf_struct_T *)ilm_ptr.local_para_ptr;
        ptrMsg->header.ft_msg_id = FT_NVRAM_WRITE_CNF_ID;
        ptrMsg->file_idx=cnf_result->file_idx;
        ptrMsg->para=cnf_result->para;
        ptrMsg->status = cnf_result->result;
        FT_SEND_MSG_TO_PC(&ilm_ptr);
    }
    else // write locally complete, return misc confirm to PC side
    {
#if !defined(NVRAM_NOT_PRESENT)
        ft_misc_cal_data_write_to_nvram_cnf(cnf_result);
#endif // #if !defined(NVRAM_NOT_PRESENT)
    }
    if(ok == FT_CNF_OK && g_b_ft_nvram_rec)
    {
       // get the nvram checksum from nvram
       kal_uint16 u2_checksum;
       bool bValid = ft_misc_cal_data_get_checksum((kal_uint16)cnf_result->file_idx,
                    cnf_result->para,&u2_checksum);
       if(bValid)
       {
           // update the misc_buffer
           ft_misc_cal_data_update_local_buf((kal_uint16)cnf_result->file_idx,
                   cnf_result->para, u2_checksum);
       }
    }
}
