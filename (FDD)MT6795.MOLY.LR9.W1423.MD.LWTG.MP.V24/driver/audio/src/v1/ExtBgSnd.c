#include "kal_public_api.h"
#include "kal_general_types.h"

#include "kal_trace.h"
#include "l1sp_trc.h"

#include "l1audio.h"
#include "am.h"
//#include "speech_def.h"
//#include "afe_def.h" // for output device setting
//#include "sp_drv.h"

#include "sal_exp.h"
#include "bgSnd.h"

#if !(defined(MT6280) || defined(MT6589))
#define DSP_BGS_UP_DOWN_INT_SEPERATE
#endif


#define BGSND_BUFFER_LEN_NB              (160) //unit is sample (16bit)
#define BGSND_BUFFER_LEN_WB              (320) //unit is sample (16bit)

#define MAX_NUM_BGSND_PROCESS (2)


//================= DSP BGSND INTERFACE ====================

typedef enum {
	DSP_BGSND_STATE_IDLE = 0,
	DSP_BGSND_STATE_RUN, 
	DSP_BGSND_STATE_STOPPING,
}DSP_BGSND_STATE_TYPE;

typedef struct{
	DSP_BGSND_STATE_TYPE   state;
		                    
	bool                   fSph[MAX_NUM_BGSND_PROCESS];
	uint16                 gain[MAX_NUM_BGSND_PROCESS];
		                    
   void                   (*Ext_Hisr[MAX_NUM_BGSND_PROCESS])(void);
}DSP_BKGSND_T; 

DSP_BKGSND_T DSP_BGSnd;

//================= Extended BGSND INTERFACE ====================
#define MAX_SIZE_EXT_BGSND_SRC (2)     // AP bkgsnd + VoLTE UL bkgsnd
#define EXT_BGSND_SRC_BUF_SIZE ((BGSND_BUFFER_LEN_WB) * 10) //buffering 10 frames
#define EXT_BGSND_BUF_PTR_DIFF (2)

#define MAX_LEVEL_EXT_BGSND_GAIN (7)  

typedef struct{
   EXT_SRC_STATE_TYPE     state[MAX_NUM_BGSND_PROCESS];
   void       (*offHdr)();//(int id);                     //TODO Trigger MED to close DSP bgsnd
   void       (*Hdr[MAX_NUM_BGSND_PROCESS])(void); // under HISR
   uint16     dspLastSample[MAX_NUM_BGSND_PROCESS];
   
   uint32     len_WriteSrcBuffer_this_time;
   //event handling
   //void       (*EventHandler)(void); 
   //void       *event_data;
   
   //gain handling  
	bool       fSph[MAX_NUM_BGSND_PROCESS];  
	uint16     gain[MAX_NUM_BGSND_PROCESS];  
   
   //buffer handling
   uint32     bufSize[MAX_NUM_BGSND_PROCESS], bufRead[MAX_NUM_BGSND_PROCESS], bufWrite[MAX_NUM_BGSND_PROCESS]; 
   uint16     buffer[MAX_NUM_BGSND_PROCESS][EXT_BGSND_SRC_BUF_SIZE]; 
   
}EXT_BGSND_SRC_T;

typedef struct{   
   bool                     is_used[MAX_SIZE_EXT_BGSND_SRC];
   bool                     is_send_event[MAX_SIZE_EXT_BGSND_SRC];
   EXT_BGSND_SRC_T          src[MAX_SIZE_EXT_BGSND_SRC];
   bool                     num_src_used;   
   	                      
   uint16                   buffer[MAX_NUM_BGSND_PROCESS][BGSND_BUFFER_LEN_WB];  //accumulate all sources multiplied by gains into this buffer
                            
	uint16                   aud_id;	
}EXT_BGSND_T;

static EXT_BGSND_T Ext_BGSnd;

/*
int has_ul = 0;
int has_dl = 0;
int ul_data[320], dl_data[320];*/

static void DSP_BGSND_INIT()
{	
   kal_prompt_trace(MOD_L1SP, "[DSP_BGSND_INIT] Enter");
	memset(&DSP_BGSnd, 0, sizeof(DSP_BKGSND_T));
	//has_ul = has_dl = 0;
	kal_prompt_trace(MOD_L1SP, "[DSP_BGSND_INIT] Leave");
}

static void DSP_BGSND_ConfigMixer(kal_bool bSPHFlag, kal_int8 SNDGain, BGSND_PROCESS_TYPE type)
{
   kal_prompt_trace(MOD_L1SP, "[DSP_BGSND_ConfigMixer] Enter");	
   kal_prompt_trace(MOD_L1SP, "[DSP_BGSND_ConfigMixer] BGSND_PROCESS_TYPE(0->DL, 1->UL)=%d flag:%d, gain:%d", type, bSPHFlag, SNDGain);
   
	ASSERT(SNDGain>=0 && SNDGain<=7);
	if( SNDGain == 0)
		DSP_BGSnd.gain[type] = 0;
	else {
		DSP_BGSnd.gain[type] = (kal_int16)(32767 >> (7 - SNDGain));
	}
	DSP_BGSnd.fSph[type] = bSPHFlag;
	kal_prompt_trace(MOD_L1SP, "[DSP_BGSND_ConfigMixer] Leave");
}

