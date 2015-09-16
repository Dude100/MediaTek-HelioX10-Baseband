#ifndef L1TRC_L1TAMR_DEF_H
#define L1TRC_L1TAMR_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define L1T_Trc_AMR_QI_INFO(v1, v2, v3, v4) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0029, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trc_AMR_QI_INFO(v1, v2, v3, v4)
#endif
#define L1T_Trc_AMR_QI_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0029, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trc_AFS_EQ_CI(v1, v2, v3, v4) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0129, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trc_AFS_EQ_CI(v1, v2, v3, v4)
#endif
#define L1T_Trc_AFS_EQ_CI_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0129, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trc_AHS_EQ_CI(v1, v2) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0229, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trc_AHS_EQ_CI(v1, v2)
#endif
#define L1T_Trc_AHS_EQ_CI_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0229, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trc_AFS_EQ_RNV(v1, v2, v3, v4) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0329, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trc_AFS_EQ_RNV(v1, v2, v3, v4)
#endif
#define L1T_Trc_AFS_EQ_RNV_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0329, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trc_AHS_EQ_RNV(v1, v2) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0429, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trc_AHS_EQ_RNV(v1, v2)
#endif
#define L1T_Trc_AHS_EQ_RNV_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0429, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trc_AFS_ANT_DIV(v1, v2, v3, v4) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0529, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trc_AFS_ANT_DIV(v1, v2, v3, v4)
#endif
#define L1T_Trc_AFS_ANT_DIV_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0529, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trc_AHS_ANT_DIV(v1, v2) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0629, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trc_AHS_ANT_DIV(v1, v2)
#endif
#define L1T_Trc_AHS_ANT_DIV_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0629, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trc_AFS_ANT_26_DIV(v1, v2, v3, v4) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0729, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trc_AFS_ANT_26_DIV(v1, v2, v3, v4)
#endif
#define L1T_Trc_AFS_ANT_26_DIV_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0729, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trc_AHS_ANT_26_DIV(v1, v2) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0829, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trc_AHS_ANT_26_DIV(v1, v2)
#endif
#define L1T_Trc_AHS_ANT_26_DIV_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0829, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trc_AMR_CI_FILTER(v1, v2) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0929, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trc_AMR_CI_FILTER(v1, v2)
#endif
#define L1T_Trc_AMR_CI_FILTER_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0929, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trc_AMR_CI_FIT(v1, v2) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A29, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trc_AMR_CI_FIT(v1, v2)
#endif
#define L1T_Trc_AMR_CI_FIT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A29, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trc_AMR_RNV_FILTER(v1, v2) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B29, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trc_AMR_RNV_FILTER(v1, v2)
#endif
#define L1T_Trc_AMR_RNV_FILTER_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B29, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trc_AMR_ANT_DIV_FILTER(v1, v2) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C29, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trc_AMR_ANT_DIV_FILTER(v1, v2)
#endif
#define L1T_Trc_AMR_ANT_DIV_FILTER_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C29, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1T_Trc_AMR_CI_COMPEN(v1, v2, v3) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D29, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define L1T_Trc_AMR_CI_COMPEN(v1, v2, v3)
#endif
#define L1T_Trc_AMR_CI_COMPEN_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D29, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define L1T_Trc_AMR_SAIC_FLAG(v1) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0E29, (unsigned short)(v1)));\
	} while(0)
#else
	#define L1T_Trc_AMR_SAIC_FLAG(v1)
