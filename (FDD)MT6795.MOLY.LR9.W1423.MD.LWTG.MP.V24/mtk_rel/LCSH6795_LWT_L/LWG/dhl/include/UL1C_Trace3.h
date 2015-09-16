#ifndef L1TRC_UL1C_PRI3_DEF_H
#define L1TRC_UL1C_PRI3_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_Reconstruct1(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x003A, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_Reconstruct1(v1, v2, v3)
#endif
#define UL1T_TRC_TGPS_Reconstruct1_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x003A, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_Reconstruct2(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x013A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_Reconstruct2(v1, v2)
#endif
#define UL1T_TRC_TGPS_Reconstruct2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x013A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_Reconstruct3(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x023A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_Reconstruct3(v1, v2, v3, v4, v5, v6)
#endif
#define UL1T_TRC_TGPS_Reconstruct3_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x023A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_Reconstruct4(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x033A, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_Reconstruct4(v1, v2, v3)
#endif
#define UL1T_TRC_TGPS_Reconstruct4_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x033A, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_Reconstruct5(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x043A, (short)(v1)));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_Reconstruct5(v1)
#endif
#define UL1T_TRC_TGPS_Reconstruct5_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x043A, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_Reconstruct6(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x053A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_Reconstruct6(v1, v2, v3)
#endif
#define UL1T_TRC_TGPS_Reconstruct6_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x053A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_Reconstruct7(v1, v2, v3, v4, v5, v6, v7) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x063A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_Reconstruct7(v1, v2, v3, v4, v5, v6, v7)
#endif
#define UL1T_TRC_TGPS_Reconstruct7_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x063A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_MeasControl(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x073A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_MeasControl(v1, v2, v3, v4)
#endif
#define UL1T_TRC_TGPS_MeasControl_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x073A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v4)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_MeasControl(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x083A, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_MeasControl(v1, v2, v3)
#endif
#define UL1I_TRC_TGPS_MeasControl_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x083A, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_Act(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x093A, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_Act(v1, v2)
#endif
#define UL1T_TRC_TGPS_Act_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x093A, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_Frame(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A3A, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (char)(v3), (char)(v4)));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_Frame(v1, v2, v3, v4)
#endif
#define UL1I_TRC_TGPS_Frame_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0A3A, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (char)(v3), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_Kill_Pending_MC(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0B3A, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_Kill_Pending_MC(v1)
#endif
#define UL1I_TRC_TGPS_Kill_Pending_MC_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0B3A, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_Status(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C3A, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_Status(v1, v2)
#endif
#define UL1I_TRC_TGPS_Status_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0C3A, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_Frame_Type(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D3A, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_Frame_Type(v1, v2)
#endif
#define UL1I_TRC_TGPS_Frame_Type_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D3A, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_Check_InterF(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E3A, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (char)(v3), (char)(v4)));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_Check_InterF(v1, v2, v3, v4)
#endif
#define UL1I_TRC_TGPS_Check_InterF_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E3A, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), (char)(v3), (char)(v4)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_Frame_Dummy(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F3A, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_Frame_Dummy(v1, v2)
#endif
#define UL1I_TRC_TGPS_Frame_Dummy_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F3A, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_Not_Allow_Recons(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x103A, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_Not_Allow_Recons(v1)
#endif
#define UL1I_TRC_TGPS_Not_Allow_Recons_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x103A, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_Frame_Len(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x113A, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_Frame_Len(v1, v2)
#endif
#define UL1I_TRC_TGPS_Frame_Len_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x113A, (short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_MaxTTI(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x123A, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_MaxTTI(v1)
#endif
#define UL1I_TRC_TGPS_MaxTTI_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x123A, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_TGPS_Overlap_Reconfig(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x133A, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_TGPS_Overlap_Reconfig(v1)
#endif
#define UL1I_TRC_TGPS_Overlap_Reconfig_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x133A, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_TGPS_TGCFN_MODIFY(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x143A, (short)(v1)));\
	} while(0)
#else
	#define UL1T_TRC_TGPS_TGCFN_MODIFY(v1)