static void DSP_BGSND_UpdateMixer() // private
{
   kal_prompt_trace(MOD_L1SP, "[DSP_BGSND_UpdateMixer] Enter");	   
   if ( AM_IsSpeechOn() || AM_IsVoIPOn()) {
   	SAL_Bgsnd_Config(DSP_BGSnd.gain[BGSND_UL_PROCESS], DSP_BGSnd.gain[BGSND_DL_PROCESS], DSP_BGSnd.fSph[BGSND_UL_PROCESS], DSP_BGSnd.fSph[BGSND_DL_PROCESS]);
   } else {
      //When enable BT, spe_setSpeechMode() will do Speech Off and Speech On. This function may run between Off and ON, so do not use ASSERT().
      //ASSERT(false);
      SAL_Bgsnd_Config(DSP_BGSnd.gain[BGSND_UL_PROCESS], DSP_BGSnd.gain[BGSND_DL_PROCESS], 0, 0);
   }
   kal_prompt_trace(MOD_L1SP, "[DSP_BGSND_UpdateMixer] Leave");	   
}


void DSP_BGSND_Stop(void)
{
   kal_prompt_trace(MOD_L1SP, "[DSP_BGSND_Stop] Enter");
   DSP_BGSnd.state = DSP_BGSND_STATE_STOPPING;
	{  //turn off DSP BGSND	
   	uint32 I;
   	if(SAL_Bgsnd_IsRunning())
   		SAL_Bgsnd_SetFinal();
   	for ( I = 0; ; I++ ) {
   		if ( SAL_Bgsnd_IsIdle())	 /* DSP returns to idle state */
   			break;
   		ASSERT_REBOOT( I < 20 );
   		kal_sleep_task( 2 );
   	}
   	
   	AM_SND_PlaybackOff( true );
   }
   
#ifdef DSP_BGS_UP_DOWN_INT_SEPERATE
	L1Audio_UnhookHisrHandler(D2C_SOUND_EFFECT_INT_ID_DL);  
	L1Audio_UnhookHisrHandler(D2C_SOUND_EFFECT_INT_ID_UL);  
#else
	L1Audio_UnhookHisrHandler(D2C_SOUND_EFFECT_INT_ID_DL);
#endif 
   DSP_BGSnd.state = DSP_BGSND_STATE_IDLE;
   kal_prompt_trace(MOD_L1SP, "[DSP_BGSND_Stop] Leave");   
}

#if !defined(DSP_BGS_UP_DOWN_INT_SEPERATE)
void DSP_BGSND_Shared_Hisr_DL_UL(void * param)
{
   kal_prompt_trace(MOD_L1SP, "[DSP_BGSND_Shared_Hisr_DL_UL] Enter");   
   DSP_BGSND_Hisr(BGSND_UL_PROCESS);
   DSP_BGSND_Hisr(BGSND_DL_PROCESS);
   kal_prompt_trace(MOD_L1SP, "[DSP_BGSND_Shared_Hisr_DL_UL] Leave");  
}
#endif
/*
static kal_uint16 tempMicData[320]
	// = { 0x4808,0x85, 0x156,0, 0x4,0, 0x146,0x9000, 
	= { 
	0xfff4,0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 
	0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 
	0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 
	0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a78, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa576, 0xfff3, 0x5a79, 0x7fff, 0x5a8b, 
   0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000c, 0xa588, 
   0x8001, 0xa576, 0xfff4, 0x5a79, 0x7fff, 0x5a8b, 0x000d, 0xa587, 0x8001, 0xa575, 	

	0xfff4,0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 
	0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 
	0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 
	0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a78, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa576, 0xfff3, 0x5a79, 0x7fff, 0x5a8b, 
   0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000c, 0xa588, 
   0x8001, 0xa576, 0xfff4, 0x5a79, 0x7fff, 0x5a8b, 0x000d, 0xa587, 0x8001, 0xa575, 

	0xfff4,0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 
	0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 
	0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 
	0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a78, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa576, 0xfff3, 0x5a79, 0x7fff, 0x5a8b, 
   0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000c, 0xa588, 
   0x8001, 0xa576, 0xfff4, 0x5a79, 0x7fff, 0x5a8b, 0x000d, 0xa587, 0x8001, 0xa575, 
   
	0xfff4,0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 
	0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 
	0x8001, 0xa575, 0xfff4, 0x5a7a, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 
	0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a78, 
	0x7fff, 0x5a8a, 0x000d, 0xa587, 0x8001, 0xa576, 0xfff3, 0x5a79, 0x7fff, 0x5a8b, 
   0x000d, 0xa587, 0x8001, 0xa575, 0xfff4, 0x5a79, 0x7fff, 0x5a8a, 0x000c, 0xa588, 
   0x8001, 0xa576, 0xfff4, 0x5a79, 0x7fff, 0x5a8b, 0x000d, 0xa587, 0x8001, 0xa575 	

};*/


