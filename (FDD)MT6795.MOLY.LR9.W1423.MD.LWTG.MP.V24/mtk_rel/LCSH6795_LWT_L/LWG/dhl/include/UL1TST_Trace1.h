#ifndef L1TRC_UL1TST_PRI1_DEF_H
#define L1TRC_UL1TST_PRI1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1TST_Trc_LISTMODE_State(v1)  (unsigned char)(v1+0)
#define UL1TST_Trc_NSFT_State(v1)  (unsigned char)(v1+10)
#define UL1TST_Trc_PRACH_CS_State(v1)  (unsigned char)(v1+27)
#define UL1TST_Trc_NSFT_DCH_DbgStr(v1)  (unsigned char)(v1+36)
#define UL1TST_Trc_NSFT_HSDSCH_EDCH_DbgStr(v1)  (unsigned char)(v1+44)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1TST_TRC_TxAccess(v1, v2, v3, v4) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x003C, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1TST_TRC_TxAccess(v1, v2, v3, v4)
#endif
#define UL1TST_TRC_TxAccess_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x003C, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1TST_TRC_NSFT_State(v1, v2) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x013C, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1TST_TRC_NSFT_State(v1, v2)
#endif
#define UL1TST_TRC_NSFT_State_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x013C, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1TST_TRC_NSFT_ILPCSETSTEP(v1, v2) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x023C, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1TST_TRC_NSFT_ILPCSETSTEP(v1, v2)
#endif
#define UL1TST_TRC_NSFT_ILPCSETSTEP_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x023C, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1TST_TRC_NSFT_TPCRECONFIG(v1, v2) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x033C, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1TST_TRC_NSFT_TPCRECONFIG(v1, v2)
#endif
#define UL1TST_TRC_NSFT_TPCRECONFIG_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x033C, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1TST_TRC_PRACH_State(v1) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x043C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1TST_TRC_PRACH_State(v1)
#endif
#define UL1TST_TRC_PRACH_State_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x043C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1TST_TRC_PRACH_TxAccess(v1, v2, v3, v4, v5) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x053C, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v5), TRC_BOXSTER_PAD), (long)(v1), (long)(v4));\
	} while(0)
#else
	#define UL1TST_TRC_PRACH_TxAccess(v1, v2, v3, v4, v5)
#endif
#define UL1TST_TRC_PRACH_TxAccess_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x053C, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v5), TRC_BOXSTER_PAD), (long)(v1), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1TST_TRC_PRACH_FS_PSCLIST(v1, v2) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x063C, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1TST_TRC_PRACH_FS_PSCLIST(v1, v2)
#endif
#define UL1TST_TRC_PRACH_FS_PSCLIST_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x063C, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1TST_TRC_NSFT_SFNStart_Info(v1, v2, v3) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x073C, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1TST_TRC_NSFT_SFNStart_Info(v1, v2, v3)
#endif
#define UL1TST_TRC_NSFT_SFNStart_Info_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x073C, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1TST_TRC_NSFT_DCH_DBG(v1, v2, v3) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x083C, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1TST_TRC_NSFT_DCH_DBG(v1, v2, v3)
#endif
#define UL1TST_TRC_NSFT_DCH_DBG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x083C, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1TST_TRC_NSFT_HSDSCH_EDCH_DBG(v1, v2, v3) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x093C, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1TST_TRC_NSFT_HSDSCH_EDCH_DBG(v1, v2, v3)
#endif
#define UL1TST_TRC_NSFT_HSDSCH_EDCH_DBG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x093C, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1TST_TRC_NSFT_SFN_REPORT_STATE(v1) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A3C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1TST_TRC_NSFT_SFN_REPORT_STATE(v1)
#endif
#define UL1TST_TRC_NSFT_SFN_REPORT_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A3C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1TST_TRC_PRACH_SFN_REPORT_STATE(v1) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B3C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1TST_TRC_PRACH_SFN_REPORT_STATE(v1)
#endif
#define UL1TST_TRC_PRACH_SFN_REPORT_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B3C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_Trc_TPC_result_ans_ptar_p(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0C3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_Trc_TPC_result_ans_ptar_p(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_Trc_TPC_result_ans_ptar_p_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0C3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_Trc_TPC_result_ans_ptar_q(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0D3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_Trc_TPC_result_ans_ptar_q(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_Trc_TPC_result_ans_ptar_q_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0D3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_Trc_TPC_result_ptar_p(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0E3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)));\
	} while(0)
#else
	#define UL1D_Trc_TPC_result_ptar_p(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_Trc_TPC_result_ptar_p_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0E3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_Trc_TPC_result_ptar_q(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0F3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)));\
	} while(0)