#endif
#define UL1T_TRC_TGPS_TGCFN_MODIFY_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x143A, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RACH_offset(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x153A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RACH_offset(v1, v2)
#endif
#define UL1I_TRC_RACH_offset_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x153A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Keep_Awake() do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x163A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Keep_Awake()
#endif
#define UL1I_TRC_Keep_Awake_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x163A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_VFD_RecoverFrame(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x173A, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_VFD_RecoverFrame(v1)
#endif
#define UL1I_TRC_VFD_RecoverFrame_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x173A, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_VFD_Status_Delay_VFD_timer() do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x183A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_VFD_Status_Delay_VFD_timer()
#endif
#define UL1I_TRC_VFD_Status_Delay_VFD_timer_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x183A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1I_TRC_VFD_Status_Recovery_stage2() do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x193A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_VFD_Status_Recovery_stage2()
#endif
#define UL1I_TRC_VFD_Status_Recovery_stage2_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x193A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_AssignGAPDBG(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A3A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_AssignGAPDBG(v1, v2)
#endif
#define UL1I_TRC_AssignGAPDBG_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1A3A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_PM_Done(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B3A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_PM_Done(v1, v2, v3)
#endif
#define UL1I_TRC_DM_PM_Done_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1B3A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_PM_Tick(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C3A, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_PM_Tick(v1, v2, v3)
#endif
#define UL1I_TRC_DM_PM_Tick_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1C3A, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_DM_Set_GSM_Gap_Type(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D3A, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_DM_Set_GSM_Gap_Type(v1, v2, v3, v4)
#endif
#define UL1I_TRC_DM_Set_GSM_Gap_Type_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D3A, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Post_Fail_InSync_Immed(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1E3A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_Post_Fail_InSync_Immed(v1, v2, v3, v4)
#endif
#define UL1I_TRC_Post_Fail_InSync_Immed_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1E3A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_tgprc_modify_to_zero() do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_tgprc_modify_to_zero()
#endif
#define UL1I_TRC_tgprc_modify_to_zero_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_HHO_Query_Timing_fail(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x203A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_HHO_Query_Timing_fail(v1, v2)
#endif
#define UL1I_TRC_HHO_Query_Timing_fail_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x203A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_QueueFunctionOverflow() do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x213A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_QueueFunctionOverflow()
#endif
#define UL1I_TRC_QueueFunctionOverflow_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x213A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_CCM_timer_delay_type(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x223A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CCM_timer_delay_type(v1, v2)
#endif
#define UL1I_TRC_CCM_timer_delay_type_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x223A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Leave_PLL_save_mode(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x233A, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_Leave_PLL_save_mode(v1)
#endif
#define UL1I_TRC_Leave_PLL_save_mode_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x233A, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_Enter_PLL_save_mode(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x243A, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_Enter_PLL_save_mode(v1)
#endif
#define UL1I_TRC_Enter_PLL_save_mode_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x243A, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RestartRACH_ongoing(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x253A, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_RestartRACH_ongoing(v1)
#endif
#define UL1I_TRC_RestartRACH_ongoing_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x253A, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_SetResourceDoneFrame(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x263A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1I_TRC_SetResourceDoneFrame(v1, v2, v3)
#endif
#define UL1I_TRC_SetResourceDoneFrame_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x263A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UseCountUpdate(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x273A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_UseCountUpdate(v1, v2)
#endif
#define UL1I_TRC_UseCountUpdate_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x273A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_UseCountDisable(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x283A, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_UseCountDisable(v1)
#endif
#define UL1I_TRC_UseCountDisable_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x283A, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_RSSI_SNIFFER1(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x293A, (short)(v1)));\
	} while(0)
#else
	#define UL1T_TRC_RSSI_SNIFFER1(v1)
#endif
#define UL1T_TRC_RSSI_SNIFFER1_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x293A, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1T_TRC_RSSI_SNIFFER2(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A3A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_RSSI_SNIFFER2(v1)
#endif
#define UL1T_TRC_RSSI_SNIFFER2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2A3A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1T_TRC_RSSI_SNIFFER3(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B3A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_RSSI_SNIFFER3(v1, v2)
#endif
#define UL1T_TRC_RSSI_SNIFFER3_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2B3A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1I_TRC_RSSI_SNIFFER_status(v1, v2, v3, v4) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2C3A, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_RSSI_SNIFFER_status(v1, v2, v3, v4)
#endif
#define UL1I_TRC_RSSI_SNIFFER_status_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x2C3A, (char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER)
	#define UL1I_TRC_FrameTick(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2D3A, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v5)), (long)(v2), (long)(v4));\
	} while(0)
