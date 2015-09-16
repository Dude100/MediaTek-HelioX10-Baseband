#ifndef L1TRC_L1C_GSM_DEF_H
#define L1TRC_L1C_GSM_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1C_Str_Bool(v1)  (unsigned char)(v1+0)
#define L1C_Str_Function(v1)  (unsigned char)(v1+2)
#define L1C_Str_ConflictReport(v1)  (unsigned char)(v1+5)
#define L1C_Str_ConflictTimer(v1)  (unsigned char)(v1+19)
#define L1I_Str_SIM(v1)  (unsigned char)(v1+34)
#define L1I_Str_Set_Sim_Mode(v1)  (unsigned char)(v1+38)
#define L1I_Str_Execute(v1)  (unsigned char)(v1+49)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define L1C_Msg_ReportFCCh(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x001C, (short)(v8)), TRC_MERGE_1S2C((short)(v11), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (char)(v6)), (long)(v7), (long)(v9), (long)(v10));\
	} while(0)
#else
	#define L1C_Msg_ReportFCCh(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define L1C_Msg_ReportFCCh_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_6_DATA(TRC_MERGE_2S(0x001C, (short)(v8)), TRC_MERGE_1S2C((short)(v11), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (char)(v6)), (long)(v7), (long)(v9), (long)(v10))

#if defined(L1_CATCHER)
	#define L1C_Msg_ReportSCh(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x011C, (short)(v7)), TRC_MERGE_1S2C((short)(v9), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (char)(v5), TRC_BOXSTER_PAD), (long)(v6), (long)(v8));\
	} while(0)
#else
	#define L1C_Msg_ReportSCh(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define L1C_Msg_ReportSCh_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_5_DATA(TRC_MERGE_2S(0x011C, (short)(v7)), TRC_MERGE_1S2C((short)(v9), (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (char)(v5), TRC_BOXSTER_PAD), (long)(v6), (long)(v8))

#if defined(L1_CATCHER)
	#define L1C_Msg_ReportBCCh(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x021C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (char)(v6)));\
	} while(0)
#else
	#define L1C_Msg_ReportBCCh(v1, v2, v3, v4, v5, v6)
#endif
#define L1C_Msg_ReportBCCh_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x021C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (char)(v6)))

#if defined(L1_CATCHER)
	#define L1C_Msg_ReportNBCCh(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x031C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (char)(v6)));\
	} while(0)
#else
	#define L1C_Msg_ReportNBCCh(v1, v2, v3, v4, v5, v6)
#endif
#define L1C_Msg_ReportNBCCh_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x031C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (char)(v6)))

#if defined(L1_CATCHER)
	#define L1C_Msg_ReportPCh(v1, v2, v3, v4, v5) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x041C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_ReportPCh(v1, v2, v3, v4, v5)
#endif
#define L1C_Msg_ReportPCh_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x041C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1C_Msg_ReportPeek(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x051C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_ReportPeek(v1, v2, v3, v4)
#endif
#define L1C_Msg_ReportPeek_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x051C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_ReportCBCh(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x061C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_ReportCBCh(v1, v2, v3, v4)
#endif
#define L1C_Msg_ReportCBCh_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x061C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1C_Msg_ReportAGCh(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x071C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_ReportAGCh(v1, v2, v3, v4)
#endif
#define L1C_Msg_ReportAGCh_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x071C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1C_Msg_ReportSDCCh(v1, v2, v3, v4, v5) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x081C, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)));\
	} while(0)
#else
	#define L1C_Msg_ReportSDCCh(v1, v2, v3, v4, v5)
#endif
#define L1C_Msg_ReportSDCCh_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x081C, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)))

#if defined(L1_CATCHER)
	#define L1C_Msg_ReportSACCh(v1, v2, v3, v4, v5) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x091C, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)));\
	} while(0)
#else
	#define L1C_Msg_ReportSACCh(v1, v2, v3, v4, v5)
#endif
#define L1C_Msg_ReportSACCh_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x091C, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4)))

#if defined(L1_CATCHER)
	#define L1C_Msg_DL_FACCH(v1) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A1C, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_DL_FACCH(v1)
