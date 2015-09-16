#ifndef L1TRC_EL1_TX_1_DEF_H
#define L1TRC_EL1_TX_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define Tx_Send_Msg_Str(v1)  (unsigned char)(v1+0)
#define Tx_Rcv_Msg_Str(v1)  (unsigned char)(v1+6)
#define Tx_Grant_Type_Str(v1)  (unsigned char)(v1+27)
#define Rx_Assgn_Type_Str(v1)  (unsigned char)(v1+43)
#define Tx_Pucch_Fmt_Str(v1)  (unsigned char)(v1+52)
#define Tx_CP_Len(v1)  (unsigned char)(v1+59)
#define Tx_TDD_Cfg(v1)  (unsigned char)(v1+61)
#define Tx_BW_Str(v1)  (unsigned char)(v1+69)
#define Tx_ACK_Mode(v1)  (unsigned char)(v1+75)
#define Tx_TA_Type(v1)  (unsigned char)(v1+77)
#define Tx_SGNL0(v1)  (unsigned char)(v1+79)
#define Tx_SGNL1(v1)  (unsigned char)(v1+87)
#define Tx_SGNL2(v1)  (unsigned char)(v1+91)
#define Tx_SGNL3(v1)  (unsigned char)(v1+95)
#define Tx_SGNL4(v1)  (unsigned char)(v1+100)
#define Tx_TPC_Mode(v1)  (unsigned char)(v1+104)
#define Tx_Func(v1)  (unsigned char)(v1+106)
#define Tx_Puxch_Cqi_Str(v1)  (unsigned char)(v1+109)
#define Tx_PL_Alpha_Str(v1)  (unsigned char)(v1+113)
#define Tx_ACK_Str(v1)  (unsigned char)(v1+121)
#define Tx_PH_Str(v1)  (unsigned char)(v1+125)
#define Tx_PCQI_Mode(v1)  (unsigned char)(v1+128)
#define Tx_PCQI_Type(v1)  (unsigned char)(v1+134)
#define Tx_ACQI_Mode(v1)  (unsigned char)(v1+141)
#define Tx_String(v1)  (unsigned char)(v1+147)
#define Tx_CH_Str(v1)  (unsigned char)(v1+183)
#define Tx_CSI_Str(v1)  (unsigned char)(v1+187)
#define Tx_PCQI2_Str(v1)  (unsigned char)(v1+195)
#define Tx_ACQI2_Hi_Str(v1)  (unsigned char)(v1+204)
#define Tx_ACQI2_UE_Str(v1)  (unsigned char)(v1+209)
#define Rx_Qual_Str(v1)  (unsigned char)(v1+213)
#define Rx_DCI_Str(v1)  (unsigned char)(v1+225)
#define UMPR_Src0_Str(v1)  (unsigned char)(v1+237)
#define UMPR_Src1_Str(v1)  (unsigned char)(v1+243)
#define TAS_Str(v1)  (unsigned char)(v1+245)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1TX_LOG_RRC_SYS0(v1, v2, v3, v4) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0007, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), (unsigned char)(v4)));\
	} while(0)
#else
	#define EL1TX_LOG_RRC_SYS0(v1, v2, v3, v4)
