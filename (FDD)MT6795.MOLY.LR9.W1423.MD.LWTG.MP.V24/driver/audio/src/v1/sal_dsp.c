#include "kal_public_api.h"
#include "kal_general_types.h"
#include "reg_base.h"
#include "l1_interface.h"
#include "string.h"

#include "common_def.h"

#include "sal_dsp.h"


extern uint16 L1Audio_GetAudioID(void);
extern void L1Audio_SetFlag(uint16 audio_id);
extern void L1Audio_ClearFlag(uint16 audio_id);
extern void L1Audio_FreeAudioID(uint16 aud_id);
extern void L1SP_Speech_On(uint8 RAT_Mode);
extern void L1SP_Speech_Off(void);
extern void AM_PCM16K_RecordOn(void);
extern void AM_PCM16K_RecordOff(bool wait);
extern void AM_PCM8K_RecordOn(uint16 appType);
extern void AM_PCM8K_RecordOff(bool wait, uint16 appType);
extern void AM_VMRecordOn(uint16 speech_mode);
extern void AM_VMRecordOff(void);

static int16 sal_tst_flag;

static void sal_tst_solve_sleep(bool ena)
{
	if(ena){
	sal_tst_flag = L1Audio_GetAudioID();
	L1Audio_SetFlag(sal_tst_flag);
	}
	else{
	L1Audio_ClearFlag(sal_tst_flag);
	L1Audio_FreeAudioID(sal_tst_flag);
	}
}
	
void SAL_TST_Handler(int16 cmd)
{
	
	switch(cmd)
	{
		case 0:
			AM_PCM8K_RecordOff(false, 1);//epl
			AM_VMRecordOff();
			L1SP_Speech_Off();
			break;
		case 1:
			L1SP_Speech_On(1);
			AM_VMRecordOn(0);
			AM_PCM8K_RecordOn(1);
			break;
		case 2:
			sal_tst_solve_sleep(true);
			AM_PCM16K_RecordOn();
			break;
		case 3:
			AM_PCM16K_RecordOff(false);
			sal_tst_solve_sleep(false);
			break;
		case 4:
			sal_tst_solve_sleep(true);
			AM_VMRecordOn(0);
			break;
		case 5:
			AM_VMRecordOff();
			sal_tst_solve_sleep(false);
			break;
		case 6:
			L1SP_Speech_On(1);
			AM_PCM8K_RecordOn(0);
			break;	
		case 7:
			AM_PCM8K_RecordOff(false, 0);//epl
			L1SP_Speech_Off();
			break;

	default:
		break;
	}
}

void Set_Dsp_Bit(volatile uint16 *addr, uint8 bitn)
{
	volatile uint16 *reg = addr;
	if(bitn > 15)
		*reg = 0xffff;
	else
	*reg |= (1 << bitn);
}

void Clear_Dsp_Bit(volatile uint16 *addr, uint8 bitn)
{
	volatile uint16 *reg = addr;
	if(bitn > 15)
		*reg = 0;
	else
	*reg &= ~(1 << bitn);
}