void DSP_BGSND_Hisr(void * param)
{
   int i;
   bool isWb;
   uint16 dst_buf_len, *src_buf;
   volatile uint16 *dst_buf;
   
   BGSND_PROCESS_TYPE type = (BGSND_PROCESS_TYPE) param; 
   
   kal_prompt_trace(MOD_L1SP, "[DSP_BGSND_Hisr] Enter");   
   
   kal_prompt_trace(MOD_L1SP, "[DSP_BGSND_Hisr] BGSND_PROCESS_TYPE(0->DL, 1->UL)=%d state=%d", type, DSP_BGSnd.state);
   
   ASSERT( type == BGSND_DL_PROCESS || type == BGSND_UL_PROCESS );   
	
	if ((DSP_BGSND_STATE_RUN != DSP_BGSnd.state)){
		return;
	}

   if(!SAL_Bgsnd_IsRunning())
      return;      		   

   DSP_BGSnd.Ext_Hisr[type]();
   src_buf = Ext_BGSnd.buffer[type]; 
   //log two to compare
///int has_ul = 0;
///int has_dl = 0;
///int ul_data[320], dl_data[320];
	
	//set up the DSP address and pointers
	switch(type){
	   case BGSND_DL_PROCESS:
         dst_buf_len = SAL_Bgsnd_GetDataLen_DL();      
         dst_buf     = SAL_Bgsnd_GetBuf_DL();
         //has_dl = 1;               
         //for(i=0; i<320; i++)
         //   ul_data[i]=param[i];
	      break;
	   case BGSND_UL_PROCESS:
         dst_buf_len = SAL_Bgsnd_GetDataLen_UL();      
         dst_buf     = SAL_Bgsnd_GetBuf_UL();      	               
         //has_ul = 1;
         //for(i=0; i<320; i++)
         //   dl_data[i]=param[i];         
	      break;   
	}         	      

   //if(has_dl == 1 && has_ul == 1){
   //      for(i=0; i<320; i++)
   //      if(dl_data[i])
   //}
   
   switch(dst_buf_len){
      case BGSND_BUFFER_LEN_WB:
         isWb = true;
         break;        
      case BGSND_BUFFER_LEN_NB:
         isWb = false;
         break;      
	   default:
 	      ASSERT(false);	  	                              
   }
		   
   for(i=0; i<dst_buf_len; i+=2){
      *dst_buf++ = *src_buf++;
      if(isWb){
         *dst_buf++ = *src_buf;
      }
      src_buf++;         
   }
   
 /*  {
      //just for debugging
      int i;
   	switch(type){
   	   case BGSND_DL_PROCESS:
            dst_buf_len = SAL_Bgsnd_GetDataLen_DL();      
            dst_buf     = SAL_Bgsnd_GetBuf_DL();               
   	      break;
   	   case BGSND_UL_PROCESS:
            dst_buf_len = SAL_Bgsnd_GetDataLen_UL();      
            dst_buf     = SAL_Bgsnd_GetBuf_UL();      	      
   	      break;  
   	}              
      for(i=0; i<10; i++){
         kal_prompt_trace(MOD_L1SP, "[DSP_BGSND_Hisr] %x %x %x %x %x %x %x %x %x %x ", 
                                     dst_buf[0],dst_buf[1],
                                     dst_buf[2],dst_buf[3],
                                     dst_buf[4],dst_buf[5],
                                     dst_buf[6],dst_buf[7],
                                     dst_buf[8],dst_buf[9]
                                     );
      
      }        
   }*/
   kal_prompt_trace(MOD_L1SP, "[DSP_BGSND_Hisr] Leave"); 
}

static void DSP_BGSND_Start(void (*Ext_DLHisr)(void), 
                            void (*Ext_ULHisr)(void))
{
   kal_prompt_trace(MOD_L1SP, "[DSP_BGSND_Start] Enter");
   ASSERT(AM_IsSpeechOn() || AM_IsVoIPOn());	
	
   DSP_BGSnd.Ext_Hisr[BGSND_DL_PROCESS]      = Ext_DLHisr;
   DSP_BGSnd.Ext_Hisr[BGSND_UL_PROCESS]      = Ext_ULHisr; 
	
#ifdef DSP_BGS_UP_DOWN_INT_SEPERATE
	L1Audio_HookHisrHandler(D2C_SOUND_EFFECT_INT_ID_DL, DSP_BGSND_Hisr, BGSND_DL_PROCESS);  
	L1Audio_HookHisrHandler(D2C_SOUND_EFFECT_INT_ID_UL, DSP_BGSND_Hisr, BGSND_UL_PROCESS);  
#else
	L1Audio_HookHisrHandler(D2C_SOUND_EFFECT_INT_ID_DL, DSP_BGSND_Shared_Hisr_DL_UL, 0);  	
#endif

	// gain setting and update 
	// Although these settings are allowed to modify during run time,
	// extended bgsnd should be fixed because the changes of volume from 
	// each sources are calculated in MCU side.
   DSP_BGSND_ConfigMixer(KAL_TRUE, 7, BGSND_UL_PROCESS);
	DSP_BGSND_ConfigMixer(KAL_TRUE, 7, BGSND_DL_PROCESS);

	DSP_BGSND_UpdateMixer();
	{  //turn on DSP BGSND
		uint32 I;
   	AM_SND_PlaybackOn();
   	SAL_Bgsnd_SetInit();		
		for( I = 0; ; I++ ) {
			if(SAL_Bgsnd_IsRunning())
				break;
			ASSERT_REBOOT( I < 20 );
			kal_sleep_task( 2 );
		}
	}	
	
	DSP_BGSnd.state = DSP_BGSND_STATE_RUN;
	kal_prompt_trace(MOD_L1SP, "[DSP_BGSND_Start] Leave");
}
/*===============  Ext BGSND interface ========= */

uint32 EXT_BGSND_init()
{
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_init] Enter");
   DSP_BGSND_INIT();
   memset((void *)&Ext_BGSnd, 0, sizeof(EXT_BGSND_T));      
   // get audio ID
	Ext_BGSnd.aud_id = L1Audio_GetAudioID(); 
	kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_init] Leave");
