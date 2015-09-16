
#include "kal_public_api.h"
#include "kal_general_types.h"

#include "kal_trace.h"
#include "l1sp_trc.h"
#include "l1audio_trace.h"
#include "l1audio_sph_trc.h"

#include "l1audio.h"
#include "common_def.h"
#include "am.h"
#include "sp_drv.h"
#include "vm.h"
#include "sp_enhance.h"

#if defined(__CVSD_CODEC_SUPPORT__) 
#include "bt_sco_drv.h"
#endif

typedef struct {
	bool isEnable;
	bool isVocOn;
	
	uint16 aud_id;

	
} PCM_ROUTER_T;


static PCM_ROUTER_T g_PcmRouter; 

// ============================================================================

void PcmRouterStart(void)
{	

	kal_uint32 module_id = MOD_L1AUDIO_SPH_SRV;
   kal_uint32 voc_ptn = TVCI_CREATE_FILE;

	//call cpd and lock sleep mode
   g_PcmRouter.aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( g_PcmRouter.aud_id );

	// force unmute to decople PS module
	SP_SetForcedUnMuteController(L1SP_FORCEDUNMUTE_PCMROUTER, true);
	
	// turn on
	AM_PcmRouter_On();	

	// voc
   if(!tst_trace_check_ps_filter_off(TRACE_GROUP_VM, &module_id, 0x2))
   {
      tst_vc_response(TVCI_VM_LOGGING, (const kal_uint8*)&voc_ptn, 4);
      VMREC_Start(NULL, 0, true);
      g_PcmRouter.isVocOn = true;
   }
	
	//always unmute DSP uplink when speech on (This is to keep the mute definition)
	SP_MuteUlEnhResult(false); 

	// turn on speech enhancement
	SetSpeechEnhancement( true );

	//always unmute DSP uplink when speech on (This is to keep the mute definition)
	SP_MuteUlFromDiffPos(false, SP_MIC_MUTE_POS_FROM_ALL);
	L1SP_MuteSpeaker(false);

#if 0 // defined(__ECALL_SUPPORT__)
/* under construction !*/
/* under construction !*/
#endif

#if defined(__CVSD_CODEC_SUPPORT__) 
   if(L1SP_GetSpeechMode() == SPH_MODE_BT_EARPHONE || L1SP_GetSpeechMode() == SPH_MODE_BT_CARKIT)
   {
      kal_bool is_WB = AFE_GetVoice8KMode() == 1 ? KAL_TRUE : KAL_FALSE;
      BT_SCO_SPEECH_ON(is_WB);
   }
#endif

	g_PcmRouter.isEnable = true;
}

void PcmRouterStop(void)
{
   kal_uint32 voc_ptn = TVCI_CLOSE_FILE;

	// mute DL to prevent sound pushes to hardware buffer then causes noise. Sync with the end of speech unumte
	L1SP_MuteSpeaker(true);

#if defined(__CVSD_CODEC_SUPPORT__) 
	if(BT_SCO_IS_SPEECH_ON())
	{
		BT_SCO_SPEECH_OFF();
	}
#endif
	
#if 0 // defined(__ECALL_SUPPORT__)
/* under construction !*/
/* under construction !*/
#endif

	
	SetSpeechEnhancement( false );

	// voc
	if(g_PcmRouter.isVocOn)
	{
		tst_vc_response(TVCI_VM_LOGGING, (const kal_uint8*)(&voc_ptn), 4);
		VMREC_Stop(true);
		g_PcmRouter.isVocOn = false;
	}

	// turn off
	AM_PcmRouter_Off();

	//always unmute DSP uplink after speech off to keep the mute definition
	SP_MuteUlEnhResult(false);
	SP_MuteUlFromDiffPos(false, SP_MIC_MUTE_POS_FROM_ALL); 
	L1SP_MuteSpeaker(false);
	
	// leave the mute control to PS module	
	SP_SetForcedUnMuteController(L1SP_FORCEDUNMUTE_PCMROUTER, false);

	//unlock sleep mode and release CPD
	L1Audio_ClearFlag( g_PcmRouter.aud_id );
   L1Audio_FreeAudioID( g_PcmRouter.aud_id );
	g_PcmRouter.aud_id = 0xffff;
	
	g_PcmRouter.isEnable = false;
}
