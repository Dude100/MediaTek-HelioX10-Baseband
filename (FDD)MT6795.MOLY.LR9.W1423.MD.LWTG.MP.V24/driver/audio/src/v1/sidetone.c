

#include "kal_public_api.h"
#include "kal_general_types.h"

#include "kal_trace.h"
#include "l1sp_trc.h"
#include "l1audio_trace.h"

#include "sidetone.h"

#include "sal_def.h"
#include "sal_exp.h"

#include "reg_base.h"



typedef struct SIDETONE_INFO_STRUCT
{
	uint16 extStVolume; // value set from AP, should be Adaptive side tone volume
// #if SMART_PHONE_HW_SIDETONE_SUPPORT
	kal_timerid timer; 
// #endif

	SIDETONE_SOLUTION_VER solutionVer;
	bool  isActive; // periodically update the Hw AFE Sidetone Gain 
} SIDETONE_INFO;

static SIDETONE_INFO gSidetoneInfo;

//=============================================================================


// #if SMART_PHONE_HW_SIDETONE_SUPPORT

#define WriteApReg(_addr, _value) (*(volatile kal_uint32 *)(_addr) = (_value))
// #define SetApReg(_addr, value) (_addr = ((_addr & (~_addr##_MASK)) | (value <<_addr##_BIT)))

#if defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(MT6752)

// #define AP_AUDSYS_BASE   0xA2070000
#define AP_AFE_SIDDETONE_GAIN              (AP_AUDSYS_base + 0x01EC)

// #define AP_AFE_SIDDETONE_GAIN_GAIN        (*(volatile kal_uint32 *)AP_AFE_SIDDETONE_GAIN)
// #define AP_AFE_SIDDETONE_GAIN_GAIN_BIT    0
// #define AP_AFE_SIDDETONE_GAIN_GAIN_MASK   (0xff << AP_AFE_SIDDETONE_GAIN_GAIN_BIT) 

#endif // defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(MT6752)

//=============================================================================


/*
	Like callback function periodically
*/
void sidetone_hw_UpdateHwStVolume(void)
{	
#ifdef AP_AFE_SIDDETONE_GAIN
	if(gSidetoneInfo.isActive){
		
		kal_uint16 dspValue, targetValue; 
		//read from DSP and update the volume 
		dspValue=SAL_Sidetone_GetAdaptiveGain(); // Q1.15 Format
		
		// multiple, 
		// gSidetoneInfo.extStVolume is Q4.12 Format
		// HW is Q1.15 Format		
		targetValue = (kal_uint16)(((kal_uint32)(dspValue* gSidetoneInfo.extStVolume))>>12);
		if(targetValue > 0x7FFF) {
			targetValue = 0x7FFF;
		}

		// write to ap hw 
		WriteApReg(AP_AFE_SIDDETONE_GAIN, targetValue);		

		// WriteApReg(AP_AFE_SIDDETONE_GAIN, 0x7FFF);		
		if(!kal_if_hisr()){
			kal_trace(TRACE_GROUP_SP_DEBUG, SIDETONE_WRITE_TO_HW, targetValue);
		} else {
			kal_dev_trace(TRACE_GROUP_SP_DEBUG, SIDETONE_WRITE_TO_HW, targetValue);
		}

		// trigger the timer again.
		kal_set_timer(gSidetoneInfo.timer, (kal_timer_func_ptr)(sidetone_hw_UpdateHwStVolume), NULL, 4, 0);
	}

#else
	ASSERT(0); // register not define, it should to use hw sidetone
#endif
}


void sidetone_hw_UpdateStart(void)
{
	kal_trace(TRACE_INFO, SIDETONE_START, SIDETONE_SOLUTION_VER_HW);

	gSidetoneInfo.isActive = true;

	// trigger the timer again.
	kal_set_timer(gSidetoneInfo.timer, (kal_timer_func_ptr)(sidetone_hw_UpdateHwStVolume), NULL, 4, 0);

}

void sidetone_hw_UpdateStop(void)
{
	kal_trace(TRACE_INFO, SIDETONE_STOP);
	
	gSidetoneInfo.isActive = false;

	kal_cancel_timer(gSidetoneInfo.timer);
	
	
}

/**
	Be called from SPC message handler, so we do not leave any log here. 
	Please try to check A2M message and you can get the value

	@vol: volume calculated by AP side
*/
void sidetone_hw_SetExtStVolume(kal_uint16 vol)
{	
	gSidetoneInfo.extStVolume = vol; 	
}


void sidetone_hw_TurnSwSidetoneOn(kal_bool on)
{
	// do nothing when using hardware sidetone
	(void) on;
}


void sidetone_hw_Init(void)
{
	//gSidetoneInfo.extStVolume = 0x7fff;
	// init value sync with AP side int value
	gSidetoneInfo.extStVolume = 0;

	
	// gSidetoneInfo.gptTimer = DclSGPT_Open(DCL_GPT_CB, FLAGS_NONE);
	gSidetoneInfo.timer = kal_create_timer("sidetone"); 
	
}

// ============================================================================
//#else
void sidetone_dspSw_SetExtStVolume(kal_uint16 vol);

void sidetone_dspSw_UpdateStart(void)
{ 
	kal_trace(TRACE_INFO, SIDETONE_START, SIDETONE_SOLUTION_VER_DSP_SW);

	gSidetoneInfo.isActive = true;

	// update dsp's sidetone volume
	sidetone_dspSw_SetExtStVolume(gSidetoneInfo.extStVolume);

}