#else
	#define UL1D_Trc_TPC_result_ptar_q(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_Trc_TPC_result_ptar_q_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0F3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_Trc_TPC_result_tpc_cmd(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x103C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_Trc_TPC_result_tpc_cmd(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_Trc_TPC_result_tpc_cmd_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x103C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_Trc_TPC_result_pseudo_hscch(v1, v2, v3, v4, v5, v6) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x113C, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_Trc_TPC_result_pseudo_hscch(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_Trc_TPC_result_pseudo_hscch_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x113C, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_Trc_TPC_result_pseudo_hdsch(v1, v2, v3, v4, v5, v6) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x123C, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_Trc_TPC_result_pseudo_hdsch(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_Trc_TPC_result_pseudo_hdsch_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x123C, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_Trc_TPC_result_beta_hs_p(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x133C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_Trc_TPC_result_beta_hs_p(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_Trc_TPC_result_beta_hs_p_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x133C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_Trc_TPC_result_beta_hs_q(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x143C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_Trc_TPC_result_beta_hs_q(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_Trc_TPC_result_beta_hs_q_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x143C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_Trc_TPC_result_beta_c(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x153C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_Trc_TPC_result_beta_c(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_Trc_TPC_result_beta_c_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x153C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_Trc_TPC_result_beta_d(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x163C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_Trc_TPC_result_beta_d(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_Trc_TPC_result_beta_d_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x163C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_Trc_TPC_result_beta_ec(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x173C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_Trc_TPC_result_beta_ec(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_Trc_TPC_result_beta_ec_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x173C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_Trc_TPC_result_beta_ed0(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x183C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_Trc_TPC_result_beta_ed0(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_Trc_TPC_result_beta_ed0_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x183C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_Trc_TPC_result_beta_ed1(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x193C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_Trc_TPC_result_beta_ed1(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_Trc_TPC_result_beta_ed1_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x193C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_Trc_TPC_result_beta_ed2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1A3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_Trc_TPC_result_beta_ed2(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_Trc_TPC_result_beta_ed2_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1A3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_Trc_TPC_result_beta_ed3(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1B3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_Trc_TPC_result_beta_ed3(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_Trc_TPC_result_beta_ed3_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1B3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_Trc_TPC_result_upc_slot(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1C3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_Trc_TPC_result_upc_slot(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_Trc_TPC_result_upc_slot_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1C3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_1S2C((short)(v16), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_Trc_TPC_final_result(v1) do {\
		if(UL1TST_PRI1_Trace_Filter[0]==1 && (UL1TST_PRI1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D3C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_Trc_TPC_final_result(v1)
#endif
#define UL1D_Trc_TPC_final_result_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D3C, (unsigned char)(v1), TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1TST_PRI1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1TST_TRC_TxAccess(char v1, long v2, char v3, short v4);
void L1TRC_Send_UL1TST_TRC_NSFT_State(unsigned char v1, short v2);
void L1TRC_Send_UL1TST_TRC_NSFT_ILPCSETSTEP(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1TST_TRC_NSFT_TPCRECONFIG(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1TST_TRC_PRACH_State(unsigned char v1);
void L1TRC_Send_UL1TST_TRC_PRACH_TxAccess(long v1, unsigned short v2, unsigned short v3, long v4, unsigned char v5);
void L1TRC_Send_UL1TST_TRC_PRACH_FS_PSCLIST(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1TST_TRC_NSFT_SFNStart_Info(unsigned short v1, unsigned short v2, long v3);
void L1TRC_Send_UL1TST_TRC_NSFT_DCH_DBG(unsigned char v1, short v2, char v3);
void L1TRC_Send_UL1TST_TRC_NSFT_HSDSCH_EDCH_DBG(unsigned char v1, short v2, char v3);
void L1TRC_Send_UL1TST_TRC_NSFT_SFN_REPORT_STATE(unsigned char v1);
void L1TRC_Send_UL1TST_TRC_PRACH_SFN_REPORT_STATE(unsigned char v1);
void L1TRC_Send_UL1D_Trc_TPC_result_ans_ptar_p(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_Trc_TPC_result_ans_ptar_q(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_Trc_TPC_result_ptar_p(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17);
void L1TRC_Send_UL1D_Trc_TPC_result_ptar_q(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17);
void L1TRC_Send_UL1D_Trc_TPC_result_tpc_cmd(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_Trc_TPC_result_pseudo_hscch(short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_UL1D_Trc_TPC_result_pseudo_hdsch(short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_UL1D_Trc_TPC_result_beta_hs_p(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_Trc_TPC_result_beta_hs_q(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_Trc_TPC_result_beta_c(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_Trc_TPC_result_beta_d(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_Trc_TPC_result_beta_ec(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_Trc_TPC_result_beta_ed0(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_Trc_TPC_result_beta_ed1(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_Trc_TPC_result_beta_ed2(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_Trc_TPC_result_beta_ed3(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_Trc_TPC_result_upc_slot(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_Trc_TPC_final_result(unsigned char v1);

void Set_UL1TST_PRI1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1TST_PRI1()	(UL1TST_PRI1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1TST_PRI1_UL1TST_Debug_M()	(ChkL1ModFltr_UL1TST_PRI1()&&((UL1TST_PRI1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()	(ChkL1ModFltr_UL1TST_PRI1()&&((UL1TST_PRI1_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_UL1TST_TRC_TxAccess()	ChkL1ClsFltr_UL1TST_PRI1_UL1TST_Debug_M()
#define ChkL1MsgFltr_UL1TST_TRC_NSFT_State()	ChkL1ClsFltr_UL1TST_PRI1_UL1TST_Debug_M()
#define ChkL1MsgFltr_UL1TST_TRC_NSFT_ILPCSETSTEP()	ChkL1ClsFltr_UL1TST_PRI1_UL1TST_Debug_M()
#define ChkL1MsgFltr_UL1TST_TRC_NSFT_TPCRECONFIG()	ChkL1ClsFltr_UL1TST_PRI1_UL1TST_Debug_M()
#define ChkL1MsgFltr_UL1TST_TRC_PRACH_State()	ChkL1ClsFltr_UL1TST_PRI1_UL1TST_Debug_M()
#define ChkL1MsgFltr_UL1TST_TRC_PRACH_TxAccess()	ChkL1ClsFltr_UL1TST_PRI1_UL1TST_Debug_M()
#define ChkL1MsgFltr_UL1TST_TRC_PRACH_FS_PSCLIST()	ChkL1ClsFltr_UL1TST_PRI1_UL1TST_Debug_M()
#define ChkL1MsgFltr_UL1TST_TRC_NSFT_SFNStart_Info()	ChkL1ClsFltr_UL1TST_PRI1_UL1TST_Debug_M()
#define ChkL1MsgFltr_UL1TST_TRC_NSFT_DCH_DBG()	ChkL1ClsFltr_UL1TST_PRI1_UL1TST_Debug_M()
#define ChkL1MsgFltr_UL1TST_TRC_NSFT_HSDSCH_EDCH_DBG()	ChkL1ClsFltr_UL1TST_PRI1_UL1TST_Debug_M()
#define ChkL1MsgFltr_UL1TST_TRC_NSFT_SFN_REPORT_STATE()	ChkL1ClsFltr_UL1TST_PRI1_UL1TST_Debug_M()
#define ChkL1MsgFltr_UL1TST_TRC_PRACH_SFN_REPORT_STATE()	ChkL1ClsFltr_UL1TST_PRI1_UL1TST_Debug_M()
#define ChkL1MsgFltr_UL1D_Trc_TPC_result_ans_ptar_p()	ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()
#define ChkL1MsgFltr_UL1D_Trc_TPC_result_ans_ptar_q()	ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()
#define ChkL1MsgFltr_UL1D_Trc_TPC_result_ptar_p()	ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()
#define ChkL1MsgFltr_UL1D_Trc_TPC_result_ptar_q()	ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()
#define ChkL1MsgFltr_UL1D_Trc_TPC_result_tpc_cmd()	ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()
#define ChkL1MsgFltr_UL1D_Trc_TPC_result_pseudo_hscch()	ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()
#define ChkL1MsgFltr_UL1D_Trc_TPC_result_pseudo_hdsch()	ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()
#define ChkL1MsgFltr_UL1D_Trc_TPC_result_beta_hs_p()	ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()
#define ChkL1MsgFltr_UL1D_Trc_TPC_result_beta_hs_q()	ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()
#define ChkL1MsgFltr_UL1D_Trc_TPC_result_beta_c()	ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()
#define ChkL1MsgFltr_UL1D_Trc_TPC_result_beta_d()	ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()
#define ChkL1MsgFltr_UL1D_Trc_TPC_result_beta_ec()	ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()
#define ChkL1MsgFltr_UL1D_Trc_TPC_result_beta_ed0()	ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()
#define ChkL1MsgFltr_UL1D_Trc_TPC_result_beta_ed1()	ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()
#define ChkL1MsgFltr_UL1D_Trc_TPC_result_beta_ed2()	ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()
#define ChkL1MsgFltr_UL1D_Trc_TPC_result_beta_ed3()	ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()
#define ChkL1MsgFltr_UL1D_Trc_TPC_result_upc_slot()	ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()
#define ChkL1MsgFltr_UL1D_Trc_TPC_final_result()	ChkL1ClsFltr_UL1TST_PRI1_HWTPC_TEST_M()


#endif
