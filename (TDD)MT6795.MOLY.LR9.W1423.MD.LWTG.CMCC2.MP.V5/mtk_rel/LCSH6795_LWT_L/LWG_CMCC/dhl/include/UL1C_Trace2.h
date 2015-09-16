#ifndef L1TRC_UL1C_PRI2_DEF_H
#define L1TRC_UL1C_PRI2_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_Start(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0038, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), (long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_Start(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CTCH_Start_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0038, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_Next_L1(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0138, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_Next_L1(v1, v2, v3)
#endif
#define UL1I_TRC_CTCH_Next_L1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0138, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_BS_Start(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0238, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_BS_Start(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_CTCH_BS_Start_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0238, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_Rx_Status(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0338, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_Rx_Status(v1, v2)
#endif
#define UL1I_TRC_CTCH_Rx_Status_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0338, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_L2_BP(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0438, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_L2_BP(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CTCH_L2_BP_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0438, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Timer(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0538, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Timer(v1, v2, v3)
#endif
#define UL1I_TRC_Timer_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0538, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_LeaveConfig(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0638, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_LeaveConfig(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1I_TRC_LeaveConfig_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0638, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EnterConfig(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0738, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1I_TRC_EnterConfig(v1, v2, v3)
#endif
#define UL1I_TRC_EnterConfig_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0738, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_AbortConfig(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0838, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_AbortConfig(v1)
#endif
#define UL1I_TRC_AbortConfig_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0838, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SuspendCNF(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0938, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SuspendCNF(v1, v2, v3)
#endif
#define UL1I_TRC_SuspendCNF_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0938, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_BCH_CCM_SIB_STATUS(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A38, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_BCH_CCM_SIB_STATUS(v1, v2)
#endif
#define UL1I_TRC_BCH_CCM_SIB_STATUS_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A38, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_BCH_CCM_SFN_STATUS(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B38, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_BCH_CCM_SFN_STATUS(v1, v2)
#endif
#define UL1I_TRC_BCH_CCM_SFN_STATUS_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B38, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EnterMode(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C38, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_EnterMode(v1)
#endif
#define UL1I_TRC_EnterMode_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C38, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EnterDCH(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0D38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_1S2C((short)(v10), (char)(v3), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_EnterDCH(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define UL1I_TRC_EnterDCH_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0D38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_1S2C((short)(v10), (char)(v3), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EnterPCH(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0E38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_EnterPCH(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_EnterPCH_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0E38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EnterFACH(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0F38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_EnterFACH(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_EnterFACH_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0F38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EnterNull(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1038, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_EnterNull(v1, v2, v3)
#endif
#define UL1I_TRC_EnterNull_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1038, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CCM_SetFN(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1138, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_CCM_SetFN(v1)
#endif
#define UL1I_TRC_CCM_SetFN_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1138, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_StartDLDCH(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1238, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_StartDLDCH(v1, v2)
#endif
#define UL1I_TRC_StartDLDCH_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1238, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TTI(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1338, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TTI(v1, v2)
#endif
#define UL1I_TRC_TTI_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1338, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CCM_State(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1438, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CCM_State(v1)
#endif
#define UL1I_TRC_CCM_State_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1438, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SFN_Stop() do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1538, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_SFN_Stop()
#endif
#define UL1T_TRC_SFN_Stop_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1538, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SFN_Start(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1638, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1T_TRC_SFN_Start(v1, v2, v3)
#endif
#define UL1T_TRC_SFN_Start_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1638, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_Rx(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1738, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_Rx(v1, v2)
#endif
#define UL1I_TRC_SFN_Rx_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1738, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_State(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1838, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_State(v1)
#endif
#define UL1I_TRC_SFN_State_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1838, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SFN_Data(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1938, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_SFN_Data(v1, v2)
#endif
#define UL1T_TRC_SFN_Data_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1938, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_Report(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A38, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_Report(v1, v2, v3)
#endif
#define UL1I_TRC_SFN_Report_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A38, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_InternalStop(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B38, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_InternalStop(v1, v2, v3, v4)
#endif
#define UL1I_TRC_SFN_InternalStop_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B38, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_Compensation(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C38, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_Compensation(v1)
#endif
#define UL1I_TRC_SFN_Compensation_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C38, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_Avail_Dec_Frms(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1D38, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_SFN_Avail_Dec_Frms(v1)
#endif
#define UL1I_TRC_SFN_Avail_Dec_Frms_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1D38, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_AdjustProtectPriority(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E38, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_AdjustProtectPriority(v1)
#endif
#define UL1I_TRC_SFN_AdjustProtectPriority_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E38, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_ReStart(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F38, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SFN_ReStart(v1, v2)
#endif
#define UL1I_TRC_SFN_ReStart_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F38, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_CMResult(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2038, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1I_TRC_SFN_CMResult(v1, v2, v3)
#endif
#define UL1I_TRC_SFN_CMResult_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2038, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SFN_TwoStage_State(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2138, (char)(v2), TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1I_TRC_SFN_TwoStage_State(v1, v2)
#endif
#define UL1I_TRC_SFN_TwoStage_State_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2138, (char)(v2), TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SIB_Start(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x2238, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD), (long)(v5));\
	} while(0)
#else
	#define UL1T_TRC_SIB_Start(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1T_TRC_SIB_Start_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x2238, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SIB_Reconfig(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2338, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_SIB_Reconfig(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_SIB_Reconfig_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2338, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v5), (char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SIB_Rx(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2438, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_SIB_Rx(v1)
