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
 *
 * Filename:
 * ---------
 * sp_strm_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Data card speech streaming driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined(__DATA_CARD_SPEECH__)
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "l1audio_trace.h" 
#include "l1audio.h"
#include "drv_msgid.h"
#include "audio_msgid.h"
#include "cmux_msgid.h"
#include "drv_msgid.h"

#include "dcl.h"
#include "exp_SphFasTypDef.h"
#include "fc_def.h"
#include "audio_enum.h"
#include "cmux_struct.h" // For cmux_dlc_connect_ind_struct;

typedef struct spstrmcontrol SpStrmControl;
#define CMUX_SPEECH_CHANNEL 10
#define WB_FRAME_SIZE 320
struct spstrmcontrol{
   kal_int16 ul_pcm[WB_FRAME_SIZE]; // fixed WB
   kal_int16 dl_pcm[WB_FRAME_SIZE]; // fixed WB
   kal_uint16 fc_aud_id;
   kal_uint16 ul_sample_count;
   kal_bool  ul_ready;
   UART_PORT  port;
   DCL_HANDLE cmux_handle;
};

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   void *para;
} sstrm_para_struct;


SpStrmControl *intSStrmControl = NULL;
kal_enhmutexid ss_enh_mutex  = NULL;

extern void L1SP_UnRegister_Strm_Handler( void );
extern void L1SP_Register_Strm_Handler( void (*onHandler)(void *hdl), void (*offHandler)(void *hdl), void (*hdl)(kal_uint32 event, void *param));

//#define SS_UNIT_TEST
#if defined(SS_UNIT_TEST)
#define SS_BUF_MASK 7
kal_uint16 ss_buf_idx = 0;
kal_uint16 SS_BUFF[8][WB_FRAME_SIZE];
#endif

/* send message to AUDL task*/
static void spStrmCallback(kal_uint32 event, void *param)
{
   msg_send4(MOD_L1SP, MOD_MED, AUDIO_SAP, event);
}

/*in audio task*/
static void spStrmMsgHandler(kal_uint16 msgOp, kal_uint32 msgData, void *userData)
{
   switch (msgOp) {
      case MSG_SAC2L1AUDIO_SPEECH_DATACARD_OPEN_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_DATACARD_CLOSE_ACK:
         L1Audio_FC_SetWait(KAL_FALSE);
         break;
      case MSG_SAC2L1AUDIO_SPEECH_DATACARD_REQUEST_EXCHANGE_UL_DATA:
      {
         SAS_DataCard_RequestWriteUlData_t *ul_data;
         ul_data = (SAS_DataCard_RequestWriteUlData_t *)msgData;
         if( !intSStrmControl->ul_ready )
            memset( ul_data->pucInputUlBufPtr, 0, sizeof(kal_int16) * WB_FRAME_SIZE );
         else{
            memcpy( ul_data->pucInputUlBufPtr, intSStrmControl->ul_pcm, sizeof(kal_int16) * WB_FRAME_SIZE );

            intSStrmControl->ul_ready = KAL_FALSE;
            spStrmCallback( MSG_ID_STRM_SPEECH_UL_DATA_REQUEST, NULL );
         }
         ul_data->u4Len = sizeof(kal_int16) * WB_FRAME_SIZE ;
         L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_DATACARD_REQUEST_EXCHANGE_UL_DATA_ACK, intSStrmControl->fc_aud_id, 0);
         break;
      }
      case MSG_SAC2L1AUDIO_SPEECH_DATACARD_REQUEST_EXCHANGE_DL_DATA:
      {
         SAS_DataCard_RequestReadDlData_t *dl_data;
         dl_data = (SAS_DataCard_RequestReadDlData_t *)msgData;
         ASSERT( dl_data->u4Len == sizeof(kal_int16) * WB_FRAME_SIZE );

         memcpy( intSStrmControl->dl_pcm, dl_data->pucOutputDlBufPtr, sizeof(kal_int16) * WB_FRAME_SIZE );

         L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_DATACARD_REQUEST_EXCHANGE_DL_DATA_ACK, intSStrmControl->fc_aud_id, 0);
         spStrmCallback( MSG_ID_STRM_SPEECH_DL_DATA_NOTIFY, NULL );
         break;
      }
      default:
         ASSERT(0);
   }
}

/*Run in L1SP_Speech_On, usually in MED_TASK*/
static void spStrmOnHandler( void *data )
{
   if (intSStrmControl != NULL ){
      memset(intSStrmControl->dl_pcm, 0, sizeof(kal_int16) * WB_FRAME_SIZE);
      memset(intSStrmControl->ul_pcm, 0, sizeof(kal_int16) * WB_FRAME_SIZE);
   }
   spStrmCallback( MSG_ID_SPEECH_ON_ACK, NULL );
   intSStrmControl->fc_aud_id = L1Audio_FC_HookHandler( 0, spStrmMsgHandler, 1, 0 );
   L1Audio_PutMessageAndWait( MSG_L1AUDIO2FAS_SPEECH_DATACARD_OPEN, intSStrmControl->fc_aud_id, NULL, KAL_TRUE );
}
/*Run in L1SP_Speech_Off, usually in MED_TASK*/
static void spStrmOffHandler( void *data)
{
   L1Audio_PutMessageAndWait( MSG_L1AUDIO2FAS_SPEECH_DATACARD_CLOSE, intSStrmControl->fc_aud_id, NULL, KAL_TRUE );
   L1Audio_FC_UnHookHandler(intSStrmControl->fc_aud_id, 1);
   spStrmCallback( MSG_ID_SPEECH_OFF_ACK, NULL );
}

