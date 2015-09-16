#ifndef L1TRC_EL1_PHS_1_DEF_H
#define L1TRC_EL1_PHS_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define PHS_Req_Evt_String(v1)  (unsigned char)(v1+0)
#define PHS_Meas_Type_String(v1)  (unsigned char)(v1+24)
#define PHS_Cfn_Type_String(v1)  (unsigned char)(v1+32)
#define PHS_Conflict_Rsn_String(v1)  (unsigned char)(v1+43)
#define PHS_Comm_String(v1)  (unsigned char)(v1+55)
#define PHS_Param_Log_Type_String(v1)  (unsigned char)(v1+169)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_FUNC_ENTRY(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0001, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_FUNC_ENTRY(v1)
#endif
#define PHS_LOG_FUNC_ENTRY_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0001, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_FUNC_ENTRY_ISR(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0101, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_FUNC_ENTRY_ISR(v1)
#endif
#define PHS_LOG_FUNC_ENTRY_ISR_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0101, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_FUNC_ENTRY_ISR_LOW(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0201, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_FUNC_ENTRY_ISR_LOW(v1)
#endif
#define PHS_LOG_FUNC_ENTRY_ISR_LOW_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0201, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_ABS_TIME_RPT(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0301, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_ABS_TIME_RPT(v1, v2, v3)
#endif
#define PHS_LOG_ABS_TIME_RPT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0301, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_CLR_EXE_EVT(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0401, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_CLR_EXE_EVT(v1, v2)
#endif
#define PHS_LOG_CLR_EXE_EVT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0401, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_CLR_SCHDL_EVT(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0501, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_CLR_SCHDL_EVT(v1, v2)
#endif
#define PHS_LOG_CLR_SCHDL_EVT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0501, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_EXE_EVT(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0601, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_SRCH_EXE_EVT(v1)
#endif
#define PHS_LOG_SRCH_EXE_EVT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0601, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_HP_EXE_EVT(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0701, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_SRCH_HP_EXE_EVT(v1)
#endif
#define PHS_LOG_SRCH_HP_EXE_EVT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0701, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SRCH_LP_EXE_EVT(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0801, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_SRCH_LP_EXE_EVT(v1)
#endif
#define PHS_LOG_SRCH_LP_EXE_EVT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0801, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MEAS_EXE_LEN(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0901, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_MEAS_EXE_LEN(v1, v2)
#endif
#define PHS_LOG_MEAS_EXE_LEN_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0901, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_FIND_EXE_EVT(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A01, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_FIND_EXE_EVT(v1, v2)
#endif
#define PHS_LOG_FIND_EXE_EVT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A01, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_FIND_HP_EXE_EVT(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B01, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_FIND_HP_EXE_EVT(v1, v2)
#endif
#define PHS_LOG_FIND_HP_EXE_EVT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B01, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_FIND_LP_EXE_EVT(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C01, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_FIND_LP_EXE_EVT(v1, v2)
#endif
#define PHS_LOG_FIND_LP_EXE_EVT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C01, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_EXT_WIN_TIME(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x0D01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v9));\
	} while(0)
#else
	#define PHS_LOG_EXT_WIN_TIME(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define PHS_LOG_EXT_WIN_TIME_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x0D01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v9))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PHY_TRACK_CHK(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0E01, (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PHS_LOG_PHY_TRACK_CHK(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define PHS_LOG_PHY_TRACK_CHK_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0E01, (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PHY_TRACK_CHK_CALC(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0F01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_PHY_TRACK_CHK_CALC(v1, v2)
#endif
#define PHS_LOG_PHY_TRACK_CHK_CALC_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0F01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PHY_TRACK_CHK_DONE(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1001, (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v10), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v9));\
	} while(0)
#else
	#define PHS_LOG_PHY_TRACK_CHK_DONE(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define PHS_LOG_PHY_TRACK_CHK_DONE_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x1001, (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v10), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v9))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_EXT_LIFE_TIME(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1101, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PHS_LOG_EXT_LIFE_TIME(v1, v2, v3, v4)
