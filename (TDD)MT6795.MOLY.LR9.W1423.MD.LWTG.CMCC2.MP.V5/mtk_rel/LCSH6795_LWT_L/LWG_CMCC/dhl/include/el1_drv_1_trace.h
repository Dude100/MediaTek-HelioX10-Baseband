#ifndef L1TRC_EL1_DRV_1_DEF_H
#define L1TRC_EL1_DRV_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define DRV_String(v1)  (unsigned char)(v1+0)
#define DRV_DSP_ACT_String(v1)  (unsigned char)(v1+113)
#define DRV_Caller_String(v1)  (unsigned char)(v1+116)
#define DRV_Dynm_Id_String(v1)  (unsigned char)(v1+123)
#define DRV_Presch_MId_String(v1)  (unsigned char)(v1+137)
#define DRV_Send_Msg_String(v1)  (unsigned char)(v1+146)
#define DRV_Param_Type_String(v1)  (unsigned char)(v1+171)
#define DRV_Phy_Track_String(v1)  (unsigned char)(v1+186)
#define DRV_BW_String(v1)  (unsigned char)(v1+190)
#define DRV_MIB_TYPE_String(v1)  (unsigned char)(v1+198)
#define DRV_RS_String(v1)  (unsigned char)(v1+202)
#define DRV_RNTI_String0(v1)  (unsigned char)(v1+218)
#define DRV_RNTI_String1(v1)  (unsigned char)(v1+234)
#define DRV_RNTI_String2(v1)  (unsigned char)(v1+242)
#define DRV_RECAL_Str(v1)  (unsigned char)(v1+250)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_FUNC_CALL(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0004, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_FUNC_CALL(v1)
#endif
#define DRV_LOG_FUNC_CALL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0004, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_FUNC_CALL_ISR(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0104, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_FUNC_CALL_ISR(v1)
#endif
#define DRV_LOG_FUNC_CALL_ISR_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0104, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_MSG_SND(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0204, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_MSG_SND(v1)
#endif
#define DRV_LOG_MSG_SND_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0204, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_RSXX_RPT(v1, v2, v3, v4) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0304, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_RSXX_RPT(v1, v2, v3, v4)
#endif
#define DRV_LOG_RSXX_RPT_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0304, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_CELL_TIME_RPT(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0404, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_CELL_TIME_RPT(v1, v2)
#endif
#define DRV_LOG_CELL_TIME_RPT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0404, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PHY_TIME_RPT(v1, v2, v3, v4, v5) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0504, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v5));\
	} while(0)
#else
	#define DRV_LOG_PHY_TIME_RPT(v1, v2, v3, v4, v5)
#endif
#define DRV_LOG_PHY_TIME_RPT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0504, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_ABS_TIME_RPT(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0604, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define DRV_LOG_ABS_TIME_RPT(v1, v2)
#endif
#define DRV_LOG_ABS_TIME_RPT_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0604, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_CELL_TIMING_CHG() do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0704, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_CELL_TIMING_CHG()
#endif
#define DRV_LOG_CELL_TIMING_CHG_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0704, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_FLOW_STRING(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0804, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_FLOW_STRING(v1)
#endif
#define DRV_LOG_FLOW_STRING_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0804, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_UPDT_DL_SYNC_TIME(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0904, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_UPDT_DL_SYNC_TIME(v1, v2)
#endif
#define DRV_LOG_UPDT_DL_SYNC_TIME_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0904, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_HW_TIME_RPT(v1, v2, v3, v4, v5) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0A04, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define DRV_LOG_HW_TIME_RPT(v1, v2, v3, v4, v5)
#endif
#define DRV_LOG_HW_TIME_RPT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0A04, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_FRC_TIME(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B04, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define DRV_LOG_FRC_TIME(v1)
#endif
#define DRV_LOG_FRC_TIME_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B04, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_UL_SYS_PARAM(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C04, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_UL_SYS_PARAM(v1, v2)
#endif
#define DRV_LOG_UL_SYS_PARAM_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C04, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_ST_MEAS_MEAS(v1, v2, v3) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D04, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_ST_MEAS_MEAS(v1, v2, v3)
#endif
#define DRV_LOG_ST_MEAS_MEAS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D04, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_ST_MEAS_CH(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E04, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_ST_MEAS_CH(v1)
#endif
#define DRV_LOG_ST_MEAS_CH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E04, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_ST_MEAS_ON_DUR(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F04, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_ST_MEAS_ON_DUR(v1, v2)
#endif
#define DRV_LOG_ST_MEAS_ON_DUR_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F04, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_ST_ADD_ON_DUR(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1004, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_ST_ADD_ON_DUR(v1, v2)
#endif
#define DRV_LOG_ST_ADD_ON_DUR_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1004, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_ST_RLQ_MONITOR(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1104, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_ST_RLQ_MONITOR(v1)
#endif
#define DRV_LOG_ST_RLQ_MONITOR_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1104, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_ST_MEAS_PHS(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1204, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_ST_MEAS_PHS(v1)
#endif
#define DRV_LOG_ST_MEAS_PHS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1204, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PHY_TRACE_STATUS(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1304, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PHY_TRACE_STATUS(v1, v2)
#endif
#define DRV_LOG_PHY_TRACE_STATUS_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1304, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_RNTI_STATUS(v1, v2, v3, v4) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1404, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_RNTI_STATUS(v1, v2, v3, v4)
#endif
#define DRV_LOG_RNTI_STATUS_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1404, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_MIB_PARAM(v1, v2, v3, v4, v5) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1504, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (char)(v4)));\
	} while(0)
