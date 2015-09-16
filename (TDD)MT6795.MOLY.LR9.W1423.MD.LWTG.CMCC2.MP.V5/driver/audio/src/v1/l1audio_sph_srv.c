#include "task_config.h"
#include "syscomp_config.h"
#include "kal_public_api.h"
#include "tst_sap.h"
#include "tst_msgid.h"

#include "kal_trace.h"
#include "l1audio_sph_trc.h"

#include "l1audio_def.h"
#include "stdlib.h"

#include "sal_exp.h"


kal_bool setCommonPara = KAL_FALSE;
uint16 commonPara_0 = 0;

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
	case 66:
	 {
		SAL_TST_Handler(atoi((kal_char *)tst_inject->string));
		break;
	 }
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

