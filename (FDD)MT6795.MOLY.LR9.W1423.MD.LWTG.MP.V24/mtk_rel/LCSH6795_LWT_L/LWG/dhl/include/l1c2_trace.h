#ifndef L1TRC_L1C_GPRS_DEF_H
#define L1TRC_L1C_GPRS_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1C_Str_Bool(v1)  (unsigned char)(v1+0)
#define L1C_Str_GPRS_DL_CtrlMsg(v1)  (unsigned char)(v1+2)
#define L1C_Str_UplinkAccessMode(v1)  (unsigned char)(v1+58)
#define L1C_Str_BandInfo(v1)  (unsigned char)(v1+62)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_ReportPBCCh(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x001E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Trace_ReportPBCCh(v1, v2, v3)
#endif
#define L1C_Trace_ReportPBCCh_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x001E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_ReportNPBCCh(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x011E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Trace_ReportNPBCCh(v1, v2, v3)
#endif
#define L1C_Trace_ReportNPBCCh_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x011E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_ReportPPCh(v1, v2, v3, v4) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x021E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Trace_ReportPPCh(v1, v2, v3, v4)
#endif
#define L1C_Trace_ReportPPCh_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x021E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1C_Trace_ReportPTCChDown(v1, v2, v3, v4) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x031E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Trace_ReportPTCChDown(v1, v2, v3, v4)
#endif
#define L1C_Trace_ReportPTCChDown_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x031E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1C_Trace_PDTChGood_woRRBP_woFBI(v1, v2, v3, v4, v5) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x041E, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Trace_PDTChGood_woRRBP_woFBI(v1, v2, v3, v4, v5)
#endif
#define L1C_Trace_PDTChGood_woRRBP_woFBI_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x041E, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1C_Trace_PDTChGood_woRRBP_wFBI(v1, v2, v3, v4, v5) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x051E, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Trace_PDTChGood_woRRBP_wFBI(v1, v2, v3, v4, v5)
#endif
#define L1C_Trace_PDTChGood_woRRBP_wFBI_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x051E, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1C_Trace_PDTChGood_wRRBP_woFBI(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x061E, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), (char)(v6)));\
	} while(0)
#else
	#define L1C_Trace_PDTChGood_wRRBP_woFBI(v1, v2, v3, v4, v5, v6)
#endif
#define L1C_Trace_PDTChGood_wRRBP_woFBI_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x061E, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), (char)(v6)))

#if defined(L1_CATCHER)
	#define L1C_Trace_PDTChGood_wRRBP_wFBI(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x071E, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), (char)(v6)));\
	} while(0)
#else
	#define L1C_Trace_PDTChGood_wRRBP_wFBI(v1, v2, v3, v4, v5, v6)
#endif
#define L1C_Trace_PDTChGood_wRRBP_wFBI_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x071E, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), (char)(v6)))

#if defined(L1_CATCHER)
	#define L1C_Trace_PDTChGood_Ctrl(v1, v2, v3, v4) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x081E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Trace_PDTChGood_Ctrl(v1, v2, v3, v4)
#endif
#define L1C_Trace_PDTChGood_Ctrl_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x081E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1C_Trace_PDTChGood_Dummy_Ctrl(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x091E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Trace_PDTChGood_Dummy_Ctrl(v1, v2, v3)
#endif
#define L1C_Trace_PDTChGood_Dummy_Ctrl_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x091E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1C_Trace_ReportPDTChBad(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A1E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Trace_ReportPDTChBad(v1, v2, v3)
#endif
#define L1C_Trace_ReportPDTChBad_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A1E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_TBFStart(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0B1E, (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7)), (long)(v2));\
	} while(0)
#else
	#define L1C_Trace_TBFStart(v1, v2, v3, v4, v5, v6, v7)
