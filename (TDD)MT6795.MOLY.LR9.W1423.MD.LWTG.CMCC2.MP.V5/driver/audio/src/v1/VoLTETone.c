
#include "kal_public_api.h"
#include "kal_general_types.h"

#include "kal_trace.h"
#include "l1sp_trc.h"

#include "l1audio.h"
#include "drv_sap.h"
#include "speech_def.h"
#include "bgSnd.h"
//#include "afe_def.h" // for output device setting
//#include "sp_drv.h"



#include "audio_msgid.h"
#include "sp_drv.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
   
typedef struct{
   uint32 id;   
   bool   is_used;   
}VOLTE_TONE_T;
VOLTE_TONE_T volte_tone;

uint32 VolteToneGetID()
{
   return(volte_tone.id);
}

void VolteToneSetID(uint32 u32val)
{
   volte_tone.id = u32val;
}

bool VolteToneGetUsed()
{
   return(volte_tone.is_used);
}

void VolteToneSetUsed(bool bval)
{
   volte_tone.is_used = bval;
}

void SP4G_PSR_Tone_init()
{
   
}
//tone
void SP4G_PSR_DL_Tone_Play(const L1SP_Tones *pToneList)
{
   ilm_PSR_DL_TONE_t *local_para;

   kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_DL_Tone_Play] Enter"); 

   //TONE_Play(pToneList, DSP_TONE);
   local_para = (ilm_PSR_DL_TONE_t *) construct_local_para( sizeof(ilm_PSR_DL_TONE_t), TD_CTRL/*TD_RESET*/ );
   local_para->pToneList = pToneList;
   msg_send6(MOD_LTECSR, MOD_MED, AUDIO_SAP, MSG_ID_AUDIO_M2M_VOLTE_DL_TONE_PLAY, (local_para_struct *)local_para, NULL);

   kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_DL_Tone_Play] Leave"); 
}

void SP4G_PSR_DL_Tone_Stop( void )
{
   kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_DL_Tone_Stop] Enter");    
   //TONE_Stop(DSP_TONE);
   msg_send6(MOD_LTECSR, MOD_MED, AUDIO_SAP, MSG_ID_AUDIO_M2M_VOLTE_DL_TONE_STOP, NULL, NULL);
   kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_DL_Tone_Stop] Leave");    
}
//KT
void SP4G_PSR_DL_KT_Play(kal_int16 freq1, kal_int16 freq2, kal_int16 duration)
{ 
   ilm_PSR_DL_KT_t *local_para;

   kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_DL_KT_Play] Enter"); 

   //KT_Play(freq1, freq2, duration, DSP_TONE);
   local_para = (ilm_PSR_DL_KT_t *) construct_local_para( sizeof(ilm_PSR_DL_KT_t), TD_CTRL/*TD_RESET*/ );
   local_para->freq1    = freq1;
   local_para->freq2    = freq2;
   local_para->duration = duration;
   msg_send6(MOD_LTECSR, MOD_MED, AUDIO_SAP, MSG_ID_AUDIO_M2M_VOLTE_DL_KT_PLAY, (local_para_struct *)local_para, NULL);

   kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_DL_KT_Play] Leave"); 
}

void SP4G_PSR_DL_KT_Stop( void )
{
   kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_DL_KT_Stop] Enter");    
   //KT_Stop(DSP_TONE);
   msg_send6(MOD_LTECSR, MOD_MED, AUDIO_SAP, MSG_ID_AUDIO_M2M_VOLTE_DL_KT_STOP, NULL, NULL);
   kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_DL_KT_Stop] Leave");    
}

void volte_Tone_bgSnd_closeHandler(void);//BGSND HISR to MED  ToDO
void volte_BGSND_ULHdr(void);
//TONE
void SP4G_PSR_UL_Tone_Play(const L1SP_Tones *pToneList )
{ 
   ilm_PSR_DL_TONE_t *local_para;

   kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_UL_Tone_Play] Enter"); 
   /*if( !volte_tone.is_used ){    
      TONE_Play(pToneList, MCU_TONE);
      volte_tone.id = EXT_BGSND_Start(volte_Tone_bgSnd_closeHandler, NULL, volte_BGSND_ULHdr, 7, 7);
      volte_tone.is_used = true;      
   }else{
      kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_UL_Tone_Play] Skip");       
   }*/
   local_para = (ilm_PSR_DL_TONE_t *) construct_local_para( sizeof(ilm_PSR_DL_TONE_t), TD_CTRL/*TD_RESET*/ );
   local_para->pToneList = pToneList;
   msg_send6(MOD_LTECSR, MOD_MED, AUDIO_SAP, MSG_ID_AUDIO_M2M_VOLTE_UL_TONE_PLAY, (local_para_struct *)local_para, NULL);

   kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_UL_Tone_Play] Leave");     
}

