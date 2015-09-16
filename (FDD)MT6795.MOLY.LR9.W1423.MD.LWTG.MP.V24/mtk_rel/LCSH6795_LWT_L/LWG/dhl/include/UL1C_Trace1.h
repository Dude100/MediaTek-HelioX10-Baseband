#ifndef L1TRC_UL1C_PRI1_DEF_H
#define L1TRC_UL1C_PRI1_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define UL1I_TRC_CM_Obsolete(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0038, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1I_TRC_CM_Obsolete(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_CM_Obsolete_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0038, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PS_TASFreqScanAnt(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0138, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_PS_TASFreqScanAnt(v1)
#endif
#define UL1I_TRC_PS_TASFreqScanAnt_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0138, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PS_Result(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0238, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PS_Result(v1)
#endif
#define UL1I_TRC_PS_Result_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0238, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PS_SortedFreq(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0338, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PS_SortedFreq(v1, v2)
#endif
#define UL1I_TRC_PS_SortedFreq_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0338, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_Result(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0438, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FS_Result(v1, v2)
#endif
#define UL1I_TRC_FS_Result_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0438, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_State(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0538, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_FS_State(v1, v2)
#endif
#define UL1I_TRC_FS_State_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0538, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_UL1_Suspend(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0638, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_FS_UL1_Suspend(v1, v2)
#endif
#define UL1I_TRC_FS_UL1_Suspend_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0638, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_FS_Start(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0738, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1T_TRC_FS_Start(v1, v2)
#endif
#define UL1T_TRC_FS_Start_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0738, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_FS_Cont() do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0838, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_FS_Cont()
#endif
#define UL1T_TRC_FS_Cont_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0838, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_FS_Suspend() do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0938, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_FS_Suspend()
#endif
#define UL1T_TRC_FS_Suspend_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0938, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_FB_PwrScanNext(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A38, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FS_FB_PwrScanNext(v1, v2)
#endif
#define UL1I_TRC_FS_FB_PwrScanNext_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A38, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_AutoGap_State(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B38, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1I_TRC_FS_AutoGap_State(v1)
#endif
#define UL1I_TRC_FS_AutoGap_State_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B38, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_ScanSuspend(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1I_TRC_FS_ScanSuspend(v1, v2, v3)
#endif
#define UL1I_TRC_FS_ScanSuspend_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_ProcessScanStart(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1I_TRC_FS_ProcessScanStart(v1, v2, v3)
#endif
#define UL1I_TRC_FS_ProcessScanStart_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ECS_Start(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0E38, (short)(v1)));\
	} while(0)
#else
	#define UL1T_TRC_ECS_Start(v1)
#endif
#define UL1T_TRC_ECS_Start_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0E38, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ECS_Stop() do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F38, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ECS_Stop()
#endif
#define UL1T_TRC_ECS_Stop_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F38, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_ECS_InternalStop() do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1038, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_ECS_InternalStop()
#endif
#define UL1I_TRC_ECS_InternalStop_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1038, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_ECS_Status(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1138, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_ECS_Status(v1)
#endif
#define UL1I_TRC_ECS_Status_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1138, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_ECS_Result(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1238, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_ECS_Result(v1, v2)
#endif
#define UL1I_TRC_ECS_Result_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1238, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_BeforeGetPendingResult(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1338, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FS_BeforeGetPendingResult(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_FS_BeforeGetPendingResult_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1338, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_AfterGetPendingResult(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1438, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FS_AfterGetPendingResult(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_FS_AfterGetPendingResult_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1438, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FS_AfterResume(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1538, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FS_AfterResume(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_FS_AfterResume_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1538, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), (char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HFS_DBG(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1638, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_HFS_DBG(v1, v2)
#endif
#define UL1I_TRC_HFS_DBG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1638, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HFS_DBG2(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1738, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_HFS_DBG2(v1, v2)
#endif
#define UL1I_TRC_HFS_DBG2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1738, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Get_ULDCHData(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1838, (short)(v1)), TRC_MERGE_1S2C((short)(v4), (char)(v2), (char)(v3)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Get_ULDCHData(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_Get_ULDCHData_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1838, (short)(v1)), TRC_MERGE_1S2C((short)(v4), (char)(v2), (char)(v3)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Get_ULDCHTRCHData(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1938, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Get_ULDCHTRCHData(v1, v2, v3, v4)
#endif
#define UL1I_TRC_Get_ULDCHTRCHData_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1938, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_StartULDCh(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A38, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_StartULDCh(v1, v2)
#endif
#define UL1I_TRC_StartULDCh_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A38, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TxStatus(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B38, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TxStatus(v1)
#endif
#define UL1I_TRC_TxStatus_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B38, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UL_Timer_TFC_CB(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C38, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_UL_Timer_TFC_CB(v1)
#endif
#define UL1I_TRC_UL_Timer_TFC_CB_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C38, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UL_Timer_Data_CB(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1I_TRC_UL_Timer_Data_CB(v1, v2, v3)
#endif
#define UL1I_TRC_UL_Timer_Data_CB_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_Report_ULCB_Data(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_Report_ULCB_Data(v1, v2, v3)
#endif
#define UL1T_TRC_Report_ULCB_Data_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_Report_ULCB_TFC(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1F38, (short)(v1)));\
	} while(0)
