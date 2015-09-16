#ifndef L1TRC_AST_L1_Trace_ISR_Context_Group4_DEF_H
#define L1TRC_AST_L1_Trace_ISR_Context_Group4_DEF_H

/******************************/
/* String category definition */
/******************************/
#define Str_Bool(v1)  (unsigned char)(v1+0)
#define Str_L1c_Sniffer_State(v1)  (unsigned char)(v1+2)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group4_TEST_MSG_1(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group4_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x003E, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group4_TEST_MSG_1(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group4_TEST_MSG_1_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x003E, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group4_TEST_MSG_2(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group4_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x013E, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group4_TEST_MSG_2(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group4_TEST_MSG_2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x013E, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group4_TEST_MSG_3(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group4_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x023E, (unsigned short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group4_TEST_MSG_3(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group4_TEST_MSG_3_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x023E, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group4_MEAS_RF_WINDOW_RANGE(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group4_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x033E, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group4_MEAS_RF_WINDOW_RANGE(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group4_MEAS_RF_WINDOW_RANGE_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x033E, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group4_MEAS_RF_CALC_INFO(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group4_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x043E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group4_MEAS_RF_CALC_INFO(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group4_MEAS_RF_CALC_INFO_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x043E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group4_TIM_ALIGN_LOCAL_CALC_INFO(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group4_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x053E, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group4_TIM_ALIGN_LOCAL_CALC_INFO(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group4_TIM_ALIGN_LOCAL_CALC_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x053E, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group4_SNIFFER_STATE(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group4_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x063E, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group4_SNIFFER_STATE(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group4_SNIFFER_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x063E, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE1(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group4_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x073E, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE1(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x073E, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE2(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group4_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x083E, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE2(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x083E, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE3(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group4_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x093E, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE3(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE3_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x093E, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE4(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group4_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A3E, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE4(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A3E, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE5(v1, v2, v3, v4, v5, v6) do {\
		if(AST_L1_Trace_ISR_Context_Group4_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0B3E, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE5(v1, v2, v3, v4, v5, v6)
#endif
#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE5_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0B3E, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE6(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group4_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0C3E, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE6(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE6_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0C3E, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE7(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(AST_L1_Trace_ISR_Context_Group4_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0D3E, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE7(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE7_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0D3E, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE8(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(AST_L1_Trace_ISR_Context_Group4_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0E3E, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE8(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE8_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0E3E, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(AST_L1_Trace_ISR_Context_Group4_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0F3E, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_1S2C((short)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE9(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE9_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0F3E, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_1S2C((short)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE10(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(AST_L1_Trace_ISR_Context_Group4_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x103E, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE10(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define AST_L1_Trace_ISR_Context_Group4_TEST_TRACE10_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_6_DATA(TRC_MERGE_2S(0x103E, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char AST_L1_Trace_ISR_Context_Group4_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_AST_L1_Trace_ISR_Context_Group4_TEST_MSG_1(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group4_TEST_MSG_2(char v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group4_TEST_MSG_3(unsigned short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group4_MEAS_RF_WINDOW_RANGE(short v1, long v2, short v3, long v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group4_MEAS_RF_CALC_INFO(long v1, long v2, long v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group4_TIM_ALIGN_LOCAL_CALC_INFO(short v1, long v2, short v3, long v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group4_SNIFFER_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE1(unsigned short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE2(unsigned short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE3(unsigned short v1, long v2, long v3, long v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE4(unsigned short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE5(unsigned short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE6(unsigned short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE7(unsigned short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE8(unsigned short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE9(unsigned short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE10(unsigned short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11);

void Set_AST_L1_Trace_ISR_Context_Group4_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group4()	(AST_L1_Trace_ISR_Context_Group4_Trace_Filter[0]==1)
#define ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_1()	(ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group4()&&((AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_2()	(ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group4()&&((AST_L1_Trace_ISR_Context_Group4_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group4_TEST_MSG_1()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group4_TEST_MSG_2()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group4_TEST_MSG_3()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group4_MEAS_RF_WINDOW_RANGE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group4_MEAS_RF_CALC_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group4_TIM_ALIGN_LOCAL_CALC_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group4_SNIFFER_STATE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE1()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE2()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE3()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE4()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE5()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE6()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE7()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE8()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE9()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group4_TEST_TRACE10()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group4_TEST_CLASS_2()


#endif
