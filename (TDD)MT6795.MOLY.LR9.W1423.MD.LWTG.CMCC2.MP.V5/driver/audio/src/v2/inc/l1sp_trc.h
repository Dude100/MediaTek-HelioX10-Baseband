#ifndef _L1SP_TRC_H
#define _L1SP_TRC_H

#ifndef GEN_FOR_PC

   #ifndef _STACK_CONFIG_H
   #error "stack_config.h should be included before l1sp_trc.h"
   #endif

#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */

#ifndef _KAL_TRACE_H
   #error "kal_trace.h should be included before nvram_trc.h"
#endif

#define TRACE_GROUP_SBC          TRACE_GROUP_1
#define TRACE_GROUP_RESAMPLER    TRACE_GROUP_1
#define TRACE_GROUP_DAFRTP       TRACE_GROUP_1
#define TRACE_GROUP_SND          TRACE_GROUP_2
#define TRACE_GROUP_AUD_PROCESS  TRACE_GROUP_3
#define TRACE_GROUP_VORTP        TRACE_GROUP_4
#define TRACE_GROUP_CACHE        TRACE_GROUP_5
#define TRACE_GROUP_AST          TRACE_GROUP_5
#define TRACE_GROUP_AUDRTP       TRACE_GROUP_6
#define TRACE_GROUP_APM          TRACE_GROUP_7
#define TRACE_GROUP_SP3G         TRACE_GROUP_8
#define TRACE_GROUP_DSPSYN       TRACE_GROUP_1
#define TRACE_GROUP_JWAV         TRACE_GROUP_2
#define TRACE_GROUP_AUD_PLAYBACK TRACE_GROUP_9
#define TRACE_GROUP_AUD_RECORD   TRACE_GROUP_9

#define TRACE_GROUP_PLAYBACK_CILENT    TRACE_GROUP_1
#define TRACE_GROUP_PLAYBACK_COMPONENT TRACE_GROUP_1
#define TRACE_GROUP_ECALL              TRACE_GROUP_1


