#ifndef L1TRC_L1C_EGPRS_DEF_H
#define L1TRC_L1C_EGPRS_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1C_Str_Bool(v1)  (unsigned char)(v1+0)
#define L1C_Str_TBF_Direct(v1)  (unsigned char)(v1+2)
#define L1C_Str_TBFStart(v1)  (unsigned char)(v1+5)
#define L1C_Str_TBF_Status(v1)  (unsigned char)(v1+11)
#define L1C_Str_TBFMode(v1)  (unsigned char)(v1+14)
#define L1C_Str_UplinkMode(v1)  (unsigned char)(v1+16)
#define L1C_Str_PSHandoverType(v1)  (unsigned char)(v1+20)
#define L1C_Str_BackupRestore_VQ(v1)  (unsigned char)(v1+22)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trace_EGPRS_TBFStart(v1, v2, v3) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0027, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trace_EGPRS_TBFStart(v1, v2, v3)
#endif
#define L1T_Trace_EGPRS_TBFStart_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0027, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1T_Trace_DL_header(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0127, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trace_DL_header(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define L1T_Trace_DL_header_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0127, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1T_Trace_EGPRS_PDTCh(v1, v2, v3, v4, v5) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0227, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trace_EGPRS_PDTCh(v1, v2, v3, v4, v5)
#endif
#define L1T_Trace_EGPRS_PDTCh_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0227, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1T_Trace_EGPRS_PDTCh_Header(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0327, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v6), (char)(v7), (char)(v8), (char)(v9)), TRC_MERGE_4C((char)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trace_EGPRS_PDTCh_Header(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define L1T_Trace_EGPRS_PDTCh_Header_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0327, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v6), (char)(v7), (char)(v8), (char)(v9)), TRC_MERGE_4C((char)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1T_Trace_EGPRS_PDTCh2(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0427, (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trace_EGPRS_PDTCh2(v1, v2, v3, v4, v5, v6)
#endif
#define L1T_Trace_EGPRS_PDTCh2_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0427, (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1T_Trace_EGPRS_PDTCh2_Header(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0527, (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v7), (char)(v8)), TRC_MERGE_4C((char)(v9), (char)(v10), (char)(v11), (char)(v12)));\
	} while(0)
#else
	#define L1T_Trace_EGPRS_PDTCh2_Header(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define L1T_Trace_EGPRS_PDTCh2_Header_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0527, (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v7), (char)(v8)), TRC_MERGE_4C((char)(v9), (char)(v10), (char)(v11), (char)(v12)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1T_Trace_EGPRS_DSP_DPS_IR(v1, v2, v3, v4, v5) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0627, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trace_EGPRS_DSP_DPS_IR(v1, v2, v3, v4, v5)
#endif
#define L1T_Trace_EGPRS_DSP_DPS_IR_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0627, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1T_Trace_EGPRS_DSP_IR(v1, v2, v3, v4) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0727, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)));\
	} while(0)
#else
	#define L1T_Trace_EGPRS_DSP_IR(v1, v2, v3, v4)
#endif
#define L1T_Trace_EGPRS_DSP_IR_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0727, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)))

#if defined(L1_CATCHER)
	#define L1T_Trace_EGPRS_DSP_IR2(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0827, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trace_EGPRS_DSP_IR2(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define L1T_Trace_EGPRS_DSP_IR2_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0827, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1T_Trace_EGPRS_PDTCH_Conflict(v1, v2, v3, v4) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0927, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trace_EGPRS_PDTCH_Conflict(v1, v2, v3, v4)
#endif
#define L1T_Trace_EGPRS_PDTCH_Conflict_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0927, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1T_Trace_Set_SRB_Mode(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)));\
	} while(0)
#else
	#define L1T_Trace_Set_SRB_Mode(v1, v2, v3, v4, v5, v6)
