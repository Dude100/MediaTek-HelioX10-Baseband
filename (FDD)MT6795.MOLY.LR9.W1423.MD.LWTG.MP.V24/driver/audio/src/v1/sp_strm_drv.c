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
#include "drv_sap.h"
#include "audio_msgid.h"
#include "cmux_msgid.h"
#include "drv_msgid.h"

#include "dcl.h"
#include "audio_enum.h"
#include "cmux_struct.h" // For cmux_dlc_connect_ind_struct;
#include "l1sp_trc.h"
#include "sp_daca.h"

typedef struct spstrmcontrol SpStrmControl;
#define CMUX_SPEECH_CHANNEL 10
#define WB_FRAME_SIZE 320

typedef enum{   
   VIA_CMUX_MODE,
   VIA_USB_MODE
}DATA_CARD_MODE;

struct spstrmcontrol{
   kal_int16 ul_pcm[WB_FRAME_SIZE]; // fixed WB
   kal_int16 dl_pcm[WB_FRAME_SIZE]; // fixed WB
   kal_uint16 fc_aud_id;
   kal_bool              is_strmOn;
   kal_uint16 ul_sample_count;
   kal_bool  ul_ready;
   kal_bool  dl_ready;
   UART_PORT  port;
   DATA_CARD_MODE        mode;
   DCL_HANDLE cmux_handle;
   DCL_HANDLE            usb_handle;
};

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   void *para;
} sstrm_para_struct;

DCL_HANDLE     gUSB_HANDLE;
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
void spStrmCallback(kal_uint32 event, void *param)
{
   msg_send4(MOD_L1SP, MOD_MED, AUDIO_SAP, event);

}



/*in audio task*/
void daca_dl_hdlr(void){
     if(NULL == intSStrmControl){
        kal_brief_trace( TRACE_INFO, DACA_EXCEPTION, 7);   
        return; 
     }   
   
     kal_brief_trace( TRACE_INFO, DACA_ENTER_REQUEST_EXCHANGE_DL_DATA, intSStrmControl->is_strmOn, intSStrmControl->dl_ready);   
     
     if( intSStrmControl->dl_ready == KAL_TRUE )
        return;
#if 1
     ASSERT(DACA_GetFromSD( (uint16 *)intSStrmControl->dl_pcm ) == WB_FRAME_SIZE);
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

     spStrmCallback( MSG_ID_STRM_SPEECH_DL_DATA_NOTIFY, NULL );
     intSStrmControl->dl_ready = true;
}

void daca_ul_hdlr(void){	 
     if(NULL == intSStrmControl){
        kal_brief_trace( TRACE_INFO, DACA_EXCEPTION, 8);   
        return; 
     }        
      
     kal_brief_trace( TRACE_INFO, DACA_ENTER_REQUEST_EXCHANGE_UL_DATA, intSStrmControl->is_strmOn, intSStrmControl->ul_ready);   
     
     if( !intSStrmControl->ul_ready ){
     	  kal_brief_trace( TRACE_INFO, DACA_UL_HAS_NO_DATA);

        DACA_FillSE(0);
     }else{
     	  kal_brief_trace( TRACE_INFO, DACA_UL_HAS_DATA);

#if 1
        DACA_PutToSE( (uint16 *)intSStrmControl->ul_pcm );
#else
/* under construction !*/
/* under construction !*/
#endif
        intSStrmControl->ul_ready = KAL_FALSE;                    
     }
     spStrmCallback( MSG_ID_STRM_SPEECH_UL_DATA_REQUEST, NULL );
     kal_brief_trace( TRACE_INFO, DACA_LEAVE_REQUEST_EXCHANGE_UL_DATA);     
}