// L1Audio_SetEventHandler( Ext_BGSnd.aud_id, (L1Audio_EventHandler) EXT_BGSND_EventHandler );  	
}

void EXT_BGSND_DLHisr(void);
void EXT_BGSND_ULHisr(void);

uint32 EXT_BGSND_Start(void (*offHdr)(void),
                       void (*DLHisr)(void),       //move data from src -> ext
                       void (*ULHisr)(void),       //move data from src -> ext 
                       kal_int8 DLSNDGain,
                       kal_int8 ULSNDGain /*,                           
                       void (*EventHandler)(void)*/)
{
   int i, j;
   
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Start] Enter");
   
   ASSERT(!(NULL==DLHisr && NULL==ULHisr));
   ASSERT(NULL!=offHdr); //without this, we cannot stop DSP BGSND
     
   for(i=0; i<MAX_SIZE_EXT_BGSND_SRC; i++){
      kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Start] debug1 i=%d", i);
      if(!Ext_BGSnd.is_used[i]){
         kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Start] debug2 i=%d", i);
         EXT_BGSND_SRC_T *pSrc = &Ext_BGSnd.src[i];

         pSrc->Hdr[BGSND_DL_PROCESS]   = DLHisr;
         pSrc->Hdr[BGSND_UL_PROCESS]   = ULHisr;        
         pSrc->offHdr = offHdr;
         for(j=0; j<MAX_NUM_BGSND_PROCESS; j++){//TODO temp solution
            
            pSrc->state[j]  = EXT_SRC_STATE_RUN;      
            //pSrc->fSph[j]   = true; //TODO
            //pSrc->gain[j]   = 7;    //TODO     
            
         	// buffer reset
         	memset(pSrc->buffer[j], 0, sizeof(kal_uint16)*EXT_BGSND_SRC_BUF_SIZE);
         	pSrc->bufSize[j]  = EXT_BGSND_SRC_BUF_SIZE;
         	pSrc->bufRead[j]  = 0;
         	pSrc->bufWrite[j] = EXT_BGSND_BUF_PTR_DIFF;
         }   
         if(AM_IsSpeechOn() || AM_IsVoIPOn()){
            EXT_BGSND_ConfigMixer(i, true, DLSNDGain, BGSND_DL_PROCESS); 
            EXT_BGSND_ConfigMixer(i, true, ULSNDGain, BGSND_UL_PROCESS);
         }else{
            EXT_BGSND_ConfigMixer(i, false, DLSNDGain, BGSND_DL_PROCESS); 
            EXT_BGSND_ConfigMixer(i, false, ULSNDGain, BGSND_UL_PROCESS);            
         }         	
      	Ext_BGSnd.is_used[i] = true;     
         if( 0 == Ext_BGSnd.num_src_used++){
            kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Start] selected_src_id=%d num_src_used=%d", i,  Ext_BGSnd.num_src_used);
      	   // lock DSP for sherif writing.	
      	   L1Audio_SetFlag( Ext_BGSnd.aud_id ); // REIMIND: Before Locking SleepMode, to access DSP sherrif tasks much time. So access DSP must be after SetFlag1       
            DSP_BGSND_Start(EXT_BGSND_DLHisr, EXT_BGSND_ULHisr);
         }      	 	
         kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Start] debug3 i=%d", i);
      	break;
      }
      kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Start] debug4 i=%d", i);
   }   
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Start] debug5 i=%d", i);
   ASSERT(i < MAX_SIZE_EXT_BGSND_SRC);  
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Start] Leave");         
   return i;
}

void EXT_BGSND_Flush(uint32 id) //under MED Task, triggered by the AP message, BGSND_OFF
{                               //flush buffer first, and then close it ; HISR will consume the buffer until it is empty. 
   int j;
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Flush] Enter");   
   ASSERT(Ext_BGSnd.is_used[id]);
   
   EXT_BGSND_SRC_T *pSrc = &Ext_BGSnd.src[id];
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Flush] id=%d ", id);
   
   for(j=0; j<MAX_NUM_BGSND_PROCESS; j++){  
      if(EXT_SRC_STATE_RUN == pSrc->state[j]){    
         pSrc->state[j] = EXT_SRC_STATE_FLUSHING;
      }else{//prevent double entry to the procedure of flushing
         kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Flush] !!@state=%d ", pSrc->state[j]);         
      }
   }
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Flush] Leave");   
}

