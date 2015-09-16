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
 * nvram_handler_write.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is write handler function of NVRAM module.
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
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "string.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "nvram_msgid.h"

#include "nvram_data_items.h"
#include "nvram_main.h"
#if defined(__NVRAM_CUSTOM_SENSITIVE__) || defined(__NVRAM_CUSTOM_DISK__)
//MSBB remove #include "fctycomp_config.h"  /* MOD_FT */
#endif

extern kal_mutexid g_nvram_imei_mutex;


/*****************************************************************************
 * FUNCTION
 *  nvram_write_confirm
 * DESCRIPTION
 *  This is nvram_write_confirm() function of NVRAM module.
 * PARAMETERS
 *  dest_id             [IN]
 *  result              [IN]
 *  nvram_write_req     [?]
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_write_confirm(module_type dest_id, nvram_errno_enum result, nvram_write_req_struct *nvram_write_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_write_cnf_struct *nvram_write_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_trace(TRACE_FUNC, FUNC_NVRAM_WRITE_CNF, result);
    nvram_write_cnf = (nvram_write_cnf_struct*) construct_local_para(sizeof(nvram_write_cnf_struct), TD_CTRL);

    nvram_write_cnf->result = result;
    nvram_write_cnf->file_idx = nvram_write_req->file_idx;
    nvram_write_cnf->para = nvram_write_req->para;
    nvram_write_cnf->access_id = nvram_write_req->access_id;

    nvram_send_ilm(dest_id, MSG_ID_NVRAM_WRITE_CNF, nvram_write_cnf, NULL);

    return;
}   /* end of nvram_write_confirm */


/*****************************************************************************
 * FUNCTION
 *  nvram_write_handler
 * DESCRIPTION
 *  This is nvram_write_handler() function of NVRAM module.
 * PARAMETERS
 *  ilm_ptr     [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_write_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_write_req_struct *nvram_write_req = (nvram_write_req_struct*) ilm_ptr->local_para_ptr;

    nvram_ltable_entry_struct *ldi;

    kal_uint8 *pdu_ptr;
    kal_uint16 pdu_length;

    nvram_errno_enum result = NVRAM_ERRNO_SUCCESS;
#if defined(__CCCIFS_SUPPORT__)
    //kal_uint8 modify_cnt[8];
    kal_uint16 modify_cnt = 0;
#endif
    kal_uint32 take_IMEI_nutex = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_trace(TRACE_FUNC, FUNC_NVRAM_WRITE);
    ASSERT(nvram_write_req);

    if (nvram_ptr->state != NVRAM_STATE_READY)
    {
        nvram_write_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_NOT_READY, nvram_write_req);
        return;
    }

    /**
    * Invalid input paramters.
    * file_idx / LID : 1 ~ (total_LID - 1)
    * para / section: 1 ~ total_records
    */
    if (!NVRAM_IS_LID_VALID(nvram_write_req->file_idx))
    {
        nvram_write_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_INVALID_LID, nvram_write_req);
        return;
    }

    nvram_util_get_data_item(&ldi, nvram_write_req->file_idx);

#if defined(__NVRAM_CUSTOM_SENSITIVE__) || defined(__NVRAM_CUSTOM_DISK__)
    /* In Meta mode, we cannot access the data belongs to custom sensitve area */
    if (NVRAM_IS_CATEGORY_CUSTOM_SENSITIVE(ldi->category) || NVRAM_IS_CATEGORY_CUSTOM_DISK(ldi->category))
    {
        if (FACTORY_BOOT == stack_query_boot_mode() && ilm_ptr->src_mod_id == MOD_FT)
        {
            nvram_write_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_ACCESS_DENIED, nvram_write_req);
            return;
        }
    }
#endif

    if ((nvram_write_req->para < 1) ||
        (nvram_write_req->para > ldi->total_records))
    {
        nvram_write_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_INVALID_RECORD, nvram_write_req);
        return;
    }

    ASSERT(ilm_ptr->peer_buff_ptr != NULL);
    pdu_ptr = get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &pdu_length);

    if (pdu_length != ldi->size)
    {
        nvram_write_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_INVALID_SIZE, nvram_write_req);
        return;
    }

    if (ldi->attr & NVRAM_ATTR_RING)
    {
        kal_uint8 *index = (kal_uint8 *)get_ctrl_buffer(ldi->size);
        memset(index, 0, ldi->size);
        if (nvram_read_data_item(ldi, 1, 1, index, ldi->size) == NVRAM_IO_ERRNO_OK)
        {
            nvram_write_req->para = (kal_uint16)index[0];

            nvram_write_req->para++;

            if (nvram_write_req->para > ldi->total_records || nvram_write_req->para < 2)
                nvram_write_req->para = 2;

            index[0] = (kal_uint8)nvram_write_req->para;

            if (nvram_write_data_item(ldi, 1, index, KAL_FALSE) != NVRAM_IO_ERRNO_OK)
            {
                free_ctrl_buffer(index);
                nvram_write_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_WRONG_RINGLID, nvram_write_req);
                return;
            }

            if (nvram_write_data_item(ldi, nvram_write_req->para, pdu_ptr, KAL_FALSE) == NVRAM_IO_ERRNO_OK)
            {
                free_ctrl_buffer(index);
                nvram_write_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_OK, nvram_write_req);
                return;
            }
        }
        free_ctrl_buffer(index);
        nvram_write_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_WRONG_RINGLID, nvram_write_req);

    }
    else
    {
        if (ldi->LID == NVRAM_EF_IMEI_IMEISV_LID)
        {
            nvram_util_take_mutex(g_nvram_imei_mutex);
            take_IMEI_nutex = 1;
        }

        result = nvram_write_data_item(ldi, nvram_write_req->para, pdu_ptr, KAL_FALSE);

#if defined(__CCCIFS_SUPPORT__)
                if (result == NVRAM_ERRNO_SUCCESS)
                {
                    if (ldi->category & (NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_IMPORTANT | NVRAM_CATEGORY_IMPORTANT_L4))
                    {
                        nvram_util_get_data_item(&ldi, NVRAM_EF_IMPT_COUNTER_LID);
                        result = nvram_read_data_item(ldi, 1, 1, (kal_uint8*)&modify_cnt, 2);
                        if (result == NVRAM_ERRNO_SUCCESS)
                        {
                            modify_cnt++; 
                            
                            result = nvram_write_data_item(ldi, 1, (kal_uint8*)&modify_cnt, KAL_FALSE);
                        }
                    }
                }
#endif
        nvram_write_confirm(ilm_ptr->src_mod_id, result, nvram_write_req);
        //if (ldi->LID == NVRAM_EF_IMEI_IMEISV_LID)
        if (take_IMEI_nutex > 0)
        {
            nvram_util_give_mutex(g_nvram_imei_mutex);
            take_IMEI_nutex = 0;
        }
    }
}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__NVRAM_CUSTOM_SENSITIVE__) || defined(__NVRAM_CUSTOM_DISK__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