#endif
#define L1C_Trace_TBFStart_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0B1E, (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7)), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_ReportIM(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C1E, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1C_Trace_ReportIM(v1, v2)
#endif
#define L1C_Trace_ReportIM_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C1E, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_ReportIMPower(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D1E, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Trace_ReportIMPower(v1, v2, v3)
#endif
#define L1C_Trace_ReportIMPower_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D1E, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_ReportPAGCh(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E1E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Trace_ReportPAGCh(v1, v2, v3)
#endif
#define L1C_Trace_ReportPAGCh_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E1E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1C_Trace_ReportSingleDL(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F1E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Trace_ReportSingleDL(v1, v2, v3)
#endif
#define L1C_Trace_ReportSingleDL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F1E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1C_Trace_ReportPACCh(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x101E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Trace_ReportPACCh(v1, v2, v3)
#endif
#define L1C_Trace_ReportPACCh_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x101E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1C_Trace_ReportPACCh_Ctrl(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x111E, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1C_Trace_ReportPACCh_Ctrl(v1, v2)
#endif
#define L1C_Trace_ReportPACCh_Ctrl_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x111E, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_SetupPBCCh(v1, v2, v3, v4) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x121E, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_SetupPBCCh(v1, v2, v3, v4)
#endif
#define L1C_Msg_SetupPBCCh_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x121E, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_SetupPPCh(v1, v2, v3, v4) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x131E, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_SetupPPCh(v1, v2, v3, v4)
#endif
#define L1C_Msg_SetupPPCh_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x131E, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_StartPAGCh(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x141E, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_StartPAGCh(v1, v2, v3)
#endif
#define L1C_Msg_StartPAGCh_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x141E, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_SetupPRACh(v1, v2, v3, v4) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x151E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_SetupPRACh(v1, v2, v3, v4)
#endif
#define L1C_Msg_SetupPRACh_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x151E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1C_Msg_StartPollRespAB(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x161E, (unsigned char)(v1), (char)(v3)), (long)(v2));\
	} while(0)
#else
	#define L1C_Msg_StartPollRespAB(v1, v2, v3)
#endif
#define L1C_Msg_StartPollRespAB_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x161E, (unsigned char)(v1), (char)(v3)), (long)(v2))

#if defined(L1_CATCHER)
	#define L1C_Msg_StartPollRespNB(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x171E, (unsigned char)(v1), (char)(v3)), (long)(v2));\
	} while(0)
#else
	#define L1C_Msg_StartPollRespNB(v1, v2, v3)
#endif
#define L1C_Msg_StartPollRespNB_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x171E, (unsigned char)(v1), (char)(v3)), (long)(v2))

#if defined(L1_CATCHER)
	#define L1C_Msg_StartSingleULwoTBF(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x181E, (unsigned char)(v1), (char)(v3)), (long)(v2));\
	} while(0)
#else
	#define L1C_Msg_StartSingleULwoTBF(v1, v2, v3)
#endif
#define L1C_Msg_StartSingleULwoTBF_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x181E, (unsigned char)(v1), (char)(v3)), (long)(v2))

#if defined(L1_CATCHER)
	#define L1C_Msg_StartSingleDL(v1, v2, v3, v4) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x191E, (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define L1C_Msg_StartSingleDL(v1, v2, v3, v4)