#endif
#define UL1I_TRC_SIB_Rx_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2438, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SIB_State(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2538, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SIB_State(v1)
#endif
#define UL1I_TRC_SIB_State_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2538, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SIB_Rpt(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2638, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SIB_Rpt(v1, v2)
#endif
#define UL1I_TRC_SIB_Rpt_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2638, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SIB_CM(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2738, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_SIB_CM(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_SIB_CM_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2738, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SIB_AdjustProtectPriority(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2838, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SIB_AdjustProtectPriority(v1)
#endif
#define UL1I_TRC_SIB_AdjustProtectPriority_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2838, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1T_TRC_ConfigBAList(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2938, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), (char)(v5)), TRC_MERGE_4C((char)(v6), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ConfigBAList(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1T_TRC_ConfigBAList_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2938, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), (char)(v5)), TRC_MERGE_4C((char)(v6), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CellInfo(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2A38, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1T_TRC_CellInfo(v1, v2, v3)
#endif
#define UL1T_TRC_CellInfo_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2A38, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CellInfo_1(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B38, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CellInfo_1(v1, v2, v3, v4)
#endif
#define UL1T_TRC_CellInfo_1_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B38, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ConfigDetectedCell(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2C38, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1T_TRC_ConfigDetectedCell(v1, v2)
#endif
#define UL1T_TRC_ConfigDetectedCell_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2C38, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1T_TRC_BA_Mapping(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2D38, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_BA_Mapping(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1T_TRC_BA_Mapping_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2D38, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v6)), TRC_MERGE_4C((char)(v7), (char)(v8), (char)(v9), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_BAStatusUpdateInfo(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_BAStatusUpdateInfo(v1, v2, v3)
#endif
#define UL1T_TRC_BAStatusUpdateInfo_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_Alloc_CMM_Report(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_Alloc_CMM_Report(v1, v2, v3)
#endif
#define UL1T_TRC_CM_Alloc_CMM_Report_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_DCH_1st_Tick(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3038, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_DCH_1st_Tick(v1, v2, v3)
#endif
#define UL1T_TRC_CM_DCH_1st_Tick_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3038, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_Prepare_BA_status(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3138, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_Prepare_BA_status(v1, v2, v3)
#endif
#define UL1T_TRC_CM_Prepare_BA_status_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3138, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_DeleteBA(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3238, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_DeleteBA(v1, v2, v3)
#endif
#define UL1T_TRC_CM_DeleteBA_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3238, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_Protected_in_DCH(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3338, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_Protected_in_DCH(v1, v2, v3)
#endif
#define UL1T_TRC_CM_Protected_in_DCH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3338, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_EvaluateReq(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3438, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_EvaluateReq(v1, v2, v3)
#endif
#define UL1T_TRC_CM_EvaluateReq_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3438, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_Trigger_EnhancedCM(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3538, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_Trigger_EnhancedCM(v1, v2, v3)
#endif
#define UL1T_TRC_CM_Trigger_EnhancedCM_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3538, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_DetectedCell_InvalidTM(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3638, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_DetectedCell_InvalidTM(v1, v2, v3)
#endif
#define UL1T_TRC_CM_DetectedCell_InvalidTM_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3638, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_freq_not_existed(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3738, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_freq_not_existed(v1, v2, v3)
#endif
#define UL1T_TRC_CM_freq_not_existed_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3738, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_ConfigBA_by_CCM(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3838, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_ConfigBA_by_CCM(v1, v2, v3)
#endif
#define UL1T_TRC_CM_ConfigBA_by_CCM_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3838, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_Restore_CM_result(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3938, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_Restore_CM_result(v1, v2, v3)
#endif
#define UL1T_TRC_CM_Restore_CM_result_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3938, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_Compensate_CMCS(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_Compensate_CMCS(v1, v2, v3)
#endif
#define UL1T_TRC_CM_Compensate_CMCS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CM_AlarmTimeoutForInterF(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_CM_AlarmTimeoutForInterF(v1, v2, v3)
#endif
#define UL1T_TRC_CM_AlarmTimeoutForInterF_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CM_RptHasCleared(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3C38, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CM_RptHasCleared(v1)
#endif
#define UL1I_TRC_CM_RptHasCleared_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3C38, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMHalt(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3D38, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_CMHalt(v1)
#endif
#define UL1I_TRC_CMHalt_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3D38, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ConfigCell(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3E38, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v6), (char)(v1), TRC_BOXSTER_PAD), (long)(v5));\
	} while(0)
#else
	#define UL1T_TRC_ConfigCell(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_ConfigCell_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3E38, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v6), (char)(v1), TRC_BOXSTER_PAD), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMResult(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3F38, (unsigned short)(v3)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CMResult(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CMResult_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3F38, (unsigned short)(v3)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMResult_RXD(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4038, (unsigned short)(v3)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CMResult_RXD(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CMResult_RXD_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4038, (unsigned short)(v3)), TRC_MERGE_1S2C((short)(v4), (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMDone(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4138, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMDone(v1, v2, v3)
