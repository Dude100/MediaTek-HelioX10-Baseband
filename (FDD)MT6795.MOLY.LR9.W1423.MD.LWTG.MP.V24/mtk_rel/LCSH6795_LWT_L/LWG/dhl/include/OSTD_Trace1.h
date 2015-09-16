#ifndef L1TRC_OSTD_1_DEF_H
#define L1TRC_OSTD_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define OSTD_TIMER_TYPE_Str(v1)  (unsigned char)(v1+0)
#define OSTD_Str_Bool(v1)  (unsigned char)(v1+2)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define OSTD_TRC_DEBUG1(v1, v2, v3) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0045, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define OSTD_TRC_DEBUG1(v1, v2, v3)
#endif
#define OSTD_TRC_DEBUG1_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0045, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define OSTD_TRC_DEBUG2(v1, v2, v3) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0145, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define OSTD_TRC_DEBUG2(v1, v2, v3)
#endif
#define OSTD_TRC_DEBUG2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0145, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define OSTD_SM_STATUS(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x0245, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define OSTD_SM_STATUS(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define OSTD_SM_STATUS_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_2S(0x0245, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define OSTD_TRC_INF_SLEEP_TRG() do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0345, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define OSTD_TRC_INF_SLEEP_TRG()
#endif
#define OSTD_TRC_INF_SLEEP_TRG_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0345, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define OSTD_TRC_INF_SLEEP_TIMER_CB(v1, v2) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0445, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define OSTD_TRC_INF_SLEEP_TIMER_CB(v1, v2)
#endif
#define OSTD_TRC_INF_SLEEP_TIMER_CB_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0445, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define OSTD_PATCH_STATUS(v1, v2, v3, v4, v5) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0545, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5));\
	} while(0)
#else
	#define OSTD_PATCH_STATUS(v1, v2, v3, v4, v5)
#endif
#define OSTD_PATCH_STATUS_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0545, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define OSTD_TRC_DEBUGH3(v1, v2, v3) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0645, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define OSTD_TRC_DEBUGH3(v1, v2, v3)
#endif
#define OSTD_TRC_DEBUGH3_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0645, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define OSTD_TRC_DEBUGH4(v1, v2, v3, v4) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0745, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define OSTD_TRC_DEBUGH4(v1, v2, v3, v4)
#endif
#define OSTD_TRC_DEBUGH4_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0745, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char OSTD_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_OSTD_TRC_DEBUG1(unsigned short v1, long v2, long v3);
void L1TRC_Send_OSTD_TRC_DEBUG2(unsigned short v1, long v2, long v3);
void L1TRC_Send_OSTD_SM_STATUS(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_OSTD_TRC_INF_SLEEP_TRG(void);
void L1TRC_Send_OSTD_TRC_INF_SLEEP_TIMER_CB(unsigned char v1, unsigned char v2);
void L1TRC_Send_OSTD_PATCH_STATUS(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned long v5);
void L1TRC_Send_OSTD_TRC_DEBUGH3(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_OSTD_TRC_DEBUGH4(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);

void Set_OSTD_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_OSTD_1()	(OSTD_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_OSTD_1_OSTD_DBG_L()	(ChkL1ModFltr_OSTD_1()&&((OSTD_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_OSTD_1_OSTD_SM_H()	(ChkL1ModFltr_OSTD_1()&&((OSTD_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_OSTD_1_OSTD_IS_H()	(ChkL1ModFltr_OSTD_1()&&((OSTD_1_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_OSTD_1_OSTD_DBG_H()	(ChkL1ModFltr_OSTD_1()&&((OSTD_1_Trace_Filter[1]&0x08)!=0))
#define ChkL1MsgFltr_OSTD_TRC_DEBUG1()	ChkL1ClsFltr_OSTD_1_OSTD_DBG_L()
#define ChkL1MsgFltr_OSTD_TRC_DEBUG2()	ChkL1ClsFltr_OSTD_1_OSTD_DBG_L()
#define ChkL1MsgFltr_OSTD_SM_STATUS()	ChkL1ClsFltr_OSTD_1_OSTD_SM_H()
#define ChkL1MsgFltr_OSTD_TRC_INF_SLEEP_TRG()	ChkL1ClsFltr_OSTD_1_OSTD_IS_H()
#define ChkL1MsgFltr_OSTD_TRC_INF_SLEEP_TIMER_CB()	ChkL1ClsFltr_OSTD_1_OSTD_IS_H()
#define ChkL1MsgFltr_OSTD_PATCH_STATUS()	ChkL1ClsFltr_OSTD_1_OSTD_SM_H()
#define ChkL1MsgFltr_OSTD_TRC_DEBUGH3()	ChkL1ClsFltr_OSTD_1_OSTD_DBG_H()
#define ChkL1MsgFltr_OSTD_TRC_DEBUGH4()	ChkL1ClsFltr_OSTD_1_OSTD_DBG_H()


#endif
