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
 * Filename:
 * ---------
 *   med_main.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of media task.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/*==== INCLUDES =========*/

/* system includes */

#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "nvram_msgid.h"
#include "sysservice_msgid.h"
#include "tst_msgid.h"
#include "med_msgid.h"
#include "drv_msgid.h"
#include "cmux_msgid.h"
#include "audio_msgid.h"

#include "tst_sap.h"
#include "drv_sap.h"


/* global includes */
#include "l1audio.h"
#include "nvram_struct.h"
#include "audio_nvram_def.h"
#include "nvram_editor_data_item.h"
#include "aud_common_config.h"

/* local include */
#include "med_global.h"
#include "med_mem.h"
#include "med_struct.h"
#include "med_context.h"
#include "med_utility.h"

#include "aud_main.h"
#include "med_main.h"

#ifdef __SPEECH_MODE_TABLE_SUPPORT__
#include "speech_mode_table.h"
#endif

/* global variables */
med_context_struct med_context;
med_context_struct *med_context_p = &med_context;

#ifdef __MTK_TARGET__
   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
      __attribute__ ((section ("DYNAMICCACHEABLEZI_NC_MMIPOOL"))) 
      __attribute__((aligned(4)))
      kal_uint8 med_aud_mem[MED_AUD_MEM_SIZE];
   #else
      __attribute__ ((section ("LARGEPOOL_ZI"))) 
      __attribute__((aligned(4)))
      kal_uint8 med_aud_mem[MED_AUD_MEM_SIZE];
   #endif
#else
    kal_uint8 med_aud_mem[MED_AUD_MEM_SIZE];
#endif


#if !defined(MED_NOT_PRESENT)

/*==== FUNCTIONS ===========*/
extern void med_timer_expiry_hdlr(ilm_struct *ilm_ptr);

