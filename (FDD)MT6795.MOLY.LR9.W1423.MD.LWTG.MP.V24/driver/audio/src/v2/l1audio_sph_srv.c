/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *
 * Filename:
 * ---------
 * l1audio_sph_srv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Speech Service. For example, speech parameter or VM Over Catcher (VOC). 
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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


#include "stdlib.h"
#include "task_config.h"
#include "syscomp_config.h"
#include "kal_public_api.h"
#include "tst_sap.h"
#include "tst_msgid.h"

#include "kal_trace.h"
#include "l1audio_sph_trc.h"

#include "l1audio_def.h"


extern kal_bool setCommonPara;
extern uint16 commonPara_0;

void voc_tst_handler(kal_char *string)
{
   commonPara_0 = atoi(string);
   
   if ((commonPara_0 < 0) || (commonPara_0 > 16))
   {
      setCommonPara = KAL_FALSE;
      commonPara_0 = 0;
      kal_trace(TRACE_GROUP_EPL, EPL_PARA_ERROR);
   }
   else
   {
      setCommonPara = KAL_TRUE;
      kal_trace(TRACE_GROUP_EPL, SET_EPL_PARA, commonPara_0);
   }
}


//void sw_transcoding_tst_handler(kal_char *string)
//{
//   return;
//}

void l1audio_sph_srv_tst_handler(ilm_struct *ilm_ptr)
{
   tst_module_string_inject_struct *tst_inject = (tst_module_string_inject_struct*) ilm_ptr->local_para_ptr;

   ASSERT(tst_inject != NULL);

   switch (tst_inject->index)
   {
      case 1:
      {
	     voc_tst_handler( (kal_char *)tst_inject->string );
         break;
      }
//	  case 2:
//	  {
//         sw_transcoding_tst_handler(tst_inject->string);
//	  }
      default:
         break;
   }
}

void l1audio_sph_srv_main(ilm_struct *ilm_ptr)
{
   if(ilm_ptr->msg_id == MSG_ID_TST_INJECT_STRING)
      l1audio_sph_srv_tst_handler(ilm_ptr);
} 

void l1audio_sph_srv_task_main(task_entry_struct *task_entry_ptr)
{
   ilm_struct current_ilm;

   while(1)
   {
      msg_receive_extq(&current_ilm);
      kal_set_active_module_id(current_ilm.dest_mod_id);

      l1audio_sph_srv_main((void *)&current_ilm);

      destroy_ilm(&current_ilm);
   }
}

kal_bool l1audio_sph_srv_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct l1audio_sph_srv_handler_info =
   {
      l1audio_sph_srv_task_main,
      NULL,
      NULL
   };
   *handle = (comptask_handler_struct *)&l1audio_sph_srv_handler_info;
   return KAL_TRUE;
}