// under MED Task, triggered by the EXT_HISR when UL/DL buffer flushes completely.
// Even if many src would like to close DSP BGSND, we don't think about the race condition since the request of closing is processed by MED's queue.
// Due to it may force close. so status check nees to remove. 
void EXT_BGSND_Close(uint32 id) 
{
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Close] Enter");     
   ASSERT(Ext_BGSnd.is_used[id]);
   EXT_BGSND_SRC_T *pSrc = &Ext_BGSnd.src[id]; 
      
   // ASSERT(EXT_SRC_STATE_FLUSHING_OVER==pSrc->state[BGSND_DL_PROCESS]);
   // ASSERT(EXT_SRC_STATE_FLUSHING_OVER==pSrc->state[BGSND_UL_PROCESS]);
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Close] selected_src_id=%d num_src_used=%d", id,  Ext_BGSnd.num_src_used);
    
   {  //flush buffer first, and then close it   // buffer reset
   	Ext_BGSnd.is_used[id] = false;  // [IMPORTANT] HISR using the information to check BGS is under use or not. so put the line before clean all information.   
   	memset(pSrc, 0, sizeof(EXT_BGSND_SRC_T));   		
   	Ext_BGSnd.num_src_used--;  
   }
	
   pSrc->state[BGSND_DL_PROCESS] = pSrc->state[BGSND_UL_PROCESS] = EXT_SRC_STATE_STOPPING;    
	
   if( 0 == Ext_BGSnd.num_src_used){ 
      DSP_BGSND_Stop();      
      L1Audio_ClearFlag( Ext_BGSnd.aud_id );

   }  
   pSrc->state[BGSND_DL_PROCESS] = pSrc->state[BGSND_UL_PROCESS] = EXT_SRC_STATE_IDLE;    
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Close] Leave");     
}

void EXT_BGSND_DLHisr(void)
{
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_DLHisr] Enter");
   EXT_BGSND_Hisr(BGSND_DL_PROCESS);
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_DLHisr] Leave");
}

void EXT_BGSND_ULHisr(void)
{
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_ULHisr] Enter");
   EXT_BGSND_Hisr(BGSND_UL_PROCESS);
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_ULHisr] Leave");
}

/*static*/ int32 EXT_BGSND_GetDataCount(uint32 id, BGSND_PROCESS_TYPE type)
{
	int32 count = 0; 
	kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_GetDataCount] Enter");
	
	ASSERT( type == BGSND_DL_PROCESS || type == BGSND_UL_PROCESS );
	EXT_BGSND_SRC_T *pSrc = &Ext_BGSnd.src[id];
            
   count = (pSrc->bufSize[type] - EXT_BGSND_BUF_PTR_DIFF) - EXT_BGSND_GetFreeSpace(id, type);
/*   for(j=0; j<MAX_BGSND_BUFFER_PROCESS_BIT; j++){
      if(type & (1<<j)){         
         type = 1<<j;
      	if(pSrc->bufWrite[type]<pSrc->bufRead[type]){
      		count = (pSrc->bufSize[type] - EXT_BGSND_BUF_PTR_DIFF)+pSrc->bufWrite[type] - pSrc->bufRead[type];
      	} else {
      		count = pSrc->bufWrite[type] - pSrc->bufRead[type];
      	}	               
      }
   }	

	if( count > EXT_BGSND_BUF_PTR_DIFF) {
		count -= EXT_BGSND_BUF_PTR_DIFF;
	} else {
		count = 0;
	}

	if(count&1){
		count = count -1;
	}*/
	kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_GetDataCount] count=%d", count);
	kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_GetDataCount] Leave");
	return count;
}

void EXT_BGSND_Hisr(BGSND_PROCESS_TYPE type)
{
   uint16 dst_buf_len, *dst_buf, *src_buf;   
   int i;
   
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Hisr] Enter");
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Hisr] BGSND_PROCESS_TYPE(0->DL, 1->UL)=%d", type);
      
   //reset buffer data
   if( BGSND_DL_PROCESS == type){// align DL timing
      for(i=0; i<BGSND_BUFFER_LEN_WB; i++){ // To do , reduce computation
         Ext_BGSnd.buffer[BGSND_DL_PROCESS][i] = 0;    
      }    
      for(i=0; i<BGSND_BUFFER_LEN_WB; i++){ 
         Ext_BGSnd.buffer[BGSND_UL_PROCESS][i] = 0;    
      }         
   }
   DSP_BGSND_UpdateMixer();      
   for(i=0; i<MAX_SIZE_EXT_BGSND_SRC; i++){         
      EXT_BGSND_SRC_T *pSrc = &Ext_BGSnd.src[i];   
      if(Ext_BGSnd.is_used[i]){
         kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Hisr] selected_src_id=%d src_state=%d", i, pSrc->state[type]);

         //point 1
         if(pSrc->Hdr[type]){  // Point1 must be before point2 since it is expected that in pSrc->Hdr[type](),  len_WriteSrcBuffer_this_time will be updated by EXT_BGSND_WriteSrcBuffer
            pSrc->Hdr[type](); // Each Hdr should update buffer[BGSND_ L_PROCESS] by EXT_BGSND_Buf_Add
         }
              
         //point 2
         if(EXT_SRC_STATE_FLUSHING == pSrc->state[type]){ // FLUSHING --> FLUSHING_OVER            
            //if(EXT_BGSND_GetDataCount(i, type) <= EXT_BGSND_BUF_PTR_DIFF){
            if( (0 == pSrc->len_WriteSrcBuffer_this_time) /*&& (EXT_BGSND_GetDataCount(i, type) <= EXT_BGSND_BUF_PTR_DIFF)*/ ){
               kal_prompt_trace(MOD_L1SP, "  [EXT_BGSND_Hisr] %d-th Src's BGSND_PROCESS_TYPE(0->DL, 1->UL)=%d EXT_SRC_STATE_FLUSHING_OVER", i, type); 
               pSrc->state[type] = EXT_SRC_STATE_FLUSHING_OVER;
               if(EXT_SRC_STATE_FLUSHING_OVER == pSrc->state[1-type]){ // 1-type is just for the opposite.  DL <-> UL
                  kal_prompt_trace(MOD_L1SP, "  [EXT_BGSND_Hisr] Enter %d-th Src's OffHdr", i); 
                  pSrc->offHdr();   //FLUSHING_OVER --> STOPPING
                  kal_prompt_trace(MOD_L1SP, "  [EXT_BGSND_Hisr] Leave %d-th Src's OffHdr", i); 
                  kal_prompt_trace(MOD_L1SP, "  [EXT_BGSND_Hisr] Flush %d-th Src's OffHdr completely", i);            
               }else{//wait DL's flushing
                  kal_prompt_trace(MOD_L1SP, "  [EXT_BGSND_Hisr] Wait %d-th Src's Hdr to flush completely", i);
               }
            }else{
               kal_prompt_trace(MOD_L1SP, "  [EXT_BGSND_Hisr]  %d-th Src's BGSND_PROCESS_TYPE(0->DL, 1->UL)=%d is flushing with len=%d", i, type, EXT_BGSND_GetDataCount(i, type));  
            }
         }else{
            kal_prompt_trace(MOD_L1SP, "  [EXT_BGSND_Hisr] %d-th Src's BGSND_PROCESS_TYPE(0->DL, 1->UL)=%d is not flushing with state=%d", i, type, pSrc->state[type]);  
         }
         

                   
      }else{
         kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Hisr] %d-th Src's Hdr is not used ", i);    
      }
      pSrc->len_WriteSrcBuffer_this_time = 0;
   }  
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_Hisr] Leave ");
}

