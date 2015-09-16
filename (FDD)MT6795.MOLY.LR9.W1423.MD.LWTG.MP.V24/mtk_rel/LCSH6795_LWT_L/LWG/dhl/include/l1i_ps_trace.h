#ifndef L1TRC_L1I_GPRS_DEF_H
#define L1TRC_L1I_GPRS_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1I_GPRS_Str_Bool(v1)  (unsigned char)(v1+0)
#define L1I_PRACH_Str_States(v1)  (unsigned char)(v1+2)
#define L1I_TBF_Str_States(v1)  (unsigned char)(v1+8)
#define L1I_Str_GPRS_UL_CtrlMsg(v1)  (unsigned char)(v1+14)
#define L1I_Str_Check_RRBP(v1)  (unsigned char)(v1+28)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_PowerControlSetC(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0020, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define L1I_Trace_PowerControlSetC(v1, v2)
#endif
#define L1I_Trace_PowerControlSetC_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0020, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_ReportTBFStarted(v1, v2, v3, v4, v5) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0120, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_ReportTBFStarted(v1, v2, v3, v4, v5)
#endif
#define L1I_Trace_ReportTBFStarted_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0120, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_TBF_Transition(v1, v2, v3, v4, v5) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0220, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_TBF_Transition(v1, v2, v3, v4, v5)
#endif
#define L1I_Trace_TBF_Transition_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0220, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_ReportTBFStopped(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0320, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define L1I_Trace_ReportTBFStopped(v1, v2)
#endif
#define L1I_Trace_ReportTBFStopped_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0320, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define L1I_Trace_ReportPDTChConflict(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0420, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define L1I_Trace_ReportPDTChConflict(v1, v2)
#endif
#define L1I_Trace_ReportPDTChConflict_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0420, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_ReportPRACh(v1, v2, v3, v4) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0520, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define L1I_Trace_ReportPRACh(v1, v2, v3, v4)
#endif
#define L1I_Trace_ReportPRACh_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0520, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define L1I_Trace_ReportPollResp(v1, v2, v3, v4, v5, v6) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0620, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)));\
	} while(0)
#else
	#define L1I_Trace_ReportPollResp(v1, v2, v3, v4, v5, v6)
#endif
#define L1I_Trace_ReportPollResp_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0620, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)))

#if defined(L1_CATCHER)
	#define L1I_Trace_ReportSingleDL(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0720, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1I_Trace_ReportSingleDL(v1, v2)
#endif
#define L1I_Trace_ReportSingleDL_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0720, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define L1I_Trace_ReportULTwoPhase(v1, v2, v3, v4, v5, v6) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0820, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (char)(v5), (char)(v6)));\
	} while(0)
#else
	#define L1I_Trace_ReportULTwoPhase(v1, v2, v3, v4, v5, v6)
#endif
#define L1I_Trace_ReportULTwoPhase_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0820, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), (char)(v5), (char)(v6)))

#if defined(L1_CATCHER)
	#define L1I_Trace_ReportULWithoutTBF(v1, v2, v3, v4, v5) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0920, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_ReportULWithoutTBF(v1, v2, v3, v4, v5)