void SP4G_PSR_UL_Tone_Stop( void )
{   
   kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_UL_Tone_Stop] Enter");   
   /*if( volte_tone.is_used ){  
      EXT_BGSND_Flush(volte_tone.id); 
      TONE_Stop(MCU_TONE);      
   }else{
      kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_UL_Tone_Stop] Skip");        
   }*/
   msg_send6(MOD_LTECSR, MOD_MED, AUDIO_SAP, MSG_ID_AUDIO_M2M_VOLTE_UL_TONE_STOP, NULL, NULL);
   kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_UL_Tone_Stop] Leave");       
}

void volte_Tone_bgSnd_closeHandler(void)//BGSND HISR to MED  ToDO
{
   kal_prompt_trace(MOD_L1SP, "[volte_bgSnd_closeHandler] Enter");    
   ASSERT( volte_tone.is_used );
	msg_send4(MOD_L1SP, MOD_MED, AUDIO_SAP, MSG_ID_AUDIO_M2M_VOLTE_TONE_BGSND_CLOSE);
   kal_prompt_trace(MOD_L1SP, "[volte_bgSnd_closeHandler] Leave");  	
}

void volte_Tone_BgSndClose(void)//trigger by MED
{
   kal_prompt_trace(MOD_L1SP, "[volte_BgSndClose] Enter");    
   ASSERT( volte_tone.is_used );
	EXT_BGSND_Close(volte_tone.id);	
	volte_tone.is_used = false;
   kal_prompt_trace(MOD_L1SP, "[volte_BgSndClose] Leave"); 	
}

//#############################################
//KT
void volte_KT_bgSnd_closeHandler(void);//BGSND HISR to MED  ToDO
void SP4G_PSR_UL_KT_Play(kal_int16 freq1, kal_int16 freq2, kal_int16 duration)
{ 
   ilm_PSR_DL_KT_t *local_para;

   kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_UL_KT_Play] Enter"); 

   /*if( !volte_tone.is_used ){    
      KT_Play(freq1, freq2, duration, MCU_TONE);
      volte_tone.id = EXT_BGSND_Start(volte_KT_bgSnd_closeHandler, NULL, volte_BGSND_ULHdr, 7, 7);
      volte_tone.is_used = true;
   }else{
      kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_UL_KT_Play] Skip");       
   }*/
   local_para = (ilm_PSR_DL_KT_t *) construct_local_para( sizeof(ilm_PSR_DL_KT_t), TD_CTRL/*TD_RESET*/ );
   local_para->freq1    = freq1;
   local_para->freq2    = freq2;
   local_para->duration = duration;
   msg_send6(MOD_LTECSR, MOD_MED, AUDIO_SAP, MSG_ID_AUDIO_M2M_VOLTE_UL_KT_PLAY, (local_para_struct *)local_para, NULL);

   kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_UL_KT_Play] Leave");     
}

void SP4G_PSR_UL_KT_Stop( void )
{   
   kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_UL_KT_Stop] Enter");   
   /*if( volte_tone.is_used ){ 
      EXT_BGSND_Flush(volte_tone.id);  
      KT_Stop(MCU_TONE);     
   }else{
      kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_UL_KT_Stop] Skip");        
   }*/
   msg_send6(MOD_LTECSR, MOD_MED, AUDIO_SAP, MSG_ID_AUDIO_M2M_VOLTE_UL_KT_STOP, NULL, NULL);
   kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_UL_KT_Stop] Leave");       
}

