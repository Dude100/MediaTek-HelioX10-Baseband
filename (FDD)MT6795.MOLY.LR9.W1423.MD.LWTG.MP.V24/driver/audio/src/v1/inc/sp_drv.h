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
 * sp_drv.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * MD speech control interfaces 
 *
 * Author:
 * -------
 * 
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
 * removed!
 *
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
 * removed!
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
 
#ifndef _SP_DRV_H
#define _SP_DRV_H

kal_bool SP_IsSpeakerMute(void);

void SP_MuteUlEnhResult(kal_bool mute);
void SP_MuteUlSource(kal_bool mute);

typedef enum { // saving inside l1sp.isUlMute, bit wise record
	SP_MIC_MUTE_POS_FROM_SPC = 0x1,	
	SP_MIC_MUTE_POS_FROM_MED = 0x2,

	SP_MIC_MUTE_POS_FROM_ALL = 0xFFFF,
	
}SP_MIC_MUTE_POS;
void SP_MuteUlFromDiffPos(bool mute, SP_MIC_MUTE_POS pos);
bool SP_IsMicMute(void);


void L1SP_SpeechLoopBackEnable(kal_bool fgEnable);

void sp_setBtOn(bool on);
bool sp_getIsBtOn(void);


// void L1SP_Register_BgsService(void (*onHandler)(void), void (*offHandler)(void));
// void L1SP_UnRegister_BgsService( void );

// ----------------------------------------------------------------------------
// ENHANCEMENT MODE PARAMETERS
// ----------------------------------------------------------------------------
void l1sp_SetWbSpeechPara( kal_uint16 m_para[NUM_MODE_PARAS] );
// void l1sp_SetSpeechMode( uint8 devMode, uint8 mode, uint16 m_para[NUM_MODE_PARAS] );
// void l1sp_SetSpeechMode( uint8 devMode, uint8 mode);


void l1sp_setAllSpeechModePara(kal_uint16 * speech_mode_para, kal_int16 length);
void l1sp_setAllSpeechFirCoeff_InputOnly(kal_int16 *speech_input_FIR_coeffs, kal_int16 length);
void l1sp_setAllSpeechFirCoeff_OutputOnly(kal_int16 *speech_output_FIR_coeffs, kal_int16 length);

void l1sp_setAllWbSpeechModePara(kal_uint16 * speech_mode_para, kal_int16 length);
void l1sp_setAllWbSpeechFirCoeff_InputOnly(kal_int16 *speech_input_FIR_coeffs, kal_int16 length);
void l1sp_setAllWbSpeechFirCoeff_OutputOnly(kal_int16 *speech_output_FIR_coeffs, kal_int16 length);

void SP_SetSpeechPara( uint16 sph_m_para[NUM_MODE_PARAS] );
void SP_SetWbSpeechPara( kal_uint16 m_para[NUM_MODE_PARAS] );

// void l1sp_updateSpeUsrMaskWithWholeValue(uint16 newValue);
// void l1sp_updateSpeUsrSubMaskWithWholeValue(uint16 newValue);


// uint16 l1sp_GetSpeState(void);

kal_uint16 *Sp_GetCommonSpeechPara(void);
kal_uint16 *Sp_GetSpeechPara(void);
kal_uint16 *Sp_GetWbSpeechPara(void);


// ----------------------------------------------------------------------------
// DSP volume related
// ----------------------------------------------------------------------------

void l1sp_digiOnly_SetOutputVolume(kal_int16 digitalGain);
void l1sp_digiOnly_SetEnhRefOutputVolume(kal_int16 digitalRefGain);
void l1sp_digiOnly_SetMicrophoneVolume(kal_int16 digitalGain);

// ----------------------------------------------------------------------------
// Mute Control
// ----------------------------------------------------------------------------
typedef enum{ //bit mask   
   L1SP_FORCEDUNMUTE_ALL = 0xFFFF,
   L1SP_FORCEDUNMUTE_PCMROUTER = 0x01,
   L1SP_FORCEDUNMUTE_PCMRECORD = 0x02,
   L1SP_FORCEDUNMUTE_ACOUSTICLOOPBACK = 0x04,
   L1SP_FORCEDUNMUTE_RAWPCMRECORD = 0x08,
}L1SP_FORCEDUNMUTE_BITMASK; 

kal_bool SP_is_codec_mute(void);
void SP_SetForcedUnMuteController(L1SP_FORCEDUNMUTE_BITMASK mask, bool b);


// ----------------------------------------------------------------------------
// Else
// ----------------------------------------------------------------------------

#if 0 //defined(MT6752)
/* under construction !*/
#endif

#if 0 //defined(MT6752) //defined(MT6595)
/* under construction !*/
#endif

#if defined(__VOLTE_SUPPORT__)  
typedef struct{
   //raw information from eMAC
   uint32 RX_period;   //ms
   uint32 TX_period;   //ms
   uint32 time2nextRX; //ms
   uint32 time2nextTX; //ms
   uint32 issueTime;   //ms
}resync_info_t;

typedef struct{
   LOCAL_PARA_HDR
   //raw information from eMAC
   uint32 RX_period;   //ms
   uint32 TX_period;   //ms
   uint32 time2nextRX; //ms
   uint32 time2nextTX; //ms
   uint32 issueTime;   //ms
}ilm_resync_info_t;

typedef struct{
   LOCAL_PARA_HDR
   kal_int16 freq1;
   kal_int16 freq2;
   kal_int16 duration;
}ilm_PSR_DL_KT_t;

typedef struct {
   LOCAL_PARA_HDR
   L1SP_Tones *pToneList;
}ilm_PSR_DL_TONE_t;

void sub_SP4G_emac_timing_update(ilm_resync_info_t* p_timing_info);
#endif //#if defined(__VOLTE_SUPPORT__)

typedef struct {
   LOCAL_PARA_HDR
   L1SP_L4C_Event event;
   L1SP_L4C_Event_Mode mode;
}ilm_SP_L4C_SET_EVENT_t;

#endif //_SP_DRV_H
