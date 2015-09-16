#ifndef L1TRC_AST_L1_Trace_Task_Context_Group1_DEF_H
#define L1TRC_AST_L1_Trace_Task_Context_Group1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define Str_Bool(v1)  (unsigned char)(v1+0)
#define Str_Gap_Service_State(v1)  (unsigned char)(v1+2)
#define Str_Gap_Sync_State(v1)  (unsigned char)(v1+6)
#define Str_Timing_Sync_State(v1)  (unsigned char)(v1+14)
#define Str_Gap_Calc_State(v1)  (unsigned char)(v1+17)
#define Str_Gap_Ctrl_State(v1)  (unsigned char)(v1+19)
#define Str_Reset_State(v1)  (unsigned char)(v1+22)
#define Str_Rf_State(v1)  (unsigned char)(v1+25)
#define Str_Rat_State(v1)  (unsigned char)(v1+27)
#define Str_Fs_State(v1)  (unsigned char)(v1+30)
#define Str_Sniffer_State(v1)  (unsigned char)(v1+35)
#define Str_Scs_State(v1)  (unsigned char)(v1+40)
#define Str_Container_State(v1)  (unsigned char)(v1+43)
#define Str_Bch_State(v1)  (unsigned char)(v1+47)
#define Str_Pch_State(v1)  (unsigned char)(v1+54)
#define Str_Fach_State(v1)  (unsigned char)(v1+61)
#define Str_Rach_State(v1)  (unsigned char)(v1+66)
#define Str_Ra_State(v1)  (unsigned char)(v1+71)
#define Str_Ul_Dch_State(v1)  (unsigned char)(v1+77)
#define Str_Dl_Dch_State(v1)  (unsigned char)(v1+84)
#define Str_Hsdsch_State(v1)  (unsigned char)(v1+91)
#define Str_Meas_State(v1)  (unsigned char)(v1+98)
#define Str_Meas_Internal_State(v1)  (unsigned char)(v1+102)
#define Str_Rel_Meas_Internal_State(v1)  (unsigned char)(v1+104)
#define Str_Meas_Internal_Result_State(v1)  (unsigned char)(v1+106)
#define Str_Suspend_State(v1)  (unsigned char)(v1+108)
#define Str_Peer2G_State(v1)  (unsigned char)(v1+111)
#define Str_Protect_State(v1)  (unsigned char)(v1+114)
#define Str_b39_tx_suspend_State(v1)  (unsigned char)(v1+117)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_GAP_SERVICE_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x003F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_GAP_SERVICE_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_GAP_SERVICE_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x003F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_GAP_SYNC_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x013F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_GAP_SYNC_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_GAP_SYNC_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x013F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_TIMING_SYNC_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x023F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_TIMING_SYNC_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_TIMING_SYNC_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x023F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_GAP_CALC_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x033F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_GAP_CALC_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_GAP_CALC_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x033F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_GAP_CTRL_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x043F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_GAP_CTRL_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_GAP_CTRL_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x043F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_RESET_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x053F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_RESET_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_RESET_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x053F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_RF_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x063F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_RF_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_RF_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x063F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_RAT_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x073F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_RAT_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_RAT_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x073F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_FS_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x083F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_FS_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_FS_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x083F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_SNIFFER_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x093F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_SNIFFER_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_SNIFFER_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x093F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_SCS_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A3F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_SCS_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_SCS_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A3F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_CONTAINER_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B3F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_CONTAINER_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_CONTAINER_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B3F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_BCH_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C3F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_BCH_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_BCH_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C3F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_PCH_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D3F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_PCH_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_PCH_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D3F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_FACH_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E3F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_FACH_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_FACH_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0E3F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_RACH_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F3F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_RACH_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_RACH_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0F3F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_RA_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x103F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_RA_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_RA_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x103F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_UL_DCH_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x113F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_UL_DCH_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_UL_DCH_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x113F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_DL_DCH_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x123F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_DL_DCH_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_DL_DCH_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x123F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_HSDSCH_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x133F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_HSDSCH_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_HSDSCH_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x133F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_MEAS_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x143F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_MEAS_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_MEAS_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x143F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_MEAS_INTERNAL_STATE(v1, v2) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x153F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_MEAS_INTERNAL_STATE(v1, v2)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_MEAS_INTERNAL_STATE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x153F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_REL_MEAS_INTERNAL_STATE(v1, v2) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x163F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_REL_MEAS_INTERNAL_STATE(v1, v2)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_REL_MEAS_INTERNAL_STATE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x163F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_MEAS_INTERNAL_RSLT_STATE(v1, v2) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x173F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_MEAS_INTERNAL_RSLT_STATE(v1, v2)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_MEAS_INTERNAL_RSLT_STATE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x173F, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_SUSPEND_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x183F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_SUSPEND_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_SUSPEND_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x183F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_PEER_2G_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x193F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_PEER_2G_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_PEER_2G_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x193F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_VIRTUAL_MODE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A3F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_VIRTUAL_MODE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_VIRTUAL_MODE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A3F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_CHANNEL_PROTECT_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B3F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_CHANNEL_PROTECT_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_CHANNEL_PROTECT_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B3F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_PEER_2G_OPEN(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C3F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_PEER_2G_OPEN(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_PEER_2G_OPEN_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C3F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_L1R_Peer2GOpenConfirm() do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D3F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_L1R_Peer2GOpenConfirm()
#endif
#define AST_L1_Trace_Task_Context_Group1_L1R_Peer2GOpenConfirm_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1D3F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_L1R_3GProtectChannel() do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E3F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_L1R_3GProtectChannel()
#endif
#define AST_L1_Trace_Task_Context_Group1_L1R_3GProtectChannel_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E3F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_L1R_3GCancelProtection() do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F3F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_L1R_3GCancelProtection()
#endif
#define AST_L1_Trace_Task_Context_Group1_L1R_3GCancelProtection_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F3F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_L1R_3GEnterVirtualMode(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x203F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_L1R_3GEnterVirtualMode(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_L1R_3GEnterVirtualMode_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x203F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_B39_TX_STATE(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x213F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_B39_TX_STATE(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_B39_TX_STATE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x213F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_TRACE1(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x223F, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_TRACE1(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_TRACE1_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x223F, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_TRACE2(v1, v2) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x233F, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_TRACE2(v1, v2)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_TRACE2_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x233F, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_TRACE3(v1, v2, v3) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x243F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_TRACE3(v1, v2, v3)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_TRACE3_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x243F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_TRACE4(v1, v2, v3, v4) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x253F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_TRACE4(v1, v2, v3, v4)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_TRACE4_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x253F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_TRACE5(v1, v2, v3, v4, v5) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x263F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_TRACE5(v1, v2, v3, v4, v5)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_TRACE5_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x263F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_MSG_2(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x273F, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_MSG_2(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_MSG_2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x273F, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group1_TEST_MSG_3(v1) do {\
		if(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x283F, (unsigned short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group1_TEST_MSG_3(v1)
#endif
#define AST_L1_Trace_Task_Context_Group1_TEST_MSG_3_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x283F, (unsigned short)(v1)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char AST_L1_Trace_Task_Context_Group1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_GAP_SERVICE_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_GAP_SYNC_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_TIMING_SYNC_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_GAP_CALC_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_GAP_CTRL_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_RESET_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_RF_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_RAT_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_FS_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_SNIFFER_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_SCS_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_CONTAINER_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_BCH_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_PCH_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_FACH_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_RACH_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_RA_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_UL_DCH_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_DL_DCH_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_HSDSCH_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_MEAS_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_MEAS_INTERNAL_STATE(unsigned char v1, short v2);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_REL_MEAS_INTERNAL_STATE(unsigned char v1, short v2);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_MEAS_INTERNAL_RSLT_STATE(unsigned char v1, short v2);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_SUSPEND_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_PEER_2G_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_VIRTUAL_MODE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_CHANNEL_PROTECT_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_PEER_2G_OPEN(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_L1R_Peer2GOpenConfirm(void);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_L1R_3GProtectChannel(void);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_L1R_3GCancelProtection(void);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_L1R_3GEnterVirtualMode(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_B39_TX_STATE(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_TRACE1(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_TRACE2(unsigned char v1, unsigned char v2);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_TRACE3(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_TRACE4(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_TRACE5(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_MSG_2(char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group1_TEST_MSG_3(unsigned short v1);

void Set_AST_L1_Trace_Task_Context_Group1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_AST_L1_Trace_Task_Context_Group1()	(AST_L1_Trace_Task_Context_Group1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()	(ChkL1ModFltr_AST_L1_Trace_Task_Context_Group1()&&((AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_2()	(ChkL1ModFltr_AST_L1_Trace_Task_Context_Group1()&&((AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_3()	(ChkL1ModFltr_AST_L1_Trace_Task_Context_Group1()&&((AST_L1_Trace_Task_Context_Group1_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_GAP_SERVICE_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_GAP_SYNC_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_TIMING_SYNC_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_GAP_CALC_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_GAP_CTRL_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_RESET_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_RF_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_RAT_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_FS_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_SNIFFER_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_SCS_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_CONTAINER_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_BCH_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_PCH_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_FACH_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_RACH_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_RA_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_UL_DCH_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_DL_DCH_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_HSDSCH_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_MEAS_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_MEAS_INTERNAL_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_REL_MEAS_INTERNAL_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_MEAS_INTERNAL_RSLT_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_SUSPEND_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_PEER_2G_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_VIRTUAL_MODE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_CHANNEL_PROTECT_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_PEER_2G_OPEN()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_L1R_Peer2GOpenConfirm()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_L1R_3GProtectChannel()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_L1R_3GCancelProtection()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_L1R_3GEnterVirtualMode()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_B39_TX_STATE()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_TRACE1()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_TRACE2()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_TRACE3()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_TRACE4()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_TRACE5()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_MSG_2()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group1_TEST_MSG_3()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group1_TEST_CLASS_1()


#endif