#endif
#define PHS_LOG_EXT_LIFE_TIME_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1101, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_FLOW_TRACE(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1201, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_FLOW_TRACE(v1)
#endif
#define PHS_LOG_FLOW_TRACE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1201, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GET_NXT_TIME(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1301, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_GET_NXT_TIME(v1, v2, v3)
#endif
#define PHS_LOG_GET_NXT_TIME_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1301, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_HNDL_QUE_MCH_REQ(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1401, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_HNDL_QUE_MCH_REQ(v1)
#endif
#define PHS_LOG_HNDL_QUE_MCH_REQ_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1401, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_HNDL_QUE_EVT_REQ(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1501, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_HNDL_QUE_EVT_REQ(v1)
#endif
#define PHS_LOG_HNDL_QUE_EVT_REQ_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1501, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_QUE_MCH_REQ(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1601, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_QUE_MCH_REQ(v1)
#endif
#define PHS_LOG_QUE_MCH_REQ_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1601, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_QUE_EVT_REQ(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1701, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_QUE_EVT_REQ(v1)
#endif
#define PHS_LOG_QUE_EVT_REQ_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1701, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_QUE_EVT_REQ_FAIL(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1801, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_QUE_EVT_REQ_FAIL(v1)
#endif
#define PHS_LOG_QUE_EVT_REQ_FAIL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1801, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_TIME_SCHDL_ST(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1901, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_TIME_SCHDL_ST(v1)
#endif
#define PHS_LOG_TIME_SCHDL_ST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1901, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_REQ_ACT(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A01, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_REQ_ACT(v1, v2)
#endif
#define PHS_LOG_REQ_ACT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A01, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GAP_REQ_ACT(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1B01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_GAP_REQ_ACT(v1, v2, v3, v4)
#endif
#define PHS_LOG_GAP_REQ_ACT_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1B01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PHS_ABORT_ACT(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_PHS_ABORT_ACT(v1, v2, v3, v4)
#endif
#define PHS_LOG_PHS_ABORT_ACT_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_DRV_CFN_RCV(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D01, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_DRV_CFN_RCV(v1)
#endif
#define PHS_LOG_DRV_CFN_RCV_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D01, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MAC_DRX_CYC_CHK(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E01, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_LOG_MAC_DRX_CYC_CHK(v1, v2)
#endif
#define PHS_LOG_MAC_DRX_CYC_CHK_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E01, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RNTI_EXE_EXPIRE(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1F01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_RNTI_EXE_EXPIRE(v1, v2, v3)
#endif
#define PHS_LOG_RNTI_EXE_EXPIRE_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1F01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RS_EXE_EXPIRE(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2001, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_RS_EXE_EXPIRE(v1, v2, v3)
#endif
#define PHS_LOG_RS_EXE_EXPIRE_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2001, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_CMD_ADD(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2101, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_CMD_ADD(v1, v2, v3)
#endif
#define PHS_LOG_CMD_ADD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2101, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_EXE_EVT_TYPE(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2201, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_EXE_EVT_TYPE(v1)
#endif
#define PHS_LOG_EXE_EVT_TYPE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2201, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RNTI_SET_EXIST(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2301, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_RNTI_SET_EXIST(v1)
#endif
#define PHS_LOG_RNTI_SET_EXIST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2301, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RNTI_CTRL_ISR(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2401, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_RNTI_CTRL_ISR(v1, v2)
#endif
#define PHS_LOG_RNTI_CTRL_ISR_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2401, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RS_CTRL_ISR(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2501, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_RS_CTRL_ISR(v1, v2)
#endif
#define PHS_LOG_RS_CTRL_ISR_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2501, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PHY_TRACK_CTRL_ISR(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2601, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_PHY_TRACK_CTRL_ISR(v1, v2, v3)
#endif
#define PHS_LOG_PHY_TRACK_CTRL_ISR_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2601, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_STRT_DRX_TRIG_TMR(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2701, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_STRT_DRX_TRIG_TMR(v1, v2)
#endif
#define PHS_LOG_STRT_DRX_TRIG_TMR_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2701, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SLEEP_PARAM(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2801, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_SLEEP_PARAM(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_SLEEP_PARAM_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2801, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SLEEP_TIME(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2901, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_LOG_SLEEP_TIME(v1)
#endif
#define PHS_LOG_SLEEP_TIME_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2901, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_REDUCE_SLEEP_TIME(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2A01, (unsigned short)(v2)), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_LOG_REDUCE_SLEEP_TIME(v1, v2)
#endif
#define PHS_LOG_REDUCE_SLEEP_TIME_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2A01, (unsigned short)(v2)), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SCHDL_EVT_NUM(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2B01, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_SCHDL_EVT_NUM(v1, v2)
#endif
#define PHS_LOG_SCHDL_EVT_NUM_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2B01, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_COPY_SCHDL_EVT(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2C01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_COPY_SCHDL_EVT(v1, v2, v3)
#endif
#define PHS_LOG_COPY_SCHDL_EVT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2C01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PARAM_ABS_TIME(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x2D01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9));\
	} while(0)