/*Run in L1SP_Speech_On, usually in MED_TASK*/
void spStrmOnHandler( void *data )
{
   if(NULL == intSStrmControl){
        kal_brief_trace( TRACE_INFO, DACA_EXCEPTION, 9);   
        return; 
   }     
   
   memset(intSStrmControl->dl_pcm, 0, sizeof(kal_int16) * WB_FRAME_SIZE);
   memset(intSStrmControl->ul_pcm, 0, sizeof(kal_int16) * WB_FRAME_SIZE);
   
   spStrmCallback( MSG_ID_SPEECH_ON_ACK, NULL );
   DACA_Start(daca_dl_hdlr, daca_ul_hdlr, DACA_APP_TYPE_ACTIVE_UL_DL_WB);
   intSStrmControl->is_strmOn = KAL_TRUE;
   kal_trace( TRACE_INFO,  DACA_ENTER_STRMONHANDLER);
}
/*Run in L1SP_Speech_Off, usually in MED_TASK*/
void spStrmOffHandler( void *data)
{ 
   if(NULL == intSStrmControl){
     kal_brief_trace( TRACE_INFO, DACA_EXCEPTION, 10);   
     return; 
   }              

   DACA_Stop(DACA_APP_TYPE_ACTIVE_UL_DL_WB);   
   spStrmCallback( MSG_ID_SPEECH_OFF_ACK, NULL );
   intSStrmControl->is_strmOn = KAL_FALSE;
   kal_trace( TRACE_INFO,  DACA_ENTER_STRMOFFHANDLER);
}

#ifdef __SPEECH_OVER_USB__
UART_PORT   SPEECH_PORT = uart_port_null;
#endif   

void SP_Strm_Init()
{
#if DATA_CARD_DISABLE_INTERNAL   
   return;   
#endif
#ifdef __SPEECH_OVER_USB__
   UART_CTRL_OPEN_T data;
   DCL_STATUS status;
   ASSERT(SPEECH_PORT != uart_port_null);
   gUSB_HANDLE = DclSerialPort_Open(SPEECH_PORT, 0);  
     
   kal_trace( TRACE_INFO, DACA_OPEN_PORT, VIA_USB_MODE, SPEECH_PORT);
   data.u4OwenrId = MOD_MED;
   status = DclSerialPort_Control(gUSB_HANDLE, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*)&data); // Notice!! Only when SIO_CMD_OPEN, USB task will send MSG_ID_UART_PLUGIN_IND to AUDL     	 
	ASSERT(STATUS_OK == status);   
#endif   

}

void SP_Strm_Enable( )
{
   UART_CTRL_OPEN_T data;
   DCL_STATUS status;

   ASSERT (intSStrmControl != NULL );  

   intSStrmControl->ul_ready = intSStrmControl->dl_ready = KAL_FALSE;
   intSStrmControl->ul_sample_count = 0;
   intSStrmControl->is_strmOn = KAL_FALSE;
#if !defined(SS_UNIT_TEST)   
   data.u4OwenrId = MOD_MED;
   switch(intSStrmControl->mode){
      case VIA_CMUX_MODE:
         status = DclSerialPort_Control(intSStrmControl->cmux_handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*)&data);   
         ASSERT(STATUS_OK == status);
         break;   
      case VIA_USB_MODE:
         //OpenPort in SP_Strm_Init which is invoked in reboot     
         break;               
   }        
   kal_trace( TRACE_INFO, DACA_STRM_ENABLE, intSStrmControl->mode);
#endif
   L1SP_Register_Strm_Handler( spStrmOnHandler, spStrmOffHandler, spStrmCallback );   
}

void SP_Strm_Disable( void )
{
   //FIXME: for phone call usage

#if !defined(SS_UNIT_TEST)
   UART_CTRL_CLOSE_T data;
   ASSERT (intSStrmControl != NULL );  
   data.u4OwenrId = MOD_MED;
   switch(intSStrmControl->mode){
      case VIA_CMUX_MODE:
         DclSerialPort_Control( intSStrmControl->cmux_handle, SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*)&data); 
         break;   
      case VIA_USB_MODE:
         //DclSerialPort_Control( intSStrmControl->usb_handle, SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*)&data);   //After PC hibernates, USB will send the driver "plugout".  If The driver closes connection with USB port, it causes the USB can't send "plugin" to the driver even if PC wakes up!! In this case, the driver stays without datacard mode. Any voice can be delivered to PC  
         break;               
   }           
   kal_trace( TRACE_INFO, DACA_STRM_DISABLE, intSStrmControl->mode);         
#endif

   free_ctrl_buffer(intSStrmControl);
   intSStrmControl = NULL;
   
   L1SP_UnRegister_Strm_Handler();
}