void sidetone_dspSw_UpdateStop(void)
{ 
	kal_trace(TRACE_INFO, SIDETONE_STOP);
	
	gSidetoneInfo.isActive = false;
}

/**
	Be called from SPC message handler, so we do not leave any log here. 
	Please try to check A2M message and you can get the value

	@vol: volume calculated by AP side
*/
void sidetone_dspSw_SetExtStVolume(kal_uint16 vol)
{ 
	gSidetoneInfo.extStVolume = vol;

	if(gSidetoneInfo.isActive){
		kal_uint16 targetValue; // This is For DSP Q4.12 Format
		
		// gSidetoneInfo.extStVolume is Q4.12 Format for HW sidetone gain.
		// targetValue is SW sidetone gain, which is 12 db loader then hw sidetone gain
		// As the result, we need to left shift 2 bit to calucate correct sw sidetone gain

		targetValue = (gSidetoneInfo.extStVolume<<2);
		if(targetValue > 0x7FFF) {
			targetValue = 0x7FFF;
		}
		
		// write to ap hw 
		SAL_Sidetone_SetGain(targetValue);
		// WriteApReg(AP_AFE_SIDDETONE_GAIN, 0x7FFF);		
		if(!kal_if_hisr()){
			kal_trace(TRACE_GROUP_SP_DEBUG, SIDETONE_WRITE_TO_HW, targetValue);
		} else {
			kal_dev_trace(TRACE_GROUP_SP_DEBUG, SIDETONE_WRITE_TO_HW, targetValue);
		}
	}
}


/**
	Please use this function during DSP power on. (The function may access sherif)
	@on: ture for turning on, false for turing off.
*/
void sidetone_dspSw_TurnSwSidetoneOn(kal_bool on)
{
	SAL_Sidetone_Enable(on);
}


void sidetone_dspSw_Init(void)
{ 
	//gSidetoneInfo.extStVolume = 0x7fff;
	// init value sync with AP side int value
	gSidetoneInfo.extStVolume = 0;

}

// #endif

//=============================================================================
// APIs 
//=============================================================================

/**
	@solutionVer: 0 for Hw 
*/
void SIDETONE_UpdateStart(void)
{
	kal_trace(TRACE_INFO, SIDETONE_START, gSidetoneInfo.solutionVer);

	gSidetoneInfo.isActive = true;
	
	if(SIDETONE_SOLUTION_VER_HW == gSidetoneInfo.solutionVer) {
		// trigger the timer again.
		kal_set_timer(gSidetoneInfo.timer, (kal_timer_func_ptr)(sidetone_hw_UpdateHwStVolume), NULL, 4, 0);
	} else {
		SIDETONE_SetExtStVolume(gSidetoneInfo.extStVolume);
	}

}

void SIDETONE_UpdateStop(void)
{
	kal_trace(TRACE_INFO, SIDETONE_STOP, gSidetoneInfo.solutionVer);
	
	gSidetoneInfo.isActive = false;

	if(SIDETONE_SOLUTION_VER_HW == gSidetoneInfo.solutionVer) {
		kal_cancel_timer(gSidetoneInfo.timer);
	}

	// gSidetoneInfo.solutionVer = SIDETONE_SOLUTION_VER_UNDEF;
}	

void SIDETONE_SetExtStVolume(kal_uint16 vol) 
{

	if(SIDETONE_SOLUTION_VER_HW == gSidetoneInfo.solutionVer) {
		sidetone_hw_SetExtStVolume(vol);
	} else if (SIDETONE_SOLUTION_VER_DSP_SW == gSidetoneInfo.solutionVer) {
		sidetone_dspSw_SetExtStVolume(vol);
	} else { // do nothing
	}	
	
}

/**
	Please use this function during DSP power on. (The function may access sherif)
	@on: ture for turning on, false for turing off.
*/
void SIDETONE_TurnSwSidetoneOn(kal_bool on)
{
	if(SIDETONE_SOLUTION_VER_HW == gSidetoneInfo.solutionVer) {
		sidetone_hw_TurnSwSidetoneOn(on);
	} else if(SIDETONE_SOLUTION_VER_DSP_SW == gSidetoneInfo.solutionVer){
		sidetone_dspSw_TurnSwSidetoneOn(on);
	} else {
		// ASSERT(0); // do nothing, in case sidetone is not use actually. 
	}
}

void SIDETONE_SetSolutionVer(SIDETONE_SOLUTION_VER solutionVer)
{	

	ASSERT((SIDETONE_SOLUTION_VER_HW == solutionVer) || (SIDETONE_SOLUTION_VER_DSP_SW == solutionVer));

	//record the solution
	gSidetoneInfo.solutionVer = solutionVer;
}

void SIDETONE_ResetSolutionVer(void)
{
	ASSERT((SIDETONE_SOLUTION_VER_HW == gSidetoneInfo.solutionVer) || (SIDETONE_SOLUTION_VER_DSP_SW == gSidetoneInfo.solutionVer));

	//record the solution
	gSidetoneInfo.solutionVer = SIDETONE_SOLUTION_VER_UNDEF;
}


void SIDETONE_Init(void)
{
	//gSidetoneInfo.extStVolume = 0x7fff;
	// init value sync with AP side int value
	gSidetoneInfo.extStVolume = 0;

	
	// gSidetoneInfo.gptTimer = DclSGPT_Open(DCL_GPT_CB, FLAGS_NONE);
	gSidetoneInfo.timer = kal_create_timer("sidetone"); 
	
}

