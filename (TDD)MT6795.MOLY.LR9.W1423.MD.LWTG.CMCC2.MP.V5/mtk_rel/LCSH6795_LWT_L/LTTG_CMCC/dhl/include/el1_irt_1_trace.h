#ifndef L1TRC_EL1_IRT_1_DEF_H
#define L1TRC_EL1_IRT_1_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IRT_LOG_RF_CONFLICT() do {\
		if(EL1_IRT_1_Trace_Filter[0]==1 && (EL1_IRT_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0005, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define IRT_LOG_RF_CONFLICT()
#endif
#define IRT_LOG_RF_CONFLICT_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0005, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IRT_LOG_RF_CONFLICT_START(v1, v2, v3) do {\
		if(EL1_IRT_1_Trace_Filter[0]==1 && (EL1_IRT_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0105, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define IRT_LOG_RF_CONFLICT_START(v1, v2, v3)
#endif
#define IRT_LOG_RF_CONFLICT_START_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0105, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IRT_LOG_RF_CONFLICT_END(v1, v2, v3) do {\
		if(EL1_IRT_1_Trace_Filter[0]==1 && (EL1_IRT_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0205, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define IRT_LOG_RF_CONFLICT_END(v1, v2, v3)
#endif
#define IRT_LOG_RF_CONFLICT_END_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0205, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define IRT_LOG_SWITCH_AFC_CONTROL(v1, v2) do {\
		if(EL1_IRT_1_Trace_Filter[0]==1 && (EL1_IRT_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0305, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define IRT_LOG_SWITCH_AFC_CONTROL(v1, v2)
#endif
#define IRT_LOG_SWITCH_AFC_CONTROL_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0305, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1_IRT_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_IRT_LOG_RF_CONFLICT(void);
void L1TRC_Send_IRT_LOG_RF_CONFLICT_START(unsigned short v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_IRT_LOG_RF_CONFLICT_END(unsigned short v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_IRT_LOG_SWITCH_AFC_CONTROL(unsigned short v1, unsigned short v2);

void Set_EL1_IRT_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1_IRT_1()	(EL1_IRT_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1_IRT_1_rf_conflict_trace()	(ChkL1ModFltr_EL1_IRT_1()&&((EL1_IRT_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1MsgFltr_IRT_LOG_RF_CONFLICT()	ChkL1ClsFltr_EL1_IRT_1_rf_conflict_trace()
#define ChkL1MsgFltr_IRT_LOG_RF_CONFLICT_START()	ChkL1ClsFltr_EL1_IRT_1_rf_conflict_trace()
#define ChkL1MsgFltr_IRT_LOG_RF_CONFLICT_END()	ChkL1ClsFltr_EL1_IRT_1_rf_conflict_trace()
#define ChkL1MsgFltr_IRT_LOG_SWITCH_AFC_CONTROL()	ChkL1ClsFltr_EL1_IRT_1_rf_conflict_trace()


#endif
