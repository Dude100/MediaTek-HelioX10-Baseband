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
 * nvram_handler_reset.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is reset handler function of NVRAM module.
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
 * removed!
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
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_trace.h"
#include "nvram_msgid.h"

#ifdef __NVRAM_OTP__
#include "fs_gprot.h"
#include "fs_iprot.h"
#endif

//MSBB remove #include "fctycomp_config.h" /* MOD_FT */

#include "nvram_main.h"

static void nvram_reset_confirm(module_type dest_id, nvram_errno_enum result, nvram_reset_req_struct *nvram_reset_req);

static void nvram_set_lock_confirm(
                module_type dest_id,
                nvram_errno_enum result,
                nvram_set_lock_req_struct *nvram_set_lock_req);


/*****************************************************************************
 * FUNCTION
 *  nvram_reset_handler
 * DESCRIPTION
 *  This is nvram_reset_handler() function of NVRAM module.
 * PARAMETERS
 *  ilm_ptr     [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_reset_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi;
    nvram_reset_req_struct *nvram_reset_req = (nvram_reset_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_trace(TRACE_FUNC, FUNC_NVRAM_RESET);
    ASSERT(nvram_reset_req != NULL);
    if (nvram_ptr->dev_broken)
    {
        nvram_reset_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_SUCCESS, nvram_reset_req);
    }
    else
    {

        if (nvram_ptr->state == NVRAM_STATE_READY)
        {
            if (!(nvram_reset_req->reset_category & NVRAM_RESET_CERTAIN))
            {
                nvram_reset_req->LID = 0;
            }

            nvram_util_get_data_item(&ldi, nvram_reset_req->LID);

            if (nvram_reset_req->reset_category == NVRAM_RESET_CERTAIN)
            {
                if (!NVRAM_IS_LID_VALID(nvram_reset_req->LID))
                {
                    nvram_reset_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_INVALID_LID, nvram_reset_req);
                    return;
                }
                
                /* In Meta mode, we cannot access the data belongs to custom sensitve area
                   we also cannot reset the important data to prevent security problem */
                 
               
                if (NVRAM_IS_CATEGORY_IMPORTANT(ldi->category)
                    || NVRAM_IS_CATEGORY_IMPORTANT_L4(ldi->category)
                    #if defined(__NVRAM_CUSTOM_SENSITIVE__) || defined(__NVRAM_CUSTOM_DISK__)
                    || NVRAM_IS_CATEGORY_CUSTOM_SENSITIVE(ldi->category)
                    || NVRAM_IS_CATEGORY_CUSTOM_DISK(ldi->category)
                    #endif
                   )
                {
                    if (FACTORY_BOOT == kal_query_boot_mode() && ilm_ptr->src_mod_id == MOD_FT)
                    {
                        
                        nvram_reset_confirm(ilm_ptr->src_mod_id, NVRAM_IO_ERRNO_ACCESS_DENIED, nvram_reset_req);
                        return;
                    }
                }
            }

            if (nvram_reset_data_items(nvram_reset_req->reset_category, nvram_reset_req->app_id, ldi, nvram_reset_req->rec_index, nvram_reset_req->rec_amount) == KAL_TRUE)
            {
                nvram_reset_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_SUCCESS, nvram_reset_req);
            }
            else
            {
                nvram_reset_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_FAIL, nvram_reset_req);
            }
        }
        /* State error */
        else
        {
            nvram_trace(TRACE_FUNC, ERROR_NVRAM_STATE);

            nvram_reset_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_FAIL, nvram_reset_req);
        }
    }
}   /* end of nvram_reset_handler */


/*****************************************************************************
 * FUNCTION
 *  nvram_reset_confirm
 * DESCRIPTION
 *  This is nvram_reset_confirm() function of NVRAM module.
 * PARAMETERS
 *  dest_id             [IN]        
 *  result              [IN]        
 *  nvram_reset_req     [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_reset_confirm(module_type dest_id, nvram_errno_enum result, nvram_reset_req_struct *nvram_reset_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_reset_cnf_struct *nvram_reset_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_trace(TRACE_FUNC, FUNC_NVRAM_RESET_CNF, result);
    nvram_reset_cnf = (nvram_reset_cnf_struct*) construct_local_para(sizeof(nvram_reset_cnf_struct), TD_CTRL);


    nvram_reset_cnf->result = result;
    nvram_reset_cnf->access_id = nvram_reset_req->access_id;

    nvram_send_ilm(dest_id, MSG_ID_NVRAM_RESET_CNF, nvram_reset_cnf, NULL);

    return;
}   /* end of nvram_reset_confirm */


