#ifndef L1TRC_UL1C_PRI4_DEF_H
#define L1TRC_UL1C_PRI4_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define UL1T_TRC_EDCH_Config(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x003B, (unsigned short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_EDCH_Config(v1, v2, v3)
#endif
#define UL1T_TRC_EDCH_Config_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x003B, (unsigned short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_EDCH_Setup(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x013B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), (char)(v4)));\
	} while(0)
#else
	#define UL1T_TRC_EDCH_Setup(v1, v2, v3, v4)
#endif
#define UL1T_TRC_EDCH_Setup_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x013B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_EDCH_Modify(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x023B, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v5)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_EDCH_Modify(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_EDCH_Modify_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x023B, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v5)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_EDCH_Release(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x033B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), (char)(v4)));\
	} while(0)
#else
	#define UL1T_TRC_EDCH_Release(v1, v2, v3, v4)
#endif
#define UL1T_TRC_EDCH_Release_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x033B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), (char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_EAGCH_Calculate_Param(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x043B, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_EAGCH_Calculate_Param(v1, v2, v3, v4)
#endif
#define UL1T_TRC_EAGCH_Calculate_Param_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x043B, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_EHICH_Calculate_Param(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x053B, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_EHICH_Calculate_Param(v1, v2, v3)
#endif
#define UL1T_TRC_EHICH_Calculate_Param_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x053B, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Calculate_Result(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x063B, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Calculate_Result(v1, v2, v3)
#endif
#define UL1T_TRC_Calculate_Result_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x063B, (short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_ERGCH_Calculate_Param(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x073B, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ERGCH_Calculate_Param(v1, v2, v3)
#endif
#define UL1T_TRC_ERGCH_Calculate_Param_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x073B, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Compare_EAGCH_Param(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x083B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Compare_EAGCH_Param(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1T_TRC_Compare_EAGCH_Param_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_5_DATA(TRC_MERGE_2S(0x083B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_1S2C((short)(v8), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Compare_EHICH_Param(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x093B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Compare_EHICH_Param(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_Compare_EHICH_Param_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x093B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Compare_Param_old(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0A3B, (short)(v1)));\
	} while(0)
#else
	#define UL1T_TRC_Compare_Param_old(v1)
#endif
#define UL1T_TRC_Compare_Param_old_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0A3B, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Compare_Param_new(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0B3B, (short)(v1)));\
	} while(0)
#else
	#define UL1T_TRC_Compare_Param_new(v1)
#endif
#define UL1T_TRC_Compare_Param_new_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0B3B, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Compare_Result(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C3B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Compare_Result(v1, v2)
#endif
#define UL1T_TRC_Compare_Result_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C3B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Compare_Result2(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0D3B, (short)(v1)));\
	} while(0)
#else
	#define UL1T_TRC_Compare_Result2(v1)
#endif
#define UL1T_TRC_Compare_Result2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0D3B, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Compare_Result3(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0E3B, (short)(v1)));\
	} while(0)
#else
	#define UL1T_TRC_Compare_Result3(v1)
#endif
#define UL1T_TRC_Compare_Result3_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0E3B, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Compare_ERGCH_Param(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0F3B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Compare_ERGCH_Param(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_Compare_ERGCH_Param_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0F3B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_Compare_ERGCH_Result(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x103B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Compare_ERGCH_Result(v1, v2)
#endif
#define UL1T_TRC_Compare_ERGCH_Result_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x103B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_EDCH_Remove(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x113B, (short)(v1)));\
	} while(0)
#else
	#define UL1T_TRC_EDCH_Remove(v1)
