#ifndef L1TRC_UL1D_HSPA_SEC_DEF_H
#define L1TRC_UL1D_HSPA_SEC_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1D_TRC_STR_MS3_ACTION(v1)  (unsigned char)(v1+0)
#define UL1D_TRC_STR_DD_SRC(v1)  (unsigned char)(v1+4)
#define UL1D_TRC_STR_MS3_PROC_ACTION(v1)  (unsigned char)(v1+7)
#define UL1D_TRC_STR_DFE_LNA_STATE(v1)  (unsigned char)(v1+14)
#define UL1D_TRC_STR_FSM_STATE(v1)  (unsigned char)(v1+18)
#define UL1D_TRC_STR_FREQ_IDX(v1)  (unsigned char)(v1+26)
#define UL1D_TRC_STR_CASE(v1)  (unsigned char)(v1+31)
#define UL1D_TRC_STR_IMD2_STATUS(v1)  (unsigned char)(v1+46)
#define UL1D_TRC_STR_ANT_SEL(v1)  (unsigned char)(v1+51)
#define UL1D_TRC_STR_RXDFE_DBG(v1)  (unsigned char)(v1+54)
#define UL1D_TRC_STR_HIRG_THR_DBG(v1)  (unsigned char)(v1+97)
#define UL1D_TRC_STR_FHC_STATE_DBG(v1)  (unsigned char)(v1+99)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define UL1D_TRC_CS_ST_MASK_DBG1(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0035, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS_ST_MASK_DBG1(v1, v2, v3, v4)
#endif
#define UL1D_TRC_CS_ST_MASK_DBG1_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0035, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CS_ST_MASK_DBG2(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0135, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CS_ST_MASK_DBG2(v1, v2)
#endif
#define UL1D_TRC_CS_ST_MASK_DBG2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0135, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SEQ_CON_R6S(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0235, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_SEQ_CON_R6S(v1, v2, v3)
#endif
#define UL1D_TRC_SEQ_CON_R6S_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0235, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MS3_ABORT_R6S(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0335, (unsigned short)(v2)), (long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_MS3_ABORT_R6S(v1, v2)
#endif
#define UL1D_TRC_MS3_ABORT_R6S_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0335, (unsigned short)(v2)), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_Meas_Avg_R6S(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0435, (unsigned short)(v1)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v2), (unsigned char)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_Meas_Avg_R6S(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_Meas_Avg_R6S_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0435, (unsigned short)(v1)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), (unsigned char)(v2), (unsigned char)(v3)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_RXD_MEAS_OPT(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0535, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v6)), TRC_MERGE_2S((short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (short)(v10)), TRC_MERGE_1S2C((short)(v11), (unsigned char)(v1), (unsigned char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_RXD_MEAS_OPT(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define UL1D_TRC_MEAS_RXD_MEAS_OPT_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0535, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v6)), TRC_MERGE_2S((short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (short)(v10)), TRC_MERGE_1S2C((short)(v11), (unsigned char)(v1), (unsigned char)(v4)), TRC_MERGE_4C((char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_MEAS_OPT_E2(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0635, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_1S2C((short)(v8), (char)(v2), (unsigned char)(v7)));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_MEAS_OPT_E2(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_MEAS_MEAS_OPT_E2_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0635, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_1S2C((short)(v8), (char)(v2), (unsigned char)(v7)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_MEAS_OPT(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0735, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_4C((char)(v2), (unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_MEAS_OPT(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define UL1D_TRC_MEAS_MEAS_OPT_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0735, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_4C((char)(v2), (unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RXD_MEAS_OPT(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0835, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXD_MEAS_OPT(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_RXD_MEAS_OPT_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0835, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_PROHIBIYED_TIMER_START(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0935, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_PROHIBIYED_TIMER_START(v1, v2)
#endif
#define UL1D_TRC_MEAS_PROHIBIYED_TIMER_START_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0935, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MEAS_PROHIBIYED_TIMER_EXPIRY(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A35, (short)(v2)), (long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_PROHIBIYED_TIMER_EXPIRY(v1, v2)
#endif
#define UL1D_TRC_MEAS_PROHIBIYED_TIMER_EXPIRY_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A35, (short)(v2)), (long)(v1))