void SP_Strm_Audl_Handler( ilm_struct *ilm_ptr )
{
   #if DATA_CARD_DISABLE_INTERNAL   
   return;   
   #endif
   switch (ilm_ptr->msg_id) {
      case MSG_ID_CMUX_DLC_CONNECT_IND:
         {
            cmux_dlc_connect_ind_struct *local_para;
            kal_trace( TRACE_INFO, DACA_PLUGIN, VIA_CMUX_MODE);
            //ASSERT (NULL == intSStrmControl);              
            if (NULL != intSStrmControl){
               kal_trace( TRACE_INFO, DACA_EXCEPTION, 1);
               return;
            }
               
            intSStrmControl = (SpStrmControl *)get_ctrl_buffer(sizeof(SpStrmControl));               
            local_para = (cmux_dlc_connect_ind_struct *)ilm_ptr->local_para_ptr;            
            kal_trace( TRACE_INFO, DACA_OPEN_PORT, VIA_CMUX_MODE, local_para->port);
            
            intSStrmControl->cmux_handle = DclSerialPort_Open(local_para->port, 0); 
            intSStrmControl->mode = VIA_CMUX_MODE;        
            SP_Strm_Enable();
         }
         break;     
#ifdef __SPEECH_OVER_USB__             
      case MSG_ID_UART_PLUGIN_IND:
      	 kal_trace( TRACE_INFO, DACA_PLUGIN, VIA_USB_MODE);
         //ASSERT (NULL == intSStrmControl);              
         if (NULL != intSStrmControl){
            kal_trace( TRACE_INFO, DACA_EXCEPTION, 2);
            return;         
         }
         intSStrmControl = (SpStrmControl *)get_ctrl_buffer(sizeof(SpStrmControl));   
         
         intSStrmControl->usb_handle = gUSB_HANDLE;  
         intSStrmControl->mode = VIA_USB_MODE;
         SP_Strm_Enable();
         break;           
#endif                
      case MSG_ID_UART_PLUGOUT_IND:
         //ASSERT (intSStrmControl != NULL );  
         if( NULL == intSStrmControl){
            kal_trace( TRACE_INFO, DACA_EXCEPTION, 3);
            return;                   
         } 
         SP_Strm_Disable();
         
         break;
      case MSG_ID_SPEECH_ON_ACK:
      case MSG_ID_SPEECH_OFF_ACK:
      {
         UART_CTRL_CLR_BUFFER_T data;
         data.u4OwenrId = MOD_MED;
         
         //ASSERT (NULL == intSStrmControl);              
         if (NULL == intSStrmControl){
            kal_trace( TRACE_INFO, DACA_EXCEPTION, 4);
            return; 
         }
            
         switch(intSStrmControl->mode){
            case VIA_CMUX_MODE:
               DclSerialPort_Control( intSStrmControl->cmux_handle,SIO_CMD_CLR_RX_BUF, (DCL_CTRL_DATA_T*)&data);
               DclSerialPort_Control( intSStrmControl->cmux_handle,SIO_CMD_CLR_TX_BUF, (DCL_CTRL_DATA_T*)&data);     
               break;                
            case VIA_USB_MODE:
               DclSerialPort_Control( intSStrmControl->usb_handle,SIO_CMD_CLR_RX_BUF, (DCL_CTRL_DATA_T*)&data);
               DclSerialPort_Control( intSStrmControl->usb_handle,SIO_CMD_CLR_TX_BUF, (DCL_CTRL_DATA_T*)&data);       
               break;                              
         }          
         break;
      }
#if !defined(SS_UNIT_TEST)
      case MSG_ID_UART_READY_TO_READ_IND:
      case MSG_ID_STRM_SPEECH_UL_DATA_REQUEST:
      {
         UART_CTRL_GET_BYTES_T data;
         kal_uint8 status;
         
        // ASSERT (NULL == intSStrmControl);              
         if (NULL == intSStrmControl){
            kal_trace( TRACE_INFO, DACA_EXCEPTION, 5);
            return; 
         }
         kal_trace( TRACE_INFO,  DACA_ENTER_GETDATA1, intSStrmControl->is_strmOn, intSStrmControl->ul_ready);   
    
         if(!intSStrmControl->is_strmOn){
		         UART_CTRL_CLR_BUFFER_T data;
		         data.u4OwenrId = MOD_MED;         	
		         switch(intSStrmControl->mode){
		            case VIA_CMUX_MODE:
		               DclSerialPort_Control( intSStrmControl->cmux_handle,SIO_CMD_CLR_RX_BUF, (DCL_CTRL_DATA_T*)&data);
		               DclSerialPort_Control( intSStrmControl->cmux_handle,SIO_CMD_CLR_TX_BUF, (DCL_CTRL_DATA_T*)&data);     
		               break;                
		            case VIA_USB_MODE:
		               DclSerialPort_Control( intSStrmControl->usb_handle,SIO_CMD_CLR_RX_BUF, (DCL_CTRL_DATA_T*)&data);
		               DclSerialPort_Control( intSStrmControl->usb_handle,SIO_CMD_CLR_TX_BUF, (DCL_CTRL_DATA_T*)&data);       
		               break;                              
		         }               	
         }else{   
             if( intSStrmControl->ul_ready == KAL_TRUE )
                 return;
             kal_trace( TRACE_INFO,  DACA_ENTER_GETDATA2);
		         data.u4OwenrId = MOD_MED;
		         data.u2Length = WB_FRAME_SIZE * sizeof(kal_int16) - intSStrmControl->ul_sample_count;
		         data.puBuffaddr = (DCL_UINT8 *)intSStrmControl->ul_pcm + intSStrmControl->ul_sample_count;
		         data.pustatus = &status;

		         switch(intSStrmControl->mode){
		            case VIA_CMUX_MODE:
		               DclSerialPort_Control( intSStrmControl->cmux_handle,SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*)&data);
		               kal_trace( TRACE_INFO, DACA_GET_DATA, data.u2RetSize, VIA_CMUX_MODE, data.u2Length);        
		               break;                 
		            case VIA_USB_MODE:
		               DclSerialPort_Control( intSStrmControl->usb_handle,SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*)&data);
		               kal_trace( TRACE_INFO, DACA_GET_DATA, data.u2RetSize, VIA_USB_MODE, data.u2Length);          
		               break;                             
		         }                  
		         
		         intSStrmControl->ul_sample_count += data.u2RetSize;
		         if( intSStrmControl->ul_sample_count >= WB_FRAME_SIZE * sizeof(kal_int16) ){
		            intSStrmControl->ul_sample_count = 0;
                intSStrmControl->ul_ready = KAL_TRUE;

		            kal_trace( TRACE_INFO,  DACA_GET_SUFFICIENT_DATA);		
		         }else{
		         	  kal_trace( TRACE_INFO,  DACA_GET_INSUFFICIENT_DATA);	
		         }
		         kal_trace( TRACE_INFO,  DACA_LEAVE_GETDATA);
         }
         break;
      }
      case MSG_ID_UART_READY_TO_WRITE_IND:
      case MSG_ID_STRM_SPEECH_DL_DATA_NOTIFY:
      {
         UART_CTRL_PUT_BYTES_T data;
         
         //ASSERT (NULL == intSStrmControl);              
         if (NULL == intSStrmControl){
            kal_trace( TRACE_INFO, DACA_EXCEPTION, 6);
            return;          
         }
         kal_trace( TRACE_INFO,  DACA_ENTER_PUTDATA1, intSStrmControl->is_strmOn, intSStrmControl->dl_ready);   
         if( !intSStrmControl->dl_ready )
            return;             
         data.u4OwenrId = MOD_MED;
         data.u2Length = WB_FRAME_SIZE * sizeof(kal_int16);
         data.puBuffaddr = (DCL_UINT8 *)intSStrmControl->dl_pcm;

         switch(intSStrmControl->mode){
            case VIA_CMUX_MODE:
               DclSerialPort_Control( intSStrmControl->cmux_handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data );
               kal_trace( TRACE_INFO, DACA_PUT_DATA, data.u2RetSize, VIA_CMUX_MODE);            
               break;   
            case VIA_USB_MODE:
               DclSerialPort_Control( intSStrmControl->usb_handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data );
               kal_trace( TRACE_INFO, DACA_PUT_DATA, data.u2RetSize, VIA_USB_MODE);            
               break;               
         }
         intSStrmControl->dl_ready = false;
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
         kal_trace( TRACE_INFO, DACA_BUFFER_IDX, ss_buf_idx);
         break;
      }
#endif
      default:
         ASSERT(0);
   }
}

#endif //#if defined(__DATA_CARD_SPEECH__)