#endif
#define UL1I_TRC_CMDone_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4138, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMStart(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4238, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMStart(v1)
#endif
#define UL1T_TRC_CMStart_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4238, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PrioCMCS(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4338, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PrioCMCS(v1, v2, v3)
#endif
#define UL1I_TRC_PrioCMCS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4338, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMStart(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4438, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CMStart(v1, v2)
#endif
#define UL1I_TRC_CMStart_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4438, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMStop(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4538, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMStop(v1)
#endif
#define UL1T_TRC_CMStop_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4538, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMReportStop() do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4638, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMReportStop()
#endif
#define UL1T_TRC_CMReportStop_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4638, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CMStop(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4738, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CMStop(v1, v2)
#endif
#define UL1I_TRC_CMStop_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4738, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_CMAlphaFilter(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x4838, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAlphaFilter(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_CMAlphaFilter_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x4838, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMReport(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4938, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMReport(v1, v2, v3)
#endif
#define UL1T_TRC_CMReport_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4938, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMAverager(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x4A38, (short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAverager(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1T_TRC_CMAverager_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x4A38, (short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMAverager_RXD(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x4B38, (short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAverager_RXD(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1T_TRC_CMAverager_RXD_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x4B38, (short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMAverager_MAX(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x4C38, (short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAverager_MAX(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1T_TRC_CMAverager_MAX_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x4C38, (short)(v3)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_1S2C((short)(v7), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMAverager2(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4D38, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAverager2(v1, v2, v3)
#endif
#define UL1T_TRC_CMAverager2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4D38, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_CMAverager2_RXD(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4E38, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAverager2_RXD(v1, v2, v3)
#endif
#define UL1T_TRC_CMAverager2_RXD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4E38, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_CMAVG_Put(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4F38, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMAVG_Put(v1, v2, v3)
#endif
#define UL1I_TRC_CMAVG_Put_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4F38, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_CMAVG_Apply(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5038, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CMAVG_Apply(v1, v2)
#endif
#define UL1I_TRC_CMAVG_Apply_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5038, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_CMAVG_Apply_RXD(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5138, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CMAVG_Apply_RXD(v1, v2)
#endif
#define UL1I_TRC_CMAVG_Apply_RXD_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5138, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_CMAVG_LINValue(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5238, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAVG_LINValue(v1, v2, v3)
#endif
#define UL1T_TRC_CMAVG_LINValue_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5238, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_CMAVG_DBG(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5338, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CMAVG_DBG(v1)
#endif
#define UL1T_TRC_CMAVG_DBG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5338, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CMTreselection(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5438, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1_TRC_CMTreselection(v1, v2)
#endif
#define UL1_TRC_CMTreselection_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5438, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASCurrentAnt(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5538, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1_TRC_CM_TASCurrentAnt(v1)
#endif
#define UL1_TRC_CM_TASCurrentAnt_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5538, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASSelectDefaultAnt(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5638, (char)(v2), TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1_TRC_CM_TASSelectDefaultAnt(v1, v2)
#endif
#define UL1_TRC_CM_TASSelectDefaultAnt_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5638, (char)(v2), TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASGuardExpire() do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5738, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASGuardExpire()
#endif
#define UL1_TRC_CM_TASGuardExpire_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5738, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASSwitchBackExpire() do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5838, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASSwitchBackExpire()
#endif
#define UL1_TRC_CM_TASSwitchBackExpire_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5838, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASEnterState(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5938, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1_TRC_CM_TASEnterState(v1)
#endif
#define UL1_TRC_CM_TASEnterState_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5938, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASDedicateAllowed(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5A38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1_TRC_CM_TASDedicateAllowed(v1, v2, v3)
#endif
#define UL1_TRC_CM_TASDedicateAllowed_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5A38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASPCHNotAllowed() do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5B38, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASPCHNotAllowed()
#endif
#define UL1_TRC_CM_TASPCHNotAllowed_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5B38, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASAbortSwitch() do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5C38, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASAbortSwitch()
#endif
#define UL1_TRC_CM_TASAbortSwitch_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5C38, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASSwitchAnt(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x5D38, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1_TRC_CM_TASSwitchAnt(v1, v2, v3)
#endif
#define UL1_TRC_CM_TASSwitchAnt_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x5D38, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASRevertSwitch(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x5E38, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1_TRC_CM_TASRevertSwitch(v1, v2, v3)
#endif
#define UL1_TRC_CM_TASRevertSwitch_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x5E38, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASStartSwitchBack(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5F38, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_TASStartSwitchBack(v1)
#endif
#define UL1_TRC_CM_TASStartSwitchBack_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5F38, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASSwitchBack(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6038, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1_TRC_CM_TASSwitchBack(v1)
#endif
#define UL1_TRC_CM_TASSwitchBack_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x6038, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASSwitchingMetric(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6138, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASSwitchingMetric(v1, v2, v3, v4)
#endif
#define UL1_TRC_CM_TASSwitchingMetric_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6138, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASType1Conditions(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x6238, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)));\
	} while(0)
#else
	#define UL1_TRC_CM_TASType1Conditions(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1_TRC_CM_TASType1Conditions_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x6238, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASType2Conditions(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x6338, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)));\
	} while(0)
#else
	#define UL1_TRC_CM_TASType2Conditions(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1_TRC_CM_TASType2Conditions_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x6338, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASType1Evaluate(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6438, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASType1Evaluate(v1, v2, v3, v4)
#endif
#define UL1_TRC_CM_TASType1Evaluate_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6438, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASType2Evaluate(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6538, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASType2Evaluate(v1, v2, v3, v4, v5, v6)
#endif
#define UL1_TRC_CM_TASType2Evaluate_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6538, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASType1SBConditions(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x6638, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)));\
	} while(0)
#else
	#define UL1_TRC_CM_TASType1SBConditions(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1_TRC_CM_TASType1SBConditions_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x6638, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASType2SBConditions(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x6738, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TASType2SBConditions(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1_TRC_CM_TASType2SBConditions_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x6738, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASSendCMReport(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x6838, (short)(v1)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1_TRC_CM_TASSendCMReport(v1, v2, v3, v4, v5)