#else
	#define PHS_LOG_PARAM_ABS_TIME(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define PHS_LOG_PARAM_ABS_TIME_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x2D01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PARAM_ABS_TIME1(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2E01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define PHS_LOG_PARAM_ABS_TIME1(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PHS_LOG_PARAM_ABS_TIME1_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x2E01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PHS_RNTI_STUS(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2F01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_PHS_RNTI_STUS(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_PHS_RNTI_STUS_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2F01, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_UPDT_SRV_CID(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3001, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_UPDT_SRV_CID(v1)
#endif
#define PHS_LOG_UPDT_SRV_CID_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3001, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_UPDT_SRV_CID_ISR(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3101, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_UPDT_SRV_CID_ISR(v1)
#endif
#define PHS_LOG_UPDT_SRV_CID_ISR_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3101, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_CHNG_OLD_END_WIN(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3201, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_CHNG_OLD_END_WIN(v1, v2)
#endif
#define PHS_LOG_CHNG_OLD_END_WIN_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3201, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_CHNG_NEW_STRT_WIN(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3301, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_CHNG_NEW_STRT_WIN(v1, v2)
#endif
#define PHS_LOG_CHNG_NEW_STRT_WIN_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3301, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_EXE_CMD_END_TIME(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3401, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PHS_LOG_EXE_CMD_END_TIME(v1, v2, v3, v4)
#endif
#define PHS_LOG_EXE_CMD_END_TIME_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3401, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_FINAL_EXE_TIME(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3501, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_FINAL_EXE_TIME(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_FINAL_EXE_TIME_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3501, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_FINAL_EXE_TIME_1(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3601, (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_FINAL_EXE_TIME_1(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_FINAL_EXE_TIME_1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3601, (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RNTI_CTRL_EN_TIME(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3701, (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PHS_LOG_RNTI_CTRL_EN_TIME(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_RNTI_CTRL_EN_TIME_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3701, (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MAC_DRX_OP_GAP(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x3801, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define PHS_LOG_MAC_DRX_OP_GAP(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_MAC_DRX_OP_GAP_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x3801, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RNTI_CTRL_REL_TIME(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3901, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_RNTI_CTRL_REL_TIME(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_RNTI_CTRL_REL_TIME_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3901, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PRESCH_CMD_TIME(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3A01, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_PRESCH_CMD_TIME(v1, v2, v3, v4)
#endif
#define PHS_LOG_PRESCH_CMD_TIME_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3A01, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PRESCH_CMD_DONE(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3B01, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_PRESCH_CMD_DONE(v1)
#endif
#define PHS_LOG_PRESCH_CMD_DONE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3B01, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_LIFE_TIME_EXPIRE(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3C01, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_LIFE_TIME_EXPIRE(v1)
#endif
#define PHS_LOG_LIFE_TIME_EXPIRE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3C01, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PRESCH_CMD_INDX(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3D01, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_PRESCH_CMD_INDX(v1, v2)
#endif
#define PHS_LOG_PRESCH_CMD_INDX_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3D01, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MEAS_CMD_TYPE(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E01, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_MEAS_CMD_TYPE(v1, v2)
#endif
#define PHS_LOG_MEAS_CMD_TYPE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E01, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_INTRA_CS_NUM(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3F01, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_INTRA_CS_NUM(v1)
#endif
#define PHS_LOG_INTRA_CS_NUM_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3F01, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_INTER_CS_NUM(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4001, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_INTER_CS_NUM(v1)
#endif
#define PHS_LOG_INTER_CS_NUM_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4001, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_FUNC_RTN(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4101, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_FUNC_RTN(v1)
#endif
#define PHS_LOG_FUNC_RTN_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4101, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SCHDL_EVT_INFO(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4201, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_SCHDL_EVT_INFO(v1, v2)
#endif
#define PHS_LOG_SCHDL_EVT_INFO_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4201, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_UPDT_MIN_EVT_TIME(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4301, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_UPDT_MIN_EVT_TIME(v1, v2)
#endif
#define PHS_LOG_UPDT_MIN_EVT_TIME_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4301, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_NXT_GAP_TIME(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4401, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PHS_LOG_NXT_GAP_TIME(v1, v2, v3, v4)
#endif
#define PHS_LOG_NXT_GAP_TIME_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4401, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_NXT_STBY_GAP_TIME(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4501, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_NXT_STBY_GAP_TIME(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_NXT_STBY_GAP_TIME_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4501, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_EXE_EVT_REMAP(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4601, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_EXE_EVT_REMAP(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_EXE_EVT_REMAP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4601, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PARAM_3(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4701, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_PARAM_3(v1, v2, v3)
#endif
#define PHS_LOG_PARAM_3_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4701, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PARAM_6(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x4801, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define PHS_LOG_PARAM_6(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PHS_LOG_PARAM_6_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x4801, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PHS_RNTI_VALUE(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4901, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)));\
	} while(0)
