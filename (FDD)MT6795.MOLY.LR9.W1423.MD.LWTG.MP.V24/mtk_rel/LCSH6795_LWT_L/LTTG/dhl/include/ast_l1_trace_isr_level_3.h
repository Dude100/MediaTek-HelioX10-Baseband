#ifndef L1TRC_AST_L1_Trace_ISR_Context_Group3_DEF_H
#define L1TRC_AST_L1_Trace_ISR_Context_Group3_DEF_H

/******************************/
/* String category definition */
/******************************/
#define Str_Bool(v1)  (unsigned char)(v1+0)
#define Str_Standby_Task_Status(v1)  (unsigned char)(v1+2)
#define Str_Standby_Task_Name(v1)  (unsigned char)(v1+6)
#define Str_Standby_Task_Schedule_Result(v1)  (unsigned char)(v1+10)
#define Str_Standby_Meas_Task_Status(v1)  (unsigned char)(v1+18)
#define Str_Standby_Fscs_Task_Status(v1)  (unsigned char)(v1+25)
#define Str_Standby_Bch_Task_Status(v1)  (unsigned char)(v1+31)
#define Str_TL1_Standby_Suspend_State(v1)  (unsigned char)(v1+34)
#define Str_TL1_Standby_Gap_State(v1)  (unsigned char)(v1+37)
#define Str_TL1_Standby_Auto_Suspend_Norm_State(v1)  (unsigned char)(v1+41)
#define Str_TL1_Standby_Auto_Gap_State(v1)  (unsigned char)(v1+43)
#define Str_TL1Data_Msg_Id(v1)  (unsigned char)(v1+47)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_TEST_MSG_1(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x003D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_TEST_MSG_1(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group3_TEST_MSG_1_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x003D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_TEST_MSG_2(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x013D, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_TEST_MSG_2(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group3_TEST_MSG_2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x013D, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_TEST_MSG_3(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x023D, (unsigned short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_TEST_MSG_3(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group3_TEST_MSG_3_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x023D, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_TASK_STATUS(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x033D, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_TASK_STATUS(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group3_STANDBY_TASK_STATUS_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x033D, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_TASK_SCHEDULE_RESULT(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x043D, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_TASK_SCHEDULE_RESULT(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group3_STANDBY_TASK_SCHEDULE_RESULT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x043D, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_TASK_LOCK_CNT(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x053D, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_TASK_LOCK_CNT(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group3_STANDBY_TASK_LOCK_CNT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x053D, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_FAKE_SCELL_INFO(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x063D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_FAKE_SCELL_INFO(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group3_STANDBY_FAKE_SCELL_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x063D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_FAKE_SCELL_RESEL(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x073D, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_FAKE_SCELL_RESEL(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group3_STANDBY_FAKE_SCELL_RESEL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x073D, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_TIMING_ADJ_INFO(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x083D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_TIMING_ADJ_INFO(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group3_STANDBY_TIMING_ADJ_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x083D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_AUTO_TIMING_ADJ_INFO(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x093D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_AUTO_TIMING_ADJ_INFO(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group3_STANDBY_AUTO_TIMING_ADJ_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x093D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning_Afc() do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning_Afc()
#endif
#define AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning_Afc_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning_Agc() do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning_Agc()
#endif
#define AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning_Agc_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning_Apc() do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning_Apc()
#endif
#define AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning_Apc_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_GAP_INDEX(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0D3D, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_GAP_INDEX(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group3_STANDBY_GAP_INDEX_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0D3D, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_RSCP_RSP_DETECT_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x0E3D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_1S2C((short)(v14), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_RSCP_RSP_DETECT_INFO(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14)
#endif
#define AST_L1_Trace_ISR_Context_Group3_RSCP_RSP_DETECT_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14) TRC_SEND_8_DATA(TRC_MERGE_2S(0x0E3D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_1S2C((short)(v14), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_LOCK_LAST_SUBFRAME(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0F3D, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_LOCK_LAST_SUBFRAME(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group3_LOCK_LAST_SUBFRAME_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0F3D, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_AVAI_SFN_ECHIP_INFO(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x103D, (short)(v3)), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_AVAI_SFN_ECHIP_INFO(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group3_AVAI_SFN_ECHIP_INFO_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x103D, (short)(v3)), (long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_AUTO_AVAI_SFN_ECHIP_INFO(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x113D, (short)(v3)), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_AUTO_AVAI_SFN_ECHIP_INFO(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group3_AUTO_AVAI_SFN_ECHIP_INFO_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x113D, (short)(v3)), (long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_AUTO_END_SFN_ECHIP_INFO(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x123D, (short)(v3)), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_AUTO_END_SFN_ECHIP_INFO(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group3_AUTO_END_SFN_ECHIP_INFO_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x123D, (short)(v3)), (long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_TIM_ALIGN_GAP_CALC_INFO(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x133D, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_TIM_ALIGN_GAP_CALC_INFO(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group3_TIM_ALIGN_GAP_CALC_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x133D, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_TIM_ALIGN_AUTO_GAP_CALC_INFO(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x143D, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_TIM_ALIGN_AUTO_GAP_CALC_INFO(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group3_TIM_ALIGN_AUTO_GAP_CALC_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x143D, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_AUTO_GAP_TO_LL1_INFO(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x153D, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_AUTO_GAP_TO_LL1_INFO(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group3_AUTO_GAP_TO_LL1_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x153D, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_GAP_AVAIABLE_CHECK_INFO(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x163D, (short)(v5)), (long)(v1), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_GAP_AVAIABLE_CHECK_INFO(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group3_GAP_AVAIABLE_CHECK_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x163D, (short)(v5)), (long)(v1), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_MEAS_TASK_STATUS(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x173D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_MEAS_TASK_STATUS(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group3_MEAS_TASK_STATUS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x173D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_FSCS_TASK_STATUS(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x183D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_FSCS_TASK_STATUS(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group3_FSCS_TASK_STATUS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x183D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_BCH_TASK_STATUS(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x193D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_BCH_TASK_STATUS(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group3_BCH_TASK_STATUS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x193D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_EN_SLEEP() do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_EN_SLEEP()
#endif
#define AST_L1_Trace_ISR_Context_Group3_EN_SLEEP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_DISEN_SLEEP() do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_DISEN_SLEEP()
#endif
#define AST_L1_Trace_ISR_Context_Group3_DISEN_SLEEP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_GAUGING() do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_GAUGING()
#endif
#define AST_L1_Trace_ISR_Context_Group3_GAUGING_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_SLEEP() do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_SLEEP()
#endif
#define AST_L1_Trace_ISR_Context_Group3_SLEEP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D3D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_MEAS_SAVE_FSCS(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1E3D, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_MEAS_SAVE_FSCS(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group3_MEAS_SAVE_FSCS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1E3D, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_CS_RX_BCH_SUSPEND(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1F3D, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_CS_RX_BCH_SUSPEND(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group3_CS_RX_BCH_SUSPEND_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1F3D, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_SEND_TASK_MSG(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x203D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_SEND_TASK_MSG(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group3_SEND_TASK_MSG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x203D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_SUSPEND_STATE(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x213D, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_SUSPEND_STATE(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group3_SUSPEND_STATE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x213D, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_AUTO_SUSPEND_NORM_STATE(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x223D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_AUTO_SUSPEND_NORM_STATE(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group3_AUTO_SUSPEND_NORM_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x223D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_GAP_STATE(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x233D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_GAP_STATE(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group3_STANDBY_GAP_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x233D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_AUTO_GAP_STATE(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x243D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group3_STANDBY_AUTO_GAP_STATE(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group3_STANDBY_AUTO_GAP_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x243D, (unsigned char)(v1), TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char AST_L1_Trace_ISR_Context_Group3_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_TEST_MSG_1(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_TEST_MSG_2(char v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_TEST_MSG_3(unsigned short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_STANDBY_TASK_STATUS(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_STANDBY_TASK_SCHEDULE_RESULT(unsigned char v1, unsigned char v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_STANDBY_TASK_LOCK_CNT(unsigned char v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_STANDBY_FAKE_SCELL_INFO(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_STANDBY_FAKE_SCELL_RESEL(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_STANDBY_TIMING_ADJ_INFO(short v1, short v2, long v3, long v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_STANDBY_AUTO_TIMING_ADJ_INFO(short v1, short v2, long v3, long v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning_Afc(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning_Agc(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning_Apc(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_STANDBY_GAP_INDEX(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_RSCP_RSP_DETECT_INFO(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_LOCK_LAST_SUBFRAME(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_AVAI_SFN_ECHIP_INFO(long v1, long v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_AUTO_AVAI_SFN_ECHIP_INFO(long v1, long v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_AUTO_END_SFN_ECHIP_INFO(long v1, long v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_TIM_ALIGN_GAP_CALC_INFO(short v1, long v2, short v3, long v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_TIM_ALIGN_AUTO_GAP_CALC_INFO(short v1, long v2, short v3, long v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_AUTO_GAP_TO_LL1_INFO(short v1, long v2, short v3, long v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_GAP_AVAIABLE_CHECK_INFO(long v1, long v2, long v3, long v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_MEAS_TASK_STATUS(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_FSCS_TASK_STATUS(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_BCH_TASK_STATUS(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_EN_SLEEP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_DISEN_SLEEP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_GAUGING(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_SLEEP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_MEAS_SAVE_FSCS(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_CS_RX_BCH_SUSPEND(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_SEND_TASK_MSG(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_SUSPEND_STATE(short v1, unsigned char v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_AUTO_SUSPEND_NORM_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_STANDBY_GAP_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group3_STANDBY_AUTO_GAP_STATE(unsigned char v1);