#else
	#define DRV_LOG_MIB_PARAM(v1, v2, v3, v4, v5)
#endif
#define DRV_LOG_MIB_PARAM_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1504, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_SI_PARAM(v1, v2, v3, v4, v5) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1604, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define DRV_LOG_SI_PARAM(v1, v2, v3, v4, v5)
#endif
#define DRV_LOG_SI_PARAM_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1604, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_MIB_RPT(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1704, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_MIB_RPT(v1)
#endif
#define DRV_LOG_MIB_RPT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1704, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_SI_RPT(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1804, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_SI_RPT(v1)
#endif
#define DRV_LOG_SI_RPT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1804, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PI_RPT(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1904, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define DRV_LOG_PI_RPT(v1, v2)
#endif
#define DRV_LOG_PI_RPT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1904, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_DL_SYNC_PARAM1(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A04, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define DRV_LOG_DL_SYNC_PARAM1(v1, v2, v3, v4, v5, v6)
#endif
#define DRV_LOG_DL_SYNC_PARAM1_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A04, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_DL_SYNC_PARAM2(v1, v2, v3) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B04, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_DL_SYNC_PARAM2(v1, v2, v3)
#endif
#define DRV_LOG_DL_SYNC_PARAM2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B04, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_SET_SLEEP(v1, v2, v3, v4, v5) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1C04, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)));\
	} while(0)
#else
	#define DRV_LOG_SET_SLEEP(v1, v2, v3, v4, v5)
#endif
#define DRV_LOG_SET_SLEEP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1C04, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_DCI_DROP(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D04, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define DRV_LOG_DCI_DROP(v1, v2, v3, v4, v5, v6)
#endif
#define DRV_LOG_DCI_DROP_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D04, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_MBSFN_CAL(v1, v2, v3) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E04, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_MBSFN_CAL(v1, v2, v3)
#endif
#define DRV_LOG_MBSFN_CAL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E04, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_AFC_DAC_TRIG() do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F04, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_AFC_DAC_TRIG()
#endif
#define DRV_LOG_AFC_DAC_TRIG_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F04, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_RNTI_CTRL_PARAM1(v1, v2, v3, v4, v5) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2004, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_RNTI_CTRL_PARAM1(v1, v2, v3, v4, v5)
#endif
#define DRV_LOG_RNTI_CTRL_PARAM1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2004, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v2), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PRESCH_CMD_HDR(v1, v2, v3, v4, v5) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2104, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v5)));\
	} while(0)
#else
	#define DRV_LOG_PRESCH_CMD_HDR(v1, v2, v3, v4, v5)