#endif
#define L1C_Msg_StartSingleDL_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x191E, (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define L1C_Msg_StartULTwoPhase(v1, v2, v3, v4) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1A1E, (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define L1C_Msg_StartULTwoPhase(v1, v2, v3, v4)
#endif
#define L1C_Msg_StartULTwoPhase_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1A1E, (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_StartIM(v1, v2) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B1E, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define L1C_Msg_StartIM(v1, v2)
#endif
#define L1C_Msg_StartIM_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B1E, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define L1C_Msg_TAS_L1D_INFO(v1, v2, v3, v4) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1C1E, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define L1C_Msg_TAS_L1D_INFO(v1, v2, v3, v4)
#endif
#define L1C_Msg_TAS_L1D_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1C1E, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define L1C_Msg_TAS_Criterion(v1, v2, v3, v4, v5) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1D1E, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define L1C_Msg_TAS_Criterion(v1, v2, v3, v4, v5)
#endif
#define L1C_Msg_TAS_Criterion_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1D1E, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define L1C_Msg_AntennaChange(v1, v2, v3) do {\
		if(L1C_GPRS_Trace_Filter[0]==1 && (L1C_GPRS_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E1E, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_AntennaChange(v1, v2, v3)
#endif
#define L1C_Msg_AntennaChange_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E1E, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1C_GPRS_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1C_Trace_ReportPBCCh(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1C_Trace_ReportNPBCCh(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1C_Trace_ReportPPCh(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1C_Trace_ReportPTCChDown(unsigned char v1, unsigned char v2, unsigned char v3, char v4);
void L1TRC_Send_L1C_Trace_PDTChGood_woRRBP_woFBI(unsigned char v1, char v2, char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_L1C_Trace_PDTChGood_woRRBP_wFBI(unsigned char v1, char v2, char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_L1C_Trace_PDTChGood_wRRBP_woFBI(unsigned char v1, char v2, char v3, unsigned char v4, unsigned char v5, char v6);
void L1TRC_Send_L1C_Trace_PDTChGood_wRRBP_wFBI(unsigned char v1, char v2, char v3, unsigned char v4, unsigned char v5, char v6);
void L1TRC_Send_L1C_Trace_PDTChGood_Ctrl(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1C_Trace_PDTChGood_Dummy_Ctrl(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1C_Trace_ReportPDTChBad(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1C_Trace_TBFStart(unsigned char v1, long v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_L1C_Trace_ReportIM(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Trace_ReportIMPower(unsigned char v1, char v2, short v3);
void L1TRC_Send_L1C_Trace_ReportPAGCh(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1C_Trace_ReportSingleDL(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1C_Trace_ReportPACCh(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1C_Trace_ReportPACCh_Ctrl(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Msg_SetupPBCCh(unsigned char v1, char v2, char v3, unsigned char v4);
void L1TRC_Send_L1C_Msg_SetupPPCh(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_L1C_Msg_StartPAGCh(unsigned char v1, char v2, char v3);
void L1TRC_Send_L1C_Msg_SetupPRACh(unsigned char v1, unsigned char v2, char v3, char v4);
void L1TRC_Send_L1C_Msg_StartPollRespAB(unsigned char v1, long v2, char v3);
void L1TRC_Send_L1C_Msg_StartPollRespNB(unsigned char v1, long v2, char v3);
void L1TRC_Send_L1C_Msg_StartSingleULwoTBF(unsigned char v1, long v2, char v3);
void L1TRC_Send_L1C_Msg_StartSingleDL(unsigned char v1, long v2, char v3, char v4);
void L1TRC_Send_L1C_Msg_StartULTwoPhase(unsigned char v1, long v2, char v3, char v4);
void L1TRC_Send_L1C_Msg_StartIM(unsigned char v1, char v2);
void L1TRC_Send_L1C_Msg_TAS_L1D_INFO(unsigned char v1, long v2, short v3, short v4);
void L1TRC_Send_L1C_Msg_TAS_Criterion(unsigned char v1, short v2, long v3, short v4, short v5);
void L1TRC_Send_L1C_Msg_AntennaChange(unsigned char v1, unsigned char v2, short v3);

void Set_L1C_GPRS_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1C_GPRS()	(L1C_GPRS_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1C_GPRS_ReportPBCCh_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1C_GPRS_ReportNPBCCh_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1C_GPRS_ReportPPCh_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1C_GPRS_ReportPTCCh_H()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1C_GPRS_ReportPDTCh_H()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1C_GPRS_L1T_TBFStart_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1C_GPRS_ReportPAGCh_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1C_GPRS_ReportSingleDL_H()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_L1C_GPRS_ReportULTwoPhase_H()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_L1C_GPRS_SetupPBCCh_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_L1C_GPRS_SetupPPCh_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_L1C_GPRS_StartPAGCh_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_L1C_GPRS_SetupPRACh_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_L1C_GPRS_StartPollResp_H()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_L1C_GPRS_StartSingleUL_H()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_L1C_GPRS_StartSingleDL_H()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_L1C_GPRS_StartULTwoPhase_H()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_L1C_GPRS_StartIM_M()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_L1C_GPRS_ReportIM_L()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_L1C_GPRS_TAS_H()	(ChkL1ModFltr_L1C_GPRS()&&((L1C_GPRS_Trace_Filter[3]&0x08)!=0))
#define ChkL1MsgFltr_L1C_Trace_ReportPBCCh()	ChkL1ClsFltr_L1C_GPRS_ReportPBCCh_M()
#define ChkL1MsgFltr_L1C_Trace_ReportNPBCCh()	ChkL1ClsFltr_L1C_GPRS_ReportNPBCCh_M()
#define ChkL1MsgFltr_L1C_Trace_ReportPPCh()	ChkL1ClsFltr_L1C_GPRS_ReportPPCh_M()
#define ChkL1MsgFltr_L1C_Trace_ReportPTCChDown()	ChkL1ClsFltr_L1C_GPRS_ReportPTCCh_H()
#define ChkL1MsgFltr_L1C_Trace_PDTChGood_woRRBP_woFBI()	ChkL1ClsFltr_L1C_GPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1C_Trace_PDTChGood_woRRBP_wFBI()	ChkL1ClsFltr_L1C_GPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1C_Trace_PDTChGood_wRRBP_woFBI()	ChkL1ClsFltr_L1C_GPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1C_Trace_PDTChGood_wRRBP_wFBI()	ChkL1ClsFltr_L1C_GPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1C_Trace_PDTChGood_Ctrl()	ChkL1ClsFltr_L1C_GPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1C_Trace_PDTChGood_Dummy_Ctrl()	ChkL1ClsFltr_L1C_GPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1C_Trace_ReportPDTChBad()	ChkL1ClsFltr_L1C_GPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1C_Trace_TBFStart()	ChkL1ClsFltr_L1C_GPRS_L1T_TBFStart_M()
#define ChkL1MsgFltr_L1C_Trace_ReportIM()	ChkL1ClsFltr_L1C_GPRS_ReportIM_L()
#define ChkL1MsgFltr_L1C_Trace_ReportIMPower()	ChkL1ClsFltr_L1C_GPRS_ReportIM_L()
#define ChkL1MsgFltr_L1C_Trace_ReportPAGCh()	ChkL1ClsFltr_L1C_GPRS_ReportPAGCh_M()
#define ChkL1MsgFltr_L1C_Trace_ReportSingleDL()	ChkL1ClsFltr_L1C_GPRS_ReportSingleDL_H()
#define ChkL1MsgFltr_L1C_Trace_ReportPACCh()	ChkL1ClsFltr_L1C_GPRS_ReportULTwoPhase_H()
#define ChkL1MsgFltr_L1C_Trace_ReportPACCh_Ctrl()	ChkL1ClsFltr_L1C_GPRS_ReportULTwoPhase_H()
#define ChkL1MsgFltr_L1C_Msg_SetupPBCCh()	ChkL1ClsFltr_L1C_GPRS_SetupPBCCh_M()
#define ChkL1MsgFltr_L1C_Msg_SetupPPCh()	ChkL1ClsFltr_L1C_GPRS_SetupPPCh_M()
#define ChkL1MsgFltr_L1C_Msg_StartPAGCh()	ChkL1ClsFltr_L1C_GPRS_StartPAGCh_M()
#define ChkL1MsgFltr_L1C_Msg_SetupPRACh()	ChkL1ClsFltr_L1C_GPRS_SetupPRACh_M()
#define ChkL1MsgFltr_L1C_Msg_StartPollRespAB()	ChkL1ClsFltr_L1C_GPRS_StartPollResp_H()
#define ChkL1MsgFltr_L1C_Msg_StartPollRespNB()	ChkL1ClsFltr_L1C_GPRS_StartPollResp_H()
#define ChkL1MsgFltr_L1C_Msg_StartSingleULwoTBF()	ChkL1ClsFltr_L1C_GPRS_StartSingleUL_H()
#define ChkL1MsgFltr_L1C_Msg_StartSingleDL()	ChkL1ClsFltr_L1C_GPRS_StartSingleDL_H()
#define ChkL1MsgFltr_L1C_Msg_StartULTwoPhase()	ChkL1ClsFltr_L1C_GPRS_StartULTwoPhase_H()
#define ChkL1MsgFltr_L1C_Msg_StartIM()	ChkL1ClsFltr_L1C_GPRS_StartIM_M()
#define ChkL1MsgFltr_L1C_Msg_TAS_L1D_INFO()	ChkL1ClsFltr_L1C_GPRS_TAS_H()
#define ChkL1MsgFltr_L1C_Msg_TAS_Criterion()	ChkL1ClsFltr_L1C_GPRS_TAS_H()
#define ChkL1MsgFltr_L1C_Msg_AntennaChange()	ChkL1ClsFltr_L1C_GPRS_TAS_H()


#endif
