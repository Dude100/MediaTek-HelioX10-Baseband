#ifndef L1TRC_AST_L1_Trace_ISR_Context_Group2_DEF_H
#define L1TRC_AST_L1_Trace_ISR_Context_Group2_DEF_H

/******************************/
/* String category definition */
/******************************/
#define Str_Bool(v1)  (unsigned char)(v1+0)
#define Str_L1c_UeState(v1)  (unsigned char)(v1+2)
#define Str_Tl1_M_L_Func(v1)  (unsigned char)(v1+10)
#define Str_L1c_Rtb_Channel(v1)  (unsigned char)(v1+44)
#define Str_L1c_Rtb_ConflictType(v1)  (unsigned char)(v1+55)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE0(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x003C, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE0(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE0_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x003C, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE1(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x013C, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE1(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x013C, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE2(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x023C, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE2(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE2_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x023C, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE3(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x033C, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE3(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE3_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x033C, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE4(v1, v2, v3, v4, v5, v6) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x043C, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE4(v1, v2, v3, v4, v5, v6)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TEST_TRACE4_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x043C, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE0(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x053C, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE0(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE0_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x053C, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE1(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x063C, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE1(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x063C, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE2(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x073C, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE2(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE2_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x073C, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE3(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x083C, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE3(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE3_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x083C, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE4(v1, v2, v3, v4, v5, v6) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x093C, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE4(v1, v2, v3, v4, v5, v6)
#endif
#define AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE4_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x093C, (unsigned short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_2S((unsigned short)(v5), (unsigned short)(v6)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_FS_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_FS_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_FS_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_CS_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0B3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_CS_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_CS_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0B3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RX_BCH_CMD(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RX_BCH_CMD(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RX_BCH_CMD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RX_PCH_CMD(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RX_PCH_CMD(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RX_PCH_CMD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RX_FACH_CMD(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RX_FACH_CMD(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RX_FACH_CMD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RX_DCH_CMD(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RX_DCH_CMD(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RX_DCH_CMD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0F3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TX_CMD(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x103C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TX_CMD(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TX_CMD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x103C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RA_CMD(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x113C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RA_CMD(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RA_CMD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x113C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_PICH_CMD(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x123C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_PICH_CMD(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_PICH_CMD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x123C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TX_DATA_CMD(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x133C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TX_DATA_CMD(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TX_DATA_CMD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x133C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SERVING_RSCP_MEAS_CMD(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x143C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SERVING_RSCP_MEAS_CMD(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SERVING_RSCP_MEAS_CMD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x143C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_INTRA_RSCP_MEAS_CMD(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x153C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_1S2C((short)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_INTRA_RSCP_MEAS_CMD(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define AST_L1_Trace_ISR_Context_Group2_INTRA_RSCP_MEAS_CMD_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_7_DATA(TRC_MERGE_2S(0x153C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_1S2C((short)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_INTER_RSCP_MEAS_CMD(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x163C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_1S2C((short)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_INTER_RSCP_MEAS_CMD(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define AST_L1_Trace_ISR_Context_Group2_INTER_RSCP_MEAS_CMD_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_7_DATA(TRC_MERGE_2S(0x163C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_1S2C((short)(v12), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_DRX_ANT_S_CMD(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x173C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_DRX_ANT_S_CMD(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_DRX_ANT_S_CMD_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x173C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_ANT_S_CMD(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x183C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_ANT_S_CMD(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_ANT_S_CMD_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x183C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TAS_SWITCH_PHYSICAL_ANT_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x193C, (short)(v1)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v2), (unsigned char)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TAS_SWITCH_PHYSICAL_ANT_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TAS_SWITCH_PHYSICAL_ANT_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x193C, (short)(v1)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v2), (unsigned char)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SCS_RSCP_MEAS_CMD(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A3C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SCS_RSCP_MEAS_CMD(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SCS_RSCP_MEAS_CMD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A3C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_PCH_CS_RSCP_MEAS_CMD(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_PCH_CS_RSCP_MEAS_CMD(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_PCH_CS_RSCP_MEAS_CMD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_HSDPA_CMD(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C3C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_HSDPA_CMD(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_HSDPA_CMD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C3C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_STOP_HSDPA_CMD(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D3C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_STOP_HSDPA_CMD(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_STOP_HSDPA_CMD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D3C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RA_PC_TA_CMD(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E3C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RA_PC_TA_CMD(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RA_PC_TA_CMD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E3C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_BEGIN_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_BEGIN_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_BEGIN_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_END_CMD(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x203C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_END_CMD(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_END_CMD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x203C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESEL_TTU_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x213C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESEL_TTU_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESEL_TTU_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x213C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RECONFIG_TTU_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x223C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RECONFIG_TTU_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RECONFIG_TTU_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x223C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_HHO_TTU_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x233C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_HHO_TTU_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_HHO_TTU_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x233C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_BHO_UL_TTU_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x243C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_BHO_UL_TTU_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_BHO_UL_TTU_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x243C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_BHO_DL_TTU_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x253C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_BHO_DL_TTU_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_BHO_DL_TTU_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x253C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_REVERT_TTU_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x263C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_REVERT_TTU_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_REVERT_TTU_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x263C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_ISCP_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x273C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_ISCP_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_ISCP_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x273C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_UARFCN_SET_CMD(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x283C, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_UARFCN_SET_CMD(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_UARFCN_SET_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x283C, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_ENDIAN_PADDING_CMD(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x293C, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_ENDIAN_PADDING_CMD(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_ENDIAN_PADDING_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x293C, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_MCU_TRACE_CMD(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2A3C, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_MCU_TRACE_CMD(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_MCU_TRACE_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2A3C, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESET_CMD(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2B3C, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESET_CMD(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESET_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2B3C, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_DRX_TASK_CMD(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_DRX_TASK_CMD(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_DRX_TASK_CMD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2C3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_HSUPA_CMD(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2D3C, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_HSUPA_CMD(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_HSUPA_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2D3C, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_EDCH_DATA_CMD(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2E3C, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_EDCH_DATA_CMD(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_EDCH_DATA_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2E3C, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SUSPEND_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SUSPEND_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SUSPEND_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2F3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TIM_BASE_ADJ_CMD(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x303C, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TIM_BASE_ADJ_CMD(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TIM_BASE_ADJ_CMD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x303C, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_S1S2_CMD(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x313C, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_S1S2_CMD(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_S1S2_CMD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x313C, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_5MS_RSCP_MEAS_CMD(v1, v2, v3, v4, v5, v6) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x323C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_5MS_RSCP_MEAS_CMD(v1, v2, v3, v4, v5, v6)
#endif
#define AST_L1_Trace_ISR_Context_Group2_5MS_RSCP_MEAS_CMD_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x323C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SCELL_SWITCH_CMD(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x333C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SCELL_SWITCH_CMD(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SCELL_SWITCH_CMD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x333C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SLEEP_CMD(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x343C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SLEEP_CMD(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SLEEP_CMD_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x343C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_GAUGING_CMD(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x353C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_GAUGING_CMD(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_GAUGING_CMD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x353C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_INJECT_MSG_CMD(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x363C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_INJECT_MSG_CMD(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_INJECT_MSG_CMD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x363C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_DMO_CMD(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x373C, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_DMO_CMD(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_DMO_CMD_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x373C, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_CMD(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x383C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_CMD(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_CMD_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x383C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TRIGGER_BY_4G_PLMN_LOSS(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x393C, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TRIGGER_BY_4G_PLMN_LOSS(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TRIGGER_BY_4G_PLMN_LOSS_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x393C, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TRIGGER_BY_4G_PLMN_LOSS_CS_END(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3A3C, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TRIGGER_BY_4G_PLMN_LOSS_CS_END(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TRIGGER_BY_4G_PLMN_LOSS_CS_END_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3A3C, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_FS_RSP(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3B3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_FS_RSP(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_FS_RSP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3B3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_FS_RSSI(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3C3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_FS_RSSI(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_FS_RSSI_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3C3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_CS_RSP(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x3D3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_CS_RSP(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define AST_L1_Trace_ISR_Context_Group2_CS_RSP_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x3D3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_FS_CS_INFO(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3E3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_FS_CS_INFO(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group2_FS_CS_INFO_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3E3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_FREQ_FEATURE_CHECK_DURATION(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x3F3C, (short)(v1)), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_FREQ_FEATURE_CHECK_DURATION(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_FREQ_FEATURE_CHECK_DURATION_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x3F3C, (short)(v1)), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_FSCS_INFO(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x403C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_FSCS_INFO(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_FSCS_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x403C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_FS_FEATURE_REQ_WINDOW_INFO(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x413C, (short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_FS_FEATURE_REQ_WINDOW_INFO(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_FS_FEATURE_REQ_WINDOW_INFO_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x413C, (short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RX_RSP(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x423C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RX_RSP(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RX_RSP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x423C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RA_RSP(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x433C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RA_RSP(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RA_RSP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x433C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_1(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x443C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_1(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x443C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_2(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x453C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_2(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_2_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x453C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_3(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x463C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_3(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_3_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x463C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_4(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x473C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_4(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_4_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_6_DATA(TRC_MERGE_2S(0x473C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_5(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x483C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_5(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_5_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13) TRC_SEND_7_DATA(TRC_MERGE_2S(0x483C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_6(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x493C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_6(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_6_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) TRC_SEND_8_DATA(TRC_MERGE_2S(0x493C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_7(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_9_DATA(TRC_MERGE_2S(0x4A3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_7(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_7_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17) TRC_SEND_9_DATA(TRC_MERGE_2S(0x4A3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_8(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_10_DATA(TRC_MERGE_2S(0x4B3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_2S((short)(v18), (short)(v19)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_8(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_8_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19) TRC_SEND_10_DATA(TRC_MERGE_2S(0x4B3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_2S((short)(v12), (short)(v13)), TRC_MERGE_2S((short)(v14), (short)(v15)), TRC_MERGE_2S((short)(v16), (short)(v17)), TRC_MERGE_2S((short)(v18), (short)(v19)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_PICH_RSP(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4C3C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_PICH_RSP(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_PICH_RSP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4C3C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SIR_RSP(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4D3C, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SIR_RSP(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SIR_RSP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4D3C, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SPEECH_INFO_RSP(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x4E3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SPEECH_INFO_RSP(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SPEECH_INFO_RSP_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x4E3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_ISCP_RSP(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x4F3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_ISCP_RSP(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_ISCP_RSP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x4F3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESET_RSP(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x503C, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESET_RSP(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESET_RSP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x503C, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_ERROR_RSP(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x513C, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_ERROR_RSP(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_ERROR_RSP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x513C, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RSP(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x523C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RSP(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RSP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x523C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_EDCH_RSP(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x533C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_1S2C((short)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_EDCH_RSP(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif
#define AST_L1_Trace_ISR_Context_Group2_EDCH_RSP_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) TRC_SEND_6_DATA(TRC_MERGE_2S(0x533C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_1S2C((short)(v10), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_DRX_RSP(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x543C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_DRX_RSP(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_DRX_RSP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x543C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SYNC_RSP(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x553C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SYNC_RSP(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SYNC_RSP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x553C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TIM_UPDATE_RSP(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x563C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TIM_UPDATE_RSP(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TIM_UPDATE_RSP_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x563C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TRACE_INFO_RSP(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x573C, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_1S2C((short)(v12), (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v6));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TRACE_INFO_RSP(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TRACE_INFO_RSP_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) TRC_SEND_7_DATA(TRC_MERGE_2S(0x573C, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v7)), TRC_MERGE_2S((short)(v8), (short)(v9)), TRC_MERGE_2S((short)(v10), (short)(v11)), TRC_MERGE_1S2C((short)(v12), (unsigned char)(v2), TRC_BOXSTER_PAD), (long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TRACE_DRX_RSP(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x583C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TRACE_DRX_RSP(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TRACE_DRX_RSP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x583C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TIM_ADJ_RSP(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x593C, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TIM_ADJ_RSP(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TIM_ADJ_RSP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x593C, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_RSP(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5A3C, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_RSP(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_RSP_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5A3C, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_FS_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5B3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_FS_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_FS_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5B3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_CS_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5C3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_CS_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_CS_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5C3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RX_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5D3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RX_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RX_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5D3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RA_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5E3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RA_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RA_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5E3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_RSCP_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5F3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_RSCP_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_RSCP_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x5F3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_PICH_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x603C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_PICH_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_PICH_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x603C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_SIR_PWR_TA_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x613C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_SIR_PWR_TA_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_SIR_PWR_TA_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x613C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_ISCP_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x623C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_ISCP_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_ISCP_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x623C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RESET_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x633C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RESET_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RESET_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x633C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_ERROR_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x643C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_ERROR_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_ERROR_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x643C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RF_CAL_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x653C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RF_CAL_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RF_CAL_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x653C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_EAGCH_EHICH() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x663C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_EAGCH_EHICH()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_EAGCH_EHICH_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x663C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_DRX_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x673C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_DRX_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_DRX_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x673C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_SYNC_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x683C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_SYNC_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_SYNC_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x683C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIM_UPD_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x693C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIM_UPD_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIM_UPD_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x693C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_INFO_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6A3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_INFO_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_INFO_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6A3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_DRX_INFO_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6B3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_DRX_INFO_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_DRX_INFO_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6B3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_BASE_ADJ_RESP_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6C3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_BASE_ADJ_RESP_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_BASE_ADJ_RESP_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6C3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_SYNC_FAIL_RESP_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6D3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_SYNC_FAIL_RESP_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_SYNC_FAIL_RESP_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6D3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TEST_CMD_RESULT_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6E3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TEST_CMD_RESULT_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TEST_CMD_RESULT_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6E3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_REPORT_UART_TRACE_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6F3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_REPORT_UART_TRACE_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_REPORT_UART_TRACE_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x6F3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_OTCAL() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x703C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_OTCAL()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_OTCAL_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x703C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_FS() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x713C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_FS()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_FS_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x713C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_CS() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x723C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_CS()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_CS_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x723C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RX() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x733C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RX()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RX_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x733C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RA() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x743C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RA()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RA_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x743C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_RSCP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x753C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_RSCP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_RSCP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x753C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_PICH() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x763C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_PICH()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_PICH_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x763C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_SIR_PWR_TA() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x773C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_SIR_PWR_TA()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_SIR_PWR_TA_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x773C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_ISCP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x783C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_ISCP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_ISCP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x783C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RESET() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x793C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RESET()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RESET_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x793C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_ERROR() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7A3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_ERROR()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_ERROR_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7A3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RF_CAL() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7B3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RF_CAL()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_RF_CAL_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7B3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_EAGCH_EHICH_SKIP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7C3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_EAGCH_EHICH_SKIP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_EAGCH_EHICH_SKIP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7C3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_DRX() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7D3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_DRX()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_DRX_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7D3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_SYNC() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7E3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_SYNC()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_SYNC_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7E3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIM_UPD() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7F3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIM_UPD()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIM_UPD_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x7F3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_INFO() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x803C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_INFO()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_INFO_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x803C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_DRX_INFO() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x813C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_DRX_INFO()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_DRX_INFO_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x813C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_BASE_ADJ_RESP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x823C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_BASE_ADJ_RESP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_BASE_ADJ_RESP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x823C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_SYNC_FAIL_RESP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x833C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_SYNC_FAIL_RESP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_SYNC_FAIL_RESP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x833C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TEST_CMD_RESULT() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x843C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TEST_CMD_RESULT()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_TEST_CMD_RESULT_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x843C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_REPORT_UART_TRACE() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x853C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_REPORT_UART_TRACE()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RESPONSE_REPORT_UART_TRACE_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x853C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_CS() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x863C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_CS()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_CS_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x863C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RX() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x873C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RX()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RX_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x873C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_MEAS_RSCP() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x883C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_MEAS_RSCP()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_MEAS_RSCP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x883C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_SIR_PWR_TA() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x893C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_SIR_PWR_TA()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_SIR_PWR_TA_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x893C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RESET() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8A3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RESET()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RESET_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8A3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_EAGCH_EHICH() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8B3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_EAGCH_EHICH()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_EAGCH_EHICH_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8B3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_TIM_UPD() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8C3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_TIM_UPD()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_TIM_UPD_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8C3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_ABBREG() do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8D3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_ABBREG()
#endif
#define AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_ABBREG_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x8D3C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_DPA_ONLY_RSP(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8E3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_DPA_ONLY_RSP(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_DPA_ONLY_RSP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8E3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_DPA_BOTH_RSP(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x8F3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_DPA_BOTH_RSP(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_DPA_BOTH_RSP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x8F3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_UPA_ONLY_RSP(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x903C, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_UPA_ONLY_RSP(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_UPA_ONLY_RSP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x903C, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_UPA_BOTH_RSP(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x913C, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_UPA_BOTH_RSP(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_UPA_BOTH_RSP_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x913C, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SERVING_CELL_RSCP_FILTERED(v1, v2, v3) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x923C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SERVING_CELL_RSCP_FILTERED(v1, v2, v3)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SERVING_CELL_RSCP_FILTERED_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x923C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_SIR_WARNING(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x933C, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_SIR_WARNING(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_SIR_WARNING_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x933C, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TX_POWER_WARNING(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x943C, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TX_POWER_WARNING(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TX_POWER_WARNING_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x943C, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TA_WARNING(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x953C, (short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TA_WARNING(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TA_WARNING_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x953C, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_TX_IS_SRB(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x963C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_TX_IS_SRB(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_TX_IS_SRB_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x963C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_RX_IS_SRB(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x973C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_RX_IS_SRB(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_RX_IS_SRB_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x973C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_IN_OUT_SYNC(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x983C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_IN_OUT_SYNC(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group2_IN_OUT_SYNC_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x983C, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x993C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x993C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch_Bch(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x9A3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch_Bch(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch_Bch_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x9A3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Fach(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x9B3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Fach(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Fach_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x9B3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Dch(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x9C3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Dch(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Dch_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x9C3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Hspa(v1, v2, v3, v4, v5, v6, v7) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x9D3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Hspa(v1, v2, v3, v4, v5, v6, v7)
#endif
#define AST_L1_Trace_ISR_Context_Group2_MM_Gap_Hspa_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x9D3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group2_HSDPA_DATA_IND(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x9E3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group2_HSDPA_DATA_IND(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group2_HSDPA_DATA_IND_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x9E3C, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_L1R_Start3GChannel(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x9F3C, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_L1R_Start3GChannel(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group1_L1R_Start3GChannel_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x9F3C, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_L1R_Stop3GChannel(v1) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xA03C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_L1R_Stop3GChannel(v1)
#endif
#define AST_L1_Trace_ISR_Context_Group1_L1R_Stop3GChannel_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0xA03C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_L1R_Change_3G_Timer_priority(v1, v2) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xA13C, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_L1R_Change_3G_Timer_priority(v1, v2)
#endif
#define AST_L1_Trace_ISR_Context_Group1_L1R_Change_3G_Timer_priority_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0xA13C, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_L1R_Check3GResource(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0xA23C, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_L1R_Check3GResource(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_ISR_Context_Group1_L1R_Check3GResource_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0xA23C, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_ISR_Context_Group1_L1R_3GPeekRTBHigherTask(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0xA33C, (short)(v2)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define AST_L1_Trace_ISR_Context_Group1_L1R_3GPeekRTBHigherTask(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_ISR_Context_Group1_L1R_3GPeekRTBHigherTask_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0xA33C, (short)(v2)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v3), (long)(v4))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char AST_L1_Trace_ISR_Context_Group2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE0(unsigned char v1, unsigned short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE1(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE2(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE3(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE4(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE0(unsigned char v1, unsigned short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE1(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE2(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE3(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE4(unsigned char v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_FS_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_CS_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RX_BCH_CMD(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RX_PCH_CMD(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RX_FACH_CMD(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RX_DCH_CMD(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TX_CMD(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RA_CMD(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_PICH_CMD(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TX_DATA_CMD(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SERVING_RSCP_MEAS_CMD(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_INTRA_RSCP_MEAS_CMD(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_INTER_RSCP_MEAS_CMD(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_DRX_ANT_S_CMD(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_ANT_S_CMD(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TAS_SWITCH_PHYSICAL_ANT_CMD(short v1, unsigned char v2, unsigned char v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SCS_RSCP_MEAS_CMD(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_PCH_CS_RSCP_MEAS_CMD(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_HSDPA_CMD(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_STOP_HSDPA_CMD(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RA_PC_TA_CMD(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_BEGIN_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_END_CMD(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESEL_TTU_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RECONFIG_TTU_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_HHO_TTU_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_BHO_UL_TTU_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_BHO_DL_TTU_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_REVERT_TTU_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_ISCP_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_UARFCN_SET_CMD(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_ENDIAN_PADDING_CMD(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_MCU_TRACE_CMD(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESET_CMD(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_DRX_TASK_CMD(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_HSUPA_CMD(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_EDCH_DATA_CMD(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SUSPEND_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TIM_BASE_ADJ_CMD(short v1, unsigned short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_S1S2_CMD(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_5MS_RSCP_MEAS_CMD(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SCELL_SWITCH_CMD(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SLEEP_CMD(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_GAUGING_CMD(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_INJECT_MSG_CMD(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_DMO_CMD(short v1, unsigned short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_CMD(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TRIGGER_BY_4G_PLMN_LOSS(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TRIGGER_BY_4G_PLMN_LOSS_CS_END(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_FS_RSP(short v1, short v2, short v3, unsigned short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_FS_RSSI(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_CS_RSP(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_FS_CS_INFO(short v1, short v2, short v3, short v4, unsigned short v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_FREQ_FEATURE_CHECK_DURATION(short v1, long v2, long v3, long v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_FSCS_INFO(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_FS_FEATURE_REQ_WINDOW_INFO(short v1, long v2, long v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RX_RSP(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RA_RSP(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_1(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_2(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_3(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_4(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_5(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_6(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_7(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_8(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10, short v11, short v12, short v13, short v14, short v15, short v16, short v17, short v18, short v19);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_PICH_RSP(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SIR_RSP(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SPEECH_INFO_RSP(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_ISCP_RSP(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESET_RSP(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_ERROR_RSP(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RFCAL_RSP(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_EDCH_RSP(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_DRX_RSP(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SYNC_RSP(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TIM_UPDATE_RSP(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TRACE_INFO_RSP(short v1, unsigned char v2, short v3, short v4, short v5, long v6, short v7, short v8, short v9, short v10, short v11, short v12);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TRACE_DRX_RSP(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TIM_ADJ_RSP(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_RSP(short v1, unsigned char v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_FS_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_CS_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RX_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RA_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_RSCP_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_PICH_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_SIR_PWR_TA_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_ISCP_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RESET_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_ERROR_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RF_CAL_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_EAGCH_EHICH(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_DRX_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_SYNC_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIM_UPD_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_INFO_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_DRX_INFO_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_BASE_ADJ_RESP_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_SYNC_FAIL_RESP_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TEST_CMD_RESULT_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_REPORT_UART_TRACE_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_OTCAL(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_FS(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_CS(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RX(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RA(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_RSCP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_PICH(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_SIR_PWR_TA(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_ISCP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RESET(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_ERROR(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RF_CAL(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_EAGCH_EHICH_SKIP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_DRX(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_SYNC(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIM_UPD(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_INFO(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_DRX_INFO(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_BASE_ADJ_RESP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_SYNC_FAIL_RESP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TEST_CMD_RESULT(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RESPONSE_REPORT_UART_TRACE(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_CS(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RX(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_MEAS_RSCP(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_SIR_PWR_TA(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RESET(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_EAGCH_EHICH(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_TIM_UPD(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_ABBREG(void);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_DPA_ONLY_RSP(short v1, short v2, unsigned short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_DPA_BOTH_RSP(short v1, short v2, unsigned short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_UPA_ONLY_RSP(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_UPA_BOTH_RSP(short v1, short v2, unsigned short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SERVING_CELL_RSCP_FILTERED(short v1, short v2, short v3);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_SIR_WARNING(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TX_POWER_WARNING(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TA_WARNING(short v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_TX_IS_SRB(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_RX_IS_SRB(short v1, short v2, short v3, short v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_IN_OUT_SYNC(short v1, short v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch(short v1, short v2, short v3, unsigned char v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch_Bch(short v1, short v2, short v3, unsigned char v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Fach(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Dch(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Hspa(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group2_HSDPA_DATA_IND(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_L1R_Start3GChannel(unsigned char v1, short v2, long v3, long v4, long v5);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_L1R_Stop3GChannel(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_L1R_Change_3G_Timer_priority(unsigned char v1, long v2);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_L1R_Check3GResource(unsigned char v1, long v2, short v3, unsigned char v4);
void L1TRC_Send_AST_L1_Trace_ISR_Context_Group1_L1R_3GPeekRTBHigherTask(unsigned char v1, short v2, long v3, long v4, short v5);