#else
	#define UL1I_TRC_FrameTick(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_FrameTick_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2D3A, (short)(v1)), TRC_MERGE_2S((short)(v3), (short)(v5)), (long)(v2), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1T_TRC_GeminiMode(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E3A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_GeminiMode(v1)
#endif
#define UL1T_TRC_GeminiMode_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2E3A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1T_TRC_PeerGeminiMode(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2F3A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_PeerGeminiMode(v1)
#endif
#define UL1T_TRC_PeerGeminiMode_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2F3A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_GeminiMode(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x303A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_GeminiMode(v1)
#endif
#define UL1I_TRC_GeminiMode_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x303A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1T_TRC_ChannelPriority(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x313A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1T_TRC_ChannelPriority(v1)
#endif
#define UL1T_TRC_ChannelPriority_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x313A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_ChannelPriority(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x323A, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1I_TRC_ChannelPriority(v1, v2)
#endif
#define UL1I_TRC_ChannelPriority_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x323A, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_FSGapStart() do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x333A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FSGapStart()
#endif
#define UL1I_TRC_FSGapStart_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x333A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_FSGapStop() do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x343A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FSGapStop()
#endif
#define UL1I_TRC_FSGapStop_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x343A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_FSGapInfo_NoStartTimer(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x353A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FSGapInfo_NoStartTimer(v1)
#endif
#define UL1I_TRC_FSGapInfo_NoStartTimer_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x353A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_FSGapInfo_StartAfter(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x363A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FSGapInfo_StartAfter(v1, v2)
#endif
#define UL1I_TRC_FSGapInfo_StartAfter_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x363A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_FSGapLength(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x373A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FSGapLength(v1, v2)
#endif
#define UL1I_TRC_FSGapLength_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x373A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CMCSGapStart(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x383A, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMCSGapStart(v1, v2, v3)
#endif
#define UL1I_TRC_CMCSGapStart_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x383A, (short)(v2)), TRC_MERGE_4C((char)(v1), (char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CMCSGapStop(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x393A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMCSGapStop(v1, v2)
#endif
#define UL1I_TRC_CMCSGapStop_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x393A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CMCSGapTimerStart(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3A3A, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_CMCSGapTimerStart(v1)
#endif
#define UL1I_TRC_CMCSGapTimerStart_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3A3A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CMCSGapInfo_NoStartTimer(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3B3A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMCSGapInfo_NoStartTimer(v1)
#endif
#define UL1I_TRC_CMCSGapInfo_NoStartTimer_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3B3A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CMCSGapInfo_StartAfter(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3C3A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMCSGapInfo_StartAfter(v1, v2)
#endif
#define UL1I_TRC_CMCSGapInfo_StartAfter_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3C3A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CMCSGapLength(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3D3A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CMCSGapLength(v1, v2, v3)
#endif
#define UL1I_TRC_CMCSGapLength_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3D3A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CMCSGap_overlapBCH(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x3E3A, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_CMCSGap_overlapBCH(v1)
#endif
#define UL1I_TRC_CMCSGap_overlapBCH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x3E3A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_FCMGapStop() do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3F3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_FCMGapStop()
#endif
#define UL1I_TRC_FCMGapStop_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3F3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxSuspend(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x403A, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_RxTxSuspend(v1, v2)
#endif
#define UL1I_TRC_RxTxSuspend_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x403A, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxRelease(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x413A, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_RxTxRelease(v1, v2)
#endif
#define UL1I_TRC_RxTxRelease_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x413A, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxReserve(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x423A, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_RxTxReserve(v1, v2)
#endif
#define UL1I_TRC_RxTxReserve_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x423A, (char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_Check2GTimer(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x433A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_Check2GTimer(v1)
#endif
#define UL1I_TRC_RxTxInfo_Check2GTimer_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x433A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_Check2GReservation(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x443A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_Check2GReservation(v1)
#endif
#define UL1I_TRC_RxTxInfo_Check2GReservation_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x443A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_CheckHWResource(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x453A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_CheckHWResource(v1)
#endif
#define UL1I_TRC_RxTxInfo_CheckHWResource_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x453A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_CheckHWPartial(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x463A, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_CheckHWPartial(v1)
#endif
#define UL1I_TRC_RxTxInfo_CheckHWPartial_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x463A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_AdjustPri_InternalHigh(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x473A, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_AdjustPri_InternalHigh(v1)
#endif
#define UL1I_TRC_RxTxInfo_AdjustPri_InternalHigh_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x473A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_AdjustPri_CheckBCH(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x483A, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_AdjustPri_CheckBCH(v1)
#endif
#define UL1I_TRC_RxTxInfo_AdjustPri_CheckBCH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x483A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_AdjustPri_SetPriHigh(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x493A, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_AdjustPri_SetPriHigh(v1)
#endif
#define UL1I_TRC_RxTxInfo_AdjustPri_SetPriHigh_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x493A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_AdjustPri_searchMask(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_AdjustPri_searchMask(v1)
#endif
#define UL1I_TRC_RxTxInfo_AdjustPri_searchMask_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x4A3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_Resume_Priority(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x4B3A, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_Resume_Priority(v1)
#endif
#define UL1I_TRC_RxTxInfo_Resume_Priority_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x4B3A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_RxStart(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4C3A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_RxStart(v1)
#endif
#define UL1I_TRC_RxTxInfo_RxStart_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4C3A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_TxStart(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4D3A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_TxStart(v1)
#endif
#define UL1I_TRC_RxTxInfo_TxStart_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4D3A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_RxStop() do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4E3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_RxStop()
#endif
#define UL1I_TRC_RxTxInfo_RxStop_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4E3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_TxStop() do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4F3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_TxStop()
#endif
#define UL1I_TRC_RxTxInfo_TxStop_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x4F3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_rtb_been_reserved() do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x503A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_rtb_been_reserved()
#endif
#define UL1I_TRC_RxTxInfo_rtb_been_reserved_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x503A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_Change_Rx_reserved(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x513A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_Change_Rx_reserved(v1)
#endif
#define UL1I_TRC_RxTxInfo_Change_Rx_reserved_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x513A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxInfo_Change_Tx_reserved(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x523A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxInfo_Change_Tx_reserved(v1)
#endif
#define UL1I_TRC_RxTxInfo_Change_Tx_reserved_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x523A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxSetPriority(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x533A, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxSetPriority(v1, v2, v3)
#endif
#define UL1I_TRC_RxTxSetPriority_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x533A, (short)(v3)), TRC_MERGE_4C((char)(v1), (char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxUpdateStarvation(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x543A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxUpdateStarvation(v1, v2)
#endif
#define UL1I_TRC_RxTxUpdateStarvation_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x543A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxStopStarvation() do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x553A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_RxTxStopStarvation()
#endif
#define UL1I_TRC_RxTxStopStarvation_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x553A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxAdjustPriStarvation(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x563A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1I_TRC_RxTxAdjustPriStarvation(v1)
#endif
#define UL1I_TRC_RxTxAdjustPriStarvation_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x563A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_RxTxSlotSuspend(v1, v2, v3, v4, v5, v6) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x573A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1I_TRC_RxTxSlotSuspend(v1, v2, v3, v4, v5, v6)
#endif
#define UL1I_TRC_RxTxSlotSuspend_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x573A, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CPCTxStatus(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x583A, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1I_TRC_CPCTxStatus(v1)
#endif
#define UL1I_TRC_CPCTxStatus_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x583A, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CPCTxCalInfo(v1, v2, v3, v4, v5) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x593A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define UL1I_TRC_CPCTxCalInfo(v1, v2, v3, v4, v5)
#endif
#define UL1I_TRC_CPCTxCalInfo_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x593A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CPCTxRelease(v1) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x5A3A, (short)(v1)));\
	} while(0)