void SP_Strm_Enable( ilm_struct *ilm_ptr )
{
   UART_CTRL_OPEN_T data;
   DCL_STATUS status;
   cmux_dlc_connect_ind_struct *local_para;
   
   if (intSStrmControl != NULL )
      return;
   local_para = (cmux_dlc_connect_ind_struct *)ilm_ptr->local_para_ptr;
   
   if( ss_enh_mutex == NULL) // no delete mutex
      ss_enh_mutex = kal_create_enh_mutex( "SP_STRM_ENH_MUTEX" );
   intSStrmControl = (SpStrmControl *)get_ctrl_buffer(sizeof(SpStrmControl));
   intSStrmControl->ul_ready = KAL_FALSE;
   intSStrmControl->ul_sample_count = 0;
   intSStrmControl->port = local_para->port;
   kal_prompt_trace(MOD_L1SP, "SS port %d", intSStrmControl->port);
#if !defined(SS_UNIT_TEST)   
   data.u4OwenrId = MOD_MED;
   intSStrmControl->cmux_handle = DclSerialPort_Open(intSStrmControl->port, 0);
   status = DclSerialPort_Control(intSStrmControl->cmux_handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*)&data);
   ASSERT(STATUS_OK == status);
#endif
   L1SP_Register_Strm_Handler( spStrmOnHandler, spStrmOffHandler, spStrmCallback );
}

void SP_Strm_Disable( void )
{
#if !defined(SS_UNIT_TEST)
   UART_CTRL_CLOSE_T data;
   data.u4OwenrId = MOD_MED;
   DclSerialPort_Control( intSStrmControl->cmux_handle, SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*)&data);
#endif
   free_ctrl_buffer(intSStrmControl);
   intSStrmControl = NULL;
   L1SP_UnRegister_Strm_Handler();
}

void SP_Strm_Audl_Handler( ilm_struct *ilm_ptr )
{
   switch (ilm_ptr->msg_id) {
      case MSG_ID_CMUX_DLC_CONNECT_IND:
         SP_Strm_Enable(ilm_ptr);
         break;
      case MSG_ID_UART_PLUGOUT_IND:
         SP_Strm_Disable();
         break;
      case MSG_ID_SPEECH_ON_ACK:
      case MSG_ID_SPEECH_OFF_ACK:
      {
         UART_CTRL_CLR_BUFFER_T data;
         data.u4OwenrId = MOD_MED;
         DclSerialPort_Control( intSStrmControl->cmux_handle,SIO_CMD_CLR_RX_BUF, (DCL_CTRL_DATA_T*)&data);
         DclSerialPort_Control( intSStrmControl->cmux_handle,SIO_CMD_CLR_TX_BUF, (DCL_CTRL_DATA_T*)&data);
         break;
      }
#if !defined(SS_UNIT_TEST)
      case MSG_ID_UART_READY_TO_READ_IND:
      case MSG_ID_STRM_SPEECH_UL_DATA_REQUEST:
      {
         UART_CTRL_GET_BYTES_T data;
         kal_uint8 status;

         if( intSStrmControl->ul_ready == KAL_TRUE )
            return;
         data.u4OwenrId = MOD_MED;
         data.u2Length = WB_FRAME_SIZE * sizeof(kal_int16) - intSStrmControl->ul_sample_count;
         data.puBuffaddr = (DCL_UINT8 *)intSStrmControl->ul_pcm + intSStrmControl->ul_sample_count;
         data.pustatus = &status;
         DclSerialPort_Control( intSStrmControl->cmux_handle,SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*)&data);
         kal_prompt_trace(MOD_L1SP,"Audl Get %d Bytes from CMUX, ori req %d", data.u2RetSize, data.u2Length);
         intSStrmControl->ul_sample_count += data.u2RetSize;
         if( intSStrmControl->ul_sample_count >= WB_FRAME_SIZE * sizeof(kal_int16) )
         {
            intSStrmControl->ul_sample_count = 0;
            intSStrmControl->ul_ready = KAL_TRUE;
         }
         break;
      }
      case MSG_ID_UART_READY_TO_WRITE_IND:
      case MSG_ID_STRM_SPEECH_DL_DATA_NOTIFY:
      {
         UART_CTRL_PUT_BYTES_T data;
         
         data.u4OwenrId = MOD_MED;
         data.u2Length = WB_FRAME_SIZE * sizeof(kal_int16);
         data.puBuffaddr = (DCL_UINT8 *)intSStrmControl->dl_pcm;
         DclSerialPort_Control( intSStrmControl->cmux_handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data );
         kal_prompt_trace(MOD_L1SP,"Audl Put %d Bytes to CMUX", data.u2RetSize);
         break;
      }
#else
      case MSG_ID_STRM_SPEECH_UL_DATA_REQUEST:
      {
         break;
      }
      
      case MSG_ID_STRM_SPEECH_DL_DATA_NOTIFY:
      {
         //loopback from DL to UL directly.
         memcpy(SS_BUFF[ss_buf_idx & SS_BUF_MASK], intSStrmControl->dl_pcm, WB_FRAME_SIZE * sizeof(kal_int16));
         memcpy(intSStrmControl->ul_pcm, SS_BUFF[(ss_buf_idx-7) & SS_BUF_MASK] , WB_FRAME_SIZE * sizeof(kal_int16));
         ss_buf_idx++;
         kal_prompt_trace(MOD_L1SP, "ss_buf_idx", ss_buf_idx);
         break;
      }
#endif
      default:
         ASSERT(0);
   }
}

#endif //#if defined(__DATA_CARD_SPEECH__)
