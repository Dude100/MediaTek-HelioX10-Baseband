#ifndef L1TRC_UL1D_SIXTH_DEF_H
#define L1TRC_UL1D_SIXTH_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1D_TRC_STR_DL_DCH_RECONFIG(v1)  (unsigned char)(v1+0)
#define UL1D_TRC_STR_DPCH_TYPE(v1)  (unsigned char)(v1+8)
#define UL1D_TRC_STR_UL_DPCH_CONFIG(v1)  (unsigned char)(v1+10)
#define UL1D_TRC_STR_DPC_MODE(v1)  (unsigned char)(v1+19)
#define UL1D_TRC_STR_NWSCAN_EVENT(v1)  (unsigned char)(v1+21)
#define UL1D_TRC_CM_CONFIG_STR(v1)  (unsigned char)(v1+27)
#define UL1D_TRC_PhCHScramblingCodeUsage_STR(v1)  (unsigned char)(v1+30)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DL_DCH_UPDATE_RXBRP_ID(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0032, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_UPDATE_RXBRP_ID(v1, v2)
#endif
#define UL1D_TRC_DL_DCH_UPDATE_RXBRP_ID_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0032, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_DPCH_TYPE(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0132, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_DPCH_TYPE(v1)
#endif
#define UL1D_TRC_DL_DCH_DPCH_TYPE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0132, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_RECONFIG(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0232, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_RECONFIG(v1)
#endif
#define UL1D_TRC_DL_DCH_RECONFIG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0232, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DL_DCH_INFO(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0332, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_INFO(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_DL_DCH_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0332, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_RXBRP_CALCULATE_PARAM() do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0432, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_RXBRP_CALCULATE_PARAM()
#endif
#define UL1D_TRC_DL_DCH_RXBRP_CALCULATE_PARAM_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0432, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_RXBRP_CONFIG() do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0532, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_RXBRP_CONFIG()
#endif
#define UL1D_TRC_DL_DCH_RXBRP_CONFIG_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0532, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_DMA_DONE_POST_RECONFIG(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0632, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_DMA_DONE_POST_RECONFIG(v1)
#endif
#define UL1D_TRC_DL_DCH_DMA_DONE_POST_RECONFIG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0632, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_GET_RL_BUFFER(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0732, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_GET_RL_BUFFER(v1)
#endif
#define UL1D_TRC_DL_DCH_GET_RL_BUFFER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0732, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_FREE_RL_BUFFER(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0832, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_FREE_RL_BUFFER(v1)
#endif
#define UL1D_TRC_DL_DCH_FREE_RL_BUFFER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0832, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_GET_RXBRP_BUFFER(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0932, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_GET_RXBRP_BUFFER(v1)
#endif
#define UL1D_TRC_DL_DCH_GET_RXBRP_BUFFER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0932, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_FREE_RXBRP_BUFFER(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A32, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_FREE_RXBRP_BUFFER(v1)
#endif
#define UL1D_TRC_DL_DCH_FREE_RXBRP_BUFFER_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A32, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DL_DCH_ADAPT_IOT_WORKAROUND(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B32, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_DL_DCH_ADAPT_IOT_WORKAROUND(v1, v2)
#endif
#define UL1D_TRC_DL_DCH_ADAPT_IOT_WORKAROUND_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B32, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UL_DCH_INI_PWR(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C32, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_UL_DCH_INI_PWR(v1, v2, v3)
#endif
#define UL1D_TRC_UL_DCH_INI_PWR_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C32, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UL_DCH_HISR_PARAM_INFO(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D32, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_UL_DCH_HISR_PARAM_INFO(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_UL_DCH_HISR_PARAM_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D32, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_UL_DCH_HISR_INFO(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E32, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v2), (unsigned char)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_UL_DCH_HISR_INFO(v1, v2, v3, v4)
#endif
#define UL1D_TRC_UL_DCH_HISR_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E32, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v2), (unsigned char)(v3)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_UL_DCH_CONFIG_INFO(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F32, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_UL_DCH_CONFIG_INFO(v1, v2)
#endif
#define UL1D_TRC_UL_DCH_CONFIG_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F32, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DPC_FDPCH_CER_TARGET(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1032, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_FDPCH_CER_TARGET(v1, v2)
#endif
#define UL1D_TRC_DPC_FDPCH_CER_TARGET_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1032, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_FDPCH_SIR_TARGET_DB(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1132, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_FDPCH_SIR_TARGET_DB(v1, v2)
#endif
#define UL1D_TRC_DPC_FDPCH_SIR_TARGET_DB_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1132, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_FDPCH_RMIS(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1232, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_FDPCH_RMIS(v1, v2)
#endif
#define UL1D_TRC_DPC_FDPCH_RMIS_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1232, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_FDPCH_RMIS_EST(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x1332, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_DPC_FDPCH_RMIS_EST(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_DPC_FDPCH_RMIS_EST_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x1332, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_FDPCH_ADJUST(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1432, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_DPC_FDPCH_ADJUST(v1, v2)
#endif
#define UL1D_TRC_DPC_FDPCH_ADJUST_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1432, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DPC_FDPCH_RMIS_RATE(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1532, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_DPC_FDPCH_RMIS_RATE(v1)
#endif
#define UL1D_TRC_DPC_FDPCH_RMIS_RATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1532, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_FDPCH_DBG3(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1632, (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_DPC_FDPCH_DBG3(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DPC_FDPCH_DBG3_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1632, (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_RXSRP_SIG_AMP(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1732, (short)(v1)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_RXSRP_SIG_AMP(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_DPC_RXSRP_SIG_AMP_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1732, (short)(v1)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DPC_RXSRP_SVC_ID(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1832, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_RXSRP_SVC_ID(v1, v2)
#endif
#define UL1D_TRC_DPC_RXSRP_SVC_ID_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1832, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_Trc_DPC_CMD(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1932, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_Trc_DPC_CMD(v1, v2, v3, v4)
#endif
#define UL1D_Trc_DPC_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1932, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DPC_DBG_LEVEL1(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1A32, (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DBG_LEVEL1(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_DPC_DBG_LEVEL1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1A32, (unsigned char)(v1), (char)(v3)), TRC_MERGE_4C((char)(v4), (char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_DBG_LEVEL2_TRCH_IND_MAP(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1B32, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DBG_LEVEL2_TRCH_IND_MAP(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_DPC_DBG_LEVEL2_TRCH_IND_MAP_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1B32, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_DBG_LEVEL2_RECONFIG_FLAG_TRCH(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1C32, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DBG_LEVEL2_RECONFIG_FLAG_TRCH(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_DPC_DBG_LEVEL2_RECONFIG_FLAG_TRCH_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1C32, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_DBG_LEVEL2_EVAL_LIST(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1D32, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DBG_LEVEL2_EVAL_LIST(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_DPC_DBG_LEVEL2_EVAL_LIST_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1D32, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_DBG_LEVEL2_USE_FLAG_TRCH(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1E32, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DBG_LEVEL2_USE_FLAG_TRCH(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_DPC_DBG_LEVEL2_USE_FLAG_TRCH_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1E32, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_DBG_LEVEL2_VERY_LOW_BLER_FLAG(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1F32, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DBG_LEVEL2_VERY_LOW_BLER_FLAG(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_DPC_DBG_LEVEL2_VERY_LOW_BLER_FLAG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1F32, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_DBG_LEVEL2_BLOCK_TRCH_IND(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2032, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DBG_LEVEL2_BLOCK_TRCH_IND(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_DPC_DBG_LEVEL2_BLOCK_TRCH_IND_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2032, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_DBG_LEVEL2_ACTIVE_FLAG_TRCH(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2132, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DBG_LEVEL2_ACTIVE_FLAG_TRCH(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_DPC_DBG_LEVEL2_ACTIVE_FLAG_TRCH_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2132, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_NUM_ERASED_BLK_ACQ(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2232, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_DPC_NUM_ERASED_BLK_ACQ(v1)
#endif
#define UL1D_TRC_DPC_NUM_ERASED_BLK_ACQ_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2232, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_REF_TRCH_ELAPSED_FRAME_CNT(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2332, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_DPC_REF_TRCH_ELAPSED_FRAME_CNT(v1, v2, v3)
#endif
#define UL1D_TRC_DPC_REF_TRCH_ELAPSED_FRAME_CNT_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2332, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_BLOCK_TRCH_TTI_CNT(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2432, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_BLOCK_TRCH_TTI_CNT(v1, v2)
#endif
#define UL1D_TRC_DPC_BLOCK_TRCH_TTI_CNT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2432, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DPC_DPCOUNTER_STARTED(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2532, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DPCOUNTER_STARTED(v1)
#endif
#define UL1D_TRC_DPC_DPCOUNTER_STARTED_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2532, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_BLER_EST(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x2632, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_DPC_BLER_EST(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_DPC_BLER_EST_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x2632, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_SIR_MEASURED_DB(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2732, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_DPC_SIR_MEASURED_DB(v1, v2)
#endif
#define UL1D_TRC_DPC_SIR_MEASURED_DB_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2732, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_TRK_BACK_TO_ACQ_CHECK(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2832, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_TRK_BACK_TO_ACQ_CHECK(v1)
#endif
#define UL1D_TRC_DPC_TRK_BACK_TO_ACQ_CHECK_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2832, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DPC_SUSPEND_WIND_UP_CHECK(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2932, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_SUSPEND_WIND_UP_CHECK(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DPC_SUSPEND_WIND_UP_CHECK_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2932, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DPC_DPCCH_INTEREFENCE_DETECT(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A32, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DPC_DPCCH_INTEREFENCE_DETECT(v1, v2, v3)
#endif
#define UL1D_TRC_DPC_DPCCH_INTEREFENCE_DETECT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A32, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NEW_MEAS_QUE(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B32, (short)(v1)), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_NEW_MEAS_QUE(v1, v2, v3)
#endif
#define UL1D_TRC_NEW_MEAS_QUE_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B32, (short)(v1)), (long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NEW_MEAS_QUE2(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C32, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_NEW_MEAS_QUE2(v1, v2)
#endif
#define UL1D_TRC_NEW_MEAS_QUE2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C32, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NEW_MEAS_CFG(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2D32, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_NEW_MEAS_CFG(v1, v2, v3)
#endif
#define UL1D_TRC_NEW_MEAS_CFG_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2D32, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_SET_MEAS_CALLBACK(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E32, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_SET_MEAS_CALLBACK(v1, v2)
#endif
#define UL1D_TRC_SET_MEAS_CALLBACK_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E32, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GET_MEAS_CALLBACK(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F32, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_GET_MEAS_CALLBACK(v1, v2)
#endif
#define UL1D_TRC_GET_MEAS_CALLBACK_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F32, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_CONFIG_CELL_LIST(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3032, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CONFIG_CELL_LIST(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_CONFIG_CELL_LIST_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3032, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_50MS_RESET(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3132, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_50MS_RESET(v1)
#endif
#define UL1D_TRC_50MS_RESET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3132, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_50MS_CELL_CONFIG(v1, v2, v3, v4, v5) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3232, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_50MS_CELL_CONFIG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_50MS_CELL_CONFIG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3232, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_50MS_LIST_FULL(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3332, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_50MS_LIST_FULL(v1, v2)
#endif
#define UL1D_TRC_50MS_LIST_FULL_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3332, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_50MS_CS4_INFO(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3432, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_50MS_CS4_INFO(v1, v2, v3)
#endif
#define UL1D_TRC_50MS_CS4_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3432, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ENHANCED_CM_CELL(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3532, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ENHANCED_CM_CELL(v1, v2, v3)
#endif
#define UL1D_TRC_ENHANCED_CM_CELL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3532, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MEAS_TIMING_INFO(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3632, (short)(v4)), (long)(v1), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_TIMING_INFO(v1, v2, v3, v4)
#endif
#define UL1D_TRC_MEAS_TIMING_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3632, (short)(v4)), (long)(v1), (unsigned long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TRCH_BLER(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3732, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TRCH_BLER(v1, v2, v3, v4)
#endif
#define UL1D_TRC_TRCH_BLER_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3732, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TRCH_BLER_RESET(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3832, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TRCH_BLER_RESET(v1)
#endif
#define UL1D_TRC_TRCH_BLER_RESET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3832, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_PICH_DISABLE(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3932, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PICH_DISABLE(v1)
#endif
#define UL1D_TRC_PICH_DISABLE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3932, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_PCH_TFCI_ADJ(v1) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3A32, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PCH_TFCI_ADJ(v1)
#endif
#define UL1D_TRC_PCH_TFCI_ADJ_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3A32, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_PI_REPEAT(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3B32, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_PI_REPEAT(v1, v2, v3, v4)
#endif
#define UL1D_TRC_PI_REPEAT_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3B32, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DRX_CYCLE_CONFIG(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3C32, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DRX_CYCLE_CONFIG(v1, v2)
#endif
#define UL1D_TRC_DRX_CYCLE_CONFIG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3C32, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NWSCAN_EVENT(v1, v2, v3) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3D32, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_NWSCAN_EVENT(v1, v2, v3)
#endif
#define UL1D_TRC_NWSCAN_EVENT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3D32, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NWSCAN_ADDNEWCELL(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3E32, (short)(v1)), TRC_MERGE_4C((char)(v2), (char)(v3), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_NWSCAN_ADDNEWCELL(v1, v2, v3, v4)
#endif
#define UL1D_TRC_NWSCAN_ADDNEWCELL_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3E32, (short)(v1)), TRC_MERGE_4C((char)(v2), (char)(v3), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NWSCAN_FSCM_DONE(v1, v2, v3, v4) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3F32, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (unsigned char)(v4)));\
	} while(0)
