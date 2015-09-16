#ifndef L1TRC_L1C_GPRS2_DEF_H
#define L1TRC_L1C_GPRS2_DEF_H

/******************************/
/* String category definition */
/******************************/
#define RTB_Str_RAT(v1)  (unsigned char)(v1+0)
#define RTB_Str_Unit(v1)  (unsigned char)(v1+4)
#define RTB_Str_Protect(v1)  (unsigned char)(v1+8)
#define RTB_Str_SIM(v1)  (unsigned char)(v1+10)
#define RTB_Str_Channel_Protect(v1)  (unsigned char)(v1+14)
#define RTB_Str_Message(v1)  (unsigned char)(v1+16)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_1(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0037, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4), (long)(v6), (unsigned long)(v7));\
	} while(0)
#else
	#define RTB_Trace_1(v1, v2, v3, v4, v5, v6, v7)
#endif
#define RTB_Trace_1_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0037, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4), (long)(v6), (unsigned long)(v7))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_2(v1) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0137, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define RTB_Trace_2(v1)
#endif
#define RTB_Trace_2_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0137, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_3(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0237, (short)(v3)), TRC_MERGE_1S2C((short)(v5), (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define RTB_Trace_3(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define RTB_Trace_3_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0237, (short)(v3)), TRC_MERGE_1S2C((short)(v5), (char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), (unsigned char)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_4(v1, v2, v3, v4) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0337, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define RTB_Trace_4(v1, v2, v3, v4)
#endif
#define RTB_Trace_4_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0337, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_5(v1, v2, v3, v4) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0437, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define RTB_Trace_5(v1, v2, v3, v4)
#endif
#define RTB_Trace_5_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0437, (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_6(v1, v2, v3) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0537, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define RTB_Trace_6(v1, v2, v3)
#endif
#define RTB_Trace_6_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0537, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_7(v1, v2, v3, v4, v5) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0637, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define RTB_Trace_7(v1, v2, v3, v4, v5)
#endif
#define RTB_Trace_7_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0637, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_8(v1, v2) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0737, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define RTB_Trace_8(v1, v2)
#endif
#define RTB_Trace_8_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0737, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_9(v1, v2, v3, v4, v5) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0837, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define RTB_Trace_9(v1, v2, v3, v4, v5)
#endif
#define RTB_Trace_9_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0837, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_10(v1, v2, v3) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0937, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define RTB_Trace_10(v1, v2, v3)
#endif
#define RTB_Trace_10_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0937, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_11(v1, v2, v3, v4, v5) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0A37, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v5));\
	} while(0)
#else
	#define RTB_Trace_11(v1, v2, v3, v4, v5)
#endif
#define RTB_Trace_11_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0A37, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_12(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0B37, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v7), TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (long)(v6));\
	} while(0)
#else
	#define RTB_Trace_12(v1, v2, v3, v4, v5, v6, v7)
#endif
#define RTB_Trace_12_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0B37, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v7), TRC_BOXSTER_PAD), (unsigned long)(v4), (unsigned long)(v5), (long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_13(v1, v2, v3) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C37, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define RTB_Trace_13(v1, v2, v3)
#endif
#define RTB_Trace_13_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C37, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RTB_Trace_14(v1, v2, v3, v4) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D37, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), (unsigned char)(v4)));\
	} while(0)
#else
	#define RTB_Trace_14(v1, v2, v3, v4)
#endif
#define RTB_Trace_14_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D37, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v2), (unsigned char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RTB_Trace_15(v1, v2, v3) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E37, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define RTB_Trace_15(v1, v2, v3)
#endif
#define RTB_Trace_15_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E37, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_16(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F37, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v6)));\
	} while(0)
#else
	#define RTB_Trace_16(v1, v2, v3, v4, v5, v6)
#endif
#define RTB_Trace_16_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F37, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), (unsigned char)(v6)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RTB_Trace_17(v1, v2, v3, v4, v5) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1037, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define RTB_Trace_17(v1, v2, v3, v4, v5)
#endif
#define RTB_Trace_17_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1037, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_18(v1) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1137, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define RTB_Trace_18(v1)
#endif
#define RTB_Trace_18_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1137, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RTB_Trace_19(v1, v2, v3) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1237, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3));\
	} while(0)
#else
	#define RTB_Trace_19(v1, v2, v3)
#endif
#define RTB_Trace_19_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1237, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_20(v1) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1337, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define RTB_Trace_20(v1)
#endif
#define RTB_Trace_20_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1337, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RTB_Trace_21(v1, v2) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1437, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define RTB_Trace_21(v1, v2)
#endif
#define RTB_Trace_21_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1437, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_22(v1) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1537, (unsigned short)(v1)));\
	} while(0)
#else
	#define RTB_Trace_22(v1)