#endif
#define UL1T_TRC_EDCH_Remove_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x113B, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_EDCH_Start_Timer(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x123B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_EDCH_Start_Timer(v1, v2)
#endif
#define UL1I_TRC_EDCH_Start_Timer_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x123B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_Start_EDCH(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x133B, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_Start_EDCH(v1, v2)
#endif
#define UL1I_TRC_Start_EDCH_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x133B, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_Internal_Start_EDCH() do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x143B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Internal_Start_EDCH()
#endif
#define UL1I_TRC_Internal_Start_EDCH_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x143B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_Stop_EDCH(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x153B, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_Stop_EDCH(v1, v2)
#endif
#define UL1I_TRC_Stop_EDCH_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x153B, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_ERNTI_Config(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x163B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_ERNTI_Config(v1, v2, v3, v4)
#endif
#define UL1I_TRC_ERNTI_Config_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x163B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_EDCH_TTI_Config(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x173B, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_EDCH_TTI_Config(v1)
#endif
#define UL1I_TRC_EDCH_TTI_Config_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x173B, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_EDPCCH_Config(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x183B, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_EDPCCH_Config(v1)
#endif
#define UL1I_TRC_EDPCCH_Config_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x183B, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_EDPDCH_Config(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x193B, (short)(v2)), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1I_TRC_EDPDCH_Config(v1, v2)
#endif
#define UL1I_TRC_EDPDCH_Config_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x193B, (short)(v2)), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define UL1I_TRC_EDPDCH_Config2(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A3B, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_EDPDCH_Config2(v1, v2, v3)
#endif
#define UL1I_TRC_EDPDCH_Config2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A3B, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_EDCH_Serv_Cell_Config(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1B3B, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_EDCH_Serv_Cell_Config(v1)
#endif
#define UL1I_TRC_EDCH_Serv_Cell_Config_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1B3B, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_EDCH_Channel_Config(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C3B, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_EDCH_Channel_Config(v1, v2, v3)
#endif
#define UL1I_TRC_EDCH_Channel_Config_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C3B, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_EDCH_HARQ_Config(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D3B, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_EDCH_HARQ_Config(v1)
#endif
#define UL1I_TRC_EDCH_HARQ_Config_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D3B, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_UL1D_EDCH_Start(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1E3B, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_UL1D_EDCH_Start(v1)
#endif
#define UL1I_TRC_UL1D_EDCH_Start_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1E3B, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_UL1D_EHICH_Remove(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F3B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1I_TRC_UL1D_EHICH_Remove(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_UL1D_EHICH_Remove_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1F3B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_UL1D_ERGCH_Remove(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x203B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1I_TRC_UL1D_ERGCH_Remove(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_UL1D_ERGCH_Remove_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x203B, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_New_UL1_EHICH_Info(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x213B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_New_UL1_EHICH_Info(v1, v2)
#endif
#define UL1I_TRC_New_UL1_EHICH_Info_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x213B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_Delete_UL1_EHICH_Info(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x223B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Delete_UL1_EHICH_Info(v1, v2)
#endif
#define UL1I_TRC_Delete_UL1_EHICH_Info_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x223B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_New_UL1_ERGCH_Info(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x233B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_New_UL1_ERGCH_Info(v1, v2)
#endif
#define UL1I_TRC_New_UL1_ERGCH_Info_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x233B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_Delete_UL1_ERGCH_Info(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x243B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Delete_UL1_ERGCH_Info(v1, v2)
#endif
#define UL1I_TRC_Delete_UL1_ERGCH_Info_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x243B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_EDPDCH_Calculate_Param(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x253B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1T_TRC_EDPDCH_Calculate_Param(v1, v2)
#endif
#define UL1T_TRC_EDPDCH_Calculate_Param_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x253B, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1T_TRC_EDPDCH_Get_Buffer(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x263B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1T_TRC_EDPDCH_Get_Buffer(v1)
#endif
#define UL1T_TRC_EDPDCH_Get_Buffer_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x263B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define UL1T_TRC_HSDSCH_EDCH_Action(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x273B, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v8), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v6), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_HSDSCH_EDCH_Action(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1T_TRC_HSDSCH_EDCH_Action_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_4_DATA(TRC_MERGE_2S(0x273B, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v5)), TRC_MERGE_1S2C((unsigned short)(v8), (char)(v3), (char)(v4)), TRC_MERGE_4C((char)(v6), (char)(v7), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UL1D_EDCH_Set_MAC_Event(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x283B, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_UL1D_EDCH_Set_MAC_Event(v1)
#endif
#define UL1I_TRC_UL1D_EDCH_Set_MAC_Event_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x283B, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_EDCH_UL1D_Intf(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x293B, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_EDCH_UL1D_Intf(v1)
#endif
#define UL1I_TRC_EDCH_UL1D_Intf_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x293B, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_HSDSCH_Config(v1, v2, v3) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2A3B, (unsigned short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_HSDSCH_Config(v1, v2, v3)
#endif
#define UL1T_TRC_HSDSCH_Config_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2A3B, (unsigned short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_HSDSCH_Setup(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B3B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), (char)(v4)));\
	} while(0)