#else
	#define UL1T_TRC_Report_ULCB_TFC(v1)
#endif
#define UL1T_TRC_Report_ULCB_TFC_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1F38, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_StopULDCh() do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2038, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_StopULDCh()
#endif
#define UL1I_TRC_StopULDCh_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2038, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_ULDCH_next_timer_delay(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2138, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_ULDCH_next_timer_delay(v1)
#endif
#define UL1I_TRC_ULDCH_next_timer_delay_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2138, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_ULDCH_UL1D_Intf(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2238, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_ULDCH_UL1D_Intf(v1)
#endif
#define UL1I_TRC_ULDCH_UL1D_Intf_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2238, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_ULDCH_Set_MAC_Event(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2338, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_ULDCH_Set_MAC_Event(v1)
#endif
#define UL1I_TRC_ULDCH_Set_MAC_Event_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2338, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Get_DLDCHData(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2438, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Get_DLDCHData(v1, v2, v3)
#endif
#define UL1I_TRC_Get_DLDCHData_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2438, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Get_DLDCHTRCHData(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2538, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Get_DLDCHTRCHData(v1, v2, v3)
#endif
#define UL1I_TRC_Get_DLDCHTRCHData_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2538, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RefDCH(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2638, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RefDCH(v1)
#endif
#define UL1I_TRC_RefDCH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2638, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RefDCHCFN(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2738, (short)(v2)), (long)(v1));\
	} while(0)
#else
	#define UL1I_TRC_RefDCHCFN(v1, v2)
#endif
#define UL1I_TRC_RefDCHCFN_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2738, (short)(v2)), (long)(v1))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DLSync_State(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2838, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DLSync_State(v1)
#endif
#define UL1I_TRC_DLSync_State_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2838, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DLSync_Qin(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2938, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DLSync_Qin(v1, v2)
#endif
#define UL1I_TRC_DLSync_Qin_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2938, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_New_DPCH_Type(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A38, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_New_DPCH_Type(v1, v2)
#endif
#define UL1I_TRC_New_DPCH_Type_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A38, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DPCH_Type(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2B38, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DPCH_Type(v1)
#endif
#define UL1I_TRC_DPCH_Type_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2B38, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ReconfigDCH(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v6)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v7)));\
	} while(0)
#else
	#define UL1T_TRC_ReconfigDCH(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1T_TRC_ReconfigDCH_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v6)), TRC_MERGE_4C((char)(v3), (char)(v4), (char)(v5), (char)(v7)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ReconfigDCH_ASAP(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_ReconfigDCH_ASAP(v1, v2, v3)
