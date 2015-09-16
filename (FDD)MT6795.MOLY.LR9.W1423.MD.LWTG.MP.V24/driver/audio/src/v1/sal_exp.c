#include "kal_public_api.h"
#include "kal_general_types.h"
#include "reg_base.h"
#include "l1_interface.h"
#include "string.h"

#include "common_def.h"

#include "sal_impl.h"
#include "sal_def.h"
#include "sal_exp.h"

#include "l1audio_trace.h"


// must to be configured right before sal app on. Normal, loudspk, and earphone can share the same device config for dsp, so switching among these 3 devices can discard the sal app reset.
void SAL_Set_Device(uint32 dev) 
{
	ASSERT(dev < SAL_DEV_MAX_NUM);
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(21), dev, SAL_UNKNOWN, SAL_UNKNOWN, SAL_UNKNOWN);
	SALI_Set_Device(dev);

}


void SAL_2G_Call_Open(uint32 enc_mod, uint32 dec_mod, uint32 sub_channel)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(0), enc_mod, dec_mod, sub_channel, SAL_UNKNOWN);
	//AM_DSP_SetSRCCtrl(0, 0);//SAL, SALI_Config_SRC
	SALI_Config_SRC(SAL_APP_TYPE_2GCall, IsWBLink(enc_mod));

	//AM_WriteSpeechParameters( 0x0633, am.speech_mode, am.speech_mode );//SAL, SALI_Enable_Codec
	/*   if(IsWBLink(enc_mod))
      *DP_AUDIO_PAR |= (VOICE_WB_AMR_FLAG); 
   else
      *DP_AUDIO_PAR &= ~(VOICE_WB_AMR_FLAG);        */
	SALI_Enable_Codec(enc_mod, dec_mod);

	//AM_FillSilencePattern( DSP_TX_TCH_S0_0, 2, am.speech_mode );  //wayne, for the next 2g call 2g mdm originally, now dsp sph and mdm has handshaking, no need anymore
	SALI_Fill_Enc_Silence(SAL_APP_TYPE_2GCall, enc_mod);

	SALI_Set_2G_Sch_Delay(enc_mod, sub_channel);	
    //AM_Write_Speech_Delay( am.speech_mode,  am.sub_channel, L1D_Get_Win_TQ_WRAP() - TQ_WRAP_COUNT );
    

   /* bit14 :the data of Speech DSP is avaible
      bit14 on  : Modem always sends the SpeechGood frame from Speech DSP, and at that time Driver fills the silence pattern. It causes MD send the silence pattern(good frame) to network
      bit14 off : Modem always sends the SpeechBad  frame into network. It will cause the better performance for continuity 
   */
   /*
   *E_CTRL_HO &= ~0x4000; 
   *E_CTRL_HO |= 0x0004;   // Enable ramp up in TCH
	*/
	
	SALI_AppSpec_Control(SAL_APP_TYPE_2GCall, 1);


   SALI_VBI_Reset();
	  
}

void SAL_2G_Handover(uint32 enc_mod, uint32 dec_mod, uint32 sub_channel)
{
		L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(2), enc_mod, dec_mod, sub_channel, SAL_UNKNOWN);
		
		SALI_Config_SRC(SAL_APP_TYPE_2GCall, IsWBLink(enc_mod));
	
		SALI_Set_2G_Handover();
		
		SALI_Enable_Codec(enc_mod, dec_mod);

        SALI_Set_2G_Sch_Delay(enc_mod, sub_channel);

		//for vm logging druing 2g ho
		SALI_Fill_Enc_Silence(SAL_APP_TYPE_2GCall, enc_mod);//wayne, for vm logging se frame during ho
        SALI_VM_Upd_Enc_Used(enc_mod);//wayne, for vm logging old se codec during ho, use DP_Encoder_Used_Mode from mt6280
        L1Audio_Msg_AM_Handover( enc_mod );
		#if defined(__MA_L1__)
        L1Audio_Msg_SPEECH_CODEC( L1SP_Speech_Codec_Mode(enc_mod), L1SP_Speech_Codec_Mode(enc_mod) );
		#endif

        SALI_VBI_Reset();

}

