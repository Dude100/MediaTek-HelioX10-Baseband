#ifndef L1TRC_L1C_GPRS3_DEF_H
#define L1TRC_L1C_GPRS3_DEF_H

/******************************/
/* String category definition */
/******************************/
#define TDRTB_Str_Bool(v1)  (unsigned char)(v1+0)
#define TDRTB_Str_RAT(v1)  (unsigned char)(v1+2)
#define TDRTB_Str_SIM(v1)  (unsigned char)(v1+4)
#define TDRTB_Str_MEAS(v1)  (unsigned char)(v1+6)
#define TDRTB_Str_FCB(v1)  (unsigned char)(v1+10)
#define TDRTB_Str_MODE(v1)  (unsigned char)(v1+12)
#define TDRTB_Str_Priority(v1)  (unsigned char)(v1+14)
#define TDRTB_Str_Task_Type(v1)  (unsigned char)(v1+20)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_0(v1, v2, v3, v4) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0038, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TDRTB_Trace_0(v1, v2, v3, v4)
#endif
#define TDRTB_Trace_0_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0038, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_1_GSM(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0138, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v3));\
	} while(0)
#else
	#define TDRTB_Trace_1_GSM(v1, v2, v3, v4, v5, v6, v7)
#endif
#define TDRTB_Trace_1_GSM_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0138, (short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_1_TD(v1, v2, v3, v4) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0238, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define TDRTB_Trace_1_TD(v1, v2, v3, v4)
#endif
#define TDRTB_Trace_1_TD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0238, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_2(v1, v2, v3, v4) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0338, (short)(v4)), (long)(v1), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define TDRTB_Trace_2(v1, v2, v3, v4)
#endif
#define TDRTB_Trace_2_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0338, (short)(v4)), (long)(v1), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_3_GSM(v1, v2) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0438, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define TDRTB_Trace_3_GSM(v1, v2)
#endif
#define TDRTB_Trace_3_GSM_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0438, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_3_TD(v1, v2) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0538, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define TDRTB_Trace_3_TD(v1, v2)
#endif
#define TDRTB_Trace_3_TD_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0538, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_4(v1, v2) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0638, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define TDRTB_Trace_4(v1, v2)
#endif
#define TDRTB_Trace_4_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0638, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_5(v1, v2, v3) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0738, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define TDRTB_Trace_5(v1, v2, v3)
#endif
#define TDRTB_Trace_5_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0738, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_6_GSM(v1, v2, v3) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0838, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define TDRTB_Trace_6_GSM(v1, v2, v3)
#endif
#define TDRTB_Trace_6_GSM_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0838, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_6_TD(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0938, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define TDRTB_Trace_6_TD(v1, v2, v3, v4, v5, v6)
#endif
#define TDRTB_Trace_6_TD_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0938, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_7_GSM(v1) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A38, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TDRTB_Trace_7_GSM(v1)
#endif
#define TDRTB_Trace_7_GSM_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A38, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_7_TD(v1, v2) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B38, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define TDRTB_Trace_7_TD(v1, v2)
#endif
#define TDRTB_Trace_7_TD_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B38, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_8(v1, v2) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C38, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define TDRTB_Trace_8(v1, v2)
#endif
#define TDRTB_Trace_8_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C38, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_9(v1, v2, v3) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D38, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3));\
	} while(0)
#else
	#define TDRTB_Trace_9(v1, v2, v3)
#endif
#define TDRTB_Trace_9_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D38, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_10(v1) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E38, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TDRTB_Trace_10(v1)
#endif
#define TDRTB_Trace_10_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E38, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_11_GSM(v1, v2, v3) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F38, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define TDRTB_Trace_11_GSM(v1, v2, v3)
#endif
#define TDRTB_Trace_11_GSM_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F38, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_11_TD(v1, v2, v3) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1038, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define TDRTB_Trace_11_TD(v1, v2, v3)
#endif
#define TDRTB_Trace_11_TD_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1038, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_12(v1, v2, v3) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1138, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define TDRTB_Trace_12(v1, v2, v3)
#endif
#define TDRTB_Trace_12_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1138, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_13_GSM(v1, v2, v3) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1238, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define TDRTB_Trace_13_GSM(v1, v2, v3)
#endif
#define TDRTB_Trace_13_GSM_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1238, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_13_TD(v1, v2, v3) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1338, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define TDRTB_Trace_13_TD(v1, v2, v3)
#endif
#define TDRTB_Trace_13_TD_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1338, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_14(v1) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1438, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TDRTB_Trace_14(v1)
#endif
#define TDRTB_Trace_14_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1438, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_15_GSM(v1, v2) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1538, (short)(v2)), (long)(v1));\
	} while(0)