#endif
#define L1T_Trace_Set_SRB_Mode_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1T_Trace_SRB_Assigned_Ts(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define L1T_Trace_SRB_Assigned_Ts(v1, v2, v3, v4, v5, v6)
#endif
#define L1T_Trace_SRB_Assigned_Ts_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1T_Trace_SBT(v1, v2, v3) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C27, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trace_SBT(v1, v2, v3)
#endif
#define L1T_Trace_SBT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C27, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1C_Trace_ReportPDTChBad_wBEP(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D27, (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Trace_ReportPDTChBad_wBEP(v1, v2, v3, v4, v5, v6)
#endif
#define L1C_Trace_ReportPDTChBad_wBEP_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0D27, (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1T_Trace_GPRS_PDTCh_wBEP(v1, v2, v3) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E27, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trace_GPRS_PDTCh_wBEP(v1, v2, v3)
#endif
#define L1T_Trace_GPRS_PDTCh_wBEP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E27, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trace_EgprsResetIR(v1, v2, v3, v4) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trace_EgprsResetIR(v1, v2, v3, v4)
#endif
#define L1T_Trace_EgprsResetIR_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F27, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_TBFStart_DL(v1, v2, v3, v4) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1027, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define L1C_Trace_TBFStart_DL(v1, v2, v3, v4)
#endif
#define L1C_Trace_TBFStart_DL_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1027, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_TBFStart_UL(v1, v2, v3, v4, v5) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1127, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define L1C_Trace_TBFStart_UL(v1, v2, v3, v4, v5)
#endif
#define L1C_Trace_TBFStart_UL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1127, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_TBFStart_DL_Temp(v1, v2, v3, v4, v5) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1227, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5));\
	} while(0)
#else
	#define L1C_Trace_TBFStart_DL_Temp(v1, v2, v3, v4, v5)
#endif
#define L1C_Trace_TBFStart_DL_Temp_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1227, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_TBFStart_UL_Temp(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1327, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD), (long)(v5));\
	} while(0)
#else
	#define L1C_Trace_TBFStart_UL_Temp(v1, v2, v3, v4, v5, v6)