#endif
#define L1I_Trace_ReportULWithoutTBF_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0920, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_MACAssigned(v1, v2, v3, v4) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A20, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_MACAssigned(v1, v2, v3, v4)
#endif
#define L1I_Trace_MACAssigned_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A20, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_MACOurUSFMask(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B20, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1I_Trace_MACOurUSFMask(v1, v2)
#endif
#define L1I_Trace_MACOurUSFMask_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B20, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define L1I_Trace_MACTxSpec(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C20, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_MACTxSpec(v1, v2, v3)
#endif
#define L1I_Trace_MACTxSpec_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C20, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_MACSetReceivedUSF(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D20, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_MACSetReceivedUSF(v1, v2, v3)
#endif
#define L1I_Trace_MACSetReceivedUSF_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D20, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Trace_MACPreGetUplinkPDTCh(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E20, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_MACPreGetUplinkPDTCh(v1, v2, v3)
#endif
#define L1I_Trace_MACPreGetUplinkPDTCh_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E20, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Trace_MACULStatusReport(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F20, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_MACULStatusReport(v1, v2, v3)
#endif
#define L1I_Trace_MACULStatusReport_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F20, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_ExtractPR1() do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1020, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_ExtractPR1()
#endif
#define L1I_Trace_ExtractPR1_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1020, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_ExtractPR2() do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1120, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_ExtractPR2()
#endif
#define L1I_Trace_ExtractPR2_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1120, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_ExtractPR3(v1, v2, v3, v4) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1220, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_ExtractPR3(v1, v2, v3, v4)
#endif
#define L1I_Trace_ExtractPR3_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1220, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_GPRS_AGC0(v1) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1320, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_GPRS_AGC0(v1)
#endif
#define L1I_Trace_GPRS_AGC0_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1320, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_GPRS_AGC1(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1420, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_GPRS_AGC1(v1, v2, v3)
#endif
#define L1I_Trace_GPRS_AGC1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1420, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_GPRS_AGC2(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1520, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_GPRS_AGC2(v1, v2, v3)
#endif
#define L1I_Trace_GPRS_AGC2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1520, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_GPRS_AGC3(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1620, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_GPRS_AGC3(v1, v2, v3)
#endif
#define L1I_Trace_GPRS_AGC3_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1620, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_GPRS_AGC4(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1720, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_GPRS_AGC4(v1, v2, v3)
#endif
#define L1I_Trace_GPRS_AGC4_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1720, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_GPRS_AGC5(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1820, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define L1I_Trace_GPRS_AGC5(v1, v2)
#endif
#define L1I_Trace_GPRS_AGC5_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1820, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define L1I_Trace_UL_DATA(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1920, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_UL_DATA(v1, v2, v3)
#endif
#define L1I_Trace_UL_DATA_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1920, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Trace_UL_Ctrl(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A20, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define L1I_Trace_UL_Ctrl(v1, v2)
#endif
#define L1I_Trace_UL_Ctrl_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A20, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_PDAN(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1B20, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (char)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_PDAN(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define L1I_Trace_PDAN_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1B20, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (char)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Trace_PCA_AB(v1) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C20, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_PCA_AB(v1)
#endif
#define L1I_Trace_PCA_AB_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C20, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_PDTChCheckNoRRBP(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D20, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_PDTChCheckNoRRBP(v1, v2, v3)
#endif
#define L1I_Trace_PDTChCheckNoRRBP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D20, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_UpdateTimingAdvance(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E20, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Trace_UpdateTimingAdvance(v1, v2, v3)
#endif
#define L1I_Trace_UpdateTimingAdvance_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E20, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1I_GPRS_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1I_Trace_PowerControlSetC(unsigned char v1, char v2);
void L1TRC_Send_L1I_Trace_ReportTBFStarted(unsigned char v1, char v2, char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_L1I_Trace_TBF_Transition(unsigned char v1, unsigned char v2, char v3, char v4, unsigned char v5);
void L1TRC_Send_L1I_Trace_ReportTBFStopped(unsigned char v1, long v2);
void L1TRC_Send_L1I_Trace_ReportPDTChConflict(unsigned char v1, long v2);
void L1TRC_Send_L1I_Trace_ReportPRACh(unsigned char v1, unsigned char v2, long v3, short v4);
void L1TRC_Send_L1I_Trace_ReportPollResp(unsigned char v1, unsigned char v2, char v3, char v4, char v5, char v6);
void L1TRC_Send_L1I_Trace_ReportSingleDL(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Trace_ReportULTwoPhase(unsigned char v1, unsigned char v2, unsigned char v3, char v4, char v5, char v6);
void L1TRC_Send_L1I_Trace_ReportULWithoutTBF(unsigned char v1, unsigned char v2, char v3, char v4, char v5);
void L1TRC_Send_L1I_Trace_MACAssigned(unsigned char v1, char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1I_Trace_MACOurUSFMask(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Trace_MACTxSpec(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1I_Trace_MACSetReceivedUSF(unsigned char v1, char v2, char v3);
void L1TRC_Send_L1I_Trace_MACPreGetUplinkPDTCh(unsigned char v1, unsigned char v2, char v3);
void L1TRC_Send_L1I_Trace_MACULStatusReport(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1I_Trace_ExtractPR1(void);
void L1TRC_Send_L1I_Trace_ExtractPR2(void);
void L1TRC_Send_L1I_Trace_ExtractPR3(unsigned char v1, char v2, unsigned char v3, char v4);
void L1TRC_Send_L1I_Trace_GPRS_AGC0(char v1);
void L1TRC_Send_L1I_Trace_GPRS_AGC1(char v1, char v2, char v3);
void L1TRC_Send_L1I_Trace_GPRS_AGC2(char v1, char v2, char v3);
void L1TRC_Send_L1I_Trace_GPRS_AGC3(char v1, char v2, char v3);
void L1TRC_Send_L1I_Trace_GPRS_AGC4(char v1, char v2, char v3);
void L1TRC_Send_L1I_Trace_GPRS_AGC5(char v1, char v2);
void L1TRC_Send_L1I_Trace_UL_DATA(char v1, char v2, unsigned char v3);
void L1TRC_Send_L1I_Trace_UL_Ctrl(unsigned char v1, char v2);
void L1TRC_Send_L1I_Trace_PDAN(char v1, char v2, char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10, unsigned char v11, char v12);
void L1TRC_Send_L1I_Trace_PCA_AB(char v1);
void L1TRC_Send_L1I_Trace_PDTChCheckNoRRBP(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1I_Trace_UpdateTimingAdvance(unsigned char v1, char v2, char v3);

void Set_L1I_GPRS_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1I_GPRS()	(L1I_GPRS_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1I_GPRS_C_Value_M()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1I_GPRS_UL_Block_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1I_GPRS_ReportTBF_M()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1I_GPRS_ReportTBF_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1I_GPRS_ReportPDTChConflict_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1I_GPRS_ReportPRACh_M()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1I_GPRS_ReportPollResp_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1I_GPRS_ReportSingleDL_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_L1I_GPRS_ReportULTwoPhase_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_L1I_GPRS_ReportSingleULWithoutTBF_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_L1I_GPRS_L1D_Constellation_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_L1I_GPRS_mpal_uplink_transfer_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_L1I_GPRS_mpal_ul_status_report_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_L1I_GPRS_mpal_next_rrbp_frame_no_M()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_L1I_GPRS_L1I_UpdateTimingAdvance_M()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_L1I_GPRS_L1I_MACFrameTick_L()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_L1I_GPRS_SetReceivedUSF_L()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_L1I_GPRS_OurUSFMask_L()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_L1I_GPRS_PR_Payload_Type_L()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_L1I_GPRS_PR_TFI_L()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_L1I_GPRS_Block_AGC_L()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_L1I_GPRS_UL_Ctrl_Block_L()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[3]&0x20)!=0))
#define ChkL1MsgFltr_L1I_Trace_PowerControlSetC()	ChkL1ClsFltr_L1I_GPRS_C_Value_M()
#define ChkL1MsgFltr_L1I_Trace_ReportTBFStarted()	ChkL1ClsFltr_L1I_GPRS_ReportTBF_M()
#define ChkL1MsgFltr_L1I_Trace_TBF_Transition()	ChkL1ClsFltr_L1I_GPRS_ReportTBF_M()
#define ChkL1MsgFltr_L1I_Trace_ReportTBFStopped()	ChkL1ClsFltr_L1I_GPRS_ReportTBF_M()
#define ChkL1MsgFltr_L1I_Trace_ReportPDTChConflict()	ChkL1ClsFltr_L1I_GPRS_ReportPDTChConflict_H()
#define ChkL1MsgFltr_L1I_Trace_ReportPRACh()	ChkL1ClsFltr_L1I_GPRS_ReportPRACh_M()
#define ChkL1MsgFltr_L1I_Trace_ReportPollResp()	ChkL1ClsFltr_L1I_GPRS_ReportPollResp_H()
#define ChkL1MsgFltr_L1I_Trace_ReportSingleDL()	ChkL1ClsFltr_L1I_GPRS_ReportSingleDL_H()
#define ChkL1MsgFltr_L1I_Trace_ReportULTwoPhase()	ChkL1ClsFltr_L1I_GPRS_ReportULTwoPhase_H()
#define ChkL1MsgFltr_L1I_Trace_ReportULWithoutTBF()	ChkL1ClsFltr_L1I_GPRS_ReportSingleULWithoutTBF_H()
#define ChkL1MsgFltr_L1I_Trace_MACAssigned()	ChkL1ClsFltr_L1I_GPRS_L1I_MACFrameTick_L()
#define ChkL1MsgFltr_L1I_Trace_MACOurUSFMask()	ChkL1ClsFltr_L1I_GPRS_OurUSFMask_L()
#define ChkL1MsgFltr_L1I_Trace_MACTxSpec()	ChkL1ClsFltr_L1I_GPRS_L1D_Constellation_H()
#define ChkL1MsgFltr_L1I_Trace_MACSetReceivedUSF()	ChkL1ClsFltr_L1I_GPRS_SetReceivedUSF_L()
#define ChkL1MsgFltr_L1I_Trace_MACPreGetUplinkPDTCh()	ChkL1ClsFltr_L1I_GPRS_mpal_uplink_transfer_H()
#define ChkL1MsgFltr_L1I_Trace_MACULStatusReport()	ChkL1ClsFltr_L1I_GPRS_mpal_ul_status_report_H()
#define ChkL1MsgFltr_L1I_Trace_ExtractPR1()	ChkL1ClsFltr_L1I_GPRS_PR_Payload_Type_L()
#define ChkL1MsgFltr_L1I_Trace_ExtractPR2()	ChkL1ClsFltr_L1I_GPRS_PR_Payload_Type_L()
#define ChkL1MsgFltr_L1I_Trace_ExtractPR3()	ChkL1ClsFltr_L1I_GPRS_PR_TFI_L()
#define ChkL1MsgFltr_L1I_Trace_GPRS_AGC0()	ChkL1ClsFltr_L1I_GPRS_Block_AGC_L()
#define ChkL1MsgFltr_L1I_Trace_GPRS_AGC1()	ChkL1ClsFltr_L1I_GPRS_Block_AGC_L()
#define ChkL1MsgFltr_L1I_Trace_GPRS_AGC2()	ChkL1ClsFltr_L1I_GPRS_Block_AGC_L()
#define ChkL1MsgFltr_L1I_Trace_GPRS_AGC3()	ChkL1ClsFltr_L1I_GPRS_Block_AGC_L()
#define ChkL1MsgFltr_L1I_Trace_GPRS_AGC4()	ChkL1ClsFltr_L1I_GPRS_Block_AGC_L()
#define ChkL1MsgFltr_L1I_Trace_GPRS_AGC5()	ChkL1ClsFltr_L1I_GPRS_Block_AGC_L()
#define ChkL1MsgFltr_L1I_Trace_UL_DATA()	ChkL1ClsFltr_L1I_GPRS_UL_Block_H()
#define ChkL1MsgFltr_L1I_Trace_UL_Ctrl()	ChkL1ClsFltr_L1I_GPRS_UL_Block_H()
#define ChkL1MsgFltr_L1I_Trace_PDAN()	ChkL1ClsFltr_L1I_GPRS_UL_Ctrl_Block_L()
#define ChkL1MsgFltr_L1I_Trace_PCA_AB()	ChkL1ClsFltr_L1I_GPRS_UL_Block_H()
#define ChkL1MsgFltr_L1I_Trace_PDTChCheckNoRRBP()	ChkL1ClsFltr_L1I_GPRS_mpal_next_rrbp_frame_no_M()
#define ChkL1MsgFltr_L1I_Trace_UpdateTimingAdvance()	ChkL1ClsFltr_L1I_GPRS_L1I_UpdateTimingAdvance_M()


#endif