#endif
#define L1C_Msg_DL_FACCH_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A1C, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_HoppingSeq(v1, v2) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B1C, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define L1C_Msg_HoppingSeq(v1, v2)
#endif
#define L1C_Msg_HoppingSeq_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B1C, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1T_Trc_SDCCH_DL_DATA(v1, v2) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C1C, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define L1T_Trc_SDCCH_DL_DATA(v1, v2)
#endif
#define L1T_Trc_SDCCH_DL_DATA_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0C1C, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1T_Trc_SACCH_DL_DATA(v1, v2) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D1C, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define L1T_Trc_SACCH_DL_DATA(v1, v2)
#endif
#define L1T_Trc_SACCH_DL_DATA_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0D1C, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1T_Trc_FACCH_DL_DATA(v1, v2) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E1C, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define L1T_Trc_FACCH_DL_DATA(v1, v2)
#endif
#define L1T_Trc_FACCH_DL_DATA_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0E1C, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_StartBCCh(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0F1C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define L1C_Msg_StartBCCh(v1, v2, v3, v4)
#endif
#define L1C_Msg_StartBCCh_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0F1C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_SetupPCh(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x101C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define L1C_Msg_SetupPCh(v1, v2, v3, v4)
#endif
#define L1C_Msg_SetupPCh_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x101C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_StartAGCh(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x111C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_StartAGCh(v1, v2, v3)
#endif
#define L1C_Msg_StartAGCh_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x111C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_SetupCBCh(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x121C, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_SetupCBCh(v1, v2, v3, v4)
#endif
#define L1C_Msg_SetupCBCh_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x121C, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_SetupCiphering(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x131C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_SetupCiphering(v1, v2, v3)
#endif
#define L1C_Msg_SetupCiphering_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x131C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_StartFCChT(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x141C, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1C_Msg_StartFCChT(v1, v2, v3)
#endif
#define L1C_Msg_StartFCChT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x141C, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_StartSChT(v1, v2, v3, v4, v5) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x151C, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), (char)(v5), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define L1C_Msg_StartSChT(v1, v2, v3, v4, v5)
#endif
#define L1C_Msg_StartSChT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x151C, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (char)(v4), (char)(v5), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_FunctionCalled(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x161C, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define L1C_Msg_FunctionCalled(v1, v2, v3, v4)
#endif
#define L1C_Msg_FunctionCalled_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x161C, (unsigned char)(v1), (unsigned char)(v2)), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_R99_Bep(v1, v2, v3, v4, v5) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x171C, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD), (long)(v4));\
	} while(0)
#else
	#define L1C_Trace_R99_Bep(v1, v2, v3, v4, v5)
#endif
#define L1C_Trace_R99_Bep_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x171C, (short)(v5)), TRC_MERGE_4C((unsigned char)(v1), (char)(v2), (char)(v3), TRC_BOXSTER_PAD), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_R99_Bep_bNormalize(v1, v2, v3, v4, v5) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x181C, (short)(v3)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v4));\
	} while(0)
#else
	#define L1C_Trace_R99_Bep_bNormalize(v1, v2, v3, v4, v5)