#endif
#define EL1TX_LOG_RRC_SYS0_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0007, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), (unsigned char)(v4)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RRC_SYS1(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0107, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RRC_SYS1(v1, v2, v3)
#endif
#define EL1TX_LOG_RRC_SYS1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0107, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RRC_SYS2(v1, v2, v3, v4, v5) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0207, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RRC_SYS2(v1, v2, v3, v4, v5)
#endif
#define EL1TX_LOG_RRC_SYS2_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0207, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RRC_PRACH0(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0307, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RRC_PRACH0(v1, v2, v3)
#endif
#define EL1TX_LOG_RRC_PRACH0_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0307, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RRC_PRACH(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0407, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RRC_PRACH(v1, v2, v3)
#endif
#define EL1TX_LOG_RRC_PRACH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0407, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RRC_PUCCH(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0507, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define EL1TX_LOG_RRC_PUCCH(v1, v2, v3, v4, v5, v6)
#endif
#define EL1TX_LOG_RRC_PUCCH_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0507, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RRC_PUSCH(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0607, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RRC_PUSCH(v1, v2, v3)
#endif
#define EL1TX_LOG_RRC_PUSCH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0607, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RRC_SPS_UL(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0707, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RRC_SPS_UL(v1, v2, v3)
#endif
#define EL1TX_LOG_RRC_SPS_UL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0707, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RRC_SPS_DL(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0807, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RRC_SPS_DL(v1, v2)
#endif
#define EL1TX_LOG_RRC_SPS_DL_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0807, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RRC_CQI0(v1, v2, v3, v4, v5) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0907, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RRC_CQI0(v1, v2, v3, v4, v5)
#endif
#define EL1TX_LOG_RRC_CQI0_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0907, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RRC_CQI1(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A07, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_RRC_CQI1(v1, v2)
#endif
#define EL1TX_LOG_RRC_CQI1_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A07, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RRC_SRS0(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B07, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RRC_SRS0(v1, v2, v3)
#endif
#define EL1TX_LOG_RRC_SRS0_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B07, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RRC_SRS1(v1, v2, v3, v4, v5) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0C07, (unsigned short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RRC_SRS1(v1, v2, v3, v4, v5)
#endif
#define EL1TX_LOG_RRC_SRS1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0C07, (unsigned short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RRC_SRS2(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D07, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define EL1TX_LOG_RRC_SRS2(v1, v2, v3, v4, v5, v6)
#endif
#define EL1TX_LOG_RRC_SRS2_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D07, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RRC_PCMAX(v1, v2, v3, v4, v5) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E07, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RRC_PCMAX(v1, v2, v3, v4, v5)
#endif
#define EL1TX_LOG_RRC_PCMAX_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E07, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RAR_GRANT(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F07, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RAR_GRANT(v1, v2, v3)
#endif
#define EL1TX_LOG_RAR_GRANT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F07, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RAR_MATCH(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1007, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RAR_MATCH(v1, v2, v3)
#endif
#define EL1TX_LOG_RAR_MATCH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1007, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_PRACH_INFO(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1107, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_PRACH_INFO(v1, v2, v3)
#endif
#define EL1TX_LOG_PRACH_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1107, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TA_INFO(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1207, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_TA_INFO(v1, v2, v3)
#endif
#define EL1TX_LOG_TA_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1207, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1TX_LOG_TXPWR_FI(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1307, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_TXPWR_FI(v1, v2)
#endif
#define EL1TX_LOG_TXPWR_FI_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1307, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1TX_LOG_TXPWR_GI(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1407, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_TXPWR_GI(v1, v2, v3)
#endif
#define EL1TX_LOG_TXPWR_GI_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1407, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_GAP(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1507, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1TX_LOG_GAP(v1, v2, v3)
#endif
#define EL1TX_LOG_GAP_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1507, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_DL_PDCCH_INFO(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1607, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_DL_PDCCH_INFO(v1, v2)
#endif
#define EL1TX_LOG_DL_PDCCH_INFO_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1607, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_UL_PDCCH_INFO(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1707, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_UL_PDCCH_INFO(v1, v2)
#endif
#define EL1TX_LOG_UL_PDCCH_INFO_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1707, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_UL_GRANT_PROC(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1807, (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((char)(v6), (unsigned char)(v7), (char)(v8), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_UL_GRANT_PROC(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EL1TX_LOG_UL_GRANT_PROC_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1807, (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((char)(v6), (unsigned char)(v7), (char)(v8), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_DL_ASSIGN_PROC(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1907, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_DL_ASSIGN_PROC(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EL1TX_LOG_DL_ASSIGN_PROC_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1907, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_DL_PDSCH_CRC(v1, v2, v3, v4, v5) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A07, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define EL1TX_LOG_DL_PDSCH_CRC(v1, v2, v3, v4, v5)
#endif
#define EL1TX_LOG_DL_PDSCH_CRC_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A07, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_DL_PDSCH_TBS(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_DL_PDSCH_TBS(v1, v2)
#endif
#define EL1TX_LOG_DL_PDSCH_TBS_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_PHICH(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C07, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_PHICH(v1, v2, v3)
#endif
#define EL1TX_LOG_PHICH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C07, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_PDCCH_ORDER(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D07, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_PDCCH_ORDER(v1, v2)
#endif
#define EL1TX_LOG_PDCCH_ORDER_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D07, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_CR_INFO(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E07, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_CR_INFO(v1, v2, v3)
#endif
#define EL1TX_LOG_CR_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E07, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_CR_RCV_TIME(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F07, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_CR_RCV_TIME(v1, v2)
#endif
#define EL1TX_LOG_CR_RCV_TIME_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F07, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_CR_ACK_TIME(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2007, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_CR_ACK_TIME(v1, v2)
#endif
#define EL1TX_LOG_CR_ACK_TIME_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2007, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_CTRL_SGNL(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2107, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_CTRL_SGNL(v1, v2)
#endif
#define EL1TX_LOG_CTRL_SGNL_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2107, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_ACK_REP_CNT(v1) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2207, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_ACK_REP_CNT(v1)
#endif
#define EL1TX_LOG_ACK_REP_CNT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2207, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_CRNTI(v1) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2307, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1TX_LOG_CRNTI(v1)
#endif
#define EL1TX_LOG_CRNTI_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2307, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_DRX_PUCCH_INFO(v1, v2, v3, v4) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2407, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_DRX_PUCCH_INFO(v1, v2, v3, v4)
#endif
#define EL1TX_LOG_DRX_PUCCH_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2407, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_DL_UL_INFO(v1, v2, v3, v4, v5) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2507, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1TX_LOG_DL_UL_INFO(v1, v2, v3, v4, v5)
#endif
#define EL1TX_LOG_DL_UL_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2507, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_MCS_INFO(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2607, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_MCS_INFO(v1, v2, v3)
#endif
#define EL1TX_LOG_MCS_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2607, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RX0_INFO(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2707, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RX0_INFO(v1, v2, v3)
#endif
#define EL1TX_LOG_RX0_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2707, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_PWR0_INFO(v1, v2, v3, v4) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2807, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_PWR0_INFO(v1, v2, v3, v4)
#endif
#define EL1TX_LOG_PWR0_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2807, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_PWR1_INFO(v1, v2, v3, v4, v5) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2907, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_PWR1_INFO(v1, v2, v3, v4, v5)
#endif
#define EL1TX_LOG_PWR1_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2907, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_FLOW(v1) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A07, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_FLOW(v1)
#endif
#define EL1TX_LOG_FLOW_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A07, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_FLOW2(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B07, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_FLOW2(v1, v2)
#endif
#define EL1TX_LOG_FLOW2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B07, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1TX_LOG_FLOW_TIME_LV(v1) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2C07, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1TX_LOG_FLOW_TIME_LV(v1)
#endif
#define EL1TX_LOG_FLOW_TIME_LV_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2C07, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_DCI0_FALSE_ALARM(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D07, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_DCI0_FALSE_ALARM(v1, v2, v3)
#endif
#define EL1TX_LOG_DCI0_FALSE_ALARM_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D07, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_DCI_WARNING(v1) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E07, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_DCI_WARNING(v1)
#endif
#define EL1TX_LOG_DCI_WARNING_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E07, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RPT_TIME_ERR(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F07, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RPT_TIME_ERR(v1, v2, v3)
#endif
#define EL1TX_LOG_RPT_TIME_ERR_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F07, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_FUNC_CALL(v1) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3007, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_FUNC_CALL(v1)
#endif
#define EL1TX_LOG_FUNC_CALL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3007, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_MSG_SND(v1) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3107, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_MSG_SND(v1)
#endif
#define EL1TX_LOG_MSG_SND_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3107, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_MSG_RCV(v1) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3207, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_MSG_RCV(v1)
#endif
#define EL1TX_LOG_MSG_RCV_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3207, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1TX_LOG_RT_CMD_PHICH_ENQUEUE(v1, v2, v3, v4) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3307, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PHICH_ENQUEUE(v1, v2, v3, v4)
#endif
#define EL1TX_LOG_RT_CMD_PHICH_ENQUEUE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3307, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_NRT_CMD_PHICH_DECODE(v1, v2, v3, v4) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3407, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_NRT_CMD_PHICH_DECODE(v1, v2, v3, v4)
#endif
#define EL1TX_LOG_NRT_CMD_PHICH_DECODE_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3407, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_NRT_CMD_PDSCH_OPT(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3507, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_NRT_CMD_PDSCH_OPT(v1, v2)
#endif
#define EL1TX_LOG_NRT_CMD_PDSCH_OPT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3507, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_Tx_Enbl(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3607, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_Tx_Enbl(v1, v2, v3, v4, v5, v6)
#endif
#define EL1TX_LOG_RT_CMD_Tx_Enbl_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3607, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_Tx_Enbl1(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3707, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_Tx_Enbl1(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1TX_LOG_RT_CMD_Tx_Enbl1_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x3707, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_Tx_Enbl2(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3807, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_Tx_Enbl2(v1, v2)
#endif
#define EL1TX_LOG_RT_CMD_Tx_Enbl2_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3807, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define El1TX_LOG_RT_CMD_Tx_time(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3907, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define El1TX_LOG_RT_CMD_Tx_time(v1, v2)
#endif
#define El1TX_LOG_RT_CMD_Tx_time_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3907, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1TX_LOG_RT_CMD_Rx_time(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A07, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_Rx_time(v1, v2)
#endif
#define EL1TX_LOG_RT_CMD_Rx_time_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A07, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PUSCH0(v1, v2, v3, v4) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B07, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PUSCH0(v1, v2, v3, v4)
#endif
#define EL1TX_LOG_RT_CMD_PUSCH0_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B07, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PUSCH1(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3C07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PUSCH1(v1, v2, v3, v4, v5, v6)
#endif
#define EL1TX_LOG_RT_CMD_PUSCH1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3C07, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v2), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PUSCH2(v1, v2, v3, v4) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3D07, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PUSCH2(v1, v2, v3, v4)
#endif
#define EL1TX_LOG_RT_CMD_PUSCH2_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3D07, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define EL1TX_LOG_RT_CMD_PUSCH3(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E07, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PUSCH3(v1, v2)
#endif
#define EL1TX_LOG_RT_CMD_PUSCH3_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E07, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PUCCH(v1, v2, v3, v4) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3F07, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PUCCH(v1, v2, v3, v4)
#endif
#define EL1TX_LOG_RT_CMD_PUCCH_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3F07, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PUCCH_CQI(v1, v2, v3, v4) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4007, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PUCCH_CQI(v1, v2, v3, v4)
#endif
#define EL1TX_LOG_RT_CMD_PUCCH_CQI_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4007, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PRACH0(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4107, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PRACH0(v1, v2, v3)
#endif
#define EL1TX_LOG_RT_CMD_PRACH0_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4107, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PRACH1(v1, v2, v3, v4) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4207, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PRACH1(v1, v2, v3, v4)
#endif
#define EL1TX_LOG_RT_CMD_PRACH1_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4207, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PUSCH_CQI(v1, v2, v3, v4) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4307, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PUSCH_CQI(v1, v2, v3, v4)
#endif
#define EL1TX_LOG_RT_CMD_PUSCH_CQI_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4307, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PUSCH_ACK(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4407, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PUSCH_ACK(v1, v2)
#endif
#define EL1TX_LOG_RT_CMD_PUSCH_ACK_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4407, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PUSCH_ACK_nBundle(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4507, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PUSCH_ACK_nBundle(v1, v2)
#endif
#define EL1TX_LOG_RT_CMD_PUSCH_ACK_nBundle_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4507, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PUSCH_ACK_Multiplex(v1, v2, v3, v4, v5) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4607, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PUSCH_ACK_Multiplex(v1, v2, v3, v4, v5)
#endif
#define EL1TX_LOG_RT_CMD_PUSCH_ACK_Multiplex_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4607, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PUCCH_ACK(v1, v2, v3, v4) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4707, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PUCCH_ACK(v1, v2, v3, v4)
#endif
#define EL1TX_LOG_RT_CMD_PUCCH_ACK_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4707, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_SRS_UCI(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4807, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_SRS_UCI(v1, v2, v3)
#endif
#define EL1TX_LOG_RT_CMD_SRS_UCI_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4807, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_PUSCH_ACK_RPT(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4907, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_PUSCH_ACK_RPT(v1, v2, v3)
#endif
#define EL1TX_LOG_PUSCH_ACK_RPT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4907, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_PUCCH_ACK_RPT(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4A07, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_PUCCH_ACK_RPT(v1, v2)
#endif
#define EL1TX_LOG_PUCCH_ACK_RPT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4A07, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_PUSCH_PRB_RPT(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B07, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_PUSCH_PRB_RPT(v1, v2)
#endif
#define EL1TX_LOG_PUSCH_PRB_RPT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B07, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_ACQI_INFO_RPT(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4C07, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_ACQI_INFO_RPT(v1, v2)
#endif
#define EL1TX_LOG_ACQI_INFO_RPT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4C07, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_ACQI_1_2_WB_RPT(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4D07, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_ACQI_1_2_WB_RPT(v1, v2, v3)
#endif
#define EL1TX_LOG_ACQI_1_2_WB_RPT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4D07, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_ACQI_1_2_PMI_RPT(v1, v2, v3, v4, v5) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4E07, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_ACQI_1_2_PMI_RPT(v1, v2, v3, v4, v5)
#endif
#define EL1TX_LOG_ACQI_1_2_PMI_RPT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4E07, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_ACQI_2_2_WB_RPT(v1, v2, v3, v4) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4F07, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_ACQI_2_2_WB_RPT(v1, v2, v3, v4)
#endif
#define EL1TX_LOG_ACQI_2_2_WB_RPT_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4F07, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_ACQI_2_2_UE_M_RPT(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5007, (char)(v2), (char)(v3)), (unsigned long)(v1));\
	} while(0)
