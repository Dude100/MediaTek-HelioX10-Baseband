#ifndef L1TRC_UL1D_HSPA_PRI_DEF_H
#define L1TRC_UL1D_HSPA_PRI_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1D_TRC_STR_HS_DSCH_STATE(v1)  (unsigned char)(v1+0)
#define UL1D_TRC_STR_EDCH_STATE(v1)  (unsigned char)(v1+4)
#define UL1D_TRC_STR_TXCRP_HARQ_STA(v1)  (unsigned char)(v1+7)
#define UL1D_TRC_STR_CH2_TYPE(v1)  (unsigned char)(v1+12)
#define UL1D_TRC_STR_EDCH_RECONFIG(v1)  (unsigned char)(v1+14)
#define UL1D_TRC_STR_EDCH_TTI(v1)  (unsigned char)(v1+27)
#define UL1D_TRC_STR_EDCH_SF(v1)  (unsigned char)(v1+29)
#define UL1D_TRC_STR_CQI_DEBUG_INFO(v1)  (unsigned char)(v1+42)
#define UL1D_TRC_STR_HRFM_MPATH_INFO(v1)  (unsigned char)(v1+49)
#define UL1D_TRC_STR_PRE_START_TYPE(v1)  (unsigned char)(v1+52)
#define UL1D_TRC_STR_DSCHINT_STS(v1)  (unsigned char)(v1+55)
#define UL1D_TRC_HSDSCH_HARQ_DBG_STR(v1)  (unsigned char)(v1+60)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define UL1D_TRC_HS_SCCH_DBG() do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0033, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HS_SCCH_DBG()
#endif
#define UL1D_TRC_HS_SCCH_DBG_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0033, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HS_DSCH_STATE(v1, v2) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0133, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_HS_DSCH_STATE(v1, v2)
#endif
#define UL1D_TRC_HS_DSCH_STATE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0133, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HS_SCCH_RESULT(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0233, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9)), TRC_MERGE_4C((unsigned char)(v10), (unsigned char)(v11), (unsigned char)(v12), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HS_SCCH_RESULT(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define UL1D_TRC_HS_SCCH_RESULT_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0233, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9)), TRC_MERGE_4C((unsigned char)(v10), (unsigned char)(v11), (unsigned char)(v12), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HS_SCCH_INFO(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0333, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HS_SCCH_INFO(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_HS_SCCH_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0333, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HS_SCCH_INFO1(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0433, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_HS_SCCH_INFO1(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_HS_SCCH_INFO1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0433, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HS_SCCH_LESS_INFO(v1, v2, v3) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0533, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HS_SCCH_LESS_INFO(v1, v2, v3)
#endif
#define UL1D_TRC_HS_SCCH_LESS_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0533, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HS_SCCH_P1_MAX_CORR(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0633, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HS_SCCH_P1_MAX_CORR(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HS_SCCH_P1_MAX_CORR_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0633, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HS_SCCH_P1_SYM_ACC(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0733, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HS_SCCH_P1_SYM_ACC(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HS_SCCH_P1_SYM_ACC_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0733, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HS_DSCH_RESULT(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0833, (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HS_DSCH_RESULT(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_HS_DSCH_RESULT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0833, (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HS_DSCH_LMBT_RESULT(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0933, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HS_DSCH_LMBT_RESULT(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HS_DSCH_LMBT_RESULT_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0933, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HS_DSCH_INT(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HS_DSCH_INT(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HS_DSCH_INT_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0A33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HS_DSCH_INT_DBG(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HS_DSCH_INT_DBG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_HS_DSCH_INT_DBG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HS_DSCH_SLT_LISR_DBG(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HS_DSCH_SLT_LISR_DBG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_HS_DSCH_SLT_LISR_DBG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HS_DSCH_SLT_LISR_DBG1(v1) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D33, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HS_DSCH_SLT_LISR_DBG1(v1)
#endif
#define UL1D_TRC_HS_DSCH_SLT_LISR_DBG1_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D33, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HS_DSCH_SLT_LISR(v1, v2, v3) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HS_DSCH_SLT_LISR(v1, v2, v3)
#endif
#define UL1D_TRC_HS_DSCH_SLT_LISR_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HS_DSCH_DBG(v1, v2) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F33, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_HS_DSCH_DBG(v1, v2)
#endif
#define UL1D_TRC_HS_DSCH_DBG_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F33, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HS_DSCH_DBG1(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x1033, (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_HS_DSCH_DBG1(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_HS_DSCH_DBG1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x1033, (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HS_DSCH_CH_STATUS(v1, v2) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1133, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HS_DSCH_CH_STATUS(v1, v2)
#endif
#define UL1D_TRC_HS_DSCH_CH_STATUS_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1133, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HSDSCH_HARQ_OFF_DBG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1233, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_HSDSCH_HARQ_OFF_DBG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HSDSCH_HARQ_OFF_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1233, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HSCQI_CTRL(v1, v2) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1333, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_HSCQI_CTRL(v1, v2)
#endif
#define UL1D_TRC_HSCQI_CTRL_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1333, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HSRP_DBG(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1433, (short)(v5)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_HSRP_DBG(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_HSRP_DBG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1433, (short)(v5)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HSCQI_DBG1(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1533, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_HSCQI_DBG1(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HSCQI_DBG1_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1533, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HSCQI_DBG2(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1633, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_HSCQI_DBG2(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HSCQI_DBG2_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1633, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HS_TXCRP_STSP(v1, v2, v3) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1733, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HS_TXCRP_STSP(v1, v2, v3)
#endif
#define UL1D_TRC_HS_TXCRP_STSP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1733, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HS_TXCRP_HARQ_CONFIG(v1, v2, v3) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1833, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_HS_TXCRP_HARQ_CONFIG(v1, v2, v3)
#endif
#define UL1D_TRC_HS_TXCRP_HARQ_CONFIG_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1833, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HS_TXCRP_CQI_CONFIG(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1933, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_HS_TXCRP_CQI_CONFIG(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_HS_TXCRP_CQI_CONFIG_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1933, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HS_TXCRP_IN_LOG(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1A33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HS_TXCRP_IN_LOG(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_HS_TXCRP_IN_LOG_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1A33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HS_TXCRP_OUT_LOG(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B33, (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define UL1D_TRC_HS_TXCRP_OUT_LOG(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_HS_TXCRP_OUT_LOG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B33, (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HS_DPCCH_FB_SYMBOL_IN_SLOT(v1) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C33, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_HS_DPCCH_FB_SYMBOL_IN_SLOT(v1)
#endif
#define UL1D_TRC_HS_DPCCH_FB_SYMBOL_IN_SLOT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C33, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HS_DSCH_HANDLE_SETUP(v1, v2) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D33, (unsigned short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HS_DSCH_HANDLE_SETUP(v1, v2)
#endif
#define UL1D_TRC_HS_DSCH_HANDLE_SETUP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D33, (unsigned short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HSCE_CH1_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1E33, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((unsigned short)(v7), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_CH1_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_HSCE_CH1_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1E33, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((unsigned short)(v7), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HSCE_EQ_INFO(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_EQ_INFO(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_HSCE_EQ_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_EQ_RESET(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2033, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_EQ_RESET(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define UL1D_TRC_HSCE_EQ_RESET_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2033, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HSCE_CHx_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2133, (short)(v3)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_CHx_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_HSCE_CHx_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2133, (short)(v3)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HSCE_FFT_INFO(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2233, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_FFT_INFO(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_HSCE_FFT_INFO_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2233, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_IOEST_WC_SET(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2333, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_IOEST_WC_SET(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_HSCE_IOEST_WC_SET_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2333, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HSCE_UPDATE_CELLS(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x2433, (unsigned short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_UPDATE_CELLS(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define UL1D_TRC_HSCE_UPDATE_CELLS_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_6_DATA(TRC_MERGE_2S(0x2433, (unsigned short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SRV_OTR_INFO(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2533, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v4)), TRC_MERGE_2S((short)(v5), (unsigned short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v3), (unsigned char)(v8)));\
	} while(0)