#endif
#define DRV_LOG_PRESCH_CMD_HDR_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2104, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PRESCH_RPT_HDR(v1, v2, v3) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2204, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PRESCH_RPT_HDR(v1, v2, v3)
#endif
#define DRV_LOG_PRESCH_RPT_HDR_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2204, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PHY_TRACK(v1, v2, v3, v4, v5) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2304, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PHY_TRACK(v1, v2, v3, v4, v5)
#endif
#define DRV_LOG_PHY_TRACK_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2304, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_DRX_GAP_IND(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2404, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_DRX_GAP_IND(v1, v2)
#endif
#define DRV_LOG_DRX_GAP_IND_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2404, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_FORCE_RS_CTRL(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2504, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_FORCE_RS_CTRL(v1, v2)
#endif
#define DRV_LOG_FORCE_RS_CTRL_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2504, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_TA_ADJ(v1, v2, v3, v4, v5) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2604, (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_TA_ADJ(v1, v2, v3, v4, v5)
#endif
#define DRV_LOG_TA_ADJ_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2604, (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_DL_SPS_RCV(v1, v2, v3, v4) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2704, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_DL_SPS_RCV(v1, v2, v3, v4)
#endif
#define DRV_LOG_DL_SPS_RCV_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2704, (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_OPTN_MODE(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2804, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define DRV_LOG_OPTN_MODE(v1, v2, v3, v4, v5, v6)
#endif
#define DRV_LOG_OPTN_MODE_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2804, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_AFCDAC_VALUE(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2904, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_AFCDAC_VALUE(v1, v2)
#endif
#define DRV_LOG_AFCDAC_VALUE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2904, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_CFN_TYPE(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A04, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define DRV_LOG_CFN_TYPE(v1, v2)
#endif
#define DRV_LOG_CFN_TYPE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A04, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_CELL_TBL_GET(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B04, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_CELL_TBL_GET(v1, v2)
#endif
#define DRV_LOG_CELL_TBL_GET_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B04, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_CELL_TBL_SET(v1, v2, v3) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C04, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_CELL_TBL_SET(v1, v2, v3)
#endif
#define DRV_LOG_CELL_TBL_SET_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C04, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_CELL_TBL_CLEAR(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D04, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define DRV_LOG_CELL_TBL_CLEAR(v1, v2)
#endif
#define DRV_LOG_CELL_TBL_CLEAR_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D04, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_RAT_CHNG(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E04, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_RAT_CHNG(v1)
#endif
#define DRV_LOG_RAT_CHNG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E04, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_DL_REL(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2F04, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define DRV_LOG_DL_REL(v1, v2)
#endif
#define DRV_LOG_DL_REL_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2F04, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_SRV_INFO_GET(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3004, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_SRV_INFO_GET(v1)
#endif
#define DRV_LOG_SRV_INFO_GET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3004, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_DYNM_CMD_HDR(v1, v2, v3) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3104, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_DYNM_CMD_HDR(v1, v2, v3)
#endif
#define DRV_LOG_DYNM_CMD_HDR_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3104, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_DYNM_RPT_HDR(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3204, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define DRV_LOG_DYNM_RPT_HDR(v1, v2)
#endif
#define DRV_LOG_DYNM_RPT_HDR_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3204, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_RX_PATH_W(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3304, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define DRV_LOG_RX_PATH_W(v1, v2)
#endif
#define DRV_LOG_RX_PATH_W_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3304, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_RX_PATH_R(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3404, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define DRV_LOG_RX_PATH_R(v1, v2)
#endif
#define DRV_LOG_RX_PATH_R_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3404, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PHS_TRACK_TIME(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3504, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PHS_TRACK_TIME(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define DRV_LOG_PHS_TRACK_TIME_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x3504, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10)), TRC_MERGE_4C((unsigned char)(v11), (unsigned char)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_TX_PATH(v1, v2, v3) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3604, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_TX_PATH(v1, v2, v3)
#endif
#define DRV_LOG_TX_PATH_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3604, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_SET_PCTI(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3704, (unsigned short)(v1)));\
	} while(0)
#else
	#define DRV_LOG_SET_PCTI(v1)
#endif
#define DRV_LOG_SET_PCTI_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3704, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PCTI_RPT(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3804, (unsigned short)(v1)));\
	} while(0)
#else
	#define DRV_LOG_PCTI_RPT(v1)
#endif
#define DRV_LOG_PCTI_RPT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3804, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_AFC_DAC(v1, v2, v3, v4) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3904, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_AFC_DAC(v1, v2, v3, v4)
#endif
#define DRV_LOG_AFC_DAC_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3904, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_RX_CTRL(v1, v2, v3, v4, v5) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3A04, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_RX_CTRL(v1, v2, v3, v4, v5)
#endif
#define DRV_LOG_RX_CTRL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3A04, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_RNTI_CTRL_PARAM2(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3B04, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_RNTI_CTRL_PARAM2(v1, v2, v3, v4, v5, v6)
#endif
#define DRV_LOG_RNTI_CTRL_PARAM2_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3B04, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_RNTI_CTRL_PARAM3(v1, v2, v3, v4, v5) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3C04, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_RNTI_CTRL_PARAM3(v1, v2, v3, v4, v5)
#endif
#define DRV_LOG_RNTI_CTRL_PARAM3_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3C04, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_RNTI_CTRL_PARAM4(v1, v2, v3, v4, v5) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3D04, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)));\
	} while(0)
#else
	#define DRV_LOG_RNTI_CTRL_PARAM4(v1, v2, v3, v4, v5)
#endif
#define DRV_LOG_RNTI_CTRL_PARAM4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3D04, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_RNTI_CTRL_PARAM5(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3E04, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v6), (unsigned char)(v2), (unsigned char)(v5)));\
	} while(0)
#else
	#define DRV_LOG_RNTI_CTRL_PARAM5(v1, v2, v3, v4, v5, v6)