/*****************************************************************************
 * FUNCTION
 *  med_nvram_read_data_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle nvram read data confirm.
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_nvram_read_data_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_read_cnf_struct *parm_ptr = NULL;
    kal_uint16 pdu_len;
    kal_uint8 *pdu_ptr;
    audio_param_struct *nvram_param_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MED_FUNC_ENTRY(MED_NVRAM_READ_DATA_CNF_HDLR) */

    parm_ptr = (nvram_read_cnf_struct*) local_para_ptr;
    pdu_ptr = get_peer_buff_pdu(peer_buff_ptr, &pdu_len);
    switch (parm_ptr->file_idx)
    {
        case NVRAM_EF_CUST_ACOUSTIC_DATA_LID:
        {
            if (parm_ptr->length != sizeof(custom_acoustic_struct))
            {
                /* error reading length */
                ASSERT(0);
                return;
            }
            kal_mem_cpy(
                &(aud_context_p->acoustic_data),
                (custom_acoustic_struct*) pdu_ptr,
                sizeof(custom_acoustic_struct));

            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
            #if defined(__SPEECH_MODE_TABLE_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_SPEECH_MODE_TABLE_LID, 0, 0);
            #elif defined(__AMRWB_LINK_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID, 0, 0);
            #elif defined(__DUAL_MIC_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_DUAL_MIC_PARAM_LID, 0, 0);
            #else
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
            #endif
            }
            break;
        }

    #ifdef __SPEECH_MODE_TABLE_SUPPORT__        
        case NVRAM_EF_AUDIO_SPEECH_MODE_TABLE_LID:
            kal_mem_cpy(
                speech_mode_table_nvram,
                (nvram_speech_mode_table_struct*) pdu_ptr,
                sizeof(nvram_speech_mode_table_struct));
            
            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
            #if defined(__AMRWB_LINK_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID, 0, 0);
            #elif defined( __DUAL_MIC_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_DUAL_MIC_PARAM_LID, 0, 0);
            #else
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
            #endif
            }
            break;
    #endif /* __SPEECH_MODE_TABLE_SUPPORT__ */
    
    #ifdef __AMRWB_LINK_SUPPORT__
        case NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID:
            ASSERT(parm_ptr->length == sizeof(audio_wb_speech_fir_struct));

            /*set to L1SP directly*/
            L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_WB_SPEECH_INPUT_FIR,(kal_uint8*) pdu_ptr, parm_ptr->length);

            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_LID, 0, 0);
            }
            break;

        case NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_LID:
            ASSERT(parm_ptr->length == sizeof(audio_wb_speech_fir_struct));

            /*set to L1SP directly*/
            L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_WB_SPEECH_OUTPUT_FIR,(kal_uint8*) pdu_ptr, parm_ptr->length);

            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_LID, 0, 0);
            }
            break;

         case NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_LID:
            ASSERT(parm_ptr->length == sizeof(audio_wb_speech_mode_struct));

            /*set to L1SP directly*/
            L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_WB_SPEECH_MODE_PARAM,(kal_uint8*) pdu_ptr, parm_ptr->length);

            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
            #if defined(__DUAL_MIC_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_DUAL_MIC_PARAM_LID, 0, 0);
            #else
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
            #endif
            }
            break;
    #endif /* __AMRWB_LINK_SUPPORT__ */

    #ifdef __DUAL_MIC_SUPPORT__
         case NVRAM_EF_AUDIO_DUAL_MIC_PARAM_LID:
         {
             audio_dual_mic_param_struct* dm_param_p;
             
             ASSERT(parm_ptr->length == sizeof(audio_dual_mic_param_struct));
             dm_param_p = (audio_dual_mic_param_struct*)pdu_ptr;

             L1SP_SetDMNRPara((kal_int16 *)(&dm_param_p->nb_param));
        #ifdef __AMRWB_LINK_SUPPORT__
             L1SP_SetWbDMNRPara((kal_int16 *)(&dm_param_p->wb_param));
        #endif
        
        		 // loud speaker mode DMNR
             L1SP_SetLSpkDMNRPara((kal_int16 *)(&dm_param_p->lspk_nb_param));
        #ifdef __AMRWB_LINK_SUPPORT__
             L1SP_SetLSpkWbDMNRPara((kal_int16 *)(&dm_param_p->lspk_wb_param));
        #endif     
            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
            }
            break;
         }
    #endif

        case NVRAM_EF_AUDIO_PARAM_LID:

            /*set to L1SP directly*/
            L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_PARAM,(kal_uint8*) pdu_ptr, parm_ptr->length);

            nvram_param_p = (audio_param_struct*)pdu_ptr;

            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
                /* Other param will be set once when bootup, no need to keep in global context */
                L1SP_LoadCommonSpeechPara(nvram_param_p->speech_common_para);
                Media_SetMelodyFilter(MELODY_FIR_COEFF_NUM, nvram_param_p->Melody_FIR_Coeff_Tbl);
                aud_set_aud_path_volume(aud_context_p->audio_mode);

                /* Set compensation filter to driver */
                aud_send_startup_cnf(MED_RES_OK);
                med_context_p->nvram_state = MED_POWERON_READING_NVRAM_FINISH;
            }
            else if(med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
            {
                aud_get_audio_param_from_nvram_rsp((void*)nvram_param_p);
            }
            else
            {
                ASSERT(0);
            }
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_nvram_write_data_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle nvram write data confirm.
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_nvram_write_data_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_write_cnf_struct *parm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parm_ptr = (nvram_write_cnf_struct*) local_para_ptr;

    /* MED_FUNC_ENTRY(MED_NVRAM_WRITE_DATA_CNF_HDLR) */

    switch (parm_ptr->file_idx)
    {
        case NVRAM_EF_CUST_ACOUSTIC_DATA_LID:
            if (!aud_context_p->no_cnf)
            {
                aud_send_set_audio_profile_cnf(MED_RES_OK);
            }
            aud_context_p->no_cnf = KAL_FALSE;
            break;
        case NVRAM_EF_AUDIO_PARAM_LID:
            aud_send_set_audio_param_cnf(MED_RES_OK);
            break;
    #ifdef __AMRWB_LINK_SUPPORT__
        case NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID:
            aud_send_set_audio_wb_input_fir_cnf(MED_RES_OK);
            break;
        case NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_LID:
            aud_send_set_audio_wb_output_fir_cnf(MED_RES_OK);
            break;
        case NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_LID:
            aud_send_set_audio_wb_mode_cnf(MED_RES_OK);
            break;
    #endif
        default:
            break;
    }

}