#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "l1sp_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_L1SP)

   // AFE
   TRC_MSG(AFE_SWITCH_FIR, "AFE Switch FIR %c for aud_func %X")
   TRC_MSG(AFE_SWITCH_LOOPBACK, "AFE Switch Loopback %c")
   TRC_MSG(AFE_SWITCH_MIC, "AFE Switch MIC %c for aud_func %X")
   TRC_MSG(AFE_SET_INPUT_SRC, "AFE SetInputSource: %X")
   TRC_MSG(AFE_GAIN, "AUDIO_CON1:%X, AUDIO_CON2:%X, AUDIO_CON20:%X")
   TRC_MSG(AFE_DIGI_GAIN, "DP_VOL_OUT_PCM:%X, DP_DigiGain_Setting:%X")
   TRC_MSG(AFE_SET_MIC_VOLUME, "AFE SetMicrophoneVolume: %X")
   TRC_MSG(AFE_SET_SIDETONE_VOLUME, "AFE SetSideToneVolume: %X")
   TRC_MSG(AFE_SET_OUTPUT_DEVICE, "AFE Set aud_func %X OutputDevice %X")
   TRC_MSG(AFE_SET_OUTPUT_VOLUME, "AFE Set aud_func %X OutputVolume %d %d")
   TRC_MSG(AFE_SET_LEVEL_VOLUME, "AFE Set aud_func %X MaxAnalogGain %d , step %d, level %d")
   TRC_MSG(AFE_SET_GIDI_GAIN, "AFE Set aud_func %X digital gain level %d")
   TRC_MSG(AFE_MUTE_SPEAKER, "AFE mute aud_func %X speaker %d")
   TRC_MSG(AFE_SET_EDI, "AFE Set EDI dir %d cycle %d fmt %d")
   TRC_MSG(AFE_SWITCH_HW_MUTE_SLEEP, "AFE Switch HW mute sleep %d")
   TRC_MSG(AFE_SET_DUAL_PATH_GAIN, "AFE set dual path gain 0x%X")
   TRC_MSG(AFE_SET_MIC_GAIN_CONTROL, "AFE set mic gain_ctrl Ana %d Dig %d(%d)")
   TRC_MSG(AFE_SET_OUTPUT_GAIN_CONTROL, "AFE set func %d gain_ctrl 0x%X Ana %d Dig %d(%d) Ext 0x%x")


   // L1CTM
   TRC_MSG(L1CTM_OPEN, "Call L1Ctm_Open")
   TRC_MSG(L1CTM_CLOSE, "Call L1Ctm_Close")
   TRC_MSG(L1CTM_CALLBACK_EVENT, "L1Ctm Event %d")
   TRC_MSG(L1CTM_SET_INTERFACE, "Call L1Ctm_SetInterface")
   TRC_MSG(L1CTM_START_NEGOTIATION, "Call L1Ctm_StartNegotiation")
   TRC_MSG(L1CTM_TX_PUT_TEXT, "Call L1Ctm_TxPutText")
   TRC_MSG(L1CTM_RX_GET_TEXT, "Call L1Ctm_RxGetText")

   TRC_MSG(L1CTM_FAR_END_CTM_DETECTED, "L1Ctm far-end CTM detected")
   TRC_MSG(L1CTM_NEGOTIATION_SUCCESS, "L1Ctm negotiation success")
   TRC_MSG(L1CTM_NEGOTIATION_FAIL, "L1Ctm negotiation fail")
   TRC_MSG(L1CTM_DEMAND_CTM_ACK, "L1Ctm is demanded to send CTM ACK")
   TRC_MSG(L1CTM_UL_SEND_IDLE_AS_ACK, "L1CtmTx ul-path send IDLE as ACK")
   TRC_MSG(L1CTM_DL_DETECT_CTM_SYNC, "L1Ctm dl-path detect CTM Sync")
   TRC_MSG(L1CTM_DL_CTM_BURST_END, "L1Ctm dl-path detect CTM burst-end")

   TRC_MSG(L1CTM_UL_SEND_ENQUIRY_CHAR, "L1Ctm ul-path send %d-time ENQUIRY char")
   TRC_MSG(L1CTM_UL_GET_DECODED_TTY_CHAR, "L1Ctm ul-path get decoded TTY-char 0x%02X")
   TRC_MSG(L1CTM_UL_SEND_CTM_CHAR, "L1Ctm ul-path send CTM-char 0x%02X")
   TRC_MSG(L1CTM_DL_GET_RECEIVED_CTM_CHAR, "L1Ctm dl-path get received CTM-char 0x%02X")
   TRC_MSG(L1CTM_DL_SEND_TTY_CHAR, "L1Ctm dl-path send TTY-char 0x%02X")
   TRC_MSG(L1CTM_REC_DIR_NO, "L1Ctm record to dir REC_%02u")
   TRC_MSG(L1CTM_SAVE_DECODED_CHAR, "L1Ctm dl-path save decoded char 0x%02X")
   TRC_MSG(L1CTM_DL_BFI, "L1Ctm dl-path BFI %d")
   
   TRC_MSG(L1CTM_DL_OVERFLOW, "L1Ctm DL buffer overflow")
   TRC_MSG(L1CTM_UL_OVERFLOW, "L1Ctm UL buffer overflow")
   TRC_MSG(L1CTM_DEBUG_FLAG, "L1Ctm param is %x, cprm_debug_flag=%x")
   
   //PCM4WAY
   TRC_MSG(PCM4WAY_SET_SERVICE_TYPE, "PCM4WAY set service type=%d")
   TRC_MSG(PCM2WAY_SET_SERVICE_TYPE, "PCM2WAY set service type=%d")
   
   //TONE DETECT
   TRC_MSG(DTMF_ANALYZE_SN, "DTMF analysis s1(%d)=%2d, s2(%d)=%2d, n(%d)=%2d, (s-n)=%2d")
   
   // SBC
   TRC_MSG(L1SBC_ENTER_SBC_INITIATEBITPOOL, "Enter SBC_InitiateBitPool")
   TRC_MSG(L1SBC_ENTER_SBC_ADJUSTBITPOOL, "Enter SBC_AdjustBitPool")
   TRC_MSG(L1SBC_ENTER_SBC_ADJUSTBITRATEFROMQOS, "Enter sbc_AdjustBitRateFromQoS")
   TRC_MSG(L1SBC_ENTER_SBC_QUERYPAYLOADSIZE, "Enter sbc_QueryPayloadSize")
   TRC_MSG(L1SBC_ENTER_SBC_GETPAYLOAD, "Enter sbc_GetPayload")
   TRC_MSG(L1SBC_ENTER_SBC_OPEN, "Enter SBC_Open")
   TRC_MSG(L1SBC_ENTER_SBC_CLOSE, "Enter SBC_Close")
   TRC_MSG(L1SBC_ENTER_SBC_GETMEMREQ, "Enter SBC_GetMemReq")
   TRC_MSG(L1SBC_ENTER_SBC_ENCODING, "Enter sbc_event_handler")
   TRC_MSG(L1SBC_QOS_REPORT, "SBC QoS=%d, change bitrate from %d to %d")
   TRC_MSG(L1SBC_OPEN_REPORT, "SBC opened with id=%d, initial bitrate=%d, full sbc=%d, fmt=%d")
   TRC_MSG(L1SBC_CLOSE_REPORT, "SBC closed with %d frame dropped")
   TRC_MSG(L1SBC_CONFIG_REPORT, "SBC encoder config: fs=%d, cm=%d, bp=%d-%d-%d")
   TRC_MSG(L1SBC_ENCODER_REPORT, "SBC encoder status: process %d samples, left %d bytes, produce %d frames")
   TRC_MSG(L1SBC_PAYLOAD_REPORT, "SBC payload request %dB, get %dB, %d frames, left %dB")
   TRC_MSG(L1SBC_FRAME_BUFFER_UNDERRUN, "SBC frame buffer underrun")
   TRC_MSG(L1SBC_ENCODER_CONFIG, "SBC encoder config: ana: %d, up: %d, sample freq: %d/%d")
   TRC_MSG(L1SBC_INITIATED, "SBC initiated")
   TRC_MSG(L1SBC_INITIATING, "SBC initiating, type %d, %d")
   TRC_MSG(L1SBC_MUTE, "SBC mute: %d")
   TRC_MSG(L1SBC_SET_LEVEL_VOLUME, "SBC SetLevelVolume: uCurStep: %d, uTotalStep: %d, uDigiGain: %d")
   
   // SND
   TRC_MSG(L1SND_ENTER_SND_OPEN, "Enter SND_Open")
   TRC_MSG(L1SND_ENTER_SND_CLOSE, "Enter SND_Close")
   TRC_MSG(L1SND_ENTER_SND_PLAY, "Enter SND_Play")
   TRC_MSG(L1SND_ENTER_SND_STOP, "Enter SND_Stop")
   TRC_MSG(L1SND_CONFIG_ULMIXER, "SND ConfigULMixer, flag:%d, gain:%d")
   TRC_MSG(L1SND_CONFIG_DLMIXER, "SND ConfigDLMixer, flag:%d, gain:%d")
   TRC_MSG(L1SND_REPEATED, "SND Repeat-play, elapsed:%d times")
   TRC_MSG(L1SND_FILLBUFFER, "SND Filled %d bytes")
   TRC_MSG(L1SND_DATACHUNK_SIZE, "SND Data chunk size: %d bytes")


   // AP2MCU2DSP
   TRC_MSG(L1AP2MCU_DEBUG_PRINT1, "[AP2MCU] %x")              
   TRC_MSG(L1AP2MCU_DEBUG_PRINT2, "[AP2MCU] %x %x")           
   TRC_MSG(L1AP2MCU_DEBUG_PRINT3, "[AP2MCU] %x %x %x")        
   TRC_MSG(L1AP2MCU_DEBUG_PRINT4, "[AP2MCU] %x %x %x %x")     
   TRC_MSG(L1AP2MCU_DEBUG_PRINT5, "[AP2MCU] %x %x %x %x %x")  
   TRC_MSG(L1AP2MCU_COMMONPAR,    "[AP2MCU] CommonPar")
   TRC_MSG(L1AP2MCU_MODEPARANB,   "[AP2MCU] ModeParaNB")         
   TRC_MSG(L1AP2MCU_VOLPARA,      "[AP2MCU] VolPara")
   TRC_MSG(L1AP2MCU_INFIRNB,      "[AP2MCU] InFirNB")
   TRC_MSG(L1AP2MCU_OUTFIRNB,     "[AP2MCU] OutFirNB")
   TRC_MSG(L1AP2MCU_DEBUGINFO,    "[AP2MCU] DebugInfo")
   TRC_MSG(L1AP2MCU_EMP1,         "[AP2MCU] Digi_DL_Speech %x")
   TRC_MSG(L1AP2MCU_EMP2,         "[AP2MCU] Digi_Microphone %x")
   TRC_MSG(L1AP2MCU_EMP3,         "[AP2MCU] FM_Record_Volume %x")
   TRC_MSG(L1AP2MCU_EMP4,         "[AP2MCU] Bluetooth_Sync_Type %x")
   TRC_MSG(L1AP2MCU_EMP5,         "[AP2MCU] Bluetooth_Sync_Length %x")
   TRC_MSG(L1AP2MCU_EMP6,         "[AP2MCU] bt_pcm_in_vol %x")
   TRC_MSG(L1AP2MCU_EMP7,         "[AP2MCU] bt_pcm_out_vol %x")
   TRC_MSG(L1AP2MCU_EMP8,         "[AP2MCU] uMicbiasVolt %x")  
   TRC_MSG(L1AP2MCU_MODEPARAWB,   "[AP2MCU] ModeParaWB")
   TRC_MSG(L1AP2MCU_INFIRWB,      "[AP2MCU] InFirWB")
   TRC_MSG(L1AP2MCU_OUTFIRWB,     "[AP2MCU] OutFirWB")
   TRC_MSG(L1AP2MCU_DMNRPARANB,   "[AP2MCU] DmnrParaNB")
   TRC_MSG(L1AP2MCU_DMNRPARAWB,   "[AP2MCU] DmnrParaWB")
   TRC_MSG(L1AP2MCU_DEBUG_PRINT0, "[AP2MCU] %d-th")   
   
   // MCU2DSP
   TRC_MSG(L1MCU2DSP_SPEECH_SET_DL_VOLUME, "[MCU2DSP] SPEECH_SET_DL_VOLUME %x %x")
   TRC_MSG(L1MCU2DSP_SPEECH_SET_UL_VOLUME, "[MCU2DSP] SPEECH_SET_UL_VOLUME %x %x")
   TRC_MSG(L1MCU2DSP_DEBUG_PRINT1,         "[MCU2DSP] %x")   
   TRC_MSG(L1MCU2DSP_DEBUG_PRINT2,         "[MCU2DSP] %x %x")   
   TRC_MSG(L1MCU2DSP_DEBUG_PRINT3,         "[MCU2DSP] %x %x %x")   
   TRC_MSG(L1MCU2DSP_DEBUG_PRINT4,         "[MCU2DSP] %x %x %x %x")   
   TRC_MSG(L1MCU2DSP_DEBUG_PRINT5,         "[MCU2DSP] %x %x %x %x %x")   
   TRC_MSG(L1MCU2DSP_COMMONPAR,            "[MCU2DSP] CommonParStruct")     
   TRC_MSG(L1MCU2DSP_EMPCOM,               "[MCU2DSP] EMPCom") 
   TRC_MSG(L1MCU2DSP_SIDETONENB,           "[MCU2DSP] SideToneNB") 
   TRC_MSG(L1MCU2DSP_SIDETONEWB,           "[MCU2DSP] SideToneWB") 
   TRC_MSG(L1MCU2DSP_MODEPAR,              "[MCU2DSP] ModeParStruct")       
   TRC_MSG(L1MCU2DSP_MODEPARANB,           "[MCU2DSP] ModeParaNB") 
   TRC_MSG(L1MCU2DSP_MODEPARAWB,           "[MCU2DSP] ModeParaWB") 
   TRC_MSG(L1MCU2DSP_INFIRNB,              "[MCU2DSP] InFirNB")  
   TRC_MSG(L1MCU2DSP_OUTFIRNB,             "[MCU2DSP] OutFirNB") 
   TRC_MSG(L1MCU2DSP_INFIRWB,              "[MCU2DSP] InFirWB")  
   TRC_MSG(L1MCU2DSP_OUTFIRWB,             "[MCU2DSP] OutFirWB")  
   TRC_MSG(L1MCU2DSP_DEBUGINFO,            "[MCU2DSP] Com[0]=%x DebugInfo[VM_DEBUG_INFO]=%x")
   TRC_MSG(L1MCU2DSP_FUNC1,                "[MCU2DSP] L1SP_UpdateWbSpeechPara")       
   TRC_MSG(L1MCU2DSP_FUNC2,                "[MCU2DSP] L1SP_UpdateSpeechPara")    
   TRC_MSG(L1MCU2DSP_FUNC3,                "[MCU2DSP] SetSpeechEnhancement")      
   TRC_MSG(L1MCU2DSP_FUNC4,                "[MCU2DSP] L1SP_SetDMNRPara") 
   TRC_MSG(L1MCU2DSP_FUNC5,                "[MCU2DSP] L1SP_SetWbDMNRPara")        
   TRC_MSG(L1MCU2DSP_FUNC6,                "[MCU2DSP] L1SP_SetSpeechMode")    
   TRC_MSG(L1MCU2DSP_FUNC7,                "[MCU2DSP] L1SP_Write_Audio_Coefficients") 
   TRC_MSG(L1MCU2DSP_FUNC8,                "[MCU2DSP] L1SP_Write_WB_Audio_Coefficients") 
   TRC_MSG(L1MCU2DSP_FUNC9,                "[MCU2DSP] L1SP_LoadSpeechPara")     
   TRC_MSG(L1MCU2DSP_FUNC10,               "[MCU2DSP] L1SP_SetULAGC") 
   TRC_MSG(L1MCU2DSP_FUNC11,               "[MCU2DSP] SPE_SetULNR") 
   TRC_MSG(L1MCU2DSP_ENHPAR,               "[MCU2DSP] ENHPar UsrMask=%x UsrSubFuncMask=%x AppMask=%x ULSpeAppMask=%x DLSpeAppMask=%x SpeState=%x SpeFlag=%x")            
   

   // L1AUDIO
   TRC_MSG(L1AUDIO_OPEN_FILE, "Enter AUD_Open file, type = %d")
   TRC_MSG(L1AUDIO_OPEN_STREAM, "Enter AUD_Open stream, type = %d")
   TRC_MSG(L1AUDIO_PLAY_FILE, "Enter AUD_Play file, type = %d")
   TRC_MSG(L1AUDIO_PLAY_STREAM, "Enter AUD_Play stream, type = %d")
   TRC_MSG(L1AUDIO_RECORD, "Enter AUD_Record stream, type = %d")
   TRC_MSG(L1AUDIO_PROCESS, "Enter AUD_Process, type = %d")
   TRC_MSG(L1AUDIO_PAUSE, "Enter AUD_Pause, type = %d")
   TRC_MSG(L1AUDIO_RESUME, "Enter AUD_Resume, type = %d")
   TRC_MSG(L1AUDIO_STOP, "Enter AUD_Stop, type = %d")
   TRC_MSG(L1AUDIO_CLOSE, "Enter AUD_Close, type = %d")
   TRC_MSG(L1AUDIO_SEEK, "Enter AUD_Seek, type = %d")
   TRC_MSG(L1AUDIO_SET_START_TIME, "Set audio start time, start time = %d ms, type = %d")
   TRC_MSG(L1AUDIO_SET_STOP_TIME, "Set audio stop time, stop time = %d ms, type = %d")
   TRC_MSG(L1AUDIO_CONTENT, "Enter AUD_GetContentDescInfo, type = %d")

   TRC_MSG(L1AUDIO_INIT_STATE, "Audio function in initial state")
   TRC_MSG(L1AUDIO_RUNNING_STATE, "Audio function in running state")
   TRC_MSG(L1AUDIO_STOP_STATE, "Audio function in stop state")
   TRC_MSG(L1AUDIO_END_STATE, "Audio function in end state")
   TRC_MSG(L1AUDIO_IDLE_STATE, "Audio function in idle state")

   TRC_MSG(L1AUDIO_READ_BYTE, "Read %d bytes from media buffer")
   TRC_MSG(L1AUDIO_WRITE_DSP_FIRST_SEGMENT, "1stDSPStrAddr=%d, Len=%d")
   TRC_MSG(L1AUDIO_WRITE_DSP_SECOND_SEGMENT, "2ndDSPStrAddr=%d, Len=%d")
   TRC_MSG(L1AUDIO_WRITE_MCU_FIRST_SEGMENT, "1st, MBR=%d, %dW")
   TRC_MSG(L1AUDIO_WRITE_MCU_SECOND_SEGMENT, "2nd, MBR=%d, %dW")

   TRC_MSG(L1AUDIO_DSP_ERROR, "ERROR! DSP decodes bitstream")
   TRC_MSG(L1AUDIO_MCU_ERROR, "ERROR! MCU parses packet")
   TRC_MSG(L1AUDIO_READ_FILE_ERROR, "ERROR! File Error = %d")

   //pcm strm drv
   TRC_MSG(L1AUDIO_PCM_STRM_BUF_OVFLOW, "PCM STRM: BUF_OverFlow") 
   TRC_MSG(L1AUDIO_PCM_STRM_IDLE, "PCM STRM: IDLE_STATE")
   TRC_MSG(L1AUDIO_PCM_STRM_END, "PCM STRM: END_STATE")
   TRC_MSG(L1AUDIO_PCM_STRM_RUN, "PCM STRM: RUN_STATE")
   TRC_MSG(L1AUDIO_PCM_STRM_SILENCE, "PCM STRM: Silence %d")
   TRC_MSG(L1AUDIO_PCM_STRM_WDATA_IDMA, "PCM STRM: Addr=%d, Len=%d")

   // AUD RTP
   TRC_MSG(RTP_AUD_CONFIG, "RTP_AAC_Config, SR = %d, FrameDur = %d, channel# = %d")
   TRC_MSG(RTP_AUD_MB_UF, "RTP_MB_UF, pos = %d, type = %d")
   TRC_MSG(RTP_AUD_MB_OF, "RTP_MB_OF, pos = %d, type = %d")
   TRC_MSG(RTP_AUD_PKT_LOSS, "RTP_PKT_LOSS, loss = %d, type = %d")
   TRC_MSG(RTP_AUD_DISCAR, "RTP_PKT_DISCAR, p # = %d, type = %d")
   TRC_MSG(RTP_AUD_PutPktToJitter, "PutPktToJitterBuffer, seq number = %d, jitter count = %d, pos = %d, type = %d")
   TRC_MSG(RTP_AUD_PutPktFromJitter, "PutPktFromJitBufWithSilence, seq number = %d, jitter count = %d, type = %d")
   TRC_MSG(RTP_AUD_PutPkt, "PutPktFromJitBufInOrder, seq number = %d, jitter count = %d, type = %d")
   TRC_MSG(RTP_AUD_GetFromJitter, "Jitter Info, seq number = %d, jitter count = %d, pos = %d")
   TRC_MSG(RTP_AUD_PUTPKT_FST, "RTP_PUTPKT_FST, p # = %d")
   TRC_MSG(RTP_AUD_PUTPKT_FUNC, "RTP_PUTPKT_FUNC, packet# = %d, timestamp = %d, size = %d, type = %d")
   TRC_MSG(RTP_AUD_PUT_SIL, "RTP_Put_Silence, packet# = %d, frames = %d, type = %d")
   TRC_MSG(RTP_AUD_Info, "AAC-LATM_bufSize_Error, seq number = %d, Residual Buffer Size = %d, type = %d")
   TRC_MSG(RTP_AUD_PUT_PKT, "RTP_Put_Packet_To_Buf, packet# = %d, timestamp = %d, type = %d")
   TRC_MSG(RTP_AUD_FRM_IN_BUF, "RTP_Frame_In_Buf, frame count = %d, type = %d")
   TRC_MSG(RTP_AUD_FRM_IN_PKT, "RTP_Frame_In_packet, frame count = %d, type = %d")
   TRC_MSG(RTP_AUD_BUF_STATUS, "RTP_Buffer_Status, CurBufDur = %d, BufTotalSize = %d, BufFreeSize = %d, MinBufTotalDur = %d")
   TRC_MSG(RTP_AUD_CheckPkts, "RTP_AUD_CheckPkts, Start Seq = %d, CurSeqNum = %d, CurWriteIdx = %d, wirteIdx = %d, diff = %d")
   TRC_MSG(RTP_AUD_CHK_PKT, "RTP_AUD_CheckPkt, Start Seq = %d, type = %d")
   TRC_MSG(RTP_AUD_DROP_PKT, "RTP_AUD_DropPkt, Case = %d, type = %d")
   TRC_MSG(RTP_AUD_DRA_ERROR, "RTP_AUD_DRA Error %d")
   TRC_MSG(RTP_AUD_ADD_DELAY_IN, "RTP_AUD_AddDelay Desired %d ms, type = %d")
   TRC_MSG(RTP_AUD_ADD_DELAY_OUT, "RTP_AUD_AddDelay Resulted %d ms, type = %d")
   TRC_MSG(RTP_AUD_AAC_TIMESTAMP_PER_FRAME, "RTP_AUD_AAC Timestamp per frame: %d, aac type: %d (if Generic aac: 4096), IsFIX: %d")
   TRC_MSG(RTP_AUD_AAC_WRONG_SILENCE_FRAME, "RTP_AUD_AAC Wrong Silence Frame, Generic aac with 2048 timestamp/frame")
  
   // APM (Audio Post-Processing Manager)
   TRC_MSG(APM_ACTIVATE_INFO, "APM:Activate Task %d, Sampling Frequency %d, Channels %d")
   TRC_MSG(APM_ACTIVATING, "APM:Activating ID %d")
   TRC_MSG(APM_DEACTIVATE_INFO, "APM:Deactivate Task %d")
   TRC_MSG(APM_DEACTIVATING, "APM:Deactivating ID %d")
   TRC_MSG(APM_REGISTER, "APM:Register ID %d, Original tasks %d")
   TRC_MSG(APM_UNREGISTER, "APM:Unregister ID %d, Original tasks %d")
   TRC_MSG(APM_CLEARBUFFER, "APM:Clear Buffer")
   TRC_MSG(APM_EOF, "APM:EOF task %d")
   TRC_MSG(APM_TRUNCATE, "APM:Truncate outTempBuf")
   TRC_MSG(APM_IN_OVFLOW, "APM: In OVFLOW")
   TRC_MSG(APM_OUT_UDFLOW, "APM: OUT UDFLOW")
   TRC_MSG(APM_BS_DISABLE, "APM: Bessound Disable")
   TRC_MSG(APM_BS_ENABLE, "APM: Bessound enable")
   TRC_MSG(APM_BS_DISABLE_VIDEO, "APM: Bessound Disable in video")
   TRC_MSG(APM_BS_ENABLE_VIDEO, "APM: Bessound enable in video")
   
   // Audio Post Process
   TRC_MSG(L1AUDIO_PP_SET_3D, "Enter AudioPP_Set3D, set 3D effect cofeeicients")
   TRC_MSG(L1AUDIO_PP_SET_TS, "Enter AudioPP_SetTS, set speed mode %d")
   TRC_MSG(L1AUDIO_PP_3D_STATE, "3D effect is in state %d")
   TRC_MSG(L1AUDIO_PP_3D_WAIT_ADDRESS, "3D effect waits DSP for getting address")
   TRC_MSG(L1AUDIO_PP_3D_GET_ADDRESS, "3D effect gets coefficient address")
   TRC_MSG(L1AUDIO_PP_TS_STATE, "TS is in state %d")
   TRC_MSG(L1AUDIO_PP_IN_IDLE, "[AudioPP] AudioPP in Idle")

   // L1SP
   TRC_MSG(L1SP_SET_MODE, "L1SP set mode=%d, spk_lev=%d, mic_lev=%d")
   TRC_MSG(L1SP_APPLY_MODE, "L1SP on=%d, mode=%d, spk_lev=%d, mic_lev=%d")
   TRC_MSG(L1SP_SPEECH_ENHANCEMENT, "L1SP turn on speech enhancement, m0=%d, m1=%d, c0=%d, c1=%d")
   TRC_MSG(L1SP_WB_SPEECH_ENHANCEMENT, "L1SP Set WB Par, m0=%d, m1=%d, m2=%d, m3=%d")
   TRC_MSG(L1SP_WB_FILTER_COEFF,"L1SP Write WB filter input %d %d %d, output %d %d %d")
   TRC_MSG(L1SP_SET_MIC_VOL, "L1SP Set Mic Vol %d, sph_par %d")
   TRC_MSG(L1SP_ENABLE_DUAL_MIC_NR, "L1SP Set Dual Mic NR %d")
   TRC_MSG(L1SP_ADAPT_MIC_VOL, "L1SP Adapt Mic Vol %d")
   TRC_MSG(L1SP_INC_SPK_VOL, "L1SP DSP Inc Spk Vol to %d, report %d")
   TRC_MSG(L1SP_DEC_SPK_VOL, "L1SP DSP Dec Spk Vol to %d, report %d")
   TRC_MSG(L1SP_Mute_PCM_Ouput_Port, "L1SP Mute PCM Output Port: %d")
	
   TRC_MSG(L1SP_DMNR_LOOPBACK_FROM_MIC,            "[DMNR Loopback]FromMic %d %d %d %d")
   TRC_MSG(L1SP_DMNR_LOOPBACK_SKIP_MIC,            "[DMNR Loopback]Skip FromMic")
   TRC_MSG(L1SP_DMNR_LOOPBACK_TO_SE,               "[DMNR Loopback]ToSE %d %d %d %d")
   TRC_MSG(L1SP_DMNR_LOOPBACK_FILL_SE,             "[DMNR Loopback]FillSE")
   TRC_MSG(L1SP_DMNR_LOOPBACK_FROM_SD,             "[DMNR Loopback]FromSD %d %d %d %d")
   TRC_MSG(L1SP_DMNR_LOOPBACK_SKIP_SD,             "[DMNR Loopback]Skip FromSD")
   TRC_MSG(L1SP_DMNR_LOOPBACK_TO_SPK,              "[DMNR Loopback]ToSPK %d %d %d %d")
   TRC_MSG(L1SP_DMNR_LOOPBACK_FILL_SPK,            "[DMNR Loopback]FillSpk")
   TRC_MSG(L1SP_DMNR_LOOPBACK_UL_DL_INDEX,         "[DMNR Loopback]Dw, Dr, Uw, Ur %d %d %d %d")
   TRC_MSG(L1SP_DMNR_LOOPBACK_ILLEGAL_OPEN,        "[DMNR Loopback]illegal DMNR Loopback open")
   TRC_MSG(L1SP_DMNR_LOOPBACK_ILLEGAL_CLOSE,       "[DMNR Loopback]illegal DMNR Loopback close")
   TRC_MSG(L1SP_SET_MIC_GAIN_CONTROL,              "[MIC GAIN CONTROL]L1SP set mic gain control %x")
   TRC_MSG(L1SP_ADAPT_MIC_GAIN_CONTROL,            "[MIC GAIN CONTROL]L1SP adapt mic gain control %x")
   TRC_MSG(L1SP_SET_ENH_FIR, "SPH[ENH] enhancement mode %d, enhance Index %d, inFIR Index %d, outFIR Index %d, updateMaskto value %d")
   TRC_MSG(L1SP_USELESS_SET, "SPH[ENH] %d, %d, %d, %d")
   TRC_MSG(L1SP_UPDATE_SPE_APP_MASK, "SPH[ENH]APP- Update all/ul/dl type=%d spe app mask[%d], spe usr mask[%d], flags=%x, on/off=%d") // for first param, 0 for all, 1 for ul, 2 for dl
   TRC_MSG(L1SP_UPDATE_SPE_USR_MASK, "SPH[ENH]USR- Update all/ul/dl type=%d spe app mask[%d], spe usr mask[%d], newValue=%x, on/off/Old=%d") // for first param, 0 for all, 1 for ul, 2 for dl
   
   TRC_MSG(L1SP_DEBUG_COMMON_PARAM, "common Param: [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d")
   TRC_MSG(L1SP_DEBUG_ENH_MODE_PARAM, "enhance mode Param: [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d")
   TRC_MSG(L1SP_DEBUG_ENH_UL_SWITCH, "enhance UL switch: [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d")
   TRC_MSG(L1SP_DEBUG_ENH_DL_SWITCH, "enhance DL switch: [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d")
   TRC_MSG(L1SP_DEBUG_DMNR_CAL, "DMNR: [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d")
   TRC_MSG(L1SP_DEBUG_WB_DMNR_CAL, "WB DMNR: [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d")
   TRC_MSG(L1SP_DEBUG_UL_FIR, "UL FIR: [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d")
   TRC_MSG(L1SP_DEBUG_DL_FIR, "DL FIR: [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d")
   TRC_MSG(L1SP_DEBUG_UL_WB_FIR, "UL WB FIR: [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d")
   TRC_MSG(L1SP_DEBUG_DL_WB_FIR, "DL WB FIR: [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d, [m%d]=%d")

   
   TRC_MSG(TONE_STOP_AND_WAIT, "TONE_StopAndWait")
   TRC_MSG(KT_STOP_AND_WAIT, "KT_StopAndWait")

   // VoRTP
   TRC_MSG(VORTP_ENTER_STARTTONE, "[VoRTP] Enter StartInbandTone; f1=%d, f2=%d, dB=%d, dura=%d")
   TRC_MSG(VORTP_ENTER_STOPTONE, "[VoRTP] Enter StopInbandTone")
   TRC_MSG(VORTP_UL_ENTER_OPEN, "[VoRTP] Enter OpenULChannel")
   TRC_MSG(VORTP_UL_ENTER_CONFIG, "[VoRTP] Enter UL::Config; type=%d, sid=%d")
   TRC_MSG(VORTP_UL_ENTER_SETBUFFER, "[VoRTP] Enter UL::SetBuffer; size=%d")
   TRC_MSG(VORTP_UL_ENTER_START, "[VoRTP] Enter UL::Start; sid=%d, ts=%d")
   TRC_MSG(VORTP_UL_ENTER_STOP, "[VoRTP] Enter UL::Stop; sid=%d")
   TRC_MSG(VORTP_UL_ENTER_CLOSE, "[VoRTP] Enter UL::Close")
   TRC_MSG(VORTP_UL_ENTER_SETMIX, "[VoRTP] Enter UL::SetMix; val=%d")
   TRC_MSG(VORTP_DL_ENTER_OPEN, "[VoRTP] Enter OpenDLChannel")
   TRC_MSG(VORTP_DL_ENTER_CONFIG, "[VoRTP] Enter DL::Config; type=%d, sid=%d")
   TRC_MSG(VORTP_DL_ENTER_SETBUFFER, "[VoRTP] Enter DL::SetBuffer; size=%d")
   TRC_MSG(VORTP_DL_ENTER_START, "[VoRTP] Enter DL::Start; sid=%d")
   TRC_MSG(VORTP_DL_ENTER_STOP, "[VoRTP] Enter DL::Stop; sid=%d")
   TRC_MSG(VORTP_DL_ENTER_CLOSE, "[VoRTP] Enter DL::Close")
   TRC_MSG(VORTP_JITTER_INFO, "[VoRTP] DL-Jitter; sid=%d, depth=%d, curJit=%d, old_ts=%d, new_ts=%d")
   TRC_MSG(VORTP_JITTER_OVERRUN, "[VoRTP] DL-Jitter; sid=%d, overrun=%d")
   TRC_MSG(VORTP_JITTER_PREBUF, "[VoRTP] DL-Jitter; sid=%d, prebuf=%d, fn=%d")
   TRC_MSG(VORTP_DL_ARRIVAL, "[VoRTP] DL-Arrival; sid=%d, seq=%d, ts=%d, type=%d, payload_sz=%d, pt=%d, m=%d")
   TRC_MSG(VORTP_DL_PLAY, "[VoRTP] DL-Play; sid=%d, seq=%d, ts=%d, type=%d, payload_sz=%d, pt=%d, m=%d")
   TRC_MSG(VORTP_UL_BORN, "[VoRTP] UL-Born; sid=%d, ts=%d, type=%d, payload_sz=%d, m=%d")
   TRC_MSG(VORTP_UL_SENT, "[VoRTP] UL-Sent; sid=%d, ts=%d, type=%d, payload_sz=%d, m=%d")
   TRC_MSG(VORTP_DL_INFO1, "[VoRTP] DL-Info; sid%d, arriv=%d, play=%d, miss=%d")
   TRC_MSG(VORTP_JITTER_BURST, "[VoRTP] DL-Burst; sid%d, curJit=%d, prevMaxJit=%d, latestBurstJit=%d")
   TRC_MSG(VORTP_JITTER_BURST_STATE, "[VoRTP] DL-Burst; sid=%d, isBurstState=%d")

   TRC_MSG(VORTP_CODEC_REG_G711, "[VoRTP] REG g711 cn=%d")
   TRC_MSG(VORTP_CODEC_REG_G726_16, "[VoRTP] REG g726_16 cn=%d")
   TRC_MSG(VORTP_CODEC_REG_G726_24, "[VoRTP] REG g726_24 cn=%d")
   TRC_MSG(VORTP_CODEC_REG_G726_32, "[VoRTP] REG g726_32 cn=%d")
   TRC_MSG(VORTP_CODEC_REG_G726_40, "[VoRTP] REG g726_40 cn=%d")
   TRC_MSG(VORTP_CODEC_REG_G729, "[VoRTP] REG g729 annexb=%d")
   TRC_MSG(VORTP_CODEC_REG_G7231, "[VoRTP] REG g7231 annexa=%d, bitrate=%d")
   
   TRC_MSG(VORTP_DUPLICATE_PACKET, "[VoRTP] Warning: src packet size = %d, dest array size = %d")

   TRC_MSG(VORTP_DUR_SYSTIME, "[VoRTP] warning:dur_systime=%d")
   TRC_MSG(VORTP_UL_START, "[VoRTP] vortp_ul_Start: %d B")
   TRC_MSG(VORTP_DL_START, "[VoRTP] vortp_dl_Start: %d B")
   TRC_MSG(VORTP_DUR_FTJBC_ON, "[VoRTP] FTJBC on")
   TRC_MSG(VORTP_DUR_FTJBC_OFF, "[VoRTP] FTJBC off")
   TRC_MSG(VORTP_SRC_CANNOT_OPEN, "[VoRTP] autorec: source file can't open")
   TRC_MSG(VORTP_VOIP_AUTOREC_STOP, "[VoRTP] VoIP auto recording stop")
   TRC_MSG(VORTP_CONTEXT, "[VoRTP] context.audId=%d, VoRTP_context.numStreams=%d")
   TRC_MSG(VORTP_UL_STATE, "[VoRTP] UL%d: state=%d, sid=%d")
   TRC_MSG(VORTP_UL_FIFO, "[VoRTP] UL%d fifo: read=%d, write=%d")
   TRC_MSG(VORTP_DL_STATE, "[VoRTP] DL%d: state=%d, sid=%d")
   TRC_MSG(VORTP_SYS_SAVE, "[VoRTP] sys.save = %d")
   TRC_MSG(VORTP_SYS_LOOPBACK, "[VoRTP] sys.loopback = %d")
   TRC_MSG(VORTP_SYS_AUTOREC, "[VoRTP] sys.autorec = %d/%d, %d")
   TRC_MSG(VORTP_IS_REC_PCM, "[VoRTP] is_rec_pcm = %d")
   TRC_MSG(VORTP_IS_REC_DL, "[VoRTP] is_rec_dl = %d")
   TRC_MSG(VORTP_IS_REC_UL, "[VoRTP] is_rec_ul = %d")
   TRC_MSG(VORTP_SYS_JITTER, "[VoRTP] sys.jitter = %d, %d")
   TRC_MSG(VORTP_JITTER_VAR_MUL, "[VoRTP] jitter_var_mul = %d")
   TRC_MSG(VORTP_JITTER_MEAN_RUN, "[VoRTP] jitter_mean_run = %d")
   TRC_MSG(VORTP_OPEN_SUCCESS, "[VoRTP] open %d success")
   TRC_MSG(VORTP_OPEN_FAIL, "[VoRTP] open %d fail")
   TRC_MSG(VORTP_QUERY_RESULT, "[VoRTP] query %d result - %d,%d,%d,%d")
   TRC_MSG(VORTP_QUERY_G729_FAIL, "[VoRTP] query %d g729 result fail")
   TRC_MSG(VORTP_QUERY_G729_RESULT, "[VoRTP] query %d g729 result - ptime=%d, maxptime=%d, annexb=%d")
   TRC_MSG(VORTP_QUERY_G7231_FAIL, "[VoRTP] query %d g7231 result fail")
   TRC_MSG(VORTP_QUERY_G7231_RESULT, "[VoRTP] query %d g7231 result - ptime=%d, maxptime=%d, annexa=%d")
   TRC_MSG(VORTP_QUERY_G726_32_FAIL, "[VoRTP] query %d g726_32 result fail")
   TRC_MSG(VORTP_QUERY_G726_32_RESULT, "[VoRTP] query %d g726_32 result - ptime=%d, maxptime=%d, cn=%d")  
   TRC_MSG(VORTP_QUERY_G711_A_FAIL, "[VoRTP] query %d g711_a result fail")
   TRC_MSG(VORTP_QUERY_G711_A_RESULT, "[VoRTP] query %d g711_a result - ptime=%d, maxptime=%d, cn=%d") 
   TRC_MSG(VORTP_UNKNOWN_CODEC, "[VoRTP] unknown codec") 
   TRC_MSG(VORTP_CONFIG_UL_FAIL, "[VoRTP] config %d uplink fail - %d") 
   TRC_MSG(VORTP_CONFIG_DL_FAIL, "[VoRTP] config %d downlink fail - %d") 
   TRC_MSG(VORTP_CONFIG_OK, "[VoRTP] config %d ok") 
   TRC_MSG(VORTP_SETBUF_UL_FAIL, "[VoRTP] setbuffer %d uplink fail - %d") 
   TRC_MSG(VORTP_SETBUF_UL_OK, "[VoRTP] setbuffer_ul %d, %d ok") 
   TRC_MSG(VORTP_SETBUF_DL_FAIL, "[VoRTP] setbuffer %d downlink fail - %d") 
   TRC_MSG(VORTP_SETBUF_DL_OK, "[VoRTP] setbuffer_dl %d, %d ok") 
   TRC_MSG(VORTP_START_UL_FAIL, "[VoRTP] start %d uplink fail - %d") 
   TRC_MSG(VORTP_START_DL_FAIL, "[VoRTP] start %d downlink fail - %d")
   TRC_MSG(VORTP_START_OK, "[VoRTP] start %d ok")
   TRC_MSG(VORTP_STOP_UL_FAIL, "[VoRTP] stop %d uplink fail - %d")
   TRC_MSG(VORTP_STOP_DL_FAIL, "[VoRTP] stop %d downlink fail - %d")   
   TRC_MSG(VORTP_STOP_OK, "[VoRTP] stop %d ok")  
   TRC_MSG(VORTP_CLOSE_UL_FAIL, "[VoRTP] close %d uplink fail - %d")  
   TRC_MSG(VORTP_CLOSE_DL_FAIL, "[VoRTP] close %d downlink fail - %d")
   TRC_MSG(VORTP_CLOSE_OK, "[VoRTP] close %d ok")  
   TRC_MSG(VORTP_TONEON_OK, "[VoRTP] toneon ok")
   TRC_MSG(VORTP_TONEON_FAIL, "[VoRTP] toneon fail - %d")
   TRC_MSG(VORTP_TONEOFF_OK, "[VoRTP] toneoff OK")
   TRC_MSG(VORTP_TONEOFF_FAIL, "[VoRTP] toneoff fail - %d")
   TRC_MSG(VORTP_UNKNOWN_COMMAND, "[VoRTP] unknown command")

   // DAF stream sender over RTP
   TRC_MSG(ENTER_A2DP_DAF_OPEN, "Enter A2DP_DAF_Open")
   TRC_MSG(ENTER_A2DP_DAF_CLOSE, "Enter A2DP_DAF_Close")
   TRC_MSG(DAFRTP_PUTDATA, "DAFRTP PutData, putlen=%d, elapsed: %d, wait: %d")
   TRC_MSG(DAFRTP_GETDATA, "DAFRTP GetData, buflen=%d, getlen: %d, elapsed: %d, sample: %d, header: %d")
   TRC_MSG(DAFRTP_FRAMESYNC, "DAFRTP FrameSync, skip=%d, framelen: %d, bitrate: %d")