#endif
#define DRV_LOG_RNTI_CTRL_PARAM5_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3E04, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v6), (unsigned char)(v2), (unsigned char)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_RNTI_CTRL_PARAM6(v1, v2, v3, v4) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3F04, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_RNTI_CTRL_PARAM6(v1, v2, v3, v4)
#endif
#define DRV_LOG_RNTI_CTRL_PARAM6_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3F04, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_RNTI_CTRL_PARAM7(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4004, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_RNTI_CTRL_PARAM7(v1, v2)
#endif
#define DRV_LOG_RNTI_CTRL_PARAM7_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4004, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PDSCH_RPT(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4104, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PDSCH_RPT(v1, v2, v3, v4, v5, v6, v7)
#endif
#define DRV_LOG_PDSCH_RPT_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4104, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PRESCH_CMD_PARAM(v1, v2, v3, v4, v5) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4204, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PRESCH_CMD_PARAM(v1, v2, v3, v4, v5)
#endif
#define DRV_LOG_PRESCH_CMD_PARAM_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4204, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_TEST_SIM() do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4304, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_TEST_SIM()
#endif
#define DRV_LOG_TEST_SIM_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4304, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_TEST_SIM_STATUS(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4404, (unsigned short)(v1)));\
	} while(0)
#else
	#define DRV_LOG_TEST_SIM_STATUS(v1)
#endif
#define DRV_LOG_TEST_SIM_STATUS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4404, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_BEF_R_BUFF_INDX(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4504, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_BEF_R_BUFF_INDX(v1)
#endif
#define DRV_LOG_BEF_R_BUFF_INDX_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4504, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_AFT_R_BUFF_INDX(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4604, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_AFT_R_BUFF_INDX(v1)
#endif
#define DRV_LOG_AFT_R_BUFF_INDX_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4604, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_RA_RNTI(v1, v2, v3, v4) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4704, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_RA_RNTI(v1, v2, v3, v4)
#endif
#define DRV_LOG_RA_RNTI_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4704, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_TC_RNTI(v1, v2, v3) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4804, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_TC_RNTI(v1, v2, v3)
#endif
#define DRV_LOG_TC_RNTI_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4804, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PARAM_1(v1, v2) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4904, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PARAM_1(v1, v2)
#endif
#define DRV_LOG_PARAM_1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4904, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PARAM_2(v1, v2, v3) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4A04, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PARAM_2(v1, v2, v3)
#endif
#define DRV_LOG_PARAM_2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4A04, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PARAM_3(v1, v2, v3, v4) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4B04, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PARAM_3(v1, v2, v3, v4)
#endif
#define DRV_LOG_PARAM_3_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4B04, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PARAM_4(v1, v2, v3, v4, v5) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4C04, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PARAM_4(v1, v2, v3, v4, v5)
#endif
#define DRV_LOG_PARAM_4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4C04, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PARAM_5(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x4D04, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PARAM_5(v1, v2, v3, v4, v5, v6)
#endif
#define DRV_LOG_PARAM_5_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x4D04, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PARAM_6(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x4E04, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PARAM_6(v1, v2, v3, v4, v5, v6, v7)
#endif
#define DRV_LOG_PARAM_6_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x4E04, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PARAM_7(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x4F04, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PARAM_7(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define DRV_LOG_PARAM_7_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x4F04, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PARAM_8(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x5004, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_1S2C((unsigned short)(v9), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PARAM_8(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define DRV_LOG_PARAM_8_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x5004, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_1S2C((unsigned short)(v9), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PARAM_FWS_DSP(v1, v2, v3, v4, v5) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5104, (short)(v2)), TRC_MERGE_2S((short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PARAM_FWS_DSP(v1, v2, v3, v4, v5)
#endif
#define DRV_LOG_PARAM_FWS_DSP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5104, (short)(v2)), TRC_MERGE_2S((short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PARAM_FWS(v1, v2, v3, v4, v5) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5204, (short)(v3)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PARAM_FWS(v1, v2, v3, v4, v5)
#endif
#define DRV_LOG_PARAM_FWS_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5204, (short)(v3)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PARAM_FWS_NEW(v1, v2, v3) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5304, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PARAM_FWS_NEW(v1, v2, v3)
#endif
#define DRV_LOG_PARAM_FWS_NEW_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5304, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PARAM_FWS_DBG(v1, v2, v3) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5404, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PARAM_FWS_DBG(v1, v2, v3)
#endif
#define DRV_LOG_PARAM_FWS_DBG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5404, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PAG_DUMP_SYNC_RPT(v1, v2, v3) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5504, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_PAG_DUMP_SYNC_RPT(v1, v2, v3)
#endif
#define DRV_LOG_PAG_DUMP_SYNC_RPT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x5504, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_PAG_DUMP_COUNT(v1, v2, v3) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5604, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define DRV_LOG_PAG_DUMP_COUNT(v1, v2, v3)
#endif
#define DRV_LOG_PAG_DUMP_COUNT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5604, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_SET_DRX_INACT(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5704, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_SET_DRX_INACT(v1)
#endif
#define DRV_SET_DRX_INACT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5704, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LAST_PDCCH_MONITOR(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5804, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LAST_PDCCH_MONITOR(v1)
#endif
#define DRV_LAST_PDCCH_MONITOR_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5804, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_CHK_PDCCH_IND(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5904, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_CHK_PDCCH_IND(v1)
#endif
#define DRV_CHK_PDCCH_IND_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5904, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LAST_PDCCH_NONE() do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5A04, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LAST_PDCCH_NONE()
#endif
#define DRV_LAST_PDCCH_NONE_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5A04, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_RECAL_FWS_TIME_ERROR(v1, v2, v3, v4) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x5B04, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define DRV_RECAL_FWS_TIME_ERROR(v1, v2, v3, v4)
#endif
#define DRV_RECAL_FWS_TIME_ERROR_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x5B04, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_RECAL_ALGO(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5C04, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_RECAL_ALGO(v1)
#endif
#define DRV_RECAL_ALGO_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5C04, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_DYNM_RECAL(v1, v2, v3, v4) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5D04, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define DRV_DYNM_RECAL(v1, v2, v3, v4)
#endif
#define DRV_DYNM_RECAL_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5D04, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_DYNM_ERROR() do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5E04, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_DYNM_ERROR()
#endif
#define DRV_LOG_DYNM_ERROR_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5E04, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_SET_TAS_CMD(v1) do {\
		if(EL1_DRV_1_Trace_Filter[0]==1 && (EL1_DRV_1_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5F04, (unsigned short)(v1)));\
	} while(0)