#else
	#define UL1D_TRC_SRV_OTR_INFO(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_SRV_OTR_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2533, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v4)), TRC_MERGE_2S((short)(v5), (unsigned short)(v6)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v3), (unsigned char)(v8)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSCE_DBG_PWR(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2633, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD), (long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_HSCE_DBG_PWR(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_HSCE_DBG_PWR_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2633, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD), (long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_OCIC_DBG(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2733, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v8), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_OCIC_DBG(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_OCIC_DBG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2733, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v8), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HRFM_REF_PAC_ADDR(v1, v2, v3) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2833, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HRFM_REF_PAC_ADDR(v1, v2, v3)
#endif
#define UL1D_TRC_HRFM_REF_PAC_ADDR_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2833, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HRFM_MPATH_LIST(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2933, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_HRFM_MPATH_LIST(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_HRFM_MPATH_LIST_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2933, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HRFM_SHADOW_RELEASE(v1, v2, v3) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HRFM_SHADOW_RELEASE(v1, v2, v3)
#endif
#define UL1D_TRC_HRFM_SHADOW_RELEASE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HRFM_VALID_FNG_LIST(v1, v2, v3) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B33, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HRFM_VALID_FNG_LIST(v1, v2, v3)
#endif
#define UL1D_TRC_HRFM_VALID_FNG_LIST_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B33, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HRFM_SHORT_DETECT(v1, v2) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2C33, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_HRFM_SHORT_DETECT(v1, v2)
#endif
#define UL1D_TRC_HRFM_SHORT_DETECT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2C33, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HRFM_PROP_WINDOW(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2D33, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (unsigned char)(v7), (unsigned char)(v8)));\
	} while(0)
#else
	#define UL1D_TRC_HRFM_PROP_WINDOW(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_HRFM_PROP_WINDOW_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2D33, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), (unsigned char)(v7), (unsigned char)(v8)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HRFM_CENTER_INIT(v1, v2) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E33, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HRFM_CENTER_INIT(v1, v2)
#endif
#define UL1D_TRC_HRFM_CENTER_INIT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E33, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HRFM_ACCUMULATE(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_2S(0x2F33, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_4C((unsigned char)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (long)(v4), (unsigned long)(v5), (long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define UL1D_TRC_HRFM_ACCUMULATE(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define UL1D_TRC_HRFM_ACCUMULATE_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_10_DATA(TRC_MERGE_2S(0x2F33, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_4C((unsigned char)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (long)(v4), (unsigned long)(v5), (long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HRFM_SWAP_WINDOW() do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3033, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HRFM_SWAP_WINDOW()
#endif
#define UL1D_TRC_HRFM_SWAP_WINDOW_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3033, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HRFM_MINOR_WIN(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3133, (short)(v2)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HRFM_MINOR_WIN(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_HRFM_MINOR_WIN_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3133, (short)(v2)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HRFM_OTR_INFO(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3233, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v2), (unsigned char)(v6)));\
	} while(0)
