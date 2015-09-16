#ifndef L1TRC_EL1_PHS_2_DEF_H
#define L1TRC_EL1_PHS_2_DEF_H

/******************************/
/* String category definition */
/******************************/
#define PHS_Main_St_String(v1)  (unsigned char)(v1+0)
#define PHS_Main_Evt_String(v1)  (unsigned char)(v1+31)
#define PHS_Math_Func_String(v1)  (unsigned char)(v1+46)
#define PHS_Meas_Trig_String(v1)  (unsigned char)(v1+55)
#define PHS_Snd_Msg_String(v1)  (unsigned char)(v1+63)
#define PHS_CH_Req_Type_String(v1)  (unsigned char)(v1+76)
#define PHS_Evt_Chg_Type_String(v1)  (unsigned char)(v1+83)
#define PHS_Auto_gap_St_String(v1)  (unsigned char)(v1+92)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MATH_IN(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0002, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_MATH_IN(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_MATH_IN_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0002, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MATH_OUT(v1, v2, v3) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0102, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_MATH_OUT(v1, v2, v3)
#endif
#define PHS_LOG_MATH_OUT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0102, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_TIME_TRANS(v1, v2, v3, v4) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0202, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_TIME_TRANS(v1, v2, v3, v4)
#endif
#define PHS_LOG_TIME_TRANS_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0202, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MAIN_ST(v1, v2, v3) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0302, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_MAIN_ST(v1, v2, v3)
#endif
#define PHS_LOG_MAIN_ST_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0302, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MAIN_EVT(v1) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0402, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_MAIN_EVT(v1)
#endif
#define PHS_LOG_MAIN_EVT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0402, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MEAS_SCH_MSG_SND(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0502, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define PHS_LOG_MEAS_SCH_MSG_SND(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_MEAS_SCH_MSG_SND_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0502, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_CH_REQ_TYPE(v1) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0602, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_CH_REQ_TYPE(v1)
#endif
#define PHS_LOG_CH_REQ_TYPE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0602, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MEAS_TRIG_INIT(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0702, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define PHS_LOG_MEAS_TRIG_INIT(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PHS_LOG_MEAS_TRIG_INIT_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x0702, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PHY_TRACK_CNCL() do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0802, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_PHY_TRACK_CNCL()
#endif
#define PHS_LOG_PHY_TRACK_CNCL_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0802, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MSG_SND(v1, v2, v3) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0902, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_MSG_SND(v1, v2, v3)
#endif
#define PHS_LOG_MSG_SND_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0902, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_CONF_ABT_MSG_SND(v1) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A02, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_CONF_ABT_MSG_SND(v1)
#endif
#define PHS_LOG_CONF_ABT_MSG_SND_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A02, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_CONF_CH_MSG_SND(v1, v2) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B02, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define PHS_LOG_CONF_CH_MSG_SND(v1, v2)
#endif
#define PHS_LOG_CONF_CH_MSG_SND_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B02, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MB_PBCH_TRIG_IN(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C02, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_MB_PBCH_TRIG_IN(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_MB_PBCH_TRIG_IN_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C02, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MB_PBCH_TRIG_OUT(v1, v2, v3) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D02, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_MB_PBCH_TRIG_OUT(v1, v2, v3)
#endif
#define PHS_LOG_MB_PBCH_TRIG_OUT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D02, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_PHY_TRACK_STUS(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0E02, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_PHY_TRACK_STUS(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define PHS_LOG_PHY_TRACK_STUS_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0E02, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)), TRC_MERGE_4C((unsigned char)(v7), (unsigned char)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MAC_DRX_FORCE_GAP() do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F02, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_MAC_DRX_FORCE_GAP()
#endif
#define PHS_LOG_MAC_DRX_FORCE_GAP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F02, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_MB_PBCH_DISABLE(v1) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1002, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_MB_PBCH_DISABLE(v1)
#endif
#define PHS_LOG_MB_PBCH_DISABLE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1002, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SPECIAL_CMD_ADD(v1) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1102, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_SPECIAL_CMD_ADD(v1)
#endif
#define PHS_LOG_SPECIAL_CMD_ADD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1102, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_WAIT_NBR_BCCH() do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1202, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_WAIT_NBR_BCCH()
#endif
#define PHS_LOG_WAIT_NBR_BCCH_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1202, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_FINAL_EXE_TIME_DBG(v1, v2) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1302, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_FINAL_EXE_TIME_DBG(v1, v2)
#endif
#define PHS_LOG_FINAL_EXE_TIME_DBG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1302, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_DISCON_NBR_SI_GET(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1402, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)));\
	} while(0)