#endif
#define UL1T_TRC_ReconfigDCH_ASAP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_LoopMode2(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E38, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_LoopMode2(v1, v2, v3)
#endif
#define UL1T_TRC_LoopMode2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2E38, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ASU(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ASU(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_ASU_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F38, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DL_DCHQual(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3038, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DL_DCHQual(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_DL_DCHQual_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3038, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DL_CRC_Value(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3138, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1I_TRC_DL_CRC_Value(v1)
#endif
#define UL1I_TRC_DL_CRC_Value_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3138, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DL_Sync_Type(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3238, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DL_Sync_Type(v1, v2)
#endif
#define UL1I_TRC_DL_Sync_Type_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3238, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DL_Sync_Info(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3338, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DL_Sync_Info(v1, v2, v3, v4)
#endif
#define UL1I_TRC_DL_Sync_Info_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3338, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_DLSync_Config(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3438, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1T_TRC_DLSync_Config(v1, v2)
#endif
#define UL1T_TRC_DLSync_Config_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3438, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ReconfigDCH_TTI(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3538, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ReconfigDCH_TTI(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_ReconfigDCH_TTI_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3538, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ReconfigDCH_TGPS(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3638, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ReconfigDCH_TGPS(v1, v2)
#endif
#define UL1T_TRC_ReconfigDCH_TGPS_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3638, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_Modify_Abort(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3738, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Modify_Abort(v1, v2)
#endif
#define UL1T_TRC_Modify_Abort_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3738, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UpdateDpchRl(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3838, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1I_TRC_UpdateDpchRl(v1, v2, v3)
#endif
#define UL1I_TRC_UpdateDpchRl_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3838, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FMO(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3938, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FMO(v1)
#endif
#define UL1I_TRC_FMO_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3938, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_FMO_Config(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3A38, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), (char)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_FMO_Config(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_FMO_Config_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3A38, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), (char)(v5)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FACH_Data(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3B38, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_FACH_Data(v1)
#endif
#define UL1I_TRC_FACH_Data_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3B38, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DRX_GAP(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3C38, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DRX_GAP(v1, v2, v3)
#endif
#define UL1I_TRC_DRX_GAP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3C38, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SCS_Start(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3D38, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), (char)(v4)));\
	} while(0)
#else
	#define UL1T_TRC_SCS_Start(v1, v2, v3, v4)
#endif
#define UL1T_TRC_SCS_Start_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3D38, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_SCS_Stop() do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E38, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_SCS_Stop()
#endif
#define UL1T_TRC_SCS_Stop_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E38, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SCS_State(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3F38, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_SCS_State(v1, v2)
#endif
#define UL1I_TRC_SCS_State_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3F38, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SCS_Result(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4038, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_SCS_Result(v1)
#endif
#define UL1I_TRC_SCS_Result_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4038, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SCS_Conflict(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4138, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SCS_Conflict(v1, v2)
#endif
#define UL1I_TRC_SCS_Conflict_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4138, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_MBSCS_ResourceConflict(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4238, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_MBSCS_ResourceConflict(v1)
#endif
#define UL1I_TRC_MBSCS_ResourceConflict_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4238, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_MBSCS_Resource(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4338, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1I_TRC_MBSCS_Resource(v1, v2, v3)
#endif
#define UL1I_TRC_MBSCS_Resource_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4338, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SCS_Init() do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4438, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SCS_Init()
#endif
#define UL1I_TRC_SCS_Init_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4438, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_Status(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4538, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_Status(v1)
#endif
#define UL1I_TRC_PCH_Status_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4538, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_ReconfigPCH(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4638, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ReconfigPCH(v1, v2, v3)
#endif
#define UL1T_TRC_ReconfigPCH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4638, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_drx_cycle2_life(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4738, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_PCH_drx_cycle2_life(v1)
#endif
#define UL1I_TRC_PCH_drx_cycle2_life_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4738, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_SmartPagingState(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4838, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_SmartPagingState(v1, v2)
#endif
#define UL1I_TRC_PCH_SmartPagingState_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4838, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_SmartPagingLog(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x4938, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v6), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_SmartPagingLog(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1I_TRC_PCH_SmartPagingLog_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x4938, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v6), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_SmartCSState(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4A38, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_SmartCSState(v1)
#endif
#define UL1I_TRC_PCH_SmartCSState_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4A38, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_PCH_SmartCSLog(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x4B38, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_1S2C((short)(v9), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_PCH_SmartCSLog(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1T_TRC_PCH_SmartCSLog_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x4B38, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_1S2C((short)(v9), (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_SmartCSSkip(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4C38, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_SmartCSSkip(v1)
#endif
#define UL1I_TRC_PCH_SmartCSSkip_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4C38, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_RxDEnSkip(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4D38, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_PCH_RxDEnSkip(v1)
#endif
#define UL1I_TRC_PCH_RxDEnSkip_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4D38, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_RxDEn(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4E38, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_PCH_RxDEn(v1)
#endif
#define UL1I_TRC_PCH_RxDEn_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4E38, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_RxDSwitchDelay(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4F38, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_PCH_RxDSwitchDelay(v1)
#endif
#define UL1I_TRC_PCH_RxDSwitchDelay_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4F38, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_RxDEcnoRscp(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5038, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1I_TRC_PCH_RxDEcnoRscp(v1, v2, v3)
#endif
#define UL1I_TRC_PCH_RxDEcnoRscp_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5038, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_RxDServingInfo(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5138, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_RxDServingInfo(v1, v2)
#endif
#define UL1I_TRC_PCH_RxDServingInfo_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5138, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_TASEvaluate(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5238, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_PCH_TASEvaluate(v1)
#endif
#define UL1I_TRC_PCH_TASEvaluate_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5238, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_TASProcOngoing() do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5338, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_PCH_TASProcOngoing()
#endif
#define UL1I_TRC_PCH_TASProcOngoing_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5338, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_TASStartTimer(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5438, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_PCH_TASStartTimer(v1)
#endif
#define UL1I_TRC_PCH_TASStartTimer_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5438, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_PCH_TASTriggerUnsync(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5538, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_PCH_TASTriggerUnsync(v1)
#endif
#define UL1I_TRC_PCH_TASTriggerUnsync_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5538, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TxAccess(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5638, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_TxAccess(v1, v2)
#endif
#define UL1T_TRC_TxAccess_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5638, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_RAChData(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5738, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_RAChData(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_RAChData_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5738, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RACH_ASCSetting(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5838, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RACH_ASCSetting(v1, v2)
#endif
#define UL1I_TRC_RACH_ASCSetting_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5838, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Get_Access_Slot(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5938, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), (char)(v5)));\
	} while(0)