#else
	#define TDRTB_Trace_15_GSM(v1, v2)
#endif
#define TDRTB_Trace_15_GSM_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1538, (short)(v2)), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_15_TD(v1, v2) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1638, (short)(v2)), (long)(v1));\
	} while(0)
#else
	#define TDRTB_Trace_15_TD(v1, v2)
#endif
#define TDRTB_Trace_15_TD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1638, (short)(v2)), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_16(v1) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1738, (short)(v1)));\
	} while(0)
#else
	#define TDRTB_Trace_16(v1)
#endif
#define TDRTB_Trace_16_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1738, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_17(v1) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1838, (short)(v1)));\
	} while(0)
#else
	#define TDRTB_Trace_17(v1)
#endif
#define TDRTB_Trace_17_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1838, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_18(v1) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1938, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define TDRTB_Trace_18(v1)
#endif
#define TDRTB_Trace_18_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1938, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_19(v1) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1A38, (short)(v1)));\
	} while(0)
#else
	#define TDRTB_Trace_19(v1)
#endif
#define TDRTB_Trace_19_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1A38, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_20(v1, v2) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B38, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define TDRTB_Trace_20(v1, v2)
#endif
#define TDRTB_Trace_20_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B38, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_21_TD(v1, v2, v3) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1C38, (short)(v2)), (long)(v1), (long)(v3));\
	} while(0)
#else
	#define TDRTB_Trace_21_TD(v1, v2, v3)
#endif
#define TDRTB_Trace_21_TD_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1C38, (short)(v2)), (long)(v1), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_22_TD(v1, v2) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D38, (short)(v1)), (long)(v2));\
	} while(0)
#else
	#define TDRTB_Trace_22_TD(v1, v2)
#endif
#define TDRTB_Trace_22_TD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D38, (short)(v1)), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_23_TD(v1, v2) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E38, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define TDRTB_Trace_23_TD(v1, v2)
#endif
#define TDRTB_Trace_23_TD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1E38, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_24(v1, v2, v3, v4) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1F38, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define TDRTB_Trace_24(v1, v2, v3, v4)
#endif
#define TDRTB_Trace_24_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x1F38, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define TDRTB_Trace_25(v1, v2) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2038, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define TDRTB_Trace_25(v1, v2)
#endif
#define TDRTB_Trace_25_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2038, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_TDDM_RF_CONFLICT(v1) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2138, (short)(v1)));\
	} while(0)
#else
	#define L1D_TDDM_RF_CONFLICT(v1)
#endif
#define L1D_TDDM_RF_CONFLICT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2138, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_TDDM_RF_CONFLICT_TIME(v1, v2, v3, v4) do {\
		if(L1C_GPRS3_Trace_Filter[0]==1 && (L1C_GPRS3_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2238, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4));\
	} while(0)
#else
	#define L1D_TDDM_RF_CONFLICT_TIME(v1, v2, v3, v4)
