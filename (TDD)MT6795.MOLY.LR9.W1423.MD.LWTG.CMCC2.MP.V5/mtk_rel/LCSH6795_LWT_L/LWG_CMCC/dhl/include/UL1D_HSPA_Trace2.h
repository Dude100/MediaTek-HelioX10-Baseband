#ifndef L1TRC_UL1D_HSPA_THIRD_DEF_H
#define L1TRC_UL1D_HSPA_THIRD_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1D_TRC_STR_TXUPC_DBG(v1)  (unsigned char)(v1+0)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_POW_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0035, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_POW_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_POW_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0035, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_POW_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0135, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_POW_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_POW_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0135, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_POW_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0235, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_POW_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_POW_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0235, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_HS_DPCCH_SYM_OFFSET(v1) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0335, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_HS_DPCCH_SYM_OFFSET(v1)
#endif
#define UL1D_TRC_HS_DPCCH_SYM_OFFSET_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0335, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_POW_CHECK_INT16(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0435, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_POW_CHECK_INT16(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_TXUPC_POW_CHECK_INT16_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0435, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_POW_CHECK_ISSUE() do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0535, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_POW_CHECK_ISSUE()
#endif
#define UL1D_TRC_TXUPC_POW_CHECK_ISSUE_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0535, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_POW_CHECK_PRF_CAL(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0635, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_POW_CHECK_PRF_CAL(v1, v2)
#endif
#define UL1D_TRC_TXUPC_POW_CHECK_PRF_CAL_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0635, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_ADDSC_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0735, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_ADDSC_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_ADDSC_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0735, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_ADDSC_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0835, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_ADDSC_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_ADDSC_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0835, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_ADDSC_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0935, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_ADDSC_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_ADDSC_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0935, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_UPC_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0A35, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_UPC_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_UPC_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0A35, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_UPC_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0B35, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_UPC_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_UPC_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0B35, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_UPC_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0C35, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_UPC_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_UPC_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0C35, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_RF_BSI_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0D35, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RF_BSI_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RF_BSI_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0D35, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_RF_BSI_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x0E35, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RF_BSI_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RF_BSI_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x0E35, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_RF_BSI_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0F35, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RF_BSI_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RF_BSI_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x0F35, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TXUPC_RF_BSI_INT16G(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1035, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RF_BSI_INT16G(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RF_BSI_INT16G_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1035, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_RF_BSI_L_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1135, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RF_BSI_L_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RF_BSI_L_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1135, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_IQDC_COMP_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1235, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_IQDC_COMP_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_IQDC_COMP_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1235, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_IQDC_COMP_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1335, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_IQDC_COMP_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_IQDC_COMP_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1335, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_IQDC_COMP_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1435, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_IQDC_COMP_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_IQDC_COMP_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1435, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_PA_BSI_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1535, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_PA_BSI_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_PA_BSI_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1535, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_PA_BSI_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1635, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_PA_BSI_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_PA_BSI_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1635, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_PA_BSI_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1735, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_PA_BSI_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_PA_BSI_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1735, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_PA_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1835, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_PA_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_PA_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1835, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_PA_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1935, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_PA_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_PA_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1935, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_PA_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1A35, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_PA_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_PA_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1A35, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_MPR_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1B35, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_MPR_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_MPR_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1B35, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_MPR_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1C35, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_MPR_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_MPR_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1C35, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_MPR_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1D35, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_MPR_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_MPR_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x1D35, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_AUX_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1E35, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_AUX_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_AUX_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1E35, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_AUX_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x1F35, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_AUX_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_AUX_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x1F35, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_AUX_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2035, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_AUX_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_AUX_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2035, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_GAIN_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2135, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_GAIN_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_GAIN_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2135, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_GAIN_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2235, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_GAIN_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_GAIN_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2235, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_GAIN_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2335, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_GAIN_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_GAIN_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2335, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_DELTA_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2435, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_DELTA_STA_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_DELTA_STA_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2435, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_DELTA_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2535, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_DELTA_STA_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_DELTA_STA_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2535, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_DELTA_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2635, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_DELTA_STA_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_DELTA_STA_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2635, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_RTR_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2735, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RTR_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RTR_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2735, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_RTR_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2835, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RTR_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RTR_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2835, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_RTR_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2935, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_RTR_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_RTR_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2935, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_DBG_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2A35, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_DBG_INT16(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_DBG_INT16_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2A35, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_2S((short)(v7), (short)(v8)), TRC_MERGE_2S((short)(v9), (short)(v10)), TRC_MERGE_2S((short)(v11), (short)(v12)), TRC_MERGE_2S((short)(v13), (short)(v14)), TRC_MERGE_2S((short)(v15), (short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_DBG_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x2B35, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_DBG_INT16X(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_DBG_INT16X_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_9_DATA(TRC_MERGE_2S(0x2B35, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_2S((unsigned short)(v7), (unsigned short)(v8)), TRC_MERGE_2S((unsigned short)(v9), (unsigned short)(v10)), TRC_MERGE_2S((unsigned short)(v11), (unsigned short)(v12)), TRC_MERGE_2S((unsigned short)(v13), (unsigned short)(v14)), TRC_MERGE_2S((unsigned short)(v15), (unsigned short)(v16)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TXUPC_DBG_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2C35, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16));\
	} while(0)