#endif
#define L1C_Trace_R99_Bep_bNormalize_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x181C, (short)(v3)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_R99_Power_bNormalize(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x191C, (unsigned char)(v1), (char)(v4)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define L1C_Trace_R99_Power_bNormalize(v1, v2, v3, v4)
#endif
#define L1C_Trace_R99_Power_bNormalize_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x191C, (unsigned char)(v1), (char)(v4)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define L1I_Msg_ConflictReportType(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A1C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_ConflictReportType(v1, v2, v3)
#endif
#define L1I_Msg_ConflictReportType_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1A1C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Msg_SimModeChange(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1B1C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_SimModeChange(v1, v2, v3)
#endif
#define L1I_Msg_SimModeChange_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1B1C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1T_TRC_REDUMP() do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[4]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C1C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1T_TRC_REDUMP()
#endif
#define L1T_TRC_REDUMP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1C1C, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Msg_ServingSB(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D1C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_ServingSB(v1, v2, v3, v4)
#endif
#define L1I_Msg_ServingSB_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1D1C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1I_Msg_TimerExecute(v1, v2) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[4]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E1C, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1I_Msg_TimerExecute(v1, v2)
#endif
#define L1I_Msg_TimerExecute_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E1C, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Msg_ServingSBPeek(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[4]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F1C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1I_Msg_ServingSBPeek(v1, v2, v3)
#endif
#define L1I_Msg_ServingSBPeek_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F1C, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1C_GSM_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1C_Msg_ReportFCCh(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, char v6, long v7, short v8, long v9, long v10, short v11);
void L1TRC_Send_L1C_Msg_ReportSCh(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, char v5, long v6, short v7, long v8, short v9);
void L1TRC_Send_L1C_Msg_ReportBCCh(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, char v6);
void L1TRC_Send_L1C_Msg_ReportNBCCh(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, char v6);
void L1TRC_Send_L1C_Msg_ReportPCh(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_L1C_Msg_ReportPeek(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1C_Msg_ReportCBCh(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1C_Msg_ReportAGCh(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1C_Msg_ReportSDCCh(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, short v5);
void L1TRC_Send_L1C_Msg_ReportSACCh(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, short v5);
void L1TRC_Send_L1C_Msg_DL_FACCH(unsigned char v1);
void L1TRC_Send_L1C_Msg_HoppingSeq(unsigned char v1, char v2);
void L1TRC_Send_L1T_Trc_SDCCH_DL_DATA(unsigned char v1, unsigned long v2);
void L1TRC_Send_L1T_Trc_SACCH_DL_DATA(unsigned char v1, unsigned long v2);
void L1TRC_Send_L1T_Trc_FACCH_DL_DATA(unsigned char v1, unsigned long v2);
void L1TRC_Send_L1C_Msg_StartBCCh(unsigned char v1, unsigned char v2, char v3, unsigned long v4);
void L1TRC_Send_L1C_Msg_SetupPCh(unsigned char v1, unsigned char v2, char v3, long v4);
void L1TRC_Send_L1C_Msg_StartAGCh(unsigned char v1, unsigned char v2, char v3);
void L1TRC_Send_L1C_Msg_SetupCBCh(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_L1C_Msg_SetupCiphering(unsigned char v1, unsigned char v2, char v3);
void L1TRC_Send_L1C_Msg_StartFCChT(unsigned char v1, char v2, char v3);
void L1TRC_Send_L1C_Msg_StartSChT(unsigned char v1, long v2, short v3, char v4, char v5);
void L1TRC_Send_L1C_Msg_FunctionCalled(unsigned char v1, unsigned char v2, long v3, long v4);
void L1TRC_Send_L1C_Trace_R99_Bep(unsigned char v1, char v2, char v3, long v4, short v5);
void L1TRC_Send_L1C_Trace_R99_Bep_bNormalize(unsigned char v1, long v2, short v3, long v4, short v5);
void L1TRC_Send_L1C_Trace_R99_Power_bNormalize(unsigned char v1, long v2, long v3, char v4);
void L1TRC_Send_L1I_Msg_ConflictReportType(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1I_Msg_SimModeChange(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1T_TRC_REDUMP(void);
void L1TRC_Send_L1I_Msg_ServingSB(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1I_Msg_TimerExecute(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Msg_ServingSBPeek(unsigned char v1, unsigned char v2, unsigned char v3);

void Set_L1C_GSM_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1C_GSM()	(L1C_GSM_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1C_GSM_ReportFCCh_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1C_GSM_ReportSCh_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1C_GSM_ReportBCCh_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1C_GSM_ReportNBCCh_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1C_GSM_ReportPCh_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1C_GSM_ReportAGCh_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1C_GSM_ReportSDCCh_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1C_GSM_ReportSACCh_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_L1C_GSM_DL_FACCH_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_L1C_GSM_StartBCCh_M()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_L1C_GSM_SetupPCh_M()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_L1C_GSM_StartAGCh_M()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_L1C_GSM_SetupCBCh_M()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_L1C_GSM_SetupCiphering_M()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_L1C_GSM_StartFCChT_M()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_L1C_GSM_StartSChT_M()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_L1C_GSM_SimMode_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_L1C_GSM_ReportCBCh_L()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_L1C_GSM_HoppingSeq_L()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_L1C_GSM_L1T_SDCCH_DL_L()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_L1C_GSM_L1T_SACCH_DL_L()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_L1C_GSM_L1T_FACCH_DL_L()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_L1C_GSM_L1T_Supplement_L()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_L1C_GSM_R99_L()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_L1C_GSM_L1C_ERROR_L()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_L1C_GSM_ServingSB_M()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[4]&0x02)!=0))
#define ChkL1ClsFltr_L1C_GSM_Timer_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[4]&0x04)!=0))
#define ChkL1MsgFltr_L1C_Msg_ReportFCCh()	ChkL1ClsFltr_L1C_GSM_ReportFCCh_H()
#define ChkL1MsgFltr_L1C_Msg_ReportSCh()	ChkL1ClsFltr_L1C_GSM_ReportSCh_H()
#define ChkL1MsgFltr_L1C_Msg_ReportBCCh()	ChkL1ClsFltr_L1C_GSM_ReportBCCh_H()
#define ChkL1MsgFltr_L1C_Msg_ReportNBCCh()	ChkL1ClsFltr_L1C_GSM_ReportNBCCh_H()
#define ChkL1MsgFltr_L1C_Msg_ReportPCh()	ChkL1ClsFltr_L1C_GSM_ReportPCh_H()
#define ChkL1MsgFltr_L1C_Msg_ReportPeek()	ChkL1ClsFltr_L1C_GSM_ReportPCh_H()
#define ChkL1MsgFltr_L1C_Msg_ReportCBCh()	ChkL1ClsFltr_L1C_GSM_ReportCBCh_L()
#define ChkL1MsgFltr_L1C_Msg_ReportAGCh()	ChkL1ClsFltr_L1C_GSM_ReportAGCh_H()
#define ChkL1MsgFltr_L1C_Msg_ReportSDCCh()	ChkL1ClsFltr_L1C_GSM_ReportSDCCh_H()
#define ChkL1MsgFltr_L1C_Msg_ReportSACCh()	ChkL1ClsFltr_L1C_GSM_ReportSACCh_H()
#define ChkL1MsgFltr_L1C_Msg_DL_FACCH()	ChkL1ClsFltr_L1C_GSM_DL_FACCH_H()
#define ChkL1MsgFltr_L1C_Msg_HoppingSeq()	ChkL1ClsFltr_L1C_GSM_HoppingSeq_L()
#define ChkL1MsgFltr_L1T_Trc_SDCCH_DL_DATA()	ChkL1ClsFltr_L1C_GSM_L1T_SDCCH_DL_L()
#define ChkL1MsgFltr_L1T_Trc_SACCH_DL_DATA()	ChkL1ClsFltr_L1C_GSM_L1T_SACCH_DL_L()
#define ChkL1MsgFltr_L1T_Trc_FACCH_DL_DATA()	ChkL1ClsFltr_L1C_GSM_L1T_FACCH_DL_L()
#define ChkL1MsgFltr_L1C_Msg_StartBCCh()	ChkL1ClsFltr_L1C_GSM_StartBCCh_M()
#define ChkL1MsgFltr_L1C_Msg_SetupPCh()	ChkL1ClsFltr_L1C_GSM_SetupPCh_M()
#define ChkL1MsgFltr_L1C_Msg_StartAGCh()	ChkL1ClsFltr_L1C_GSM_StartAGCh_M()
#define ChkL1MsgFltr_L1C_Msg_SetupCBCh()	ChkL1ClsFltr_L1C_GSM_SetupCBCh_M()
#define ChkL1MsgFltr_L1C_Msg_SetupCiphering()	ChkL1ClsFltr_L1C_GSM_SetupCiphering_M()
#define ChkL1MsgFltr_L1C_Msg_StartFCChT()	ChkL1ClsFltr_L1C_GSM_StartFCChT_M()
#define ChkL1MsgFltr_L1C_Msg_StartSChT()	ChkL1ClsFltr_L1C_GSM_StartSChT_M()
#define ChkL1MsgFltr_L1C_Msg_FunctionCalled()	ChkL1ClsFltr_L1C_GSM_L1T_Supplement_L()
#define ChkL1MsgFltr_L1C_Trace_R99_Bep()	ChkL1ClsFltr_L1C_GSM_R99_L()
#define ChkL1MsgFltr_L1C_Trace_R99_Bep_bNormalize()	ChkL1ClsFltr_L1C_GSM_R99_L()
#define ChkL1MsgFltr_L1C_Trace_R99_Power_bNormalize()	ChkL1ClsFltr_L1C_GSM_R99_L()
#define ChkL1MsgFltr_L1I_Msg_ConflictReportType()	ChkL1ClsFltr_L1C_GSM_ReportFCCh_H()
#define ChkL1MsgFltr_L1I_Msg_SimModeChange()	ChkL1ClsFltr_L1C_GSM_SimMode_H()
#define ChkL1MsgFltr_L1T_TRC_REDUMP()	ChkL1ClsFltr_L1C_GSM_L1C_ERROR_L()
#define ChkL1MsgFltr_L1I_Msg_ServingSB()	ChkL1ClsFltr_L1C_GSM_ServingSB_M()
#define ChkL1MsgFltr_L1I_Msg_TimerExecute()	ChkL1ClsFltr_L1C_GSM_Timer_H()
#define ChkL1MsgFltr_L1I_Msg_ServingSBPeek()	ChkL1ClsFltr_L1C_GSM_ServingSB_M()


#endif