void SAL_3G_Call_Open(uint32 enc_mod, uint32 dec_mod, uint32 dtx, uint32 delR, uint32 delW, uint32 delM)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(3), enc_mod, dec_mod, dtx, SAL_UNKNOWN);		 
	//AM_DSP_SetSRCCtrl(0, 0);//SAL, SAL_ConfigSRC(device, codec);
	
	SALI_Config_SRC(SAL_APP_TYPE_3GCall, IsWBLink(enc_mod));

	
	// *DP_3G_STATE = 1;//SAL, Dsp_Set3GMode(true);
	SALI_Set_3G(true);

	/*
	if( SP3G_IsDTXOn() )
            sc_flags = 0x637;
         else
            sc_flags = 0x633;
         AM_WriteSpeechParameters( sc_flags, am.speech_mode, am.speech_mode ); // DTX always on*/
	SALI_Enable_Codec(enc_mod, dec_mod);//does 3g also use these two sherrif to assgin codec?? difference between MT6280 and MT6583
	SALI_3G_SetDtx(dtx);
	
	//AM_FillSilencePattern( DP_3G_UL_TX_TYPE, 2, am.speech_mode );  
	SALI_Fill_Enc_Silence(SAL_APP_TYPE_3GCall, enc_mod);

	//AM_Write_Idle_Delay(6);	 
    SALI_Set_Sch_Delay(delR, delW, delM, 0, SAL_UNKNOWN);

	SALI_AppSpec_Control(SAL_APP_TYPE_3GCall, 1);

        
   	SALI_VBI_Reset();
	  
}

void SAL_4G_Call_Open_temp(uint32 enc_mod, uint32 dec_mod, uint32 dtx, uint32 delR, uint32 delW, uint32 delM)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(3), enc_mod, dec_mod, dtx, SAL_UNKNOWN);		 
	//AM_DSP_SetSRCCtrl(0, 0);//SAL, SAL_ConfigSRC(device, codec);
	
	SALI_Config_SRC(SAL_APP_TYPE_4GCall, IsWBLink(enc_mod));

	
	// *DP_3G_STATE = 1;//SAL, Dsp_Set3GMode(true);
	SALI_Set_3G(true);

	/*
	if( SP3G_IsDTXOn() )
            sc_flags = 0x637;
         else
            sc_flags = 0x633;
         AM_WriteSpeechParameters( sc_flags, am.speech_mode, am.speech_mode ); // DTX always on*/
	SALI_Enable_Codec(enc_mod, dec_mod);//does 3g also use these two sherrif to assgin codec?? difference between MT6280 and MT6583
	SALI_3G_SetDtx(dtx);
	
	//AM_FillSilencePattern( DP_3G_UL_TX_TYPE, 2, am.speech_mode );  
	SALI_Fill_Enc_Silence(SAL_APP_TYPE_3GCall, enc_mod);

	//AM_Write_Idle_Delay(6);	 
    SALI_Set_Sch_Delay(delR, delW, delM, 0, SAL_UNKNOWN);

	SALI_AppSpec_Control(SAL_APP_TYPE_4GCall, 1);

        
   	SALI_VBI_Reset();
	  
}

void SAL_3G_SetDtx(bool on)
{
	SALI_3G_SetDtx(on);
}

void SAL_3G_Upd_Enc_Cod(uint32 enc_mod)
{
	SALI_Upd_3G_Enc_Rate(enc_mod);
}

void SAL_3G_Upd_Dec_Cod(uint32 dec_mod)
{	
	SALI_Upd_3G_Dec_Rate(dec_mod);
}