// Audio Cache
   TRC_MSG(L1AUDIO_SET_CACHE_TBL, "Set Cache Table, type = %d")
   TRC_MSG(L1AUDIO_BUILD_CACHE, "Build Cache, type = %d, Ret = %d, Prog = %d")
   TRC_MSG(L1AUDIO_CACHE_STROFFSET, "Cache_Start_Offset, type = %d, idx = %d, offset = %d")
   TRC_MSG(L1AUDIO_CACHE_ACCFRAME, "Cache_Accumulated_Frame, type = %d, idx = %d, frame = %d")
   TRC_MSG(L1AUDIO_CACHE_FINISH_RETURN, "Cache Finished Return, type = %d")
   TRC_MSG(L1AUDIO_CACHE_END, "Cache End, type = %d, total frame = %d")
   TRC_MSG(L1AUDIO_CACHE_FAILED, "Cache Fail, type = %d, total frame = %d")
   TRC_MSG(L1AUDIO_SEEK_RESULT, " Seek Result, type=%d, Start Frame=%d, Offset=%d, ST(ms)=%d")
   TRC_MSG(L1AUDIO_SEEK_FAIL, " Seek Fail, type=%d, Start Frame=%d, Offset=%d, ST(ms)=%d")
   TRC_MSG(L1AUDIO_CACHE_GET_DUR, "Cache_Get_Duration, type = %d, dur = %d")
   TRC_MSG(L1AUDIO_CACHE_GET_DUR_F, "Cache_Get_Duration_F, type = %d, dur = %d")
   TRC_MSG(L1AUDIO_CACHE_GET_TOTAL_DUR, "Cache_Get_Total_Duration, type = %d, dur = %d")
   TRC_MSG(L1AUDIO_CACHE_FILE_SIZE, "File Size, type = %d, file size = %d")

