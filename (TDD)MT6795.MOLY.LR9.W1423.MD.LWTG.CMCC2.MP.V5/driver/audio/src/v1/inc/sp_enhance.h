
#ifndef _SP_ENHANCE_H
#define _SP_ENHANCE_H

#include "common_def.h"

uint8 SPE_GetSpeechMode(void);

void SetSpeechEnhancement( bool ec );
void L1SP_EnableSpeechEnhancement( bool enable );
bool spe_isSpeFweOn(void);


kal_uint16 *SPE_getAllWbSpeechModePara(void);
kal_int16 *SPE_getAllWbSpeechFirCoeff_InputOnly(void);
kal_int16 *SPE_getAllWbSpeechFirCoeff_OutputOnly(void);


void SPE_LoadSpeechPara( uint16 c_para[NUM_COMMON_PARAS], uint16 m_para[NUM_MODE_PARAS],uint16 v_para[NUM_VOL_PARAS],
	uint16 m_paraWb[NUM_MODE_PARAS]);

void spe_updateSpeAppMask(uint8 updateFlags, bool enable);

void spe_updateSpeUsrMaskWithWholeValue(uint16 newValue);
void spe_updateSpeUsrSubMaskWithWholeValue(uint16 newValue);

void spe_setHacSpeechModePara(kal_uint16 * modePara, kal_int16 length);
void spe_setHacSpeechFirCoeff_InputOnly(kal_int16 *fIR_coeffs, kal_int16 length);
void spe_setHacSpeechFirCoeff_OutputOnly(kal_int16 *fIR_coeffs, kal_int16 length);
void spe_setHacWbSpeechModePara(kal_uint16 * modePara, kal_int16 length);
void spe_setHacWbSpeechFirCoeff_InputOnly(kal_int16 *fIR_coeffs, kal_int16 length);
void spe_setHacWbSpeechFirCoeff_OutputOnly(kal_int16 *fIR_coeffs, kal_int16 length);
void spe_setHacModeNeeded(bool isNeed);

// ----------------------------------------------------------------------------
// DSP filter/function related parameter/coefficient setting
// ----------------------------------------------------------------------------
void spe_setMagiConParam(uint16 *nbParam, uint16 *wbParam);
void spe_setNotchFilterParam(int16 *param, bool is2In1Spk);


void SPE_SetAgcInfo(bool isNxpOn, uint16 nxpPaMicIndex, uint16 delayAndSwitch4Dsp);
bool SPE_AgcInfo_IsNxpPaOn(void);


#endif