void SAL_3G_Set_TxType(uint32 tx_type)
{
	SALI_Set_3G_TxType(tx_type);
}

void SAL_3G_Set_RxType(uint32 rx_type)
{
	SALI_Set_3G_RxType(rx_type);
}

void SAL_2G_Call_Close(uint32 dsp_end)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(1), dsp_end, SAL_UNKNOWN, SAL_UNKNOWN, SAL_UNKNOWN);
	if(dsp_end)
	SALI_VBI_End();

	SALI_Disable_Codec();
   //*DP_SC_MUTE &= ~0x0002; wayne, come back, why??
   
 	SALI_AppSpec_Control(SAL_APP_TYPE_2GCall, 0);

}

void SAL_3G_Call_Close(uint32 dsp_end)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(4), dsp_end, SAL_UNKNOWN, SAL_UNKNOWN, SAL_UNKNOWN);
	
	if(dsp_end)
	SALI_VBI_End();

	SALI_Disable_Codec();	
   
   //*DP_SC_MUTE &= ~0x0002;

   	SALI_Set_3G_RxType(SAL_3G_RX_NO_DATA);
	SALI_Set_3G(false);

	SALI_AppSpec_Control(SAL_APP_TYPE_3GCall, 0);

}

void SAL_4G_Call_Close_temp(uint32 dsp_end)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(4), dsp_end, SAL_UNKNOWN, SAL_UNKNOWN, SAL_UNKNOWN);
	
	if(dsp_end)
	SALI_VBI_End();

	SALI_Disable_Codec();	
   
   //*DP_SC_MUTE &= ~0x0002;

   	SALI_Set_3G_RxType(SAL_3G_RX_NO_DATA);
	SALI_Set_3G(false);

	SALI_AppSpec_Control(SAL_APP_TYPE_4GCall, 0);

}

//fsju
void SAL_4G_G_Codec_Call_Close(uint32 dsp_end)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(30), dsp_end, SAL_UNKNOWN, SAL_UNKNOWN, SAL_UNKNOWN);

	SALI_Disable_Update_Codec_Now();

	if(dsp_end)
	SALI_VBI_End();

	SALI_Disable_Codec();	
   
   //*DP_SC_MUTE &= ~0x0002;

   	SALI_Set_3G_RxType(SAL_3G_RX_NO_DATA);
	SALI_Set_3G(false);

	SALI_AppSpec_Control(SAL_APP_TYPE_3GCall, 0);

}

//fsju
void SAL_4G_G_Codec_Call_Open(uint32 enc_mod, uint32 dec_mod, uint32 dtx, uint32 delR, uint32 delW, uint32 delM)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(29), enc_mod, dec_mod, dtx, SAL_UNKNOWN);		 
	//AM_DSP_SetSRCCtrl(0, 0);//SAL, SAL_ConfigSRC(device, codec);
	
	SALI_Config_SRC(SAL_APP_TYPE_3GCall, IsWBLink(enc_mod));

	
	// *DP_3G_STATE = 1;//SAL, Dsp_Set3GMode(true);
	SALI_Set_3G(true);

	/*
	if( SP3G_IsDTXOn() )
            sc_flags = 0x637;
         else
            sc_flags = 0x633;
         AM_WriteSpeechParameters( sc_flags, am.speech_mode, am.speech_mode ); // DTX always on*/
	SALI_Enable_Codec(enc_mod, dec_mod);//does 3g also use these two sherrif to assgin codec?? difference between MT6280 and MT6583
	SALI_3G_SetDtx(dtx);
	
	//AM_FillSilencePattern( DP_3G_UL_TX_TYPE, 2, am.speech_mode );  
	SALI_Fill_Enc_Silence(SAL_APP_TYPE_3GCall, enc_mod);

	//AM_Write_Idle_Delay(6);	 
    SALI_Set_Sch_Delay(delR, delW, delM, 0, SAL_UNKNOWN);

	SALI_AppSpec_Control(SAL_APP_TYPE_3GCall, 1);

        
   	SALI_VBI_Reset();

    //for G-serial codec, Just only disable AMR
	SALI_Disable_Codec();
	SALI_Enable_Update_Codec_Now();

}

