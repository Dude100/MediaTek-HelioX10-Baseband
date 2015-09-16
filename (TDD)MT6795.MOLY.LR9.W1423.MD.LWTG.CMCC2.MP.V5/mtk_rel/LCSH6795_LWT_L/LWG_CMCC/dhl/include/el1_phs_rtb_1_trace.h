#ifndef L1TRC_EL1_PHS_RTB_DEF_H
#define L1TRC_EL1_PHS_RTB_DEF_H

/******************************/
/* String category definition */
/******************************/
#define PHS_Etimer_String(v1)  (unsigned char)(v1+0)
#define PHS_Reserve_End_Time_String(v1)  (unsigned char)(v1+22)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_RTB_LOG_FRAME_SYNC(v1, v2, v3) do {\
		if(EL1_PHS_RTB_Trace_Filter[0]==1 && (EL1_PHS_RTB_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0003, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_RTB_LOG_FRAME_SYNC(v1, v2, v3)
#endif
#define PHS_RTB_LOG_FRAME_SYNC_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0003, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_RTB_LOG_TIMER_PRIO(v1, v2) do {\
		if(EL1_PHS_RTB_Trace_Filter[0]==1 && (EL1_PHS_RTB_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0103, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_RTB_LOG_TIMER_PRIO(v1, v2)
#endif
#define PHS_RTB_LOG_TIMER_PRIO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0103, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_RTB_LOG_RESERV_LEN(v1, v2) do {\
		if(EL1_PHS_RTB_Trace_Filter[0]==1 && (EL1_PHS_RTB_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0203, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_RTB_LOG_RESERV_LEN(v1, v2)
#endif
#define PHS_RTB_LOG_RESERV_LEN_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0203, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_RTB_LOG_RESERV_END_TIME(v1, v2, v3) do {\
		if(EL1_PHS_RTB_Trace_Filter[0]==1 && (EL1_PHS_RTB_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0303, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_RTB_LOG_RESERV_END_TIME(v1, v2, v3)
#endif
#define PHS_RTB_LOG_RESERV_END_TIME_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0303, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_RTB_LOG_SCH_RESERV(v1, v2, v3) do {\
		if(EL1_PHS_RTB_Trace_Filter[0]==1 && (EL1_PHS_RTB_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0403, (short)(v3)), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_RTB_LOG_SCH_RESERV(v1, v2, v3)
#endif
#define PHS_RTB_LOG_SCH_RESERV_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0403, (short)(v3)), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_RTB_LOG_REG_TIMER_BITMAP(v1) do {\
		if(EL1_PHS_RTB_Trace_Filter[0]==1 && (EL1_PHS_RTB_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0503, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_RTB_LOG_REG_TIMER_BITMAP(v1)
#endif
#define PHS_RTB_LOG_REG_TIMER_BITMAP_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0503, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_RTB_LOG_PRESCH_CMD_NUM(v1, v2) do {\
		if(EL1_PHS_RTB_Trace_Filter[0]==1 && (EL1_PHS_RTB_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0603, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_RTB_LOG_PRESCH_CMD_NUM(v1, v2)
#endif
#define PHS_RTB_LOG_PRESCH_CMD_NUM_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0603, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_RTB_LOG_CHK_SCH_FAIL() do {\
		if(EL1_PHS_RTB_Trace_Filter[0]==1 && (EL1_PHS_RTB_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0703, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_RTB_LOG_CHK_SCH_FAIL()
#endif
#define PHS_RTB_LOG_CHK_SCH_FAIL_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0703, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_RTB_LOG_RXTX_FAIL_CNT(v1, v2) do {\
		if(EL1_PHS_RTB_Trace_Filter[0]==1 && (EL1_PHS_RTB_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0803, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_RTB_LOG_RXTX_FAIL_CNT(v1, v2)
#endif
#define PHS_RTB_LOG_RXTX_FAIL_CNT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0803, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_RTB_LOG_HIGH_PRIO_MAC_DRX_ON(v1, v2) do {\
		if(EL1_PHS_RTB_Trace_Filter[0]==1 && (EL1_PHS_RTB_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0903, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_RTB_LOG_HIGH_PRIO_MAC_DRX_ON(v1, v2)
#endif
#define PHS_RTB_LOG_HIGH_PRIO_MAC_DRX_ON_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0903, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_RTB_LOG_NEXT_MAC_DRX_ON(v1, v2, v3) do {\
		if(EL1_PHS_RTB_Trace_Filter[0]==1 && (EL1_PHS_RTB_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A03, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_RTB_LOG_NEXT_MAC_DRX_ON(v1, v2, v3)
#endif
#define PHS_RTB_LOG_NEXT_MAC_DRX_ON_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A03, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_RTB_LOG_SPEC_RESRV_TYPE(v1) do {\
		if(EL1_PHS_RTB_Trace_Filter[0]==1 && (EL1_PHS_RTB_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0B03, (unsigned short)(v1)));\
	} while(0)
#else
	#define PHS_RTB_LOG_SPEC_RESRV_TYPE(v1)
#endif
#define PHS_RTB_LOG_SPEC_RESRV_TYPE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0B03, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_RTB_LOG_HIGH_PRIO_SCH(v1) do {\
		if(EL1_PHS_RTB_Trace_Filter[0]==1 && (EL1_PHS_RTB_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0C03, (unsigned short)(v1)));\
	} while(0)
#else
	#define PHS_RTB_LOG_HIGH_PRIO_SCH(v1)
#endif
#define PHS_RTB_LOG_HIGH_PRIO_SCH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0C03, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_RTB_LOG_NXT_GEMINI_GAP(v1, v2) do {\
		if(EL1_PHS_RTB_Trace_Filter[0]==1 && (EL1_PHS_RTB_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0D03, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2));\
	} while(0)
#else
	#define PHS_RTB_LOG_NXT_GEMINI_GAP(v1, v2)
#endif
#define PHS_RTB_LOG_NXT_GEMINI_GAP_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0D03, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v2))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1_PHS_RTB_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_PHS_RTB_LOG_FRAME_SYNC(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_RTB_LOG_TIMER_PRIO(unsigned char v1, unsigned short v2);
void L1TRC_Send_PHS_RTB_LOG_RESERV_LEN(unsigned char v1, unsigned short v2);
void L1TRC_Send_PHS_RTB_LOG_RESERV_END_TIME(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_RTB_LOG_SCH_RESERV(unsigned long v1, unsigned long v2, short v3);
void L1TRC_Send_PHS_RTB_LOG_REG_TIMER_BITMAP(unsigned long v1);
void L1TRC_Send_PHS_RTB_LOG_PRESCH_CMD_NUM(short v1, short v2);
void L1TRC_Send_PHS_RTB_LOG_CHK_SCH_FAIL(void);
void L1TRC_Send_PHS_RTB_LOG_RXTX_FAIL_CNT(unsigned short v1, unsigned short v2);
void L1TRC_Send_PHS_RTB_LOG_HIGH_PRIO_MAC_DRX_ON(unsigned long v1, unsigned long v2);
void L1TRC_Send_PHS_RTB_LOG_NEXT_MAC_DRX_ON(unsigned long v1, unsigned long v2, unsigned short v3);
void L1TRC_Send_PHS_RTB_LOG_SPEC_RESRV_TYPE(unsigned short v1);
void L1TRC_Send_PHS_RTB_LOG_HIGH_PRIO_SCH(unsigned short v1);
void L1TRC_Send_PHS_RTB_LOG_NXT_GEMINI_GAP(unsigned long v1, long v2);

void Set_EL1_PHS_RTB_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1_PHS_RTB()	(EL1_PHS_RTB_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1_PHS_RTB_phs_rtb_flow_trace()	(ChkL1ModFltr_EL1_PHS_RTB()&&((EL1_PHS_RTB_Trace_Filter[1]&0x01)!=0))
#define ChkL1MsgFltr_PHS_RTB_LOG_FRAME_SYNC()	ChkL1ClsFltr_EL1_PHS_RTB_phs_rtb_flow_trace()
#define ChkL1MsgFltr_PHS_RTB_LOG_TIMER_PRIO()	ChkL1ClsFltr_EL1_PHS_RTB_phs_rtb_flow_trace()
#define ChkL1MsgFltr_PHS_RTB_LOG_RESERV_LEN()	ChkL1ClsFltr_EL1_PHS_RTB_phs_rtb_flow_trace()
#define ChkL1MsgFltr_PHS_RTB_LOG_RESERV_END_TIME()	ChkL1ClsFltr_EL1_PHS_RTB_phs_rtb_flow_trace()
#define ChkL1MsgFltr_PHS_RTB_LOG_SCH_RESERV()	ChkL1ClsFltr_EL1_PHS_RTB_phs_rtb_flow_trace()
#define ChkL1MsgFltr_PHS_RTB_LOG_REG_TIMER_BITMAP()	ChkL1ClsFltr_EL1_PHS_RTB_phs_rtb_flow_trace()
#define ChkL1MsgFltr_PHS_RTB_LOG_PRESCH_CMD_NUM()	ChkL1ClsFltr_EL1_PHS_RTB_phs_rtb_flow_trace()
#define ChkL1MsgFltr_PHS_RTB_LOG_CHK_SCH_FAIL()	ChkL1ClsFltr_EL1_PHS_RTB_phs_rtb_flow_trace()
#define ChkL1MsgFltr_PHS_RTB_LOG_RXTX_FAIL_CNT()	ChkL1ClsFltr_EL1_PHS_RTB_phs_rtb_flow_trace()
#define ChkL1MsgFltr_PHS_RTB_LOG_HIGH_PRIO_MAC_DRX_ON()	ChkL1ClsFltr_EL1_PHS_RTB_phs_rtb_flow_trace()
#define ChkL1MsgFltr_PHS_RTB_LOG_NEXT_MAC_DRX_ON()	ChkL1ClsFltr_EL1_PHS_RTB_phs_rtb_flow_trace()
#define ChkL1MsgFltr_PHS_RTB_LOG_SPEC_RESRV_TYPE()	ChkL1ClsFltr_EL1_PHS_RTB_phs_rtb_flow_trace()
#define ChkL1MsgFltr_PHS_RTB_LOG_HIGH_PRIO_SCH()	ChkL1ClsFltr_EL1_PHS_RTB_phs_rtb_flow_trace()
#define ChkL1MsgFltr_PHS_RTB_LOG_NXT_GEMINI_GAP()	ChkL1ClsFltr_EL1_PHS_RTB_phs_rtb_flow_trace()


#endif