#else
	#define UL1D_TRC_NWSCAN_FSCM_DONE(v1, v2, v3, v4)
#endif
#define UL1D_TRC_NWSCAN_FSCM_DONE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3F32, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (unsigned char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_NWSCAN_MEASCELLFULL(v1, v2) do {\
		if(UL1D_SIXTH_Trace_Filter[0]==1 && (UL1D_SIXTH_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4032, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_NWSCAN_MEASCELLFULL(v1, v2)
#endif
#define UL1D_TRC_NWSCAN_MEASCELLFULL_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4032, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1D_SIXTH_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1D_TRC_DL_DCH_UPDATE_RXBRP_ID(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_DL_DCH_DPCH_TYPE(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DL_DCH_RECONFIG(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DL_DCH_INFO(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_UL1D_TRC_DL_DCH_RXBRP_CALCULATE_PARAM(void);
void L1TRC_Send_UL1D_TRC_DL_DCH_RXBRP_CONFIG(void);
void L1TRC_Send_UL1D_TRC_DL_DCH_DMA_DONE_POST_RECONFIG(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DL_DCH_GET_RL_BUFFER(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DL_DCH_FREE_RL_BUFFER(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DL_DCH_GET_RXBRP_BUFFER(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DL_DCH_FREE_RXBRP_BUFFER(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DL_DCH_ADAPT_IOT_WORKAROUND(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_UL_DCH_INI_PWR(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_UL_DCH_HISR_PARAM_INFO(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_UL_DCH_HISR_INFO(short v1, unsigned char v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_UL_DCH_CONFIG_INFO(unsigned char v1, short v2);
void L1TRC_Send_UL1D_TRC_DPC_FDPCH_CER_TARGET(short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_DPC_FDPCH_SIR_TARGET_DB(short v1, short v2);
void L1TRC_Send_UL1D_TRC_DPC_FDPCH_RMIS(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_DPC_FDPCH_RMIS_EST(short v1, short v2, long v3, long v4, long v5);
void L1TRC_Send_UL1D_TRC_DPC_FDPCH_ADJUST(long v1, long v2);
void L1TRC_Send_UL1D_TRC_DPC_FDPCH_RMIS_RATE(short v1);
void L1TRC_Send_UL1D_TRC_DPC_FDPCH_DBG3(long v1, long v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_DPC_RXSRP_SIG_AMP(short v1, unsigned char v2, unsigned char v3, unsigned char v4, short v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_DPC_RXSRP_SVC_ID(unsigned char v1, unsigned short v2);
void L1TRC_Send_UL1D_Trc_DPC_CMD(unsigned short v1, short v2, unsigned short v3, short v4);
void L1TRC_Send_UL1D_TRC_DPC_DBG_LEVEL1(unsigned char v1, long v2, char v3, char v4, char v5);
void L1TRC_Send_UL1D_TRC_DPC_DBG_LEVEL2_TRCH_IND_MAP(char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8);
void L1TRC_Send_UL1D_TRC_DPC_DBG_LEVEL2_RECONFIG_FLAG_TRCH(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_UL1D_TRC_DPC_DBG_LEVEL2_EVAL_LIST(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_UL1D_TRC_DPC_DBG_LEVEL2_USE_FLAG_TRCH(char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8);
void L1TRC_Send_UL1D_TRC_DPC_DBG_LEVEL2_VERY_LOW_BLER_FLAG(char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8);
void L1TRC_Send_UL1D_TRC_DPC_DBG_LEVEL2_BLOCK_TRCH_IND(char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8);
void L1TRC_Send_UL1D_TRC_DPC_DBG_LEVEL2_ACTIVE_FLAG_TRCH(char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8);
void L1TRC_Send_UL1D_TRC_DPC_NUM_ERASED_BLK_ACQ(short v1);
void L1TRC_Send_UL1D_TRC_DPC_REF_TRCH_ELAPSED_FRAME_CNT(long v1, long v2, long v3);
void L1TRC_Send_UL1D_TRC_DPC_BLOCK_TRCH_TTI_CNT(char v1, short v2);
void L1TRC_Send_UL1D_TRC_DPC_DPCOUNTER_STARTED(char v1);
void L1TRC_Send_UL1D_TRC_DPC_BLER_EST(char v1, char v2, long v3, long v4, long v5, long v6, char v7);
void L1TRC_Send_UL1D_TRC_DPC_SIR_MEASURED_DB(long v1, long v2);
void L1TRC_Send_UL1D_TRC_DPC_TRK_BACK_TO_ACQ_CHECK(unsigned char v1);
void L1TRC_Send_UL1D_TRC_DPC_SUSPEND_WIND_UP_CHECK(unsigned char v1, unsigned char v2, unsigned char v3, short v4);
void L1TRC_Send_UL1D_TRC_DPC_DPCCH_INTEREFENCE_DETECT(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_NEW_MEAS_QUE(short v1, long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_NEW_MEAS_QUE2(short v1, short v2);
void L1TRC_Send_UL1D_TRC_NEW_MEAS_CFG(short v1, long v2, short v3);
void L1TRC_Send_UL1D_TRC_SET_MEAS_CALLBACK(unsigned char v1, short v2);
void L1TRC_Send_UL1D_TRC_GET_MEAS_CALLBACK(short v1, short v2);
void L1TRC_Send_UL1D_TRC_CONFIG_CELL_LIST(short v1, short v2, short v3, short v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_50MS_RESET(short v1);
void L1TRC_Send_UL1D_TRC_50MS_CELL_CONFIG(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_50MS_LIST_FULL(short v1, short v2);
void L1TRC_Send_UL1D_TRC_50MS_CS4_INFO(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_ENHANCED_CM_CELL(short v1, short v2, char v3);
void L1TRC_Send_UL1D_TRC_MEAS_TIMING_INFO(long v1, unsigned long v2, long v3, short v4);
void L1TRC_Send_UL1D_TRC_TRCH_BLER(char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_TRCH_BLER_RESET(char v1);
void L1TRC_Send_UL1D_TRC_PICH_DISABLE(char v1);
void L1TRC_Send_UL1D_TRC_PCH_TFCI_ADJ(char v1);
void L1TRC_Send_UL1D_TRC_PI_REPEAT(short v1, short v2, char v3, short v4);
void L1TRC_Send_UL1D_TRC_DRX_CYCLE_CONFIG(short v1, short v2);
void L1TRC_Send_UL1D_TRC_NWSCAN_EVENT(unsigned char v1, char v2, short v3);
void L1TRC_Send_UL1D_TRC_NWSCAN_ADDNEWCELL(short v1, char v2, char v3, char v4);
void L1TRC_Send_UL1D_TRC_NWSCAN_FSCM_DONE(unsigned char v1, short v2, short v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_NWSCAN_MEASCELLFULL(short v1, char v2);

void Set_UL1D_SIXTH_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1D_SIXTH()	(UL1D_SIXTH_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_DLDCH_M()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_DLDCH_L()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_ULDCH_M()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_ULDCH_H()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_ULDCH_L()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_DPC_H()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_DPC_M()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_DPC_L()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_H()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_L()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_BLER_M()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_PICH_M()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_SIXTH_NWSCAN_M()	(ChkL1ModFltr_UL1D_SIXTH()&&((UL1D_SIXTH_Trace_Filter[2]&0x40)!=0))
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_UPDATE_RXBRP_ID()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_L()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_DPCH_TYPE()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_RECONFIG()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_INFO()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_L()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_RXBRP_CALCULATE_PARAM()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_RXBRP_CONFIG()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_DMA_DONE_POST_RECONFIG()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_GET_RL_BUFFER()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_FREE_RL_BUFFER()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_GET_RXBRP_BUFFER()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_FREE_RXBRP_BUFFER()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DL_DCH_ADAPT_IOT_WORKAROUND()	ChkL1ClsFltr_UL1D_SIXTH_DLDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_UL_DCH_INI_PWR()	ChkL1ClsFltr_UL1D_SIXTH_ULDCH_M()
#define ChkL1MsgFltr_UL1D_TRC_UL_DCH_HISR_PARAM_INFO()	ChkL1ClsFltr_UL1D_SIXTH_ULDCH_M()
#define ChkL1MsgFltr_UL1D_TRC_UL_DCH_HISR_INFO()	ChkL1ClsFltr_UL1D_SIXTH_ULDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_UL_DCH_CONFIG_INFO()	ChkL1ClsFltr_UL1D_SIXTH_ULDCH_H()
#define ChkL1MsgFltr_UL1D_TRC_DPC_FDPCH_CER_TARGET()	ChkL1ClsFltr_UL1D_SIXTH_DPC_H()
#define ChkL1MsgFltr_UL1D_TRC_DPC_FDPCH_SIR_TARGET_DB()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_FDPCH_RMIS()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_FDPCH_RMIS_EST()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_FDPCH_ADJUST()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_FDPCH_RMIS_RATE()	ChkL1ClsFltr_UL1D_SIXTH_DPC_H()
#define ChkL1MsgFltr_UL1D_TRC_DPC_FDPCH_DBG3()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_RXSRP_SIG_AMP()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_RXSRP_SVC_ID()	ChkL1ClsFltr_UL1D_SIXTH_DPC_H()
#define ChkL1MsgFltr_UL1D_Trc_DPC_CMD()	ChkL1ClsFltr_UL1D_SIXTH_DPC_H()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DBG_LEVEL1()	ChkL1ClsFltr_UL1D_SIXTH_DPC_H()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DBG_LEVEL2_TRCH_IND_MAP()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DBG_LEVEL2_RECONFIG_FLAG_TRCH()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DBG_LEVEL2_EVAL_LIST()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DBG_LEVEL2_USE_FLAG_TRCH()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DBG_LEVEL2_VERY_LOW_BLER_FLAG()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DBG_LEVEL2_BLOCK_TRCH_IND()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DBG_LEVEL2_ACTIVE_FLAG_TRCH()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_NUM_ERASED_BLK_ACQ()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_REF_TRCH_ELAPSED_FRAME_CNT()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_BLOCK_TRCH_TTI_CNT()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DPCOUNTER_STARTED()	ChkL1ClsFltr_UL1D_SIXTH_DPC_L()
#define ChkL1MsgFltr_UL1D_TRC_DPC_BLER_EST()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_SIR_MEASURED_DB()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_TRK_BACK_TO_ACQ_CHECK()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_SUSPEND_WIND_UP_CHECK()	ChkL1ClsFltr_UL1D_SIXTH_DPC_M()
#define ChkL1MsgFltr_UL1D_TRC_DPC_DPCCH_INTEREFENCE_DETECT()	ChkL1ClsFltr_UL1D_SIXTH_DPC_H()
#define ChkL1MsgFltr_UL1D_TRC_NEW_MEAS_QUE()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_NEW_MEAS_QUE2()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_NEW_MEAS_CFG()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_SET_MEAS_CALLBACK()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_GET_MEAS_CALLBACK()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_CONFIG_CELL_LIST()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_50MS_RESET()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_50MS_CELL_CONFIG()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_50MS_LIST_FULL()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_50MS_CS4_INFO()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_M()
#define ChkL1MsgFltr_UL1D_TRC_ENHANCED_CM_CELL()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_TIMING_INFO()	ChkL1ClsFltr_UL1D_SIXTH_UL1D_New_Meas_L()
#define ChkL1MsgFltr_UL1D_TRC_TRCH_BLER()	ChkL1ClsFltr_UL1D_SIXTH_BLER_M()
#define ChkL1MsgFltr_UL1D_TRC_TRCH_BLER_RESET()	ChkL1ClsFltr_UL1D_SIXTH_BLER_M()
#define ChkL1MsgFltr_UL1D_TRC_PICH_DISABLE()	ChkL1ClsFltr_UL1D_SIXTH_PICH_M()
#define ChkL1MsgFltr_UL1D_TRC_PCH_TFCI_ADJ()	ChkL1ClsFltr_UL1D_SIXTH_PICH_M()
#define ChkL1MsgFltr_UL1D_TRC_PI_REPEAT()	ChkL1ClsFltr_UL1D_SIXTH_PICH_M()
#define ChkL1MsgFltr_UL1D_TRC_DRX_CYCLE_CONFIG()	ChkL1ClsFltr_UL1D_SIXTH_PICH_M()
#define ChkL1MsgFltr_UL1D_TRC_NWSCAN_EVENT()	ChkL1ClsFltr_UL1D_SIXTH_NWSCAN_M()
#define ChkL1MsgFltr_UL1D_TRC_NWSCAN_ADDNEWCELL()	ChkL1ClsFltr_UL1D_SIXTH_NWSCAN_M()
#define ChkL1MsgFltr_UL1D_TRC_NWSCAN_FSCM_DONE()	ChkL1ClsFltr_UL1D_SIXTH_NWSCAN_M()
#define ChkL1MsgFltr_UL1D_TRC_NWSCAN_MEASCELLFULL()	ChkL1ClsFltr_UL1D_SIXTH_NWSCAN_M()


#endif