//fsju
/*void SAL_4G_G_Codec_Open_DisableAMR(void)
{
	SALI_Disable_Codec();
	SALI_Enable_Update_Codec_Now();
}*/

//fsju
/*void SAL_4G_AMR_Call_Close(uint32 dsp_end)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(4), dsp_end, SAL_UNKNOWN, SAL_UNKNOWN, SAL_UNKNOWN);
	
	if(dsp_end)
	SALI_VBI_End();

	SALI_Disable_Codec();
	SALI_Enable_Update_Codec_Now();
   
   //*DP_SC_MUTE &= ~0x0002;

   	SALI_Set_3G_RxType(SAL_3G_RX_NO_DATA);
	SALI_Set_3G(false);

	SALI_AppSpec_Control(SAL_APP_TYPE_3GCall, 0);

}*/

bool SAL_3G_Mode()
{
	return SALI_Check_3G();
}

void SAL_App_Open(uint32 delR, uint32 delW, uint32 delM)
{
	//SALI_Set_Sch_Delay(delR, delW, delM, 0, 0);
	//SALI_VBI_Reset();
}

void SAL_App_Close(uint32 dsp_end)
{
	//if(dsp_end)
		//SALI_VBI_End();
}

void SAL_Bgsnd_SetInit()
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(5), 1, SAL_UNKNOWN, SAL_UNKNOWN, SAL_UNKNOWN);
	SALI_Bgsnd_Switch(true);
}

bool SAL_Bgsnd_IsRunning()
{
	return SALI_Bgsnd_IsRunning();
}

bool SAL_Bgsnd_IsIdle()
{
	return SALI_Bgsnd_IsOFF();
}

void SAL_Bgsnd_SetFinal()
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(5), 0, SAL_UNKNOWN, SAL_UNKNOWN, SAL_UNKNOWN);
	SALI_Bgsnd_Switch(false);
}

void SAL_Bgsnd_Config(uint32 ulgain, uint32 dlgain, uint32 ulmix, uint32 dlmix)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(6), ulgain, dlgain, ulmix, dlmix);
	SALI_Bgsnd_Config(ulgain, dlgain, ulmix, dlmix);
}

volatile uint16* SAL_Bgsnd_GetBuf_DL()
{
	return SALI_Bgsnd_GetBuf(1);
}

uint32 SAL_Bgsnd_GetDataLen_DL()
{
	return SALI_Bgsnd_GetDataLen(1);
}

volatile uint16* SAL_Bgsnd_GetBuf_UL()
{
	return SALI_Bgsnd_GetBuf(0);
}

uint32 SAL_Bgsnd_GetDataLen_UL()
{
	return SALI_Bgsnd_GetDataLen(0);
}

void SAL_Dsp_Sph_Init()
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(19), SAL_UNKNOWN, SAL_UNKNOWN, SAL_UNKNOWN, SAL_UNKNOWN);
	SALI_Init();
//	SALI_Fill_Enc_Silence(SAL_APP_TYPE_2GCall, enc_mod);
}


volatile uint16* SAL_Sidetone_GetFltCoefAddr()
{
	return SALI_GetFltCoefAddr(SALI_FLTCOEF_TYPE_SIDETONE);
}

volatile uint16* SAL_Notch_GetFltCoefAddr()
{
	return SALI_GetFltCoefAddr(SALI_FLTCOEF_TYPE_NOTCH);
}

uint16 SAL_Sidetone_GetAdaptiveGain()
{
	return SALI_Sidetone_GetAdaptiveGain();
}

void SAL_Sidetone_SetGain(uint16 val)
{
	SALI_Sidetone_SetGain(val);
}