/*****************************************************************************
 * FUNCTION
 *  nvram_set_lock_handler
 * DESCRIPTION
 *  This is nvram_set_lock_handler() function of NVRAM module.
 * PARAMETERS
 *  ilm_ptr     [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_set_lock_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool lock_state = nvram_ptr->lock;
    nvram_set_lock_req_struct *nvram_set_lock_req = (nvram_set_lock_req_struct*) ilm_ptr->local_para_ptr;
    nvram_ltable_entry_struct *ldi;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nvram_ptr->dev_broken)
    {
        nvram_set_lock_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_INVALID, nvram_set_lock_req);
    }
    else
    {
        nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_LID);

        if ((nvram_set_lock_req->lock_en == NVRAM_LOCK_ENABLE && lock_state == KAL_TRUE) ||
            (nvram_set_lock_req->lock_en == NVRAM_LOCK_DISABLE && lock_state == KAL_FALSE))
        {
            nvram_set_lock_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_SUCCESS, nvram_set_lock_req);
            return;
        }
        else if (nvram_set_lock_req->lock_en == NVRAM_LOCK_TEMP_DISABLE)
        {
            nvram_ptr->lock = KAL_FALSE;
            nvram_set_lock_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_SUCCESS, nvram_set_lock_req);
            return;
        }
    #ifdef __NVRAM_OTP__
        else if (nvram_set_lock_req->lock_en == NVRAM_LOCK_OTP)
        {
            FS_OTPLock(FS_DEVICE_TYPE_NOR);
        }
    #endif /* __NVRAM_OTP__ */

        if (nvram_set_lock_req->lock_en == NVRAM_LOCK_ENABLE)
        {
            nvram_write_system_record(NVRAM_LOCK_ENABLE);
            nvram_set_lock_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_SUCCESS, nvram_set_lock_req);
        }
        else if (nvram_set_lock_req->lock_en == NVRAM_LOCK_DISABLE)
        {
            nvram_write_system_record(NVRAM_LOCK_DISABLE);
            nvram_set_lock_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_SUCCESS, nvram_set_lock_req);
        }
        else
        {
            /* Invalid parameter */
            nvram_set_lock_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_INVALID, nvram_set_lock_req);
            return;
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  nvram_set_lock_confirm
 * DESCRIPTION
 *  This is nvram_set_lock_confirm() function of NVRAM module.
 * PARAMETERS
 *  dest_id                 [IN]        
 *  result                  [IN]        
 *  nvram_set_lock_req      [?]         
 *  ilm_ptr(?)              [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_set_lock_confirm(module_type dest_id,
                                   nvram_errno_enum result,
                                   nvram_set_lock_req_struct *nvram_set_lock_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_set_lock_cnf_struct *nvram_set_lock_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_set_lock_cnf = (nvram_set_lock_cnf_struct*) construct_local_para(sizeof(nvram_set_lock_cnf_struct), TD_CTRL);

    nvram_set_lock_cnf->result = result;

    nvram_send_ilm(dest_id, MSG_ID_NVRAM_SET_LOCK_CNF, nvram_set_lock_cnf, NULL);

    return;

}


/*****************************************************************************
 * FUNCTION
 *  nvram_suspend_handler
 * DESCRIPTION
 *  This is the handler to handle MSG_ID_NVRAM_SUSPEND_REQ
 *  After nvram receive this request, it will be suspend forever now.
 * PARAMETERS
 *  ilm_ptr     [IN]        the message content
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_suspend_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_suspend_req_struct *nvram_suspend_req = (nvram_suspend_req_struct*) ilm_ptr->local_para_ptr;
    nvram_suspend_cnf_struct *nvram_suspend_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_suspend_cnf = (nvram_suspend_cnf_struct*) construct_local_para(sizeof(nvram_suspend_cnf_struct), TD_CTRL);

    nvram_suspend_cnf->result = NVRAM_ERRNO_SUCCESS;

    nvram_send_ilm(ilm_ptr->src_mod_id, MSG_ID_NVRAM_SUSPEND_CNF, nvram_suspend_cnf, NULL);

    if (nvram_suspend_req == NULL || nvram_suspend_req->suspend_time == 0)
    {
        while(1)
        {
            kal_sleep_task(100);
        }
    }
    else
    {
        kal_sleep_task(nvram_suspend_req->suspend_time);
    }

    return;
}
