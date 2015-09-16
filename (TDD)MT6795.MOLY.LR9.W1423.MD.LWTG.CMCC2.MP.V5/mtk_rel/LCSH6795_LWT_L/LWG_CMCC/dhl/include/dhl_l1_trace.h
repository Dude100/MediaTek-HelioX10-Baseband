#ifndef L1TRC_DHL_L1_DEF_H
#define L1TRC_DHL_L1_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UMTS_3G_GEMINI_TIME(v1, v2, v3, v4, v5) do {\
		if(DHL_L1_Trace_Filter[0]==1 && (DHL_L1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0000, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (char)(v1), TRC_BOXSTER_PAD), (long)(v3), (long)(v5));\
	} while(0)
#else
	#define UMTS_3G_GEMINI_TIME(v1, v2, v3, v4, v5)
#endif
#define UMTS_3G_GEMINI_TIME_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0000, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (char)(v1), TRC_BOXSTER_PAD), (long)(v3), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UMTS_3G_TIME(v1, v2, v3, v4) do {\
		if(DHL_L1_Trace_Filter[0]==1 && (DHL_L1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0100, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4));\
	} while(0)
#else
	#define UMTS_3G_TIME(v1, v2, v3, v4)
#endif
#define UMTS_3G_TIME_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0100, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UMTS_2G_GEMINI_TIME(v1, v2, v3, v4) do {\
		if(DHL_L1_Trace_Filter[0]==1 && (DHL_L1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0200, (short)(v3)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (long)(v4));\
	} while(0)
#else
	#define UMTS_2G_GEMINI_TIME(v1, v2, v3, v4)
#endif
#define UMTS_2G_GEMINI_TIME_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0200, (short)(v3)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UMTS_2G_TIME(v1, v2, v3) do {\
		if(DHL_L1_Trace_Filter[0]==1 && (DHL_L1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0300, (short)(v2)), (unsigned long)(v1), (long)(v3));\
	} while(0)
#else
	#define UMTS_2G_TIME(v1, v2, v3)
#endif
#define UMTS_2G_TIME_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0300, (short)(v2)), (unsigned long)(v1), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UMTS_2G_HANDOVER_TIME(v1, v2) do {\
		if(DHL_L1_Trace_Filter[0]==1 && (DHL_L1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0400, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2));\
	} while(0)
#else
	#define UMTS_2G_HANDOVER_TIME(v1, v2)
#endif
#define UMTS_2G_HANDOVER_TIME_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0400, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UMTS_3G_HANDOVER_TIME(v1, v2) do {\
		if(DHL_L1_Trace_Filter[0]==1 && (DHL_L1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0500, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2));\
	} while(0)
#else
	#define UMTS_3G_HANDOVER_TIME(v1, v2)
#endif
#define UMTS_3G_HANDOVER_TIME_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0500, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTE_4G_TIME(v1, v2, v3, v4) do {\
		if(DHL_L1_Trace_Filter[0]==1 && (DHL_L1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0600, (short)(v2)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v3));\
	} while(0)
#else
	#define LTE_4G_TIME(v1, v2, v3, v4)
#endif
#define LTE_4G_TIME_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0600, (short)(v2)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTE_4G_TIME_2(v1, v2, v3, v4, v5) do {\
		if(DHL_L1_Trace_Filter[0]==1 && (DHL_L1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0700, (short)(v2)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v3), (long)(v5));\
	} while(0)
#else
	#define LTE_4G_TIME_2(v1, v2, v3, v4, v5)
#endif
#define LTE_4G_TIME_2_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0700, (short)(v2)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v3), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTE_4G_L2_TIME(v1, v2, v3, v4) do {\
		if(DHL_L1_Trace_Filter[0]==1 && (DHL_L1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0800, (short)(v1)), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define LTE_4G_L2_TIME(v1, v2, v3, v4)
#endif
#define LTE_4G_L2_TIME_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0800, (short)(v1)), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1_TRC_REDUMP() do {\
		if(DHL_L1_Trace_Filter[0]==1 && (DHL_L1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0900, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1_TRC_REDUMP()
#endif
#define L1_TRC_REDUMP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0900, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char DHL_L1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UMTS_3G_GEMINI_TIME(char v1, short v2, long v3, short v4, long v5);
void L1TRC_Send_UMTS_3G_TIME(short v1, long v2, short v3, long v4);
void L1TRC_Send_UMTS_2G_GEMINI_TIME(char v1, unsigned long v2, short v3, long v4);
void L1TRC_Send_UMTS_2G_TIME(unsigned long v1, short v2, long v3);
void L1TRC_Send_UMTS_2G_HANDOVER_TIME(unsigned long v1, long v2);
void L1TRC_Send_UMTS_3G_HANDOVER_TIME(unsigned long v1, long v2);
void L1TRC_Send_LTE_4G_TIME(long v1, short v2, long v3, short v4);
void L1TRC_Send_LTE_4G_TIME_2(long v1, short v2, long v3, short v4, long v5);
void L1TRC_Send_LTE_4G_L2_TIME(short v1, long v2, long v3, long v4);
void L1TRC_Send_L1_TRC_REDUMP(void);

void Set_DHL_L1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_DHL_L1()	(DHL_L1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_DHL_L1_L1_Time_Info()	(ChkL1ModFltr_DHL_L1()&&((DHL_L1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_DHL_L1_L1_Info()	(ChkL1ModFltr_DHL_L1()&&((DHL_L1_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_UMTS_3G_GEMINI_TIME()	ChkL1ClsFltr_DHL_L1_L1_Time_Info()
#define ChkL1MsgFltr_UMTS_3G_TIME()	ChkL1ClsFltr_DHL_L1_L1_Time_Info()
#define ChkL1MsgFltr_UMTS_2G_GEMINI_TIME()	ChkL1ClsFltr_DHL_L1_L1_Time_Info()
#define ChkL1MsgFltr_UMTS_2G_TIME()	ChkL1ClsFltr_DHL_L1_L1_Time_Info()
#define ChkL1MsgFltr_UMTS_2G_HANDOVER_TIME()	ChkL1ClsFltr_DHL_L1_L1_Time_Info()
#define ChkL1MsgFltr_UMTS_3G_HANDOVER_TIME()	ChkL1ClsFltr_DHL_L1_L1_Time_Info()
#define ChkL1MsgFltr_LTE_4G_TIME()	ChkL1ClsFltr_DHL_L1_L1_Time_Info()
#define ChkL1MsgFltr_LTE_4G_TIME_2()	ChkL1ClsFltr_DHL_L1_L1_Time_Info()
#define ChkL1MsgFltr_LTE_4G_L2_TIME()	ChkL1ClsFltr_DHL_L1_L1_Time_Info()
#define ChkL1MsgFltr_L1_TRC_REDUMP()	ChkL1ClsFltr_DHL_L1_L1_Info()


#endif