void SAL_Sidetone_Enable(bool ena)
{
	SALI_Sidetone_Enable(ena);
}

uint16 SAL_DGain_Get_DL()
{
	return SALI_DGain_Get(1);
}

void SAL_DGain_Set_DL(uint16 val)
{
	SALI_DGain_Set(1, val);
}

uint16 SAL_DGain_Get_UL()
{
	return SALI_DGain_Get(0);
}

void SAL_DGain_Set_UL(uint16 val)
{
	SALI_DGain_Set(0, val);
}

volatile uint16* SAL_BKF_GetFltCoefAddr_NB_UL()
{
	volatile uint16 *addr;
	addr = SALI_GetFltCoefAddr(SALI_FLTCOEF_TYPE_BKF_NB_UL);
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(10), ((int)addr)>>16, (int)addr, SAL_UNKNOWN, SAL_UNKNOWN);
	return addr;
}

volatile uint16* SAL_BKF_GetFltCoefAddr_NB_DL()
{
	volatile uint16 *addr;
	addr = SALI_GetFltCoefAddr(SALI_FLTCOEF_TYPE_BKF_NB_DL);
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(10), SAL_UNKNOWN, ((int)addr)>>16, (int)addr, SAL_UNKNOWN);
	return addr;
}

volatile uint16* SAL_BKF_GetFltCoefAddr_WB_UL()
{
	volatile uint16 *addr;
	addr = SALI_GetFltCoefAddr(SALI_FLTCOEF_TYPE_BKF_WB_UL);
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(10), SAL_UNKNOWN, SAL_UNKNOWN, ((int)addr)>>16, (int)addr);
	return addr;
}

volatile uint16* SAL_BKF_GetFltCoefAddr_WB_DL()
{
	volatile uint16 *addr;
	addr = SALI_GetFltCoefAddr(SALI_FLTCOEF_TYPE_BKF_WB_DL);
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(10), (int)addr, SAL_UNKNOWN, SAL_UNKNOWN, ((int)addr)>>16);
	return addr;
}

void SAL_BKF_Switch(uint32 ul, uint32 dl)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(7), ul, dl, SAL_UNKNOWN, SAL_UNKNOWN);
	SALI_BKF_Switch(ul, dl);
}

volatile uint16* SAL_SRC_GetFltCoefAddr()
{
	return SALI_GetFltCoefAddr(SALI_FLTCOEF_TYPE_SRC);
}

volatile uint16* SAL_AGC_GetFltCoefAddr()
{
	return SALI_GetFltCoefAddr(SALI_FLTCOEF_TYPE_AGC);
}

void SAL_ENH_SetULPath(bool on)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(8), 0, on, SAL_UNKNOWN, SAL_UNKNOWN);
	SALI_ENH_PathEnable(0, on);
}

void SAL_ENH_SetDLPath(bool on)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(8), 1, on, SAL_UNKNOWN, SAL_UNKNOWN);
	SALI_ENH_PathEnable(1, on);
}


void SAL_ENH_SetInit(uint32 enh_mod)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(9), enh_mod, 1, SAL_UNKNOWN, SAL_UNKNOWN);
	SALI_ENH_Switch(enh_mod, true);
}

void SAL_ENH_SetOff(uint32 enh_mod)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(9), enh_mod, 0, SAL_UNKNOWN, SAL_UNKNOWN);
	SALI_ENH_Switch(enh_mod, false);
}

bool SAL_ENH_IsReady(uint32 enh_mod)
{
	return SALI_ENH_IsReady(enh_mod);
}

bool SAL_ENH_IsIdle(uint32 enh_mod)
{
	return SALI_ENH_IsIdle(enh_mod);
}

void SAL_ENH_Dynamic_Ctrl(bool on, Sal_Enh_Dynamic_t fea)
{
	SALI_ENH_Dynamic_Ctrl(on, fea);
}

