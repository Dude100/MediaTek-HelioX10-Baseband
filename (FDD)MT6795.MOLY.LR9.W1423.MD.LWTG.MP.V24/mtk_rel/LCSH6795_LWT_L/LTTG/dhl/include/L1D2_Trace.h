#ifndef L1TRC_L1D_SEC_DEF_H
#define L1TRC_L1D_SEC_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1I_AFC_REASON_STR(v1)  (unsigned char)(v1+0)
#define L1D_Str_Bool(v1)  (unsigned char)(v1+15)
#define L1I_DCM_status_STR(v1)  (unsigned char)(v1+17)
#define L1D_Str_PM_Mode(v1)  (unsigned char)(v1+19)
#define L1D_ExecuteTime_Type(v1)  (unsigned char)(v1+24)
#define L1D_Debug_Type(v1)  (unsigned char)(v1+26)
#define L1D_Trc_Str_FCCh_Start_Type(v1)  (unsigned char)(v1+28)
#define L1D_Trc_Str_FH_CLK(v1)  (unsigned char)(v1+35)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define L1I_Msg_AFC_Assert_Reason(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0024, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_AFC_Assert_Reason(v1)
#endif
#define L1I_Msg_AFC_Assert_Reason_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0024, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Msg_AFC_TQ_TIME(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0124, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_AFC_TQ_TIME(v1, v2)
#endif
#define L1I_Msg_AFC_TQ_TIME_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0124, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Msg_AFC_Assert34(v1, v2, v3) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0224, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_AFC_Assert34(v1, v2, v3)
#endif
#define L1I_Msg_AFC_Assert34_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0224, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Msg_AFC_Tid_MisMatch(v1, v2, v3) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0324, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_AFC_Tid_MisMatch(v1, v2, v3)
#endif
#define L1I_Msg_AFC_Tid_MisMatch_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0324, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_SB_Status_Extend(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0424, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (char)(v6), (unsigned char)(v9)), TRC_MERGE_4C((unsigned char)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_SB_Status_Extend(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define L1D_SB_Status_Extend_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0424, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), (char)(v6), (unsigned char)(v9)), TRC_MERGE_4C((unsigned char)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_HIGHSNR_BADBLOCK() do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0524, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_Trc_HIGHSNR_BADBLOCK()
#endif
#define L1D_Trc_HIGHSNR_BADBLOCK_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0524, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_SP_flag(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0624, (short)(v1)));\
	} while(0)
#else
	#define L1D_SP_flag(v1)
#endif
#define L1D_SP_flag_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0624, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_SP_flag_Fsig_no_data_tx(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0724, (short)(v1)));\
	} while(0)
#else
	#define L1D_SP_flag_Fsig_no_data_tx(v1)