#endif
#define UL1_TRC_CM_TASSendCMReport_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x6838, (short)(v1)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASDeriveMeasSample(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x6938, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1_TRC_CM_TASDeriveMeasSample(v1, v2, v3, v4, v5)
#endif
#define UL1_TRC_CM_TASDeriveMeasSample_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x6938, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASDeriveMeasSample_Div(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x6A38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1_TRC_CM_TASDeriveMeasSample_Div(v1, v2, v3)
#endif
#define UL1_TRC_CM_TASDeriveMeasSample_Div_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x6A38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASQueueMeasSample(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x6B38, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_TASQueueMeasSample(v1)
#endif
#define UL1_TRC_CM_TASQueueMeasSample_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x6B38, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASInitDedi(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x6C38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1_TRC_CM_TASInitDedi(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1_TRC_CM_TASInitDedi_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_6_DATA(TRC_MERGE_2S(0x6C38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TASInitIdle(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x6D38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1_TRC_CM_TASInitIdle(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1_TRC_CM_TASInitIdle_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_6_DATA(TRC_MERGE_2S(0x6D38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_ServingIdx(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x6E38, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_ServingIdx(v1)
#endif
#define UL1_TRC_CM_ServingIdx_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x6E38, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_HTP_Power(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x6F38, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_HTP_Power(v1)
#endif
#define UL1_TRC_CM_HTP_Power_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x6F38, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_HTP_Ratio(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7038, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_HTP_Ratio(v1, v2)
#endif
#define UL1_TRC_CM_HTP_Ratio_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7038, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_DPCCH_TXPWR(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7138, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_DPCCH_TXPWR(v1, v2)
#endif
#define UL1_TRC_CM_DPCCH_TXPWR_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7138, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TAS_Dynamic_Barrier(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7238, (short)(v2)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1_TRC_CM_TAS_Dynamic_Barrier(v1, v2, v3)
#endif
#define UL1_TRC_CM_TAS_Dynamic_Barrier_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7238, (short)(v2)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TAS_Avg_Buf_idx(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7338, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TAS_Avg_Buf_idx(v1, v2)
#endif
#define UL1_TRC_CM_TAS_Avg_Buf_idx_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7338, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TAS_Floating_Thre(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7438, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TAS_Floating_Thre(v1, v2)
#endif
#define UL1_TRC_CM_TAS_Floating_Thre_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7438, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TAS_Type1_NoDiv() do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7538, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1_TRC_CM_TAS_Type1_NoDiv()
#endif
#define UL1_TRC_CM_TAS_Type1_NoDiv_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7538, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1_TRC_CM_TAS_StopTimer(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x7638, (short)(v1)));\
	} while(0)
#else
	#define UL1_TRC_CM_TAS_StopTimer(v1)
#endif
#define UL1_TRC_CM_TAS_StopTimer_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x7638, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CSDone(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7738, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_CSDone(v1, v2)
#endif
#define UL1I_TRC_CSDone_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7738, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_CSResult(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7838, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CSResult(v1, v2, v3)
#endif
#define UL1I_TRC_CSResult_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7838, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CSStart(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x7938, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CSStart(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CSStart_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x7938, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CS_Stop(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7A38, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CS_Stop(v1)
#endif
#define UL1I_TRC_CS_Stop_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7A38, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CS_RptHasCleared(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7B38, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CS_RptHasCleared(v1)
#endif
#define UL1I_TRC_CS_RptHasCleared_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7B38, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Unlock_gapStopCnf(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7C38, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Unlock_gapStopCnf(v1)
#endif
#define UL1I_TRC_Unlock_gapStopCnf_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7C38, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_DMStopGap(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7D38, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1T_TRC_DMStopGap(v1, v2)
#endif
#define UL1T_TRC_DMStopGap_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7D38, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_DM_SetGap(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x7E38, (short)(v6)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v7), (char)(v8)), TRC_MERGE_4C((char)(v9), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1T_TRC_DM_SetGap(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1T_TRC_DM_SetGap_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_6_DATA(TRC_MERGE_2S(0x7E38, (short)(v6)), TRC_MERGE_4C((char)(v4), (char)(v5), (char)(v7), (char)(v8)), TRC_MERGE_4C((char)(v9), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1T_TRC_DM_DRXTick(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x7F38, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_DM_DRXTick(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_DM_DRXTick_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x7F38, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_CMCSTickInfo(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8038, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_CMCSTickInfo(v1, v2, v3, v4)
#endif
#define UL1I_TRC_DM_CMCSTickInfo_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8038, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_DM_SetCurrActiveMode(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8138, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_DM_SetCurrActiveMode(v1)
#endif
#define UL1T_TRC_DM_SetCurrActiveMode_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8138, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_AssignGAP(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x8238, (short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_DM_AssignGAP(v1, v2, v3)
#endif
#define UL1I_TRC_DM_AssignGAP_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x8238, (short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Start_GAP_Timer1(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x8338, (short)(v2)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v3), (long)(v5));\
	} while(0)
#else
	#define UL1I_TRC_Start_GAP_Timer1(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_Start_GAP_Timer1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x8338, (short)(v2)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v3), (long)(v5))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Start_GAP_Timer2(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x8438, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_Start_GAP_Timer2(v1, v2, v3, v4)
#endif
#define UL1I_TRC_Start_GAP_Timer2_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x8438, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Start_GAP(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8538, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), (char)(v4)));\
	} while(0)
#else
	#define UL1I_TRC_Start_GAP(v1, v2, v3, v4)
#endif
#define UL1I_TRC_Start_GAP_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8538, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_TimeSyncStart(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x8638, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_DM_TimeSyncStart(v1, v2)
#endif
#define UL1I_TRC_DM_TimeSyncStart_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x8638, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_TimeSyncReport(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x8738, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_DM_TimeSyncReport(v1, v2, v3)
#endif
#define UL1I_TRC_DM_TimeSyncReport_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x8738, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1T_TRC_DM_Cancel_ActiveGAP() do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8838, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_DM_Cancel_ActiveGAP()
#endif
#define UL1T_TRC_DM_Cancel_ActiveGAP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8838, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_Cancel_2G_GAP_Cnf() do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8938, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_Cancel_2G_GAP_Cnf()
#endif
#define UL1I_TRC_DM_Cancel_2G_GAP_Cnf_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8938, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_Query_GAP(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8A38, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_Query_GAP(v1, v2)
#endif
#define UL1I_TRC_DM_Query_GAP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8A38, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_Query_GAP_SM(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8B38, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_Query_GAP_SM(v1, v2)
#endif
#define UL1I_TRC_DM_Query_GAP_SM_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8B38, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_Query_PSEUDO() do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8C38, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_Query_PSEUDO()
#endif
#define UL1I_TRC_DM_Query_PSEUDO_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8C38, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_Sleep_Ind(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x8D38, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v9), (char)(v6), TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define UL1I_TRC_DM_Sleep_Ind(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1I_TRC_DM_Sleep_Ind_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_7_DATA(TRC_MERGE_2S(0x8D38, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v9), (char)(v6), TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v7), (long)(v8))