void SAL_ENH_Gain_Set_DL(uint16 val)
{
	SALI_ENH_Gain_Set_DL(val);
}

volatile uint16* SAL_CommonPar_GetBuf()
{
	volatile uint16 *addr;
	addr = SALI_Parameter_GetAddr(SALI_PARAMETER_TYPE_COMMON);
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(12), ((int)addr)>>16, (int)addr, SAL_UNKNOWN, SAL_UNKNOWN);
	return addr;
}

volatile uint16* SAL_ModePar_GetBuf_NB()
{
	volatile uint16 *addr;
	addr = SALI_Parameter_GetAddr(SALI_PARAMETER_TYPE_MODE_NB);
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(11), ((int)addr)>>16, (int)addr, SAL_UNKNOWN, SAL_UNKNOWN);
	return addr;
}

volatile uint16* SAL_ModePar_GetBuf_WB()
{
	volatile uint16 *addr;
	addr = SALI_Parameter_GetAddr(SALI_PARAMETER_TYPE_MODE_WB);
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(11), SAL_UNKNOWN, SAL_UNKNOWN, ((int)addr)>>16, (int)addr);
	return addr;
}

volatile uint16* SAL_DMNR_GetFltCoefAddr_NB()
{
	volatile uint16 *addr;
	addr = SALI_GetFltCoefAddr(SALI_FLTCOEF_TYPE_DMNR_NB);
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(13), ((int)addr)>>16, (int)addr, SAL_UNKNOWN, SAL_UNKNOWN);
	return addr;
}


volatile uint16* SAL_DMNR_GetFltCoefAddr_WB()
{
	volatile uint16 *addr;
	addr = SALI_GetFltCoefAddr(SALI_FLTCOEF_TYPE_DMNR_WB);
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(13), SAL_UNKNOWN, SAL_UNKNOWN, ((int)addr)>>16, (int)addr);
	return addr;
}

uint16 SAL_3G_GetValue(uint16 type)
{
	return SALI_3G_GetValue(type);
}

volatile uint16* SAL_3G_GetAddr(uint16 type)
{
	return SALI_3G_GetAddr(type);
}

bool SAL_3G_IsULReady()
{
	return SALI_3G_CheckDataSync(0);
}

void SAL_3G_SetULEmpty()
{
	SALI_3G_SetDataStatus(0, 0);
}

bool SAL_3G_IsDLEmpty()
{
	return SALI_3G_CheckDataSync(1);
}

void SAL_3G_SetDLReady()
{
	SALI_3G_SetDataStatus(1, 1);
}


bool SAL_DSPINT_Resolve(uint16 iid, uint32* sph_int)
{
	return SALI_Int_Resolve(iid, sph_int);
}

void SAL_PcmEx_Config(Sal_PCMEx_Config_t* cfg)
{
	ASSERT_REBOOT(cfg != 0);
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(14), cfg->swi, cfg->type, cfg->idle, cfg->band);
	SALI_PcmEx_Config(cfg);
}

void SAL_PcmEx_SetStateUL(Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(15), 0, type, sta, SAL_UNKNOWN);
	SALI_PcmEx_SetState(0, type, sta);
}

void SAL_PcmEx_SetStateDL(Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(15), 1, type, sta, SAL_UNKNOWN);
	SALI_PcmEx_SetState(1, type, sta);
}

bool SAL_PcmEx_CheckStateUL(Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta)
{
	return SALI_PcmEx_CheckState(0, type, sta);
}

bool SAL_PcmEx_CheckStateDL(Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta)
{
	return SALI_PcmEx_CheckState(1, type, sta);
}

bool SAL_PcmEx_IsCtrlClean(Sal_PcmEx_Type_t type)
{
	return SALI_PcmEx_IsCtrlClean(type);
}

void SAL_PcmEx_SetCtrlClean(Sal_PcmEx_Type_t type)//dangerous operation
{
	//SALI_PcmEx_SetCtrlClean(type);
}