#else
	#define UL1I_TRC_Get_Access_Slot(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_Get_Access_Slot_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5938, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), (char)(v5)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RACH_Start(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5A38, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1I_TRC_RACH_Start(v1)
#endif
#define UL1I_TRC_RACH_Start_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5A38, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER)
	#define UL1T_TRC_RACH_NextASS(v1, v2) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5B38, (short)(v1)), (long)(v2));\
	} while(0)
#else
	#define UL1T_TRC_RACH_NextASS(v1, v2)
#endif
#define UL1T_TRC_RACH_NextASS_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5B38, (short)(v1)), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TxAccess(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5C38, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_TxAccess(v1, v2, v3, v4)
#endif
#define UL1I_TRC_TxAccess_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5C38, (short)(v4)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DelayTxAccess_CCM(v1, v2, v3, v4) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5D38, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_DelayTxAccess_CCM(v1, v2, v3, v4)
#endif
#define UL1I_TRC_DelayTxAccess_CCM_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5D38, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DelayTxAccess_FMO(v1, v2, v3) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5E38, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_DelayTxAccess_FMO(v1, v2, v3)
#endif
#define UL1I_TRC_DelayTxAccess_FMO_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5E38, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER)
	#define UL1AC_TRC_EvtReport(v1) do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5F38, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1AC_TRC_EvtReport(v1)