#else
	#define PHS_LOG_DISCON_NBR_SI_GET(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_DISCON_NBR_SI_GET_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1402, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_REDUCE_MEAS_EXE_TIME(v1, v2, v3, v4) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1502, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PHS_LOG_REDUCE_MEAS_EXE_TIME(v1, v2, v3, v4)
#endif
#define PHS_LOG_REDUCE_MEAS_EXE_TIME_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1502, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_EVT_CHG_TYPE(v1) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1602, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_EVT_CHG_TYPE(v1)
#endif
#define PHS_LOG_EVT_CHG_TYPE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1602, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GET_NXT_NBR_TIMER(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1702, (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define PHS_LOG_GET_NXT_NBR_TIMER(v1, v2, v3, v4, v5, v6, v7)
#endif
#define PHS_LOG_GET_NXT_NBR_TIMER_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1702, (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_NXT_NBR_TIMER_TO(v1, v2, v3) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1802, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define PHS_LOG_NXT_NBR_TIMER_TO(v1, v2, v3)
#endif
#define PHS_LOG_NXT_NBR_TIMER_TO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1802, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GET_FINAL_NBR_BCCH(v1, v2, v3, v4, v5, v6) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1902, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_GET_FINAL_NBR_BCCH(v1, v2, v3, v4, v5, v6)
#endif
#define PHS_LOG_GET_FINAL_NBR_BCCH_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1902, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RESET_NBR_TIMER(v1, v2, v3) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A02, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define PHS_LOG_RESET_NBR_TIMER(v1, v2, v3)
#endif
#define PHS_LOG_RESET_NBR_TIMER_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A02, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_NBR_END_UNFREEZE(v1, v2) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B02, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_NBR_END_UNFREEZE(v1, v2)
#endif
#define PHS_LOG_NBR_END_UNFREEZE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B02, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_FINAL_NBR_BCCH_STRT(v1, v2) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C02, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_FINAL_NBR_BCCH_STRT(v1, v2)
#endif
#define PHS_LOG_FINAL_NBR_BCCH_STRT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C02, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_STB_NBR_TIMER_TO(v1, v2, v3, v4, v5) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1D02, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define PHS_LOG_STB_NBR_TIMER_TO(v1, v2, v3, v4, v5)
#endif
#define PHS_LOG_STB_NBR_TIMER_TO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1D02, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_NXT_WAKEUP_TIME(v1, v2, v3) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1E02, (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_NXT_WAKEUP_TIME(v1, v2, v3)
#endif
#define PHS_LOG_NXT_WAKEUP_TIME_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1E02, (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_GAP_DRX_TRACK_LEN(v1, v2, v3) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F02, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define PHS_LOG_GAP_DRX_TRACK_LEN(v1, v2, v3)
#endif
#define PHS_LOG_GAP_DRX_TRACK_LEN_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1F02, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_SKIP_DRX_SLP_IND(v1, v2) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2002, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_SKIP_DRX_SLP_IND(v1, v2)
#endif
#define PHS_LOG_SKIP_DRX_SLP_IND_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2002, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_NEW_DRX_TRACK_STRT(v1, v2, v3) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2102, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_NEW_DRX_TRACK_STRT(v1, v2, v3)
#endif
#define PHS_LOG_NEW_DRX_TRACK_STRT_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2102, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_TRACK_MODE_CRITERIA(v1, v2, v3, v4) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2202, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_TRACK_MODE_CRITERIA(v1, v2, v3, v4)
#endif
#define PHS_LOG_TRACK_MODE_CRITERIA_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2202, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_FWS_ERR_RPT(v1, v2) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2302, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define PHS_LOG_FWS_ERR_RPT(v1, v2)
#endif
#define PHS_LOG_FWS_ERR_RPT_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2302, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RX_WAKEUP(v1, v2, v3) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2402, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define PHS_LOG_RX_WAKEUP(v1, v2, v3)
#endif
#define PHS_LOG_RX_WAKEUP_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x2402, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_RX_LAST_TRACK_TIME(v1, v2, v3) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2502, (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define PHS_LOG_RX_LAST_TRACK_TIME(v1, v2, v3)
#endif
#define PHS_LOG_RX_LAST_TRACK_TIME_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2502, (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_AUTO_GAP_ST(v1) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2602, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define PHS_LOG_AUTO_GAP_ST(v1)
#endif
#define PHS_LOG_AUTO_GAP_ST_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2602, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PHS_LOG_AUTO_GAP_LEN_FROM_AP(v1) do {\
		if(EL1_PHS_2_Trace_Filter[0]==1 && (EL1_PHS_2_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2702, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define PHS_LOG_AUTO_GAP_LEN_FROM_AP(v1)
#endif
#define PHS_LOG_AUTO_GAP_LEN_FROM_AP_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2702, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1_PHS_2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_PHS_LOG_MATH_IN(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_PHS_LOG_MATH_OUT(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_TIME_TRANS(unsigned long v1, unsigned long v2, unsigned short v3, unsigned char v4);
void L1TRC_Send_PHS_LOG_MAIN_ST(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_MAIN_EVT(unsigned char v1);
void L1TRC_Send_PHS_LOG_MEAS_SCH_MSG_SND(unsigned char v1, unsigned char v2, unsigned short v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_PHS_LOG_CH_REQ_TYPE(unsigned char v1);
void L1TRC_Send_PHS_LOG_MEAS_TRIG_INIT(unsigned char v1, unsigned char v2, unsigned char v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_PHS_LOG_PHY_TRACK_CNCL(void);
void L1TRC_Send_PHS_LOG_MSG_SND(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_CONF_ABT_MSG_SND(unsigned char v1);
void L1TRC_Send_PHS_LOG_CONF_CH_MSG_SND(unsigned char v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_MB_PBCH_TRIG_IN(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_PHS_LOG_MB_PBCH_TRIG_OUT(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_PHY_TRACK_STUS(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8);
void L1TRC_Send_PHS_LOG_MAC_DRX_FORCE_GAP(void);
void L1TRC_Send_PHS_LOG_MB_PBCH_DISABLE(unsigned char v1);
void L1TRC_Send_PHS_LOG_SPECIAL_CMD_ADD(unsigned char v1);
void L1TRC_Send_PHS_LOG_WAIT_NBR_BCCH(void);
void L1TRC_Send_PHS_LOG_FINAL_EXE_TIME_DBG(unsigned short v1, unsigned char v2);
void L1TRC_Send_PHS_LOG_DISCON_NBR_SI_GET(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_PHS_LOG_REDUCE_MEAS_EXE_TIME(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_PHS_LOG_EVT_CHG_TYPE(unsigned char v1);
void L1TRC_Send_PHS_LOG_GET_NXT_NBR_TIMER(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned short v5, unsigned short v6, unsigned short v7);
void L1TRC_Send_PHS_LOG_NXT_NBR_TIMER_TO(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_PHS_LOG_GET_FINAL_NBR_BCCH(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_PHS_LOG_RESET_NBR_TIMER(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_PHS_LOG_NBR_END_UNFREEZE(unsigned short v1, unsigned short v2);
void L1TRC_Send_PHS_LOG_FINAL_NBR_BCCH_STRT(unsigned short v1, unsigned short v2);
void L1TRC_Send_PHS_LOG_STB_NBR_TIMER_TO(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_PHS_LOG_NXT_WAKEUP_TIME(unsigned long v1, unsigned long v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_GAP_DRX_TRACK_LEN(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_PHS_LOG_SKIP_DRX_SLP_IND(unsigned long v1, unsigned long v2);
void L1TRC_Send_PHS_LOG_NEW_DRX_TRACK_STRT(unsigned long v1, unsigned long v2, unsigned short v3);
void L1TRC_Send_PHS_LOG_TRACK_MODE_CRITERIA(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_PHS_LOG_FWS_ERR_RPT(long v1, long v2);
void L1TRC_Send_PHS_LOG_RX_WAKEUP(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_PHS_LOG_RX_LAST_TRACK_TIME(unsigned long v1, unsigned long v2, unsigned char v3);
void L1TRC_Send_PHS_LOG_AUTO_GAP_ST(unsigned char v1);
void L1TRC_Send_PHS_LOG_AUTO_GAP_LEN_FROM_AP(unsigned long v1);

void Set_EL1_PHS_2_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1_PHS_2()	(EL1_PHS_2_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1_PHS_2_phs_func_trace()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_func_trace_1()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_func_trace_2()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_math_trace()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_var_trace_l()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_var_trace_2()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_var2_trace()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_var2_trace_l()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_var2_trace_2()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_var3_trace()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_var3_trace_l()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_var3_trace_2()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace_l()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace_2()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_msg_trace()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_msg_trace_l()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_error_trace()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_EL1_PHS_2_phs_debug_trace()	(ChkL1ModFltr_EL1_PHS_2()&&((EL1_PHS_2_Trace_Filter[3]&0x08)!=0))
#define ChkL1MsgFltr_PHS_LOG_MATH_IN()	ChkL1ClsFltr_EL1_PHS_2_phs_math_trace()
#define ChkL1MsgFltr_PHS_LOG_MATH_OUT()	ChkL1ClsFltr_EL1_PHS_2_phs_math_trace()
#define ChkL1MsgFltr_PHS_LOG_TIME_TRANS()	ChkL1ClsFltr_EL1_PHS_2_phs_math_trace()
#define ChkL1MsgFltr_PHS_LOG_MAIN_ST()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_MAIN_EVT()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_MEAS_SCH_MSG_SND()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_CH_REQ_TYPE()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_MEAS_TRIG_INIT()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace_2()
#define ChkL1MsgFltr_PHS_LOG_PHY_TRACK_CNCL()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_MSG_SND()	ChkL1ClsFltr_EL1_PHS_2_phs_msg_trace_l()
#define ChkL1MsgFltr_PHS_LOG_CONF_ABT_MSG_SND()	ChkL1ClsFltr_EL1_PHS_2_phs_msg_trace()
#define ChkL1MsgFltr_PHS_LOG_CONF_CH_MSG_SND()	ChkL1ClsFltr_EL1_PHS_2_phs_msg_trace()
#define ChkL1MsgFltr_PHS_LOG_MB_PBCH_TRIG_IN()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_MB_PBCH_TRIG_OUT()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_PHY_TRACK_STUS()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_MAC_DRX_FORCE_GAP()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_MB_PBCH_DISABLE()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SPECIAL_CMD_ADD()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_WAIT_NBR_BCCH()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace_2()
#define ChkL1MsgFltr_PHS_LOG_FINAL_EXE_TIME_DBG()	ChkL1ClsFltr_EL1_PHS_2_phs_debug_trace()
#define ChkL1MsgFltr_PHS_LOG_DISCON_NBR_SI_GET()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace_2()
#define ChkL1MsgFltr_PHS_LOG_REDUCE_MEAS_EXE_TIME()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace_2()
#define ChkL1MsgFltr_PHS_LOG_EVT_CHG_TYPE()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_GET_NXT_NBR_TIMER()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_NXT_NBR_TIMER_TO()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_GET_FINAL_NBR_BCCH()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()
#define ChkL1MsgFltr_PHS_LOG_RESET_NBR_TIMER()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_NBR_END_UNFREEZE()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_FINAL_NBR_BCCH_STRT()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_STB_NBR_TIMER_TO()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace_2()
#define ChkL1MsgFltr_PHS_LOG_NXT_WAKEUP_TIME()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace_2()
#define ChkL1MsgFltr_PHS_LOG_GAP_DRX_TRACK_LEN()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_SKIP_DRX_SLP_IND()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_NEW_DRX_TRACK_STRT()	ChkL1ClsFltr_EL1_PHS_2_phs_var3_trace_2()
#define ChkL1MsgFltr_PHS_LOG_TRACK_MODE_CRITERIA()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace_2()
#define ChkL1MsgFltr_PHS_LOG_FWS_ERR_RPT()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace_2()
#define ChkL1MsgFltr_PHS_LOG_RX_WAKEUP()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_RX_LAST_TRACK_TIME()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_AUTO_GAP_ST()	ChkL1ClsFltr_EL1_PHS_2_phs_flow_trace()
#define ChkL1MsgFltr_PHS_LOG_AUTO_GAP_LEN_FROM_AP()	ChkL1ClsFltr_EL1_PHS_2_phs_var_trace()


#endif