#endif
#define L1D_SP_flag_Fsig_no_data_tx_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0724, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_DCM_status(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0824, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_DCM_status(v1)
#endif
#define L1I_DCM_status_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0824, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_PCH_OK_AT_STATE(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0924, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_PCH_OK_AT_STATE(v1, v2)
#endif
#define L1D_PCH_OK_AT_STATE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0924, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_CCCH_OK_AT_STATE(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A24, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_CCCH_OK_AT_STATE(v1, v2)
#endif
#define L1D_CCCH_OK_AT_STATE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A24, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_PCH_One_Burst_Enable(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B24, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_PCH_One_Burst_Enable(v1, v2)
#endif
#define L1D_PCH_One_Burst_Enable_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B24, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_PCH_Null_Detect(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C24, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_PCH_Null_Detect(v1)
#endif
#define L1D_PCH_Null_Detect_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C24, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_PCH_Empty_Detect(v1) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D24, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_PCH_Empty_Detect(v1)
#endif
#define L1D_PCH_Empty_Detect_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D24, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_PCH_Pattern(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0E24, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_1S2C((unsigned short)(v8), (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1D_PCH_Pattern(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define L1D_PCH_Pattern_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0E24, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_1S2C((unsigned short)(v8), (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_TRC_PM(v1, v2, v3, v4) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F24, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_TRC_PM(v1, v2, v3, v4)
#endif
#define L1D_TRC_PM_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0F24, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_DP6TapEQStatus(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1024, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_Trc_DP6TapEQStatus(v1, v2)
#endif
#define L1D_Trc_DP6TapEQStatus_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1024, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_DSP_WATCH_DOG(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1124, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_DSP_WATCH_DOG(v1, v2)
#endif
#define L1D_DSP_WATCH_DOG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1124, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_DSP_RX_FILTER(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1224, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_DSP_RX_FILTER(v1, v2)
#endif
#define L1D_DSP_RX_FILTER_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1224, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_Trc_CD2nd_CRC_Pass(v1, v2, v3) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1324, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_Trc_CD2nd_CRC_Pass(v1, v2, v3)
#endif
#define L1D_Trc_CD2nd_CRC_Pass_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1324, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_Trc_Tx_ARFCN_TA(v1, v2, v3) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1424, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_Trc_Tx_ARFCN_TA(v1, v2, v3)
#endif
#define L1D_Trc_Tx_ARFCN_TA_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1424, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_Trc_Timing_Check_Fail_v1(v1, v2, v3, v4) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1524, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define L1D_Trc_Timing_Check_Fail_v1(v1, v2, v3, v4)
#endif
#define L1D_Trc_Timing_Check_Fail_v1_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1524, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define L1D_Trc_Timing_Check_Fail_v2(v1, v2, v3) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1624, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define L1D_Trc_Timing_Check_Fail_v2(v1, v2, v3)
#endif
#define L1D_Trc_Timing_Check_Fail_v2_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1624, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define L1D_Trc_Execute_Timing_Check(v1, v2) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1724, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_Trc_Execute_Timing_Check(v1, v2)
#endif
#define L1D_Trc_Execute_Timing_Check_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1724, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_Trc_DSP_PM_Not_Done(v1, v2, v3) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1824, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define L1D_Trc_DSP_PM_Not_Done(v1, v2, v3)
#endif
#define L1D_Trc_DSP_PM_Not_Done_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1824, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_AFC_DAC_Data(v1, v2, v3, v4) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1924, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_Trc_AFC_DAC_Data(v1, v2, v3, v4)
#endif
#define L1D_Trc_AFC_DAC_Data_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1924, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_MPLL_FH(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x1A24, (short)(v2)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v8));\
	} while(0)
#else
	#define L1D_Trc_MPLL_FH(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define L1D_Trc_MPLL_FH_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_7_DATA(TRC_MERGE_2S(0x1A24, (short)(v2)), TRC_MERGE_1S2C((short)(v7), (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_LCD_Collision(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B24, (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_Trc_LCD_Collision(v1, v2, v3, v4, v5, v6)
#endif
#define L1D_Trc_LCD_Collision_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B24, (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_Trc_FCCh_Start(v1, v2, v3, v4) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1C24, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define L1D_Trc_FCCh_Start(v1, v2, v3, v4)
#endif
#define L1D_Trc_FCCh_Start_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1C24, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define L1D_Trc_FCCh_Stop(v1, v2, v3, v4) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D24, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)));\
	} while(0)
#else
	#define L1D_Trc_FCCh_Stop(v1, v2, v3, v4)
#endif
#define L1D_Trc_FCCh_Stop_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D24, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (char)(v4)))

#if defined(L1_CATCHER)
	#define L1D_Trc_FB_False_Alarm(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1E24, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (char)(v3)));\
	} while(0)
#else
	#define L1D_Trc_FB_False_Alarm(v1, v2, v3, v4, v5, v6)