#else
	#define UL1T_TRC_HSDSCH_Setup(v1, v2, v3, v4)
#endif
#define UL1T_TRC_HSDSCH_Setup_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B3B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_HSDSCH_Modify(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C3B, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v5)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_HSDSCH_Modify(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_HSDSCH_Modify_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2C3B, (short)(v1)), TRC_MERGE_2S((short)(v2), (unsigned short)(v5)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_HSDSCH_Release(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D3B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), (char)(v4)));\
	} while(0)
#else
	#define UL1T_TRC_HSDSCH_Release(v1, v2, v3, v4)
#endif
#define UL1T_TRC_HSDSCH_Release_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2D3B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_HSDSCH_Suspend(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2E3B, (short)(v1)));\
	} while(0)
#else
	#define UL1T_TRC_HSDSCH_Suspend(v1)
#endif
#define UL1T_TRC_HSDSCH_Suspend_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2E3B, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HSDSCH_Start_Timer(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F3B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_HSDSCH_Start_Timer(v1, v2)
#endif
#define UL1I_TRC_HSDSCH_Start_Timer_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2F3B, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Start_HSDSCH(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x303B, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_Start_HSDSCH(v1, v2)
#endif
#define UL1I_TRC_Start_HSDSCH_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x303B, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Internal_Start_HSDSCH() do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x313B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Internal_Start_HSDSCH()
#endif
#define UL1I_TRC_Internal_Start_HSDSCH_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x313B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Stop_HSDSCH(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x323B, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_Stop_HSDSCH(v1, v2)
#endif
#define UL1I_TRC_Stop_HSDSCH_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x323B, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UL1D_HS_Serv_RL_Config(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x333B, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_UL1D_HS_Serv_RL_Config(v1)
#endif
#define UL1I_TRC_UL1D_HS_Serv_RL_Config_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x333B, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HSDSCH_Meas_Po(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x343B, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_HSDSCH_Meas_Po(v1)
#endif
#define UL1I_TRC_HSDSCH_Meas_Po_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x343B, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UL1D_HS_State_Info(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x353B, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_UL1D_HS_State_Info(v1, v2)
#endif
#define UL1I_TRC_UL1D_HS_State_Info_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x353B, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UL1D_HS_DSCH_Start(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x363B, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_UL1D_HS_DSCH_Start(v1)
#endif
#define UL1I_TRC_UL1D_HS_DSCH_Start_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x363B, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UL1D_HS_Set_MAC_Event(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x373B, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_UL1D_HS_Set_MAC_Event(v1)
#endif
#define UL1I_TRC_UL1D_HS_Set_MAC_Event_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x373B, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HSDSCH_UL1D_Intf(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x383B, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_HSDSCH_UL1D_Intf(v1)
#endif
#define UL1I_TRC_HSDSCH_UL1D_Intf_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x383B, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Update_Strongest_Cells(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x393B, (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), (char)(v4)));\
	} while(0)
#else
	#define UL1I_TRC_Update_Strongest_Cells(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1I_TRC_Update_Strongest_Cells_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x393B, (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Update_Strongest_Cells_RXD(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3A3B, (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), (char)(v4)));\
	} while(0)
#else
	#define UL1I_TRC_Update_Strongest_Cells_RXD(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1I_TRC_Update_Strongest_Cells_RXD_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3A3B, (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_Update_Strongest_Cells(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3B3B, (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Update_Strongest_Cells(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_Update_Strongest_Cells_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3B3B, (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_Update_Strongest_Cells_RXD(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3C3B, (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Update_Strongest_Cells_RXD(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_Update_Strongest_Cells_RXD_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3C3B, (short)(v4)), TRC_MERGE_2S((short)(v5), (short)(v6)), TRC_MERGE_4C((char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_Update_Serving_Cell(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3D3B, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Update_Serving_Cell(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_Update_Serving_Cell_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3D3B, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_Update_Serving_Cell_RXD(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3E3B, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Update_Serving_Cell_RXD(v1, v2, v3, v4, v5)
