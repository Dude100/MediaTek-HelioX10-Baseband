#ifndef _SIDETONE_H
#define _SIDETONE_H

// ----------------------------------------------------------------------------

typedef enum {
	SIDETONE_SOLUTION_VER_UNDEF = 0,
	SIDETONE_SOLUTION_VER_HW,
	SIDETONE_SOLUTION_VER_DSP_SW	
	
}SIDETONE_SOLUTION_VER;


// ----------------------------------------------------------------------------

#if ((defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(MT6752)) && defined(__SMART_PHONE_MODEM__))
// #define SMART_PHONE_HW_SIDETONE_SUPPORT 1
#define SMART_PHONE_SIDETONE_SOLUTION_VER SIDETONE_SOLUTION_VER_HW
#else //((defined(MT6589) || defined(MT6572) || defined(MT6582) ) using sw sidetone
// #define SMART_PHONE_HW_SIDETONE_SUPPORT 0
#define SMART_PHONE_SIDETONE_SOLUTION_VER SIDETONE_SOLUTION_VER_DSP_SW
#endif

// ----------------------------------------------------------------------------
//=========================== call from spc_drv.c ============================
void SIDETONE_UpdateStart(void);
void SIDETONE_UpdateStop(void);

void SIDETONE_SetSolutionVer(SIDETONE_SOLUTION_VER solutionVer);
void SIDETONE_ResetSolutionVer(void);


/**
	@vol: value from ap
*/
void SIDETONE_SetExtStVolume(kal_uint16 vol);


//=============================================================================

/**
	Please use this function during DSP power on. (The function may access sherif)
	@on: ture for turning on, false for turing off.
*/
void SIDETONE_TurnSwSidetoneOn(kal_bool on);


void SIDETONE_Init(void);

#endif //_SIDETONE_H