#else
	#define DRV_SET_TAS_CMD(v1)
#endif
#define DRV_SET_TAS_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5F04, (unsigned short)(v1)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1_DRV_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_DRV_LOG_FUNC_CALL(unsigned char v1);
void L1TRC_Send_DRV_LOG_FUNC_CALL_ISR(unsigned char v1);
void L1TRC_Send_DRV_LOG_MSG_SND(unsigned char v1);
void L1TRC_Send_DRV_LOG_RSXX_RPT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_DRV_LOG_CELL_TIME_RPT(unsigned short v1, unsigned char v2);
void L1TRC_Send_DRV_LOG_PHY_TIME_RPT(unsigned long v1, unsigned long v2, unsigned char v3, unsigned short v4, unsigned long v5);
void L1TRC_Send_DRV_LOG_ABS_TIME_RPT(unsigned long v1, unsigned long v2);
void L1TRC_Send_DRV_LOG_CELL_TIMING_CHG(void);
void L1TRC_Send_DRV_LOG_FLOW_STRING(unsigned char v1);
void L1TRC_Send_DRV_LOG_UPDT_DL_SYNC_TIME(unsigned short v1, unsigned char v2);
void L1TRC_Send_DRV_LOG_HW_TIME_RPT(unsigned long v1, unsigned char v2, unsigned short v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_DRV_LOG_FRC_TIME(unsigned long v1);
void L1TRC_Send_DRV_LOG_UL_SYS_PARAM(unsigned short v1, unsigned char v2);
void L1TRC_Send_DRV_LOG_ST_MEAS_MEAS(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_DRV_LOG_ST_MEAS_CH(unsigned char v1);
void L1TRC_Send_DRV_LOG_ST_MEAS_ON_DUR(unsigned char v1, unsigned short v2);
void L1TRC_Send_DRV_LOG_ST_ADD_ON_DUR(unsigned short v1, unsigned short v2);
void L1TRC_Send_DRV_LOG_ST_RLQ_MONITOR(unsigned char v1);
void L1TRC_Send_DRV_LOG_ST_MEAS_PHS(unsigned char v1);
void L1TRC_Send_DRV_LOG_PHY_TRACE_STATUS(unsigned char v1, unsigned short v2);
void L1TRC_Send_DRV_LOG_RNTI_STATUS(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_DRV_LOG_MIB_PARAM(unsigned char v1, unsigned char v2, char v3, char v4, short v5);
void L1TRC_Send_DRV_LOG_SI_PARAM(unsigned char v1, unsigned char v2, unsigned short v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_DRV_LOG_MIB_RPT(unsigned char v1);
void L1TRC_Send_DRV_LOG_SI_RPT(unsigned char v1);
void L1TRC_Send_DRV_LOG_PI_RPT(unsigned char v1, unsigned char v2);
void L1TRC_Send_DRV_LOG_DL_SYNC_PARAM1(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_DRV_LOG_DL_SYNC_PARAM2(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_DRV_LOG_SET_SLEEP(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_DRV_LOG_DCI_DROP(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_DRV_LOG_MBSFN_CAL(unsigned char v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_DRV_LOG_AFC_DAC_TRIG(void);
void L1TRC_Send_DRV_LOG_RNTI_CTRL_PARAM1(unsigned short v1, unsigned char v2, unsigned short v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_DRV_LOG_PRESCH_CMD_HDR(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4, unsigned char v5);
void L1TRC_Send_DRV_LOG_PRESCH_RPT_HDR(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_DRV_LOG_PHY_TRACK(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_DRV_LOG_DRX_GAP_IND(unsigned char v1, unsigned short v2);
void L1TRC_Send_DRV_LOG_FORCE_RS_CTRL(unsigned char v1, unsigned short v2);
void L1TRC_Send_DRV_LOG_TA_ADJ(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_DRV_LOG_DL_SPS_RCV(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_DRV_LOG_OPTN_MODE(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_DRV_LOG_AFCDAC_VALUE(unsigned char v1, unsigned short v2);
void L1TRC_Send_DRV_LOG_CFN_TYPE(unsigned char v1, unsigned char v2);
void L1TRC_Send_DRV_LOG_CELL_TBL_GET(unsigned short v1, unsigned char v2);
void L1TRC_Send_DRV_LOG_CELL_TBL_SET(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_DRV_LOG_CELL_TBL_CLEAR(unsigned char v1, unsigned char v2);
void L1TRC_Send_DRV_LOG_RAT_CHNG(unsigned char v1);
void L1TRC_Send_DRV_LOG_DL_REL(unsigned char v1, unsigned char v2);
void L1TRC_Send_DRV_LOG_SRV_INFO_GET(unsigned char v1);
void L1TRC_Send_DRV_LOG_DYNM_CMD_HDR(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_DRV_LOG_DYNM_RPT_HDR(unsigned char v1, unsigned char v2);
void L1TRC_Send_DRV_LOG_RX_PATH_W(unsigned char v1, unsigned char v2);
void L1TRC_Send_DRV_LOG_RX_PATH_R(unsigned char v1, unsigned char v2);
void L1TRC_Send_DRV_LOG_PHS_TRACK_TIME(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10, unsigned char v11, unsigned char v12);
void L1TRC_Send_DRV_LOG_TX_PATH(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_DRV_LOG_SET_PCTI(unsigned short v1);
void L1TRC_Send_DRV_LOG_PCTI_RPT(unsigned short v1);
void L1TRC_Send_DRV_LOG_AFC_DAC(unsigned short v1, unsigned short v2, short v3, unsigned short v4);
void L1TRC_Send_DRV_LOG_RX_CTRL(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_DRV_LOG_RNTI_CTRL_PARAM2(unsigned short v1, unsigned short v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned short v6);
void L1TRC_Send_DRV_LOG_RNTI_CTRL_PARAM3(unsigned short v1, unsigned short v2, unsigned short v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_DRV_LOG_RNTI_CTRL_PARAM4(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_DRV_LOG_RNTI_CTRL_PARAM5(unsigned short v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned char v5, unsigned short v6);
void L1TRC_Send_DRV_LOG_RNTI_CTRL_PARAM6(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_DRV_LOG_RNTI_CTRL_PARAM7(unsigned char v1, unsigned short v2);
void L1TRC_Send_DRV_LOG_PDSCH_RPT(unsigned short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_DRV_LOG_PRESCH_CMD_PARAM(unsigned char v1, unsigned short v2, unsigned char v3, unsigned short v4, unsigned char v5);
void L1TRC_Send_DRV_LOG_TEST_SIM(void);
void L1TRC_Send_DRV_LOG_TEST_SIM_STATUS(unsigned short v1);
void L1TRC_Send_DRV_LOG_BEF_R_BUFF_INDX(unsigned char v1);
void L1TRC_Send_DRV_LOG_AFT_R_BUFF_INDX(unsigned char v1);
void L1TRC_Send_DRV_LOG_RA_RNTI(unsigned char v1, unsigned short v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_DRV_LOG_TC_RNTI(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_DRV_LOG_PARAM_1(unsigned char v1, unsigned short v2);
void L1TRC_Send_DRV_LOG_PARAM_2(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_DRV_LOG_PARAM_3(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_DRV_LOG_PARAM_4(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_DRV_LOG_PARAM_5(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_DRV_LOG_PARAM_6(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7);
void L1TRC_Send_DRV_LOG_PARAM_7(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8);
void L1TRC_Send_DRV_LOG_PARAM_8(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9);
void L1TRC_Send_DRV_LOG_PARAM_FWS_DSP(unsigned char v1, short v2, short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_DRV_LOG_PARAM_FWS(unsigned char v1, unsigned char v2, short v3, unsigned char v4, short v5);
void L1TRC_Send_DRV_LOG_PARAM_FWS_NEW(unsigned char v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_DRV_LOG_PARAM_FWS_DBG(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_DRV_LOG_PAG_DUMP_SYNC_RPT(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_DRV_LOG_PAG_DUMP_COUNT(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_DRV_SET_DRX_INACT(unsigned char v1);
void L1TRC_Send_DRV_LAST_PDCCH_MONITOR(unsigned char v1);
void L1TRC_Send_DRV_CHK_PDCCH_IND(unsigned char v1);
void L1TRC_Send_DRV_LAST_PDCCH_NONE(void);
void L1TRC_Send_DRV_RECAL_FWS_TIME_ERROR(unsigned char v1, long v2, long v3, long v4);
void L1TRC_Send_DRV_RECAL_ALGO(unsigned char v1);
void L1TRC_Send_DRV_DYNM_RECAL(unsigned char v1, unsigned short v2, long v3, long v4);
void L1TRC_Send_DRV_LOG_DYNM_ERROR(void);
void L1TRC_Send_DRV_SET_TAS_CMD(unsigned short v1);

void Set_EL1_DRV_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1_DRV_1()	(EL1_DRV_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1_DRV_1_drv_func_trace()	(ChkL1ModFltr_EL1_DRV_1()&&((EL1_DRV_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1_DRV_1_drv_func_trace_1()	(ChkL1ModFltr_EL1_DRV_1()&&((EL1_DRV_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1_DRV_1_drv_func_trace_2()	(ChkL1ModFltr_EL1_DRV_1()&&((EL1_DRV_1_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1_DRV_1_drv_math_trace()	(ChkL1ModFltr_EL1_DRV_1()&&((EL1_DRV_1_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()	(ChkL1ModFltr_EL1_DRV_1()&&((EL1_DRV_1_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1_DRV_1_drv_var_trace_l()	(ChkL1ModFltr_EL1_DRV_1()&&((EL1_DRV_1_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1_DRV_1_drv_var_trace_2()	(ChkL1ModFltr_EL1_DRV_1()&&((EL1_DRV_1_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1_DRV_1_drv_flow_trace()	(ChkL1ModFltr_EL1_DRV_1()&&((EL1_DRV_1_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1_DRV_1_drv_flow_trace_1()	(ChkL1ModFltr_EL1_DRV_1()&&((EL1_DRV_1_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1_DRV_1_drv_flow_trace_2()	(ChkL1ModFltr_EL1_DRV_1()&&((EL1_DRV_1_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1_DRV_1_drv_error_trace()	(ChkL1ModFltr_EL1_DRV_1()&&((EL1_DRV_1_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1_DRV_1_drv_param_trace()	(ChkL1ModFltr_EL1_DRV_1()&&((EL1_DRV_1_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_EL1_DRV_1_drv_fws_trace()	(ChkL1ModFltr_EL1_DRV_1()&&((EL1_DRV_1_Trace_Filter[2]&0x10)!=0))
#define ChkL1MsgFltr_DRV_LOG_FUNC_CALL()	ChkL1ClsFltr_EL1_DRV_1_drv_func_trace_1()
#define ChkL1MsgFltr_DRV_LOG_FUNC_CALL_ISR()	ChkL1ClsFltr_EL1_DRV_1_drv_func_trace_1()
#define ChkL1MsgFltr_DRV_LOG_MSG_SND()	ChkL1ClsFltr_EL1_DRV_1_drv_func_trace_1()
#define ChkL1MsgFltr_DRV_LOG_RSXX_RPT()	ChkL1ClsFltr_EL1_DRV_1_drv_func_trace_1()
#define ChkL1MsgFltr_DRV_LOG_CELL_TIME_RPT()	ChkL1ClsFltr_EL1_DRV_1_drv_flow_trace()
#define ChkL1MsgFltr_DRV_LOG_PHY_TIME_RPT()	ChkL1ClsFltr_EL1_DRV_1_drv_flow_trace()
#define ChkL1MsgFltr_DRV_LOG_ABS_TIME_RPT()	ChkL1ClsFltr_EL1_DRV_1_drv_flow_trace()
#define ChkL1MsgFltr_DRV_LOG_CELL_TIMING_CHG()	ChkL1ClsFltr_EL1_DRV_1_drv_flow_trace()
#define ChkL1MsgFltr_DRV_LOG_FLOW_STRING()	ChkL1ClsFltr_EL1_DRV_1_drv_flow_trace()
#define ChkL1MsgFltr_DRV_LOG_UPDT_DL_SYNC_TIME()	ChkL1ClsFltr_EL1_DRV_1_drv_flow_trace()
#define ChkL1MsgFltr_DRV_LOG_HW_TIME_RPT()	ChkL1ClsFltr_EL1_DRV_1_drv_flow_trace_1()
#define ChkL1MsgFltr_DRV_LOG_FRC_TIME()	ChkL1ClsFltr_EL1_DRV_1_drv_flow_trace_1()
#define ChkL1MsgFltr_DRV_LOG_UL_SYS_PARAM()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_ST_MEAS_MEAS()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_ST_MEAS_CH()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_ST_MEAS_ON_DUR()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_ST_ADD_ON_DUR()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_ST_RLQ_MONITOR()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_ST_MEAS_PHS()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_PHY_TRACE_STATUS()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_RNTI_STATUS()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_MIB_PARAM()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_SI_PARAM()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_MIB_RPT()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_SI_RPT()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_PI_RPT()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_DL_SYNC_PARAM1()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_DL_SYNC_PARAM2()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_SET_SLEEP()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_DCI_DROP()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_MBSFN_CAL()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_AFC_DAC_TRIG()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_RNTI_CTRL_PARAM1()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_PRESCH_CMD_HDR()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_PRESCH_RPT_HDR()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_PHY_TRACK()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_DRX_GAP_IND()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_FORCE_RS_CTRL()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_TA_ADJ()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_DL_SPS_RCV()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_OPTN_MODE()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_AFCDAC_VALUE()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_CFN_TYPE()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_CELL_TBL_GET()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_CELL_TBL_SET()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_CELL_TBL_CLEAR()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_RAT_CHNG()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_DL_REL()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_SRV_INFO_GET()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_DYNM_CMD_HDR()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_DYNM_RPT_HDR()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_RX_PATH_W()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_RX_PATH_R()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_PHS_TRACK_TIME()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_TX_PATH()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_SET_PCTI()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_PCTI_RPT()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_AFC_DAC()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace_l()
#define ChkL1MsgFltr_DRV_LOG_RX_CTRL()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace_l()
#define ChkL1MsgFltr_DRV_LOG_RNTI_CTRL_PARAM2()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace_l()
#define ChkL1MsgFltr_DRV_LOG_RNTI_CTRL_PARAM3()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace_l()
#define ChkL1MsgFltr_DRV_LOG_RNTI_CTRL_PARAM4()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace_l()
#define ChkL1MsgFltr_DRV_LOG_RNTI_CTRL_PARAM5()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace_l()
#define ChkL1MsgFltr_DRV_LOG_RNTI_CTRL_PARAM6()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace_l()
#define ChkL1MsgFltr_DRV_LOG_RNTI_CTRL_PARAM7()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace_l()
#define ChkL1MsgFltr_DRV_LOG_PDSCH_RPT()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace_l()
#define ChkL1MsgFltr_DRV_LOG_PRESCH_CMD_PARAM()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace_l()
#define ChkL1MsgFltr_DRV_LOG_TEST_SIM()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_TEST_SIM_STATUS()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_BEF_R_BUFF_INDX()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace_2()
#define ChkL1MsgFltr_DRV_LOG_AFT_R_BUFF_INDX()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace_2()
#define ChkL1MsgFltr_DRV_LOG_RA_RNTI()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace_l()
#define ChkL1MsgFltr_DRV_LOG_TC_RNTI()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace_l()
#define ChkL1MsgFltr_DRV_LOG_PARAM_1()	ChkL1ClsFltr_EL1_DRV_1_drv_param_trace()
#define ChkL1MsgFltr_DRV_LOG_PARAM_2()	ChkL1ClsFltr_EL1_DRV_1_drv_param_trace()
#define ChkL1MsgFltr_DRV_LOG_PARAM_3()	ChkL1ClsFltr_EL1_DRV_1_drv_param_trace()
#define ChkL1MsgFltr_DRV_LOG_PARAM_4()	ChkL1ClsFltr_EL1_DRV_1_drv_param_trace()
#define ChkL1MsgFltr_DRV_LOG_PARAM_5()	ChkL1ClsFltr_EL1_DRV_1_drv_param_trace()
#define ChkL1MsgFltr_DRV_LOG_PARAM_6()	ChkL1ClsFltr_EL1_DRV_1_drv_param_trace()
#define ChkL1MsgFltr_DRV_LOG_PARAM_7()	ChkL1ClsFltr_EL1_DRV_1_drv_param_trace()
#define ChkL1MsgFltr_DRV_LOG_PARAM_8()	ChkL1ClsFltr_EL1_DRV_1_drv_param_trace()
#define ChkL1MsgFltr_DRV_LOG_PARAM_FWS_DSP()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_PARAM_FWS()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_PARAM_FWS_NEW()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_PARAM_FWS_DBG()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_PAG_DUMP_SYNC_RPT()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_PAG_DUMP_COUNT()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_SET_DRX_INACT()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LAST_PDCCH_MONITOR()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_CHK_PDCCH_IND()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LAST_PDCCH_NONE()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_RECAL_FWS_TIME_ERROR()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_RECAL_ALGO()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_DYNM_RECAL()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_DYNM_ERROR()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()
#define ChkL1MsgFltr_DRV_SET_TAS_CMD()	ChkL1ClsFltr_EL1_DRV_1_drv_var_trace()


#endif
