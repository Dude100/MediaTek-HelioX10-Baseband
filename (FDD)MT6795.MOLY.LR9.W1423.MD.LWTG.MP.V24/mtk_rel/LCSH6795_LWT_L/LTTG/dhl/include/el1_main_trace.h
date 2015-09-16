#ifndef L1TRC_EL1_MAIN_DEF_H
#define L1TRC_EL1_MAIN_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1_BW_Str(v1)  (unsigned char)(v1+0)
#define EL1_CH_Str(v1)  (unsigned char)(v1+8)
#define EL1_CH_Evt_Str(v1)  (unsigned char)(v1+20)
#define EL1_CH_Ctrl_Str(v1)  (unsigned char)(v1+33)
#define EL1_SCS_Ctrl_Str(v1)  (unsigned char)(v1+39)
#define EL1_BCCH_PURPOSE_Str(v1)  (unsigned char)(v1+44)
#define EL1_BCCH_TYPE_Str(v1)  (unsigned char)(v1+51)
#define EL1_PCH_NB_Str(v1)  (unsigned char)(v1+54)
#define EL1_PCH_MOD_Str(v1)  (unsigned char)(v1+62)
#define EL1_SCH_EVT_Str(v1)  (unsigned char)(v1+66)
#define EL1_CSR_Str(v1)  (unsigned char)(v1+76)
#define EL1_CSR_ST_Str(v1)  (unsigned char)(v1+84)
#define EL1_CSR_Purpose_Str(v1)  (unsigned char)(v1+91)
#define EL1_CSR_Cause_Str(v1)  (unsigned char)(v1+96)
#define EL1_EFUSE_Str(v1)  (unsigned char)(v1+99)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_RECAL_SLEEP_TIME(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0008, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1_RECAL_SLEEP_TIME(v1, v2, v3)
#endif
#define EL1_RECAL_SLEEP_TIME_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0008, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CAPTURE_START(v1) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0108, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1_CAPTURE_START(v1)
#endif
#define EL1_CAPTURE_START_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0108, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CAPTURE_STOP(v1) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0208, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1_CAPTURE_STOP(v1)
#endif
#define EL1_CAPTURE_STOP_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0208, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CAPTURE_STOP_COUNT_DOWN(v1) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0308, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CAPTURE_STOP_COUNT_DOWN(v1)
#endif
#define EL1_CAPTURE_STOP_COUNT_DOWN_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0308, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CH_LOG(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0408, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1_CH_LOG(v1, v2)
#endif
#define EL1_CH_LOG_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0408, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_SCS_LOG0(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0508, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_SCS_LOG0(v1, v2, v3)
#endif
#define EL1_SCS_LOG0_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0508, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_BCCH_LOG0(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0608, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_BCCH_LOG0(v1, v2, v3)
#endif
#define EL1_BCCH_LOG0_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0608, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_BCCH_LOG1(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0708, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_BCCH_LOG1(v1, v2, v3, v4)
#endif
#define EL1_BCCH_LOG1_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0708, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_BCCH_LOG2(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0808, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_BCCH_LOG2(v1, v2)
#endif
#define EL1_BCCH_LOG2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0808, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_PCH_LOG0(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0908, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_PCH_LOG0(v1, v2, v3, v4, v5, v6)
#endif
#define EL1_PCH_LOG0_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0908, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_PCH_LOG1(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A08, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), (unsigned char)(v4)));\
	} while(0)
#else
	#define EL1_PCH_LOG1(v1, v2, v3, v4)