// AST
   TRC_MSG(L1AUDIO_AST_INIT, "[AST]Initial AST, Entry Number = %d, BufSize = %u")
   TRC_MSG(L1AUDIO_AST_FRAME_PER_ENTRY, "[AST]AST Entry Size, frame number = %u")  
   TRC_MSG(L1AUDIO_AST_BUILD_TABLE, "[AST]Build AST Parsing Frame, Result = %u, Demand Parse frame = %u, Actual Parse frame = %u")      
   TRC_MSG(L1AUDIO_AST_SEEK, "[AST]Seek in AST, destiny frame = %u, actual achieve frame = %u, offset = %u")   
   TRC_MSG(L1AUDIO_AST_GET_INDEXED_FRAME, "[AST]Indexed Frame in AST: frame = %u")   
   TRC_MSG(L1AUDIO_AST_GET_TOTAL_FRAME, "[AST]Estimated Total Frames: frame = %u")
   TRC_MSG(L1AUDIO_AST_UPDATE_TABLE, "[AST]Update AST table, Index = %u, Frame = %u, Offset = %u")  

// TTS
   TRC_MSG(TTS_TEXT_CONTENT, "TTS Content")
   TRC_MSG(TTS_IFLYTTS, "iFlyTTS Output=%d")
   TRC_MSG(TTS_SPCM_BUF, "Spcm Buf ptr=%x,len=%d")
   TRC_MSG(TTS_TASK_DONE, "TTS Task done %d")
   TRC_MSG(TTS_GET_DATA, "TTS GetData len=%d")
   TRC_MSG(TTS_PUT_SPCM, "JTTs put Spcm %d data")
   TRC_MSG(TTS_SET_BUF, "TTS SetBuffer %d")
   TRC_MSG(TTS_PLAY, "TTS Play")
   TRC_MSG(TTS_TDIC_ERR, "TDic Err =%d")
   TRC_MSG(TTS_JTTS_ERR, "jTTS Err =%d")
   TRC_MSG(TTS_TTS_STATE, "TTS state %d")
   TRC_MSG(TTS_TRC_PAUSE, "TTS Pause")
   TRC_MSG(TTS_RESUME, "TTS Resume")
   TRC_MSG(TTS_ENTER_STOP, "TTS enter Stop")
   TRC_MSG(TTS_LEAVE_STOP, "TTS leave Stop")
   TRC_MSG(TTS_CLOSE, "TTS Close")
   TRC_MSG(TTS_TDIC_SETPITCH, "TDIC SetPitch %d")
   TRC_MSG(TTS_SET_SPEED, "TTS SetSpeed %d")
   TRC_MSG(TTS_SET_VOL, "TTS SetVol %d")
   TRC_MSG(TTS_SPCM_EVENT, "TTS spcm_event %d")
   TRC_MSG(TTS_PRC_MED_END, "TTS PRC MED END")
   TRC_MSG(TTS_TDIC_GET_DATA, "TDIC get %d data%d, remain %d")
   TRC_MSG(TTS_TDIC_GET_NODATA, "TDIC Get No Data")
   TRC_MSG(TTS_TDIC_RPC_DONE, "TDIC PRC done")
   TRC_MSG(TTS_TDIC_RPC_NEED, "TDIC PRC needed")
   TRC_MSG(TTS_TDIC_RPC_DATA, "TDIC PRC data")
   TRC_MSG(TTS_TDIC_ERR_CODE, "TDic error code = %d")
   TRC_MSG(TTS_SET_ATTR, "TTSSetAttr id %x, val %x")
   