#else
	#define PHS_LOG_PHS_RNTI_VALUE(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_PHS_RNTI_VALUE_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4901, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_CH_RNTI_ACT(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4A01, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_CH_RNTI_ACT(v1, v2, v3)
#endif
#define PHS_LOG_CH_RNTI_ACT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4A01, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_REDUCE_END_TIME(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4B01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_REDUCE_END_TIME(v1, v2, v3)
#endif
#define PHS_LOG_REDUCE_END_TIME_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4B01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_ENBL_RX_CTRL(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4C01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_ENBL_RX_CTRL(v1, v2)
#endif
#define PHS_LOG_ENBL_RX_CTRL_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4C01, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MEAS_TRIG(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x4D01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define PHS_LOG_MEAS_TRIG(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PHS_LOG_MEAS_TRIG_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_1S2C(0x4D01, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GAP_ACTV(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4E01, (unsigned char)(v1), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_GAP_ACTV(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_GAP_ACTV_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4E01, (unsigned char)(v1), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_HNDLR_ENTRY(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4F01, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_HNDLR_ENTRY(v1)
#endif
#define PHS_LOG_HNDLR_ENTRY_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4F01, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GET_NXT_TIME_DBG(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5001, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_GET_NXT_TIME_DBG(v1, v2, v3)
#endif
#define PHS_LOG_GET_NXT_TIME_DBG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5001, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_EXE_EVT_STUS_DBG(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5101, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_EXE_EVT_STUS_DBG(v1, v2, v3, v4)
#endif
#define PHS_LOG_EXE_EVT_STUS_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5101, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SCH_EVT_ACTIVE_DBG(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5201, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_SCH_EVT_ACTIVE_DBG(v1, v2, v3)
#endif
#define PHS_LOG_SCH_EVT_ACTIVE_DBG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5201, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RTB_CONFLICT(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5301, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_RTB_CONFLICT(v1, v2)
#endif
#define PHS_LOG_RTB_CONFLICT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5301, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SCH_DROP_RATE(v1) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5401, (unsigned short)(v1)));\
	} while(0)