void Set_AST_L1_Trace_ISR_Context_Group2_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group2()	(AST_L1_Trace_ISR_Context_Group2_Trace_Filter[0]==1)
#define ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()	(ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group2()&&((AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()	(ChkL1ModFltr_AST_L1_Trace_ISR_Context_Group2()&&((AST_L1_Trace_ISR_Context_Group2_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE0()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE1()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE2()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE3()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TEST_TRACE4()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE0()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE1()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE2()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE3()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_VIRTUAL_MODE_TRACE4()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_FS_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_CS_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RX_BCH_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RX_PCH_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RX_FACH_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RX_DCH_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TX_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RA_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_PICH_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TX_DATA_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SERVING_RSCP_MEAS_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_INTRA_RSCP_MEAS_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_INTER_RSCP_MEAS_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_DRX_ANT_S_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TAS_MEAS_ANT_S_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TAS_SWITCH_PHYSICAL_ANT_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SCS_RSCP_MEAS_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_PCH_CS_RSCP_MEAS_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_HSDPA_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_STOP_HSDPA_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RA_PC_TA_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_BEGIN_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_NBCH_TTU_END_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESEL_TTU_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RECONFIG_TTU_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_HHO_TTU_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_BHO_UL_TTU_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_BHO_DL_TTU_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_REVERT_TTU_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_ISCP_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_UARFCN_SET_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_ENDIAN_PADDING_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_MCU_TRACE_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESET_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_DRX_TASK_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_HSUPA_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_EDCH_DATA_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SUSPEND_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TIM_BASE_ADJ_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_S1S2_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_5MS_RSCP_MEAS_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SCELL_SWITCH_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SLEEP_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_GAUGING_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_INJECT_MSG_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_DMO_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_CMD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TRIGGER_BY_4G_PLMN_LOSS()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TRIGGER_BY_4G_PLMN_LOSS_CS_END()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_FS_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_FS_RSSI()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_CS_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_FS_CS_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_FREQ_FEATURE_CHECK_DURATION()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_FSCS_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_FS_FEATURE_REQ_WINDOW_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RX_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RA_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_1()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_2()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_3()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_4()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_5()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_6()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_7()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RSCP_MEAS_8()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_PICH_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SIR_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SPEECH_INFO_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_ISCP_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESET_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_ERROR_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RFCAL_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_EDCH_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_DRX_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SYNC_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TIM_UPDATE_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TRACE_INFO_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TRACE_DRX_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TIM_ADJ_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_LPM_DIV_UPDATE_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_FS_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_CS_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RX_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RA_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_RSCP_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_PICH_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_SIR_PWR_TA_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_ISCP_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RESET_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_ERROR_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RF_CAL_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_EAGCH_EHICH()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_DRX_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_SYNC_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIM_UPD_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_INFO_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_DRX_INFO_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_BASE_ADJ_RESP_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_SYNC_FAIL_RESP_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TEST_CMD_RESULT_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_REPORT_UART_TRACE_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_OTCAL()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_FS()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_CS()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RX()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RA()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_RSCP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_PICH()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_SIR_PWR_TA()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_MEAS_ISCP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RESET()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_ERROR()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_RF_CAL()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_EAGCH_EHICH_SKIP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_DRX()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_SYNC()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIM_UPD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TRACE_DRX_INFO()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_BASE_ADJ_RESP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TIMING_SYNC_FAIL_RESP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_TEST_CMD_RESULT()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RESPONSE_REPORT_UART_TRACE()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_CS()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RX()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_MEAS_RSCP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_SIR_PWR_TA()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_RESET()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_EAGCH_EHICH()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_TIM_UPD()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RFCAL_RESPONSE_ABBREG()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_DPA_ONLY_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_DPA_BOTH_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_UPA_ONLY_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_UPA_BOTH_RSP()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SERVING_CELL_RSCP_FILTERED()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_SIR_WARNING()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TX_POWER_WARNING()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TA_WARNING()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_TX_IS_SRB()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_RX_IS_SRB()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_IN_OUT_SYNC()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Pch_Bch()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Fach()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Dch()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_MM_Gap_Hspa()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group2_HSDPA_DATA_IND()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_L1R_Start3GChannel()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_L1R_Stop3GChannel()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_L1R_Change_3G_Timer_priority()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_L1R_Check3GResource()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_ISR_Context_Group1_L1R_3GPeekRTBHigherTask()	ChkL1ClsFltr_AST_L1_Trace_ISR_Context_Group2_TEST_CLASS_1()


#endif