volatile uint16* SAL_PcmEx_GetBuf(Sal_PcmEx_BufId_t id)
{
	return SALI_PcmEx_GetBuf(id);
}

uint16 SAL_PcmEx_GetBufLen(Sal_PcmEx_BufId_t id)
{
	return SALI_PcmEx_GetBufLen(id);
}

uint16 SAL_AGC_GetSWGain(uint8 mic) // 0 -> mic1, 1 -> mic2
{
	return SALI_AGC_GetSWGain(mic);
}

void SAL_AGC_SetGain(uint16 val)
{
	SALI_AGC_SetGain(val);
}

void SAL_VM_Config(Sal_VM_Config_t *cfg)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(20), cfg->swi, cfg->idle, cfg->codec, SAL_UNKNOWN);
	SALI_VM_Config(cfg);
}


void SAL_VM_GetFrame2G(Sal_VM_Frame *vmfrm)
{
	ASSERT_REBOOT(vmfrm != 0);
	SALI_VM_GetFrame(0, vmfrm);
}

void SAL_VM_GetFrame3G(Sal_VM_Frame *vmfrm)
{
	ASSERT_REBOOT(vmfrm != 0);
	SALI_VM_GetFrame(1, vmfrm);
}

void SAL_EPL_GetFrame(Sal_EPL_Frame *eplfrm)
{
	ASSERT_REBOOT(eplfrm != 0);
	SALI_EPL_GetFrame(eplfrm);
}

void SAL_LBK_Codec(bool on)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(16), on, SAL_UNKNOWN, SAL_UNKNOWN, SAL_UNKNOWN);
	SALI_LBK_Codec(on);
}

void SAL_BT_Config(Sal_BT_Config *cfg)
{
	ASSERT_REBOOT(cfg != 0);
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(17), cfg->feed_cfg, cfg->mode, cfg->linear_ctrl, (cfg->linear_ul_gain<<8)+cfg->linear_reverse);
	SALI_BT_Config(cfg);
}

//return if DSP is being in bt-mode
bool SAL_BT_IsEnable()
{
	return SALI_BT_IsEnable();
}

void SAL_Mute_Ctrl(Sal_Mute_Point_t ctrl, bool mute)
{
	SALI_Mute_Ctrl(ctrl, mute);
}

//true means the dsp point is muted
bool SAL_Mute_Check(Sal_Mute_Point_t ctrl)
{
	return SALI_Mute_Check(ctrl);
}

void SAL_CTM_Switch(bool on)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(18), on, SAL_UNKNOWN, SAL_UNKNOWN, SAL_UNKNOWN);
	SALI_CTM_Switch(on);
}

void SAL_CTM_SetGain(uint16 limit, uint16 update)
{
	SALI_CTM_SetGain(limit, update);
}

uint16 SAL_CTM_GetValue(uint16 type)
{
	return SALI_CTM_GetValue(type);
}

bool SAL_CTM_IsIdle()
{
	return SALI_CTM_IsIdle();
}

bool SAL_CTM_IsOff()
{
	return SALI_CTM_IsOff();
}

void SAL_AGC1_Config(Sal_AGC_Config_t *cfg)
{
	ASSERT_REBOOT(cfg != 0);
	SALI_AGC1_Config(cfg);
}

void SAL_AGC2_Config(Sal_AGC_Config_t *cfg)
{
	ASSERT_REBOOT(cfg != 0);
	SALI_AGC2_Config(cfg);
}

void SAL_AGC3_Config(Sal_AGC_Config_t *cfg)
{
	ASSERT_REBOOT(cfg != 0);
	SALI_AGC3_Config(cfg);
}

void SAL_AGC4_Config(Sal_AGC_Config_t *cfg)
{
	ASSERT_REBOOT(cfg != 0);
	SALI_AGC4_Config(cfg);
}