#endif
#define RTB_Trace_22_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1537, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_23(v1, v2, v3, v4) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1637, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define RTB_Trace_23(v1, v2, v3, v4)
#endif
#define RTB_Trace_23_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1637, (short)(v3)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_24(v1, v2) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1737, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define RTB_Trace_24(v1, v2)
#endif
#define RTB_Trace_24_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1737, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define RTB_Trace_25(v1, v2) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1837, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define RTB_Trace_25(v1, v2)
#endif
#define RTB_Trace_25_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1837, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RTB_Trace_26(v1, v2, v3, v4) do {\
		if(L1C_GPRS2_Trace_Filter[0]==1 && (L1C_GPRS2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1937, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define RTB_Trace_26(v1, v2, v3, v4)
#endif
#define RTB_Trace_26_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x1937, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3), (unsigned long)(v4))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1C_GPRS2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_RTB_Trace_1(unsigned char v1, unsigned char v2, unsigned char v3, long v4, unsigned char v5, long v6, unsigned long v7);
void L1TRC_Send_RTB_Trace_2(unsigned long v1);
void L1TRC_Send_RTB_Trace_3(char v1, unsigned char v2, short v3, unsigned char v4, short v5, unsigned char v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_RTB_Trace_4(unsigned char v1, unsigned char v2, short v3, long v4);
void L1TRC_Send_RTB_Trace_5(unsigned char v1, unsigned char v2, unsigned char v3, short v4);
void L1TRC_Send_RTB_Trace_6(long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_RTB_Trace_7(unsigned char v1, unsigned char v2, short v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_RTB_Trace_8(unsigned char v1, unsigned char v2);
void L1TRC_Send_RTB_Trace_9(short v1, unsigned char v2, unsigned char v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_RTB_Trace_10(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_RTB_Trace_11(unsigned char v1, unsigned char v2, long v3, unsigned char v4, long v5);
void L1TRC_Send_RTB_Trace_12(unsigned char v1, unsigned char v2, short v3, unsigned long v4, unsigned long v5, long v6, unsigned char v7);
void L1TRC_Send_RTB_Trace_13(unsigned char v1, unsigned char v2, short v3);
void L1TRC_Send_RTB_Trace_14(short v1, unsigned char v2, short v3, unsigned char v4);
void L1TRC_Send_RTB_Trace_15(unsigned char v1, short v2, unsigned long v3);
void L1TRC_Send_RTB_Trace_16(unsigned char v1, short v2, short v3, short v4, short v5, unsigned char v6);
void L1TRC_Send_RTB_Trace_17(unsigned char v1, short v2, short v3, long v4, unsigned long v5);
void L1TRC_Send_RTB_Trace_18(long v1);
void L1TRC_Send_RTB_Trace_19(unsigned char v1, unsigned char v2, long v3);
void L1TRC_Send_RTB_Trace_20(long v1);
void L1TRC_Send_RTB_Trace_21(unsigned char v1, char v2);
void L1TRC_Send_RTB_Trace_22(unsigned short v1);
void L1TRC_Send_RTB_Trace_23(unsigned char v1, unsigned char v2, short v3, short v4);
void L1TRC_Send_RTB_Trace_24(unsigned char v1, unsigned char v2);
void L1TRC_Send_RTB_Trace_25(unsigned char v1, short v2);
void L1TRC_Send_RTB_Trace_26(unsigned char v1, unsigned char v2, unsigned long v3, unsigned long v4);

void Set_L1C_GPRS2_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1C_GPRS2()	(L1C_GPRS2_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1C_GPRS2_RTB_M()	(ChkL1ModFltr_L1C_GPRS2()&&((L1C_GPRS2_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1C_GPRS2_RTB_L()	(ChkL1ModFltr_L1C_GPRS2()&&((L1C_GPRS2_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_RTB_Trace_1()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_2()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_3()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_4()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_5()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_6()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_7()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_8()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_9()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_10()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_11()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_12()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_13()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_14()	ChkL1ClsFltr_L1C_GPRS2_RTB_L()
#define ChkL1MsgFltr_RTB_Trace_15()	ChkL1ClsFltr_L1C_GPRS2_RTB_L()
#define ChkL1MsgFltr_RTB_Trace_16()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_17()	ChkL1ClsFltr_L1C_GPRS2_RTB_L()
#define ChkL1MsgFltr_RTB_Trace_18()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_19()	ChkL1ClsFltr_L1C_GPRS2_RTB_L()
#define ChkL1MsgFltr_RTB_Trace_20()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_21()	ChkL1ClsFltr_L1C_GPRS2_RTB_L()
#define ChkL1MsgFltr_RTB_Trace_22()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_23()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_24()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_25()	ChkL1ClsFltr_L1C_GPRS2_RTB_M()
#define ChkL1MsgFltr_RTB_Trace_26()	ChkL1ClsFltr_L1C_GPRS2_RTB_L()


#endif