/*****************************************************************************
 * FUNCTION
 *  med_startup_hdlr
 * DESCRIPTION
 *  This function is handle startup procedure of media task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_startup_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    med_context_p->event_scheduler_ptr = evshed_create("MED base timer", MOD_MED, 0, 0 );

    aud_startup_hdlr(ilm_ptr);

    /* start to read nvram data for media task */
    aud_startup_read_nvram_data();

}

#endif   // #if !defined(MED_NOT_PRESENT)

#if !defined(MED_NOT_PRESENT)
extern void l1audio_console_handler(kal_char *string); 
#endif // 
/*****************************************************************************
 * FUNCTION
 *  med_main
 * DESCRIPTION
 *  This function is main message dispatching function of media task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(MED_NOT_PRESENT)
    if (ilm_ptr->msg_id == MSG_ID_TIMER_EXPIRY)
    {
        med_timer_expiry_hdlr(ilm_ptr);
    }
    else if (ilm_ptr->msg_id == MSG_ID_MED_STARTUP_REQ)
    {
        med_startup_hdlr(ilm_ptr);
    }
    else if (ilm_ptr->msg_id == MSG_ID_NVRAM_READ_CNF)
    {
        med_nvram_read_data_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
    }
    else if (ilm_ptr->msg_id == MSG_ID_NVRAM_WRITE_CNF)
    {
        med_nvram_write_data_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
    }
    else if ( (ilm_ptr->msg_id >= MSG_ID_MED_CODE_BEGIN) && (ilm_ptr->msg_id <= MSG_ID_MED_CODE_TAIL) )
    {
        aud_main(ilm_ptr);
    }
    else 
#endif    
    if (ilm_ptr->msg_id == MSG_ID_TST_INJECT_STRING) {
	 	tst_module_string_inject_struct *tstInj = (tst_module_string_inject_struct *)ilm_ptr->local_para_ptr;
		if(tstInj->index == 99 ) {
			l1audio_console_handler(tstInj->string);
		} else {
			kal_prompt_trace(MOD_MED, "unused inject string index = %d ", tstInj->index);
		}			
	 }

#if !defined(L1_NOT_PRESENT) && !defined(__UE_SIMULATOR__)
  #if defined( __DATA_CARD_SPEECH__ )
    if ( ( (ilm_ptr->msg_id >= CMUX_MSG_CODE_BEGIN) && (ilm_ptr->msg_id <= MSG_ID_CMUX_CODE_TAIL) )
    	   || ( (ilm_ptr->msg_id >= MSG_ID_AUDIO_MSG_CODE_BEGIN) && (ilm_ptr->msg_id <= MSG_ID_AUDIO_MSG_CODE_TAIL) )
    	   || ( (ilm_ptr->msg_id >= DRIVER_MSG_CODE_BEGIN) && (ilm_ptr->msg_id <= MSG_ID_DRIVER_CODE_TAIL) ) )
    {
        SP_Strm_Audl_Handler(ilm_ptr);
    }
  #endif
  #if defined( __SMART_PHONE_MODEM__ )
    if (ilm_ptr->msg_id == MSG_ID_AUDIO_A2M_CCCI)
    {
        SpcIO_Msg_Handler_inAudL(ilm_ptr);
    } else if (ilm_ptr->msg_id == MSG_ID_MEDIA_AUD_MUTE_REQ) {
    	 /*----------------------------------------------------------------*/
	    /* Local Variables                                                */
	    /*----------------------------------------------------------------*/
	    kal_uint16 cnf_msg_id;
	    void *cnf_p = NULL;

	    media_aud_mute_req_struct *req_p;

	    /*----------------------------------------------------------------*/
	    /* Code Body                                                      */
	    /*----------------------------------------------------------------*/
	    req_p = (media_aud_mute_req_struct*) ilm_ptr->local_para_ptr;

	    switch (req_p->device)
	    {
	        case AUDIO_DEVICE_MICROPHONE:
	            /* call L1AUD to set microphone mute */
	            L1SP_MuteMicrophone(req_p->mute);
	            // aud_context_p->audio_mute = req_p->mute;
	            break;
	        default:
	            break;
	    }

	    cnf_p = (media_aud_mute_cnf_struct*) construct_local_para(sizeof(media_aud_mute_cnf_struct), TD_CTRL);

	    cnf_msg_id = MSG_ID_MEDIA_AUD_MUTE_CNF;

	    // aud_send_ilm(ilm_ptr->src_mod_id, cnf_msg_id, cnf_p, NULL);
	    msg_send6(kal_get_active_module_id(),ilm_ptr->src_mod_id,AUDIO_SAP,cnf_msg_id,cnf_p, NULL);
    }
  #endif