#else
	#define UL1D_TRC_TXUPC_DBG_INT32(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#endif
#define UL1D_TRC_TXUPC_DBG_INT32_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16) TRC_SEND_16_DATA(TRC_MERGE_1S2C(0x2C35, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned long)(v9), (unsigned long)(v10), (unsigned long)(v11), (unsigned long)(v12), (unsigned long)(v13), (unsigned long)(v14), (unsigned long)(v15), (unsigned long)(v16))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_GENERAL_DEBUG(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x2D35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_GENERAL_DEBUG(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_GENERAL_DEBUG_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x2D35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_LOW_POWER_DEBUG(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x2E35, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_LOW_POWER_DEBUG(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_LOW_POWER_DEBUG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x2E35, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TIME_MAC_R99_DBG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TIME_MAC_R99_DBG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_TIME_MAC_R99_DBG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TIME_MAC_R6_DBG(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3035, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_TIME_MAC_R6_DBG(v1, v2)
#endif
#define UL1D_TRC_TIME_MAC_R6_DBG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3035, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ETXCRP_TICK_INFO(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3135, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v7));\
	} while(0)
#else
	#define UL1D_TRC_ETXCRP_TICK_INFO(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1D_TRC_ETXCRP_TICK_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3135, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v7))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ETXCRP_RESTRIC_ETFC_INFO(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3235, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ETXCRP_RESTRIC_ETFC_INFO(v1, v2, v3)
