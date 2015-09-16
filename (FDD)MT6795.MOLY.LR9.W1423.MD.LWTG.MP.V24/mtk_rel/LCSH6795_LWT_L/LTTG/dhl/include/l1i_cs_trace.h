#ifndef L1TRC_L1I_GSM_DEF_H
#define L1TRC_L1I_GSM_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1I_Str_Burst(v1)  (unsigned char)(v1+0)
#define L1I_Str_Bool(v1)  (unsigned char)(v1+2)
#define L1I_Str_RATSCCH_STATE(v1)  (unsigned char)(v1+4)
#define L1I_Str_NoExecute(v1)  (unsigned char)(v1+21)
#define L1I_Str_AbortOrNoExecute(v1)  (unsigned char)(v1+23)
#define L1I_Str_Cell(v1)  (unsigned char)(v1+25)
#define L1I_Str_Protect(v1)  (unsigned char)(v1+27)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define L1I_Msg_AGC(v1, v2, v3, v4, v5) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x001F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), (char)(v4), (char)(v5)));\
	} while(0)
#else
	#define L1I_Msg_AGC(v1, v2, v3, v4, v5)
#endif
#define L1I_Msg_AGC_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x001F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), (char)(v4), (char)(v5)))

#if defined(L1_CATCHER)
	#define L1I_Msg_C_AGCNB(v1, v2, v3, v4, v5, v6) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x011F, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (char)(v4), (char)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_C_AGCNB(v1, v2, v3, v4, v5, v6)
#endif
#define L1I_Msg_C_AGCNB_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x011F, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (char)(v4), (char)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Msg_PDTCH_TS0_AGC(v1, v2, v3, v4, v5, v6) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x021F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), (char)(v4), (char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_PDTCH_TS0_AGC(v1, v2, v3, v4, v5, v6)
#endif
#define L1I_Msg_PDTCH_TS0_AGC_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x021F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), (char)(v4), (char)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Msg_PDTCH_TS123_AGC(v1, v2, v3, v4, v5) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x031F, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_PDTCH_TS123_AGC(v1, v2, v3, v4, v5)
#endif
#define L1I_Msg_PDTCH_TS123_AGC_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x031F, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Msg_IM_TS0_AGC(v1, v2, v3, v4, v5) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x041F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), (char)(v4), (char)(v5)));\
	} while(0)
#else
	#define L1I_Msg_IM_TS0_AGC(v1, v2, v3, v4, v5)
#endif
#define L1I_Msg_IM_TS0_AGC_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x041F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), (char)(v4), (char)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Msg_IM_TS123_AGC(v1, v2, v3, v4) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x051F, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_IM_TS123_AGC(v1, v2, v3, v4)
#endif
#define L1I_Msg_IM_TS123_AGC_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x051F, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Msg_AGC_PM(v1, v2, v3, v4) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x061F, (short)(v1)), TRC_MERGE_4C((char)(v2), (char)(v3), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_AGC_PM(v1, v2, v3, v4)
#endif
#define L1I_Msg_AGC_PM_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x061F, (short)(v1)), TRC_MERGE_4C((char)(v2), (char)(v3), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Msg_AFC(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x071F, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_AFC(v1, v2, v3)
#endif
#define L1I_Msg_AFC_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x071F, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Msg_C_AFCNB(v1, v2, v3, v4, v5) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x081F, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_C_AFCNB(v1, v2, v3, v4, v5)
#endif
#define L1I_Msg_C_AFCNB_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x081F, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Msg_TAC(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x091F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_TAC(v1, v2, v3)
#endif
#define L1I_Msg_TAC_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x091F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Msg_TAC_Accumulate(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A1F, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_TAC_Accumulate(v1, v2, v3)
#endif
#define L1I_Msg_TAC_Accumulate_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A1F, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Msg_TAC_Adjust(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B1F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_TAC_Adjust(v1, v2)
#endif
#define L1I_Msg_TAC_Adjust_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B1F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Msg_Timer(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0C1F, (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_Timer(v1, v2, v3, v4, v5, v6, v7)
#endif
#define L1I_Msg_Timer_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0C1F, (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Msg_ReportRACh(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D1F, (unsigned char)(v1), (char)(v3)), (long)(v2));\
	} while(0)
#else
	#define L1I_Msg_ReportRACh(v1, v2, v3)
#endif
#define L1I_Msg_ReportRACh_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D1F, (unsigned char)(v1), (char)(v3)), (long)(v2))