#if defined(L1_CATCHER)
	#define UL1T_TRC_DM_EFACHDRX_NeedGap(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8E38, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_DM_EFACHDRX_NeedGap(v1)
#endif
#define UL1T_TRC_DM_EFACHDRX_NeedGap_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8E38, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_EFACHDRX_Disable(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8F38, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_EFACHDRX_Disable(v1, v2, v3)
#endif
#define UL1I_TRC_DM_EFACHDRX_Disable_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x8F38, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DMA_Auto_Gap_Assign(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x9038, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_DMA_Auto_Gap_Assign(v1, v2, v3)
#endif
#define UL1I_TRC_DMA_Auto_Gap_Assign_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x9038, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DMA_Auto_Gap_Update(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9138, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_DMA_Auto_Gap_Update(v1, v2)
#endif
#define UL1I_TRC_DMA_Auto_Gap_Update_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9138, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DMS_Auto_Gap_State(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9238, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_DMS_Auto_Gap_State(v1, v2)
#endif
#define UL1I_TRC_DMS_Auto_Gap_State_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9238, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DMS_Auto_Gap_Req(v1, v2, v3) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x9338, (short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_DMS_Auto_Gap_Req(v1, v2, v3)
#endif
#define UL1I_TRC_DMS_Auto_Gap_Req_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x9338, (short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DMS_Auto_Gap_AvailStart(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9438, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_DMS_Auto_Gap_AvailStart(v1, v2)
#endif
#define UL1I_TRC_DMS_Auto_Gap_AvailStart_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9438, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DMS_Auto_Gap_Assign(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x9538, (short)(v1)), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_DMS_Auto_Gap_Assign(v1, v2, v3, v4)
#endif
#define UL1I_TRC_DMS_Auto_Gap_Assign_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x9538, (short)(v1)), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RTB_Timer(v1, v2, v3, v4) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x9638, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_RTB_Timer(v1, v2, v3, v4)
#endif
#define UL1I_TRC_RTB_Timer_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x9638, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1I_TRC_AGPS_INFO(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x9738, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1I_TRC_AGPS_INFO(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_AGPS_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x9738, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_ADJUSTMENT_STATUS(v1) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9838, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_ADJUSTMENT_STATUS(v1)
#endif
#define UL1I_TRC_CTCH_ADJUSTMENT_STATUS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x9838, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_ADJUSTMENT_SUSPEND(v1, v2) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x9938, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_ADJUSTMENT_SUSPEND(v1, v2)
#endif
#define UL1I_TRC_CTCH_ADJUSTMENT_SUSPEND_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x9938, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CTCH_Resume(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI2_Trace_Filter[0]==1 && (UL1C_PRI2_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x9A38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CTCH_Resume(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_CTCH_Resume_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x9A38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1C_PRI2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1I_TRC_CTCH_Start(short v1, long v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_CTCH_Next_L1(short v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_CTCH_BS_Start(short v1, short v2, short v3, long v4, short v5, short v6);
void L1TRC_Send_UL1I_TRC_CTCH_Rx_Status(char v1, short v2);
void L1TRC_Send_UL1I_TRC_CTCH_L2_BP(short v1, short v2, long v3, short v4);
void L1TRC_Send_UL1I_TRC_Timer(char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_LeaveConfig(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1I_TRC_EnterConfig(short v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_AbortConfig(char v1);
void L1TRC_Send_UL1I_TRC_SuspendCNF(char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_BCH_CCM_SIB_STATUS(char v1, char v2);
void L1TRC_Send_UL1I_TRC_BCH_CCM_SFN_STATUS(char v1, char v2);
void L1TRC_Send_UL1I_TRC_EnterMode(char v1);
void L1TRC_Send_UL1I_TRC_EnterDCH(short v1, short v2, char v3, long v4, short v5, char v6, char v7, char v8, char v9, short v10);
void L1TRC_Send_UL1I_TRC_EnterPCH(short v1, short v2, char v3, long v4, short v5);
void L1TRC_Send_UL1I_TRC_EnterFACH(short v1, short v2, char v3, long v4, short v5);
void L1TRC_Send_UL1I_TRC_EnterNull(short v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_CCM_SetFN(short v1);
void L1TRC_Send_UL1I_TRC_StartDLDCH(short v1, short v2);
void L1TRC_Send_UL1I_TRC_TTI(short v1, short v2);
void L1TRC_Send_UL1I_TRC_CCM_State(char v1);
void L1TRC_Send_UL1T_TRC_SFN_Stop(void);
void L1TRC_Send_UL1T_TRC_SFN_Start(short v1, short v2, long v3);
void L1TRC_Send_UL1I_TRC_SFN_Rx(char v1, short v2);
void L1TRC_Send_UL1I_TRC_SFN_State(char v1);
void L1TRC_Send_UL1T_TRC_SFN_Data(char v1, short v2);
void L1TRC_Send_UL1I_TRC_SFN_Report(char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_SFN_InternalStop(char v1, char v2, short v3, char v4);
void L1TRC_Send_UL1I_TRC_SFN_Compensation(char v1);
void L1TRC_Send_UL1I_TRC_SFN_Avail_Dec_Frms(short v1);
void L1TRC_Send_UL1I_TRC_SFN_AdjustProtectPriority(char v1);
void L1TRC_Send_UL1I_TRC_SFN_ReStart(short v1, short v2);
void L1TRC_Send_UL1I_TRC_SFN_CMResult(short v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_SFN_TwoStage_State(long v1, char v2);
void L1TRC_Send_UL1T_TRC_SIB_Start(short v1, short v2, short v3, short v4, long v5, short v6, char v7, char v8, char v9);
void L1TRC_Send_UL1T_TRC_SIB_Reconfig(short v1, short v2, char v3, char v4, char v5, char v6);
void L1TRC_Send_UL1I_TRC_SIB_Rx(short v1);
void L1TRC_Send_UL1I_TRC_SIB_State(char v1);
void L1TRC_Send_UL1I_TRC_SIB_Rpt(short v1, char v2);
void L1TRC_Send_UL1T_TRC_SIB_CM(char v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1I_TRC_SIB_AdjustProtectPriority(char v1);
void L1TRC_Send_UL1T_TRC_ConfigBAList(char v1, char v2, char v3, short v4, char v5, char v6, char v7);
void L1TRC_Send_UL1T_TRC_CellInfo(char v1, short v2, long v3);
void L1TRC_Send_UL1T_TRC_CellInfo_1(char v1, char v2, char v3, char v4);
void L1TRC_Send_UL1T_TRC_ConfigDetectedCell(char v1, char v2);
void L1TRC_Send_UL1T_TRC_BA_Mapping(char v1, char v2, char v3, char v4, char v5, char v6, char v7, char v8, char v9);
void L1TRC_Send_UL1T_TRC_BAStatusUpdateInfo(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_Alloc_CMM_Report(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_DCH_1st_Tick(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_Prepare_BA_status(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_DeleteBA(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_Protected_in_DCH(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_EvaluateReq(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_Trigger_EnhancedCM(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_DetectedCell_InvalidTM(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_freq_not_existed(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_ConfigBA_by_CCM(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_Restore_CM_result(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_Compensate_CMCS(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_CM_AlarmTimeoutForInterF(short v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_CM_RptHasCleared(char v1);
void L1TRC_Send_UL1I_TRC_CMHalt(short v1);
void L1TRC_Send_UL1T_TRC_ConfigCell(char v1, short v2, short v3, short v4, long v5, short v6);
void L1TRC_Send_UL1I_TRC_CMResult(char v1, char v2, unsigned short v3, short v4);
void L1TRC_Send_UL1I_TRC_CMResult_RXD(char v1, char v2, unsigned short v3, short v4);
void L1TRC_Send_UL1I_TRC_CMDone(char v1, char v2, char v3);
void L1TRC_Send_UL1T_TRC_CMStart(char v1);
void L1TRC_Send_UL1I_TRC_PrioCMCS(short v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_CMStart(char v1, char v2);
void L1TRC_Send_UL1T_TRC_CMStop(char v1);
void L1TRC_Send_UL1T_TRC_CMReportStop(void);
void L1TRC_Send_UL1I_TRC_CMStop(char v1, char v2);
void L1TRC_Send_UL1T_TRC_CMAlphaFilter(char v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1T_TRC_CMReport(char v1, char v2, char v3);
void L1TRC_Send_UL1T_TRC_CMAverager(char v1, char v2, short v3, char v4, short v5, short v6, short v7);
void L1TRC_Send_UL1T_TRC_CMAverager_RXD(char v1, char v2, short v3, char v4, short v5, short v6, short v7);
void L1TRC_Send_UL1T_TRC_CMAverager_MAX(char v1, char v2, short v3, char v4, short v5, short v6, short v7);
void L1TRC_Send_UL1T_TRC_CMAverager2(char v1, char v2, short v3);
void L1TRC_Send_UL1T_TRC_CMAverager2_RXD(char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_CMAVG_Put(char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_CMAVG_Apply(char v1, char v2);
void L1TRC_Send_UL1I_TRC_CMAVG_Apply_RXD(char v1, char v2);
void L1TRC_Send_UL1T_TRC_CMAVG_LINValue(char v1, char v2, char v3);
void L1TRC_Send_UL1T_TRC_CMAVG_DBG(char v1);
void L1TRC_Send_UL1_TRC_CMTreselection(char v1, char v2);
void L1TRC_Send_UL1_TRC_CM_TASCurrentAnt(long v1);
void L1TRC_Send_UL1_TRC_CM_TASSelectDefaultAnt(long v1, char v2);
void L1TRC_Send_UL1_TRC_CM_TASGuardExpire(void);
void L1TRC_Send_UL1_TRC_CM_TASSwitchBackExpire(void);
void L1TRC_Send_UL1_TRC_CM_TASEnterState(long v1);
void L1TRC_Send_UL1_TRC_CM_TASDedicateAllowed(short v1, short v2, short v3);
void L1TRC_Send_UL1_TRC_CM_TASPCHNotAllowed(void);
void L1TRC_Send_UL1_TRC_CM_TASAbortSwitch(void);
void L1TRC_Send_UL1_TRC_CM_TASSwitchAnt(long v1, long v2, long v3);
void L1TRC_Send_UL1_TRC_CM_TASRevertSwitch(long v1, long v2, long v3);
void L1TRC_Send_UL1_TRC_CM_TASStartSwitchBack(short v1);
void L1TRC_Send_UL1_TRC_CM_TASSwitchBack(long v1);
void L1TRC_Send_UL1_TRC_CM_TASSwitchingMetric(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1_TRC_CM_TASType1Conditions(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9);
void L1TRC_Send_UL1_TRC_CM_TASType2Conditions(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9);
void L1TRC_Send_UL1_TRC_CM_TASType1Evaluate(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1_TRC_CM_TASType2Evaluate(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1_TRC_CM_TASType1SBConditions(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9);
void L1TRC_Send_UL1_TRC_CM_TASType2SBConditions(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1_TRC_CM_TASSendCMReport(short v1, char v2, long v3, short v4, short v5);
void L1TRC_Send_UL1_TRC_CM_TASDeriveMeasSample(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1_TRC_CM_TASDeriveMeasSample_Div(short v1, short v2, short v3);
void L1TRC_Send_UL1_TRC_CM_TASQueueMeasSample(short v1);
void L1TRC_Send_UL1_TRC_CM_TASInitDedi(short v1, short v2, long v3, long v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1_TRC_CM_TASInitIdle(short v1, short v2, long v3, long v4, short v5, short v6, short v7, short v8, short v9);
void L1TRC_Send_UL1_TRC_CM_ServingIdx(short v1);
void L1TRC_Send_UL1_TRC_CM_HTP_Power(short v1);
void L1TRC_Send_UL1_TRC_CM_HTP_Ratio(short v1, short v2);
void L1TRC_Send_UL1_TRC_CM_DPCCH_TXPWR(short v1, short v2);
void L1TRC_Send_UL1_TRC_CM_TAS_Dynamic_Barrier(long v1, short v2, short v3);
void L1TRC_Send_UL1_TRC_CM_TAS_Avg_Buf_idx(short v1, short v2);
void L1TRC_Send_UL1_TRC_CM_TAS_Floating_Thre(short v1, short v2);
void L1TRC_Send_UL1_TRC_CM_TAS_Type1_NoDiv(void);
void L1TRC_Send_UL1_TRC_CM_TAS_StopTimer(short v1);
void L1TRC_Send_UL1I_TRC_CSDone(char v1, char v2);
void L1TRC_Send_UL1I_TRC_CSResult(char v1, short v2, unsigned short v3);
void L1TRC_Send_UL1I_TRC_CSStart(char v1, short v2, char v3, char v4);
void L1TRC_Send_UL1I_TRC_CS_Stop(char v1);
void L1TRC_Send_UL1I_TRC_CS_RptHasCleared(char v1);
void L1TRC_Send_UL1I_TRC_Unlock_gapStopCnf(char v1);
void L1TRC_Send_UL1T_TRC_DMStopGap(char v1, char v2);
void L1TRC_Send_UL1T_TRC_DM_SetGap(long v1, long v2, long v3, char v4, char v5, short v6, char v7, char v8, char v9);
void L1TRC_Send_UL1T_TRC_DM_DRXTick(char v1, short v2, char v3, short v4, short v5);
void L1TRC_Send_UL1I_TRC_DM_CMCSTickInfo(char v1, char v2, char v3, char v4);
void L1TRC_Send_UL1T_TRC_DM_SetCurrActiveMode(char v1);
void L1TRC_Send_UL1I_TRC_DM_AssignGAP(short v1, long v2, long v3);
void L1TRC_Send_UL1I_TRC_Start_GAP_Timer1(long v1, short v2, long v3, short v4, long v5);
void L1TRC_Send_UL1I_TRC_Start_GAP_Timer2(char v1, long v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_Start_GAP(char v1, short v2, short v3, char v4);
void L1TRC_Send_UL1I_TRC_DM_TimeSyncStart(long v1, long v2);
void L1TRC_Send_UL1I_TRC_DM_TimeSyncReport(long v1, long v2, long v3);
void L1TRC_Send_UL1T_TRC_DM_Cancel_ActiveGAP(void);
void L1TRC_Send_UL1I_TRC_DM_Cancel_2G_GAP_Cnf(void);
void L1TRC_Send_UL1I_TRC_DM_Query_GAP(char v1, short v2);
void L1TRC_Send_UL1I_TRC_DM_Query_GAP_SM(char v1, short v2);
void L1TRC_Send_UL1I_TRC_DM_Query_PSEUDO(void);
void L1TRC_Send_UL1I_TRC_DM_Sleep_Ind(long v1, long v2, short v3, short v4, short v5, char v6, long v7, long v8, short v9);
void L1TRC_Send_UL1T_TRC_DM_EFACHDRX_NeedGap(char v1);
void L1TRC_Send_UL1I_TRC_DM_EFACHDRX_Disable(char v1, char v2, char v3);
void L1TRC_Send_UL1I_TRC_DMA_Auto_Gap_Assign(long v1, long v2, long v3);
void L1TRC_Send_UL1I_TRC_DMA_Auto_Gap_Update(char v1, char v2);
void L1TRC_Send_UL1I_TRC_DMS_Auto_Gap_State(char v1, char v2);
void L1TRC_Send_UL1I_TRC_DMS_Auto_Gap_Req(short v1, long v2, long v3);
void L1TRC_Send_UL1I_TRC_DMS_Auto_Gap_AvailStart(char v1, char v2);
void L1TRC_Send_UL1I_TRC_DMS_Auto_Gap_Assign(short v1, long v2, long v3, long v4);
void L1TRC_Send_UL1I_TRC_RTB_Timer(char v1, short v2, long v3, char v4);
void L1TRC_Send_UL1I_TRC_AGPS_INFO(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1I_TRC_CTCH_ADJUSTMENT_STATUS(char v1);
void L1TRC_Send_UL1I_TRC_CTCH_ADJUSTMENT_SUSPEND(short v1, short v2);
void L1TRC_Send_UL1I_TRC_CTCH_Resume(short v1, short v2, short v3, short v4, short v5, short v6);

void Set_UL1C_PRI2_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1C_PRI2()	(UL1C_PRI2_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_TIMER_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_RTB_L()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_TIMER_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_RTB_M()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_TIMER_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[4]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[4]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[4]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[4]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI2_UL1C_RTB_H()	(ChkL1ModFltr_UL1C_PRI2()&&((UL1C_PRI2_Trace_Filter[4]&0x20)!=0))
#define ChkL1MsgFltr_UL1I_TRC_CTCH_Start()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_Next_L1()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_BS_Start()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_Rx_Status()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_L2_BP()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Timer()	ChkL1ClsFltr_UL1C_PRI2_UL1C_TIMER_H()
#define ChkL1MsgFltr_UL1I_TRC_LeaveConfig()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_EnterConfig()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_AbortConfig()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_SuspendCNF()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_BCH_CCM_SIB_STATUS()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_BCH_CCM_SFN_STATUS()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_EnterMode()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_EnterDCH()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_EnterPCH()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_EnterFACH()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_EnterNull()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_CCM_SetFN()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_StartDLDCH()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_TTI()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1I_TRC_CCM_State()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CCM_H()
#define ChkL1MsgFltr_UL1T_TRC_SFN_Stop()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1T_TRC_SFN_Start()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_Rx()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_State()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1T_TRC_SFN_Data()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_Report()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_InternalStop()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_Compensation()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_Avail_Dec_Frms()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_AdjustProtectPriority()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_ReStart()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_CMResult()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1I_TRC_SFN_TwoStage_State()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SFN_H()
#define ChkL1MsgFltr_UL1T_TRC_SIB_Start()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1T_TRC_SIB_Reconfig()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1I_TRC_SIB_Rx()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1I_TRC_SIB_State()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1I_TRC_SIB_Rpt()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1T_TRC_SIB_CM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1I_TRC_SIB_AdjustProtectPriority()	ChkL1ClsFltr_UL1C_PRI2_UL1C_SIB_H()
#define ChkL1MsgFltr_UL1T_TRC_ConfigBAList()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_M()
#define ChkL1MsgFltr_UL1T_TRC_CellInfo()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CellInfo_1()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_ConfigDetectedCell()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_BA_Mapping()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_M()
#define ChkL1MsgFltr_UL1T_TRC_BAStatusUpdateInfo()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_Alloc_CMM_Report()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_DCH_1st_Tick()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_Prepare_BA_status()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_DeleteBA()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_Protected_in_DCH()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_EvaluateReq()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_Trigger_EnhancedCM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_DetectedCell_InvalidTM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_freq_not_existed()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_ConfigBA_by_CCM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_Restore_CM_result()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_Compensate_CMCS()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CM_AlarmTimeoutForInterF()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CM_RptHasCleared()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMHalt()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_ConfigCell()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMResult()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMResult_RXD()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMDone()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CMStart()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_PrioCMCS()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMStart()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CMStop()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CMReportStop()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CMStop()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CMAlphaFilter()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_L()
#define ChkL1MsgFltr_UL1T_TRC_CMReport()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1T_TRC_CMAverager()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_H()
#define ChkL1MsgFltr_UL1T_TRC_CMAverager_RXD()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_H()
#define ChkL1MsgFltr_UL1T_TRC_CMAverager_MAX()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_H()
#define ChkL1MsgFltr_UL1T_TRC_CMAverager2()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_H()
#define ChkL1MsgFltr_UL1T_TRC_CMAverager2_RXD()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_H()
#define ChkL1MsgFltr_UL1I_TRC_CMAVG_Put()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_L()
#define ChkL1MsgFltr_UL1I_TRC_CMAVG_Apply()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_L()
#define ChkL1MsgFltr_UL1I_TRC_CMAVG_Apply_RXD()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_L()
#define ChkL1MsgFltr_UL1T_TRC_CMAVG_LINValue()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_L()
#define ChkL1MsgFltr_UL1T_TRC_CMAVG_DBG()	ChkL1ClsFltr_UL1C_PRI2_UL1C_AVG_L()
#define ChkL1MsgFltr_UL1_TRC_CMTreselection()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASCurrentAnt()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASSelectDefaultAnt()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASGuardExpire()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASSwitchBackExpire()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASEnterState()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASDedicateAllowed()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASPCHNotAllowed()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASAbortSwitch()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASSwitchAnt()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASRevertSwitch()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASStartSwitchBack()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASSwitchBack()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASSwitchingMetric()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASType1Conditions()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASType2Conditions()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASType1Evaluate()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASType2Evaluate()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASType1SBConditions()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASType2SBConditions()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASSendCMReport()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASDeriveMeasSample()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASDeriveMeasSample_Div()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASQueueMeasSample()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASInitDedi()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TASInitIdle()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_ServingIdx()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_HTP_Power()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_HTP_Ratio()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_DPCCH_TXPWR()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TAS_Dynamic_Barrier()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TAS_Avg_Buf_idx()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TAS_Floating_Thre()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TAS_Type1_NoDiv()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1_TRC_CM_TAS_StopTimer()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CMM_H()
#define ChkL1MsgFltr_UL1I_TRC_CSDone()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_H()
#define ChkL1MsgFltr_UL1I_TRC_CSResult()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_L()
#define ChkL1MsgFltr_UL1I_TRC_CSStart()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_H()
#define ChkL1MsgFltr_UL1I_TRC_CS_Stop()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_H()
#define ChkL1MsgFltr_UL1I_TRC_CS_RptHasCleared()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CS_H()
#define ChkL1MsgFltr_UL1I_TRC_Unlock_gapStopCnf()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1T_TRC_DMStopGap()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1T_TRC_DM_SetGap()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1T_TRC_DM_DRXTick()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_CMCSTickInfo()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1T_TRC_DM_SetCurrActiveMode()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_AssignGAP()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_Start_GAP_Timer1()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_Start_GAP_Timer2()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_Start_GAP()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_TimeSyncStart()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_TimeSyncReport()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1T_TRC_DM_Cancel_ActiveGAP()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_Cancel_2G_GAP_Cnf()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_Query_GAP()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_Query_GAP_SM()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_Query_PSEUDO()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_Sleep_Ind()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1T_TRC_DM_EFACHDRX_NeedGap()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_EFACHDRX_Disable()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DMA_Auto_Gap_Assign()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DMA_Auto_Gap_Update()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DMS_Auto_Gap_State()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DMS_Auto_Gap_Req()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DMS_Auto_Gap_AvailStart()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_DMS_Auto_Gap_Assign()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_RTB_Timer()	ChkL1ClsFltr_UL1C_PRI2_UL1C_RTB_H()
#define ChkL1MsgFltr_UL1I_TRC_AGPS_INFO()	ChkL1ClsFltr_UL1C_PRI2_UL1C_DM_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_ADJUSTMENT_STATUS()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_ADJUSTMENT_SUSPEND()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()
#define ChkL1MsgFltr_UL1I_TRC_CTCH_Resume()	ChkL1ClsFltr_UL1C_PRI2_UL1C_CTCH_H()


#endif