#if defined(L1_CATCHER)
	#define UL1D_TRC_SEQ_PROC_CON(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B35, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)));\
	} while(0)
#else
	#define UL1D_TRC_SEQ_PROC_CON(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_SEQ_PROC_CON_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0B35, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MEAS_PATH_R6S(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0C35, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_PATH_R6S(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define UL1D_TRC_MEAS_PATH_R6S_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0C35, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DD_RESULT_R6S(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D35, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DD_RESULT_R6S(v1, v2, v3)
#endif
#define UL1D_TRC_DD_RESULT_R6S_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D35, (short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DBG_SG_R6S(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E35, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DBG_SG_R6S(v1, v2, v3)
#endif
#define UL1D_TRC_DBG_SG_R6S_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E35, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DBG_2STAGE(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F35, (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DBG_2STAGE(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_DBG_2STAGE_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F35, (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CS3_2STAGE_TIMING_INFO(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x1035, (short)(v1)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_CS3_2STAGE_TIMING_INFO(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_CS3_2STAGE_TIMING_INFO_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x1035, (short)(v1)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define UL1D_TRC_CALC_CELL_TIME(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x1135, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_CALC_CELL_TIME(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_CALC_CELL_TIME_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x1135, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DBG_TIMED_CELL_FOUND(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x1235, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define UL1D_TRC_DBG_TIMED_CELL_FOUND(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_DBG_TIMED_CELL_FOUND_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x1235, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_DBG_NON_TIMED_CELL_FOUND(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1335, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_DBG_NON_TIMED_CELL_FOUND(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_DBG_NON_TIMED_CELL_FOUND_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1335, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXDFE_IQGAINPHASE(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1435, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_IQGAINPHASE(v1, v2)
#endif
#define UL1D_TRC_HW_RXDFE_IQGAINPHASE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1435, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HW_RXDFE_CURR_STA_AGC(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1535, (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CURR_STA_AGC(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_HW_RXDFE_CURR_STA_AGC_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1535, (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HW_RXDFE_CURR_DCIQ(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1635, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CURR_DCIQ(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HW_RXDFE_CURR_DCIQ_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1635, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HW_RXDFE_INT_STA_RSSI(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1735, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_INT_STA_RSSI(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_HW_RXDFE_INT_STA_RSSI_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1735, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXDFE_EST_DCIQ(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1835, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_EST_DCIQ(v1, v2)
#endif
#define UL1D_TRC_HW_RXDFE_EST_DCIQ_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1835, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HW_RXDFE_DC12PGASTA(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1935, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_DC12PGASTA(v1, v2, v3)
#endif
#define UL1D_TRC_HW_RXDFE_DC12PGASTA_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1935, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXDFE_HDC_VALIDE01(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1A35, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_HDC_VALIDE01(v1, v2)
#endif
#define UL1D_TRC_HW_RXDFE_HDC_VALIDE01_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1A35, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXDFE_AD_SCALER_CLIP(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_AD_SCALER_CLIP(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HW_RXDFE_AD_SCALER_CLIP_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1B35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXDFE_RSSI(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C35, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_RSSI(v1, v2, v3)
#endif
#define UL1D_TRC_HW_RXDFE_RSSI_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C35, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HW_RXDFE_SLOT_RSSI(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_SLOT_RSSI(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HW_RXDFE_SLOT_RSSI_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1D35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXDFE_DC_FL(v1) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E35, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_DC_FL(v1)
#endif
#define UL1D_TRC_HW_RXDFE_DC_FL_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E35, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HW_RXDFE_CAL_DBG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CAL_DBG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HW_RXDFE_CAL_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HW_RXDFE_CAL_DBG2(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2035, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CAL_DBG2(v1, v2)
#endif
#define UL1D_TRC_HW_RXDFE_CAL_DBG2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2035, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HW_RXDFE_CAL_DBG3(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2135, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CAL_DBG3(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_HW_RXDFE_CAL_DBG3_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2135, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HW_RXDFE_CAL_DBG4(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2235, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CAL_DBG4(v1, v2, v3)
#endif
#define UL1D_TRC_HW_RXDFE_CAL_DBG4_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2235, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HW_RXDFE_CAL_DBG5(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2335, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CAL_DBG5(v1, v2, v3)
#endif
#define UL1D_TRC_HW_RXDFE_CAL_DBG5_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2335, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HW_RXDFE_CAL_DBG6(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2435, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CAL_DBG6(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_HW_RXDFE_CAL_DBG6_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2435, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXDFE_CAL_DBG7(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2535, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CAL_DBG7(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HW_RXDFE_CAL_DBG7_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2535, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXDFE_CAL_DBG8(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2635, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXDFE_CAL_DBG8(v1, v2)
#endif
#define UL1D_TRC_HW_RXDFE_CAL_DBG8_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2635, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_IMD2_LMS_COEFF(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x2735, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_IMD2_LMS_COEFF(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_IMD2_LMS_COEFF_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x2735, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_IMD2_LMS_STA_DC(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2835, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_IMD2_LMS_STA_DC(v1, v2, v3, v4)
#endif
#define UL1D_TRC_IMD2_LMS_STA_DC_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2835, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_EHI_DBG_CMB(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x2935, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define UL1D_TRC_EHI_DBG_CMB(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_EHI_DBG_CMB_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x2935, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_EHI_DBG_CMB_COM(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A35, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_EHI_DBG_CMB_COM(v1, v2)
#endif
#define UL1D_TRC_EHI_DBG_CMB_COM_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2A35, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_EHI_DBG_ALL(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B35, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v2), (unsigned char)(v3)), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_EHI_DBG_ALL(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_EHI_DBG_ALL_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2B35, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v2), (unsigned char)(v3)), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_EHI_DBG_RAKE_RFM_FNG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C35, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_EHI_DBG_RAKE_RFM_FNG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_EHI_DBG_RAKE_RFM_FNG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C35, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_EHI_DBG_FNG_MIC_PWR(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2D35, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v8), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EHI_DBG_FNG_MIC_PWR(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_EHI_DBG_FNG_MIC_PWR_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2D35, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v6)), TRC_MERGE_1S2C((unsigned short)(v8), (unsigned char)(v1), (unsigned char)(v3)), TRC_MERGE_4C((unsigned char)(v5), (unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_EHI_DBG_SOFT(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2E35, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_EHI_DBG_SOFT(v1, v2)
#endif
#define UL1D_TRC_EHI_DBG_SOFT_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2E35, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_EHI_DBG_CG(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2F35, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EHI_DBG_CG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_EHI_DBG_CG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2F35, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG1_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x3035, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG1_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG1_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x3035, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG1_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x3135, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_2S((unsigned short)(v12), (unsigned short)(v13)), TRC_MERGE_2S((unsigned short)(v14), (unsigned short)(v15)), TRC_MERGE_2S((unsigned short)(v16), (unsigned short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG1_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG1_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x3135, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_2S((unsigned short)(v12), (unsigned short)(v13)), TRC_MERGE_2S((unsigned short)(v14), (unsigned short)(v15)), TRC_MERGE_2S((unsigned short)(v16), (unsigned short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG1_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3235, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG1_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG1_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3235, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RXDFE_DBG1_INT32X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3335, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16), (unsigned long)(v17));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG1_INT32X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG1_INT32X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3335, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16), (unsigned long)(v17))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG2_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x3435, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG2_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG2_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x3435, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG2_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x3535, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_2S((unsigned short)(v12), (unsigned short)(v13)), TRC_MERGE_2S((unsigned short)(v14), (unsigned short)(v15)), TRC_MERGE_2S((unsigned short)(v16), (unsigned short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG2_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG2_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x3535, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_2S((unsigned short)(v12), (unsigned short)(v13)), TRC_MERGE_2S((unsigned short)(v14), (unsigned short)(v15)), TRC_MERGE_2S((unsigned short)(v16), (unsigned short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG2_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3635, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG2_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG2_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3635, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG2_INT32X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3735, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16), (unsigned long)(v17));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG2_INT32X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG2_INT32X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3735, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16), (unsigned long)(v17))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG3_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x3835, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG3_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG3_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x3835, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG3_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x3935, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_2S((unsigned short)(v12), (unsigned short)(v13)), TRC_MERGE_2S((unsigned short)(v14), (unsigned short)(v15)), TRC_MERGE_2S((unsigned short)(v16), (unsigned short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG3_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG3_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x3935, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_2S((unsigned short)(v12), (unsigned short)(v13)), TRC_MERGE_2S((unsigned short)(v14), (unsigned short)(v15)), TRC_MERGE_2S((unsigned short)(v16), (unsigned short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG3_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3A35, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG3_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG3_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3A35, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXDFE_DBG3_INT32X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3B35, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16), (unsigned long)(v17));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG3_INT32X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG3_INT32X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3B35, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16), (unsigned long)(v17))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RXDFE_DBG4_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x3C35, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG4_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG4_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x3C35, (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RXDFE_DBG4_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x3D35, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_2S((unsigned short)(v12), (unsigned short)(v13)), TRC_MERGE_2S((unsigned short)(v14), (unsigned short)(v15)), TRC_MERGE_2S((unsigned short)(v16), (unsigned short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG4_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG4_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x3D35, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_2S((unsigned short)(v8), (unsigned short)(v9)), TRC_MERGE_2S((unsigned short)(v10), (unsigned short)(v11)), TRC_MERGE_2S((unsigned short)(v12), (unsigned short)(v13)), TRC_MERGE_2S((unsigned short)(v14), (unsigned short)(v15)), TRC_MERGE_2S((unsigned short)(v16), (unsigned short)(v17)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RXDFE_DBG4_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3E35, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG4_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG4_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3E35, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8), (long)(v9), (long)(v10), (long)(v11), (long)(v12), (long)(v13), (long)(v14), (long)(v15), (long)(v16), (long)(v17))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RXDFE_DBG4_INT32X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3F35, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16), (unsigned long)(v17));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_DBG4_INT32X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define UL1D_TRC_RXDFE_DBG4_INT32X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x3F35, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16), (unsigned long)(v17))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RFPWRCTRL(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4035, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_RFPWRCTRL(v1, v2, v3)
#endif
#define UL1D_TRC_RFPWRCTRL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4035, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RFDMPWRCTRL(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4135, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RFDMPWRCTRL(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RFDMPWRCTRL_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4135, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_AUX_DBG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4235, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_AUX_DBG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_AUX_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4235, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_ERX_HI_CONFIG(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4335, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_ERX_HI_CONFIG(v1, v2)
#endif
#define UL1D_TRC_ERX_HI_CONFIG_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4335, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_ERX_HI_FILTER_STATUS(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4435, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_ERX_HI_FILTER_STATUS(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_ERX_HI_FILTER_STATUS_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x4435, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_ERX_HI_ABS_TH_FOR_CSD(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4535, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ERX_HI_ABS_TH_FOR_CSD(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ERX_HI_ABS_TH_FOR_CSD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4535, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_ERX_RG_ABS_TH_FOR_CSD(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4635, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RG_ABS_TH_FOR_CSD(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ERX_RG_ABS_TH_FOR_CSD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4635, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_ERX_RSLT_FOR_CSD_RG(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4735, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RSLT_FOR_CSD_RG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_ERX_RSLT_FOR_CSD_RG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4735, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_ERX_RSLT_FOR_CSD_HI(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4835, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RSLT_FOR_CSD_HI(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_ERX_RSLT_FOR_CSD_HI_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4835, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_RG_DYN_THRESHOLD(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4935, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RG_DYN_THRESHOLD(v1, v2, v3)
#endif
#define UL1D_TRC_ERX_RG_DYN_THRESHOLD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4935, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_HIRG_THRESHOLD(v1) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4A35, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ERX_HIRG_THRESHOLD(v1)
#endif
#define UL1D_TRC_ERX_HIRG_THRESHOLD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4A35, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_E_HIRG_E2_DBG16(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4B35, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_E_HIRG_E2_DBG16(v1, v2)
#endif
#define UL1D_TRC_E_HIRG_E2_DBG16_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4B35, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_E_HIRG_E2_DBG32(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4C35, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_E_HIRG_E2_DBG32(v1, v2)
#endif
#define UL1D_TRC_E_HIRG_E2_DBG32_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4C35, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RXDFE_RXPOST(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4D35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_RXPOST(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_RXDFE_RXPOST_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4D35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RXDFE_RXPOST_L(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x4E35, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_RXPOST_L(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_RXDFE_RXPOST_L_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x4E35, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_RXDFE_RXPOST_FULL(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x4F35, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define UL1D_TRC_RXDFE_RXPOST_FULL(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_RXDFE_RXPOST_FULL_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x4F35, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_FHC_DBG1_INT16(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x5035, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FHC_DBG1_INT16(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_FHC_DBG1_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x5035, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_FHC_DBG1_INT16X(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x5135, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_1S2C((unsigned short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FHC_DBG1_INT16X(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_FHC_DBG1_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x5135, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)), TRC_MERGE_1S2C((unsigned short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_FHC_DBG1_INT32(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x5235, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define UL1D_TRC_FHC_DBG1_INT32(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_FHC_DBG1_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x5235, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_FHC_DBG1_INT32X(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x5335, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define UL1D_TRC_FHC_DBG1_INT32X(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_FHC_DBG1_INT32X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_9_DATA(TRC_MERGE_1S2C(0x5335, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_FHC_STATE(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x5435, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FHC_STATE(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_FHC_STATE_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x5435, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RXD_TESTMODE() do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5535, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXD_TESTMODE()
#endif
#define UL1D_TRC_RXD_TESTMODE_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5535, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_IDLE_CM(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x5635, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_IDLE_CM(v1, v2, v3)
#endif
#define UL1D_TRC_IDLE_CM_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x5635, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RXD_MEAS_START(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5735, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXD_MEAS_START(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_RXD_MEAS_START_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5735, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RXD_MPS_START(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5835, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXD_MPS_START(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_RXD_MPS_START_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5835, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RXD_SET_MS3_PARM(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5935, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXD_SET_MS3_PARM(v1, v2, v3, v4)
#endif
#define UL1D_TRC_RXD_SET_MS3_PARM_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5935, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RXD_CS3_2STAGE_START(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5A35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define UL1D_TRC_RXD_CS3_2STAGE_START(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_RXD_CS3_2STAGE_START_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5A35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RXD_CS_SET_PARM(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x5B35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RXD_CS_SET_PARM(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_RXD_CS_SET_PARM_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x5B35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_IDLE_RXD_TURN_ON(v1, v2) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5C35, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_IDLE_RXD_TURN_ON(v1, v2)
#endif
#define UL1D_TRC_IDLE_RXD_TURN_ON_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5C35, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RXD_LISR_DBG(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5D35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_RXD_LISR_DBG(v1, v2, v3)
#endif
#define UL1D_TRC_RXD_LISR_DBG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5D35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_IDLE_FREE_RXD_DEBUG(v1, v2, v3) do {\
		if(UL1D_HSPA_SEC_Trace_Filter[0]==1 && (UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5E35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_IDLE_FREE_RXD_DEBUG(v1, v2, v3)
#endif
#define UL1D_TRC_IDLE_FREE_RXD_DEBUG_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5E35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1D_HSPA_SEC_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1D_TRC_CS_ST_MASK_DBG1(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_CS_ST_MASK_DBG2(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_SEQ_CON_R6S(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_MS3_ABORT_R6S(long v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_Meas_Avg_R6S(unsigned short v1, unsigned char v2, unsigned char v3, short v4, short v5, short v6);
void L1TRC_Send_UL1D_TRC_MEAS_RXD_MEAS_OPT(unsigned char v1, unsigned short v2, unsigned short v3, unsigned char v4, char v5, unsigned short v6, short v7, unsigned short v8, unsigned short v9, short v10, short v11);
void L1TRC_Send_UL1D_TRC_MEAS_MEAS_OPT_E2(unsigned short v1, char v2, unsigned short v3, short v4, unsigned short v5, unsigned short v6, unsigned char v7, short v8);
void L1TRC_Send_UL1D_TRC_MEAS_MEAS_OPT(unsigned short v1, char v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned char v7, short v8, short v9);
void L1TRC_Send_UL1D_TRC_RXD_MEAS_OPT(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1D_TRC_MEAS_PROHIBIYED_TIMER_START(long v1, long v2);
void L1TRC_Send_UL1D_TRC_MEAS_PROHIBIYED_TIMER_EXPIRY(long v1, short v2);
void L1TRC_Send_UL1D_TRC_SEQ_PROC_CON(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_MEAS_PATH_R6S(char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10);
void L1TRC_Send_UL1D_TRC_DD_RESULT_R6S(unsigned char v1, short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_DBG_SG_R6S(unsigned char v1, unsigned char v2, short v3);
void L1TRC_Send_UL1D_TRC_DBG_2STAGE(unsigned char v1, unsigned char v2, unsigned char v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_CS3_2STAGE_TIMING_INFO(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, short v6);
void L1TRC_Send_UL1D_TRC_CALC_CELL_TIME(short v1, unsigned long v2, short v3, short v4, short v5, unsigned long v6);
void L1TRC_Send_UL1D_TRC_DBG_TIMED_CELL_FOUND(short v1, short v2, short v3, short v4, short v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_UL1D_TRC_DBG_NON_TIMED_CELL_FOUND(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_IQGAINPHASE(short v1, short v2);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CURR_STA_AGC(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, short v5, short v6, short v7);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CURR_DCIQ(short v1, short v2, long v3, long v4);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_INT_STA_RSSI(unsigned char v1, unsigned char v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_EST_DCIQ(long v1, long v2);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_DC12PGASTA(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_HDC_VALIDE01(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_AD_SCALER_CLIP(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_RSSI(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_SLOT_RSSI(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_DC_FL(unsigned long v1);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CAL_DBG(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CAL_DBG2(short v1, short v2);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CAL_DBG3(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CAL_DBG4(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CAL_DBG5(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CAL_DBG6(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CAL_DBG7(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_HW_RXDFE_CAL_DBG8(short v1, short v2);
void L1TRC_Send_UL1D_TRC_IMD2_LMS_COEFF(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1D_TRC_IMD2_LMS_STA_DC(unsigned char v1, short v2, long v3, long v4);
void L1TRC_Send_UL1D_TRC_EHI_DBG_CMB(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_UL1D_TRC_EHI_DBG_CMB_COM(unsigned char v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_EHI_DBG_ALL(unsigned short v1, unsigned char v2, unsigned char v3, unsigned long v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_EHI_DBG_RAKE_RFM_FNG(unsigned short v1, unsigned short v2, unsigned short v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_EHI_DBG_FNG_MIC_PWR(unsigned char v1, unsigned short v2, unsigned char v3, unsigned short v4, unsigned char v5, unsigned short v6, unsigned char v7, unsigned short v8);
void L1TRC_Send_UL1D_TRC_EHI_DBG_SOFT(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_EHI_DBG_CG(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG1_INT16(unsigned char v1, unsigned char v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG1_INT16X(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16, unsigned short v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG1_INT32(unsigned char v1, unsigned char v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9, long v10, long v11, long v12, long v13, long v14, long v15, long v16, long v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG1_INT32X(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16, unsigned long v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG2_INT16(unsigned char v1, unsigned char v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG2_INT16X(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16, unsigned short v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG2_INT32(unsigned char v1, unsigned char v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9, long v10, long v11, long v12, long v13, long v14, long v15, long v16, long v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG2_INT32X(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16, unsigned long v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG3_INT16(unsigned char v1, unsigned char v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG3_INT16X(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16, unsigned short v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG3_INT32(unsigned char v1, unsigned char v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9, long v10, long v11, long v12, long v13, long v14, long v15, long v16, long v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG3_INT32X(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16, unsigned long v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG4_INT16(unsigned char v1, unsigned char v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG4_INT16X(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16, unsigned short v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG4_INT32(unsigned char v1, unsigned char v2, long v3, long v4, long v5, long v6, long v7, long v8, long v9, long v10, long v11, long v12, long v13, long v14, long v15, long v16, long v17);
void L1TRC_Send_UL1D_TRC_RXDFE_DBG4_INT32X(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16, unsigned long v17);
void L1TRC_Send_UL1D_TRC_RFPWRCTRL(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_RFDMPWRCTRL(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_AUX_DBG(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_ERX_HI_CONFIG(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_ERX_HI_FILTER_STATUS(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned long v6);
void L1TRC_Send_UL1D_TRC_ERX_HI_ABS_TH_FOR_CSD(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_ERX_RG_ABS_TH_FOR_CSD(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_ERX_RSLT_FOR_CSD_RG(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_ERX_RSLT_FOR_CSD_HI(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_UL1D_TRC_ERX_RG_DYN_THRESHOLD(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_ERX_HIRG_THRESHOLD(unsigned char v1);
void L1TRC_Send_UL1D_TRC_E_HIRG_E2_DBG16(unsigned char v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_E_HIRG_E2_DBG32(unsigned char v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_RXDFE_RXPOST(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_RXDFE_RXPOST_L(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_UL1D_TRC_RXDFE_RXPOST_FULL(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7);
void L1TRC_Send_UL1D_TRC_FHC_DBG1_INT16(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1D_TRC_FHC_DBG1_INT16X(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8);
void L1TRC_Send_UL1D_TRC_FHC_DBG1_INT32(long v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8);
void L1TRC_Send_UL1D_TRC_FHC_DBG1_INT32X(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_UL1D_TRC_FHC_STATE(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1D_TRC_RXD_TESTMODE(void);
void L1TRC_Send_UL1D_TRC_IDLE_CM(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_RXD_MEAS_START(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1D_TRC_RXD_MPS_START(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1D_TRC_RXD_SET_MS3_PARM(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_RXD_CS3_2STAGE_START(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_UL1D_TRC_RXD_CS_SET_PARM(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1D_TRC_IDLE_RXD_TURN_ON(short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_RXD_LISR_DBG(short v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_IDLE_FREE_RXD_DEBUG(short v1, short v2, short v3);

void Set_UL1D_HSPA_SEC_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1D_HSPA_SEC()	(UL1D_HSPA_SEC_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_EHI_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_RXDFE_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_RXDFE_DUMP_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_MEAS_H()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_H()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_IMD2_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_H()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG1_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG1_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG2_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG3_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG4_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RFPwrCtrl_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_RFPwrCtrl_H()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_AUX_DBG_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_RG_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_HI_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_RG_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_HI_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[4]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_HIRG_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[4]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_FHC_M()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[4]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_FHC_L()	(ChkL1ModFltr_UL1D_HSPA_SEC()&&((UL1D_HSPA_SEC_Trace_Filter[4]&0x10)!=0))
#define ChkL1MsgFltr_UL1D_TRC_CS_ST_MASK_DBG1()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_CS_ST_MASK_DBG2()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_SEQ_CON_R6S()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_MS3_ABORT_R6S()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_Meas_Avg_R6S()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_L()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_RXD_MEAS_OPT()	ChkL1ClsFltr_UL1D_HSPA_SEC_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_MEAS_OPT_E2()	ChkL1ClsFltr_UL1D_HSPA_SEC_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_MEAS_OPT()	ChkL1ClsFltr_UL1D_HSPA_SEC_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_RXD_MEAS_OPT()	ChkL1ClsFltr_UL1D_HSPA_SEC_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_PROHIBIYED_TIMER_START()	ChkL1ClsFltr_UL1D_HSPA_SEC_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_PROHIBIYED_TIMER_EXPIRY()	ChkL1ClsFltr_UL1D_HSPA_SEC_MEAS_H()
#define ChkL1MsgFltr_UL1D_TRC_SEQ_PROC_CON()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_PATH_R6S()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_L()
#define ChkL1MsgFltr_UL1D_TRC_DD_RESULT_R6S()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_DBG_SG_R6S()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_L()
#define ChkL1MsgFltr_UL1D_TRC_DBG_2STAGE()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_L()
#define ChkL1MsgFltr_UL1D_TRC_CS3_2STAGE_TIMING_INFO()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_CALC_CELL_TIME()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_DBG_TIMED_CELL_FOUND()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_DBG_NON_TIMED_CELL_FOUND()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_IQGAINPHASE()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CURR_STA_AGC()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_H()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CURR_DCIQ()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_H()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_INT_STA_RSSI()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_H()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_EST_DCIQ()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_DC12PGASTA()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_H()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_HDC_VALIDE01()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_AD_SCALER_CLIP()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_RSSI()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_SLOT_RSSI()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_M()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_DC_FL()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CAL_DBG()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_M()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CAL_DBG2()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_M()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CAL_DBG3()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_M()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CAL_DBG4()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_M()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CAL_DBG5()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_M()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CAL_DBG6()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_M()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CAL_DBG7()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXDFE_CAL_DBG8()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_L()
#define ChkL1MsgFltr_UL1D_TRC_IMD2_LMS_COEFF()	ChkL1ClsFltr_UL1D_HSPA_SEC_IMD2_L()
#define ChkL1MsgFltr_UL1D_TRC_IMD2_LMS_STA_DC()	ChkL1ClsFltr_UL1D_HSPA_SEC_IMD2_L()
#define ChkL1MsgFltr_UL1D_TRC_EHI_DBG_CMB()	ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_EHI_DBG_CMB_COM()	ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_EHI_DBG_ALL()	ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_EHI_DBG_RAKE_RFM_FNG()	ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_EHI_DBG_FNG_MIC_PWR()	ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_EHI_DBG_SOFT()	ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_EHI_DBG_CG()	ChkL1ClsFltr_UL1D_HSPA_SEC_EHI_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG1_INT16()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG1_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG1_INT16X()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG1_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG1_INT32()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG1_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG1_INT32X()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG1_L()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG2_INT16()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG2_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG2_INT16X()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG2_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG2_INT32()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG2_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG2_INT32X()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG2_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG3_INT16()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG3_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG3_INT16X()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG3_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG3_INT32()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG3_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG3_INT32X()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG3_M()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG4_INT16()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG4_L()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG4_INT16X()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG4_L()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG4_INT32()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG4_L()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_DBG4_INT32X()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG4_L()
#define ChkL1MsgFltr_UL1D_TRC_RFPWRCTRL()	ChkL1ClsFltr_UL1D_HSPA_SEC_RFPwrCtrl_M()
#define ChkL1MsgFltr_UL1D_TRC_RFDMPWRCTRL()	ChkL1ClsFltr_UL1D_HSPA_SEC_RFPwrCtrl_H()
#define ChkL1MsgFltr_UL1D_TRC_AUX_DBG()	ChkL1ClsFltr_UL1D_HSPA_SEC_AUX_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_HI_CONFIG()	ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_HI_L()
#define ChkL1MsgFltr_UL1D_TRC_ERX_HI_FILTER_STATUS()	ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_HI_L()
#define ChkL1MsgFltr_UL1D_TRC_ERX_HI_ABS_TH_FOR_CSD()	ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_HI_L()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RG_ABS_TH_FOR_CSD()	ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_RG_L()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RSLT_FOR_CSD_RG()	ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_RG_L()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RSLT_FOR_CSD_HI()	ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_HI_L()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RG_DYN_THRESHOLD()	ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_RG_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_HIRG_THRESHOLD()	ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_HI_M()
#define ChkL1MsgFltr_UL1D_TRC_E_HIRG_E2_DBG16()	ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_HIRG_L()
#define ChkL1MsgFltr_UL1D_TRC_E_HIRG_E2_DBG32()	ChkL1ClsFltr_UL1D_HSPA_SEC_CSD_HIRG_L()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_RXPOST()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG4_L()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_RXPOST_L()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG4_L()
#define ChkL1MsgFltr_UL1D_TRC_RXDFE_RXPOST_FULL()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG4_L()
#define ChkL1MsgFltr_UL1D_TRC_FHC_DBG1_INT16()	ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_FHC_M()
#define ChkL1MsgFltr_UL1D_TRC_FHC_DBG1_INT16X()	ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_FHC_M()
#define ChkL1MsgFltr_UL1D_TRC_FHC_DBG1_INT32()	ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_FHC_M()
#define ChkL1MsgFltr_UL1D_TRC_FHC_DBG1_INT32X()	ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_FHC_M()
#define ChkL1MsgFltr_UL1D_TRC_FHC_STATE()	ChkL1ClsFltr_UL1D_HSPA_SEC_DBG_FHC_M()
#define ChkL1MsgFltr_UL1D_TRC_RXD_TESTMODE()	ChkL1ClsFltr_UL1D_HSPA_SEC_RXDFE_DBG1_M()
#define ChkL1MsgFltr_UL1D_TRC_IDLE_CM()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_RXD_MEAS_START()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_RXD_MPS_START()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_RXD_SET_MS3_PARM()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_RXD_CS3_2STAGE_START()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_RXD_CS_SET_PARM()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_IDLE_RXD_TURN_ON()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_RXD_LISR_DBG()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()
#define ChkL1MsgFltr_UL1D_TRC_IDLE_FREE_RXD_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_SEC_UL1D_R6s_Meas_H()


#endif