#else
	#define UL1D_TRC_HRFM_OTR_INFO(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_HRFM_OTR_INFO_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3233, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v2), (unsigned char)(v6)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_CQI_DBG1(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x3333, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v13)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v14), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v10), (long)(v11), (long)(v12));\
	} while(0)
#else
	#define UL1D_TRC_CQI_DBG1(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14)
#endif
#define UL1D_TRC_CQI_DBG1_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14) TRC_SEND_9_DATA(TRC_MERGE_2S(0x3333, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v13)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v14), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v10), (long)(v11), (long)(v12))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_CQI_INPUT(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3433, (unsigned short)(v3)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), (char)(v7)), TRC_MERGE_4C((unsigned char)(v9), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CQI_INPUT(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_CQI_INPUT_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3433, (unsigned short)(v3)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), (char)(v7)), TRC_MERGE_4C((unsigned char)(v9), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CQI_ADJUST(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3533, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CQI_ADJUST(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_CQI_ADJUST_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3533, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CQI_TX_SIR(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3633, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CQI_TX_SIR(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_CQI_TX_SIR_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3633, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), (unsigned char)(v9), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CQI_DELTA_SIR_CQI(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_31_DATA(TRC_MERGE_1S2C(0x3733, (unsigned char)(v31), TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17), (long)(v18), (long)(v19), (long)(v20), (long)(v21), (long)(v22), (long)(v23), (long)(v24), (long)(v25), (long)(v26), (long)(v27), (long)(v28), (long)(v29), (long)(v30));\
	} while(0)
#else
	#define UL1D_TRC_CQI_DELTA_SIR_CQI(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31)
#endif
#define UL1D_TRC_CQI_DELTA_SIR_CQI_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31) TRC_SEND_31_DATA(TRC_MERGE_1S2C(0x3733, (unsigned char)(v31), TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17), (long)(v18), (long)(v19), (long)(v20), (long)(v21), (long)(v22), (long)(v23), (long)(v24), (long)(v25), (long)(v26), (long)(v27), (long)(v28), (long)(v29), (long)(v30))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CQI_DEBUG_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_2S(0x3833, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_2S((short)(v17), (short)(v18)), TRC_MERGE_2S((short)(v19), (short)(v20)), TRC_MERGE_2S((short)(v21), (short)(v22)), TRC_MERGE_2S((short)(v23), (short)(v24)), TRC_MERGE_2S((short)(v25), (short)(v26)), TRC_MERGE_2S((short)(v27), (short)(v28)), TRC_MERGE_2S((short)(v29), (short)(v30)), TRC_MERGE_1S2C((short)(v31), (unsigned char)(v1), (unsigned char)(v32)));\
	} while(0)
#else
	#define UL1D_TRC_CQI_DEBUG_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32)
#endif
#define UL1D_TRC_CQI_DEBUG_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32) TRC_SEND_16_DATA(TRC_MERGE_2S(0x3833, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_2S((short)(v17), (short)(v18)), TRC_MERGE_2S((short)(v19), (short)(v20)), TRC_MERGE_2S((short)(v21), (short)(v22)), TRC_MERGE_2S((short)(v23), (short)(v24)), TRC_MERGE_2S((short)(v25), (short)(v26)), TRC_MERGE_2S((short)(v27), (short)(v28)), TRC_MERGE_2S((short)(v29), (short)(v30)), TRC_MERGE_1S2C((short)(v31), (unsigned char)(v1), (unsigned char)(v32)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CQI_DEBUG_INFO_32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_31_DATA(TRC_MERGE_1S2C(0x3933, (unsigned char)(v1), (unsigned char)(v32)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17), (long)(v18), (long)(v19), (long)(v20), (long)(v21), (long)(v22), (long)(v23), (long)(v24), (long)(v25), (long)(v26), (long)(v27), (long)(v28), (long)(v29), (long)(v30), (long)(v31));\
	} while(0)
#else
	#define UL1D_TRC_CQI_DEBUG_INFO_32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32)