#else
	#define PHS_LOG_SCH_DROP_RATE(v1)
#endif
#define PHS_LOG_SCH_DROP_RATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5401, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_INTRA_CONTI_INTER() do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5501, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_INTRA_CONTI_INTER()
#endif
#define PHS_LOG_INTRA_CONTI_INTER_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5501, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_DRX_INACT(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5601, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_DRX_INACT(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_DRX_INACT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5601, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PAG_DUMP_INFO(v1, v2, v3, v4) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5701, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PHS_LOG_PAG_DUMP_INFO(v1, v2, v3, v4)
#endif
#define PHS_LOG_PAG_DUMP_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5701, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_UNSLP_CNT(v1, v2) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5801, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_LOG_UNSLP_CNT(v1, v2)
#endif
#define PHS_LOG_UNSLP_CNT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5801, (unsigned char)(v2), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PAG_DUMP_INFO2(v1, v2, v3) do {\
		if(EL1_PHS_1_Trace_Filter[0]==1 && (EL1_PHS_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5901, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_PAG_DUMP_INFO2(v1, v2, v3)
#endif
#define PHS_LOG_PAG_DUMP_INFO2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5901, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1_PHS_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_PHS_LOG_FUNC_ENTRY(unsigned char v1);
void L1TRC_Send_PHS_LOG_FUNC_ENTRY_ISR(unsigned char v1);
void L1TRC_Send_PHS_LOG_FUNC_ENTRY_ISR_LOW(unsigned char v1);
void L1TRC_Send_PHS_LOG_ABS_TIME_RPT(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_CLR_EXE_EVT(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_CLR_SCHDL_EVT(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_SRCH_EXE_EVT(unsigned char v1);
void L1TRC_Send_PHS_LOG_SRCH_HP_EXE_EVT(unsigned char v1);
void L1TRC_Send_PHS_LOG_SRCH_LP_EXE_EVT(unsigned char v1);
void L1TRC_Send_PHS_LOG_MEAS_EXE_LEN(unsigned char v1, unsigned long v2);
void L1TRC_Send_PHS_LOG_FIND_EXE_EVT(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_FIND_HP_EXE_EVT(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_FIND_LP_EXE_EVT(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_EXT_WIN_TIME(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned char v5, unsigned long v6, unsigned long v7, unsigned char v8, unsigned long v9);
void L1TRC_Send_PHS_LOG_PHY_TRACK_CHK(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_PHS_LOG_PHY_TRACK_CHK_CALC(unsigned long v1, unsigned long v2);
void L1TRC_Send_PHS_LOG_PHY_TRACK_CHK_DONE(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned long v9, unsigned char v10);
void L1TRC_Send_PHS_LOG_EXT_LIFE_TIME(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_PHS_LOG_FLOW_TRACE(unsigned char v1);
void L1TRC_Send_PHS_LOG_GET_NXT_TIME(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_HNDL_QUE_MCH_REQ(unsigned char v1);
void L1TRC_Send_PHS_LOG_HNDL_QUE_EVT_REQ(unsigned char v1);
void L1TRC_Send_PHS_LOG_QUE_MCH_REQ(unsigned char v1);
void L1TRC_Send_PHS_LOG_QUE_EVT_REQ(unsigned char v1);
void L1TRC_Send_PHS_LOG_QUE_EVT_REQ_FAIL(unsigned char v1);
void L1TRC_Send_PHS_LOG_TIME_SCHDL_ST(unsigned char v1);
void L1TRC_Send_PHS_LOG_REQ_ACT(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_GAP_REQ_ACT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_PHS_LOG_PHS_ABORT_ACT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_PHS_LOG_DRV_CFN_RCV(unsigned char v1);
void L1TRC_Send_PHS_LOG_MAC_DRX_CYC_CHK(unsigned long v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_RNTI_EXE_EXPIRE(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_RS_EXE_EXPIRE(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_CMD_ADD(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_EXE_EVT_TYPE(unsigned char v1);
void L1TRC_Send_PHS_LOG_RNTI_SET_EXIST(unsigned char v1);
void L1TRC_Send_PHS_LOG_RNTI_CTRL_ISR(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_RS_CTRL_ISR(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_PHY_TRACK_CTRL_ISR(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_STRT_DRX_TRIG_TMR(unsigned long v1, unsigned long v2);
void L1TRC_Send_PHS_LOG_SLEEP_PARAM(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PHS_LOG_SLEEP_TIME(unsigned long v1);
void L1TRC_Send_PHS_LOG_REDUCE_SLEEP_TIME(unsigned long v1, unsigned short v2);
void L1TRC_Send_PHS_LOG_SCHDL_EVT_NUM(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_COPY_SCHDL_EVT(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_PARAM_ABS_TIME(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9);
void L1TRC_Send_PHS_LOG_PARAM_ABS_TIME1(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_PHS_LOG_PHS_RNTI_STUS(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_PHS_LOG_UPDT_SRV_CID(unsigned char v1);
void L1TRC_Send_PHS_LOG_UPDT_SRV_CID_ISR(unsigned char v1);
void L1TRC_Send_PHS_LOG_CHNG_OLD_END_WIN(unsigned long v1, unsigned long v2);
void L1TRC_Send_PHS_LOG_CHNG_NEW_STRT_WIN(unsigned long v1, unsigned long v2);
void L1TRC_Send_PHS_LOG_EXE_CMD_END_TIME(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_PHS_LOG_FINAL_EXE_TIME(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_PHS_LOG_FINAL_EXE_TIME_1(unsigned long v1, unsigned long v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_PHS_LOG_RNTI_CTRL_EN_TIME(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned char v5);
void L1TRC_Send_PHS_LOG_MAC_DRX_OP_GAP(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_PHS_LOG_RNTI_CTRL_REL_TIME(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_PHS_LOG_PRESCH_CMD_TIME(unsigned long v1, unsigned long v2, unsigned short v3, unsigned char v4);
void L1TRC_Send_PHS_LOG_PRESCH_CMD_DONE(unsigned char v1);
void L1TRC_Send_PHS_LOG_LIFE_TIME_EXPIRE(unsigned char v1);
void L1TRC_Send_PHS_LOG_PRESCH_CMD_INDX(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_MEAS_CMD_TYPE(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_INTRA_CS_NUM(unsigned char v1);
void L1TRC_Send_PHS_LOG_INTER_CS_NUM(unsigned char v1);
void L1TRC_Send_PHS_LOG_FUNC_RTN(unsigned char v1);
void L1TRC_Send_PHS_LOG_SCHDL_EVT_INFO(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_UPDT_MIN_EVT_TIME(unsigned long v1, unsigned long v2);
void L1TRC_Send_PHS_LOG_NXT_GAP_TIME(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_PHS_LOG_NXT_STBY_GAP_TIME(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_PHS_LOG_EXE_EVT_REMAP(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_PHS_LOG_PARAM_3(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_PARAM_6(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_PHS_LOG_PHS_RNTI_VALUE(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_PHS_LOG_CH_RNTI_ACT(unsigned char v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_PHS_LOG_REDUCE_END_TIME(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_ENBL_RX_CTRL(unsigned long v1, unsigned long v2);
void L1TRC_Send_PHS_LOG_MEAS_TRIG(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_PHS_LOG_GAP_ACTV(unsigned char v1, unsigned long v2, unsigned long v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_PHS_LOG_HNDLR_ENTRY(unsigned char v1);
void L1TRC_Send_PHS_LOG_GET_NXT_TIME_DBG(unsigned short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_EXE_EVT_STUS_DBG(unsigned char v1, unsigned short v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_PHS_LOG_SCH_EVT_ACTIVE_DBG(unsigned char v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_RTB_CONFLICT(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_SCH_DROP_RATE(unsigned short v1);
void L1TRC_Send_PHS_LOG_INTRA_CONTI_INTER(void);
void L1TRC_Send_PHS_LOG_DRX_INACT(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_PHS_LOG_PAG_DUMP_INFO(unsigned char v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_PHS_LOG_UNSLP_CNT(unsigned long v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_PAG_DUMP_INFO2(unsigned short v1, unsigned char v2, unsigned short v3);

void Set_EL1_PHS_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1_PHS_1()	(EL1_PHS_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1_PHS_1_phs_func_trace()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_func_trace_1()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_func_trace_2()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_math_trace()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_2()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_var2_trace()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_var2_trace_l()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_var2_trace_2()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_var3_trace()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_var3_trace_l()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_var3_trace_2()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_l()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_2()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_msg_trace()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_msg_trace_l()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_error_trace()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_EL1_PHS_1_phs_debug_trace()	(ChkL1ModFltr_EL1_PHS_1()&&((EL1_PHS_1_Trace_Filter[3]&0x08)!=0))
#define ChkL1MsgFltr_PHS_LOG_FUNC_ENTRY()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace()
#define ChkL1MsgFltr_PHS_LOG_FUNC_ENTRY_ISR()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace()
#define ChkL1MsgFltr_PHS_LOG_FUNC_ENTRY_ISR_LOW()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace_2()
#define ChkL1MsgFltr_PHS_LOG_ABS_TIME_RPT()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace()
#define ChkL1MsgFltr_PHS_LOG_CLR_EXE_EVT()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace()
#define ChkL1MsgFltr_PHS_LOG_CLR_SCHDL_EVT()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace()
#define ChkL1MsgFltr_PHS_LOG_SRCH_EXE_EVT()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace_1()
#define ChkL1MsgFltr_PHS_LOG_SRCH_HP_EXE_EVT()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace_1()
#define ChkL1MsgFltr_PHS_LOG_SRCH_LP_EXE_EVT()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace_1()
#define ChkL1MsgFltr_PHS_LOG_MEAS_EXE_LEN()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace()
#define ChkL1MsgFltr_PHS_LOG_FIND_EXE_EVT()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace()
#define ChkL1MsgFltr_PHS_LOG_FIND_HP_EXE_EVT()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace()
#define ChkL1MsgFltr_PHS_LOG_FIND_LP_EXE_EVT()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace()
#define ChkL1MsgFltr_PHS_LOG_EXT_WIN_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace()
#define ChkL1MsgFltr_PHS_LOG_PHY_TRACK_CHK()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace()
#define ChkL1MsgFltr_PHS_LOG_PHY_TRACK_CHK_CALC()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace()
#define ChkL1MsgFltr_PHS_LOG_PHY_TRACK_CHK_DONE()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace()
#define ChkL1MsgFltr_PHS_LOG_EXT_LIFE_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace()
#define ChkL1MsgFltr_PHS_LOG_FLOW_TRACE()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_GET_NXT_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_HNDL_QUE_MCH_REQ()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_2()
#define ChkL1MsgFltr_PHS_LOG_HNDL_QUE_EVT_REQ()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_2()
#define ChkL1MsgFltr_PHS_LOG_QUE_MCH_REQ()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_2()
#define ChkL1MsgFltr_PHS_LOG_QUE_EVT_REQ()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_2()
#define ChkL1MsgFltr_PHS_LOG_QUE_EVT_REQ_FAIL()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_2()
#define ChkL1MsgFltr_PHS_LOG_TIME_SCHDL_ST()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_REQ_ACT()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_GAP_REQ_ACT()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_PHS_ABORT_ACT()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_DRV_CFN_RCV()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_MAC_DRX_CYC_CHK()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RNTI_EXE_EXPIRE()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RS_EXE_EXPIRE()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_CMD_ADD()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_EXE_EVT_TYPE()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RNTI_SET_EXIST()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RNTI_CTRL_ISR()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RS_CTRL_ISR()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_PHY_TRACK_CTRL_ISR()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_STRT_DRX_TRIG_TMR()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace_2()
#define ChkL1MsgFltr_PHS_LOG_SLEEP_PARAM()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SLEEP_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_REDUCE_SLEEP_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SCHDL_EVT_NUM()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_2()
#define ChkL1MsgFltr_PHS_LOG_COPY_SCHDL_EVT()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_2()
#define ChkL1MsgFltr_PHS_LOG_PARAM_ABS_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_PARAM_ABS_TIME1()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_PHS_RNTI_STUS()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_2()
#define ChkL1MsgFltr_PHS_LOG_UPDT_SRV_CID()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_UPDT_SRV_CID_ISR()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_CHNG_OLD_END_WIN()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_CHNG_NEW_STRT_WIN()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_EXE_CMD_END_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_FINAL_EXE_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_FINAL_EXE_TIME_1()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_RNTI_CTRL_EN_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_MAC_DRX_OP_GAP()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_RNTI_CTRL_REL_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_2()
#define ChkL1MsgFltr_PHS_LOG_PRESCH_CMD_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_PRESCH_CMD_DONE()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_LIFE_TIME_EXPIRE()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_2()
#define ChkL1MsgFltr_PHS_LOG_PRESCH_CMD_INDX()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_2()
#define ChkL1MsgFltr_PHS_LOG_MEAS_CMD_TYPE()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_INTRA_CS_NUM()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_INTER_CS_NUM()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_FUNC_RTN()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_SCHDL_EVT_INFO()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_UPDT_MIN_EVT_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_l()
#define ChkL1MsgFltr_PHS_LOG_NXT_GAP_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_NXT_STBY_GAP_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_EXE_EVT_REMAP()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace_2()
#define ChkL1MsgFltr_PHS_LOG_PARAM_3()	ChkL1ClsFltr_EL1_PHS_1_phs_var2_trace_2()
#define ChkL1MsgFltr_PHS_LOG_PARAM_6()	ChkL1ClsFltr_EL1_PHS_1_phs_var2_trace_2()
#define ChkL1MsgFltr_PHS_LOG_PHS_RNTI_VALUE()	ChkL1ClsFltr_EL1_PHS_1_phs_var3_trace()
#define ChkL1MsgFltr_PHS_LOG_CH_RNTI_ACT()	ChkL1ClsFltr_EL1_PHS_1_phs_var3_trace()
#define ChkL1MsgFltr_PHS_LOG_REDUCE_END_TIME()	ChkL1ClsFltr_EL1_PHS_1_phs_var3_trace_2()
#define ChkL1MsgFltr_PHS_LOG_ENBL_RX_CTRL()	ChkL1ClsFltr_EL1_PHS_1_phs_var3_trace_2()
#define ChkL1MsgFltr_PHS_LOG_MEAS_TRIG()	ChkL1ClsFltr_EL1_PHS_1_phs_var3_trace()
#define ChkL1MsgFltr_PHS_LOG_GAP_ACTV()	ChkL1ClsFltr_EL1_PHS_1_phs_var3_trace()
#define ChkL1MsgFltr_PHS_LOG_HNDLR_ENTRY()	ChkL1ClsFltr_EL1_PHS_1_phs_msg_trace()
#define ChkL1MsgFltr_PHS_LOG_GET_NXT_TIME_DBG()	ChkL1ClsFltr_EL1_PHS_1_phs_debug_trace()
#define ChkL1MsgFltr_PHS_LOG_EXE_EVT_STUS_DBG()	ChkL1ClsFltr_EL1_PHS_1_phs_debug_trace()
#define ChkL1MsgFltr_PHS_LOG_SCH_EVT_ACTIVE_DBG()	ChkL1ClsFltr_EL1_PHS_1_phs_debug_trace()
#define ChkL1MsgFltr_PHS_LOG_RTB_CONFLICT()	ChkL1ClsFltr_EL1_PHS_1_phs_func_trace()
#define ChkL1MsgFltr_PHS_LOG_SCH_DROP_RATE()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_INTRA_CONTI_INTER()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_DRX_INACT()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_PAG_DUMP_INFO()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_UNSLP_CNT()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_PAG_DUMP_INFO2()	ChkL1ClsFltr_EL1_PHS_1_phs_var_trace()


#endif