#endif
#define UL1T_TRC_Update_Serving_Cell_RXD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3E3B, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_Send_DC_Report(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3F3B, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_Send_DC_Report(v1, v2)
#endif
#define UL1T_TRC_Send_DC_Report_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3F3B, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_HS_Reset_HSCE_DB(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x403B, (short)(v1)));\
	} while(0)
#else
	#define UL1T_TRC_HS_Reset_HSCE_DB(v1)
#endif
#define UL1T_TRC_HS_Reset_HSCE_DB_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x403B, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Sec_HSDSCH_64QAM(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x413B, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_Sec_HSDSCH_64QAM(v1)
#endif
#define UL1I_TRC_Sec_HSDSCH_64QAM_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x413B, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Sec_HSDSCH_Meas_Po(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x423B, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_Sec_HSDSCH_Meas_Po(v1)
#endif
#define UL1I_TRC_Sec_HSDSCH_Meas_Po_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x423B, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Sec_HSDSCH_MAC_Type(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x433B, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Sec_HSDSCH_MAC_Type(v1)
#endif
#define UL1I_TRC_Sec_HSDSCH_MAC_Type_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x433B, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_Wakeup(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x443B, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_Wakeup(v1)
#endif
#define UL1I_TRC_Wakeup_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x443B, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CPC_Config(v1, v2, v3, v4) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x453B, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CPC_Config(v1, v2, v3, v4)
#endif
#define UL1I_TRC_CPC_Config_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x453B, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), (char)(v4), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CPC_Control(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x463B, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CPC_Control(v1)
#endif
#define UL1I_TRC_CPC_Control_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x463B, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_Monitor_Order_Status(v1, v2) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x473B, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Monitor_Order_Status(v1, v2)
#endif
#define UL1I_TRC_Monitor_Order_Status_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x473B, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_Monitor_Order_Timer(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x483B, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_Monitor_Order_Timer(v1)
#endif
#define UL1I_TRC_Monitor_Order_Timer_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x483B, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_SkipSyncA() do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x493B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_SkipSyncA()
#endif
#define UL1I_TRC_SkipSyncA_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x493B, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CEDCH_Termination(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4A3B, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CEDCH_Termination(v1)
#endif
#define UL1I_TRC_CEDCH_Termination_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4A3B, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1T_TRC_CTCH_ChannelPriority(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B3B, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_CTCH_ChannelPriority(v1)
#endif
#define UL1T_TRC_CTCH_ChannelPriority_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4B3B, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HSPASYS_Configure(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4C3B, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_HSPASYS_Configure(v1)
#endif
#define UL1I_TRC_HSPASYS_Configure_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4C3B, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HSPASYS_Status(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4D3B, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_HSPASYS_Status(v1)
#endif
#define UL1I_TRC_HSPASYS_Status_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4D3B, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HSPASYS_Delay_frame(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4E3B, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_HSPASYS_Delay_frame(v1)
#endif
#define UL1I_TRC_HSPASYS_Delay_frame_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4E3B, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HSPASYS_ON_Control(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4F3B, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_HSPASYS_ON_Control(v1)
#endif
#define UL1I_TRC_HSPASYS_ON_Control_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4F3B, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HSPASYS_OFF_Control(v1) do {\
		if(UL1C_PRI4_Trace_Filter[0]==1 && (UL1C_PRI4_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x503B, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_HSPASYS_OFF_Control(v1)
#endif
#define UL1I_TRC_HSPASYS_OFF_Control_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x503B, (short)(v1)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1C_PRI4_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1T_TRC_EDCH_Config(char v1, char v2, unsigned short v3);
void L1TRC_Send_UL1T_TRC_EDCH_Setup(short v1, short v2, char v3, char v4);
void L1TRC_Send_UL1T_TRC_EDCH_Modify(short v1, short v2, char v3, char v4, unsigned short v5);
void L1TRC_Send_UL1T_TRC_EDCH_Release(short v1, short v2, char v3, char v4);
void L1TRC_Send_UL1T_TRC_EAGCH_Calculate_Param(char v1, short v2, short v3, short v4);
void L1TRC_Send_UL1T_TRC_EHICH_Calculate_Param(char v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_Calculate_Result(short v1, char v2, short v3);
void L1TRC_Send_UL1T_TRC_ERGCH_Calculate_Param(char v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_Compare_EAGCH_Param(short v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8);
void L1TRC_Send_UL1T_TRC_Compare_EHICH_Param(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1T_TRC_Compare_Param_old(short v1);
void L1TRC_Send_UL1T_TRC_Compare_Param_new(short v1);
void L1TRC_Send_UL1T_TRC_Compare_Result(short v1, short v2);
void L1TRC_Send_UL1T_TRC_Compare_Result2(short v1);
void L1TRC_Send_UL1T_TRC_Compare_Result3(short v1);
void L1TRC_Send_UL1T_TRC_Compare_ERGCH_Param(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1T_TRC_Compare_ERGCH_Result(short v1, short v2);
void L1TRC_Send_UL1T_TRC_EDCH_Remove(short v1);
void L1TRC_Send_UL1I_TRC_EDCH_Start_Timer(short v1, short v2);
void L1TRC_Send_UL1I_TRC_Start_EDCH(char v1, char v2);
void L1TRC_Send_UL1I_TRC_Internal_Start_EDCH(void);
void L1TRC_Send_UL1I_TRC_Stop_EDCH(char v1, char v2);
void L1TRC_Send_UL1I_TRC_ERNTI_Config(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_EDCH_TTI_Config(char v1);
void L1TRC_Send_UL1I_TRC_EDPCCH_Config(short v1);
void L1TRC_Send_UL1I_TRC_EDPDCH_Config(unsigned long v1, short v2);
void L1TRC_Send_UL1I_TRC_EDPDCH_Config2(char v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_EDCH_Serv_Cell_Config(short v1);
void L1TRC_Send_UL1I_TRC_EDCH_Channel_Config(char v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_EDCH_HARQ_Config(char v1);
void L1TRC_Send_UL1I_TRC_UL1D_EDCH_Start(short v1);
void L1TRC_Send_UL1I_TRC_UL1D_EHICH_Remove(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1I_TRC_UL1D_ERGCH_Remove(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1I_TRC_New_UL1_EHICH_Info(short v1, short v2);
void L1TRC_Send_UL1I_TRC_Delete_UL1_EHICH_Info(short v1, short v2);
void L1TRC_Send_UL1I_TRC_New_UL1_ERGCH_Info(short v1, short v2);
void L1TRC_Send_UL1I_TRC_Delete_UL1_ERGCH_Info(short v1, short v2);
void L1TRC_Send_UL1T_TRC_EDPDCH_Calculate_Param(char v1, unsigned long v2);
void L1TRC_Send_UL1T_TRC_EDPDCH_Get_Buffer(unsigned long v1);
void L1TRC_Send_UL1T_TRC_HSDSCH_EDCH_Action(short v1, short v2, char v3, char v4, unsigned short v5, char v6, char v7, unsigned short v8);
void L1TRC_Send_UL1I_TRC_UL1D_EDCH_Set_MAC_Event(short v1);
void L1TRC_Send_UL1I_TRC_EDCH_UL1D_Intf(char v1);
void L1TRC_Send_UL1T_TRC_HSDSCH_Config(char v1, char v2, unsigned short v3);
void L1TRC_Send_UL1T_TRC_HSDSCH_Setup(short v1, short v2, char v3, char v4);
void L1TRC_Send_UL1T_TRC_HSDSCH_Modify(short v1, short v2, char v3, char v4, unsigned short v5);
void L1TRC_Send_UL1T_TRC_HSDSCH_Release(short v1, short v2, char v3, char v4);
void L1TRC_Send_UL1T_TRC_HSDSCH_Suspend(short v1);
void L1TRC_Send_UL1I_TRC_HSDSCH_Start_Timer(short v1, short v2);
void L1TRC_Send_UL1I_TRC_Start_HSDSCH(char v1, char v2);
void L1TRC_Send_UL1I_TRC_Internal_Start_HSDSCH(void);
void L1TRC_Send_UL1I_TRC_Stop_HSDSCH(char v1, char v2);
void L1TRC_Send_UL1I_TRC_UL1D_HS_Serv_RL_Config(short v1);
void L1TRC_Send_UL1I_TRC_HSDSCH_Meas_Po(short v1);
void L1TRC_Send_UL1I_TRC_UL1D_HS_State_Info(char v1, char v2);
void L1TRC_Send_UL1I_TRC_UL1D_HS_DSCH_Start(short v1);
void L1TRC_Send_UL1I_TRC_UL1D_HS_Set_MAC_Event(short v1);
void L1TRC_Send_UL1I_TRC_HSDSCH_UL1D_Intf(char v1);
void L1TRC_Send_UL1I_TRC_Update_Strongest_Cells(char v1, char v2, char v3, char v4, short v5, short v6, short v7);
void L1TRC_Send_UL1I_TRC_Update_Strongest_Cells_RXD(char v1, char v2, char v3, char v4, short v5, short v6, short v7);
void L1TRC_Send_UL1T_TRC_Update_Strongest_Cells(char v1, char v2, char v3, short v4, short v5, short v6);
void L1TRC_Send_UL1T_TRC_Update_Strongest_Cells_RXD(char v1, char v2, char v3, short v4, short v5, short v6);
void L1TRC_Send_UL1T_TRC_Update_Serving_Cell(char v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1T_TRC_Update_Serving_Cell_RXD(char v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1T_TRC_Send_DC_Report(short v1, char v2);
void L1TRC_Send_UL1T_TRC_HS_Reset_HSCE_DB(short v1);
void L1TRC_Send_UL1I_TRC_Sec_HSDSCH_64QAM(short v1);
void L1TRC_Send_UL1I_TRC_Sec_HSDSCH_Meas_Po(short v1);
void L1TRC_Send_UL1I_TRC_Sec_HSDSCH_MAC_Type(char v1);
void L1TRC_Send_UL1I_TRC_Wakeup(short v1);
void L1TRC_Send_UL1I_TRC_CPC_Config(char v1, short v2, char v3, char v4);
void L1TRC_Send_UL1I_TRC_CPC_Control(char v1);
void L1TRC_Send_UL1I_TRC_Monitor_Order_Status(short v1, char v2);
void L1TRC_Send_UL1I_TRC_Monitor_Order_Timer(short v1);
void L1TRC_Send_UL1I_TRC_SkipSyncA(void);
void L1TRC_Send_UL1I_TRC_CEDCH_Termination(char v1);
void L1TRC_Send_UL1T_TRC_CTCH_ChannelPriority(char v1);
void L1TRC_Send_UL1I_TRC_HSPASYS_Configure(short v1);
void L1TRC_Send_UL1I_TRC_HSPASYS_Status(short v1);
void L1TRC_Send_UL1I_TRC_HSPASYS_Delay_frame(short v1);
void L1TRC_Send_UL1I_TRC_HSPASYS_ON_Control(short v1);
void L1TRC_Send_UL1I_TRC_HSPASYS_OFF_Control(short v1);

void Set_UL1C_PRI4_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1C_PRI4()	(UL1C_PRI4_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_L()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_M()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_H()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_CPC_M()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_MonitorOrd_M()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_CEDCH_M()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_DC_HSDSCH_M()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI4_UL1C_ETWS_M()	(ChkL1ModFltr_UL1C_PRI4()&&((UL1C_PRI4_Trace_Filter[2]&0x02)!=0))
#define ChkL1MsgFltr_UL1T_TRC_EDCH_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_EDCH_Setup()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_EDCH_Modify()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_EDCH_Release()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_EAGCH_Calculate_Param()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_EHICH_Calculate_Param()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Calculate_Result()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_ERGCH_Calculate_Param()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Compare_EAGCH_Param()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Compare_EHICH_Param()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Compare_Param_old()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Compare_Param_new()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Compare_Result()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Compare_Result2()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Compare_Result3()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Compare_ERGCH_Param()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_Compare_ERGCH_Result()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_EDCH_Remove()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_EDCH_Start_Timer()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_Start_EDCH()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_Internal_Start_EDCH()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_Stop_EDCH()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_ERNTI_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_EDCH_TTI_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_EDPCCH_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_EDPDCH_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_EDPDCH_Config2()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_EDCH_Serv_Cell_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_EDCH_Channel_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_EDCH_HARQ_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_UL1D_EDCH_Start()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_UL1D_EHICH_Remove()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_UL1D_ERGCH_Remove()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_New_UL1_EHICH_Info()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_Delete_UL1_EHICH_Info()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_New_UL1_ERGCH_Info()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1I_TRC_Delete_UL1_ERGCH_Info()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_EDPDCH_Calculate_Param()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_H()
#define ChkL1MsgFltr_UL1T_TRC_EDPDCH_Get_Buffer()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_HSDSCH_EDCH_Action()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_UL1D_EDCH_Set_MAC_Event()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_H()
#define ChkL1MsgFltr_UL1I_TRC_EDCH_UL1D_Intf()	ChkL1ClsFltr_UL1C_PRI4_UL1C_EDCH_L()
#define ChkL1MsgFltr_UL1T_TRC_HSDSCH_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_HSDSCH_Setup()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_HSDSCH_Modify()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_HSDSCH_Release()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_HSDSCH_Suspend()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_HSDSCH_Start_Timer()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Start_HSDSCH()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Internal_Start_HSDSCH()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Stop_HSDSCH()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_UL1D_HS_Serv_RL_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_HSDSCH_Meas_Po()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_UL1D_HS_State_Info()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_UL1D_HS_DSCH_Start()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_UL1D_HS_Set_MAC_Event()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_HSDSCH_UL1D_Intf()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Update_Strongest_Cells()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Update_Strongest_Cells_RXD()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_Update_Strongest_Cells()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_Update_Strongest_Cells_RXD()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_Update_Serving_Cell()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_Update_Serving_Cell_RXD()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_Send_DC_Report()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1T_TRC_HS_Reset_HSCE_DB()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Sec_HSDSCH_64QAM()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Sec_HSDSCH_Meas_Po()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Sec_HSDSCH_MAC_Type()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_Wakeup()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_L()
#define ChkL1MsgFltr_UL1I_TRC_CPC_Config()	ChkL1ClsFltr_UL1C_PRI4_UL1C_CPC_M()
#define ChkL1MsgFltr_UL1I_TRC_CPC_Control()	ChkL1ClsFltr_UL1C_PRI4_UL1C_CPC_M()
#define ChkL1MsgFltr_UL1I_TRC_Monitor_Order_Status()	ChkL1ClsFltr_UL1C_PRI4_UL1C_MonitorOrd_M()
#define ChkL1MsgFltr_UL1I_TRC_Monitor_Order_Timer()	ChkL1ClsFltr_UL1C_PRI4_UL1C_MonitorOrd_M()
#define ChkL1MsgFltr_UL1I_TRC_SkipSyncA()	ChkL1ClsFltr_UL1C_PRI4_UL1C_CEDCH_M()
#define ChkL1MsgFltr_UL1I_TRC_CEDCH_Termination()	ChkL1ClsFltr_UL1C_PRI4_UL1C_CEDCH_M()
#define ChkL1MsgFltr_UL1T_TRC_CTCH_ChannelPriority()	ChkL1ClsFltr_UL1C_PRI4_UL1C_ETWS_M()
#define ChkL1MsgFltr_UL1I_TRC_HSPASYS_Configure()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_HSPASYS_Status()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_HSPASYS_Delay_frame()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_HSPASYS_ON_Control()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()
#define ChkL1MsgFltr_UL1I_TRC_HSPASYS_OFF_Control()	ChkL1ClsFltr_UL1C_PRI4_UL1C_HSDSCH_H()


#endif