#endif
#define UL1D_TRC_CQI_DEBUG_INFO_32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32) TRC_SEND_31_DATA(TRC_MERGE_1S2C(0x3933, (unsigned char)(v1), (unsigned char)(v32)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17), (long)(v18), (long)(v19), (long)(v20), (long)(v21), (long)(v22), (long)(v23), (long)(v24), (long)(v25), (long)(v26), (long)(v27), (long)(v28), (long)(v29), (long)(v30), (long)(v31))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CQI_XLAYER_ALGO_RLC_INFO(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3A33, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CQI_XLAYER_ALGO_RLC_INFO(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_CQI_XLAYER_ALGO_RLC_INFO_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3A33, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CQI_XLAYER_TXMAPPING_SEL(v1) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3B33, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CQI_XLAYER_TXMAPPING_SEL(v1)
#endif
#define UL1D_TRC_CQI_XLAYER_TXMAPPING_SEL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3B33, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CQI_XLAYER_SWITCH_CTRL(v1, v2, v3) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3C33, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CQI_XLAYER_SWITCH_CTRL(v1, v2, v3)
#endif
#define UL1D_TRC_CQI_XLAYER_SWITCH_CTRL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3C33, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CQI_PULL_IN(v1, v2, v3) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3D33, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CQI_PULL_IN(v1, v2, v3)
#endif
#define UL1D_TRC_CQI_PULL_IN_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3D33, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_CQI_BIAS_MODE(v1) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3E33, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_CQI_BIAS_MODE(v1)
#endif
#define UL1D_TRC_CQI_BIAS_MODE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3E33, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_CQI_SIR_NW(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3F33, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v6), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CQI_SIR_NW(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_CQI_SIR_NW_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3F33, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v6), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSRP_DBG_LOG(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x4033, (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v7)), TRC_MERGE_4C((unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSRP_DBG_LOG(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_HSRP_DBG_LOG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x4033, (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v7)), TRC_MERGE_4C((unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSRP_FCC_DBG_LOG(v1) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4133, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSRP_FCC_DBG_LOG(v1)
#endif
#define UL1D_TRC_HSRP_FCC_DBG_LOG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4133, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HSRP_DSCH_SIR_LOG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4233, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HSRP_DSCH_SIR_LOG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HSRP_DSCH_SIR_LOG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4233, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HRXBRP_DBG0(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4333, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HRXBRP_DBG0(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_HRXBRP_DBG0_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4333, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HRXBRP_DBG1(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4433, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HRXBRP_DBG1(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_HRXBRP_DBG1_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4433, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HRXBRP_DBG2(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4533, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HRXBRP_DBG2(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_HRXBRP_DBG2_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4533, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HRXBRP_DBG3(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4633, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HRXBRP_DBG3(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HRXBRP_DBG3_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4633, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HRXBRP_DBG4(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4733, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HRXBRP_DBG4(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_HRXBRP_DBG4_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4733, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HRXBRP_S_VALUE(v1, v2, v3) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4833, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_HRXBRP_S_VALUE(v1, v2, v3)
#endif
#define UL1D_TRC_HRXBRP_S_VALUE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4833, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EDCH_STATE(v1, v2) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4933, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_STATE(v1, v2)
#endif
#define UL1D_TRC_EDCH_STATE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4933, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_EDCH_INFO_IND(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_INFO_IND(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_EDCH_INFO_IND_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EDCH_DATA_IND(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4B33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_DATA_IND(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_EDCH_DATA_IND_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4B33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EDCH_MAC_EVENT(v1) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4C33, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_MAC_EVENT(v1)
#endif
#define UL1D_TRC_EDCH_MAC_EVENT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4C33, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EDCH_RECONFIG(v1, v2) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4D33, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_RECONFIG(v1, v2)
#endif
#define UL1D_TRC_EDCH_RECONFIG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4D33, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EDCH_EDPDCH_CONFIG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4E33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_EDPDCH_CONFIG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_EDCH_EDPDCH_CONFIG_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4E33, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EDCH_HI_CONFIG(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4F33, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_HI_CONFIG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_EDCH_HI_CONFIG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4F33, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EDCH_RG_CONFIG(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5033, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_RG_CONFIG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_EDCH_RG_CONFIG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5033, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_EDCH_STS_INFO1(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5133, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_STS_INFO1(v1, v2, v3, v4)
#endif
#define UL1D_TRC_EDCH_STS_INFO1_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5133, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_EDCH_STS_INFO2(v1, v2, v3) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5233, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_STS_INFO2(v1, v2, v3)
#endif
#define UL1D_TRC_EDCH_STS_INFO2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5233, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EDCH_STS_INFO3(v1, v2, v3) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5333, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_STS_INFO3(v1, v2, v3)
#endif
#define UL1D_TRC_EDCH_STS_INFO3_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5333, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ETXCRP_GET_BUFFER(v1) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5433, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ETXCRP_GET_BUFFER(v1)
#endif
#define UL1D_TRC_ETXCRP_GET_BUFFER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5433, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ETXCRP_FREE_BUFFER(v1) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5533, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ETXCRP_FREE_BUFFER(v1)
#endif
#define UL1D_TRC_ETXCRP_FREE_BUFFER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5533, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EDCH_L2_TICK4_FAIL() do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5633, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_L2_TICK4_FAIL()
#endif
#define UL1D_TRC_EDCH_L2_TICK4_FAIL_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5633, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DBG_ETX_CR(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5733, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_DBG_ETX_CR(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_DBG_ETX_CR_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x5733, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_EDCH_GRANT_BITS_INFO(v1, v2, v3) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x5833, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_GRANT_BITS_INFO(v1, v2, v3)
#endif
#define UL1D_TRC_EDCH_GRANT_BITS_INFO_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x5833, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_EDCH_RG_THRESHOLD_INFO(v1) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5933, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_EDCH_RG_THRESHOLD_INFO(v1)
#endif
#define UL1D_TRC_EDCH_RG_THRESHOLD_INFO_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5933, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_PRE_START_INFO(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5A33, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PRE_START_INFO(v1, v2, v3, v4)
#endif
#define UL1D_TRC_PRE_START_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5A33, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RF_RX_CAL_SETTING(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5B33, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RF_RX_CAL_SETTING(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RF_RX_CAL_SETTING_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5B33, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RF_TX_CAL_SETTING(v1, v2) do {\
		if(UL1D_HSPA_PRI_Trace_Filter[0]==1 && (UL1D_HSPA_PRI_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5C33, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RF_TX_CAL_SETTING(v1, v2)
#endif
#define UL1D_TRC_RF_TX_CAL_SETTING_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5C33, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1D_HSPA_PRI_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1D_TRC_HS_SCCH_DBG(void);
void L1TRC_Send_UL1D_TRC_HS_DSCH_STATE(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_HS_SCCH_RESULT(unsigned short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10, unsigned char v11, unsigned char v12);
void L1TRC_Send_UL1D_TRC_HS_SCCH_INFO(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_HS_SCCH_INFO1(unsigned short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_HS_SCCH_LESS_INFO(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_HS_SCCH_P1_MAX_CORR(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_HS_SCCH_P1_SYM_ACC(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_HS_DSCH_RESULT(unsigned char v1, unsigned char v2, unsigned char v3, short v4, short v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_HS_DSCH_LMBT_RESULT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_HS_DSCH_INT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_HS_DSCH_INT_DBG(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_HS_DSCH_SLT_LISR_DBG(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_HS_DSCH_SLT_LISR_DBG1(unsigned char v1);
void L1TRC_Send_UL1D_TRC_HS_DSCH_SLT_LISR(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_HS_DSCH_DBG(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_HS_DSCH_DBG1(unsigned char v1, unsigned long v2, unsigned long v3, short v4, short v5, unsigned long v6);
void L1TRC_Send_UL1D_TRC_HS_DSCH_CH_STATUS(short v1, short v2);
void L1TRC_Send_UL1D_TRC_HSDSCH_HARQ_OFF_DBG(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_HSCQI_CTRL(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_HSRP_DBG(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, short v5, unsigned long v6);
void L1TRC_Send_UL1D_TRC_HSCQI_DBG1(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_HSCQI_DBG2(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_HS_TXCRP_STSP(unsigned short v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_HS_TXCRP_HARQ_CONFIG(unsigned short v1, unsigned long v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_HS_TXCRP_CQI_CONFIG(unsigned short v1, unsigned long v2, unsigned long v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_UL1D_TRC_HS_TXCRP_IN_LOG(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_UL1D_TRC_HS_TXCRP_OUT_LOG(unsigned char v1, char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, short v7, short v8);
void L1TRC_Send_UL1D_TRC_HS_DPCCH_FB_SYMBOL_IN_SLOT(short v1);
void L1TRC_Send_UL1D_TRC_HS_DSCH_HANDLE_SETUP(unsigned short v1, char v2);
void L1TRC_Send_UL1D_TRC_HSCE_CH1_INFO(unsigned short v1, short v2, short v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned short v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_UL1D_TRC_HSCE_EQ_INFO(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_HSCE_EQ_RESET(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10, unsigned char v11, unsigned char v12);
void L1TRC_Send_UL1D_TRC_HSCE_CHx_INFO(unsigned char v1, unsigned char v2, short v3, unsigned char v4, unsigned short v5, unsigned char v6, unsigned short v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_UL1D_TRC_HSCE_FFT_INFO(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_HSCE_IOEST_WC_SET(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_HSCE_UPDATE_CELLS(unsigned char v1, unsigned short v2, short v3, short v4, unsigned short v5, short v6, short v7, unsigned short v8, short v9, short v10);
void L1TRC_Send_UL1D_TRC_SRV_OTR_INFO(unsigned short v1, short v2, unsigned char v3, unsigned short v4, short v5, unsigned short v6, short v7, unsigned char v8);
void L1TRC_Send_UL1D_TRC_HSCE_DBG_PWR(unsigned char v1, unsigned short v2, unsigned char v3, unsigned short v4, unsigned char v5, long v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_UL1D_TRC_OCIC_DBG(unsigned char v1, short v2, unsigned char v3, short v4, short v5, short v6, short v7, unsigned char v8);
void L1TRC_Send_UL1D_TRC_HRFM_REF_PAC_ADDR(unsigned char v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_HRFM_MPATH_LIST(unsigned char v1, char v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1D_TRC_HRFM_SHADOW_RELEASE(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_HRFM_VALID_FNG_LIST(unsigned char v1, short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_HRFM_SHORT_DETECT(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_HRFM_PROP_WINDOW(short v1, unsigned short v2, short v3, unsigned short v4, short v5, unsigned short v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_UL1D_TRC_HRFM_CENTER_INIT(unsigned char v1, short v2);
void L1TRC_Send_UL1D_TRC_HRFM_ACCUMULATE(long v1, unsigned long v2, unsigned short v3, long v4, unsigned long v5, unsigned short v6, long v7, unsigned long v8, unsigned short v9, short v10, short v11, unsigned char v12);
void L1TRC_Send_UL1D_TRC_HRFM_SWAP_WINDOW(void);
void L1TRC_Send_UL1D_TRC_HRFM_MINOR_WIN(unsigned char v1, short v2, unsigned char v3, unsigned char v4, short v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_HRFM_OTR_INFO(unsigned short v1, unsigned char v2, unsigned short v3, short v4, unsigned short v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_CQI_DBG1(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, long v10, long v11, long v12, short v13, unsigned char v14);
void L1TRC_Send_UL1D_TRC_CQI_INPUT(unsigned char v1, unsigned char v2, unsigned short v3, unsigned char v4, unsigned char v5, unsigned char v6, char v7, short v8, unsigned char v9);
void L1TRC_Send_UL1D_TRC_CQI_ADJUST(unsigned char v1, unsigned char v2, short v3, short v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_CQI_TX_SIR(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, unsigned char v9);
void L1TRC_Send_UL1D_TRC_CQI_DELTA_SIR_CQI(long v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9, long v10, long v11, long v12, long v13, long v14, long v15, long v16, long v17, long v18, long v19, long v20, long v21, long v22, long v23, long v24, long v25, long v26, long v27, long v28, long v29, long v30, unsigned char v31);
void L1TRC_Send_UL1D_TRC_CQI_DEBUG_INFO(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17, short v18, short v19, short v20, short v21, short v22, short v23, short v24, short v25, short v26, short v27, short v28, short v29, short v30, short v31, unsigned char v32);
void L1TRC_Send_UL1D_TRC_CQI_DEBUG_INFO_32(unsigned char v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9, long v10, long v11, long v12, long v13, long v14, long v15, long v16, long v17, long v18, long v19, long v20, long v21, long v22, long v23, long v24, long v25, long v26, long v27, long v28, long v29, long v30, long v31, unsigned char v32);
void L1TRC_Send_UL1D_TRC_CQI_XLAYER_ALGO_RLC_INFO(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_CQI_XLAYER_TXMAPPING_SEL(unsigned char v1);
void L1TRC_Send_UL1D_TRC_CQI_XLAYER_SWITCH_CTRL(unsigned short v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_CQI_PULL_IN(unsigned char v1, short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_CQI_BIAS_MODE(short v1);
void L1TRC_Send_UL1D_TRC_CQI_SIR_NW(unsigned char v1, unsigned char v2, short v3, short v4, short v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_HSRP_DBG_LOG(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_UL1D_TRC_HSRP_FCC_DBG_LOG(unsigned char v1);
void L1TRC_Send_UL1D_TRC_HSRP_DSCH_SIR_LOG(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_HRXBRP_DBG0(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_UL1D_TRC_HRXBRP_DBG1(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_UL1D_TRC_HRXBRP_DBG2(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_UL1D_TRC_HRXBRP_DBG3(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_HRXBRP_DBG4(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_UL1D_TRC_HRXBRP_S_VALUE(unsigned char v1, unsigned char v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_EDCH_STATE(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_EDCH_INFO_IND(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_EDCH_DATA_IND(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_UL1D_TRC_EDCH_MAC_EVENT(unsigned short v1);
void L1TRC_Send_UL1D_TRC_EDCH_RECONFIG(unsigned char v1, short v2);
void L1TRC_Send_UL1D_TRC_EDCH_EDPDCH_CONFIG(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_EDCH_HI_CONFIG(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_EDCH_RG_CONFIG(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_EDCH_STS_INFO1(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_EDCH_STS_INFO2(unsigned char v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_EDCH_STS_INFO3(unsigned char v1, unsigned char v2, char v3);
void L1TRC_Send_UL1D_TRC_ETXCRP_GET_BUFFER(unsigned char v1);
void L1TRC_Send_UL1D_TRC_ETXCRP_FREE_BUFFER(unsigned char v1);
void L1TRC_Send_UL1D_TRC_EDCH_L2_TICK4_FAIL(void);
void L1TRC_Send_UL1D_TRC_DBG_ETX_CR(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_UL1D_TRC_EDCH_GRANT_BITS_INFO(long v1, long v2, long v3);
void L1TRC_Send_UL1D_TRC_EDCH_RG_THRESHOLD_INFO(short v1);
void L1TRC_Send_UL1D_TRC_PRE_START_INFO(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_RF_RX_CAL_SETTING(short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_RF_TX_CAL_SETTING(short v1, unsigned short v2);

void Set_UL1D_HSPA_PRI_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1D_HSPA_PRI()	(UL1D_HSPA_PRI_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_L()	(ChkL1ModFltr_UL1D_HSPA_PRI()&&((UL1D_HSPA_PRI_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_M()	(ChkL1ModFltr_UL1D_HSPA_PRI()&&((UL1D_HSPA_PRI_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()	(ChkL1ModFltr_UL1D_HSPA_PRI()&&((UL1D_HSPA_PRI_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_PRI_HRFM_L()	(ChkL1ModFltr_UL1D_HSPA_PRI()&&((UL1D_HSPA_PRI_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_PRI_HRFM_M()	(ChkL1ModFltr_UL1D_HSPA_PRI()&&((UL1D_HSPA_PRI_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_PRI_HSCE_L()	(ChkL1ModFltr_UL1D_HSPA_PRI()&&((UL1D_HSPA_PRI_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_PRI_HSCE_M()	(ChkL1ModFltr_UL1D_HSPA_PRI()&&((UL1D_HSPA_PRI_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_PRI_HSCE_H()	(ChkL1ModFltr_UL1D_HSPA_PRI()&&((UL1D_HSPA_PRI_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_PRI_CQI_M()	(ChkL1ModFltr_UL1D_HSPA_PRI()&&((UL1D_HSPA_PRI_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_PRI_CQI_L()	(ChkL1ModFltr_UL1D_HSPA_PRI()&&((UL1D_HSPA_PRI_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_PRI_HSRP_M()	(ChkL1ModFltr_UL1D_HSPA_PRI()&&((UL1D_HSPA_PRI_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_PRI_HRXBRP_L()	(ChkL1ModFltr_UL1D_HSPA_PRI()&&((UL1D_HSPA_PRI_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_H()	(ChkL1ModFltr_UL1D_HSPA_PRI()&&((UL1D_HSPA_PRI_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_M()	(ChkL1ModFltr_UL1D_HSPA_PRI()&&((UL1D_HSPA_PRI_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_L()	(ChkL1ModFltr_UL1D_HSPA_PRI()&&((UL1D_HSPA_PRI_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_PRI_PRESTR_H()	(ChkL1ModFltr_UL1D_HSPA_PRI()&&((UL1D_HSPA_PRI_Trace_Filter[2]&0x80)!=0))
#define ChkL1MsgFltr_UL1D_TRC_HS_SCCH_DBG()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HS_DSCH_STATE()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HS_SCCH_RESULT()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HS_SCCH_INFO()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HS_SCCH_INFO1()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HS_SCCH_LESS_INFO()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HS_SCCH_P1_MAX_CORR()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_L()
#define ChkL1MsgFltr_UL1D_TRC_HS_SCCH_P1_SYM_ACC()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_L()
#define ChkL1MsgFltr_UL1D_TRC_HS_DSCH_RESULT()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HS_DSCH_LMBT_RESULT()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HS_DSCH_INT()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HS_DSCH_INT_DBG()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HS_DSCH_SLT_LISR_DBG()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HS_DSCH_SLT_LISR_DBG1()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HS_DSCH_SLT_LISR()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HS_DSCH_DBG()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HS_DSCH_DBG1()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HS_DSCH_CH_STATUS()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HSDSCH_HARQ_OFF_DBG()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HSCQI_CTRL()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HSRP_DBG()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HSCQI_DBG1()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HSCQI_DBG2()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HS_TXCRP_STSP()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_M()
#define ChkL1MsgFltr_UL1D_TRC_HS_TXCRP_HARQ_CONFIG()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_M()
#define ChkL1MsgFltr_UL1D_TRC_HS_TXCRP_CQI_CONFIG()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_M()
#define ChkL1MsgFltr_UL1D_TRC_HS_TXCRP_IN_LOG()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_M()
#define ChkL1MsgFltr_UL1D_TRC_HS_TXCRP_OUT_LOG()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HS_DPCCH_FB_SYMBOL_IN_SLOT()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_H()
#define ChkL1MsgFltr_UL1D_TRC_HS_DSCH_HANDLE_SETUP()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSSM_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_CH1_INFO()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSCE_H()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_EQ_INFO()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSCE_H()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_EQ_RESET()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_CHx_INFO()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSCE_H()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_FFT_INFO()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSCE_L()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_IOEST_WC_SET()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_UPDATE_CELLS()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSCE_L()
#define ChkL1MsgFltr_UL1D_TRC_SRV_OTR_INFO()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSCE_H()
#define ChkL1MsgFltr_UL1D_TRC_HSCE_DBG_PWR()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_OCIC_DBG()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSCE_M()
#define ChkL1MsgFltr_UL1D_TRC_HRFM_REF_PAC_ADDR()	ChkL1ClsFltr_UL1D_HSPA_PRI_HRFM_M()
#define ChkL1MsgFltr_UL1D_TRC_HRFM_MPATH_LIST()	ChkL1ClsFltr_UL1D_HSPA_PRI_HRFM_M()
#define ChkL1MsgFltr_UL1D_TRC_HRFM_SHADOW_RELEASE()	ChkL1ClsFltr_UL1D_HSPA_PRI_HRFM_M()
#define ChkL1MsgFltr_UL1D_TRC_HRFM_VALID_FNG_LIST()	ChkL1ClsFltr_UL1D_HSPA_PRI_HRFM_L()
#define ChkL1MsgFltr_UL1D_TRC_HRFM_SHORT_DETECT()	ChkL1ClsFltr_UL1D_HSPA_PRI_HRFM_L()
#define ChkL1MsgFltr_UL1D_TRC_HRFM_PROP_WINDOW()	ChkL1ClsFltr_UL1D_HSPA_PRI_HRFM_M()
#define ChkL1MsgFltr_UL1D_TRC_HRFM_CENTER_INIT()	ChkL1ClsFltr_UL1D_HSPA_PRI_HRFM_L()
#define ChkL1MsgFltr_UL1D_TRC_HRFM_ACCUMULATE()	ChkL1ClsFltr_UL1D_HSPA_PRI_HRFM_L()
#define ChkL1MsgFltr_UL1D_TRC_HRFM_SWAP_WINDOW()	ChkL1ClsFltr_UL1D_HSPA_PRI_HRFM_L()
#define ChkL1MsgFltr_UL1D_TRC_HRFM_MINOR_WIN()	ChkL1ClsFltr_UL1D_HSPA_PRI_HRFM_L()
#define ChkL1MsgFltr_UL1D_TRC_HRFM_OTR_INFO()	ChkL1ClsFltr_UL1D_HSPA_PRI_HRFM_M()
#define ChkL1MsgFltr_UL1D_TRC_CQI_DBG1()	ChkL1ClsFltr_UL1D_HSPA_PRI_CQI_L()
#define ChkL1MsgFltr_UL1D_TRC_CQI_INPUT()	ChkL1ClsFltr_UL1D_HSPA_PRI_CQI_L()
#define ChkL1MsgFltr_UL1D_TRC_CQI_ADJUST()	ChkL1ClsFltr_UL1D_HSPA_PRI_CQI_M()
#define ChkL1MsgFltr_UL1D_TRC_CQI_TX_SIR()	ChkL1ClsFltr_UL1D_HSPA_PRI_CQI_M()
#define ChkL1MsgFltr_UL1D_TRC_CQI_DELTA_SIR_CQI()	ChkL1ClsFltr_UL1D_HSPA_PRI_CQI_M()
#define ChkL1MsgFltr_UL1D_TRC_CQI_DEBUG_INFO()	ChkL1ClsFltr_UL1D_HSPA_PRI_CQI_M()
#define ChkL1MsgFltr_UL1D_TRC_CQI_DEBUG_INFO_32()	ChkL1ClsFltr_UL1D_HSPA_PRI_CQI_M()
#define ChkL1MsgFltr_UL1D_TRC_CQI_XLAYER_ALGO_RLC_INFO()	ChkL1ClsFltr_UL1D_HSPA_PRI_CQI_M()
#define ChkL1MsgFltr_UL1D_TRC_CQI_XLAYER_TXMAPPING_SEL()	ChkL1ClsFltr_UL1D_HSPA_PRI_CQI_M()
#define ChkL1MsgFltr_UL1D_TRC_CQI_XLAYER_SWITCH_CTRL()	ChkL1ClsFltr_UL1D_HSPA_PRI_CQI_M()
#define ChkL1MsgFltr_UL1D_TRC_CQI_PULL_IN()	ChkL1ClsFltr_UL1D_HSPA_PRI_CQI_M()
#define ChkL1MsgFltr_UL1D_TRC_CQI_BIAS_MODE()	ChkL1ClsFltr_UL1D_HSPA_PRI_CQI_L()
#define ChkL1MsgFltr_UL1D_TRC_CQI_SIR_NW()	ChkL1ClsFltr_UL1D_HSPA_PRI_CQI_L()
#define ChkL1MsgFltr_UL1D_TRC_HSRP_DBG_LOG()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSRP_M()
#define ChkL1MsgFltr_UL1D_TRC_HSRP_FCC_DBG_LOG()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSRP_M()
#define ChkL1MsgFltr_UL1D_TRC_HSRP_DSCH_SIR_LOG()	ChkL1ClsFltr_UL1D_HSPA_PRI_HSRP_M()
#define ChkL1MsgFltr_UL1D_TRC_HRXBRP_DBG0()	ChkL1ClsFltr_UL1D_HSPA_PRI_HRXBRP_L()
#define ChkL1MsgFltr_UL1D_TRC_HRXBRP_DBG1()	ChkL1ClsFltr_UL1D_HSPA_PRI_HRXBRP_L()
#define ChkL1MsgFltr_UL1D_TRC_HRXBRP_DBG2()	ChkL1ClsFltr_UL1D_HSPA_PRI_HRXBRP_L()
#define ChkL1MsgFltr_UL1D_TRC_HRXBRP_DBG3()	ChkL1ClsFltr_UL1D_HSPA_PRI_HRXBRP_L()
#define ChkL1MsgFltr_UL1D_TRC_HRXBRP_DBG4()	ChkL1ClsFltr_UL1D_HSPA_PRI_HRXBRP_L()
#define ChkL1MsgFltr_UL1D_TRC_HRXBRP_S_VALUE()	ChkL1ClsFltr_UL1D_HSPA_PRI_HRXBRP_L()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_STATE()	ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_H()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_INFO_IND()	ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_M()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_DATA_IND()	ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_H()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_MAC_EVENT()	ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_H()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_RECONFIG()	ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_H()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_EDPDCH_CONFIG()	ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_H()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_HI_CONFIG()	ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_H()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_RG_CONFIG()	ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_H()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_STS_INFO1()	ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_M()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_STS_INFO2()	ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_M()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_STS_INFO3()	ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_H()
#define ChkL1MsgFltr_UL1D_TRC_ETXCRP_GET_BUFFER()	ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_H()
#define ChkL1MsgFltr_UL1D_TRC_ETXCRP_FREE_BUFFER()	ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_H()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_L2_TICK4_FAIL()	ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_H()
#define ChkL1MsgFltr_UL1D_TRC_DBG_ETX_CR()	ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_H()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_GRANT_BITS_INFO()	ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_L()
#define ChkL1MsgFltr_UL1D_TRC_EDCH_RG_THRESHOLD_INFO()	ChkL1ClsFltr_UL1D_HSPA_PRI_EDCHSM_M()
#define ChkL1MsgFltr_UL1D_TRC_PRE_START_INFO()	ChkL1ClsFltr_UL1D_HSPA_PRI_PRESTR_H()
#define ChkL1MsgFltr_UL1D_TRC_RF_RX_CAL_SETTING()	ChkL1ClsFltr_UL1D_HSPA_PRI_PRESTR_H()
#define ChkL1MsgFltr_UL1D_TRC_RF_TX_CAL_SETTING()	ChkL1ClsFltr_UL1D_HSPA_PRI_PRESTR_H()


#endif