#if defined(L1_CATCHER)
	#define L1I_Msg_UL_FACCH(v1) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E1F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_UL_FACCH(v1)
#endif
#define L1I_Msg_UL_FACCH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E1F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Msg_ReportTCh(v1, v2, v3, v4, v5) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F1F, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v5)));\
	} while(0)
#else
	#define L1I_Msg_ReportTCh(v1, v2, v3, v4, v5)
#endif
#define L1I_Msg_ReportTCh_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F1F, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v5)))

#if defined(L1_CATCHER)
	#define L1I_Msg_SetSync(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x101F, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define L1I_Msg_SetSync(v1, v2, v3)
#endif
#define L1I_Msg_SetSync_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x101F, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define L1I_Msg_TaskSetSync(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x111F, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define L1I_Msg_TaskSetSync(v1, v2, v3)
#endif
#define L1I_Msg_TaskSetSync_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x111F, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define L1I_Msg_TxPower(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x121F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_TxPower(v1, v2, v3)
#endif
#define L1I_Msg_TxPower_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x121F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Msg_ULDTX(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x131F, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1I_Msg_ULDTX(v1, v2)
#endif
#define L1I_Msg_ULDTX_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x131F, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Msg_RATSCChState(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x141F, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1I_Msg_RATSCChState(v1, v2)
#endif
#define L1I_Msg_RATSCChState_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x141F, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Msg_SetupTA(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x151F, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1I_Msg_SetupTA(v1, v2)
#endif
#define L1I_Msg_SetupTA_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x151F, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define L1I_Msg_FCBT_CNT(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x161F, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1I_Msg_FCBT_CNT(v1, v2)
#endif
#define L1I_Msg_FCBT_CNT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x161F, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_MonitorReportEnh1(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x171F, (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v6), (char)(v7)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define L1I_Trace_MonitorReportEnh1(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define L1I_Trace_MonitorReportEnh1_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x171F, (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v6), (char)(v7)), TRC_MERGE_4C((char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_MonitorReportEnh2(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x181F, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define L1I_Trace_MonitorReportEnh2(v1, v2, v3)
#endif
#define L1I_Trace_MonitorReportEnh2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x181F, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_MonitorReportEnh3(v1, v2, v3, v4, v5) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x191F, (short)(v3)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v4));\
	} while(0)
#else
	#define L1I_Trace_MonitorReportEnh3(v1, v2, v3, v4, v5)
#endif
#define L1I_Trace_MonitorReportEnh3_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x191F, (short)(v3)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_MonitorReportEnh4(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A1F, (unsigned char)(v1), (char)(v3)), (long)(v2));\
	} while(0)
#else
	#define L1I_Trace_MonitorReportEnh4(v1, v2, v3)
#endif
#define L1I_Trace_MonitorReportEnh4_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A1F, (unsigned char)(v1), (char)(v3)), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Msg_RepeatSACCh(v1, v2, v3, v4, v5, v6) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B1F, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1I_Msg_RepeatSACCh(v1, v2, v3, v4, v5, v6)
#endif
#define L1I_Msg_RepeatSACCh_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B1F, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define L1I_Msg_SIM_STATUS(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C1F, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1I_Msg_SIM_STATUS(v1, v2)
#endif
#define L1I_Msg_SIM_STATUS_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C1F, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define L1C_Msg_SIMTiming(v1, v2, v3, v4, v5) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D1F, (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (char)(v2)), (long)(v3));\
	} while(0)
#else
	#define L1C_Msg_SIMTiming(v1, v2, v3, v4, v5)
#endif
#define L1C_Msg_SIMTiming_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D1F, (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (char)(v2)), (long)(v3))

#if defined(L1_CATCHER)
	#define L1I_Msg_TimerNoExecute(v1, v2, v3, v4, v5, v6) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E1F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)));\
	} while(0)
#else
	#define L1I_Msg_TimerNoExecute(v1, v2, v3, v4, v5, v6)
#endif
#define L1I_Msg_TimerNoExecute_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E1F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)))

#if defined(L1_CATCHER)
	#define L1I_Msg_TimerAbortNoExecute(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F1F, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1I_Msg_TimerAbortNoExecute(v1, v2)