void SAL_NotchFilter_Enable(bool ena, bool thirdStageIIR)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(22), ena, thirdStageIIR, SAL_UNKNOWN, SAL_UNKNOWN);
	SALI_NotchFilter_Enable(ena, thirdStageIIR);
}
void SAL_8K_Resync(bool ul, int16 ul_offset, bool dl, int16 dl_offset)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(23), ul, ul_offset, dl, dl_offset);
	SALI_8K_Resync(ul, ul_offset, dl, dl_offset);
}

void SAL_GetWarnMsg(uint16 *ulcode, uint16 *dlcode)
{
	SALI_GetWarnMsg(ulcode, dlcode);
}

void SAL_2G_SMR_Switch(bool on)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(25), on, SAL_UNKNOWN, SAL_UNKNOWN, SAL_UNKNOWN);
	SALI_2G_SMR_Switch(on);
}

void SAL_VOLTE_SetInfo(Sal_VOLTE_info_t info, uint16 val)
{
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(24), info, val, SAL_UNKNOWN, SAL_UNKNOWN);
	SALI_VOLTE_SetInfo(info, val);
}

volatile uint16* SAL_ENH_GetInternalParAddr()
{
	volatile uint16 *addr;
	addr = SALI_Parameter_GetAddr(SALI_PARAMETER_TYPE_MODE_INTERNAL);
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(26), ((int)addr)>>16, (int)addr, SAL_UNKNOWN, SAL_UNKNOWN);
	return addr;
}

void SAL_3G_SetULUnsync()
{
	SALI_3G_SetULUnsync();
}

void SAL_PCM_Router_Open(Sal_PCM_Router_t *pcmrt)
{
	uint16 value1 = 0;
	uint16 value2 = 0;
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(27), pcmrt->dev_band, pcmrt->cod_band, SAL_UNKNOWN, SAL_UNKNOWN);
	value1 |= SAL_BIT0;       //enable PCM router
	if(0 == pcmrt->dev_band) // NB
	{
		value1 |= SAL_BIT1;     // NB: (value |= SAL_BIT1), WB: (value &= ~SAL_BIT1)
	}
	
	//if((0 == pcmrt->dev_band) && (1 == pcmrt->cod_band))
	//{
	//	value2 |= (SPH_SFE_SRC_PCM_RT_SE28K_DS + SPH_SFE_SRC_PCM_RT_8K2SD_US);
	//}
	//else if((1 == pcmrt->dev_band) && (0 == pcmrt->cod_band))
	//{
	//	value2 |= (SPH_SFE_SRC_PCM_RT_SE28K_US + SPH_SFE_SRC_PCM_RT_8K2SD_DS);
	//}	
	
	if(1 == pcmrt->cod_band)
	{
		*DSP_SPH_8K_CTRL |= SAL_BIT3;
	}
	SALI_Set_Sch_Delay(pcmrt->delR, pcmrt->delW, pcmrt->delM_DL, 0, pcmrt->delM_UL);
	*DSP_SPH_PCM_ROUTER_CTRL = value1;
	*DSP_SPH_SFE_CTRL |= value2;
	SALI_Config_SRC(SAL_APP_TYPE_PCM_Router, pcmrt->cod_band == SAL_PCM_WIDEBAND);
	SALI_AppSpec_Control(SAL_APP_TYPE_PCM_Router, 1);
	SALI_VBI_Reset();
}

void SAL_PCM_Router_Close(uint32 dsp_end)
{
	uint16 value = 0;
	
	L1Audio_Msg_SAL_PROC(SAL_PROC_NAME(28), SAL_UNKNOWN, SAL_UNKNOWN, SAL_UNKNOWN, SAL_UNKNOWN);
	*DSP_SPH_PCM_ROUTER_CTRL = value;
	if(dsp_end)
	SALI_VBI_End();
	SALI_AppSpec_Control(SAL_APP_TYPE_PCM_Router, 0);
}
