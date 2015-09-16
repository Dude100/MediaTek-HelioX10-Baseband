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
 * nvram_msg_handler.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   To handle the messages sent to NVRAM
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
* Include
*****************************************************************************/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "nvram_msgid.h"

#include "nvram_main.h"

/*****************************************************************************
 * FUNCTION
 *  nvram_create_image_confirm
 * DESCRIPTION
 *  send the create image confirm
 * PARAMETERS
 *  dest_id:    [IN]    the destination module
 *  result:     [IN]    error code
 *  nvram_create_image_req:   [IN]    the reqeuset message sent from destination module
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
 void nvram_create_image_confirm(module_type dest_id, nvram_errno_enum result, nvram_create_image_req_struct *nvram_create_image_req)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     nvram_create_image_cnf_struct *nvram_create_image_cnf;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/

     nvram_create_image_cnf = (nvram_create_image_cnf_struct*) construct_local_para(sizeof(nvram_create_image_cnf_struct), TD_RESET);
     nvram_create_image_cnf->result = result;
     nvram_create_image_cnf->access_id = nvram_create_image_req->access_id;

     nvram_send_ilm(dest_id, MSG_ID_NVRAM_CREATE_IMAGE_CNF, nvram_create_image_cnf, NULL);

     return;
 }

/*****************************************************************************
 * FUNCTION
 *  nvram_create_image_handler
 * DESCRIPTION
 *  This function is to handle the MSG_ID_NVRAM_CREATE_IMAGE_REQ.
 * PARAMETERS
 *  ilm_ptr:        [IN]    the message sent from other module
 * RETURNS
 *  void
 *****************************************************************************/
 void nvram_create_image_handler(ilm_struct *ilm_ptr)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     nvram_create_image_req_struct *req = (nvram_create_image_req_struct*) ilm_ptr->local_para_ptr;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/

#ifdef __NVRAM_BACKUP_DISK_RAW__
    if (nvram_ptr->state != NVRAM_STATE_READY)
    {
        nvram_trace(TRACE_ERROR, ERROR_NVRAM_STATE);
        nvram_create_image_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_NOT_READY, req);
        return;
    }

    nvram_create_image_confirm(ilm_ptr->src_mod_id, nvram_create_image(req->image_type), req);
#else
    nvram_create_image_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_INVALID, req);
#endif
 }

/*****************************************************************************
 * FUNCTION
 *  nvram_recover_image_confirm
 * DESCRIPTION
 *  send the recover image confirm
 * PARAMETERS
 *  dest_id:    [IN]    the destination module
 *  result:     [IN]    error code
 *  nvram_recover_image_req:   [IN]    the reqeuset message sent from destination module
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
 void nvram_recover_image_confirm(module_type dest_id, nvram_errno_enum result, nvram_recover_image_req_struct *nvram_recover_image_req)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     nvram_recover_image_cnf_struct *nvram_recover_image_cnf;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/

     nvram_recover_image_cnf = (nvram_recover_image_cnf_struct*) construct_local_para(sizeof(nvram_recover_image_cnf_struct), TD_RESET);
     nvram_recover_image_cnf->result = result;
     nvram_recover_image_cnf->access_id = nvram_recover_image_req->access_id;

     nvram_send_ilm(dest_id, MSG_ID_NVRAM_RECOVER_IMAGE_CNF, nvram_recover_image_cnf, NULL);

     return;
 }


/*****************************************************************************
 * FUNCTION
 *  nvram_recover_image_handler
 * DESCRIPTION
 *  This function is to handle the MSG_ID_NVRAM_RECOVER_IMAGE_REQ.
 * PARAMETERS
 *  ilm_ptr:        [IN]    the message sent from other module
 * RETURNS
 *  void
 *****************************************************************************/
  void nvram_recover_image_handler(ilm_struct *ilm_ptr)
  {
      /*----------------------------------------------------------------*/
      /* Local Variables                                                */
      /*----------------------------------------------------------------*/
      nvram_recover_image_req_struct *req = (nvram_recover_image_req_struct*) ilm_ptr->local_para_ptr;

      /*----------------------------------------------------------------*/
      /* Code Body                                                      */
      /*----------------------------------------------------------------*/

#ifdef __NVRAM_BACKUP_DISK_RAW__
    if (nvram_ptr->state != NVRAM_STATE_READY)
    {
        nvram_trace(TRACE_ERROR, ERROR_NVRAM_STATE);

        nvram_recover_image_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_NOT_READY, req);
        return;
    }

    nvram_recover_image_confirm(ilm_ptr->src_mod_id, nvram_recover_image(req->image_type), req);
#else
    nvram_recover_image_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_INVALID, req);