#endif
#define L1I_Msg_TimerAbortNoExecute_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F1F, (unsigned char)(v1), (unsigned char)(v2)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1I_GSM_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1I_Msg_AGC(unsigned char v1, short v2, char v3, char v4, char v5);
void L1TRC_Send_L1I_Msg_C_AGCNB(unsigned char v1, unsigned char v2, short v3, char v4, char v5, char v6);
void L1TRC_Send_L1I_Msg_PDTCH_TS0_AGC(unsigned char v1, short v2, char v3, char v4, char v5, unsigned char v6);
void L1TRC_Send_L1I_Msg_PDTCH_TS123_AGC(unsigned char v1, char v2, char v3, char v4, unsigned char v5);
void L1TRC_Send_L1I_Msg_IM_TS0_AGC(unsigned char v1, short v2, char v3, char v4, char v5);
void L1TRC_Send_L1I_Msg_IM_TS123_AGC(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_L1I_Msg_AGC_PM(short v1, char v2, char v3, char v4);
void L1TRC_Send_L1I_Msg_AFC(unsigned char v1, short v2, short v3);
void L1TRC_Send_L1I_Msg_C_AFCNB(unsigned char v1, unsigned char v2, short v3, short v4, short v5);
void L1TRC_Send_L1I_Msg_TAC(unsigned char v1, short v2, char v3);
void L1TRC_Send_L1I_Msg_TAC_Accumulate(unsigned char v1, short v2, short v3);
void L1TRC_Send_L1I_Msg_TAC_Adjust(unsigned char v1, short v2);
void L1TRC_Send_L1I_Msg_Timer(unsigned char v1, char v2, char v3, unsigned char v4, unsigned char v5, unsigned char v6, short v7);
void L1TRC_Send_L1I_Msg_ReportRACh(unsigned char v1, long v2, char v3);
void L1TRC_Send_L1I_Msg_UL_FACCH(unsigned char v1);
void L1TRC_Send_L1I_Msg_ReportTCh(unsigned char v1, unsigned char v2, unsigned char v3, short v4, unsigned char v5);
void L1TRC_Send_L1I_Msg_SetSync(unsigned char v1, long v2, short v3);
void L1TRC_Send_L1I_Msg_TaskSetSync(unsigned char v1, long v2, short v3);
void L1TRC_Send_L1I_Msg_TxPower(unsigned char v1, short v2, unsigned char v3);
void L1TRC_Send_L1I_Msg_ULDTX(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Msg_RATSCChState(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Msg_SetupTA(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Msg_FCBT_CNT(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Trace_MonitorReportEnh1(unsigned char v1, unsigned long v2, char v3, char v4, char v5, char v6, char v7, char v8);
void L1TRC_Send_L1I_Trace_MonitorReportEnh2(unsigned char v1, long v2, long v3);
void L1TRC_Send_L1I_Trace_MonitorReportEnh3(unsigned char v1, long v2, short v3, long v4, short v5);
void L1TRC_Send_L1I_Trace_MonitorReportEnh4(unsigned char v1, long v2, char v3);
void L1TRC_Send_L1I_Msg_RepeatSACCh(unsigned char v1, unsigned char v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_L1I_Msg_SIM_STATUS(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Msg_SIMTiming(unsigned char v1, char v2, long v3, short v4, short v5);
void L1TRC_Send_L1I_Msg_TimerNoExecute(unsigned char v1, unsigned char v2, char v3, char v4, char v5, char v6);
void L1TRC_Send_L1I_Msg_TimerAbortNoExecute(unsigned char v1, unsigned char v2);

void Set_L1I_GSM_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1I_GSM()	(L1I_GSM_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1I_GSM_Timer_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1I_GSM_AGC_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1I_GSM_AGCPDTCh_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1I_GSM_AFC_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1I_GSM_TAC_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1I_GSM_ReportRACh_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1I_GSM_SetSync_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1I_GSM_TxPower_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_L1I_GSM_UL_FACCH_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_L1I_GSM_ReportTCh_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_L1I_GSM_AGCIM_M()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_L1I_GSM_AMR_M()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_L1I_GSM_SetupTA_M()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_L1I_GSM_SetupFCBT_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_L1I_GSM_SIM_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_L1I_GSM_TAC_Debug_L()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_L1I_GSM_AGCPM_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_L1I_GSM_UL_DTX_L()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_L1I_GSM_R99_L()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_L1I_GSM_RepeatSACCh_L()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[3]&0x08)!=0))
#define ChkL1MsgFltr_L1I_Msg_AGC()	ChkL1ClsFltr_L1I_GSM_AGC_H()
#define ChkL1MsgFltr_L1I_Msg_C_AGCNB()	ChkL1ClsFltr_L1I_GSM_AGC_H()
#define ChkL1MsgFltr_L1I_Msg_PDTCH_TS0_AGC()	ChkL1ClsFltr_L1I_GSM_AGCPDTCh_H()
#define ChkL1MsgFltr_L1I_Msg_PDTCH_TS123_AGC()	ChkL1ClsFltr_L1I_GSM_AGCPDTCh_H()
#define ChkL1MsgFltr_L1I_Msg_IM_TS0_AGC()	ChkL1ClsFltr_L1I_GSM_AGCIM_M()
#define ChkL1MsgFltr_L1I_Msg_IM_TS123_AGC()	ChkL1ClsFltr_L1I_GSM_AGCIM_M()
#define ChkL1MsgFltr_L1I_Msg_AGC_PM()	ChkL1ClsFltr_L1I_GSM_AGCPM_H()
#define ChkL1MsgFltr_L1I_Msg_AFC()	ChkL1ClsFltr_L1I_GSM_AFC_H()
#define ChkL1MsgFltr_L1I_Msg_C_AFCNB()	ChkL1ClsFltr_L1I_GSM_AFC_H()
#define ChkL1MsgFltr_L1I_Msg_TAC()	ChkL1ClsFltr_L1I_GSM_TAC_H()
#define ChkL1MsgFltr_L1I_Msg_TAC_Accumulate()	ChkL1ClsFltr_L1I_GSM_TAC_Debug_L()
#define ChkL1MsgFltr_L1I_Msg_TAC_Adjust()	ChkL1ClsFltr_L1I_GSM_TAC_H()
#define ChkL1MsgFltr_L1I_Msg_Timer()	ChkL1ClsFltr_L1I_GSM_Timer_H()
#define ChkL1MsgFltr_L1I_Msg_ReportRACh()	ChkL1ClsFltr_L1I_GSM_ReportRACh_H()
#define ChkL1MsgFltr_L1I_Msg_UL_FACCH()	ChkL1ClsFltr_L1I_GSM_UL_FACCH_H()
#define ChkL1MsgFltr_L1I_Msg_ReportTCh()	ChkL1ClsFltr_L1I_GSM_ReportTCh_H()
#define ChkL1MsgFltr_L1I_Msg_SetSync()	ChkL1ClsFltr_L1I_GSM_SetSync_H()
#define ChkL1MsgFltr_L1I_Msg_TaskSetSync()	ChkL1ClsFltr_L1I_GSM_SetSync_H()
#define ChkL1MsgFltr_L1I_Msg_TxPower()	ChkL1ClsFltr_L1I_GSM_TxPower_H()
#define ChkL1MsgFltr_L1I_Msg_ULDTX()	ChkL1ClsFltr_L1I_GSM_UL_DTX_L()
#define ChkL1MsgFltr_L1I_Msg_RATSCChState()	ChkL1ClsFltr_L1I_GSM_AMR_M()
#define ChkL1MsgFltr_L1I_Msg_SetupTA()	ChkL1ClsFltr_L1I_GSM_SetupTA_M()
#define ChkL1MsgFltr_L1I_Msg_FCBT_CNT()	ChkL1ClsFltr_L1I_GSM_SetupFCBT_H()
#define ChkL1MsgFltr_L1I_Trace_MonitorReportEnh1()	ChkL1ClsFltr_L1I_GSM_R99_L()
#define ChkL1MsgFltr_L1I_Trace_MonitorReportEnh2()	ChkL1ClsFltr_L1I_GSM_R99_L()
#define ChkL1MsgFltr_L1I_Trace_MonitorReportEnh3()	ChkL1ClsFltr_L1I_GSM_R99_L()
#define ChkL1MsgFltr_L1I_Trace_MonitorReportEnh4()	ChkL1ClsFltr_L1I_GSM_R99_L()
#define ChkL1MsgFltr_L1I_Msg_RepeatSACCh()	ChkL1ClsFltr_L1I_GSM_RepeatSACCh_L()
#define ChkL1MsgFltr_L1I_Msg_SIM_STATUS()	ChkL1ClsFltr_L1I_GSM_SIM_H()
#define ChkL1MsgFltr_L1C_Msg_SIMTiming()	ChkL1ClsFltr_L1I_GSM_SIM_H()
#define ChkL1MsgFltr_L1I_Msg_TimerNoExecute()	ChkL1ClsFltr_L1I_GSM_Timer_H()
#define ChkL1MsgFltr_L1I_Msg_TimerAbortNoExecute()	ChkL1ClsFltr_L1I_GSM_Timer_H()


#endif
