#include "kal_public_api.h"
#include "reg_base.h"

#include "l1audio.h"
#include "am.h"
#include "audio_def.h"
#include "afe_def.h"
#include "media.h"
#include "sp_daca.h"
#include "sp_drv.h"
#include "sal_def.h"
#include "sal_exp.h"

#define DACA_STATE    0x4




static _DACA_EX_T dacaEx;

void Daca_hisrDlHdlr(void *param) 
{
   dacaEx.daca_dl_hdlr();   
}

void Daca_hisrUlHdlr(void *param) 
{
   dacaEx.daca_ul_hdlr();   
}

void DACA_Start(void (*daca_dl_hdlr)(void), void (*daca_ul_hdlr)(void), DACA_APP_TYPE app_type)
{
   uint32 I;
   //Sal_PCMEx_Config_t cfg_t;   

	//cfg_t.idle = false;//initialized;
   
   dacaEx.aud_daca_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( dacaEx.aud_daca_id ); 

   L1Audio_HookHisrHandler(DP_D2C_DACA_REQ_DL,(L1Audio_EventHandler)Daca_hisrDlHdlr, 0);
   L1Audio_HookHisrHandler(DP_D2C_DACA_REQ_UL,(L1Audio_EventHandler)Daca_hisrUlHdlr, 0);
   dacaEx.daca_dl_hdlr = daca_dl_hdlr; 
   dacaEx.daca_ul_hdlr = daca_ul_hdlr;     
        
   dacaEx.app_type = app_type;     
   
   if(app_type & DACA_IN_PHONE_CALL){
      dacaEx.am_type = AM_PCMEX_TYPE_DACA_DEDICATION;  
   }else{
      dacaEx.am_type = AM_PCMEX_TYPE_DACA_IDLE_WO_ENH;
   }
   
   if(app_type & DACA_USE_NB){
      dacaEx.frame_size = 160;//PCMNWAY_BAND_INFO_NB;
      // cfg_t.band      = SAL_PCM_NARROWBAND;
   }else{
      dacaEx.frame_size = 320;//PCMNWAY_BAND_INFO_WB;
      // cfg_t.band = SAL_PCM_WIDEBAND;
   }         

	
    /* the begining of configure the SAL */  
   if(app_type & DACA_USE_UL){
      SAL_PcmEx_SetStateUL(SAL_PCMEX_TYPE_DACA, SAL_PCMEX_ON);
   }
   
   if(app_type & DACA_USE_DL){
      SAL_PcmEx_SetStateDL(SAL_PCMEX_TYPE_DACA, SAL_PCMEX_ON);
   }  

	//cfg_t.swi  = SAL_PCMEX_SWITCH_ON;
	//cfg_t.type = SAL_PCMEX_TYPE_DACA;	
	//cfg_t.band = (app_type & DACA_USE_NB) ? SAL_PCM_NARROWBAND : SAL_PCM_WIDEBAND;
   
   AM_PCM_EX_On(dacaEx.am_type, (uint32)&dacaEx);   
   
   for(dacaEx.state = DACA_STATE, I = 0; ;I ++){
   	kal_bool is_ready = true;
   	if((dacaEx.app_type & DACA_USE_UL) && (!SAL_PcmEx_CheckStateUL(SAL_PCMEX_TYPE_DACA, SAL_PCMEX_RDY)))
			is_ready = false;
		if((dacaEx.app_type & DACA_USE_DL) && (!SAL_PcmEx_CheckStateDL(SAL_PCMEX_TYPE_DACA, SAL_PCMEX_RDY)))
			is_ready = false;
		
      if(is_ready)
         break;
      ASSERT(I < 22);  // wait 200ms  
      kal_sleep_task(2);
   }    
   /* the end of configure the SAL */ 
}

void DACA_Stop(DACA_APP_TYPE app_type)
{
	// Sal_PCMEx_Config_t cfg_t;

	// cfg_t.idle = false;//initialized

   ASSERT((dacaEx.app_type == app_type) && (dacaEx.state == DACA_STATE));   
  
    /* the begining of configure the SAL */  
   if(dacaEx.app_type & DACA_USE_UL){//either ready or off
   	ASSERT(SAL_PcmEx_CheckStateUL(SAL_PCMEX_TYPE_DACA, SAL_PCMEX_RDY));
   }else{
   	ASSERT(SAL_PcmEx_CheckStateUL(SAL_PCMEX_TYPE_DACA, SAL_PCMEX_OFF));
   }
   
   if(dacaEx.app_type & DACA_USE_DL){//either ready or off
		ASSERT(SAL_PcmEx_CheckStateDL(SAL_PCMEX_TYPE_DACA, SAL_PCMEX_RDY));
   }else{
		ASSERT(SAL_PcmEx_CheckStateDL(SAL_PCMEX_TYPE_DACA, SAL_PCMEX_OFF));
   }

	SAL_PcmEx_SetStateUL(SAL_PCMEX_TYPE_DACA, SAL_PCMEX_OFF);
	SAL_PcmEx_SetStateDL(SAL_PCMEX_TYPE_DACA, SAL_PCMEX_OFF);
	  
   // cfg_t.swi = SAL_PCMEX_SWITCH_OFF;
   // cfg_t.type = SAL_PCMEX_TYPE_DACA;
   AM_PCM_EX_Off(dacaEx.am_type, (uint32)&dacaEx);    
    /* the end of configure the SAL */  
    
   L1Audio_UnhookHisrHandler(DP_D2C_DACA_REQ_DL); 
   L1Audio_UnhookHisrHandler(DP_D2C_DACA_REQ_UL); 

   L1Audio_ClearFlag( dacaEx.aud_daca_id );
   L1Audio_FreeAudioID( dacaEx.aud_daca_id );
   
   dacaEx.daca_dl_hdlr   = dacaEx.daca_ul_hdlr = NULL;
   dacaEx.state          = 0; 
   dacaEx.app_type       = DACA_APP_TYPE_UNDEFINE; 
   dacaEx.am_type        = 0xFFFF;      
}


uint32 DACA_GetFromSD(uint16 *dl_buf)
{
   uint32 I; 
   uint32 fsize = dacaEx.frame_size;
	
	if(SP_IsSpeakerMute()){
		  memset(dl_buf, 0, fsize * sizeof(uint16));
	} else { 
      volatile int16* ptr = SAL_PcmEx_GetBuf(SAL_PCMEX_DACA_BUF_DL);
      int16 *out_buf = dl_buf;
   
      int32 gain = AM_DSP_GetSpeechDigitalGain();
      ASSERT(gain > 0 && gain <= 4096);    

      for( I = 0 ; I < fsize; I++ ){
         // tmp = *ptr++;
         //tmp = (tmp * gain) >> 12;
         //*out_buf++ = tmp;
         *out_buf++ = (*ptr++ * gain) >> 12;
      }
	}
   return fsize;
}

void DACA_PutToSE(const uint16 *ul_data)  
{
   uint32 I;   
	uint32 fsize = dacaEx.frame_size;
   volatile uint16* ptr = SAL_PcmEx_GetBuf(SAL_PCMEX_DACA_BUF_UL);
   for( I = fsize; I > 0; I-- )
      *ptr++ = *ul_data++;

}

void DACA_FillSE(uint16 value)
{
   uint32 I;
   uint32 fsize = dacaEx.frame_size;
   volatile uint16* ptr = SAL_PcmEx_GetBuf(SAL_PCMEX_DACA_BUF_UL);
   for( I = fsize; I > 0; I-- )
      *ptr++ = value;
}