void Set_AST_L1_Trace_ISR_Context_Group3_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group3()	(AST_L1_Trace_ISR_Context_Group3_Trace_Filter[0]==1)
#define ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()	(ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group3()&&((AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_2()	(ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group3()&&((AST_L1_Trace_ISR_Context_Group3_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_TEST_MSG_1()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_TEST_MSG_2()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_TEST_MSG_3()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_STANDBY_TASK_STATUS()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_STANDBY_TASK_SCHEDULE_RESULT()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_STANDBY_TASK_LOCK_CNT()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_STANDBY_FAKE_SCELL_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_STANDBY_FAKE_SCELL_RESEL()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_STANDBY_TIMING_ADJ_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_STANDBY_AUTO_TIMING_ADJ_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning_Afc()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning_Agc()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_No_Cal_Data_Warning_Apc()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_STANDBY_GAP_INDEX()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_RSCP_RSP_DETECT_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_LOCK_LAST_SUBFRAME()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_AVAI_SFN_ECHIP_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_AUTO_AVAI_SFN_ECHIP_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_AUTO_END_SFN_ECHIP_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_TIM_ALIGN_GAP_CALC_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_TIM_ALIGN_AUTO_GAP_CALC_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_AUTO_GAP_TO_LL1_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_GAP_AVAIABLE_CHECK_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_MEAS_TASK_STATUS()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_FSCS_TASK_STATUS()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_BCH_TASK_STATUS()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_EN_SLEEP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_DISEN_SLEEP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_GAUGING()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_SLEEP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_MEAS_SAVE_FSCS()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_CS_RX_BCH_SUSPEND()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_SEND_TASK_MSG()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_SUSPEND_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_AUTO_SUSPEND_NORM_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_STANDBY_GAP_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group3_STANDBY_AUTO_GAP_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group3_TEST_CLASS_1()


#endif