/*
void EXT_BGSND_Buf_Add(uint32 id, uint16* src_buf, int src_len, BGSND_PROCESS_TYPE type) // write into ext buffer
{
   int i;
   uint16 *dst_buf; 
   EXT_BGSND_SRC_T *pSrc;
   
   kal_prompt_trace(MOD_L1SP, "[BGSND] DSP_BGSND_Buf_Add id=%d src_len=%d type=%x ", id, src_len, type);
   
   ASSERT(Ext_BGSnd.is_used[id]);
   pSrc = &Ext_BGSnd.src[id]; 
   
   ASSERT( BGSND_BUFFER_LEN_WB == src_len);//must be wb
   ASSERT( type == BGSND_DL_PROCESS || type == BGSND_UL_PROCESS );   

   { // DL    
      dst_buf = Ext_BGSnd.buffer[type];
        
      for(i=0; i<src_len; i++){//accumulate DSP_DLBuffer
         if( src_buf[i] < (0x1111111111111111 - dst_buf[i])){ //limiter
            dst_buf[i] += src_buf[i];
         }else{
            kal_prompt_trace(MOD_L1SP, "[BKGSND]DSP_buf_add buf[%d]=%x DSP_DLBuffer[%d]=%x", i, src_buf[i], i, dst_buf[i]);  
         }
      }      
   }
}*/

/*
uint32 EXT_BGSND_SetEvent(uint32 id, void *data )
{
   ASSERT(Ext_BGSnd.is_used[id] && Ext_BGSnd.src[id].EventHandler);
   is_send_event[id] = true;
   Ext_BGSnd.src[i].event_data = data;
   L1Audio_SetEvent(Ext_BGSnd.src.aud_id, NULL);
}

void EXT_BGSND_EventHandler(void)
{
   for(i=0; i<MAX_SIZE_EXT_BGSND_SRC; i++){//dispatch the event
      if(Ext_BGSnd.is_send_event[i] && Ext_BGSnd.src[i].EventHandler){  
         Ext_BGSnd.src[i].EventHandler(Ext_BGSnd.src[i].event_data);
         Ext_BGSnd.is_send_event[i] = false;
      }
   }   
}
*/

void EXT_BGSND_WriteSrcBuffer(uint32 id, kal_uint8 *srcBuf, kal_int32 bufLen, BGSND_PROCESS_TYPE type)
{
	int32 freeLen; 
	int32 srcBufLen = bufLen >> 1; // unit: 8bits -> 16bits
	int32 currentRead; 
   EXT_BGSND_SRC_T *pSrc = &Ext_BGSnd.src[id];

   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_WriteSrcBuffer] Enter ");
   currentRead = pSrc->bufRead[type];          
   
   pSrc->len_WriteSrcBuffer_this_time = bufLen;
   
	if(currentRead > pSrc->bufWrite[type] || currentRead < EXT_BGSND_BUF_PTR_DIFF) {	// one segment
		if(currentRead > pSrc->bufWrite[type]){
			freeLen=currentRead - pSrc->bufWrite[type]-EXT_BGSND_BUF_PTR_DIFF;
		}else {
			freeLen=pSrc->bufSize[type] - pSrc->bufWrite[type]-EXT_BGSND_BUF_PTR_DIFF;
		}

		kal_trace( TRACE_FUNC, L1SND_WRITE_DATA, 1, id, type,  srcBufLen, freeLen, pSrc->bufRead[type], pSrc->bufWrite[type]+srcBufLen ); // using write information which is after memory copy
		
		ASSERT(srcBufLen <= freeLen); // unit is 2 byte
		memcpy(pSrc->buffer[type]+pSrc->bufWrite[type], srcBuf, srcBufLen*sizeof(uint16));		
	
		pSrc->bufWrite[type] += srcBufLen;
	}else { // two segment		
		int32 segment; 
		kal_uint8 *p2SrcBuf;

		freeLen= currentRead + pSrc->bufSize[type] - pSrc->bufWrite[type]-EXT_BGSND_BUF_PTR_DIFF;

		kal_trace( TRACE_FUNC, L1SND_WRITE_DATA, 2, id, type,  srcBufLen, freeLen, 0, 0 ); 
		ASSERT(srcBufLen <= freeLen);

		p2SrcBuf = srcBuf;
		segment = pSrc->bufSize[type] - pSrc->bufWrite[type]; // bug
		if(segment > srcBufLen){
			segment = srcBufLen;
		}

		if(segment>0) { //first segment		
			memcpy(pSrc->buffer[type]+pSrc->bufWrite[type], p2SrcBuf, segment*sizeof(kal_uint16));					
			//update pointer
			p2SrcBuf = srcBuf + segment*sizeof(kal_uint16); 
			pSrc->bufWrite[type] += segment;
			if(pSrc->bufWrite[type]>=pSrc->bufSize[type]){				
				pSrc->bufWrite[type] = 0; 
			}
			kal_trace( TRACE_FUNC, L1SND_WRITE_DATA, 3, id, type, 0, 0, pSrc->bufRead[type], pSrc->bufWrite[type]);
	
			segment = srcBufLen - segment; 
		}

		if(segment>0) { //second segement
			memcpy(pSrc->buffer[type], p2SrcBuf, segment*sizeof(kal_uint16));	
			pSrc->bufWrite[type] = segment;

			kal_trace( TRACE_FUNC, L1SND_WRITE_DATA, 4, id, type, 0, 0, pSrc->bufRead[type], pSrc->bufWrite[type]);	
		}
	}         
	kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_WriteSrcBuffer] Leave ");
}