#endif
#define UL1AC_TRC_EvtReport_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5F38, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_REDUMP() do {\
		if(UL1C_PRI1_Trace_Filter[0]==1 && (UL1C_PRI1_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6038, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_REDUMP()
#endif
#define UL1T_TRC_REDUMP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6038, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1C_PRI1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1I_TRC_CM_Obsolete(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1I_TRC_PS_TASFreqScanAnt(short v1);
void L1TRC_Send_UL1I_TRC_PS_Result(unsigned char v1);
void L1TRC_Send_UL1I_TRC_PS_SortedFreq(short v1, char v2);
void L1TRC_Send_UL1I_TRC_FS_Result(short v1, char v2);
void L1TRC_Send_UL1I_TRC_FS_State(char v1, char v2);
void L1TRC_Send_UL1I_TRC_FS_UL1_Suspend(char v1, char v2);
void L1TRC_Send_UL1T_TRC_FS_Start(char v1, char v2);
void L1TRC_Send_UL1T_TRC_FS_Cont(void);
void L1TRC_Send_UL1T_TRC_FS_Suspend(void);
void L1TRC_Send_UL1I_TRC_FS_FB_PwrScanNext(char v1, short v2);
void L1TRC_Send_UL1I_TRC_FS_AutoGap_State(long v1);
void L1TRC_Send_UL1I_TRC_FS_ScanSuspend(short v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_FS_ProcessScanStart(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_ECS_Start(short v1);
void L1TRC_Send_UL1T_TRC_ECS_Stop(void);
void L1TRC_Send_UL1I_TRC_ECS_InternalStop(void);
void L1TRC_Send_UL1I_TRC_ECS_Status(char v1);
void L1TRC_Send_UL1I_TRC_ECS_Result(short v1, char v2);
void L1TRC_Send_UL1I_TRC_FS_BeforeGetPendingResult(short v1, char v2, short v3, char v4, char v5);
void L1TRC_Send_UL1I_TRC_FS_AfterGetPendingResult(short v1, char v2, short v3, char v4, char v5);
void L1TRC_Send_UL1I_TRC_FS_AfterResume(short v1, char v2, short v3, char v4, char v5);
void L1TRC_Send_UL1I_TRC_HFS_DBG(short v1, short v2);
void L1TRC_Send_UL1I_TRC_HFS_DBG2(short v1, short v2);
void L1TRC_Send_UL1I_TRC_Get_ULDCHData(short v1, char v2, char v3, short v4, char v5);
void L1TRC_Send_UL1I_TRC_Get_ULDCHTRCHData(char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_StartULDCh(short v1, char v2);
void L1TRC_Send_UL1I_TRC_TxStatus(char v1);
void L1TRC_Send_UL1I_TRC_UL_Timer_TFC_CB(short v1);
void L1TRC_Send_UL1I_TRC_UL_Timer_Data_CB(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_Report_ULCB_Data(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_Report_ULCB_TFC(short v1);
void L1TRC_Send_UL1I_TRC_StopULDCh(void);
void L1TRC_Send_UL1I_TRC_ULDCH_next_timer_delay(char v1);
void L1TRC_Send_UL1I_TRC_ULDCH_UL1D_Intf(char v1);
void L1TRC_Send_UL1I_TRC_ULDCH_Set_MAC_Event(char v1);
void L1TRC_Send_UL1I_TRC_Get_DLDCHData(short v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_Get_DLDCHTRCHData(char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_RefDCH(char v1);
void L1TRC_Send_UL1I_TRC_RefDCHCFN(long v1, short v2);
void L1TRC_Send_UL1I_TRC_DLSync_State(char v1);
void L1TRC_Send_UL1I_TRC_DLSync_Qin(short v1, short v2);
void L1TRC_Send_UL1I_TRC_New_DPCH_Type(char v1, char v2);
void L1TRC_Send_UL1I_TRC_DPCH_Type(char v1);
void L1TRC_Send_UL1T_TRC_ReconfigDCH(short v1, short v2, char v3, char v4, char v5, short v6, char v7);
void L1TRC_Send_UL1T_TRC_ReconfigDCH_ASAP(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_LoopMode2(short v1, short v2, char v3);
void L1TRC_Send_UL1T_TRC_ASU(short v1, short v2, char v3, char v4, short v5);
void L1TRC_Send_UL1I_TRC_DL_DCHQual(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1I_TRC_DL_CRC_Value(unsigned long v1);
void L1TRC_Send_UL1I_TRC_DL_Sync_Type(short v1, short v2);
void L1TRC_Send_UL1I_TRC_DL_Sync_Info(char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_DLSync_Config(char v1, char v2);
void L1TRC_Send_UL1T_TRC_ReconfigDCH_TTI(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1T_TRC_ReconfigDCH_TGPS(short v1, short v2);
void L1TRC_Send_UL1T_TRC_Modify_Abort(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1I_TRC_UpdateDpchRl(short v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_FMO(char v1);
void L1TRC_Send_UL1T_TRC_FMO_Config(char v1, char v2, char v3, short v4, char v5, char v6);
void L1TRC_Send_UL1I_TRC_FACH_Data(short v1);
void L1TRC_Send_UL1I_TRC_DRX_GAP(char v1, char v2, char v3);
void L1TRC_Send_UL1T_TRC_SCS_Start(short v1, short v2, char v3, char v4);
void L1TRC_Send_UL1T_TRC_SCS_Stop(void);
void L1TRC_Send_UL1I_TRC_SCS_State(char v1, char v2);
void L1TRC_Send_UL1I_TRC_SCS_Result(short v1);
void L1TRC_Send_UL1I_TRC_SCS_Conflict(short v1, short v2);
void L1TRC_Send_UL1I_TRC_MBSCS_ResourceConflict(short v1);
void L1TRC_Send_UL1I_TRC_MBSCS_Resource(short v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_SCS_Init(void);
void L1TRC_Send_UL1I_TRC_PCH_Status(char v1);
void L1TRC_Send_UL1T_TRC_ReconfigPCH(short v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_PCH_drx_cycle2_life(short v1);
void L1TRC_Send_UL1I_TRC_PCH_SmartPagingState(char v1, short v2);
void L1TRC_Send_UL1I_TRC_PCH_SmartPagingLog(char v1, char v2, short v3, short v4, short v5, char v6, short v7, short v8);
void L1TRC_Send_UL1I_TRC_PCH_SmartCSState(char v1);
void L1TRC_Send_UL1T_TRC_PCH_SmartCSLog(char v1, char v2, short v3, short v4, short v5, char v6, short v7, short v8, short v9);
void L1TRC_Send_UL1I_TRC_PCH_SmartCSSkip(char v1);
void L1TRC_Send_UL1I_TRC_PCH_RxDEnSkip(short v1);
void L1TRC_Send_UL1I_TRC_PCH_RxDEn(short v1);
void L1TRC_Send_UL1I_TRC_PCH_RxDSwitchDelay(short v1);
void L1TRC_Send_UL1I_TRC_PCH_RxDEcnoRscp(short v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_PCH_RxDServingInfo(short v1, short v2);
void L1TRC_Send_UL1I_TRC_PCH_TASEvaluate(short v1);
void L1TRC_Send_UL1I_TRC_PCH_TASProcOngoing(void);
void L1TRC_Send_UL1I_TRC_PCH_TASStartTimer(short v1);
void L1TRC_Send_UL1I_TRC_PCH_TASTriggerUnsync(short v1);
void L1TRC_Send_UL1T_TRC_TxAccess(short v1, char v2);
void L1TRC_Send_UL1T_TRC_RAChData(short v1, short v2, char v3, short v4, short v5);
void L1TRC_Send_UL1I_TRC_RACH_ASCSetting(short v1, short v2);
void L1TRC_Send_UL1I_TRC_Get_Access_Slot(char v1, short v2, char v3, char v4, char v5);
void L1TRC_Send_UL1I_TRC_RACH_Start(long v1);
void L1TRC_Send_UL1T_TRC_RACH_NextASS(short v1, long v2);
void L1TRC_Send_UL1I_TRC_TxAccess(char v1, long v2, char v3, short v4);
void L1TRC_Send_UL1I_TRC_DelayTxAccess_CCM(char v1, short v2, short v3, long v4);
void L1TRC_Send_UL1I_TRC_DelayTxAccess_FMO(short v1, short v2, long v3);
void L1TRC_Send_UL1AC_TRC_EvtReport(char v1);
void L1TRC_Send_UL1T_TRC_REDUMP(void);

void Set_UL1C_PRI1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1C_PRI1()	(UL1C_PRI1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_CM_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_FACH_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_RPT_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_ERROR_L()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_M()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_M()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_CM_M()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_M()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_M()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_M()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_FACH_M()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_M()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_RPT_M()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_H()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_CM_H()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_FACH_H()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[4]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[4]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI1_UL1C_RPT_H()	(ChkL1ModFltr_UL1C_PRI1()&&((UL1C_PRI1_Trace_Filter[4]&0x08)!=0))
#define ChkL1MsgFltr_UL1I_TRC_CM_Obsolete()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_PS_TASFreqScanAnt()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_PS_Result()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_PS_SortedFreq()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_Result()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_State()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_UL1_Suspend()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1T_TRC_FS_Start()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1T_TRC_FS_Cont()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1T_TRC_FS_Suspend()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_FB_PwrScanNext()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_AutoGap_State()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_ScanSuspend()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_ProcessScanStart()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1T_TRC_ECS_Start()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1T_TRC_ECS_Stop()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_ECS_InternalStop()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_ECS_Status()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_ECS_Result()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_BeforeGetPendingResult()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_AfterGetPendingResult()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_FS_AfterResume()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_HFS_DBG()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_HFS_DBG2()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FS_H()
#define ChkL1MsgFltr_UL1I_TRC_Get_ULDCHData()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Get_ULDCHTRCHData()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_StartULDCh()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_TxStatus()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_UL_Timer_TFC_CB()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_UL_Timer_Data_CB()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_Report_ULCB_Data()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_Report_ULCB_TFC()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_StopULDCh()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_ULDCH_next_timer_delay()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_ULDCH_UL1D_Intf()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_ULDCH_Set_MAC_Event()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ULDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Get_DLDCHData()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Get_DLDCHTRCHData()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_RefDCH()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_RefDCHCFN()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_DLSync_State()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_DLSync_Qin()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_New_DPCH_Type()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_DPCH_Type()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_ReconfigDCH()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_ReconfigDCH_ASAP()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_LoopMode2()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_ASU()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_DL_DCHQual()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_DL_CRC_Value()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_DL_Sync_Type()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_DL_Sync_Info()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_DLSync_Config()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_ReconfigDCH_TTI()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_ReconfigDCH_TGPS()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_Modify_Abort()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_UpdateDpchRl()	ChkL1ClsFltr_UL1C_PRI1_UL1C_DLDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_FMO()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FACH_H()
#define ChkL1MsgFltr_UL1T_TRC_FMO_Config()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FACH_H()
#define ChkL1MsgFltr_UL1I_TRC_FACH_Data()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FACH_H()
#define ChkL1MsgFltr_UL1I_TRC_DRX_GAP()	ChkL1ClsFltr_UL1C_PRI1_UL1C_FACH_H()
#define ChkL1MsgFltr_UL1T_TRC_SCS_Start()	ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_H()
#define ChkL1MsgFltr_UL1T_TRC_SCS_Stop()	ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_H()
#define ChkL1MsgFltr_UL1I_TRC_SCS_State()	ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_H()
#define ChkL1MsgFltr_UL1I_TRC_SCS_Result()	ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_H()
#define ChkL1MsgFltr_UL1I_TRC_SCS_Conflict()	ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_H()
#define ChkL1MsgFltr_UL1I_TRC_MBSCS_ResourceConflict()	ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_H()
#define ChkL1MsgFltr_UL1I_TRC_MBSCS_Resource()	ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_H()
#define ChkL1MsgFltr_UL1I_TRC_SCS_Init()	ChkL1ClsFltr_UL1C_PRI1_UL1C_SCS_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_Status()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1T_TRC_ReconfigPCH()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_drx_cycle2_life()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_SmartPagingState()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_SmartPagingLog()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_SmartCSState()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1T_TRC_PCH_SmartCSLog()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_SmartCSSkip()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_RxDEnSkip()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_RxDEn()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_RxDSwitchDelay()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_RxDEcnoRscp()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_RxDServingInfo()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_TASEvaluate()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_TASProcOngoing()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_TASStartTimer()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1I_TRC_PCH_TASTriggerUnsync()	ChkL1ClsFltr_UL1C_PRI1_UL1C_PCH_H()
#define ChkL1MsgFltr_UL1T_TRC_TxAccess()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()
#define ChkL1MsgFltr_UL1T_TRC_RAChData()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()
#define ChkL1MsgFltr_UL1I_TRC_RACH_ASCSetting()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()
#define ChkL1MsgFltr_UL1I_TRC_Get_Access_Slot()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()
#define ChkL1MsgFltr_UL1I_TRC_RACH_Start()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()
#define ChkL1MsgFltr_UL1T_TRC_RACH_NextASS()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()
#define ChkL1MsgFltr_UL1I_TRC_TxAccess()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()
#define ChkL1MsgFltr_UL1I_TRC_DelayTxAccess_CCM()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()
#define ChkL1MsgFltr_UL1I_TRC_DelayTxAccess_FMO()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RACH_H()
#define ChkL1MsgFltr_UL1AC_TRC_EvtReport()	ChkL1ClsFltr_UL1C_PRI1_UL1C_RPT_H()
#define ChkL1MsgFltr_UL1T_TRC_REDUMP()	ChkL1ClsFltr_UL1C_PRI1_UL1C_ERROR_L()


#endif