#else
	#define EL1TX_LOG_ACQI_2_2_UE_M_RPT(v1, v2, v3)
#endif
#define EL1TX_LOG_ACQI_2_2_UE_M_RPT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5007, (char)(v2), (char)(v3)), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_ACQI_3_1_WB_RPT(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5107, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_ACQI_3_1_WB_RPT(v1, v2, v3)
#endif
#define EL1TX_LOG_ACQI_3_1_WB_RPT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5107, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_ACQI_3_1_SB_RPT(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5207, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define EL1TX_LOG_ACQI_3_1_SB_RPT(v1, v2, v3, v4, v5, v6)
#endif
#define EL1TX_LOG_ACQI_3_1_SB_RPT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5207, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_PCQI_INFO_RPT(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5307, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_PCQI_INFO_RPT(v1, v2)
#endif
#define EL1TX_LOG_PCQI_INFO_RPT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5307, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_PCQI_WB_RPT(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5407, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_PCQI_WB_RPT(v1, v2, v3)
#endif
#define EL1TX_LOG_PCQI_WB_RPT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5407, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_PCQI_SB_RPT(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5507, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_PCQI_SB_RPT(v1, v2, v3)
#endif
#define EL1TX_LOG_PCQI_SB_RPT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5507, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_DL_QUAL_CQI(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5607, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_DL_QUAL_CQI(v1, v2)
#endif
#define EL1TX_LOG_DL_QUAL_CQI_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5607, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_MPR_PWR(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5707, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_MPR_PWR(v1, v2, v3)
#endif
#define EL1TX_LOG_RT_CMD_MPR_PWR_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5707, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_UMPR_PWR(v1) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5807, (unsigned short)(v1)));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_UMPR_PWR(v1)
#endif
#define EL1TX_LOG_RT_CMD_UMPR_PWR_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5807, (unsigned short)(v1)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PL_PWR(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5907, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PL_PWR(v1, v2)
#endif
#define EL1TX_LOG_RT_CMD_PL_PWR_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5907, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PUSCH_PWR0(v1, v2, v3, v4, v5) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5A07, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PUSCH_PWR0(v1, v2, v3, v4, v5)
#endif
#define EL1TX_LOG_RT_CMD_PUSCH_PWR0_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5A07, (char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PUSCH_PWR1(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5B07, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PUSCH_PWR1(v1, v2, v3)
#endif
#define EL1TX_LOG_RT_CMD_PUSCH_PWR1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5B07, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PUSCH_PWR2(v1) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5C07, (short)(v1)));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PUSCH_PWR2(v1)
#endif
#define EL1TX_LOG_RT_CMD_PUSCH_PWR2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5C07, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PUCCH_PWR0(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5D07, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PUCCH_PWR0(v1, v2, v3)
#endif
#define EL1TX_LOG_RT_CMD_PUCCH_PWR0_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5D07, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PUCCH_PWR1(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5E07, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PUCCH_PWR1(v1, v2, v3)
#endif
#define EL1TX_LOG_RT_CMD_PUCCH_PWR1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5E07, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PUCCH_PWR2(v1) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5F07, (short)(v1)));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PUCCH_PWR2(v1)
#endif
#define EL1TX_LOG_RT_CMD_PUCCH_PWR2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5F07, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_PRACH_PWR(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6007, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_PRACH_PWR(v1, v2, v3)
#endif
#define EL1TX_LOG_RT_CMD_PRACH_PWR_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6007, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_SRS_PWR0(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6107, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_SRS_PWR0(v1, v2, v3, v4, v5, v6)
#endif
#define EL1TX_LOG_RT_CMD_SRS_PWR0_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6107, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((char)(v5), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RT_CMD_SRS_PWR2(v1) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x6207, (short)(v1)));\
	} while(0)