#endif

    if ((ilm_ptr->msg_id > MSG_ID_AUDIO_M2M_BEGIN) && (ilm_ptr->msg_id < MSG_ID_AUDIO_M2M_TAIL))
    {
        #ifdef __MTK_TARGET__
        SP_M2M_Handler(ilm_ptr);
        #endif //#ifdef __MTK_TARGET__
    }
#if defined(__VOLTE_SUPPORT__)
    if ( ilm_ptr->msg_id == MSG_ID_MEDIA_IN_PROC_CALL_REQ )
    {
        #ifdef __MTK_TARGET__
        kal_prompt_trace(MOD_L1SP, "[TONEDEBUG]MSG_ID_MEDIA_IN_PROC_CALL_REQ1");
        aud_util_in_proc_call_req_hdlr(ilm_ptr);
        #endif //#ifdef __MTK_TARGET__
    }
#endif   
}


/*****************************************************************************
 * FUNCTION
 *  med_task_main
 * DESCRIPTION
 *  This function is main function of media task.
 * PARAMETERS
 *  task_entry_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if !defined(L1_NOT_PRESENT) && !defined(__UE_SIMULATOR__)
    SP_Drv_Init_Task();
#endif

    while (1)
    {
        msg_receive_extq(&current_ilm);
        
        kal_set_active_module_id(current_ilm.dest_mod_id);

        med_main((void*)&current_ilm);

        destroy_ilm(&current_ilm);
    }

}


/*****************************************************************************
 * FUNCTION
 *  med_init
 * DESCRIPTION
 *  This function is used to init media task.
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(MED_NOT_PRESENT)
    med_context_p->aud_mem_p = med_aud_mem;

    if (!aud_init())
    {
        return KAL_FALSE;
    }
#else //#if !defined(MED_NOT_PRESENT)
    #if defined(__MCU_DTMF_SUPPORT__) 
    med_context_p->aud_mem_p = med_aud_mem;
    #endif //#if defined(__MCU_DTMF_SUPPORT__) 
#endif //#if !defined(MED_NOT_PRESENT)

    if (!med_utility_init())
    {
        return KAL_FALSE;
    }

#if !defined(L1_NOT_PRESENT) && !defined(__UE_SIMULATOR__)
    if (!SP_Drv_Init_Bootup())
    {
        return KAL_FALSE;
    }
#endif

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  med_reset
 * DESCRIPTION
 *  This function is used to reset media task.
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  med_create
 * DESCRIPTION
 *  This function is used to create media task configuration info.
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct med_handler_info = 
    {
        med_task_main,  /* task entry function */
        med_init,       /* task initialization function */
        med_reset       /* task reset handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & med_handler_info;

    return KAL_TRUE;
}