#endif
#define L1D_Trc_FB_False_Alarm_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1E24, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v1), (char)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_TXPC(v1, v2, v3) do {\
		if(L1D_SEC_Trace_Filter[0]==1 && (L1D_SEC_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F24, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_Trc_TXPC(v1, v2, v3)
#endif
#define L1D_Trc_TXPC_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F24, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1D_SEC_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1I_Msg_AFC_Assert_Reason(unsigned char v1);
void L1TRC_Send_L1I_Msg_AFC_TQ_TIME(short v1, short v2);
void L1TRC_Send_L1I_Msg_AFC_Assert34(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1I_Msg_AFC_Tid_MisMatch(unsigned char v1, char v2, char v3);
void L1TRC_Send_L1D_SB_Status_Extend(unsigned char v1, short v2, unsigned char v3, short v4, short v5, char v6, short v7, short v8, unsigned char v9, unsigned char v10);
void L1TRC_Send_L1D_Trc_HIGHSNR_BADBLOCK(void);
void L1TRC_Send_L1D_SP_flag(short v1);
void L1TRC_Send_L1D_SP_flag_Fsig_no_data_tx(short v1);
void L1TRC_Send_L1I_DCM_status(unsigned char v1);
void L1TRC_Send_L1D_PCH_OK_AT_STATE(unsigned char v1, short v2);
void L1TRC_Send_L1D_CCCH_OK_AT_STATE(unsigned char v1, short v2);
void L1TRC_Send_L1D_PCH_One_Burst_Enable(unsigned char v1, short v2);
void L1TRC_Send_L1D_PCH_Null_Detect(unsigned char v1);
void L1TRC_Send_L1D_PCH_Empty_Detect(unsigned char v1);
void L1TRC_Send_L1D_PCH_Pattern(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8);
void L1TRC_Send_L1D_TRC_PM(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1D_Trc_DP6TapEQStatus(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1D_DSP_WATCH_DOG(char v1, short v2);
void L1TRC_Send_L1D_DSP_RX_FILTER(unsigned char v1, short v2);
void L1TRC_Send_L1D_Trc_CD2nd_CRC_Pass(unsigned char v1, char v2, unsigned short v3);
void L1TRC_Send_L1D_Trc_Tx_ARFCN_TA(unsigned char v1, short v2, short v3);
void L1TRC_Send_L1D_Trc_Timing_Check_Fail_v1(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_L1D_Trc_Timing_Check_Fail_v2(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_L1D_Trc_Execute_Timing_Check(unsigned char v1, short v2);
void L1TRC_Send_L1D_Trc_DSP_PM_Not_Done(unsigned short v1, short v2, short v3);
void L1TRC_Send_L1D_Trc_AFC_DAC_Data(char v1, short v2, short v3, short v4);
void L1TRC_Send_L1D_Trc_MPLL_FH(unsigned char v1, short v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, short v7, unsigned long v8);
void L1TRC_Send_L1D_Trc_LCD_Collision(unsigned char v1, unsigned char v2, unsigned char v3, short v4, short v5, short v6);
void L1TRC_Send_L1D_Trc_FCCh_Start(unsigned char v1, short v2, unsigned char v3, long v4);
void L1TRC_Send_L1D_Trc_FCCh_Stop(unsigned char v1, short v2, short v3, char v4);
void L1TRC_Send_L1D_Trc_FB_False_Alarm(unsigned char v1, short v2, char v3, short v4, short v5, short v6);
void L1TRC_Send_L1D_Trc_TXPC(unsigned char v1, short v2, short v3);

void Set_L1D_SEC_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1D_SEC()	(L1D_SEC_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1D_SEC_AFCdebug_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_SB_Extend_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_GPRS_State_L()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1D_SEC_SP_flag_L()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1D_SEC_DCM_debug_L()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_PCH_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_PM_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_DSP_COMMON2_L()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_DSP_FILTER_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_CD_2nd_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_L1D_SEC_Tx_ARFCN_TA_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_L1D_SEC_FB_Search_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_Timing_Check_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_L1D_SEC_PM_DONE_CHECK_M()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_L1D_SEC_AFC_DAC_L()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_MPLL_FH_L()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_TXPC_L()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_L1D_SEC_AFCdebug_H()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_SB_Extend_H()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_PCH_H()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_DSP_FILTER_H()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_CD_2nd_H()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_L1D_SEC_Tx_ARFCN_TA_H()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_L1D_SEC_L1D_Timing_Check_H()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_L1D_SEC_PM_DONE_CHECK_H()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_L1D_SEC_FB_Search_H()	(ChkL1ModFltr_L1D_SEC()&&((L1D_SEC_Trace_Filter[4]&0x02)!=0))
#define ChkL1MsgFltr_L1I_Msg_AFC_Assert_Reason()	ChkL1ClsFltr_L1D_SEC_AFCdebug_H()
#define ChkL1MsgFltr_L1I_Msg_AFC_TQ_TIME()	ChkL1ClsFltr_L1D_SEC_AFCdebug_H()
#define ChkL1MsgFltr_L1I_Msg_AFC_Assert34()	ChkL1ClsFltr_L1D_SEC_AFCdebug_H()
#define ChkL1MsgFltr_L1I_Msg_AFC_Tid_MisMatch()	ChkL1ClsFltr_L1D_SEC_AFCdebug_H()
#define ChkL1MsgFltr_L1D_SB_Status_Extend()	ChkL1ClsFltr_L1D_SEC_L1D_SB_Extend_H()
#define ChkL1MsgFltr_L1D_Trc_HIGHSNR_BADBLOCK()	ChkL1ClsFltr_L1D_SEC_L1D_GPRS_State_L()
#define ChkL1MsgFltr_L1D_SP_flag()	ChkL1ClsFltr_L1D_SEC_SP_flag_L()
#define ChkL1MsgFltr_L1D_SP_flag_Fsig_no_data_tx()	ChkL1ClsFltr_L1D_SEC_SP_flag_L()
#define ChkL1MsgFltr_L1I_DCM_status()	ChkL1ClsFltr_L1D_SEC_DCM_debug_L()
#define ChkL1MsgFltr_L1D_PCH_OK_AT_STATE()	ChkL1ClsFltr_L1D_SEC_L1D_PCH_H()
#define ChkL1MsgFltr_L1D_CCCH_OK_AT_STATE()	ChkL1ClsFltr_L1D_SEC_L1D_PCH_H()
#define ChkL1MsgFltr_L1D_PCH_One_Burst_Enable()	ChkL1ClsFltr_L1D_SEC_L1D_PCH_M()
#define ChkL1MsgFltr_L1D_PCH_Null_Detect()	ChkL1ClsFltr_L1D_SEC_L1D_PCH_M()
#define ChkL1MsgFltr_L1D_PCH_Empty_Detect()	ChkL1ClsFltr_L1D_SEC_L1D_PCH_M()
#define ChkL1MsgFltr_L1D_PCH_Pattern()	ChkL1ClsFltr_L1D_SEC_L1D_PCH_H()
#define ChkL1MsgFltr_L1D_TRC_PM()	ChkL1ClsFltr_L1D_SEC_L1D_PM_M()
#define ChkL1MsgFltr_L1D_Trc_DP6TapEQStatus()	ChkL1ClsFltr_L1D_SEC_L1D_DSP_COMMON2_L()
#define ChkL1MsgFltr_L1D_DSP_WATCH_DOG()	ChkL1ClsFltr_L1D_SEC_L1D_PCH_H()
#define ChkL1MsgFltr_L1D_DSP_RX_FILTER()	ChkL1ClsFltr_L1D_SEC_L1D_DSP_FILTER_H()
#define ChkL1MsgFltr_L1D_Trc_CD2nd_CRC_Pass()	ChkL1ClsFltr_L1D_SEC_L1D_CD_2nd_H()
#define ChkL1MsgFltr_L1D_Trc_Tx_ARFCN_TA()	ChkL1ClsFltr_L1D_SEC_Tx_ARFCN_TA_H()
#define ChkL1MsgFltr_L1D_Trc_Timing_Check_Fail_v1()	ChkL1ClsFltr_L1D_SEC_L1D_Timing_Check_H()
#define ChkL1MsgFltr_L1D_Trc_Timing_Check_Fail_v2()	ChkL1ClsFltr_L1D_SEC_L1D_Timing_Check_H()
#define ChkL1MsgFltr_L1D_Trc_Execute_Timing_Check()	ChkL1ClsFltr_L1D_SEC_L1D_Timing_Check_H()
#define ChkL1MsgFltr_L1D_Trc_DSP_PM_Not_Done()	ChkL1ClsFltr_L1D_SEC_PM_DONE_CHECK_H()
#define ChkL1MsgFltr_L1D_Trc_AFC_DAC_Data()	ChkL1ClsFltr_L1D_SEC_AFC_DAC_L()
#define ChkL1MsgFltr_L1D_Trc_MPLL_FH()	ChkL1ClsFltr_L1D_SEC_L1D_MPLL_FH_L()
#define ChkL1MsgFltr_L1D_Trc_LCD_Collision()	ChkL1ClsFltr_L1D_SEC_L1D_MPLL_FH_L()
#define ChkL1MsgFltr_L1D_Trc_FCCh_Start()	ChkL1ClsFltr_L1D_SEC_FB_Search_H()
#define ChkL1MsgFltr_L1D_Trc_FCCh_Stop()	ChkL1ClsFltr_L1D_SEC_FB_Search_H()
#define ChkL1MsgFltr_L1D_Trc_FB_False_Alarm()	ChkL1ClsFltr_L1D_SEC_FB_Search_H()
#define ChkL1MsgFltr_L1D_Trc_TXPC()	ChkL1ClsFltr_L1D_SEC_L1D_TXPC_L()


#endif