#endif
#define EL1_PCH_LOG1_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A08, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (unsigned char)(v3), (unsigned char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_REQ(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B08, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_REQ(v1, v2, v3)
#endif
#define EL1_CSR_LOG_REQ_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B08, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_PARAM0(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C08, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_PARAM0(v1, v2, v3)
#endif
#define EL1_CSR_LOG_PARAM0_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C08, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_PARAM1(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D08, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_PARAM1(v1, v2, v3)
#endif
#define EL1_CSR_LOG_PARAM1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D08, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_CMD(v1) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E08, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_CMD(v1)
#endif
#define EL1_CSR_LOG_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E08, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_START_CNF(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F08, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1_CSR_LOG_START_CNF(v1, v2)
#endif
#define EL1_CSR_LOG_START_CNF_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F08, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_STOP_CNF(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1008, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1_CSR_LOG_STOP_CNF(v1, v2)
#endif
#define EL1_CSR_LOG_STOP_CNF_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1008, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_RPT(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1108, (unsigned short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_RPT(v1, v2, v3)
#endif
#define EL1_CSR_LOG_RPT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1108, (unsigned short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_CSR_LOG_CELL(v1, v2, v3, v4, v5) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1208, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_CSR_LOG_CELL(v1, v2, v3, v4, v5)
#endif
#define EL1_CSR_LOG_CELL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1208, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_IDC_TX_NTF(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1308, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1_IDC_TX_NTF(v1, v2)
#endif
#define EL1_IDC_TX_NTF_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1308, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_LPP_UPDT_NEXT_PRS(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1408, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1_LPP_UPDT_NEXT_PRS(v1, v2, v3, v4)
#endif
#define EL1_LPP_UPDT_NEXT_PRS_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1408, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_LPP_IS_MUTE_NBR(v1, v2, v3) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1508, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1_LPP_IS_MUTE_NBR(v1, v2, v3)
#endif
#define EL1_LPP_IS_MUTE_NBR_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1508, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_LPP_UPDT_NEXT_REF(v1, v2, v3, v4) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1608, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1_LPP_UPDT_NEXT_REF(v1, v2, v3, v4)
#endif
#define EL1_LPP_UPDT_NEXT_REF_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1608, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_LPP_UPDT_NBR_DATA(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1708, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define EL1_LPP_UPDT_NBR_DATA(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1_LPP_UPDT_NBR_DATA_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1708, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_LPP_GAP(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x1808, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1_LPP_GAP(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1_LPP_GAP_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x1808, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_LPP_GAP_PRS_DIFF(v1, v2) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1908, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_LPP_GAP_PRS_DIFF(v1, v2)
#endif
#define EL1_LPP_GAP_PRS_DIFF_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1908, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EL1_EFUSE_TURN_OFF(v1) do {\
		if(EL1_MAIN_Trace_Filter[0]==1 && (EL1_MAIN_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A08, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1_EFUSE_TURN_OFF(v1)
#endif
#define EL1_EFUSE_TURN_OFF_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A08, (unsigned char)(v1), TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1_MAIN_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1_RECAL_SLEEP_TIME(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1_CAPTURE_START(unsigned long v1);
void L1TRC_Send_EL1_CAPTURE_STOP(unsigned long v1);
void L1TRC_Send_EL1_CAPTURE_STOP_COUNT_DOWN(unsigned char v1);
void L1TRC_Send_EL1_CH_LOG(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1_SCS_LOG0(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1_BCCH_LOG0(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1_BCCH_LOG1(unsigned char v1, unsigned char v2, char v3, unsigned char v4);
void L1TRC_Send_EL1_BCCH_LOG2(unsigned char v1, short v2);
void L1TRC_Send_EL1_PCH_LOG0(unsigned short v1, unsigned short v2, unsigned short v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1_PCH_LOG1(unsigned short v1, unsigned short v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1_CSR_LOG_REQ(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1_CSR_LOG_PARAM0(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1_CSR_LOG_PARAM1(unsigned short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1_CSR_LOG_CMD(unsigned char v1);
void L1TRC_Send_EL1_CSR_LOG_START_CNF(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1_CSR_LOG_STOP_CNF(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1_CSR_LOG_RPT(unsigned char v1, unsigned short v2, short v3);
void L1TRC_Send_EL1_CSR_LOG_CELL(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_EL1_IDC_TX_NTF(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1_LPP_UPDT_NEXT_PRS(unsigned short v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1_LPP_IS_MUTE_NBR(unsigned short v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_EL1_LPP_UPDT_NEXT_REF(unsigned short v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EL1_LPP_UPDT_NBR_DATA(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_EL1_LPP_GAP(unsigned long v1, unsigned long v2, unsigned short v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_EL1_LPP_GAP_PRS_DIFF(unsigned short v1, unsigned short v2);
void L1TRC_Send_EL1_EFUSE_TURN_OFF(unsigned char v1);

void Set_EL1_MAIN_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1_MAIN()	(EL1_MAIN_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1_MAIN_el1_bcch_var_trace()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1_MAIN_el1_pch_var_trace()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1_MAIN_el1_main_var_trace()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1_MAIN_el1_idc_var_trace()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1_MAIN_el1_lpp_var_trace()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1_MAIN_inject_var_trace()	(ChkL1ModFltr_EL1_MAIN()&&((EL1_MAIN_Trace_Filter[1]&0x80)!=0))
#define ChkL1MsgFltr_EL1_RECAL_SLEEP_TIME()	ChkL1ClsFltr_EL1_MAIN_el1_main_var_trace()
#define ChkL1MsgFltr_EL1_CAPTURE_START()	ChkL1ClsFltr_EL1_MAIN_inject_var_trace()
#define ChkL1MsgFltr_EL1_CAPTURE_STOP()	ChkL1ClsFltr_EL1_MAIN_inject_var_trace()
#define ChkL1MsgFltr_EL1_CAPTURE_STOP_COUNT_DOWN()	ChkL1ClsFltr_EL1_MAIN_inject_var_trace()
#define ChkL1MsgFltr_EL1_CH_LOG()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_SCS_LOG0()	ChkL1ClsFltr_EL1_MAIN_el1_ch_var_trace()
#define ChkL1MsgFltr_EL1_BCCH_LOG0()	ChkL1ClsFltr_EL1_MAIN_el1_bcch_var_trace()
#define ChkL1MsgFltr_EL1_BCCH_LOG1()	ChkL1ClsFltr_EL1_MAIN_el1_bcch_var_trace()
#define ChkL1MsgFltr_EL1_BCCH_LOG2()	ChkL1ClsFltr_EL1_MAIN_el1_bcch_var_trace()
#define ChkL1MsgFltr_EL1_PCH_LOG0()	ChkL1ClsFltr_EL1_MAIN_el1_pch_var_trace()
#define ChkL1MsgFltr_EL1_PCH_LOG1()	ChkL1ClsFltr_EL1_MAIN_el1_pch_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_REQ()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_PARAM0()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_PARAM1()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_CMD()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_START_CNF()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_STOP_CNF()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_RPT()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_CSR_LOG_CELL()	ChkL1ClsFltr_EL1_MAIN_el1_csr_var_trace()
#define ChkL1MsgFltr_EL1_IDC_TX_NTF()	ChkL1ClsFltr_EL1_MAIN_el1_idc_var_trace()
#define ChkL1MsgFltr_EL1_LPP_UPDT_NEXT_PRS()	ChkL1ClsFltr_EL1_MAIN_el1_lpp_var_trace()
#define ChkL1MsgFltr_EL1_LPP_IS_MUTE_NBR()	ChkL1ClsFltr_EL1_MAIN_el1_lpp_var_trace()
#define ChkL1MsgFltr_EL1_LPP_UPDT_NEXT_REF()	ChkL1ClsFltr_EL1_MAIN_el1_lpp_var_trace()
#define ChkL1MsgFltr_EL1_LPP_UPDT_NBR_DATA()	ChkL1ClsFltr_EL1_MAIN_el1_lpp_var_trace()
#define ChkL1MsgFltr_EL1_LPP_GAP()	ChkL1ClsFltr_EL1_MAIN_el1_lpp_var_trace()
#define ChkL1MsgFltr_EL1_LPP_GAP_PRS_DIFF()	ChkL1ClsFltr_EL1_MAIN_el1_lpp_var_trace()
#define ChkL1MsgFltr_EL1_EFUSE_TURN_OFF()	ChkL1ClsFltr_EL1_MAIN_el1_main_var_trace()


#endif