#endif
#define L1C_Trace_TBFStart_UL_Temp_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1327, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_TBFStart_Base(v1, v2, v3, v4, v5) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1427, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Trace_TBFStart_Base(v1, v2, v3, v4, v5)
#endif
#define L1C_Trace_TBFStart_Base_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1427, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_TBF_Status(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1527, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define L1C_Trace_TBF_Status(v1, v2, v3, v4, v5, v6)
#endif
#define L1C_Trace_TBF_Status_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1527, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_TBFMode(v1, v2) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1627, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1C_Trace_TBFMode(v1, v2)
#endif
#define L1C_Trace_TBFMode_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1627, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_ResetIR(v1, v2) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1727, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1C_Trace_ResetIR(v1, v2)
#endif
#define L1C_Trace_ResetIR_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1727, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_TBFHandoverStart(v1, v2, v3, v4, v5) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1827, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_TBFHandoverStart(v1, v2, v3, v4, v5)
#endif
#define L1C_Msg_TBFHandoverStart_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1827, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_SetPDTChABCount(v1, v2) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1927, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_SetPDTChABCount(v1, v2)
#endif
#define L1C_Msg_SetPDTChABCount_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1927, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_GetPacketTimingAdvance(v1, v2) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_GetPacketTimingAdvance(v1, v2)
#endif
#define L1C_Msg_GetPacketTimingAdvance_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_SearchFBforBlindHO(v1, v2) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_SearchFBforBlindHO(v1, v2)
#endif
#define L1C_Msg_SearchFBforBlindHO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_UpdateHandoverRAChCount(v1, v2) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_UpdateHandoverRAChCount(v1, v2)
#endif
#define L1C_Msg_UpdateHandoverRAChCount_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_PDTChRAChStop(v1, v2) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_PDTChRAChStop(v1, v2)
#endif
#define L1C_Msg_PDTChRAChStop_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D27, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_BackupRestore_VQ(v1, v2, v3) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E27, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_BackupRestore_VQ(v1, v2, v3)
#endif
#define L1C_Msg_BackupRestore_VQ_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E27, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1C_EGPRS_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1T_Trace_EGPRS_TBFStart(unsigned char v1, char v2, char v3);
void L1TRC_Send_L1T_Trace_DL_header(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_L1T_Trace_EGPRS_PDTCh(unsigned char v1, char v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_L1T_Trace_EGPRS_PDTCh_Header(unsigned char v1, char v2, char v3, char v4, short v5, char v6, char v7, char v8, char v9, char v10);
void L1TRC_Send_L1T_Trace_EGPRS_PDTCh2(unsigned char v1, char v2, char v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_L1T_Trace_EGPRS_PDTCh2_Header(unsigned char v1, char v2, char v3, char v4, short v5, short v6, char v7, char v8, char v9, char v10, char v11, char v12);
void L1TRC_Send_L1T_Trace_EGPRS_DSP_DPS_IR(unsigned char v1, short v2, short v3, short v4, char v5);
void L1TRC_Send_L1T_Trace_EGPRS_DSP_IR(unsigned char v1, short v2, short v3, char v4);
void L1TRC_Send_L1T_Trace_EGPRS_DSP_IR2(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_L1T_Trace_EGPRS_PDTCH_Conflict(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_L1T_Trace_Set_SRB_Mode(unsigned char v1, char v2, char v3, char v4, char v5, char v6);
void L1TRC_Send_L1T_Trace_SRB_Assigned_Ts(unsigned char v1, char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_L1T_Trace_SBT(unsigned char v1, short v2, short v3);
void L1TRC_Send_L1C_Trace_ReportPDTChBad_wBEP(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_L1T_Trace_GPRS_PDTCh_wBEP(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_L1T_Trace_EgprsResetIR(unsigned char v1, char v2, char v3, unsigned char v4);
void L1TRC_Send_L1C_Trace_TBFStart_DL(unsigned char v1, char v2, unsigned char v3, long v4);
void L1TRC_Send_L1C_Trace_TBFStart_UL(unsigned char v1, char v2, unsigned char v3, long v4, unsigned char v5);
void L1TRC_Send_L1C_Trace_TBFStart_DL_Temp(unsigned char v1, unsigned char v2, char v3, unsigned char v4, long v5);
void L1TRC_Send_L1C_Trace_TBFStart_UL_Temp(unsigned char v1, unsigned char v2, char v3, unsigned char v4, long v5, unsigned char v6);
void L1TRC_Send_L1C_Trace_TBFStart_Base(unsigned char v1, unsigned char v2, char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_L1C_Trace_TBF_Status(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_L1C_Trace_TBFMode(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Trace_ResetIR(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Msg_TBFHandoverStart(unsigned char v1, unsigned char v2, short v3, short v4, short v5);
void L1TRC_Send_L1C_Msg_SetPDTChABCount(unsigned char v1, short v2);
void L1TRC_Send_L1C_Msg_GetPacketTimingAdvance(unsigned char v1, short v2);
void L1TRC_Send_L1C_Msg_SearchFBforBlindHO(unsigned char v1, short v2);
void L1TRC_Send_L1C_Msg_UpdateHandoverRAChCount(unsigned char v1, short v2);
void L1TRC_Send_L1C_Msg_PDTChRAChStop(unsigned char v1, short v2);
void L1TRC_Send_L1C_Msg_BackupRestore_VQ(unsigned char v1, unsigned char v2, unsigned char v3);

void Set_L1C_EGPRS_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1C_EGPRS()	(L1C_EGPRS_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()	(ChkL1ModFltr_L1C_EGPRS()&&((L1C_EGPRS_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1C_EGPRS_L1T_EGPRS_TBFStart_M()	(ChkL1ModFltr_L1C_EGPRS()&&((L1C_EGPRS_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1C_EGPRS_DL_header_L()	(ChkL1ModFltr_L1C_EGPRS()&&((L1C_EGPRS_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh__IR_L()	(ChkL1ModFltr_L1C_EGPRS()&&((L1C_EGPRS_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1C_EGPRS_SRB_L()	(ChkL1ModFltr_L1C_EGPRS()&&((L1C_EGPRS_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1C_EGPRS_SBT_L()	(ChkL1ModFltr_L1C_EGPRS()&&((L1C_EGPRS_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1C_EGPRS_MTBF_M()	(ChkL1ModFltr_L1C_EGPRS()&&((L1C_EGPRS_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1C_EGPRS_PSHO_M()	(ChkL1ModFltr_L1C_EGPRS()&&((L1C_EGPRS_Trace_Filter[1]&0x80)!=0))
#define ChkL1MsgFltr_L1T_Trace_EGPRS_TBFStart()	ChkL1ClsFltr_L1C_EGPRS_L1T_EGPRS_TBFStart_M()
#define ChkL1MsgFltr_L1T_Trace_DL_header()	ChkL1ClsFltr_L1C_EGPRS_DL_header_L()
#define ChkL1MsgFltr_L1T_Trace_EGPRS_PDTCh()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1T_Trace_EGPRS_PDTCh_Header()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1T_Trace_EGPRS_PDTCh2()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1T_Trace_EGPRS_PDTCh2_Header()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1T_Trace_EGPRS_DSP_DPS_IR()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh__IR_L()
#define ChkL1MsgFltr_L1T_Trace_EGPRS_DSP_IR()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1T_Trace_EGPRS_DSP_IR2()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1T_Trace_EGPRS_PDTCH_Conflict()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1T_Trace_Set_SRB_Mode()	ChkL1ClsFltr_L1C_EGPRS_SRB_L()
#define ChkL1MsgFltr_L1T_Trace_SRB_Assigned_Ts()	ChkL1ClsFltr_L1C_EGPRS_SRB_L()
#define ChkL1MsgFltr_L1T_Trace_SBT()	ChkL1ClsFltr_L1C_EGPRS_SBT_L()
#define ChkL1MsgFltr_L1C_Trace_ReportPDTChBad_wBEP()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1T_Trace_GPRS_PDTCh_wBEP()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1T_Trace_EgprsResetIR()	ChkL1ClsFltr_L1C_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1C_Trace_TBFStart_DL()	ChkL1ClsFltr_L1C_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1C_Trace_TBFStart_UL()	ChkL1ClsFltr_L1C_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1C_Trace_TBFStart_DL_Temp()	ChkL1ClsFltr_L1C_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1C_Trace_TBFStart_UL_Temp()	ChkL1ClsFltr_L1C_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1C_Trace_TBFStart_Base()	ChkL1ClsFltr_L1C_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1C_Trace_TBF_Status()	ChkL1ClsFltr_L1C_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1C_Trace_TBFMode()	ChkL1ClsFltr_L1C_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1C_Trace_ResetIR()	ChkL1ClsFltr_L1C_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1C_Msg_TBFHandoverStart()	ChkL1ClsFltr_L1C_EGPRS_PSHO_M()
#define ChkL1MsgFltr_L1C_Msg_SetPDTChABCount()	ChkL1ClsFltr_L1C_EGPRS_PSHO_M()
#define ChkL1MsgFltr_L1C_Msg_GetPacketTimingAdvance()	ChkL1ClsFltr_L1C_EGPRS_PSHO_M()
#define ChkL1MsgFltr_L1C_Msg_SearchFBforBlindHO()	ChkL1ClsFltr_L1C_EGPRS_PSHO_M()
#define ChkL1MsgFltr_L1C_Msg_UpdateHandoverRAChCount()	ChkL1ClsFltr_L1C_EGPRS_PSHO_M()
#define ChkL1MsgFltr_L1C_Msg_PDTChRAChStop()	ChkL1ClsFltr_L1C_EGPRS_PSHO_M()
#define ChkL1MsgFltr_L1C_Msg_BackupRestore_VQ()	ChkL1ClsFltr_L1C_EGPRS_PSHO_M()


#endif