#else
	#define UL1I_TRC_CPCTxRelease(v1)
#endif
#define UL1I_TRC_CPCTxRelease_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x5A3A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CPCTxSlotSuspend(v1, v2) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5B3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1I_TRC_CPCTxSlotSuspend(v1, v2)
#endif
#define UL1I_TRC_CPCTxSlotSuspend_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x5B3A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1I_TRC_CPCTxNoSync(v1, v2, v3) do {\
		if(UL1C_PRI3_Trace_Filter[0]==1 && (UL1C_PRI3_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x5C3A, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1I_TRC_CPCTxNoSync(v1, v2, v3)
#endif
#define UL1I_TRC_CPCTxNoSync_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x5C3A, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1C_PRI3_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1T_TRC_TGPS_Reconstruct1(char v1, char v2, char v3);
void L1TRC_Send_UL1T_TRC_TGPS_Reconstruct2(short v1, short v2);
void L1TRC_Send_UL1T_TRC_TGPS_Reconstruct3(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_UL1T_TRC_TGPS_Reconstruct4(char v1, char v2, char v3);
void L1TRC_Send_UL1T_TRC_TGPS_Reconstruct5(short v1);
void L1TRC_Send_UL1T_TRC_TGPS_Reconstruct6(short v1, short v2, short v3);
void L1TRC_Send_UL1T_TRC_TGPS_Reconstruct7(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_UL1T_TRC_TGPS_MeasControl(short v1, short v2, char v3, short v4);
void L1TRC_Send_UL1I_TRC_TGPS_MeasControl(char v1, short v2, char v3);
void L1TRC_Send_UL1T_TRC_TGPS_Act(char v1, char v2);
void L1TRC_Send_UL1I_TRC_TGPS_Frame(short v1, unsigned short v2, char v3, char v4);
void L1TRC_Send_UL1I_TRC_TGPS_Kill_Pending_MC(short v1);
void L1TRC_Send_UL1I_TRC_TGPS_Status(short v1, char v2);
void L1TRC_Send_UL1I_TRC_TGPS_Frame_Type(short v1, char v2);
void L1TRC_Send_UL1I_TRC_TGPS_Check_InterF(short v1, unsigned short v2, char v3, char v4);
void L1TRC_Send_UL1I_TRC_TGPS_Frame_Dummy(short v1, char v2);
void L1TRC_Send_UL1I_TRC_TGPS_Not_Allow_Recons(short v1);
void L1TRC_Send_UL1I_TRC_TGPS_Frame_Len(short v1, char v2);
void L1TRC_Send_UL1I_TRC_TGPS_MaxTTI(short v1);
void L1TRC_Send_UL1I_TRC_TGPS_Overlap_Reconfig(short v1);
void L1TRC_Send_UL1T_TRC_TGPS_TGCFN_MODIFY(short v1);
void L1TRC_Send_UL1I_TRC_RACH_offset(short v1, short v2);
void L1TRC_Send_UL1I_TRC_Keep_Awake(void);
void L1TRC_Send_UL1I_TRC_VFD_RecoverFrame(unsigned short v1);
void L1TRC_Send_UL1I_TRC_VFD_Status_Delay_VFD_timer(void);
void L1TRC_Send_UL1I_TRC_VFD_Status_Recovery_stage2(void);
void L1TRC_Send_UL1I_TRC_AssignGAPDBG(char v1, short v2);
void L1TRC_Send_UL1I_TRC_DM_PM_Done(short v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_DM_PM_Tick(char v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_DM_Set_GSM_Gap_Type(char v1, char v2, char v3, char v4);
void L1TRC_Send_UL1I_TRC_Post_Fail_InSync_Immed(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1I_TRC_tgprc_modify_to_zero(void);
void L1TRC_Send_UL1I_TRC_HHO_Query_Timing_fail(short v1, short v2);
void L1TRC_Send_UL1I_TRC_QueueFunctionOverflow(void);
void L1TRC_Send_UL1I_TRC_CCM_timer_delay_type(char v1, short v2);
void L1TRC_Send_UL1I_TRC_Leave_PLL_save_mode(short v1);
void L1TRC_Send_UL1I_TRC_Enter_PLL_save_mode(short v1);
void L1TRC_Send_UL1I_TRC_RestartRACH_ongoing(short v1);
void L1TRC_Send_UL1I_TRC_SetResourceDoneFrame(short v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_UseCountUpdate(char v1, short v2);
void L1TRC_Send_UL1I_TRC_UseCountDisable(short v1);
void L1TRC_Send_UL1T_TRC_RSSI_SNIFFER1(short v1);
void L1TRC_Send_UL1T_TRC_RSSI_SNIFFER2(char v1);
void L1TRC_Send_UL1T_TRC_RSSI_SNIFFER3(char v1, short v2);
void L1TRC_Send_UL1I_TRC_RSSI_SNIFFER_status(char v1, char v2, char v3, long v4);
void L1TRC_Send_UL1I_TRC_FrameTick(short v1, long v2, short v3, long v4, short v5);
void L1TRC_Send_UL1T_TRC_GeminiMode(char v1);
void L1TRC_Send_UL1T_TRC_PeerGeminiMode(char v1);
void L1TRC_Send_UL1I_TRC_GeminiMode(char v1);
void L1TRC_Send_UL1T_TRC_ChannelPriority(char v1);
void L1TRC_Send_UL1I_TRC_ChannelPriority(char v1, char v2);
void L1TRC_Send_UL1I_TRC_FSGapStart(void);
void L1TRC_Send_UL1I_TRC_FSGapStop(void);
void L1TRC_Send_UL1I_TRC_FSGapInfo_NoStartTimer(char v1);
void L1TRC_Send_UL1I_TRC_FSGapInfo_StartAfter(char v1, short v2);
void L1TRC_Send_UL1I_TRC_FSGapLength(char v1, short v2);
void L1TRC_Send_UL1I_TRC_CMCSGapStart(char v1, short v2, char v3);
void L1TRC_Send_UL1I_TRC_CMCSGapStop(char v1, short v2);
void L1TRC_Send_UL1I_TRC_CMCSGapTimerStart(short v1);
void L1TRC_Send_UL1I_TRC_CMCSGapInfo_NoStartTimer(char v1);
void L1TRC_Send_UL1I_TRC_CMCSGapInfo_StartAfter(char v1, short v2);
void L1TRC_Send_UL1I_TRC_CMCSGapLength(char v1, short v2, short v3);
void L1TRC_Send_UL1I_TRC_CMCSGap_overlapBCH(short v1);
void L1TRC_Send_UL1I_TRC_FCMGapStop(void);
void L1TRC_Send_UL1I_TRC_RxTxSuspend(char v1, unsigned long v2);
void L1TRC_Send_UL1I_TRC_RxTxRelease(char v1, unsigned long v2);
void L1TRC_Send_UL1I_TRC_RxTxReserve(char v1, unsigned long v2);
void L1TRC_Send_UL1I_TRC_RxTxInfo_Check2GTimer(long v1);
void L1TRC_Send_UL1I_TRC_RxTxInfo_Check2GReservation(char v1);
void L1TRC_Send_UL1I_TRC_RxTxInfo_CheckHWResource(char v1);
void L1TRC_Send_UL1I_TRC_RxTxInfo_CheckHWPartial(short v1);
void L1TRC_Send_UL1I_TRC_RxTxInfo_AdjustPri_InternalHigh(short v1);
void L1TRC_Send_UL1I_TRC_RxTxInfo_AdjustPri_CheckBCH(short v1);
void L1TRC_Send_UL1I_TRC_RxTxInfo_AdjustPri_SetPriHigh(short v1);
void L1TRC_Send_UL1I_TRC_RxTxInfo_AdjustPri_searchMask(long v1);
void L1TRC_Send_UL1I_TRC_RxTxInfo_Resume_Priority(short v1);
void L1TRC_Send_UL1I_TRC_RxTxInfo_RxStart(char v1);
void L1TRC_Send_UL1I_TRC_RxTxInfo_TxStart(char v1);
void L1TRC_Send_UL1I_TRC_RxTxInfo_RxStop(void);
void L1TRC_Send_UL1I_TRC_RxTxInfo_TxStop(void);
void L1TRC_Send_UL1I_TRC_RxTxInfo_rtb_been_reserved(void);
void L1TRC_Send_UL1I_TRC_RxTxInfo_Change_Rx_reserved(char v1);
void L1TRC_Send_UL1I_TRC_RxTxInfo_Change_Tx_reserved(char v1);
void L1TRC_Send_UL1I_TRC_RxTxSetPriority(char v1, char v2, short v3);
void L1TRC_Send_UL1I_TRC_RxTxUpdateStarvation(short v1, short v2);
void L1TRC_Send_UL1I_TRC_RxTxStopStarvation(void);
void L1TRC_Send_UL1I_TRC_RxTxAdjustPriStarvation(long v1);
void L1TRC_Send_UL1I_TRC_RxTxSlotSuspend(char v1, short v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_UL1I_TRC_CPCTxStatus(char v1);
void L1TRC_Send_UL1I_TRC_CPCTxCalInfo(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_UL1I_TRC_CPCTxRelease(short v1);
void L1TRC_Send_UL1I_TRC_CPCTxSlotSuspend(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1I_TRC_CPCTxNoSync(short v1, unsigned long v2, unsigned long v3);

void Set_UL1C_PRI3_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1C_PRI3()	(UL1C_PRI3_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_L()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_L()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_RS_L()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_Frame_H()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_M()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_M()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_RS_M()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1C_PRI3_UL1C_RS_H()	(ChkL1ModFltr_UL1C_PRI3()&&((UL1C_PRI3_Trace_Filter[2]&0x04)!=0))
#define ChkL1MsgFltr_UL1T_TRC_TGPS_Reconstruct1()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_Reconstruct2()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_Reconstruct3()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_Reconstruct4()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_Reconstruct5()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_Reconstruct6()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_Reconstruct7()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_MeasControl()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_MeasControl()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_Act()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_Frame()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_Kill_Pending_MC()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_Status()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_Frame_Type()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_Check_InterF()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_Frame_Dummy()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_Not_Allow_Recons()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_Frame_Len()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_MaxTTI()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_TGPS_Overlap_Reconfig()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1T_TRC_TGPS_TGCFN_MODIFY()	ChkL1ClsFltr_UL1C_PRI3_UL1C_TGPS_H()
#define ChkL1MsgFltr_UL1I_TRC_RACH_offset()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_Keep_Awake()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_VFD_RecoverFrame()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_L()
#define ChkL1MsgFltr_UL1I_TRC_VFD_Status_Delay_VFD_timer()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_L()
#define ChkL1MsgFltr_UL1I_TRC_VFD_Status_Recovery_stage2()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_L()
#define ChkL1MsgFltr_UL1I_TRC_AssignGAPDBG()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_PM_Done()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_PM_Tick()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_DM_Set_GSM_Gap_Type()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_Post_Fail_InSync_Immed()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_tgprc_modify_to_zero()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_HHO_Query_Timing_fail()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_QueueFunctionOverflow()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_CCM_timer_delay_type()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_Leave_PLL_save_mode()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_Enter_PLL_save_mode()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_RestartRACH_ongoing()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_SetResourceDoneFrame()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_UseCountUpdate()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1I_TRC_UseCountDisable()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Debug_H()
#define ChkL1MsgFltr_UL1T_TRC_RSSI_SNIFFER1()	ChkL1ClsFltr_UL1C_PRI3_UL1C_RS_H()
#define ChkL1MsgFltr_UL1T_TRC_RSSI_SNIFFER2()	ChkL1ClsFltr_UL1C_PRI3_UL1C_RS_H()
#define ChkL1MsgFltr_UL1T_TRC_RSSI_SNIFFER3()	ChkL1ClsFltr_UL1C_PRI3_UL1C_RS_H()
#define ChkL1MsgFltr_UL1I_TRC_RSSI_SNIFFER_status()	ChkL1ClsFltr_UL1C_PRI3_UL1C_RS_H()
#define ChkL1MsgFltr_UL1I_TRC_FrameTick()	ChkL1ClsFltr_UL1C_PRI3_UL1C_Frame_H()
#define ChkL1MsgFltr_UL1T_TRC_GeminiMode()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1T_TRC_PeerGeminiMode()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_GeminiMode()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1T_TRC_ChannelPriority()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_ChannelPriority()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_FSGapStart()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_FSGapStop()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_FSGapInfo_NoStartTimer()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_FSGapInfo_StartAfter()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_FSGapLength()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CMCSGapStart()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CMCSGapStop()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CMCSGapTimerStart()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CMCSGapInfo_NoStartTimer()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CMCSGapInfo_StartAfter()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CMCSGapLength()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CMCSGap_overlapBCH()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_FCMGapStop()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxSuspend()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxRelease()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxReserve()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_Check2GTimer()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_Check2GReservation()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_CheckHWResource()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_CheckHWPartial()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_AdjustPri_InternalHigh()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_AdjustPri_CheckBCH()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_AdjustPri_SetPriHigh()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_AdjustPri_searchMask()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_Resume_Priority()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_RxStart()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_TxStart()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_RxStop()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_TxStop()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_rtb_been_reserved()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_Change_Rx_reserved()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxInfo_Change_Tx_reserved()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxSetPriority()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxUpdateStarvation()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxStopStarvation()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxAdjustPriStarvation()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_RxTxSlotSuspend()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CPCTxStatus()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CPCTxCalInfo()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CPCTxRelease()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CPCTxSlotSuspend()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()
#define ChkL1MsgFltr_UL1I_TRC_CPCTxNoSync()	ChkL1ClsFltr_UL1C_PRI3_UL1C_GEMINI20_M()


#endif