#endif
#define UL1D_TRC_ETXCRP_RESTRIC_ETFC_INFO_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3235, (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_ETXCRP_RV_INDEX(v1) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3335, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ETXCRP_RV_INDEX(v1)
#endif
#define UL1D_TRC_ETXCRP_RV_INDEX_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3335, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_ETXBRP_TIMING(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3435, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ETXBRP_TIMING(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_ETXBRP_TIMING_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3435, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ETXBRP_ENCODE_TIME(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3535, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ETXBRP_ENCODE_TIME(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_ETXBRP_ENCODE_TIME_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3535, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ERX_AG_RSLT(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3635, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_ERX_AG_RSLT(v1, v2)
#endif
#define UL1D_TRC_ERX_AG_RSLT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3635, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_HI_RSLT(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3735, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ERX_HI_RSLT(v1, v2, v3)
#endif
#define UL1D_TRC_ERX_HI_RSLT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x3735, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_RG_RSLT(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3835, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RG_RSLT(v1, v2)
#endif
#define UL1D_TRC_ERX_RG_RSLT_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3835, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_RG_LOW_INT() do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3935, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RG_LOW_INT()
#endif
#define UL1D_TRC_ERX_RG_LOW_INT_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3935, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_HI_SOFT_DEBUG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3A35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ERX_HI_SOFT_DEBUG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ERX_HI_SOFT_DEBUG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3A35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_ERX_HI_INT_DEBUG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3B35, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_ERX_HI_INT_DEBUG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ERX_HI_INT_DEBUG_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3B35, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_RG_DEBUG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3C35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RG_DEBUG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ERX_RG_DEBUG_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3C35, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_RG_INT_DEBUG(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3D35, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_ERX_RG_INT_DEBUG(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ERX_RG_INT_DEBUG_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3D35, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ERX_HI_NACK_BOOST(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E35, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_ERX_HI_NACK_BOOST(v1, v2)
#endif
#define UL1D_TRC_ERX_HI_NACK_BOOST_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3E35, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_E2_HIRG_MIC_RLS(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3F35, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_ERX_E2_HIRG_MIC_RLS(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ERX_E2_HIRG_MIC_RLS_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x3F35, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_E2_HIRG_PACK_FABIAS(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4035, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_ERX_E2_HIRG_PACK_FABIAS(v1, v2, v3)
#endif
#define UL1D_TRC_ERX_E2_HIRG_PACK_FABIAS_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x4035, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_ERX_E2_RG_TH(v1, v2, v3, v4) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4135, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_ERX_E2_RG_TH(v1, v2, v3, v4)
#endif
#define UL1D_TRC_ERX_E2_RG_TH_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x4135, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_FRAMERATE_INFO(v1, v2, v3, v4, v5) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4235, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1D_TRC_FRAMERATE_INFO(v1, v2, v3, v4, v5)
#endif
#define UL1D_TRC_FRAMERATE_INFO_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4235, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_FRAMERATE_RTR_INFO(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4335, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FRAMERATE_RTR_INFO(v1, v2)
#endif
#define UL1D_TRC_FRAMERATE_RTR_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4335, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UL_DCH_POW_IND_INT32(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4435, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_UL_DCH_POW_IND_INT32(v1, v2, v3)
#endif
#define UL1D_TRC_UL_DCH_POW_IND_INT32_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4435, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UL_DCH_DPCCH_BITMAP_INT32(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x4535, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_UL_DCH_DPCCH_BITMAP_INT32(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_UL_DCH_DPCCH_BITMAP_INT32_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x4535, (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_4C((unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_UL_DCH_EDCH_BITMAP_INT32(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x4635, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_UL_DCH_EDCH_BITMAP_INT32(v1, v2, v3)
#endif
#define UL1D_TRC_UL_DCH_EDCH_BITMAP_INT32_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x4635, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_FCM_GAP_START_CASCADE(v1) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4735, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_FCM_GAP_START_CASCADE(v1)
#endif
#define UL1D_TRC_FCM_GAP_START_CASCADE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4735, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MM_GEMINI_CALC_AVAIL_TIME(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x4835, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((short)(v6), (unsigned short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MM_GEMINI_CALC_AVAIL_TIME(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_MM_GEMINI_CALC_AVAIL_TIME_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x4835, (unsigned short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((short)(v6), (unsigned short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_TO_GAP_2G(v1) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4935, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_TO_GAP_2G(v1)
#endif
#define UL1D_TRC_MEAS_TO_GAP_2G_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4935, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MM_GEMINI_FCM_DONE_LISR() do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4A35, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MM_GEMINI_FCM_DONE_LISR()
#endif
#define UL1D_TRC_MM_GEMINI_FCM_DONE_LISR_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4A35, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MM_GEMINI_PICH_DONE_LISR(v1) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4B35, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_MM_GEMINI_PICH_DONE_LISR(v1)
#endif
#define UL1D_TRC_MM_GEMINI_PICH_DONE_LISR_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4B35, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MM_GEMINI_GAP_CHECK_MEAS(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x4C35, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_MM_GEMINI_GAP_CHECK_MEAS(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_MM_GEMINI_GAP_CHECK_MEAS_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x4C35, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULING_MODE(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4D35, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULING_MODE(v1, v2)
#endif
#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULING_MODE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4D35, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_INTER_FREQ_PROHIBITED(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4E35, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_INTER_FREQ_PROHIBITED(v1, v2)
#endif
#define UL1D_TRC_MEAS_INTER_FREQ_PROHIBITED_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4E35, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_WAIT_INTER_FREQ_ALLOWED(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4F35, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_WAIT_INTER_FREQ_ALLOWED(v1, v2)
#endif
#define UL1D_TRC_MEAS_WAIT_INTER_FREQ_ALLOWED_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4F35, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULER_IS_RUNNING(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5035, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULER_IS_RUNNING(v1, v2)
#endif
#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULER_IS_RUNNING_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5035, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULING(v1, v2) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x5135, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULING(v1, v2)
#endif
#define UL1D_TRC_MEAS_FREE_RUN_SCHEDULING_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x5135, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MM_GEMINI_MEAS_ENTER_IDLE(v1) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5235, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MM_GEMINI_MEAS_ENTER_IDLE(v1)
#endif
#define UL1D_TRC_MM_GEMINI_MEAS_ENTER_IDLE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5235, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_STANDBY_FCM_DONE_LISR() do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5335, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_STANDBY_FCM_DONE_LISR()
#endif
#define UL1D_TRC_STANDBY_FCM_DONE_LISR_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5335, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MM_GEMINI_STOP_PICH_TIMER() do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5435, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MM_GEMINI_STOP_PICH_TIMER()
#endif
#define UL1D_TRC_MM_GEMINI_STOP_PICH_TIMER_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5435, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MM_GEMINI_STOP_FCM_TIMER() do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5535, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MM_GEMINI_STOP_FCM_TIMER()
#endif
#define UL1D_TRC_MM_GEMINI_STOP_FCM_TIMER_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5535, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MM_GEMINI_RETURN_PICH() do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5635, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MM_GEMINI_RETURN_PICH()
#endif
#define UL1D_TRC_MM_GEMINI_RETURN_PICH_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5635, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MEAS_FRAME_IDLE(v1, v2, v3) do {\
		if(UL1D_HSPA_THIRD_Trace_Filter[0]==1 && (UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5735, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_MEAS_FRAME_IDLE(v1, v2, v3)
#endif
#define UL1D_TRC_MEAS_FRAME_IDLE_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5735, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1D_HSPA_THIRD_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1D_TRC_TXUPC_POW_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_POW_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_POW_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_HS_DPCCH_SYM_OFFSET(short v1);
void L1TRC_Send_UL1D_TRC_TXUPC_POW_CHECK_INT16(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_TXUPC_POW_CHECK_ISSUE(void);
void L1TRC_Send_UL1D_TRC_TXUPC_POW_CHECK_PRF_CAL(char v1, char v2);
void L1TRC_Send_UL1D_TRC_TXUPC_ADDSC_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_ADDSC_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_ADDSC_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_UPC_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_UPC_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_UPC_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RF_BSI_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RF_BSI_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RF_BSI_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RF_BSI_INT16G(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RF_BSI_L_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_IQDC_COMP_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_IQDC_COMP_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_IQDC_COMP_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_PA_BSI_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_PA_BSI_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_PA_BSI_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_PA_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_PA_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_PA_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_MPR_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_MPR_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_MPR_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_AUX_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_AUX_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_AUX_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_GAIN_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_GAIN_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_GAIN_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_DELTA_STA_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_DELTA_STA_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_DELTA_STA_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RTR_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RTR_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_RTR_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_TXUPC_DBG_INT16(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_DBG_INT16X(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7, unsigned short v8, unsigned short v9, unsigned short v10, unsigned short v11, unsigned short v12, unsigned short v13, unsigned short v14, unsigned short v15, unsigned short v16);
void L1TRC_Send_UL1D_TRC_TXUPC_DBG_INT32(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8, unsigned long v9, unsigned long v10, unsigned long v11, unsigned long v12, unsigned long v13, unsigned long v14, unsigned long v15, unsigned long v16);
void L1TRC_Send_UL1D_TRC_GENERAL_DEBUG(short v1, short v2, short v3, short v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_UL1D_TRC_LOW_POWER_DEBUG(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_UL1D_TRC_TIME_MAC_R99_DBG(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_TIME_MAC_R6_DBG(short v1, short v2);
void L1TRC_Send_UL1D_TRC_ETXCRP_TICK_INFO(unsigned char v1, short v2, short v3, short v4, short v5, short v6, long v7);
void L1TRC_Send_UL1D_TRC_ETXCRP_RESTRIC_ETFC_INFO(char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_ETXCRP_RV_INDEX(unsigned char v1);
void L1TRC_Send_UL1D_TRC_ETXBRP_TIMING(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1D_TRC_ETXBRP_ENCODE_TIME(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, short v7, short v8);
void L1TRC_Send_UL1D_TRC_ERX_AG_RSLT(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_ERX_HI_RSLT(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_UL1D_TRC_ERX_RG_RSLT(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_ERX_RG_LOW_INT(void);
void L1TRC_Send_UL1D_TRC_ERX_HI_SOFT_DEBUG(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_ERX_HI_INT_DEBUG(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_ERX_RG_DEBUG(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_ERX_RG_INT_DEBUG(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_ERX_HI_NACK_BOOST(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_ERX_E2_HIRG_MIC_RLS(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_ERX_E2_HIRG_PACK_FABIAS(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_ERX_E2_RG_TH(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_FRAMERATE_INFO(unsigned short v1, unsigned short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1D_TRC_FRAMERATE_RTR_INFO(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_UL_DCH_POW_IND_INT32(unsigned long v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_UL_DCH_DPCCH_BITMAP_INT32(unsigned long v1, unsigned long v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned char v6);
void L1TRC_Send_UL1D_TRC_UL_DCH_EDCH_BITMAP_INT32(unsigned long v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_FCM_GAP_START_CASCADE(short v1);
void L1TRC_Send_UL1D_TRC_MM_GEMINI_CALC_AVAIL_TIME(unsigned short v1, short v2, unsigned short v3, short v4, unsigned short v5, short v6, unsigned short v7, short v8);
void L1TRC_Send_UL1D_TRC_MEAS_TO_GAP_2G(short v1);
void L1TRC_Send_UL1D_TRC_MM_GEMINI_FCM_DONE_LISR(void);
void L1TRC_Send_UL1D_TRC_MM_GEMINI_PICH_DONE_LISR(short v1);
void L1TRC_Send_UL1D_TRC_MM_GEMINI_GAP_CHECK_MEAS(short v1, unsigned long v2, short v3, unsigned long v4, short v5, short v6);
void L1TRC_Send_UL1D_TRC_MEAS_FREE_RUN_SCHEDULING_MODE(short v1, short v2);
void L1TRC_Send_UL1D_TRC_MEAS_INTER_FREQ_PROHIBITED(short v1, short v2);
void L1TRC_Send_UL1D_TRC_MEAS_WAIT_INTER_FREQ_ALLOWED(short v1, short v2);
void L1TRC_Send_UL1D_TRC_MEAS_FREE_RUN_SCHEDULER_IS_RUNNING(short v1, short v2);
void L1TRC_Send_UL1D_TRC_MEAS_FREE_RUN_SCHEDULING(short v1, short v2);
void L1TRC_Send_UL1D_TRC_MM_GEMINI_MEAS_ENTER_IDLE(unsigned char v1);
void L1TRC_Send_UL1D_TRC_STANDBY_FCM_DONE_LISR(void);
void L1TRC_Send_UL1D_TRC_MM_GEMINI_STOP_PICH_TIMER(void);
void L1TRC_Send_UL1D_TRC_MM_GEMINI_STOP_FCM_TIMER(void);
void L1TRC_Send_UL1D_TRC_MM_GEMINI_RETURN_PICH(void);
void L1TRC_Send_UL1D_TRC_MEAS_FRAME_IDLE(short v1, short v2, unsigned long v3);

void Set_UL1D_HSPA_THIRD_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1D_HSPA_THIRD()	(UL1D_HSPA_THIRD_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_TXUPC_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_TXUPC_DUMP_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_RXBRP_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_STA_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_CHECK_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_ADDSC_STA_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RF_BSI_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RF_BSI_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_IQDC_COMP_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_BSI_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_STA_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_MPR_STA_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_AUX_STA_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_GAIN_STA_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DELTA_STA_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RTR_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_RXBRP_DBG_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_RXBRP_DBG_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_MAC_TIME_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_MAC_TIME_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXCRP_H()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXCRP_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXCRP_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXBRP_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXBRP_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_H()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_L()	(ChkL1ModFltr_UL1D_HSPA_THIRD()&&((UL1D_HSPA_THIRD_Trace_Filter[4]&0x40)!=0))
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_POW_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_POW_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_POW_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_HS_DPCCH_SYM_OFFSET()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_POW_CHECK_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_CHECK_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_POW_CHECK_ISSUE()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_CHECK_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_POW_CHECK_PRF_CAL()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_POW_CHECK_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_ADDSC_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_ADDSC_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_ADDSC_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_ADDSC_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_ADDSC_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_ADDSC_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_UPC_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_UPC_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_UPC_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RF_BSI_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RF_BSI_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RF_BSI_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RF_BSI_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RF_BSI_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RF_BSI_INT16G()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RF_BSI_M()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RF_BSI_L_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RF_BSI_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_IQDC_COMP_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_IQDC_COMP_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_IQDC_COMP_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_IQDC_COMP_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_IQDC_COMP_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_IQDC_COMP_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_PA_BSI_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_BSI_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_PA_BSI_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_BSI_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_PA_BSI_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_BSI_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_PA_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_PA_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_PA_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_PA_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_MPR_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_MPR_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_MPR_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_MPR_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_MPR_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_MPR_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_AUX_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_AUX_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_AUX_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_AUX_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_AUX_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_AUX_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_GAIN_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_GAIN_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_GAIN_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_GAIN_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_GAIN_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_GAIN_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_DELTA_STA_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DELTA_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_DELTA_STA_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DELTA_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_DELTA_STA_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DELTA_STA_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RTR_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RTR_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RTR_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RTR_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_RTR_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_RTR_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_DBG_INT16()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_DBG_INT16X()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_TXUPC_DBG_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_GENERAL_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_LOW_POWER_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_TIME_MAC_R99_DBG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_MAC_TIME_L()
#define ChkL1MsgFltr_UL1D_TRC_TIME_MAC_R6_DBG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_MAC_TIME_L()
#define ChkL1MsgFltr_UL1D_TRC_ETXCRP_TICK_INFO()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXCRP_M()
#define ChkL1MsgFltr_UL1D_TRC_ETXCRP_RESTRIC_ETFC_INFO()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXCRP_H()
#define ChkL1MsgFltr_UL1D_TRC_ETXCRP_RV_INDEX()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXCRP_L()
#define ChkL1MsgFltr_UL1D_TRC_ETXBRP_TIMING()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXBRP_L()
#define ChkL1MsgFltr_UL1D_TRC_ETXBRP_ENCODE_TIME()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ETXBRP_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_AG_RSLT()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_H()
#define ChkL1MsgFltr_UL1D_TRC_ERX_HI_RSLT()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RG_RSLT()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RG_LOW_INT()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_HI_SOFT_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_HI_INT_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_L()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RG_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_RG_INT_DEBUG()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_HI_NACK_BOOST()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_H()
#define ChkL1MsgFltr_UL1D_TRC_ERX_E2_HIRG_MIC_RLS()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_E2_HIRG_PACK_FABIAS()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_ERX_E2_RG_TH()	ChkL1ClsFltr_UL1D_HSPA_THIRD_ERX_M()
#define ChkL1MsgFltr_UL1D_TRC_FRAMERATE_INFO()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_FRAMERATE_RTR_INFO()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_DBG_L()
#define ChkL1MsgFltr_UL1D_TRC_UL_DCH_POW_IND_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_UL_DCH_DPCCH_BITMAP_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_UL_DCH_EDCH_BITMAP_INT32()	ChkL1ClsFltr_UL1D_HSPA_THIRD_TXUPC_UPC_STA_M()
#define ChkL1MsgFltr_UL1D_TRC_FCM_GAP_START_CASCADE()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MM_GEMINI_CALC_AVAIL_TIME()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_TO_GAP_2G()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MM_GEMINI_FCM_DONE_LISR()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MM_GEMINI_PICH_DONE_LISR()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MM_GEMINI_GAP_CHECK_MEAS()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_FREE_RUN_SCHEDULING_MODE()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_INTER_FREQ_PROHIBITED()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_WAIT_INTER_FREQ_ALLOWED()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_FREE_RUN_SCHEDULER_IS_RUNNING()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_FREE_RUN_SCHEDULING()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MM_GEMINI_MEAS_ENTER_IDLE()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_STANDBY_FCM_DONE_LISR()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MM_GEMINI_STOP_PICH_TIMER()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MM_GEMINI_STOP_FCM_TIMER()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MM_GEMINI_RETURN_PICH()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()
#define ChkL1MsgFltr_UL1D_TRC_MEAS_FRAME_IDLE()	ChkL1ClsFltr_UL1D_HSPA_THIRD_DBG_M()


#endif