#endif
#define L1T_Trc_AMR_SAIC_FLAG_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0E29, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trc_AMR_DSP_EQSOSUM(v1, v2, v3, v4) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0F29, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define L1T_Trc_AMR_DSP_EQSOSUM(v1, v2, v3, v4)
#endif
#define L1T_Trc_AMR_DSP_EQSOSUM_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0F29, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trc_AMR_DSP_EQSOFT(v1, v2, v3, v4) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1029, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trc_AMR_DSP_EQSOFT(v1, v2, v3, v4)
#endif
#define L1T_Trc_AMR_DSP_EQSOFT_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1029, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trc_AMR_EQSOFT_FILTER(v1, v2, v3, v4) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1129, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trc_AMR_EQSOFT_FILTER(v1, v2, v3, v4)
#endif
#define L1T_Trc_AMR_EQSOFT_FILTER_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1129, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trc_AMR_ANTDIV_FILTER(v1, v2, v3) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1229, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trc_AMR_ANTDIV_FILTER(v1, v2, v3)
#endif
#define L1T_Trc_AMR_ANTDIV_FILTER_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1229, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1T_Trc_AMR_DSP_C_VALUE(v1, v2, v3, v4) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1329, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trc_AMR_DSP_C_VALUE(v1, v2, v3, v4)
#endif
#define L1T_Trc_AMR_DSP_C_VALUE_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1329, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trc_AMR_C_VALUE_FILTER(v1, v2, v3) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1429, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_Trc_AMR_C_VALUE_FILTER(v1, v2, v3)
#endif
#define L1T_Trc_AMR_C_VALUE_FILTER_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1429, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1T_Trc_AMR_QI_MAPPING(v1, v2, v3) do {\
		if(L1TAMR_Trace_Filter[0]==1 && (L1TAMR_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1529, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define L1T_Trc_AMR_QI_MAPPING(v1, v2, v3)
#endif
#define L1T_Trc_AMR_QI_MAPPING_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1529, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1TAMR_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1T_Trc_AMR_QI_INFO(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1T_Trc_AFS_EQ_CI(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1T_Trc_AHS_EQ_CI(short v1, short v2);
void L1TRC_Send_L1T_Trc_AFS_EQ_RNV(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1T_Trc_AHS_EQ_RNV(short v1, short v2);
void L1TRC_Send_L1T_Trc_AFS_ANT_DIV(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1T_Trc_AHS_ANT_DIV(short v1, short v2);
void L1TRC_Send_L1T_Trc_AFS_ANT_26_DIV(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1T_Trc_AHS_ANT_26_DIV(short v1, short v2);
void L1TRC_Send_L1T_Trc_AMR_CI_FILTER(short v1, short v2);
void L1TRC_Send_L1T_Trc_AMR_CI_FIT(short v1, short v2);
void L1TRC_Send_L1T_Trc_AMR_RNV_FILTER(short v1, short v2);
void L1TRC_Send_L1T_Trc_AMR_ANT_DIV_FILTER(short v1, short v2);
void L1TRC_Send_L1T_Trc_AMR_CI_COMPEN(short v1, short v2, short v3);
void L1TRC_Send_L1T_Trc_AMR_SAIC_FLAG(unsigned short v1);
void L1TRC_Send_L1T_Trc_AMR_DSP_EQSOSUM(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_L1T_Trc_AMR_DSP_EQSOFT(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1T_Trc_AMR_EQSOFT_FILTER(short v1, short v2, short v3, char v4);
void L1TRC_Send_L1T_Trc_AMR_ANTDIV_FILTER(short v1, short v2, char v3);
void L1TRC_Send_L1T_Trc_AMR_DSP_C_VALUE(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1T_Trc_AMR_C_VALUE_FILTER(short v1, short v2, char v3);
void L1TRC_Send_L1T_Trc_AMR_QI_MAPPING(short v1, short v2, short v3);

void Set_L1TAMR_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1TAMR()	(L1TAMR_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1TAMR_AMR_QI_INFO_H()	(ChkL1ModFltr_L1TAMR()&&((L1TAMR_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1TAMR_AMR_QI_INPUT_M()	(ChkL1ModFltr_L1TAMR()&&((L1TAMR_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1TAMR_AMR_QI_FILTER_M()	(ChkL1ModFltr_L1TAMR()&&((L1TAMR_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1TAMR_AMR_QI_COMPEN_M()	(ChkL1ModFltr_L1TAMR()&&((L1TAMR_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1TAMR_AMR_QI_COMPEN_H()	(ChkL1ModFltr_L1TAMR()&&((L1TAMR_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1TAMR_AMR_QI_INPUT_H()	(ChkL1ModFltr_L1TAMR()&&((L1TAMR_Trace_Filter[1]&0x20)!=0))
#define ChkL1MsgFltr_L1T_Trc_AMR_QI_INFO()	ChkL1ClsFltr_L1TAMR_AMR_QI_INFO_H()
#define ChkL1MsgFltr_L1T_Trc_AFS_EQ_CI()	ChkL1ClsFltr_L1TAMR_AMR_QI_INPUT_M()
#define ChkL1MsgFltr_L1T_Trc_AHS_EQ_CI()	ChkL1ClsFltr_L1TAMR_AMR_QI_INPUT_M()
#define ChkL1MsgFltr_L1T_Trc_AFS_EQ_RNV()	ChkL1ClsFltr_L1TAMR_AMR_QI_INPUT_M()
#define ChkL1MsgFltr_L1T_Trc_AHS_EQ_RNV()	ChkL1ClsFltr_L1TAMR_AMR_QI_INPUT_M()
#define ChkL1MsgFltr_L1T_Trc_AFS_ANT_DIV()	ChkL1ClsFltr_L1TAMR_AMR_QI_INPUT_M()
#define ChkL1MsgFltr_L1T_Trc_AHS_ANT_DIV()	ChkL1ClsFltr_L1TAMR_AMR_QI_INPUT_M()
#define ChkL1MsgFltr_L1T_Trc_AFS_ANT_26_DIV()	ChkL1ClsFltr_L1TAMR_AMR_QI_INPUT_M()
#define ChkL1MsgFltr_L1T_Trc_AHS_ANT_26_DIV()	ChkL1ClsFltr_L1TAMR_AMR_QI_INPUT_M()
#define ChkL1MsgFltr_L1T_Trc_AMR_CI_FILTER()	ChkL1ClsFltr_L1TAMR_AMR_QI_FILTER_M()
#define ChkL1MsgFltr_L1T_Trc_AMR_CI_FIT()	ChkL1ClsFltr_L1TAMR_AMR_QI_FILTER_M()
#define ChkL1MsgFltr_L1T_Trc_AMR_RNV_FILTER()	ChkL1ClsFltr_L1TAMR_AMR_QI_FILTER_M()
#define ChkL1MsgFltr_L1T_Trc_AMR_ANT_DIV_FILTER()	ChkL1ClsFltr_L1TAMR_AMR_QI_FILTER_M()
#define ChkL1MsgFltr_L1T_Trc_AMR_CI_COMPEN()	ChkL1ClsFltr_L1TAMR_AMR_QI_COMPEN_H()
#define ChkL1MsgFltr_L1T_Trc_AMR_SAIC_FLAG()	ChkL1ClsFltr_L1TAMR_AMR_QI_INPUT_H()
#define ChkL1MsgFltr_L1T_Trc_AMR_DSP_EQSOSUM()	ChkL1ClsFltr_L1TAMR_AMR_QI_INPUT_M()
#define ChkL1MsgFltr_L1T_Trc_AMR_DSP_EQSOFT()	ChkL1ClsFltr_L1TAMR_AMR_QI_INPUT_M()
#define ChkL1MsgFltr_L1T_Trc_AMR_EQSOFT_FILTER()	ChkL1ClsFltr_L1TAMR_AMR_QI_FILTER_M()
#define ChkL1MsgFltr_L1T_Trc_AMR_ANTDIV_FILTER()	ChkL1ClsFltr_L1TAMR_AMR_QI_FILTER_M()
#define ChkL1MsgFltr_L1T_Trc_AMR_DSP_C_VALUE()	ChkL1ClsFltr_L1TAMR_AMR_QI_INPUT_H()
#define ChkL1MsgFltr_L1T_Trc_AMR_C_VALUE_FILTER()	ChkL1ClsFltr_L1TAMR_AMR_QI_FILTER_M()
#define ChkL1MsgFltr_L1T_Trc_AMR_QI_MAPPING()	ChkL1ClsFltr_L1TAMR_AMR_QI_COMPEN_H()


#endif
