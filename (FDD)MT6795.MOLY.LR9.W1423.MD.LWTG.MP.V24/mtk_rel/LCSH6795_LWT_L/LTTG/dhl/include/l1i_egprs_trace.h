#ifndef L1TRC_L1I_EGPRS_DEF_H
#define L1TRC_L1I_EGPRS_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1I_EGPRS_Str_Bool(v1)  (unsigned char)(v1+0)
#define L1I_Str_TBF_Direct(v1)  (unsigned char)(v1+2)
#define L1I_Str_MAC_Grant(v1)  (unsigned char)(v1+5)
#define L1C_Str_restart_bsic_type(v1)  (unsigned char)(v1+8)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_U2_header(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0026, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)));\
	} while(0)
#else
	#define L1I_Trace_U2_header(v1, v2, v3, v4, v5, v6, v7)
#endif
#define L1I_Trace_U2_header_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0026, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)))

#if defined(L1_CATCHER)
	#define L1I_Trace_UL_Header1(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0126, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v6), (char)(v7), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_UL_Header1(v1, v2, v3, v4, v5, v6, v7)
#endif
#define L1I_Trace_UL_Header1_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0126, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), (char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v6), (char)(v7), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Trace_UL_Header2(v1, v2, v3, v4, v5) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0226, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), (char)(v5)));\
	} while(0)
#else
	#define L1I_Trace_UL_Header2(v1, v2, v3, v4, v5)
#endif
#define L1I_Trace_UL_Header2_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0226, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), (char)(v5)))

#if defined(L1_CATCHER)
	#define L1I_Trace_UL_Header3(v1, v2, v3, v4, v5, v6) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0326, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), (char)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_UL_Header3(v1, v2, v3, v4, v5, v6)
#endif
#define L1I_Trace_UL_Header3_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0326, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), (char)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_IRParams(v1, v2, v3, v4, v5, v6) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0426, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_IRParams(v1, v2, v3, v4, v5, v6)
#endif
#define L1I_Trace_IRParams_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0426, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_IRParams_TS(v1, v2, v3) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0526, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_IRParams_TS(v1, v2, v3)
#endif
#define L1I_Trace_IRParams_TS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0526, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_EGPRS_PDAN(v1, v2, v3, v4) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0626, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define L1I_Trace_EGPRS_PDAN(v1, v2, v3, v4)
#endif
#define L1I_Trace_EGPRS_PDAN_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0626, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_Set_SRB_Mode(v1, v2, v3, v4) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0726, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_Set_SRB_Mode(v1, v2, v3, v4)
#endif
#define L1I_Trace_Set_SRB_Mode_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0726, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_Egprs_ExtractPR(v1, v2, v3) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0826, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_Egprs_ExtractPR(v1, v2, v3)
#endif
#define L1I_Trace_Egprs_ExtractPR_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0826, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_New_TBF_Tid(v1, v2) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0926, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_New_TBF_Tid(v1, v2)
#endif
#define L1I_Trace_New_TBF_Tid_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0926, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_U2_data(v1) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0A26, (unsigned short)(v1)));\
	} while(0)
#else
	#define L1I_Trace_U2_data(v1)
#endif
#define L1I_Trace_U2_data_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0A26, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_TAC_no_accumulate(v1, v2) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B26, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define L1I_Trace_TAC_no_accumulate(v1, v2)
#endif
#define L1I_Trace_TAC_no_accumulate_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B26, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_TBF_Status(v1, v2, v3, v4, v5) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C26, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_TBF_Status(v1, v2, v3, v4, v5)
#endif
#define L1I_Trace_TBF_Status_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C26, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_MAC_Update_USF(v1, v2) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D26, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_MAC_Update_USF(v1, v2)
#endif
#define L1I_Trace_MAC_Update_USF_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D26, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_MAC_Granularity(v1, v2) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_MAC_Granularity(v1, v2)
#endif
#define L1I_Trace_MAC_Granularity_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E26, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_TBFStop(v1, v2, v3) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F26, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_TBFStop(v1, v2, v3)
#endif
#define L1I_Trace_TBFStop_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F26, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_TBFStop_Base(v1, v2, v3, v4, v5, v6) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1026, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define L1I_Trace_TBFStop_Base(v1, v2, v3, v4, v5, v6)
#endif
#define L1I_Trace_TBFStop_Base_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1026, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_MAC_Grant(v1, v2, v3, v4) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1126, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (unsigned char)(v4)));\
	} while(0)
#else
	#define L1I_Trace_MAC_Grant(v1, v2, v3, v4)