#endif
#define L1D_TDDM_RF_CONFLICT_TIME_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2238, (short)(v1)), TRC_MERGE_1S2C((short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1C_GPRS3_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_TDRTB_Trace_0(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_TDRTB_Trace_1_GSM(long v1, short v2, long v3, short v4, short v5, unsigned char v6, unsigned char v7);
void L1TRC_Send_TDRTB_Trace_1_TD(long v1, short v2, short v3, unsigned char v4);
void L1TRC_Send_TDRTB_Trace_2(long v1, long v2, long v3, short v4);
void L1TRC_Send_TDRTB_Trace_3_GSM(unsigned char v1, unsigned char v2);
void L1TRC_Send_TDRTB_Trace_3_TD(unsigned char v1, unsigned char v2);
void L1TRC_Send_TDRTB_Trace_4(unsigned char v1, unsigned char v2);
void L1TRC_Send_TDRTB_Trace_5(unsigned char v1, long v2, short v3);
void L1TRC_Send_TDRTB_Trace_6_GSM(unsigned char v1, long v2, short v3);
void L1TRC_Send_TDRTB_Trace_6_TD(unsigned char v1, long v2, short v3, long v4, long v5, unsigned char v6);
void L1TRC_Send_TDRTB_Trace_7_GSM(unsigned char v1);
void L1TRC_Send_TDRTB_Trace_7_TD(unsigned char v1, unsigned char v2);
void L1TRC_Send_TDRTB_Trace_8(unsigned char v1, long v2);
void L1TRC_Send_TDRTB_Trace_9(unsigned char v1, unsigned char v2, long v3);
void L1TRC_Send_TDRTB_Trace_10(unsigned char v1);
void L1TRC_Send_TDRTB_Trace_11_GSM(unsigned char v1, long v2, short v3);
void L1TRC_Send_TDRTB_Trace_11_TD(unsigned char v1, long v2, short v3);
void L1TRC_Send_TDRTB_Trace_12(unsigned char v1, long v2, short v3);
void L1TRC_Send_TDRTB_Trace_13_GSM(unsigned char v1, long v2, short v3);
void L1TRC_Send_TDRTB_Trace_13_TD(unsigned char v1, long v2, short v3);
void L1TRC_Send_TDRTB_Trace_14(unsigned char v1);
void L1TRC_Send_TDRTB_Trace_15_GSM(long v1, short v2);
void L1TRC_Send_TDRTB_Trace_15_TD(long v1, short v2);
void L1TRC_Send_TDRTB_Trace_16(short v1);
void L1TRC_Send_TDRTB_Trace_17(short v1);
void L1TRC_Send_TDRTB_Trace_18(unsigned char v1);
void L1TRC_Send_TDRTB_Trace_19(short v1);
void L1TRC_Send_TDRTB_Trace_20(unsigned char v1, unsigned char v2);
void L1TRC_Send_TDRTB_Trace_21_TD(long v1, short v2, long v3);
void L1TRC_Send_TDRTB_Trace_22_TD(short v1, long v2);
void L1TRC_Send_TDRTB_Trace_23_TD(unsigned char v1, long v2);
void L1TRC_Send_TDRTB_Trace_24(unsigned char v1, long v2, long v3, long v4);
void L1TRC_Send_TDRTB_Trace_25(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1D_TDDM_RF_CONFLICT(short v1);
void L1TRC_Send_L1D_TDDM_RF_CONFLICT_TIME(short v1, long v2, short v3, long v4);

void Set_L1C_GPRS3_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1C_GPRS3()	(L1C_GPRS3_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1C_GPRS3_RTB_M()	(ChkL1ModFltr_L1C_GPRS3()&&((L1C_GPRS3_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1C_GPRS3_RTB_L()	(ChkL1ModFltr_L1C_GPRS3()&&((L1C_GPRS3_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_TDRTB_Trace_0()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_1_GSM()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_1_TD()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_2()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_3_GSM()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_3_TD()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_4()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_5()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_6_GSM()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_6_TD()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_7_GSM()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_7_TD()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_8()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_9()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_10()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_11_GSM()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_11_TD()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_12()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_13_GSM()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_13_TD()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_14()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_15_GSM()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_15_TD()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_16()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_17()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_18()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_19()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_20()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_21_TD()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_22_TD()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_23_TD()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_24()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_TDRTB_Trace_25()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_L1D_TDDM_RF_CONFLICT()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()
#define ChkL1MsgFltr_L1D_TDDM_RF_CONFLICT_TIME()	ChkL1ClsFltr_L1C_GPRS3_RTB_M()


#endif