//from DL Src buffer -> DL ext buffer, multiplied by gain
//from UL Src buffer -> UL ext buffer
void EXT_BGSND_WriteExtBuffer(uint32 id, int gain, BGSND_PROCESS_TYPE type) // ToDo
{
	volatile uint16 *toPtr;
   int32 count, segment, i;
   uint16 *dataPtr;
   uint16 gainFactor;
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_WriteExtBuffer] Enter ");   
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_WriteExtBuffer] selected_src_id = %d BGSND_PROCESS_TYPE(0->DL, 1->UL)=%d", id, type);   
	ASSERT( type == BGSND_DL_PROCESS || type == BGSND_UL_PROCESS );
   EXT_BGSND_SRC_T *pSrc = &Ext_BGSnd.src[id];
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_WriteExtBuffer] fSph=%d gain=%d ", pSrc->fSph[type], pSrc->gain[type]);      

   gainFactor = pSrc->gain[type];
   
   count = EXT_BGSND_GetDataCount(id, type);   
   toPtr = Ext_BGSnd.buffer[type];   
   
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_WriteExtBuffer] count=%d ", count);  
   
   if (count > BGSND_BUFFER_LEN_WB)
      count = BGSND_BUFFER_LEN_WB;         
   
   
   if(count > 0) {
	   /* First Segemnt */
		if(pSrc->bufWrite[type] < pSrc->bufRead[type]) {
		   segment = (pSrc->bufSize[type] - pSrc->bufRead[type]);
		} else {
			segment = (pSrc->bufWrite[type] - pSrc->bufRead[type]);
		}

		if(segment&1){ // keep two sample alight
			segment =segment - 1;
		}      

		if (segment > count)
			segment = count;
			   
	   if (segment > 0) {
	      dataPtr = &(pSrc->buffer[type][pSrc->bufRead[type]]);
	      
	      if(pSrc->fSph[type] && MAX_LEVEL_EXT_BGSND_GAIN!=gainFactor){
   	      for (i=0; i<segment; i++) {			
               if( *dataPtr < (0x1111111111111111 - *toPtr)){ //limiter
                  *toPtr += ((*dataPtr)>>gainFactor);     				
               }else{               
                  kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_WriteExtBuffer] overflows1");  
                  ASSERT(0);
               }
               toPtr++;
               dataPtr++;     				
   	      }
   	      pSrc->dspLastSample[type] = *(toPtr-1);
   	   }else{
	         toPtr   += segment;
	         dataPtr += segment;
	         
	         pSrc->dspLastSample[type] = 0;
	      }   

	      pSrc->bufRead[type] += segment;
	      if (pSrc->bufRead[type] >= pSrc->bufSize[type])
	         pSrc->bufRead[type] = (pSrc->bufRead[type]-pSrc->bufSize[type]);

			kal_prompt_trace(MOD_L1SP,   "[EXT_BGSND_WriteExtBuffer_%d] Filled %d word to DSP, bgSnd.bufRead=%d, bgSnd.bufWrite=%d", 1, segment, pSrc->bufRead[type], pSrc->bufWrite[type]);
	   }

		segment = count - segment;

	   if (segment > 0) {
	      dataPtr = &(pSrc->buffer[type][pSrc->bufRead[type]]);
	      if(pSrc->fSph[type] && MAX_LEVEL_EXT_BGSND_GAIN!=gainFactor){
   	      for (i=0; i<segment; i++) {  				
               if( *dataPtr < (0x1111111111111111 - *toPtr)){ //limiter
                  *toPtr += ((*dataPtr)>>gainFactor);
               }else{
                  kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_WriteExtBuffer] overflows2");  
                  ASSERT(0);
               }
               toPtr++;
               dataPtr++;     				
   	      }  
   	      pSrc->dspLastSample[type] = *(dataPtr-1);  	      
	      }else{
	         toPtr   += segment;
	         dataPtr += segment;
	         
	         pSrc->dspLastSample[type] = 0;
	      }
	      
	      pSrc->bufRead[type] += segment;
	      if (pSrc->bufRead[type] >= pSrc->bufSize[type])
	         pSrc->bufRead[type] = (pSrc->bufRead[type]-pSrc->bufSize[type]);

			kal_prompt_trace(MOD_L1SP,  "[EXT_BGSND_WriteExtBuffer_%d] Filled %d word to DSP, bgSnd.bufRead=%d, bgSnd.bufWrite=%d", 2, segment, pSrc->bufRead[type], pSrc->bufWrite[type]);	
	   }		
	}  
	
   /* Put silence (last sample) if MCU buffer is empty */
   if (count > 0 && count < BGSND_BUFFER_LEN_WB && EXT_SRC_STATE_RUN == pSrc->state[type]) {      		
      kal_uint16 last_sample = pSrc->dspLastSample[type];      
      // segment = dsp_buf_len - count;
      segment = BGSND_BUFFER_LEN_WB - count;
      //for (i=0; i<segment; i++)) {
      //   *toPtr++ = last_sample;     				
      //}	
      kal_prompt_trace(MOD_L1SP,  "[EXT_BGSND_WriteExtBuffer] Filled %d word to DSP with last sample %x", segment, last_sample);
      if(pSrc->fSph[type] && MAX_LEVEL_EXT_BGSND_GAIN!=gainFactor){
         for (i=0; i<segment; i++) {
            //*toPtr++ = *dataPtr++;     				
            if( last_sample < (0x1111111111111111 - *toPtr)){ //limiter
               *toPtr += (last_sample>>gainFactor);		               
            }else{
               kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_WriteExtBuffer] overflows3");  
               ASSERT(0);
            }
            toPtr++;			
         }   
      }else{
         toPtr += segment;
      } 	
   }//else{ //it means no data should be played, so we don't append to the size of a frame any more
   //   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_WriteExtBuffer] skip fill %d word to DSP with silence pattern, state=%d", count, pSrc->state[type]);      
   //}        	 
   