#endif
#define L1I_Trace_MAC_Grant_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1126, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (unsigned char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_RescheFCBSearch(v1, v2) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1226, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1I_Trace_RescheFCBSearch(v1, v2)
#endif
#define L1I_Trace_RescheFCBSearch_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1226, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_ReportGPRS_DL_CB_Check(v1, v2, v3) do {\
		if(L1I_EGPRS_Trace_Filter[0]==1 && (L1I_EGPRS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1326, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define L1C_ReportGPRS_DL_CB_Check(v1, v2, v3)
#endif
#define L1C_ReportGPRS_DL_CB_Check_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1326, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1I_EGPRS_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1I_Trace_U2_header(short v1, short v2, short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7);
void L1TRC_Send_L1I_Trace_UL_Header1(char v1, short v2, short v3, char v4, char v5, char v6, char v7);
void L1TRC_Send_L1I_Trace_UL_Header2(char v1, short v2, char v3, char v4, char v5);
void L1TRC_Send_L1I_Trace_UL_Header3(char v1, short v2, char v3, char v4, char v5, char v6);
void L1TRC_Send_L1I_Trace_IRParams(unsigned char v1, unsigned char v2, char v3, char v4, short v5, char v6);
void L1TRC_Send_L1I_Trace_IRParams_TS(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1I_Trace_EGPRS_PDAN(char v1, char v2, short v3, short v4);
void L1TRC_Send_L1I_Trace_Set_SRB_Mode(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_L1I_Trace_Egprs_ExtractPR(unsigned char v1, char v2, unsigned char v3);
void L1TRC_Send_L1I_Trace_New_TBF_Tid(unsigned char v1, short v2);
void L1TRC_Send_L1I_Trace_U2_data(unsigned short v1);
void L1TRC_Send_L1I_Trace_TAC_no_accumulate(unsigned char v1, long v2);
void L1TRC_Send_L1I_Trace_TBF_Status(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_L1I_Trace_MAC_Update_USF(short v1, short v2);
void L1TRC_Send_L1I_Trace_MAC_Granularity(unsigned char v1, short v2);
void L1TRC_Send_L1I_Trace_TBFStop(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1I_Trace_TBFStop_Base(unsigned char v1, unsigned char v2, unsigned char v3, char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_L1I_Trace_MAC_Grant(unsigned char v1, short v2, short v3, unsigned char v4);
void L1TRC_Send_L1I_Trace_RescheFCBSearch(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_ReportGPRS_DL_CB_Check(unsigned char v1, long v2, short v3);

void Set_L1I_EGPRS_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1I_EGPRS()	(L1I_EGPRS_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1I_EGPRS_UL_Block_H()	(ChkL1ModFltr_L1I_EGPRS()&&((L1I_EGPRS_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1I_EGPRS_U2_header_L()	(ChkL1ModFltr_L1I_EGPRS()&&((L1I_EGPRS_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1I_EGPRS_IRParams_M()	(ChkL1ModFltr_L1I_EGPRS()&&((L1I_EGPRS_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1I_EGPRS_EGPRS_PDAN_L()	(ChkL1ModFltr_L1I_EGPRS()&&((L1I_EGPRS_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1I_EGPRS_U1_cps_L()	(ChkL1ModFltr_L1I_EGPRS()&&((L1I_EGPRS_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1I_EGPRS_SRB_L()	(ChkL1ModFltr_L1I_EGPRS()&&((L1I_EGPRS_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1I_EGPRS_PR_TFI_L()	(ChkL1ModFltr_L1I_EGPRS()&&((L1I_EGPRS_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1I_EGPRS_newTBFtid_M()	(ChkL1ModFltr_L1I_EGPRS()&&((L1I_EGPRS_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_L1I_EGPRS_U2_data_L()	(ChkL1ModFltr_L1I_EGPRS()&&((L1I_EGPRS_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_L1I_EGPRS_TAC_M()	(ChkL1ModFltr_L1I_EGPRS()&&((L1I_EGPRS_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_L1I_EGPRS_MTBF_M()	(ChkL1ModFltr_L1I_EGPRS()&&((L1I_EGPRS_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_L1I_EGPRS_GEMINI20_M()	(ChkL1ModFltr_L1I_EGPRS()&&((L1I_EGPRS_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_L1I_EGPRS_DL_Block_M()	(ChkL1ModFltr_L1I_EGPRS()&&((L1I_EGPRS_Trace_Filter[2]&0x10)!=0))
#define ChkL1MsgFltr_L1I_Trace_U2_header()	ChkL1ClsFltr_L1I_EGPRS_U2_header_L()
#define ChkL1MsgFltr_L1I_Trace_UL_Header1()	ChkL1ClsFltr_L1I_EGPRS_UL_Block_H()
#define ChkL1MsgFltr_L1I_Trace_UL_Header2()	ChkL1ClsFltr_L1I_EGPRS_UL_Block_H()
#define ChkL1MsgFltr_L1I_Trace_UL_Header3()	ChkL1ClsFltr_L1I_EGPRS_UL_Block_H()
#define ChkL1MsgFltr_L1I_Trace_IRParams()	ChkL1ClsFltr_L1I_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1I_Trace_IRParams_TS()	ChkL1ClsFltr_L1I_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1I_Trace_EGPRS_PDAN()	ChkL1ClsFltr_L1I_EGPRS_EGPRS_PDAN_L()
#define ChkL1MsgFltr_L1I_Trace_Set_SRB_Mode()	ChkL1ClsFltr_L1I_EGPRS_SRB_L()
#define ChkL1MsgFltr_L1I_Trace_Egprs_ExtractPR()	ChkL1ClsFltr_L1I_EGPRS_PR_TFI_L()
#define ChkL1MsgFltr_L1I_Trace_New_TBF_Tid()	ChkL1ClsFltr_L1I_EGPRS_newTBFtid_M()
#define ChkL1MsgFltr_L1I_Trace_U2_data()	ChkL1ClsFltr_L1I_EGPRS_U2_data_L()
#define ChkL1MsgFltr_L1I_Trace_TAC_no_accumulate()	ChkL1ClsFltr_L1I_EGPRS_TAC_M()
#define ChkL1MsgFltr_L1I_Trace_TBF_Status()	ChkL1ClsFltr_L1I_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1I_Trace_MAC_Update_USF()	ChkL1ClsFltr_L1I_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1I_Trace_MAC_Granularity()	ChkL1ClsFltr_L1I_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1I_Trace_TBFStop()	ChkL1ClsFltr_L1I_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1I_Trace_TBFStop_Base()	ChkL1ClsFltr_L1I_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1I_Trace_MAC_Grant()	ChkL1ClsFltr_L1I_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1I_Trace_RescheFCBSearch()	ChkL1ClsFltr_L1I_EGPRS_GEMINI20_M()
#define ChkL1MsgFltr_L1C_ReportGPRS_DL_CB_Check()	ChkL1ClsFltr_L1I_EGPRS_DL_Block_M()


#endif