#else
	#define EL1TX_LOG_RT_CMD_SRS_PWR2(v1)
#endif
#define EL1TX_LOG_RT_CMD_SRS_PWR2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x6207, (short)(v1)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TPC_POWER_RPT(v1, v2, v3, v4, v5) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6307, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_TPC_POWER_RPT(v1, v2, v3, v4, v5)
#endif
#define EL1TX_LOG_TPC_POWER_RPT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6307, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TPC_PHR_RPT(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6407, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_TPC_PHR_RPT(v1, v2, v3)
#endif
#define EL1TX_LOG_TPC_PHR_RPT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6407, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_RX_QUAL_RPT(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6507, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_RX_QUAL_RPT(v1, v2, v3)
#endif
#define EL1TX_LOG_RX_QUAL_RPT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6507, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_UMPR_INFO0(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6607, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_UMPR_INFO0(v1, v2)
#endif
#define EL1TX_LOG_UMPR_INFO0_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6607, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_UMPR_INFO1(v1, v2, v3, v4) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6707, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_UMPR_INFO1(v1, v2, v3, v4)
#endif
#define EL1TX_LOG_UMPR_INFO1_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6707, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_STATUS(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6807, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_STATUS(v1, v2, v3)
#endif
#define EL1TX_LOG_TAS_STATUS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6807, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_NORMAL0(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6907, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_NORMAL0(v1, v2, v3)
#endif
#define EL1TX_LOG_TAS_NORMAL0_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6907, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_NORMAL1(v1, v2, v3, v4, v5) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6A07, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_NORMAL1(v1, v2, v3, v4, v5)
#endif
#define EL1TX_LOG_TAS_NORMAL1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6A07, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_PRE_SWITCH0(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6B07, (char)(v1), (char)(v2)), (long)(v3));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_PRE_SWITCH0(v1, v2, v3)
#endif
#define EL1TX_LOG_TAS_PRE_SWITCH0_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6B07, (char)(v1), (char)(v2)), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_PRE_SWITCH1(v1, v2, v3, v4) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6C07, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_PRE_SWITCH1(v1, v2, v3, v4)
#endif
#define EL1TX_LOG_TAS_PRE_SWITCH1_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6C07, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_PHI_STATUS(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6D07, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_PHI_STATUS(v1, v2)
#endif
#define EL1TX_LOG_TAS_PHI_STATUS_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6D07, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_PHI_STATUS1(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6E07, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_PHI_STATUS1(v1, v2)
#endif
#define EL1TX_LOG_TAS_PHI_STATUS1_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6E07, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_DB_STATUS(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6F07, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_DB_STATUS(v1, v2)
#endif
#define EL1TX_LOG_TAS_DB_STATUS_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6F07, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_FTC_STATUS(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7007, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_FTC_STATUS(v1, v2)
#endif
#define EL1TX_LOG_TAS_FTC_STATUS_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7007, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_CB_STATUS(v1, v2, v3, v4) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7107, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_CB_STATUS(v1, v2, v3, v4)
#endif
#define EL1TX_LOG_TAS_CB_STATUS_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7107, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_FORCE_TX(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7207, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_FORCE_TX(v1, v2)
#endif
#define EL1TX_LOG_TAS_FORCE_TX_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7207, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_FEATURE(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x7307, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_FEATURE(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EL1TX_LOG_TAS_FEATURE_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x7307, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_RSRP_DIFF_THD(v1, v2, v3, v4) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7407, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_RSRP_DIFF_THD(v1, v2, v3, v4)
#endif
#define EL1TX_LOG_TAS_RSRP_DIFF_THD_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7407, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_CB_THD(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7507, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_CB_THD(v1, v2, v3)
#endif
#define EL1TX_LOG_TAS_CB_THD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7507, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_TPC_HTP_THD(v1, v2) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7607, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_TPC_HTP_THD(v1, v2)
#endif
#define EL1TX_LOG_TAS_TPC_HTP_THD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7607, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_TPC_SB_THD(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7707, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_TPC_SB_THD(v1, v2, v3)
#endif
#define EL1TX_LOG_TAS_TPC_SB_THD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7707, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_PHI_INFO(v1, v2, v3, v4) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7807, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_PHI_INFO(v1, v2, v3, v4)
#endif
#define EL1TX_LOG_TAS_PHI_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7807, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_DB_INFO0(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7907, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_DB_INFO0(v1, v2, v3)
#endif
#define EL1TX_LOG_TAS_DB_INFO0_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x7907, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1TX_LOG_TAS_DB_INFO1(v1, v2, v3) do {\
		if(EL1_TX_1_Trace_Filter[0]==1 && (EL1_TX_1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7A07, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1TX_LOG_TAS_DB_INFO1(v1, v2, v3)
#endif
#define EL1TX_LOG_TAS_DB_INFO1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7A07, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1_TX_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1TX_LOG_RRC_SYS0(unsigned char v1, unsigned short v2, unsigned short v3, unsigned char v4);
void L1TRC_Send_EL1TX_LOG_RRC_SYS1(unsigned char v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_EL1TX_LOG_RRC_SYS2(unsigned char v1, unsigned char v2, char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1TX_LOG_RRC_PRACH0(unsigned short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1TX_LOG_RRC_PRACH(char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1TX_LOG_RRC_PUCCH(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1TX_LOG_RRC_PUSCH(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1TX_LOG_RRC_SPS_UL(unsigned char v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_EL1TX_LOG_RRC_SPS_DL(unsigned char v1, unsigned short v2);
void L1TRC_Send_EL1TX_LOG_RRC_CQI0(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1TX_LOG_RRC_CQI1(unsigned char v1, char v2);
void L1TRC_Send_EL1TX_LOG_RRC_SRS0(unsigned char v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_EL1TX_LOG_RRC_SRS1(unsigned char v1, unsigned char v2, unsigned short v3, short v4, short v5);
void L1TRC_Send_EL1TX_LOG_RRC_SRS2(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1TX_LOG_RRC_PCMAX(char v1, char v2, char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1TX_LOG_RAR_GRANT(unsigned char v1, unsigned char v2, char v3);
void L1TRC_Send_EL1TX_LOG_RAR_MATCH(char v1, char v2, char v3);
void L1TRC_Send_EL1TX_LOG_PRACH_INFO(char v1, char v2, char v3);
void L1TRC_Send_EL1TX_LOG_TA_INFO(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1TX_LOG_TXPWR_FI(char v1, char v2);
void L1TRC_Send_EL1TX_LOG_TXPWR_GI(char v1, char v2, unsigned char v3);
void L1TRC_Send_EL1TX_LOG_GAP(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EL1TX_LOG_DL_PDCCH_INFO(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1TX_LOG_UL_PDCCH_INFO(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1TX_LOG_UL_GRANT_PROC(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned short v5, char v6, unsigned char v7, char v8);
void L1TRC_Send_EL1TX_LOG_DL_ASSIGN_PROC(unsigned char v1, unsigned char v2, char v3, char v4, char v5, char v6, unsigned char v7, char v8, char v9);
void L1TRC_Send_EL1TX_LOG_DL_PDSCH_CRC(unsigned char v1, unsigned short v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1TX_LOG_DL_PDSCH_TBS(unsigned short v1, unsigned short v2);
void L1TRC_Send_EL1TX_LOG_PHICH(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1TX_LOG_PDCCH_ORDER(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1TX_LOG_CR_INFO(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1TX_LOG_CR_RCV_TIME(unsigned short v1, unsigned char v2);
void L1TRC_Send_EL1TX_LOG_CR_ACK_TIME(unsigned short v1, unsigned char v2);
void L1TRC_Send_EL1TX_LOG_CTRL_SGNL(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1TX_LOG_ACK_REP_CNT(unsigned char v1);
void L1TRC_Send_EL1TX_LOG_CRNTI(unsigned short v1);
void L1TRC_Send_EL1TX_LOG_DRX_PUCCH_INFO(unsigned short v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1TX_LOG_DL_UL_INFO(unsigned char v1, unsigned char v2, unsigned short v3, unsigned long v4, unsigned char v5);
void L1TRC_Send_EL1TX_LOG_MCS_INFO(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1TX_LOG_RX0_INFO(unsigned char v1, char v2, char v3);
void L1TRC_Send_EL1TX_LOG_PWR0_INFO(char v1, char v2, char v3, char v4);
void L1TRC_Send_EL1TX_LOG_PWR1_INFO(short v1, short v2, unsigned char v3, char v4, unsigned short v5);
void L1TRC_Send_EL1TX_LOG_FLOW(unsigned char v1);
void L1TRC_Send_EL1TX_LOG_FLOW2(unsigned char v1, short v2);
void L1TRC_Send_EL1TX_LOG_FLOW_TIME_LV(unsigned long v1);
void L1TRC_Send_EL1TX_LOG_DCI0_FALSE_ALARM(unsigned short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1TX_LOG_DCI_WARNING(unsigned char v1);
void L1TRC_Send_EL1TX_LOG_RPT_TIME_ERR(unsigned char v1, unsigned short v2, unsigned char v3);
void L1TRC_Send_EL1TX_LOG_FUNC_CALL(unsigned char v1);
void L1TRC_Send_EL1TX_LOG_MSG_SND(unsigned char v1);
void L1TRC_Send_EL1TX_LOG_MSG_RCV(unsigned char v1);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PHICH_ENQUEUE(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1TX_LOG_NRT_CMD_PHICH_DECODE(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1TX_LOG_NRT_CMD_PDSCH_OPT(unsigned short v1, unsigned short v2);
void L1TRC_Send_EL1TX_LOG_RT_CMD_Tx_Enbl(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1TX_LOG_RT_CMD_Tx_Enbl1(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_EL1TX_LOG_RT_CMD_Tx_Enbl2(unsigned char v1, unsigned char v2);
void L1TRC_Send_El1TX_LOG_RT_CMD_Tx_time(unsigned short v1, unsigned char v2);
void L1TRC_Send_EL1TX_LOG_RT_CMD_Rx_time(unsigned short v1, unsigned char v2);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PUSCH0(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PUSCH1(unsigned short v1, unsigned char v2, unsigned char v3, unsigned short v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PUSCH2(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PUSCH3(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PUCCH(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PUCCH_CQI(unsigned char v1, unsigned short v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PRACH0(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PRACH1(short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PUSCH_CQI(unsigned char v1, unsigned short v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PUSCH_ACK(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PUSCH_ACK_nBundle(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PUSCH_ACK_Multiplex(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PUCCH_ACK(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_EL1TX_LOG_RT_CMD_SRS_UCI(unsigned char v1, char v2, char v3);
void L1TRC_Send_EL1TX_LOG_PUSCH_ACK_RPT(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1TX_LOG_PUCCH_ACK_RPT(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1TX_LOG_PUSCH_PRB_RPT(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1TX_LOG_ACQI_INFO_RPT(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1TX_LOG_ACQI_1_2_WB_RPT(unsigned char v1, char v2, unsigned char v3);
void L1TRC_Send_EL1TX_LOG_ACQI_1_2_PMI_RPT(char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_EL1TX_LOG_ACQI_2_2_WB_RPT(char v1, unsigned char v2, char v3, unsigned char v4);
void L1TRC_Send_EL1TX_LOG_ACQI_2_2_UE_M_RPT(unsigned long v1, char v2, char v3);
void L1TRC_Send_EL1TX_LOG_ACQI_3_1_WB_RPT(char v1, char v2, unsigned char v3);
void L1TRC_Send_EL1TX_LOG_ACQI_3_1_SB_RPT(char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_EL1TX_LOG_PCQI_INFO_RPT(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1TX_LOG_PCQI_WB_RPT(unsigned char v1, unsigned char v2, char v3);
void L1TRC_Send_EL1TX_LOG_PCQI_SB_RPT(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_EL1TX_LOG_DL_QUAL_CQI(unsigned char v1, unsigned char v2);
void L1TRC_Send_EL1TX_LOG_RT_CMD_MPR_PWR(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_EL1TX_LOG_RT_CMD_UMPR_PWR(unsigned short v1);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PL_PWR(char v1, short v2);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PUSCH_PWR0(char v1, char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PUSCH_PWR1(unsigned char v1, char v2, short v3);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PUSCH_PWR2(short v1);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PUCCH_PWR0(char v1, char v2, char v3);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PUCCH_PWR1(unsigned char v1, char v2, short v3);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PUCCH_PWR2(short v1);
void L1TRC_Send_EL1TX_LOG_RT_CMD_PRACH_PWR(unsigned char v1, char v2, short v3);
void L1TRC_Send_EL1TX_LOG_RT_CMD_SRS_PWR0(short v1, short v2, unsigned char v3, unsigned char v4, char v5, unsigned char v6);
void L1TRC_Send_EL1TX_LOG_RT_CMD_SRS_PWR2(short v1);
void L1TRC_Send_EL1TX_LOG_TPC_POWER_RPT(unsigned char v1, unsigned char v2, char v3, char v4, char v5);
void L1TRC_Send_EL1TX_LOG_TPC_PHR_RPT(unsigned char v1, char v2, unsigned char v3);
void L1TRC_Send_EL1TX_LOG_RX_QUAL_RPT(unsigned char v1, short v2, short v3);
void L1TRC_Send_EL1TX_LOG_UMPR_INFO0(unsigned char v1, char v2);
void L1TRC_Send_EL1TX_LOG_UMPR_INFO1(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_EL1TX_LOG_TAS_STATUS(unsigned char v1, unsigned char v2, long v3);
void L1TRC_Send_EL1TX_LOG_TAS_NORMAL0(char v1, char v2, char v3);
void L1TRC_Send_EL1TX_LOG_TAS_NORMAL1(char v1, char v2, char v3, char v4, char v5);
void L1TRC_Send_EL1TX_LOG_TAS_PRE_SWITCH0(char v1, char v2, long v3);
void L1TRC_Send_EL1TX_LOG_TAS_PRE_SWITCH1(char v1, char v2, char v3, char v4);
void L1TRC_Send_EL1TX_LOG_TAS_PHI_STATUS(char v1, char v2);
void L1TRC_Send_EL1TX_LOG_TAS_PHI_STATUS1(char v1, char v2);
void L1TRC_Send_EL1TX_LOG_TAS_DB_STATUS(char v1, char v2);
void L1TRC_Send_EL1TX_LOG_TAS_FTC_STATUS(char v1, char v2);
void L1TRC_Send_EL1TX_LOG_TAS_CB_STATUS(char v1, char v2, char v3, char v4);
void L1TRC_Send_EL1TX_LOG_TAS_FORCE_TX(char v1, char v2);
void L1TRC_Send_EL1TX_LOG_TAS_FEATURE(char v1, char v2, char v3, char v4, char v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_EL1TX_LOG_TAS_RSRP_DIFF_THD(char v1, char v2, char v3, unsigned char v4);
void L1TRC_Send_EL1TX_LOG_TAS_CB_THD(char v1, char v2, short v3);
void L1TRC_Send_EL1TX_LOG_TAS_TPC_HTP_THD(char v1, short v2);
void L1TRC_Send_EL1TX_LOG_TAS_TPC_SB_THD(char v1, char v2, short v3);
void L1TRC_Send_EL1TX_LOG_TAS_PHI_INFO(char v1, char v2, char v3, short v4);
void L1TRC_Send_EL1TX_LOG_TAS_DB_INFO0(char v1, char v2, char v3);
void L1TRC_Send_EL1TX_LOG_TAS_DB_INFO1(char v1, char v2, short v3);

void Set_EL1_TX_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1_TX_1()	(EL1_TX_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_trace_H()	(ChkL1ModFltr_EL1_TX_1()&&((EL1_TX_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_trace_M()	(ChkL1ModFltr_EL1_TX_1()&&((EL1_TX_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_ACK_trace_H()	(ChkL1ModFltr_EL1_TX_1()&&((EL1_TX_1_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_CQI_trace_H()	(ChkL1ModFltr_EL1_TX_1()&&((EL1_TX_1_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_PWR_trace_H()	(ChkL1ModFltr_EL1_TX_1()&&((EL1_TX_1_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1_TX_1_tx_func_trace_H()	(ChkL1ModFltr_EL1_TX_1()&&((EL1_TX_1_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1_TX_1_tx_flow_trace_H()	(ChkL1ModFltr_EL1_TX_1()&&((EL1_TX_1_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1_TX_1_tx_time_trace_M()	(ChkL1ModFltr_EL1_TX_1()&&((EL1_TX_1_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1_TX_1_tx_msg_trace_H()	(ChkL1ModFltr_EL1_TX_1()&&((EL1_TX_1_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()	(ChkL1ModFltr_EL1_TX_1()&&((EL1_TX_1_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_M()	(ChkL1ModFltr_EL1_TX_1()&&((EL1_TX_1_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1_TX_1_tx_warning_trace_H()	(ChkL1ModFltr_EL1_TX_1()&&((EL1_TX_1_Trace_Filter[2]&0x08)!=0))
#define ChkL1MsgFltr_EL1TX_LOG_RRC_SYS0()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RRC_SYS1()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RRC_SYS2()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RRC_PRACH0()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RRC_PRACH()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RRC_PUCCH()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RRC_PUSCH()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RRC_SPS_UL()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RRC_SPS_DL()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RRC_CQI0()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RRC_CQI1()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RRC_SRS0()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RRC_SRS1()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RRC_SRS2()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RRC_PCMAX()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RAR_GRANT()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RAR_MATCH()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_PRACH_INFO()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TA_INFO()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TXPWR_FI()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_M()
#define ChkL1MsgFltr_EL1TX_LOG_TXPWR_GI()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_M()
#define ChkL1MsgFltr_EL1TX_LOG_GAP()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_DL_PDCCH_INFO()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_UL_PDCCH_INFO()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_UL_GRANT_PROC()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_DL_ASSIGN_PROC()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_DL_PDSCH_CRC()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_DL_PDSCH_TBS()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_PHICH()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_PDCCH_ORDER()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_CR_INFO()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_CR_RCV_TIME()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_CR_ACK_TIME()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_CTRL_SGNL()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_ACK_REP_CNT()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_CRNTI()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_DRX_PUCCH_INFO()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_DL_UL_INFO()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_MCS_INFO()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RX0_INFO()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_PWR0_INFO()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_PWR1_INFO()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_FLOW()	ChkL1ClsFltr_EL1_TX_1_tx_flow_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_FLOW2()	ChkL1ClsFltr_EL1_TX_1_tx_flow_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_FLOW_TIME_LV()	ChkL1ClsFltr_EL1_TX_1_tx_time_trace_M()
#define ChkL1MsgFltr_EL1TX_LOG_DCI0_FALSE_ALARM()	ChkL1ClsFltr_EL1_TX_1_tx_warning_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_DCI_WARNING()	ChkL1ClsFltr_EL1_TX_1_tx_warning_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RPT_TIME_ERR()	ChkL1ClsFltr_EL1_TX_1_tx_warning_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_FUNC_CALL()	ChkL1ClsFltr_EL1_TX_1_tx_func_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_MSG_SND()	ChkL1ClsFltr_EL1_TX_1_tx_msg_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_MSG_RCV()	ChkL1ClsFltr_EL1_TX_1_tx_msg_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PHICH_ENQUEUE()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_trace_M()
#define ChkL1MsgFltr_EL1TX_LOG_NRT_CMD_PHICH_DECODE()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_NRT_CMD_PDSCH_OPT()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_Tx_Enbl()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_Tx_Enbl1()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_Tx_Enbl2()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_trace_H()
#define ChkL1MsgFltr_El1TX_LOG_RT_CMD_Tx_time()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_Rx_time()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_trace_M()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PUSCH0()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PUSCH1()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PUSCH2()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PUSCH3()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_trace_M()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PUCCH()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PUCCH_CQI()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_CQI_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PRACH0()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PRACH1()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PUSCH_CQI()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_CQI_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PUSCH_ACK()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_ACK_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PUSCH_ACK_nBundle()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_ACK_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PUSCH_ACK_Multiplex()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_ACK_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PUCCH_ACK()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_ACK_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_SRS_UCI()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_ACK_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_PUSCH_ACK_RPT()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_ACK_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_PUCCH_ACK_RPT()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_ACK_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_PUSCH_PRB_RPT()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_ACQI_INFO_RPT()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_CQI_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_ACQI_1_2_WB_RPT()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_CQI_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_ACQI_1_2_PMI_RPT()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_CQI_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_ACQI_2_2_WB_RPT()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_CQI_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_ACQI_2_2_UE_M_RPT()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_CQI_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_ACQI_3_1_WB_RPT()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_CQI_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_ACQI_3_1_SB_RPT()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_CQI_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_PCQI_INFO_RPT()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_CQI_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_PCQI_WB_RPT()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_CQI_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_PCQI_SB_RPT()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_CQI_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_DL_QUAL_CQI()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_CQI_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_MPR_PWR()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_PWR_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_UMPR_PWR()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_PWR_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PL_PWR()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_PWR_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PUSCH_PWR0()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_PWR_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PUSCH_PWR1()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_PWR_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PUSCH_PWR2()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_PWR_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PUCCH_PWR0()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_PWR_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PUCCH_PWR1()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_PWR_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PUCCH_PWR2()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_PWR_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_PRACH_PWR()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_PWR_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_SRS_PWR0()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_PWR_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RT_CMD_SRS_PWR2()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_PWR_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TPC_POWER_RPT()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_PWR_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TPC_PHR_RPT()	ChkL1ClsFltr_EL1_TX_1_tx_trig_cmd_PWR_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_RX_QUAL_RPT()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_UMPR_INFO0()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_UMPR_INFO1()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_STATUS()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_NORMAL0()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_NORMAL1()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_PRE_SWITCH0()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_PRE_SWITCH1()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_PHI_STATUS()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_PHI_STATUS1()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_DB_STATUS()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_FTC_STATUS()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_CB_STATUS()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_FORCE_TX()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_FEATURE()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_RSRP_DIFF_THD()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_CB_THD()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_TPC_HTP_THD()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_TPC_SB_THD()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_PHI_INFO()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_DB_INFO0()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()
#define ChkL1MsgFltr_EL1TX_LOG_TAS_DB_INFO1()	ChkL1ClsFltr_EL1_TX_1_tx_internal_info_trace_H()


#endif