/*   {
      //just for debugging
      int i;
      for(i=0; i<10; i++){
         kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_WriteExtBuffer] %x %x %x %x %x %x %x %x %x %x ", 
                                     Ext_BGSnd.buffer[type][0],Ext_BGSnd.buffer[type][1],
                                     Ext_BGSnd.buffer[type][2],Ext_BGSnd.buffer[type][3],
                                     Ext_BGSnd.buffer[type][4],Ext_BGSnd.buffer[type][5],
                                     Ext_BGSnd.buffer[type][6],Ext_BGSnd.buffer[type][7],
                                     Ext_BGSnd.buffer[type][8],Ext_BGSnd.buffer[type][9]
                                     );
      
      }        
   }*/
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_WriteExtBuffer] Leave ");    
}

int32 EXT_BGSND_GetFreeSpace(uint32 id, BGSND_PROCESS_TYPE type)
{
	int32 count;
	ASSERT( type == BGSND_DL_PROCESS || type == BGSND_UL_PROCESS );
	EXT_BGSND_SRC_T *pSrc = &Ext_BGSnd.src[id];	
	
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_GetFreeSpace] Enter "); 
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_GetFreeSpace] ## r = %d w = %d size = %d", pSrc->bufSize[type], pSrc->bufRead[type], pSrc->bufWrite[type]); 
   
	count = pSrc->bufSize[type] + pSrc->bufRead[type] - pSrc->bufWrite[type] - EXT_BGSND_BUF_PTR_DIFF; // (int32)ihdl->mh.rbInfo.read - (int32)ihdl->mh.rbInfo.write - 1;
	if( count > pSrc->bufSize[type] )
      count = count - pSrc->bufSize[type];
   
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_GetFreeSpace] Leave ");    
	return count;	
}


void EXT_BGSND_ConfigMixer(int id, kal_bool bSPHFlag, kal_int8 SNDGain, BGSND_PROCESS_TYPE type)
{
   EXT_BGSND_SRC_T *pSrc = &Ext_BGSnd.src[id];   
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_ConfigMixer] Enter "); 
   ASSERT(SNDGain>=0 && SNDGain<=MAX_LEVEL_EXT_BGSND_GAIN);
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_ConfigMixer] bSPHFlag=%d SNDGain=%d", bSPHFlag, SNDGain); 
   pSrc->fSph[type] = bSPHFlag;
   pSrc->gain[type] = MAX_LEVEL_EXT_BGSND_GAIN-SNDGain;
   kal_prompt_trace(MOD_L1SP, "[EXT_BGSND_ConfigMixer] Leave ");  
   /*
   SNDGain = 7 --> Volume >> 0
   SNDGain = 6 --> Volume >> 1
   SNDGain = 5 --> Volume >> 2
   
   SNDGain = 0 --> Volume * 0 = 0
   */   
}


EXT_SRC_STATE_TYPE EXT_BGSND_GetStatus(int id,  BGSND_PROCESS_TYPE enULDL)
{
   ASSERT( id < MAX_SIZE_EXT_BGSND_SRC );
   ASSERT( enULDL < MAX_NUM_BGSND_PROCESS );
   return(Ext_BGSnd.src[id].state[enULDL]);
}


//================= Extended SPC BGSND INTERFACE ====================