// 3G speech
   TRC_MSG(SP3G_RAB_EST, "SP3G CSR notify RAB establish with codec %MtSP3G_SpeechCodecType")
   TRC_MSG(SP3G_RAB_DEEST, "SP3G CSR notify RAB De-establish")
   TRC_MSG(SP3G_TX_SID_FIRST, "SP3G_HISR TX SID FISRT")
   TRC_MSG(SP3G_TX_SID_UPDATE, "SP3G_HISR TX SID UPDATE")
   TRC_MSG(SP3G_RX_SPEECH_GOOD, "SP3G_HISR RX SPEECH GOOD")
   TRC_MSG(SP3G_RX_SPEECH_BAD, "SP3G_HISR RX SPEECH BAD")
   TRC_MSG(SP3G_RX_FORCE_NO_DATA_WHEN_CHANGE_BAND, "SP3G_HISR RX Band Change,force speech frame to NO_DATA")
   TRC_MSG(SP3G_RX_SID_FIRST, "SP3G_HISR RX SID FISRT")
   TRC_MSG(SP3G_RX_SID_UPDATE, "SP3G_HISR RX SID UPDATE")
   TRC_MSG(SP3G_RX_NO_DATA, "SP3G_HISR RX GET NO DATA FRAME")
   TRC_MSG(SP3G_DTX_NO_DATA, "SP3G_HISR INSERT NO DATA")
   TRC_MSG(SP3G_BUFFER_STATUS, "SP3G_HISR DL r = %d, w = %d, num = %d, 1st byte = %x")
   TRC_MSG(SP3G_UL_DELAY, "SP3G UL delay %d")
   TRC_MSG(SP3G_REQUEST, "SP3G Request")
   TRC_MSG(SP3G_REQUEST_UL_FRAME_TYPE, "SP3G set UL frame type %MtSP3G_SpeechCodecType")
   TRC_MSG(SP3G_UL_START_GET_SPEECH_FRAME, "SP3G UL GetSpFrame start")
   TRC_MSG(SP3G_UL_GET_SPEECH_FRAME, "SP3G UL GetSpFrame type %d, len %d, %hx %hx")
   TRC_MSG(SP3G_DL_BUFFER_FINISH, "SP3G DL Buffering finished")
   TRC_MSG(SP3G_DL_PUT_SPEECH_FRAME, "SP3G DL sub_flow %d, frame_type %MtSP3G_SpeechCodecType, crc_status %d")
   TRC_MSG(SP3G_LOG_L1_INFO, "SP3G CFN=%x, l1info=%x, crc = %x, s_val =%x, %x, %x")
   TRC_MSG(SP3G_L1A_UPDATE_INFO, "SP3G Update Info bitmap %d, val %d")
   TRC_MSG(SP3G_INVALID_UL_CODEC_MODE, "SP3G invalid UL codec mode %d")
   TRC_MSG(SP3G_SET_DTX, "SP3G Set DTX %d")
   
   TRC_MSG(SP3G_UL_BIT_TRUE_DSP_F8, "SP3G_HISR UL DSP len %d, %hx %hx %hx %hx %hx %hx %hx %hx")
   TRC_MSG(SP3G_UL_BIT_TRUE_DSP_N8, "SP3G_HISR UL DSP %hx %hx %hx %hx %hx %hx %hx %hx")
   TRC_MSG(SP3G_TX_SPEECH_GOOD, "SP3G_HISR UL is TX_SPEECH_GOOD")
   TRC_MSG(SP3G_UL_NO_DATA, "SP3G_HISR UL is NO DATA")
   TRC_MSG(SP3G_UL_BIT_TRUE_F8, "SP3G_HISR=%d UL Type %d, Frm %hx %hx %hx %hx %hx %hx %hx %hx")
   TRC_MSG(SP3G_UL_BIT_TRUE_N13, "SP3G UL %hx %hx %hx %hx %hx %hx %hx %hx %hx %hx %hx %hx %hx")
   TRC_MSG(SP3G_UL_BUFFER, "SP3GVT UL cnt=%d,r=%d,w=%d")
   TRC_MSG(SP3G_DL_BIT_TRUE, "SP3G_HISR DL Type %d, Frm %x %x %x %x %x")
   TRC_MSG(SP3G_DL_BIT_TRUE_TASK, "SP3G DL Frm CFN =%x, %x %x %x %x %x")
   TRC_MSG(SP3G_DL_BIT_TRUE_DSP_F8, "SP3G_HISR DL DSP len %d, %hx %hx %hx %hx %hx %hx %hx %hx") 
   TRC_MSG(SP3G_DL_BIT_TRUE_DSP_N8, "SP3G_HISR DL DSP %hx %hx %hx %hx %hx %hx %hx %hx")
   TRC_MSG(SP3GVT_FAKE_NODATA, "SP3GVT Fake NoData")
   
   //VT
   TRC_MSG(SP3GVT_UL_GET_SPEECH_FRAME, "SP3GVT UL GetSpFrm, CurFrmCount %d")
   TRC_MSG(SP3GVT_UL_FRAME_INFO, "SP3GVT UL Frm len %d, first 3 byte %x %x %x")
   TRC_MSG(SP3GVT_DL_FRAME_INFO, "SP3GVT DL Frm len %d, first 3 byte %x %x %x")
   TRC_MSG(SP3GVT_DL_FRAME_ERROR, "SP3GVT DL FrmType Err Warning %d !!")
   TRC_MSG(SP3GVT_SET_DELAY, "SP3GVT SetDelay %d ms, about %d frame")
   
   //VM
   TRC_MSG(VM_CONTROL, "vm_con : %x")
   
   // CCCI Message
   TRC_MSG(L1AUDIO_RECEIVE_COMMAND, "SPC rece Msg 0x%08X [(%d)%MSPC_MSG_ID_T][(%d)%MAUD_CCCI_MSG_TYPE_T][(%d)%MAUD_CCCI_MSG_T]")
   TRC_MSG(L1AUDIO_RECEIVE_DATA_NOTIFY, "SPC rece data_ntf 0x%08X [(%d)%MSPC_MSG_ID_T][(%d)%MAUD_CCCI_MSG_TYPE_T][(%d)%MAUD_CCCI_MSG_T], offset 0x%x, len 0x%x")
   TRC_MSG(L1AUDIO_PROCESS_COMMAND, "SPC proc Msg 0x%08X [(%d)%MSPC_MSG_ID_T][(%d)%MAUD_CCCI_MSG_TYPE_T][(%d)%MAUD_CCCI_MSG_T]")
   TRC_MSG(L1AUDIO_PEOCESS_DATA_NOTIFY, "SPC proc data_ntf 0x%08X [(%d)%MSPC_MSG_ID_T][(%d)%MAUD_CCCI_MSG_TYPE_T][(%d)%MAUD_CCCI_MSG_T], offset 0x%x, len 0x%x")
   TRC_MSG(L1AUDIO_SEND_M2A_MESSAGE, "SPC send M2A message 0x%08X")
   TRC_MSG(L1AUDIO_SEND_M2A_MESSAGE_FAIL, "SPC send M2A message 0x%08X fail, ret %d")
   TRC_MSG(L1AUDIO_ENTER_MSG_HANDLER, "SPC Enter MsgHandler V2")
   TRC_MSG(L1AUDIO_LEAVE_MSG_HANDLER, "SPC Leave MsgHandler V2")
   TRC_MSG(L1AUDIO_CUSTOM_PARAM, "aud customize %d, receive %d, in position %d")
   TRC_MSG(L1AUDIO_SPC_M2A_DROP, "M2A MSG DROP %d")
   TRC_MSG(L1AUDIO_SPC_A2M_ILLEGAL, "Illegal A2M message %x")
   
   // MIDI DSPSYN
   TRC_MSG(MIDI_DSPSYN_ENDHDL_IDLE,"DSP Idle")
   TRC_MSG(MIDI_DSPSYN_ENDHDL_END,"CallEndHdlr")
   TRC_MSG(MIDI_DSPSYN_TICK_END,"DSP Ending")
   TRC_MSG(MIDI_DSPSYN_TICK_TERMINATE,"DSP Terminating")
   TRC_MSG(MIDI_DSPSYN_START,"DStart state = %x, condition = %d")
   TRC_MSG(MIDI_DSPSYN_START_TERMINATE,"PutTermCmd")
   TRC_MSG(MIDI_DSPSYN_GETCHANNEL,"GetCh %d")
   TRC_MSG(MIDI_DSPSYN_SETCHANNEL,"SetCh %d")
   TRC_MSG(MIDI_DSPSYN_GETSTOPCMD,"GotStopCmd %d->%d, head=%d, tail=%d")
   TRC_MSG(MIDI_DSPSYN_GETENDCMD,"GotEndCmd %d->%d, head=%d, tail=%d")
   
   // MIDI JWAV
   TRC_MSG(MIDI_JWAV_OPEN,"JWOpen, handle = %d")
   TRC_MSG(MIDI_JWAV_CLOSE,"JWCls, handle = %d")
   TRC_MSG(MIDI_JWAV_PLAY,"JWPlay, handle = %d")
   TRC_MSG(MIDI_JWAV_STOP,"JWStop, handle = %d")
   TRC_MSG(MIDI_JWAV_GETCOMMAND,"JWSFlag handle = %d, stop type =  %d")
   TRC_MSG(MIDI_JWAV_GETSTOPCMD,"Get Command JWStop, handle = %d")
   TRC_MSG(MIDI_JWAV_GETENDCMD,"Get JWEnd, handle = %d")
   TRC_MSG(MIDI_JWAV_GETREPEATCMD,"Get JWRep, handle = %d")
   TRC_MSG(MIDI_JWAV_ENDHDL,"JWEHnd, handle =  %d")

   //DAF
   TRC_MSG(DAF_L1AUDIO_STOP_TIME_UP_STATE, "DAF_L1AUDIO_STOP_TIME_UP_STATE")
   TRC_MSG(DAF_L1AUDIO_IDLE_STATE, "DAF_L1AUDIO_IDLE_STATE")
   TRC_MSG(DAF_L1AUDIO_END_STATE, "DAF_L1AUDIO_END_STATE")
   TRC_MSG(DAF_L1AUDIO_FRAME_LENGTH_TBL0, "DAF_L1AUDIO_FRAME_LENGTH_TBL 01~15:%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d") 
   TRC_MSG(DAF_L1AUDIO_FRAME_LENGTH_TBL1, "DAF_L1AUDIO_FRAME_LENGTH_TBL 16~30:%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d")
   TRC_MSG(DAF_L1AUDIO_FRAME_LENGTH_TBL2, "DAF_L1AUDIO_FRAME_LENGTH_TBL 31~15:%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d")
   TRC_MSG(DAF_L1AUDIO_FIRSTWORD_POSITION, "DAF_L1AUDIO_FIRSTWORD_POSITION : %d")
   
   //AWBPLUS
   TRC_MSG(AWBPLUS_L1AUDIO_STOP_TIME_UP_STATE, "AWBPLUS_L1AUDIO_STOP_TIME_UP_STATE")
   TRC_MSG(AWBPLUS_L1AUDIO_IDLE_STATE, "AWBPLUS_L1AUDIO_IDLE_STATE")
   TRC_MSG(AWBPLUS_L1AUDIO_END_STATE, "AWBPLUS_L1AUDIO_END_STATE")

   //MDCI
   TRC_MSG(L1AUDIO_MDCI_M2D_MSG,"Send M2D Msg 0x%X %ML1AUDIO2FAS_AUDIO_MSG, msgData32= 0x%X, r = 0x%X, w = 0x%X, ret = 0x%X")
   TRC_MSG(L1AUDIO_MDCI_D2M_MSG,"Rece D2M Msg 0x%X %MSAC2L1AUDIO_AUDIO_MSG, msgData32= 0x%X, r = 0x%X, w = 0x%X")
   TRC_MSG(L1AUDIO_MDCI_PROCESS_D2M_MSG,"Proc D2M Msg 0x%X, %MSAC2L1AUDIO_AUDIO_MSG, msgData16 = 0x%X, msgData32 = 0x%X")
   TRC_MSG(L1AUDIO_MDCI_ERR_MSG,"mdciErrMsg = %d")

   //AAC
   TRC_MSG(AAC_L1AUDIO_IDLE_STATE, "AAC_L1AUDIO_IDLE_STATE")
   TRC_MSG(AAC_L1AUDIO_END_STATE, "AAC_L1AUDIO_END_STATE")
   TRC_MSG(AAC_L1AUDIO_STOP_TIME_UP_STATE, "AAC_L1AUDIO_STOP_TIME_UP_STATE")
   TRC_MSG(AAC_L1AUDIO_ERROR_REPORT, "AAC_Error %d")


   //WMA
   TRC_MSG(WMA_L1AUDIO_IDLE_STATE, "WMA_L1AUDIO_IDLE_STATE")
   TRC_MSG(WMA_L1AUDIO_END_STATE, "WMA_L1AUDIO_END_STATE")
   TRC_MSG(WMA_L1AUDIO_STOP_TIME_UP_STATE, "WMA_L1AUDIO_STOP_TIME_UP_STATE")

   //WAV
   TRC_MSG(WAV_L1AUDIO_IDLE_STATE, "WAV_L1AUDIO_IDLE_STATE")
   TRC_MSG(WAV_L1AUDIO_END_STATE, "WAV_L1AUDIO_END_STATE")
   TRC_MSG(WAV_L1AUDIO_INIT_STATE, "WAV_L1AUDIO_INIT_STATE")  
   TRC_MSG(WAV_L1AUDIO_TIME_UP_STATE, "WAV_L1AUDIO_TIME_UP_STATE")
   TRC_MSG(WAV_L1AUDIO_BUF_UF, "WAV_L1AUDIO_BUF_UF")
   TRC_MSG(WAV_L1AUDIO_FREQ_CHANNEL, "WAV_L1AUDIO_FREQ_CHANNEL: WAV: Freq %d, Channel %d")
   
   //tone_loopback_Rec
   TRC_MSG(L1AUDIO_TONE_LOOPBACK_REC_CALLBACK_MODE, "TONE_LOOPBACK_REC: callback Mode=%d")
   TRC_MSG(L1AUDIO_TONE_LOOPBACK_REC_MODE, "TONE_LOOPBACK_REC: Mode=%d")  

   //I2S
   TRC_MSG(L1AUDIO_I2S_ENABLE, "[I2S]enable, I2S mode %d enable, sr = %d")  
   TRC_MSG(L1AUDIO_I2S_DISABLE, "[I2S]disable")
   TRC_MSG(L1AUDIO_I2S_REC_INIT, "[I2S]init, TCM ptr= %d, TCM size for i2srec= %d")
   TRC_MSG(L1AUDIO_I2S_REC_ACTIVATE, "[I2S]activate, use TCM: %d, encMemSIze: %d")
   TRC_MSG(L1AUDIO_I2S_REC_DEACTIVATE, "[I2S]deactivate")
   
   TRC_MSG(L1AUDIO_I2S_REC_ON, "[I2S]record on")
   TRC_MSG(L1AUDIO_I2S_REC_OFF, "[I2S]record off")
   TRC_MSG(L1AUDIO_I2S_REC_REC_OF, "[I2S]medbuf OF, freespace(word):%d, required(word):")
   TRC_MSG(L1AUDIO_I2S_REC_PROCESS, "[I2S]process, APM_inputCnt(word): %d, encBuf_space(word): %d")
   TRC_MSG(L1AUDIO_I2S_REC_ENCODED, "[I2S]encoder out, encData_consumed(word): %d, outputByte: %d, flush: %d")

   //spt
   TRC_MSG(L1AUDIO_SPT_SPT_RESET, "SPT reset,SR=%d,St=%d")
   TRC_MSG(L1AUDIO_SPT_SPT_TASK, "SPT TASK")  
   TRC_MSG(L1AUDIO_SPT_D_F_T, "SPT D%d F%d T%d")
   TRC_MSG(L1AUDIO_SPT_SPT_OPEN, "SPT OPEN")   

   //WAV DRA
   TRC_MSG(L1AUDIO_WAV_DRA_NO_SYNC, "WAV_DRA No Sync %d, Offset %d")
   TRC_MSG(L1AUDIO_WAV_DRA_ERROR, "WAV_DRA Error %d, Offset %d")   
   
   //KT_detect
   TRC_MSG(L1AUDIO_KT_DETECT_START, "KT_DETECT_ktDetectStarted")  
   TRC_MSG(L1AUDIO_KT_DETECT_STOP, "KT_DETECT_ktDetectStoped")
   TRC_MSG(L1AUDIO_KT_DETECT_DUMP, "KT_DETECT_prepare to dump pcm file")
   TRC_MSG(L1AUDIO_KT_DETECT_FINISH, "KT_DETECT_finish dump pcm file")

   //avsync mp4
   TRC_MSG(L1AUDIO_AVSYNC_MP4_AUDIO_GETPLAYTIME,       "[AVSYNC_MP4] Audio_GetPlayTime,IntptCnt: %d, SeekPointTime: %d, CurrPlayTime(ms): %d")
   TRC_MSG(L1AUDIO_AVSYNC_MP4_VIDEO_GETPLAYTIME,       "[AVSYNC_MP4] Video_GetPlayTime,PrevIntptCnt: %d, CurrIntptCnt: %d, PrePlayTime: %d, CurrPlayTime(ms): %d")
   TRC_MSG(L1AUDIO_AVSYNC_MP4_SETPLAYBACKTIMERBASE, "[AVSYNC_MP4] MP4_SetPlaybackTimerBase,Prev PlayTime: %d, New PlayTime: %d")

   //MCU DECODE PLAYBACK
   TRC_MSG(L1AUDIO_PLAYBACK_PCMBF_UF, "[AUD_PLAY][HISR]PCM BUFFER Under Flow in HISR%d" )
   TRC_MSG(L1AUDIO_PLAYBACK_TIMEUP, "[AUD_PLAY][HISR]Time Up%d" )   
   TRC_MSG(L1AUDIO_PLAYBACK_DSPRB_INIT, "[AUD_PLAY][HISR]DSP RB Init%d" ) 
   TRC_MSG(L1AUDIO_PLAYBACK_MEDIA_END, "[AUD_PLAY][HISR]Media End%d" ) 
   TRC_MSG(L1AUDIO_PLAYBACK_DSP_IDLE, "[AUD_PLAY][HISR]DSP IDLE%d" ) 
   TRC_MSG(L1AUDIO_PLAYBACK_GETDATA_FROM_FILE, "[AUD_PLAY][PROS]Put %d bytes to bsbuf" )


   //WAVDEC PLAYBACK
   TRC_MSG(L1AUDIO_WAVDEC_PARAM_1, "[WAVDEC][Header Info1] format: %d, data offset: %d, SR: %d, Channelnum %d" )
   TRC_MSG(L1AUDIO_WAVDEC_PARAM_2, "[WAVDEC][Header Info1] data chunk length: %d, bite rate: %d, total dur: %d" )
   TRC_MSG(L1AUDIO_WAVDEC_DECODE, "[WAVDEC]DECODE TASK, output length: %d" )
   TRC_MSG(L1AUDIO_WAVDEC_DEC_FAIL, "[WAVDEC]DECODE FAIL" )


   //AUDIO PLAYBACK CILENT
   TRC_MSG(L1AUDIO_PLAYBACK_OPEN         , "[AUD_CIL][OPEN ] format: %d, handle: 0x%X, callback: 0x%X" )
   TRC_MSG(L1AUDIO_PLAYBACK_PLAY         , "[AUD_CIL][PLAY ] format: %d, handle: 0x%X" )
   TRC_MSG(L1AUDIO_PLAYBACK_STOP         , "[AUD_CIL][STOP ] format: %d, handle: 0x%X" )
   TRC_MSG(L1AUDIO_PLAYBACK_CLOSE        , "[AUD_CIL][CLOSE] format: %d, handle: 0x%X" )
   TRC_MSG(L1AUDIO_PLAYBACK_PROSS        , "[AUD_CIL][PROSS] format: %d, handle: 0x%X, event: %d" )
   TRC_MSG(L1AUDIO_PLAYBACK_PLAY_SUCCESS , "[AUD_CIL][PLAY ] format: %d, handle: 0x%X, PLAY SUCCESS" )
   
   //AUDIO PLAYBACK COMPONENT
   TRC_MSG(L1AUDIO_COM_INIT   , "[AUD_COMP][INIT ] type: %d, AudID: %d, com_status: %d" )
   TRC_MSG(L1AUDIO_COM_START  , "[AUD_COMP][START] type: %d, AudID: %d, com_status: %d" )
   TRC_MSG(L1AUDIO_COM_STOP   , "[AUD_COMP][STOP ] type: %d, AudID: %d, com_status: %d" )
   TRC_MSG(L1AUDIO_COM_DEINIT , "[AUD_COMP][DINIT] type: %d, AudID: %d, com_status: %d" )
   TRC_MSG(L1AUDIO_COM_PROSS  , "[AUD_COMP][PROSS] type: %d, AudID: %d, com_status: %d" )
   
   //Compensation Filter
   TRC_MSG(L1AUDIO_ACF_SELECT, "[ACF]Media_SelectAudioCompensation: %d" )
   TRC_MSG(L1AUDIO_ACF_ACTIVATE, "[ACF]Audio_Compensation_Activate, mode: %d" )

   //AUDIO PLAYBACK
   TRC_MSG(L1AUDIO_PLY_DECODE_CHECKSUM, "[L1AU][PLY] type=%d, CHECKSUM: 0x%X")
   
   //Audio General info
   TRC_MSG(L1AUDIO_GENERAL_INFO, "[AUD][%MAudio_Trace_Index] %d, %d, %d, %d, %d, %d")
   
   // Data comsumption
   TRC_MSG(L1AUDIO_SINK_INFO, "[AUD][Sink] AudID: %d, Consume %d bytes")
   TRC_MSG(L1AUDIO_SOURCE_INFO, "[AUD][Source] Get %d bytes")
   
   // Audio SYS Power On Off
   TRC_MSG(L1AUDIO_AUDSYS_POWER_ON_Enter, "[AUDSYS] Power On enter")
   TRC_MSG(L1AUDIO_AUDSYS_POWER_ON_Exit, "[AUDSYS] Power On exit")
   TRC_MSG(L1AUDIO_AUDSYS_POWER_OFF_Enter, "[AUDSYS] Power Off enter")
   TRC_MSG(L1AUDIO_AUDSYS_POWER_OFF_Exit, "[AUDSYS] Power Off exit")
   


   TRC_MSG(L1AUDIO_RESAMPLER_OV1, "[L1AU][Resampler] RES RB OVFlow")
   TRC_MSG(L1AUDIO_RESAMPLER_OV2, "[L1AU][Resampler] RES buf OVFlow2")
   TRC_MSG(L1AUDIO_RESAMPLER_UDF, "[L1AU][Resampler] RES BUF UDFLOW")
   TRC_MSG(L1AUDIO_RESAMPLER_PUTBUF1, "[L1AU][Resampler] RES putbuf seg1=%d")
   TRC_MSG(L1AUDIO_RESAMPLER_PUTBUF2, "[L1AU][Resampler] RES putbuf seg2=%d")
   TRC_MSG(L1AUDIO_RESAMPLER_RESINTCM, "[L1AU][Resampler] ResInTcm;ResSize=%d,TcmLen=%d")
   TRC_MSG(L1AUDIO_RESAMPLER_RESHDLTCM, "[L1AU][Resampler] ResHdlInTcm;ResSize=%d,TcmLen=%d")
   TRC_MSG(L1AUDIO_RESAMPLER_RESINEXT, "[L1AU][Resampler] ResInExt")
   

   //VORBIS
   TRC_MSG(L1AUDIO_VBSENC_RECORD   , "[L1AU][VBS_ENC]VBSENC_RECORD, State: %d, Speech: %d" )
   TRC_MSG(L1AUDIO_VBSENC_STOP     , "[L1AU][VBS_ENC]VBSENC_STOP, State: %d" )
   TRC_MSG(L1AUDIO_VBSENC_PAUSE    , "[L1AU][VBS_ENC]VBSENC_PAUSE, State: %d" )
   TRC_MSG(L1AUDIO_VBSENC_RESUME   , "[L1AU][VBS_ENC]VBSENC_RESUME, State: %d" )
   TRC_MSG(L1AUDIO_VBSENC_FLUSH    , "[L1AU][VBS_ENC]VBSENC_FLUSH, Media_GetDataCount: %d" )
   TRC_MSG(L1AUDIO_VBSENC_DSPOFF   , "[L1AU][VBS_ENC]VBSENC_DSPOFF, SampleRate: %d" )
   TRC_MSG(L1AUDIO_VBSENC_HISR     , "[L1AU][VBS_ENC]VBSENC_HISR, State: %d" )
   TRC_MSG(L1AUDIO_VBSENC_COPY2IN  , "[L1AU][VBS_ENC]VBSENC_COPY2IN, WBLK: %d, EBLK: %d, READY: %d, INLEN: %d, CurBLK_W: %d " )
   TRC_MSG(L1AUDIO_VBSENC_COPY2OUT , "[L1AU][VBS_ENC]VBSENC_COPY2OUT, OutLen: %d, OutLenRead: %d, Segment: %d " )
   TRC_MSG(L1AUDIO_VBSENC_PROCESS  , "[L1AU][VBS_ENC]VBSENC_PROCESS, State: %d, Ready: %d, OutLen: %d " )
   TRC_MSG(L1AUDIO_VBSENC_ENCODE   , "[L1AU][VBS_ENC]VBSENC_ENCODE, Flush: %d, OutLen: %d, EncBlk: %d " )
   TRC_MSG(L1AUDIO_VBSENC_FREE     , "[L1AU][VBS_ENC]VBSENC_FREE, State: %d " )
   TRC_MSG(L1AUDIO_VBSENC_INIT     , "[L1AU][VBS_ENC]VBSENC_INIT, State " )
   TRC_MSG(L1AUDIO_VBSENC_MEMSIZE  , "[L1AU][VBS_ENC]VBSENC_MEMSIZE, rt_tab: %d, shared: %d, encoder: %d, parser: %d, input: %d, output: %d  " )
   TRC_MSG(L1AUDIO_VBSENC_ALLOC_INPCM  , "[L1AU][VBS_ENC]VBSENC_ALLOC_INPCM: %d " )
   TRC_MSG(L1AUDIO_VBSENC_ALLOC_OUTBS  , "[L1AU][VBS_ENC]VBSENC_ALLOC_OUTBS: %d " )
   TRC_MSG(L1AUDIO_VBSENC_ALLOC_WORK   , "[L1AU][VBS_ENC]VBSENC_ALLOC_WORK: %d " )
   TRC_MSG(L1AUDIO_VBSENC_ALLOC_TEMP   , "[L1AU][VBS_ENC]VBSENC_ALLOC_TEMP: %d " )
   TRC_MSG(L1AUDIO_VBSENC_I2S_RECORD   , "[L1AU][VBS_ENC]VBSENC_I2S_RECORD: State: %d, SR: %d, CH: %d " )
   TRC_MSG(L1AUDIO_VBSENC_I2S_COPY2OUT , "[L1AU][VBS_ENC]VBSENC_I2S_COPY2OUT: OutLen: %d, OutLenRead: %d, FreeSpeace: %d " )
   TRC_MSG(L1AUDIO_VBSENC_I2S_PROCESS  , "[L1AU][VBS_ENC]VBSENC_I2S_PROCESS: State: %d, inDataCnt: %d, outFreeSpace: %d, Flush : %d " )
   TRC_MSG(L1AUDIO_VBSENC_OPEN_DEVICE  , "[L1AU][VBS_ENC]VBSENC_OPEN_DEVICE, SpeechMode: %d" )
   TRC_MSG(L1AUDIO_VBSENC_CLOSE_DEVICE , "[L1AU][VBS_ENC]VBSENC_CLOSE_DEVICE, SpeechMode: %d" )
   TRC_MSG(L1AUDIO_VBSENC_READ_FROM_FC , "[L1AU][VBS_ENC]VBSENC_READ_FROM_FC, DataLen(Byte): %d" )
   TRC_MSG(L1AUDIO_VBSENC_MSGHANDLER   , "[L1AU][VBS_ENC]VBSENC_MSGHANDLER, msgOp: %X" )

   //MIXER
   TRC_MSG(L1AUDIO_MIXER_PCMRENDER_START   , "[L1AU][MIXER]PcmRender_Start, uState: %d, numHook: %d" )
   TRC_MSG(L1AUDIO_MIXER_PCMRENDER_STOP    , "[L1AU][MIXER]PcmRender_Stop, uState: %d, numHook: %d" )
   TRC_MSG(L1AUDIO_MIXER_REGISTER_INPUT    , "[L1AU][MIXER]RenMix_RegisterInput, uState: %d, numHook: %d" )
   TRC_MSG(L1AUDIO_MIXER_UNREGISTER_INPUT  , "[L1AU][MIXER]RenMix_UnRegisterInput, uState: %d, numHook: %d" )
   TRC_MSG(L1AUDIO_MIXER_ACTIVATE1         , "[L1AU][MIXER]audioMixer_Activate1, uState: %d, numHook: %d" )
   TRC_MSG(L1AUDIO_MIXER_DEACTIVATE        , "[L1AU][MIXER]audioMixer_Deactivate, uState: %d, numHook: %d" )
   TRC_MSG(L1AUDIO_MIXER_MIXEROUT_STOP     , "[L1AU][MIXER]MixerOut_Stop, uState: %d, numHook: %d" )


   //Loudness
   TRC_MSG(L1AUDIO_LOUDNESS_RINETONE_ENABLE   ,"[L1AU][LOUDNESS]Ringtone_Mode_Enable")
   TRC_MSG(L1AUDIO_LOUDNESS_RINETONE_DISABLE  ,"[L1AU][LOUDNESS]Ringtone_Mode_Disable")  
   TRC_MSG(L1AUDIO_LOUDNESS_REGISTRY          ,"[L1AU][LOUDNESS]Registry, iTurnOnLoudness: %d")  
   TRC_MSG(L1AUDIO_LOUDNESS_INIT_PARAM        ,"[L1AU][LOUDNESS]Init Param, mode: %d, fBloud_HSF_AVAILABLE: %d")  
   TRC_MSG(L1AUDIO_LOUDNESS_FILTER            ,"[L1AU][LOUDNESS]Filter, mode: %d, HPF[0][0]= 0x%X, BPF[0][0][0]= 0x%X")  

   //eCall
   TRC_MSG(ECALL_IVS_DRV_CATCH_EVENT, "[eCall]IVS Driver Catch Event %d")
   TRC_MSG(ECALL_IVS_DRV_HLACK, "[eCall]IVS Driver HLACK. Expect %d, Received %d")
   TRC_MSG(ECALL_PSAP_DRV_CATCH_EVENT, "[eCall]PSAP Driver Catch Event %d")
   TRC_MSG(ECALL_PSAP_DRV_RECEIVE_MSD, "[eCall]PSAP Driver Received MSD")
   TRC_MSG(ECALL_PSAP_DRV_MSD_DATA, "[eCall]PSAP MSD %3d %3d %3d %3d %3d %3d %3d")
   TRC_MSG(ECALL_IVS_MODEM_SENDSTART, "[eCall]IVS SendStart received from control")
   TRC_MSG(ECALL_IVS_MODEM_SENDSTART_IGNORE, "[eCall]IVS SendStart received from control, ignored")
   TRC_MSG(ECALL_IVS_MODEM_RX_RESET, "[eCall]IVS reset receiver")
   TRC_MSG(ECALL_IVS_MODEM_TX_RESET, "[eCall]IVS reset transmitter")
   TRC_MSG(ECALL_IVS_MODEM_TX_RESET_MSD_PROVIDED, "[eCall]IVS reset transmitter (MSD provided)")
   TRC_MSG(ECALL_IVS_MODEM_SENDSTART_DUR_MSD_IGNORE, "[eCall]IVS SendStart during MSD transmission, ignored.")
   TRC_MSG(ECALL_IVS_MODEM_SENDING_SEND, "[eCall]IVS sending  SEND")
   TRC_MSG(ECALL_IVS_MODEM_FULL_RESET, "[eCall]IVS full reset (no sync detected)")
   TRC_MSG(ECALL_IVS_MODEM_IGNORING_HLACK, "[eCall]IVS ignoring additional HLACK (data: 0x0%X, metric: %3d)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_HLACK_FINISHED, "[eCall]IVS received HLACK (data: 0x0%X, metric: %3d), finished.")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_HLACK_WAITING, "[eCall]IVS received HLACK (data: 0x0%X, metric: %3d), waiting...")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_START_LOW_RELIABILITY, "[eCall]IVS received START !> ignoring message (reliability too low)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_START_TOO_OFTEN, "[eCall]IVS received START (metric: %3d) too often starting over...")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_START_STARTING, "[eCall]IVS received START (metric: %3d), starting...")
   TRC_MSG(ECALL_IVS_MODEM_FAST_MODULATOR, "[eCall]IVS fast modulator chosen (NACK count: %d)")
   TRC_MSG(ECALL_IVS_MODEM_ROBUST_MODULATOR, "[eCall]IVS robust modulator chosen (NACK count: %d)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_START, "[eCall]IVS received START (metric: %3d)")
   TRC_MSG(ECALL_IVS_MODEM_START_AFTER_ACK, "[eCall]IVS START ... !> assuming previous ACK was wrong")
   TRC_MSG(ECALL_IVS_MODEM_START_AFTER_HLACK, "[eCall]IVS START ... !> assuming previous HLACK was wrong")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_NACK_EXCEPTING_START, "[eCall]IVS received NACK  !> ignoring message (expecting START)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_NACK_LOW_RELIABILITY, "[eCall]IVS received NACK  !> ignoring message (reliability too low)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_NACK_ASSUME_IDLE, "[eCall]IVS received NACK  !> ignoring message (assume IDLE)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_NACK_FIRST_TIME, "[eCall]IVS received NACK  (metric: %3d), first time")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_NACK, "[eCall]IVS received NACK  (metric: %3d)")
   TRC_MSG(ECALL_IVS_MODEM_NACK_AFTER_ACK, "[eCall]IVS NACK ... !> assuming previous ACK was wrong")
   TRC_MSG(ECALL_IVS_MODEM_NACK_AFTER_HLACK, "[eCall]IVS NACK ... !> assuming previous HLACK was wrong")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_ACK_EXPECTING_START, "[eCall]IVS received ACK   !> ignoring message (expecting START)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_ACK_RECORDED, "[eCall]IVS received ACK   !> ignoring message (already recorded)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_ACK_LOW_RELIABILITY, "[eCall]IVS received ACK   !> ignoring message (reliability too low)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_ACK_ASSUME_IDLE, "[eCall]IVS received ACK   !> ignoring message (assume IDLE)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_ACK, "[eCall]IVS received ACK   (metric: %3d), ACK recorded, wait for HLACK")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_ACK_WAITING, "[eCall]IVS received ACK   (metric: %3d), waiting...")
   TRC_MSG(ECALL_IVS_MODEM_ACK_AFTER_HLACK, "[eCall]IVS ACK ... !> assuming previous HLACK was wrong")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_IDLE_EXPECTING_START, "[eCall]IVS received IDLE  !> ignoring message (expecting START)")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_IDLE_IGNORE, "[eCall]IVS received IDLE  !> ignoring message")
   TRC_MSG(ECALL_IVS_MODEM_RECEIVED_IDLE_REMAINING, "[eCall]IVS remaining in IDLE mode")
   TRC_MSG(ECALL_SYNC_DETECTED, "[eCall]sync detected; delay: %+4d; npeaks: %+4d (inverted sync)")
   TRC_MSG(ECALL_SYNC_DETECTED_REGULAR, "[eCall]sync detected; delay: %+4d; npeaks: %+4d (regular sync)")
   TRC_MSG(ECALL_SYNC_MAX_RANGE, "[eCall]maximum sync checking range is [-480...480] samples")
   TRC_MSG(ECALL_SYNC_DETECTE_SLIP, "[eCall]sync check detects sample slip! [%+1d sample(s)]")
   TRC_MSG(ECALL_SYNC_PSAP_MAX_RANGE, "[eCall][PSAP] maximum sync tracking range is [-240...240] samples")
   TRC_MSG(ECALL_SYNC_PSAP_SLIP, "[eCall][PSAP] sync tracking detects sample slip! [%+1d sample(s)]")
   TRC_MSG(ECALL_CONTROL_PORT_UNDEFINE, "[eCall]control callback: port owner undefined.")
   TRC_MSG(ECALL_CONTROL_SYNC_LOCKED, "[eCall]sync locked, starting control message detection")
   TRC_MSG(ECALL_CONTROL_CODEC_INVERSION, "[eCall]codec inversion detected!")
   TRC_MSG(ECALL_CONTROL_MESSAGE_IGNORE, "[eCall]message ignored (bad sync check)")
   TRC_MSG(ECALL_PSAP_MODEM_RECEIVED_SEND_CONTROL, "[eCall][PSAP] SendStart received from control")
   TRC_MSG(ECALL_PSAP_MODEM_RECEIVED_SEND_OVER, "[eCall][PSAP] SendStart received, starting over...")
   TRC_MSG(ECALL_PSAP_MODEM_RECEIVED_SEND_IGNORE, "[eCall][PSAP] SendStart received from control, ignored.")
   TRC_MSG(ECALL_PSAP_MODEM_RECEIVED_HLACK, "[eCall][PSAP] HLACK data received from control")
   TRC_MSG(ECALL_PSAP_MODEM_RECEIVED_HLACK_IGNORE, "[eCall][PSAP] HLACK data received from control, ignored.")
   TRC_MSG(ECALL_PSAP_MODEM_RESET_RECEIVER, "[eCall][PSAP] reset receiver")
   TRC_MSG(ECALL_PSAP_MODEM_RESET_TRANSMITTER, "[eCall][PSAP] reset transmitter")
   TRC_MSG(ECALL_PSAP_MODEM_RECEIVED_SEND, "[eCall][PSAP] received SEND (metric: %3d), initiating START trigger")
   TRC_MSG(ECALL_PSAP_MODEM_INVERSION_DETECT, "[eCall][PSAP] codec inversion detected!")
   TRC_MSG(ECALL_PSAP_MODEM_INVERSION_SYNC, "[eCall][PSAP] codec inversion detected (sync observer)!")
   TRC_MSG(ECALL_PSAP_MODEM_RESTART, "[eCall][PSAP] restart due to tracking failures!")
   TRC_MSG(ECALL_PSAP_MODEM_CRC_FAIL, "[eCall][PSAP] CRC failed; rv = %d")
   TRC_MSG(ECALL_PSAP_MODEM_RECEIVED_MSD, "[eCall][PSAP] MSD successfully received; redundancy versions: %d")
   TRC_MSG(ECALL_PSAP_MODEM_SENDING_HLACK, "[eCall][PSAP] sending HLACK; data: 0x0%X")
   TRC_MSG(ECALL_PSAP_MODEM_SENDING_START, "[eCall][PSAP] sending START")
   TRC_MSG(ECALL_PSAP_MODEM_SENDING_NACK, "[eCall][PSAP] sending NACK")
   TRC_MSG(ECALL_PSAP_MODEM_SENDING_ACK, "[eCall][PSAP] sending ACK")
   TRC_MSG(ECALL_PSAP_MODEM_SENDING_ACK_PEND, "[eCall][PSAP] sending ACK (HLACK pending)")
   TRC_MSG(ECALL_PSAP_MODEM_FAST_REMAIN_IDLE, "[eCall][PSAP] remaining in IDLE mode")
   TRC_MSG(ECALL_PSAP_MODEM_FAST_MODULATION, "[eCall][PSAP] fast modulator chosen (metric: %d)")
   TRC_MSG(ECALL_PSAP_MODEM_ROBUST_MODULATION, "[eCall][PSAP] robust modulator chosen (metric: %d)")

END_TRACE_MAP(MOD_L1SP)

#endif // _L1SP_TRC_H