void volte_KT_bgSnd_closeHandler(void)//BGSND HISR to MED  ToDO
{
   kal_prompt_trace(MOD_L1SP, "[volte_bgSnd_closeHandler] Enter");    
   ASSERT( volte_tone.is_used );
	msg_send4(MOD_L1SP, MOD_MED, AUDIO_SAP, MSG_ID_AUDIO_M2M_VOLTE_KT_BGSND_CLOSE);
   kal_prompt_trace(MOD_L1SP, "[volte_bgSnd_closeHandler] Leave");  	
}

void volte_KT_BgSndClose(void)//trigger by MED
{
   kal_prompt_trace(MOD_L1SP, "[volte_BgSndClose] Enter");    
   ASSERT( volte_tone.is_used );
	EXT_BGSND_Close(volte_tone.id);
	volte_tone.is_used = false;
   kal_prompt_trace(MOD_L1SP, "[volte_BgSndClose] Leave"); 	
}

void volte_BGSND_ULHdr(void)
{
   int KK = 0;
	kal_uint32 uToneCnt, I;
   kal_int16 *pTone;
   kal_uint32 uRemains = 320*2;
   
   kal_prompt_trace(MOD_L1SP, "[volte_BGSND_ULHdr] Enter");  
   
//   if(!DTMF_MCU_IsPlaying()){
//      EXT_BGSND_Flush(volte_tone.id); 
//      //return;
//   }
   
   
   if(DTMF_MCU_IsPlaying()){
         
      //while(uRemains)//due to no place to do this , so put it here
      {
         KK++;
         DTMF_MCU_GetReadBuffer(&pTone, &uToneCnt);
         
         uRemains = EXT_BGSND_GetFreeSpace(volte_tone.id, BGSND_UL_PROCESS);
         
         kal_prompt_trace(MOD_L1SP, "[volte_BGSND_ULHdr]  ToneCnt %d Remains %d", uToneCnt, uRemains);
         if(uToneCnt > uRemains)
         {
            uToneCnt = uRemains;
         }
         
         if(uToneCnt){
            EXT_BGSND_WriteSrcBuffer(volte_tone.id, pTone, (kal_int32) uToneCnt, BGSND_UL_PROCESS);         
            //EXT_BGSND_WriteSrcBuffer(volte_tone.id, pTone, (kal_int32) uToneCnt, BGSND_DL_PROCESS);//Temp, To DO
         }
        
         DTMF_MCU_ReadDataDone(uToneCnt);
         //uRemains -= uToneCnt;
         //if(KK > 2)
         //   break;
      }	
      kal_prompt_trace(MOD_L1SP, "[volte_BGSND_ULHdr] we still need %d samples", uRemains);
            
      //every HISR, add data into a big pipe.
      kal_prompt_trace(MOD_L1SP, "[volte_BGSND_ULHdr] EXT_BGSND_WriteExtBuffer ");
      EXT_BGSND_WriteExtBuffer(volte_tone.id, 1, BGSND_UL_PROCESS);
      //EXT_BGSND_WriteExtBuffer(volte_tone.id, 1, BGSND_DL_PROCESS); //Temp, To DO
   }else{
      if(volte_tone.is_used){
         kal_prompt_trace(MOD_L1SP, "[volte_BGSND_ULHdr] No EXT_BGSND_WriteExtBuffer ");
         if(EXT_BGSND_GetDataCount(volte_tone.id, BGSND_UL_PROCESS) > 0)
         {
            kal_prompt_trace(MOD_L1SP, "[volte_BGSND_ULHdr] EXT_BGSND_WriteExtBuffer last data ");
            EXT_BGSND_WriteExtBuffer(volte_tone.id, 1, BGSND_UL_PROCESS);
         }
         EXT_BGSND_Flush(volte_tone.id); 
      }else{
         kal_prompt_trace(MOD_L1SP, "[volte_BGSND_ULHdr] Should assert ");
      }
   }
   
   {
	   //int bLen = MIN( EXT_BGSND_GetFreeSpace(volte_tone.id, BGSND_DL_PROCESS), EXT_BGSND_GetFreeSpace(volte_tone.id, BGSND_UL_PROCESS));
	   int bLen = EXT_BGSND_GetFreeSpace(volte_tone.id, BGSND_UL_PROCESS);
		if( bLen >= 1000 ) {
			DTMF_MCU_DataRequestCallback();
		}
	}   
	
   kal_prompt_trace(MOD_L1SP, "[volte_BGSND_ULHdr] Leave");  	
}