#endif

}

 /*****************************************************************************
 * FUNCTION
 *  nvram_verify_image_confirm
 * DESCRIPTION
 *  send the verify image confirm
 * PARAMETERS
 *  dest_id:    [IN]    the destination module
 *  result:     [IN]    error code
 *  nvram_verify_image_eq:   [IN]    the reqeuset message sent from destination module
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
 void nvram_verify_image_confirm(module_type dest_id, nvram_errno_enum result, nvram_verify_image_req_struct *nvram_verify_image_req)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     nvram_verify_image_cnf_struct *nvram_verify_image_cnf;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/

     nvram_verify_image_cnf = (nvram_verify_image_cnf_struct*) construct_local_para(sizeof(nvram_verify_image_cnf_struct), TD_RESET);
     nvram_verify_image_cnf->result = result;
     nvram_verify_image_cnf->access_id = nvram_verify_image_req->access_id;

     nvram_send_ilm(dest_id, MSG_ID_NVRAM_VERIFY_IMAGE_CNF, nvram_verify_image_cnf, NULL);

     return;
 }

/*****************************************************************************
 * FUNCTION
 *  nvram_verify_image_handler
 * DESCRIPTION
 *  This function is to handle the MSG_ID_NVRAM_VERIFY_IMAGE_REQ.
 * PARAMETERS
 *  ilm_ptr:        [IN]    the message sent from other module
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_verify_image_handler(ilm_struct *ilm_ptr)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   nvram_verify_image_req_struct *req = (nvram_verify_image_req_struct*) ilm_ptr->local_para_ptr;

   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __NVRAM_BACKUP_DISK_RAW__
    if (nvram_ptr->state != NVRAM_STATE_READY)
    {
        nvram_trace(TRACE_ERROR, ERROR_NVRAM_STATE);

        nvram_verify_image_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_NOT_READY, req);
        return;
    }

    nvram_verify_image_confirm(ilm_ptr->src_mod_id, nvram_verify_image(req->image_type, req->fast_verify), req);
#else
    nvram_verify_image_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_INVALID, req);
#endif /* __SYSDRV_BACKUP_DISK_RAW__ */
}

#ifdef __NVRAM_SECURE_DATA_STORAGE__
 /*****************************************************************************
 * FUNCTION
 *  nvram_sds_confirm
 * DESCRIPTION
 *  send the sds confirm
 * PARAMETERS
 *  dest_id:    [IN]    the destination module
 *  result:     [IN]    error code
 *  nvram_verify_image_eq:   [IN]    the reqeuset message sent from destination module
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
 void nvram_sds_confirm(module_type dest_id, nvram_errno_enum result, nvram_sds_req_struct *req)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     nvram_sds_cnf_struct *nvram_backup_to_sds_cnf;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/

     nvram_backup_to_sds_cnf = (nvram_sds_cnf_struct*) construct_local_para(sizeof(nvram_sds_cnf_struct), TD_RESET);
     nvram_backup_to_sds_cnf->result = result;
     nvram_backup_to_sds_cnf->access_id = req->access_id;

     nvram_send_ilm(dest_id, MSG_ID_NVRAM_SDS_CNF, nvram_backup_to_sds_cnf, NULL);

     return;
 }

/*****************************************************************************
 * FUNCTION
 *  nvram_sds_handler
 * DESCRIPTION
 *  This function is to handle the MSG_ID_NVRAM_SDS_REQ.
 * PARAMETERS
 *  ilm_ptr:        [IN]    the message sent from other module
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_sds_handler(ilm_struct *ilm_ptr)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   nvram_sds_req_struct *sds_req = (nvram_sds_req_struct*) ilm_ptr->local_para_ptr;
   nvram_errno_enum result = NVRAM_ERRNO_SUCCESS;

   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (nvram_ptr->state != NVRAM_STATE_READY)
    {
        nvram_trace(TRACE_ERROR, ERROR_NVRAM_STATE);

        nvram_sds_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_NOT_READY, sds_req);
        return;
    }
    if (sds_req->access_mode == NVRAM_SDS_ACCESS_BACKUP)
    {
        result = nvram_sds_backup();
    }
    else
    {
        result = nvram_sds_restore();
    }
    
    nvram_sds_confirm(ilm_ptr->src_mod_id, result, sds_req);

}
#endif /* __SYSDRV_BACKUP_DISK_RAW__ */

/*****************************************************************************
* FUNCTION
*  nvram_ap_bin_region_confirm
* DESCRIPTION
*  send the ap BIN region confirm
* PARAMETERS
*  dest_id:    [IN]    the destination module
*  result:     [IN]    error code
*  nvram_verify_image_eq:   [IN]    the reqeuset message sent from destination module
* RETURNS
*  void
* RETURN VALUES
*  void
*****************************************************************************/
void nvram_ap_bin_region_confirm(module_type dest_id, nvram_errno_enum result, nvram_bin_region_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_bin_region_cnf_struct *nvram_bin_region_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_bin_region_cnf = (nvram_bin_region_cnf_struct*) construct_local_para(sizeof(nvram_bin_region_cnf_struct), TD_RESET);
    nvram_bin_region_cnf->result = result;
    nvram_bin_region_cnf->access_id = req->access_id;

    nvram_send_ilm(dest_id, MSG_ID_NVRAM_BIN_REGION_CNF, nvram_bin_region_cnf, NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_ap_bin_region_handler
 * DESCRIPTION
 *  This function is to handle the MSG_ID_NVRAM_BIN_REGION_REQ.
 * PARAMETERS
 *  ilm_ptr:        [IN]    the message sent from other module
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_ap_bin_region_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_bin_region_req_struct *bin_region_req = (nvram_bin_region_req_struct*) ilm_ptr->local_para_ptr;
    nvram_errno_enum result = NVRAM_ERRNO_SUCCESS;

    /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/

     if (nvram_ptr->state != NVRAM_STATE_READY)
     {
         nvram_trace(TRACE_ERROR, ERROR_NVRAM_STATE);

         nvram_ap_bin_region_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_NOT_READY, bin_region_req);
         return;
     }

     if (bin_region_req->access_mode == NVRAM_BIN_REGION_BACKUP)
     {
         result = nvram_ap_bin_region_backup();
     }

     nvram_ap_bin_region_confirm(ilm_ptr->src_mod_id, result, bin_region_req);

}

