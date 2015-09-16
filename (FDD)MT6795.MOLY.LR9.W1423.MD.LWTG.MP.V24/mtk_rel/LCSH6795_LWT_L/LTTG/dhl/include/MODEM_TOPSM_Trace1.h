#ifndef L1TRC_MODEM_TOPSM_1_DEF_H
#define L1TRC_MODEM_TOPSM_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define MODEM_TOPSM_Str_Bool(v1)  (unsigned char)(v1+0)
#define MODEM_TOPSM_Str_Enable(v1)  (unsigned char)(v1+2)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define MODEM_TOPSM_EMI_REQUEST(v1, v2, v3) do {\
		if(MODEM_TOPSM_1_Trace_Filter[0]==1 && (MODEM_TOPSM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0033, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define MODEM_TOPSM_EMI_REQUEST(v1, v2, v3)
#endif
#define MODEM_TOPSM_EMI_REQUEST_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0033, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define MODEM_TOPSM_TRC_CALIBRATION(v1, v2, v3) do {\
		if(MODEM_TOPSM_1_Trace_Filter[0]==1 && (MODEM_TOPSM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0133, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define MODEM_TOPSM_TRC_CALIBRATION(v1, v2, v3)
#endif
#define MODEM_TOPSM_TRC_CALIBRATION_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0133, (unsigned short)(v1)), (long)(v2), (long)(v3))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char MODEM_TOPSM_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_MODEM_TOPSM_EMI_REQUEST(unsigned short v1, unsigned char v2, unsigned long v3);
void L1TRC_Send_MODEM_TOPSM_TRC_CALIBRATION(unsigned short v1, long v2, long v3);

void Set_MODEM_TOPSM_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_MODEM_TOPSM_1()	(MODEM_TOPSM_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_MODEM_TOPSM_1_MODEM_TOPSM_SM_H()	(ChkL1ModFltr_MODEM_TOPSM_1()&&((MODEM_TOPSM_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1MsgFltr_MODEM_TOPSM_EMI_REQUEST()	ChkL1ClsFltr_MODEM_TOPSM_1_MODEM_TOPSM_SM_H()
#define ChkL1MsgFltr_MODEM_TOPSM_TRC_CALIBRATION()	ChkL1ClsFltr_MODEM_TOPSM_1_MODEM_TOPSM_SM_H()


#endif
